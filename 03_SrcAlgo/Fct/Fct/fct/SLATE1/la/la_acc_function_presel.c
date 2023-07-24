/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 SLATE_LA (Lane Association)

PACKAGENAME:               la_acc_function_presel.c

DESCRIPTION:               Evaluates the ACC quality and the time gap of each object. Only objects which pass the 
                           ACC pre-selection can be considered in the functional lane association

AUTHOR:                    Fridolin Kolb

CREATION DATE:             12.09.2007

VERSION:                   $Revision: 1.26 $

LEGACY VERSION:            Revision: 2.2

**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/


#include "la.h"//PRQA S 0380
/* date: 2019-07-28, reviewer:Prabhu Sundaramurthy, reason: Arises due to inclusion of multiple header files in this header file which has multiple macros*/

#if (FCT_CFG_ACC_LANE_ASSOCIATION)
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
@defgroup la_acc_function_presel LA ACC function Preselection
@ingroup la
@brief          Provides functions to checks ACC range,pick up distance for objects based on object and ego vechicle properties. \n
                Thus selecting qualified objects for ACC functionality \n

@{

*/

/*****************************************************************************
  MACROS 
*****************************************************************************/
#define LA_RANGERED_ON            (1.0f)
#define LA_RANGERED_OFF           (0.0f)
#define LA_RANGERED_FILTERFAST    (5.0f)

/* curve dependent RangeReduction to avoid false pickups in curveexit situations*/             /*|*/
/* and alternating curves*/                                                                    /*|*/
/* simple curve observer */
#define LA_RANGERED_CURVE_THRESH     (1.0F/2000.0F)                                            /*|*/
#define LA_RANGERED_OFF_TIMEKONSTANT (100.0F)                                                  /*|*/
#define LA_RANGERED_ON_TIMEKONSTANT  (LA_RANGERED_FILTERFAST)                                  /*!*/


#if (SLATE_CFG_USE_DRIVE_MODE)
static const GDBLFunction_t t_LAMovingObjBasePickUpRangeParamEco = {
  LA_ACC_RANGE_DEFAULT_LOW_VEGO_TG_ECO,
  LA_ACC_RANGE_DEFAULT_HIGH_VEGO_TG_ECO,
  ( ( LA_ACC_RANGE_DEFAULT_HIGH_VEGO_TG_ECO - LA_ACC_RANGE_DEFAULT_LOW_VEGO_TG_ECO ) / ( LA_ACC_RANGE_DEFAULT_VEGO_HIGH - LA_ACC_RANGE_DEFAULT_VEGO_LOW ) ),
  LA_ACC_RANGE_DEFAULT_LOW_VEGO_TG_ECO - ( (( LA_ACC_RANGE_DEFAULT_HIGH_VEGO_TG_ECO - LA_ACC_RANGE_DEFAULT_LOW_VEGO_TG_ECO ) / ( LA_ACC_RANGE_DEFAULT_VEGO_HIGH - LA_ACC_RANGE_DEFAULT_VEGO_LOW ) ) * LA_ACC_RANGE_DEFAULT_VEGO_LOW)
};
#endif /* (SLATE_CFG_USE_DRIVE_MODE) */
/* Base/default pick-up range is computed by multiplying ego velocity (vego) with a time-gap value, which is linearily interpolated
   vego < LA_ACC_RANGE_DEFAULT_VEGO_LOW  : LA_ACC_RANGE_DEFAULT_LOW_VEGO_TG
   vego > LA_ACC_RANGE_DEFAULT_VEGO_HIGH : LA_ACC_RANGE_DEFAULT_HIGH_VEGO_TG
   else : [LA_ACC_RANGE_DEFAULT_LOW_VEGO_TG  -  (vego - LA_ACC_RANGE_DEFAULT_VEGO_LOW  ) /(LA_ACC_RANGE_DEFAULT_VEGO_HIGH - LA_ACC_RANGE_DEFAULT_VEGO_LOW)] 
 */
static const GDBLFunction_t t_LAMovingObjBasePickUpRangeParam = {// PRQA S 3218
   /* date: 2016-10-28, reviewer: Grant Davtjan, reason: static local for saving data across function calls */
  LA_ACC_RANGE_DEFAULT_LOW_VEGO_TG,
  LA_ACC_RANGE_DEFAULT_HIGH_VEGO_TG,
  ( ( LA_ACC_RANGE_DEFAULT_HIGH_VEGO_TG - LA_ACC_RANGE_DEFAULT_LOW_VEGO_TG ) / ( LA_ACC_RANGE_DEFAULT_VEGO_HIGH - LA_ACC_RANGE_DEFAULT_VEGO_LOW ) ),
  LA_ACC_RANGE_DEFAULT_LOW_VEGO_TG - ( (( LA_ACC_RANGE_DEFAULT_HIGH_VEGO_TG - LA_ACC_RANGE_DEFAULT_LOW_VEGO_TG ) / ( LA_ACC_RANGE_DEFAULT_VEGO_HIGH - LA_ACC_RANGE_DEFAULT_VEGO_LOW ) ) * LA_ACC_RANGE_DEFAULT_VEGO_LOW)
};

/*****************************************************************************
  MACROS (KOMPONENTENINTERN)
*****************************************************************************/

/*****************************************************************************
  TYPEDEFS
*****************************************************************************/
typedef enum LA_VrelRangeModKinModel
{
  LA_VREL_RANGE_MOD_MIN,
  LA_VREL_RANGE_MOD_COMF
}LA_VrelRangeModKinModel_t;

/*****************************************************************************
  (SYMBOLIC) CONSTANTS 
*****************************************************************************/

/*****************************************************************************
  VARIABLES 
*****************************************************************************/

/*****************************************************************************
  FUNCTION 
*****************************************************************************/
static void LA_v_ResetRangeFactor(void);
static void LA_v_UpdateRangeFactor(void);
static boolean LA_b_CheckACCRangeCriteria_propertytype(ObjNumber_t t_ObjNr);

#if (FCT_CFG_CURVATURE_CHANGE_COMPUTATION)
static float32 LA_f_GetRangeFacBasedOnDistToCurvatureChange(void);
#endif
static void LA_v_SetMovingObjBasePickUpRange(void);
static boolean LA_b_CheckACCRangeCriteria(ObjNumber_t t_ObjNr);
static float32 LA_f_GetACCRangeForStationary(ObjNumber_t t_ObjNr);
static float32 LA_f_GetACCRangeForMoving(ObjNumber_t t_ObjNr);
static float32 LA_f_GetMovObjRangeHysteresis(ObjNumber_t t_ObjNr, float32 f_RangeFacLocal);
static float32 LA_f_GetACCRangeForOncoming(ObjNumber_t t_ObjNr);
static boolean LA_b_GetSitRangeRedFlag(ObjNumber_t t_ObjNr);
static boolean LA_b_GetSitRangeExtFlag(ObjNumber_t t_ObjNr);
static float32 LA_f_ComputeVrelDepPickUpRange(ObjNumber_t t_ObjNr, LA_VrelRangeModKinModel_t t_KinModel);

/*PRQA S 2013,2016 EMPTY_ELSE_OR_DEFAULT*/
/* date: 2019-07-28, reviewer:Prabhu Sundaramurthy, reason: Empty else or default, no effect on functionality*/

/*************************************************************************************************************************
  Functionname:    LA_v_ResetRangeFactor                                                            */ /*!

  @brief           Reset the range factor

  @description     Reset the range factor e.g. when ego stops

		@startuml
		Start
		Partition LA_v_ResetRangeFactor {
		: Reset the range factor e.g. when ego stops;
		}
		End
		@enduml

  @return          -

  @param[in]       -
  @param[out]      -

  @glob_in         -
  @glob_out        pt_LAOutput->fRangeFac : factor used for curvature depedant range reduction [0.0f]

  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         -

  @author          Marie-Theres Boll | Marie-Theres.Boll@continental-corporation.com | +49 (8382) 9699-632
*************************************************************************************************************************/
static void LA_v_ResetRangeFactor(void)
{
  /* Reset range factor (global) */
  pt_LAOutput->fRangeFac = 0.0f;
}

/*************************************************************************************************************************
  Functionname:    LA_v_InitAccFunPreselection                                                            */ /*!

  @brief           Initialize ACC function preselection

  @description     In this case initialization is identical to a reset. Thus the function calls the reset function.

		@startuml
		Start
		Partition LA_v_InitAccFunPreselection {
		: Initialize ACC function preselection (Reset the range factor e.g. when ego stops);
		}
		End
		@enduml

  @return          -

  @param[in]       -
  @param[out]      -

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         -

  @author          Nele Hanel | nele.hanel@continental-corporation.com | +49 (8382) 9699-401
*************************************************************************************************************************/
void LA_v_InitAccFunPreselection(void)
{
  LA_v_ResetRangeFactor();
}



/*************************************************************************************************************************
  Functionname:    LA_v_UpdateRangeFactor                                                            */ /*!

  @brief           Update ACC selection range factor

  @description     Update ACC selection range factor. The range factor is a filtered value with two alternative inputs.
                   First: The VDY curvature based range factor. This version of the VDY curvature based range factor only takes 
                   the current driven curvature into account. Second: A range factor based on the curvature change information 
                   from FIP curvature change. FIP curvature change fuses the distance to a high curvature change from road (FIP road) 
                   and navigation data (FIP navi). If the curvature change information is not available, the VDY curvature based 
                   range factor is used.

		@startuml
		Start
		Partition LA_v_UpdateRangeFactor {
		: Set Filter Factor On as LA_RANGERED_ON_TIMEKONSTANT;
		: Set Filter Factor Off as LA_RANGERED_OFF_TIMEKONSTANT;
		: Get distance to high curvature change (curve entry/exit) valid flag;
		If (Check if distance to high curvature change (curve entry/exit) is available) then (yes)
			: Update Filter Factor On as LA_RANGERED_FILTERFAST;
			: Update Filter Factor Off as LA_RANGERED_FILTERFAST;
			: Set new range factor according to distance to high curvature change;
		Else (no)
			: Update Ego Curve and New Range Factor;
		Endif
		If (New Range Factor < Range Factor) then (yes)
			: Update Range Factor as Filter Factor off;
		Else (no)
			: Update Range Factor as Filter Factor on;
		Endif
		}
		End
		@enduml

  @return          -

  @param[in]       -
  @param[out]      -

  @glob_in         *pt_LAInput->t_FIPCC.pb_FusedDistToHighCCValid : valid flag for distance to high curvature flag [TRUE, FALSE]
  @glob_in         EGO_SPEED_X_OBJ_SYNC : Ego velocity provided by VDY [-330.f ... 330.f] m/s
  @glob_in         EGO_CURVE_OBJ_SYNC : Ego curve [-1.f ... 1.f] 1/m
  @glob_in         EGO_CURVE_RAW : Ego curve [-1.f ... 1.f] 1/m
  @glob_in         SIT_CYCLE_TIME : [0.f ... 1.f] s
  @glob_in         pt_LAOutput->fRangeFac : factor used for curvature depedant range reduction [0.0f ... 1.0f]
  @glob_in         pt_LAInput->t_FIPRoadType.pt_FusedRoadType : Reference to FIP road type [full range of FIP_t_FusedRoadType as in fip_ext.h]
  @glob_out        pt_LAOutput->fRangeFac : factor used for curvature depedant range reduction [0.0f ... 1.0f]

  @c_switch_part   FCT_CFG_CURVATURE_CHANGE_COMPUTATION : FCT support for Curvature Change Computation in FIP
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component

  @pre             LA_v_InitAccFunPreselection called once previously
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).
  
  @traceability    215:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-215-00061542 \n
                   241:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-241-00061542 \n

  @created         -
  @changed         -

  @author          Nele Hanel | nele.hanel@continental-corporation.com | +49 (8382) 9699-401
*************************************************************************************************************************/
static void LA_v_UpdateRangeFactor(void)
{
#if (FCT_CFG_CURVATURE_CHANGE_COMPUTATION)
  boolean b_DistToHighCurvatureChangeValid; /* Valid flag for distance to high curvature change */
#endif
  float32   f_NewRangeFac;
  fCurve_t  f_EgoCurve;
  float32   f_FilterFactorOn;
  float32   f_FilterFactorOff;
  fCurve_t  f_ABS_EgoCurve;

  /**********************************************************************************/
  /* simple curve observer and range reduction logic                                */
  /**********************************************************************************/
  f_FilterFactorOn  = LA_RANGERED_ON_TIMEKONSTANT;
  f_FilterFactorOff = LA_RANGERED_OFF_TIMEKONSTANT;

#if (FCT_CFG_CURVATURE_CHANGE_COMPUTATION)
  /* Get distance to high curvature change (curve entry/exit) valid flag */
  b_DistToHighCurvatureChangeValid = pt_LAInput->pt_FIPCC->b_FusedDistToHighCCValid; /* Get valid flag for distance to curvature change*/

  /* Check if distance to high curvature change (curve entry/exit) is available */
  if (b_DistToHighCurvatureChangeValid == TRUE)
  {
    /* fast filtering in case distance to high curvature change available */
    f_FilterFactorOn  = LA_RANGERED_FILTERFAST;
    f_FilterFactorOff = LA_RANGERED_FILTERFAST;

    /* Set new range factor according to distance to high curvature change */
    f_NewRangeFac = LA_f_GetRangeFacBasedOnDistToCurvatureChange();
  } else
#endif
  {
    /* Low Pass Filter of RangeReductionFac */
    f_EgoCurve    = *(pt_LAInput->t_RTE.pf_EgoCurveRaw);
    f_ABS_EgoCurve    = fABS(f_EgoCurve);
    f_NewRangeFac = (f_ABS_EgoCurve > LA_RANGERED_CURVE_THRESH)?1.0F:0.0F;
  }

  if(f_NewRangeFac < pt_LAOutput->fRangeFac)
  {
    pt_LAOutput->fRangeFac = GDB_FILTER(f_NewRangeFac , pt_LAOutput->fRangeFac , f_FilterFactorOff );
  }
  else
  {
    pt_LAOutput->fRangeFac = GDB_FILTER(f_NewRangeFac , pt_LAOutput->fRangeFac , f_FilterFactorOn );
  }
}

#if (FCT_CFG_CURVATURE_CHANGE_COMPUTATION)
/*************************************************************************************************************************
  Functionname:    LA_f_GetRangeFacBasedOnDistToCurvatureChange                                 */ /*!

  @brief           Set the range factor based on the x-distance to high curvature change

  @description     Set the range factor based on the x-distance to high curvature change. 
                   The computation of the distance in FIP is based on navi, road and VDY information.

		@startuml
		Start
		Partition LA_f_GetRangeFacBasedOnDistToCurvatureChange {
		: Get distance to high curvature change (curve entry/exit);
		: Get minimum pick-up range for moving objects;
		: Get base pick-up range for moving objects;
		If (Check if distance to high curvature change is above pick-up range for moving objects without range reduction) then (yes)
			: Do not apply range reduction;
		Else if (Check if distance to high curvature change is above pick-up range for moving objects with maximum range reduction) then (yes)
			: Apply maximum range reduction;
		Else (no)
			: Between base and minimum pick-up range the range factor is given by linear interpolation between 0 and 1;
			If (Check if Moving Object Pick Up Range Max Min Delta > 0.001) then (yes)
				: Update Range factor based on the x-distance to high curvature change;
			Endif
		Endif
		}
		End
		@enduml

  @return          f_RangeRedFactorCC : range factor based on the x-distance to high curvature change [0.f ... 1.f]

  @param[in]       -
  @param[out]      -

  @glob_in         pt_LAInput->pt_FIPCC->f_FusedDistToHighCC : x-distance to high curvature [0.f ... 5*RW_FCT_MAX]
  @glob_in         EGO_SPEED_X_OBJ_SYNC : Ego velocity provided by VDY [-330.f ... 330.f] m/s
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_CURVATURE_CHANGE_COMPUTATION : FCT support for Curvature Change Computation in FIP
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         -

  @author          Grant Davtjan | Grant.Davtjan@continental-corporation.com | +49-8382-9699-633
*************************************************************************************************************************/
static float32 LA_f_GetRangeFacBasedOnDistToCurvatureChange(void)
{
  float32 f_DistToHighCurvatureChange;          /* Distance to high curvature change (curve entry/exit) */
  float32 f_MovingObjMinPickUpRange;            /* Minimum pick-up range for moving objects */
  float32 f_MovingObjBasePickUpRange;           /* Minimum pick-up range for moving objects */
  float32 f_MovingObjPickUpRangeMaxMinDelta;    /* Base pick-up range for moving objects */
  float32 f_RangeRedFactorCC = LA_RANGERED_OFF; /* Range factor based on the x-distance to high curvature change */
  float32 f_EgoVelObjSync = SLATE_f_GetEgoVelObjSync();

  /* Get distance to high curvature change (curve entry/exit) */
  f_DistToHighCurvatureChange = pt_LAInput->pt_FIPCC->f_FusedDistToHighCC; 

  /* Get minimum pick-up range for moving objects */
  f_MovingObjMinPickUpRange = f_EgoVelObjSync * LA_ACC_RANGE_TIMEGAP_MIN_MOVING;

  /* Get base pick-up range for moving objects */
  f_MovingObjBasePickUpRange = f_EgoVelObjSync * dGDBmathLineareFunktion( &t_LAMovingObjBasePickUpRangeParam, f_EgoVelObjSync);

  /* Check if distance to high curvature change is above pick-up range for moving objects without range reduction */
  if (f_DistToHighCurvatureChange > f_MovingObjBasePickUpRange)
  {
    /* Do not apply range reduction */
    f_RangeRedFactorCC = LA_RANGERED_OFF;
  }
  /* Check if distance to high curvature change is above pick-up range for moving objects with maximum range reduction */
  else if (f_DistToHighCurvatureChange < f_MovingObjMinPickUpRange)
  {
    /* Apply maximum range reduction */
    f_RangeRedFactorCC = LA_RANGERED_ON;
  }
  else
  {
    /* Between base and minimum pick-up range the range factor is given by linear interpolation between 0 and 1 */
    f_MovingObjPickUpRangeMaxMinDelta = f_MovingObjBasePickUpRange - f_MovingObjMinPickUpRange;

    /* Check for division-by-zero */
    if (f_MovingObjPickUpRangeMaxMinDelta > CML_f_Delta)
    {
      f_RangeRedFactorCC = (f_MovingObjBasePickUpRange - f_DistToHighCurvatureChange) / f_MovingObjPickUpRangeMaxMinDelta;
    }
  }

  return f_RangeRedFactorCC;
}
#endif

/*************************************************************************************************************************
  Functionname:    LA_v_ObjectPreselection                                                            */ /*!

  @brief           Preselect objects for acc functionality

  @description     This function fills the global array LABasePreselObjList, which contains a boolean flag for each object 
                   indicating if it may take part in ACC object selection or not. Most of the object filtering is done in EM, 
                   this function only evaluates the passed ACC object quality and checks the time-gap value (which is very 
                   function specific).

		@startuml
		Start
		Partition LA_v_ObjectPreselection {
		: Update range reduction factor;
		: Set moving object base pick-up ranges with and without range reduction;
		Repeat 
			If (if object is not deleted) then (yes)
				: Preselect objects for acc functionality (Check distance of object for functional pre-selection);
			Else (no)
				: No Preselection objects for acc functionality;
			Endif
			: Save preselection decisions for debugging and display;
			: Call customizable function to merge selections;
		Repeat While (For all Objects)
		}
		End
		@enduml

  @return          -

  @param[in]       -
  @param[out]      -

  @glob_in         EGO_SPEED_X_OBJ_SYNC : Ego velocity provided by VDY [-330.f ... 330.f] m/s
  @glob_in         *SLATE_pf_GetObjLongDisp(i) : Longitudinal distance of object i [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                            with i in [0 ... EM_N_OBJECTS[ and EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @glob_in         OBJ_DYNAMIC_PROPERTY(i) : Dynamic property of object i [EM_t_ARS_DynamicProperty as defined in rte_type.h]
                            with i in [0 ... EM_N_OBJECTS[ and EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @glob_in         OBJ_IS_DELETED(i) : information if object is deleted [TRUE, FALSE]
                            with i in [0 ... EM_N_OBJECTS[ and EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @glob_in         OBJ_GET_ACC_FUN_PRESEL_QUALITY(i): ACC object quality for object i [0u ... 100u] 
                            with i in [0 ... EM_N_OBJECTS[ and EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @glob_out        pt_LAOutput->t_LAObjOutputList[i] : struct stores object specific information from LA for object i [LAObjOutputList_t as defined in la_ext.h]
                            with i in [0 ... EM_N_OBJECTS[ and EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
                    pt_LAOutput->t_LAObjOutputList[i].t_Bool.FctPreselTG [TRUE, FALSE]
  @glob_out        pt_LAOutput->LABasePreselObjList[i] : pre-selection decision for object i [BasePreselObjList_t as defined in la_ext.h]
                            with i in [0 ... EM_N_OBJECTS[ and EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h

  @c_switch_part   FCT_SIMU : FCT simulation specific function switch
  @c_switch_part   FASTSIM : FASTSIM simulation specific function switch
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).
  
  @traceability    165:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-165-00061542 \n
                   199:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-199-00061542 \n

  @created         -
  @changed         -

  @author          Grant Davtjan | Grant.Davtjan@continental-corporation.com | +49-8382-9699-633
*************************************************************************************************************************/
void LA_v_ObjectPreselection(void)
{
  ObjNumber_t ObjNr;
  boolean TGValue;
  boolean b_ObjIsDeleted;
    
  /* Update range reduction factor */
  LA_v_UpdateRangeFactor();

  /* Set moving object base pick-up ranges with and without range reduction */
  LA_v_SetMovingObjBasePickUpRange();

  for (ObjNr = (ObjNumber_t)(EM_N_OBJECTS - 1) ; ObjNr >= 0; ObjNr--)
  {
    b_ObjIsDeleted = SLATE_b_GetObjIsDeleted(ObjNr);
    if (!b_ObjIsDeleted)
    {
      TGValue    =  LA_b_CheckACCRangeCriteria(ObjNr);
    }
    else
    {
      TGValue = FALSE;
    }

    /* Save preselection decisions for debugging and display */
    pt_LAOutput->t_LAObjOutputList[ObjNr].t_Bool.FctPreselTG   = TGValue;

    /* Call customizable function to merge selections */
    pt_LAOutput->LABasePreselObjList[ObjNr] = LA_b_CustMergePreselection(ObjNr, SLATE_u_GetAccQuality(ObjNr), TGValue);
  }
}

/*************************************************************************************************************************
  Functionname:    LA_v_SetMovingObjBasePickUpRange                                                            */ /*!

  @brief           Compute base pick-up ranges for moving objects

  @description     First, an ego velocity dependent base pick-up range without range reduction is computed. 
                   Then a second pick-up range with range reduction is computed. Also, an ego velocity dependent range limitation
                   is computed and applied to both pick-up ranges. Finally, a minimum range criteria is applied to both
                   pick-up ranges and the results are stored in global variables.

		@startuml
		Start
		Partition LA_v_SetMovingObjBasePickUpRange {
		Partition #LightBlue “** if SLATE_CFG_USE_DRIVE_MODE **” {
			: Get Drive mode;
			If (Check if drive mode is ECO) then (yes)
				: Calculate ego-speed dependent pick-up range for moving objects without range reduction for eco mode;
			Else (no)
				: Calculate ego-speed dependent pick-up range for moving objects without range reduction for normal mode;
			Endif
		}
		Partition #LightBlue “** Else **”  {
			: Calculate ego-speed dependent pick-up range for moving objects without range reduction;
		}
		: Calculate ego-speed dependent minimum pick-up range for moving objects without range reduction;
		: Calculate ego-speed dependent pick-up range for moving objects with range reduction;
		: Set maximum value at lower ego velocities, maximum at higher ego velocities and maximum control time-gap for ego velocities in the middle;
		: Apply range limitation (Moving Object Base Pick Up Range and Moving Object Reduced Pick Up Range);
		: Set minimum distance and minimum control time-gap (Ego velocity dependent range limitation minimum for moving objects);
		: Update Base pick up range for moving objects without range factor correction;
		: Update Pick up range for moving objects with range factor correction;
		: Update base pick up range for moving objects and pick up range for moving objects;
		: Update ego velocity dependent range limitation minimum and maximum for moving objects;
		}
		End
		@enduml

  @return          -

  @param[in]       -
  @param[out]      -

  @glob_in         EGO_SPEED_X_OBJ_SYNC : Ego velocity provided by VDY [-330.f ... 330.f] m/s
  @glob_in         pt_LAOutput->fRangeFac : factor used for curvature depedant range reduction [0.0f ... 1.0f]
  @glob_out        pt_LAOutput->f_LAMovingObjBasePickUpRange : base pick up range for moving objects without range reduction [fDistance_t as defined in rte_type.h]
  @glob_out        pt_LAOutput->f_LAMovingObjPickUpRange : base pick up range for moving objects with range reduction [fDistance_t as defined in rte_type.h]
  @glob_out        pt_LAOutput->f_LAMovingObjRangeLimitMin : the ego velocity dependent range limitation minimum for moving objects [fDistance_t as defined in rte_type.h]
  @glob_out        pt_LAOutput->f_LAMovingObjRangeLimitMax : the ego velocity dependent range limitation maximum for moving objects [fDistance_t as defined in rte_type.h]

  @c_switch_part   FCT_SIMU : FCT simulation specific function switch
  @c_switch_part   FASTSIM : FASTSIM simulation specific function switch
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).
  
  @traceability    211:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-211-00061542 \n
                   236:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-236-00061542 \n

  @created         -
  @changed         -

  @author          Grant Davtjan | Grant.Davtjan@continental-corporation.com | +49-8382-9699-633
*************************************************************************************************************************/
static void LA_v_SetMovingObjBasePickUpRange(void)
{
  float32 f_MovingObjBasePickUpRange;      /* Base pick up range for moving objects without range factor correction */
  float32 f_MovingObjReducedPickUpRange;   /* Pick up range for moving objects with range factor correction */
  float32 f_MovingObjRangeLimitMin;        /* Ego velocity dependent range limitation minimum for moving objects */
  float32 f_MovingObjRangeLimitMax;        /* Ego velocity dependent range limitation maximum for moving objects */

  float32 f_SpeedObjSync = *(pt_LAInput->t_RTE.pf_EgoVelObjSync);
#if (SLATE_CFG_USE_DRIVE_MODE)
  DriveMode_t_e t_edrivemode = *(pt_LAInput->t_RTE.pt_edrivemode);

  if(t_edrivemode == ECO)
  {
    /* Calculate ego-speed dependent pick-up range for moving objects without range reduction for eco mode*/
    f_MovingObjBasePickUpRange = f_SpeedObjSync * dGDBmathLineareFunktion( &t_LAMovingObjBasePickUpRangeParamEco, f_SpeedObjSync);
  }
  else
  {
    /* Calculate ego-speed dependent pick-up range for moving objects without range reduction for normal mode*/
    f_MovingObjBasePickUpRange = f_SpeedObjSync * dGDBmathLineareFunktion( &t_LAMovingObjBasePickUpRangeParam, f_SpeedObjSync);
  }
#else
  {
    /* Calculate ego-speed dependent pick-up range for moving objects without range reduction */
    f_MovingObjBasePickUpRange = f_SpeedObjSync * dGDBmathLineareFunktion( &t_LAMovingObjBasePickUpRangeParam, f_SpeedObjSync);
  }
#endif /* (SLATE_CFG_USE_DRIVE_MODE) */
  
  
  /* Calculate ego-speed dependent minimum pick-up range for moving objects without range reduction */
  f_MovingObjRangeLimitMin = f_SpeedObjSync * LA_ACC_RANGE_TIMEGAP_MIN_MOVING;

  /* Calculate ego-speed dependent pick-up range for moving objects with range reduction */
  f_MovingObjReducedPickUpRange = ( ((1.f - pt_LAOutput->fRangeFac) * f_MovingObjBasePickUpRange) + (pt_LAOutput->fRangeFac * f_MovingObjRangeLimitMin) );

  /* ACC range has to be below maximum given by 
     1. a first maximum at lower ego velocities, 
     2. a general maximum at higher ego velocities and 
     3. a maximum control time-gap for ego velocities in the middle */
  f_MovingObjRangeLimitMax = MAX_FLOAT(LA_ACC_RANGE_MAX_LOWER_MOVING, (f_SpeedObjSync * LA_ACC_RANGE_MAX_TIMEGAP_MAX_MOVING));
  f_MovingObjRangeLimitMax = MIN_FLOAT(LA_ACC_RANGE_MAX_UPPER_MOVING, f_MovingObjRangeLimitMax);

  /* Apply range limitation */
  f_MovingObjBasePickUpRange    = MIN_FLOAT(f_MovingObjRangeLimitMax, f_MovingObjBasePickUpRange);
  f_MovingObjReducedPickUpRange = MIN_FLOAT(f_MovingObjRangeLimitMax, f_MovingObjReducedPickUpRange);

  /* ACC range has to be above maximum given by 
    1. a global minimum distance
    2. a global minimum control time-gap */
  f_MovingObjRangeLimitMin = MAX_FLOAT(f_MovingObjRangeLimitMin, LA_ACC_RANGE_MIN_MOVING);

  /* ACC range has to be above minimum for moving objects */
  f_MovingObjBasePickUpRange    = MAX_FLOAT(f_MovingObjRangeLimitMin, f_MovingObjBasePickUpRange);
  f_MovingObjReducedPickUpRange = MAX_FLOAT(f_MovingObjRangeLimitMin, f_MovingObjReducedPickUpRange);

  /* Store the results in global variable */
  pt_LAOutput->f_LAMovingObjBasePickUpRange = f_MovingObjBasePickUpRange;
  pt_LAOutput->f_LAMovingObjPickUpRange     = f_MovingObjReducedPickUpRange;
  pt_LAOutput->f_LAMovingObjRangeLimitMin   = f_MovingObjRangeLimitMin;
  pt_LAOutput->f_LAMovingObjRangeLimitMax   = f_MovingObjRangeLimitMax;

#if SLATE_CFG_USE_DRIVE_MODE
  pt_LAInput->t_FrameFreeze.pt_LA_DeviceInfo->t_edrivemode = t_edrivemode;
#endif

}

/*************************************************************************************************************************
  Functionname:    LA_b_CheckACCRangeCriteria_propertytype                                                            */ /*!

  @brief           Get if clause

  @description     Clause taken out of the code for cantata, as branch clause is unreachable, as already caught
                   with the clause before

		@startuml
		Start
		Partition LA_b_CheckACCRangeCriteria_propertytype {
		: Check clause is true;
		}
		End
		@enduml

  @return          boolean : if check clause is true [TRUE, FALSE]

  @param[in]       t_ObjNr : internal object number (Object ID) of a valid object [0 ... EM_N_OBJECTS[
                           with EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @param[out]      -

  @glob_in         OBJ_DYNAMIC_PROPERTY(i) : Dynamic property of object i [EM_t_ARS_DynamicProperty as defined in rte_type.h]
                            with i in [0 ... EM_N_OBJECTS[ and EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @glob_in         OBJ_IS_MOVING_TO_STATIONARY(i) : Info if object i is moving to stationary [TRUE, FALSE]
                            with i in [0 ... EM_N_OBJECTS[ and EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         -

  @author          Grant Davtjan | Grant.Davtjan@continental-corporation.com | +49-8382-9699-633
*************************************************************************************************************************/
static boolean LA_b_CheckACCRangeCriteria_propertytype(ObjNumber_t t_ObjNr)
{
  SLATE_t_Obj_DynamicProperty t_ObjDynProperty = *SLATE_pt_GetObjDynProperty(t_ObjNr);
  boolean b_ObjIsMovingToStationary = SLATE_b_GetObjIsMovingToStationary(t_ObjNr);
return(boolean)( (t_ObjDynProperty == SLATE_OBJECT_PROPERTY_MOVING) 
#if (FCT_CFG_SENSOR_TYPE_RADAR)
     || ((t_ObjDynProperty == SLATE_OBJECT_PROPERTY_STATIONARY) && (b_ObjIsMovingToStationary))
#else /* !FCT_CFG_SENSOR_TYPE_RADAR */
     || (b_ObjIsMovingToStationary)
#endif /* !FCT_CFG_SENSOR_TYPE_RADAR */
      );
}

/*************************************************************************************************************************
  Functionname:    LA_b_GetSitRangeRedFlag                                                            */ /*!

  @brief           Get situation specific range reduction flag

  @description     Check flag if a situation specific range reduction criteria is fulfilled.

		@startuml
		Start
		Partition LA_b_GetSitRangeRedFlag {
		Partition FCT_CFG_SIGNAL_PERF_MONITORING {
		: Set Absolute Ego Curve Raw;
		If (Check if Tunnel Probability > Threshold value and Absolute Ego Curve Raw > LA_ACC_RANGE_RED_TUNNEL_CURVE_THRES and Object is not OOI) then (yes)
			: Get situation specific range reduction flag;
		Endif
		}
		Partition LA_CFG_NARROW_HIGHWAY_CRITERIA {
		: Checks if object will likely generate a false positive event on a narrow highway e.g. the Brenner highway;
		If (Check if Brenner Highway Criteria) then (yes)
			: Get situation specific range reduction flag;
		Endif
		}
		}
		End
		@enduml

  @return          boolean : if range reduction criteria fulfilled [TRUE, FALSE]

  @param[in]       t_ObjNr : internal object number (Object ID) of a valid object [0 ... EM_N_OBJECTS[
                           with EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h

  @glob_in         EGO_CURVE_OBJ_SYNC : Ego curve [-1.f ... 1.f] 1/m
  @glob_in         t_OOI_ObjectList[i].t_Bool.AlreadyOOI : information if object i is already OOI selected [TRUE, FALSE]
                          with i in [0 ... EM_N_OBJECTS[ and EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @glob_in         TUNNEL_PROBABILITY : Probability for a tunnel [0.0f ... 1.0f]
  @glob_out        -

  @c_switch_part   LA_CFG_NARROW_HIGHWAY_CRITERIA : LA switch for narrow highway criteria check
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).
  
  @traceability    242:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-242-00061542 \n
                   228:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-228-00061542 \n
                   243:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-243-00061542 \n
                   

  @created         -
  @changed         -

  @author          Grant Davtjan | Grant.Davtjan@continental-corporation.com | +49-8382-9699-633
*************************************************************************************************************************/
static boolean LA_b_GetSitRangeRedFlag(ObjNumber_t t_ObjNr)
{
  boolean b_RangeRedCrit = FALSE;

#if (LA_CFG_NARROW_HIGHWAY_CRITERIA)
  boolean b_NarrowHighwayCriteria; /* Flag for narrow highway criteria */ 
#endif

#if (FCT_CFG_SIGNAL_PERF_MONITORING)
  float32 f_ABS_EgoCurveRaw; /* For the calculation of  ABS value */
  f_ABS_EgoCurveRaw = fABS(*pt_LAInput->t_RTE.pf_EgoCurveRaw);
  /* Range reduction in curvy tunnels for non-OOI objects */
  if ( (*pt_LAInput->t_RTE.pf_TunnelProbability > LA_TUNNEL_PROB_THRES)
    && (f_ABS_EgoCurveRaw > LA_ACC_RANGE_RED_TUNNEL_CURVE_THRES)
    && (t_OOI_ObjectList[t_ObjNr].t_Bool.AlreadyOOI != (ubit16_t)1)
     )
  {
    b_RangeRedCrit = TRUE;
  }
#endif

#if (LA_CFG_NARROW_HIGHWAY_CRITERIA)
  b_NarrowHighwayCriteria = LA_b_CheckNarrowHighwayCriteria(t_ObjNr);
  if (b_NarrowHighwayCriteria == FALSE)
  {
    b_RangeRedCrit = TRUE;
  }
#endif

#if ( (FCT_CFG_SIGNAL_PERF_MONITORING == SWITCH_OFF) && (LA_CFG_NARROW_HIGHWAY_CRITERIA == SWITCH_OFF) )
  _PARAM_UNUSED(t_ObjNr);
#endif

  return b_RangeRedCrit;
}

/*************************************************************************************************************************
  Functionname:    LA_b_GetSitRangeExtFlag                                                            */ /*!

  @brief           Get situation specific range extension flag

  @description     Check flag if a situation specific range extension criteria is fulfilled.

		@startuml
		Start
		Partition LA_b_GetSitRangeExtFlag {
		Partition FCT_CFG_ROAD_INPUT {
		: Get Object Longitudinal Displacement;
		: Get road estimation fusion state;
		If (Check if Range extension when road fusion available) then (yes)
			If (Ego Velocity Object Sync > LA_ACC_RANGE_EXT_RD_FUS_CRIT_VEGO_MAX) then (yes)
				: Get situation specific range extension flag;
			Else if (if range of confident road estimation is above object distance)then (yes)
				: Get situation specific range extension flag;
			Else (no)
				: Do Nothing;
			Endif
		Endif
		}
		Partition FCT_CFG_CURVATURE_CHANGE_COMPUTATION {
		: Check distance to high curvature change (curve entry/exit) criteria;
		If (Check if distance to high curvature change criteria is False) then (yes)
			: Don’t get situation specific range extension flag;
		Endif
		}
		}
		End
		@enduml

  @return          boolean : if range extension criteria fulfilled [TRUE, FALSE]

  @param[in]       t_ObjNr : internal object number (Object ID) of a valid object [0 ... EM_N_OBJECTS[
                           with EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h

  @glob_in         EGO_SPEED_X_OBJ_SYNC : Ego velocity provided by VDY [-330.f ... 330.f] m/s
  @glob_in         *SLATE_pf_GetObjLongDisp(i) : Longitudinal distance of object i [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                            with i in [0 ... EM_N_OBJECTS[ and EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @glob_in         pt_LAInput->pt_FIPRoad->t_FIPRoadEstimation.fmaxXLeftCompensated : Distance up to which road estimation on left side is available [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @glob_in         pt_LAInput->pt_FIPRoad->t_FIPRoadEstimation.fmaxXRightCompensated :  Distance up to which road estimation on right side is available [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @glob_out        -

  @c_switch_part   FCT_CFG_ROAD_INPUT : road estimation input to FCT
  @c_switch_part   FCT_CFG_CURVATURE_CHANGE_COMPUTATION : FCT support for Curvature Change Computation in FIP
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).
  
  @traceability    228:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-228-00061542 \n

  @created         -
  @changed         -

  @author          Grant Davtjan | Grant.Davtjan@continental-corporation.com | +49-8382-9699-633
*************************************************************************************************************************/
static boolean LA_b_GetSitRangeExtFlag(ObjNumber_t t_ObjNr)
{
  boolean b_RangeExtCrit = FALSE;

#if (FCT_CFG_CURVATURE_CHANGE_COMPUTATION)
  boolean b_DistToHighCCCriteria; /* Flag for distance to high curvature change criteria */ 
#endif

#if (FCT_CFG_ROAD_INPUT)
  /* Road estimation fusion state */
  ubit16_t t_FusionRoadstimation;
  float32 f_ObjLongDisp = *SLATE_pf_GetObjLongDisp(t_ObjNr);

  /* Get road estimation fusion state */
  t_FusionRoadstimation = pt_LAInput->t_CP.pt_TrajectoryData->State.FusionRoadstimation;

  /* Range extension when road fusion available */
  if (t_FusionRoadstimation == TRUE)
  {
     /* For high velocities range of confident road estimation is irrelevant */
    if (*pt_LAInput->t_RTE.pf_EgoVelObjSync > LA_ACC_RANGE_EXT_RD_FUS_CRIT_VEGO_MAX)
    {
      b_RangeExtCrit = TRUE;
    }
    /* Range extension if range of confident road estimation is above object distance */
    else if ( ((pt_LAInput->pt_FIPRoad->t_FIPRoadEstimation.fmaxXLeftCompensated) > f_ObjLongDisp)
           && ((pt_LAInput->pt_FIPRoad->t_FIPRoadEstimation.fmaxXRightCompensated) > f_ObjLongDisp)
            )
    {
      b_RangeExtCrit = TRUE;
    }
    /* No range extension even if road fusion is active */
    else
    {
    }
  }
#endif /* (FCT_CFG_ROAD_INPUT) */

#if (FCT_CFG_CURVATURE_CHANGE_COMPUTATION)
  /* Check distance to high curvature change (curve entry/exit) criteria */
  b_DistToHighCCCriteria = LA_b_CheckObjDistToCCCriteria(t_ObjNr);
  if (b_DistToHighCCCriteria == FALSE)
  {
    b_RangeExtCrit = FALSE;
  }
#endif

#if ( (FCT_CFG_ROAD_INPUT == SWITCH_OFF) && (FCT_CFG_CURVATURE_CHANGE_COMPUTATION == SWITCH_OFF) )
  _PARAM_UNUSED(t_ObjNr);
#endif

  return b_RangeExtCrit;
}

/*************************************************************************************************************************
  Functionname:    LA_f_ComputeVrelDepPickUpRange                                                            */ /*!

  @brief           Get vrel dependent pick-up range based on one of two parameter sets of a
                   kinematic model.

  @description     Returns vrel dependent pick-up range based on one of two parameter sets of a
                   kinematic model. The first model is a minimum range needed for an ACC approach. 
                   The second model is a comfortable one. Pick-up range is sum of 1. distance driven 
                   due to delay 2. distance driven with engaged deceleration 3. final distance 
                   according to distance level (time-gap).

		@startuml
		Start
		Partition LA_f_ComputeVrelDepPickUpRange {
		: Get object relative velocity;
		: Get ego velocity;
		: Compute range with consideration of ego acceleration;
		If (ego acceleration < LA_VREL_RANGE_EGO_ACCEL_MIN) then (yes)
			: Set Ego Acceleration as 0;
		Endif
		If (Check if Kinematic Model is LA_VREL_RANGE_MOD_MIN) then (yes)
			: Set maximum jerk for deceleration according to motion model as LA_VREL_RANGE_JERK_MAX;
		: Set maximum deceleration according to motion model as LA_VREL_RANGE_DECEL_MAX;
		: Set control delay according to motion model as LA_VREL_RANGE_DELAY;
		: Set final time-gap according to motion model for kinematic model as LA_VREL_RANGE_TIMEGAP;
		Else (no)
			: Set maximum jerk for deceleration according to motion model as LA_VREL_RANGE_JERK_MAX_COMF;
		: Set maximum deceleration according to motion model as LA_VREL_RANGE_DECEL_MAX_COMF;
		: Set control delay according to motion model as LA_VREL_RANGE_DELAY_COMF;
		: Set final time-gap according to motion model for kinematic model as LA_VREL_RANGE_TIMEGAP_COMF;
		Endif
		: Compute final distance according to selected distance level (time-gap);
		: Compute relative velocity of object after delay;
		If (velocity relevant object delayed < LA_VREL_RANGE_OBJ_VREL_MAX) then (yes)
			: Compute distance driven with delay i.e. without controller engagement;
			: Compute distance driven with controller engaged deceleration;
			: Compute time to reach maximum deceleration;
			: Compute distance driven with controller engaged deceleration before maximum deceleration reached;
			: Compute relative velocity of object when maximum deceleration reached;
			: Compute distance driven with controller engaged deceleration after maximum deceleration reached;
			: Pick-up range is sum of above computed distances;
		Else (no)
			: Set relative velocity dependent pick-up range is the sum of three distances;
		Endif
		}
		End
		@enduml

  @return          f_dist_sum : vrel dependent pick-up distance for moving object [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m

  @param[in]       t_ObjNr : internal object number (Object ID) of a valid object [0 ... EM_N_OBJECTS[
                            with EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @param[in]       t_KinModel : switch between different parameter sets of the kinematic model
                            according to which range is computed [LA_VrelRangeModKinModel_t]
  @param[out]      -

  @glob_in         EGO_SPEED_X_OBJ_SYNC : Ego velocity provided by VDY [-330.f ... 330.f] m/s
  @glob_in         EGO_ACCEL_X_OBJ_SYNC : ego acceleration             [-100.f ... 100.f] m/s^2
  @glob_in         OBJ_LONG_VREL(i) : Relative velocity of object i    [-330.f ... 330.f] m/s
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @traceability    204:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-204-00061542 \n
                   205:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-205-00061542 \n

  @created         -
  @changed         -

  @author          Grant Davtjan | Grant.Davtjan@continental-corporation.com | +49-8382-9699-633
*************************************************************************************************************************/
static float32 LA_f_ComputeVrelDepPickUpRange(ObjNumber_t t_ObjNr, LA_VrelRangeModKinModel_t t_KinModel)
{
  float32 f_v_ego;                 /* current ego velocity */
  float32 f_a_ego;                 /* current ego acceleration */
  float32 f_vrel_obj;              /* current object relative velocity */

  float32 f_j_max;                 /* maximum jerk for deceleration according to motion model */
  float32 f_a_max;                 /* maximum deceleration according to motion model */
  float32 f_t_delay;               /* control delay according to motion model */
  float32 f_t_timegap;             /* final time-gap according to motion model */
  
  float32 f_t_start_decel;         /* time until maximum deceleration is reached */
  float32 f_t_start_decel_2;       /* square of time until maximum deceleration is reached */
  float32 f_vrel_obj_delayed;      /* object relative velocity after delay */
  float32 f_vrel_obj_at_max_decel; /* object relative velocity when maximum deceleration reached */
  
  float32 f_dist_delay;            /* distance driven with delay i.e. without controller engagement */
  float32 f_dist_decel_up_to_max;  /* distance driven with controller engaged deceleration before maximum deceleration reached */
  float32 f_dist_decel_with_max;   /* distance driven with controller engaged deceleration after maximum deceleration reached */
  float32 f_dist_final;            /* final distance according to selected distance level (time-gap) */
  float32 f_dist_sum;              /* relative velocity dependent pick-up range is the sum of three distances */

  /* Get object relative velocity */
  f_vrel_obj = *pt_LAInput->t_RTE.pf_ObjVrelX(t_ObjNr);

  /* Get ego velocity */
  f_v_ego = *pt_LAInput->t_RTE.pf_EgoVelObjSync;

  /* Compute range with consideration of ego acceleration */
  f_a_ego = *pt_LAInput->t_RTE.pf_EgoAccObjSync;

  /* Consider ego acceleration only when accelerating */
  if (f_a_ego < LA_VREL_RANGE_EGO_ACCEL_MIN)
  {
    f_a_ego = 0.0f;
  }

  /* Choose parameter set for kinematic model */
  if ( t_KinModel == LA_VREL_RANGE_MOD_MIN )
  {
    f_j_max     = LA_VREL_RANGE_JERK_MAX;
    f_a_max     = LA_VREL_RANGE_DECEL_MAX;
    f_t_delay   = LA_VREL_RANGE_DELAY;
    f_t_timegap = LA_VREL_RANGE_TIMEGAP;
  }
  else /* t_KinModel is LA_VREL_RANGE_MOD_COMF */
  {
    f_j_max     = LA_VREL_RANGE_JERK_MAX_COMF;
    f_a_max     = LA_VREL_RANGE_DECEL_MAX_COMF;
    f_t_delay   = LA_VREL_RANGE_DELAY_COMF;
    f_t_timegap = LA_VREL_RANGE_TIMEGAP_COMF;
  }

  /* Compute final distance according to selected distance level (time-gap) */
  f_dist_final = ( f_vrel_obj + f_v_ego) * f_t_timegap;

  /* Compute relative velocity of object after delay */
  f_vrel_obj_delayed = f_vrel_obj - (f_a_ego * f_t_delay);

  /* Compute vrel dependent range only for objects moving significantly slower than ego */
  if (f_vrel_obj_delayed < LA_VREL_RANGE_OBJ_VREL_MAX)
  {
    /* Compute distance driven with delay i.e. without controller engagement */
    f_dist_delay = (-1.f * f_vrel_obj * f_t_delay) + (0.5f * f_a_ego * SQR(f_t_delay));

    /* Compute distance driven with controller engaged deceleration */
    /* Compute time to reach maximum deceleration */
    f_t_start_decel         = (f_a_max - f_a_ego) / f_j_max;
    f_t_start_decel_2       = SQR(f_t_start_decel );
    /* Compute distance driven with controller engaged deceleration before maximum deceleration reached */
    f_dist_decel_up_to_max  = (-1.f * f_vrel_obj_delayed * f_t_start_decel ) + (0.5f * f_a_ego * f_t_start_decel_2);
    f_dist_decel_up_to_max += ( f_j_max * f_t_start_decel * f_t_start_decel_2 * C_SIXTH);
    /* Compute relative velocity of object when maximum deceleration reached */
    f_vrel_obj_at_max_decel = f_vrel_obj_delayed - (f_a_ego * f_t_start_decel ) - (0.5f * f_j_max * f_t_start_decel_2);
    /* Compute distance driven with controller engaged deceleration after maximum deceleration reached */
    f_dist_decel_with_max   = (-0.5f * SQR(f_vrel_obj_at_max_decel)) / (f_a_max);

    /* Pick-up range is sum of above computed distances */
    f_dist_sum = f_dist_delay + f_dist_decel_up_to_max + f_dist_decel_with_max + f_dist_final;
  }
  else
  {
    /* For positive or close to positive vrel set vrel dependent pick-up range to final distance according to selected distance level (time-gap) */
    f_dist_sum = f_dist_final;
  }

  return f_dist_sum;
}

/*************************************************************************************************************************
  Functionname:    LA_f_GetACCRangeForStationary                                                            */ /*!

  @brief           Get ACC range of stationary object for functional pre-selection

  @description     Returns ACC range for the stationary object ID passed as parameter.

		@startuml
		Start
		Partition LA_f_GetACCRangeForStationary {
		If (check if Object is already selected as OOI) then (yes)
			: Set OOI Dependent Range Addend;
			: Set Maximum Distance;
		Endif
		: Update Maximum Distance;
		If (Ego Yaw Rate Quality <= LA_VDY_YAWRATE_QUAL_SENSOR_UNLEARNED) then (yes)
			: Update Maximum Distance;
		Endif
		}
		End
		@enduml

  @return          f_DistMax : ACC range for oncoming object [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m

  @param[in]       t_ObjNr : internal object number (Object ID) of a valid object [0 ... EM_N_OBJECTS[
                           with EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @param[out]      -

  @glob_in         pt_LAOutput->fRangeFac : factor used for curvature depedant range reduction [0.0f ... 1.0f]
  @glob_in         t_OOI_ObjectList[i].t_Bool.AlreadyOOI : information if object i is already OOI selected [TRUE, FALSE]
                          with i in [0 ... EM_N_OBJECTS[ and EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @glob_in         EGO_YAW_RATE_QUALITY_RAW :  Quality of yaw rate provided by VDY [Quality_t as in Rte_Type.h]
  @glob_in         EGO_SPEED_X_OBJ_SYNC : Ego velocity provided by VDY [-330.f ... 330.f] m/s
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).
  
  @traceability    209:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-209-00061542
                   208:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-208-00061542

  @created         -
  @changed         -

  @author          Grant Davtjan | Grant.Davtjan@continental-corporation.com | +49-8382-9699-633
*************************************************************************************************************************/
static float32 LA_f_GetACCRangeForStationary(ObjNumber_t t_ObjNr)
{
  float32 f_OOIDependentRangeAddend;
  float32 f_DistMax = (LA_ACC_RANGE_MAX_STATIONARY);

  /* Set Hysteresis for dropping OOIs */
  /* @todo only relevant when driving backwards or when object is moving slowly (e.G. pedestrians). remove fRangeFac dependency */    
  if (t_OOI_ObjectList[t_ObjNr].t_Bool.AlreadyOOI  == (ubit16_t)1)
  {
    f_OOIDependentRangeAddend = MAX_FLOAT( LA_ACC_RANGE_HYSTERESIS_MIN_STATIONARY , LA_ACC_RANGE_HYSTERESIS_STATIONARY*(1.0f - pt_LAOutput->fRangeFac) );
    f_DistMax += f_OOIDependentRangeAddend;
  }

  f_DistMax = MIN_FLOAT(f_DistMax, (*pt_LAInput->t_RTE.pf_EgoVelObjSync * LA_ACC_RANGE_TIMEGAP_MAX_STATIONARY));
  f_DistMax = MAX_FLOAT(f_DistMax, LA_ACC_RANGE_MIN_STATIONARY);

  /* reduce maximum ACC range for stationary objects, if sensor is unlearned (steering angle offset) */
  if(pt_LAInput->t_RTE.f_EgoYawRateQuality <= LA_VDY_YAWRATE_QUAL_SENSOR_UNLEARNED)
  {
    f_DistMax = MIN_FLOAT(f_DistMax, LA_ACC_RANGE_MAX_UNLEARNED_SENSOR_STATIONARY);
  }

  return f_DistMax;
}

/*************************************************************************************************************************
  Functionname:    LA_f_GetACCRangeForMoving                                                            */ /*!

  @brief           Get ACC range of moving object for functional pre-selection

  @description     Returns the ACC range for the moving object ID passed as parameter. The ACC range consist of the ACC pick-up 
                   range plus an additional OOI-dependent hysteresis. The ACC pick-up range consists of three components. First, 
                   an ego velocity dependent range (computed in LA_v_SetMovingObjBasePickUpRange). Second, an object relative 
                   velocity dependent range. The object relative velocity dependent range is based on a kinematic model. Dependent 
                   on the situation it is computed either for a minimum ACC pick-up range or a comfort ACC pick-up range. 
                   Third, a minimum and maximum range independent of velocity. An OOI-specific hysteresis and the general range 
                   limitation of the ACC range are applied at the end of the function.

		@startuml
		Start
		Partition LA_f_GetACCRangeForMoving {
		: Get the situation specific range criteria flags;
		If (Check if Object Longitudinal relevant Velocity > LA_ACC_RANGE_POS_VREL_THRES or Range reduction situation) then (yes)
			: Update Time Gap Dependent Pick Up Range with LA Moving Object Minimum Range Limit;
		Else (no)
			: Update Time Gap Dependent Pick Up Range with LA Moving Object Pick Up Range;
		Endif
		If (Check If Range reduction flag is FALSE and range extension flag TRUE)
			: Compute ACC comfort pick-up range according to kinematic model;
		Else (no)
			: Compute ACC minimum pick-up range according to kinematic model;
		Endif
		: Set pick-up range to maximum of time-gap dependent range and relative velocity dependent range;
		: Get object specific hysteresis of ACC range;
		: Add hysteresis value to the object specific pick-up range;
		: Apply range limitation;
		}
		End
		@enduml

  @return          f_DistMax : ACC range for moving object [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m

  @param[in]       t_ObjNr : internal object number (Object ID) of a valid object [0 ... EM_N_OBJECTS[
                           with EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @param[out]      -

  @glob_in         pt_LAOutput->fRangeFac : factor used for curvature depedant range reduction [0.0f ... 1.0f]
  @glob_in         pt_LAOutput->f_LAMovingObjPickUpRange : base pick up range for moving objects with range reduction [fDistance_t as defined in rte_type.h]
  @glob_in         pt_LAOutput->f_LAMovingObjRangeLimitMin : the ego velocity dependent range limitation minimum for moving objects [fDistance_t as defined in rte_type.h]
  @glob_in         pt_LAOutput->f_LAMovingObjRangeLimitMax : the ego velocity dependent range limitation maximum for moving objects [fDistance_t as defined in rte_type.h]
  @glob_in         EGO_SPEED_X_OBJ_SYNC : Ego velocity provided by VDY [-330.f ... 330.f] m/s

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component

  @pre             pt_LAOutput->f_LAMovingObjPickUpRange contains the current base pickup range with range reduction for moving objects
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @traceability    210:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-210-00061542 \n
                   274:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-274-00061542 \n
                   204:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-204-00061542 \n 
                   205:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-205-00061542 \n 

  @created         -
  @changed         -

  @author          Grant Davtjan | Grant.Davtjan@continental-corporation.com | +49-8382-9699-633
*************************************************************************************************************************/
static float32 LA_f_GetACCRangeForMoving(ObjNumber_t t_ObjNr)
{
  float32 f_MovObjPickUpRangeLocal;
  float32 f_VrelDepPickUpRange;
  float32 f_TimeGapDepPickUpRange;
  float32 f_OOIDependentRangeAddend;
  float32 f_vrelx_obj;
  boolean b_SitRangeExt = FALSE;
  boolean b_SitRangeRed = FALSE;

  /* Get the situation specific range criteria flags */
  b_SitRangeRed = LA_b_GetSitRangeRedFlag(t_ObjNr);
  b_SitRangeExt = LA_b_GetSitRangeExtFlag(t_ObjNr);

  /* In case of a receding object
     or a range reduction situation
     decrease the time-gap dependent pick-up range to avoid drop-ins and drop-outs */

  f_vrelx_obj = *pt_LAInput->t_RTE.pf_ObjVrelX(t_ObjNr);
  if ( (f_vrelx_obj > LA_ACC_RANGE_POS_VREL_THRES)
    || (b_SitRangeRed == TRUE) )
  {
    f_TimeGapDepPickUpRange = pt_LAOutput->f_LAMovingObjRangeLimitMin;
  }
  else
  {
    f_TimeGapDepPickUpRange = pt_LAOutput->f_LAMovingObjPickUpRange;
  }

  /* Range extension only possible when reduction flag is FALSE and range extension flag TRUE */
  if ( (b_SitRangeRed == FALSE)
    && (b_SitRangeExt == TRUE) )
  {
    /* Compute ACC comfort pick-up range according to kinematic model */
    f_VrelDepPickUpRange = LA_f_ComputeVrelDepPickUpRange(t_ObjNr, LA_VREL_RANGE_MOD_COMF);
  }
  else
  {
    /* Compute ACC minimum pick-up range according to kinematic model */
    f_VrelDepPickUpRange = LA_f_ComputeVrelDepPickUpRange(t_ObjNr, LA_VREL_RANGE_MOD_MIN);
  }

  /* Set pick-up range to maximum of time-gap dependent range and relative velocity dependent range */
  f_MovObjPickUpRangeLocal = MAX_FLOAT(f_TimeGapDepPickUpRange, f_VrelDepPickUpRange);

  /* Get object specific hysteresis of ACC range */
  f_OOIDependentRangeAddend = LA_f_GetMovObjRangeHysteresis(t_ObjNr, pt_LAOutput->fRangeFac);
  
  /* Add hysteresis value to the object specific pick-up range */
  f_MovObjPickUpRangeLocal += f_OOIDependentRangeAddend;

  /* Apply range limitation */
  f_MovObjPickUpRangeLocal = MIN_FLOAT(pt_LAOutput->f_LAMovingObjRangeLimitMax, f_MovObjPickUpRangeLocal);

  return f_MovObjPickUpRangeLocal;
}

/*************************************************************************************************************************
  Functionname:    LA_f_GetMovObjRangeHysteresis                                                            */ /*!

  @brief           Get hysteresis of ACC range of moving object for functional pre-selection

  @description     Returns hysteresis of ACC range for the moving object ID passed as parameter.

		@startuml
		Start
		Partition LA_f_GetMovObjRangeHysteresis {
		If (if object is already OOI selected) then (yes)
			If (Object Longitudinal Velocity < 0) then (yes)
				: Set OOI Dependent Range Addend as LA_ACC_RANGE_HYSTERESIS_HIGH_MOVING;
			Else (no)
				If (Check if Object is not in OOI List and Longitudinal Displacement > LA Moving Object Min Range Limit and Object relevant Longitudinal velocity > its Threshold) then (yes)
					: Set OOI Dependent Range Addend as 0;
				Else (no)
					: Set OOI Dependent Range Addend as Lower hysteresis distance of OOI for positive relative velocities;
				Endif
			Endif
		Else (no)
			: No Hysteresis if object is not OOI;
		Endif
		}
		End
		@enduml

  @return          f_OOIDependentRangeAddend : ACC range hysteresis for moving object [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m

  @param[in]       t_ObjNr : internal object number (Object ID) of a valid object [0 ... EM_N_OBJECTS[
                           with EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @param[in]       f_RangeFacLocal : object specific and situation dependent local range factor [0.f ... 1.f]
  @param[out]      -


  @glob_in         OBJ_LONG_VREL(i) : Relative velocity of object i [-330.f ... 330.f] m/s
                            with i in [0 ... EM_N_OBJECTS[ and EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @glob_in         t_OOI_ObjectList[i].t_Bool.AlreadyOOI : information if object i is already OOI selected [TRUE, FALSE]
                            with i in [0 ... EM_N_OBJECTS[ and EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @glob_in         OBJ_GET_OOI_LIST_OBJ_IDX(i) : object number of object of interest [0 ... EM_N_OBJECTS[
                            with i in [0 ... 6[ as defined in aiOOIList_array_t in Rte_Type.h
  @glob_in         pt_LAOutput->f_LAMovingObjBasePickUpRange : base pick up range for moving objects without range reduction [fDistance_t as defined in rte_type.h]

  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component

  @pre             pt_LAOutput->f_LAMovingObjRangeLimitMin computed in LA_v_SetMovingObjBasePickUpRange()
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @traceability    237:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-237-00061542 \n
                   275:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-275-00061542 \n
                   276:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-276-00061542 \n

  @created         -
  @changed         -

  @author          Grant Davtjan | Grant.Davtjan@continental-corporation.com | +49-8382-9699-633
*************************************************************************************************************************/
static float32 LA_f_GetMovObjRangeHysteresis(ObjNumber_t t_ObjNr, float32 f_RangeFacLocal)
{
  float32 f_OOIDependentRangeAddend;
  const float32 f_LongDisp = *pt_LAInput->t_RTE.pf_ObjLongDisp(t_ObjNr);
  const float32 f_ObjVrelX = *pt_LAInput->t_RTE.pf_ObjVrelX(t_ObjNr);

  /* Set Hysteresis for dropping OOIs */
  if (t_OOI_ObjectList[t_ObjNr].t_Bool.AlreadyOOI == (ubit16_t)1)
  {
    if (f_ObjVrelX < 0.F )
    {
      /* Higher hysteresis distance of OOI for negative relative velocities to avoid drop-outs in approach scenarios */
      f_OOIDependentRangeAddend = LA_ACC_RANGE_HYSTERESIS_HIGH_MOVING;
    }
    else
    {
      /* Set Hysteresis for dropping receding OOIs on neighboring lane and above minimum ego velocity dependent pick-up range */
      if ( (t_ObjNr != OBJ_GET_OOI_LIST_OBJ_IDX(OBJ_NEXT_OOI))
        && (f_LongDisp > pt_LAOutput->f_LAMovingObjRangeLimitMin)
        && (f_ObjVrelX > LA_ACC_RANGE_POS_VREL_THRES)
         )
      {
        f_OOIDependentRangeAddend = 0.f;
      }
      else
      {
        /* Lower hysteresis distance of OOI for positive relative velocities */
        f_OOIDependentRangeAddend = MAX_FLOAT( LA_ACC_RANGE_HYSTERESIS_MIN_MOVING , LA_ACC_RANGE_HYSTERESIS_MOVING*(1.0f - f_RangeFacLocal) );
      }
    }
  }
  else
  {
    /* No Hysteresis if object is not OOI */
    f_OOIDependentRangeAddend = 0.f;
  }

  return f_OOIDependentRangeAddend;
}

/*************************************************************************************************************************
  Functionname:    LA_f_GetACCRangeForOncoming                                                            */ /*!

  @brief           Get ACC range of oncoming object for functional pre-selection

  @description     Returns ACC range for the oncoming object ID passed as parameter.

		@startuml
		Start
		Partition LA_f_GetACCRangeForOncoming {
		: Get Curvature;
		If (Absolute Curvature > 0.0001)
			: Calculate Radius;
		Else (no)
			: Set Radius as 10000;
		Endif
		: Update Maximum Distance On Coming;
		: Update ACC range for oncoming object;
		: Get ACC range of oncoming object for functional pre-selection;
		}
		End
		@enduml

  @return          f_DistMax : ACC range for oncoming object [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m

  @param[in]       t_ObjNr : internal object number (Object ID) of a valid object [0 ... EM_N_OBJECTS[
                           with EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @param[out]      -

  @glob_in         EGO_CURVE_OBJ_SYNC : Ego curve [-1.f ... 1.f] 1/m
  @glob_in         OBJ_LONG_VREL(i) : Relative velocity of object i [-330.f ... 330.f] m/s
                            with i in [0 ... EM_N_OBJECTS[ and EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @glob_out        -


  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         -

  @author          Grant Davtjan | Grant.Davtjan@continental-corporation.com | +49-8382-9699-633
*************************************************************************************************************************/
static float32 LA_f_GetACCRangeForOncoming(ObjNumber_t t_ObjNr)
{
  float32 f_DistMax;
  float32 f_temp;
  float32 f_MaxDistOncoming;
  float32 f_Radius;
  float32 f_Curve;
  float32 f_ABS_Curve;

  /* Reduce ACC range for oncoming objects */
  /* Get Curvature */
  f_Curve = *pt_LAInput->t_RTE.pf_EgoCurve;
  f_ABS_Curve = fABS(f_Curve);
  if(f_ABS_Curve > C_F32_DELTA)
  {
    f_Radius = fABS(1.0f/f_Curve);
  }
  else
  {
    f_Radius = 1.0f/C_F32_DELTA;
  }
  f_temp = MIN_FLOAT( (fABS(*pt_LAInput->t_RTE.pf_ObjVrelX(t_ObjNr)) * (LA_ACC_RANGE_TIMEGAP_ONCOMING) ), LA_ACC_RANGE_MAX_ONCOMING);
  f_MaxDistOncoming = LA_ACC_RANGE_TIMEGAP_ONCOMING * SQRT_(LA_ACC_RANGE_AY_MAX_ONCOMING*f_Radius);
  f_DistMax =  MIN_FLOAT(f_temp, f_MaxDistOncoming);

  /* If the target vehicle starts rolling back very slowly, it can get very-very small ranges! Workaround to keep object */
  f_DistMax = MAX_FLOAT(FIP_PAR_ONCOMMING_KEEP_RELEV_DISTX_MAX, f_DistMax);

  return f_DistMax;
}

/*************************************************************************************************************************
  Functionname:    LA_b_CheckACCRangeCriteria                                                            */ /*!

  @brief           Check distance of object for functional pre-selection

  @description     Returns TRUE if distance selection criteria satisfied for the object ID passed as parameter. 
                   This basically requires that based on ego speed and other criteria the object be within a certain range.

		@startuml
		Start
		Partition LA_b_CheckACCRangeCriteria {
		If (if object is not deleted) then (yes)
			If (Object is stationary and if moving object is not stationary) then (yes)
				: Get ACC range of stationary object for functional pre-selection;
			Else if (if check clause is true) then (yes)
				: Get ACC range of moving object for functional pre-selection;
			Else if (Object is Oncoming) then (yes)
				: Get ACC range of oncoming object for functional pre-selection;
			Else (no)
				: Set ACC range as 0;
				Note Left: With current implementation this part shall not be reached
			Endif
		Else (no)
			: Set ACC range as 0;
			Note Left: Deleted object branch
		Endif
		: Set Limit Distance Max independent of the object's dynamic property to the maximal sensor range;
		: Save maximal distance;
		If (Object Longitudinal Displacement > 0 and Object Longitudinal Displacement < ACC range) then (yes)
			: ACC range criteria is satisfied;
		Else (no)
			: ACC range criteria is not satisfied;
		Endif
		}
		End
		@enduml

  @return          b_Ret : boolean if ACC range criteria is satisfied [TRUE, FALSE]

  @param[in]       t_ObjNr : internal object number (Object ID) of a valid object [0 ... EM_N_OBJECTS[
                           with EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @param[out]      -

  @glob_in         pt_LAInput->t_RTE.pf_ObjLongDisp(i) : Longitudinal distance of object i [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                            with i in [0 ... EM_N_OBJECTS[ and EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @glob_in         pt_LAInput->t_RTE.pt_ObjDynamicProperty(i) : Dynamic property of object i [EM_t_ARS_DynamicProperty as defined in rte_type.h]
                            with i in [0 ... EM_N_OBJECTS[ and EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @glob_in         SLATE_b_GetObjIsDeleted(i) : information if object is deleted [TRUE, FALSE]
                            with i in [0 ... EM_N_OBJECTS[ and EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @glob_in         SLATE_b_GetObjIsMovingToStationary(i) : Info if object i is moving to stationary [TRUE, FALSE]
                            with i in [0 ... EM_N_OBJECTS[ and EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @glob_out        pt_LAOutput->t_LAObjOutputList[i].ObjDependantMaxRange : object depedent maximum range of object i for display in simulation [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                            with i in [0 ... EM_N_OBJECTS[ and EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h

  @c_switch_part   FCT_SIMU : FCT simulation specific function switch
  @c_switch_part   FASTSIM : FASTSIM simulation specific function switch
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @traceability    209:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-209-00061542 \n
                   208:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-208-00061542 \n

  @created         -
  @changed         -

  @author          Grant Davtjan | Grant.Davtjan@continental-corporation.com | +49-8382-9699-633
*************************************************************************************************************************/
static boolean LA_b_CheckACCRangeCriteria(ObjNumber_t t_ObjNr)
{
  float32       f_DistMax;
  boolean       b_Ret;
  const float32 f_DistObj = *pt_LAInput->t_RTE.pf_ObjLongDisp(t_ObjNr);
  const SLATE_t_Obj_DynamicProperty t_ObjDynProperty = *pt_LAInput->t_RTE.pt_ObjDynamicProperty(t_ObjNr);
  const boolean b_ObjIsMovingToStationary = SLATE_b_GetObjIsMovingToStationary(t_ObjNr);
  const boolean b_Obj_IsDeleted = SLATE_b_GetObjIsDeleted(t_ObjNr);
  const boolean b_ACCRangeCriteria_propertytype = LA_b_CheckACCRangeCriteria_propertytype(t_ObjNr);

  if (!b_Obj_IsDeleted)
  {
    /* this part for ARS_OBJECT_PROPERTY_STATIONARY (subcategory STOPPED moved to moving) */
    if ((t_ObjDynProperty == SLATE_OBJECT_PROPERTY_STATIONARY) && (!b_ObjIsMovingToStationary))
    {
      f_DistMax = LA_f_GetACCRangeForStationary(t_ObjNr);
    }
    /* This part for ARS_OBJECT_PROPERTY_MOVING and subcategory STOPPED */
    else if (b_ACCRangeCriteria_propertytype == TRUE)
    {
      f_DistMax = LA_f_GetACCRangeForMoving(t_ObjNr);
    }
    /* this part for ARS_OBJECT_PROPERTY_ONCOMING */
    else if (t_ObjDynProperty == SLATE_OBJECT_PROPERTY_ONCOMING)
    {
      f_DistMax = LA_f_GetACCRangeForOncoming(t_ObjNr);
    }
    else
    {
      /* With current implementation this part shall not be reached */
      f_DistMax = (0.0f);
    }
  }
  else
  {
    /* Deleted object branch */
    f_DistMax = (0.0f);
  }

  /*! Limit DistMax independent of the object's dynamic property to the maximal sensor range RW_FCT_MAX */
  f_DistMax = MIN_FLOAT(f_DistMax, RW_FCT_MAX);
  
  /* Save maximal distance  */
    pt_LAOutput->t_LAObjOutputList[t_ObjNr].ObjDependantMaxRange = f_DistMax;
	
  /* Objects which are above the maximum longitudinal distance shall not be
     selected as OOI as the ACC trajectory, object position and object classification
     are unreliable in high distances. Furthermore object selection with a high time-gap
     value is not so important since there is enough reaction time. */
  if(   ( f_DistObj > 0.0f )
      &&( f_DistObj < f_DistMax )
    )
  {
    b_Ret = (TRUE);
  }
  else
  {
    b_Ret = (FALSE);
  }
  return b_Ret;
}
/* PRQA L:EMPTY_ELSE_OR_DEFAULT */
/** @} end defgroup */
#endif /* (FCT_CFG_ACC_LANE_ASSOCIATION) */

/* ************************************************************************* */
/*   Copyright ADC-GmbH, Lindau                                              */
/* ************************************************************************* */
