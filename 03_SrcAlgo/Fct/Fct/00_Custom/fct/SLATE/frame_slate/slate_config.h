/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 SLATE (Situation Lane Association Trajectory Estimation)

PACKAGENAME:               slate_config.h

DESCRIPTION:               Configuration file for SLATE

AUTHOR:                    Umesh Babu Harsha (uidj3583)

CREATION DATE:             23.03.2017

VERSION:                   $Revision: 1.55.18.1 $

LEGACY VERSION:            None

**************************************************************************** */

#ifndef SLATE_CFG_H_INCLUDED
#define SLATE_CFG_H_INCLUDED

#include "fct_config.h"
#if (FCT_CFG_SLATE_COMPONENT)
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/*!
@defgroup slate_config Configuration
@ingroup frame
@brief    Contains all configuration switches related to the slate subcomponent.\n\n
@{
*/

/*****************************************************************************
  INCLUDES
*****************************************************************************/

/*****************************************************************************
  SYMBOLIC CONSTANTS (COMPONENT INTERN)
*****************************************************************************/


/*****************************************************************************
  MACROS (COMPONENT INTERN)
*****************************************************************************/
#define SLATE_CFG_ALGO_COMMON_AVAILABLE                     SWITCH_ON
/*****************************************************************************
  Config: Interfaces
*****************************************************************************/
/*! Configuration switch enabling simple navi input data to SLATE */
#define SLATE_CFG_SIMPLE_NAVI_INTERFACE           FCT_CFG_DEPENDENT_SWITCH(FCT_CFG_SEN_SIMPLE_NAVI_INTERFACE,SWITCH_ON)

/*! Configuration switch enabling camera lane input data to SLATE */
#define SLATE_CFG_CAM_LANE_INTERFACE              FCT_CFG_DEPENDENT_SWITCH(FCT_CFG_SEN_CAM_LANE_INTERFACE,SWITCH_ON)

/*! FCT switch for ACC Performance Monitoring (APM) */
#define SLATE_CFG_ACC_PERF_MONITORING             FCT_CFG_DEPENDENT_SWITCH(FCT_CFG_ACC_PERF_MONITORING,SWITCH_ON)

/*! Config switch for using Traces computed in EM, ATTENTION this is mutually exclusive with SLATE_CFG_USE_FCT_STATIC_TRACES */
#define SLATE_CFG_USE_EM_MOVING_OBJECT_TRACES     FCT_CFG_DEPENDENT_SWITCH((FCT_CFG_INPUT_PREPROCESSSING && FCT_CFG_USE_EM_MOVING_OBJECT_TRACES), SWITCH_ON)

/*! Configuration switch enabling overtake support feature*/
#define SLATE_CFG_ENABLE_OVERTAKE_ASSIST          FCT_CFG_DEPENDENT_SWITCH((FCT_CFG_CUSTOM_IO_INTERFACE && SIT_CFG_LC_USE_TURN_INDICATOR_INPUT), SWITCH_OFF)

/*! Configuration switch enabling use of drivemode input*/
#define SLATE_CFG_USE_DRIVE_MODE                  FCT_CFG_DEPENDENT_SWITCH((FCT_CFG_ACT_CODE_VERSION && FCT_CFG_LOHP_COMPONENT), SWITCH_OFF)

/*****************************************************************************
  Config: Modules
*****************************************************************************/

/*!  brief FCT support for CP sub-component */
#define FCT_CFG_COURSE_PREDICTION                 SWITCH_ON  

/*! FCT support for ACC LA (Lane Association) sub-component */
#define FCT_CFG_ACC_LANE_ASSOCIATION              SWITCH_ON

/*! FCT support for ACC OOI (Object Of Interest selection) sub-component */
#define FCT_CFG_ACC_OOI                           SWITCH_ON

/*! FCT support for ACC OUT (output) sub-component */
#define FCT_CFG_ACC_OUTPUT                        SWITCH_ON

/*! FCT support for ACC SIT (situation) sub-component */
#define FCT_CFG_ACC_SITUATION                     SWITCH_ON

/*! FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC */
#define FCT_CFG_INPUT_PREPROCESSSING              SWITCH_ON

/*****************************************************************************
  OUT Configurations
*****************************************************************************/
/*! Config switch which enables the SLATE support for TCI module */
#ifdef TCI_CFG_ENABLE
#define SLATE_CFG_TCI_BASE       FCT_CFG_DEPENDENT_SWITCH((FCT_CFG_TCI), SWITCH_OFF)
#else
#define SLATE_CFG_TCI_BASE       SWITCH_OFF
#endif

/*****************************************************************************
  FIP Configurations
*****************************************************************************/
/*! FCT support for Object Trace Preprocessing (FIP) and using Traces in FCT, irrespective of where they are computed! */
#define FCT_CFG_OBJECT_TRACE_PREPROCESSSING       SWITCH_ON

/* Trace preprocessing in FIP module */

/*! Switch for Enabling or disabling FCT Computed Traces in FIP module, ATTENTION this is mutually exclusive with SLATE_CFG_USE_EM_MOVING_OBJECT_TRACES */
#define FCT_CFG_USE_FCT_STATIC_TRACES                    FCT_CFG_DEPENDENT_SWITCH(FCT_CFG_INPUT_PREPROCESSSING, (SWITCH_OFF == SLATE_CFG_USE_EM_MOVING_OBJECT_TRACES))

/*! Switch for enabling or disabling FCT Computed Dynamic Traces in FIP module*/
#define FCT_CFG_USE_FCT_DYNAMIC_TRACES                    FCT_CFG_DEPENDENT_SWITCH(FCT_CFG_INPUT_PREPROCESSSING, SWITCH_OFF)

/*! Switch to get Left and Right Road Border input to FCT */
#define SLATE_CFG_LEFT_RIGHT_ROADBORDER_INPUT             FCT_CFG_DEPENDENT_SWITCH(FCT_CFG_ROAD_INPUT, SWITCH_OFF)

/*---  fip_object_traces.c ---*/
/*! Switch for enabling or disabling FCT Computed Ego Trace in FIP module*/
#define FIP_CFG_USE_EGO_TRACE                 (SWITCH_OFF)

#if( (SLATE_CFG_SIMPLE_NAVI_INTERFACE) && (FCT_CFG_INPUT_PREPROCESSSING) )
/* This config switch has to be moved back to fip_cfg.h when 
    FIP_v_CalcNaviPathApproxPosSample(CAL_t_PosSamples * pOutput)
    FIPGetNaviNumLaneAtDist(uint8 * pu_NumLane, const float32 fDist)
   are handled as IO between FIP, CP and LA
*/
#define FIP_EVAL_SHAPE_POINTS                     (SWITCH_ON)   /*!< Switch to enable the shape point evaluation */
#define SLATE_CFG_NAVI_OBJ_LAT_DIST        FCT_CFG_DEPENDENT_SWITCH( (FIP_EVAL_SHAPE_POINTS == SWITCH_OFF), SWITCH_OFF )
#endif /* (SLATE_CFG_SIMPLE_NAVI_INTERFACE) && (FCT_CFG_INPUT_PREPROCESSSING) */

/*Configuration switch to enable distance to road junction calculation */
#define FIP_EVAL_ROAD_JUNCTION                    FCT_CFG_DEPENDENT_SWITCH(SLATE_CFG_SIMPLE_NAVI_INTERFACE, SWITCH_OFF)

/*****************************************************************************
  CP Configurations
*****************************************************************************/
/*! @brief  Configuration switch to enable support for camera lane fusion features
when changing lanes */
#define CP_CFG_LANE_CHG_CAM_FUSION                FCT_CFG_DEPENDENT_SWITCH(SLATE_CFG_CAM_LANE_INTERFACE, SWITCH_ON)
/*! @brief  Configuration switch to enable low-pass filtering for Trace trajectory calculation, ATTENTION this is mutually exclusive with CP_CFG_TRACE_TRAJ_KALMAN_FILTER*/
#define CP_CFG_TRACE_TRAJ_LOWPASS_FILTER              FCT_CFG_DEPENDENT_SWITCH(FCT_CFG_COURSE_PREDICTION, SWITCH_ON)
/*! @brief  Configuration switch to enable kalman filter  for Trace Trajectoy calculation, ATTENTION this is mutually exclusive with CP_CFG_TRACE_TRAJ_LOWPASS_FILTER*/
#define CP_CFG_TRACE_TRAJ_KALMAN_FILTER               FCT_CFG_DEPENDENT_SWITCH(FCT_CFG_COURSE_PREDICTION, ( SWITCH_OFF == CP_CFG_TRACE_TRAJ_LOWPASS_FILTER))
/*****************************************************************************
  LA Configurations
*****************************************************************************/
///*--- la_corridor_cam.c ---*/
/*! Configuration switch, which moves the trace brackets based on the ego position in lane; 
    only active in combination with the camera lane interface */
    /*! In case of a lane change: */
#define LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM \
  FCT_CFG_DEPENDENT_SWITCH(((FCT_CFG_INPUT_PREPROCESSSING) && (SLATE_CFG_CAM_LANE_INTERFACE)), SWITCH_ON)
    /*! In case of no lane change: */
#define LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM \
  FCT_CFG_DEPENDENT_SWITCH(((FCT_CFG_INPUT_PREPROCESSSING) && (SLATE_CFG_CAM_LANE_INTERFACE)), SWITCH_ON)
    /*! In case of the blinker feature (FCT_CFG_CUSTOM_IO_INTERFACE need to be switched on): */
#define LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM \
  FCT_CFG_DEPENDENT_SWITCH(((FCT_CFG_INPUT_PREPROCESSSING) && (SLATE_CFG_CAM_LANE_INTERFACE) && (FCT_CFG_CUSTOM_IO_INTERFACE)), SWITCH_ON)

#define LA_CFG_DTR_OBJ_SELECTION                    0
#define LA_CFG_TRUCK_OBJ_SELECTION                  0

/*! Configuration switch to enable Shape Point for Inlap Calculation */
#define LA_CFG_USE_SHAPEPOINT_WITH_INLAP            SWITCH_ON

/*! Configuration switch to enable/disable relevant object extension. Note: was active
in old versions, thus default state should be ON! */
#define LA_CFG_EXT_RELEVANT_OBJECT                1

/*! @brief       Switch to enable restriction based on stationary objects in next lane
    @general     To avoid stationary objects which are on next lane being selected as OOI, restrictions are added to its corridor.
    @conseq      @incp  Restriction is ENABLED
                 @decp  Restriction is DISABLED
    @attention   Only applies to objects that are stationary, approach to such such can be negatively affected.
    @typical     0   @unit NO-UNIT     @min 0   @max 1   */
#define LA_CFG_ADD_RESTRICTION_STATOBJ_NEXTLANE     1 

/*! Configuration switch to enable restriction based on relevant object trace */
/* This restriction is aimed at improving cutouts */
#define LA_CFG_ADD_RESTRICTION_OBJ_TRACE \
  FCT_CFG_DEPENDENT_SWITCH((FCT_CFG_OBJECT_TRACE_PREPROCESSSING) && (FCT_CFG_ROAD_INPUT),  SWITCH_ON)

/* Enable Counter for Ego lane change indicator*/
#define LA_CFG_TURN_INDICATOR_COUNTER     FCT_CFG_DEPENDENT_SWITCH(FCT_CFG_CUSTOM_IO_INTERFACE, SWITCH_OFF)

/* Switch to Release the object early when Ego makes a lane change after turning on Indicator */
#define LA_CFG_RESTRICTION_EGO_LANE_CHANGE          FCT_CFG_DEPENDENT_SWITCH (LA_CFG_TURN_INDICATOR_COUNTER, SWITCH_OFF)

/* Configuration Switch to enable timer for ego lane change restriction */
#define LA_CFG_RESTRICTION_EGO_LANE_CHANGE_TIMER    FCT_CFG_DEPENDENT_SWITCH (LA_CFG_RESTRICTION_EGO_LANE_CHANGE, SWITCH_OFF)

/*! Configuration switch to enable a restriction in the near range for country road /city scenarios 
to improve the release of objects that take a turn */
#define LA_CFG_RESTRICTION_CITY_NEAR_RANGE          1 

/*! Configuration switch to determine if the camera lane object association is valid*/
#define LA_CFG_CAM_OBJ_ASSOC_VALID          FCT_CFG_DEPENDENT_SWITCH(((FCT_CFG_INPUT_PREPROCESSSING) && (SLATE_CFG_CAM_LANE_INTERFACE)), SWITCH_ON)

/*! Configuration switch which enables Checking the object lane association with respect to Camera Trajectory */
#define LA_CFG_OBJ_LANE_ASSOC_CAM_TRAJ              FCT_CFG_DEPENDENT_SWITCH(SLATE_CFG_CAM_LANE_INTERFACE, SWITCH_OFF)

/*! Configuration switch to enable bracket extension used for situations in 
which the relevant object moves in the direction of a near neighboring object.
For the relevant object the brackets are extended. Should only be active 
if camera lane information is available to detect the ego lane change phases. */
#define LA_CFG_EXT_NEIGHBORHOOD_REL_OBJ   FCT_CFG_DEPENDENT_SWITCH((LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM && \
  LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM && LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM), SWITCH_OFF) //ToBeDiscussed - Used in la_ext.h and thus can not be moved to la_cfg.h or la_par.h


/*! Configuration switch enabling the trace bracket adaption based on the navi information */
#if (SLATE_CFG_SIMPLE_NAVI_INTERFACE) && (FCT_CFG_INPUT_PREPROCESSSING)
/*! Configuration switch enabling the trace bracket extension on country roads (based on navi information) */
#define LA_CFG_NAVI_COUNTRYROAD_EXTENSION           1 
/*! Configuration switch enabling the trace bracket restriction close to an exit (based on navi information) */
#define LA_CFG_NAVI_OBJ_CLOSE_TO_EXIT_RESTRICTION   0 
#else
#define LA_CFG_NAVI_COUNTRYROAD_EXTENSION           0 
#define LA_CFG_NAVI_OBJ_CLOSE_TO_EXIT_RESTRICTION   0 
#endif

/*! Configuration switch, which enables corridor extension based on camera lane object association 
 Only to be enabled in case of camera lane information and camera object lane association 
 -> (FCT_CFG_INPUT_PREPROCESSSING) && (SLATE_CFG_CAM_LANE_INTERFACE) && (FCT_CFG_CAMERA_OBJECT_DETECTION) */
#if ((FCT_CFG_INPUT_PREPROCESSSING) && (SLATE_CFG_CAM_LANE_INTERFACE) && (FCT_CFG_CAMERA_OBJECT_DETECTION))
#define LA_CFG_CAM_LANE_OBJ_ASSOC_EXTENSION       1 
#else
#define LA_CFG_CAM_LANE_OBJ_ASSOC_EXTENSION       0 
#endif

/*! Configuration switch enabling the trace bracket extension for the blocked path between an object and an obstacle */
#if (FCT_CFG_COURSE_PREDICTION)
/* Only if FCT_CFG_COURSE_PREDICTION is ON will the blocked obstacle extension be usable */
#define LA_CFG_BLOCKED_OBSTACLE_EXTENSION             1 
#else
#define LA_CFG_BLOCKED_OBSTACLE_EXTENSION             0 
#endif

/*! Configuration switch for activating object-to-object (O2O) relation based ego lane association. */
/* No functional impact, computation only. Uses traces, distance to trajectory (to be removed) and CP extern functions */
#define LA_CFG_O2O_EGO_LANE_ASSOC \
  FCT_CFG_DEPENDENT_SWITCH(((FCT_CFG_OBJECT_TRACE_PREPROCESSSING) && (FCT_CFG_COURSE_PREDICTION) && (FCT_CFG_ROAD_INPUT) ), SWITCH_OFF)

/*! DTR (ARS4D0/ARS440) only: Configuration switch for activating object-to-object (O2O) relation based increase 
in pick-up distance up to maximum in case an object is O2O ego lane associated. 
O2O ego lane association has to be activated by switch LA_CFG_O2O_EGO_LANE_ASSOC.*/
#define LA_CFG_O2O_EGO_LANE_ASSOC_RANGE_EXTENSION \
  FCT_CFG_DEPENDENT_SWITCH(((LA_CFG_O2O_EGO_LANE_ASSOC) && (LA_CFG_DTR_OBJ_SELECTION) ), SWITCH_OFF)

/* Configuration switch to enable a bracket extension used for high-speed
approaches. For a relevant object which we approach very fast without
reliable road estimation, the brackets are extended */
#define LA_CFG_EXT_HIGHSPEED_APPROACH          1 

/* Configuration switch to enable a bracket extension used for improved robustness
against drop-outs in tunnels, since trajectory fusion inputs may be not available 
or less stable in this environment. For a relevant object which is already held for a 
long time the brackets are extended.*/
#define LA_CFG_ADD_EXT_TUNNEL_PROB         1

/* DTR (ARS4D0/ARS440) only: apply object-to-object (O2O) ego lane association by extending trace brackets. 
Extension overwrites high-speed approach brackets. O2O ego lane association has to be activated 
by switch LA_CFG_O2O_EGO_LANE_ASSOC. Also, SIT_CFG_CUSTOM_CRITERIA_MATRIX_PROCESSING
has to be activated. */

#define LA_CFG_O2O_EGO_LANE_ASSOC_BRACKET_EXTENSION \
  FCT_CFG_DEPENDENT_SWITCH(( (LA_CFG_O2O_EGO_LANE_ASSOC) && (LA_CFG_DTR_OBJ_SELECTION) ), SWITCH_OFF) // need to be verified by Grant 

/*! Extend trace brackets for low ego velocities and missing adjacent lanes.
  Since low speeds are currently a problem for lane-matrix, check with fused road
  border if a driveable lane exists */
#define LA_CFG_EXT_LOWSPEEDFUSEDBRD             0

/*Incase Driver steer away from Stationary object and number of lanes is unknown then don't apply extention */
#define LA_CFG_EXT_LOWSPEEDFUSEDBRD_DRIVER_STEER_AWAY          FCT_CFG_DEPENDENT_SWITCH(LA_CFG_EXT_LOWSPEEDFUSEDBRD, SWITCH_OFF)

/*Incase Driver steer away from Object and we have sufficient place to steer away from Object*/
#define LA_CFG_EXT_LOWSPEEDFUSEDBRD_SUFFICIENT_SPACE_STEER     FCT_CFG_DEPENDENT_SWITCH(LA_CFG_EXT_LOWSPEEDFUSEDBRD, SWITCH_OFF)

/*Used object orientation to release early if relevant object exiting the lane*/
#define LA_CFG_EXT_LOWSPEEDFUSEDBRD_ORIENTATION_ENABLE        FCT_CFG_DEPENDENT_SWITCH(LA_CFG_EXT_LOWSPEEDFUSEDBRD, SWITCH_OFF)

/*! Extend the trace bracket when the object is within the camera lane marker */
#define LA_CFG_EXT_LOWSPEEDFUSEDBRD_BASED_ON_CAM     FCT_CFG_DEPENDENT_SWITCH((LA_CFG_EXT_LOWSPEEDFUSEDBRD && SLATE_CFG_CAM_LANE_INTERFACE), SWITCH_OFF)

/*! Extend trace brackets for relevant object when there is parallel lane change
    Both ego and OOI-0 are doing lane change in the same direction */
#define LA_CFG_EXT_PARALLEL_LANE_CHANGE         FCT_CFG_DEPENDENT_SWITCH (SLATE_CFG_PARALLEL_LANE_CHANGE, SWITCH_OFF)

/* Configuration switch which enables the Counter which checks the validation of camera lane inputs for 0.18 sec before associating objects to Ego lane*/
#define LA_CFG_CAM_INLANE_STABLE_SELECTION        SWITCH_OFF

/*Switch to adapt camera lane association while Ego making Lane change*/
#define LA_CFG_ADAPT_CAM_LA_AT_EGO_LANE_CHANGE    FCT_CFG_DEPENDENT_SWITCH (FCT_CFG_CAMERA_OBJECT_DETECTION, SWITCH_OFF )

/*Switch to adapt camera lane association while Ego making Lane change*/
#define LA_CFG_ADAPT_CAM_LA_AT_TURN_INDICATOR     FCT_CFG_DEPENDENT_SWITCH ( (FCT_CFG_CAMERA_OBJECT_DETECTION && LA_CFG_TURN_INDICATOR_COUNTER), SWITCH_OFF )

/* ! Update Inlane Timer value for Stationary Objects on Curve */
#define LA_CFG_ADAPT_INLANE_TIME_CURVE_STAT       SWITCH_OFF

/*Switch to use SIT ego lane change info in extension high speed approach */
#define LA_CFG_USE_SIT_LANECHANGE_INFO       SWITCH_OFF                
/*****************************************************************************
  SIT Configurations
*****************************************************************************/

/*! Configuration switch enabling use of turn indicator input */
#define SIT_CFG_LC_USE_TURN_INDICATOR_INPUT        FCT_CFG_DEPENDENT_SWITCH(FCT_CFG_CUSTOM_IO_INTERFACE, SWITCH_OFF)

/*--- sit_objscore.c ---*/ 
/*! Configuration switch to enable new object scoring module */
#define SIT_CFG_OBJECT_SCORING           0


/*--- sit_traffic_estimation.c ---*/

/*! Configuration switch to enable/disable the calculation of a traffic flow and traffic jam probability (sit_traffic_estimation.c) */
#define SIT_CFG_TRAFFIC_ESTIMATION                 0

/*--- sit_calc_cutin_pot.c ---*/
/*! Configuration switch to enable multi object analyse as one input for the cutin potential 
if enabled, object OOI[3] (and OOI[2]) are compared to other objects ahead to determine a cutin potential */
#define SIT_CUTINPOTENTIAL_MULTIOBJECTANALYSE          0
/*! Configuration switch to enable O2O Lane Association information */
#define SIT_O2O_ANALYSIS \
  FCT_CFG_DEPENDENT_SWITCH(((FCT_CFG_OBJECT_TRACE_PREPROCESSSING) && (FCT_CFG_COURSE_PREDICTION) && (FCT_CFG_ROAD_INPUT) ), SWITCH_OFF)


/*Configuration switch to enable camera based trace bracket extension logic*/
#define SLATE_CFG_USE_BRACKETEXTENSION_ON_CAMERA				SWITCH_OFF


/*! Configuration switch for enabling overtake support for controller*/
#define SIT_LC_CFG_USE_OVERTAKE_IN_LANECHANGE       FCT_CFG_DEPENDENT_SWITCH(FCT_CFG_LOHP_COMPONENT, SWITCH_ON)

/*--- sit_objfeatures.c ---*/

/*! Config switch which enables the SLATE support for TCI module - Front Obstacle Detection Functionality */
#ifdef TCI_CFG_ENABLE
#define SLATE_CFG_TCI_FRONT_OBST_DETCD       FCT_CFG_DEPENDENT_SWITCH((SLATE_CFG_TCI_BASE), SWITCH_OFF)
#else
#define SLATE_CFG_TCI_FRONT_OBST_DETCD       SWITCH_OFF
#endif

/*****************************************************************************
  OUT Configurations
*****************************************************************************/
/*! Configuration switch for enabling obstacle probability*/
#define OUT_CFG_CUSTOM_OBSTACLE_PROBABILITY             (SWITCH_OFF)

/*! Configuration switch which provides Functional Lane Association during pre lane change to LOHP*/
#define OUT_CFG_FUNC_LANEASSOC_LA                     FCT_CFG_DEPENDENT_SWITCH(SIT_CFG_LC_USE_TURN_INDICATOR_INPUT,SWITCH_OFF)
/*****************************************************************************
  SLATE Configurations: External object ID
*****************************************************************************/
/*! Configuration switch to enable SI external object ID assignment */
#define SLATE_CFG_USE_EXT_OBJ_ID                SWITCH_ON

#if (SLATE_CFG_USE_EXT_OBJ_ID)
/*! Configuration switch to enable 1-1 mapping between internal ID
and external ID, simply counting up modulo EM_N_OBJECTS with the
external ID */
#define SLATE_CFG_EXTERN_ID_FROM_INTERN_ID_MODULO   1

/*! Configuration switch to enable assignment age based trackign of
external IDs (this means the object that has not been OOI for the
longest time will have it's ID removed if all external IDs are exhausted */
#define SLATE_CFG_EXT_ID_ASSIGN_AGE_TRACKING        0

/*! Configuration switch, when not set, only the objects that are in the
OOI list get external object IDs assigned. Otherwise when set all tracked
objects get external object IDs assigned */
#define SLATE_CFG_ASSIGN_EXT_OBJ_ID_FOR_ALL_OBJS    0

/*! Configuration switch enabling external ID assignment to all objects
that get a CD hypothesis assigned */
#define SLATE_CFG_ASSIGN_EXT_ID_CD_HYPOTHESIS       0

#endif /* SLATE_CFG_USE_EXT_OBJ_ID */

/*****************************************************************************
  Config: Features
*****************************************************************************/
/*! FCT Input Preprocessing Lane matrix (FIP Lane Matrix) */
/*! Config switch for FIP Lane Matrix: Need to be switched on for ACC */
#define FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING  FCT_CFG_DEPENDENT_SWITCH(FCT_CFG_INPUT_PREPROCESSSING, SWITCH_ON)
/*! Config switch for fusion of different input sources for FIP Lane Matrix */
#define FCT_CFG_FIP_LANE_MATRIX_FUSION            FCT_CFG_DEPENDENT_SWITCH(FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING && (FCT_CFG_SEN_CAM_LANE_INTERFACE || SLATE_CFG_SIMPLE_NAVI_INTERFACE), SWITCH_ON)

/* Config switch for fusion of navi information in traffic orientation. Remark: In RTE e_NaviTrafficOrientation need to be available */
#define FCT_CFG_FUSION_NAVI_TRAF_ORIENT  FCT_CFG_DEPENDENT_SWITCH(SLATE_CFG_SIMPLE_NAVI_INTERFACE, SWITCH_OFF)

/* Config switch for fusion of navi information in road type */
#define FCT_CFG_FUSION_NAVI_ROAD_TYPE  FCT_CFG_DEPENDENT_SWITCH(SLATE_CFG_SIMPLE_NAVI_INTERFACE, SWITCH_OFF)

/*! FCT support for Road based Curvature Change Computation in FIP */
#define FCT_CFG_ROAD_CURVATURE_CHANGE_COMPUTATION   FCT_CFG_DEPENDENT_SWITCH(FCT_CFG_INPUT_PREPROCESSSING && FCT_CFG_ROAD_INPUT, SWITCH_ON)

/*! FCT support for Navi based Curvature Change Computation in FIP */
#define FCT_CFG_NAVI_CURVATURE_CHANGE_COMPUTATION   FCT_CFG_DEPENDENT_SWITCH(FCT_CFG_INPUT_PREPROCESSSING && SLATE_CFG_SIMPLE_NAVI_INTERFACE, SWITCH_OFF)

/*! FCT support for Curvature Change Computation in FIP */
#define FCT_CFG_CURVATURE_CHANGE_COMPUTATION      FCT_CFG_DEPENDENT_SWITCH(FCT_CFG_INPUT_PREPROCESSSING && (FCT_CFG_SEN_SIMPLE_NAVI_INTERFACE || FCT_CFG_ROAD_INPUT), SWITCH_ON)

/* Camera based cut in probability for ooi lane association */
#define FCT_CFG_CAMERA_CUTIN_POTENTIAL           (SWITCH_OFF)  

/* Camera based cut in probability for ooi lane association */
#define FCT_CFG_CAMERA_CUTOUT_POTENTIAL          (SWITCH_OFF)  

/*! Dependency switch using navi,camlane and lanematrix for custom passing state  */
#define FCT_CFG_CUSTOM_PASSING_STATE    FCT_CFG_DEPENDENT_SWITCH(FCT_CFG_SEN_SIMPLE_NAVI_INTERFACE && FCT_CFG_SEN_CAM_LANE_INTERFACE && FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING ,SWITCH_OFF)


/* This is a copy of the ALGO_CFG_CameraRadarFusion - Global switch enabling EM/FCT code for fusion of camera and radar data
   TODO - Remove this after review since object fusion is active in ARS400 and already in series production */
#define SLATE_CFG_CAMERA_RADAR_FUSION             (SWITCH_ON)

/*! Configuration switch enabling low speed pedestrian selection support in
EM and FCT components. This switch was formerly in TP with the name
CFG_SI_LOW_SPEED_STAT_PEDESTRIAN or CFG_LOW_SPEED_STAT_PEDESTRIAN(in algo_cfg.h) */
#define SLATE_CFG_LOW_SPEED_STAT_PEDESTRIAN       (SWITCH_OFF)

/* Output interface switch for the ALGO signal state */
#define SLATE_CFG_USE_ALGO_SIGSTATE_INPUT_CHECK          (FCT_CFG_USE_ALGO_SIGSTATE_INPUT_CHECK)

/*! FCT camera object turn indicator usage in SLATE */
#define SLATE_CFG_CAMERA_TURN_INDICATOR_USAGE           FCT_CFG_DEPENDENT_SWITCH ( FCT_CFG_CAMERA_OBJECT_DETECTION, SWITCH_OFF )

/*! Configuration switch for enabling Parallel lane change detection */
#define SLATE_CFG_PARALLEL_LANE_CHANGE                  FCT_CFG_DEPENDENT_SWITCH( FCT_CFG_LOHP_COMPONENT, SWITCH_OFF )

/*! Configuration switch for enabling the selection of OOI during blocked path when Ego is in left most or right most lane*/
#define SLATE_CFG_EGO_LANE_DEPENDENT_BLOCKED_PATH       SWITCH_OFF
/************************************************************************/
/*                              Ports                                   */
/************************************************************************/

/*! @brief    Macro to determine the current number of require ports. Has to be aligned with the structure @ref reqSLATEPortList_t*/
#define SLATE_NOF_REQ_PORTS  (   ( (uint8)(0                                                                    ) )                            \
                               + ( (uint8)(1                                                                    ) ) /* pSenCtrlData */         \
                               + ( (uint8)(!FCT_CFG_SHORT_RANGE_FUNCTIONS                                       ) ) /* pEgoDynObjSync */       \
                               + ( (uint8)(1                                                                    ) ) /* pEgoDynRaw */           \
                               + ( (uint8)(1                                                                    ) ) /* pEgoStaticData */       \
                               + ( (uint8)(FCT_CFG_EM_FCT_CYCLEMODE                                             ) ) /* pEmFctCycleMode */      \
                               + ( (uint8)(  (FCT_CFG_OBJECT_LIST_PROC)       																   \
        /* This check for || (1) is done here to take into account the port count for the PubEmObj list when the GenObj list is unavailable */ \
                                           ||(1)                                                                ) ) /*pPubEmObj */             \
                               + ( (uint8)(   (FCT_CFG_OBJECT_LIST_PROC)                                                                       \
							                &&(FCT_USE_EM_CUSTOM_OBJECT_LIST)                                   ) ) /* pEmCustObjList */       \
                               + ( (uint8)(   (FCT_CFG_OBJECT_LIST_PROC)                                                                       \
                                            &&(FCT_USE_EM_ARS_TECH_OBJECT_LIST)                                 ) ) /* pEmARSObjList */        \
                               + ( (uint8)(   (FCT_CFG_OBJECT_LIST_PROC)                                                                       \
                                            &&(FCT_USE_EM_CAM_TECH_OBJECT_LIST)                                 ) ) /* pEmCamObjList */        \
                               + ( (uint8)((FCT_CFG_OBJECT_LIST_PROC) && (FCT_CFG_USE_EM_MOVING_OBJECT_TRACES)  ) ) /* pMovObjTraces */        \
                               + ( (uint8)(FCT_CFG_SIGNAL_PERF_MONITORING                                       ) ) /* pPerfDegrData */        \
                               + ( (uint8)(FCT_CFG_ROAD_INPUT                                                   ) ) /* pRoadData */            \
                               + ( (uint8)(FCT_CFG_RSP_CONTEXT_INPUT                                            ) ) /* pRSPContextData */      \
                               + ( (uint8)((FCT_CFG_CUSTOM_IO_INTERFACE) || (FCT_CFG_INCLUDE_UNUSED_INTF)       ) ) /* pFCTCustomInput */      \
                               + ( (uint8)((FCT_CFG_ALIGNMENT_MONITORING_INPUT) || (FCT_CFG_INCLUDE_UNUSED_INTF)) ) /* pAlignmentMonInput */   \
                               + ( (uint8)((FCT_CFG_ME_INPUT_FOR_DEBUG) || (FCT_CFG_INCLUDE_UNUSED_INTF)        ) ) /* pME_in */               \
                               + ( (uint8)((FCT_CFG_BSW_ALGO_PARAMS) || (FCT_CFG_INCLUDE_UNUSED_INTF)           ) ) /* pBswAlgoParameters */   \
                               + ( (uint8)((FCT_CFG_SEN_SIMPLE_NAVI_INTERFACE) || (FCT_CFG_INCLUDE_UNUSED_INTF) ) ) /* pNaviData */            \
                               + ( (uint8)(FCT_CFG_INCLUDE_FUSION_OBJECT_LIST                                   ) ) /* pEmFusionObjectList */  \
                               + ( (uint8)((SLATE_CFG_CAM_LANE_INTERFACE) || (FCT_CFG_INCLUDE_UNUSED_INTF)    ) ) /* pCamLaneData */         \
                               + ( (uint8)((FCT_CFG_TSA_INTF) || (FCT_CFG_INCLUDE_UNUSED_INTF)                  ) ) /* pCamSLAInputData */     \
                               + ( (uint8)(  (  (FCT_CFG_CAMERA_OBJECT_DETECTION)                                                              \
                                              &&(!FCT_USE_EM_CUSTOM_OBJECT_LIST) )                                                             \
                                           ||(FCT_CFG_INCLUDE_UNUSED_INTF)                                      ) ) /* pCameraObjData */       \
                               + ( (uint8)(  (FCT_CFG_ACT_CODE_VERSION) && (FCT_CFG_LOHP_COMPONENT)             ) )) /* pLongCtrlResp */


/*! @brief    Macro to determine the current number of provide ports. Has to be aligned with the structure @ref provSLATEPortList_t*/
#define SLATE_NOF_PRO_PORTS  (   ( (uint8)(0                                                                   ) )                                \
                               + ( (uint8)(FCT_CFG_ERROR_OUTPUT_SEN                                            ) ) /*pt_SLATEErrorOut*/           \
                               + ( (uint8)(FCT_CFG_USE_ALGOCOMPSTATE                                           ) ) /*pSenCompState*/              \
                               + ( (uint8)((FCT_CFG_OBJECT_LIST_PROC) && (FCT_CFG_ASSESSED_OBJ_OUT_INTF)       ) ) /* pPubFctObj */               \
                               + ( (uint8)(FCT_CFG_USE_BUS_DEBUG                                               ) ) /* pFCTSenBusDebugData */      \
                               + ( (uint8)(FCT_CFG_SEN2VEH_ACC_OOI_PORT                                        ) ) /* pFCTAccOOIData */           \
                               + ( (uint8)(FCT_CFG_SEN2TJA_ACC_OOI_PORT                                        ) ) /* pFCTTJAOOIData */           \
                               + ( (uint8)(FCT_CFG_LOHP_COMPONENT                                              ) ) /* pSLATE_HC_Data */           \
                               + ( (uint8)(FCT_CFG_SIGNAL_PERF_MONITORING                                      ) ) /* pSLATE_SPM_Data */          \
                               + ( (uint8)(FCT_CFG_COLLISION_DETECTION                                         ) ) /* pSLATE_CD_Data */           \
                               + ( (uint8)(   (FCT_CFG_CUSTOM_IO_INTERFACE)                                                                       \
                                            ||(FCT_CFG_INCLUDE_UNUSED_INTF)                                                                       \
                                            ||(FCT_CFG_SHORT_RANGE_FUNCTIONS)                                  ) )  /* pFCTCustomOutput */        \
                               + ( (uint8)(FCT_CFG_SLA_FEATURE                                                 ) ) )/* pSLAData */
#else

/*!  brief FCT support for CP sub-component */
#define FCT_CFG_COURSE_PREDICTION                 SWITCH_OFF  

/*! FCT support for ACC LA (Lane Association) sub-component */
#define FCT_CFG_ACC_LANE_ASSOCIATION              SWITCH_OFF

/*! FCT support for ACC OOI (Object Of Interest selection) sub-component */
#define FCT_CFG_ACC_OOI                           SWITCH_OFF

/*! FCT support for ACC OUT (output) sub-component */
#define FCT_CFG_ACC_OUTPUT                        SWITCH_OFF

/*! FCT support for ACC SIT (situation) sub-component */
#define FCT_CFG_ACC_SITUATION                     SWITCH_OFF

/*! FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC */
#define FCT_CFG_INPUT_PREPROCESSSING              SWITCH_OFF
#endif /* FCT_CFG_SLATE_COMPONENT */
/// @}

#endif /* SLATE_CFG_H_INCLUDED */
