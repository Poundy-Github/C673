/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 SLATE_OOI (Object of Interest selection)

MODULNAME:                 ooi_objloss.c

DESCRIPTION:               This file includes logic for determining relevant object loss reason 

AUTHOR:                    Fridolin Kolb

CREATION DATE:             10.08.2016

  VERSION:                  $Revision: 1.45 $

LEGACY VERSION:            Revision: 2.2

**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "ooi.h"//PRQA S 0380
/* date: 2019-07-28, reviewer:Prabhu Sundaramurthy, reason: Arises due to inclusion of multiple header files in this header file which has multiple macros*/
#if (FCT_CFG_ACC_OOI)

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/

/**
@defgroup ooi_objloss Object loss
@ingroup ooi
@brief          This module determine the reason for losing relevant object. \n\n
@{
*/
/*****************************************************************************
  MODULGLOBALE KONSTANTEN
*****************************************************************************/


/*****************************************************************************
  MODULGLOBALE VARIABLEN
*****************************************************************************/


/*****************************************************************************
  MODULLOKALE SYMBOLISCHE KONSTANTEN
*****************************************************************************/
#define OOI_ROVG_VEIGENMIN                 (10.F / C_KMH_MS)

#define OOI_ROVG_BREMSUNG                  (6.F)

#define OOI_ROVG_GRENZKRUEMMUNG_AUS_AF     (0.5F/1000.F)
#define OOI_ROVG_GRENZWINKEL               (SLATE_f_GetLobeAngle() * 0.75F)

#define OOI_ROVG_GRENZE_BX                 (25.F)

#define OOI_ROVG_GRENZWINKEL_BX_NEU        OOI_ROVG_GRENZWINKEL/*(ERFASSUNGSWINKEL *0.75f)*/

#define OOI_ROV_SET_MAX_TIME_DIST      (2.5f)
#define OOI_ROV_RESET_MAX_TIME_DIST    (4.0f)
#define OOI_ROV_MAX_DIST               (100.0f)
#define OOI_ROV_MIN_DIST               (0.0f)

#define OOI_ROV_RELEVANT_OBJ_COUNTER_EGO_MOVING        ((uint8)10)
#define OOI_ROV_RELEVANT_OBJ_COUNTER_EGO_STANDSTILL    ((uint8)50)

#define OOI_FAST_CURVE_SCALE           (-0.5f)



#define OOI_ROV_MIN_DIST_THRES         (10.0f)
#define OOI_ROV_MAX_CURVATURE          (1.0f/1000.0f)
#define OOI_ROV_MAX_LC_PROB            (30)

/*
Parameters used by function iSISeReObFastTrackAbschaltung(void), previously
defined in the function body (now a MISRA violation, thus moved here
*/
#define OOI_KRUEMMUNGGRENZ       (0.5F/40.F)
/* Geschwindigkeitsschwelle fuer RCS-Ueberpruefung */
#define OOI_TRACK_ABSCHALT_VEIGEN_MIN              (30.F/C_KMH_MS)

/*
Parameters used by function OOI_v_ObReObRelObjVerlustSetzenTimeDist(...), previously
defined in the function body (now a MISRA violation, thus moved here
*/
#define OOI_ROVG_FLAG_ABSTAND_MAX          (60.F)
#define OOI_ROVG_FLAG_GRENZGRADIENT_AF     (0.0005F)
/* TB A ARS200 SCR 159  20-12-2004 */
#define OOI_ROVG_ABSTAND_MIN               (10.F)              /* Mindestabstand fuer die Ausgabe des OBJ_LOSS_DISAPPEARED */
/* TB A ARS200 SCR 159  20-12-2004 */

/*****************************************************************************
  MODULLOKALE MAKROS
*****************************************************************************/
#ifndef OBJ_LOSS_EGO_LANE_CHG_LEFT
#define OBJ_LOSS_EGO_LANE_CHG_LEFT 14U
#endif

#ifndef OBJ_LOSS_EGO_LANE_CHG_RIGHT
#define OBJ_LOSS_EGO_LANE_CHG_RIGHT 15U
#endif

/*****************************************************************************
  MODULLOKALE TYPEN
*****************************************************************************/
typedef enum SIFastTrackSwitchOff{
  NO_SWITCH_OFF,
  LEFT_CURVE_SWITCH_OFF,
  RIGHT_CURVE_SWITCH_OFF
}OOI_FastTrackSwitchOff_t;

/*****************************************************************************
  MODULLOKALE KONSTANTEN
*****************************************************************************/

/*****************************************************************************
  MODULLOKALE TYPEDEFS 
*****************************************************************************/

/*****************************************************************************
  MODULLOKALE VARIABLEN
*****************************************************************************/

SET_MEMSEC_VAR(OOI_f_dROVGHalteDistanz)
static float32 OOI_f_dROVGHalteDistanz[OBJLOSS_NUMBER_OF_OOI];

SET_MEMSEC_VAR(OOI_t_dROVGHalteVObjekt)
static fVelocity_t OOI_t_dROVGHalteVObjekt[OBJLOSS_NUMBER_OF_OOI];

SET_MEMSEC_VAR(OOI_f_dKruemmungWaehrendROVMin)
static float32 OOI_f_dKruemmungWaehrendROVMin[OBJLOSS_NUMBER_OF_OOI];

SET_MEMSEC_VAR(OOI_b_RelObjDisappearedFlag)
static boolean OOI_b_RelObjDisappearedFlag[OBJLOSS_NUMBER_OF_OOI];// PRQA S 3229
/* date: 2017-01-6, reviewer: Rahul Raj R (uid41599), reason: static local for saving data across function calls/cycles */

#if (OOI_ROV_RESET_BY_TIME == SWITCH_ON)
SET_MEMSEC_VAR(OOI_f_rov_reset_time)
float32 OOI_f_rov_reset_time[OBJLOSS_NUMBER_OF_OOI];
#endif

#if (OOI_CFG_OBJLOSS_LOWDIST)
SET_MEMSEC_VAR(OOI_b_ROVGHalteNearDistCondtition)
static boolean OOI_b_ROVGHalteNearDistCondtition;
#endif

/*****************************************************************************
  FUNCTION PROTOTYPES
*****************************************************************************/
static void OOI_v_ReObRelObVerlustGrundInit (void);
static void OOI_v_ResetRelObjLossReason(uint8 Nr);
static OOI_FastTrackSwitchOff_t OOI_t_SeReObFastTrackAbschaltung(void);
static void OOI_v_ObReObRelObjVerlRueckTimeDist (const OOI_ROVDataInput_t *ROVDataInput);
static void OOI_v_ObReObRelObjVerlustSetzenTimeDist (const OOI_ROVDataInput_t *ROVDataInput);

/*************************************************************************************************************************
  Functionname:    OOI_v_ReObRelObVerlustGrundInit                                                                      */ /*!

  @brief           Initialization function for structures used in object loss reason evaluation

  @description     Initialization function for structures used in object loss reason evaluation
					
		@startuml
		Start
		Partition OOI_v_ReObRelObVerlustGrundInit  {
			Repeat 
				: Initialize Object loss reason related Object data;
		Repeat While (For All OOI)
		}
		End
		@enduml

  @return          -

  @param[in]       -
  @param[out]      -

  @glob_in         - 
  @glob_out        OOI_b_ROVGHalteNearDistCondtition : Boolean indicating if relevant object loss is due to the near distance criteria [TRUE, FALSE]
  @glob_out        OOI_f_dKruemmungWaehrendROVMin : Array of curvatures during relevant object loss, array size                        [0u ... OOI_NUMBER_OF_OOI] [-1 ... +1] m^-1
  @glob_out        OOI_f_dROVGHalteDistanz : Array of distances used in relevant object loss, array size                               [0u ... OOI_NUMBER_OF_OOI] [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
  @glob_out        OOI_t_dROVGHalteVObjekt : Array of translatory velocity values, array size                                          [0u ... OOI_NUMBER_OF_OOI[ [-330.f ... 330.f] m/s
  @glob_out        OOI_b_RelObjDisappearedFlag : Array of boolean flags indicating relevant object has disappeared, array size         [0u ... OOI_NUMBER_OF_OOI] [TRUE, FALSE]
  @glob_out        OOI_f_rov_reset_time : Array of timers used in relevant object loss reset , array size                              [0u ... OOI_NUMBER_OF_OOI] [0.f ... OOI_ROV_RESET_TIME] s
  

  @c_switch_part   OOI_CFG_OBJLOSS_LOWDIST : Configuration switch enabling ObjectLossReason at low distance
  @c_switch_part   OOI_ROV_RESET_BY_TIME   : switch for enabling ROV reset condition by time
  @c_switch_part   OBJLOSS_NUMBER_OF_OOI   : switch for the number of OOIs for which object loss reasons are to be calculated
  @c_switch_full   FCT_CFG_ACC_OOI         : Configuration switch to configure OOI sub-component for FCT_ACC

  @pre             - 
  @post            No changes 

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         24.03.2016
  @changed         23.10.2001

  @author          Harsha Umesh Babu | harsha.umesh.babu@continental-corporation.com | +49 (8382) 9699-474
*************************************************************************************************************************/
static void OOI_v_ReObRelObVerlustGrundInit (void)
{
  ObjNumber_t i;
#if (OOI_CFG_OBJLOSS_LOWDIST)
    OOI_b_ROVGHalteNearDistCondtition     = FALSE;
#endif
  for(i = 0; i< OBJLOSS_NUMBER_OF_OOI; i++)
  {
    OOI_f_dKruemmungWaehrendROVMin[i]         = 0.0f;
    OOI_f_dROVGHalteDistanz[i]                = 0.0f;
    OOI_t_dROVGHalteVObjekt[i]                = 0.0f;
    OOI_b_RelObjDisappearedFlag[i]            = FALSE;
#if (OOI_ROV_RESET_BY_TIME == SWITCH_ON)
    OOI_f_rov_reset_time[i] = 0.0f;
#endif
  }
  for(i = 0; i< OOI_NUMBER_OF_OOI; i++)
  {
    pt_OOI_Output->OOI_t_eRelObjVerlustGrund[i]  = OBJ_LOSS_NO_INFO;
  }
}

/*************************************************************************************************************************
  Functionname:    OOI_v_ResetRelObjLossReason                                                                      */ /*!

  @brief           Reset function for structures used in object loss reason evaluation

  @description     Reset function for structures used in object loss reason evaluation
          
		@startuml
				Start 
					Partition OOI_v_ResetRelObjLossReason {
					- Reset object loss reason related object data for the object which was Object of Interest in previous cycle
					}
				End 
		@enduml

  @return          -

  @param[in]       -
  @param[out]      -

  @glob_in         - 
  @glob_out        OOI_b_ROVGHalteNearDistCondtition : Boolean indicating if relevant object loss is due to the near distance criteria [TRUE, FALSE]
  @glob_out        OOI_f_dKruemmungWaehrendROVMin : Array of curvatures during relevant object loss, array size                        [0u ... OOI_NUMBER_OF_OOI] [-1 ... +1] m^-1
  @glob_out        OOI_f_dROVGHalteDistanz : Array of distances used in relevant object loss, array size                               [0u ... OOI_NUMBER_OF_OOI] [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
  @glob_out        OOI_t_dROVGHalteVObjekt : Array of translatory velocity values, array size                                          [0u ... OOI_NUMBER_OF_OOI[ [-330.f ... 330.f] m/s
  @glob_out        OOI_b_RelObjDisappearedFlag : Array of boolean flags indicating relevant object has disappeared, array size         [0u ... OOI_NUMBER_OF_OOI] [TRUE, FALSE]
  @glob_out        OOI_f_rov_reset_time : Array of timers used in relevant object loss reset , array size                              [0u ... OOI_NUMBER_OF_OOI] [0.f ... OOI_ROV_RESET_TIME] s
  

  @c_switch_part   OOI_CFG_OBJLOSS_LOWDIST : Configuration switch enabling ObjectLossReason at low distance
  @c_switch_part   OOI_ROV_RESET_BY_TIME   : switch for enabling ROV reset condition by time
  @c_switch_full   FCT_CFG_ACC_OOI         : Configuration switch to configure OOI sub-component for FCT_ACC

  @pre             - 
  @post            No changes 

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         18.10.2019

  @author          Gowthama P | gowthama.p@continental-corporation.com 
*************************************************************************************************************************/
static void OOI_v_ResetRelObjLossReason (uint8 Nr)
{
#if (OOI_CFG_OBJLOSS_LOWDIST)
  OOI_b_ROVGHalteNearDistCondtition     = FALSE;
#endif

  OOI_f_dKruemmungWaehrendROVMin[Nr]         = 0.0f;
  OOI_f_dROVGHalteDistanz[Nr]                = 0.0f;
  OOI_t_dROVGHalteVObjekt[Nr]                = 0.0f;
  OOI_b_RelObjDisappearedFlag[Nr]            = FALSE;

#if (OOI_ROV_RESET_BY_TIME == SWITCH_ON)
  OOI_f_rov_reset_time[Nr] = 0.0f;
#endif

  pt_OOI_Output->OOI_t_eRelObjVerlustGrund[Nr]  = OBJ_LOSS_NO_INFO;
}

/*************************************************************************************************************************
  Functionname:    OOI_v_ObReObInit                                                                                     */ /*!

  @brief           Initialization function for relevant object loss

  @description     Initialization function for relevant object loss
					
		@startuml 
		Start
		Partition OOI_v_ObReObInit { 
			#Orange: <b>OOI_v_ReObRelObVerlustGrundInit()</b>:Initialize object loss reason related object data;
		}	
		End 
		@enduml

  @return          -

  @param[in]       -
  @param[out]      -

  @glob_in         - 
  @glob_out        - 

  @c_switch_part   - 
  @c_switch_full   FCT_CFG_ACC_OOI : Configuration switch to configure OOI sub-component for FCT_ACC

  @pre             - 
  @post            No changes 

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         24.03.2016
  @changed         23.10.2016

  @author          Harsha Umesh Babu | harsha.umesh.babu@continental-corporation.com | +49 (8382) 9699-474
*************************************************************************************************************************/
void OOI_v_ObReObInit (void)
{
  OOI_v_ReObRelObVerlustGrundInit ( );
}


/*************************************************************************************************************************
  Functionname:    OOI_t_SeReObFastTrackAbschaltung                                                                     */ /*!

  @brief           Suppression of the relevant object due to large curvature during driving.

  @description     Suppression of the relevant object due to large curvature during driving.
					
		@startuml
		Start 
			Partition OOI_t_SeReObFastTrackAbschaltung {
				- Set default Fast Track SwitchOff to No switch off
				- Calculate curvature using Ego Curvature and Curvature Scale
				If (Curvature value is more than OOI_KRUEMMUNGGRENZ) then (true)
					- Set Fast Track SwitchOff to Right Curve Switch off
				Elseif (Curvature value is less than - OOI_KRUEMMUNGGRENZ) then (true) 
					- Set Fast Track SwitchOff to Left Curve Switch off
				Else (false)
					- Set Fast Track SwitchOff to No switch off
				Endif		 
			}
		End 
		@enduml

  @return          FastTrackSwitchOff : Enum describing the object loss reason due to large curvature [Full range of datatype OOI_FastTrackSwitchOff_t as defined in ooi_objloss.c]

  @param[in]       -
  @param[out]      -

  @glob_in         pt_OOI_Input->t_RTE.pf_EgoCurve   : Ego curve    [-1.f ... 1.f] 1/m
  @glob_in         pt_OOI_Input->t_RTE.pf_EgoVelObjSync : Ego speed    [-330.f ... 330.f] m/s
  @glob_out        - 

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_OOI : Configuration switch to configure OOI sub-component for FCT_ACC

  @pre             - 
  @post            No changes 

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         09.11.2009
  @changed         24.03.2016

  @author          Harsha Umesh Babu | harsha.umesh.babu@continental-corporation.com | +49 (8382) 9699-474
*************************************************************************************************************************/
static OOI_FastTrackSwitchOff_t OOI_t_SeReObFastTrackAbschaltung(void)
{
  OOI_FastTrackSwitchOff_t FastTrackSwitchOff;
  fCurve_t fCurveFast;
  
  /*! Set default to "No switch off" */
  FastTrackSwitchOff = NO_SWITCH_OFF;
  /* Holen der Schnellen-Spur */
  fCurveFast = OOI_FAST_CURVE_SCALE * (*pt_OOI_Input->t_RTE.pf_EgoCurve);


    if( fCurveFast > OOI_KRUEMMUNGGRENZ )
    {
      FastTrackSwitchOff = RIGHT_CURVE_SWITCH_OFF;
    }
    else if( fCurveFast < -OOI_KRUEMMUNGGRENZ )
    {
      FastTrackSwitchOff = LEFT_CURVE_SWITCH_OFF;
    }
    else
    {
      FastTrackSwitchOff = NO_SWITCH_OFF;
    }


  return FastTrackSwitchOff;
}

/*************************************************************************************************************************
  Functionname:    OOI_v_ObReObRelObjLossReason                                                                         */ /*!

  @brief           Identify and reset the relevant object loss reason.

  @description     Identify and reset the relevant object loss reason. Causes for relevant object loss:
                    OBJ_LOSS_NO_INFO,
                    OBJ_LOSS_DISAPPEARED,
                    OBJ_LOSS_LANE_CHG_LEFT (not used),
                    OBJ_LOSS_LANE_CHG_RIGHT (not used),
                    OBJ_LOSS_CURVE_LEFT,
                    OBJ_LOSS_CURVE_RIGHT,
                    OBJ_LOSS_CURVE_LEFT_AHEAD (not used),
                    OBJ_LOSS_CURVE_RIGHT_AHEAD (not used),
                    OBJ_LOSS_STEER_LEFT,
                    OBJ_LOSS_STEER_RIGHT

                    While determining the cause the information about relevant object(from previous cycle) is 
                    compared with the data from the object indicated by RelTrckObjNr (relevant object in current cycle).
                    
		@startuml
		Start 
			Partition OOI_v_ObReObRelObjLossReason {
				- Get object id of last cycle relvant object
				- Initialize Object Loss Reason data with various parameters
				If (New Object ID is not equal to old Object Id and Old Object is valid Object) then (yes)
					#Orange:<b>OOI_v_ObReObRelObjVerlustSetzenTimeDist</b>: To Set relevent object loss using time gap criteria;
				Else (no)
					#Orange:<b>OOI_v_ObReObRelObjVerlRueckTimeDist</b>: To Reset relevant object loss reason;	
				Endif
				If(Old Object is valid Object)then (yes)
					#Orange:<b>OOI_b_CheckTargetLossDueToLateralPositionDrift</b>: OOI-0 loss due to lateral drift of target object during EGO and Target standstill situation;
				Else (no)
					: Do Nothing;
				Endif
			}
		End 
		@enduml

  @return          -

  @param[in]       NewObjId : Object ID of current relevant object                                                [0u ... EM_N_OBJECTS-1]
  @param[in]       pOldObject : Reference to data structure containing information about previous relevant object 
                      ObjectNr : Object ID of previous relevant object                                            [0u ... EM_N_OBJECTS-1]
                      ObjValid : Boolean set to TRUE if object is valid                                           [TRUE, FALSE]
                      DistX : Longitudinal distance of object in X direction                                      [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                      StatObj : Boolean set to TRUE if object is stationary                                       [TRUE, FALSE]       
  @param[in]       SiOOINr : Index of the object whose loss is being evaluated                                    [Full range of datatype OOI_RelObjEnum_t as defined in ooi_ext.h]
  @param[out]      -

  @glob_in         * pt_OOIInput->t_RTE.pf_ObjLongDisp(i) : Longitudinal displacement of an object i      [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                                              with i in [0u ... EM_N_OBJECTS-1]
  @glob_in         pt_OOI_Input->t_RTE.pf_EgoCurve : Ego curve                                           [-1.f ... 1.f] 1/m
  @glob_in         pt_OOI_Input->t_RTE.pf_EgoVelObjSync : Ego speed                                         [-330.f ... 330.f] m/s
  @glob_in         EGO_CURVE_GRAD_OBJ_SYNC : Gradient of the Ego curve                      [-1.f   1.f] 1/m
  @glob_out        - 

  @c_switch_part   OOI_CFG_OBJLOSS_LOWDIST : Configuration switch enabling ObjectLossReason at low distance
  @c_switch_full   FCT_CFG_ACC_OOI         : Configuration switch to configure OOI sub-component for FCT_ACC

  @pre             - 
  @post            No changes 

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @traceability    363:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-363-00061542 \n
                   398:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-398-00061542 \n

  @created         15.03.2007
  @changed         24.03.2016

  @author          Harsha Umesh Babu | harsha.umesh.babu@continental-corporation.com | +49 (8382) 9699-474
*************************************************************************************************************************/
void OOI_v_ObReObRelObjLossReason(const ObjNumber_t NewObjId, const OOI_RelObject_t* pOldObject, OOI_RelObjEnum_t SiOOINr)
{
/*--- VARIABLES ---*/
  fCurve_t fCurveFast;
  OOI_ROVDataInput_t ROVDataInput;
  ObjNumber_t OldObjId;

  OldObjId   = pOldObject->ObjectNr;

  fCurveFast = OOI_FAST_CURVE_SCALE * (*pt_OOI_Input->t_RTE.pf_EgoCurve);

  ROVDataInput.RelTrckObjNr           = NewObjId;
  ROVDataInput.pRelObj                = pOldObject;   /*!< Remark: pOldObject points to the global variable OOI_RelObject, which is properly initialized -> variables of the structure can be always accessed */
  ROVDataInput.TPVehicleSpeed         = *pt_OOI_Input->t_RTE.pf_EgoVelObjSync;
  ROVDataInput.TrackStandardCurve     = *pt_OOI_Input->t_RTE.pf_EgoCurve;
  ROVDataInput.TrackStandardGradient  = *SLATE_pf_GetEgoCurveGrad();
  ROVDataInput.TrackFastCurve         = fCurveFast;
  ROVDataInput.OOINr                  = (uint8)SiOOINr;

  /* I.)   Wenn kein relevantes Objekt ermittelt wurde, */
  /* II.)  Bisher muss ein fahrendes Objekt relevant gewesen sein. */
  /* III.) Die Fahrzeug mindest Eigenschwindigkeit > OOI_ROVG_VEIGENMIN betragen. */
  /*       Dann muß ein Relevant Objekt Verlustgrund detektiert werden ! */

    if( (NewObjId != OldObjId) &&
      ( pOldObject->ObjValid == TRUE )
      )
  {
    /* Setzen eines detektierten ROVG */
    OOI_v_ObReObRelObjVerlustSetzenTimeDist( &ROVDataInput );
  }
  else
  {
    /* Loeschen eines detektierten ROVG */
    OOI_v_ObReObRelObjVerlRueckTimeDist( &ROVDataInput );
  }

  if( pOldObject->ObjValid == TRUE )
  {
    /* OOI-0 loss due to lateral drift of target object during EGO and Target standstill situation */
    OOI_b_CheckTargetLossDueToLateralPositionDrift(&ROVDataInput);
  }
}




/*************************************************************************************************************************
  Functionname:    OOI_v_ObReObRelObjVerlustSetzenTimeDist                                                              */ /*!

  @brief           Function to set relevant object loss using time-gap criterion.

  @description     Evaluate and set the relevant object loss reason based on time-gap criteria.

		@startuml
		Start
		Partition OOI_v_ObReObRelObjVerlustSetzenTimeDist {
			If(Ego motion state is standard stationary motion state and Ego motion state is ok) then (yes)
				: Set relevant Object counter value is set to EGO Standstill value;
			Else (no)
				: Set relevant Object counter as Object is Moving;
			Endif
			If (Relevant Object Distance in X direction is less than OOI_ROVG_GRENZE_BX) then (yes)
				: Update critical angle as OOI_ROVG_GRENZWINKEL_BX_NEU;
			Endif
			If(Vehicle speed is greater than C_F32_DELTA) then (yes)
				: Calculate the relative time using Distance and vehicle speed;
			Else (no)
				: Set Relative Time as Max Time;
			Endif
			If (No Object loss reason) then (yes)
				If (No Relative Track object) then (yes)
					If (Object is moving) then (yes)
						If (Vehicle Speed is greater than OOI_ROVG_VEIGENMIN)then(yes)
							If(Relative Time is less than Max time and Relative Object Distance is less than or equal to Max Distance) then (yes)
								If (Track Standard Curve is greater than 0.0f and Relative Object Angle is greater than critical angle) then (yes)
									If (Get Lane Associate of Base Preselection of Object has to be fulfilled and Object Associated Lane is Right and Object is already existed) then (yes)
										: Do Nothing;
									Else(no)
										: Update Object Associate lane as Left;
										: Reset relevant object loss reason;
									Endif
								Elseif (Track Standard curve is less than 0.f and Relative Object Angle is less than -critical angle) then (yes)
									If (Get Lane Associate of Base Preselection of Object has to be fulfilled and Object Associated Lane is Left and Object is already existed) then (yes)
										: Do Nothing;
									Else(no)
										: Update Object Associatelane as Right;
										: Reset relevant object loss reason;
									Endif
								Else (no)
									: Do Nothing;
								Endif
							Endif
						Endif
					Endif
				Endif
			If (No Object Loss Reason) then (yes)
				If (Trace Bracket Right - Distance of object in Y direction is less than 0.f and Trace Bracket Left - Distance of object in Y direction is greater than 0.f and OOI Number is OBJ_NEXT_OOI) then (yes)
					If(ACC Object Quality is less than Minimum ACC Quality level)then(yes)
						If(No Relative Track Object and No Object of Interest) then (yes)						If (Object angle is less than critical Angle) then (yes)
								If (Track Standard Curve is less than OOI_ROVG_GRENZKRUEMMUNG_AUS and Related Object Distance is less than Max Distance and greater than or equal to Minimum Distance and Relative Object Counter is greater than or equal to Ego Moving Object counter) then (yes)
									: Update Distance and Speed od object;
									: Relative Object Disappeared Flag is enabled;
								Endif
							Endif
						Endif
					Endif
				Endif
			Endif
			If (No Object loss reason) then (yes)
				If (No Track object) then (yes)
					: Check for narrow ego curve in the left or right direction;
					If (narrow ego curve is in right direction) then (yes)
						: Steer strong right turn;
					Else if (narrow ego curve is in left direction) then (yes)
						: Steer Strong left turn;
					Else (no)
						: Reset Object loss reason;
					Endif
				Else (no)
					: Do Nothing;
				Endif
			Endif 
			If(No Object loss reason) then (yes)
				If(No Track Object) then (yes)
					If (Object is stationary) then (yes)
						If(Vehicle Speed is more than minimum speed) then (yes)
							If(Old Relative Object Distance in X direction is more than Object Dependant Maximum Range)then(yes)
								: Set Object loss reason as OBJ_LOSS_RANGE_REDUCTION;
							Endif
						Endif
					Endif
				Endif
			Endif
			If(No Object loss reason) then (yes)
				If(No Track Object) then (yes)
					If (Object is stationary and Object Dynamic property is not Oncoming) then (yes)
						If(Vehicle Speed is more than minimum speed)then(yes)
							If(Relative Object Distance in X direction is more than Minimum Distance)
								If(Track Standard Curvature is more than Maximum Curvature and Object Angle is more than critical angle) then (yes)
									: Set Object loss reason as OBJ_LOSS_CURVE_LEFT_AHEAD;
								Else if(Track Standard Curve is less than -Maximum Curvature and Object Angle is less than -critical angle) then (yes)
									: Set Object loss reason as OBJ_LOSS_CURVE_RIGHT_AHEAD;
								Else(no)
									: Do Nothing;
								Endif
							Endif
						Endif
					Endif
				Endif
			Endif
			If(No Object loss reason) then (yes)
				If(No Track Object) then (yes)
					If (Object is stationary) then (yes)
						If(Vehicle Speed is more than minimum speed)then(yes)
							If((Pre Lane change stage or Left Lane Change) and maximum Probability For Lane change and Left Lane Change Phase State and Object Associated Lane is Right)then(yes)
								: Set Object Loss Reason as OBJ_LOSS_EGO_LANE_CHG_LEFT;
							Else if (((Pre Lane change stage or Left Lane Change) and maximum Probability For Lane change and Right Lane Change Phase State and Object Associated Lane is Left) then (yes)
								: Set Object Loss Reason as OBJ_LOSS_EGO_LANE_CHG_RIGHT;
							Else (no)
								: Do Nothing;
							Endif
						Endif
					Endif
				Endif
			Endif
			If(No Object loss reason) then (yes)
				If(No Track Object) then (yes)
					If (Object is stationary) then (yes)
						If(Vehicle Speed is more than minimum speed)then(yes)
							If(Object Associated Lane is Left or Far Left) then (yes)
								: Set Object Loss Reason as OBJ_LOSS_LANE_CHG_LEFT;
							Else if(Object Associated Lane is Right or Far Right) then (yes)
								: Set Object Loss Reason as OBJ_LOSS_LANE_CHG_RIGHT;
							Else (no)
								: Do Nothing;
							Endif
						Endif
					Endif
				Endif
			Endif
			If(No Object loss reason) then (yes)
				: Check for custom Object loss reason;
			Endif
			: Set Object loss reason for Critically disappeared cut-in object;
		}		
		End
		@enduml

  @return          -

  @param[in]       ROVDataInput : reference to data structure containing info about relevant object loss scenario            
                      TPVehicleSpeed : EGO vehicle speed at time of relevant object loss scene evaluation                       [-330.f ... 330.f] m/s
                      TrackStandardCurve : EGO curvature                                                                        [-1 ... +1] m^-1
                      TrackStandardGradient : EGO curvature gradient                                                            [-1 ... +1] m^-1
                      OOINr : Index of the object whose loss is being evaluated                                                 [OOI_NUMBER_OF_OOI as defined in si_ext.h]
                      RelTrckObjNr : Index of the object which was being tracked and now lost                                   [0u ... EM_N_OBJECTS-1]
                      bNearDistCondtition : Boolean indicating if relevant object loss is due to the near distance criteria     [TRUE, FALSE]
                      pRelObj->DistX : Longitudinal distance of the current relevant object                                     [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                      pRelObj->ObjAngle : Angle from EGO perpective where current relevant object is found                      [-PI ... +PI] rad
                      pRelObj->ObjectNr : Object ID of the relevant object                                                      [0u ... EM_N_OBJECTS-1]
                      pRelObj->LatDisplRoadBordR : Lateral road border right for current relevant object                        [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      pRelObj->LatDisplRoadBordL : Lateral road border left for current relevant object                         [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      pRelObj->ObjDistY : Lateral position of the currentl relevant object                                      [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @param[out]      -

  @glob_in         pt_OOI_Input->t_LAInput.pb_BasePreselObjList(i) : Boolean                                                    [TRUE, FALSE]
                                                                     with i in [0u ... EM_N_OBJECTS-1]     
  @glob_in         SLATE_b_GetObjIsNew(i) : Information if administration state of object i is EM_GEN_OBJECT_MT_STATE_NEW                [TRUE, FALSE]
                                   with i in [0u ... EM_N_OBJECTS-1]                                       
  @glob_in         OBJ_GET_ASSOCIATED_LANE(i) : Associated lane information of an object i                                      [Full range of datatype eAssociatedLane_t as in Rte_Type.h]
                                                with i in [0u ... EM_N_OBJECTS-1]
  @glob_in         SLATE_u_GetAccQuality(i) : ACC quality of object i which includes cluster variance information      [0 ... 100]
                                                       with i in [0u ... EM_N_OBJECTS-1]
  @glob_out        OOI_b_RelObjDisappearedFlag : Array of boolean flags indicating relevant object has disappeared, array size  [0u ... OOI_NUMBER_OF_OOI] [TRUE, FALSE]
  @glob_out        pt_OOI_Output->OOI_t_eRelObjVerlustGrund : Array of structure for processing object loss reason, array size  [0u ... OOI_NUMBER_OF_OOI] [Full range of datatype eRelObjLossReason_t as defined in Rte_Type.h]
  @glob_out        OOI_f_dKruemmungWaehrendROVMin : Array of curvatures during relevant object loss, array size                 [0u ... OOI_NUMBER_OF_OOI] [-1 ... +1] m^-1
  @glob_out        OOI_f_rov_reset_time : Array of timers used in relevant object loss reset , array size                       [0u ... OOI_NUMBER_OF_OOI] [0.f ... OOI_ROV_RESET_TIME] s
  @glob_out        OOI_t_dROVGHalteVObjekt : Array of translatory velocity values, array size                                   [0u ... OOI_NUMBER_OF_OOI] [-330.f ... 330.f] m/s
  @glob_out        OOI_f_dROVGHalteDistanz : Array of distances used in relevant object loss, array size                        [0u ... OOI_NUMBER_OF_OOI] [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
  @glob_out        OOI_b_ROVGHalteNearDistCondtition : Boolean indicating if relevant object loss is due to the near distance criteria [TRUE, FALSE]

  @c_switch_part   OOI_CFG_OBJLOSS_LOWDIST      : Configuration switch enabling ObjectLossReason at low distance
  @c_switch_part   FCT_CFG_ACC_LANE_ASSOCIATION : FCT support for ACC LA (Lane Association) sub-component
  @c_switch_part   OOI_ROV_RESET_BY_TIME        : switch for enabling ROV reset condition by time
  @c_switch_part   OBJLOSS_NUMBER_OF_OOI        : switch for the number of OOIs for which object loss reasons are to be calculated
  @c_switch_full   FCT_CFG_ACC_OOI              : Configuration switch to configure OOI sub-component for FCT_ACC

  @pre             -
  @post            No changes

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @traceability    363:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-363-00061542 \n
                   364:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-364-00061542 \n
                   365:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-365-00061542 \n
                   366:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-366-00061542 \n
                   367:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-367-00061542 \n
                   368:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-368-00061542 \n
                   

  @created         15.03.2007
  @changed         24.03.2016

  @author          Harsha Umesh Babu | harsha.umesh.babu@continental-corporation.com | +49 (8382) 9699-474
*************************************************************************************************************************/
static void OOI_v_ObReObRelObjVerlustSetzenTimeDist (const OOI_ROVDataInput_t *ROVDataInput)
{
  float32 TimeDist;
  float32 f_TPVehicleSpeed;
  float32 dGrenzwinkel = OOI_ROVG_GRENZWINKEL;
  uint8 u_relobjcountervalue = OOI_ROV_RELEVANT_OBJ_COUNTER_EGO_MOVING;
  OOI_FastTrackSwitchOff_t FastTrackSwitchOff;
  MotState_t t_EGOMotionState = SLATE_t_GetEGOMotionState();
  VDYIoStateTypes_t uEgoMotionState = SLATE_u_EgoMotionState();
  SLATE_t_Obj_DynamicProperty Obj_DynamicProperty = *(pt_OOI_Input->t_RTE.pf_ObjDynProperty(ROVDataInput->pRelObj->ObjectNr));
  boolean b_ObjIsNew = SLATE_b_GetObjIsNew(ROVDataInput->pRelObj->ObjectNr);
  SIT_LC_t_LaneChangePhaseEnum t_LCPhase = pt_OOI_Input->t_SITInput.pt_GetLaneChangePhase->t_LCPhase;
  SIT_LC_t_LaneChangeState t_LCPhaseState = pt_OOI_Input->t_SITInput.pt_GetLaneChangePhase->t_LCPhaseState;
  sint16 s_LaneChangeProbability = *pt_OOI_Input->t_SITInput.pt_GetLaneChangeProb;
  eAssociatedLane_t t_ObjAssociatedLane = pt_OOI_Input->t_LAInput.pt_LAObjectList(ROVDataInput->pRelObj->ObjectNr)->ObjAssociatedLane;
  float32 ObjDependantMaxRange = pt_OOI_Input->t_LAInput.pt_LAObjectList(ROVDataInput->pRelObj->ObjectNr)->ObjDependantMaxRange;
  float32 f_OldRelObjDistX = *pt_OOI_Input->t_RTE.pf_ObjLongDisp(ROVDataInput->pRelObj->ObjectNr);
#if (FCT_CFG_ACC_LANE_ASSOCIATION)
  boolean b_BasePreselObjList = *(pt_OOI_Input->t_LAInput.pb_BasePreselObjList(ROVDataInput->pRelObj->ObjectNr));
#endif

#if (OOI_CFG_OBJLOSS_LOWDIST)
  ObjNumber_t NewObjId = ROVDataInput->RelTrckObjNr;
  float32 f_ObjLongDisp = 0.f;
  const float32 dGrenzwinkelFOV = RAD2DEG(ALGO_f_AzMaxSpecNear)*0.8f;

  if(ROVDataInput->RelTrckObjNr != OBJ_INDEX_NO_OBJECT)
  {
    f_ObjLongDisp = *pt_OOI_Input->t_RTE.pf_ObjLongDisp(NewObjId);
  }
#endif

  OOI_b_RelObjDisappearedFlag[ROVDataInput->OOINr] = FALSE;

  /* Update relevency check counter value based on EGO motion state */
  if ((t_EGOMotionState ==  VDY_LONG_MOT_STATE_STDST) && (IS_SIGNAL_STATUS_OK(uEgoMotionState)))
  {
    u_relobjcountervalue = OOI_ROV_RELEVANT_OBJ_COUNTER_EGO_STANDSTILL ;
  }
  else
  {
    u_relobjcountervalue = OOI_ROV_RELEVANT_OBJ_COUNTER_EGO_MOVING ;
  }

  /* Anderer Grenzwinkel fuer nahe Verfolgte: */
  /*!< Remark: pRelObj points to the global variable OOI_RelObject, which is properly initialized -> variables of the structure can be always accessed */
  if (ROVDataInput->pRelObj->DistX < OOI_ROVG_GRENZE_BX)
  {
    dGrenzwinkel = OOI_ROVG_GRENZWINKEL_BX_NEU;
  }

  f_TPVehicleSpeed = fABS(ROVDataInput->TPVehicleSpeed);
  if(f_TPVehicleSpeed > C_F32_DELTA)
  {
    TimeDist = ROVDataInput->pRelObj->DistX / ROVDataInput->TPVehicleSpeed;
  }
  else
  {
    TimeDist = OOI_ROV_SET_MAX_TIME_DIST;
  }


#if (OOI_CFG_OBJLOSS_LOWDIST)
  if (pt_OOI_Output->OOI_t_eRelObjVerlustGrund[ROVDataInput->OOINr] == OBJ_LOSS_NO_INFO)
  {
    /* I.)   Bisher muss ein fahrendes Objekt mit kleiner DistX relevant gewesen sein. */
    /* II.)   kein neues Object, oder ein neues object hinter dem bisherigen, */
    if(( ROVDataInput->pRelObj->DistX  < OOI_ROV_LOWDIST_THRES ) &&
       (  (NewObjId == OBJ_INDEX_NO_OBJECT)
        ||((NewObjId != ROVDataInput->pRelObj->ObjectNr) &&
          ((f_ObjLongDisp - ROVDataInput->pRelObj->DistX ) > OOI_ROV_DISTXSKIP_THRES))
       ) &&
       (ROVDataInput->pRelObj->RelObjCounter >= u_relobjcountervalue)
      )
    {
      /* I.)   When old Object was in FOV (not on the edges of the FOV), */
      /* II.)  Only by NearDistCondition. */
      /* III.) The old object is not associated as the left or right object. This means that 
      there was no transition of from Ego-Lane to a neighbor lane. This is "suspicious". Possible reasons: 
      Lost of the ACC Quality or change of the moving status in this Cycle from CROSSING/ONCOMMING */
      /* IV.)  curve not stronger than the typical roundabout. */
      const float32 f_AbsObjAngle = fABS(ROVDataInput->pRelObj->ObjAngle);
      if(  (f_AbsObjAngle < dGrenzwinkelFOV)
         &&(((t_ObjAssociatedLane != ASSOC_LANE_LEFT)
         &&(t_ObjAssociatedLane != ASSOC_LANE_RIGHT)
         &&(ROVDataInput->OOINr == (uint8)OBJ_NEXT_OOI))
#if (OBJLOSS_NUMBER_OF_OOI >1)
        || (   (ROVDataInput->OOINr == OBJ_HIDDEN_NEXT_OOI)
            && (t_ObjAssociatedLane != ASSOC_LANE_LEFT) 
            && (t_ObjAssociatedLane != ASSOC_LANE_RIGHT))
        || (   (ROVDataInput->OOINr == OBJ_NEXT_LONG_LEFT_OOI)
            && (t_ObjAssociatedLane != ASSOC_LANE_FAR_LEFT) 
            && (t_ObjAssociatedLane != ASSOC_LANE_EGO))
        || (   (ROVDataInput->OOINr == OBJ_NEXT_LONG_RIGHT_OOI)
            && (t_ObjAssociatedLane != ASSOC_LANE_FAR_RIGHT) 
            && (t_ObjAssociatedLane != ASSOC_LANE_EGO))
#endif
          )
        )
      {
        pt_OOI_Output->OOI_t_eRelObjVerlustGrund[ROVDataInput->OOINr] = OOI_v_ObjLossLowDist();
        OOI_b_RelObjDisappearedFlag[ROVDataInput->OOINr] = TRUE;
        OOI_f_dROVGHalteDistanz[ROVDataInput->OOINr]     = ROVDataInput->pRelObj->DistX;
        OOI_t_dROVGHalteVObjekt[ROVDataInput->OOINr]     = ROVDataInput->TPVehicleSpeed;
        OOI_b_ROVGHalteNearDistCondtition                = TRUE;
#if (OOI_ROV_RESET_BY_TIME == SWITCH_ON)
        OOI_f_rov_reset_time[ROVDataInput->OOINr] = OOI_ROV_RESET_TIME;
#endif
      }
    }
  }
#endif /* END IF OOI_CFG_OBJLOSS_LOWDIST */


  /* 13.10.07 Definition ZVG-Kurve ab R3.3.1 (Kolb+Reichmann):
  Auslösen:
  Objekte_Y_Ablage ausserhalb sicherem FBR Erfassungsbe. ca. +/-6.0° 
  UND Objekt_X_Abst < 100m 
  UND Objekt_X_Zeitabstand < 2,5 Sek.
  UND Objektverlust aus Spur in Richtung kl. Radius (Kurveninnenseitig)

  Aufheben im gleichen Systemzyklus (Überschreibt Auslösen-Kritierien):
  Sichtweite im sicheren FBR Erfassungsbe. > 100m
  ODER Sichtweite im sicheren FBR Erfassungsbereich > 4.0 Sek Zeitab.*/
  if (pt_OOI_Output->OOI_t_eRelObjVerlustGrund[ROVDataInput->OOINr] == OBJ_LOSS_NO_INFO)
  {
    if (ROVDataInput->RelTrckObjNr == OBJ_INDEX_NO_OBJECT)
    {
      if ( ROVDataInput->pRelObj->StatObj == FALSE)
      {
        if(ROVDataInput->TPVehicleSpeed > OOI_ROVG_VEIGENMIN)
        {
          if (  (TimeDist < OOI_ROV_SET_MAX_TIME_DIST)
              &&( ROVDataInput->pRelObj->DistX <= OOI_ROV_MAX_DIST)
             )
          {
            /*Linkskurve und Objekt war links !!!!*/
            if (   (ROVDataInput->TrackStandardCurve > 0.f)
                && (ROVDataInput->pRelObj->ObjAngle  > dGrenzwinkel))
            {
              /* Objekt noch da, aber zum Kurvenaussenrand verschwunden ? */
#if (FCT_CFG_ACC_LANE_ASSOCIATION)
              if (  (b_BasePreselObjList == TRUE )
                  &&(pt_OOI_Input->t_LAInput.pt_LAObjectList(ROVDataInput->pRelObj->ObjectNr)->ObjAssociatedLane == ASSOC_LANE_RIGHT)
#endif
                  &&(!b_ObjIsNew))
              {
                /* Objekt zum Kurvenausenrand verschwunden --> kein Zielverlustgrund */
              }
              else
              {
                /* Objekt ist nict mehr sichtbar --> Zielverlustgrund */
                pt_OOI_Output->OOI_t_eRelObjVerlustGrund[ROVDataInput->OOINr] = OBJ_LOSS_CURVE_LEFT;
                OOI_f_dKruemmungWaehrendROVMin[ROVDataInput->OOINr] = ROVDataInput->TrackStandardCurve;

#if (OOI_ROV_RESET_BY_TIME == SWITCH_ON)
        OOI_f_rov_reset_time[ROVDataInput->OOINr] = OOI_ROV_RESET_TIME;/* PRQA S 2200 *//* Date: 2020-04-02, Reviewer:Tejaswini M , Reason:This warning is suppressed as Indentation does not have any critical impact  on the functionality. */
#endif
                /* Falls parallel Ruecksetzgruende vorhanden, ueberwiegen diese !! */
                OOI_v_ObReObRelObjVerlRueckTimeDist(ROVDataInput);
              }
            }
            /* Rechtskurve, Objekt war rechts */
            else if (   (ROVDataInput->TrackStandardCurve < 0.f)
                     && (ROVDataInput->pRelObj->ObjAngle < -dGrenzwinkel))
            {
              /* Objekt noch da, aber zum Kurvenaussenrand verschwunden ? */
#if (FCT_CFG_ACC_LANE_ASSOCIATION)
              if (  (b_BasePreselObjList == TRUE )
                  &&(pt_OOI_Input->t_LAInput.pt_LAObjectList(ROVDataInput->pRelObj->ObjectNr)->ObjAssociatedLane == ASSOC_LANE_LEFT)
#endif
                  &&(!b_ObjIsNew))
              {
                /* Objekt zum Kurvenausenrand verschwunden --> kein Zielverlustgrund */
              }
              else
              {
                /* Objekt ist nict mehr sichtbar --> Zielverlustgrund */
                pt_OOI_Output->OOI_t_eRelObjVerlustGrund[ROVDataInput->OOINr] = OBJ_LOSS_CURVE_RIGHT;
                OOI_f_dKruemmungWaehrendROVMin[ROVDataInput->OOINr] = ROVDataInput->TrackStandardCurve;

#if (OOI_ROV_RESET_BY_TIME == SWITCH_ON)
                OOI_f_rov_reset_time[ROVDataInput->OOINr] = OOI_ROV_RESET_TIME;
#endif
                /* Falls parallel Ruecksetzgruende vorhanden, ueberwiegen diese !! */
                OOI_v_ObReObRelObjVerlRueckTimeDist(ROVDataInput);
              }
            }
            else
            {
              /* do nothing but satisfy lint */
            }
          }
        }
      }
    }
  }


  /* Hier Nachbearbeitung, um OBJ_LOSS_DISAPPEARED zu detektieren: */
  if (pt_OOI_Output->OOI_t_eRelObjVerlustGrund[ROVDataInput->OOINr] == OBJ_LOSS_NO_INFO)
  {
    if(   ((( ROVDataInput->pRelObj->LatDisplRoadBordR - ROVDataInput->pRelObj->ObjDistY ) < 0.F )
       && (( ROVDataInput->pRelObj->LatDisplRoadBordL - ROVDataInput->pRelObj->ObjDistY ) > 0.F )
          && (ROVDataInput->OOINr == (uint8)OBJ_NEXT_OOI))
#if (OBJLOSS_NUMBER_OF_OOI >1)
      || (  ((ROVDataInput->pRelObj->LatDisplRoadBordR - ROVDataInput->pRelObj->ObjDistY) < 0.F)
          && (( ROVDataInput->pRelObj->LatDisplRoadBordL - ROVDataInput->pRelObj->ObjDistY ) > 0.F)
          && (ROVDataInput->OOINr == OBJ_HIDDEN_NEXT_OOI))
      || (   ((ROVDataInput->pRelObj->LatDisplRoadBordR - ROVDataInput->pRelObj->ObjDistY) < 0.F)
          && (( ROVDataInput->pRelObj->LatDisplRoadBordL - ROVDataInput->pRelObj->ObjDistY ) < 0.F)
          && ((ROVDataInput->OOINr == OBJ_NEXT_LONG_LEFT_OOI) || (ROVDataInput->OOINr == OBJ_NEXT_LAT_LEFT_OOI)))
      || (   ((ROVDataInput->pRelObj->LatDisplRoadBordR - ROVDataInput->pRelObj->ObjDistY) > 0.F)
          && (( ROVDataInput->pRelObj->LatDisplRoadBordL - ROVDataInput->pRelObj->ObjDistY ) > 0.F)
          && ((ROVDataInput->OOINr == OBJ_NEXT_LONG_RIGHT_OOI) || (ROVDataInput->OOINr == OBJ_NEXT_LAT_RIGHT_OOI)))
#endif
      )
    {
      if (SLATE_u_GetAccQuality(ROVDataInput->pRelObj->ObjectNr) < FUN_PRESEL_ACC_MIN_OBJ_QUAL)
      {
        if (   (ROVDataInput->RelTrckObjNr == OBJ_INDEX_NO_OBJECT)
            && (FCTSEN_pPubFctObjList->ObjList[ROVDataInput->pRelObj->ObjectNr].ObjOfInterest.eObjOOI == OBJ_NOT_OOI)
           )
        {
          /* Angle of the object within corresponding angle limits */
          /* dGrenzwinkel (Critical angle) here : OOI_ROVG_GRENZWINKEL */
          float32 f_Abs_ObjAngle = fABS(ROVDataInput->pRelObj->ObjAngle);
          if (f_Abs_ObjAngle < dGrenzwinkel)
          {
            /* TB A ARS200 SCR 159  20-12-2004 */
            float32 f_Abs_TrackStandardCurve = fABS(ROVDataInput->TrackStandardCurve);
            if(   (f_Abs_TrackStandardCurve < OOI_ROVG_GRENZKRUEMMUNG_AUS)
               && (ROVDataInput->pRelObj->DistX < OOI_ROV_MAX_DIST)
               &&
#if (OOI_CFG_OBJLOSS_LOWDIST)
                  (ROVDataInput->pRelObj->DistX >= OOI_ROV_LOWDIST_THRES)
#endif /*(OOI_CFG_OBJLOSS_LOWDIST)*/
#if (!OOI_CFG_OBJLOSS_LOWDIST)
                  (ROVDataInput->pRelObj->DistX >= OOI_ROV_MIN_DIST) 
#endif /*(!OOI_CFG_OBJLOSS_LOWDIST)*/
               && (ROVDataInput->pRelObj->RelObjCounter >= u_relobjcountervalue)
              )
            {
               /* PRQA S 715 */
               /* date: 2018-10-10, reviewer: Ravi Kiran, reason: Nested control structures exceeds 15, not safety critical */
                /* TB E ARS200 SCR 159  20-12-2004 */
                pt_OOI_Output->OOI_t_eRelObjVerlustGrund[ROVDataInput->OOINr]  = OBJ_LOSS_DISAPPEARED;
                OOI_f_dROVGHalteDistanz[ROVDataInput->OOINr]    = ROVDataInput->pRelObj->DistX;
                OOI_t_dROVGHalteVObjekt[ROVDataInput->OOINr]    = ROVDataInput->TPVehicleSpeed;
                OOI_b_RelObjDisappearedFlag[ROVDataInput->OOINr] = TRUE;

#if (OOI_ROV_RESET_BY_TIME == SWITCH_ON)
                OOI_f_rov_reset_time[ROVDataInput->OOINr] = OOI_ROV_RESET_TIME;
#endif
            }
          }
        }
      }
    }
  }

  /* Object loss reason is set if target loss occurs due to streeing */
  if (pt_OOI_Output->OOI_t_eRelObjVerlustGrund[ROVDataInput->OOINr] == OBJ_LOSS_NO_INFO)
  {
    if (ROVDataInput->RelTrckObjNr == OBJ_INDEX_NO_OBJECT)
    {
      /* Check for narrow ego curve in the left or right direction */
      FastTrackSwitchOff = OOI_t_SeReObFastTrackAbschaltung();
      if( FastTrackSwitchOff == RIGHT_CURVE_SWITCH_OFF)
      {
        /* Strong right turn */
        pt_OOI_Output->OOI_t_eRelObjVerlustGrund[ROVDataInput->OOINr] = OBJ_LOSS_STEER_RIGHT;
        OOI_f_dKruemmungWaehrendROVMin[ROVDataInput->OOINr] = ROVDataInput->TrackStandardCurve;
#if (OOI_ROV_RESET_BY_TIME == SWITCH_ON)
        OOI_f_rov_reset_time[ROVDataInput->OOINr] = OOI_ROV_RESET_TIME;
#endif
      }
      else if (FastTrackSwitchOff == LEFT_CURVE_SWITCH_OFF)
      {
        /* Strong Left Turn */
        pt_OOI_Output->OOI_t_eRelObjVerlustGrund[ROVDataInput->OOINr] = OBJ_LOSS_STEER_LEFT;
        OOI_f_dKruemmungWaehrendROVMin[ROVDataInput->OOINr]   = ROVDataInput->TrackStandardCurve;
#if (OOI_ROV_RESET_BY_TIME == SWITCH_ON)
        OOI_f_rov_reset_time[ROVDataInput->OOINr] = OOI_ROV_RESET_TIME;
#endif
      }
      else
      {
        OOI_v_ResetRelObjLossReason(ROVDataInput->OOINr);
      }
    }
    else
    {
       /* "different object selected" case not handled*/
    }
  }


  /* Object loss reason are set to OBJ_LOSS_RANGE_REDUCTION if
  1. Target is deselected in current cycle.
  2. It must not be stationary in previous cycle.
  3. Ego velocity must be greater than 10 kmph.
  4. Target goes beyond the Radar pickup range.
  */
  if (pt_OOI_Output->OOI_t_eRelObjVerlustGrund[ROVDataInput->OOINr] == OBJ_LOSS_NO_INFO)
  {
    if(ROVDataInput->RelTrckObjNr == OBJ_INDEX_NO_OBJECT)
    {
      if ((ROVDataInput->pRelObj->StatObj == FALSE))
      {
        if(ROVDataInput->TPVehicleSpeed > OOI_ROVG_VEIGENMIN)
        {
          if(f_OldRelObjDistX > ObjDependantMaxRange)
          {
            pt_OOI_Output->OOI_t_eRelObjVerlustGrund[ROVDataInput->OOINr] = OBJ_LOSS_RANGE_REDUCTION;
#if (OOI_ROV_RESET_BY_TIME == SWITCH_ON)
            OOI_f_rov_reset_time[ROVDataInput->OOINr] = OOI_ROV_RESET_TIME;
#endif
          }
        }
      }
    }
  }


  /* Object loss reason are set to OBJ_LOSS_CURVE_LEFT_AHEAD and OBJ_LOSS_CURVE_RIGHT_AHEAD if target cuts out to different lane
  1. Target is deselected in current cycle.
  2. It must not be stationary in previous cycle.
  3. Ego velocity must be greater than 10 kmph.
  4. Ego curve radius less then 1000m and angle to the target greater than 75% of senser lobe angle.
  */
  if (pt_OOI_Output->OOI_t_eRelObjVerlustGrund[ROVDataInput->OOINr] == OBJ_LOSS_NO_INFO)
  {
    if(ROVDataInput->RelTrckObjNr == OBJ_INDEX_NO_OBJECT)
    {
      if ((ROVDataInput->pRelObj->StatObj == FALSE) && (Obj_DynamicProperty != SLATE_OBJECT_PROPERTY_ONCOMING))
      {
        if(ROVDataInput->TPVehicleSpeed > OOI_ROVG_VEIGENMIN)
        {
          if((ROVDataInput->pRelObj->DistX > OOI_ROV_MIN_DIST_THRES))
          {
            if (((ROVDataInput->TrackStandardCurve) > (OOI_ROV_MAX_CURVATURE)) && (ROVDataInput->pRelObj->ObjAngle  > dGrenzwinkel))
            {
              pt_OOI_Output->OOI_t_eRelObjVerlustGrund[ROVDataInput->OOINr] = OBJ_LOSS_CURVE_LEFT_AHEAD;
#if (OOI_ROV_RESET_BY_TIME == SWITCH_ON)
              OOI_f_rov_reset_time[ROVDataInput->OOINr] = OOI_ROV_RESET_TIME;
#endif
            }
            else if(((ROVDataInput->TrackStandardCurve) < -(OOI_ROV_MAX_CURVATURE)) && (ROVDataInput->pRelObj->ObjAngle < -dGrenzwinkel))
            {
              pt_OOI_Output->OOI_t_eRelObjVerlustGrund[ROVDataInput->OOINr] = OBJ_LOSS_CURVE_RIGHT_AHEAD;
#if (OOI_ROV_RESET_BY_TIME == SWITCH_ON)
              OOI_f_rov_reset_time[ROVDataInput->OOINr] = OOI_ROV_RESET_TIME;
#endif
            }
            else
            {
              /* dummy else to satisy QAC */
            }
          }
        }
      }
    }
  }


  /* Object loss reason are set to OBJ_LOSS_EGO_LANE_CHG_LEFT and OBJ_LOSS_EGO_LANE_CHG_RIGHT if there is target loss due to EGO lane change
  1. Target is deselected in current cycle.
  2. It must not be stationary in previous cycle.
  3. Ego velocity must be greater than 10 kmph.
  4. EGO vehicle lane change was detected
  */
  if (pt_OOI_Output->OOI_t_eRelObjVerlustGrund[ROVDataInput->OOINr] == OBJ_LOSS_NO_INFO)
  {
    if(ROVDataInput->RelTrckObjNr == OBJ_INDEX_NO_OBJECT)
    {
      if ( ROVDataInput->pRelObj->StatObj == FALSE)
      {
        if(ROVDataInput->TPVehicleSpeed > OOI_ROVG_VEIGENMIN)
        {
          if(   ((t_LCPhase == LC_PRELANECHANGE) || (t_LCPhase == LC_LANECHANGE))
              && (s_LaneChangeProbability > OOI_ROV_MAX_LC_PROB)
              && (t_LCPhaseState == LC_LEFT)
              && (t_ObjAssociatedLane == ASSOC_LANE_RIGHT)
              )
          {
            pt_OOI_Output->OOI_t_eRelObjVerlustGrund[ROVDataInput->OOINr] = OBJ_LOSS_EGO_LANE_CHG_LEFT;
#if (OOI_ROV_RESET_BY_TIME == SWITCH_ON)
            OOI_f_rov_reset_time[ROVDataInput->OOINr] = OOI_ROV_RESET_TIME;
#endif
          }
          else if(   ((t_LCPhase == LC_PRELANECHANGE) || (t_LCPhase == LC_LANECHANGE))
                  && (s_LaneChangeProbability > OOI_ROV_MAX_LC_PROB)
                  && (t_LCPhaseState == LC_RIGHT)
                  && (t_ObjAssociatedLane == ASSOC_LANE_LEFT)
              )
          {
            pt_OOI_Output->OOI_t_eRelObjVerlustGrund[ROVDataInput->OOINr] = OBJ_LOSS_EGO_LANE_CHG_RIGHT;
#if (OOI_ROV_RESET_BY_TIME == SWITCH_ON)
            OOI_f_rov_reset_time[ROVDataInput->OOINr] = OOI_ROV_RESET_TIME;
#endif
          }
          else
          {
            /* dummy else to satisy QAC */
          }
        }
      }
    }
  }


  /* Object loss reason are set to OBJ_LOSS_LANE_CHG_LEFT and OBJ_LOSS_LANE_CHG_RIGHT if target cuts out to different lane
  1. Target was deselected.
  2. It must not be stationary in previous cycle.
  3. Ego velocity must be greater than 10 kmph.
  4. Object Lane association is no more EGO lane association.
  */
  if (pt_OOI_Output->OOI_t_eRelObjVerlustGrund[ROVDataInput->OOINr] == OBJ_LOSS_NO_INFO)
  {
    if(ROVDataInput->RelTrckObjNr == OBJ_INDEX_NO_OBJECT)
    {
      if ( ROVDataInput->pRelObj->StatObj == FALSE)
      {
        if(ROVDataInput->TPVehicleSpeed > OOI_ROVG_VEIGENMIN)
        {
          if((t_ObjAssociatedLane == ASSOC_LANE_LEFT) || (t_ObjAssociatedLane == ASSOC_LANE_FAR_LEFT))
          {
            pt_OOI_Output->OOI_t_eRelObjVerlustGrund[ROVDataInput->OOINr] = OBJ_LOSS_LANE_CHG_LEFT;
#if (OOI_ROV_RESET_BY_TIME == SWITCH_ON)
            OOI_f_rov_reset_time[ROVDataInput->OOINr] = OOI_ROV_RESET_TIME;
#endif
          }
          else if((t_ObjAssociatedLane == ASSOC_LANE_RIGHT) || (t_ObjAssociatedLane == ASSOC_LANE_FAR_RIGHT))
          {
            pt_OOI_Output->OOI_t_eRelObjVerlustGrund[ROVDataInput->OOINr] = OBJ_LOSS_LANE_CHG_RIGHT;
#if (OOI_ROV_RESET_BY_TIME == SWITCH_ON)
            OOI_f_rov_reset_time[ROVDataInput->OOINr] = OOI_ROV_RESET_TIME;
#endif
          }
          else
          {
            /* Do Nothing */
          }
        }
      }
    }
  }


  if (pt_OOI_Output->OOI_t_eRelObjVerlustGrund[ROVDataInput->OOINr] == OBJ_LOSS_NO_INFO)
  {
    /* Check for custom Object loss reason */
    OOI_b_CheckCustomObjLossReason( ROVDataInput );
  }

  /* Set Object loss reason for Critically disappeared cut-in object */
  OOI_b_CheckforCriticalObjLossReason( ROVDataInput );

}/* PRQA S 7004 */
/* date: 2018-10-10, reviewer: Ravi Kiran Gurrala, reason : Cyclomatic complexity. Not Safety critical*/

/*************************************************************************************************************************
  Functionname:    OOI_v_ObReObRelObjVerlRueckTimeDist                                                                  */ /*!

  @brief           Reset relevant object loss reason

  @description     Reset relevant object loss reason
                   Different hypotheses are explored in terms reason such as OBJ_LOSS_CURVE_LEFT_AHEAD, OBJ_LOSS_CURVE_RIGHT_AHEAD
                   OBJ_LOSS_CURVE_LEFT, OBJ_LOSS_CURVE_RIGHT in combination with time gap criterion.

		@startuml
			Start
			Partition OOI_v_ObReObRelObjVerlRueckTimeDist {
				- Set relevant object disappeared flag as FALSE
				If (Relevant object longitudinal distance less than 25m) then (true)
					- Update Sensor lobe angle
				Else (false)
					: Do nothing;
				Endif 
				If (OOI relevant object reset by time is Enabled) then (true)
					If (Relevant object reset time more than Zero) then (true)
						- Update Relevant object reset time 
					Else (false)
						- Update Relevant object reset time as Zero
						- Reset relevant object
					Endif 
				Else (false)
					: Do nothing;
				Endif 
				If (Relevant object is disappeared) then (true)
					- Update array of distances used in relevant object loss
					If (array of distances used in relevant object loss more than Zero) then (true)
						- Update array of distances used in relevant object loss
					Endif 
					If (array of distances used in relevant object loss less or equal to Zero) then (true)
					- Reset relevant object
					Endif 
				Else if (Relevant object loss reason is Left or Right) then (true)
					If (Relevant object vehicle speed more than Zero) then (true)
						- Calculate Time to Distance
					Else (false)
						: Reset Time to Distance to Max value;
					Endif 
					If (Time to Distance >= maximum relevant object reset time or Distance to FOV > OOI_ROV_MAX_DIST) then (true)
						- Reset relevant object
					Else (false) 
						If (Absolute value of Stored Curvature < Absolute value of Track Standard Curvature) then (true)
							- Update array of curvature during object loss
						Else (false)
							: Do nothing;
						Endif 
					Endif 
				Else if (Relevent Object loss is steering Left or Right) then (true)
					: Check for narrow ego curve in the left or right direction;
					If (No narrow ego curve or No Relevent Object) then (true)
						: Reset Object Loss Reason;
					Endif
				Else (false)
					: Do nothing;
				Endif
				If (if ROV-Gruenden Near Distance Condition is True) then (yes)
					If (No Track Object) then (yes)
						: Reset object loss reason related object data for the object which was Object of Interest in previous cycle;
					Endif
				Else (no)
					If (No Track Object) then (yes)
						: Reset Relevant Object Loss Reason;
					Endif 
					If (Relevant object loss reason is Left or Right) then (yes)
						If(Vehicle speed is less than or equal to Minimum speed)then (yes)
							: Reset Relevant Object Loss Reason;
						Endif
					Endif
				Endif
		}
		End 
		@enduml

  @return          -

  @param[in]       ROVDataInput : reference to data structure containing info about relevant object loss scenario                       
                      OOINr : Index of the object whose loss is being evaluated                                                         [0u ... OOI_NUMBER_OF_OOI][OOI_NUMBER_OF_OOI as defined in si_ext.h]
                      TPVehicleSpeed : EGO vehicle speed at time of relevant object loss scene evaluation                               [-330.f ... 330.f] m/s
                      TrackStandardCurve : EGO curvature                                                                                [-1 ... +1] m^-1
                      RelTrckObjNr : Index of the object which was being tracked and now lost                                           [0u ... EM_N_OBJECTSs]
                      pRelObj->DistX : Longitudinal distance of the current relevant object                                             [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                      pRelObj->ObjAngle : Angle from EGO perpective where current relevant object is found                              [-PI ... +PI] rad
                      pRelObj->ObjectNr : Object ID of the relevant object                                                              [0u ... EM_N_OBJECTSs]
                      pRelObj->LatDisplRoadBordR : Lateral road border right for current relevant object                                [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      pRelObj->LatDisplRoadBordL : Lateral road border left for current relevant object                                 [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      pRelObj->ObjDistY : Lateral position of the currentl relevant object                                              [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @param[out]      -

  @glob_in         OOI_f_rov_reset_time : Array of timers used in relevant object loss reset , array size                               [0u ... OOI_NUMBER_OF_OOI] [0.f ... OOI_ROV_RESET_TIME] s
  @glob_in         SLATE_f_GetSITCycleTime() : Task cycle time                                                                                     [0.f ... 1.f] s
  @glob_in         pt_OOI_Output->OOI_t_eRelObjVerlustGrund : Array of structure for processing object loss reason, array size          [0u ... OOI_NUMBER_OF_OOI] [Full range of datatype eRelObjLossReason_t as defined in Rte_Type.h]
  @glob_in         OOI_t_dROVGHalteVObjekt : Array of translatory velocity values, array size                                           [0u ... OOI_NUMBER_OF_OOI] [-330.f ... 330.f] m/s
  @glob_in         OOI_f_dKruemmungWaehrendROVMin : Array of curvatures during relevant object loss, array size                         [0u ... OOI_NUMBER_OF_OOI] [-1 ... +1] m^-1
  @glob_in         OOI_b_ROVGHalteNearDistCondtition : Boolean indicating if relevant object loss is due to the near distance criteria  [TRUE, FALSE]
  @glob_in         *SLATE_pt_GetObjDynProperty(i) : Dynamic property of object i                                                               [Full range of datatype SLATE_t_Obj_DynamicProperty as defined in rte_type.h]
                                             with i in [0 ... EM_N_OBJECTS-1] and EM_N_OBJECTS as defined in Rte_SWCEmAdapt_Type.h 
  @glob_out        OOI_b_RelObjDisappearedFlag : Array of boolean flags indicating relevant object has disappeared, array size          [0u ... OOI_NUMBER_OF_OOI] [TRUE, FALSE]
  @glob_out        OOI_f_rov_reset_time : Array of timers used in relevant object loss reset , array size                               [0u ... OOI_NUMBER_OF_OOI] [0.f ... OOI_ROV_RESET_TIME] s
  @glob_out        OOI_f_dROVGHalteDistanz : Array of distances used in relevant object loss, array size                                [0u ... OOI_NUMBER_OF_OOI] [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
  @glob_out        OOI_t_dROVGHalteVObjekt : Array of translatory velocity values, array size                                           [0u ... OOI_NUMBER_OF_OOI] [-330.f ... 330.f] m/s
  @glob_out        OOI_f_dKruemmungWaehrendROVMin : Array of curvatures during relevant object loss, array size                         [0u ... OOI_NUMBER_OF_OOI] [-1 ... +1] m^-1
  @glob_in         pt_OOI_Output->OOI_t_eRelObjVerlustGrund : Array of structure for processing object loss reason, array size          [0u ... OOI_NUMBER_OF_OOI] [Full range of datatype eRelObjLossReason_t as defined in Rte_Type.h]
  
  
  @c_switch_part   OOI_ROV_RESET_BY_TIME   : switch for enabling ROV reset condition by time
  @c_switch_part   OOI_CFG_OBJLOSS_LOWDIST : Configuration switch enabling ObjectLossReason at low distance
  @c_switch_full   FCT_CFG_ACC_OOI         : Configuration switch to configure OOI sub-component for FCT_ACC

  @pre             -
  @post            No changes

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @traceability    370:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-370-00061542 \n
                   371:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-371-00061542 \n

  @created         15.03.2007
  @changed         24.03.2016

  @author          Harsha Umesh Babu | harsha.umesh.babu@continental-corporation.com | +49 (8382) 9699-474
*************************************************************************************************************************/
static void OOI_v_ObReObRelObjVerlRueckTimeDist (const OOI_ROVDataInput_t *ROVDataInput)
{
/*--- VARIABLES ---*/
  float32  TimeDist;
  float32 dGrenzwinkel = OOI_ROVG_GRENZWINKEL;
  float32 DistanceToFOV = 0.0f;
  //SLATE_t_Obj_DynamicProperty t_ObjDynProperty;
  OOI_FastTrackSwitchOff_t FastTrackSwitchOff;

  /* Anderer Grenzwinkel fuer nahe Verfolgte: */
  /*!< Remark: pRelObj points to the global variable OOI_RelObject, which is properly initialized -> variables of the structure can be always accessed */
  if (ROVDataInput->pRelObj->DistX < OOI_ROVG_GRENZE_BX)
  {
    dGrenzwinkel = OOI_ROVG_GRENZWINKEL_BX_NEU;
  }

#if (OOI_ROV_RESET_BY_TIME == SWITCH_ON) 
  if(OOI_f_rov_reset_time[ROVDataInput->OOINr] > 0.0f)
  {
    OOI_f_rov_reset_time[ROVDataInput->OOINr] -= SLATE_f_GetSITCycleTime();
  }
  else
  {
    OOI_f_rov_reset_time[ROVDataInput->OOINr] = 0.0f;
    OOI_v_ResetRelObjLossReason(ROVDataInput->OOINr);
  }
#endif

  if(pt_OOI_Output->OOI_t_eRelObjVerlustGrund[ROVDataInput->OOINr] == OBJ_LOSS_DISAPPEARED) 
  {
    OOI_f_dROVGHalteDistanz[ROVDataInput->OOINr] -= ROVDataInput->TPVehicleSpeed * SLATE_f_GetSITCycleTime();
    OOI_f_dROVGHalteDistanz[ROVDataInput->OOINr] += OOI_t_dROVGHalteVObjekt[ROVDataInput->OOINr] * SLATE_f_GetSITCycleTime();

    if (OOI_t_dROVGHalteVObjekt[ROVDataInput->OOINr] > (float32) 0.)
    {
      OOI_t_dROVGHalteVObjekt[ROVDataInput->OOINr] -= OOI_ROVG_BREMSUNG * SLATE_f_GetSITCycleTime();
    }
    if( OOI_f_dROVGHalteDistanz[ROVDataInput->OOINr] <= 0.f )
    {
      OOI_v_ResetRelObjLossReason(ROVDataInput->OOINr);
    }
  }
  else if(( pt_OOI_Output->OOI_t_eRelObjVerlustGrund[ROVDataInput->OOINr] == OBJ_LOSS_CURVE_LEFT ) ||
          ( pt_OOI_Output->OOI_t_eRelObjVerlustGrund[ROVDataInput->OOINr] == OBJ_LOSS_CURVE_RIGHT ))
  {
    const float32 fSinBorderAngle = CML_cos66(DEG2RAD(dGrenzwinkel));
    const float32 fCosBorderAngle = CML_cos66(DEG2RAD(90.f - dGrenzwinkel));
    const float32 fTrackCurvDivisor = MAX_FLOAT(fABS(ROVDataInput->TrackStandardCurve), C_F32_DELTA);

    DistanceToFOV = (2.f * fSinBorderAngle * fCosBorderAngle) / fTrackCurvDivisor;

    if(ROVDataInput->TPVehicleSpeed > C_F32_DELTA)
    {
      TimeDist = DistanceToFOV / ROVDataInput->TPVehicleSpeed;
    }
    else
    {
      TimeDist = OOI_ROV_RESET_MAX_TIME_DIST;
    }

    /* OBJ_LOSS_CURVE_RIGHT or OBJ_LOSS_CURVE_LEFT */
    /* flag reset :                              */
    /* - Visibility to detection edge > 4s or > 100m
          && Curve radius has doubled again compared to target loss*/
    /* - sign change of the curve radius                  */
    if (   (TimeDist >= OOI_ROV_RESET_MAX_TIME_DIST)
        || (DistanceToFOV > OOI_ROV_MAX_DIST))
    {
      OOI_v_ResetRelObjLossReason(ROVDataInput->OOINr);
    }
    else
    {
      const float32 fCurStoredCurvAbs = fABS(OOI_f_dKruemmungWaehrendROVMin[ROVDataInput->OOINr]);
      const float32 fNewCurvAbs = fABS(ROVDataInput->TrackStandardCurve);
      if (fCurStoredCurvAbs < fNewCurvAbs)
      {
        OOI_f_dKruemmungWaehrendROVMin[ROVDataInput->OOINr] = ROVDataInput->TrackStandardCurve;
      }
    }
  }
  else if(   ( pt_OOI_Output->OOI_t_eRelObjVerlustGrund[ROVDataInput->OOINr] == OBJ_LOSS_STEER_LEFT )
          || ( pt_OOI_Output->OOI_t_eRelObjVerlustGrund[ROVDataInput->OOINr] == OBJ_LOSS_STEER_RIGHT))
  {
    /* Check for narrow ego curve in the left or right direction */
    FastTrackSwitchOff = OOI_t_SeReObFastTrackAbschaltung();

    if ((FastTrackSwitchOff == NO_SWITCH_OFF) || (ROVDataInput->RelTrckObjNr != OBJ_INDEX_NO_OBJECT))
    {
      OOI_v_ResetRelObjLossReason(ROVDataInput->OOINr);
    }
  }
  else
  {
    /* Keiner der folgenden ROV-Gruenden ist aktiv */
    /* OBJ_LOSS_DISAPPEARED                       */
    /* OBJ_LOSS_CURVE_LEFT                        */
    /* OBJ_LOSS_CURVE_RIGHT                       */
    /* OBJ_LOSS_CURVE_LEFT_AHEAD                  */
    /* OBJ_LOSS_CURVE_RIGHT_AHEAD                 */
  }

#if (OOI_CFG_OBJLOSS_LOWDIST)
  if (OOI_b_ROVGHalteNearDistCondtition==TRUE)
  {
    if (ROVDataInput->RelTrckObjNr != OBJ_INDEX_NO_OBJECT)
    {
      OOI_v_ResetRelObjLossReason(ROVDataInput->OOINr);
    }
  }
  else
  {
#endif

    if (ROVDataInput->RelTrckObjNr != OBJ_INDEX_NO_OBJECT)
    {
      /*t_ObjDynProperty = *SLATE_pt_GetObjDynProperty(ROVDataInput->RelTrckObjNr);
      if (t_ObjDynProperty == SLATE_OBJECT_PROPERTY_MOVING)
      {*/
        /* Relevant Objekt Verlustgrund loeschen */
        OOI_v_ResetRelObjLossReason(ROVDataInput->OOINr);
      //}
    }
  
    if (  (pt_OOI_Output->OOI_t_eRelObjVerlustGrund[ROVDataInput->OOINr] == OBJ_LOSS_CURVE_LEFT )
       || (pt_OOI_Output->OOI_t_eRelObjVerlustGrund[ROVDataInput->OOINr] == OBJ_LOSS_CURVE_RIGHT))
    {
      if( ROVDataInput->TPVehicleSpeed<= OOI_ROVG_VEIGENMIN )
      {
        OOI_v_ResetRelObjLossReason(ROVDataInput->OOINr);
      }
    }
#if (OOI_CFG_OBJLOSS_LOWDIST)
  }
#endif
}
/** @} end defgroup ooi*/
#endif /* (FCT_CFG_ACC_OOI) */
