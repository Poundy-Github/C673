/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC/LOHP/HP (Adaptive Cruise Control - Longitudinal Headway Planner - Headway Planner)

PACKAGENAME:               hp_custom.h

DESCRIPTION:               Custom header file for HP in LOHP

AUTHOR:                    Mistry Niraj (uidq5738)

CREATION DATE:             25.02.2018

VERSION:                   $Revision: 1.2 $

**************************************************************************** */

#ifndef _HP_CUSTOM_H_INCLUDED
#define _HP_CUSTOM_H_INCLUDED

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/*!
@defgroup         hp_custom_h   Hp_custom_h
@ingroup          hp_custom
@brief            Custom header file for HP
@{
*/

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "hp.h"

#ifdef __cplusplus
extern "C" {
#endif

#if ((FCT_CFG_LOHP_COMPONENT) && (FCT_CFG_ACC_HEADWAY_PLANNER))

/*****************************************************************************
  SYMOBLIC CONSTANTS 
*****************************************************************************/


/*****************************************************************************
  MACROS 
*****************************************************************************/
#if (CFG_FCT_ACC_PARAMS_DEBUG)
#ifndef FCT_MEAS_ID_LOHP_ACC_PARAMS
#define FCT_MEAS_ID_LOHP_ACC_PARAMS (0x20020A85u)
#endif
#endif

/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/
#if (CFG_FCT_ACC_PARAMS_DEBUG)
/*! @brief Collection of ACC parameter values for debugging*/
typedef struct acc_params { 
  sint16 ACC_FSR_MAX_ACCEL_DEFAULT[2*Acc_fsr_max_acceleration_points];         /*!< max acceleration/deceleration request that is allowed (speed depended)*/
  sint16 ACC_FSR_MAX_DECEL[2*Acc_fsr_max_deceleration_points];
  sint16 ACC_HEADWAY_MIN_DIST_DEFAULT[2*Acc_headway_min_dist_points]; /*headway setting for minimum headway setting (0%) and maximum headway setting (100%)*/
  sint16 ACC_HEADWAY_MAX_DIST_DEFAULT[2*Acc_headway_max_dist_points];
  sint16 ACC_MAX_POS_GRAD_NEG_ACCEL[2*Acc_pos_grad_neg_accel_points];
  sint16 ACC_MAX_POS_GRAD_POS_ACCEL[2*Acc_pos_grad_pos_accel_points];
  sint16 ACC_MAX_NEG_GRAD[2*Acc_neg_grad_points];
  sint16 ACC_RECOMMENDED_VELOCITY_CURVE[2*Acc_recommended_velocity_curve_points];
  sint16 ACC_MIN_TO_MAX_INTRUSION_FACTOR[2*Acc_min_to_max_intrusion_factor_points];
  sint16 ACC_MAX_INTRUSION_DISTANCE[2*Acc_max_intrusion_distance_points];
} acc_params_t;
#endif

/*****************************************************************************
  CONSTANTS 
*****************************************************************************/


/*****************************************************************************
  VARIABLES
*****************************************************************************/


/*****************************************************************************
  FUNCTION PROTOTYPES 
*****************************************************************************/


#endif  /* (FCT_CFG_LOHP_COMPONENT) && (FCT_CFG_ACC_HEADWAY_PLANNER) */

#ifdef __cplusplus
};
#endif

/** @} end defgroup */

/* End of conditional inclusion */
#endif  /*!< _HP_CUSTOM_H_INCLUDED */
