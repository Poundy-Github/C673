/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 ACC/LOPC/CC (Adaptive Cruise Control - Longitudinal Planner & Coordinator - Longitudinal Coordinator)

PACKAGENAME:               loc_par.h

DESCRIPTION:               Internal header file for function CC in LOPC in FCT_SEN Task

AUTHOR:                    Mistry Niraj (uidq5738)

CREATION DATE:             24.02.2017

VERSION:                   $Revision: 1.3 $

---*/ /*---
CHANGES:                    $Log: cc_par.h  $
CHANGES:                    Revision 1.3 2018/10/11 10:57:08CEST uidj5069 
CHANGES:                    CC parameter updated on Application Workshop in 07/2018
CHANGES:                    Revision 1.2 2017/10/26 17:07:42CEST Borgs, Wolfgang (uidj5069) 
CHANGES:                    Parameter <CC_CRUISE_TIME_STAND_STILL_MAX> <3000> added
CHANGES:                    Revision 1.1 2017/10/05 08:24:04CEST Borgs, Wolfgang (uidj5069) 
CHANGES:                    Initial revision
CHANGES:                    Member added to project /ADAS/SW/Components/LOCC_LongitudinalCruiseControl/04_Engineering/00_Projects/ARS510/LOCC/locc/cc/project.pj
CHANGES:                    Derived from Version 1.24.1.2 in /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/FCT_Function/04_Engineering/01_Source_Code/algo/fct/lopc/hc/acc/project.pj

**************************************************************************** */

/* conditional include */
#ifndef CC_PAR_INCLUDED
#define CC_PAR_INCLUDED


#if ((FCT_CFG_LOCC_COMPONENT) && (LOCC_CFG_CC))

#define CC_SET_SPEED_MIN                              (30u)   /* Minimum SetSpeed:  30 [km/h] */
#define CC_SET_SPEED_MAX                             (180u)   /* Maximum SetSpeed: 180 [km/h] */

#define CC_ENG_SPEED_MIN                               (0u)   /* Minimum Engage Speed:   0 [km/h] */
#define CC_ENG_SPEED_MAX                             (210u)   /* Maximum Engage Speed: 210 [km/h] */

#define CC_INC_SPEED_1                                 (1u)   /* Set Speed Increment Level 1 */
#define CC_DEC_SPEED_1                                 (1u)   /* Set Speed Decrement Level 1 */

#define CC_INC_SPEED_2                                (10u)   /* Set Speed Increment Level 2 */
#define CC_DEC_SPEED_2                                (10u)   /* Set Speed Decrement Level 2 */

#define CC_CRUISE_TIME_STAND_STILL_MAX              (3000u)   /* Max Time for StandStill without Driver Confirmation [ms] (3s) */

/* Time constant for ego velocity filter */
#define CC_CRUISE_EGO_SPEED_FILT_CONST       (1.0f / 0.02f)   /* Filter time constant for low pass filter of ego speed */
extern float f_cc_cruise_ego_speed_filt_const;


/* Normal control limitations for cruise control */
#define CC_CRUISE_ACCEL_MAX                          (1.0f)   /* Maximum Cruise Acceleration:  1.5 [m/s^2] */
extern float f_cc_cruise_accel_max;

#define CC_CRUISE_DECEL_MAX                         (-0.9f)   /* Maximum Cruise Deceleration: -2.0 [m/s^2] */
extern float f_cc_cruise_decel_max;

#define CC_CRUISE_ACCEL_GRAD_MAX                     (1.0f)   /* Maximum Cruise Acceleration Gradient:  2.5 [m/s^3] */
extern float f_cc_cruise_accel_grad_max;

#define CC_CRUISE_DECEL_GRAD_MAX                    (-1.0f)   /* Maximum Cruise Deceleration Gradient: -2.5 [m/s^3] */
extern float f_cc_cruise_decel_grad_max;


/* Special control limitations for cruise control */
#define CC_CRUISE_DECEL_MAX_DURING_OVERRIDE         (-0.4f)   /* Maximum Cruise Deceleration during Override: -0.4 [m/s^2] */
extern float f_cc_cruise_decel_max_during_override;

#define CC_CRUISE_DECEL_MAX_AFTER_OVERRIDE          (-0.4f)   /* Maximum Cruise Deceleration after Override: -0.4 [m/s^2] */
extern float f_cc_cruise_decel_max_after_override;

#define CC_CRUISE_DECEL_MAX_AFTER_ENGAGEMENT        (-0.4f)   /* Maximum Cruise Deceleration after Engagement: -0.4 [m/s^2] */
extern float f_cc_cruise_decel_max_after_engagement;


/* Normal control limitations for curve control */
#define CC_CURVE_ACCEL_MAX                          (1.0f)   /* Maximum Acceleration for Curve Speed Control:  2.0 [m/s^2] */
extern float f_cc_curve_accel_max;

#define CC_CURVE_DECEL_MAX                         (-2.0f)   /* Maximum Deceleration for Curve Speed Control: -2.0 [m/s^2] */
extern float f_cc_curve_decel_max;

#define CC_CURVE_ACCEL_GRAD_MAX                     (1.0f)   /* Maximum Acceleration Gradient for Curve Speed Control:  2.5 [m/s^3] */
extern float f_cc_curve_accel_grad_max;

#define CC_CURVE_DECEL_GRAD_MAX                    (-2.5f)   /* Maximum Deceleration Gradient for Curve Speed Control: -2.5 [m/s^3] */
extern float f_cc_curve_decel_grad_max;


/* Table of maximum lateral acceleration depending on curve radius */
#define CC_CURVE_ACCEL_LAT_BKP                      {10.0f, 50.0f, 100.0f, 250.0f, 1500.0f, 3000.0f}
extern float af_cc_curve_accel_lat_bkp[];           /* Lateral Acceleration Curve Radius Breakpoints [m] */
#define CC_CURVE_ACCEL_LAT_VAL                      { 3.0f,  2.8f,   2.6f,   2.4f,    2.2f,    2.0f}
extern float af_cc_curve_accel_lat_val[];           /* Lateral Acceleration Values [m/s^2] */
#define CC_CURVE_ACCEL_LAT_CNT                      (6u)


#endif  /* (FCT_CFG_LOCC_COMPONENT && LOCC_CFG_CC)  */

#endif
