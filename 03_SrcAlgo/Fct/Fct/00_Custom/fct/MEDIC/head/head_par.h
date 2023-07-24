/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 HEAD (Hypothesis Evaluation And Decision)

PACKAGENAME:               head_par.h

DESCRIPTION:               Header of the HEAD parameters 

AUTHOR:                    $Author: uia92763 $

CREATION DATE:             $Date: 2020/06/24 08:44:16CEST $

VERSION:                   $Revision: 1.2.11.4 $

LEGACY VERSION:            1.41.1.9

**************************************************************************** */
/**
@ingroup head_par
@{ **/

#ifndef _HEAD_PAR_H_INCLUDED
#define _HEAD_PAR_H_INCLUDED

/*****************************************************************************
INCLUDES
*****************************************************************************/
#include "head/head_cfg.h"
#include "frame_medic/medic_par.h"

#if (MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION)

/*****************************************************************************
(SYMBOLIC) CONSTANTS 
*****************************************************************************/
/*! @brief      Switch for the cross brake use */
#define HEAD_USE_CROSSING_BRK                 SWITCH_OFF

/*! @brief      Switch for the cross warn use */
#define HEAD_USE_CROSS_WARN                   SWITCH_OFF

/* Possibility to change function channel during activation */
/*! @brief      Switch for function channel change */
#define HEAD_USE_CHANGE_FUNCTIONCHANNEL       SWITCH_ON

/*! @brief      Switch to change unclassified objects into vehicles */
#define HEAD_DO_NOT_SET_CHANNEL_UNCLASSIFIED  SWITCH_OFF

/*! @brief      Switch which enables use of high eba quality lifetime  */
#define HEAD_USE_TIME_HIGH_OBJ_QUALITY        SWITCH_OFF

/*! @brief      HEAD_USE_ANEC_CTRL switch   
    @general    Use avoidance deceleration for closed loop control during 
                each level brake intervention   */
#define HEAD_USE_ANEC_CTRL                    SWITCH_ON

/*! @brief      HEAD_HBA_VDS_USE_CUST_ANECLONG switch   
    @general    Use ANecLong custom for HBA_VDS */
#define HEAD_HBA_VDS_USE_CUST_ANECLONG         SWITCH_OFF

/*! @brief      HEAD_USE_RAMP_BRK switch
    @general    Use ramping of the acceleration request in the brake function */
#define HEAD_USE_RAMP_BRK                      SWITCH_ON

/*! @brief      HEAD_USE_GRADIENT_LIMITATION switch
    @general    Use limitation of the gradient of the requested brake acceleration */
#define HEAD_USE_GRADIENT_LIMITATION           SWITCH_OFF

/*! @brief      Use TTM LONG - this config switch is doubled from CD! */
#define HEAD_USE_TTM_LONG                      SWITCH_OFF

/*! @brief Use custom Systemfuction */ 
#define HEAD_USE_CUSTOM_SYSTEMFUNCTION  (SWITCH_OFF)

/* Assumed default values, in case of invalid input signals */

/*! @brief      Default value of HEAD Longitudinal Velocity 
    @general    HEAD actual Ego Velocity
    @conseq     -
    @attention  -
    @typical 0  @unit  m/s   @min -   @max - */
#define HEAD_DEFAULT_LongVelocity              (0)

/*! @brief      Default value of HEAD Longitudinal Acceleration 
    @general    HEAD actual Ego Acceleration
    @conseq     -
    @attention  -
    @typical 0  @unit  m/s^2   @min -   @max - */
#define HEAD_DEFAULT_LongAccel                 (0)

/*! @brief      Default value of lateral curvature of ego trajectory 
    @general    HEAD actual Ego lateral curvature
    @conseq     -
    @attention  -
    @typical 0  @unit  1/m   @min -   @max -  */
#define HEAD_DEFAULT_EgoLatCur                 (0)

/*! @brief      Default value of safe object distance for safety functions 
    @general    -
    @conseq     -
    @attention  -
    @typical 0  @unit  m   @min -   @max - */
#define HEAD_DEFAULT_SafeObjDistance           (0)

/*! @brief      Default value of safe object distance for performance functions 
    @general    -
    @conseq     -
    @attention  -
    @typical 200  @unit  m   @min -   @max - */
#define HEAD_DEFAULT_PerfObjDistance      (200.0f)

/*! @brief      Default value of DIM Attention Probability
    @general    Actual value of DIM attention probability
    @conseq     -
    @attention  -
    @typical 0  @unit  -   @min -   @max - */
#define HEAD_DEFAULT_DriverAttentionProb       (0)

/*! @brief      Default value of DIM Attention Confidence
    @general    Actual value of DIM attention confidence
    @conseq     -
    @attention  -
    @typical 0  @unit  -   @min -   @max - */
#define HEAD_DEFAULT_DriverAttentionConf       (0)

/*! @brief      Default value of DIM Activity Probability
    @general    Actual value of DIM activity probability
    @conseq     -
    @attention  -
    @typical 0  @unit  -   @min -   @max - */
#define HEAD_DEFAULT_DriverActivityProb        (0)

/*! @brief      Default value of DIM Activity Confidence
    @general    Actual value of DIM activity confidence
    @conseq     -
    @attention  -
    @typical 0  @unit  -   @min -   @max - */
#define HEAD_DEFAULT_DriverActivityConf        (0)

/*! @brief      Default value of DIM Feedback Probability
    @general    Actual value of DIM feedback probability
    @conseq     -
    @attention  -
    @typical 0  @unit  -   @min -   @max - */
#define HEAD_DEFAULT_DriverFeedbackProb        (0)

/*! @brief      Default value of DIM Feedback Confidence
    @general    Get default quality  signal state 
    @conseq     -
    @attention  -
    @typical 0  @unit  -   @min -   @max -  */
#define HEAD_DEFAULT_DriverFeedbackConf        (0)

/*! @brief      DIM hypothesis normal confidence value
    @general    The quality of signal state ok
    @conseq     -
    @attention  -
    @typical 100  @unit  -   @min -   @max -  */
#define HEAD_DM_HYP_NORMAL_CONFIDENCE ((percentage_t)(100u))

/*! @brief      DIM hypothesis minimum confidence value
    @general    Get bad quality of input signal state 
    @conseq     -
    @attention  -
    @typical 70  @unit  -   @min -   @max -   */
#define HEAD_DM_HYP_MIN_CONFIDENCE ((percentage_t)(70u))

/*! @brief Absolute steering wheel angle. */
#define HEAD_DEFAULT_SteeringAngle                      (0)

/*! @brief Set to TRUE if and only if the steering wheel is rotated in the direction of the active turn indicator. */
#define HEAD_DEFAULT_TurnIndicatorInSteeringDirection   (FALSE)

/*! @brief Position of the gas pedal in percent */ 
#define HEAD_DEFAULT_GasPedal                           (0)

/* Head calibration support for hand code parameters */
#if (MEDIC_CFG_ENABLE_RAM_PARAM)

/*! @brief       HEAD_DECL_PARAM(type_, name_)
    @general     HEAD_DECL_PARAM(type_, name_) if MEDIC_CFG_ENABLE_RAM_PARAM is true
    @conseq      @incp  
                 @decp  
    @attention   [None]
    @typical     FCT_DECL_ADJ_PARAM(type_, name_)
    @unit        SI-unit */
#define HEAD_DECL_PARAM(type_, name_)           MEDIC_DECL_ADJ_PARAM(type_, name_)

/*! @brief       HEAD_DECL_PARAM(type_, name_, value_)
    @general     HEAD_DECL_PARAM(type_, name_, value_) if MEDIC_CFG_ENABLE_RAM_PARAM is true
    @conseq      @incp  
                 @decp  
    @attention   [None]
    @typical     FCT_DECL_ADJ_PARAM(type_, name_, value_)
    @unit        SI-unit */
#define HEAD_DEF_PARAM(type_, name_, value_)    MEDIC_DEF_ADJ_PARAM(type_, name_, value_)

/*! @brief       HEAD_PAR_CONST
    @general     HEAD_PAR_CONST if MEDIC_CFG_ENABLE_RAM_PARAM is true
    @conseq      @incp  
                 @decp  
    @attention   [None]
    @typical     [None]
    @unit        SI-unit */
#define HEAD_PAR_CONST                           
#else
/*! @brief       HEAD_DECL_PARAM(type_, name_)
    @general     HEAD_DECL_PARAM(type_, name_)  if MEDIC_CFG_ENABLE_RAM_PARAM is false
    @conseq      @incp  
                 @decp  
    @attention   [None]
    @typical     FCT_DECL_FIX_PARAM(type_, name_)
    @unit        SI-unit */
#define HEAD_DECL_PARAM(type_, name_)           FCT_DECL_FIX_PARAM(type_, name_)

/*! @brief       HEAD_DECL_PARAM(type_, name_, value_)
    @general     HEAD_DECL_PARAM(type_, name_, value_)  if MEDIC_CFG_ENABLE_RAM_PARAM is false
    @conseq      @incp  
                 @decp  
    @attention   [None]
    @typical     FCT_DEF_FIX_PARAM(type_, name_, value_)
    @unit        SI-unit */
#define HEAD_DEF_PARAM(type_, name_, value_)    MEDIC_DEF_FIX_PARAM(type_, name_, value_)

/*! @brief       HEAD_PAR_CONST
    @general     HEAD_PAR_CONST  if MEDIC_CFG_ENABLE_RAM_PARAM is false
    @conseq      @incp  
                 @decp  
    @attention   [None]
    @typical     const
    @unit        SI-unit */
#define HEAD_PAR_CONST const
#endif

/*! @brief      Parameter for latent warning factors, which depends on country code settings
    @conseq     @incp  Earlier point in time of warning
                @decp  Later point in time of warning
    @typical 1.0  @unit  -   @min 0.1   @max 2.0 */
#define HEAD_PAR_LATPREEARLYFACT_CNTR0 (0.9f)  /*!< Early warning factor country 0 */
#define HEAD_PAR_LATPREEARLYFACT_CNTR1 (1.0f)  /*!< Early warning factor country 1 */
#define HEAD_PAR_LATPRELATEFACT_CNTR0  (0.7f)  /*!< Normal warning factor country 0 */
#define HEAD_PAR_LATPRELATEFACT_CNTR1  (1.0f)  /*!< Normal warning factor country 1 */

/*! @brief      Max. permitted jerk for transition from deactivated iBrk5 to active iBrk5
    @conseq     @incp  Higher change rate of output deceleration
                @decp  Lower change rate of output deceleration
    @typical 5.0  @unit  m/s^3   @min 0.1   @max 10.0   */
#define HEAD_MAX_GRAD_IB5_TO_3 (5.0f)

/*! @brief      Low speed threshold, used for coding parameter to disable function at low speed
    @conseq     @incp  head modules gets active at higher ego velocity
                @decp  head modules gets active at lower ego velocity
    @attention  This parameter is only active if coding parameter "low speed active" is disabled
    @typical 10.0  @unit  m/s   @min 0.0   @max 20.0   */
#define HEAD_PAR_EGO_THRSHOLD_LOW_SPEED_CODING (10.0f)

/*! @brief      Velocity interval around zero of absolute (vrel+vego) object velocity 
    @general    If absolute object velocity is inside, to the object will be classified stopped, 
                otherwise is moving
    @conseq     @incp  Interval for stopped classification is wider
                @decp  Interval for stopped classification is closer
    @attention  This effective for dynamic pre and accute warning, defining the warning type
    @typical 1.0  @unit  m/s   @min 0.0   @max 5.0   */
#define HEAD_PAR_OBJ_STOPPED_VABS_ERROR (1.0F)

/*! @brief      Precrash time-to-collision latency
    @general    Latency time in the perspective of pre-crash function, probably caused by
                different relevant location in car and expected mechanical deformations
    @conseq     @incp  Increase pre-crash ttc output value
                @decp  Decrease pre-crash ttc output value
    @attention  This effective for dynamic pre and accute warning, defining the warning type
    @typical 0.0  @unit  s   @min 0.0   @max 0.5   */
#define HEAD_PAR_PRECRASH_TTC_LATENCY   (0.0F)

/*! @brief      Max. allowed distance to brake
    @general    Maxim allowed long. object distance where pre-braking is started
    @conseq     @incp  Earlier braking during run-up
                @decp  Later braking during run-up
    @attention  -
    @typical 100  @unit  m   @min 0.0   @max 200   */
#define HEAD_PAR_MAX_BRAKE_DISTANCE  HeadParMaxBrakeDistance_c

/*! @brief       HEAD_PAR_MAX_BRAKE_DISTANCE_VALUE
    @general     Define the maximum level of brake depends on distance
    @conseq      @incp  
                 @decp  
    @attention   [None]
    @typical     100.0
    @unit        SI-unit  */
#define HEAD_PAR_MAX_BRAKE_DISTANCE_VALUE 200.0F
HEAD_DECL_PARAM(MEMSEC_REF float32, HEAD_PAR_MAX_BRAKE_DISTANCE)

/*! @brief       HEAD_PAR_MAX_VIDEO_SELF_CONF_DIST
    @general     Max Distance to Object and min Object Quality to keep Object Quality high
    @conseq      @incp  
                 @decp  
    @attention   [None]
    @typical     HeadParMaxVidSelfConfDist_c
    @unit        SI-unit  */
#define HEAD_PAR_MAX_VIDEO_SELF_CONF_DIST  HeadParMaxVidSelfConfDist_c 

/*! @brief       HEAD_PAR_MAX_VIDEO_SELF_CONF_DIST_VALUE
    @general     Maximum video self Confidence depends on the distance  
    @conseq      @incp  
                 @decp  
    @attention   [None]
    @typical     3.0
    @unit        SI-unit  */
#define HEAD_PAR_MAX_VIDEO_SELF_CONF_DIST_VALUE  3.0F

/*! @brief       HEAD_PAR_MIN_VIDEO_SELF_OBJ_QUAL_VALUE
    @general     Minimum video self confidence obeject quality
    @conseq      @incp  
                 @decp  
    @attention   [None]
    @typical     89.0
    @unit        SI-unit  */
#define HEAD_PAR_MIN_VIDEO_SELF_OBJ_QUAL_VALUE  89.0F

/*! @brief       HEAD_PAR_MAX_VIDEO_SELF_OBJ_QUAL_VALUE
    @general     Maximum video self confidence  obeject quality
    @conseq      @incp  
                 @decp  
    @attention   [None]
    @typical     100.0
    @unit        SI-unit  */
#define HEAD_PAR_MAX_VIDEO_SELF_OBJ_QUAL_VALUE 100.0F
HEAD_DECL_PARAM(float32, HEAD_PAR_MAX_VIDEO_SELF_CONF_DIST)

/*! @brief      LAT_PRE_DIST_OVER_VELOCITY_TAB_POINTS
    @general    Number of table entries for distance over velocity in 
                module latent pre-warning
    @conseq     -
    @attention  -
    @typical 6  @unit  -   @min -   @max -   */
#define LAT_PRE_DIST_OVER_VELOCITY_TAB_POINTS        (6u)

/*! @brief      LAT_PRE_DIST_OVER_VELOCITY_DEF_VELO
    @general    Default input velocity for distance over velocity table 
                in module latent pre-warning
    @conseq     -
    @attention  -
    @typical 20  @unit  m/s   @min -   @max -   */
#define LAT_PRE_DIST_OVER_VELOCITY_DEF_VELO        (20.F)

/*! @brief      LAT_ACUTE_DIST_OVER_VELOCITY_TAB_POINTS
    @general    Number of table entries for distance over velocity in
                module latent acute-warning
    @conseq     -
    @attention  -
    @typical 6  @unit  m/s   @min -   @max -   */
#define LAT_ACUTE_DIST_OVER_VELOCITY_TAB_POINTS        (6u)

/* Default input velocity for distance over velocity table in module latent acute-warning */

/*! @brief      LAT_ACUTE_DIST_OVER_VELOCITY_DEF_VELO
    @general    Default input velocity for distance over velocity table
                in module latent acute-warning
    @conseq     -
    @attention  -
    @typical 20  @unit  m/s   @min -   @max -   */
#define LAT_ACUTE_DIST_OVER_VELOCITY_DEF_VELO        (20.F)

/* Parameters to prevent function deactivation during unintentional driver acceleration due to 
   function activation (weak negative feedback) */

/*! @brief      HEAD_DRV_FDBCK_IGNORE_MIN_ACT_TIME
    @general    min. time elapsed after function activation to detect 
                unintentional weak negative feedback
    @conseq     -
    @attention  -
    @typical 0.0F  @unit  -   @min -   @max -   */
#define HEAD_DRV_FDBCK_IGNORE_MIN_ACT_TIME         (0.0F)  

/*! @brief      HEAD_DRV_FDBCK_IGNORE_MAX_ACT_TIME
    @general    max. time elapsed after function activation to detect 
                unintentional weak negative feedback
    @conseq     -
    @attention  -
    @typical 0.5F  @unit  -   @min -   @max -   */
#define HEAD_DRV_FDBCK_IGNORE_MAX_ACT_TIME         (0.5F)

/*! @brief      HEAD_DRV_FDBCK_IGNORE_DURATION 
    @general    max. time-out to ignore weak feedback after detection
    @conseq     -
    @attention  -
    @typical 1.0F  @unit  -   @min -   @max -   */
#define HEAD_DRV_FDBCK_IGNORE_DURATION             (1.0F)

/*! @brief      HEAD_DRV_FDBCK_FILTER_WEAK_PROB_MIN 
    @general    minimum driver feedback probability which will be filtered
    @conseq     -
    @attention  -
    @typical -90  @unit  -   @min -   @max -   */
#define HEAD_DRV_FDBCK_FILTER_WEAK_PROB_MIN        (-90)

/*! @brief      HEAD_DRV_FDBCK_FILTER_WEAK_PROB_MAX 
    @general    maximum driver feedback probability which will be filtered
    @conseq     -
    @attention  -
    @typical -70  @unit  -   @min -   @max -   */
#define HEAD_DRV_FDBCK_FILTER_WEAK_PROB_MAX        (-70)

/*! @brief      HEAD_DRV_FDBCK_FILTER_IGNORE_PROB 
    @general    output probability during active filtering
    @conseq     -
    @attention  -
    @typical -50  @unit  -   @min -   @max -   */
#define HEAD_DRV_FDBCK_FILTER_IGNORE_PROB          (-50)

/* Warning parameters values dependent on encoded pre-brake function. Parameters values 
   are different due to availability of sensor fusion */

/*! @brief      HEAD_PAR_NO_FUSION_VAR  
    @general    Number of encoding variants
    @conseq     -
    @attention  -
    @typical 2  @unit  -   @min -   @max -   */
#define HEAD_PAR_NO_FUSION_VAR               2

/*! @brief      HEAD_Switch_Function_Nr
    @general    Number of the functions, which could be switched (DW, FCW1, FCW2, FCW3, BRK)
    @conseq     -
    @attention  -
    @typical 5  @unit -   @min -   @max -   */
#define HEAD_Switch_Function_Nr        (5u)

/*! @brief      HEAD_Switch_Object_Type_Nr
    @general    Number of the defined object types for switches (Veh, Vru)
    @conseq     -
    @attention  -
    @typical 2  @unit -   @min -   @max -   */
#define HEAD_Switch_Object_Type_Nr        (2u)

/*! @brief      HEAD_Coding_Object_Type_Nr
    @general    Number of the defined object types for codings (Veh, Ped, Cycl, Obs)
    @conseq     -
    @attention  -
    @typical 4  @unit -   @min -   @max -   */
#define HEAD_Coding_Object_Type_Nr        (4u)

/*! @brief      HEAD_Coding_Object_Mov_Nr
    @general    Number of the defined object Movement Types for codings (Mov, Stat)
    @conseq     -
    @attention  -
    @typical 2  @unit -   @min -   @max -   */
#define HEAD_Coding_Object_Mov_Nr        (2u)

/*! @brief      HEAD_USE_ABSOLUTE_VEL_FOR_XING_SIGNAL switch   
    @general    Calculate vAbsY for crossing direction determination */
#define HEAD_USE_ABSOLUTE_VEL_FOR_XING_SIGNAL   (SWITCH_OFF)

/*! @brief      HEAD_EGO_YAWRATE_COMPENSATION 
    @general    Ego yawrate compensation. Distance from rear axle to sensor.
    @conseq     -
    @attention  -
    @typical 3.75f  @unit  m   @min 0.0f   @max -   */
#define HEAD_EGO_YAWRATE_COMPENSATION    (3.75f)

/* Dynamic pre-warning parameters */

/*! @brief      Dynamic pre-warning TTB early state */
#define HEAD_PAR_DYNPRE_TTBPRE_EARLY_STAT    DynPreTTBPreEarlyStat_c

/*! @brief      Dynamic pre-warning TTB later state */
#define HEAD_PAR_DYNPRE_TTBPRE_LATE_STAT     DynPreTTBPreLateStat_c

/*! @brief      Dynamic pre-warning TTS early */
#define HEAD_PAR_DYNPRE_TTSPRE_EARLY         DynPreTTSPreEarly_c

/*! @brief      Dynamic pre-warning TTS late */
#define HEAD_PAR_DYNPRE_TTSPRE_LATE          DynPreTTSPreLate_c 

/* Dynamic acute warning parameters */

/*! @brief      Dynamic acute-warning TTB acute state */
#define HEAD_PAR_DYNACUTE_TTBACUTE_STAT      DynAcuteTTBAcuteStat_c

/*! @brief      Dynamic acute-warning TTS acute */
#define HEAD_PAR_DYNACUTE_TTSACUTE           DynAcuteTTSAcute_c 

/* Haptic acute warn parameters */

/*! @brief      lowest threshold to enable sensitivity state to high

*/
#define HEAD_PAR_HAPTACUWARN_SENS_HIGH_THRS         (-6)

/*! @brief      lowest threshold to enable sensitivity state to mid

*/
#define HEAD_PAR_HAPTACUWARN_SENS_MID_THRS          (-4)

/*! @brief      lowest threshold to enable sensitivity state to low

*/
#define HEAD_PAR_HAPTACUWARN_SENS_LOW_THRS          (-2)
/* Pedestrian parameters */

/*! @brief       HEAD_PAR_PED_LEVEL1_MAX_DECEL_MPSS
    @general     Maximum deceleration level for pedestrian1
    @conseq      @incp  
                 @decp  
    @attention   [None]
    @typical     -4.0
    @unit        SI-unit   */
#define HEAD_PAR_PED_LEVEL1_MAX_DECEL_MPSS  (-4.0F)

/*! @brief      Max. permitted jerk for transition from deactivated to active Pedestrian LV2 brake
    @conseq     @incp  Higher change rate of output deceleration
                @decp  Lower change rate of output deceleration
    @typical 5.0  @unit  m/s^3   @min 0.1   @max 10.0   */
#define HEAD_MAX_GRAD_PED_LV2_TO_LV1 (5.0f)

/*! @brief      HEAD_MIN_DECEL_PREBRAKEEMERGENCY  
    @general    Minimum required deceleration to set PreBrakeEmergency- Flag
    @conseq     -
    @attention  -
    @typical -4.4f  @unit  -   @min -   @max -   */
#define HEAD_MIN_DECEL_PREBRAKEEMERGENCY  (-4.4f)

/* maximum allowed total speed reduction for pedestrian braking and general braking */
/*! @unit m/s */
#define HEAD_PAR_MAX_VELO_RED (70.0f)/*!< used in outputfunctions PreBrake and FullBrake */
#define HEAD_PAR_MAX_VELO_RED_PED (70.0f)/*!< used in outputfunctions PedPreBrake */

/* time gap between request to ramp out and start of actual decrease of braking deceleration */
/*! @unit s */
#define HEAD_PAR_BRAKE_REAC_TIME (0.25f)/*!< used in outputfunctions PreBrake, PedPreBrake and FullBrake */

/*! @brief       Maximum absolute steering wheel movement
    @general     Maximum absolute steering wheel movement
    @conseq      @incp  -
                 @decp  -
    @attention   -
    @typical     -   @unit deg     @min -   @max -   */
#define HEAD_PAR_STANDSTILL_MAX_STEER_WHEEL_MOVE      (90.f)

/*! @brief       Maximum gas pedal movement
    @general     Maximum gas pedal movement
    @conseq      @incp  -
                 @decp  -
    @attention   -
    @typical     -   @unit percent     @min -   @max -   */
#define HEAD_PAR_STANDSTILL_MAX_GAS_PEDAL_MOVE        (70.f)

/*! @brief       Maximum gas pedal position
    @general     Maximum gas pedal position
    @conseq      @incp  -
                 @decp  -
    @attention   -
    @typical     -   @unit percent     @min -   @max -   */
#define HEAD_PAR_STANDSTILL_MAX_ACC_PEDAL_POS         (90.0f)

/*! @brief       Maximal observation time
    @general     Maximal observation time
    @conseq      @incp  -
                 @decp  -
    @attention   -
    @typical     -   @unit s     @min -   @max -   */
#define HEAD_PAR_MAX_OBS_TIME                         (999.f)

/*! @brief       Hold time for standstill
    @general     Hold time for standstill
    @conseq      @incp  -
                 @decp  -
    @attention   -
    @typical     -   @unit s     @min -   @max -   */
#define HEAD_PAR_STANDSTILL_HOLD_TIME_STAT_MAX        (2.0f)

/* Maximal observation time */
/*! @brief       Deceleration value for standstill
    @general     Deceleration value for standstill
    @conseq      @incp  -
                 @decp  -
    @attention   -
    @typical     -   @unit m/s2     @min -   @max -   */
#define HEAD_PAR_STANDSTILL_REQ_DECEL_VAL             (-2.0f)

/*! @brief  Switch for using the release of brake pedal for the deactivation of standstill module */
#define HEAD_STANDSTILL_DEACT_USE_BRAKE               (SWITCH_ON)
/*! @brief  Switch for using the movement of brake steering wheel for the deactivation of standstill module */
#define HEAD_STANDSTILL_DEACT_USE_STEER_ANGLE_MOVE    (SWITCH_ON)
/*! @brief  Switch for using the movement of gas pedal for the deactivation of standstill module */
#define HEAD_STANDSTILL_DEACT_USE_GAS_PEDAL_MOVE      (SWITCH_ON)
/*! @brief  Switch for using the gas pedal position for the deactivation of standstill module */
#define HEAD_STANDSTILL_DEACT_USE_GAS_PEDAL_POS       (SWITCH_ON)
/*! @brief  Switch for using the detection of kick down for the deactivation of standstill module */
#define HEAD_STANDSTILL_DEACT_USE_KICK_DOWN           (SWITCH_OFF)

/*! Costom mapping for early, middle, late and ACC HEAD Main Mode setting. Assign here which HEAD mode 
    shall be set as INIT mode and depending on the different input states */

/*! @brief      HEAD mode setting for early state */
#define HEAD_PAR_MODE_SETTING_EARLY   ((HEADMainMode_t) HEADMainMode_Early)

/*! @brief      HEAD mode setting for middle state */
#define HEAD_PAR_MODE_SETTING_MIDDLE  ((HEADMainMode_t) HEADMainMode_Middle)

/*! @brief      HEAD mode setting for late state */
#define HEAD_PAR_MODE_SETTING_LATE    ((HEADMainMode_t) HEADMainMode_Late)

/*! @brief      HEAD mode setting for ACC state */
#define HEAD_PAR_MODE_SETTING_ACC     ((HEADMainMode_t) HEADMainMode_ACC)

/*! @brief      HEAD mode setting for INIT mode */
#define HEAD_PAR_MODE_SETTING_INIT    ((HEADMainMode_t) HEADMainMode_Middle)

/*! @brief      Generic Object limitation (unclassified) */
#define HEAD_PAR_OBJ_MAX_DECEL_MPSS  (-4.0F)

// Module Mapping to Autocode Names

/*! @brief      Total number of Head modules */
#define HEAD_MOD_NO_MODULE         (uint32) 255u

/*! @brief      Head module lat pre warning */
#define HEAD_MOD_LAT_PRE_WARN      (uint32) HEAD_AUTOCODE_MOD_LatPreWarn

/*! @brief      Head module lat acute warning */
#define HEAD_MOD_LAT_ACU_WARN      (uint32) HEAD_AUTOCODE_MOD_LatAcuteWarn

/*! @brief      Head module vehicle dynamic pre warning */
#define HEAD_MOD_VEH_DYN_PRE_WARN  (uint32) HEAD_AUTOCODE_MOD_DynPreWarn

/*! @brief      Head module vehicle dynamic acute warning */
#define HEAD_MOD_VEH_DYN_ACU_WARN  (uint32) HEAD_AUTOCODE_MOD_DynAcuteWarn

/*! @brief      Head module vehicle pre fill */
#define HEAD_MOD_VEH_PREFILL       (uint32) HEAD_AUTOCODE_MOD_Prefill

/*! @brief      Head module vehicle brake level1 */
#define HEAD_MOD_VEH_BRK_LV1       (uint32) HEAD_AUTOCODE_MOD_Veh_AutoBrk1

/*! @brief      Head module vehicle brake level2 */
#define HEAD_MOD_VEH_BRK_LV2       (uint32) HEAD_AUTOCODE_MOD_Veh_AutoBrk2

/*! @brief      Head module vehicle brake level3 */
#define HEAD_MOD_VEH_BRK_LV3       (uint32) HEAD_AUTOCODE_MOD_Veh_AutoBrk3

/*! @brief      Head module vehicle HBA */
#define HEAD_MOD_VEH_HBA_TA           (uint32) HEAD_AUTOCODE_MOD_HBA_TA

/*! @brief      Head module vehicle HBA VDS */
#define HEAD_MOD_VEH_HBA_VDS           (uint32) HEAD_AUTOCODE_MOD_HBA_VDS

/*! @brief      Head module pedestrian dynamic pre warning */
#define HEAD_MOD_PED_DYN_PRE_WARN  (uint32) HEAD_MOD_NO_MODULE

/*! @brief      Head module pedestrian dynamic acute warning */
#define HEAD_MOD_PED_DYN_ACU_WARN  (uint32) HEAD_AUTOCODE_MOD_CrossVru_DynAcuteWarn

/*! @brief      Head module pedestrian prefill */
#define HEAD_MOD_PED_PREFILL       (uint32) HEAD_AUTOCODE_MOD_CrossVru_Prefill

/*! @brief      Head module pedestrian brake level1 */
#define HEAD_MOD_PED_BRK_LV1       (uint32) HEAD_AUTOCODE_MOD_CrossVru_PreBrk

/*! @brief      Head module pedestrian brake level2 */
#define HEAD_MOD_PED_BRK_LV2       (uint32) HEAD_AUTOCODE_MOD_CrossVru_PreBrk2

/*! @brief      Head module pedestrian brake level3 */
#define HEAD_MOD_PED_BRK_LV3       (uint32) HEAD_MOD_NO_MODULE

/*! @brief      Head module pedestrian HBA */
#define HEAD_MOD_PED_HBA           (uint32) HEAD_AUTOCODE_MOD_CrossVru_HBA

/*! @brief      Head module Longitudinal VRU brake level1 */
#define HEAD_MOD_LONGVRU_BRK_LV1       (uint32) HEAD_AUTOCODE_MOD_LongVru_Brk1 

/*! @brief      Head module Longitudinal VRU brake level2 
    @typical @ref HEAD_AUTOCODE_MOD_LongVru_Brk2*/
#define HEAD_MOD_LONGVRU_BRK_LV2       (uint32) HEAD_AUTOCODE_MOD_LongVru_Brk2

/*! @brief      Head module Long VRU dynamic acute warning 
    @typical @ref HEAD_AUTOCODE_MOD_LongVru_DynAcuteWarn*/
#define HEAD_MOD_Long_PED_DYN_ACU_WARN  (uint32) HEAD_AUTOCODE_MOD_LongVru_DynAcuteWarn

/*! @brief      Head module Long VRU prefill 
    @typical @ref HEAD_AUTOCODE_MOD_LongVru_Prefill*/
#define HEAD_MOD_Long_PED_PREFILL       (uint32) HEAD_AUTOCODE_MOD_LongVru_Prefill

#if HEAD_CFG_TURN_ASSIST
/*! @brief      Pre-Brake deceleration requested by the Turn Assist.
    @typical -14.0  @unit  m/s^2 */
#define HEAD_PAR_PRE_BRAKE_DECELERATION_FOR_TURN_ASSIST (-14.0f)
#endif /* HEAD_CFG_TURN_ASSIST */

/*! @brief      If the absolute steering wheel angle exceeds this threshold in the direction opposite of the active turn indicator,
    it is assumed that the activated turn indicator and the direction of steering do not match.
    @typical 5.0  @unit  degrees  */
#define HEAD_PAR_TURN_INDICATOR_IN_STEERING_DIRECTION_STEERING_WHEEL_ANGLE_THRESHOLD (5.0f)

/*! @brief      brake pressure
    @typical 3.0  @unit  bar  */
#define HEAD_PAR_Brake_Pressure_THRESHOLD (3.0f)



/*! @brief  Application specific customer Parameter 6 to check Inhibition from FPS for  EBA activations in CrossVru Scenarios when difference in kinematics between Camera and Radar is huge*/
#define HEAD_CUST_FPS_INHIBITION_MASK_CHECK     HEADHypOutType_CustomPar_00

/*! @brief  Application specific customer Parameter 6 for checking Hypothesis Lifetime in Car to Car Scenarios*/
#define HEAD_CUST_PAR_Hypo_Lifetime     HEADHypOutType_CustomPar_01

/*! @brief  Custom parameter for table distance over vrelX
    @typical 21   -       */
#define HEAD__OBJ_LT_HQ      HEADHypOutType_CustomPar_02

/*! @brief  Custom parameter for table distance over vrelX
    @typical 22   -       */
#define HEAD_CUST_PAR_DRV_FDBCK  HEADHypOutType_CustomPar_03

/*! @brief  Application specific customer Parameter 4 for checking Steering Gradient of the Ego vehicle in LongVru Scenario*/
#define HEAD_CUST_PAR_STEER_GRAD       HEADHypOutType_CustomPar_04

/*! @brief  Application specific customer Parameter 5 for checking Stopped Ped or Bicycle in CrossVru Scenarios*/
#define HEAD_CUST_PAR_OBJ_CORRIDOR     HEADHypOutType_CustomPar_05

/*! @brief  Application specific customer Parameter 6 for checking object sensor source*/
#define HEAD_CUST_PAR_OBJ_SENSOURCE    HEADHypOutType_CustomPar_06

/*! @brief  Application specific customer Parameter 7 for checking Object velocity abs Y*/
#define HEAD_CUST_PAR_OBJ_VRELY     HEADHypOutType_CustomPar_07

/*! @brief  Application specific customer Parameter 6 for checking object sensor source*/
#define HEAD_CUST_PAR_OBJ_VABSX    HEADHypOutType_CustomPar_08
/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/

/*****************************************************************************
  GLOBAL CONSTANTS (EXTERNAL SCOPE)
*****************************************************************************/

/* Latent pre-warning: tables for object distance over velocity dependent on country and driver settings */
extern MEMSEC_REF HEAD_PAR_CONST float32 LatPreDistVel_Cntr0[2*LAT_PRE_DIST_OVER_VELOCITY_TAB_POINTS];  /* Country 0, Latent Pre */
extern MEMSEC_REF HEAD_PAR_CONST float32 LatPreDistVel_Cntr1[2*LAT_PRE_DIST_OVER_VELOCITY_TAB_POINTS];  /* Country 1, Latent Pre */
extern MEMSEC_REF HEAD_PAR_CONST float32 LatAcuteDistVel_Cntr0[2*LAT_ACUTE_DIST_OVER_VELOCITY_TAB_POINTS];  /* Country 0, Latent Acute */
extern MEMSEC_REF HEAD_PAR_CONST float32 LatAcuteDistVel_Cntr1[2*LAT_ACUTE_DIST_OVER_VELOCITY_TAB_POINTS];  /* Country 1, Latent Acute */

/* Warning parameter variants due to encoding of different pre brake functions */
extern MEMSEC_REF HEAD_PAR_CONST float32 HEAD_PAR_DYNPRE_TTBPRE_EARLY_STAT[HEAD_PAR_NO_FUSION_VAR];
extern MEMSEC_REF HEAD_PAR_CONST float32 HEAD_PAR_DYNPRE_TTBPRE_LATE_STAT[HEAD_PAR_NO_FUSION_VAR];
extern MEMSEC_REF HEAD_PAR_CONST float32 HEAD_PAR_DYNPRE_TTSPRE_EARLY[HEAD_PAR_NO_FUSION_VAR];
extern MEMSEC_REF HEAD_PAR_CONST float32 HEAD_PAR_DYNPRE_TTSPRE_LATE[HEAD_PAR_NO_FUSION_VAR];
extern MEMSEC_REF HEAD_PAR_CONST float32 HEAD_PAR_DYNACUTE_TTBACUTE_STAT[HEAD_PAR_NO_FUSION_VAR];
extern MEMSEC_REF HEAD_PAR_CONST float32 HEAD_PAR_DYNACUTE_TTSACUTE[HEAD_PAR_NO_FUSION_VAR];

/*****************************************************************************
  GLOBAL VARIABLES (EXTERNAL SCOPE)
*****************************************************************************/

/*** END OF SINLGE INCLUDE SECTION ******************************************/

#endif  /* #if (MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION) */

#endif /* _HEAD_PAR_H_INCLUDED */
/**@}*/
