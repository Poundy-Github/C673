/*! \file **********************************************************************

  COMPANY:         Continental

  PROJECT:         Simulation

  COMPONENT:       sim_adapter em

  MODULNAME:       sim_conv_em_objectlist_scam.cpp

  DESCRIPTION:

  AUTHOR:          Thomas Berndt

  CREATION DATE:   31.10.2013

  VERSION:         $Revision: 1.1 $

  ---*/ /*---
  CHANGES:         $Log: sim_conv_em_objectlist_scam.cpp  $
  CHANGES:         Revision 1.1 2021/12/13 17:20:45CET Wang, David (Wangd3) 
  CHANGES:         Initial revision
  CHANGES:         Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_adapter/em/project.pj
  CHANGES:         Revision 1.1 2017/08/10 13:15:07CEST uid34177 
  CHANGES:         Initial revision
  CHANGES:         Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_adapter/em/project.pj
  CHANGES:         Revision 1.19 2016/09/16 08:28:38CEST Kubera, David (kuberad) 
  CHANGES:         add conversion from BW16 to BW18: 0x000A0004 -> 0x000D0006
  CHANGES:         Revision 1.18 2015/11/04 14:20:27CET Berndt, Thomas01 (berndtt1) 
  CHANGES:         Removed the merged manipulation of ...objectListHeader.eventDataQualifier = 0; and ...objectListHeader.extendedQualifier  = 0;
  CHANGES:         - Added comments -  berndtt1 [Nov 4, 2015 2:21:29 PM CET]
  CHANGES:         Change Package : 393512:1 http://mks-psad:7002/im/viewissue?selection=393512
  CHANGES:         Revision 1.17 2015/11/04 13:46:15CET Berndt, Thomas01 (berndtt1) 
  CHANGES:         Merged manipulation of ...objectListHeader.eventDataQualifier = 0; and ...objectListHeader.extendedQualifier  = 0;
  CHANGES:         Added conversion of 0x80004 and 0xA0004 to the sim_fusion branches
  CHANGES:         --- Added comments ---  berndtt1 [Nov 4, 2015 2:00:52 PM CET]
  CHANGES:         Change Package : 393512:1 http://mks-psad:7002/im/viewissue?selection=393512
  CHANGES:         Revision 1.16 2015/09/28 08:46:59CEST Kaelberer, Stephan (uidu2442) 
  CHANGES:         added conversion for 0xA0004u
  CHANGES:         --- Added comments ---  uidu2442 [Sep 28, 2015 8:46:59 AM CEST]
  CHANGES:         Change Package : 380807:1 http://mks-psad:7002/im/viewissue?selection=380807
  CHANGES:         Revision 1.15 2015/08/25 14:27:43CEST Kubera, David (kuberad) 
  CHANGES:         add compatible versions
  CHANGES:         --- Added comments ---  kuberad [Aug 25, 2015 2:27:43 PM CEST]
  CHANGES:         Change Package : 370541:1 http://mks-psad:7002/im/viewissue?selection=370541
  CHANGES:         Revision 1.14 2015/01/20 19:31:57CET Kubera, David (kuberad) 
  CHANGES:         preliminary quick adaption to new camera input data (version). no warranty!
  CHANGES:         --- Added comments ---  kuberad [Jan 20, 2015 7:31:57 PM CET]
  CHANGES:         Change Package : 262492:1 http://mks-psad:7002/im/viewissue?selection=262492
  CHANGES:         Revision 1.13 2014/12/02 15:40:17CET Berndt, Thomas01 (berndtt1) 
  CHANGES:         + false Version 0x80003 (wrong export -1 Byte)
  CHANGES:         --- Added comments ---  berndtt1 [Dec 5, 2014 2:17:01 PM CET]
  CHANGES:         Change Package : 221167:9 http://mks-psad:7002/im/viewissue?selection=221167
  CHANGES:         Revision 1.12 2014/10/31 08:14:20CET Berndt, Thomas01 (berndtt1) 
  CHANGES:         + Version 0x80003 which has only an enhanced enum to 0x50002
  CHANGES:         --- Added comments ---  berndtt1 [Oct 31, 2014 8:22:31 AM CET]
  CHANGES:         Change Package : 221167:34 http://mks-psad:7002/im/viewissue?selection=221167
  CHANGES:         Revision 1.11 2014/08/19 17:18:23CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:         Modify pDest->objectListHeader.u_Timestamp modulo 1000000 in EMB0_t_ObjectList_SCAM_V50002_R::EMB0_t_ObjectList_SCAM
  CHANGES:         --- Added comments ---  berndtt1 [Aug 19, 2014 5:41:09 PM CEST]
  CHANGES:         Change Package : 221167:23 http://mks-psad:7002/im/viewissue?selection=221167
  CHANGES:         Revision 1.10 2014/07/16 16:12:56CEST Kubera, David (kuberad) 
  CHANGES:         add compatibility :  V00060002 -> V00060002
  CHANGES:         neat arrangements of code for better maintainability
  CHANGES:         --- Added comments ---  kuberad [Jul 16, 2014 4:12:56 PM CEST]
  CHANGES:         Change Package : 245845:3 http://mks-psad:7002/im/viewissue?selection=245845
  CHANGES:         Revision 1.9 2014/07/08 15:11:28CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:         + Conversion from SIM_FUSION_SYNC delivered data block Version 0x60002 (which is exactly like 0x50002) with byte aligned structures
  CHANGES:         conversion only impemented to V50002
  CHANGES:         --- Added comments ---  berndtt1 [Jul 8, 2014 3:15:27 PM CEST]
  CHANGES:         Change Package : 221167:9 http://mks-psad:7002/im/viewissue?selection=221167
  CHANGES:         Revision 1.8 2014/04/24 17:20:13CEST Ungvary, Gergely (ungvaryg) 
  CHANGES:         Minor fix: wrong header file included (no extern declaration for factory function) - replace sim_conv_aln_rtebswout.h with proper sim_conv_em_objectlist_scam.h
  CHANGES:         --- Added comments ---  ungvaryg [Apr 24, 2014 5:20:13 PM CEST]
  CHANGES:         Change Package : 228642:1 http://mks-psad:7002/im/viewissue?selection=228642
  CHANGES:         Revision 1.7 2014/04/08 13:24:50CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:         + Conversion from SIM_FUSION_SYNC delivered data block Version 0x50002 with byte aligned structures
  CHANGES:         conversion only impemented for V50002
  CHANGES:         --- Added comments ---  berndtt1 [Apr 8, 2014 1:29:48 PM CEST]
  CHANGES:         Change Package : 221167:9 http://mks-psad:7002/im/viewissue?selection=221167
  CHANGES:         Revision 1.6 2014/03/07 18:15:28CET Kubera, David (kuberad) 
  CHANGES:         provide support for recordings with V00050002
  CHANGES:         --- Added comments ---  kuberad [Mar 7, 2014 6:15:28 PM CET]
  CHANGES:         Change Package : 184194:5 http://mks-psad:7002/im/viewissue?selection=184194
  CHANGES:         Revision 1.5 2014/01/17 19:37:53CET Kubera, David (kuberad) 
  CHANGES:         fixes to convert V00030002 to V00050002
  CHANGES:         --- Added comments ---  kuberad [Jan 17, 2014 7:37:53 PM CET]
  CHANGES:         Change Package : 209133:3 http://mks-psad:7002/im/viewissue?selection=209133
  CHANGES:         Revision 1.4 2014/01/17 19:02:07CET Kubera, David (kuberad) 
  CHANGES:         add conversion from V00030002 to V00050002
  CHANGES:         --- Added comments ---  kuberad [Jan 17, 2014 7:02:08 PM CET]
  CHANGES:         Change Package : 209132:1 http://mks-psad:7002/im/viewissue?selection=209132
  CHANGES:         Revision 1.3 2013/12/18 19:42:56CET Kubera, David (kuberad) 
  CHANGES:         Updated with Version 0x00050002u
  CHANGES:         --- Added comments ---  kuberad [Dec 18, 2013 7:42:56 PM CET]
  CHANGES:         Change Package : 209133:1 http://mks-psad:7002/im/viewissue?selection=209133
  CHANGES:         Revision 1.2 2013/11/06 13:14:27CET Berndt, Thomas01 (berndtt1) 
  CHANGES:         Updated with Version 0x00030002u
  CHANGES:         --- Added comments ---  berndtt1 [Nov 6, 2013 1:20:11 PM CET]
  CHANGES:         Change Package : 193430:6 http://mks-psad:7002/im/viewissue?selection=193430
  CHANGES:         Revision 1.1 2013/10/31 17:03:35CET Berndt, Thomas01 (berndtt1) 
  CHANGES:         Initial revision
  CHANGES:         Member added to project /nfs/projekte1/PROJECTS/ARS400/06_Algorithm/04_Engineering/03_Workspace/algo/sim_adapter/em/project.pj

**************************************************************************** */
/* includes ---------------------------------------------------------------- */

#include "sim_conv_em_objectlist_scam.h"
#include "sim_versioninfo_impl.h"

// typedef float float32;
typedef unsigned __int8 boolean/*, uint8*/;
// typedef unsigned __int32 uint32;

/* typedef AlgoSignalState_t */
#ifndef AL_SIG_STATE_INIT
  #define AL_SIG_STATE_INIT (0U)
#endif
#ifndef AL_SIG_STATE_OK
  #define AL_SIG_STATE_OK (1U)
#endif

/* typedef e_AlnState_t */
#ifndef   AlnStateNormal
  #define AlnStateNormal (0U)
#endif


// ARS4xx EMB0_t_ObjectList_SCAM version 1                           Length = 6088
namespace EMB0_t_ObjectList_SCAM_V1
{
  typedef unsigned long AlgoInterfaceVersionNumber_t                 /* Algo interface version nummbers @min:0 @max:4294967295 */ /* [Satisfies_rte sws 1188] */;
  typedef unsigned long AlgoDataTimeStamp_t                          /* Algo data time-stamp type (32 bit variant) @min:0 @max:4294967295 */  /* [Satisfies_rte sws 1188] */;
  typedef unsigned short AlgoCycleCounter_t                          /* Algo cycle counter @min:0 @max:65535 */  /* [Satisfies_rte sws 1188] */;
  typedef unsigned char AlgoSignalState_t                            /* Algo signal state enumeration @min: 0 @max:2 @values: enum { AL_SIG_STATE_INVALID=2,AL_SIG_STATE_INIT=0,AL_SIG_STATE_OK=1,} */  /* [Satisfies_rte sws 1188] */;
  typedef unsigned char EMB0_t_SensorSource                          /* Enumberation to identify the sensor reporting an specific object list @min: 0 @max:9 @values: enum { EMB0_OBJECT_LIST_SOURCE_LRR=1,EMB0_OBJECT_LIST_SOURCE_SCAM=9,EMB0_OBJECT_LIST_SOURCE_MCAM=8,EMB0_OBJECT_LIST_SOURCE_SRL=7,EMB0_OBJECT_LIST_SOURCE_SRR_FR=4,EMB0_OBJECT_LIST_SOURCE_SRR_RR=6,EMB0_OBJECT_LIST_SOURCE_SRR_RL=5,EMB0_OBJECT_LIST_SOURCE_SRR_FL=3,EMB0_OBJECT_LIST_SOURCE_NONE=0,EMB0_OBJECT_LIST_SOURCE_MRR=2,} */ /* [Satisfies_rte sws 1188] */;
  typedef unsigned char EMB0_t_Service                               /* Common status qualifier. @min: 0 @max:255 @values: enum { EMB0_QS_NOT_OK=2,EMB0_QS_INIT=0,EMB0_QS_SNA=255,EMB0_QS_OK=1,} */ /* [Satisfies_rte sws 1188] */;
  typedef unsigned char EMB0_t_EventDataQualifier                    /* The qualifier expresses whether the content of this event can be used or not. @min: 0 @max:255 @values: enum { EMB0_CEDQ_EVENT_DATA_AVAILABLE=0,EMB0_CEDQ_SNA=255,EMB0_CEDQ_EVENT_DATA_AVAILABLE_REDUCED=1,EMB0_CEDQ_EVENT_DATA_NOT_AVAILABLE=2,} */ /* [Satisfies_rte sws 1188] */;
  typedef unsigned char EMB0_t_ExtendedQualifier                     /* The extendedQualifier describes the reason (not the effect) why the service is reduced or not available. @min: 0 @max:255 @values: enum { EMB0_CEQ_SENSOR_NOT_CALIBRATED=2,EMB0_CEQ_INPUT_NOT_AVAILABLE=7,EMB0_CEQ_NORMAL_OPERATION_MODE=0,EMB0_CEQ_POWER_UP_OR_DOWN=1,EMB0_CEQ_SNA=255,EMB0_CEQ_BAD_SENSOR_ENVIRONMENTAL_CONDITION=5,EMB0_CEQ_SENSOR_BLOCKED=3,EMB0_CEQ_SENSOR_MISALIGNED=4,EMB0_CEQ_REDUCED_FIELD_OF_VIEW=6,} */ /* [Satisfies_rte sws 1188] */;

  typedef struct SignalHeader_t                                      /* [Satisfies_rte sws 1191] */
  {
    AlgoDataTimeStamp_t uiTimeStamp;
    AlgoCycleCounter_t uiMeasurementCounter;
    AlgoCycleCounter_t uiCycleCounter;
    AlgoSignalState_t eSigStatus;
  } SignalHeader_t;                                                  /* Common header for all structured data types */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    unsigned long u_SwVersionNumber;
    EMB0_t_Service dataComplete;
    unsigned char u_NumOfEventGroups;
    EMB0_t_Service commonCRC_OK;
    unsigned char u_NumberOfObjects;
    unsigned long u_Alive;
    unsigned short u_Timestamp;
    EMB0_t_EventDataQualifier eventDataQualifier;
    EMB0_t_ExtendedQualifier extendedQualifier;
  } EMB0_t_ObjectListHeader;                                         /* This data type provides common status information about the object property lists. */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    unsigned char u_NumberOfPedestrians;
    unsigned char u_NumberOfCyclists;
    unsigned char u_NumberOfBikes;
    unsigned char u_NumberOfCars;
    unsigned char u_NumberOfTrucks;
    unsigned char u_NumberOfOtherVehicles;
    unsigned char u_NumberOfRoadBoundaries;
    unsigned char u_NumberOfBridges;
    unsigned char u_NumberOfUnknownObjects;
    unsigned char u_NumberOfFreeFormObjects;
    unsigned char dummy_82;
    unsigned char dummy_83;
  } EMB0_t_ObjectListCounts;                                         /* This data type provides a brief summary of object type distribution over in the lists (e.g. how many cars, how many bikes). */

  typedef unsigned char EMB0_t_MeasurementStatus                     /* Measurement status of object, e.g. measured, predicted, etc. @min: 0 @max:255 @values: enum { EMB0_CMS_MEAS_PART_OCCL=3,EMB0_CMS_MEAS_NEW=0,EMB0_CMS_MEAS=2,EMB0_CMS_SNA=255,EMB0_CMS_MEAS_NEW_PART_OCCL=1,EMB0_CMS_PRED_PART_OCCL=5,EMB0_CMS_PRED=4,} */ /* [Satisfies_rte sws 1188] */;
  typedef unsigned char EMB0_t_ObjectMovementStatus                  /* Movement status of object, e.g. moving in own direction, stopped, etc. @min: 0 @max:255 @values: enum { EMB0_OMS_SNA=255,EMB0_OMS_STATIONARY_PARKING=0,EMB0_OMS_STOPPED=1,EMB0_OMS_MOVING_ONGOING=3,EMB0_OMS_MOVING_ONCOMMING=2,EMB0_OMS_MOVING_DIR_UNKNOWN=4,} */ /* [Satisfies_rte sws 1188] */;
  typedef unsigned char EMB0_t_ObjectType                            /* Discrete classification type based on probabilities within the classification vector. This is the most likely type of the object based on the classification. @min: 0 @max:255 @values: enum { EMB0_OT_ROAD_BOUNDARY=6,EMB0_OT_MOTORBIKE=2,EMB0_OT_TRUCK=4,EMB0_OT_SNA=255,EMB0_OT_UNKNOWN=8,EMB0_OT_CYCLIST=1,EMB0_OT_PEDESTRIAN=0,EMB0_OT_CAR=3,EMB0_OT_OTHER_VEHICLE=5,EMB0_OT_BRIDGE=7,} */ /* [Satisfies_rte sws 1188] */;
  typedef unsigned char EMB0_t_ObjectModeLateral                     /* Movement status lateral. @min: 0 @max:255 @values: enum { EMB0_OML_REEVE_FROM_LEFT=1,EMB0_OML_SNA=255,EMB0_OML_NONE=5,EMB0_OML_REEVE_FROM_RIGHT=2,EMB0_OML_UNKNOWN=0,EMB0_OML_REEVE_TO_RIGHT=4,EMB0_OML_REEVE_TO_LEFT=3,} */ /* [Satisfies_rte sws 1188] */;
  typedef unsigned char EMB0_t_DrivingTubeMapping                    /* Association to the driving lane of the object. @min: 0 @max:255 @values: enum { EMB0_DTM_SNA=255,EMB0_DTM_EGO_LANE=1,EMB0_DTM_NEXT_RIGHT=4,EMB0_DTM_FAR_RIGHT=5,EMB0_DTM_NEXT_LEFT=2,EMB0_DTM_FAR_LEFT=3,EMB0_DTM_INIT_UNKNOWN=0,} */ /* [Satisfies_rte sws 1188] */;
  typedef unsigned char EMB0_t_ObjectReferencePoint                  /* This enum identifies the corner of the object the sensor has observed. The whole measurement originates from the reference point. @min: 0 @max:255 @values: enum { EMB0_ORP_CORNER_FRONT_LEFT=0,EMB0_ORP_CORNER_REAR_LEFT=6,EMB0_ORP_MIDDLE_SIDE_RIGHT=3,EMB0_ORP_CORNER_REAR_RIGHT=4,EMB0_ORP_SNA=255,EMB0_ORP_MIDDLE_SIDE_LEFT=7,EMB0_ORP_MIDDLE_FRONT=1,EMB0_ORP_CORNER_FRONT_RIGHT=2,EMB0_ORP_MIDDLE_REAR=5,} */ /* [Satisfies_rte sws 1188] */;
  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    unsigned char u_ObjectId;
    EMB0_t_MeasurementStatus statusMeasurement;
    EMB0_t_ObjectMovementStatus statusMovement;
    EMB0_t_ObjectType classificationType;
    EMB0_t_ObjectModeLateral modeLateral;
    EMB0_t_DrivingTubeMapping drivingTubeMapping;
    EMB0_t_ObjectReferencePoint referencePoint;
    unsigned char dummy_81;
  } EMB0_t_ObjectRecognitionInfo;                                    /* This datatype summarizes status information of an object. */
  typedef EMB0_t_ObjectRecognitionInfo EMB0_t_ScamOriArray[40];      /* [Satisfies_rte sws 1189] */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    float f_PositionX;
    float f_PositionY;
    float f_PositionZ;
  } EMB0_t_ObjectPositionInfo;                                       /* This data type summarizes object position information. The coordinates are in vehicle coordinate system. */
  typedef EMB0_t_ObjectPositionInfo EMB0_t_ScamOpiArray[40];         /* [Satisfies_rte sws 1189] */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    float f_ExtensionX;
    float f_ExtensionY;
    float f_ExtensionZ;
  } EMB0_t_ObjectExtensionInfo;                                      /* This data type summarizes object extension information (e.g. length, width) of an object. */
  typedef EMB0_t_ObjectExtensionInfo EMB0_t_ScamOeiArray[40];        /* [Satisfies_rte sws 1189] */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    float f_SpeedAbsoluteX;
    float f_SpeedAbsoluteY;
    float f_AccelAbsoluteX;
    float f_AccelAbsoluteY;
    float f_YawAngle;
    float f_YawSpeed;
  } EMB0_t_ObjectMovementInfo;                                       /* This data type summarizes absolute speed and yaw angle information of an object. */
  typedef EMB0_t_ObjectMovementInfo EMB0_t_ScamOmiArray[40];         /* [Satisfies_rte sws 1189] */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    float f_StdDevPositionX;
    float f_StdDevPositionY;
    float f_StdDevPositionZ;
    float f_StdDevExtensionX;
    float f_StdDevExtensionY;
    float f_StdDevExtensionZ;
  } EMB0_t_ObjectPositionStdDev;                                     /* This data type summarizes standard deviations for position and extension information of an object. */
  typedef EMB0_t_ObjectPositionStdDev EMB0_t_ScamPsdArray[40];       /* [Satisfies_rte sws 1189] */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    float f_StdDevSpeedAbsoluteX;
    float f_StdDevSpeedAbsoluteY;
    float f_StdDevAccelAbsoluteX;
    float f_StdDevAccelAbsoluteY;
    float f_StdDevYawAngle;
    float f_StdDevYawSpeed;
  } EMB0_t_ObjectMovementStdDev;                                     /* This data types summarizes standard deviations for movement information of an object. */
  typedef EMB0_t_ObjectMovementStdDev EMB0_t_ScamOmsdArray[40];      /* [Satisfies_rte sws 1189] */

  typedef unsigned char percentage_t                                 /* percentage @min:0 @max:100 @resolution:1.0 */ /* [Satisfies_rte sws 1188] */;
  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    percentage_t existenceProbability;
    percentage_t probabilityPedestrian;
    percentage_t probabilityCyclist;
    percentage_t probabilityBike;
    percentage_t probabilityCar;
    percentage_t propabilityTruck;
    percentage_t probabilityOtherVehicles;
    percentage_t probabilityRoadBoundary;
    percentage_t probabilityBridge;
    percentage_t probabilityUnknown;
    unsigned char dummy_81;
    unsigned char dummy_82;
  } EMB0_t_ObjectProbabilityInfo;                                    /* This data type represents the classification vector of an object. An object can be classified with 80% as car and 20% as truck. The individual probabilities are stored in this data type. */
  typedef EMB0_t_ObjectProbabilityInfo EMB0_t_ScamOpriArray[40];     /* [Satisfies_rte sws 1189] */

  typedef unsigned char EMB0_t_ObjFlashLightStat                     /* Status of the flash light of the object. @min: 0 @max:255 @values: enum { EMB0_OFS_SNA=255,EMB0_OFS_HAZARD_FLASHING=4,EMB0_OFS_NO_FLASHING=1,EMB0_OFS_FLASHING_LEFT=2,EMB0_OFS_FLASHING_RIGHT=3,EMB0_OFS_INITIALIZATION_STATUS_UNKNOWN=0,} */ /* [Satisfies_rte sws 1188] */;
  typedef unsigned char EMB0_t_ObjBrakeLightStat                     /* This enum provides a status of the brake light of the object. @min: 0 @max:255 @values: enum { EMB0_REGULAR_BRAKING=2,EMB0_INITIALIZATION_STATUS_UNKNOWN=0,EMB0_SNA=255,EMB0_NO_BRAKING=1,EMB0_HEAVY_BREAKING=3,} */ /* [Satisfies_rte sws 1188] */;
  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    EMB0_t_ObjFlashLightStat statusFlashLight;
    EMB0_t_ObjBrakeLightStat statusBrakingLight;
    percentage_t percentageOwnDrivingLane;
    percentage_t percentageSideDrivingLaneLeft;
    percentage_t percentageSideDrivingLaneRight;
    unsigned char dummy_81;
    unsigned char dummy_82;
    unsigned char dummy_83;
  } EMB0_t_ObjectFrontCameraInfo;                                    /* This data type contains information provided by front camera only, e.g. brakelight status or status of blinker which is not visible for other sensors. */
  typedef EMB0_t_ObjectFrontCameraInfo EMB0_t_ScamOfciArray[40];     /* [Satisfies_rte sws 1189] */


  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    float f_X;
    float f_Y;
  } EMB0_t_ObjectFreeFormPoint;                                      /* - */
  typedef EMB0_t_ObjectFreeFormPoint EMB0_t_OffpArray[13];           /* - */ /* [Satisfies_rte sws 1189] */
  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    unsigned char u_NumberOfPoints;
    unsigned char u_ObjectId;
    unsigned char dummy_82;
    unsigned char dummy_83;
    EMB0_t_OffpArray a_ObjectPoints;
  } EMB0_t_ObjectFreeFormInfo;                                       /* This data type summarizes the freeform information of this object. */
  typedef EMB0_t_ObjectFreeFormInfo EMB0_t_ScamOffiArray[10];        /* [Satisfies_rte sws 1189] */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    AlgoInterfaceVersionNumber_t u_VersionNumber;
    SignalHeader_t sSigHeader;
    EMB0_t_SensorSource sensorSource;
    EMB0_t_ObjectListHeader objectListHeader;
    EMB0_t_ObjectListCounts objectListCounts;
    EMB0_t_ScamOriArray a_ObjRecognitionInfo;
    EMB0_t_ScamOpiArray a_ObjPositionInfo;
    EMB0_t_ScamOeiArray a_ObjExtensionInfo;
    EMB0_t_ScamOmiArray a_ObjMovementInfo;
    EMB0_t_ScamPsdArray a_ObjPositionStdDev;
    EMB0_t_ScamOmsdArray a_ObjMovementStdDev;
    EMB0_t_ScamOpriArray a_ObjProbabilityInfo;
    EMB0_t_ScamOfciArray a_ObjFrontCameraInfo;
    EMB0_t_ScamOffiArray a_ObjFreeFormInfo;
  } EMB0_t_ObjectList_SCAM;                                          /* @vaddr:0x20190000 @vaddr_defs: EM_MEAS_ID_B0_OBJECT_LIST_SCAM @cycleid:EM_ENV @vname:EMB0ObjDataSCam */

} // end of namespace EMB0_t_ObjectList_SCAM_V1


// ARS4xx EMB0_t_ObjectList_SCAM version 2                           Length = 6092
namespace EMB0_t_ObjectList_SCAM_V2
{
  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    EMB0_t_ObjectList_SCAM_V1::AlgoInterfaceVersionNumber_t u_VersionNumber;
    EMB0_t_ObjectList_SCAM_V1::SignalHeader_t sSigHeader;
    EMB0_t_ObjectList_SCAM_V1::EMB0_t_SensorSource sensorSource;
    unsigned long u_CurrentExternalTime;
    EMB0_t_ObjectList_SCAM_V1::EMB0_t_ObjectListHeader objectListHeader;
    EMB0_t_ObjectList_SCAM_V1::EMB0_t_ObjectListCounts objectListCounts;
    EMB0_t_ObjectList_SCAM_V1::EMB0_t_ScamOriArray a_ObjRecognitionInfo;
    EMB0_t_ObjectList_SCAM_V1::EMB0_t_ScamOpiArray a_ObjPositionInfo;
    EMB0_t_ObjectList_SCAM_V1::EMB0_t_ScamOeiArray a_ObjExtensionInfo;
    EMB0_t_ObjectList_SCAM_V1::EMB0_t_ScamOmiArray a_ObjMovementInfo;
    EMB0_t_ObjectList_SCAM_V1::EMB0_t_ScamPsdArray a_ObjPositionStdDev;
    EMB0_t_ObjectList_SCAM_V1::EMB0_t_ScamOmsdArray a_ObjMovementStdDev;
    EMB0_t_ObjectList_SCAM_V1::EMB0_t_ScamOpriArray a_ObjProbabilityInfo;
    EMB0_t_ObjectList_SCAM_V1::EMB0_t_ScamOfciArray a_ObjFrontCameraInfo;
    EMB0_t_ObjectList_SCAM_V1::EMB0_t_ScamOffiArray a_ObjFreeFormInfo;
  } EMB0_t_ObjectList_SCAM;                                          /* @vaddr:0x20190000 @vaddr_defs: EM_MEAS_ID_B0_OBJECT_LIST_SCAM @cycleid:EM_ENV @vname:EMB0ObjDataSCam */

} // end of namespace EMB0_t_ObjectList_SCAM_V2


// ARS4xx EMB0_t_ObjectList_SCAM version 30002                       Length = 5176
namespace EMB0_t_ObjectList_SCAM_V30002
{
  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    unsigned long u_SwVersionNumber;
    EMB0_t_ObjectList_SCAM_V1::EMB0_t_Service dataComplete;
    unsigned char u_NumOfEventGroups;
    EMB0_t_ObjectList_SCAM_V1::EMB0_t_Service commonCRC_OK;
    unsigned char u_NumberOfObjects;
    unsigned long u_Counter;
    unsigned short u_Timestamp;
    EMB0_t_ObjectList_SCAM_V1::EMB0_t_EventDataQualifier eventDataQualifier;
    EMB0_t_ObjectList_SCAM_V1::EMB0_t_ExtendedQualifier extendedQualifier;
  } EMB0_t_ObjectListHeader;                                         /* This data type provides common status information about the object property lists. */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    float f_Length;
    float f_Width;
    float f_Height;
  } EMB0_t_ObjectDimensionInfo;                                      /* This data type summarizes object dimension information (e.g. length, width) of an object. */
  typedef EMB0_t_ObjectDimensionInfo EMB0_t_ScamOeiArray[40];        /* [Satisfies_rte sws 1189] */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    float f_StdDevPositionX;
    float f_StdDevPositionY;
    float f_StdDevPositionZ;
    float f_StdDevLength;
    float f_StdDevWidth;
    float f_StdDevHeight;
  } EMB0_t_ObjectPositionStdDev;                                     /* This data type summarizes standard deviations for position and extension information of an object. */
  typedef EMB0_t_ObjectPositionStdDev EMB0_t_ScamPsdArray[40];       /* [Satisfies_rte sws 1189] */

  typedef unsigned long EMB0_t_Flags                                 /* Discribes the invalidity of separate object signals @min: 1 @max:2147483648 @values: enum { EMB0_MSDVF_STD_DEV_SPEED_ABSOLUTE_Y_INVALID=524288,EMB0_MSDVF_STD_DEV_ACCEL_YAW_ANGLE_INVALID=4194304,EMB0_MSDVF_STD_DEV_ACCEL_ABSOLUTE_Y_INVALID=2097152,EMB0_PSDVF_STD_DEV_POSITION_Y_INVALID=8192,EMB0_DVF_WIDTH_INVALID=16,EMB0_DVF_LENGTH_INVALID=8,EMB0_MIVF_ACCEL_YAW_ANGLE_INVALID=1024,EMB0_DVF_HEIGHT_INVALID=32,EMB0_FLAGS_SNA=2147483648,EMB0_PVF_POSITION_Y_INVALID=2,EMB0_MSDVF_STD_DEV_SPEED_ABSOLUTE_X_INVALID=262144,EMB0_MIVF_SPEED_ABSOLUTE_X_INVALID=64,EMB0_PSDVF_STD_DEV_WIDTH_INVALID=65536,EMB0_MSDVF_STD_DEV_ACCEL_YAW_SPEED_INVALID=8388608,EMB0_MIVF_SPEED_ABSOLUTE_Y_INVALID=128,EMB0_MIVF_ACCEL_ABSOLUTE_X_INVALID=256,EMB0_PVF_POSITION_X_INVALID=1,EMB0_PVF_POSITION_Z_INVALID=4,EMB0_MIVF_ACCEL_YAW_SPEED_INVALID=2048,EMB0_PSDVF_STD_DEV_HEIGHT_INVALID=131072,EMB0_PSDVF_STD_DEV_LENGTH_INVALID=32768,EMB0_PSDVF_STD_DEV_POSITION_Z_INVALID=16384,EMB0_PSDVF_STD_DEV_POSITION_X_INVALID=4096,EMB0_MIVF_ACCEL_ABSOLUTE_Y_INVALID=512,EMB0_MSDVF_STD_DEV_ACCEL_ABSOLUTE_X_INVALID=1048576,} */ /* [Satisfies_rte sws 1188] */;
  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    EMB0_t_Flags flags;
  } EMB0_t_ObjectSignalInvalidFlags;                                 /* This data types summarizes standard deviations for movement information of an object. */
  typedef EMB0_t_ObjectSignalInvalidFlags  EMB0_t_ScamSigFlagArray[40];   /* [Satisfies_rte sws 1189] */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    EMB0_t_ObjectList_SCAM_V1::AlgoInterfaceVersionNumber_t u_VersionNumber;
    EMB0_t_ObjectList_SCAM_V1::SignalHeader_t sSigHeader;
    EMB0_t_ObjectList_SCAM_V1::EMB0_t_SensorSource sensorSource;
    unsigned long u_CurrentExternalTime;
    EMB0_t_ObjectListHeader objectListHeader;
    EMB0_t_ObjectList_SCAM_V1::EMB0_t_ObjectListCounts objectListCounts;
    EMB0_t_ObjectList_SCAM_V1::EMB0_t_ScamOriArray a_ObjRecognitionInfo;
    EMB0_t_ObjectList_SCAM_V1::EMB0_t_ScamOpiArray a_ObjPositionInfo;
    EMB0_t_ScamOeiArray a_ObjDimensionInfo;
    EMB0_t_ObjectList_SCAM_V1::EMB0_t_ScamOmiArray a_ObjMovementInfo;
    EMB0_t_ObjectList_SCAM_V1::EMB0_t_ScamPsdArray a_ObjPositionStdDev;
    EMB0_t_ObjectList_SCAM_V1::EMB0_t_ScamOmsdArray a_ObjMovementStdDev;
    EMB0_t_ObjectList_SCAM_V1::EMB0_t_ScamOpriArray a_ObjProbabilityInfo;
    EMB0_t_ScamSigFlagArray a_ObjSignalInvalidFlags;
    EMB0_t_ObjectList_SCAM_V1::EMB0_t_ScamOfciArray a_ObjFrontCameraInfo;
  } EMB0_t_ObjectList_SCAM;                                          /* @vaddr:0x20190000 @vaddr_defs: EM_MEAS_ID_B0_OBJECT_LIST_SCAM @cycleid:EM_ENV @vname:EMB0ObjDataSCam */

} // end of namespace EMB0_t_ObjectList_SCAM_V30002


// ARS4xx EMB0_t_ObjectList_SCAM version 50002                       Length = 5176
namespace EMB0_t_ObjectList_SCAM_V50002
{
  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    unsigned long u_SwVersionNumber;
    EMB0_t_ObjectList_SCAM_V1::EMB0_t_Service dataComplete;
    unsigned char u_NumOfEventGroups;
    EMB0_t_ObjectList_SCAM_V1::EMB0_t_Service commonCRC_OK;
    unsigned char u_NumberOfObjects;
    unsigned long u_Counter;
    unsigned long u_Timestamp;
    EMB0_t_ObjectList_SCAM_V1::EMB0_t_EventDataQualifier eventDataQualifier;
    EMB0_t_ObjectList_SCAM_V1::EMB0_t_ExtendedQualifier extendedQualifier;
  } EMB0_t_ObjectListHeader;                                         /* This data type provides common status information about the object property lists. */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    EMB0_t_ObjectList_SCAM_V1::AlgoInterfaceVersionNumber_t u_VersionNumber;
    EMB0_t_ObjectList_SCAM_V1::SignalHeader_t sSigHeader;
    EMB0_t_ObjectList_SCAM_V1::EMB0_t_SensorSource sensorSource;
    unsigned long u_CurrentExternalTime;
    EMB0_t_ObjectListHeader objectListHeader;
    EMB0_t_ObjectList_SCAM_V1::EMB0_t_ObjectListCounts objectListCounts;
    EMB0_t_ObjectList_SCAM_V1::EMB0_t_ScamOriArray a_ObjRecognitionInfo;
    EMB0_t_ObjectList_SCAM_V1::EMB0_t_ScamOpiArray a_ObjPositionInfo;
    EMB0_t_ObjectList_SCAM_V30002::EMB0_t_ScamOeiArray a_ObjDimensionInfo;
    EMB0_t_ObjectList_SCAM_V1::EMB0_t_ScamOmiArray a_ObjMovementInfo;
    EMB0_t_ObjectList_SCAM_V30002::EMB0_t_ScamPsdArray a_ObjPositionStdDev;
    EMB0_t_ObjectList_SCAM_V1::EMB0_t_ScamOmsdArray a_ObjMovementStdDev;
    EMB0_t_ObjectList_SCAM_V1::EMB0_t_ScamOpriArray a_ObjProbabilityInfo;
    EMB0_t_ObjectList_SCAM_V30002::EMB0_t_ScamSigFlagArray a_ObjSignalInvalidFlags;
    EMB0_t_ObjectList_SCAM_V1::EMB0_t_ScamOfciArray a_ObjFrontCameraInfo;
  } EMB0_t_ObjectList_SCAM;                                          /* @vaddr:0x20190000 @vaddr_defs: EM_MEAS_ID_B0_OBJECT_LIST_SCAM @cycleid:EM_ENV @vname:EMB0ObjDataSCam */

} // end of namespace EMB0_t_ObjectList_SCAM_V50002


// ARS4xx EMB0_t_ObjectList_SCAM version 50002                       Length = 5168
// Data package for the sim_fusion_sync connection (byte aligned structures!)
// Always provide port, never receive port!
namespace EMB0_t_ObjectList_SCAM_V50002_R
{
#pragma pack (push, 1)
  typedef struct SignalHeader_t                                      /* [Satisfies_rte sws 1191] */
  {
    EMB0_t_ObjectList_SCAM_V1::AlgoDataTimeStamp_t uiTimeStamp;
    EMB0_t_ObjectList_SCAM_V1::AlgoCycleCounter_t uiMeasurementCounter;
    EMB0_t_ObjectList_SCAM_V1::AlgoCycleCounter_t uiCycleCounter;
    EMB0_t_ObjectList_SCAM_V1::AlgoSignalState_t eSigStatus;
  } SignalHeader_t;                                                  /* Common header for all structured data types */

#pragma pack (1)
  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    unsigned long u_SwVersionNumber;
    EMB0_t_ObjectList_SCAM_V1::EMB0_t_Service dataComplete;
    unsigned char u_NumOfEventGroups;
    EMB0_t_ObjectList_SCAM_V1::EMB0_t_Service commonCRC_OK;
    unsigned char u_NumberOfObjects;
    unsigned long u_Counter;
    unsigned long u_Timestamp;
    EMB0_t_ObjectList_SCAM_V1::EMB0_t_EventDataQualifier eventDataQualifier;
    EMB0_t_ObjectList_SCAM_V1::EMB0_t_ExtendedQualifier extendedQualifier;
  } EMB0_t_ObjectListHeader;                                         /* This data type provides common status information about the object property lists. */

#pragma pack (1)
  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    float f_Length;
    float f_Width;
    float f_Height;
  } EMB0_t_ObjectDimensionInfo;                                      /* This data type summarizes object dimension information (e.g. length, width) of an object. */
  typedef EMB0_t_ObjectDimensionInfo EMB0_t_ScamOeiArray[40];        /* [Satisfies_rte sws 1189] */

#pragma pack (1)
  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    float f_StdDevPositionX;
    float f_StdDevPositionY;
    float f_StdDevPositionZ;
    float f_StdDevLength;
    float f_StdDevWidth;
    float f_StdDevHeight;
  } EMB0_t_ObjectPositionStdDev;                                     /* This data type summarizes standard deviations for position and extension information of an object. */
  typedef EMB0_t_ObjectPositionStdDev EMB0_t_ScamPsdArray[40];       /* [Satisfies_rte sws 1189] */

  typedef unsigned long EMB0_t_Flags                                 /* Discribes the invalidity of separate object signals @min: 1 @max:2147483648 @values: enum { EMB0_MSDVF_STD_DEV_SPEED_ABSOLUTE_Y_INVALID=524288,EMB0_MSDVF_STD_DEV_ACCEL_YAW_ANGLE_INVALID=4194304,EMB0_MSDVF_STD_DEV_ACCEL_ABSOLUTE_Y_INVALID=2097152,EMB0_PSDVF_STD_DEV_POSITION_Y_INVALID=8192,EMB0_DVF_WIDTH_INVALID=16,EMB0_DVF_LENGTH_INVALID=8,EMB0_MIVF_ACCEL_YAW_ANGLE_INVALID=1024,EMB0_DVF_HEIGHT_INVALID=32,EMB0_FLAGS_SNA=2147483648,EMB0_PVF_POSITION_Y_INVALID=2,EMB0_MSDVF_STD_DEV_SPEED_ABSOLUTE_X_INVALID=262144,EMB0_MIVF_SPEED_ABSOLUTE_X_INVALID=64,EMB0_PSDVF_STD_DEV_WIDTH_INVALID=65536,EMB0_MSDVF_STD_DEV_ACCEL_YAW_SPEED_INVALID=8388608,EMB0_MIVF_SPEED_ABSOLUTE_Y_INVALID=128,EMB0_MIVF_ACCEL_ABSOLUTE_X_INVALID=256,EMB0_PVF_POSITION_X_INVALID=1,EMB0_PVF_POSITION_Z_INVALID=4,EMB0_MIVF_ACCEL_YAW_SPEED_INVALID=2048,EMB0_PSDVF_STD_DEV_HEIGHT_INVALID=131072,EMB0_PSDVF_STD_DEV_LENGTH_INVALID=32768,EMB0_PSDVF_STD_DEV_POSITION_Z_INVALID=16384,EMB0_PSDVF_STD_DEV_POSITION_X_INVALID=4096,EMB0_MIVF_ACCEL_ABSOLUTE_Y_INVALID=512,EMB0_MSDVF_STD_DEV_ACCEL_ABSOLUTE_X_INVALID=1048576,} */ /* [Satisfies_rte sws 1188] */;
#pragma pack (1)
  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    EMB0_t_Flags flags;
  } EMB0_t_ObjectSignalInvalidFlags;                                 /* This data types summarizes standard deviations for movement information of an object. */
  typedef EMB0_t_ObjectSignalInvalidFlags  EMB0_t_ScamSigFlagArray[40];   /* [Satisfies_rte sws 1189] */

#pragma pack (1)
  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    EMB0_t_ObjectList_SCAM_V1::AlgoInterfaceVersionNumber_t u_VersionNumber;
    SignalHeader_t sSigHeader;
    EMB0_t_ObjectList_SCAM_V1::EMB0_t_SensorSource sensorSource;
    unsigned long u_CurrentExternalTime;
    EMB0_t_ObjectListHeader objectListHeader;
    EMB0_t_ObjectList_SCAM_V1::EMB0_t_ObjectListCounts objectListCounts;
    EMB0_t_ObjectList_SCAM_V1::EMB0_t_ScamOriArray a_ObjRecognitionInfo;
    EMB0_t_ObjectList_SCAM_V1::EMB0_t_ScamOpiArray a_ObjPositionInfo;
    EMB0_t_ScamOeiArray a_ObjDimensionInfo;
    EMB0_t_ObjectList_SCAM_V1::EMB0_t_ScamOmiArray a_ObjMovementInfo;
    EMB0_t_ObjectList_SCAM_V1::EMB0_t_ScamPsdArray a_ObjPositionStdDev;
    EMB0_t_ObjectList_SCAM_V1::EMB0_t_ScamOmsdArray a_ObjMovementStdDev;
    EMB0_t_ObjectList_SCAM_V1::EMB0_t_ScamOpriArray a_ObjProbabilityInfo;
    EMB0_t_ScamSigFlagArray a_ObjSignalInvalidFlags;
    EMB0_t_ObjectList_SCAM_V1::EMB0_t_ScamOfciArray a_ObjFrontCameraInfo;
  } EMB0_t_ObjectList_SCAM;                                          /* @vaddr:0x20190000 @vaddr_defs: EM_MEAS_ID_B0_OBJECT_LIST_SCAM @cycleid:EM_ENV @vname:EMB0ObjDataSCam */

#pragma pack (pop)
} // end of namespace EMB0_t_ObjectList_SCAM_V50002_R

// ARS4xx EMB0_t_ObjectList_SCAM version 80003_RM                    Length = 5167
// Data package for the sim_fusion_sync connection (byte aligned structures!)
// Interface change, but the export to the bsig went wrong and a byte was missing.
// Always provide port, never receive port!
namespace EMB0_t_ObjectList_SCAM_V80003_RM
{
#pragma pack (push, 1)
  typedef struct SignalHeader_t                                      /* [Satisfies_rte sws 1191] */
  {
    EMB0_t_ObjectList_SCAM_V1::AlgoDataTimeStamp_t uiTimeStamp;
    EMB0_t_ObjectList_SCAM_V1::AlgoCycleCounter_t uiMeasurementCounter;
    EMB0_t_ObjectList_SCAM_V1::AlgoCycleCounter_t uiCycleCounter;
    EMB0_t_ObjectList_SCAM_V1::AlgoSignalState_t eSigStatus;
  } SignalHeader_t;                                                  /* Common header for all structured data types */

#pragma pack (1)
  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    unsigned long u_SwVersionNumber;
    EMB0_t_ObjectList_SCAM_V1::EMB0_t_Service dataComplete;
    unsigned char u_NumOfEventGroups;
    EMB0_t_ObjectList_SCAM_V1::EMB0_t_Service commonCRC_OK;
    unsigned char u_NumberOfObjects;
    unsigned long u_Counter;
    unsigned long u_Timestamp;
    EMB0_t_ObjectList_SCAM_V1::EMB0_t_EventDataQualifier eventDataQualifier;
    EMB0_t_ObjectList_SCAM_V1::EMB0_t_ExtendedQualifier extendedQualifier;
  } EMB0_t_ObjectListHeader;                                         /* This data type provides common status information about the object property lists. */

#pragma pack (1)
  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    unsigned char u_NumberOfPedestrians;
    unsigned char u_NumberOfCyclists;
    unsigned char u_NumberOfBikes;
    unsigned char u_NumberOfCars;
    unsigned char u_NumberOfTrucks;
    unsigned char u_NumberOfOtherVehicles;
    unsigned char u_NumberOfRoadBoundaries;
    unsigned char u_NumberOfBridges;
    unsigned char u_NumberOfUnknownObjects;
    unsigned char u_NumberOfFreeFormObjects;
    //unsigned char dummy_82;                                        /* or u_NumberOfTrafficLights */
    unsigned char dummy_83;
  } EMB0_t_ObjectListCounts;                                         /* This data type provides a brief summary of object type distribution over in the lists (e.g. how many cars, how many bikes). */

#pragma pack (1)
  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    float f_Length;
    float f_Width;
    float f_Height;
  } EMB0_t_ObjectDimensionInfo;                                      /* This data type summarizes object dimension information (e.g. length, width) of an object. */
  typedef EMB0_t_ObjectDimensionInfo EMB0_t_ScamOeiArray[40];        /* [Satisfies_rte sws 1189] */

#pragma pack (1)
  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    float f_StdDevPositionX;
    float f_StdDevPositionY;
    float f_StdDevPositionZ;
    float f_StdDevLength;
    float f_StdDevWidth;
    float f_StdDevHeight;
  } EMB0_t_ObjectPositionStdDev;                                     /* This data type summarizes standard deviations for position and extension information of an object. */
  typedef EMB0_t_ObjectPositionStdDev EMB0_t_ScamPsdArray[40];       /* [Satisfies_rte sws 1189] */

  typedef unsigned long EMB0_t_Flags                                 /* Discribes the invalidity of separate object signals @min: 1 @max:2147483648 @values: enum { EMB0_MSDVF_STD_DEV_SPEED_ABSOLUTE_Y_INVALID=524288,EMB0_MSDVF_STD_DEV_ACCEL_YAW_ANGLE_INVALID=4194304,EMB0_MSDVF_STD_DEV_ACCEL_ABSOLUTE_Y_INVALID=2097152,EMB0_PSDVF_STD_DEV_POSITION_Y_INVALID=8192,EMB0_DVF_WIDTH_INVALID=16,EMB0_DVF_LENGTH_INVALID=8,EMB0_MIVF_ACCEL_YAW_ANGLE_INVALID=1024,EMB0_DVF_HEIGHT_INVALID=32,EMB0_FLAGS_SNA=2147483648,EMB0_PVF_POSITION_Y_INVALID=2,EMB0_MSDVF_STD_DEV_SPEED_ABSOLUTE_X_INVALID=262144,EMB0_MIVF_SPEED_ABSOLUTE_X_INVALID=64,EMB0_PSDVF_STD_DEV_WIDTH_INVALID=65536,EMB0_MSDVF_STD_DEV_ACCEL_YAW_SPEED_INVALID=8388608,EMB0_MIVF_SPEED_ABSOLUTE_Y_INVALID=128,EMB0_MIVF_ACCEL_ABSOLUTE_X_INVALID=256,EMB0_PVF_POSITION_X_INVALID=1,EMB0_PVF_POSITION_Z_INVALID=4,EMB0_MIVF_ACCEL_YAW_SPEED_INVALID=2048,EMB0_PSDVF_STD_DEV_HEIGHT_INVALID=131072,EMB0_PSDVF_STD_DEV_LENGTH_INVALID=32768,EMB0_PSDVF_STD_DEV_POSITION_Z_INVALID=16384,EMB0_PSDVF_STD_DEV_POSITION_X_INVALID=4096,EMB0_MIVF_ACCEL_ABSOLUTE_Y_INVALID=512,EMB0_MSDVF_STD_DEV_ACCEL_ABSOLUTE_X_INVALID=1048576,} */ /* [Satisfies_rte sws 1188] */;
#pragma pack (1)
  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    EMB0_t_Flags flags;
  } EMB0_t_ObjectSignalInvalidFlags;                                 /* This data types summarizes standard deviations for movement information of an object. */
  typedef EMB0_t_ObjectSignalInvalidFlags  EMB0_t_ScamSigFlagArray[40];   /* [Satisfies_rte sws 1189] */

#pragma pack (1)
  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    EMB0_t_ObjectList_SCAM_V1::AlgoInterfaceVersionNumber_t u_VersionNumber;
    SignalHeader_t sSigHeader;
    EMB0_t_ObjectList_SCAM_V1::EMB0_t_SensorSource sensorSource;
    unsigned long u_CurrentExternalTime;
    EMB0_t_ObjectListHeader objectListHeader;
    EMB0_t_ObjectListCounts objectListCounts;
    EMB0_t_ObjectList_SCAM_V1::EMB0_t_ScamOriArray a_ObjRecognitionInfo;
    EMB0_t_ObjectList_SCAM_V1::EMB0_t_ScamOpiArray a_ObjPositionInfo;
    EMB0_t_ScamOeiArray a_ObjDimensionInfo;
    EMB0_t_ObjectList_SCAM_V1::EMB0_t_ScamOmiArray a_ObjMovementInfo;
    EMB0_t_ObjectList_SCAM_V1::EMB0_t_ScamPsdArray a_ObjPositionStdDev;
    EMB0_t_ObjectList_SCAM_V1::EMB0_t_ScamOmsdArray a_ObjMovementStdDev;
    EMB0_t_ObjectList_SCAM_V1::EMB0_t_ScamOpriArray a_ObjProbabilityInfo;
    EMB0_t_ScamSigFlagArray a_ObjSignalInvalidFlags;
    EMB0_t_ObjectList_SCAM_V1::EMB0_t_ScamOfciArray a_ObjFrontCameraInfo;
  } EMB0_t_ObjectList_SCAM;                                          /* @vaddr:0x20190000 @vaddr_defs: EM_MEAS_ID_B0_OBJECT_LIST_SCAM @cycleid:EM_ENV @vname:EMB0ObjDataSCam */

#pragma pack (pop)
} // end of namespace EMB0_t_ObjectList_SCAM_V80003_RM

// ARS4xx EMB0_t_ObjectList_SCAM version 0x000D0006             Length = 5176
// Data package for the sim_fusion_sync connection (byte aligned structures!)
// Interface change, but the export to the bsig went wrong and a byte was missing.
// Always provide port, never receive port!
namespace EMB0_t_ObjectList_SCAM_V000A0004
{

  typedef unsigned char EMB0_t_EventDataQualifier /* The qualifier expresses whether the content of this event can be used or not. @min: 0 @max:255 @values: enum { EMB0_CEDQ_EVENT_DATA_AVAILABLE=0,EMB0_CEDQ_SNA=255,EMB0_CEDQ_EVENT_DATA_AVAILABLE_REDUCED=1,EMB0_CEDQ_EVENT_DATA_NOT_AVAILABLE=2,} */	/* [Satisfies_rte sws 1188] */;
  typedef unsigned char EMB0_t_ExtendedQualifier  /* The extendedQualifier describes the reason (not the effect) why the service is reduced or not available. @min: 0 @max:255 @values: enum { EMB0_CEQ_SENSOR_NOT_CALIBRATED=2,EMB0_CEQ_INTERNAL_REASON=8,EMB0_CEQ_INPUT_NOT_AVAILABLE=7,EMB0_CEQ_NORMAL_OPERATION_MODE=0,EMB0_CEQ_POWER_UP_OR_DOWN=1,EMB0_CEQ_SNA=255,EMB0_CEQ_BAD_SENSOR_ENVIRONMENTAL_CONDITION=5,EMB0_CEQ_SENSOR_BLOCKED=3,EMB0_CEQ_BEGINNING_BLOCKAGE=10,EMB0_CEQ_SENSOR_MISALIGNED=4,EMB0_CEQ_EXTERNAL_DISTORTION=9,EMB0_CEQ_REDUCED_FIELD_OF_VIEW=6,} */	/* [Satisfies_rte sws 1188] */;
  typedef unsigned long EMB0_t_Flags              /* Discribes the invalidity of separate object signals @min: 1 @max:2147483648 @values: enum { EMB0_MSDVF_STD_DEV_YAW_SPEED_INVALID=8388608,EMB0_MSDVF_STD_DEV_SPEED_ABSOLUTE_Y_INVALID=524288,EMB0_PSDVF_STD_DEV_POSITION_Y_INVALID=8192,EMB0_DVF_WIDTH_INVALID=16,EMB0_DVF_LENGTH_INVALID=8,EMB0_DVF_HEIGHT_INVALID=32,EMB0_FLAGS_SNA=2147483648,EMB0_PVF_POSITION_Y_INVALID=2,EMB0_MSDVF_STD_DEV_SPEED_ABSOLUTE_X_INVALID=262144,EMB0_MIVF_SPEED_ABSOLUTE_X_INVALID=64,EMB0_PSDVF_STD_DEV_WIDTH_INVALID=65536,EMB0_MIVF_SPEED_ABSOLUTE_Y_INVALID=128,EMB0_MIVF_ACCEL_ABSOLUTE_X_INVALID=256,EMB0_PVF_POSITION_X_INVALID=1,EMB0_PVF_POSITION_Z_INVALID=4,EMB0_MSDVF_STD_DEV_ACCEL_ABSOLUTE_Y_INVALID=2097152,EMB0_PSDVF_STD_DEV_HEIGHT_INVALID=131072,EMB0_MSDVF_STD_DEV_YAW_ANGLE_INVALID=4194304,EMB0_MIVF_YAW_SPEED_INVALID=2048,EMB0_PSDVF_STD_DEV_LENGTH_INVALID=32768,EMB0_PSDVF_STD_DEV_POSITION_Z_INVALID=16384,EMB0_PSDVF_STD_DEV_POSITION_X_INVALID=4096,EMB0_MIVF_ACCEL_ABSOLUTE_Y_INVALID=512,EMB0_MSDVF_STD_DEV_ACCEL_ABSOLUTE_X_INVALID=1048576,EMB0_MIVF_YAW_ANGLE_INVALID=1024,} */	/* [Satisfies_rte sws 1188] */;
  typedef unsigned char EMB0_t_SensorSource       /* Enumberation to identify the sensor reporting an specific object list @min: 0 @max:9 @values: enum { EMB0_OBJECT_LIST_SOURCE_LRR=1,EMB0_OBJECT_LIST_SOURCE_SCAM=9,EMB0_OBJECT_LIST_SOURCE_MCAM=8,EMB0_OBJECT_LIST_SOURCE_SRL=7,EMB0_OBJECT_LIST_SOURCE_SRR_FR=4,EMB0_OBJECT_LIST_SOURCE_SRR_RR=6,EMB0_OBJECT_LIST_SOURCE_SRR_RL=5,EMB0_OBJECT_LIST_SOURCE_SRR_FL=3,EMB0_OBJECT_LIST_SOURCE_NONE=0,EMB0_OBJECT_LIST_SOURCE_MRR=2,} */	/* [Satisfies_rte sws 1188] */;
  typedef unsigned char EMB0_t_Service            /* Common status qualifier. @min: 0 @max:255 @values: enum { EMB0_QS_NOT_OK=2,EMB0_QS_INIT=0,EMB0_QS_SNA=255,EMB0_QS_OK=1,} */	/* [Satisfies_rte sws 1188] */;
  typedef unsigned char EMB0_t_DrivingTubeMapping /* Association to the driving lane of the object. @min: 0 @max:255 @values: enum { EMB0_DTM_SNA=255,EMB0_DTM_EGO_LANE=1,EMB0_DTM_NEXT_RIGHT=4,EMB0_DTM_FAR_RIGHT=5,EMB0_DTM_NEXT_LEFT=2,EMB0_DTM_FAR_LEFT=3,EMB0_DTM_INIT_UNKNOWN=0,} */	/* [Satisfies_rte sws 1188] */;
  typedef unsigned char EMB0_t_MeasurementStatus  /* Measurement status of object, e.g. measured, predicted, etc. @min: 0 @max:255 @values: enum { EMB0_CMS_MEAS_PART_OCCL=3,EMB0_CMS_MEAS_NEW=0,EMB0_CMS_MEAS=2,EMB0_CMS_SNA=255,EMB0_CMS_MEAS_NEW_PART_OCCL=1,EMB0_CMS_PRED_PART_OCCL=5,EMB0_CMS_PRED=4,} */	/* [Satisfies_rte sws 1188] */;
  typedef unsigned char EMB0_t_ObjBrakeLightStat  /* This enum provides a status of the brake light of the object. @min: 0 @max:255 @values: enum { EMB0_BLS_NO_BRAKING=1,EMB0_BLS_REGULAR_BRAKING=2,EMB0_BLS_HEAVY_BREAKING=3,EMB0_BLS_STATUS_UNKNOWN=0,EMB0_BLS_SNA=255,} */	/* [Satisfies_rte sws 1188] */;
  typedef unsigned char EMB0_t_ObjFlashLightStat  /* Status of the flash light of the object. @min: 0 @max:255 @values: enum { EMB0_OFS_SNA=255,EMB0_OFS_HAZARD_FLASHING=4,EMB0_OFS_NO_FLASHING=1,EMB0_OFS_STATUS_UNKNOWN=0,EMB0_OFS_FLASHING_LEFT=2,EMB0_OFS_FLASHING_RIGHT=3,} */	/* [Satisfies_rte sws 1188] */;
  typedef unsigned char EMB0_t_ObjectModeLateral  /* Movement status lateral. @min: 0 @max:255 @values: enum { EMB0_OML_SNA=255,EMB0_OML_CUTTING_IN_FROM_LEFT=1,EMB0_OML_NONE=5,EMB0_OML_CUTTING_OUT_TO_LEFT=3,EMB0_OML_UNKNOWN=0,EMB0_OML_CUTTING_OUT_TO_RIGHT=4,EMB0_OML_CUTTING_IN_FROM_RIGHT=2,} */	/* [Satisfies_rte sws 1188] */;
  typedef unsigned char EMB0_t_ObjectMovementStatus /* Movement status of object, e.g. moving in own direction, stopped, etc. @min: 0 @max:255 @values: enum { EMB0_OMS_SNA=255,EMB0_OMS_STOPPED_WAS_ONGOING=2,EMB0_OMS_STATIONARY_PARKING=0,EMB0_OMS_STOPPED_WAS_UNKNOWN=3,EMB0_OMS_CROSSING=7,EMB0_OMS_MOVING_ONGOING=5,EMB0_OMS_MOVING_ONCOMMING=4,EMB0_OMS_MOVING_DIR_UNKNOWN=6,EMB0_OMS_STOPPED_WAS_ONCOMING=1,} */	/* [Satisfies_rte sws 1188] */;
  typedef unsigned char EMB0_t_ObjectReferencePoint /* This enum identifies the corner of the object the sensor has observed. The whole measurement originates from the reference point. @min: 0 @max:255 @values: enum { EMB0_ORP_CORNER_FRONT_LEFT=0,EMB0_ORP_CORNER_REAR_LEFT=6,EMB0_ORP_MIDDLE_SIDE_RIGHT=3,EMB0_ORP_CORNER_REAR_RIGHT=4,EMB0_ORP_SNA=255,EMB0_ORP_MIDDLE_SIDE_LEFT=7,EMB0_ORP_MIDDLE_FRONT=1,EMB0_ORP_CORNER_FRONT_RIGHT=2,EMB0_ORP_MIDDLE_REAR=5,} */	/* [Satisfies_rte sws 1188] */;
  typedef unsigned char EMB0_t_ObjectType         /* Discrete classification type based on probabilities within the classification vector. This is the most likely type of the object based on the classification. @min: 0 @max:255 @values: enum { EMB0_OT_ROAD_BOUNDARY=6,EMB0_OT_MOTORBIKE=2,EMB0_OT_TRUCK=4,EMB0_OT_SNA=255,EMB0_OT_UNKNOWN=8,EMB0_OT_CYCLIST=1,EMB0_OT_PEDESTRIAN=0,EMB0_OT_CAR=3,EMB0_OT_OTHER_VEHICLE=5,EMB0_OT_BRIDGE=7,} */	/* [Satisfies_rte sws 1188] */;
  typedef unsigned long AlgoInterfaceVersionNumber_t /* Algo interface version nummbers @min:0 @max:4294967295 */	/* [Satisfies_rte sws 1188] */;
  typedef unsigned short AlgoCycleCounter_t        /* Algo cycle counter @min:0 @max:65535 */	/* [Satisfies_rte sws 1188] */;
  typedef unsigned long AlgoDataTimeStamp_t       /* Algo data time-stamp type (32 bit variant) @min:0 @max:4294967295 */	/* [Satisfies_rte sws 1188] */;
  typedef unsigned char AlgoSignalState_t         /* Algo signal state enumeration @min: 0 @max:2 @values: enum { AL_SIG_STATE_INVALID=2,AL_SIG_STATE_INIT=0,AL_SIG_STATE_OK=1,} */	/* [Satisfies_rte sws 1188] */;
  typedef unsigned char percentage_t              /* percentage @min:0 @max:100 @resolution:1.0 */	/* [Satisfies_rte sws 1188] */;

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    float f_Length;
    float f_Width;
    float f_Height;
  } EMB0_t_ObjectDimensionInfo;			/* This data type summarizes object dimension information (e.g. length, width) of an object. */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    unsigned char u_NumberOfPedestrians;
    unsigned char u_NumberOfCyclists;
    unsigned char u_NumberOfBikes;
    unsigned char u_NumberOfCars;
    unsigned char u_NumberOfTrucks;
    unsigned char u_NumberOfOtherVehicles;
    unsigned char u_NumberOfRoadBoundaries;
    unsigned char u_NumberOfBridges;
    unsigned char u_NumberOfUnknownObjects;
    unsigned char u_NumberOfFreeFormObjects;
    unsigned char dummy_82;
    unsigned char dummy_83;
  } EMB0_t_ObjectListCounts;			/* This data type provides a brief summary of object type distribution over in the lists (e.g. how many cars, how many bikes). */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    float f_SpeedAbsoluteX;
    float f_SpeedAbsoluteY;
    float f_AccelAbsoluteX;
    float f_AccelAbsoluteY;
    float f_YawAngle;
    float f_YawSpeed;
  } EMB0_t_ObjectMovementInfo;			/* This data type summarizes absolute speed and yaw angle information of an object. */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    float f_StdDevSpeedAbsoluteX;
    float f_StdDevSpeedAbsoluteY;
    float f_StdDevAccelAbsoluteX;
    float f_StdDevAccelAbsoluteY;
    float f_StdDevYawAngle;
    float f_StdDevYawSpeed;
  } EMB0_t_ObjectMovementStdDev;			/* This data types summarizes standard deviations for movement information of an object. */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    float f_PositionX;
    float f_PositionY;
    float f_PositionZ;
  } EMB0_t_ObjectPositionInfo;			/* This data type summarizes object position information. The coordinates are in vehicle coordinate system. */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    float f_StdDevPositionX;
    float f_StdDevPositionY;
    float f_StdDevPositionZ;
    float f_StdDevLength;
    float f_StdDevWidth;
    float f_StdDevHeight;
  } EMB0_t_ObjectPositionStdDev;			/* This data type summarizes standard deviations for position and extension information of an object. */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    percentage_t existenceProbability;
    percentage_t probabilityPedestrian;
    percentage_t probabilityCyclist;
    percentage_t probabilityBike;
    percentage_t probabilityCar;
    percentage_t propabilityTruck;
    percentage_t probabilityOtherVehicles;
    percentage_t probabilityRoadBoundary;
    percentage_t probabilityBridge;
    percentage_t probabilityUnknown;
    unsigned char dummy_81;
    unsigned char dummy_82;
  } EMB0_t_ObjectProbabilityInfo;			/* This data type represents the classification vector of an object. An object can be classified with 80% as car and 20% as truck. The individual probabilities are stored in this data type. */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    unsigned char u_ObjectId;
    EMB0_t_MeasurementStatus statusMeasurement;
    EMB0_t_ObjectMovementStatus statusMovement;
    EMB0_t_ObjectType classificationType;
    EMB0_t_ObjectModeLateral modeLateral;
    EMB0_t_DrivingTubeMapping drivingTubeMapping;
    EMB0_t_ObjectReferencePoint referencePoint;
    unsigned char dummy_81;
  } EMB0_t_ObjectRecognitionInfo;			/* This datatype summarizes status information of an object. */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    EMB0_t_Flags flags;
  } EMB0_t_ObjectSignalInvalidFlags;			/* This data types summarizes standard deviations for movement information of an object. */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    EMB0_t_ObjFlashLightStat statusFlashLight;
    EMB0_t_ObjBrakeLightStat statusBrakingLight;
    percentage_t percentageOwnDrivingLane;
    percentage_t percentageSideDrivingLaneLeft;
    percentage_t percentageSideDrivingLaneRight;
    unsigned char dummy_81;
    unsigned char dummy_82;
    unsigned char dummy_83;
  } EMB0_t_ObjectFrontCameraInfo;			/* This data type contains information provided by front camera only, e.g. brakelight status or status of blinker which is not visible for other sensors. */

  typedef EMB0_t_ObjectDimensionInfo 	EMB0_t_ScamOeiArray[40];			/* [Satisfies_rte sws 1189] */
  typedef EMB0_t_ObjectMovementInfo 	EMB0_t_ScamOmiArray[40];			/* [Satisfies_rte sws 1189] */
  typedef EMB0_t_ObjectMovementStdDev 	EMB0_t_ScamOmsdArray[40];			/* [Satisfies_rte sws 1189] */
  typedef EMB0_t_ObjectPositionInfo 	EMB0_t_ScamOpiArray[40];			/* [Satisfies_rte sws 1189] */
  typedef EMB0_t_ObjectPositionStdDev 	EMB0_t_ScamPsdArray[40];			/* [Satisfies_rte sws 1189] */
  typedef EMB0_t_ObjectFrontCameraInfo 	EMB0_t_ScamOfciArray[40];			/* [Satisfies_rte sws 1189] */
  typedef EMB0_t_ObjectProbabilityInfo 	EMB0_t_ScamOpriArray[40];			/* [Satisfies_rte sws 1189] */
  typedef EMB0_t_ObjectRecognitionInfo 	EMB0_t_ScamOriArray[40];			/* [Satisfies_rte sws 1189] */
  typedef EMB0_t_ObjectSignalInvalidFlags 	EMB0_t_ScamSigFlagArray[40];			/* [Satisfies_rte sws 1189] */
  
  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    unsigned long u_SwVersionNumber;
    EMB0_t_Service dataComplete;
    unsigned char u_NumOfEventGroups;
    EMB0_t_Service commonCRC_OK;
    unsigned char u_NumberOfObjects;
    unsigned long u_Counter;
    unsigned long u_Timestamp;
    EMB0_t_EventDataQualifier eventDataQualifier;
    EMB0_t_ExtendedQualifier extendedQualifier;
  } EMB0_t_ObjectListHeader;			/* This data type provides common status information about the object property lists. */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    AlgoDataTimeStamp_t uiTimeStamp;
    AlgoCycleCounter_t uiMeasurementCounter;
    AlgoCycleCounter_t uiCycleCounter;
    AlgoSignalState_t eSigStatus;
  } SignalHeader_t;			/* Common header for all structured data types */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    AlgoInterfaceVersionNumber_t u_VersionNumber;
    SignalHeader_t sSigHeader;
    EMB0_t_SensorSource sensorSource;
    unsigned long u_CurrentExternalTime;
    EMB0_t_ObjectListHeader objectListHeader;
    EMB0_t_ObjectListCounts objectListCounts;
    EMB0_t_ScamOriArray a_ObjRecognitionInfo;
    EMB0_t_ScamOpiArray a_ObjPositionInfo;
    EMB0_t_ScamOeiArray a_ObjDimensionInfo;
    EMB0_t_ScamOmiArray a_ObjMovementInfo;
    EMB0_t_ScamPsdArray a_ObjPositionStdDev;
    EMB0_t_ScamOmsdArray a_ObjMovementStdDev;
    EMB0_t_ScamOpriArray a_ObjProbabilityInfo;
    EMB0_t_ScamSigFlagArray a_ObjSignalInvalidFlags;
    EMB0_t_ScamOfciArray a_ObjFrontCameraInfo;
  } EMB0_t_ObjectList_SCAM;			/* @vaddr:0x20190000 @vaddr_defs: EM_MEAS_ID_B0_OBJECT_LIST_SCAM @cycleid:EM_ENV @vname:EMB0ObjDataSCam */
}

// ARS4xx EMB0_t_ObjectList_SCAM version 0x000D0006             Length = 3284
// Data package for the sim_fusion_sync connection (byte aligned structures!)
// Interface change, but the export to the bsig went wrong and a byte was missing.
// Always provide port, never receive port!
namespace EMB0_t_ObjectList_SCAM_V000D0006
{
  typedef unsigned char AlgoSignalState_t         /* Algo signal state enumeration @min: 0 @max:2 @values: enum { AL_SIG_STATE_INVALID=2,AL_SIG_STATE_INIT=0,AL_SIG_STATE_OK=1,} */	/* [Satisfies_rte sws 1188] */;
  typedef unsigned short AlgoCycleCounter_t        /* Algo cycle counter @min:0 @max:65535 */	/* [Satisfies_rte sws 1188] */;
  typedef unsigned long AlgoDataTimeStamp_t       /* Algo data time-stamp type (32 bit variant) @min:0 @max:4294967295 */	/* [Satisfies_rte sws 1188] */;

  typedef unsigned long AlgoInterfaceVersionNumber_t /* Algo interface version nummbers @min:0 @max:4294967295 */	/* [Satisfies_rte sws 1188] */;
  typedef unsigned char percentage_t                                 /* percentage @min:0 @max:100 @resolution:1.0 */ /* [Satisfies_rte sws 1188] */;
  typedef unsigned char EMB0_t_SensorSource       /* Enumberation to identify the sensor reporting an specific object list @min: 0 @max:9 @values: enum { EMB0_OBJECT_LIST_SOURCE_LRR=1,EMB0_OBJECT_LIST_SOURCE_SCAM=9,EMB0_OBJECT_LIST_SOURCE_MCAM=8,EMB0_OBJECT_LIST_SOURCE_SRL=7,EMB0_OBJECT_LIST_SOURCE_SRR_FR=4,EMB0_OBJECT_LIST_SOURCE_SRR_RR=6,EMB0_OBJECT_LIST_SOURCE_SRR_RL=5,EMB0_OBJECT_LIST_SOURCE_SRR_FL=3,EMB0_OBJECT_LIST_SOURCE_NONE=0,EMB0_OBJECT_LIST_SOURCE_MRR=2,} */	/* [Satisfies_rte sws 1188] */;
  typedef unsigned char EMB0_t_DrivingTubeMapping /* Association to the driving lane of the object. @min: 0 @max:255 @values: enum { EMB0_DTM_SNA=255,EMB0_DTM_EGO_LANE=1,EMB0_DTM_NEXT_RIGHT=4,EMB0_DTM_FAR_RIGHT=5,EMB0_DTM_NEXT_LEFT=2,EMB0_DTM_FAR_LEFT=3,EMB0_DTM_INIT_UNKNOWN=0,} */	/* [Satisfies_rte sws 1188] */;
  typedef unsigned char EMB0_t_MeasurementStatus  /* Measurement status of object, e.g. measured, predicted, etc. @min: 0 @max:255 @values: enum { EMB0_CMS_MEAS_PART_OCCL=3,EMB0_CMS_MEAS_NEW=0,EMB0_CMS_MEAS=2,EMB0_CMS_SNA=255,EMB0_CMS_MEAS_NEW_PART_OCCL=1,EMB0_CMS_PRED_PART_OCCL=5,EMB0_CMS_PRED=4,} */	/* [Satisfies_rte sws 1188] */;
  typedef unsigned char EMB0_t_ObjCollisionStatus /* This flag provides whether the object is verified as collision critical from the camera. Information about the defined thresholds will be provided in a future distribution due to its specification during the development process. @min: 0 @max:255 @values: enum { EMB0_STC_SNA=255,EMB0_STC_COLLISION_CRIT_HOLD=3,EMB0_STC_COLLISION_CRIT_VERIFIED=2,EMB0_STC_NO_COLLISION_CRIT=1,EMB0_STC_UNKNOWN=0,} */	/* [Satisfies_rte sws 1188] */;
  typedef unsigned char EMB0_t_ObjectModeLateral  /* Movement status lateral. @min: 0 @max:255 @values: enum { EMB0_OML_SNA=255,EMB0_OML_CUTTING_IN_FROM_LEFT=1,EMB0_OML_NONE=5,EMB0_OML_CUTTING_OUT_TO_LEFT=3,EMB0_OML_UNKNOWN=0,EMB0_OML_CUTTING_OUT_TO_RIGHT=4,EMB0_OML_CUTTING_IN_FROM_RIGHT=2,} */	/* [Satisfies_rte sws 1188] */;
  typedef unsigned char EMB0_t_ObjectMovementStatus /* Movement status of object, e.g. moving in own direction, stopped, etc. @min: 0 @max:255 @values: enum { EMB0_OMS_STOPPED_WAS_ONGOING=2,EMB0_OMS_STATIONARY_PARKING=0,EMB0_OMS_STATIONARY_PARKING_ONGOING=9,EMB0_OMS_CROSSING=7,EMB0_OMS_MOVING_ONGOING=5,EMB0_OMS_STATIONARY_PARKING_CROSSING=10,EMB0_OMS_STOPPED_WAS_CROSSING=3,EMB0_OMS_MOVING_ONCOMMING=4,EMB0_OMS_SNA=255,EMB0_OMS_STOPPED_WAS_ONCOMING=1,EMB0_OMS_STATIONARY_PARKING_ONCOMING=8,} */	/* [Satisfies_rte sws 1188] */;
  typedef unsigned char EMB0_t_ObjectReferencePoint /* This enum identifies the corner of the object the sensor has observed. The whole measurement originates from the reference point. @min: 0 @max:255 @values: enum { EMB0_ORP_CORNER_FRONT_LEFT=0,EMB0_ORP_CORNER_REAR_LEFT=6,EMB0_ORP_MIDDLE_SIDE_RIGHT=3,EMB0_ORP_CORNER_REAR_RIGHT=4,EMB0_ORP_SNA=255,EMB0_ORP_MIDDLE_SIDE_LEFT=7,EMB0_ORP_MIDDLE_FRONT=1,EMB0_ORP_CORNER_FRONT_RIGHT=2,EMB0_ORP_MIDDLE_REAR=5,} */	/* [Satisfies_rte sws 1188] */;
  typedef unsigned char EMB0_t_ObjectType         /* Discrete classification type based on probabilities within the classification vector. This is the most likely type of the object based on the classification. @min: 0 @max:255 @values: enum { EMB0_OT_ROAD_BOUNDARY=6,EMB0_OT_MOTORBIKE=2,EMB0_OT_TRUCK=4,EMB0_OT_SNA=255,EMB0_OT_UNKNOWN=8,EMB0_OT_CYCLIST=1,EMB0_OT_PEDESTRIAN=0,EMB0_OT_CAR=3,EMB0_OT_OTHER_VEHICLE=5,EMB0_OT_BRIDGE=7,} */	/* [Satisfies_rte sws 1188] */;
  typedef unsigned char EMB0_t_ObjBrakeLightStat  /* This enum provides a status of the brake light of the object. @min: 0 @max:255 @values: enum { EMB0_BLS_NO_BRAKING=1,EMB0_BLS_REGULAR_BRAKING=2,EMB0_BLS_HEAVY_BREAKING=3,EMB0_BLS_STATUS_UNKNOWN=0,EMB0_BLS_SNA=255,} */	/* [Satisfies_rte sws 1188] */;
  typedef unsigned char EMB0_t_ObjFlashLightStat  /* Status of the flash light of the object. @min: 0 @max:255 @values: enum { EMB0_OFS_SNA=255,EMB0_OFS_HAZARD_FLASHING=4,EMB0_OFS_NO_FLASHING=1,EMB0_OFS_STATUS_UNKNOWN=0,EMB0_OFS_FLASHING_LEFT=2,EMB0_OFS_FLASHING_RIGHT=3,} */	/* [Satisfies_rte sws 1188] */;
  typedef unsigned long EMB0_t_Flags              /* Discribes the invalidity of separate object signals @min: 1 @max:2147483648 @values: enum { EMB0_MSDVF_STD_DEV_YAW_SPEED_INVALID=8388608,EMB0_MSDVF_STD_DEV_SPEED_ABSOLUTE_Y_INVALID=524288,EMB0_PSDVF_STD_DEV_POSITION_Y_INVALID=8192,EMB0_DVF_WIDTH_INVALID=16,EMB0_DVF_LENGTH_INVALID=8,EMB0_DVF_HEIGHT_INVALID=32,EMB0_FLAGS_SNA=2147483648,EMB0_PVF_POSITION_Y_INVALID=2,EMB0_MSDVF_STD_DEV_SPEED_ABSOLUTE_X_INVALID=262144,EMB0_MIVF_SPEED_ABSOLUTE_X_INVALID=64,EMB0_PSDVF_STD_DEV_WIDTH_INVALID=65536,EMB0_MIVF_SPEED_ABSOLUTE_Y_INVALID=128,EMB0_MIVF_ACCEL_ABSOLUTE_X_INVALID=256,EMB0_PVF_POSITION_X_INVALID=1,EMB0_PVF_POSITION_Z_INVALID=4,EMB0_MSDVF_STD_DEV_ACCEL_ABSOLUTE_Y_INVALID=2097152,EMB0_PSDVF_STD_DEV_HEIGHT_INVALID=131072,EMB0_MSDVF_STD_DEV_YAW_ANGLE_INVALID=4194304,EMB0_MIVF_YAW_SPEED_INVALID=2048,EMB0_PSDVF_STD_DEV_LENGTH_INVALID=32768,EMB0_PSDVF_STD_DEV_POSITION_Z_INVALID=16384,EMB0_PSDVF_STD_DEV_POSITION_X_INVALID=4096,EMB0_MIVF_ACCEL_ABSOLUTE_Y_INVALID=512,EMB0_MSDVF_STD_DEV_ACCEL_ABSOLUTE_X_INVALID=1048576,EMB0_MIVF_YAW_ANGLE_INVALID=1024,} */	/* [Satisfies_rte sws 1188] */;

// #pragma pack (push, 1)
// #pragma pack (1)
  typedef struct SignalHeader_t                                      /* [Satisfies_rte sws 1191] */
  {
    AlgoDataTimeStamp_t uiTimeStamp;
    AlgoCycleCounter_t uiMeasurementCounter;
    AlgoCycleCounter_t uiCycleCounter;
    AlgoSignalState_t eSigStatus;
  } SignalHeader_t;                                                  /* Common header for all structured data types */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    percentage_t existenceProbability;
    percentage_t probabilityPedestrian;
    percentage_t probabilityCyclist;
    percentage_t probabilityBike;
    percentage_t probabilityCar;
    percentage_t propabilityTruck;
    percentage_t probabilityOtherVehicles;
    percentage_t probabilityUnknown;
  } EMB0_t_ObjectProbabilityInfo;			/* This data type represents the classification vector of an object. An object can be classified with 80% as car and 20% as truck. The individual probabilities are stored in this data type. */
  // new prob struct


  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    unsigned long u_SwVersionNumber;
    EMB0_t_ObjectList_SCAM_V1::EMB0_t_Service dataComplete;
    unsigned char u_NumOfEventGroups;
    EMB0_t_ObjectList_SCAM_V1::EMB0_t_Service commonCRC_OK;
    unsigned char u_NumberOfObjects;
    unsigned long u_Counter;
    unsigned long u_Timestamp;
    unsigned long u_Timestamp_sec;  // NEW
    EMB0_t_ObjectList_SCAM_V1::EMB0_t_EventDataQualifier eventDataQualifier;
    EMB0_t_ObjectList_SCAM_V1::EMB0_t_ExtendedQualifier extendedQualifier;
  } EMB0_t_ObjectListHeader;                                         /* This data type provides common status information about the object property lists. */
  // new header 


  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    unsigned char u_NumberOfPedestrians;
    unsigned char u_NumberOfCyclists;
    unsigned char u_NumberOfBikes;
    unsigned char u_NumberOfCars;
    unsigned char u_NumberOfTrucks;
    unsigned char u_NumberOfOtherVehicles;
    unsigned char u_NumberOfRoadBoundaries;
    unsigned char u_NumberOfBridges;
    unsigned char u_NumberOfUnknownObjects;
    unsigned char u_NumberOfFreeFormObjects;
    unsigned char dummy_82;
    unsigned char dummy_83;
  } EMB0_t_ObjectListCounts;			/* This data type provides a brief summary of object type distribution over in the lists (e.g. how many cars, how many bikes). */


  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    float x;
    float y;
    float z;
    float roll;
    float pitch;
    float yaw;
  } EMB0_t_CamExtrinsics;			/* This data type provides position */


  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    unsigned char u_ObjectId;
    EMB0_t_MeasurementStatus statusMeasurement;
    EMB0_t_ObjectMovementStatus statusMovement;
    EMB0_t_ObjectType classificationType;
    EMB0_t_ObjectModeLateral modeLateral;
    EMB0_t_DrivingTubeMapping drivingTubeMapping;
    EMB0_t_ObjectReferencePoint referencePoint;
    EMB0_t_ObjCollisionStatus statusCollision;
  } EMB0_t_ObjectRecognitionInfo;			/* This datatype summarizes status information of an object. */


  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    float f_SpeedAbsoluteX;
    float f_SpeedAbsoluteY;
    float f_AccelAbsoluteX;
    float f_AccelAbsoluteY;
    float f_YawAngle;
    float f_YawSpeed;
    float f_iTTC;
  } EMB0_t_ObjectMovementInfo;			/* This data type summarizes absolute speed and yaw angle information of an object. */


  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    float f_PositionX;
    float f_PositionY;
    float f_AngleRightEdgeToLeftLane;
    float f_AngleLeftEdgeToRightLane;
  } EMB0_t_ObjectPositionInfo;			/* This data type summarizes object position information. The coordinates are in vehicle coordinate system. */


  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    float f_StdDevPositionX;
    float f_StdDevPositionY;
    float f_StdDevLength;
    float f_StdDevWidth;
    float f_StdDevHeight;
  } EMB0_t_ObjectPositionStdDev;			/* This data type summarizes standard deviations for position and extension information of an object. */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    float f_Distance;
    float f_DistanceStd;
    float f_DistanceRate;
    float f_DistanceRateStd;
    float f_Angle;
    float f_AngleStd;
    float f_AngleRate;
    float f_AngleRateStd;
  } EMB0_t_ObjectPolarCoordInfo;			/* The polar coordinates are described in the coordinate system of the corresponding sensor.                  A polar coordinate states a distance and an angle measured from the sensor's origin to the given reference point */


  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    float f_Length;
    float f_Width;
    float f_Height;
  } EMB0_t_ObjectDimensionInfo;			/* This data type summarizes object dimension information (e.g. length, width) of an object. */


  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    float f_StdDevSpeedAbsoluteX;
    float f_StdDevSpeedAbsoluteY;
    float f_StdDevAccelAbsoluteX;
    float f_StdDevAccelAbsoluteY;
    float f_StdDevYawAngle;
    float f_StdDevYawSpeed;
  } EMB0_t_ObjectMovementStdDev;			/* This data types summarizes standard deviations for movement information of an object. */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    EMB0_t_ObjFlashLightStat statusFlashLight;
    EMB0_t_ObjBrakeLightStat statusBrakingLight;
    percentage_t percentageOwnDrivingLane;
    percentage_t percentageSideDrivingLaneLeft;
    percentage_t percentageSideDrivingLaneRight;
    unsigned char dummy_81;
    unsigned char dummy_82;
    unsigned char dummy_83;
  } EMB0_t_ObjectFrontCameraInfo;			/* This data type contains information provided by front camera only, e.g. brakelight status or status of blinker which is not visible for other sensors. */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    EMB0_t_Flags flags;
  } EMB0_t_ObjectSignalInvalidFlags;			/* This data types summarizes standard deviations for movement information of an object. */

  typedef EMB0_t_ObjectDimensionInfo 	EMB0_t_ScamOeiArray[20];			/* [Satisfies_rte sws 1189] */
  typedef EMB0_t_ObjectMovementInfo 	EMB0_t_ScamOmiArray[20];			/* [Satisfies_rte sws 1189] */
  typedef EMB0_t_ObjectMovementStdDev 	  EMB0_t_ScamOmsdArray[20];			/* [Satisfies_rte sws 1189] */
  typedef EMB0_t_ObjectPositionInfo 	EMB0_t_ScamOpiArray[20];			/* [Satisfies_rte sws 1189] */
  typedef EMB0_t_ObjectPolarCoordInfo EMB0_t_ScamPpciArray[20];			/* [Satisfies_rte sws 1189] */
  typedef EMB0_t_ObjectPositionStdDev 	EMB0_t_ScamPsdArray[20];			/* [Satisfies_rte sws 1189] */
  typedef EMB0_t_ObjectFrontCameraInfo 	EMB0_t_ScamOfciArray[20];			/* [Satisfies_rte sws 1189] */
  typedef EMB0_t_ObjectProbabilityInfo 	EMB0_t_ScamOpriArray[20];			/* [Satisfies_rte sws 1189] */
  typedef EMB0_t_ObjectRecognitionInfo 	EMB0_t_ScamOriArray[20];			/* [Satisfies_rte sws 1189] */
  typedef EMB0_t_ObjectSignalInvalidFlags 	EMB0_t_ScamSigFlagArray[20];			/* [Satisfies_rte sws 1189] */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    AlgoInterfaceVersionNumber_t u_VersionNumber;
    SignalHeader_t sSigHeader;
    EMB0_t_SensorSource sensorSource;
    unsigned long u_CurrentExternalTime;
    EMB0_t_ObjectListHeader objectListHeader;
    EMB0_t_CamExtrinsics cameraExtrinsics;
    EMB0_t_ObjectListCounts objectListCounts;
    EMB0_t_ScamOriArray a_ObjRecognitionInfo;
    EMB0_t_ScamOpiArray a_ObjPositionInfo;
    EMB0_t_ScamPpciArray a_ObjPolCoordInfo;
    EMB0_t_ScamOeiArray a_ObjDimensionInfo;
    EMB0_t_ScamOmiArray a_ObjMovementInfo;
    EMB0_t_ScamPsdArray a_ObjPositionStdDev;
    EMB0_t_ScamOmsdArray a_ObjMovementStdDev;
    EMB0_t_ScamOpriArray a_ObjProbabilityInfo;
    EMB0_t_ScamSigFlagArray a_ObjSignalInvalidFlags;
    EMB0_t_ScamOfciArray a_ObjFrontCameraInfo;
  } EMB0_t_ObjectList_SCAM;			/* @vaddr:0x20190000 @vaddr_defs: EM_MEAS_ID_B0_OBJECT_LIST_SCAM @cycleid:EM_ENV @vname:EMB0ObjDataSCam */
} // end of namespace EMB0_t_ObjectList_SCAM_V000D0006


class CConvEmObjectListScam : public CSimConverterBase
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

  EMB0_t_ObjectList_SCAM_V1::EMB0_t_ObjectList_SCAM m_BufV1;
  EMB0_t_ObjectList_SCAM_V2::EMB0_t_ObjectList_SCAM m_BufV2;
  EMB0_t_ObjectList_SCAM_V30002::EMB0_t_ObjectList_SCAM m_BufV30002;
  EMB0_t_ObjectList_SCAM_V50002::EMB0_t_ObjectList_SCAM m_BufV50002;
  EMB0_t_ObjectList_SCAM_V000A0004::EMB0_t_ObjectList_SCAM m_BufV000A0004;
  EMB0_t_ObjectList_SCAM_V000D0006::EMB0_t_ObjectList_SCAM m_BufV000D0006;

  static void InitV1(EMB0_t_ObjectList_SCAM_V1::EMB0_t_ObjectList_SCAM & Params);
  static void InitV2(EMB0_t_ObjectList_SCAM_V2::EMB0_t_ObjectList_SCAM & Params);
  static void InitV30002(EMB0_t_ObjectList_SCAM_V30002::EMB0_t_ObjectList_SCAM & Params);
  static void InitV50002(EMB0_t_ObjectList_SCAM_V50002::EMB0_t_ObjectList_SCAM & Params);
  static void InitV000A0004(EMB0_t_ObjectList_SCAM_V000A0004::EMB0_t_ObjectList_SCAM & Params);
  static void InitV000D0006(EMB0_t_ObjectList_SCAM_V000D0006::EMB0_t_ObjectList_SCAM & Params);

public:

  static const char *GetConverterTypeName()
  {
    return "CamObjInputData";
  }

  CConvEmObjectListScam(void);
  virtual ~CConvEmObjectListScam(void);

  const char *GetTypeName()
  {
    return GetConverterTypeName();
  }

  void Destroy()
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
  enum EM_ObjectList_Scam
  {
    EMB0_T_OBJECTLIST_SCAM_V1,
    EMB0_T_OBJECTLIST_SCAM_V2,
    EMB0_T_OBJECTLIST_SCAM_V30002,
    EMB0_T_OBJECTLIST_SCAM_V50002,
    EMB0_T_OBJECTLIST_SCAM_V60002,
    EMB0_T_OBJECTLIST_SCAM_V80003,
    EMB0_T_OBJECTLIST_SCAM_V80004,
    EMB0_T_OBJECTLIST_SCAM_V000A0004,
    EMB0_T_OBJECTLIST_SCAM_V000D0006, // BW 18
    EM_OBJECTLIST_SCAM_VERSION_COUNT
  };

  static CVersionInfoImpl BASE_VERSION;
  static CVersionInfoImpl VERSION2;
  static CVersionInfoImpl VERSION30002;
  static CVersionInfoImpl VERSION50002;
  static CVersionInfoImpl VERSION60002;
  static CVersionInfoImpl VERSION80003;
  static CVersionInfoImpl VERSION80004;
  static CVersionInfoImpl VERSION000A0004;
  static CVersionInfoImpl VERSION000D0006;
  static const CVersionInfoImpl * const EM_OBJECTLIST_SCAM_INPUT_VERSIONS[EM_OBJECTLIST_SCAM_VERSION_COUNT];


  static const unsigned long SUPPORTED_SIZE[EM_OBJECTLIST_SCAM_VERSION_COUNT];

  bool IsPortSupported(unsigned long ulPortSize, const IVersionInfo *pPortVersion) const
  {
    for (int nI = 0; nI < EM_OBJECTLIST_SCAM_VERSION_COUNT; nI++)
    {
      if ((pPortVersion == NULL) || pPortVersion->Equals(EM_OBJECTLIST_SCAM_INPUT_VERSIONS[nI]))
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

CVersionInfoImpl CConvEmObjectListScam::BASE_VERSION(0, 0, 0);
CVersionInfoImpl CConvEmObjectListScam::VERSION2    (0, 0, 2);
CVersionInfoImpl CConvEmObjectListScam::VERSION30002(3, 0, 2);
CVersionInfoImpl CConvEmObjectListScam::VERSION50002(5, 0, 2);
CVersionInfoImpl CConvEmObjectListScam::VERSION60002(6, 0, 2);
CVersionInfoImpl CConvEmObjectListScam::VERSION80003(8, 0, 3);
CVersionInfoImpl CConvEmObjectListScam::VERSION80004(8, 0, 4);
CVersionInfoImpl CConvEmObjectListScam::VERSION000A0004(10, 0, 4);
CVersionInfoImpl CConvEmObjectListScam::VERSION000D0006(13, 0, 6);

const CVersionInfoImpl * const CConvEmObjectListScam::EM_OBJECTLIST_SCAM_INPUT_VERSIONS[CConvEmObjectListScam::EM_OBJECTLIST_SCAM_VERSION_COUNT] =
{
  &BASE_VERSION,
  &VERSION2,
  &VERSION30002,
  &VERSION50002,
  &VERSION60002,
  &VERSION80003,
  &VERSION80004,
  &VERSION000A0004,
  &VERSION000D0006
};

const unsigned long CConvEmObjectListScam::SUPPORTED_SIZE[CConvEmObjectListScam::EM_OBJECTLIST_SCAM_VERSION_COUNT] =
{
  sizeof(EMB0_t_ObjectList_SCAM_V1::EMB0_t_ObjectList_SCAM),         //    EMB0_T_OBJECTLIST_SCAM_V1,
  sizeof(EMB0_t_ObjectList_SCAM_V2::EMB0_t_ObjectList_SCAM),         //    EMB0_T_OBJECTLIST_SCAM_V2,
  sizeof(EMB0_t_ObjectList_SCAM_V30002::EMB0_t_ObjectList_SCAM),     //    EMB0_T_OBJECTLIST_SCAM_V30002,
  sizeof(EMB0_t_ObjectList_SCAM_V50002::EMB0_t_ObjectList_SCAM),     //    EMB0_T_OBJECTLIST_SCAM_V50002,
  sizeof(EMB0_t_ObjectList_SCAM_V50002::EMB0_t_ObjectList_SCAM),     //    EMB0_T_OBJECTLIST_SCAM_V60002,
  sizeof(EMB0_t_ObjectList_SCAM_V80003_RM::EMB0_t_ObjectList_SCAM),  //    EMB0_T_OBJECTLIST_SCAM_V80003,
  sizeof(EMB0_t_ObjectList_SCAM_V80003_RM::EMB0_t_ObjectList_SCAM),  //    EMB0_T_OBJECTLIST_SCAM_V80004,
  sizeof(EMB0_t_ObjectList_SCAM_V000A0004::EMB0_t_ObjectList_SCAM),  //    EMB0_T_OBJECTLIST_SCAM_V000A0004,
  sizeof(EMB0_t_ObjectList_SCAM_V000D0006::EMB0_t_ObjectList_SCAM)   //    EMB0_T_OBJECTLIST_SCAM_V000D0006,
};

__inline void v_Convert_v1_to_v2 (EMB0_t_ObjectList_SCAM_V2::EMB0_t_ObjectList_SCAM * const pDest,
  const EMB0_t_ObjectList_SCAM_V1::EMB0_t_ObjectList_SCAM * const pSrc)
{
  pDest->u_VersionNumber = 2;
  pDest->u_CurrentExternalTime = 0;
  pDest->sSigHeader = pSrc->sSigHeader;

  pDest->sensorSource = pSrc->sensorSource;
  pDest->objectListHeader = pSrc->objectListHeader;
  pDest->objectListCounts = pSrc->objectListCounts;
  memcpy_s(pDest->a_ObjRecognitionInfo, sizeof(pDest->a_ObjRecognitionInfo), pSrc->a_ObjRecognitionInfo, sizeof(pSrc->a_ObjRecognitionInfo));
  memcpy_s(pDest->a_ObjPositionInfo   , sizeof(pDest->a_ObjPositionInfo   ), pSrc->a_ObjPositionInfo   , sizeof(pSrc->a_ObjPositionInfo   ));
  memcpy_s(pDest->a_ObjExtensionInfo  , sizeof(pDest->a_ObjExtensionInfo  ), pSrc->a_ObjExtensionInfo  , sizeof(pSrc->a_ObjExtensionInfo  ));
  memcpy_s(pDest->a_ObjMovementInfo   , sizeof(pDest->a_ObjMovementInfo   ), pSrc->a_ObjMovementInfo   , sizeof(pSrc->a_ObjMovementInfo   ));
  memcpy_s(pDest->a_ObjPositionStdDev , sizeof(pDest->a_ObjPositionStdDev ), pSrc->a_ObjPositionStdDev , sizeof(pSrc->a_ObjPositionStdDev ));
  memcpy_s(pDest->a_ObjMovementStdDev , sizeof(pDest->a_ObjMovementStdDev ), pSrc->a_ObjMovementStdDev , sizeof(pSrc->a_ObjMovementStdDev ));
  memcpy_s(pDest->a_ObjProbabilityInfo, sizeof(pDest->a_ObjProbabilityInfo), pSrc->a_ObjProbabilityInfo, sizeof(pSrc->a_ObjProbabilityInfo));
  memcpy_s(pDest->a_ObjFrontCameraInfo, sizeof(pDest->a_ObjFrontCameraInfo), pSrc->a_ObjFrontCameraInfo, sizeof(pSrc->a_ObjFrontCameraInfo));
  memcpy_s(pDest->a_ObjFreeFormInfo   , sizeof(pDest->a_ObjFreeFormInfo   ), pSrc->a_ObjFreeFormInfo   , sizeof(pSrc->a_ObjFreeFormInfo   ));
}

__inline void v_Convert_v2_to_v1 (EMB0_t_ObjectList_SCAM_V1::EMB0_t_ObjectList_SCAM * const pDest,
  const EMB0_t_ObjectList_SCAM_V2::EMB0_t_ObjectList_SCAM * const pSrc)
{
  pDest->u_VersionNumber = 2;
  pDest->sSigHeader = pSrc->sSigHeader;

  pDest->sensorSource = pSrc->sensorSource;
  pDest->objectListHeader = pSrc->objectListHeader;
  pDest->objectListCounts = pSrc->objectListCounts;
  memcpy_s(pDest->a_ObjRecognitionInfo, sizeof(pDest->a_ObjRecognitionInfo), pSrc->a_ObjRecognitionInfo, sizeof(pSrc->a_ObjRecognitionInfo));
  memcpy_s(pDest->a_ObjPositionInfo   , sizeof(pDest->a_ObjPositionInfo   ), pSrc->a_ObjPositionInfo   , sizeof(pSrc->a_ObjPositionInfo   ));
  memcpy_s(pDest->a_ObjExtensionInfo  , sizeof(pDest->a_ObjExtensionInfo  ), pSrc->a_ObjExtensionInfo  , sizeof(pSrc->a_ObjExtensionInfo  ));
  memcpy_s(pDest->a_ObjMovementInfo   , sizeof(pDest->a_ObjMovementInfo   ), pSrc->a_ObjMovementInfo   , sizeof(pSrc->a_ObjMovementInfo   ));
  memcpy_s(pDest->a_ObjPositionStdDev , sizeof(pDest->a_ObjPositionStdDev ), pSrc->a_ObjPositionStdDev , sizeof(pSrc->a_ObjPositionStdDev ));
  memcpy_s(pDest->a_ObjMovementStdDev , sizeof(pDest->a_ObjMovementStdDev ), pSrc->a_ObjMovementStdDev , sizeof(pSrc->a_ObjMovementStdDev ));
  memcpy_s(pDest->a_ObjProbabilityInfo, sizeof(pDest->a_ObjProbabilityInfo), pSrc->a_ObjProbabilityInfo, sizeof(pSrc->a_ObjProbabilityInfo));
  memcpy_s(pDest->a_ObjFrontCameraInfo, sizeof(pDest->a_ObjFrontCameraInfo), pSrc->a_ObjFrontCameraInfo, sizeof(pSrc->a_ObjFrontCameraInfo));
  memcpy_s(pDest->a_ObjFreeFormInfo   , sizeof(pDest->a_ObjFreeFormInfo   ), pSrc->a_ObjFreeFormInfo   , sizeof(pSrc->a_ObjFreeFormInfo   ));
}

__inline void v_Convert_v1_to_v30002 (EMB0_t_ObjectList_SCAM_V30002::EMB0_t_ObjectList_SCAM * const pDest,
  const EMB0_t_ObjectList_SCAM_V1::EMB0_t_ObjectList_SCAM * const pSrc)
{
  pDest->u_VersionNumber = 0x30002;
  pDest->u_CurrentExternalTime = 0;
  pDest->sSigHeader = pSrc->sSigHeader;

  pDest->sensorSource = pSrc->sensorSource;
  memcpy_s(&(pDest->objectListHeader) , sizeof(pDest->objectListHeader    ), &(pSrc->objectListHeader) , sizeof(pSrc->objectListHeader    ));
  pDest->objectListCounts = pSrc->objectListCounts;
  memcpy_s(pDest->a_ObjRecognitionInfo, sizeof(pDest->a_ObjRecognitionInfo), pSrc->a_ObjRecognitionInfo, sizeof(pSrc->a_ObjRecognitionInfo));
  memcpy_s(pDest->a_ObjPositionInfo   , sizeof(pDest->a_ObjPositionInfo   ), pSrc->a_ObjPositionInfo   , sizeof(pSrc->a_ObjPositionInfo   ));
  memcpy_s(pDest->a_ObjDimensionInfo  , sizeof(pDest->a_ObjDimensionInfo  ), pSrc->a_ObjExtensionInfo  , sizeof(pSrc->a_ObjExtensionInfo  ));
  memcpy_s(pDest->a_ObjMovementInfo   , sizeof(pDest->a_ObjMovementInfo   ), pSrc->a_ObjMovementInfo   , sizeof(pSrc->a_ObjMovementInfo   ));
  memcpy_s(pDest->a_ObjPositionStdDev , sizeof(pDest->a_ObjPositionStdDev ), pSrc->a_ObjPositionStdDev , sizeof(pSrc->a_ObjPositionStdDev ));
  memcpy_s(pDest->a_ObjMovementStdDev , sizeof(pDest->a_ObjMovementStdDev ), pSrc->a_ObjMovementStdDev , sizeof(pSrc->a_ObjMovementStdDev ));
  memcpy_s(pDest->a_ObjProbabilityInfo, sizeof(pDest->a_ObjProbabilityInfo), pSrc->a_ObjProbabilityInfo, sizeof(pSrc->a_ObjProbabilityInfo));
  memset(pDest->a_ObjSignalInvalidFlags, 0, sizeof(pDest->a_ObjSignalInvalidFlags));
  memcpy_s(pDest->a_ObjFrontCameraInfo, sizeof(pDest->a_ObjFrontCameraInfo), pSrc->a_ObjFrontCameraInfo, sizeof(pSrc->a_ObjFrontCameraInfo));
}

__inline void v_Convert_v1_to_v50002 (EMB0_t_ObjectList_SCAM_V50002::EMB0_t_ObjectList_SCAM * const pDest,
  const EMB0_t_ObjectList_SCAM_V1::EMB0_t_ObjectList_SCAM * const pSrc)
{
  pDest->u_VersionNumber = 0x50002;
  pDest->u_CurrentExternalTime = 0;
  pDest->sSigHeader = pSrc->sSigHeader;

  pDest->sensorSource = pSrc->sensorSource;
  pDest->objectListHeader.commonCRC_OK        =                   pSrc->objectListHeader.commonCRC_OK      ;
  pDest->objectListHeader.dataComplete        =                   pSrc->objectListHeader.dataComplete      ;
  pDest->objectListHeader.eventDataQualifier  =                   pSrc->objectListHeader.eventDataQualifier;
  pDest->objectListHeader.extendedQualifier   =                   pSrc->objectListHeader.extendedQualifier ;
  pDest->objectListHeader.u_Counter           =                   pSrc->objectListHeader.u_Alive           ;
  pDest->objectListHeader.u_NumberOfObjects   =                   pSrc->objectListHeader.u_NumberOfObjects ;
  pDest->objectListHeader.u_NumOfEventGroups  =                   pSrc->objectListHeader.u_NumOfEventGroups;
  pDest->objectListHeader.u_SwVersionNumber   =                   pSrc->objectListHeader.u_SwVersionNumber ;
  pDest->objectListHeader.u_Timestamp         =    (unsigned long)pSrc->objectListHeader.u_Timestamp       ;

  pDest->objectListCounts = pSrc->objectListCounts;
  memcpy_s(pDest->a_ObjRecognitionInfo, sizeof(pDest->a_ObjRecognitionInfo), pSrc->a_ObjRecognitionInfo, sizeof(pSrc->a_ObjRecognitionInfo));
  memcpy_s(pDest->a_ObjPositionInfo   , sizeof(pDest->a_ObjPositionInfo   ), pSrc->a_ObjPositionInfo   , sizeof(pSrc->a_ObjPositionInfo   ));
  memcpy_s(pDest->a_ObjDimensionInfo  , sizeof(pDest->a_ObjDimensionInfo  ), pSrc->a_ObjExtensionInfo  , sizeof(pSrc->a_ObjExtensionInfo  ));
  memcpy_s(pDest->a_ObjMovementInfo   , sizeof(pDest->a_ObjMovementInfo   ), pSrc->a_ObjMovementInfo   , sizeof(pSrc->a_ObjMovementInfo   ));
  memcpy_s(pDest->a_ObjPositionStdDev , sizeof(pDest->a_ObjPositionStdDev ), pSrc->a_ObjPositionStdDev , sizeof(pSrc->a_ObjPositionStdDev ));
  memcpy_s(pDest->a_ObjMovementStdDev , sizeof(pDest->a_ObjMovementStdDev ), pSrc->a_ObjMovementStdDev , sizeof(pSrc->a_ObjMovementStdDev ));
  memcpy_s(pDest->a_ObjProbabilityInfo, sizeof(pDest->a_ObjProbabilityInfo), pSrc->a_ObjProbabilityInfo, sizeof(pSrc->a_ObjProbabilityInfo));
  memset(pDest->a_ObjSignalInvalidFlags, 0, sizeof(pDest->a_ObjSignalInvalidFlags));
  memcpy_s(pDest->a_ObjFrontCameraInfo, sizeof(pDest->a_ObjFrontCameraInfo), pSrc->a_ObjFrontCameraInfo, sizeof(pSrc->a_ObjFrontCameraInfo));
}

__inline void v_Convert_v2_to_v30002 (EMB0_t_ObjectList_SCAM_V30002::EMB0_t_ObjectList_SCAM * const pDest,
  const EMB0_t_ObjectList_SCAM_V2::EMB0_t_ObjectList_SCAM * const pSrc)
{
  pDest->u_VersionNumber = 0x30002;
  pDest->u_CurrentExternalTime = pSrc->u_CurrentExternalTime;
  pDest->sSigHeader = pSrc->sSigHeader;

  pDest->sensorSource = pSrc->sensorSource;
  memcpy_s(&(pDest->objectListHeader) , sizeof(pDest->objectListHeader    ), &(pSrc->objectListHeader) , sizeof(pSrc->objectListHeader    ));
  pDest->objectListCounts = pSrc->objectListCounts;
  memcpy_s(pDest->a_ObjRecognitionInfo, sizeof(pDest->a_ObjRecognitionInfo), pSrc->a_ObjRecognitionInfo, sizeof(pSrc->a_ObjRecognitionInfo));
  memcpy_s(pDest->a_ObjPositionInfo   , sizeof(pDest->a_ObjPositionInfo   ), pSrc->a_ObjPositionInfo   , sizeof(pSrc->a_ObjPositionInfo   ));
  memcpy_s(pDest->a_ObjDimensionInfo  , sizeof(pDest->a_ObjDimensionInfo  ), pSrc->a_ObjExtensionInfo  , sizeof(pSrc->a_ObjExtensionInfo  ));
  memcpy_s(pDest->a_ObjMovementInfo   , sizeof(pDest->a_ObjMovementInfo   ), pSrc->a_ObjMovementInfo   , sizeof(pSrc->a_ObjMovementInfo   ));
  memcpy_s(pDest->a_ObjPositionStdDev , sizeof(pDest->a_ObjPositionStdDev ), pSrc->a_ObjPositionStdDev , sizeof(pSrc->a_ObjPositionStdDev ));
  memcpy_s(pDest->a_ObjMovementStdDev , sizeof(pDest->a_ObjMovementStdDev ), pSrc->a_ObjMovementStdDev , sizeof(pSrc->a_ObjMovementStdDev ));
  memcpy_s(pDest->a_ObjProbabilityInfo, sizeof(pDest->a_ObjProbabilityInfo), pSrc->a_ObjProbabilityInfo, sizeof(pSrc->a_ObjProbabilityInfo));
  memset(pDest->a_ObjSignalInvalidFlags, 0, sizeof(pDest->a_ObjSignalInvalidFlags));
  memcpy_s(pDest->a_ObjFrontCameraInfo, sizeof(pDest->a_ObjFrontCameraInfo), pSrc->a_ObjFrontCameraInfo, sizeof(pSrc->a_ObjFrontCameraInfo));
}

__inline void v_Convert_v2_to_v50002 (EMB0_t_ObjectList_SCAM_V50002::EMB0_t_ObjectList_SCAM * const pDest,
  const EMB0_t_ObjectList_SCAM_V2::EMB0_t_ObjectList_SCAM * const pSrc)
{
  pDest->u_VersionNumber = 0x50002;
  pDest->u_CurrentExternalTime = pSrc->u_CurrentExternalTime;
  pDest->sSigHeader = pSrc->sSigHeader;

  pDest->sensorSource = pSrc->sensorSource;
  pDest->objectListHeader.commonCRC_OK        =                   pSrc->objectListHeader.commonCRC_OK      ;
  pDest->objectListHeader.dataComplete        =                   pSrc->objectListHeader.dataComplete      ;
  pDest->objectListHeader.eventDataQualifier  =                   pSrc->objectListHeader.eventDataQualifier;
  pDest->objectListHeader.extendedQualifier   =                   pSrc->objectListHeader.extendedQualifier ;
  pDest->objectListHeader.u_Counter           =                   pSrc->objectListHeader.u_Alive           ;
  pDest->objectListHeader.u_NumberOfObjects   =                   pSrc->objectListHeader.u_NumberOfObjects ;
  pDest->objectListHeader.u_NumOfEventGroups  =                   pSrc->objectListHeader.u_NumOfEventGroups;
  pDest->objectListHeader.u_SwVersionNumber   =                   pSrc->objectListHeader.u_SwVersionNumber ;
  pDest->objectListHeader.u_Timestamp         =    (unsigned long)pSrc->objectListHeader.u_Timestamp       ;
  pDest->objectListCounts = pSrc->objectListCounts;
  memcpy_s(pDest->a_ObjRecognitionInfo, sizeof(pDest->a_ObjRecognitionInfo), pSrc->a_ObjRecognitionInfo, sizeof(pSrc->a_ObjRecognitionInfo));
  memcpy_s(pDest->a_ObjPositionInfo   , sizeof(pDest->a_ObjPositionInfo   ), pSrc->a_ObjPositionInfo   , sizeof(pSrc->a_ObjPositionInfo   ));
  memcpy_s(pDest->a_ObjDimensionInfo  , sizeof(pDest->a_ObjDimensionInfo  ), pSrc->a_ObjExtensionInfo  , sizeof(pSrc->a_ObjExtensionInfo  ));
  memcpy_s(pDest->a_ObjMovementInfo   , sizeof(pDest->a_ObjMovementInfo   ), pSrc->a_ObjMovementInfo   , sizeof(pSrc->a_ObjMovementInfo   ));
  memcpy_s(pDest->a_ObjPositionStdDev , sizeof(pDest->a_ObjPositionStdDev ), pSrc->a_ObjPositionStdDev , sizeof(pSrc->a_ObjPositionStdDev ));
  memcpy_s(pDest->a_ObjMovementStdDev , sizeof(pDest->a_ObjMovementStdDev ), pSrc->a_ObjMovementStdDev , sizeof(pSrc->a_ObjMovementStdDev ));
  memcpy_s(pDest->a_ObjProbabilityInfo, sizeof(pDest->a_ObjProbabilityInfo), pSrc->a_ObjProbabilityInfo, sizeof(pSrc->a_ObjProbabilityInfo));
  memset(pDest->a_ObjSignalInvalidFlags, 0, sizeof(pDest->a_ObjSignalInvalidFlags));
  memcpy_s(pDest->a_ObjFrontCameraInfo, sizeof(pDest->a_ObjFrontCameraInfo), pSrc->a_ObjFrontCameraInfo, sizeof(pSrc->a_ObjFrontCameraInfo));
}


__inline void v_Convert_v30002_to_v50002 (EMB0_t_ObjectList_SCAM_V50002::EMB0_t_ObjectList_SCAM * const pDest,
  const EMB0_t_ObjectList_SCAM_V30002::EMB0_t_ObjectList_SCAM * const pSrc)
{
  pDest->u_VersionNumber = 0x50002;
  pDest->u_CurrentExternalTime = pSrc->u_CurrentExternalTime;
  pDest->sSigHeader = pSrc->sSigHeader;

  pDest->sensorSource = pSrc->sensorSource;
  pDest->objectListHeader.commonCRC_OK        =                   pSrc->objectListHeader.commonCRC_OK      ;
  pDest->objectListHeader.dataComplete        =                   pSrc->objectListHeader.dataComplete      ;
  pDest->objectListHeader.eventDataQualifier  =                   pSrc->objectListHeader.eventDataQualifier;
  pDest->objectListHeader.extendedQualifier   =                   pSrc->objectListHeader.extendedQualifier ;
  pDest->objectListHeader.u_Counter           =                   pSrc->objectListHeader.u_Counter         ;
  pDest->objectListHeader.u_NumberOfObjects   =                   pSrc->objectListHeader.u_NumberOfObjects ;
  pDest->objectListHeader.u_NumOfEventGroups  =                   pSrc->objectListHeader.u_NumOfEventGroups;
  pDest->objectListHeader.u_SwVersionNumber   =                   pSrc->objectListHeader.u_SwVersionNumber ;
  pDest->objectListHeader.u_Timestamp         =    (unsigned long)pSrc->objectListHeader.u_Timestamp       ;
  pDest->objectListCounts = pSrc->objectListCounts;
  memcpy_s(pDest->a_ObjRecognitionInfo, sizeof(pDest->a_ObjRecognitionInfo), pSrc->a_ObjRecognitionInfo, sizeof(pSrc->a_ObjRecognitionInfo));
  memcpy_s(pDest->a_ObjPositionInfo   , sizeof(pDest->a_ObjPositionInfo   ), pSrc->a_ObjPositionInfo   , sizeof(pSrc->a_ObjPositionInfo   ));
  memcpy_s(pDest->a_ObjDimensionInfo  , sizeof(pDest->a_ObjDimensionInfo  ), pSrc->a_ObjDimensionInfo  , sizeof(pSrc->a_ObjDimensionInfo  ));
  memcpy_s(pDest->a_ObjMovementInfo   , sizeof(pDest->a_ObjMovementInfo   ), pSrc->a_ObjMovementInfo   , sizeof(pSrc->a_ObjMovementInfo   ));
  memcpy_s(pDest->a_ObjPositionStdDev , sizeof(pDest->a_ObjPositionStdDev ), pSrc->a_ObjPositionStdDev , sizeof(pSrc->a_ObjPositionStdDev ));
  memcpy_s(pDest->a_ObjMovementStdDev , sizeof(pDest->a_ObjMovementStdDev ), pSrc->a_ObjMovementStdDev , sizeof(pSrc->a_ObjMovementStdDev ));
  memcpy_s(pDest->a_ObjProbabilityInfo, sizeof(pDest->a_ObjProbabilityInfo), pSrc->a_ObjProbabilityInfo, sizeof(pSrc->a_ObjProbabilityInfo));
  memset(pDest->a_ObjSignalInvalidFlags, 0, sizeof(pDest->a_ObjSignalInvalidFlags));
  memcpy_s(pDest->a_ObjFrontCameraInfo, sizeof(pDest->a_ObjFrontCameraInfo), pSrc->a_ObjFrontCameraInfo, sizeof(pSrc->a_ObjFrontCameraInfo));
}

__inline void v_Convert_v30002_to_v2 (EMB0_t_ObjectList_SCAM_V2::EMB0_t_ObjectList_SCAM * const pDest,
  const EMB0_t_ObjectList_SCAM_V30002::EMB0_t_ObjectList_SCAM * const pSrc)
{
  pDest->u_VersionNumber = 0x30002;
  pDest->u_CurrentExternalTime = pSrc->u_CurrentExternalTime;
  pDest->sSigHeader = pSrc->sSigHeader;

  pDest->sensorSource = pSrc->sensorSource;
  memcpy_s(&(pDest->objectListHeader) , sizeof(pDest->objectListHeader    ), &(pSrc->objectListHeader) , sizeof(pSrc->objectListHeader    ));
  pDest->objectListCounts = pSrc->objectListCounts;
  memcpy_s(pDest->a_ObjRecognitionInfo, sizeof(pDest->a_ObjRecognitionInfo), pSrc->a_ObjRecognitionInfo, sizeof(pSrc->a_ObjRecognitionInfo));
  memcpy_s(pDest->a_ObjPositionInfo   , sizeof(pDest->a_ObjPositionInfo   ), pSrc->a_ObjPositionInfo   , sizeof(pSrc->a_ObjPositionInfo   ));
  memcpy_s(pDest->a_ObjExtensionInfo  , sizeof(pDest->a_ObjExtensionInfo  ), pSrc->a_ObjDimensionInfo  , sizeof(pSrc->a_ObjDimensionInfo  ));
  memcpy_s(pDest->a_ObjMovementInfo   , sizeof(pDest->a_ObjMovementInfo   ), pSrc->a_ObjMovementInfo   , sizeof(pSrc->a_ObjMovementInfo   ));
  memcpy_s(pDest->a_ObjPositionStdDev , sizeof(pDest->a_ObjPositionStdDev ), pSrc->a_ObjPositionStdDev , sizeof(pSrc->a_ObjPositionStdDev ));
  memcpy_s(pDest->a_ObjMovementStdDev , sizeof(pDest->a_ObjMovementStdDev ), pSrc->a_ObjMovementStdDev , sizeof(pSrc->a_ObjMovementStdDev ));
  memcpy_s(pDest->a_ObjProbabilityInfo, sizeof(pDest->a_ObjProbabilityInfo), pSrc->a_ObjProbabilityInfo, sizeof(pSrc->a_ObjProbabilityInfo));
  memcpy_s(pDest->a_ObjFrontCameraInfo, sizeof(pDest->a_ObjFrontCameraInfo), pSrc->a_ObjFrontCameraInfo, sizeof(pSrc->a_ObjFrontCameraInfo));
  memset(pDest->a_ObjFreeFormInfo, 0, sizeof(pDest->a_ObjFreeFormInfo));
}

__inline void v_Convert_v30002_to_v1 (EMB0_t_ObjectList_SCAM_V1::EMB0_t_ObjectList_SCAM * const pDest,
  const EMB0_t_ObjectList_SCAM_V30002::EMB0_t_ObjectList_SCAM * const pSrc)
{
  pDest->u_VersionNumber = 0x30002;
  pDest->sSigHeader = pSrc->sSigHeader;

  pDest->sensorSource = pSrc->sensorSource;
  memcpy_s(&(pDest->objectListHeader) , sizeof(pDest->objectListHeader    ), &(pSrc->objectListHeader) , sizeof(pSrc->objectListHeader    ));
  pDest->objectListCounts = pSrc->objectListCounts;
  memcpy_s(pDest->a_ObjRecognitionInfo, sizeof(pDest->a_ObjRecognitionInfo), pSrc->a_ObjRecognitionInfo, sizeof(pSrc->a_ObjRecognitionInfo));
  memcpy_s(pDest->a_ObjPositionInfo   , sizeof(pDest->a_ObjPositionInfo   ), pSrc->a_ObjPositionInfo   , sizeof(pSrc->a_ObjPositionInfo   ));
  memcpy_s(pDest->a_ObjExtensionInfo  , sizeof(pDest->a_ObjExtensionInfo  ), pSrc->a_ObjDimensionInfo  , sizeof(pSrc->a_ObjDimensionInfo  ));
  memcpy_s(pDest->a_ObjMovementInfo   , sizeof(pDest->a_ObjMovementInfo   ), pSrc->a_ObjMovementInfo   , sizeof(pSrc->a_ObjMovementInfo   ));
  memcpy_s(pDest->a_ObjPositionStdDev , sizeof(pDest->a_ObjPositionStdDev ), pSrc->a_ObjPositionStdDev , sizeof(pSrc->a_ObjPositionStdDev ));
  memcpy_s(pDest->a_ObjMovementStdDev , sizeof(pDest->a_ObjMovementStdDev ), pSrc->a_ObjMovementStdDev , sizeof(pSrc->a_ObjMovementStdDev ));
  memcpy_s(pDest->a_ObjProbabilityInfo, sizeof(pDest->a_ObjProbabilityInfo), pSrc->a_ObjProbabilityInfo, sizeof(pSrc->a_ObjProbabilityInfo));
  memcpy_s(pDest->a_ObjFrontCameraInfo, sizeof(pDest->a_ObjFrontCameraInfo), pSrc->a_ObjFrontCameraInfo, sizeof(pSrc->a_ObjFrontCameraInfo));
  memset(pDest->a_ObjFreeFormInfo, 0, sizeof(pDest->a_ObjFreeFormInfo));
}

__inline void v_Convert_v50002_R_to_v50002(EMB0_t_ObjectList_SCAM_V50002::EMB0_t_ObjectList_SCAM * const pDest,
  const EMB0_t_ObjectList_SCAM_V50002_R::EMB0_t_ObjectList_SCAM * const pSrc)
{
  pDest->u_VersionNumber = 0x50002;
  memcpy_s(&(pDest->sSigHeader), sizeof(pSrc->sSigHeader), &(pSrc->sSigHeader), sizeof(pSrc->sSigHeader));
  pDest->sensorSource = pSrc->sensorSource;
  pDest->u_CurrentExternalTime = pSrc->u_CurrentExternalTime;
  memcpy_s(&(pDest->objectListHeader) , sizeof(pSrc->objectListHeader    ), &(pSrc->objectListHeader) , sizeof(pSrc->objectListHeader    ));

  // Manipulate pDest->objectListHeader.u_Timestamp coming from camera bsig
  pDest->objectListHeader.u_Timestamp = pDest->objectListHeader.u_Timestamp % (EMB0_t_ObjectList_SCAM_V1::AlgoDataTimeStamp_t) 1000000;

  pDest->objectListCounts = pSrc->objectListCounts;

  memcpy_s(pDest->a_ObjRecognitionInfo, sizeof(pDest->a_ObjRecognitionInfo), pSrc->a_ObjRecognitionInfo, sizeof(pSrc->a_ObjRecognitionInfo));
  memcpy_s(pDest->a_ObjPositionInfo   , sizeof(pDest->a_ObjPositionInfo   ), pSrc->a_ObjPositionInfo   , sizeof(pSrc->a_ObjPositionInfo   ));
  memcpy_s(pDest->a_ObjDimensionInfo  , sizeof(pDest->a_ObjDimensionInfo  ), pSrc->a_ObjDimensionInfo  , sizeof(pSrc->a_ObjDimensionInfo  ));
  memcpy_s(pDest->a_ObjMovementInfo   , sizeof(pDest->a_ObjMovementInfo   ), pSrc->a_ObjMovementInfo   , sizeof(pSrc->a_ObjMovementInfo   ));
  memcpy_s(pDest->a_ObjPositionStdDev , sizeof(pDest->a_ObjPositionStdDev ), pSrc->a_ObjPositionStdDev , sizeof(pSrc->a_ObjPositionStdDev ));
  memcpy_s(pDest->a_ObjMovementStdDev , sizeof(pDest->a_ObjMovementStdDev ), pSrc->a_ObjMovementStdDev , sizeof(pSrc->a_ObjMovementStdDev ));
  memcpy_s(pDest->a_ObjProbabilityInfo, sizeof(pDest->a_ObjProbabilityInfo), pSrc->a_ObjProbabilityInfo, sizeof(pSrc->a_ObjProbabilityInfo));
  memcpy_s(pDest->a_ObjSignalInvalidFlags, sizeof(pDest->a_ObjSignalInvalidFlags), pSrc->a_ObjSignalInvalidFlags, sizeof(pSrc->a_ObjSignalInvalidFlags));
  memcpy_s(pDest->a_ObjFrontCameraInfo, sizeof(pDest->a_ObjFrontCameraInfo), pSrc->a_ObjFrontCameraInfo, sizeof(pSrc->a_ObjFrontCameraInfo));
}

__inline void v_Convert_v80003_RM_to_v50002(EMB0_t_ObjectList_SCAM_V50002::EMB0_t_ObjectList_SCAM * const pDest,
  const EMB0_t_ObjectList_SCAM_V80003_RM::EMB0_t_ObjectList_SCAM * const pSrc)
{
  pDest->u_VersionNumber = 0x50002;
  memcpy_s(&(pDest->sSigHeader), sizeof(pSrc->sSigHeader), &(pSrc->sSigHeader), sizeof(pSrc->sSigHeader));
  pDest->sensorSource = pSrc->sensorSource;
  pDest->u_CurrentExternalTime = pSrc->u_CurrentExternalTime;
  memcpy_s(&(pDest->objectListHeader) , sizeof(pSrc->objectListHeader    ), &(pSrc->objectListHeader) , sizeof(pSrc->objectListHeader    ));

  // Manipulate pDest->objectListHeader.u_Timestamp coming from camera bsig
  pDest->objectListHeader.u_Timestamp = pDest->objectListHeader.u_Timestamp % (EMB0_t_ObjectList_SCAM_V1::AlgoDataTimeStamp_t) 1000000;

  memcpy_s(&(pDest->objectListCounts), sizeof(pDest->objectListCounts)-2, &(pSrc->objectListCounts), sizeof(pSrc->objectListCounts)-1);
  pDest->objectListCounts.dummy_82 = pDest->objectListCounts.dummy_83 = pSrc->objectListCounts.dummy_83;

  memcpy_s(pDest->a_ObjRecognitionInfo, sizeof(pDest->a_ObjRecognitionInfo), pSrc->a_ObjRecognitionInfo, sizeof(pSrc->a_ObjRecognitionInfo));
  memcpy_s(pDest->a_ObjPositionInfo   , sizeof(pDest->a_ObjPositionInfo   ), pSrc->a_ObjPositionInfo   , sizeof(pSrc->a_ObjPositionInfo   ));
  memcpy_s(pDest->a_ObjDimensionInfo  , sizeof(pDest->a_ObjDimensionInfo  ), pSrc->a_ObjDimensionInfo  , sizeof(pSrc->a_ObjDimensionInfo  ));
  memcpy_s(pDest->a_ObjMovementInfo   , sizeof(pDest->a_ObjMovementInfo   ), pSrc->a_ObjMovementInfo   , sizeof(pSrc->a_ObjMovementInfo   ));
  memcpy_s(pDest->a_ObjPositionStdDev , sizeof(pDest->a_ObjPositionStdDev ), pSrc->a_ObjPositionStdDev , sizeof(pSrc->a_ObjPositionStdDev ));
  memcpy_s(pDest->a_ObjMovementStdDev , sizeof(pDest->a_ObjMovementStdDev ), pSrc->a_ObjMovementStdDev , sizeof(pSrc->a_ObjMovementStdDev ));
  memcpy_s(pDest->a_ObjProbabilityInfo, sizeof(pDest->a_ObjProbabilityInfo), pSrc->a_ObjProbabilityInfo, sizeof(pSrc->a_ObjProbabilityInfo));
  memcpy_s(pDest->a_ObjSignalInvalidFlags, sizeof(pDest->a_ObjSignalInvalidFlags), pSrc->a_ObjSignalInvalidFlags, sizeof(pSrc->a_ObjSignalInvalidFlags));
  memcpy_s(pDest->a_ObjFrontCameraInfo, sizeof(pDest->a_ObjFrontCameraInfo), pSrc->a_ObjFrontCameraInfo, sizeof(pSrc->a_ObjFrontCameraInfo));
}

__inline void v_Convert_vA0004_to_v000D0006( EMB0_t_ObjectList_SCAM_V000D0006::EMB0_t_ObjectList_SCAM * const pDest,
  const EMB0_t_ObjectList_SCAM_V000A0004::EMB0_t_ObjectList_SCAM * const pSrc)
{
    int i;
    pDest->u_VersionNumber = 0xD0006;
    memcpy_s(&(pDest->sSigHeader), sizeof(pSrc->sSigHeader), &(pSrc->sSigHeader), sizeof(pSrc->sSigHeader));
    pDest->sensorSource = pSrc->sensorSource;
    pDest->u_CurrentExternalTime = pSrc->u_CurrentExternalTime;

    pDest->objectListHeader.u_SwVersionNumber      = pSrc->objectListHeader.u_SwVersionNumber                           ;
    pDest->objectListHeader.dataComplete           = pSrc->objectListHeader.dataComplete                                ;
    pDest->objectListHeader.u_NumOfEventGroups     = pSrc->objectListHeader.u_NumOfEventGroups                          ;
    pDest->objectListHeader.commonCRC_OK           = pSrc->objectListHeader.commonCRC_OK                                ;
    pDest->objectListHeader.u_NumberOfObjects      = pSrc->objectListHeader.u_NumberOfObjects                           ;
    pDest->objectListHeader.u_Counter              = pSrc->objectListHeader.u_Counter                                   ;
    pDest->objectListHeader.u_Timestamp            = pSrc->objectListHeader.u_Timestamp                                 ;
    pDest->objectListHeader.u_Timestamp_sec        = 0U;
    pDest->objectListHeader.eventDataQualifier     = pSrc->objectListHeader.eventDataQualifier                          ;
    pDest->objectListHeader.extendedQualifier      = pSrc->objectListHeader.extendedQualifier                           ;

    pDest->cameraExtrinsics.x     =  0.0f;
    pDest->cameraExtrinsics.y     =  0.0f;
    pDest->cameraExtrinsics.z     =  0.0f;
    pDest->cameraExtrinsics.pitch =  0.0f;
    pDest->cameraExtrinsics.roll  =  0.0f;
    pDest->cameraExtrinsics.yaw   =  0.0f;

    pDest->objectListCounts.u_NumberOfPedestrians       = pSrc->objectListCounts.u_NumberOfPedestrians     ;
    pDest->objectListCounts.u_NumberOfCyclists          = pSrc->objectListCounts.u_NumberOfCyclists        ;
    pDest->objectListCounts.u_NumberOfBikes             = pSrc->objectListCounts.u_NumberOfBikes           ;
    pDest->objectListCounts.u_NumberOfCars              = pSrc->objectListCounts.u_NumberOfCars            ;
    pDest->objectListCounts.u_NumberOfTrucks            = pSrc->objectListCounts.u_NumberOfTrucks          ;
    pDest->objectListCounts.u_NumberOfOtherVehicles     = pSrc->objectListCounts.u_NumberOfOtherVehicles   ;
    pDest->objectListCounts.u_NumberOfRoadBoundaries    = pSrc->objectListCounts.u_NumberOfRoadBoundaries  ;
    pDest->objectListCounts.u_NumberOfBridges           = pSrc->objectListCounts.u_NumberOfBridges         ;
    pDest->objectListCounts.u_NumberOfUnknownObjects    = pSrc->objectListCounts.u_NumberOfUnknownObjects  ;
    pDest->objectListCounts.u_NumberOfFreeFormObjects   = pSrc->objectListCounts.u_NumberOfFreeFormObjects ;

  for (i=0;i<20;i++){
    pDest->a_ObjRecognitionInfo[i].u_ObjectId               = pSrc->a_ObjRecognitionInfo[i].u_ObjectId              ;
    pDest->a_ObjRecognitionInfo[i].statusMeasurement        = pSrc->a_ObjRecognitionInfo[i].statusMeasurement       ; // OK
    switch (  pSrc->a_ObjRecognitionInfo[i].statusMovement){
    case 0:  pDest->a_ObjRecognitionInfo[i].statusMovement = 0; break;  // EMB0_OMS_STATIONARY_PARKING=0,
    case 1:  pDest->a_ObjRecognitionInfo[i].statusMovement = 1; break;  // EMB0_OMS_STOPPED_WAS_ONCOMING=1,
    case 2:  pDest->a_ObjRecognitionInfo[i].statusMovement = 2; break;  // EMB0_OMS_STOPPED_WAS_ONGOING=2
    case 3:  pDest->a_ObjRecognitionInfo[i].statusMovement = 3; break;  // EMB0_OMS_STOPPED_WAS_UNKNOWN=3,     ->   EMB0_OMS_STOPPED_WAS_CROSSING=3,
    case 4:  pDest->a_ObjRecognitionInfo[i].statusMovement = 4; break;  // EMB0_OMS_MOVING_ONCOMMING=4,
    case 5:  pDest->a_ObjRecognitionInfo[i].statusMovement = 5; break;  // EMB0_OMS_MOVING_ONGOING=5,
    case 6:  pDest->a_ObjRecognitionInfo[i].statusMovement = 5; break;  // EMB0_OMS_MOVING_DIR_UNKNOWN=6,      ->   EMB0_OMS_MOVING_ONGOING=5,
    case 7:  pDest->a_ObjRecognitionInfo[i].statusMovement = 7; break;  // EMB0_OMS_CROSSING=7,
    case 255:pDest->a_ObjRecognitionInfo[i].statusMovement = 255; break;// 
    default: pDest->a_ObjRecognitionInfo[i].statusMovement = 255; 
    }
    pDest->a_ObjRecognitionInfo[i].classificationType       = pSrc->a_ObjRecognitionInfo[i].classificationType      ; // ok
    pDest->a_ObjRecognitionInfo[i].modeLateral              = pSrc->a_ObjRecognitionInfo[i].modeLateral             ; // ok
    pDest->a_ObjRecognitionInfo[i].drivingTubeMapping       = pSrc->a_ObjRecognitionInfo[i].drivingTubeMapping      ; // ok
    pDest->a_ObjRecognitionInfo[i].referencePoint           = pSrc->a_ObjRecognitionInfo[i].referencePoint          ; // ok
    pDest->a_ObjRecognitionInfo[i].statusCollision          = 0U;

    pDest->a_ObjPositionInfo[i].f_PositionX = pSrc->a_ObjPositionInfo[i].f_PositionX  ;
    pDest->a_ObjPositionInfo[i].f_PositionY = pSrc->a_ObjPositionInfo[i].f_PositionY  ;
    pDest->a_ObjPositionInfo[i].f_AngleLeftEdgeToRightLane = 0.f ;
    pDest->a_ObjPositionInfo[i].f_AngleRightEdgeToLeftLane = 0.f ;

    pDest->a_ObjPolCoordInfo[i].f_Distance         = 0.f ;
    pDest->a_ObjPolCoordInfo[i].f_DistanceStd      = 0.f ;
    pDest->a_ObjPolCoordInfo[i].f_DistanceRate     = 0.f ;
    pDest->a_ObjPolCoordInfo[i].f_DistanceRateStd  = 0.f ;
    pDest->a_ObjPolCoordInfo[i].f_Angle            = 0.f ;
    pDest->a_ObjPolCoordInfo[i].f_AngleStd         = 0.f ;
    pDest->a_ObjPolCoordInfo[i].f_AngleRate        = 0.f ;
    pDest->a_ObjPolCoordInfo[i].f_AngleRateStd     = 0.f ;

    memcpy_s(&(pDest->a_ObjDimensionInfo[i]) , sizeof(pDest->a_ObjDimensionInfo[i]), &(pSrc->a_ObjDimensionInfo[i]) , sizeof(pSrc->a_ObjDimensionInfo[i]));

    pDest->a_ObjMovementInfo[i].f_SpeedAbsoluteX    = pSrc->a_ObjMovementInfo[i].f_SpeedAbsoluteX   ;
    pDest->a_ObjMovementInfo[i].f_SpeedAbsoluteY    = pSrc->a_ObjMovementInfo[i].f_SpeedAbsoluteY   ;
    pDest->a_ObjMovementInfo[i].f_AccelAbsoluteX    = pSrc->a_ObjMovementInfo[i].f_AccelAbsoluteX   ;
    pDest->a_ObjMovementInfo[i].f_AccelAbsoluteY    = pSrc->a_ObjMovementInfo[i].f_AccelAbsoluteY   ;
    pDest->a_ObjMovementInfo[i].f_YawAngle          = pSrc->a_ObjMovementInfo[i].f_YawAngle         ;
    pDest->a_ObjMovementInfo[i].f_YawSpeed          = pSrc->a_ObjMovementInfo[i].f_YawSpeed         ;
    pDest->a_ObjMovementInfo[i].f_iTTC              = 0.f            ;

    pDest->a_ObjPositionStdDev[i].f_StdDevPositionX   = pSrc->a_ObjPositionStdDev[i].f_StdDevPositionX  ;
    pDest->a_ObjPositionStdDev[i].f_StdDevPositionY   = pSrc->a_ObjPositionStdDev[i].f_StdDevPositionY  ;
    pDest->a_ObjPositionStdDev[i].f_StdDevLength      = pSrc->a_ObjPositionStdDev[i].f_StdDevLength     ;
    pDest->a_ObjPositionStdDev[i].f_StdDevWidth       = pSrc->a_ObjPositionStdDev[i].f_StdDevWidth      ;
    pDest->a_ObjPositionStdDev[i].f_StdDevHeight      = pSrc->a_ObjPositionStdDev[i].f_StdDevHeight     ;

    memcpy_s(&(pDest->a_ObjMovementStdDev[i]) , sizeof(pDest->a_ObjMovementStdDev[i]), &(pSrc->a_ObjMovementStdDev[i]) , sizeof(pSrc->a_ObjMovementStdDev[i]));

    pDest->a_ObjProbabilityInfo[i].existenceProbability       = pSrc->a_ObjProbabilityInfo[i].existenceProbability      ;
    pDest->a_ObjProbabilityInfo[i].probabilityPedestrian      = pSrc->a_ObjProbabilityInfo[i].probabilityPedestrian     ;
    pDest->a_ObjProbabilityInfo[i].probabilityCyclist         = pSrc->a_ObjProbabilityInfo[i].probabilityCyclist        ;
    pDest->a_ObjProbabilityInfo[i].probabilityBike            = pSrc->a_ObjProbabilityInfo[i].probabilityBike           ;
    pDest->a_ObjProbabilityInfo[i].probabilityCar             = pSrc->a_ObjProbabilityInfo[i].probabilityCar            ;
    pDest->a_ObjProbabilityInfo[i].propabilityTruck           = pSrc->a_ObjProbabilityInfo[i].propabilityTruck          ;
    pDest->a_ObjProbabilityInfo[i].probabilityOtherVehicles   = pSrc->a_ObjProbabilityInfo[i].probabilityOtherVehicles  ;
    pDest->a_ObjProbabilityInfo[i].probabilityUnknown         = pSrc->a_ObjProbabilityInfo[i].probabilityUnknown        ;

    memcpy_s(&(pDest->a_ObjSignalInvalidFlags[i] ) , sizeof(pDest->a_ObjSignalInvalidFlags[i]), &(pSrc->a_ObjSignalInvalidFlags[i]) , sizeof(pSrc->a_ObjSignalInvalidFlags[i]));

    memcpy_s(&(pDest->a_ObjFrontCameraInfo[i] ) , sizeof(pDest->a_ObjFrontCameraInfo[i]), &(pSrc->a_ObjFrontCameraInfo[i]) , sizeof(pSrc->a_ObjFrontCameraInfo[i]));

  }
}


CConvEmObjectListScam::CConvEmObjectListScam(void) : CSimConverterBase(NULL/*DEP_NAMES*/, DEP_COUNT), m_BufV1(), m_BufV2(), m_BufV30002(), m_BufV50002(), m_BufV000A0004(),m_BufV000D0006()
{
  InitV1(m_BufV1);
  InitV2(m_BufV2);
  InitV30002(m_BufV30002);
  InitV50002(m_BufV50002);
  InitV000A0004(m_BufV000A0004);
  InitV000D0006(m_BufV000D0006);
}

CConvEmObjectListScam::~CConvEmObjectListScam(void)
{
}

void CConvEmObjectListScam::InitV1(EMB0_t_ObjectList_SCAM_V1::EMB0_t_ObjectList_SCAM & Params)
{
  ::memset(&Params, 0, sizeof(Params));
  Params.u_VersionNumber                         = 1u;
  // Signal Header
  Params.sSigHeader.eSigStatus                   = AL_SIG_STATE_INIT;
}

void CConvEmObjectListScam::InitV2(EMB0_t_ObjectList_SCAM_V2::EMB0_t_ObjectList_SCAM & Params)
{
  ::memset(&Params, 0, sizeof(Params));
  Params.u_VersionNumber                         = 2u;
  // Signal Header
  Params.sSigHeader.eSigStatus                   = AL_SIG_STATE_INIT;
}

void CConvEmObjectListScam::InitV30002(EMB0_t_ObjectList_SCAM_V30002::EMB0_t_ObjectList_SCAM & Params)
{
  ::memset(&Params, 0, sizeof(Params));
  Params.u_VersionNumber                         = 0x30002u;
  // Signal Header
  Params.sSigHeader.eSigStatus                   = AL_SIG_STATE_INIT;
}

void CConvEmObjectListScam::InitV50002(EMB0_t_ObjectList_SCAM_V50002::EMB0_t_ObjectList_SCAM & Params)
{
  ::memset(&Params, 0, sizeof(Params));
  Params.u_VersionNumber                         = 0x50002u;
  // Signal Header
  Params.sSigHeader.eSigStatus                   = AL_SIG_STATE_INIT;
}

void CConvEmObjectListScam::InitV000A0004(EMB0_t_ObjectList_SCAM_V000A0004::EMB0_t_ObjectList_SCAM & Params)
{
  ::memset(&Params, 0, sizeof(Params));
  Params.u_VersionNumber                         = 0xA0004u;
  // Signal Header
  Params.sSigHeader.eSigStatus                   = AL_SIG_STATE_INIT;
}

void CConvEmObjectListScam::InitV000D0006(EMB0_t_ObjectList_SCAM_V000D0006::EMB0_t_ObjectList_SCAM & Params)
{
  ::memset(&Params, 0, sizeof(Params));
  Params.u_VersionNumber                         = 0xD0006u;
  // Signal Header
  Params.sSigHeader.eSigStatus                   = AL_SIG_STATE_INIT;
}


long CConvEmObjectListScam::ConvertData(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
  SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo *pProvidePortVersionInfo,
  void *pPPortData,
  void **pOutData, unsigned long &ulOutSize)
{
  long lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
  const unsigned int uDataVer = ((pPPortData != NULL) && (ulPPortSize >= 4) && (ePPortType == simOPAQUE_t))?(*reinterpret_cast<unsigned int*>(pPPortData)):(0);
  const unsigned int uDataVerR = ((pPPortData != NULL) && (ulPPortSize >= 4) && (ePPortType == simREFERENCE_t))?(*reinterpret_cast<unsigned int*>(pPPortData)):(0);
  // First decide which version we are converting to
  if ((ulRPortSize == sizeof(EMB0_t_ObjectList_SCAM_V000D0006::EMB0_t_ObjectList_SCAM))
           && (requestPortVersionInfo.Equals(&VERSION000D0006) ) )
  {
    // Destination port of V000D0006
    EMB0_t_ObjectList_SCAM_V000D0006::EMB0_t_ObjectList_SCAM & Dest = (m_BufV000D0006);
    
    if ( ( (pProvidePortVersionInfo == NULL) || pProvidePortVersionInfo->Equals(&VERSION000D0006) )
        &&( (uDataVer == 0x000D0006u) ))
    {
      // same version
      const EMB0_t_ObjectList_SCAM_V000D0006::EMB0_t_ObjectList_SCAM & Src = *reinterpret_cast<EMB0_t_ObjectList_SCAM_V000D0006::EMB0_t_ObjectList_SCAM*>(pPPortData);
      *pOutData = (void*)&Src;
      ulOutSize = sizeof(Src);
      lRet = SIM_ERR_OK;
    }
    else if (  ( (pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VERSION000A0004)) )
             &&( (uDataVer == 0x000A0004u) ) )
    {
      const EMB0_t_ObjectList_SCAM_V000A0004::EMB0_t_ObjectList_SCAM & Src = *reinterpret_cast<EMB0_t_ObjectList_SCAM_V000A0004::EMB0_t_ObjectList_SCAM*>(pPPortData);
      v_Convert_vA0004_to_v000D0006(&Dest, &Src);
      *pOutData = (void*)&Dest;
      ulOutSize = sizeof(Dest);
      lRet = SIM_ERR_OK;
    }

    //if ((ulPPortSize == ulRPortSize)
    //  && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VERSION2)) || (pProvidePortVersionInfo->Equals(&VERSION80003)) || (pProvidePortVersionInfo->Equals(&BASE_VERSION)))
    //  && ((uDataVer == 0x60002u) || (uDataVer == 0x80003u) ||(uDataVer == 0x80004u) || (uDataVer == 0x50002u) || (uDataVer == 0xA0004u) ))
    //{
    //  const EMB0_t_ObjectList_SCAM_V50002::EMB0_t_ObjectList_SCAM & Src = *reinterpret_cast<EMB0_t_ObjectList_SCAM_V50002::EMB0_t_ObjectList_SCAM*>(pPPortData);
    //  *pOutData = (void*)&Src;
    //  ulOutSize = sizeof(Src);
    //  lRet = SIM_ERR_OK;
    //}

  }
  else if ((ulRPortSize == sizeof(EMB0_t_ObjectList_SCAM_V50002::EMB0_t_ObjectList_SCAM))
      && (requestPortVersionInfo.Equals(&VERSION000A0004) ||
          requestPortVersionInfo.Equals(&VERSION80004) ||
          requestPortVersionInfo.Equals(&VERSION80003) ||
          requestPortVersionInfo.Equals(&VERSION60002) ||
          requestPortVersionInfo.Equals(&VERSION50002) ||
          requestPortVersionInfo.Equals(&VERSION30002) ||
          requestPortVersionInfo.Equals(&VERSION2)     ||
          requestPortVersionInfo.Equals(&BASE_VERSION)  ) )
  {
    // Destination port of V50002
    EMB0_t_ObjectList_SCAM_V50002::EMB0_t_ObjectList_SCAM & Dest = /*reinterpret_cast<EMB0_t_ObjectList_SCAM_V2::EMB0_t_ObjectList_SCAM &>*/(m_BufV50002);
    if ((ulPPortSize == ulRPortSize)
      && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VERSION2)) || (pProvidePortVersionInfo->Equals(&VERSION80003)) || (pProvidePortVersionInfo->Equals(&BASE_VERSION)))
      && ((uDataVer == 0x60002u) || (uDataVer == 0x80003u) ||(uDataVer == 0x80004u) || (uDataVer == 0x50002u) || (uDataVer == 0xA0004u) ))
    {
      const EMB0_t_ObjectList_SCAM_V50002::EMB0_t_ObjectList_SCAM & Src = *reinterpret_cast<EMB0_t_ObjectList_SCAM_V50002::EMB0_t_ObjectList_SCAM*>(pPPortData);
      *pOutData = (void*)&Src;
      ulOutSize = sizeof(Src);
      lRet = SIM_ERR_OK;
    }
    else if ((ulPPortSize == sizeof(EMB0_t_ObjectList_SCAM_V30002::EMB0_t_ObjectList_SCAM))
      && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VERSION2)) || (pProvidePortVersionInfo->Equals(&BASE_VERSION)))
      && ( uDataVer == 0x30002u) )
    {
      const EMB0_t_ObjectList_SCAM_V30002::EMB0_t_ObjectList_SCAM & Src = *reinterpret_cast<EMB0_t_ObjectList_SCAM_V30002::EMB0_t_ObjectList_SCAM*>(pPPortData);
      v_Convert_v30002_to_v50002(&Dest, &Src);
      *pOutData = &Dest;
      ulOutSize = sizeof(Dest);
      lRet = SIM_ERR_OK;
    }
    else if ((ulPPortSize == sizeof(EMB0_t_ObjectList_SCAM_V2::EMB0_t_ObjectList_SCAM))
      && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VERSION2)) || (pProvidePortVersionInfo->Equals(&BASE_VERSION)))
      && ((uDataVer == 2u) || (uDataVer == 1) || (uDataVer == 0)))
    {
      const EMB0_t_ObjectList_SCAM_V2::EMB0_t_ObjectList_SCAM & Src = *reinterpret_cast<EMB0_t_ObjectList_SCAM_V2::EMB0_t_ObjectList_SCAM*>(pPPortData);
      v_Convert_v2_to_v50002(&Dest, &Src);
      *pOutData = &Dest;
      ulOutSize = sizeof(Dest);
      lRet = SIM_ERR_OK;
    }
    else if ((ulPPortSize == sizeof(EMB0_t_ObjectList_SCAM_V1::EMB0_t_ObjectList_SCAM))
      && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VERSION2)) || (pProvidePortVersionInfo->Equals(&BASE_VERSION)))
      && ((uDataVer == 2u) || (uDataVer == 1) || (uDataVer == 0)))
    {
      const EMB0_t_ObjectList_SCAM_V1::EMB0_t_ObjectList_SCAM & Src = *reinterpret_cast<EMB0_t_ObjectList_SCAM_V1::EMB0_t_ObjectList_SCAM*>(pPPortData);
      v_Convert_v1_to_v50002(&Dest, &Src);
      *pOutData = &Dest;
      ulOutSize = sizeof(Dest);
      lRet = SIM_ERR_OK;
    }
    // Data package for the sim_fusion_sync connection (byte aligned structures!)
    else if ((ulPPortSize == sizeof(EMB0_t_ObjectList_SCAM_V50002_R::EMB0_t_ObjectList_SCAM))
      && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VERSION80003)) || (pProvidePortVersionInfo->Equals(&VERSION60002)) || (pProvidePortVersionInfo->Equals(&VERSION50002)) || (pProvidePortVersionInfo->Equals(&BASE_VERSION)))
      && ((uDataVerR == 0xA0004u) || (uDataVerR == 0x80004u) || (uDataVerR == 0x80003u) || (uDataVerR == 0x60002u) || (uDataVerR == 0x50002u) ))
    {
      const EMB0_t_ObjectList_SCAM_V50002_R::EMB0_t_ObjectList_SCAM & Src = *reinterpret_cast<EMB0_t_ObjectList_SCAM_V50002_R::EMB0_t_ObjectList_SCAM*>(pPPortData);
      v_Convert_v50002_R_to_v50002(&Dest, &Src);
      *pOutData = (void*)&Dest;
      ulOutSize = sizeof(Dest);
      lRet = SIM_ERR_OK;
    }
    else if ((ulPPortSize == sizeof(EMB0_t_ObjectList_SCAM_V80003_RM::EMB0_t_ObjectList_SCAM))
      && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VERSION80003)) || (pProvidePortVersionInfo->Equals(&VERSION60002)) || (pProvidePortVersionInfo->Equals(&VERSION50002)) || (pProvidePortVersionInfo->Equals(&BASE_VERSION)))
      && ((uDataVerR == 0xA0004u) || (uDataVerR == 0x80004u) || (uDataVerR == 0x80003u) || (uDataVerR == 0x60002u) || (uDataVerR == 0x50002u) ))
    {
      const EMB0_t_ObjectList_SCAM_V80003_RM::EMB0_t_ObjectList_SCAM & Src = *reinterpret_cast<EMB0_t_ObjectList_SCAM_V80003_RM::EMB0_t_ObjectList_SCAM*>(pPPortData);
      v_Convert_v80003_RM_to_v50002(&Dest, &Src);
      *pOutData = (void*)&Dest;
      ulOutSize = sizeof(Dest);
      lRet = SIM_ERR_OK;
    }
  }
  else if ((ulRPortSize == sizeof(EMB0_t_ObjectList_SCAM_V30002::EMB0_t_ObjectList_SCAM))
          && (requestPortVersionInfo.Equals(&VERSION30002) ||
              requestPortVersionInfo.Equals(&VERSION2)     ||
              requestPortVersionInfo.Equals(&BASE_VERSION)))
  {
    // Destination port of V30002
    EMB0_t_ObjectList_SCAM_V30002::EMB0_t_ObjectList_SCAM & Dest = /*reinterpret_cast<EMB0_t_ObjectList_SCAM_V2::EMB0_t_ObjectList_SCAM &>*/(m_BufV30002);
    if ((ulPPortSize == ulRPortSize)
      && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VERSION2)) || (pProvidePortVersionInfo->Equals(&BASE_VERSION)))
      && ((uDataVer == 0x30002u) || (uDataVer == 2u) || (uDataVer == 1) || (uDataVer == 0)))
    {
      lRet = SIM_ERR_USE_VALUE_FROM_PPORT;
    }
    else if ((ulPPortSize == sizeof(EMB0_t_ObjectList_SCAM_V2::EMB0_t_ObjectList_SCAM))
      && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VERSION2)) || (pProvidePortVersionInfo->Equals(&BASE_VERSION)))
      && ((uDataVer == 2u) || (uDataVer == 1) || (uDataVer == 0)))
    {
      const EMB0_t_ObjectList_SCAM_V2::EMB0_t_ObjectList_SCAM & Src = *reinterpret_cast<EMB0_t_ObjectList_SCAM_V2::EMB0_t_ObjectList_SCAM*>(pPPortData);
      v_Convert_v2_to_v30002(&Dest, &Src);
      *pOutData = &Dest;
      ulOutSize = sizeof(Dest);
      lRet = SIM_ERR_OK;
    }
    else if ((ulPPortSize == sizeof(EMB0_t_ObjectList_SCAM_V1::EMB0_t_ObjectList_SCAM))
      && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VERSION2)) || (pProvidePortVersionInfo->Equals(&BASE_VERSION)))
      && ((uDataVer == 2u) || (uDataVer == 1) || (uDataVer == 0)))
    {
      const EMB0_t_ObjectList_SCAM_V1::EMB0_t_ObjectList_SCAM & Src = *reinterpret_cast<EMB0_t_ObjectList_SCAM_V1::EMB0_t_ObjectList_SCAM*>(pPPortData);
      v_Convert_v1_to_v30002(&Dest, &Src);
      *pOutData = &Dest;
      ulOutSize = sizeof(Dest);
      lRet = SIM_ERR_OK;
    }
  }
  else if ((ulRPortSize == sizeof(EMB0_t_ObjectList_SCAM_V2::EMB0_t_ObjectList_SCAM))
         && ( (requestPortVersionInfo.Equals(&VERSION2))
            ||(requestPortVersionInfo.Equals(&BASE_VERSION))))
  {
    // Destination port of V2
    EMB0_t_ObjectList_SCAM_V2::EMB0_t_ObjectList_SCAM & Dest = /*reinterpret_cast<EMB0_t_ObjectList_SCAM_V2::EMB0_t_ObjectList_SCAM &>*/(m_BufV2);
    if ((ulPPortSize == sizeof(EMB0_t_ObjectList_SCAM_V30002::EMB0_t_ObjectList_SCAM))
      && ((pProvidePortVersionInfo == NULL) || pProvidePortVersionInfo->Equals(&VERSION30002) || pProvidePortVersionInfo->Equals(&VERSION2) || pProvidePortVersionInfo->Equals(&BASE_VERSION))
      && ((uDataVer == 0x30002u) || (uDataVer == 2u) || (uDataVer == 1) || (uDataVer == 0)))
    {
      const EMB0_t_ObjectList_SCAM_V30002::EMB0_t_ObjectList_SCAM & Src = *reinterpret_cast<EMB0_t_ObjectList_SCAM_V30002::EMB0_t_ObjectList_SCAM*>(pPPortData);
      v_Convert_v30002_to_v2(&Dest, &Src);
      *pOutData = &Dest;
      ulOutSize = sizeof(Dest);
      lRet = SIM_ERR_OK;
    }
    else if ((ulPPortSize == ulRPortSize)
      && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VERSION2)) || (pProvidePortVersionInfo->Equals(&BASE_VERSION)))
      && ((uDataVer == 2u) || (uDataVer == 1) || (uDataVer == 0)))
    {
      lRet = SIM_ERR_USE_VALUE_FROM_PPORT;
    }
    else if ((ulPPortSize == sizeof(EMB0_t_ObjectList_SCAM_V1::EMB0_t_ObjectList_SCAM))
      && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VERSION2)) || (pProvidePortVersionInfo->Equals(&BASE_VERSION)))
      && ((uDataVer == 2u) || (uDataVer == 1) || (uDataVer == 0)))
    {
      const EMB0_t_ObjectList_SCAM_V1::EMB0_t_ObjectList_SCAM & Src = *reinterpret_cast<EMB0_t_ObjectList_SCAM_V1::EMB0_t_ObjectList_SCAM*>(pPPortData);
      v_Convert_v1_to_v2(&Dest, &Src);
      *pOutData = &Dest;
      ulOutSize = sizeof(Dest);
      lRet = SIM_ERR_OK;
    }
  }
  else if ((ulRPortSize == sizeof(EMB0_t_ObjectList_SCAM_V1::EMB0_t_ObjectList_SCAM))
        &&((requestPortVersionInfo.Equals(&VERSION2)) ||
           (requestPortVersionInfo.Equals(&BASE_VERSION))) )
  {
    // Destination port of V1
    EMB0_t_ObjectList_SCAM_V1::EMB0_t_ObjectList_SCAM & Dest = /*reinterpret_cast<EMB0_t_ObjectList_SCAM_V1::EMB0_t_ObjectList_SCAM &>*/(m_BufV1);;
    if ((ulPPortSize == sizeof(EMB0_t_ObjectList_SCAM_V30002::EMB0_t_ObjectList_SCAM))
      && ((pProvidePortVersionInfo == NULL) || pProvidePortVersionInfo->Equals(&VERSION30002) || pProvidePortVersionInfo->Equals(&VERSION2) || pProvidePortVersionInfo->Equals(&BASE_VERSION))
      && ((uDataVer == 0x30002u) || (uDataVer == 2u) || (uDataVer == 1) || (uDataVer == 0)))
    {
      const EMB0_t_ObjectList_SCAM_V30002::EMB0_t_ObjectList_SCAM & Src = *reinterpret_cast<EMB0_t_ObjectList_SCAM_V30002::EMB0_t_ObjectList_SCAM*>(pPPortData);
      v_Convert_v30002_to_v1(&Dest, &Src);
      *pOutData = &Dest;
      ulOutSize = sizeof(Dest);
      lRet = SIM_ERR_OK;
    }
    else if ((ulPPortSize == sizeof(EMB0_t_ObjectList_SCAM_V2::EMB0_t_ObjectList_SCAM))
      && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VERSION2)) || (pProvidePortVersionInfo->Equals(&BASE_VERSION)))
      && ((uDataVer == 2u) || (uDataVer == 1) || (uDataVer == 0)))
    {
      const EMB0_t_ObjectList_SCAM_V2::EMB0_t_ObjectList_SCAM & Src = *reinterpret_cast<EMB0_t_ObjectList_SCAM_V2::EMB0_t_ObjectList_SCAM*>(pPPortData);
      v_Convert_v2_to_v1(&Dest, &Src);
      *pOutData = &Dest;
      ulOutSize = sizeof(Dest);
      lRet = SIM_ERR_OK;
    }
    else if ((ulPPortSize == ulRPortSize)
      && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VERSION2)) || (pProvidePortVersionInfo->Equals(&BASE_VERSION)))
      && ((uDataVer == 2u) || (uDataVer == 1) || (uDataVer == 0)))
    {
      lRet = SIM_ERR_USE_VALUE_FROM_PPORT;
    }
  }
  return lRet;
}

/** returns:
 *   SIM_ERR_OK - when this value can be used
 *   SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT - when the default vaule is not implememnted here
 *                                            and the default value from Request Port must be used
 */
long CConvEmObjectListScam::GetDefaultValue(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
  void **pDefaultData, unsigned long &ulDefaultSize)
{
  long lRet = SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT;
  if (eRPortType == simOPAQUE_t)
  {
    if ( (ulRPortSize == sizeof(EMB0_t_ObjectList_SCAM_V000A0004::EMB0_t_ObjectList_SCAM)) && (VERSION000A0004.Equals(&requestPortVersionInfo)) )
    {
      InitV000A0004(m_BufV000A0004);
      *pDefaultData = &m_BufV000A0004;
      ulDefaultSize = sizeof(EMB0_t_ObjectList_SCAM_V000A0004::EMB0_t_ObjectList_SCAM);
      lRet = SIM_ERR_OK;
    }
    if ((ulRPortSize == sizeof(EMB0_t_ObjectList_SCAM_V000D0006::EMB0_t_ObjectList_SCAM)) && ((VERSION000D0006.Equals(&requestPortVersionInfo)) ))
    {
      InitV000D0006(m_BufV000D0006);
      *pDefaultData = &m_BufV000D0006;
      ulDefaultSize = sizeof(EMB0_t_ObjectList_SCAM_V000D0006::EMB0_t_ObjectList_SCAM);
      lRet = SIM_ERR_OK;
    }
    if ((ulRPortSize == sizeof(EMB0_t_ObjectList_SCAM_V50002::EMB0_t_ObjectList_SCAM)) && ((BASE_VERSION.Equals(&requestPortVersionInfo)) || (VERSION80003.Equals(&requestPortVersionInfo)) || (VERSION60002.Equals(&requestPortVersionInfo)) || (VERSION50002.Equals(&requestPortVersionInfo)) ))
    {
      InitV50002(m_BufV50002);
      *pDefaultData = &m_BufV50002;
      ulDefaultSize = sizeof(EMB0_t_ObjectList_SCAM_V50002::EMB0_t_ObjectList_SCAM);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(EMB0_t_ObjectList_SCAM_V30002::EMB0_t_ObjectList_SCAM)) && ((BASE_VERSION.Equals(&requestPortVersionInfo)) || (VERSION30002.Equals(&requestPortVersionInfo))))
    {
      InitV30002(m_BufV30002);
      *pDefaultData = &m_BufV30002;
      ulDefaultSize = sizeof(EMB0_t_ObjectList_SCAM_V30002::EMB0_t_ObjectList_SCAM);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(EMB0_t_ObjectList_SCAM_V2::EMB0_t_ObjectList_SCAM)) && ((BASE_VERSION.Equals(&requestPortVersionInfo)) || (VERSION2.Equals(&requestPortVersionInfo))))
    {
      InitV2(m_BufV2);
      *pDefaultData = &m_BufV2;
      ulDefaultSize = sizeof(EMB0_t_ObjectList_SCAM_V2::EMB0_t_ObjectList_SCAM);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(EMB0_t_ObjectList_SCAM_V1::EMB0_t_ObjectList_SCAM)) && ((BASE_VERSION.Equals(&requestPortVersionInfo)) || (VERSION2.Equals(&requestPortVersionInfo))))
    {
      InitV1(m_BufV1);
      *pDefaultData = &m_BufV1;
      ulDefaultSize = sizeof(EMB0_t_ObjectList_SCAM_V1::EMB0_t_ObjectList_SCAM);
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
bool CConvEmObjectListScam::IsVersionCompatibleWithType(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
  SimPortDataTypes_t ePPortType, unsigned long ulPPortSize)
{
  bool bResult = false;
  // Equal ports are always compatible (at least assumed to be)
  if ((ulRPortSize == ulPPortSize) && (eRPortType == ePPortType))
  {
    bResult = true;
  }
  else if ((eRPortType == simOPAQUE_t) && (ePPortType == simOPAQUE_t))
  {
    if ((IsPortSupported(ulRPortSize, &requestPortVersionInfo)) && (IsPortSupported(ulPPortSize, NULL)))
    {
      bResult = true;
    }
  }
  // Data package for the sim_fusion_sync connection (byte aligned structures!)
  else if ((eRPortType == simOPAQUE_t) && (ePPortType == simREFERENCE_t))
  {
    if (requestPortVersionInfo.Equals(&VERSION000D0006) ||
      requestPortVersionInfo.Equals(&VERSION000A0004) ||
      requestPortVersionInfo.Equals(&VERSION80004) ||
      requestPortVersionInfo.Equals(&VERSION80003) ||
      requestPortVersionInfo.Equals(&VERSION60002) ||
      requestPortVersionInfo.Equals(&VERSION50002) ||
      requestPortVersionInfo.Equals(&BASE_VERSION))
    {
      if (ulRPortSize == sizeof(EMB0_t_ObjectList_SCAM_V50002::EMB0_t_ObjectList_SCAM))
      {
        if ((ulPPortSize == sizeof(EMB0_t_ObjectList_SCAM_V50002_R::EMB0_t_ObjectList_SCAM)) || (ulPPortSize == sizeof(EMB0_t_ObjectList_SCAM_V80003_RM::EMB0_t_ObjectList_SCAM)))
        {
          bResult = true;
        }
      }
    }
  }
  return bResult;
}

// used to check if ports are compatible between different versions
bool CConvEmObjectListScam::AreVersionsCompatible(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
  SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo &providePortVersionInfo)
{
  bool bResult = false;
  // Equal ports are always compatible (at least assumed to be)
  if ((ulRPortSize == ulPPortSize) && (eRPortType == ePPortType))
  {
    bResult = true;
  }
  else if ((eRPortType == simOPAQUE_t) && (ePPortType == simOPAQUE_t))
  {
    if ((IsPortSupported(ulRPortSize, &requestPortVersionInfo)) && (IsPortSupported(ulPPortSize, &providePortVersionInfo)))
    {
      bResult = true;
    }
  }
  // Data package for the sim_fusion_sync connection (byte aligned structures!)
  else if ((eRPortType == simOPAQUE_t) && (ePPortType == simREFERENCE_t))
  {
    if (providePortVersionInfo.Equals(&VERSION000A0004) ||
        providePortVersionInfo.Equals(&VERSION80004) ||
        requestPortVersionInfo.Equals(&VERSION80003) ||
        requestPortVersionInfo.Equals(&VERSION60002) ||
        requestPortVersionInfo.Equals(&VERSION50002) ||
        requestPortVersionInfo.Equals(&BASE_VERSION)   )
    {
      if (ulRPortSize == sizeof(EMB0_t_ObjectList_SCAM_V50002::EMB0_t_ObjectList_SCAM))
      {
        if (providePortVersionInfo.Equals(&VERSION000A0004) ||
            providePortVersionInfo.Equals(&VERSION80004) ||
            providePortVersionInfo.Equals(&VERSION80003) ||
            providePortVersionInfo.Equals(&VERSION60002) ||
            providePortVersionInfo.Equals(&VERSION50002) ||
            providePortVersionInfo.Equals(&BASE_VERSION)   )
        {
          if ((ulPPortSize == sizeof(EMB0_t_ObjectList_SCAM_V50002_R::EMB0_t_ObjectList_SCAM)) || (ulPPortSize == sizeof(EMB0_t_ObjectList_SCAM_V80003_RM::EMB0_t_ObjectList_SCAM)))
          {
            bResult = true;
          }
        }
      }
    }
  }
  return bResult;
}

//
// Main factory class returning conversion class
//
IConverter * CreateEmObjectListScamConvClass(void)
{
  return new CConvEmObjectListScam();
}
