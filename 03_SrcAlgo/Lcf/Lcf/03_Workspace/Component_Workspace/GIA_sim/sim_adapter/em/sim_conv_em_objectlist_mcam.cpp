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
  CHANGES:         $Log: sim_conv_em_objectlist_mcam.cpp  $
  CHANGES:         Revision 1.1 2017/08/10 13:15:06CEST uid34177 
  CHANGES:         Initial revision
  CHANGES:         Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_adapter/em/project.pj
  CHANGES:         Revision 1.2 2014/11/18 16:23:45CET Berndt, Thomas01 (berndtt1) 
  CHANGES:         + Conversion from Byte-Aligned input V1_1_R to V1 and V1_1
  CHANGES:         for the fusion of camera and radar
  CHANGES:         - Added comments -  berndtt1 [Nov 18, 2014 4:25:39 PM CET]
  CHANGES:         Change Package : 281259:1 http://mks-psad:7002/im/viewissue?selection=281259
  CHANGES:         Revision 1.1 2014/04/24 18:59:47CEST Ungvary, Gergely (ungvaryg) 
  CHANGES:         Initial revision
  CHANGES:         Member added to project /nfs/projekte1/PROJECTS/ARS400/06_Algorithm/04_Engineering/03_Workspace/algo/sim_adapter/em/project.pj

**************************************************************************** */
/* includes ---------------------------------------------------------------- */
#include "stdafx.h"
#include "sim_conv_em_objectlist_mcam.h"
#include "sim_versioninfo_impl.h"

// typedef float float32;
//typedef unsigned __int8 boolean/*, uint8*/;
// typedef unsigned __int32 uint32;

static const unsigned int EMT0_N_MCAM_OBJECTS = 12u;

//
// ARS4T0 EMT0_t_ObjectList_MCAM version 1 (taken from rte_type.h revision 1.14.1.5.1.1.1.1.1.13)
//
namespace EMT0_t_ObjectList_MCAM_V1
{
  typedef unsigned __int32 AlgoInterfaceVersionNumber_t     /* Algo interface version nummbers @min:0 @max:4294967295 */ /* [Satisfies_rte sws 1188] */;
  typedef unsigned __int32 AlgoDataTimeStamp_t              /* Algo data time-stamp type (32 bit variant) @min:0 @max:4294967295 */  /* [Satisfies_rte sws 1188] */;
  typedef unsigned __int16 AlgoCycleCounter_t               /* Algo cycle counter @min:0 @max:65535 */  /* [Satisfies_rte sws 1188] */;
  typedef unsigned __int8 AlgoSignalState_t                 /* Algo signal state enumeration @min: 0 @max:2 @values: enum { AL_SIG_STATE_INVALID=2,AL_SIG_STATE_INIT=0,AL_SIG_STATE_OK=1,} */  /* [Satisfies_rte sws 1188] */;
  typedef unsigned __int8 EMT0_t_CamDetectionMode           /* Status of camera object detection @min: 0 @max:2 @values: enum { EMT0_MCAM_DETECT_STATE_UNKNOWN=0,EMT0_MCAM_DETECT_STATE_REDUCED=2,EMT0_MCAM_DETECT_STATE_NORMAL=1,} */	/* [Satisfies_rte sws 1188] */;
  typedef unsigned __int8 EMT0_t_CamSensorState             /* Status of camera @min: 0 @max:3 @values: enum { EMT0_MCAM_SEN_STATE_OK=1,EMT0_MCAM_SEN_STATE_UNKNOWN=0,EMT0_MCAM_SEN_STATE_NOT_OK=2,EMT0_MCAM_SEN_STATE_BLOCKED=3,} */	/* [Satisfies_rte sws 1188] */;
  typedef unsigned __int8 EMT0_t_MCamObjClass               /* This signal indicates the class of the object. @min: 0 @max:7 @values: enum { EMT0_MCAM_OBJ_CLASS_POINT=0,EMT0_MCAM_OBJ_CLASS_BICYCLE=5,EMT0_MCAM_OBJ_CLASS_WIDE=6,EMT0_MCAM_OBJ_CLASS_UNCLASSIFIED=7,EMT0_MCAM_OBJ_CLASS_MOTORCYCLE=4,EMT0_MCAM_OBJ_CLASS_TRUCK=2,EMT0_MCAM_OBJ_CLASS_PEDESTRIAN=3,EMT0_MCAM_OBJ_CLASS_CAR=1,} */	/* [Satisfies_rte sws 1188] */;
  typedef unsigned __int8 EMT0_t_MCamObjDynProp             /* This signal indicates wether the object is moving, stationary or oncoming, based on comparison of the longitudinal relative velocity with the host vehicle velocity. @min: 0 @max:6 @values: enum { EMT0_MCAM_OBJ_DYN_PROP_ONCOMING=2,EMT0_MCAM_OBJ_DYN_PROP_STATIONARY=1,EMT0_MCAM_OBJ_DYN_PROP_CROSSING_RIGHT=4,EMT0_MCAM_OBJ_DYN_PROP_CROSSING_LEFT=3,EMT0_MCAM_OBJ_DYN_PROP_STOPPED=6,EMT0_MCAM_OBJ_DYN_PROP_UNKNOWN=5,EMT0_MCAM_OBJ_DYN_PROP_MOVING=0,} */	/* [Satisfies_rte sws 1188] */;
  typedef unsigned __int8 EMT0_t_ObjFlashLightStat          /* Status of the flash light of the object. @min: 0 @max:255 @values: enum { EMT0_MCAM_SFL_HAZARD_FLASHING=4,EMT0_MCAM_SFL_NO_FLASHING=1,EMT0_MCAM_SFL_FLASHING_LEFT=2,EMT0_MCAM_SFL_FLASHING_RIGHT=3,EMT0_MCAM_SFL_UNKNOWN=0,EMT0_MCAM_SFL_SNA=255,} */	/* [Satisfies_rte sws 1188] */;

  typedef enum eAlgoSignalState_t {
    AL_SIG_STATE_INIT=0,
    AL_SIG_STATE_OK=1,
    AL_SIG_STATE_INVALID=2,
  } eAlgoSignalState_t;

  typedef enum eEMT0_t_CamDetectionMode {
    EMT0_MCAM_DETECT_STATE_UNKNOWN=0,
    EMT0_MCAM_DETECT_STATE_NORMAL=1,
    EMT0_MCAM_DETECT_STATE_REDUCED=2,
  } eEMT0_t_CamDetectionMode;

  typedef enum eEMT0_t_CamSensorState {
    EMT0_MCAM_SEN_STATE_UNKNOWN=0,
    EMT0_MCAM_SEN_STATE_OK=1,
    EMT0_MCAM_SEN_STATE_NOT_OK=2,
    EMT0_MCAM_SEN_STATE_BLOCKED=3,
  } eEMT0_t_CamSensorState;

  typedef enum eEMT0_t_MCamObjClass {
    EMT0_MCAM_OBJ_CLASS_POINT=0,
    EMT0_MCAM_OBJ_CLASS_CAR=1,
    EMT0_MCAM_OBJ_CLASS_TRUCK=2,
    EMT0_MCAM_OBJ_CLASS_PEDESTRIAN=3,
    EMT0_MCAM_OBJ_CLASS_MOTORCYCLE=4,
    EMT0_MCAM_OBJ_CLASS_BICYCLE=5,
    EMT0_MCAM_OBJ_CLASS_WIDE=6,
    EMT0_MCAM_OBJ_CLASS_UNCLASSIFIED=7,
  } eEMT0_t_MCamObjClass;

  typedef enum eEMT0_t_MCamObjDynProp {
    EMT0_MCAM_OBJ_DYN_PROP_MOVING=0,
    EMT0_MCAM_OBJ_DYN_PROP_STATIONARY=1,
    EMT0_MCAM_OBJ_DYN_PROP_ONCOMING=2,
    EMT0_MCAM_OBJ_DYN_PROP_CROSSING_LEFT=3,
    EMT0_MCAM_OBJ_DYN_PROP_CROSSING_RIGHT=4,
    EMT0_MCAM_OBJ_DYN_PROP_UNKNOWN=5,
    EMT0_MCAM_OBJ_DYN_PROP_STOPPED=6,
  } eEMT0_t_MCamObjDynProp;

  typedef enum eEMT0_t_ObjFlashLightStat {
    EMT0_MCAM_SFL_UNKNOWN=0,
    EMT0_MCAM_SFL_NO_FLASHING=1,
    EMT0_MCAM_SFL_FLASHING_LEFT=2,
    EMT0_MCAM_SFL_FLASHING_RIGHT=3,
    EMT0_MCAM_SFL_HAZARD_FLASHING=4,
    EMT0_MCAM_SFL_SNA=255,
  } eEMT0_t_ObjFlashLightStat;

  typedef struct SignalHeader_t                             /* [Satisfies_rte sws 1191] */
  {
    AlgoDataTimeStamp_t uiTimeStamp;
    AlgoCycleCounter_t uiMeasurementCounter;
    AlgoCycleCounter_t uiCycleCounter;
    AlgoSignalState_t eSigStatus;
  } SignalHeader_t;                                         /* Common header for all structured data types */

  typedef struct EMT0_t_ObjectRecognitionInfo
  {
    float f_DistX;
    float f_DistY;
    float f_VabsX;
    float f_VabsY;
    EMT0_t_MCamObjDynProp e_DynamicProperty;
    EMT0_t_MCamObjClass e_Classification;
    unsigned char ui_Quality;
    unsigned char ui_ID;
    EMT0_t_ObjFlashLightStat e_StatusFlashLight;
    unsigned char ui_Reserved1;
    unsigned char ui_Reserved2;
    unsigned char ui_Reserved3;
  } EMT0_t_ObjectRecognitionInfo;

  typedef struct EMT0_t_ObjectListHeader
  {
    float f_CamObjAge;
    EMT0_t_CamSensorState e_CamSensorState;
    EMT0_t_CamDetectionMode e_CamDetectionMode;
    unsigned char ui_CamNumObjects;
    unsigned char b_ValidCRC;
    unsigned char ui_MsgCounter;
    unsigned char ui_Reserved1;
    unsigned char ui_Reserved2;
    unsigned char ui_Reserved3;
  } EMT0_t_ObjectListHeader;

  typedef EMT0_t_ObjectRecognitionInfo EMT0_t_MCamObjArray[EMT0_N_MCAM_OBJECTS];

  typedef struct EMT0_t_ObjectList_MCAM
  {
    AlgoInterfaceVersionNumber_t u_VersionNumber;
    SignalHeader_t sSigHeader;
    EMT0_t_ObjectListHeader objectListHeader;
    EMT0_t_MCamObjArray a_ObjRecognitionInfo;
  } EMT0_t_ObjectList_MCAM;

} // end of namespace EMT0_t_ObjectList_MCAM_V1

//
// ARS4T0 EMT0_t_ObjectList_MCAM version 1.1 (taken from rte_type.h revision 1.24.1.9.1.2)
//
namespace EMT0_t_ObjectList_MCAM_V1_1
{

  typedef unsigned __int8 EMT0_t_CamObjAssociatedLane /* Mapping of the object to a lane @min: 0 @max:255 @values:  */;

  typedef enum eEMT0_t_CamObjAssociatedLane {
    EMT0_MCAM_OBJ_ASSOC_LANE_UNKNOWN=0,
    EMT0_MCAM_OBJ_ASSOC_LANE_EGO=1,
    EMT0_MCAM_OBJ_ASSOC_LANE_LEFT=2,
    EMT0_MCAM_OBJ_ASSOC_LANE_RIGHT=3,
    EMT0_MCAM_OBJ_ASSOC_LANE_OUTSIDE=4,
    EMT0_MCAM_OBJ_ASSOC_LANE_BEYOND_LEFT=5,
    EMT0_MCAM_OBJ_ASSOC_LANE_BEYOND_RIGHT=6,
    EMT0_MCAM_OBJ_ASSOC_LANE_SNA=255,
  } eEMT0_t_CamObjAssociatedLane;

  typedef struct EMT0_t_ObjectRecognitionInfo
  {
    float f_DistX;
    float f_DistY;
    float f_VabsX;
    float f_VabsY;
    EMT0_t_ObjectList_MCAM_V1::EMT0_t_MCamObjDynProp e_DynamicProperty;
    EMT0_t_ObjectList_MCAM_V1::EMT0_t_MCamObjClass e_Classification;
    unsigned char ui_Quality;
    unsigned char ui_ID;
    EMT0_t_ObjectList_MCAM_V1::EMT0_t_ObjFlashLightStat e_StatusFlashLight;
    unsigned char ui_Accuracy;
    EMT0_t_CamObjAssociatedLane eAssociatedLane;
    unsigned char uiAssignedLaneLeftQuota;
    unsigned char uiAssignedLaneRightQuota;
    unsigned char ui_Reserved1;
    unsigned char ui_Reserved2;
    unsigned char ui_Reserved3;
  } EMT0_t_ObjectRecognitionInfo;

  typedef EMT0_t_ObjectRecognitionInfo EMT0_t_MCamObjArray[EMT0_N_MCAM_OBJECTS];

  typedef struct EMT0_t_ObjectList_MCAM
  {
    EMT0_t_ObjectList_MCAM_V1::AlgoInterfaceVersionNumber_t u_VersionNumber;
    EMT0_t_ObjectList_MCAM_V1::SignalHeader_t sSigHeader;
    EMT0_t_ObjectList_MCAM_V1::EMT0_t_ObjectListHeader objectListHeader;
    EMT0_t_MCamObjArray a_ObjRecognitionInfo;
  } EMT0_t_ObjectList_MCAM;

} // end of namespace EMT0_t_ObjectList_MCAM_V1_1

// ARS4xx EMT0_t_ObjectList_MCAM version 1                           Length = 361
// Data package for the sim_fusion_sync connection (byte aligned structures!)
// Always provide port, never receive port!
namespace EMT0_t_ObjectList_MCAM_V1_1_R
{
#pragma pack (push, 1)
  typedef struct SignalHeader_t                             /* [Satisfies_rte sws 1191] */
  {
    EMT0_t_ObjectList_MCAM_V1::AlgoDataTimeStamp_t uiTimeStamp;
    EMT0_t_ObjectList_MCAM_V1::AlgoCycleCounter_t uiMeasurementCounter;
    EMT0_t_ObjectList_MCAM_V1::AlgoCycleCounter_t uiCycleCounter;
    EMT0_t_ObjectList_MCAM_V1::AlgoSignalState_t eSigStatus;
  } SignalHeader_t;                                         /* Common header for all structured data types */

#pragma pack (1)
  typedef EMT0_t_ObjectList_MCAM_V1_1::EMT0_t_ObjectRecognitionInfo EMT0_t_ObjectRecognitionInfo;
#pragma pack (1)
  typedef EMT0_t_ObjectList_MCAM_V1_1::EMT0_t_ObjectRecognitionInfo EMT0_t_MCamObjArray[EMT0_N_MCAM_OBJECTS];

#pragma pack (1)
  typedef struct EMT0_t_ObjectList_MCAM
  {
    EMT0_t_ObjectList_MCAM_V1::AlgoInterfaceVersionNumber_t u_VersionNumber;
    SignalHeader_t sSigHeader;
    EMT0_t_ObjectList_MCAM_V1::EMT0_t_ObjectListHeader objectListHeader;
    EMT0_t_MCamObjArray a_ObjRecognitionInfo;
  } EMT0_t_ObjectList_MCAM;

#pragma pack (pop)
} // end of namespace EMT0_t_ObjectList_MCAM_V1_1_R


class CConvEmObjectListMcam : public CSimConverterBase
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

  EMT0_t_ObjectList_MCAM_V1::EMT0_t_ObjectList_MCAM   m_BufV1;
  EMT0_t_ObjectList_MCAM_V1_1::EMT0_t_ObjectList_MCAM m_BufV1_1;

  static void InitSigHeader(EMT0_t_ObjectList_MCAM_V1::SignalHeader_t & SigHeader)
  {
    SigHeader.uiTimeStamp           = 0;
    SigHeader.uiMeasurementCounter  = 0;
    SigHeader.uiCycleCounter        = 0;
    SigHeader.eSigStatus            = EMT0_t_ObjectList_MCAM_V1::AL_SIG_STATE_INIT;
  };
  static void InitHeader(EMT0_t_ObjectList_MCAM_V1::EMT0_t_ObjectListHeader & ObjHeader)
  {
    ObjHeader.f_CamObjAge         = 0.f;
    ObjHeader.e_CamSensorState    = EMT0_t_ObjectList_MCAM_V1::EMT0_MCAM_SEN_STATE_UNKNOWN;
    ObjHeader.e_CamDetectionMode  = EMT0_t_ObjectList_MCAM_V1::EMT0_MCAM_DETECT_STATE_UNKNOWN;
    ObjHeader.ui_CamNumObjects    = 0u;
    ObjHeader.b_ValidCRC          = 0u;
    ObjHeader.ui_MsgCounter       = 0u;
  };
  static void InitObject(EMT0_t_ObjectList_MCAM_V1::EMT0_t_ObjectRecognitionInfo & CamObject)
  {
    CamObject.f_DistX             = 0.f;
    CamObject.f_DistY             = 0.f;
    CamObject.f_VabsX             = 0.f;
    CamObject.f_VabsY             = 0.f;
    CamObject.e_DynamicProperty   = EMT0_t_ObjectList_MCAM_V1::EMT0_MCAM_OBJ_DYN_PROP_UNKNOWN;
    CamObject.e_Classification    = EMT0_t_ObjectList_MCAM_V1::EMT0_MCAM_OBJ_CLASS_UNCLASSIFIED;
    CamObject.ui_Quality          = 0u;
    CamObject.ui_ID               = 63u;
    CamObject.e_StatusFlashLight  = EMT0_t_ObjectList_MCAM_V1::EMT0_MCAM_SFL_UNKNOWN;
    CamObject.ui_Reserved1        = 0;
    CamObject.ui_Reserved2        = 0;
    CamObject.ui_Reserved3        = 0;
  };
  static void InitObject(EMT0_t_ObjectList_MCAM_V1_1::EMT0_t_ObjectRecognitionInfo & CamObject)
  {
    CamObject.f_DistX                   = 0.f;
    CamObject.f_DistY                   = 0.f;
    CamObject.f_VabsX                   = 0.f;
    CamObject.f_VabsY                   = 0.f;
    CamObject.e_DynamicProperty         = EMT0_t_ObjectList_MCAM_V1::EMT0_MCAM_OBJ_DYN_PROP_UNKNOWN;
    CamObject.e_Classification          = EMT0_t_ObjectList_MCAM_V1::EMT0_MCAM_OBJ_CLASS_UNCLASSIFIED;
    CamObject.ui_Quality                = 0u;
    CamObject.ui_ID                     = 63u;
    CamObject.e_StatusFlashLight        = EMT0_t_ObjectList_MCAM_V1::EMT0_MCAM_SFL_UNKNOWN;
    CamObject.ui_Accuracy               = 0;
    CamObject.eAssociatedLane           = EMT0_t_ObjectList_MCAM_V1_1::EMT0_MCAM_OBJ_ASSOC_LANE_UNKNOWN;
    CamObject.uiAssignedLaneLeftQuota   = 0;
    CamObject.uiAssignedLaneRightQuota  = 0;
    CamObject.ui_Reserved1              = 0;
    CamObject.ui_Reserved2              = 0;
    CamObject.ui_Reserved3              = 0;
  };
  static void InitV1(EMT0_t_ObjectList_MCAM_V1::EMT0_t_ObjectList_MCAM & ObjList)
  {
    ObjList.u_VersionNumber = 1u;
    InitSigHeader(ObjList.sSigHeader);
    InitHeader(ObjList.objectListHeader);
    for (unsigned int i=0; i<EMT0_N_MCAM_OBJECTS; i++)
    {
      InitObject(ObjList.a_ObjRecognitionInfo[i]);
    }
  };
  static void InitV1_1(EMT0_t_ObjectList_MCAM_V1_1::EMT0_t_ObjectList_MCAM & ObjList)
  {
    ObjList.u_VersionNumber = 1u;
    InitSigHeader(ObjList.sSigHeader);
    InitHeader(ObjList.objectListHeader);
    for (unsigned int i=0; i<EMT0_N_MCAM_OBJECTS; i++)
    {
      InitObject(ObjList.a_ObjRecognitionInfo[i]);
    }
  };
  static void ConvertObject(EMT0_t_ObjectList_MCAM_V1_1::EMT0_t_ObjectRecognitionInfo & DestObj, const EMT0_t_ObjectList_MCAM_V1::EMT0_t_ObjectRecognitionInfo & SrcObj)
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
    DestObj.ui_Accuracy               = 0u;
    DestObj.eAssociatedLane           = EMT0_t_ObjectList_MCAM_V1_1::EMT0_MCAM_OBJ_ASSOC_LANE_UNKNOWN;
    DestObj.uiAssignedLaneLeftQuota   = 0u;
    DestObj.uiAssignedLaneRightQuota  = 0u;
    DestObj.ui_Reserved1              = SrcObj.ui_Reserved1;
    DestObj.ui_Reserved2              = SrcObj.ui_Reserved2;
    DestObj.ui_Reserved3              = SrcObj.ui_Reserved3;
  };
  static void ConvertObject(EMT0_t_ObjectList_MCAM_V1::EMT0_t_ObjectRecognitionInfo & DestObj, const EMT0_t_ObjectList_MCAM_V1_1::EMT0_t_ObjectRecognitionInfo & SrcObj)
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
  static void ConvertObject(EMT0_t_ObjectList_MCAM_V1_1::EMT0_t_ObjectRecognitionInfo & DestObj, const EMT0_t_ObjectList_MCAM_V1_1::EMT0_t_ObjectRecognitionInfo & SrcObj)
  {
    memcpy(&DestObj, &SrcObj, sizeof(DestObj));
  };
  static void Convert(EMT0_t_ObjectList_MCAM_V1_1::EMT0_t_ObjectList_MCAM & DestObjList, const EMT0_t_ObjectList_MCAM_V1::EMT0_t_ObjectList_MCAM & SrcObjList)
  {
    DestObjList.u_VersionNumber   = 1u;
    DestObjList.sSigHeader        = SrcObjList.sSigHeader;
    DestObjList.objectListHeader  = SrcObjList.objectListHeader;
    for (unsigned int i=0; i<EMT0_N_MCAM_OBJECTS; i++)
    {
      ConvertObject(DestObjList.a_ObjRecognitionInfo[i], SrcObjList.a_ObjRecognitionInfo[i]);
    }
  };
  static void Convert(EMT0_t_ObjectList_MCAM_V1::EMT0_t_ObjectList_MCAM & DestObjList, const EMT0_t_ObjectList_MCAM_V1_1::EMT0_t_ObjectList_MCAM & SrcObjList)
  {
    DestObjList.u_VersionNumber   = 1u;
    DestObjList.sSigHeader        = SrcObjList.sSigHeader;
    DestObjList.objectListHeader  = SrcObjList.objectListHeader;
    for (unsigned int i=0; i<EMT0_N_MCAM_OBJECTS; i++)
    {
      ConvertObject(DestObjList.a_ObjRecognitionInfo[i], SrcObjList.a_ObjRecognitionInfo[i]);
    }
  };
  static void Convert(EMT0_t_ObjectList_MCAM_V1_1::EMT0_t_ObjectList_MCAM & DestObjList, const EMT0_t_ObjectList_MCAM_V1_1_R::EMT0_t_ObjectList_MCAM & SrcObjList)
  {
    DestObjList.u_VersionNumber = 1u;
    DestObjList.sSigHeader.uiTimeStamp          = SrcObjList.sSigHeader.uiTimeStamp;
    DestObjList.sSigHeader.uiMeasurementCounter = SrcObjList.sSigHeader.uiMeasurementCounter;
    DestObjList.sSigHeader.uiCycleCounter       = SrcObjList.sSigHeader.uiCycleCounter;
    DestObjList.sSigHeader.eSigStatus           = SrcObjList.sSigHeader.eSigStatus;
    DestObjList.objectListHeader = SrcObjList.objectListHeader;
    for (unsigned int i=0; i<EMT0_N_MCAM_OBJECTS; i++)
    {
      ConvertObject(DestObjList.a_ObjRecognitionInfo[i], SrcObjList.a_ObjRecognitionInfo[i]);
    }
  };
  static void Convert(EMT0_t_ObjectList_MCAM_V1::EMT0_t_ObjectList_MCAM & DestObjList, const EMT0_t_ObjectList_MCAM_V1_1_R::EMT0_t_ObjectList_MCAM & SrcObjList)
  {
    DestObjList.u_VersionNumber = 1u;
    DestObjList.sSigHeader.uiTimeStamp          = SrcObjList.sSigHeader.uiTimeStamp;
    DestObjList.sSigHeader.uiMeasurementCounter = SrcObjList.sSigHeader.uiMeasurementCounter;
    DestObjList.sSigHeader.uiCycleCounter       = SrcObjList.sSigHeader.uiCycleCounter;
    DestObjList.sSigHeader.eSigStatus           = SrcObjList.sSigHeader.eSigStatus;
    DestObjList.objectListHeader = SrcObjList.objectListHeader;
    for (unsigned int i=0; i<EMT0_N_MCAM_OBJECTS; i++)
    {
      ConvertObject(DestObjList.a_ObjRecognitionInfo[i], SrcObjList.a_ObjRecognitionInfo[i]);
    }
  };

public:

  static const char *GetConverterTypeName()
  {
    return "CamObjInputData";
  };

  CConvEmObjectListMcam(void) : CSimConverterBase(NULL/*DEP_NAMES*/, DEP_COUNT), m_BufV1(), m_BufV1_1()
  {
    InitV1(m_BufV1);
    InitV1_1(m_BufV1_1);
  };

  virtual ~CConvEmObjectListMcam(void)
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

  typedef enum eEMT0_ObjListVersionCount
  {
    EMT0_T_OBJECTLIST_MCAM_V1,
    EMT0_T_OBJECTLIST_MCAM_V1_1,
    EMT0_T_OBJECTLIST_COUNT
  } eEMT0_ObjListVersionCount;

  static const unsigned long SUPPORTED_SIZE[EMT0_T_OBJECTLIST_COUNT];

};

CVersionInfoImpl CConvEmObjectListMcam::BASE_VERSION(0, 0, 0);
CVersionInfoImpl CConvEmObjectListMcam::VERSION1(0, 0, 1);

const unsigned long CConvEmObjectListMcam::SUPPORTED_SIZE[CConvEmObjectListMcam::EMT0_T_OBJECTLIST_COUNT] =
{
  sizeof(EMT0_t_ObjectList_MCAM_V1::EMT0_t_ObjectList_MCAM),
  sizeof(EMT0_t_ObjectList_MCAM_V1_1::EMT0_t_ObjectList_MCAM)
};

long CConvEmObjectListMcam::ConvertData(
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
    if ((ulRPortSize == sizeof(EMT0_t_ObjectList_MCAM_V1_1::EMT0_t_ObjectList_MCAM)) && (requestPortVersionInfo.Equals(&VERSION1) || requestPortVersionInfo.Equals(&BASE_VERSION)))
    {
      // Destination port of V1.1
      EMT0_t_ObjectList_MCAM_V1_1::EMT0_t_ObjectList_MCAM & Dest = m_BufV1_1;
      if ((ulPPortSize == sizeof(EMT0_t_ObjectList_MCAM_V1::EMT0_t_ObjectList_MCAM))
          && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VERSION1)) || (pProvidePortVersionInfo->Equals(&BASE_VERSION)))
          && ((uDataVer == 0x1u) ))
      {
        const EMT0_t_ObjectList_MCAM_V1::EMT0_t_ObjectList_MCAM & Src = *reinterpret_cast<EMT0_t_ObjectList_MCAM_V1::EMT0_t_ObjectList_MCAM*>(pPPortData);
        Convert(Dest, Src);
        *pOutData = (void*)&Dest;
        ulOutSize = sizeof(Dest);
        lRet = SIM_ERR_OK;
      }
      // Data package for the sim_fusion_sync connection (byte aligned structures!)
      else if ((ulPPortSize == sizeof(EMT0_t_ObjectList_MCAM_V1_1_R::EMT0_t_ObjectList_MCAM)) &&
        (uDataVerR == 0x1u))
      {
        const EMT0_t_ObjectList_MCAM_V1_1_R::EMT0_t_ObjectList_MCAM & Src = *reinterpret_cast<EMT0_t_ObjectList_MCAM_V1_1_R::EMT0_t_ObjectList_MCAM*>(pPPortData);
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
    else if ((ulRPortSize == sizeof(EMT0_t_ObjectList_MCAM_V1::EMT0_t_ObjectList_MCAM)) && (requestPortVersionInfo.Equals(&VERSION1) || requestPortVersionInfo.Equals(&BASE_VERSION)))
    {
      // Destination port of V1
      EMT0_t_ObjectList_MCAM_V1::EMT0_t_ObjectList_MCAM & Dest = m_BufV1;
      if ((ulPPortSize == sizeof(EMT0_t_ObjectList_MCAM_V1_1::EMT0_t_ObjectList_MCAM))
          && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VERSION1)) || (pProvidePortVersionInfo->Equals(&BASE_VERSION)))
          && ((uDataVer == 0x1u) ))
      {
        const EMT0_t_ObjectList_MCAM_V1_1::EMT0_t_ObjectList_MCAM & Src = *reinterpret_cast<EMT0_t_ObjectList_MCAM_V1_1::EMT0_t_ObjectList_MCAM*>(pPPortData);
        Convert(Dest, Src);
        *pOutData = (void*)&Dest;
        ulOutSize = sizeof(Dest);
        lRet = SIM_ERR_OK;
      }
      // Data package for the sim_fusion_sync connection (byte aligned structures!)
      else if ((ulPPortSize == sizeof(EMT0_t_ObjectList_MCAM_V1_1_R::EMT0_t_ObjectList_MCAM)) &&
        (uDataVerR == 0x1u))
      {
        const EMT0_t_ObjectList_MCAM_V1_1_R::EMT0_t_ObjectList_MCAM & Src = *reinterpret_cast<EMT0_t_ObjectList_MCAM_V1_1_R::EMT0_t_ObjectList_MCAM*>(pPPortData);
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
  }
  return lRet;
};

/** returns:
 *   SIM_ERR_OK - when this value can be used
 *   SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT - when the default vaule is not implememnted here
 *                                            and the default value from Request Port must be used
 */
long CConvEmObjectListMcam::GetDefaultValue(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
  void **pDefaultData, unsigned long &ulDefaultSize)
{
  long lRet = SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT;
  if (eRPortType == simOPAQUE_t)
  {
    if ((ulRPortSize == sizeof(EMT0_t_ObjectList_MCAM_V1_1::EMT0_t_ObjectList_MCAM)) && ((BASE_VERSION.Equals(&requestPortVersionInfo)) || (VERSION1.Equals(&requestPortVersionInfo))))
    {
      EMT0_t_ObjectList_MCAM_V1_1::EMT0_t_ObjectList_MCAM & Dest = m_BufV1_1;
      InitV1_1(Dest);
      *pDefaultData = &Dest;
      ulDefaultSize = sizeof(Dest);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(EMT0_t_ObjectList_MCAM_V1::EMT0_t_ObjectList_MCAM)) && ((BASE_VERSION.Equals(&requestPortVersionInfo)) || (VERSION1.Equals(&requestPortVersionInfo))))
    {
      EMT0_t_ObjectList_MCAM_V1::EMT0_t_ObjectList_MCAM & Dest = m_BufV1;
      InitV1(Dest);
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
bool CConvEmObjectListMcam::IsVersionCompatibleWithType(
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
    if ((ulRPortSize == sizeof(EMT0_t_ObjectList_MCAM_V1_1::EMT0_t_ObjectList_MCAM)) && (ulPPortSize == sizeof(EMT0_t_ObjectList_MCAM_V1::EMT0_t_ObjectList_MCAM)))
    {
      bResult = true;
    }
    else if ((ulRPortSize == sizeof(EMT0_t_ObjectList_MCAM_V1::EMT0_t_ObjectList_MCAM)) && (ulPPortSize == sizeof(EMT0_t_ObjectList_MCAM_V1_1::EMT0_t_ObjectList_MCAM)))
    {
      bResult = true;
    }
  }
  // Data package for the sim_fusion_sync connection (byte aligned structures!)
  else if ((eRPortType == simOPAQUE_t) && (ePPortType == simREFERENCE_t))
  {
    if ((ulRPortSize == sizeof(EMT0_t_ObjectList_MCAM_V1_1::EMT0_t_ObjectList_MCAM)) || (ulRPortSize == sizeof(EMT0_t_ObjectList_MCAM_V1::EMT0_t_ObjectList_MCAM)))
    {
      bResult = true;
    }
  }
  return bResult;
}

// used to check if ports are compatible between different versions
bool CConvEmObjectListMcam::AreVersionsCompatible(
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
    if ((ulRPortSize == sizeof(EMT0_t_ObjectList_MCAM_V1_1::EMT0_t_ObjectList_MCAM)) && (ulPPortSize == sizeof(EMT0_t_ObjectList_MCAM_V1::EMT0_t_ObjectList_MCAM))
      && ((requestPortVersionInfo.Equals(&VERSION1)) || (requestPortVersionInfo.Equals(&BASE_VERSION)))
      && ((providePortVersionInfo.Equals(&VERSION1)) || (providePortVersionInfo.Equals(&BASE_VERSION))))
    {
      bResult = true;
    }
    else if ((ulRPortSize == sizeof(EMT0_t_ObjectList_MCAM_V1::EMT0_t_ObjectList_MCAM)) && (ulPPortSize == sizeof(EMT0_t_ObjectList_MCAM_V1_1::EMT0_t_ObjectList_MCAM))
      && ((requestPortVersionInfo.Equals(&VERSION1)) || (requestPortVersionInfo.Equals(&BASE_VERSION)))
      && ((providePortVersionInfo.Equals(&VERSION1)) || (providePortVersionInfo.Equals(&BASE_VERSION))))
    {
      bResult = true;
    }
  }
  return bResult;
}

//
// Main factory class returning conversion class
//
IConverter * CreateEmObjectListMcamConvClass(void)
{
  return new CConvEmObjectListMcam();
}
