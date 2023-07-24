/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 ACC/LOHP/TC (Adaptive Cruise Control - Longitudinal Headway Planner - Target Control)

PACKAGENAME:               tc_par.c

DESCRIPTION:               Parameter file for function TC in LOHP

AUTHOR:                    Mistry Niraj (uidq5738)

CREATION DATE:             24.02.2017

VERSION:                   $Revision: 1.6 $

---*/ /*---
CHANGES:                    $Log: tc_par.c  $
CHANGES:                    Revision 1.6 2018/11/07 14:36:07CET uidj5069 
CHANGES:                    Parameter <f_tc_accel_long_pref_fac> added
CHANGES:                    Revision 1.5 2018/07/12 17:13:36CEST Borgs, Wolfgang (uidj5069) 
CHANGES:                    Calibration Concept revised
CHANGES:                    Revision 1.4 2018/03/15 11:49:21CET Borgs, Wolfgang (uidj5069) 
CHANGES:                    Parameters for Multi Object Control added
CHANGES:                    Revision 1.3 2017/10/17 14:01:09CEST Borgs, Wolfgang (uidj5069) 
CHANGES:                    Initial Target Control Parameter Set
CHANGES:                    Revision 1.2 2017/10/10 13:54:57CEST Mistry, Niraj (uidq5738) 
CHANGES:                    Switch added
CHANGES:                    Revision 1.1 2017/10/05 09:48:10CEST Borgs, Wolfgang (uidj5069) 
CHANGES:                    Initial revision
CHANGES:                    Member added to project /ADAS/SW/Components/LOHP_LongitudinalHeadwayPlanner/04_Engineering/00_Projects/ARS510/LOHP/lohp/tc/project.pj
CHANGES:                    Derived from Version 1.32.2.2 in /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/FCT_Function/04_Engineering/01_Source_Code/algo/fct/lopc/hc/acc/project.pj

**************************************************************************** */

#include "tc.h"
#include "tc_par.h"
#include "tc_cfg.h"

#if ((FCT_CFG_LOHP_COMPONENT) && (LOHP_CFG_TC))


/* Normal control limitations for target control */
float32 f_tc_target_accel_max = TC_TARGET_ACCEL_MAX;
float32 f_tc_target_decel_max = TC_TARGET_DECEL_MAX;
float32 f_tc_target_accel_grad_max = TC_TARGET_ACCEL_GRAD_MAX;
float32 f_tc_target_decel_grad_max = TC_TARGET_DECEL_GRAD_MAX;


/* Special control limitations for target control */
float32 f_tc_target_decel_max_during_override = TC_TARGET_DECEL_MAX_DURING_OVERRIDE;
float32 f_tc_target_decel_max_after_override = TC_TARGET_DECEL_MAX_AFTER_OVERRIDE;
float32 f_tc_target_decel_max_after_engagement = TC_TARGET_DECEL_MAX_AFTER_ENGAGEMENT;


/* CutInOut Probability dependent Tables */

/* CutInOut Probability Breakpoints [0..1] */
float32 af_tc_cutinout_prob_bkp[TC_CUTINOUT_PROB_CNT] = TC_CUTINOUT_PROB_BKP;

/* Max Deceleration for CutIn Targets [m/s^2] */
float32 af_tc_cutin_tar_decel_max[TC_CUTINOUT_PROB_CNT] = TC_CUTIN_TAR_DECEL_MAX;

/* Max Deceleration on OOI-1 for CutOut OOI-0 Target [m/s^2] */
float32 af_tc_cutout_tar_decel_max[TC_CUTINOUT_PROB_CNT] = TC_CUTOUT_TAR_DECEL_MAX;

/* Blending Factor of Reference to Intrusion Distance for CutOut Targets [0..1] */
float32 af_tc_cutout_tar_dist_blend_fac[TC_CUTINOUT_PROB_CNT] = TC_CUTOUT_TAR_DIST_BLEND_FAC;

/* CutInOut Probability dependent Tables - End */


/* Longitudinal Target Speed dependent Tables */

/* Longitudinal Target Speed Breakpoints [m/s] */
float32 af_tc_target_speed_long_bkp[TC_TARGET_SPEED_LONG_CNT] = TC_TARGET_SPEED_LONG_BKP;

/* Longitudinal Target Alert Distance [m] */
float32 af_tc_tar_dist_long_alert[TC_TARGET_SPEED_LONG_CNT] = TC_TAR_DIST_LONG_ALERT;

/* Longitudinal Target Reference Distance for Headway Min [m] */
float32 af_tc_tar_dist_long_ref_min[TC_TARGET_SPEED_LONG_CNT] = TC_TAR_DIST_LONG_REF_MIN;

/* Longitudinal Target Reference Distance for Headway Max [m] */
float32 af_tc_tar_dist_long_ref_max[TC_TARGET_SPEED_LONG_CNT] = TC_TAR_DIST_LONG_REF_MAX;

/* Longitudinal Relative Intrusion Distance for Headway Min [m] */
float32 af_tc_int_dist_long_rel_min[TC_TARGET_SPEED_LONG_CNT] = TC_INT_DIST_LONG_REL_MIN;

/* Longitudinal Relative Intrusion Distance for Headway Max [m] */
float32 af_tc_int_dist_long_rel_max[TC_TARGET_SPEED_LONG_CNT] = TC_INT_DIST_LONG_REL_MAX;

/* Longitudinal Target Speed depending Tables - End */


/* Longitudinal Target Speed and Distance Error dependent Tables */

/* Longitudinal Target Distance Error Axes for all Velocities of TC_TARGET_SPEED_LONG_BKP [m] */
float32 af_tc_tar_dist_long_err[TC_TARGET_SPEED_LONG_CNT][TC_TAR_DIST_LONG_ERR_CNT] = TC_TAR_DIST_LONG_ERR;

/* Longitudinal Preferred Acceleration Curves for all Velocities of TC_TARGET_SPEED_LONG_BKP [m/s^2] */
float32 af_tc_accel_long_pref[TC_TARGET_SPEED_LONG_CNT][TC_TAR_DIST_LONG_ERR_CNT] = TC_ACCEL_LONG_PREF;

/* Longitudinal Preferred Acceleration Factor [-] */
float32 f_tc_accel_long_pref_fac = TC_ACCEL_LONG_PREF_FAC;

/* Longitudinal Target Speed and Distance Error dependent Tables - End */

#endif /* (FCT_CFG_LOHP_COMPONENT) && (LOHP_CFG_TC) */
