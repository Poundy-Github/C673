/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 SLATE_LA (Lane Association)

PACKAGENAME:               la_corridor.c

DESCRIPTION:               Main file for corridor module for initialization of corridor environment, 
                           calculation of ACC Corridor, Trace Brackets(Lane Width), Trace Bracket 
                           Adjustments and object relevancy for all objects individually

AUTHOR:                    Norman Apel / Fridolin Kolb

CREATION DATE:             06.08.2008

VERSION:                   $Revision: 1.28 $

LEGACY VERSION:            Revision: 2.1


**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/


#include "la.h"//PRQA S 0380
/* date: 2019-07-28, reviewer:Prabhu Sundaramurthy, reason: Arises due to inclusion of multiple header files in this header file which has multiple macros*/

#if (FCT_CFG_ACC_LANE_ASSOCIATION)
#include "la_corridor_crit.h"
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
@defgroup la_corridor LA Corridor
@ingroup la
@brief         This is the main file for initialization of corridor environment, 
               calculation of ACC Corridor, Trace Brackets(Lane Width), Trace Bracket 
               Adjustments and object relevancy for all objects individually. \n\n

@{

*/

/*****************************************************************************
  MACROS 
*****************************************************************************/


/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/

/*****************************************************************************
  (SYMBOLIC) CONSTANTS 
*****************************************************************************/

/*! Definition of the close Range [m] for special handling of stationary Objects */
#define LA_STAT_CLOSE_RANGE                          (10.0F)

/* Constants for reflection point correction */
#define LA_REF_CORR_FAC_MIN                    (0.0F)
#define LA_REF_CORR_FAC_MAX                    (1.0F)
#define LA_REF_CORR_MIN_ANGLE                  (7.0F)
#define LA_REF_CORR_MAX_ANGLE                  (20.0F)

#define LA_REF_CORR_MIN_LIFETIME               (15.F)
#define LA_REF_CORR_MAX_LIFETIME               (20.F)

#if LA_CFG_ADAPT_LANEWIDTH_BASED_ON_CAM
  /* Filter constant used for lowpass filtering camera based lane width */
  #define LA_CAM_LANE_FILTER_CONST (0.5f / SLATE_f_GetSITCycleTime()) //ToBeDiscussed
  /* Possible divide-by-0 condition because of SLATE_f_GetSITCycleTime: May have to be handled */
#endif

/*! Modes of trace bracket manipulation (used by SIRelTraSetLeftBracket and
SIRelTraSetRightBracket functions) */
typedef enum {
  DEFAULT_MODE,       /*!< Default mode: set to given value */
  RESTRICTION_MODE,   /*!< Trace bracket restrction mode: default init to left: -max right: +max,
                           when updating, take smaller of bracket values (restrict) */
  EXTENSION_MODE     /*!< Trace bracket extension mode: default init to left: +max right: -max, 
                           when updating, take greater of bracket values (extend existing) */
} LA_t_TraceBracketMode;

#if LA_DISABLED_FOR_TESTING_REMOVABILITY_OF_CURRENT_TARGET_FROM_FCT
#define LA_NOT_MEASURED_TARGET_LAT_DISP     (999.f) /*!< Default lateral displacement which indicates that object is not measured */
#endif

/* ramp for correcting the object reference point to its center at field of views edge */
SET_MEMSEC_CONST(ReflectionCorrectionAngleFactor)
static const GDBLFunction_t ReflectionCorrectionAngleFactor = { // PRQA S 3218
/* date: 2015-06-17, reviewer: Rachit Sharma (uidr5426), reason: static local for saving data across function calls */ 
  LA_REF_CORR_FAC_MIN,   /*!< A1 */
  LA_REF_CORR_FAC_MAX,   /*!< A2 */
  /*! (A2-A1)/(E2-E1) */
  /* <ln_offset:+1 PCLINT Error 835: reviewer name: Boll date: 22-06-2012 reason: LA_REF_CORR_FAC_MIN set to zero */
  ( LA_REF_CORR_FAC_MAX - LA_REF_CORR_FAC_MIN ) / ( LA_REF_CORR_MAX_ANGLE - LA_REF_CORR_MIN_ANGLE ),
  /*! A1 - (A2-A1)/(E2-E1) * E1 */
  /* <ln_offset:+1 PCLINT Error 835: reviewer name: Boll date: 22-06-2012 reason: LA_REF_CORR_FAC_MIN set to zero */
  LA_REF_CORR_FAC_MIN -( (( LA_REF_CORR_FAC_MAX - LA_REF_CORR_FAC_MIN ) / ( LA_REF_CORR_MAX_ANGLE - LA_REF_CORR_MIN_ANGLE )) * LA_REF_CORR_MIN_ANGLE )
};

/* ramp for correcting the object reference point to its center at field of views edge dependent on LifeTime*/
SET_MEMSEC_CONST(ReflectionCorrectionLifeFactor)
static const GDBLFunction_t ReflectionCorrectionLifeFactor = { // PRQA S 3218
/* date: 2015-06-17, reviewer: Rachit Sharma (uidr5426), reason: static local for saving data across function calls */ 
  LA_REF_CORR_FAC_MIN,   /*!< A1 */
  LA_REF_CORR_FAC_MAX,   /*!< A2 */
  /*! (A2-A1)/(E2-E1) */
  ( LA_REF_CORR_FAC_MIN - LA_REF_CORR_FAC_MAX ) / ( LA_REF_CORR_MAX_LIFETIME - LA_REF_CORR_MIN_LIFETIME ),
  /*! A1 - (A2-A1)/(E2-E1) * E1 */
  LA_REF_CORR_FAC_MAX -( (( LA_REF_CORR_FAC_MIN - LA_REF_CORR_FAC_MAX ) / ( LA_REF_CORR_MAX_LIFETIME - LA_REF_CORR_MIN_LIFETIME )) * LA_REF_CORR_MIN_ANGLE )
  /*!< Remark: Is LA_REF_CORR_MIN_LIFETIME instead of LA_REF_CORR_MIN_ANGLE correct? For keeping the same performance, this parameter is not changed */
};

SET_MEMSEC_CONST(TRCK_Seek_LaneWidth_SpeedAdapted)
static const GDBLFunction_t TRCK_Seek_LaneWidth_SpeedAdapted = {
  LA_HIGHWAYLANEWIDTHSEEK_MIN,/*!< A1 */
  LA_HIGHWAYLANEWIDTHSEEK_MAX,/*!< A2 */
  /*! (A2-A1)/(E2-E1) */
  ( LA_HIGHWAYLANEWIDTHSEEK_MAX - LA_HIGHWAYLANEWIDTHSEEK_MIN ) / ( LA_MAX_SPEED_HIGWAYLANEWIDTH - LA_MIN_SPEED_HIGWAYLANEWIDTH ),
  /*! A1 - (A2-A1)/(E2-E1) * E1 */
  LA_HIGHWAYLANEWIDTHSEEK_MIN
  -( (( LA_HIGHWAYLANEWIDTHSEEK_MAX - LA_HIGHWAYLANEWIDTHSEEK_MIN ) / ( LA_MAX_SPEED_HIGWAYLANEWIDTH - LA_MIN_SPEED_HIGWAYLANEWIDTH ))
  * LA_MIN_SPEED_HIGWAYLANEWIDTH )
};

SET_MEMSEC_CONST(TRCK_Track_Offset_SpeedAdapted)
static const GDBLFunction_t TRCK_Track_Offset_SpeedAdapted = { // PRQA S 3218
/* date: 2015-06-17, reviewer: Rachit Sharma (uidr5426), reason: static local for saving data across function calls */ 
  LA_HIGHWAYLANEWIDTH_TRCK_OFFSET_MAX,/*!< A1 */
  LA_HIGHWAYLANEWIDTH_TRCK_OFFSET_MIN,/*!< A2 */
  /*! (A2-A1)/(E2-E1) */
  ( LA_HIGHWAYLANEWIDTH_TRCK_OFFSET_MIN - LA_HIGHWAYLANEWIDTH_TRCK_OFFSET_MAX ) / ( LA_MAX_SPEED_HIGWAYLANEWIDTH - LA_MIN_SPEED_HIGWAYLANEWIDTH ),
  /*! A1 - (A2-A1)/(E2-E1) * E1 */
  LA_HIGHWAYLANEWIDTH_TRCK_OFFSET_MAX
  -( (( LA_HIGHWAYLANEWIDTH_TRCK_OFFSET_MIN - LA_HIGHWAYLANEWIDTH_TRCK_OFFSET_MAX ) / ( LA_MAX_SPEED_HIGWAYLANEWIDTH - LA_MIN_SPEED_HIGWAYLANEWIDTH ))
  * LA_MIN_SPEED_HIGWAYLANEWIDTH )
};


/*****************************************************************************
  VARIABLES 
*****************************************************************************/
#if ((LA_CFG_ADAPT_LANEWIDTH_BASED_ON_CAM) && (FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING))
SET_MEMSEC_VAR(fLastCycleCamLaneWidth)
/*! Camera lane width value for previous cycle */
static float32 fLastCycleCamLaneWidth = LA_STANDARDLANEWIDTHSEEK;//PRQA S 3218
/*date: 2018-07-31, reviewer: Midhun Easo Daniel, reason: static local for saving data across function calls*/
#endif
#ifdef FCT_SIMU
/*! Global variable for easier debugging */
SET_MEMSEC_VAR(LAAssTraEnvironment)
static LA_t_AssTraEnvironment    LAAssTraEnvironment;
#endif

/* Array to hold bracket positions of EM_N_OBJECTS objects whch is used in 
   Shape Point based calculation.*/
SET_MEMSEC_VAR(a_BracketPositionArray)
static LA_t_BracketOutput a_BracketPositionArray[EM_N_OBJECTS];

/*! Check how many poles are configred for stationary object course filtering.
Note: check for greater one, since one pole would mean identity transform,
that is no filtering */
#if (LA_PAR_STAT_COURSE_FIR_POLES > 1u)
/*! Local low-pass filtered trajectory for stationary objects */
SET_MEMSEC_VAR(LAStatLowPassTraj)
static struct LAStatLowPassTraj
{
  float32 afCrvSamples[LA_PAR_STAT_COURSE_FIR_POLES];
  float32 fSumCrv;
  uint8 uNextIdx;
  CP_t_GDBTrajectoryData Traj;
} LAStatLowPassTraj;
#endif

#if ( LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM || \
      LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM || \
      LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM )
#ifdef FCT_SIMU 

SET_MEMSEC_VAR(LACritMatrixAllObjDebug)
LA_t_DebugCriteriaMatrixAllObj LACritMatrixAllObjDebug;

SET_MEMSEC_CONST(LACritMatAllObjMeasInfo)
static const MEASInfo_t LACritMatAllObjMeasInfo = 
{
  /* .VirtualAddress = */
  FCT_MEAS_ID_LA_CRITERIA_MATRIX_ALL_OBJ,
  /* .Length = */
  sizeof(LACritMatrixAllObjDebug),
  /* .FuncID = */
  OOI_MEAS_FUNC_ID,
  /* .FuncChannelID = */
  OOI_MEAS_FUNC_CHAN_ID
};
#endif  /*!< FCT_SIMU */
#endif /*!< LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM, LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM, LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM */

/*****************************************************************************
  FUNCTION 
*****************************************************************************/
static void LA_v_CalculateBaseLaneWidths(void);
static void LA_v_ConstructCorridorEnvironment(LA_t_AssTraEnvironment* const pEnvironment);
static void LA_v_ConstructDefaultTrajectory(LA_t_RelTraCurve* const pRelTraCurve);
static void LA_v_ConstructAlternativeTrajectory(LA_t_RelTraCurve* const pRelTraCurve);
static void LA_v_UpdateRelevanceForAllObjects(void);
static void LA_v_AdjustObjectPropertiesToTrajectory(LA_t_RelTraObjInput* const pObjectProperties, const LA_t_RelTraCurve* const pTrajectory);
static void LA_v_ConstructObjectVariables(const ObjNumber_t ObjNr, LA_t_RelTraObjOutput* const pRelTraObj);
static void LA_v_ConstructObjectProperties(const ObjNumber_t ObjNr, LA_t_RelTraObjInput* const pRelTraObj);
static void LA_v_InitCriteriaMatrix (LA_t_CriteriaMatrix * const pCriteriaMatrix);
static void LA_v_RelTraInitCriteriaOutput(LA_t_BracketOutput * const pOutput, const LA_t_TraceBracketMode eMode);
static LA_t_BracketOutput LA_t_CalculateBracketsForCurrentObject(const ObjNumber_t ObjNr, LA_t_RelTraObjInput* const pObjectProperties, const  LA_t_RelTraCurve* const pTrajectory, LA_t_AssTraEnvironment* const pEnvironment,
                                                             const LA_t_CriteriaMatrixAllObj* const pCritMatrixAllObj);
static void LA_v_RecalculateBracketsUsingAlternativeTrajectory(const ObjNumber_t ObjNr, LA_t_RelTraObjInput* const pObjectProperties, LA_t_RelTraObjOutput* const pObjectVariables,
                                                            LA_t_AssTraEnvironment* const pEnvironment, LA_t_CriteriaMatrix* const pBracketFuncResults, LA_t_BracketFuncEnable * const pBracketFuncEnableFlags, 
                                                            const LA_t_CriteriaMatrixAllObj* const pCritMatrixAllObj);
static LADistanceWidth_t LA_t_GenerateCorridorDescriptionFromBrackets(const ObjNumber_t ObjNr, const LA_t_BracketOutput* const pBracketPositions, const LA_t_RelTraObjInput* const pObjectProperties);
static void LA_v_PerformReflectionCorrection(const ObjNumber_t ObjNr, LADistanceWidth_t* const pCorridorDescription);

static void LA_v_InitCorridorCritModule(void);
static void LA_v_EnableAllBracketFunctions(LA_t_BracketFuncEnable* const pBracketFuncEnable);
static float32 LA_f_CalcRelTraTrackwidthSeek( void );
static float32 LA_f_CalcRelTraTrackwidthTrack( void );
#if ((LA_CFG_ADAPT_LANEWIDTH_BASED_ON_CAM) && (FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING))
static void LA_v_ManipulateLaneClassBasedOnCam(FIP_t_LaneWidthClass* const pLaneWidthClass);
#endif /* END IF ((LA_CFG_ADAPT_LANEWIDTH_BASED_ON_CAM) && (FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING)) */

static float32 LA_f_GetObjWidthVarForCorridor(const ObjNumber_t iObjNr);
static float32 LA_f_GetReflectionOffset(const ObjNumber_t iObjNr);
#if (LA_PAR_STAT_COURSE_FIR_POLES > 1u)
static void LA_v_CalcStatLowPassTraj(void);
#endif
static void LA_v_UpdateRelevancyTimers(const ObjNumber_t ObjNr , LA_t_ObjCorridor *const pObjCor);
static void LA_v_UpdateTimeTrackLaneExtFactor(const ObjNumber_t ObjNr , LA_t_ObjCorridor *const pObjCor);
static void LA_v_UpdateDistTrackLaneExtFactor(const ObjNumber_t ObjNr, LA_t_ObjCorridor *const pObjCor);

static void LA_v_RelTraObjOutputToObject(const LA_t_RelTraObjOutput *const pRelTraObj , LA_t_ObjCorridor *const pObjCor );

// PRQA S 7013 STTLN_EXCEEDED
/* date: 2015-04-28, reviewer: Lonard jaison manohar, reason: Number of lines exceeded per file, not safety critical */

/*************************************************************************************************************************
  Functionname:    LA_v_CorridorInit                                                            */ /*!

  @brief           Initialize module data

  @description     Initialize SI corridor module specific data

		@startuml
		Start
		Partition LA_v_CorridorInit {
			#Orange :<b>LA_v_InitCorridorCritModule()</b>:Initialize/reset global variables of this module;
			Partition #LightBlue "**~#if LA_PAR_STAT_COURSE_FIR_POLES > 1u **" {
				Repeat
					: Initialize Curve samples as 0;
				Repeat While (For all Poles)
				: Initialize low-pass filtered trajectory for stationary objects;
			}
		}
		End
		@enduml

  @return          -

  @param[in]       -
  @param[out]      -

  @glob_in         -
  @glob_out        LAStatLowPassTraj : struct with information on low-pass filtered trajectory for stationary objects [LAStatLowPassTraj type]
                    afCrvSamples[i] : buffer of curvature samples [-1.f ... 1.f]
                          with i in [0u ... LA_PAR_STAT_COURSE_FIR_POLES[ and LA_PAR_STAT_COURSE_FIR_POLES as in sla_par.h
                    fSumCrv : curve sum value [full range of float32]
                    uNextIdx : next index in curvature buffer [0u ... LA_PAR_STAT_COURSE_FIR_POLES[ and LA_PAR_STAT_COURSE_FIR_POLES as in la_par.h
                    Traj.fTrajC0 : trajectory C0 parameter value [-1.f ... 1.f]
                    Traj.fTrajC1 : trajectory C1 parameter value [-1.f ... 1.f]
                    Traj.fTrajAngle : trajectory angle [-PI ... PI]

  @c_switch_part   LA_PAR_STAT_COURSE_FIR_POLES : How many poles to use to filter VDY course for stationary objects
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component

  @pre             -
  @post            -

  @testmethod      Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         -

  @author          Christopher Knievel | christopher.knievel@continental-corporation.com | +49 (8382) 9699-399
*************************************************************************************************************************/
void LA_v_CorridorInit (void)
{
#if (LA_PAR_STAT_COURSE_FIR_POLES > 1u)
  uint8 i;
#endif

  /* Call new function of si_corridor_crit.c to initialize that module's statics */
  LA_v_InitCorridorCritModule();

#if (LA_PAR_STAT_COURSE_FIR_POLES > 1u)
  for (i = 0u; i < LA_PAR_STAT_COURSE_FIR_POLES; i++)
  {
    LAStatLowPassTraj.afCrvSamples[i] = 0.f;
  }
  LAStatLowPassTraj.fSumCrv         = 0.f;
  LAStatLowPassTraj.uNextIdx        = 0u;
  LAStatLowPassTraj.Traj.fTrajC0    = 0.f;
  LAStatLowPassTraj.Traj.fTrajC1    = 0.f;
  LAStatLowPassTraj.Traj.fTrajAngle = 0.f;
#endif
}

/*************************************************************************************************************************
  Functionname:    LA_v_Calculate_ACC_Corridor                                                            */ /*!

  @brief           Calculates the corridor width for the actual object, including criteria for corridor expansion 
                   and restriction

  @description     This is the 'main' function of the corridor evaluation functions. It first initializes a stack 
                   local LA_t_AssTraEnvironment instance. It then loops through all objects first updating their
                   relevancy information (function LA_v_UpdateRelevanceForAllObjects), and calculating the corresponding 
                   trace brackets

		@startuml 
		Start
		Partition LA_v_Calculate_ACC_Corridor {
		: Calculate the seek and track lane widths;
		: Fill corridor environment with initial values;
		: Setup ACC trajectory which is considered for trace bracket calculation;
		: Initialization of the criteria (trace brackets) which are independent of a specific object;
		: Calculate the trace brackets independent of a specific object;
		: Update relevancy information for all objects;
		Partition LA_CFG_BLOCKED_OBSTACLE_EXTENSION {
			: Determine the "real" object that is selected based on blocked path "object to obstacle";
		}
		Repeat
			: Construct object properties for better processing in the lane assignment determination;
			: Adjust object properties to trajectory;
			: Calculate brackets for current object and store it to Bracket Position array;
			: Get Corridor Description using calculation of the center of the corridor;
			: Perform reflection correction;
			: Store the final corridor description for the current object;
		Repeat While (For All Objects)
		}
		stop
		@enduml

  @return          -

  @param[in,out]   pDistWidth : pointer to corridor description array of length i [LADistanceWidth_t]
                      with i in [0 ... EM_N_OBJECTS[ and EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @glob_in         -
  @glob_out        -

  @c_switch_part   LA_CFG_BLOCKED_OBSTACLE_EXTENSION : blocked obstacle extension
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component

  @pre             CP must be finished
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         -

  @author          Christopher Knievel | christopher.knievel@continental-corporation.com | +49 (8382) 9699-399
*************************************************************************************************************************/
void LA_v_Calculate_ACC_Corridor(LADistanceWidth_t pDistWidth[])
{
  ObjNumber_t           ObjNr;
  LA_t_AssTraEnvironment   t_Environment;
  LA_t_RelTraCurve         Trajectory;

  /* Criteria Matrix: values which are the same for all objects */
  LA_t_CriteriaMatrixAllObj CritMatrixAllObj;

  /* Calculate two types of lane widths on which the corridor calculation is going to be based.
     A wider corridor is used for objects which are being tracked, while a more narrow one is considered for non-tracked objects. */
  LA_v_CalculateBaseLaneWidths(); 

  /* Initialization of the environment variable */
  LA_v_ConstructCorridorEnvironment(&t_Environment);

  /* Save parameters of ACC trajectority (includes fusion of VDY and ROAD) */
  LA_v_ConstructDefaultTrajectory(&Trajectory);

  /* Initialization of Criteria Matrix which is equal for all objects as well as
      activation / deactivation of corridor bracket functions*/
  LA_v_InitCriteriaMatrixAllObj(&CritMatrixAllObj);

  /* Determine Criteria Matrix which is equal for all objects */
  LA_v_RelTraCheckCriteriaAllObj(&CritMatrixAllObj);

  /* Update for all objects relevant/not relevant time, lane extension factor, and distance extension factor */
  LA_v_UpdateRelevanceForAllObjects();

#if (LA_CFG_BLOCKED_OBSTACLE_EXTENSION)
  /* Determine the "real" object that is selected based on a blocked path "object to obstacle" */
  LA_v_GetBlockedObstacleCorridor();
#endif

  /* For each object a distinct description of the corridor is calculated.
     The description consists of the corridor width, the object's width and the distance from the object to the center of the corridor. */
  for (ObjNr = (ObjNumber_t)(EM_N_OBJECTS - 1) ; ObjNr >= 0; ObjNr--)
  {
    LADistanceWidth_t CorridorDescription;
    LA_t_RelTraObjInput  ObjectProperties;

    /* Collect properties relating to the current object and combine them in a single data structure.
       The dAblage_Radius property depends on the trajectory, therefore it is set separately. */
    LA_v_ConstructObjectProperties(ObjNr, &ObjectProperties);

    /* Lateral component of the point on the trajectory with the shortest distance to the object */
    LA_v_AdjustObjectPropertiesToTrajectory(&ObjectProperties, &Trajectory);

    /* For the current object calculate the left and right bracket position, which mark the boundaries of the corridor.
    Using the base lane widths the brackets are positioned and then further extended/restricted based on whether specific case scenarios are detected. */
    a_BracketPositionArray[ObjNr] = LA_t_CalculateBracketsForCurrentObject(ObjNr, &ObjectProperties, &Trajectory, &t_Environment, &CritMatrixAllObj);

    /* Use the bracket positions calculated for the current object to generate a corresponding corridor description.
    This description consists of the corridor width, the object's width and the distance from the object to the center of the corridor. */
    CorridorDescription = LA_t_GenerateCorridorDescriptionFromBrackets(ObjNr, &a_BracketPositionArray[ObjNr], &ObjectProperties);

    /* Reflection correction */
    LA_v_PerformReflectionCorrection(ObjNr, &CorridorDescription);

    /* Store the final corridor description for the current object */
    pDistWidth[ObjNr] = CorridorDescription;
  }
}

/*************************************************************************************************************************
  Functionname:    LA_t_GetBracketPosition                                                                             */ /*!

  @brief            Get Bracket Position of the given object

  @description      Get cordinates of left and right bracket positions for the given object which is
                    stored in a static variable a_BracketPositionArray computed in LA_v_Calculate_ACC_Corridor module

		@startuml
		Start
		Partition LA_t_GetBracketPosition {
		: Get Bracket Position of the given object;
		}
		End
		@enduml

  @return          a_BracketPositionArray[iObj] : Braket postion of type LA_t_BracketOutput for given object 

  @param[in]       iObj : FCT object ID                                                                        [0 ... 39]

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   -

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         8/25/2016
  @changed         8/25/2016

  @todo            Remove this entire line if not needed

  @author          Saurabh Pandey | saurabh.pandey-ext@continental-corporation.com | 
*************************************************************************************************************************/
 LA_t_BracketOutput LA_t_GetBracketPosition(const ObjNumber_t iObj)
{
  return a_BracketPositionArray[iObj];
}

/*************************************************************************************************************************
  Functionname:    SIGetObjWidthForCorridor                                                            */ /*!

  @brief           Get object width variance for corridor calculation

  @description     Get object width variance for corridor calculation. At the moment this value is either zero for a priori
                   stationary objects. In all other cases another non-zero value is set

		@startuml
		Start
		Partition LA_f_GetObjWidthVarForCorridor {
		If (Object Dynamic Property is Stationery and Object Is Not Moving To Stationary and Object Longitudinal Distance > LA_STAT_CLOSE_RANGE) then (yes)
			: Set Variance of object width as 0;
		Else (no)
			: Set Variance of object width as Square_root(LA_OBJ_WIDTH_VAR_MOVE_NEAR);
		Endif
		}
		End
		@enduml

  @return          fVar : Variance of object width to use for corridor [0.f ... 10.f]

  @param[in]       iObjNr : internal object number (Object ID) of a valid object [0 ... EM_N_OBJECTS[
                           with EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @param[out]      -

  @glob_in         *pt_LAInput->t_RTE.pf_ObjLongDisp  (i) : Longitudinal displacement of an object i [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                            with i in [0 ... EM_N_OBJECTS[ and EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @glob_in         *SLATE_pt_GetObjDynProperty(i) : Dynamic property of object i [SLATE_t_Obj_DynamicProperty as defined in rte_type.h]
                            with i in [0 ... EM_N_OBJECTS[ and EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @glob_in         SLATE_b_GetObjIsMovingToStationary(i) : Info if object i is moving to stationary [TRUE, FALSE]
                            with i in [0 ... EM_N_OBJECTS[ and EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component

  @pre             EM Object class/moving to stationary/long displacement is available for given object
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         -

  @author          Norman Apel | norman.apel@continental-corporation.com | +49 (8382) 9699-365
*************************************************************************************************************************/
static float32 LA_f_GetObjWidthVarForCorridor(const ObjNumber_t iObjNr)/* PRQA S 2200 *//* Date: 2020-04-02, Reviewer:Gireesh , Reason:This warning is suppressed as Indentation does not have any critical impact the functionality. */
{
  float32 fVar;
  float32 f_ObjDistX = *pt_LAInput->t_RTE.pf_ObjLongDisp(iObjNr);
  SLATE_t_Obj_DynamicProperty t_ObjDynProperty = *SLATE_pt_GetObjDynProperty(iObjNr);
  boolean b_ObjIsMovingToStationary = SLATE_b_GetObjIsMovingToStationary(iObjNr);

  if( (t_ObjDynProperty == SLATE_OBJECT_PROPERTY_STATIONARY)
    &&(!b_ObjIsMovingToStationary)
    &&(f_ObjDistX > LA_STAT_CLOSE_RANGE))
  {
    fVar = 0.f;
  }
  else
  {
    fVar = SQR(LA_OBJ_WIDTH_VAR_MOVE_NEAR);
  }

  return (fVar * LA_OBJ_WIDTH_VAR_FACTOR);
}

/*************************************************************************************************************************
  Functionname:    LA_f_GetReflectionOffset                                                            */ /*!

  @brief           Get reflection offset for correcting 

  @description     Get reflection offset for correcting. Value is a function of object width, object angle and 
                   object number of life cycles.

		@startuml
		Start
		Partition LA_f_GetReflectionOffset {
		: Get Object Angle, Object Life Cycles;
		: Get Angle corridor Factor and Life time Corridor Factor;
		Partition FCT_CFG_INPUT_PREPROCESSSING {
		: Calculate Distance Reflection Offset;
		}
		}
		End
		@enduml

  @return          fDistReflectionOffset : reflection offset [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m

  @param[in]       iObjNr : internal object number (Object ID) of a valid object [0 ... EM_N_OBJECTS[
                           with EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @param[out]      -

  @glob_in         SLATE_f_GetObjectAngle(i) : Longitudinal displacement of an object i [-PI ... +PI] rad
                            with i in [0 ... EM_N_OBJECTS[ and EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @glob_in         SLATE_u_GetObjLifeCycles(i) : Number of life cycles of object i [AlgoCycleCounter_t as defined in rte_type.h]
                            with i in [0 ... EM_N_OBJECTS[ and EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @glob_in         pt_LAInput->t_FIPOA.pf_GetObjWidthforCorridor(i)  : get object width for corridor of object with ID i  [0.f  10.f]
                            with i in [0 ... EM_N_OBJECTS[ and EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @glob_out        -

  @c_switch_part   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC
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

  @author          Norman Apel | norman.apel@continental-corporation.com | +49 (8382) 9699-365
*************************************************************************************************************************/
static float32 LA_f_GetReflectionOffset(const ObjNumber_t iObjNr)
{
  float32 f_ObjectAngle, f_ObjLifeCycles, fAngleCorrFactor, fLifeTimeCorrFactor;
  float32 fDistReflectionOffset;

  f_ObjectAngle = SLATE_f_GetObjectAngle(iObjNr);
  f_ObjLifeCycles = (float32)(SLATE_u_GetObjLifeCycles(iObjNr));
  
  fAngleCorrFactor    = dGDBmathLineareFunktion ( &ReflectionCorrectionAngleFactor, fABS(f_ObjectAngle));
  fLifeTimeCorrFactor = dGDBmathLineareFunktion ( &ReflectionCorrectionLifeFactor, f_ObjLifeCycles);
  

#if (FCT_CFG_INPUT_PREPROCESSSING)
  fDistReflectionOffset = 0.5F * ((pt_LAInput->pt_FIPOA->t_ObjList[iObjNr].f_ObjectWidthCorridor))
                               * fAngleCorrFactor
                               * fLifeTimeCorrFactor;
#endif /*(FCT_CFG_INPUT_PREPROCESSSING)*/
  return fDistReflectionOffset;
}

#if (LA_PAR_STAT_COURSE_FIR_POLES > 1u)
/*************************************************************************************************************************
  Functionname:    LA_v_CalcStatLowPassTraj                                                            */ /*!

  @brief           Calculate second low pass trajectory for stationary objects

  @description     Calculate second low pass trajectory information and store it into module local LAStatLowPassTraj variable

		@startuml
		Start
		Partition LA_v_CalcStatLowPassTraj {
		: Load current ego curvature;
		: Read old curvature from buffer;
		: Write the new curvature value into the buffer;
		: Update the next index in the buffer to write to;
		: Update sum of Curvature values in buffer;
		: Write simple curve with no angle and change rate of trajectory data;
		}
		End
		@enduml

  @return          -

  @param[in]       -
  @param[out]      -

  @glob_in         pt_LAInput->t_RTE.pf_EgoCurveRaw : Unfiltered curve provided by VDY [-1.f ... +1.f] m^(-1)
  @glob_in         LAStatLowPassTraj : struct with information on low-pass filtered trajectory for stationary objects [LAStatLowPassTraj type]
                    LAStatLowPassTraj.afCrvSamples[i] : buffer of curvature samples [-1.f ... 1.f]
                          with i in [0u ... LA_PAR_STAT_COURSE_FIR_POLES[ and LA_PAR_STAT_COURSE_FIR_POLES as in la_par.h
                    fSumCrv : curve sum value [full range of float32]
                    uNextIdx : next index in curvature buffer [0u ... LA_PAR_STAT_COURSE_FIR_POLES[ and LA_PAR_STAT_COURSE_FIR_POLES as in la_par.h
  @glob_out        LAStatLowPassTraj : struct with information on low-pass filtered trajectory for stationary objects [LAStatLowPassTraj type]
                    LAStatLowPassTraj.afCrvSamples[i] : buffer of curvature samples [-1.f ... 1.f]
                          with i in [0u ... LA_PAR_STAT_COURSE_FIR_POLES[ and LA_PAR_STAT_COURSE_FIR_POLES as in la_par.h
                    fSumCrv : curve sum value [full range of float32]
                    uNextIdx : next index in curvature buffer [0u ... LA_PAR_STAT_COURSE_FIR_POLES[ and LA_PAR_STAT_COURSE_FIR_POLES as in la_par.h
                    Traj.fTrajC0 : trajectory C0 parameter value [-1.f ... 1.f]
                    Traj.fTrajC1 : trajectory C1 parameter value [-1.f ... 1.f]
                    Traj.fTrajAngle : trajectory angle [-PI ... PI]

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component
  @c_switch_full   LA_PAR_STAT_COURSE_FIR_POLES : Number of poles to use to filter VDY course for stationary objects, hast to be grater than 1

  @pre             -
  @post            -

  @testmethod      Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         -

  @author          Gergely Ungvary | gergely.ungvary@conti-engineering.com | +36-88-548-671
*************************************************************************************************************************/
static void LA_v_CalcStatLowPassTraj(void)
{
  /* Load current ego curvature */
  const float32 fCurCrv = *pt_LAInput->t_RTE.pf_EgoCurveRaw;
  /* Read old curvature from buffer (the value we are about to overwrite) */
  const float32 fOldCrv = LAStatLowPassTraj.afCrvSamples[LAStatLowPassTraj.uNextIdx];

  /* Write the new curvature value into the buffer */
  LAStatLowPassTraj.afCrvSamples[LAStatLowPassTraj.uNextIdx] = fCurCrv;
  /* Update the next index in the buffer to write to */
  LAStatLowPassTraj.uNextIdx = ((LAStatLowPassTraj.uNextIdx + 1u) % (uint8)LA_PAR_STAT_COURSE_FIR_POLES);
  /* Update summ of values in buffer */
  LAStatLowPassTraj.fSumCrv += (fCurCrv - fOldCrv);
  /* And write output data struct (simple curve with no angle and change rate) */
  LAStatLowPassTraj.Traj.fTrajAngle = 0.f;
  LAStatLowPassTraj.Traj.fTrajC0    = LAStatLowPassTraj.fSumCrv * (1.f / (float32)LA_PAR_STAT_COURSE_FIR_POLES);
  LAStatLowPassTraj.Traj.fTrajC1    = 0.f;
}
#endif

/*************************************************************************************************************************
  Functionname:    LA_v_ConstructCorridorEnvironment                                                            */ /*!

  @brief           Fill corridor environment with initial values

  @description     Fill corridor environment with initial values

		@startuml
		Start
		Partition LA_v_ConstructCorridorEnvironment {
		Partition FCT_CFG_ROAD_INPUT {
		Partition FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING {
		: Set Environment Lane matrix (Number of Left Lanes and Number of Right Lanes);
		}
		: Set No Lane Probability to Left as ROAD_GET_NO_LANE_MATRIX_PROB_LEFT;
		: Set No Lane Probability to Right as ROAD_GET_NO_LANE_MATRIX_PROB_RIGHT;
		If (Confidence of Left Border estimation >= Minimum road border status) then (yes)
			: Set the distance to the road border left as absolute value of Distance to left side fused road boundary;
		Else (no)
		: Do not use road border;
		Endif
		If (Confidence of Right Border estimation >= Minimum road border status) then (no)
		: Set the distance to the road border right as absolute value of Distance to right side fused road boundary;
		Else (no)
		: Do not use road border;
		Endif   
		}
		: Get information regarding the tracked relevant objects;
		If (Check if No Tracked Relevant Objects) then (yes)
			: Get Relevant Object, its Dynamic Property, its Longitudinal Distance and Lateral Distance;
			Partition LA_CFG_EXT_RELEVANT_OBJECT {
				: Get Relevant Object Target Fusion Hold Time;
		}
		Else (no)
			: There is no relevant Object;
			: Set Relevant Object Dynamic Property, its Longitudinal Distance and Lateral Distance as 0;
			Partition LA_CFG_EXT_RELEVANT_OBJECT {
				: Set Relevant Object Target Fusion Hold Time as 0;
		}
		Endif
		: Save lane assignment environment data for visualization;	
		}
		End
		@enduml

  @return          -

  @param[in]       -
  @param[out]      p_Environment : environment variable information [LA_t_AssTraEnvironment as defined in la_corridor_crit.h]
                    p_Environment->ucRelObjDynamicProperty : Relevant object dynamic property [SLATE_t_Obj_DynamicProperty as defined in rte_type.h]
                    p_Environment->iRelObjNr : Relevant object object number [-1 ... EM_N_OBJECTS-1] and EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
                    p_Environment->fRelObjDistX : Longitudinal displacement of relevant object [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                    p_Environment->fRelObjDistY : Lateral displacement of relevant object [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                    p_Environment->fRelObjTargetFusionHoldTime : Object Target Fusion hold time [Full range of float32 >= 0.f]
                    p_Environment->dEOBorderLeft : Lateral ego distance to left road border [0.f ... 30.f]
                    p_Environment->dEOBorderRight : Lateral ego distance to right road border [-30.f ... 0.f]
                    p_Environment->iNumberLanesLeft : Number of left lanes [-1 ... 20]
                    p_Environment->iNumberLanesRight : Number of right lanes [-1 ... 20]
                    p_Environment->dNoLaneProbL : probability that there is no left lane [0.f ... 100.f]
                    p_Environment->dNoLaneProbR : probability that there is no right lane [0.f ... 100.f]

  @glob_in         *pt_LAInput->t_RTE.pf_ObjLongDisp  (i) : Longitudinal displacement of an object i [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                            with i in [0 ... EM_N_OBJECTS[ and EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @glob_in         *pt_LAInput->t_RTE.pf_ObjLatDisp   (i) : Lateral distance of object i [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                            with i in [0 ... EM_N_OBJECTS[ and EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @glob_in         *SLATE_pt_GetObjDynProperty(i) : Dynamic property of object i [SLATE_t_Obj_DynamicProperty as defined in rte_type.h]
                            with i in [0 ... EM_N_OBJECTS[ and EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @glob_in         pt_LAOutput->t_LAObjOutputList[i].ObjCor.fTargetFusionHoldTime : target hold time for relevant object extension [full range of float32 >= 0.f]
  @glob_in         pt_LAInput->pt_FIPRoad->t_FIPRoadFusedBorder.fDistLeft : Lateral ego distance to left road border   [0.f ... 30.f]
  @glob_in         pt_LAInput->pt_FIPRoad->t_FIPRoadFusedBorder.bStatusLeft : Left road border status                  [0u ... 100u]
  @glob_in         pt_LAInput->pt_FIPRoad->t_FIPRoadFusedBorder.fDistRight : Lateral ego distance to right road border [-30.f ... 0.f]
  @glob_in         pt_LAInput->pt_FIPRoad->t_FIPRoadFusedBorder.bStatusRight : Right road border status                [0u ... 100u]
  @glob_in         ROAD_GET_NO_LANE_MATRIX_PROB_LEFT : probability that there is no left lane [0.f ... 100.f]
  @glob_in         ROAD_GET_NO_LANE_MATRIX_PROB_RIGHT : probability that there is no right lane [0.f ... 100.f]
  @glob_out        AssTraEnvironment : save environment data for debugging and visualization [LA_t_AssTraEnvironment as defined in la_corridor_crit.h]

  @c_switch_part   FCT_CFG_ROAD_INPUT :  Road estimation input active in FCT
  @c_switch_part   FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING :  FCT Input Preprocessing Lane matrix
  @c_switch_part   LA_CFG_EXT_RELEVANT_OBJECT : Configuration switch to enable/disable relevant object extension
  @c_switch_part   FCT_SIMU : Save data for visualization in simulation
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

  @todo            Inputs from FIP Road (pt_LAInput->t_FIPRoad) are available only if switch FCT_CFG_INPUT_PREPROCESSSING is 
                   on, which is not considered here. Switch for FCT_CFG_ROAD_INPUT to also be adapted.

  @author          Christopher Knievel | christopher.knievel@continental-corporation.com | +49 (8382) 9699-399
*************************************************************************************************************************/
static void LA_v_ConstructCorridorEnvironment(LA_t_AssTraEnvironment* const pEnvironment)
{
  ObjNumber_t RelTrckObjNr;

#if (FCT_CFG_ROAD_INPUT)
#if (FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING)
  pEnvironment->iNumberLanesLeft    = (pt_LAInput->pt_FIPLaneMatrix->s_NumOfLaneLeft);
  pEnvironment->iNumberLanesRight   = (pt_LAInput->pt_FIPLaneMatrix->s_NumOfLaneRight);
#else
  pEnvironment->iNumberLanesLeft    = 1;
  pEnvironment->iNumberLanesRight   = 1;
#endif

  pEnvironment->dNoLaneProbL        = ROAD_GET_NO_LANE_MATRIX_PROB_LEFT;
  pEnvironment->dNoLaneProbR        = ROAD_GET_NO_LANE_MATRIX_PROB_RIGHT;
  if ((pt_LAInput->pt_FIPRoad->t_FIPRoadFusedBorder.bStatusLeft) >= LA_MIN_ROAD_BORDER_STAT)
  {
    pEnvironment->dEOBorderLeft     = fABS(pt_LAInput->pt_FIPRoad->t_FIPRoadFusedBorder.fDistLeft);
  }
  else
  {
    /* Do not use road border */
    pEnvironment->dEOBorderLeft     = -1.f;
  }
  if ((pt_LAInput->pt_FIPRoad->t_FIPRoadFusedBorder.bStatusRight) >= LA_MIN_ROAD_BORDER_STAT)
  {
    pEnvironment->dEOBorderRight    = fABS(pt_LAInput->pt_FIPRoad->t_FIPRoadFusedBorder.fDistRight);
  }
  else
  {
    /* Do not use road border */
    pEnvironment->dEOBorderRight    = -1.f;
  }
#else
  pEnvironment->iNumberLanesLeft    = 1;
  pEnvironment->iNumberLanesRight   = 1;
  pEnvironment->dNoLaneProbL        = 0.5f;
  pEnvironment->dNoLaneProbR        = 0.5f;
  pEnvironment->dEOBorderLeft       = -1.f;
  pEnvironment->dEOBorderRight      = -1.f;
#endif /* FCT_CFG_ROAD_INPUT */

/* Temporary change of prefix to ensure compatibility in EBA */
  RelTrckObjNr = SISeReObGetRelTrckObjNumber(); 
  if(RelTrckObjNr != OBJ_INDEX_NO_OBJECT)
  {
    pEnvironment->iRelObjNr                   = RelTrckObjNr;
    pEnvironment->ucRelObjDynamicProperty     = *SLATE_pt_GetObjDynProperty(RelTrckObjNr);
    pEnvironment->fRelObjDistX                = *pt_LAInput->t_RTE.pf_ObjLongDisp(RelTrckObjNr);
    pEnvironment->fRelObjDistY                = *pt_LAInput->t_RTE.pf_ObjLatDisp(RelTrckObjNr);
#if (LA_CFG_EXT_RELEVANT_OBJECT)
    pEnvironment->fRelObjTargetFusionHoldTime = pt_LAOutput->t_LAObjOutputList[RelTrckObjNr].ObjCor.fTargetFusionHoldTime;
#endif
  }
  else
  {
    pEnvironment->iRelObjNr                   = OBJ_INDEX_NO_OBJECT;
    pEnvironment->ucRelObjDynamicProperty     = SLATE_OBJECT_PROPERTY_MOVING;
    pEnvironment->fRelObjDistX                = 0.0f;
    pEnvironment->fRelObjDistY                = 0.0f;
#if (LA_CFG_EXT_RELEVANT_OBJECT)
    pEnvironment->fRelObjTargetFusionHoldTime = 0.0f;
#endif
  }

#ifdef FCT_SIMU
  /* Save lane assignment environment data for visualization in simulation */
  LAAssTraEnvironment = *pEnvironment;
#endif
}

/*************************************************************************************************************************
  Functionname:    LA_v_ConstructDefaultTrajectory                                                            */ /*!

  @brief           Setup ACC trajectory

  @description     Setup ACC trajectory which is considered for trace bracket calculation

		@startuml
		Start
		Partition LA_v_ConstructDefaultTrajectory {
		: Set Curvature of considered trajectory for trace bracket as current trajectory C0 parameter value;
		: Set Absolute curvature value as absolute value of current trajectory C0;
		: Set Flag describing which trajectory hypothesis is considered as LA_OWVKRIT_AKTIV;
		}
		End
		@enduml

  @return          -

  @param[in]       -
  @param[out]      pRelTraCurve : pointer to specific trajectory used for trace bracket calculation [LA_t_RelTraCurve as defined in la_corridor_crit.h]
                    pRelTraCurve->dCurve : Curvature of considered trajectory for trace bracket calculation [-1.f ... 1.f]
                    pRelTraCurve->dCurve_abs : Absolute curvature value of considered trajectory for trace bracket calculation [0.f ... 1.f]
                    pRelTraCurve->iOWVflag : Flag describing which trajectory hypothesis is considered [LA_OWVKRIT_AKTIV as defined in la_corridor_crit.h]

  @glob_in         CP_TrajectoryData.Current.fTrajC0 : current trajectory C0 parameter value [-1.f ... 1.f]
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

  @author          Christopher Knievel | christopher.knievel@continental-corporation.com | +49 (8382) 9699-399
*************************************************************************************************************************/
static void LA_v_ConstructDefaultTrajectory(LA_t_RelTraCurve* const pRelTraCurve)
{
  /* Setup Curve struct to SI fusion course (EGO + ROAD + ..) */
  pRelTraCurve->dCurve      = pt_LAInput->t_CP.pt_TrajectoryData->Current.fTrajC0;
  pRelTraCurve->dCurve_abs  = fABS(pt_LAInput->t_CP.pt_TrajectoryData->Current.fTrajC0);
  pRelTraCurve->iOWVflag    = LA_OWVKRIT_AKTIV;
}

/*************************************************************************************************************************
  Functionname:    LA_v_UpdateRelevanceForAllObjects                                                            */ /*!

  @brief           Update relevancy information for all objects

  @description     Function loops over all objects and calls functions which update relevancy information for all objects.

		@startuml
		Start
		Partition LA_v_UpdateRelevanceForAllObjects {
		Repeat 
			If (if object is not deleted) then (yes)
				: Update Object Corridor;
				: Update relevant/non-relevant object timers;
				: Update relevant object lane extension factor distance based;
			Endif
		Repeat While (All Objects)
		}
		End
		@enduml

  @return          -

  @param[in]       -
  @param[out]      -

  @glob_in         SLATE_b_GetObjIsDeleted(i) : information if object i is deleted [TRUE, FALSE]
                            with i in [0 ... EM_N_OBJECTS[ and EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @glob_in         pt_LAOutput->t_LAObjOutputList[i].ObjCor : object specific corridor information for object i [LA_t_ObjCorridor as defined in la_corridor_crit.h]
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

  @author          Christopher Knievel | christopher.knievel@continental-corporation.com | +49 (8382) 9699-399
*************************************************************************************************************************/
static void LA_v_UpdateRelevanceForAllObjects(void)
{
  ObjNumber_t       iObj;
  LA_t_ObjCorridor*  pObjCor;
  boolean b_ObjIsDeleted;
  
  for (iObj = (ObjNumber_t)(EM_N_OBJECTS - 1) ; iObj >= 0; iObj--)
  {
    b_ObjIsDeleted = SLATE_b_GetObjIsDeleted(iObj);
    if (!b_ObjIsDeleted)
    {
      /* Update relevancy timers (relevant/not relevant time counters) */
      pObjCor = &(pt_LAOutput->t_LAObjOutputList[iObj].ObjCor);

      LA_v_UpdateRelevancyTimers(iObj, pObjCor);

      LA_v_UpdateTimeTrackLaneExtFactor(iObj, pObjCor);

      LA_v_UpdateDistTrackLaneExtFactor(iObj, pObjCor);
    }
  }
}

/*************************************************************************************************************************
  Functionname:    LA_v_ConstructObjectProperties                                                            */ /*!

  @brief           Construct object properties

  @description     Construct object properties for better processing in the lane assignment determination
  
		@startuml
		Start
		Partition LA_v_ConstructObjectProperties {
		: Update Object corridor, Object trace, Object Dynamic Property and stopped confidence;
		If (Check if Object trace < Number of Traces) then (yes)
			: Update Trace Reached Ego Vehicle value, Y intersection of the trace w.r.t X-axis and Y intersection of the trace;
		Else (no)
			: Set Trace Reached Ego Vehicle value, Y intersection of the trace w.r.t X-axis and Y intersection of the trace as 0;
		Endif
		If (check if object is relevant) then (yes)
			: Set Object as relevant Object;
		Else (no)
			: Set Object as not relevant Object;
		Endif
		: Get Object Life cycles;
		: Get Relevant trace Object data;
		}
		End
		@enduml  
  
  @return          -

  @param[in]       ObjNr : internal object number (Object ID) of a valid object [0 ... EM_N_OBJECTS[
                           with EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @param[out]      pRelTraObj : Pointer to properties of the given object [LA_t_RelTraObjInput defined in la_corridor_crit.h]
                    pRelTraObj->iObjNr [0 ... EM_N_OBJECTS[
                           with EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
                    pRelTraObj->ucDynamicProperty [SLATE_t_Obj_DynamicProperty as in Rte_Type.h]
                    pRelTraObj->uiStoppedConfidence [0u ... 100u]
                    pRelTraObj->iTracingID [TraceID_t as in Rte_Type.h]
                    pRelTraObj->iTraceReachedEgoVeh [ubit8_t as defined in la_corridor_crit.h]
                    pRelTraObj->iRelevant [ubit8_t as defined in la_corridor_crit.h]
                    pRelTraObj->iObjectLifeCycles [AlgoCycleCounter_t]
                    pRelTraObj->LetztZielEntfernung [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                    pRelTraObj->AktZielHorizontaleAblage [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                    pRelTraObj->LetztZielHorizontaleAblage [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                    pRelTraObj->fYPosStdDev [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                    pRelTraObj->dAblage_m [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                    pRelTraObj->dAbst_mittel [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                    pRelTraObj->dVrel_mittel [-330.f ... 330.f] m/s 
                    pRelTraObj->dWinkel_mittel [-PI … +PI] rad
                    pRelTraObj->dWinkel_m_abs [0 … PI] rad
                    pRelTraObj->dAblageSpurGrenzeR [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                    pRelTraObj->dAblageSpurGrenzeL [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                    pRelTraObj->dAblage_Radius [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                    pRelTraObj->dRelevantZeit : timer for relevancy [0 .. LA_RELEVANTZEIT_MAX] with LA_RELEVANTZEIT_MAX defined in la_par.h
                    pRelTraObj->dNichtRelevantZeit : timer for non-relevancy [0 .. LA_RELEVANTZEIT_MAX] with LA_RELEVANTZEIT_MAX defined in la_par.h
                    pRelTraObj->dRelSpurErweiterungsFaktor [0.0f ... 1.0f]
                    pRelTraObj->dRelSpurAbstandErweitFaktor [0.0f ... 1.0f]
                    pRelTraObj->dYIntersec [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                    pRelTraObj->dYIntersecGradFilt [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m

  @glob_in         pt_LAOutput->t_LAObjOutputList[i].ObjCor : relevance time and trace bracket extension factor information [LA_t_ObjCorridor as defined in la_corridor_crit.h]
                            with i in [0 ... EM_N_OBJECTS[ and EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @glob_in         OBJ_GET_TRACE_ID(i) : The trace ID of the object [Datatype of unsigned char] [0 ... 10]
                            with i in [0 ... EM_N_OBJECTS[ and EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @glob_in         *SLATE_pt_GetObjDynProperty(i) : Dynamic property of object i [SLATE_t_Obj_DynamicProperty as defined in rte_type.h]
                            with i in [0 ... EM_N_OBJECTS[ and EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @glob_in         SLATE_b_GetObjIsMovingToStationary(i) : Info if object i is moving to stationary [TRUE, FALSE]
                            with i in [0 ... EM_N_OBJECTS[ and EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @glob_in         TRACE_IS_OUALITY_FLAG_SET(i) : check for trace validity flag [TRUE, FALSE]
                            with i in [0 ... FIP_STATIC_TRACE_NO_OF_TRACES[ and FIP_STATIC_TRACE_NO_OF_TRACES as in Rte_SWCEmAdapt_Type.h
  @glob_in         GET_MOVING_OBJ_TRACE_PTR(i): Pointer to trace object i [data type ObjectTrace_t as defined in Rte_Type.h]
                            with i in [0 ... FIP_STATIC_TRACE_NO_OF_TRACES[ and FIP_STATIC_TRACE_NO_OF_TRACES as in Rte_SWCEmAdapt_Type.h
  @glob_in         TRACE_GET_Y_INTERSEC(i) : Get y intersection of given trace [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                            with i in [0 ... FIP_STATIC_TRACE_NO_OF_TRACES[ and FIP_STATIC_TRACE_NO_OF_TRACES as in Rte_SWCEmAdapt_Type.h
  @glob_in         TRACE_GET_Y_INTERSEC_GRAD_FILT(i) : gradient of y intersection of given trace [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m 
                            with i in [0 ... FIP_STATIC_TRACE_NO_OF_TRACES[ and FIP_STATIC_TRACE_NO_OF_TRACES as in Rte_SWCEmAdapt_Type.h
  @glob_in         SLATE_u_GetObjLifeCycles(i) : Number of life cycles of object i [AlgoCycleCounter_t as defined in rte_type.h]
                            with i in [0 ... EM_N_OBJECTS[ and EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @glob_in         OBJ_TGT_LAST_DISTANCE(i) : last longitudinal distance of object i [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                            with i in [0 ... EM_N_OBJECTS[ and EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @glob_in         OBJ_TGT_LAT_DISPLACEMENT(i) : current lateral distance of object i [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                            with i in [0 ... EM_N_OBJECTS[ and EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @glob_in         OBJ_TGT_LAST_HORZ_DISPLACEMENT(i) : last lateral distance of object i [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                            with i in [0 ... EM_N_OBJECTS[ and EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @glob_in         *pt_LAInput->t_RTE.pf_ObjLatDisp_STD(i) : standard deviation of lateral displacement [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                            with i in [0 ... EM_N_OBJECTS[ and EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @glob_in         *pt_LAInput->t_RTE.pf_ObjLatDisp   (i) : Lateral distance of object i [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                            with i in [0 ... EM_N_OBJECTS[ and EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @glob_in         *pt_LAInput->t_RTE.pf_ObjLongDisp(i) : Longitudinal distance of object i [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                            with i in [0 ... EM_N_OBJECTS[ and EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @glob_in         pt_LAInput->t_RTE.pf_ObjVrelX(i) : Relative velocity of object i [-330.f ... 330.f] m/s
                            with i in [0 ... EM_N_OBJECTS[ and EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @glob_in         SLATE_f_GetObjectAngle(i) : Longitudinal displacement of an object i [-PI ... +PI] rad
                           with i in [0 ... EM_N_OBJECTS[ and EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @glob_out        -

  @c_switch_part   LA_DISABLED_FOR_TESTING_REMOVABILITY_OF_CURRENT_TARGET_FROM_FCT : switch for testing purposes
  @c_switch_part   FCT_CFG_OBJECT_TRACE_PREPROCESSSING : Config switch for using Traces in FCT, irrespective of where they are computed
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

  @author          Christopher Knievel | christopher.knievel@continental-corporation.com | +49 (8382) 9699-399
*************************************************************************************************************************/
static void LA_v_ConstructObjectProperties(const ObjNumber_t ObjNr, LA_t_RelTraObjInput* const pRelTraObj)
{
  /* pObjCor : pointer to an LA_t_ObjCorridor type structure with
                  relevance time and trace bracket extension factor information */
  const LA_t_ObjCorridor* pObjCor = &(pt_LAOutput->t_LAObjOutputList[ObjNr].ObjCor);
  boolean b_ObjIsRelevant;
#if (FCT_CFG_OBJECT_TRACE_PREPROCESSSING)
  const TraceID_t iObjTrace = *(pt_LAInput->t_FIPMOTTraceId.pu_FIPStaticTraceID(ObjNr));
  /*TraceID_t iTracingID;*/
  pRelTraObj->iTracingID                  = iObjTrace;
#endif /* END IF (FCT_CFG_OBJECT_TRACE_PREPROCESSSING) */

  /*ObjNumber_t iObjNr;*/
  pRelTraObj->iObjNr                      = ObjNr;
  /*uint8 ucDynamicProperty;*/
  pRelTraObj->ucDynamicProperty           = *SLATE_pt_GetObjDynProperty(ObjNr);
  /*uint8 uiStoppedConfidence;*/
#if (FCT_USE_EM_ARS_TECH_OBJECT_LIST)
  pRelTraObj->uiStoppedConfidence         = SLATE_u_GetStoppedConfidence(ObjNr);
#endif
#if (FCT_CFG_OBJECT_TRACE_PREPROCESSSING)
  /* Check if link obj<->trace is valid */
  if (iObjTrace < (TraceID_t)FIP_STATIC_TRACE_NO_OF_TRACES)
  {
    pRelTraObj->iTraceReachedEgoVeh       = pt_LAInput->pt_FIPMOT->t_MovObjStaticTrace[iObjTrace].Legacy.TraceReachEgoVeh;
    pRelTraObj->dYIntersec                = pt_LAInput->pt_FIPMOT->t_MovObjStaticTrace[iObjTrace].fYIntersection;
    pRelTraObj->dYIntersecGradFilt        = pt_LAInput->pt_FIPMOT->t_MovObjStaticTrace[iObjTrace].fYIntersectionGradFilt;
  }
  else
#endif /* (FCT_CFG_OBJECT_TRACE_PREPROCESSSING) */
  {
    pRelTraObj->iTraceReachedEgoVeh       = (ubit8_t)FALSE;
    pRelTraObj->dYIntersec                = 0.0F;
    pRelTraObj->dYIntersecGradFilt        = 0.0F;
  }

  /* ubit8_t iRelevant: 1 -> Bit field of size 1 */
  b_ObjIsRelevant = SLATE_b_GetObjIsRelevant(ObjNr);
  if (b_ObjIsRelevant)
  {
    pRelTraObj->iRelevant                 = (ubit8_t)TRUE;
  }
  else
  {
    pRelTraObj->iRelevant                  = (ubit8_t)FALSE;
  }

  /*AlgoCycleCounter_t iObjectLifeCycles;*/
  pRelTraObj->iObjectLifeCycles           = SLATE_u_GetObjLifeCycles(ObjNr);

#if LA_DISABLED_FOR_TESTING_REMOVABILITY_OF_CURRENT_TARGET_FROM_FCT
  /*float32 LetztZielEntfernung;*/
  pRelTraObj->LetztZielEntfernung         = OBJ_TGT_LAST_DISTANCE(ObjNr);
  /*float32 AktZielHorizontaleAblage;*/
  pRelTraObj->AktZielHorizontaleAblage    = OBJ_TGT_LAT_DISPLACEMENT(ObjNr);
  /*float32 LetztZielHorizontaleAblage;*/
  pRelTraObj->LetztZielHorizontaleAblage  = OBJ_TGT_LAST_HORZ_DISPLACEMENT(ObjNr);
#else
  pRelTraObj->fYPosStdDev                 = *SLATE_pf_GetObjDistYStd(ObjNr);
#endif
  /*float32 dAblage_m;*/
  pRelTraObj->dAblage_m                   = *pt_LAInput->t_RTE.pf_ObjLatDisp(ObjNr);
  /*float32 dAbst_mittel;*/
  pRelTraObj->dAbst_mittel                = *pt_LAInput->t_RTE.pf_ObjLongDisp(ObjNr);
  /*float32 dVrel_mittel;*/
  pRelTraObj->dVrel_mittel                = *pt_LAInput->t_RTE.pf_ObjVrelX(ObjNr);
  /*float32 dWinkel_mittel;*/
  pRelTraObj->dWinkel_mittel              = SLATE_f_GetObjectAngle(ObjNr);
  /*float32 dWinkel_m_abs;*/
  pRelTraObj->dWinkel_m_abs               = fABS(SLATE_f_GetObjectAngle(ObjNr));/* PRQA S 3455 *//* Date: 2020-04-02,Reviewer: Gireesh, This warning is suppressed as function call does not have any critical impact the functionality.*/
  /*float32 dAblageSpurGrenzeR;*/
  pRelTraObj->dAblageSpurGrenzeR          = pObjCor->TrckFahr.dAblage_SpurGrenze_R;
  /*float32 dAblageSpurGrenzeL;*/
  pRelTraObj->dAblageSpurGrenzeL          = pObjCor->TrckFahr.dAblage_SpurGrenze_L;
  /*float32 dAblage_Radius;*/
  pRelTraObj->dAblage_Radius              = 0.f;  /*!< Value determined in SICalcCriteriaMatrix*/
  /*float32 dRelevantZeit;*/
  pRelTraObj->dRelevantZeit                = pObjCor->dRelevantZeit;
  /*float32 dNichtRelevantZeit;*/
  pRelTraObj->dNichtRelevantZeit           = pObjCor->dNichtRelevantZeit;
  /*float32 dRelSpurErweiterungsFaktor;*/
  pRelTraObj->dRelSpurErweiterungsFaktor   = pObjCor->TrckFahr.dRelSpurErweiterungsFaktor;
  /*float32 dRelSpurAbstandErweitFaktor;*/
  pRelTraObj->dRelSpurAbstandErweitFaktor  = pObjCor->TrckFahr.dRelSpurAbstandErweitFaktor;
#if LA_DISABLED_FOR_TESTING_REMOVABILITY_OF_CURRENT_TARGET_FROM_FCT
  /* to have the same effects in SIRelTraZielAblage, if distY is 999 the object is not measured */
  if (fABS(pRelTraObj->AktZielHorizontaleAblage - LA_NOT_MEASURED_TARGET_LAT_DISP) <= C_F32_DELTA)
  {
      pRelTraObj->AktZielHorizontaleAblage = -LA_NOT_MEASURED_TARGET_LAT_DISP;
  }
#endif
}

/*************************************************************************************************************************
  Functionname:    LA_t_GenerateCorridorDescriptionFromBrackets                                                            */ /*!

  @brief           Calculation of the center of the corridor

  @description     Due to asymmetric corridor extensions (left/right), the center of the corridor needs to be recalculated

		@startuml
		Start
		Partition LA_t_GenerateCorridorDescriptionFromBrackets {
		: Get estimated Object width and associated Variance of Object;
		: Get the trajectory distance;
		Partition #LightBlue "**~#if LA_PAR_STAT_COURSE_FIR_POLES > 1u **" {
			: Calculate second low pass trajectory for stationary objects;
			If (Check if Object is in-lane and Object is stationery and Object Is Not Moving To Stationary) then (yes)
				: Calculate Object Longitudinal and Lateral Distance;
				: Get trajectory reference point;
				If (Absolute value of Distance to trajectory < Absolute value of Object To Reference Distance) then (yes)
					: Get the trajectory distance;
				Endif
			Endif
		}
		: Update First element of the 2D vector;
		: Calculate Corridor Center, Distance Extension Offset, Distance and Distance Variance;
		: Calculate corridor width;
		: Update Trajectory Width and Trajectory Width Variance;
		Note Left : Set Trajectory Width Variance as 0.0f \n as long as extensions are working and track width \nis not measured or estimated 
		}
		End
		@enduml
  
  @return          Result : structure containing distance width information [LADistanceWidth_t]

  @param[in]       ObjNr : internal object number (Object ID) of a valid object [0 ... EM_N_OBJECTS[
                           with EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @param[in]       pObjectProperties : Pointer to properties of the given object [LA_t_RelTraObjInput defined in la_corridor_crit.h]
                    pObjectProperties->dAblage_Radius [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @param[in]       pBracketPositions : Pointer to properties of the given object [LA_t_BracketOutput defined in la_corridor_crit.h]
                    pBracketPositions->BracketPositionRight [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m 
                    pBracketPositions->BracketPositionLeft [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m 
  @param[out]      -

  @glob_in         FCT_fBumperToCoG : distance of bumper to center of gravity [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @glob_in         pt_LAOutput->t_LAObjOutputList[i].ObjLaneAccStatus.SIInlaneState : State if object i is in-lane or not (confirmed with all criteria) [TRUE, FALSE]
                            with i in [0 ... EM_N_OBJECTS[ and EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @glob_in         *SLATE_pt_GetObjDynProperty(i) : Dynamic property of object i [SLATE_t_Obj_DynamicProperty as defined in rte_type.h]
                            with i in [0 ... EM_N_OBJECTS[ and EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @glob_in         SLATE_b_GetObjIsMovingToStationary(i) : Info if object i is moving to stationary [TRUE, FALSE]
                            with i in [0 ... EM_N_OBJECTS[ and EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @glob_in         *pt_LAInput->t_RTE.pf_ObjLatDisp(i) : Lateral distance of object i [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                            with i in [0 ... EM_N_OBJECTS[ and EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @glob_in         *pt_LAInput->t_RTE.pf_ObjLongDisp(i) : Longitudinal distance of object i [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                            with i in [0 ... EM_N_OBJECTS[ and EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @glob_in         pt_LAInput->t_FIPOA.pf_GetObjWidthforCorridor(i)  : get object width for corridor of object with ID i  [0.f  10.f]
                            with i in [0 ... EM_N_OBJECTS[ and EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h

  @glob_out        OBJ_GET_OBJ_TO_REF_DISTANCE(i) : object distance to low-pass filtered trajectory [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m

  @c_switch_part   LA_PAR_STAT_COURSE_FIR_POLES : How many poles to use to filter VDY course for stationary objects
  @c_switch_part   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC
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

  @author          Christopher Knievel | christopher.knievel@continental-corporation.com | +49 (8382) 9699-399
*************************************************************************************************************************/
static LADistanceWidth_t LA_t_GenerateCorridorDescriptionFromBrackets(const ObjNumber_t ObjNr, const LA_t_BracketOutput* const pBracketPositions, const LA_t_RelTraObjInput* const pObjectProperties)
{
  LADistanceWidth_t Result;
  float32 CorridorWidth;
  float32 CorridorCenter;
  float32 ObjToRefDist;
  float32 ObjToRefDistVar;
  float32 fDistExtensionOffset;
  SLATE_t_Obj_DynamicProperty t_ObjDynProperty = *SLATE_pt_GetObjDynProperty(ObjNr);
  boolean b_ObjIsMovingToStationary = SLATE_b_GetObjIsMovingToStationary(ObjNr);

  /* Get estimated Object width and associated Variance */
#if (FCT_CFG_INPUT_PREPROCESSSING)
  Result.fObjectWidth    = (pt_LAInput->pt_FIPOA->t_ObjList[ObjNr].f_ObjectWidthCorridor); /* Replaces: OT_GET_OBJ_WIDTH(iObj); */
#endif /*FCT_CFG_INPUT_PREPROCESSSING*/
  Result.fObjectWidthVar = 0.0f;

  /* Get the trajectory distance */
  ObjToRefDist = pt_LAOutput->t_LAObjOutputList[ObjNr].TrajDist.TrajDistMeas.Y.f0;
  ObjToRefDistVar = pt_LAOutput->t_LAObjOutputList[ObjNr].TrajDist.TrajDistFilt.P.f00;

#if (LA_PAR_STAT_COURSE_FIR_POLES > 1u)
  /* Fill in low pass trajectory information */
  LA_v_CalcStatLowPassTraj();

  /* For stationary objects that are already assigned to the ego lane also use
  a low-pass filtered trajectory and select smaller distance to trajectory. This
  improves stationary approach performance on the proving ground, where no lane
  markers or stationary obstacle based road estimation is available.
  Only apply this to stationary (non-stopped) objects, as those already have
  extended trace brackets, which should assure correct selection */
  if ( (pt_LAOutput->t_LAObjOutputList[ObjNr].ObjLaneAccStatus.LAInlaneState == OBJ_STATE_INLANE)
    && (t_ObjDynProperty == SLATE_OBJECT_PROPERTY_STATIONARY)
    &&(!b_ObjIsMovingToStationary))
  {
    const float32     fObjDistX = (*pt_LAInput->t_RTE.pf_ObjLongDisp(ObjNr)) + FCT_fBumperToCoG;
    const float32     fObjDistY = *pt_LAInput->t_RTE.pf_ObjLatDisp(ObjNr);
    CAL_t_TrajRefPoint  DistToLowPassTraj;
    float32 f_ABS_DistToTraj;
    float32 f_ABS_ObjToRefDist ;

    LA_v_CalculateDistance2Traj(fObjDistX, fObjDistY, TRUE, &LAStatLowPassTraj.Traj, &DistToLowPassTraj);
    f_ABS_DistToTraj = fABS(DistToLowPassTraj.fDistToTraj);
    f_ABS_ObjToRefDist = fABS(ObjToRefDist);	
    if (f_ABS_DistToTraj < f_ABS_ObjToRefDist)
    {
      ObjToRefDist    = DistToLowPassTraj.fDistToTraj;
      ObjToRefDistVar = 0.f;
    }
  }
#endif

  /* Save it in global output */
  //OBJ_GET_OBJ_TO_REF_DISTANCE(ObjNr) = ObjToRefDist;
   pt_LAOutput->t_LAObjOutputList[ObjNr].TrajDist.TrajDistMeas.Y.f0 = ObjToRefDist;

  /* this offset corrects the asymmetric extensions of lane borders */
  /* distance is assumed to be measured to lane center. therefor asymmetric extensions must be considered as an offset. */
  CorridorCenter = (pBracketPositions->BracketPositionLeft + pBracketPositions->BracketPositionRight) * 0.5f;
  fDistExtensionOffset = CorridorCenter - pObjectProperties->dAblage_Radius;
  
  Result.fDistance = (ObjToRefDist - fDistExtensionOffset);
  
  Result.fDistanceVar  = ObjToRefDistVar + LA_f_GetObjWidthVarForCorridor(ObjNr); /*!< Remark: fDistanceVar >= 0 */

  /* Obtain corridor width */
  CorridorWidth = fABS(pBracketPositions->BracketPositionLeft - pBracketPositions->BracketPositionRight);
  Result.fTrajectoryWidth    = CorridorWidth;
  Result.fTrajectoryWidthVar = 0.0f; /* 0.0f as long as extensions are working and track width is not measured or estimated*/

  return Result;
}

/*************************************************************************************************************************
  Functionname:    LA_v_PerformReflectionCorrection                                                            */ /*!

  @brief           Perform reflection correction

  @description     Offset correction of the reflection point
  
		@startuml
		Start
		Partition LA_v_PerformReflectionCorrection {
		: Set offset which corrects the reflection point to the center of the object;
		If (Object Angle > 0) then (yes)
			: Calculate LA Distance using addition of Distance Reflection Offset;
		Else (no)
			: Calculate LA Distance using subtraction of Distance Reflection Offset;
		Endif
		}
		End
		@enduml  
  
  @return          Result : structure containing distance width information [LADistanceWidth_t]

  @param[in]       ObjNr : internal object number (Object ID) of a valid object [0 ... EM_N_OBJECTS[
                           with EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @param[in]       pCorridorDescription : Corridor parameters [LA_t_RelTraObjInput defined in si_corridor_crit.h]
                    pCorridorDescription->fDistance [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @param[out]      pCorridorDescription : Corridor parameters [LA_t_RelTraObjInput defined in si_corridor_crit.h]
                    pCorridorDescription->fDistance [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m

  @glob_in         SLATE_f_GetObjectAngle(i) : Longitudinal displacement of an object i [-PI ... +PI] rad
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

  @author          Christopher Knievel | christopher.knievel@continental-corporation.com | +49 (8382) 9699-399
*************************************************************************************************************************/
static void LA_v_PerformReflectionCorrection(const ObjNumber_t ObjNr, LADistanceWidth_t* const pCorridorDescription)
{
  float32 fDistReflectionOffset;
  const float32 f_ObjectAngle = SLATE_f_GetObjectAngle(ObjNr);

  /* this offset corrects the reflection point to the center of the object */
  fDistReflectionOffset = LA_f_GetReflectionOffset(ObjNr);/* Replaces: OT_GET_REFLECTION_OFFSET(iObj); */
  if(f_ObjectAngle > 0.0F)
  {
    pCorridorDescription->fDistance += fDistReflectionOffset;
  }
  else
  {
    pCorridorDescription->fDistance -= fDistReflectionOffset;
  }
}

/*************************************************************************************************************************
  Functionname:    LA_v_CalculateBaseLaneWidths                                                            */ /*!

  @brief           Calculate the seek and track lane widths

  @description     To reduce processing load, do the calculations of the seek and track lane widths once here and write
                   the results to module global variables.The corresponding values are accessible via the LA_f_GetBaseSeekLaneWidth()
                   and LA_f_GetTrackLaneWidth() functions.

		@startuml
		Start
		Partition LA_v_CalculateBaseLaneWidths {
		: Calculate the seek and track lane widths;
		}
		End
		@enduml
  
  @return          -

  @param[in]       -
  @param[out]      -

  @glob_in         LACalibLaneWidth : Structure used to calibrate lane widths over CANAPE [LACalibLaneWidth as defined in si_corridor_radarroad.c]
                    LACalibLaneWidth.bOverride [TRUE, FALSE]
                    LACalibLaneWidth.fSeekLaneWidth [LA_CALIB_LANE_WIDTH_MIN ... LA_CALIB_LANE_WIDTH_MAX]
                           with LA_CALIB_LANE_WIDTH_MIN, LA_CALIB_LANE_WIDTH_MAX as defined in si_corridor_radarroad.c
  @glob_out        pt_LAOutput->f_LA_SeekLaneWidth : global seek lane width variable [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @glob_out        pt_LAOutput->f_LA_TrackLaneWidth : global track lane width variable [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @glob_out        LACalibLaneWidth.fAutoSeekLaneWidth : seek lane width when override is not active [LA_CALIB_LANE_WIDTH_MIN ... LA_CALIB_LANE_WIDTH_MAX]  
                           with LA_CALIB_LANE_WIDTH_MIN, LA_CALIB_LANE_WIDTH_MAX as defined in si_corridor_radarroad.c

  @c_switch_part   LA_CFG_CALIBRATE_SEEK_LANE_WIDTH : Calibration of seek lane width over CANAPE
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component

  @pre             -
  @post            -

  @testmethod      Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         -

  @author          Gergely Ungvary | gergely.ungvary@conti-engineering.com | +36-88-548-671
*************************************************************************************************************************/
static void LA_v_CalculateBaseLaneWidths(void)
{
  pt_LAOutput->f_LA_SeekLaneWidth  = LA_f_CalcRelTraTrackwidthSeek();
  pt_LAOutput->f_LA_TrackLaneWidth = LA_f_CalcRelTraTrackwidthTrack();

#if (LA_CFG_CALIBRATE_SEEK_LANE_WIDTH)
  /* Store the automatic seek width */
  LACalibLaneWidth.fAutoSeekLaneWidth = pt_LA_Output->f_LA_SeekLaneWidth;

  /* When calibration seek lane width override is active, and the value is
  within an 'acceptable' range, then override the value */
  if ((LACalibLaneWidth.bOverride == TRUE) &&
      (LACalibLaneWidth.fSeekLaneWidth >= LA_CALIB_LANE_WIDTH_MIN) &&
      (LACalibLaneWidth.fSeekLaneWidth <= LA_CALIB_LANE_WIDTH_MAX))
  {
    pt_LAOutput->f_LA_SeekLaneWidth = LACalibLaneWidth.fSeekLaneWidth;
  }
#endif
}

/*************************************************************************************************************************
  Functionname:    LA_f_CalcRelTraTrackwidthSeek                                                            */ /*!

  @brief           Get seek lane width to use

  @description     Get the seek lane width to use (i.e.: the width when not following the object). This width depends on 
                   the road type and the ego velocity

		@startuml
		Start
		Partition LA_f_CalcRelTraTrackwidthSeek {
		Partition #LightBlue "**~#if (FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING) && (LA_CFG_SEEK_LANE_WIDTH_USE_LANE_CLASS) **” {
			: Update Lane Width class;
		}
		Partition LA_CFG_SEEK_LANE_WIDTH_USE_LANE_CLASS {
			Partition FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING {
				If (Lane Width is Unknown or Normal) then (yes)
					: break;
				Else if (Lane Width is Narrow) then (yes)
					: Calculate lane width; 
					Note Left: Narrow lane width is typically \ndetected on narrow roads \nsuch as the Brenner pass ;
				Else if (Lane Width is Narrower) then (yes)
					: Calculate lane width;
					Note Left: Narrower lane width is typically\n detected when roads are very narrow \nas in a construction site ;
				Else (no)
					: Do Nothing;
					Note Right: If no info available or normal \nwidth then assume highway widths, which are \nlinearly mapped depending on ego speed ;
				Endif
			}
		}
		Partition FCT_CFG_ROAD_INPUT {
			Partition FCT_CFG_INPUT_PREPROCESSSING {
				: Update Road Type Levels;
		}
		If (If Road is City Road) then (yes)
				: Set seek lane width as LA_CITYLANEWIDTHSEEK;
			Else if (Road is Highway) then (yes)
				: Set seek lane width as class width;
			Else (no)
				: Set seek lane width as LA_STANDARDLANEWIDTHSEEK;
			Endif
			Partition #LightBlue "**~#if LA_CFG_LIMIT_LANEWIDTH_IN_TUNNEL && FCT_CFG_SIGNAL_PERF_MONITORING **” {
				If (Tunnel Probability >= 0.5) then (yes)
					: Set seek lane width as LA_TUNNEL_LANEWIDTHSEEK;
				Endif
		}
		If (Check if Road work is detected) then (yes)
			If (If Road is Highway) then (yes)
					: Set seek lane width as LA_ROADWORKSLANEWIDTHSEEK;
				Endif
			Else (no)
				: Do Nothing;
			Endif
		}
		}
		End
		@enduml
  
  @return          fret : the seek lane width [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m

  @param[in]       -
  @param[out]      -

  @glob_in         ROAD_GET_LANE_CLASS : road lane class [eLaneWidthClass_t as defined in Rte_Type.h]
  @glob_in         pt_LAInput->t_RTE.pf_EgoVelObjSync : Ego velocity [-330.f ... 330.f] m/s 
  @glob_in         pt_LAInput->t_RTE.pf_TunnelProbability : Probability for a tunnel [0.0f ... 1.0f]
  @glob_in         GET_ROAD_DATA_PTR->LaneWidth.fLaneWidth : [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @glob_in         GET_ROAD_DATA_PTR->LaneWidth.eLaneWidthSource : source of lane width information [eLaneWidthSource_t as defined in Rte_Type.h]
  @glob_in         pt_LAInput->pt_FIPRoadType->t_FusedRoadType : Reference to FIP road type [full range of FIP_t_FusedRoadType as in fip_ext.h]
  @glob_in         pt_LAInput->pt_FIPRoadType->t_RoadWorks : Reference to FIP road works type [full range of FIP_t_RoadWorks as in fip_ext.h]
  @glob_out        -

  @c_switch_part   LA_CFG_LIMIT_SEEK_LANEWIDTH_BASED_ON_ROAD : limitation of seek lane width based on road lane width estimation
  @c_switch_part   LA_CFG_LIMIT_LANEWIDTH_IN_TUNNEL : limitation of seek lane width based on tunnel probability
  @c_switch_part   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing, and
  @c_switch_part   SLATE_CFG_SIMPLE_NAVI_INTERFACE : enable simple NAVI input data to FCT_SEN
  @c_switch_part   FCT_CFG_ROAD_INPUT : road estimation input to FCT
  @c_switch_part   LA_CFG_ADAPT_LANEWIDTH_BASED_ON_CAM : use of camera information for lane width detection
  @c_switch_part   LA_CFG_SEEK_LANE_WIDTH_USE_LANE_CLASS : seek lane width modification based on EM information
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component

  @pre             -
  @post            -

  @testmethod      Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         -

  @author          Christopher Knievel | christopher.knievel@continental-corporation.com | +49 (8382) 9699-399
*************************************************************************************************************************/
static float32 LA_f_CalcRelTraTrackwidthSeek( void )
{
  FIP_t_FusedRoadType iRoadTypeLevel_1;
  FIP_t_RoadWorks iRoadTypeLevel_2;
#if ((LA_CFG_LIMIT_SEEK_LANEWIDTH_BASED_ON_ROAD) && (FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING)) 
  FIP_t_LaneWidthSource t_LaneWidthSource = FIP_t_Get_LaneWidthSource();
  float32 f_LaneWidth = FIP_f_Get_LaneWidth();
#endif
#if ((FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING)&& (LA_CFG_SEEK_LANE_WIDTH_USE_LANE_CLASS))
  FIP_t_LaneWidthClass sLaneWidthClass = (pt_LAInput->pt_FIPLaneMatrix->t_FIPLaneWidthClass);
#endif /* END IF (FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING) */
#if ((FCT_CFG_INPUT_PREPROCESSSING) && (SLATE_CFG_SIMPLE_NAVI_INTERFACE) && (FCT_CFG_ROAD_INPUT))
  boolean bNaviMapIsAdasQual = (pt_LAInput->pt_FIPNaviData->b_NaviPathIsADASQuality);
  boolean bNaviPathInCityLimits = (pt_LAInput->pt_FIPNaviData->b_NaviPathIsInCityLimits);
#endif
  float32 fret;
  float32 fclasswid;

  /* First calculate lane width seek based on ego speed */
  fclasswid = dGDBmathLineareFunktion(&TRCK_Seek_LaneWidth_SpeedAdapted,(*pt_LAInput->t_RTE.pf_EgoVelObjSync));

#if (LA_CFG_SEEK_LANE_WIDTH_USE_LANE_CLASS)
  /* Modify lane class based on cam lane width */
#if ((LA_CFG_ADAPT_LANEWIDTH_BASED_ON_CAM) && (FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING))
  LA_v_ManipulateLaneClassBasedOnCam(&sLaneWidthClass);
#endif /* END IF ((LA_CFG_ADAPT_LANEWIDTH_BASED_ON_CAM) && (FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING)) */ 
#if (LA_CFG_LANE_WIDTH_CLASS_PlAUSIBLE)
  #if ((FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING)&& (LA_CFG_SEEK_LANE_WIDTH_USE_LANE_CLASS))
    pt_LAOutput->s_LaneWidthClass = sLaneWidthClass;
  #endif /* END IF (FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING) */
#endif /*END IF (LA_CFG_LANE_WIDTH_CLASS_PlAUSIBLE)*/
  /* Modify lane width seek based on lane class */
#if (FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING) 
  switch (sLaneWidthClass)
  {
  case FIP_LANE_WIDTH_CLASS_UNKNOWN:
  case FIP_LANE_WIDTH_CLASS_NORMAL:
    break;
  case FIP_LANE_WIDTH_CLASS_NARROW:
    /* Narrow lane width is typically detected on narrow roads such as
    the Brenner pass */
    fclasswid *= LA_SEEK_LANE_WIDTH_FACTOR_NARROW_LANE;
    break;
  case FIP_LANE_WIDTH_CLASS_MORE_NARROW:
    /* Narrower lane width is typically detected when roads are very narrow
    as in a construction site */
    fclasswid *= LA_SEEK_LANE_WIDTH_FACTOR_NARROWER_LANE;
    break;
  default:
    /* If no info available or normal width then assume highway widths, which are
    linearly mapped depending on ego speed (already calculated above) */
    break;
  }
#endif /* END IF (FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING) */ 
#endif /* END IF (LA_CFG_SEEK_LANE_WIDTH_USE_LANE_CLASS) */

#if (FCT_CFG_ROAD_INPUT)
  /* Next modify it based on road type */

#if (FCT_CFG_INPUT_PREPROCESSSING)
  iRoadTypeLevel_1 = (pt_LAInput->pt_FIPRoadType->t_FIPFusedRoadType);
  iRoadTypeLevel_2 = (pt_LAInput->pt_FIPRoadType->t_FIPRoadWorks);
#else
  iRoadTypeLevel_1 = FIP_ROAD_TYPE_UNKNOWN;
  iRoadTypeLevel_2 = FIP_NOINFO_ROADWORKS;
#endif /* FCT_CFG_INPUT_PREPROCESSSING */

  switch( iRoadTypeLevel_1 )
  {
    case FIP_ROAD_TYPE_CITY:
      /* ROADTYPE_MARKOV_CITY */
      fret = LA_CITYLANEWIDTHSEEK;
      break;

    case FIP_ROAD_TYPE_HIGHWAY:
      /* Use unchanged lane width */
      fret = fclasswid;
      break;

    default:
      /*  */
      fret = LA_STANDARDLANEWIDTHSEEK;
      break;
  }

#if ((FCT_CFG_INPUT_PREPROCESSSING) && (SLATE_CFG_SIMPLE_NAVI_INTERFACE))
  if((bNaviMapIsAdasQual == TRUE) &&(bNaviPathInCityLimits == TRUE))
  {
    fret = LA_CITYLANEWIDTHSEEK;
  }
#endif

#if LA_CFG_LIMIT_LANEWIDTH_IN_TUNNEL
#if (FCT_CFG_SIGNAL_PERF_MONITORING)
  if(*pt_LAInput->t_RTE.pf_TunnelProbability >= 0.5F)
  {
    fret = LA_TUNNEL_LANEWIDTHSEEK;
  }
#endif
#endif

  switch( iRoadTypeLevel_2 )
  {
    case FIP_ROADWORKS_DETECTED:
      if(iRoadTypeLevel_1 == FIP_ROAD_TYPE_HIGHWAY)
      {
        /* ROADTYPE_LEVEL2_ROADWORKS */
        fret = LA_ROADWORKSLANEWIDTHSEEK;
      }
      break;
    default:
      /* ROADTYPE_LEVEL2_NOINFO ROADTYPE_LEVEL2_TRAFFICJAM ROADTYPE_LEVEL2_ROADWORKS_JAM */
      break;
  }
#else
  fret = fclasswid;
  _PARAM_UNUSED(iRoadTypeLevel_1);
  _PARAM_UNUSED(iRoadTypeLevel_2);
#endif /* FCT_CFG_ROAD_INPUT */

#if ((LA_CFG_LIMIT_SEEK_LANEWIDTH_BASED_ON_ROAD) && (FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING)) 
  /* If road provides a valid lane width estimation (when source is not
  Source0, and within an acceptable range of
  [LA_ROADWORKSLANEWIDTHSEEK ... LA_STANDARDLANEWIDTHSEEK]) */
  if (((pt_LAInput->pt_FIPLaneMatrix->t_FIPLaneWidthSource) != FIP_SOURCE_0)
    &&((pt_LAInput->pt_FIPLaneMatrix->f_FIPLaneWidth) >= ROADWORKSLANEWIDTHSEEK)
    &&((pt_LAInput->pt_FIPLaneMatrix->f_FIPLaneWidth) <= STANDARDLANEWIDTHSEEK))
  {
    /* Calculate the maximum permitted seek width based on the lane width provided by road */
    const float32 fMaxLaneWidth = LA_PAR_SEEK_WIDTH_TO_CAM_LANE_WIDTH_TOLERANCE *((pt_LAInput->pt_FIPLaneMatrix->f_FIPLaneWidth));
    /* Calculate the minimum permitted seek width based on the lane width provided by road */
    const float32 fMinLaneWidth = (1.f / LA_PAR_SEEK_WIDTH_TO_CAM_LANE_WIDTH_TOLERANCE) * ((pt_LAInput->pt_FIPLaneMatrix->f_FIPLaneWidth));
    /* Clamp the returned lane width between the min-max just calculated */
    fret = MIN_FLOAT(fMaxLaneWidth, fret);
    fret = MAX_FLOAT(fMinLaneWidth, fret);
  }
#endif /* END IF ((LA_CFG_LIMIT_SEEK_LANEWIDTH_BASED_ON_ROAD) && (FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING)) */

  return fret;
}

/*************************************************************************************************************************
  Functionname:    LA_v_InitCorridorCritModule                                                            */ /*!

  @brief           Initialize global variables of this module

  @description     Initialize/reset global variables of this module

		@startuml
		Start
		Partition LA_v_InitCorridorCritModule {
		Repeat
			: Initialize Lane/Corridor Bracket in left and right position;
		Repeat While (For All Objects) 
		}
		End
		@enduml
  
  @return          -

  @param[in]       -
  @param[out]      -

  @glob_in         -
  @glob_out        -

  @c_switch_part   FCT_SIMU : FCT simulation specific function switch
  @c_switch_part   LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM : Move trace brackets in case of a lane change (camera lane interface), or
  @c_switch_part   LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM : Move trace brackets in case of no lane change (camera lane interface), or
  @c_switch_part   LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM : Move trace brackets in case of the blinker feature (camera lane interface)
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component

  @pre             -
  @post            -

  @testmethod      Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         -

  @author          Gergely Ungvary | gergely.ungvary@conti-engineering.com | +36-88-548-671
*************************************************************************************************************************/
static void LA_v_InitCorridorCritModule(void)
{
  uint8 uIndex = 0u;

#if ( LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM || \
      LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM || \
      LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM)

    LA_v_InitCorridorCamParameter();
    /* Initialize Debug variable */
#ifdef FCT_SIMU
    LA_v_InitDebugStruct();
#endif

#endif

  for (uIndex = 0u; uIndex < EM_N_OBJECTS; uIndex++)
  {
    a_BracketPositionArray[uIndex].BracketPositionLeft = 0.0f;
    a_BracketPositionArray[uIndex].BracketPositionRight = 0.0f;
  }
}

/*************************************************************************************************************************
  Functionname:    LA_f_CalcRelTraTrackwidthTrack                                                            */ /*!

  @brief           Get track lane width to use

  @description     Get the track lane width to use (i.e.: when already following object). This width depends on the 
                   road type and the ego velocity

		@startuml
		Start
		Partition LA_f_CalcRelTraTrackwidthTrack {
			If (check if Road is City road) then (yes)
				: Set track lane width as LA_CITYLANEWIDTHTRCK;
			Else if (Road is Highway) then (yes)
				: Calculate track lane width;
			Else (no)
				: Set track lane width as LA_STANDARDLANEWIDTHTRCK;
			Endif
			Partition #LightBlue "**~#if LA_CFG_LIMIT_LANEWIDTH_IN_TUNNEL && FCT_CFG_SIGNAL_PERF_MONITORING **” {
				If (Tunnel Probability >= 0.5) then (yes)
					: Set track lane width as LA_TUNNEL_LANEWIDTHTRCK;
				Endif 
			}
			If (Check if Road work is detected) then (yes)
				If (If Road is Highway) then (yes)
					: Set track lane width as LA_ROADWORKSLANEWIDTHTRCK;
				Endif
			Else (no)
				: Do Nothing;
			Endif
		}
		End
		@enduml

  @return          fret : the track lane width [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m

  @param[in]       -
  @param[out]      -

  @glob_in         pt_LAInput->t_RTE.pf_EgoVelObjSync : Ego velocity [-330.f ... 330.f] m/s 
  @glob_in         pt_LAInput->t_RTE.pf_TunnelProbability : Probability for a tunnel [0.0f ... 1.0f]
  @glob_in         pt_LAInput->pt_FIPRoadType->t_FusedRoadType : Reference to FIP road type [full range of FIP_t_FusedRoadType as in fip_ext.h]
  @glob_in         pt_LAInput->pt_FIPRoadType->t_RoadWorks : Reference to FIP road works type [full range of FIP_t_RoadWorks as in fip_ext.h]
  @glob_out        -

  @c_switch_part   LA_CFG_LIMIT_LANEWIDTH_IN_TUNNEL : limitation of seek lane width based on tunnel probability
  @c_switch_part   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing, and
  @c_switch_part   SLATE_CFG_SIMPLE_NAVI_INTERFACE : enable simple NAVI input data to FCT_SEN
  @c_switch_part   FCT_CFG_ROAD_INPUT : road estimation input to FCT
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component

  @pre             -
  @post            -

  @testmethod      Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         -

  @author          Christopher Knievel | christopher.knievel@continental-corporation.com | +49 (8382) 9699-399
*************************************************************************************************************************/
static float32 LA_f_CalcRelTraTrackwidthTrack(void)
{
  float32 fret;
#if (FCT_CFG_ROAD_INPUT)
  FIP_t_FusedRoadType iRoadTypeLevel_1;
  FIP_t_RoadWorks iRoadTypeLevel_2;
#endif /* END IF (EM_ROAD_INTFVER == 1) */

#if ((FCT_CFG_INPUT_PREPROCESSSING) && (SLATE_CFG_SIMPLE_NAVI_INTERFACE) && (FCT_CFG_ROAD_INPUT))
  boolean bNaviMapIsAdasQual = (pt_LAInput->pt_FIPNaviData->b_NaviPathIsADASQuality);
  boolean bNaviPathInCityLimits = (pt_LAInput->pt_FIPNaviData->b_NaviPathIsInCityLimits);
#endif

#if (FCT_CFG_ROAD_INPUT)

#if (FCT_CFG_INPUT_PREPROCESSSING)
  iRoadTypeLevel_1 = (pt_LAInput->pt_FIPRoadType->t_FIPFusedRoadType);
  iRoadTypeLevel_2 = (pt_LAInput->pt_FIPRoadType->t_FIPRoadWorks);
#else
  iRoadTypeLevel_1 = FIP_ROAD_TYPE_UNKNOWN;
  iRoadTypeLevel_2 = FIP_NOINFO_ROADWORKS;
#endif /* FCT_CFG_INPUT_PREPROCESSSING */

  switch( iRoadTypeLevel_1 )
  {
    case FIP_ROAD_TYPE_CITY:
      /* ROADTYPE_MARKOV_CITY */
      fret = LA_CITYLANEWIDTHTRCK;
      break;

    case FIP_ROAD_TYPE_HIGHWAY:
      fret = dGDBmathLineareFunktion(&TRCK_Seek_LaneWidth_SpeedAdapted,*pt_LAInput->t_RTE.pf_EgoVelObjSync);
      fret += dGDBmathLineareFunktion(&TRCK_Track_Offset_SpeedAdapted,*pt_LAInput->t_RTE.pf_EgoVelObjSync);
      #if (LA_CFG_LANE_WIDTH_CLASS_PlAUSIBLE)
        #if ((FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING)&& (LA_CFG_SEEK_LANE_WIDTH_USE_LANE_CLASS))
          if(pt_LAOutput->s_LaneWidthClass == FIP_LANE_WIDTH_CLASS_NARROW)
          {
            fret *= LA_SEEK_LANE_WIDTH_FACTOR_NARROW_LANE;
          }
          else if(pt_LAOutput->s_LaneWidthClass == FIP_LANE_WIDTH_CLASS_MORE_NARROW)
          {
            fret *= LA_SEEK_LANE_WIDTH_FACTOR_NARROWER_LANE;
          }
          else
          {
          }
        #endif /* END IF ((FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING)&& (LA_CFG_SEEK_LANE_WIDTH_USE_LANE_CLASS)) */
      #endif /* END IF (LA_CFG_LANE_WIDTH_CLASS_PlAUSIBLE) */
      break;

    default:
      /* ROADTYPE_MARKOV_NOINFO ROADTYPE_MARKOV_COUNTRYROAD */
      fret = LA_STANDARDLANEWIDTHTRCK;
      break;
  }

#if ((FCT_CFG_INPUT_PREPROCESSSING) && (SLATE_CFG_SIMPLE_NAVI_INTERFACE))
  if((bNaviMapIsAdasQual == TRUE) &&(bNaviPathInCityLimits == TRUE))
  {
    fret = LA_CITYLANEWIDTHTRCK;
  }
#endif

#if LA_CFG_LIMIT_LANEWIDTH_IN_TUNNEL
#if (FCT_CFG_SIGNAL_PERF_MONITORING)
  if(*pt_LAInput->t_RTE.pf_TunnelProbability >= 0.5F)
  {
    fret = LA_TUNNEL_LANEWIDTHTRCK;
  }
#endif
#endif

  switch( iRoadTypeLevel_2 )
  {
    case FIP_ROADWORKS_DETECTED:
      if(iRoadTypeLevel_1 == FIP_ROAD_TYPE_HIGHWAY)
      {
        /* ROADTYPE_LEVEL2_ROADWORKS */
        fret = LA_ROADWORKSLANEWIDTHTRCK;
      }
      break;
    default:
      /* ROADTYPE_LEVEL2_NOINFO ROADTYPE_LEVEL2_TRAFFICJAM ROADTYPE_LEVEL2_ROADWORKS_JAM */
      break;
  }
#else
  /* No road available : assume default highway widths */
  fret = dGDBmathLineareFunktion(&TRCK_Seek_LaneWidth_SpeedAdapted,*pt_LAInput->t_RTE.pf_EgoVelObjSync);
  fret += dGDBmathLineareFunktion(&TRCK_Track_Offset_SpeedAdapted,*pt_LAInput->t_RTE.pf_EgoVelObjSync);
#endif /* FCT_CFG_ROAD_INPUT */

  return fret;
}

/*************************************************************************************************************************
  Functionname:    LA_v_InitCriteriaMatrix                                                            */ /*!

  @brief           Initialize lane assignment criteria matrix

  @description     Initialize the lane assignment criteria matrix

		@startuml
		Start
		Partition LA_v_InitCriteriaMatrix {
		: Set Criteria define track bracket expansion of left and right brackets as 0; 
		Note Left: based on\n1.) Relevant Object \n2.) Object Approximation \n3.) Curve Outer border \n4.) High speed approach \n5.) High Tunnel Probability;
		: Set Criteria define track bracket restriction of left brackets as INITVALUE_BRACKETPOSITION and right brackets as - INITVALUE_BRACKETPOSITION; 
		Note Left: based on \n1.) Target Outside Brackets \n2.) Analog Road Border \n3.) Neighborhood Relevant Object \n4.) Object Trace \n5.) Stationary Objects on neighboring lanes \n6.) the near range for country road /city scenarios;
		: Set Criteria define track bracket Extension of left brackets as -INITVALUE_BRACKETPOSITION and right brackets as INITVALUE_BRACKETPOSITION;
		Note Left: based on \n1.) Road Border \n2.) Curve Inner Border \n3.) Road Border CI \n4.) Follow Object Into Curve \n5.) Guard Rail Road Border \n6.) Blocked Obstacle Corridor;
		: Set Criteria define track bracket of left and right brackets as 0; 
		Note Left: based on\n1.) Base Corridor \n2.) Final Brackets Positions; 
		}
		End
		@enduml
  
  @return          -

  @param[in]       pCriteriaMatrix : pointer to the criteria matrix to be initialized [LA_t_CriteriaMatrix as defined in corridor_crit.h]
  @param[out]      pCriteriaMatrix : pointer to the initialized criteria matrix [LA_t_CriteriaMatrix as defined in corridor_crit.h]

  @glob_in         pt_LAInput->t_RTE.pf_EgoVelObjSync : Ego velocity [-330.f ... 330.f] m/s 
  @glob_out        -

  @c_switch_part   LA_CFG_EXT_RELEVANT_OBJECT : relevant object extension
  @c_switch_part   LA_CFG_EXT_HIGHSPEED_APPROACH : bracket extension used for high speed approaches
  @c_switch_part   LA_CFG_ADD_EXT_TUNNEL_PROB : bracket extension used for improved robustness against drop-outs in tunnels
  @c_switch_part   LA_CFG_EXT_NEIGHBORHOOD_REL_OBJ : bracket extension for situations in which relevant object moves in the direction of a near neighboring 
  @c_switch_part   LA_CFG_ADD_RESTRICTION_OBJ_TRACE : enable restriction based on relevant object trace
  @c_switch_part   LA_CFG_EXT_LOWSPEEDFUSEDBRD : Extend trace brackets for low ego velocities and missing adjacent lanes
  @c_switch_part   LA_CFG_ADD_RESTRICTION_STATOBJ_NEXTLANE : enable restriction based on stationary objects in next lane
  @c_switch_part   LA_CFG_RESTRICTION_CITY_NEAR_RANGE : enable a restriction in the near range for country road /city scenarios
  @c_switch_part   FCT_CFG_ROAD_INPUT : Road estimation input to FCT
  @c_switch_part   LA_CFG_NAVI_COUNTRYROAD_EXTENSION : trace bracket extension on country roads (based on NAVI information)
  @c_switch_part   LA_CFG_CAM_LANE_OBJ_ASSOC_EXTENSION : enable corridor extension based on camera lane object association
  @c_switch_part   LA_CFG_BLOCKED_OBSTACLE_EXTENSION : extension for the blocked path between an object and an obstacle
  @c_switch_part   LA_CFG_NAVI_OBJ_CLOSE_TO_EXIT_RESTRICTION : trace bracket restriction close to an exit (based on navi information)
  @c_switch_part   LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM : Move trace brackets in case of a lane change (camera lane interface), or
  @c_switch_part   LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM : Move trace brackets in case of no lane change (camera lane interface), or
  @c_switch_part   LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM : Move trace brackets in case of the blinker feature (camera lane interface)
  @c_switch_part   SIT_CFG_OBJECT_SCORING : enable object scoring module
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

  @author          Norman Apel | norman.apel@continental-corporation.com | +49 (8382) 9699-365
*************************************************************************************************************************/
static void LA_v_InitCriteriaMatrix (LA_t_CriteriaMatrix * const pCriteriaMatrix)
{
  /*! Kriterien legen Spurklammererweiterung oder -beschränkung basierend auf bisheriger Position fest */
#if (LA_CFG_EXT_RELEVANT_OBJECT)
  LA_v_RelTraInitCriteriaOutput( &(pCriteriaMatrix->AddExtensionRelevantObject), DEFAULT_MODE );             /*!< VorbeifahrtRelObjekt */
#endif
  LA_v_RelTraInitCriteriaOutput( &(pCriteriaMatrix->AddExtensionObjectApproximation), DEFAULT_MODE );        /*!< Approx */
  LA_v_RelTraInitCriteriaOutput( &(pCriteriaMatrix->AddRestrictionCurveOuterBorder), DEFAULT_MODE );         /*!< KurveAussenrand */
#if (LA_CFG_EXT_HIGHSPEED_APPROACH) || (LA_CFG_O2O_EGO_LANE_ASSOC_BRACKET_EXTENSION)
  LA_v_RelTraInitCriteriaOutput(&(pCriteriaMatrix->AddExtensionHighspeedApproach), DEFAULT_MODE);            /*!< Highspeed approaches */
#endif
#if (LA_CFG_ADD_EXT_TUNNEL_PROB)
  LA_v_RelTraInitCriteriaOutput(&(pCriteriaMatrix->AddExtensionHighTunnelProb), DEFAULT_MODE);            /*!< Highspeed approaches */
#endif

  /*! Kriterien legen neue Spurklammerposition fest */
  LA_v_RelTraInitCriteriaOutput( &(pCriteriaMatrix->RestrictionTargetOutsideBrackets), RESTRICTION_MODE );   /*!< ZielAblage */
  LA_v_RelTraInitCriteriaOutput( &(pCriteriaMatrix->RestrictionAnalogRoadBorder), RESTRICTION_MODE );        /*!< AnalogerStrassenrand */
  LA_v_RelTraInitCriteriaOutput( &(pCriteriaMatrix->RestrictionNeighbourhoodRelObj), RESTRICTION_MODE );     /*!< UmfeldRelevantesObjekt */
#if (LA_CFG_EXT_NEIGHBORHOOD_REL_OBJ)
  LA_v_RelTraInitCriteriaOutput( &(pCriteriaMatrix->ExtensionNeighbourhoodRelObj), EXTENSION_MODE );         /*!< Extension for nearby neighboring objects */
#endif
#if (LA_CFG_ADD_RESTRICTION_OBJ_TRACE)
  LA_v_RelTraInitCriteriaOutput( &(pCriteriaMatrix->RestrictionObjectTrace), RESTRICTION_MODE);              /*!< Restriction based on object trace */
#endif
#if (LA_CFG_EXT_LOWSPEEDFUSEDBRD)
  LA_v_RelTraInitCriteriaOutput(&(pCriteriaMatrix->AddExtensionLowSpeedFusedBrd),EXTENSION_MODE);            /*!< Low speed short range extension */
#endif

#if (LA_CFG_ADD_RESTRICTION_STATOBJ_NEXTLANE)
  LA_v_RelTraInitCriteriaOutput( &(pCriteriaMatrix->AddRestrictionStatObjNextLane), RESTRICTION_MODE);        /*!< Restriction for stationary objects on neighboring lanes */
#endif

#if (LA_CFG_RESTRICTION_EGO_LANE_CHANGE)
  LA_v_RelTraInitCriteriaOutput( &(pCriteriaMatrix->AddRestrictionEgoLaneChange), RESTRICTION_MODE);          /*!< Restriction for Ego Lane Change */
#endif

#if (LA_CFG_RESTRICTION_CITY_NEAR_RANGE)
  LA_v_RelTraInitCriteriaOutput( &(pCriteriaMatrix->RestrictionCityNearRange), RESTRICTION_MODE);            /*!< Restriction in the near range for country road /city scenarios */
#endif
  LA_v_RelTraInitCriteriaOutput( &(pCriteriaMatrix->ExtensionRoadBorder), EXTENSION_MODE );                  /*!< Richtungsfahrspuren */
  LA_v_RelTraInitCriteriaOutput( &(pCriteriaMatrix->ExtensionCurveInnerBorder), EXTENSION_MODE );            /*!< KurveInnenrand */
  LA_v_RelTraInitCriteriaOutput( &(pCriteriaMatrix->ExtensionRoadBorderCI), EXTENSION_MODE );                /*!< RIchtungsfahrspurenKI */
  LA_v_RelTraInitCriteriaOutput( &(pCriteriaMatrix->ExtensionFollowObjectIntoCurve), EXTENSION_MODE );       /*!< ObjektWinkelVerfolgung */
#if (FCT_CFG_ROAD_INPUT)
  LA_v_RelTraInitCriteriaOutput( &(pCriteriaMatrix->ExtensionGuardRailRoadBorder), EXTENSION_MODE );         /*!< GuardRailRoadBorder */
#endif /* FCT_CFG_ROAD_INPUT */
#if (LA_CFG_NAVI_COUNTRYROAD_EXTENSION)
  LA_v_RelTraInitCriteriaOutput( &(pCriteriaMatrix->ExtensionNaviCountryroad), EXTENSION_MODE );             /*!< Country road extension based on navi info */
#endif
#if (LA_CFG_CAM_LANE_OBJ_ASSOC_EXTENSION)
  LA_v_RelTraInitCriteriaOutput( &(pCriteriaMatrix->ExtensionCamLaneObjAssoc), EXTENSION_MODE );
#endif
#if (LA_CFG_BLOCKED_OBSTACLE_EXTENSION)
  LA_v_RelTraInitCriteriaOutput( &(pCriteriaMatrix->ExtensionBlockedObstacleCorridor), EXTENSION_MODE );
#endif
#if (LA_CFG_EXT_PARALLEL_LANE_CHANGE)
  LA_v_RelTraInitCriteriaOutput( &(pCriteriaMatrix->ExtensionParallelLaneChange), EXTENSION_MODE );
#endif /* (LA_CFG_EXT_PARALLEL_LANE_CHANGE) */
#if(LA_CFG_NAVI_OBJ_CLOSE_TO_EXIT_RESTRICTION)
    LA_v_RelTraInitCriteriaOutput( &(pCriteriaMatrix->RestrictionNaviObjCloseToExit), RESTRICTION_MODE );    /*!< Restriction of trace bracket if object close to exit based on navi information */
#endif

  /*! Initialization: Adaption trace brackets based on in-lane position of ego-vehicle (camera information), object specific variable */
#if ( LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM || \
      LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM || \
      LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM )
  LA_v_RelTraInitCriteriaOutputScale( &(pCriteriaMatrix->RatioEgoPositionInLaneCam));                        /*!< RatioEgoPositionInLaneCam */
#endif

#if (SIT_CFG_OBJECT_SCORING)
  LA_v_RelTraInitCriteriaOutput( &(pCriteriaMatrix->ExtensionObjScoring), EXTENSION_MODE );                  /*!< Scoring extensions */
#endif

  LA_v_RelTraInitCriteriaOutput( &(pCriteriaMatrix->BaseCorridor), DEFAULT_MODE );
  LA_v_RelTraInitCriteriaOutput( &(pCriteriaMatrix->FinalBracketPositions), DEFAULT_MODE );
}
/*PRQA S 2013,2016 EMPTY_ELSE_OR_DEFAULT*/
/* date: 2019-07-28, reviewer:Prabhu Sundaramurthy, reason: Empty else or default, no effect on functionality*/
/*************************************************************************************************************************
  Functionname:    LA_v_RelTraInitCriteriaOutput                                                            */ /*!

  @brief           Initialize one criteria result bracket

  @description     Initialize one criteria result bracket
  
		@startuml
		Start
		Partition LA_v_RelTraInitCriteriaOutput {
			If (Check if Mode of initialization of bracket is RESTRICTION_MODE) then (yes)
				: Set Left side Bracket as INITVALUE_BRACKETPOSITION;
				: Set Right side Bracket as -INITVALUE_BRACKETPOSITION;
			Else if (Check if Mode of initialization of bracket is EXTENSION_MODE) then (yes)
				: Set Left side Bracket as -INITVALUE_BRACKETPOSITION;
				: Set Right side Bracket as INITVALUE_BRACKETPOSITION;
			Else if (Check if Mode of initialization of bracket is DEFAULT_MODE) then (yes)
				: Set Left side Bracket as 0;
				: Set Right side Bracket as 0;
			Else (no)
				: Set Left side Bracket as 0;
				: Set Right side Bracket as 0;
			Endif
		}
		End
		@enduml  
  
  @return          -

  @param[in]       eMode : mode of initialization of the bracket [LA_t_TraceBracketMode]
  @param[out]      pOutput : pointer to the trace bracket to initialize [LA_t_BracketOutput as defined in si_corridor_crit.h]
                    pOutput->BracketPositionLeft [-INITVALUE_BRACKETPOSITION, 0.f, INITVALUE_BRACKETPOSITION]
                            with INITVALUE_BRACKETPOSITION as defined in si_corridor_crit.h
                    pOutput->BracketPositionRight [-INITVALUE_BRACKETPOSITION, 0.f, INITVALUE_BRACKETPOSITION]
                            with INITVALUE_BRACKETPOSITION as defined in si_corridor_crit.h

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

  @author          Christopher Knievel | christopher.knievel@continental-corporation.com | +49 (8382) 9699-399
*************************************************************************************************************************/
static void LA_v_RelTraInitCriteriaOutput (LA_t_BracketOutput *const pOutput, const LA_t_TraceBracketMode eMode)
{
  switch (eMode)
  {
    case RESTRICTION_MODE:
      pOutput->BracketPositionLeft  =   INITVALUE_BRACKETPOSITION;
      pOutput->BracketPositionRight =  -INITVALUE_BRACKETPOSITION;
      break;

    case EXTENSION_MODE:
      pOutput->BracketPositionLeft  =  -INITVALUE_BRACKETPOSITION;
      pOutput->BracketPositionRight =   INITVALUE_BRACKETPOSITION;
      break;

    case DEFAULT_MODE:
    default:
      pOutput->BracketPositionLeft  = 0.F;
      pOutput->BracketPositionRight = 0.F;
      break;
  }
}

/*************************************************************************************************************************
  Functionname:    LA_v_CorridorObjInit                                                            */ /*!

  @brief           Initialize the corridor object passed

  @description     Initialize (reset) the corridor object passed
  
		@startuml
		Start
		Partition LA_v_CorridorObjInit {
		: Set timer for relevancy as 0;
		: Set timer for non-relevancy as 0;
		: Set Target Fusion Hold Time as 0;
		: Set counter flag for object being held over steering speed as 0;
		: Set Maximal allowed deviation to left from ideal trajectory as -INITVALUE_BRACKETPOSITION;
		: Set Maximal allowed deviation to right from ideal trajectory as INITVALUE_BRACKETPOSITION;
		: Set Factor for widening seek lane width to relevant object track lane width as 0;
		: Initialize lane assignment criteria matrix;
		}
		End
		@enduml  
  
  @return          -

  @param[in]       eMode : mode of initialization of the bracket [LA_t_TraceBracketMode]
  @param[out]      pObjCor : pointer to the corridor object to reset [LA_t_ObjCorridor as defined in si_corridor_crit.h]
                    pObjCor->dRelevantZeit : timer for relevancy [0.0F]
                    pObjCor->dNichtRelevantZeit : timer for non-relevancy [0.0F]
                    pObjCor->fTargetFusionHoldTime [0.0F]
                    pObjCor->TrckFahr.iLwFolge : counter flag for object being held over steering speed [0]
                    pObjCor->TrckFahr.dAblage_SpurGrenze_L [INITVALUE_BRACKETPOSITION]
                            with INITVALUE_BRACKETPOSITION as defined in si_corridor_crit.h
                    pObjCor->TrckFahr.dAblage_SpurGrenze_R [INITVALUE_BRACKETPOSITION]
                            with INITVALUE_BRACKETPOSITION as defined in si_corridor_crit.h
                    pObjCor->TrckFahr.dRelSpurErweiterungsFaktor [0.0F]
                    pObjCor->TrckFahr.dRelSpurAbstandErweitFaktor [0.0F]
                    pObjCor->ObjCriteriaMatrix [LA_t_CriteriaMatrix as defined in corridor_crit.h]

  @glob_in         -
  @glob_out        -

  @c_switch_part   LA_CFG_EXT_RELEVANT_OBJECT :  Configuration switch to enable/disable relevant object extension
  @c_switch_part   FCT_SIMU : FCT simulation specific function switch
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

  @author          Christopher Knievel | christopher.knievel@continental-corporation.com | +49 (8382) 9699-399
*************************************************************************************************************************/
void LA_v_CorridorObjInit(LA_t_ObjCorridor * const pObjCor)
{
  pObjCor->dRelevantZeit = 0.0F;
  pObjCor->dNichtRelevantZeit = 0.0F;
#if (LA_CFG_EXT_RELEVANT_OBJECT)
  pObjCor->fTargetFusionHoldTime   = 0.0F;
#endif

  pObjCor->TrckFahr.iLwFolge = 0;
  pObjCor->TrckFahr.dAblage_SpurGrenze_L = -INITVALUE_BRACKETPOSITION;
  pObjCor->TrckFahr.dAblage_SpurGrenze_R = INITVALUE_BRACKETPOSITION;

  pObjCor->TrckFahr.dRelSpurErweiterungsFaktor  = 0.0F;
  pObjCor->TrckFahr.dRelSpurAbstandErweitFaktor = 0.0F;

#ifdef FCT_SIMU
  LA_v_InitCriteriaMatrix(&pObjCor->ObjCriteriaMatrix);
#endif
}

/*************************************************************************************************************************
  Functionname:    LA_t_CalculateBracketsForCurrentObject                                                            */ /*!

  @brief           Calculate brackets for current object

  @description     Criteria matrix is initialized for the current cycle for the given object. The corridor bracket enable flags are checked.
                   Various criteria for extensions and restrictions for corridor are evaluated and final corridors are computed. 
                   In case of relevant objects loss, corridors are recalculated with consideration of its previous cycle information.

		@startuml
		Start
		Partition LA_t_CalculateBracketsForCurrentObject {
		: Initialize lane assignment criteria matrix;
		: Construct object variables from corridor criteria persistent struct;
		: Enable all corridor bracket functions;
		: Call to custom preprocessing which allows to enable and disable selected corridor bracket functions;
		: Calculation of priority and default bracket functions;
		: Determine final bracket positions given all calculated extensions and restrictions;
		If (check if previously relevant object is lost now and Object Stack Cycle is not in Ego Lane) then (yes)
			: Recalculates the trace brackets with an alternative trajectory;
		Endif
		: Copy from corridor object data to persistent struct;
		: Update Object criteria Matrix;
		: return final bracket positions for current object;
		}
		End
		@enduml

  
  @return          BracketFuncResults.FinalBracketPositions : Final bracket positions for current object [SIBracketOutput_tas defined in si_corridor_crit.h]

  @param[in]       ObjNr : internal object number (Object ID) of a valid object [0 ... EM_N_OBJECTS[
                           with EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @param[in]       pObjectProperties : Pointer to input object properties [LA_t_RelTraObjInput as defined in si_corridor_crit.h]
                    pObjectProperties->iObjNr : Object number [-1 ... EM_N_OBJECTS-1]
                    pObjectProperties->iRelevant : If the given object is relevant or not [TRUE, FALSE]
  @param[in]       pTrajectory : Pointer to trajectory parameters [LA_t_RelTraCurve as defined in si_corridor_crit.h]
  @param[in,out]   pEnvironment : pointer to structure of type LA_t_AssTraEnvironment, containing lane matrix information. Defined in si_corridor_crit.h
                     pEnvironment->f_EgoObjPathDiffAvg : Difference between EGO path and relevant object trace. Defined in si_corridor_crit.h [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                     pEnvironment->f_SATrajObjPathDiffAvg : Difference between ACC trajectory and relevant object trace. Defined in si_ext.h [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @param[in,out]   pCritMatrixAllObj : Pointer to bracket modifications equal for all objects [LA_t_CriteriaMatrixAllObj as defined in si_corridor_crit.h]
                    pBracketFuncResults->RatioEgoPositionInLaneCam : Struct to describe the lane change for the trace bracket adaption based on the ego position in lane
                           [SIScaleBracketOutput_t as defined in si_criteria_crit.h]

  @glob_in         pt_LAOutput->t_LAObjOutputList[i].ObjCor : object specific corridor information [LA_t_ObjCorridor as defined in si_corridor_crit.h]
                           with i in [0 ... EM_N_OBJECTS[ and EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
                    pt_LAOutput->t_LAObjOutputList[i].ObjCor.ObjCriteriaMatrix : stores results of bracket functions for debugging [LA_t_CriteriaMatrix as defined in si_corridor_crit.h]
                           with i in [0 ... EM_N_OBJECTS[ and EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @glob_in         pt_LAOutput->t_LAObjOutputList[i].f_EgoObjPathDiffAvg : Difference between EGO path and relevant object trace. Defined in si_corridor_crit.h [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                           with i in [0 ... EM_N_OBJECTS[ and EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @glob_in         pt_LAOutput->t_LAObjOutputList[i].f_SATrajObjPathDiffAvg : Difference between ACC trajectory and relevant object trace. Defined in si_ext.h [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                           with i in [0 ... EM_N_OBJECTS[ and EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @glob_out        LACritMatrixAllObjDebug.CriteriaMatrixAllObj : criteria matrix information for debugging [LA_t_CriteriaMatrixAllObj as defined in si_corridor_crit.h]

  @c_switch_part   OUT_CFG_CUSTOM_CRITERIA_MATRIX_PROCESSING : activating additional call to custom LA_b_CustProcessCriteriaMatrix
  @c_switch_part   LA_CFG_ADD_RESTRICTION_OBJ_TRACE : enable restriction based on relevant object trace
  @c_switch_part   LA_CFG_CUSTOM_CORRIDOR_PREPROCESSING :  allows to enable or disable selected corridor bracket functions
  @c_switch_part   LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM : Move trace brackets in case of a lane change (camera lane interface), or
  @c_switch_part   LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM : Move trace brackets in case of no lane change (camera lane interface), or
  @c_switch_part   LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM : Move trace brackets in case of the blinker feature (camera lane interface)
  @c_switch_part   FCT_SIMU : FCT simulation specific function switch
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

  @author          Christopher Knievel | christopher.knievel@continental-corporation.com | +49 (8382) 9699-399
*************************************************************************************************************************/
static LA_t_BracketOutput LA_t_CalculateBracketsForCurrentObject(const ObjNumber_t ObjNr, LA_t_RelTraObjInput* const pObjectProperties, const  LA_t_RelTraCurve* const pTrajectory, 
                                                             LA_t_AssTraEnvironment* const pEnvironment, const LA_t_CriteriaMatrixAllObj* const pCritMatrixAllObj)
{
#if (OUT_CFG_CUSTOM_CRITERIA_MATRIX_PROCESSING)
  boolean b_CustomCriteriaProcessing;
#endif
  LA_t_CriteriaMatrix    BracketFuncResults;
  LA_t_RelTraObjOutput     ObjectVariables;
  LA_t_BracketFuncEnable BracketFuncEnableFlags;

#if (OUT_CFG_CUSTOM_CRITERIA_MATRIX_PROCESSING)
  b_CustomCriteriaProcessing = FALSE;     /* Init value */
#endif

  /* Initialize lane assignment criteria matrix */
  LA_v_InitCriteriaMatrix(&BracketFuncResults);

  /* Construct object variables from corridor criteria persistent struct */
  LA_v_ConstructObjectVariables(ObjNr, &ObjectVariables);

  /* Enable all corridor bracket functions */
  LA_v_EnableAllBracketFunctions(&BracketFuncEnableFlags);

#if (LA_CFG_CUSTOM_CORRIDOR_PREPROCESSING)
  /* Call to custom preprocessing which allows to enable and disable
     selected corridor bracket functions*/
  LA_v_CustomCorridorPreProcessing(ObjNr, &BracketFuncEnableFlags);
#endif

  /* Fill the entire CriteriaMatrix for the current object, the Matrix also contains the (preliminary) final bracket positions,
     Usually this will also be the final result, except for the special case of recalculation with fast trajectory and custom matrix processing. */
  /* This is the 'main' part in determining the corridor bracket positions .. */
  LA_v_EvaluateBracketFunctions(pObjectProperties, &ObjectVariables, pTrajectory, pEnvironment, &BracketFuncResults, &BracketFuncEnableFlags, pCritMatrixAllObj);

  /* Determine final bracket positions given all calculated extensions and restrictions */
  LA_v_DetermineFinalBracketPositions(pObjectProperties, &ObjectVariables, &BracketFuncResults);

  /* In case the previously relevant object is lost now, the corridor is re-calculated
     with a VDY-only trajectory. */
  if ( (pObjectProperties->iRelevant == (ubit8_t)TRUE ) && (ObjectVariables.iObjektSpur_Zyklus != ASSOC_LANE_EGO) )
  {
    LA_v_RecalculateBracketsUsingAlternativeTrajectory(ObjNr, pObjectProperties, &ObjectVariables, pEnvironment, &BracketFuncResults, &BracketFuncEnableFlags, pCritMatrixAllObj);
  }

  /* write back variable object properties to global variables,
     fFusionTargetHoldTime is accessed via AssTraEnvironment.fRelObjTargetFusionHoldTime in in RestrictNeighbourhoodRelObj,
     also needed to save iLwFolge value for next cycle for ExtensionFollowObjectIntoCurve,
     also needs dAblage_SpurGrenze_L/R values from last cycle in ExtensionsCurveInnerBorder and ExtensionRoadBorder */
  LA_v_RelTraObjOutputToObject( &ObjectVariables , &pt_LAOutput->t_LAObjOutputList[ObjNr].ObjCor );

#if (OUT_CFG_CUSTOM_CRITERIA_MATRIX_PROCESSING)
  /* custom processing of criteria matrix */
  /* Call custom processing function to modify criteria matrix as needed */
  /* Hint: Set CriteriaMatrix.EvaluationMode to SKIP_EVALUATION to directly supply the final bracket positions */
  /* TODO b_CustomCriteriaProcessing is always FALSE in ARS4B0, need to be checked in other projects and if not necessary, removed. */
  b_CustomCriteriaProcessing = LA_b_CustProcessCriteriaMatrix(pObjectProperties->iObjNr, &BracketFuncResults);
  if (b_CustomCriteriaProcessing == TRUE)
  {
    /* In case brackets were modified, set them again */
    LA_v_DetermineFinalBracketPositions(pObjectProperties, &ObjectVariables, &BracketFuncResults);
  }
#endif

  /* freeze CriteriaMatrix for simulation */
#ifdef FCT_SIMU
  pt_LAOutput->t_LAObjOutputList[pObjectProperties->iObjNr].ObjCor.ObjCriteriaMatrix = BracketFuncResults;

  /* Adaption trace brackets based on inlane position of ego-vehicle (camera information) */
  #if ( LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM || \
        LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM || \
        LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM )
    if (pCritMatrixAllObj->RatioEgoPositionInLaneCam.fScaleBracketLeft < LA_BRACKETPOS_VALID_VAL_COMPARE)
   {
      LACritMatrixAllObjDebug.CriteriaMatrixAllObj = (*pCritMatrixAllObj);
      (void) MEASFreezeDataMTS(&LACritMatAllObjMeasInfo, &LACritMatrixAllObjDebug, NULL);
  }
  else
  {
    if(pObjectProperties->iObjNr == 0)
    {
      LACritMatrixAllObjDebug.CriteriaMatrixAllObj = (*pCritMatrixAllObj);
      (void) MEASFreezeDataMTS(&LACritMatAllObjMeasInfo, &LACritMatrixAllObjDebug, NULL);
    }
  }
  #endif
#endif

  /* return final bracket positions for current object */
  return BracketFuncResults.FinalBracketPositions;
}

/*************************************************************************************************************************
  Functionname:    LA_v_AdjustObjectPropertiesToTrajectory                                                            */ /*!

  @brief           Adjust object properties to trajectory

  @description     Based on iOWVflag (criteria) the distance of the object to ACC trajectory or EGO course is computed and updated in dAblage_Radius

		@startuml
		Start
		Partition LA_v_AdjustObjectPropertiesToTrajectory {
		If (check if trajectory hypothesis is LA_OWVKRIT_AKTIV) then (yes)
			: Get trajectory reference point;
			: Compute dAblage_Radius with ACC Trajectory as reference;
		Else if (check if trajectory hypothesis is LA_OWVKRIT_INAKTIV) then (yes)
			: Calculates the distance to trajectory;
			: Compute dAblage_Radius with Ego Course as reference;
		Else (no)
			: Do Nothing;
		Endif
		}
		End
		@enduml
  
  @return          -

  @param[in]       pTrajectory : Pointer to trajectory parameters [LA_t_RelTraCurve as defined in si_corridor_crit.h]
                    pTrajectory->iOWVflag : Flag describing which trajectory hypothesis is considered [0L, 1L as defined in si_corridor_crit.h]
                    pTrajectory->dCurve : Curvature of considered trajectory for trace bracket calculation [-1.f ... 1.f]
  @param[in]       pTrajectoryData : Auxiliary trajectory information [CP_t_TrajectoryData as defined in cp_ext.h]
                    pTrajData->State.EgoCourseOnly  : Bit field which indicates whether the ACC trajectory is based only on the
                     VDY trajectory [data type ubit16_t with range [0,1] as defined in cp_ext.h]
                    pTrajectoryData->Current : rajectory data from the current cycle [CP_GDBTrajectoryData]
  @param[in]       pObjectProperties : Pointer to input object properties [LA_t_RelTraObjInput as defined in si_corridor_crit.h]
                    pObjectProperties->dAbst_mittel [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                    pObjectProperties->dAblage_m [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @param[out]      pObjectProperties->dAblage_Radius [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m

  @glob_in         FCT_fBumperToCoG : distance of bumper to center of gravity [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
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

  @author          Christopher Knievel | christopher.knievel@continental-corporation.com | +49 (8382) 9699-399
*************************************************************************************************************************/
static void LA_v_AdjustObjectPropertiesToTrajectory(LA_t_RelTraObjInput* const pObjectProperties, const LA_t_RelTraCurve* const pTrajectory)
{  
  if (pTrajectory->iOWVflag == LA_OWVKRIT_AKTIV) /* USE ACC Trajectory */
  {
    CAL_t_TrajRefPoint    TrajRefPoint;
    /* dAblage_Radius is computed with ACC trajectory as reference */
    LA_v_CalculateDistance2Traj((pObjectProperties->dAbst_mittel+FCT_fBumperToCoG), pObjectProperties->dAblage_m, (boolean)pt_LAInput->t_CP.pt_TrajectoryData->State.EgoCourseOnly, &pt_LAInput->t_CP.pt_TrajectoryData->Current, &TrajRefPoint);
    pObjectProperties->dAblage_Radius = TrajRefPoint.fY;
  }
  else if (pTrajectory->iOWVflag == LA_OWVKRIT_INAKTIV) /* USE EGO Course */
  {
    CAL_t_TrajRefPoint    TrajRefPoint;
    /* dAblage_Radius is computed with EGO-Course as reference */
    TrajRefPoint            = CAL_t_CalculateDistancePoint2Circle((pObjectProperties->dAbst_mittel+FCT_fBumperToCoG), pObjectProperties->dAblage_m, pTrajectory->dCurve);
    pObjectProperties->dAblage_Radius = TrajRefPoint.fY;
  }
  else
  {
    
  }
}

/*************************************************************************************************************************
  Functionname:    LA_v_ConstructObjectVariables                                                            */ /*!

  @brief           Copy object data from corridor criteria persistent struct

  @description     Copy persistent object data from corridor criteria structure to LA_t_RelTraObjOutput structure. 
                   The main goal of this function is load data from persistent storage to the larger internally
                   used criteria struct, that only exists temporarily on stack. See also function LA_v_RelTraObjOutputToObject 

		@startuml
		Start
		Partition LA_v_ConstructObjectVariables {
		: Update counter flag for object being held over steering speed and Preliminary lane association;
		: Update Temporary storage of trace-bracket position for left-hand side and right-hand side as 0;
		: Update target hold time for relevant object extension;
		}
		End
		@enduml

  @return          -

  @param[in]       ObjNr : internal object number (Object ID) of a valid object [0 ... EM_N_OBJECTS[
                           with EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @param[out]      pRelTraObj : Pointer to an LA_t_RelTraObjOutput type structure [LA_t_RelTraObjOutput as defined in si_corridor_crit.h]
                    pRelTraObj->iObjektSpur_Zyklus : Preliminary lane association [ASSOC_LANE_RIGHT as defined in Rte_SWCEmAdapt_Type.h]
                    pRelTraObj->dAblage_SpurGrenze_L : Temporary storage of trace-bracket position for left-hand side  [0.f] m
                    pRelTraObj->dAblage_SpurGrenze_R : Temporary storage of trace-bracket position for right-hand side [0.f] m
                    pRelTraObj->iLwFolge : counter flag for object being held over steering speed [full range sint32]
                    pRelTraObj->fTargetFusionHoldTime : target hold time for relevant object extension [full range of float32 >= 0.f]

  @glob_in         pt_LAOutput->t_LAObjOutputList[i].ObjCor : object specific corridor information [LA_t_ObjCorridor as defined in si_corridor_crit.h]
                           with i in [0 ... EM_N_OBJECTS[ and EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @glob_out        -

  @c_switch_part   LA_CFG_EXT_RELEVANT_OBJECT :  Configuration switch to enable/disable relevant object extension
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

  @author          Christopher Knievel | christopher.knievel@continental-corporation.com | +49 (8382) 9699-399
*************************************************************************************************************************/
static void LA_v_ConstructObjectVariables(const ObjNumber_t ObjNr, LA_t_RelTraObjOutput* const pRelTraObj)
{
  const LA_t_ObjCorridor* pObjCor    = &(pt_LAOutput->t_LAObjOutputList[ObjNr].ObjCor);

  pRelTraObj->iLwFolge              = pObjCor->TrckFahr.iLwFolge;

  pRelTraObj->iObjektSpur_Zyklus    = ASSOC_LANE_RIGHT;

  pRelTraObj->dAblage_SpurGrenze_L  = 0.F;
  pRelTraObj->dAblage_SpurGrenze_R  = 0.F;

#if (LA_CFG_EXT_RELEVANT_OBJECT)
  pRelTraObj->fTargetFusionHoldTime = pObjCor->fTargetFusionHoldTime;
#endif
}

/*************************************************************************************************************************
  Functionname:    LA_v_RecalculateBracketsUsingAlternativeTrajectory                                               */ /*!

  @brief           Recalculates the trace brackets with an alternative trajectory

  @description     In case the previously relevant object was lost, the corridor is re-calculated with a EGO-Course

		@startuml
		Start
		Partition LA_v_RecalculateBracketsUsingAlternativeTrajectory {
		: Initialize lane assignment criteria matrix;
		: Save AblageRadius for default trajectory to possibly restore it;
		: Construct alternative trajectory and modify accordingly the objects properties;
		: Copy object data from corridor criteria persistent struct;
		: Calculation of priority and default corridor functions;
		: Determine final bracket positions given all calculated extensions and restrictions;
		If (check if object is now within brackets) then (yes)
			: Update Object Variables and Bracket Function Results;
		Else (no)
			: Restore the default trajectory value for the dAblageRadius property;
		Endif
		}
		End
		@enduml
  
  @return          -

  @param[in]       ObjNr : internal object number (Object ID) of a valid object [0 ... EM_N_OBJECTS[
                           with EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h

  @param[in]       pEnvironment : pointer to structure of type LA_t_AssTraEnvironment, containing lane matrix information. Defined in si_corridor_crit.h
  @param[in]       pCritMatrixAllObj : Pointer to bracket modifications equal for all objects [LA_t_CriteriaMatrixAllObj as defined in si_corridor_crit.h]
  @param[in,out]   pObjectProperties : Pointer to input object properties [LA_t_RelTraObjInput as defined in si_corridor_crit.h]
                    pObjectProperties->dAblage_Radius [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @param[in,out]   pBracketFuncResults: Alternative Trajectory calculation result [LA_t_CriteriaMatrix]
  @param[in,out]   pBracketFuncEnableFlags: Enable Flags for Bracket recalculation [LA_t_BracketFuncEnable]
  @param[out]      pObjectVariables : Pointer to an LA_t_RelTraObjOutput type structure [LA_t_RelTraObjOutput as defined in si_corridor_crit.h]

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

  @author          Christopher Knievel | christopher.knievel@continental-corporation.com | +49 (8382) 9699-399
*************************************************************************************************************************/
static void LA_v_RecalculateBracketsUsingAlternativeTrajectory(const ObjNumber_t ObjNr, LA_t_RelTraObjInput* const pObjectProperties, LA_t_RelTraObjOutput* const pObjectVariables,
                                                            LA_t_AssTraEnvironment* const pEnvironment, LA_t_CriteriaMatrix* const pBracketFuncResults, 
                                                            LA_t_BracketFuncEnable * const pBracketFuncEnableFlags, const LA_t_CriteriaMatrixAllObj* const pCritMatrixAllObj)
{
  LA_t_CriteriaMatrix AlternativeBracketFuncResults;
  LA_t_RelTraObjOutput AlternativeObjectVariables;
  LA_t_RelTraCurve AlternativeTrajectory;
  float32 DefaultAblageRadius;

  /* Initialize bracket functions */
  LA_v_InitCriteriaMatrix(&AlternativeBracketFuncResults);

  /* Construct alternative trajectory and modify accordingly the objects properties (dAblage_Radius) */
  /* beforehand save AblageRadius for default trajectory to possibly restore it later */
  DefaultAblageRadius = pObjectProperties->dAblage_Radius;
  LA_v_ConstructAlternativeTrajectory(&AlternativeTrajectory);
  LA_v_AdjustObjectPropertiesToTrajectory(pObjectProperties, &AlternativeTrajectory);

  /* Copy object data from corridor criteria persistent struct */
  LA_v_ConstructObjectVariables(ObjNr, &AlternativeObjectVariables);

  /* Calculation of priority and default corridor functions */
  LA_v_EvaluateBracketFunctions(pObjectProperties, &AlternativeObjectVariables, &AlternativeTrajectory, pEnvironment, &AlternativeBracketFuncResults, pBracketFuncEnableFlags, pCritMatrixAllObj);
  
  /* Determine final bracket positions given all calculated extensions and restrictions */
  LA_v_DetermineFinalBracketPositions(pObjectProperties, &AlternativeObjectVariables, &AlternativeBracketFuncResults);

  /* Check if object is now within brackets, eventually restore previous results */
  if( AlternativeObjectVariables.iObjektSpur_Zyklus == ASSOC_LANE_EGO )
  {
    /* Use alternative trajectory recalculation results (copy structure) */
    *pObjectVariables    = AlternativeObjectVariables;
    *pBracketFuncResults = AlternativeBracketFuncResults;    
  }
  else
  {
    /* Omit results of recalculation */
    /* Restore the default trajectory value for the dAblageRadius property */
    pObjectProperties->dAblage_Radius = DefaultAblageRadius;
  }
}

/*************************************************************************************************************************
  Functionname:    LA_v_ConstructAlternativeTrajectory                                                            */ /*!

  @brief           Save parameters for trace bracket calculation with VDY-only trajectory

  @description     Setup ACC trajectory which is considered for trace bracket calculation

		@startuml
		Start
		Partition LA_v_ConstructAlternativeTrajectory {
		: Update Curvature, Absolute Curvature and trajectory hypothesis(Copy ego curve to local curve struct);
		}
		End
		@enduml

  @return          -

  @param[in]       -
  @param[out]     pRelTraCurve : pointer to specific trajectory used for trace bracket calculation [LA_t_RelTraCurve as defined in si_corridor_crit.h]
                   pRelTraCurve->dCurve : Curvature of considered trajectory for trace bracket calculation [-1.f ... +1.f] m-1
                   pRelTraCurve->dCurve_abs : Absolute curvature value of considered trajectory for trace bracket calculation [0.f ... +1.f] m-1
                   pRelTraCurve->iOWVflag : Flag describing which trajectory hypothesis is considered [LA_OWVKRIT_INAKTIV as defined in si_corridor_crit.h]

  @glob_in         pt_LAInput->t_RTE.pf_EgoCurve : Ego curve [-1.f ... 1.f] 1/m
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

  @author          Christopher Knievel | christopher.knievel@continental-corporation.com | +49 (8382) 9699-399
*************************************************************************************************************************/
static void LA_v_ConstructAlternativeTrajectory(LA_t_RelTraCurve* const pRelTraCurve)
{
  /* Copy ego curve to local curve struct */
  pRelTraCurve->dCurve      = *pt_LAInput->t_RTE.pf_EgoCurve;
  pRelTraCurve->dCurve_abs  = fABS(*pt_LAInput->t_RTE.pf_EgoCurve);
  pRelTraCurve->iOWVflag    = LA_OWVKRIT_INAKTIV;
}

/*************************************************************************************************************************
  Functionname:    LA_v_EnableAllBracketFunctions                                                            */ /*!

  @brief           Enable bracket functions

  @description     Enable bracket functions (some can be deactivated by the SI config switches) i.e. set the boolean flag
                   for every bracket function.
		@startuml
		Start
		Partition LA_v_EnableAllBracketFunctions {
			: Enable corridor bracket functions;
			Note Left: Enable below functions \n1.) Add Extension Object Approximation \n2.) Add Restriction Curve Outer Border \n3.) Restriction Target Outside Brackets \n4.) Restriction Analog Road Border \n5.) Restriction Neighborhood Relevant Object \n6.) Restriction Object Trace \n7.) Add Restriction Stationary Object Next Lane \n8.) Restriction City Near Range \n9.) Extension Road Border \n10.) Extension Curve Inner Border \n11.) Extension Road Border CI \n12.) Extension Follow Object Into Curve \n13.) Extension Guard Rail Road Border \n14.) Add Extension Relevant Object \n15.) Extension Blocked Obstacle Corridor \n16.) Extension High speed Approach \n17.) Add Extension High Tunnel Probability 
		}
		End
		@enduml

  @return          -

  @param[in]       -
  @param[out]      pBracketFuncEnable : pointer to data type with flags describing different configurations of trace brackets [LA_t_BracketFuncEnable as defined in si_corridor_crit.h]
                    pBracketFuncEnable->bUseSeekLaneWidthOnly [FALSE]
                    pBracketFuncEnable->bEnableAddExtensionObjectApproximation [TRUE]
                    pBracketFuncEnable->bEnableAddRestrictionCurveOuterBorder [TRUE]
                    pBracketFuncEnable->bEnableRestrictionTargetOutsideBrackets [TRUE]
                    pBracketFuncEnable->bEnableRestrictionAnalogRoadBorder [TRUE]
                    pBracketFuncEnable->bEnableRestrictionNeighbourhoodRelObj [TRUE]
                    pBracketFuncEnable->bEnableRestrictionObjTrace [FALSE, TRUE]
                    pBracketFuncEnable->bEnableAddRestrictionStatObjNextLane [FALSE, TRUE]
                    pBracketFuncEnable->bEnableRestrictionCityNearRange [FALSE, TRUE]
                    pBracketFuncEnable->bEnableExtensionRoadBorder [TRUE]
                    pBracketFuncEnable->bEnableExtensionCurveInnerBorder [TRUE]
                    pBracketFuncEnable->bEnableExtensionRoadBorderCI [TRUE]
                    pBracketFuncEnable->bEnableExtensionFollowObjectIntoCurve [TRUE]
                    pBracketFuncEnable->bEnableExtensionGuardRailRoadBorder [TRUE]
                    pBracketFuncEnable->bEnableExtensionNeighbourhoodRelObj [FALSE, TRUE]
                    pBracketFuncEnable->bEnableAddExtensionRelevantObject [FALSE, TRUE]
                    pBracketFuncEnable->bEnableRestrictionNaviObjCloseToExit [FALSE, TRUE]
                    pBracketFuncEnable->bEnableExtensionNaviCountryroad [FALSE, TRUE]
                    pBracketFuncEnable->bEnableExtensionCamLaneObjAssoc [FALSE, TRUE]
                    pBracketFuncEnable->bExtensionBlockedObstacleCorridor [FALSE, TRUE]
                    pBracketFuncEnable->bEnableExtensionObjScoring [FALSE, TRUE]
                    pBracketFuncEnable->bEnableExtensionHighspeedApproach [FALSE, TRUE]
                    pBracketFuncEnable->bEnableAddExtensionHighTunnelProb [FALSE, TRUE]
                    pBracketFuncEnable->bEnableExtensionLowSpeedFusedBrd [FALSE, TRUE]

  @glob_in         *pt_LAInput->t_RTE.pf_EgoCurve : Ego curve [-1.f ... 1.f] 1/m
  @glob_out        -

  @c_switch_part   LA_CFG_EXT_RELEVANT_OBJECT : relevant object extension
  @c_switch_part   LA_CFG_EXT_HIGHSPEED_APPROACH : bracket extension used for high speed approaches
  @c_switch_part   LA_CFG_ADD_EXT_TUNNEL_PROB : bracket extension used for improved robustness against drop-outs in tunnels
  @c_switch_part   LA_CFG_EXT_NEIGHBORHOOD_REL_OBJ : bracket extension for situations in which relevant object moves in the direction of a near neighboring 
  @c_switch_part   LA_CFG_ADD_RESTRICTION_OBJ_TRACE : enable restriction based on relevant object trace
  @c_switch_part   LA_CFG_EXT_LOWSPEEDFUSEDBRD : Extend trace brackets for low ego velocities and missing adjacent lanes
  @c_switch_part   LA_CFG_ADD_RESTRICTION_STATOBJ_NEXTLANE : enable restriction based on stationary objects in next lane
  @c_switch_part   LA_CFG_RESTRICTION_CITY_NEAR_RANGE : enable a restriction in the near range for country road /city scenarios
  @c_switch_part   LA_CFG_NAVI_COUNTRYROAD_EXTENSION : trace bracket extension on country roads (based on NAVI information)
  @c_switch_part   LA_CFG_CAM_LANE_OBJ_ASSOC_EXTENSION : enable corridor extension based on camera lane object association
  @c_switch_part   LA_CFG_BLOCKED_OBSTACLE_EXTENSION : extension for the blocked path between an object and an obstacle
  @c_switch_part   LA_CFG_NAVI_OBJ_CLOSE_TO_EXIT_RESTRICTION : trace bracket restriction close to an exit (based on NAVI information)
  @c_switch_part   SIT_CFG_OBJECT_SCORING : enable object scoring module
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

  @author          Christopher Knievel | christopher.knievel@continental-corporation.com | +49 (8382) 9699-399
*************************************************************************************************************************/
static void LA_v_EnableAllBracketFunctions(LA_t_BracketFuncEnable* const pBracketFuncEnable)
{
  /* Restrict base corridor width to the seek lane-width only. The seek lane-width
     is smaller compared to the track lane-width and thus, objects can be released
     earlier in e.g. overtake-scenarios. */
  pBracketFuncEnable->bUseSeekLaneWidthOnly = FALSE;

  /* Enable / Disable corridor bracket functions */
  pBracketFuncEnable->bEnableAddExtensionObjectApproximation  = LA_CORR_BRACKET_FUNC_ENABLED;
  pBracketFuncEnable->bEnableAddRestrictionCurveOuterBorder   = LA_CORR_BRACKET_FUNC_ENABLED;
  pBracketFuncEnable->bEnableRestrictionTargetOutsideBrackets = LA_CORR_BRACKET_FUNC_ENABLED;
  pBracketFuncEnable->bEnableRestrictionAnalogRoadBorder      = LA_CORR_BRACKET_FUNC_ENABLED;
  pBracketFuncEnable->bEnableRestrictionNeighbourhoodRelObj   = LA_CORR_BRACKET_FUNC_ENABLED;
#if (LA_CFG_ADD_RESTRICTION_OBJ_TRACE)
  pBracketFuncEnable->bEnableRestrictionObjTrace              = LA_CORR_BRACKET_FUNC_ENABLED;
#endif
#if (LA_CFG_ADD_RESTRICTION_STATOBJ_NEXTLANE)
  pBracketFuncEnable->bEnableAddRestrictionStatObjNextLane    = LA_CORR_BRACKET_FUNC_ENABLED;
#endif
#if (LA_CFG_RESTRICTION_EGO_LANE_CHANGE)
  pBracketFuncEnable->bEnableRestrictionEgoLaneChange         = LA_CORR_BRACKET_FUNC_ENABLED;
#endif
#if (LA_CFG_RESTRICTION_CITY_NEAR_RANGE)
  pBracketFuncEnable->bEnableRestrictionCityNearRange         = LA_CORR_BRACKET_FUNC_ENABLED;
#endif
  pBracketFuncEnable->bEnableExtensionRoadBorder              = LA_CORR_BRACKET_FUNC_ENABLED;
  pBracketFuncEnable->bEnableExtensionCurveInnerBorder        = LA_CORR_BRACKET_FUNC_ENABLED;
  pBracketFuncEnable->bEnableExtensionRoadBorderCI            = LA_CORR_BRACKET_FUNC_ENABLED;
  pBracketFuncEnable->bEnableExtensionFollowObjectIntoCurve   = LA_CORR_BRACKET_FUNC_ENABLED;
  pBracketFuncEnable->bEnableExtensionGuardRailRoadBorder     = LA_CORR_BRACKET_FUNC_ENABLED;
#if (LA_CFG_EXT_NEIGHBORHOOD_REL_OBJ)
  pBracketFuncEnable->bEnableExtensionNeighbourhoodRelObj     = LA_CORR_BRACKET_FUNC_ENABLED;
#endif
#if (LA_CFG_EXT_RELEVANT_OBJECT)
     pBracketFuncEnable->bEnableAddExtensionRelevantObject     = LA_CORR_BRACKET_FUNC_ENABLED;
#endif
#if (LA_CFG_NAVI_OBJ_CLOSE_TO_EXIT_RESTRICTION)
   pBracketFuncEnable->bEnableRestrictionNaviObjCloseToExit    = LA_CORR_BRACKET_FUNC_ENABLED;
#endif
#if (LA_CFG_NAVI_COUNTRYROAD_EXTENSION)
   pBracketFuncEnable->bEnableExtensionNaviCountryroad         = LA_CORR_BRACKET_FUNC_ENABLED;
#endif
#if (LA_CFG_CAM_LANE_OBJ_ASSOC_EXTENSION)
   pBracketFuncEnable->bEnableExtensionCamLaneObjAssoc         = LA_CORR_BRACKET_FUNC_ENABLED;
#endif
#if (LA_CFG_BLOCKED_OBSTACLE_EXTENSION)
   pBracketFuncEnable->bExtensionBlockedObstacleCorridor       = LA_CORR_BRACKET_FUNC_ENABLED;
#endif
#if (SIT_CFG_OBJECT_SCORING) //ToBeDiscussed
   pBracketFuncEnable->bEnableExtensionObjScoring              = LA_CORR_BRACKET_FUNC_ENABLED;
#endif

#if (LA_CFG_EXT_HIGHSPEED_APPROACH)
  pBracketFuncEnable->bEnableExtensionHighspeedApproach        = LA_CORR_BRACKET_FUNC_ENABLED;
#endif

#if (LA_CFG_ADD_EXT_TUNNEL_PROB)
  pBracketFuncEnable->bEnableAddExtensionHighTunnelProb           = LA_CORR_BRACKET_FUNC_ENABLED;
#endif
#if(LA_CFG_EXT_LOWSPEEDFUSEDBRD)
  pBracketFuncEnable->bEnableExtensionLowSpeedFusedBrd        = LA_CORR_BRACKET_FUNC_ENABLED;
#endif
#if(LA_CFG_EXT_PARALLEL_LANE_CHANGE)
  pBracketFuncEnable->bEnableExtensionParallelLaneChange      = LA_CORR_BRACKET_FUNC_ENABLED;
#endif
}

/*************************************************************************************************************************
  Functionname:    LA_v_UpdateRelevancyTimers                                                            */ /*!

  @brief           Update relevant/non-relevant object timers

  @description     Update relevant/non-relevant object timers in the structure passed. If the passed object is
                   relevant, then the cycle time is added to dRelevantZeit and the dNichtRelevantZeit is reset to zero. If the
                   object is not relevant, but has non-zero relevant time, then dNichtRelevantZeit is incremented by the cycle time.
                   Both relevant and not relevant timers are capped.

		@startuml
		Start
		Partition LA_v_UpdateRelevancyTimers {
			If (Check if Object is relevant) then (yes)
				If (check if timer for non-relevancy > 0.0001) then (yes)
					: Update timer for non-relevancy and timer for relevancy as 0;
				Endif
			: Update timer for relevancy;
			Else (no)
				If (check if timer for relevancy > 0.0001) then (yes)
					: Update timer for relevancy;
				Endif
			Endif
		}
		End
		@enduml

  @return          -

  @param[in]       ObjNr : internal object number (Object ID) of a valid object [0 ... EM_N_OBJECTS[
                           with EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @param[in,out]   pObjCor : pointer to object specific corridor information [LA_t_ObjCorridor as defined in si_corridor_crit.h]
                    pObjCor->dNichtRelevantZeit : timer for non-relevancy [0 .. LA_RELEVANTZEIT_MAX] with LA_RELEVANTZEIT_MAX defined in la_par.h
                    pObjCor->dRelevantZeit : timer for relevancy [0 .. LA_RELEVANTZEIT_MAX] with LA_RELEVANTZEIT_MAX defined in la_par.h

  @glob_in         SLATE_b_GetObjIsRelevant(i) : boolean if object i is the relevant object [FALSE, TRUE]
                           with i in [0 ... EM_N_OBJECTS[ and EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @glob_in         SLATE_f_GetSITCycleTime() : [0.f ... 1.f] s
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

  @author          Christopher Knievel | christopher.knievel@continental-corporation.com | +49 (8382) 9699-399
*************************************************************************************************************************/
static void LA_v_UpdateRelevancyTimers(const ObjNumber_t ObjNr , LA_t_ObjCorridor * const pObjCor)
{
  const boolean b_ObjIsRelevant = SLATE_b_GetObjIsRelevant(ObjNr);
  if (b_ObjIsRelevant)
  {
    if( pObjCor->dNichtRelevantZeit > C_F32_DELTA )
    {
      pObjCor->dNichtRelevantZeit = 0.F;
      pObjCor->dRelevantZeit = 0.F;
    }
    pObjCor->dRelevantZeit = pObjCor->dRelevantZeit + SLATE_f_GetSITCycleTime(); //ToBeDiscussed
    pObjCor->dRelevantZeit = MIN_FLOAT( LA_RELEVANTZEIT_MAX , pObjCor->dRelevantZeit );
  }
  else
  {
    if( pObjCor->dRelevantZeit > C_F32_DELTA )
    {
      pObjCor->dNichtRelevantZeit = pObjCor->dNichtRelevantZeit + SLATE_f_GetSITCycleTime(); //ToBeDiscussed
      pObjCor->dNichtRelevantZeit = MIN_FLOAT( LA_RELEVANTZEIT_MAX , pObjCor->dNichtRelevantZeit);
    }
  }
}

/*************************************************************************************************************************
  Functionname:    LA_v_UpdateTimeTrackLaneExtFactor                                                            */ /*!

  @brief           Update relevant/non-relevant object timers

  @description     This function updates the relevant object lane extension factor. If an object becomes relevant then the 
                   trace brackets get extended (wider) depending on the distance the given object is in. The closer the 
                   object the faster the lane extension factor goes up. This extension is done for objects that are closer 
                   than a threshold. When an object goes farther than the threshold, then the factor gets decreased
                   again. For objects that are no longer relevant the factor gets decreased quickly. Lane uncertainty actually 
                   increases with timegap and not absolute distance; hence the usage of timegap instead of longitudinal distance 
                   as base for extension of trace brackets

		@startuml
		Start
		Partition LA_v_UpdateTimeTrackLaneExtFactor {
		If (If Object is relevant) then (yes)
			If (Object Longitudinal Displacement < LA_SPUR_SICHERHEIT) then (yes) 
				: Calculate Absolute factor of Object within distance for lane safety;
				: Calculate positive Inc/Dec factor because relevant track expansion factor is 0 -> 1;   
			Else (no)
				: Calculate Absolute factor of Object within distance for lane safety;
				If (Check If Absolute value of abs_factor > 0.0001) then (yes)
					: Calculate negative Inc/Dec factor because relevant track expansion factor is 1 -> 0;
				Else (no)
					: Set Inc/Dec factor as 0;
				Endif
			Endif
		Else (no)
			: Calculate negative Inc/Dec factor because relevant track expansion factor is 1-> 0;
		Endif
		: Calculate Factor for widening seek lane width to relevant obj track lane width depending on time and distance;
		}
		End
		@enduml

  @return          -

  @param[in]       ObjNr : internal object number (Object ID) of a valid object [0 ... EM_N_OBJECTS[
                           with EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @param[in,out]   pObjCor : pointer to object specific corridor information [LA_t_ObjCorridor as defined in si_corridor_crit.h]
                    pObjCor->TrckFahr.dRelSpurErweiterungsFaktor : Factor for widening seek lane width to relevant obj track 
                     lane width depending on time and distance : [0.0f ... 1.0f]

  @glob_in         SLATE_b_GetObjIsRelevant(i) : boolean if object i is the relevant object [FALSE, TRUE]
                           with i in [0 ... EM_N_OBJECTS[ and EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @glob_in         SLATE_f_GetSITCycleTime() : [0.f ... 1.f] s
  @glob_in         *pt_LAInput->t_RTE.pf_ObjLongDisp  (i) : Longitudinal distance of object i [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
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

  @author          Christopher Knievel | christopher.knievel@continental-corporation.com | +49 (8382) 9699-399
*************************************************************************************************************************/
static void LA_v_UpdateTimeTrackLaneExtFactor(const ObjNumber_t ObjNr, LA_t_ObjCorridor *const pObjCor)
{
  /*--- VARIABLES ---*/
  float32 dIncDecFaktor;
  float32 dAbstFaktor;
  const boolean b_ObjIsRelevant = SLATE_b_GetObjIsRelevant(ObjNr);
  const float32 f_ObjLongDisp = *pt_LAInput->t_RTE.pf_ObjLongDisp(ObjNr);
  float32 f_SPURZEIT_MINMAX_AbstFaktor;

  if (b_ObjIsRelevant)
  {
    /* Objekt innerhalb der Spurbreite fuer eigene Spur                                */
    
    /* dAbstFaktor gibt die Abstandsabhaengigkeit des Inkrement/Dekrementanteils vor   */
    /* 0 = Schnelles Inkrement/Dekrement 1 = Langsames Inkrement/Dekrement             */
    /* Bei dAbstFaktor = 0 gilt die LA_SPURZEIT_MIN, bei = 1 die LA_SPURZEIT_MAX, dazwischen */
    /* linear. LA_SPURZEIT_MIN gibt die kuerzeste Zeit zum Erreichen des Maximums von     */
    /* dRelSpurErweiterungsfaktor an, LA_SPURZEIT_MAX die laengste Zeit.                  */

    if( f_ObjLongDisp < LA_SPUR_SICHERHEIT )
    {
      /* Objekt innerhalb des Abstands fuer Spursicherheit */
      /* je naeher, desto kleiner der dAbstFaktor          */
      dAbstFaktor   = (*pt_LAInput->t_RTE.pf_ObjLongDisp(ObjNr)) * (1.F / LA_SPUR_SICHERHEIT);

      /* positiver dIncDecFaktor da dRelSpurErweiterungsFaktor 0->1 */
      dIncDecFaktor = SLATE_f_GetSITCycleTime() / ( LA_SPURZEIT_MIN + (( LA_SPURZEIT_MAX - LA_SPURZEIT_MIN ) * dAbstFaktor ) );

    }
    else
    {
      /* Objekt ausserhalb des Abstands fuer Spursicherheit */
      /* je weiter entfernt, desto kleiner der dAbstFaktor  */
      dAbstFaktor   =  1.F - (( *pt_LAInput->t_RTE.pf_ObjLongDisp(ObjNr) - LA_SPUR_SICHERHEIT ) / ( RW_FCT_MAX - LA_SPUR_SICHERHEIT ));

      /* negativer dIncDecFaktor da dRelSpurErweiterungsfaktor 1->0 */
      f_SPURZEIT_MINMAX_AbstFaktor = fABS( LA_SPURZEIT_MIN + (( LA_SPURZEIT_MAX - LA_SPURZEIT_MIN ) * dAbstFaktor) );
      if(f_SPURZEIT_MINMAX_AbstFaktor > C_F32_DELTA )
      {
        dIncDecFaktor = - ( SLATE_f_GetSITCycleTime() / ( LA_SPURZEIT_MIN + (( LA_SPURZEIT_MAX - LA_SPURZEIT_MIN ) * dAbstFaktor )) );
      }
      else
      {
        dIncDecFaktor = 0.f;
      }
      
    }
  }
  else
  {
    /* Objekt ausserhalb der Spurbreite fuer eigene Spur             */
    /* negativer dIncDecFaktor damit dRelSpurErweiterungsfaktor 1->0 */
    dIncDecFaktor = - ( SLATE_f_GetSITCycleTime() * (1.F / LA_SPURZEIT_DEC ));
  }

  pObjCor->TrckFahr.dRelSpurErweiterungsFaktor += dIncDecFaktor;

  pObjCor->TrckFahr.dRelSpurErweiterungsFaktor = MINMAX_FLOAT( 0.F , 1.F , pObjCor->TrckFahr.dRelSpurErweiterungsFaktor );
}

/*************************************************************************************************************************
  Functionname:    LA_v_UpdateDistTrackLaneExtFactor                                                            */ /*!

  @brief           Update relevant object lane extension factor distance based

  @description     If an object becomes relevant, wider trace brackets are used than in the seek case. Depending on the object
                   longitudinal distance change the trace brackets can be extended. If the object is not relevant, this extension
                   factor is reset to zero. The calculated factor itself is a value between [0..1] Lane uncertainty actually 
                   increases with timegap and not absolute distance; hence the usage of timegap instead of longitudinal distance 
                   as base for extension of trace brackets

		@startuml
		Start
		Partition LA_v_UpdateDistTrackLaneExtFactor {
		Partition FCT_CFG_ACC_OOI {
		If (check if Object is relevant and Object Relevant Longitudinal Velocity < Maximum velocity) then (yes)
			: Get Object within trace brackets (ego lane) and we are approaching it; 
			: Calculate Relevant lane distance widening factor;
		Else (no)
			: Set Relevant lane distance widening factor as 0;
		Endif
		}
		}
		End
		@enduml

  @return          -

  @param[in]       ObjNr : internal object number (Object ID) of a valid object [0 ... EM_N_OBJECTS[
                           with EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @param[in,out]   pObjCor : pointer to object specific corridor information [LA_t_ObjCorridor as defined in si_corridor_crit.h]
                    pObjCor->TrckFahr.dRelSpurAbstandErweitFaktor : Factor for widening seek lane width to relevant obj track 
                     lane width depending on distance : [0.0f ... 1.0f]

  @glob_in         SLATE_b_GetObjIsRelevant(i) : boolean if object i is the relevant object [FALSE, TRUE]
                           with i in [0 ... EM_N_OBJECTS[ and EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @glob_in         pt_LAInput->t_RTE.pf_ObjVrelX(i) : Relative velocity of object i [-330.f ... 330.f] m/s
                           with i in [0 ... EM_N_OBJECTS[ and EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @glob_in         pt_LAInput->t_OOI.pt_OOIRelObj->ObjectNr : object number of relevant object [OBJ_INDEX_NO_OBJECT ... EM_N_OBJECTS[ and EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @glob_in         pt_LAInput->t_OOI.pt_OOIRelObj->RelPickupDist : pick-up distance of relevant object [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
  @glob_in         *pt_LAInput->t_RTE.pf_ObjLongDisp  (i) : Longitudinal distance of object i [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
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

  @author          Christopher Knievel | christopher.knievel@continental-corporation.com | +49 (8382) 9699-399
*************************************************************************************************************************/
static void LA_v_UpdateDistTrackLaneExtFactor(const ObjNumber_t ObjNr, LA_t_ObjCorridor *const pObjCor)
{
  /*--- VARIABLES ---*/
  float32 dAbstandDiff = 0.F;
  float32 f_ObjVrelX = *pt_LAInput->t_RTE.pf_ObjVrelX(ObjNr);
  boolean b_ObjIsRelevant = SLATE_b_GetObjIsRelevant(ObjNr);
  
#if (FCT_CFG_ACC_OOI)
  if ((pt_LAInput->t_OOI.pt_OOIRelObj->ObjectNr == ObjNr) && (b_ObjIsRelevant) && (f_ObjVrelX < LA_MAX_VREL_REL_LANE_EXT_FACT))
  {
    /* Object within trace brackets (ego lane) and we are approaching it */
    dAbstandDiff = ((pt_LAInput->t_OOI.pt_OOIRelObj->RelPickupDist) - (*pt_LAInput->t_RTE.pf_ObjLongDisp(ObjNr)));

    /* 10m - 30 m => RelSpurAbstandErweitFaktor 0-1 */
    /* Der RelSpurAbstandErweitFaktor wird am Ende der Funktion auf Werte zwischen 0 und 1 begrenzt */
    pObjCor->TrckFahr.dRelSpurAbstandErweitFaktor = (dAbstandDiff - LA_SPUR_ABSTANDDIFF_MIN)*(1.f /(LA_SPUR_ABSTANDDIFF_MAX - LA_SPUR_ABSTANDDIFF_MIN));

    pObjCor->TrckFahr.dRelSpurAbstandErweitFaktor = MINMAX_FLOAT( 0.F , 1.F , pObjCor->TrckFahr.dRelSpurAbstandErweitFaktor );
  }
  else
  {
    /* Object not relevant or we are not approaching it with a sufficiently large
    speed difference, reset extension factor */
    pObjCor->TrckFahr.dRelSpurAbstandErweitFaktor = 0.0F;
  }
#endif  /* (FCT_CFG_ACC_OOI) */  
}

/*************************************************************************************************************************
  Functionname:    LA_v_RelTraObjOutputToObject                                                            */ /*!

  @brief           Copy from corridor object data to persistent struct

  @description     Copy persistent object from internally used LA_t_RelTraObjOutput structure to persistent LA_t_ObjCorridor struct. 
                   The main goal of this function is to store data into persistent storage, so that it can be reloaded in the next cycle.
                   See also function SIRelTraObjectToObjOutput

		@startuml
		Start
		Partition LA_v_RelTraObjOutputToObject {
		: Update object specific corridor information;
		Note Left: 1.) counter flag for object being held over steering speed \n2.) trace-bracket position for left-hand side and right-hand side \n3.) target hold time for relevant object extension ;
		}
		End
		@enduml

  @return          -

  @param[in]      pRelTraObj : pointer to an LA_t_RelTraObjInput type structure from which data to be persistently stored gets copied from
                    pRelTraObj->iLwFolge :counter flag for object being held over steering speed [full range sint32]
                    pRelTraObj->dAblage_SpurGrenze_L : trace-bracket position for left-hand side [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                    pRelTraObj->dAblage_SpurGrenze_R : trace-bracket position for right-hand side [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                    pRelTraObj->fTargetFusionHoldTime : target hold time for relevant object extension [full range of float32 >= 0.f]
  @param[out]     pObjCor : pointer to object specific corridor information [LA_t_ObjCorridor as defined in si_corridor_crit.h]
                    pObjCor->TrckFahr.iLwFolge : counter flag for object being held over steering speed [full range sint32]
                    pObjCor->TrckFahr.dAblage_SpurGrenze_L : trace-bracket position for left-hand side [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                    pObjCor->TrckFahr.dAblage_SpurGrenze_R : trace-bracket position for right-hand side [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                    pObjCor->fTargetFusionHoldTime : target hold time for relevant object extension [full range of float32 >= 0.f]

  @glob_out        -

  @c_switch_part   LA_CFG_EXT_RELEVANT_OBJECT : relevant object extension
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

  @author          Christopher Knievel | christopher.knievel@continental-corporation.com | +49 (8382) 9699-399
*************************************************************************************************************************/
static void LA_v_RelTraObjOutputToObject(const LA_t_RelTraObjOutput *const pRelTraObj , LA_t_ObjCorridor *const pObjCor )
{
  pObjCor->TrckFahr.iLwFolge             = pRelTraObj->iLwFolge;

  pObjCor->TrckFahr.dAblage_SpurGrenze_L = pRelTraObj->dAblage_SpurGrenze_L;
  pObjCor->TrckFahr.dAblage_SpurGrenze_R = pRelTraObj->dAblage_SpurGrenze_R;
#if (LA_CFG_EXT_RELEVANT_OBJECT)
  pObjCor->fTargetFusionHoldTime         = pRelTraObj->fTargetFusionHoldTime;
#endif
}

#if ((LA_CFG_ADAPT_LANEWIDTH_BASED_ON_CAM) && (FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING))
/*************************************************************************************************************************
  Functionname:    LA_v_ManipulateLaneClassBasedOnCam                                                            */ /*!

  @brief           Manipulate lane class used for seek lane width calculation based on cam lane width

  @description     Manipulate lane class used for seek lane width calculation based on cam lane width

		@startuml
		Start
		Partition LA_v_ManipulateLaneClassBasedOnCam {
		: Obtain lane width measured by camera;
		If (Check if camera lane width is available) then (yes)
			If (if the last camera lane width value is valid) then (yes)
				: Apply low pass filter to smooth the used lane width;
			Else (no)
				: initialize filtered camera lane width to current camera lane width value;
			Endif
			: Update last camera lane width value with camera lane width value;
			If (If Narrow Lane Width) then (yes)
				If (Camera Lane Width Filtered <= LA_CAM_LANEWIDTH_MORE_NARROW_LANE_MAX \nand Ego velocity sync < LA_CAM_LANEWIDTH_MAX_SPEED) then (yes)
					: Set Lane Width as FIP_LANE_WIDTH_CLASS_MORE_NARROW;
				Else (no)
					: Do Nothing;
				Endif
			Else if (If Narrower Lane Width) then (yes)
				: Do Nothing;
			Else if (If Unknown Lane Width or Normal Lane Width) then (yes)
				If (if Camera Lane Width Filtered <= LA_CAM_LANEWIDTH_MORE_NARROW_LANE_MAX \nand Ego velocity sync < LA_CAM_LANEWIDTH_MAX_SPEED) then (yes)
					: Set Lane Width as FIP_LANE_WIDTH_CLASS_MORE_NARROW;
				Else if (if Camera Lane Width Filtered <= LA_CAM_LANEWIDTH_NARROW_LANE_MAX \nand Ego velocity sync < LA_CAM_LANEWIDTH_MAX_SPEED) then (yes)
					: Set Lane Width as FIP_LANE_WIDTH_CLASS_NARROW;
				Else (no)
					: Do Nothing;
				Endif
			Else (no)
				If (if Camera Lane Width Filtered <= LA_CAM_LANEWIDTH_MORE_NARROW_LANE_MAX \nand Ego velocity sync < LA_CAM_LANEWIDTH_MAX_SPEED) then (yes)
					: Set Lane Width as FIP_LANE_WIDTH_CLASS_MORE_NARROW;
				Else if (if Camera Lane Width Filtered <= LA_CAM_LANEWIDTH_NARROW_LANE_MAX \nand Ego velocity sync < LA_CAM_LANEWIDTH_MAX_SPEED) then (yes)
					: Set Lane Width as FIP_LANE_WIDTH_CLASS_NARROW;
				Else (no)
					: Do Nothing;
				Endif
			Endif
		Else (no)
			: Set last camera lane width to 0;
		Endif
		}
		End
		@enduml

  @return          -

  @param[in]       -
  @param[in,out]   pLaneWidthClass : pointer to lane width class information [FIP_t_LaneWidthClass]

  @glob_in         -
  @glob_out        -

  @c_switch_part   LA_CFG_ADAPT_LANEWIDTH_BASED_ON_CAM : enables use of camera information for lane width detection
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

  @author          Thomas Bock | Thomas.2.Bock@continental-corporation.com | +49-8382-9699-755
*************************************************************************************************************************/
static void LA_v_ManipulateLaneClassBasedOnCam(FIP_t_LaneWidthClass* const pLaneWidthClass)
{
  /* Obtain lane width measured by camera */
  const float32 fCamLaneWidth = (pt_LAInput->pt_FIPCamLane->f_LaneWidth);
  /* Check if camera lane width is available */
  float32 fCamLaneWidthFiltered = 0.0f;
  if (fCamLaneWidth > C_F32_DELTA)
  {
    /* Apply low pass filter to smooth the used lane width. Apply filter only if the last camera lane width value is valid. 
       Otherwise, initialize filtered camera lane width to current camera lane width value. */
    if(fLastCycleCamLaneWidth > C_F32_DELTA)
    {
      fCamLaneWidthFiltered = GDB_FILTER(fCamLaneWidth, fLastCycleCamLaneWidth, LA_CAM_LANE_FILTER_CONST);
    }
    else
    {
      fCamLaneWidthFiltered = fCamLaneWidth;
    }
    
    fLastCycleCamLaneWidth = fCamLaneWidthFiltered;
    switch (*pLaneWidthClass)
    {
      case FIP_LANE_WIDTH_CLASS_NARROW:
        if((fCamLaneWidthFiltered <= LA_CAM_LANEWIDTH_MORE_NARROW_LANE_MAX) && (*pt_LAInput->t_RTE.pf_EgoVelObjSync < LA_CAM_LANEWIDTH_MAX_SPEED))
        {
          *pLaneWidthClass = FIP_LANE_WIDTH_CLASS_MORE_NARROW;
        }
        else
        {
          /* do nothing */
        }
        break;
      case FIP_LANE_WIDTH_CLASS_MORE_NARROW:
        /* do nothing */
        break;
      /* Map measured camera lane width to lane class, if camera indicates a smaller lane class than the radar-based estimation */
      case FIP_LANE_WIDTH_CLASS_UNKNOWN:
      case FIP_LANE_WIDTH_CLASS_NORMAL:
      default:
        if((fCamLaneWidthFiltered <= LA_CAM_LANEWIDTH_MORE_NARROW_LANE_MAX) && (*pt_LAInput->t_RTE.pf_EgoVelObjSync < LA_CAM_LANEWIDTH_MAX_SPEED))
        {
          *pLaneWidthClass = FIP_LANE_WIDTH_CLASS_MORE_NARROW;
        }
        else if((fCamLaneWidthFiltered <= LA_CAM_LANEWIDTH_NARROW_LANE_MAX) && (*pt_LAInput->t_RTE.pf_EgoVelObjSync < LA_CAM_LANEWIDTH_MAX_SPEED))
        {
          *pLaneWidthClass = FIP_LANE_WIDTH_CLASS_NARROW;
        }
        else
        {
          /* do nothing */
        }
        break;
    }
  }
  else
  {
    /*! Set last camera lane width to zero if camera lane width is invalid */
    fLastCycleCamLaneWidth = 0.f;
  }
}
#endif /* END IF ((LA_CFG_ADAPT_LANEWIDTH_BASED_ON_CAM) && (FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING)) */

#if ( LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM || \
  LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM || \
  LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM )
#ifdef FCT_SIMU
/*************************************************************************************************************************
  Functionname:    LA_v_InitDebugStruct                                                            */ /*!

  @brief           Initialize debug structure

  @description     Initialize debug structure and call it every time SI is initialized

		@startuml
		Start
		Partition LA_v_InitDebugStruct {
		Note Left: Initialize debug structure and \ncall it every time SI is initialized
		: Check Lane Change is active or not;
		: Initialization of the criteria (trace brackets) which are independent of a specific object;
		: Set lane change state to LA_NO_TB_LANE_CHANGE;
		}
		End
		@enduml

  @return          -

  @param[in]       -
  @param[in,out]   -

  @glob_in         -
  @glob_out        LACritMatrixAllObjDebug : structure with lane change information for debugging [LA_t_DebugCriteriaMatrixAllObj]
                    LACritMatrixAllObjDebug.b_LaneChangeIsActive : information if lane change is active [TRUE]
                    LACritMatrixAllObjDebug.CriteriaMatrixAllObj : criteria matrix information for debugging [LA_t_CriteriaMatrixAllObj as defined in si_corridor_crit.h]
                    LACritMatrixAllObjDebug.LaneChgTBState : lane change state [LA_NO_TB_LANE_CHANGE] 
                     as defined in LA_t_LaneChangeTraceBracketState in si_corridor_crit.h

  @c_switch_part   -
  @c_switch_full   FCT_SIMU : FCT simulation specific function switch
  @c_switch_full   LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM : Move trace brackets in case of a lane change (camera lane interface), or
  @c_switch_full   LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM : Move trace brackets in case of no lane change (camera lane interface), or
  @c_switch_full   LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM : Move trace brackets in case of the blinker feature (camera lane interface)
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component

  @pre             -
  @post            -

  @testmethod      Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         -

  @author          Christopher Knievel | christopher.knievel@continental-corporation.com | +49 (8382) 9699-399
*************************************************************************************************************************/
void LA_v_InitDebugStruct(void)
{
  LACritMatrixAllObjDebug.b_LaneChangeIsActive = TRUE;
  LA_v_InitCriteriaMatrixAllObj( &( LACritMatrixAllObjDebug.CriteriaMatrixAllObj ) );
  LACritMatrixAllObjDebug.LaneChgTBState = LA_NO_TB_LANE_CHANGE;
}
#endif /* FCT_SIMU */
#endif /*!< LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM or LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM or LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM */
/* PRQA L:EMPTY_ELSE_OR_DEFAULT */
/** @} end defgroup */
#endif /* (FCT_CFG_ACC_LANE_ASSOCIATION) */
/* ************************************************************************* */
/*   Copyright ADC-GmbH, Lindau                                              */
/* ************************************************************************* */

// PRQA L:STTLN_EXCEEDED 
