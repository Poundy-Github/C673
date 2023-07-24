/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)
  
CPU:                       CPU-Independent
  
COMPONENT:                 SLATE_SIT (Situation)

PACKAGENAME:               sit_objfeatures.c

DESCRIPTION:               Calculation of object features like cut-in potential, etc.

AUTHOR:                    Fridolin Kolb, Gergely Ungvary

CREATION DATE:             02.11.2009

VERSION:                   $Revision: 1.27 $

LEGACY VERSION:            Revision: 2.5

**************************************************************************** */


/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "sit.h"//PRQA S 0380
/* date: 2019-07-28, reviewer:Prabhu Sundaramurthy, reason: Arises due to inclusion of multiple header files in this header file which has multiple macros*/

#include "sit_custom.h"
#if (FCT_CFG_ACC_SITUATION)

#ifdef FCT_SIMU
#ifndef __PDO__
#include <string.h>
#endif /* #ifndef __PDO__ */
#endif  /* FCT_SIMU */
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/

/**
@defgroup sit_objfeatures Sit Object features
@ingroup sit
@brief          This module calculates object properties.\n\n
@{
*/
/*****************************************************************************
  MODULGLOBALE KONSTANTEN
*****************************************************************************/


/*****************************************************************************
  MODULGLOBALE VARIABLEN
*****************************************************************************/
static void SIT_v_CalcCutInOutPotentialAllObjects(void);

/*****************************************************************************
  MODULLOKALE SYMBOLISCHE KONSTANTEN
*****************************************************************************/

#if(SIT_USE_OBJ_OCCLUSION_LANEASSOCIATION == SWITCH_ON)
#define SIT_MAX_DIST_OOI_TO_TRACE_OBJ        (75.f)
#define SIT_MIN_DIST_OOI_TO_TRACE            (-1.f)
#define SIT_MIN_DIST_OOI_TO_TRACE_ACC_TRAJ   (-2.f)
#define SIT_MAX_DIST_OOI_TO_TRACE            (4.f)
#define SIT_MIN_DIST_OOI_TO_ACC_TRAJ         (-1.f)
#endif

#if ((SLATE_CFG_TCI_BASE) && (SLATE_CFG_TCI_FRONT_OBST_DETCD))

/* Maximum Longitudinal Displacement to Object from Ego in meter */
#define SIT_MAX_LONG_DISP_TO_OBJ_FROM_EGO    (7.f)
/* Minimum Longitudinal Displacement to Object from Ego in meter */
#define SIT_MIN_LONG_DISP_TO_OBJ_FROM_EGO    (0.f)
/* Maximum Lateral Displacement to Object from Ego in meter to left */
#define SIT_MAX_LAT_DISP_OF_OBJ              (1.f)
/* Minimum Lateral Displacement to Object from Ego in meter to right*/
#define SIT_MIN_LAT_DISP_OF_OBJ              (-1.f)
/* Maximum speed of the Ego Vehicle in meters per second within which the front obstacle signal needs to be filled */
#define SIT_MAX_EGO_SPEED                    (2.777778f)
/* Maximum speed of the Ego Vehicle in meters per second which we consider while calculating the lateral disp of object */
#define SIT_MIN_EGO_SPEED                    (1.67f)
/* Threshold for Minimizing Object Lateral Velocity in Y direction */
#define SIT_THRESH_FOR_OBJ_LAT_VEL           (0.6f)
#endif /* END IF (SLATE_CFG_TCI_BASE) && (SLATE_CFG_TCI_FRONT_OBST_DETCD) */

/*****************************************************************************
  MODULLOKALE MAKROS
*****************************************************************************/


/*****************************************************************************
  MODULLOKALE TYPEN
*****************************************************************************/

#if(SIT_USE_OBJ_OCCLUSION_LANEASSOCIATION == SWITCH_ON)
typedef enum SIT_OcclusionByTraceSide_t
{
  SIT_OCCL_BY_TRACE_LEFT,
  SIT_OCCL_BY_TRACE_RIGHT
}t_SIT_OcclusionByTraceSide;
#endif

/*****************************************************************************
  MODULLOKALE KONSTANTEN
*****************************************************************************/


/*****************************************************************************
  MODULLOKALE TYPEDEFS
*****************************************************************************/


/*****************************************************************************
  MODULLOKALE VARIABLEN
*****************************************************************************/


/*****************************************************************************
  FUNCTION PROTOTYPES
*****************************************************************************/

#if(SIT_USE_OBJ_OCCLUSION_LANEASSOCIATION == SWITCH_ON)
#if (FCT_CFG_OBJECT_TRACE_PREPROCESSSING)
static void SIT_v_DetectOccludedByTrace(void);
static void SIT_v_DetectOccludedByTraceSigleSide(const ObjNumber_t t_NextLongOOI, t_SIT_OcclusionByTraceSide t_OcclSide);
#endif /* END IF (FCT_CFG_OBJECT_TRACE_PREPROCESSSING) */
#endif

#if (FCT_CFG_OBJECT_TRACE_PREPROCESSSING)
static float32 SIT_f_SetCrossingDistTrace(const ObjNumber_t ObjID);
#endif /* END IF FCT_CFG_OBJECT_TRACE_PREPROCESSSING */
/*PRQA S 2013,2016 EMPTY_ELSE_OR_DEFAULT*/
/* date: 2019-07-28, reviewer:Prabhu Sundaramurthy, reason: Empty else or default, no effect on functionality*/
/*************************************************************************************************************************
  Functionname:    SIT_v_CalcBaseFeatures                                                                               */ /*!

  @brief           Determines Cut-In/Out potential for all objects.

  @description     Determines Cut-In/Out potential for all objects.

		@startuml
		Start
		Partition SIT_v_CalcBaseFeatures {
			#Orange : <b> SIT_v_CalcCutInOutPotentialAllObjects</b>: Calculates Cut-In/Out potential for all objects;
		}
		End
		@enduml

  @return          None

  @param[in]       None

  @glob_in         None
  @glob_out        None

  @c_switch_part   None
  @c_switch_full   None

  @pre             None
  @post            None

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         23.05.2018
  @created         23.05.2018

  @author          Grant Davtjan | Grant.Davtjan@continental-corporation.com | +49-8382-9699-633
*************************************************************************************************************************/
void SIT_v_CalcBaseFeatures(void)
{
  /*!Calculates Cut-In/Out potential for all objects*/
  SIT_v_CalcCutInOutPotentialAllObjects();
}

#if ((SLATE_CFG_TCI_BASE) && (SLATE_CFG_TCI_FRONT_OBST_DETCD))


/*************************************************************************************************************************
  Functionname:         SIT_b_FrontObstacleFilling                                                                   */ /*!

  @brief                Filing out the b_FrontObstacleDetected signal.

  @description          Determines if there are any crossing pedestrians/bicycle between subject(Ego) vehicle and OOI-0.

		@startuml
		Start
		Partition SIT_b_FrontObstacleFilling {
		: Set Object ID of OOI-0;
		If (Check if Object ID of OOI-0 is not existed) then (yes)
			:  Get Longitudinal Displacement to OOI-0 from Ego Vehicle;
			Repeat
				: Get Longitudinal Displacement of the Object;
				: Get Lateral Displacement of the Object;
				: Get Velocity of the Ego vehicle;
				: Get Lateral velocity of the Object in Y direction;
				: Get Sensor source of the object by which it is confirmed;
				: Get Dynamic property of the Object;
				: Get Sub-Dynamic property of the Object;
				: Get Classification of the Object;
				If (Velocity of the Ego vehicle > SIT_MIN_EGO_SPEED) then (yes)
					: Calculate Time to Collision value using Object Longitudinal Displacement and Ego Velocity;
					: Calculate Predicted Lateral displacement of the object which it can cover;
				Else (no)
					: Calculate Time to Collision value;
					: Calculate Predicted Lateral displacement of the object which it can cover;
				Endif
				If (If Object is selected as OOI-0) then (yes)
					: Set Signal High if an Obstacle is detected;
					: Set SIT Front Obstacle Detection Object;
				Else (no)
					: Set Signal Low if Obstacle is not detected;
				Endif 
			Repeat While (For All Objects)
		Endif
		}
		End
		@enduml

  @return               boolean

  @param[in]            void 

  @glob_in              pt_SITInput->t_OOI.pu_OOIListObjId : Macro for accessing ACC Assessed Object List object of interest array [based on GET_FCT_PUB_OBJ_DATA_PTR]
  @glob_in              *SLATE_pf_GetObjLongDisp(iObjID) : Longitudinal distance of object iObjID [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                                   with iObjID in [0 ... EM_N_OBJECTS[ and EM_N_OBJECTS as in Rte_RadarBase_Type.h
  @glob_in              *SLATE_pt_GetObjClassification : object class              [EM_t_GenObjClassification as in Rte_Type.h]
  @glob_in              *SLATE_pf_GetObjLatDisp(iObjID) : Lateral distance of object iObjID [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                                   with iObjID in [0 ... EM_N_OBJECTS[ and EM_N_OBJECTS as in Rte_Type.h
  @glob_in              *SLATE_pt_GetObjDynProperty(iObjID) : Dynamic property of an object iObjID [EM_t_GenObjDynamicProperty as in Rte_Type.h]
  @glob_in              *SLATE_pt_GetObjDynSubProperty(iObjID) :  Dynamic sub property of an object iObjID [SLATE_t_Obj_DynamicProperty as in Rte_Type.h] 
                                   for enum { ARS_OBJECT_SUBPROP_NORMAL=0,SLATE_OBJECT_SUBPROP_CROSSING=1} [0,1]
  @glob_in              *SLATE_pf_GetObjVabsY(iObjID) : Velocity (absolute) in Y direction of object iObjID [-330f   330f] m/s
                                   with iObjID in [0 ... EM_N_OBJECTS[ and EM_N_OBJECTS as in Rte_RadarBase_Type.h
  @glob_in              EGO_SPEED_X_OBJ_SYNC : Ego velocity provided by VDY [-330.f ... 330.f] m/s
  @glob_out             None 

  @c_switch_part        SLATE_CFG_TCI_BASE             : Config switch which enables the SLATE support for TCI Functionality
  @c_switch_part        SLATE_CFG_TCI_FRONT_OBST_DETCD : Config switch which enables the SLATE support for TCI Functionality - Front Obstacle Detected Functionality
  @c_switch_full        FCT_CFG_ACC_SITUATION          :  FCT support for ACC SIT (situation) sub-component

  @pre                  None 
  @post                 b_FrontObstacleDetetced signal is filled.

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  

  @todo                 -

  @author               Pavan Kotra | pavan.kotra@continental-corporation.com | +91 (80) 6679-6000
*************************************************************************************************************************/
boolean SIT_b_FrontObstacleFilling(void)
{

/* Longitudinal Displacement of the Object                       */
float32 f_ObjectLongDisp;                                 
/* Lateral Displacement of the Object                            */                                              
float32 f_ObjectLatDisp;        
/* Longitudinal Displacement to OOI-0 from Ego Vehicle                              */
float32 f_relobjLongDisp;                  
/* Velocity of the Ego vehicle                                           */
float32 f_EgoVel;        
/* Predicted Lateral displacement of the object which it can cover       */
float32 f_ObjDistCovrd;    
/* Time to Collision value                                               */
float32 f_ttc;           
/* Lateral velocity of the Object in Y direction                 */
float32 f_ObjectLatvely;         
/* Object ID of the vehicle                                      */
ObjNumber_t iObjID;           
/* Object ID of OOI-0                                                    */
ObjNumber_t relobj;      
/* Sensor source of the object by which it is confirmed                  */
uint8 u_sensrc;               
/* Boolean signal which says whether there is any Obstacle in the Front  */
boolean b_FrontObstacleDetetced = FALSE;      
/* Dynamic property of the Object                                */
SLATE_t_Obj_DynamicProperty b_ObjDynamicProperty;    
/* Sub-Dynamic property of the Object                            */
SLATE_t_Obj_DynamicSubProperty b_ObjDynSubProperty;      
/* Classification of the Object                                  */
SLATE_t_Obj_CLassification t_ObjClassification;      

relobj = *pt_SITInput->t_OOI.pu_OOIListObjId(OBJ_NEXT_OOI);
    if(relobj != OBJ_INDEX_NO_OBJECT)
    {
      /* Checking whether the OOI-0 is present */
    f_relobjLongDisp = *SLATE_pf_GetObjLongDisp(relobj);
      
    for(iObjID= (ObjNumber_t)(EM_N_OBJECTS - 1); iObjID >= 0; iObjID--)
    {
      /* Looping for all the 40 objects      */
      f_ObjectLongDisp = *SLATE_pf_GetObjLongDisp(iObjID);
      f_ObjectLatDisp = *SLATE_pf_GetObjLatDisp(iObjID);
      f_EgoVel = SLATE_f_GetEgoVelObjSync();
      f_ObjectLatvely = *SLATE_pf_GetObjVabsY(iObjID);
      u_sensrc = SLATE_p_GetEMGenObjGeneral(iObjID)->eSensorSource;
      b_ObjDynamicProperty = *SLATE_pt_GetObjDynProperty(iObjID);
      b_ObjDynSubProperty = (*SLATE_pt_GetObjDynSubProperty(iObjID) == SLATE_OBJECT_SUBPROP_CROSSING);
      t_ObjClassification = *SLATE_pt_GetObjClassification(iObjID);

    if(f_EgoVel > SIT_MIN_EGO_SPEED)
    {
      /* Perform this when ego velocity is greater than 6 kmph */
      f_ttc = ((f_ObjectLongDisp)/(f_EgoVel)); // PRQA S 0584
      /* date : 2018-08-13, reviewer : Pavan Kumar Kotra, reason : Only when Ego speed is > 1.67 m/s, this operation is performed, so no possibility for division by zero */
      f_ObjDistCovrd = ((f_ttc)*(f_ObjectLatvely)*(SIT_THRESH_FOR_OBJ_LAT_VEL));
    }
    else
    {
      f_ttc = ((f_ObjectLongDisp)/(SIT_MIN_EGO_SPEED));
      f_ObjDistCovrd = ((f_ttc)*(f_ObjectLatvely)*(SIT_THRESH_FOR_OBJ_LAT_VEL));
    }
    
    /* Boolean signal is not set for the Pedestrian if it is OOI-0 because setting it will overwrite the TCI property */

    if(((t_ObjClassification == SLATE_OBJCLASS_POINT) || (t_ObjClassification == SLATE_OBJCLASS_PEDESTRIAN) ||
        (t_ObjClassification == SLATE_OBJCLASS_BICYCLE) || (t_ObjClassification == SLATE_OBJCLASS_UNCLASSIFIED)) && 
        ((SLATE_u_GetAccQuality(iObjID) != FUN_PRESEL_ACC_DROP_QUAL) || (u_sensrc == EM_GEN_OBJECT_MS_CAM)) &&
        ((b_ObjDynamicProperty == SLATE_OBJECT_PROPERTY_STATIONARY) || (b_ObjDynamicProperty == SLATE_OBJECT_PROPERTY_MOVING) || (b_ObjDynSubProperty != FALSE) ||
        ((b_ObjDynamicProperty == SLATE_OBJECT_PROPERTY_ONCOMING) && (f_ObjectLatDisp >= SIT_MIN_LAT_DISP_OF_OBJ) && (f_ObjectLatDisp <= SIT_MAX_LAT_DISP_OF_OBJ ))) &&
        (( f_ObjectLongDisp>(SIT_MIN_LONG_DISP_TO_OBJ_FROM_EGO)) && (f_ObjectLongDisp<(SIT_MAX_LONG_DISP_TO_OBJ_FROM_EGO)) && (f_ObjectLongDisp<f_relobjLongDisp)) &&
        (f_EgoVel<SIT_MAX_EGO_SPEED) && (relobj != iObjID) &&
        (( f_ObjectLatDisp>((SIT_MIN_LAT_DISP_OF_OBJ)-(fABS(f_ObjDistCovrd)))) && (f_ObjectLatDisp<((SIT_MAX_LAT_DISP_OF_OBJ)+(fABS(f_ObjDistCovrd))))))
    {
      /* Setting the Boolean Sigal High if an Obstacle is detected */
	    b_FrontObstacleDetetced = TRUE;
      pt_SITOutput->t_SIT_FrontObstacleDetection.ObjID = iObjID; //Can be Removed in Future, used for Visualization purpose in MTS
      break;
    }
    else
    {
	    b_FrontObstacleDetetced = FALSE;
    }	
    }
    } 
return b_FrontObstacleDetetced ;
}

#endif /* END IF  (SLATE_CFG_TCI_BASE) && (SLATE_CFG_TCI_FRONT_OBST_DETCD) */
/*************************************************************************************************************************
  Functionname:    SIT_v_CalcCutInOutPotentialAllObjects                                                                             */ /*!

  @brief           Determines Cut-in / Cut-out potentials

  @description     Determines Cut-in / Cut-out potentials based on OOI or lane association.

		@startuml 
		Start
		Partition SIT_v_CalcCutInOutPotentialAllObjects {
			#Orange :<b>SIT_v_CutInObjectDataInit</b>:Initialization of SITCutInObjData;
			Repeat
				If (Object is existed and moving and Longitudinal Displacement of Object is less than Maximum range of Object Dependant and No OOI-0) then (yes)
					: Look for objects of interest;
					Repeat
						If (OOI-0 Object) then (yes)
							: Object is OOI-0;
						Else (no)
							: Increse the Object Number;
						Endif
					Repeat While (Objects exist)
				If (Object is OOI-0) then (yes)
					If (Object is Next to OOI) then (yes)
						: Calculate CutIn/Out potential based on kinematics;
						: Calculate CutIn/Out potential based on Distance to Inlap/ Distance to InlapDrop;
							: Calculate CutOut potential for Object;
						: Set CutIn potential for Object as 0u;
					Elseif(Object is Next Logitudinual Left or Right to OOI) then (yes)
						: Calculate CutIn/Out potential based on kinematics;
						: Calculate CutIn/Out potential based on Distance to Inlap/ Distance to InlapDrop;
							: Calculate CutOut potential for Object;
						: Set CutIn potential for Object as 0u;
					Elseif (Object is Next to Hidden or Lateral Left Or Lateral Right) than (yes)
						: Set CutIn potential for Object as 0u;
						: Set CutOut potential for Object as 0u;
					Else (no)
						: Do Nothing;
					Endif
				Else (no)
					: Set CutIn potential for Object as 0u;
					: Set CutOut potential for Object as 0u;
				Endif
			Else (no)
				: Set CutIn potential for Object as 0u;
				: Set CutOut potential for Object as 0u;
			Endif
			Repeat While (For Entire Object List)
		End
		}
		@enduml

  @return          None

  @param[in]       None

  @glob_in         pt_SITInput->t_OOI.pu_OOIListObjId : Macro for accessing ACC Assessed Object List object of interest array [based on GET_FCT_PUB_OBJ_DATA_PTR]
  @glob_in         pt_SITInput->t_RTE.pt_ObjDynProperty(i) : Dynamic property of the object i                   [SLATE_t_Obj_DynamicProperty defined in Rte_Type.h]
                                        [TRUE, FALSE]
  @glob_in         pt_SITInput->t_OOI.pt_OOIRelObj->DistX : To get the longitudinal displacement of the object
  @glob_in         pt_SITInput->t_RTE.b_ObjIsDeleted(iObj): To check the object existence.
  @glob_in         (pt_SITInput->t_LAInput.pf_ObjDependantMaxRange(iObj)): To get the object range

  @glob_out        pt_SITOutput->t_ObjList[i].u_ObjCutInPotential : Cut in potential of object i                       [0u ... 100u]
  @glob_out        pt_SITOutput->t_ObjList[i].u_ObjCutOutPotential : Cut out potential of object i                     [0u ... 100u]

  @c_switch_part   None
  @c_switch_full   None

  @pre             pt_SITInput->t_OOI.pu_OOIListObjId(x) has to be able to return object indices (i.e.: object of interest list filled)
  @post            None

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @traceability    404:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-404-00061542 \n
                   389:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-389-00061542 \n

  @created         23.05.2018
  @created         23.05.2018

  @author          Grant Davtjan | Grant.Davtjan@continental-corporation.com | +49-8382-9699-633
*************************************************************************************************************************/

static void SIT_v_CalcCutInOutPotentialAllObjects(void)
{
  ObjNumber_t                 iObj;
  SLATE_t_Obj_DynamicProperty t_ObjDynProperty;
  boolean                     b_ObjIsDeleted;
  uint8                       u_OOInr;
  boolean                     b_ObjIsOOI;
  float32                     f_ObjDependantMaxRange;
  float32                     f_ObjLongDisp;
  float32                     f_DistXRelvantObject = 0.f;
  boolean                     b_RelevantObjectAvailable = FALSE;
  ObjNumber_t                 t_OOIListObjId = *pt_SITInput->t_OOI.pu_OOIListObjId((uint8)OBJ_NEXT_OOI);
  ObjNumber_t                 tOOIListObjId;
  if (t_OOIListObjId != OBJ_INDEX_NO_OBJECT)
  { 
    b_RelevantObjectAvailable = TRUE;
    f_DistXRelvantObject = pt_SITInput->t_OOI.pt_OOIRelObj->DistX;
  }

  SIT_v_CutInObjectDataInit();

  for (iObj=0; iObj<EM_N_OBJECTS; iObj++)
  {
    b_ObjIsDeleted         = pt_SITInput->t_RTE.b_ObjIsDeleted(iObj);
    t_ObjDynProperty       = *(pt_SITInput->t_RTE.pt_ObjDynProperty(iObj));
    f_ObjLongDisp          = *(pt_SITInput->t_RTE.pf_ObjLongDisp (iObj));
    f_ObjDependantMaxRange = *(pt_SITInput->t_LAInput.pf_ObjDependantMaxRange(iObj));

    if ( (b_ObjIsDeleted == FALSE)
      && (t_ObjDynProperty == SLATE_OBJECT_PROPERTY_MOVING)
      && (f_ObjLongDisp < f_ObjDependantMaxRange)
      && ( (b_RelevantObjectAvailable == FALSE) /*If there is no OOI0, Calculate potential based on ACC range only*/
        || (f_ObjLongDisp <= f_DistXRelvantObject) /* If there is OOI0, limit potential calculation to the distance of OOI0 */
         )
       )
    {
      /*! Look for objects of interest */
      b_ObjIsOOI = FALSE;
      u_OOInr = 0u;
      while ( (u_OOInr < OOI_NUMBER_OF_OOI) && (b_ObjIsOOI == FALSE) )
      {
        tOOIListObjId = *pt_SITInput->t_OOI.pu_OOIListObjId(u_OOInr);
        if (iObj == tOOIListObjId)
        {
          b_ObjIsOOI = TRUE;
        }
        else
        {
          u_OOInr++;
        }
      }

      if (b_ObjIsOOI == TRUE)
      {
        switch(u_OOInr)
        {
        case (uint8)OBJ_NEXT_OOI:
          SITCutInObjData[iObj].u_KinematicCutInOutPot = SIT_u_CutOutPotCalcKinematic(iObj);
          SITCutInObjData[iObj].u_PotentialDistanceCutInOut = SIT_u_CutOutPotCalcDist(iObj);
          pt_SITOutput->t_ObjList[iObj].u_ObjCutOutPotential = SIT_u_CutOutPotFusion(iObj, SITCutInObjData[iObj].u_KinematicCutInOutPot, SITCutInObjData[iObj].u_PotentialDistanceCutInOut);
          pt_SITOutput->t_ObjList[iObj].u_ObjCutInPotential  = 0u;

          break;

        case (uint8)OBJ_NEXT_LONG_LEFT_OOI:
        case (uint8)OBJ_NEXT_LONG_RIGHT_OOI:
          SITCutInObjData[iObj].u_KinematicCutInOutPot = SIT_u_CutInPotCalcKinematic(iObj);
          SITCutInObjData[iObj].u_PotentialDistanceCutInOut = SIT_u_CutInPotCalcDist(iObj);
          pt_SITOutput->t_ObjList[iObj].u_ObjCutInPotential  = SIT_u_CutInPotFusion(iObj, SITCutInObjData[iObj].u_KinematicCutInOutPot, SITCutInObjData[iObj].u_PotentialDistanceCutInOut);
          pt_SITOutput->t_ObjList[iObj].u_ObjCutOutPotential = 0u;

          break;

        case (uint8)OBJ_HIDDEN_NEXT_OOI:
        case (uint8)OBJ_NEXT_LAT_LEFT_OOI:
        case (uint8)OBJ_NEXT_LAT_RIGHT_OOI:
          pt_SITOutput->t_ObjList[iObj].u_ObjCutOutPotential = 0u;
          pt_SITOutput->t_ObjList[iObj].u_ObjCutInPotential  = 0u;

          break;

        default:
          break;
        }
      }
      else
      {
        /* For non-OOI objects set potential to zero */
        pt_SITOutput->t_ObjList[iObj].u_ObjCutInPotential  = 0u;
        pt_SITOutput->t_ObjList[iObj].u_ObjCutOutPotential = 0u;
      }
    }
    else
    {
      /* For objects above ACC range set potential to zero */
      pt_SITOutput->t_ObjList[iObj].u_ObjCutInPotential  = 0u;
      pt_SITOutput->t_ObjList[iObj].u_ObjCutOutPotential = 0u;
    }
  }

#if (SIT_CUTINPOTENTIAL_MULTIOBJECTANALYSE == 1)
#ifdef FCT_SIMU
  SIT_v_CutInDebugDataFreeze();
#endif
#endif /*(SIT_CUTINPOTENTIAL_MULTIOBJECTANALYSE == 1)*/
}

/*************************************************************************************************************************
  Functionname:    SIT_v_CalcObjectFeaturesPre                                                                      */ /*!

  @brief           Preprocessing calculation of object features

  @description     Preprocessing calculation of object features

		@startuml
		Start
		Partition SIT_v_CalcObjectFeaturesPre {
			#Orange :<b> SIT_v_DetectOccludedByTrace</b>: objects are occluded based on a trace analysis;
			Repeat 
				: Calculate the point where trace and trajectory meet;
			Repeat While (For Entire Object List)
		}
		End
		@enduml

  @return          -

  @param[in]       -

  @glob_in         -
  @glob_out        pt_SITOutput->t_ObjList[ObjNr].f_CrossingDistTrace  : Point where trace and trajectory meet,float32 Longitudinal distance of the crossing point [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] 

  @c_switch_part   SIT_USE_OBJ_OCCLUSION_LANEASSOCIATION : Configuration switch to enable occlusion calculation usage for inlane decision
  @c_switch_part   FCT_CFG_OBJECT_TRACE_PREPROCESSSING   : FCT support for Object Trace Preprocessing (FIP) and using Traces in FCT, irrespective of where they are computed
  @c_switch_full   FCT_CFG_ACC_SITUATION : FCT support for ACC SIT (situation) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         -

  @author          -
*************************************************************************************************************************/
void SIT_v_CalcObjectFeaturesPre(void)
{
  ObjNumber_t ObjNr;
#if (SIT_USE_OBJ_OCCLUSION_LANEASSOCIATION == SWITCH_ON)
  /* Determine if objects are occluded based on a trace analysis */
#if (FCT_CFG_OBJECT_TRACE_PREPROCESSSING)
  SIT_v_DetectOccludedByTrace();
#endif /* END IF (FCT_CFG_OBJECT_TRACE_PREPROCESSSING) */
#endif /* END IF (SIT_USE_OBJ_OCCLUSION_LANEASSOCIATION) */

#if (FCT_CFG_OBJECT_TRACE_PREPROCESSSING)
  for (ObjNr = (ObjNumber_t)(EM_N_OBJECTS - 1); ObjNr >= 0; ObjNr--)
  {
    pt_SITOutput->t_ObjList[ObjNr].f_CrossingDistTrace = SIT_f_SetCrossingDistTrace(ObjNr);
  }
#else
  _PARAM_UNUSED(ObjNr);
#endif /* END IF (FCT_CFG_OBJECT_TRACE_PREPROCESSSING) */
}

#if(SIT_USE_OBJ_OCCLUSION_LANEASSOCIATION == SWITCH_ON)
#if (FCT_CFG_OBJECT_TRACE_PREPROCESSSING)
/*************************************************************************************************************************
  Functionname:    SIT_v_DetectOccludedByTrace                                                            */ /*!

  @brief           Determine if objects are occluded based on a trace analysis

  @description     This function initializes the "occluded by trace" flag for all objects and calls the "occluded by trace" 
                   check for the left and the right side.

		@startuml
		Start
		Partition SIT_v_DetectOccludedByTrace {
			Repeat 
				: Occluded by trace is a boolean and is set to default value of 0 initially;
			Repeat While (For Entire Object List)
			#Orange : <b>SIT_v_DetectOccludedByTraceSigleSide</b>: Check for traces which go through the next long OOI on the right side or Left side; 
		}
		End
		@enduml

  @return          -

  @param[in]       -
  @param[out]      -

  @glob_in         pt_SITInput->t_OOI.pu_OOIListObjId(i) : ger object number of object of interest [0 ... EM_N_OBJECTS[
                            with i in [0 ... 6[ as defined in aiOOIList_array_t in Rte_Type.h
  @glob_out         pt_SITOutput->t_ObjList[i].t_Bool.OccludedByTrace : information if object i is occluded by a trace [TRUE, FALSE]
                            with i in [0 ... EM_N_OBJECTS[ and EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h

  @c_switch_part   -
  @c_switch_full   LA_USE_OBJ_OCCLUSION_LANEASSOCIATION : enables occluded-by-trace calculation
  @c_switch_full   FCT_CFG_ACC_SITUATION :  FCT support for ACC SIT (situation) sub-component
  @c_switch_full   FCT_CFG_OBJECT_TRACE_PREPROCESSSING : Config switch for using Traces in FCT, irrespective of where they are computed

  @pre             trace computation done for current cycle
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         -

  @author          Marie-Theres Boll | Marie-Theres.Boll | +49-8382-9699-632
*************************************************************************************************************************/
static void SIT_v_DetectOccludedByTrace(void)
{
  ObjNumber_t ObjNr;

  /* Set default values */
  for (ObjNr = (ObjNumber_t)(EM_N_OBJECTS - 1); ObjNr >= 0; ObjNr--)
  {
    pt_SITOutput->t_ObjList[ObjNr].t_Bool.OccludedByTrace = 0u;
  }

  /* Check for traces which go through the next long OOI on the right side */
  SIT_v_DetectOccludedByTraceSigleSide(*pt_SITInput->t_OOI.pu_OOIListObjId((uint8)OBJ_NEXT_LONG_RIGHT_OOI), SIT_OCCL_BY_TRACE_RIGHT);
  /* Check for traces which go through the next long OOI on the left side */
  SIT_v_DetectOccludedByTraceSigleSide(*pt_SITInput->t_OOI.pu_OOIListObjId((uint8)OBJ_NEXT_LONG_LEFT_OOI), SIT_OCCL_BY_TRACE_LEFT);
}

/*************************************************************************************************************************
  Functionname:    SIT_v_DetectOccludedByTraceSigleSide                                                            */ /*!

  @brief           Determine if objects are occluded based on a trace analysis for a single side

  @description     Determine if objects are occluded based on a trace analysis for a single side. An object is considered 
                   as "hidden by trace" if the trace of this objects goes "through" the next long OOI on this side.
                   It is iterated over the different trace-objects and the polynom through the objects is determine in order 
                   to calculate the lateral distance of the next long OOI to the trace polynomial.

		@startuml
		Start
		Partition SIT_v_DetectOccludedByTraceSigleSide {
			If (next long OOI object is available) then (yes)
				: Get the x- and y-position of the next long OOI;
				Repeat
					: Defining local variables from reference pointer
					If (FCT Object is less than Trace Valid Object Id and Not Equals to next Long OOI) then (yes)	
						: Set Object Longitudinal Displacement;
						If (there is a x-sample lower and higher than the x-position of the next long OOI) then (yes)
							Repeat 
								If (Trace Point in X coordinate is more than X position of the next long OOI and next trace Point in X Coordinate is less than or equal to next long OOI) then (yes)
									: Find the number of samples with positive X coordinate;
									Repeat
										: Decrease Approximate Points by 1;
									Repeat While (Number Approximate Points is more than 1 and Trace Point X coordinate is less than or equals to 0)
									If (Number Approximate Points is more than 3) then (yes)
										: Interpolate a polynomial through the trace samples;
										: Get the distance of the next long OOI to the ACC trajectory;
										: Get the distance of the next long OOI to the trace polynomial;
										If (SIT_Occlusion By Trace Side is Right) then (yes)
											If (Control structures exceeds 15) then (yes)
												: Set occluded by trace as 1;
											Endif
										Else if (SIT_Occlusion By Trace Side is Left) then (yes)
											If (Control structures is agreed up) then (yes)
												: Set occluded by trace as 1;
											Endif
										Else (no)
											: Do Nothing;
										Endif
									Endif
								Endif
							Repeat While (For All Trace Samples)
						Endif
				Repeat While (All Trace Objects)
			Endif
		}
		End
		@enduml

  @return          -

  @param[in]       t_NextLongOOI : ID of next long OOI [0 ... EM_N_OBJECTS[
                           with EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @param[in]       t_OcclSide : left or right side which should be considered [t_SIT_OcclusionByTraceSide]
  @param[out]      -

  @glob_in         pt_SITInput->t_RTE.pf_ObjLongDisp(i) : Longitudinal distance of object i [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                            with i in [0 ... EM_N_OBJECTS[ and EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @glob_in         pt_SITInput->t_RTE.pf_ObjLatDisp(i) : Lateral distance of object i [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                            with i in [0 ... EM_N_OBJECTS[ and EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @glob_in         pt_SITInput->t_FIPMOT.pt_FIPMovObjStaticTrace(i)->iNumberOfPoints : No of points for the given trace i as defined in cp_ext.h [0 ... CAL_MAX_NB_TRAJ_SAMPLES]
                            with i in [0 ... FIP_STATIC_TRACE_NO_OF_TRACES[ and FIP_STATIC_TRACE_NO_OF_TRACES as in Rte_SWCEmAdapt_Type.h
  @glob_in         pt_SITInput->t_FIPMOT.pt_FIPMovObjStaticTrace(i)->uiReferenceToFCTObject : The reference FCT Object Id for given trace i [0 ... EM_N_OBJECTS-1s] 
                            with i in [0 ... FIP_STATIC_TRACE_NO_OF_TRACES[ and FIP_STATIC_TRACE_NO_OF_TRACES as in Rte_SWCEmAdapt_Type.h
  @glob_in         pt_SITInput->t_FIPMOT.pt_FIPMovObjStaticTrace(i)->fTracePointX : The X coordinate of given trace i [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m 
                            with i in [0 ... FIP_STATIC_TRACE_NO_OF_TRACES[ and FIP_STATIC_TRACE_NO_OF_TRACES as in Rte_SWCEmAdapt_Type.h
  @glob_in         pt_SITInput->t_FIPMOT.pt_FIPMovObjStaticTrace(i)->fTracePointY : The Y coordinate of given trace i [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                            with i in [0 ... FIP_STATIC_TRACE_NO_OF_TRACES[ and FIP_STATIC_TRACE_NO_OF_TRACES as in Rte_SWCEmAdapt_Type.h
  @glob_in         pt_SITInput->t_LAInput.pf_ObjToRefDistMeas    : Pointer to object to reference distance measurement                            [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m       
  @glob_in         pt_SITInput->t_LAInput.pf_ObjToRefDistFiltVar : Pointer to variance of object to reference distance measurement                [0 ... PI/2*RW_FCT_MAX] m 
  @glob_out        t_LAObjOutputList[i].t_Bool.OccludedByTrace : information if object i is occluded by a trace [TRUE, FALSE]
                            with i in [0 ... EM_N_OBJECTS[ and EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_SITUATION :  FCT support for ACC SIT (situation) sub-component

  @pre             trace computation done for current cycle
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         -

  @author          Marie-Theres Boll | Marie-Theres.Boll | +49-8382-9699-632
*************************************************************************************************************************/
static void SIT_v_DetectOccludedByTraceSigleSide(const ObjNumber_t t_NextLongOOI, t_SIT_OcclusionByTraceSide t_OcclSide)
{
  uint8 u_IdxTrace, u_IdxTraceSample, u_NumApproxPts;
  float32 f_XDistNextLongOOI, f_YDistNextLongOOI;
  float32 f_YDistToTracePolyNextLongOOI;
  float32 f_DistToTrajNextLongOOI;
  CAL_t_TracePolyL2 t_ApproxPolyTrace;
  uint8 uRefToFCTObject;
  sint8 i_NumberOfPoints;
  float32 f_ObjLongDisp;

  /* Find occluded objects only if a next long OOI object is available */
  if (t_NextLongOOI != OBJ_NOT_OOI)
  {
    /* Get the x- and y-position of the next long OOI */
    f_XDistNextLongOOI = *pt_SITInput->t_RTE.pf_ObjLongDisp(t_NextLongOOI);
    f_YDistNextLongOOI = *pt_SITInput->t_RTE.pf_ObjLatDisp(t_NextLongOOI);

    /* Check if there exists a trace which goes "through" the next long OOI 
      -> the object of this trace is marked as "occluded by trace" */
    for (u_IdxTrace = 0u; u_IdxTrace < FIP_STATIC_TRACE_NO_OF_TRACES; u_IdxTrace++)
    {
      /* Defining local variables from reference pointer */
      uRefToFCTObject = pt_SITInput->pt_FIPMOT->t_MovObjStaticTrace[u_IdxTrace].uiReferenceToFCTObject;
      i_NumberOfPoints = pt_SITInput->pt_FIPMOT->t_MovObjStaticTrace[u_IdxTrace].iNumberOfPoints;

      if((uRefToFCTObject < FIP_u_TRACE_VALID_NO_OBJ_ID) && (uRefToFCTObject != t_NextLongOOI))/* PRQA S 1863 *//* Date: 2020-04-02, Reviewer:Tejaswini M , Reason:This warning is suppressed as it does not have any critical impact on the functionality. */
      {
        f_ObjLongDisp=*pt_SITInput->t_RTE.pf_ObjLongDisp((sint8)uRefToFCTObject);
        /* If the object of the trace is valid and if the distance to the next long OOI is lower than a threshold */
        if((f_ObjLongDisp - (f_XDistNextLongOOI)) < SIT_MAX_DIST_OOI_TO_TRACE_OBJ) 
        {
          /* Check if there is a x-sample lower and higher than the x-position of the next long OOI */
          for (u_IdxTraceSample = 0u; u_IdxTraceSample < (uint8)i_NumberOfPoints - 1u ; u_IdxTraceSample ++ )
          {
            if( (pt_SITInput->pt_FIPMOT->t_MovObjStaticTrace[u_IdxTrace].fTracePointX[u_IdxTraceSample] > f_XDistNextLongOOI) && 
              (pt_SITInput->pt_FIPMOT->t_MovObjStaticTrace[u_IdxTrace].fTracePointX[u_IdxTraceSample + 1u] <= f_XDistNextLongOOI)
              )
            {
              /* Find the number of samples with positive X coordinate */
              u_NumApproxPts = (uint8)i_NumberOfPoints;
              while ((u_NumApproxPts > 1u) && (pt_SITInput->pt_FIPMOT->t_MovObjStaticTrace[u_IdxTrace].fTracePointX[u_NumApproxPts-2u] <= 0.f))
              {
                u_NumApproxPts--;
              }

              if (u_NumApproxPts >= 3u)
              {
                /* Interpolate a polynomial through the trace samples */
                CAL_v_CalcPointApproxPolyL2(&t_ApproxPolyTrace, pt_SITInput->pt_FIPMOT->t_MovObjStaticTrace[u_IdxTrace].fTracePointX, pt_SITInput->pt_FIPMOT->t_MovObjStaticTrace[u_IdxTrace].fTracePointY, u_NumApproxPts);

                /* Get the distance of the next long OOI to the ACC trajectory */
  #if (FCT_CFG_ACC_LANE_ASSOCIATION)
                f_DistToTrajNextLongOOI = *(pt_SITInput->t_LAInput.pf_ObjToRefDistMeas(t_NextLongOOI));        
  #endif
              
                /* Get the distance of the next long OOI to the trace polynomial */
                f_YDistToTracePolyNextLongOOI = t_ApproxPolyTrace.fC0 + t_ApproxPolyTrace.fC1 * f_XDistNextLongOOI + 
                  t_ApproxPolyTrace.fC2 * f_XDistNextLongOOI * f_XDistNextLongOOI;

                /* If the distance of the trace to the next long OOI is within limits, set the "occluded by trace"-bit 
                  (if the distance of the next long OOI to the ACC trajectory is high, the threshold is different) */
                if (t_OcclSide == SIT_OCCL_BY_TRACE_RIGHT)
                {/* PRQA S 715 */
                 /* date: 2017-02-17, reviewer: Harsha Umesh Babu, reason: Nested control structures exceeds 15, not safety critical */
                  if( ( (f_YDistNextLongOOI - f_YDistToTracePolyNextLongOOI > SIT_MIN_DIST_OOI_TO_TRACE) ||
                        ( (f_YDistNextLongOOI - f_YDistToTracePolyNextLongOOI > SIT_MIN_DIST_OOI_TO_TRACE_ACC_TRAJ) &&
                          (f_DistToTrajNextLongOOI - f_YDistToTracePolyNextLongOOI > SIT_MIN_DIST_OOI_TO_ACC_TRAJ)
                        )
                      ) && 
                      (f_YDistNextLongOOI - f_YDistToTracePolyNextLongOOI < SIT_MAX_DIST_OOI_TO_TRACE)
                    )
                  {// PRQA S 3355,2004,715
                    /* date: 2015-06-11, reviewer: Gangadhar Badiger, reason: conditions checked already in if and else, else is not required here. since nothing is performed inside else*/
                    pt_SITOutput->t_ObjList[uRefToFCTObject].t_Bool.OccludedByTrace = 1u;
                    break;
                  }
                }
                else if(t_OcclSide == SIT_OCCL_BY_TRACE_LEFT)// PRQA S 3355,2004,3358,715
                 /* date: 2015-06-11, reviewer: Gangadhar Badiger, reason: conditions checked already in if and else, else is not required here. since nothing is performed inside else*/
                {
                  if( ( (f_YDistNextLongOOI - f_YDistToTracePolyNextLongOOI < -SIT_MIN_DIST_OOI_TO_TRACE) ||// PRQA S 715
                  /* date: 2015-06-11, reviewer: Gangadhar Badiger, reason:Need to change control structure if agreed up on*/
                        ( (f_YDistNextLongOOI - f_YDistToTracePolyNextLongOOI < -SIT_MIN_DIST_OOI_TO_TRACE_ACC_TRAJ) &&
                          (f_DistToTrajNextLongOOI - f_YDistToTracePolyNextLongOOI < -SIT_MIN_DIST_OOI_TO_ACC_TRAJ)
                        )
                      ) && 
                      (f_YDistNextLongOOI - f_YDistToTracePolyNextLongOOI > -SIT_MAX_DIST_OOI_TO_TRACE)
                    )
                  {
                    pt_SITOutput->t_ObjList[uRefToFCTObject].t_Bool.OccludedByTrace = 1u;
                    break;// PRQA S 771
                     /* date: 2015-06-11, reviewer: Gangadhar Badiger, reason:Need to change control structure if agreed up on */
                  }
                }
              }
            }
          }
        }
      }
    }
  }
}
#endif /* END IF (FCT_CFG_OBJECT_TRACE_PREPROCESSSING) */
#endif


#if (FCT_CFG_OBJECT_TRACE_PREPROCESSSING)
/*************************************************************************************************************************
  Functionname:    SIT_f_SetCrossingDistTrace                                                                           */ /*!

  @brief           Calculate the point where trace and trajectory meet

  @description     Calculate the longitudinal crossing point of the trajectory 
                   and the corresponding trace trajectory

		@startuml
		Start
		Partition SIT_f_SetCrossingDistTrace {
			If (No Valid Trace Found) then (yes)
				: Set Distance Crossing as 0;
			Else (no)
				: Store polynomial trace parameters of trace Object;
				If (Polynomial trace is valid and Absolute Course Curve is more than zero)
					: Calculate the crossing point between the two curves;
					If (First auxiliary Crossing point value is more than Second one) then (yes)
						: Use the larger crossing point as result;
					Else (no)
						: The two polynomials are not crossing;
					Endif
				Else (no)
					: Trace is invalid;
				Endif
			Endif
		}
		End
		@enduml

  @return          fDistCrossing : float32 Longitudinal distance of the crossing point [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m

  @param[in]       ObjID : Object ID [OBJ_INDEX_NO_OBJECT ... EM_N_OBJECTS-1]

  @glob_in         *(pt_SITInput->t_FIPMOT.pu_FIPStaticTraceID(i)) : Trace index of object i [full range of unsigned char data type]
  @glob_in         pt_SITInput->t_CP.pf_CourseCurve : Radius of the curve provided by the VDY trajectory [-1.f ... +1.f] m^(-1)
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_OBJECT_TRACE_PREPROCESSSING : Config switch for using Traces in FCT, irrespective of where they are computed
  @c_switch_full   FCT_CFG_ACC_SITUATION : FCT support for ACC SIT (situation) sub-component

  @pre             ObjId passed has to belong to a valid object
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         29.02.2016
  @changed         29.02.2016

  @author          Christopher Knievel | Christopher.Knievel@continental-corporation.com | +49 (8382) 9699-399
*************************************************************************************************************************/
static float32 SIT_f_SetCrossingDistTrace(const ObjNumber_t ObjID)
{
  float32 fDistCrossing = 0.0f;
  float32 fAuxCross1, fAuxCross2, fAuxP, fAuxQ;
  CAL_t_TracePolyL2 pTracePoly;
  float32 fABS_CourseCurve;		/* For calculating ABS value */
  const TraceID_t iObjTrace = *(pt_SITInput->t_FIPMOTTraceId.pu_FIPStaticTraceID(ObjID));

  if(iObjTrace >= FIP_u_TRACE_VALID_NO_OBJ_ID)
  { 
    /* No valid trace found, set crossing distance to zero. 
       This results in a scaling factor of one. */
    fDistCrossing = 0.0f;
  }
  else
  {
    /* Store polynomial trace parameters of trace iObjTrace*/
    pTracePoly = *pt_SITInput->t_CP.pt_TracePoly(iObjTrace);
	fABS_CourseCurve = fABS(pTracePoly.fC2 - (0.5f * (*pt_SITInput->t_CP.pf_CourseCurve)));

    if(   (pTracePoly.isValid != FALSE)
       && (fABS_CourseCurve > CML_f_AlmostZero ))
    {
      /* Calculate the crossing point between the two curves */
      fAuxP = pTracePoly.fC1 / (pTracePoly.fC2 - (0.5f * (*pt_SITInput->t_CP.pf_CourseCurve)));
      fAuxQ = pTracePoly.fC0 / (pTracePoly.fC2 - (0.5f * (*pt_SITInput->t_CP.pf_CourseCurve)));

      if(SQR(fAuxP/2.0f) > fAuxQ)
      {
        fAuxCross1 = - (fAuxP/2.0f) + SQRT_(SQR(fAuxP/2.0f) - fAuxQ);
        fAuxCross2 = - (fAuxP/2.0f) - SQRT_(SQR(fAuxP/2.0f) - fAuxQ);

        /* Use the larger crossing point as result */
        fDistCrossing = (fAuxCross1 > fAuxCross2) ? fAuxCross1 : fAuxCross2;
      }
      else
      {
        /* The two polynomials are not crossing.  */
        fDistCrossing = 0.0f;
      }
    }
    else
    {
      /* Trace is invalid */
      fDistCrossing = 0.0f;
    }
  }

  return fDistCrossing;
}
#endif /* END IF (FCT_CFG_OBJECT_TRACE_PREPROCESSSING) */
/* PRQA L:EMPTY_ELSE_OR_DEFAULT */
///@}
#endif /* (FCT_CFG_ACC_SITUATION) */
/* ************************************************************************* */
/*   Copyright ADC-GmbH, Lindau                                              */
/* ************************************************************************* */
