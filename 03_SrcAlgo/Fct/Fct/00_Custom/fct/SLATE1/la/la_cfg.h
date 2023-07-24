/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 SLATE_LA (Lane Association)

PACKAGENAME:               la_cfg.h

DESCRIPTION:               Configuration Header File for ACC Lane Association (LA) module

AUTHOR:                    Boll Marie-Theres (uidu1091)

CREATION DATE:             20.06.2016

VERSION:                   $Revision: 1.65.20.1 $

LEGACY VERSION:            Revision: 1.9

**************************************************************************** */
#ifndef LA_CFG_H_INCLUDED
#define LA_CFG_H_INCLUDED

#include "slate_config.h"
#if (FCT_CFG_ACC_LANE_ASSOCIATION)
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/*!
@defgroup la_cfg Configuration
@ingroup la
@brief    Contains all configuration switches related to the la subcomponent.\n\n
@{
*/
/*--- la_acc_function_presel.c ---*/

/*-- la_corridor.c ---*/

/*! Configuration switch for enabling modification (narrowing) of seek lane
width based on lane width class from EM */
#define LA_CFG_SEEK_LANE_WIDTH_USE_LANE_CLASS   FCT_CFG_DEPENDENT_SWITCH(FCT_CFG_ROAD_INPUT, SWITCH_ON)

/*! Configuration switch for enabling calibration of seek lane width over
XCP (creation of global variable for overriding default seek width) */
#define LA_CFG_CALIBRATE_SEEK_LANE_WIDTH        0

/*! Configuration switch allowing limitation of seek lane width based on tunnel probability*/
# define LA_CFG_LIMIT_LANEWIDTH_IN_TUNNEL           1

/*! Configuration switch, which enables use of camera information for lane width detection */
#if ((FCT_CFG_INPUT_PREPROCESSSING) && (SLATE_CFG_CAM_LANE_INTERFACE))
#define LA_CFG_ADAPT_LANEWIDTH_BASED_ON_CAM       FCT_CFG_DEPENDENT_SWITCH(FCT_CFG_ROAD_INPUT,1)
#else
#define LA_CFG_ADAPT_LANEWIDTH_BASED_ON_CAM       0
#endif

/*--- la_corridor_radarroad.c ---*/

/*! configuration switch for enabling road border criteria */
#define LA_CFG_USE_ROAD_BORDER_BRACKET_CRITERIA  1

/* Configuration Switch to Adapt Road Border trace bracket extension for Objects having smaller Object width i.e. Motorcycle, bicycle, pedestrian */
#define LA_CFG_ROAD_BORDER_EXT_LESSER_WIDTH_OBJS    FCT_CFG_DEPENDENT_SWITCH(LA_CFG_USE_ROAD_BORDER_BRACKET_CRITERIA, SWITCH_OFF)

/*! Configuration switch allowing extension of track lane width based on road
border estimation. Useful when rel. objects is merged with mirror in guardrail */
#define LA_CFG_GUARDRAILROADBORDER_HIGHWAY      1

/*! Configuration switch to enable extended CurveInnerBorder criterion */
/* in very narrow curves extend the trace bracket on the curve inner side beyond the FOV */
/* currently extension up to azimuth angle 39 degree on both sides) */
/* fixes parts of Dante1368 - dropout in traffic circle */
#define LA_EXTENDED_CURVEINNERBORDER_CRITERION    1

/* do not apply wide bracket criteria in case of steering gradient is leading out of curve and there is another lane available */ 
/* fixes some special situation with late release of a cutout object */
/* but also causes some drop outs in curvy following / approach situation */
#define LA_EXTENDED_CURVEINNERBORDER_CRITERION_WEAKER (LA_EXTENDED_CURVEINNERBORDER_CRITERION && SWITCH_OFF)

/*! Limit the inner curve border extension based on the curvature of the course and the position of the object */
#define LA_CFG_LIMIT_CURVE_INNER_BORDER_EXT       0

/*! Configuration switch to apply Curve Road Border Extension based on Dist2Traj */
#define LA_CFG_CURVE_INNER_BORDER_EXT_DIST_TO_TRAJ       0

/*! Configuration switch to enable/disable additive Curve Road Border Extension (default mode) */
#define LA_CFG_USE_ADDITIVE_CURVE_INNER_ROAD_BORDER_EXTENSION    SWITCH_ON

/*! Limit the camera lane gate pickup quality for ego lane change */
#define LA_CFG_LIMIT_CAM_LANE_GATE_PICKUP         SWITCH_OFF

/* Switch to enable camera confirmation for trace brackets (Disabling camera confirmation check for ARS510VW19/20 temporarily due to wrong camera input) */
#define LA_CFG_ENABLE_CAM_VALIDITY        FCT_CFG_DEPENDENT_SWITCH(FCT_CFG_CAMERA_OBJECT_DETECTION, SWITCH_ON)

/*--- la_corridor_trackwidth.c ---*/

/*! Configuration switch to enable/disable extension object approximation. Note: was active
in old versions, thus default state should be ON! */
#define LA_CFG_ADD_EXTENSION_OBJ_APPROX           1

/*--- la_corridor_cam.c ---*/

/*! Configuration switch, which moves the trace brackets based on the ego position in lane; 
    only active in combination with the camera lane interface */
    /*! In case of a lane change: */
    /*! Use the BMW blinker feature (LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM need to be switched on);
        otherwise the turn indicator signal is used */
#define LA_CFG_ADAPT_TRACEBRACKETS_USE_BMW_BLINKER_FEATURE \
  FCT_CFG_DEPENDENT_SWITCH(LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM, SWITCH_OFF)

/*--- la_corridor_cam_adapt.c ---*/

/*! Configuration switch, which enables corridor extension based on camera lane object association 
 Only to be enabled in case of camera lane information and camera object lane association 
 -> (FCT_CFG_INPUT_PREPROCESSSING) && (SLATE_CFG_CAM_LANE_INTERFACE) && (FCT_CFG_CAMERA_OBJECT_DETECTION) */

/*--- la_corridor_navi.c ---*/

/*! Configuration switch enabling the trace bracket adaption based on the navi information */

/*--- la_geometric_lane_assoc.c ---*/

/*! Configuration switch which enables the adaptation of Inlap Drop threshold based on OOI-0 & OOI-1 kinematics */
#define LA_CFG_ADAPT_OUTLANE_INLAP_DROP_THRESHOLD              SWITCH_OFF

/*! Configuration switch which enables the adaptation of Inlap Pickup threshold based on Relative lateral velocity */
#define LA_CFG_ADAPT_INLANE_INLAP_PICKUP_THRESHOLD             SWITCH_ON

/*! Configuration switch which enables the adaptation of Inlane Time Threshold for stationary objects based on vdy curvature */
#define LA_CFG_ADAPT_INLANE_TIME_THRESHOLD_STAT_OBJ_CURVE      SWITCH_OFF

/*! Configuration switch which enables the adaptation of Inlane Time Threshold using blocked path timer */
#define LA_CFG_ADAPT_BLOCKED_PATH_TIMER_BASED_INLANE_TIME      SWITCH_OFF

/*! Configuration switch which enables the adaptation of Inlap Pickup threshold based on Relative longitudinal velocity  */
#define LA_CFG_INLANE_INLAP_PICKUP_THRESHOLD_VRELX             SWITCH_OFF

/*! Configuration switch to increase In-Lane Time Threshold based on the Camera Trajectory Based Lane Association */
#define LA_CFG_ADAPT_INLANE_TIME_CAM_TRAJ_LA                   FCT_CFG_DEPENDENT_SWITCH(LA_CFG_OBJ_LANE_ASSOC_CAM_TRAJ, SWITCH_OFF)

/*! Configuration switch to adapt Pickup Threshold based on the Camera Trajectory Based Lane Association */
#define LA_CFG_ADAPT_PICKUP_THRES_CAM_TRAJ_LA                  FCT_CFG_DEPENDENT_SWITCH(LA_CFG_OBJ_LANE_ASSOC_CAM_TRAJ, SWITCH_OFF)

/*--- la_pred_lane_assoc.c ---*/

/*! Configuration switch to disable radar-based predicted outlane functionality e.g. for the entry sensor due to bad tracking */
/*! Recommendation for entry sensor radar-only projects: SWITCH_ON, Recommendation for other projects: SWITCH_OFF */
#define LA_CFG_NO_RADAR_PREDICTED_OUTLANE             SWITCH_ON

/*Configuration switch to disable predicted lane associtaion for ego velocity less than 80 KPH*/
/*Note: Right now these checks are done only for ARS510TA19, Validation is still needs to be performed on other projects as well*/
#define LA_PRED_EGO_VEL_MIN_DISABLE                   SWITCH_OFF

/*Configuration switch to enable predicted lane associtaion for ego velocity less than 80 KPH*/
/*Note: Right now these checks are done only for ARS510TA19, Validation is still needs to be performed on other projects as well*/
#define LA_PRED_EGO_VEL_AND_OBJ_DISTX_ENABLE          SWITCH_ON

/*! Configuration switch allowing the use of extended prediction time(EPT) for objects that are in NEAR region */
#define LA_CFG_USE_EXTENDED_PRED_TIME_NEAR_OBJECTS    SWITCH_ON

/*! Configuration switch to use pickup border values decreasing with distance */
#define LA_CFG_DECREASING_PICKUP_BORDER               SWITCH_OFF

/*! Configuration switch to use ego turn indicator for early pickup of the object */
#define LA_CFG_EGO_TURNIND_BASED_PICKUP               SWITCH_OFF

/*! Configuration switch to use pred time extenstion bascd on lateral standard deviation for early selection of the object */
#define LA_CFG_USE_EXTENDED_PRED_TIME_BASED_ON_LAT_STD               SWITCH_OFF

/*--- la_laneassociation.c ---*/

/*! Configuration switch for enabling modification of occupancy handling for
objects at high angles. Objects seen at great angles have a tendency to have
very high standard deviations leading to very late pickups */
#define LA_CFG_MANIPULATE_OCCUPANCY_AT_HIGH_ANGLES  1

/*! Configuration switch allowing the use of object orientation angle(OOA) in overlap and occupancy calculations for objects that are in NEAR region */
#define LA_CFG_USE_OBJECT_ORIENTATION_NEAR_OBJECTS    1

/*! Configuration switch to prevent orientation based object width adaption for OOI0 which intends to cut out */
#define LA_CFG_DISABLE_OBJECT_ORIENTATION_FOR_OOI0    FCT_CFG_DEPENDENT_SWITCH(LA_CFG_USE_OBJECT_ORIENTATION_NEAR_OBJECTS, SWITCH_OFF)

/*! Configuration switch to enable situative increase of inlane timer as a
  function of relative velocity, curvature, and distance */
#define LA_SIT_VREL_INLANE_TIME_INC                1

/*! Configuration switch to enable increase of inlane timer as a
  function of approximate time-to-collision (distance divided by relative velocity) */
#define LA_TTC_DEPENDANT_INLANE_TIME  0

/*! Configuration switch to enable suppression of objects at high velocities when ego is on the left lane */
/*! This feature is useful for german autobahn and above 140 kph. It should be made dependent on traffic direction. */
/* When an object is detected and there is no other object which could be overtaken by it, */
/* increase the in-lane timer */
#define LA_HIGH_VEGO_INLANE_TIME \
  FCT_CFG_DEPENDENT_SWITCH(FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING,  SWITCH_ON)

/*! Configuration switch enabling additional object quality check for objects and only allowing
them to become in-lane when the function LA_b_CheckObjInlaneAllowed() returns TRUE */
#define LA_CFG_ADD_CHECK_INLANE_TRANSITION        1

/*! Configuration switch enabling increased in-lane time for objects with micro doppler signature 
Prerequisite: active micro doppler computation in EM (CFG_EM_PED_MICRO_DOPPLER)
and updated interface */
#define LA_CFG_MICRODOPPLER_PEDESTRIAN_HIGH_INLANE_TIME  0

/*! Switch for Parked Object detection using Right and Left Road Border inputs */
#define LA_CFG_ENABLE_PARKED_DETECTION            FCT_CFG_DEPENDENT_SWITCH(SLATE_CFG_LEFT_RIGHT_ROADBORDER_INPUT,  SWITCH_OFF)

/*--- la_laneassociation_stateflow.c ---*/

/*! Configuration switch, which sets selection of bicycles and motocycles 
on left and right OOI position ON, even if no lane was recognized.
see FR95432 (Zweir‰der auch bei nicht vorhandenener Nebenspur als Nebenspurobjekt [DANTE 1345])*/
#define LA_CFG_NOLANE_BIKE_SELECTION                 1

/*! Configuration switch, which sets selection of cars and trucks
on left and right OOI position ON, even if no lane was recognized.
see Issue 321998 (Traktor auf schmalem Standstreifen auf zweispuriger Landstraﬂe erh‰lt keine Vorselektion als rechtes Nebenspurobjekt [DANTE 5244])*/
#define LA_CFG_NOLANE_VEHICLE_SELECTION               0

/*--- la_customfunctions.c ---*/

/*! Configuration switch to activate additional call to custom
SICustomCorridorPreProcessing , which allows to enable or disable
selected corridor bracket functions before their actual calculation */
#define LA_CFG_CUSTOM_CORRIDOR_PREPROCESSING      1

/*!@brief   Configuration switch to enable calculation of last object position in
function CPCalculateObjectReference. This value is not used anywhere in the
software. A seperate switch for it was created to clarify if this functionality
is needed in the future. @todo: Clarify if needed! */
#define LA_CFG_TRAJECTORY_USE_LAST_OBJ_POS        0

/*! Additional check if object fulfills the characteristics of a likely false positive event on a narrow highway. 
This information is used to tighten the ego-lane association criteria e.g. the in-lane time threshold is increased, the predicted
pick-up is turned off and the pick-up range is set to a minimum. */
#define LA_CFG_NARROW_HIGHWAY_CRITERIA            FCT_CFG_DEPENDENT_SWITCH((FCT_CFG_INPUT_PREPROCESSSING && FCT_CFG_ROAD_INPUT),  SWITCH_ON)

/* Switch to analyze gap Between Stationary Cars to Detect Parking Row for Camera confirmed Objects */
#define LA_CFG_CAM_PARKING_DETECTED               FCT_CFG_DEPENDENT_SWITCH(FCT_CFG_CAMERA_OBJECT_DETECTION, SWITCH_OFF)

/* Switch to Update Pick-Up threshold for camera confirmed Objects to improve slow cut-ins in city  */
#define LA_CFG_CAM_INLANE_THRSHOLD_UPDATE         FCT_CFG_DEPENDENT_SWITCH( (SLATE_CFG_CAMERA_RADAR_FUSION && FCT_CFG_CAMERA_OBJECT_DETECTION), SWITCH_OFF)

/*! Detect trajectory Dynamism in case based on OOI-0 Dist2Traj value  */
#define LA_CFG_TRAJ_DYNAMISM_DETECTION            SWITCH_OFF
/* ! Update Inlane Time value for obstacles based on Object's Distance to Road Border */
#define LA_CFG_ADAPT_INLANE_TIME_FOR_OBSTACLES    SWITCH_OFF

/* Switch to Update Inlane Time value for Slow Trucks which are longitudinally at higher distance */
#define LA_CFG_ADAPT_INLANE_FAR_TRUCK			SWITCH_OFF

/*switch to enable/disable trace bracket restriction according to distance of objects*/
#define LA_CFG_NEAR_NEIGHBOURHOOD_DIST_REDUCTION                SWITCH_OFF

/*! Restrict track lane width for calculating Base corridor for Road type highway
  Since Road type detection from  Navi in ARS410VW29  is not accurate, check plausibilation of road type with lane width class from EM */
#define LA_CFG_LANE_WIDTH_CLASS_PlAUSIBLE         FCT_CFG_DEPENDENT_SWITCH(LA_CFG_SEEK_LANE_WIDTH_USE_LANE_CLASS, SWITCH_ON) /* Enabled only for ARS410VW29, to be removed when Navi input is correct */

/*! Configuration switch which enables lower prediction time for objects which has 
    longitudinal distance less than 30m to reduce DropIn and DropOut OR object is classified as TRUCK by both Radar AND Camera*/
#define LA_CFG_LOWER_PRED_TIME_FOR_CLOSER_DIST    SWITCH_OFF

/* Outlane counter based on Situation */
#define LA_CFG_ADAPT_OUTLANE_COUNTER_THRESHOLD    SWITCH_ON

/*! Configuration switch which enables Outlane counter adaption based on object lane association with respect to Camera Trajectory */
#define LA_CFG_ADAPT_OUTLANE_COUNTER_CAM_LANE_ASSOC   FCT_CFG_DEPENDENT_SWITCH(LA_CFG_ADAPT_OUTLANE_COUNTER_THRESHOLD && LA_CFG_OBJ_LANE_ASSOC_CAM_TRAJ, SWITCH_OFF)

/* Configuration switch to Adapt Trajectory Dynamism detection to reduce Drop Threshold in Single City Lane Scenario */
#define LA_CFG_ADAPT_TRAJ_DYNAMISM_CITY_NO_LANE   SWITCH_OFF

/* Configuration switch to restrict trace bracket if OOI-0 is in Left Lane or Right Lane based on CameraTrajectoryLaneAssociation */
#define LA_CFG_RESTRICTION_CITY_NEAR_RANGE_LANE_ASSOC_CAM_TRAJ          FCT_CFG_DEPENDENT_SWITCH(LA_CFG_OBJ_LANE_ASSOC_CAM_TRAJ, SWITCH_OFF) 

/*--- la_corridor_radarroad.c ---*/

/*! Configuration switch to reduce split object dropin */
#define LA_CFG_AVOID_SPILT_OBJ                    SWITCH_ON

/*! Configuration switch to check camera outlane and lane change to enable ExtensionRoadBorderCI */
#define LA_CFG_CHK_CAM_OUTLANE_AND_LANECHANGE     SWITCH_ON

/* Configuration switch to not extend Extension Highway GuardRail RoadBorder depending on Camera Trajectory based Lane Association */
#define LA_CFG_DISABLE_EXTENSION_CAM_TRAJ_LA             FCT_CFG_DEPENDENT_SWITCH(LA_CFG_OBJ_LANE_ASSOC_CAM_TRAJ, SWITCH_OFF)

/* Configuration switch to reduce In-Lane Time and In-Lane Distance threshold (only for Car, Truck and Motorbike classification) depending on Camera Trajectory based Lane Association */
#define LA_CFG_ADAPT_IN_LANE_TIME_AND_DIST_CAM_TRAJ_LA   FCT_CFG_DEPENDENT_SWITCH(LA_CFG_OBJ_LANE_ASSOC_CAM_TRAJ, SWITCH_OFF)

/*! Configuration switch to disable low speed fused road border extension when distance to trajectory of the object is more than the threshold */
#define LA_CFG_DISABLE_EXT_LOWSPEEDFUSEDBRD_BASED_ON_DIST2TRAJ                    FCT_CFG_DEPENDENT_SWITCH(LA_CFG_EXT_LOWSPEEDFUSEDBRD_SUFFICIENT_SPACE_STEER, SWITCH_OFF)

/* Configuration Switch to use last turn indicator status and trajectory hypothesis for ego lane change restriction */
#define LA_CFG_USE_TURNIND_LASTSTATUS               FCT_CFG_DEPENDENT_SWITCH (LA_CFG_RESTRICTION_EGO_LANE_CHANGE, SWITCH_OFF)

#endif
#endif
/** @} end defgroup */
