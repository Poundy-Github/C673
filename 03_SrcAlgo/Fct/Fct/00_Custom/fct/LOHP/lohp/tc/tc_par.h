/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 ACC/LOHP/TC (Adaptive Cruise Control - Longitudinal Headway Planner - Target Control)

PACKAGENAME:               tc_par.h

DESCRIPTION:               Internal header file for function TC in LOHP

AUTHOR:                    Mistry Niraj (uidq5738)

CREATION DATE:             24.02.2017

VERSION:                   $Revision: 1.10 $

---*/ /*---
CHANGES:                    $Log: tc_par.h  $
CHANGES:                    Revision 1.10 2018/11/07 14:36:48CET uidj5069 
CHANGES:                    Parameter <f_tc_accel_long_pref_fac> added (Default = 1.0)
CHANGES:                    Revision 1.9 2018/10/11 11:02:19CEST Borgs, Wolfgang (uidj5069) 
CHANGES:                    ACC parameter updated on Application Workshop in 07/2018
CHANGES:                    Revision 1.8 2018/07/12 17:14:01CEST Borgs, Wolfgang (uidj5069) 
CHANGES:                    Calibration Concept revised
CHANGES:                    Revision 1.7 2018/04/16 15:28:42CEST Borgs, Wolfgang (uidj5069) 
CHANGES:                    Control Parameters updated to improve stability
CHANGES:                    Revision 1.6 2018/03/15 11:49:33CET Borgs, Wolfgang (uidj5069) 
CHANGES:                    Parameters for Multi Object Control added
CHANGES:                    Revision 1.5 2017/11/13 14:25:47CET Borgs, Wolfgang (uidj5069) 
CHANGES:                    Update Parameter <TC_ACCEL_LONG_PREF_POS_1>
CHANGES:                    Revision 1.4 2017/10/26 12:41:35CEST Borgs, Wolfgang (uidj5069) 
CHANGES:                    Target Control Parameters optimized for CarMaker
CHANGES:                    Revision 1.3 2017/10/17 14:01:19CEST Borgs, Wolfgang (uidj5069) 
CHANGES:                    Initial Target Control Parameter Set
CHANGES:                    Revision 1.2 2017/10/10 13:55:19CEST Mistry, Niraj (uidq5738) 
CHANGES:                    Switch added
CHANGES:                    Revision 1.1 2017/10/05 09:48:10CEST Borgs, Wolfgang (uidj5069) 
CHANGES:                    Initial revision
CHANGES:                    Member added to project /ADAS/SW/Components/LOHP_LongitudinalHeadwayPlanner/04_Engineering/00_Projects/ARS510/LOHP/lohp/tc/project.pj
CHANGES:                    Derived from Version 1.24.1.2 in /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/FCT_Function/04_Engineering/01_Source_Code/algo/fct/lopc/hc/acc/project.pj

**************************************************************************** */

/* conditional include */
#ifndef TC_PAR_INCLUDED
#define TC_PAR_INCLUDED


#if ((FCT_CFG_LOHP_COMPONENT) && (LOHP_CFG_TC))


/* Normal control limitations for target control */
#define TC_TARGET_ACCEL_MAX                          (2.0f)   /* Maximum Target Control Acceleration:  2.0 [m/s^2] */
extern float32 f_tc_target_accel_max;

#define TC_TARGET_DECEL_MAX                         (-3.5f)   /* Maximum Target Control Deceleration: -3.5 [m/s^2] */
extern float32 f_tc_target_decel_max;

#define TC_TARGET_ACCEL_GRAD_MAX                     (2.5f)   /* Maximum Target Control Acceleration Gradient:  2.5 [m/s^3] */
extern float32 f_tc_target_accel_grad_max;

#define TC_TARGET_DECEL_GRAD_MAX                    (-2.5f)   /* Maximum Target Control Deceleration Gradient: -2.5 [m/s^3] */
extern float32 f_tc_target_decel_grad_max;


/* Special control limitations for target control */
#define TC_TARGET_DECEL_MAX_DURING_OVERRIDE         (-0.4f)   /* Maximum Target Control Deceleration during Override: -0.4 [m/s^2] */
extern float32 f_tc_target_decel_max_during_override;

#define TC_TARGET_DECEL_MAX_AFTER_OVERRIDE          (-0.4f)   /* Maximum Target Control Deceleration during Override: -0.4 [m/s^2] */
extern float32 f_tc_target_decel_max_after_override;

#define TC_TARGET_DECEL_MAX_AFTER_ENGAGEMENT        (-0.4f)   /* Maximum Target Control Deceleration during Override: -0.4 [m/s^2] */
extern float32 f_tc_target_decel_max_after_engagement;


/* CutInOut Probability dependent Tables */
#define TC_CUTINOUT_PROB_CNT                        (6u)

/* CutInOut Probability Breakpoints [0..1] */
#define TC_CUTINOUT_PROB_BKP                        {0.0f, 0.2f, 0.4f, 0.6f, 0.8f, 1.0f}
extern float32 af_tc_cutinout_prob_bkp[];

/* Max Deceleration for CutIn Targets [m/s^2] */
#define TC_CUTIN_TAR_DECEL_MAX                      {4.0f, 4.0f, 4.0f, 4.0f, 0.0f, -1.0f}
extern float32 af_tc_cutin_tar_decel_max[];

/* Max Deceleration on OOI-1 for CutOut OOI-0 Target [m/s^2] */
#define TC_CUTOUT_TAR_DECEL_MAX                     {-1.0f, -1.0f, -1.5f, -2.0f, -2.5f, -3.0f}
extern float32 af_tc_cutout_tar_decel_max[];

/* Blending Factor of Reference to Intrusion Distance for CutOut Targets [0..1] */
#define TC_CUTOUT_TAR_DIST_BLEND_FAC                {0.0f, 0.0f, 0.0f, 0.3f, 0.6f, 1.0f}
extern float32 af_tc_cutout_tar_dist_blend_fac[];
/* CutInOut Probability dependent Tables - end */


/* Longitudinal Target Speed dependent Tables */
#define TC_TARGET_SPEED_LONG_CNT                    (4u)

/* Longitudinal Target Speed Breakpoints [km/h]      0.0   50.4  100.8  151.2 */
/* Longitudinal Target Speed Breakpoints [m/s] */
#define TC_TARGET_SPEED_LONG_BKP                    {0.0f, 14.0f, 28.0f, 42.0f}
extern float32 af_tc_target_speed_long_bkp[];

/* Longitudinal Target Alert Distance [m] (2.0m + v*0.3s) */
#define TC_TAR_DIST_LONG_ALERT                      {2.0f,  6.2f, 10.4f, 14.6f}
extern float32 af_tc_tar_dist_long_alert[];

/* Longitudinal Target Reference Distance for Headway Min [m] (3.0m + v*1.0s) */
#define TC_TAR_DIST_LONG_REF_MIN                    {3.0f, 17.0f, 31.0f, 45.0f}
extern float32 af_tc_tar_dist_long_ref_min[];

/* Longitudinal Target Reference Distance for Headway Max [m] (4.0m + v*2.0s) */
#define TC_TAR_DIST_LONG_REF_MAX                    {4.0f, 32.0f, 60.0f, 88.0f}
extern float32 af_tc_tar_dist_long_ref_max[];

/* Longitudinal Relative Intrusion Distance for Headway Min [m] (v*0.5s) */
#define TC_INT_DIST_LONG_REL_MIN                    {0.0f,  7.0f, 14.0f, 21.0f}
extern float32 af_tc_int_dist_long_rel_min[];

/* Longitudinal Relative Intrusion Distance for Headway Max [m] (v*1.0s) */
#define TC_INT_DIST_LONG_REL_MAX                    {0.0f, 14.0f, 28.0f, 42.0f}
extern float32 af_tc_int_dist_long_rel_max[];

/* Longitudinal Target Speed dependent Tables - End */


/* Longitudinal Target Speed and Distance Error dependent Tables */
#define TC_TAR_DIST_LONG_ERR_CNT                    (6u)

/* Longitudinal Target Distance Error Axes for all Velocities of TC_TARGET_SPEED_LONG_BKP [m] */
/* (-40.0m - v*2.0s) (-30.0m - v*1.5s) (-20.0m - v*1.0s) (-10.0m - v*0.5s) (0.0m)!!! (3.0m + v*0.2s) */
#define TC_TAR_DIST_LONG_ERR \
{ \
  { -40.0f, -30.0f, -20.0f, -10.0f, 0.0f, 10.0f}, \
  { -68.0f, -51.0f, -34.0f, -17.0f, 0.0f, 17.0f}, \
  { -96.0f, -72.0f, -48.0f, -24.0f, 0.0f, 24.0f}, \
  {-124.0f, -93.0f, -62.0f, -31.0f, 0.0f, 31.0f}  \
};
extern float32 af_tc_tar_dist_long_err[][TC_TAR_DIST_LONG_ERR_CNT];

/* Longitudinal Preferred Acceleration Curves for all Velocities of TC_TARGET_SPEED_LONG_BKP [m/s^2] */
/* (neg) (neg) (neg) (neg) (0.0)!!! (pos) */
#define TC_ACCEL_LONG_PREF \
{ \
  {-1.0f, -1.0f, -1.0f, -1.0f, 0.0f, 1.0f}, \
  {-1.0f, -1.0f, -1.0f, -1.0f, 0.0f, 1.0f}, \
  {-1.0f, -1.0f, -1.0f, -1.0f, 0.0f, 1.0f}, \
  {-1.0f, -1.0f, -1.0f, -1.0f, 0.0f, 1.0f}, \
};
extern float32 af_tc_accel_long_pref[][TC_TAR_DIST_LONG_ERR_CNT];

/* Longitudinal Preferred Acceleration Factor: 1.0 [-] */
#define TC_ACCEL_LONG_PREF_FAC                (1.0f)
extern float32 f_tc_accel_long_pref_fac;

/* Longitudinal Target Speed and Distance Error dependent Tables - End */


#endif /* (FCT_CFG_LOHP_COMPONENT) && (LOHP_CFG_TC) */

#endif
