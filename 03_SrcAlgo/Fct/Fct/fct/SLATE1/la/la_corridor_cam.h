/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 SLATE_LA (Lane Association)

PACKAGENAME:               la_corridor_cam.h

DESCRIPTION:               ACC object corridor brackets implementation based on Ego
                           position in cam lane. This is the main file dealing with
                           trace brackets using camera information. All stuff that 
                           is local to corridor_cam will be included here for sharing
                           between la_corridor_cam.c and la_corridor_cam_adapt.c

AUTHOR:                    Harsha Umesh Babu (uidj3583)

CREATION DATE:             05.11.2014

VERSION:                   $Revision: 1.6 $

LEGACY VERSION:            Revision: 2.0

**************************************************************************** */

#ifndef SI_CORRIDOR_CAM_H_INCLUDED
#define SI_CORRIDOR_CAM_H_INCLUDED


/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "la.h"
#ifdef __cplusplus
extern "C" {
#endif

#if (FCT_CFG_ACC_LANE_ASSOCIATION)
#if ((FCT_CFG_INPUT_PREPROCESSSING) && (SLATE_CFG_CAM_LANE_INTERFACE))
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
@addtogroup la_corridor_cam
@{ */
/*****************************************************************************
  MODULEGLOBAL CONSTANTS
*****************************************************************************/


/*****************************************************************************
  MODULGLOBAL VARIABLES
*****************************************************************************/

/*****************************************************************************
  MODULE LOCAL SYMBOLIC CONSTANTS
*****************************************************************************/

/*---------------------------------------------------------------------------
| Constants, Variables: Adaption of trace brackets based on camera information about ego-position in lane |
---------------------------------------------------------------------------*/
#if ( LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM || \
      LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM || \
      LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM )

/*! Constants */
#define LA_MIN_CAM_COURSE_DIST               (7.0f)
#define LA_LC_PROB_LEVEL_LOW_SPEED           (72u) /*lane change prob upper threshold*/
#define LA_LC_PROB_LEVEL_HIGH_SPEED          (67u)/*lane change prob lower threshold*/
#define LA_LC_PROB_LEVEL_HYSTERESIS          (10u)
#define LA_CP_PAR_LC_MAX_MARKER_DIST         (0.5f)
#define LA_LEVEL_LOW_SPEED                   (20.f)
#define LA_LANE_CHANGE_HISTORY_BUFFER        (5u)
#define LA_LC_PROB_LEVEL_LOW                 (25)
#define LA_LEVEL_CURVE_DIFF_CAM_EGO          (0.004f)
#define LA_LC_LEFT_DIFF_DIST_MARKER_HIST_LEVEL  (0.01f)
#define LA_LC_RIGHT_DIFF_DIST_MARKER_HIST_LEVEL (-0.01f)
#define LA_TB_RATIO_MIN_CAM_LANE_WIDTH       (1.5f)
#define LA_TB_RATIO_MAX_CAM_LANE_WIDTH       (4.5f)
#define LA_MIN_DIST_MARKER_INLANE            (0.9f)
#define LA_MIN_FACTOR_DIST_MARKER_INLANE     (0.3f)
#define LA_PAR_INVALIDE_LANE_MARKER_DIST     (-99.9f)
#define LA_FAC_LANEWIDTH_OBJECT_SELECTION    (0.8f)
#define LA_TB_LANE_ASSO_CAM_COURSE_LEVEL     (0.0002f)
#define LA_TB_LANE_ASSO_CAM_COURSE_EGO_COURSE_DIFF_LEVEL  (0.002f)
#define LA_TB_ASSO_LAT_DIST_COMP_PARA_MULTI_LANE          (0.7f)
#define LA_TB_ASSO_LAT_DIST_PARA_MULTI_LANE               (0.8f)
#define LA_TB_ASSO_LAT_DIST_COMP_PARA_STRAIGHT_LANE       (0.45f)
#define LA_TB_ASSO_LAT_DIST_PARA_STRAIGHT_LANE            (0.6f)
#define LA_TB_ASSO_LC_LAT_VREL_PARA                   (- 1.1f)
#define LA_TB_ASSO_LC_LONG_VREL_PARA                  (-7.f)
#define LA_TB_ASSO_LC_LAT_DIST_MIN_PARA               (-2.f)
#define LA_TB_ASSO_LC_COURSE_LAT_DIST_MIN_PARA        (-1.f)
#define LA_TB_ASSO_LC_LAT_DIST_MAX_ACC_LANE_PARA      (0.f)
#define LA_TB_ASSO_LC_LAT_DIST_MIN_ACC_LANE_PARA      (-2.f)
#define LA_TB_ASSO_LC_LONG_DIST_MAX_PARALL            (70.f)
#define LA_TB_ASSO_POST_LC_TIME_RELEVANT_PARA_MIN     (1.f)
#define LA_TB_ASSO_LC_TIME_RELEVANT_PARA_MAX          (5.f)
#define LA_TB_ASSO_PRE_LC_MIN_TIME_RELEVANT_PARA      (0.4f)
#define LA_TB_ASSO_PRE_LC_MIN_MIN_TIME_RELEVANT_PARA  (0.2f)
#define LA_TB_ASSO_POST_LC_LAT_DIST_CAM_LANE_PARA     (-1.5f)
#define LA_TB_ASSO_PRE_LC_LAT_DIST_CAM_LANE_PARA      (0.f)
#define LA_TB_ASSO_PRE_LC_LAT_DIST_PARA               (0.f)
#define LA_TB_ADAPT_FACTOR_LONG_DIST                  (70.f)
#define LA_TB_LEFT_LC_PROB_LEVEL_RESET_HIST           (30u) /*hysteresis to  in case of lane change*/
#define LA_TB_RIGHT_LC_PROB_LEVEL_RESET_HIST          (30u)
#define LA_TB_ABORT_BLINKER_FEATURE_LC_PROB_LEVEL     (10)
#define LA_TB_INCREASE_FACTOR_BLINKER_FEATURE         (0.65f)
#define LA_TB_DECREASE_FACTOR_BLINKER_FEATURE         (1.f - LA_TB_INCREASE_FACTOR_BLINKER_FEATURE)
#endif  /*!< ( LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM || 
               LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM || 
               LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM) */

/*****************************************************************************
  MODULE LOCAL MACROS
*****************************************************************************/


/*****************************************************************************
  MODULE LOCAL TYPES
*****************************************************************************/


/*****************************************************************************
  MODULE LOCAL CONSTANTS
*****************************************************************************/


/*****************************************************************************
  MODULE LOCAL TYPEDEFS
*****************************************************************************/

typedef enum LAInLaneDecision
{
  UNKNOWN_LANE,
  EGO_LANE,
  LEFT_LANE,
  RIGHT_LANE
} LA_t_InLaneDecision;   /*!< Enum for lane assignment (object relative to ego-lane) */

/*****************************************************************************
  MODULE LOCAL VARIABLES
*****************************************************************************/

/*****************************************************************************
  FUNCTION PROTOTYPES
*****************************************************************************/

/* ************************************************************************* */
/*   Copyright ADC-GmbH, Lindau                                              */
/* ************************************************************************* */
///@}
#endif /* ((FCT_CFG_INPUT_PREPROCESSSING) && (SLATE_CFG_CAM_LANE_INTERFACE)) */
#endif /* FCT_CFG_ACC_LANE_ASSOCIATION */

#ifdef __cplusplus
};
#endif

#endif /*_SI_CORRIDOR_CAM_H_INCLUDED*/
