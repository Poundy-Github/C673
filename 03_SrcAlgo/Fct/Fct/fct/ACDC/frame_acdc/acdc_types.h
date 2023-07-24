/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG
  
PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 ACDC - Advanced collision detection and classification

PACKAGENAME:               acdc_types.h

DESCRIPTION:               Header file for the ACDC types

AUTHOR:                    $Author: Thallam, Nagasurya Latha Sree (uib46516) (uib46516) $

CREATION DATE:             $Date: 2020/10/22 09:04:16CEST $

VERSION:                   $Revision: 1.54 $

**************************************************************************** */
#ifndef ACDC_TYPES_INCLUDED
#define ACDC_TYPES_INCLUDED

/************************************************************************/
/*                        INCLUDES                                      */
/************************************************************************/
#include "acdc_custom_types.h"

#if (ACDC_CFG_SFL)
#include "sfl_ext.h"
#endif

#if (ACDC_CFG_FRAME)
/************************************************************************/
/*                      MODULE DESCRIPTION                              */
/************************************************************************/
/*!
@defgroup acdc_types Types
@ingroup frame

@brief    Contains all types of the acdc frame. \n\n
@description Looking at the acdc frame as a subcomponent all types which are defined and needed in this subcomponent are defined here. This file is simular to the "sub1_ext_types.h" files.
@{
*/

/*! @brief Activate this switch if you want to place a variable in the corresponding struct.*/
#define USE_ACDC_BASEOBJ_STACK       SWITCH_OFF
#define USE_ACDC_BASEGLOB_STACK      SWITCH_OFF

#define USE_ACDC_BASEOBJ_INTER       SWITCH_OFF
#define USE_ACDC_BASEGLOB_INTER      SWITCH_ON

#define USE_ACDC_BASEOBJ_INTERMEAS   SWITCH_OFF
#define USE_ACDC_BASEGLOB_INTERMEAS  SWITCH_ON

#define USE_ACDC_BASEOBJ_INTRAMEAS   SWITCH_OFF
#define USE_ACDC_BASEGLOB_INTRAMEAS  SWITCH_ON

#define USE_ACDC_BASEOBJ_INTRA       SWITCH_OFF
#define USE_ACDC_BASEGLOB_INTRA      SWITCH_OFF

#define USE_ACDC_BASEOBJ_SIMU        SWITCH_OFF
#define USE_ACDC_BASEGLOB_SIMU       SWITCH_OFF

/* Switches for the integration of component substructures */
#define USE_ACDC_OBJ_STACK         (USE_ACDC_BASEOBJ_STACK      || USE_ACDC_CUSTOBJ_STACK     )
#define USE_ACDC_GLOB_STACK        (USE_ACDC_BASEGLOB_STACK     || USE_ACDC_CUSTGLOB_STACK    )
#define USE_ACDC_OBJ_INTER         (USE_ACDC_BASEOBJ_INTER      || USE_ACDC_CUSTOBJ_INTER     )
#define USE_ACDC_GLOB_INTER        (USE_ACDC_BASEGLOB_INTER     || USE_ACDC_CUSTGLOB_INTER    )
#define USE_ACDC_OBJ_INTERMEAS     (USE_ACDC_BASEOBJ_INTERMEAS  || USE_ACDC_CUSTOBJ_INTERMEAS )
#define USE_ACDC_GLOB_INTERMEAS    (USE_ACDC_BASEGLOB_INTERMEAS || USE_ACDC_CUSTGLOB_INTERMEAS)
#define USE_ACDC_OBJ_INTRAMEAS     (USE_ACDC_BASEOBJ_INTRAMEAS  || USE_ACDC_CUSTOBJ_INTRAMEAS )
#define USE_ACDC_GLOB_INTRAMEAS    (USE_ACDC_BASEGLOB_INTRAMEAS || USE_ACDC_CUSTGLOB_INTRAMEAS)
#define USE_ACDC_OBJ_INTRA         (USE_ACDC_BASEOBJ_INTRA      || USE_ACDC_CUSTOBJ_INTRA     )
#define USE_ACDC_GLOB_INTRA        (USE_ACDC_BASEGLOB_INTRA     || USE_ACDC_CUSTGLOB_INTRA    )
#define USE_ACDC_OBJ_SIMU          (USE_ACDC_BASEOBJ_SIMU       || USE_ACDC_CUSTOBJ_SIMU      )
#define USE_ACDC_GLOB_SIMU         (USE_ACDC_BASEGLOB_SIMU      || USE_ACDC_CUSTGLOB_SIMU     )
/* End of switches for the integration of component substructures */


/*****************************************************************************
  TYPEDEFS ACDC_VER
*****************************************************************************/
#ifndef CDHypothesisType_RunupCoMoving
/*  @description  CDHypothesisType_RunupCoMoving is only defined in interface versions (FCT_HYPOTHESIS_INTFVER = 0x00001C) or newer.
                  Assure that it is treated like CDHypothesisType_RunUp in older versions by setting the switch @ref ACDC_USE_HYP_TYPE_RUNUP_COMOVING to false. 
                  This definition is done to be able to execute all calculations equally to the new interface versions.*/
#define CDHypothesisType_RunupCoMoving 14U
#endif

typedef uint32 ACDCSwVersion_t; /*!< Type used for describing an FCT sub-component version */

/*****************************************************************************
  TYPEDEFS EMP
*****************************************************************************/

/*! @brief Enum describing different types of maneuvers. (Typically maneuvers that are expected in the future.)*/
typedef enum {
  ACDC_MANEUVER_KinematicsUnchanged,                /*!< The current kinematics will not change */
  ACDC_MANEUVER_KinematicsWithoutAcceleration,      /*!< The current kinematics will not change. Accelerations are assumed to be 0*/
  ACDC_MANEUVER_KinematicsUnchanged_Front,          /* PRQA S 0779 *//* date: 2020-10-22, reviewer:Ponnapalli, Ramalingeswara Rao, reason: Identifiers are different after 16 characters  */ /*!< The current kinematics will not change, prediction of obj front */
  ACDC_MANEUVER_KinematicsWithoutAcceleration_Front,/* PRQA S 0779 *//* date: 2020-10-22, reviewer:Ponnapalli, Ramalingeswara Rao, reason: Identifiers are different after 16 characters  *//*!< The current kinematics will not change. Accelerations are assumed to be 0, pred. of obj. front */
  ACDC_MANEUVER_ComfortBraking,                     /*!< A comfort brake acceleration is applied*/
  ACDC_MANEUVER_FullBraking,                        /*!< A full brake acceleration is applied*/
  ACDC_MANEUVER_PrecisionBraking,                   /*!< A brake acceleration is applied which stops the vehicle at the required position*/ 
  ACDC_MANEUVER_MediumAvoidCollSteerBrake,          /*!< EMP maneuver of type Medium Avoid Collision Steer Brake */
  ACDC_MANEUVER_MaximumAvoidCollSteerBrake,         /*!< EMP maneuver of type Maximum Avoid Collision Steer Break */
  ACDC_MANEUVER_NumOfTypes
} ACDCManeuverType_e;

/*! @brief Structure to describe an object circle with its trajectory ref Point, its DistToTraj and its RefPoint Angle*/
typedef struct ACDCObjectCircle{
  SFLCircle_t   Circle;          /*!< Radius of the circle.                               @phys_unit [m]*/
  SFLVector2D_t RefPoint;        /*!< Reference point of the circle center. (=projection onto the ego trajectory.)*/
  float32       fDistToTraj;     /*!< Distance to trajectory of the circle center.        @phys_unit [m]*/
  float32       fRefPointAngle;  /*!< Angle of the ego trajectory at the reference point. @phys_unit [rad]*/
} ACDCObjectCircle_t;

/*! @brief Structure to store the object related circle data*/
typedef struct ACDCObjectCircleData{
  ACDCObjectCircle_t ObjectCircles[ACDC_MAX_NOF_OBJECT_CIRCLES]; /*!< Object circles assigned to the object. */
  uint8              uMinDistCircle;  /*!< Index of the circle with the lowest distance to trajectory (Not absolute!)*/
  uint8              uMaxDistCircle;  /*!< Index of the circle with the highest distance to trajectory (Not absolute!)*/
  uint8              uNofCircles;     /*!< Number of object circles that are stored int he array ObjectCircles[] */
} ACDCObjectCircleData_t;

/*! @brief Structure used to describe a trajectory prediction in x and y direction, including the variance.*/
typedef struct ACDCTrajPred
{
  SFLPolyDeg2_t XofT;    /*!< 2nd degree Polynomial describing the x position of an object. Typical: \unit [m]*/
  SFLPolyDeg2_t YofT;    /*!< 2nd degree Polynomial describing the y position of an object. Typical: \unit [m]*/
  SFLPolyDeg2_t VarXofT; /*!< 2nd degree Polynomial describing the variance in x direction of an object. Typical: \unit [m]*/
  SFLPolyDeg2_t VarYofT; /*!< 2nd degree Polynomial describing the variance in y direction of an object. Typical: \unit [m] */
} ACDCTrajPred_t;

/*! @brief Structure used to define the size of an object. */
typedef struct ACDCGeometry
{
  float32 fWidth;               /*!< Width of the object.  Typical: \unit [m] */
  float32 fLength;              /*!< Length of the object. Typical: \unit [m] */
  float32 fOrientation;         /*!< Orientation of the object. Typical: \unit [rad] */
} ACDCGeometry_t;

/*! @brief Structure used to describe the kinematics of the ego vehicle. */
typedef struct ACDCKinEgo
{
  float32 fVel;                 /*!< Velocity of the ego vehicle.    \Typical: [m/s]   */
  float32 fAccel;               /*!< Acceleration of the ego object. \Typical: [m/s^2] */
  float32 fYawRate;             /*!< YawRate of the ego object.      \Typical: [rad/s] */
} ACDCKinEgo_t;


/*! @brief Structure used to describe an object */
typedef struct ACDCObjDesc
{
  boolean                 bExists;          /*!< Boolean indicating if an object exists (True) or not (False).*/
  ACDCGeometry_t          Geometry;         /*!< Geometry of an object (e.g. length, width).*/
  SFLMovement_t           Movement;         /*!< Kinematics of the object. */
  SFLVector2D_t           ObjectPosCenter;  /*!< Position of the objects center (based on shape points).*/
} ACDCObjDesc_t;

/*! @brief Structure used to describe the prediction of an object*/
typedef struct ACDCObjPred
{
  const ACDCTrajPred_t  * pTrajPred;        /*!< Predicted trajectory of the object*/
  const ACDCGeometry_t * pGeometry;        /*!< Geometry of the object. (e.g. length, width)*/
} ACDCObjPred_t;

/*! @brief Structure used for defining EMP object to trajectory relation */
typedef struct ACDCObjToTrajRelation
{
  float32 fDistToTraj;            /*!< lateral object displacement to a trajectory.                  Typical: \unit [m]*/
  float32 fDistToTrajVar;         /*!< variance of lateral object displacement to a trajectory.      Typical: \unit [m]*/
  float32 fDistToTrajMin;         /*!< lateral object displacement to a trajectory.                  Typical: \unit [m]*/
  float32 fDistToTrajMax;         /*!< lateral object displacement to a trajectory.                  Typical: \unit [m]*/
  float32 fVelocityToTraj;        /*!< lateral object velocity to a trajectory.                      Typical: \unit [m/s]*/
  float32 fVelocityToTrajVar;     /*!< variance of lateral object velocity to a trajectory.          Typical: \unit [m/s]*/
  float32 fDistOnTraj;            /*!< longitudinal object displacement on a trajectory.             Typical: \unit [m]*/
  float32 fDistOnTrajVar;         /*!< variance of longitudinal object displacement on a trajectory. Typical: \unit [m]*/
  float32 fVelocityOnTraj;        /*!< longitudinal object velocity to a trajectory.                 Typical: \unit [m/s]*/
  float32 fVelocityOnTrajVar;     /*!< variance of longitudinal object velocity to a trajectory.     Typical: \unit [m/s]*/
  float32 fDistToTrajMinAngle;    /*!< angle of the vector of the DistToTrajMin. @phys_unit [rad]*/
  float32 fDistToTrajMaxAngle;    /*!< angle of the vector of the DistToTrajMax. @phys_unit [rad]*/
  float32 fDistToTrajAngle;       /*!< angle of the vector of the DistToTraj. @phys_unit [rad]*/
} ACDCObjToTrajRelation_t;


/*****************************************************************************
  TYPEDEFS ACDC
*****************************************************************************/
/*! @brief          Define structure for the access to the different positions of a shape point in an object.
    @description    Describes the position a shape point has in the context of an object. Size is described by the define @ref ACDC_NOF_SP_POSITIONS */
typedef enum
{
  SP_FRONT_LEFT,                /*!< Denominates the shape point at the left front of the object.*/
  SP_FRONT_RIGHT,               /*!< Denominates the shape point at the right front of the object.*/
  SP_REAR_RIGHT,                /*!< Denominates the shape point at the right rear of the object.*/
  SP_REAR_LEFT                  /*!< Denominates the shape point at the left rear of the object.*/
}ACDCShapePointPositions_e;

/*! @brief          Enum for the access to the different positions of an object.*/
typedef enum
{
  POS_CENTER,                   /*!< Position in the center of the object */
  POS_CLOSEST_IN_CORR,          /*!< Closest Position in the corridor of the object */
  POS_CLOSEST_IN_X,             /*!< Closest Position in X of the object */
  POS_GEN_OBJECT,               /*!< Position of the GenObject */
  POS_VAR                       /*!< Variance of the Position of the object */
}ACDCObjPositions_e;

/*! @brief          Enum for the access to the different Kinematics of an object.*/
typedef enum
{
  KIN_ABS,                      /*!< Absolute object kinematics */
  KIN_REL,                      /*!< Relative object kinematics */
  KIN_VAR                       /*!< Variance of the absolute object kinematics */
}ACDCObjKinematics_e;

/*! @brief          Define ACDC Comp state if it is not available already. This improves consistency, as all components work with the same states.
    @description    ACDC component state. Describes the state in which a (Sub-)component is currently. 
                      @range[0,6], @values: enum { COMP_STATE_NOT_INITIALIZED=0,
                                                   COMP_STATE_RUNNING=1,
                                                   COMP_STATE_TEMPORARY_ERROR=2,
                                                   COMP_STATE_PERMANENT_ERROR=3,
                                                   COMP_STATE_SUCCESS=4,
                                                   COMP_STATE_REDUCEDAVAILABILITY=5,
                                                   COMP_STATE_NOT_RUNNING=6} */
typedef uint8 ACDCCompState_t;


/*! @brief          ACDC Subcomponent Indices.
    @description    Bitfield with Indices for each subcomponent. Can handle a maximum of 8 subcomponents.
                    The current number of subcomponent is defined by @ref ACDC_NOF_SUB_COMPONENTS.
                      @range[0,255], 
                      @values: 
                      struct {
                      .offset(0) = uint8 Bits; 
                      .offset(0).mask((ACDC_SUB_COMP_AIP)) = uint8 bAIP; 
                      .offset(0).mask((ACDC_SUB_COMP_CD)) = uint8 bCD; 
                      .offset(0).mask((ACDC_SUB_COMP_ESPM)) = uint8 bESPM; 
                      .offset(0).mask((ACDC_SUB_COMP_EMP)) = uint8 bEMP; 
                      .offset(0).mask((ACDC_SUB_COMP_SFL)) = uint8 bSFL; 
                      .offset(0).mask((ACDC_SUB_COMP_ACDC)) = uint8 bACDC; 
                      } */
typedef uint8 ACDCSubCompIndices_t;

/*! @brief          Generic Data contained in each Req/Pro Port
    @description    Describes generic data that is contained in each Req/Pro port: The Version Number and the Signal header. 
                    This data type is used to enable a generic handling of all ports. (see @ref ACDCPortHandlerList_t)*/
typedef struct ACDCGenericPortData
{
  AlgoInterfaceVersionNumber_t uiVersionNumber;
  SignalHeader_t sSigHeader;
}ACDCGenericPortData_t;

/*! @brief    Structure of the require port handler. It is filled by the function @ref ACDC_v_SetupReqPortHander */
typedef struct ACDCReqPortHandler{
  void                  const * pReqPort;                 /*!< Pointer to the considered require port.*/
  ACDCGenericPortData_t const * pGenericReqPortData;      /*!< Pointer to the signal header and version number of the considered require port.*/
  SignalHeader_t              * pReqSignalHeaderSyncRef;  /*!< Pointer to the corresponding signal header in @ref ACDC_p_GetSyncRef.*/
  sMeasCycleMonitor             MeasCycleMonitor;         /*!< MeasCycleInformation of the corresponding port.*/
  ACDCSubCompIndices_t          InfluencedSubComponents;  /*!< Bitfield indicating which subcomponents are affected by the Req Port.*/
}ACDCReqPortHandler_t;

/*! @brief    Structure of the provide port handler. It is filled by the function @ref ACDC_v_SetupProPortHander */
typedef struct ACDCProPortHandler{
  void                        * pProPort;                   /*!< Pointer to the considered provide port.*/
  ACDCGenericPortData_t       * pGenericProPortData;        /*!< Pointer to the signal header and version number of the considered provide port.*/
  ACDCGenericPortData_t const * pGenericReqPortData;        /*!< Signal header of the require port which shall be source for the signal header of the provide port.*/
  uint32                        uSize;                      /*!< Size of the structure of the provide port. Needed here for freezing.*/
  uint32                        uMeasFreezeAddress;         /*!< Address to which the information provided by the port shall be frozen.*/
  uint32                        uProNewVersionNumber;       /*!< Version number that shall be written to the provide port.*/
  ACDCSubCompIndices_t          uInfluencingSubComponents;  /*!< Bitfield indicating which subcomponents are affecting the content of the Pro Port*/
}ACDCProPortHandler_t;

/*PRQA S 3494,3493,4304,4548 5*/ /* date: 2019-05-14, reviewer: Schnurr, Clemens, reason: defensive programming with parameters*/
/*! @brief    Contains two lists of handlers: One for all provide ports and one for all require ports.*/
typedef struct ACDCPortHandlerList
{
  ACDCProPortHandler_t    ProPortHandler[ACDC_NOF_PRO_PORTS];   /*!< List of all provide port handlers*/
  ACDCReqPortHandler_t    ReqPortHandler[ACDC_NOF_REQ_PORTS];   /*!< List of all require port handlers*/
  uint8                   uNofProPorts;                         /*!< Number of Ports stored in the provide port handler list*/
  uint8                   uNofReqPorts;                         /*!< Number of Ports stored in the require port handler list*/
}ACDCPortHandlerList_t;


/*! @brief    structure containing information about the current project and software version*/
typedef struct ACDCVersions
{
  uint32           uProjectID;              /*!< ID of the current project*/
  ACDCSwVersion_t  ACDC_VERSION_AS_TEXT;
  ACDCSwVersion_t  ACDCSwVersion;           /*!< ID of the current ACDC software version*/
} ACDCVersions_t;

/*! @brief  structure for a global variable containing frame information 
            for the calculations of the acdc component.  */
typedef struct ACDCFrame { 
  AlgoCycleCounter_t  uiCycleCounter;   /*!< Is increased by 1 in each cycle. */
  ACDCVersions_t      Versions;         /*!< Contains information about the current project and software. */
  uint16              uiVDYSigErrorCnt; /*!< Counts consecutive VDY signal errors */ 
  ACDCCompState_t     eACDCState;       /*!< Current state of the ACDC component.*/
  ACDCCompState_t     eCDState;         /*!< Current state of the CD subcomponent.*/
  ACDCCompState_t     eESPMState;       /*!< Current state of the ESPM subcomponent.*/
  ACDCCompState_t     eAIPState;        /*!< Current state of the AIP subcomponent.*/
  FCT_OP_MODE_t       eOpMode;          /*!< Operation mode in which the ACDC component is called. */
  boolean             bIsInitialized;   /*!< Boolean showing if the component has been initialized. */
} ACDCFrame_t;                          /*!< The function frame*/


/*! @brief          Structure to describe all relevant positions of an object.*/
typedef struct ACDCObjPositions{
  SFLVector2D_t Center;                       /*!<Center position of the object*/
  SFLVector2D_t ClosestInCorr;                /*!<Closest position of the object in the ego corridor*/
  SFLVector2D_t ClosestInX;                   /*!<Closest position of the object in longitudinal direction*/
  SFLVector2D_t GenObject;                    /*!<Position of the Generic Object*/
  SFLVector2D_t Var;                          /*!<Variance of the position of the object*/
}ACDCObjPositions_t;

/*! @brief          Structure to describe all movements of an object.*/
typedef struct ACDCObjMovement{
  SFLMovement_t Abs;                          /*!<Absolute Object movement                     */
  SFLMovement_t Rel;                          /*!<Object movement relative to the ego movement */
  SFLMovement_t Var;                          /*!<Variance of the absolute object movement     */
}ACDCObjMovement_t;

/*! @brief          Structure to describe the main properties of an object*/
typedef struct ACDCObjDescMain{
  ACDCObjMovement_t             Movement;     /*!< Movement of the object*/
  ACDCObjPositions_t            Positions;    /*!< Relevant positions of the object */
  ACDCObjToTrajRelation_t       TrajRelation; /*!< Relation of the object and the ego trajectory */
  ACDCGeometry_t                Geometry;     /*!< Geometry of an object (e.g. length, width).*/
}ACDCObjDescMain_t;

/*! @brief          Structure to describe the additional information attached to an object*/
typedef struct ACDCObjDescAdd{
  SFLVector2D_t                 asLimitedShapePoints[EM_GEN_OBJ_N_SHAPE_POINTS]; /*!< Modified Shape Points after the limitation in the function @ref AIP_v_CalculateLimitedShapePoints.*/
  float32                       afShapePointQualities[EM_GEN_OBJ_N_SHAPE_POINTS];/*!< Measurement quality of each shape point. @range [0,1]*/
  sint8                         aiShapePointPositions[ACDC_NOF_SP_POSITIONS];    /*!< Relative positioning of the objects shape points. 
                                                                                      Access with the elements of the enum @ref ACDCShapePointPositions_e*/
}ACDCObjDescAdd_t;


/*! @brief    Describes an ACDC intern object. */
typedef struct ACDCObject {
  ACDCObjDescMain_t   ObjDescMain;            /*!< Main description of an ACDC Object */
  ACDCObjDescAdd_t    ObjDescAdd;             /*!< Additional description of an ACDC Object */
} ACDCObject_t;


#ifdef ACDC_SIMU
/*! @brief    Contains all object related data which shall only be stored for simulation purposes */
typedef struct ACDCObjectSimu{

#if(ACDC_CFG_USE_OBJECT_CIRCLES)
  ACDCObjectCircleData_t ObjectCircleData;
#endif
  uint8 uDummy;
}ACDCObjectSimu_t;


typedef struct ACDCTrajOccupancySimu{
  uint32  uNofCalculations;                                 /*!< Number of calculation steps that have been executed to calculate the traj occupancy */
  float32 afDecelerations[SFL_TRAJOCC_MAX_NOF_TIME_STEPS];  /*!< Table with allowed decelerations */
}ACDCTrajOccupancySimu_t;

/* @brief    Contains all EPF target related data which shall only be stored for simulation purposes */
typedef struct ACDCEPFTargetSimu {
  SFLVector2D_t sTargetKinNow;
  SFLVector2D_t sTargetKinPred;
  float32       fSafetyDist;
  ObjNumber_t   iTargetID;
} ACDCEPFTargetSimu_t;

#endif /* ACDC_SIMU */

/*! @brief    Contains all data related to the ego vehicle*/
typedef struct ACDCEgoData{
  ACDCGeometry_t Geometry;                            /*<! Ego vehicle geometry: Width, Length and orientation */
  ACDCKinEgo_t   Kinematics;                          /*<! Ego vehicle kinematics: Velocity, Acceleration and Yaw Rate*/
  SFLMovement_t  MovementRaw;                         /*<! Ego vehicle raw movement: Velocity & Acceleration in X and Y*/
  SFLMovement_t  MovementObjSync;                     /*<! Ego vehicle object synchronized movement: Velocity & Acceleration in X and Y*/
  ACDCTrajPred_t aTrajPred[ACDC_MANEUVER_NumOfTypes]; /*<! Possible ego vehicle trajectories for different driving scenarios described in @ref ACDCManeuverType_e*/
  SFLCircle_t    TrajCircle;                          /*<! Circle describing the ego trajectory */
}ACDCEgoData_t;

/*! @brief    Enum containing all states used in the function @ref ACDC_SERVICE_ADD_EVENT*/
typedef enum {
  ACDC_RTA_PROCESS,                          /*!< Whole EBASEN procedure runtime */
  ACDC_RTA_PRE_PROCESS,                      /*!< Data preprocessing runtime */
  ACDC_RTA_POST_PROCESS,                     /*!< Post processing runtime */
  ACDC_RTA_PROCESSFREEZE,                    /*!< Process Measfreeze runtime */
  ACDC_RTA_FRAMEFREEZE,                      /*!< Frame Measfreeze runtime */
  ACDC_RTA_AIP,                              /*!< ACDC Input Processing runtime */
  ACDC_RTA_CD,                               /*!< Collision Detection runtime */
  ACDC_RTA_CD_UPDATE_EMP,                    /*!< CD EMP Update runtime */
  ACDC_RTA_CD_CALCULATE_OBJECT_PROP,         /*!< Calculate object properties (all objects) runtime */
  ACDC_RTA_CD_HYPO_HANDLER,                  /*!< Test all hypotheses for all objects runtime */
  ACDC_RTA_CD_HYPO_UPDATE,                   /*!< Update hypotheses runtime */
  ACDC_RTA_CD_SORT_HYPO,                     /*!< Sort hypotheses runtime */
  ACDC_RTA_CD_CUSTOMER_FUNCTIONS,            /*!< Customer specific functions runtime */
  ACDC_RTA_CD_HYP_ACC_SINGLE,                /*!< Hypothesis ACC runtime (one object) */
  ACDC_RTA_CD_HYP_COLLISION_SINGLE,          /*!< Hypothesis Collision runtime (one object) */
  ACDC_RTA_CD_HYP_CROSSING_SINGLE,           /*!< Hypothesis Crossing runtime (one object) */
  ACDC_RTA_CD_HYP_CUTIN_SINGLE,              /*!< Hypothesis Cutin runtime (one object) */
  ACDC_RTA_CD_HYP_PASS_SINGLE,               /*!< Hypothesis Pass runtime (one object) */
  ACDC_RTA_CD_HYP_PEDCOLL_SINGLE,            /*!< Hypothesis PedCollision runtime (one object) */
  ACDC_RTA_CD_HYP_BICYCLECOLL_SINGLE,        /*!< Hypothesis CycleColl runtime (one object) */
  ACDC_RTA_CD_HYP_RUNUP_SINGLE,              /*!< Hypothesis RunUp runtime (one object) */
  ACDC_RTA_CD_HYP_RUNUP_STAT_SINGLE,         /*!< Hypothesis Runup Stationary runtime (one object) */
  ACDC_RTA_CD_HYP_TURNINTOVRU_SINGLE,        /*!< Hypothesis turn into oncoming VRU runtime (one object) */
  ACDC_RTA_CD_HYP_STATIC_SINGLE,             /*!< Hypothesis Static runtime (one object) */
  ACDC_RTA_CD_HYP_DRIVEINTOSLOMO_SINGLE,     /*!< Hypothesis drive into slow moving runtime (one object) */
  ACDC_RTA_CD_HYP_ACC,                       /*!< Hypothesis ACC runtime (all objects) */
  ACDC_RTA_CD_HYP_COLLISION,                 /*!< Hypothesis Collision runtime (all objects) */
  ACDC_RTA_CD_HYP_CROSSING,                  /*!< Hypothesis Crossing runtime (all objects) */
  ACDC_RTA_CD_HYP_ONCOMING,                  /*!< Hypothesis Oncoming runtime (all objects) */
  ACDC_RTA_CD_HYP_CUTIN,                     /*!< Hypothesis Cutin runtime (all objects) */
  ACDC_RTA_CD_HYP_PASS,                      /*!< Hypothesis Pass runtime (all objects) */
  ACDC_RTA_CD_HYP_PEDCOLL,                   /*!< Hypothesis PedCollision runtime (all objects) */
  ACDC_RTA_CD_HYP_PEDPASS,                   /*!< Hypothesis PedPass runtime (all objects) */
  ACDC_RTA_CD_HYP_BICYCLECOLL,               /*!< Hypothesis CycleColl runtime (all objects) */
  ACDC_RTA_CD_HYP_RUNUP,                     /*!< Hypothesis RunUp runtime (all objects) */
  ACDC_RTA_CD_HYP_RUNUPLONG,                 /*!< Hypothesis RunUp runtime (all objects) */
  ACDC_RTA_CD_HYP_RUNUP_STAT,                /*!< Hypothesis Runup Stationary runtime (all objects) */
  ACDC_RTA_CD_HYP_TURNINTOVRU,               /*!< Hypothesis turn into oncoming VRU runtime (all objects) */
  ACDC_RTA_CD_HYP_DRIVEINTOSLOMO,            /*!< Hypothesis drive into slow moving runtime (all objects) */
  ACDC_RTA_CD_HYP_STATIC,                    /*!< Hypothesis Static runtime (all objects) */
  ACDC_RTA_CD_CALCULATE_SINGLE_OBJECT_PROP,  /*!< Calculate object properties (single object) runtime -> show after 12*/
  ACDC_RTA_CD_CALCULATE_TTC,                 /*!< Calculate single object TTCs */
  ACDC_RTA_CD_CALCULATE_LONG,                /*!< Calculate single object AnecLong and TTBs */
  ACDC_RTA_CD_CALCULATE_LAT,                 /*!< Calculate single object AnecLat and TTSs */
  ACDC_RTA_CD_CALCULATE_ASSIGN,              /*!< Calculate single object Track assignment and rest */
  ACDC_RTA_CD_CALCULATE_COMMON,              /*!< Calculate single object common data */
  ACDC_RTA_ESPM,                             /*!< Collision Detection runtime */
  ACDC_RTA_CD_CALCULATE_TRAJ_RELATION,       /*!< Calculate trajectory relation */
  ACDC_RTA_CD_UPDATE_OBJ_HIST,               /*!< Update object history */
  ACDC_RTA_CD_TRAJOCCUPANCY_ACDC,            /*!< Calculation of the trajectory occupancy */
  ACDC_RTA_CD_TRAJOCCUPANCY_MEDIC,           /*!< Calculation of the TTX on base of the trajectory occupancy (To be shifted to MEDIC)*/
  ACDC_RTA_CD_OBSERVE_EGO_BEHAVIOR,          /*!< Observers for the Ego behavior ex: turning scenario detection*/
  ACDC_RTA_CD_EPF,                           /*!< EPF runtime */
  ACDC_RTA_NOF_CHECKPOINTS                   /*!< This line has to be the last to determine the size of the structure */
} ACDC_t_RtaMapping; /* RTA_LOCAL_ID_FOR_XML_GENERATION */

#if FCT_CFG_RUNTIME_MEAS

#ifndef FCT_MEAS_ID_EBA_RUNTIME_DEBUG
/*! @brief Virtual address for FCT EBA runtime measurement freeze in the device (to be moved to rte) */
#define FCT_MEAS_ID_EBA_RUNTIME_DEBUG 0x20273A00u
#endif

/*! @brief    Structure is used to store the runtime of all considered events.
              It is filled in the function @ref ACDC_SERVICE_ADD_EVENT. */
typedef struct
{
  uint32 uACDCRuntime[ACDC_RTA_NOF_CHECKPOINTS];
}ACDCRuntimeInfo_t;
#endif

typedef struct 
{
  ACDCObjPositions_t    Pos;
  ACDCGeometry_t        Geometry;
  ACDCObjMovement_t     Movement;
  ObjNumber_t           iObj;
  sint8                 iHyp;
}ACDCDebugObj_t;











/************************************************************************/
/* ACDC generic memory type setup                                       */
/************************************************************************/


/*! ACDC object data */
#if (USE_ACDC_OBJ_STACK)
typedef struct  ACDC_ObjStack_t  
{
#if (USE_ACDC_CUSTOBJ_STACK)
  ACDC_ObjDataCustStack_t Custom;
#endif /* USE_ACDC_CUSTOBJ_STACK */
}ACDC_ObjStack_t;
#endif /* USE_ACDC_OBJ_STACK */

/*! ACDC global data */
#if (USE_ACDC_GLOB_STACK)
typedef struct  ACDC_GlobDataStack_t  
{
#if (USE_ACDC_CUSTGLOB_STACK)
  ACDC_GlobDataCustStack_t Custom;
#endif /* USE_ACDC_CUSTGLOB_STACK */
}ACDC_GlobDataStack_t;
#endif /* USE_ACDC_GLOB_STACK */

/*! ACDC object data */
#if (USE_ACDC_OBJ_INTER)
typedef struct  ACDC_ObjInter_t  
{
#if (USE_ACDC_CUSTOBJ_INTER)
  ACDC_ObjDataCustInter_t Custom;
#endif /* USE_ACDC_CUSTOBJ_INTER */
}ACDC_ObjInter_t;
#endif /* USE_ACDC_OBJ_INTER */

/*! ACDC global data */
#if (USE_ACDC_GLOB_INTER)
typedef struct  ACDC_GlobDataInter_t  
{
#if (USE_ACDC_CUSTGLOB_INTER)
  ACDC_GlobDataCustInter_t Custom;
#endif /* USE_ACDC_CUSTGLOB_INTER */
  ACDCPortHandlerList_t  ACDC_PortHandlerList;
}ACDC_GlobDataInter_t;
#endif /* USE_ACDC_GLOB_INTER */

/*! ACDC object data */
#if (USE_ACDC_OBJ_INTERMEAS)
typedef struct  ACDC_ObjInterMeas_t  
{
#if (USE_ACDC_CUSTOBJ_INTERMEAS)
  ACDC_ObjDataCustInterMeas_t Custom;
#endif /* USE_ACDC_CUSTOBJ_INTERMEAS */

}ACDC_ObjInterMeas_t;
#endif /* USE_ACDC_OBJ_INTERMEAS */

/*! ACDC global data */
#if (USE_ACDC_GLOB_INTERMEAS)
typedef struct  ACDC_GlobDataInterMeas_t  
{
#if (USE_ACDC_CUSTGLOB_INTERMEAS)
  ACDC_GlobDataCustInterMeas_t Custom;
#endif /* USE_ACDC_CUSTGLOB_INTERMEAS */
  ACDCFrame_t       sFrame;
}ACDC_GlobDataInterMeas_t;
#endif /* USE_ACDC_GLOB_INTERMEAS */



/************************************************************************/
/* ACDC IntraMeas types                                                 */
/************************************************************************/

/* ACDC object data */
#if (USE_ACDC_OBJ_INTRAMEAS)
typedef struct  ACDC_ObjIntraMeas_t  
{
#if (USE_ACDC_CUSTOBJ_INTRAMEAS)
  ACDC_ObjDataCustIntraMeas_t Custom;
#endif /* USE_ACDC_CUSTOBJ_INTRAMEAS */

}ACDC_ObjIntraMeas_t;
#endif /* USE_ACDC_OBJ_INTRAMEAS */

/* ACDC global data */
#if (USE_ACDC_GLOB_INTRAMEAS)
typedef struct  ACDC_GlobDataIntraMeas_t  
{
#if (USE_ACDC_CUSTGLOB_INTRAMEAS)
  ACDC_GlobDataCustIntraMeas_t Custom;
#endif /* USE_ACDC_CUSTGLOB_INTRAMEAS */
  ACDCSyncRef_t ACDC_SyncRef;
#if (FCT_CFG_RUNTIME_MEAS)
  ACDCRuntimeInfo_t sRuntimeInfo;
#endif
}ACDC_GlobDataIntraMeas_t;
#endif /* USE_ACDC_GLOB_INTRAMEAS */



/************************************************************************/
/* ACDC Intra types                                                     */
/************************************************************************/
/* ACDC object data */
#if (USE_ACDC_OBJ_INTRA)
typedef struct  ACDC_ObjIntra_t  
{
#if (USE_ACDC_CUSTOBJ_INTRA)
  ACDC_ObjDataCustIntra_t Custom;
#endif /* USE_ACDC_CUSTOBJ_INTRA */
}ACDC_ObjIntra_t;
#endif /* USE_ACDC_OBJ_INTRA */

/* ACDC global data */
#if (USE_ACDC_GLOB_INTRA)
typedef struct  ACDC_GlobDataIntra_t  
{
#if (USE_ACDC_CUSTGLOB_INTRA)
  ACDC_GlobDataCustIntra_t Custom;
#endif /* USE_ACDC_CUSTGLOB_INTRA */
}ACDC_GlobDataIntra_t;
#endif /* USE_ACDC_GLOB_INTRA */


#ifdef ACDC_SIMU
/************************************************************************/
/* ACDC Simu types                                                      */
/************************************************************************/
/* ACDC object data */
#if (USE_ACDC_OBJ_SIMU)
typedef struct  ACDC_ObjSimu_t  
{
#if (USE_ACDC_CUSTOBJ_SIMU)
  ACDC_ObjDataCustSimu_t Custom;
#endif /* USE_ACDC_CUSTOBJ_SIMU */
}ACDC_ObjSimu_t;
#endif /* USE_ACDC_OBJ_SIMU */

/* ACDC global data */
#if (USE_ACDC_GLOB_SIMU)
typedef struct  ACDC_GlobDataSimu_t  
{
#if (USE_ACDC_CUSTGLOB_SIMU)
  ACDC_GlobDataCustSimu_t Custom;
#endif /* USE_ACDC_CUSTGLOB_SIMU */

}ACDC_GlobDataSimu_t;
#endif /* USE_ACDC_GLOB_SIMU */
#endif /* ACDC_SIMU */




/*! @}*/
#endif /* ACDC_CFG_FRAME */

#endif
