/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 ACC/LOCC/CC (Adaptive Cruise Control - Longitudinal Cruise Control - Cruise Control)

PACKAGENAME:               cc_par.c

DESCRIPTION:               Parameter file for function CC in LOPC in FCT_SEN Task

AUTHOR:                    Mistry Niraj (uidq5738)

CREATION DATE:             24.02.2017

VERSION:                   $Revision: 1.1 $

---*/ /*---
CHANGES:                    $Log: cc_par.c  $
CHANGES:                    Revision 1.1 2017/10/05 08:24:04CEST uidj5069 
CHANGES:                    Initial revision
CHANGES:                    Member added to project /ADAS/SW/Components/LOCC_LongitudinalCruiseControl/04_Engineering/00_Projects/ARS510/LOCC/locc/cc/project.pj
CHANGES:                    Derived from Version 1.32.2.2 in /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/FCT_Function/04_Engineering/01_Source_Code/algo/fct/lopc/hc/acc/project.pj

**************************************************************************** */

#include "cc.h"
#include "cc_par.h"
#include "cc_cfg.h"

#if ((FCT_CFG_LOCC_COMPONENT) && (LOCC_CFG_CC))

/* Time constant for ego velocity filter */
float f_cc_cruise_ego_speed_filt_const = CC_CRUISE_EGO_SPEED_FILT_CONST;


/* Normal control limitations for cruise control */
float f_cc_cruise_accel_max = CC_CRUISE_ACCEL_MAX;
float f_cc_cruise_decel_max = CC_CRUISE_DECEL_MAX;
float f_cc_cruise_accel_grad_max = CC_CRUISE_ACCEL_GRAD_MAX;
float f_cc_cruise_decel_grad_max = CC_CRUISE_DECEL_GRAD_MAX;


/* Special control limitations for cruise control */
float f_cc_cruise_decel_max_during_override = CC_CRUISE_DECEL_MAX_DURING_OVERRIDE;
float f_cc_cruise_decel_max_after_override = CC_CRUISE_DECEL_MAX_AFTER_OVERRIDE;
float f_cc_cruise_decel_max_after_engagement = CC_CRUISE_DECEL_MAX_AFTER_ENGAGEMENT;


/* Normal control limitations for curve control */
float f_cc_curve_accel_max = CC_CURVE_ACCEL_MAX;
float f_cc_curve_decel_max = CC_CURVE_DECEL_MAX;
float f_cc_curve_accel_grad_max = CC_CURVE_ACCEL_GRAD_MAX;
float f_cc_curve_decel_grad_max = CC_CURVE_DECEL_GRAD_MAX;


/* Map for maximum lateral acceleration depending on curve radius */
float af_cc_curve_accel_lat_bkp[CC_CURVE_ACCEL_LAT_CNT] = CC_CURVE_ACCEL_LAT_BKP;
float af_cc_curve_accel_lat_val[CC_CURVE_ACCEL_LAT_CNT] = CC_CURVE_ACCEL_LAT_VAL;

#endif  /* (FCT_CFG_LOCC_COMPONENT && LOCC_CFG_CC) */
