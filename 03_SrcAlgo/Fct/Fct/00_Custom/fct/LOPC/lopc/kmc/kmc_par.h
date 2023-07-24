/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC/LOPC/KMC (Adaptive Cruise Control - Longitudinal Planner and Controller - Kinematic Motion Control)

PACKAGENAME:               kmc_par.h

DESCRIPTION:               Header file for parameters for CruiseControl functionality in KMC

AUTHOR:                    Mistry Niraj (uidq5738)

CREATION DATE:             24.02.2017

VERSION:                   $Revision: 1.11.6.7 $

LEGACY VERSION:            Revision: 1.28
**************************************************************************** */

/* conditional include */
#ifndef KMC_PAR_H_INCLUDED
#define KMC_PAR_H_INCLUDED

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/*!
@defgroup         kmc_par_h   Kmc_Par_h
@ingroup          kmc_custom
@brief            Parameter header file for KMC
@{
*/

#if ((FCT_CFG_LOPC_COMPONENT) && (FCT_CFG_CC) && (LOPC_CFG_KMC))

#if (defined(_MSC_VER) && defined(_WIN32))
#define Cc_const DLLEXPORT const
#else
#define Cc_const const
#endif


/*****************************************************************************
  CONSTANTS (COMPONENT EXTERN)
*****************************************************************************/

#if (CFG_FCT_CC_USE_CONTROL_CRITICALITY)
/* [m/s³] Maximum allowed deceleration gradient in critical situations within ISO norm 22179:2009 limits*/
#define max_decel_gradient_critical MAX_DECEL_GRADIENT_CRITICAL
#define max_decel_gradient_critical_points ((uint16)2)
extern Cc_const acceleration_t MAX_DECEL_GRADIENT_CRITICAL[2*max_decel_gradient_critical_points];

/* Factor to increase the acceleration request gradient in critical traffic situations */
#define criticality_accel_gradient_gain CRITICALITY_ACCEL_GRADIENT_GAIN
#define accel_gradient_gain_points ((uint16)2)
extern Cc_const factor_t CRITICALITY_ACCEL_GRADIENT_GAIN[2*accel_gradient_gain_points];
#endif /* (CFG_FCT_CC_USE_CONTROL_CRITICALITY) */

#if (CFG_FCT_CC_SMOOTH_ACCEL_REQUEST)
/* Factor to reduce filter time in critical traffic situations */
#define criticality_accel_filter_time CRITICALITY_ACCEL_FILTER_TIME
#define accel_filter_time_time_points ((uint16)2)
extern Cc_const times_t CRITICALITY_ACCEL_FILTER_TIME[2*accel_filter_time_time_points];

#if (KMC_NO_SMOOTH_JERK_IN_LOW_SPEED)
/* Factor to reduce filter time dependent on vehicle speed */
#define egospeed_accel_filter_time EGOSPEED_ACCEL_FILTER_TIME
#define egospeed_accel_filter_time_points ((uint16)2)
extern factor_t EGOSPEED_ACCEL_FILTER_TIME[2*egospeed_accel_filter_time_points];

#define Kmc_fast_brake_release_speed_thres KMC_FAST_BRAKE_RELEASE_SPEED_THRES
extern Cc_const velocity_t KMC_FAST_BRAKE_RELEASE_SPEED_THRES;
#define Kmc_fast_brake_release_accel_high_thres KMC_FAST_BRAKE_RELEASE_ACCEL_HIGH_THRES
extern Cc_const acceleration_t KMC_FAST_BRAKE_RELEASE_ACCEL_HIGH_THRES;
#define Kmc_fast_brake_release_accel_low_thres KMC_FAST_BRAKE_RELEASE_ACCEL_LOW_THRES
extern Cc_const acceleration_t KMC_FAST_BRAKE_RELEASE_ACCEL_LOW_THRES;
#define Kmc_low_speed_thres_neg_smooth_jerk KMC_LOW_SPEED_THRES_NEG_SMOOTH_JERK
extern Cc_const velocity_t KMC_LOW_SPEED_THRES_NEG_SMOOTH_JERK;

#endif
#endif /* (CFG_FCT_CC_SMOOTH_ACCEL_REQUEST) */

/*![m/s²] acceleration delta that is used to determine if the acceleration will reach a specific value (keep it at 0.05m/s²)*/
#define Cc_accel_band ((acceleration_t)50)

/*! [m/s²] cruise acceleration is a function of the difference vehicle speed and set speed */
#define Cc_accel_curve CC_ACCEL_CURVE
#define Cc_curve_points  ((uint16)18)
extern acceleration_t CC_ACCEL_CURVE[2*Cc_curve_points];

/*! [m/s²] max longitudinal acceleration is a function of the difference vehicle speed and max speed for a lateral acceleration*/
#define Cc_long_accel_curve CC_LONG_ACCEL_CURVE
#define Cc_long_accel_curve_points  ((uint16)8)
extern acceleration_t CC_LONG_ACCEL_CURVE[2*Cc_long_accel_curve_points];

/*! [m/s] max speed is a function of the lateral acceleration*/
#define Cc_alat_speed_curve_points ((uint16)6)
#define Cc_alat_speed_curve pCC_ALatSpeedCurve
extern acceleration_t* pCC_ALatSpeedCurve;

#if (KMC_INC_LAT_LIMITS_IN_FOLLOW)
/* Factor to increase lateral acceleration limitation when in follow mode */
#define Cc_alat_followmode_accel_inc_fac CC_ALAT_FOLLOWMODE_ACCEL_INC_FAC
extern Cc_const factor_t CC_ALAT_FOLLOWMODE_ACCEL_INC_FAC;

#define Cc_alat_followmode_min_speed CC_ALAT_FOLLOWMODE_MIN_SPEED
extern Cc_const velocity_t CC_ALAT_FOLLOWMODE_MIN_SPEED;
#endif

/*! [m/s²] max allowed vehicle(ESP) acceleration is a function of the vehicle speed*/
#define Cc_max_vehicle_accel_points ((uint16)2)
#define Cc_max_vehicle_accel CC_MAX_VEHICLE_ACCEL
extern acceleration_t CC_MAX_VEHICLE_ACCEL[2*Cc_max_vehicle_accel_points];

/*! [m/s²] max allowed vehicle(ESP) deceleration is a function of the vehicle speed*/
#define Cc_max_vehicle_decel_points ((uint16)2)
#define Cc_max_vehicle_decel CC_MAX_VEHICLE_DECEL
extern acceleration_t CC_MAX_VEHICLE_DECEL[2*Cc_max_vehicle_decel_points];

#if(!CFG_FCT_CC_USE_CUSTOM_ACCEL_LIMITS)

/*! [m/s²] max cruise acceleration is a function of the vehicle speed*/
#define Cc_max_accel_curve_points  ((uint16)4)
#define Cc_max_accel_curve CC_MAX_ACCEL_CURVE
extern Cc_const acceleration_t CC_MAX_ACCEL_CURVE[2*Cc_max_accel_curve_points];

#else

/*! [m/s²] max acceleration for CC depending on vehicle speed with country code*/
#define Cc_max_accel_curve_points ((uint16)7)
#define Cc_max_accel_curve pCC_MaxAccel
extern acceleration_t* pCC_MaxAccel;

#endif

#if (CFG_FCT_USE_ACCEL_GAIN)

/*! [m/s²] accel gain is a function of the vehicle speed*/
#define Cc_accel_gain_curve CC_ACCEL_GAIN_CURVE
#define Cc_accel_gain_curve_points  ((uint16)4)
extern Cc_const acceleration_t CC_ACCEL_GAIN_CURVE[2*Cc_accel_gain_curve_points];

#endif

/*! [m/s²] limiter acceleration is a function of the difference vehicle speed and set speed */
#define Lim_accel_curve  LIM_ACCEL_CURVE
#define Lim_curve_points  ((uint16)14)
extern Cc_const acceleration_t LIM_ACCEL_CURVE[2*Lim_curve_points];
 
#if (CFG_FCT_CC_USE_ACCEL_DECEL_MODE)
/*! [m/s] acceleration request prior to "acceleration mode" */
#define Cc_accelmode_init CC_V_ACCELMODE_INIT
extern Cc_const velocity_t CC_V_ACCELMODE_INIT;

/*! [m/s] acceleration request during "acceleration mode" */
#define Cc_accelmode_delta CC_V_ACCELMODE
extern Cc_const velocity_t CC_V_ACCELMODE;

/*! [m/s] deceleration request during "deceleration mode" */
extern Cc_const velocity_t CC_V_DECELMODE;
#define Cc_decelmode_delta CC_V_DECELMODE

/*! [m/s] deceleration request prior to "deceleration mode" */
extern Cc_const velocity_t CC_V_DECELMODE_INIT;
#define Cc_decelmode_init CC_V_DECELMODE_INIT

#endif  /* CFG_FCT_CC_USE_ACCEL_DECEL_MODE */

#if (CFG_FCT_USE_ACCEL_GAIN)
/*! [m/s²] maximum acceleration request during cruise control */
#define Cc_accel_limit CC_ACCEL_LIMIT
extern Cc_const acceleration_t CC_ACCEL_LIMIT;
#endif 

/*! [m/s²] maximum deceleration request during cruise control */
#define Cc_decel_limit (*pCC_DecelLimit)
extern acceleration_t* pCC_DecelLimit;

/*! [km/h] when the vehicle speed goes below minimum set speed minus this value, the cruise control is disengaged (with an object)*/
#define Cc_disengage_threshold_kmh CC_OFF_THRES_KMH
extern Cc_const setspeed_t CC_OFF_THRES_KMH;

/*! [km/h] minimum allowed engagement speed*/
#define Cc_min_v_engage_kmh CC_MIN_V_ENGAGE_KMH
extern Cc_const setspeed_t CC_MIN_V_ENGAGE_KMH;

/*! [mph] minimum allowed engagement speed*/
#define Cc_min_v_engage_mph CC_MIN_V_ENGAGE_MPH
extern Cc_const setspeed_t CC_MIN_V_ENGAGE_MPH;

/*! [mph] minimum allowed engagement speed (usa)*/
#define Cc_min_v_engage_usa_mph CC_MIN_V_ENGAGE_USA_MPH
extern Cc_const setspeed_t CC_MIN_V_ENGAGE_USA_MPH;


/*! [km/h] when the vehicle speed goes below minimum set speed minus this value, the cruise control is disengaged (without an object)*/
#define Cc_disengage_threshold_cruise_kmh CC_OFF_THRES_CRUISE_KMH
extern Cc_const setspeed_t CC_OFF_THRES_CRUISE_KMH;

/*! [km/h] maximum set speed for cruise control function */
#define Cc_max_setspeed_kmh CC_MAX_VSET_KMH
extern Cc_const setspeed_t CC_MAX_VSET_KMH;

/*! [m/s²] maximum deceleration during override */
#define Cc_max_decel_during_override CC_MAX_DECEL_DURING_OVERRIDE
extern acceleration_t CC_MAX_DECEL_DURING_OVERRIDE;

/*! [m/s²] maximum acceleration request after override */
#define Cc_max_decel_after_override CC_MAX_DECEL_AFTER_OVERRIDE
extern acceleration_t CC_MAX_DECEL_AFTER_OVERRIDE;

/*! [m/s²] maximum acceleration request after engage */
#define Cc_max_decel_after_engage CC_MAX_DECEL_AFTER_ENGAGE
extern acceleration_t CC_MAX_DECEL_AFTER_ENGAGE;

/*! [m/s³] Maximum increase of acceleration request during automatic braking */
#define Cc_max_release_brake_grad CC_MAX_GRAD_RELEASE_BRAKE
extern Cc_const gradient_t CC_MAX_GRAD_RELEASE_BRAKE;

/*! [m/s] Minimum valid velocity offset of speedometer speed */
/*! If speedometer_speed < vehicle_velocity + offset, then speedometer speed is not valid */
#define Cc_min_valid_speedo_offset_points ((uint16)3)
#define Cc_min_valid_speedo_offset CC_MIN_VALID_SPEEDO_OFFSET
extern Cc_const velocity_t CC_MIN_VALID_SPEEDO_OFFSET[2*Cc_min_valid_speedo_offset_points];

/*! [m/s] Maximum valid velocity offset of speedometer speed */
/*! If speedometer_speed > vehicle_velocity + offset, then speedometer speed is not valid */
#define Cc_max_valid_speedo_offset_points ((uint16)3)
#define Cc_max_valid_speedo_offset CC_MAX_VALID_SPEEDO_OFFSET
extern Cc_const velocity_t CC_MAX_VALID_SPEEDO_OFFSET[2*Cc_max_valid_speedo_offset_points];

/*! [m/s³] Maximum decrease of acceleration request during "acceleration / deceleration mode" */
#define Cc_max_neg_grad_accel_decel CC_ACCELMODE_MAX_NEG_GRAD
extern Cc_const gradient_t CC_ACCELMODE_MAX_NEG_GRAD;

/*! [m/s³] Maximum decrease of acceleration request during cruise control */
#define Cc_neg_grad_points (uint16)2
#define Cc_max_neg_grad pCC_MaxNegGrad
extern acceleration_t* pCC_MaxNegGrad;

/*! ACC to CC transition factor to reduce acceleration change rate */
#define Cc_acc_to_cc_transition_factor (*pCC_AccToCcTransitionFactor)
extern Cc_const factor_t* pCC_AccToCcTransitionFactor;

/*! [m/s³] Maximum decrease of acceleration request after cruise disengagement */
#define Cc_max_neg_grad_disengage CC_OFF_MAX_NEG_GRAD
extern Cc_const gradient_t CC_OFF_MAX_NEG_GRAD;

/*! [m/s³] Maximum increase of acceleration request during "acceleration / deceleration mode" */
#define Cc_max_pos_grad_accel_decel CC_ACCELMODE_MAX_POS_GRAD
extern Cc_const gradient_t CC_ACCELMODE_MAX_POS_GRAD;

/*! [m/s³] Maximum increase of acceleration request during cruise control */
#define Cc_pos_grad_pos_accel_points (uint16)2
#define Cc_max_pos_grad_pos_accel pCC_MaxPosGradPosAccel
extern acceleration_t* pCC_MaxPosGradPosAccel;

/*! [m/s³] Maximum increase of acceleration request during cruise control */
#define Cc_pos_grad_neg_accel_points (uint16)2
#define Cc_max_pos_grad_neg_accel pCC_MaxPosGradNegAccel
extern acceleration_t* pCC_MaxPosGradNegAccel;


/*! [m/s³] Maximum increase of acceleration request after cruise disengagement */
#define Cc_max_pos_grad_disengage CC_OFF_MAX_POS_GRAD
extern Cc_const gradient_t CC_OFF_MAX_POS_GRAD;

/*! [m/s³] Maximum increase of acceleration request after cruise disengagement with rapid ramp*/
#define Cc_max_pos_grad_rapid_disengage CC_OFF_MAX_POS_GRAD_RAPID
extern Cc_const gradient_t CC_OFF_MAX_POS_GRAD_RAPID;

/*! [m/s³] Maximum decrease of acceleration request after cruise disengagement with rapid ramp*/
#define Cc_max_neg_grad_rapid_disengage CC_OFF_MAX_NEG_GRAD_RAPID
extern Cc_const gradient_t CC_OFF_MAX_NEG_GRAD_RAPID;
    
/*! [km/h] minimum set speed for cruise control function */
#define Cc_min_setspeed_kmh CC_MIN_VSET_KMH
extern Cc_const setspeed_t CC_MIN_VSET_KMH;

/*! [m/s per m/s²] Acceleration dependent offset added to the speedometer speed when it is adopted as the new set speed */
#define Cc_pos_accel_offset CC_A_POS_OFFSET
extern velocity_t CC_A_POS_OFFSET;

/*! [m/s] Maximum positive acceleration dependent offset */
#define Cc_max_pos_accel_offset CC_A_POS_OFFSET_MAX
extern Cc_const velocity_t CC_A_POS_OFFSET_MAX;

/*! [m/s per m/s²] Acceleration dependent offset added to the speedometer speed when it is adopted as the new set speed */
#define Cc_neg_accel_offset CC_A_NEG_OFFSET
extern velocity_t CC_A_NEG_OFFSET;

/*! [m/s] Acceleration dependent offset added to the speedometer speed when it is adopted as the new set speed */
#define Cc_max_neg_accel_offset CC_A_NEG_OFFSET_MAX
extern Cc_const velocity_t CC_A_NEG_OFFSET_MAX;

/*! [m/s²] maximum acceleration request during "deceleration only" mode */
#define Cc_min_decel_brake_only CC_MIN_DECEL_BRAKE_ONLY
extern Cc_const acceleration_t CC_MIN_DECEL_BRAKE_ONLY;

/*! [m/s³]  */
extern Cc_const gradient_t CC_REST_MIN_GRAD;
#define Cc_min_grad_rest CC_REST_MIN_GRAD

/*! [m/s³] Positive disengagement ramp for speedlimiter */
#define Lim_max_pos_grad_disengage LIM_OFF_MAX_POS_GRAD
extern Cc_const gradient_t LIM_OFF_MAX_POS_GRAD;

/*! [m/s³] Negative disengagement ramp for speedlimiter */
#define Lim_max_neg_grad_disengage LIM_OFF_MAX_NEG_GRAD
extern Cc_const gradient_t LIM_OFF_MAX_NEG_GRAD;

/*! [m/s³]  Positive Jerk during speedlimiter */
#define Lim_max_pos_grad LIM_MAX_POS_GRAD
extern Cc_const gradient_t LIM_MAX_POS_GRAD;

/*! [m/s³]  Negative Jerk during speed limiter */
#define Lim_max_neg_grad LIM_MAX_NEG_GRAD
extern Cc_const gradient_t LIM_MAX_NEG_GRAD;

/*! [m/s³] Max. Positive Jerk during override of speed limiter */
#define Lim_max_pos_grad_override LIM_OVERRIDE_MAX_POS_GRAD
extern Cc_const gradient_t LIM_OVERRIDE_MAX_POS_GRAD;

/*! [m/s³] Max. Negative Jerk during override of speed limiter */
#define Lim_max_neg_grad_override LIM_OVERRIDE_MAX_NEG_GRAD
extern Cc_const gradient_t LIM_OVERRIDE_MAX_NEG_GRAD;

/*! [m/s³]  */
#define Lim_min_grad_rest LIM_REST_MIN_GRAD
extern Cc_const gradient_t LIM_REST_MIN_GRAD;

/*! [m/s²] Maximum value for the commanded acceleration during speed limiter */
#define Lim_accel_limit LIM_ACCEL_LIMIT
extern Cc_const acceleration_t LIM_ACCEL_LIMIT;

/* [m/s²] Maximum value for the commanded deceleration during speed limiter */
#define Lim_decel_limit LIM_DECEL_LIMIT
extern Cc_const acceleration_t LIM_DECEL_LIMIT;

/*! [km/h] Minimum speed limiter set speed */
#define Lim_min_setspeed_kmh LIM_MIN_VSET_KMH
extern Cc_const setspeed_t LIM_MIN_VSET_KMH;

/*! [km/h] Maximum speed limiter set speed */
#define Lim_max_setspeed_kmh LIM_MAX_VSET_KMH
extern Cc_const setspeed_t LIM_MAX_VSET_KMH;

/*! [Mph] Minimum speed limiter set speed */
#define Lim_min_setspeed_mph LIM_MIN_VSET_MPH
extern Cc_const setspeed_t LIM_MIN_VSET_MPH;

/*! [Mph] Maximum speed limiter set speed */
#define Lim_max_setspeed_mph LIM_MAX_VSET_MPH
extern Cc_const setspeed_t LIM_MAX_VSET_MPH;

/*! [km/h] Threshold for engagement of permanent limiter below driver selected maximum speed */
#define Plim_threshold_kmh PLIM_THRES_KMH
extern Cc_const setspeed_t PLIM_THRES_KMH;

/*! [km/h] Hysteresis for disengagement of permanent limiter */
#define Plim_hyst_kmh PLIM_HYST_KMH
extern Cc_const setspeed_t PLIM_HYST_KMH;

/*! [Mph] Threshold for engagement of permanent limiter below driver selected maximum speed */
#define Plim_threshold_mph PLIM_THRES_MPH
extern Cc_const setspeed_t PLIM_THRES_MPH;

/*! [Mph] Hysteresis for disengagement of permanent limiter */
#define Plim_hyst_mph PLIM_HYST_MPH
extern Cc_const setspeed_t PLIM_HYST_MPH;

/*! [Mph] Step for Speed increment / Decreasement level 1 */
#define Cc_setspeed_step_level_1_mph CC_VSET_STEP_LEVEL_1_MPH
extern Cc_const setspeed_t CC_VSET_STEP_LEVEL_1_MPH;

/*! [Mph] Step for Speed increment / Decreasement level 2 */
#define Cc_setspeed_step_level_2_mph CC_VSET_STEP_LEVEL_2_MPH
extern Cc_const setspeed_t CC_VSET_STEP_LEVEL_2_MPH;

/*! [km/h] Step for Speed increment / Decreasement level 1 */
#define Cc_setspeed_step_level_1_kmh CC_VSET_STEP_LEVEL_1_KMH
extern Cc_const setspeed_t CC_VSET_STEP_LEVEL_1_KMH;

/*! [km/h] Step for Speed increment / Decreasement level2 */
#define Cc_setspeed_step_level_2_kmh CC_VSET_STEP_LEVEL_2_KMH
extern Cc_const setspeed_t CC_VSET_STEP_LEVEL_2_KMH;

/*! [km/h] Vehicle speed threshold. Above this threshold CC will be disengaged. Value 255 is default-> no disengagement */
#define Cc_max_speed_kmh CC_VMAX_KMH
extern Cc_const setspeed_t CC_VMAX_KMH;

/*! [Mph] Vehicle speed threshold. Above this threshold CC will be disengaged. Value 255 is default-> no disengagement */
#define Cc_max_speed_mph CC_VMAX_MPH
extern Cc_const setspeed_t CC_VMAX_MPH;

/*! [ms] Time until the hold and repeat function of the cruise switches is activated */
#define Cc_start_repeat_function_time CC_START_T_REP_FUNC
extern Cc_const times_t CC_START_T_REP_FUNC;

/*! [ms] Time in which the cruise switch activation (hold) will be repeated */
#define Cc_repeat_function_time CC_T_REP_FUNC
extern Cc_const times_t CC_T_REP_FUNC;

/*! [s] Time in that the driver must apply the RESUME-switch for a smooth drive off after complete standstill */
#define Cc_default_drive_off_smooth_time    3000u
#define Cc_drive_off_smooth_time CC_T_DRIVE_OFF_SMOOTH 
extern Cc_const times_t CC_T_DRIVE_OFF_SMOOTH;

/*! [m/s³] Minimum gradient for actual acceleration at cruise engagement */
#define Cc_min_engage_accel_gradient CC_MIN_ENGAGE_A_GRAD
extern Cc_const gradient_t CC_MIN_ENGAGE_A_GRAD;

/*! [m/s³] Maximum gradient for actual acceleration at cruise engagement */
#define Cc_max_engage_accel_gradient CC_MAX_ENGAGE_A_GRAD
extern Cc_const gradient_t CC_MAX_ENGAGE_A_GRAD;

/*! [M/h] Minimum cruise set speed */
#define Cc_min_setspeed_mph CC_MIN_VSET_MPH
extern Cc_const setspeed_t CC_MIN_VSET_MPH;

/*! [M/h] Minimum cruise set speed in USA */
#define Cc_min_setspeed_usa_mph CC_MIN_VSET_USA_MPH
extern Cc_const setspeed_t CC_MIN_VSET_USA_MPH;

/*! [M/h] Maximum cruise set speed */
#define Cc_max_setspeed_mph CC_MAX_VSET_MPH
extern Cc_const setspeed_t CC_MAX_VSET_MPH;

/*! [M/h] Threshold for shutoff below minimum set speed */
#define Cc_disengage_threshold_mph CC_OFF_THRES_MPH
extern Cc_const setspeed_t CC_OFF_THRES_MPH;

/*! [M/h] Threshold for shutoff below minimum set speed for cruise control (without relevant object)*/
#define Cc_disengage_threshold_cruise_mph CC_OFF_THRES_CRUISE_MPH
extern Cc_const setspeed_t CC_OFF_THRES_CRUISE_MPH;

/*! [-] filter time for lateral acceleration limitation at positive gradient of lateral accel */
#define Cc_pos_lateral_accel_filter_time CC_TFILT_POS_ALAT
extern Cc_const times_t CC_TFILT_POS_ALAT;

/*! [-] filter time for lateral acceleration limitation at negative gradient of lateral accel */
#define Cc_neg_lateral_accel_filter_time CC_TFILT_NEG_ALAT
extern Cc_const times_t CC_TFILT_NEG_ALAT;

/*! [ms] Max. duration of brake only mode (69.444 - 2.777) [m/s] / 0.5 [m/s²] = 133.333 [s] max. = 65534 */
#define Cc_max_decel_only_time CC_TMAX_DECEL_ONLY
extern Cc_const times_t CC_TMAX_DECEL_ONLY;
  
/*! [ms] Max. time till disengagement of cruise, when gear is clutch pressed (manual gear only) */
#define Cc_shift_active_inhibit_time CC_T_SHIFT_ACT_INH
extern Cc_const times_t CC_T_SHIFT_ACT_INH;

/*! [ms] Max. time Limit deceleration after Override is active */
#define Cc_max_decel_limit_time CC_TMAX_DECEL_LIMIT
extern times_t CC_TMAX_DECEL_LIMIT;

/*! [ms] Max. time ABS is active until CC is disengaged */
#define Cc_abs_act_inhibit_time CC_T_ABS_ACT_INH
extern Cc_const times_t CC_T_ABS_ACT_INH;

/*! [ms] Max. time ESP is active until CC is disengaged */
#define Cc_esp_act_inhibit_time CC_T_ESP_ACT_INH
extern Cc_const times_t CC_T_ESP_ACT_INH;

/*! [ms] Max. time driver door is open until CC is disengaged */
#define Cc_driver_door_inhibit_time CC_T_DRIVER_DOOR_INH
extern times_t CC_T_DRIVER_DOOR_INH;

/*! [ms] Max. time driver seat is open until CC is disengaged */
#define Cc_driver_seat_inhibit_time CC_T_DRIVER_SEAT_INH
extern times_t CC_T_DRIVER_SEAT_INH;
/*! [ms] Max. time TCS is active until CC is disengaged */
#define Cc_tcs_act_inhibit_time CC_T_TCS_ACT_INH
extern Cc_const times_t CC_T_TCS_ACT_INH;

/*! [m/s²] Maximum deceleration request during acceleration mode */
#define Cc_max_decel_during_accel_mode CC_MAX_DECEL_DURING_ACCEL_MODE
extern Cc_const acceleration_t CC_MAX_DECEL_DURING_ACCEL_MODE;

/*! [m/s²] Maximum acceleration request during deceleration mode */
#define Cc_max_accel_during_decel_mode CC_MAX_ACCEL_DURING_DECEL_MODE
extern Cc_const acceleration_t CC_MAX_ACCEL_DURING_DECEL_MODE;


#if (CFG_FCT_CC_USE_ACCEL_BAND_MODIFICATION)

/*! [-] Scaling of accel band influence (velocity dependent) */
#define Cc_accel_band_scale_points ((uint16)2)
#define Cc_accel_band_scale CC_ACCEL_BAND_SCALE
extern Cc_const acceleration_t CC_ACCEL_BAND_SCALE[];


/*! [m/s²] upper acceleration band (acceleration dependent) */
#define Cc_max_accel_band_pos_points ((uint16)2)
#define Cc_accel_band_pos CC_ACCEL_BAND_POS
extern Cc_const acceleration_t CC_ACCEL_BAND_POS[];

/*! [m/s²] upper acceleration band (acceleration dependent) */
#define Cc_max_accel_band_neg_points ((uint16)2)
#define Cc_accel_band_neg CC_ACCEL_BAND_NEG
extern Cc_const acceleration_t CC_ACCEL_BAND_NEG[];

/*! [-] max/min gradient for accel band change rate*/
#define Cc_accel_band_gradient CC_ACCEL_BAND_GRADIENT
extern Cc_const gradient_t CC_ACCEL_BAND_GRADIENT;

/*! [-] max/min gradient for requested accel (DAS) approaching real requested accel (ACC/CC) within the accel band*/
#define Cc_accel_band_approach_gradient CC_ACCEL_BAND_APPROACH_GRADIENT
extern Cc_const gradient_t CC_ACCEL_BAND_APPROACH_GRADIENT;

/*! [m/s²] decreasing the minimum acceleration depending on vehicle speed*/
#define Acc_decrease_minaccel_curve ACC_DECREASE_MINACCEL_CURVE
#define Acc_decrease_minaccel_points ((uint16)3)
extern Cc_const acceleration_t ACC_DECREASE_MINACCEL_CURVE[2*Acc_decrease_minaccel_points];

/*! [m/s²] increasing the maximum acceleration depending on vehicle speed*/
#define Acc_increase_maxaccel_curve ACC_INCREASE_MAXACCEL_CURVE
#define Acc_increase_maxaccel_points ((uint16)3)
extern Cc_const acceleration_t ACC_INCREASE_MAXACCEL_CURVE[2*Acc_increase_maxaccel_points];

#endif /* (CFG_FCT_CC_USE_ACCEL_BAND_MODIFICATION) */

/*! [-] lowest possible jerk for jerk limitation during smooth jerk functionality*/
#define Cc_smooth_jerk_min_gradient CC_SMOOTH_JERK_MIN_GRADIENT
extern Cc_const gradient_t CC_SMOOTH_JERK_MIN_GRADIENT;

/*! [m/s] lowest velociy where to perform positive smooth gradients (for starts behind a vehicle)*/
#define Cc_smooth_gradient_pos_min_velocity CC_SMOOTH_GRADIENT_POS_MIN_VELOCITY
extern Cc_const velocity_t CC_SMOOTH_GRADIENT_POS_MIN_VELOCITY;

/*! [s] defines the time when the commanded acceleration shall be reached*/
#define Cc_smooth_gradient_pos_time pCC_SmoothGradientPosTime
#define Cc_smooth_gradient_pos_time_points ((uint16)2)
extern Cc_const sint16*  pCC_SmoothGradientPosTime;

#if (CFG_FCT_CC_USE_SMOOTH_JERKS)
/*! [s] defines the time when the commanded acceleration shall be reached*/
#define Cc_smooth_gradient_neg_time pCC_SmoothGradientNegTime
#define Cc_smooth_gradient_neg_time_points ((uint16)2)
extern Cc_const sint16*   pCC_SmoothGradientNegTime; 

/*! [na] Gain to decrease gradient smoothening dependent on acceleration request error */
#define Kmc_smooth_gradient_gain KMC_SMOOTH_GRADIENT_GAIN
#define Kmc_smooth_gradient_gain_points ((uint16)3)
extern factor_t KMC_SMOOTH_GRADIENT_GAIN[2*Kmc_smooth_gradient_gain_points];

#endif  /* CFG_FCT_CC_USE_SMOOTH_JERKS */

/*! [s] defines the time after engagement where override detection is not used to avoid going into override directly after engagement*/
#define Cc_engage_override_time CC_ENGAGE_OVERRTIDE_TIME
extern Cc_const times_t CC_ENGAGE_OVERRTIDE_TIME;

#if (FCT_CFG_SLA_FEATURE)
/* ********************** ADD SPEED LIMIT ASSIST PARAMETERS HERE ************************* */

/*! [m] Speed limit control distance befor limit position if deceleration have to be requested */
#define Cc_sla_ctrl_dist_befor_limit_accel_points ((uint16)2)
#define Cc_sla_ctrl_dist_befor_limit_accel CC_SLA_CTRL_DIST_BEFOR_LIMIT_ACCEL
extern Cc_const distance_t CC_SLA_CTRL_DIST_BEFOR_LIMIT_ACCEL[2*Cc_sla_ctrl_dist_befor_limit_accel_points];

/*! [m] Speed limit control distance befor limit position if deceleration have to be requested */
#define Cc_sla_ctrl_dist_befor_limit_decel_points ((uint16)3)
#define Cc_sla_ctrl_dist_befor_limit_decel CC_SLA_CTRL_DIST_BEFOR_LIMIT_DECEL
extern Cc_const distance_t CC_SLA_CTRL_DIST_BEFOR_LIMIT_DECEL[2*Cc_sla_ctrl_dist_befor_limit_decel_points];

/*! [m] Speed limit control distance after limit position */
#define Cc_sla_ctrl_dist_after_limit_points ((uint16)3)
#define Cc_sla_ctrl_dist_after_limit CC_SLA_CTRL_DIST_AFTER_LIMIT
extern Cc_const distance_t CC_SLA_CTRL_DIST_AFTER_LIMIT[2*Cc_sla_ctrl_dist_after_limit_points];

/*! [m/s²] Minimum SLA deceleration limit */
#define Cc_sla_min_decel_limit_points ((uint16)3)
#define Cc_sla_min_decel_limit CC_SLA_MIN_DECEL_LIMIT
extern Cc_const acceleration_t CC_SLA_MIN_DECEL_LIMIT[2*Cc_sla_min_decel_limit_points];

/*! [m/s²] Maximum SLA deceleration limit */
#define Cc_sla_max_decel_limit_points ((uint16)2)
#define Cc_sla_max_decel_limit CC_SLA_MAX_DECEL_LIMIT
extern Cc_const acceleration_t CC_SLA_MAX_DECEL_LIMIT[2*Cc_sla_max_decel_limit_points];

/*! [kph] Minimum speed limit set by driver (only relevant with SLA feature) */
#define Cc_sla_min_driver_speed_kmh CC_SLA_MIN_DRIVER_SPEED_KMH
extern Cc_const setspeed_t CC_SLA_MIN_DRIVER_SPEED_KMH;

/*! [mph] Minimum speed limit set by driver (only relevant with SLA feature) */
#define Cc_sla_min_driver_speed_mph CC_SLA_MIN_DRIVER_SPEED_MPH
extern Cc_const setspeed_t CC_SLA_MIN_DRIVER_SPEED_MPH;

/*! [kph] Speedometer speed value for switch from SLA acceleration request to common cruise control acceleration */
#define Cc_sla_common_accel_speed_diff_kmh CC_SLA_COMMON_ACCEL_SPEED_DIFF_KMH
extern Cc_const setspeed_t CC_SLA_COMMON_ACCEL_SPEED_DIFF_KMH;

/*! [mph] Speedometer speed value for switch from SLA acceleration request to common cruise control acceleration */
#define Cc_sla_common_accel_speed_diff_mph CC_SLA_COMMON_ACCEL_SPEED_DIFF_MPH
extern Cc_const setspeed_t CC_SLA_COMMON_ACCEL_SPEED_DIFF_MPH;/*PRQA S 0777  */
/* date: 2018-03-22, reviewer: Ravi Kiran Gurrala, reason: identifier differs clearly from other identifiers*/

/*! [kph] Speedometer speed value for switch from SLA deceleration request to common cruise control acceleration */
#define Cc_sla_common_decel_speed_diff_kmh CC_SLA_COMMON_DECEL_SPEED_DIFF_KMH
extern Cc_const setspeed_t CC_SLA_COMMON_DECEL_SPEED_DIFF_KMH;

/*! [mph] Speedometer speed value for switch from SLA deceleration request to common cruise control acceleration */
#define Cc_sla_common_decel_speed_diff_mph CC_SLA_COMMON_DECEL_SPEED_DIFF_MPH
extern Cc_const setspeed_t CC_SLA_COMMON_DECEL_SPEED_DIFF_MPH;/*PRQA S 0777  */
/* date: 2018-03-22, reviewer: Ravi Kiran Gurrala, reason: identifier differs clearly from other identifiers*/

/*! [ms] Timer duration of SLA manual availability */
#define Cc_sla_manual_usage_time CC_SLA_MANUAL_USAGE_TIME
extern times_t CC_SLA_MANUAL_USAGE_TIME;

#define SLA_UNRESTRICTED_SPEED (setspeed_t)253

/* ************************************************************************************** */
#endif /* FCT_CFG_SLA_FEATURE */

#if (KMC_CFG_OVERTAKE_SUPPORT_FEATURE)

/*! [factor] Factor for positive acceleration for overtake support feature in pass-by phase */
#define Cc_ot_pos_accel_factor CC_OT_POS_ACCEL_FACTOR
extern factor_t CC_OT_POS_ACCEL_FACTOR;
#endif

/* [m/s²] max acceleration for the disengagement ramp*/
#define Acc_max_accel_disengage ACC_MAX_ACCEL_DISENGAGE
extern Cc_const acceleration_t ACC_MAX_ACCEL_DISENGAGE;

/* [m/s²] min acceleration for the disengagement ramp*/
#define Acc_min_accel_disengage ACC_MIN_ACCEL_DISENGAGE
extern Cc_const acceleration_t ACC_MIN_ACCEL_DISENGAGE;

/* ************************************************************************************** */
/* Paramater values copied from hp_par.h (earlier acc_par.h) due to separation of Long 
   to LOPC and LOHP. The value is to be same in both locations */
#if (FCT_CFG_ACC_HEADWAY_PLANNER)

/*! [%] Default headway setting value */
#define Kmc_acc_default_headway_setting  90u

/*! [km/h] minimum set speed for adaptive cruise control function (10kmh function)*/
#define Kmc_acc_fsr_min_setspeed_kmh KMC_ACC_FSR_MIN_VSET_KMH
extern Cc_const setspeed_t KMC_ACC_FSR_MIN_VSET_KMH;

/*! [km/h] minimum allowed engagement speed for 10kmh function*/
#define Kmc_acc_fsr_min_v_engage_kmh KMC_ACC_FSR_MIN_V_ENGAGE_KMH
extern Cc_const setspeed_t KMC_ACC_FSR_MIN_V_ENGAGE_KMH;

/*! [km/h] Maximum set speed for ACC */
#define Kmc_acc_max_setspeed_kmh KMC_ACC_MAX_VSET_KMH
extern Cc_const setspeed_t KMC_ACC_MAX_VSET_KMH;

/*! [km/h] when the vehicle speed goes below minimum set speed minus this value, the adaptive cruise control (10kmh) is disengaged */
#define Kmc_acc_fsr_disengage_threshold_kmh KMC_ACC_FSR_OFF_THRES_KMH
extern Cc_const setspeed_t KMC_ACC_FSR_OFF_THRES_KMH;

/*! [mph] minimum set speed for adaptive cruise control function (10kmh function) (usa)*/
#define Kmc_acc_fsr_min_setspeed_usa_mph KMC_ACC_FSR_MIN_VSET_USA_MPH
extern Cc_const setspeed_t KMC_ACC_FSR_MIN_VSET_USA_MPH;

/*! [mph] minimum set speed for adaptive cruise control function (10kmh function)*/
#define Kmc_acc_fsr_min_setspeed_mph KMC_ACC_FSR_MIN_VSET_MPH
extern Cc_const setspeed_t KMC_ACC_FSR_MIN_VSET_MPH;

/*! [mph] minimum allowed engagement speed for 10kmh function (usa)*/
#define Kmc_acc_fsr_min_v_engage_usa_mph KMC_ACC_FSR_MIN_V_ENGAGE_USA_MPH
extern Cc_const setspeed_t KMC_ACC_FSR_MIN_V_ENGAGE_USA_MPH;

/*! [mph] minimum allowed engagement speed for 10kmh function*/
#define Kmc_acc_fsr_min_v_engage_mph KMC_ACC_FSR_MIN_V_ENGAGE_MPH
extern Cc_const setspeed_t KMC_ACC_FSR_MIN_V_ENGAGE_MPH;

/*! [Mph] Maximum set speed for ACC */
#define Kmc_acc_max_setspeed_mph KMC_ACC_MAX_VSET_MPH
extern Cc_const setspeed_t KMC_ACC_MAX_VSET_MPH;

/*! [mph] when the vehicle speed goes below minimum set speed minus this value, the adaptive cruise control (10kmh) is disengaged */
#define Kmc_acc_fsr_disengage_threshold_mph KMC_ACC_FSR_OFF_THRES_MPH
extern Cc_const setspeed_t KMC_ACC_FSR_OFF_THRES_MPH;

/*! [m/s³] Maximum decrease of acceleration request during follow mode (speed dependent)*/
#define Kmc_acc_neg_grad_points (uint16)5
#define Kmc_acc_max_neg_grad KMC_ACC_MAX_NEG_GRAD
extern Cc_const acceleration_t KMC_ACC_MAX_NEG_GRAD[2*Kmc_acc_neg_grad_points];

/*! [m/s³] Maximum increase of acceleration request during follow mode for positive values(speed dependent)*/
#define Kmc_acc_pos_grad_pos_accel_points (uint16)2
#define Kmc_acc_max_pos_grad_pos_accel pKMC_ACC_MaxPosGradPosAccel
extern acceleration_t* pKMC_ACC_MaxPosGradPosAccel;

/*! [m/s³] Maximum increase of acceleration request during follow mode for negative values(speed dependent)*/
#define Kmc_acc_pos_grad_neg_accel_points (uint16)2
#define Kmc_acc_max_pos_grad_neg_accel KMC_ACC_MAX_POS_GRAD_NEG_ACCEL
extern Cc_const acceleration_t KMC_ACC_MAX_POS_GRAD_NEG_ACCEL[2*Kmc_acc_pos_grad_neg_accel_points];

/*! [m/s²] Requested acceleration while stand still */
#define Kmc_acc_standstill_accel_req KMC_ACC_STANDSTILL_ACCEL_REQ
extern Cc_const acceleration_t KMC_ACC_STANDSTILL_ACCEL_REQ;

/*! max host vehicle velocity to decelerate on stationary objects */
#define Kmc_acc_decel_on_stationary_speed KMC_ACC_DECEL_ON_STATIONARY_SPEED
extern Cc_const velocity_t KMC_ACC_DECEL_ON_STATIONARY_SPEED;

/*! [m] Drive off hysteresis */
#define Kmc_acc_drive_off_dist_hyst KMC_ACC_DRIVE_OFF_DIST_HYST
extern  distance_t KMC_ACC_DRIVE_OFF_DIST_HYST;

#define Kmc_acc_standsitll_velocity_threshold KMC_ACC_STANDSTILL_VELOCITY_THRESHOLD
extern velocity_t KMC_ACC_STANDSTILL_VELOCITY_THRESHOLD;


#define Kmc_acc_offset_for_roll KMC_ACC_OFFSET_FOR_ROLL
extern acceleration_t KMC_ACC_OFFSET_FOR_ROLL;

#define p_slopeTc KMC_P_SLOPETC
extern float32 KMC_P_SLOPETC;

#define p_slopeTc1 KMC_P_SLOPETC1
extern float32 KMC_P_SLOPETC1;

#define Counter_enter_slope COUNTER_ENTER_SLOPE
extern  percentage_t COUNTER_ENTER_SLOPE;

#define Counter_exit_slope COUNTER_EXIT_SLOPE
extern  percentage_t COUNTER_EXIT_SLOPE;


#define p_threshold_enter_slope THRESHOLD_ENTER_SLOPE
extern float32 THRESHOLD_ENTER_SLOPE;

#define p_threshold_exit_slope THRESHOLD_EXIT_SLOPE
extern float32 THRESHOLD_EXIT_SLOPE;

#define p_threshold_accel_slope THRESHOD_ACCEL_SLOPE
extern acceleration_t THRESHOD_ACCEL_SLOPE;

#endif /* ENDIF (FCT_CFG_ACC_HEADWAY_PLANNER) */


/*******************************************************************************************/
/*                       A P P L I C A T I O N   P A R A M E T E R S                       */                 
/*******************************************************************************************/

/*! [s] Time within the driver has to activate the RESUME-switch twice to confirm drive off after complete standstill */
#define Cc_default_drive_off_confirmation_time    ((times_t)1000)
#define Cc_drive_off_confirmation_time CC_T_DRIVE_OFF_CONF 
extern Cc_const times_t CC_T_DRIVE_OFF_CONF;

/*! [s] Sending time for drive_off signal */
#define Cc_drive_off_set_time CC_T_DRIVE_OFF_SET 
extern Cc_const times_t CC_T_DRIVE_OFF_SET;


/*! [s] Time the standsill for the ACC_INPUT_DATA.LODM_STAT.STANDSTILL is delayed*/
#define Cc_standstill_delay_time CC_T_STANDSTILL_DELAY 
extern Cc_const times_t CC_T_STANDSTILL_DELAY;

/*! [s] Time Takeover shall be at least displayed to the driver */
#define Cc_display_takeover_time CC_T_DISPLAY_TAKEOVER_TIME
extern Cc_const times_t CC_T_DISPLAY_TAKEOVER_TIME;

/*! [%] First threshold of display distance logic */
#define display_distance_threshold_1 DISPLAY_DISTANCE_THRESHOLD_1
extern percentage_t DISPLAY_DISTANCE_THRESHOLD_1;

/*! [%] Second threshold of display distance logic */
#define display_distance_threshold_2 DISPLAY_DISTANCE_THRESHOLD_2
extern percentage_t DISPLAY_DISTANCE_THRESHOLD_2;

/*! [%] Offset value of display distance logic */
#define display_distance_hyst DISPLAY_DISTANCE_HYST
extern percentage_t DISPLAY_DISTANCE_HYST;

/*! [m/s²] Acceleration request band from customer upper limit */
#define upper_acceleration_value UPPER_ACCELERATION_VALUE
extern sint16 UPPER_ACCELERATION_VALUE;

/*! [m/s²] Acceleration request band from customer lower limit */
#define lower_acceleration_value LOWER_ACCELERATION_VALUE
extern sint16 LOWER_ACCELERATION_VALUE;

/*! [m/s³] Acceleration rate request band from customer upper limit */
#define upper_acceleration_rate_value UPPER_ACCELERATION_RATE_VALUE
extern uint16 UPPER_ACCELERATION_RATE_VALUE;

/*! [m/s³] Acceleration rate request band from customer lower limit */
#define lower_acceleration_rate_value LOWER_ACCELERATION_RATE_VALUE
extern sint16 LOWER_ACCELERATION_RATE_VALUE;

/*! [m/s] threshold of ego speed in break_pre signal calculate */
#define threshold_breakpre_egospeed_value T_BRAKEPRE_EGOSPEED_VALUE 
extern velocity_t T_BRAKEPRE_EGOSPEED_VALUE;

/*! [m/s] threshold of target speed in break_pre signal calculate */
#define threshold_breakpre_tarspeed_value T_BRAKEPRE_TARSPEED_VALUE 
extern velocity_t T_BRAKEPRE_TARSPEED_VALUE;

/*! [m/s^2] threshold of ego acceleration in break_pre signal calculate */
#define threshold_breakpre_egoaccel_value T_BRAKEPRE_EGOACCEL_VALUE 
extern acceleration_t T_BRAKEPRE_EGOACCEL_VALUE;

/*****************************************************************************
  FUNCTIONS (COMPONENT EXTERN)
*****************************************************************************/
/*! set mode depended parameters */
extern void KMC_v_SelectParamSet(void);


#endif  /* FCT_CFG_LOPC_COMPONENT && CFG_FCT_CC && LOPC_CFG_KMC*/

/** @} end defgroup */
#endif /* ifndef KMC_PAR_H_INCLUDED */
