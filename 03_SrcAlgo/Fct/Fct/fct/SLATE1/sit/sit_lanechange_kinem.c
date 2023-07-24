/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)
  
CPU:                       CPU-Independent
  
COMPONENT:                 SLATE_SIT (Situation)

PACKAGENAME:               sit_lanechange_kinem.c

DESCRIPTION:               ACC lane change detection of the host vehicle. 
                           Implementation of the kinematic observer

AUTHOR:                    Christopher Knievel

CREATION DATE:             04.12.2014

VERSION:                   $Revision: 1.15 $

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
#if (SIT_CFG_LC_PROB_CALC)
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/

/**
@defgroup sit_lanechange_kinem Sit Lane change Kinematics
@ingroup sit_lanechange
@brief          This module detects ACC Lane change of object based on Kinematics.\n\n
@{
*/
/*****************************************************************************
  MODULEGLOBAL CONSTANTS
*****************************************************************************/
//PRQA S 0791 MACRO_IDENTIFIER_LENGTH
/* date: 2019-07-28, reviewer:Prabhu Sundaramurthy, reason: Macro identifier does not differ from other macro identifier within the specified number of significant characters,Does not affect functionality*/
/*! Yawrate limits for left and right lane changes...*/

#define YAWRATE_RIGHTLANECHANGE_LOWLIMIT    (-0.05f)
#define YAWRATE_RIGHTLANECHANGE_HIGHLIMIT   (0.03f)

#define YAWRATE_LEFTLANECHANGE_LOWLIMIT    (-0.03f)
#define YAWRATE_LEFTLANECHANGE_HIGHLIMIT   (0.05f)


/*! Minimum value for DMMRYAW value  */ 
#define SIT_DMMRYAW_MINVAL  (1.e8f)

/*! Minimum speed for calculation of kinematic lane change probability */
#define SIT_LC_MIN_SPEED_KINEM             (30.0f/C_KMH_MS)
#define SIT_LC_MID_SPEED_KINEM             (80.0f/C_KMH_MS)
#define SIT_LC_HIGH_SPEED_KINEM            (100.0f/C_KMH_MS)
/*lane change scenario probability */
#define SIT_LC_PROB_LOWSPEED                0.13f
#define SIT_LC_PROB_MIDSPEED                0.17f
#define SIT_LC_PROB_HIGHSPEED               0.20f
#define SIT_FOLLOW_PROB_LOWSPEED            0.74f
#define SIT_FOLLOW_PROB_MIDSPEED            0.66f
#define SIT_FOLLOW_PROB_HIGHSPEED           0.60f
/*! Parameters for the GEV-Distribution of raw yaw rate - Left lane change */
#define SIT_LC_LEFT_YAW_RATE_K             (0.0808861f)/*(0.128861f)*/
#define SIT_LC_LEFT_YAW_RATE_SIGMA         (0.0072599f)/*(0.012599f)*/
#define SIT_LC_LEFT_YAW_RATE_MU            (0.0195819f)/*(0.0195819f)*/

/*! Parameters for the GEV-Distribution of raw yaw rate - Right lane change */
#define SIT_LC_RIGHT_YAW_RATE_K            (-0.4520063f)/*(-0.530063f)*/
#define SIT_LC_RIGHT_YAW_RATE_SIGMA        (0.012154861f)/*(0.014861f)*/
#define SIT_LC_RIGHT_YAW_RATE_MU           (-0.0301606f)/*(-0.029606f)*/

/*! Parameters for the standard normal distribution of raw yaw rate - Follow lane */
#define SIT_LC_FOLLOW_YAW_RATE_MU            (0.0f)
#define SIT_LC_FOLLOW_YAW_RATE_SIGMA         (0.025f)


/*! Parameters for the GEV-Distribution of DMMR Yaw rate - Left lane change */
#define SIT_LC_LEFT_DMMR_YAW_RATE_K        (0.861009f)
#define SIT_LC_LEFT_DMMR_YAW_RATE_SIGMA    (0.00118437f)
#define SIT_LC_LEFT_DMMR_YAW_RATE_MU       (0.00107065f)

/*! Parameters for the GEV-Distribution of DMMR Yaw rate - Right lane change */
#define SIT_LC_RIGHT_DMMR_YAW_RATE_K       (0.823817f)
#define SIT_LC_RIGHT_DMMR_YAW_RATE_SIGMA   (0.00104879f)
#define SIT_LC_RIGHT_DMMR_YAW_RATE_MU      (0.00103833f)

/*! Parameters for the standard normal Distribution of DMMR Yaw rate - Follow lane*/
#define SIT_LC_FOLLOW_DMMR_YAW_RATE_MU     (0.001f)
#define SIT_LC_FOLLOW_DMMR_YAW_RATE_SIGMA  (0.00056f)


/*! Parameters for the GEV-Distribution of cumulative sum distance to road border- Left lane change */
#define SIT_LC_LEFT_CUMSUM_DIST_ROAD_MU       (0.35f)
#define SIT_LC_LEFT_CUMSUM_DIST_ROAD_SIGMA    (0.3f)

/*! Parameters for the GEV-Distribution of cumulative sum distance to road border - Right lane change */
#define SIT_LC_RIGHT_CUMSUM_DIST_ROAD_MU       (-0.35f)
#define SIT_LC_RIGHT_CUMSUM_DIST_ROAD_SIGMA    (0.3f)

/*! Parameters for the standard normal Distribution of DMMR  distance to road border - Follow lane*/
#define SIT_LC_FOLLOW_CUMSUM_DIST_ROAD_MU     (0.0f)
#define SIT_LC_FOLLOW_CUMSUM_DIST_ROAD_SIGMA  (0.3f)


/*! Parameters for the GEV-Distribution of aflat - Left lane change */
#define SIT_LC_LEFT_AFLAT_K        (-0.457638f)
#define SIT_LC_LEFT_AFLAT_SIGMA    (0.184667f)
#define SIT_LC_LEFT_AFLAT_MU       (0.452301f)

/*! Parameters for the GEV-Distribution of aflat - Right lane change */
#define SIT_LC_RIGHT_AFLAT_K       (-0.207147f)
#define SIT_LC_RIGHT_AFLAT_SIGMA   (0.1650719f)
#define SIT_LC_RIGHT_AFLAT_MU      (-0.562272f)

/*! Parameters for the standard normal Distribution of aflat - Follow lane*/
#define SIT_LC_FOLLOW_AFLAT_MU     (0.0f)
#define SIT_LC_FOLLOW_AFLAT_SIGMA  (0.357567f)
#define SIT_LC_BLINKER_PROB_FACTOR (0.2f)
#define SIT_LC_ALPHA_MAVERAGE      (1.0f)  /* Weighting for moving average */


/*! Minimum Road Border confidence */
#define SIT_LC_ROAD_BORDER_MIN_STAT (84.f)

/*! Minimum Road Border tracking status*/
#define SIT_LC_ROAD_BORDER_MIN_TRACKING_STAT (7u)

/* Maximum summation value for DMMR distance */
#define SIT_LC_CUMSUM_DIST_MAX_SUM     (3.0f)
/* PRQA L:MACRO_IDENTIFIER_LENGTH*/
/*****************************************************************************
  MODULGLOBAL VARIABLES
*****************************************************************************/



/*****************************************************************************
  MODULE LOCAL SYMBOLIC CONSTANTS
*****************************************************************************/

/*****************************************************************************
  MODULE LOCAL MACROS
*****************************************************************************/


/*****************************************************************************
  MODULE LOCAL TYPES
*****************************************************************************/


/*****************************************************************************
  MODULE LOCAL CONSTANTS
*****************************************************************************/


/*****************************************************************************
  MODULE LOCAL TYPEDEFS
*****************************************************************************/

  
/*****************************************************************************
  MODULE LOCAL VARIABLES
*****************************************************************************/


/*****************************************************************************
  FUNCTION PROTOTYPES
*****************************************************************************/
static void SIT_v_CalculateInputSignals(const float32* const pfYawRate, const float32* const pfDistToRoad, boolean bDistValid, float32* const pfDMMRYaw,  
  float32* const pfDMMRDist);

static float32 SIT_f_CalcCUMSUMDistance(const float32 fCurrentVal);
static float32 SIT_f_CalcDMMRYaw(const float32 fCurrentVal);
static void SIT_v_InitRoadParameters(void);

/* ************************************************************************* */
/*   Copyright ADC-GmbH, Lindau                                              */
/* ************************************************************************* */


/*************************************************************************************************************************
  Functionname:    SIT_v_InitLaneChangeKinem                                                                        */ /*!

  @brief           Initialize kinematic lane change detection module

  @description     Function initializes kinematic lane change detection module

                   @startuml
                   partition SIT_v_InitLaneChangeKinem{
                   start
                   : Initialize moving average yaw rate, Lane change overall probability, Lane change state counter to zero;
                   : Initialize Yaw rate of last cycle, Estimated distance to side road boundry of previous cycle, Array indices, final kinematic probability output to zero;
                   : Initialize Arrays for storing difference between distance to side road boundry and difference between yaw rate of previous and current sample to zero;
                   Stop
                   }
                   @enduml

  @return          -

  @param[in]       - 

  @glob_in         -
  @glob_out        fMovingAverageYawRate : Moving Average Yaw Rate                                                                                          [-100.f .. +100.f] rad/s
  @glob_out        fLCProbOverall : Lance Change overall probability                                                                                        [0f ... 100f]
  @glob_out        fLCDetectState : Lane change state counter of the kinematic observer                                                                     [-1f ... +1f]
  @glob_out        SITLaneChangeCUMSUMDist.fDMMRSamples : Array for storing difference between Distance to side road boundary of Previous and current cycle [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @glob_out        SITLaneChangeCUMSUMDist.fLastValue   : Estimated Distance to side road boundary of Previous cycle                                        [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @glob_out        SITLaneChangeCUMSUMDist.uiRunIndex   : Index                                                                                             [0..SIT_LC_DMMR_YAW_MAX_SAMPLES]
  @glob_out        SITLaneChangeDMMRYaw.fDMMRSamples    : Array for storing difference between Distance to side road boundary of Previous and current cycle [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @glob_out        SITLaneChangeDMMRYaw.fLastValue      : Input Yawrate of Last cycle                                                                       [-100.f .. +100.f] rad/s 
  @glob_out        SITLaneChangeDMMRYaw.uiRunIndex      : Index                                                                                             [0..SIT_LC_DMMR_YAW_MAX_SAMPLES]

  @c_switch_part   -
  @c_switch_full   SIT_CFG_LC_PROB_CALC  : Configuration switch enabling lane change probability calculation 
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
void SIT_v_InitLaneChangeKinem(void)
{
  uint8 i;

  /* Initialize static variables */ 
  pt_SITOutput->t_LaneChangeKinStatic.fMovingAverageYawRate = 0.0f;
  pt_SITOutput->t_LaneChangeKinStatic.fLCProbOverall        = 0.0f;
  t_SITOutput.t_LaneChangeStatic.f_LCProbRightAverage   = 0.0f;
  t_SITOutput.t_LaneChangeStatic.f_LCProbLeftAverage    = 0.0f;
  for (i=0u; i<SIT_LC_DMMR_YAW_MAX_SAMPLES; i++)
  {
    pt_SITOutput->t_LaneChangeKinStatic.t_LaneChangeDMMRYaw.fDMMRSamples[i]  = 0.0f;
  }

  for (i=0u; i<SIT_LC_CUMSUM_DIST_MAX_SAMPLES; i++)
  {
    pt_SITOutput->t_LaneChangeKinStatic.t_LaneChangeCUMSUMDist.fDMMRSamples[i] = 0.0f;
  }

  pt_SITOutput->t_LaneChangeKinStatic.t_LaneChangeCUMSUMDist.fLastValue = 0.0f;
  pt_SITOutput->t_LaneChangeKinStatic.t_LaneChangeDMMRYaw.fLastValue  = 0.0f;

  pt_SITOutput->t_LaneChangeKinStatic.t_LaneChangeCUMSUMDist.uiRunIndex = 0u;
  pt_SITOutput->t_LaneChangeKinStatic.t_LaneChangeDMMRYaw.uiRunIndex  = 0u;
}



/*************************************************************************************************************************
  Functionname:    SIT_v_InitRoadParameters                                                                         */ /*!

  @brief           Initialize road border specific parameters

  @description     Initialize road border specific parameters

                   @startuml
                   partition SIT_v_InitRoadParameters{
                   start
                   : Initialize the array to store difference between distance to road boundry of previous and current cycle to zero;
                   : Initialize the input yaw rate variable for previous cycle to zero;
                   : Initialize the array index to zero;
                   Stop
                   }
                   @enduml

  @return          -

  @param[in]       - 

  @glob_in         -
  @glob_out        SITLaneChangeCUMSUMDist.fDMMRSamples : Array for storing difference between Distance to side road boundary of Previous and current cycle [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @glob_out        SITLaneChangeDMMRYaw.fLastValue      : Input Yawrate of Last cycle                                                                       [-100.f .. +100.f] rad/s 
  @glob_out        SITLaneChangeDMMRYaw.uiRunIndex      : Index                                                                                             [0..SIT_LC_DMMR_YAW_MAX_SAMPLES]

  @c_switch_part   -
  @c_switch_full   SIT_CFG_LC_PROB_CALC  : Configuration switch enabling lane change probability calculation 
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
static void SIT_v_InitRoadParameters(void)
{
  uint8 i;

  for (i=0u; i<SIT_LC_CUMSUM_DIST_MAX_SAMPLES; i++)
  {
    pt_SITOutput->t_LaneChangeKinStatic.t_LaneChangeCUMSUMDist.fDMMRSamples[i] = 0.0f;
  }

  pt_SITOutput->t_LaneChangeKinStatic.t_LaneChangeCUMSUMDist.fLastValue = 0.0f;
  pt_SITOutput->t_LaneChangeKinStatic.t_LaneChangeCUMSUMDist.uiRunIndex = 0u;
}


/*************************************************************************************************************************
  Functionname:    SIT_v_CalculateKinematicLCProb                                                                   */ /*!

  @brief           Calculate the lane change probability based on kinematic signals

  @description     Calculate the lane change probability based on kinematic signals

                   @startuml
                   partition SIT_v_CalculateKinematicLCProb{
                   Start
                   : Initialize variables to default vaues which are required for calculation of kinematic lane change probability;
                   : Get turn indicator current state;
                   : Get left road border;
                   : Get yaw rate;
                   : Get lateral difference of filtered curve;
                   If (Ego vehicle speed is > SIT_LC_MIN_SPEED_KINEM) then (yes)
                   	If (check that road border information and road tracking status fullfill the minimum requirement) then (yes)
                   		: Set flag true to remember that road border information is valid;
                   	Else
                   		: Do nothing;
                   	Endif
                   	If (Lane change state machine is in prelanechange state) then (yes)
                   		: Assign blinker probability factor depending on turn indicator input;
                   	Else
                   		: Do nothing;
                   	Endif
                   	If (Ego speed is <= SIT_LC_MIN_SPEED_KINEM) then (yes)
                   		: Calculate probability priorities by adding lane change scenario probability for low speed with blinker factor;
                   	Elseif (Ego speed is < SIT_LC_MID_SPEED_KINEM) then (yes)
                   		: Calculate probability priorities by adding lane change scenario probability for medium speed with blinker factor;
                   	Else
                   		: Calculate probability priorities by adding lane change scenario probability for high speed with blinker factor;
                   	Endif
                   	: Initialize road border specific parameters;
                   	: Calculate additional required input signals based on yaw rate and distance to road border;
                   	If (Current yaw rate is within higher and lower limits for left lane change) then (yes)
                   		: Calculate lane change probability for yaw rate;
                   	Else
                   		: Set lane change probability for yaw rate to zero;
                   	Endif
                   	: Calculate lane change probability based on DMMR for yaw rate;
                   	: Calculate lane change probability based on DMMR for distance to road border;
                   	: Calculate lane change probability for lateral difference to filtered curve;
                   	: Calculate overall left lane change probability;
                   	If (Current yaw rate is within higher and lower limits for right lane change) then (yes)
                   		: Calculate lane change probability for yaw rate;
                   	Else
                   		: Set lane change probability for yaw rate to zero;
                   	Endif
                   	: Calculate lane change probability based on DMMR for yaw rate;
                   	: Calculate lane change probability based on DMMR for distance to road border;
                   	: Calculate lane change probability for lateral difference to filtered curve;
                   	: Calculate overall right lane change probability;
                   	: Calculate lane follow probability for yaw rate;
                   	: Calculate lane follow probability based on DMMR for yaw rate;
                   	: Calculate lane follow probability based on DMMR for distance to road border;
                   	: Calculate lane follow probability for lateral difference to filtered curve;
                   	: Calculate overall lane follow probability;
                   	: Calculate sum of overall right/left lane change and lane follow probability;
                   Else
                   	: Set sum of all the probabilities to zero;
                   Endif
                   If (Sum of all the probabilities is greater than zero) then (yes)
                   	: Calculate individual probabilities for left/right lane change and lane follow mode;
                   Else
                   	: Set all the individual probabilities for left/right lane change and lane follow mode to zero;
                   Endif
                   : Calculate moving average for overall lane change probability;
                   : Separate moving average for left/right lane change probability;
                   : Determine the lane change left/right/follow;
                   : Save all the calculated probabilities;
                   Stop
                   }
                   @enduml

  @return          -

  @param[in]       -

  @glob_in         pt_SITInput->t_RTE.pf_EgoLongVel : Ego Speed                                                    [-330.f ... 330.f] m/s
  @glob_in         pt_SITInput->t_FIPRoad.fYLeft                                                                   [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @glob_in         SITLCProbDataGlobal.afLatDiffFilteredCurvesFilt[   ] : filtered difference in lateral distance  [-PI*RW_FCT_MAX    PI*RW_FCT_MAX] 
  @glob_in         pt_SITInput->pt_FIPRoad->t_FIPRoadEstimation.fConfidenceLeft : one-sided road confidence for left side                [0f ... 100f]
  @glob_in         pt_SITInput->pt_FIPRoad->t_FIPRoadEstimation.uiTrackingStatus : Road tracking status                                  [0...7]
  @glob_out        fLCProbOverall : Lance Change overall probability                                               [0f ... 100f]
  @glob_out        fLCDetectState : Lane change state counter of the kinematic observer                            [-1f ... +1f]
  @glob_out        SITLCProbDataGlobal.fLCKinematicProb : lane change probability based on kinematic signals       [0f   100f]
  @glob_out        SITLCProbDataGlobal.fLCProbLeft : LC probability left                                           [0f   100f]
  @glob_out        SITLCProbDataGlobal.fLCProbRight : LC probability right                                         [0f   100f]
  @glob_out        SITLCProbDataGlobal.fLCProbFollow : LC probability follow                                       [0f   100f]
  
  
  @c_switch_part   FCT_CFG_ROAD_INPUT    : Road estimation input to FCT
  @c_switch_full   SIT_CFG_LC_PROB_CALC  : Configuration switch enabling lane change probability calculation 
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

  @todo            Inputs from FIP Road (pt_LAInput->t_FIPRoad) are available only if switch FCT_CFG_INPUT_PREPROCESSSING is 
                   on, which is not considered here. Switch for FCT_CFG_ROAD_INPUT to also be adapted.

  @author          Christopher Knievel
*************************************************************************************************************************/
void SIT_v_CalculateKinematicLCProb(void)
{
  float32 fRoadBorder;
  float32 fYawRate;
  float32 afLatDiffFilterCurve;
  float32 fDMMRYaw, fDMMRDist;
  float32 f_LCProbLeft, f_LCProbRight, fLCProbFollow, fLCProbSum;
  float32 f_BlinkerFactorLeft,f_BlinkerFactorRight;
  float32 fLCPaLeft, fLCPaRight, fLCPaFollow;
  const float32 fEgoSpeed = *pt_SITInput->t_RTE.pf_EgoLongVel;
  float32 fLCDMMRYaw, fLCDMMRDist, fLCYaw, fLCAflat;
#if (SIT_CFG_LC_USE_TURN_INDICATOR_INPUT) 
  eTurnIndicator_t t_TurnIndicator;
#endif
  boolean bRoadBorderValid = FALSE;




  /* Init probability values */
  f_LCProbLeft   = 0.0f;
  f_LCProbRight  = 0.0f;
  fLCProbFollow = 1.0f;
  f_BlinkerFactorRight = 0.0f;
  f_BlinkerFactorLeft = 0.0f;
#if (SIT_CFG_LC_USE_TURN_INDICATOR_INPUT) 
  t_TurnIndicator = SIT_t_SetTurnIndState();
#endif
  /* Get left road border */
#if (FCT_CFG_ROAD_INPUT)
  fRoadBorder = pt_SITInput->pt_FIPRoad->t_FIPRoadEstimation.fYLeft;
#endif /* FCT_CFG_ROAD_INPUT */
  /* Get yaw rate */
  fYawRate = SLATE_f_GetEgoYawRateObjSync();

  /* Get lateral difference of filtered curve */
  afLatDiffFilterCurve = SITLCProbDataGlobal.afLatDiffFilteredCurvesFilt[0];

  if( fEgoSpeed > SIT_LC_MIN_SPEED_KINEM)    
  {  
#if (FCT_CFG_ROAD_INPUT)
    /* If road border is sufficiently good set a flag to remember */
    if((  (pt_SITInput->pt_FIPRoad->t_FIPRoadEstimation.fConfidenceLeft) >= SIT_LC_ROAD_BORDER_MIN_STAT)
      && ((pt_SITInput->pt_FIPRoad->t_FIPRoadEstimation.uiTrackingStatus) >= SIT_LC_ROAD_BORDER_MIN_TRACKING_STAT))
    {
      bRoadBorderValid = TRUE;
    }
#endif /* FCT_CFG_ROAD_INPUT */
    /* Set a priori probabilities for left and right lane change as well as lane follow */
    /* These probabilities are chosen to yield a good trade-off between performance and false positive
        rate. They do not reflect the true a priori values.  */
    /* Right lane changes are harder to detect which is reasoned in the way they are executed, i.e. the
       variation is much larger compared to a left lane change. In order to improve the false positive
       rate, the a priori probability for a right lane change without turn signal indicator is set to zero. */
#if (SIT_CFG_LC_USE_TURN_INDICATOR_INPUT) 
    if (pt_SITOutput->t_LaneChangePhase.t_LCPhase == LC_PRELANECHANGE)
    {
      switch(t_TurnIndicator)
      {
      case eTurnIndicator_Left:
        f_BlinkerFactorRight = 0.0f;
        f_BlinkerFactorLeft = SIT_LC_BLINKER_PROB_FACTOR;
        break;
      case eTurnIndicator_Right:
        f_BlinkerFactorRight = SIT_LC_BLINKER_PROB_FACTOR;
        f_BlinkerFactorLeft = 0.0f;
        break;
      default:
        f_BlinkerFactorRight = 0.0f;
        f_BlinkerFactorLeft = 0.0f;
        break;

      }
    }
#endif
     if( fEgoSpeed <= SIT_LC_MIN_SPEED_KINEM)
     {
       fLCPaLeft   = SIT_LC_PROB_LOWSPEED + f_BlinkerFactorLeft;
       fLCPaRight  = SIT_LC_PROB_LOWSPEED + f_BlinkerFactorRight;
       fLCPaFollow = SIT_FOLLOW_PROB_MIDSPEED - f_BlinkerFactorRight -f_BlinkerFactorLeft;
     }
     else if( fEgoSpeed < SIT_LC_MID_SPEED_KINEM)
     {
       fLCPaLeft   = SIT_LC_PROB_MIDSPEED     + f_BlinkerFactorLeft;
       fLCPaRight  = SIT_LC_PROB_MIDSPEED     + f_BlinkerFactorRight;
       fLCPaFollow = SIT_FOLLOW_PROB_MIDSPEED - f_BlinkerFactorRight - f_BlinkerFactorLeft;
     }
     else 
     {
       fLCPaLeft   = SIT_LC_PROB_HIGHSPEED     + f_BlinkerFactorLeft;
       fLCPaRight  = SIT_LC_PROB_HIGHSPEED     + f_BlinkerFactorRight;
       fLCPaFollow = SIT_FOLLOW_PROB_HIGHSPEED - f_BlinkerFactorRight - f_BlinkerFactorLeft;
     }
 
    SIT_v_InitRoadParameters();

    /* Calculate all required input signals. Currently based on yaw rate and distance to road border */
    SIT_v_CalculateInputSignals(&fYawRate,&fRoadBorder,bRoadBorderValid,&fDMMRYaw,&fDMMRDist);

    /* Calculate lane change probability based on kinematic signals */
 
    /*************************************************************** 
     *    LEFT LANE CHANGE                                         *
     ***************************************************************/
    if ( (fYawRate > YAWRATE_LEFTLANECHANGE_LOWLIMIT)
      && (fYawRate < YAWRATE_LEFTLANECHANGE_HIGHLIMIT)
       )
    {
      /* Only calculate the lc prob for a yaw rate within given limits. Otherwise false alarm rate is very high */
      fLCYaw = SIT_f_CalcGEVDProb(fYawRate,SIT_LC_LEFT_YAW_RATE_K,SIT_LC_LEFT_YAW_RATE_SIGMA,SIT_LC_LEFT_YAW_RATE_MU);
    }
    else
    {
      fLCYaw = 0.0f;
    }
    fLCDMMRYaw  = SIT_f_CalcGEVDProb(fDMMRYaw,SIT_LC_LEFT_DMMR_YAW_RATE_K,SIT_LC_LEFT_DMMR_YAW_RATE_SIGMA,SIT_LC_LEFT_DMMR_YAW_RATE_MU);
    if(bRoadBorderValid != FALSE)
    {
      fLCDMMRDist = SIT_f_CalcGDProb(fDMMRDist,SIT_LC_LEFT_CUMSUM_DIST_ROAD_MU,SIT_LC_LEFT_CUMSUM_DIST_ROAD_SIGMA);
    }
    else
    {
      /* Road is not available. This should not affect the overall probability. */
      fLCDMMRDist = 1.0f;
    }
 
    fLCAflat    = SIT_f_CalcGEVDProb(afLatDiffFilterCurve,SIT_LC_LEFT_AFLAT_K,SIT_LC_LEFT_AFLAT_SIGMA,SIT_LC_LEFT_AFLAT_MU);

  
    f_LCProbLeft = fLCYaw * fLCDMMRYaw * fLCDMMRDist  * fLCAflat * fLCPaLeft;

    /*************************************************************** 
    *    RIGHT LANE CHANGE                                        *
    ***************************************************************/
    if ( ( fYawRate > YAWRATE_RIGHTLANECHANGE_LOWLIMIT )
      && ( fYawRate < YAWRATE_RIGHTLANECHANGE_HIGHLIMIT )
       )
    {
      /* Only calculate the lc prob for a yaw rate within given limits. Otherwise false alarm rate is very high */
      fLCYaw = SIT_f_CalcGEVDProb(fYawRate,SIT_LC_RIGHT_YAW_RATE_K,SIT_LC_RIGHT_YAW_RATE_SIGMA,SIT_LC_RIGHT_YAW_RATE_MU);
    }
    else
    {
      fLCYaw = 0.0f;
    }
    fLCDMMRYaw  = SIT_f_CalcGEVDProb(fDMMRYaw,SIT_LC_RIGHT_DMMR_YAW_RATE_K,SIT_LC_RIGHT_DMMR_YAW_RATE_SIGMA,SIT_LC_RIGHT_DMMR_YAW_RATE_MU);
    if(bRoadBorderValid != FALSE)
    {
      fLCDMMRDist = SIT_f_CalcGDProb(fDMMRDist,SIT_LC_RIGHT_CUMSUM_DIST_ROAD_MU,SIT_LC_RIGHT_CUMSUM_DIST_ROAD_SIGMA);
    }
    else
    {
      /* Road is not available. This should not affect the overall probability. */
      fLCDMMRDist = 1.0f;
    }
    fLCAflat    = SIT_f_CalcGEVDProb(afLatDiffFilterCurve,SIT_LC_RIGHT_AFLAT_K,SIT_LC_RIGHT_AFLAT_SIGMA,SIT_LC_RIGHT_AFLAT_MU);

    f_LCProbRight = fLCYaw * fLCDMMRYaw * fLCDMMRDist  * fLCAflat * fLCPaRight;

    /*************************************************************** 
     *    LANE FOLLOW                                              *
     ***************************************************************/
    fLCYaw      = SIT_f_CalcGDProb(fYawRate,SIT_LC_FOLLOW_YAW_RATE_MU,SIT_LC_FOLLOW_YAW_RATE_SIGMA);
    fLCDMMRYaw  = SIT_f_CalcGDProb(fDMMRYaw,SIT_LC_FOLLOW_DMMR_YAW_RATE_MU,SIT_LC_FOLLOW_DMMR_YAW_RATE_SIGMA);
    if(bRoadBorderValid != FALSE)
    {
      fLCDMMRDist = SIT_f_CalcGDProb(fDMMRDist,SIT_LC_FOLLOW_CUMSUM_DIST_ROAD_MU,SIT_LC_FOLLOW_CUMSUM_DIST_ROAD_SIGMA);
    }
    else
    {
      /* Road is not available. */
      fLCDMMRDist = 1.0f;
    }

    fLCAflat    = SIT_f_CalcGDProb(afLatDiffFilterCurve,SIT_LC_FOLLOW_AFLAT_MU,SIT_LC_FOLLOW_AFLAT_SIGMA);

    fLCProbFollow = fLCYaw * fLCDMMRYaw * fLCDMMRDist  * fLCAflat * fLCPaFollow;

    fLCProbSum = f_LCProbLeft + f_LCProbRight + fLCProbFollow;
  }
  else
  {
    /* We are too slow, thus the kinematic observer doesn't work reliably. Mostly caused by missing
      input such as a reliable road border estimation. */
    fLCProbSum = 0.0f;
  }


  if(fLCProbSum > CML_f_AlmostZero)
  {
    f_LCProbLeft   = f_LCProbLeft / fLCProbSum;
    f_LCProbRight  = f_LCProbRight / fLCProbSum;
    fLCProbFollow = fLCProbFollow / fLCProbSum;
  }
  else
  {
    /* The overall probabilities are close to zero. In order to keep the false positive rate happy
       we say its lane follow */
    f_LCProbLeft = 0.0f;
    f_LCProbRight = 0.0f;
    fLCProbFollow = 1.0f;
  }

  /* Calculate moving average for overall lane change probability */
  pt_SITOutput->t_LaneChangeKinStatic.fLCProbOverall = (SIT_LC_ALPHA_MAVERAGE * MAX(f_LCProbLeft,f_LCProbRight)) + ((1.f-SIT_LC_ALPHA_MAVERAGE) * pt_SITOutput->t_LaneChangeKinStatic.fLCProbOverall);
  /*  separating right and left probability calculation for each its own average for later observer fusion   */
  t_SITOutput.t_LaneChangeStatic.f_LCProbLeftAverage = (SIT_LC_ALPHA_MAVERAGE * f_LCProbLeft) + ((1.f-SIT_LC_ALPHA_MAVERAGE) * t_SITOutput.t_LaneChangeStatic.f_LCProbLeftAverage);
  t_SITOutput.t_LaneChangeStatic.f_LCProbRightAverage = (SIT_LC_ALPHA_MAVERAGE * f_LCProbRight) + ((1.f-SIT_LC_ALPHA_MAVERAGE) * t_SITOutput.t_LaneChangeStatic.f_LCProbRightAverage);
  /* end of probability calculation    */
  /* Determine the lane change state (LC_LEFT, LC_RIGHT, LC_FOLLOW) */


  /* Save probability */
  SITLCProbDataGlobal.fLCKinematicProb = 100.0f * pt_SITOutput->t_LaneChangeKinStatic.fLCProbOverall;

  SITLCProbDataGlobal.f_LCProbLeft     = t_SITOutput.t_LaneChangeStatic.f_LCProbLeftAverage;
  SITLCProbDataGlobal.f_LCProbRight    = t_SITOutput.t_LaneChangeStatic.f_LCProbRightAverage;
  SITLCProbDataGlobal.fLCProbFollow    = fLCProbFollow;

}

/*************************************************************************************************************************
  Functionname:    SIT_v_CalculateInputSignals                                                                      */ /*!

  @brief           Calculate additional input signals for the Bayes classifier

  @description     Calculate additional input signals for the Bayes classifier

                   @startuml
                   partition SIT_v_CalculateInputSignals{
                   start
                   : Calculate the moving average of yaw rate;
                   : Calculate the differential maximum minimum rate for yaw rate;
                   If (The road border information is sufficienly good) then (yes)
                   	: Calculate the differential maximum minumim rate for distance to road border;
                   Else
                   	: Make DMMR for distance to road border zero;
                   Endif
                   Stop
                   }
                   @enduml

  @return          -

  @param[in]       pfYawRate : Raw signal yaw rate                              [-100.f .. +100.f] rad/s
  @param[in]       pfDistToRoad :Raw signal distance to road border             [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @param[in]       bDistValid : Boolean DataType                                [TRUE FALSE]
  @param[out]      pfDMMRYaw  : Differential minimum maximum rate for yaw rate  [-100.f .. +100.f] rad/s 
  @param[out]      pfDMMRDist : Differential minimum maximum rate for distance  [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m

  @glob_in         fMovingAverageYawRate : Moving Average Yaw Rate [-100.f .. +100.f] rad/s
  @glob_out        fMovingAverageYawRate : Moving Average Yaw Rate [-100.f .. +100.f] rad/s

  @c_switch_part   -
  @c_switch_full   SIT_CFG_LC_PROB_CALC  : Configuration switch enabling lane change probability calculation 
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

  @author          Christopher Knievel-
*************************************************************************************************************************/
static void SIT_v_CalculateInputSignals(const float32* const pfYawRate, const float32* const pfDistToRoad, boolean bDistValid, float32* const pfDMMRYaw,  
                                     float32* const pfDMMRDist )
{ 
  /* Weighting for moving average */
  const float32 fAlpha = 0.1f;

  /* Calculate the moving average of yaw rate */
  pt_SITOutput->t_LaneChangeKinStatic.fMovingAverageYawRate = fAlpha * *pfYawRate + (1.f-fAlpha) * pt_SITOutput->t_LaneChangeKinStatic.fMovingAverageYawRate;

  /* Calculate the DMMR for yaw rate */
  *pfDMMRYaw = SIT_f_CalcDMMRYaw(*pfYawRate);

  /* Calculate the DMMR for distance to road border */
  if(bDistValid != FALSE)
  {
    *pfDMMRDist = SIT_f_CalcCUMSUMDistance(*pfDistToRoad);
  }
  else
  {
    *pfDMMRDist = 0.0f;
  }
}


#if 0

/*************************************************************************************************************************
  Functionname:    SIT_f_CalcLCSYaw                                                                                 */ /*!

  @brief           Calculate the longest common subsequence for yaw rate

  @description     Calculate the longest common subsequence for yaw rate.
                   The yaw rate is approximated for the left and right lane change as
                   well as for the lane follow case. The deviation of the measured yaw
                   rate to the approximated yaw rate is used.

                   @startuml
                   partition SIT_f_CalcLCSYaw{
                   start
                   : Depending on the received lane change type assign values to Alpha, Mean and Sigma;
                   If (Sigma > CML_f_AlmostZero) then (yes)
                   	: Calculate the reference curve value for left and right lane change;
                   Else (no)
                   	: Assign zero value to reference curve as there is no lane change;
                   Endif
                   If (Lane change type == LC_FOLLOW) then (yes)
                   	: Increment the static counter for reference curve;
                   Else (no)
                   Endif
                   : The difference of reference curve value and measured value is returned;
                   stop
                   @enduml

  @return          fRetVal : [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m

  @param[in]       fVal                           [Full Range of float32]
  @param[in]       fMeanOfSignal : Mean of signal [Full Range of float32]
  @param[in]       eLCType : Reference to SIT_LC_t_LaneChange as defined in sit_lanechange.h

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   SIT_CFG_LC_PROB_CALC  : Configuration switch enabling lane change probability calculation 
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
static float32 SIT_f_CalcLCSYaw(float32 fVal, float32 fMeanOfSignal, SIT_LC_t_LaneChange eLCType)
{
  float32 fRetVal;
  float32 fMean, fSigma, fAlpha;
  /* Reference curve value */
  float32 fRefCurveValue; 

  switch(eLCType)
  {
    case LC_LEFT:
      fAlpha = 0.03f;
      fMean = 20.f;
      fSigma = 8.f;
      break;
    case LC_RIGHT:
      fAlpha = -0.025f;
      fMean  = 13.f;
      fSigma = 13.f;
      break;
    case LC_FOLLOW:
    default:
      fAlpha = 0.0f;
      fMean =  0.0f;
      fSigma = 0.0f;
      break;
  }

  /* Calculate the reference value for left and right lane change */
  if(fSigma > CML_f_AlmostZero)
  {
    fRefCurveValue = 0.5f * GDBexp(SQR((uiRunIndexLCSYaw - fMean)/fSigma)) +  fMeanOfSignal;
  }
  else
  {
    /* In case of lane follow, a straight line is assumed */
    fRefCurveValue = 0.0f;
  }

  /* Increment static counter for reference curve.
     Only increment for the last case */
  if(eLCType == LC_FOLLOW)
  {
    uiRunIndexLCSYaw = (uiRunIndexLCSYaw % SIT_LC_LCS_YAW_COUNTER_MAX == 0) ? 0 : uiRunIndexLCSYaw + 1;
  }
  
  

  fRetVal = SQRT_(SQR(fRefCurveValue - fVal));

  return fRetVal;
}
#endif


/*************************************************************************************************************************
  Functionname:    SIT_f_CalcCUMSUMDistance                                                                         */ /*!

  @brief           Calculate the differential minimum maximum rate for distance to road border

  @description     Calculate the differential minimum maximum rate for distance to road border

                   @startuml
                   partition SIT_f_CalcCUMSUMDistance {
                   start
                   : Calculate difference between previous an current sample of distance to road border;
                   : Save the difference between previous and current sample of distance to road border in an array at same position as the index of distance to road border sample;
                   If (Array index for Distance to road border samples is more than threshold) then (yes)
                   	: Index is reset to zero;
                   Else
                   	: Increment the index;
                   endif
                   : Save the current sample for next cycle computation;
                   While (Number of road border samples are less than SIT_LC_CUMSUM_DIST_MAX_SAMPLES) is (yes)
                   	: Calculate the sum of all samples;
                   Endwhile
                   If (Sum value exceeds the threshold) then (yes)
                   : Reset the sum to zero;
                   Note right
                   To make sure the sum value is not overflowing
                   End note
                   Endif
                   Stop
                   }
                   @enduml

  @return          fRetVal : [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m

  @param[in]       fCurrentVal : Estimated Distance to side road boundary of current cycle                                                                  [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m

  @glob_in         SITLaneChangeCUMSUMDist.fLastValue   : Estimated Distance to side road boundary of Previous cycle                                        [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @glob_in         SITLaneChangeCUMSUMDist.uiRunIndex   : Index used to finding array position                                                              [0..SIT_LC_DMMR_YAW_MAX_SAMPLES]
  @glob_out        SITLaneChangeCUMSUMDist.fDMMRSamples : Array for storing difference between Distance to side road boundary of Previous and current cycle [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @glob_out        SITLaneChangeCUMSUMDist.fLastValue   : Estimated Distance to side road boundary of Previous cycle                                        [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @glob_out        SITLaneChangeCUMSUMDist.uiRunIndex   : Index used to finding array position                                                              [0..SIT_LC_DMMR_YAW_MAX_SAMPLES]

  @c_switch_part   -
  @c_switch_full   SIT_CFG_LC_PROB_CALC  : Configuration switch enabling lane change probability calculation 
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
static float32 SIT_f_CalcCUMSUMDistance(const float32 fCurrentVal)
{
  float32 fRetVal, fDiffVal;
  float32 fSumVal, f_Abs_SumVal;
  uint8 i, uiCurrentPos;

  /* Calculate the difference between previous and current sample */
  fDiffVal = pt_SITOutput->t_LaneChangeKinStatic.t_LaneChangeCUMSUMDist.fLastValue - fCurrentVal;

  /* Save current difference value */
  uiCurrentPos = pt_SITOutput->t_LaneChangeKinStatic.t_LaneChangeCUMSUMDist.uiRunIndex % SIT_LC_CUMSUM_DIST_MAX_SAMPLES;
  pt_SITOutput->t_LaneChangeKinStatic.t_LaneChangeCUMSUMDist.fDMMRSamples[uiCurrentPos] = fDiffVal;

  /* Increment counter and prevent overflow */
  if((uiCurrentPos == 0u) && (pt_SITOutput->t_LaneChangeKinStatic.t_LaneChangeCUMSUMDist.uiRunIndex > 0u))
  {
    pt_SITOutput->t_LaneChangeKinStatic.t_LaneChangeCUMSUMDist.uiRunIndex = 0u;
  }
  else
  {
    pt_SITOutput->t_LaneChangeKinStatic.t_LaneChangeCUMSUMDist.uiRunIndex++;
  }

  /* Save current value for the next cycle */
  pt_SITOutput->t_LaneChangeKinStatic.t_LaneChangeCUMSUMDist.fLastValue = fCurrentVal;

  /* Init sum value */
  fSumVal = 0.0f;
  for (i=0u; i<SIT_LC_CUMSUM_DIST_MAX_SAMPLES; i++)
  {
    fSumVal += pt_SITOutput->t_LaneChangeKinStatic.t_LaneChangeCUMSUMDist.fDMMRSamples[i];
  }

  /* Sanity check for summation value. If value is too large, it is likely that the road-border
     just changed to a new value or is not available. A summation value of zero results in a 
     higher probability for lane follow. */
  f_Abs_SumVal = fABS(fSumVal);
  if(f_Abs_SumVal >SIT_LC_CUMSUM_DIST_MAX_SUM)
  {
    fSumVal = 0.0f;
  }

  fRetVal = fSumVal;

  return fRetVal;
}


/*************************************************************************************************************************
  Functionname:    SIT_f_CalcDMMRYaw                                                                                */ /*!

  @brief           Calculate the differential minimum maximum rate for yaw rate.

  @description     Calculate the differential minimum maximum rate for yaw rate.

                   @startuml
                   partition SIT_f_CalcDMMRYaw {
                   start
                   : Calculate difference between previous an current sample of yaw rate;
                   : Save the difference between previous and current sample of yaw rate in an array at same position as the index of yaw rate sample;
                   If (Array index for yaw sample is more than SIT_LC_DMMR_YAW_MAX_SAMPLES) then (yes)
                   	: Index is reset to zero;
                   Else
                   	: Increment the index;
                   endif
                   : Save the current yaw sample for next cycle;
                   While (Number of yaw samples are less than SIT_LC_DMMR_YAW_MAX_SAMPLES) is (yes)
                   	: Calculate minimum of difference between consecutive yaw samples and minimum threshold;
                   	: Calculate maximum of difference between consecutive yaw samples and maximum threshold;
                   Endwhile
                   : DMMR Yaw is calculated as difference between maximum and minimum yaw sample;
                   
                   Stop
                   }
                   @enduml

  @return          fRetVal : [-100.f .. +100.f] rad/s

  @param[in]       fCurrentVal : Input Yawrate of current cycle [-100.f .. +100.f] rad/s

  @glob_in         SITLaneChangeDMMRYaw.fLastValue   : Input Yawrate of Last cycle [-100.f .. +100.f] rad/s
  @glob_in         SITLaneChangeDMMRYaw.uiRunIndex   : Index [0..SIT_LC_DMMR_YAW_MAX_SAMPLES]
  @glob_in         SITLaneChangeDMMRYaw.fDMMRSamples : Array for storing difference between previous and current sample Yawrate [-100.f .. +100.f] rad/s
  @glob_out        SITLaneChangeDMMRYaw.fLastValue   : Input Yawrate of Last cycle [-100.f .. +100.f] rad/s 

  @c_switch_part   -
  @c_switch_full   SIT_CFG_LC_PROB_CALC  : Configuration switch enabling lane change probability calculation 
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
static float32 SIT_f_CalcDMMRYaw(const float32 fCurrentVal)
{
  float32 fRetVal, fDiffVal;
  float32 fMinVal, fMaxVal;
  uint8 i, uiCurrentPos;

  /* Calculate the difference between previous and current sample */
  fDiffVal = pt_SITOutput->t_LaneChangeKinStatic.t_LaneChangeDMMRYaw.fLastValue - fCurrentVal;

  /* Save current difference value */
  uiCurrentPos = pt_SITOutput->t_LaneChangeKinStatic.t_LaneChangeDMMRYaw.uiRunIndex % SIT_LC_DMMR_YAW_MAX_SAMPLES;
  pt_SITOutput->t_LaneChangeKinStatic.t_LaneChangeDMMRYaw.fDMMRSamples[uiCurrentPos] = fDiffVal;

  /* Increment counter and prevent overflow*/
  if((uiCurrentPos == 0u) && (pt_SITOutput->t_LaneChangeKinStatic.t_LaneChangeDMMRYaw.uiRunIndex > 0u))
  {
    pt_SITOutput->t_LaneChangeKinStatic.t_LaneChangeDMMRYaw.uiRunIndex = 0u;
  }
  else
  {
    pt_SITOutput->t_LaneChangeKinStatic.t_LaneChangeDMMRYaw.uiRunIndex++;
  }

  /* Save current value for the next cycle */
  pt_SITOutput->t_LaneChangeKinStatic.t_LaneChangeDMMRYaw.fLastValue = fCurrentVal;

  /* Init min and max value */
  fMinVal = SIT_DMMRYAW_MINVAL;
  fMaxVal = 0.0f;

  /* Find min and max value within the last SIT_LC_DMMR_MAX_SAMPLES */
  for (i=0u; i<SIT_LC_DMMR_YAW_MAX_SAMPLES; i++)
  {
    fMinVal = MIN(fMinVal, pt_SITOutput->t_LaneChangeKinStatic.t_LaneChangeDMMRYaw.fDMMRSamples[i]);
    fMaxVal = MAX(fMaxVal, pt_SITOutput->t_LaneChangeKinStatic.t_LaneChangeDMMRYaw.fDMMRSamples[i]);
  }

  fRetVal = fMaxVal - fMinVal;

  return fRetVal;
}
///@}
#endif /* (SIT_CFG_LC_PROB_CALC) */

#endif /* (FCT_CFG_ACC_SITUATION) */
