/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 FCT_sen

PACKAGENAME:               slate_types.h

DESCRIPTION:               This files is used for structures and type definitions used across SLATE component

AUTHOR:                    $Author: Raj, Rahul (uid41599) $

CREATION DATE:             15.02.2017

VERSION:                   $Revision: 1.65 $

LEGACY VERSION:            Revision: 2.0

**************************************************************************** */

/* Previously this file was named fct_sen_feedback.h */
#ifndef SLATE_TYPES_H_INCLUDED
#define SLATE_TYPES_H_INCLUDED

#if (FCT_CFG_SLATE_COMPONENT) 

#include "slate_custom_types.h"
#include "slate_ver.h"

#ifdef __cplusplus
/* All internal _ext headers shall contain proper C++ extern C
declarations, to allow directly including them in C++ sources. */
extern "C" {
#endif

/************************************************************************/
/*                      MODULE DESCRIPTION                              */
/************************************************************************/
/*!
@addtogroup slate
@brief    Contains all types that are used in the slate frame or commonly in more than one subcomponent.
@{
*/
/*****************************************************************************
  INCLUDES
*****************************************************************************/

/*****************************************************************************
  SYMBOLIC CONSTANTS
*****************************************************************************/
  /*! @brief CP_NB_TRAJ_STATE */
#define CP_NB_TRAJ_STATE                   (uint8)(2)
#define CP_NB_TRAJ_STATE2                  (uint8)(2u*CP_NB_TRAJ_STATE)

#if (CP_CFG_TRACE_TRAJ_KALMAN_FILTER)
  /*! @brief CP_NB_TRAJ_STATE */
#define CP_NB_TRACE_TRAJ_STATE                   (uint8)(2)
#define CP_NB_TRACE_TRAJ_STATE2                  (uint8)(2u*CP_NB_TRACE_TRAJ_STATE)
#endif
#if (FCT_CFG_SENSOR_TYPE_RADAR)   // radar sensor 
/* Object type/Dynamic Property */
#define SLATE_OBJECT_PROPERTY_STATIONARY ARS_OBJECT_PROPERTY_STATIONARY
#define SLATE_OBJECT_PROPERTY_MOVING     ARS_OBJECT_PROPERTY_MOVING
#define SLATE_OBJECT_PROPERTY_ONCOMING   ARS_OBJECT_PROPERTY_ONCOMING

#define SLATE_OBJECT_SUBPROP_NORMAL      ARS_OBJECT_SUBPROP_NORMAL
#define SLATE_OBJECT_SUBPROP_CROSSING    ARS_OBJECT_SUBPROP_CROSSING

/* Object Class */
#define SLATE_OBJCLASS_POINT         ARS_OBJCLASS_POINT
#define SLATE_OBJCLASS_CAR           ARS_OBJCLASS_CAR
#define SLATE_OBJCLASS_TRUCK         ARS_OBJCLASS_TRUCK
#define SLATE_OBJCLASS_PEDESTRIAN    ARS_OBJCLASS_PEDESTRIAN
#define SLATE_OBJCLASS_MOTORCYCLE    ARS_OBJCLASS_MOTORCYCLE
#define SLATE_OBJCLASS_BICYCLE       ARS_OBJCLASS_BICYCLE
#define SLATE_OBJCLASS_WIDE          ARS_OBJCLASS_WIDE
#define SLATE_OBJCLASS_UNCLASSIFIED  ARS_OBJCLASS_UNCLASSIFIED
#endif

#if (FCT_CFG_SENSOR_TYPE_CAMERA)  // Camera sensor
/* Object type/Dynamic Property */
#define SLATE_OBJECT_PROPERTY_STATIONARY     EM_GEN_OBJECT_DYN_PROPERTY_STATIONARY  // checked for usage since it is different in ARS vs CAM . ARS might mnean also Stopped (subprop). Can it mean also crossing??
#define SLATE_OBJECT_PROPERTY_MOVING         EM_GEN_OBJECT_DYN_PROPERTY_MOVING      // can it mean also crossing in ARS?
#define SLATE_OBJECT_PROPERTY_ONCOMING       EM_GEN_OBJECT_DYN_PROPERTY_ONCOMING    // can it mean also crossing in ARS?
#define SLATE_OBJECT_PROPERTY_CROSSING_LEFT  EM_GEN_OBJECT_DYN_PROPERTY_CROSSING_LEFT
#define SLATE_OBJECT_PROPERTY_CROSSING_RIGHT EM_GEN_OBJECT_DYN_PROPERTY_CROSSING_RIGHT
#define SLATE_OBJECT_PROPERTY_UNKNOWN        EM_GEN_OBJECT_DYN_PROPERTY_UNKNOWN
#define SLATE_OBJECT_PROPERTY_STOPPED        EM_GEN_OBJECT_DYN_PROPERTY_STOPPED

/* Object Class */
#define SLATE_OBJCLASS_POINT         EM_GEN_OBJECT_CLASS_POINT
#define SLATE_OBJCLASS_CAR           EM_GEN_OBJECT_CLASS_CAR
#define SLATE_OBJCLASS_TRUCK         EM_GEN_OBJECT_CLASS_TRUCK
#define SLATE_OBJCLASS_PEDESTRIAN    EM_GEN_OBJECT_CLASS_PEDESTRIAN
#define SLATE_OBJCLASS_MOTORCYCLE    EM_GEN_OBJECT_CLASS_MOTORCYCLE
#define SLATE_OBJCLASS_BICYCLE       EM_GEN_OBJECT_CLASS_BICYCLE
#define SLATE_OBJCLASS_WIDE          EM_GEN_OBJECT_CLASS_WIDE
#define SLATE_OBJCLASS_UNCLASSIFIED  EM_GEN_OBJECT_CLASS_UNCLASSIFIED
#endif

/*****************************************************************************
  MACROS 
*****************************************************************************/
#ifndef FCT_MEAS_ID_SEN_ACC_FRAME_DATA
#define FCT_MEAS_ID_SEN_ACC_FRAME_DATA  (0x20270609u)  //0x20270600u 0x202705A3 0x20270000u FCT_MEAS_ID_SEN_FRAME_DATA 0x202705FCu
#endif

#define FCT_MEAS_ID_ACCSEN_COMP_STATE       0x20267954

#if (FCT_CFG_USE_ALGOCOMPSTATE)
#ifndef FCT_MEAS_ID_SEN_ACC_COMP_STATE
#define FCT_MEAS_ID_SEN_ACC_COMP_STATE      FCT_MEAS_ID_ACCSEN_COMP_STATE
#endif
#endif

#define SLATE_MAX_NB_TRAJ_SAMPLES                 (20u)
#if (FCT_CFG_OBJECT_TRACE_PREPROCESSSING)
#if (FCT_CFG_USE_FCT_STATIC_TRACES)
/* New  traces calculated for the FCT */
/* Number of traces that are processed in FCT */
#define FIP_STATIC_TRACE_NO_OF_TRACES           (10u)
/* Maximum number of sample trace points in each trace */
#define FIP_STATIC_TRACE_NO_OF_POINTS           (25)
#else
/* SLATE_CFG_USE_EM_MOVING_OBJECT_TRACES */
/* Number of traces that are processed in FCT */
#define FIP_STATIC_TRACE_NO_OF_TRACES           TRACE_NO_OF_TRACES
/* Maximum number of sample trace points in each trace */
#define FIP_STATIC_TRACE_NO_OF_POINTS           TRACE_NO_OF_POINTS
#endif /* END IF (FCT_CFG_USE_FCT_STATIC_TRACES) */
#endif /* END IF (FCT_CFG_OBJECT_TRACE_PREPROCESSSING) */

#if (SLATE_CFG_CAM_LANE_INTERFACE)
/*!number of camlanes*/
#define FIP_CL_NUM_LANES   4U
/*!Camlane Adjust Left*/
#define FIP_CL_MK_ADJ_LEFT  0U
/*!Camlane Left*/
#define FIP_CL_MK_LEFT      1U
/*!Camlane Right*/
#define FIP_CL_MK_RIGHT     2U
/*!Camlane Adjust Right*/
#define FIP_CL_MK_ADJ_RIGHT 3U
#endif/*END OF SLATE_CFG_CAM_LANE_INTERFACE*/

#if( (SLATE_CFG_SIMPLE_NAVI_INTERFACE) && (FCT_CFG_INPUT_PREPROCESSSING) )
#if FIP_EVAL_SHAPE_POINTS
#define FIP_NUM_HIST_SHAPE_POINTS         (3u)      /*!< Number of history shape points (the last shape points which the ego vehicle passed) */
#define FIP_NUM_HIST_SHAPE_POINTS_BUFFER  (3u)      /*!< Number of history shape points buffer, this is typically same size as FIP_NUM_HIST_SHAPE_POINTS */

/*!< Total number of segments in NAVI reference coordinate system */
#define FIP_NUM_NAVI_REF_SEGMENTS         (FCT_NAV_NUM_SEG + (FIP_NUM_HIST_SHAPE_POINTS + FIP_NUM_HIST_SHAPE_POINTS_BUFFER))
/*!< Total number of shape points in NAVI reference coordinate system */
#define FIP_NUM_NAVI_REF_SHAPE_POINTS     (FCT_NAV_NUM_SEG + FIP_NUM_HIST_SHAPE_POINTS + FIP_NUM_HIST_SHAPE_POINTS_BUFFER + 1)
/* +1 for Ego position considered as origin */
#define FIP_NUM_NAVI_PATH_SHAPE_POINTS    ((uint8)FCT_NAV_NUM_SEG + 1u) /*!< Number of shape points of the future NAVI path with reference to EGO */
#endif /* FIP_EVAL_SHAPE_POINTS */
#endif /* (SLATE_CFG_SIMPLE_NAVI_INTERFACE) && (FCT_CFG_INPUT_PREPROCESSSING) */

/* Length of path occupation array */
#define SIT_PATH_OCC_ENTRIES ((2 * EM_N_OBJECTS) + 4)
/*****************************************************************************
  MODULLOKALE SYMBOLISCHE KONSTANTEN - Device Freeze Addresses
*****************************************************************************/
/*! Address of SIT device measurement freeze */
#ifndef FCT_MEAS_ID_SIT_DEVICE
#define FCT_MEAS_ID_SIT_DEVICE      (0x20285000u)  /* to be moved to RTE, ADDRESS : 0x20285000 <-> 539512832u */
#endif

/*! Address of SIT device measurement freeze */
#ifndef FCT_MEAS_ID_FIP_DEVICE
#define FCT_MEAS_ID_FIP_DEVICE      (0x20270360u)  /* to be moved to RTE, ADDRESS : 0x20270360 <-> 539427680u */
#endif

/*! Address of CP device measurement freeze */
#ifndef FCT_MEAS_ID_CP_DEVICE
#define FCT_MEAS_ID_CP_DEVICE       (0x20240100u)  /* to be moved to RTE, ADDRESS :  0x20240100 <-> 539230464u */
#endif

/*! Address of LA device measurement freeze */
#ifndef FCT_MEAS_ID_LA_DEVICE
#define FCT_MEAS_ID_LA_DEVICE       (0x20263500u)  /* to be moved to RTE, ADDRESS : 0x20263500 <-> 539374848u */
#endif

/*! Address of OUT device measurement freeze */
#ifndef FCT_MEAS_ID_OUT_DEVICE
#define FCT_MEAS_ID_OUT_DEVICE      (0x20260280u)  /* to be moved to RTE, ADDRESS : 0x20260280 <-> 539361920u */
#endif
#if (FCT_CFG_LOHP_COMPONENT)
#ifndef FCT_MEAS_ID_SEN_SLATE_HC_DATA
#define FCT_MEAS_ID_SEN_SLATE_HC_DATA  (0x202FCB84)
#endif
#endif

/*****************************************************************************
  MODULLOKALE SYMBOLISCHE KONSTANTEN - Simulation Freeze Addresses
*****************************************************************************/
  /*! Address of CP Simulation measurement freeze */
#ifdef FCT_SIMU
#ifndef FCT_MEAS_ID_CP_SIM
#define FCT_MEAS_ID_CP_SIM          (0x20260B00)  /* to be moved to RTE, ADDRESS : 0x20260B00 <-> 539364096u */
#endif
#endif

  /*! Address of FIP Simulation measurement freeze */
#ifdef FCT_SIMU
#ifndef FCT_MEAS_ID_FIP_SIM
#define FCT_MEAS_ID_FIP_SIM         (0x20212500)  /* to be moved to RTE, ADDRESS : 0x20212500 <-> 539043072u */
#endif
#endif

  /*! Address of LA Simulation measurement freeze */
#ifdef FCT_SIMU
#ifndef FCT_MEAS_ID_LA_SIM
#define FCT_MEAS_ID_LA_SIM          (0x20193984)  /* to be moved to RTE, ADDRESS : 0x20194000 <-> 538525696u */ //0x20195507
#endif
#endif

  /*! Address of OOI Simulation measurement freeze */
#ifdef FCT_SIMU
#ifndef FCT_MEAS_ID_OOI_SIM
#define FCT_MEAS_ID_OOI_SIM         (0x20211900)  /* to be moved to RTE, ADDRESS : 0x20211900 <-> 539040000u */
#endif
#endif

  /*! Address of OUT Simulation measurement freeze */
#ifdef FCT_SIMU
#ifndef FCT_MEAS_ID_OUT_SIM
#define FCT_MEAS_ID_OUT_SIM         (0x20215300)  /* to be moved to RTE, ADDRESS : 0x20215300 <-> 539054848u */
#endif
#endif

  /*! Address of SIT Simulation measurement freeze */
#ifdef FCT_SIMU
#ifndef FCT_MEAS_ID_SIT_SIM
#define FCT_MEAS_ID_SIT_SIM         (0x20210800)  /* to be moved to RTE, ADDRESS : 0x20210817 <-> 539035671u */
#endif
#endif

/*****************************************************************************
  TYPEDEFS
*****************************************************************************/
/*! @brief Type used for describing an FCT sub-component version */
typedef uint32 SLATESwVersion_t;

/*! @brief          Define SLATE Comp state if it is not available already. This improves consistency, as all components work with the same states.
    @description    SLATE component state. Describes the state in which a (Sub-)component is currently. 
                      @range[0,6], @values: enum { COMP_STATE_NOT_INITIALIZED=0,
                                                   COMP_STATE_RUNNING=1,
                                                   COMP_STATE_TEMPORARY_ERROR=2,
                                                   COMP_STATE_PERMANENT_ERROR=3,
                                                   COMP_STATE_SUCCESS=4,
                                                   COMP_STATE_REDUCEDAVAILABILITY=5,
                                                   COMP_STATE_NOT_RUNNING=6} */
typedef uint8 SLATECompState_t;

/*! @brief    Structure of the require port handler. It is filled by the macros 
              @ref SLATE_SET_REQPORT_HANDLER and @ref SLATE_SET_REQPORT_HANDLER_NO_SIGHEADER
              @attention If this structure is updated, also the macros @ref SLATE_SET_REQPORT_HANDLER 
                          and @ref SLATE_SET_REQPORT_HANDLER_NO_SIGHEADER have to be updated*/
typedef struct SLATEReqPortHandler{
  void            const * pReqPort;                 /*!< Pointer to the considered require port.*/
  SignalHeader_t  const * pReqPortSignalHeader;     /*!< Pointer to the signal header of the considered require port.*/
  void           const ** pGlobal;                  /*!< Pointer to the global pointer. Will be bent to the require port pointer.*/
  uint32                  uSize;                    /*!< Size of the structure of the require port. Needed here for freezing.*/
  SignalHeader_t        * pReqSignalHeaderSyncRef;  /*!< Pointer to the corresponding signal header in @ref t_SLATESyncRef.*/
  sMeasCycleMonitor       MeasCycleMonitor;         /*!< MeasCycleInformation of the corresponding port.*/
}SLATEReqPortHandler_t;

/*! @brief    Structure of the provide port handler. It is filled by the macro 
              @ref SLATE_SET_PROPORT_HANDLER
              @attention If this structure is updated, also the macro @ref SLATE_SET_PROPORT_HANDLER has to be updated*/
typedef struct SLATEProPortHandler{
  void                  * pProPort;                 /*!< Pointer to the considered provide port.*/
  SignalHeader_t        * pProPortSignalHeader;     /*!< Pointer to the signal header of the considered provide port.*/
  void                 ** pGlobal;                  /*!< Pointer to the global pointer. Will be bent to the provide port pointer.*/
  uint32                  uSize;                    /*!< Size of the structure of the provide port. Needed here for freezing.*/
  SignalHeader_t  const * pReqPortSignalHeader;     /*!< Signal header of the require port which shall be source for the signal header of the provide port.*/
  uint32                  uMeasFreezeAddress;       /*!< Address to which the information provided by the port shall be frozen.*/
  uint32                * pProVersionNumber;        /*!< Pointer to the version number of the provide port.*/
  SLATECompState_t      * pProNewSignalState;       /*!< Subcomponent state on base of which the provide port signal state shall be set.*/
  uint32                  uProNewVersionNumber;     /*!< Version number that shall be written to the provide port.*/
}SLATEProPortHandler_t;

/*! @brief    Contains two lists of handlers: One for all provide ports and one for all require ports.
              @attention If this structure is updated, also the macros @ref SLATE_SET_REQPORT_HANDLER,
                         @ref SLATE_SET_PROPORT_HANDLER, and @ref SLATE_SET_REQPORT_HANDLER_NO_SIGHEADER have to be updated*/
/* PRQA S 4548 3 */ 
typedef struct SLATEPortHandlerList{/* date: 2019-07-01, reviewer: Karthik Chittepu, reason:safe as values of operand involved in logical operation is either zero or one */
  SLATEProPortHandler_t    ProPortHandler[SLATE_NOF_PRO_PORTS];   /*!< List of all provide port handlers*/
  SLATEReqPortHandler_t    ReqPortHandler[SLATE_NOF_REQ_PORTS];   /*!< List of all require port handlers*/
  uint8                    uNofProPorts;                         /*!< Number of Ports stored in the provide port handler list*/
  uint8                    uNofReqPorts;                         /*!< Number of Ports stored in the require port handler list*/
}SLATEPortHandlerList_t;

/*! FCT sub-component version structure */
typedef struct SLATEVersions
{

#if (FCT_CFG_ACC_CAL)
  FCTSwVersion_t  uiCAL;
#endif
#if (FCT_CFG_INPUT_PREPROCESSSING)
  SLATESwVersion_t  uiFIP;
#endif
#if (FCT_CFG_COURSE_PREDICTION)
  SLATESwVersion_t  uiCP;
#endif
#if (FCT_CFG_ACC_SITUATION)
  FCTSwVersion_t  uiSIT;
#endif
#if (FCT_CFG_ACC_LANE_ASSOCIATION)
  FCTSwVersion_t  uiLA;
#endif
#if (FCT_CFG_ACC_OOI)
  FCTSwVersion_t  uiOOI;
#endif
#if (SLATE_CFG_ACC_PERF_MONITORING)
  SLATESwVersion_t  uiAPM;
#endif
#if (FCT_CFG_ACC_OUTPUT)
  FCTSwVersion_t  uiOUT;
#endif

  uint32          uProjectID;

  SLATESwVersion_t  SLATE_VERSION_AS_TEXT;

  SLATESwVersion_t  uSLATESwVersion;
} SLATEVersions_t;

/*! The function frame */
typedef struct SLATEFrame {
  AlgoCycleCounter_t  uiCycleCounter;   /*!< The FCT_SEN cycle counter */
  SLATEVersions_t     Versions;         /*!< FCT versions */
  SLATECompState_t    SLATEState;        /*!< FCT current operation mode */
  FCT_OP_MODE_t       SLATEOpMode;       /*!< FCT requested operation mode */
  boolean             bIsInitialized;   /*!< Boolean showing if the component has been initialized */
} SLATEFrame_t;

/* date: 2015-06-17, reviewer: Lonard jaison manohar(uidj2547), reason: Simulation specific macro */
typedef enum {
  SLATE_RTA_PROCESS,                        /*!< Whole procedure runtime */
  SLATE_RTA_PREPRE_PROCESS,                 /*!< data preparation runtime */
  SLATE_RTA_PRE_PROCESS,                    /*!< data preprocessing runtime */
  SLATE_RTA_POST_PROCESS,                   /*!< Post processing runtime */
  SLATE_RTA_PROCESSFREEZE,                  /*!< Process Measfreeze runtime */
  SLATE_RTA_FRAMEFREEZE,                    /*!< Frame Measfreeze runtime */
  SLATE_RTA_FIP,                           /*!< Runtime for FIP (Function Input Preprocessing) */
  SLATE_RTA_CP,                                /*!< Course Prediction runtime */
  SLATE_RTA_LA,                            /*!< Runtime for LA (Lane Association) */
  SLATE_RTA_OOI,                           /*!< Runtime for OOI (Object Of Interest selection) */
  SLATE_RTA_SIT,                           /*!< Runtime for SIT (Situation) */
  SLATE_RTA_OUT,                           /*!< Runtime for OUT (Output) */ 
  SLATE_RTA_APM,                           /*!< Runtime for HC (Headway Control) */
  SLATE_RTA_NOF_CHECKPOINTS                /*!< This line has to be the last to determine the size of the structure */
} SLATE_t_LocalID; /* RTA_LOCAL_ID_FOR_XML_GENERATION */

#if FCT_CFG_RUNTIME_MEAS
/* Virtual address for FCT ACC runtime measurement freeze in the device (to be moved to rte) */
#ifndef FCT_MEAS_ID_ACC_RUNTIME_DEBUG
#define FCT_MEAS_ID_ACC_RUNTIME_DEBUG 0x20273700u //0x20273600
#endif

typedef struct FCT_ACCRuntimeInfo
{
  uint32 uRuntime[SLATE_RTA_NOF_CHECKPOINTS];
}SLATERuntimeInfo_t;
#endif

typedef struct FCTSen_MergeDeleteObject{
  ObjNumber_t t_ObjectToKeep; /* -1 - Initialized State, [0   EM_N_Objects[ - Object ID that has to be merged/ Object retained */
  boolean b_ObjectToDelete;   /*  0 - Initialized State, 1 - Object to be Deleted */
}FCTSen_MergeDeleteObject_t;

typedef FCTSen_MergeDeleteObject_t FCTSen_MergeDeleteList_t[EM_N_OBJECTS];


#if (FCT_CFG_CAMERA_CUTIN_POTENTIAL || FCT_CFG_CAMERA_CUTOUT_POTENTIAL)
/* camera based state */
typedef enum
{
  LA_POTENTIAL_INIT,
  LA_POTENTIAL_CUTIN,
  LA_POTENTIAL_CUTOUT
}CutInOutState_t;
#endif

/*! Lane change direction */
typedef enum SLATE_LC_Direction{
  SLATE_LC_RIGHT = 2,        /*!< Lane change right */
  SLATE_LC_NONE = 0,          /*!< No lane change, i.e. follow mode */
  SLATE_LC_LEFT = 1           /*!< Lane change left */
} SLATE_LC_Direction_t_e;

#if (FCT_CFG_FIP_LANE_MATRIX_FUSION && SLATE_CFG_CAM_LANE_INTERFACE)
/*! Enum to describe the camera lane marker crossing state */
typedef enum SITLCStateCamLaneMarkerCrossed
{
  UNKNOWN_CROSS_CAMLANE,              /*!< Unknown crossing of the camera lane marker */
  LEFT_ONE_LANE_CONF_CROSS_CAMLANE,   /*!< Crossing of the left camera lane marker based on the information of the left camera lane marker */
  RIGHT_ONE_LANE_CONF_CROSS_CAMLANE,  /*!< Crossing of the right camera lane marker based on the information of the right camera lane marker */
  LEFT_TWO_LANE_CONF_CROSS_CAMLANE,   /*!< Crossing of the left camera lane marker based on the information of the left and right camera lane marker */
  RIGHT_TWO_LANE_CONF_CROSS_CAMLANE   /*!< Crossing of the right camera lane marker based on the information of the left and right camera lane marker */
}SITLCStateCamLaneMarkerCrossed_t;
#endif

#if (FCT_CFG_FIP_LANE_MATRIX_FUSION && SLATE_CFG_CAM_LANE_INTERFACE)
/*! Enum to describe if the ego vehicle moves to the new lane in the first stage of the lane change, 
    i.e. before entering the new lane */
typedef enum SITLaneChaneCamPreMove
{
  LANE_CHANGE_CAM_PRE_MOVE_NO = 0,
  LANE_CHANGE_CAM_PRE_MOVE_LEFT = 1,
  LANE_CHANGE_CAM_PRE_MOVE_RIGHT = -1
} SITLaneChangeCamPreMove_t;
#endif

/* Additional typedefs have been moved from subcomponents which are used at SLATE level*/
/*! lane change states */
typedef enum SIT_LC_LaneChangeState{
  LC_RIGHT = 2,        /*!< Lane change right */
  LC_FOLLOW = 0,        /*!< No lane change, i.e. follow mode */
  LC_LEFT = 1           /*!< Lane change left */
} SIT_LC_t_LaneChangeState;

/*! Path occupation structure, used in sit_check_occupied_lane.c. Only here because simulation
frame needs access to type. In ECU code type is only used in the mentioned C file */
typedef struct SITPathOccupationStruct{
  struct SITPathOccupationStruct *next;
  struct SITPathOccupationStruct *prev;
  float32         LengthTrajEgoFrontToObj;
  float32         DistTrajToObjEdge;
  ObjNumber_t     ObjID;
} SIT_t_PathOccupation;

  typedef enum SIT_LC_LaneChangePhaseEnum{
    LC_NO_LANECHANGE = 0,        /*!< no lane change possible or intended */
    LC_PRELANECHANGE = 1,        /*!< lane change possible or might be intended by driver */
    LC_LANECHANGE = 2,           /*!< Lane change left */
    LC_STEERBACK = 3           /*!< Lane change left */
  } SIT_LC_t_LaneChangePhaseEnum;
  

  /*! Lane change Traffic orientation */
  typedef enum SIT_LC_TrafficOrientation{
    LC_TRAFFIC_ORIENT_RIGHT   = 1,
    LC_TRAFFIC_ORIENT_LEFT    = 2,
    LC_TRAFFIC_ORIENT_UNKNOWN = 0
  } SIT_LC_t_TrafficOrientation;

#if (SIT_LC_CFG_USE_OVERTAKE_IN_LANECHANGE)
typedef enum SIT_LC_OvertakeEnum{
  LC_ALLOW_NO_OVERTAKE = 0,     /*!< Overtake support not allowed */
  LC_ALLOW_OVERTAKE_LEFT = 1,   /*!< Overtake support allowed in left direction */
  LC_ALLOW_OVERTAKE_RIGHT = 2   /*!< Overtake support allowed in right direction */
}SIT_LC_OvertakeEnum;
#endif

/*!< Information for each lane change phase */
typedef struct SIT_LC_LaneChangePhaseInfo{
  SIT_LC_t_LaneChangePhaseEnum t_LCPhase;             /* LC stage indicator pre lanechange , mid lanechange, post lanechange*/
  SIT_LC_t_LaneChangeState t_LCPhaseState;            /*!< Lane change state */
  SIT_LC_t_TrafficOrientation t_LCTrafficOrientation; /*!< Traffic orientation */
#if (SIT_LC_CFG_USE_OVERTAKE_IN_LANECHANGE)
  SIT_LC_OvertakeEnum t_AllowOvertake;                /*!< Enum to indicate overtake support is possible, with direction */ 
#endif
  uint8 u_LCPhaseProb;                                /*!< Lane change probability */
  uint8 u_LCConfidence;                               /* confidence represents how stable or reliable the current phase indicator is despite having low probability as in some cases.*/
#if (SLATE_CFG_EGO_LANE_DEPENDENT_BLOCKED_PATH)
  boolean b_EgoLaneStatus;                            /* Indicates the Ego is in left or right most lane */
#endif /* SLATE_CFG_EGO_LANE_DEPENDENT_BLOCKED_PATH */
}SIT_LC_t_LaneChangePhaseInfo;


/* Traffic Orientation information - fip_traffic_orientation.c */
#if (FCT_CFG_INPUT_PREPROCESSSING)
typedef enum SLATETrafficOrientation{
  SLATE_TRAFFIC_ORIENTATION_RIGHT = 1,
  SLATE_TRAFFIC_ORIENTATION_LEFT = 2,
  SLATE_TRAFFIC_ORIENTATION_UNKNOWN = 0
}SLATE_t_TrafficOrientation; 
#endif

#if ( LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM || \
  LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM || \
  LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM )
  /*! State of trace bracket adaption */
typedef enum LAScaleBracketState
{
  SLATE_LANE_CHANGE_UNKNOWN,                /*!< Unknown-> default value without functional influence */
  SLATE_PRE_LANE_CHANGE_LEFT,   /*!< Lane change to the left based on blinker feature (usually before internal LC prob is high) */
  SLATE_PRE_LANE_CHANGE_RIGHT,  /*!< Lane change to the right based on blinker feature (usually before internal LC prob is high) */
  SLATE_POST_LANE_CHANGE_LEFT,  /*!< Lane change to the left based on internal LC prob */
  SLATE_POST_LANE_CHANGE_RIGHT, /*!< Lane change to the right based on internal LC prob */
  SLATE_NO_LANE_CHANGE          /*!< No lane change -> adaption of trace bracket */
} LA_t_ScaleBracketState;
#endif /*!< LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM or LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM or LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM */
/*! LA_t_LaneState */
typedef enum LALaneStateTag
{
  OBJ_STATE_INLANE = 0,   /*!< Object is in-lane */
  OBJ_STATE_OUTLANE = 1   /*!< Object is not in ego lane */
} LA_t_LaneState;

typedef struct LAObjLaneStateTag
{
  LA_t_LaneState     LAInlaneState;          /*!< Lane assignment (confirmed with all criteria) */
  LA_t_LaneState     LAActLaneState;         /*!< Lane assignment without timer and distance criteria (unconfirmed) */
  fTime_t           fCorridorRelevantTime;
  fDistance_t       fCorridorRelevantDist;
  uint8             In2OutlaneTransition;
  uint8            Inlap_In2OutlaneCounter; /*!< Inlane to outlane transition counter for outlane decision of objects (in case the trajectory is fluctuating), used 
                                                  differently from In2OutlaneTransition to reduce dropouts*/
} LA_t_ObjLaneState;

#if ( LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM || \
  LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM || \
  LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM )
/*! Struct to describe the trace bracket adaption based on the ego position in the lane */
typedef struct LAScaleBracketOutput
{
  float32 fScaleBracketLeft;                /*! Factor to scale the left trace bracket */
  float32 fScaleBracketRight;               /*! Factor to scale the right trace bracket */
  LA_t_ScaleBracketState StateScaleBracket;  /*!< State of trace bracket adaption */
} LA_t_ScaleBracketOutput;
#endif /*!< LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM or LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM or LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM */




typedef struct {
  float32 BracketPositionLeft;            /*!< Lane/Corridor Bracket in left position   [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] @unit:m */
  float32 BracketPositionRight;           /*!< Lane/Corridor Bracket in Right position  [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] @unit:m */
} LA_t_BracketOutput;

typedef struct {
  LA_t_BracketOutput BaseCorridor;                           /*!< Base corridor brackets */
  LA_t_BracketOutput FinalBracketPositions;                  /*!< Final corridor brackets */
  /*! Kriterien legen Spurklammererweiterung oder -beschraenkung basierend auf bisheriger Position fest */
#if (LA_CFG_EXT_RELEVANT_OBJECT)
  LA_t_BracketOutput  AddExtensionRelevantObject;           /*!< VorbeifahrtRelObjekt */
#endif
  LA_t_BracketOutput  AddExtensionObjectApproximation;      /*!< Approx */
  LA_t_BracketOutput  AddRestrictionCurveOuterBorder;       /*!< KurveAussenrand */
#if (LA_CFG_ADD_RESTRICTION_STATOBJ_NEXTLANE)
  LA_t_BracketOutput  AddRestrictionStatObjNextLane;        /*!< Restriction specific to stationary object on next lanes */
#endif
  /*! Kriterien legen neue Spurklammerposition fest */
  LA_t_BracketOutput  RestrictionTargetOutsideBrackets;     /*!< ZielAblage */
  LA_t_BracketOutput  RestrictionAnalogRoadBorder;          /*!< AnalogerStrassenrand */
  LA_t_BracketOutput  RestrictionNeighbourhoodRelObj;       /*!< UmfeldRelevantesObjekt */
#if LA_CFG_ADD_RESTRICTION_OBJ_TRACE
  LA_t_BracketOutput  RestrictionObjectTrace;               /*!< Restriction based on object trace */
#endif
#if (LA_CFG_RESTRICTION_EGO_LANE_CHANGE)
  LA_t_BracketOutput AddRestrictionEgoLaneChange;           /*!< Restriction for Ego Lane Change */
#endif
#if (LA_CFG_RESTRICTION_CITY_NEAR_RANGE)
  LA_t_BracketOutput RestrictionCityNearRange;              /*!< Restriction for cut-out in near range */
#endif
#if (LA_CFG_EXT_NEIGHBORHOOD_REL_OBJ)
  LA_t_BracketOutput  ExtensionNeighbourhoodRelObj;		   /*!< Neighbouring object */
#endif
#if (LA_CFG_NAVI_OBJ_CLOSE_TO_EXIT_RESTRICTION)
  LA_t_BracketOutput  RestrictionNaviObjCloseToExit;        /*!< Restriction of trace bracket if object close to exit based on navi information */
#endif
  LA_t_BracketOutput  ExtensionRoadBorder;                  /*!< Richtungsfahrspuren */
  LA_t_BracketOutput  ExtensionCurveInnerBorder;            /*!< KurveInnenrand */
  LA_t_BracketOutput  ExtensionRoadBorderCI;                /*!< RIchtungsfahrspurenKI */
  LA_t_BracketOutput  ExtensionFollowObjectIntoCurve;       /*!< ObjektWinkelVerfolgung */
  LA_t_BracketOutput  ExtensionGuardRailRoadBorder;         /*!< GuardRailRoadBorder */

#if (LA_CFG_NAVI_COUNTRYROAD_EXTENSION)
  LA_t_BracketOutput  ExtensionNaviCountryroad;             /*!< Country road extension based on navi info */
#endif

#if (LA_CFG_CAM_LANE_OBJ_ASSOC_EXTENSION)
  LA_t_BracketOutput  ExtensionCamLaneObjAssoc;             /*!< Extension based on camera lane object association */
#endif

#if (LA_CFG_BLOCKED_OBSTACLE_EXTENSION)
  LA_t_BracketOutput  ExtensionBlockedObstacleCorridor;     /*!< Extension based on scene analysis: obstacle blocks path */
#endif

#if ( LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM || \
  LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM || \
  LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM )
  LA_t_ScaleBracketOutput  RatioEgoPositionInLaneCam;       /*!< RatioEgoPositionInLaneCam */
#endif

#if (SIT_CFG_OBJECT_SCORING)
  LA_t_BracketOutput  ExtensionObjScoring;                   /*!< Scoring extensions */
#endif

#if (LA_CFG_EXT_HIGHSPEED_APPROACH) || (LA_CFG_O2O_EGO_LANE_ASSOC_BRACKET_EXTENSION)
  LA_t_BracketOutput AddExtensionHighspeedApproach;             /*!< Extension for highspeed approaches */
#endif

#if (LA_CFG_ADD_EXT_TUNNEL_PROB)
  LA_t_BracketOutput AddExtensionHighTunnelProb;             /*!< Extension for tunnels */
#endif

#if (LA_CFG_EXT_LOWSPEEDFUSEDBRD)
  LA_t_BracketOutput AddExtensionLowSpeedFusedBrd;           /*!< Extension for low speed and fused road boarder */
#endif

#if (LA_CFG_EXT_PARALLEL_LANE_CHANGE)
  LA_t_BracketOutput ExtensionParallelLaneChange;           /*!< Extension for parallel lane change */
#endif /* (LA_CFG_EXT_PARALLEL_LANE_CHANGE) */
} LA_t_CriteriaMatrix; /* Check if external in necessary, restructure ???*/

/* PRQA S 0635   LA_Bool */
/* date: 2019-07-01, reviewer: Karthik Chittepu, reason: safe, as compiler supports bit-field of type unsigned short and unsigned char */
/*! bit by bit history type (used for whole lifetime valid informations )*/
typedef struct LA_Bool {
  ubit16_t FctPreselTG                :1; /*!< Object is within preselection timegap distance */ // LA
  ubit16_t InLInlapValue              :1; /*!< Inlane inlap flag */ // LA
  ubit16_t InLCustomValue             :1; /*!< Inlane custom flag (predicted inlane) */ // LA
  ubit16_t InLQualityValue            :1; /*!< Inlane quality value (unused) */ // LA
  ubit16_t InLTimeValue               :1; /*!< Inlane timer satisfied */ // LA
  ubit16_t InLDistValue               :1; /*!< Inlane Distance satisfied */ // LA
#if (FCT_CFG_CAMERA_OBJECT_DETECTION)
  ubit16_t InLCamValue                :1; /*!< Inlane Camera satisfied */ // LA
#endif

  ubit16_t OutLInlapValue             :1; /*!< Outlane inlap flag */ // LA
  ubit16_t OutLCustomValue            :1; /*!< Outlane custom flag (predicted outlane) */ // LA
  ubit16_t                            :0;
  ubit16_t                            :0;
  ubit16_t                            :0;
  ubit16_t                            :0;
  ubit16_t                            :0;
  ubit16_t                            :0;
  ubit16_t                            :0;
#if (!FCT_CFG_CAMERA_OBJECT_DETECTION)
  ubit16_t                            :0;
#endif /* FCT_CFG_CAMERA_OBJECT_DETECTION */
}LA_Bool_t;
/* PRQA L:LA_Bool */

/*! @brief CPTrajOccupancy_t */
typedef struct LATrajOccupancy
{
  float32 fOverlap;/*!<fOverlap */
  float32 fOverlapVar;/*!<fOverlapVar */
  float32 fObjectOccupancy;/*!<fObjectOccupancy */
  float32 fObjectOccupancyVar;/*!<fObjectOccupancyVar */
  float32 fTrajectoryOccupancy;/*!<fTrajectoryOccupancy */
  float32 fTrajectoryOccupancyVar;/*!<fTrajectoryOccupancyVar */
} CPTrajOccupancy_t; // USED in EAB?
/* CPTrajOccupancy_t is temporarily kept with old prefix due to compatibility issues with 
EBA. Several files are using this structure. Once FCT400 code is completely restructured (including
input/output variables), this as well as the EBA file have to be updated */

/*! @brief LADistanceWidth_t */
typedef struct LADistanceWidth
{
  float32 fDistance; /*!< fDistance */
  float32 fDistanceVar;/*!< fDistanceVar */
  float32 fTrajectoryWidth;/*!< fTrajectoryWidth */
  float32 fTrajectoryWidthVar;/*!< fTrajectoryWidthVar */
  float32 fObjectWidth;/*!< fObjectWidth */
  float32 fObjectWidthVar;/*!< fObjectWidthVar */
} LADistanceWidth_t; // USED in EBA 
/* LADistanceWidth_t is temporarily kept with old prefix due to compatibility issues with 
EBA. Several files are using this structure. Once FCT400 code is completely restructured (including
input/output variables), this as well as the EBA file have to be updated */

/*! @brief Holds the recursive values of the Distance Kalman filter */
typedef struct
{
  GDBVector2_t      X;  /*!< kalman states (distance velocity) */
  GDBSymMatrix2_t   P;  /*!< kalman estimation covariance matrix */
} LA_t_TrajDistKalmanData;


/*! @brief LA_t_TrajDistKalmanMeas */
typedef struct
{
#ifdef FCT_SIMU
  GDBVector2_t     Y;/*!< GDBVector2_t */
#else
  GDBVector1_t     Y;/*!< GDBVector1_t */
#endif
  GDBSymMatrix1_t  R;/*!< GDBSymMatrix1_t */
} LA_t_TrajDistKalmanMeas;

/*! @brief LAObjDist2Traj_t */
typedef struct
{
  LA_t_TrajDistKalmanData  TrajDistFilt;/*!< TrajDistFilt */ // LA
  LA_t_TrajDistKalmanMeas  TrajDistMeas;/*!< TrajDistMeas */ //LA

  float32 ObjDistOnTraj;   /*!< Distance from vehicle center of gravity to object on trajectory @unit:m */// LA
#ifdef FCT_SIMU
  float32 TrajDistGradRel; /*!< Distance gradient using dist differentiation */
  float32 TrajDistGradAbs; /*!< Distance gradient using last object position */
#endif
} LAObjDist2Traj_t; 

typedef struct 
{
  float32 dRelSpurErweiterungsFaktor;     /*!< Factor for widening seek lane width to relevant obj track lane width
                                          depending on time and distance @min:0 @max:1 */
  float32 dRelSpurAbstandErweitFaktor;    /*!< Factor for widening seek lane width to relevant object track lane width
                                          depending on distance difference @min:0 @max:1 */

  sint32 iLwFolge;                        /*!< Counter flag for object being held over steering speed */

  float32 dAblage_SpurGrenze_L;           /*!< Maximal allowed deviation to left from ideal trajectory @unit:m */
  float32 dAblage_SpurGrenze_R;           /*!< Maximal allowed deviation to right from ideal trajectory @unit:m */
} LA_OTTrack_Fahrend_t;

#if(LA_CFG_OBJ_LANE_ASSOC_CAM_TRAJ)
typedef enum LA_ObjCamTrajLanAssocEnum{
  LA_OBJ_CAM_LANE_UNDEFINED = 0,        /*!< Object Camera Trajectory based lane association is not available */
  LA_OBJ_CAM_LANE_LEFT = 1,              /*!< Object Camera Trajectory based lane association is Left lane */
  LA_OBJ_CAM_LANE_EGO = 2,              /*!< Object Camera Trajectory based lane association is Ego lane */
  LA_OBJ_CAM_LANE_RIGHT = 3            /*!< Object Camera Trajectory based lane association is Right lane */
} LA_t_ObjCamTrajLanAssocEnum;
#endif /* (LA_CFG_OBJ_LANE_ASSOC_CAM_TRAJ) */

typedef struct
{
  float32 dRelevantZeit;
  float32 dNichtRelevantZeit;
  LA_OTTrack_Fahrend_t TrckFahr;
#if (LA_CFG_EXT_RELEVANT_OBJECT)
  float32 fTargetFusionHoldTime;
#endif
#ifdef FCT_SIMU
  LA_t_CriteriaMatrix   ObjCriteriaMatrix;
#endif
} LA_t_ObjCorridor;

/*! @brief LA_t_TrajInlap */
typedef struct LATrajInlap
{
  float32 fInlap;/*!<fInlap */
  float32 fInlapVar;/*!<fInlapVar */
} LA_t_TrajInlap;

typedef struct LA_Object{
  LAObjDist2Traj_t TrajDist;
  LADistanceWidth_t ObjTrajDistWidth;
  LA_t_TrajInlap ObjTrajRelation;
  LA_t_ObjLaneState ObjLaneAccStatus;     /*!< The object lane assignment state */
  LA_t_ObjCorridor ObjCor;
  LA_Bool_t t_Bool;  
#ifdef FCT_SIMU
  CAL_t_TrajRefPoint ObjTrajRefPoint;
  CAL_t_TrajRefPoint ObjTrajRefPointLastCycle;

  float32 fObjInlapPickupThreshSIM;
  float32 fObjInlapDropThreshSIM;
#endif /* FCT_SIMU */
  float32 f_ObjInlapDropThresh;
  float32 f_ObjInlapPickupThresh;
  float32 ObjDependantMaxRange;
  fTime_t fInLaneTimeThres;
#if (FCT_CFG_CAMERA_CUTIN_POTENTIAL || FCT_CFG_CAMERA_CUTOUT_POTENTIAL)
  CutInOutState_t   t_CutInCutOutstate;                        /* object state */ 
  float32           f_CAM_Overlap_prev_cycle;           /* previous cycle overlap distance [m]*/
  float32           f_CAM_Overlap_delta;                        /* filtered overlap distance change [m]*/
#endif
  fTime_t t_PredTimeThreshold;    /*! Prediction time threshold */
  fTime_t t_TotalTimeToInlap;     /*! Total time to Inlap for Inlane Prediction */
  fTime_t t_TotalTimeToInlapDrop; /*! Total time to InlapDrop for Outlane Prediction */
  fTime_t t_PredInlaneTimer;      /*! Predicted Inlane timer. To start the timer as soon it reaches the distance to inlap */
  float32 f_DistanceToInlap;      /*! Distance to Inlap is from the edge of the object to the Pick up threshold*/
  float32 f_TotalDistanceToInlap; /*! Total Distance to Inlap is from Pick up threshold to InlaneTimerThreshold*/
  float32 f_DistanceToInlapDrop;  /*! Distance to InlapDrop is from the edge of the object to the Drop threshold*/
  float32 f_TotalDistanceToInlapDrop;/*! Total Distance to InlapDrop is from Drop threshold to Outlane counter*/
  eAssociatedLane_t ObjAssociatedLane; /*Replacement for macro ObjAssociatedLane*/
  eAssociatedLane_t ObjFuncLane; /*Replacement for macro ObjFuncLane*/
#if (FCT_CFG_CAMERA_CUTIN_POTENTIAL)
  uint8 u_CameraCutInPotential;  /* camera based cut In potential [0U .. 100U]*/
#endif
#if (FCT_CFG_CAMERA_CUTOUT_POTENTIAL)
  uint8 u_CameraCutOutPotential; /* camera based cut Out potential [0U .. 100U]*/
#endif
  uint8 u_PredOutlaneCounter;     /*! Predicted Outlane counter. To start the counter as soon it reaches the distance to InlapDrop */
#if (LA_CFG_CAM_INLANE_STABLE_SELECTION)
  uint8 u_CamInlaneCounter ;      /* Camera Inlane counter */
#endif /* END IF LA_CFG_CAM_INLANE_STABLE_SELECTION */
  boolean b_SetEgoLaneValidity;   /* Ego Lane Validity check if there is overlap of object with OOI-0 Object */
#if (LA_CFG_ADAPT_INLANE_TIME_CURVE_STAT)
  boolean b_SetInLaneTimeCurve;   /* Boolean to indicate increase in In-Lane timer for Stationry Objects on Curve*/
#endif /* (LA_CFG_ADAPT_INLANE_TIME_CURVE_STAT) */
#if (LA_CFG_OBJ_LANE_ASSOC_CAM_TRAJ)
  LA_t_ObjCamTrajLanAssocEnum t_ObjCamTrajLaneAssoc; /*!< Camera Trajectory bsed object's lane association */
  float32 f_ObjCamTrajLaneAssocProb; /*!< Camera Trajectory based object's lane association Probability */
#endif /*(LA_CFG_OBJ_LANE_ASSOC_CAM_TRAJ) */
}LAObjOutput_t; // check what need to be local (only within la -> la.h) or global (usage outside la -> la_ext.h)

/* PRQA S 0635   CP_t_TrajectoryState */
/* date: 2019-07-01, reviewer: Karthik Chittepu, reason: safe, as compiler supports bit-field of type unsigned short and unsigned char */
/*! @brief CP_t_TrajectoryState */
typedef struct // PRQA S 635
{ /* date: 2015-09-23, reviewer: Harsha Umesh Babu, reason: Project specific type definition */
  /* !!!ATTENTION!!! Do not change order of bitfield entries because of initialization downward compatibility */
  ubit16_t EgoCourseOnly             : 1;  /*!< Bit indicating that only ego course used for trajectory (fusion off) */
  ubit16_t FusionRoadstimation       : 1;  /*!< Bit indicating that RE is used for trajectory fusion */
  ubit16_t FusionTraces              : 1;  /*!< Bit indicating that Traces are used for trajectory fusion */
  ubit16_t FusionTraceHystEgoSpeed   : 1;  /*!< Bit indicating that ego speed is sufficient for Traces fusion */
  ubit16_t FusionHystLRoadRangeConf  : 1;  /*!< Bit indicating that features from left side of road estimation fulfill fusion criteria */
  ubit16_t FusionHystRRoadRangeConf  : 1;  /*!< Bit indicating that features from right side of road estimation fulfill fusion criteria */
  ubit16_t FusionHystEgoSpeed        : 1;  /*!< Bit indicating that ego speed fusion criteria is fulfilled */
  ubit16_t FusionHystEgoRadius       : 1;  /*!< Bit indicating that ego radius fusion criteria is fulfilled */
  ubit16_t FusTraceCrit              : 1;  /*!< Bit set when if CPMOTraceFusionCriterion returns TRUE */
  ubit16_t FusionPlaus               : 1;  /*!< Bit to non-zero if CPFusionPlausibilityCheck returns TRUE */
  ubit16_t CamLaneQualityHigh        : 1;  /*!< Bit indicating if camera lane foresight/quality criteria met */
  ubit16_t CamLaneFusion             : 1;  /*!< Bit when camera lane fusion is active */
  ubit16_t NaviPathFusion            : 1;  /*!< Bit when navi path fusion is active */
}CP_t_TrajectoryState;
/* PRQA L:CP_t_TrajectoryState */

/*! @brief CPCourseData_t */
typedef struct CPCourseData
{
  fCurve_t    fCurve; /*!< fCurve */
  float32     fCurveVar;/*!< fCurveVar */
  fGradient_t fCurveGradient;/*!< fCurveGradient */
  float32     HeadingAngle;/*!< HeadingAngle */
  float32     SideSlipAngle;/*!< SideSlipAngle */
  float32     SideSlipAngleVariance;/*!< SideSlipAngleVariance */
}CP_t_CourseData;

/*! @brief CP_t_TrajKafiData */
typedef struct CP_TrajKafiData
{
  float32 AMatrix[CP_NB_TRAJ_STATE*CP_NB_TRAJ_STATE];                 /*!< full matrix, transition matrix                */
  float32 QMatrix[CP_NB_TRAJ_STATE];                               /*!< diagonal matrix, process noise covariance     */
  float32 XVector[CP_NB_TRAJ_STATE];                               /*!< Vector, estimated state vector                */
   float32 UDMatrix[(CP_NB_TRAJ_STATE * (CP_NB_TRAJ_STATE + 1u)) / 2u];  /*!< UDUT factorized matrix, covariance            */
  float32 XsVector[CP_NB_TRAJ_STATE];                              /*!< Vector, predicted state vector                */
  float32 PDiagMatrix[CP_NB_TRAJ_STATE];                           /*!< PDiagMatrix              */
}CP_t_TrajKafiData;

/* PRQA S 0635   CP_t_TrajectoryConfig */
/* date: 2019-07-01, reviewer: Karthik Chittepu, reason: safe, as compiler supports bit-field of type unsigned short and unsigned char */
/*! @brief CP_t_TrajectoryConfig */
typedef struct  // PRQA S 635
{ /* date: 2015-09-23, reviewer: Harsha Umesh Babu, reason: Project specific type definition */
  ubit8_t UseRoadEstim  : 1;  /*!< Bit indicating if road estimation shall be used for fusion */
  ubit8_t UseObjTraces  : 1;  /*!< Bit indicating if object traces shall be used for fusion */
#if (CP_CFG_LANE_CHG_CAM_FUSION)
  ubit8_t UseCamLane    : 1;  /*!< Bit indicating if camera lane shall be used for trajectory fusion */
#endif
#if (SLATE_CFG_SIMPLE_NAVI_INTERFACE) && (FCT_CFG_INPUT_PREPROCESSSING)
  ubit8_t UseNaviPath   : 1; /*!< Bit indicating if Navi path shall be used for trajectory fusion */
#endif
}CP_t_TrajectoryConfig;
/* PRQA L:CP_t_TrajectoryConfig */

/*! @brief CP_t_GDBTrajectoryData */
typedef struct
{
  float32 fTrajC0;/*!< fTrajC0 */
  float32 fTrajC1;/*!< fTrajC1 */
  float32 fTrajAngle;/*!< fTrajAngle */
}CP_t_GDBTrajectoryData;

#if (SLATE_CFG_PARALLEL_LANE_CHANGE)
typedef struct CPTraceLaneChangeInfo{
#ifdef FCT_SIMU
  ObjNumber_t              iObjNr;            /*!< Obj Id of the Trace */
#endif
  SLATE_LC_Direction_t_e   t_TraceLaneChange; /*!< Trace Lane Change Direction i.e. either LEFT or RIGHT*/
  float32 f_AveragePathDifference;            /*!< Avergae Path Difference between Trace and Ego/ACC Curve */
  boolean b_SetTraceLeftLaneCutOut;           /*!< Flag to set based on the Trace Ego Difference Parameters for Left Cut Out */
  boolean b_SetTraceRightLaneCutOut;          /*!< Flag to set based on the Trace Ego Difference Parameters for Right Cut Out*/
  boolean b_SetLeftTurnIndicatorCutOut;       /*!< Flag to set based on the Turn Indicator and Average Curve Difference Parameters for Left Cut Out*/
  boolean b_SetRightTurnIndicatorCutOut;      /*!< Flag to set based on the Turn Indicator and Average Curve Difference Parameters for Right Cut Out*/
}CPTraceLaneChangeInfo_t;
#endif /* (SLATE_CFG_PARALLEL_LANE_CHANGE) */

/*! @brief CP_t_TrajectoryData */
typedef struct CP_TrajectoryData
{
  CP_t_TrajectoryConfig  Config;/*!< Config */
  CP_t_TrajectoryState   State;/*!< State */
  CP_t_GDBTrajectoryData   Current;    /*!< Trajectory data from the current cycle */
  CP_t_GDBTrajectoryData   LastCycle;  /*!< Trajectory data from the last cycle */
  float32               fDistXUnplausibleSCurve;/*!< fDistXUnplausibleSCurve */
  float32               fRoadEstFusRange;/*!< fRoadEstFusRange */
  float32               fMovObjFusRange;/*!< fMovObjFusRange */
  float32               fMSETrace;/*!< fMSETrace */
#if (CP_CFG_LANE_CHG_CAM_FUSION)
  float32               fCamLaneFusionTimer;  /*!< Down counting camera lane fusion timer */
  float32               fEgo2CamDistX;        /*!< Ego curve to camera lane blending X distance */
  float32               fBaseY;               /*!< Cam lane fusion Y displacement base */
  float32               fFilteredDIC;         /*!< Filtered driver intended curvature */
#endif
  GDBBaseKafi_t         KafiEst;    /*!< The Kalman filter base data (matrix representation information) */
  CP_t_TrajKafiData     KafiData;   /*!< The Kalman filter data (the matrices/vectors themselves) */
#if (SLATE_CFG_PARALLEL_LANE_CHANGE)
  CPTraceLaneChangeInfo_t    t_TraceLaneChangeInfo[FIP_STATIC_TRACE_NO_OF_TRACES];
#endif /* (SLATE_CFG_PARALLEL_LANE_CHANGE) */
  boolean               bTraceFusionActiveLastCycle;/*!< bTraceFusionActiveLastCycle */
}CP_t_TrajectoryData;

typedef struct OOIRelObjectTag {
#ifdef FCT_SIMU
  LA_t_CriteriaMatrix  ObjCriteriaMatrix;
  LA_t_ObjLaneState    ObjLaneAccStatus;
  LA_t_TrajInlap       ObjTrajRelation;
  fDistance_t         fDist_4mss;       /*!< Distance hard brake */
  fDistance_t         fDist_2mss;       /*!< Distance comfort brake */
#endif
  fDistance_t     DistX;                    /*!< Distance of object in X direction (longitudinal) */
  fVelocity_t     RelSpeedX;                /*!< Relative speed of object in X direction */
  fAccel_t        RelAcclX;                 /*!< Relative acceleration of object in X direction */
  fVelocity_t     ObjSpeed;                 /*!< Absolute object speed */
  fAccel_t        ObjAccl;                  /*!< Absolute object acceleration */
  fAngle_t        ObjAngle;                 /*!< Object angle */
  fDistance_t     ObjDistY;                 /*!< Distance of object in Y direction (lateral) */
  fVelocity_t     RelSpeedY;                /*!< Relative speed of object in Y direction */
  fDistance_t     LatDisplRoadBordL;        /*!< Lateral displacement of lane border (bracket) left */
  fDistance_t     LatDisplRoadBordR;        /*!< Lateral displacement of lane border (bracket) right */
  fDistance_t     RelPickupDist;            /*!< Pickup (first selection X distance), formerly dAbst_RelevantNeu on each object, now only here */
  /* Additional information for deducing object loss reason */
  ObjNumber_t     ObjectNr;                 /*!< Object index (or OBJ_INDEX_NO_OBJECT if none) */
  eRelObjLossReason_t LossReason;           /*!< Relevant object loss reason */
  boolean         ObjValid;                 /*!< Boolean set to TRUE if object is valid */
  boolean         StatObj;                  /*!< Boolean set to TRUE if object is stationary */
  boolean         MovingToStat;             /*!< Boolean set to TRUE if moving object turned stationary */
  uint8           RelObjCounter;        /*Number of cycles object is relevant (OOI 0)*/
  ObjNumber_t     iLastObjektNr;
} OOI_RelObject_t;

/* SIT Typedefs */

#if (SIT_O2O_ANALYSIS)
typedef struct SIT_O2O_Analysis{
  float32 f_LongDist; /*  */
  float32 f_LatDist; /* Orthogonal distance of object to the road polynomial */
  float32 f_DistBorderLeft; /* Distance of object to the left road border */
  float32 f_DistBorderRight; /* Distance of object to the right road border */
  ObjNumber_t t_NearObjIDLeft[SIT_O2O_NEAR_OBJECTS]; /* Neighboring objects to the left of the object under consideration */
  ObjNumber_t t_NearObjIDRight[SIT_O2O_NEAR_OBJECTS]; /* Neighboring objects to the right of the object under consideration */
#if (SIT_CFG_OBJECT_SCORING)
  eAssociatedLane_t t_ObjScoreLane; /* Absolute lane of object based on object scoring */
#endif
  ObjNumber_t t_ObjID; /* Object ID */
}SIT_O2O_Analysis_t;
#endif

/* PRQA S 0635   SIT_OutputBool */
/* date: 2019-07-01, reviewer: Karthik Chittepu, reason: safe, as compiler supports bit-field of type unsigned short and unsigned char */
/*! bit by bit history type (used for whole lifetime valid informations )*/
typedef struct SIT_OutputBool {
  ubit8_t SelectedByPathDecision     :1; /*!< Object was selected by blocked path */ 
  ubit8_t OccludedByTrace            :1; /*!< Object is marked as occluded by trace analysis */
  ubit8_t                            :0;
  ubit8_t                            :0;
  ubit8_t                            :0;
  ubit8_t                            :0;
  ubit8_t                            :0;
  ubit8_t                            :0;
}SIT_OutputBool_t;
/* PRQA L:SIT_OutputBool */

typedef struct SITObjOutput{
#if (SIT_O2O_ANALYSIS)
  SIT_O2O_Analysis_t t_SIT_O2O_Analysis;
#endif /* END IF SIT_O2O_ANALYSIS */
  float32 f_CrossingDistTrace;
  SIT_OutputBool_t t_Bool; /*!< Booleans indicating decisions in SIT */
  uint8 u_BlockedPathSelectionTimer; /*!< Path SelectionTimer for Blocked path objects */
  uint8 u_ObjCutInPotential; /*!< Cut-In potential for object */
  uint8 u_ObjCutOutPotential; /*!< Cut-Out potential for object */
}SITObjOutput_t;

/* Object classification is sensor dependent, USE mapped SLATE classification based on sensor */
#if (FCT_CFG_SENSOR_TYPE_RADAR)   // Radar sensor
typedef EM_t_ARS_Classification     SLATE_t_Obj_CLassification;
typedef EM_t_ARS_DynamicProperty    SLATE_t_Obj_DynamicProperty;
typedef EM_t_ARS_DynamicSubProperty SLATE_t_Obj_DynamicSubProperty;
#endif  /* (FCT_CFG_SENSOR_TYPE_RADAR) */

#if (FCT_CFG_SENSOR_TYPE_CAMERA)  // Camera sensor
typedef EM_t_GenObjClassification   SLATE_t_Obj_CLassification;
typedef EM_t_GenObjDynamicProperty  SLATE_t_Obj_DynamicProperty;
// SLATE_t_Obj_DynamicSubProperty in case of Camera is included in SLATE_t_Obj_DynamicProperty
#endif

/* ACCObjectQuality_t is defined generally in algo_type.h but this is not available in some configurations */
#if (!SLATE_CFG_ALGO_COMMON_AVAILABLE)
typedef ucConfidence_t ACCObjectQuality_t;
#endif


/* CAL Equivalent Typedefs */
/*! @brief Structure storing position samples of trajectories */
typedef struct SLATESamplesTag
{
  float32   fx[SLATE_MAX_NB_TRAJ_SAMPLES];    /*!< x-Position */
  float32   fy[SLATE_MAX_NB_TRAJ_SAMPLES];    /*!< y-position */
  float32   fVar[SLATE_MAX_NB_TRAJ_SAMPLES];  /*!< variance information */
  uint8     nb_samples;                 /*!< Number of samples */
} SLATE_t_PosSamples;


#if (FCT_CFG_CAMERA_OBJECT_DETECTION)
/* Reference EM_t_CamTurnLightsState - status of turn light detection @min: 0 @max:15 */
typedef enum FIPCamTurnLightsState{
  FIP_CAM_TURN_LIGHT_OFF=0,
  FIP_CAM_TURN_LIGHT_LEFT=1,
  FIP_CAM_TURN_LIGHT_RIGHT=2,
  FIP_CAM_TURN_LIGHT_HAZARD=3,
  FIP_CAM_TURN_LIGHT_UNKNOWN=15
}FIP_t_CamTurnLightsState;

/* Reference EM_t_CamBrakeLight - status of brake light detection @min: 0 @max:15 */
typedef enum FIPCamBrakeLight{
  FIP_CAM_BRAKE_LIGHT_OFF=0,
  FIP_CAM_BRAKE_LIGHT_ON=1,
  FIP_CAM_BRAKE_LIGHT_UNKNOWN=15
}FIP_t_CamBrakeLight;

/* Reference eAssociatedLane_t - Lane enumeration @min: 0 @max:5 */
typedef enum FIP_CamAssociatedLane{
  FIP_CAM_ASSOC_LANE_UNKNOWN=0,
  FIP_CAM_ASSOC_LANE_FAR_LEFT=1,
  FIP_CAM_ASSOC_LANE_LEFT=2,
  FIP_CAM_ASSOC_LANE_EGO=3,
  FIP_CAM_ASSOC_LANE_RIGHT=4,
  FIP_CAM_ASSOC_LANE_FAR_RIGHT=5
}FIP_t_CamAssociatedLane;

/* Reference EM_t_CamObjManeuver - camera detected object maneuver @min: 0 @max:2 */
typedef enum FIP_CamObjManeuver{
  FIP_CAM_OM_NONE=0,
  FIP_CAM_OM_CUT_IN=1,
  FIP_CAM_OM_CUT_OUT=2
}FIP_t_CamObjManeuver;
#endif /* END IF (FCT_CFG_CAMERA_OBJECT_DETECTION) */

#if ((FCT_CFG_OBJECT_TRACE_PREPROCESSSING) || (FCT_CFG_USE_FCT_DYNAMIC_TRACES))
/* All these structures are FCT local but equivalent of definitions found in RTE/EM. 
   Irrespective of whether we are using traces computed in EM or FCT, we would need these structures */
/* FCT Moving object traces*/
/* Legacy moving object traces structure*/
typedef struct 
{
  float32 YPredictedIntersec;
  float32 YPredictedIntersecVar;
  boolean TraceReachEgoVeh;
  boolean ValidForLaneMatrix;
} FIP_LegacyMOT_t;
#endif

/* PRQA S 0635   bit_StatObjWasOncoming */
/* date: 2019-07-01, reviewer: Karthik Chittepu, reason: safe, as compiler supports bit-field of type unsigned short and unsigned char */
/* Output for FIP object attributes */
/*! bit by bit history type for FIP object attributes (used for whole lifetime valid informations )*/
typedef struct FIP_OA_Bool {
ubit8_t bit_StatObjWasOncoming     :1; /*!< Boolean if stationary object was treated as oncoming */ 
ubit8_t bit_ObjWasMoving           :1;
ubit8_t bit_ObjWasOncoming         :1;
ubit8_t bit_ObjWasStationary       :1;
ubit8_t                            :0;
ubit8_t                            :0;
ubit8_t                            :0;
ubit8_t                            :0;
}FIP_OA_Bool_t;
/* PRQA L:bit_StatObjWasOncoming */

#if (FCT_CFG_OBJECT_TRACE_PREPROCESSSING)

typedef float32 f_FIPStaticTracePoint_array_t[FIP_STATIC_TRACE_NO_OF_POINTS];       /* Array for trace points - X, Y, Standard deviation etc. */

typedef struct 
{
  float32 fYIntersection;                /*! Y intersection of the trace w.r.t X-axis */
  float32 fYIntersectionGradFilt;        /*! Y intersection of the trace */
  f_FIPStaticTracePoint_array_t fTracePointX;   /*! X coordinate point in Trace */
  f_FIPStaticTracePoint_array_t fTracePointY;   /*! Y coordinate point in Trace */
  f_FIPStaticTracePoint_array_t fTracePointYStdDev;/*! Standard deviation of trace points (note: Y not completely correct, since through ego vehicle rotation,
                                                 this becomes a position uncertainty. Only when driving straight is it the Y uncertainty) */
  FIP_LegacyMOT_t Legacy;/*! Legacy structure of the trace */
  sint8 iNumberOfPoints;     /*! number of trace points in a traces.. max is 25 */
  uint8 uiReferenceToFCTObject;/*! Getting FCT Object ID */
  uint8 uiReferenceToEMObject; /*! Getting EM Object ID */ 
} FIP_MovObjStaticTrace_t;

typedef FIP_MovObjStaticTrace_t FIP_MovObjStaticTraceList_t[FIP_STATIC_TRACE_NO_OF_TRACES];/*!Object static trace array */
#endif /* END IF (FCT_CFG_OBJECT_TRACE_PREPROCESSSING) */

#if (FCT_CFG_USE_FCT_DYNAMIC_TRACES)
typedef float32 f_FIPDynTracePoint_array_t[FIP_DYN_TRACE_NO_OF_POINTS];       /* Array for trace points - X, Y, Standard deviation etc. */

typedef struct 
{
  float32 fYIntersection;                /*! Y intersection of the trace w.r.t X-axis */
  float32 fYIntersectionGradFilt;        /*! Y intersection of the trace */
  float32 fSamplingLength;               /*! Trace resolution/sampling interval for each trace */
  f_FIPDynTracePoint_array_t fTracePointX;   /*! X coordinate point in Trace */
  f_FIPDynTracePoint_array_t fTracePointY;   /*! Y coordinate point in Trace */
  f_FIPDynTracePoint_array_t fTracePointYStdDev;/*! standard deviation of the trace points in trace */
  FIP_LegacyMOT_t Legacy;/*! Legacy structure of the dynamic trace */
  sint8 iNumberOfPoints;     /*! number of trace points in a dynamic traces.. max is 20 */
  uint8 uiReferenceToFCTObject;/*! Getting FCT Object ID */
  uint8 uiReferenceToEMObject; /*! Getting EM Object ID */
  uint8 uiHistorySampleHead;  /*History sample starting index in trace*/
} FIP_ObjectDynTrace_t;

typedef FIP_ObjectDynTrace_t FIP_ObjectDynTraceList_t[FIP_DYN_TRACE_NO_OF_TRACES];/*!Object dynamic trace array */
#endif /*FCT_CFG_USE_FCT_DYNAMIC_TRACES*/

#if (FIP_CFG_USE_EGO_TRACE)
/* FCT Ego trace*/

typedef float32 f_FIPEgoTracePoint_array_t[FIP_EGO_TRACE_NO_OF_POINTS];       /* Array for trace points - X, Y etc. */

typedef struct 
{
  f_FIPEgoTracePoint_array_t fTracePointX;   /*! X coordinate point in Trace */
  f_FIPEgoTracePoint_array_t fTracePointY;   /*! Y coordinate point in Trace */
  float32 fLength;                  /*!< length of trace (m) */
  float32 fSamplingDistance;        /*!< sampling interval (distance) of ego trace (m) */
  sint8 iNumberOfPoints;     /*! number of trace points in a trace.. max is 5 */
} FIP_t_EgoTrace;

#endif /* END IF (FIP_CFG_USE_EGO_TRACE) */

/*Road Works Information - fip_road_type.c*/
typedef enum FIPRoadWorks{
    FIP_NOINFO_ROADWORKS,
    FIP_ROADWORKS_DETECTED
} FIP_t_RoadWorks;

/*Types of Road - fip_road_type.c*/
typedef enum FIPRoadType{
  FIP_ROAD_TYPE_UNKNOWN,
  FIP_ROAD_TYPE_CITY,
  FIP_ROAD_TYPE_COUNTRY,
  FIP_ROAD_TYPE_HIGHWAY
} FIP_t_FusedRoadType;

/* Lane Width Class - fip_lane_matrix_plg.c */
typedef enum FIPLaneWidthClass{
  FIP_LANE_WIDTH_CLASS_UNKNOWN = -1,
  FIP_LANE_WIDTH_CLASS_NORMAL = 0, 
  FIP_LANE_WIDTH_CLASS_NARROW = 1,
  FIP_LANE_WIDTH_CLASS_MORE_NARROW = 2
} FIP_t_LaneWidthClass;

/* Lane Width Source TODO - fip_lane_matrix_plg.c */
typedef enum FIPLaneWidthSource{
  FIP_SOURCE_0,
  FIP_SOURCE_1
} FIP_t_LaneWidthSource;

/*! Debug information for simulation */
#ifdef FCT_SIMU
typedef struct FIPLaneMatrixDebug{
#if (FCT_CFG_FIP_LANE_MATRIX_FUSION)
  float32 f_FusedNumLaneLeftFilt;                         /*!< Filtered fused (EM, NAVI, camera) number of lanes left */
  float32 f_FusedNumLaneRightFilt;                        /*!< Filtered fused (EM, NAVI, camera) number of lanes right */
  float32 f_SumDistDrivenLeft;                            /*!< Distance the ego vehicle is driving to the left */
  float32 f_SumDistDrivenRight;                           /*!< Distance the ego vehicle is driving to the right */
  float32 f_LeftTimerUnknownCurrentNumLane;               /*!< Timer for the unknown current number of lanes left */
  float32 f_RightTimerUnknownCurrentNumLane;              /*!< Timer for the unknown current number of lanes right */
  float32 f_LeftTimerUnknownFiltNumLane;                  /*!< Timer for the unknown filtered number of lanes left */
  float32 f_RightTimerUnknownFiltNumLane;                 /*!< Timer for the unknown filtered number of lanes right */
#if (FCT_CFG_FIP_LANE_MATRIX_FUSION && SLATE_CFG_CAM_LANE_INTERFACE)
  SITLCStateCamLaneMarkerCrossed_t CamLaneMarkerCrossed;  /*!< Info if camera lane marker is crossed */
#endif
  sint8 s_NaviNumLane;                                    /*!< Number of lanes (left + right + ego) based on the NAVI */
  sint8 s_CamNumLaneLeft;                                 /*!< Number of lanes left based on the camera */
  sint8 s_CamNumLaneRight;                                /*!< Number of lanes right based on the camera */
  sint8 s_FusedNumLaneLeftBeforeFilt;                     /*!< Fused (EM, NAVI, camera) number of lanes left before filtering */
  sint8 s_FusedNumLaneRightBeforeFilt;                    /*!< Fused (EM, NAVI, camera) number of lanes right before filtering */
  sint8 s_FusedNumLaneLeftBeforeLC;                       /*!< Fused number of lanes left before considering a lane change */
  sint8 s_FusedNumLaneRightBeforeLC;                      /*!< Fused number of lanes right before considering a lane change */
  boolean b_DrvLeftCamLane;                               /*!< Info if ego vehicle is driving to the left based on the distance to the camera lane marker */
  boolean b_DrvRightCamLane;                              /*!< Info if ego vehicle is driving to the right based on the distance to the camera lane marker */
  boolean b_IsInfoIdenticalLeft;                          /*!< Boolean if the input sources for the left number of lanes give the same info */
  boolean b_IsInfoIdenticalRight;                         /*!< Boolean if the input sources for the right number of lanes give the same info */
  boolean b_InputDataFused;                               /*!< Info if input sources are fused */
  boolean b_MultipleInputSourceAvailable;                 /*!< Info if different input sources are available */
#endif
  sint8 s_FIPNumLaneLeft;     /*!< Number of lanes left after FCT input preprocessing (result) */
  sint8 s_FIPNumLaneRight;    /*!< Number of lanes right after FCT input preprocessing (result) */
  sint8 s_EMNumLaneLeft;      /*!< Number of lanes left based on EM Road */
  sint8 s_EMNumLaneRight;     /*!< Number of lanes right based on EM Road */
}FIP_t_LaneMatrixDebugInfo;
#endif /* FCT_SIMU */

#if (FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING)
/*! Typedef of output of FIPLaneMatrix */
typedef struct FIP_LM_Output{
  float32 f_FIPLaneWidth;                          /*!< Lane Width */
  FIP_t_LaneWidthClass t_FIPLaneWidthClass;        /*!< Lane Width Class */
  FIP_t_LaneWidthSource t_FIPLaneWidthSource;      /*!< Lane Width Source */
#ifdef FCT_SIMU
  FIP_t_LaneMatrixDebugInfo t_FIPLaneMatrixDebugInfo; /*!< Data structure used for storing Lane Matrix debug data */
#endif /* FCT_SIMU */
  sint8 s_NumOfLaneLeft;                           /*!< Number of lanes on the left */
  sint8 s_NumOfLaneRight;                          /*!< Number of lanes on the right */
#if (SLATE_CFG_EGO_LANE_DEPENDENT_BLOCKED_PATH) 
  sint8 s_CamNumLaneLeft;                          /*!< Number of Camera lanes on the left */
  sint8 s_CamNumLaneRight;                         /*!< Number of Camera lanes on the right */
#endif /* SLATE_CFG_EGO_LANE_DEPENDENT_BLOCKED_PATH */
}FIP_LM_Output_t;
#endif

/* Comment Date: 30/07/2016 Structure containing road estimation information. Structure may change after new EM Road Update */
typedef struct FIPRoadEstimationData
{
  float32 fC0;                          /*!< Road Curvature*/
  float32 fC1;                          /*!< Road Curvature Gradient*/
  float32 fYawAngle;                    /*!< Road YawAngle*/
  float32 fRangeMaxRight;               /*!< Estimated maximum range of road on right side */
  float32 fRangeMaxLeft;                /*!< Estimated maximum range of road on left side */
  float32 fYLeft;                       /*!< Estimated Distance to left side road boundary */
  float32 fYRight;                      /*!< Estimated Distance to right side road boundary */
  float32 fminXLeft;                    /*!< Minimal left side distance X from current cycle for road estimation */
  float32 fminXRight;                   /*!< Minimal right side distance X from current cycle for road estimation */
  float32 fmaxXLeftCompensated;         /*!< Estimated Confident maximum range of road on left side */
  float32 fmaxXRightCompensated;        /*!< Estimated Confident maximum range of road on right side */
  float32 fLatStdDevFiltered;           /*!< Road filtered lateral standard deviation */
  float32 fConfidenceLeft;              /*!< Confidence of left side estimation of road */
  float32 fConfidenceRight;             /*!< Confidence of right side estimation of road */
  uint8 uiTrackingStatus;               /*!< Road tracking status */
  uint8 uiTrackingStatusLeft;           /*!< Road left side tracking status */
  uint8 uiTrackingStatusRight;          /*!< Road right side tracking status */
  uint8 uiConfidence;                   /*!< Confidence on Road estimation */
} FIP_t_RoadEstimation;

/* Left Road Border information */
#if SLATE_CFG_LEFT_RIGHT_ROADBORDER_INPUT
typedef struct FIPLeftRoadBorder{
  float32 fC0;                          /*!< Left Road Border Curvature*/
  float32 fC1;                          /*!< Left Road Border Curvature Gradient*/
  float32 fYawAngle;                    /*!< Left Road Border YawAngle*/
  float32 fConfidence;                  /*!< Confidence of Left Road Border estimation*/
  float32 fMinX;                        /*!< Estimated minimum range of Left Road Border distance X */
  float32 fMaxX;                        /*!< Estimated maximum range of Left Road Border distance X */
  float32 fMaxXCompensated;             /*!< Estimated Confident maximum range Left Road Border */
  uint8 uiTrackingStatus;               /*!< Left Road Border tracking status */
  float32 fLateralOffset;               /*!< LAteral offset to Left Road Border */  
}FIPLeftRoadBorder_t;

/* Right Road Border information */
typedef struct FIPRightRoadBorder{
  float32 fC0;                          /*!< Right Road Border Curvature*/
  float32 fC1;                          /*!< Right Road Border Curvature Gradient*/
  float32 fYawAngle;                    /*!< Right Road Border YawAngle*/
  float32 fConfidence;                  /*!< Confidence of Right Road Border estimation*/
  float32 fMinX;                        /*!< Estimated minimum range of Right Road Border distance X */
  float32 fMaxX;                        /*!< Estimated maximum range of Right Road Border distance X */
  float32 fMaxXCompensated;             /*!< Estimated Confident maximum range Right Road Border */
  uint8 uiTrackingStatus;               /*!< Right Road Border tracking status */
  float32 fLateralOffset;               /*!< LAteral offset to Right Road Border */  
}FIPRightRoadBorder_t;
#endif /* end of SLATE_CFG_LEFT_RIGHT_ROADBORDER_INPUT*/
/* Comment Date: 30/07/2016 Structure containing fused road border information. Structure may change after new EM Road Update */
typedef struct FIPRoadFusedBorderData
{
  float32 fDistRight;                   /*!< Estimated Distance to right side fused road boundary */
  float32 fDistRightStd;                /*!< Standard Deviation of Estimated Distance to right side fused road boundary */
  float32 fDistLeft;                    /*!< Estimated Distance to left side fused road boundary */
  float32 fDistLeftStd;                 /*!< Standard Deviation of Estimated Distance to left side fused road boundary */
  uint8 bStatusRight;                   /*!< Confidence of Right Border estimation */
  uint8 bStatusLeft;                    /*!< Confidence of Left Border estimation */
}FIP_t_RoadFusedBorder;

/*! Structure to store information for special handling of stationary objects which were only seen stationary or oncoming */
typedef struct StatObjWasOncoming {
  uint8  uiOncomingCounter;         /*!< No. of cycles which an object was seen oncoming */  
}StatObjWasOncoming_t; // to be moved to FIP object, la.h

#ifdef FCT_SIMU
typedef struct FIPCamLaneDebugData{ 
  boolean b_MarkerToUse;        /*!< Info which lane marker should be used; if FALSE -> invalid lane markers */
} FIP_t_CamLaneDebugData;
#endif /*!< FCT_SIMU */
#if (SLATE_CFG_CAM_LANE_INTERFACE)
/*! Typedef of output of CamLane */
typedef struct FIP_CL_Output{
#ifdef FCT_SIMU
  FIP_t_CamLaneDebugData t_FIPCamLaneDebugData;      /*!< Data structure used for storing Camera Lane debug data */
#endif /*!< FCT_SIMU */
  float32  f_HeadingAngle;                        /*!< Number of lanes on the left */
  float32  f_VisibilityDist;                      /*!< Number of lanes on the right */
  float32  f_LaneWidth;                           /*!< Width of the camera lane */
  float32  f_Curve;                               /*!< Curvature of the camera lane */
  float32  f_CurvatureChange;                     /*!< Curvature change of the camera lane*/
  boolean  b_CamLaneIsRoadEdge[FIP_CL_NUM_LANES]; /*!< Info if the camera lane is a road edge */
  boolean  b_Roadworks;                           /*!< Info if camera lane indicates a roadworks (on a highway) */
#if (LA_CFG_CAM_OBJ_ASSOC_VALID)
  boolean  b_CamLaneAssocValid;                   /*!< Info if camera lane association is valid */
#endif /*end of LA_CFG_CAM_OBJ_ASSOC_VALID*/
}FIP_CL_Output_t;
#endif /* END IF SLATE_CFG_CAM_LANE_INTERFACE */

#if (FCT_CFG_INPUT_PREPROCESSSING)
/*! Typedef of output of FIPROAD */
typedef struct FIP_RD_Output{
  FIP_t_RoadEstimation t_FIPRoadEstimation;
#if SLATE_CFG_LEFT_RIGHT_ROADBORDER_INPUT
  FIPLeftRoadBorder_t t_FIPLeftRoadBorder;
  FIPRightRoadBorder_t t_FIPRightRoadBorder;
#endif /* end of SLATE_CFG_LEFT_RIGHT_ROADBORDER_INPUT */
  FIP_t_RoadFusedBorder t_FIPRoadFusedBorder;
#if (FCT_CFG_ROAD_CURVATURE_CHANGE_COMPUTATION)
  float32 f_DistToHighCC;                     /*!< Longitudinal distance to high curvature change*/  
  boolean b_RoadPathIsValidForCC;             /*!< Info if road path is valid for distance to high curvature change computation*/
#endif
}FIP_RD_Output_t;
#endif

#if (FCT_CFG_INPUT_PREPROCESSSING)
/*! Typedef of output of FIPROADTYPE */
typedef struct FIP_RT_Output{
  FIP_t_RoadWorks t_FIPRoadWorks;
  FIP_t_FusedRoadType t_FIPFusedRoadType;
#if (FCT_CFG_FUSION_NAVI_ROAD_TYPE)
  boolean b_FIPFusedRoadTypeFromNavi;
#endif
}FIP_RT_Output_t;
#endif /* END IF (FCT_CFG_INPUT_PREPROCESSSING) */

#if( (SLATE_CFG_SIMPLE_NAVI_INTERFACE) && (FCT_CFG_INPUT_PREPROCESSSING) )
#if FIP_EVAL_SHAPE_POINTS
/*!< Global structure used to store all shape point information along with segment info */
typedef struct FIPNaviReferenceShapePoint
{
  float32 af_AlphaShapePointNaviRef[FIP_NUM_NAVI_REF_SEGMENTS];     /*!< Angle of the all segments of current NAVI path */
  float32 af_LengthShapePointNaviRef[FIP_NUM_NAVI_REF_SEGMENTS];    /*!< Length of the all segments of current NAVI path */
  float32 af_CurvatureShapePointNaviRef[FIP_NUM_NAVI_REF_SEGMENTS]; /*!< Curvature of the all segments of current NAVI path */
  float32 af_XPosShapePointNaviRef[FIP_NUM_NAVI_REF_SHAPE_POINTS];  /*!<X-position of all shape points in NAVI reference*/
  float32 af_YPosShapePointNaviRef[FIP_NUM_NAVI_REF_SHAPE_POINTS];  /*!<Y-position of all shape points in NAVI reference*/
  float32 af_DiffXPosHistorySPNaviRef[FIP_NUM_HIST_SHAPE_POINTS];       /*!<X-position difference between EGO position and history shape points in NAVI reference*/
  float32 af_DiffYPosHistorySPNaviRef[FIP_NUM_HIST_SHAPE_POINTS];       /*!<Y-position difference between EGO position and history shape points in NAVI reference*/
  float32 f_AvgEGOPathDiff;
  GDBTrafoMatrix2D_t CON2COGAtEgoBufferCumulReset;                  /*!< Transformation matrix from NAVI reference coordinates to EGO reference coordinates when shape point buffer is full */
  boolean b_TreeValid;            /*!< Info if there exists a valid tree */
  boolean b_TreeExtendable;       /*!< Info if the tree can be extended by adding shape points */
  uint8 ui_IndexCurrentSegEgo;    /*!< Index indicating the position of the EGO in terms of segment */
  uint8 ui_IndexLastSPInBuffer;   /*!< Index indicating the last filled position in shape point array */
  uint8 ui_IndexDiffPosHistorySPNaviRef; /*!< Index indicating the last filled position in difference between history SP and EGO array (af_DiffXPosHistorySPNaviRef, af_DiffYPosHistorySPNaviRef) */
  uint8 ui_CountSegmentForced;    /*!< Counter for number of consecutive forced segments */
  uint8 au_ProbTakeBranchShapePointNaviRef[FIP_NUM_NAVI_REF_SEGMENTS]; /*!< Probability that EGO takes branch of the all segments of current NAVI path */
}FIPNaviReferenceShapePoint_t;

typedef struct FIPNaviShapePointEgo
{
  float32 af_XPosShapePointEgoRef[FIP_NUM_NAVI_PATH_SHAPE_POINTS]; /*!< X-position of all shape points in ego reference */
  float32 af_YPosShapePointEgoRef[FIP_NUM_NAVI_PATH_SHAPE_POINTS]; /*!< Y-position of all shape points in ego reference */
  /* This should be with FIPNaviShapePointEgo since they have to be computed in EGO reference coordinates to be used in FUSION! */
  float32 af_ParaA[FCT_NAV_NUM_SEG]; /*!< Parameter for the spline of each segment */
  float32 af_ParaB[FCT_NAV_NUM_SEG]; /*!< Parameter for the spline of each segment */
  float32 af_ParaC[FCT_NAV_NUM_SEG]; /*!< Parameter for the spline of each segment */
  float32 af_ParaD[FCT_NAV_NUM_SEG]; /*!< Parameter for the spline of each segment */
  uint8 ui_NumberOfShapePoints;     /*!< Number of shape points in EGO reference coordinate system */
  boolean b_SplineValid;  /*!< Info if entire spline interpolation was valid */
  boolean ab_SegmentSplineValid[FCT_NAV_NUM_SEG];    /*!< Info the interpolated spline for a single segment was valid */
}FIPNaviShapePointEgo_t;

/*!< Segment Info related to EGO motion */
typedef struct FIPNaviEgoSegmentInfo {
  float32 f_Length;
  float32 f_Curvature;
  float32 f_AnglePrevSeg;
  /* Seg0 refers to segment 0 in EGO reference system  */ 
  float32 f_DistInNaviSeg0;               /*!< Driven distance of ego vehicle in the first segment (segment 0) @unit:m */
  /* Forced new segment concept : Previously when EGO motion was not tracked, incoming NAVI data indicated if EGO has moved into a new segment. 
     Since the sampling rates are different for NAVI data and the FCT processing, the actual beginning of a new segment might be missed.
     By tracking EGO motion, the actual beginning of a new segment can be estimated with better accuracy, when this takes place the flag 
     indicating a forced new segment is set. */
  boolean b_ForcedNewSegment;                 /*!< Boolean indicating if the current segment was forced */
}FIPNaviEgoSegmentInfo_t;
#endif /* FIP_EVAL_SHAPE_POINTS */

/*!< Debug information during simulation */
#ifdef FCT_SIMU
typedef struct FIPNaviPlausiBitsDebug{
  boolean b_ValidNaviData;
  boolean b_QualityNavData;
  boolean b_MppNew;
  boolean b_ValidNaviNumberLanes;
  boolean b_DrivingDifferentFromNaviPath;
}FIPNaviPlausiBitsDebug_t;

typedef struct FIPNaviPathDebug{
  float32 f_LengthSeg0;
  float32 fSumLengthNaviPath;
  float32 fEgoNaviPathErrDistAvg;
  float32 fNaviPathToPolySumSqDistAvg;
  float32 fApproxC0;
  float32 fApproxC1;
  float32 fApproxC2;
  float32 fAbsMaxDiffYSampleNaviPath;
  GDBTrafoMatrix2D_t CON2COG_Matrix;
  SLATE_t_PosSamples NaviSamples;
  boolean b_NewSegment;
  boolean b_NewTree;
  boolean b_NewTreeYDiff;
  boolean b_MppNew;
  boolean b_ShiftOrigin;
  boolean bNaviPathPlausible;
  boolean bNaviPathApproxPlausible;
  boolean bNaviPathIsInCityLimits;          /*!< Info if current NAVI path indicates driving within city limits*/
  boolean bNaviPathIsADASQuality;           /*!< Info if the NAVI path is of ADAS quality */
#if FIP_EVAL_SHAPE_POINTS
  float32 f_YOffsetEgoCompAtOrig;
  float32 f_DiffAngleToFistShapePoint;
#if (FIP_NUM_HIST_SHAPE_POINTS > 0u)
  float32 f_SplineYOffsetAtEgoPos;
#endif
  FIPNaviReferenceShapePoint_t FIPShapePointsInNaviRef;
  FIPNaviShapePointEgo_t FIPShapePointsInEgoRef;
  FIPNaviEgoSegmentInfo_t NaviEGOSegment;
#endif /* FIP_EVAL_SHAPE_POINTS */
  FIPNaviPlausiBitsDebug_t PlausiBits;
  uint16  uiCountHighDiffEgo2NaviPath;
} FIP_t_NaviPathDebugInfo_t;
#endif /*!< FCT_SIMU */

#endif /* (SLATE_CFG_SIMPLE_NAVI_INTERFACE) && (FCT_CFG_INPUT_PREPROCESSSING) */
#if( (SLATE_CFG_SIMPLE_NAVI_INTERFACE) && (FCT_CFG_INPUT_PREPROCESSSING) )
/*Sim Save Data for Navi*/
typedef struct NaviDataSIM
{
  t_NaviInputData NaviInputData;
  CAL_t_TracePolyL2 NaviPathApprox;
  float32 fPosXApprox[20];
  float32 fPosYApprox[20];
  uint8 uiNumPoints;
  uint8 uiNumShapePoints;
#if 0
  float32 fKalman_C0;
  float32 fKalman_C1;
  float32 fPosXApproxKalman[20];
  float32 fPosYApproxKalman[20];
  uint8 uiNumPointsKalman;
#endif
#if (FIP_EVAL_SHAPE_POINTS)
  float32 fXPosShapeAll[FIP_NUM_NAVI_PATH_SHAPE_POINTS];
  float32 fYPosShapeAll[FIP_NUM_NAVI_PATH_SHAPE_POINTS];
#endif
  float32 af_ParaA[FCT_NAV_NUM_SEG];
  float32 af_ParaB[FCT_NAV_NUM_SEG];
  float32 af_ParaC[FCT_NAV_NUM_SEG];
  float32 af_ParaD[FCT_NAV_NUM_SEG];
  boolean ab_SegmentSplineValid[FCT_NAV_NUM_SEG];
}NaviDataSIM_t;
#endif /*( (SLATE_CFG_SIMPLE_NAVI_INTERFACE) && (FCT_CFG_INPUT_PREPROCESSSING) )*/

#if( (SLATE_CFG_SIMPLE_NAVI_INTERFACE) && (FCT_CFG_INPUT_PREPROCESSSING) )
typedef struct FIP_NDObj_Output {
  uint8 u_NumLane;
#if SLATE_CFG_NAVI_OBJ_LAT_DIST
  float32 f_NaviLatDist;                     /*!< Object Lateral Distance to corresponding position on Navi trajectory */
#endif /*end of SLATE_CFG_NAVI_OBJ_LAT_DIST */
}FIP_NDObj_Output_t;
#endif /* END IF SLATE_CFG_SIMPLE_NAVI_INTERFACE & FCT_CFG_INPUT_PREPROCESSSING */

#if( (SLATE_CFG_SIMPLE_NAVI_INTERFACE) && (FCT_CFG_INPUT_PREPROCESSSING) )
/*! Typedef of output of NAVI data */
typedef struct FIP_ND_Output{
#ifdef FCT_SIMU
  FIP_t_NaviPathDebugInfo_t t_FIPNaviPathDebugInfo;  /*!< Data structure used for storing Navi Path debug data */
#endif /* FCT_SIMU */
  float32 f_NaviPathApproxLength;             /*!< Length of NAVI path which is used for approximation of the NAVI path @unit:m */
  float32 f_YOffsetEgoCompAtOrig;             /*!< Y-Offset of ego motion compensated NAVI path at the ego position */
  float32 f_EgoNaviPathErrDistAvg;            /*!< Difference between the approximated NAVI path and the ego curve @unit:m^2 */
  float32 f_DistNextLeftExit;                 /*!< Distance to next left exit */
  float32 f_DistNextRightExit;                /*!< Distance to next right exit */
#if (FCT_CFG_NAVI_CURVATURE_CHANGE_COMPUTATION)
  float32 f_DistToHighCC;                     /*!< Longitudinal distance to High Curvature Change*/
#endif
  float32 f_CurvinessProbNear;                /*!< Curviness probability value from offset between curvature at ego position and NAVI-curvature for time-gap of 2s */
  float32 f_CurvinessProbFar;                 /*!< Curviness probability value from offset between curvature at ego position and NAVI-curvature for time-gap of 4s */
#if (FIP_EVAL_ROAD_JUNCTION)
  float32 f_Dist2Junction;                    /*!<distance to next exit/junction found on navi path */
  e_JunctionDetection_t e_JunctionDetection;                /*!<Info whether junction found */
#endif
  NaviDataSIM_t t_SIMNaviData;               /* Navi Data that needs to be saved for SIM */
  FIP_NDObj_Output_t t_ObjList[EM_N_OBJECTS]; /*!< Object specific output for FIP NAVI data */
  boolean b_NaviPathPlausible;                /*!< Info if NAVI path seems plausible */
  boolean b_NaviPathIsHighway;                /*!< Info if driving on a highway */
  boolean b_NaviPathIsCountryRoadOneLane;     /*!< Info if driving on a country road with one lane */
  boolean b_NaviPathIsInCityLimits;           /*!< Info if driving within city limits */
  boolean b_NaviPathIsADASQuality;            /*!< Info if the NAVI path is of ADAS quality */
  boolean b_NaviPathIsValid;                  /*!< Info if NAVI path is valid */
#if (FCT_CFG_CUSTOM_PASSING_STATE) && (FCT_CFG_INPUT_PREPROCESSSING)
  boolean b_OvertakeLaneIsExitLane;           /*!< Info if overtakelane is exit lane */
  boolean b_NoPassingSign;                    /*!< Info of No-Passing sign from NAVI */
#endif  /* #endif FCT_CFG_CUSTOM_PASSING_STATE & FCT_CFG_INPUT_PREPROCESSSING */
  uint8 u_NaviBranchProb;                     /*!< Probability ego will not follow navi path [0% .. 100%]*/
}FIP_ND_Output_t;
#endif /* END IF SLATE_CFG_SIMPLE_NAVI_INTERFACE & FCT_CFG_INPUT_PREPROCESSSING */

#if ((FCT_CFG_OBJECT_TRACE_PREPROCESSSING) || (FCT_CFG_USE_FCT_DYNAMIC_TRACES) || (FIP_CFG_USE_EGO_TRACE))
/*! Typedef of output of FIP Object traces */
typedef struct FIP_MOT_Output{
/*! b_Dummy is removed as one of the switches is always active */
#if (FCT_CFG_OBJECT_TRACE_PREPROCESSSING)
 FIP_MovObjStaticTraceList_t t_MovObjStaticTrace;/*!Object static trace array */
#endif
#if (FCT_CFG_USE_FCT_DYNAMIC_TRACES)
  FIP_ObjectDynTraceList_t t_MovObjDynamicTrace;
#endif
#if (FCT_CFG_OBJECT_TRACE_PREPROCESSSING)
  TraceID_t u_ReferenceToStaticTrace[EM_N_OBJECTS];
#endif
#if (FCT_CFG_USE_FCT_DYNAMIC_TRACES)
  TraceID_t u_ReferenceToDynTrace[EM_N_OBJECTS];
#endif
#if (FIP_CFG_USE_EGO_TRACE)
  FIP_t_EgoTrace t_EgoTrace;
#endif
}FIP_MOT_Output_t;
#endif /* END IF ((FCT_CFG_OBJECT_TRACE_PREPROCESSSING) || (FCT_CFG_USE_FCT_DYNAMIC_TRACES) || (FIP_CFG_USE_EGO_TRACE)) */

/*! Curvature type for each segment of the NAVI path */
typedef enum FIPNaviPathCurvatureType{
  NAVI_PATH_CURVY,            /*!< Segment is curvy (fABS(curvature) > 0) */
  NAVI_PATH_STRAIGHT,          /*!< Segment is straight (curvature = 0) */
  NAVI_PATH_POLYNOMIAL         /*< Segment is clothoid -> use polynomial approximation of clothoid */
}FIPNaviPathCurvatureType_t;

/*****************************************************************************
  (SYMBOLIC) CONSTANTS
*****************************************************************************/


/*****************************************************************************
  EXTERN VARIABLES
*****************************************************************************/

#ifdef __cplusplus
};
#endif
/// @}
/* END of #ifndef SLATE_TYPES_H_INCLUDED */
#endif
#endif
/* ************************************************************************* */
/*   Copyright ADC-GmbH, Lindau                                              */
/* ************************************************************************* */
