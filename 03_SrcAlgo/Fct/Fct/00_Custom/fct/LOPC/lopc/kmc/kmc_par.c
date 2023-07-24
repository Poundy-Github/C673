/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC/LOPC/KMC (Adaptive Cruise Control - Longitudinal Planner and Controller - Kinematic Motion Control)

PACKAGENAME:               kmc_par.c

DESCRIPTION:               Parameter file for CruiseControl functionality in KMC

AUTHOR:                    Mistry Niraj (uidq5738)

CREATION DATE:             24.02.2017

VERSION:                   $Revision: 1.13.8.9 $

LEGACY VERSION:            Revision: 1.35.1.1
**************************************************************************** */

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/*!
@defgroup         kmc_par   Kmc_Parameters
@ingroup          kmc_custom
@brief            Parameter file for KMC
@{
*/

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "kmc.h"

#if ((FCT_CFG_LOPC_COMPONENT) && (FCT_CFG_CC) && (LOPC_CFG_KMC))

/*------ parameters which can be modified without deep knowledge about the code --------*/

/*for limiter function*/
Cc_const setspeed_t LIM_MIN_VSET_KMH = 30U;
Cc_const setspeed_t LIM_MAX_VSET_KMH = 180U;
Cc_const setspeed_t LIM_MIN_VSET_MPH = 20U;
Cc_const setspeed_t LIM_MAX_VSET_MPH = 110U;

/*cruise control*/
Cc_const setspeed_t CC_VSET_STEP_LEVEL_1_MPH = 5U;
Cc_const setspeed_t CC_VSET_STEP_LEVEL_1_KMH = 5U;
Cc_const setspeed_t CC_VSET_STEP_LEVEL_2_MPH = 5U;
Cc_const setspeed_t CC_VSET_STEP_LEVEL_2_KMH = 5U;
Cc_const setspeed_t CC_VMAX_KMH = 155U;
Cc_const setspeed_t CC_VMAX_MPH = 155U;
Cc_const setspeed_t CC_OFF_THRES_MPH = 2U;
Cc_const setspeed_t CC_MIN_V_ENGAGE_MPH = 0U;
Cc_const setspeed_t CC_OFF_THRES_CRUISE_MPH = 20U;
Cc_const setspeed_t CC_MAX_VSET_MPH = 110U;
Cc_const setspeed_t CC_MIN_VSET_MPH = 20U;
Cc_const setspeed_t CC_MIN_VSET_USA_MPH = 20U;
Cc_const setspeed_t CC_MIN_V_ENGAGE_USA_MPH = 0U;

Cc_const setspeed_t CC_OFF_THRES_KMH = 2U;
Cc_const setspeed_t CC_MIN_V_ENGAGE_KMH = 0U;
Cc_const setspeed_t CC_OFF_THRES_CRUISE_KMH = 30U;
Cc_const setspeed_t CC_MAX_VSET_KMH = 130U;
Cc_const setspeed_t CC_MIN_VSET_KMH = 30U;
Cc_const times_t CC_START_T_REP_FUNC = 1000U;
Cc_const times_t CC_T_REP_FUNC = 500U;
Cc_const times_t CC_T_DRIVE_OFF_SMOOTH = Cc_default_drive_off_smooth_time;

#if (CFG_FCT_CC_USE_CONTROL_CRITICALITY)

/* [m/s³] Maximum allowed deceleration gradient in critical situations within ISO norm 22179:2009 limits */
/* v_ego [m/s] - max jerk [m/s³] */
Cc_const acceleration_t MAX_DECEL_GRADIENT_CRITICAL[2*max_decel_gradient_critical_points] = 
{
 500,   -5000,  /*  5m/s - 5 m/s³ */
 2000,  -2500   /* 20m/s - 2.5 m/s³ */
};

/* Factor to increase the acceleration request gradient in critical traffic situations */
/* criticality [%] - gain factor(%) */
Cc_const factor_t CRITICALITY_ACCEL_GRADIENT_GAIN[2*accel_gradient_gain_points] = 
{
 0,   100,  /*   0% - x1 */
 100, 200   /* 100% - x2 */
};
#endif /* (CFG_FCT_CC_USE_CONTROL_CRITICALITY) */

#if (CFG_FCT_CC_SMOOTH_ACCEL_REQUEST)

/* Factor to reduce filter time in critical traffic situations */
/* criticality [%] - filter time [ms] */
Cc_const times_t CRITICALITY_ACCEL_FILTER_TIME[2*accel_filter_time_time_points] = 
{
 0U,   300U,  /*   0% - 300 ms */
 100U, 125U   /* 100% - 125 ms */
};

#if (KMC_NO_SMOOTH_JERK_IN_LOW_SPEED)
/* Factor to reduce filter time dependent on vehicle speed */
/* Ego speed [m/s] - Factor [Factor_s] */
factor_t EGOSPEED_ACCEL_FILTER_TIME[2*egospeed_accel_filter_time_points] = 
{
  0,   50,   /* 0 m/s - Factor 0.050 */
  400, 1000  /* 4 m/s - Factor 1 */
};
/* Max speed threshold for recognizing fast brake release */
Cc_const velocity_t KMC_FAST_BRAKE_RELEASE_SPEED_THRES = 400;             /* 4 m/s */
/* Max acceleration threshold for recognizing fast brake release */
Cc_const acceleration_t KMC_FAST_BRAKE_RELEASE_ACCEL_HIGH_THRES = -3000;  /* -3 m/s^2 */
/* Min acceleration threshold for stopping fast brake release */
Cc_const acceleration_t KMC_FAST_BRAKE_RELEASE_ACCEL_LOW_THRES = -1000;   /* -1 m/s^2 */
/* Max speed threshold for not smoothing negative gradient */
Cc_const velocity_t KMC_LOW_SPEED_THRES_NEG_SMOOTH_JERK = 1800;           /* 18 m/s */
#endif  /* KMC_NO_SMOOTH_JERK_IN_LOW_SPEED */
#endif /* (CFG_FCT_CC_SMOOTH_ACCEL_REQUEST) */

/*m/s        m/s²*/
acceleration_t CC_ACCEL_CURVE[2*Cc_curve_points] = 
{ /*BMW*/
 -1666,     -1800,
 -833,      -1500,
 -555,      -1250,
 -277,      -800,
 -55,       -200,
 -27,       -110,
 -8,        -40,
 -4,        -20,
 0,          0,
 4,          20,
 8,          40,
 27,         135,
 55,         275,
 138,        690,
 277,        1385,
 555,        2100,
 833,        2100,
 1250,       2100
};

acceleration_t CC_MAX_VEHICLE_ACCEL[2*Cc_max_vehicle_accel_points] = 
{
  500,  4000, /*  18kph */
  2000,  2000  /*  72kph */
};

acceleration_t CC_MAX_VEHICLE_DECEL[2*Cc_max_vehicle_decel_points] = 
{
   500, -5000,
  2000, -3500
};

#if(!CFG_FCT_CC_USE_CUSTOM_ACCEL_LIMITS)
/*Maximum allowed acceleration for CC */
/* [m/s], [m/s²] */
Cc_const acceleration_t CC_MAX_ACCEL_CURVE[2*Cc_max_accel_curve_points] = 
{
 600,   2000,
 2000,  1500,
 5000,  800,
 7000,  400 
};

#else

/*Maximum allowed acceleration for CC EU */
/* [m/s], [m/s²] */
acceleration_t CC_MAX_ACCEL_CURVE_NORMAL[2*Cc_max_accel_curve_points] = // PRQA S 3408
/* date: 2018-04-18, reviewer: Ravi Kiran Gurrala, reason: Not Safety critical */
{
    0,   850,
    5,  1600,
  500,  1600,
 1400,  900,
 2000,  800,
 3000,  800,
 5500,  800
};

/*Maximum allowed acceleration for CC not EU */
/* [m/s], [m/s²] */
//Cc_const acceleration_t CC_MAX_ACCEL_CURVE_NOT_EU[2*Cc_max_accel_curve_points] = 
//{
// 600,   2000,
// 2000,  1500,
// 5000,  800,
// 7000,  400 
//};

/*Maximum allowed acceleration for CC during following */
/* [m/s], [m/s²] */
//Cc_const acceleration_t CC_MAX_ACCEL_CURVE_FOLLOW[2*Cc_max_accel_curve_points] = 
//{
// 600,   2000,
// 2000,  1500,
// 5000,  800,
// 7000,  400 
//
//};

#if (CFG_FCT_CC_USE_DRIVE_MODE)
/*Maximum allowed acceleration for CC in Sport mode */
/* [m/s], [m/s²] */
acceleration_t CC_MAX_ACCEL_CURVE_SPORT[2*Cc_max_accel_curve_points] = // PRQA S 3408
/* date: 2018-04-18, reviewer: Ravi Kiran Gurrala, reason: Not Safety critical */
{
     0,   850,
     5,  2000,
   500,  2000,
  1400,  1600,
  2000,  1400,
  3000,  1250,
  5500,  1000
};

/*Maximum allowed acceleration for CC in Eco/Comfort mode */
/* [m/s], [m/s²] */
acceleration_t CC_MAX_ACCEL_CURVE_ECO[2*Cc_max_accel_curve_points] = // PRQA S 3408
/* date: 2018-04-18, reviewer: Ravi Kiran Gurrala, reason: Not Safety critical */
{
     0,   850,
     5,  1400,
   500,  1400,
  1400,   800,
  2000,   600,
  3000,   550,
  5500,   500
};
#endif

/* Set default value*/
acceleration_t* pCC_MaxAccel = CC_MAX_ACCEL_CURVE_NORMAL;
#endif

#if (CFG_FCT_USE_ACCEL_GAIN)
Cc_const acceleration_t CC_ACCEL_LIMIT = 1200;
#endif

acceleration_t CC_DECEL_LIMIT_NORMAL = -1600;// PRQA S 3408
/* date: 2018-04-18, reviewer: Ravi Kiran Gurrala, reason: Not Safety critical */
#if (CFG_FCT_CC_USE_DRIVE_MODE)
acceleration_t CC_DECEL_LIMIT_SPORT = -2000;// PRQA S 3408
/* date: 2018-04-18, reviewer: Ravi Kiran Gurrala, reason: Not Safety critical */
acceleration_t CC_DECEL_LIMIT_ECO = -1200;// PRQA S 3408
/* date: 2018-04-18, reviewer: Ravi Kiran Gurrala, reason: Not Safety critical */
#endif
acceleration_t* pCC_DecelLimit = &CC_DECEL_LIMIT_NORMAL;

acceleration_t CC_MAX_DECEL_DURING_OVERRIDE = -150; /* default Accel_min = -32767 */

acceleration_t CC_MAX_DECEL_AFTER_OVERRIDE = -600;

acceleration_t CC_MAX_DECEL_AFTER_ENGAGE = -400;

Cc_const gradient_t CC_ACCELMODE_MAX_NEG_GRAD = -800;

Cc_const gradient_t CC_ACCELMODE_MAX_POS_GRAD = 600;

/* v_ego [m/s] - min speedometer offset [m/s] */
Cc_const velocity_t CC_MIN_VALID_SPEEDO_OFFSET[2*Cc_min_valid_speedo_offset_points] =
{
      0, 0,   /*   0 kph - 0 kph   */
   2778, 0,   /* 100 kph - 0 kph   */
   6000, 0    /* 216 kph - 0 kph */
};

/* v_ego [m/s] - max speedometer offset [m/s] */
Cc_const velocity_t CC_MAX_VALID_SPEEDO_OFFSET[2*Cc_max_valid_speedo_offset_points] =
{
      0, 278,   /*   0 kph - +10 kph   */
   2778, 278,   /* 100 kph - +10 kph   */
   6000, 600    /* 216 kph - +21.6 kph */
};

/* CC brake release gradient limit */
/* velocity [m/s], jerk [m/s^3] */
acceleration_t CC_MAX_POS_GRAD_NORMAL_NEG_ACCEL[2*Cc_pos_grad_neg_accel_points] = // PRQA S 3408
/* date: 2018-04-18, reviewer: Ravi Kiran Gurrala, reason: Not Safety critical */
{
  100 , 1500,
  1500, 1500
};

/* CC acceleration gradient limit */
/* velocity [m/s], jerk [m/s^3] */
acceleration_t CC_MAX_POS_GRAD_NORMAL_POS_ACCEL[2*Cc_pos_grad_pos_accel_points] = // PRQA S 3408
/* date: 2018-04-18, reviewer: Ravi Kiran Gurrala, reason: Not Safety critical */
{
  100 , 1000,
  1500, 1000
};

#if (CFG_FCT_CC_USE_DRIVE_MODE)
/* CC brake release gradient limit */
/* velocity [m/s], jerk [m/s^3] */
acceleration_t CC_MAX_POS_GRAD_SPORT_NEG_ACCEL[2*Cc_pos_grad_neg_accel_points] = // PRQA S 3408
/* date: 2018-04-18, reviewer: Ravi Kiran Gurrala, reason: Not Safety critical */
{
  100 , 2500,
  1500, 2500
};

/* CC acceleration gradient limit */
/* velocity [m/s], jerk [m/s^3] */
acceleration_t CC_MAX_POS_GRAD_SPORT_POS_ACCEL[2*Cc_pos_grad_pos_accel_points] = // PRQA S 3408
/* date: 2018-04-18, reviewer: Ravi Kiran Gurrala, reason: Not Safety critical */
{
  100 , 2000,
  1500, 2000
};

/* CC brake release gradient limit */
/* velocity [m/s], jerk [m/s^3] */
acceleration_t CC_MAX_POS_GRAD_ECO_NEG_ACCEL[2*Cc_pos_grad_neg_accel_points] = // PRQA S 3408
/* date: 2018-04-18, reviewer: Ravi Kiran Gurrala, reason: Not Safety critical */
{
  100 , 1000,
  1500, 1000
};

/* CC acceleration gradient limit */
/* velocity [m/s], jerk [m/s^3] */
acceleration_t CC_MAX_POS_GRAD_ECO_POS_ACCEL[2*Cc_pos_grad_pos_accel_points] = // PRQA S 3408
/* date: 2018-04-18, reviewer: Ravi Kiran Gurrala, reason: Not Safety critical */
{
  100 , 500,
  1500, 500
};
#endif

acceleration_t* pCC_MaxPosGradPosAccel = CC_MAX_POS_GRAD_NORMAL_POS_ACCEL;
acceleration_t* pCC_MaxPosGradNegAccel = CC_MAX_POS_GRAD_NORMAL_NEG_ACCEL;


/* CC deceleration gradient limit */
/* velocity [m/s], jerk [m/s^3] */
acceleration_t CC_MAX_NEG_GRAD_NORMAL[2*Cc_neg_grad_points] = // PRQA S 3408
/* date: 2018-04-18, reviewer: Ravi Kiran Gurrala, reason: Not Safety critical */
{
  800,  -1000,
  1500, -1000
};

/* velocity [m/s], jerk [m/s^3] */
#if (CFG_FCT_CC_USE_DRIVE_MODE)
acceleration_t CC_MAX_NEG_GRAD_SPORT[2*Cc_neg_grad_points] = // PRQA S 3408
/* date: 2018-04-18, reviewer: Ravi Kiran Gurrala, reason: Not Safety critical */
{
  800,  -1200,
  1500, -1200
};

/* velocity [m/s], jerk [m/s^3] */
acceleration_t CC_MAX_NEG_GRAD_ECO[2*Cc_neg_grad_points] = // PRQA S 3408
/* date: 2018-04-18, reviewer: Ravi Kiran Gurrala, reason: Not Safety critical */
{
  800,  -800,
  1500, -800
};
#endif

acceleration_t* pCC_MaxNegGrad = CC_MAX_NEG_GRAD_NORMAL;

/* Factor for reduction of positive acceleration gradient when transition from ACC to CC mode */
factor_t CC_ACC_TO_CC_TRANSITON_FACTOR_DEFAULT = 1000;// PRQA S 3408
/* date: 2018-04-18, reviewer: Ravi Kiran Gurrala, reason: Not Safety critical */
#if (CFG_FCT_CC_USE_DRIVE_MODE)
factor_t CC_ACC_TO_CC_TRANSITON_FACTOR_SPORT = 500;// PRQA S 3408
/* date: 2018-04-18, reviewer: Ravi Kiran Gurrala, reason: Not Safety critical */
factor_t CC_ACC_TO_CC_TRANSITON_FACTOR_ECO = 500;// PRQA S 3408
/* date: 2018-04-18, reviewer: Ravi Kiran Gurrala, reason: Not Safety critical */
#endif
Cc_const factor_t* pCC_AccToCcTransitionFactor = &CC_ACC_TO_CC_TRANSITON_FACTOR_DEFAULT;


Cc_const gradient_t CC_OFF_MAX_POS_GRAD = 2000; 

Cc_const gradient_t CC_OFF_MAX_NEG_GRAD = -2000; /*600*/

Cc_const gradient_t CC_OFF_MAX_POS_GRAD_RAPID = 8000;

Cc_const gradient_t CC_OFF_MAX_NEG_GRAD_RAPID = -4000; /*-4000*/

Cc_const acceleration_t CC_MIN_DECEL_BRAKE_ONLY = -500;

Cc_const times_t CC_T_ABS_ACT_INH = 200U;

Cc_const times_t CC_T_ESP_ACT_INH = 200U;

Cc_const times_t CC_T_TCS_ACT_INH = 200U;

times_t CC_T_DRIVER_DOOR_INH = 400U;

times_t CC_T_DRIVER_SEAT_INH = 400U;


/*------ parameters which can be modified with some knowledge about the code --------*/
Cc_const times_t CC_TFILT_POS_ALAT = 0U; /*400*/
Cc_const times_t CC_TFILT_NEG_ALAT = 0U; /*1000*/



/* Curves for lateral acceleration limiter */

/* Longitudinal acceleration reqeust dependent on error from lateral acceleration */
/* (a lat max - a lat ego) [m/s²]   (a long max) [m/s²] */
acceleration_t CC_LONG_ACCEL_CURVE[2*Cc_long_accel_curve_points] = 
{
 -1000,  -800,
     0,     0,
  3000,  2000,
  3600,  3000,
  4000,  3000,
  5000,  3000,
  6000,  3000,
  7000,  3000
};

/* Max allowed lateral acceleration */
/* Ego velocity [m/s], Acceleration [m/s²] */
acceleration_t CC_ALAT_SPEED_CURVE_NORMAL[2*Cc_alat_speed_curve_points] = // PRQA S 3408
/* date: 2020-06-02, reviewer: Letian Zhang, reason: Not Safety critical */
{/*v*/ /*a*/
  500, 3600,
 1200, 2000,
 1900, 1900,
 2700, 1800,
 6000, 1500,
 7500, 1400
};

#if (CFG_FCT_CC_USE_DRIVE_MODE)
/* Ego velocity [m/s], Acceleration [m/s²] */
acceleration_t CC_ALAT_SPEED_CURVE_SPORT[2*Cc_alat_speed_curve_points] = // PRQA S 3408
/* date: 2020-06-02, reviewer: Letian Zhang, reason: Not Safety critical */
{/*v*/ /*a*/
   500, 3800,
  1200, 2200,
  1900, 2100,
  2700, 2000,
  6000, 1700,
  7500, 1600
};

/* Ego velocity [m/s], Acceleration [m/s²] */
acceleration_t CC_ALAT_SPEED_CURVE_ECO[2*Cc_alat_speed_curve_points] = // PRQA S 3408
/* date: 2020-06-02, reviewer: Letian Zhang, reason: Not Safety critical */
{/*v*/ /*a*/
   500, 3400,
  1200, 1800,
  1900, 1700,
  2700, 1600,
  6000, 1300,
  7500, 1200
};
#endif

acceleration_t* pCC_ALatSpeedCurve = CC_ALAT_SPEED_CURVE_NORMAL;
#if (KMC_INC_LAT_LIMITS_IN_FOLLOW)
/* Factor to increase lateral acceleration limitation when in follow mode */
Cc_const factor_t CC_ALAT_FOLLOWMODE_ACCEL_INC_FAC = 300;
/* Minimum speed for activating reduced suppression of lateral acceleration in follow mode */
Cc_const velocity_t CC_ALAT_FOLLOWMODE_MIN_SPEED = 0; /* 0kph */
#endif

#if (CFG_FCT_USE_ACCEL_GAIN)

Cc_const acceleration_t CC_ACCEL_GAIN_CURVE[2*Cc_accel_gain_curve_points] = 
{
 0,     2500,
 2000,  1500,
 5000,  400,
 7000,  0 
};

#endif

#if (CFG_FCT_CC_USE_ACCEL_BAND_MODIFICATION)
/*speed, acceldif*/
Cc_const acceleration_t ACC_DECREASE_MINACCEL_CURVE[2*Acc_decrease_minaccel_points] = 
{
  500 , 0,
  1000, -100,
  1500, 0
};

/*speed, acceldif*/
Cc_const acceleration_t ACC_INCREASE_MAXACCEL_CURVE[2*Acc_increase_maxaccel_points] = 
{
  500,  0,
  1000, 100,
  1500, 0
};
#endif

Cc_const acceleration_t LIM_ACCEL_CURVE[2*Lim_curve_points] = 
{
  -7000,-1200,
    -555,-999,
    -277,-700,
    -138,-400,
    -55,-200,
    -27,-100,
    0,0,
    14,100,
    27,200,
    55,300,
    138,800,
    277,1700,
    555,3000,
    7000,12000
};

Cc_const acceleration_t ACC_MAX_ACCEL_DISENGAGE = (acceleration_t)10000;

Cc_const acceleration_t ACC_MIN_ACCEL_DISENGAGE = (acceleration_t)-10000;

/*------ parameters which shouldn't be modified without having deep knowledge about the code --------*/

Cc_const gradient_t LIM_OFF_MAX_POS_GRAD = 2000;

Cc_const gradient_t LIM_OFF_MAX_NEG_GRAD = -2000;

Cc_const gradient_t LIM_MAX_POS_GRAD = 2500;

Cc_const gradient_t LIM_MAX_NEG_GRAD = -4000;

Cc_const gradient_t LIM_OVERRIDE_MAX_POS_GRAD = 3500;

Cc_const gradient_t LIM_OVERRIDE_MAX_NEG_GRAD = -3500;

Cc_const gradient_t LIM_REST_MIN_GRAD = 500;

Cc_const acceleration_t LIM_ACCEL_LIMIT = 10000;

Cc_const acceleration_t LIM_DECEL_LIMIT = -2500;

Cc_const setspeed_t PLIM_THRES_KMH = 7U;

Cc_const setspeed_t PLIM_HYST_KMH = 2U;

Cc_const setspeed_t PLIM_THRES_MPH = 4U;

Cc_const setspeed_t PLIM_HYST_MPH = 1U;

Cc_const gradient_t CC_MIN_ENGAGE_A_GRAD = -10000;

Cc_const gradient_t CC_MAX_ENGAGE_A_GRAD = 10000;

velocity_t CC_A_POS_OFFSET = 83;

Cc_const velocity_t CC_A_POS_OFFSET_MAX = 138;

velocity_t CC_A_NEG_OFFSET = 83;

Cc_const velocity_t CC_A_NEG_OFFSET_MAX = -414;

Cc_const times_t CC_TMAX_DECEL_ONLY = 5000U;

times_t CC_TMAX_DECEL_LIMIT = 65533u;

#if (CFG_FCT_CC_USE_ACCEL_DECEL_MODE)
Cc_const velocity_t CC_V_ACCELMODE = 6000;

Cc_const velocity_t CC_V_ACCELMODE_INIT = 277;

Cc_const velocity_t CC_V_DECELMODE = -6000;

Cc_const velocity_t CC_V_DECELMODE_INIT = -277;
#endif  /* CFG_FCT_CC_USE_ACCEL_DECEL_MODE */

Cc_const gradient_t CC_MAX_GRAD_RELEASE_BRAKE = 3500; /* 2500*/

Cc_const gradient_t CC_REST_MIN_GRAD = 150;

Cc_const velocity_t CC_SMOOTH_GRADIENT_POS_MIN_VELOCITY = (velocity_t)100;

/* Smoothing time constant for positive jerk */
/* Ego velocity [m/s], Smoothing constant [ms] */
Cc_const sint16 CC_T_SMOOTH_GRADIENT_POS_TIME_DEFAULT[2*Cc_smooth_gradient_pos_time_points] = // PRQA S 3408
/* date: 2018-04-18, reviewer: Ravi Kiran Gurrala, reason: Not Safety critical */
{
     0, 350,
   500, 500
};

#if (CFG_FCT_CC_USE_DRIVE_MODE)
/* Ego velocity [m/s], Smoothing constant [ms] */
Cc_const sint16 CC_T_SMOOTH_GRADIENT_POS_TIME_SPORT[2*Cc_smooth_gradient_pos_time_points] =// PRQA S 3408
/* date: 2018-04-18, reviewer: Ravi Kiran Gurrala, reason: Not Safety critical */ 
{
     0, 300,
   500, 500
};

/* Ego velocity [m/s], Smoothing constant [ms] */
Cc_const sint16 CC_T_SMOOTH_GRADIENT_POS_TIME_ECO[2*Cc_smooth_gradient_pos_time_points] = // PRQA S 3408
/* date: 2018-04-18, reviewer: Ravi Kiran Gurrala, reason: Not Safety critical */
{
     0, 600,
   500, 800
};
#endif

Cc_const sint16* pCC_SmoothGradientPosTime = CC_T_SMOOTH_GRADIENT_POS_TIME_DEFAULT;

#if (CFG_FCT_CC_USE_SMOOTH_JERKS)
/* Smoothing time constant for negative jerk */
/* Ego velocity [m/s], Smoothing constant [ms] */
Cc_const sint16 CC_T_SMOOTH_GRADIENT_NEG_TIME_DEFAULT[2*Cc_smooth_gradient_neg_time_points] = // PRQA S 3408
/* date: 2018-04-18, reviewer: Ravi Kiran Gurrala, reason: Not Safety critical */
{
     0, 300,
   500, 450
};

#if (CFG_FCT_CC_USE_DRIVE_MODE)
/* Ego velocity [m/s], Smoothing constant [ms] */
Cc_const sint16 CC_T_SMOOTH_GRADIENT_NEG_TIME_SPORT[2*Cc_smooth_gradient_neg_time_points] = // PRQA S 3408
/* date: 2018-04-18, reviewer: Ravi Kiran Gurrala, reason: Not Safety critical */
 {
     0, 300,
   500, 500
};

/* Ego velocity [m/s], Smoothing constant [ms] */
Cc_const sint16 CC_T_SMOOTH_GRADIENT_NEG_TIME_ECO[2*Cc_smooth_gradient_neg_time_points] = // PRQA S 3408
/* date: 2018-04-18, reviewer: Ravi Kiran Gurrala, reason: Not Safety critical */
{
     0, 600,
   500, 800
};
#endif

Cc_const sint16* pCC_SmoothGradientNegTime = CC_T_SMOOTH_GRADIENT_NEG_TIME_DEFAULT;

/* Acceleration error [m/s^2], gain [Factor] */
factor_t KMC_SMOOTH_GRADIENT_GAIN[2*Kmc_smooth_gradient_gain_points] =
{
  300,  1000,
  800,  1000,
  1200, 1000
};

#endif /* CFG_FCT_CC_USE_SMOOTH_JERKS */

Cc_const acceleration_t CC_MAX_DECEL_DURING_ACCEL_MODE = -800;

Cc_const acceleration_t CC_MAX_ACCEL_DURING_DECEL_MODE = 400;

#if (CFG_FCT_CC_USE_ACCEL_BAND_MODIFICATION)

Cc_const acceleration_t CC_ACCEL_BAND_SCALE[2*Cc_accel_band_scale_points] =
{   
     0,  100,
    500, 1000
};

/*commanded accel, band*/
Cc_const acceleration_t CC_ACCEL_BAND_POS[2*Cc_max_accel_band_pos_points] = 
{
 0,     50,
 1000,  400
 
};

Cc_const acceleration_t CC_ACCEL_BAND_NEG[2*Cc_max_accel_band_neg_points] = 
{
 -2000, 500,
  0,    50 
};


/*
   Auch hier scheint der Verlauf der Beschleunigungsanforderung smoother zu verlaufen. 
   subjektiv sieht es viel bessr aus.
*/
Cc_const gradient_t CC_ACCEL_BAND_GRADIENT = 800; /*400*/

/* Der CC_ACCEL_BAND_APPROACH_GRADIENT bewirkt, das der Gradient nicht so steil wird. siehe 17_46_46 
   besser noch 14_48_46 mit Grad = 400
   hat bisher nur subjektiven Charakter. Allerdings vermute ich das die Bremse bessr damit klarkommt,
   der Gradient nciht so steil ist.800 ist gut!
*/
Cc_const gradient_t CC_ACCEL_BAND_APPROACH_GRADIENT = 600; /*150, 50*/

#endif /* (CFG_FCT_CC_USE_ACCEL_BAND_MODIFICATION) */

#if (FCT_CFG_SLA_FEATURE)
/* ********************** ADD SPEED LIMIT ASSIST PARAMETERS HERE ************************* */

/*! V_ego [m/s], [m] Speed limit control distance befor limit position if acceleration is requested */
Cc_const distance_t CC_SLA_CTRL_DIST_BEFOR_LIMIT_ACCEL[2*Cc_sla_ctrl_dist_befor_limit_accel_points] =
{
  1350, 2000,
  2780, 4200
};

/*! V_ego [m/s], [m] Speed limit control distance befor limit position if deceleration is requested */
Cc_const distance_t CC_SLA_CTRL_DIST_BEFOR_LIMIT_DECEL[2*Cc_sla_ctrl_dist_befor_limit_decel_points] =
{
  1400, 2000,
  2800, 4500,
  4500, 5500
};

/*! V_ego [m/s], [m] Speed limit control distance after limit position */
Cc_const distance_t CC_SLA_CTRL_DIST_AFTER_LIMIT[2*Cc_sla_ctrl_dist_after_limit_points] =
{
  1400, 2000,
  2800, 7000,
  4500, 11000
};

/*! V_ego [m/s], [m/s²] Minimum SLA deceleration limit */
Cc_const acceleration_t CC_SLA_MIN_DECEL_LIMIT[2*Cc_sla_min_decel_limit_points] =
{
  1400, -1200,
  2800, -1500,
  4500, -2400
};

/*! V_ego [m/s], [m/s²] Maximum SLA deceleration limit */
Cc_const acceleration_t CC_SLA_MAX_DECEL_LIMIT[2*Cc_sla_max_decel_limit_points] =
{
  1400, -1100,
  2800, -1100,
};

/*! [kph] Minimum speed limit set by driver (only relevant with SLA feature) */
Cc_const setspeed_t CC_SLA_MIN_DRIVER_SPEED_KMH = (setspeed_t)16;

/*! [mph] Minimum speed limit set by driver (only relevant with SLA feature) */
Cc_const setspeed_t CC_SLA_MIN_DRIVER_SPEED_MPH = (setspeed_t)10;

/*! [kph] Speedometer speed value for switch from SLA acceleration request to common cruise control acceleration */
Cc_const setspeed_t CC_SLA_COMMON_ACCEL_SPEED_DIFF_KMH = (setspeed_t)200;

/*! [mph] Speedometer speed value for switch from SLA acceleration request to common cruise control acceleration */
Cc_const setspeed_t CC_SLA_COMMON_ACCEL_SPEED_DIFF_MPH = (setspeed_t)120;

/*! [kph] Speedometer speed value for switch from SLA deceleration request to common cruise control acceleration */
Cc_const setspeed_t CC_SLA_COMMON_DECEL_SPEED_DIFF_KMH = (setspeed_t)100;

/*! [mph] Speedometer speed value for switch from SLA deceleration request to common cruise control acceleration */
Cc_const setspeed_t CC_SLA_COMMON_DECEL_SPEED_DIFF_MPH = (setspeed_t)3;

/*! [ms] Timer duration of SLA manual availability */
times_t CC_SLA_MANUAL_USAGE_TIME = (times_t)7000;

/* ************************************************************************************** */
#endif  /* FCT_CFG_SLA_FEATURE */

#if (KMC_CFG_OVERTAKE_SUPPORT_FEATURE)
/*! [factor] Factor for positive gradient for overtake support feature in pass-by phase */
factor_t CC_OT_POS_ACCEL_FACTOR = (factor_t)120;
#endif

Cc_const gradient_t CC_SMOOTH_JERK_MIN_GRADIENT = (gradient_t)128; /*64*/

Cc_const times_t CC_ENGAGE_OVERRTIDE_TIME = (times_t)160;

/* ************************************************************************************** */
/* Paramater values copied from hp_par.h (earlier acc_par.h) due to separation of Long to
   LOPC and LOHP. The value is to be same in both locations */
#if (FCT_CFG_ACC_HEADWAY_PLANNER)

/*typical thresholds for FSRA (dis)engagement*/
#if (FCT_CFG_FSRACC)
Cc_const setspeed_t KMC_ACC_FSR_OFF_THRES_KMH = 2U;
Cc_const setspeed_t KMC_ACC_FSR_MIN_V_ENGAGE_KMH = 0U; /*Engage ACC in standstill == 0*/
Cc_const setspeed_t KMC_ACC_FSR_MIN_VSET_KMH = 30U;
Cc_const setspeed_t KMC_ACC_FSR_OFF_THRES_MPH = 2U;
Cc_const setspeed_t KMC_ACC_FSR_MIN_V_ENGAGE_MPH = 0U; 
Cc_const setspeed_t KMC_ACC_FSR_MIN_VSET_MPH = 20U;
Cc_const setspeed_t KMC_ACC_FSR_MIN_V_ENGAGE_USA_MPH = 0U; 
Cc_const setspeed_t KMC_ACC_FSR_MIN_VSET_USA_MPH = 20U;
#endif

/*max set speed for ACC in kph/mph*/
Cc_const setspeed_t KMC_ACC_MAX_VSET_KMH = 150U;
Cc_const setspeed_t KMC_ACC_MAX_VSET_MPH = 115U;

/* Deceleration gradient limit for ACC Mode */
/*velocity m/s, jerk m/s^3*/
Cc_const acceleration_t KMC_ACC_MAX_NEG_GRAD[2*Kmc_acc_neg_grad_points] = 
{
  0   , -1000,
  100 , -5000,
  2000, -2500,
  3500, -2500,
  5000, -2500
};

/* Object control acceleration gradient limit */
/* velocity [m/s], jerk [m/s^3] */
acceleration_t KMC_ACC_MAX_POS_GRAD_NORMAL_POS_ACCEL[2*Kmc_acc_pos_grad_pos_accel_points] = // PRQA S 3408
/* date: 2018-04-18, reviewer: Ravi Kiran Gurrala, reason: Not Safety critical */
{
  100, 1500,
  1500, 1500
};

/* velocity [m/s], jerk [m/s^3] */
#if (CFG_FCT_CC_USE_DRIVE_MODE)
acceleration_t KMC_ACC_MAX_POS_GRAD_SPORT_POS_ACCEL[2*Kmc_acc_pos_grad_pos_accel_points] = // PRQA S 3408
/* date: 2018-04-18, reviewer: Ravi Kiran Gurrala, reason: Not Safety critical */
{
  100, 2500,
  1500, 2500
};
/* velocity [m/s], jerk [m/s^3] */
acceleration_t KMC_ACC_MAX_POS_GRAD_ECO_POS_ACCEL[2*Kmc_acc_pos_grad_pos_accel_points] = // PRQA S 3408
/* date: 2018-04-18, reviewer: Ravi Kiran Gurrala, reason: Not Safety critical */
{
  100, 1000,
  1500, 1000
};
#endif
acceleration_t* pKMC_ACC_MaxPosGradPosAccel = KMC_ACC_MAX_POS_GRAD_NORMAL_POS_ACCEL;

/* Object control brake release gradient limit */
/*velocity m/s, jerk m/s^3*/
Cc_const acceleration_t KMC_ACC_MAX_POS_GRAD_NEG_ACCEL[2*Kmc_acc_pos_grad_neg_accel_points] = 
{
  100, 2500, /* all 2500 */
  1500, 2500
};

/* Standstill brake-hold deceleration request [m/s^2] */
Cc_const acceleration_t KMC_ACC_STANDSTILL_ACCEL_REQ = (acceleration_t) -300;

Cc_const velocity_t KMC_ACC_DECEL_ON_STATIONARY_SPEED = (velocity_t)2000; //417

/* Hysteresis to make drive-off state handling more stable */
distance_t KMC_ACC_DRIVE_OFF_DIST_HYST = (distance_t)250; /* 2.5m */

velocity_t KMC_ACC_STANDSTILL_VELOCITY_THRESHOLD = (velocity_t) 25;  /*0.25m/s*/


acceleration_t KMC_ACC_OFFSET_FOR_ROLL = (acceleration_t) -200;

float32 KMC_P_SLOPETC = (float32) 0.95;

float32 KMC_P_SLOPETC1 = (float32) 0.8;

percentage_t  COUNTER_ENTER_SLOPE = (percentage_t)75;

percentage_t COUNTER_EXIT_SLOPE = (percentage_t)40;

float32 THRESHOLD_ENTER_SLOPE = (float32) 2;

float32 THRESHOLD_EXIT_SLOPE = (float32) 1.5;

acceleration_t THRESHOD_ACCEL_SLOPE=(acceleration_t)500;

#endif /* ENDIF (FCT_CFG_ACC_HEADWAY_PLANNER) */


/*******************************************************************************************/
/*                       A P P L I C A T I O N   P A R A M E T E R S                       */
/*******************************************************************************************/

Cc_const times_t CC_T_DRIVE_OFF_CONF = Cc_default_drive_off_confirmation_time;

Cc_const times_t CC_T_DRIVE_OFF_SET = 3000U;

Cc_const times_t CC_T_STANDSTILL_DELAY = 3000U;

Cc_const times_t CC_T_DISPLAY_TAKEOVER_TIME = 400U;

Cc_const times_t CC_BRAKE_PEDAL_MAX_TIME = 500U;// PRQA S 3408
/* date: 2018-04-18, reviewer: Ravi Kiran Gurrala, reason: Not Safety critical */

percentage_t DISPLAY_DISTANCE_THRESHOLD_1 = 60U;

percentage_t DISPLAY_DISTANCE_THRESHOLD_2 = 130U;

percentage_t DISPLAY_DISTANCE_HYST = 20U;

sint16 UPPER_ACCELERATION_VALUE = (sint16)100;

sint16 LOWER_ACCELERATION_VALUE = (sint16)-100;

uint16 UPPER_ACCELERATION_RATE_VALUE = (uint16)16000;

sint16 LOWER_ACCELERATION_RATE_VALUE = (sint16)-16000;

velocity_t T_BRAKEPRE_EGOSPEED_VALUE =  1700;

velocity_t T_BRAKEPRE_TARSPEED_VALUE =  700;

acceleration_t T_BRAKEPRE_EGOACCEL_VALUE = -3500;
/*************************************************************************************************************************
  Functionname:    KMC_v_SelectParamSet                                                                             */ /*!

  @brief           Initialize parameters to be passed to CC with custom specific values

  @description     Initialize parameters to be passed to CC with custom specific values

@startuml
start
  Partition KMC_v_SelectParamSet(){
  : Initialize paramters to be passed to CC with custom specific values;
  If (Sport Mode is activated) Then (True)
  : Initialize the parameter values;
  : CC_MAX_ACCEL_CURVE_SPORT
  : CC_MAX_POS_GRAD_SPORT_POS_ACCEL;
  : CC_MAX_POS_GRAD_SPORT_NEG_ACCEL;
  : CC_MAX_NEG_GRAD_SPORT
  : CC_DECEL_LIMIT_SPORT;
  : CC_ALAT_SPEED_CURVE_SPORT;
  : CC_KMC_ACC_MAX_POS_GRAD_SPORT_POS_ACCEL;
  Endif
  If (ECO mode is activated) Then (True)
  : CC_MAX_ACCEL_CURVE_ECO;
  : CC_MAX_POS_GRAD_ECO_POS_ACCEL;
  : CC_MAX_POS_GRAD_ECO_NEG_ACCEL;
  : CC_MAX_NEG_GRAD_ECO;
  : CC_ALAT_SPEED_CURVE_ECO;
  : CC_DECEL_LIMIT_ECO;
  : CC_KMC_ACC_MAX_POS_GRAD_ECO_POS_ACCEL;
Endif
If (Normal ) Then (True)
: MAX_ACCEL_CURVE_NORMAL;
: MAX_POS_GRAD_NORMAL_POS_ACCEL;
: MAX_POS_GRAD_NORMAL_NEG_ACCEL;
: ALAT_SPEED_CURVE_NORMAL;
: CC_MAX_NEG_GRAD_NORMAL;
: CC_DECEL_LIMIT_NORMAL;
: KMC_ACC_MAX_POS_GRAD_NORMAL_POS_ACCEL;
Endif
}
End
@enduml


  @return          void

  @param[in]       -

  @glob_in         CC_MAX_ACCEL_CURVE_DEFAULT : Array of constants for acceleration gradient    [full range of acceleration_t datatype as defined in Rte_Type.h]
                   CC_DECEL_LIMIT_DEFAULT : Decelaration Limit                                  [full range of acceleration_t datatype as defined in Rte_Type.h]
                   CC_MAX_POS_GRAD_DEFAULT_POS_ACCEL : Array of constants for acceleration      [full range of acceleration_t datatype as defined in Rte_Type.h]
                   CC_MAX_POS_GRAD_DEFAULT_NEG_ACCEL : Array of constants for acceleration      [full range of acceleration_t datatype as defined in Rte_Type.h]
                   CC_MAX_NEG_GRAD_DEFAULT : Array of constants for acceleration gradient       [full range of acceleration_t datatype as defined in Rte_Type.h]
                   CC_ACC_TO_CC_TRANSITON_FACTOR_DEFAULT :                                      [full range of factor_t type as defined in Rte_Type.h]
                   CC_T_SMOOTH_GRADIENT_POS_TIME_DEFAULT :                                      [full range of sint16 datatype as defined in Platform_Types.h]
                   CC_T_SMOOTH_GRADIENT_NEG_TIME_DEFAULT :                                      [full range of sint16 datatype as defined in Platform_Types.h]
                   CC_ALAT_SPEED_CURVE_DEFAULT :                                                [full range of velocity_t datatype as defined in Rte_Type.h]

                   CC_MAX_ACCEL_CURVE_SPORT : Array of constants for acceleration gradient            [full range of acceleration_t datatype as defined in Rte_Type.h]
                   CC_DECEL_LIMIT_SPORT : Array of constants for acceleration gradient                [full range of acceleration_t datatype as defined in Rte_Type.h]
                   CC_MAX_POS_GRAD_SPORT_POS_ACCEL : Array of constants for acceleration gradient     [full range of acceleration_t datatype as defined in Rte_Type.h]
                   CC_MAX_POS_GRAD_SPORT_NEG_ACCEL : Array of constants for acceleration gradient     [full range of acceleration_t datatype as defined in Rte_Type.h]
                   CC_MAX_NEG_GRAD_SPORT : Array of constants for acceleration gradient               [full range of acceleration_t datatype as defined in Rte_Type.h]
                   CC_ACC_TO_CC_TRANSITON_FACTOR_SPORT :                                              [full range of factor_t type as defined in Rte_Type.h]
                   CC_T_SMOOTH_GRADIENT_POS_TIME_SPORT :                                              [full range of sint16 datatype as defined in Platform_Types.h]
                   CC_T_SMOOTH_GRADIENT_NEG_TIME_SPORT :                                              [full range of sint16 datatype as defined in Platform_Types.h]
                   CC_ALAT_SPEED_CURVE_SPORT :                                                        [full range of velocity_t datatype as defined in Rte_Type.h]

                   CC_MAX_ACCEL_CURVE_ECO : Array of constants for acceleration gradient            [full range of acceleration_t datatype as defined in Rte_Type.h]
                   CC_DECEL_LIMIT_ECO : Array of constants for acceleration gradient                [full range of acceleration_t datatype as defined in Rte_Type.h]
                   CC_MAX_POS_GRAD_ECO_POS_ACCEL : Array of constants for acceleration gradient     [full range of acceleration_t datatype as defined in Rte_Type.h]
                   CC_MAX_POS_GRAD_ECO_NEG_ACCEL : Array of constants for acceleration gradient     [full range of acceleration_t datatype as defined in Rte_Type.h]
                   CC_MAX_NEG_GRAD_ECO : Array of constants for acceleration gradient               [full range of acceleration_t datatype as defined in Rte_Type.h]
                   CC_ALAT_SPEED_CURVE_ECO :                                                        [full range of velocity_t datatype as defined in Rte_Type.h]


  @glob_out        pCC_MaxAccelCurve :                    acceleration_t type pointer
                   pCC_DecelLimit :                       acceleration_t type pointer
                   pCC_MaxPosGradPosAccel :               acceleration_t type pointer
                   pCC_MaxPosGradNegAccel :               acceleration_t type pointer
                   pCC_MaxNegGrad :                       acceleration_t type pointer
                   pCC_AccToCcTransitionFactor :          factor_t type pointer
                   pCC_SmoothGradientPosTime :            sint16 type pointer
                   pCC_SmoothGradientNegTime :            sint16 type pointer
                   pCC_ALatSpeedCurve :                   velocity_t type pointer

  @c_switch_part   -
  @c_switch_full   FCT_CFG_LOPC_COMPONENT : Configuration switch for enabling LOPC processing
                   FCT_CFG_CC : Configuration switch enabeling Cruise Control functionality (no object evaluation)

  @pre             -
  @post            -

  @created         -
  @changed         5/31/2016
  @traceability    doors://rbgs854a:40000/?version=2&prodID=0&view=00000002&urn=urn:telelogic::1-503e822e5ec3651e-O-167-0008a220
  @author          -
*************************************************************************************************************************/
void KMC_v_SelectParamSet(void)
{

  pCC_AccToCcTransitionFactor = &CC_ACC_TO_CC_TRANSITON_FACTOR_DEFAULT;

  pCC_SmoothGradientPosTime = CC_T_SMOOTH_GRADIENT_POS_TIME_DEFAULT;
#if (CFG_FCT_CC_USE_SMOOTH_JERKS)  
  pCC_SmoothGradientNegTime = CC_T_SMOOTH_GRADIENT_NEG_TIME_DEFAULT;
#endif

#if (CFG_FCT_CC_USE_DRIVE_MODE)
  switch (LOPC_pLongCtrlResp->KinCtrlDynInput.eDriveMode)
  {
  case SPORT:
    pCC_MaxAccel = CC_MAX_ACCEL_CURVE_SPORT;
    pCC_MaxPosGradPosAccel = CC_MAX_POS_GRAD_SPORT_POS_ACCEL;
    pCC_MaxPosGradNegAccel = CC_MAX_POS_GRAD_SPORT_NEG_ACCEL;
    pCC_MaxNegGrad = CC_MAX_NEG_GRAD_SPORT;
    pCC_ALatSpeedCurve = CC_ALAT_SPEED_CURVE_SPORT;
    pCC_DecelLimit = &CC_DECEL_LIMIT_SPORT;
    pKMC_ACC_MaxPosGradPosAccel = KMC_ACC_MAX_POS_GRAD_SPORT_POS_ACCEL;
    break;
  case ECO:
    pCC_MaxAccel = CC_MAX_ACCEL_CURVE_ECO;
    pCC_MaxPosGradPosAccel = CC_MAX_POS_GRAD_ECO_POS_ACCEL;
    pCC_MaxPosGradNegAccel = CC_MAX_POS_GRAD_ECO_NEG_ACCEL;
    pCC_MaxNegGrad = CC_MAX_NEG_GRAD_ECO;
    pCC_ALatSpeedCurve = CC_ALAT_SPEED_CURVE_ECO;
    pCC_DecelLimit = &CC_DECEL_LIMIT_ECO;
    pKMC_ACC_MaxPosGradPosAccel = KMC_ACC_MAX_POS_GRAD_ECO_POS_ACCEL;
    break;
  case NORMAL:
  default:
    pCC_MaxAccel = CC_MAX_ACCEL_CURVE_NORMAL;
    pCC_MaxPosGradPosAccel = CC_MAX_POS_GRAD_NORMAL_POS_ACCEL;
    pCC_MaxPosGradNegAccel = CC_MAX_POS_GRAD_NORMAL_NEG_ACCEL;
    pCC_MaxNegGrad = CC_MAX_NEG_GRAD_NORMAL;
    pCC_ALatSpeedCurve = CC_ALAT_SPEED_CURVE_NORMAL;
    pCC_DecelLimit = &CC_DECEL_LIMIT_NORMAL;
    pKMC_ACC_MaxPosGradPosAccel = KMC_ACC_MAX_POS_GRAD_NORMAL_POS_ACCEL;
    break;
  }
#else
  pCC_MaxAccel = CC_MAX_ACCEL_CURVE_NORMAL;
  pCC_MaxPosGradPosAccel = CC_MAX_POS_GRAD_NORMAL_POS_ACCEL;
  pCC_MaxPosGradNegAccel = CC_MAX_POS_GRAD_NORMAL_NEG_ACCEL;
  pCC_MaxNegGrad = CC_MAX_NEG_GRAD_NORMAL;
  pCC_ALatSpeedCurve = CC_ALAT_SPEED_CURVE_NORMAL;
  pCC_DecelLimit = &CC_DECEL_LIMIT_NORMAL;
  pKMC_ACC_MaxPosGradPosAccel = KMC_ACC_MAX_POS_GRAD_NORMAL_POS_ACCEL;
#endif /* (CFG_FCT_CC_USE_DRIVE_MODE) */
}

#endif  /* ((FCT_CFG_LOPC_COMPONENT) && (FCT_CFG_CC) && (LOPC_CFG_KMC)) */

/** @} end defgroup */

