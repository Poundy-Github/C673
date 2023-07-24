/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 ACC/LOHP/PRED (Adaptive Cruise Control - Longitudinal Headway Planner - Predictive ACC)

PACKAGENAME:               pred_par.h

DESCRIPTION:               Internal header file for PRED in LOHP

AUTHOR:                    Schnellbach Hans-Juergen (uidg5946)

CREATION DATE:             08.01.2019

VERSION:                   $Revision: 1.4 $

**************************************************************************** */

/* conditional include */
#ifndef PRED_PAR_INCLUDED
#define PRED_PAR_INCLUDED

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/*!
@defgroup         pred_par_h   Pred_par_h
@ingroup          pred_custom
@brief            Parameter header file for PRED
@{
*/

#if ( LOHP_CFG_PRED )

/* Smallest distance to curve used for calculations */
#define AACC_MIN_DIST  ( 0.01f )
/* Maximal acceleration request for AACC feature */
#define AACC_MAX_ACCEL_REQ      ( 4.0f )  /* AACC_MAX_ACCEL_REQ must be smaller than +32.0f */
/* Quality threshold for validity calculation of Navi Input data */
#define AACC_MIN_NAVI_QUALITY   ( 0u )
/* Maximal amount of available Navi Input segments */
#define AACC_MAX_NR_NAV_SEG     ( 8u )
/* Maximal amount of possible lanes associated to a road segment */
#define AACC_MAX_NR_NAV_LANES   ( 10u )
/* Index of the first used Navi Input segment */
#define AACC_FIRST_SEG          ( 0u )
/* Minimal amount of valid Navi Input segments to allow feature to activate */
#define AACC_MIN_AV_NAVI_SEG    ( 1u )
/* Cycle time [ms] in which PRED subcomponent is executed */
#define AACC_CYCLE_TIME         ( 60u )
/* Define a time limit for keeping last valid Navi Input data as usable */
#define AACC_TIMER_MAX_INVALID  Time_max
/* Slope conversion factor */
#define AACC_SLOPE_CONV_FAC     ( 0.01f )
/* Slope input offset */
#define AACC_SLOPE_OFFS         ( 100.0f )
/* Min slope input value */
#define AACC_MIN_SLOPE          ( 0x2133u )
/* Max slope input value */
#define AACC_MAX_SLOPE          ( 0x2CEDu )
/* Min speed limit input value */
#define AACC_MIN_SPEED_LIM      (( velocity_t )5 )
/* Max speed limit input value */
#define AACC_MAX_SPEED_LIM      (( velocity_t )50 )


/*****************************************************************************
  CURVE CTRL SPECIFIC CALIBRATIONS
*****************************************************************************/
#if ( PRED_ACT_CURVE_CTRL )

/* Smallest allowed curvature used for calculations */
#define AACC_CURVATURE_MIN      ( 0.00002f )

/*! [m] Curve radius table used to calculate setspeed for predictive curve control based on navi information */
#define Aacc_alat_curve_radius_points ((uint16)6)
#define Aacc_alat_curve_radius AACC_ALAT_CURVE_RADIUS
extern float32 AACC_ALAT_CURVE_RADIUS[Aacc_alat_curve_radius_points];

/*! [m/s] Desired ego velocity driving through curve based on navi information */
#define Aacc_alat_curve_setspeed_points Aacc_alat_curve_radius_points
#define Aacc_alat_curve_setspeed AACC_ALAT_CURVE_SETSPEED
extern float32 AACC_ALAT_CURVE_SETSPEED[Aacc_alat_curve_setspeed_points];

/*! [m/s] Conversion table angle to curvature */
#define Aacc_alat_angle_to_radius_points Aacc_alat_curve_radius_points
#define Aacc_alat_angle_to_radius AACC_ALAT_ANGLE_TO_RADIUS
extern float32 AACC_ALAT_ANGLE_TO_RADIUS[Aacc_alat_angle_to_radius_points];

#endif /* PRED_ACT_CURVE_CTRL */
/*****************************************************************************
*****************************************************************************/

/*! [m/s²] Desired deceleration in case AACC curve control is active */
#define Aacc_desired_decel AACC_DESIRED_DECEL
extern float32 AACC_DESIRED_DECEL;     /* Value must be negative */

/*! [m/s²] Maximum allowed deceleration intervention of AACC curve controller */
#define Aacc_min_accel_req AACC_MIN_ACCEL_REQ
extern float32 AACC_MIN_ACCEL_REQ;     /* must be greater than -32.0f */

/*! [s] Maximum allowed deceleration intervention of AACC curve controller */
#define Aacc_min_dist_act_ctrl AACC_MIN_DIST_ACT_CTRL
extern float32 AACC_MIN_DIST_ACT_CTRL;

/*! Switch to activate the arbitration of the AACC curve control deceleration request */
#define Lc_act_pred_ctrl LC_ACT_PRED_CTRL
extern boolean LC_ACT_PRED_CTRL;

#endif  /* ( LOHP_CFG_PRED ) */

/** @} end defgroup */

#endif  /* PRED_PAR_INCLUDED */
