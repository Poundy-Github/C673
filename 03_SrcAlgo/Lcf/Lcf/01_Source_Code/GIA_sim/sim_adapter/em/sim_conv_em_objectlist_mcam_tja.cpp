/*! \file **********************************************************************

  COMPANY:         Continental

  PROJECT:         Simulation

  COMPONENT:       sim_adapter em

  MODULNAME:       sim_conv_em_objectlist_mcam.cpp

  DESCRIPTION:     Converter for MFC4T0 MCAM object list

  AUTHOR:          Gergely Ungvary

  CREATION DATE:   24.04.2014

  VERSION:         $Revision: 1.1 $

  ---*/ /*---
  CHANGES:         $Log: sim_conv_em_objectlist_mcam_tja.cpp  $
  CHANGES:         Revision 1.1 2021/12/13 17:20:44CET Wang, David (Wangd3) 
  CHANGES:         Initial revision
  CHANGES:         Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_adapter/em/project.pj
  CHANGES:         Revision 1.1 2017/08/10 13:15:06CEST uid34177 
  CHANGES:         Initial revision
  CHANGES:         Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_adapter/em/project.pj
  CHANGES:         Revision 1.2 2016/10/07 09:58:42CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:         + Version 3 (and 2) with dependency from EM
  CHANGES:         Revision 1.1 2016/01/13 13:46:22CET Berndt, Thomas01 (berndtt1) 
  CHANGES:         Initial revision
  CHANGES:         Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/CRT_CommonRadarToolbox/04_Engineering/03_Workspace/algo/sim_adapter/em/project.pj
  CHANGES:         Revision 1.2 2014/11/18 16:23:45CET Berndt, Thomas01 (berndtt1) 
  CHANGES:         + Conversion from Byte-Aligned input V1_1_R to V1 and V1_1
  CHANGES:         for the fusion of camera and radar
  CHANGES:         --- Added comments ---  berndtt1 [Nov 18, 2014 4:25:39 PM CET]
  CHANGES:         Change Package : 281259:1 http://mks-psad:7002/im/viewissue?selection=281259
  CHANGES:         Revision 1.1 2014/04/24 18:59:47CEST Ungvary, Gergely (ungvaryg) 
  CHANGES:         Initial revision
  CHANGES:         Member added to project /nfs/projekte1/PROJECTS/ARS400/06_Algorithm/04_Engineering/03_Workspace/algo/sim_adapter/em/project.pj

**************************************************************************** */
/* includes ---------------------------------------------------------------- */
#include "stdafx.h"
#include "sim_conv_em_objectlist_mcam_tja.h"
#include "sim_versioninfo_impl.h"

// typedef float float32;
//typedef unsigned __int8 boolean/*, uint8*/;
// typedef unsigned __int32 uint32;

static const unsigned int EMTJA_N_MCAM_OBJECTS = 12u;

//
// ARS4T0 EMTJA_t_ObjectList_MCAM version 1
//
namespace EMTJA_t_ObjectList_MCAM_V1
{
  typedef unsigned __int32 AlgoInterfaceVersionNumber_t     /* Algo interface version nummbers @min:0 @max:4294967295 */ /* [Satisfies_rte sws 1188] */;
  typedef unsigned __int32 AlgoDataTimeStamp_t              /* Algo data time-stamp type (32 bit variant) @min:0 @max:4294967295 */  /* [Satisfies_rte sws 1188] */;
  typedef unsigned __int16 AlgoCycleCounter_t               /* Algo cycle counter @min:0 @max:65535 */  /* [Satisfies_rte sws 1188] */;
  typedef unsigned __int8 AlgoSignalState_t                 /* Algo signal state enumeration @min: 0 @max:2 @values: enum { AL_SIG_STATE_INVALID=2,AL_SIG_STATE_INIT=0,AL_SIG_STATE_OK=1,} */  /* [Satisfies_rte sws 1188] */;
  typedef unsigned __int8 EMTJA_t_CamDetectionMode           /* Status of camera object detection @min: 0 @max:2 @values: enum { EMTJA_MCAM_DETECT_STATE_UNKNOWN=0,EMTJA_MCAM_DETECT_STATE_REDUCED=2,EMTJA_MCAM_DETECT_STATE_NORMAL=1,} */	/* [Satisfies_rte sws 1188] */;
  typedef unsigned __int8 EMTJA_t_CamSensorState             /* Status of camera @min: 0 @max:3 @values: enum { EMTJA_MCAM_SEN_STATE_OK=1,EMTJA_MCAM_SEN_STATE_UNKNOWN=0,EMTJA_MCAM_SEN_STATE_NOT_OK=2,EMTJA_MCAM_SEN_STATE_BLOCKED=3,} */	/* [Satisfies_rte sws 1188] */;
  typedef unsigned __int8 EMTJA_t_MCamObjClass               /* This signal indicates the class of the object. @min: 0 @max:7 @values: enum { EMTJA_MCAM_OBJ_CLASS_POINT=0,EMTJA_MCAM_OBJ_CLASS_BICYCLE=5,EMTJA_MCAM_OBJ_CLASS_WIDE=6,EMTJA_MCAM_OBJ_CLASS_UNCLASSIFIED=7,EMTJA_MCAM_OBJ_CLASS_MOTORCYCLE=4,EMTJA_MCAM_OBJ_CLASS_TRUCK=2,EMTJA_MCAM_OBJ_CLASS_PEDESTRIAN=3,EMTJA_MCAM_OBJ_CLASS_CAR=1,} */	/* [Satisfies_rte sws 1188] */;
  typedef unsigned __int8 EMTJA_t_MCamObjDynProp             /* This signal indicates wether the object is moving, stationary or oncoming, based on comparison of the longitudinal relative velocity with the host vehicle velocity. @min: 0 @max:6 @values: enum { EMTJA_MCAM_OBJ_DYN_PROP_ONCOMING=2,EMTJA_MCAM_OBJ_DYN_PROP_STATIONARY=1,EMTJA_MCAM_OBJ_DYN_PROP_CROSSING_RIGHT=4,EMTJA_MCAM_OBJ_DYN_PROP_CROSSING_LEFT=3,EMTJA_MCAM_OBJ_DYN_PROP_STOPPED=6,EMTJA_MCAM_OBJ_DYN_PROP_UNKNOWN=5,EMTJA_MCAM_OBJ_DYN_PROP_MOVING=0,} */	/* [Satisfies_rte sws 1188] */;
  typedef unsigned __int8 EMTJA_t_ObjFlashLightStat          /* Status of the flash light of the object. @min: 0 @max:255 @values: enum { EMTJA_MCAM_SFL_HAZARD_FLASHING=4,EMTJA_MCAM_SFL_NO_FLASHING=1,EMTJA_MCAM_SFL_FLASHING_LEFT=2,EMTJA_MCAM_SFL_FLASHING_RIGHT=3,EMTJA_MCAM_SFL_UNKNOWN=0,EMTJA_MCAM_SFL_SNA=255,} */	/* [Satisfies_rte sws 1188] */;

  typedef enum eAlgoSignalState_t {
    AL_SIG_STATE_INIT=0,
    AL_SIG_STATE_OK=1,
    AL_SIG_STATE_INVALID=2,
  } eAlgoSignalState_t;

  typedef enum eEMTJA_t_CamDetectionMode {
    EMTJA_MCAM_DETECT_STATE_UNKNOWN=0,
    EMTJA_MCAM_DETECT_STATE_NORMAL=1,
    EMTJA_MCAM_DETECT_STATE_REDUCED=2,
  } eEMTJA_t_CamDetectionMode;

  typedef enum eEMTJA_t_CamSensorState {
    EMTJA_MCAM_SEN_STATE_UNKNOWN=0,
    EMTJA_MCAM_SEN_STATE_OK=1,
    EMTJA_MCAM_SEN_STATE_NOT_OK=2,
    EMTJA_MCAM_SEN_STATE_BLOCKED=3,
  } eEMTJA_t_CamSensorState;

  typedef enum eEMTJA_t_MCamObjClass {
    EMTJA_MCAM_OBJ_CLASS_POINT=0,
    EMTJA_MCAM_OBJ_CLASS_CAR=1,
    EMTJA_MCAM_OBJ_CLASS_TRUCK=2,
    EMTJA_MCAM_OBJ_CLASS_PEDESTRIAN=3,
    EMTJA_MCAM_OBJ_CLASS_MOTORCYCLE=4,
    EMTJA_MCAM_OBJ_CLASS_BICYCLE=5,
    EMTJA_MCAM_OBJ_CLASS_WIDE=6,
    EMTJA_MCAM_OBJ_CLASS_UNCLASSIFIED=7,
  } eEMTJA_t_MCamObjClass;

  typedef enum eEMTJA_t_MCamObjDynProp {
    EMTJA_MCAM_OBJ_DYN_PROP_MOVING=0,
    EMTJA_MCAM_OBJ_DYN_PROP_STATIONARY=1,
    EMTJA_MCAM_OBJ_DYN_PROP_ONCOMING=2,
    EMTJA_MCAM_OBJ_DYN_PROP_CROSSING_LEFT=3,
    EMTJA_MCAM_OBJ_DYN_PROP_CROSSING_RIGHT=4,
    EMTJA_MCAM_OBJ_DYN_PROP_UNKNOWN=5,
    EMTJA_MCAM_OBJ_DYN_PROP_STOPPED=6,
  } eEMTJA_t_MCamObjDynProp;

  typedef enum eEMTJA_t_ObjFlashLightStat {
    EMTJA_MCAM_SFL_UNKNOWN=0,
    EMTJA_MCAM_SFL_NO_FLASHING=1,
    EMTJA_MCAM_SFL_FLASHING_LEFT=2,
    EMTJA_MCAM_SFL_FLASHING_RIGHT=3,
    EMTJA_MCAM_SFL_HAZARD_FLASHING=4,
    EMTJA_MCAM_SFL_SNA=255,
  } eEMTJA_t_ObjFlashLightStat;

  typedef struct SignalHeader_t                             /* [Satisfies_rte sws 1191] */
  {
    AlgoDataTimeStamp_t uiTimeStamp;
    AlgoCycleCounter_t uiMeasurementCounter;
    AlgoCycleCounter_t uiCycleCounter;
    AlgoSignalState_t eSigStatus;
  } SignalHeader_t;                                         /* Common header for all structured data types */

  typedef struct EMTJA_t_ObjectRecognitionInfo
  {
    float f_DistX;
    float f_DistY;
    float f_VabsX;
    float f_VabsY;
    EMTJA_t_MCamObjDynProp e_DynamicProperty;
    EMTJA_t_MCamObjClass e_Classification;
    unsigned char ui_Quality;
    unsigned char ui_ID;
    EMTJA_t_ObjFlashLightStat e_StatusFlashLight;
    unsigned char ui_Reserved1;
    unsigned char ui_Reserved2;
    unsigned char ui_Reserved3;
  } EMTJA_t_ObjectRecognitionInfo;

  typedef struct EMTJA_t_ObjectListHeader
  {
    float f_CamObjAge;
    EMTJA_t_CamSensorState e_CamSensorState;
    EMTJA_t_CamDetectionMode e_CamDetectionMode;
    unsigned char ui_CamNumObjects;
    unsigned char b_ValidCRC;
    unsigned char ui_MsgCounter;
    unsigned char ui_Reserved1;
    unsigned char ui_Reserved2;
    unsigned char ui_Reserved3;
  } EMTJA_t_ObjectListHeader;

  typedef EMTJA_t_ObjectRecognitionInfo EMTJA_t_MCamObjArray[EMTJA_N_MCAM_OBJECTS];

  typedef struct EMTJA_t_ObjectList_MCAM
  {
    AlgoInterfaceVersionNumber_t u_VersionNumber;
    SignalHeader_t sSigHeader;
    EMTJA_t_ObjectListHeader objectListHeader;
    EMTJA_t_MCamObjArray a_ObjRecognitionInfo;
  } EMTJA_t_ObjectList_MCAM;
} // end of namespace EMTJA_t_ObjectList_MCAM_V1

namespace EMTJA_t_ObjectList_MCAM_V1_1
{
  typedef unsigned __int8 EMTJA_t_CamObjAssociatedLane /* Mapping of the object to a lane @min: 0 @max:255 @values:  */;

  typedef enum eEMTJA_t_CamObjAssociatedLane {
    EMTJA_MCAM_OBJ_ASSOC_LANE_UNKNOWN=0,
    EMTJA_MCAM_OBJ_ASSOC_LANE_EGO=1,
    EMTJA_MCAM_OBJ_ASSOC_LANE_LEFT=2,
    EMTJA_MCAM_OBJ_ASSOC_LANE_RIGHT=3,
    EMTJA_MCAM_OBJ_ASSOC_LANE_OUTSIDE=4,
    EMTJA_MCAM_OBJ_ASSOC_LANE_BEYOND_LEFT=5,
    EMTJA_MCAM_OBJ_ASSOC_LANE_BEYOND_RIGHT=6,
    EMTJA_MCAM_OBJ_ASSOC_LANE_SNA=255,
  } eEMTJA_t_CamObjAssociatedLane;

  typedef struct EMTJA_t_ObjectRecognitionInfo
  {
    float f_DistX;
    float f_DistXStd;
    float f_DistY;
    float f_DistYStd;
    float f_VabsX;
    float f_VabsXStd;
    float f_VabsY;
    float f_VabsYStd;
    EMTJA_t_ObjectList_MCAM_V1::EMTJA_t_MCamObjDynProp e_DynamicProperty;
    EMTJA_t_ObjectList_MCAM_V1::EMTJA_t_MCamObjClass e_Classification;
    unsigned char ui_Quality;
    unsigned char ui_ID;
    EMTJA_t_ObjectList_MCAM_V1::EMTJA_t_ObjFlashLightStat e_StatusFlashLight;
    unsigned char ui_Accuracy;
    EMTJA_t_CamObjAssociatedLane eAssociatedLane;
    unsigned char uiAssignedLaneLeftQuota;
    unsigned char uiAssignedLaneRightQuota;
    unsigned char ui_Reserved1;
    unsigned char ui_Reserved2;
    unsigned char ui_Reserved3;
  } EMTJA_t_ObjectRecognitionInfo;

  typedef EMTJA_t_ObjectRecognitionInfo EMTJA_t_MCamObjArray[EMTJA_N_MCAM_OBJECTS];

  typedef struct EMTJA_t_ObjectList_MCAM
  {
    EMTJA_t_ObjectList_MCAM_V1::AlgoInterfaceVersionNumber_t u_VersionNumber;
    EMTJA_t_ObjectList_MCAM_V1::SignalHeader_t sSigHeader;
    EMTJA_t_ObjectList_MCAM_V1::EMTJA_t_ObjectListHeader objectListHeader;
    EMTJA_t_MCamObjArray a_ObjRecognitionInfo;
  } EMTJA_t_ObjectList_MCAM;

} // end of namespace EMTJA_t_ObjectList_MCAM_V1_1


// Data package for the sim_fusion_sync connection (byte aligned structures!)
// Always provide port, never receive port!
namespace EMTJA_t_ObjectList_MCAM_V1_1_R
{
#pragma pack (push, 1)
  typedef struct SignalHeader_t                             /* [Satisfies_rte sws 1191] */
  {
    EMTJA_t_ObjectList_MCAM_V1::AlgoDataTimeStamp_t uiTimeStamp;
    EMTJA_t_ObjectList_MCAM_V1::AlgoCycleCounter_t uiMeasurementCounter;
    EMTJA_t_ObjectList_MCAM_V1::AlgoCycleCounter_t uiCycleCounter;
    EMTJA_t_ObjectList_MCAM_V1::AlgoSignalState_t eSigStatus;
  } SignalHeader_t;                                         /* Common header for all structured data types */

#pragma pack (1)
  typedef EMTJA_t_ObjectList_MCAM_V1_1::EMTJA_t_ObjectRecognitionInfo EMTJA_t_ObjectRecognitionInfo;
#pragma pack (1)
  typedef EMTJA_t_ObjectList_MCAM_V1_1::EMTJA_t_ObjectRecognitionInfo EMTJA_t_MCamObjArray[EMTJA_N_MCAM_OBJECTS];

#pragma pack (1)
  typedef struct EMTJA_t_ObjectList_MCAM
  {
    EMTJA_t_ObjectList_MCAM_V1::AlgoInterfaceVersionNumber_t u_VersionNumber;
    SignalHeader_t sSigHeader;
    EMTJA_t_ObjectList_MCAM_V1::EMTJA_t_ObjectListHeader objectListHeader;
    EMTJA_t_MCamObjArray a_ObjRecognitionInfo;
  } EMTJA_t_ObjectList_MCAM;

#pragma pack (pop)
} // end of namespace EMTJA_t_ObjectList_MCAM_V1_1_R

// Version 3 and Version 2 have identical lenght ! The difference is ui_CamObstacleDetected in version 3 had replaced ui_Reserved1 in version 2
namespace EMTJA_t_ObjectList_MCAM_V3
{
  typedef struct EMTJA_t_ObjectListHeader
  {
    float f_CamObjAge;
    EMTJA_t_ObjectList_MCAM_V1::EMTJA_t_CamSensorState e_CamSensorState;
    EMTJA_t_ObjectList_MCAM_V1::EMTJA_t_CamDetectionMode e_CamDetectionMode;
    unsigned char ui_CamNumObjects;
    unsigned char b_ValidCRC;
    unsigned char ui_MsgCounter;
    unsigned char ui_CamObstacleDetected;
    unsigned char ui_Reserved2;
    unsigned char ui_Reserved3;
  } EMTJA_t_ObjectListHeader;

  typedef struct EMTJA_t_ObjectRecognitionInfo
  {
    float f_DistX;
    float f_DistXStd;
    float f_DistY;
    float f_DistYStd;
    float f_VrelX;
    float f_VrelXStd;
    float f_VrelY;
    float f_VrelYStd;
    EMTJA_t_ObjectList_MCAM_V1::EMTJA_t_MCamObjDynProp e_DynamicProperty;
    EMTJA_t_ObjectList_MCAM_V1::EMTJA_t_MCamObjClass e_Classification;
    unsigned char ui_Quality;
    unsigned char ui_ID;
    EMTJA_t_ObjectList_MCAM_V1::EMTJA_t_ObjFlashLightStat e_StatusFlashLight;
    unsigned char ui_Accuracy;
    EMTJA_t_ObjectList_MCAM_V1_1::EMTJA_t_CamObjAssociatedLane eAssociatedLane;
    unsigned char uiAssignedLaneLeftQuota;
    unsigned char uiAssignedLaneRightQuota;
    unsigned char ui_Reserved1;
    unsigned char ui_Reserved2;
    unsigned char ui_Reserved3;
  } EMTJA_t_ObjectRecognitionInfo;

  typedef EMTJA_t_ObjectRecognitionInfo EMTJA_t_MCamObjArray[EMTJA_N_MCAM_OBJECTS];

  typedef struct EMTJA_t_ObjectList_MCAM
  {
    EMTJA_t_ObjectList_MCAM_V1::AlgoInterfaceVersionNumber_t u_VersionNumber;
    EMTJA_t_ObjectList_MCAM_V1::SignalHeader_t sSigHeader;
    EMTJA_t_ObjectListHeader objectListHeader;
    EMTJA_t_MCamObjArray a_ObjRecognitionInfo;
  } EMTJA_t_ObjectList_MCAM;
} // end of namespace EMTJA_t_ObjectList_MCAM_V3

// Dependency structure
typedef struct tag_ObjSyncEgoMotion
{
  float Velocity;
  float f_GlobalObjSyncCosFloatAng;
  float YawRate;
  float LatPos;
  float f_GlobalLongPosToRot;
} ObjSyncEgoMotion_t;

class CConvEmObjectListMcamTJA : public CSimConverterBase
{
  // the list of dependency names used inside by the converter
  static const char *DEP_NAMES[];

  // here we define the index of each dependency for quick acces
  // the order here should match with the order from DEP_NAMES array
  enum eDepIdx
  {
    // add new dependencies here
    OBJ_SYNC_EGO_MOTION,
    DEP_COUNT
  };

  ObjSyncEgoMotion_t m_ObjSyncEgoMotion;

  static float EMTRAFO_f_GetObjSyncEgoMotionVx (float f_DistY, ObjSyncEgoMotion_t &ObjSyncEgoMotion)
  {
    return ((ObjSyncEgoMotion.Velocity * ObjSyncEgoMotion.f_GlobalObjSyncCosFloatAng) - (ObjSyncEgoMotion.YawRate * (f_DistY - ObjSyncEgoMotion.LatPos)));
  }

  static float EMTRAFO_f_GetObjSyncEgoMotionVy (float f_DistX, ObjSyncEgoMotion_t &ObjSyncEgoMotion)
  {
    return (ObjSyncEgoMotion.YawRate * (f_DistX + ObjSyncEgoMotion.f_GlobalLongPosToRot));
  }

  EMTJA_t_ObjectList_MCAM_V1::EMTJA_t_ObjectList_MCAM   m_BufV1;
  EMTJA_t_ObjectList_MCAM_V1_1::EMTJA_t_ObjectList_MCAM m_BufV1_1;
  EMTJA_t_ObjectList_MCAM_V3::EMTJA_t_ObjectList_MCAM m_BufV3;

  static void InitSigHeader(EMTJA_t_ObjectList_MCAM_V1::SignalHeader_t & SigHeader)
  {
    SigHeader.uiTimeStamp           = 0;
    SigHeader.uiMeasurementCounter  = 0;
    SigHeader.uiCycleCounter        = 0;
    SigHeader.eSigStatus            = EMTJA_t_ObjectList_MCAM_V1::AL_SIG_STATE_INIT;
  };
  static void InitHeader(EMTJA_t_ObjectList_MCAM_V1::EMTJA_t_ObjectListHeader & ObjHeader)
  {
    ObjHeader.f_CamObjAge         = 0.f;
    ObjHeader.e_CamSensorState    = EMTJA_t_ObjectList_MCAM_V1::EMTJA_MCAM_SEN_STATE_UNKNOWN;
    ObjHeader.e_CamDetectionMode  = EMTJA_t_ObjectList_MCAM_V1::EMTJA_MCAM_DETECT_STATE_UNKNOWN;
    ObjHeader.ui_CamNumObjects    = 0u;
    ObjHeader.b_ValidCRC          = 0u;
    ObjHeader.ui_MsgCounter       = 0u;
  };
  static void InitHeader(EMTJA_t_ObjectList_MCAM_V3::EMTJA_t_ObjectListHeader & ObjHeader)
  {
    ObjHeader.f_CamObjAge             = 0.f;
    ObjHeader.e_CamSensorState        = EMTJA_t_ObjectList_MCAM_V1::EMTJA_MCAM_SEN_STATE_UNKNOWN;
    ObjHeader.e_CamDetectionMode      = EMTJA_t_ObjectList_MCAM_V1::EMTJA_MCAM_DETECT_STATE_UNKNOWN;
    ObjHeader.ui_CamNumObjects        = 0u;
    ObjHeader.b_ValidCRC              = 0u;
    ObjHeader.ui_MsgCounter           = 0u;
    ObjHeader.ui_CamObstacleDetected  = 0u;
  };
  static void InitObject(EMTJA_t_ObjectList_MCAM_V1::EMTJA_t_ObjectRecognitionInfo & CamObject)
  {
    CamObject.f_DistX             = 0.f;
    CamObject.f_DistY             = 0.f;
    CamObject.f_VabsX             = 0.f;
    CamObject.f_VabsY             = 0.f;
    CamObject.e_DynamicProperty   = EMTJA_t_ObjectList_MCAM_V1::EMTJA_MCAM_OBJ_DYN_PROP_UNKNOWN;
    CamObject.e_Classification    = EMTJA_t_ObjectList_MCAM_V1::EMTJA_MCAM_OBJ_CLASS_UNCLASSIFIED;
    CamObject.ui_Quality          = 0u;
    CamObject.ui_ID               = 255u;
    CamObject.e_StatusFlashLight  = EMTJA_t_ObjectList_MCAM_V1::EMTJA_MCAM_SFL_UNKNOWN;
    CamObject.ui_Reserved1        = 0;
    CamObject.ui_Reserved2        = 0;
    CamObject.ui_Reserved3        = 0;
  };
  static void InitObject(EMTJA_t_ObjectList_MCAM_V1_1::EMTJA_t_ObjectRecognitionInfo & CamObject)
  {
    CamObject.f_DistX                   = 0.f;
    CamObject.f_DistXStd                = 0.f;
    CamObject.f_DistY                   = 0.f;
    CamObject.f_DistYStd                = 0.f;
    CamObject.f_VabsX                   = 0.f;
    CamObject.f_VabsXStd                = 0.f;
    CamObject.f_VabsY                   = 0.f;
    CamObject.f_VabsYStd                = 0.f;
    CamObject.e_DynamicProperty         = EMTJA_t_ObjectList_MCAM_V1::EMTJA_MCAM_OBJ_DYN_PROP_UNKNOWN;
    CamObject.e_Classification          = EMTJA_t_ObjectList_MCAM_V1::EMTJA_MCAM_OBJ_CLASS_UNCLASSIFIED;
    CamObject.ui_Quality                = 0u;
    CamObject.ui_ID                     = 255u;
    CamObject.e_StatusFlashLight        = EMTJA_t_ObjectList_MCAM_V1::EMTJA_MCAM_SFL_UNKNOWN;
    CamObject.ui_Accuracy               = 0;
    CamObject.eAssociatedLane           = EMTJA_t_ObjectList_MCAM_V1_1::EMTJA_MCAM_OBJ_ASSOC_LANE_UNKNOWN;
    CamObject.uiAssignedLaneLeftQuota   = 0;
    CamObject.uiAssignedLaneRightQuota  = 0;
    CamObject.ui_Reserved1              = 0;
    CamObject.ui_Reserved2              = 0;
    CamObject.ui_Reserved3              = 0;
  };
  static void InitObject(EMTJA_t_ObjectList_MCAM_V3::EMTJA_t_ObjectRecognitionInfo & CamObject)
  {
    CamObject.f_DistX                   = 0.f;
    CamObject.f_DistXStd                = 0.f;
    CamObject.f_DistY                   = 0.f;
    CamObject.f_DistYStd                = 0.f;
    CamObject.f_VrelX                   = 0.f;
    CamObject.f_VrelXStd                = 0.f;
    CamObject.f_VrelY                   = 0.f;
    CamObject.f_VrelYStd                = 0.f;
    CamObject.e_DynamicProperty         = EMTJA_t_ObjectList_MCAM_V1::EMTJA_MCAM_OBJ_DYN_PROP_UNKNOWN;
    CamObject.e_Classification          = EMTJA_t_ObjectList_MCAM_V1::EMTJA_MCAM_OBJ_CLASS_UNCLASSIFIED;
    CamObject.ui_Quality                = 0u;
    CamObject.ui_ID                     = 255u;
    CamObject.e_StatusFlashLight        = EMTJA_t_ObjectList_MCAM_V1::EMTJA_MCAM_SFL_UNKNOWN;
    CamObject.ui_Accuracy               = 0;
    CamObject.eAssociatedLane           = EMTJA_t_ObjectList_MCAM_V1_1::EMTJA_MCAM_OBJ_ASSOC_LANE_UNKNOWN;
    CamObject.uiAssignedLaneLeftQuota   = 0;
    CamObject.uiAssignedLaneRightQuota  = 0;
    CamObject.ui_Reserved1              = 0;
    CamObject.ui_Reserved2              = 0;
    CamObject.ui_Reserved3              = 0;
  };

  static void InitV1(EMTJA_t_ObjectList_MCAM_V1::EMTJA_t_ObjectList_MCAM & ObjList)
  {
    ObjList.u_VersionNumber = 1u;
    InitSigHeader(ObjList.sSigHeader);
    InitHeader(ObjList.objectListHeader);
    for (unsigned int i=0; i<EMTJA_N_MCAM_OBJECTS; i++)
    {
      InitObject(ObjList.a_ObjRecognitionInfo[i]);
    }
  };

  static void InitV1_1(EMTJA_t_ObjectList_MCAM_V1_1::EMTJA_t_ObjectList_MCAM & ObjList)
  {
    ObjList.u_VersionNumber = 1u;
    InitSigHeader(ObjList.sSigHeader);
    InitHeader(ObjList.objectListHeader);
    for (unsigned int i=0; i<EMTJA_N_MCAM_OBJECTS; i++)
    {
      InitObject(ObjList.a_ObjRecognitionInfo[i]);
    }
  };

  static void InitV3(EMTJA_t_ObjectList_MCAM_V3::EMTJA_t_ObjectList_MCAM & ObjList)
  {
    ObjList.u_VersionNumber = 3u;
    InitSigHeader(ObjList.sSigHeader);
    InitHeader(ObjList.objectListHeader);
    for (unsigned int i=0; i<EMTJA_N_MCAM_OBJECTS; i++)
    {
      InitObject(ObjList.a_ObjRecognitionInfo[i]);
    }
  };

  static void ConvertObject(EMTJA_t_ObjectList_MCAM_V1_1::EMTJA_t_ObjectRecognitionInfo & DestObj, const EMTJA_t_ObjectList_MCAM_V1::EMTJA_t_ObjectRecognitionInfo & SrcObj)
  {
    DestObj.f_DistX                   = SrcObj.f_DistX;
    DestObj.f_DistXStd                = 0.f;
    DestObj.f_DistY                   = SrcObj.f_DistY;
    DestObj.f_DistYStd                = 0.f;
    DestObj.f_VabsX                   = SrcObj.f_VabsX;
    DestObj.f_VabsXStd                = 0.f;
    DestObj.f_VabsY                   = SrcObj.f_VabsY;
    DestObj.f_VabsYStd                = 0.f;
    DestObj.e_DynamicProperty         = SrcObj.e_DynamicProperty;
    DestObj.e_Classification          = SrcObj.e_Classification;
    DestObj.ui_Quality                = SrcObj.ui_Quality;
    DestObj.ui_ID                     = SrcObj.ui_ID;
    DestObj.e_StatusFlashLight        = SrcObj.e_StatusFlashLight;
    DestObj.ui_Accuracy               = 0u;
    DestObj.eAssociatedLane           = EMTJA_t_ObjectList_MCAM_V1_1::EMTJA_MCAM_OBJ_ASSOC_LANE_UNKNOWN;
    DestObj.uiAssignedLaneLeftQuota   = 0u;
    DestObj.uiAssignedLaneRightQuota  = 0u;
    DestObj.ui_Reserved1              = SrcObj.ui_Reserved1;
    DestObj.ui_Reserved2              = SrcObj.ui_Reserved2;
    DestObj.ui_Reserved3              = SrcObj.ui_Reserved3;
  };
  static void ConvertObject(EMTJA_t_ObjectList_MCAM_V1::EMTJA_t_ObjectRecognitionInfo & DestObj, const EMTJA_t_ObjectList_MCAM_V1_1::EMTJA_t_ObjectRecognitionInfo & SrcObj)
  {
    DestObj.f_DistX                   = SrcObj.f_DistX;
    DestObj.f_DistY                   = SrcObj.f_DistY;
    DestObj.f_VabsX                   = SrcObj.f_VabsX;
    DestObj.f_VabsY                   = SrcObj.f_VabsY;
    DestObj.e_DynamicProperty         = SrcObj.e_DynamicProperty;
    DestObj.e_Classification          = SrcObj.e_Classification;
    DestObj.ui_Quality                = SrcObj.ui_Quality;
    DestObj.ui_ID                     = SrcObj.ui_ID;
    DestObj.e_StatusFlashLight        = SrcObj.e_StatusFlashLight;
    DestObj.ui_Reserved1              = SrcObj.ui_Reserved1;
    DestObj.ui_Reserved2              = SrcObj.ui_Reserved2;
    DestObj.ui_Reserved3              = SrcObj.ui_Reserved3;
  };
  static void ConvertObject(EMTJA_t_ObjectList_MCAM_V1_1::EMTJA_t_ObjectRecognitionInfo & DestObj, const EMTJA_t_ObjectList_MCAM_V1_1::EMTJA_t_ObjectRecognitionInfo & SrcObj)
  {
    memcpy(&DestObj, &SrcObj, sizeof(DestObj));
  };

  // Conversion addaptation for EMTJA_OBJECT_LIST_MCAM_INTFVER = 0x00000003

  static void ConvertObject(EMTJA_t_ObjectList_MCAM_V1::EMTJA_t_ObjectRecognitionInfo & DestObj, const EMTJA_t_ObjectList_MCAM_V3::EMTJA_t_ObjectRecognitionInfo & SrcObj, ObjSyncEgoMotion_t &ObjSyncEgoMotion)
  {
    DestObj.f_DistX                   = SrcObj.f_DistX;
    DestObj.f_DistY                   = SrcObj.f_DistY;
    DestObj.f_VabsX                   = SrcObj.f_VrelX + EMTRAFO_f_GetObjSyncEgoMotionVx(SrcObj.f_DistY, ObjSyncEgoMotion);
    DestObj.f_VabsY                   = SrcObj.f_VrelY + EMTRAFO_f_GetObjSyncEgoMotionVy(SrcObj.f_DistX, ObjSyncEgoMotion);
    DestObj.e_DynamicProperty         = SrcObj.e_DynamicProperty;
    DestObj.e_Classification          = SrcObj.e_Classification;
    DestObj.ui_Quality                = SrcObj.ui_Quality;
    DestObj.ui_ID                     = SrcObj.ui_ID;
    DestObj.e_StatusFlashLight        = SrcObj.e_StatusFlashLight;
    DestObj.ui_Reserved1              = SrcObj.ui_Reserved1;
    DestObj.ui_Reserved2              = SrcObj.ui_Reserved2;
    DestObj.ui_Reserved3              = SrcObj.ui_Reserved3;
  };

  static void ConvertObject(EMTJA_t_ObjectList_MCAM_V3::EMTJA_t_ObjectRecognitionInfo & DestObj, const EMTJA_t_ObjectList_MCAM_V1::EMTJA_t_ObjectRecognitionInfo & SrcObj, ObjSyncEgoMotion_t &ObjSyncEgoMotion)
  {
    DestObj.f_DistX                   = SrcObj.f_DistX;
    DestObj.f_DistXStd                = 0.f;
    DestObj.f_DistY                   = SrcObj.f_DistY;
    DestObj.f_DistYStd                = 0.f;
    DestObj.f_VrelX                   = SrcObj.f_VabsX - EMTRAFO_f_GetObjSyncEgoMotionVx(SrcObj.f_DistY, ObjSyncEgoMotion);
    DestObj.f_VrelXStd                = 0.f;
    DestObj.f_VrelY                   = SrcObj.f_VabsY - EMTRAFO_f_GetObjSyncEgoMotionVy(SrcObj.f_DistX, ObjSyncEgoMotion);
    DestObj.f_VrelYStd                = 0.f;
    DestObj.e_DynamicProperty         = SrcObj.e_DynamicProperty;
    DestObj.e_Classification          = SrcObj.e_Classification;
    DestObj.ui_Quality                = SrcObj.ui_Quality;
    DestObj.ui_ID                     = SrcObj.ui_ID;
    DestObj.e_StatusFlashLight        = SrcObj.e_StatusFlashLight;
    DestObj.ui_Accuracy               = 0u;
    DestObj.eAssociatedLane           = EMTJA_t_ObjectList_MCAM_V1_1::EMTJA_MCAM_OBJ_ASSOC_LANE_UNKNOWN;
    DestObj.uiAssignedLaneLeftQuota   = 0u;
    DestObj.uiAssignedLaneRightQuota  = 0u;
    DestObj.ui_Reserved1              = SrcObj.ui_Reserved1;
    DestObj.ui_Reserved2              = SrcObj.ui_Reserved2;
    DestObj.ui_Reserved3              = SrcObj.ui_Reserved3;
  };

  static void ConvertObject(EMTJA_t_ObjectList_MCAM_V3::EMTJA_t_ObjectRecognitionInfo & DestObj, const EMTJA_t_ObjectList_MCAM_V1_1::EMTJA_t_ObjectRecognitionInfo & SrcObj, ObjSyncEgoMotion_t &ObjSyncEgoMotion)
  {
    DestObj.f_DistX                   = SrcObj.f_DistX;
    DestObj.f_DistXStd                = 0.f;
    DestObj.f_DistY                   = SrcObj.f_DistY;
    DestObj.f_DistYStd                = 0.f;
    DestObj.f_VrelX                   = SrcObj.f_VabsX - EMTRAFO_f_GetObjSyncEgoMotionVx(SrcObj.f_DistY, ObjSyncEgoMotion);
    DestObj.f_VrelXStd                = 0.f;
    DestObj.f_VrelY                   = SrcObj.f_VabsY - EMTRAFO_f_GetObjSyncEgoMotionVy(SrcObj.f_DistX, ObjSyncEgoMotion);
    DestObj.f_VrelYStd                = 0.f;
    DestObj.e_DynamicProperty         = SrcObj.e_DynamicProperty;
    DestObj.e_Classification          = SrcObj.e_Classification;
    DestObj.ui_Quality                = SrcObj.ui_Quality;
    DestObj.ui_ID                     = SrcObj.ui_ID;
    DestObj.e_StatusFlashLight        = SrcObj.e_StatusFlashLight;
    DestObj.ui_Accuracy               = 0u;
    DestObj.eAssociatedLane           = EMTJA_t_ObjectList_MCAM_V1_1::EMTJA_MCAM_OBJ_ASSOC_LANE_UNKNOWN;
    DestObj.uiAssignedLaneLeftQuota   = 0u;
    DestObj.uiAssignedLaneRightQuota  = 0u;
    DestObj.ui_Reserved1              = SrcObj.ui_Reserved1;
    DestObj.ui_Reserved2              = SrcObj.ui_Reserved2;
    DestObj.ui_Reserved3              = SrcObj.ui_Reserved3;
  };

  static void ConvertObject(EMTJA_t_ObjectList_MCAM_V1_1::EMTJA_t_ObjectRecognitionInfo & DestObj, const EMTJA_t_ObjectList_MCAM_V3::EMTJA_t_ObjectRecognitionInfo & SrcObj, ObjSyncEgoMotion_t &ObjSyncEgoMotion)
  {
    DestObj.f_DistX                   = SrcObj.f_DistX;
    DestObj.f_DistXStd                = 0.f;
    DestObj.f_DistY                   = SrcObj.f_DistY;
    DestObj.f_DistYStd                = 0.f;
    DestObj.f_VabsX                   = SrcObj.f_VrelX + EMTRAFO_f_GetObjSyncEgoMotionVx(SrcObj.f_DistY, ObjSyncEgoMotion);
    DestObj.f_VabsXStd                = 0.f;
    DestObj.f_VabsY                   = SrcObj.f_VrelY + EMTRAFO_f_GetObjSyncEgoMotionVy(SrcObj.f_DistX, ObjSyncEgoMotion);
    DestObj.f_VabsYStd                = 0.f;
    DestObj.e_DynamicProperty         = SrcObj.e_DynamicProperty;
    DestObj.e_Classification          = SrcObj.e_Classification;
    DestObj.ui_Quality                = SrcObj.ui_Quality;
    DestObj.ui_ID                     = SrcObj.ui_ID;
    DestObj.e_StatusFlashLight        = SrcObj.e_StatusFlashLight;
    DestObj.ui_Accuracy               = 0u;
    DestObj.eAssociatedLane           = EMTJA_t_ObjectList_MCAM_V1_1::EMTJA_MCAM_OBJ_ASSOC_LANE_UNKNOWN;
    DestObj.uiAssignedLaneLeftQuota   = 0u;
    DestObj.uiAssignedLaneRightQuota  = 0u;
    DestObj.ui_Reserved1              = SrcObj.ui_Reserved1;
    DestObj.ui_Reserved2              = SrcObj.ui_Reserved2;
    DestObj.ui_Reserved3              = SrcObj.ui_Reserved3;
  };

  static void ConvertObject(EMTJA_t_ObjectList_MCAM_V3::EMTJA_t_ObjectRecognitionInfo & DestObj, const EMTJA_t_ObjectList_MCAM_V3::EMTJA_t_ObjectRecognitionInfo & SrcObj)
  {
    memcpy(&DestObj, &SrcObj, sizeof(DestObj));
  };

  // Conversion addaptation for EMTJA_OBJECT_LIST_MCAM_INTFVER = 0x00000003

  static void Convert(EMTJA_t_ObjectList_MCAM_V1_1::EMTJA_t_ObjectList_MCAM & DestObjList, const EMTJA_t_ObjectList_MCAM_V1::EMTJA_t_ObjectList_MCAM & SrcObjList)
  {
    DestObjList.u_VersionNumber   = 1u;
    DestObjList.sSigHeader        = SrcObjList.sSigHeader;
    DestObjList.objectListHeader  = SrcObjList.objectListHeader;
    for (unsigned int i=0; i<EMTJA_N_MCAM_OBJECTS; i++)
    {
      ConvertObject(DestObjList.a_ObjRecognitionInfo[i], SrcObjList.a_ObjRecognitionInfo[i]);
    }
  };
  static void Convert(EMTJA_t_ObjectList_MCAM_V1::EMTJA_t_ObjectList_MCAM & DestObjList, const EMTJA_t_ObjectList_MCAM_V1_1::EMTJA_t_ObjectList_MCAM & SrcObjList)
  {
    DestObjList.u_VersionNumber   = 1u;
    DestObjList.sSigHeader        = SrcObjList.sSigHeader;
    DestObjList.objectListHeader  = SrcObjList.objectListHeader;
    for (unsigned int i=0; i<EMTJA_N_MCAM_OBJECTS; i++)
    {
      ConvertObject(DestObjList.a_ObjRecognitionInfo[i], SrcObjList.a_ObjRecognitionInfo[i]);
    }
  };
  static void Convert(EMTJA_t_ObjectList_MCAM_V1_1::EMTJA_t_ObjectList_MCAM & DestObjList, const EMTJA_t_ObjectList_MCAM_V1_1_R::EMTJA_t_ObjectList_MCAM & SrcObjList)
  {
    DestObjList.u_VersionNumber = 1u;
    DestObjList.sSigHeader.uiTimeStamp          = SrcObjList.sSigHeader.uiTimeStamp;
    DestObjList.sSigHeader.uiMeasurementCounter = SrcObjList.sSigHeader.uiMeasurementCounter;
    DestObjList.sSigHeader.uiCycleCounter       = SrcObjList.sSigHeader.uiCycleCounter;
    DestObjList.sSigHeader.eSigStatus           = SrcObjList.sSigHeader.eSigStatus;
    DestObjList.objectListHeader = SrcObjList.objectListHeader;
    for (unsigned int i=0; i<EMTJA_N_MCAM_OBJECTS; i++)
    {
      ConvertObject(DestObjList.a_ObjRecognitionInfo[i], SrcObjList.a_ObjRecognitionInfo[i]);
    }
  };
  static void Convert(EMTJA_t_ObjectList_MCAM_V1::EMTJA_t_ObjectList_MCAM & DestObjList, const EMTJA_t_ObjectList_MCAM_V1_1_R::EMTJA_t_ObjectList_MCAM & SrcObjList)
  {
    DestObjList.u_VersionNumber = 1u;
    DestObjList.sSigHeader.uiTimeStamp          = SrcObjList.sSigHeader.uiTimeStamp;
    DestObjList.sSigHeader.uiMeasurementCounter = SrcObjList.sSigHeader.uiMeasurementCounter;
    DestObjList.sSigHeader.uiCycleCounter       = SrcObjList.sSigHeader.uiCycleCounter;
    DestObjList.sSigHeader.eSigStatus           = SrcObjList.sSigHeader.eSigStatus;
    DestObjList.objectListHeader = SrcObjList.objectListHeader;
    for (unsigned int i=0; i<EMTJA_N_MCAM_OBJECTS; i++)
    {
      ConvertObject(DestObjList.a_ObjRecognitionInfo[i], SrcObjList.a_ObjRecognitionInfo[i]);
    }
  };

  static void Convert(EMTJA_t_ObjectList_MCAM_V3::EMTJA_t_ObjectList_MCAM & DestObjList, const EMTJA_t_ObjectList_MCAM_V1_1_R::EMTJA_t_ObjectList_MCAM & SrcObjList, ObjSyncEgoMotion_t &ObjSyncEgoMotion)
  {
    DestObjList.u_VersionNumber = 3u;
    DestObjList.sSigHeader.uiTimeStamp          = SrcObjList.sSigHeader.uiTimeStamp;
    DestObjList.sSigHeader.uiMeasurementCounter = SrcObjList.sSigHeader.uiMeasurementCounter;
    DestObjList.sSigHeader.uiCycleCounter       = SrcObjList.sSigHeader.uiCycleCounter;
    DestObjList.sSigHeader.eSigStatus           = SrcObjList.sSigHeader.eSigStatus;

    //objectListHeader
    DestObjList.objectListHeader.b_ValidCRC              = SrcObjList.objectListHeader.b_ValidCRC;
    DestObjList.objectListHeader.e_CamDetectionMode      = SrcObjList.objectListHeader.e_CamDetectionMode;
    DestObjList.objectListHeader.f_CamObjAge             = SrcObjList.objectListHeader.f_CamObjAge;
    DestObjList.objectListHeader.ui_CamNumObjects        = SrcObjList.objectListHeader.ui_CamNumObjects;
    DestObjList.objectListHeader.ui_MsgCounter           = SrcObjList.objectListHeader.ui_MsgCounter;
    DestObjList.objectListHeader.ui_CamObstacleDetected  = 0U;
    for (unsigned int i=0; i<EMTJA_N_MCAM_OBJECTS; i++)
    {
      ConvertObject(DestObjList.a_ObjRecognitionInfo[i], SrcObjList.a_ObjRecognitionInfo[i], ObjSyncEgoMotion);
    }
  };

  static void Convert(EMTJA_t_ObjectList_MCAM_V3::EMTJA_t_ObjectList_MCAM & DestObjList, const EMTJA_t_ObjectList_MCAM_V1_1::EMTJA_t_ObjectList_MCAM & SrcObjList, ObjSyncEgoMotion_t &ObjSyncEgoMotion)
  {
    DestObjList.u_VersionNumber = 3u;
    DestObjList.sSigHeader                               = SrcObjList.sSigHeader;
    //objectListHeader
    DestObjList.objectListHeader.b_ValidCRC              = SrcObjList.objectListHeader.b_ValidCRC;
    DestObjList.objectListHeader.e_CamDetectionMode      = SrcObjList.objectListHeader.e_CamDetectionMode;
    DestObjList.objectListHeader.f_CamObjAge             = SrcObjList.objectListHeader.f_CamObjAge;
    DestObjList.objectListHeader.ui_CamNumObjects        = SrcObjList.objectListHeader.ui_CamNumObjects;
    DestObjList.objectListHeader.ui_MsgCounter           = SrcObjList.objectListHeader.ui_MsgCounter;
    DestObjList.objectListHeader.ui_CamObstacleDetected  = 0U;

    for (unsigned int i=0; i<EMTJA_N_MCAM_OBJECTS; i++)
    {
      ConvertObject(DestObjList.a_ObjRecognitionInfo[i], SrcObjList.a_ObjRecognitionInfo[i], ObjSyncEgoMotion);
    }
  };


  static void Convert(EMTJA_t_ObjectList_MCAM_V1_1::EMTJA_t_ObjectList_MCAM & DestObjList, const EMTJA_t_ObjectList_MCAM_V3::EMTJA_t_ObjectList_MCAM & SrcObjList, ObjSyncEgoMotion_t &ObjSyncEgoMotion)
  {
    DestObjList.u_VersionNumber = 1u;
    DestObjList.sSigHeader                               = SrcObjList.sSigHeader;
    //objectListHeader
    DestObjList.objectListHeader.b_ValidCRC              = SrcObjList.objectListHeader.b_ValidCRC;
    DestObjList.objectListHeader.e_CamDetectionMode      = SrcObjList.objectListHeader.e_CamDetectionMode;
    DestObjList.objectListHeader.f_CamObjAge             = SrcObjList.objectListHeader.f_CamObjAge;
    DestObjList.objectListHeader.ui_CamNumObjects        = SrcObjList.objectListHeader.ui_CamNumObjects;
    DestObjList.objectListHeader.ui_MsgCounter           = SrcObjList.objectListHeader.ui_MsgCounter;

    for (unsigned int i=0; i<EMTJA_N_MCAM_OBJECTS; i++)
    {
      ConvertObject(DestObjList.a_ObjRecognitionInfo[i], SrcObjList.a_ObjRecognitionInfo[i], ObjSyncEgoMotion);
    }
  };
public:

  static const char *GetConverterTypeName()
  {
    return "EMTJA_t_ObjectList_MCAM";
  };

  CConvEmObjectListMcamTJA(void) : CSimConverterBase(DEP_NAMES, DEP_COUNT), m_ObjSyncEgoMotion(), m_BufV1(), m_BufV1_1(), m_BufV3()
  {
    InitV1(m_BufV1);
    InitV1_1(m_BufV1_1);
    InitV3(m_BufV3);
  };

  virtual ~CConvEmObjectListMcamTJA(void)
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

  static CVersionInfoImpl BASE_VERSION;
  static CVersionInfoImpl VERSION1;
  static CVersionInfoImpl VERSION2;
  static CVersionInfoImpl VERSION3;

  typedef enum eEMTJA_ObjListVersionCount
  {
    EMTJA_T_OBJECTLIST_MCAM_V1,
    EMTJA_T_OBJECTLIST_MCAM_V1_1,
    EMTJA_T_OBJECTLIST_MCAM_V3,
    EMTJA_T_OBJECTLIST_COUNT
  } eEMTJA_ObjListVersionCount;

  static const unsigned long SUPPORTED_SIZE[EMTJA_T_OBJECTLIST_COUNT];

public:
  bool GetDeps (ObjSyncEgoMotion_t &ObjSyncEgoMotion)
  {
    bool bRet = false;
    DepInfo *pValUi = GetDependencyInfo(OBJ_SYNC_EGO_MOTION);
    // retrieve dependency for being used
    if ((pValUi != NULL) && (pValUi->m_pDepData != NULL))
    {
      memcpy (&ObjSyncEgoMotion, pValUi->m_pDepData, sizeof(ObjSyncEgoMotion_t));
      bRet = true;
    }
    else
    {
      memset (&ObjSyncEgoMotion, 0, sizeof(ObjSyncEgoMotion_t));
    }
    return bRet;
  }
};


const char *CConvEmObjectListMcamTJA::DEP_NAMES[] = { "ObjSyncEgoMotion" };

CVersionInfoImpl CConvEmObjectListMcamTJA::BASE_VERSION(0, 0, 0);
CVersionInfoImpl CConvEmObjectListMcamTJA::VERSION1(0, 0, 1);
CVersionInfoImpl CConvEmObjectListMcamTJA::VERSION2(0, 0, 2);
CVersionInfoImpl CConvEmObjectListMcamTJA::VERSION3(0, 0, 3);

const unsigned long CConvEmObjectListMcamTJA::SUPPORTED_SIZE[CConvEmObjectListMcamTJA::EMTJA_T_OBJECTLIST_COUNT] =
{
  sizeof(EMTJA_t_ObjectList_MCAM_V1::EMTJA_t_ObjectList_MCAM),
  sizeof(EMTJA_t_ObjectList_MCAM_V1_1::EMTJA_t_ObjectList_MCAM),
  sizeof(EMTJA_t_ObjectList_MCAM_V3::EMTJA_t_ObjectList_MCAM)
};

long CConvEmObjectListMcamTJA::ConvertData(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
  SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo *pProvidePortVersionInfo,
  void *pPPortData,
  void **pOutData, unsigned long &ulOutSize)
{
  long lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
  const unsigned int uDataVer = ((pPPortData != NULL) && (ulPPortSize >= 4) && (ePPortType == simOPAQUE_t))?(*reinterpret_cast<unsigned int*>(pPPortData)):(0);
  const unsigned int uDataVerR = ((pPPortData != NULL) && (ulPPortSize >= 4) && (ePPortType == simREFERENCE_t))?(*reinterpret_cast<unsigned int*>(pPPortData)):(0);
  CVersionInfoImpl SrcVersion(CONV_I32VERSION_TO_TUPPLE(uDataVer));
  // If no provide port version provided, then use the one extracted from the numeric value
  if (pProvidePortVersionInfo == NULL)
  {
    pProvidePortVersionInfo = &SrcVersion;
  }
  if ((eRPortType == ePPortType) && (ulRPortSize == ulPPortSize) && (requestPortVersionInfo.Equals(pProvidePortVersionInfo)))
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
    if ((ulRPortSize == sizeof(EMTJA_t_ObjectList_MCAM_V1_1::EMTJA_t_ObjectList_MCAM)) && (requestPortVersionInfo.Equals(&VERSION1) || requestPortVersionInfo.Equals(&BASE_VERSION)))
    {
      // Destination port of V1.1
      EMTJA_t_ObjectList_MCAM_V1_1::EMTJA_t_ObjectList_MCAM & Dest = m_BufV1_1;
      if ((ulPPortSize == sizeof(EMTJA_t_ObjectList_MCAM_V1::EMTJA_t_ObjectList_MCAM))
          && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VERSION1)) || (pProvidePortVersionInfo->Equals(&BASE_VERSION)))
          && ((uDataVer == 0x1u) ))
      {
        const EMTJA_t_ObjectList_MCAM_V1::EMTJA_t_ObjectList_MCAM & Src = *reinterpret_cast<EMTJA_t_ObjectList_MCAM_V1::EMTJA_t_ObjectList_MCAM*>(pPPortData);
        Convert(Dest, Src);
        *pOutData = (void*)&Dest;
        ulOutSize = sizeof(Dest);
        lRet = SIM_ERR_OK;
      }
      else if ((ulPPortSize == sizeof(EMTJA_t_ObjectList_MCAM_V3::EMTJA_t_ObjectList_MCAM))
          && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VERSION2)) || (pProvidePortVersionInfo->Equals(&VERSION3)) || (pProvidePortVersionInfo->Equals(&BASE_VERSION)))
          && ((uDataVer == 0x3u) ))
      {
        const EMTJA_t_ObjectList_MCAM_V3::EMTJA_t_ObjectList_MCAM & Src = *reinterpret_cast<EMTJA_t_ObjectList_MCAM_V3::EMTJA_t_ObjectList_MCAM*>(pPPortData);
        GetDeps (m_ObjSyncEgoMotion);
        Convert(Dest, Src, m_ObjSyncEgoMotion);
        *pOutData = (void*)&Dest;
        ulOutSize = sizeof(Dest);
        lRet = SIM_ERR_OK;
      }
      // Data package for the sim_fusion_sync connection (byte aligned structures!)
      else if ((ulPPortSize == sizeof(EMTJA_t_ObjectList_MCAM_V1_1_R::EMTJA_t_ObjectList_MCAM)) &&
        (uDataVerR == 0x1u))
      {
        const EMTJA_t_ObjectList_MCAM_V1_1_R::EMTJA_t_ObjectList_MCAM & Src = *reinterpret_cast<EMTJA_t_ObjectList_MCAM_V1_1_R::EMTJA_t_ObjectList_MCAM*>(pPPortData);
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
    else if ((ulRPortSize == sizeof(EMTJA_t_ObjectList_MCAM_V1::EMTJA_t_ObjectList_MCAM)) && (requestPortVersionInfo.Equals(&VERSION1) || requestPortVersionInfo.Equals(&BASE_VERSION)))
    {
      // Destination port of V1
      EMTJA_t_ObjectList_MCAM_V1::EMTJA_t_ObjectList_MCAM & Dest = m_BufV1;
      if ((ulPPortSize == sizeof(EMTJA_t_ObjectList_MCAM_V1_1::EMTJA_t_ObjectList_MCAM))
          && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VERSION1)) || (pProvidePortVersionInfo->Equals(&BASE_VERSION)))
          && ((uDataVer == 0x1u) ))
      {
        const EMTJA_t_ObjectList_MCAM_V1_1::EMTJA_t_ObjectList_MCAM & Src = *reinterpret_cast<EMTJA_t_ObjectList_MCAM_V1_1::EMTJA_t_ObjectList_MCAM*>(pPPortData);
        Convert(Dest, Src);
        *pOutData = (void*)&Dest;
        ulOutSize = sizeof(Dest);
        lRet = SIM_ERR_OK;
      }
      // Data package for the sim_fusion_sync connection (byte aligned structures!)
      else if ((ulPPortSize == sizeof(EMTJA_t_ObjectList_MCAM_V1_1_R::EMTJA_t_ObjectList_MCAM)) &&
        (uDataVerR == 0x1u))
      {
        const EMTJA_t_ObjectList_MCAM_V1_1_R::EMTJA_t_ObjectList_MCAM & Src = *reinterpret_cast<EMTJA_t_ObjectList_MCAM_V1_1_R::EMTJA_t_ObjectList_MCAM*>(pPPortData);
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
    else if ((ulRPortSize == sizeof(EMTJA_t_ObjectList_MCAM_V3::EMTJA_t_ObjectList_MCAM)) && (requestPortVersionInfo.Equals(&VERSION2) || requestPortVersionInfo.Equals(&VERSION3) || requestPortVersionInfo.Equals(&VERSION1)))
    {
      // Destination port of V3
      EMTJA_t_ObjectList_MCAM_V3::EMTJA_t_ObjectList_MCAM & Dest = m_BufV3;
      if ((ulPPortSize == sizeof(EMTJA_t_ObjectList_MCAM_V1_1::EMTJA_t_ObjectList_MCAM))
          && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VERSION1)) || (pProvidePortVersionInfo->Equals(&BASE_VERSION)))
          && ((uDataVer == 0x1u) ))
      {
        const EMTJA_t_ObjectList_MCAM_V1_1::EMTJA_t_ObjectList_MCAM & Src = *reinterpret_cast<EMTJA_t_ObjectList_MCAM_V1_1::EMTJA_t_ObjectList_MCAM*>(pPPortData);
        GetDeps (m_ObjSyncEgoMotion);
        Convert(Dest, Src, m_ObjSyncEgoMotion);
        *pOutData = (void*)&Dest;
        ulOutSize = sizeof(Dest);
        lRet = SIM_ERR_OK;
      }
      // Data package for the sim_fusion_sync connection (byte aligned structures!)
      else if ((ulPPortSize == sizeof(EMTJA_t_ObjectList_MCAM_V1_1_R::EMTJA_t_ObjectList_MCAM)) &&
        (uDataVerR == 0x1u))
      {
        const EMTJA_t_ObjectList_MCAM_V1_1_R::EMTJA_t_ObjectList_MCAM & Src = *reinterpret_cast<EMTJA_t_ObjectList_MCAM_V1_1_R::EMTJA_t_ObjectList_MCAM*>(pPPortData);
        GetDeps (m_ObjSyncEgoMotion);
        Convert(Dest, Src, m_ObjSyncEgoMotion);
        *pOutData = (void*)&Dest;
        ulOutSize = sizeof(Dest);
        lRet = SIM_ERR_OK;
      }
      else if ((ulPPortSize == sizeof(EMTJA_t_ObjectList_MCAM_V3::EMTJA_t_ObjectList_MCAM)) &&
        requestPortVersionInfo.Equals(&VERSION3) && (uDataVer == 0x2u))
      {
        memcpy (&Dest, pPPortData, sizeof(EMTJA_t_ObjectList_MCAM_V1_1_R::EMTJA_t_ObjectList_MCAM));
        Dest.u_VersionNumber = 3u;
        *pOutData = (void*)&Dest;
        ulOutSize = sizeof(Dest);
        lRet = SIM_ERR_OK;
      }
      else if ((ulPPortSize == sizeof(EMTJA_t_ObjectList_MCAM_V3::EMTJA_t_ObjectList_MCAM)) &&
        requestPortVersionInfo.Equals(&VERSION2) && (uDataVer == 0x3u))
      {
        memcpy (&Dest, pPPortData, sizeof(EMTJA_t_ObjectList_MCAM_V1_1_R::EMTJA_t_ObjectList_MCAM));
        Dest.u_VersionNumber = 3u;
        *pOutData = (void*)&Dest;
        ulOutSize = sizeof(Dest);
        lRet = SIM_ERR_OK;
      }
      else
      {
        lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
      }
    }
  }
  return lRet;
};

/** returns:
 *   SIM_ERR_OK - when this value can be used
 *   SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT - when the default vaule is not implememnted here
 *                                            and the default value from Request Port must be used
 */
long CConvEmObjectListMcamTJA::GetDefaultValue(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
  void **pDefaultData, unsigned long &ulDefaultSize)
{
  long lRet = SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT;
  if (eRPortType == simOPAQUE_t)
  {
    if ((ulRPortSize == sizeof(EMTJA_t_ObjectList_MCAM_V1_1::EMTJA_t_ObjectList_MCAM)) && ( (BASE_VERSION.Equals(&requestPortVersionInfo)) || (VERSION1.Equals(&requestPortVersionInfo)) || (VERSION2.Equals(&requestPortVersionInfo) ) || (VERSION3.Equals(&requestPortVersionInfo) ) ) )
    {
      EMTJA_t_ObjectList_MCAM_V1_1::EMTJA_t_ObjectList_MCAM & Dest = m_BufV1_1;
      InitV1_1(Dest);
      *pDefaultData = &Dest;
      ulDefaultSize = sizeof(Dest);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(EMTJA_t_ObjectList_MCAM_V1::EMTJA_t_ObjectList_MCAM)) && ( (BASE_VERSION.Equals(&requestPortVersionInfo)) || (VERSION1.Equals(&requestPortVersionInfo)) || (VERSION2.Equals(&requestPortVersionInfo) ) || (VERSION3.Equals(&requestPortVersionInfo) ) ) )
    {
      EMTJA_t_ObjectList_MCAM_V1::EMTJA_t_ObjectList_MCAM & Dest = m_BufV1;
      InitV1(Dest);
      *pDefaultData = &Dest;
      ulDefaultSize = sizeof(Dest);
      lRet = SIM_ERR_OK;
    }
    else if ( (ulRPortSize == sizeof(EMTJA_t_ObjectList_MCAM_V3::EMTJA_t_ObjectList_MCAM)) && ( (BASE_VERSION.Equals(&requestPortVersionInfo)) || (VERSION1.Equals(&requestPortVersionInfo)) || (VERSION2.Equals(&requestPortVersionInfo) ) || (VERSION3.Equals(&requestPortVersionInfo) ) ) )
    {
      EMTJA_t_ObjectList_MCAM_V3::EMTJA_t_ObjectList_MCAM & Dest = m_BufV3;
      InitV3(Dest);
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
bool CConvEmObjectListMcamTJA::IsVersionCompatibleWithType(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
  SimPortDataTypes_t ePPortType, unsigned long ulPPortSize)
{
  bool bResult = false;

  // Assume equal ports to be compatible
  if ((eRPortType == ePPortType) && (ulRPortSize == ulPPortSize))
  {
    bResult = true;
  }
  else if ((eRPortType == simOPAQUE_t) && (ePPortType == simOPAQUE_t))
  {
    if ((ulRPortSize == sizeof(EMTJA_t_ObjectList_MCAM_V1_1::EMTJA_t_ObjectList_MCAM)) && (ulPPortSize == sizeof(EMTJA_t_ObjectList_MCAM_V1::EMTJA_t_ObjectList_MCAM)))
    {
      bResult = true;
    }
    else if ((ulRPortSize == sizeof(EMTJA_t_ObjectList_MCAM_V1::EMTJA_t_ObjectList_MCAM)) && (ulPPortSize == sizeof(EMTJA_t_ObjectList_MCAM_V1_1::EMTJA_t_ObjectList_MCAM)))
    {
      bResult = true;
    }
    else if ((ulRPortSize == sizeof(EMTJA_t_ObjectList_MCAM_V1_1::EMTJA_t_ObjectList_MCAM)) && (ulPPortSize == sizeof(EMTJA_t_ObjectList_MCAM_V3::EMTJA_t_ObjectList_MCAM)))
    {
      bResult = true;
    }
    else if ((ulRPortSize == sizeof(EMTJA_t_ObjectList_MCAM_V3::EMTJA_t_ObjectList_MCAM)) && (ulPPortSize == sizeof(EMTJA_t_ObjectList_MCAM_V1_1::EMTJA_t_ObjectList_MCAM)))
    {
      bResult = true;
    }
  }
  // Data package for the sim_fusion_sync connection (byte aligned structures!)
  else if ((eRPortType == simOPAQUE_t) && (ePPortType == simREFERENCE_t))
  {
    if ((ulRPortSize == sizeof(EMTJA_t_ObjectList_MCAM_V1_1::EMTJA_t_ObjectList_MCAM)) || (ulRPortSize == sizeof(EMTJA_t_ObjectList_MCAM_V1::EMTJA_t_ObjectList_MCAM)))
    {
      bResult = true;
    }
    else if ((ulRPortSize == sizeof(EMTJA_t_ObjectList_MCAM_V3::EMTJA_t_ObjectList_MCAM)) || (ulRPortSize == sizeof(EMTJA_t_ObjectList_MCAM_V1_1::EMTJA_t_ObjectList_MCAM)))
    {
      bResult = true;
    }
  }
  return bResult;
}

// used to check if ports are compatible between different versions
bool CConvEmObjectListMcamTJA::AreVersionsCompatible(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
  SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo &providePortVersionInfo)
{
  bool bResult = false;

  // Assume equal ports to be compatible
  if ((eRPortType == ePPortType) && (ulRPortSize == ulPPortSize) && (requestPortVersionInfo.Equals(&providePortVersionInfo)))
  {
    bResult = true;
  }
  else if ((eRPortType == simOPAQUE_t) && (ePPortType == simOPAQUE_t))
  {
    if ((ulRPortSize == sizeof(EMTJA_t_ObjectList_MCAM_V1_1::EMTJA_t_ObjectList_MCAM)) && (ulPPortSize == sizeof(EMTJA_t_ObjectList_MCAM_V1::EMTJA_t_ObjectList_MCAM))
      && ((requestPortVersionInfo.Equals(&VERSION1)) || (requestPortVersionInfo.Equals(&BASE_VERSION)))
      && ((providePortVersionInfo.Equals(&VERSION1)) || (providePortVersionInfo.Equals(&BASE_VERSION))))
    {
      bResult = true;
    }
    else if ((ulRPortSize == sizeof(EMTJA_t_ObjectList_MCAM_V1::EMTJA_t_ObjectList_MCAM)) && (ulPPortSize == sizeof(EMTJA_t_ObjectList_MCAM_V1_1::EMTJA_t_ObjectList_MCAM))
      && ((requestPortVersionInfo.Equals(&VERSION1)) || (requestPortVersionInfo.Equals(&BASE_VERSION)))
      && ((providePortVersionInfo.Equals(&VERSION1)) || (providePortVersionInfo.Equals(&BASE_VERSION))))
    {
      bResult = true;
    }
    else if ((ulRPortSize == sizeof(EMTJA_t_ObjectList_MCAM_V3::EMTJA_t_ObjectList_MCAM)) && (ulPPortSize == sizeof(EMTJA_t_ObjectList_MCAM_V1_1::EMTJA_t_ObjectList_MCAM))
      && ((requestPortVersionInfo.Equals(&VERSION2)) || (requestPortVersionInfo.Equals(&VERSION3)) || (requestPortVersionInfo.Equals(&VERSION1)))
      && ((providePortVersionInfo.Equals(&VERSION2)) || (providePortVersionInfo.Equals(&VERSION3)) || (providePortVersionInfo.Equals(&VERSION1))))
    {
      bResult = true;
    }
  }
  return bResult;
}

//
// Main factory class returning conversion class
//
IConverter * CreateEmObjectListMcamTJAConvClass(void)
{
  return new CConvEmObjectListMcamTJA();
}
