/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 ACC/LOHP/PRED (Adaptive Cruise Control - Longitudinal Headway Planner - Predictive ACC functions)

PACKAGENAME:               pred_par.c

DESCRIPTION:               Parameter file for functions concerning predictive curve control

AUTHOR:                    Schnellbach Hans-Juergen (uidg5946)

CREATION DATE:             08.01.2019

VERSION:                   $Revision: 1.4 $

LEGACY VERSION:            Revision: 1.1

**************************************************************************** */

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/*!
@defgroup         pred_par   Pred_par
@ingroup          pred_custom
@brief            Parameter file for PRED
@{
*/

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "pred.h"
#include "pred_par.h"
#include "pred_cfg.h"

#if ( LOHP_CFG_PRED )

/*****************************************************************************
  CURVE CTRL SPECIFIC CALIBRATIONS
*****************************************************************************/
#if ( PRED_ACT_CURVE_CTRL )

/*! [m] Curve radius table used to calculate setspeed for predictive curve control based on navi information */
float32 AACC_ALAT_CURVE_RADIUS[Aacc_alat_curve_radius_points] =       { 15.0f, 80.0f, 210.0f, 460.0f, 2480.0f, 4020.0f }; /* Curve radius [m] */
/*! [m/s] Desired ego velocity driving through curve based on navi information */
float32 AACC_ALAT_CURVE_SETSPEED[Aacc_alat_curve_setspeed_points] =   {  7.5f, 14.0f,  21.0f,  28.0f,   55.0f,   60.0f }; /* Curve setspeed [m/s] */
/*! [m/s] Conversion table angle to radius */
float32 AACC_ALAT_ANGLE_TO_RADIUS[Aacc_alat_angle_to_radius_points] = { 30.0f, 20.0f,  13.0f,  12.0f,   11.0f,   10.0f }; /* Curve setspeed [m/s] */

#endif /* PRED_ACT_CURVE_CTRL */
/*****************************************************************************
*****************************************************************************/

/*! [m/s²] Desired deceleration in case AACC curve control is active */
float32 AACC_DESIRED_DECEL = -0.75f;     /* Value must be negative */

/*! [m/s²] Maximum allowed deceleration intervention of AACC curve controller */
float32 AACC_MIN_ACCEL_REQ = -1.0f;     /* must be greater than -32.0f */

/*! [s] Maximum allowed deceleration intervention of AACC curve controller */
float32 AACC_MIN_DIST_ACT_CTRL = 5.0f;

/*! Switch to activate the arbitration of the AACC curve control deceleration request */
boolean LC_ACT_PRED_CTRL = TRUE;


#endif  /* ( LOHP_CFG_PRED ) */

/** @} end defgroup */
