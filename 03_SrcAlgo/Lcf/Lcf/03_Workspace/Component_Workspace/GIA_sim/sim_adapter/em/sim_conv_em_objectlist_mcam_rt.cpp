/*! \file **********************************************************************

  COMPANY:         Continental

  PROJECT:         Simulation

  COMPONENT:       sim_adapter em

  MODULNAME:       sim_conv_em_objectlist_mcam_rt.cpp

  DESCRIPTION:     Converter for Renault Camera object list

  AUTHOR:          David Kubera

  CREATION DATE:   24.05.2016

  VERSION:         $Revision: 1.1 $

  ---*/ /*---
  CHANGES:         $Log: sim_conv_em_objectlist_mcam_rt.cpp  $
  CHANGES:         Revision 1.1 2017/08/10 13:15:05CEST uid34177 
  CHANGES:         Initial revision
  CHANGES:         Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_adapter/em/project.pj
  CHANGES:         Revision 1.2 2016/10/25 07:19:10CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:         + V1, V2 and V3
  CHANGES:         Revision 1.1 2016/05/30 15:35:15CEST Kubera, David (kuberad) 
  CHANGES:         Initial revision
  CHANGES:         Member added to project /nfs/projekte1/PROJECTS/ARS400/06_Algorithm/04_Engineering/03_Workspace/algo/sim_adapter/em/project.pj

**************************************************************************** */
/* includes ---------------------------------------------------------------- */
#include "stdafx.h"
#include "sim_conv_em_objectlist_mcam_rt.h"
#include "sim_versioninfo_impl.h"

// typedef float float32;
//typedef unsigned __int8 boolean/*, uint8*/;
// typedef unsigned __int32 uint32;

static const unsigned int EMRT_N_MCAM_OBJECTS = 12u;

typedef unsigned __int32 AlgoInterfaceVersionNumber_t;               /* Algo interface version nummbers @min:0 @max:4294967295 */ /* [Satisfies_rte sws 1188] */
typedef unsigned __int32 AlgoDataTimeStamp_t                         /* Algo data time-stamp type (32 bit variant) @min:0 @max:4294967295 */  /* [Satisfies_rte sws 1188] */;
typedef unsigned __int16 AlgoCycleCounter_t                          /* Algo cycle counter @min:0 @max:65535 */  /* [Satisfies_rte sws 1188] */;
typedef unsigned __int8 AlgoSignalState_t                            /* Algo signal state enumeration @min: 0 @max:2 @values: enum { AL_SIG_STATE_INVALID=2,AL_SIG_STATE_INIT=0,AL_SIG_STATE_OK=1,} */  /* [Satisfies_rte sws 1188] */;

typedef struct SignalHeader_t                                        /* [Satisfies_rte sws 1191] */
{
  AlgoDataTimeStamp_t uiTimeStamp;
  AlgoCycleCounter_t uiMeasurementCounter;
  AlgoCycleCounter_t uiCycleCounter;
  AlgoSignalState_t eSigStatus;
} SignalHeader_t;                                                    /* Common header for all structured data types */

typedef enum eAlgoSignalState_t {
  AL_SIG_STATE_INIT=0,
  AL_SIG_STATE_OK=1,
  AL_SIG_STATE_INVALID=2,
} eAlgoSignalState_t;


//
// ARS410 EMRT_t_ObjectList_MCAM version 1 based on
// Member:        Rte_Type.h
// Project:       /nfs/projekte1/PROJECTS/ARS400/06_Algorithm/01_Source_Code/common/rte/project.pj
// Revision:      1.3
// Description:   generated with AlgoTypesAUTOSAR4.ecuextract 1.18.1.12
//
namespace EMRT_t_ObjectList_MCAM_V1
{
  typedef unsigned __int8 EMRT_t_CamSensorState;                     /* Status of camera @min: 0 @max:3 @values: enum { EMRT_CAM_SEN_STATE_UNKNOWN=0,EMRT_CAM_SEN_STATE_NOT_OK=2,EMRT_CAM_SEN_STATE_BLOCKED=3,EMRT_CAM_SEN_STATE_OK=1,} */
  typedef unsigned __int8 EMRT_t_CamDetectionMode;                   /* Status of camera object detection @min: 0 @max:2 @values: enum { EMRT_CAM_DETECT_STATE_UNKNOWN=0,EMRT_CAM_DETECT_STATE_REDUCED=2,EMRT_CAM_DETECT_STATE_NORMAL=1,} */

  typedef unsigned __int8 EMRT_t_CamLaneAssoc;                       /* Associated Lane of object @min: 0 @max:5 @values: enum { EM_RT_CAM_ASSOC_LANE_EGO=1,EM_RT_CAM_ASSOC_LANE_NEXT_NEXT_LEFT=4,EM_RT_CAM_ASSOC_LANE_NOT_ASSINGED=0,EM_RT_CAM_ASSOC_LANE_NEXT_LEFT=2,EM_RT_CAM_ASSOC_LANE_NEXT_RIGHT=3,EM_RT_CAM_ASSOC_LANE_NEXT_NEXT_RIGHT=5,} */
  typedef unsigned __int8 EMRT_t_CamLaneMovement;                    /* @min: 0 @max:3 @values: enum { EM_RT_CAM_LANE_MOVEMENT_UNKNOWN=0,EM_RT_CAM_LANE_MOVEMENT_LEFT=1,EM_RT_CAM_LANE_MOVEMENT_NOT_USED=3,EM_RT_CAM_LANE_MOVEMENT_RIGHT=2,} */
  typedef unsigned __int8 EMRT_t_CamObjBrakeLight;                   /* Status of the brake light of the object. @min: 0 @max:3 @values: enum { EM_RT_CAM_BRAKE_LIGHT_OFF=2,EM_RT_CAM_BRAKE_LIGHT_ON=1,EM_RT_CAM_BRAKE_LIGHT_RESERVED=3,EM_RT_CAM_BRAKE_LIGHT_NOT_AVAILABLE=0,} */
  typedef unsigned __int8 EMRT_t_CamObjMotStat;                      /* This signal indicates wether the object is moving, stationary or oncoming, based on comparison of the longitudinal relative velocity with the host vehicle velocity. @min: 0 @max:8 @values: enum { EM_RT_CAM_DYN_PROP_PARKED=2,EM_RT_CAM_DYN_PROP_STOPPED_ONCOMING=6,EM_RT_CAM_DYN_PROP_UNKNOWN=4,EM_RT_CAM_DYN_PROP_MOVING_ONCOMING=8,EM_RT_CAM_DYN_PROP_STOPPED=3,EM_RT_CAM_DYN_PROP_STATIONARY=1,EM_RT_CAM_DYN_PROP_UNKNOWN_ONCOMING=7,EM_RT_CAM_DYN_PROP_NOT_DEFINED=0,EM_RT_CAM_DYN_PROP_MOVING=5,} */
  typedef unsigned __int8 EMRT_t_CamObjTurnInd;                      /* Status of the turn indicator light of the object. @min: 0 @max:4 @values: enum { EM_RT_CAM_TURN_IND_OFF=1,EM_RT_CAM_TURN_IND_BOTH=4,EM_RT_CAM_TURN_IND_NOT_AVAILABLE=0,EM_RT_CAM_TURN_IND_LEFT=2,EM_RT_CAM_TURN_IND_RIGHT=3,} */

  typedef unsigned __int8 e_CIPV_t;                                  /* Closest in path vehicle @min: 0 @max:1 @values: enum { EM_RT_CAM_CLOSEST_IN_PATH_VEHICLE=1,EM_RT_CAM_NOT_CLOSEST_IN_PATH_VEHICLE=0,} */
  typedef unsigned __int8 e_FrontCollisionValid_t;                   /* front collision valid @min: 0 @max:1 @values: enum { EM_RT_CAM_FRONT_COLLISION_INVALID=0,EM_RT_CAM_FRONT_COLLISION_VALID=1,} */
  typedef unsigned __int8 e_PedOnPavement_t;                         /* pedestrian on pavement @min: 0 @max:1 @values: enum { EM_RT_CAM_PED_OUT_OF_PAVEMENT=1,EM_RT_CAM_PED_ON_PAVEMENT=0,} */

  typedef enum eEMRT_t_CamSensorState{
    EMRT_CAM_SEN_STATE_UNKNOWN=0,
    EMRT_CAM_SEN_STATE_NOT_OK=2,
    EMRT_CAM_SEN_STATE_BLOCKED=3,
    EMRT_CAM_SEN_STATE_OK=1,
  } eEMRT_t_CamSensorState;
  typedef enum eEMRT_t_CamDetectionMode{
    EMRT_CAM_DETECT_STATE_UNKNOWN=0,
    EMRT_CAM_DETECT_STATE_REDUCED=2,
    EMRT_CAM_DETECT_STATE_NORMAL=1,
  } eEMRT_t_CamDetectionMode;
  typedef enum eEMRT_t_CamLaneAssoc{
    EM_RT_CAM_ASSOC_LANE_EGO=1,
    EM_RT_CAM_ASSOC_LANE_NEXT_NEXT_LEFT=4,
    EM_RT_CAM_ASSOC_LANE_NOT_ASSINGED=0,
    EM_RT_CAM_ASSOC_LANE_NEXT_LEFT=2,
    EM_RT_CAM_ASSOC_LANE_NEXT_RIGHT=3,
    EM_RT_CAM_ASSOC_LANE_NEXT_NEXT_RIGHT=5,
  } eEMRT_t_CamLaneAssoc;
  typedef enum eEMRT_t_CamLaneMovement{
    EM_RT_CAM_LANE_MOVEMENT_UNKNOWN=0,
    EM_RT_CAM_LANE_MOVEMENT_LEFT=1,
    EM_RT_CAM_LANE_MOVEMENT_NOT_USED=3,
    EM_RT_CAM_LANE_MOVEMENT_RIGHT=2,
  } eEMRT_t_CamLaneMovement;
  typedef enum eEMRT_t_CamObjBrakeLight{
    EM_RT_CAM_BRAKE_LIGHT_OFF=2,
    EM_RT_CAM_BRAKE_LIGHT_ON=1,
    EM_RT_CAM_BRAKE_LIGHT_RESERVED=3,
    EM_RT_CAM_BRAKE_LIGHT_NOT_AVAILABLE=0,
  } eEMRT_t_CamObjBrakeLight;
  typedef enum eEMRT_t_CamObjClass{
    EM_RT_CAM_CLASS_PEDESTRIAN=5,
    EM_RT_CAM_CLASS_BICYCLE=4,
    EM_RT_CAM_CLASS_NO_DETECTION=0,
    EM_RT_CAM_CLASS_CAR=2,
    EM_RT_CAM_CLASS_CAR_OR_TRUCK=6,
    EM_RT_CAM_CLASS_MOTORBIKE=3,
    EM_RT_CAM_CLASS_TRUCK=1,
    EM_RT_CAM_CLASS_NOT_CONF_RADAR_INFORM=7,
  } eEMRT_t_CamObjClass;
  typedef enum eEMRT_t_CamObjMotStat{
    EM_RT_CAM_DYN_PROP_PARKED=2,
    EM_RT_CAM_DYN_PROP_STOPPED_ONCOMING=6,
    EM_RT_CAM_DYN_PROP_UNKNOWN=4,
    EM_RT_CAM_DYN_PROP_MOVING_ONCOMING=8,
    EM_RT_CAM_DYN_PROP_STOPPED=3,
    EM_RT_CAM_DYN_PROP_STATIONARY=1,
    EM_RT_CAM_DYN_PROP_UNKNOWN_ONCOMING=7,
    EM_RT_CAM_DYN_PROP_NOT_DEFINED=0,
    EM_RT_CAM_DYN_PROP_MOVING=5,
  } eEMRT_t_CamObjMotStat;
  typedef enum eEMRT_t_CamObjTurnInd{
    EM_RT_CAM_TURN_IND_OFF=1,
    EM_RT_CAM_TURN_IND_BOTH=4,
    EM_RT_CAM_TURN_IND_NOT_AVAILABLE=0,
    EM_RT_CAM_TURN_IND_LEFT=2,
    EM_RT_CAM_TURN_IND_RIGHT=3,
  } eEMRT_t_CamObjTurnInd;
  typedef enum ee_CIPV_t{
    EM_RT_CAM_CLOSEST_IN_PATH_VEHICLE=1,
    EM_RT_CAM_NOT_CLOSEST_IN_PATH_VEHICLE=0,
  } ee_CIPV_t;
  typedef enum ee_FrontCollisionValid_t{
    EM_RT_CAM_FRONT_COLLISION_INVALID=0,
    EM_RT_CAM_FRONT_COLLISION_VALID=1,
  } ee_FrontCollisionValid_t;
  typedef enum ee_PedOnPavement_t{
    EM_RT_CAM_PED_OUT_OF_PAVEMENT=1,
    EM_RT_CAM_PED_ON_PAVEMENT=0,
  } ee_PedOnPavement_t;

  typedef struct
  {
    float f_LongDist;
    float f_LongDistStd;
    float f_LateralDist;
    float f_LongVelocityRel;
    float f_LongVelocityRelStd;
    float f_LateralVelocityRel;
    float f_AccelAbs;
    float f_Width;
    float f_Angle;
    float f_AngleRate;
    float f_TTC;
    unsigned __int8 ui_Quality;
    EMRT_t_CamObjMotStat e_MotionStatus;
    EMRT_t_CamLaneMovement e_LaneMovement;
    EMRT_t_CamLaneAssoc e_LaneAssignment;
    unsigned __int8 ui_ObjID;
    EMRT_t_CamObjTurnInd e_TurnIndicator;
    EMRT_t_CamObjBrakeLight e_BrakeLight;
    e_PedOnPavement_t e_PedOnPavement;
    e_FrontCollisionValid_t e_FrontCollisionValid;
    e_CIPV_t e_CIPV;
    //EMRT_t_CamObjClass e_CamClass;
    //unsigned __int8 ui_LaneOccupancyEgo;
    //unsigned __int8 ui_LaneOccupancyLeft;
    //unsigned __int8 ui_LaneOccupancyRight;
    unsigned __int8 ui_Reserved1;
    unsigned __int8 ui_Reserved2;
  } EMRT_t_CamObjectInfo;

  typedef struct
  {
    float f_CamObjListDelay;
    EMRT_t_CamSensorState e_CamSensorState;
    EMRT_t_CamDetectionMode e_CamDetectionMode;
    unsigned char ui_CamNumObjects;
    unsigned char b_ValidCRC;
    unsigned char ui_ImageCounter;
    unsigned long ui_CamVersionNumber;
    unsigned char ui_Reserved1;
    unsigned char ui_Reserved2;
    unsigned char ui_Reserved3;
  } EM_t_RTCamObjectListHeader;

  typedef EMRT_t_CamObjectInfo EMRT_t_CamObjArray[EMRT_N_MCAM_OBJECTS];

  typedef struct EM_t_RTObjectList_CAM
  {
    AlgoInterfaceVersionNumber_t u_VersionNumber;
    SignalHeader_t sSigHeader;
    EM_t_RTCamObjectListHeader objectListHeader;
    EMRT_t_CamObjArray a_CamObject;
  } EM_t_RTObjectList_CAM;

} // end of namespace EMRT_t_ObjectList_MCAM_V1

//
// ARS4T0 EMRT_t_ObjectList_MCAM version 2 (taken from rte_type.h revision 1.3)
//
namespace EMRT_t_ObjectList_MCAM_V2
{
  typedef unsigned __int8 EMRT_t_CamObjMotStat;                      /* This signal indicates wether the object is moving, stationary or oncoming, based on comparison of the longitudinal relative velocity with the host vehicle velocity. @min: 0 @max:8 @values: enum { EM_RT_CAM_DYN_PROP_PARKED=2,EM_RT_CAM_DYN_PROP_STOPPED_ONCOMING=6,EM_RT_CAM_DYN_PROP_UNKNOWN=4,EM_RT_CAM_DYN_PROP_MOVING_ONCOMING=8,EM_RT_CAM_DYN_PROP_STOPPED=3,EM_RT_CAM_DYN_PROP_STATIONARY=1,EM_RT_CAM_DYN_PROP_UNKNOWN_ONCOMING=7,EM_RT_CAM_DYN_PROP_NOT_DEFINED=0,EM_RT_CAM_DYN_PROP_MOVING=5,} */
  typedef unsigned __int8 EMRT_t_CamObjTurnInd;                      /* Status of the turn indicator light of the object. @min: 0 @max:4 @values: enum { EM_RT_CAM_TURN_IND_OFF=1,EM_RT_CAM_TURN_IND_BOTH=4,EM_RT_CAM_TURN_IND_NOT_AVAILABLE=0,EM_RT_CAM_TURN_IND_LEFT=2,EM_RT_CAM_TURN_IND_RIGHT=3,} */
  typedef unsigned __int8 EMRT_t_CamLaneAssoc;                       /* Associated Lane of object @min: 0 @max:5 @values: enum { EM_RT_CAM_ASSOC_LANE_EGO=1,EM_RT_CAM_ASSOC_LANE_NEXT_NEXT_LEFT=4,EM_RT_CAM_ASSOC_LANE_NOT_ASSINGED=0,EM_RT_CAM_ASSOC_LANE_NEXT_LEFT=2,EM_RT_CAM_ASSOC_LANE_NEXT_RIGHT=3,EM_RT_CAM_ASSOC_LANE_NEXT_NEXT_RIGHT=5,} */
  typedef unsigned __int8 EMRT_t_CamLaneMovement;                    /* lane movement @min: 0 @max:3 @values: enum { EM_RT_CAM_LANE_MOVEMENT_UNKNOWN=0,EM_RT_CAM_LANE_MOVEMENT_LEFT=1,EM_RT_CAM_LANE_MOVEMENT_NOT_USED=3,EM_RT_CAM_LANE_MOVEMENT_RIGHT=2,} */
  typedef unsigned __int8 EMRT_t_CamObjBrakeLight;                   /* Status of the brake light of the object. @min: 0 @max:3 @values: enum { EM_RT_CAM_BRAKE_LIGHT_OFF=2,EM_RT_CAM_BRAKE_LIGHT_ON=1,EM_RT_CAM_BRAKE_LIGHT_RESERVED=3,EM_RT_CAM_BRAKE_LIGHT_NOT_AVAILABLE=0,} */
  typedef unsigned __int8 e_PedOnPavement_t;                         /* pedestrian on pavement @min: 0 @max:1 @values: enum { EM_RT_CAM_PED_OUT_OF_PAVEMENT=1,EM_RT_CAM_PED_ON_PAVEMENT=0,} */
  typedef unsigned __int8 e_FrontCollisionValid_t;                   /* front collision valid @min: 0 @max:1 @values: enum { EM_RT_CAM_FRONT_COLLISION_INVALID=0,EM_RT_CAM_FRONT_COLLISION_VALID=1,} */
  typedef unsigned __int8 e_CIPV_t;                                  /* Closest in path vehicle @min: 0 @max:1 @values: enum { EM_RT_CAM_CLOSEST_IN_PATH_VEHICLE=1,EM_RT_CAM_NOT_CLOSEST_IN_PATH_VEHICLE=0,} */
  typedef unsigned __int8 EMRT_t_CamObjClass;                        /* Camera classification @min: 0 @max:7 @values: enum { EM_RT_CAM_CLASS_PEDESTRIAN=5,EM_RT_CAM_CLASS_BICYCLE=4,EM_RT_CAM_CLASS_NO_DETECTION=0,EM_RT_CAM_CLASS_CAR=2,EM_RT_CAM_CLASS_CAR_OR_TRUCK=6,EM_RT_CAM_CLASS_MOTORBIKE=3,EM_RT_CAM_CLASS_TRUCK=1,EM_RT_CAM_CLASS_NOT_CONF_RADAR_INFORM=7,} */

  typedef struct
  {
    float f_LongDist;
    float f_LongDistStd;
    float f_LateralDist;
    float f_LongVelocityRel;
    float f_LongVelocityRelStd;
    float f_LateralVelocityRel;
    float f_AccelAbs;
    float f_Width;
    float f_Angle;
    float f_AngleRate;
    float f_TTC;
    unsigned __int8 ui_Quality;
    EMRT_t_CamObjMotStat e_MotionStatus;
    EMRT_t_CamLaneMovement e_LaneMovement;
    EMRT_t_CamLaneAssoc e_LaneAssignment;
    unsigned __int8 ui_ObjID;
    EMRT_t_CamObjTurnInd e_TurnIndicator;
    EMRT_t_CamObjBrakeLight e_BrakeLight;
    e_PedOnPavement_t e_PedOnPavement;
    e_FrontCollisionValid_t e_FrontCollisionValid;
    e_CIPV_t e_CIPV;
    EMRT_t_CamObjClass e_CamClass;
    unsigned __int8 ui_LaneOccupancyEgo;
    unsigned __int8 ui_LaneOccupancyLeft;
    unsigned __int8 ui_LaneOccupancyRight;
    unsigned __int8 ui_Reserved1;
    unsigned __int8 ui_Reserved2;
  } EMRT_t_CamObjectInfo;

  typedef EMRT_t_CamObjectInfo EMRT_t_CamObjArray[EMRT_N_MCAM_OBJECTS];

  typedef struct
  {
    AlgoInterfaceVersionNumber_t u_VersionNumber;
    SignalHeader_t sSigHeader;
    EMRT_t_ObjectList_MCAM_V1::EM_t_RTCamObjectListHeader objectListHeader;
    EMRT_t_CamObjArray a_CamObject;
  } EM_t_RTObjectList_CAM;                                           /* @vaddr:0x20198000 @vaddr_defs: EM_MEAS_ID_RT_OBJECT_LIST_CAM @cycleid:EM_ENV @vname:EMRTObjDataCam */
} // end of namespace EMRT_t_ObjectList_MCAM_V2

//
// ARS4T0 EMRT_t_ObjectList_MCAM version 3 (taken from rte_type.h revision 1.22)
//
namespace EMRT_t_ObjectList_MCAM_V3
{
  typedef unsigned __int8 EMRT_t_CamSensorState;                     /* Status of camera @min: 0 @max:3 @values: enum { EMRT_CAM_SEN_STATE_UNKNOWN=0,EMRT_CAM_SEN_STATE_NOT_OK=2,EMRT_CAM_SEN_STATE_BLOCKED=3,EMRT_CAM_SEN_STATE_OK=1,} */
  typedef unsigned __int8 EMRT_t_CamDetectionMode;                   /* Status of camera object detection @min: 0 @max:2 @values: enum { EMRT_CAM_DETECT_STATE_UNKNOWN=0,EMRT_CAM_DETECT_STATE_REDUCED=2,EMRT_CAM_DETECT_STATE_NORMAL=1,} */
  typedef unsigned __int8 EMRT_t_CamObjMotStat;                      /* This signal indicates wether the object is moving, stationary or oncoming, based on comparison of the longitudinal relative velocity with the host vehicle velocity. @min: 0 @max:8 @values: enum { EM_RT_CAM_DYN_PROP_PARKED=2,EM_RT_CAM_DYN_PROP_STOPPED_ONCOMING=6,EM_RT_CAM_DYN_PROP_UNKNOWN=4,EM_RT_CAM_DYN_PROP_MOVING_ONCOMING=8,EM_RT_CAM_DYN_PROP_STOPPED=3,EM_RT_CAM_DYN_PROP_STATIONARY=1,EM_RT_CAM_DYN_PROP_UNKNOWN_ONCOMING=7,EM_RT_CAM_DYN_PROP_NOT_DEFINED=0,EM_RT_CAM_DYN_PROP_MOVING=5,} */
  typedef unsigned __int8 EMRT_t_CamObjTurnInd;                      /* Status of the turn indicator light of the object. @min: 0 @max:4 @values: enum { EM_RT_CAM_TURN_IND_OFF=1,EM_RT_CAM_TURN_IND_BOTH=4,EM_RT_CAM_TURN_IND_NOT_AVAILABLE=0,EM_RT_CAM_TURN_IND_LEFT=2,EM_RT_CAM_TURN_IND_RIGHT=3,} */
  typedef unsigned __int8 EMRT_t_CamPedOnPavem;                      /* pedestrian on pavement @min: 0 @max:1 @values: enum { EM_RT_CAM_PED_OUT_OF_PAVEMENT=1,EM_RT_CAM_PED_ON_PAVEMENT=0,} */
  typedef unsigned __int8 EMRT_t_CamLaneAssoc;                       /* Associated Lane of object @min: 0 @max:5 @values: enum { EM_RT_CAM_ASSOC_LANE_EGO=1,EM_RT_CAM_ASSOC_LANE_NEXT_NEXT_LEFT=4,EM_RT_CAM_ASSOC_LANE_NOT_ASSINGED=0,EM_RT_CAM_ASSOC_LANE_NEXT_LEFT=2,EM_RT_CAM_ASSOC_LANE_NEXT_RIGHT=3,EM_RT_CAM_ASSOC_LANE_NEXT_NEXT_RIGHT=5,} */
  typedef unsigned __int8 EMRT_t_CamLaneMovement;                    /* lane movement @min: 0 @max:3 @values: enum { EM_RT_CAM_LANE_MOVEMENT_UNKNOWN=0,EM_RT_CAM_LANE_MOVEMENT_LEFT=1,EM_RT_CAM_LANE_MOVEMENT_NOT_USED=3,EM_RT_CAM_LANE_MOVEMENT_RIGHT=2,} */
  typedef unsigned __int8 EMRT_t_CamObjBrakeLight;                   /* Status of the brake light of the object. @min: 0 @max:3 @values: enum { EM_RT_CAM_BRAKE_LIGHT_OFF=2,EM_RT_CAM_BRAKE_LIGHT_ON=1,EM_RT_CAM_BRAKE_LIGHT_RESERVED=3,EM_RT_CAM_BRAKE_LIGHT_NOT_AVAILABLE=0,} */
  typedef unsigned __int8 EMRT_t_CamObjClass;                        /* Camera classification @min: 0 @max:7 @values: enum { EM_RT_CAM_CLASS_PEDESTRIAN=5,EM_RT_CAM_CLASS_BICYCLE=4,EM_RT_CAM_CLASS_NO_DETECTION=0,EM_RT_CAM_CLASS_CAR=2,EM_RT_CAM_CLASS_CAR_OR_TRUCK=6,EM_RT_CAM_CLASS_MOTORBIKE=3,EM_RT_CAM_CLASS_TRUCK=1,EM_RT_CAM_CLASS_NOT_CONF_RADAR_INFORM=7,} */
  typedef unsigned __int8 EMRT_t_CIPV;                               /* Closest in path vehicle @min: 0 @max:1 @values: enum { EM_RT_CAM_CLOSEST_IN_PATH_VEHICLE=1,EM_RT_CAM_NOT_CLOSEST_IN_PATH_VEHICLE=0,} */
  typedef unsigned __int8 EMRT_t_CyclOnPavem;                        /* Cyclist on pavement @min: 0 @max:1 @values: enum { EM_RT_CAM_CYCL_ON_PAVEMENT=0,EM_RT_CAM_CYCL_OUT_OF_PAVEMENT=1,} */
  typedef unsigned __int8 EMRT_t_FCV;                                /* front collision valid @min: 0 @max:1 @values: enum { EM_RT_CAM_FRONT_COLLISION_INVALID=0,EM_RT_CAM_FRONT_COLLISION_VALID=1,} */
  typedef unsigned __int8 EMRT_t_FreeSpaceTgtPos;                    /* free space target position @min: 0 @max:3 @values: enum { EM_RT_CAM_NO_STATEMENT=2,EM_RT_CAM_NO_SNA=3,EM_RT_CAM_FST_NO_PENETRATION=0,EM_RT_CAM_FST_PENETRATION=1,} */
  typedef unsigned __int8 EMRT_t_RefPt;                              /* reference point @min: 0 @max:1 @values: enum { EM_RT_CAM_REFPT_SIDE=1,EM_RT_CAM_REFPT_REAR=0,} */
  typedef unsigned __int8 EMRT_t_TurnLeft;                           /* object turn left indicated @min: 0 @max:1 @values: enum { EM_RT_CAM_TL_NO_TURN_LEFT=0,EM_RT_CAM_TL_TURN_LEFT=1,} */
  typedef unsigned __int8 EMRT_t_CutInOut;                           /* cut in / out info @min: 0 @max:7 @values: enum { EM_RT_CAM_CUT_IO_HOST_CUTOUT_R=3,EM_RT_CAM_CUT_IO_UNKNOWN=0,EM_RT_CAM_CUT_IO_NEXT_CUTOUT_R=6,EM_RT_CAM_CUT_IO_HOST_CUTIN=1,EM_RT_CAM_CUT_IO_NEXT_CUTIN=4,EM_RT_CAM_CUT_IO_RESV=7,EM_RT_CAM_CUT_IO_NEXT_CUTOUT_L=5,EM_RT_CAM_CUT_IO_HOST_CUTOUT_L=2,} */

  typedef struct
  {
    float f_LongDist;
    float f_LongDistStd;
    float f_LateralDist;
    float f_LongVelocityRel;
    float f_LongVelocityRelStd;
    float f_LateralVelocityRel;
    float f_AccelAbs;
    float f_Width;
    float f_Angle;
    float f_AngleRate;
    float f_TTC;
    float f_LatVelStd;
    float f_PredImpactPos;
    float f_LateralDistStd;
    unsigned __int8 ui_Quality;
    EMRT_t_CamObjMotStat e_MotionStatus;
    EMRT_t_CamLaneMovement e_LaneMovement;
    EMRT_t_CamLaneAssoc e_LaneAssignment;
    unsigned __int8 ui_ObjID;
    EMRT_t_CamObjTurnInd e_TurnIndicator;
    EMRT_t_CamObjBrakeLight e_BrakeLight;
    EMRT_t_CamPedOnPavem e_PedOnPavement;
    EMRT_t_FCV e_FrontCollisionValid;
    EMRT_t_CIPV e_CIPV;
    EMRT_t_CamObjClass e_CamClass;
    unsigned __int8 ui_LaneOccupancyEgo;
    unsigned __int8 ui_LaneOccupancyLeft;
    unsigned __int8 ui_LaneOccupancyRight;
    EMRT_t_FreeSpaceTgtPos e_FreeSpaceTgtPos;
    EMRT_t_TurnLeft e_TurnLeft;
    EMRT_t_CutInOut e_CutInOut;
    EMRT_t_RefPt e_RefPt;
    unsigned __int8 ui_ObjLifeTime;
    unsigned __int8 ui_SceneScoreInfo;
    unsigned __int8 ui_StuctureScoreInfo;
    EMRT_t_CyclOnPavem e_CyclOnPavement;
    unsigned __int8 ui_Reserved1;
    unsigned __int8 ui_Reserved2;
  } EMRT_t_CamObjectInfo;

  typedef EMRT_t_CamObjectInfo EMRT_t_CamObjArray[EMRT_N_MCAM_OBJECTS];

  typedef struct
  {
    AlgoInterfaceVersionNumber_t u_VersionNumber;
    SignalHeader_t sSigHeader;
    EMRT_t_ObjectList_MCAM_V1::EM_t_RTCamObjectListHeader objectListHeader;
    EMRT_t_CamObjArray a_CamObject;
  } EM_t_RTObjectList_CAM;                                           /* @vaddr:0x20198000 @vaddr_defs: EM_MEAS_ID_RT_OBJECT_LIST_CAM @cycleid:EM_ENV @vname:EMRTObjDataCam */
} // end of namespace EMRT_t_ObjectList_MCAM_V3


class CConvEmObjectListMcamRt : public CSimConverterBase
{
  // the list of dependency names used inside by the converter
  /*
  static const char *DEP_NAMES[];
  */

  // here we define the index of each dependency for quick acces
  // the order here should match with the order from DEP_NAMES array
  enum eDepIdx
  {
    // add new dependencies here
    DEP_COUNT
  };

  EMRT_t_ObjectList_MCAM_V1::EM_t_RTObjectList_CAM m_BufV1;
  EMRT_t_ObjectList_MCAM_V2::EM_t_RTObjectList_CAM m_BufV2;
  EMRT_t_ObjectList_MCAM_V3::EM_t_RTObjectList_CAM m_BufV3;

  static void InitSigHeader(SignalHeader_t & SigHeader)
  {
    SigHeader.uiTimeStamp           = 0;
    SigHeader.uiMeasurementCounter  = 0;
    SigHeader.uiCycleCounter        = 0;
    SigHeader.eSigStatus            = AL_SIG_STATE_INIT;
  };
  static void InitHeader(EMRT_t_ObjectList_MCAM_V1::EM_t_RTCamObjectListHeader & ObjHeader)
  {
    memset(&ObjHeader, 0, sizeof(EMRT_t_ObjectList_MCAM_V1::EM_t_RTCamObjectListHeader));
    ObjHeader.b_ValidCRC          = true;
    ObjHeader.e_CamSensorState    = EMRT_t_ObjectList_MCAM_V1::EMRT_CAM_SEN_STATE_UNKNOWN;
    ObjHeader.e_CamDetectionMode  = EMRT_t_ObjectList_MCAM_V1::EMRT_CAM_DETECT_STATE_UNKNOWN;
    ObjHeader.ui_CamNumObjects    = 0u;
    ObjHeader.f_CamObjListDelay   = 0.0f;
    ObjHeader.ui_ImageCounter     = 0u;
    ObjHeader.ui_CamVersionNumber = 0u;
  };
  static void InitObject(EMRT_t_ObjectList_MCAM_V1::EMRT_t_CamObjectInfo & CamObject)
  {
    memset(&CamObject, 0, sizeof(EMRT_t_ObjectList_MCAM_V1::EMRT_t_CamObjectInfo));
    CamObject.f_LongDist = 0.0f;
    CamObject.f_LongDistStd = 0.0f;
    CamObject.f_LateralDist = 0.0f;
    CamObject.f_LongVelocityRel = 0.0f;
    CamObject.f_LongVelocityRelStd = 0.0f;
    CamObject.f_LateralVelocityRel = 0.0f;
    CamObject.f_AccelAbs = 0.0f;
    CamObject.f_Width = 0.0f;
    CamObject.f_Angle = 0.0f;
    CamObject.f_AngleRate = 0.0f;
    CamObject.f_TTC = 0.0f;
    CamObject.ui_Quality = 0u;
    CamObject.e_MotionStatus = EMRT_t_ObjectList_MCAM_V1::EM_RT_CAM_DYN_PROP_NOT_DEFINED;
    CamObject.e_LaneMovement = EMRT_t_ObjectList_MCAM_V1::EM_RT_CAM_LANE_MOVEMENT_UNKNOWN;
    CamObject.e_LaneAssignment = EMRT_t_ObjectList_MCAM_V1::EM_RT_CAM_ASSOC_LANE_NOT_ASSINGED;
    CamObject.ui_ObjID = 255;
    CamObject.e_TurnIndicator = EMRT_t_ObjectList_MCAM_V1::EM_RT_CAM_TURN_IND_NOT_AVAILABLE;
    CamObject.e_BrakeLight = EMRT_t_ObjectList_MCAM_V1::EM_RT_CAM_BRAKE_LIGHT_NOT_AVAILABLE;
    CamObject.e_PedOnPavement = EMRT_t_ObjectList_MCAM_V1::EM_RT_CAM_PED_OUT_OF_PAVEMENT;
    CamObject.e_FrontCollisionValid = EMRT_t_ObjectList_MCAM_V1::EM_RT_CAM_FRONT_COLLISION_INVALID;
    CamObject.e_CIPV = EMRT_t_ObjectList_MCAM_V1::EM_RT_CAM_NOT_CLOSEST_IN_PATH_VEHICLE;
    //CamObject.e_CamClass = EMRT_t_ObjectList_MCAM_V1::EM_RT_CAM_CLASS_NO_DETECTION;
    //CamObject.ui_LaneOccupancyEgo = 0u;
    //CamObject.ui_LaneOccupancyLeft = 0u;
    //CamObject.ui_LaneOccupancyRight = 0u;
    CamObject.ui_Reserved1 = 0u;
    CamObject.ui_Reserved2 = 0u;
  };
  static void InitObject(EMRT_t_ObjectList_MCAM_V2::EMRT_t_CamObjectInfo & CamObject)
  {
    memset(&CamObject, 0, sizeof(EMRT_t_ObjectList_MCAM_V2::EMRT_t_CamObjectInfo));
    CamObject.f_LongDist = 0.0f;
    CamObject.f_LongDistStd = 0.0f;
    CamObject.f_LateralDist = 0.0f;
    CamObject.f_LongVelocityRel = 0.0f;
    CamObject.f_LongVelocityRelStd = 0.0f;
    CamObject.f_LateralVelocityRel = 0.0f;
    CamObject.f_AccelAbs = 0.0f;
    CamObject.f_Width = 0.0f;
    CamObject.f_Angle = 0.0f;
    CamObject.f_AngleRate = 0.0f;
    CamObject.f_TTC = 0.0f;
    CamObject.ui_Quality = 0u;
    CamObject.e_MotionStatus = EMRT_t_ObjectList_MCAM_V1::EM_RT_CAM_DYN_PROP_NOT_DEFINED;
    CamObject.e_LaneMovement = EMRT_t_ObjectList_MCAM_V1::EM_RT_CAM_LANE_MOVEMENT_UNKNOWN;
    CamObject.e_LaneAssignment = EMRT_t_ObjectList_MCAM_V1::EM_RT_CAM_ASSOC_LANE_NOT_ASSINGED;
    CamObject.ui_ObjID = 255;
    CamObject.e_TurnIndicator = EMRT_t_ObjectList_MCAM_V1::EM_RT_CAM_TURN_IND_NOT_AVAILABLE;
    CamObject.e_BrakeLight = EMRT_t_ObjectList_MCAM_V1::EM_RT_CAM_BRAKE_LIGHT_NOT_AVAILABLE;
    CamObject.e_PedOnPavement = EMRT_t_ObjectList_MCAM_V1::EM_RT_CAM_PED_OUT_OF_PAVEMENT;
    CamObject.e_FrontCollisionValid = EMRT_t_ObjectList_MCAM_V1::EM_RT_CAM_FRONT_COLLISION_INVALID;
    CamObject.e_CIPV = EMRT_t_ObjectList_MCAM_V1::EM_RT_CAM_NOT_CLOSEST_IN_PATH_VEHICLE;
    CamObject.e_CamClass = EMRT_t_ObjectList_MCAM_V1::EM_RT_CAM_CLASS_NO_DETECTION;
    CamObject.ui_LaneOccupancyEgo = 0u;
    CamObject.ui_LaneOccupancyLeft = 0u;
    CamObject.ui_LaneOccupancyRight = 0u;
    CamObject.ui_Reserved1 = 0u;
    CamObject.ui_Reserved2 = 0u;
  };
  static void InitObject(EMRT_t_ObjectList_MCAM_V3::EMRT_t_CamObjectInfo & CamObject)
  {
    memset(&CamObject, 0, sizeof(EMRT_t_ObjectList_MCAM_V3::EMRT_t_CamObjectInfo));
    CamObject.f_LongDist = 0.0f;
    CamObject.f_LongDistStd = 0.0f;
    CamObject.f_LateralDist = 0.0f;
    CamObject.f_LongVelocityRel = 0.0f;
    CamObject.f_LongVelocityRelStd = 0.0f;
    CamObject.f_LateralVelocityRel = 0.0f;
    CamObject.f_AccelAbs = 0.0f;
    CamObject.f_Width = 0.0f;
    CamObject.f_Angle = 0.0f;
    CamObject.f_AngleRate = 0.0f;
    CamObject.f_TTC = 0.0f;
    CamObject.ui_Quality = 0u;
    CamObject.e_MotionStatus = EMRT_t_ObjectList_MCAM_V1::EM_RT_CAM_DYN_PROP_NOT_DEFINED;
    CamObject.e_LaneMovement = EMRT_t_ObjectList_MCAM_V1::EM_RT_CAM_LANE_MOVEMENT_UNKNOWN;
    CamObject.e_LaneAssignment = EMRT_t_ObjectList_MCAM_V1::EM_RT_CAM_ASSOC_LANE_NOT_ASSINGED;
    CamObject.ui_ObjID = 255;
    CamObject.e_TurnIndicator = EMRT_t_ObjectList_MCAM_V1::EM_RT_CAM_TURN_IND_NOT_AVAILABLE;
    CamObject.e_BrakeLight = EMRT_t_ObjectList_MCAM_V1::EM_RT_CAM_BRAKE_LIGHT_NOT_AVAILABLE;
    CamObject.e_PedOnPavement = EMRT_t_ObjectList_MCAM_V1::EM_RT_CAM_PED_OUT_OF_PAVEMENT;
    CamObject.e_FrontCollisionValid = EMRT_t_ObjectList_MCAM_V1::EM_RT_CAM_FRONT_COLLISION_INVALID;
    CamObject.e_CIPV = EMRT_t_ObjectList_MCAM_V1::EM_RT_CAM_NOT_CLOSEST_IN_PATH_VEHICLE;
    CamObject.e_CamClass = EMRT_t_ObjectList_MCAM_V1::EM_RT_CAM_CLASS_NO_DETECTION;
    CamObject.ui_LaneOccupancyEgo = 0u;
    CamObject.ui_LaneOccupancyLeft = 0u;
    CamObject.ui_LaneOccupancyRight = 0u;
    CamObject.ui_Reserved1 = 0u;
    CamObject.ui_Reserved2 = 0u;
  };

  //static void InitObject(EMRT_t_ObjectList_MCAM_V1::EMT0_t_ObjectRecognitionInfo & CamObject)
  //{
  //  CamObject.ui_Reserved3              = 0;
  //};
  static void Init_EMRT_t_ObjectList(EMRT_t_ObjectList_MCAM_V1::EM_t_RTObjectList_CAM & ObjList)
  {
    ObjList.u_VersionNumber = 1u;
    InitSigHeader(ObjList.sSigHeader);
    InitHeader(ObjList.objectListHeader);
    for (unsigned int i=0; i<EMRT_N_MCAM_OBJECTS; i++)
    {
      InitObject(ObjList.a_CamObject[i]);
    }
  };
  static void Init_EMRT_t_ObjectList(EMRT_t_ObjectList_MCAM_V2::EM_t_RTObjectList_CAM & ObjList)
  {
    ObjList.u_VersionNumber = 2u;
    InitSigHeader(ObjList.sSigHeader);
    InitHeader(ObjList.objectListHeader);
    for (unsigned int i=0; i<EMRT_N_MCAM_OBJECTS; i++)
    {
      InitObject(ObjList.a_CamObject[i]);
    }
  };
  static void Init_EMRT_t_ObjectList(EMRT_t_ObjectList_MCAM_V3::EM_t_RTObjectList_CAM & ObjList)
  {
    ObjList.u_VersionNumber = 3u;
    InitSigHeader(ObjList.sSigHeader);
    InitHeader(ObjList.objectListHeader);
    for (unsigned int i=0; i<EMRT_N_MCAM_OBJECTS; i++)
    {
      InitObject(ObjList.a_CamObject[i]);
    }
  };
  static void ConvertObject(EMRT_t_ObjectList_MCAM_V1::EMRT_t_CamObjectInfo & Dest, const EMRT_t_ObjectList_MCAM_V2::EMRT_t_CamObjectInfo & Src)
  {
    Dest.f_LongDist            = Src.f_LongDist;
    Dest.f_LongDistStd         = Src.f_LongDistStd;
    Dest.f_LateralDist         = Src.f_LateralDist;
    Dest.f_LongVelocityRel     = Src.f_LongVelocityRel;
    Dest.f_LongVelocityRelStd  = Src.f_LongVelocityRelStd;
    Dest.f_LateralVelocityRel  = Src.f_LateralVelocityRel;
    Dest.f_AccelAbs            = Src.f_AccelAbs;
    Dest.f_Width               = Src.f_Width;
    Dest.f_Angle               = Src.f_Angle;
    Dest.f_AngleRate           = Src.f_AngleRate;
    Dest.f_TTC                 = Src.f_TTC;
    Dest.ui_Quality            = Src.ui_Quality;
    Dest.e_MotionStatus        = Src.e_MotionStatus;
    Dest.e_LaneMovement        = Src.e_LaneMovement;
    Dest.e_LaneAssignment      = Src.e_LaneAssignment;
    Dest.ui_ObjID              = Src.ui_ObjID;
    Dest.e_TurnIndicator       = Src.e_TurnIndicator;
    Dest.e_BrakeLight          = Src.e_BrakeLight;
    Dest.e_PedOnPavement       = Src.e_PedOnPavement;
    Dest.e_FrontCollisionValid = Src.e_FrontCollisionValid;
    Dest.e_CIPV                = Src.e_CIPV;
    Dest.ui_Reserved1          = Src.ui_Reserved1;
    Dest.ui_Reserved2          = Src.ui_Reserved2;
  };
  static void ConvertObject(EMRT_t_ObjectList_MCAM_V1::EMRT_t_CamObjectInfo & Dest, const EMRT_t_ObjectList_MCAM_V3::EMRT_t_CamObjectInfo & Src)
  {
    Dest.f_LongDist            = Src.f_LongDist;
    Dest.f_LongDistStd         = Src.f_LongDistStd;
    Dest.f_LateralDist         = Src.f_LateralDist;
    Dest.f_LongVelocityRel     = Src.f_LongVelocityRel;
    Dest.f_LongVelocityRelStd  = Src.f_LongVelocityRelStd;
    Dest.f_LateralVelocityRel  = Src.f_LateralVelocityRel;
    Dest.f_AccelAbs            = Src.f_AccelAbs;
    Dest.f_Width               = Src.f_Width;
    Dest.f_Angle               = Src.f_Angle;
    Dest.f_AngleRate           = Src.f_AngleRate;
    Dest.f_TTC                 = Src.f_TTC;
    Dest.ui_Quality            = Src.ui_Quality;
    Dest.e_MotionStatus        = Src.e_MotionStatus;
    Dest.e_LaneMovement        = Src.e_LaneMovement;
    Dest.e_LaneAssignment      = Src.e_LaneAssignment;
    Dest.ui_ObjID              = Src.ui_ObjID;
    Dest.e_TurnIndicator       = Src.e_TurnIndicator;
    Dest.e_BrakeLight          = Src.e_BrakeLight;
    Dest.e_PedOnPavement       = Src.e_PedOnPavement;
    Dest.e_FrontCollisionValid = Src.e_FrontCollisionValid;
    Dest.e_CIPV                = Src.e_CIPV;
    Dest.ui_Reserved1          = Src.ui_Reserved1;
    Dest.ui_Reserved2          = Src.ui_Reserved2;
  };

  static void ConvertObject(EMRT_t_ObjectList_MCAM_V2::EMRT_t_CamObjectInfo & Dest, const EMRT_t_ObjectList_MCAM_V1::EMRT_t_CamObjectInfo & Src)
  {
    Dest.f_LongDist            = Src.f_LongDist;
    Dest.f_LongDistStd         = Src.f_LongDistStd;
    Dest.f_LateralDist         = Src.f_LateralDist;
    Dest.f_LongVelocityRel     = Src.f_LongVelocityRel;
    Dest.f_LongVelocityRelStd  = Src.f_LongVelocityRelStd;
    Dest.f_LateralVelocityRel  = Src.f_LateralVelocityRel;
    Dest.f_AccelAbs            = Src.f_AccelAbs;
    Dest.f_Width               = Src.f_Width;
    Dest.f_Angle               = Src.f_Angle;
    Dest.f_AngleRate           = Src.f_AngleRate;
    Dest.f_TTC                 = Src.f_TTC;
    Dest.ui_Quality            = Src.ui_Quality;
    Dest.e_MotionStatus        = Src.e_MotionStatus;
    Dest.e_LaneMovement        = Src.e_LaneMovement;
    Dest.e_LaneAssignment      = Src.e_LaneAssignment;
    Dest.ui_ObjID              = Src.ui_ObjID;
    Dest.e_TurnIndicator       = Src.e_TurnIndicator;
    Dest.e_BrakeLight          = Src.e_BrakeLight;
    Dest.e_PedOnPavement       = Src.e_PedOnPavement;
    Dest.e_FrontCollisionValid = Src.e_FrontCollisionValid;
    Dest.e_CIPV                = Src.e_CIPV;
    Dest.e_CamClass            = EMRT_t_ObjectList_MCAM_V1::EM_RT_CAM_CLASS_NO_DETECTION;
    Dest.ui_LaneOccupancyEgo   = 0u;
    Dest.ui_LaneOccupancyLeft  = 0u;
    Dest.ui_LaneOccupancyRight = 0u;
    Dest.ui_Reserved1          = Src.ui_Reserved1;
    Dest.ui_Reserved2          = Src.ui_Reserved2;
  };
  static void ConvertObject(EMRT_t_ObjectList_MCAM_V2::EMRT_t_CamObjectInfo & Dest, const EMRT_t_ObjectList_MCAM_V3::EMRT_t_CamObjectInfo & Src)
  {
    Dest.f_LongDist            = Src.f_LongDist;
    Dest.f_LongDistStd         = Src.f_LongDistStd;
    Dest.f_LateralDist         = Src.f_LateralDist;
    Dest.f_LongVelocityRel     = Src.f_LongVelocityRel;
    Dest.f_LongVelocityRelStd  = Src.f_LongVelocityRelStd;
    Dest.f_LateralVelocityRel  = Src.f_LateralVelocityRel;
    Dest.f_AccelAbs            = Src.f_AccelAbs;
    Dest.f_Width               = Src.f_Width;
    Dest.f_Angle               = Src.f_Angle;
    Dest.f_AngleRate           = Src.f_AngleRate;
    Dest.f_TTC                 = Src.f_TTC;
    Dest.ui_Quality            = Src.ui_Quality;
    Dest.e_MotionStatus        = Src.e_MotionStatus;
    Dest.e_LaneMovement        = Src.e_LaneMovement;
    Dest.e_LaneAssignment      = Src.e_LaneAssignment;
    Dest.ui_ObjID              = Src.ui_ObjID;
    Dest.e_TurnIndicator       = Src.e_TurnIndicator;
    Dest.e_BrakeLight          = Src.e_BrakeLight;
    Dest.e_PedOnPavement       = Src.e_PedOnPavement;
    Dest.e_FrontCollisionValid = Src.e_FrontCollisionValid;
    Dest.e_CIPV                = Src.e_CIPV;
    Dest.e_CamClass            = Src.e_CamClass;
    Dest.ui_LaneOccupancyEgo   = Src.ui_LaneOccupancyEgo;
    Dest.ui_LaneOccupancyLeft  = Src.ui_LaneOccupancyLeft;
    Dest.ui_LaneOccupancyRight = Src.ui_LaneOccupancyRight;
    Dest.ui_Reserved1          = Src.ui_Reserved1;
    Dest.ui_Reserved2          = Src.ui_Reserved2;
  };

  static void ConvertObject(EMRT_t_ObjectList_MCAM_V3::EMRT_t_CamObjectInfo & Dest, const EMRT_t_ObjectList_MCAM_V1::EMRT_t_CamObjectInfo & Src)
  {
    Dest.f_LongDist            = Src.f_LongDist;
    Dest.f_LongDistStd         = Src.f_LongDistStd;
    Dest.f_LateralDist         = Src.f_LateralDist;
    Dest.f_LongVelocityRel     = Src.f_LongVelocityRel;
    Dest.f_LongVelocityRelStd  = Src.f_LongVelocityRelStd;
    Dest.f_LateralVelocityRel  = Src.f_LateralVelocityRel;
    Dest.f_AccelAbs            = Src.f_AccelAbs;
    Dest.f_Width               = Src.f_Width;
    Dest.f_Angle               = Src.f_Angle;
    Dest.f_AngleRate           = Src.f_AngleRate;
    Dest.f_TTC                 = Src.f_TTC;
    Dest.f_LatVelStd           = 0.0f;
    Dest.f_PredImpactPos       = 0.0f;
    Dest.f_LateralDistStd      = 0.0f;
    Dest.ui_Quality            = Src.ui_Quality;
    Dest.e_MotionStatus        = Src.e_MotionStatus;
    Dest.e_LaneMovement        = Src.e_LaneMovement;
    Dest.e_LaneAssignment      = Src.e_LaneAssignment;
    Dest.ui_ObjID              = Src.ui_ObjID;
    Dest.e_TurnIndicator       = Src.e_TurnIndicator;
    Dest.e_BrakeLight          = Src.e_BrakeLight;
    Dest.e_PedOnPavement       = Src.e_PedOnPavement;
    Dest.e_FrontCollisionValid = Src.e_FrontCollisionValid;
    Dest.e_CIPV                = Src.e_CIPV;
    Dest.e_CamClass            = EMRT_t_ObjectList_MCAM_V1::EM_RT_CAM_CLASS_NO_DETECTION;
    Dest.ui_LaneOccupancyEgo   = 0u;
    Dest.ui_LaneOccupancyLeft  = 0u;
    Dest.ui_LaneOccupancyRight = 0u;
    Dest.e_FreeSpaceTgtPos     = 0/*=EM_RT_CAM_FST_NO_PENETRATION*/;
    Dest.e_TurnLeft            = 0/*=EM_RT_CAM_TL_NO_TURN_LEFT*/;
    Dest.e_CutInOut            = 0/*=EM_RT_CAM_CUT_IO_UNKNOWN*/;
    Dest.e_RefPt               = 0/*=EM_RT_CAM_REFPT_REAR*/;
    Dest.ui_ObjLifeTime        = 0/*=*/;
    Dest.ui_SceneScoreInfo     = 0/*=*/;
    Dest.ui_StuctureScoreInfo  = 0/*=*/;
    Dest.e_CyclOnPavement      = 0/*=EM_RT_CAM_CYCL_ON_PAVEMENT*/;
    Dest.ui_Reserved1          = Src.ui_Reserved1;
    Dest.ui_Reserved2          = Src.ui_Reserved2;
  };
  static void ConvertObject(EMRT_t_ObjectList_MCAM_V3::EMRT_t_CamObjectInfo & Dest, const EMRT_t_ObjectList_MCAM_V2::EMRT_t_CamObjectInfo & Src)
  {
    Dest.f_LongDist            = Src.f_LongDist;
    Dest.f_LongDistStd         = Src.f_LongDistStd;
    Dest.f_LateralDist         = Src.f_LateralDist;
    Dest.f_LongVelocityRel     = Src.f_LongVelocityRel;
    Dest.f_LongVelocityRelStd  = Src.f_LongVelocityRelStd;
    Dest.f_LateralVelocityRel  = Src.f_LateralVelocityRel;
    Dest.f_AccelAbs            = Src.f_AccelAbs;
    Dest.f_Width               = Src.f_Width;
    Dest.f_Angle               = Src.f_Angle;
    Dest.f_AngleRate           = Src.f_AngleRate;
    Dest.f_TTC                 = Src.f_TTC;
    Dest.f_LatVelStd           = 0.0f;
    Dest.f_PredImpactPos       = 0.0f;
    Dest.f_LateralDistStd      = 0.0f;
    Dest.ui_Quality            = Src.ui_Quality;
    Dest.e_MotionStatus        = Src.e_MotionStatus;
    Dest.e_LaneMovement        = Src.e_LaneMovement;
    Dest.e_LaneAssignment      = Src.e_LaneAssignment;
    Dest.ui_ObjID              = Src.ui_ObjID;
    Dest.e_TurnIndicator       = Src.e_TurnIndicator;
    Dest.e_BrakeLight          = Src.e_BrakeLight;
    Dest.e_PedOnPavement       = Src.e_PedOnPavement;
    Dest.e_FrontCollisionValid = Src.e_FrontCollisionValid;
    Dest.e_CIPV                = Src.e_CIPV;
    Dest.e_CamClass            = Src.e_CamClass;
    Dest.ui_LaneOccupancyEgo   = Src.ui_LaneOccupancyEgo;
    Dest.ui_LaneOccupancyLeft  = Src.ui_LaneOccupancyLeft;
    Dest.ui_LaneOccupancyRight = Src.ui_LaneOccupancyRight;
    Dest.e_FreeSpaceTgtPos     = 0/*=EM_RT_CAM_FST_NO_PENETRATION*/;
    Dest.e_TurnLeft            = 0/*=EM_RT_CAM_TL_NO_TURN_LEFT*/;
    Dest.e_CutInOut            = 0/*=EM_RT_CAM_CUT_IO_UNKNOWN*/;
    Dest.e_RefPt               = 0/*=EM_RT_CAM_REFPT_REAR*/;
    Dest.ui_ObjLifeTime        = 0/*=*/;
    Dest.ui_SceneScoreInfo     = 0/*=*/;
    Dest.ui_StuctureScoreInfo  = 0/*=*/;
    Dest.e_CyclOnPavement      = 0/*=EM_RT_CAM_CYCL_ON_PAVEMENT*/;
    Dest.ui_Reserved1          = Src.ui_Reserved1;
    Dest.ui_Reserved2          = Src.ui_Reserved2;
  };

  static void Convert(EMRT_t_ObjectList_MCAM_V1::EM_t_RTObjectList_CAM & Dest, const EMRT_t_ObjectList_MCAM_V2::EM_t_RTObjectList_CAM & Src)
  {
    Dest.u_VersionNumber   = 1u;
    Dest.sSigHeader        = Src.sSigHeader;
    Dest.objectListHeader  = Src.objectListHeader;
    for (unsigned int i=0; i<EMRT_N_MCAM_OBJECTS; i++)
    {
      ConvertObject(Dest.a_CamObject[i], Src.a_CamObject[i]);
    }
  };
  static void Convert(EMRT_t_ObjectList_MCAM_V1::EM_t_RTObjectList_CAM & Dest, const EMRT_t_ObjectList_MCAM_V3::EM_t_RTObjectList_CAM & Src)
  {
    Dest.u_VersionNumber   = 1u;
    Dest.sSigHeader        = Src.sSigHeader;
    Dest.objectListHeader  = Src.objectListHeader;
    for (unsigned int i=0; i<EMRT_N_MCAM_OBJECTS; i++)
    {
      ConvertObject(Dest.a_CamObject[i], Src.a_CamObject[i]);
    }
  };

  static void Convert(EMRT_t_ObjectList_MCAM_V2::EM_t_RTObjectList_CAM & Dest, const EMRT_t_ObjectList_MCAM_V1::EM_t_RTObjectList_CAM & Src)
  {
    Dest.u_VersionNumber   = 2u;
    Dest.sSigHeader        = Src.sSigHeader;
    Dest.objectListHeader  = Src.objectListHeader;
    for (unsigned int i=0; i<EMRT_N_MCAM_OBJECTS; i++)
    {
      ConvertObject(Dest.a_CamObject[i], Src.a_CamObject[i]);
    }
  };
  static void Convert(EMRT_t_ObjectList_MCAM_V2::EM_t_RTObjectList_CAM & Dest, const EMRT_t_ObjectList_MCAM_V3::EM_t_RTObjectList_CAM & Src)
  {
    Dest.u_VersionNumber   = 2u;
    Dest.sSigHeader        = Src.sSigHeader;
    Dest.objectListHeader  = Src.objectListHeader;
    for (unsigned int i=0; i<EMRT_N_MCAM_OBJECTS; i++)
    {
      ConvertObject(Dest.a_CamObject[i], Src.a_CamObject[i]);
    }
  };

  static void Convert(EMRT_t_ObjectList_MCAM_V3::EM_t_RTObjectList_CAM & Dest, const EMRT_t_ObjectList_MCAM_V1::EM_t_RTObjectList_CAM & Src)
  {
    Dest.u_VersionNumber   = 3u;
    Dest.sSigHeader        = Src.sSigHeader;
    Dest.objectListHeader  = Src.objectListHeader;
    for (unsigned int i=0; i<EMRT_N_MCAM_OBJECTS; i++)
    {
      ConvertObject(Dest.a_CamObject[i], Src.a_CamObject[i]);
    }
  };
  static void Convert(EMRT_t_ObjectList_MCAM_V3::EM_t_RTObjectList_CAM & Dest, const EMRT_t_ObjectList_MCAM_V2::EM_t_RTObjectList_CAM & Src)
  {
    Dest.u_VersionNumber   = 3u;
    Dest.sSigHeader        = Src.sSigHeader;
    Dest.objectListHeader  = Src.objectListHeader;
    for (unsigned int i=0; i<EMRT_N_MCAM_OBJECTS; i++)
    {
      ConvertObject(Dest.a_CamObject[i], Src.a_CamObject[i]);
    }
  };

public:

  static const char *GetConverterTypeName()
  {
    return "CamObjInputData"; /* "EMRT_t_ObjectList_MCAM" */
  };

  CConvEmObjectListMcamRt(void) : CSimConverterBase(NULL/*DEP_NAMES*/, DEP_COUNT), m_BufV1(), m_BufV2(), m_BufV3()
  {
    Init_EMRT_t_ObjectList(m_BufV1);
    Init_EMRT_t_ObjectList(m_BufV2);
    Init_EMRT_t_ObjectList(m_BufV3);
  };

  virtual ~CConvEmObjectListMcamRt(void)
  {
  };

  const char *GetTypeName(void)
  {
    return GetConverterTypeName();
  }

  void Destroy(void)
  {
    delete this;
  }

  /** returns:
   *   SIM_ERR_OK - when this value can be used
   *   SIM_ERR_USE_VALUE_FROM_PPORT - when the conversion is not implemented here
   *                                  and the value from Provide Port must be used
   */
  long ConvertData(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
    SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo *pProvidePortVersionInfo,
    void *pPPortData,
    void **pOutData, unsigned long &ulOutSize);

  /** returns:
   *   SIM_ERR_OK - when this value can be used
   *   SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT - when the default vaule is not implemented here
   *                                            and the default value from Request Port must be used
   */
  long GetDefaultValue(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
    void **pDefaultData, unsigned long &ulDefaultSize);

protected:

  // used to check if an unversioned PPort is compatible with a certain version of RPort
  bool IsVersionCompatibleWithType(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
    SimPortDataTypes_t ePPortType, unsigned long ulPPortSize);

  // used to check if ports are compatible between different versions
  bool AreVersionsCompatible(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
    SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo &providePortVersionInfo);

private:
  typedef enum eEMRT_ObjListVersionCount
  {
    EMRT_T_OBJECTLIST_MCAM_V1,
    EMRT_T_OBJECTLIST_MCAM_V2,
    EMRT_T_OBJECTLIST_MCAM_V3,
    EMRT_T_OBJECTLIST_COUNT
  } eEMRT_ObjListVersionCount;

  static CVersionInfoImpl BASE_VERSION;
  static CVersionInfoImpl VERSION1;
  static CVersionInfoImpl VERSION2;
  static CVersionInfoImpl VERSION3;
  static const CVersionInfoImpl * const INPUT_DATA_VERSIONS[EMRT_T_OBJECTLIST_COUNT];

  static const unsigned long SUPPORTED_SIZE[EMRT_T_OBJECTLIST_COUNT];

  bool IsPortSupported(unsigned long ulPortSize, const IVersionInfo *pPortVersion) const
  {
    for (int nI = 0; nI < EMRT_T_OBJECTLIST_COUNT; nI++)
    {
      if ((pPortVersion == NULL) || pPortVersion->Equals(INPUT_DATA_VERSIONS[nI]))
      {
        if (ulPortSize == SUPPORTED_SIZE[nI])
        {
          return true;
        }
      }
    };
    return false;
  };
};

CVersionInfoImpl CConvEmObjectListMcamRt::BASE_VERSION(0, 0, 0);
CVersionInfoImpl CConvEmObjectListMcamRt::VERSION1(0, 0, 1);
CVersionInfoImpl CConvEmObjectListMcamRt::VERSION2(0, 0, 2);
CVersionInfoImpl CConvEmObjectListMcamRt::VERSION3(0, 0, 3);

const CVersionInfoImpl * const CConvEmObjectListMcamRt::INPUT_DATA_VERSIONS[CConvEmObjectListMcamRt::EMRT_T_OBJECTLIST_COUNT] =
{
  &VERSION1,
  &VERSION2,
  &VERSION3
};

const unsigned long CConvEmObjectListMcamRt::SUPPORTED_SIZE[CConvEmObjectListMcamRt::EMRT_T_OBJECTLIST_COUNT] =
{
  sizeof(EMRT_t_ObjectList_MCAM_V1::EM_t_RTObjectList_CAM),
  sizeof(EMRT_t_ObjectList_MCAM_V2::EM_t_RTObjectList_CAM),
  sizeof(EMRT_t_ObjectList_MCAM_V3::EM_t_RTObjectList_CAM),
};

long CConvEmObjectListMcamRt::ConvertData(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
  SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo *pProvidePortVersionInfo,
  void *pPPortData,
  void **pOutData, unsigned long &ulOutSize)
{
  long lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
  const unsigned int uDataVer = ((pPPortData != NULL) && (ulPPortSize >= 4) && (ePPortType == simOPAQUE_t))?(*reinterpret_cast<unsigned int*>(pPPortData)):(0);
  //const unsigned int uDataVerR = ((pPPortData != NULL) && (ulPPortSize >= 4) && (ePPortType == simREFERENCE_t))?(*reinterpret_cast<unsigned int*>(pPPortData)):(0);
  CVersionInfoImpl SrcVersion(CONV_I32VERSION_TO_TUPPLE(uDataVer));
  // If no provide port version provided, then use the one extracted from the numeric value
  if (pProvidePortVersionInfo == NULL)
  {
    pProvidePortVersionInfo = &SrcVersion;
  }
  if (/*(eRPortType == ePPortType)*/((eRPortType == simOPAQUE_t) && ((ePPortType == simOPAQUE_t) || (ePPortType == simREFERENCE_t)))
    && (ulRPortSize == ulPPortSize) && (requestPortVersionInfo.Equals(pProvidePortVersionInfo)))
  {
    // No conversion necessary
    *pOutData = pPPortData;
    ulOutSize = ulRPortSize;
    lRet = SIM_ERR_USE_VALUE_FROM_PPORT;
  }
  else
  {
    // Some conversion is necessary
    // First decide which version we are converting to
    if ((ulRPortSize == sizeof(EMRT_t_ObjectList_MCAM_V3::EM_t_RTObjectList_CAM)) && (requestPortVersionInfo.Equals(&VERSION3) || requestPortVersionInfo.Equals(&BASE_VERSION)))
    {
      // Destination port of V3
      EMRT_t_ObjectList_MCAM_V3::EM_t_RTObjectList_CAM & Dest = m_BufV3;
      if ((ulPPortSize == sizeof(EMRT_t_ObjectList_MCAM_V2::EM_t_RTObjectList_CAM))
        && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VERSION2)) || (pProvidePortVersionInfo->Equals(&BASE_VERSION)))
        && (uDataVer == 0x2u))
      {
        // Source port of V2
        const EMRT_t_ObjectList_MCAM_V2::EM_t_RTObjectList_CAM & Src = *reinterpret_cast<EMRT_t_ObjectList_MCAM_V2::EM_t_RTObjectList_CAM *>(pPPortData);
        Convert(Dest, Src);
        *pOutData = (void*)&Dest;
        ulOutSize = sizeof(Dest);
        lRet = SIM_ERR_OK;
      }
      else if ((ulPPortSize == sizeof(EMRT_t_ObjectList_MCAM_V1::EM_t_RTObjectList_CAM))
        && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VERSION1)) || (pProvidePortVersionInfo->Equals(&BASE_VERSION)))
        && ((uDataVer == 0x1u) ))
      {
        // Source port of V1
        const EMRT_t_ObjectList_MCAM_V1::EM_t_RTObjectList_CAM & Src = *reinterpret_cast<EMRT_t_ObjectList_MCAM_V1::EM_t_RTObjectList_CAM *>(pPPortData);
        Convert(Dest, Src);
        *pOutData = (void*)&Dest;
        ulOutSize = sizeof(Dest);
        lRet = SIM_ERR_OK;
      }
      else
      {
        lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
      }
    }
    else if ((ulRPortSize == sizeof(EMRT_t_ObjectList_MCAM_V2::EM_t_RTObjectList_CAM)) && (requestPortVersionInfo.Equals(&VERSION2) || requestPortVersionInfo.Equals(&BASE_VERSION)))
    {
      // Destination port of V2
      EMRT_t_ObjectList_MCAM_V2::EM_t_RTObjectList_CAM & Dest = m_BufV2;
      if ((ulPPortSize == sizeof(EMRT_t_ObjectList_MCAM_V3::EM_t_RTObjectList_CAM))
        && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VERSION3)) || (pProvidePortVersionInfo->Equals(&BASE_VERSION)))
        && (uDataVer == 0x3u))
      {
        // Source port of V3
        const EMRT_t_ObjectList_MCAM_V3::EM_t_RTObjectList_CAM & Src = *reinterpret_cast<EMRT_t_ObjectList_MCAM_V3::EM_t_RTObjectList_CAM *>(pPPortData);
        Convert(Dest, Src);
        *pOutData = (void*)&Dest;
        ulOutSize = sizeof(Dest);
        lRet = SIM_ERR_OK;
      }
      else if ((ulPPortSize == sizeof(EMRT_t_ObjectList_MCAM_V1::EM_t_RTObjectList_CAM))
        && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VERSION1)) || (pProvidePortVersionInfo->Equals(&BASE_VERSION)))
        && ((uDataVer == 0x1u) ))
      {
        // Source port of V1
        const EMRT_t_ObjectList_MCAM_V1::EM_t_RTObjectList_CAM & Src = *reinterpret_cast<EMRT_t_ObjectList_MCAM_V1::EM_t_RTObjectList_CAM *>(pPPortData);
        Convert(Dest, Src);
        *pOutData = (void*)&Dest;
        ulOutSize = sizeof(Dest);
        lRet = SIM_ERR_OK;
      }
      else
      {
        lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
      }
    }
    else if ((ulRPortSize == sizeof(EMRT_t_ObjectList_MCAM_V1::EM_t_RTObjectList_CAM)) && (requestPortVersionInfo.Equals(&VERSION1) || requestPortVersionInfo.Equals(&BASE_VERSION)))
    {
      // Destination port of V1
      EMRT_t_ObjectList_MCAM_V1::EM_t_RTObjectList_CAM & Dest = m_BufV1;
      if ((ulPPortSize == sizeof(EMRT_t_ObjectList_MCAM_V3::EM_t_RTObjectList_CAM))
        && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VERSION3)) || (pProvidePortVersionInfo->Equals(&BASE_VERSION)))
        && (uDataVer == 0x3u))
      {
        // Source port of V3
        const EMRT_t_ObjectList_MCAM_V3::EM_t_RTObjectList_CAM & Src = *reinterpret_cast<EMRT_t_ObjectList_MCAM_V3::EM_t_RTObjectList_CAM *>(pPPortData);
        Convert(Dest, Src);
        *pOutData = (void*)&Dest;
        ulOutSize = sizeof(Dest);
        lRet = SIM_ERR_OK;
      }
      else if ((ulPPortSize == sizeof(EMRT_t_ObjectList_MCAM_V2::EM_t_RTObjectList_CAM))
        && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VERSION2)) || (pProvidePortVersionInfo->Equals(&BASE_VERSION)))
        && ((uDataVer == 0x2u) ))
      {
        // Source port of V2
        const EMRT_t_ObjectList_MCAM_V2::EM_t_RTObjectList_CAM & Src = *reinterpret_cast<EMRT_t_ObjectList_MCAM_V2::EM_t_RTObjectList_CAM *>(pPPortData);
        Convert(Dest, Src);
        *pOutData = (void*)&Dest;
        ulOutSize = sizeof(Dest);
        lRet = SIM_ERR_OK;
      }
      else
      {
        lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
      }
    }
    else
    {
      lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
    }
  }
  return lRet;
};

/** returns:
 *   SIM_ERR_OK - when this value can be used
 *   SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT - when the default value is not implemented here
 *                                            and the default value from Request Port must be used
 */
long CConvEmObjectListMcamRt::GetDefaultValue(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
  void **pDefaultData, unsigned long &ulDefaultSize)
{
  long lRet = SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT;
  if (eRPortType == simOPAQUE_t)
  {
    if ((ulRPortSize == sizeof(EMRT_t_ObjectList_MCAM_V1::EM_t_RTObjectList_CAM)) && ((BASE_VERSION.Equals(&requestPortVersionInfo)) || (VERSION1.Equals(&requestPortVersionInfo))))
    {
      EMRT_t_ObjectList_MCAM_V1::EM_t_RTObjectList_CAM & Dest = m_BufV1;
      Init_EMRT_t_ObjectList(Dest);
      *pDefaultData = &Dest;
      ulDefaultSize = sizeof(Dest);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(EMRT_t_ObjectList_MCAM_V2::EM_t_RTObjectList_CAM)) && ((BASE_VERSION.Equals(&requestPortVersionInfo)) || (VERSION2.Equals(&requestPortVersionInfo))))
    {
      EMRT_t_ObjectList_MCAM_V2::EM_t_RTObjectList_CAM & Dest = m_BufV2;
      Init_EMRT_t_ObjectList(Dest);
      *pDefaultData = &Dest;
      ulDefaultSize = sizeof(Dest);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(EMRT_t_ObjectList_MCAM_V3::EM_t_RTObjectList_CAM)) && ((BASE_VERSION.Equals(&requestPortVersionInfo)) || (VERSION3.Equals(&requestPortVersionInfo))))
    {
      EMRT_t_ObjectList_MCAM_V3::EM_t_RTObjectList_CAM & Dest = m_BufV3;
      Init_EMRT_t_ObjectList(Dest);
      *pDefaultData = &Dest;
      ulDefaultSize = sizeof(Dest);
      lRet = SIM_ERR_OK;
    }
    else
    {
      // No conversion available
    }
  }
  return lRet;
}

// used to check if an unversioned PPort is compatible with a certain version of RPort
bool CConvEmObjectListMcamRt::IsVersionCompatibleWithType(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
  SimPortDataTypes_t ePPortType, unsigned long ulPPortSize)
{
  bool bResult = false;
  // Equal ports are always compatible (at least assumed to be)
  if ((ulRPortSize == ulPPortSize)
    && /*(eRPortType == ePPortType)*/((eRPortType == simOPAQUE_t) && ((ePPortType == simOPAQUE_t) || (ePPortType == simREFERENCE_t))))
  {
    bResult = true;
  }
  else if ((eRPortType == simOPAQUE_t) && ((ePPortType == simOPAQUE_t) || (ePPortType == simREFERENCE_t)))
  {
    if ((IsPortSupported(ulRPortSize, &requestPortVersionInfo)) && (IsPortSupported(ulPPortSize, NULL)))
    {
      bResult = true;
    }
  }
  return bResult;
}

// used to check if ports are compatible between different versions
bool CConvEmObjectListMcamRt::AreVersionsCompatible(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
  SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo &providePortVersionInfo)
{
  bool bResult = false;
  // Equal ports are always compatible (at least assumed to be)
  if ((ulRPortSize == ulPPortSize)
    && ((eRPortType == simOPAQUE_t) && ((ePPortType == simOPAQUE_t) || (ePPortType == simREFERENCE_t))))
  {
    bResult = true;
  }
  else if ((eRPortType == simOPAQUE_t) && ((ePPortType == simOPAQUE_t) || (ePPortType == simREFERENCE_t)))
  {
    if ((IsPortSupported(ulRPortSize, &requestPortVersionInfo)) && (IsPortSupported(ulPPortSize, &providePortVersionInfo)))
    {
      bResult = true;
    }
  }
  return bResult;
}

//
// Main factory class returning conversion class
//
IConverter * CreateEmObjectListMcamRtConvClass(void)
{
  return new CConvEmObjectListMcamRt();
}
