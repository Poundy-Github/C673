/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 SLATE_SIT (Situation)

PACKAGENAME:               sit_lanechange.c

DESCRIPTION:               ACC lane change detection of the host vehicle. The information
                           of different observers, comprising kinematic, camera, and multi-object,
                           are combined to detect three phases of a lane change.

AUTHOR:                    Christopher Knievel

CREATION DATE:             04.12.2014

VERSION:                   $Revision: 1.44 $

LEGACY VERSION:            Revision: 2.1
  
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
@defgroup sit_lanechange Sit Lane change
@ingroup sit
@brief          This module detects ACC Lane change of object.\n\n
@{
*/
/*****************************************************************************
MODULEGLOBAL CONSTANTS
*****************************************************************************/


/*****************************************************************************
MODULGLOBAL VARIABLES
*****************************************************************************/
#if (SIT_CFG_LC_PROB_CALC)
SITLCProbDataGlobal_t SITLCProbDataGlobal; 
#endif

#ifdef FCT_SIMU
/*! Calculation of lane change prob */  
#ifndef SIT_LC_PROB_DEBUG_VADDR
#define SIT_LC_PROB_DEBUG_VADDR  (0x2020FD00u)
#endif

SET_MEMSEC_VAR(SITInternalLCProbDebugData)
  /*! Debug information */
  SITLCProbDebugData_t SITInternalLCProbDebugData;

SET_MEMSEC_CONST(SITLCProbDebugMeasInfo)
  static const MEASInfo_t SITLCProbDebugMeasInfo =
{
  SIT_LC_PROB_DEBUG_VADDR,             /*!<.VirtualAddress */
  sizeof(SITInternalLCProbDebugData),  /*!<.Length */
  FCT_MEAS_FUNC_ID,                   /*!<.FuncID */
  FCT_MEAS_FUNC_CHAN_ID               /*!<.FuncChannelID */
};
#endif
/*****************************************************************************
MODULE LOCAL SYMBOLIC CONSTANTS
*****************************************************************************/

/*****************************************************************************
MODULE LOCAL MACROS
*****************************************************************************/
#define SIT_LC_HYSTERESIS_TIME         SLATE_f_GetCycleTime() 

/*****************************************************************************
MODULE LOCAL TYPES
*****************************************************************************/


/*****************************************************************************
MODULE LOCAL CONSTANTS
*****************************************************************************/
#define SIT_LC_STEERBACK_TIME_FACTOR   (3.f )
#define SIT_LC_HYSTERESIS_STEERBACK_TIME      (1.0f)
/* Max time in which state can persist  in seconds cant have a 0 value */
#define SIT_LC_STATE_HYSTERESIS ( 2.0f )
/*time difference between current calculated hystersis and previous cycle hystersis time used for checking steerback transition conditions */
#define SIT_LC_TO_STEERBACK_MIN_TIME ( 0.2f )
/* The maximum value for normally distributed random variable used for calculation of normal distribution */
#define SIT_LC_GAUSS_RANDOM_VARIBLE_MAX (150.0f)
/* The minimum value for normally distributed random variable used for calculation of normal distribution */
#define SIT_LC_GAUSS_RANDOM_VARIBLE_MIN (-150.0f)
/*! Prefactor for Gaussian distribution SQRT_(2.0f * CML_F_pi) */
#define SIT_LC_GAUSS_PREFAC (2.50662827f)
/*Steerback kinematic probability threshold*/
#define SIT_LC_STEERBACK_KINEMATIC_THRESH (0.5f)
/*! Maximum time to determine the lane change state */
#define SIT_LC_MAX_TIME_STATE   (0.5f) /* maximum time for LC to persist */
#define SIT_LC_PROB_THRESHOLD   (50u)  /* lane change prob threshold used to determine state pre, LC, post*/
#define SIT_LC_PROBTOPRECENTAGE (100.f) /* used to convert final floating point prob to an integer*/

/*weights for each observer used in final fusion*/
#define SIT_LC_CFG_USE_CAMERAFUSION_WEIGHT (0.8f) 
#define SIT_LC_KINEMATICFUSION_WEIGHT (0.2f)
#if (SIT_LC_CFG_LANEMATRIX_FUSION)
#define SIT_LC_ENVIROMENTFUSION_WEIGHT (0.2f)
#endif
#if (SIT_LC_CFG_ENABLE_MULTIOBJECTFUSION)
#define SIT_LC_MULTIOBJFUSION_WEIGHT  (0.1f)
#endif

#if (!SIT_LC_CFG_USE_TURNIND_CAMERA_PROB)
  /* lane change prob threshold used to determine steerback state */
#define SIT_LC_PROB_THRESHOLD_STEERBACK ( 20u )
  /*check if right prob is high enough to consider a valid left/right state*/
#define SIT_LC_PROB_RIGHT_LOWTHRESHOLD ( 0.2f )
  /* check if left prob is high enough to consider a valid left/right state */
#define SIT_LC_PROB_LEFT_LOWTHRESHOLD ( 0.2f )
  /* minimum value threshold used to enter lane change or steer back state given high enough kinematic probabilities*/
#define SIT_LC_PROBMIN_LANECHANGE (30u)
#endif /*!< (!SIT_LC_CFG_USE_TURNIND_CAMERA_PROB) */

/* a factor used to adjust weights depending on phase due to the difference in source responsive in different phases*/
#define SIT_LC_FUSIONWEIGHT_ADJUSTMENT (0.2f)
  /* threshold from which left prob is determined as high*/ /* used in peak filtering*/
#define SIT_LC_PROB_LEFT_THRESHOLD ( 0.25f ) 
  /* threshold from which right prob is determined as high*/ /* used in peak filtering*/
#define SIT_LC_PROB_RIGHT_THRESHOLD ( 0.25f )
  /* threshold to check if there is a high enough left kinematic prob*/
#define SIT_LC_PROB_LEFT_THRESHOLD_KIN ( 0.7f )
  /*threshold to check if there is a high enough right kinematic prob*/
#define SIT_LC_PROB_RIGHT_THRESHOLD_KIN ( 0.7f ) 
  /* threshold used to determine if kinematic prob is high enough to enter lane change state directly or not*/
#define SIT_LC_PROB_LEFT_MAXTHRESHOLD ( 0.65f ) 
  /* threshold used to determine if kinematic prob is high enough to enter lane change state directly or not */
#define SIT_LC_PROB_RIGHT_MAXTHRESHOLD ( 0.65f ) 
  /* added to environment prob when conditions for relevant objects are meet, it is deducted otherwise*/
#define SIT_LC_VALIDFRONT_OBJECTPROB ( 0.3f ) 
  /* minimum prob assigned to environment in case it is lower than zero*/
#define SIT_LC_MIN_ENVIPROB ( 0.2f )
  /* added to environment prob when conditions for side objects are meet deducted otherwise*/
#define SIT_LC_VALIDSIDE_OBJECTPROB ( 0.5f ) 
  /* prob added when no side object are available */
#define SIT_LC_NOOBJECTS_ENVIPROB ( 0.3f ) 
  /* added prob to environment if lane on either left or right is valid in lane matrix*/
#define SIT_LC_VALIDLANE_ENVIPROB (1.0f) 
  /*unit:Meter, this is currently an adhoc value to be replaced with dynamically computed minimum stopping distance using EGO velocity*/
#define SIT_LC_STOPPING_DISTANCE (40.0f) 
  /* turn indicator  set count down hysteresis time */
#define SIT_LC_MAX_TIME_TURNINDICATOR ( 5.0f )
  /*Intercept for linear relationship between velocity and state hysteresis */
#define SIT_LC_STATE_HYSTERESIS_INTERCEPT   (1.5f) /* y = (x/-120)+ 1.5 */
#define SIT_LC_STATE_HYSTERESIS_SLOPEFACTOR (-120.f) /* y = (x/-120)+ 1.5 */
  /*! Minimum speed for which the lane change prob based on  environment is calculated */
#define SIT_LC_MIN_SPEED_TIENV (25.0f/C_KMH_MS)
  /*Section for impulse filter defines*/
  /* prob filter time used to remove peak values  in seconds*/
#define SIT_LC_PULSE_TIME_FILTER ( 0.05f )
  /*prob range 0.3 lowest 1.0 highest used to smoothing lane change and filter out peaks*/
#define SIT_LC_PEAKFILTER_MAX_PROB ( 1.0f ) 
  /* low prob to filter peaks*/
#define SIT_LC_PEAKFILTER_BASEPROB ( 0.5f ) 

/*section for turn indicator  probability calculation*/
/*Turn indicator off prob of LC*/
#define SIT_LC_TURNINDICATOR_BASEPROB   ( 0.7f ) 
/*Turn indicator prob range 1.0 max, 0.7 min, 1.0 - 0.7*/
#define SIT_LC_TURNINDICATOR_MAX_PROB ( 1.0f )
/* time difference tolerance for indicating  both turn indicators on*/
#define SIT_LC_TURNINDICATOR_TOLERANCE (0.01f)

#if (SIT_CFG_LC_USE_TURN_INDICATOR_INPUT)
/*array to calculate turn indicator prob*/
static const GDBLFunction_t SIT_LC_TURNIND_PROB = {// PRQA S 3218, 3207
/* date: 2017-11-24, reviewer: Shruthi Ramaiah, reason: static local required for saving data across function calls */
  SIT_LC_TURNINDICATOR_BASEPROB, /*min output probability  */
  SIT_LC_TURNINDICATOR_MAX_PROB, /*max output probability */
  (SIT_LC_TURNINDICATOR_MAX_PROB - SIT_LC_TURNINDICATOR_BASEPROB) /(SIT_LC_MAX_TIME_TURNINDICATOR - 0.0f),/* slope*/
  SIT_LC_TURNINDICATOR_BASEPROB-(((SIT_LC_TURNINDICATOR_MAX_PROB)/(SIT_LC_MAX_TIME_TURNINDICATOR - 0.0f))*0.0f)
};
#endif /*(SIT_CFG_LC_USE_TURN_INDICATOR_INPUT)*/
/*****************************************************************************
MODULE LOCAL TYPEDEFS
*****************************************************************************/

/*****************************************************************************
MODULE LOCAL VARIABLES
*****************************************************************************/


/*****************************************************************************
FUNCTION PROTOTYPES
*****************************************************************************/
#if (SIT_CFG_LC_USE_TURN_INDICATOR_INPUT)
static void SIT_LC_v_FilterTurnIndicator(eTurnIndicator_t t_TurnIndicator);
#endif /*(SIT_CFG_LC_USE_TURN_INDICATOR_INPUT)*/

#if (SIT_CFG_LC_PROB_CALC)
#if (SIT_LC_CFG_LANEMATRIX_FUSION)
/*calculate environment prob*/
static void SIT_v_DetectLaneChangeTIEnv(void);
#endif
#if (SIT_LC_CFG_ENABLE_MULTIOBJFUSION)
/*calculate environment prob*/
static boolean SIT_b_DetectLaneChangeMultiObject(void);
#endif
#if (SIT_LC_USE_FILTER_PEAK_PROB)
/*a filter for prob peaks*/
static void SIT_v_FilterPeakProb(void);
#endif
/* state machine for the different lanechange phases and states */
#if (SIT_LC_CFG_ENABLE_MULTIOBJFUSION)
static void SIT_v_SetLaneChangeOutput(boolean b_PreLaneChange);
static void SIT_v_NoLaneChangeState(boolean b_PreLaneChange);
static void SIT_v_PreLaneChangeState(boolean b_PreLaneChange);
#else
static void SIT_v_SetLaneChangeOutput(void);
static void SIT_v_NoLaneChangeState(void);
static void SIT_v_PreLaneChangeState(void);
#endif

static void SIT_v_SetLaneChangeTimeGap(void);
static void SIT_v_LaneChangeState( float32 f_StateHysteresis );
static void SIT_v_LaneChangeProbFusion(void);
static void SIT_v_DetermineLaneChangeState(void);
#endif

#if (SIT_CFG_LC_USE_TURN_INDICATOR_INPUT) 
eTurnIndicator_t SIT_t_SetTurnIndState(void);
static void SIT_v_SetTurnIndicatorProb(float32 * const f_LeftTurnIndProb ,float32 * const f_RightTurnIndProb);
#endif

/* ************************************************************************* */
/*   Copyright ADC-GmbH, Lindau                                              */
/* ************************************************************************* */

#if (SIT_CFG_LC_USE_TURN_INDICATOR_INPUT) 
/* ***********************************************************************
@fn             SIT_t_SetFilterTurnIndState                           */ /*!

@brief          Returns the filtered turn indicator signal

@description    Returns the filtered turn indicator signal.

                 @startuml
                 Partition SIT_t_SetTurnIndState{
                 Start
                 If (filtered turn Left OR Right) then (TRUE)
                 If (both hysteresis timers are equal) then (TRUE)
                 : both left and right indicators are set;
                 Elseif (the right hysteresis value is higher) then (TRUE)
                 : right turn indicator lastly used;
                 Else (FALSE)
                 : A left hysteresis is valid and used then;
                 Endif
                 Else (FALSE)
                 : Set Indicator state off;
                 Endif
                 End
                 }
                 @enduml

@return         eTurnIndicator_t

@param[in]       -

@glob_in         - pt_SITOutput->t_LaneChangeStatic.f_TimeFiltTurnIndLeft
@glob_in         - pt_SITOutput->t_LaneChangeStatic.f_TimeFiltTurnIndRight
@glob_out        - pt_SITOutput->t_LaneChangeStatic.f_TimeFiltTurnIndLeft
@glob_out        - pt_SITOutput->t_LaneChangeStatic.f_TimeFiltTurnIndRight

@c_switch_part   SIT_CFG_LC_PROB_CALC  : Configuration switch enabling lane change prob calculation 
@c_switch_full   FCT_CFG_ACC_SITUATION : FCT support for ACC SIT (situation) sub-component

@pre             -
@post            -

@testmethod        Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

@created         -
@changed         -


@pre            -

@author         Marie-Theres Boll , Christopher Knievel, Ahmed Shabayek

**************************************************************************** */
eTurnIndicator_t SIT_t_SetTurnIndState(void)
{
  /* Variable for storing returned state*/
  eTurnIndicator_t t_TurnindicatorState;
  const float32 TimeFiltLeftTI = pt_SITOutput->t_LaneChangeStatic.f_TimeFiltTurnIndLeft;
  const float32 TimeFiltRightTI = pt_SITOutput->t_LaneChangeStatic.f_TimeFiltTurnIndRight;
  if ( (TimeFiltLeftTI > 0.0f)
    || (TimeFiltRightTI > 0.0f) )
  {
    /* if both hysteresis timers are equal then both left and right indicators are set (waiting)*/
    if ( fABS(TimeFiltLeftTI - TimeFiltRightTI) < SIT_LC_TURNINDICATOR_TOLERANCE )
    {
      t_TurnindicatorState =  eTurnIndicator_Both;
    }
    /*if the right hysteresis value is higher then its a right turn indicator lastly used*/
    else if(pt_SITOutput->t_LaneChangeStatic.f_TimeFiltTurnIndRight > pt_SITOutput->t_LaneChangeStatic.f_TimeFiltTurnIndLeft )
    {
      t_TurnindicatorState = eTurnIndicator_Right;
    }

    else/* A left hysteresis is valid and used then*/
    {
      t_TurnindicatorState = eTurnIndicator_Left;
    }

  }
  else
  {
    t_TurnindicatorState = eTurnIndicator_Off;
  }
  return t_TurnindicatorState;
}
#endif  /*(SIT_CFG_LC_USE_TURN_INDICATOR_INPUT) */
#if (SIT_CFG_LC_USE_TURN_INDICATOR_INPUT)
/* ***********************************************************************
@fn             SIT_LC_v_FilterTurnIndicator                           */ /*!

@brief          Filter the turn indicator signal

@description    Filter the turn indicator signal. Prolongs the signal
for a given time.

                 @startuml
                 Partition SIT_LC_v_FilterTurnIndicator{
                 Start
                 If (the turn indicator is switched ON or not) then (ON)
                 If (Turn Indicator Left) then (TRUE)
                 : set hysteresis countdown time to the left time filter variable;
                 : Left indicator is ON in current cycle but check for\n Right indicator hysteresis and reduce filter time;
                 Elseif (Turn Indicator Right) then (TRUE)
                 : set hysteresis countdown time  to the right time filter variable;
                 : Right indicator is ON in current cycle but check for\n Left indicator hysteresis and reduce filter time;
                 Else (FALSE)
                 : both indicators are ON, DO NOTHING;
                 Endif
                 Else (no indicator is switched ON)
                 : hysteresis time is reduced till zero, then the turn indicator\n is assumed to have always been OFF;
                 Endif
                 End
                 }
                 @enduml

@param          -

@return         -

@param[in]       -

@glob_in         pt_SITOutput->t_LaneChangeStatic.f_TimeFiltTurnIndLeft
@glob_in         pt_SITOutput->t_LaneChangeStatic.f_TimeFiltTurnIndRight
@glob_in         pt_SITOutput->t_LaneChangeStatic.TurnIndLastStatus
@glob_out        -

@c_switch_part   SIT_CFG_LC_PROB_CALC  : Configuration switch enabling lane change prob calculation 
@c_switch_full   FCT_CFG_ACC_SITUATION : FCT support for ACC SIT (situation) sub-component
@c_switch_full   SIT_LC_CFG_USE_TURNIND_CAMERA_PROB : Configuration switch to enable lane change probability calculation using turn indicator input and camera lane input

@pre             -
@post            -

@testmethod        Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

@created         -
@changed         -

@pre            -

@author         Marie-Theres Boll
Christopher Knievel
**************************************************************************** */
static void SIT_LC_v_FilterTurnIndicator(eTurnIndicator_t t_TurnIndicator)
{
  /*check if the turn indicator is switched ON*/
  if (   (t_TurnIndicator != eTurnIndicator_Off) 
#if (SIT_LC_CFG_USE_TURNIND_CAMERA_PROB)
      && (pt_SITOutput->t_LaneChangeStatic.TurnIndLastStatus != t_TurnIndicator)
#endif /*!< SIT_LC_CFG_USE_TURNIND_CAMERA_PROB */
  )
  {
    /* Case: Left indicator, set hysteresis countdown time to the left time filter variable */
    if (t_TurnIndicator == eTurnIndicator_Left)
    {
      pt_SITOutput->t_LaneChangeStatic.f_TimeFiltTurnIndLeft = SIT_LC_MAX_TIME_TURNINDICATOR;
      if(pt_SITOutput->t_LaneChangeStatic.f_TimeFiltTurnIndRight > 0.0f )
      {
        /* Left indicator is ON in current cycle but check for Right indicator hysteresis and reduce filter time */
        pt_SITOutput->t_LaneChangeStatic.f_TimeFiltTurnIndRight = 0.0f;
      }
    }
    /* Case: Right indicator, set hysteresis countdown time  to the right time filter variable */
    else if (t_TurnIndicator == eTurnIndicator_Right)
    {
      pt_SITOutput->t_LaneChangeStatic.f_TimeFiltTurnIndRight = SIT_LC_MAX_TIME_TURNINDICATOR;
      if(pt_SITOutput->t_LaneChangeStatic.f_TimeFiltTurnIndLeft > 0.0f )
      {
        /* Right indicator is ON in current cycle but check for Left indicator hysteresis and reduce filter time */
        pt_SITOutput->t_LaneChangeStatic.f_TimeFiltTurnIndLeft = 0.0f;
      }
    }
    else
    {
      /* Case where both indicators are ON, DO NOTHING */
    }
  }
  else /* if turn indicator is switched OFF or turn indicator is already ON, then hysteresis time is reduced till zero */
  {
    if(pt_SITOutput->t_LaneChangeStatic.f_TimeFiltTurnIndLeft > 0.0f )
    {
      pt_SITOutput->t_LaneChangeStatic.f_TimeFiltTurnIndLeft-= SLATE_f_GetSITCycleTime();
    }
    if(pt_SITOutput->t_LaneChangeStatic.f_TimeFiltTurnIndRight > 0.0f )
    {
      pt_SITOutput->t_LaneChangeStatic.f_TimeFiltTurnIndRight-= SLATE_f_GetSITCycleTime();
    }
  } /* Check if Turn indicator is ON (t_TurnIndicator != eTurnIndicator_Off) */

#if (SIT_LC_CFG_USE_TURNIND_CAMERA_PROB)
  pt_SITOutput->t_LaneChangeStatic.TurnIndLastStatus = t_TurnIndicator;
#endif /*!< SIT_LC_CFG_USE_TURNIND_CAMERA_PROB */
}
#endif  /*(SIT_CFG_LC_USE_TURN_INDICATOR_INPUT) */
/*************************************************************************************************************************
Functionname:    SIT_v_InitLaneChange                                                                             */ /*!

@brief           Initialize lane change detection module

@description     Function initializes lane change detection module

                  @startuml
                  Partition SIT_v_InitLaneChange{
                  Start
                  : Initialize camera lane change observer;
                  : Initialize kinematic lane change observer;
                  End
                  }
                  @enduml

@return          -

@param[in]       - 

@glob_in        

@glob_out         pt_SITOutput->t_LaneChangeStatic.s_NumberLanesLeft
@glob_out         pt_SITOutput->t_LaneChangeStatic.s_NumberLanesRight
@glob_out         pt_SITOutput->t_LaneChangeStatic.s_relevantLaneObject
@glob_out         pt_SITOutput->t_LaneChangeStatic.s_leftLaneObject
@glob_out         pt_SITOutput->t_LaneChangeStatic.s_rightLaneObject
@glob_out         pt_SITOutput->t_LaneChangeStatic.f_LCProbMultiobjectLeft
@glob_out         pt_SITOutput->t_LaneChangeStatic.f_LCProbMultiobjectRight
@glob_out         pt_SITOutput->t_LaneChangeStatic.f_LCProbTIEnvLeft
@glob_out         pt_SITOutput->t_LaneChangeStatic.f_LCProbTIEnvRight
@glob_out         pt_SITOutput->t_LaneChangeStatic.f_LCFilterHysteresisLeft
@glob_out         pt_SITOutput->t_LaneChangeStatic.f_LCFilterHysteresisRight
@glob_out         pt_SITOutput->t_LaneChangeStatic.f_LCStateHysteresisLeft
@glob_out         pt_SITOutput->t_LaneChangeStatic.f_LCStateHysteresisRight
@glob_out         pt_SITOutput->t_LaneChangePhase.t_LCPhase
@glob_out         pt_SITOutput->t_LaneChangePhase.u_LCPhaseProb
@glob_out         pt_SITOutput->t_LaneChangeStatic.t_PreviousState   : Lane change state [LC_RIGHT ... LC_LEFT]
@glob_out         pt_SITOutput->t_LaneChangeStatic.f_LCCamLMHysteresisLeft
@glob_out         pt_SITOutput->t_LaneChangeStatic.TurnIndLastStatus
@glob_out         pt_SITOutput->t_LaneChangeStatic.f_LCCamLMHysteresiRight


@c_switch_part   SIT_CFG_LC_PROB_CALC  : Configuration switch enabling lane change prob calculation
@c_switch_full   FCT_CFG_ACC_SITUATION : FCT support for ACC SIT (situation) sub-component
@c_switch_full   SIT_LC_CFG_USE_TURNIND_CAMERA_PROB : Configuration switch to enable lane change probability calculation using turn indicator input and camera lane input

@pre             -
@post            -

@testmethod        Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

@traceability    117:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-117-00061542 \n

@created         -
@changed         -

@author          Christopher Knievel
*************************************************************************************************************************/
void SIT_v_InitLaneChange (void)
{
#if (SIT_LC_CFG_LANEMATRIX_FUSION)
  pt_SITOutput->t_LaneChangeStatic.s_NumberLanesLeft    = (sint8) 0;
  pt_SITOutput->t_LaneChangeStatic.s_NumberLanesRight   = (sint8)0;
  pt_SITOutput->t_LaneChangeStatic.f_LCProbTIEnvLeft        = 0.0f;
  pt_SITOutput->t_LaneChangeStatic.f_LCProbTIEnvRight       = 0.0f;  
#endif
#if (SIT_LC_CFG_ENABLE_MULTIOBJFUSION)
  pt_SITOutput->t_LaneChangeStatic.s_relevantLaneObject = (sint8)0;
  pt_SITOutput->t_LaneChangeStatic.s_leftLaneObject     = (sint8)0;
  pt_SITOutput->t_LaneChangeStatic.s_rightLaneObject    = (sint8)0;
  pt_SITOutput->t_LaneChangeStatic.f_LCProbMultiobjectLeft  = 0.0f;
  pt_SITOutput->t_LaneChangeStatic.f_LCProbMultiobjectRight = 0.0f;
#endif
  pt_SITOutput->t_LaneChangeStatic.f_LCFilterHysteresisLeft = 0.0f; 
  pt_SITOutput->t_LaneChangeStatic.f_LCFilterHysteresisRight = 0.0f;
  pt_SITOutput->t_LaneChangeStatic.f_LCStateHysteresisLeft = 0.0f; 
  pt_SITOutput->t_LaneChangeStatic.f_LCStateHysteresisRight = 0.0f;
  pt_SITOutput->t_LaneChangePhase.t_LCPhase = LC_NO_LANECHANGE ;
  pt_SITOutput->t_LaneChangePhase.u_LCPhaseProb = 0u;
  pt_SITOutput->t_LaneChangeStatic.t_PreviousState = LC_FOLLOW;
#if (SIT_LC_CFG_USE_TURNIND_CAMERA_PROB)
  pt_SITOutput->t_LaneChangeStatic.f_LCCamLMHysteresiRight = 0.f;
  pt_SITOutput->t_LaneChangeStatic.f_LCCamLMHysteresisLeft = 0.f;
  pt_SITOutput->t_LaneChangeStatic.TurnIndLastStatus = eTurnIndicator_Off;
  pt_SITOutput->t_LaneChangeStatic.f_LCSteerbackTimer = 0.f;
#endif /*!< SIT_LC_CFG_USE_TURNIND_CAMERA_PROB */
#if (SIT_CFG_LC_USE_TURN_INDICATOR_INPUT)
  pt_SITOutput->t_LaneChangeStatic.f_TimeFiltTurnIndLeft = 0.f;
  pt_SITOutput->t_LaneChangeStatic.f_TimeFiltTurnIndRight = 0.f;
#endif
#if (SIT_LC_CFG_USE_OVERTAKE_IN_LANECHANGE)
  pt_SITOutput->t_LaneChangePhase.t_AllowOvertake = LC_ALLOW_NO_OVERTAKE;
#endif


  /* Initialize camera lane change observer */
  SIT_v_InitLaneChangeCam();

  /* Initialize kinematic lane change observer */
#if (SIT_CFG_LC_PROB_CALC)
  SIT_v_InitLaneChangeKinem();
#endif
}

/*************************************************************************************************************************
Functionname:    SIT_v_DetectLaneChange                                                                           */ /*!

@brief           Detect ego lane change 

@description     Function that calls different observers and combines the probabilities of each observer to generate
                 a combined lane change prob.

                 @startuml
                 Partition SIT_v_DetectLaneChange{
                 Start
                 : turn indicator on/off based on hysteresis;
                 : Detect lane change (deprecated call for backward compatibility);
                 : kinematic observer prob calculation based on yawrate\n as well as distance to border and filtered driver curve stored;
                 : multi object observer prob calculation base on surrounding OOI stored;
                 : Environment observer prob calculation based on available lanes stored;
                 : Final fusion and lanechange state machine;
                 End
                 }
                 @enduml

@return          -

@param[in]       -

@glob_in         -
@glob_out        -

@c_switch_part   SIT_CFG_LC_PROB_CALC  : Configuration switch enabling lane change prob calculation 
@c_switch_full   FCT_CFG_ACC_SITUATION : FCT support for ACC SIT (situation) sub-component

@pre             -
@post            -

@testmethod        Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

@created         -
@changed         -

@author          Christopher Knievel
*************************************************************************************************************************/
void SIT_v_DetectLaneChange(void)
{
#if (SIT_LC_CFG_ENABLE_MULTIOBJFUSION)
  boolean b_PreLaneChange = FALSE;
#endif
#if (SIT_CFG_LC_USE_TURN_INDICATOR_INPUT)
  eTurnIndicator_t t_TurnIndicator = *pt_SITInput->t_RTE.pt_TurnIndicator;
  /* turn indicator on/off based on hysteresis*/
  SIT_LC_v_FilterTurnIndicator(t_TurnIndicator);
#endif  /* (SIT_CFG_LC_USE_TURN_INDICATOR_INPUT) */
  /**********************************************************************
  *      Calculate lane change based on different observers            *
  **********************************************************************/

  /* Detect lane change (deprecated call for backward compatibility) */
  SIT_v_DetectLaneChangeCam();

#if (SIT_CFG_LC_PROB_CALC)
  /*kinematic observer  prob calculation based on yawrate as well as distance to border and filtered driver curve stored in global variables*/
  SIT_v_CalculateKinematicLCProb();
  /*multi object observer  prob calculation base on surrounding OOI stored in global variables*/
#if (SIT_LC_CFG_ENABLE_MULTIOBJFUSION)
  b_PreLaneChange = SIT_b_DetectLaneChangeMultiObject();
#endif
#if (FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING)
#if (SIT_LC_CFG_LANEMATRIX_FUSION)
  /*Environment observer  prob calculation based on available lanes stored in global variables*/
  SIT_v_DetectLaneChangeTIEnv();
#endif
#endif
#if (SIT_LC_CFG_ENABLE_MULTIOBJFUSION)
  /*Final fusion and lanechange state machine*/
  SIT_v_SetLaneChangeOutput(b_PreLaneChange);
#else
  SIT_v_SetLaneChangeOutput();
#endif
#endif

#ifdef FCT_SIMU
  SITInternalLCProbDebugData.SITLCProbDataGlobal = SITLCProbDataGlobal;
  FCT_FREEZE_DATA(&SITLCProbDebugMeasInfo, &SITInternalLCProbDebugData, SIT_v_MeasCallback);
#endif
  /**********************************************************************
  *      Calculate additional lane change signals                       *
  **********************************************************************/




  /**********************************************************************
  *      Prepare fusion  output signals                                        *
  **********************************************************************/

  /* Set output values */




}
#if (SIT_LC_CFG_ENABLE_MULTIOBJFUSION)
/* ***********************************************************************
@fn             SIT_b_DetectLaneChangeMultiObject                           */ /*!

@brief          Detect lane change based on Surronding Object , speed distance as well as set prelanechange flag

@description    Sets prob based on surrounding objects their speed and distance 
                and turn the prelanechange flag in case of approaching  another front vehicle fast.
                side objects have the most weight in prob calculation 

                 @startuml
                 Partition SIT_b_DetectLaneChangeMultiObject{
                 Start
                 : Initialize relative velocity for left, right, front;
                 : Initialize relative distance for left, right, front;
                 : Initialize flags;
                 : change only when not changing lanes to avoid calculating\n based on object relative to the upcoming lane rather the current;
                 : check if front object exists with same or less speed;
                 If (distance and relative velocity allow for lane change) then (TRUE)
                 : if side object available meets lane change conditions prob is greatly increased;
                 Else (FALSE)
                 : if side object available does not meet lane change conditions prob is deducted;
                 Endif
                 : set min probability;
                 End
                 }
                 @enduml

@param          -

@return         boolean showing whether surrounding obstacles allow lane change while a slower front object is present 
@param[in]       -

@glob_in         -pt_SITOutput->t_LaneChangeStatic.s_relevantLaneObject
@glob_in         -pt_SITOutput->t_LaneChangeStatic.s_leftLaneObject
@glob_in         -pt_SITOutput->t_LaneChangeStatic.s_rightLaneObject
@glob_in         -pt_SITOutput->t_LaneChangeStatic.f_LCProbMultiobjectRight
@glob_in         -pt_SITOutput->t_LaneChangeStatic.f_LCProbMultiobjectLeft

@glob_out         -pt_SITOutput->t_LaneChangeStatic.s_relevantLaneObject
@glob_out         -pt_SITOutput->t_LaneChangeStatic.s_leftLaneObject
@glob_out         -pt_SITOutput->t_LaneChangeStatic.s_rightLaneObject
@glob_out         -pt_SITOutput->t_LaneChangeStatic.f_LCProbMultiobjectRight
@glob_out         -pt_SITOutput->t_LaneChangeStatic.f_LCProbMultiobjectLeft

@pre         -pt_SITOutput->t_LaneChangeStatic.s_relevantLaneObject
@pre         -pt_SITOutput->t_LaneChangeStatic.s_leftLaneObject
@pre         -pt_SITOutput->t_LaneChangeStatic.s_rightLaneObject

@post            -

@testmethod        Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

@created         -
@changed         -

@author         Ahmed Shabayek
**************************************************************************** */
static boolean SIT_b_DetectLaneChangeMultiObject(void)
{
  const float32 fEgoSpeed = *pt_SITInput->t_RTE.pf_EgoLongVel;
  /* relative velocity for left*/
  float32 f_reltaiveVelocityLeft;
  /* relative velocity for right*/
  float32 f_reltaiveVelocityRight;
  /* relative velocity for front*/
  float32 f_reltaiveVelocityfront;
  /* relative distance for left*/
  float32 f_reltaiveDistanceLeft;
  /* relative distance for right*/
  float32 f_reltaiveDistanceRight;
  /* relative distance for front*/
  float32 f_reltaiveDistancefront;// PRQA S 3203
  /* date: 2017-11-15, reviewer: Shruthi Ramaiah, reason: Redundant, but may be used in future*/	
  /*variables used to indicate whether or not conditions are suitable for  prelanechange state or not*/
  boolean b_PreLaneChange ;
  /* presence of a slower front object*/
  boolean b_FrontObject;
  /* flag set when side OOI 2 or 3 allow for lane change*/
  boolean b_sideObjectValid;
  /* flag set when left object exists */
  boolean b_validLeftObject;// PRQA S 3203
  /* date: 2017-11-15, reviewer: Shruthi Ramaiah, reason: Redundant, but may be used in future*/
  /*flag set when right object exists*/
  boolean b_validRightObject;// PRQA S 3203
  /* date: 2017-11-15, reviewer: Shruthi Ramaiah, reason: Redundant, but may be used in future*/
  /* flag set when front object exists*/
  boolean b_validFrontObject;
  /*Initialize flags*/
  b_validFrontObject = FALSE;
  b_validLeftObject  = FALSE;
  b_validRightObject = FALSE;
  b_PreLaneChange    = FALSE;
  b_FrontObject      = FALSE;
  b_sideObjectValid  = FALSE;
  f_reltaiveVelocityLeft  = 0.f;
  f_reltaiveVelocityRight = 0.f;
  f_reltaiveVelocityfront = 0.f;
  f_reltaiveDistanceLeft  = 0.f;
  f_reltaiveDistanceRight = 0.f;
  f_reltaiveDistancefront = 0.f;
  
  /* change only when not changing lanes to avoid calculating based on object relative to the upcoming lane  rather the curent*/
  if ( pt_SITOutput->t_LaneChangePhase.t_LCPhase != LC_LANECHANGE ) 
  {
    pt_SITOutput->t_LaneChangeStatic.s_relevantLaneObject = *pt_SITInput->t_OOI.pu_OOIListObjId(OBJ_NEXT_OOI);
    pt_SITOutput->t_LaneChangeStatic.s_leftLaneObject     = *pt_SITInput->t_OOI.pu_OOIListObjId(OBJ_NEXT_LONG_LEFT_OOI);
    pt_SITOutput->t_LaneChangeStatic.s_rightLaneObject    = *pt_SITInput->t_OOI.pu_OOIListObjId(OBJ_NEXT_LONG_RIGHT_OOI);
    if (pt_SITOutput->t_LaneChangeStatic.s_relevantLaneObject > OBJ_INDEX_NO_OBJECT  )
    {
      b_validFrontObject = TRUE;
      f_reltaiveVelocityfront = *SLATE_pf_GetObjVrelX(pt_SITOutput->t_LaneChangeStatic.s_relevantLaneObject);
      f_reltaiveDistancefront = *SLATE_pf_GetObjLongDisp(pt_SITOutput->t_LaneChangeStatic.s_relevantLaneObject); // PRQA S 3199
      /* date: 2017-12-05, reviewer: Harsha Umesh Babu, reason: Redundant, but may be used in future*/	
    }
    if (pt_SITOutput->t_LaneChangeStatic.s_leftLaneObject > OBJ_INDEX_NO_OBJECT  )
    {
      b_validLeftObject = TRUE;// PRQA S 3199
      /* date: 2017-11-15, reviewer: Shruthi Ramaiah, reason: Redundant, but may be used in future*/	
      f_reltaiveVelocityLeft = *SLATE_pf_GetObjVrelX( pt_SITOutput->t_LaneChangeStatic.s_leftLaneObject );
      f_reltaiveDistanceLeft = *SLATE_pf_GetObjLongDisp( pt_SITOutput->t_LaneChangeStatic.s_leftLaneObject );
    }
    else /* no objects left*/
    {
      pt_SITOutput->t_LaneChangeStatic.f_LCProbMultiobjectLeft += SIT_LC_NOOBJECTS_ENVIPROB;
    }

    if (pt_SITOutput->t_LaneChangeStatic.s_rightLaneObject > OBJ_INDEX_NO_OBJECT)
    {
      b_validRightObject = TRUE;// PRQA S 3199
      /* date: 2017-11-15, reviewer: Shruthi Ramaiah, reason: Redundant, but may be used in future*/	
      f_reltaiveVelocityRight = *SLATE_pf_GetObjVrelX(pt_SITOutput->t_LaneChangeStatic.s_rightLaneObject);
      f_reltaiveDistanceRight = *SLATE_pf_GetObjLongDisp(pt_SITOutput->t_LaneChangeStatic.s_rightLaneObject);
    }
    else
    {
      pt_SITOutput->t_LaneChangeStatic.f_LCProbMultiobjectRight += SIT_LC_NOOBJECTS_ENVIPROB;
    }
  }

  if(fEgoSpeed > SIT_LC_MIN_SPEED_TIENV)
  {
    /* check if front object exists with same or less speed */
    if ( ( b_validFrontObject == TRUE ) 
      && ( f_reltaiveVelocityfront >= 0.0f ) 
       )/*front object with same or less velocity */
    {
      pt_SITOutput->t_LaneChangeStatic.f_LCProbMultiobjectLeft += SIT_LC_VALIDFRONT_OBJECTPROB;
      pt_SITOutput->t_LaneChangeStatic.f_LCProbMultiobjectRight += SIT_LC_VALIDFRONT_OBJECTPROB;
      b_FrontObject = TRUE;
    }

    /*check if distance and relative velocity allow for lane change*/
    if ( ( f_reltaiveDistanceLeft > SIT_LC_STOPPING_DISTANCE ) 
      && (f_reltaiveVelocityLeft > 0) 
       )
    {
      /* if side object available meets lane change conditions prob is greatly increased*/
      pt_SITOutput->t_LaneChangeStatic.f_LCProbMultiobjectLeft += SIT_LC_VALIDSIDE_OBJECTPROB;
      b_sideObjectValid = TRUE ;
    }
    else
    {
      pt_SITOutput->t_LaneChangeStatic.f_LCProbMultiobjectLeft -= SIT_LC_VALIDSIDE_OBJECTPROB; /* if side object available does not meet lane change conditions prob is deducted*/
    }

    /*check if distance and relative velocity allow for lane change */
    if ( (f_reltaiveDistanceRight > SIT_LC_STOPPING_DISTANCE )
      && ( f_reltaiveVelocityRight > 0.0f )
       )
    {
      pt_SITOutput->t_LaneChangeStatic.f_LCProbMultiobjectRight += SIT_LC_VALIDSIDE_OBJECTPROB;
      b_sideObjectValid = TRUE ;
    }
    else
    {
      /*  deduction of prob based on absence of valid side object*/
      pt_SITOutput->t_LaneChangeStatic.f_LCProbMultiobjectRight -= SIT_LC_VALIDSIDE_OBJECTPROB;
    }
  }

  /* set min probability */
  if (pt_SITOutput->t_LaneChangeStatic.f_LCProbMultiobjectRight <= 0.0f)
  {
    pt_SITOutput->t_LaneChangeStatic.f_LCProbMultiobjectRight = SIT_LC_MIN_ENVIPROB;
  }

  /* set min probability */
  if (pt_SITOutput->t_LaneChangeStatic.f_LCProbMultiobjectLeft <= 0.0f)
  {
    pt_SITOutput->t_LaneChangeStatic.f_LCProbMultiobjectLeft = SIT_LC_MIN_ENVIPROB;
  }

  b_PreLaneChange = b_FrontObject && b_sideObjectValid;
  return b_PreLaneChange;
}
#endif
#if (SIT_CFG_LC_PROB_CALC) && (FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING)
#if (SIT_LC_CFG_LANEMATRIX_FUSION)
/* ***********************************************************************
@fn             SIT_v_DetectLaneChangeTIEnv                           */ /*!

@brief          Detect lane change based on turn signal indicator and environment

@description    Detect lane change based on environment available Lanes( Lane Matrix) 
if any,assuming independence from left 
and right probabilities. lane matrix prob .

                 @startuml
                 Partition SIT_v_DetectLaneChangeTIEnv{
                 Start
                 : number of lanes and objects are kept in left and right to maintain\n their values during lane change and thus maintain environment prob;
                 : Right lanes addition and deduction based on availability;
                 : set minimum threshold;
                 End
                 }
                 @enduml

@param          -

@return         Prob corresponding to available Lanes and/or ENV prob hysteresis
lane is available

@param[in]       -

@glob_in         -pt_SITOutput->t_LaneChangeStatic.s_NumberLanesLeft
@glob_in         pt_SITOutput->t_LaneChangeStatic.s_NumberLanesRight


@glob_out        -

@c_switch_part   -
@c_switch_full   SIT_CFG_LC_PROB_CALC
@c_switch_full   FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING

@pre             -
@post            -

@testmethod        Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

@created         -
@changed         -

@author         Ahmed Shabayek
**************************************************************************** */
static void SIT_v_DetectLaneChangeTIEnv(void)
{
  if ( pt_SITOutput->t_LaneChangePhase.t_LCPhase != LC_LANECHANGE ) 
  {
    /* number of lanes and objects are kept in global variables to maintain their values during lane change and thus maintain environment prob*/
    pt_SITOutput->t_LaneChangeStatic.s_NumberLanesLeft    = (pt_SITInput->pt_FIPLM->s_NumOfLaneLeft);
    pt_SITOutput->t_LaneChangeStatic.s_NumberLanesRight   = (pt_SITInput->pt_FIPLM->s_NumOfLaneRight);
  }

  if (pt_SITOutput->t_LaneChangeStatic.s_NumberLanesLeft > (sint8)0)
  {
    pt_SITOutput->t_LaneChangeStatic.f_LCProbTIEnvLeft += SIT_LC_VALIDLANE_ENVIPROB;
  }
  else
  {
    pt_SITOutput->t_LaneChangeStatic.f_LCProbTIEnvLeft = 0;
  }

  /*Right lanes  addition and deduction based on avalibility*/
  if (pt_SITOutput->t_LaneChangeStatic.s_NumberLanesRight > (sint8)0)
  {
    pt_SITOutput->t_LaneChangeStatic.f_LCProbTIEnvRight += SIT_LC_VALIDLANE_ENVIPROB;
  }
  else
  {
    pt_SITOutput->t_LaneChangeStatic.f_LCProbTIEnvRight = 0.f;
  }

  /*set minimum threshold*/
  if (pt_SITOutput->t_LaneChangeStatic.f_LCProbTIEnvRight <= 0.0f)
  {
    pt_SITOutput->t_LaneChangeStatic.f_LCProbTIEnvRight = SIT_LC_MIN_ENVIPROB;
  }

  if (pt_SITOutput->t_LaneChangeStatic.f_LCProbTIEnvLeft <= 0.0f)
  {
    pt_SITOutput->t_LaneChangeStatic.f_LCProbTIEnvLeft = SIT_LC_MIN_ENVIPROB;
  }
}
#endif
#endif
/* ***********************************************************************
@fn             SIT_v_GetLaneChangeTimeGap                           */ /*!

@brief          Get time gap lane change signals

@description    Returns the relevant information for time gap lane change event

                @startuml
                Partition SIT_v_SetLaneChangeTimeGap{
                Start
                : Get the turn indicator state;
                : Feed forward of the traffic orientation;
                : use the turn indicator and orientation as a trigger\n for deciding on the overtake allow flag;
                End
                }
                @enduml

@return         All relevant signals for time gap lane change event
@param[in]       -

@glob_in         -
@glob_out        -

@c_switch_part   - FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING
                 - FCT_CFG_INPUT_PREPROCESSSING
                 - SLATE_CFG_ENABLE_OVERTAKE_ASSIST
                 - SIT_LC_CFG_USE_OVERTAKE_IN_LANECHANGE
				 - FCT_SIM_EXT
@c_switch_full   -

@pre             -
@post            -

@created         -
@changed         -

@pre            SIT_v_DetectLaneChange must have been done in the current cycle
(to update internal state)

@post           -

@testmethod        Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

@traceability    192:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-192-00061542 \n
                 193:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-193-00061542 \n

@author         Christopher Knievel
**************************************************************************** */
static void SIT_v_SetLaneChangeTimeGap(void)
{
#if (SLATE_CFG_ENABLE_OVERTAKE_ASSIST) 
  eTrafficOrientation_t t_TrafficOrientation;

#if (SIT_LC_CFG_USE_OVERTAKE_IN_LANECHANGE)
#if (FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING)  /* This switch is ONLY for better readability, it has to switched ON at all times for ACC */
#if (SIT_CFG_IGNORE_LANE_VALADITY)
  sint32 s_NumberLanesLeft = (pt_SITInput->pt_FIPLM->s_NumOfLaneLeft);
  sint32 s_NumberLanesRight = (pt_SITInput->pt_FIPLM->s_NumOfLaneRight);
#endif
#endif /* (FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING) */
  /*get the turn indicator state directly from the rte input recieved by the sit*/
eTurnIndicator_t t_TurnIndicator = *pt_SITInput->t_RTE.pt_TurnIndicator;
#endif /*(SIT_LC_CFG_USE_OVERTAKE_IN_LANECHANGE)*/

  /* Set temporary default values */
  /* Feed forward of the traffic orientation. The headway control only reacts on
  a high lane change prob in combination with the correct traffic orientation.
  In case of right hand traffic, a change to from left to right lane should not
  result in a headway distance reduction. */

#if (FCT_CFG_INPUT_PREPROCESSSING)
  t_TrafficOrientation = (pt_SITInput->pt_FIPTO->t_FIPTrafficOrientation); /* Get fused traffic orientation */
#else
#if (FCT_CFG_ROAD_INPUT)  
  t_TrafficOrientation = ROAD_GET_TRAFFIC_ORIENTATION; 
#else
  t_TrafficOrientation = TRAFFICORIENTATION_UNKNOWN;
#endif /* FCT_CFG_ROAD_INPUT */
#endif /* FCT_CFG_INPUT_PREPROCESSSING */

#ifdef FCT_SIM_EXT
/* FCT_SIM_EXT To have the features (Overtake Support and Prevention) active in carmaker simulation, 
     these hacks are added along with the preprocessor directive that is only existing in the carmaker fct visual studio solution.
     The reason being that all inputs are not provided to SLATE in the carmaker environment. */
  t_TrafficOrientation = LC_TRAFFIC_ORIENT_RIGHT;
#if (FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING)
#if (SIT_CFG_IGNORE_LANE_VALADITY)
  s_NumberLanesLeft = (sint32)1;
  s_NumberLanesRight = (sint32)1;
#endif
#endif
#endif /* END IF FCT_SIM_EXT */

  switch (t_TrafficOrientation)
  {
  case GDB_TRAFFICORIENTATION_RIGHT_HAND:
    pt_SITOutput->t_LaneChangePhase.t_LCTrafficOrientation = LC_TRAFFIC_ORIENT_RIGHT;
    break;
  case GDB_TRAFFICORIENTATION_LEFT_HAND:
    pt_SITOutput->t_LaneChangePhase.t_LCTrafficOrientation = LC_TRAFFIC_ORIENT_LEFT;
    break;
  case TRAFFICORIENTATION_UNKNOWN:
  default:
    pt_SITOutput->t_LaneChangePhase.t_LCTrafficOrientation = LC_TRAFFIC_ORIENT_UNKNOWN;
    break;
  }

#if (SIT_LC_CFG_USE_OVERTAKE_IN_LANECHANGE)
  if((pt_SITOutput->t_LaneChangePhase.t_LCTrafficOrientation == LC_TRAFFIC_ORIENT_LEFT)
      && (t_TurnIndicator == eTurnIndicator_Right)
      /*use the turn indicator and orientation as a trigger for deciding on the overtake allow flag*/
#if (FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING)
#if (SIT_CFG_IGNORE_LANE_VALADITY)
      && (s_NumberLanesRight > (sint8)0)
#endif
#endif /* FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING */
    )
    {
      pt_SITOutput->t_LaneChangePhase.t_AllowOvertake = LC_ALLOW_OVERTAKE_RIGHT;
    }
    else if ((pt_SITOutput->t_LaneChangePhase.t_LCTrafficOrientation == LC_TRAFFIC_ORIENT_RIGHT)
      && (t_TurnIndicator== eTurnIndicator_Left)
#if (FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING)
#if (SIT_CFG_IGNORE_LANE_VALADITY)
      && (s_NumberLanesLeft > (sint8)0)
#endif
#endif /* FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING */
     )
    {
      pt_SITOutput->t_LaneChangePhase.t_AllowOvertake = LC_ALLOW_OVERTAKE_LEFT;
    }
    else
    {
      pt_SITOutput->t_LaneChangePhase.t_AllowOvertake = LC_ALLOW_NO_OVERTAKE;
    }
#endif /*(SIT_LC_CFG_USE_OVERTAKE_IN_LANECHANGE)*/

#else
  pt_SITOutput->t_LaneChangePhase.t_LCTrafficOrientation = LC_TRAFFIC_ORIENT_UNKNOWN;
#endif  /*  SLATE_CFG_ENABLE_OVERTAKE_ASSIST */
}

#if (SIT_LC_USE_FILTER_PEAK_PROB)
/* ***********************************************************************
@fn             SIT_v_FilterPeakProb                           */ /*!

@brief          Pass down final fused prob ( naive bayes) and state coming out of camera and radar 

@description   filter prob peaks based on how consistent the value is , this is done by adding to
the hysteresis which is then used to decide the state later on.

                @startuml
                Partition SIT_v_FilterPeakProb{
                Start
                If (Left probability is high) then (TRUE)
                : add time to hysteresis based on cycle time;
                Elseif (probability is not threshold high) then (TRUE)
                : hysteresis is decreased;
                Else (FALSE)
                : Do nothing;
                Endif
                If (Right probability is high) then (TRUE)
                : add time to hysteresis based on cycle time;
                Else (FALSE)
                : Do nothing;
                Endif
                End
                }
                @enduml

@return         Final lane change prob and state

@param[in]       -

@glob_in         -pt_SITOutput->t_LaneChangeStatic.f_LCFilterHysteresisLeft
@glob_in          pt_SITOutput->t_LaneChangeStatic.f_LCFilterHysteresisRight
@glob_in          SITLCProbDataGlobal.f_LCProbRight
@glob_in          SITLCProbDataGlobal.f_LCProbLeft

@glob_out        -pt_SITOutput->t_LaneChangeStatic.f_LCFilterHysteresisLeft
@glob_out        -pt_SITOutput->t_LaneChangeStatic.f_LCFilterHysteresisRight

@c_switch_part   -
@c_switch_full   -

@pre             -
@post            -

@testmethod        Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).


@pre            SIT_v_DetectLaneChange must have been done in the current cycle
(to update internal state)

@post           -

@author         Ahmed Shabayek
**************************************************************************** */
static void SIT_v_FilterPeakProb(void)
{ 

  /* for left side check if probability is high enough ( lane change threshold high)to increase hysteresis value */
  if ( SITLCProbDataGlobal.f_LCProbLeft > SIT_LC_PROB_LEFT_THRESHOLD )
  {
    if (pt_SITOutput->t_LaneChangeStatic.f_LCFilterHysteresisLeft < SIT_LC_PULSE_TIME_FILTER)
    {
      /* add time to hysteresis based on the software running cycle time */
      pt_SITOutput->t_LaneChangeStatic.f_LCFilterHysteresisLeft += SLATE_f_GetCycleTime();
      if (pt_SITOutput->t_LaneChangeStatic.f_LCFilterHysteresisLeft > SIT_LC_PULSE_TIME_FILTER)
      {
        /* check added to prevent hysteresis going out of calculated range*/
        pt_SITOutput->t_LaneChangeStatic.f_LCFilterHysteresisLeft = SIT_LC_PULSE_TIME_FILTER;
      }
    }
  }
  /* if probability is not threshold high hysteresis is decreased*/
  else if (pt_SITOutput->t_LaneChangeStatic.f_LCFilterHysteresisLeft > 0.f)
  {
    pt_SITOutput->t_LaneChangeStatic.f_LCFilterHysteresisLeft -= SLATE_f_GetCycleTime();
    if (pt_SITOutput->t_LaneChangeStatic.f_LCFilterHysteresisLeft < 0.f)
    {
      /* check added to prevent hysteresis going out of calculated range*/
      pt_SITOutput->t_LaneChangeStatic.f_LCFilterHysteresisLeft = 0.f;
    }
  }
  else
  {
    /* do nothing QAC else*/
  }

  /* for right side check if probability is high enough ( lane change threshold high)to increase hysteresis value */
  if (SITLCProbDataGlobal.f_LCProbRight > SIT_LC_PROB_RIGHT_THRESHOLD)
  {
    if (pt_SITOutput->t_LaneChangeStatic.f_LCFilterHysteresisRight < SIT_LC_PULSE_TIME_FILTER )
    {
      /* add time to hysteresis based on the software running cycle time */
      pt_SITOutput->t_LaneChangeStatic.f_LCFilterHysteresisRight += SLATE_f_GetCycleTime();
      if (pt_SITOutput->t_LaneChangeStatic.f_LCFilterHysteresisRight > SIT_LC_PULSE_TIME_FILTER )
      {
        /* check added to prevent hysteresis going out of calculated range*/
        pt_SITOutput->t_LaneChangeStatic.f_LCFilterHysteresisRight = SIT_LC_PULSE_TIME_FILTER; 
      }
    }
  }
  else if (pt_SITOutput->t_LaneChangeStatic.f_LCFilterHysteresisRight > 0.f)
  {
    pt_SITOutput->t_LaneChangeStatic.f_LCFilterHysteresisRight -= SLATE_f_GetCycleTime();
    if (pt_SITOutput->t_LaneChangeStatic.f_LCFilterHysteresisRight < 0.f )
    {
      /* check added to prevent hysteresis going out of calculated range*/
      pt_SITOutput->t_LaneChangeStatic.f_LCFilterHysteresisRight = 0.f;
    }
  }
  else
  {
    /*Do nothing QAC else*/
  }
}
#endif
#if (SIT_CFG_LC_USE_TURN_INDICATOR_INPUT) 
/* ***********************************************************************
@fn             SIT_v_SetTurnIndicatorProb                           */ /*!

@brief          Turn indicator prob based  on hysteresis range [0.7 - 1.0]

@description    returns turn indicator prob based on hysteresis with prob interpolation between 0.7 and 1.0

                @startuml
                Partition SIT_v_SetTurnIndicatorProb{
                Start
                : assign prob based of hysteresis timer and the\n predefined min and max turn indicator prob;
                End
                }
                @enduml

@return         f_LeftTurnIndProb, f_RightTurnIndProb

@param[in]       - pointer to f_LeftTurnIndProb 
@param[in]        -pointer to f_RightTurnIndProb

@glob_in         -pt_SITOutput->t_LaneChangeStatic.f_TimeFiltTurnIndLeft
@glob_in         -pt_SITOutput->t_LaneChangeStatic.f_TimeFiltTurnIndRight
@glob_out        -

@c_switch_part   -
@c_switch_full   -

@pre             -
@post            -


@pre            SIT_v_DetectLaneChange must have been done in the current cycle
(to update internal state)

@post           -

@testmethod        Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

@author         Ahmed Shabayek
**************************************************************************** */
static void SIT_v_SetTurnIndicatorProb(float32 * const f_LeftTurnIndProb ,float32 * const f_RightTurnIndProb)
{
  /* output = ((input - inputmin) * ( (outputmax - outputstart ) / ( inputmax - inputmin ) ) ) + outputmin */
  /*assign prob based of hysteresis timer and the predefined min and max turn indicator prob*/
  *f_LeftTurnIndProb = dGDBmathLineareFunktion(&SIT_LC_TURNIND_PROB,pt_SITOutput->t_LaneChangeStatic.f_TimeFiltTurnIndLeft);
  *f_RightTurnIndProb = dGDBmathLineareFunktion(&SIT_LC_TURNIND_PROB,pt_SITOutput->t_LaneChangeStatic.f_TimeFiltTurnIndRight);
}
#endif
/* ***********************************************************************
@fn             SIT_v_LaneChangeProbFusion                           */ /*!

@brief          Pass down final fused prob ( naive bayes) and state coming out of camera and radar 

@description    Fuses different input probabilities and output the semi-final prob before determining
                the state and applying the peak filter for final probability output 

                 @startuml
                 Partition SIT_v_LaneChangeProbFusion{
                 Start
                 : probabilities are assigned to their relevant side for\n later fusion of all left and right probabilities;
                 : fusion is done by having probabilities multiplied (chain rule)\n with each of their respective weights as a power factor;
                 : left, right prob assigning end;
                 End
                 }
                 @enduml

@return         Final lane change prob and state

@param[in]       -

@glob_in         -pt_SITOutput->t_LaneChangeStatic.f_LCProbTIEnvLeft
@glob_in         -pt_SITOutput->t_LaneChangeStatic.f_LCProbMultiobjectLeft
@glob_in         -pt_SITOutput->t_LaneChangeStatic.f_LCProbLeftAverage
@glob_in         -pt_SITOutput->s_LCProbLeft
@glob_in         -pt_SITOutput->t_LaneChangeStatic.f_LCProbTIEnvRight
@glob_in         -pt_SITOutput->t_LaneChangeStatic.f_LCProbMultiobjectRight
@glob_in         -pt_SITOutput->t_LaneChangeStatic.f_LCProbRightAverage
@glob_in         -pt_SITOutput->s_LCProbRight
@glob_in         -

@glob_out        -SITLCProbDataGlobal.f_LCProbLeft
@glob_out        -SITLCProbDataGlobal.f_LCProbRight

@c_switch_part   -
@c_switch_full   -

@pre             -
@post            -


@pre            SIT_v_DetectLaneChange must have been done in the current cycle
(to update internal state)

@post           -

@testmethod        Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

@author         Ahmed Shabayek
**************************************************************************** */
static void SIT_v_LaneChangeProbFusion(void)
{
  float32  f_LeftTurnIndProb;// PRQA S 3203
  /* date: 2017-11-15, reviewer: Shruthi Ramaiah, reason: Redundant, but may be used in future*/
  float32  f_RightTurnIndProb;// PRQA S 3203
  /* date: 2017-11-15, reviewer: Shruthi Ramaiah, reason: Redundant, but may be used in future*/
  float32  f_kinematic_weight;
#if (SIT_LC_CFG_USE_CAMERA)
  float32  f_camera_weight;
  float32  f_camera_left = 0.0f;
  float32  f_camera_right = 0.0f;
#endif

  f_LeftTurnIndProb = 0.0f ;// PRQA S 3199
  /* date: 2017-11-15, reviewer: Shruthi Ramaiah, reason: Redundant, but may be used in future*/	
  f_RightTurnIndProb = 0.0f;// PRQA S 3199
  /* date: 2017-11-15, reviewer: Shruthi Ramaiah, reason: Redundant, but may be used in future*/	
  if (pt_SITOutput->t_LaneChangePhase.t_LCPhase != LC_PRELANECHANGE)
  {
#if SIT_LC_CFG_USE_CAMERA
    f_camera_weight = SIT_LC_CFG_USE_CAMERAFUSION_WEIGHT;
#endif
    f_kinematic_weight = SIT_LC_KINEMATICFUSION_WEIGHT;
  }
  else
  {
#if SIT_LC_CFG_USE_CAMERA
    f_camera_weight = SIT_LC_CFG_USE_CAMERAFUSION_WEIGHT - SIT_LC_FUSIONWEIGHT_ADJUSTMENT;
#endif
    f_kinematic_weight = SIT_LC_KINEMATICFUSION_WEIGHT   + SIT_LC_FUSIONWEIGHT_ADJUSTMENT;
  }

#if (SIT_LC_CFG_USE_CAMERA) 
  /* probabilities are  assigned to their relevant side for later fusion of all left and right probabilities this is temporary till both left  & right probabilties are passed down */
  f_camera_left = ((float32)pt_SITOutput->s_LCProbLeft)/(float32)SIT_LC_PROBTOPRECENTAGE;
  f_camera_right = ((float32)pt_SITOutput->s_LCProbRight)/(float32)SIT_LC_PROBTOPRECENTAGE;
#endif /* END IF LC Camera*/

  /*fusion is done by having probabilities multiplied (chain rule)  with each of their respective weights as a power factor*/
#if (SIT_CFG_LC_USE_TURN_INDICATOR_INPUT) 
  SIT_v_SetTurnIndicatorProb( &f_LeftTurnIndProb , &f_RightTurnIndProb);
#endif  /*  (SIT_CFG_LC_USE_TURN_INDICATOR_INPUT) */

  /* left, right prob assigning end*/
  SITLCProbDataGlobal.f_LCProbLeft = CML_f_XPowY(pt_SITOutput->t_LaneChangeStatic.f_LCProbLeftAverage , f_kinematic_weight);

#if (SIT_LC_CFG_LANEMATRIX_FUSION)
  SITLCProbDataGlobal.f_LCProbLeft *= CML_f_XPowY(pt_SITOutput->t_LaneChangeStatic.f_LCProbTIEnvLeft , SIT_LC_ENVIROMENTFUSION_WEIGHT);
#endif /* END IF LC Environment*/

#if (SIT_LC_CFG_ENABLE_MULTIOBJECTFUSION)
  SITLCProbDataGlobal.f_LCProbLeft *= CML_f_XPowY(pt_SITOutput->t_LaneChangeStatic.f_LCProbMultiobjectLeft , SIT_LC_MULTIOBJFUSION_WEIGHT);
#endif /* END IF LC Multi object*/

#if (SIT_LC_CFG_USE_CAMERA)
  SITLCProbDataGlobal.f_LCProbLeft *= CML_f_XPowY(f_camera_left , f_camera_weight);
#endif /* END IF LC Camera*/

  SITLCProbDataGlobal.f_LCProbRight = CML_f_XPowY(pt_SITOutput->t_LaneChangeStatic.f_LCProbRightAverage ,f_kinematic_weight);

#if (SIT_LC_CFG_LANEMATRIX_FUSION)
  SITLCProbDataGlobal.f_LCProbRight *= CML_f_XPowY(pt_SITOutput->t_LaneChangeStatic.f_LCProbTIEnvRight , SIT_LC_ENVIROMENTFUSION_WEIGHT);
#endif /* END IF LC Environment*/

#if (SIT_LC_CFG_ENABLE_MULTIOBJECTFUSION)
  SITLCProbDataGlobal.f_LCProbRight *= CML_f_XPowY(pt_SITOutput->t_LaneChangeStatic.f_LCProbMultiobjectRight , SIT_LC_MULTIOBJFUSION_WEIGHT);
#endif /* END IF LC Multi object*/

#if (SIT_LC_CFG_USE_CAMERA)
  SITLCProbDataGlobal.f_LCProbRight *= CML_f_XPowY(f_camera_right , f_camera_weight);
#endif /* END IF LC Camera*/
}

/* ***********************************************************************
@fn              SIT_v_DetermineLaneChangeState                           */ /*!

@brief           Pass down final fused prob ( naive bayes) and state coming out of camera and radar 

@description     uses fused prob to determine lanechange state for a final output prob

                  @startuml
                  Partition SIT_v_DetermineLaneChangeState{
                  Start
                  : if above low threshold then its a valid prob to one side or the other;
                  End
                  }
                  @enduml

@return          Final lane change prob and state

@param[in]       -

@glob_in         - SITLCProbDataGlobal.f_LCProbRight
@glob_in         - SITLCProbDataGlobal.f_LCProbLeft
@glob_in         - pt_SITOutput->t_LaneChangeStatic.t_PreviousState
@glob_out        -

@c_switch_part   -
@c_switch_full   SIT_LC_CFG_USE_TURNIND_CAMERA_PROB : Configuration switch to enable lane change probability calculation using turn indicator input and camera lane input

@pre             -
@post            -

@pre             SIT_v_DetectLaneChange must have been done in the current cycle (to update internal state)

@post           -

@testmethod        Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

@author         Ahmed Shabayek
**************************************************************************** */
static void SIT_v_DetermineLaneChangeState(void)
{
  /* Left lane change probability in terms of percentage */
  float32 f_LCProbabilityLeft = (SITLCProbDataGlobal.f_LCProbLeft * SIT_LC_PROBTOPRECENTAGE);
  /* Right lane change probability in terms of percentage */
  float32 f_LCProbabilityRight = (SITLCProbDataGlobal.f_LCProbRight * SIT_LC_PROBTOPRECENTAGE);

  /*if above low threshold then its a valid prob to one side or the other*/
  if ( (SITLCProbDataGlobal.f_LCProbRight > SIT_LC_PROB_RIGHT_LOWTHRESHOLD )
    || (SITLCProbDataGlobal.f_LCProbLeft > SIT_LC_PROB_LEFT_LOWTHRESHOLD )
    || (pt_SITOutput->t_LaneChangePhase.t_LCPhase == LC_LANECHANGE )
     )
  {
    if (  (SITLCProbDataGlobal.f_LCProbRight > SITLCProbDataGlobal.f_LCProbLeft )
#if (SIT_LC_CFG_USE_TURNIND_CAMERA_PROB) /* Remain in LCState Right if the previous state is right and probability of right and left becomes equal */
       || (  (pt_SITOutput->t_LaneChangeStatic.t_PreviousState == LC_RIGHT)
          && ((uint8)f_LCProbabilityRight == (uint8)f_LCProbabilityLeft)
          )
#endif /*!< SIT_LC_CFG_USE_TURNIND_CAMERA_PROB */
     )
    {
      pt_SITOutput->t_LaneChangePhase.u_LCPhaseProb = (uint8)f_LCProbabilityRight;
      pt_SITOutput->s_LCProb = (sint16)pt_SITOutput->t_LaneChangePhase.u_LCPhaseProb;
      pt_SITOutput->t_LaneChangePhase.t_LCPhaseState = LC_RIGHT;
    }
#if (SIT_LC_CFG_USE_TURNIND_CAMERA_PROB)
    /* Remain in LCState Left if the previous state is left and probability of right and left becomes equal */
    else if (  (SITLCProbDataGlobal.f_LCProbRight < SITLCProbDataGlobal.f_LCProbLeft )
            || (  (pt_SITOutput->t_LaneChangeStatic.t_PreviousState == LC_LEFT)
               && ((uint8)f_LCProbabilityLeft == (uint8)f_LCProbabilityRight)
               )
    )
#else
    else
#endif /*!< SIT_LC_CFG_USE_TURNIND_CAMERA_PROB */
    {
      pt_SITOutput->t_LaneChangePhase.u_LCPhaseProb = (uint8)f_LCProbabilityLeft;
      pt_SITOutput->s_LCProb = (sint16)pt_SITOutput->t_LaneChangePhase.u_LCPhaseProb;
      pt_SITOutput->t_LaneChangePhase.t_LCPhaseState = LC_LEFT;
    }
#if (SIT_LC_CFG_USE_TURNIND_CAMERA_PROB)
    else
    {
      /* Do nothing */
    }
#endif /*!< SIT_LC_CFG_USE_TURNIND_CAMERA_PROB */
  }
  /* in case of low probability treat as LC_FOLLOW unless in the midst of a lanechange state until LC phase time tolerance is done ,
  meanwhile maintain previous state*/
  else 
  {
    if (pt_SITOutput->t_LaneChangePhase.t_LCPhase != LC_LANECHANGE)
    {
      pt_SITOutput->t_LaneChangePhase.t_LCPhaseState = LC_FOLLOW;
    }
    if ( SITLCProbDataGlobal.f_LCProbRight > SITLCProbDataGlobal.f_LCProbLeft)
    {
      pt_SITOutput->t_LaneChangePhase.u_LCPhaseProb = (uint8)f_LCProbabilityRight;
      pt_SITOutput->s_LCProb = (sint16)pt_SITOutput->t_LaneChangePhase.u_LCPhaseProb;
    }
    else
    {
      pt_SITOutput->t_LaneChangePhase.u_LCPhaseProb = (uint8)f_LCProbabilityLeft;
      pt_SITOutput->s_LCProb = (sint16)pt_SITOutput->t_LaneChangePhase.u_LCPhaseProb;
    }
  }
}

/* ***********************************************************************
@fn              SIT_v_NoLaneChangeState                           */ /*!

@brief           no lane change phase state logic

@description     carries out transitions possible from no lane change phase and sets the new phase accordingly

                 @startuml
                 Partition SIT_v_NoLaneChangeState{
                 Start
                 : check if there is high kinematic prob in either direction\n then switch directly to lane change state;
                 : if there is a kinematic potential or valid environment\n prob then Prelane change is set;
                 End
                 }
                 @enduml

@return           

@param[in]       -b_PreLaneChange flag for transitioning to prelanechange 

@glob_in         -
@glob_out        -

@c_switch_part   -
@c_switch_full   -

@pre             -
@post            -


@pre            SIT_v_DetectLaneChange must have been done in the current cycle (to update internal state)

@post           -

@testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                 Test order of calls (dynamic module test). \n
                 Test of code coverage (dynamic module test). \n  
                 Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                 Test of run time error/warnings (Static code analysis).

@author         Ahmed Shabayek
**************************************************************************** */
#if (SIT_LC_CFG_ENABLE_MULTIOBJFUSION)
static void SIT_v_NoLaneChangeState(boolean b_PreLaneChange)
#else
static void SIT_v_NoLaneChangeState(void)
#endif
{
  /*check if there is high kinematic prob in either direction then switch directly to lane change state*/
  if ( pt_SITOutput->t_LaneChangePhase.u_LCPhaseProb > SIT_LC_PROB_THRESHOLD )/* LC_release*/
  {
    pt_SITOutput->t_LaneChangePhase.t_LCPhase = LC_LANECHANGE;
  }
  /*if there is a kinematic potential or valid environment prob then Prelane change is set*/
  /*high prob but low kinematic prob, with valid environment prob  */ 
#if (SIT_LC_CFG_ENABLE_MULTIOBJFUSION || SIT_CFG_LC_USE_TURN_INDICATOR_INPUT)
  else if (
#if (SIT_LC_CFG_ENABLE_MULTIOBJFUSION)
#if (SIT_CFG_LC_USE_TURN_INDICATOR_INPUT)
            (b_PreLaneChange == TRUE) ||
#else
            (b_PreLaneChange == TRUE)
#endif
#endif
#if (SIT_CFG_LC_USE_TURN_INDICATOR_INPUT)
            (pt_SITOutput->t_LaneChangeStatic.f_TimeFiltTurnIndRight > 0.0f)
         || (pt_SITOutput->t_LaneChangeStatic.f_TimeFiltTurnIndLeft > 0.0f )
#endif
          )
  {
    pt_SITOutput->t_LaneChangePhase.t_LCPhase = LC_PRELANECHANGE;
  }
#endif
  else /*no lane change*/
  {
    pt_SITOutput->t_LaneChangePhase.t_LCPhase = LC_NO_LANECHANGE;
  
  }

}
/* ***********************************************************************
@fn              SIT_v_PreLaneChangeState                           */ /*!

@brief           pre lane change phase state logic

@description     carries out transitions possible from pre lane change phase and sets the new phase accordingly

                 @startuml
                 Partition SIT_v_PreLaneChangeState{
                 Start
                 : high enough kinematic or high lane change prob;
                 : turn indicator check and prelane change from multiobject observer;
                 End
                 }
                 @enduml

@return          

@param[in]       -

@glob_in         -SITLCProbDataGlobal.fLCProbLef
@glob_in         -SITLCProbDataGlobal.f_LCProbRight
@glob_in          pt_SITOutput->t_LaneChangeStatic.f_TimeFiltTurnIndRight
@glob_in          pt_SITOutput->t_LaneChangeStatic.f_TimeFiltTurnIndLeft

@glob_out        -pt_SITOutput->t_LaneChangePhase.t_LCPhase

@c_switch_part   -
@c_switch_full   -

@pre             - 
@post            -


@pre            SIT_v_DetectLaneChange must have been done in the current cycle (to update internal state)

@post           -

@testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                 Test order of calls (dynamic module test). \n
                 Test of code coverage (dynamic module test). \n  
                 Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                 Test of run time error/warnings (Static code analysis).

@author         Ahmed Shabayek
**************************************************************************** */
#if (SIT_LC_CFG_ENABLE_MULTIOBJFUSION)
static void SIT_v_PreLaneChangeState(boolean b_PreLaneChange)
#else
static void SIT_v_PreLaneChangeState(void)
#endif
{
  /*high enough kinematic or high lane change prob*/
  if ( (SITLCProbDataGlobal.f_LCProbLeft > SIT_LC_PROB_LEFT_THRESHOLD_KIN)
    || (SITLCProbDataGlobal.f_LCProbRight > SIT_LC_PROB_LEFT_THRESHOLD_KIN)
    || (pt_SITOutput->t_LaneChangePhase.u_LCPhaseProb > SIT_LC_PROB_THRESHOLD)
     )
  {
    pt_SITOutput->t_LaneChangePhase.t_LCPhase = LC_LANECHANGE;
  }
  /* turn indicator check and prelanechange from multiobject observer*/
#if (SIT_LC_CFG_ENABLE_MULTIOBJFUSION || SIT_CFG_LC_USE_TURN_INDICATOR_INPUT)
  else if (
#if (SIT_LC_CFG_ENABLE_MULTIOBJFUSION)
#if (SIT_CFG_LC_USE_TURN_INDICATOR_INPUT)
            (b_PreLaneChange == TRUE) ||
#else
            (b_PreLaneChange == TRUE)
#endif
#endif
#if (SIT_CFG_LC_USE_TURN_INDICATOR_INPUT)
            (pt_SITOutput->t_LaneChangeStatic.f_TimeFiltTurnIndRight > 0.0f)
         || (pt_SITOutput->t_LaneChangeStatic.f_TimeFiltTurnIndLeft > 0.0f )
#endif
          )
  {
    pt_SITOutput->t_LaneChangePhase.t_LCPhase = LC_PRELANECHANGE;
  }
#endif
  else /* no lane change */
  {
    pt_SITOutput->t_LaneChangePhase.t_LCPhase = LC_NO_LANECHANGE;
  }
}

/************************************************************************
@fn             SIT_v_LaneChangeState                           */ /*!

@brief          Function for lane change phase transition from previous cycle

@description    Based on outputs of fusion and state this function decided the next phase transition taking a state hysteresis into account
                as well as previous  state so that it may decide on a steer back should it happen

                 @startuml
                 Partition SIT_v_LaneChangeState{
                 Start
                 : High prob indicating lane change or steer back due to high kinematic input;
                 If (state is different than previous cycle while having high prob) then (TRUE)
                 : before transitioning to steerback make sure that LC expiring conditions\n (detection of opposing probabilty) is not a spike or impluse but rather the current state;
                 Else (FALSE)
                 : High kinematic prob a) with same previous state or\nb) No hysteresis active then maintain lane change state and\n increase hysteresis count;
                 Endif
                 End
                 }
                 @enduml

@return         lane change State transitions and hysteresis
@param[in]      f_StateHysteresis : State hysteresis based on factor of ego speed [full range float32]

@glob_in         -pt_SITOutput->t_LaneChangePhase.u_LCPhaseProb                                                         [0u    100u]
@glob_in         -pt_SITOutput->t_LaneChangePhase.t_LCPhase                                                             [SIT_LC_t_LaneChangePhaseEnum as defined in slate_types.h]
@glob_in         -pt_SITOutput->t_LaneChangePhase.t_LCPhaseState                                                        [SIT_LC_t_LaneChangeState as defined in slate_types.h]
@glob_in         -pt_SITOutput->t_LaneChangeStatic.f_LCStateHysteresisLeft                                              [full range float32]
@glob_in         -pt_SITOutput->t_LaneChangeStatic.f_LCStateHysteresisRight                                             [full range float32]
@glob_in         -pt_SITOutput->t_LaneChangeStatic.f_LCCamLMHysteresisLeft                                              [full range float32]
@glob_in         -pt_SITOutput->t_LaneChangeStatic.f_LCCamLMHysteresiRight                                              [full range float32]
@glob_out        -pt_SITOutput->t_LaneChangePhase.t_LCPhase                                                             [SIT_LC_t_LaneChangePhaseEnum as defined in slate_types.h]
@glob_out        -pt_SITOutput->t_LaneChangeStatic.f_LCSteerbackTimer                                                   [full range float32]
@glob_out         SITLCProbDataGlobal.CamLaneMarkerCrossedProbLeft : Left Camera lane marker crossed probability        [0u  100u]
@glob_out         SITLCProbDataGlobal.CamLaneMarkerCrossedProbRight : Right Camera lane marker crossed probability      [0u  100u]

@c_switch_part   -
@c_switch_full    SIT_LC_CFG_USE_TURNIND_CAMERA_PROB : Configuration switch to enable lane change probability calculation using turn indicator input and camera lane input

@pre             -
@post            -


@pre            SIT_v_DetectLaneChange must have been done in the current cycle (to update internal state)

@post           -

@testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                 Test order of calls (dynamic module test). \n
                 Test of code coverage (dynamic module test). \n  
                 Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                 Test of run time error/warnings (Static code analysis).

@author         Ahmed Shabayek
**************************************************************************** */
static void SIT_v_LaneChangeState( float32 f_StateHysteresis )
{
  boolean b_stateTransitionleft = FALSE;
  boolean b_stateTransitionright = FALSE;
#if ((SIT_LC_CFG_USE_TURNIND_CAMERA_PROB) && (FCT_CFG_INPUT_PREPROCESSSING) && (SLATE_CFG_CAM_LANE_INTERFACE))
  /* Lane change phase is set to Steerback if 
     Camera lane info is valid
     Camera lane marker is crossed
     Distance to left/right Lane marker is within the defined range */
  if (  (pt_SITInput->pt_FIPCamLane->f_VisibilityDist > SIT_LC_PROB_MIN_CAM_DIST)
     && (pt_SITOutput->t_LaneChangePhase.u_LCPhaseProb >= SIT_LC_PROB_MIN_THRESHOLD)
     )
  {
    if (pt_SITOutput->t_LaneChangePhase.t_LCPhaseState == LC_LEFT)
    {
      if (SITLCProbDataGlobal.CamLaneMarkerCrossedProbLeft != SIT_LC_MAX_PROB)
      {
        pt_SITOutput->t_LaneChangePhase.t_LCPhase = LC_LANECHANGE;

        if (pt_SITOutput->t_LaneChangeStatic.f_LCCamLMHysteresisLeft >= SIT_LC_HYSTERESIS_STEERBACK_TIME)
        {
          pt_SITOutput->t_LaneChangeStatic.f_LCCamLMHysteresisLeft += SIT_LC_HYSTERESIS_TIME;
        }
      }
      else
      {
        pt_SITOutput->t_LaneChangeStatic.f_LCCamLMHysteresisLeft = SIT_LC_HYSTERESIS_STEERBACK_TIME;
      }

      if (  (pt_SITInput->t_RTE.pt_CamLaneData->LaneMarkerInfo[FIP_CL_MK_RIGHT].f_MarkerDist < -SIT_LC_CAM_LM_MIN_DIST)
         && (pt_SITInput->t_RTE.pt_CamLaneData->LaneMarkerInfo[FIP_CL_MK_RIGHT].f_MarkerDist > -SIT_LC_CAM_LM_MAX_DIST)
         && (pt_SITOutput->t_LaneChangeStatic.f_LCCamLMHysteresisLeft > SIT_LC_HYSTERESIS_STEERBACK_TIME)
         )
      {
        pt_SITOutput->t_LaneChangePhase.t_LCPhase = LC_STEERBACK;
        pt_SITOutput->t_LaneChangeStatic.f_LCSteerbackTimer = SIT_LC_STEERBACK_TIME;
      }
    }
    else if (pt_SITOutput->t_LaneChangePhase.t_LCPhaseState == LC_RIGHT)
    {
      if (SITLCProbDataGlobal.CamLaneMarkerCrossedProbRight != SIT_LC_MAX_PROB)
      {
        pt_SITOutput->t_LaneChangePhase.t_LCPhase = LC_LANECHANGE;

        if (pt_SITOutput->t_LaneChangeStatic.f_LCCamLMHysteresiRight >= SIT_LC_HYSTERESIS_STEERBACK_TIME)
        {
          pt_SITOutput->t_LaneChangeStatic.f_LCCamLMHysteresiRight += SIT_LC_HYSTERESIS_TIME;
        }
      }
      else
      {
        pt_SITOutput->t_LaneChangeStatic.f_LCCamLMHysteresiRight = SIT_LC_HYSTERESIS_STEERBACK_TIME;
      }

      if (  (pt_SITInput->t_RTE.pt_CamLaneData->LaneMarkerInfo[FIP_CL_MK_LEFT].f_MarkerDist > SIT_LC_CAM_LM_MIN_DIST)
         && (pt_SITInput->t_RTE.pt_CamLaneData->LaneMarkerInfo[FIP_CL_MK_LEFT].f_MarkerDist < SIT_LC_CAM_LM_MAX_DIST)
         && (pt_SITOutput->t_LaneChangeStatic.f_LCCamLMHysteresiRight > SIT_LC_HYSTERESIS_STEERBACK_TIME)
         )
      {
        pt_SITOutput->t_LaneChangePhase.t_LCPhase = LC_STEERBACK;
        pt_SITOutput->t_LaneChangeStatic.f_LCSteerbackTimer = SIT_LC_STEERBACK_TIME;
      }
    }
    else
    {
      /* Do nothing */
    }
  }
#endif /*! (SIT_LC_CFG_USE_TURNIND_CAMERA_PROB) && (FCT_CFG_INPUT_PREPROCESSSING) && (SLATE_CFG_CAM_LANE_INTERFACE) */
  /* High prob indicating lane change or steer back due to high kinematic input*/
#if ((SIT_LC_CFG_USE_TURNIND_CAMERA_PROB) && (FCT_CFG_INPUT_PREPROCESSSING) && (SLATE_CFG_CAM_LANE_INTERFACE))
  else if ( pt_SITOutput->t_LaneChangePhase.u_LCPhaseProb > SIT_LC_PROB_THRESHOLD )
#else
  if ( pt_SITOutput->t_LaneChangePhase.u_LCPhaseProb > SIT_LC_PROB_THRESHOLD )
#endif /*! (SIT_LC_CFG_USE_TURNIND_CAMERA_PROB) && (FCT_CFG_INPUT_PREPROCESSSING) && (SLATE_CFG_CAM_LANE_INTERFACE) */
  {
    /* Case for steerback */
    /*
    During high LC probability or the the tolerance after probability drop if a high probability is detected 
    in opposite direction then its counted as a steer back state , and outputted as such
    */
         /* Check if 
      a) state is different than previous cycle while having high prob, */
    if ( ( (pt_SITOutput->t_LaneChangeStatic.t_PreviousState != pt_SITOutput->t_LaneChangePhase.t_LCPhaseState) 
        && (pt_SITOutput->t_LaneChangePhase.t_LCPhaseState != LC_FOLLOW)
         )
      || ( ( ( pt_SITOutput->t_LaneChangeStatic.f_LCProbLeftAverage > SIT_LC_STEERBACK_KINEMATIC_THRESH ) 
          && (pt_SITOutput->t_LaneChangeStatic.t_PreviousState == LC_RIGHT) 
           )
        || ( ( pt_SITOutput->t_LaneChangeStatic.f_LCProbRightAverage > SIT_LC_STEERBACK_KINEMATIC_THRESH ) 
          && (pt_SITOutput->t_LaneChangeStatic.t_PreviousState == LC_LEFT)
           )
         )
       )
    {
     /*  b) before transitioning to steerback make sure that LC expiring 
      conditions(detection of opposing probabilty) is not a spike or impluse but rather
      the current state.*/
      b_stateTransitionright = ( (pt_SITOutput->t_LaneChangeStatic.f_LCStateHysteresisRight - f_StateHysteresis ) > SIT_LC_TO_STEERBACK_MIN_TIME) ? TRUE:FALSE;
      b_stateTransitionleft = ( (pt_SITOutput->t_LaneChangeStatic.f_LCStateHysteresisLeft - f_StateHysteresis ) > SIT_LC_TO_STEERBACK_MIN_TIME) ? TRUE:FALSE;

      if ( ( ( b_stateTransitionright == TRUE)
          && (pt_SITOutput->t_LaneChangeStatic.t_PreviousState == LC_RIGHT)
           )
        || ( ( b_stateTransitionleft == TRUE)
          && (pt_SITOutput->t_LaneChangeStatic.t_PreviousState == LC_LEFT)
           )
         )
      {
        pt_SITOutput->t_LaneChangePhase.t_LCPhase = LC_STEERBACK;
        pt_SITOutput->t_LaneChangeStatic.f_LCStateHysteresisRight = SIT_LC_HYSTERESIS_STEERBACK_TIME;
        pt_SITOutput->t_LaneChangeStatic.f_LCStateHysteresisLeft = SIT_LC_HYSTERESIS_STEERBACK_TIME;
#if (SIT_LC_CFG_USE_TURNIND_CAMERA_PROB)
        pt_SITOutput->t_LaneChangeStatic.f_LCSteerbackTimer = SIT_LC_STEERBACK_TIME;
#endif /*!< SIT_LC_CFG_USE_TURNIND_CAMERA_PROB */
      }
      else
      {
        pt_SITOutput->t_LaneChangeStatic.f_LCStateHysteresisRight -= SIT_LC_HYSTERESIS_TIME;
        pt_SITOutput->t_LaneChangeStatic.f_LCStateHysteresisLeft -= SIT_LC_HYSTERESIS_TIME;
      }
      
    }
    else 
    {
      /* High kinematic prob 
      a) with same previous state or
      b) No hysteresis active
      then maintain lane change state and increase hysteresis count */
      pt_SITOutput->t_LaneChangePhase.t_LCPhase = LC_LANECHANGE;
      if ( pt_SITOutput->t_LaneChangePhase.t_LCPhaseState == LC_LEFT )
      {
        /*increase left hysteresis without exceeding the max calculated based on velocity*/
        pt_SITOutput->t_LaneChangeStatic.f_LCStateHysteresisLeft += SIT_LC_STEERBACK_TIME_FACTOR * SIT_LC_HYSTERESIS_TIME;
        if ( pt_SITOutput->t_LaneChangeStatic.f_LCStateHysteresisLeft > f_StateHysteresis )
        { 
          pt_SITOutput->t_LaneChangeStatic.f_LCStateHysteresisLeft = f_StateHysteresis ;
        }
      }
      else
      {
        /*increase left hysteresis without exceeding the max calculated based on velocity*/
        pt_SITOutput->t_LaneChangeStatic.f_LCStateHysteresisRight += SIT_LC_STEERBACK_TIME_FACTOR * SIT_LC_HYSTERESIS_TIME;
        if (pt_SITOutput->t_LaneChangeStatic.f_LCStateHysteresisRight > f_StateHysteresis)
        { 
          pt_SITOutput->t_LaneChangeStatic.f_LCStateHysteresisRight = f_StateHysteresis;
        }
      } /* END IF ( t_PreviousState == LC_LEFT ) */
    } /* END IF Case for steerback */
  }
  else if ( ( pt_SITOutput->t_LaneChangePhase.u_LCPhaseProb > SIT_LC_PROB_THRESHOLD_STEERBACK )
         || ( pt_SITOutput->t_LaneChangeStatic.f_LCProbLeftAverage > SIT_LC_STEERBACK_KINEMATIC_THRESH )
         || ( pt_SITOutput->t_LaneChangeStatic.f_LCProbRightAverage > SIT_LC_STEERBACK_KINEMATIC_THRESH)
          )
  { 
    /* Due to majority of steerbacks having a much weaker prob/ kinematic response another check with much lower threshold value */
    if ( ( ( (pt_SITOutput->t_LaneChangeStatic.t_PreviousState != pt_SITOutput->t_LaneChangePhase.t_LCPhaseState) 
          && (pt_SITOutput->t_LaneChangePhase.t_LCPhaseState != LC_FOLLOW)
           )
        || ( ( (pt_SITOutput->t_LaneChangeStatic.f_LCProbLeftAverage > SIT_LC_STEERBACK_KINEMATIC_THRESH) 
            && (pt_SITOutput->t_LaneChangeStatic.t_PreviousState == LC_RIGHT) 
             )
          || ( (pt_SITOutput->t_LaneChangeStatic.f_LCProbRightAverage > SIT_LC_STEERBACK_KINEMATIC_THRESH) 
            && (pt_SITOutput->t_LaneChangeStatic.t_PreviousState == LC_LEFT)
             )
           )
         )
      && ( ( pt_SITOutput->t_LaneChangeStatic.f_LCStateHysteresisRight > 0.0f)
        || ( pt_SITOutput->t_LaneChangeStatic.f_LCStateHysteresisLeft > 0.0f)
         )
       )
    {
      pt_SITOutput->t_LaneChangePhase.t_LCPhase = LC_STEERBACK;
      pt_SITOutput->t_LaneChangeStatic.f_LCStateHysteresisRight = SIT_LC_HYSTERESIS_STEERBACK_TIME;
      pt_SITOutput->t_LaneChangeStatic.f_LCStateHysteresisLeft = SIT_LC_HYSTERESIS_STEERBACK_TIME;
#if (SIT_LC_CFG_USE_TURNIND_CAMERA_PROB)
      pt_SITOutput->t_LaneChangeStatic.f_LCSteerbackTimer = SIT_LC_STEERBACK_TIME;
#endif /*!< SIT_LC_CFG_USE_TURNIND_CAMERA_PROB */
    }
    else
    {
      /*do nothing retain phase*/
    } 
  } /* END IF Case for steerback low threshold */
  /*detecting the end of lane change phase based on hysteresis and low prob*/
  else if ( (pt_SITOutput->t_LaneChangePhase.u_LCPhaseProb < SIT_LC_PROBMIN_LANECHANGE)
         && (pt_SITOutput->t_LaneChangeStatic.f_LCStateHysteresisLeft <= 0.0f)
         && (pt_SITOutput->t_LaneChangeStatic.f_LCStateHysteresisRight <= 0.0f) 
          )
  {
    pt_SITOutput->t_LaneChangePhase.t_LCPhase = LC_NO_LANECHANGE;
#if (SIT_LC_CFG_USE_TURNIND_CAMERA_PROB)
#if (SIT_CFG_LC_USE_TURN_INDICATOR_INPUT)
    pt_SITOutput->t_LaneChangeStatic.f_TimeFiltTurnIndLeft = 0.f;
    pt_SITOutput->t_LaneChangeStatic.f_TimeFiltTurnIndRight = 0.f;
#endif  /*(SIT_CFG_LC_USE_TURN_INDICATOR_INPUT) */
    SITLCProbDataGlobal.LCTurnLightEvalLeft.fTimeAfterTLActivation = SIT_LC_PROB_MAX_TIME_AFTER_TI_ACTIVE;
    SITLCProbDataGlobal.LCTurnLightEvalRight.fTimeAfterTLActivation = SIT_LC_PROB_MAX_TIME_AFTER_TI_ACTIVE;
    pt_SITOutput->t_LaneChangeStatic.f_LCCamLMHysteresisLeft = 0.f;
    pt_SITOutput->t_LaneChangeStatic.f_LCCamLMHysteresiRight = 0.f;
#endif /*!< SIT_LC_CFG_USE_TURNIND_CAMERA_PROB */
  }
  else/*In the case of low prob but with valid state hysteresis maintain state  while reducing hysteresis gradually */
  {
    if (pt_SITOutput->t_LaneChangeStatic.f_LCStateHysteresisRight <= 0.0f)
    { 
      pt_SITOutput->t_LaneChangeStatic.f_LCStateHysteresisRight = 0.0f;
    }
    else
    {
      pt_SITOutput->t_LaneChangeStatic.f_LCStateHysteresisRight -= SLATE_f_GetCycleTime();
    }

    if (pt_SITOutput->t_LaneChangeStatic.f_LCStateHysteresisLeft <= 0.0f)
    { 
      pt_SITOutput->t_LaneChangeStatic.f_LCStateHysteresisLeft = 0.0f;
    }
    else
    {
      pt_SITOutput->t_LaneChangeStatic.f_LCStateHysteresisLeft -= SLATE_f_GetCycleTime();
    }

    if ( (pt_SITOutput->t_LaneChangeStatic.f_LCStateHysteresisRight <= 0.0f)
      && (pt_SITOutput->t_LaneChangeStatic.f_LCStateHysteresisLeft <= 0.0f)
       )
    {
      pt_SITOutput->t_LaneChangePhase.t_LCPhase = LC_NO_LANECHANGE;
#if (SIT_LC_CFG_USE_TURNIND_CAMERA_PROB)
#if (SIT_CFG_LC_USE_TURN_INDICATOR_INPUT)
      pt_SITOutput->t_LaneChangeStatic.f_TimeFiltTurnIndLeft = 0.f;
      pt_SITOutput->t_LaneChangeStatic.f_TimeFiltTurnIndRight = 0.f;
#endif  /*(SIT_CFG_LC_USE_TURN_INDICATOR_INPUT) */
      SITLCProbDataGlobal.LCTurnLightEvalLeft.fTimeAfterTLActivation = SIT_LC_PROB_MAX_TIME_AFTER_TI_ACTIVE;
      SITLCProbDataGlobal.LCTurnLightEvalRight.fTimeAfterTLActivation = SIT_LC_PROB_MAX_TIME_AFTER_TI_ACTIVE;
      pt_SITOutput->t_LaneChangeStatic.f_LCCamLMHysteresisLeft = 0.f;
      pt_SITOutput->t_LaneChangeStatic.f_LCCamLMHysteresiRight = 0.f;
#endif /*!< SIT_LC_CFG_USE_TURNIND_CAMERA_PROB */
    }
  }
}// PRQA S 7004
 /* date: 2020-10-06, reviewer: Gowthama P, reason: Cyclometric complexity, Not safety critical */

/* ***********************************************************************
@fn              SIT_v_SetLaneChangeOutput                           */ /*!

@brief           lanechange state machine 

@description     phase transitions between all phases as well as confidence calculation which is based on the state hysteresis

                 @startuml
                 Partition SIT_v_SetLaneChangeOutput{
                 Start
                 : set minimum values for fusion probabilities;
                 : hold previous state until lane change phase is over,\n in order to detect steer back should it occur  during this time;
                 If (NOLANECHANGE) then (TRUE)
                 : no lane change phase state;
                 Elseif (PRELANECHANGE) then (TRUE)
                 : pre lane change phase state;
                 Elseif (LANECHANGE) then (TRUE)
                 : Function for lane change phase transition;
                 Elseif (STEERBACK) then (TRUE)
                 : Get LC stage indicator pre lanechange, hysteresis countdown for lane change\n state after probability drop;
                 Else (FALSE)
                 : NO LANECHANGE;
                 Endif
                 : confidence factor calculation based on state hysteresis;
                 End
                 }
                 @enduml

@return          Final lane change prob and state

@param[in]       -b_PreLaneChange 0 or 1 indicating  possibility or intention for lane change.

@glob_in         -pt_SITOutput->s_LCProbLeft
@glob_in         -pt_SITOutput->s_LCProbRight
@glob_in         -pt_SITOutput->t_LaneChangeStatic.f_LCStateHysteresisRight
@glob_in         -pt_SITOutput->t_LaneChangeStatic.f_LCStateHysteresisLeft

@glob_out        -pt_SITOutput->t_LaneChangePhase.t_LCPhase
@glob_out        -pt_SITOutput->t_LaneChangePhase.u_LCConfidence
@c_switch_part   -
@c_switch_full   SIT_LC_CFG_USE_TURNIND_CAMERA_PROB : Configuration switch to enable lane change probability calculation using turn indicator input and camera lane input

@pre             -
@post            -


@pre            SIT_v_DetectLaneChange must have been done in the current cycle (to update internal state)

@post           -

@testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                 Test order of calls (dynamic module test). \n
                 Test of code coverage (dynamic module test). \n  
                 Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                 Test of run time error/warnings (Static code analysis).

@traceability    429:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-429-00061542 \n

@author         Ahmed Shabayek
**************************************************************************** */
#if (SIT_LC_CFG_ENABLE_MULTIOBJFUSION)
static void SIT_v_SetLaneChangeOutput(boolean b_PreLaneChange)
#else
static void SIT_v_SetLaneChangeOutput(void)
#endif
{
  const float32 fEgoSpeed = *pt_SITInput->t_RTE.pf_EgoLongVel;
  /*state hysteresis set linearly as a factor of speed, higher speed yeilds lower time for the state*/
  float32 f_StateHysteresis = ( -fEgoSpeed/SIT_LC_STATE_HYSTERESIS_SLOPEFACTOR ) + SIT_LC_STATE_HYSTERESIS_INTERCEPT ;
  float32 fOutputCast = 0.0f;
#if (SIT_LC_CFG_USE_TURNIND_CAMERA_PROB)
  /* If ego is stationary (velocity below 1m/s) then reset the left and right lane change probabilities. 
  This is because CamLaneMarkerCrossedProb goes high due to fluctuations in distance to camera lane markers */
  if ( fEgoSpeed <= SIT_LC_PROB_MIN_EGO_SPEED )
  {
    pt_SITOutput->s_LCProbLeft = 0;
    pt_SITOutput->s_LCProbRight = 0;
    pt_SITOutput->t_LaneChangeStatic.f_LCProbLeftAverage = 0.f;
    pt_SITOutput->t_LaneChangeStatic.f_LCProbRightAverage = 0.f;
  }
  else
  {
#endif /*!< SIT_LC_CFG_USE_TURNIND_CAMERA_PROB */
    /*set minimum values for fusion probabilities*/
    /*temporary*/
    if (pt_SITOutput->s_LCProbLeft < (uint16)10)
    {
      pt_SITOutput->s_LCProbLeft = 10;
    }

    if (pt_SITOutput->s_LCProbRight < (uint16)10)
    {
      pt_SITOutput->s_LCProbRight = 10;
    }

    if (pt_SITOutput->t_LaneChangeStatic.f_LCProbLeftAverage < 0.3f)
    {
      pt_SITOutput->t_LaneChangeStatic.f_LCProbLeftAverage = 0.3f ;
    }

    if (pt_SITOutput->t_LaneChangeStatic.f_LCProbRightAverage < 0.3f)
    {
      pt_SITOutput->t_LaneChangeStatic.f_LCProbRightAverage = 0.3f ;
    }
#if (SIT_LC_CFG_USE_TURNIND_CAMERA_PROB)
  }
#endif /*!< SIT_LC_CFG_USE_TURNIND_CAMERA_PROB */
  SIT_v_LaneChangeProbFusion();/* naive bayes fusion to all observer probabilities */
#if (SIT_LC_USE_FILTER_PEAK_PROB)
  SIT_v_FilterPeakProb();
#endif
  SIT_v_DetermineLaneChangeState();/*where state is determined and impulse filtering is applied to the prob */
  
  /*hold previous state until lane change phase is over, in order to detect steer back should it occur  during this time*/
  if (pt_SITOutput->t_LaneChangePhase.t_LCPhase != LC_LANECHANGE)
  {
    pt_SITOutput->t_LaneChangeStatic.t_PreviousState = pt_SITOutput->t_LaneChangePhase.t_LCPhaseState;
  }

  switch (pt_SITOutput->t_LaneChangePhase.t_LCPhase )
  {
    /*START NOLANECHANGE*/
  case LC_NO_LANECHANGE:
#if (SIT_LC_CFG_ENABLE_MULTIOBJFUSION)
    SIT_v_NoLaneChangeState( b_PreLaneChange);
#else
    SIT_v_NoLaneChangeState();
#endif
    break;
    /* END NOLANECHANGE */
    /* START PRELANECHANGE*/
  case LC_PRELANECHANGE:
#if (SIT_LC_CFG_ENABLE_MULTIOBJFUSION)
    SIT_v_PreLaneChangeState( b_PreLaneChange);
#else
    SIT_v_PreLaneChangeState();
#endif
    break;
    /*END PRELANECHANGE */

    /* START LANECHANGE*/
  case LC_LANECHANGE: 
    SIT_v_LaneChangeState( f_StateHysteresis );
    break;
    /*END LANE CHANGE*/

    /*START STEERBACK*/
  case LC_STEERBACK:/*  */
    if ( (  ( pt_SITOutput->t_LaneChangePhase.u_LCPhaseProb > SIT_LC_PROB_THRESHOLD_STEERBACK )
         || ( pt_SITOutput->t_LaneChangeStatic.f_LCStateHysteresisRight > 0.0f )
         || ( pt_SITOutput->t_LaneChangeStatic.f_LCStateHysteresisLeft > 0.0f )
#if (SIT_LC_CFG_USE_TURNIND_CAMERA_PROB)
         || ( pt_SITOutput->t_LaneChangeStatic.f_LCCamLMHysteresisLeft > 0.f )
         || ( pt_SITOutput->t_LaneChangeStatic.f_LCCamLMHysteresiRight > 0.f )
#endif /*!< SIT_LC_CFG_USE_TURNIND_CAMERA_PROB */
       )
#if (SIT_LC_CFG_USE_TURNIND_CAMERA_PROB)
       && (pt_SITOutput->t_LaneChangeStatic.f_LCSteerbackTimer > 0.f)
#endif /*!< SIT_LC_CFG_USE_TURNIND_CAMERA_PROB */
       )
    {
      pt_SITOutput->t_LaneChangePhase.t_LCPhase = LC_STEERBACK;
      pt_SITOutput->t_LaneChangeStatic.f_LCStateHysteresisRight -= SLATE_f_GetCycleTime() ;
      pt_SITOutput->t_LaneChangeStatic.f_LCStateHysteresisLeft -= SLATE_f_GetCycleTime();
#if (SIT_LC_CFG_USE_TURNIND_CAMERA_PROB)
      pt_SITOutput->t_LaneChangeStatic.f_LCCamLMHysteresisLeft -= SLATE_f_GetCycleTime() ;
      pt_SITOutput->t_LaneChangeStatic.f_LCCamLMHysteresiRight -= SLATE_f_GetCycleTime();
      pt_SITOutput->t_LaneChangeStatic.f_LCSteerbackTimer -= SLATE_f_GetCycleTime();
#endif /*!< SIT_LC_CFG_USE_TURNIND_CAMERA_PROB */
    }
    else /* No lane change*/
    {
      pt_SITOutput->t_LaneChangeStatic.f_LCStateHysteresisRight = 0.f;
      pt_SITOutput->t_LaneChangeStatic.f_LCStateHysteresisLeft = 0.f;
      pt_SITOutput->t_LaneChangePhase.t_LCPhase = LC_NO_LANECHANGE;
#if (SIT_LC_CFG_USE_TURNIND_CAMERA_PROB)
#if (SIT_CFG_LC_USE_TURN_INDICATOR_INPUT)
      pt_SITOutput->t_LaneChangeStatic.f_TimeFiltTurnIndLeft = 0.f;
      pt_SITOutput->t_LaneChangeStatic.f_TimeFiltTurnIndRight = 0.f;
#endif  /*(SIT_CFG_LC_USE_TURN_INDICATOR_INPUT) */
      pt_SITOutput->t_LaneChangeStatic.f_LCCamLMHysteresisLeft = 0.f;
      pt_SITOutput->t_LaneChangeStatic.f_LCCamLMHysteresiRight = 0.f;
      pt_SITOutput->t_LaneChangeStatic.f_LCSteerbackTimer = 0.f;
      SITLCProbDataGlobal.LCTurnLightEvalLeft.fTimeAfterTLActivation = SIT_LC_PROB_MAX_TIME_AFTER_TI_ACTIVE;
      SITLCProbDataGlobal.LCTurnLightEvalRight.fTimeAfterTLActivation = SIT_LC_PROB_MAX_TIME_AFTER_TI_ACTIVE;
#endif /*!< SIT_LC_CFG_USE_TURNIND_CAMERA_PROB */
    }
    break;
  default:
    pt_SITOutput->t_LaneChangePhase.t_LCPhase = LC_NO_LANECHANGE;
    break;
  }
  /* END STEERBACK*/

  /*confidence factor calculation based on state hysteresis*/
  if (pt_SITOutput->t_LaneChangeStatic.f_LCStateHysteresisLeft > pt_SITOutput->t_LaneChangeStatic.f_LCStateHysteresisRight)
  {
    /* output = ((input - inputmin) * ( (outputmax - outputstart ) / ( inputmax - inputmin ) ) ) + outputmin */
    fOutputCast  = ((pt_SITOutput->t_LaneChangeStatic.f_LCStateHysteresisLeft / SIT_LC_STATE_HYSTERESIS) * SIT_LC_PROBTOPRECENTAGE); 
    pt_SITOutput->t_LaneChangePhase.u_LCConfidence = (uint8) fOutputCast;
  }
  else
  {
    fOutputCast = (( pt_SITOutput->t_LaneChangeStatic.f_LCStateHysteresisRight / SIT_LC_STATE_HYSTERESIS) * SIT_LC_PROBTOPRECENTAGE);
    pt_SITOutput->t_LaneChangePhase.u_LCConfidence = (uint8)fOutputCast; 
  }
  SIT_v_SetLaneChangeTimeGap();
}

#if (SIT_CFG_LC_PROB_CALC)
/* ***********************************************************************
@fn             SIT_f_CalcGEVDProb                           */ /*!

@brief          Calculate the generalized extreme value distribution for a given input

@description    Calculate the generalized extreme value distribution for a given input

                @startuml
                Partition SIT_f_CalcGEVDProb{
                Start
                : Calculate first auxiliary variable;
                : Calculate second auxiliary variable;
                : Calculate the value obtained by the gev-distribution;
                End
                }
                @enduml

@param          fVal : Input parameter

@param          fKappa : Shape parameter

@param          fSigma :  Scale parameter

@param          fMu : Location parameter

@author         Christopher Knievel
**************************************************************************** */
float32 SIT_f_CalcGEVDProb(float32 fVal, float32 fKappa, float32 fSigma, float32 fMu)
{
  float32 fRetVal;
  float32 fAuxM, fAuxN;
  const float32 fSigmaInv = 1.f/fSigma;
  const float32 fKappaInv = 1.f/fKappa;

  /* Calculate first auxiliary variable */  
  fAuxM = fABS((((fVal - fMu) * fSigmaInv) * fKappa) + 1.0f);

  /* Calculate second auxiliary variable */
  if(fAuxM > CML_f_AlmostZero)
  {
    fAuxN = -1.0f * fKappaInv * CML_f_fastlog(fAuxM);

    /* Calculate the value obtained by the gev-distribution */
    fRetVal = fSigmaInv * (1.0f/(fAuxM)) * GDBexp(fAuxN - GDBexp(fAuxN));
  }
  else
  {
    fRetVal = 0.0f;
  }
  return fRetVal;
}


/*************************************************************************************************************************
Functionname:    SIT_f_CalcGDProb                                                                                 */ /*!

@brief           Calculate the normal distribution for a given input.

@description     Calculate the normal distribution for a given input.

                  @startuml
                  Partition SIT_f_CalcGDProb{
                  Start
                  : Calculate the value obtained by the Gaussian distribution;
                  End
                  }
                  @enduml

@return          fRetVal : float32

@param[in]       fVal   : Input parameter     [Full range of float32]
@param[in]       fMean  : Mean value          [Full range of float32]
@param[in]       fSigma : Standard deviation  [Full range of float32]

@glob_in         -
@glob_out        -

@c_switch_part   -
@c_switch_full   SIT_CFG_LC_PROB_CALC  : Configuration switch enabling lane change prob calculation 
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

@author          Christopher Knievel
*************************************************************************************************************************/
float32 SIT_f_CalcGDProb(float32 fVal, float32 fMean, float32 fSigma)
{
  float32 fRetVal = 0.0f;
  float32 faux = 0.0f;
  if (fVal > SIT_LC_GAUSS_RANDOM_VARIBLE_MAX)
  {
    fVal = SIT_LC_GAUSS_RANDOM_VARIBLE_MAX;
  }
  else if ( fVal < SIT_LC_GAUSS_RANDOM_VARIBLE_MIN)
  {
    fVal = SIT_LC_GAUSS_RANDOM_VARIBLE_MIN;
  }
  else
  {
    /* do nothing */
  }
  if(fSigma > CML_f_AlmostZero)
  {
    /* Calculate the value obtained by the Gaussian distribution */
    faux = -0.5f * (SQR((fVal-fMean)/fSigma));
    faux  = GDBexp(faux);
    fRetVal = faux / (SIT_LC_GAUSS_PREFAC * fSigma);
  }

  return fRetVal;
}
#endif
///@}
#endif /*!< FCT_CFG_ACC_SITUATION */
