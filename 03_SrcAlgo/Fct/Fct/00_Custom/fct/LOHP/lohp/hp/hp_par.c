/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC/LOHP/HP (Adaptive Cruise Control - Longitudinal Headway Planner - Headway Planner)

PACKAGENAME:               hp_par.c

DESCRIPTION:               Parameter file for HP

AUTHOR:                    Mistry Niraj (uidq5738)

CREATION DATE:             24.02.2017

VERSION:                   $Revision: 1.32.10.2 $

LEGACY VERSION:            Revision: 1.34

**************************************************************************** */

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/*!
@defgroup         hp_par   Hp_par
@ingroup          hp_custom
@brief            Parameter file for HP
@{
*/

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "hp.h"

#if ((FCT_CFG_LOHP_COMPONENT) && (FCT_CFG_ACC_HEADWAY_PLANNER))

/*------ parameters which can be modified without deep knowledge about the code --------*/



#if (CFG_FCT_ACC_TTS_CONTROLLER)
/* Time constant for TTS speed controller [0.001 s] */
times_t ACC_TTS_CONTROL_TIME_CONST = 1500;

/* Minimum ramp distance for TTS speed controller [0.01 m] */
distance_t ACC_TTS_CONTROL_DIST_RAMP_MIN = -1000;

/* Maximum ramp distance for TTS speed controller [0.01 m] */
distance_t ACC_TTS_CONTROL_DIST_RAMP_MAX = 1000;

/* Minimum ramp acceleration for TTS speed controller [0.001 m/s^2] */
acceleration_t ACC_TTS_CONTROL_ACCEL_RAMP_MIN = -1000;

/* Maximum ramp acceleration for TTS speed controller [0.001 m/s^2] */
acceleration_t ACC_TTS_CONTROL_ACCEL_RAMP_MAX = 1000;

/* Stop ramp acceleration for TTS speed controller [0.001 m/s^2] */
acceleration_t ACC_TTS_CONTROL_ACCEL_RAMP_STOP = -500;

#endif /* CFG_FCT_ACC_TTS_CONTROLLER */

/*max acceleration/deceleration request that is allowed (speed depended)*/
/*host vehicle speed (m/s * velocity_s) | max allowed accel/decel (m/s^2 * Acceleration_s)*/
#if (FCT_CFG_FSRACC)
acceleration_t ACC_FSR_MAX_ACCEL_DEFAULT[2*Acc_fsr_max_acceleration_points] = // PRQA S 3408
/* date: 2015-09-16, reviewer: Chirag Patel, reason: Not Safety critical */
{
     0, 4000,
   500, 4000,
  2000, 2000,
  5000, 2000
};

Acc_const acceleration_t* ACC_pFsrMaxAccelPar = ACC_FSR_MAX_ACCEL_DEFAULT;

acceleration_t ACC_FSR_MAX_DECEL[2*Acc_fsr_max_deceleration_points] = 
{
     0, -5000,
   500, -5000,
   500, -5000,
  2000, -3500,
  5000, -3500
};
#else
Acc_const acceleration_t ACC_MAX_ACCEL[2*Acc_max_acceleration_points] = 
{
     0, 2500,
  100 , 2000,
  2500, 1200
};
Acc_const acceleration_t ACC_MAX_DECEL[2*Acc_max_deceleration_points] = 
{
    0, -100,
  300 , -3000,
  1500, -3000
};
#endif /* (FCT_CFG_FSRACC) */

/*headway setting for minimum headway setting (0%) and maximum headway setting (100%)*/
/*speed(m/s), distance (m)*/
distance_t ACC_HEADWAY_MIN_DIST_DEFAULT[2*Acc_headway_min_dist_points] = // PRQA S 3408
/* date: 2015-09-16, reviewer: Chirag Patel, reason: Not Safety critical */
{
  0,    210,  /*379*/ 
  260,  820,  /*800*/
  1700, 1880, /*1650*/
  2500, 2700, /*2200*/
  3500, 5900, /*2800*/
  6000, 8600  /*5500*/
};

distance_t* ACC_pHeadwayMinDist = ACC_HEADWAY_MIN_DIST_DEFAULT;

/*speed(m/s), distance (m)*/
distance_t ACC_HEADWAY_MAX_DIST_DEFAULT[2*Acc_headway_max_dist_points] =// PRQA S 3408
/* date: 2018-03-22, reviewer: Ravi Kiran Gurrala, reason: Not Safety critical */
{
  0,    250,   /*620*/ 
  260,  1000,  /*1200*/ 
  1700, 3870,  /*6000*/ 
  2500, 6970,  /*9000*/ 
  3500, 10500, /*11000*/ 
  6000, 12000  /*11000*/ 
};

/* Set default values*/
distance_t* ACC_pHeadwayMaxDist = ACC_HEADWAY_MAX_DIST_DEFAULT;


/* Brake release gradient limit */
/*velocity m/s, jerk m/s^3*/
acceleration_t ACC_MAX_POS_GRAD_NEG_ACCEL[2*Acc_pos_grad_neg_accel_points] = 
{
     0, 2500, /* all 2000 */
   100, 2500, 
  1500, 2500

};

/* Acceleration gradient limits */
/*velocity m/s, jerk m/s^3*/
acceleration_t ACC_MAX_POS_GRAD_POS_ACCEL[2*Acc_pos_grad_pos_accel_points] = 
{
     0, 2000,
   100, 2000,
  1500, 2000
};

/*velocity m/s, jerk m/s^3*/
acceleration_t ACC_MAX_NEG_GRAD[2*Acc_neg_grad_points] = 
{
  0   , -1000,
  100 , -5000,
  2000, -2500,
  3500, -2500,
  5000, -2500
};


/* recommended velocity as a function of visibility range */
velocity_t ACC_RECOMMENDED_VELOCITY_CURVE[2*Acc_recommended_velocity_curve_points] =
{
  3000,  1500,
  4000,  2000,
  5000,  2500,
  10000, 5000,
  15000, 7000
};

/*! [%] factor (0-1) max intrusion distance * factor = min intrusion distance */ 
/*vehicle speed [m/s] | intrusion factor (factor 0-1000)*/
factor_t ACC_MIN_TO_MAX_INTRUSION_FACTOR[2*Acc_min_to_max_intrusion_factor_points] =
{
    0,  700,
  1400, 700,
  2500, 650
};

/*! Maximum intrusion distance */
/* vehicle speed [m/s] | intrusion distance [m] */
distance_t ACC_MAX_INTRUSION_DISTANCE[2*Acc_max_intrusion_distance_points] =
{
   0,    210,
  300,  750,
  1000, 1480,
  2000, 2200,
  9000, 8400
};

/*! [%] factor (0-1) dependent on relative veloctiy (reduced intrusion during approach) */ 
/*relative velocity [m/s] | v_rel factor (factor 0-1000)*/
factor_t ACC_INTRUSION_VREL_FACTOR[2*Acc_intrusion_vrel_factor_points] =
{
/* Example:
   -972,  1000,
   -694,  950,
   -556,  800,
   -417,  300,
   -278,  100,
      0,  0
*/

   -972,  1000,
   -694,  950,
   -556,  800,
   -417,  300,
   -278,  100,
      0,  0   

};

/*! [%] factor (0-1) dependent on relative acceleration */ 
/*relative acceleration[m/s^2] | a_rel factor (factor 0-1000)*/
factor_t ACC_INTRUSION_AREL_FACTOR[2*Acc_intrusion_arel_factor_points] = // PRQA S 3408
  /* date: 2018-12-18, reviewer: Niraj Mistry, reason: Not Safety critical */
{
  0,     1000,
  1000,  1000,
  2000,  1000,
  3000,  1000
};

/*! Intrusion scaling factor, max intrusion depending of headway setting [0 - 1] */
/* headway setting [%] | intrusion factor [0 - 1000] */
factor_t ACC_INTRUSION_HEADWAY_FACTOR[2*Acc_intrusion_headway_factor_points] =
{
/* Example:
  0,   0,
  50,  100,
  100, 150
*/

  0,   0,
  50,  100,
  100, 150
};

/*------ parameters which can be modified with some knowledge about the code --------*/

Acc_const times_t ACC_ALERT_MAX_SIM_TIME[2*Acc_max_sim_time_points] = 
{ /*m/s   sim_time */
   200, 1000,
  1000, 3000,
  3000, 4000
};

times_t ACC_ALERT_SIM_TIME_STEP = 500;

times_t ACC_ALERT_SUPRESS_ALERT_TIME[2*Acc_alert_supress_alert_time_points] =
{ /* estimated speed [m/s], supress time [s] */
  200,   400,
  1500, 1000
};

times_t ACC_ALERT_MIN_OUTPUT_TIME = 600;

/*estimated speed, alert distance*/
distance_t ACC_MIN_ALERT_THRES[2*Acc_min_alert_thres_points] =
{
  10,   100,
  100,  120,
  300,  150,
  1000, 200,
  8000, 1300
};

/*estimated speed, alert distance*/
distance_t ACC_MAX_ALERT_THRES[2*Acc_max_alert_thres_points] =
{
  10,   100,
  100,  180,
  300,  300,
  1000, 400,
  8000, 2500
};

/* relative speed, factor between object distance and requested distance */
Acc_const factor_t ACC_HEADWAY_ADD_FACTOR[2*Acc_headway_add_factor_points] =
{
 -600, 300,
 -300, 150,
    0, 50
};


Acc_const factor_t HP_HEADWAY_INCREASE_GRAD_FACTOR = 65; /*6.5% of requested distance/s*/

/* Vrel threshold for activating reduced distance ramp gradient */
Acc_const velocity_t HP_REDUCED_DISTRAMP_VREL_THRES = (-50);  /* 0.36 kph */
/* Aobj threshold for activating reduced distance ramp gradient */
Acc_const acceleration_t HP_REDUCED_DISTRAMP_AOBJ_THRES = (-350);  /* -0.35 m/s^2 */

/*! Factor for reduction of alert factor dependent on relative distance to min headway setting */
/* Relative Distance [factor] | Alert factor reduction factor [0-1000] */
factor_t HP_ALERT_FAC_REDUCTION_RELDIST_VREL[Hp_alert_fac_red_points_reldist*Hp_alert_fac_red_points_vrel] =
{ /* Object distance relative to short headway setting distance */
  //Input X = Obj Dist /(Dist for HS Short)
  /* 200,   600,    1000,   1400,   1800 */
  120,    300,    400,    550,    1000,   /* -600 */ /* Input Y = Relative Speed (m/s) */
  110,    270,    450,    600,    1000,   /* -300 */ 
  80,     250,    900,    1000,   1000,   /* 0 */
  60,     200,    950,    1000,   1000    /* 300 */
};

/*! Distance based max relative velocity for reduction of intrusion distance at obj initialization */
/*! [Obj distance (m) |, Relative velocity (m/s) */
Acc_const velocity_t HP_INTRUSION_RED_VREL_THRES[2*Hp_intrusion_red_vrel_thres_points] = 
{
  500,  -100,    /* At distance of 5m, 7 kph relative velocity is threshold */
  4000, -900  /* At distance of 40m, 40 kph relative velocity is threshold */
};


/*! [m/s²] max allowed deceleration to objects being in front of the next object in lane*/
acceleration_t ACC_MAX_DECEL_HIDDEN_OBJECT[2*Acc_max_decel_hidden_object_points] = 
{/*cutoutprob relevant (0) object, deceleration limit to hidden object*/
  20,  -1000,
  100, -3000  
};

/*! [m/s²] max allowed deceleration to objects being at the outer lanes (depending on own lane change potential)*/
acceleration_t ACC_MAX_DECEL_OUTER_LANES[2*Acc_max_decel_outer_lanes_points] = 
{
  60 ,  4000,
  100,  -500,
  120,  -2000 /* Usage of 120 reserved for OTS, HP_OTS_LC_PROB defined in hp_drint.c */
};

/*! [m/s^2] max allowed deceleration to an adjacent lane object depending on its cut in potential*/ 
/* cut in potential % / max deceleration*/
acceleration_t ACC_MAX_DECEL_CUT_IN[2*Acc_max_decel_cut_in_points] = 
{
  0,    4000,
  40,    500,
  60,   -300,
  80,   -800,
  100, -1500
};

/*! [] cut out depended factor for requested distance*/
/* cut out potential % / factor *1000*/
factor_t ACC_CUT_OUT_DISTANCE_FACTOR[2*Acc_cut_out_distance_factor_points] =
{
  40,  1000,
  60,  800,
  100, 600
};

/*! [a_obj (m/s^2) | max neg grad (m/s^3)*/
Acc_const acceleration_t ACC_OBJ_ACCEL_MAX_NEG_GRAD[2*Acc_obj_accel_max_neg_grad_points] = 
{
  -1500, -5000,
  -500,  -1500, 
   500,  -700
};

/*! [v_obj (m/s) | factor for max neg grad*/
Acc_const factor_t ACC_OBJ_ACCEL_GRAD_SPEED_FAC[2*Acc_obj_accel_grad_speed_fac_points] =
{
  700, 400,
  1500, 5000
};

/*! [a_obj_delat (m/s^2) | factor for max neg grad*/
Acc_const factor_t ACC_OBJ_ACCEL_GRAD_ACCEL_D_FAC[2*Acc_obj_accel_grad_accel_d_fac_pt] =
{
  -1000, 1000,
  -2000, 1500,
  -3000, 3000
};

#if (CFG_FCT_ACC_TTS_CONTROLLER)
/*! [object velocity | usage of calculated TTS acceleration] */
factor_t ACC_USE_CALC_TTS_FACTOR[2*Acc_use_calc_tts_factor_points] = // PRQA S 3408
  /* date: 2019-03-11, reviewer: Niraj Mistry, reason: Not Safety critical */
{
  400, 1000,
  1000, 0
};

#else 
/*! [time to object stop | usage of calculated deceleration] */
factor_t ACC_USE_CALC_DECEL_FACTOR[2*Acc_use_calc_decel_factor_points] =
{
  1500, 1000,
  4000, 0
};

/*! [ Object Distance[m] | Ideal relative speed [m/s] ] */
velocity_t ACC_TTS_DIST_VREL[2*Acc_tts_dist_vrel_points] = // PRQA S 3408
  /* date: 2019-03-11, reviewer: Niraj Mistry, reason: Not Safety critical */
{
  0,    50,
  500,  0,
  1500, -200,
  4000, -1100
};

/*! [Delta vrel [m/s] | Scaling factor to increase TTS Decel] */
factor_t ACC_TTS_DEL_VREL_FAC[2*Acc_tts_del_vrel_fac_points] = // PRQA S 3408
  /* date: 2019-03-11, reviewer: Niraj Mistry, reason: Not Safety critical */
{                   /* Default value to not use scaling factor: */
  -400, 150,        /*-300, 0, */
  0,    0          /*0,    0   */
};                  

/*! [Egospeed [m/s] | Scaling factor to increase TTS Decel] */
factor_t ACC_TTS_VEGO_FAC[2*Acc_tts_vego_fac_points] = // PRQA S 3408
  /* date: 2019-03-11, reviewer: Niraj Mistry, reason: Not Safety critical */
{                    /* Default value to not use scaling factor: */
  50,   1600,         /*200, 0, */
  400,  2500,
  1800, 1000          /*500, 0  */
};

Acc_const times_t HP_TTS_GRAD_LIMIT = (times_t)24; /* Configured to ramp out from TTS 0 for min of 5 secs */

/*! [m] Delta dist to obj for min deceleration output as Acc_standstill_accel_req */
distance_t HP_TTS_MIN_BRAKE_DIST = (distance_t)200; /* 2m Distance to end desired stop distance */  // PRQA S 3408
  /* date: 2019-03-11, reviewer: Niraj Mistry, reason: Not Safety critical */

#endif /* CFG_FCT_ACC_TTS_CONTROLLER */

Acc_const distance_t ACC_EMERGENCY_BRAKE_DISTANCE = (distance_t)100;

/*object relative speed | factor for using calculated decel against fuzzy decel*/
factor_t ACC_USE_APPROACH_DECEL_SPEED_FACTOR[2*Acc_use_approach_decel_speed_factor_points] = 
{
  -1000,  1000,
  -640,  800,
  -350 , 0
};

/*host vehicle velocity | factor for using calculated decel against fuzzy decel*/
factor_t ACC_USE_APPROACH_DECEL_V_HOST_FACTOR[2*Acc_use_approach_decel_v_host_factor_points] = 
{
  1500, 0,
  2500, 1000
};

/*Obj acceleration | factor for using calculated decel against fuzzy decel, at larger obj decel, fuzzy decel is to be weighted more*/
factor_t ACC_USE_APPROACH_DECEL_OBJ_ACCEL_FACTOR[2*Acc_use_approach_decel_obj_accel_factor_points] =  // PRQA S 3408
  /* date: 2019-03-11, reviewer: Niraj Mistry, reason: Not Safety critical */
{
  -800, 600,    
  -300, 1000
};

/*max intrusion decel | factor for using calculated decel against fuzzy decel*/
factor_t ACC_USE_APPROACH_DECEL_DECEL_FACTOR[2*Acc_use_approach_decel_decel_factor_points] = 
{
  -1400, 1000,
  -700, 900,
  -400, 800
};

/*relative acceleration [m/s^2] | factor for using calculated decel against fuzzy decel  (factor 0-1000)*/
factor_t ACC_USE_APPROACH_AREL_FACTOR[2*Acc_use_approach_arel_factor_points] = // PRQA S 3408
  /* date: 2018-12-18, reviewer: Niraj Mistry, reason: Not Safety critical */
{
  0,     1000,
  250,   1000,
  500,   950,
  1000,  850,
  1500,  750,
  2000,  650,
  2500,  600
};

/*distance error [%] | factor for using approach decel against fuzzy decel  (factor 0-1000)*/
factor_t ACC_USE_APPROACH_DIST_FACTOR[2*Acc_use_approach_dist_factor_points] =// PRQA S 3408
  /* date: 2018-12-18, reviewer: Niraj Mistry, reason: Not Safety critical */
{
  1300,   0,//0
  1600,   0,//150
  2000,   0,//500
  2200,   0 //600
};

/*! [] VRel threshold for blending fuzzy deceleration to dmin deceleration (relative acceleration depended)*/
velocity_t ACC_VREL_VAL_FUZZY_TO_DMIN = -300;  /* 3 m/s */ // PRQA S 3408
/* date: 2018-12-18, reviewer: Niraj Mistry, reason: Not Safety critical */
/*! [] Min factor of reduced fuzzy deceleration to dmin deceleration (relative acceleration depended)*/
factor_t ACC_MIN_FACTOR_FUZZY_TO_DMIN = 700;  /* Fuzzy deceleration reduced to 70% */ // PRQA S 3408
/* date: 2018-12-18, reviewer: Niraj Mistry, reason: Not Safety critical */
/*! [] Relative distance threshold for blending of Dmin output with fuzzy for long headway settings */
distance_t HP_FUZZY_HIGH_REL_DISTANCE_THRES = 1300; // PRQA S 3408
/* date: 2019-03-10, reviewer: Niraj Mistry, reason: Not Safety critical */


/* Object Dynamics Filters */
/*! [ms] Filter constant for object acceleration filtering, dependent on object acceleration */
/*! [ Object acceleration [m/s^2] | Filter constant [ms] ] */
sint16 ACC_OBJ_ACCEL_FILTER[2*Hp_obj_accel_filter_points] = 
{
  -1800,  400,
  -1350,  500,
  -1300,  1200,
  -700,   1200,
  -650,   500,
  1000,   500
};

/*! [ms] Filter constant for object relative velocity filtering, dependent on object acceleration */
/*! [ Object acceleration [m/s^2] | Filter constant [ms] ] */
sint16 ACC_OBJ_VREL_FILTER[2*Hp_obj_vrel_filter_points] = 
{
  -1300,  0,
  -1200,  100,
  -800,   100,
  -700,   0
};

/*! [Factor_t] Factor for object acceleration filter reduction based on object jerk */
/*! [ Object jerk [m/s^3] | Factor ] */
sint16 ACC_OBJ_JERK_FAC[2*Hp_obj_jerk_fac_points] = 
{
  1200,   1000,
  1500,   800,
  2200,   200
};

/* Hysterese for value close to "0":                FUZZY_INPUT_HYST_FAK * FUZZY_INPUT_HYST_NOMIN / FUZZY_INPUT_HYST_DENOM */
/* Hysterese for value >> (NOMIN + DENOM):          FUZZY_INPUT_HYST_FAK                                                   */

/* Parameter for hysteresis filtering of object acceleration */
Acc_const float32 OBJ_ACC_HYST_FACTOR = 0.15f;                  /* [m/ss] Hysteresis Width for complete range of object acceleration */
Acc_const float32 OBJ_ACC_HYST_NOMINATOR = 1.0f;                /* nominator factor for hysteresis of object acceleration at very low values  */
Acc_const float32 OBJ_ACC_HYST_DENOMINATOR = 0.6f;              /* denominator factor for hysteresis of object acceleration at very low values  */
/* for 0 as input variable                            -> HYST = 0.15 * 1.0 / 0.6 = 0.25 m/ss   */
/* for high input variable                            -> HYST = 0.15             = 0.15 m/ss   */
Acc_const float32 OBJ_ACC_HYST_ANTIWINDUP_ERROR_LIMIT = 0.28f;  /* max error in[m/s]  0.27 m/s due to offset potential offset drift */

boolean lc_ActHystObjAccel = FALSE;


/*------ parameters which shouldn't be modified without having deep knowledge about the code --------*/


Acc_const acceleration_t ACC_AMIN_OBJECT_LOST = 0;

Acc_const acceleration_t ACC_AMAX_OBJECT_LOST = 300;

Acc_const acceleration_t ACC_MIN_ACCEL_OBJECT_STATIONARY = 0;

velocity_t ACC_VREL_ESTIM_MIN = -10; /*0.1m/s */ 

factor_t ACC_END_ALERT_HYST_FACTOR = 150; /*15% more than alert distance*/

Acc_const times_t ACC_ALERT_SIM_VEHICLE_FILTER_TIME = 1000;

/*! [m/s] Minimum speed to judge stopping state of an object */
Acc_const velocity_t ACC_STOPPED_SPEED = 30;

/*! [m/s] maximum speed for a "crawling" vehicle*/
Acc_const velocity_t ACC_CRAWL_MAX_VELOCITY = (velocity_t)600; /*6m/s*/

/*! [s] maximum time the target vehicle may need to come to a full stop to call this situation a stop situation if object in front of the target has already stopped*/
Acc_const times_t ACC_SI_MAX_TIME_TO_STOP_2OBJ = (times_t)3000; /*3s*/

/*! [m/s²] object acceleration for a "go" signal in low speed situations*/
Acc_const acceleration_t ACC_SI_MIN_GO_ACCEL = (acceleration_t)800; /*0.8m/s²*/

/*! [m/s²] object acceleration for a "go" signal in low speed situations if object in front of target is faster and accelerating too*/
Acc_const acceleration_t ACC_SI_MIN_GO_ACCEL_2OBJ = (acceleration_t)500; /*0.5m/s²*/

Acc_const times_t ACC_SI_MAX_RELEVANT_TTC = (times_t)10000;

/* Criticality factor based on object deceleration */
/*! a_obj (m/s^2) | critical factor 0..1*/
Acc_const factor_t ACC_SI_CRIT_FACTOR_OBJ_ACCEL[2*Acc_si_crit_factor_obj_accel_points] = 
{
  -3500, 1000,
  -2500, 600,
  -1500, 150,
  -500, 0
};

/*! Criticality Scaling Factor for different headway setting */
/* headway setting [%] | intrusion factor [0 - 1000] */
factor_t ACC_SI_CRITICALITY_HEADWAY_FACTOR[2*Acc_si_criticality_headway_factor_points] = // PRQA S 3408
  /* date: 2019-03-10, reviewer: Niraj Mistry, reason: Not Safety critical */
{
  0,   1500,
  50,  1000,
  100, 700
};

/*! [%] criticality to object based on ttc value*/
Acc_const factor_t ACC_SI_CRITICALITY_FROM_TTC[2*Acc_si_crit_from_ttc_points] = 
{/*ttc (s), criticality*/
  1000,  1000,
  10000, 0
};

Acc_const gradient_t ACC_SI_CRIT_POS_GRAD = 250; /* 98%/s*/

Acc_const gradient_t ACC_SI_CRIT_NEG_GRAD = -200; /* 78%/s*/

/*! [m/s²] maximum allowed acceleration that can happen*/
Acc_const acceleration_t ACC_MAX_ALLOWED_ACCEL = (acceleration_t)4000;

/*! [m/s²] maximum allowed deceleration that can happen*/
Acc_const acceleration_t ACC_MAX_ALLOWED_DECEL = (acceleration_t)-6000;

/*! [s] System reaction time when braking requested*/
Acc_const times_t ACC_T_REACT_BRAKE = 500;

/*! [s] longitudinal visibility threshold related to vehicle velocity where ACC is disengaged (according to ISO 2[s]) */
Acc_const times_t ACC_T_VIS_DISENGAGE = (times_t)1900;

/*! [s] longitudinal visibility threshold related to vehicle velocity where ACC engagement is allowed (according to ISO 2[s]) */
Acc_const times_t ACC_T_VIS_ENGAGE = (times_t)2100;
 
/*! [s] ACC prediction time for host velocity prediction*/
//Acc_const times_t ACC_PREDICTED_REACTION_TIME = 1000;
times_t ACC_PREDICTED_REACTION_TIME = 500;
/*! [m/s²] Minimum deceleration resolution*/
Acc_const acceleration_t ACC_MIN_DECEL_RESOLUTION  = 100;

Acc_const acceleration_t ACC_EMERGENCY_BRAKE_DECELERATION = (acceleration_t)-1000;

Acc_const acceleration_t ACC_MINIMUM_CALCULATED_BRAKE_REQUEST = (acceleration_t)-100;

Acc_const acceleration_t ACC_OBJECT_DECEL_FOR_TTS_CALC = (acceleration_t)-500;

Acc_const velocity_t ACC_OBJECT_SPEED_FOR_TTS_CALC = (velocity_t)200;

Acc_const distance_t ACC_OBJECT_MAX_DISTANCE_FOR_TTS_CALC = (distance_t)20000;

Acc_const velocity_t ACC_OBJECT_REL_SPEED_FOR_TTS_CALC = (velocity_t)100;

Acc_const acceleration_t ACC_OBJECT_ACCEL_FOR_TTS_ZERO = (acceleration_t)300; /* 0.3 m/s^2 */

Acc_const velocity_t ACC_OBJECT_SPEED_FOR_TTS_ZERO = (velocity_t)50; /* 0.5 m/s */

Acc_const velocity_t ACC_REL_SPEED_FOR_TTS_ZERO = (velocity_t)-150; /* 1.5 m/s */

Acc_const times_t ACC_TTS_DEFAULT_VALUE = (times_t)10000;

acceleration_t ACC_STANDSTILL_ACCEL_REQ = (acceleration_t) -350;

Acc_const times_t ACC_TIMER_LIMIT_ACCEL_OBJ_LOST = (times_t)60;

/* Maximum speed for controller reaction on stationary objects */
Acc_const velocity_t ACC_DECEL_ON_STATIONARY_SPEED = (velocity_t)2000;

/*! Parameters for traffic situation estimation */
Acc_const acceleration_t ACC_MIN_OBJ_CRAWL_ACCEL = (acceleration_t)50; /*50 -> 0.05m/s²*/

Acc_const acceleration_t ACC_MIN_OBJ_STOP_ACCEL = (acceleration_t)10; /*10 -> 0.01m/s²*/

/*! [m] Maximum stopping distance of standing object (below this threshold, no drive off possible) */
Acc_const distance_t ACC_MAX_STOP_DISTANCE = (distance_t)750; /*7.5m*/
/* Minimum ACC distance for control usage */
/* Default value (no restriction) */
Acc_const distance_t ACC_MIN_CUST_PERF_DIST = (distance_t)0; /* 0m */ // PRQA S 3408
/* date: 2018-11-08, reviewer: Radhakrishna Vemula, reason: Not Safety critical */
/* Set default value */
Acc_const distance_t* pAcc_min_cust_perf_dist = &ACC_MIN_CUST_PERF_DIST;
Acc_const times_t ACC_SI_MAX_HYS_TIME_TO_STOP = (times_t)1000; /*1sec */
Acc_const times_t ACC_SI_MIN_HYS_TIME_TO_STOP = (times_t)500; /*0.5sec */

/* Threshold of critical TTC to use minimum needed deceleration for avoiding crash */
Acc_const times_t HP_CRITICAL_TTC_THRES = (times_t)1600;  /* 1.6s considered as extremely critical TTC threshold */

/*! max control distance for standing relevant object */
Acc_const distance_t ACC_MAX_DIST_REL_STANDING_OBJ = (distance_t)600; /* 6 meters max */

/* Parameters for Overtake Support */
#if (HP_CFG_OVERTAKE_SUPPORT_FEATURE)
/*! min ego speed for overtake support to be activated */
velocity_t ACC_OTSUPPORT_MIN_SPEED = (velocity_t) 1806; /* 1806 = 65 kph */
/*! max duration of time gap reduction phase for overtake support */
Acc_const times_t ACC_OTSUPPORT_TGR_MAX_DURATION = (times_t) 7000; /* 7s */
/*! max duration of time bypass phase for overtake support */
Acc_const times_t ACC_OTSUPPORT_BP_MAX_DURATION = (times_t) 4000; /* 4s */
/*!< Threshold for req acceleration for neighbouring object */
acceleration_t ACC_OTSUPPORT_OOI_ACCEL_THRESHOLD = (acceleration_t) 200; /* 200 = 0.2 m/s^2 */
/*!< Overtake support distance factor for low requested distance. New desired distance to object = Factor/1000 * (Original desired distance) */
factor_t ACC_OTSUPPORT_DISTANCE_FACTOR_LOW = (factor_t) 200;
/*!< Overtake support distance factor for high requested distance. New desired distance to object = Factor/1000 * (Original desired distance) */
factor_t ACC_OTSUPPORT_DISTANCE_FACTOR_HIGH = (factor_t) 500;
/*!< Init distance factor if feature is cancelled. Ramping out starts from this value. New desired distance to object = Factor/1000 * (Original desired distance) */
Acc_const factor_t ACC_OTSUPPORT_DIST_FACT_CANCEL = (factor_t) 575;
/*! [factor] Factor for reducing timegap for overtake support (headway setting dependent)*/
/*! [Headway setting [%] | factor for min reduced distance [0,1000] */
factor_t ACC_OTSUPPORT_MIN_DIST_FACTOR[2*Acc_otsupport_min_dist_factor_points] = 
{
  0,    700,  /* Initial TG of 1s reduced to 0.7s */
  50,   553,  /* Initial TG of 1.5s reduced to 0.8s */
  100,  450   /* Initial TG of 2s reduced to 0.9s */
};
/*! [factor] Number of cycles for which obj loss is counted for changing to pass by state (headway setting dependent)*/
/*! [Headway setting [%] |, No of cycles [0,100] */
Acc_const factor_t ACC_OTSUPPORT_LC_CYCLE_COUNTER[2*Acc_otsupport_min_dist_factor_points] = 
{
  0,    2,
  50,   10,
  100,  20
};
/*!< DMC deceleration delay time in approach situations */
Acc_const times_t ACC_OTSUPPORT_DECEL_DELAY = ( times_t )300;

/*!< Minimum acceleration during active Overtake Support */
Acc_const acceleration_t ACC_OTSUPPORT_MIN_APPROACH_ACCEL = ( acceleration_t )300;

/*!< Feature deactivation acceleration threshold in case of slow adjacent OOI before passby during Overtake Support */
acceleration_t ACC_OTSUPPORT_DEAC_ACCEL_ADJ_OBJ = ( acceleration_t )-2000;

#endif /* (HP_CFG_OVERTAKE_SUPPORT_FEATURE) */

/* Parameters for Overtake Prevention */
#if (HP_CFG_OVERTAKE_PREVENTION_FEATURE)
/*! min ego speed for overtake prevention to be activated */
velocity_t ACC_OTPREVENT_MIN_SPEED = (velocity_t) 1944; /* 1944 = 70 kph */
/*! Speed offset for overtake prevention to be deactivated */
velocity_t ACC_OTPREVENT_DEACT_SPEED_OFFSET = (velocity_t) 139; /* 139 = 5 kph */
/*!< Overtake prevention desired time gap to obj not on lane in ms */
times_t ACC_OTPREVENT_DES_TIMEGAP = (times_t) 600; /* 0.6s */
/*! min allowed deceleration for reaction to obj in neighbouring lane */
Acc_const acceleration_t ACC_OTPREVENT_MIN_ALLOWED_DECEL = (acceleration_t)-4000; /* -4 m/s^2 */
/*! Distance based relative velocity for activation of overtake prevention */
/*! [Obj distance (m) |, Relative velocity (m/s) */
velocity_t ACC_OTPREVENT_MAXRELSPEED[2*Acc_otprevent_maxrelspeed_points] = 
{
  500,  0,    /* At distance of 5m, 0 kph relative velocity is threhold */
  6500, -1444  /* At distance of 65m, 52 kph relative velocity is threhold */
};

/*! CutIn Probability dependent factor to increase desired distance to object when OTP is active */
/*! [Cutin Probability (%) |, Distance factor (n/a) */
factor_t ACC_OTP_CUTIN_DIST_FACTOR[2*Acc_otp_cutin_dist_factor_points] = 
{
  40,   0,    /* No increase in obj desired distance */
  80,   600,  /* 60% increase */
  100,  800   /* 80% increase */
};
#endif /* (HP_CFG_OVERTAKE_PREVENTION_FEATURE) */

/*************************************************************************************************************************
  Functionname:    HP_v_SelectParamSet                                                                             */ /*!

  @brief           Setting the acc parameter data as per customer request

  @description     Setting the acc parameter data as per customer request.

                    @startuml
                        Start
                        Partition HP_v_SelectParamSet {
                            -Initializing headway settings and FSR Acceleration 
                        }
                        end
                    @enduml

  @return          NA

  @param[in]       void

  @glob_in         NA
  @glob_out        ACC_pFsrMaxAccelPar: max acceleration/deceleration request
  @glob_out        ACC_pHeadwayMinDist: Struct to collect ACC parameter data
  @glob_out        ACC_pHeadwayMaxDist: Struct to collect ACC parameter data

  @created         12.12.2018
  @changed         12.12.2018

  @traceability    doors://rbgs854a:40000/?version=2&prodID=0&view=00000002&urn=urn:telelogic::1-503e822e5ec3651e-O-117-0008a201

  @author          Radhakrishna Vemula | Radhakrishna.Vemula@continental-corporation.com | +91 (80) 6679-1353
*************************************************************************************************************************/
void HP_v_SelectParamSet(void)
{
  /*! Use this function to set the pointer to correct parameter variable, depending of customer specific modes */
  ACC_pFsrMaxAccelPar = ACC_FSR_MAX_ACCEL_DEFAULT;
  ACC_pHeadwayMinDist = ACC_HEADWAY_MIN_DIST_DEFAULT;
  ACC_pHeadwayMaxDist = ACC_HEADWAY_MAX_DIST_DEFAULT;
}

#endif  /* ((FCT_CFG_LOHP_COMPONENT) && (FCT_CFG_ACC_HEADWAY_PLANNER)) */

/** @} end defgroup */
