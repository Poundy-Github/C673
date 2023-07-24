/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC/LOHP/HP (Adaptive Cruise Control - Longitudinal Headway Planner - Headway Planner)

PACKAGENAME:               hp_par.h

DESCRIPTION:               Internal header file for HP

AUTHOR:                    Mistry Niraj (uidq5738)

CREATION DATE:             24.02.2017

VERSION:                   $Revision: 1.28.8.1 $

LEGACY VERSION:            Revision: 1.28.1.2

**************************************************************************** */

/* conditional include */
#ifndef HP_PAR_H_INCLUDED
#define HP_PAR_H_INCLUDED

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/*!
@defgroup         hp_par_h   Hp_par_h
@ingroup          hp_custom
@brief            Parameter header file for HP
@{
*/

#if ((FCT_CFG_LOHP_COMPONENT) && (FCT_CFG_ACC_HEADWAY_PLANNER))

#if (defined(_MSC_VER) && defined(_WIN32))
#define Acc_const DLLEXPORT const
#else
#define Acc_const const
#endif

extern void HP_v_SelectParamSet(void);

#if (CFG_FCT_ACC_TTS_CONTROLLER)
/*! [s] Time constant for TTS speed controller */
#define Acc_tts_control_time_const ACC_TTS_CONTROL_TIME_CONST
extern times_t ACC_TTS_CONTROL_TIME_CONST;

/*! [m] Minimum ramp distance for TTS speed controller */
#define Acc_tts_control_dist_ramp_min ACC_TTS_CONTROL_DIST_RAMP_MIN
extern distance_t ACC_TTS_CONTROL_DIST_RAMP_MIN;

/*! [m] Maximum ramp distance for TTS speed controller */
#define Acc_tts_control_dist_ramp_max ACC_TTS_CONTROL_DIST_RAMP_MAX
extern distance_t ACC_TTS_CONTROL_DIST_RAMP_MAX;

/*! [m/s²] Minimum ramp acceleration for TTS speed controller */
#define Acc_tts_control_accel_ramp_min ACC_TTS_CONTROL_ACCEL_RAMP_MIN
extern acceleration_t ACC_TTS_CONTROL_ACCEL_RAMP_MIN;

/*! [m/s²] Maximum ramp acceleration for TTS speed controller */
#define Acc_tts_control_accel_ramp_max ACC_TTS_CONTROL_ACCEL_RAMP_MAX
extern acceleration_t ACC_TTS_CONTROL_ACCEL_RAMP_MAX;

/*! [m/s²] Stop ramp acceleration for TTS speed controller */
#define Acc_tts_control_accel_ramp_stop ACC_TTS_CONTROL_ACCEL_RAMP_STOP
extern acceleration_t ACC_TTS_CONTROL_ACCEL_RAMP_STOP;

#endif /* CFG_FCT_ACC_TTS_CONTROLLER */

/*! [m/s²] Minimum value for commanded acceleration when a reason for loss of object could be detected */
#define Acc_min_accel_object_lost ACC_AMIN_OBJECT_LOST
extern Acc_const acceleration_t ACC_AMIN_OBJECT_LOST;

/*! [m/s²] Maximum value for commanded acceleration when a reason for loss of object could be detected */
#define Acc_max_accel_object_lost ACC_AMAX_OBJECT_LOST
extern Acc_const acceleration_t ACC_AMAX_OBJECT_LOST;

/*! [m/s²] Minimum value for commanded acceleration to statonary objects */
#define Acc_min_accel_object_stationary ACC_MIN_ACCEL_OBJECT_STATIONARY
extern Acc_const acceleration_t ACC_MIN_ACCEL_OBJECT_STATIONARY;

/*! [m/s³] Maximum decrease of acceleration request during follow mode (speed dependent)*/
#define Acc_neg_grad_points (uint16)5
#define Acc_max_neg_grad ACC_MAX_NEG_GRAD
extern acceleration_t ACC_MAX_NEG_GRAD[2*Acc_neg_grad_points];

/*! [m/s³] Maximum increase of acceleration request during follow mode for positive values(speed dependent)*/
#define Acc_pos_grad_pos_accel_points (uint16)3
#define Acc_max_pos_grad_pos_accel ACC_MAX_POS_GRAD_POS_ACCEL
extern acceleration_t ACC_MAX_POS_GRAD_POS_ACCEL[2*Acc_pos_grad_pos_accel_points];

/*! [m/s³] Maximum increase of acceleration request during follow mode for negative values(speed dependent)*/
#define Acc_pos_grad_neg_accel_points (uint16)3
#define Acc_max_pos_grad_neg_accel ACC_MAX_POS_GRAD_NEG_ACCEL
extern acceleration_t ACC_MAX_POS_GRAD_NEG_ACCEL[2*Acc_pos_grad_neg_accel_points];

/*! [m/s] Minimum estimated RelativeSteed Threshold for Takeover */
#define Acc_vrel_estim_min ACC_VREL_ESTIM_MIN
extern  velocity_t ACC_VREL_ESTIM_MIN;

/*! [s] Time gap hysteresis to end Takeover */
#define Acc_end_alert_hyst_factor ACC_END_ALERT_HYST_FACTOR
extern factor_t ACC_END_ALERT_HYST_FACTOR;

/*! [s] Estimated Headway max Simulation Time */
#define Acc_alert_max_sim_time ACC_ALERT_MAX_SIM_TIME
#define Acc_max_sim_time_points 3
extern Acc_const times_t ACC_ALERT_MAX_SIM_TIME[2*Acc_max_sim_time_points];

/*! [s] Estimated Headway Simulation TimeStep */
#define Acc_alert_sim_time_step ACC_ALERT_SIM_TIME_STEP
extern  times_t ACC_ALERT_SIM_TIME_STEP;

/*! [s] Filter time for acceleration of vehicle for alert simulation*/
#define Acc_alert_sim_vehicle_filter_time ACC_ALERT_SIM_VEHICLE_FILTER_TIME
extern Acc_const times_t ACC_ALERT_SIM_VEHICLE_FILTER_TIME;

/*! [s] Estimated Headway Simulation TimeStep */
#define Acc_alert_supress_alert_time_points 2
#define Acc_alert_supress_alert_time ACC_ALERT_SUPRESS_ALERT_TIME
extern  times_t ACC_ALERT_SUPRESS_ALERT_TIME[2*Acc_alert_supress_alert_time_points];

/*! minimum output time, which ACC alert shall be sent to avoid to short acoustical and visual signals*/
#define Acc_alert_min_output_time ACC_ALERT_MIN_OUTPUT_TIME
extern times_t ACC_ALERT_MIN_OUTPUT_TIME;

/*! [m/s²] max acceleration for ACC FSR depending on vehicle speed*/
#define Acc_fsr_max_acceleration ACC_pFsrMaxAccelPar
#define Acc_fsr_max_acceleration_points 4
extern Acc_const acceleration_t* ACC_pFsrMaxAccelPar;

/*! [m/s²] max acceleration for ACC depending on vehicle speed*/
#define Acc_max_acceleration ACC_MAX_ACCEL
#define Acc_max_acceleration_points 3
extern Acc_const acceleration_t ACC_MAX_ACCEL[2*Acc_max_acceleration_points];

/*! [m/s²] max deceleration for ACC FSR depending on vehicle speed*/
#define Acc_fsr_max_deceleration ACC_FSR_MAX_DECEL
#define Acc_fsr_max_deceleration_points 5
extern acceleration_t ACC_FSR_MAX_DECEL[2*Acc_fsr_max_deceleration_points];

/*! [m/s²] max deceleration for ACC depending on vehicle speed*/
#define Acc_max_deceleration ACC_MAX_DECEL
#define Acc_max_deceleration_points 3
extern Acc_const acceleration_t ACC_MAX_DECEL[2*Acc_max_deceleration_points];

/*! [m] min following distance (speed dependent) the driver can set (headway setting 0%)*/
#define Acc_headway_min_dist_points ((uint16)6)
#define Acc_headway_min_dist ACC_pHeadwayMinDist
extern distance_t* ACC_pHeadwayMinDist;

/*! [m] max following distance (speed dependent) the driver can set (headway setting 100%)*/
#define Acc_headway_max_dist_points ((uint16)6)
#define Acc_headway_max_dist ACC_pHeadwayMaxDist
extern distance_t* ACC_pHeadwayMaxDist;

/*! [m] min alert distance (estimated host speed dependend)*/
#define Acc_min_alert_thres ACC_MIN_ALERT_THRES
#define Acc_min_alert_thres_points 5
extern  distance_t ACC_MIN_ALERT_THRES[2*Acc_min_alert_thres_points];

/*! [m] may alert distance (estimated host speed dependend)*/
#define Acc_max_alert_thres ACC_MAX_ALERT_THRES
#define Acc_max_alert_thres_points 5
extern  distance_t ACC_MAX_ALERT_THRES[2*Acc_max_alert_thres_points];

/*! modfiy estimated distance for new or changed control object */
#define Acc_headway_add_factor ACC_HEADWAY_ADD_FACTOR
#define Acc_headway_add_factor_points 3
extern Acc_const factor_t ACC_HEADWAY_ADD_FACTOR[2*Acc_headway_add_factor_points];



/*! [] factor of how much the headway to a new object can be increased per second*/
#define Hp_headway_increase_grad_factor HP_HEADWAY_INCREASE_GRAD_FACTOR
extern Acc_const factor_t HP_HEADWAY_INCREASE_GRAD_FACTOR;

/* Vrel threshold for activating reduced distance ramp gradient */
#define Hp_reduced_distramp_vrel_thres HP_REDUCED_DISTRAMP_VREL_THRES
extern Acc_const velocity_t HP_REDUCED_DISTRAMP_VREL_THRES;
/* Aobj threshold for activating reduced distance ramp gradient */
#define Hp_reduced_distramp_aobj_thres HP_REDUCED_DISTRAMP_AOBJ_THRES
extern Acc_const acceleration_t HP_REDUCED_DISTRAMP_AOBJ_THRES;
/* Ramp gradient reduction factor for distance */
#define Hp_reduced_distramp_grad_factor (factor_t)5 
/* Ramp gradient reduction factor for alert mod factor */
#define Hp_reduced_alertramp_grad_factor (factor_t)2 
/* Minimum Ramp gradient for alert and distance */
#define Hp_dist_alert_minimum_grad 20

/*! Defines of points and steps for table HP_ALERT_FACT_RED_RELDIST_VREL */
/* Step of relative distance columns [-] */
#define Hp_alert_fac_red_step_reldist (factor_t)400
/* Step of relative speed rows [m/s] */
#define Hp_alert_fac_red_step_vrel (velocity_t)300
/* Start of relative distance columns [-] */
#define Hp_alert_fac_red_start_reldist (factor_t)200
/* Start of relative speed rows [m/s] */
#define Hp_alert_fac_red_start_vrel (velocity_t)(-600)

#define Hp_alert_fac_red_points_vrel 4
#define Hp_alert_fac_red_points_reldist 5

/*! Factor for reduction of alert factor dependent on relative distance to min headway setting */
#define Hp_alert_fac_red_reldist_vrel HP_ALERT_FAC_REDUCTION_RELDIST_VREL
extern factor_t HP_ALERT_FAC_REDUCTION_RELDIST_VREL[Hp_alert_fac_red_points_reldist*Hp_alert_fac_red_points_vrel];

/*! Distance based max relative velocity for reduction of intrusion distance at obj initialization */
/*! [Obj distance (m) |, Relative velocity (m/s) */
#define Hp_intrusion_red_vrel_thres_points 2
#define Hp_intrusion_red_vrel_thres HP_INTRUSION_RED_VREL_THRES
extern Acc_const velocity_t HP_INTRUSION_RED_VREL_THRES[2*Hp_intrusion_red_vrel_thres_points];



/*! [m/s] speed where standstill is assumed */
#define Acc_stopped_speed ACC_STOPPED_SPEED
extern Acc_const velocity_t ACC_STOPPED_SPEED;

/*! [m/s] maximum speed for a "crawling" vehicle*/
#define Acc_crawl_max_velocity ACC_CRAWL_MAX_VELOCITY
extern Acc_const velocity_t ACC_CRAWL_MAX_VELOCITY;

/*! [s] maximum time the target vehicle may need to come to a full stop to call this situation a stop situation if object if front of the target has already stopped*/
#define Acc_si_max_time_to_stop_2obj ACC_SI_MAX_TIME_TO_STOP_2OBJ
extern Acc_const times_t ACC_SI_MAX_TIME_TO_STOP_2OBJ;

/*! [m/s²] object acceleration for a "go" signal in low speed situations*/
#define Acc_si_min_go_accel ACC_SI_MIN_GO_ACCEL
extern Acc_const acceleration_t ACC_SI_MIN_GO_ACCEL;

/*! [m/s²] object acceleration for a "go" signal in low speed situations if object in front of target is faster and accelerating too*/
#define Acc_si_min_go_accel_2obj ACC_SI_MIN_GO_ACCEL_2OBJ 
extern Acc_const acceleration_t ACC_SI_MIN_GO_ACCEL_2OBJ;

/*! [m/s²] max allowed deceleration to objects being in front of the next object in lane*/
#define Acc_max_decel_hidden_object_points 2
#define Acc_max_decel_hidden_object ACC_MAX_DECEL_HIDDEN_OBJECT
extern acceleration_t ACC_MAX_DECEL_HIDDEN_OBJECT[2*Acc_max_decel_hidden_object_points]; 

/*! [s] max relevant ttc for check if object will come to full stop while ttc*/
#define Acc_si_max_relevant_ttc ACC_SI_MAX_RELEVANT_TTC
extern Acc_const times_t ACC_SI_MAX_RELEVANT_TTC;

/*! [] criticality factor depending on the current object deceleration */
#define Acc_si_crit_factor_obj_accel ACC_SI_CRIT_FACTOR_OBJ_ACCEL
#define Acc_si_crit_factor_obj_accel_points ((uint16)4)
extern Acc_const factor_t ACC_SI_CRIT_FACTOR_OBJ_ACCEL[2*Acc_si_crit_factor_obj_accel_points];

/*! [] criticality factor depending on the current object deceleration */
#define Acc_si_criticality_headway_factor ACC_SI_CRITICALITY_HEADWAY_FACTOR
#define Acc_si_criticality_headway_factor_points ((uint16)3)
extern factor_t ACC_SI_CRITICALITY_HEADWAY_FACTOR[2*Acc_si_criticality_headway_factor_points];

/*! [%] criticality to object based on ttc value*/
#define Acc_si_crit_from_ttc_points 2
#define Acc_si_criticality_from_ttc ACC_SI_CRITICALITY_FROM_TTC
extern Acc_const factor_t ACC_SI_CRITICALITY_FROM_TTC[2*Acc_si_crit_from_ttc_points]; 

/*! [%] Default headway setting value */
#define Acc_default_headway_setting  100u

/*! [-] max allowed pos grad for criticality */
#define Acc_si_crit_pos_grad ACC_SI_CRIT_POS_GRAD
extern Acc_const gradient_t ACC_SI_CRIT_POS_GRAD;

/*! [-] max allowed neg grad for criticality */
#define Acc_si_crit_neg_grad ACC_SI_CRIT_NEG_GRAD
extern Acc_const gradient_t ACC_SI_CRIT_NEG_GRAD;

/*! [m/s²] maximum allowed acceleration that can happen*/
#define Acc_max_allowed_accel ACC_MAX_ALLOWED_ACCEL
extern Acc_const acceleration_t ACC_MAX_ALLOWED_ACCEL;

/*! [m/s²] maximum allowed deceleration that can happen*/
#define Acc_max_allowed_decel ACC_MAX_ALLOWED_DECEL
extern Acc_const acceleration_t ACC_MAX_ALLOWED_DECEL;

/*! [s] System reaction time when braking requested*/
#define Acc_t_reaction_brake ACC_T_REACT_BRAKE
extern Acc_const times_t ACC_T_REACT_BRAKE;

/*! [m/s] recommended velocity as a function of visibility range */
#define Acc_recommended_velocity_curve ACC_RECOMMENDED_VELOCITY_CURVE
#define Acc_recommended_velocity_curve_points 5
extern velocity_t ACC_RECOMMENDED_VELOCITY_CURVE[2*Acc_recommended_velocity_curve_points];

/*! [s] longitudinal visibility threshold related to vehicle velocity where ACC is disengaged (according to ISO 2[s]) */
#define Acc_t_visibility_disengage ACC_T_VIS_DISENGAGE
extern Acc_const times_t ACC_T_VIS_DISENGAGE;

/*! [s] longitudinal visibility threshold related to vehicle velocity where ACC engagement is allowed (according to ISO 2[s]) */
#define Acc_t_visibility_engage ACC_T_VIS_ENGAGE
extern Acc_const times_t ACC_T_VIS_ENGAGE;

/*! Factor to calculate minimum intrusion distance based on maximum intrusion distance */ 
#define Acc_min_to_max_intrusion_factor ACC_MIN_TO_MAX_INTRUSION_FACTOR
#define Acc_min_to_max_intrusion_factor_points 3
extern distance_t ACC_MIN_TO_MAX_INTRUSION_FACTOR[2*Acc_min_to_max_intrusion_factor_points];

/*! Maximum intrusion distance */
#define Acc_max_intrusion_distance ACC_MAX_INTRUSION_DISTANCE
#define Acc_max_intrusion_distance_points 5
extern distance_t ACC_MAX_INTRUSION_DISTANCE[2*Acc_max_intrusion_distance_points];

/*! Intrusion distance factor for interpolation between minimum and maximum intrusion curves
    depends of relative speed */
#define Acc_intrusion_vrel_factor ACC_INTRUSION_VREL_FACTOR
#define Acc_intrusion_vrel_factor_points 6
extern factor_t ACC_INTRUSION_VREL_FACTOR[2*Acc_intrusion_vrel_factor_points];

/*! Intrusion distance factor for interpolation between minimum and maximum intrusion curves
    depends of relative acceleration */
#define Acc_intrusion_arel_factor ACC_INTRUSION_AREL_FACTOR
#define Acc_intrusion_arel_factor_points 4
extern factor_t ACC_INTRUSION_AREL_FACTOR[2*Acc_intrusion_arel_factor_points];

/*! Intrusion distance factor for interpolation between minimum and maximum intrusion curves
    depens of headway setting */
#define Acc_intrusion_headway_factor ACC_INTRUSION_HEADWAY_FACTOR
#define Acc_intrusion_headway_factor_points 3
extern factor_t ACC_INTRUSION_HEADWAY_FACTOR[2*Acc_intrusion_headway_factor_points];

/*! [m/s²] max allowed deceleration to objects being at the outer lanes (lane change)*/
#define Acc_max_decel_outer_lanes ACC_MAX_DECEL_OUTER_LANES
#define Acc_max_decel_outer_lanes_points ((uint16)3)
extern acceleration_t ACC_MAX_DECEL_OUTER_LANES[2*Acc_max_decel_outer_lanes_points];

/*! [m/s^2] max allowed deceleration to an adjacent lane object depending on its cut in potential*/ 
#define Acc_max_decel_cut_in ACC_MAX_DECEL_CUT_IN
#define Acc_max_decel_cut_in_points 5
extern acceleration_t ACC_MAX_DECEL_CUT_IN[2*Acc_max_decel_cut_in_points];

/*! [] cut out depended factor for requested distance*/
#define Acc_cut_out_distance_factor ACC_CUT_OUT_DISTANCE_FACTOR
#define Acc_cut_out_distance_factor_points ((uint16)3)
extern factor_t ACC_CUT_OUT_DISTANCE_FACTOR[2*Acc_cut_out_distance_factor_points];

/*! [s] ACC prediction time for host velocity prediction*/
#define Acc_predicted_reaction_time ACC_PREDICTED_REACTION_TIME
//extern Acc_const times_t ACC_PREDICTED_REACTION_TIME;
extern times_t ACC_PREDICTED_REACTION_TIME;
/*! [m/s²] Minimum deceleration resolution*/
#define Acc_min_decel_resolution ACC_MIN_DECEL_RESOLUTION  
extern Acc_const acceleration_t ACC_MIN_DECEL_RESOLUTION; 

/*! [] maximum negative gradient of object acceleration depending on the current object acceleration*/
#define Acc_obj_accel_max_neg_grad ACC_OBJ_ACCEL_MAX_NEG_GRAD
#define Acc_obj_accel_max_neg_grad_points ((uint16)3)
extern Acc_const acceleration_t ACC_OBJ_ACCEL_MAX_NEG_GRAD[2*Acc_obj_accel_max_neg_grad_points];

/*! [] factor for maximum negative gradient of object acceleration depending on the current object velocity*/
#define Acc_obj_accel_grad_speed_fac ACC_OBJ_ACCEL_GRAD_SPEED_FAC
#define Acc_obj_accel_grad_speed_fac_points ((uint16)2)
extern Acc_const factor_t ACC_OBJ_ACCEL_GRAD_SPEED_FAC[2*Acc_obj_accel_grad_speed_fac_points];

/*! [] factor for maximum negative gradient of object acceleration depending on the distance between current and filtered acceleration*/
#define Acc_obj_accel_grad_accel_d_fac ACC_OBJ_ACCEL_GRAD_ACCEL_D_FAC
#define Acc_obj_accel_grad_accel_d_fac_pt ((uint16)3)
extern Acc_const factor_t ACC_OBJ_ACCEL_GRAD_ACCEL_D_FAC[2*Acc_obj_accel_grad_accel_d_fac_pt];

#if (CFG_FCT_ACC_TTS_CONTROLLER)
/*! [] factor for using calculated TTS deceleration below a specific object velocity threshold*/
#define Acc_use_calc_tts_factor ACC_USE_CALC_TTS_FACTOR
#define Acc_use_calc_tts_factor_points ((uint16)2)
extern factor_t ACC_USE_CALC_TTS_FACTOR[2*Acc_use_calc_tts_factor_points];

#else

/*! [] factor for using calculated stop deceleration below a specific time to object stop threshold*/
#define Acc_use_calc_decel_factor ACC_USE_CALC_DECEL_FACTOR
#define Acc_use_calc_decel_factor_points ((uint16)2)
extern factor_t ACC_USE_CALC_DECEL_FACTOR[2*Acc_use_calc_decel_factor_points];

/*! [ Object Distance[m] | Ideal Vrel [m/s] ] */
#define Acc_tts_dist_vrel ACC_TTS_DIST_VREL
#define Acc_tts_dist_vrel_points ((uint16)4)
extern velocity_t ACC_TTS_DIST_VREL[2*Acc_tts_dist_vrel_points];

/*! [Delta ego speed [m/s] | Scaling factor to increase TTS Decel] */
#define Acc_tts_del_vrel_fac ACC_TTS_DEL_VREL_FAC
#define Acc_tts_del_vrel_fac_points ((uint16)2)
extern factor_t ACC_TTS_DEL_VREL_FAC[2*Acc_tts_del_vrel_fac_points];

/*! [Egospeed | Scaling factor to increase TTS Decel] */
#define Acc_tts_vego_fac ACC_TTS_VEGO_FAC
#define Acc_tts_vego_fac_points ((uint16)3)
extern factor_t ACC_TTS_VEGO_FAC[2*Acc_tts_vego_fac_points];

/*! [ms] Time value for TTS ramping out */
#define Hp_tts_grad_limit HP_TTS_GRAD_LIMIT
extern Acc_const times_t HP_TTS_GRAD_LIMIT;

/*! [m] Delta dist to obj for min deceleration output as Acc_standstill_accel_req */
#define Hp_tts_min_brake_dist HP_TTS_MIN_BRAKE_DIST
extern distance_t HP_TTS_MIN_BRAKE_DIST;

#endif /* CFG_FCT_ACC_TTS_CONTROLLER */

/*! [m] distance to braking object where "emergency braking" should be applied*/
#define Acc_emergency_brake_distance ACC_EMERGENCY_BRAKE_DISTANCE
extern Acc_const distance_t ACC_EMERGENCY_BRAKE_DISTANCE;

/*! [m/s^2] minimum deceleration request in case of a emergency stop*/
#define Acc_emergency_brake_deceleration ACC_EMERGENCY_BRAKE_DECELERATION
extern Acc_const acceleration_t ACC_EMERGENCY_BRAKE_DECELERATION;

/*! [m/s^2] minimum deceleration request for calculated deceleration*/
#define Acc_minimum_calculated_brake_request ACC_MINIMUM_CALCULATED_BRAKE_REQUEST
extern Acc_const acceleration_t ACC_MINIMUM_CALCULATED_BRAKE_REQUEST;

/*! [m/s^2] minimum object deceleration for Time To Stop calculation*/
#define Acc_object_decel_for_tts_calc ACC_OBJECT_DECEL_FOR_TTS_CALC
extern Acc_const acceleration_t ACC_OBJECT_DECEL_FOR_TTS_CALC;

/*! [m/s] minimum object speed for Time To Stop calculation*/
#define Acc_object_speed_for_tts_calc ACC_OBJECT_SPEED_FOR_TTS_CALC
extern  Acc_const velocity_t ACC_OBJECT_SPEED_FOR_TTS_CALC;

/*! [m] maximum object distance for Time To Stop calculation*/
#define Acc_object_max_distance_for_tts_calc ACC_OBJECT_MAX_DISTANCE_FOR_TTS_CALC
extern  Acc_const distance_t ACC_OBJECT_MAX_DISTANCE_FOR_TTS_CALC;

/*! [m/s^2] minimum object acceleration for Time To Stop zero */
#define Acc_object_accel_for_tts_zero ACC_OBJECT_ACCEL_FOR_TTS_ZERO
extern  Acc_const acceleration_t ACC_OBJECT_ACCEL_FOR_TTS_ZERO;

/*! [m/s] maximum object speed for Time To Stop zero */
#define Acc_object_speed_for_tts_zero ACC_OBJECT_SPEED_FOR_TTS_ZERO
extern  Acc_const velocity_t ACC_OBJECT_SPEED_FOR_TTS_ZERO;

/*! [m/s^2] maximum object rel speed for Time To Stop zero */
#define Acc_rel_speed_for_tts_zero ACC_REL_SPEED_FOR_TTS_ZERO
extern  Acc_const velocity_t ACC_REL_SPEED_FOR_TTS_ZERO;

/*! [s] Default value for TTS calculations for objects */
#define Acc_tts_default_value ACC_TTS_DEFAULT_VALUE
extern  Acc_const times_t ACC_TTS_DEFAULT_VALUE;

/*! [m/s] maximum object relative speed for Time To Stop calculation (not brake for faster objects)*/
#define Acc_object_rel_speed_for_tts_calc ACC_OBJECT_REL_SPEED_FOR_TTS_CALC
extern  Acc_const velocity_t ACC_OBJECT_REL_SPEED_FOR_TTS_CALC;

/*! [] factor for using calculated (max intrusion) deceleration against calculated (max intrusion distance) deceleration (object rel speed dependant)*/
#define Acc_use_approach_decel_speed_factor ACC_USE_APPROACH_DECEL_SPEED_FACTOR
#define Acc_use_approach_decel_speed_factor_points ((uint16)3)
extern factor_t ACC_USE_APPROACH_DECEL_SPEED_FACTOR[2*Acc_use_approach_decel_speed_factor_points];

/*! [] factor for using calculated (max intrusion) deceleration against calculated (max intrusion distance) deceleration (host speed dependant)*/
#define Acc_use_approach_decel_v_host_factor ACC_USE_APPROACH_DECEL_V_HOST_FACTOR
#define Acc_use_approach_decel_v_host_factor_points ((uint16)2)
extern factor_t ACC_USE_APPROACH_DECEL_V_HOST_FACTOR[2*Acc_use_approach_decel_v_host_factor_points];

/*! [] factor for using calculated (max intrusion) deceleration against calculated (max intrusion distance) deceleration (object accel dependant)*/
#define Acc_use_approach_decel_obj_accel_factor ACC_USE_APPROACH_DECEL_OBJ_ACCEL_FACTOR
#define Acc_use_approach_decel_obj_accel_factor_points ((uint16)2)
extern factor_t ACC_USE_APPROACH_DECEL_OBJ_ACCEL_FACTOR[2*Acc_use_approach_decel_obj_accel_factor_points];

/*! [] factor for using calculated (max intrusion) deceleration against calculated (max intrusion distance) deceleration (max intrusion decel depended)*/
#define Acc_use_approach_decel_decel_factor ACC_USE_APPROACH_DECEL_DECEL_FACTOR
#define Acc_use_approach_decel_decel_factor_points ((uint16)3)
extern factor_t ACC_USE_APPROACH_DECEL_DECEL_FACTOR[2*Acc_use_approach_decel_decel_factor_points];

/*! [] factor for using calculated (max intrusion) deceleration against calculated (max intrusion distance) deceleration (relative acceleration depended)*/
#define Acc_use_approach_arel_factor ACC_USE_APPROACH_AREL_FACTOR
#define Acc_use_approach_arel_factor_points 7
extern factor_t ACC_USE_APPROACH_AREL_FACTOR[2*Acc_use_approach_arel_factor_points];

/*! [] factor for using approach decel against fuzzy in very high distances */
#define Acc_use_approach_dist_factor ACC_USE_APPROACH_DIST_FACTOR
#define Acc_use_approach_dist_factor_points 4
extern factor_t ACC_USE_APPROACH_DIST_FACTOR[2*Acc_use_approach_dist_factor_points];

/*! [] VRel threshold for blending fuzzy deceleration to dmin deceleration (relative acceleration depended)*/
#define Acc_vrel_val_fuzzy_to_dmin ACC_VREL_VAL_FUZZY_TO_DMIN
extern velocity_t ACC_VREL_VAL_FUZZY_TO_DMIN;

/*! [] Min factor of reduced fuzzy deceleration to dmin deceleration (relative acceleration depended)*/
#define Acc_min_factor_fuzzy_to_dmin ACC_MIN_FACTOR_FUZZY_TO_DMIN
extern factor_t ACC_MIN_FACTOR_FUZZY_TO_DMIN;

/*! [] Relative distance threshold for blending of Dmin output with fuzzy for long headway settings */
#define Hp_fuzzy_high_rel_dist_thres HP_FUZZY_HIGH_REL_DISTANCE_THRES
extern distance_t HP_FUZZY_HIGH_REL_DISTANCE_THRES;

/*! [m/s²] Requested acceleration while stand still */
#define Acc_standstill_accel_req ACC_STANDSTILL_ACCEL_REQ
extern acceleration_t ACC_STANDSTILL_ACCEL_REQ;

/*! Timer to determine the duration for acceleration limitation after object was lost due to a curve */
#define Acc_timer_limit_accel_obj_lost ACC_TIMER_LIMIT_ACCEL_OBJ_LOST
extern Acc_const times_t ACC_TIMER_LIMIT_ACCEL_OBJ_LOST;

/*! max host vehicle velocity to decelerate on stationary objects */
#define Acc_decel_on_stationary_speed ACC_DECEL_ON_STATIONARY_SPEED
extern Acc_const velocity_t ACC_DECEL_ON_STATIONARY_SPEED;

/*! defines for traffic situation estimation */
#define Acc_min_obj_crawl_accel ACC_MIN_OBJ_CRAWL_ACCEL
extern Acc_const acceleration_t ACC_MIN_OBJ_CRAWL_ACCEL;

/*! Min acceleration to detect stop situation */
#define Acc_min_obj_stop_accel ACC_MIN_OBJ_STOP_ACCEL
extern Acc_const acceleration_t ACC_MIN_OBJ_STOP_ACCEL;

#define Acc_max_stop_distance ACC_MAX_STOP_DISTANCE
extern Acc_const distance_t ACC_MAX_STOP_DISTANCE;
/*! [m] Minimum ACC distance for control usage */
#define Acc_min_cust_perf_dist (*pAcc_min_cust_perf_dist)
extern Acc_const distance_t* pAcc_min_cust_perf_dist;

#define Acc_si_max_hys_time_to_stop ACC_SI_MAX_HYS_TIME_TO_STOP
extern Acc_const times_t ACC_SI_MAX_HYS_TIME_TO_STOP;

#define Acc_si_min_hys_time_to_stop ACC_SI_MIN_HYS_TIME_TO_STOP
extern Acc_const times_t ACC_SI_MIN_HYS_TIME_TO_STOP;

/* Threshold of critical TTC to use minimum needed deceleration for avoiding crash */
#define Hp_critical_ttc_thres HP_CRITICAL_TTC_THRES
extern Acc_const times_t HP_CRITICAL_TTC_THRES;

/*! max control distance for standing relevant object */
#define Acc_max_dist_rel_standing_obj ACC_MAX_DIST_REL_STANDING_OBJ
extern Acc_const distance_t ACC_MAX_DIST_REL_STANDING_OBJ;

/* Parameters for Overtake Support */
#if (HP_CFG_OVERTAKE_SUPPORT_FEATURE)

/*! min ego speed for overtake support to be activated */
#define Acc_otsupport_min_speed ACC_OTSUPPORT_MIN_SPEED
extern velocity_t ACC_OTSUPPORT_MIN_SPEED;

/*! max duration of time gap reduction phase for overtake support */
#define Acc_otsupport_tgr_max_duration ACC_OTSUPPORT_TGR_MAX_DURATION
extern Acc_const times_t ACC_OTSUPPORT_TGR_MAX_DURATION;

/*! max duration of bypass phase for overtake support */
#define Acc_otsupport_bp_max_duration ACC_OTSUPPORT_BP_MAX_DURATION
extern Acc_const times_t ACC_OTSUPPORT_BP_MAX_DURATION;

/*!< Threshold for req acceleration for neighbouring object for overtake support activation */
#define  Acc_otsupport_ooi_accel_threshold ACC_OTSUPPORT_OOI_ACCEL_THRESHOLD
extern acceleration_t ACC_OTSUPPORT_OOI_ACCEL_THRESHOLD;

/*!< Overtake support distance factor for low requested distance */
#define Acc_otsupport_distance_factor_low ACC_OTSUPPORT_DISTANCE_FACTOR_LOW
extern factor_t ACC_OTSUPPORT_DISTANCE_FACTOR_LOW;

/*!< Overtake support distance factor for high requested distance */
#define Acc_otsupport_distance_factor_high ACC_OTSUPPORT_DISTANCE_FACTOR_HIGH
extern factor_t ACC_OTSUPPORT_DISTANCE_FACTOR_HIGH;

/*!< Init distance factor if feature is cancelled. Ramping out starts from this value */
#define Acc_otsupport_dist_fact_cancel ACC_OTSUPPORT_DIST_FACT_CANCEL
extern Acc_const factor_t ACC_OTSUPPORT_DIST_FACT_CANCEL;

/*! [factor] Factor for reducing timegap for overtake support (headway setting dependent)*/
#define Acc_otsupport_min_dist_factor_points ((uint16)3)
#define Acc_otsupport_min_dist_factor ACC_OTSUPPORT_MIN_DIST_FACTOR
extern factor_t ACC_OTSUPPORT_MIN_DIST_FACTOR[2*Acc_otsupport_min_dist_factor_points];

/*! [factor] Number of cycles for which obj loss is counted for changing to pass by state (headway setting dependent)*/
#define Acc_otsupport_lc_cycle_counter_points ((uint16)3)
#define Acc_otsupport_lc_cycle_counter ACC_OTSUPPORT_LC_CYCLE_COUNTER
extern Acc_const factor_t ACC_OTSUPPORT_LC_CYCLE_COUNTER[2*Acc_otsupport_lc_cycle_counter_points];

/*!< DMC deceleration delay time in approach situations */
#define Acc_otsupport_decel_delay ACC_OTSUPPORT_DECEL_DELAY
extern Acc_const times_t ACC_OTSUPPORT_DECEL_DELAY;

/*!< Minimum acceleration during active Overtake Support */
#define Acc_otsupport_min_approach_accel ACC_OTSUPPORT_MIN_APPROACH_ACCEL
extern Acc_const acceleration_t ACC_OTSUPPORT_MIN_APPROACH_ACCEL;

/*!< Feature deactivation acceleration threshold in case of slow adjacent OOI before passby during Overtake Support */
#define Acc_otsupport_deac_accel_adj_obj ACC_OTSUPPORT_DEAC_ACCEL_ADJ_OBJ
extern acceleration_t ACC_OTSUPPORT_DEAC_ACCEL_ADJ_OBJ;

#endif /* (HP_CFG_OVERTAKE_SUPPORT_FEATURE) */

/* Parameters for Overtake Prevention */
#if (HP_CFG_OVERTAKE_PREVENTION_FEATURE)

/*! min object speed for overtake prevention to be activated */
#define Acc_otprevent_min_speed ACC_OTPREVENT_MIN_SPEED
extern velocity_t ACC_OTPREVENT_MIN_SPEED;

/*! Speed offset for overtake prevention to be deactivated */
#define Acc_otprevent_deact_speed_offset ACC_OTPREVENT_DEACT_SPEED_OFFSET
extern velocity_t ACC_OTPREVENT_DEACT_SPEED_OFFSET;

/*!< Overtake prevention desired time gap to obj not on lane */
#define Acc_otprevent_des_timegap ACC_OTPREVENT_DES_TIMEGAP
extern times_t ACC_OTPREVENT_DES_TIMEGAP;

/*! min allowed deceleration for reaction to obj in neighbouring lane  */
#define Acc_otprevent_min_allowed_decel ACC_OTPREVENT_MIN_ALLOWED_DECEL
extern Acc_const acceleration_t ACC_OTPREVENT_MIN_ALLOWED_DECEL;

/*! Distance based relative velocity for activation of overtake prevention */
#define Acc_otprevent_maxrelspeed_points ((uint16)2)
#define Acc_otprevent_maxrelspeed ACC_OTPREVENT_MAXRELSPEED
extern velocity_t ACC_OTPREVENT_MAXRELSPEED[2*Acc_otprevent_maxrelspeed_points];

/*! CutIn Probability dependent factor to increase desired distance to object when OTP is active */
#define Acc_otp_cutin_dist_factor_points ((uint16)3)
#define Acc_otp_cutin_dist_factor ACC_OTP_CUTIN_DIST_FACTOR
extern factor_t ACC_OTP_CUTIN_DIST_FACTOR[2*Acc_otp_cutin_dist_factor_points];

#endif /* (HP_CFG_OVERTAKE_PREVENTION_FEATURE) */

/* Object Dynamics Filters */
/*! [ms] Filter constant for object acceleration filtering, dependent on object acceleration */
#define Hp_obj_accel_filter_points ((uint16)6)
/*! [ Object acceleration [m/s^2] | Filter constant [ms] ] */
#define Acc_obj_accel_filter ACC_OBJ_ACCEL_FILTER
extern sint16 ACC_OBJ_ACCEL_FILTER[2*Hp_obj_accel_filter_points];

/*! [ms] Filter constant for object relative velocity filtering, dependent on object acceleration */
#define Hp_obj_vrel_filter_points ((uint16)4)
/*! [ Object acceleration [m/s^2] | Filter constant [ms] ] */
#define Acc_obj_vrel_filter ACC_OBJ_VREL_FILTER
extern sint16 ACC_OBJ_VREL_FILTER[2*Hp_obj_vrel_filter_points];

/*! [Factor_t] Factor for object acceleration filter reduction based on object jerk */
#define Hp_obj_jerk_fac_points ((uint16)3)
/*! [ Object jerk [m/s^3] | Factor ] */
#define Acc_obj_jerk_fac ACC_OBJ_JERK_FAC
extern sint16 ACC_OBJ_JERK_FAC[2*Hp_obj_jerk_fac_points];

/* Hysterese for value close to "0":                FUZZY_INPUT_HYST_FAK * FUZZY_INPUT_HYST_NOMIN / FUZZY_INPUT_HYST_DENOM */
/* Hysterese for value >> (NOMIN + DENOM):          FUZZY_INPUT_HYST_FAK                                                   */

/* Parameter for hysteresis filtering of object acceleration */
#define Obj_acc_hyst_factor OBJ_ACC_HYST_FACTOR
#define Obj_acc_hyst_nominator OBJ_ACC_HYST_NOMINATOR
#define Obj_acc_hyst_denominator OBJ_ACC_HYST_DENOMINATOR
#define Obj_acc_hyst_antiwindup_error_limit OBJ_ACC_HYST_ANTIWINDUP_ERROR_LIMIT

extern Acc_const float32 OBJ_ACC_HYST_FACTOR;                  /* [m/ss] Hysteresis Width for complete range of object acceleration */
extern Acc_const float32 OBJ_ACC_HYST_NOMINATOR;                /* nominator factor for hysteresis of object acceleration at very low values  */
extern Acc_const float32 OBJ_ACC_HYST_DENOMINATOR;              /* denominator factor for hysteresis of object acceleration at very low values  */
/* for 0 as input variable                            -> HYST = 0.15 * 1.0 / 0.6 = 0.25 m/ss   */
/* for high input variable                            -> HYST = 0.15             = 0.15 m/ss   */
extern Acc_const float32 OBJ_ACC_HYST_ANTIWINDUP_ERROR_LIMIT;  /* max error in[m/s]  0.27 m/s due to offset potential offset drift */

#define Hp_activate_hys_obj_accel lc_ActHystObjAccel
extern boolean lc_ActHystObjAccel;

#endif  /* ((FCT_CFG_LOHP_COMPONENT) && (FCT_CFG_ACC_HEADWAY_PLANNER)) */

/** @} end defgroup */

#endif /* ifndef HP_PAR_H_INCLUDED */
