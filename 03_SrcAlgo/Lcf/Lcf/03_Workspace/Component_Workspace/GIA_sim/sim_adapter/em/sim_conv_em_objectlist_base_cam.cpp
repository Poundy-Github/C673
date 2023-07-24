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
  CHANGES:         $Log: sim_conv_em_objectlist_base_cam.cpp  $
  CHANGES:         Revision 1.1 2017/08/10 13:15:03CEST uid34177 
  CHANGES:         Initial revision
  CHANGES:         Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_adapter/em/project.pj
  CHANGES:         Revision 1.1 2016/10/17 11:49:39CEST Kubera, David (kuberad) 
  CHANGES:         Initial revision
  CHANGES:         Member added to project /nfs/projekte1/REPOSITORY/Function_Projects/EUNCAP18/06_Algorithm/04_Engineering/03_Workspace/algo/sim_adapter/em/project.pj
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
//#include "emlib_coord_trafo.h"

// typedef float float32;
//typedef unsigned __int8 boolean/*, uint8*/;
// typedef unsigned __int32 uint32;

static const unsigned int EM_N_CAM_OBJECTS = 12u;
static const unsigned int EM_BASE_CAM_SHAPEPOINT_ARRAY_SIZE = 4u;

//
// ARS4T0 EMTJA_t_ObjectList_MCAM version 1
//

namespace EM_BASE_t_ObjectList_CAM_V2
{

  typedef unsigned __int32 AlgoInterfaceVersionNumber_t     /* Algo interface version nummbers @min:0 @max:4294967295 */ /* [Satisfies_rte sws 1188] */;
  typedef unsigned __int32 AlgoDataTimeStamp_t              /* Algo data time-stamp type (32 bit variant) @min:0 @max:4294967295 */  /* [Satisfies_rte sws 1188] */;
  typedef unsigned __int16 AlgoCycleCounter_t               /* Algo cycle counter @min:0 @max:65535 */  /* [Satisfies_rte sws 1188] */;
  typedef unsigned __int8  AlgoSignalState_t                 /* Algo signal state enumeration @min: 0 @max:2 @values: enum { AL_SIG_STATE_INVALID=2,AL_SIG_STATE_INIT=0,AL_SIG_STATE_OK=1,} */  /* [Satisfies_rte sws 1188] */;
  typedef unsigned __int8  EMBase_t_CamSensorState            /* Status of camera @min: 0 @max:7 @values: enum { EMBASE_CAM_SEN_STATE_NOT_OK=1,EMBASE_CAM_SEN_STATE_BLOCKED=4,INVALID=7,EMBASE_CAM_SEN_STATE_OK=2,EMBASE_CAM_SEN_STATE_UNKNOWN=0,EMBASE_CAM_SEN_STATE_REDUCED=3,} */	/* [Satisfies_rte sws 1188] */;
  typedef unsigned __int8  EM_t_CamObjStatusBrakeLight /* Status of brake light detection @min: 0 @max:255 @values: enum { EM_CAM_OBJ_BRAKE_LIGHT_NO_BRAKING=1,EM_CAM_OBJ_BRAKE_LIGHT_HEAVY_BREAKING=3,EM_CAM_OBJ_BRAKE_LIGHT_UNKNOWN=0,EM_CAM_OBJ_BRAKE_LIGHT_SNA=255,EM_CAM_OBJ_BRAKE_LIGHT_REGULAR_BRAKING=2,} */	/* [Satisfies_rte sws 1188] */;
  typedef unsigned __int8  EM_t_CamObjStatusFlashLight /* Status of flash light detection @min: 0 @max:255 @values: enum { EM_CAM_OBJ_FLASH_LIGHT_UNKNOWN=0,EM_CAM_OBJ_FLASH_LIGHT_FLASHING_LEFT=2,EM_CAM_OBJ_FLASH_LIGHT_HAZARD_FLASHING=4,EM_CAM_OBJ_FLASH_LIGHT_FLASHING_RIGHT=3,EM_CAM_OBJ_FLASH_LIGHT_SNA=255,EM_CAM_OBJ_FLASH_LIGHT_NO_FLASHING=1,} */	/* [Satisfies_rte sws 1188] */;
  typedef unsigned __int8  EM_t_CamObjAssociatedLane         /* Lane enumeration @min: 0 @max:5 @values: enum { ASSOC_LANE_LEFT=2,ASSOC_LANE_FAR_RIGHT=5,ASSOC_LANE_FAR_LEFT=1,ASSOC_LANE_UNKNOWN=0,ASSOC_LANE_RIGHT=4,ASSOC_LANE_EGO=3,} */	/* [Satisfies_rte sws 1188] */;
  typedef unsigned __int8  EM_t_CamObjLaneChange     /* Object lane change maneuver in respect to the objects associated lane. @min: 0 @max:4 @values: enum { EM_CAM_OBJ_LANE_CHANGE_CUT_IN_LEFT=4,EM_CAM_OBJ_LANE_CHANGE_CUT_OUT_LEFT=2,EM_CAM_OBJ_LANE_CHANGE_CUT_IN_RIGHT=3,EM_CAM_OBJ_LANE_CHANGE_NONE=0,EM_CAM_OBJ_LANE_CHANGE_CUT_OUT_RIGHT=1,} */	/* [Satisfies_rte sws 1188] */;
  typedef unsigned __int8 EM_t_GenObjShapePointState /* State of shape point at index @min: 0 @max:4 @values: enum { EM_GEN_OBJECT_SHAPE_POINT_STATE_EDGE_MEASURED=1,EM_GEN_OBJECT_SHAPE_POINT_STATE_INVALID=0,EM_GEN_OBJECT_SHAPE_POINT_STATE_VISIBILITY_EDGE=3,EM_GEN_OBJECT_SHAPE_POINT_STATE_EDGE_ASSUMED=2,EM_GEN_OBJECT_SHAPE_POINT_STATE_MAX_DIFF_TYPES=4,} */	/* [Satisfies_rte sws 1188] */; 
  typedef unsigned __int8 EM_t_GenObjDynamicProperty /* This signal indicates wether the object is moving, stationary or oncoming, based on comparison of the longitudinal relative velocity with the host vehicle velocity. @min: 0 @max:7 @values: enum { EM_GEN_OBJECT_DYN_PROPERTY_CROSSING_LEFT=3,EM_GEN_OBJECT_DYN_PROPERTY_STOPPED=6,EM_GEN_OBJECT_DYN_PROPERTY_CROSSING_RIGHT=4,EM_GEN_OBJECT_DYN_PROPERTY_MOVING=0,EM_GEN_OBJECT_DYN_PROPERTY_ONCOMING=2,EM_GEN_OBJECT_DYN_PROPERTY_STATIONARY=1,EM_GEN_OBJECT_DYN_PROPERTY_UNKNOWN=5,EM_GEN_OBJECT_DYN_PROPERTY_MAX_DIFF_TYPES=7,} */	/* [Satisfies_rte sws 1188] */;
  typedef unsigned __int8 EM_t_GenObjClassification /* This signal indicates the class of the object. Optimizes for ACC function. Classification limitation especially for pedestrians and bicycles @min: 0 @max:9 @values: enum { EM_GEN_OBJECT_CLASS_TRUCK=2,EM_GEN_OBJECT_CLASS_MAX_DIFF_TYPES=9,EM_GEN_OBJECT_CLASS_WIDE=6,EM_GEN_OBJECT_CLASS_PEDESTRIAN=3,EM_GEN_OBJECT_CLASS_CAR=1,EM_GEN_OBJECT_CLASS_POINT=0,EM_GEN_OBJECT_CLASS_BICYCLE=5,EM_GEN_OBJECT_CLASS_TL=8,EM_GEN_OBJECT_CLASS_MOTORCYCLE=4,EM_GEN_OBJECT_CLASS_UNCLASSIFIED=7,} */	/* [Satisfies_rte sws 1188] */;
  typedef unsigned __int8 EM_t_GenObjOcclusionState /* Describes if/how Object is covered by closer objects in sensing direction. @min: 0 @max:4 @values: enum { EM_GEN_OBJECT_OCCL_PARTLY=2,EM_GEN_OBJECT_OCCL_FULL=3,EM_GEN_OBJECT_OCCL_NONE=0,EM_GEN_OBJECT_OCCL_MAX_DIFF_TYPES=4,EM_GEN_OBJECT_OCCL_UNKNOWN=1,} */	/* [Satisfies_rte sws 1188] */;
  typedef unsigned __int8 EM_t_GenObjMaintenanceState /* Indicate the adminstration state of object @min: 0 @max:5 @values: enum { EM_GEN_OBJECT_MT_STATE_PREDICTED=3,EM_GEN_OBJECT_MT_STATE_DELETED=0,EM_GEN_OBJECT_MT_STATE_INACTIVE=4,EM_GEN_OBJECT_MT_STATE_MEASURED=2,EM_GEN_OBJECT_MT_STATE_NEW=1,EM_GEN_OBJECT_MT_STATE_MAX_DIFF_TYPES=5,} */	/* [Satisfies_rte sws 1188] */;
  typedef unsigned __int8 EM_t_GenObjSensorSource   /* Bitfield for a combination of given enum values to point out what sensor participated at measurement of the object. The object assocaition shall consider different acquisition times and  expected update cycles (properly avoid toggling) @min: 0 @max:128 @values: enum { EM_GEN_OBJECT_MS_NONE=0,EM_GEN_OBJECT_MS_LRR=1,EM_GEN_OBJECT_MS_SRR=4,EM_GEN_OBJECT_MS_HFL=64,EM_GEN_OBJECT_MS_MRR=2,EM_GEN_OBJECT_MS_IR=128,EM_GEN_OBJECT_MS_CAM=16,EM_GEN_OBJECT_MS_SRL=8,EM_GEN_OBJECT_MS_USN=32,} */	/* [Satisfies_rte sws 1188] */; 
  typedef unsigned __int16 EM_t_GenEbaInhibit        /* Bitfield for Inhibition of eba function activations @min: 0 @max:65535 @values: enum { FPS_EBA_INH_BRAKE_L3=512,FPS_EBA_INH_PRE_WARN=2,FPS_EBA_INH_HBA_TBRK=32,FPS_EBA_INH_NONE=0,FPS_EBA_INH_HBA_THRD=16,FPS_EBA_INH_BRAKE_L1=128,FPS_EBA_INH_ALL=65535,FPS_EBA_INH_LAT_WARN=1,FPS_EBA_INH_ACU_WARN=4,FPS_EBA_INH_BRAKE_L2=256,FPS_EBA_INH_PRE_FILL=8,FPS_EBA_INH_PRECRASH=64,} */	/* [Satisfies_rte sws 1188] */;

  typedef enum eEM_t_GenEbaInhibit
  {
    FPS_EBA_INH_BRAKE_L3=512,
    FPS_EBA_INH_PRE_WARN=2,
    FPS_EBA_INH_HBA_TBRK=32,
    FPS_EBA_INH_NONE=0,
    FPS_EBA_INH_HBA_THRD=16,
    FPS_EBA_INH_BRAKE_L1=128,
    FPS_EBA_INH_ALL=65535,
    FPS_EBA_INH_LAT_WARN=1,
    FPS_EBA_INH_ACU_WARN=4,
    FPS_EBA_INH_BRAKE_L2=256,
    FPS_EBA_INH_PRE_FILL=8,
    FPS_EBA_INH_PRECRASH=64,
  }eEM_t_GenEbaInhibit;


  typedef enum eEM_t_GenObjSensorSource
  {
    EM_GEN_OBJECT_MS_NONE=0,
    EM_GEN_OBJECT_MS_LRR=1,
    EM_GEN_OBJECT_MS_SRR=4,
    EM_GEN_OBJECT_MS_HFL=64,
    EM_GEN_OBJECT_MS_MRR=2,
    EM_GEN_OBJECT_MS_IR=128,
    EM_GEN_OBJECT_MS_CAM=16,
    EM_GEN_OBJECT_MS_SRL=8,
    EM_GEN_OBJECT_MS_USN=32,
  }eEM_t_GenObjSensorSource;

  typedef enum eEM_t_GenObjMaintenanceState
  {
    EM_GEN_OBJECT_MT_STATE_PREDICTED=3,
    EM_GEN_OBJECT_MT_STATE_DELETED=0,
    EM_GEN_OBJECT_MT_STATE_INACTIVE=4,
    EM_GEN_OBJECT_MT_STATE_MEASURED=2,
    EM_GEN_OBJECT_MT_STATE_NEW=1,
    EM_GEN_OBJECT_MT_STATE_MAX_DIFF_TYPES=5,
  }eEM_t_GenObjMaintenanceState;

  typedef enum eEM_t_GenObjOcclusionState
  {
    EM_GEN_OBJECT_OCCL_PARTLY=2,
    EM_GEN_OBJECT_OCCL_FULL=3,
    EM_GEN_OBJECT_OCCL_NONE=0,EM_GEN_OBJECT_OCCL_MAX_DIFF_TYPES=4,EM_GEN_OBJECT_OCCL_UNKNOWN=1,
  }eEM_t_GenObjOcclusionState;


  typedef enum eEM_t_GenObjClassification
  {EM_GEN_OBJECT_CLASS_TRUCK=2,
  EM_GEN_OBJECT_CLASS_MAX_DIFF_TYPES=9,
  EM_GEN_OBJECT_CLASS_WIDE=6,
  EM_GEN_OBJECT_CLASS_PEDESTRIAN=3,
  EM_GEN_OBJECT_CLASS_CAR=1,
  EM_GEN_OBJECT_CLASS_POINT=0,
  EM_GEN_OBJECT_CLASS_BICYCLE=5,
  EM_GEN_OBJECT_CLASS_TL=8,EM_GEN_OBJECT_CLASS_MOTORCYCLE=4,
  EM_GEN_OBJECT_CLASS_UNCLASSIFIED=7,
  }eEM_t_GenObjClassification;

  typedef enum eEM_t_GenObjDynamicProperty
  { EM_GEN_OBJECT_DYN_PROPERTY_CROSSING_LEFT=3,
  EM_GEN_OBJECT_DYN_PROPERTY_STOPPED=6,
  EM_GEN_OBJECT_DYN_PROPERTY_CROSSING_RIGHT=4,
  EM_GEN_OBJECT_DYN_PROPERTY_MOVING=0,
  EM_GEN_OBJECT_DYN_PROPERTY_ONCOMING=2,
  EM_GEN_OBJECT_DYN_PROPERTY_STATIONARY=1,
  EM_GEN_OBJECT_DYN_PROPERTY_UNKNOWN=5,
  EM_GEN_OBJECT_DYN_PROPERTY_MAX_DIFF_TYPES=7,
  }eEM_t_GenObjDynamicProperty;

  typedef enum eEM_t_GenObjShapePointState
  {
    EM_GEN_OBJECT_SHAPE_POINT_STATE_EDGE_MEASURED=1,
    EM_GEN_OBJECT_SHAPE_POINT_STATE_INVALID=0,
    EM_GEN_OBJECT_SHAPE_POINT_STATE_VISIBILITY_EDGE=3,
    EM_GEN_OBJECT_SHAPE_POINT_STATE_EDGE_ASSUMED=2,
    EM_GEN_OBJECT_SHAPE_POINT_STATE_MAX_DIFF_TYPES=4,
  }eEM_t_GenObjShapePointState;

  typedef enum eCamObjStatusBrakeLight
  {
    EM_CAM_OBJ_BRAKE_LIGHT_UNKNOWN=0,
    EM_CAM_OBJ_BRAKE_LIGHT_NO_BRAKING=1,
    EM_CAM_OBJ_BRAKE_LIGHT_REGULAR_BRAKING=2,
    EM_CAM_OBJ_BRAKE_LIGHT_HEAVY_BREAKING=3,    
    EM_CAM_OBJ_BRAKE_LIGHT_SNA=255,
  } eCamObjStatusBrakeLight;


  typedef enum eCamObjStatusFlashLight
  {
    EM_CAM_OBJ_FLASH_LIGHT_UNKNOWN=0,
    EM_CAM_OBJ_FLASH_LIGHT_NO_FLASHING=1,
    EM_CAM_OBJ_FLASH_LIGHT_FLASHING_LEFT=2,
    EM_CAM_OBJ_FLASH_LIGHT_FLASHING_RIGHT=3,
    EM_CAM_OBJ_FLASH_LIGHT_HAZARD_FLASHING=4,  
    EM_CAM_OBJ_FLASH_LIGHT_SNA=255,    
  } eCamObjStatusFlashLight;


  typedef enum eAlgoSignalState_t {
    AL_SIG_STATE_INIT=0,
    AL_SIG_STATE_OK=1,
    AL_SIG_STATE_INVALID=2,
  } eAlgoSignalState_t;


  typedef enum eEMBase_t_CamSensorState {
    EMBASE_CAM_SEN_STATE_UNKNOWN = 0,
    EMBASE_CAM_SEN_STATE_NOT_OK = 1,
    EMBASE_CAM_SEN_STATE_OK= 2,
    EMBASE_CAM_SEN_STATE_REDUCED = 3,
    EMBASE_CAM_SEN_STATE_BLOCKED = 4,
    INVALID = 7,
  } eEMBase_t_CamSensorState;


  typedef enum eEMBase_t_CamLaneAssoc
  {
    EM_CAM_OBJ_ASSOC_LANE_UNKNOWN=0,
    EM_CAM_OBJ_ASSOC_LANE_EGO=1,
    EM_CAM_OBJ_ASSOC_LANE_LEFT=2,
    EM_CAM_OBJ_ASSOC_LANE_RIGHT=3,
    EM_CAM_OBJ_ASSOC_LANE_OUTSIDE_LEFT=4,
    EM_CAM_OBJ_ASSOC_LANE_OUTSIDE_RIGHT=5,
    EM_CAM_OBJ_ASSOC_LANE_SNA=255,   
  } eEMBase_t_CamLaneAssoc;

  typedef enum eEM_t_CamObjLaneChange
  {
    EM_CAM_OBJ_LANE_CHANGE_NONE=0,
    EM_CAM_OBJ_LANE_CHANGE_CUT_OUT_RIGHT=1,
    EM_CAM_OBJ_LANE_CHANGE_CUT_OUT_LEFT=2,
    EM_CAM_OBJ_LANE_CHANGE_CUT_IN_RIGHT=3,
    EM_CAM_OBJ_LANE_CHANGE_CUT_IN_LEFT=4, 
  }eEM_t_CamObjLaneChange;



  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    float fDistX;
    float fDistXStd;
    float fDistY;
    float fDistYStd;
    float fVabsX;
    float fVabsXStd;
    float fVabsY;
    float fVabsYStd;
    float fAabsX;
    float fAabsXStd;
    float fAabsY;
    float fAabsYStd;
  } EM_t_GenObjKinematicsSubset;

  typedef struct SignalHeader_t                             /* [Satisfies_rte sws 1191] */
  {
    AlgoDataTimeStamp_t uiTimeStamp;
    AlgoCycleCounter_t uiMeasurementCounter;
    AlgoCycleCounter_t uiCycleCounter;
    AlgoSignalState_t eSigStatus;
  } SignalHeader_t;                                         /* Common header for all structured data types */

  typedef struct EM_t_BaseCamObjectListHeader
  {
    float                     f_CamObjListDelay;
    unsigned long             ui_GlobalTimeStamp_s;
    unsigned long             ui_GlobalTimeStamp_us;
    unsigned long             ui_AliveCounter;
    unsigned long             ui_CamVersionNumber;
    EMBase_t_CamSensorState   e_CamSensorState;
    unsigned char             ui_CamNumObjects;
    unsigned char             ui_SyncRelative;
    unsigned char             ui_Reserved2;    
  } EM_t_BaseCamObjectListHeader;

  typedef struct EM_t_CamObjKinematicsSubset
  {
    float fYaw;
  } EM_t_CamObjKinematicsSubset;

  typedef struct EM_t_CamObjGeometrySubset
  {
    float fHeight;
    float fOffsetToGround;
  } EM_t_CamObjGeometrySubset;

  typedef struct EM_t_CamObjAttributesSubset
  {
    EM_t_CamObjStatusBrakeLight eStatusBrakeLight;
    EM_t_CamObjStatusFlashLight eStatusFlashLight;
    EM_t_CamObjAssociatedLane eAssociatedLane;
    EM_t_CamObjLaneChange eLaneChangeManeuver;
    unsigned char percentageOwnDrivingLane;
    unsigned char percentageSideDrivingLaneLeft;
    unsigned char percentageSideDrivingLaneRight;
  } EM_t_CamObjAttributesSubset;

  typedef struct EM_t_CamObjectSubset
  {
    EM_t_CamObjKinematicsSubset Kinematic;
    EM_t_CamObjGeometrySubset Geometry;
    EM_t_CamObjAttributesSubset Attributes;
  } EM_t_CamObjectSubset;

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    float fPosX;
    float fPosY;
    unsigned short uiPosXStd;
    unsigned short uiPosYStd;
  } EM_t_GenObjShapePointCoord;


  typedef EM_t_GenObjShapePointState EM_t_GenObjSPSArray_t[EM_BASE_CAM_SHAPEPOINT_ARRAY_SIZE];
  typedef EM_t_GenObjShapePointCoord EM_t_GenObjSPCArray_t[EM_BASE_CAM_SHAPEPOINT_ARRAY_SIZE];

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    EM_t_GenObjSPSArray_t aShapePointStates;
    EM_t_GenObjSPCArray_t aShapePointCoordinates;
  } EM_t_GenObjGeometry;			/* Object size related properties */



  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    EM_t_GenObjDynamicProperty eDynamicProperty;
    unsigned char uiDynConfidence;
    EM_t_GenObjClassification eClassification;
    unsigned char uiClassConfidence;
    EM_t_GenObjOcclusionState eObjectOcclusion;
  } EM_t_GenObjAttributesSubset;			

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    AlgoCycleCounter_t uiLifeCycles;
    EM_t_GenObjMaintenanceState eMaintenanceState;
    unsigned char uiID;
    EM_t_GenObjSensorSource eSensorSource;
  } EM_t_GenObjGeneralsSubset;			

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    unsigned char uiProbabilityOfExistence;
    unsigned char uiAccObjQuality;
    unsigned char uiEbaObjQuality;
    EM_t_GenEbaInhibit eEbaInhibitionMask;
  } EM_t_GenObjQualifiersSubset;			



  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    EM_t_GenObjKinematicsSubset Kinematic;
    EM_t_GenObjGeometry Geometry;
    EM_t_GenObjAttributesSubset Attributes;
    EM_t_GenObjGeneralsSubset General;
    EM_t_GenObjQualifiersSubset Qualifiers;
  } EM_t_GenObjectSubset;


  typedef struct EM_t_BaseCamInput
  {
    EM_t_CamObjectSubset CamObject;
    EM_t_GenObjectSubset GenObject;
  } EM_t_BaseCamInput;


  typedef  EM_t_BaseCamInput EMBase_t_CamObjInputArray[EM_N_CAM_OBJECTS];

  typedef struct EM_t_BaseObjectList_CAM
  {
    AlgoInterfaceVersionNumber_t u_VersionNumber;
    SignalHeader_t sSigHeader;
    EM_t_BaseCamObjectListHeader objectListHeader;
    EMBase_t_CamObjInputArray aObject;
  } EM_t_BaseObjectList_CAM;

}

class CConvEmBaseObjectListCam : public CSimConverterBase
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

  EM_BASE_t_ObjectList_CAM_V2::EM_t_BaseObjectList_CAM m_BufV2;

  static void InitSigHeader(EM_BASE_t_ObjectList_CAM_V2::SignalHeader_t & SigHeader)
  {
    SigHeader.uiTimeStamp           = 0;
    SigHeader.uiMeasurementCounter  = 0;
    SigHeader.uiCycleCounter        = 0;
    SigHeader.eSigStatus            = EM_BASE_t_ObjectList_CAM_V2::AL_SIG_STATE_INIT;
  };
  static void InitHeader(EM_BASE_t_ObjectList_CAM_V2::EM_t_BaseCamObjectListHeader & ObjHeader)
  {
    ObjHeader.f_CamObjListDelay      = 0.f;
    ObjHeader.ui_GlobalTimeStamp_s   = 0u;
    ObjHeader.f_CamObjListDelay      = 0.f;
    ObjHeader.ui_GlobalTimeStamp_s   = 0u;
    ObjHeader.ui_GlobalTimeStamp_us  = 0u;
    ObjHeader.ui_AliveCounter        = 0u;
    ObjHeader.ui_CamVersionNumber    = 0u;
    ObjHeader.e_CamSensorState       = EM_BASE_t_ObjectList_CAM_V2::EMBASE_CAM_SEN_STATE_UNKNOWN;
    ObjHeader.ui_CamNumObjects       = 0u;
    ObjHeader.ui_SyncRelative        = 0u;
    ObjHeader.ui_Reserved2           = 0u;    

  };


   
 static void InitCamObject(EM_BASE_t_ObjectList_CAM_V2::EM_t_CamObjectSubset & CamObject)
  { 
    /*Kinematc*/
    CamObject.Kinematic.fYaw                              = 0.f;
    
    /*Geometry*/
    CamObject.Geometry.fHeight                            = 0.f;
    CamObject.Geometry.fOffsetToGround                    = 0.f;

    /*Attributes*/
    CamObject.Attributes.eAssociatedLane                  = EM_BASE_t_ObjectList_CAM_V2::EM_CAM_OBJ_ASSOC_LANE_UNKNOWN;
    CamObject.Attributes.eLaneChangeManeuver              = EM_BASE_t_ObjectList_CAM_V2::EM_CAM_OBJ_LANE_CHANGE_NONE;
    CamObject.Attributes.eStatusBrakeLight                = EM_BASE_t_ObjectList_CAM_V2::EM_CAM_OBJ_BRAKE_LIGHT_UNKNOWN;
    CamObject.Attributes.eStatusFlashLight                = EM_BASE_t_ObjectList_CAM_V2::EM_CAM_OBJ_FLASH_LIGHT_UNKNOWN;
    CamObject.Attributes.percentageOwnDrivingLane         = 0u;
    CamObject.Attributes.percentageSideDrivingLaneLeft    = 0u;
    CamObject.Attributes.percentageSideDrivingLaneRight   = 0u;
  };
 
 static void InitGenObject(EM_BASE_t_ObjectList_CAM_V2::EM_t_GenObjectSubset & GenObject)
  {
    /*Kinematc*/
      GenObject.Kinematic.fDistX     = 0.f;
      GenObject.Kinematic.fDistXStd  = 0.f;
      GenObject.Kinematic.fDistY = 0.f;
      GenObject.Kinematic.fDistYStd = 0.f;
      GenObject.Kinematic.fVabsX = 0.f;
      GenObject.Kinematic.fVabsXStd = 0.f;
      GenObject.Kinematic.fVabsY = 0.f;
      GenObject.Kinematic.fVabsYStd = 0.f;
      GenObject.Kinematic.fAabsX = 0.f;
      GenObject.Kinematic.fAabsXStd = 0.f;
      GenObject.Kinematic.fAabsY = 0.f;
      GenObject.Kinematic.fAabsYStd = 0.f;

      /*Geometry*/
      for (int i=0; i<EM_BASE_CAM_SHAPEPOINT_ARRAY_SIZE; i++)
      {
        /*ShapePointCoordinates*/
        GenObject.Geometry.aShapePointCoordinates[i].fPosX = 0.f;
        GenObject.Geometry.aShapePointCoordinates[i].fPosY = 0.f;
        GenObject.Geometry.aShapePointCoordinates[i].uiPosXStd = 0u;
        GenObject.Geometry.aShapePointCoordinates[i].uiPosYStd = 0u;

        /*ShapePointStates*/
        GenObject.Geometry.aShapePointStates[i]=EM_BASE_t_ObjectList_CAM_V2::EM_GEN_OBJECT_SHAPE_POINT_STATE_INVALID;
      }

      /*Attributes*/
      GenObject.Attributes.eClassification   = EM_BASE_t_ObjectList_CAM_V2::EM_GEN_OBJECT_CLASS_UNCLASSIFIED;
      GenObject.Attributes.eDynamicProperty  = EM_BASE_t_ObjectList_CAM_V2::EM_GEN_OBJECT_DYN_PROPERTY_UNKNOWN;
      GenObject.Attributes.eObjectOcclusion  = EM_BASE_t_ObjectList_CAM_V2::EM_GEN_OBJECT_OCCL_UNKNOWN;
      GenObject.Attributes.uiClassConfidence = 0u;
      GenObject.Attributes.uiDynConfidence   = 0u;

      /*General*/
      GenObject.General.eMaintenanceState    = EM_BASE_t_ObjectList_CAM_V2::EM_GEN_OBJECT_MT_STATE_DELETED;
      GenObject.General.eSensorSource        = EM_BASE_t_ObjectList_CAM_V2::EM_GEN_OBJECT_MS_NONE;
      GenObject.General.uiID                 = 255u;
      GenObject.General.uiLifeCycles         = 0u;

      /*Qualifiers*/
      GenObject.Qualifiers.eEbaInhibitionMask       = EM_BASE_t_ObjectList_CAM_V2::FPS_EBA_INH_NONE;
      GenObject.Qualifiers.uiAccObjQuality          = 0u;
      GenObject.Qualifiers.uiEbaObjQuality          = 0u;
      GenObject.Qualifiers.uiProbabilityOfExistence = 0u;

  };

 


  static void InitV2(EM_BASE_t_ObjectList_CAM_V2::EM_t_BaseObjectList_CAM & ObjList)
  {
    ObjList.u_VersionNumber = 2u;
    InitSigHeader(ObjList.sSigHeader);
    InitHeader(ObjList.objectListHeader);

    for (unsigned int i=0; i<EM_N_CAM_OBJECTS; i++)
    {
      InitCamObject(ObjList.aObject[i].CamObject);     
      InitGenObject(ObjList.aObject[i].GenObject);     
    }
  };


  static void ConvertObject(EM_BASE_t_ObjectList_CAM_V2::EM_t_BaseObjectList_CAM & DestObj, const EM_BASE_t_ObjectList_CAM_V2::EM_t_BaseObjectList_CAM & SrcObj)
  {
    memcpy(&DestObj, &SrcObj, sizeof(DestObj));
  };

   


  static void Convert(EM_BASE_t_ObjectList_CAM_V2::EM_t_BaseObjectList_CAM & DestObjList, const EM_BASE_t_ObjectList_CAM_V2::EM_t_BaseObjectList_CAM & SrcObjList)
  {
    memcpy(&DestObjList, &SrcObjList, sizeof(DestObjList));
  };



 
public:

  static const char *GetConverterTypeName()
  {
    return "EM_t_BaseObjectList_CAM";
  };

  CConvEmBaseObjectListCam(void) : CSimConverterBase(NULL/*DEP_NAMES*/, DEP_COUNT), m_BufV2()
  {
    InitV2(m_BufV2);
    
  };

  virtual ~CConvEmBaseObjectListCam(void)
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

  static CVersionInfoImpl VERSION2;

  typedef enum eEM_Base_Cam_ObjListVersionCount
  {
    EM__BASE_CAM_T_OBJECTLIST_V2,
    EM_BASE_CAM_T_OBJECTLIST_COUNT
  } eEM_BaseCam_ObjListVersionCount;

  static const unsigned long SUPPORTED_SIZE[EM_BASE_CAM_T_OBJECTLIST_COUNT];

};

CVersionInfoImpl CConvEmBaseObjectListCam::VERSION2(0, 0, 2);


const unsigned long CConvEmBaseObjectListCam::SUPPORTED_SIZE[CConvEmBaseObjectListCam::EM_BASE_CAM_T_OBJECTLIST_COUNT] =
{
  sizeof(EM_BASE_t_ObjectList_CAM_V2::EM_t_BaseObjectList_CAM)
};

long CConvEmBaseObjectListCam::ConvertData(
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
    if ((ulRPortSize == sizeof(EM_BASE_t_ObjectList_CAM_V2::EM_t_BaseObjectList_CAM ) ) && (requestPortVersionInfo.Equals(&VERSION2) ) ) 
    {
     
      EM_BASE_t_ObjectList_CAM_V2::EM_t_BaseObjectList_CAM & Dest = m_BufV2;
      if ((ulPPortSize == sizeof(EM_BASE_t_ObjectList_CAM_V2::EM_t_BaseObjectList_CAM))
        && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VERSION2)) )
        && ((uDataVer == 0x2u) ))
      {
        const EM_BASE_t_ObjectList_CAM_V2::EM_t_BaseObjectList_CAM & Src = *reinterpret_cast<EM_BASE_t_ObjectList_CAM_V2::EM_t_BaseObjectList_CAM*>(pPPortData);
        Convert(Dest, Src);
        *pOutData = (void*)&Dest;
        ulOutSize = sizeof(Dest);
        lRet = SIM_ERR_OK;
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
 *   SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT - when the default vaule is not implememnted here
 *                                            and the default value from Request Port must be used
 */
long CConvEmBaseObjectListCam::GetDefaultValue(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
  void **pDefaultData, unsigned long &ulDefaultSize)
{
  long lRet = SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT;
  if (eRPortType == simOPAQUE_t)
  {
    if ( ( ulRPortSize == sizeof(EM_BASE_t_ObjectList_CAM_V2::EM_t_BaseCamInput ) )    && ( VERSION2.Equals(&requestPortVersionInfo) ) )
    {
      EM_BASE_t_ObjectList_CAM_V2::EM_t_BaseObjectList_CAM & Dest = m_BufV2;       
      InitV2(Dest);
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
bool CConvEmBaseObjectListCam::IsVersionCompatibleWithType(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
  SimPortDataTypes_t ePPortType, unsigned long ulPPortSize)
{
  bool bResult = false;

  // Assume equal ports to be compatible
  if ((eRPortType == ePPortType) && (ulRPortSize == ulPPortSize))
  {
    bResult = true;
  }  
  
  return bResult;
}

// used to check if ports are compatible between different versions
bool CConvEmBaseObjectListCam::AreVersionsCompatible(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
  SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo &providePortVersionInfo)
{
  bool bResult = false;

  // Assume equal ports to be compatible
  if ((eRPortType == ePPortType) && (ulRPortSize == ulPPortSize) && (requestPortVersionInfo.Equals(&providePortVersionInfo)))
  {
    bResult = true;
  }

  return bResult;
}

//
// Main factory class returning conversion class
//
IConverter * CreateEmObjectListBaseCamConvClass(void)
{
  return new CConvEmBaseObjectListCam();
}
