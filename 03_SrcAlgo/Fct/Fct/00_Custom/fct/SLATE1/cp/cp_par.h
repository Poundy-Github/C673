/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   ARS5xx

CPU:                       CPU-Independent

COMPONENT:                 SLATE_CP (Course Prediction)

MODULNAME:                 cp_par.h

DESCRIPTION:               Course prediction parameters header

AUTHOR:                    $Author: Raj, Rahul (uid41599) $

CREATION DATE:             09.11.2009

VERSION:                   $Revision: 1.21 $

LEGACY VERSION:            Revision: 1.25.2.5

**************************************************************************** */
#ifndef CP_PAR_H_INCLUDED
#define CP_PAR_H_INCLUDED

#include "cp_cfg.h"
#include "slate_par.h"
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/*!
@defgroup cp_par Parameter
@ingroup cp
@brief        Contains all parameters that are used in cp and their values.\n\n
@description  This module does not contain any functions. It only contains defines as soon as variable initializations.
@{
*/

#if(CP_CFG_USE_LOWER_VEL_ROAD_FUSION == 1)
/*! @brief CP_FUSIONTRACESPEEDTHRESH */
#define CP_FUSIONTRACESPEEDTHRESH      (float32)(30.F/C_KMH_MS)
#else
/*! @brief CP_FUSIONTRACESPEEDTHRESH */
#define CP_FUSIONTRACESPEEDTHRESH      (float32)(40.F/C_KMH_MS)
#endif
#define CP_MIN_ACC_QUALITY              (75u)
#if (CP_CFG_USE_TRACE_FUSION_LOWER_VEL)
#define CP_FUSIONTRACESPEEDTHRESHCITY      (float32)(25.F/C_KMH_MS)
#define CP_FUSIONTRACESPEEDHYSTOFFSETCITY  (float32)(10.F/C_KMH_MS)
#endif/*CP_CFG_USE_TRACE_FUSION_LOWER_VEL*/

/*! @brief CP_FUSIONTRACESPEEDHYSTOFFSET */
#define CP_FUSIONTRACESPEEDHYSTOFFSET  (float32)(10.F/C_KMH_MS)
/*! @brief CP_FUSIONSPEEDHYSTOFFSET */
#define CP_FUSIONSPEEDHYSTOFFSET       (float32)(10.F/C_KMH_MS)
/*! @brief CP_MINFUSIONSPEED */
#define CP_MINFUSIONSPEED              (float32)(125.F/C_KMH_MS)/*@todo not used delete*/
/*! @brief CP_MINFUSIONCURVE */
#define CP_MINFUSIONCURVE             (1.F/500.F)
/*! @brief CP_MAXFUSIONCURVE */
#define CP_MAXFUSIONCURVE             (1.F/300.F)

#if(CP_CFG_USE_LOWER_VEL_ROAD_FUSION == 1)
/*! @brief CP_MINFUSIONEOROADCONFIDENCE */
#define CP_MINFUSIONEOROADCONFIDENCE  (85.0f)
/*! @brief CP_MAXFUSIONEOROADCONFIDENCE */
#define CP_MAXFUSIONEOROADCONFIDENCE  (90.0f)
#else
/*! @brief (uint8)(78) */
#define CP_MINFUSIONEOROADCONFIDENCE  (78.0f)
/*! @brief (uint8)(84) */
#define CP_MAXFUSIONEOROADCONFIDENCE  (84.0f)
#endif
/*! @brief CP_MINREFUSIONEGOSPEEDDIST */
#define CP_MINREFUSIONEGOSPEEDDIST            (80.0F) /* distance min */
/*! @brief CP_MAXREFUSIONEGOSPEEDDIST */
#define CP_MAXREFUSIONEGOSPEEDDIST            (165.0F) /* distace max */
/*! @brief CP_MAXREFUSIONEGOSPEED */
#define CP_MAXREFUSIONEGOSPEED                (200.0F/C_KMH_MS)
/*! @brief CP_MINREFUSIONEGOSPEED */
#define CP_MINREFUSIONEGOSPEED                (80.0F/C_KMH_MS)
/*! @brief CP_SAREFUSIONDISTHYST */
#define CP_SAREFUSIONDISTHYST                 (10.0F) /*Hysteresis for State*/
/*! @brief CP_CURVEDIRECTIONTHRESH */
#define CP_CURVEDIRECTIONTHRESH               (1.80f) /*m*/
/*! @brief CP_PARALLELISM_THRESH */
#define CP_PARALLELISM_THRESH                1.0F  /*Do not set to zero!!! causes division by zero*/
/*! @brief CP_PARALLELISM_MIN_LENGTH_TRACE */
#define CP_PARALLELISM_MIN_LENGTH_TRACE      ((sint8)4)
/*! @brief CP_PARALLELISM_MIN_RE_TRACKING_STAT */
#define CP_PARALLELISM_MIN_RE_TRACKING_STAT  5u
/*! @brief CP_PLAUSIBILITY_S_CURVE_CORRIDOR */
#define CP_PLAUSIBILITY_S_CURVE_CORRIDOR     1.5F
/*! @brief CP_EXTOBJAPPROX_PARALLELISM_MIN_LENGTH_TRACE */
#define CP_EXTOBJAPPROX_PARALLELISM_MIN_LENGTH_TRACE      ((sint8)2)

#if (SLATE_CFG_PARALLEL_LANE_CHANGE)
/* Thresholds for detecting object lane change */
#define CP_OBJECT_LANE_CHANGE_MIN_THRESHOLD      (0.001f)         /* Trace Curve Polynomial Average Curve Difference Min Threshold */
#define CP_OBJECT_LANE_CHANGE_MAX_THRESHOLD      (0.045f)         /* Trace Curve Polynomial Average Curve Difference Max Threshold */

/* Thresholds for detecting Trace Cut out */
#define CP_EGO_ACC_TRACE_DIFF_MIN_THRESHOLD      (0.22f)          /* Trace and Ego/ACC Path Difference Min Threshold */
#define CP_EGO_ACC_TRACE_DIFF_MAX_THRESHOLD      (0.34f)          /* Trace and Ego/ACC Path Difference Max Threshold */

#define CP_EGO_ACC_TRACE_DIFF_EGO_SPEED_THRES    (60.f/C_KMH_MS)  /* Trace and Ego/ACC Path Difference Ego Speed Threshold */
#define CP_EGO_ACC_TRACE_DIFF_MIN_LONG_DISP      (10.f)           /* Trace and Ego/ACC Path Difference Min Longitudinal Distance Threshold */
#define CP_EGO_ACC_TRACE_DIFF_MAX_LONG_DISP      (150.f)          /* Trace and Ego/ACC Path Difference Max Longitudinal Distance Threshold */
#endif /* (SLATE_CFG_PARALLEL_LANE_CHANGE) */

/*-------------------------------------------------------------------------
| Trajectory Fusion Parameters 
-------------------------------------------------------------------------*/
#if(CP_CFG_USE_LOWER_VEL_ROAD_FUSION == 1)
#define CP_MAXFUSIONSPEED              (float32)(70.F/C_KMH_MS)
#define CP_MAXFUSIONSPEEDWITHTRACEINFO (float32)(70.F/C_KMH_MS)
#else
/*! @brief CP_MAXFUSIONSPEED */
#define CP_MAXFUSIONSPEED              (float32)(105.F/C_KMH_MS)
/*! @brief CP_MAXFUSIONSPEEDWITHTRACEINFO */
#define CP_MAXFUSIONSPEEDWITHTRACEINFO (float32)(75.F/C_KMH_MS)
#endif

/*! @brief time distanse for fusion sampeling*/
#define CP_SAMPLETIMEDIST              (4.F)
/*! @brief minimum distanse for fusion sampeling (set to MAX to disable faeture)*/
#define CP_SAMPLEDIST_MIN              (50.F)
/*! @brief maximum distanse for fusion sampeling*/
#define CP_SAMPLEDIST_MAX               (200.F)

/*! @brief minimum std for gradient update*/
#define CP_GRADUPDATE_STD_MIN           (0.01F)

/*! @brief RE plausibility parameters for C1 ramp (ego vs re plausibilisation)*/
#define CP_PLAUSIBILITY_HIGHWAY_HIGHSPEED    (150.F/C_KMH_MS)
/*! @brief CP_PLAUSIBILITY_HIGHWAY_LOWSPEED */
#define CP_PLAUSIBILITY_HIGHWAY_LOWSPEED     (80.F/C_KMH_MS)
/*! @brief CP_PLAUSIBILITY_HIGHWAY_HIGHSPEED_A */
#define CP_PLAUSIBILITY_HIGHWAY_HIGHSPEED_A  250.0F
/*! @brief CP_PLAUSIBILITY_HIGHWAY_LOWSPEED_A */
#define CP_PLAUSIBILITY_HIGHWAY_LOWSPEED_A   60.0F

/*! @brief EGO STD parameters for C1 ramp (weight of ego in grad update)*/
#define CP_COURSE_GRADUPDATE_STD_HIGHSPEED    (150.F/C_KMH_MS)
/*! @brief CP_COURSE_GRADUPDATE_STD_LOWSPEED */
#define CP_COURSE_GRADUPDATE_STD_LOWSPEED     (40.F/C_KMH_MS)
/*! @brief CP_COURSE_GRADUPDATE_STD_HIGHSPEED_A */
#define CP_COURSE_GRADUPDATE_STD_HIGHSPEED_A  150.0F
/*! @brief CP_COURSE_GRADUPDATE_STD_LOWSPEED_A */
#define CP_COURSE_GRADUPDATE_STD_LOWSPEED_A   30.0F
/*! @brief trajectory noise*/
#define CP_TRAJ_NOISE_C1            2.0e-3f
/*! @brief CP_TRAJ_NOISE_C1_SQR */
#define CP_TRAJ_NOISE_C1_SQR        (CP_TRAJ_NOISE_C1 * CP_TRAJ_NOISE_C1)

/*-------------------------------------------------------------------------
| Lane change camera lane fusion parameters (config switch: CP_CFG_LANE_CHG_CAM_FUSION)
-------------------------------------------------------------------------*/
/*! @brief Minimal visibility distance in meters for lane marker visibility for fusion with ACC course @unit:m */
#define CP_PAR_MIN_LANE_MARKER_VISIB_DIST   20.f

/*! @brief Minimal visibility distance for lane marker visibility (Ratio  Visibility_Dist/ACC_Pickup_Dist) */
#define CP_PAR_MIN_CAM_LANE_FUS_DIST_RATIO       0.65f

/*!  @brief Minimal visibility timegap in seconds for lane marker visibility for fusion with ACC course @unit:s */
#define CP_PAR_MIN_LANE_MARKER_VISIB_TIMEGAP  2.f

/*!  @brief Maximum camera curvature to use for fusion */
#define CP_PAR_MAX_CAM_CURVATURE            (1e-2f)

/*!  @brief Maximum ego speed for camera marker fusion */
#define CP_PAR_MAX_CAM_LANE_FUS_SPEED       (150.0f/C_KMH_MS)

/*!  @brief Hysteresis value used for ego max speed offset for camera marker fusion */
#define CP_PAR_CAM_HYST_OFFSET_LANE_FUS_SPEED_MAX       (10.f/C_KMH_MS)

/*!  @brief Hysteresis value used for ego min speed offset for camera marker fusion. 
		    Make sure that ((CP_PAR_MIN_CAM_LANE_FUS_SPEED-CP_PAR_CAM_HYST_OFFSET_LANE_FUS_SPEED_MIN) > 0) is true.*/
#define CP_PAR_CAM_HYST_OFFSET_LANE_FUS_SPEED_MIN       (10.f/C_KMH_MS)

/*!  @brief Minimum ego speed for camera marker fusion @min:CP_PAR_CAM_HYST_OFFSET_LANE_FUS_SPEED_MIN @max:CP_PAR_MAX_CAM_LANE_FUS_SPEED */
#define CP_PAR_MIN_CAM_LANE_FUS_SPEED       (30.f/C_KMH_MS)

/*!  @brief Minimum number camera trajectory samples */
#define CP_PAR_MAX_CAM_SAMPLES_LR_FUS       (8u)

/*!  @brief Maximum number of trace trajectory samples */
#define CP_PAR_MIN_TRACE_SAMPLES_LR_FUS     (12u)

/*!  @brief Minimum distance to which parallelism CAM to VDY shall be checked @unit:m @min:10 @max:200 */
#define CP_PARALLELISM_MIN_LENGTH_CAM       (80u)

/*!  @brief Threshold of standard deviation CAM to VDY, above cam trajectory fusion is thrown away */
#define CP_PARALLELISM_THRES_CAM            (3.0f)

/*!  @brief Hysteriesis value used for thresholds ACC course fusion is on @min:0.01 @max:1 */
#define CP_PAR_CAM_LANE_FUSION_HYST         0.75f

/*!  @brief Maximum camera lane angle for fusion of camera lane with ACC course @unit:rad */
#define CP_PAR_MAX_CAM_LANE_ANGLE           DEG2RAD(6.f)

/*!  @brief The activation threshold for lane change recognition: if DIM lane change probability exceeds
this threshold, then fusion with camera course is activated */
#define CP_PAR_DIM_LANE_CHANGE_PROB_MIN     65u

/*!  @brief The activation threshold for lane change recognition in lateral acceleration deviation between
filtered (low-pass) lateral acceleration and driver intended lateral acceleration */
#define CP_PAR_LAT_ACC_THRES_CAM_LANE_ACTIVE  0.1f

/*!  @brief The activation time of how long camera lane fusion is active after a lane change was detected @unit:s */
#define CP_PAR_CAM_LANE_CHANGE_ACTIVATION_TIME  2.5f

/*!  @brief The default lane marker offset when lane change trajectory modification is active @unit:m @min:0 @max:3 */
#define CP_PAR_DEFAULT_LC_MARKER_OFFSET         1.5f

/*! @brief  The minimum distance of the lane marker on a given side for lane change to assume that the next lane
marker is the destination lane Example: if set to 1 m, then that means when lane change to the left is
active and the left lane marker is in 0.2m distance, then it is assumed that the destination lane is
between the left and beyond left lane markers. @unit:m @min:0 @max:3 */
#define CP_PAR_LC_MIN_MARKER_DIST               1.0f

/*!  @brief The maximum distance of the lane marker on a given side for lane change to assume that the next lane
marker is the destination lane Example: if set to 1 m, then that means when lane change to the left is
active and the left lane marker is in 0.2m distance, then it is assumed that the destination lane is
between the left and beyond left lane markers. @unit:m @min:#CP_PAR_LC_MIN_MARKER_DIST @max:10 */
#define CP_PAR_LC_MAX_MARKER_DIST               5.6f

/*!  @brief The minimum distance of a lane marker in non-lane-change case @unit:m @min:0 @max:3 */
#define CP_PAR_NO_LC_MIN_MARKER_DIST            0.05f

/*! @brief  The maximum distance of a lane marker in non-lane change case. (I.e.: lane change already took
place and we are in the destination lane) @unit:m @min:#CP_PAR_NO_LC_MIN_MARKER_DIST @max:5 */
#define CP_PAR_NO_LC_MAX_MARKER_DIST            4.2f

/*! @brief  Maximum lane width for camera lane fusion in non-lane change case @unit:m @min:1 @max:10 */
#define CP_PAR_NO_LC_MAX_LANEWIDTH              5.0f

/*!  @brief Tolerance in Y direction when solving second order equation to find X coordinate where
ego dynamics based trajectory meets the camera lane center @unit:m */
#define CP_CAM_LANE_FUSION_EGO_LANE_TOLERANCE   1.0f

/*! @brief  Parameter for maximum average driver intended curvature vs trace distance
[in m] for a given trace to be fused into the ACC trajectory. @unit:m */
#define CP_PAR_MAX_TRACE_EGO_AVG_DIFF     1.25f

/*!  @brief Parameters for increasing trace fusion's gradient update standard deviation
depending on average error [in m] from the driver intended curvature over the next
second when lane available on given side. The add-on standard deviation is linearly
ramped between CP_PAR_EGO_LA_TRACE_ERR_STD_DEV_MIN .. CP_PAR_EGO_LA_TRACE_ERR_STD_DEV_MAX,
for average errors between CP_PAR_EGO_LA_TRACE_ERR_MIN .. CP_PAR_EGO_LA_TRACE_ERR_MAX */

/*! Parameters for increasing trace fusion's gradient update standard deviation
depending on average error [in m] from the driver intended curvature over the
next second when directly driving on trace and no lane known in given direction. */

/*! Parameters for increasing trace fusion's standard deviation depending
on the distance of the trace at X=0. When lanes are splitting, then this
increase in stddev leads to lower weighting of far away lane objects */
/*! @brief CP_MOT_POINT_STDDEV_THRESH */
#define CP_MOT_POINT_STDDEV_THRESH              1.5f
/*! @brief CP_MIN_PEX_FOR_VALID_TRACE */
#define CP_MIN_PEX_FOR_VALID_TRACE              96u /*0.96f*/
/*! @brief CP_ONETRACEGRADFUSIONDIST */
#define CP_ONETRACEGRADFUSIONDIST               80.0F
/*!  @brief standard deviation for gradient update of traces */
#define CP_MOT_SLOPEANGLE_STDDEV                DEG2RAD(5.f)

/*!  @brief maximum lateral Acceleration when following a trace in m/s2 */
#define CP_TRACE_MAX_PLAUSIBLE_LAT_ACCEL        (8.f)

#if (CP_CFG_LIMIT_UNPLAUSIBLE_S_CURVE_VALUE)
/*!  @brief minimun longitudinal unplausible s-curve distance */
#define CP_MIN_DISTX_UNPLAUSIBLE_SCURVE            (100.f)
#endif /* (CP_CFG_LIMIT_UNPLAUSIBLE_S_CURVE_VALUE) */

/*-------------------------------------------------------------------------
| Navi Fusion Parameters - customer specific
-------------------------------------------------------------------------*/

#if (SLATE_CFG_SIMPLE_NAVI_INTERFACE) && (FCT_CFG_INPUT_PREPROCESSSING)

/*!  @brief Lower hysteresis limit for Valid EGO speed range */
#define CP_NAVI_HYST_MIN_VALID_SPEED            (90.f/C_KMH_MS)
/*!  @brief Required threshold for Valid EGO speed range */
#define CP_NAVI_REQ_VALID_SPEED                 (100.f/C_KMH_MS)

#endif

/*-------------------------------------------------------------------------
| City Cam Fusion Parameters - customer specific
-------------------------------------------------------------------------*/
#if (CP_CFG_ADAPT_CAM_FUSION_IN_CITY)

#define CP_EGO_SPEED_HIGHWAY (float32)(72.F/C_KMH_MS) /* Maximum Ego speed in City */
#define CP_LOW_EGO_SPEED     (float32)(50.4F/C_KMH_MS) /* Low speed threshold for Ego in City */
#define CP_LOW_EGO_SPEED_VISIBILITY   (30.0f) /* Visibility distance required for Ego at Low Speed in City */
#define CP_HIGH_EGO_SPEED_VISIBILITY  (35.0f) /* Visibility distance required for Ego at High Speed in City */
#define CP_CITY_LC_PROB               (20u)   /* Lane change probability for Lane Change in City */

#endif /* (CP_CFG_ADAPT_CAM_FUSION_IN_CITY) */

#endif
/** @} end defgroup */
