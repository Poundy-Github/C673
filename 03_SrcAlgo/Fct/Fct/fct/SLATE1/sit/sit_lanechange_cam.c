/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 SLATE_SIT (Situation)

PACKAGENAME:               sit_lanechange_cam.c

DESCRIPTION:               SIT lane change detection module for the lane change observer based on the camera lane input

AUTHOR:                    R. Erhardt 

CREATION DATE:             -

VERSION:                   $Revision: 1.26 $

LEGACY VERSION:            Revision: 2.2

**************************************************************************** */


/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "sit.h"//PRQA S 0380
/* date: 2019-07-28, reviewer:Prabhu Sundaramurthy, reason: Arises due to inclusion of multiple header files in this header file which has multiple macros*/
#include "sit_lanechange.h"
#include "sit_custom.h"
#if (FCT_CFG_ACC_SITUATION)
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/

/**
@defgroup sit_lanechange_cam Sit Camera Lane change
@ingroup sit_lanechange
@brief          This module detects ACC Lane change of object based on camera lane input.\n\n
@{
*/
/*****************************************************************************
  MODULGLOBALE KONSTANTEN
*****************************************************************************/
#ifndef _PARAM_UNUSED
#define _PARAM_UNUSED(x) (void)(x)
#endif

/*****************************************************************************
  MODULGLOBALE VARIABLEN
*****************************************************************************/

/*****************************************************************************
  MODULLOKALE SYMBOLISCHE KONSTANTEN
*****************************************************************************/

/*----------------------------------------------------------------------------
  EO_LaneChange.c
----------------------------------------------------------------------------*/
/* Anfangswert fuer die Korrektur mit zeitlichem Bezug: */
/*   Anzahl der Zyklen fuer die Korrektur der Fahrspurberechnungsmatrix ( + 1 ! ) */
#define iFSW_KANF            4u

/* Konstante unterer Eckwert der Veigen: */
#define FSW_VEIGEN_UE        ((80.F/C_KMH_MS))
#define FSW_VEIGEN_OE        ((160.F/C_KMH_MS))
/* Annaehernd Geradeausfahrt (Konstante unterer Eckwert der Veigen): */
#define FSW_GERADE_SPUR_UE   (+1500.F)
/* Annaehernd Geradeausfahrt (Konstante oberer Eckwert der Veigen): */
#define FSW_GERADE_SPUR_OE   (+2500.F)

/* Verfolgungsfahrt: */
#define dFSW_FZ_TOLERANZ     (0.9F)


/* Ableitung der Kurvendetektion per Faktor aus Geradeausfahrt (Hysterese): */
#define FSW_NACH_SEITE_FAKTOR (0.8F)

/* Endwert fuer die Korrektur mit zeitlichem Bezug: */
#define iFSW_KEND            1u

/* Neutralwert fuer die Korrektur */
#define iFSW_KNEUTRAL        0u

/* State transition times for SALaneChangeSideState_t enumeration */
#define FSW_EINLENKEN_1_ZEIT      20u
#define FSW_EINLENKEN_2_ZEIT      25u
#define FSW_GERADELENKEN_ZEIT     50u
#define FSW_LCSTATE_TIMER_MAX     255u

/* State transition times for SARelObjLaneState_t enumeration */
#define FSW_RELOBJSTATE_1_TO_2      10u
#define FSW_RELOBJSTATE_2_TO_NORM   40u
#define FSW_RELOBJSTATE_TIMER_MAX   255u

/***************************************************/
/*! Calculation of lane change probability */
#if (SIT_CFG_LC_PROB_CALC) 
#if (SLATE_CFG_CAM_LANE_INTERFACE)
#define SIT_LC_PROB_MIN_DIST_CAM_COURSE                (7.f)     /*! Minimal camera course distance (visibility range) for considering camera infos */
#define SIT_LC_PROB_TIME_CAM_LANE_MARKER_CROSSED       (0.5f)    /*! Time for test if camera lane marker is crossed within this time */
#define SIT_LC_PROB_MAX_DIFF_PSI                       (0.02f)   /*! Maximum reliable difference in heading angle between two timestamps which is reliable */
#endif /*!< SLATE_CFG_CAM_LANE_INTERFACE */
#define SIT_LC_PROB_FILTER_CONST_DIFF_LAT_CURVE        (35.f/3.3f)  /*!< Filter constant for filtering the lateral difference based on curves */
#define SIT_LC_PROB_FILTER_CONST_CURVE_LEVEL           (200.f/3.3f) /*!< Filter constant for the curve level ("curve level": Should be zero on a straight road and non-zero in a curve) */
#define SIT_LC_PROB_MIN_DIFF_CURVE_ANALYSE_DISTLAT     (0.015f)  /*!< Minimum difference between ego curve and driver intended curve to analyse driven distance in lateral direction */
#define SIT_LC_PROB_MIN_DIST_DIFF_CURVE_ANALYSE_DISTLAT  (0.1f)  /*!< Minimum driven lateral distance based on difference between ego curve and driver intended curve to analyse driven distance in lateral direction */
#define SIT_LC_PROB_MIN_LCPROB_ANALYSE_DISTLAT         (40)      /*!< Minimum lane change probablity (last cycle) to analyse driven distance in lateral direction */
#define SIT_LC_PROB_MIN_CURVE_CURVE_LEVEL              (0.004f)  /*!< Maximum curve to determine mean curve level */
#define SIT_LC_PROB_MAX_CURVE_CURVE_LEVEL              (0.03f)   /*!< Minimum curve to determine mean curve level */
#define SIT_LC_PROB_MIN_EGOVELO_SWCURVE_EVAL           (5.f)     /*!< Minimum velocity for evaluation of the mean curve level */
#define SIT_LC_PROB_FILTER_CONST_EGO_CURVE             (60.0f/3.3f) /*!< Time constant for filtering the ego curvature to mimic behavior of old ARS300 signals */

/* Transformations of PT1 elements
  |-------------------------| |-------------------------|
  | T = 0.02 * X / [ 1- X ] | | X = T / ( T + t_cycle ) |  T and t_cycle in sec
  |-------------------------| |-------------------------|
*/
/* PT1 Element Back Transformations to X */
/* X = 0.975 --> T = 0.78 (for 20ms) */
/* pDynPar->fEgoCurvePT1X = (float32) 0.78f / ( (float32) 0.78f + fCycleTime ); */
#define SIT_LC_PROB_EGO_CURVE_PT1_X                  (0.78f) /*!< Filter coefficient for ego curve */
#define SIT_LC_PROB_LOW_SPEED_LEVEL                  (20.f)  /*!< Below this threshold the ego velocity in considered "low speed" */
#define SIT_LC_PROB_DIFF_CURVE_FACTOR                (2.5f)  /*!< Parameter to increase the difference between ego and driver intended curve in order to reach 100 LC prob in case of a LC */

#if (!SIT_LC_CFG_USE_TURNIND_CAMERA_PROB)
#define SIT_LC_PROB_MAX_TIME_TURN_LIGHT_ON           (30.f)  /*!< Maximum time that a turn light is considered to be enabled */
#endif /* (!SIT_LC_CFG_USE_TURNIND_CAMERA_PROB) */

#define SIT_LC_PROB_MAX_TIME_AFTER_TURN_LIGHT_ACTIVE (100.f) /*!< Timer value which leads to a lane change probability of 0 */
/*!< Calculation of lane change probability */  
/***************************************************/
#endif /*!< SIT_CFG_LC_PROB_CALC */

/***************************************************/
/*! Detection of the camera lane marker crossing */
#if (FCT_CFG_FIP_LANE_MATRIX_FUSION && SLATE_CFG_CAM_LANE_INTERFACE)
#define SIT_LC_MIN_DIFF_DIST_CAM_LANE_MARKER             (1.f)   /*!< Minimum difference in the camera lane marker distance between the current and the last cycle */
#define SIT_LC_MIN_MAX_INTERVAL_DIST_CAM_LANE_MARKER     (0.75f) /*!< Maximum interval for the camera lane marker distance */
#define SIT_LC_CAM_LANE_MARKER_HISTORY_BUFFER            (5u)    /*!< Size of the history buffer for the distance to the camera lane markers */
#define SIT_LC_CAM_DEFAULT_CAM_LANE_MARKER_DIST          (99.f)  /*!< Default distance to camera lane marker */
#define SIT_LC_CAM_MOVE_PRE_MIN_DIVENDIST_TO_SIDE        (0.1f)  /*!< Minimal distance the ego vehicle is driven to one side */
#define SIT_LC_CAM_MOVE_PRE_MAX_DIVENDIST_TO_SIDE        (1.f)   /*!< Maximal distance the ego vehicle is driven to one side */
#define SIT_LC_CAM_MOVE_PRE_LM_MIN_LC_PROB               (30)    /*!< Minimal lane change probability to consider it as a lane change for the FIP lane matrix */
#define SIT_LC_CAM_MOVE_PRE_MAX_DIST_LANE_MARKER_LC      (0.9f)  /*!< Maximal distance to the camera lane marker to consider it as a lane change for the FIP lane matrix */
#endif
/*!< Detection of the camera lane marker crossing */
/***************************************************/

/*! The virtual address of the internal data freeze in this module */
#ifndef SIT_MEAS_ADDR_LANE_CHANGE
#define SIT_MEAS_ADDR_LANE_CHANGE     0x20260800
#endif

#ifdef FCT_SIMU
#if (SIT_CFG_LC_PROB_CALC) 
#endif /* SIT_CFG_LC_PROB_CALC */
#if (FCT_CFG_FIP_LANE_MATRIX_FUSION && SLATE_CFG_CAM_LANE_INTERFACE)
/*! Camera lane crossing */
#ifndef SIT_LC_CAM_LANE_CROSS_DEBUG_VADDR
#define SIT_LC_CAM_LANE_CROSS_DEBUG_VADDR  (0x2020FE00u)
#endif

#ifndef SIT_LC_CAM_MOVE_PRE_DEBUG_VADDR
#define SIT_LC_CAM_MOVE_PRE_DEBUG_VADDR  (0x2020FEE0u)
#endif
#endif /* FCT_CFG_FIP_LANE_MATRIX_FUSION && SLATE_CFG_CAM_LANE_INTERFACE */
#endif /*FCT_SIMU*/
/*****************************************************************************
  MODULLOKALE MAKROS
*****************************************************************************/


/*****************************************************************************
  MODULLOKALE TYPEN
*****************************************************************************/

/*! State enumeration of a lane change process per side */
typedef enum SALaneChangeSideStateTag
{
  FSW_ST_WAIT,
  FSW_ST_STRAIGHT,
  FSW_ST_STEER_INTO_1,
  FSW_ST_STEER_INTO_2,
  FSW_ST_GERADELENKEN
} SALaneChangeSideState_t;

/*! State enumeration of lane change process single */
typedef enum SARelObjLaneStateTag
{
  FSW_RELOBJ_WAIT,        /*!< Waiting for a relevant object (none tracked by lane change algo, init state) */
  FSW_RELOBJ_INLANE,      /*!< Releavnt object inlane */
  FSW_RELOBJ_AUSSPUR_L1,  /*!< Releavnt object out-of-lane left for short period of time */
  FSW_RELOBJ_AUSSPUR_L2,  /*!< Relevant object out-of-lane left for long period of time */
  FSW_RELOBJ_AUSSPUR_R1,  /*!< Relevant object out-of-lane right for short period of time */
  FSW_RELOBJ_AUSSPUR_R2   /*!< Relevant object out-of-lane right for long period of time */
} SARelObjLaneState_t;

/*! Lane change information for one side (L/R), formerly FahrspurwechselSeite_t */
typedef struct
{
  SALaneChangeSideState_t eLaneChangeState; /*!< State-machine for lane change process */
  uint8 uiLCStateTimer;                     /*!< Timer for state transitions @max:FSW_LCSTATE_TIMER_MAX @unit:cycles */
  uint8 uiCorrection;                       /*!< Signal for correction
                                              = 0     = no correction
                                              > 0     = correction with timed expiration!
                                              = KANF  = Initialization value, decremented in every cycle.
                                              @min:0 @max:iFSW_KANF */
} SALaneChangeSide_t;

/*! Lane change information, formerly known as Fahrspurwechsel_t */
typedef struct 
{
  float32 dGeradeAus;
  float32 dNachSeite;

  SARelObjLaneState_t eRelObjLaneState; /*!< State of relevant object */

  uint8 uiRelObjLaneStateTimer;         /*!< Timer for relevant object lane state @unit:cycles @max: FSW_RELOBJSTATE_TIMER_MAX */

  ObjNumber_t iLaneChangeTrRelObj;      /*!< To recognise relevant object changes (stores ID of rel obj or OBJ_INDEX_NO_OBJECT if none) */

  SALaneChangeSide_t LeftSide;

  SALaneChangeSide_t RightSide;

} SALaneChange_t;


#if (FCT_CFG_FIP_LANE_MATRIX_FUSION && SLATE_CFG_CAM_LANE_INTERFACE)
/*! History data for the camera lane crossing detection */
typedef struct SITLCCamLaneMarkerHistData {
  boolean b_CrossingLeft;   /*!< Info if camera lane is crossed driving to the left direction */
  boolean b_CrossingRight;  /*!< Info if camera lane is crossed driving to the right direction */
  float32 f_Dist;           /*!< Distance to the camera lane marker */
  uint32 LaneMarkerPoE; /*!< State to the camera lane marker */
}SITLCCamLaneMarkerHistData_t;

/*! Global data for camera lane crossing detection */
typedef struct t_SITCamLaneCrossedData {
  SITLCCamLaneMarkerHistData_t LeftLaneMarkerLastCycle;  /*!< History data for the camera lane crossing detection based on the left camera lane marker */
  SITLCCamLaneMarkerHistData_t RightLaneMarkerLastCycle; /*!< History data for the camera lane crossing detection based on the left camera lane marker */
}SITCamLaneCrossedData_t;

typedef struct SITLCCamPreMoveneData {
float32 af_LeftCamMarkerDistHistory[SIT_LC_CAM_LANE_MARKER_HISTORY_BUFFER];  /*!< Buffer: Distance to the lane marker on the left side */
float32 af_RightCamMarkerDistHistory[SIT_LC_CAM_LANE_MARKER_HISTORY_BUFFER]; /*!< Buffer: Distance to the lane marker on the right side */
}SITLCCamPreMoveneData_t;

#ifdef FCT_SIMU
typedef struct SITLCCamLaneCrossDebugInfo {
  SITCamLaneCrossedData_t t_SITCamLaneCrossedData;
}SITLCCamLaneCrossDebugInfo_t;

static SITLCCamLaneCrossDebugInfo_t SITLCCamLaneCrossedDebugInfo;

SET_MEMSEC_CONST(SILCCamLaneCrossDebugMeasInfo)
static const MEASInfo_t SILCCamLaneCrossDebugMeasInfo =
{
  SIT_LC_CAM_LANE_CROSS_DEBUG_VADDR,   /*!<.VirtualAddress */
  sizeof(SITLCCamLaneCrossedDebugInfo),/*!<.Length */
  FCT_MEAS_FUNC_ID,                   /*!<.FuncID */
  FCT_MEAS_FUNC_CHAN_ID               /*!<.FuncChannelID */
};
#endif

#endif /*!< FCT_CFG_FIP_LANE_MATRIX_FUSION && SLATE_CFG_CAM_LANE_INTERFACE */

/*! Enum to describe which lane change direction is considered */
typedef enum SITLCProbDirection
{
  LC_PROB_LEFT = 0,       /*!< LC left */
  LC_PROB_RIGHT = 1       /*!< LC right */
}SITLCProbDirection_t;

/*! Lane change probabilities for individual detectors */
typedef struct SITLCProbDetectors
{
  uint8 iLatDiffFilteredCurvesProb; /*!< LC probability based on difference in lateral distance between filtered ego curve and filtered driver intended curve */
  uint8 iLatDiffCamCurveProb;       /*!< LC probability based on difference in lateral distance between camera curve and filtered driver intended curve */
  uint8 iVelLatCamLaneMarkerProb;   /*!< LC probability based on lateral velocity of the ego vehicle towards camera lane markers */
  uint8 iTurnLightProb;             /*!< LC probability based on turn light information */
  uint8 iDistLatProb;               /*!< LC probability based on driven distance in lateral direction (only for low speed) */
  uint8 iCamLaneMarkerCrossedProb;  /*!< LC probability based on crossed camera lane marker */
  uint8 iCurveProb;                 /*!< LC probability based on curve (only for low speed) */
}SILCProbDetectors_t;


/*!< Calculation of lane change probability */
/***************************************************/

/*****************************************************************************
  MODULLOKALE KONSTANTEN
*****************************************************************************/

/* Konstantenfeld fuer Fahrspurwechsel: */
SET_MEMSEC_CONST(FSW_GERADE_GRENZEN)
static const GDBLFunction_t FSW_GERADE_GRENZEN = {// PRQA S 3218
  /* date: 2015-05-18, reviewer: Lonard jaison manohar, reason: static local for using data across function calls */
  /* Ausgangswert A1: */
  FSW_GERADE_SPUR_UE,
  /* Ausgangswert A2: */
  FSW_GERADE_SPUR_OE,
  /* Steigung der Anpassungsgerade:        (A2-A1)/(E2-E1) */
  (FSW_GERADE_SPUR_OE - FSW_GERADE_SPUR_UE) / (FSW_VEIGEN_OE - FSW_VEIGEN_UE),
  /* Achsabschnitt der Anpassungsgerade:   A1 - (A2-A1)/(E2-E1) * E1 */
  FSW_GERADE_SPUR_UE
  - ( ( ( FSW_GERADE_SPUR_OE - FSW_GERADE_SPUR_UE) / (FSW_VEIGEN_OE - FSW_VEIGEN_UE ) )
  * FSW_VEIGEN_UE )
};

/*****************************************************************************
  MODULLOKALE TYPEDEFS 
*****************************************************************************/


/*****************************************************************************
  MODULLOKALE VARIABLEN
*****************************************************************************/

/*! Lane change information used for brackets, formerly known as OTFahrspurWechsel  */
SET_MEMSEC_VAR(SALaneChangeInst)
static SALaneChange_t SALaneChangeInst;

SET_MEMSEC_VAR(s_LCProb)
static sint16 s_LCProb; /*!< Lane change probability [-100 100] -> probabilities for a LC to the left and right side are combined */// PRQA S 3229, 3218
/* date: 2017-01-6, reviewer: Bibin Mathew(uid32142), reason: static local for saving data across function calls/cycles */

#if (FCT_CFG_FIP_LANE_MATRIX_FUSION && SLATE_CFG_CAM_LANE_INTERFACE)
SET_MEMSEC_VAR(t_SITCamLaneCrossedData)
static SITCamLaneCrossedData_t t_SITCamLaneCrossedData; /*!< Global data for the detection of crossed camera lane markers */

SET_MEMSEC_VAR(SITLCCamMovePreGlobalData)
static SITLCCamPreMoveneData_t SITLCCamMovePreGlobalData; /*!< Structure to store global data for lane change camera move pre */
#endif

/*****************************************************************************
  Modullocal Functions
*****************************************************************************/

static void SACheckLaneChangeState (SALaneChangeSide_t * pSide, const float32 dCurvature, const float32 dGradient);
#if (SIT_CFG_LC_PROB_CALC == 0)
static void SIT_v_SetLCProbability(void);
#endif

#if (SIT_CFG_LC_PROB_CALC)
static void SIT_v_InitLCProbDataGlobal(void);
static void SIT_v_InitLCProbDataLocal(const float32 fCycleTime, SITLCProbDataLocal_t * pSILCProbDataLocal);
static void SIT_v_InitLCProbDetectors(SILCProbDetectors_t * pSILCProbDetectors);
static void SIT_v_InitLCProbInputData(SITLCProbInputData_t * pSILCProbInputData);
static void SIT_v_LCProbSetTurnLightPhase(const float32 fCycleTime, const SITLCProbDirection_t LCProbDirection, const boolean bTLStatusActive, SITLCProbTurnLightEval_t * pTLEval);
static void SIT_v_LCProbGetCamLaneInfo(SITLCProbCamLaneInfo_t * pCamLaneEval);
static void SIT_v_LCProbGetEgoMotionInfo(const SITLCProbDataLocal_t * pSILCProbDataLocal, float32 * pfEgoCurvePT1, float32 * pfDrvIntCurvePT1);
static void SIT_v_LCProbGetDrivenDistVeloLateralDuringLC(const float32 fCycleTime, const float32 fEgoCurvePT1, const float32 fDrvIntCurvePT1, float32 * pfDistLat);
static void SIT_v_CalcLaneChangeProbability(const float32 fCycleTime);
#endif

#if (FCT_CFG_FIP_LANE_MATRIX_FUSION && SLATE_CFG_CAM_LANE_INTERFACE)
static void SIT_v_InitGlobalCameraLaneCrossingData(void);
static boolean SIT_b_GetValidCamLane(uint32 u_LaneMarkerPoELastCycle, uint32 u_LaneMarkerPoECurrentCycle);
static void SIT_v_DetectCamLaneCrossing(boolean * pb_LCLeftMarkerLeft, boolean * pb_LCLeftMarkerRight, 
                                       boolean * pb_LCRightMarkerLeft, boolean * pb_LCRightMarkerRight, 
                                       const boolean b_LaneMarkerLeftValid, const boolean b_LaneMarkerRightValid,
                                       const SITLCCamLaneMarkerHistData_t * p_LeftLaneMarkerLastCycle, 
                                       const SITLCCamLaneMarkerHistData_t * p_RightLaneMarkerLastCycle);
static void SIT_v_StateCamLaneCrossing(SITLCStateCamLaneMarkerCrossed_t * p_StateCamLaneMarkerCrossed, 
                                      SITLCCamLaneMarkerHistData_t * p_LeftLaneMarkerLastCycle, SITLCCamLaneMarkerHistData_t * p_RightLaneMarkerLastCycle);
#endif

#if (FCT_CFG_FIP_LANE_MATRIX_FUSION && SLATE_CFG_CAM_LANE_INTERFACE)
static void SIT_v_InitGlobLCCamLanePreMove(void);
static void SIT_v_SetLaneChangeMovePre(SITLaneChangeCamPreMove_t * p_SILaneChangeCamPreMoveState);
#endif
/*PRQA S 2013,2016 EMPTY_ELSE_OR_DEFAULT*/
/* date: 2019-07-28, reviewer:Prabhu Sundaramurthy, reason: Empty else or default, no effect on functionality*/
// PRQA S 7013 STTLN_EXCEEDED

/*************************************************************************************************************************
  Functionname:    SIT_v_InitLaneChangeCam                                                                              */ /*!

  @brief           Reset SA lane change detection module

  @description     Function resets SA lane change detection variables

                   @startuml
                   partition  SIT_v_InitLaneChangeCam{
				   start
                       :Reset following SALAne change detection variables
                       -Left and Right Lane change state
                       -Left and Right LC State  timer and Correction factor
                       -Relevant Object lane state and id
                       -Threshold for straight driving and curve for Lane change
                       -Relevant object lane state timer;
                   Stop
				   }
                   @enduml

  @return          -

  @param[in]       -

  @glob_out        SALaneChangeInst.LeftSide.eLaneChangeState  [SALaneChangeSideState_t defined in sit_lanechange_cam.c]
  @glob_out        SALaneChangeInst.RightSide.eLaneChangeState [SALaneChangeSideState_t defined in sit_lanechange_cam.c]
  @glob_out        SALaneChangeInst.LeftSide.uiLCStateTimer    [0 to FSW_LCSTATE_TIMER_MAX]
  @glob_out        SALaneChangeInst.LeftSide.uiCorrection      [0 to iFSW_KANF]
  @glob_out        SALaneChangeInst.RightSide.uiLCStateTimer   [0 to FSW_LCSTATE_TIMER_MAX]
  @glob_out        SALaneChangeInst.RightSide.uiCorrection     [0 to iFSW_KANF]
  @glob_out        SALaneChangeInst.eRelObjLaneState           [SARelObjLaneState_t defined in sit_lanechange_cam.c]
  @glob_out        SALaneChangeInst.iLaneChangeTrRelObj        [ObjNumber_t defined in Rte_type.h]
  @glob_out        SALaneChangeInst.dGeradeAus                 [Full range float32]
  @glob_out        SALaneChangeInst.dNachSeite                 [Full range float32]
  @glob_out        SALaneChangeInst.uiRelObjLaneStateTimer     [0 to FSW_RELOBJSTATE_TIMER_MAX]
  @glob_out        s_LCProbability : Lane change probability   [-100 100] 

  @c_switch_part   SIT_CFG_LC_PROB_CALC                    : Configuration switch enabling lane change probability calculation
  @c_switch_part   FCT_CFG_FIP_LANE_MATRIX_FUSION         : Config switch for fusion of different input sources for FIP Lane Matrix
  @c_switch_part   SLATE_CFG_CAM_LANE_INTERFACE         : Configuration switch enabling camera lane input data to FCT_SEN
  @c_switch_full   FCT_CFG_ACC_SITUATION           :  FCT support for ACC SIT (situation) sub-component

  @pre             -
  @post            Default lane change values set up (waiting for relevant object,
                   all timers reset etc.)

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         12/7/2015

 
  @author          R. Ehrhardt (original)
                   Gergely Ungvary (modified for better clarity, logic unchanged)
*************************************************************************************************************************/
void SIT_v_InitLaneChangeCam (void)
{

/*--- FUNKTIONSLOKALE SYMBOLISCHE KONSTANTEN ---*/

/*--- FUNKTIONSLOKALE KONSTANTEN ---*/

/*--- FUNKTIONSLOKALE VARIABLEN ---*/

  SALaneChangeInst.LeftSide.eLaneChangeState = FSW_ST_WAIT;

  SALaneChangeInst.RightSide.eLaneChangeState = FSW_ST_WAIT;


  SALaneChangeInst.LeftSide.uiLCStateTimer = 0u;

  SALaneChangeInst.LeftSide.uiCorrection = 0u;


  SALaneChangeInst.RightSide.uiLCStateTimer = 0u;

  SALaneChangeInst.RightSide.uiCorrection = 0u;


  SALaneChangeInst.eRelObjLaneState = FSW_RELOBJ_WAIT;

  SALaneChangeInst.iLaneChangeTrRelObj = OBJ_INDEX_NO_OBJECT;

  SALaneChangeInst.dGeradeAus = (0.5f / FSW_GERADE_SPUR_UE);
  SALaneChangeInst.dNachSeite = (0.5f / (FSW_GERADE_SPUR_UE * FSW_NACH_SEITE_FAKTOR));

  SALaneChangeInst.uiRelObjLaneStateTimer = 0u;

/*--- AUFHEBUNG FUNKTIONSLOKALE SYMBOLISCHE KONSTANTEN ---*/

  s_LCProb = 0;

#if (SIT_CFG_LC_PROB_CALC)
  /*! Initialize the global data for lane change probability calculation */
  SIT_v_InitLCProbDataGlobal();
#endif

#if (FCT_CFG_FIP_LANE_MATRIX_FUSION && SLATE_CFG_CAM_LANE_INTERFACE)
  /*! Initialize the global data for the camera lane crossing detection */
  SIT_v_InitGlobalCameraLaneCrossingData();
#endif

#if (FCT_CFG_FIP_LANE_MATRIX_FUSION && SLATE_CFG_CAM_LANE_INTERFACE)
  /*! Initialize global information for lane change camera move pre state */
  SIT_v_InitGlobLCCamLanePreMove();
#endif
}
/*PRQA S 2013,2016 EMPTY_ELSE_OR_DEFAULT*/
/* date: 2019-07-28, reviewer:Prabhu Sundaramurthy, reason: Empty else or default, no effect on functionality*/

/*************************************************************************************************************************
  Functionname:    SACheckLaneChangeState                                                                           */ /*!

  @brief           Detect ego lane change for OWV criteria for given side

  @description     Function previously known as EOCheckLaneChangeState before
                   being moved to SA. This function maintains the state for
                   a given side (left or right), to attempt lane changes

                   @startuml
                   partition SACheckLaneChangeState {
                   start
                   if (LC State timer for one side L/R does not exceed FSW_LCSTATE_TIMER_MAX) then (yes)
                       : Increment LC state timer>
                   Endif
                   Partition eLaneChangeState {
                   If (Lane Change State is FSW_ST_WAIT) then (yes)
                   If(Curvature to the left has not reached threshold for curvature) then (yes)
                                   :Next State is FSW_ST_STRAIGHT>
                           Endif
                   Endif
                   If(Lane Change State is FSW_ST_STRAIGHT) then (yes)
                           If(Curvature is greater than Curvature threshold) then (yes)
                                   :Next State is FSW_ST_STEER_INTO_1
                                   Reset LC state timer>
                               Elseif(Curvature is exceeds the negative curve threshold)
                                   :Curvature points to other side,Go back to FSW_ST_WAIT>
                               Endif
                           Endif
                   If(Lane Change State is FSW_ST_STEER_INTO_1) then (yes)
                           If(LC State timer reached FSW_EINLENKEN_1_ZEIT)  then (yes)
                               :State is changed to FSW_ST_WAIT>
                           Endif
                           IF(Curve gradient goes back) then (yes)
                               :State timer is reset
                               Next Lane Change State is FSW_ST_STEER_INTO_2>
                           Endif
                   Endif
                   If(Lane Change state is FSW_ST_STEER_INTO_2) then (yes)
                           If(LC state timer exceeds FSW_EINLENKEN_2_ZEIT)
                               :LC state is FSW_ST_WAIT>
                           Endif
                           IF (Curvature is less than Curve threshold) then (yes)
                               :Reset LC state timer
                               LC State is FSW_ST_GERADELENKEN>
                           Endif
                   Endif
                   IF(Lane Change state is FSW_ST_GERADELENKEN) then (yes)
                           IF(LC state timer exceeds threshold FSW_GERADELENKEN_ZEIT) then (yes)
                               : LC state is FSW_ST_WAIT>
                           Endif
                   Else
                       :LC state is FSW_ST_WAIT>
                   Endif
                   stop
                   }
                   @enduml

  @return          -

  @param[in,out]   pSide : pointer to SALaneChangeSide_t defined in sit_lanechange_cam.c
                      uiLCStateTimer                                      [0u    FSW_LCSTATE_TIMER_MAX]
                      eLaneChangeState                                    [SALaneChangeSideState_t defined in sit_lanechange_cam.c]
  @param[in]       dCurvature : the currently driven curvature            [-1f   1f]
  @param[in]       dGradient : the curvature change gradient              [-1f   1f]

  @glob_in         SALaneChangeInst.dGeradeAus                            [full range float32]
  @glob_in         SALaneChangeInst.dNachSeite                            [full range float32]

  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_SITUATION :  FCT support for ACC SIT (situation) sub-component

  @pre             -
  @post            Data updated for current cycle; module local variable SALaneChangeInst updated

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         12/7/2015

  @author          R. Ehrhardt (original)
                   Gergely Ungvary (modified for better clarity, logic unchanged)
*************************************************************************************************************************/
static void SACheckLaneChangeState (SALaneChangeSide_t * pSide, const float32 dCurvature, const float32 dGradient)
{
/*--- FUNKTIONSLOKALE SYMBOLISCHE KONSTANTEN ---*/

/*--- FUNKTIONSLOKALE KONSTANTEN ---*/

/*--- FUNKTIONSLOKALE VARIABLEN ---*/
 float32 f_Abs_dCurvature;

  if (pSide->uiLCStateTimer < FSW_LCSTATE_TIMER_MAX)
  {
    pSide->uiLCStateTimer++;
  }

  /* Recognition lane change: */
  switch (pSide->eLaneChangeState)
  {
  case FSW_ST_WAIT:
    /* Next state driving straight, with condition of curvature below threshold: */
    f_Abs_dCurvature = fABS(dCurvature);
    if (f_Abs_dCurvature < SALaneChangeInst.dGeradeAus)
    {
      pSide->eLaneChangeState = FSW_ST_STRAIGHT;
    }
    break;

  case FSW_ST_STRAIGHT:
    /* Curve or lane change beginning: */
    if (dCurvature > SALaneChangeInst.dNachSeite)
    {
      /* Next state: curvature goes into the given state: */
      pSide->eLaneChangeState = FSW_ST_STEER_INTO_1;
      pSide->uiLCStateTimer = 0u;
    }
    else
    {
      if (dCurvature < -SALaneChangeInst.dNachSeite)
      {
        /* Curvature points to other side, go back to initial state (wait) */
        pSide->eLaneChangeState = FSW_ST_WAIT;
      }
    }
    break;

  case FSW_ST_STEER_INTO_1:
    /* Check for abort using timer */
    if (pSide->uiLCStateTimer > FSW_EINLENKEN_1_ZEIT)
    {
      pSide->eLaneChangeState = FSW_ST_WAIT;
    }

    /* Check for next state (when curvature change gradient goes back) */
    if (dGradient < C_F32_DELTA)
    {
      pSide->uiLCStateTimer = 0u;
      pSide->eLaneChangeState = FSW_ST_STEER_INTO_2;
    }
    break;

  case FSW_ST_STEER_INTO_2:
    /* Abbruch */
    /* Diese Abbruchzeit hat Auswirkungen auf Funktion bei niedrigen Gewchwindigkeiten */
    /* Zeit eventuell abhängig machen vom minimalem Kurvenradius */
    /* Dateien: c:\daten\spurwechsel\V220-679\19_05_99\19059909 */
    /*          c:\daten\spurwechsel\V220-679\19_05_99\1905990a */
    if (pSide->uiLCStateTimer > FSW_EINLENKEN_2_ZEIT)
    {
      /* Abort due to timer too high */
      pSide->eLaneChangeState = FSW_ST_WAIT;
    }

    /* Naechster Zustand: */
    /* Mehrere Moeglichkeiten, je nach gewuenschtem Ansprechverhalten: */
    /* Fruehestes Ansprechen:  if (dCurvature < SALaneChangeInst.dNachSeite) */
    /* Spaeteres Ansprechen:   if (fABS(dCurvature) < SALaneChangeInst.dGeradeAus) */
    /* Wirkliche Geradeausfahrt bzw Gegenlenken, ganz spaetes Ansprechen: */
    /*                         if (dSpurRadius < C_F32_DELTA) */
    if (dCurvature < SALaneChangeInst.dNachSeite)
    {
      pSide->uiLCStateTimer = 0u;
      pSide->eLaneChangeState = FSW_ST_GERADELENKEN;
    }
    break;

  case FSW_ST_GERADELENKEN:
    /* Abort */
    if (pSide->uiLCStateTimer > FSW_GERADELENKEN_ZEIT)
    {
      pSide->eLaneChangeState = FSW_ST_WAIT;
    }
    break;

  default:
    pSide->eLaneChangeState = FSW_ST_WAIT;
    break;
  }

/*--- AUFHEBUNG FUNKTIONSLOKALE SYMBOLISCHE KONSTANTEN ---*/

}


/*************************************************************************************************************************
  Functionname:    SIT_v_DetectLaneChangeCam                                                                            */ /*!

  @brief           Detect ego lane change for OWV criteria

  @description     Function previously known as EODetectLaneChange before
                   being moved to SA. This function has to be called in
                   every SA/SI processing cycle before trace bracket
                   calculation takes place.

                   @startuml
                   partition SIT_v_DetectLaneChangeCam {
                   start
                   :Get the following inputs to calculate Camera LC probability from RTE
                   -Ego Longitudinal Velocity
                   -Ego Curve
                   -Ego Curve Gradient
                   -Get the relevant OOI-0 from OOI module;
                   :Derive Linear interpolation of Ego speed driving in straight line w.r.t to Constant thresholds for Lane Change
                   Derive the Curve detection by a factor from straight driving hysteresis;
                   If (Valid Relevant object is greater than 0) then (yes)
                   	If (Relevant object is static and not moving) then (yes)
                   		:Wait for valid object
                   		Set the relevant object change for next cycle as invalid>
                   		Note right
                   			Variable to recognise relevant object change
                   			If valid holds the object id, else holds -1
                   		End note
                   	Else (no)
                   		If (Lane state timer has not reached FSW_RELOBJSTATE_TIMER_MAX) then (yes)
                   			: Increment the Lane state timer>
                   		Endif
                   		If (Relevantobjectchange from previous cycle is not as OOI-0) then (yes)
                   			:Wait until the Previous cycle relevant object is OOI-0
                   			Set the relevant object for next cycle to invalid>
                   		Endif
                   	Endif
                   	Partition eRelObjLaneState {
                   	If ( Relevant object state is FSW_RELOBJ_WAIT) then (yes)
                   		If (Relevant object Lateral displacement is within a defined tolerance) then (yes)
                   			:Relevant object is in FSW_RELOBJ_INLANE
                   			Relevant object is recognized as OOI-0>
                   			Note right
                   				Relevant object is within ego lane and is a valid OOI-0
                   			End note
                   		Endif
                   	Endif
                   	If (Relevant object state is FSW_RELOBJ_INLANE) then (yes)
                   		If (Relevant object Lateral displacement is within a tolerance range negative value) then (yes)
                   			:Reset the Lane state timer
                   			Relevant object Lane state is FSW_RELOBJ_AUSSPUR_R1>
                   			Note right
                   				Object is set to Out of lane on right side of ego lane for short time
                   			End note
                   		Endif
                   		If (Relevant object Lateral displacement is within a tolerance range positive value) then (yes)
                   			:Reset the Lane state timer
                   			Relevant object Lane state is FSW_RELOBJ_AUSSPUR_L1>
                   			Note right
                   				Object is set to Out of lane on left side of ego lane for short time
                   			End note
                   		Endif
                   	Endif
                   	If (Relevant object state is FSW_RELOBJ_AUSSPUR_L1) then (yes)
                   		If (Lane state timer exceeds FSW_RELOBJSTATE_1_TO_2) then (yes)
                   			:Lane state of the object is FSW_RELOBJ_AUSSPUR_R2>
                   			Note right
                   				Object is out of lane right for longer period of time
                   			End note
                   		Endif
                   	Endif
                   	If (Relevant object state is FSW_RELOBJ_AUSSPUR_L2 or FSW_RELOBJ_AUSSPUR_R2) then (yes)
                   		If (Lane state timer exceeds FSW_RELOBJSTATE_2_TO_NORM) then (yes)
                   			: Set Lane state to FSW_RELOBJ_WAIT>
                   		Endif
                   	Endif
                   	}
                   Else
                   	:Relevant object state is FSW_RELOBJ_WAIT
                   	Relevant object change is OBJ_INDEX_NO_OBJECT>
                   Endif
                   : Detect lane change for OWV criteria to the left
                   <b>SACheckLaneChangeState</b>;
                   :Detect lane change for OWV criteria to the right
                   <b>SACheckLaneChangeState</b>;
                   If (Lane change state is FSW_ST_GERADELENKEN and ObjLane state is FSW_RELOBJ_AUSSPUR_R2
                   ) then (yes)
                   	If (Correction for left side is iFSW_KNEUTRAL) then (yes)
                   		:Correction for left side is set to iFSW_KANF>
                   	Else
                   		If (Correction for left side exceeds iFSW_KEND) then (yes)
                   			:Decrement the Signal correction value for left side>
                   		Endif
                   	Endif
                   Else
                   	:Reset the left side  Signal correction value to iFSW_KNEUTRAL>
                   endif
                   If (Lane change state is FSW_ST_GERADELENKEN and ObjLane state is FSW_RELOBJ_AUSSPUR_L2
                   ) then (yes)
                   	If (Correction for right side  is iFSW_KNEUTRAL) then (yes)
                   		:Correction for right side is set to iFSW_KANF>
                   	Else
                   		If (Correction for right side exceeds iFSW_KEND) then (yes)
                   			:Decrement the Signal correction value for right side>
                   		Endif
                   	Endif
                   Else
                   	:Reset the right side  Signal correction value to iFSW_KNEUTRAL>
                   Endif
                   If (Camera Lane change probability calculation enabled) then (yes)
                   :Calculate of lane change probability
                   <b>SIT_v_CalcLaneChangeProbability</b>;
                   Else
                   :Use Radar only Lane change probability
                   <b>SIT_v_SetLCProbability</b>;
                   endif
                   If (FIP Lane matrix and Camera lane interface enabled) then (yes)
                   	:Determine if camera lane markers are crossed
                   	<b>SIT_v_StateCamLaneCrossing</b>;
                   	:State if ego vehicle moves towards the new lane during the ego lane change
                   	i.e Premovestate before entering the new lane
                   	<b>SIT_v_SetLaneChangeMovePre</b>;
                   	:Freeze the debug data;
                   endif
                   stop
                   }
                   @enduml


  @return          -

  @param[in]       - 

  @glob_in         pt_SITInput->t_RTE.pf_EgoLongVel                                         [-330f   330f]
  @glob_in         pt_SITInput->t_OOI.pu_OOIListObjId                                       [0u   40u]
  @glob_in         pt_SITInput->t_RTE.pf_EgoCurve                                           [-1f   1f]
  @glob_in         pt_SITInput->t_RTE.pf_EgoCurveGrad                                       [-1f   1f]
  @glob_in         FSW_GERADE_GRENZEN                                                       [GDBLFunction_t defined in cml_mapping.h]
  @glob_in         pt_SITInput->t_RTE.pt_ObjDynProperty                                     [EM_t_GenObjDynamicProperty defined in Rte_Type.h]
  @glob_in         pt_SITInput->t_RTE.pf_ObjLatDisp                                         [-PI/2*RW_FCT_MAX   PI/2*RW_FCT_MAX]
  @glob_in         SALaneChangeInst.uiRelObjLaneStateTimer                                  [0u to FSW_RELOBJSTATE_TIMER_MAX]
  @glob_in         SALaneChangeInst.LeftSide                                                [SALaneChangeSide_t defined in sit_lanechange_cam.c]
  @glob_in         SALaneChangeInst.RightSide                                               [SALaneChangeSide_t defined in sit_lanechange_cam.c]
  @glob_in         SALaneChangeInst.LeftSide.eLaneChangeState                               [SALaneChangeSideState_t defined in sit_lanechnege_cam.c]
  @glob_in         SALaneChangeInst.RightSide.eLaneChangeState                              [SALaneChangeSideState_t defined in sit_lanechnege_cam.c]
  @glob_in         SALaneChangeInst.eRelObjLaneState                                        [SARelObjLaneState_t defined in sit_lanechange_cam.c]
  @glob_in         SALaneChangeInst.LeftSide.uiCorrection                                   [0u to iFSW_KANF]
  @glob_in         SALaneChangeInst.RightSide.uiCorrection                                  [0u to iFSW_KANF]
  @glob_in         pt_SITOutput->t_CamLaneMarkerCrossed : Camera lane marker crossing state [type SITLCStateCamLaneMarkerCrossed_t defined in si_ext.h]
  @glob_in         t_SITCamLaneCrossedData.LeftLaneMarkerLastCycle  
  @glob_in         t_SITCamLaneCrossedData.RightLaneMarkerLastCycle 
  @glob_in         pt_SITOutput->t_LaneChangeCamPreMoveState                                [type SITLaneChangeCamPreMove_t defined in fct_sen_feedback.h]
  @glob_in         t_SITCamLaneCrossedData                          
  @glob_in         SITLCCamLaneCrossedDebugInfo                     
  @glob_in         SILCCamLaneCrossDebugMeasInfo                    
  @glob_in         SALaneChangeInst                                 
  @glob_in         SALaneChangeMeasInfo                             
  @glob_out        SALaneChangeInst.dGeradeAus                                              [full range datatype of float32]
  @glob_out        SALaneChangeInst.dNachSeite                                              [full range datatype of float32]
  @glob_out        SALaneChangeInst.eRelObjLaneState                                        [SARelObjLaneState_t defined in sit_lanechange_cam.c]
  @glob_out        SALaneChangeInst.iLaneChangeTrRelObj                                     [ObjNumber_t defined in Rte_Type.h]
  @glob_out        SALaneChangeInst.uiRelObjLaneStateTimer                                  [0u to FSW_RELOBJSTATE_TIMER_MAX]
  @glob_out        SALaneChangeInst.LeftSide                                                [SALaneChangeSide_t defined in sit_lanechange_cam.c]
  @glob_out        SALaneChangeInst.RightSide                                               [SALaneChangeSide_t defined in sit_lanechange_cam.c]
  @glob_out        SALaneChangeInst.LeftSide.uiCorrection                                   [0u to iFSW_KANF]
  @glob_out        SALaneChangeInst.RightSide.uiCorrection                                  [0u to iFSW_KANF]
  @glob_out        SITLCCamLaneCrossedDebugInfo.t_SITCamLaneCrossedData 

  @c_switch_part   FCT_SIMU                       : Configuration switch for enabling simulation profiling
  @c_switch_part   SIT_CFG_LC_PROB_CALC           : Configuration switch enabling lane change probability calculation
  @c_switch_part   FCT_CFG_FIP_LANE_MATRIX_FUSION : Config switch for fusion of different input sources for FIP Lane Matrix
  @c_switch_part   SLATE_CFG_CAM_LANE_INTERFACE : Configuration switch enabling camera lane input data to FCT_SEN  
  @c_switch_full   FCT_CFG_ACC_SITUATION          :  FCT support for ACC SIT (situation) sub-component

  @pre             -
  @post            Data updated for current cycle, other code may call
                   SAGetLaneChange function
                   (module local variable SALaneChangeInst updated)

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         12/8/2015

  @todo            Verify that using signed pt_SITInput->t_RTE.pf_EgoLongVel as opposed
                   to old version's use of EGO_SPEED_X_RAW has no detrimental
                   effects

                   Also change sign of curvature to avoid swapping from globally
                   used curvature (AUTOSAR) sign definition


  @author          R. Ehrhardt (original)
                   Gergely Ungvary (modified for better clarity, logic unchanged)
*************************************************************************************************************************/
void SIT_v_DetectLaneChangeCam (void)
{
  /*--- FUNKTIONSLOKALE VARIABLEN ---*/
  fCurve_t fCurveStandard;
  float32 fGradientOfCurveStandard;
  float32 fRelObjDist2Course;
  float32 f_Abs_RelObjDist2Course;

  const fVelocity_t fEgoSpeed = *pt_SITInput->t_RTE.pf_EgoLongVel;
  const ObjNumber_t RelTrckObjNr = *pt_SITInput->t_OOI.pu_OOIListObjId((uint8)OBJ_NEXT_OOI);
  SLATE_t_Obj_DynamicProperty t_RelTrckObjDynProperty;

  
  /* Holen der Standard-Spur */
  fCurveStandard = (-0.5f) * (*pt_SITInput->t_RTE.pf_EgoCurve);
  fGradientOfCurveStandard = (-0.5f) * (*pt_SITInput->t_RTE.pf_EgoCurveGrad);

  /* Geschwindigkeitsabhängig rechnen: */
  SALaneChangeInst.dGeradeAus = dGDBmathLineareFunktion (&FSW_GERADE_GRENZEN, fEgoSpeed);
  SALaneChangeInst.dGeradeAus = (0.5f / SALaneChangeInst.dGeradeAus);
  SALaneChangeInst.dNachSeite = SALaneChangeInst.dGeradeAus / FSW_NACH_SEITE_FAKTOR;
  /*     Multi Object     */
  /*check if there is a valid relative object (OOI 0)*/
  if (RelTrckObjNr >= 0)
  {
    /*check if relative object OOI 0, is a moving not static object*/
    t_RelTrckObjDynProperty = *pt_SITInput->t_RTE.pt_ObjDynProperty(RelTrckObjNr);
    if (t_RelTrckObjDynProperty != 0U)
    {
      /*if static wait for another valid object, and set relative object for next cycle use to no object*/
      SALaneChangeInst.eRelObjLaneState = FSW_RELOBJ_WAIT;
      SALaneChangeInst.iLaneChangeTrRelObj = OBJ_INDEX_NO_OBJECT;
    }
    /*if valid OOI object is not static and is moving. */
    else
    {
      /*if state timer is not at its maximum increase it for later use in */
      if (SALaneChangeInst.uiRelObjLaneStateTimer < FSW_RELOBJSTATE_TIMER_MAX)
      {
        SALaneChangeInst.uiRelObjLaneStateTimer++;
      }
      /*if previous cycle set object (set by the below switch case) is not the same as current OOI 0 set state to wait and object to none*/
      if (SALaneChangeInst.iLaneChangeTrRelObj != RelTrckObjNr)
      {
        SALaneChangeInst.eRelObjLaneState = FSW_RELOBJ_WAIT;
        SALaneChangeInst.iLaneChangeTrRelObj = OBJ_INDEX_NO_OBJECT;
      }

      fRelObjDist2Course = *pt_SITInput->t_RTE.pf_ObjLatDisp(RelTrckObjNr);
      /* Code above replaces former: trace code since traces were all invalid due to no copy of  TRACE_VALID_LANEMATRIX in EM*/

      switch (SALaneChangeInst.eRelObjLaneState)
      {
      case FSW_RELOBJ_WAIT:
        /*when in wait state to validate a relevant check if relevant object is valid within the ego lane according to defined tolerance*/
	    f_Abs_RelObjDist2Course = fABS(fRelObjDist2Course);
        if (f_Abs_RelObjDist2Course < dFSW_FZ_TOLERANZ) 
        {
          SALaneChangeInst.eRelObjLaneState = FSW_RELOBJ_INLANE;
          SALaneChangeInst.iLaneChangeTrRelObj = RelTrckObjNr;
        }
        break;
      case FSW_RELOBJ_INLANE:
        /* check if the valid in lane relevant object is  within tolerance range (negative for right side)for right if not reset timer and change state*/
        if (fRelObjDist2Course < (-2.0F*dFSW_FZ_TOLERANZ))
        {
          /*reset timer*/
          SALaneChangeInst.uiRelObjLaneStateTimer = 0u;
          /*set to out of lane to the right side for a short time*/
          SALaneChangeInst.eRelObjLaneState = FSW_RELOBJ_AUSSPUR_R1; 
        }
        /*maximum tolerance range for left (positive distance)*/
        if (fRelObjDist2Course > (2.0F*dFSW_FZ_TOLERANZ))
        {
          /*reset timer*/
          SALaneChangeInst.uiRelObjLaneStateTimer = 0u;
          /*set to out of lane to the left side for a short time*/
          SALaneChangeInst.eRelObjLaneState = FSW_RELOBJ_AUSSPUR_L1;
        }
        break;

      case FSW_RELOBJ_AUSSPUR_L1:
        if (SALaneChangeInst.uiRelObjLaneStateTimer > FSW_RELOBJSTATE_1_TO_2)
        {
          SALaneChangeInst.eRelObjLaneState = FSW_RELOBJ_AUSSPUR_L2;
        }
        break;

      case FSW_RELOBJ_AUSSPUR_R1:
        if (SALaneChangeInst.uiRelObjLaneStateTimer > FSW_RELOBJSTATE_1_TO_2)
        {
          SALaneChangeInst.eRelObjLaneState = FSW_RELOBJ_AUSSPUR_R2;
        }
        break;

      case FSW_RELOBJ_AUSSPUR_L2:
      case FSW_RELOBJ_AUSSPUR_R2:
        if (SALaneChangeInst.uiRelObjLaneStateTimer > FSW_RELOBJSTATE_2_TO_NORM)
        {
          SALaneChangeInst.eRelObjLaneState = FSW_RELOBJ_WAIT;
        }
        break;
      default:
        break;
      } /* endswitch */
    }
  }
  else
  {
    SALaneChangeInst.eRelObjLaneState = FSW_RELOBJ_WAIT;
    SALaneChangeInst.iLaneChangeTrRelObj = OBJ_INDEX_NO_OBJECT;
  }

  /* Erkennung Spurwechsel nach links ueber Automaten: */
  SACheckLaneChangeState (&(SALaneChangeInst.LeftSide), -fCurveStandard, -fGradientOfCurveStandard);

  /* Erkennung Spurwechsel nach rechtss ueber endlichen Automaten: */
  SACheckLaneChangeState (&(SALaneChangeInst.RightSide), fCurveStandard, fGradientOfCurveStandard);

  /* Korrekturzustand erkennen und anstoßen oder altern: */
  if ((SALaneChangeInst.LeftSide.eLaneChangeState == FSW_ST_GERADELENKEN) &&
      (SALaneChangeInst.eRelObjLaneState == FSW_RELOBJ_AUSSPUR_R2))
  {
    if (SALaneChangeInst.LeftSide.uiCorrection == iFSW_KNEUTRAL)
    {
      SALaneChangeInst.LeftSide.uiCorrection = iFSW_KANF;
    }
    else if (SALaneChangeInst.LeftSide.uiCorrection > iFSW_KEND)
    {
      SALaneChangeInst.LeftSide.uiCorrection--;
    }
    else
    {
    }
  }
  else
  {
    SALaneChangeInst.LeftSide.uiCorrection = iFSW_KNEUTRAL;
  }

  if ((SALaneChangeInst.RightSide.eLaneChangeState == FSW_ST_GERADELENKEN) &&
      (SALaneChangeInst.eRelObjLaneState == FSW_RELOBJ_AUSSPUR_L2))
  {
    if (SALaneChangeInst.RightSide.uiCorrection == iFSW_KNEUTRAL)
    {
      SALaneChangeInst.RightSide.uiCorrection = iFSW_KANF;
    }
    else if (SALaneChangeInst.RightSide.uiCorrection > iFSW_KEND)
    {
      SALaneChangeInst.RightSide.uiCorrection--;
    }
    else
    {
    }
  }
  else
  {
    SALaneChangeInst.RightSide.uiCorrection = iFSW_KNEUTRAL;
  }

#if (SIT_CFG_LC_PROB_CALC)
  /*! Calculation of lane change probability */
  SIT_v_CalcLaneChangeProbability(SLATE_f_GetCycleTime());
#else
  SIT_v_SetLCProbability();
#endif

#if (FCT_CFG_FIP_LANE_MATRIX_FUSION && SLATE_CFG_CAM_LANE_INTERFACE)
  /*! Determine if camera lane markers are crossed */
  SIT_v_StateCamLaneCrossing(&(pt_SITOutput->t_CamLaneMarkerCrossed), 
    &(t_SITCamLaneCrossedData.LeftLaneMarkerLastCycle), &(t_SITCamLaneCrossedData.RightLaneMarkerLastCycle));
#endif

#if (FCT_CFG_FIP_LANE_MATRIX_FUSION && SLATE_CFG_CAM_LANE_INTERFACE)
  /*! State if ego vehicle moves towards the new lane during the ego lane change, 
    i.e. before entering the new lane */
  SIT_v_SetLaneChangeMovePre(&pt_SITOutput->t_LaneChangeCamPreMoveState);
#endif

  /*--- AUFHEBUNG FUNKTIONSLOKALE SYMBOLISCHE KONSTANTEN ---*/

} /* end of EODetectLaneChange */ // PRQA S 7004
 /* date: 2011-06-11, reviewer: Lonard Jaison Manohar, reason: Cyclometric complexity, Not safety critical */


#if (SIT_CFG_LC_PROB_CALC)
/*************************************************************************************************************************
  Functionname:    SIT_v_InitLCProbDataGlobal                                                                           */ /*!

  @brief           Initialize the global data for lane change probability calculation, which need to be known beyond one cycle

  @description     Initialize the global data for lane change probability calculation, which need to be known beyond one cycle

                   @startuml
                   partition  SIT_v_InitLCProbDataGlobal {
                   start
                   	: Initialize the global data for lane change probability calculation, which need to be known beyond one cycle;
                   Stop
                   }
                   @enduml

  @return          -

  @param[in]       -

  @glob_in         -
  @glob_out        SITLCProbDataGlobal.iTLLeftPrevious : Turn light status of left turn light last cycle                                           [sint8 full range]
  @glob_out        SITLCProbDataGlobal.iTLRightPrevious : Turn light status of right turn light last cycle                                         [sint8 full range]
  @glob_out        SITLCProbDataGlobal.iProbability : Probabilities for a LC to the left and right side are combined                               [-100   100]
  @glob_out        SITLCProbDataGlobal.iProbabilityBefore : Lane change probability in last cycle                                                  [-100   100]
  @glob_out        SITLCProbDataGlobal.fDistLat : Distance driven in lateral direction during LC                                                   [-PI/2*RW_FCT_MAX   PI/2*RW_FCT_MAX]
  @glob_out        SITLCProbDataGlobal.fVelLat : Velocity in lateral direction during LC                                                           [-330f   330f]
  @glob_out        SITLCProbDataGlobal.fCurveLevel : Mean curve level                                                                              [-1f   1f]
  @glob_out        SITLCProbDataGlobal.fLCPsiBefore : Last heading angle independent of cycle time                                                 [-PI   PI]
  @glob_out        SITLCProbDataGlobal.fLCPsiBeforeBuffer : Heading angle in last cycle                                                            [-PI   PI]
  @glob_out        SITLCProbDataGlobal.fFilteredEgoCurve : Filtered ego curve                                                                      [-1f   1f]
  @glob_out        SITLCProbDataGlobal.fEgoCurvePT1Previous : Filtered ego curve last cycle                                                        [-1f   1f]
  @glob_out        SITLCProbDataGlobal.fDrvIntCurvePT1Previous : Filtered driver intended curve last cycle                                         [-1f   1f]
  @glob_out        SITLCProbDataGlobal.afLatDiffFilteredCurvesFilt[   ] : Filtered difference in lateral distance between filtered ego curve and filtered driver intended curve [-PI*RW_FCT_MAX    PI*RW_FCT_MAX]
  @glob_out        SITLCProbDataGlobal.afLatDiffCamCurveFilt[   ] : Filtered difference in lateral distance between camera curve and filtered driver intended curve             [-PI*RW_FCT_MAX    PI*RW_FCT_MAX]
  @glob_out        SITLCProbDataGlobal.fLCKinematicProb : lane change probability based on kinematic signals                                       [0f   100f]
  @glob_out        SITLCProbDataGlobal.fLCProbLeft : LC probability left                                                                           [0f   100f]
  @glob_out        SITLCProbDataGlobal.fLCProbRight : LC probability right                                                                         [0f   100f]
  @glob_out        SITLCProbDataGlobal.fLCProbFollow : LC probability follow                                                                       [0f   100f]
  @glob_out        SITLCProbDataGlobal.LCTurnLightEvalLeft.State : State of LC phase based on left turn light information                          [SILCTurnLightState_t defined in sit_lanechange.h]
  @glob_out        SITLCProbDataGlobal.LCTurnLightEvalLeft.fTimeAfterTLActivation : Duration after the left turn light was switched on last time   [0f  SIT_LC_PROB_MAX_TIME_AFTER_TURN_LIGHT_ACTIVE]
  @glob_out        SITLCProbDataGlobal.LCTurnLightEvalRight.State : State of LC phase based on right turn light information                        [SILCTurnLightState_t defined in sit_lanechange.h]
  @glob_out        SITLCProbDataGlobal.LCTurnLightEvalRight.fTimeAfterTLActivation : Duration after the lt turn light was switched on last time    [0f  SIT_LC_PROB_MAX_TIME_AFTER_TURN_LIGHT_ACTIVE]
  @glob_out        SITLCProbDataGlobal.CamLaneMarkerCrossedProbLeft : Left Camera lane marker crossed probability                                  [0u  100u]
  @glob_out        SITLCProbDataGlobal.CamLaneMarkerCrossedProbRight : Right Camera lane marker crossed probability                                [0u  100u]

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_SITUATION :  FCT support for ACC SIT (situation) sub-component
  @c_switch_full   SIT_CFG_LC_PROB_CALC  : Configuration switch enabling lane change probability calculation

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).


  @created         -
  @changed         12/17/2015

  @author          Marie-Theres Boll
*************************************************************************************************************************/
static void SIT_v_InitLCProbDataGlobal(void)
{
  SITLCProbDataGlobal.iTLLeftPrevious = 0;
  SITLCProbDataGlobal.iTLRightPrevious = 0;

  SITLCProbDataGlobal.iProbability = 0;
  SITLCProbDataGlobal.iProbabilityBefore = 0;

  SITLCProbDataGlobal.fDistLat           = 0.f;
  SITLCProbDataGlobal.fVelLat            = 0.f;
  SITLCProbDataGlobal.fCurveLevel        = 0.f;
  SITLCProbDataGlobal.fLCPsiBefore       = 0.f;
  SITLCProbDataGlobal.fLCPsiBeforeBuffer = 0.f;
  SITLCProbDataGlobal.fFilteredEgoCurve = 0.f;
  SITLCProbDataGlobal.fEgoCurvePT1Previous = 0.f;
  SITLCProbDataGlobal.fDrvIntCurvePT1Previous = 0.f;

  SITLCProbDataGlobal.afLatDiffFilteredCurvesFilt[0] = 0.f;
  SITLCProbDataGlobal.afLatDiffFilteredCurvesFilt[1] = 0.f;
  SITLCProbDataGlobal.afLatDiffCamCurveFilt[0] = 0.f;
  SITLCProbDataGlobal.afLatDiffCamCurveFilt[1] = 0.f;

#if (SIT_LC_CFG_USE_TURNIND_CAMERA_PROB)
  SITLCProbDataGlobal.CamLaneMarkerCrossedProbLeft = 0u;
  SITLCProbDataGlobal.CamLaneMarkerCrossedProbRight = 0u;
#endif /*!< SIT_LC_CFG_USE_TURNIND_CAMERA_PROB */

  SITLCProbDataGlobal.fLCKinematicProb = 0.f;
  SITLCProbDataGlobal.f_LCProbLeft     = 0.f;
  SITLCProbDataGlobal.f_LCProbRight    = 0.f;
  SITLCProbDataGlobal.fLCProbFollow    = 0.f;

  SITLCProbDataGlobal.LCTurnLightEvalLeft.State = SIT_LC_TURN_LIGHT_NOT_ACTIVE;
  SITLCProbDataGlobal.LCTurnLightEvalLeft.fTimeAfterTLActivation = SIT_LC_PROB_MAX_TIME_AFTER_TURN_LIGHT_ACTIVE;
  SITLCProbDataGlobal.LCTurnLightEvalRight.State = SIT_LC_TURN_LIGHT_NOT_ACTIVE;
  SITLCProbDataGlobal.LCTurnLightEvalRight.fTimeAfterTLActivation = SIT_LC_PROB_MAX_TIME_AFTER_TURN_LIGHT_ACTIVE;
}
	

/*************************************************************************************************************************
  Functionname:    SIT_v_InitLCProbDataLocal                                                                            */ /*!

  @brief           Initialize the local data for lane change probability calculation, which is calculated each cycle

  @description     Initialize the local data for lane change probability calculation, which is calculated each cycle

                   @startuml
                   partition  SIT_v_InitLCProbDataLocal {
                   start
                   	: Initialize the local data for lane change probability calculation, which is calculated in each cycle;
                   Stop
                   }
                   @enduml

  @return          -

  @param[in]       fCycleTime : Cycle time for determing the cycle time dependent parameter   [0f   1f]
  @param[out]      pSILCProbDataLocal : local data for lane change probability calculation; pointer to SITLCProbDataLocal_t defined in sit_lanechange.h
                      iProbabilityLaneChangeLeft                 [0    100]
                      iProbabilityLaneChangeRight                [0    100]
                      DynPar.fEgoCurvePT1X                       [-1f   1f]
                      DynPar.DriverIntCurveFilterConst[   ].f0   [-1f   1f]
                      DynPar.DriverIntCurveFilterConst[   ].f1   [-1f   1f]

  @glob_in         SITLCProbParData.SIT_LC_PROB_TABLE_DRIVER_INT_CURVE_FILTER_CONST[   ].f0 : Lane change probability points of a 2D Vector [full range float32 > 0]
  @glob_in         SITLCProbParData.SIT_LC_PROB_TABLE_DRIVER_INT_CURVE_FILTER_CONST[   ].f1 : lane change probability points of a 2D Vector [full range float32 > 0]
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_SITUATION :  FCT support for ACC SIT (situation) sub-component
  @c_switch_full   SIT_CFG_LC_PROB_CALC  : Configuration switch enabling lane change probability calculation

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         12/17/2015

  @author          Marie-Theres Boll
*************************************************************************************************************************/
static void SIT_v_InitLCProbDataLocal(const float32 fCycleTime, SITLCProbDataLocal_t * pSILCProbDataLocal)
{
  uint16 i;
  float32 f_Abs_EgoCurvePT1X_CycleTime, f_AbsDvrIntCrvFltrConstCylTime;
  /*! Lane Change probability left/right */
  pSILCProbDataLocal->iProbabilityLaneChangeLeft              = 0;
  pSILCProbDataLocal->iProbabilityLaneChangeRight             = 0;

  /*! Initialize parameters which depend on the cycle time */
  pSILCProbDataLocal->DynPar.fEgoCurvePT1X = 1.f;
  f_Abs_EgoCurvePT1X_CycleTime = fABS(SIT_LC_PROB_EGO_CURVE_PT1_X + fCycleTime);
  if (f_Abs_EgoCurvePT1X_CycleTime > C_F32_DELTA)
  {
    pSILCProbDataLocal->DynPar.fEgoCurvePT1X = SIT_LC_PROB_EGO_CURVE_PT1_X / (SIT_LC_PROB_EGO_CURVE_PT1_X + fCycleTime);
  }
  
  for(i = 0u; i < (uint16) SIT_LC_PROB_POINTS_DRIVER_INT_CURVE_FILTER_TABLE; i++)
  {
    pSILCProbDataLocal->DynPar.DriverIntCurveFilterConst[i].f0 = SITLCProbParData.SIT_LC_PROB_TABLE_DRIVER_INT_CURVE_FILTER_CONST[i].f0;
    pSILCProbDataLocal->DynPar.DriverIntCurveFilterConst[i].f1 = 1.f;
    f_AbsDvrIntCrvFltrConstCylTime = fABS(SITLCProbParData.SIT_LC_PROB_TABLE_DRIVER_INT_CURVE_FILTER_CONST[i].f1 + fCycleTime);
    if(f_AbsDvrIntCrvFltrConstCylTime > C_F32_DELTA)
    {
      pSILCProbDataLocal->DynPar.DriverIntCurveFilterConst[i].f1 = SITLCProbParData.SIT_LC_PROB_TABLE_DRIVER_INT_CURVE_FILTER_CONST[i].f1 /
        (SITLCProbParData.SIT_LC_PROB_TABLE_DRIVER_INT_CURVE_FILTER_CONST[i].f1 + fCycleTime);
    }
  }
}


/*************************************************************************************************************************
  Functionname:    SIT_v_InitLCProbDetectors                                                                            */ /*!

  @brief           Initialize the lane change probability for the single detectors

  @description     Initialize the lane change probability for the single detectors

                   @startuml
                   partition  SIT_v_InitLCProbDetectors {
                   start
                       : Initialize the lane change probabilities for 
                       -Lateral Difference between filtered ego curve and filtered driver curve
                       -Lateral Difference Camera curve and filtered driver intended curve
                       -Lateral Velcoity to Camera Lane
                       -Turn light information
                       -Driver distance in Lateral Direction
                       -Crossed Camera lane marker
                       -Based on curve(for low speed);
                   Stop
                   }
                   @enduml

  @return          -

  @param[in,out]   pSILCProbDetectors : Lane change probabilties for individual detectors; pointer to SILCProbDetectors_t defined in sit_lanechange.h
                      iLatDiffFilteredCurvesProb       [0u   100u]
                      iLatDiffCamCurveProb             [0u   100u]
                      iVelLatCamLaneMarkerProb         [0u   100u]
                      iTurnLightProb                   [0u   100u]
                      iDistLatProb                     [0u   100u]
                      iCamLaneMarkerCrossedProb        [0u   100u]
                      iCurveProb                       [0u   100u]

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_SITUATION :  FCT support for ACC SIT (situation) sub-component
  @c_switch_full   SIT_CFG_LC_PROB_CALC  : Configuration switch enabling lane change probability calculation

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         12/17/2015

  @author          Marie-Theres Boll
*************************************************************************************************************************/
static void SIT_v_InitLCProbDetectors(SILCProbDetectors_t * pSILCProbDetectors)
{
  pSILCProbDetectors->iLatDiffFilteredCurvesProb = 0u;
  pSILCProbDetectors->iLatDiffCamCurveProb = 0u;
  pSILCProbDetectors->iVelLatCamLaneMarkerProb = 0u;
  pSILCProbDetectors->iTurnLightProb = 0u;
  pSILCProbDetectors->iDistLatProb = 0u;
  pSILCProbDetectors->iCamLaneMarkerCrossedProb = 0u;
  pSILCProbDetectors->iCurveProb = 0u;
}


/*************************************************************************************************************************
  Functionname:    SIT_v_InitLCProbInputData                                                                            */ /*!

  @brief           Initialize the structure SITLCProbInputData_t

  @description     Initialize the structure SITLCProbInputData_t (Input data for the LC probability calculation)

                   @startuml
                   partition SIT_v_InitLCProbInputData {
                   start
                       : Initialize the inputs for Lane Change Probability calculation
                       -Filtered ego curve
                       -Filtered driver intended curve
                       -Driven distance in lateral direction
                       -Curve level
                       -Camera lane visibility
                       -Lane change left and right
                       -Camera curvature
                       -Lateral velocity to camera lane marker;
                   Stop
                   }
                   @enduml

  @return          -

  @param[in,out]   pSILCProbInputData : Input data to calculate the probability values; pointer to SITLCProbInputData_t defined in sit_lanechange.h
                      fEgoCurvePT1                                 [-1f   1f]
                      fDrvIntCurvePT1                              [-1f   1f]
                      fDistLat                                     [-PI/2*RW_FCT_MAX   PI/2*RW_FCT_MAX]
                      fCurveLevel                                  [-1f   1f]
                      CamLaneInfo.bCamLaneVisible                  [TRUE   FALSE]
                      CamLaneInfo.bCamLaneChangeLeft               [TRUE   FALSE]
                      CamLaneInfo.bCamLaneChangeRight              [TRUE   FALSE]
                      CamLaneInfo.fCameraCurvature                 [-1f   1f]
                      CamLaneInfo.fLateralVelocityToCamLaneMarker  [-330f   330f]



  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_SITUATION :  FCT support for ACC SIT (situation) sub-component
  @c_switch_full   SIT_CFG_LC_PROB_CALC  : Configuration switch enabling lane change probability calculation

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         12/28/2015

  @author          Marie-Theres Boll
*************************************************************************************************************************/
static void SIT_v_InitLCProbInputData(SITLCProbInputData_t * pSILCProbInputData)
{
  pSILCProbInputData->fEgoCurvePT1 = 0.f;
  pSILCProbInputData->fDrvIntCurvePT1 = 0.f;
  pSILCProbInputData->fDistLat = 0.f;
  pSILCProbInputData->fCurveLevel = 0.f;
  pSILCProbInputData->CamLaneInfo.bCamLaneVisible = FALSE;
  pSILCProbInputData->CamLaneInfo.bCamLaneChangeLeft = FALSE;
  pSILCProbInputData->CamLaneInfo.bCamLaneChangeRight = FALSE;
  pSILCProbInputData->CamLaneInfo.fCameraCurvature = 0.f;
  pSILCProbInputData->CamLaneInfo.fLateralVelocityToCamLaneMarker = 0.f;
}


/*************************************************************************************************************************
  Functionname:    SIT_v_LCProbSetTurnLightPhase                                                                        */ /*!

  @brief           Set the phase of the turn light relevant for the calculation of the lane change probability

  @description     Set the phase of the turn light relevant for the calculation of the lane change probability

                   @startuml 
                       Partition SIT_LCProbSetTurnLightPhase {
                   	Start
                           -Determine Turn Light status value
                               Partition SetHistoryBuffer {
                                   If(Lane Change Prob direction is left) then (true)
                                       -Update Turn Light Status change & TL Left prev signals
                                   Else(false)
                                       -Update Turn Light Status change & TL Right prev signals
                                   endif
                               }
                               Partition LaneChangeTurnLightActive {
                                   If((TimeafterTLActivation is > threshold) or (TLStatusactive is false)) then (true)
                                       -make TimeaftertTLActivation to the set threshold
                                       -Update state to not active
                                   Elseif(Turnlightstatuschange is > 0) then (true)
                                       -make TimeafterTLActivation to zero
                                        Elseif(TimeafterTLActivation is < threshold) then (true)
                                       -Update TimeafterTLActivation with the Cycle time
                                   Else(false)
                                       -Do nothing
                                   Endif
                               }
                               Partition LaneChangeTurnLightNotActive {
                                   If(TurnLightStatusChange is > 0) then (true)
                                       -Make TimeafterTLActivation to zero
                                       -Update State to Active 
                                   Elseif(TurnLightStatusChange is < 0) then (true)
                                       -Update TimeafterTLActivation signal
                                   Elseif(TimeafterTLActivation is < threshold) then (true)
                                       -Update TimeafterTLActivation with the Cycle Time
                                   Else(false)
                                       -Do nothing    
                                   Endif
                               }
                           -Set State to TurnLightNotactive
                           -Set TimeafterTLActivation to the respective threshold 
                   End 
                      }
                   @enduml

  @return          -

  @param[in]       fCycleTime                 [0f   1f]
  @param[in]       LCProbDirection            [SITLCProbDirection_t defined in sit_lanechange.h]
  @param[in]       bTLStatusActive            [TRUE, FALSE]
  @param[in,out]   pTLEval : evaluation of turn light for lane change probability; pointer to SITLCProbTurnLightEval_t defined in sit_lanechnage.h
                      State                   [type SILCTurnLightState_t defined in sit_lanechange.h]
                      fTimeAfterTLActivation  [full range float32>=0]


  @glob_in         -
  @glob_out        SITLCProbDataGlobal.iTLLeftPrevious         [full range sint8]
  @glob_out        SITLCProbDataGlobal.iTLRightPrevious        [full range sint8]

  @c_switch_part   -
  @c_switch_full   SIT_CFG_LC_PROB_CALC  : Configuration switch enabling lane change probability calculation
  @c_switch_full   FCT_CFG_ACC_SITUATION :  FCT support for ACC SIT (situation) sub-component
  @c_switch_full   SIT_LC_CFG_USE_TURNIND_CAMERA_PROB : Configuration switch to enable lane change probability calculation using turn indicator input and camera lane input

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         1/12/2016

  @author          Marie-Theres Boll
*************************************************************************************************************************/
static void SIT_v_LCProbSetTurnLightPhase( const float32 fCycleTime, const SITLCProbDirection_t LCProbDirection, const boolean bTLStatusActive, SITLCProbTurnLightEval_t * pTLEval )
{
  sint8 iTLStatus, iTLStatusChange;

  /*! Determine turn light status (integer value for calculation) */
  iTLStatus  = (bTLStatusActive == TRUE) ? (sint8) 1 : (sint8) 0;

  /*! Determine turn light status change (integer value for calculation) */
  

  /*! Set history buffer */
  if(LCProbDirection == LC_PROB_LEFT)
  {
    iTLStatusChange = iTLStatus - SITLCProbDataGlobal.iTLLeftPrevious;
    SITLCProbDataGlobal.iTLLeftPrevious = iTLStatus;
  }
  else
  {
    iTLStatusChange = iTLStatus - SITLCProbDataGlobal.iTLRightPrevious;
    SITLCProbDataGlobal.iTLRightPrevious = iTLStatus;
  }

   /*! State machine: Set state and time after activation of turn light */
  switch (pTLEval->State)
  {
    /*! If turn light was ACTIVE in the last cycle */
    case SIT_LC_TURN_LIGHT_ACTIVE:
#if (SIT_LC_CFG_USE_TURNIND_CAMERA_PROB)
      if(iTLStatusChange > 0)
      { 
        /*! If turn light activated although SIT_LC_TURN_LIGHT_ACTIVE phase still active -> reset timer */
        pTLEval->fTimeAfterTLActivation = 0.f;
      }
      else if ( (bTLStatusActive == FALSE) && (pTLEval->fTimeAfterTLActivation <= SIT_LC_PROB_MIN_TIME_TURN_LIGHT_ON) )
      {
        /*! If turn light switched off but the time since turn light activation is shorter than minimum time, then increment the timer */
        pTLEval->fTimeAfterTLActivation += fCycleTime;
      }
      else if( (pTLEval->fTimeAfterTLActivation > SIT_LC_PROB_MIN_TIME_TURN_LIGHT_ON) || (bTLStatusActive == FALSE) )
      {
        /* Transition from ACTIVE to NON_ACTIVE: 
          if turn light switched off
          if turn light is on for a longer time than the maximum time for considering a turn light on 
          if turn light is off */
        /*! Set timer to the maximum value for considering the turn light ACTIVE */
        pTLEval->fTimeAfterTLActivation = SIT_LC_PROB_TURN_LIGHT_OFF;
        /*! Set state */
        pTLEval->State = SIT_LC_TURN_LIGHT_NOT_ACTIVE;
      }
#else
      if(  (pTLEval->fTimeAfterTLActivation > SIT_LC_PROB_MAX_TIME_TURN_LIGHT_ON) || (bTLStatusActive == FALSE) )
      {
        /* Transition from ACTIVE to NON_ACTIVE: 
            if turn light switched off
            if turn light is on for a longer time than the maximum time for considering a turn light on 
            if turn light is off */
        /*! Set timer to the maximum value for considering the turn light ACTIVE */
        pTLEval->fTimeAfterTLActivation = SIT_LC_PROB_MAX_TIME_TURN_LIGHT_ON;
        /*! Set state */
        pTLEval->State = SIT_LC_TURN_LIGHT_NOT_ACTIVE;
      }
      else if(iTLStatusChange > 0)
      { /*! If turn light activated although SIT_LC_TURN_LIGHT_ACTIVE phase still active -> reset timer */
        pTLEval->fTimeAfterTLActivation = 0.f;
      }
#endif /*!< SIT_LC_CFG_USE_TURNIND_CAMERA_PROB */
      else
      {
        /*! Remain ACTIVE, increase timer (if below maximum value) */
        if(pTLEval->fTimeAfterTLActivation < SIT_LC_PROB_MAX_TIME_AFTER_TURN_LIGHT_ACTIVE)
        {
          pTLEval->fTimeAfterTLActivation += fCycleTime;
        }
      }
      break;
    /*! If turn light was NOT ACTIVE in the last cycle */
    case SIT_LC_TURN_LIGHT_NOT_ACTIVE:
      if( (iTLStatusChange > 0) )
      {
        /*! Transition from NON ACTIVE to ACTIVE
            if turn light change indicates the activation
            if turn light active */
        /*! Set timer, which indicates the time after activation of the turn light, to zero */
        pTLEval->fTimeAfterTLActivation = 0.f;
        /*! Set state */
        pTLEval->State = SIT_LC_TURN_LIGHT_ACTIVE;
      }
      else if(iTLStatusChange < 0)
      {
#if (SIT_LC_CFG_USE_TURNIND_CAMERA_PROB)
        /*! Reset timer to maximum value if turn light change indicates the deactivation of the turn light although state already NON ACTIVE */
        pTLEval->fTimeAfterTLActivation = MAX_FLOAT(SIT_LC_PROB_TURN_LIGHT_OFF, pTLEval->fTimeAfterTLActivation);
#else
        /*! Reset timer to maximum value if turn light change indicates the deactivation of the turn light although state already NON ACTIVE */
        pTLEval->fTimeAfterTLActivation = MAX_FLOAT(SIT_LC_PROB_MAX_TIME_TURN_LIGHT_ON, pTLEval->fTimeAfterTLActivation);
#endif /*!< SIT_LC_CFG_USE_TURNIND_CAMERA_PROB */
      }
      else
      {
#if (SIT_LC_CFG_USE_TURNIND_CAMERA_PROB)
        /*! Remain INACTIVE, increase timer (if below maximum value) */
        if(pTLEval->fTimeAfterTLActivation < SIT_LC_PROB_MAX_TIME_TURN_LIGHT_ON)
        {
          pTLEval->fTimeAfterTLActivation += fCycleTime;
        }
        else
        {
          /*! Set the timer to the maximum value */
            pTLEval->fTimeAfterTLActivation = SIT_LC_PROB_MAX_TIME_AFTER_TURN_LIGHT_ACTIVE;
        }
#else
        /*! Remain INACTIVE, increase timer (if below maximum value) */
        if(pTLEval->fTimeAfterTLActivation < SIT_LC_PROB_MAX_TIME_AFTER_TURN_LIGHT_ACTIVE)
        {
          pTLEval->fTimeAfterTLActivation += fCycleTime;
        }
#endif /*!< SIT_LC_CFG_USE_TURNIND_CAMERA_PROB */
      }
      break;
    default:
      /*! Set default values */
      pTLEval->State = SIT_LC_TURN_LIGHT_NOT_ACTIVE;
      pTLEval->fTimeAfterTLActivation = SIT_LC_PROB_MAX_TIME_AFTER_TURN_LIGHT_ACTIVE;
      break;
  }
}


/*************************************************************************************************************************
  Functionname:    SIT_v_LCProbGetCamLaneInfo                                                                           */ /*!

  @brief           Get camera lane information for lane change probability calculation

  @description     Get camera lane information for lane change probability calculation

                    @startuml 
                        Partition SIT_LCProbGetCamLaneInfo {
                    	Start
                            -Update all the necessary signals with respective values
                                Partition CamLaneInterfaceisturnedon {
                                    If(CamLaneVisibilityDistance is > threshold) then (true)
                                        -Update all the necessary signals to the initialization values
                                    If((Existence Prob of left is >= threshold) && (Sigstatus == ok)&& (Marker distance of left is < 0)) then (true)
                                        -Set CamLaneChangeLeft to True
                                    Endif
                            -Set CamLAneChangeRight to False
                                    If((Existence Prob of right is >= threshold) && (Sigstatus == ok)&& (Marker distance of right is > 0)) then (true)
                                        -Set CamLaneChangeRight to True
                                    Endif
                            -Update deltapsi buffer
                                    If(Absolute value of deltapsi is > threshold) then (true)
                                        -update lane change psi before
                                    Endif
                                    If(Difference in angle is not allowed to be higher than threshold) then (true)
                                        -Set Cam lane change left and right to false
                                    Endif
                                    Else (false)
                                        -Parameter is unused
                                    Endif
                            -SetlanechangePsibeforebuffer to psi
                         End 
                    }
                    @enduml

  @return          -

  @param[in,out]   pCamLaneEval : camera lane for lane change probability calculation; pointer to SITLCProbCamLaneInfo_t defined in sit_lanechange.h
                      fCameraCurvature                   [-1f   1f]
                      bCamLaneVisible                    [TRUE, FALSE]
                      fLateralVelocityToCamLaneMarker    [-330f   330f]
                      bCamLaneChangeLeft                 [TRUE, FALSE]
                      bCamLaneChangeRight                [TRUE, FALSE]

  @glob_in         pt_SITInput->pt_FIPCamLane->f_VisibilityDist : Visibility distance of the camera lane [full range float32]
  @glob_in         pt_SITInput->pt_FIPCamLane->f_Curve : Curvature of the camera lane [Full range of pf_Curve as defined in sit_ext.h]
  @glob_in         pt_SITInput->pt_FIPCamLane->f_HeadingAngle : Heading angle relative to the camera lane [Full range of pf_HeadingAngle as defined in sit_ext.h]  
  @glob_in         pt_SITInput->t_RTE.pf_EgoLongVel                                                     [-330f   330f]
  @glob_in         pt_SITInput->t_RTE.pt_CamLaneData->LaneMarkerInfo[   ].u_ExistanceProbability        [0u   100u]
  @glob_in         pt_SITInput->t_RTE.pt_CamLaneData->sSigHeader.eSigStatus                             [AlgoSignalState_t defined in Rte_Type.h]
  @glob_in         pt_SITInput->t_RTE.pt_CamLaneData->LaneMarkerInfo[   ].f_MarkerDist                  [-100f   100f]
  @glob_in         SITLCProbDataGlobal.fLCPsiBeforeBuffer                                               [full range float32]
  @glob_out        SITLCProbDataGlobal.fLCPsiBeforeBuffer                                  [full range float32]
  @glob_out        SITLCProbDataGlobal.fLCPsiBefore                                        [full range float32]

  @c_switch_part   FCT_CFG_INPUT_PREPROCESSSING   : FCT support for FCT Input Preprocessing
  @c_switch_part   SLATE_CFG_CAM_LANE_INTERFACE : Configuration switch enabling camera lane input data to FCT_SEN
  @c_switch_full   SIT_CFG_LC_PROB_CALC           : Configuration switch enabling lane change probability calculation
  @c_switch_full   FCT_CFG_ACC_SITUATION          :  FCT support for ACC SIT (situation) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         1/12/2016

  @author          Marie-Theres Boll
*************************************************************************************************************************/
static void SIT_v_LCProbGetCamLaneInfo(SITLCProbCamLaneInfo_t * pCamLaneEval)
{
  float32 fPsi;
#if ((FCT_CFG_INPUT_PREPROCESSSING) && (SLATE_CFG_CAM_LANE_INTERFACE))
  const float32 f_CamLaneVisibilityDist= (pt_SITInput->pt_FIPCamLane->f_VisibilityDist); /*!< Visibility distance of camera lane */
  const float32 f_CamLaneC0 = (pt_SITInput->pt_FIPCamLane->f_Curve);                     /*!< Curvature of camera lane */
  const float32 f_CamLaneAngle = (pt_SITInput->pt_FIPCamLane->f_HeadingAngle);           /*!< Heading angle of camera lane */
#endif

  /*! Set default value */
  fPsi = 0.f;

#if ((FCT_CFG_INPUT_PREPROCESSSING) && (SLATE_CFG_CAM_LANE_INTERFACE))
  if (f_CamLaneVisibilityDist > SIT_LC_PROB_MIN_DIST_CAM_COURSE)
  {
    float32 fDeltaPsi;
    float32 f_abs_DeltaPsi;
    float32 f_Abs_LCPsiBefore_Psi;

    pCamLaneEval->fCameraCurvature = f_CamLaneC0;
    fPsi = -f_CamLaneAngle;

    /* Since course has a valid estimation length, set camera lane visibility to TRUE */
    pCamLaneEval->bCamLaneVisible = TRUE;

    /*! Calculate the camera lane relative lateral speed using the course orientation angle and the ego speed 
        -> lateral velocity towards camera lane markers */
    pCamLaneEval->fLateralVelocityToCamLaneMarker = SIN_HD_(fPsi) * (*pt_SITInput->t_RTE.pf_EgoLongVel);

    /* Check if we will cross the left lane marker within our prediction time */
    pCamLaneEval->bCamLaneChangeLeft = FALSE;
    if( (pt_SITInput->t_RTE.pt_CamLaneData->LaneMarkerInfo[FIP_CL_MK_LEFT].u_ExistanceProbability >= FIP_CAM_LANE_POE_LEVEL) &&
        (pt_SITInput->t_RTE.pt_CamLaneData->sSigHeader.eSigStatus == AL_SIG_STATE_OK) &&
      ( (pt_SITInput->t_RTE.pt_CamLaneData->LaneMarkerInfo[FIP_CL_MK_LEFT].f_MarkerDist - (pCamLaneEval->fLateralVelocityToCamLaneMarker * SIT_LC_PROB_TIME_CAM_LANE_MARKER_CROSSED)) < 0.f )
      )
    {
      pCamLaneEval->bCamLaneChangeLeft = TRUE;
    }

    /* Check if we will cross the right lane marker within our prediction time */
    pCamLaneEval->bCamLaneChangeRight = FALSE;
    if( (pt_SITInput->t_RTE.pt_CamLaneData->LaneMarkerInfo[FIP_CL_MK_RIGHT].u_ExistanceProbability >= FIP_CAM_LANE_POE_LEVEL) &&
        (pt_SITInput->t_RTE.pt_CamLaneData->sSigHeader.eSigStatus == AL_SIG_STATE_OK) &&
      ( (pt_SITInput->t_RTE.pt_CamLaneData->LaneMarkerInfo[FIP_CL_MK_RIGHT].f_MarkerDist - (pCamLaneEval->fLateralVelocityToCamLaneMarker * SIT_LC_PROB_TIME_CAM_LANE_MARKER_CROSSED)) > 0.f )
      )
    {
      pCamLaneEval->bCamLaneChangeRight = TRUE;
    }

    /* Update of psi buffer (only if change detected, since other cycle time than FCT) */
    fDeltaPsi = SITLCProbDataGlobal.fLCPsiBeforeBuffer - fPsi;
    f_abs_DeltaPsi = fABS(fDeltaPsi);
    if (f_abs_DeltaPsi > C_F32_DELTA)
    {
      SITLCProbDataGlobal.fLCPsiBefore = SITLCProbDataGlobal.fLCPsiBeforeBuffer;
    }
    /* Check plausibility: Difference in angle is not allowed to be higher than a threshold SIT_LC_PROB_MAX_DIFF_PSI*/
    f_Abs_LCPsiBefore_Psi = fABS(SITLCProbDataGlobal.fLCPsiBefore - fPsi);
    if (f_Abs_LCPsiBefore_Psi > SIT_LC_PROB_MAX_DIFF_PSI)
    {
      pCamLaneEval->bCamLaneChangeLeft = FALSE;
      pCamLaneEval->bCamLaneChangeRight = FALSE;
    }
  }
#else
  /* Remark: pCamLaneEval still has initial values which show that no camera lane data available */
  _PARAM_UNUSED(pCamLaneEval);
#endif
  SITLCProbDataGlobal.fLCPsiBeforeBuffer = fPsi;
}

/*************************************************************************************************************************
  Functionname:    SIT_v_LCProbGetEgoMotionInfo                                                                         */ /*!

  @brief           Get ego motion information for lane change probability calculation

  @description     Get ego motion information for lane change probability calculation -> Filtering of ego curve and driver intended curve

                   @startuml
                   partition  SIT_v_LCProbGetEgoMotionInfo {
                   start
                       :Filter the ego curve
                           -Filter the ego curve from VDY  using a low pass filter and a constant SIT_LC_PROB_FILTER_CONST_EGO_CURVE
                           -Filtered the low pass filtered curve using a filter coefficient.
                           -Store the filtered ego curve in history buffer for next cycle;
                       :Filter the driver intended curve
                           -Derive filter constant for driver intended curve derived on Polygon fir method and based on driver intended curve variance
                           -Filter the driver intended curve using the filter constant derived based on Polygon fit method.
                           -Store the filtered driver intended curve value in history buffer for next cycle computation;
                   Stop
                   }
                   @enduml

  @return          -

  @param[in]       pSILCProbDataLocal : Local data for lane change probability calculation; pointer to SITLCProbDataLocal_t defned in sit_lanechange.h
                      DynPar.fEgoCurvePT1X                                                                 [-1f   1f]
                      DynPar.DriverIntCurveFilterConst                                                     [GDBVector2_t defined in cml_mapping.h]
  @param[in,out]   pfEgoCurvePT1 : Filtered ego curve                                                      [-1f   1f]
  @param[in,out]   pfDrvIntCurvePT1 : Filtered driver intended curve                                       [-1f   1f]
    
  @glob_in         SITLCProbDataGlobal.fFilteredEgoCurve                                                   [-1f   1f]  
  @glob_in         SITLCProbDataGlobal.fEgoCurvePT1Previous                                                [-1f   1f]
  @glob_in         SITLCProbDataGlobal.fDrvIntCurvePT1Previous : Filtered driver intended curve last cycle [-1f   1f]
  @glob_in         pt_SITInput->t_RTE.pf_EgoCurve                                                          [-1f   1f]
  @glob_in         pt_SITInput->t_RTE.pf_EgoDrvIntCurveVar                                                 [-1f   1f]
  @glob_in         pt_SITInput->t_RTE.pf_EgoDrvIntCurve                                                    [-1f   1f]

  @glob_in         -
  @glob_out        SITLCProbDataGlobal.fFilteredEgoCurve                                                   [-1f   1f]
  @glob_out        SITLCProbDataGlobal.fDrvIntCurvePT1Previous : Filtered driver intended curve last cycle [-1f   1f]

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_SITUATION :  FCT support for ACC SIT (situation) sub-component
  @c_switch_full   SIT_CFG_LC_PROB_CALC  : Configuration switch enabling lane change probability calculation

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         1/12/2016

  @author          Marie-Theres Boll
*************************************************************************************************************************/
static void SIT_v_LCProbGetEgoMotionInfo(const SITLCProbDataLocal_t * pSILCProbDataLocal, float32 * pfEgoCurvePT1, float32 * pfDrvIntCurvePT1)
{
  float32 fPT1ConstDrvIntCurve; /*!< Filter constant for driver intended curve */

  /*! Filter ego curve */
  /*! Filter the ego curvature to mimic behavior of old ARS300 signals, where the VDY yaw rate had a latency of approximately 200ms */
  SITLCProbDataGlobal.fFilteredEgoCurve = GDB_FILTER(*pt_SITInput->t_RTE.pf_EgoCurve, SITLCProbDataGlobal.fFilteredEgoCurve, SIT_LC_PROB_FILTER_CONST_EGO_CURVE);

  /*! Filter the ego curvature as done in ARS300 */
  (*pfEgoCurvePT1) = ( ( SITLCProbDataGlobal.fEgoCurvePT1Previous - SITLCProbDataGlobal.fFilteredEgoCurve ) * pSILCProbDataLocal->DynPar.fEgoCurvePT1X ) + SITLCProbDataGlobal.fFilteredEgoCurve;

  /*! Store result in history buffer */
  SITLCProbDataGlobal.fEgoCurvePT1Previous = (*pfEgoCurvePT1);

  /*! Filter driver intended curve */
  /*! Get filter constant for driver intended curve based on driver intended curve variance (Remark: *pt_SITInput->t_RTE.pf_EgoDrvIntCurveVar >= 0) */
  fPT1ConstDrvIntCurve = GDB_Math_CalculatePolygonValue(SIT_LC_PROB_POINTS_DRIVER_INT_CURVE_FILTER_TABLE, pSILCProbDataLocal->DynPar.DriverIntCurveFilterConst, 
    SQRT_(*pt_SITInput->t_RTE.pf_EgoDrvIntCurveVar));

  /*! Filter driver intended curve */
  (*pfDrvIntCurvePT1) = ( ( SITLCProbDataGlobal.fDrvIntCurvePT1Previous - (*pt_SITInput->t_RTE.pf_EgoDrvIntCurve) ) * fPT1ConstDrvIntCurve ) + (*pt_SITInput->t_RTE.pf_EgoDrvIntCurve);

  /*! Store result in history buffer */
  SITLCProbDataGlobal.fDrvIntCurvePT1Previous = (*pfDrvIntCurvePT1);
}

/*************************************************************************************************************************
  Functionname:    SIT_v_LCProbGetDrivenDistVeloLateralDuringLC                                                         */ /*!

  @brief           Calculation of distance driven and velocity in lateral direction after a LC-maneuver started

  @description     Calculation of distance driven and velocity in lateral direction after a LC-maneuver started

                   @startuml
                   partition SIT_v_LCProbGetDrivenDistVeloLateralDuringLC {
                   start
                       Note right
                           This function determines the distance driven in lateral direction after a LC-manuever started
                       End note
                       IF (Lateral Velocity of ego is positive and difference between Driver intended curve and Low pass filtered Curve level is positive \n \t\t\t\t\t\t\t\t\t\t\t OR \n Lateral velocity of ego is negative and difference between Driver intended curve and low pass filtered curve level is negative  ) then (yes)
                           : Determine the difference in lateral distance between filtered ego curve and \n filtered driver intended curve>
                       Else
                           :The curve difference is reset to zero>
                       Endif
                       If (Difference between Ego curve and driver intended curve exceeds threshold\n
                   \t\t\t\t\t\t\t\t\t\t\t OR \n Calculated difference between filtered ego curve and filtered driver intended curve is greater than threshold \n\t\t\t\t\t\t\t\t\t\t\t  OR \n LC probability of last cycle higher than a threshold) then (yes)
                           :Determine the lateral velocity>
                           If (Ego Speed is greater than minimum threshold) then (yes)
                               :Determine the driven distance in lateral direction>
                           Endif
                       Else
                           :Reset Lateral distance
                           Reset Lateral velocity>
                       endif
                   Stop
                   }
                   @enduml

  @return          -

  @param[in]       fCycleTime : Cycle time                          [0f   1f]
  @param[in]       fEgoCurvePT1 : Filtered ego curve                [-1f   1f]
  @param[in]       fDrvIntCurvePT1 : Filtered driver intended curve [-1f   1f]
  @param[out]      pfDistLat : Distance driven in lateral direction [-PI/2*RW_FCT_MAX   PI/2*RW_FCT_MAX]

  @glob_in         SITLCProbDataGlobal.fVelLat                      [-330f   330f]
  @glob_in         SITLCProbDataGlobal.fCurveLevel                  [-1f   1f]
  @glob_in         SITLCProbDataGlobal.iProbabilityBefore           [-100f   100f]
  @glob_in         SITLCProbDataGlobal.fDistLat                     [-PI/2*RW_FCT_MAX   PI/2*RW_FCT_MAX]
  @glob_in         pSLATE_EgoDynRaw->Lateral.Accel.LatAccel        [-100f   100f]
  @glob_in         pt_SITInput->t_RTE.pf_EgoLongVel                 [-330f   330f]
  @glob_in         pt_SITInput->t_RTE.pf_EgoCurve                   [-1f   1f]

  @glob_out        SITLCProbDataGlobal.fVelLat                      [-330f   330f]
  @glob_out        SITLCProbDataGlobal.fDistLat                     [-PI/2*RW_FCT_MAX   PI/2*RW_FCT_MAX]

  @c_switch_part   -
  @c_switch_full   SIT_CFG_LC_PROB_CALC  : Configuration switch enabling lane change probability calculation
  @c_switch_full   FCT_CFG_ACC_SITUATION :  FCT support for ACC SIT (situation) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         1/12/2016

  @author          Marie-Theres Boll
*************************************************************************************************************************/
static void SIT_v_LCProbGetDrivenDistVeloLateralDuringLC(const float32 fCycleTime, const float32 fEgoCurvePT1, const float32 fDrvIntCurvePT1, float32 * pfDistLat)
{
  float32 fDistCurveDiff;
  /*Defining local variables from reference pointer*/
  float32 f_EgoSpeed = *pt_SITInput->t_RTE.pf_EgoLongVel;
  float32 fXSqr;
  float32 f_ABS_DrvIntCurvePT1CurveLevel;
  const sint16 f_AbsProbBefore = ABS(SITLCProbDataGlobal.iProbabilityBefore);
  /*! Calculation of distance driven in lateral direction after a LC-maneuver started */
  /*! Determine the difference in lateral distance between filtered ego curve and filtered driver intended curve in 1s */
  if ( ((SITLCProbDataGlobal.fVelLat >= 0.f) && ((fDrvIntCurvePT1 - SITLCProbDataGlobal.fCurveLevel) > 0.f) ) || 
    ((SITLCProbDataGlobal.fVelLat <= 0.f) && ((fDrvIntCurvePT1 - SITLCProbDataGlobal.fCurveLevel) < 0.f) ) )
  {
    fDistCurveDiff = fABS(0.5f * ( fEgoCurvePT1 - fDrvIntCurvePT1 ) * f_EgoSpeed * f_EgoSpeed * SIT_LC_PROB_DIFF_CURVE_FACTOR);
  }
  else
  {
    fDistCurveDiff = 0.f;
  }

  /*! Determine the lateral velocity/driven distance in lane change situation 
      (difference between ego curve and driver intended curve higher than a threshold, fDistCurveDiff higher than a threshold, 
       LC prob of last cycle higher than a threshold ); otherwise set values to zeros */
 f_ABS_DrvIntCurvePT1CurveLevel = fABS((fDrvIntCurvePT1 - SITLCProbDataGlobal.fCurveLevel));
  if( (f_ABS_DrvIntCurvePT1CurveLevel > SIT_LC_PROB_MIN_DIFF_CURVE_ANALYSE_DISTLAT) || 
      (fDistCurveDiff > SIT_LC_PROB_MIN_DIST_DIFF_CURVE_ANALYSE_DISTLAT) || 
      (f_AbsProbBefore > (sint16) SIT_LC_PROB_MIN_LCPROB_ANALYSE_DISTLAT) 
    )
  {
    
    /*! Determine the lateral velocity */
    SITLCProbDataGlobal.fVelLat = (pSLATE_EgoDynRaw->Lateral.Accel.LatAccel * fCycleTime) + SITLCProbDataGlobal.fVelLat;

    /*! Determine the driven distance in lateral direction */
    if (f_EgoSpeed > C_F32_DELTA )
    {
      fXSqr = SQR(f_EgoSpeed * fCycleTime);
      SITLCProbDataGlobal.fDistLat += 0.5f * (*pt_SITInput->t_RTE.pf_EgoCurve) * fXSqr;
    }
  }
  else
  {
    SITLCProbDataGlobal.fDistLat = 0.f;
    SITLCProbDataGlobal.fVelLat = 0.f;
  }

  *pfDistLat = SITLCProbDataGlobal.fDistLat;
}


/*************************************************************************************************************************
  Functionname:    SIT_v_CalcLaneChangeProbability                                                                      */ /*!

  @brief           Calculation of lane change probability

  @description     Calculation of lane change probability

                   @startuml
                   partition  SIT_v_CalcLaneChangeProbability {
                   start
                       : Set turn light state based on input data;
                       : Determine lane change phase based on turn light information left
                       <b>SIT_v_LCProbSetTurnLightPhase</b>;
                       : Determine lane change phase based on turn light information right
                       <b>SIT_v_LCProbSetTurnLightPhase</b>;
                       :Get camera lane information for lane change probability calculation
                       <b>SIT_v_LCProbGetCamLaneInfo</b>;
                          :Filtering of ego curve and driver intended curve
                          <b>SIT_v_LCProbGetEgoMotionInfo</b>;
                       If (EgoSpeed is greater than minimum threshold and Driver intended curve is lower than threshold) then (yes)
                           :Filter the curve over a timer factor>
                       Else
                           :Curve level is zero>
                       Endif
                       : Calculate of distance driven in lateral direction after a LC-maneuver started
                       <b>SIT_v_LCProbGetDrivenDistVeloLateralDuringLC</b>;
                       :Copy all the LC probability inputs and calculated intermediate outputs to a new structure for both left and right;
                       :Calculate difference in lateral distance between filtered ego curve and filtered driver intended curve;
                       :Calculate lane change probabilities for following based on look up table or using border values
                       -Difference between Camera curve and filtered driver intended curve in 1s
                       -Lateral velocity towards camera lane marker
                       -Turn lights
                       -Driven distance in lateral direction;
                       If (lane change direction is left and Camera lane change is left) then (yes)
                           : Set Camera lane marker crossed probability to 100>
                       Else if (lane change direction is right and Camera lane change is right) then (yes)
                           : Set Camera lane marker crossed probability to 100>
                       Endif
                       :Combine all the calculated probabilities using Bayes theorem;
                       If (Ego speed is greater than minimum threshold) then (yes)
                           If (Camera information available) then (yes)
                               :Combine probabilities calculated from Lateral velocity to camera lane marker and Turn light>
                           Else
                               :Consider only turn light probability>
                           Endif
                           If (Camera lane visibility is true) then (yes)
                               :Consider only camera lane marker crossed probability>
                           Endif
                       Else
                           If(Camera information available) then (yes)
                               :Combine probabilities from 
                               -Lateral velocity to camera lane marker
                               -Turn light
                               -Lateral difference between filtered curves
                               -Curvature
                               -Camera lane marker crossed>
                           Else
                               :Combine probabilities from
                               -Turn light
                               -Curvature>
                           Endif
                       Endif
                       :Store the respective probability results;
                   Stop
                   }
                   @enduml

  @return          -

  @param[in]       fCycleTime : Cycle time                          [0f   1f]

  @glob_in         pt_SITInput->t_RTE.pt_TurnIndicator                                                                   [eTurnIndicator_t defined in interfacediverinput.h]
  @glob_in         SITLCProbDataGlobal.LCTurnLightEvalLeft : LC phase based on turn light for evaluation of a LC left     
  @glob_in         SITLCProbDataGlobal.LCTurnLightEvalRight : LC phase based on turn light for evaluation of a LC right   
  @glob_in         SILCProbInput.CamLaneInfo    
  @glob_in         pt_SITInput->t_RTE.pf_EgoLongVel                                                                      [-330f   330f]
  @glob_out        SITLCProbDataGlobal.fCurveLevel                                                                       [-1f   1f]
  @glob_in         SITLCProbDataGlobal.LCTurnLightEvalRight.fTimeAfterTLActivation                                       [full range float32 >=0]
  @glob_in         SITLCProbDataGlobal.LCTurnLightEvalLeft.fTimeAfterTLActivation                                        [full range float32 >=0]
  @glob_in         SITLCProbDataGlobal.afLatDiffFilteredCurvesFilt[   ] : filtered difference in lateral distance        [-PI*RW_FCT_MAX    PI*RW_FCT_MAX]
  @glob_in         SITLCProbDataGlobal.afLatDiffCamCurveFilt[  ]                                                         [full range float32 >=0]
  @glob_in         SITLCProbParData.SIT_LC_PROB_TABLE_DIFF_LAT_FILT_CURVES : converts distance into LC probability       [0f    100f]
  @glob_in         SITLCProbParData.SIT_LC_PROB_TABLE_LAT_VEL_CAM_LANE_MARKER                                            [GDBVector2_t defined in cml_mapping.h]
  @glob_in         SITLCProbParData.SIT_LC_PROB_TABLE_TURN_LIGHT                                                         [GDBVector2_t defined in cml_mapping.h]
  @glob_in         SITLCProbParData.SIT_LC_PROB_TABLE_LAT_DIST                                                           [GDBVector2_t defined in cml_mapping.h]
  @glob_in         SITLCProbParData.SIT_LC_PROB_TABLE_CURVE[   ] : converts curve into probabilty                        [0f    100f]
  @glob_in         SITLCProbParData.SIT_LC_PROB_TABLE_COMB_CAM_PROB[   ] : combination of camera probabilites into a single probability                   [0u    100u]
  @glob_in         SITLCProbParData.SIT_LC_PROB_TABLE_COMB_LOWSPEED_TURNLIGHT[   ] : combination of LC probabilty with turn light probability             [0u    100u]
  @glob_in         SITLCProbParData.SIT_LC_PROB_TABLE_COMB_LATDIST_LATDIFFCURVE[   ] : combination of LC probabilty with distance in lateral direction    [0u    100u]
  @glob_in         SITLCProbParData.SIT_LC_PROB_TABLE_COMB_CURVE[   ] : combination of LC probability with curvature based probability                    [0u    100u]
  @glob_in         SITLCProbParData.SIT_LC_PROB_TABLE_COMB_MARKERCROSSING[   ] : combination of LC probability with crossing of lane markings             [0u    100u]
  @glob_out        SITLCProbDataGlobal.afLatDiffFilteredCurvesFilt[   ] : filtered difference in lateral distance                                         [-PI*RW_FCT_MAX    PI*RW_FCT_MAX]
  @glob_out        SITInternalLCProbDebugData.LatDiffFilteredCurvesProb[   ]                [0u    100u]
  @glob_out        SITInternalLCProbDebugData.LatDiffCamCurveProb[   ]                      [0u    100u]
  @glob_out        SITInternalLCProbDebugData.VelLatCamLaneMarkerProb[[   ]                 [0u    100u]
  @glob_out        SITInternalLCProbDebugData.TurnLightProb[   ]                            [0u    100u]
  @glob_out        SITInternalLCProbDebugData.DistLatProb[   ]                              [0u    100u]
  @glob_out        SITInternalLCProbDebugData.CamLaneMarkerCrossedProb[   ]                 [0u    100u]
  @glob_out        SITInternalLCProbDebugData.CurveProb[   ]                                [0u    100u]
  @glob_out        SITInternalLCProbDebugData.SITLCProbDataLocal
  @glob_out        SITInternalLCProbDebugData.SITLCProbInput
  @glob_out        SITLCProbDataGlobal.afLatDiffCamCurveFilt[  ]                            [full range float32 >=0]
  @glob_out        SILCProbDataLocal.iProbabilityLaneChangeLeft : lane change probability   [0s    100s]
  @glob_out        SILCProbDataLocal.iProbabilityLaneChangeRight : lane change probability  [0s    100s]
  @glob_out        pt_SITOutput->s_LCProbability : Reference to SIT Lane change probability  [-100 100]
  @glob_out        SITLCProbDataGlobal.CamLaneMarkerCrossedProbLeft : Left Camera lane marker crossed probability        [0u  100u]
  @glob_out        SITLCProbDataGlobal.CamLaneMarkerCrossedProbRight : Right Camera lane marker crossed probability      [0u  100u]

  @c_switch_part   FCT_CFG_CUSTOM_IO_INTERFACE         : Switch to enable selecting a different parameter set during the operation
  @c_switch_part   SIT_CFG_LC_USE_TURN_INDICATOR_INPUT : Configuration switch enabling use of turn indicator input
  @c_switch_part   FCT_SIMU                            : Configuration switch for enabling simulation profiling
  @c_switch_full   FCT_CFG_ACC_SITUATION               :  FCT support for ACC SIT (situation) sub-component
  @c_switch_full   SIT_CFG_LC_PROB_CALC                : Configuration switch enabling lane change probability calculation
  @c_switch_full   SIT_LC_CFG_USE_TURNIND_CAMERA_PROB : Configuration switch to enable lane change probability calculation using turn indicator input and camera lane input

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         12/9/2015

  @author          Marie-Theres Boll
*************************************************************************************************************************/
static void SIT_v_CalcLaneChangeProbability(const float32 fCycleTime)
{
  boolean bTurnLightLeft, bTurnLightRight;
  uint8 uiLCDirection; /*!< Info about which lane change direction is considered -> Initialization within a for loop */
  uint8 iLCProbTemp;
  float32 fTimeTurnLightPhase;
  float32 fLatDiffFilteredCurves, fLatDiffFilteredCurvesFilt, fLatDiffFilteredCurvesFiltLastCycle;
  float32 fLatDiffCamCurve, fLatDiffCamCurveFilt;
  float32 fABS_SILCProbInput_fDrvIntCurvePT1;
  float32 f_EgoSpeed;
  float32 f_Abs_DrvIntCurvePT1;

  /*! Input data for probability calculation (SILCProbInputOneSide -> initialzation in the for loop later in the code) */
  SITLCProbInputData_t SILCProbInput, SILCProbInputOneSide;
  /*! Lane Change probability values for the individual detectors for one side (left or right) -> initialzation in the for loop later in the code */
  SILCProbDetectors_t SILCProbDetectorsOneSide;
  /*! Local LC probability data */
  SITLCProbDataLocal_t SILCProbDataLocal;

  /*! Initialization of structures */
  SIT_v_InitLCProbInputData(&SILCProbInput);
  SIT_v_InitLCProbDataLocal(fCycleTime, &SILCProbDataLocal);

  /*! Set turn light state based on input data */
  bTurnLightLeft = FALSE;
  bTurnLightRight = FALSE;
#if (SIT_CFG_LC_USE_TURN_INDICATOR_INPUT)
  if (*pt_SITInput->t_RTE.pt_TurnIndicator == eTurnIndicator_Left)
  {
    bTurnLightLeft = TRUE;
  }
  if (*pt_SITInput->t_RTE.pt_TurnIndicator == eTurnIndicator_Right)
  {
    bTurnLightRight = TRUE;
  }
#endif

  /*! Determine lane change phase based on turn light information */
  SIT_v_LCProbSetTurnLightPhase( fCycleTime, LC_PROB_LEFT, bTurnLightLeft, &(SITLCProbDataGlobal.LCTurnLightEvalLeft) );
  SIT_v_LCProbSetTurnLightPhase( fCycleTime, LC_PROB_RIGHT, bTurnLightRight, &(SITLCProbDataGlobal.LCTurnLightEvalRight) );

  /*! Get camera lane information for lane change probability calculation */
  SIT_v_LCProbGetCamLaneInfo(&(SILCProbInput.CamLaneInfo));

  /*! Filtering of ego curve and driver intended curve */
  SIT_v_LCProbGetEgoMotionInfo(&SILCProbDataLocal, &(SILCProbInput.fEgoCurvePT1), &(SILCProbInput.fDrvIntCurvePT1));

  /* Definining local variables from reference pointer */
  f_EgoSpeed = *pt_SITInput->t_RTE.pf_EgoLongVel;

  /*! Calculation of "curve level": Should be zero on a straight road and non-zero in a curve */
  /*! Adapt curve level only if not close to standstill or if not turning 
      -> ego speed must be higher than a threshold, fDrvIntCurvePT1 must be lower than a threshold */
  fABS_SILCProbInput_fDrvIntCurvePT1 = fABS(SILCProbInput.fDrvIntCurvePT1);
  if ( (f_EgoSpeed > SIT_LC_PROB_MIN_EGOVELO_SWCURVE_EVAL) && (fABS_SILCProbInput_fDrvIntCurvePT1 < SIT_LC_PROB_MAX_CURVE_CURVE_LEVEL) )
  {
    /*! Filter the curve over time */
    /*! If curve lower than a threshold and velocity low, consider the curve as zeros */
    f_Abs_DrvIntCurvePT1 = fABS(SILCProbInput.fDrvIntCurvePT1);
    if ((f_Abs_DrvIntCurvePT1 > SIT_LC_PROB_MIN_CURVE_CURVE_LEVEL) || (f_EgoSpeed >= SIT_LC_PROB_LOW_SPEED_LEVEL))
    {
      SITLCProbDataGlobal.fCurveLevel = GDB_FILTER(SILCProbInput.fDrvIntCurvePT1, SITLCProbDataGlobal.fCurveLevel, SIT_LC_PROB_FILTER_CONST_CURVE_LEVEL);
    }
    else
    {
      SITLCProbDataGlobal.fCurveLevel = GDB_FILTER(0.f, SITLCProbDataGlobal.fCurveLevel, SIT_LC_PROB_FILTER_CONST_CURVE_LEVEL);
    }
  }
  else
  {
    /* Leave fCurveLevel unchanged (freeze) */
  }
  SILCProbInput.fCurveLevel = SITLCProbDataGlobal.fCurveLevel;

  /*! Calculation of distance driven in lateral direction after a LC-maneuver started */
  SIT_v_LCProbGetDrivenDistVeloLateralDuringLC(fCycleTime, SILCProbInput.fEgoCurvePT1, SILCProbInput.fDrvIntCurvePT1, &(SILCProbInput.fDistLat));

  /*! Firstly determine LC probability for lane change in left direction, secondly for lane change in right direction */
  for(uiLCDirection = (uint8) LC_PROB_LEFT; uiLCDirection <= (uint8) LC_PROB_RIGHT; uiLCDirection++)
  {
    /*! Initialization of structures which are filled for each iteration of loop */
    SIT_v_InitLCProbInputData(&SILCProbInputOneSide);
    SIT_v_InitLCProbDetectors(&SILCProbDetectorsOneSide);

    /*! Adapt signs of values based on LC side */
    if(uiLCDirection == (uint8) LC_PROB_LEFT)
    {
      SILCProbInputOneSide = SILCProbInput;
      fTimeTurnLightPhase = SITLCProbDataGlobal.LCTurnLightEvalLeft.fTimeAfterTLActivation;
      /* lane change probability based on blinker should become zero if blinker in the opposite direction was activated afterwards -> Level is set*/
      if(SITLCProbDataGlobal.LCTurnLightEvalLeft.fTimeAfterTLActivation > SITLCProbDataGlobal.LCTurnLightEvalRight.fTimeAfterTLActivation)
      {
        fTimeTurnLightPhase = SIT_LC_PROB_MAX_TIME_AFTER_TURN_LIGHT_ACTIVE;
      }
    }
    else
    {
      SILCProbInputOneSide.fEgoCurvePT1 = - SILCProbInput.fEgoCurvePT1;
      SILCProbInputOneSide.fDrvIntCurvePT1 = - SILCProbInput.fDrvIntCurvePT1;
      SILCProbInputOneSide.fDistLat = - SILCProbInput.fDistLat;
      SILCProbInputOneSide.fCurveLevel = - SILCProbInput.fCurveLevel;

      /* Camera relevant information (Remark: if no camera data available, CamLaneInfo has initial values)*/
      SILCProbInputOneSide.CamLaneInfo.bCamLaneVisible = SILCProbInput.CamLaneInfo.bCamLaneVisible;
      SILCProbInputOneSide.CamLaneInfo.bCamLaneChangeLeft = SILCProbInput.CamLaneInfo.bCamLaneChangeLeft;
      SILCProbInputOneSide.CamLaneInfo.bCamLaneChangeRight = SILCProbInput.CamLaneInfo.bCamLaneChangeRight;

      SILCProbInputOneSide.CamLaneInfo.fCameraCurvature = -SILCProbInput.CamLaneInfo.fCameraCurvature;
      SILCProbInputOneSide.CamLaneInfo.fLateralVelocityToCamLaneMarker = -SILCProbInput.CamLaneInfo.fLateralVelocityToCamLaneMarker;

      fTimeTurnLightPhase = SITLCProbDataGlobal.LCTurnLightEvalRight.fTimeAfterTLActivation;
      /* lane change probability based on blinker should become zero if blinker in the opposite direction was activated afterwards -> Level is set*/
      if(SITLCProbDataGlobal.LCTurnLightEvalRight.fTimeAfterTLActivation > SITLCProbDataGlobal.LCTurnLightEvalLeft.fTimeAfterTLActivation)
      {
        fTimeTurnLightPhase = SIT_LC_PROB_MAX_TIME_AFTER_TURN_LIGHT_ACTIVE;
      }
    }

    /*! LC probability: difference in lateral distance between filtered ego curve and filtered driver intended curve */
    /*! Difference in lateral distance between filtered ego curve and filtered driver intended curve in 1s 
        -> this difference is usually high before a lane change; 
        SIT_LC_PROB_DIFF_CURVE_FACTOR: Factor to increase the difference -> to reach 100 when LC */
    fLatDiffFilteredCurves = (-0.5f) * (SILCProbInputOneSide.fEgoCurvePT1 - SILCProbInputOneSide.fDrvIntCurvePT1) * f_EgoSpeed * f_EgoSpeed * SIT_LC_PROB_DIFF_CURVE_FACTOR;

    /*! Filter difference in lateral distance between filtered ego curve and filtered driver intended curve */
    fLatDiffFilteredCurvesFiltLastCycle = SITLCProbDataGlobal.afLatDiffFilteredCurvesFilt[uiLCDirection];
    fLatDiffFilteredCurvesFilt = GDB_FILTER(fLatDiffFilteredCurves, fLatDiffFilteredCurvesFiltLastCycle, SIT_LC_PROB_FILTER_CONST_DIFF_LAT_CURVE);
    SITLCProbDataGlobal.afLatDiffFilteredCurvesFilt[uiLCDirection] = fLatDiffFilteredCurvesFilt;

    /*! Get lane change probability based on lookup table: Interpolate or use border values */
    SILCProbDetectorsOneSide.iLatDiffFilteredCurvesProb = (uint8) ROUND_TO_INT(GDB_Math_CalculatePolygonValue(SIT_LC_PROB_POINTS_DIFF_LAT_FILT_CURVES_TABLE, 
      SITLCProbParData.SIT_LC_PROB_TABLE_DIFF_LAT_FILT_CURVES, fLatDiffFilteredCurvesFilt));

    /*! LC probability: difference in lateral distance between camera curve and filtered driver intended curve */
    if(SILCProbInputOneSide.CamLaneInfo.bCamLaneVisible == TRUE)
    {
      /*! Difference in lateral distance between camera curve and filtered driver intended curve in 1s 
        -> this difference is usually high before the camera lane markers are crossed */
      fLatDiffCamCurve = (-0.5f) * (SILCProbInputOneSide.CamLaneInfo.fCameraCurvature - SILCProbInputOneSide.fDrvIntCurvePT1) * f_EgoSpeed * f_EgoSpeed;
    }
    else
    {
      fLatDiffCamCurve = 0.f;
    }
    /*! Filter: difference in lateral distance between camera curve and filtered driver intended curve */
    fLatDiffCamCurveFilt = SITLCProbDataGlobal.afLatDiffCamCurveFilt[uiLCDirection];
    fLatDiffCamCurve = GDB_FILTER(fLatDiffCamCurve, fLatDiffCamCurveFilt, SIT_LC_PROB_FILTER_CONST_DIFF_LAT_CURVE);
    SITLCProbDataGlobal.afLatDiffCamCurveFilt[uiLCDirection] = fLatDiffCamCurve;

    /*! Get lane change probability based on lookup table: Interpolate or use border values */
    SILCProbDetectorsOneSide.iLatDiffCamCurveProb = (uint8) ROUND_TO_INT(GDB_Math_CalculatePolygonValue(SIT_LC_PROB_POINTS_DIFF_LAT_FILT_CURVES_TABLE, 
      SITLCProbParData.SIT_LC_PROB_TABLE_DIFF_LAT_FILT_CURVES, fLatDiffCamCurve));

    /*! LC probability: lateral velocity towards camera lane markers */
    /*! Get lane change probability based on lookup table: Interpolate or use border values */
    SILCProbDetectorsOneSide.iVelLatCamLaneMarkerProb = (uint8) ROUND_TO_INT(GDB_Math_CalculatePolygonValue(SIT_LC_PROB_POINTS_LAT_VEL_CAM_LANE_MARKER_TABLE, 
      SITLCProbParData.SIT_LC_PROB_TABLE_LAT_VEL_CAM_LANE_MARKER, SILCProbInputOneSide.CamLaneInfo.fLateralVelocityToCamLaneMarker));

    /*! LC probability: turn lights */
    /*! Get lane change probability based on lookup table: Interpolate or use border values */
    SILCProbDetectorsOneSide.iTurnLightProb = (uint8) ROUND_TO_INT(GDB_Math_CalculatePolygonValue(SIT_LC_PROB_POINTS_TURN_LIGHT_TABLE, 
      SITLCProbParData.SIT_LC_PROB_TABLE_TURN_LIGHT, fTimeTurnLightPhase));

    /*! LC probability: driven distance in lateral direction */
    /*! Get lane change probability based on lookup table: Interpolate or use border values */
    SILCProbDetectorsOneSide.iDistLatProb = (uint8) ROUND_TO_INT(GDB_Math_CalculatePolygonValue(SIT_LC_PROB_POINTS_LAT_DIST_TABLE, 
      SITLCProbParData.SIT_LC_PROB_TABLE_LAT_DIST, SILCProbInputOneSide.fDistLat));


    /* LC probability: camera lane crossed -> set LC probability to 100 if lane change is detected */
    SILCProbDetectorsOneSide.iCamLaneMarkerCrossedProb = 0u;
    if (uiLCDirection == (uint8) LC_PROB_LEFT)
    {
      if (SILCProbInputOneSide.CamLaneInfo.bCamLaneChangeLeft == TRUE)
      {
        SILCProbDetectorsOneSide.iCamLaneMarkerCrossedProb = 100u;
      }
#if (SIT_LC_CFG_USE_TURNIND_CAMERA_PROB)
      SITLCProbDataGlobal.CamLaneMarkerCrossedProbLeft = SILCProbDetectorsOneSide.iCamLaneMarkerCrossedProb;
#endif /*!< SIT_LC_CFG_USE_TURNIND_CAMERA_PROB */
    }
    else
    {
      if (SILCProbInputOneSide.CamLaneInfo.bCamLaneChangeRight == TRUE)
      {
        SILCProbDetectorsOneSide.iCamLaneMarkerCrossedProb = 100u;
      }
#if (SIT_LC_CFG_USE_TURNIND_CAMERA_PROB)
      SITLCProbDataGlobal.CamLaneMarkerCrossedProbRight = SILCProbDetectorsOneSide.iCamLaneMarkerCrossedProb;
#endif /*!< SIT_LC_CFG_USE_TURNIND_CAMERA_PROB */
    }

    /*! LC probability: Curve */
    /*! Get lane change probability based on lookup table: Interpolate or use border values */
    SILCProbDetectorsOneSide.iCurveProb = (uint8) ROUND_TO_INT(GDB_Math_CalculatePolygonValue(SIT_LC_PROB_POINTS_CURVE_TABLE, 
      SITLCProbParData.SIT_LC_PROB_TABLE_CURVE, (SILCProbInputOneSide.fDrvIntCurvePT1 - SILCProbInputOneSide.fCurveLevel)));

#ifdef FCT_SIMU
    /*! Store debug info */
    SITInternalLCProbDebugData.LatDiffFilteredCurvesProb[uiLCDirection] = SILCProbDetectorsOneSide.iLatDiffFilteredCurvesProb;
    SITInternalLCProbDebugData.LatDiffCamCurveProb[uiLCDirection] = SILCProbDetectorsOneSide.iLatDiffCamCurveProb;
    SITInternalLCProbDebugData.VelLatCamLaneMarkerProb[uiLCDirection] = SILCProbDetectorsOneSide.iVelLatCamLaneMarkerProb;
    SITInternalLCProbDebugData.TurnLightProb[uiLCDirection] = SILCProbDetectorsOneSide.iTurnLightProb;
    SITInternalLCProbDebugData.DistLatProb[uiLCDirection] = SILCProbDetectorsOneSide.iDistLatProb;
    SITInternalLCProbDebugData.CamLaneMarkerCrossedProb[uiLCDirection] = SILCProbDetectorsOneSide.iCamLaneMarkerCrossedProb;
    SITInternalLCProbDebugData.CurveProb[uiLCDirection] = SILCProbDetectorsOneSide.iCurveProb;
#endif

    /*! Combine lane change probabilities of the individual detectors (different parameters for "high speed" and "low speed") */
    if (f_EgoSpeed > SIT_LC_PROB_LOW_SPEED_LEVEL)
    {
      /*! If camera information is available */
      if (SILCProbInputOneSide.CamLaneInfo.bCamLaneVisible == TRUE)
      { 
        iLCProbTemp = CML_Bayes2(SILCProbDetectorsOneSide.iLatDiffCamCurveProb, SILCProbDetectorsOneSide.iVelLatCamLaneMarkerProb, 
          SITLCProbParData.SIT_LC_PROB_TABLE_COMB_CAM_PROB);                    /*!< Camera based probabilities */
        iLCProbTemp = CML_Bayes3(SILCProbDetectorsOneSide.iLatDiffFilteredCurvesProb, iLCProbTemp, SILCProbDetectorsOneSide.iTurnLightProb, 
          SITLCProbParData.SIT_LC_PROB_TABLE_COMB_ALL_LATDIFFCURVE_TURNLIGHT);  /*< iLatDiffFilteredCurvesProb, iLCProbTemp, iTurnLightProb */
      }
      else 
      {
        /*! If no camera information is available */
        iLCProbTemp = CML_Bayes2(SILCProbDetectorsOneSide.iLatDiffFilteredCurvesProb, SILCProbDetectorsOneSide.iTurnLightProb, 
          SITLCProbParData.SIT_LC_PROB_TABLE_COMB_LATDIFFCURVE_TURNLIGHT);      /*< iLatDiffFilteredCurvesProb, iTurnLightProb */
      }

      /*! If camera information is available */
      if (SILCProbInputOneSide.CamLaneInfo.bCamLaneVisible == TRUE)
      {
        iLCProbTemp = CML_Bayes2(iLCProbTemp, SILCProbDetectorsOneSide.iCamLaneMarkerCrossedProb, 
          SITLCProbParData.SIT_LC_PROB_TABLE_COMB_MARKERCROSSING);              /*!< iLCProbTemp and detected crossing of lane markers */
      }
    }
    else
    {
      /*! If camera information is available */
      if (SILCProbInputOneSide.CamLaneInfo.bCamLaneVisible == TRUE)
      {
        iLCProbTemp = CML_Bayes2(SILCProbDetectorsOneSide.iLatDiffCamCurveProb, SILCProbDetectorsOneSide.iVelLatCamLaneMarkerProb, 
          SITLCProbParData.SIT_LC_PROB_TABLE_COMB_CAM_PROB);              /*!< Camera based probabilities */
        iLCProbTemp = CML_Bayes2(iLCProbTemp, SILCProbDetectorsOneSide.iTurnLightProb, 
          SITLCProbParData.SIT_LC_PROB_TABLE_COMB_LOWSPEED_TURNLIGHT);    /*!< Turn light */
        iLCProbTemp = CML_Bayes3(iLCProbTemp, SILCProbDetectorsOneSide.iLatDiffFilteredCurvesProb, SILCProbDetectorsOneSide.iDistLatProb, 
          SITLCProbParData.SIT_LC_PROB_TABLE_COMB_LATDIST_LATDIFFCURVE);  /*!< iLatDiffFilteredCurvesProb and distance in lateral direction */
        iLCProbTemp = CML_Bayes2(iLCProbTemp, SILCProbDetectorsOneSide.iCurveProb, 
          SITLCProbParData.SIT_LC_PROB_TABLE_COMB_CURVE);                 /*!< Curvature */
        iLCProbTemp = CML_Bayes2(iLCProbTemp, SILCProbDetectorsOneSide.iCamLaneMarkerCrossedProb, 
          SITLCProbParData.SIT_LC_PROB_TABLE_COMB_MARKERCROSSING);        /*!< iLCProbTemp and detected crossing of lane markers */
      }
      else
      {
        /*! If no camera information is available */
        iLCProbTemp = CML_Bayes3(SILCProbDetectorsOneSide.iDistLatProb, SILCProbDetectorsOneSide.iLatDiffFilteredCurvesProb, SILCProbDetectorsOneSide.iTurnLightProb, 
          SITLCProbParData.SIT_LC_PROB_TABLE_COMB_LATDIST_TURNLIGHT_LATDIFFCURVE);  /*!< iDistLatProb, iLatDiffFilteredCurvesProb, iTurnLightProb */
        iLCProbTemp = CML_Bayes2(iLCProbTemp, SILCProbDetectorsOneSide.iCurveProb, 
          SITLCProbParData.SIT_LC_PROB_TABLE_COMB_CURVE);                           /*!< Curvature */
      }
    }

    /*! Store results */
    if(uiLCDirection == (uint8) LC_PROB_LEFT)
    {
      SILCProbDataLocal.iProbabilityLaneChangeLeft = (sint16) iLCProbTemp;
    }
    else
    {
      SILCProbDataLocal.iProbabilityLaneChangeRight = (sint16) iLCProbTemp;
    }
  } /*!< End: for(SILCDirection = LC_PROB_LEFT; SILCDirection <= LC_PROB_RIGHT; SILCDirection++) */
  
  /*! Get one lane change probability for left and right 
      -> Lane change LEFT: [0, 100]; lane change RIGHT: [-100, 0] */
  pt_SITOutput->s_LCProbLeft  = SILCProbDataLocal.iProbabilityLaneChangeLeft;
  pt_SITOutput->s_LCProbRight = SILCProbDataLocal.iProbabilityLaneChangeRight;
  pt_SITOutput->s_LCProb = SILCProbDataLocal.iProbabilityLaneChangeLeft - SILCProbDataLocal.iProbabilityLaneChangeRight;

  /*! Store result in history buffer */
  SITLCProbDataGlobal.iProbabilityBefore = pt_SITOutput->s_LCProb;

#ifdef FCT_SIMU
  /*! Store debug info */
  SITInternalLCProbDebugData.SITLCProbDataLocal = SILCProbDataLocal;
  SITInternalLCProbDebugData.SITLCProbInput = SILCProbInput;
#endif

}
#endif /*!< SIT_CFG_LC_PROB_CALC */

#if (SIT_CFG_LC_PROB_CALC == SWITCH_OFF)
/*************************************************************************************************************************
  Functionname:    SIT_v_SetLCProbability                                                                     */ /*!

  @brief           Set lane change probability

  @description     Set lane change probability. If information not available, give radar only lane change value

                   @startuml
                   partition  SIT_v_SetLCProbability {
                   start
                       if (Left side Lane change state correction is positive) then (yes)
                           :Set LC Probability to maximum positive threshold>
                       elseif (Right side Lane change state correction is positive) then (yes) 
                           :Set LC Probability to maximum negative threshold>
                       else
                           :Reset Lane change probability>
                       endif
                   Stop
                   }
                   @enduml

  @return          -

  @param[in]       -

  @glob_in         SALaneChangeInst.LeftSide.uiCorrection         [0   iFSW_KANF]
  @glob_in         SALaneChangeInst.RightSide.uiCorrection        [0   iFSW_KANF]
  @glob_out        s_LCProbability : SIT Lane change probability  [-100 100]

  @c_switch_part   SI_CFG_LC_PROB_CALC       : Configuration switch enabling lane change probability calculation
  @c_switch_full   FCT_CFG_ACC_SITUATION     : FCT support for ACC SIT (situation) sub-component
  @c_switch_full   SIT_CFG_LC_PROB_CALC      : Configuration switch enabling lane change probability calculation

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         1/12/2016

  @author          Marie-Theres Boll
*************************************************************************************************************************/

static void SIT_v_SetLCProbability(void)
{
  /*! Lane change probability calculation disabled: Use radar only lane change information */
  if (SALaneChangeInst.LeftSide.uiCorrection > 0u)
  {
    s_LCProb = 100;
  }
  else if (SALaneChangeInst.RightSide.uiCorrection > 0u)
  {
    s_LCProb = -100;
  }
  else
  {
    s_LCProb = 0;
  }
}
#endif

#if (FCT_CFG_FIP_LANE_MATRIX_FUSION && SLATE_CFG_CAM_LANE_INTERFACE)

/*************************************************************************************************************************
  Functionname:    SIT_v_InitGlobalCameraLaneCrossingData                                                            */ /*!

  @brief           Initialize the global data used for the camera lane crossing detection

  @description     Initialize the global data used for the camera lane crossing detection

                   @startuml
                   partition SIT_v_InitGlobalCameraLaneCrossingData {
                   start
                       :Initialize the global data used for Camera lane crossing detection
                       1.Camera Lane crossing state
                       2.History buffer for Left Lane marker data
                       3.History buffer for Right Lane marker data;
                   Stop
                   }
                   @enduml

  @return          -

  @param[in]       - 

  @glob_in         -
  @glob_out        pt_SITOutput->t_CamLaneMarkerCrossed : Camera lane marker crossing state                                                         [type SITLCStateCamLaneMarkerCrossed_t defined in si_ext.h]
  @glob_out        t_SITCamLaneCrossedData.LeftLaneMarkerLastCycle.b_CrossingLeft : Info if camera lane is crossed driving to the left direction    [TRUE, FALSE]
  @glob_out        t_SITCamLaneCrossedData.LeftLaneMarkerLastCycle.b_CrossingRight : Info if camera lane is crossed driving to the right direction  [TRUE, FALSE]
  @glob_out        t_SITCamLaneCrossedData.LeftLaneMarkerLastCycle.f_Dist : Distance to camera lane marker                                          [-PI/2*RW_FCT_MAX   PI/2*RW_FCT_MAX]
  @glob_out        t_SITCamLaneCrossedData.LeftLaneMarkerLastCycle.LaneMarkerPoE : State to the camera lane marker                                  [full range of uint32]
  @glob_out        t_SITCamLaneCrossedData.RightLaneMarkerLastCycle.b_CrossingLeft : Info if camera lane is crossed driving to the left direction   [TRUE, FALSE]
  @glob_out        t_SITCamLaneCrossedData.RightLaneMarkerLastCycle.b_CrossingRight : Info if camera lane is crossed driving to the right direction [TRUE, FALSE]
  @glob_out        t_SITCamLaneCrossedData.RightLaneMarkerLastCycle.f_Dist : Distance to camera lane marker                                         [-PI/2*RW_FCT_MAX   PI/2*RW_FCT_MAX]
  @glob_out        t_SITCamLaneCrossedData.RightLaneMarkerLastCycle.LaneMarkerPoE : State to the camera lane marker                                 [full range of uint32]

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_SITUATION   :  FCT support for ACC SIT (situation) sub-component
  @c_switch_full   FCT_CFG_FIP_LANE_MATRIX_FUSION : Config switch for fusion of different input sources for FIP Lane Matrix
  @c_swtich_full   SLATE_CFG_CAM_LANE_INTERFACE : Configuration switch enabling camera lane input data to FCT_SEN

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         1/13/2016

  @author          Marie-Theres Boll
*************************************************************************************************************************/
static void SIT_v_InitGlobalCameraLaneCrossingData(void)
{
  /*! Camera lane crossing state */
  pt_SITOutput->t_CamLaneMarkerCrossed = UNKNOWN_CROSS_CAMLANE;
  /*! History data for left side */
  t_SITCamLaneCrossedData.LeftLaneMarkerLastCycle.b_CrossingLeft = FALSE;
  t_SITCamLaneCrossedData.LeftLaneMarkerLastCycle.b_CrossingRight = FALSE;
  t_SITCamLaneCrossedData.LeftLaneMarkerLastCycle.f_Dist = 0.f;
  t_SITCamLaneCrossedData.LeftLaneMarkerLastCycle.LaneMarkerPoE = 0u;
  /*! History data for right side */
  t_SITCamLaneCrossedData.RightLaneMarkerLastCycle.b_CrossingLeft = FALSE;
  t_SITCamLaneCrossedData.RightLaneMarkerLastCycle.b_CrossingRight = FALSE;
  t_SITCamLaneCrossedData.RightLaneMarkerLastCycle.f_Dist = 0.f;
  t_SITCamLaneCrossedData.RightLaneMarkerLastCycle.LaneMarkerPoE = 0u;
}
#endif


#if (FCT_CFG_FIP_LANE_MATRIX_FUSION && SLATE_CFG_CAM_LANE_INTERFACE)

/*************************************************************************************************************************
  Functionname:    SIT_b_GetValidCamLane                                                                             */ /*!

  @brief           Determine if the camera lane marker is valid

  @description     Determine if the camera lane marker is valid

                   @startuml
                   partition SIT_b_GetValidCamLane {
                   start
                   	If (Camera lane marker POE is above threshold for Previous and Current cycle and Signal state is AL_SIG_STATE_OK) then (yes)
                   		:Camera lane marker is valid>
                   	Endif
                   Stop
                   }
                   @enduml

  @return          b_LaneMarkerValid: Info if camera lane marker is valid                                                [TRUE, FALSE]

  @param[in]       u_LaneMarkerPoELastCycle    : Existance probability of the camera lane marker of the last cycle       [0u   100u]
  @param[in]       u_LaneMarkerPoECurrentCycle : Existance probability of the camera lane marker of the current cycle    [0u   100u]

  @glob_in         pt_SITInput->t_RTE.pt_CamLaneData->sSigHeader.eSigStatus                                              [AlgoSignalState_t defined in Rte_Type.h]
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_SITUATION   :  FCT support for ACC SIT (situation) sub-component
  @c_switch_full   FCT_CFG_FIP_LANE_MATRIX_FUSION : Config switch for fusion of different input sources for FIP Lane Matrix
  @c_swtich_full   SLATE_CFG_CAM_LANE_INTERFACE : Configuration switch enabling camera lane input data to FCT_SEN


  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         1/13/2016

  @author          Marie-Theres Boll
*************************************************************************************************************************/
static boolean SIT_b_GetValidCamLane(uint32 u_LaneMarkerPoELastCycle, uint32 u_LaneMarkerPoECurrentCycle)
{
  boolean b_LaneMarkerValid;

  /*! Set default: Camera lane marker is invalid */
  b_LaneMarkerValid = FALSE;

  /*! Consider the camera lane marker state as valid if the state is valid for the last and the current cycle */
  if( (u_LaneMarkerPoELastCycle >= FIP_CAM_LANE_POE_LEVEL) && (u_LaneMarkerPoECurrentCycle >= FIP_CAM_LANE_POE_LEVEL) && (pt_SITInput->t_RTE.pt_CamLaneData->sSigHeader.eSigStatus == AL_SIG_STATE_OK))
  {
    b_LaneMarkerValid = TRUE;
  }

  return b_LaneMarkerValid;
}
#endif

#if (FCT_CFG_FIP_LANE_MATRIX_FUSION && SLATE_CFG_CAM_LANE_INTERFACE)

/*************************************************************************************************************************
  Functionname:    SIT_v_DetectCamLaneCrossing                                                                       */ /*!

  @brief           Determine if the camera lane markers are crossed

  @description     Determine if the camera lane markers are crossed into the left/right direction. 
                   It is distinguished if the camera lane markers are crossed into the left/right direction 
                   based on the analysis of the left and/or right camera lane markers

                   @startuml
                   partition SIT_v_DetectCamLaneCrossing {
                   start
                   If ( Camera lane marker on the left is valid) then (yes)
                       IF ( Difference in distance of Ego to Camera lane marker between last cycle and current cycle is above SIT_LC_MIN_DIFF_DIST_CAM_LANE_MARKER
                    and \n
                   Distance to Camera lane marker in last cycle is within an interval  SIT_LC_MIN_DIFF_DIST_CAM_LANE_MARKER) then (yes)
                           : Ego vehicle is crossing the left lane marker in to left direction>
                       Elseif(Difference in distance to Camera lane markers between current and last cycle is lower than a threshold and \n
                   Distance to left camera lane in current cycle is lower than SIT_LC_MIN_MAX_INTERVAL_DIST_CAM_LANE_MARKER) then (yes)		
                           :Ego vehicle is crossing the left lane marker into right direction>
                       Endif
                   Endif
                   If ( Camera lane marker on the right  is valid) then (yes)
                       IF ( Difference in distance of Ego to Right Camera lane marker between last cycle and current cycle is above SIT_LC_MIN_DIFF_DIST_CAM_LANE_MARKER
                    and \n
                   Distance to right Camera lane marker in last cycle is within an interval        SIT_LC_MIN_MAX_INTERVAL_DIST_CAM_LANE_MARKER) then (yes)
                           : Ego vehicle is crossing the right  lane marker in to left direction>
                       Elseif(Difference in distance to Right Camera lane markers between current and last cycle is lower than a threshold SIT_LC_MIN_DIFF_DIST_CAM_LANE_MARKER
                    and \n
                   Distance to right  camera lane in current cycle is lower than SIT_LC_MIN_MAX_INTERVAL_DIST_CAM_LANE_MARKER) then (yes)		
                           :Ego vehicle is crossing the right lane marker into right direction>
                       Endif
                   Endif
                   Stop
                   }
                   @enduml

  @return          -

  @param[out]      pb_LCLeftMarkerLeft : Ego vehicle crossing the left lane marker into to left direction     [TRUE,FALSE]
  @param[out]      pb_LCLeftMarkerRight : Ego vehicle crossing the right lane marker into to left direction   [TRUE,FALSE]
  @param[out]      pb_LCRightMarkerLeft : Ego vehicle crossing the left lane marker into to right direction   [TRUE,FALSE]
  @param[out]      pb_LCRightMarkerRight : Ego vehicle crossing the right lane marker into to right direction [TRUE,FALSE]
  @param[in]       b_LaneMarkerLeftValid : Info if left lane markers are valid                                [TRUE,FALSE]
  @param[in]       b_LaneMarkerRightValid : Info if right lane markers are valid                              [TRUE,FALSE]
  @param[in]       p_LeftLaneMarkerLastCycle : History data for the left/right lane markers; pointer to SITLCCamLaneMarkerHistData_t defined in sit_lanechange_cam.c
                      f_Dist                                                                                  [-PI/2*RW_FCT_MAX   PI/2*RW_FCT_MAX]
  @param[in]       p_RightLaneMarkerLastCycle : History data for the left/right lane markers; pointer to SITLCCamLaneMarkerHistData_t defined in sit_lanechange_cam.c
                      f_Dist                                                                                  [-PI/2*RW_FCT_MAX   PI/2*RW_FCT_MAX]

  @glob_in         pt_SITInput->t_RTE.pt_CamLaneData->LaneMarkerInfo[   ].f_MarkerDist                        [-100f   100f]

  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_SITUATION          :  FCT support for ACC SIT (situation) sub-component
  @c_switch_full   FCT_CFG_FIP_LANE_MATRIX_FUSION : Config switch for fusion of different input sources for FIP Lane Matrix
  @c_swtich_full   SLATE_CFG_CAM_LANE_INTERFACE : Configuration switch enabling camera lane input data to FCT_SEN

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         1/13/2016

  @author          Marie-Theres Boll
*************************************************************************************************************************/
static void SIT_v_DetectCamLaneCrossing(boolean * pb_LCLeftMarkerLeft, boolean * pb_LCLeftMarkerRight, 
                                       boolean * pb_LCRightMarkerLeft, boolean * pb_LCRightMarkerRight, 
                                       const boolean b_LaneMarkerLeftValid, const boolean b_LaneMarkerRightValid,
                                       const SITLCCamLaneMarkerHistData_t * p_LeftLaneMarkerLastCycle, 
                                       const SITLCCamLaneMarkerHistData_t * p_RightLaneMarkerLastCycle)
{
  float32 fABS_Dist_Left, fABS_Dist_Right, fABS_MarkerDist_Left, fABS_MarkerDist_Right;		/* For calculating ABS value */

  /*! Initialize output values */
  (*pb_LCLeftMarkerLeft) = FALSE;   /*!< Ego vehicle crossing the left lane marker into to left direction */
  (*pb_LCRightMarkerLeft) = FALSE;  /*!< Ego vehicle crossing the left lane marker into to right direction */
  (*pb_LCLeftMarkerRight) = FALSE;  /*!< Ego vehicle crossing the right lane marker into to left direction */
  (*pb_LCRightMarkerRight) = FALSE; /*!< Ego vehicle crossing the right lane marker into to right direction */

  /*! Detect the crossing of left camera lane marker */
  if(b_LaneMarkerLeftValid == TRUE) 
  {
	fABS_Dist_Left = fABS(p_LeftLaneMarkerLastCycle->f_Dist);
	fABS_MarkerDist_Left = fABS(pt_SITInput->t_RTE.pt_CamLaneData->LaneMarkerInfo[FIP_CL_MK_LEFT].f_MarkerDist);
	
    /*! Consider it a crossing into the left direction, if the difference in the distance to the camera lane markers between the current and 
    the last cycle is higher than a threshold;
    and if the distance to the left camera lane marker was within an interval for the last cycle */
    if( ((pt_SITInput->t_RTE.pt_CamLaneData->LaneMarkerInfo[FIP_CL_MK_LEFT].f_MarkerDist - p_LeftLaneMarkerLastCycle->f_Dist) > SIT_LC_MIN_DIFF_DIST_CAM_LANE_MARKER ) &&
        (fABS_Dist_Left < SIT_LC_MIN_MAX_INTERVAL_DIST_CAM_LANE_MARKER)
      )
    {
      (*pb_LCLeftMarkerLeft) = TRUE;
    }
    else if ( ((pt_SITInput->t_RTE.pt_CamLaneData->LaneMarkerInfo[FIP_CL_MK_LEFT].f_MarkerDist - p_LeftLaneMarkerLastCycle->f_Dist) < -SIT_LC_MIN_DIFF_DIST_CAM_LANE_MARKER ) &&
              ( fABS_MarkerDist_Left < SIT_LC_MIN_MAX_INTERVAL_DIST_CAM_LANE_MARKER)
            )
    {
      /*! Consider it a crossing into the right direction, if the difference in the distance to the camera lane markers between the current and 
      the last cycle is lower than a threshold;
      and if the distance to the left camera lane marker is within an interval for the current cycle */
      (*pb_LCRightMarkerLeft) = TRUE;
    }
    else
    {
      /*! Nothing */
    }
  }

  /*! Detect the crossing of right camera lane marker */
  if(b_LaneMarkerRightValid == TRUE)
  {
	fABS_Dist_Right = fABS(p_RightLaneMarkerLastCycle->f_Dist);
	fABS_MarkerDist_Right = fABS(pt_SITInput->t_RTE.pt_CamLaneData->LaneMarkerInfo[FIP_CL_MK_RIGHT].f_MarkerDist);
	
    /*! Consider it a crossing into the left direction, if the difference in the distance to the camera lane markers between the current and 
    the last cycle is higher than a threshold;
    and if the distance to the right camera lane marker was within an interval for the last cycle */
    if( ((pt_SITInput->t_RTE.pt_CamLaneData->LaneMarkerInfo[FIP_CL_MK_RIGHT].f_MarkerDist - p_RightLaneMarkerLastCycle->f_Dist) > SIT_LC_MIN_DIFF_DIST_CAM_LANE_MARKER ) &&
        (fABS_MarkerDist_Right < SIT_LC_MIN_MAX_INTERVAL_DIST_CAM_LANE_MARKER)
      )
    {
      (*pb_LCLeftMarkerRight) = TRUE;
    }
    else if( ((pt_SITInput->t_RTE.pt_CamLaneData->LaneMarkerInfo[FIP_CL_MK_RIGHT].f_MarkerDist - p_RightLaneMarkerLastCycle->f_Dist) < -SIT_LC_MIN_DIFF_DIST_CAM_LANE_MARKER ) &&
             (fABS_Dist_Right < SIT_LC_MIN_MAX_INTERVAL_DIST_CAM_LANE_MARKER)
      )
    {
      /*! Consider it a crossing into the right direction, if the difference in the distance to the camera lane markers between the current and 
      the last cycle is lower than a threshold;
      and if the distance to the right camera lane marker is within an interval for the current cycle */
      (*pb_LCRightMarkerRight) = TRUE;
    }
    else
    {
      /*! Nothing */
    }
  }
}
#endif

#if (FCT_CFG_FIP_LANE_MATRIX_FUSION && SLATE_CFG_CAM_LANE_INTERFACE)

/*************************************************************************************************************************
  Functionname:    SIT_v_StateCamLaneCrossing                                                                        */ /*!

  @brief           Determine the camera lane crossing state

  @description     Determine the camera lane crossing state. It is distinguished if the camera lane markers are crossed into the left/right direction 
                   based on the analysis of the left and/or right camera lane markers.

                   @startuml
                   partition SIT_v_StateCamLaneCrossing {
                   start
                   :Get the Left Camera lane validity
                   <b>SIT_b_GetValidCamLane</b>;
                   :Get the right Camera lane validity
                   <b>SIT_b_GetValidCamLane</b>;
                   : Determine if the camera lane markers are crossed into the left/right 
                   direction based on the analysis of the left and/or right camera lane markers
                   <b>SIT_v_DetectCamLaneCrossing</b>;
                   If (Left lane marker and right lane marker are both valid) then (yes)
                       If (Ego is crossing the left lane marker into left direction in current cycle OR
                   Ego crossed the left lane marker into left direction in previous cycle) then (yes)
                           :Left marker crossing in left direction>
                       endif
                       If (Ego is crossing the left lane marker into right direction in current cycle OR
                   Ego crossed the left lane marker into right direction in previous cycle) then (yes)
                           :Left marker crossing in right direction>
                       endif
                       If (Ego is crossing the right lane marker into left direction in current cycle OR
                   Ego crossed the left lane marker into left direction in previous cycle) then (yes)
                           :Right marker crossing in left direction>
                       endif
                       If (Ego is crossing the right lane marker into left direction in current cycle OR
                   Ego crossed the left lane marker into right direction in previous cycle) then (yes)
                           :Right marker crossing in right direction>
                       Endif
                   If (Left and right camera lane markers indicate a crossing in left direction) then (yes)
                   :Set Cameral Lane crossing state to LEFT_TWO_LANE_CONF_CROSS_CAMLANE>
                       endif
                   If (Left and right camera lane markers indicate a crossing in right direction) then (yes)
                   :Set Cameral Lane crossing state to RIGHT_TWO_LANE_CONF_CROSS_CAMLANE>
                       endif
                   elseif(Only left lane marker is valid and left camera lane marker indicates crossing to left direction) then (yes)
                       :Set Camera Lane crossing state to LEFT_ONE_LANE_CONF_CROSS_CAMLANE>
                   elseif(Only right lane marker is valid and left camera lane marker indicates crossing to right direction) then (yes)
                       :Set Camera Lane crossing state to RIGHT_ONE_LANE_CONF_CROSS_CAMLANE>
                   Endif
                   :Save the global data for next cycle;
                   Stop
                   }
                   @enduml

  @return          -

  @param[in,out]   p_StateCamLaneMarkerCrossed : State indicating the camera lane marker crossing [type SITLCStateCamLaneMarkerCrossed_t defined in sit_ext.h]
  @param[in,out]   p_LeftLaneMarkerLastCycle : History data for the left lane markers pointer to SITLCCamLaneMarkerHistData_t defined in sit_lanechange_cam.c
                      p_LeftLaneMarkerLastCycle->LaneMarkerPoE   [full range uint32]
                      p_LeftLaneMarkerLastCycle->b_CrossingLeft  [TRUE, FALSE]
                      p_LeftLaneMarkerLastCycle->b_CrossingRight [TRUE, FALSE]
                      p_LeftLaneMarkerLastCycle->f_Dist          [-PI/2*RW_FCT_MAX   PI/2*RW_FCT_MAX]

  @param[in,out]   p_RightLaneMarkerLastCycle : History data for the right lane markers pointer to SITLCCamLaneMarkerHistData_t defined in sit_lanechange_cam.c
                      p_RightLaneMarkerLastCycle->LaneMarkerPoE   [full range uint32]
                      p_RightLaneMarkerLastCycle->b_CrossingLeft  [TRUE, FALSE]
                      p_RightLaneMarkerLastCycle->b_CrossingRight [TRUE, FALSE]
                      p_RightLaneMarkerLastCycle->f_Dist          [-PI/2*RW_FCT_MAX   PI/2*RW_FCT_MAX]

  @glob_in         pt_SITInput->t_RTE.pt_CamLaneData->LaneMarkerInfo[   ].u_ExistanceProbability    [0u   100u]
  @glob_in         pt_SITInput->t_RTE.pt_CamLaneData->LaneMarkerInfo[   ].f_MarkerDist              [-100f   100f]
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_SITUATION   :  FCT support for ACC SIT (situation) sub-component
  @c_switch_full   FCT_CFG_FIP_LANE_MATRIX_FUSION : Config switch for fusion of different input sources for FIP Lane Matrix
  @c_swtich_full   SLATE_CFG_CAM_LANE_INTERFACE : Configuration switch enabling camera lane input data to FCT_SEN


  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         1/14/2016

  @author          Marie-Theres Boll
*************************************************************************************************************************/
static void SIT_v_StateCamLaneCrossing(SITLCStateCamLaneMarkerCrossed_t * p_StateCamLaneMarkerCrossed, 
                                      SITLCCamLaneMarkerHistData_t * p_LeftLaneMarkerLastCycle, SITLCCamLaneMarkerHistData_t * p_RightLaneMarkerLastCycle)
{
  boolean b_LaneMarkerLeftValid, b_LaneMarkerRightValid;
  boolean b_LCLeftMarkerLeft, b_LCLeftMarkerRight, b_LCRightMarkerLeft, b_LCRightMarkerRight;
  boolean b_LCLeftMarkerLeftAll, b_LCRightMarkerLeftAll, b_LCLeftMarkerRightAll, b_LCRightMarkerRightAll;

  /*! Determine if the left camera lane marker is valid */
  b_LaneMarkerLeftValid = SIT_b_GetValidCamLane(p_LeftLaneMarkerLastCycle->LaneMarkerPoE, 
    (uint32)pt_SITInput->t_RTE.pt_CamLaneData->LaneMarkerInfo[FIP_CL_MK_LEFT].u_ExistanceProbability);

  /*! Determine if the right camera lane marker is valid */
  b_LaneMarkerRightValid = SIT_b_GetValidCamLane(p_RightLaneMarkerLastCycle->LaneMarkerPoE, 
    (uint32)pt_SITInput->t_RTE.pt_CamLaneData->LaneMarkerInfo[FIP_CL_MK_RIGHT].u_ExistanceProbability);

  /*! Determine if the camera lane markers are crossed into the left/right direction based on the analysis of the left and/or right camera lane markers */
  SIT_v_DetectCamLaneCrossing(&b_LCLeftMarkerLeft, &b_LCLeftMarkerRight, &b_LCRightMarkerLeft, &b_LCRightMarkerRight, 
    b_LaneMarkerLeftValid, b_LaneMarkerRightValid, p_LeftLaneMarkerLastCycle, p_RightLaneMarkerLastCycle);

  /*! Set camera lane marker crossing state */
  /*! Default: UNKNOWN_CROSS_CAMLANE */
  (*p_StateCamLaneMarkerCrossed) = UNKNOWN_CROSS_CAMLANE;

  if( (b_LaneMarkerLeftValid == TRUE) && (b_LaneMarkerRightValid == TRUE) )
  {
    /*! If the left and right camera lane markers are valid, both markers have to indicate the crossing */

    /*! Combine information of detected camera lane crossing from the last cycle and the current cycle */
    /*! Default values */
    b_LCLeftMarkerLeftAll = FALSE;
    b_LCRightMarkerLeftAll = FALSE;
    b_LCLeftMarkerRightAll = FALSE;
    b_LCRightMarkerRightAll =  FALSE;
    if( (b_LCLeftMarkerLeft == TRUE) || (p_LeftLaneMarkerLastCycle->b_CrossingLeft == TRUE) )
    {
      b_LCLeftMarkerLeftAll = TRUE;
    }
    if ( (b_LCRightMarkerLeft == TRUE) || (p_LeftLaneMarkerLastCycle->b_CrossingRight == TRUE) )
    {
      b_LCRightMarkerLeftAll = TRUE;
    }
    if( (b_LCLeftMarkerRight == TRUE) || (p_RightLaneMarkerLastCycle->b_CrossingLeft == TRUE) )
    {
      b_LCLeftMarkerRightAll = TRUE;
    }
    if( (b_LCRightMarkerRight == TRUE) || (p_RightLaneMarkerLastCycle->b_CrossingRight == TRUE) )
    {
      b_LCRightMarkerRightAll = TRUE;
    }

    /*! The left and right camera lane markers indicate a crossing in the left direction */
    if( (b_LCLeftMarkerLeftAll == TRUE) && (b_LCLeftMarkerRightAll == TRUE) )
    {
      (*p_StateCamLaneMarkerCrossed) = LEFT_TWO_LANE_CONF_CROSS_CAMLANE;
    }
    else if ((b_LCRightMarkerLeftAll == TRUE) && (b_LCRightMarkerRightAll == TRUE))
    {
      /*! The left and right camera lane markers indicate a crossing in the right direction */
      (*p_StateCamLaneMarkerCrossed) = RIGHT_TWO_LANE_CONF_CROSS_CAMLANE;
    }
    else
    {
      /*! Nothing */
    }
  }
  else if ( (b_LaneMarkerLeftValid == TRUE) && (b_LCLeftMarkerLeft == TRUE) )
  {
    /*! Only the left camera lane marker is valid and the left camera lane marker indicates the crossing into the left direction */
    (*p_StateCamLaneMarkerCrossed) = LEFT_ONE_LANE_CONF_CROSS_CAMLANE;
  }
  else if ( (b_LaneMarkerRightValid == TRUE) && (b_LCRightMarkerRight == TRUE) )
  {
    /*! Only the right camera lane marker is valid and the right camera lane marker indicates the crossing into the right direction */
    (*p_StateCamLaneMarkerCrossed) = RIGHT_ONE_LANE_CONF_CROSS_CAMLANE;
  }
  else
  {
    /*! Nothing */
  }

  /*! Update the global data with the information from this cycle */
  p_LeftLaneMarkerLastCycle->b_CrossingLeft = b_LCLeftMarkerLeft;
  p_LeftLaneMarkerLastCycle->b_CrossingRight = b_LCRightMarkerLeft;
  p_LeftLaneMarkerLastCycle->f_Dist = pt_SITInput->t_RTE.pt_CamLaneData->LaneMarkerInfo[FIP_CL_MK_LEFT].f_MarkerDist;
  p_LeftLaneMarkerLastCycle->LaneMarkerPoE = pt_SITInput->t_RTE.pt_CamLaneData->LaneMarkerInfo[FIP_CL_MK_LEFT].u_ExistanceProbability;
  p_RightLaneMarkerLastCycle->b_CrossingLeft = b_LCLeftMarkerRight;
  p_RightLaneMarkerLastCycle->b_CrossingRight = b_LCRightMarkerRight;
  p_RightLaneMarkerLastCycle->f_Dist = pt_SITInput->t_RTE.pt_CamLaneData->LaneMarkerInfo[FIP_CL_MK_RIGHT].f_MarkerDist;
  p_RightLaneMarkerLastCycle->LaneMarkerPoE = pt_SITInput->t_RTE.pt_CamLaneData->LaneMarkerInfo[FIP_CL_MK_RIGHT].u_ExistanceProbability;
}
#endif

#if (FCT_CFG_FIP_LANE_MATRIX_FUSION && SLATE_CFG_CAM_LANE_INTERFACE)

/*************************************************************************************************************************
  Functionname:    SIT_v_SetLaneChangeMovePre                                                                        */ /*!

  @brief           State if ego vehicle moves towards the new lane during the ego lane change, 
                    i.e. before entering the new lane

  @description     State if ego vehicle moves towards the new lane during the ego lane change, 
                    i.e. before entering the new lane.
                    This information is based on camera lane information and the ego lane change probability.
                    The distance to the camera lane marker has to reduce constantly over several cycles and 
                    ego dynamic has to signalize a lane change for setting the state 
                    LANE_CHANGE_CAM_PRE_MOVE_LEFT or LANE_CHANGE_CAM_PRE_MOVE_RIGHT. 
                    The state LANE_CHANGE_CAM_PRE_MOVE_NO is the default value.

                   @startuml
                   partition  SIT_v_SetLaneChangeMovePre {
                   start
                       :Fill the Camera lane history buffer with Distance to lane marker on the left side
                       Fill the Camera lane history buffer with Distance to lane marker on the right  side;
                       If (Camera lane visibility is greater than minimum value and Left camera lane existence probability is greater than threshold) then (yes)
                           :Copy the current cycle Distance to camera lane marker left to history buffer>
                       Else(no)
                           :Reset the left History buffer to default value>
                       endif
                       If (Camera lane visibility is greater than minimum value and right camera lane existence probability is greater than threshold) then (yes)
                           :Copy the current cycle Distance to camera lane marker right to history buffer>
                       Else(no)
                           :Reset the right History buffer to default value;
                       endif
                       Repeat
                           If (If lane marker distance entries in Left history buffer are increasing consecutively in each cycle) then (yes)
                               :Ego is not driving towards left camera lane>
                           Else
                               :Driven distance to the left camera lane is accumulated difference of previous cycle and current cycle distance to the left lane marker>
                           endif
                           Note right
                               Left Driven distance is the sum of (Previous - Current cycle Left Lane marker distance) from each cycle
                           End note
                           If (If lane marker distance entries in Right history buffer are increasing(negatively) consecutively  in each cycle) then (yes)
                               :Ego is not driving towards right camera lane>
                           Else
                               :Driven distance to the right camera lane is accumulated difference of previous cycle and current cycle distance to the right lane marker>
                           endif
                           Note right
                               Right Driven distance is the sum of (Previous - Current cycle Right Lane marker distance) from each cycle
                           End note
                       Repeat while (History buffer of size SIT_LC_CAM_LANE_MARKER_HISTORY_BUFFER)
                       If( Ego driving towards left camera lane and left driven distance is not sufficient or too high) then (yes)
                           :Reset the Ego driving towards left camera lane to FALSE>
                       endif
                       If( Ego driving towards right camera lane and right driven distance is not sufficient or too high) then (yes)
                           :Reset the Ego driving towards right camera lane to FALSE>
                       Endif
                       If(Ego driving towards left and right camera are both true) then (yes)
                           : Indicates that the results are implausible hence reset both>
                       Endif
                       If (Lane marker information is valid, valid lane markers, visibility distance higher than threshold, valid camera lane width) then (yes)
                           If (Lane marker distance to left camera lane is smaller than lane marker distance to right camera lane and Hysteresis of ego driving towards left lane marker is true and Lane change state is LC_LEFT and (LC_Prob is higher than threshold or Distance to camera lane marker left is smaller than threshold)) then (yes)
                               : Ego is in PRE move state towards left>
                           Endif
                           If (Lane marker distance to right camera lane is smaller than lane marker distance to left camera lane and Hysteresis of ego driving towards right lane marker is true and Lane change state is LC_RIGHT and (LC_Prob is higher than threshold or Distance to camera lane marker right is higher than negative threshold)) then (yes)
                               : Ego is in PRE move state towards right>
                           Endif
                   Endif
                   Stop
                   }
                   @enduml

  @return          -

  @param[in,out]   p_SILaneChangeCamPreMoveState : State if ego vehicle moves towards the 
                      new lane during the ego lane change, i.e. before entering the new lane. 
                      [SITLaneChangeCamPreMove_t as in sit_ext.h]

  @glob_in         pt_SITInput->t_RTE.pt_CamLaneData->LaneMarkerInfo[   ].f_MarkerDist            [-100.f ...100.f]
  @glob_in         pt_SITInput->t_RTE.pt_CamLaneData->LaneMarkerInfo[   ].u_ExistanceProbability  [0u ...100u]
  @glob_in         SITLCCamMovePreGlobalData.af_LeftCamMarkerDistHistory[   ]                     [-100.f ...100.f]
  @glob_in         SITLCCamMovePreGlobalData.af_RightCamMarkerDistHistory[   ]                    [-100.f ...100.f]
  @glob_out        SITLCCamMovePreGlobalData.af_LeftCamMarkerDistHistory[   ]                     [-100.f ...100.f]
  @glob_out        SITLCCamMovePreGlobalData.af_RightCamMarkerDistHistory[   ]                    [-100.f ...100.f]

  @c_switch_part   FCT_SIMU                       : Configuration switch for enabling simulation profiling

  @c_switch_full   FCT_CFG_FIP_LANE_MATRIX_FUSION : Config switch for fusion of different input sources for FIP Lane Matrix
  @c_switch_full   SLATE_CFG_CAM_LANE_INTERFACE : Configuration switch enabling camera lane input data to FCT_SEN
  @c_switch_full   FCT_CFG_ACC_SITUATION   :  FCT support for ACC SIT (situation) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         10/27/2015
  @changed         1/22/2016

  @author          Marie-Theres Boll | marie-theres.boll@continental-corporation.com | +49 (8382) 9699-632
*************************************************************************************************************************/
static void SIT_v_SetLaneChangeMovePre(SITLaneChangeCamPreMove_t * p_SILaneChangeCamPreMoveState)
{
  uint8 i;
  boolean b_DrvLeftCamLane, b_DrvRightCamLane;
  SIT_LC_t_LaneChangeState t_LCState;
  sint16 s_LCProbCam;
  float32 f_DistCamLaneMarkerLeft, f_DistCamLaneMarkerRight, f_AbsDistCamLaneMarkerLeft, f_AbsDistCamLaneMarkerRight, f_CamLaneWidth;
  float32 f_SumDistDrivenLeft, f_SumDistDrivenRight;
  float32 f_CamLaneVisibilityDist;


  /*! Set default: No lane change */
  *p_SILaneChangeCamPreMoveState = LANE_CHANGE_CAM_PRE_MOVE_NO;

  /*! Store distance to camera lane markers, width of the camera lane and 
      visibility distance of the camera lane in a local variable */
  f_DistCamLaneMarkerLeft = pt_SITInput->t_RTE.pt_CamLaneData->LaneMarkerInfo[FIP_CL_MK_LEFT].f_MarkerDist;
  f_DistCamLaneMarkerRight = pt_SITInput->t_RTE.pt_CamLaneData->LaneMarkerInfo[FIP_CL_MK_RIGHT].f_MarkerDist;
  f_AbsDistCamLaneMarkerLeft = fABS(f_DistCamLaneMarkerLeft);
  f_AbsDistCamLaneMarkerRight = fABS(f_DistCamLaneMarkerRight);
  f_CamLaneWidth = pt_SITInput->pt_FIPCamLane->f_LaneWidth;  /*!< Width of camera lane */
  f_CamLaneVisibilityDist = pt_SITInput->pt_FIPCamLane->f_VisibilityDist;/*!< Visibility distance of camera lane */

  /*! Fill camera lane history buffer */
  /*! First: Move entries for left and right buffer */
  for( i = SIT_LC_CAM_LANE_MARKER_HISTORY_BUFFER - 1u; i >= 1u ; i--)
  {
    SITLCCamMovePreGlobalData.af_LeftCamMarkerDistHistory[i] = SITLCCamMovePreGlobalData.af_LeftCamMarkerDistHistory[i - 1u];
    SITLCCamMovePreGlobalData.af_RightCamMarkerDistHistory[i] = SITLCCamMovePreGlobalData.af_RightCamMarkerDistHistory[i - 1u];
  }

  /*! Second: Set the new value at the 0-th entry -> If the state is invalid, set the default value */
  /*! Left side */
  if( (f_CamLaneVisibilityDist > C_F32_DELTA) && 
      (pt_SITInput->t_RTE.pt_CamLaneData->LaneMarkerInfo[FIP_CL_MK_LEFT].u_ExistanceProbability >= FIP_CAM_LANE_POE_LEVEL) 
    )
  {
   SITLCCamMovePreGlobalData.af_LeftCamMarkerDistHistory[0u] = f_DistCamLaneMarkerLeft;
  }
  else
  {
    SITLCCamMovePreGlobalData.af_LeftCamMarkerDistHistory[0u] = SIT_LC_CAM_DEFAULT_CAM_LANE_MARKER_DIST;
  }
  /*! Right side */
  if( (f_CamLaneVisibilityDist > C_F32_DELTA) &&
      (pt_SITInput->t_RTE.pt_CamLaneData->LaneMarkerInfo[FIP_CL_MK_RIGHT].u_ExistanceProbability >= FIP_CAM_LANE_POE_LEVEL)
    )
  {
    SITLCCamMovePreGlobalData.af_RightCamMarkerDistHistory[0u] = f_DistCamLaneMarkerRight;
  }
  else
  {
    SITLCCamMovePreGlobalData.af_RightCamMarkerDistHistory[0u] = SIT_LC_CAM_DEFAULT_CAM_LANE_MARKER_DIST;
  }

  /*! Determine if the ego vehicle is driving to the left or right side based on the distance to the camera lane markers 
      -> the ego vehicle is considered to drive to one side, if all entries in the histroy buffer indicate this 
      (i.e. the distance to the lane markers must become higher or lower for all entries in the history buffer) */
  b_DrvLeftCamLane = TRUE;
  b_DrvRightCamLane = TRUE;
  f_SumDistDrivenLeft = 0.f;
  f_SumDistDrivenRight = 0.f;
  for ( i = 0u ; i < (SIT_LC_CAM_LANE_MARKER_HISTORY_BUFFER - 1u); i++)
  {
    /*! Determine if the ego vehicle is driving to the left */
    if( (SITLCCamMovePreGlobalData.af_LeftCamMarkerDistHistory[i] > (SIT_LC_CAM_DEFAULT_CAM_LANE_MARKER_DIST - C_F32_DELTA)) || 
        (SITLCCamMovePreGlobalData.af_LeftCamMarkerDistHistory[i + 1u] > (SIT_LC_CAM_DEFAULT_CAM_LANE_MARKER_DIST - C_F32_DELTA)) ||
        ((SITLCCamMovePreGlobalData.af_LeftCamMarkerDistHistory[i] - SITLCCamMovePreGlobalData.af_LeftCamMarkerDistHistory[i + 1u]) > C_F32_DELTA)
      )
    {
      b_DrvLeftCamLane = FALSE;
    }
    else
    {
      f_SumDistDrivenLeft += (SITLCCamMovePreGlobalData.af_LeftCamMarkerDistHistory[i + 1u] - SITLCCamMovePreGlobalData.af_LeftCamMarkerDistHistory[i]);
    }
    /*! Determine if the ego vehicle is driving to the right */
    if( (SITLCCamMovePreGlobalData.af_RightCamMarkerDistHistory[i] > (SIT_LC_CAM_DEFAULT_CAM_LANE_MARKER_DIST - C_F32_DELTA)) || 
        (SITLCCamMovePreGlobalData.af_RightCamMarkerDistHistory[i + 1u] > (SIT_LC_CAM_DEFAULT_CAM_LANE_MARKER_DIST - C_F32_DELTA)) ||
        ((SITLCCamMovePreGlobalData.af_RightCamMarkerDistHistory[i] - SITLCCamMovePreGlobalData.af_RightCamMarkerDistHistory[i + 1u]) < -C_F32_DELTA)
      )
    {
      b_DrvRightCamLane = FALSE;
    }
    else
    {
      f_SumDistDrivenRight += (SITLCCamMovePreGlobalData.af_RightCamMarkerDistHistory[i] - SITLCCamMovePreGlobalData.af_RightCamMarkerDistHistory[i + 1u]);
    }
  }

  /*! Reset results if the driven distance to the left/right side is not sufficient high or too high (camera lane marker are crossed)*/
  if( (b_DrvLeftCamLane == TRUE) && ( (f_SumDistDrivenLeft < SIT_LC_CAM_MOVE_PRE_MIN_DIVENDIST_TO_SIDE) || (f_SumDistDrivenLeft > SIT_LC_CAM_MOVE_PRE_MAX_DIVENDIST_TO_SIDE) ) )
  {
     b_DrvLeftCamLane = FALSE;
  }
  if( (b_DrvRightCamLane == TRUE) && ( (f_SumDistDrivenRight < SIT_LC_CAM_MOVE_PRE_MIN_DIVENDIST_TO_SIDE) || (f_SumDistDrivenLeft > SIT_LC_CAM_MOVE_PRE_MAX_DIVENDIST_TO_SIDE) ) )
  {
    b_DrvRightCamLane = FALSE;
  }

  /*! Reset results due to implausibility */
  if( (b_DrvLeftCamLane == TRUE) && (b_DrvRightCamLane == TRUE))
  {
    b_DrvLeftCamLane = FALSE;
    b_DrvRightCamLane = FALSE;
  }

  /*! Determine the lane change direction (only if the lane marker information are reliable 
      -> valid lane markers, visibility distance higher than a threshold, valid camera lane width) */
  if( (f_CamLaneVisibilityDist > C_F32_DELTA) && 
      (pt_SITInput->t_RTE.pt_CamLaneData->LaneMarkerInfo[FIP_CL_MK_LEFT].u_ExistanceProbability >= FIP_CAM_LANE_POE_LEVEL) &&
      (pt_SITInput->t_RTE.pt_CamLaneData->LaneMarkerInfo[FIP_CL_MK_RIGHT].u_ExistanceProbability >= FIP_CAM_LANE_POE_LEVEL) &&
      (f_CamLaneWidth > C_F32_DELTA) 
    )
  {
    /*! Get the lane change probability */
    s_LCProbCam = pt_SITOutput->s_LCProb;
    t_LCState = pt_SITOutput->t_LaneChangePhase.t_LCPhaseState;

    /*! Lane Change left: Considered only until the lane marker is crossed and when the ego vehicle is still 
        at the left side of the lane (fABS(f_DistCamLaneMarkerLeft) < fABS(f_DistCamLaneMarkerRight));
        Situation after the lane marker is crossed is handled by the function FIP_v_LaneMatrixFilteringOneSide(...) */
    if( (f_AbsDistCamLaneMarkerLeft < f_AbsDistCamLaneMarkerRight) &&
        (b_DrvLeftCamLane == TRUE) &&
        (t_LCState == LC_LEFT) &&
        ( (s_LCProbCam > SIT_LC_CAM_MOVE_PRE_LM_MIN_LC_PROB) || 
          (f_DistCamLaneMarkerLeft < SIT_LC_CAM_MOVE_PRE_MAX_DIST_LANE_MARKER_LC)
        )
      )
    {
      *p_SILaneChangeCamPreMoveState = LANE_CHANGE_CAM_PRE_MOVE_LEFT;
    }

    /*! Lane Change right: Considered only until the lane marker is crossed and when the ego vehicle is still 
    at the right side of the lane (fABS(f_DistCamLaneMarkerRight) < fABS(f_DistCamLaneMarkerLeft));
    Situation after the lane marker is crossed is handled by the function FIP_v_LaneMatrixFilteringOneSide(...) */
    if( (f_AbsDistCamLaneMarkerRight < f_AbsDistCamLaneMarkerLeft) &&
        (b_DrvRightCamLane == TRUE) &&
        (t_LCState == LC_RIGHT) &&
        ( (s_LCProbCam > SIT_LC_CAM_MOVE_PRE_LM_MIN_LC_PROB) || 
          (f_DistCamLaneMarkerRight > -SIT_LC_CAM_MOVE_PRE_MAX_DIST_LANE_MARKER_LC)
        )
      )
    {
      *p_SILaneChangeCamPreMoveState = LANE_CHANGE_CAM_PRE_MOVE_RIGHT;
    }
  }

}
#endif


#if ((FCT_CFG_FIP_LANE_MATRIX_FUSION) && (SLATE_CFG_CAM_LANE_INTERFACE))
/*************************************************************************************************************************
  Functionname:    SIT_v_InitGlobLCCamLanePreMove                                                                    */ /*!

  @brief           Initialize global information for lane change camera move pre state

  @description     Initialize global information for lane change camera move pre state

                   @startuml
                   partition SIT_v_InitGlobLCCamLanePreMove {
                   start
                       : Initialize global information for lane change camera move pre state
                       1.Left Camera Lane marker distance history buffer
                       2.Right Camera Lane marker distance history buffer;
                   Stop
                   }
                   @enduml

  @return          -

  @param[in]       -

  @glob_in         -

  @glob_out        SITLCCamMovePreGlobalData.af_LeftCamMarkerDistHistory[   ]        [-100.f ...100.f]
  @glob_out        SITLCCamMovePreGlobalData.af_RightCamMarkerDistHistory[   ]       [-100.f ...100.f]
  @glob_out        pt_SITOutput->t_LaneChangeCamPreMoveState : Lane change pre state [typet_SILaneChangeCamPreMove defined in sit_ext.h]

  @c_switch_part   -

  @c_switch_full   FCT_CFG_FIP_LANE_MATRIX_FUSION : Config switch for fusion of different input sources for FIP Lane Matrix
  @c_switch_full   SLATE_CFG_CAM_LANE_INTERFACE : Configuration switch enabling camera lane input data to FCT_SEN
  @c_switch_full   FCT_CFG_ACC_SITUATION   :  FCT support for ACC SIT (situation) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         10/27/2016
  @changed         1/22/2016

  @todo            -

  @author          Marie-Theres Boll | marie-theres.boll@continental-corporation.com | +49 (8382) 9699-632
*************************************************************************************************************************/
static void SIT_v_InitGlobLCCamLanePreMove(void)
{
  uint8 i;
  /* Initialize camera lane marker distance history buffer */
  for (i = 0u; i < SIT_LC_CAM_LANE_MARKER_HISTORY_BUFFER; i++)
  {
    SITLCCamMovePreGlobalData.af_LeftCamMarkerDistHistory[i] = SIT_LC_CAM_DEFAULT_CAM_LANE_MARKER_DIST;
    SITLCCamMovePreGlobalData.af_RightCamMarkerDistHistory[i] = SIT_LC_CAM_DEFAULT_CAM_LANE_MARKER_DIST;
  }

  /* Initialize SILaneChangeCamPreMoveState */
  pt_SITOutput->t_LaneChangeCamPreMoveState = LANE_CHANGE_CAM_PRE_MOVE_NO;
}
#endif
///@}
/* PRQA L:EMPTY_ELSE_OR_DEFAULT */
/* PRQA L:EMPTY_ELSE_OR_DEFAULT */
#endif /* (FCT_CFG_ACC_SITUATION) */
/*****************************************************************************
  UNDEF MODULE LOCAL SYMBOLIC CONSTANTS
*****************************************************************************/
// PRQA L:STTLN_EXCEEDED 
