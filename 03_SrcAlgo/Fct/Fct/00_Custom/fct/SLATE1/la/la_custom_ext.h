/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 SLATE_LA (Lane Association)

PACKAGENAME:               la_custom_ext.h

DESCRIPTION:               External Header File for Custom specific information in ACC Lane Association (LA) module

AUTHOR:                    Boll Marie-Theres (uidu1091)

CREATION DATE:             27.07.2016

VERSION:                   $Revision: 1.7 $

LEGACY VERSION:            Revision: 1.12

**************************************************************************** */

#ifndef LA_CUSTOM_EXT_H_INCLUDED
#define LA_CUSTOM_EXT_H_INCLUDED


/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "la_cfg.h"
#include "slate_ext.h"
#include "la_ver.h"
/* nothing should be included in this file */
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
@addtogroup la_customfunctions
@{ */

/*****************************************************************************
  SYMOBLIC CONSTANTS (COMPONENT EXTERNAL SCOPE)
*****************************************************************************/
/*--- GENERAL ---*/
/*! Tunnel probability threshold, above which tunnel specific behavior @min:0 @max: 1 */
#define LA_TUNNEL_PROB_THRES   0.50f


/*--- la_acc_function_presel.c ---*/
/*! Configuration switch to enable cluster variance usage for in-lane decision      */
/*! Reduces drop-ins on difficult highways                                         */
/* For objects with high cluster variance:                                         */
/* 1. increased object occupancy pick-up threshold                                  */
/* 2. increased object occupancy drop threshold                                     */
/* 3. increased object in-lane-time                                                 */
/* 4. no predicted lane association                                                */
#define LA_USE_CLUSTER_VARIANCE_IN_LANEASSOCIATION  \
  FCT_CFG_DEPENDENT_SWITCH(FCT_CFG_ROAD_INPUT,  SWITCH_ON)


#define LA_HIGHWAYLANEWIDTHSEEK_MIN           (3.0f) /* similar parameters in la_par.h */
/*! This factor scales down the variances of vrel to course after start of new distance to course filtering in SA */
#define LA_VARIANCE_SCALE_FACTOR    (0.1272727272727F)

/*-- la_corridor.c ---*/
/*! Configuration switch allowing limitation of seek lane width based on road
lane width estimation. Useful when road lane width estimation incorporates fusion
of camera information (for example) */
#define LA_CFG_LIMIT_SEEK_LANEWIDTH_BASED_ON_ROAD   0

#define LA_CITYLANEWIDTHSEEK            (2.7F)

#define LA_STANDARDLANEWIDTHSEEK        (STRASSENBREITE)

#define LA_ROADWORKSLANEWIDTHSEEK       (2.25f)/*(STRASSENBREITE - 1.5F)*/

/*-- la_corridor_crit.c ---*/
/*! Configuration switch for enabling NBS Diagnose Test
@todo: Clarify if this is needed! */
#define LA_CFG_NBS_DIAGNOSE_TEST        0

/*--- la_corridor_radarroad.c ---*/


/*! Configuration switch for enabling optimized country road hold performance
for preventing drop-outs on country roads */
#define LA_CFG_OPTIMIZED_OBJECT_HOLD_FEATURES   1



/*--- la_corridor_trackwidth.c ---*/




/*--- la_corridor_cam.c ---*/
/* Configuration switch, which moves the trace brackets based on the ego position in lane; 
    only active in combination with the camera lane interface are moved to fct_config.h as a temporary measure*/


/*--- la_corridor_cam_adapt.c ---*/



/*--- la_corridor_scene.c ---*/









/*--- la_corridor_navi.c ---*/



/*--- la_acc_function_presel.c ---*/

/*--- la_laneassociation.c ---*/

/*! Configuration switch to delay the predicted lane association */
#define LA_CFG_DELAY_PRED_LANE_ASSOC                  1 

/*! Configuration switch to enable old wide near range track. This was a special
work-around checked in to provide better cut-in recognition in near range. New
simulation on the original measurements no longer shows any benefits */
#define LA_CFG_USE_WIDE_NEAR_TRACEBRACKETS          0

/*--- la_par.h ---*/

/*! @brief maximum acceleration of object to trajectory*/
#define LA_ACC_MAXACCELTRAJDIST         (5.0f)

/*--- la_predictions.c ---*/

/*--- la_custom_functions.c ------*/

/* End of conditional inclusion */
/** @} end defgroup */
#endif  /*!< _LA_CUSTOM_EXT_H_INCLUDED */
