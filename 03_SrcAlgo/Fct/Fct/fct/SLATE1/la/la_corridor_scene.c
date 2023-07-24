/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 SLATE_LA (Lane Association)

PACKAGENAME:               la_corridor_scene.c

DESCRIPTION:               ACC object corridor brackets' adaptation implementation based on scene

AUTHOR:                    Norman Apel
                           Gergely Ungvary

CREATION DATE:             09.11.2009

VERSION:                   $Revision: 1.45.1.1 $

LEGACY VERSION:            Revision: 2.1

**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "la.h"//PRQA S 0380
/* date: 2019-07-28, reviewer:Prabhu Sundaramurthy, reason: Arises due to inclusion of multiple header files in this header file which has multiple macros*/

#if (FCT_CFG_ACC_LANE_ASSOCIATION)
#include "la_corridor_crit.h"
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
@defgroup la_corridor_scene LA Corridor scene
@ingroup la_corridor
@brief          Provides ACC object corridor brackets' adaptation implementation based on scene. \n\n

@{

*/

/*****************************************************************************
  MODULGLOBALE KONSTANTEN
*****************************************************************************/

/*****************************************************************************
  MODULGLOBALE VARIABLEN
*****************************************************************************/

/*****************************************************************************
  MODULLOKALE SYMBOLISCHE KONSTANTEN
*****************************************************************************/
#if (LA_CFG_O2O_EGO_LANE_ASSOC)
/*------------------------------------------------------------------------------------------------*/
/* Parameters used in multiple O2O functions*/
#define LA_O2O_ROADVDYDELTA_FAR_HIGH        (7.5f)           /*! [m], Threshold for orthogonal distance delta of road and VDY curves in far range. Indicates curve entry or lane change. */
#define LA_O2O_ROADVDYDELTA_NEAR_HIGH       (1.5f)           /*! [m], Threshold for orthogonal distance delta of road and VDY curves in near range. Indicates curve entry or lane change. */
#define LA_O2O_HIGHSPEED                    (140.f/C_KMH_MS) /*! [m/s] Definition of high-speed in O2O module */
#define LA_O2O_BORDER_DIST_CLOSE            (3.3f)           /*! [m], Absolute distance to road border below which ego is on outer lane */
#define LA_O2O_BORDER_DIST_FAR              (8.f)            /*! [m], Absolute distance to road border above which ego is likely on opposite outer lane */
#define LA_O2O_BORDER_STATUS_MIN            (100u)           /*! percentage, Minimum for road border stat left/right to compute object distance to road border */
#define LA_O2O_CURVY_ROAD_CURVATURE         (1.f/1500.f)     /*! [1/m], Curve threshold in O2O module */
#define LA_O2O_STRONG_CURVE_CURVATURE       (1.f/750.f)      /*! [1/m], Strong curve threshold in O2O module */

/*------------------------------------------------------------------------------------------------*/
/* LA_b_O2OCheckEgoLaneByObjTrace */
#define LA_O2O_TRACE_SAMPLES_MIN          ((sint8)11) /*! minimum sample number for analysis if trace has not reached ego */
#define LA_O2O_TRACE_DISTX_FAR            (120.f)     /*! [m], distx above which less stringent thresholds are used */
#define LA_O2O_TRACE_DIST_MEAN_PICKUP     (0.5f)      /*! [m], pick-up threshold of mean trace sample orthogonal distance to VDY curve */
#define LA_O2O_TRACE_DIST_MEAN_DROP_NEAR  (0.7f)      /*! [m], near drop threshold of mean trace sample orthogonal distance to VDY curve */
#define LA_O2O_TRACE_DIST_MEAN_DROP_FAR   (1.6f)      /*! [m], far drop threshold of mean trace sample orthogonal distance to VDY curve */
#define LA_O2O_TRACE_STD_DEV_PICKUP       (0.6f)      /*! [m], pick-up threshold of standard deviation of trace sample orthogonal distance to VDY curve */
#define LA_O2O_TRACE_STD_DEV_DROP_NEAR    (0.7f)      /*! [m], near drop threshold of standard deviation of trace sample orthogonal distance to VDY curve */
#define LA_O2O_TRACE_STD_DEV_DROP_FAR     (1.0f)      /*! [m], far drop threshold of standard deviation of trace sample orthogonal distance to VDY curve */

/* Defines area and velocity delta in which possible overtaken object can be located in relation
to the overtaking object */
#define LA_O2O_TRACE_FREE_AREA_DELTAX_LOWER (5.f)    /*! [m], Maximum distance delta in negative X direction */
#define LA_O2O_TRACE_FREE_AREA_DELTAX_UPPER (50.f)   /*! [m], Maximum distance delta in positive X direction */
#define LA_O2O_TRACE_FREE_AREA_DELTAY_LOWER (-10.f)  /*! [m], Maximum distance delta in negative Y direction */
#define LA_O2O_TRACE_FREE_AREA_DELTAY_UPPER (10.f)   /*! [m], Maximum distance delta in positive Y direction */
#define LA_O2O_TRACE_FREE_AREA_DELTAV_LOWER (-999.f) /*! [m/s], Velocity delta lower threshold */
#define LA_O2O_TRACE_FREE_AREA_DELTAV_UPPER (-3.f)   /*! [m/s], Velocity delta upper threshold */

static const LA_t_FindObjInAreaArgs LAEgoLaneByObjTraceArgs = // PRQA S 3218
/* date: 2015-09-18, reviewer: Grant Davtjan, reason: static local for saving data across function calls */
{
  LA_O2O_TRACE_FREE_AREA_DELTAX_LOWER,
  LA_O2O_TRACE_FREE_AREA_DELTAX_UPPER,
  LA_O2O_TRACE_FREE_AREA_DELTAY_LOWER,
  LA_O2O_TRACE_FREE_AREA_DELTAY_UPPER,
  LA_O2O_TRACE_FREE_AREA_DELTAV_LOWER,
  LA_O2O_TRACE_FREE_AREA_DELTAV_UPPER
};

/*------------------------------------------------------------------------------------------------*/
/* LA_b_O2OCheckRelObjDistToTrajHint */
#define LA_O2O_RELOBJ_DIST2TRAJ_PICKUP_FAR   (5.5f) /*! [m], far pick-up threshold of orthogonal distance to trajectory */
#define LA_O2O_RELOBJ_DIST2TRAJ_PICKUP_MID   (4.5f) /*! [m], mid pick-up threshold of orthogonal distance to trajectory */
#define LA_O2O_RELOBJ_DIST2TRAJ_PICKUP_CLOSE (2.8f) /*! [m], near pick-up threshold of orthogonal distance to trajectory */
#define LA_O2O_RELOBJ_DIST2TRAJ_THRES_HYST   (1.f)  /*! [m], hysteresis: increase threshold of orthogonal distance to trajectory when object already on ego lane by O2O analysis */

#define LA_O2O_RELOBJ_DIST2TRAJ_DISTX_FAR   (180.f) /*! [m], dist-x above which least stringent thresholds are used */
#define LA_O2O_RELOBJ_DIST2TRAJ_DISTX_MID   (115.f) /*! [m], dist-x above which less stringent thresholds are used */

/*------------------------------------------------------------------------------------------------*/
/* LA_b_O2OCheckRelObjTraceHint */
#define LA_O2O_RELOBJ_OCCL_DROP_DISTX_MAX              (120.f)     /*! [m], dist-x below which occlusion drop criteria is applied */

#define LA_O2O_RELOBJ_TRACE_SAMPLES_MIN                ((sint8)4)  /*! minimum number of trace samples for consideration of object trace hint */
#define LA_O2O_RELOBJ_TRACE_Y_INTERSEC_ABS_MAX         (3.f)       /*! [m], maximum absolute distance of trace y-intersection for fulfillment of criteria */
#define LA_O2O_RELOBJ_TRACE_Y_INTERSEC_STD_DEV_MAX     (1.f)       /*! [m], y-intersection criteria for drop only when trace parallel i.e standard deviation of trace sample orthogonal distance to VDY curve below threshold */

#define LA_O2O_RELOBJ_TRACE_STD_DEV_PICKUP             (1.f)       /*! [m], near pick-up threshold of standard deviation of trace sample orthogonal distance to VDY curve */
#define LA_O2O_RELOBJ_TRACE_STD_DEV_PICKUP_FAR         (1.3f)      /*! [m], far pick-up threshold of standard deviation of trace sample orthogonal distance to VDY curve */
#define LA_O2O_RELOBJ_TRACE_STD_DEV_PICKUP_TUNNEL      (1.8f)      /*! [m], tunnel pick-up threshold of standard deviation of trace sample orthogonal distance to VDY curve */
#define LA_O2O_RELOBJ_TRACE_STD_DEV_DROP               (1.2f)      /*! [m], near drop threshold of standard deviation of trace sample orthogonal distance to VDY curve */
#define LA_O2O_RELOBJ_TRACE_STD_DEV_DROP_FAR           (2.4f)      /*! [m], far drop threshold of standard deviation of trace sample orthogonal distance to VDY curve */
#define LA_O2O_RELOBJ_TRACE_STD_DEV_DISTX_FAR          (130.f)     /*! [m], dist-x above which less stringent thresholds are used for standard deviation */

#define LA_O2O_RELOBJ_TRACE_DIST_MEAN_CLOSE_STRAIGHT   (1.8f)      /*! [m], near threshold of mean trace sample orthogonal distance to VDY curve on straight roads */
#define LA_O2O_RELOBJ_TRACE_DIST_MEAN_MID_STRAIGHT     (2.1f)      /*! [m], mid threshold of mean trace sample orthogonal distance to VDY curve on straight roads */
#define LA_O2O_RELOBJ_TRACE_DIST_MEAN_FAR_STRAIGHT     (2.7f)      /*! [m], far threshold of mean trace sample orthogonal distance to VDY curve on straight roads */
#define LA_O2O_RELOBJ_TRACE_DIST_MEAN_CLOSE_CURVY      (1.7f)      /*! [m], near threshold of mean trace sample orthogonal distance to VDY curve on curvy roads */
#define LA_O2O_RELOBJ_TRACE_DIST_MEAN_FAR_CURVY        (2.5f)      /*! [m], far threshold of mean trace sample orthogonal distance to VDY curve on curvy roads */

#define LA_O2O_RELOBJ_TRACE_DIST_MEAN_DISTX_MID        (120.f)     /*! [m], dist-x above which less stringent thresholds are used for mean distance */
#define LA_O2O_RELOBJ_TRACE_DIST_MEAN_DISTX_FAR        (150.f)     /*! [m], dist-x above which the least stringent thresholds are used for mean distance */

#define LA_O2O_RELOBJ_TRACE_ABS_MEAN_AND_STD_SUM_THRES (3.f)       /*! parameter used for trace standard deviation threshold which is a function of the mean distance */

static const GDBLFunction_t LAO2ORelObjTraceStdDevMeanRamp = // PRQA S 3218
  /* date: 2015-09-18, reviewer: Grant Davtjan, reason: static local for saving data across function calls */
{
  (0.f),
  (LA_O2O_RELOBJ_TRACE_ABS_MEAN_AND_STD_SUM_THRES),
  ( (LA_O2O_RELOBJ_TRACE_ABS_MEAN_AND_STD_SUM_THRES - 0.f) / ( 0.f - LA_O2O_RELOBJ_TRACE_ABS_MEAN_AND_STD_SUM_THRES ) ),
  (0.f) -  ( ( ( LA_O2O_RELOBJ_TRACE_ABS_MEAN_AND_STD_SUM_THRES - 0.f ) / ( 0.f - LA_O2O_RELOBJ_TRACE_ABS_MEAN_AND_STD_SUM_THRES ) ) * LA_O2O_RELOBJ_TRACE_ABS_MEAN_AND_STD_SUM_THRES )
};

/* more stringent thresholds on mid lane */
#define LA_O2O_RELOBJ_TRACE_STD_DEV_MIDLANE_CRIT        (0.4f)      /*! [m], more stringent thresholds of standard deviation of trace sample orthogonal distance to VDY curve only if trace is not very parallel */
#define LA_O2O_RELOBJ_TRACE_DIST_MEAN_MIDLANE_CRIT      (0.5f)      /*! [m], more stringent threshold of mean trace sample orthogonal distance to VDY curve */
#define LA_O2O_RELOBJ_TRACE_SAMPLES_MIDLANE_CRIT        ((sint8)13) /*! more stringent threshold of minimum number of trace samples */

/*------------------------------------------------------------------------------------------------*/
/* LA_b_O2OCheckRelObjBorderDistHint */
#define LA_O2O_RELOBJ_BORDER_GATE_HALF_LONG    (20.f) /*! [m], absolute value of upper and lower longitudinal search gate */
#define LA_O2O_RELOBJ_BORDER_GATE_LAT          (10.f) /*! [m], absolute value of upper and lower lateral search gate */
#define LA_O2O_RELOBJ_BORDER_GUARDRAIL_OBJ_MIN (6u)   /*! minimum number of stationary (guardrail) objects needed for object distance to road border estimation */
#define LA_O2O_RELOBJ_BORDER_DIST_PICKUP       (6.f)  /*! [m], pick-up threshold of object distance to road border when ego on outer lane */
#define LA_O2O_RELOBJ_BORDER_DIST_DROP         (7.f)  /*! [m], drop threshold of object distance to road border when ego on outer lane */

#define LA_O2O_RELOBJ_BORDER_ROAD_TRACK_MIN    (5u)   /*! Minimal tracking status for the Road Estimation to be considered */
#define LA_O2O_RELOBJ_BORDER_ROAD_CONF_MIN     (60u)  /*! Minimal confidence for the Road Estimation to be considered */
#define LA_O2O_RELOBJ_BORDER_ROAD_RANGE_OFFSET (10.f) /*! [m], offset of left/right road range to compensate filtering and avoid too high ranges */

/*------------------------------------------------------------------------------------------------*/
/* LA_b_O2OCheckRelObjCutOutHint */
#define LA_O2O_RELOBJ_CUTOUT_DISTX_MAX               (180.f)         /*! [m], maximum distance of the "relevant" object for consideration of its cut-out */
#define LA_O2O_RELOBJ_CUTOUT_TRACE_STD_DEV_MIN       (0.5f)          /*! [m], minimum of standard deviation of trace sample orthogonal distance to VDY curve of the "relevant" object for its cut-out */
#define LA_O2O_RELOBJ_CUTOUT_TRACE_DIST_MEAN_MIN     (0.5f)          /*! [m], minimum of mean trace sample orthogonal distance to VDY curve of the "relevant" object for its cut-out */

#define LA_O2O_RELOBJ_CUTOUT_DISTX_DIFF_MIN          (-35.f)         /*! [m], minimum longitudinal distance difference between "relevant" and neighboring object for a cut-out. */
#define LA_O2O_RELOBJ_CUTOUT_VREL_DIFF_MIN           (10.f/C_KMH_MS) /*! [m/s], minimum v-rel difference between "relevant" and neighboring object for a cut-out. Object cutting-out has to be the faster one */

#define LA_O2O_RELOBJ_CUTOUT_ABS_TRACE_DIST_DIFF_MIN (-0.5f)         /*! [m], minimum of the difference of absolute values of the mean trace sample orthogonal distance to VDY curve of both objects for a cut-out of the "relevant" object */
#define LA_O2O_RELOBJ_CUTOUT_OBJ_TRACE_STD_DEV_MAX   (1.5f)          /*! [m], maximum of standard deviation of trace sample orthogonal distance to VDY curve of the neighboring object for a cut-out of the "relevant" object */

/*------------------------------------------------------------------------------------------------*/
/* LA_t_O2OFindNeighboringO2OObject */
#define LA_O2O_DOUBLEOBJ_DISTX_DIFF_ABS_MAX (15.F)                /*! [m], maximum absolute dist-x difference of two objects of the same vehicle */
#define LA_O2O_DOUBLEOBJ_VREL_DIFF_ABS_MAX  (0.1f)                /*! [m/s], maximum absolute v-rel difference of two objects of the same vehicle */
#define LA_O2O_DOUBLEOBJ_DISTY_DIFF_ABS_MAX (3.f)                 /*! [m], maximum absolute dist-y difference of two objects of the same vehicle */

#define LA_O2O_MIRROR_DISTX_DIFF_ABS_MAX    (5.0F)                /*! [m], maximum absolute dist-x difference of a mirror and a real object */
#define LA_O2O_MIRROR_VREL_DIFF_ABS_MAX     (0.5F)                /*! [m/s], maximum absolute v-rel difference of a mirror and a real object */

#define LA_O2O_VREL_TRACE_SAMPLES_MAX       ((sint8)16)           /*! maximum number of "relevant" object trace samples up until to which v-rel criteria is considered */
#define LA_O2O_VREL_ABS_VREL_DIFF_MAX       (23.f/C_KMH_MS)       /*! [m/s], maximum absolute v-rel difference above which v-rel criteria is not fulfilled */

#define LA_O2O_POSITION_DISTX_FAR                 (115.f)         /*! [m], dist-x above which less stringent thresholds are used for longitudinal and lateral search gates */
#define LA_O2O_POSITION_DISTX_DIFF_THRES_FAR      (35.f)          /*! [m], absolute value of upper and lower longitudinal search gate in far range */
#define LA_O2O_POSITION_DISTY_DIFF_PICKUP_FAR     (7.f)           /*! [m], pick-up threshold of upper and lower lateral search gate in far range */
#define LA_O2O_POSITION_DISTX_DIFF_THRES_NEAR     (30.f)          /*! [m], absolute value of upper and lower longitudinal search gate in near range */
#define LA_O2O_POSITION_DISTY_DIFF_PICKUP_NEAR    (6.f)           /*! [m], pick-up threshold of upper and lower lateral search gate in near range */
#define LA_O2O_POSITION_DISTY_DIFF_THRES_HYST     (1.f)           /*! [m], hysteresis: increase threshold of lateral search gate when "relevant" object already on ego lane by O2O analysis */
#define LA_O2O_POSITION_SAME_VEL_THRES            (10.f/C_KMH_MS) /*! [m/s], v-rel between "relevant" and neighboring object below which they are likely to follow each other */
#define LA_O2O_POSITION_DISTX_DIFF_SAME_VEL       (15.f)          /*! [m], decreased longitudinal search gate when v-rel indicates that "relevant" and neighboring object are likely to follow each other */
#define LA_O2O_POSITION_DISTX_DIFF_MAX_TRUCK_ADD  (15.f)          /*! [m], addend for upper longitudinal search gate when neighboring object is a truck */

/*------------------------------------------------------------------------------------------------*/
/* LA_b_O2OCheckO2OTraceRelationHint */
#define LA_O2O_TRACEREL_ABS_TRACE_DIST_DIFF_PICKUP         (0.f)   /*! [m], pick-up threshold of the difference of absolute values of the mean trace sample orthogonal distance to VDY curve of both objects */
#define LA_O2O_TRACEREL_ABS_TRACE_DIST_DIFF_DROP_DISTX_FAR (160.f) /*! [m], dist-x upper threshold: for high dist-x less stringent drop thresholds are used for the difference of absolute values of the mean trace sample orthogonal distance to VDY curve of both objects */
#define LA_O2O_TRACEREL_ABS_TRACE_DIST_DIFF_DROP_DISTX_NEAR (80.f)  /*! [m], dist-x lower threshold: for low dist-x more stringent drop thresholds are used for the difference of absolute values of the mean trace sample orthogonal distance to VDY curve of both objects */
#define LA_O2O_TRACEREL_ABS_TRACE_DIST_DIFF_DROP_NEAR      (0.5f)  /*! [m], near drop threshold of the difference of absolute values of the mean trace sample orthogonal distance to VDY curve of both objects */
#define LA_O2O_TRACEREL_ABS_TRACE_DIST_DIFF_DROP_FAR       (1.3f)  /*! [m], far drop threshold of the difference of absolute values of the mean trace sample orthogonal distance to VDY curve of both objects */
static const GDBLFunction_t LAO2OTraceRelationAbsTraceDistDiffRamp = {// PRQA S 3218
  /* date: 2015-09-18, reviewer: Grant Davtjan, reason: static local for saving data across function calls */
    LA_O2O_TRACEREL_ABS_TRACE_DIST_DIFF_DROP_NEAR,
    LA_O2O_TRACEREL_ABS_TRACE_DIST_DIFF_DROP_FAR,
    ( ( LA_O2O_TRACEREL_ABS_TRACE_DIST_DIFF_DROP_FAR - LA_O2O_TRACEREL_ABS_TRACE_DIST_DIFF_DROP_NEAR ) / ( LA_O2O_TRACEREL_ABS_TRACE_DIST_DIFF_DROP_DISTX_FAR - LA_O2O_TRACEREL_ABS_TRACE_DIST_DIFF_DROP_DISTX_NEAR ) ),
    LA_O2O_TRACEREL_ABS_TRACE_DIST_DIFF_DROP_NEAR - ( (( LA_O2O_TRACEREL_ABS_TRACE_DIST_DIFF_DROP_FAR - LA_O2O_TRACEREL_ABS_TRACE_DIST_DIFF_DROP_NEAR ) / ( LA_O2O_TRACEREL_ABS_TRACE_DIST_DIFF_DROP_DISTX_FAR - LA_O2O_TRACEREL_ABS_TRACE_DIST_DIFF_DROP_DISTX_NEAR ) ) * SI_O2O_TRACEREL_ABS_TRACE_DIST_DIFF_DROP_DISTX_NEAR)
};
#define LA_O2O_TRACEREL_OBJ_TRACE_STD_DISTX_FAR            (140.f) /*! [m], dist-x above which less stringent thresholds are used for neighboring object's standard deviation of trace sample orthogonal distance to VDY curve */
#define LA_O2O_TRACEREL_OBJ_TRACE_STD_PARALLEL             (1.f)   /*! [m], near threshold of neighboring object's standard deviation of trace sample orthogonal distance to VDY curve for consideration of its trace in the analysis */
#define LA_O2O_TRACEREL_OBJ_TRACE_STD_PARALLEL_FAR         (1.6f)  /*! [m], far threshold of neighboring object's standard deviation of trace sample orthogonal distance to VDY curve for consideration of its trace in the analysis */
#define LA_O2O_TRACEREL_OBJ_TRACE_STD_DEV_MAX_STRONG_CURVE (1.5f)  /*! [m], maximum of neighboring object's standard deviation of trace sample orthogonal distance to VDY curve in strong curves. Above threshold neighboring object is likely a split object */
#define LA_O2O_TRACEREL_OBJ_STD_DEV_MAX                    (3.f)   /*! [m], maximum of neighboring object's standard deviation of trace sample orthogonal distance to VDY curve. Above threshold neighboring object is likely a split object */

/*------------------------------------------------------------------------------------------------*/
/* LA_b_O2OCheckO2OTraceRelationFurtherAnalysis */
#define LA_O2O_TRACEREL_TRACE_DIST_DIFF_ABS_PICKUP_MIDLANE   (5.5f)   /*! [m], pick-up threshold for the absolute difference of the mean trace sample orthogonal distance to VDY curve of both objects when ego on mid-lane */
#define LA_O2O_TRACEREL_TRACE_DIST_DIFF_ABS_PICKUP_OUTERLANE (6.5f)   /*! [m], pick-up threshold for the absolute difference of the mean trace sample orthogonal distance to VDY curve of both objects when ego on outer lane */
#define LA_O2O_TRACEREL_TRACE_DIST_DIFF_ABS_THRES_HYST       (1.f)    /*! [m], hysteresis: increase threshold of absolute difference of the mean trace sample orthogonal distance to VDY curve of both objects when the "relevant" object is already on ego lane by O2O analysis */

#define LA_O2O_TRACEREL_ABS_TRACE_DIST_SUM_DISTX_FAR         (180.0f) /*! [m], dist-x above which less stringent thresholds are used for the sum of absolute values of the mean trace sample orthogonal distance to VDY curve of both objects */
#define LA_O2O_TRACEREL_ABS_TRACE_DIST_SUM_PICKUP_FAR        (7.0f)   /*! [m], far pick-up threshold for the sum of absolute values of the mean trace sample orthogonal distance to VDY curve of both objects */
#define LA_O2O_TRACEREL_ABS_TRACE_DIST_SUM_PICKUP            (6.0f)   /*! [m], near pick-up threshold for the sum of absolute values of the mean trace sample orthogonal distance to VDY curve of both objects */
#define LA_O2O_TRACEREL_ABS_TRACE_DIST_SUM_THRES_HYST        (0.7f)   /*! [m], hysteresis: increase threshold of the sum of absolute values of the mean trace sample orthogonal distance to VDY curve of both objects when "relevant" object already on ego lane by O2O analysis */

#define LA_O2O_TRACEREL_OBJ_DIST_PICKUP_MAX                  (6.f)    /*! [m], pick-up threshold for neighboring object's orthogonal distance to trajectory when both objects are on same side of the trajectory */

#endif /* #if (LA_CFG_O2O_EGO_LANE_ASSOC) */

/*------------------------------------------------------------------------
| constants for trace bracket extension for object - obstacle blocked path    |
-------------------------------------------------------------------------*/
#if (LA_CFG_BLOCKED_OBSTACLE_EXTENSION)
#define LA_LAT_LANECHANGE_TIME      (0.5f)          /*!< Comfort Lat LANECHANGE time for calculating 
                                                      blocked path object length @unit:s */
#define LA_SCENE_MAX_OBJ_LENGTH     (10.f)          /*!< Maximum object length for calculating 
                                                      blocked path object length */
#define LA_SCENE_OBJ_WIDTH_NO_POINT (1.8f)          /*!< Assumed object width for non-point objects */
#define LA_SCENE_OBJ_WIDTH_POINT    (0.8f)          /*!< Assumed object width for point objects */
#define LA_SCENE_MIN_PASSABLE_PASS_WIDTH    (1.5f)  /*!< Minimal pass width which the ego vehicle can pass through */
#define LA_SCENE_TB_MIN_DISTX       (5.f)           /*!< Minimum longitudinal distance tor the trace bracket extension to be applied */
#define LA_SCENE_TB_MIN_EGO_SPEED   (20.f/C_KMH_MS) /*!< Minimum ego speed tor the trace bracket extension to be applied */
#define LA_SCENE_TB_MAX_EGO_CURVE   (0.01f)         /*!< Maximum ego curve tor the trace bracket extension to be applied */
#define LA_SCENE_START_IDX_RIGHT_OCC_LIST   (2u)    /*!< Staring point in occupancy list for right entries is number 2 */
#define LA_SCENE_START_IDX_LEFT_OCC_LIST    (3u)    /*!< Staring point in occupancy list for left entries is number 3 */
#define LA_SCENE_START_IDX_FREE_OCC_LIST    (4u)    /*!< First free entry in occupancy list is number 4 */
#endif

/*-------------------------------------------------------------------------
| constants for trace bracket restriction immediately before the relevant object|
-------------------------------------------------------------------------*/
/* Distance around the relevant object */
#define LA_DIST_DIFF_NEIGHBORHOOD_REL_OBJ       (5.0F+C_F32_DELTA)

#if(LA_CFG_NEAR_NEIGHBOURHOOD_DIST_REDUCTION)
/*Distance considered for neigbourhood Near object */
#define LA_DIST_NEIGHBORHOOD_NEAR_OBJ           (10.0F)
/*Lateral Distance from trajectory considered for neigbourhood Near object */
#define LA_TRAJ_DISTANCE_NEAR_OBJ               (1.5F)
#endif/*LA_CFG_NEAR_NEIGHBOURHOOD_DIST_REDUCTION*/

/* Seek width when passing the relevant object */
#define LA_SEEKWIDTH_NEIGHBORHOOD_RELOBJ        (0.2F)

/*------------------------------------------------------------------------
| constants for trace bracket extension for nearby neighboring objects    |
-------------------------------------------------------------------------*/
#if (LA_CFG_EXT_NEIGHBORHOOD_REL_OBJ)
/*! correction width for trace bracket extension */
#define LA_CORR_TRACE_BRACKET_NEIGHBORHOOD                 ((0.5F * LA_STANDARDLANEWIDTHTRCK) + 1.5F) 
/*! minimal longitudinal distance of relevant object for neighborhood trace bracket extension */
#define LA_DIST_MIN_REL_OBJ_NEIGHBORHOOD                   (40.0F)
/* Virtual address for trace bracket extension for nearby neighboring objects */
#ifdef FCT_SIMU
#ifndef LA_CORR_NEIGHBOUR_EXT_DEBUG_VADDR
#define LA_CORR_NEIGHBOUR_EXT_DEBUG_VADDR               (0x202B3100)
#endif
#endif
#endif /*LA_CFG_EXT_NEIGHBORHOOD_REL_OBJ*/

/*------------------------------------------------------------------------
| constants for LA_t_FindNearNeighboringObjToEgoLane  |
-------------------------------------------------------------------------*/
#if (LA_CFG_EXT_NEIGHBORHOOD_REL_OBJ || LA_CFG_ADD_RESTRICTION_OBJ_TRACE) /* Remark: config switches to be removed if 
                                                                                LA_t_FindNearNeighboringObjToEgoLane
                                                                                is called from more functions */
/*! forward distance for search of neighboring object */
#define LA_DIST_DIFF_LONG_FAR_REL_OBJ_NEIGHBORHOOD         (-30.0F)
/*! backward distance for search of neighboring object */
#define LA_DIST_DIFF_LONG_NEAR_REL_OBJ_NEIGHBORHOOD        (15.0F)
/*! distance to ACC trajectory for search of neighboring object */
#define LA_DIST_TO_TRAJ_OBJ_NEIGHBORHOOD                   (6.0F)
/*! lateral distance between double objects which gives hint to double object for neighboring object*/
#define LA_DIST_HINT_DOUBLEOBJ_NEIGHBORHOOD                (12.0F)
/*! longitudinal distance which gives hint to mirror objects for neighboring objects  */
#define LA_DIST_LONG_HINT_MIRROR_NEIGHBORHOOD              (5.0F)
/*! difference of relative velocities which gives hint to mirror objects for neighboring objects */
#define LA_VEL_DIFF_HINT_MIRROR_NEIGHBORHOOD               (0.5F)
/*! maximal lateral distance between relevant object and ACC trajectory for neighborhood trace bracket extension */
#define LA_DIST_MAX_REL_TO_TRAJ_NEIGHBORHOOD               (2.7F)
/*! minimal  value for y-intersection of trace for hint that object is on neighboring lane */
#define LA_DIST_MIN_TRACE_NEIGHBORHOOD                     (0.75F * LA_STANDARDLANEWIDTHSEEK)
/*! invalid value for trace y-intersection */
#define LA_DIST_INVALID_TRACE_NEIGHBORHOOD                 (900.F)

#endif /*(LA_CFG_EXT_NEIGHBORHOOD_REL_OBJ || LA_CFG_ADD_RESTRICTION_OBJ_TRACE)*/


/*****************************************************************************
  MODULLOKALE MAKROS
*****************************************************************************/
#if (LA_CFG_BLOCKED_OBSTACLE_EXTENSION)
#ifndef FUN_PRESEL_ACC_STAT_OBSTACLE
  #define FUN_PRESEL_ACC_STAT_OBSTACLE  (30u) /* To be removed here, if available in algo_constants.h */
#endif
#endif

/*****************************************************************************
  MODULLOKALE TYPEN
*****************************************************************************/

/*****************************************************************************
  MODULLOKALE KONSTANTEN
*****************************************************************************/



/*****************************************************************************
  MODULLOKALE TYPEDEFS
*****************************************************************************/

/*****************************************************************************
  MODULLOKALE VARIABLEN
*****************************************************************************/
#if (LA_CFG_BLOCKED_OBSTACLE_EXTENSION)
static ObjNumber_t t_BlockedObjId;    /*!< Object ID of the "real" object that is selected based on blocked path "object to obstacle" */

#ifdef FCT_SIMU
static float32 f_BlockedPathWidth = 999.f;
#endif
#endif 

#if (LA_CFG_EXT_NEIGHBORHOOD_REL_OBJ)
#ifdef FCT_SIMU
static LA_t_CorrNeighbourDebug LACorrNeighbourDebugInfo;

static const MEASInfo_t LACorrNeighbourDebugMeasInfo =
{
  LA_CORR_NEIGHBOUR_EXT_DEBUG_VADDR,      /*!<.VirtualAddress */
  sizeof(LACorrNeighbourDebugInfo),   /*!<.Length */
  FCT_MEAS_FUNC_ID,                 /*!<.FuncID */
  FCT_MEAS_FUNC_CHAN_ID             /*!<.FuncChannelID */
};
#endif
#endif

/*****************************************************************************
  FUNCTION PROTOTYPES
*****************************************************************************/
#if (LA_CFG_BLOCKED_OBSTACLE_EXTENSION)
static void LA_v_RelTraExtensionBlockedObstacleCorridor(LA_t_RelTraObjInput const * p_ObjectProperties, LA_t_BracketOutput * p_BracketFuncResults);
static void LA_v_FillObj2ObstaclePathOccupation (void);
static float32 LA_f_GetObjectWidthInLane(const ObjNumber_t t_Object);
static void LA_v_InitPathOccupation (const float32 f_HalfLaneWidth);
static float32 LA_f_GetCalcDriveAroundDist(const float32 f_EgoSpeedXObjSync);
static void LA_v_CalcOccPathWidth( SIT_t_PathOccResultArray t_LAPathhOccResult);
static void LA_v_InitSiPathOccResult(SIT_t_PathOccResultArray t_LAPathhOccResult, const float32 f_HalfLaneWidth);
static void LA_v_CheckForNarrowPath(const SIT_t_PathOccResult a_LAPathhOccResult[SIT_PATH_OCC_ENTRIES]);
static void LA_v_InsertObjInPathOcc(
  uint32 * pui_ActualEntry, uint32 * pui_NextFree, const SIT_t_PathOccInsertObjData * pt_LAPathOccInsertObjDataPtr);
#endif /*LA_CFG_BLOCKED_OBSTACLE_EXTENSION*/

#if (LA_CFG_O2O_EGO_LANE_ASSOC)
static void LA_v_PerformEgoLaneByO2OAnalysis(void);
static void LA_v_PerformEgoLaneByTraceAnalysis(void);
#endif

static void LA_v_RelTraRestrictNeighbourhoodRelObj(LA_t_RelTraObjInput const *p_ObjInput , LA_t_AssTraEnvironment const *p_Environment , LA_t_BracketOutput *p_BracketOut );

#if (LA_CFG_EXT_NEIGHBORHOOD_REL_OBJ)
static void LA_v_CalcCorrExtendNeighbourhoodRelObj(LA_t_RelTraObjInput const * p_ObjInput , LA_t_AssTraEnvironment const * p_Environment , LA_t_BracketOutput * p_BracketOut );
#endif

#if (LA_CFG_O2O_EGO_LANE_ASSOC)
static boolean LA_b_O2OCheckEgoLaneByObjTrace(const ObjNumber_t t_ObjNr);
static boolean LA_b_O2OCheckEgoLaneByO2O(const ObjNumber_t t_ObjNrRel);
static boolean LA_b_O2OCheckRelObjDistToTrajHint(const ObjNumber_t t_ObjNrRel);
static boolean LA_b_O2OCheckRelObjTraceHint(const ObjNumber_t t_ObjNrRel);
static boolean LA_b_O2OCheckRelObjBorderDistHint(const ObjNumber_t t_ObjNrRel);
static boolean LA_b_O2OCheckRelObjCutOutHint( const ObjNumber_t t_ObjNrRel);
static ObjNumber_t LA_t_O2OFindNeighboringO2OObject(const ObjNumber_t t_ObjNrRel);
static boolean LA_b_O2OCheckO2OTraceRelationHint( const ObjNumber_t t_ObjNrRel, const ObjNumber_t t_ObjNr);
static boolean LA_b_O2OCheckO2OTraceRelationFurtherAnalysis( const ObjNumber_t t_ObjNrRel, float32 f_DistRelToTraj, float32 f_DistObjToTraj);
#endif

#if ((LA_CFG_EXT_LOWSPEEDFUSEDBRD) && (FCT_CFG_ROAD_INPUT))
static void LA_v_CalcCorrExtendLowSpeedFusedBrd(LA_t_RelTraObjInput const * p_ObjInput, LA_t_AssTraEnvironment const *p_Environment, LA_t_BracketOutput * p_BracketOut );
#endif /* END IF ((LA_CFG_EXT_LOWSPEEDFUSEDBRD) && (FCT_CFG_ROAD_INPUT)) */
// PRQA S 7013 STTLN_EXCEEDED
/* date: 2016-07-04, reviewer: Davtjan, Grant, reason: Number of lines exceeded per file, not safety critical */
#if (LA_CFG_BLOCKED_OBSTACLE_EXTENSION)
/*************************************************************************************************************************
  Functionname:    LA_v_InitCorridorScene                                                                           */ /*!

  @brief           Initialization of static variables for si_corridor_scene.c

  @description     Initialization of static variables, like Object ID, etc. for si_corridor_scene.c
                   @startuml
                   Partition LA_v_InitCorridorScene {
                   Start
                   -Initialize object ID of the "real" object that is selected based on blocked path "object to obstacle”
                   
                   end
                   }
                   @enduml

  @return          void

  @param[in]       void

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   LA_CFG_BLOCKED_OBSTACLE_EXTENSION : As defined in la_cfg.h. Configuration switch enabling the trace bracket extension for the blocked 
                   path between an object and an obstacle. This will be usable only if FCT_CFG_COURSE_PREDICTION is ON.
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         3/17/2016

  @author          Marie-Theres Boll | Marie-Theres Boll@continental-corporation.com | 
*************************************************************************************************************************/
void LA_v_InitCorridorScene(void)
{
  /* Initialize object ID of the "real" object that is selected based on blocked path "object to obstacle" */
  t_BlockedObjId  = OBJ_INDEX_NO_OBJECT;
}
#endif



#if (LA_CFG_BLOCKED_OBSTACLE_EXTENSION)
/*************************************************************************************************************************
  Functionname:    LA_v_GetBlockedObstacleCorridor                                                                  */ /*!

  @brief           Determine the "real" object that is selected based on blocked path "object to obstacle"

  @description     Determine the "real" object that is selected based on blocked path 
                   "object to obstacle". A blocked path between two "real" objects is not considered.
                   Here, "object" means an "object" that fulfills the ACC function preselection 
                   (pt_LAOutput->LABasePreselObjList[..] == TRUE), an obstacle doesn't fulfills the ACC function preselection.
                   @startuml
                   Partition LA_v_GetBlockedObstacleCorridor {
                   Start
                   -Initialize the object that is selected based on blocked path "object to obstacle”
                   Partition #LightBlue **LA_v_FillObj2ObstaclePathOccupation** {
                   -Insert objects and obstacle into path occupation list
                   }
                   
                   Partition #LightBlue **LA_v_CalcOccPathWidth** {
                   -Calculate resulting path widths of neigbouring objects and obstacles within path
                   }
                   
                   Partition #LightBlue **LA_v_CheckForNarrowPath** {
                   - Check for blocked object to obstacle path
                   }
                   
                   If(Both Blocked farther and Blocked Near Objects are greater than zero) then (Yes)
                      If (Blocked near object fulfills the ACC function preselection) then (yes)
                        -select Blocked near object as object to obstacle 
                      Elseif(Blocked Farther object fulfills the ACC function preselection) then (yes)
                        -select Blocked near object as object to obstacle 
                      Endif
                   endif
                   
                   end
                   }
                   @enduml

  @return          -

  @param[in]       -

  @glob_in         pt_LAOutput->LABasePreselObjList : Array of type BasePreselObjList_t(Boolean) which stores pre-selection decision for one object   [TRUE, FALSE]
  @glob_out        -

  @c_switch_part   FCT_SIMU : Enable FCT Simulation as defined in fct_config.h
  @c_switch_part   FASTSIM : Enable FASTSIM environment

  @c_switch_full   LA_CFG_BLOCKED_OBSTACLE_EXTENSION : As defined in la_cfg.h. Configuration switch enabling the trace bracket extension for the blocked 
                   path between an object and an obstacle. This will be usable only if FCT_CFG_COURSE_PREDICTION is ON.
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         3/4/2016
  @todo            Call to SIMSaveObj2ObstacleOccPathInfo has to be moved to SIM Frame

  @author          Marie-Theres Boll | Marie-Theres Boll@continental-corporation.com | 
*************************************************************************************************************************/
void LA_v_GetBlockedObstacleCorridor(void)
{
  
  SIT_t_PathOccResultArray  a_PathOccResultObj2Obstacle;  /*!< Pairs of objects and obstacles that create a corridor */

  pt_LAOutput->s_BlockedNearObj  = OBJ_INDEX_NO_OBJECT;      /*!< The longitudinal closer object that is part of the blocking object-obstacle pair */
  pt_LAOutput->s_BlockedFartherObj    = OBJ_INDEX_NO_OBJECT;      /*!< The longitudinal further away object that is part of the blocking object-obstacle pair */

  /* Initialize the object that is selected based on blocked path "object to obstacle" */
  t_BlockedObjId = OBJ_INDEX_NO_OBJECT;

#ifdef FCT_SIMU
  pt_LAOutput->f_BlockedPathWidth = 999.f;
#endif

  /* Insert objects and obstacle into path occupation list */
  LA_v_FillObj2ObstaclePathOccupation( );

  /* Calculate resulting path widths of neigbouring objects and obstacles within path */
  LA_v_CalcOccPathWidth( a_PathOccResultObj2Obstacle);

  /* Check for blocked object to obstacle path */
  LA_v_CheckForNarrowPath(a_PathOccResultObj2Obstacle);


  /* Determine "real" object that is selected based on blocked path "object to obstacle" 
  -> the obstacle shall not be selected but only the object that fulfills the ACC function preselection. */
  if ((pt_LAOutput->s_BlockedNearObj >= 0) && (pt_LAOutput->s_BlockedFartherObj >= 0))
  {
    if(pt_LAOutput->LABasePreselObjList[pt_LAOutput->s_BlockedNearObj] == TRUE)
    {
      t_BlockedObjId = pt_LAOutput->s_BlockedNearObj;
    }
    else if(pt_LAOutput->LABasePreselObjList[pt_LAOutput->s_BlockedFartherObj] == TRUE)
    {
      t_BlockedObjId = pt_LAOutput->s_BlockedFartherObj;
    }
    else
    {
      /* Nothing: Initialization done before */
    }
  }
}
#endif

/*************************************************************************************************************************
  Functionname:    LA_v_ExecuteSceneBracketFuncstions                                                               */ /*!

  @brief           Determine the scene related trace brackets for a specific object

  @description     Determine the scene related trace brackets for a specific object
                   @startuml
                   Partition LA_v_ExecuteSceneBracketFuncstions {
                   Start
                   If(Extension of Blocked Obstacle Corridor is Enabled)then (yes)
                     Partition #LightBlue **LA_v_RelTraExtensionBlockedObstacleCorridor** {
                     - Set the trace brackets based on a blocked path "object to obstacle"
                     }
                   Endif
                   
                   If(Restriction on Neighborhood object is Enable) then (yes)
                     Partition #LightBlue **LA_v_RelTraRestrictNeighbourhoodRelObj** {
                     - Restrict track width relative to neighborhood object
                     }
                   Endif
                   
                   If(Extension of Neighborhood object is enable ) then (yes)
                    Partition #LightBlue **LA_v_CalcCorrExtendNeighbourhoodRelObj** { 
                     - extend trace brackets for the relevant object in situations with close neighboring objects
                     }
                   endif
                   
                   If(Extension of Low Speed Fused Border is enabled) then (yes)
                    Partition #LightBlue **LA_v_CalcCorrExtendNeighbourhoodRelObj** { 
                     - extend trace brackets for the relevant object in low speed and close range situations
                     }
                   endif
                   
                   
                   end
                   }
                   @enduml

  @return          void

  @param[in]       p_ObjectProperties : Pointer to datatype LA_t_RelTraObjInput which describes object properties as defined in si_corridor_crit.h
  @param[in]       p_Environment : Pointer to datatype LA_t_AssTraEnvironment which gives information about relevant object as defined in si_corridor_crit.h
  @param[in]       p_BracketFuncEnableFlags : Pointer to datatype LA_t_BracketFuncEnable which has flags describes different configurations of trace brackets
                    p_BracketFuncEnableFlags->bExtensionBlockedObstacleCorridor : Boolean variable for extension of corridor in case of blocked obstacle                 [TRUE, FALSE]
                    p_BracketFuncEnableFlags->bEnableRestrictionNeighbourhoodRelObj : Boolean variable for Restriction of corridor in case of Neighbor object            [TRUE, FALSE]
                    p_BracketFuncEnableFlags->bEnableExtensionNeighbourhoodRelObj : Boolean variable for Extension of corridor in case of Neighbor object                [TRUE, FALSE]
                    p_BracketFuncEnableFlags->bEnableExtensionLowSpeedFusedBrd : Boolean variable for Extension of corridor in case of low speed and fused road border   [TRUE, FALSE]

  @param[in,out]   p_BracketFuncResults : Pointer to datatype LA_t_CriteriaMatrix which contains trace bracket results
                    p_BracketFuncResults->ExtensionBlockedObstacleCorridor : Extension based on scene analysis: obstacle blocks path
                    p_BracketFuncResults->RestrictionNeighbourhoodRelObj : Restriction for Neighbor Objects 
                    p_BracketFuncResults->ExtensionNeighbourhoodRelObj : Extension for Neighbor Objects
                    p_BracketFuncResults->AddExtensionLowSpeedFusedBrd : Extension for low speed and fused road border


  @glob_in         -
  @glob_out        -

  @c_switch_part   LA_CFG_BLOCKED_OBSTACLE_EXTENSION : Configuration switch enabling the trace bracket extension for the blocked path 
                                                       between an object and an obstacle.This will be enabled only if FCT_CFG_COURSE_PREDICTION is ON
  @c_switch_part   LA_CFG_EXT_NEIGHBORHOOD_REL_OBJ : Configuration switch to enable bracket extension used for situations in which the 
                                                     relevant object moves in the direction of a near neighboring object. For the relevant 
                                                     object the brackets are extended. Should only be active if camera lane information is 
                                                     available to detect the ego lane change phases.
  @c_switch_part   LA_CFG_EXT_LOWSPEEDFUSEDBRD: Extend trace brackets for low ego velocities and missing adjacent lanes.Since low speeds are 
                                                currently a problem for lanematrix, check with fused road border if a driveable lane exists.
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         2/29/2016

  @author          Marie-Theres Boll | Marie-Theres Boll@continental-corporation.com | 
*************************************************************************************************************************/
void LA_v_ExecuteSceneBracketFuncstions(LA_t_RelTraObjInput const * p_ObjectProperties, LA_t_AssTraEnvironment const * const p_Environment,
  LA_t_BracketFuncEnable const * p_BracketFuncEnableFlags, LA_t_CriteriaMatrix * p_BracketFuncResults)
{
#if (LA_CFG_BLOCKED_OBSTACLE_EXTENSION)
  /* Determine trace brackets based on a blocked path "object to obstacle" */
  if(p_BracketFuncEnableFlags->bExtensionBlockedObstacleCorridor != LA_CORR_BRACKET_FUNC_DISABLED)
  {
    LA_v_RelTraExtensionBlockedObstacleCorridor(p_ObjectProperties, &(p_BracketFuncResults->ExtensionBlockedObstacleCorridor));
  }
#endif

  /* RestrictionNeighbourhoodRelObj */
  if (p_BracketFuncEnableFlags->bEnableRestrictionNeighbourhoodRelObj != LA_CORR_BRACKET_FUNC_DISABLED)
  {
    LA_v_RelTraRestrictNeighbourhoodRelObj(p_ObjectProperties, p_Environment, &p_BracketFuncResults->RestrictionNeighbourhoodRelObj);
  }
  
#if (LA_CFG_EXT_NEIGHBORHOOD_REL_OBJ) 
  /* ExtendNeighbourhoodRelObj */
  if (p_BracketFuncEnableFlags->bEnableExtensionNeighbourhoodRelObj != LA_CORR_BRACKET_FUNC_DISABLED)
  {
    LA_v_CalcCorrExtendNeighbourhoodRelObj(p_ObjectProperties, p_Environment, &p_BracketFuncResults->ExtensionNeighbourhoodRelObj);
  }
#endif

#if ((LA_CFG_EXT_LOWSPEEDFUSEDBRD) && (FCT_CFG_ROAD_INPUT))
  /* Extend trace brackets for low speed as a function of fused road border */
  if (p_BracketFuncEnableFlags->bEnableExtensionLowSpeedFusedBrd != LA_CORR_BRACKET_FUNC_DISABLED)
  {
    LA_v_CalcCorrExtendLowSpeedFusedBrd(p_ObjectProperties, p_Environment, &p_BracketFuncResults->AddExtensionLowSpeedFusedBrd);
  }
#endif /* END IF ((LA_CFG_EXT_LOWSPEEDFUSEDBRD) && (FCT_CFG_ROAD_INPUT)) */
}

#if (LA_CFG_BLOCKED_OBSTACLE_EXTENSION)
/*************************************************************************************************************************
  Functionname:    LA_v_FillObj2ObstaclePathOccupation                                                               */ /*!

  @brief           Fill the path occupation list with objects and obstacles

  @description     Fill the path occupation list with objects (ACC quality) and obstacles
                   @startuml
					Partition LA_v_FillObj2ObstaclePathOccupation {
					Start
					- set path width for all objects
					Partition #LightBlue **LA_v_InitPathOccupation** { 
					- initialize path occupation list
					}
					
					Repeat 
					- insert stationary obstacles into list
					If(object is stationary AND object is not moving to stationary AND object is consider as obstacle object is not crossing) then (yes)
					- set object data structure for path occupation list entry
					- Object length is not the "real" object length but an artificial object length representing the space where the ego vehicle will not pass and will drive around
					If(Measured distance to trajectory is less than zero)then (yes)
					- insert to right path of list
					- recalculate distance to trajectory using absolute value and respecting object width
					Else
					- insert to left path of list
					- recalculate distance to trajectory using absolute value and respecting object width
					Endif
					endif
					Repeat while(For all the objects in use)
					
					Repeat
					If(object is stationary OR object is moving & sum of Ego velocity sync and object velocity is less that SIT_CORR_SEL_MOVING_AS_STAT_SPEED AND object is in preselection list AND object is not crossing object  ) then (yes)
					- set object data structure for path occupation list entry
					- Object length is not the "real" object length but an artificial object length representing the space where the ego vehicle will not pass and will drive around
						If(Measured distance to trajectory is less than zero)then (yes)
						- insert to Right path of list
						- recalculate distance to trajectory using absolute value and respecting object width
						Else
						- insert to left path of list
						- recalculate distance to trajectory using absolute value and respecting object width
						Endif
					endif
                    Repeat while(For all the objects in use)
                    end
                    }
                    @enduml

  @return          void

  @param[in]       t_LAPathOccupation : Array of SIT_t_PathOccupation which if of size SIT_PATH_OCC_ENTRIES as defined in si.h

  @glob_in         SLATE_t_GetNumOfObjectsUsed() : Macro to access number of objects (based on GET_EM_PUB_OBJ_DATA_PTR),defined in algo_glob.h                                      [-1 ... EM_N_OBJECTS-1]
  @glob_in         *SLATE_pu_GetDistXSortedObj(j) : Objects sorted according to x distance, defined in algo_glob.h                                                                [-1 ... EM_N_OBJECTS-1]
  @glob_in         *SLATE_pt_GetObjDynProperty(t_ObjNr): Macro to obtain dynamic object property. This signal indicates wether the object is moving, 
                             stationary or oncoming, based on comparison of the longitudinal relative velocity with the host vehicle velocity,defined in algo_glob.h         [0...7]
                             enum { EM_GEN_OBJECT_DYN_PROPERTY_CROSSING_LEFT=3,EM_GEN_OBJECT_DYN_PROPERTY_STOPPED=6,EM_GEN_OBJECT_DYN_PROPERTY_CROSSING_RIGHT=4,EM_GEN_OBJECT_DYN_PROPERTY_MOVING=0,EM_GEN_OBJECT_DYN_PROPERTY_ONCOMING=2,EM_GEN_OBJECT_DYN_PROPERTY_STATIONARY=1,EM_GEN_OBJECT_DYN_PROPERTY_UNKNOWN=5,EM_GEN_OBJECT_DYN_PROPERTY_MAX_DIFF_TYPES=7,}
  @glob_in         SLATE_u_GetAccQuality(t_ObjNr) : Macro to access EM-based function pre-selection information (based on GET_EM_OBJ_PUB(iObj) 
                                                             ,Defined in algo_glob.h                                                                                         [full range of unsigned char]

  @glob_in         *SLATE_pt_GetObjDynSubProperty : Defined in algo_glob.h, Macro to obtain Dynamic sub-property of object which can take values for enum { ARS_OBJECT_SUBPROP_NORMAL=0,SLATE_OBJECT_SUBPROP_CROSSING=1} 
                                                                                                                                                                             [0,1]
  @glob_in         OBJ_GET_CP(i) : Macro to obtain Information about objects relation to estimated course as defined in fct_sen.h
  @glob_in         pt_LAInput->t_RTE.pf_ObjVrelX(t_ObjNrRel) : Longitudinal relative velocity for the given object, defined in algo_main.h                                                   [-330.f ... 330.f] m/s
  @glob_in         pt_LAOutput->LABasePreselObjList : Array to store pre-selection decision for the given object, defined in la_ext.h                                                    [True, False]

  @glob_out        -

  @c_switch_part   -
  @c_switch_full   LA_CFG_BLOCKED_OBSTACLE_EXTENSION : As defined in la_cfg.h. Configuration switch enabling the trace bracket extension for the blocked 
                   path between an object and an obstacle. This will be usable only if FCT_CFG_COURSE_PREDICTION is ON.
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         2/29/2016

  @author          Marie-Theres Boll | Marie-Theres Boll@continental-corporation.com | 
*************************************************************************************************************************/
static void LA_v_FillObj2ObstaclePathOccupation (void)
{
  ObjNumber_t i, j;
  float32 f_ObjHalfWidth, f_ObjLength, f_CalculatedObjLength, f_ObjVrelX, f_EgoVelObjSync;
  uint32  ActualR = LA_SCENE_START_IDX_RIGHT_OCC_LIST;  /* staring point for right entries is number 2 */ 
  uint32  ActualL = LA_SCENE_START_IDX_LEFT_OCC_LIST;   /* staring point for left entries is number 3 */
  uint32  NextFree = LA_SCENE_START_IDX_FREE_OCC_LIST;  /* so first free entry is number 4 */
  SLATE_t_Obj_DynamicProperty t_ObjDynProperty;
  SIT_t_PathOccInsertObjData  LAPathOccInsertObjData;
  boolean b_ObjIsMovingToStationary;
#if FCT_USE_EM_ARS_TECH_OBJECT_LIST
  SLATE_t_Obj_DynamicSubProperty t_ObjDynSubProperty;
#endif
  uint8 u_AccQuality;

  f_EgoVelObjSync = *pt_LAInput->t_RTE.pf_EgoVelObjSync;

  /* set path width for all objects */
  LAPathOccInsertObjData.HalbeSpurbreite = SIT_HALF_LANEOCCUPATION_WIDTH;

  /* initialize path occupation list */
  LA_v_InitPathOccupation(LAPathOccInsertObjData.HalbeSpurbreite);

  /* First, insert stationary obstacles into list. Insert objects based on sorted object list */
  for(j = 0; j < SLATE_t_GetNumOfObjectsUsed(); j++)
  {
    i = *SLATE_pu_GetDistXSortedObj(j);
#if (FCT_USE_EM_ARS_TECH_OBJECT_LIST)
    t_ObjDynSubProperty = *SLATE_pt_GetObjDynSubProperty(i);
#endif /* END IF (FCT_USE_EM_ARS_TECH_OBJECT_LIST) */
    /* First, insert stationary obstacles into list. Crossing objects are excluded from corridor selection list */
    b_ObjIsMovingToStationary = ((SLATE_b_GetObjIsMovingToStationary(i))== FALSE);

    u_AccQuality = SLATE_u_GetAccQuality(i);
    t_ObjDynProperty = *SLATE_pt_GetObjDynProperty(i);

    if( (t_ObjDynProperty == SLATE_OBJECT_PROPERTY_STATIONARY) &&
         (b_ObjIsMovingToStationary != FALSE) && 
         (u_AccQuality == FUN_PRESEL_ACC_STAT_OBSTACLE) 
#if (FCT_USE_EM_ARS_TECH_OBJECT_LIST)
         &&(t_ObjDynSubProperty != SLATE_OBJECT_SUBPROP_CROSSING)
#endif
      )
    {
      f_ObjHalfWidth = 0.5f * LA_f_GetObjectWidthInLane(i);
      f_ObjLength    = (pt_LAInput->pt_FIPOA->t_ObjList[i].fObjectLength);
      /* set object data structure for path occupation list entry */
      LAPathOccInsertObjData.DistTrajToObjEdge = pt_LAOutput->t_LAObjOutputList[i].TrajDist.TrajDistMeas.Y.f0;
      LAPathOccInsertObjData.ObjID = i;
      /* Object length is not the "real" object length but an artificial object length representing the 
      space where the ego vehicle will not pass and will drive around */
      f_CalculatedObjLength = LA_f_GetCalcDriveAroundDist(*pt_LAInput->t_RTE.pf_EgoVelObjSync) + (f_ObjLength + FCT_WHEELBASE_DEFAULT);
      LAPathOccInsertObjData.CalculatedObjLength = MIN_FLOAT(LA_SCENE_MAX_OBJ_LENGTH, f_CalculatedObjLength);
      LAPathOccInsertObjData.ObjDistOnTraj = pt_LAOutput->t_LAObjOutputList[i].TrajDist.ObjDistOnTraj;

      /* left side or right side ? */
      if(LAPathOccInsertObjData.DistTrajToObjEdge < 0.f)
      {
        /* right side, so insert to right path of list */
        /* recalculate distance to trajectory using absolute value and respecting object width */
        LAPathOccInsertObjData.DistTrajToObjEdge = fABS(LAPathOccInsertObjData.DistTrajToObjEdge) - f_ObjHalfWidth;
        LA_v_InsertObjInPathOcc(&ActualR, &NextFree, &LAPathOccInsertObjData);
      }
      else
      {
        /* left side, so insert to left path of list */
        /* recalculate distance to trajectory using absolute value and respecting object width */
        LAPathOccInsertObjData.DistTrajToObjEdge = fABS(LAPathOccInsertObjData.DistTrajToObjEdge) - f_ObjHalfWidth;
        LA_v_InsertObjInPathOcc(&ActualL, &NextFree, &LAPathOccInsertObjData);
      }
    }
  }

  /* Then, insert object with ACC quality to ensure that these object are inserted in any case and 
      replace obstacles which are inserted before. Insert objects based on sorted object list */
  for(j = 0; j < SLATE_t_GetNumOfObjectsUsed(); j++)
  {
    i = *SLATE_pu_GetDistXSortedObj(j);
    t_ObjDynProperty = *SLATE_pt_GetObjDynProperty(i);
    f_ObjVrelX = *pt_LAInput->t_RTE.pf_ObjVrelX(i);
#if (FCT_USE_EM_ARS_TECH_OBJECT_LIST)
    t_ObjDynSubProperty = *SLATE_pt_GetObjDynSubProperty(i);
#endif /* END IF (FCT_USE_EM_ARS_TECH_OBJECT_LIST) */
    /* Then, insert stationary object with ACC quality to ensure that these object are inserted in any case and 
        replace obstacles which are inserted before. Slow moving objects are handled as stationary objects;
        definition of slow moving is constant SIT_CORR_SEL_MOVING_AS_STAT_SPEED. 
        Crossing objects are excluded from corridor selection list */
    if( ( ( (t_ObjDynProperty == SLATE_OBJECT_PROPERTY_STATIONARY) 
#if (FCT_CFG_SENSOR_TYPE_CAMERA)
         || (t_ObjDynProperty == SLATE_OBJECT_PROPERTY_STOPPED) 
#endif /* FCT_CFG_SENSOR_TYPE_CAMERA */
          ) ||
          ( (t_ObjDynProperty == SLATE_OBJECT_PROPERTY_MOVING) &&
            ((f_EgoVelObjSync + f_ObjVrelX) < SIT_CORR_SEL_MOVING_AS_STAT_SPEED)
          )
        ) &&
        (pt_LAOutput->LABasePreselObjList[i] == TRUE)
#if (FCT_USE_EM_ARS_TECH_OBJECT_LIST)
        && (t_ObjDynSubProperty != SLATE_OBJECT_SUBPROP_CROSSING)
#endif
      )
    {
      f_ObjHalfWidth = 0.5f * LA_f_GetObjectWidthInLane(i);
      f_ObjLength    = (pt_LAInput->pt_FIPOA->t_ObjList[i].fObjectLength);
      /* set object data structure for path occupation list entry */
      LAPathOccInsertObjData.DistTrajToObjEdge = pt_LAOutput->t_LAObjOutputList[i].TrajDist.TrajDistMeas.Y.f0;
      LAPathOccInsertObjData.ObjID = i;
      /* Object length is not the "real" object length but an artificial object length representing the 
      space where the ego vehicle will not pass and will drive around */
      f_CalculatedObjLength = LA_f_GetCalcDriveAroundDist(*pt_LAInput->t_RTE.pf_EgoVelObjSync) + (f_ObjLength + FCT_WHEELBASE_DEFAULT);
      LAPathOccInsertObjData.CalculatedObjLength = MIN_FLOAT(LA_SCENE_MAX_OBJ_LENGTH, f_CalculatedObjLength);
      LAPathOccInsertObjData.ObjDistOnTraj = pt_LAOutput->t_LAObjOutputList[i].TrajDist.ObjDistOnTraj;

      /* left side or right side ? */
      if(LAPathOccInsertObjData.DistTrajToObjEdge < 0.f)
      {
        /* right side, so insert to right path of list */
        /* recalculate distance to trajectory using absolute value and respecting object width */
        LAPathOccInsertObjData.DistTrajToObjEdge = fABS(LAPathOccInsertObjData.DistTrajToObjEdge) - f_ObjHalfWidth;
        LA_v_InsertObjInPathOcc(&ActualR, &NextFree, &LAPathOccInsertObjData);
      }
      else
      {
        /* left side, so insert to left path of list */
        /* recalculate distance to trajectory using absolute value and respecting object width */
        LAPathOccInsertObjData.DistTrajToObjEdge = fABS(LAPathOccInsertObjData.DistTrajToObjEdge) - f_ObjHalfWidth;
        LA_v_InsertObjInPathOcc(&ActualL, &NextFree, &LAPathOccInsertObjData);
      }
    }
  }
}
#endif /* LA_CFG_BLOCKED_OBSTACLE_EXTENSION */

#if(LA_CFG_BLOCKED_OBSTACLE_EXTENSION)
/*************************************************************************************************************************
  Functionname:    LA_v_InitPathOccupation                                                                          */ /*!

  @brief           Init the path occupation list

  @description     Initialize the path occupation list
                   @startuml
                   Partition LA_v_InitPathOccupation {
                   Start
                   - Initialize the path occupation list with  Half lane width
                   end
                   }
                   @enduml

  @return          -

  @param[in]       t_LAPathOccupation : Array of SIT_t_PathOccupation which if of size SIT_PATH_OCC_ENTRIES.
                      t_LAPathOccupation[i].LengthTrajEgoFrontToObj : Distance b/w Ego front to the object [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                      t_LAPathOccupation[i].DistTrajToObjEdge : Distance from trajectory to object edge    [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      t_LAPathOccupation[i].ObjID : Object id                                              [-1 ... EM_N_OBJECTS-1]
                      t_LAPathOccupation[i].prev : Address to the SIT_t_PathOccupation type of data          [ Address range]
                      t_LAPathOccupation[i].next : Address to the SIT_t_PathOccupation type of data          [ Address range]
  @param[in]       f_HalfLaneWidth : Half lane width                                                       [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         3/4/2016

  @author          Marie-Theres Boll| Marie-Theres Boll@continental-corporation.com | 
*************************************************************************************************************************/
static void LA_v_InitPathOccupation (const float32 f_HalfLaneWidth)
{
  uint32 i;
  /* SiPathOccupation entries 0 and 1 are starting points of the list.
  SiPathOccupation[0] is starting point for right side with Distance to Trajectory of
  half trackwidth.
  SiPathOccupation[1] is starting point for left side with Distance to Trajectory of
  half trackwidth.
  This is to find the first entry of narrow track and to keep information of trackwidth within the list. */
  
  /*initialize entire list */
  for(i=0u; i<(uint32)SIT_PATH_OCC_ENTRIES;i++)
  {

    pt_LAOutput->a_PathOccObj2Obstacle[i].DistTrajToObjEdge = f_HalfLaneWidth;

  }


}
#endif

#if (LA_CFG_BLOCKED_OBSTACLE_EXTENSION)

/*************************************************************************************************************************
  Functionname:    LA_f_GetObjectWidthInLane                                                                        */ /*!

  @brief           Get object width in lane

  @description     Get object width in lane. The width is object class dependent.
                   @startuml
                   Partition LA_f_GetObjectWidthInLane {
                   Start
                   If(Object class is point) then(Yes)
                   - set object width as point
                   Else 
                   -set object widht as no point
                   Endif
                   - Return object width
                   end
                   }
                   @enduml

  @return          Width of object of type float32                    [0.8f,1.8f] [LA_SCENE_OBJ_WIDTH_POINT,SI_SCENE_OBJ_WIDTH_NO_POINT]

  @param[in]       t_Object : Object number                           [0...39]

  @glob_in         -
  @glob_out        -

  @c_switch_part   -

  @c_switch_full   LA_CFG_BLOCKED_OBSTACLE_EXTENSION : Enable blocked obstacle extension as defined in la_cfg.h. This will be enabled only when FCT_CFG_COURSE_PREDICTION is on.
  @c_switch_full   FCT_CFG_COURSE_PREDICTION : Enable course prediction as defined in fct_config.h.
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         2/27/2016

  @author          Marie-Theres Boll | Marie-Theres Boll@continental-corporation.com | 
*************************************************************************************************************************/
static float32 LA_f_GetObjectWidthInLane(const ObjNumber_t t_Object)
{
  float32 f_ObjectWidth;

  /* Set object width based on object class */
  if (*SLATE_pt_GetObjClassification(t_Object) == SLATE_OBJCLASS_POINT)
  {
    f_ObjectWidth = LA_SCENE_OBJ_WIDTH_POINT;
  }
  else
  {
    f_ObjectWidth = LA_SCENE_OBJ_WIDTH_NO_POINT;
  }
  return f_ObjectWidth;
}
#endif

#if (LA_CFG_BLOCKED_OBSTACLE_EXTENSION)
/*************************************************************************************************************************
  Functionname:    LA_f_GetCalcDriveAroundDist                                                                      */ /*!

  @brief           Determine the "drive around distance"

  @description     Determine the artificial object length representing the 
                   space where the ego vehicle will not pass and will drive around
                   @startuml
                   Partition LA_f_GetCalcDriveAroundDist {
                   Start
                   - Calculate drive around distance based on the ego speed and Comfort Lateral LANECHANGE time 
                   -return calculated drive around distance
                   end
                   }
                   @enduml

  @return          f_CalcDriveAroundDist : artificial object length representing the space where the ego vehicle will not pass 
                                           and will drive around                      [0f ... 150f] m

  @param[in]       f_EgoSpeedXObjSync : Ego speed                                     [-330.f ... 330.f] m/s

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  
  @c_switch_full   LA_CFG_BLOCKED_OBSTACLE_EXTENSION : Enable blocked obstacle extension as defined in la_cfg.h. This will be enabled only when FCT_CFG_COURSE_PREDICTION is on.
  @c_switch_full   FCT_CFG_COURSE_PREDICTION : Enable course prediction as defined in fct_config.h.
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         2/27/2016

  @author          Marie-Theres Boll| Marie-Theres Boll@continental-corporation.com | 
*************************************************************************************************************************/
static float32 LA_f_GetCalcDriveAroundDist(const float32 f_EgoSpeedXObjSync)
{
  float32 f_CalcDriveAroundDist;

  /* The drive around distance depends on the ego speed */
  f_CalcDriveAroundDist = (MAX_FLOAT(0.f, f_EgoSpeedXObjSync)) * LA_LAT_LANECHANGE_TIME;

  return f_CalcDriveAroundDist;
}
#endif

#if (LA_CFG_BLOCKED_OBSTACLE_EXTENSION)
/* PRQA S 7004 CYCLOMETRIC_COMPLEXITY */
/* date: 2015-08-19, reviewer: Rachit Sharma (uidr5426), reason: Cyclometric complexity, not safety critical */
/*************************************************************************************************************************
  Functionname:    LA_v_InsertObjInPathOcc                                                                          */ /*!

  @brief           Insert a single object or obstacle into the occupancy list

  @description     Insert a single object or obstacle into the occupancy list. 
                   It is ensured that an object which passes the ACC preselection 
                   suppresses an obstacle without ACC quality.
                   @startuml
Partition LA_v_InsertObjInPathOcc {
Start  
	if(last entry at the side nearer than new entry) then (yes)
		-add new edge at the end of the list
		-insert first point of object
		-prepare second point entry
		-insert second point of object
		-prepare next edge entry
	else
		-the new entry must be inserted between the previous found entries
		-first look for distance to insert new edge 
		-ListInsertPtr now stands at list entry nearer than new edge
		-now look for path wider than new entry
		repeat 
			if(object id is valid) then (yes)
				
			else
				-ACC obstacle Quality is true
			endif
			
			if(ACC obstacle Quality is false) then (yes)
				
			else
				-break the loop
			endif
		repeat while(untill path wider than new entry is found)
		
	    if(object id is valid)
			
		else
			-ObjIsMovingToStationary and ObjDynamicProperty is false and drop acc quality
		endif
		
		if(new edge is farer away than this entry insert new edge as follower of ListInsertPtr)then (yes)
			- ListInsertPtr now stands at list entry wider than new edge
		    if(Path Occ Object to Obstacle next is NULL) then (yes)
				-new entry is last in list, so directly insert second point
				-insert second point of object
				-prepare next edge entry
			else
				-new entry was not last in list, so look for position to insert second edge of entry
				repeat 
					if(LengthTrajEgoFrontToObj is less than sum of ObjDistOnTraj and CalculatedObjLength)
						if(object is valid) then (yes)
							
						else
							-ACCobstacleQuality is true
					    endif
						
						if(DistTrajToObjEdge is less than or equal to DistTrajToObjEdge and acc obstacle quality is false)
							-this point is nearer but narrower than actual entry, so keep it
							-next entry in list
							-increment Pointer to next free space in SiPathOccupation
						else
							if(entry is nearer and wider than new entry) then (yes)
								-This point once was endpoint of an object, narrower than actual, so keep it and just give it new ObjID and DistTrajToObjEdge data
							    -next entry in list
								-increment Pointer to next free space in SiPathOccupation
							else
								if(point wider than actual entry) then (yes)
									-delete it from list
									-next entry in list
								else
									-insert second point of object
								    -next entry in list
									-prepare next edge entry
								endif
								
							endif
						endif
					else
						if(object is valid ) then (yes)
						 -break condition for while loop
					   else
						   -found insertion point for new entry
						   -insert second point of object
					   endif
					endif
				repeat while(until List insert ptr is not null)
			endif
	    else
			if(ListInsertPtr still stands at list entry wider than new edge) then (true)
				-do nothing
			elseif(next pointer is null)
				-refill DistTrajToObjEdge of new previous with actual DistTrajToObjEdge
				- the found entry was last in list so directly insert second point after that entry
				- prepare next edge entry
			else
				- new entry was not last in list, so look for position to insert second edge of entry
				repeat 
					if(LengthTrajEgoFrontToObj is less than sum of ObjDistOnTraj and CalculatedObjLength)then (yes)
						if(DistTrajToObjEdge is less than or equal to DistTrajToObjEdge)
							-this point is nearer but narrower than actual entry, so keep it
							-next entry in list
						else
							if(entry is nearer and wider than new entry) then (yes)
								-This point once was endpoint of an object, narrower than actual, so keep it and just give it new ObjID and DistTrajToObjEdge data
							    -next entry in list
							else
								if(point wider than actual entry ) then (yes)
									-delete it from list
									-next entry in list
								else
									-insert second point of object 
								    -next entry in list
									-prepare next edge entry
								endif
							endif
						endif
						
					else
						if(DistTrajToObjEdge is less than DistTrajToObjEdge) then (yes)
							- do not insert entry, because t is wider than already saved point and break loop
						else
							-insert second point of object
						    -break condition for while loop
							-prepare next edge entry	
						endif
					endif
				repeat while(new entry was not null)
			endif
			
		endif
		
		
	endif
end
}
@enduml

  @return          -

  @param[in]       t_LAPathOccupation : Occupancy list to be filled.  Array of SIT_t_PathOccupation which if of size SIT_PATH_OCC_ENTRIES.
                      t_LAPathOccupation[i].LengthTrajEgoFrontToObj : Distance b/w Ego front to the object [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                      t_LAPathOccupation[i].DistTrajToObjEdge : Distance from trajectory to object edge    [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      t_LAPathOccupation[i].ObjID : Object id                                              [-1 ... EM_N_OBJECTS-1]
                      t_LAPathOccupation[i].prev : Address to the SIT_t_PathOccupation type of data          [ SIT_t_PathOccupationArray defined in si.h ]
                      t_LAPathOccupation[i].next : Address to the SIT_t_PathOccupation type of data          [ SIT_t_PathOccupationArray defined in si.h ]

  @param[in,out]    pui_ActualEntry : Actual entry in occupancy list                                        [-1 ... EM_N_OBJECTS-1]
  @param[in,out]    pui_NextFree : Next free entry in the list                                              [-1 ... EM_N_OBJECTS-1]
  
  @param[in]       pt_LAPathOccInsertObjDataPtr : Pointer to SIT_t_PathOccInsertObjData, Information about the object/obstacle to be inserted
                      pt_LAPathOccInsertObjDataPtr->ObjDistOnTraj : Measured distance to trajectory                                                [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      pt_LAPathOccInsertObjDataPtr->DistTrajToObjEdge : Distance from EGO center of gravity to trajectory object reference point   [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      pt_LAPathOccInsertObjDataPtr->ObjID : Object ID                                                                              [-1 ... EM_N_OBJECTS-1]
                      pt_LAPathOccInsertObjDataPtr->CalculatedObjLength : Calculated object lenght                                                 [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                      pt_LAPathOccInsertObjDataPtr->HalbeSpurbreite : Path width                                                                   [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   LA_CFG_BLOCKED_OBSTACLE_EXTENSION : As defined in la_cfg.h. Configuration switch enabling the trace bracket extension for the blocked 
                   path between an object and an obstacle. This will be usable only if FCT_CFG_COURSE_PREDICTION is ON.
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         3/7/2016

  @author          Marie-Theres Boll| Marie-Theres Boll@continental-corporation.com | 
*************************************************************************************************************************/
static void LA_v_InsertObjInPathOcc(
                                 uint32 * pui_ActualEntry, uint32 * pui_NextFree, 
                                 const SIT_t_PathOccInsertObjData * pt_LAPathOccInsertObjDataPtr)
{
  SIT_t_PathOccupation * pt_List_insert_ptr = NULL;
  SIT_t_PathOccupation * pt_last_deleted = NULL;
  boolean b_ACCobstacleQuality;
  boolean b_ObjIsMovingToStationary;
  boolean b_ObjDynamicProperty;
  uint8 u_AccQuality;
  
   /* last entry at this side nearer than new entry ? */
  if(pt_LAOutput->a_PathOccObj2Obstacle[*pui_ActualEntry].LengthTrajEgoFrontToObj < pt_LAPathOccInsertObjDataPtr->ObjDistOnTraj)
  {
    /* this is the simple case: add new edge at the end of the list */
    /* insert first point of object */
    pt_LAOutput->a_PathOccObj2Obstacle[*pui_ActualEntry].next                  = &(pt_LAOutput->a_PathOccObj2Obstacle[*pui_NextFree]);
    pt_LAOutput->a_PathOccObj2Obstacle[*pui_NextFree].prev                     = &(pt_LAOutput->a_PathOccObj2Obstacle[*pui_ActualEntry]);
    pt_LAOutput->a_PathOccObj2Obstacle[*pui_NextFree].LengthTrajEgoFrontToObj  = pt_LAPathOccInsertObjDataPtr->ObjDistOnTraj;
    pt_LAOutput->a_PathOccObj2Obstacle[*pui_NextFree].DistTrajToObjEdge        = pt_LAPathOccInsertObjDataPtr->DistTrajToObjEdge;
    pt_LAOutput->a_PathOccObj2Obstacle[*pui_NextFree].ObjID                    = pt_LAPathOccInsertObjDataPtr->ObjID;
    
    /* prepare second point entry */
    *pui_ActualEntry = *pui_NextFree;
    (*pui_NextFree)++;

    /* insert second point of object (object length)*/
    pt_LAOutput->a_PathOccObj2Obstacle[*pui_ActualEntry].next            = &(pt_LAOutput->a_PathOccObj2Obstacle[*pui_NextFree]);
    pt_LAOutput->a_PathOccObj2Obstacle[*pui_NextFree].prev           = &(pt_LAOutput->a_PathOccObj2Obstacle[*pui_ActualEntry]);
    pt_LAOutput->a_PathOccObj2Obstacle[*pui_NextFree].LengthTrajEgoFrontToObj = pt_LAPathOccInsertObjDataPtr->ObjDistOnTraj 
                                                    + pt_LAPathOccInsertObjDataPtr->CalculatedObjLength;
    pt_LAOutput->a_PathOccObj2Obstacle[*pui_NextFree].DistTrajToObjEdge         = pt_LAPathOccInsertObjDataPtr->HalbeSpurbreite;
    pt_LAOutput->a_PathOccObj2Obstacle[*pui_NextFree].ObjID              = OBJ_INDEX_NO_OBJECT;
    pt_LAOutput->a_PathOccObj2Obstacle[*pui_NextFree].next           = NULL;

    /* prepare next edge entry */
    *pui_ActualEntry = *pui_NextFree;
    (*pui_NextFree)++;
  }/* end simple case */
  else
  {
    /* now it gets complex: the new entry must be inserted between the previous found entries*/
    /* first look for distance to insert new edge */
    pt_List_insert_ptr = &pt_LAOutput->a_PathOccObj2Obstacle[*pui_ActualEntry];
    while((pt_List_insert_ptr->LengthTrajEgoFrontToObj > pt_LAPathOccInsertObjDataPtr->ObjDistOnTraj)
        &&(pt_List_insert_ptr->prev != NULL))
    {
      pt_List_insert_ptr = pt_List_insert_ptr->prev;
    }
    
    /* ListInsertPtr now stands at list entry nearer than new edge */
    /* now look for path wider than new entry */
    while( (pt_List_insert_ptr->DistTrajToObjEdge < pt_LAPathOccInsertObjDataPtr->DistTrajToObjEdge) &&
      (pt_List_insert_ptr->next != NULL)  
      )
    {
      if ((pt_List_insert_ptr->ObjID != OBJ_INDEX_NO_OBJECT))
      {
        b_ObjIsMovingToStationary = ((SLATE_b_GetObjIsMovingToStationary(pt_List_insert_ptr->ObjID))== FALSE);
#if (FCT_CFG_SENSOR_TYPE_RADAR)
        b_ObjDynamicProperty = (*SLATE_pt_GetObjDynProperty(pt_List_insert_ptr->ObjID) == SLATE_OBJECT_PROPERTY_STATIONARY);
#else /* !FCT_CFG_SENSOR_TYPE_RADAR */
        b_ObjDynamicProperty = ( (*SLATE_pt_GetObjDynProperty(pt_List_insert_ptr->ObjID) == SLATE_OBJECT_PROPERTY_STATIONARY) 
                              || (*SLATE_pt_GetObjDynProperty(pt_List_insert_ptr->ObjID) == SLATE_OBJECT_PROPERTY_STOPPED) );
#endif /* !FCT_CFG_SENSOR_TYPE_RADAR */

        b_ACCobstacleQuality = !((SLATE_u_GetAccQuality(pt_List_insert_ptr->ObjID) == FUN_PRESEL_ACC_STAT_OBSTACLE) &&
          (b_ObjDynamicProperty != FALSE) && 
          (b_ObjIsMovingToStationary != FALSE));
      }
      else
      {
        b_ACCobstacleQuality = TRUE;
      }

      if ((b_ACCobstacleQuality != FALSE) || 
        (pt_LAOutput->LABasePreselObjList[pt_LAPathOccInsertObjDataPtr->ObjID] == FALSE))
      {
        pt_List_insert_ptr = pt_List_insert_ptr->next;
      }
      else
      {
        break;
      }
    }

    if ((pt_List_insert_ptr->ObjID != OBJ_INDEX_NO_OBJECT))
    {
      b_ObjIsMovingToStationary = ((SLATE_b_GetObjIsMovingToStationary(pt_List_insert_ptr->ObjID))== FALSE);
#if (FCT_CFG_SENSOR_TYPE_RADAR)
      b_ObjDynamicProperty = (*SLATE_pt_GetObjDynProperty(pt_List_insert_ptr->ObjID) == SLATE_OBJECT_PROPERTY_STATIONARY);
#else /* !FCT_CFG_SENSOR_TYPE_RADAR */
      b_ObjDynamicProperty = ( (*SLATE_pt_GetObjDynProperty(pt_List_insert_ptr->ObjID) == SLATE_OBJECT_PROPERTY_STATIONARY) 
                            || (*SLATE_pt_GetObjDynProperty(pt_List_insert_ptr->ObjID) == SLATE_OBJECT_PROPERTY_STOPPED) );
#endif /* !FCT_CFG_SENSOR_TYPE_RADAR */
      u_AccQuality = SLATE_u_GetAccQuality(pt_List_insert_ptr->ObjID);
    }
    else
    {
      b_ObjIsMovingToStationary = FALSE;
      b_ObjDynamicProperty = FALSE;
      u_AccQuality = FUN_PRESEL_ACC_DROP_QUAL;
    } 
    /* ListInsertPtr now stands at list entry wider than new edge */
    /* if new edge is farer away than this entry insert new edge as follower of ListInsertPtr*/
    if( (pt_LAPathOccInsertObjDataPtr->ObjDistOnTraj > pt_List_insert_ptr->LengthTrajEgoFrontToObj) ||
        ( (pt_LAOutput->LABasePreselObjList[pt_LAPathOccInsertObjDataPtr->ObjID] == TRUE) && 
          ((b_ObjDynamicProperty != FALSE) && (b_ObjIsMovingToStationary != FALSE) && 
           (pt_List_insert_ptr->ObjID != OBJ_INDEX_NO_OBJECT) &&
           (u_AccQuality == FUN_PRESEL_ACC_STAT_OBSTACLE)
          )
        )
      )
    {
      pt_LAOutput->a_PathOccObj2Obstacle[*pui_NextFree].LengthTrajEgoFrontToObj    = pt_LAPathOccInsertObjDataPtr->ObjDistOnTraj;
      pt_LAOutput->a_PathOccObj2Obstacle[*pui_NextFree].DistTrajToObjEdge  = pt_LAPathOccInsertObjDataPtr->DistTrajToObjEdge;
      pt_LAOutput->a_PathOccObj2Obstacle[*pui_NextFree].ObjID              = pt_LAPathOccInsertObjDataPtr->ObjID;
      pt_LAOutput->a_PathOccObj2Obstacle[*pui_NextFree].prev               = pt_List_insert_ptr;
      pt_LAOutput->a_PathOccObj2Obstacle[*pui_NextFree].next               = pt_List_insert_ptr->next;
      pt_List_insert_ptr->next                         = &(pt_LAOutput->a_PathOccObj2Obstacle[*pui_NextFree]);
                      
      if(pt_LAOutput->a_PathOccObj2Obstacle[*pui_NextFree].next == NULL)
      {
        /* new entry is last in list, so directly insert second point */
        *pui_ActualEntry = *pui_NextFree;
        (*pui_NextFree)++;
        /* insert second point of object (object length)*/
        pt_LAOutput->a_PathOccObj2Obstacle[*pui_ActualEntry].next            = &(pt_LAOutput->a_PathOccObj2Obstacle[*pui_NextFree]);
        pt_LAOutput->a_PathOccObj2Obstacle[*pui_NextFree].prev       = &(pt_LAOutput->a_PathOccObj2Obstacle[*pui_ActualEntry]);
        pt_LAOutput->a_PathOccObj2Obstacle[*pui_NextFree].LengthTrajEgoFrontToObj = pt_LAPathOccInsertObjDataPtr->ObjDistOnTraj 
                                                        + pt_LAPathOccInsertObjDataPtr->CalculatedObjLength;
        pt_LAOutput->a_PathOccObj2Obstacle[*pui_NextFree].DistTrajToObjEdge         = pt_LAPathOccInsertObjDataPtr->HalbeSpurbreite;
        pt_LAOutput->a_PathOccObj2Obstacle[*pui_NextFree].ObjID              = pt_LAPathOccInsertObjDataPtr->ObjID;
        pt_LAOutput->a_PathOccObj2Obstacle[*pui_NextFree].next           = NULL;

        /* prepare next edge entry */
        *pui_ActualEntry = *pui_NextFree;
        (*pui_NextFree)++;
      }
      else
      {
        /* new entry was not last in list, so look for position to insert second edge of entry */
        pt_LAOutput->a_PathOccObj2Obstacle[*pui_NextFree].next->prev = &(pt_LAOutput->a_PathOccObj2Obstacle[*pui_NextFree]);
        pt_List_insert_ptr = pt_LAOutput->a_PathOccObj2Obstacle[*pui_NextFree].next;
        
        while((pt_List_insert_ptr != NULL))
        {        
          if (pt_List_insert_ptr->LengthTrajEgoFrontToObj < (pt_LAPathOccInsertObjDataPtr->ObjDistOnTraj 
                                                        + pt_LAPathOccInsertObjDataPtr->CalculatedObjLength ) )
          {
            if ((pt_List_insert_ptr->ObjID != OBJ_INDEX_NO_OBJECT))
            {
              b_ObjIsMovingToStationary = ((SLATE_b_GetObjIsMovingToStationary(pt_List_insert_ptr->ObjID))== FALSE);
#if (FCT_CFG_SENSOR_TYPE_RADAR)
              b_ObjDynamicProperty = (*SLATE_pt_GetObjDynProperty(pt_List_insert_ptr->ObjID) == SLATE_OBJECT_PROPERTY_STATIONARY);
#else /* !FCT_CFG_SENSOR_TYPE_RADAR */
              b_ObjDynamicProperty = ( (*SLATE_pt_GetObjDynProperty(pt_List_insert_ptr->ObjID) == SLATE_OBJECT_PROPERTY_STATIONARY) 
                                    || (*SLATE_pt_GetObjDynProperty(pt_List_insert_ptr->ObjID) == SLATE_OBJECT_PROPERTY_STOPPED) );
#endif /* !FCT_CFG_SENSOR_TYPE_RADAR */

              b_ACCobstacleQuality = !((SLATE_u_GetAccQuality(pt_List_insert_ptr->ObjID) == FUN_PRESEL_ACC_STAT_OBSTACLE) && 
                (b_ObjDynamicProperty != FALSE) && 
                (b_ObjIsMovingToStationary != FALSE));
            }
            else
            {
              b_ACCobstacleQuality = TRUE;
            }

            if( (pt_List_insert_ptr->DistTrajToObjEdge <= pt_LAPathOccInsertObjDataPtr->DistTrajToObjEdge) &&
                ( (pt_LAOutput->LABasePreselObjList[pt_LAPathOccInsertObjDataPtr->ObjID] == FALSE) || 
                  (b_ACCobstacleQuality != FALSE) )
                )
            {
              /* this point is nearer but narrower than actual entry, so keep it */

              /* next entry in list */
              pt_List_insert_ptr = pt_List_insert_ptr->next;
              
              /* do not forget to increment Pointer to next free space in SiPathOccupation */
              if(pt_List_insert_ptr == NULL)
              {
                (*pui_NextFree)++;
              }
            }
            else
            {
              /* this entry is nearer and wider than new entry */
             if( (pt_List_insert_ptr->prev->DistTrajToObjEdge < pt_LAPathOccInsertObjDataPtr->DistTrajToObjEdge) &&
                  ( (pt_LAOutput->LABasePreselObjList[pt_LAPathOccInsertObjDataPtr->ObjID] == FALSE) ||
                     (b_ACCobstacleQuality != FALSE)))
             {
                /*This point once was endpoint of an object, narrower than actual, so keep it and
                just give it new ObjID and DistTrajToObjEdge data */
                pt_List_insert_ptr->ObjID = pt_LAPathOccInsertObjDataPtr->ObjID;
                pt_List_insert_ptr->DistTrajToObjEdge = pt_LAPathOccInsertObjDataPtr->DistTrajToObjEdge;
                
                /* next entry in list */
                pt_List_insert_ptr = pt_List_insert_ptr->next;

                /* do not forget to increment Pointer to next free space in SiPathOccupation */
                if(pt_List_insert_ptr == NULL)
                { /* PRQA S 715 */
                  /* date: 2015-08-19, reviewer: Rachit Sharma (uidr5426), reason: Nested control structures exceeds 15, not safety critical */
                  (*pui_NextFree)++;
                }
             }
              else
              {
                /* seems to be a point wider than actual entry so delete it from list (open chain)*/
                if(pt_List_insert_ptr->next != NULL)
                { /* PRQA S 715 */
                  /* date: 2015-08-19, reviewer: Rachit Sharma (uidr5426), reason: Nested control structures exceeds 15, not safety critical */
                  pt_LAOutput->a_PathOccObj2Obstacle[*pui_NextFree].next = pt_List_insert_ptr->next;
                  pt_List_insert_ptr->next->prev     = &(pt_LAOutput->a_PathOccObj2Obstacle[*pui_NextFree]);
                  
                  pt_last_deleted = pt_List_insert_ptr;
                  
                  /* next entry in list */
                  pt_List_insert_ptr = pt_List_insert_ptr->next;
                }
                else
                { /* PRQA S 715 */
                  /* date: 2015-08-19, reviewer: Rachit Sharma (uidr5426), reason: Nested control structures exceeds 15, not safety critical */
                  (*pui_NextFree)++;
                  /* insert second point of object (object length)*/
                  pt_LAOutput->a_PathOccObj2Obstacle[*pui_ActualEntry].prev->next            = &(pt_LAOutput->a_PathOccObj2Obstacle[*pui_NextFree]);
                  pt_LAOutput->a_PathOccObj2Obstacle[*pui_NextFree].prev                     = pt_LAOutput->a_PathOccObj2Obstacle[*pui_ActualEntry].prev;
                  pt_LAOutput->a_PathOccObj2Obstacle[*pui_NextFree].LengthTrajEgoFrontToObj  = pt_LAPathOccInsertObjDataPtr->ObjDistOnTraj 
                                                                        + pt_LAPathOccInsertObjDataPtr->CalculatedObjLength;
                  pt_LAOutput->a_PathOccObj2Obstacle[*pui_NextFree].DistTrajToObjEdge        = pt_LAPathOccInsertObjDataPtr->HalbeSpurbreite;
                  pt_LAOutput->a_PathOccObj2Obstacle[*pui_NextFree].ObjID                    = OBJ_INDEX_NO_OBJECT;
                  pt_LAOutput->a_PathOccObj2Obstacle[*pui_NextFree].next                     = NULL;

                  /* next entry in list */
                  pt_List_insert_ptr = NULL;

                  /* prepare next edge entry */
                  *pui_ActualEntry = *pui_NextFree;
                  (*pui_NextFree)++;
                }
              }
            }
          }
          else
          {
            if ((pt_List_insert_ptr->ObjID != OBJ_INDEX_NO_OBJECT))
            {
              b_ObjIsMovingToStationary = ((SLATE_b_GetObjIsMovingToStationary(pt_List_insert_ptr->ObjID))== FALSE);
#if (FCT_CFG_SENSOR_TYPE_RADAR)
              b_ObjDynamicProperty = (*SLATE_pt_GetObjDynProperty(pt_List_insert_ptr->ObjID) == SLATE_OBJECT_PROPERTY_STATIONARY);
#else /* !FCT_CFG_SENSOR_TYPE_RADAR */
              b_ObjDynamicProperty = ( (*SLATE_pt_GetObjDynProperty(pt_List_insert_ptr->ObjID) == SLATE_OBJECT_PROPERTY_STATIONARY) 
                                    || (*SLATE_pt_GetObjDynProperty(pt_List_insert_ptr->ObjID) == SLATE_OBJECT_PROPERTY_STOPPED) );
#endif /* !FCT_CFG_SENSOR_TYPE_RADAR */

              b_ACCobstacleQuality = !((SLATE_u_GetAccQuality(pt_List_insert_ptr->ObjID) == FUN_PRESEL_ACC_STAT_OBSTACLE) && 
                (b_ObjDynamicProperty != FALSE) &&
                (b_ObjIsMovingToStationary != FALSE));
            }
            else
            {
                  b_ACCobstacleQuality = TRUE;
            }

            if( (pt_List_insert_ptr->prev->DistTrajToObjEdge < pt_LAPathOccInsertObjDataPtr->DistTrajToObjEdge) &&
                ( (pt_LAOutput->LABasePreselObjList[pt_LAPathOccInsertObjDataPtr->ObjID] == FALSE) ||
                  (b_ACCobstacleQuality != FALSE))
              )
            {
              /* do not insert entry, because t is wider than already saved point */
              /* break condition for while loop */
              pt_List_insert_ptr = NULL;
              (*pui_NextFree)++;
            }
            else
            {
              /*found insertion point for new entry */
              (*pui_NextFree)++;
              /* insert second point of object (object length)*/
              pt_List_insert_ptr->prev->next                         = &(pt_LAOutput->a_PathOccObj2Obstacle[*pui_NextFree]);
              pt_LAOutput->a_PathOccObj2Obstacle[*pui_NextFree].prev                     = pt_List_insert_ptr->prev;
              pt_LAOutput->a_PathOccObj2Obstacle[*pui_NextFree].LengthTrajEgoFrontToObj  = pt_LAPathOccInsertObjDataPtr->ObjDistOnTraj 
                                                                    + pt_LAPathOccInsertObjDataPtr->CalculatedObjLength;
              if(pt_last_deleted != NULL)
              {
                pt_LAOutput->a_PathOccObj2Obstacle[*pui_NextFree].DistTrajToObjEdge      = pt_last_deleted->DistTrajToObjEdge;
                pt_LAOutput->a_PathOccObj2Obstacle[*pui_NextFree].ObjID                  = pt_last_deleted->ObjID ;
              }
              else
              {
                pt_LAOutput->a_PathOccObj2Obstacle[*pui_NextFree].DistTrajToObjEdge      = pt_LAPathOccInsertObjDataPtr->HalbeSpurbreite;
                pt_LAOutput->a_PathOccObj2Obstacle[*pui_NextFree].ObjID                  = OBJ_INDEX_NO_OBJECT;
              }
              pt_LAOutput->a_PathOccObj2Obstacle[*pui_NextFree].next                     = pt_List_insert_ptr;
              pt_List_insert_ptr->prev                               = &pt_LAOutput->a_PathOccObj2Obstacle[*pui_NextFree];

              /* break condition for while loop */
              pt_List_insert_ptr = NULL;

              /* prepare next edge entry */
              (*pui_NextFree)++;
            }
          }
        }
      }
    }
    else
    {
      /* new entry is nearer than found wider edge --> do not save first point of object !!*/
      /* ListInsertPtr still stands at list entry wider than new edge */
      if(pt_List_insert_ptr->LengthTrajEgoFrontToObj > ( pt_LAPathOccInsertObjDataPtr->ObjDistOnTraj 
                                                    + pt_LAPathOccInsertObjDataPtr->CalculatedObjLength) )
      {
        /* second edge of object is even nearer than found wider edge so even do not save that point */
      }
      else if(pt_List_insert_ptr->next == NULL)
      {
        /* refill DistTrajToObjEdge of new previous with actual DistTrajToObjEdge */
        pt_List_insert_ptr->DistTrajToObjEdge = pt_LAPathOccInsertObjDataPtr->DistTrajToObjEdge;
        
        /* the found entry was last in list so directly insert second point after that entry*/
        pt_List_insert_ptr->next                               = &(pt_LAOutput->a_PathOccObj2Obstacle[*pui_NextFree]);
        pt_LAOutput->a_PathOccObj2Obstacle[*pui_NextFree].prev                     = pt_List_insert_ptr;
        pt_LAOutput->a_PathOccObj2Obstacle[*pui_NextFree].LengthTrajEgoFrontToObj  = pt_LAPathOccInsertObjDataPtr->ObjDistOnTraj 
                                                              + pt_LAPathOccInsertObjDataPtr->CalculatedObjLength;
        pt_LAOutput->a_PathOccObj2Obstacle[*pui_NextFree].DistTrajToObjEdge        = pt_LAPathOccInsertObjDataPtr->HalbeSpurbreite;
        pt_LAOutput->a_PathOccObj2Obstacle[*pui_NextFree].ObjID                    = pt_LAPathOccInsertObjDataPtr->ObjID;
        pt_LAOutput->a_PathOccObj2Obstacle[*pui_NextFree].next                     = NULL;

        /* prepare next edge entry */
        *pui_ActualEntry = *pui_NextFree;
        (*pui_NextFree)++;
      }
      else
      {
        /* new entry was not last in list, so look for position to insert second edge of entry */
        pt_List_insert_ptr = pt_List_insert_ptr->next;
        
        while((pt_List_insert_ptr != NULL))
        {
          if (pt_List_insert_ptr->LengthTrajEgoFrontToObj < (pt_LAPathOccInsertObjDataPtr->ObjDistOnTraj 
                                                        + pt_LAPathOccInsertObjDataPtr->CalculatedObjLength ) )
          {
            if(pt_List_insert_ptr->DistTrajToObjEdge <= pt_LAPathOccInsertObjDataPtr->DistTrajToObjEdge)
            {
              /* this point is nearer but narrower than actual entry, so keep it */

              /* next entry in list */
              pt_List_insert_ptr = pt_List_insert_ptr->next;
            }
            else
            {
              /* this entry is nearer and wider than new entry */
              if(pt_List_insert_ptr->prev->DistTrajToObjEdge < pt_LAPathOccInsertObjDataPtr->DistTrajToObjEdge)
              {
                /*This point once was endpoint of an object, narrower than actual, so keep it and
                just give it new ObjID and DistTrajToObjEdge data */
                pt_List_insert_ptr->ObjID = pt_LAPathOccInsertObjDataPtr->ObjID;
                pt_List_insert_ptr->DistTrajToObjEdge = pt_LAPathOccInsertObjDataPtr->DistTrajToObjEdge;
                
                /* next entry in list */
                pt_List_insert_ptr = pt_List_insert_ptr->next;
              }
              else
              {
                /* seems to be a point wider than actual entry so delete it from list (open chain)*/
                if(pt_List_insert_ptr->next != NULL) /* PRQA S 715 */
                                                     /* date: 2015-08-19, reviewer: Rachit Sharma (uidr5426), reason: Nested control structures exceeds 15, not safety critical */
                {
                  pt_List_insert_ptr->next->prev     = pt_List_insert_ptr->prev;
                  pt_List_insert_ptr->prev->next     = pt_List_insert_ptr->next;
                                              
                  pt_last_deleted = pt_List_insert_ptr;
                  /* next entry in list */
                  pt_List_insert_ptr = pt_List_insert_ptr->next;
                }
                else
                {
                  /* insert second point of object (object length)*/
                  pt_LAOutput->a_PathOccObj2Obstacle[*pui_ActualEntry].prev->next            = &(pt_LAOutput->a_PathOccObj2Obstacle[*pui_NextFree]);
                  pt_LAOutput->a_PathOccObj2Obstacle[*pui_NextFree].prev                     = pt_LAOutput->a_PathOccObj2Obstacle[*pui_ActualEntry].prev;
                  pt_LAOutput->a_PathOccObj2Obstacle[*pui_NextFree].prev->DistTrajToObjEdge  = pt_LAPathOccInsertObjDataPtr->DistTrajToObjEdge;
                  pt_LAOutput->a_PathOccObj2Obstacle[*pui_NextFree].LengthTrajEgoFrontToObj  = pt_LAPathOccInsertObjDataPtr->ObjDistOnTraj 
                                                                        + pt_LAPathOccInsertObjDataPtr->CalculatedObjLength;
                  pt_LAOutput->a_PathOccObj2Obstacle[*pui_NextFree].DistTrajToObjEdge        = pt_LAPathOccInsertObjDataPtr->HalbeSpurbreite;
                  pt_LAOutput->a_PathOccObj2Obstacle[*pui_NextFree].ObjID                    = OBJ_INDEX_NO_OBJECT;
                  pt_LAOutput->a_PathOccObj2Obstacle[*pui_NextFree].next                     = NULL;

                  /* next entry in list */
                  pt_List_insert_ptr = NULL;

                  /* prepare next edge entry */
                  *pui_ActualEntry = *pui_NextFree;
                  (*pui_NextFree)++;
                }
              }
            }
          }
          else
          {
            if(pt_List_insert_ptr->prev->DistTrajToObjEdge < pt_LAPathOccInsertObjDataPtr->DistTrajToObjEdge)
            {
              /* do not insert entry, because t is wider than already saved point */
              /* break condition for while loop */
              pt_List_insert_ptr = NULL;
            }
            else
            {
              /* insert second point of object (object length)*/
              pt_List_insert_ptr->prev->next                          = &(pt_LAOutput->a_PathOccObj2Obstacle[*pui_NextFree]);
              pt_LAOutput->a_PathOccObj2Obstacle[*pui_NextFree].prev                     = pt_List_insert_ptr->prev;
              pt_LAOutput->a_PathOccObj2Obstacle[*pui_NextFree].prev->DistTrajToObjEdge  = pt_LAPathOccInsertObjDataPtr->DistTrajToObjEdge;
              pt_LAOutput->a_PathOccObj2Obstacle[*pui_NextFree].LengthTrajEgoFrontToObj  = pt_LAPathOccInsertObjDataPtr->ObjDistOnTraj 
                                                                    + pt_LAPathOccInsertObjDataPtr->CalculatedObjLength;
              if(pt_last_deleted != NULL)
              {
                pt_LAOutput->a_PathOccObj2Obstacle[*pui_NextFree].DistTrajToObjEdge      = pt_last_deleted->DistTrajToObjEdge;
                pt_LAOutput->a_PathOccObj2Obstacle[*pui_NextFree].ObjID                  = pt_last_deleted->ObjID ;
              }
              else
              {
                pt_LAOutput->a_PathOccObj2Obstacle[*pui_NextFree].DistTrajToObjEdge      = pt_LAPathOccInsertObjDataPtr->HalbeSpurbreite;
                pt_LAOutput->a_PathOccObj2Obstacle[*pui_NextFree].ObjID                  = OBJ_INDEX_NO_OBJECT;
              }
              pt_LAOutput->a_PathOccObj2Obstacle[*pui_NextFree].next                     = pt_List_insert_ptr;
              pt_List_insert_ptr->prev                               = &pt_LAOutput->a_PathOccObj2Obstacle[*pui_NextFree];

              /* break condition for while loop */
              pt_List_insert_ptr = NULL;

              /* prepare next edge entry */
              (*pui_NextFree)++;
            }
          }
        }
      }
    }
  }/* end of complex case */
  
}/* PRQA S 7004,7012 */
/* date: 2018-06-13, reviewer: Ravi Kiran Gurrala, reason : Cyclomatic complexity. Not Safety critical*/
#endif

#if (LA_CFG_BLOCKED_OBSTACLE_EXTENSION)
/*************************************************************************************************************************
  Functionname:    LA_v_CalcOccPathWidth                                                                            */ /*!

  @brief           Calculate resulting path widths between an object and an obstacle which form a corridor

  @description     Calculate resulting path widths between an object and an obstacle which form a corridor
                   @startuml
        Partition LA_v_CalcOccPathWidth {
        Start
            Partition #LightBlue **LA_v_InitSiPathOccResult** {
              - initialize result structure
              }
            
            Repeat
            If(there is an object entry on Left side) then (Yes)
               - get object quality if moving object is stationary left  and if object property is stationary
            Else
              -No object entry on left side set "actual left acc quality" to 0
            endif
        	
        	If(there is an object entry on Right side) then (Yes)
               - get object quality if moving object is stationary right and if object property is stationary
            Else
              -No object entry on Right side set "actual Right acc quality" to 0
            endif
        	
        	if(Actual Right object and actual left object is greater than OBJECT INDEX NO OBJECT and 
        	   ACC quality of Left object or right object is equal to FUNCTION PRESEL ACC STAT OBSTACLE)then (yes)
        	  -save object IDs of participating objects	
        	  -save distance from sensor of actual entry point
              -prepare next entry	  
        	endif
        	
        	if(Actual Right object next is valid and Actual Left object next is valid) then (yes)
        	  if(next closest entry point is on left side ) then (yes)
        		 -next entry is left
        	  elseif(next closest entry point is on right)then (yes)
        	     -next entry is right
        	  else
        		 -entry points on both sides are of equal distance, set both of them
                endif
            elseif(Actual Right object next is valid) then (yes)
              -no more entries on left side, so set right entry as next
            elseif(Actual Left object next is valid) then (Yes)	  
        	  -no more entries on right side, so set left entry as next
            else
        	  -no more entries on both sides	
            endif  
        	
            Repeat while(as long as there are entries on any side)
        
        end
        }
        @enduml

  @return          -

  @param[in]       a_LAPathOcc[SIT_PATH_OCC_ENTRIES] :Array of SIT_t_PathOccupation which if of size SIT_PATH_OCC_ENTRIES as defined in si.h
                      a_LAPathOcc[i].LengthTrajEgoFrontToObj : Distance b/w Ego front to the object        [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                      a_LAPathOcc[i].DistTrajToObjEdge : Distance from trajectory to object edge           [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      a_LAPathOcc[i].ObjID : Object id                                                     [-1 ... EM_N_OBJECTS-1]
                      a_LAPathOcc[i].prev : Address to the SIT_t_PathOccupation type of data                 [ SIT_t_PathOccupation as defined in si.h]
  @param[in]       t_LAPathhOccResult : Variable of type SIT_t_PathOccResultArray and describe path width between an object and an obstacle which form a corridor 

  @glob_in         SLATE_u_GetAccQuality(ObjNr) : Macro to access EM-based function pre-selection information (based on GET_EM_OBJ_PUB(iObj) 
                                                    [full range of unsigned char]
  @glob_in         pt_LAOutput->LABasePreselObjList : Array of type BasePreselObjList_t(Boolean) which stores pre-selection decision for one object   [TRUE, FALSE]

  @glob_out        -

  @c_switch_part   -
  @c_switch_full   LA_CFG_BLOCKED_OBSTACLE_EXTENSION : As defined in la_cfg.h. Configuration switch enabling the trace bracket extension for the blocked 
                   path between an object and an obstacle. This will be usable only if FCT_CFG_COURSE_PREDICTION is ON.
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         3/7/2016

  @author          Marie-Theres Boll | Marie-Theres Boll@continental-corporation.com | 
*************************************************************************************************************************/
static void LA_v_CalcOccPathWidth(
  SIT_t_PathOccResultArray t_LAPathhOccResult)
{
  const SIT_t_PathOccupation * pt_ActualR = &(pt_LAOutput->a_PathOccObj2Obstacle[0u]); /* right start point is entry 0 */
  const SIT_t_PathOccupation * pt_ActualL = &(pt_LAOutput->a_PathOccObj2Obstacle[1u]); /* left start point is entry 1 */
  SIT_t_PathOccResult * pt_NextResult = &t_LAPathhOccResult[0u]; /* result structure start point is 0 */
  boolean b_ObjIsMovToStatLeft;
  boolean b_ObjDynPropertyLeft;
  boolean b_ObjIsMovToStatRight;
  boolean b_ObjDynPropertyRight;
  uint8 u_ActualL_AccQual;
  uint8 u_ActualR_AccQual;

  /* initialize result structure */
  LA_v_InitSiPathOccResult(t_LAPathhOccResult, pt_ActualR->DistTrajToObjEdge);

  /* as long as there are entries on any side */
  while( (pt_ActualR != NULL) && (pt_ActualL != NULL) )
  {
    if ( (pt_ActualL->ObjID > OBJ_INDEX_NO_OBJECT))
    {
      b_ObjIsMovToStatLeft = ((SLATE_b_GetObjIsMovingToStationary(pt_ActualL->ObjID))== FALSE);
#if (FCT_CFG_SENSOR_TYPE_RADAR)
      b_ObjDynPropertyLeft = (*SLATE_pt_GetObjDynProperty(pt_ActualL->ObjID) == SLATE_OBJECT_PROPERTY_STATIONARY);
#else /* !FCT_CFG_SENSOR_TYPE_RADAR */
      b_ObjDynPropertyLeft = ( (*SLATE_pt_GetObjDynProperty(pt_ActualL->ObjID) == SLATE_OBJECT_PROPERTY_STATIONARY) 
                            || (*SLATE_pt_GetObjDynProperty(pt_ActualL->ObjID) == SLATE_OBJECT_PROPERTY_STOPPED) );
#endif /* !FCT_CFG_SENSOR_TYPE_RADAR */
      u_ActualL_AccQual = SLATE_u_GetAccQuality(pt_ActualL->ObjID);
    }
    else
    {
      b_ObjIsMovToStatLeft = FALSE;
      b_ObjDynPropertyLeft = FALSE;
      u_ActualL_AccQual = FUN_PRESEL_ACC_DROP_QUAL;
    }


    if ( (pt_ActualR->ObjID > OBJ_INDEX_NO_OBJECT))
    {
      b_ObjIsMovToStatRight = ((SLATE_b_GetObjIsMovingToStationary(pt_ActualR->ObjID))== FALSE);
#if (FCT_CFG_SENSOR_TYPE_RADAR)
      b_ObjDynPropertyRight = (*SLATE_pt_GetObjDynProperty(pt_ActualR->ObjID) == SLATE_OBJECT_PROPERTY_STATIONARY);
#else /* !FCT_CFG_SENSOR_TYPE_RADAR */
      b_ObjDynPropertyRight = ( (*SLATE_pt_GetObjDynProperty(pt_ActualR->ObjID) == SLATE_OBJECT_PROPERTY_STATIONARY) 
                             || (*SLATE_pt_GetObjDynProperty(pt_ActualR->ObjID) == SLATE_OBJECT_PROPERTY_STOPPED) );
#endif /* !FCT_CFG_SENSOR_TYPE_RADAR */
      u_ActualR_AccQual = SLATE_u_GetAccQuality(pt_ActualR->ObjID);
    }
    else
    {
      b_ObjIsMovToStatRight = FALSE;
      b_ObjDynPropertyRight = FALSE;
      u_ActualR_AccQual = FUN_PRESEL_ACC_DROP_QUAL;
    }

    /* Calculate path width at actual entry point */
    if( (pt_ActualR->ObjID > OBJ_INDEX_NO_OBJECT) &&
        (pt_ActualL->ObjID > OBJ_INDEX_NO_OBJECT) &&
        ( ( (pt_LAOutput->LABasePreselObjList[pt_ActualR->ObjID] == TRUE) &&
            (b_ObjDynPropertyLeft != FALSE) && 
            (b_ObjIsMovToStatLeft != FALSE) && 
            (u_ActualL_AccQual == FUN_PRESEL_ACC_STAT_OBSTACLE)
          ) ||
          ( (pt_LAOutput->LABasePreselObjList[pt_ActualL->ObjID] == TRUE) &&
            (b_ObjDynPropertyRight != FALSE) && 
            (b_ObjIsMovToStatRight != FALSE) &&
            (u_ActualR_AccQual == FUN_PRESEL_ACC_STAT_OBSTACLE)
          )
        )
      )
    {
      pt_NextResult->PathWidth = pt_ActualR->DistTrajToObjEdge + pt_ActualL->DistTrajToObjEdge;
      /* save object IDs of participating objects */
      pt_NextResult->ObjIDR = pt_ActualR->ObjID;
      pt_NextResult->ObjIDL = pt_ActualL->ObjID;
      /* save distance from sensor of actual entry point */
      pt_NextResult->LengthTrajEgoFrontToObj = MAX_FLOAT(pt_ActualR->LengthTrajEgoFrontToObj, pt_ActualL->LengthTrajEgoFrontToObj);

      /*prepare next entry*/
      pt_NextResult++; /* PRQA S 489 */
                       /* date: 2015-08-19, reviewer: Rachit Sharma (uidr5426), reason: Application wide deviation to rule agreed upon */
    }
    
    if((pt_ActualR->next!=NULL) && (pt_ActualL->next!= NULL))
    {
      /* Look if next closest entry point is on right or left side */
      if(pt_ActualR->next->LengthTrajEgoFrontToObj > pt_ActualL->next->LengthTrajEgoFrontToObj)
      {
        /* next entry is left */
        pt_ActualL = pt_ActualL->next;
      }
      else if(pt_ActualR->next->LengthTrajEgoFrontToObj < pt_ActualL->next->LengthTrajEgoFrontToObj)
      {
        /* next entry is right */
        pt_ActualR = pt_ActualR->next;
      }
      else
      {
        /* if entry points on both sides are of equal distance, set both of them */
        pt_ActualL = pt_ActualL->next;
        pt_ActualR = pt_ActualR->next;
      }
    }
    else if(pt_ActualR->next!=NULL)
    {
      /* no more entries on left side, so set right entry as next */
      pt_ActualR = pt_ActualR->next;
    }
    else if(pt_ActualL->next!=NULL)
    {
      /* no more entries on right side, so set left entry as next */
      pt_ActualL = pt_ActualL->next;
    }
    else
    {
      /* no more entries on both sides, set both to break while loop */
      pt_ActualL = pt_ActualL->next;
      pt_ActualR = pt_ActualR->next;
    }
  }
}
#endif

#if (LA_CFG_BLOCKED_OBSTACLE_EXTENSION)
/*************************************************************************************************************************
  Functionname:    LA_v_InitSiPathOccResult                                                                         */ /*!

  @brief           Initialization of path widths structure
          
  @description     Initialization of path widths structure.
                   @startuml
                   Partition LA_v_InitSiPathOccResult {
                   Start
                     - Initialization of path widths structure
                   end
                   }
                   @enduml

  @return          static void

  @param[in/out]       t_LAPathhOccResult : Variable of datatype SIT_t_PathOccResultArray and describe path width between an object and an obstacle which form a corridor
                      t_LAPathhOccResult[i].LengthTrajEgoFrontToObj : Longitudnal distance from Ego to Object [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                      t_LAPathhOccResult[i].PathWidth : Width of trace bracket                                [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      t_LAPathhOccResult[i].ObjIDL : object no                                                [-1...39]
                      t_LAPathhOccResult[i].ObjIDR : object no                                                [-1...39]

  @param[in]       f_HalfLaneWidth : half lane width                                                          [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   LA_CFG_BLOCKED_OBSTACLE_EXTENSION : As defined in la_cfg.h. Configuration switch enabling the trace bracket extension for the blocked 
                   path between an object and an obstacle. This will be usable only if FCT_CFG_COURSE_PREDICTION is ON.
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         2/29/2016

  @author          Marie-Theres Boll | Marie-Theres Boll@continental-corporation.com | 
*************************************************************************************************************************/
static void LA_v_InitSiPathOccResult(SIT_t_PathOccResultArray t_LAPathhOccResult, const float32 f_HalfLaneWidth)
{
  uint32 i;
  const float32 f_LaneWidth = 2.f * f_HalfLaneWidth;

  /* Initialize PathWidth with f_LaneWidth*/
  for(i=0u; i<(uint32)SIT_PATH_OCC_ENTRIES;i++)
  {
    t_LAPathhOccResult[i].LengthTrajEgoFrontToObj = LA_SCENE_DEFAULT_DISTTOOBJ;
    t_LAPathhOccResult[i].PathWidth               = f_LaneWidth;
    t_LAPathhOccResult[i].ObjIDL                  = OBJ_INDEX_NO_OBJECT;
    t_LAPathhOccResult[i].ObjIDR                  = OBJ_INDEX_NO_OBJECT;
  }
}
#endif

#if (LA_CFG_BLOCKED_OBSTACLE_EXTENSION)
/*************************************************************************************************************************
  Functionname:    LA_v_CheckForNarrowPath                                                                          */ /*!

  @brief           Check if the corridor between an object and an obstacle can be passed by the ego vehicle.

  @description     Check if the corridor between an object and an obstacle can be passed by the ego vehicle.
                   @startuml
                   Partition LA_v_CheckForNarrowPath {
                   Start
                   	repeat
                   		if(next result "object id left" and "right" are greater than OBJECT INDEX NO OBJECT) then (yes)
                   			if(path width is less than LA SCENE MINIMUM PASSABLE PASS WIDTH) then (yes)
                   				if(check for closer object of right) then (yes)
                   					-report it as narrow object
                   				else
                   					-report it as narrow object
                   				endif
                   				-set Blocked Path Width to next result path width
                   			endif
                   			if(Blocked Near Object is less than 0 and Blocked Path Width is greater than next result path width)then (yes)
                   				-set Blocked Path Width to next result path width
                   			endif
                   		endif
                   	repeat while(next result of "Length Trajectory Ego Front To Object is less than LA SCENE DEFAULT DIST TO OBJ and
                   	             Blocked Near Object is less than 0) theh (yes)
                   end
                   }
                   @enduml

  @return          -

  @param[in]       a_LAPathhOccResult[SIT_PATH_OCC_ENTRIES] : Path occupation result structure of datatype SIT_t_PathOccResult
  @param[in,out]   p_CloseObjId : Pointer to Close object id, value will have range                                          [-1 ... EM_N_OBJECTS-1]
  @param[in,out]   p_FarObjId : Pointer to Far object id, value will have range                                              [-1 ... EM_N_OBJECTS-1]

  @glob_in         *pt_LAInput->t_RTE.pf_ObjLongDisp  (pt_NextResult->ObjIDR) : Macro to get longitudinal distance of given object         [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m

  @glob_out        -

  @c_switch_part   FCT_SIMU : Enable FCT Simulation as defined in fct_config.h

  @c_switch_full   LA_CFG_BLOCKED_OBSTACLE_EXTENSION : As defined in la_cfg.h. Configuration switch enabling the trace bracket extension for the blocked 
                   path between an object and an obstacle. This will be usable only if FCT_CFG_COURSE_PREDICTION is ON.
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         3/4/2016

  @author          Marie-Theres Boll | Marie-Theres Boll@continental-corporation.com | 
*************************************************************************************************************************/
static void LA_v_CheckForNarrowPath(const SIT_t_PathOccResult a_LAPathhOccResult[SIT_PATH_OCC_ENTRIES])
{
  const SIT_t_PathOccResult * pt_NextResult = &a_LAPathhOccResult[0u];
  
  pt_LAOutput->s_BlockedNearObj = OBJ_INDEX_NO_OBJECT;

  /* SiPathhOccResult is sorted by distance to sensor, so first detected blocked path is closest */
  while( (pt_NextResult->LengthTrajEgoFrontToObj < LA_SCENE_DEFAULT_DISTTOOBJ) && (pt_LAOutput->s_BlockedNearObj < 0) )
  {
    if( (pt_NextResult->ObjIDL != OBJ_INDEX_NO_OBJECT) && (pt_NextResult->ObjIDR != OBJ_INDEX_NO_OBJECT) )
    {
      /* path is build up by two objects */
      if(pt_NextResult->PathWidth < LA_SCENE_MIN_PASSABLE_PASS_WIDTH)
      {
        /* check for closer object of both and report it as narrow object*/
        if(*pt_LAInput->t_RTE.pf_ObjLongDisp(pt_NextResult->ObjIDR) < *pt_LAInput->t_RTE.pf_ObjLongDisp(pt_NextResult->ObjIDL))
        {
          pt_LAOutput->s_BlockedNearObj  = pt_NextResult->ObjIDR;
          pt_LAOutput->s_BlockedFartherObj    = pt_NextResult->ObjIDL;
        }
        else
        {
          pt_LAOutput->s_BlockedNearObj  = pt_NextResult->ObjIDL;
          pt_LAOutput->s_BlockedFartherObj    = pt_NextResult->ObjIDR;
        }
#ifdef FCT_SIMU
        pt_LAOutput->f_BlockedPathWidth = pt_NextResult->PathWidth;
#endif
      }
#ifdef FCT_SIMU
      if( (pt_LAOutput->s_BlockedNearObj < 0) && (fABS(f_BlockedPathWidth) > fABS(pt_NextResult->PathWidth)) )
      {
        pt_LAOutput->f_BlockedPathWidth = pt_NextResult->PathWidth;
      }
#endif
    }
    pt_NextResult++; /* PRQA S 489 */
                     /* date: 2015-08-19, reviewer: Rachit Sharma (uidr5426), reason: Application wide deviation to rule agreed upon */
  }
}
#endif

#if (LA_CFG_BLOCKED_OBSTACLE_EXTENSION)
/*************************************************************************************************************************
  Functionname:    LA_v_RelTraExtensionBlockedObstacleCorridor                                                      */ /*!

  @brief           Set the trace brackets based on a blocked path "object to obstacle"

  @description     Set the trace brackets based on a blocked path "object to obstacle". If the object is the "real" object
                   that is selected based on blocked path "object to obstacle".Apply trace bracket extension only for objects 
                   above a longitudinal distance threshold,for objects which are car or truck,if ego speed above a threshold,
                   if curvature below a threshold.
                   @startuml
                   Partition LA_v_RelTraExtensionBlockedObstacleCorridor {
                   Start
                   	if(object longitudinal distance is above longitudinal distance threshold and
                         objects which are car or truck,and 
                         ego speed is above a threshold, and
                         curvature is below a threshold) then (yes)
                   	  -Set only the trace bracket on the trajectory side on which the object is.
                   	  -Ensure that the object is within the trace bracket.
                   	endif
                   end
                   }
                   @enduml

  @return          -

  @param[in]       p_ObjectProperties :  Pointer to datatype LA_t_RelTraObjInput as defined in si_corridor_crit.h
                      p_ObjectProperties->iObjNr : Object no                                        [-1 ... EM_N_OBJECTS-1]
                      p_ObjectProperties->dAblage_m : dAblage_m                                     [Full range of float32]

  @param[in,out]   p_BracketFuncResults : Pointer to datatype LA_t_BracketOutput as defined in si_corridor_crit.h
                      p_BracketFuncResults->BracketPositionRight : Right bracket position           [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      p_BracketFuncResults->BracketPositionLeft :  Left bracket position            [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m

  @glob_in         *pt_LAInput->t_RTE.pf_ObjLongDisp   : Macro to get longitudinal distance of given object       [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
  @glob_in         pt_LAInput->t_RTE.pf_EgoVelObjSync : Ego Speed                                                 [-330.f ... 330.f] m/s
  @glob_in         pt_LAInput->t_RTE.pf_EgoCurve : Curvature                                                   [-1...1] m^-1
  @glob_in         *SLATE_pt_GetObjClassification : Object Classification                                       [EM_t_GenObjClassification defined in Rte_Type.h]
  @glob_in         OBJ_GET_CP : Macro to get distance from trajectory of datatype CPObjDist2Traj_t as defined in cp_ext.h

  @glob_out        -

  @c_switch_part   -
  @c_switch_full   LA_CFG_BLOCKED_OBSTACLE_EXTENSION : Configuration switch enabling the trace bracket extension for the blocked path between an object and an obstacle as defined in la_cfg.h
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         3/7/2016

  @author          Marie-Theres Boll | Marie-Theres Boll@continental-corporation.com | 
*************************************************************************************************************************/
static void LA_v_RelTraExtensionBlockedObstacleCorridor(LA_t_RelTraObjInput const * p_ObjectProperties, LA_t_BracketOutput * p_BracketFuncResults)
{
  float32 f_ObjDistX = *pt_LAInput->t_RTE.pf_ObjLongDisp(p_ObjectProperties->iObjNr);
  float32 f_EgoVelObjSync = *pt_LAInput->t_RTE.pf_EgoVelObjSync;
  float32 f_EgoCurve = *pt_LAInput->t_RTE.pf_EgoCurve;
  SLATE_t_Obj_CLassification t_ObjClassification = *SLATE_pt_GetObjClassification(p_ObjectProperties->iObjNr);
  /* If the object is the "real" object that is selected based on blocked path "object to obstacle".
    Apply trace bracket extension only 
      for objects above a longitudinal distance threshold,
      for objects which are car or truck,
      if ego speed above a threshold,
      if curvature below a threshold
  */
  if( (p_ObjectProperties->iObjNr == t_BlockedObjId) &&
      (f_ObjDistX > LA_SCENE_TB_MIN_DISTX) &&
      (f_EgoVelObjSync > LA_SCENE_TB_MIN_EGO_SPEED) &&
      (fABS(f_EgoCurve) < LA_SCENE_TB_MAX_EGO_CURVE) &&
      ( (t_ObjClassification == SLATE_OBJCLASS_CAR) || 
        (t_ObjClassification == SLATE_OBJCLASS_TRUCK )
      )
    )
  {
    /* Set only the trace bracket on the trajectory side on which the object is. 
      Ensure that the object is within the trace bracket.  */
    if(pt_LAOutput->t_LAObjOutputList[p_ObjectProperties->iObjNr].TrajDist.TrajDistMeas.Y.f0 > 0.f)
    {
      p_BracketFuncResults->BracketPositionLeft = p_ObjectProperties->dAblage_m + 1.f;
    }
    else
    {
      p_BracketFuncResults->BracketPositionRight = p_ObjectProperties->dAblage_m - 1.f;
    }
  }
}
#endif

/*************************************************************************************************************************
  Functionname:    LA_v_RelTraRestrictNeighbourhoodRelObj                                                              */ /*!

  @brief           Restrict track width relative to neighborhood object

  @description     Limit the track width immediately before the relevant Object on a narrower width
                   @startuml
                   Partition LA_v_RelTraRestrictNeighbourhoodRelObj{
                   Start
                   	if(Environment Relevant Obj is not equal to OBJECT INDEX NO OBJECT)then (yes)
                   		if(object is moving and Environment Relevant Object is not equal input object and input object is moving)then (yes)
                   			-set Longitudinal Distance Difference to Environment RelObjDistX minus ObjInput Longitudinal Distance
                   		    if(Longitudinal Distance Difference is greater than C F32 DELTA and 
                   Environment Relevant Object Target Fusion Hold Time is less than or equal to C F32 DELTA) then (yes)
                   			   if(object for which the longitudinal distance is less than the longitudinal distance of the relevant object
                                     or the relevant object was neighboring object during object separation) then (yes)
                   				   -set Lateral Distance Difference to Environment Relevant Object DistY minus ObjInput dAblage_m
                   				   if(Lateral Distance Difference is greater than 0) then (yes)
                   					  -Right boundary,Write trace bracket position
                   				   else
                   					  -Left boundary,Write trace bracket position
                   				   endif
                   			   endif
                   			   
                   			endif
                   		endif
                   	endif
                   end
                   }
                   @enduml

  @return          -

  @param[in]       p_ObjInput : Pointer to datatype LA_t_RelTraObjInput as defined in si_corridor_crit.h
                      p_ObjInput->iObjNr : Object no                                                     [-1 ... EM_N_OBJECTS-1]
                      p_ObjInput->ucDynamicProperty : Relative object dynamic property, This signal indicates wether the 
                        object is moving, stationary or oncoming, based on comparison of the longitudinal relative velocity with 
                        the host vehicle velocity.values: enum { SLATE_OBJECT_PROPERTY_STATIONARY=1,SLATE_OBJECT_PROPERTY_MOVING=0,SLATE_OBJECT_PROPERTY_ONCOMING=2} 
                        [0...2]
                      p_ObjInput->dAbst_mittel : dAbst_mittel                                            [Full range of float32]
                      p_ObjInput->dAblage_m : dAblage_m                                                  [Full range of float32]

  @param[in]       p_Environment :Pointer to datatype LA_t_AssTraEnvironment as defined in si_corridor_crit.h
                      p_Environment->ucRelObjDynamicProperty : Relative object dynamic property, This signal indicates wether the 
                        object is moving, stationary or oncoming, based on comparison of the longitudinal relative velocity with 
                        the host vehicle velocity.values: enum { SLATE_OBJECT_PROPERTY_STATIONARY=1,SLATE_OBJECT_PROPERTY_MOVING=0,SLATE_OBJECT_PROPERTY_ONCOMING=2} 
                                                                                                          [0...2]
                      p_Environment->iRelObjNr : Object no                                                [-1 ... EM_N_OBJECTS-1]
                      p_Environment->fRelObjDistX : Longitudinal distance of object from trajectory       [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                      p_Environment->fRelObjTargetFusionHoldTime : Object Target Fusion hold time         [0...Full range of float32]
                      p_Environment->fRelObjDistY : Lateral distance of object from trajectory          : [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m


  @param[in,out]   p_BracketOut : Pointer to datatype LA_t_BracketOutput as defined in si_corridor_crit.h
                      p_BracketOut->BracketPositionRight : Right bracket position                         [-PI/2*RW_FCT_MAX ... 0] m
                      p_BracketOut->BracketPositionLeft :  Left bracket position                          [0 ... PI/2*RW_FCT_MAX] m

  @glob_in         - *pt_LAInput->t_RTE.pf_ObjLongDisp   : Macro to get longitudinal distance of given object             [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
  @glob_out        -

  @c_switch_part   LA_CFG_EXT_RELEVANT_OBJECT : Configuration switch to enable/disable relevant object extension as defined in la_cfg.h
				   LA_CFG_NEAR_NEIGHBOURHOOD_DIST_REDUCTION : Configuration switch to enable/disable trace bracket restriction according to distance of objects as defined in la_cfg.h
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component
  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         23/10/2010
  @changed         23/10/2010

  @author          R.Ehrhardt | R.Ehrhardt@continental-corporation.com | 
*************************************************************************************************************************/
static void LA_v_RelTraRestrictNeighbourhoodRelObj(LA_t_RelTraObjInput const *p_ObjInput , LA_t_AssTraEnvironment const *p_Environment , LA_t_BracketOutput *p_BracketOut )
{
  /*--- VARIABLES ---*/
  float32 f_LatDistDiff;
  float32 f_LongDistDiff;

#if (LA_CFG_EXT_RELEVANT_OBJECT)
  float32 fABS_pEnvironment_fRelObjTargetFusionHoldTime;
#endif
#if(LA_CFG_NEAR_NEIGHBOURHOOD_DIST_REDUCTION)
  float32 f_AbsLongDistDiff;
  float32 f_AbsDistToTraj;
  const float32 f_ObjLongDisp = (*pt_LAInput->t_RTE.pf_ObjLongDisp(p_ObjInput->iObjNr));
  float32 fDistToTraj = pt_LAOutput->t_LAObjOutputList[p_ObjInput->iObjNr].TrajDist.TrajDistMeas.Y.f0;
#endif/*LA_CFG_NEAR_NEIGHBOURHOOD_DIST_REDUCTION*/

  if( p_Environment->iRelObjNr != OBJ_INDEX_NO_OBJECT )
  {
    if( ( p_Environment->ucRelObjDynamicProperty == SLATE_OBJECT_PROPERTY_MOVING )
      &&( p_Environment->iRelObjNr != p_ObjInput->iObjNr )
      &&( p_ObjInput->ucDynamicProperty == SLATE_OBJECT_PROPERTY_MOVING )
      )
    {
      f_LongDistDiff = p_Environment->fRelObjDistX - p_ObjInput->dAbst_mittel;

      /* Restriction: only for object for which the longitudinal distance is less than the longitudinal distance of the relevant object
         or if the relevant object was neighboring object during object separation (Zielverschmelzer) (if this extension is considered 
         as shown by the config switch) */
#if (LA_CFG_EXT_RELEVANT_OBJECT)
      fABS_pEnvironment_fRelObjTargetFusionHoldTime = fABS(p_Environment->fRelObjTargetFusionHoldTime);
#endif
      if( (f_LongDistDiff > C_F32_DELTA) 
#if (LA_CFG_EXT_RELEVANT_OBJECT)
        || (fABS_pEnvironment_fRelObjTargetFusionHoldTime <= C_F32_DELTA)
#endif
        )
      {
#if(LA_CFG_NEAR_NEIGHBOURHOOD_DIST_REDUCTION)
        f_AbsLongDistDiff = fABS(f_LongDistDiff);
        f_AbsDistToTraj   = fABS(fDistToTraj);
	
        if(((f_ObjLongDisp <= LA_DIST_NEIGHBORHOOD_NEAR_OBJ) && 
		    (f_AbsLongDistDiff <= LA_DIST_DIFF_NEIGHBORHOOD_REL_OBJ) &&
			(f_AbsDistToTraj > LA_TRAJ_DISTANCE_NEAR_OBJ) )
			|| ((f_ObjLongDisp > LA_DIST_NEIGHBORHOOD_NEAR_OBJ) && 
			    (f_AbsLongDistDiff <= LA_DIST_DIFF_NEIGHBORHOOD_REL_OBJ) ))
#else
        float32 f_ABS_LongDistDiff;
        f_ABS_LongDistDiff = fABS(f_LongDistDiff);
        if(f_ABS_LongDistDiff <= LA_DIST_DIFF_NEIGHBORHOOD_REL_OBJ)
#endif/*LA_CFG_NEAR_NEIGHBOURHOOD_DIST_REDUCTION*/
        {
          f_LatDistDiff = p_Environment->fRelObjDistY - p_ObjInput->dAblage_m;

          if( f_LatDistDiff > 0.F )
          {
            /* Right boundary */
            /* Write trace bracket position */
            p_BracketOut->BracketPositionRight = (p_ObjInput->dAblage_Radius - LA_SEEKWIDTH_NEIGHBORHOOD_RELOBJ);

          } else
          {
            /* Left boundary */
            /* Write trace bracket position */
            p_BracketOut->BracketPositionLeft = (p_ObjInput->dAblage_Radius + LA_SEEKWIDTH_NEIGHBORHOOD_RELOBJ);

          }
        }
      }
    }
  }
}

#if (LA_CFG_EXT_NEIGHBORHOOD_REL_OBJ)
/*************************************************************************************************************************
  Functionname:    LA_v_CalcCorrExtendNeighbourhoodRelObj                                                           */ /*!

  @brief           Trace bracket extension for the relevant object in situations with close neighboring objects

  @description     Trace bracket extension for the relevant object in situations in which the neighboring object is close 
                   and the relevant object moves towards the neighboring object. Should only be used if ego lane change 
                   phase are determined based on the camera lane information.
                   @startuml
                   Partition LA_v_CalcCorrExtendNeighbourhoodRelObj{
                   Start
                   	if(current object is the relevant object) then (yes)
                   		if(object is moving and the longitudinal distance of the object is above a threshold 
                   	       and in highway situations and camera detects that no lane change is performed) then (yes)
                   		   -Get Neighborhood Object
                   		   if(Neighborhood Object is not equal to OBJECT INDEX NO OBJECT) then (yes)
                   			   -Get Distance Related To Trajectory
                                  if(Distance Related To Trajectory is less than 0) then (yes)
                   				   -write right bracket position
                   			   elseif(Distance Related To Trajectory is greater than 0) then (yes)
                   			       -write left bracket position
                   		       else
                   				   -do nothing
                   			   endif
                   		   endif
                   		endif	
                   	endif
                   	
                   	if(Nenighborhood Object is not equal to OBJECT INDEX NO OBJECT) then (yes)
                   		-update LA Corridor Neighbour DebugInfo structure
                   	Endif
                              -Freeze the debug info
                   
                   end
                   }
                   @enduml

  @return          -


  @param[in]       p_ObjInput : Pointer to datatype LA_t_RelTraObjInput as defined in si_corridor_crit.h
                      p_ObjInput->iObjNr : Object no                                                     [-1 ... EM_N_OBJECTS-1]
                      p_ObjInput->dAblage_Radius : dAblage_Radius                                        [Full range of float32]

  @param[in]       p_Environment :Pointer to datatype LA_t_AssTraEnvironment as defined in si_corridor_crit.h
                      p_Environment->ucRelObjDynamicProperty : Relative object dynamic property, This signal indicates wether the 
                        object is moving, stationary or oncoming, based on comparison of the longitudinal relative velocity with 
                        the host vehicle velocity.values: enum { SLATE_OBJECT_PROPERTY_STATIONARY=1,SLATE_OBJECT_PROPERTY_MOVING=0,SLATE_OBJECT_PROPERTY_ONCOMING=2} 
                                                                                                          [0...2]
                      p_Environment->iRelObjNr : Object no                                                [-1 ... EM_N_OBJECTS-1]

  @param[in,out]   p_BracketOut : Pointer to datatype LA_t_BracketOutput as defined in si_corridor_crit.h
                      p_BracketOut->BracketPositionRight : Right bracket position                         [-PI/2*RW_FCT_MAX ... 0] m
                      p_BracketOut->BracketPositionLeft :  Left bracket position                          [0 ... PI/2*RW_FCT_MAX] m

  @glob_in         *pt_LAInput->t_RTE.pf_ObjLongDisp   : Macro to get longitudinal distance of given object             [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
  @glob_in         pt_LAInput->pt_FIPRoadType->t_FusedRoadType : Reference to FIP road type [full range of FIP_t_FusedRoadType as in fip_ext.h]
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component

  @c_switch_part   FCT_SIMU : Enable FCT Simulation as defined in fct_config.h
  @c_switch_part   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC
  @c_switch_full     LA_CFG_EXT_NEIGHBORHOOD_REL_OBJ : As defined in la_cfg.h. Configuration switch to enable bracket extension used for situations in 
                     which the relevant object moves in the direction of a near neighboring object. For the relevant object the 
                     brackets are extended. Should only be active if camera lane information is available to detect the ego 
                     lane change phases.

  @pre             SIT_CFG_EXT_NEIGHBOURHOOD_REL_OBJ needs to be activated based on (SIT_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM && \
                   SIT_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM && SIT_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM)

  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         20.07.2015
  @changed         20.07.2015

  @author          Yvonne Strigel | yvonne.strigel@continental-corporation.com | +49 (8382) 9699-696
*************************************************************************************************************************/
static void LA_v_CalcCorrExtendNeighbourhoodRelObj(LA_t_RelTraObjInput const * p_ObjInput , LA_t_AssTraEnvironment const * p_Environment , LA_t_BracketOutput * p_BracketOut )
{
  /*--- VARIABLES ---*/
  ObjNumber_t t_ObjNrNeighborObj = OBJ_INDEX_NO_OBJECT;
  float32 f_DistRelToTraj = 0.f;
  float32 fObjLongDisp;
#if (FCT_CFG_ROAD_INPUT)
#if (FCT_CFG_INPUT_PREPROCESSSING)
  FIP_t_FusedRoadType t_RoadTypeLevel_1 = pt_LAInput->pt_FIPRoadType->t_FIPFusedRoadType;
#else
  FIP_t_FusedRoadType t_RoadTypeLevel_1 = FIP_ROAD_TYPE_UNKNOWN;
#endif /* (FCT_CFG_INPUT_PREPROCESSSING) */
#endif /* FCT_CFG_ROAD_INPUT */
  const LA_t_ScaleBracketState LC_State = pt_LAOutput->f_LA_StateScaleBracket; /* Remark: (SIT_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM &&
                             SIT_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM && SIT_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM) 
                             activated based in dependent switch SIT_CFG_EXT_NEIGHBOURHOOD_REL_OBJ */

#ifdef FCT_SIMU
  LACorrNeighbourDebugInfo.t_ObjPair = OBJ_INDEX_NO_OBJECT;
  LACorrNeighbourDebugInfo.f_DiffDistX = 0.f;
  LACorrNeighbourDebugInfo.f_DiffVelocity = 0.f;
  LACorrNeighbourDebugInfo.t_RefObj = OBJ_INDEX_NO_OBJECT;
  LACorrNeighbourDebugInfo.f_DistRef2Traj = 0.f;
#endif

  /* check if the current object is the relevant object,
  only for moving object,
  only if the longitudinal distance of the object is above a threshold,
  only consider highway situations,
  only if camera detects that no lane change is performed. Otherwise (also if no camera information is available), the extension should NOT be applied. */  
  if(p_Environment->iRelObjNr != OBJ_INDEX_NO_OBJECT)
  {
      fObjLongDisp = *pt_LAInput->t_RTE.pf_ObjLongDisp(p_Environment->iRelObjNr);
	  if( (fObjLongDisp > LA_DIST_MIN_REL_OBJ_NEIGHBORHOOD)
		&& (p_Environment->ucRelObjDynamicProperty == SLATE_OBJECT_PROPERTY_MOVING)
		&& (p_Environment->iRelObjNr == p_ObjInput->iObjNr)
	#if (FCT_CFG_ROAD_INPUT)
		&& (t_RoadTypeLevel_1 == FIP_ROAD_TYPE_HIGHWAY)
	#endif /* FCT_CFG_ROAD_INPUT */
		&& (LC_State == SLATE_NO_LANE_CHANGE)
		)
	  {
		t_ObjNrNeighborObj = pt_LAOutput->t_NearNeighboringObj[p_Environment->iRelObjNr];
    
		if (t_ObjNrNeighborObj != OBJ_INDEX_NO_OBJECT)
		{
		  f_DistRelToTraj = pt_LAOutput->t_LAObjOutputList[p_Environment->iRelObjNr].TrajDist.TrajDistMeas.Y.f0;
      
		  if(f_DistRelToTraj < 0.F)
		  {
			/* right bracket */
			/* write bracket position */
			p_BracketOut->BracketPositionRight = (p_ObjInput->dAblage_Radius - LA_CORR_TRACE_BRACKET_NEIGHBORHOOD);
		  } 
		  else if (f_DistRelToTraj > 0.F)
		  {
			/* left bracket */
			/* write bracket position */
			p_BracketOut->BracketPositionLeft = (p_ObjInput->dAblage_Radius + LA_CORR_TRACE_BRACKET_NEIGHBORHOOD);
		  }
		  else 
		  {
			/* no trace bracket extension set */
		  }
		}
	  }
  }
#ifdef FCT_SIMU
  if(t_ObjNrNeighborObj != OBJ_INDEX_NO_OBJECT)
  {
    LACorrNeighbourDebugInfo.t_ObjPair = t_ObjNrNeighborObj;
    LACorrNeighbourDebugInfo.f_DiffDistX = *pt_LAInput->t_RTE.pf_ObjLongDisp(p_Environment->iRelObjNr) - (*pt_LAInput->t_RTE.pf_ObjLongDisp(t_ObjNrNeighborObj));
    LACorrNeighbourDebugInfo.f_DiffVelocity = *pt_LAInput->t_RTE.pf_ObjVrelX(p_Environment->iRelObjNr) - *pt_LAInput->t_RTE.pf_ObjVrelX(t_ObjNrNeighborObj);
    LACorrNeighbourDebugInfo.t_RefObj = p_Environment->iRelObjNr;
    LACorrNeighbourDebugInfo.f_DistRef2Traj = f_DistRelToTraj;
  }
  /*! Freeze the debug info */
  FCT_FREEZE_DATA(&LACorrNeighbourDebugMeasInfo, &LACorrNeighbourDebugInfo, NULL);
#endif

}
#endif /*(SIT_CFG_EXT_NEIGHBOURHOOD_REL_OBJ)*/


#if (LA_CFG_EXT_NEIGHBORHOOD_REL_OBJ || LA_CFG_ADD_RESTRICTION_OBJ_TRACE)
/*************************************************************************************************************************
  Functionname:    LA_t_FindNearNeighboringObjToEgoLane                                                             */ /*!

  @brief           Search for a near neighboring object for the given object which is on the same side of the ACC-trajectory
                   as the given object. The given object should be on the ego lane.

  @description     Search for a near neighboring object for the given object which is on the same side of the ACC-trajectory
                   as the given object. Usecase: object for which an neighboring object is looked for, should be on the ego lane.
                   
                   restrictions: 
                   neighboring object must have sufficient ACC quality
                   reference object must not be occluded
                   trace for reference object must not have a huge offset to ego-position
                   reference and neighboring object are checked for being object and mirror
                   reference and neighboring object are checked for being two reflections of the same real object
                   reference object and neighboring object must be located on the same side of the ACC trajectory

                   Remark: (LA_CFG_EXT_NEIGHBORHOOD_REL_OBJ || LA_CFG_ADD_RESTRICTION_OBJ_TRACE) to be removed if used in other functions
                   @startuml
                Partition LA_t_FindNearNeighboringObjToEgoLane{
                Start
                	if(target object is occluded)
                		-the risk for drop ins from neighboring lane is high.Therefore, the bracket extension is inactive for occluded objects
                	endif
                	
                	if(trace exists and lateral difference between ego-position and trace is huge)
                		-object is not considered to avoid long drop-ins from neighboring lane
                	endif
                	
                	-Get number of objec in use
                	repeat 
                	   -Get x-distance sorted objects 
                	   if(neighboring objects are moving and objects have sufficient ACC-quality) then (yes)
                		   -calculate longitudinal distances difference to relevant object
                	       -calculate the ACC trajectory distances difference compared to relevant object
                		   if(longitudinal distance and the lateral distance to the relevant object is above a threshold) then (yes)
                			   -Set hint Double Object to true
                		   else
                			   -Set hint Double Object to false
                		   endif
                		   
                		   if(longitudinal distance and the relative velocity difference to the relevant object is above a threshold) then (yes)
                			   -set hint Mirror to true
                		   else
                			   -set hint mirror to false
                		   endif
                		   
                		   if(objects is in direct longitudinal and lateral neighborhood based on position and distance to ACC trajectory and
                             object is not occluded and hint for neighboring lane, hint for second radar object of the same real object, 
                             hint for mirror object are false)then (yes)
                		       if()then (yes)
                				   -both objects are on the right side of the ACC trajectory
                			   elseif(Lateral Distance Differencr is greater than 0 and Distance Related To Trajectory is greater than or equal 0)then (yes)
                			       -both objects are on the left side of the ACC trajectory
                			   else
                				   -Do nothing
                			   endif
                           endif 		   
                	   endif
                	repeat while(for all the objects in use and for Neighbor Object is equal to OBJECT INDEX NO OBJECT)
                end
                }
                @enduml

  @return          static ObjNumber_t : Neighbor Object No                                            [-1 ... EM_N_OBJECTS-1]

  @param[in]       t_ObjNrRel : Input object No                                                       [-1 ... EM_N_OBJECTS-1]

  @glob_in         SLATE_p_GetEMGenObjAttributes(t_ObjNrRel)->eObjectOcclusion : Enum of type EM_t_GenObjOcclusionState as defined in Rte_type.h, 
                                                                 Describes if/how Object is covered by closer objects in sensing direction [0...4] 
                                                                 enum { EM_GEN_OBJECT_OCCL_PARTLY=2,EM_GEN_OBJECT_OCCL_FULL=3,EM_GEN_OBJECT_OCCL_NONE=0,EM_GEN_OBJECT_OCCL_MAX_DIFF_TYPES=4,EM_GEN_OBJECT_OCCL_UNKNOWN=1,}
  @glob_in         pt_LAInput->t_SIT.pt_ObjBool(t_ObjNrRel)->OccludedByTrace : Of data type ubit32_t, Bit which denotes if Object is marked as occluded by trace analysis [0...1]
  @glob_in         OBJ_GET_TRACE_ID(t_ObjNrRel) : Get the trace id of the given trace [0...10]
  @glob_in         pt_LAInput->t_FIPMOT.pt_FIPMovObjStaticTrace(t_ObjTraceNr)->fYIntersection : Get y intersection of given trace                              [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @glob_in         SLATE_t_GetNumOfObjectsUsed() : Macro to access number of objects (based on GET_EM_PUB_OBJ_DATA_PTR)       [-1 ... EM_N_OBJECTS-1]
  @glob_in         *SLATE_pu_GetDistXSortedObj(j) : Objects sorted according to x distance                                  [-1 ... EM_N_OBJECTS-1]
  @glob_in         *SLATE_pt_GetObjDynProperty(t_ObjNr): Macro to obtain dynamic object property. This signal indicates wether the object is moving, 
                             stationary or oncoming, based on comparison of the longitudinal relative velocity with the host vehicle velocity     [0...7]
                             enum { EM_GEN_OBJECT_DYN_PROPERTY_CROSSING_LEFT=3,EM_GEN_OBJECT_DYN_PROPERTY_STOPPED=6,EM_GEN_OBJECT_DYN_PROPERTY_CROSSING_RIGHT=4,EM_GEN_OBJECT_DYN_PROPERTY_MOVING=0,EM_GEN_OBJECT_DYN_PROPERTY_ONCOMING=2,EM_GEN_OBJECT_DYN_PROPERTY_STATIONARY=1,EM_GEN_OBJECT_DYN_PROPERTY_UNKNOWN=5,EM_GEN_OBJECT_DYN_PROPERTY_MAX_DIFF_TYPES=7,}
  @glob_in         SLATE_u_GetAccQuality(t_ObjNr) : Macro to access EM-based function pre-selection information (based on GET_EM_OBJ_PUB(iObj)   [full range of unsigned char]
  @glob_in         *pt_LAInput->t_RTE.pf_ObjLongDisp  (t_ObjNrRel) : Macro to get longitudinal distance of given object               [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
  @glob_in         OBJ_GET_CP(t_ObjNr) : Distance from trajectory of datatype CPObjDist2Traj_t as defined in cp_ext.h
  @glob_in         pt_LAInput->t_RTE.pf_ObjVrelX(t_ObjNrRel) : Longidudinal relative velocity for the given object                      [-330.f ... 330.f] m/s 

  @glob_out        -

  @c_switch_part   -
  @c_switch_full     LA_CFG_EXT_NEIGHBORHOOD_REL_OBJ : As defined in la_cfg.h. Configuration switch to enable bracket extension used for situations in 
                     which the relevant object moves in the direction of a near neighboring object. For the relevant object the 
                     brackets are extended. Should only be active if camera lane information is available to detect the ego 
                     lane change phases.
  @c_switch_full     LA_CFG_ADD_RESTRICTION_OBJ_TRACE : Configuration switch to enable restriction based on relevant object trace. Enabled when
                     FCT_CFG_OBJECT_TRACE_PREPROCESSSING is on.
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         09.09.2015
  @changed         09.09.2015

  @todo            adapt config switch for used variables
                   if the function is called on more locations, the result for all objects should be saved in a global variable

  @author          Yvonne Strigel | yvonne.strigel@continental-corporation.com | +49 (8382) 9699-696
*************************************************************************************************************************/
void LA_t_FindNearNeighboringObjToEgoLane( const ObjNumber_t t_ObjNrRel )
{
  ObjNumber_t t_ObjNrNeighborObj = OBJ_INDEX_NO_OBJECT;

  ObjNumber_t j = 0;
  ObjNumber_t i_NumOfObjectsUsed;
  boolean b_hintObjNeighbouringLane = FALSE;    /*!< hint that the object drives on the neighboring lane */
  boolean b_hintDoubleObject = FALSE;           /*!< hint that relevant object and found neighboring object belong to the same vehicle */
  boolean b_hintRelObjOccluded = TRUE;          /*!< hint that the relevant object is occluded */
  boolean b_hintMirror = FALSE;                 /*!< hint that relevant object and neighboring object are mirrors of the same vehicle */
  ObjNumber_t t_ObjNr = OBJ_INDEX_NO_OBJECT;    /*!< index for search of neighboring object */
  TraceID_t t_ObjTraceNr = FIP_STATIC_TRACE_NO_OF_TRACES;  /*!< index of trace belonging to relevant object*/
  float32 f_DistObjToTraj = 0.f;                /*!< lateral distance between neighboring object and ACC trajectory */
  float32 f_DistRelToTraj = 0.f;                /*!< lateral distance between relevant object and ACC trajectory */
  float32 f_LongDistDiff = 0.f;                 /*!< difference of longitudinal distances between relevant and neighboring object and ACC trajectory */
  float32 f_LatDistDiff = 0.f;                  /*!< difference of lateral distances to relevant and neighboring object */
  float32 fYIntersection = 0.f;
  const float32 f_ObjNrRelVrelX = *pt_LAInput->t_RTE.pf_ObjVrelX(t_ObjNrRel);
  float32 f_DiffVrel = 0.f;
  float32 fABS_YIntersection, fABS_LongDistDiff, fABS_LatDistDiff, fABS_DistRelToTraj, fABS_DistObjToTraj;	/* For calculating ABS value */
  SLATE_t_Obj_DynamicProperty t_ObjDynamicProperty;
  float32 f_ABS_LongDistDiff;

  /* if target object is occluded the risk for drop ins from neighboring lane is high.
  Therefore, the bracket extension is inactive for occluded objects */
  if ((SLATE_p_GetEMGenObjAttributes(t_ObjNrRel)->eObjectOcclusion == EM_GEN_OBJECT_OCCL_NONE)
    || (SLATE_p_GetEMGenObjAttributes(t_ObjNrRel)->eObjectOcclusion == EM_GEN_OBJECT_OCCL_UNKNOWN)
    || (pt_LAInput->t_SIT.pt_ObjBool(t_ObjNrRel)->OccludedByTrace == (ubit8_t)0u)
    )
  {
    b_hintRelObjOccluded = FALSE;
  }

  /* if trace exists and lateral difference between ego-position and trace is huge 
  object is not considered to avoid long drop-ins from neighboring lane */
  t_ObjTraceNr = *(pt_LAInput->t_FIPMOTTraceId.pu_FIPStaticTraceID(t_ObjNrRel));
  if (t_ObjTraceNr < (TraceID_t)FIP_STATIC_TRACE_NO_OF_TRACES)
  {
  	fYIntersection = pt_LAInput->pt_FIPMOT->t_MovObjStaticTrace[t_ObjTraceNr].fYIntersection;
  }
  
  fABS_YIntersection = fABS(fYIntersection);
  if ((t_ObjTraceNr < (TraceID_t)FIP_STATIC_TRACE_NO_OF_TRACES)
    && (fABS_YIntersection < LA_DIST_INVALID_TRACE_NEIGHBORHOOD)
    && (fABS_YIntersection > LA_DIST_MIN_TRACE_NEIGHBORHOOD) 
    )
  {
    b_hintObjNeighbouringLane = TRUE;
  }

  /* Find a near neighboring object */
  i_NumOfObjectsUsed = SLATE_t_GetNumOfObjectsUsed();
  for (j = 0; ((j < i_NumOfObjectsUsed) && (t_ObjNrNeighborObj == OBJ_INDEX_NO_OBJECT)); j++)
  {
    /* Get x-distance sorted objects */
    t_ObjNr = *SLATE_pu_GetDistXSortedObj(j);
    t_ObjDynamicProperty = *SLATE_pt_GetObjDynProperty(t_ObjNr);
    /* Do not consider the relevant object! The trace bracket extension is applied to the relevant object but 
    here a near neighboring object is looked for. Here, only moving neighboring objects are considered and 
    only objects with sufficient ACC-quality */
    if ( (t_ObjNr != t_ObjNrRel) &&
          (t_ObjDynamicProperty == SLATE_OBJECT_PROPERTY_MOVING) &&
          (SLATE_p_GetEMGenObjQualifiers(t_ObjNr)->uiAccObjQuality >= FUN_PRESEL_ACC_MIN_OBJ_QUAL)
      )
    {
      /* calculate longitudinal distances difference to relevant object */
      f_LongDistDiff = (*pt_LAInput->t_RTE.pf_ObjLongDisp(t_ObjNrRel))- (*pt_LAInput->t_RTE.pf_ObjLongDisp(t_ObjNr));

          /* calculate the ACC trajectory distances difference compared to relevant object  */
          f_DistObjToTraj = pt_LAOutput->t_LAObjOutputList[t_ObjNr].TrajDist.TrajDistMeas.Y.f0;
          f_DistRelToTraj = pt_LAOutput->t_LAObjOutputList[t_ObjNrRel].TrajDist.TrajDistMeas.Y.f0;
          f_LatDistDiff = f_DistObjToTraj - f_DistRelToTraj;
		  fABS_LongDistDiff = fABS(f_LongDistDiff);
		  fABS_LatDistDiff = fABS(f_LatDistDiff);
          /* Problem: the relevant object can have two radar objects (happens often for trucks). To suppress this second object 
          the longitudinal distance and the lateral distance to the relevant object must be above a threshold.*/
          if ((fABS_LongDistDiff <= LA_DIST_HINT_DOUBLEOBJ_NEIGHBORHOOD) 
            && (fABS_LatDistDiff <= (0.5F * LA_STANDARDLANEWIDTHSEEK)))
          {
            b_hintDoubleObject = TRUE;
          }
          else
          {
            b_hintDoubleObject = FALSE;
          }
          f_DiffVrel = (fABS(f_ObjNrRelVrelX- *pt_LAInput->t_RTE.pf_ObjVrelX(t_ObjNr)));
          /* avoid trace bracket extension for object and its mirror: Therefore, the longitudinal distance and the relative velocity difference 
          to the relevant object must be above a threshold */
          f_ABS_LongDistDiff = fABS(f_LongDistDiff);
          if ((f_ABS_LongDistDiff < LA_DIST_LONG_HINT_MIRROR_NEIGHBORHOOD) && (f_DiffVrel < LA_VEL_DIFF_HINT_MIRROR_NEIGHBORHOOD))
          {
            b_hintMirror = TRUE;
            
          }
          else
          {
            b_hintMirror = FALSE;
          }

          /* Restriction: 
          only for objects in direct longitudinal and lateral neighborhood based on position and distance to ACC trajectory
          which are not occluded and 
          for which none of the hints calculated is true (hint for neighboring lane, hint for second radar object of the same real object, 
          hint for mirror object) */
		  fABS_DistRelToTraj = fABS(f_DistRelToTraj);
		  fABS_DistObjToTraj = fABS(f_DistObjToTraj);
		  
          if( (f_LongDistDiff < LA_DIST_DIFF_LONG_NEAR_REL_OBJ_NEIGHBORHOOD)
            && (f_LongDistDiff > LA_DIST_DIFF_LONG_FAR_REL_OBJ_NEIGHBORHOOD)
            && (fABS_DistRelToTraj <= LA_DIST_MAX_REL_TO_TRAJ_NEIGHBORHOOD)
            && (fABS_DistObjToTraj <= LA_DIST_TO_TRAJ_OBJ_NEIGHBORHOOD)
            && (b_hintRelObjOccluded == FALSE)
            && (b_hintObjNeighbouringLane == FALSE)
            && (b_hintDoubleObject == FALSE)
            && (b_hintMirror == FALSE)
            )
          {
            if((f_LatDistDiff < 0.F) && (f_DistRelToTraj <= 0.F))
            {
              /* both objects are on the right side of the ACC trajectory */
              t_ObjNrNeighborObj = t_ObjNr;
            } 
            else if ((f_LatDistDiff > 0.F) && (f_DistRelToTraj >= 0.F))
            {
              /* both objects are on the left side of the ACC trajectory */
              t_ObjNrNeighborObj = t_ObjNr;
            }
            else 
            {
              /* objects are on different sides of the ACC trajectory -> not relevant*/
            }
          }
    }
  }

  pt_LAOutput->t_NearNeighboringObj[t_ObjNrRel] = t_ObjNrNeighborObj; 
}
#endif /* END IF (LA_CFG_EXT_NEIGHBORHOOD_REL_OBJ || LA_CFG_ADD_RESTRICTION_OBJ_TRACE) */


#if ((LA_CFG_EXT_LOWSPEEDFUSEDBRD) && (FCT_CFG_ROAD_INPUT))
/*************************************************************************************************************************
  Functionname:    LA_v_CalcCorrExtendLowSpeedFusedBrd                                                              */ /*!

  @brief           Trace bracket extension for the relevant object in low speed and close range situations.

  @description     Trace bracket extension for the relevant object in situations in low ego-velocities and short range distance
                   of the relevant object. Extend trace brackets if no adjacent drivable lane exists, or Fused Roadborder 
                   indicates no plausible gap between roadborder and object, or relevant object has high cluster spread
                   @startuml
Partition LA_v_CalcCorrExtendLowSpeedFusedBrd{
Start
	if(FIP road estimation y left is greater than 0) then (yes)
		-set Road Border Left to minimum of Road Border Left and FIP road estimation y left
	endif
	
	if(FIP road estimation y Right is less than 0) then (yes)
		-set Road Border Right to maximum of Road Border Left and FIP road estimation y Right
	endif
	
	if(Object is relevant objects and Ego velocity is below 25 km/h and
    Distance of relevant object is below 20 m and Curve radius above 10 m) then (yes)
	    if(ego speed below or equal to 5 km/h and maximum distance x is less than or equal to 10m) then (yes)
			-set minimum extension as default
		else
			if(number of drivable lanes to left is zero) then (yes)
				if(there is no sufficient space on the Left side and Ego is not moving faster than object) then (yes)
					-extend trace bracket left
				else
					-do nothing
				endif
			elseif(number of drivable lanes to left is -1)then (yes)
			    if(Driver steer away from Stationary object and number of lanes on right is unknown) then (yes)
					-Do nothing
				elseif(there exists a lane or we are unsure, in any case check fused road border in this case) then (yes)
				    -set distance to Road Border Left to LA MIN LOW SPEED FUSEDBRD EXTENSION
			    else
					-Do nothing
				endif
			else
				if(there exists a lane or we are unsure, in any case check fused road border in this case) then (yes)
				    -set distance to Road Border Left to LA MIN LOW SPEED FUSEDBRD EXTENSION
			    else
					-Do nothing
				endif
			endif
			
			if(number of drivable lanes to Right is zero) then (yes)
				if(there is no sufficient space on the Right side and Ego is not moving faster than object) then (yes)
					-extend trace bracket left
				else
					-do nothing
				endif
			elseif(number of drivable lanes to Right is -1) then (yes)
			    if(Driver steer away from Stationary object and number of lanes on right is unknown) then (yes)
					-Do nothing
				elseif(there exists a lane or we are unsure, in any case check fused road border in this case) then (yes)
				    -set distance to Road Border Right to LA MIN LOW SPEED FUSEDBRD EXTENSION
			    else
					-Do nothing
				endif
		    else
				if(there exists a lane or we are unsure, in any case check fused road border in this case) then (yes)
				    -set distance to Road Border Right to LA MIN LOW SPEED FUSEDBRD EXTENSION
			    else
					-Do nothing
				endif
			endif
			
		endif
		
		-set Bracket Position Left to distance Road Border Left
		-set Bracket Position Right to distance Road Border Right
	endif
end
}
@enduml

  @return          -

  @param[in]       p_ObjInput : Pointer to datatype LA_t_RelTraObjInput as defined in si_corridor_crit.h
                      p_ObjInput->iObjNr : Object no                                                               [-1 ... EM_N_OBJECTS-1]
                      p_ObjInput->dAblage_m : dAblage_m                                                            [Full range of float32]
                      p_ObjInput->iRelevant : If the given object is relevant or not                               [TRUE, FALSE]

  @param[in]       p_Environment :Pointer to datatype LA_t_AssTraEnvironment as defined in si_corridor_crit.h
                      p_Environment->iNumberLanesLeft : No of drivable lanes on the left side of the lane           [-1...20]
                      p_Environment->iNumberLanesRight : No of drivable lanes on the right side of the lane         [-1...20]


  @param[in,out]   p_BracketOut : Pointer to datatype LA_t_BracketOutput as defined in si_corridor_crit.h
                      p_BracketOut->BracketPositionRight : Right bracket position                                   [-PI/2*RW_FCT_MAX ... 0] m
                      p_BracketOut->BracketPositionLeft :  Left bracket position                                    [0 ... PI/2*RW_FCT_MAX] m

  @glob_in         pt_LAInput->pt_FIPRoad : pointer to road data type
                      pt_LAInput->pt_FIPRoad->t_FIPRoadFusedBorder.fDistLeft : Lateral displacement to left border                [0 ... PI/2*RW_FCT_MAX] m
                      pt_LAInput->pt_FIPRoad->t_FIPRoadFusedBorder.fDistRight : Lateral displacement to right border              [-PI/2*RW_FCT_MAX ... 0] m
                      pt_LAInput->pt_FIPRoad->t_FIPRoadFusedBorder.fYLeft : Legecy Lateral displacement to left border      [0 ... PI/2*RW_FCT_MAX] m
                      pt_LAInput->pt_FIPRoad->t_FIPRoadFusedBorder.fYRight : Legecy Lateral displacement to right border    [-PI/2*RW_FCT_MAX ... 0] m

  @glob_in         pt_LAInput->t_RTE.pf_EgoVelObjSync : Ego Speed                                                                 [-330.f ... 330.f] m/s
  @glob_in         *pt_LAInput->t_RTE.pf_ObjLongDisp   : Macro to get longitudinal distance of given object                       [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
  @glob_in         pt_LAInput->t_RTE.pf_EgoCurveRaw : Curvature                                                                        [-1 ... 1]m^-1
  @glob_in         pt_LAInput->t_CP.pf_CourseCurve :  Ego course curvature [1/m] 
  @glob_in         pt_LAInput->t_RTE.pf_ObjOrientation( ) :orientation of the object             [-PI   PI] rad
  @glob_in         SLATE_u_GetAccQuality(ObjNr) : Macro for accessing EM-based function pre-selection information (based on GET_EM_OBJ_PUB(iObj)) as defined in algo_glob.h
  @glob_in         pt_LAInput->t_RTE.pf_ObjVrelX(i) : Relative velocity of object i [-330.f ... 330.f] m/s
  @glob_out        -

  @c_switch_part   LA_CFG_EXT_LOWSPEEDFUSEDBRD_DRIVER_STEER_AWAY : To enable, trace brackets extension for low ego velocities, missing adjacent lanes and fused road boarder while driver steer away
  @c_switch_part   LA_CFG_EXT_LOWSPEEDFUSEDBRD_SUFFICIENT_SPACE_STEER : To enable, Incase Driver steer away from Object and we have sufficient place to steer away from Object
  @c_switch_part   LA_CFG_EXT_LOWSPEEDFUSEDBRD_BASED_ON_CAM : To enable, Extend the trace bracket when the object is within the camera lane marker  
  @c_switch_part   LA_CFG_EXT_LOWSPEEDFUSEDBRD_ORIENTATION_ENABLE : To enable object orientation to release early if relevant object exiting the lane
  @c_switch_full   LA_CFG_EXT_LOWSPEEDFUSEDBRD : To enable, trace brackets extension for low ego velocities, missing adjacent lanes and fused road boarder
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component

  @pre             LA_CFG_EXT_LOWSPEEDFUSEDBRD needs to be activated
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         28.10.2015
  @changed         28.10.2015

  @todo            Inputs from FIP Road (pt_LAInput->t_FIPRoad) are available only if switch FCT_CFG_INPUT_PREPROCESSSING is 
                   on, which is not considered here. Switch for FCT_CFG_ROAD_INPUT to also be adapted.

  @author          Christopher Knievel | christopher.knievel@continental-corporation.com | +49 (8382) 9699-399
*************************************************************************************************************************/
static void LA_v_CalcCorrExtendLowSpeedFusedBrd(LA_t_RelTraObjInput const * p_ObjInput, LA_t_AssTraEnvironment const *p_Environment, LA_t_BracketOutput * p_BracketOut )
{
  float32 dAblage_RoadBorderLeft = 0.f;
  float32 dAblage_RoadBorderRight = 0.f;

  float32 fRoadBorderLeft =  pt_LAInput->pt_FIPRoad->t_FIPRoadFusedBorder.fDistLeft;
  float32 fRoadBorderRight = pt_LAInput->pt_FIPRoad->t_FIPRoadFusedBorder.fDistRight;
#if LA_CFG_EXT_LOWSPEEDFUSEDBRD_ORIENTATION_ENABLE
  const fCurve_t f_Curve = *(pt_LAInput->t_CP.pf_CourseCurve);  /* get curvature */
  const fCurve_t f_AbsCurve = fABS(f_Curve); /* Absolute curvature */
  float32 f_ObjOrientation = pt_LAInput->t_RTE.pf_ObjOrientation(p_ObjInput->iObjNr);
#endif /* end of (LA_CFG_EXT_LOWSPEEDFUSEDBRD_ORIENTATION_ENABLE)*/
  float32 f_EgoVelObjSync = *pt_LAInput->t_RTE.pf_EgoVelObjSync;
  float32 f_ObjLongDisp   = *pt_LAInput->t_RTE.pf_ObjLongDisp(p_ObjInput->iObjNr);
  float32 f_EgoCurveRaw   = fABS(*pt_LAInput->t_RTE.pf_EgoCurveRaw);
#if (LA_CFG_EXT_LOWSPEEDFUSEDBRD_DRIVER_STEER_AWAY || LA_CFG_DISABLE_EXT_LOWSPEEDFUSEDBRD_BASED_ON_DIST2TRAJ)
  SLATE_t_Obj_DynamicProperty t_ObjDynamicProperty = *SLATE_pt_GetObjDynProperty(p_ObjInput->iObjNr);
#endif /* end of LA_CFG_EXT_LOWSPEEDFUSEDBRD_DRIVER_STEER_AWAY || LA_CFG_DISABLE_EXT_LOWSPEEDFUSEDBRD_BASED_ON_DIST2TRAJ */

#if LA_CFG_EXT_LOWSPEEDFUSEDBRD_SUFFICIENT_SPACE_STEER
  float32 f_ObjVrelX      = *pt_LAInput->t_RTE.pf_ObjVrelX(p_ObjInput->iObjNr);
  float32 f_ABS_RoadBorderLeft;
  float32 f_ABS_RoadBorderRight;
#endif  /* end of LA_CFG_EXT_LOWSPEEDFUSEDBRD_SUFFICIENT_SPACE_STEER */
  uint8 u_ObjACCQuality = SLATE_u_GetAccQuality(p_ObjInput->iObjNr);

#if (LA_CFG_EXT_LOWSPEEDFUSEDBRD_BASED_ON_CAM )
  const float32 f_LeftMarkerDist = pSLATE_CamLaneData->LaneMarkerInfo[FIP_CL_MK_LEFT].f_MarkerDist;
  const uint8 f_LeftMarkerProb = pSLATE_CamLaneData->LaneMarkerInfo[FIP_CL_MK_LEFT]. u_ExistanceProbability;
  const float32 f_RightMarkerDist = pSLATE_CamLaneData->LaneMarkerInfo[FIP_CL_MK_RIGHT].f_MarkerDist;
  const uint8 f_RightMarkerProb = pSLATE_CamLaneData->LaneMarkerInfo[FIP_CL_MK_RIGHT]. u_ExistanceProbability;
  const float32 fDistToTraj = pt_LAOutput->t_LAObjOutputList[p_ObjInput->iObjNr].TrajDist.TrajDistMeas.Y.f0;
  float32 f_LeftMarkerDistAbs = fABS(f_LeftMarkerDist);
  float32 f_RightMarkerDistAbs = fABS(f_RightMarkerDist);
  float32 fDistToTrajAbs = fABS(fDistToTraj);
  float32 f_CamLaneVirtual;
#endif

  if((pt_LAInput->pt_FIPRoad->t_FIPRoadEstimation.fYLeft) > 0.f)
  {
    fRoadBorderLeft  = MIN_FLOAT(fRoadBorderLeft, (pt_LAInput->pt_FIPRoad->t_FIPRoadEstimation.fYLeft));
  }
  
  if((pt_LAInput->pt_FIPRoad->t_FIPRoadEstimation.fYRight) < 0.f)
  {
    fRoadBorderRight = MAX_FLOAT(fRoadBorderRight,(pt_LAInput->pt_FIPRoad->t_FIPRoadEstimation.fYRight));
  }

  /*  Only relevant objects shall be extended
      Ego velocity needs to be below 25 km/h  
      Distance of relevant object needs to be below 20 m 
      Curve radius above 10 m */
  if  (    (p_ObjInput->iRelevant == TRUE)
        && (f_EgoVelObjSync <= LA_MAX_SPEED_LOW_SPEED_FUSEDBRD_EXTENSION)
        && (f_ObjLongDisp <= LA_MAX_DISTX_LOW_SPEED_FUSEDBRD_EXTENSION)
        && (f_EgoCurveRaw < LA_MAX_CURVE_RADIUS_LOW_SPEED_FUSEDBRD_EXTENSION))
  {
    /* set minimum extension as default when ego speed below or equal to 5 km/h and max distx <= 10m*/
    if(     (f_EgoVelObjSync <= LA_MAX_SPEED_DEFAULT_LOW_SPEED_FUSEDBRD_EXTENSION)
        &&  (f_ObjLongDisp <= LA_MAX_DISTX_DEFAULT_LOW_SPEED_FUSEDBRD_EXTENSION))
    {
#if (LA_CFG_EXT_LOWSPEEDFUSEDBRD_BASED_ON_CAM )
        if ( (f_LeftMarkerProb  >= FIP_CAM_LANE_POE_LEVEL) || (f_RightMarkerProb  >= FIP_CAM_LANE_POE_LEVEL)) /* At least one near lane has good confidence */
        {
            if (fDistToTraj > 0.f) /* Object is left to trajectory */
            {
                f_CamLaneVirtual = (f_LeftMarkerDistAbs > 0.f) ? f_LeftMarkerDistAbs : (LA_LOWSPEEDFUSEDBRD_CAMLANE_WIDTH - f_RightMarkerDistAbs); /* Calculate Object distance to Camera lane */
                f_CamLaneVirtual = (f_CamLaneVirtual > 0.f) ? f_CamLaneVirtual : LA_LOWSPEEDFUSEDBRD_CAMLANE_HALF ; /* Must be a Positive value */
                if (fDistToTrajAbs < f_CamLaneVirtual)
                {
                    dAblage_RoadBorderLeft  = LA_DEFAULT_LOW_SPEED_FUSEDBRD_EXTENSION;
                }	
                else
                {
                   /* Dont extend TB */
                }
            }
            else /* Object is right to trajectory */
            {
                f_CamLaneVirtual = (f_RightMarkerDistAbs > 0.f) ? f_RightMarkerDistAbs : (LA_LOWSPEEDFUSEDBRD_CAMLANE_WIDTH - f_LeftMarkerDistAbs) ; /* Calculate Object distance to Camera lane */
                f_CamLaneVirtual = (f_CamLaneVirtual > 0.f) ? f_CamLaneVirtual : LA_LOWSPEEDFUSEDBRD_CAMLANE_HALF ; /* Must be a Positive value */
                if (fDistToTrajAbs < f_CamLaneVirtual)
                {
                    dAblage_RoadBorderRight = -LA_DEFAULT_LOW_SPEED_FUSEDBRD_EXTENSION;
                }
                else
                {
                   /* Dont extend TB */
                }
            }
        }
        else
        {
            dAblage_RoadBorderLeft  = LA_DEFAULT_LOW_SPEED_FUSEDBRD_EXTENSION;
            dAblage_RoadBorderRight = -LA_DEFAULT_LOW_SPEED_FUSEDBRD_EXTENSION;
        }
#else
        dAblage_RoadBorderLeft  = LA_DEFAULT_LOW_SPEED_FUSEDBRD_EXTENSION;
        dAblage_RoadBorderRight = -LA_DEFAULT_LOW_SPEED_FUSEDBRD_EXTENSION;
#endif /*(LA_CFG_EXT_LOWSPEEDFUSEDBRD_BASED_ON_CAM )*/
    }
    else
    {
      /* Check if number of drivable lanes is zero */
      if(p_Environment->iNumberLanesLeft == 0L)
      {
#if LA_CFG_EXT_LOWSPEEDFUSEDBRD_ORIENTATION_ENABLE
	    dAblage_RoadBorderLeft = LA_MIN_LOW_SPEED_FUSEDBRD_EXTENSION;
#endif /* end of (LA_CFG_EXT_LOWSPEEDFUSEDBRD_ORIENTATION_ENABLE)*/
        /* no drivable lane available, hence extend the trace bracket */
#if LA_CFG_EXT_LOWSPEEDFUSEDBRD_SUFFICIENT_SPACE_STEER
        /*Do not extend TB if there is sufficient space on the Left side and Ego is moving faster than object */
        f_ABS_RoadBorderLeft = fABS(fRoadBorderLeft);
        if( (   (f_ABS_RoadBorderLeft  < LA_SUFFICIENT_DIST_TO_RB_TO_DRIVE) 
             && (pt_LAOutput->t_LAObjOutputList[p_ObjInput->iObjNr].TrajDist.TrajDistMeas.Y.f0 > -LA_MAX_LATERAL_POS_DRIVER_STEER )
#if (LA_CFG_DISABLE_EXT_LOWSPEEDFUSEDBRD_BASED_ON_DIST2TRAJ)
             && (   (t_ObjDynamicProperty == (uint8)SLATE_OBJECT_PROPERTY_MOVING) 
                 || (   (t_ObjDynamicProperty == (uint8)SLATE_OBJECT_PROPERTY_STATIONARY) 
                     && (pt_LAOutput->t_LAObjOutputList[p_ObjInput->iObjNr].TrajDist.TrajDistMeas.Y.f0 < LA_MAX_DIST2TRAJ )
                    )
                )
#endif /* (LA_CFG_DISABLE_EXT_LOWSPEEDFUSEDBRD_BASED_ON_DIST2TRAJ) */
            ) 
            || (f_ObjVrelX > (0.0f) ) 
          )
        {
          dAblage_RoadBorderLeft = LA_MAX_LOW_SPEED_FUSEDBRD_EXTENSION;
#if LA_CFG_EXT_LOWSPEEDFUSEDBRD_ORIENTATION_ENABLE
		  if (f_AbsCurve > LA_LFBE_HIGH_CURVE)
		  {
		    dAblage_RoadBorderLeft = LA_DEFAULT_LOW_SPEED_FUSEDBRD_EXTENSION;
		  }
		  else if (f_ObjOrientation > LA_FORIENTATION_BOUNDARY_VAL)
		  {
		    dAblage_RoadBorderLeft = LA_FORIENTATION_LOW_SPEED_FUSEDBRD_EXTENSION;
		  }
		  else
		  {
		    /*dont extend TB */
		  }
#endif /* end of (LA_CFG_EXT_LOWSPEEDFUSEDBRD_ORIENTATION_ENABLE)*/
        }
        else
        {
           /* Dont extend TB */
        }
#else
        dAblage_RoadBorderLeft = LA_MAX_LOW_SPEED_FUSEDBRD_EXTENSION;
#endif  /* end of LA_CFG_EXT_LOWSPEEDFUSEDBRD_SUFFICIENT_SPACE_STEER */
      }
#if LA_CFG_EXT_LOWSPEEDFUSEDBRD_DRIVER_STEER_AWAY
      else if((p_Environment->iNumberLanesLeft == -1)) 
      {
          /*if Driver steer away from Stationary object and number of lanes on right is unknown then don't apply extention */
        if( (pt_LAOutput->t_LAObjOutputList[p_ObjInput->iObjNr].TrajDist.TrajDistMeas.Y.f0 > LA_MAX_LATERAL_POS_DRIVER_STEER) && 
            ( (t_ObjDynamicProperty == (uint8)SLATE_OBJECT_PROPERTY_STATIONARY)
#if (FCT_CFG_SENSOR_TYPE_CAMERA)
           || (t_ObjDynamicProperty == (uint8)SLATE_OBJECT_PROPERTY_STOPPED)
#endif /* FCT_CFG_SENSOR_TYPE_CAMERA */
            )
          )
        {
          /* do Nothing Driver want to steer away from the Object so don't extend the TB */
        }
          /* Apparently there exists a lane or we are unsure, in any case check fused road border in this case */
        else if(  (((p_ObjInput->dAblage_m > 0.f) && (p_ObjInput->dAblage_m < HALBESTRASSENBREITE ))
            && (    ((fRoadBorderLeft - p_ObjInput->dAblage_m) < LA_MAX_GAP_LOW_SPEED_FUSEDBRD_EXTENSION)
                 && (u_ObjACCQuality <= FUN_PRESEL_ACC_HIGH_CLUST_VAR_OBJ_QUAL)))
            || (((fRoadBorderLeft - p_ObjInput->dAblage_m) < LA_MIN_GAP_LOW_SPEED_FUSEDBRD_EXTENSION)))
        {
          dAblage_RoadBorderLeft = LA_MIN_LOW_SPEED_FUSEDBRD_EXTENSION;
        }
        else
        {
          /* more than one lane, but may be plausible. nothing to do here */
        }
      }
#endif  /* end of LA_CFG_EXT_LOWSPEEDFUSEDBRD_DRIVER_STEER_AWAY*/
      else
      {
        /* Apparently there exists a lane or we are unsure, in any case check fused road border in this case */
        if(  (((p_ObjInput->dAblage_m > 0.f) && (p_ObjInput->dAblage_m < HALBESTRASSENBREITE ))
            && (    ((fRoadBorderLeft - p_ObjInput->dAblage_m) < LA_MAX_GAP_LOW_SPEED_FUSEDBRD_EXTENSION)
                 && (u_ObjACCQuality <= FUN_PRESEL_ACC_HIGH_CLUST_VAR_OBJ_QUAL)))
            || (((fRoadBorderLeft - p_ObjInput->dAblage_m) < LA_MIN_GAP_LOW_SPEED_FUSEDBRD_EXTENSION)))
        {
          dAblage_RoadBorderLeft = LA_MIN_LOW_SPEED_FUSEDBRD_EXTENSION;
        }
        else
        {
          /* more than one lane, but may be plausible. nothing to do here */
        }
      }
    
      if(p_Environment->iNumberLanesRight == 0L)
      {
#if LA_CFG_EXT_LOWSPEEDFUSEDBRD_ORIENTATION_ENABLE
	    dAblage_RoadBorderRight = -LA_MIN_LOW_SPEED_FUSEDBRD_EXTENSION;
#endif /* end of (LA_CFG_EXT_LOWSPEEDFUSEDBRD_ORIENTATION_ENABLE)*/
        /* no drivable lane available, hence extend the trace bracket */
#if LA_CFG_EXT_LOWSPEEDFUSEDBRD_SUFFICIENT_SPACE_STEER
        /*Do not extend TB if there is sufficient space on the Right side and Ego is moving faster than object */
        f_ABS_RoadBorderRight = fABS(fRoadBorderRight);
        if( (   (f_ABS_RoadBorderRight < LA_SUFFICIENT_DIST_TO_RB_TO_DRIVE) 
             && (pt_LAOutput->t_LAObjOutputList[p_ObjInput->iObjNr].TrajDist.TrajDistMeas.Y.f0 < LA_MAX_LATERAL_POS_DRIVER_STEER )
#if (LA_CFG_DISABLE_EXT_LOWSPEEDFUSEDBRD_BASED_ON_DIST2TRAJ)
             && (  (t_ObjDynamicProperty == (uint8)SLATE_OBJECT_PROPERTY_MOVING) 
                || (   (t_ObjDynamicProperty == (uint8)SLATE_OBJECT_PROPERTY_STATIONARY) 
                    && (pt_LAOutput->t_LAObjOutputList[p_ObjInput->iObjNr].TrajDist.TrajDistMeas.Y.f0 > -LA_MAX_DIST2TRAJ )
                   )
                )
#endif /* (LA_CFG_DISABLE_EXT_LOWSPEEDFUSEDBRD_BASED_ON_DIST2TRAJ) */
            ) 
            || (f_ObjVrelX > 0.0f ) 
          )
        {
		  dAblage_RoadBorderRight = -LA_MAX_LOW_SPEED_FUSEDBRD_EXTENSION;
#if LA_CFG_EXT_LOWSPEEDFUSEDBRD_ORIENTATION_ENABLE
		  if (f_AbsCurve > LA_LFBE_HIGH_CURVE)
		  {
		    dAblage_RoadBorderRight = -LA_DEFAULT_LOW_SPEED_FUSEDBRD_EXTENSION;
		  }
		  else if(f_ObjOrientation < -LA_FORIENTATION_BOUNDARY_VAL)
		  {
		    dAblage_RoadBorderRight = -LA_FORIENTATION_LOW_SPEED_FUSEDBRD_EXTENSION;
		  }
		  else
		  {
		    /*dont extend TB */
		  }
#endif /* end of (LA_CFG_EXT_LOWSPEEDFUSEDBRD_ORIENTATION_ENABLE)*/
        }
        else
        {
          /*dont extend TB */
        }
#else
        dAblage_RoadBorderRight = -LA_MAX_LOW_SPEED_FUSEDBRD_EXTENSION;
#endif  /* end of LA_CFG_EXT_LOWSPEEDFUSEDBRD_SUFFICIENT_SPACE_STEER */
      }
#if LA_CFG_EXT_LOWSPEEDFUSEDBRD_DRIVER_STEER_AWAY
      else if((p_Environment->iNumberLanesRight == -1)) 
      {
          /*if Driver steer away from Stationary object and number of lanes on right is unknown then don't apply extention */
        if((pt_LAOutput->t_LAObjOutputList[p_ObjInput->iObjNr].TrajDist.TrajDistMeas.Y.f0 < -LA_MAX_LATERAL_POS_DRIVER_STEER) && (t_ObjDynamicProperty == (uint8)SLATE_OBJECT_PROPERTY_STATIONARY) )
        {
          /* do Nothing Driver want to steer away from the Object so don't extend the TB */
        }
          /* Apparently there exists a lane or we are unsure, in any case check fused road border in this case */
        else if( (((p_ObjInput->dAblage_m < 0.f) && (p_ObjInput->dAblage_m > -HALBESTRASSENBREITE ))
          && (    ((fRoadBorderRight - p_ObjInput->dAblage_m) > -LA_MAX_GAP_LOW_SPEED_FUSEDBRD_EXTENSION)
               && (u_ObjACCQuality <= FUN_PRESEL_ACC_HIGH_CLUST_VAR_OBJ_QUAL)))
          || (((fRoadBorderRight - p_ObjInput->dAblage_m) > -LA_MIN_GAP_LOW_SPEED_FUSEDBRD_EXTENSION)))
        {
          dAblage_RoadBorderRight = -LA_MIN_LOW_SPEED_FUSEDBRD_EXTENSION;
        }
        else
        {
          /* more than one lane, but may be plausible. nothing to do here */
        }
      }
#endif  /* end of LA_CFG_EXT_LOWSPEEDFUSEDBRD_DRIVER_STEER_AWAY*/
      else
      {
        /* Apparently there exists a lane or we are unsure, in any case check fused road border in this case */
        if( (((p_ObjInput->dAblage_m < 0.f) && (p_ObjInput->dAblage_m > -HALBESTRASSENBREITE ))
          && (    ((fRoadBorderRight - p_ObjInput->dAblage_m) > -LA_MAX_GAP_LOW_SPEED_FUSEDBRD_EXTENSION)
               && (u_ObjACCQuality <= FUN_PRESEL_ACC_HIGH_CLUST_VAR_OBJ_QUAL)))
          || (((fRoadBorderRight - p_ObjInput->dAblage_m) > -LA_MIN_GAP_LOW_SPEED_FUSEDBRD_EXTENSION)))
        {
          dAblage_RoadBorderRight = -LA_MIN_LOW_SPEED_FUSEDBRD_EXTENSION;
        }
        else
        {
          /* more than one lane, but may be plausible. nothing to do here */
        }
      }
    }

    p_BracketOut->BracketPositionLeft  = dAblage_RoadBorderLeft;
    p_BracketOut->BracketPositionRight = dAblage_RoadBorderRight;
  }  
}
#endif /* END IF ((LA_CFG_EXT_LOWSPEEDFUSEDBRD) && (FCT_CFG_ROAD_INPUT)) */

/*************************************************************************************************************************
  Functionname:    LA_v_PerformO2OLaneAssociation                                                              */ /*!

  @brief           Main function for object-to-object (O2O) relation based lane association

  @description     Calls sub-functions for object-to-object (O2O) relation based lane association. As an initial 
                   implementation the sub-functions perform lane association for ego lane only, based on considerations 
                   of the object trace or its relation to other objects. In contrast to ego lane association
                   by O2O analysis, ego lane association by trace analysis is also possible when no second object
                   is close to the object under consideration.
                  @startuml
                  Partition LA_v_PerformO2OLaneAssociation{
                  Start
                  	partition LA_v_PerformEgoLaneByTraceAnalysis{
                  	-call to LA_v_PerformEgoLaneByTraceAnalysis
                  	}
                  	partition LA_v_PerformEgoLaneByO2OAnalysis{
                  	-call to LA_v_PerformEgoLaneByO2OAnalysis
                  	}
                  end
                  }
                  @enduml

  @return          -

  @param[in]       -

  @glob_in         -
  @glob_out        -

  @c_switch_part   LA_CFG_O2O_EGO_LANE_ASSOC : Compute object-to-object (O2O) relation based ego lane association
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         30.06.2016
  @changed         30.06.2016

  @todo            Compute distance of trace to VDY once for every trace object and store it for further usage.
                   Compute distance of object to road border and store it for further usage.

  @author          Grant Davtjan | Grant.Davtjan@continental-corporation.com | +49-8382-9699-633
*************************************************************************************************************************/
void LA_v_PerformO2OLaneAssociation (void)
{
#if (LA_CFG_O2O_EGO_LANE_ASSOC)
  /* update DTR specific trace dependent ego lane association */
  LA_v_PerformEgoLaneByTraceAnalysis();

  /* update DTR specific O2O ego lane association */
  LA_v_PerformEgoLaneByO2OAnalysis();
#endif
}

#if (LA_CFG_O2O_EGO_LANE_ASSOC)
/*************************************************************************************************************************
  Functionname:    LA_v_PerformEgoLaneByTraceAnalysis                                                              */ /*!

  @brief           Call main function for ego lane association by trace consideration for all moving objects and store result.

  @description     Loop over all moving objects and call function which checks if object can be assigned to ego lane
                   by consideration of its trace. In contrast to ego lane association by O2O analysis, ego lane association 
                   by trace analysis is also possible when no second object is close to the object under consideration.
                   @startuml
                   Partition LA_v_PerformEgoLaneByTraceAnalysis{
                   Start
                   	repeat 
                   	   if(object is moving) then (yes)
                   		   -trace-based ego lane association: save result of analysis
                   	   else
                   		   -no trace-based ego lane association for stationary objects
                   	   endif
                   	repeat while(for all objects to store result of ego lane association by trace analysis)
                   end
                   }
                   @enduml

  @return          -

  @param[in]       -

  @glob_in         *SLATE_pt_GetObjDynProperty(i) : Dynamic property of an object i [SLATE_t_Obj_DynamicProperty as in Rte_Type.h]
  @glob_out       t_LA_InternalObjectData[i].t_O2O_EgoLaneAssocStatus.b_TraceEgoLaneObj : Object i is on ego lane based on a trace analysis [TRUE, FALSE]

  @c_switch_part   -
  @c_switch_full   LA_CFG_O2O_EGO_LANE_ASSOC : Compute object-to-object (O2O) relation based ego lane association
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         30.06.2016
  @changed         21.07.2016

  @author          Grant Davtjan | Grant.Davtjan@continental-corporation.com | +49-8382-9699-633
*************************************************************************************************************************/
void LA_v_PerformEgoLaneByTraceAnalysis(void)
{
  ObjNumber_t t_ObjNrRel;

  /* Loop over all objects to store result of ego lane association by trace analysis */
  for (t_ObjNrRel = (ObjNumber_t)(EM_N_OBJECTS - 1) ; t_ObjNrRel >= 0; t_ObjNrRel--)
  {
    if (*SLATE_pt_GetObjDynProperty(t_ObjNrRel) == SLATE_OBJECT_PROPERTY_MOVING)
    {
      /* trace-based ego lane association: save result of analysis */
      t_LA_InternalObjectData[t_ObjNrRel].t_O2O_EgoLaneAssocStatus.b_TraceEgoLaneObj = LA_b_O2OCheckEgoLaneByObjTrace(t_ObjNrRel);
    }
    else
    {
      /* no trace-based ego lane association for stationary objects */
      t_LA_InternalObjectData[t_ObjNrRel].t_O2O_EgoLaneAssocStatus.b_TraceEgoLaneObj = FALSE;
    }
  }
}
#endif

#if (LA_CFG_O2O_EGO_LANE_ASSOC)
/*************************************************************************************************************************
  Functionname:    LA_b_O2OCheckEgoLaneByObjTrace                                                             */ /*!

  @brief           Checks if object can be associated to ego lane by consideration of its trace.

  @description     Check if object can be assigned to ego lane by consideration of its trace. The objects trace has 
                   to be available and long enough or reached the ego vehicle. The distance mean and standard deviation 
                   (as a measure of how parallel they are) of the objects trace to the VDY curve has to be below a threshold.
                   Also, no second object which could be overtaken has to be found in front of the object. Other
                   preconditions are: object shall not be fully occluded, road-VDY-delta shall not imply a strong curve entry
                   and the object distance to road border hint shall be fulfilled. Result of check is stored in
                   t_LA_InternalObjectData[i].t_O2O_EgoLaneAssocStatus.b_TraceEgoLaneObj.
                   @startuml
                   Partition LA_b_O2OCheckEgoLaneByObjTrace{
                   Start
                   	-Get Number of left lanes 
                   	-get trace ID
                   	if(trace ID is equal to TRACE NO OF TRACES) then (yes)
                   		-set Preconditions flag to false
                   	elseif(trace too short and has not reached ego) then (yes)
                   	    -set Preconditions flag to false
                   	elseif(object is fully occluded)then (yes)
                   	    -set Preconditions flag to false
                       elseif(road-VDY-delta implies a possible curve entry)then (yes)
                   	    -set Preconditions flag to false
                   	else
                   		-Get distance to road border criteria and store result in Preconditions flag
                   	endif
                   	
                   	if(Preconditions flag is True) then (yes)
                   		-Get trace mean distance to VDY course and its standard deviation for the object
                   	    if(Trace Ego Lane Object is true) then (yes)
                   			if(Object Longitudinal Displacement is greater than LA O2O TRACE DISTX FAR) then (yes)
                   				-Set Distance Mean Threshold to LA O2O TRACE DISTANCE MEAN DROP FAR
                                   -Set Distance Standerd Deviation Threshold to LA O2O TRACE STD DEV DROP FAR
                   			else
                   				-Set Distance Mean Threshold to LA O2O TRACE DIST MEAN DROP NEAR
                                   -Set Distance Standerd Deviation Threshold to LA O2O TRACE STD DEV DROP NEAR
                   			endif
                   			
                   		else
                   			-Set pick-up thresholds of trace mean distance and standard deviation 
                   		endif
                   		
                   		if(trace is close and parallel to the VDY curve) then (True)
                   			if(ego driving on the left most lane is overtaking )then (yes)
                   				-set "Get Check Ego Lane By Object Trace" to true
                   			else
                   				-Look for other close objects. Extend brackets only, when there are no ego lane objects which could be overtaken to avoid bad cut-outs due to bracket extension
                   		        if(possible overtaken object is found) then (yes)
                   					-set "Get Check Ego Lane By Object Trace" to true
                   				endif	
                   			endif
                                    			
                 		endif
                 	endif
                 		
                 end
                 }
                 @enduml


  @return          b_GetCheckEgoLaneByObjTrace : TRUE, if object is on ego lane by trace analysis [TRUE, FALSE]

  @param[in]       t_ObjNr : Input object No [-1 ... EM_N_OBJECTS-1]

  @glob_in         *(pt_LAInput->t_FIPMOT.pu_FIPStaticTraceID(i)) : Trace index of object i [full range of unsigned char data type]
  @glob_in         t_LA_InternalObjectData[i].t_O2O_EgoLaneAssocStatus.b_TraceEgoLaneObj : Object i is on ego lane based on a trace analysis? [TRUE, FALSE]
  @glob_in         pt_LAInput->t_RTE.pf_EgoCurve : Ego curve provided by VDY [-1 ... +1] m^-1
  @glob_in         *pt_LAInput->t_RTE.pf_ObjLongDisp  (i) : Longitudinal displacement of an object i  [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
  @glob_in         pt_LAInput->t_FIPMOT.pt_FIPMovObjStaticTrace(t_ObjTraceNr)->iNumberOfPoints : Get number of trace points [full range of signed char data type]
  @glob_in         pt_LAInput->pt_FIPRoad->t_FIPRoadFusedBorder.fDistLeft : Lateral ego distance to left road border [0.f ... 30.f] m
  @glob_in         pt_LAInput->pt_FIPRoad->t_FIPRoadFusedBorder.fDistRight : Lateral ego distance to right road border [-30.f ... 0.f] m
  @glob_in         ROAD_GET_BORDER_STAT_RIGHT : Right road border status [0u ... 100u]
  @glob_in         f_RoadVDYDeltaFar : Distance delta of road and VDY curves [full range of data type float32 >= 0.f]
  @glob_in         f_RoadVDYDeltaNear : Distance delta of road and VDY curves [full range of data type float32 >= 0.f]
  @glob_in         SLATE_p_GetEMGenObjAttributes(i)->eObjectOcclusion : Occlusion of object i [EM_t_GenObjOclusionState as in Rte_Type.h]
  @glob_in         pt_LAInput->t_RTE.pf_EgoVelObjSync : Ego velocity provided by VDY [-330.f ... 330.f] m/s

  @glob_out        -

  @c_switch_part   -
  @c_switch_full   LA_CFG_O2O_EGO_LANE_ASSOC : Compute object-to-object (O2O) relation based ego lane association
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         30.06.2016
  @changed         21.07.2016

  @todo            Inputs from FIP Road (pt_LAInput->t_FIPRoad) are available only if switch FCT_CFG_INPUT_PREPROCESSSING is 
                   on, which is not considered here. Switch for FCT_CFG_ROAD_INPUT to also be adapted.

  @author          Grant Davtjan | Grant.Davtjan@continental-corporation.com | +49-8382-9699-633
*************************************************************************************************************************/
static boolean LA_b_O2OCheckEgoLaneByObjTrace( const ObjNumber_t t_ObjNr )
{
  boolean b_GetCheckEgoLaneByObjTrace = FALSE; /* default return value */
  TraceID_t t_ObjTraceNr;                      /* index of trace belonging to object */

  boolean b_Preconditions;     /* flag signalizing fulfillment of preconditions for trace-based ego lane assignment*/
  float32 f_DistMeanThres;     /* threshold for the mean distance of object trace samples and VDY curve */
  float32 f_DistStdDevThres;   /* threshold for the standard deviation of distance of object trace samples and VDY curve */

  ObjNumber_t a_OvertakenObjID[LA_FIND_MOV_OBJ_IN_AREA_NUM_MAX]; /* Array of objects close to t_ObjNr. Needed to check if it is a possible cut-out object. */

  /* Variables for distance and parallelism of trace calculation */
  GDBTrafoMatrix2D_t MOT2EGO = GDBGetTrafoMatrixByDisplacement( FCT_fBumperToCoG, SLATE_f_GetSensorYPosition() ); // PRQA S 1031 
  /* date: 2016-07-04, reviewer: Davtjan, Grant reason: Allowed in later versions of ISO C99*/
  CPTrace2CurveParallelism_t  t_TraceVDYCurvePara_Obj; /* Variable stores distance and parallelism of object trace */

  /* Number of left lanes. As for high-speeds (> 140 kph) check is not needed on left lane (german autobahn). */
#if (FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING)
  /* Number of left lanes */
  const sint8 i_NumberOfLeftLanes = (pt_LAInput->pt_FIPLaneMatrix->s_NumOfLaneLeft);
#else
  /* assume one left lane when lane matrix not available */
  const sint8 i_NumberOfLeftLanes = (const sint8)1;
#endif

  /* get trace ID */
  t_ObjTraceNr = *(pt_LAInput->t_FIPMOT.pu_FIPStaticTraceID(t_ObjNr));
  if (t_ObjTraceNr >= (TraceID_t)TRACE_NO_OF_TRACES)
  {
    /* trace not available */
    b_Preconditions = FALSE;
  }
  else if ( ( (pt_LAInput->pt_FIPMOT->t_MovObjStaticTrace[t_ObjTraceNr].iNumberOfPoints > LA_O2O_TRACE_SAMPLES_MIN) || (pt_LAInput->pt_FIPMOT->t_MovObjStaticTrace[t_ObjTraceNr].Legacy.TraceReachEgoVeh == TRUE) ) == FALSE)
  {
    /* trace too short and has not reached ego */
    b_Preconditions = FALSE;
  }
  else if (SLATE_p_GetEMGenObjAttributes(t_ObjNr)->eObjectOcclusion == EM_GEN_OBJECT_OCCL_FULL)
  {
    /* object is fully occluded */
    b_Preconditions = FALSE;
  }
  else if ( (OBJ_GET_SI(t_ObjNr).b_TraceEgoLaneObj == FALSE)
         && ( (f_RoadVDYDeltaFar > LA_O2O_ROADVDYDELTA_FAR_HIGH )
         || (f_RoadVDYDeltaNear > LA_O2O_ROADVDYDELTA_NEAR_HIGH ) )
          )
  {
    /* road-VDY-delta implies a possible curve entry */
    b_Preconditions = FALSE;
  }
  else
  {
    /* Finally, check distance to road border criteria. Result is TRUE if it is possible that
       object is on ego lane based on its distance to road border */
    b_Preconditions = LA_b_O2OCheckRelObjBorderDistHint(t_ObjNr);
  }

  if (b_Preconditions == TRUE)
  {
    /* Get trace mean distance to VDY course and its standard deviation for the object */
    t_TraceVDYCurvePara_Obj = CPFusionTraceCalcTraceCircleParallelism( t_ObjTraceNr, *pt_LAInput->t_RTE.pf_EgoCurve, &MOT2EGO );

    /* Set thresholds of trace mean distance and standard deviation */
    if ( (t_LA_InternalObjectData[t_ObjNr].t_O2O_EgoLaneAssocStatus.b_TraceEgoLaneObj == TRUE) )
    {
      /* Drop threshold dependent on object longitudinal distance */
      if (*pt_LAInput->t_RTE.pf_ObjLongDisp(t_ObjNr) > LA_O2O_TRACE_DISTX_FAR )
      {
        f_DistMeanThres   = LA_O2O_TRACE_DIST_MEAN_DROP_FAR;
        f_DistStdDevThres = LA_O2O_TRACE_STD_DEV_DROP_FAR;
      }
      else
      {
        f_DistMeanThres   = LA_O2O_TRACE_DIST_MEAN_DROP_NEAR;
        f_DistStdDevThres = LA_O2O_TRACE_STD_DEV_DROP_NEAR;
      }
    }
    else
    {
      /* Set pick-up thresholds of trace mean distance and standard deviation */
      f_DistMeanThres   = LA_O2O_TRACE_DIST_MEAN_PICKUP;
      f_DistStdDevThres = LA_O2O_TRACE_STD_DEV_PICKUP;
    }

    /* For trace-based ego lane assignment trace has to be close and parallel to the VDY curve */
    if ( (fABS(t_TraceVDYCurvePara_Obj.fDistMean) < f_DistMeanThres )
      && (t_TraceVDYCurvePara_Obj.fDistStdDev < f_DistStdDevThres ) )
    {
      /* following check is not needed for high velocities on german autobahn */
      /* as ego driving on the left most lane is always overtaking */
      if ( ((*pt_LAInput->t_RTE.pf_EgoVelObjSync) > (LA_O2O_HIGHSPEED))
        && ( (i_NumberOfLeftLanes == (sint8)0) 
        || ((pt_LAInput->pt_FIPRoad->t_FIPRoadFusedBorder.fDistLeft)  < LA_O2O_BORDER_DIST_CLOSE)
          || ((i_NumberOfLeftLanes == (sint8)-1) 
          && ((pt_LAInput->pt_FIPRoad->t_FIPRoadFusedBorder.fDistRight) < -LA_O2O_BORDER_DIST_FAR)
            && ((pt_LAInput->pt_FIPRoad->t_FIPRoadFusedBorder.bStatusRight) >= LA_O2O_BORDER_STATUS_MIN)
             )
           )
         )
      {
        b_GetCheckEgoLaneByObjTrace = TRUE;
      }
      else
      {
        /* Look for other close objects. Extend brackets only, when there are no ego lane objects which could be overtaken
        to avoid bad cut-outs due to bracket extension */
#if (LA_CFG_AVOID_SPILT_OBJ)
        LA_v_FindObjInArea(a_OvertakenObjID, t_ObjNr, &LAEgoLaneByObjTraceArgs, FALSE);
#else
        LA_v_FindObjInArea(a_OvertakenObjID, t_ObjNr, &LAEgoLaneByObjTraceArgs);
#endif /*LA_CFG_AVOID_SPILT_OBJ*/

        /* Check if possible overtaken object has been found */
        if (a_OvertakenObjID[0] == (ObjNumber_t)-1)
        {
          b_GetCheckEgoLaneByObjTrace = TRUE;
        }
      }
    }
  }

  return b_GetCheckEgoLaneByObjTrace;
}
#endif

#if (LA_CFG_O2O_EGO_LANE_ASSOC)
/*************************************************************************************************************************
  Functionname:    LA_v_PerformEgoLaneByO2OAnalysis                                                              */ /*!

  @brief           Call main function for ego lane association by object-to-object (O2O) relation consideration 
                   for all moving objects and store result.

  @description     Loop over all moving objects and call function which checks if object can be assigned to ego lane
                   by consideration of its relation to other objects (O2O). In contrast to ego lane association by trace analysis, 
                   ego lane association by O2O analysis requires a second object close to the object under consideration.
                   For O2O analysis we compare two objects with each other. The object currently under consideration i.e 
                   the one which is selected in the outer loop is denoted as the "relevant" object. This notion is not related
                   to the identical term known from object-of-interest (OOI) selection process/interface. Actually,
                   the O2O ego lane association process is completely independent of the OOI-selection state of an object.
                   @startuml
                   Partition LA_v_PerformEgoLaneByO2OAnalysis{
                   Start
                   	repeat
                   		if(object is moving) then (yes)
                   			-O2O ego lane association: save result of analysis
                   		else
                   			-no O2O ego lane association for stationary objects
                   		endif
                   	repeat while(all objects to store result of ego lane association by O2O analysis)
                   end
                   }
                   @enduml

  @return          -

  @param[in]       -

  @glob_in         *SLATE_pt_GetObjDynProperty(i) : Dynamic property of an object i [SLATE_t_Obj_DynamicProperty as in Rte_Type.h]
  @glob_out        t_LA_InternalObjectData[i].t_O2O_EgoLaneAssocStatus.b_O2OEgoLaneObj : Object i is on ego lane based on a O2O analysis? [TRUE, FALSE]

  @c_switch_part   -
  @c_switch_full   LA_CFG_O2O_EGO_LANE_ASSOC : Compute object-to-object (O2O) relation based ego lane association
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         30.06.2016
  @changed         21.07.2016

  @todo            Parameters have been optimized for ARS440/DTR (a pick up distance of time-gap < 4 sec and minimum 80m).
                   Generalize O2O analysis so that it is also suitable for association on other lanes and for other projects.

  @author          Grant Davtjan | Grant.Davtjan@continental-corporation.com | +49-8382-9699-633
*************************************************************************************************************************/
void LA_v_PerformEgoLaneByO2OAnalysis(void)
{
  ObjNumber_t t_ObjNrRel; /* relevant object under consideration */

  /* Loop over all objects to store result of ego lane association by O2O analysis */
  for (t_ObjNrRel = (ObjNumber_t)(EM_N_OBJECTS - 1) ; t_ObjNrRel >= 0; t_ObjNrRel--)
  {
    if (*SLATE_pt_GetObjDynProperty(t_ObjNrRel) == SLATE_OBJECT_PROPERTY_MOVING)
    {
      /* O2O ego lane association: save result of analysis */
      t_LA_InternalObjectData[t_ObjNrRel].t_O2O_EgoLaneAssocStatus.b_O2OEgoLaneObj = LA_b_O2OCheckEgoLaneByO2O(t_ObjNrRel);
    }
    else
    {
      /* no O2O ego lane association for stationary objects */
      t_LA_InternalObjectData[t_ObjNrRel].t_O2O_EgoLaneAssocStatus.b_O2OEgoLaneObj = FALSE;
    }
  }
}
#endif

#if (LA_CFG_O2O_EGO_LANE_ASSOC)
/*************************************************************************************************************************
  Functionname:    LA_b_O2OCheckEgoLaneByO2O                                                             */ /*!

  @brief           Checks if object can be assigned to ego lane by consideration of its object-to-object (O2O) relation.

  @description     The object currently under consideration i.e the one which is selected in the outer loop is denoted 
                   as the "relevant" object in the context of this O2O analysis. First, we check if the relevant object fulfills 
                   criteria for selection as O2O ego lane object. These criteria are: a distance to trajectory criteria, 
                   an occlusions criteria, its trace criteria, its distance to the road border and a cut-out observer.
                   Second, we check the O2O criteria i.e. those criteria where we compare the relevant object with other
                   neighboring moving objects. Those O2O criteria are checked in the sub-function LA_t_O2OFindNeighboringO2OObject.
                   All of the relevant object related and O2O related criteria (denoted hints) need to be fulfilled for
                   an ego lane association. In some of the criteria a hysteresis is included which is triggered on the 
                   output of the O2O ego lane decision which is stored in t_LA_InternalObjectData[i].t_O2O_EgoLaneAssocStatus.b_O2OEgoLaneObj.
                   @startuml
Partition LA_b_O2OCheckEgoLaneByO2O{
Start
	-Get relevant object trace ID
	-Check relevant object distance to trajectory hint
	if(O2O Ego Lane Object is false) then (yes)
		if(Object Occlusion is high or Occluded By Trace is 0) then (yes)
			-hint Relevant Object Occluded is false
		endif
	else
		if(Object Occlusion is high and Object Longitudinal Displacement is less than LA O2O RELOBJ OCCL DROP DISTX MAX)
			-hint Relevant Object Occluded is false*
		endif
	endif
	
	if(trace exists and lateral difference between ego-position and trace is huge)then (yes)
		-object is not considered to avoid long drop-ins from neighboring lane
	else
		if(trace is not available for the relevant object) then (yes)
			if(relevant object trace is not available for ego lane association) then (yes)
				-hint Relevant Object Occluded is false
			endif
		endif
	endif
	
	if(Tunnel Probability is less than Tunnel Probability threshold) then (yes)
		-Check relevant object distance to trajectory hint
	endif
	
	if(Object Longitudinal Displacement is less than LA O2O RELOBJ CUTOUT DISTX MAX)then (yes)
		-Check relevant object distance to trajectory hint
	endif
	
	if(hint Relevant Object Distance To Trajectory, Occluded, Trace, BorderDist and CutOut is TRUE) then (yes)
		-Find Neighboring O2OO bject
	else
		-overwrite O2O hint flags if relevant object specific hints not fulfilled
	endif
    -store relevant object specific hint information 
	if(Object Ego Lane By O2O is not equal to OBJECT INDEX NO OBJECT) then(yes)
		-Object is on ego lane based on O2O analysis
	else
		-Object is not assigned to ego lane based on O2O analysis
	endif
end
}
@enduml

  @return          b_GetCheckEgoLaneByO2O :  TRUE, if object is on ego lane by O2O analysis [TRUE, FALSE]

  @param[in]       t_ObjNrRel : Input "relevant" object No [-1 ... EM_N_OBJECTS-1]

  @glob_in         *(pt_LAInput->t_FIPMOT.pu_FIPStaticTraceID(i)) : Trace index of object i [full range of unsigned char data type]
  @glob_in         pt_LAInput->t_RTE.pf_EgoCurve : Ego curve provided by VDY [-1 ... +1] m^-1
  @glob_in         pt_LAInput->t_FIPMOT.pt_FIPMovObjStaticTrace(i)->iNumberOfPoints : Get number of trace points [full range of signed char data type]
  @glob_in         *pt_LAInput->t_RTE.pf_TunnelProbability : Probability for a tunnel [0.0f ... 1.0f]
  @glob_in         SLATE_p_GetEMGenObjAttributes(i)->eObjectOcclusion : Occlusion of object i [EM_t_GenObjOclusionState as in Rte_Type.h]
  @glob_in         pt_LAInput->t_SIT.pt_ObjBool(t_ObjNrRel)->OccludedByTrace : Object i is occluded based on a trace analysis? [TRUE, FALSE]
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   LA_CFG_O2O_EGO_LANE_ASSOC : Compute object-to-object (O2O) relation based ego lane association
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         30.06.2016
  @changed         21.07.2016

  @author          Grant Davtjan | Grant.Davtjan@continental-corporation.com | +49-8382-9699-633
*************************************************************************************************************************/
static boolean LA_b_O2OCheckEgoLaneByO2O( const ObjNumber_t t_ObjNrRel )
{
  ObjNumber_t t_ObjNrEgoLaneByO2O = OBJ_INDEX_NO_OBJECT; /* default: no O2O object assigning relevant object to ego lane */
  boolean b_GetCheckEgoLaneByO2O  = FALSE;                /* default return value */

  /* Relevant object only hints. Object-to-object (O2O) relation based hints will be checked only if
  relevant object fulfills all criteria */
  boolean b_hintRelObjDistToTraj    = TRUE;   /* hint that the relevant object is close to trajectory */
  boolean b_hintRelObjOccluded      = TRUE;   /* hint that the relevant object is occluded */
  boolean b_hintRelObjTrace         = TRUE;   /* hint that the object drives on ego lane */
  boolean b_hintRelObjBorderDist    = TRUE;   /* hint that the relevant object is far from road border */
  boolean b_hintRelObjCutOut        = TRUE;   /* hint that the relevant object is performing a cut-out */

  /* Get relevant object trace ID */
  TraceID_t t_RelTraceNr = *(pt_LAInput->t_FIPMOT.pu_FIPStaticTraceID(t_ObjNrRel));

  /* Check relevant object distance to trajectory hint */
  b_hintRelObjDistToTraj = LA_b_O2OCheckRelObjDistToTrajHint(t_ObjNrRel);

  /* if target object is occluded the risk for drop ins from neighboring lane is high.
  Therefore, the bracket extension is inactive for occluded objects */
  if (t_LA_InternalObjectData[t_ObjNrRel].t_O2O_EgoLaneAssocStatus.b_O2OEgoLaneObj == FALSE)
  {
    if ( (SLATE_p_GetEMGenObjAttributes(t_ObjNrRel)->eObjectOcclusion == EM_GEN_OBJECT_OCCL_FULL)
      || (pt_LAInput->t_SIT.pt_ObjBool(t_ObjNrRel)->OccludedByTrace == 0u)
    {
      b_hintRelObjOccluded = FALSE;
    }
  }
  else /* (t_LA_InternalObjectData[t_ObjNrRel].t_O2O_EgoLaneAssocStatus.b_O2OEgoLaneObj == TRUE) */
  {
    if ( (SLATE_p_GetEMGenObjAttributes(t_ObjNrRel).eObjectOcclusion == EM_GEN_OBJECT_OCCL_FULL)
      && (*pt_LAInput->t_RTE.pf_ObjLongDisp(t_ObjNrRel) < LA_O2O_RELOBJ_OCCL_DROP_DISTX_MAX) )
    {
      b_hintRelObjOccluded = FALSE;
    }
  }

  /* If trace exists and lateral difference between ego-position and trace is huge 
  object is not considered to avoid long drop-ins from neighboring lane */
  if ( (t_RelTraceNr < (TraceID_t)TRACE_NO_OF_TRACES)
    && (pt_LAInput->pt_FIPMOT->t_MovObjStaticTrace[t_RelTraceNr].iNumberOfPoints > LA_O2O_RELOBJ_TRACE_SAMPLES_MIN)
    )
  {
    b_hintRelObjTrace = LA_b_O2OCheckRelObjTraceHint(t_ObjNrRel);
  }
  else
  {
    /* if trace is not available for the relevant object do following checks */

    if (fABS(*pt_LAInput->t_RTE.pf_EgoCurve) > LA_O2O_STRONG_CURVE_CURVATURE)
    {
      /* in curve exit relevant object trace should be available for ego lane association*/
      if ( (f_RoadVDYDeltaFar > LA_O2O_ROADVDYDELTA_FAR_HIGH)
        || (f_RoadVDYDeltaNear > LA_O2O_ROADVDYDELTA_NEAR_HIGH) )
      {
        b_hintRelObjTrace = FALSE;
      }
    }
  }

  /* check corridor between object and road border outside of tunnels */
  if (*pt_LAInput->t_RTE.pf_TunnelProbability < LA_TUNNEL_PROB_THRES)
  {
    b_hintRelObjBorderDist = LA_b_O2OCheckRelObjBorderDistHint(t_ObjNrRel);
  }

  /* Avoid late release of an O2O ego lane object which is performing a cut-out behind another 
  object */
  if (*pt_LAInput->t_RTE.pf_ObjLongDisp(t_ObjNrRel) < LA_O2O_RELOBJ_CUTOUT_DISTX_MAX)
  {
  b_hintRelObjCutOut = LA_b_O2OCheckRelObjCutOutHint(t_ObjNrRel);
  }

  /* Loop over all objects for O2O specific hints. */
  /* Loop only if both relevant object specific criteria fulfilled. */
  if ( (b_hintRelObjDistToTraj == TRUE)
    && (b_hintRelObjOccluded   == TRUE)
    && (b_hintRelObjTrace      == TRUE) 
    && (b_hintRelObjBorderDist == TRUE)
    && (b_hintRelObjCutOut     == TRUE)
     )
  {
    t_ObjNrEgoLaneByO2O = LA_t_O2OFindNeighboringO2OObject(t_ObjNrRel);
  }
#ifdef FCT_SIMU
  else
  {
    /* overwrite O2O hint flags if relevant object specific hints not fulfilled */
    t_LA_InternalObjectData[t_ObjNrRel].t_O2ODebugInfo.b_hintO2ODoubleObject   = FALSE;
    t_LA_InternalObjectData[t_ObjNrRel].t_O2ODebugInfo.b_hintO2OMirror         = FALSE;
    t_LA_InternalObjectData[t_ObjNrRel].t_O2ODebugInfo.b_hintO2OLaneMatrix     = FALSE;
    t_LA_InternalObjectData[t_ObjNrRel].t_O2ODebugInfo.b_hintO2OVrel           = FALSE;
    t_LA_InternalObjectData[t_ObjNrRel].t_O2ODebugInfo.b_hintO2OTraceDistances = FALSE;
    t_LA_InternalObjectData[t_ObjNrRel].t_O2ODebugInfo.b_hintO2OPosition       = FALSE;
    t_LA_InternalObjectData[t_ObjNrRel].t_O2ODebugInfo.t_ObjNrEgoLaneByO2O     = OBJ_INDEX_NO_OBJECT;
  }

  /* store relevant object specific hint information */
   t_LA_InternalObjectData[t_ObjNrRel].t_O2ODebugInfo.b_hintRelObjDistToTraj = b_hintRelObjDistToTraj;
   t_LA_InternalObjectData[t_ObjNrRel].t_O2ODebugInfo.b_hintRelObjOccluded   = b_hintRelObjOccluded;
   t_LA_InternalObjectData[t_ObjNrRel].t_O2ODebugInfo.b_hintRelObjTrace      = b_hintRelObjTrace;
   t_LA_InternalObjectData[t_ObjNrRel].t_O2ODebugInfo.b_hintRelObjBorderDist = b_hintRelObjBorderDist;
   t_LA_InternalObjectData[t_ObjNrRel].t_O2ODebugInfo.b_hintRelObjCutOut     = b_hintRelObjCutOut;
#endif

  /* Save result of O2O analysis for relevant object */
  if (t_ObjNrEgoLaneByO2O != OBJ_INDEX_NO_OBJECT)
  {
    /* Object is on ego lane based on O2O analysis */
    b_GetCheckEgoLaneByO2O = TRUE;
  }
  else
  {
    /* Object is not assigned to ego lane based on O2O analysis */
    b_GetCheckEgoLaneByO2O = FALSE;
  }

  return b_GetCheckEgoLaneByO2O;
}
#endif

#if (LA_CFG_O2O_EGO_LANE_ASSOC)
/*************************************************************************************************************************
  Functionname:    LA_b_O2OCheckRelObjDistToTrajHint                                                             */ /*!

  @brief           Checks object-to-object (O2O) relation based ego lane association distance to trajectory hint.

  @description     Function checks if relevant object is close enough to the SI trajectory for
                   ego lane association by O2O analysis.
                   @startuml
                   Partition LA_b_O2OCheckRelObjDistToTrajHint{
                   Start
                   	-get relevant object distance to trajectory
                   	if(longitudinal distance is greater than LA O2O RELOBJ DIST2TRAJ DISTX FAR) then (yes)
                   		-Relevant Distance To Trajectory Threshold is set to LA O2O RELOBJ DIST2TRAJ PICKUP FAR;
                   	elseif(longitudinal distance is greater than LA O2O RELOBJ DIST2TRAJ DISTX MID)
                   		-Relevant Distance To Trajectory Threshold is set to LA O2O RELOBJ DIST2TRAJ PICKUP MID
                       else
                   		-Relevant Distance To Trajectory Threshold is set to LA O2O RELOBJ DIST2TRAJ PICKUP CLOSE
                   	endif
                   	
                   	if(O2O Ego Lane Object is true)then (yes)
                   		-calculate Hysteresis of threshold
                   	endif
                   
                       if(relative distance to trajectory is greater than trajectory threshold)then (yes)
                   		-set distance to trajectory to false
                   	endif
                   end
                   }
                   @enduml

  @return          boolean : TRUE, if criteria fulfilled [TRUE, FALSE]

  @param[in]       t_ObjNrRel : Input "relevant" object No [-1 ... EM_N_OBJECTS-1]

  @glob_in         t_LA_InternalObjectData[i].t_O2O_EgoLaneAssocStatus.b_O2OEgoLaneObj : Object i is on ego lane based on a object-to-object (O2O) relation analysis? [TRUE, FALSE]
  @glob_in         *pt_LAInput->t_RTE.pf_ObjLongDisp  (i) : Longitudinal displacement of an object i [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
  @glob_in         OBJ_GET_CP(i).TrajDist : Structure of type CPObjDist2Traj_t, Information about objects relation to estimated course. Defined in cp_ext.h
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   LA_CFG_O2O_EGO_LANE_ASSOC : Compute object-to-object (O2O) relation based ego lane association
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @todo            Consider also curvature (and curve entry) dependence of distance to trajectory

  @created         30.06.2016
  @changed         21.07.2016

  @author          Grant Davtjan | Grant.Davtjan@continental-corporation.com | +49-8382-9699-633
*************************************************************************************************************************/
static boolean LA_b_O2OCheckRelObjDistToTrajHint( const ObjNumber_t t_ObjNrRel )
{
  boolean b_hintRelObjDistToTraj = TRUE; /* default return value */

  float32 f_RelDistToTraj;           /* lateral distance between relevant object and ACC trajectory */
  float32 f_RelDistToTrajThres;      /* relevant object distance to trajectory threshold */

  /* get relevant object distance to trajectory */
  f_RelDistToTraj = pt_LAOutput->t_LAObjOutputList[t_ObjNrRel].TrajDist[t_ObjNrRel].TrajDistMeas.Y.f0;

  /* longitudinal distance dependent threshold */
  if (*pt_LAInput->t_RTE.pf_ObjLongDisp(t_ObjNrRel) > LA_O2O_RELOBJ_DIST2TRAJ_DISTX_FAR)
  {
    f_RelDistToTrajThres   = LA_O2O_RELOBJ_DIST2TRAJ_PICKUP_FAR;
  }
  else if (*pt_LAInput->t_RTE.pf_ObjLongDisp(t_ObjNrRel) > LA_O2O_RELOBJ_DIST2TRAJ_DISTX_MID)
  {
    f_RelDistToTrajThres   = LA_O2O_RELOBJ_DIST2TRAJ_PICKUP_MID;
  }
  else /* (*pt_LAInput->t_RTE.pf_ObjLongDisp(t_ObjNrRel) > 80.f) */
  {
    f_RelDistToTrajThres   = LA_O2O_RELOBJ_DIST2TRAJ_PICKUP_CLOSE;
  }

  /* Hysteresis of threshold */ 
  if (t_LA_InternalObjectData[t_ObjNrRel].t_O2O_EgoLaneAssocStatus.b_O2OEgoLaneObj == TRUE)
  {
    f_RelDistToTrajThres = f_RelDistToTrajThres + LA_O2O_RELOBJ_DIST2TRAJ_THRES_HYST;
  }

  /* Check distance to trajectory criteria */ 
  if (fABS(f_RelDistToTraj) > f_RelDistToTrajThres)
  {
    b_hintRelObjDistToTraj = FALSE;
  }

  return b_hintRelObjDistToTraj;
}
#endif

#if (LA_CFG_O2O_EGO_LANE_ASSOC)
/*************************************************************************************************************************
  Functionname:    LA_b_O2OCheckRelObjTraceHint                                                             */ /*!

  @brief           Checks object-to-object (O2O) relation based ego lane association relevant object trace hint.

  @description     Function shall be called only if relevant object's trace is available and has minimum length for
                   computation of mean and standard deviation of trace sample distance to VDY curve. 
                   For fulfillment of this criteria the trace sample mean distance to the VDY curve and its standard 
                   deviation have to indicate that the object is close to the ego path and parallel.
                   Also, if the trace has reached ego its y-intersection should be close to ego. 
                   An additional and more stringent check is done when ego is on mid lane to avoid drop-ins.
                   @startuml
Partition LA_b_O2OCheckRelObjTraceHint{
Start
	-Get Number of left and right lane
	-Get relevant object trace ID
	-Get trace mean distance to VDY course and its standard deviation for relevant object
	if(Check if object trace intersection is too far away) then (yes)
		-set hint Relevant Object Trace to false
	endif
	
	if(O2O Ego Lane Object is true)
	    if(Object Longitudinal Displacement is greater than LA O2O RELOBJ TRACE STD DEV DISTX FAR or 
	   Tunnel Probability is greater than Tunnel Probability threshold or
	   Ego Curve  is greater than LA O2O CURVY ROAD CURVATURE) then (yes)
			-situation dependent increase of drop threshold to avoid drop-outs
		else
			-set standerd Deviation Threshold to LA O2O RELOBJ TRACE STD DEV DROP
		endif
	elseif(Object Longitudinal Displacement is greater than LA O2O RELOBJ RACE STD DEV DISTX FAR)then (yes)
        -Increase threshold in tunnel
	elseif() then (yes)
		-set standerd Deviation Threshold to far pick-up threshold
	else
		-set standerd Deviation Threshold to near pick-up threshold
	endif
	if(standard deviation distance is greater than standerd Deviation Threshold ) then (yes)
		-set hint Relevant Object Trace to false
	endif
	
	if(ego curve is less than Curve threshold in O2O module) then (yes)
		if(Object Longitudinal Displacement is less than dist-x above which less stringent thresholds are used for mean distance) then (yes)
			-set distance mean threshold to near threshold of mean trace sample orthogonal distance to VDY curve on straight roads
		elseif(Object Longitudinal Displacement is less than dist-x above which the least stringent thresholds are used for mean distance)then (yes)
			-set distance mean threshold to mid threshold of mean trace sample orthogonal distance to VDY curve on straight roads
	    else
			-set distance mean threshold to far threshold of mean trace sample orthogonal distance to VDY curve on straight roads
		endif
	else
		if(Object Longitudinal Displacement is less than dist-x above which less stringent thresholds are used for mean distance) then (yes)
			-set distance mean threshold to near threshold of mean trace sample orthogonal distance to VDY curve on curvy roads
		else
			-set distance mean threshold to far threshold of mean trace sample orthogonal distance to VDY curve on curvy roads
		endif	
	endif
	
	if(mean distance is greater than distance mean threshold and Number Of Left Lanes is not 0) then (yes)
		- Object trace mean is too far to the left for O2O ego lane association
	elseif(mean distance is less than negative distance mean threshold and Number Of right Lanes is not 0) then (yes)
	    -Object trace mean is too far away to the right for O2O ego lane association
	else
		-Do nothing
	endif
	
	if(O2O Ego Lane Object is false) then (yes)
		-for higher mean distances the standard deviation criteria is more stringent
		if(standard deviation distance is greater than standerd Deviation Threshold ) then (yes)
			-set hint Relevant Object Trace to false
		endif
	endif
	
	if(ego is driving on mid lane) then (yes)
		if(trace is short and not very close) then (yes)
			-set hint Relevant Object Trace to false
		endif
		
		if( road-VDY-delta implies a possible curve entry)then (yes)
			-set hint Relevant Object Trace to false
		endif
	endif

end
}
@enduml

  @return          boolean : TRUE, if criteria fulfilled [TRUE, FALSE]

  @param[in]       t_ObjNrRel : Input "relevant" object No [-1 ... EM_N_OBJECTS-1]

  @glob_in         *(pt_LAInput->t_FIPMOT.pu_FIPStaticTraceID(i)) : Trace index of object i [full range of unsigned char data type]
  @glob_in         t_LA_InternalObjectData[i].t_O2O_EgoLaneAssocStatus.b_O2OEgoLaneObj : Object i is on ego lane based on a object-to-object (O2O) relation analysis? [TRUE, FALSE]
  @glob_in         pt_LAInput->t_FIPMOT.pt_FIPMovObjStaticTrace(i)->Legacy.TraceReachEgoVeh : Boolean variable, Trace reached ego vehicle? [TRUE, FALSE]
  @glob_in         pt_LAInput->t_FIPMOT.pt_FIPMovObjStaticTrace(i)->fYIntersection : Get y intersection of given trace [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @glob_in         FCT_fBumperToCoG : distance from Bumper to Center of Gravity [full range of data type float32 >= 0.F]
  @glob_in         SLATE_f_GetSensorYPosition() : Sensor mounting lateral position [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @glob_in         pt_LAInput->t_RTE.pf_EgoCurve : Ego curve provided by VDY [-1 ... +1] m^-1
  @glob_in         *pt_LAInput->t_RTE.pf_ObjLongDisp  (i) : Longitudinal displacement of an object i [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
  @glob_in         pt_LAInput->t_FIPMOT.pt_FIPMovObjStaticTrace(i)->iNumberOfPoints : Get number of trace points [full range of signed char data type]
  @glob_in         *pt_LAInput->t_RTE.pf_TunnelProbability : Probability for a tunnel [0.0f ... 1.0f]
  @glob_in         f_RoadVDYDeltaFar : Distance delta of road and VDY curves [full range of data type float32 >= 0.f]
  @glob_in         f_RoadVDYDeltaNear : Distance delta of road and VDY curves [full range of data type float32 >= 0.f]

  @glob_out        -

  @c_switch_part   FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING : FCT Input Preprocessing Lane matrix
  @c_switch_full   LA_CFG_O2O_EGO_LANE_ASSOC : Compute object-to-object (O2O) relation based ego lane association
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         30.06.2016
  @changed         21.07.2016

  @author          Grant Davtjan | Grant.Davtjan@continental-corporation.com | +49-8382-9699-633
*************************************************************************************************************************/
static boolean LA_b_O2OCheckRelObjTraceHint( const ObjNumber_t t_ObjNrRel )
{
  boolean b_hintRelObjTrace = TRUE; /* default return value */
  TraceID_t t_RelTraceNr;           /* index of trace belonging to relevant object*/

  /* Situation dependent thresholds */
  float32 f_RelTraceDistStdDevThres;       /* relevant object trace samples to VDY distance standard deviation threshold */
  float32 f_RelTraceDistMeanThres;         /* relevant object trace samples to VDY distance mean threshold */
  float32 f_TraceMeanDependentStdDevThres; /* trace-VDY distance standard deviation threshold which is dependent on mean distance */

#if (FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING)
  /* Number of left an right lanes */
  const sint8 i_NumberOfLeftLanes = (pt_LAInput->pt_FIPLaneMatrix->s_NumOfLaneLeft);
  const sint8 i_NumberOfRightLanes = (pt_LAInput->pt_FIPLaneMatrix->s_NumOfLaneRight);
#else
  /* assume one left and right lane when lane matrix not available */
  const sint8 i_NumberOfLeftLanes = (const sint8)1;
  const sint8 i_NumberOfRightLanes = (const sint8)1;
#endif

  /* Variables for distance and parallelism of trace calculation */
  GDBTrafoMatrix2D_t MOT2EGO = GDBGetTrafoMatrixByDisplacement( FCT_fBumperToCoG, SLATE_f_GetSensorYPosition() ); // PRQA S 1031 
  /* date: 2016-07-04, reviewer: Davtjan, Grant reason: Allowed in later versions of ISO C99*/
  CPTrace2CurveParallelism_t t_TraceVDYCurvePara_Rel; /* Variable stores distance and parallelism of relevant object trace */

  /* Get relevant object trace ID */
  t_RelTraceNr = *(pt_LAInput->t_FIPMOT.pu_FIPStaticTraceID(t_ObjNrRel));
  /* Get trace mean distance to VDY course and its standard deviation for relevant object */
  t_TraceVDYCurvePara_Rel = CPFusionTraceCalcTraceCircleParallelism( t_RelTraceNr, *pt_LAInput->t_RTE.pf_EgoCurve, &MOT2EGO );

  /* 1. Check if object trace intersection is too far away */
  if ( ( (t_LA_InternalObjectData[ObjNr].t_O2O_EgoLaneAssocStatus.b_O2OEgoLaneObj == FALSE) 
      || (t_TraceVDYCurvePara_Rel.fDistStdDev < LA_O2O_RELOBJ_TRACE_Y_INTERSEC_STD_DEV_MAX)
       )
  && (pt_LAInput->pt_FIPMOT->t_MovObjStaticTrace[t_RelTraceNr].Legacy.TraceReachEgoVeh == TRUE)
    && (fABS(pt_LAInput->pt_FIPMOT->t_MovObjStaticTrace[t_RelTraceNr].fYIntersection > LA_O2O_RELOBJ_TRACE_Y_INTERSEC_ABS_MAX)
    )
  {
    b_hintRelObjTrace = FALSE;
  }

    /* 2. Check if trace standard deviation criteria fulfilled */
    /* Set standard deviation of trace threshold */
    if (t_LA_InternalObjectData[t_ObjNrRel].t_O2O_EgoLaneAssocStatus.b_O2OEgoLaneObj == TRUE)
    {
      /* Hysteresis of threshold */
      if ( (*pt_LAInput->t_RTE.pf_ObjLongDisp(t_ObjNrRel) > LA_O2O_RELOBJ_TRACE_STD_DEV_DISTX_FAR)
        || (*pt_LAInput->t_RTE.pf_TunnelProbability > LA_TUNNEL_PROB_THRES) 
        || (fABS(*pt_LAInput->t_RTE.pf_EgoCurve) > LA_O2O_CURVY_ROAD_CURVATURE) 
         )
      {
        /* situation dependent increase of drop threshold to avoid drop-outs */
        f_RelTraceDistStdDevThres = LA_O2O_RELOBJ_TRACE_STD_DEV_DROP_FAR;
      }
      else
      {
        f_RelTraceDistStdDevThres = LA_O2O_RELOBJ_TRACE_STD_DEV_DROP;
      }
    }
    else if (*pt_LAInput->t_RTE.pf_TunnelProbability > LA_TUNNEL_PROB_THRES)
    {
      /* Increase threshold in tunnel */
      f_RelTraceDistStdDevThres = LA_O2O_RELOBJ_TRACE_STD_DEV_PICKUP_TUNNEL;
    }
    /* Increase threshold in high distances */
    else if (*pt_LAInput->t_RTE.pf_ObjLongDisp(t_ObjNrRel) > LA_O2O_RELOBJ_TRACE_STD_DEV_DISTX_FAR)
    {
      f_RelTraceDistStdDevThres = LA_O2O_RELOBJ_TRACE_STD_DEV_PICKUP_FAR;
    }
    else
    {
      f_RelTraceDistStdDevThres = LA_O2O_RELOBJ_TRACE_STD_DEV_PICKUP;
    }

    /* Check threshold for standard deviation which is a measure of parallelism */
    if (t_TraceVDYCurvePara_Rel.fDistStdDev > f_RelTraceDistStdDevThres)
    {
      b_hintRelObjTrace = FALSE;
    }

    /* 3. Check if trace mean distance criteria fulfilled */
    /* Set threshold value for mean distance criteria */
    if (fABS(*pt_LAInput->t_RTE.pf_EgoCurve) < LA_O2O_CURVY_ROAD_CURVATURE)
    {
      /* Set threshold for mean distance of trace on straight road */
      if (*pt_LAInput->t_RTE.pf_ObjLongDisp(t_ObjNrRel) < LA_O2O_RELOBJ_TRACE_DIST_MEAN_DISTX_MID)
      {
        f_RelTraceDistMeanThres = LA_O2O_RELOBJ_TRACE_DIST_MEAN_CLOSE_STRAIGHT;
      }
      else if (*pt_LAInput->t_RTE.pf_ObjLongDisp(t_ObjNrRel) < LA_O2O_RELOBJ_TRACE_DIST_MEAN_DISTX_FAR)
      {
        f_RelTraceDistMeanThres = LA_O2O_RELOBJ_TRACE_DIST_MEAN_MID_STRAIGHT;
      }
      else
      {
        f_RelTraceDistMeanThres = LA_O2O_RELOBJ_TRACE_DIST_MEAN_FAR_STRAIGHT;
      }
    }
    else
    {
      /* Set threshold for mean distance of trace on curvy road */
      if (*pt_LAInput->t_RTE.pf_ObjLongDisp(t_ObjNrRel) < LA_O2O_RELOBJ_TRACE_DIST_MEAN_DISTX_MID)
      {
        f_RelTraceDistMeanThres = LA_O2O_RELOBJ_TRACE_DIST_MEAN_CLOSE_CURVY;
      }
      else
      {
        f_RelTraceDistMeanThres = LA_O2O_RELOBJ_TRACE_DIST_MEAN_FAR_CURVY;
      }
    }

    /* Check threshold for mean distance of trace if a left/right lane exists */
    if ( (t_TraceVDYCurvePara_Rel.fDistMean > f_RelTraceDistMeanThres)
      && (i_NumberOfLeftLanes != (sint8)0)
      )
    {
      /* Object trace mean is too far to the left for O2O ego lane association */
      b_hintRelObjTrace = FALSE;
    }
    else if ( (t_TraceVDYCurvePara_Rel.fDistMean < -f_RelTraceDistMeanThres)
      && (i_NumberOfRightLanes != (sint8)0)
      )
    {
      /* Object trace mean is too far away to the right for O2O ego lane association */
      b_hintRelObjTrace = FALSE;
    }
    else
    {
      /* b_hintRelObjTrace = TRUE; */
    }

    /* 4. Check if trace mean distance dependent standard deviation criteria */
    if (t_LA_InternalObjectData[t_ObjNrRel].t_O2O_EgoLaneAssocStatus.b_O2OEgoLaneObj == FALSE )
    {
      /* for higher mean distances the standard deviation criteria is more stringent */
      f_TraceMeanDependentStdDevThres = dGDBmathLineareFunktion( &LAO2ORelObjTraceStdDevMeanRamp, fABS(t_TraceVDYCurvePara_Rel.fDistMean));
      if (t_TraceVDYCurvePara_Rel.fDistStdDev > f_TraceMeanDependentStdDevThres)
      {
        b_hintRelObjTrace = FALSE;
      }
    }

    /* 5. When ego is driving on mid lane, do additional checks */
    /* On mid lane trace has to be very parallel */
    if ( (t_LA_InternalObjectData[t_ObjNrRel].t_O2O_EgoLaneAssocStatus.b_O2OEgoLaneObj == FALSE)
      && (i_NumberOfLeftLanes != (sint8)0)
      && (i_NumberOfRightLanes != (sint8)0)
      && (t_TraceVDYCurvePara_Rel.fDistStdDev > LA_O2O_RELOBJ_TRACE_STD_DEV_MIDLANE_CRIT)
      )
    {
      /* trace is short and not very close */
      if ( (pt_LAInput->pt_FIPMOT->t_MovObjStaticTrace[t_RelTraceNr].iNumberOfPoints <= LA_O2O_RELOBJ_TRACE_SAMPLES_MIDLANE_CRIT)
        && (fABS(t_TraceVDYCurvePara_Rel.fDistMean) > LA_O2O_RELOBJ_TRACE_DIST_MEAN_MIDLANE_CRIT) )
      {
        b_hintRelObjTrace = FALSE;
      }
      /* road-VDY-delta implies a possible curve entry */
      if ( (f_RoadVDYDeltaFar > LA_O2O_ROADVDYDELTA_FAR_HIGH)
        || (f_RoadVDYDeltaNear > LA_O2O_ROADVDYDELTA_NEAR_HIGH) )
      {
        b_hintRelObjTrace = FALSE;
    }
  }

  return b_hintRelObjTrace;
}
#endif

#if (LA_CFG_O2O_EGO_LANE_ASSOC)
/*************************************************************************************************************************
  Functionname:    LA_b_O2OCheckRelObjBorderDistHint                                                             */ /*!

  @brief           Checks object-to-object (O2O) relation based ego lane association relevant object distance 
                   to road border hint.

  @description     Function checks if relevant object is close to the road border when ego is close the road border. 
                   If relevant object is too far from the road border while ego is close to it, the criteria is not fulfilled.
                   The distance to road border is computed by two means. First, by counting the number of stationary (guardrail)
                   objects close to the relevant object. The mean lateral distance of the relevant object to those stationary 
                   objects is the first estimation of its distance to the road border. Second, the relevant object distance to the
                   road border is computed by using the object's distance to the road estimation clothoid with an offset 
                   which equals the ego distance to the road border.
                   @startuml
Partition LA_b_O2OCheckRelObjBorderDistHint{
Start
	-get the ACC trajectory distance of the relevant object
	if(ego is driving on outer left lane) then (yes)
		-Ego is driving on outer left lane. Set search gate borders accordingly
	elseif(ego is driving on outer right lane) then (yes)
		-Ego is driving on outer right lane Set search gate borders accordingly
	else
		-Ego is not driving on outer left or right lane. Do not perform border distance check
	endif
	
	repeat
		-Get x-distance sorted objects
		if(Check if upper longitudinal distance gate reached) then (yes)
			-set precondition flag to true
		endif
		
		if(precondition flag is false and object is relevant and object is stationary or stopped and object class is GUARDRAIL and object is inside search gate)then (yes)
			-get the ACC trajectory distances difference compared to relevant object
			-sum up the distances
			-increase the number of guardrail objects
		endif
	repeat while(all objects until upper longitudinal distance gate reached)
	if(O2O Ego Lane Object is true or Trace Ego Lane Object is true) then (yes)
		-set "distance of object to road border threshold" to "drop threshold of object distance to road border" when ego on outer lane
	else
		-set "distance of object to road border threshold" to "pick-up threshold of object distance to road border "when ego on outer lane
	endif
	
	if(Road Border Object Number is greater than or equal to  minimum number of stationary (guardrail) objects needed for object distance to road border estimation) then (yes)
		-Compute the mean distance of all guardrail objects inside the search gate to the moving object under consideration
	    if(the mean distance of the object to the guardrail is high enough) then (yes)
			-it is most likely not on ego lane
		endif
    else
		if(ego is close to left road border and if road estimation and road border information are reliable enough)then (yes)
			-Evaluate lateral object position relative to road center
			-Evaluate lateral object position relative to road border.  A positive value means object is inside road borders.
		elseif(ego is close to right road border and if road estimation and road border information are reliable enough) then (yes)
			-Evaluate lateral object position relative to road center
			- Evaluate lateral object position relative to road border. A positive value means object is inside road borders
		else
			-If road estimation information not reliable, we cannot compute a distance to road border
		endif
		
		if(mean distance of the object to the guardrail is high enough) then (true)
			-it is most likely not on  ego lane
		endif
		
	endif
end
}
@enduml

  @return          boolean : TRUE, if criteria fulfilled [TRUE, FALSE]

  @param[in]       t_ObjNrRel : Input "relevant" object No [-1 ... EM_N_OBJECTS-1]

  @glob_in         *pt_LAInput->t_RTE.pf_ObjLongDisp  (i) : Longitudinal displacement of an object i [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
  @glob_in         OBJ_GET_CP(i).TrajDist : Structure of type CPObjDist2Traj_t, Information about objects relation to estimated course. Defined in cp_ext.h
  @glob_in         SLATE_t_GetNumOfObjectsUsed() : number of objects [0 ... EM_N_OBJECTS[ with EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @glob_in         *SLATE_pt_GetObjDynProperty(i) : Dynamic property of an object i [EM_t_ARS_DynamicProperty as in Rte_Type.h]
  @glob_in         *SLATE_pu_GetDistXSortedObj(j) : number of object i in dist-x sorted list [0 ... EM_N_OBJECTS[ with EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @glob_in         pt_LAInput->pt_FIPRoad->t_FIPRoadFusedBorder.fDistLeft : Lateral ego distance to left road border [0.f ... 30.f] m
  @glob_in         pt_LAInput->pt_FIPRoad->t_FIPRoadFusedBorder.fDistRight : Lateral ego distance to right road border [-30.f ... 0.f] m
  @glob_in         pSLATE_EmCustObjList->CustObjects[i].DTR_Obj_Class : DTR specific object class [DTR_Obj_Class_t  as defined in Rte_Type.h]
  @glob_in         *pt_LAInput->t_RTE.pf_ObjLatDisp   (i) : Lateral displacement of an object i [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @glob_in         pt_LAInput->pt_FIPRoad->t_FIPRoadEstimation.fYawAngle : [-100.f .. +100.f] rad/s
  @glob_in         pt_LAInput->pt_FIPRoad->t_FIPRoadEstimation.fC0 : [-1 ... +1] m^(-1)
  @glob_in         pt_LAInput->pt_FIPRoad->t_FIPRoadEstimation.fC1 : [-1 ... +1] m^(-1)
  @glob_in         pt_LAInput->pt_FIPRoad->t_FIPRoadEstimation.uiTrackingStatusRight : [0u ... MAX_TRACKING_STATUS as defined in rd_ext.h]
  @glob_in         pt_LAInput->pt_FIPRoad->t_FIPRoadEstimation.uiTrackingStatusLeft : [0u ... MAX_TRACKING_STATUS as defined in rd_ext.h]
  @glob_in         pt_LAInput->pt_FIPRoad->t_FIPRoadFusedBorder.bStatusLeft : Left road border status [0u ... 100u]
  @glob_in         pt_LAInput->pt_FIPRoad->t_FIPRoadEstimation.fConfidenceLeft : Confidence of road estimation on left side [0.f ... 100.f]
  @glob_in         pt_LAInput->pt_FIPRoad->t_FIPRoadEstimation.fmaxXLeftCompensated : Distance up to which road estimation on left side is available [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
  @glob_in         pt_LAInput->pt_FIPRoad->t_FIPRoadFusedBorder.bStatusRight : Right road border status [0u ... 100u]
  @glob_in         pt_LAInput->pt_FIPRoad->t_FIPRoadEstimation.fConfidenceRight : Confidence of road estimation on left side [0.f ... 100.f]
  @glob_in         pt_LAInput->pt_FIPRoad->t_FIPRoadEstimation.fmaxXRightCompensated : Distance up to which road estimation on left side is available [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
  @glob_in         t_LA_InternalObjectData[ObjNr].t_O2O_EgoLaneAssocStatus.b_TraceEgoLaneObj : object i has been associated to ego lane based on trace analysis [TRUE, FALSE]
  @glob_in         t_LA_InternalObjectData[ObjNr].t_O2O_EgoLaneAssocStatus.b_O2OEgoLaneObj : object i has been associated to ego lane based on object-to-object (O2O) relation analysis [TRUE, FALSE]
  @glob_out        -
  
  @c_switch_part   LA_CFG_DTR_OBJ_SELECTION : activate DTR specific custom interface
  @c_switch_part   FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING : FCT Input Preprocessing Lane matrix
  @c_switch_full   LA_CFG_O2O_EGO_LANE_ASSOC : Compute object-to-object (O2O) relation based ego lane association
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @todo            Guardrail class only available for ARS440/DTR (active LA_CFG_DTR_OBJ_SELECTION). 
                   Check performance of function without this information. 
                   Have a global signal for the object distance to the road border.

  @created         30.06.2016
  @changed         21.07.2016

  @todo            Inputs from FIP Road (pt_LAInput->t_FIPRoad) are available only if switch FCT_CFG_INPUT_PREPROCESSSING is 
                   on, which is not considered here. Switch for FCT_CFG_ROAD_INPUT to also be adapted.

  @author          Grant Davtjan | Grant.Davtjan@continental-corporation.com | +49-8382-9699-633
*************************************************************************************************************************/
static boolean LA_b_O2OCheckRelObjBorderDistHint( const ObjNumber_t t_ObjNrRel )
{
  boolean b_hintRelObjBorderDist = TRUE;  /* default return value */
  uint8  u_RoadBorderObjNum = 0u;         /* number of stationary road border objects found */
  float32 f_RoadBorderObjDistMean = 0.f;  /* mean distance of road border objects */
  float32 f_RoadBorderObjDistMeanThres;   /* distance of object to road border threshold */
  boolean b_StopLoop = FALSE;             /* precondition flag and flag to stop loop when upper gate border reached */

  boolean b_EgoCloseToLeftBorder = FALSE;                 /* ego is close to left border? */
  boolean b_EgoCloseToRightBorder = FALSE;                /* ego is close to right border? */
  float32 f_RelObjDistToRoadborder;                       /* Object position relative to road border close to ego */
  float32 f_RelDistX_Sqr;                                 /* Object longitudinal distance square */
  float32 f_RelObjRoadDistY;                              /* Object position relative to road center */
  float32 f_RelDistY;                                     /* Lateral relevant object distance */
  float32 f_RelDistX = *pt_LAInput->t_RTE.pf_ObjLongDisp(t_ObjNrRel); /* Longitudinal relevant object distance */

  ObjNumber_t t_ObjNr;     /* index for search of neighboring object */
  float32 f_DistObjToTraj; /* lateral distance between neighboring object and ACC trajectory */
  float32 f_DistRelToTraj; /* lateral distance between relevant object and ACC trajectory */
  float32 f_LatDistDiff;   /* difference of lateral distances to relevant and neighboring object */

  /* Situation dependent thresholds */
  float32 f_LatDistUpperGate; /* Lateral search gate upper threshold */
  float32 f_LatDistLowerGate; /* Lateral search gate lower threshold */
  float32 f_LongDistUpperGate = f_RelDistX + LA_O2O_RELOBJ_BORDER_GATE_HALF_LONG; /* Longitudinal search gate upper threshold */
  float32 f_LongDistLowerGate = f_RelDistX - LA_O2O_RELOBJ_BORDER_GATE_HALF_LONG; /* Longitudinal search gate lower threshold */

  /* Index for loop over range sorted object list */
  ObjNumber_t j = 0;

#if (FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING)
  /* Number of left an right lanes */
  const sint8 i_NumberOfLeftLanes = (pt_LAInput->pt_FIPLaneMatrix->s_NumOfLaneLeft);
  const sint8 i_NumberOfRightLanes = (pt_LAInput->pt_FIPLaneMatrix->s_NumOfLaneRight);
#else
  /* assume one left and right lane when lane matrix not available */
  const sint8 i_NumberOfLeftLanes = (const sint8)1;
  const sint8 i_NumberOfRightLanes = (const sint8)1;
#endif

  /* get the ACC trajectory distance of the relevant object */
  f_DistRelToTraj = pt_LAOutput->t_LAObjOutputList[t_ObjNrRel].TrajDist.TrajDistMeas.Y.f0;

  /* Perform the border distance check only in case ego is driving on outer left or right lane */
  if ( (i_NumberOfLeftLanes == (sint8)0) 
    || ((pt_LAInput->pt_FIPRoad->t_FIPRoadFusedBorder.fDistLeft)  < LA_O2O_BORDER_DIST_CLOSE)
    || ((i_NumberOfLeftLanes == (sint8)-1) 
    && ((pt_LAInput->pt_FIPRoad->t_FIPRoadFusedBorder.fDistRight) < -LA_O2O_BORDER_DIST_FAR)
    && ((pt_LAInput->pt_FIPRoad->t_FIPRoadFusedBorder.bStatusRight) >= LA_O2O_BORDER_STATUS_MIN)
       )
     )
  {
    /* Ego is driving on outer left lane. Set search gate borders accordingly */
    f_LatDistUpperGate = f_DistRelToTraj + LA_O2O_RELOBJ_BORDER_GATE_LAT;
    f_LatDistLowerGate = f_DistRelToTraj;
    b_EgoCloseToLeftBorder = TRUE;
  }
  else if ( (i_NumberOfRightLanes == (sint8)0) 
    || ((pt_LAInput->pt_FIPRoad->t_FIPRoadFusedBorder.fDistRight)  > -LA_O2O_BORDER_DIST_CLOSE)
         || ((i_NumberOfRightLanes == (sint8)-1) 
         && ((pt_LAInput->pt_FIPRoad->t_FIPRoadFusedBorder.fDistLeft) > LA_O2O_BORDER_DIST_FAR)
         && ((pt_LAInput->pt_FIPRoad->t_FIPRoadFusedBorder.bStatusLeft) >= LA_O2O_BORDER_STATUS_MIN)
            )
          )
  {
   /* Ego is driving on outer right lane Set search gate borders accordingly */
    f_LatDistUpperGate = f_DistRelToTraj;
    f_LatDistLowerGate = f_DistRelToTraj - LA_O2O_RELOBJ_BORDER_GATE_LAT;
    b_EgoCloseToRightBorder = TRUE;
  }
  else
  {
    /* Ego is not driving on outer left or right lane. Do not perform border distance check */
    f_LatDistUpperGate = 0.f;
    f_LatDistLowerGate = 0.f;
    b_StopLoop = TRUE;
  }

  /* Loop over all objects until upper longitudinal distance gate reached */
  for (j = 0; ((j < SLATE_t_GetNumOfObjectsUsed()) && (b_StopLoop == FALSE)); j++)
  {
    /* Get x-distance sorted objects */
    t_ObjNr = *SLATE_pu_GetDistXSortedObj(j);

    /* Check if upper longitudinal distance gate reached */
    if (*pt_LAInput->t_RTE.pf_ObjLongDisp(t_ObjNr) > f_LongDistUpperGate)
    {
      b_StopLoop = TRUE;
    }

    /* Look for stationary objects from the road border inside the search gate */
    if ( (b_StopLoop == FALSE)
      && (t_ObjNr != t_ObjNrRel)
      && ( (*SLATE_pt_GetObjDynProperty(t_ObjNr) == SLATE_OBJECT_PROPERTY_STATIONARY)
#if (FCT_CFG_SENSOR_TYPE_CAMERA)
        || (*SLATE_pt_GetObjDynProperty(t_ObjNr) == SLATE_OBJECT_PROPERTY_STOPPED) 
#endif /* FCT_CFG_SENSOR_TYPE_CAMERA */
         )
#if (LA_CFG_DTR_OBJ_SELECTION)
      && (pSLATE_EmCustObjList->CustObjects[t_ObjNr].DTR_Obj_Class == DTR_CLASS_GUARDRAIL)
#endif
      && (*pt_LAInput->t_RTE.pf_ObjLongDisp(t_ObjNr) > f_LongDistLowerGate)
      && (*pt_LAInput->t_RTE.pf_ObjLatDisp(t_ObjNr)  > f_LatDistLowerGate)
      && (*pt_LAInput->t_RTE.pf_ObjLatDisp(t_ObjNr)  < f_LatDistUpperGate)
       )
    {
      /* get the ACC trajectory distances difference compared to relevant object  */
      f_DistObjToTraj = pt_LAOutput->t_LAObjOutputList[t_ObjNr].TrajDist.TrajDistMeas.Y.f0;
      f_LatDistDiff   = f_DistRelToTraj - f_DistObjToTraj;

      /* sum up the distances */
      f_RoadBorderObjDistMean = f_RoadBorderObjDistMean + f_LatDistDiff;
      /* increase the number of guardrail objects */
      u_RoadBorderObjNum++;
    }
  }

  /* Set longitudinal distance dependent object distance to road border threshold */
  if (t_LA_InternalObjectData[t_ObjNrRel].t_O2O_EgoLaneAssocStatus.b_O2OEgoLaneObj == TRUE)
    || (t_LA_InternalObjectData[t_ObjNrRel].t_O2O_EgoLaneAssocStatus.b_TraceEgoLaneObj == TRUE) )
  {
    f_RoadBorderObjDistMeanThres = LA_O2O_RELOBJ_BORDER_DIST_DROP;
  }
  else
  {
    f_RoadBorderObjDistMeanThres = LA_O2O_RELOBJ_BORDER_DIST_PICKUP;
  }

  if (u_RoadBorderObjNum >= LA_O2O_RELOBJ_BORDER_GUARDRAIL_OBJ_MIN)
  {
    /* Compute the mean distance of all guardrail objects inside the search gate to the moving object 
    under consideration */
    f_RoadBorderObjDistMean = f_RoadBorderObjDistMean / (float32)u_RoadBorderObjNum;

    /* If the mean distance of the object to the guardrail is high enough, it is most likely not on  
    ego lane */
    if (fABS(f_RoadBorderObjDistMean) > f_RoadBorderObjDistMeanThres)
    {
      b_hintRelObjBorderDist = FALSE;
    }
  }
  else
  {
    /* Check distance to road using the the road estimation if not enough guardrail objects have been found */

    /* If ego is close to left road border check if road estimation and road border information are reliable enough */
    if ( (b_EgoCloseToLeftBorder == TRUE)
      && ((pt_LAInput->pt_FIPRoad->t_FIPRoadFusedBorder.bStatusLeft) >= (LA_O2O_BORDER_STATUS_MIN))
      && ((pt_LAInput->pt_FIPRoad->t_FIPRoadEstimation.fConfidenceLeft) > LA_O2O_RELOBJ_BORDER_ROAD_CONF_MIN)
      && ((pt_LAInput->pt_FIPRoad->t_FIPRoadEstimation.uiTrackingStatusLeft) > LA_O2O_RELOBJ_BORDER_ROAD_TRACK_MIN)
      && (f_RelDistX <= ((pt_LAInput->pt_FIPRoad->t_FIPRoadEstimation.fmaxXLeftCompensated) - LA_O2O_RELOBJ_BORDER_ROAD_RANGE_OFFSET)) 
    )
    {
      /* Local variables */
      f_RelDistX_Sqr = SQR(f_RelDistX) * (0.5f);
      f_RelDistY = *pt_LAInput->t_RTE.pf_ObjLatDisp(t_ObjNrRel);

      /* Evaluate lateral object position relative to road center */
      f_RelObjRoadDistY = f_RelDistY - (((pt_LAInput->pt_FIPRoad->t_FIPRoadEstimation.fYawAngle))*f_RelDistX) - (((pt_LAInput->pt_FIPRoad->t_FIPRoadEstimation.fC0))*f_RelDistX_Sqr) - ((((pt_LAInput->pt_FIPRoad->t_FIPRoadEstimation.fC1))*f_RelDistX*f_RelDistX_Sqr)*(1.0F/3.0f));

      /* Evaluate lateral object position relative to road border.  A positive value means object is inside road borders. */
      f_RelObjDistToRoadborder = (pt_LAInput->pt_FIPRoad->t_FIPRoadEstimation.fYLeft) - f_RelObjRoadDistY;
    }
    /* If ego is close to right road border check if road estimation and road border information are reliable enough */
    else if ( (b_EgoCloseToRightBorder == TRUE)
           && ((pt_LAInput->pt_FIPRoad->t_FIPRoadFusedBorder.bStatusRight) >= (LA_O2O_BORDER_STATUS_MIN))
           && ((pt_LAInput->pt_FIPRoad->t_FIPRoadEstimation.fConfidenceRight) > LA_O2O_RELOBJ_BORDER_ROAD_CONF_MIN)
           && ((pt_LAInput->pt_FIPRoad->t_FIPRoadEstimation.uiTrackingStatusRight) > LA_O2O_RELOBJ_BORDER_ROAD_TRACK_MIN)
           && (f_RelDistX <= ((pt_LAInput->pt_FIPRoad->t_FIPRoadEstimation.fmaxXRightCompensated) - LA_O2O_RELOBJ_BORDER_ROAD_RANGE_OFFSET)) 
       )
    {
      /* Local variables */
      f_RelDistX_Sqr = SQR(f_RelDistX) * (0.5f);
      f_RelDistY = *pt_LAInput->t_RTE.pf_ObjLatDisp(t_ObjNrRel);

      /* Evaluate lateral object position relative to road center */
      f_RelObjRoadDistY = f_RelDistY - (((pt_LAInput->pt_FIPRoad->t_FIPRoadEstimation.fYawAngle))*f_RelDistX) - (((pt_LAInput->pt_FIPRoad->t_FIPRoadEstimation.fC0))*f_RelDistX_Sqr) - ((((pt_LAInput->pt_FIPRoad->t_FIPRoadEstimation.fC1))*f_RelDistX*f_RelDistX_Sqr)*(1.0F/3.0f));

      /* Evaluate lateral object position relative to road border. A positive value means object is inside road borders. */
      f_RelObjDistToRoadborder = f_RelObjRoadDistY - (pt_LAInput->pt_FIPRoad->t_FIPRoadEstimation.fYRight);
    }
    else
    {
      /* If road estimation information not reliable, we cannot compute a distance to road border */
      f_RelObjDistToRoadborder = 0.f;
    }

    /* If the mean distance of the object to the guardrail is high enough, it is most likely not on  
    ego lane */
    if (fABS(f_RelObjDistToRoadborder) > f_RoadBorderObjDistMeanThres)
    {
      b_hintRelObjBorderDist = FALSE;
    }
  }

  return b_hintRelObjBorderDist;
}
#endif

#if (LA_CFG_O2O_EGO_LANE_ASSOC)
/*************************************************************************************************************************
  Functionname:    LA_b_O2OCheckRelObjCutOutHint                                                             */ /*!

  @brief           Checks object-to-object (O2O) relation based ego lane association relevant object cut-out hint.

  @description     Function checks if relevant object is likely performing a cut-out. Precondition is that a neighboring
                   lane exists. Also, if the relevant object trace is available it should indicate a cut-out by an increase
                   in trace sample distance to VDY curve standard deviation. If preconditions are fulfilled a loop
                   over all moving objects is done. In case a second moving object is found directly in front of the 
                   relevant object which is slower than the relevant object and its trace is close and parallel to the 
                   VDY curve (or very close to the trajectory if trace not available), a cutting-out of the relevant 
                   object is suggested.
                   @startuml
Partition LA_b_O2OCheckRelObjCutOutHint{
Start
	-Get trace mean distance to VDY course and its standard deviation for relevant object
	If(Relevant Traces is less than TRACE NO OF TRACES) then (yes)
		-Calc distance mean and standard deviation of distances of trajectory to circle
	endif
	
	if(mean distances is greater than CP TRAJECTORY INVALID VALUE)then (yes)
		if(Number Of Left Lanes is not equal to 0 or Number Of Right Lanes is not equal to 0) then (yes)
			-set CutOut Precondition flag to true
		endif
	elseif(trace mean and standard deviation of relevant object available) then (yes)
		if(Check if cut-out is possible to the left side) then (yes)
			-set CutOut Precondition flag to true
		elseif(Check if cut-out is possible to the right side) then (yes)
			-set CutOut Precondition flag to true
		else
			-set CutOut Precondition flag to false
			-set hint O2O CutOut to false
		endif
	else
		-set CutOut Precondition flag to false
		-set hint O2O CutOut to false
	endif
	
	repeat 
		-get DTR specific quality criteria 
		if(object is relevant and object is moving and DTR Pre Select is true and acc quality is greater than minimum) then (yes)
			-calculate difference of relative velocity between relevant and neighboring object 
			-calculate longitudinal distances difference between relevant and neighboring object
			if(relevant object is close to and behind another object which is slower than the relevant object) then (yes)
				-Initialize mean distances and standard deviation for neighboring object
				-Get trace mean distance to VDY course and its standard deviation for neighboring object
				if(traces are available for both objects) then (yes)
					-consider the trace mean distance to VDY course as a more accurate estimation of the distances of neighboring and relevant object
				elseif(Traces are available only for the relevant object) then (yes)
					-get the ACC trajectory distance of the object
					-consider the trace mean distance to VDY course as more accurate estimation of the distance of the relevant object 
				elseif(Traces are available only for the neighboring object) then (yes)
					-get the ACC trajectory distance of the relevant object
					-consider the trace mean distance to VDY course as more accurate estimation  of the distance of the neighboring object 
				else
					-get the ACC trajectory distance for both objects 
				endif
				-calculate the trace absolute distance difference of relevant and neighboring object 
				if(relevant object trace is not much closer than the trace of the neighboring object and 
				the neighboring objects trace is parallel or information not available) then (true)
					-relevant object is likely performing a cut-out
				endif
			endif
		endif
	repeat while(for all objects in use and CutOut Precondition flag to true)
	
end
}
@enduml

  @return          boolean : TRUE, if it is unlikely that relevant object is performing a cut-out [TRUE, FALSE]

  @param[in]       t_ObjNrRel : Input "relevant" object No [-1 ... EM_N_OBJECTS-1]

  @glob_in         *(pt_LAInput->t_FIPMOT.pu_FIPStaticTraceID(i)) : Trace index of object i [full range of unsigned char data type]
  @glob_in         FCT_fBumperToCoG : distance from Bumper to Center of Gravity [full range of data type float32 >= 0.F]
  @glob_in         SLATE_f_GetSensorYPosition() : Sensor mounting lateral position [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @glob_in         pt_LAInput->t_RTE.pf_EgoCurve: Ego curve provided by VDY [-1 ... +1] m^-1
  @glob_in         *pt_LAInput->t_RTE.pf_ObjLongDisp  (i) : Longitudinal displacement of an object i [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
  @glob_in         OBJ_GET_CP(i).TrajDist : Structure of type CPObjDist2Traj_t, Information about objects relation to estimated course. Defined in cp_ext.h
  @glob_in         SLATE_t_GetNumOfObjectsUsed() : number of objects [0 ... EM_N_OBJECTS[ with EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @glob_in         *SLATE_pt_GetObjDynProperty(i) : Dynamic property of an object i [SLATE_t_Obj_DynamicProperty as in Rte_Type.h]
  @glob_in         SLATE_u_GetAccQuality(i) : ACC quality of object i [0 ... 100]
  @glob_in         pt_LAInput->t_RTE.pf_ObjVrelX(i) : Relative velocity of object i [-330.f ... 330.f] m/s
  @glob_out        -

  @c_switch_part   LA_CFG_DTR_OBJ_SELECTION : activate DTR specific custom interface
  @c_switch_part   FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING : FCT Input Preprocessing Lane matrix
  @c_switch_full   LA_CFG_O2O_EGO_LANE_ASSOC : Compute object-to-object (O2O) relation based ego lane association
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         30.06.2016
  @changed         21.07.2016

  @todo            Have a global signal for the object cut-out probability.

  @todo            Inputs from FIP Road (pt_LAInput->t_FIPRoad) are available only if switch FCT_CFG_INPUT_PREPROCESSSING is 
                   on, which is not considered here. Switch for FCT_CFG_ROAD_INPUT to also be adapted.

  @author          Grant Davtjan | Grant.Davtjan@continental-corporation.com | +49-8382-9699-633
*************************************************************************************************************************/
static boolean LA_b_O2OCheckRelObjCutOutHint( const ObjNumber_t t_ObjNrRel)
{
  boolean b_hintO2OCutOut            = TRUE;  /* default return value */
  boolean b_RelObjCutOutPrecondition = FALSE; /* precondition for further computation of cut-out hint */

  ObjNumber_t t_ObjNr;        /* index of trace belonging to relevant object */
  TraceID_t t_RelTraceNr;     /* index of trace belonging to relevant object */
  TraceID_t t_ObjTraceNr;     /* index of trace belonging to neighboring object */
  float32 f_AbsTraceDistDiff; /* index of trace belonging to neighboring object */

  float32 f_VrelDiff;     /* difference of relative velocity between relevant and neighboring object */
  float32 f_LongDistDiff; /* longitudinal distances difference between relevant and neighboring object */

  /* Distance to trajectory used when trace mean distance not available */
  float32 f_DistObjToTraj; /* lateral distance between neighboring object and ACC trajectory */
  float32 f_DistRelToTraj; /* lateral distance between relevant object and ACC trajectory */

#if (FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING)
  /* Number of left an right lanes */
  const sint8 i_NumberOfLeftLanes  = (pt_LAInput->pt_FIPLaneMatrix->s_NumOfLaneLeft);
  const sint8 i_NumberOfRightLanes = (pt_LAInput->pt_FIPLaneMatrix->s_NumOfLaneRight);
#else
  /* assume one left and right lane when lane matrix not available */
  const sint8 i_NumberOfLeftLanes  = (const sint8)1;
  const sint8 i_NumberOfRightLanes = (const sint8)1;
#endif

  /* Variables for distance and parallelism of trace calculation */
  GDBTrafoMatrix2D_t MOT2EGO = GDBGetTrafoMatrixByDisplacement( FCT_fBumperToCoG, SLATE_f_GetSensorYPosition() ); // PRQA S 1031 
  /* date: 2016-07-04, reviewer: Davtjan, Grant reason: Allowed in later versions of ISO C99*/
  CPTrace2CurveParallelism_t  t_TraceVDYCurvePara_Rel; /* Variable stores distance and parallelism of relevant object trace */
  CPTrace2CurveParallelism_t  t_TraceVDYCurvePara_Obj; /* Variable stores distance and parallelism of neighboring object trace */

#if (LA_CFG_DTR_OBJ_SELECTION)
  boolean b_DTRPreSelect; /* DTR specific quality criteria */
#endif

  /* Initialize mean distances and standard deviation for relevant object */
  t_TraceVDYCurvePara_Rel.fDistMean   = CP_TRAJ_INVALID_VALUE; /* default value */
  t_TraceVDYCurvePara_Rel.fDistStdDev = CP_TRAJ_INVALID_VALUE; /* default value */

  /* Get trace mean distance to VDY course and its standard deviation for relevant object */
  t_RelTraceNr = *(pt_LAInput->t_FIPMOT.pu_FIPStaticTraceID(t_ObjNrRel));
  if (t_RelTraceNr < (TraceID_t)TRACE_NO_OF_TRACES)
  {
    t_TraceVDYCurvePara_Rel = CPFusionTraceCalcTraceCircleParallelism( t_RelTraceNr, *pt_LAInput->t_RTE.pf_EgoCurve, &MOT2EGO );
  }

  /* Check preconditions for possible cut-out of relevant object: if trace of relevant object
     does not exist or is too short, check only if neighboring lane exists */
  if (t_TraceVDYCurvePara_Rel.fDistMean >= CP_TRAJ_INVALID_VALUE)
  {
    if ( (i_NumberOfLeftLanes != (sint8)0) 
      || (i_NumberOfRightLanes != (sint8)0) )
    {
      b_RelObjCutOutPrecondition = TRUE;
    }
  }
  /* If trace mean and standard deviation of relevant object available: for a cut-out its standard 
     deviation should be high enough */
  else if (t_TraceVDYCurvePara_Rel.fDistStdDev > LA_O2O_RELOBJ_CUTOUT_TRACE_STD_DEV_MIN)
  {
    /* Check if cut-out is possible to the left side */
    if ( (i_NumberOfLeftLanes != (sint8)0)
      && (t_TraceVDYCurvePara_Rel.fDistMean > LA_O2O_RELOBJ_CUTOUT_TRACE_DIST_MEAN_MIN) )
    {
      b_RelObjCutOutPrecondition = TRUE;
    }
    /* Check if cut-out is possible to the right side */
    else if ( (i_NumberOfRightLanes != (sint8)0)
      && (t_TraceVDYCurvePara_Rel.fDistMean < -LA_O2O_RELOBJ_CUTOUT_TRACE_DIST_MEAN_MIN) )
    {
      b_RelObjCutOutPrecondition = TRUE;
    }
    else
    {
      /* cut-out can't be detected */
      b_RelObjCutOutPrecondition = FALSE;
      b_hintO2OCutOut = TRUE;
    }
  }
  else
  {
    /* cut-out can't be detected */
    b_RelObjCutOutPrecondition = FALSE;
    b_hintO2OCutOut = TRUE;
  }

  /* Check if there exists a second object behind which relevant object likely performs a cut-out */
  for (t_ObjNr = 0u; ((t_ObjNr < SLATE_t_GetNumOfObjectsUsed()) && (b_RelObjCutOutPrecondition == TRUE)); t_ObjNr++)
  {
#if (LA_CFG_DTR_OBJ_SELECTION)
    /* get DTR specific quality criteria */
    b_DTRPreSelect = LA_b_DTRPreselectCrit(t_ObjNr);
#endif

    if ( (t_ObjNr != t_ObjNrRel) &&
      (*SLATE_pt_GetObjDynProperty(t_ObjNr) == SLATE_OBJECT_PROPERTY_MOVING) &&
#if (LA_CFG_DTR_OBJ_SELECTION)
      (b_DTRPreSelect == TRUE)
#else
      (SLATE_u_GetAccQuality(t_ObjNr) >= FUN_PRESEL_ACC_MIN_OBJ_QUAL)
#endif
      )
    {
      /* calculate difference of relative velocity between relevant and neighboring object */
      f_VrelDiff = *pt_LAInput->t_RTE.pf_ObjVrelX(t_ObjNrRel) - *pt_LAInput->t_RTE.pf_ObjVrelX(t_ObjNr);

      /* calculate longitudinal distances difference between relevant and neighboring object */
      f_LongDistDiff = (*pt_LAInput->t_RTE.pf_ObjLongDisp(t_ObjNrRel)) - (*pt_LAInput->t_RTE.pf_ObjLongDisp(t_ObjNr));

      /* Cut-out probability is high when relevant object is close to and behind another object
         which is slower than the relevant object */
      if ( (f_LongDistDiff < 0.f)
        && (f_LongDistDiff > LA_O2O_RELOBJ_CUTOUT_DISTX_DIFF_MIN)
        && (f_VrelDiff > LA_O2O_RELOBJ_CUTOUT_VREL_DIFF_MIN)
         )
      {
        /* Initialize mean distances and standard deviation for neighboring object */
        t_TraceVDYCurvePara_Obj.fDistMean   = CP_TRAJ_INVALID_VALUE; /* default value */
        t_TraceVDYCurvePara_Obj.fDistStdDev = CP_TRAJ_INVALID_VALUE; /* default value */

        /* Get trace mean distance to VDY course and its standard deviation for neighboring object */
        t_ObjTraceNr = *(pt_LAInput->t_FIPMOT.pu_FIPStaticTraceID(t_ObjNr));
        if (t_ObjTraceNr < (TraceID_t)TRACE_NO_OF_TRACES)
        {
          t_TraceVDYCurvePara_Obj = CPFusionTraceCalcTraceCircleParallelism( t_ObjTraceNr, *pt_LAInput->t_RTE.pf_EgoCurve, &MOT2EGO );
        }

        /* Do following calculation if traces are available for both objects */
        if ( (t_TraceVDYCurvePara_Rel.fDistMean < CP_TRAJ_INVALID_VALUE)
          && (t_TraceVDYCurvePara_Obj.fDistMean < CP_TRAJ_INVALID_VALUE)
          )
        {
          /* consider the trace mean distance to VDY course as a more accurate estimation of the 
             distances of neighboring and relevant object */
          f_DistObjToTraj = t_TraceVDYCurvePara_Obj.fDistMean;
          f_DistRelToTraj = t_TraceVDYCurvePara_Rel.fDistMean;
        }
        /* Traces are available only for the relevant object */
        else if (t_TraceVDYCurvePara_Rel.fDistMean < CP_TRAJ_INVALID_VALUE)
        {
          /* get the ACC trajectory distance of the object */
          f_DistObjToTraj = pt_LAOutput->t_LAObjOutputList[t_ObjNr].TrajDist.TrajDistMeas.Y.f0;
          /* consider the trace mean distance to VDY course as more accurate estimation 
             of the distance of the relevant object */
          f_DistRelToTraj = t_TraceVDYCurvePara_Rel.fDistMean;
        }
        /* Traces are available only for the neighboring object */
        else if (t_TraceVDYCurvePara_Obj.fDistMean < CP_TRAJ_INVALID_VALUE)
        {
          /* get the ACC trajectory distance of the relevant object */
          f_DistRelToTraj = pt_LAOutput->t_LAObjOutputList[t_ObjNrRel].TrajDist.TrajDistMeas.Y.f0;
          /* consider the trace mean distance to VDY course as more accurate estimation 
             of the distance of the neighboring object */
          f_DistObjToTraj = t_TraceVDYCurvePara_Obj.fDistMean;
        }
        /* Traces are not available for both objects */
        else
        {
          /* get the ACC trajectory distance for both objects */
          f_DistRelToTraj = pt_LAOutput->TrajDist[t_ObjNrRel].TrajDistMeas.Y.f0;
          f_DistObjToTraj = pt_LAOutput->t_LAObjOutputList[t_ObjNrRel].TrajDist.TrajDistMeas.Y.f0;
        }

        /* calculate the trace absolute distance difference of relevant and neighboring object */
        f_AbsTraceDistDiff = fABS(f_DistRelToTraj) - fABS(f_DistObjToTraj);

        /* If relevant object trace is not much closer than the trace of the neighboring object and 
           the neighboring objects trace is parallel or information not available: 
           relevant object is likely performing a cut-out */
        if ( (f_AbsTraceDistDiff > LA_O2O_RELOBJ_CUTOUT_ABS_TRACE_DIST_DIFF_MIN)
          && ( (t_TraceVDYCurvePara_Obj.fDistMean >= CP_TRAJ_INVALID_VALUE)
            || (t_TraceVDYCurvePara_Obj.fDistStdDev < LA_O2O_RELOBJ_CUTOUT_OBJ_TRACE_STD_DEV_MAX)
             )
           )
        {
          b_hintO2OCutOut = FALSE;
        }
      }
    }
  }

  return b_hintO2OCutOut;
}
#endif

#if (LA_CFG_O2O_EGO_LANE_ASSOC)
/*************************************************************************************************************************
  Functionname:    LA_t_O2OFindNeighboringO2OObject                                                             */ /*!

  @brief           Look for object which will confirm the object-to-object (O2O) relation based ego lane association 
                   of the relevant object.

  @description     Loop over all moving ("neighboring") objects with ACC quality. Check if neighboring object can 
                   confirm the ego lane assignment of the "relevant" object. Therefore, both objects have to pass
                   additional checks. Those are: both objects shall belong to different vehicles, they shall not be mirrors,
                   relevant object is the closest of both objects when ego on outer lane, in difficult situations 
                   relevant object absolute v-rel is not much higher than that of the neighboring object, their trace relation
                   criteria shall be fulfilled and the neighboring object shall be close enough to the relevant object.
                   All of these "O2O criteria" need to be fulfilled for an ego lane association of the relevant object.
                   @startuml
Partition LA_t_O2OFindNeighboringO2OObject{
Start
	repeat 
		-Initialize O2O based hints
		-Get x-distance sorted objects
		partition #lightblue **LA_CFG_DTR_OBJ_SELECTION**{
			-get DTR specific quality criteria
		}
		if(neighboring object is moving and object have sufficient ACC-quality) then (yes)
			-calculate longitudinal distances difference to relevant object
		    -get the ACC trajectory distances difference compared to relevant object
			-calculate absolute value of difference of relative velocity between relevant and neighboring object
			if(the longitudinal distance, relative velocity and the lateral distance to the relevant object is above a threshold) then (yes)
				-hint O2O Double Object is false
			endif
			if(the longitudinal distance and the relative velocity difference to the relevant object is above a threshold) then (yes)
				-hint O2O Mirror is false
			endif
			
			if(ego is driving on outer right lane) then (yes)
				-hint O2O Lane Matrix is false	
			endif
			
			if(ego is driving on outer left lane) then (yes)
				-hint O2O Lane Matrix is false	
			endif
			
			if( ego is on mid lane) then (yes) 
				if(object has a much higher absolute relative velocity than the neighboring object) then (yes)
					-hint O2O relative velocity is false
				endif
			endif
			
			-Check trace relation of relevant and neighboring object criteria
			
			if(longitudinal distance of the relevant object is greater than LA O2O POSITION DISTX FAR) then (yes)
				-set Position thresholds to far range
			else
				-set Position thresholds to near range
			endif
			
			if(Objects having low velocity difference)then (yes)
				-decrease the search gate for longitudinal distances to a minimum
			endif
			
			if(object is truck)then (yes)
				-increase the upper search gate threshold for longitudinal distance
			endif
			
			if(O2O Ego Lane Object is true)
				-Hysteresis of thresholds
			endif
			
			if(position is inside search gate) then (yes)
				-the hint is not fulfilled
			endif
			
			if(b_hint O2O Double Object, hint O2O Mirror ,hint O2O Lane Matrix, hint O2O relative velocity ,hint O2O Trace Distances and hint O2O Position) then (yes)
				-object to be assigned to ego lane by O2O analysis
			endif
			
			partition #lightblue **FCT_SIMU** {
				-retain information about O2O selection loss reason from last cycle for debugging
			}
			
		endif
		
		partition #lightblue **FCT_SIMU** {
		 if(new O2O object found) then (yes)
			-overwrite O2O information
		 else
			-retain information about O2O selection loss reason from last cycle for debugging 
		 endif
		}
		
	repeat while(all objects to find a near neighboring object as long as none has been found)
end
}
@enduml

  @return          static ObjNumber_t : No of neighboring object which fulfills all O2O criteria [-1 ... EM_N_OBJECTS-1]

  @param[in]       t_ObjNrRel : Input "relevant" object No [-1 ... EM_N_OBJECTS-1]

  @glob_in         *(pt_LAInput->t_FIPMOT.pu_FIPStaticTraceID(i)) : Trace index of object i [full range of unsigned char data type]
  @glob_in         *pt_LAInput->t_RTE.pf_ObjLongDisp  (i) : Longitudinal displacement of an object i [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
  @glob_in         pt_LAInput->t_FIPMOT.pt_FIPMovObjStaticTrace(i)->iNumberOfPoints : Get number of trace points [full range of signed char data type]
  @glob_in         OBJ_GET_CP(i).TrajDist : Structure of type CPObjDist2Traj_t, Information about objects relation to estimated course. Defined in cp_ext.h
  @glob_in         SLATE_t_GetNumOfObjectsUsed() : number of objects [0 ... EM_N_OBJECTS[ with EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @glob_in         *SLATE_pt_GetObjDynProperty(i) : Dynamic property of an object i [SLATE_t_Obj_DynamicProperty as in Rte_Type.h]
  @glob_in         *SLATE_pu_GetDistXSortedObj(j) : number of object i in dist-x sorted list [0 ... EM_N_OBJECTS[ with EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @glob_in         SLATE_u_GetAccQuality(i) : ACC quality of object i [0 ... 100]
  @glob_in         pt_LAInput->t_RTE.pf_ObjVrelX(i) : Relative velocity of object i [-330.f ... 330.f] m/s
  @glob_in         pt_LAInput->pt_FIPRoad->t_FIPRoadFusedBorder.fDistLeft : Lateral ego distance to left road border [0.f ... 30.f] m
  @glob_in         pt_LAInput->pt_FIPRoad->t_FIPRoadFusedBorder.fDistRight : Lateral ego distance to right road border [-30.f ... 0.f] m
  @glob_in         *SLATE_pt_GetObjClassification(i) : Object class [EM_t_GenObjClassification as in Rte_Type.h]
  @glob_out        -

  @c_switch_part   LA_CFG_DTR_OBJ_SELECTION : activate DTR specific custom interface
  @c_switch_part   FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING : FCT Input Preprocessing Lane matrix
  @c_switch_full   LA_CFG_O2O_EGO_LANE_ASSOC : Compute object-to-object (O2O) relation based ego lane association
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         30.06.2016
  @changed         21.07.2016

  @todo            Inputs from FIP Road (pt_LAInput->t_FIPRoad) are available only if switch FCT_CFG_INPUT_PREPROCESSSING is 
                   on, which is not considered here. Switch for FCT_CFG_ROAD_INPUT to also be adapted.

  @author          Grant Davtjan | Grant.Davtjan@continental-corporation.com | +49-8382-9699-633
*************************************************************************************************************************/
static ObjNumber_t LA_t_O2OFindNeighboringO2OObject( const ObjNumber_t t_ObjNrRel )
{
  ObjNumber_t t_ObjNrEgoLaneByO2O = OBJ_INDEX_NO_OBJECT;  /* default return value: no neighboring object for O2O ego lane assignment found */

  /* Index for loop over range sorted object list  */
  uint8 j = 0u;

  /* O2O hints */
  boolean b_hintO2ODoubleObject   = TRUE; /* Hint that relevant object and found neighboring object belong to different vehicles */
  boolean b_hintO2OMirror         = TRUE; /* Hint that relevant object and neighboring object are no mirrors of the same vehicle */
  boolean b_hintO2OLaneMatrix     = TRUE; /* Hint that relevant object is the closest one when ego is on outer lane */
  boolean b_hintO2OVrel           = TRUE; /* Hint that relevant object velocity does not differ too much. Applied on mid lane against drop-ins */
  boolean b_hintO2OTraceDistances = TRUE; /* Hint that relevant object is on ego lane based on the trace relation of both objects */
  boolean b_hintO2OPosition       = TRUE; /* Hint that relevant object and neighboring object are close enough for O2O ego lane association */

  ObjNumber_t t_ObjNr;      /* index for search of neighboring object */
  float32 f_DistObjToTraj;  /* lateral distance between neighboring object and ACC trajectory */
  float32 f_DistRelToTraj;  /* lateral distance between relevant object and ACC trajectory */
  float32 f_LongDistDiff;   /* difference of longitudinal distances between relevant and neighboring object and ACC trajectory */
  float32 f_LatDistDiffAbs; /* absolute value of difference of lateral distances to relevant and neighboring object */
  float32 f_VrelDiffAbs;    /* absolute value of difference of relative velocity between relevant and neighboring object */

  /* Situation dependent thresholds */
  float32 f_LongDistDiffThresMin; /* longitudinal distance difference minimum threshold */
  float32 f_LongDistDiffThresMax; /* longitudinal distance difference maximum threshold */
  float32 f_LatDistDiffAbsThres;  /* absolute lateral distance difference threshold */

  /* Index of trace belonging to relevant object */
  TraceID_t t_RelTraceNr;  

#if (FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING)
  /* Number of left an right lanes */
  const sint8 i_NumberOfLeftLanes = (pt_LAInput->pt_FIPLaneMatrix->s_NumOfLaneLeft);
  const sint8 i_NumberOfRightLanes = (pt_LAInput->pt_FIPLaneMatrix->s_NumOfLaneRight);
#else
  /* assume one left and right lane when lane matrix not available */
  const sint8 i_NumberOfLeftLanes = (const sint8)1;
  const sint8 i_NumberOfRightLanes = (const sint8)1;
#endif

#if (LA_CFG_DTR_OBJ_SELECTION)
  boolean b_DTRPreSelect; /* DTR specific quality criteria */
#endif

  /* Loop over all objects to find a near neighboring object as long as none has been found */
  for (j = 0u; ((j < SLATE_t_GetNumOfObjectsUsed()) && (t_ObjNrEgoLaneByO2O == OBJ_INDEX_NO_OBJECT)); j++)
  {
    /* Initialize O2O based hints */
    b_hintO2ODoubleObject        = TRUE;
    b_hintO2OMirror              = TRUE;
    b_hintO2OLaneMatrix          = TRUE;
    b_hintO2OVrel                = TRUE;
    b_hintO2OTraceDistances      = TRUE;
    b_hintO2OPosition            = TRUE;

    /* Get x-distance sorted objects */
    t_ObjNr = *SLATE_pu_GetDistXSortedObj(j);

#if (LA_CFG_DTR_OBJ_SELECTION)
    /* get DTR specific quality criteria */
    b_DTRPreSelect = LA_b_DTRPreselectCrit(t_ObjNr);
#endif

    /* Do not consider the relevant object The trace bracket extension is applied to the relevant 
    object but here a near neighboring object is looked for. Here, only moving neighboring objects 
    are considered and only objects with sufficient ACC-quality */
    if ( (t_ObjNr != t_ObjNrRel) &&
          (*SLATE_pt_GetObjDynProperty(t_ObjNr) == SLATE_OBJECT_PROPERTY_MOVING) &&
#if (LA_CFG_DTR_OBJ_SELECTION)
          (b_DTRPreSelect == TRUE)
#else
          (SLATE_u_GetAccQuality(t_ObjNr) >= FUN_PRESEL_ACC_MIN_OBJ_QUAL)
#endif
      )
    {
      /* calculate longitudinal distances difference to relevant object */
      f_LongDistDiff = (*pt_LAInput->t_RTE.pf_ObjLongDisp(t_ObjNrRel)) - (*pt_LAInput->t_RTE.pf_ObjLongDisp(t_ObjNr));

      /* get the ACC trajectory distances difference compared to relevant object  */
      f_DistRelToTraj = pt_LAOutput->t_LAObjOutputList[t_ObjNrRel].TrajDist.TrajDistMeas.Y.f0;
      f_DistObjToTraj = pt_LAOutput->t_LAObjOutputList[t_ObjNrRel].TrajDist.TrajDistMeas.Y.f0;
      f_LatDistDiffAbs = fABS(f_DistRelToTraj - f_DistObjToTraj);

      /* calculate absolute value of difference of relative velocity between relevant and 
      neighboring object */
      f_VrelDiffAbs = fABS(*pt_LAInput->t_RTE.pf_ObjVrelX(t_ObjNrRel) - *pt_LAInput->t_RTE.pf_ObjVrelX(t_ObjNr));

      /*--------------------------------- O2O DOUBLE OBJECT HINT ---------------------------------*/
      /* Problem: the relevant object can have two radar objects (happens often for trucks). 
      To suppress this second object the longitudinal distance, relative velocity and the lateral 
      distance to the relevant object must be above a threshold.*/
      if ( (fABS(f_LongDistDiff) <= LA_O2O_DOUBLEOBJ_DISTX_DIFF_ABS_MAX) 
        && (f_VrelDiffAbs < LA_O2O_DOUBLEOBJ_VREL_DIFF_ABS_MAX)
        && (f_LatDistDiffAbs <= LA_O2O_DOUBLEOBJ_DISTY_DIFF_ABS_MAX))
      {
        b_hintO2ODoubleObject = FALSE;
      }

      /*--------------------------------- O2O MIRROR HINT ----------------------------------------*/
      /* avoid trace bracket extension for object and its mirror: Therefore, the longitudinal 
      distance and the relative velocity difference to the relevant object must be above a 
      threshold */
      if ((fABS(f_LongDistDiff) < LA_O2O_MIRROR_DISTX_DIFF_ABS_MAX)
        && (f_VrelDiffAbs < LA_O2O_MIRROR_VREL_DIFF_ABS_MAX)
        )
      {
        b_hintO2OMirror = FALSE;
      }

      /*--------------------------------- O2O LANE MATRIX HINT -----------------------------------*/
      /* if ego is driving on outer left/right lane, relevant object should be more to the 
      left/right than neighboring O2O object */
      if ( ( (i_NumberOfLeftLanes == (sint8)0) 
          || ((pt_LAInput->pt_FIPRoad->t_FIPRoadFusedBorder.fDistLeft)  < LA_O2O_BORDER_DIST_CLOSE)
          || ((i_NumberOfLeftLanes == (sint8)-1) 
            && ((pt_LAInput->pt_FIPRoad->t_FIPRoadFusedBorder.fDistRight) < -LA_O2O_BORDER_DIST_FAR))
            && ((pt_LAInput->pt_FIPRoad->t_FIPRoadFusedBorder.bStatusRight) >= LA_O2O_BORDER_STATUS_MIN))
           )
        && (f_DistObjToTraj > f_DistRelToTraj) )
      {
        b_hintO2OLaneMatrix = FALSE;
      }

      if ( ( (i_NumberOfRightLanes == (sint8)0) 
             || ((pt_LAInput->pt_FIPRoad->t_FIPRoadFusedBorder.fDistRight)  > -LA_O2O_BORDER_DIST_CLOSE)
             || ((i_NumberOfRightLanes == (sint8)-1) 
               &&((pt_LAInput->pt_FIPRoad->t_FIPRoadFusedBorder.fDistLeft) > LA_O2O_BORDER_DIST_FAR))
               &&((pt_LAInput->pt_FIPRoad->t_FIPRoadFusedBorder.bStatusLeft) >= LA_O2O_BORDER_STATUS_MIN))
               )
             && (f_DistObjToTraj < f_DistRelToTraj) )
      {
        b_hintO2OLaneMatrix = FALSE;
      }

      /*--------------------------------- O2O VREL HINT ------------------------------------------*/
      /* In high distances and for high ego velocities drop-ins occur when ego is on mid lane.
      In those unsure situations do not select the object which has a much higher absolute relative 
      velocity than the neighboring object */
      t_RelTraceNr = *(pt_LAInput->t_FIPMOT.pu_FIPStaticTraceID(t_ObjNrRel));

      if ( ( ((t_RelTraceNr < (TraceID_t)TRACE_NO_OF_TRACES) == FALSE)
        || (pt_LAInput->pt_FIPMOT->t_MovObjStaticTrace[t_RelTraceNr].iNumberOfPoints < LA_O2O_VREL_TRACE_SAMPLES_MAX) )
         && (i_NumberOfLeftLanes != (sint8)0) 
         && (i_NumberOfRightLanes != (sint8)0)
         )
      {
        if ( (fABS(*pt_LAInput->t_RTE.pf_ObjVrelX(t_ObjNrRel)) - fABS(*pt_LAInput->t_RTE.pf_ObjVrelX(t_ObjNr))) > LA_O2O_VREL_ABS_VREL_DIFF_MAX)
        {
          b_hintO2OVrel = FALSE;
        }
      }

      /*--------------------------------- O2O TRACE RELATION HINT --------------------------------*/
      /* Check trace relation of relevant and neighboring object criteria */
      b_hintO2OTraceDistances = LA_b_O2OCheckO2OTraceRelationHint(t_ObjNrRel, t_ObjNr);

      /*--------------------------------- O2O POSITION HINT --------------------------------------*/
      /* Position thresholds are dependent on longitudinal distance of the relevant object */
      if (*pt_LAInput->t_RTE.pf_ObjLongDisp(t_ObjNrRel) > LA_O2O_POSITION_DISTX_FAR)
      {
        f_LongDistDiffThresMin = -LA_O2O_POSITION_DISTX_DIFF_THRES_FAR;
        f_LongDistDiffThresMax = LA_O2O_POSITION_DISTX_DIFF_THRES_FAR;
        f_LatDistDiffAbsThres  = LA_O2O_POSITION_DISTY_DIFF_PICKUP_FAR;
      }
      else
      {
        f_LongDistDiffThresMin = -LA_O2O_POSITION_DISTX_DIFF_THRES_NEAR;
        f_LongDistDiffThresMax = LA_O2O_POSITION_DISTX_DIFF_THRES_NEAR;
        f_LatDistDiffAbsThres  = LA_O2O_POSITION_DISTY_DIFF_PICKUP_NEAR;
      }

      /* Objects having low velocity difference are likely to follow each other on the same lane */
      /* Thus, decrease the search gate for longitudinal distances to a minimum */
      if (f_VrelDiffAbs < LA_O2O_POSITION_SAME_VEL_THRES)
      {
        f_LongDistDiffThresMin = -LA_O2O_POSITION_DISTX_DIFF_SAME_VEL;
        f_LongDistDiffThresMax = LA_O2O_POSITION_DISTX_DIFF_SAME_VEL;
      }

      /* As trucks are longer than cars, objects overtaking trucks do cut-out later */
      /* Thus, increase the upper search gate threshold for longitudinal distance  */
      if (*SLATE_pt_GetObjClassification(t_ObjNr) == SLATE_OBJCLASS_TRUCK)
      {
        f_LongDistDiffThresMax += LA_O2O_POSITION_DISTX_DIFF_MAX_TRUCK_ADD;
      }

      /* Hysteresis of thresholds */
      if (t_LA_InternalObjectData[t_ObjNrRel].t_O2O_EgoLaneAssocStatus.b_O2OEgoLaneObj == TRUE)
      {
        f_LatDistDiffAbsThres += LA_O2O_POSITION_DISTY_DIFF_THRES_HYST;
      }

      /* Check if position is inside search gate. Otherwise, the hint is not fulfilled. */
      if ( (f_LongDistDiff > f_LongDistDiffThresMax)
        || (f_LongDistDiff < f_LongDistDiffThresMin)
        || (f_LatDistDiffAbs > f_LatDistDiffAbsThres)
         )
      {
        b_hintO2OPosition = FALSE;
      }

      /* All conditions have to be fulfilled for an object to be assigned to ego lane by O2O analysis */
      if ( (b_hintO2ODoubleObject     == TRUE)
        && (b_hintO2OMirror           == TRUE)
        && (b_hintO2OLaneMatrix       == TRUE)
        && (b_hintO2OVrel             == TRUE)
        && (b_hintO2OTraceDistances   == TRUE)
        && (b_hintO2OPosition         == TRUE)
        )
      {
        t_ObjNrEgoLaneByO2O = t_ObjNr;
      }

#ifdef FCT_SIMU
      /* retain information about O2O selection loss reason from last cycle for debugging */
      if ( (t_LA_InternalObjectData[t_ObjNrRel].t_O2ODebugInfo.t_ObjNrEgoLaneByO2O == t_ObjNr) )
      {
        t_LA_InternalObjectData[t_ObjNrRel].t_O2ODebugInfo.b_hintO2ODoubleObject   = b_hintO2ODoubleObject;
        t_LA_InternalObjectData[t_ObjNrRel].t_O2ODebugInfo.b_hintO2OMirror         = b_hintO2OMirror;
        t_LA_InternalObjectData[t_ObjNrRel].t_O2ODebugInfo.b_hintO2OLaneMatrix     = b_hintO2OLaneMatrix;
        t_LA_InternalObjectData[t_ObjNrRel].t_O2ODebugInfo.b_hintO2OVrel           = b_hintO2OVrel;
        t_LA_InternalObjectData[t_ObjNrRel].t_O2ODebugInfo.b_hintO2OTraceDistances = b_hintO2OTraceDistances;
        t_LA_InternalObjectData[t_ObjNrRel].t_O2ODebugInfo.b_hintO2OPosition       = b_hintO2OPosition;
      }
#endif

    }
  }

#ifdef FCT_SIMU
  /* overwrite O2O information if new O2O object found */
  if (t_ObjNrEgoLaneByO2O != OBJ_INDEX_NO_OBJECT)
  {
    t_LA_InternalObjectData[t_ObjNrRel].t_O2ODebugInfo.b_hintO2ODoubleObject     = b_hintO2ODoubleObject;
    t_LA_InternalObjectData[t_ObjNrRel].t_O2ODebugInfo.b_hintO2OMirror           = b_hintO2OMirror;
    t_LA_InternalObjectData[t_ObjNrRel].t_O2ODebugInfo.b_hintO2OLaneMatrix       = b_hintO2OLaneMatrix;
    t_LA_InternalObjectData[t_ObjNrRel].t_O2ODebugInfo.b_hintO2OVrel             = b_hintO2OVrel;
    t_LA_InternalObjectData[t_ObjNrRel].t_O2ODebugInfo.b_hintO2OTraceDistances   = b_hintO2OTraceDistances;
    t_LA_InternalObjectData[t_ObjNrRel].t_O2ODebugInfo.b_hintO2OPosition         = b_hintO2OPosition;
    t_LA_InternalObjectData[t_ObjNrRel].t_O2ODebugInfo.t_ObjNrEgoLaneByO2O       = t_ObjNrEgoLaneByO2O;
  }
  else
  {
    /* retain information about O2O selection loss reason from last cycle for debugging */
    t_LA_InternalObjectData[t_ObjNrRel].t_O2ODebugInfo.t_ObjNrEgoLaneByO2O = OBJ_INDEX_NO_OBJECT;
  }
#endif

  return t_ObjNrEgoLaneByO2O;
}
#endif

#if (LA_CFG_O2O_EGO_LANE_ASSOC)
/*************************************************************************************************************************
  Functionname:    LA_b_O2OCheckO2OTraceRelationHint                                                             */ /*!

  @brief           Checks the trace O2O criteria for ego lane association of the "relevant" object.

  @description     Checks if the O2O trace criteria are fulfilled. Those include: the relevant object trace (or position if
                   trace not available) shall be closer to the VDY curve than the neighboring object trace (or position if
                   trace not available), the neighboring object is no split object, ego curve is not too strong in case traces 
                   are too short for both objects. Also, the sub-function LA_b_O2OCheckO2OTraceRelationFurtherAnalysis is
                   called which does further analysis of the trace relation.
                   @startuml
Partition LA_b_O2OCheckO2OTraceRelationHint{
Start
	-Initialize mean distances and standard deviation
	-Get trace mean distance to VDY course and its standard deviation for relevant object
	-Get trace mean distance to VDY course and its standard deviation for neighboring object
	- Longitudinal distance dependent threshold of trace standard deviation threshold of neighboring object
	if(traces are available for both objects) then (yes)
		-consider the trace mean distance to VDY course as a more accurate estimation of the distances of neighboring and relevant object
	elseif(Traces are available only for the relevant object)
	    -get the ACC trajectory distance of the object
		-consider the trace mean distance to VDY course as a more accurate estimation of the distance of the relevant object
	elseif(Traces are available only for the neighboring object)
		-get the ACC trajectory distance of the relevant object
		- consider the trace mean distance to VDY course as a more accurate estimation of the distance of the neighboring object
	else
		-get the ACC trajectory distance for both objects
	endif
	-calculate the trace absolute distance difference of relevant and neighboring object
	
	if(O2O Ego Lane Object is false)then (yes)
		-pick-up criteria is not fulfilled when neighboring object has lower mean distance than relevant object
	else
		-for higher longitudinal distances the absolute trace distance difference drop threshold is less stringent to avoid drop-outs9
	endif
	
	if(trace of relevant object is closer than trace of object) then (yes)
		-hint O2O Trace is FALSE
	elseif(object is split-objects) then (yes)
		-hint O2O Trace is FALSE
	else
		- Do further analysis of the traces to avoid false ego lane association
	endif
	
	if(relevant object mean distance and object mean distance is greater than or equal CP TRAJECTORY INVALID VALUE)
		-In curves traces are needed for reliable O2O ego lane association
	endif
	
end
}
@enduml 

  @return          boolean : TRUE, if criteria fulfilled [TRUE, FALSE]

  @param[in]       t_ObjNrRel : Input "relevant" object No [-1 ... EM_N_OBJECTS-1]
  @param[in]       t_ObjNr : Input neighboring object No [-1 ... EM_N_OBJECTS-1]

  @glob_in         *(pt_LAInput->t_FIPMOT.pu_FIPStaticTraceID(i)) : Trace index of object i [full range of unsigned char data type]
  @glob_in         t_LA_InternalObjectData[i].t_O2O_EgoLaneAssocStatus.b_O2OEgoLaneObj : Object i is on ego lane based on a object-to-object (O2O) relation analysis? [TRUE, FALSE]
  @glob_in         FCT_fBumperToCoG : distance from Bumper to Center of Gravity [full range of data type float32 >= 0.F]
  @glob_in         SLATE_f_GetSensorYPosition() : Sensor mounting lateral position [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @glob_in         pt_LAInput->t_RTE.pf_EgoCurve : Ego curve provided by VDY [-1 ... +1] m^-1
  @glob_in         *pt_LAInput->t_RTE.pf_ObjLongDisp  (i) : Longitudinal displacement of an object i [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
  @glob_in         OBJ_GET_CP(i).TrajDist : Structure of type CPObjDist2Traj_t, Information about objects relation to estimated course. Defined in cp_ext.h
  @glob_out        -

  @c_switch_part   
  @c_switch_full    LA_CFG_O2O_EGO_LANE_ASSOC : Compute object-to-object (O2O) relation based ego lane association
  @c_switch_full    FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         30.06.2016
  @changed         21.07.2016

  @author          Grant Davtjan | Grant.Davtjan@continental-corporation.com | +49-8382-9699-633
*************************************************************************************************************************/
static boolean LA_b_O2OCheckO2OTraceRelationHint( const ObjNumber_t t_ObjNrRel, const ObjNumber_t t_ObjNr)
{
  boolean b_hintO2OTrace = TRUE;         /* default return value */
  boolean b_hintO2OTraceFurtherAnalysis; /* return value of sub-function which does further analysis of the trace relation */

  TraceID_t t_RelTraceNr;     /* index of trace belonging to relevant object */
  TraceID_t t_ObjTraceNr;     /* index of trace belonging to neighboring object */
  float32 f_AbsTraceDistDiff; /* difference of absolute values of distances of both objects */

  /* Situation dependent thresholds */
  float32 f_AbsTraceDistDiffThres;   /* difference of absolute values of distances of both objects threshold */
  float32 f_ObjTraceDistStdDevThres; /* neighboring object's trace standard deviation threshold above which we do not consider its trace */

  /* Distance to trajectory used when trace mean distance not available */
  float32 f_DistObjToTraj; /* lateral distance between neighboring object and ACC trajectory */
  float32 f_DistRelToTraj; /* lateral distance between relevant object and ACC trajectory */

  /* Variables for distance and parallelism of trace calculation */
  GDBTrafoMatrix2D_t MOT2EGO = GDBGetTrafoMatrixByDisplacement( FCT_fBumperToCoG, SLATE_f_GetSensorYPosition() ); // PRQA S 1031 
  /* date: 2016-07-04, reviewer: Davtjan, Grant reason: Allowed in later versions of ISO C99*/
  /* Variable stores distance and parallelism of relevant object trace */
  CPTrace2CurveParallelism_t  t_TraceVDYCurvePara_Rel; 
  /* Variable stores distance and parallelism of neighboring object trace */
  CPTrace2CurveParallelism_t  t_TraceVDYCurvePara_Obj;

  /* Initialize mean distances and standard deviation */
  t_TraceVDYCurvePara_Rel.fDistMean   = CP_TRAJ_INVALID_VALUE;
  t_TraceVDYCurvePara_Obj.fDistMean   = CP_TRAJ_INVALID_VALUE;
  t_TraceVDYCurvePara_Obj.fDistStdDev = CP_TRAJ_INVALID_VALUE;

  /* Get trace mean distance to VDY course and its standard deviation for relevant object */
  t_RelTraceNr = OBJ_GET_STATIC_TRACE_ID(t_ObjNrRel);
  if (t_RelTraceNr < (TraceID_t)TRACE_NO_OF_TRACES)
  {
    t_TraceVDYCurvePara_Rel = CPFusionTraceCalcTraceCircleParallelism( t_RelTraceNr, *pt_LAInput->t_RTE.pf_EgoCurve, &MOT2EGO );
  }

  /* Get trace mean distance to VDY course and its standard deviation for neighboring object */
  t_ObjTraceNr = *(pt_LAInput->t_FIPMOT.pu_FIPStaticTraceID(t_ObjNr));
  if (t_ObjTraceNr < (TraceID_t)TRACE_NO_OF_TRACES)
  {
    t_TraceVDYCurvePara_Obj = CPFusionTraceCalcTraceCircleParallelism( t_ObjTraceNr, *pt_LAInput->t_RTE.pf_EgoCurve, &MOT2EGO );
  }

  /* Longitudinal distance dependent threshold of trace standard deviation threshold of neighboring object */
  if (*pt_LAInput->t_RTE.pf_ObjLongDisp(t_ObjNr) > LA_O2O_TRACEREL_OBJ_TRACE_STD_DISTX_FAR)
  {
    f_ObjTraceDistStdDevThres = LA_O2O_TRACEREL_OBJ_TRACE_STD_PARALLEL_FAR;
  }
  else
  {
    f_ObjTraceDistStdDevThres = LA_O2O_TRACEREL_OBJ_TRACE_STD_PARALLEL;
  }

  /* Do following calculation if traces are available for both objects */
  if ( (t_TraceVDYCurvePara_Rel.fDistMean < CP_TRAJ_INVALID_VALUE)
    && (t_TraceVDYCurvePara_Obj.fDistMean < CP_TRAJ_INVALID_VALUE)
    && (t_TraceVDYCurvePara_Obj.fDistStdDev < f_ObjTraceDistStdDevThres)
    )
  {
    /* consider the trace mean distance to VDY course as a more accurate estimation of the 
       distances of neighboring and relevant object */
    f_DistObjToTraj = t_TraceVDYCurvePara_Obj.fDistMean;
    f_DistRelToTraj = t_TraceVDYCurvePara_Rel.fDistMean;
  }
  /* Traces are available only for the relevant object */
  else if (t_TraceVDYCurvePara_Rel.fDistMean < CP_TRAJ_INVALID_VALUE)
  {
    /* get the ACC trajectory distance of the object */
    f_DistObjToTraj = pt_LAOutput->t_LAObjOutputList[t_ObjNr].TrajDist.TrajDistMeas.Y.f0;
    /* consider the trace mean distance to VDY course as a more accurate estimation of the 
       distance of the relevant object */
    f_DistRelToTraj = t_TraceVDYCurvePara_Rel.fDistMean;
  }
  /* Traces are available only for the neighboring object */
  else if ( (t_TraceVDYCurvePara_Obj.fDistMean < CP_TRAJ_INVALID_VALUE)
         && (t_TraceVDYCurvePara_Obj.fDistStdDev < f_ObjTraceDistStdDevThres) )
  {
    /* get the ACC trajectory distance of the relevant object */
    f_DistRelToTraj = pt_LAOutput->t_LAObjOutputList[t_ObjNrRel].TrajDist.TrajDistMeas.Y.f0;

    /* consider the trace mean distance to VDY course as a more accurate estimation of the 
       distance of the neighboring object */
    f_DistObjToTraj = t_TraceVDYCurvePara_Obj.fDistMean;
  }
  /* Traces are not available for both objects */
  else
  {
    /* get the ACC trajectory distance for both objects */
    f_DistRelToTraj = pt_LAOutput->t_LAObjOutputList[t_ObjNrRel].TrajDist.TrajDistMeas.Y.f0;
    f_DistObjToTraj = pt_LAOutput->t_LAObjOutputList[t_ObjNr].TrajDist.TrajDistMeas.Y.f0;
  }

  /* calculate the trace absolute distance difference of relevant and neighboring object */
  f_AbsTraceDistDiff = fABS(f_DistRelToTraj) - fABS(f_DistObjToTraj);

  /* Set threshold for trace absolute distance difference */
  if (t_LA_InternalObjectData[t_ObjNrRel].t_O2O_EgoLaneAssocStatus.b_O2OEgoLaneObj == FALSE)
  {
    /* pick-up criteria is not fulfilled when neighboring object has lower mean distance than relevant object */
    f_AbsTraceDistDiffThres = LA_O2O_TRACEREL_ABS_TRACE_DIST_DIFF_PICKUP;
  }
  else
  {
    /* for higher longitudinal distances the absolute trace distance difference drop threshold is less stringent to avoid drop-outs */
    f_AbsTraceDistDiffThres = dGDBmathLineareFunktion( &LAO2OTraceRelationAbsTraceDistDiffRamp, *pt_LAInput->t_RTE.pf_ObjLongDisp(t_ObjNrRel));
  }

  /* trace of relevant object has to be closer than trace of object */
  if (f_AbsTraceDistDiff > f_AbsTraceDistDiffThres)
  {
    b_hintO2OTrace = FALSE;
  }
  /* Avoid false ego-lane association of relevant object because of split-objects */
  else if ( (t_TraceVDYCurvePara_Obj.fDistMean < CP_TRAJ_INVALID_VALUE)
         && (t_TraceVDYCurvePara_Obj.fDistStdDev > LA_O2O_TRACEREL_OBJ_STD_DEV_MAX) )
  {
    b_hintO2OTrace = FALSE;
  }
  /* Avoid false ego-lane association of relevant object because of split-objects in strong curves */
  else if ( (fABS(*pt_LAInput->t_RTE.pf_EgoCurve) > LA_O2O_STRONG_CURVE_CURVATURE)
         && (t_TraceVDYCurvePara_Obj.fDistMean < CP_TRAJ_INVALID_VALUE)
         && (t_TraceVDYCurvePara_Obj.fDistStdDev > LA_O2O_TRACEREL_OBJ_TRACE_STD_DEV_MAX_STRONG_CURVE) )
  {
    b_hintO2OTrace = FALSE;
  }
  else
  {
    /* Do further analysis of the traces to avoid false ego lane association */
    b_hintO2OTraceFurtherAnalysis = LA_b_O2OCheckO2OTraceRelationFurtherAnalysis(t_ObjNrRel, f_DistRelToTraj, f_DistObjToTraj);

    if (b_hintO2OTraceFurtherAnalysis == FALSE)
    {
      b_hintO2OTrace = FALSE;
    }
  }

  /* Do following checks if traces are not available for at least one object */
  if ( (t_TraceVDYCurvePara_Rel.fDistMean >= CP_TRAJ_INVALID_VALUE)
    && (t_TraceVDYCurvePara_Obj.fDistMean >= CP_TRAJ_INVALID_VALUE)
     )
  {
    /* In curves traces are needed for reliable O2O ego lane association */
    if ( (t_LA_InternalObjectData[t_ObjNrRel].t_O2O_EgoLaneAssocStatus.b_O2OEgoLaneObj == FALSE)
      && (fABS(*pt_LAInput->t_RTE.pf_EgoCurve) > LA_O2O_CURVY_ROAD_CURVATURE) )
    {
      b_hintO2OTrace = FALSE;
    }
  }

  return b_hintO2OTrace;
}
#endif

#if (LA_CFG_O2O_EGO_LANE_ASSOC)
/*************************************************************************************************************************
  Functionname:    LA_b_O2OCheckO2OTraceRelationFurtherAnalysis                                                         */ /*!

  @brief           Perform further analysis of the trace relation of neighboring and "relevant" object for O2O ego lane association.

  @description     Function checks if the trace distance difference (when both objects are on different sides of trajectory) 
                   or absolute trace distance sum (when both objects are on the same side of trajectory) 
                   of "relevant" and neighboring object are above situation dependent thresholds. In those cases the "relevant"
                   object can't be assigned to ego lane with high confidence. In case ego is on mid lane and objects are on 
                   different sides of trajectory a more stringent threshold is used to avoid drop-ins. Also, in case objects are
                   on the same side of the trajectory the neighboring object shall not have a too high distance to trajectory.
                   @startuml
                   Partition LA_b_O2OCheckO2OTraceRelationFurtherAnalysis{
                   Start
                   	- calculate the trace distance difference of relevant and neighboring object
                   	-calculate the absolute trace distance sum of relevant and neighboring object
                   	if(the product of Distance Relevant To Trajectory and Distance Object To Trajectory is less than 0) then (yes)
                   		if(objects are on different sides of the ACC trajectory) then (yes)
                   			-stricter trace distance criteria on mid lane, as other criteria not available here
                   		else 
                   			-Trace Distance Difference Absolute Threshold is LA O2O TRACEREL TRACE DIST DIFF ABS PICKUP OUTERLANE
                   		endif
                   		-calculate Hysteresis of thresholds
                   		-check criteria when relevant object not very close to trajectory
                   	else
                   		-Longitudinal distance dependent threshold of absolute trace distance sum
                   	    -calculate Hysteresis of thresholds
                   		if(Absolute Trace Distance Sum is greater than Absolute Trace Distance Sum Threshold)then (yes)
                   			-hint O2O Trace Further Analysis is FALSE
                   		elseif(O2O Ego Lane Object is fale and "Dist Obj To Traj" greater than LA O2O TRACEREL OBJ DIST PICKUP MAX) then (yes)
                   			-hint O2O Trace Further Analysis is true
                   		else
                   			
                   		endif
                   	endif
                   end
                   }
                   @enduml

  @return          boolean : TRUE, if criteria fulfilled [TRUE, FALSE]

  @param[in]       t_ObjNrRel : Input relevant object No [-1 ... EM_N_OBJECTS-1]
  @param[in]       f_DistRelToTraj : relevant object trace sample mean distance to VDY curve 
                                     or distance to trajectory if trace not available [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @param[in]       f_DistObjToTraj : neighboring object trace sample mean distance to VDY curve 
                                     or distance to trajectory if trace not available [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m

  @glob_in         t_LA_InternalObjectData[i].t_O2O_EgoLaneAssocStatus.b_O2OEgoLaneObj : Object i is on ego lane based on a object-to-object (O2O) relation analysis? [TRUE, FALSE]
  @glob_in         *pt_LAInput->t_RTE.pf_ObjLongDisp  (i) : Longitudinal displacement of an object i [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m

  @glob_out        -

  @c_switch_part    FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING : FCT Input Preprocessing Lane matrix
  @c_switch_full    LA_CFG_O2O_EGO_LANE_ASSOC : Compute object-to-object (O2O) relation based ego lane association
  @c_switch_full    FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         30.06.2016
  @changed         21.07.2016

  @author          Grant Davtjan | Grant.Davtjan@continental-corporation.com | +49-8382-9699-633
*************************************************************************************************************************/
static boolean LA_b_O2OCheckO2OTraceRelationFurtherAnalysis( const ObjNumber_t t_ObjNrRel, float32 f_DistRelToTraj, float32 f_DistObjToTraj)
{
  boolean b_hintO2OTraceFurtherAnalysis = TRUE; /* default return value */

  float32 f_TraceDistDiffAbs;/* absolute value of difference of distances of both object's trace sample mean distance to VDY curve (or distance to trajectory if trace not available) */
  float32 f_AbsTraceDistSum; /* sum of absolute distances of both object's trace sample mean distance to VDY curve (or distance to trajectory if trace not available) */

  /* Situation dependent thresholds */
  float32 f_TraceDistDiffAbsThres; /* trace distance threshold */
  float32 f_AbsTraceDistSumThres;  /* absolute trace distance sum threshold */

#if (FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING)
  /* Number of left an right lanes */
  const sint8 i_NumberOfLeftLanes = (pt_LAInput->pt_FIPLaneMatrix->s_NumOfLaneLeft);
  const sint8 i_NumberOfRightLanes = (pt_LAInput->pt_FIPLaneMatrix->s_NumOfLaneRight);
#else
  /* assume one left and right lane when lane matrix not available */
  const sint8 i_NumberOfLeftLanes = (const sint8)1;
  const sint8 i_NumberOfRightLanes = (const sint8)1;
#endif

  /* calculate the trace distance difference of relevant and neighboring object */
  f_TraceDistDiffAbs = fABS(f_DistRelToTraj - f_DistObjToTraj);

  /* calculate the absolute trace distance sum of relevant and neighboring object */
  f_AbsTraceDistSum  = fABS(f_DistRelToTraj) + fABS(f_DistObjToTraj);

  if ((f_DistRelToTraj * f_DistObjToTraj) < 0.f)
  {
    /* objects are on different sides of the ACC trajectory */
    if ( (i_NumberOfLeftLanes != (sint8)0)
      && (i_NumberOfRightLanes != (sint8)0) )
    {
      /* stricter trace distance criteria on mid lane, as other criteria (e.g. border distance)
      not available here */
      f_TraceDistDiffAbsThres = LA_O2O_TRACEREL_TRACE_DIST_DIFF_ABS_PICKUP_MIDLANE;
    }
    else
    {
      f_TraceDistDiffAbsThres = LA_O2O_TRACEREL_TRACE_DIST_DIFF_ABS_PICKUP_OUTERLANE;
    }

    /* Hysteresis of thresholds */
    if (t_LA_InternalObjectData[t_ObjNrRel].t_O2O_EgoLaneAssocStatus.b_O2OEgoLaneObj == TRUE)
    {
      f_TraceDistDiffAbsThres = f_TraceDistDiffAbsThres + LA_O2O_TRACEREL_TRACE_DIST_DIFF_ABS_THRES_HYST;
    }

    /* check criteria when relevant object not very close to trajectory */
    if ( f_TraceDistDiffAbs > f_TraceDistDiffAbsThres)
    {
      b_hintO2OTraceFurtherAnalysis = FALSE;
    }

    /* add here more criteria here when both objects are on different sides of trajectory */
  }
  else
  {
    /* do following checks if both objects are on the same side of the ACC trajectory */

    /* Longitudinal distance dependent threshold of absolute trace distance sum */
    if (*pt_LAInput->t_RTE.pf_ObjLongDisp(t_ObjNrRel) > LA_O2O_TRACEREL_ABS_TRACE_DIST_SUM_DISTX_FAR)
    {
      f_AbsTraceDistSumThres = LA_O2O_TRACEREL_ABS_TRACE_DIST_SUM_PICKUP_FAR;
    }
    else
    {
      f_AbsTraceDistSumThres = LA_O2O_TRACEREL_ABS_TRACE_DIST_SUM_PICKUP;
    }

    /* Hysteresis of thresholds */
    if (t_LA_InternalObjectData[t_ObjNrRel].t_O2O_EgoLaneAssocStatus.b_O2OEgoLaneObj == TRUE)
    {
      f_AbsTraceDistSumThres = f_AbsTraceDistSumThres + LA_O2O_TRACEREL_ABS_TRACE_DIST_SUM_THRES_HYST;
    }

    if ( (f_AbsTraceDistSum > f_AbsTraceDistSumThres) )
    {
      b_hintO2OTraceFurtherAnalysis = FALSE;
    }
    else if ( (t_LA_InternalObjectData[t_ObjNrRel].t_O2O_EgoLaneAssocStatus.b_O2OEgoLaneObj == FALSE)
      && (fABS(f_DistObjToTraj) > LA_O2O_TRACEREL_OBJ_DIST_PICKUP_MAX) )
    {
      b_hintO2OTraceFurtherAnalysis = FALSE;
    }
    else
    {
      /* b_hintO2OTraceFurtherAnalysis = TRUE; */
    }

    /* add here more criteria here when both objects are on the same side of trajectory */
  }

  return b_hintO2OTraceFurtherAnalysis;
}

#endif /*!< (LA_CFG_O2O_EGO_LANE_ASSOC) */
/** @} end defgroup */
#endif /*!< (FCT_CFG_ACC_LANE_ASSOCIATION) */
/* ************************************************************************* */
/*   Copyright ADC-GmbH, Lindau                                              */
/* ************************************************************************* */
// PRQA L:STTLN_EXCEEDED
