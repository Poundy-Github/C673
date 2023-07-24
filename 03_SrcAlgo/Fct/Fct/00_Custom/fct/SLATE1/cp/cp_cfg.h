/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 SLATE_CP (Course Prediction)

MODULNAME:                 cp_cfg.h

DESCRIPTION:               CP internal configuration header

AUTHOR:                    $Author: Raj, Rahul (uid41599) $

CREATION DATE:             26.03.2010

VERSION:                   $Revision: 1.26.9.1 $

LEGACY VERSION:            Revision: 1.18.4.6

**************************************************************************** */
#ifndef CP_CFG_H_INCLUDED
#define CP_CFG_H_INCLUDED

#include "slate_config.h"
#if (FCT_CFG_COURSE_PREDICTION)
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/*!
@defgroup cp_cfg Configuration
@ingroup cp
@brief    Contains all configuration switches related to the cp subcomponent.\n\n
@{
*/

/*****************************************************************************
  Config: CP (Course Prediction)
*****************************************************************************/

/*! @brief  use slip angle information for trajectory calculation */
#define CP_CFG_USE_SLIPANGLE                      0

/*! @brief  Configuration switch to enable an artificial extension of the road fusion
 distance when the compensated distance is close to the cluster distance.
 Currently (05/2015) not suitable for entry. */
#define CP_CFG_ENABLE_EXTEND_ROAD_FUSION_DIST     1

/*! @brief  Configuration switch to enable trace fusion in tunnels. If set to off,
then tunnel probability of over 50% will disable trace fusion */
#define CP_CFG_ENABLE_TRACE_FUSION_IN_TUNNEL      1

/*! @brief  Custom configuration switch for ARS4L1 trajectory fusion: non-zero setting 
causes road fusion at lower velocities, while zero means use fusion as other projects */
#define CP_CFG_USE_LOWER_VEL_ROAD_FUSION          0

/*! @brief  Custom configuration switch for ARS510TA19 trace fusion at lower ego velocities (above 25 kmph)  */
#define CP_CFG_USE_TRACE_FUSION_LOWER_VEL         0

/*! @brief  Custom configuration switch for ARS510TA19 discard traces which have high deviation w.r.t ACC trajectory */
#define CP_CFG_DISCARD_TRACE_WITH_HIGH_DEVIATION  0

/*--- cp_si.c ---*/

/*! Configuration switch selecting if road estimation shall be used for SI course */
#define CP_USE_ROADESTIM (boolean)1

/*! Configuration switch selecting if object traces shall be used for SI course */
#define CP_USE_OBJTRACES (boolean)1

/*! Configuration switch to enable fusion of camera lane for ACC trajectory */
#define CP_USE_CAM_LANE_FUSION  FCT_CFG_DEPENDENT_SWITCH(SLATE_CFG_CAM_LANE_INTERFACE, SWITCH_ON)

/*! Configuration switch to enable fusion of camera lane in city for ACC trajectory */
#define CP_USE_CAM_LANE_FUSION_IN_CITY  FCT_CFG_DEPENDENT_SWITCH(CP_USE_CAM_LANE_FUSION, SWITCH_OFF)

#if (SLATE_CFG_SIMPLE_NAVI_INTERFACE) && (FCT_CFG_INPUT_PREPROCESSSING)
/*! Configuration switch to enable navi path fusion for ACC trajectory 
    -> need to be switched on because they can be disabled by coding parameters 
    FCT_BSW_ALGO_PARAM_PTR->Fct.Acc.NaviFusionPreselBits */
#define CP_USE_NAVI_PATH_FUSION                   (boolean)1
#else
#define CP_USE_NAVI_PATH_FUSION                   (boolean)0
#endif

#define CP_CFG_USE_LOW_PASS_FILTERED_EGO_CURVE           SWITCH_OFF

/* switch to Adapt CamLength to guarantee a certain influence of cam lanes */
#define CP_CFG_CAM_LENGTH_FUSION                         SWITCH_OFF

/* switch to enable Opposite Trace Hypothesis if all the three hypothesis are pointing in same direction */
#define CP_CFG_TRACE_FUSION_OPPO_HYPOTHESIS              SWITCH_OFF

/* Configuration switch to enable Actual Trace length consideration based on Object Long Displacement */
#define CP_CFG_USE_ACTUAL_TRACE_LENGTH                   SWITCH_OFF

/* Configuration switch to limit Unplausible S Curve value to enable Road Fusion for longer duration */
#define CP_CFG_LIMIT_UNPLAUSIBLE_S_CURVE_VALUE           SWITCH_OFF

/* Configuration switch to enable Road Type Check for Road Fusion to form ACC Trajectory (Switch is added due to Wrong Road Type from Navi in VW19 and it will be removed once the Navi Road Type is accurate) */
#define CP_CFG_ENABLE_ROAD_TYPE_CHECK_IN_FUSION          SWITCH_ON

/* Configuration switch to adapt Camera fusion in city with less visibility distance */
#define CP_CFG_ADAPT_CAM_FUSION_IN_CITY                  SWITCH_OFF

/* Configuration switch to use the Target Turn Indicator from Camera to determine the Target Cut-Out */
#define CP_CFG_USE_TARGET_INDICATOR_FOR_TARGET_CUTOUT    FCT_CFG_DEPENDENT_SWITCH(FCT_CFG_CAMERA_OBJECT_DETECTION, SWITCH_OFF)

#endif
#endif
/** @} end defgroup */
