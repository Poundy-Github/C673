/*! \file **********************************************************************

  COMPANY:         Continental

  PROJECT:         Simulation

  COMPONENT:       sim_adapter em

  MODULNAME:       sim_conv_em_objectlist_custom.cpp

  DESCRIPTION:

  AUTHOR:          Thomas Berndt

  CREATION DATE:   25.2.2015

  VERSION:         $Revision: 1.1 $

  ---*/ /*---
  CHANGES:         $Log: sim_conv_em_objectlist_custom.cpp  $
  CHANGES:         Revision 1.1 2017/08/10 13:14:59CEST uid34177 
  CHANGES:         Initial revision
  CHANGES:         Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_adapter/awv/project.pj
  CHANGES:         Revision 1.4 2015/08/21 06:44:57CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:         + New version 7_2 of custom obect list
  CHANGES:         - Added comments -  berndtt1 [Aug 21, 2015 9:15:45 AM CEST]
  CHANGES:         Change Package : 221167:51 http://mks-psad:7002/im/viewissue?selection=221167
  CHANGES:         Revision 1.3 2015/05/20 11:19:56CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:         + New version 7 of custom obect list
  CHANGES:         --- Added comments ---  berndtt1 [May 20, 2015 11:22:25 AM CEST]
  CHANGES:         Change Package : 339696:1 http://mks-psad:7002/im/viewissue?selection=339696
  CHANGES:         Revision 1.2 2015/03/02 16:47:20CET Berndt, Thomas01 (berndtt1) 
  CHANGES:         Don't check port version when equality of size is given
  CHANGES:         --- Added comments ---  berndtt1 [Mar 2, 2015 4:51:56 PM CET]
  CHANGES:         Change Package : 276620:4 http://mks-psad:7002/im/viewissue?selection=276620
  CHANGES:         Revision 1.1 2015/02/25 12:59:31CET Berndt, Thomas01 (berndtt1) 
  CHANGES:         Initial revision
  CHANGES:         Member added to project /nfs/projekte1/PROJECTS/ARS400/06_Algorithm/04_Engineering/03_Workspace/algo/sim_adapter/awv/project.pj

**************************************************************************** */
/* includes ---------------------------------------------------------------- */

#include "sim_adapter_cfg.h"
#include "sim_conv_em_objectlist_custom.h"
#include "sim_versioninfo_impl.h"

/** 
* @brief The standard AUTOSAR type boolean shall be implemented on basis of an eight bits long 
*        unsigned integer.
* @implements boolean_type
*/
typedef unsigned char boolean;
/* Boolean types */
typedef boolean Boolean                                              /* [Satisfies_rte sws 1188] */;

/* Common definitions/declarations */
typedef unsigned __int8 EM_t_CustomerProjectDef                      /* Indicator to identify application projects @min: 0 @max:10 @values: enum { EM_PRJ_ARS4B0=1,EM_PRJ_ARS4D2=4,EM_PRJ_ARS4D1=3,EM_PRJ_ARS4D0=2,EM_PRJ_ARS4G0=9,EM_PRJ_ARS400=0,EM_PRJ_ARS4L1=6,EM_PRJ_ARS4L0=5,EM_PRJ_ARS4A0=10,EM_PRJ_ARS4T0=7,EM_PRJ_ARS4V0=8,} */ /* [Satisfies_rte sws 1180], [Satisfies_rte sws 1265] */;
typedef signed __int8 ObjNumber_t                                    /* Object Number (Object ID) @min:-1 @max:127 */ /* [Satisfies_rte sws 1177], [Satisfies_rte sws 1265] */;
typedef unsigned __int8 EM_t_VW_Obj_Mt_State                         /* Indicate the tracking state of object @min: 0 @max:5 @values: enum { EM_VW_OBJECT_STATE_MEASURED=2,EM_VW_OBJECT_STATE_MAX_DIFF_TYPES=5,EM_VW_OBJECT_STATE_INACTIVE=4,EM_VW_OBJECT_STATE_DELETED=0,EM_VW_OBJECT_STATE_PREDICTED=3,EM_VW_OBJECT_STATE_NEW=1,} */ /* [Satisfies_rte sws 1180], [Satisfies_rte sws 1265] */;
typedef unsigned __int8 percentage_t                                 /* percentage @min:0 @max:100 @resolution:1.0 */ /* [Satisfies_rte sws 1180], [Satisfies_rte sws 1265] */;
typedef unsigned __int8 EM_t_VW_Obj_Class                            /* This signal indicates the class of the object. Optimizes for ACC function. Classification limitation especially for pedestrians and bicycles @min: 0 @max:8 @values: enum { EM_VW_OBJECT_CLASS_PEDESTRIAN=3,EM_VW_OBJECT_CLASS_POINT=0,EM_VW_OBJECT_CLASS_TRUCK=2,EM_VW_OBJECT_CLASS_MAX_DIFF_TYPES=8,EM_VW_OBJECT_CLASS_MOTORCYCLE=4,EM_VW_OBJECT_CLASS_WIDE=6,EM_VW_OBJECT_CLASS_UNCLASSIFIED=7,EM_VW_OBJECT_CLASS_CAR=1,EM_VW_OBJECT_CLASS_BICYCLE=5,} */ /* [Satisfies_rte sws 1180], [Satisfies_rte sws 1265] */;
typedef unsigned __int8 EM_t_VW_Obj_Dyn_Prop                         /* This signal indicates wether the object is moving, stationary or oncoming, based on comparison of the longitudinal relative velocity with the host vehicle velocity. @min: 0 @max:7 @values: enum { EM_VW_OBJECT_DYN_PROPERTY_UNKNOWN=5,EM_VW_OBJECT_DYN_PROPERTY_CROSSING_RIGHT=4,EM_VW_OBJECT_DYN_PROPERTY_ONCOMING=2,EM_VW_OBJECT_DYN_PROPERTY_STATIONARY=1,EM_VW_OBJECT_DYN_PROPERTY_STOPPED=6,EM_VW_OBJECT_DYN_PROPERTY_MAX_DIFF_TYPES=7,EM_VW_OBJECT_DYN_PROPERTY_CROSSING_LEFT=3,EM_VW_OBJECT_DYN_PROPERTY_MOVING=0,} */ /* [Satisfies_rte sws 1180], [Satisfies_rte sws 1265] */;
typedef unsigned __int8 EMVW_t_ClassificationType                    /* Object classification @min: 0 @max:15 @values: enum { EMVW_CAM_CLASS_UEBERFAHRBAR=1,EMVW_CAM_CLASS_PKW=7,EMVW_CAM_CLASS_RETROREFLEKTOR=12,EMVW_CAM_CLASS_TIER=11,EMVW_CAM_CLASS_FAHRRAD=5,EMVW_CAM_CLASS_FUSSGAENGERGRUPPE=4,EMVW_CAM_CLASS_INIT=15,EMVW_CAM_CLASS_MOTORRAD=6,EMVW_CAM_CLASS_RANDBEBAUUNG=10,EMVW_CAM_CLASS_FUSSGAENGER=3,EMVW_CAM_CLASS_UNTERFAHRBAR=2,EMVW_CAM_CLASS_UNBEKANNT=0,EMVW_CAM_CLASS_VAN=8,EMVW_CAM_CLASS_LKW=9,} */ /* [Satisfies_rte sws 1180], [Satisfies_rte sws 1265] */;

typedef unsigned long AlgoInterfaceVersionNumber_t                   /* Algo interface version nummbers @min:0 @max:4294967295 */ /* [Satisfies_rte sws 1188] */;
typedef unsigned long AlgoDataTimeStamp_t                            /* Algo data time-stamp type (32 bit variant) @min:0 @max:4294967295 */ /* [Satisfies_rte sws 1188] */;
typedef unsigned short AlgoCycleCounter_t                            /* Algo cycle counter @min:0 @max:65535 */ /* [Satisfies_rte sws 1188] */;
typedef unsigned char AlgoSignalState_t                              /* Algo signal state enumeration @min: 0 @max:2 @values: enum { AL_SIG_STATE_INVALID=2,AL_SIG_STATE_INIT=0,AL_SIG_STATE_OK=1,} */ /* [Satisfies_rte sws 1188] */;

typedef struct SignalHeader_t                                        /* [Satisfies_rte sws 1191] */
{
  AlgoDataTimeStamp_t uiTimeStamp;
  AlgoCycleCounter_t uiMeasurementCounter;
  AlgoCycleCounter_t uiCycleCounter;
  AlgoSignalState_t eSigStatus;
} SignalHeader_t;                                                    /* Common header for all structured data types */

// X120 RTE 1.2
namespace EM_t_ObjectList_Custom_V4
{
  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    percentage_t u_CamConf;                                          /* camera confirmation probability @min:0 @max:100 */
    ObjNumber_t u_CamID;                                             /* ID of assiciated camera object 0 - no object 1.. 254   valid objects */
    EMVW_t_ClassificationType e_CamClass;                            /* Object Classification */
    float f_CamDistY;                                                /* Lateral (parallel to ego-vehicle y-axis) distance to object reference point. Positive to the left */
    float f_CamDistYStd;                                             /* Standard deviation of fDistY */
    float f_CamVrelY;                                                /* Relative lateral velocity: Velocity of the object in lateral direction, relative to the host vehicle. This value shall be positive when the object is moving towards the left. */
    float f_CamVrelYStd;                                             /* Relative lateral velocity standard deviation */
    float f_CamWidth;                                                /* Object width (lateral dimension) */
  } EM_t_Cust_CamObjectData;                                         /* COD related data per internal object */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    ObjNumber_t u_ExternalID;                                        /* External object ID -1  no object 0..127 valid Ids */
    float f_LifeTime;                                                /* object lifetime in seconds */
    EM_t_VW_Obj_Mt_State e_MaintenanceState;                         /* Indicate the tracking state of object */
    percentage_t u_ProbabilityOfExistence;                           /* Likelihood that object is present. Probability that the object is a real object. @min:0 @max:100 */
    EM_t_VW_Obj_Class e_Classification;                              /* This signal indicates the class of the object. Optimizes for ACC function. Classification limitation especially for pedestrians and bicycles */
    EM_t_VW_Obj_Dyn_Prop e_DynamicProperty;                          /* This signal indicates wether the object is moving, stationary or oncoming, based on comparison of the longitudinal relative velocity with the host vehicle velocity. */
    float f_Length;                                                  /* Object length (longitunal dimension) */
    float f_Width;                                                   /* Object width (lateral dimension) based on measurement supported by the assumed object width as a function of the object class */
    float f_DistX;                                                   /* Longitudinal (parallel to ego-vehicle x-axis) distance to object kinematic point. */
    float f_DistXStd;                                                /* Standard deviation of fDistX. Negative if invalid. */
    float f_DistY;                                                   /* Lateral (parallel to ego-vehicle y-axis) distance to object kinematic point. Positive to the left. */
    float f_DistYStd;                                                /* Standard deviation of fDistY. Negative if invalid. */
    float f_VrelX;                                                   /* Relative longitudinal velocity: Difference in longitudinal velocity of the host and the object. This value shall be positive when the object velocity is higher than the host velocity (opening velocity). */
    float f_VrelXStd;                                                /* Relative longitudinal velocity standard deviation: Set to negative value (-1.0) if signal not available. */
    float f_VrelY;                                                   /* Relative lateral velocity: Velocity of the object in lateral direction, relative to the host vehicle. This value shall be positive when the object is moving towards the left. */
    float f_VrelYStd;                                                /* Relative lateral velocity standard deviation: Set to negative value (-1.0) if signal not available. */
    float f_ArelX;                                                   /* Relative longitudinal acceleration: Difference in longitudinal acceleration of the host and the object. This value shall be positive when the object acceleration is higher than the host acceleration. */
    float f_ArelXStd;                                                /* Relative longitudinal acceleration standard deviation: Set to negative value (-1.0) if signal not available. */
    float f_Orientation;                                             /* Motion direction of object relative to ego vehicle */
    percentage_t u_ObstacleProbability;                              /* Probability that the object is an obstacle @min:0 @max:100 */
    float f_PedestrianProbability;                                   /* Probability that the object is a crossing pedestrian @min:0 @max:1 */
    unsigned __int8 u_MeasuredTargetFrequency;                       /* Bitfield of the maintenance state of the last 8 cycles @min:0 @max:255 */
    float f_UpdateQuality;                                           /* Update confidence @min:0 @max:1 */
    EM_t_Cust_CamObjectData CamObjectData;                           /* COD related data per internal object */
  } EM_t_Cust_ObjectData;                                            /* customer related data per internal object */

  typedef EM_t_Cust_ObjectData CustObjects_array_t[40];              /* customer related data per internal object */ /* [Satisfies_rte sws 1189] */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    AlgoInterfaceVersionNumber_t u_VersionNumber;                    /* Interface version number (32bit) (increased when changed) @min:0 @max:16277215 */
    SignalHeader_t sSigHeader;                                       /* information for synchronisation of SIL simulation */
    EM_t_CustomerProjectDef project;                                 /* Indicator to identify application projects  (8bit) */
    CustObjects_array_t CustObjects;                                 /* customer related data per internal object */
  } EM_t_ObjectList_Custom;                                          /* Custom Outputs for functional and customer requirements @vaddr:0x201A0000 @vaddr_defs: EM_MEAS_ID_CUSTOM_OBJECT_LIST @cycleid:EM_ENV @vname:EMCustomerObjData */
} // end of EM_t_ObjectList_Custom_V4



namespace EM_t_ObjectList_Custom_V5
{
  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    ObjNumber_t u_ExternalID;                                        /* External object ID -1  no object 0..127 valid Ids */
    float f_LifeTime;                                                /* object lifetime in seconds */
    EM_t_VW_Obj_Mt_State e_MaintenanceState;                         /* Indicate the tracking state of object */
    percentage_t u_ProbabilityOfExistence;                           /* Likelihood that object is present. Probability that the object is a real object. @min:0 @max:100 */
    EM_t_VW_Obj_Class e_Classification;                              /* This signal indicates the class of the object. Optimizes for ACC function. Classification limitation especially for pedestrians and bicycles */
    EM_t_VW_Obj_Dyn_Prop e_DynamicProperty;                          /* This signal indicates wether the object is moving, stationary or oncoming, based on comparison of the longitudinal relative velocity with the host vehicle velocity. */
    float f_Length;                                                  /* Object length (longitunal dimension) */
    float f_Width;                                                   /* Object width (lateral dimension) based on measurement supported by the assumed object width as a function of the object class */
    float f_DistX;                                                   /* Longitudinal (parallel to ego-vehicle x-axis) distance to object kinematic point. */
    float f_DistXStd;                                                /* Standard deviation of fDistX. Negative if invalid. */
    float f_DistY;                                                   /* Lateral (parallel to ego-vehicle y-axis) distance to object kinematic point. Positive to the left. */
    float f_DistYStd;                                                /* Standard deviation of fDistY. Negative if invalid. */
    float f_VrelX;                                                   /* Relative longitudinal velocity: Difference in longitudinal velocity of the host and the object. This value shall be positive when the object velocity is higher than the host velocity (opening velocity). */
    float f_VrelXStd;                                                /* Relative longitudinal velocity standard deviation: Set to negative value (-1.0) if signal not available. */
    float f_VrelY;                                                   /* Relative lateral velocity: Velocity of the object in lateral direction, relative to the host vehicle. This value shall be positive when the object is moving towards the left. */
    float f_VrelYStd;                                                /* Relative lateral velocity standard deviation: Set to negative value (-1.0) if signal not available. */
    float f_ArelX;                                                   /* Relative longitudinal acceleration: Difference in longitudinal acceleration of the host and the object. This value shall be positive when the object acceleration is higher than the host acceleration. */
    float f_ArelXStd;                                                /* Relative longitudinal acceleration standard deviation: Set to negative value (-1.0) if signal not available. */
    float f_Orientation;                                             /* Motion direction of object relative to ego vehicle */
    percentage_t u_ObstacleProbability;                              /* Probability that the object is an obstacle @min:0 @max:100 */
    float f_PedestrianProbability;                                   /* Probability that the object is a crossing pedestrian @min:0 @max:1 */
    unsigned __int8 u_MeasuredTargetFrequency;                       /* Bitfield of the maintenance state of the last 8 cycles @min:0 @max:255 */
    float f_UpdateQuality;                                           /* Update confidence @min:0 @max:1 */
    unsigned __int8 u_PedestrianMicroDoppler;                        /* Flag for detection of pedestrian via micro doppler effect @min:0 @max:1 */
    EM_t_ObjectList_Custom_V4::EM_t_Cust_CamObjectData CamObjectData;/* COD related data per internal object */
  } EM_t_Cust_ObjectData;                                            /* customer related data per internal object */

  typedef EM_t_Cust_ObjectData CustObjects_array_t[40];              /* customer related data per internal object */ /* [Satisfies_rte sws 1189] */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    AlgoInterfaceVersionNumber_t u_VersionNumber;                    /* Interface version number (32bit) (increased when changed) @min:0 @max:16277215 */
    SignalHeader_t sSigHeader;                                       /* information for synchronisation of SIL simulation */
    EM_t_CustomerProjectDef project;                                 /* Indicator to identify application projects  (8bit) */
    CustObjects_array_t CustObjects;                                 /* customer related data per internal object */
  } EM_t_ObjectList_Custom;                                          /* Custom Outputs for functional and customer requirements @vaddr:0x201A0000 @vaddr_defs: EM_MEAS_ID_CUSTOM_OBJECT_LIST @cycleid:EM_ENV @vname:EMCustomerObjData */
} // end of EM_t_ObjectList_Custom_V5

namespace EM_t_ObjectList_Custom_V7                                  // Size 4660
{
  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    percentage_t u_CamConf;                                          /* camera confirmation probability @min:0 @max:100 */
    unsigned char u_CamID;                                           /* ID of assiciated camera object 0 - no object 1.. 254   valid objects 255 invalid */
    EMVW_t_ClassificationType e_CamClass;                            /* Object Classification */
    float f_CamDistY;                                                /* Lateral (parallel to ego-vehicle y-axis) distance to object reference point. Positive to the left */
    float f_CamDistYStd;                                             /* Standard deviation of fDistY */
    float f_CamVrelY;                                                /* Relative lateral velocity: Velocity of the object in lateral direction, relative to the host vehicle. This value shall be positive when the object is moving towards the left. */
    float f_CamVrelYStd;                                             /* Relative lateral velocity standard deviation */
    float f_CamWidth;                                                /* Object width (lateral dimension) */
    float f_ObjLineCoverAngleL;                                      /* Object angle overlap between right ego lane border and left rear object corner. Positive if left rear object corner is right to right ego lane border */
    float f_ObjLineCoverAngleR;                                      /* Object angle overlap between left ego lane border and right rear object corner. Positive if right rear object corner is right to left ego lane border. */
  } EM_t_Cust_CamObjectData;                                         /* COD related data per internal object */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    ObjNumber_t u_ExternalID;                                        /* External object ID -1  no object 0..127 valid Ids */
    float f_LifeTime;                                                /* object lifetime in seconds */
    EM_t_VW_Obj_Mt_State e_MaintenanceState;                         /* Indicate the tracking state of object */
    percentage_t u_ProbabilityOfExistence;                           /* Likelihood that object is present. Probability that the object is a real object. @min:0 @max:100 */
    EM_t_VW_Obj_Class e_Classification;                              /* This signal indicates the class of the object. Optimizes for ACC function. Classification limitation especially for pedestrians and bicycles */
    EM_t_VW_Obj_Dyn_Prop e_DynamicProperty;                          /* This signal indicates wether the object is moving, stationary or oncoming, based on comparison of the longitudinal relative velocity with the host vehicle velocity. */
    float f_Length;                                                  /* Object length (longitunal dimension) */
    float f_Width;                                                   /* Object width (lateral dimension) based on measurement supported by the assumed object width as a function of the object class */
    float f_DistX;                                                   /* Longitudinal (parallel to ego-vehicle x-axis) distance to object kinematic point. */
    float f_DistXStd;                                                /* Standard deviation of fDistX. Negative if invalid. */
    float f_DistY;                                                   /* Lateral (parallel to ego-vehicle y-axis) distance to object kinematic point. Positive to the left. */
    float f_DistYStd;                                                /* Standard deviation of fDistY. Negative if invalid. */
    float f_VrelX;                                                   /* Relative longitudinal velocity: Difference in longitudinal velocity of the host and the object. This value shall be positive when the object velocity is higher than the host velocity (opening velocity). */
    float f_VrelXStd;                                                /* Relative longitudinal velocity standard deviation: Set to negative value (-1.0) if signal not available. */
    float f_VrelY;                                                   /* Relative lateral velocity: Velocity of the object in lateral direction, relative to the host vehicle. This value shall be positive when the object is moving towards the left. */
    float f_VrelYStd;                                                /* Relative lateral velocity standard deviation: Set to negative value (-1.0) if signal not available. */
    float f_ArelX;                                                   /* Relative longitudinal acceleration: Difference in longitudinal acceleration of the host and the object. This value shall be positive when the object acceleration is higher than the host acceleration. */
    float f_ArelXStd;                                                /* Relative longitudinal acceleration standard deviation: Set to negative value (-1.0) if signal not available. */
    float f_Orientation;                                             /* Motion direction of object relative to ego vehicle */
    percentage_t u_ObstacleProbability;                              /* Probability that the object is an obstacle @min:0 @max:100 */
    float f_PedestrianProbability;                                   /* Probability that the object is a crossing pedestrian @min:0 @max:1 */
    unsigned __int8 u_MeasuredTargetFrequency;                       /* Bitfield of the maintenance state of the last 8 cycles @min:0 @max:255 */
    float f_UpdateQuality;                                           /* Update confidence @min:0 @max:1 */
    unsigned __int8 u_PedestrianMicroDoppler;                        /* Flag for detection of pedestrian via micro doppler effect @min:0 @max:1 */
    EM_t_Cust_CamObjectData CamObjectData;                           /* COD related data per internal object */
  } EM_t_Cust_ObjectData;                                            /* customer related data per internal object */

  typedef EM_t_Cust_ObjectData CustObjects_array_t[40];              /* customer related data per internal object */ /* [Satisfies_rte sws 1189] */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    AlgoInterfaceVersionNumber_t u_VersionNumber;                    /* Interface version number (32bit) (increased when changed) @min:0 @max:16277215 */
    SignalHeader_t sSigHeader;                                       /* information for synchronisation of SIL simulation */
    EM_t_CustomerProjectDef project;                                 /* Indicator to identify application projects  (8bit) */
    CustObjects_array_t CustObjects;                                 /* customer related data per internal object */
  } EM_t_ObjectList_Custom;                                          /* Custom Outputs for functional and customer requirements @vaddr:0x201A0000 @vaddr_defs: EM_MEAS_ID_CUSTOM_OBJECT_LIST @cycleid:EM_ENV @vname:EMCustomerObjData */
} // end of EM_t_ObjectList_Custom_V7

namespace EM_t_ObjectList_Custom_V7_2                                // Size 5780
{
  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    ObjNumber_t u_ExternalID;                                        /* External object ID -1  no object 0..127 valid Ids */
    float f_LifeTime;                                                /* object lifetime in seconds */
    EM_t_VW_Obj_Mt_State e_MaintenanceState;                         /* Indicate the tracking state of object */
    percentage_t u_ProbabilityOfExistence;                           /* Likelihood that object is present. Probability that the object is a real object. @min:0 @max:100 */
    EM_t_VW_Obj_Class e_Classification;                              /* This signal indicates the class of the object. Optimizes for ACC function. Classification limitation especially for pedestrians and bicycles */
    EM_t_VW_Obj_Dyn_Prop e_DynamicProperty;                          /* This signal indicates wether the object is moving, stationary or oncoming, based on comparison of the longitudinal relative velocity with the host vehicle velocity. */
    float f_Length;                                                  /* Object length (longitunal dimension) */
    float f_Width;                                                   /* Object width (lateral dimension) based on measurement supported by the assumed object width as a function of the object class */
    float f_DistX;                                                   /* Longitudinal (parallel to ego-vehicle x-axis) distance to object kinematic point. */
    float f_DistXStd;                                                /* Standard deviation of fDistX. Negative if invalid. */
    float f_DistY;                                                   /* Lateral (parallel to ego-vehicle y-axis) distance to object kinematic point. Positive to the left. */
    float f_DistYStd;                                                /* Standard deviation of fDistY. Negative if invalid. */
    float f_VrelX;                                                   /* Relative longitudinal velocity: Difference in longitudinal velocity of the host and the object. This value shall be positive when the object velocity is higher than the host velocity (opening velocity). */
    float f_VrelXStd;                                                /* Relative longitudinal velocity standard deviation: Set to negative value (-1.0) if signal not available. */
    float f_VrelY;                                                   /* Relative lateral velocity: Velocity of the object in lateral direction, relative to the host vehicle. This value shall be positive when the object is moving towards the left. */
    float f_VrelYStd;                                                /* Relative lateral velocity standard deviation: Set to negative value (-1.0) if signal not available. */
    float f_ArelX;                                                   /* Relative longitudinal acceleration: Difference in longitudinal acceleration of the host and the object. This value shall be positive when the object acceleration is higher than the host acceleration. */
    float f_ArelXStd;                                                /* Relative longitudinal acceleration standard deviation: Set to negative value (-1.0) if signal not available. */
    float f_Orientation;                                             /* Motion direction of object relative to ego vehicle */
    percentage_t u_ObstacleProbability;                              /* Probability that the object is an obstacle @min:0 @max:100 */
    float f_PedestrianProbability;                                   /* Probability that the object is a crossing pedestrian @min:0 @max:1 */
    unsigned __int8 u_MeasuredTargetFrequency;                       /* Bitfield of the maintenance state of the last 8 cycles @min:0 @max:255 */
    float f_UpdateQuality;                                           /* Update confidence @min:0 @max:1 */
    unsigned __int8 u_PedestrianMicroDoppler;                        /* Flag for detection of pedestrian via micro doppler effect @min:0 @max:1 */
    float f_VabsX;                                                   /* Absolute longitudinal velocity of the object */
    float f_VabsY;                                                   /* Absolute lateral velocity of the object */
    float f_AabsX;                                                   /* Absolute longitudinal acceleration: Longitudinal acceleration of the object */
    float f_AabsY;                                                   /* Absolute lateral acceleration: Acceleration in lateral direction of the object. */
    unsigned __int8 u_EBAObjectQuality;                              /* EBA Object Quality from pre-selection */
    unsigned __int8 u_ObjSafe;                                       /* EBA Object Quality bits */
    float f_Reserved1;                                               /* Reserved float */
    __int32 s_Reserved2;                                             /* Reserved signed integer */
    EM_t_ObjectList_Custom_V7::EM_t_Cust_CamObjectData CamObjectData;/* COD related data per internal object */
  } EM_t_Cust_ObjectData;                                            /* customer related data per internal object */

  typedef EM_t_Cust_ObjectData CustObjects_array_t[40];              /* customer related data per internal object */ /* [Satisfies_rte sws 1189] */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    AlgoInterfaceVersionNumber_t u_VersionNumber;                    /* Interface version number (32bit) (increased when changed) @min:0 @max:16277215 */
    SignalHeader_t sSigHeader;                                       /* information for synchronisation of SIL simulation */
    EM_t_CustomerProjectDef project;                                 /* Indicator to identify application projects  (8bit) */
    CustObjects_array_t CustObjects;                                 /* customer related data per internal object */
  } EM_t_ObjectList_Custom;                                          /* Custom Outputs for functional and customer requirements @vaddr:0x201A0000 @vaddr_defs: EM_MEAS_ID_CUSTOM_OBJECT_LIST @cycleid:EM_ENV @vname:EMCustomerObjData */
} // end of EM_t_ObjectList_Custom_V7_2


class CConvEmObjectlistCustom : public CSimConverterBase
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

  EM_t_ObjectList_Custom_V4::EM_t_ObjectList_Custom m_BufV4;
  EM_t_ObjectList_Custom_V5::EM_t_ObjectList_Custom m_BufV5;
  EM_t_ObjectList_Custom_V7::EM_t_ObjectList_Custom m_BufV7;
  EM_t_ObjectList_Custom_V7_2::EM_t_ObjectList_Custom m_BufV7_2;

  // Initialization
  template <typename T> static void InitVx (T & Dest)
  {
    ::memset(&Dest, 0, sizeof(Dest));
  }

public:

  static const char *GetConverterTypeName()
  {
    return "EMCustomObjectList";
  }

  CConvEmObjectlistCustom(void);
  virtual ~CConvEmObjectlistCustom(void);

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
  enum AVWV_EM_t_ObjectList_Custom
  {
    EMOBJECTLISTCUSTOM_V4,
    EMOBJECTLISTCUSTOM_V5,
    EMOBJECTLISTCUSTOM_V7,
    EMOBJECTLISTCUSTOM_V7_2,
    EMOBJECTLISTCUSTOM_VERSION_COUNT
  };

  static CVersionInfoImpl BASE_VERSION;
  static CVersionInfoImpl VERSION4;
  static CVersionInfoImpl VERSION5;
  static CVersionInfoImpl VERSION7;

  static const CVersionInfoImpl * const EM_OBJECTLIST_CUSTOM_VERSIONS[EMOBJECTLISTCUSTOM_VERSION_COUNT];

  static const unsigned long SUPPORTED_SIZE[EMOBJECTLISTCUSTOM_VERSION_COUNT];

  bool IsPortSupported(unsigned long ulPortSize, const IVersionInfo *pPortVersion) const
  {
    for (int nI = 0; nI < EMOBJECTLISTCUSTOM_VERSION_COUNT; nI++)
    {
      if ((pPortVersion == NULL) || pPortVersion->Equals(EM_OBJECTLIST_CUSTOM_VERSIONS[nI]))
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

CVersionInfoImpl CConvEmObjectlistCustom::BASE_VERSION(0, 0, 0);
CVersionInfoImpl CConvEmObjectlistCustom::VERSION4(0, 0, 4);
CVersionInfoImpl CConvEmObjectlistCustom::VERSION5(0, 0, 5);
CVersionInfoImpl CConvEmObjectlistCustom::VERSION7(0, 0, 7);

const CVersionInfoImpl * const CConvEmObjectlistCustom::EM_OBJECTLIST_CUSTOM_VERSIONS[CConvEmObjectlistCustom::EMOBJECTLISTCUSTOM_VERSION_COUNT] =
{
  &VERSION4,
  &VERSION5,
  &VERSION7,
  &VERSION7
};

const unsigned long CConvEmObjectlistCustom::SUPPORTED_SIZE[CConvEmObjectlistCustom::EMOBJECTLISTCUSTOM_VERSION_COUNT] =
{
  sizeof(EM_t_ObjectList_Custom_V4::EM_t_ObjectList_Custom),
  sizeof(EM_t_ObjectList_Custom_V5::EM_t_ObjectList_Custom),
  sizeof(EM_t_ObjectList_Custom_V7::EM_t_ObjectList_Custom),
  sizeof(EM_t_ObjectList_Custom_V7_2::EM_t_ObjectList_Custom)
};

__inline void v_Convert_v4_to_v5 (EM_t_ObjectList_Custom_V5::EM_t_ObjectList_Custom * const pDest,
  const EM_t_ObjectList_Custom_V4::EM_t_ObjectList_Custom * const pSrc)
{
  pDest->u_VersionNumber = 5u;
  pDest->sSigHeader = pSrc->sSigHeader;
  pDest->project = pSrc->project;
  for (int nI=0; nI<40; nI++)
  {
    pDest->CustObjects[nI].u_ExternalID = pSrc->CustObjects[nI].u_ExternalID;
    pDest->CustObjects[nI].f_LifeTime = pSrc->CustObjects[nI].f_LifeTime;
    pDest->CustObjects[nI].e_MaintenanceState = pSrc->CustObjects[nI].e_MaintenanceState;
    pDest->CustObjects[nI].u_ProbabilityOfExistence = pSrc->CustObjects[nI].u_ProbabilityOfExistence;
    pDest->CustObjects[nI].e_Classification = pSrc->CustObjects[nI].e_Classification;
    pDest->CustObjects[nI].e_DynamicProperty = pSrc->CustObjects[nI].e_DynamicProperty;
    pDest->CustObjects[nI].f_Length = pSrc->CustObjects[nI].f_Length;
    pDest->CustObjects[nI].f_Width = pSrc->CustObjects[nI].f_Width;
    pDest->CustObjects[nI].f_DistX = pSrc->CustObjects[nI].f_DistX;
    pDest->CustObjects[nI].f_DistXStd = pSrc->CustObjects[nI].f_DistXStd;
    pDest->CustObjects[nI].f_DistY = pSrc->CustObjects[nI].f_DistY;
    pDest->CustObjects[nI].f_DistYStd = pSrc->CustObjects[nI].f_DistYStd;
    pDest->CustObjects[nI].f_VrelX = pSrc->CustObjects[nI].f_VrelX;
    pDest->CustObjects[nI].f_VrelXStd = pSrc->CustObjects[nI].f_VrelXStd;
    pDest->CustObjects[nI].f_VrelY = pSrc->CustObjects[nI].f_VrelY;
    pDest->CustObjects[nI].f_VrelYStd = pSrc->CustObjects[nI].f_VrelYStd;
    pDest->CustObjects[nI].f_ArelX = pSrc->CustObjects[nI].f_ArelX;
    pDest->CustObjects[nI].f_ArelXStd = pSrc->CustObjects[nI].f_ArelXStd;
    pDest->CustObjects[nI].f_Orientation = pSrc->CustObjects[nI].f_Orientation;
    pDest->CustObjects[nI].u_ObstacleProbability = pSrc->CustObjects[nI].u_ObstacleProbability;
    pDest->CustObjects[nI].f_PedestrianProbability = pSrc->CustObjects[nI].f_PedestrianProbability;
    pDest->CustObjects[nI].u_MeasuredTargetFrequency = pSrc->CustObjects[nI].u_MeasuredTargetFrequency;
    pDest->CustObjects[nI].f_UpdateQuality = pSrc->CustObjects[nI].f_UpdateQuality;
    pDest->CustObjects[nI].u_PedestrianMicroDoppler = 0u;
    pDest->CustObjects[nI].CamObjectData = pSrc->CustObjects[nI].CamObjectData;
  }
}

__inline void v_Convert_v4_to_v7 (EM_t_ObjectList_Custom_V7::EM_t_ObjectList_Custom * const pDest,
  const EM_t_ObjectList_Custom_V4::EM_t_ObjectList_Custom * const pSrc)
{
  pDest->u_VersionNumber = 7u;
  pDest->sSigHeader = pSrc->sSigHeader;
  pDest->project = pSrc->project;
  for (int nI=0; nI<40; nI++)
  {
    pDest->CustObjects[nI].u_ExternalID                       = pSrc->CustObjects[nI].u_ExternalID;
    pDest->CustObjects[nI].f_LifeTime                         = pSrc->CustObjects[nI].f_LifeTime;
    pDest->CustObjects[nI].e_MaintenanceState                 = pSrc->CustObjects[nI].e_MaintenanceState;
    pDest->CustObjects[nI].u_ProbabilityOfExistence           = pSrc->CustObjects[nI].u_ProbabilityOfExistence;
    pDest->CustObjects[nI].e_Classification                   = pSrc->CustObjects[nI].e_Classification;
    pDest->CustObjects[nI].e_DynamicProperty                  = pSrc->CustObjects[nI].e_DynamicProperty;
    pDest->CustObjects[nI].f_Length                           = pSrc->CustObjects[nI].f_Length;
    pDest->CustObjects[nI].f_Width                            = pSrc->CustObjects[nI].f_Width;
    pDest->CustObjects[nI].f_DistX                            = pSrc->CustObjects[nI].f_DistX;
    pDest->CustObjects[nI].f_DistXStd                         = pSrc->CustObjects[nI].f_DistXStd;
    pDest->CustObjects[nI].f_DistY                            = pSrc->CustObjects[nI].f_DistY;
    pDest->CustObjects[nI].f_DistYStd                         = pSrc->CustObjects[nI].f_DistYStd;
    pDest->CustObjects[nI].f_VrelX                            = pSrc->CustObjects[nI].f_VrelX;
    pDest->CustObjects[nI].f_VrelXStd                         = pSrc->CustObjects[nI].f_VrelXStd;
    pDest->CustObjects[nI].f_VrelY                            = pSrc->CustObjects[nI].f_VrelY;
    pDest->CustObjects[nI].f_VrelYStd                         = pSrc->CustObjects[nI].f_VrelYStd;
    pDest->CustObjects[nI].f_ArelX                            = pSrc->CustObjects[nI].f_ArelX;
    pDest->CustObjects[nI].f_ArelXStd                         = pSrc->CustObjects[nI].f_ArelXStd;
    pDest->CustObjects[nI].f_Orientation                      = pSrc->CustObjects[nI].f_Orientation;
    pDest->CustObjects[nI].u_ObstacleProbability              = pSrc->CustObjects[nI].u_ObstacleProbability;
    pDest->CustObjects[nI].f_PedestrianProbability            = pSrc->CustObjects[nI].f_PedestrianProbability;
    pDest->CustObjects[nI].u_MeasuredTargetFrequency          = pSrc->CustObjects[nI].u_MeasuredTargetFrequency;
    pDest->CustObjects[nI].f_UpdateQuality                    = pSrc->CustObjects[nI].f_UpdateQuality;
    pDest->CustObjects[nI].u_PedestrianMicroDoppler           = 0;
    pDest->CustObjects[nI].CamObjectData.u_CamConf            = pSrc->CustObjects[nI].CamObjectData.u_CamConf;
    pDest->CustObjects[nI].CamObjectData.u_CamID              = pSrc->CustObjects[nI].CamObjectData.u_CamID;
    pDest->CustObjects[nI].CamObjectData.e_CamClass           = pSrc->CustObjects[nI].CamObjectData.e_CamClass;
    pDest->CustObjects[nI].CamObjectData.f_CamDistY           = pSrc->CustObjects[nI].CamObjectData.f_CamDistY;
    pDest->CustObjects[nI].CamObjectData.f_CamDistYStd        = pSrc->CustObjects[nI].CamObjectData.f_CamDistYStd;
    pDest->CustObjects[nI].CamObjectData.f_CamVrelY           = pSrc->CustObjects[nI].CamObjectData.f_CamVrelY;
    pDest->CustObjects[nI].CamObjectData.f_CamVrelYStd        = pSrc->CustObjects[nI].CamObjectData.f_CamVrelYStd;
    pDest->CustObjects[nI].CamObjectData.f_CamWidth           = pSrc->CustObjects[nI].CamObjectData.f_CamWidth;
    pDest->CustObjects[nI].CamObjectData.f_ObjLineCoverAngleL = 0.f;
    pDest->CustObjects[nI].CamObjectData.f_ObjLineCoverAngleR = 0.f;
  }
}

__inline void v_Convert_v4_to_v7_2 (EM_t_ObjectList_Custom_V7_2::EM_t_ObjectList_Custom * const pDest,
  const EM_t_ObjectList_Custom_V4::EM_t_ObjectList_Custom * const pSrc)
{
  pDest->u_VersionNumber = 7u;
  pDest->sSigHeader = pSrc->sSigHeader;
  pDest->project = pSrc->project;
  for (int nI=0; nI<40; nI++)
  {
    pDest->CustObjects[nI].u_ExternalID                       = pSrc->CustObjects[nI].u_ExternalID;
    pDest->CustObjects[nI].f_LifeTime                         = pSrc->CustObjects[nI].f_LifeTime;
    pDest->CustObjects[nI].e_MaintenanceState                 = pSrc->CustObjects[nI].e_MaintenanceState;
    pDest->CustObjects[nI].u_ProbabilityOfExistence           = pSrc->CustObjects[nI].u_ProbabilityOfExistence;
    pDest->CustObjects[nI].e_Classification                   = pSrc->CustObjects[nI].e_Classification;
    pDest->CustObjects[nI].e_DynamicProperty                  = pSrc->CustObjects[nI].e_DynamicProperty;
    pDest->CustObjects[nI].f_Length                           = pSrc->CustObjects[nI].f_Length;
    pDest->CustObjects[nI].f_Width                            = pSrc->CustObjects[nI].f_Width;
    pDest->CustObjects[nI].f_DistX                            = pSrc->CustObjects[nI].f_DistX;
    pDest->CustObjects[nI].f_DistXStd                         = pSrc->CustObjects[nI].f_DistXStd;
    pDest->CustObjects[nI].f_DistY                            = pSrc->CustObjects[nI].f_DistY;
    pDest->CustObjects[nI].f_DistYStd                         = pSrc->CustObjects[nI].f_DistYStd;
    pDest->CustObjects[nI].f_VrelX                            = pSrc->CustObjects[nI].f_VrelX;
    pDest->CustObjects[nI].f_VrelXStd                         = pSrc->CustObjects[nI].f_VrelXStd;
    pDest->CustObjects[nI].f_VrelY                            = pSrc->CustObjects[nI].f_VrelY;
    pDest->CustObjects[nI].f_VrelYStd                         = pSrc->CustObjects[nI].f_VrelYStd;
    pDest->CustObjects[nI].f_ArelX                            = pSrc->CustObjects[nI].f_ArelX;
    pDest->CustObjects[nI].f_ArelXStd                         = pSrc->CustObjects[nI].f_ArelXStd;
    pDest->CustObjects[nI].f_Orientation                      = pSrc->CustObjects[nI].f_Orientation;
    pDest->CustObjects[nI].u_ObstacleProbability              = pSrc->CustObjects[nI].u_ObstacleProbability;
    pDest->CustObjects[nI].f_PedestrianProbability            = pSrc->CustObjects[nI].f_PedestrianProbability;
    pDest->CustObjects[nI].u_MeasuredTargetFrequency          = pSrc->CustObjects[nI].u_MeasuredTargetFrequency;
    pDest->CustObjects[nI].f_UpdateQuality                    = pSrc->CustObjects[nI].f_UpdateQuality;
    pDest->CustObjects[nI].u_PedestrianMicroDoppler           = 0;
    pDest->CustObjects[nI].f_VabsX                            = 0.f;
    pDest->CustObjects[nI].f_VabsY                            = 0.f;
    pDest->CustObjects[nI].f_AabsX                            = 0.f;
    pDest->CustObjects[nI].f_AabsY                            = 0.f;
    pDest->CustObjects[nI].u_EBAObjectQuality                 = 0;
    pDest->CustObjects[nI].u_ObjSafe                          = 0;
    pDest->CustObjects[nI].f_Reserved1                        = 0.f;
    pDest->CustObjects[nI].s_Reserved2                        = 0;
    pDest->CustObjects[nI].CamObjectData.u_CamConf            = pSrc->CustObjects[nI].CamObjectData.u_CamConf;
    pDest->CustObjects[nI].CamObjectData.u_CamID              = pSrc->CustObjects[nI].CamObjectData.u_CamID;
    pDest->CustObjects[nI].CamObjectData.e_CamClass           = pSrc->CustObjects[nI].CamObjectData.e_CamClass;
    pDest->CustObjects[nI].CamObjectData.f_CamDistY           = pSrc->CustObjects[nI].CamObjectData.f_CamDistY;
    pDest->CustObjects[nI].CamObjectData.f_CamDistYStd        = pSrc->CustObjects[nI].CamObjectData.f_CamDistYStd;
    pDest->CustObjects[nI].CamObjectData.f_CamVrelY           = pSrc->CustObjects[nI].CamObjectData.f_CamVrelY;
    pDest->CustObjects[nI].CamObjectData.f_CamVrelYStd        = pSrc->CustObjects[nI].CamObjectData.f_CamVrelYStd;
    pDest->CustObjects[nI].CamObjectData.f_CamWidth           = pSrc->CustObjects[nI].CamObjectData.f_CamWidth;
    pDest->CustObjects[nI].CamObjectData.f_ObjLineCoverAngleL = 0.f;
    pDest->CustObjects[nI].CamObjectData.f_ObjLineCoverAngleR = 0.f;
  }
}

__inline void v_Convert_v5_to_v4 (EM_t_ObjectList_Custom_V4::EM_t_ObjectList_Custom * const pDest,
  const EM_t_ObjectList_Custom_V5::EM_t_ObjectList_Custom * const pSrc)
{
  pDest->u_VersionNumber = 4u;
  pDest->sSigHeader = pSrc->sSigHeader;
  pDest->project = pSrc->project;
  for (int nI=0; nI<40; nI++)
  {
    pDest->CustObjects[nI].u_ExternalID = pSrc->CustObjects[nI].u_ExternalID;
    pDest->CustObjects[nI].f_LifeTime = pSrc->CustObjects[nI].f_LifeTime;
    pDest->CustObjects[nI].e_MaintenanceState = pSrc->CustObjects[nI].e_MaintenanceState;
    pDest->CustObjects[nI].u_ProbabilityOfExistence = pSrc->CustObjects[nI].u_ProbabilityOfExistence;
    pDest->CustObjects[nI].e_Classification = pSrc->CustObjects[nI].e_Classification;
    pDest->CustObjects[nI].e_DynamicProperty = pSrc->CustObjects[nI].e_DynamicProperty;
    pDest->CustObjects[nI].f_Length = pSrc->CustObjects[nI].f_Length;
    pDest->CustObjects[nI].f_Width = pSrc->CustObjects[nI].f_Width;
    pDest->CustObjects[nI].f_DistX = pSrc->CustObjects[nI].f_DistX;
    pDest->CustObjects[nI].f_DistXStd = pSrc->CustObjects[nI].f_DistXStd;
    pDest->CustObjects[nI].f_DistY = pSrc->CustObjects[nI].f_DistY;
    pDest->CustObjects[nI].f_DistYStd = pSrc->CustObjects[nI].f_DistYStd;
    pDest->CustObjects[nI].f_VrelX = pSrc->CustObjects[nI].f_VrelX;
    pDest->CustObjects[nI].f_VrelXStd = pSrc->CustObjects[nI].f_VrelXStd;
    pDest->CustObjects[nI].f_VrelY = pSrc->CustObjects[nI].f_VrelY;
    pDest->CustObjects[nI].f_VrelYStd = pSrc->CustObjects[nI].f_VrelYStd;
    pDest->CustObjects[nI].f_ArelX = pSrc->CustObjects[nI].f_ArelX;
    pDest->CustObjects[nI].f_ArelXStd = pSrc->CustObjects[nI].f_ArelXStd;
    pDest->CustObjects[nI].f_Orientation = pSrc->CustObjects[nI].f_Orientation;
    pDest->CustObjects[nI].u_ObstacleProbability = pSrc->CustObjects[nI].u_ObstacleProbability;
    pDest->CustObjects[nI].f_PedestrianProbability = pSrc->CustObjects[nI].f_PedestrianProbability;
    pDest->CustObjects[nI].u_MeasuredTargetFrequency = pSrc->CustObjects[nI].u_MeasuredTargetFrequency;
    pDest->CustObjects[nI].f_UpdateQuality = pSrc->CustObjects[nI].f_UpdateQuality;
    pDest->CustObjects[nI].CamObjectData = pSrc->CustObjects[nI].CamObjectData;
  }
}

__inline void v_Convert_v5_to_v7 (EM_t_ObjectList_Custom_V7::EM_t_ObjectList_Custom * const pDest,
  const EM_t_ObjectList_Custom_V5::EM_t_ObjectList_Custom * const pSrc)
{
  pDest->u_VersionNumber = 7u;
  pDest->sSigHeader = pSrc->sSigHeader;
  pDest->project = pSrc->project;
  for (int nI=0; nI<40; nI++)
  {
    pDest->CustObjects[nI].u_ExternalID                       = pSrc->CustObjects[nI].u_ExternalID;
    pDest->CustObjects[nI].f_LifeTime                         = pSrc->CustObjects[nI].f_LifeTime;
    pDest->CustObjects[nI].e_MaintenanceState                 = pSrc->CustObjects[nI].e_MaintenanceState;
    pDest->CustObjects[nI].u_ProbabilityOfExistence           = pSrc->CustObjects[nI].u_ProbabilityOfExistence;
    pDest->CustObjects[nI].e_Classification                   = pSrc->CustObjects[nI].e_Classification;
    pDest->CustObjects[nI].e_DynamicProperty                  = pSrc->CustObjects[nI].e_DynamicProperty;
    pDest->CustObjects[nI].f_Length                           = pSrc->CustObjects[nI].f_Length;
    pDest->CustObjects[nI].f_Width                            = pSrc->CustObjects[nI].f_Width;
    pDest->CustObjects[nI].f_DistX                            = pSrc->CustObjects[nI].f_DistX;
    pDest->CustObjects[nI].f_DistXStd                         = pSrc->CustObjects[nI].f_DistXStd;
    pDest->CustObjects[nI].f_DistY                            = pSrc->CustObjects[nI].f_DistY;
    pDest->CustObjects[nI].f_DistYStd                         = pSrc->CustObjects[nI].f_DistYStd;
    pDest->CustObjects[nI].f_VrelX                            = pSrc->CustObjects[nI].f_VrelX;
    pDest->CustObjects[nI].f_VrelXStd                         = pSrc->CustObjects[nI].f_VrelXStd;
    pDest->CustObjects[nI].f_VrelY                            = pSrc->CustObjects[nI].f_VrelY;
    pDest->CustObjects[nI].f_VrelYStd                         = pSrc->CustObjects[nI].f_VrelYStd;
    pDest->CustObjects[nI].f_ArelX                            = pSrc->CustObjects[nI].f_ArelX;
    pDest->CustObjects[nI].f_ArelXStd                         = pSrc->CustObjects[nI].f_ArelXStd;
    pDest->CustObjects[nI].f_Orientation                      = pSrc->CustObjects[nI].f_Orientation;
    pDest->CustObjects[nI].u_ObstacleProbability              = pSrc->CustObjects[nI].u_ObstacleProbability;
    pDest->CustObjects[nI].f_PedestrianProbability            = pSrc->CustObjects[nI].f_PedestrianProbability;
    pDest->CustObjects[nI].u_MeasuredTargetFrequency          = pSrc->CustObjects[nI].u_MeasuredTargetFrequency;
    pDest->CustObjects[nI].f_UpdateQuality                    = pSrc->CustObjects[nI].f_UpdateQuality;
    pDest->CustObjects[nI].u_PedestrianMicroDoppler           = pSrc->CustObjects[nI].u_PedestrianMicroDoppler;
    pDest->CustObjects[nI].CamObjectData.u_CamConf            = pSrc->CustObjects[nI].CamObjectData.u_CamConf;
    pDest->CustObjects[nI].CamObjectData.u_CamID              = pSrc->CustObjects[nI].CamObjectData.u_CamID;
    pDest->CustObjects[nI].CamObjectData.e_CamClass           = pSrc->CustObjects[nI].CamObjectData.e_CamClass;
    pDest->CustObjects[nI].CamObjectData.f_CamDistY           = pSrc->CustObjects[nI].CamObjectData.f_CamDistY;
    pDest->CustObjects[nI].CamObjectData.f_CamDistYStd        = pSrc->CustObjects[nI].CamObjectData.f_CamDistYStd;
    pDest->CustObjects[nI].CamObjectData.f_CamVrelY           = pSrc->CustObjects[nI].CamObjectData.f_CamVrelY;
    pDest->CustObjects[nI].CamObjectData.f_CamVrelYStd        = pSrc->CustObjects[nI].CamObjectData.f_CamVrelYStd;
    pDest->CustObjects[nI].CamObjectData.f_CamWidth           = pSrc->CustObjects[nI].CamObjectData.f_CamWidth;
    pDest->CustObjects[nI].CamObjectData.f_ObjLineCoverAngleL = 0.f;
    pDest->CustObjects[nI].CamObjectData.f_ObjLineCoverAngleR = 0.f;
  }
}

__inline void v_Convert_v5_to_v7_2 (EM_t_ObjectList_Custom_V7_2::EM_t_ObjectList_Custom * const pDest,
  const EM_t_ObjectList_Custom_V5::EM_t_ObjectList_Custom * const pSrc)
{
  pDest->u_VersionNumber = 7u;
  pDest->sSigHeader = pSrc->sSigHeader;
  pDest->project = pSrc->project;
  for (int nI=0; nI<40; nI++)
  {
    pDest->CustObjects[nI].u_ExternalID                       = pSrc->CustObjects[nI].u_ExternalID;
    pDest->CustObjects[nI].f_LifeTime                         = pSrc->CustObjects[nI].f_LifeTime;
    pDest->CustObjects[nI].e_MaintenanceState                 = pSrc->CustObjects[nI].e_MaintenanceState;
    pDest->CustObjects[nI].u_ProbabilityOfExistence           = pSrc->CustObjects[nI].u_ProbabilityOfExistence;
    pDest->CustObjects[nI].e_Classification                   = pSrc->CustObjects[nI].e_Classification;
    pDest->CustObjects[nI].e_DynamicProperty                  = pSrc->CustObjects[nI].e_DynamicProperty;
    pDest->CustObjects[nI].f_Length                           = pSrc->CustObjects[nI].f_Length;
    pDest->CustObjects[nI].f_Width                            = pSrc->CustObjects[nI].f_Width;
    pDest->CustObjects[nI].f_DistX                            = pSrc->CustObjects[nI].f_DistX;
    pDest->CustObjects[nI].f_DistXStd                         = pSrc->CustObjects[nI].f_DistXStd;
    pDest->CustObjects[nI].f_DistY                            = pSrc->CustObjects[nI].f_DistY;
    pDest->CustObjects[nI].f_DistYStd                         = pSrc->CustObjects[nI].f_DistYStd;
    pDest->CustObjects[nI].f_VrelX                            = pSrc->CustObjects[nI].f_VrelX;
    pDest->CustObjects[nI].f_VrelXStd                         = pSrc->CustObjects[nI].f_VrelXStd;
    pDest->CustObjects[nI].f_VrelY                            = pSrc->CustObjects[nI].f_VrelY;
    pDest->CustObjects[nI].f_VrelYStd                         = pSrc->CustObjects[nI].f_VrelYStd;
    pDest->CustObjects[nI].f_ArelX                            = pSrc->CustObjects[nI].f_ArelX;
    pDest->CustObjects[nI].f_ArelXStd                         = pSrc->CustObjects[nI].f_ArelXStd;
    pDest->CustObjects[nI].f_Orientation                      = pSrc->CustObjects[nI].f_Orientation;
    pDest->CustObjects[nI].u_ObstacleProbability              = pSrc->CustObjects[nI].u_ObstacleProbability;
    pDest->CustObjects[nI].f_PedestrianProbability            = pSrc->CustObjects[nI].f_PedestrianProbability;
    pDest->CustObjects[nI].u_MeasuredTargetFrequency          = pSrc->CustObjects[nI].u_MeasuredTargetFrequency;
    pDest->CustObjects[nI].f_UpdateQuality                    = pSrc->CustObjects[nI].f_UpdateQuality;
    pDest->CustObjects[nI].u_PedestrianMicroDoppler           = pSrc->CustObjects[nI].u_PedestrianMicroDoppler;
    pDest->CustObjects[nI].f_VabsX                            = 0.f;
    pDest->CustObjects[nI].f_VabsY                            = 0.f;
    pDest->CustObjects[nI].f_AabsX                            = 0.f;
    pDest->CustObjects[nI].f_AabsY                            = 0.f;
    pDest->CustObjects[nI].u_EBAObjectQuality                 = 0;
    pDest->CustObjects[nI].u_ObjSafe                          = 0;
    pDest->CustObjects[nI].f_Reserved1                        = 0.f;
    pDest->CustObjects[nI].s_Reserved2                        = 0;
    pDest->CustObjects[nI].CamObjectData.u_CamConf            = pSrc->CustObjects[nI].CamObjectData.u_CamConf;
    pDest->CustObjects[nI].CamObjectData.u_CamID              = pSrc->CustObjects[nI].CamObjectData.u_CamID;
    pDest->CustObjects[nI].CamObjectData.e_CamClass           = pSrc->CustObjects[nI].CamObjectData.e_CamClass;
    pDest->CustObjects[nI].CamObjectData.f_CamDistY           = pSrc->CustObjects[nI].CamObjectData.f_CamDistY;
    pDest->CustObjects[nI].CamObjectData.f_CamDistYStd        = pSrc->CustObjects[nI].CamObjectData.f_CamDistYStd;
    pDest->CustObjects[nI].CamObjectData.f_CamVrelY           = pSrc->CustObjects[nI].CamObjectData.f_CamVrelY;
    pDest->CustObjects[nI].CamObjectData.f_CamVrelYStd        = pSrc->CustObjects[nI].CamObjectData.f_CamVrelYStd;
    pDest->CustObjects[nI].CamObjectData.f_CamWidth           = pSrc->CustObjects[nI].CamObjectData.f_CamWidth;
    pDest->CustObjects[nI].CamObjectData.f_ObjLineCoverAngleL = 0.f;
    pDest->CustObjects[nI].CamObjectData.f_ObjLineCoverAngleR = 0.f;
  }
}

__inline void v_Convert_v7_to_v4 (EM_t_ObjectList_Custom_V4::EM_t_ObjectList_Custom * const pDest,
  const EM_t_ObjectList_Custom_V7::EM_t_ObjectList_Custom * const pSrc)
{
  pDest->u_VersionNumber = 7u;
  pDest->sSigHeader = pSrc->sSigHeader;
  pDest->project = pSrc->project;
  for (int nI=0; nI<40; nI++)
  {
    pDest->CustObjects[nI].u_ExternalID                       = pSrc->CustObjects[nI].u_ExternalID;
    pDest->CustObjects[nI].f_LifeTime                         = pSrc->CustObjects[nI].f_LifeTime;
    pDest->CustObjects[nI].e_MaintenanceState                 = pSrc->CustObjects[nI].e_MaintenanceState;
    pDest->CustObjects[nI].u_ProbabilityOfExistence           = pSrc->CustObjects[nI].u_ProbabilityOfExistence;
    pDest->CustObjects[nI].e_Classification                   = pSrc->CustObjects[nI].e_Classification;
    pDest->CustObjects[nI].e_DynamicProperty                  = pSrc->CustObjects[nI].e_DynamicProperty;
    pDest->CustObjects[nI].f_Length                           = pSrc->CustObjects[nI].f_Length;
    pDest->CustObjects[nI].f_Width                            = pSrc->CustObjects[nI].f_Width;
    pDest->CustObjects[nI].f_DistX                            = pSrc->CustObjects[nI].f_DistX;
    pDest->CustObjects[nI].f_DistXStd                         = pSrc->CustObjects[nI].f_DistXStd;
    pDest->CustObjects[nI].f_DistY                            = pSrc->CustObjects[nI].f_DistY;
    pDest->CustObjects[nI].f_DistYStd                         = pSrc->CustObjects[nI].f_DistYStd;
    pDest->CustObjects[nI].f_VrelX                            = pSrc->CustObjects[nI].f_VrelX;
    pDest->CustObjects[nI].f_VrelXStd                         = pSrc->CustObjects[nI].f_VrelXStd;
    pDest->CustObjects[nI].f_VrelY                            = pSrc->CustObjects[nI].f_VrelY;
    pDest->CustObjects[nI].f_VrelYStd                         = pSrc->CustObjects[nI].f_VrelYStd;
    pDest->CustObjects[nI].f_ArelX                            = pSrc->CustObjects[nI].f_ArelX;
    pDest->CustObjects[nI].f_ArelXStd                         = pSrc->CustObjects[nI].f_ArelXStd;
    pDest->CustObjects[nI].f_Orientation                      = pSrc->CustObjects[nI].f_Orientation;
    pDest->CustObjects[nI].u_ObstacleProbability              = pSrc->CustObjects[nI].u_ObstacleProbability;
    pDest->CustObjects[nI].f_PedestrianProbability            = pSrc->CustObjects[nI].f_PedestrianProbability;
    pDest->CustObjects[nI].u_MeasuredTargetFrequency          = pSrc->CustObjects[nI].u_MeasuredTargetFrequency;
    pDest->CustObjects[nI].f_UpdateQuality                    = pSrc->CustObjects[nI].f_UpdateQuality;
    pDest->CustObjects[nI].CamObjectData.u_CamConf            = pSrc->CustObjects[nI].CamObjectData.u_CamConf;
    pDest->CustObjects[nI].CamObjectData.u_CamID              = pSrc->CustObjects[nI].CamObjectData.u_CamID;
    pDest->CustObjects[nI].CamObjectData.e_CamClass           = pSrc->CustObjects[nI].CamObjectData.e_CamClass;
    pDest->CustObjects[nI].CamObjectData.f_CamDistY           = pSrc->CustObjects[nI].CamObjectData.f_CamDistY;
    pDest->CustObjects[nI].CamObjectData.f_CamDistYStd        = pSrc->CustObjects[nI].CamObjectData.f_CamDistYStd;
    pDest->CustObjects[nI].CamObjectData.f_CamVrelY           = pSrc->CustObjects[nI].CamObjectData.f_CamVrelY;
    pDest->CustObjects[nI].CamObjectData.f_CamVrelYStd        = pSrc->CustObjects[nI].CamObjectData.f_CamVrelYStd;
    pDest->CustObjects[nI].CamObjectData.f_CamWidth           = pSrc->CustObjects[nI].CamObjectData.f_CamWidth;
  }
}

__inline void v_Convert_v7_to_v5 (EM_t_ObjectList_Custom_V5::EM_t_ObjectList_Custom * const pDest,
  const EM_t_ObjectList_Custom_V7::EM_t_ObjectList_Custom * const pSrc)
{
  pDest->u_VersionNumber = 7u;
  pDest->sSigHeader = pSrc->sSigHeader;
  pDest->project = pSrc->project;
  for (int nI=0; nI<40; nI++)
  {
    pDest->CustObjects[nI].u_ExternalID                       = pSrc->CustObjects[nI].u_ExternalID;
    pDest->CustObjects[nI].f_LifeTime                         = pSrc->CustObjects[nI].f_LifeTime;
    pDest->CustObjects[nI].e_MaintenanceState                 = pSrc->CustObjects[nI].e_MaintenanceState;
    pDest->CustObjects[nI].u_ProbabilityOfExistence           = pSrc->CustObjects[nI].u_ProbabilityOfExistence;
    pDest->CustObjects[nI].e_Classification                   = pSrc->CustObjects[nI].e_Classification;
    pDest->CustObjects[nI].e_DynamicProperty                  = pSrc->CustObjects[nI].e_DynamicProperty;
    pDest->CustObjects[nI].f_Length                           = pSrc->CustObjects[nI].f_Length;
    pDest->CustObjects[nI].f_Width                            = pSrc->CustObjects[nI].f_Width;
    pDest->CustObjects[nI].f_DistX                            = pSrc->CustObjects[nI].f_DistX;
    pDest->CustObjects[nI].f_DistXStd                         = pSrc->CustObjects[nI].f_DistXStd;
    pDest->CustObjects[nI].f_DistY                            = pSrc->CustObjects[nI].f_DistY;
    pDest->CustObjects[nI].f_DistYStd                         = pSrc->CustObjects[nI].f_DistYStd;
    pDest->CustObjects[nI].f_VrelX                            = pSrc->CustObjects[nI].f_VrelX;
    pDest->CustObjects[nI].f_VrelXStd                         = pSrc->CustObjects[nI].f_VrelXStd;
    pDest->CustObjects[nI].f_VrelY                            = pSrc->CustObjects[nI].f_VrelY;
    pDest->CustObjects[nI].f_VrelYStd                         = pSrc->CustObjects[nI].f_VrelYStd;
    pDest->CustObjects[nI].f_ArelX                            = pSrc->CustObjects[nI].f_ArelX;
    pDest->CustObjects[nI].f_ArelXStd                         = pSrc->CustObjects[nI].f_ArelXStd;
    pDest->CustObjects[nI].f_Orientation                      = pSrc->CustObjects[nI].f_Orientation;
    pDest->CustObjects[nI].u_ObstacleProbability              = pSrc->CustObjects[nI].u_ObstacleProbability;
    pDest->CustObjects[nI].f_PedestrianProbability            = pSrc->CustObjects[nI].f_PedestrianProbability;
    pDest->CustObjects[nI].u_MeasuredTargetFrequency          = pSrc->CustObjects[nI].u_MeasuredTargetFrequency;
    pDest->CustObjects[nI].f_UpdateQuality                    = pSrc->CustObjects[nI].f_UpdateQuality;
    pDest->CustObjects[nI].u_PedestrianMicroDoppler           = pSrc->CustObjects[nI].u_PedestrianMicroDoppler;
    pDest->CustObjects[nI].CamObjectData.u_CamConf            = pSrc->CustObjects[nI].CamObjectData.u_CamConf;
    pDest->CustObjects[nI].CamObjectData.u_CamID              = pSrc->CustObjects[nI].CamObjectData.u_CamID;
    pDest->CustObjects[nI].CamObjectData.e_CamClass           = pSrc->CustObjects[nI].CamObjectData.e_CamClass;
    pDest->CustObjects[nI].CamObjectData.f_CamDistY           = pSrc->CustObjects[nI].CamObjectData.f_CamDistY;
    pDest->CustObjects[nI].CamObjectData.f_CamDistYStd        = pSrc->CustObjects[nI].CamObjectData.f_CamDistYStd;
    pDest->CustObjects[nI].CamObjectData.f_CamVrelY           = pSrc->CustObjects[nI].CamObjectData.f_CamVrelY;
    pDest->CustObjects[nI].CamObjectData.f_CamVrelYStd        = pSrc->CustObjects[nI].CamObjectData.f_CamVrelYStd;
    pDest->CustObjects[nI].CamObjectData.f_CamWidth           = pSrc->CustObjects[nI].CamObjectData.f_CamWidth;
  }
}

__inline void v_Convert_v7_to_v7_2 (EM_t_ObjectList_Custom_V7_2::EM_t_ObjectList_Custom * const pDest,
  const EM_t_ObjectList_Custom_V7::EM_t_ObjectList_Custom * const pSrc)
{
  pDest->u_VersionNumber = 7u;
  pDest->sSigHeader = pSrc->sSigHeader;
  pDest->project = pSrc->project;
  for (int nI=0; nI<40; nI++)
  {
    pDest->CustObjects[nI].u_ExternalID                       = pSrc->CustObjects[nI].u_ExternalID;
    pDest->CustObjects[nI].f_LifeTime                         = pSrc->CustObjects[nI].f_LifeTime;
    pDest->CustObjects[nI].e_MaintenanceState                 = pSrc->CustObjects[nI].e_MaintenanceState;
    pDest->CustObjects[nI].u_ProbabilityOfExistence           = pSrc->CustObjects[nI].u_ProbabilityOfExistence;
    pDest->CustObjects[nI].e_Classification                   = pSrc->CustObjects[nI].e_Classification;
    pDest->CustObjects[nI].e_DynamicProperty                  = pSrc->CustObjects[nI].e_DynamicProperty;
    pDest->CustObjects[nI].f_Length                           = pSrc->CustObjects[nI].f_Length;
    pDest->CustObjects[nI].f_Width                            = pSrc->CustObjects[nI].f_Width;
    pDest->CustObjects[nI].f_DistX                            = pSrc->CustObjects[nI].f_DistX;
    pDest->CustObjects[nI].f_DistXStd                         = pSrc->CustObjects[nI].f_DistXStd;
    pDest->CustObjects[nI].f_DistY                            = pSrc->CustObjects[nI].f_DistY;
    pDest->CustObjects[nI].f_DistYStd                         = pSrc->CustObjects[nI].f_DistYStd;
    pDest->CustObjects[nI].f_VrelX                            = pSrc->CustObjects[nI].f_VrelX;
    pDest->CustObjects[nI].f_VrelXStd                         = pSrc->CustObjects[nI].f_VrelXStd;
    pDest->CustObjects[nI].f_VrelY                            = pSrc->CustObjects[nI].f_VrelY;
    pDest->CustObjects[nI].f_VrelYStd                         = pSrc->CustObjects[nI].f_VrelYStd;
    pDest->CustObjects[nI].f_ArelX                            = pSrc->CustObjects[nI].f_ArelX;
    pDest->CustObjects[nI].f_ArelXStd                         = pSrc->CustObjects[nI].f_ArelXStd;
    pDest->CustObjects[nI].f_Orientation                      = pSrc->CustObjects[nI].f_Orientation;
    pDest->CustObjects[nI].u_ObstacleProbability              = pSrc->CustObjects[nI].u_ObstacleProbability;
    pDest->CustObjects[nI].f_PedestrianProbability            = pSrc->CustObjects[nI].f_PedestrianProbability;
    pDest->CustObjects[nI].u_MeasuredTargetFrequency          = pSrc->CustObjects[nI].u_MeasuredTargetFrequency;
    pDest->CustObjects[nI].f_UpdateQuality                    = pSrc->CustObjects[nI].f_UpdateQuality;
    pDest->CustObjects[nI].u_PedestrianMicroDoppler           = pSrc->CustObjects[nI].u_PedestrianMicroDoppler;
    pDest->CustObjects[nI].f_VabsX                            = 0.f;
    pDest->CustObjects[nI].f_VabsY                            = 0.f;
    pDest->CustObjects[nI].f_AabsX                            = 0.f;
    pDest->CustObjects[nI].f_AabsY                            = 0.f;
    pDest->CustObjects[nI].u_EBAObjectQuality                 = 0;
    pDest->CustObjects[nI].u_ObjSafe                          = 0;
    pDest->CustObjects[nI].f_Reserved1                        = 0.f;
    pDest->CustObjects[nI].s_Reserved2                        = 0;
    pDest->CustObjects[nI].CamObjectData                      = pSrc->CustObjects[nI].CamObjectData;
  }
}

CConvEmObjectlistCustom::CConvEmObjectlistCustom(void) : CSimConverterBase(NULL/*DEP_NAMES*/, DEP_COUNT), m_BufV4(), m_BufV5(), m_BufV7(), m_BufV7_2()
{
  InitVx(m_BufV4);
  InitVx(m_BufV5);
  InitVx(m_BufV7);
  InitVx(m_BufV7_2);
}

CConvEmObjectlistCustom::~CConvEmObjectlistCustom(void)
{
}

long CConvEmObjectlistCustom::ConvertData(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
  SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo *pProvidePortVersionInfo,
  void *pPPortData,
  void **pOutData, unsigned long &ulOutSize)
{
  long lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
  //const unsigned int uDataVer = ((pPPortData != NULL) && (ulPPortSize >= 4) && (ePPortType == simOPAQUE_t))?(*reinterpret_cast<unsigned int*>(pPPortData)):(0);

  if (eRPortType == ePPortType)
  {
    if ((ulRPortSize == ulPPortSize) /*&& ((pProvidePortVersionInfo == NULL) || requestPortVersionInfo.Equals(pProvidePortVersionInfo))*/)
    {
      // Use data directly from provide port
      lRet = SIM_ERR_USE_VALUE_FROM_PPORT;
    }
    else
    {
      // First decide which version we are converting from
      if ((ulPPortSize == SUPPORTED_SIZE[EMOBJECTLISTCUSTOM_V7]) &&
        ((pProvidePortVersionInfo == NULL) || pProvidePortVersionInfo->Equals(EM_OBJECTLIST_CUSTOM_VERSIONS[EMOBJECTLISTCUSTOM_V7])))
      {
        const EM_t_ObjectList_Custom_V7::EM_t_ObjectList_Custom *pSrc = reinterpret_cast<EM_t_ObjectList_Custom_V7::EM_t_ObjectList_Custom *>(pPPortData);
        // Then decide which version we are converting to
        if ((ulRPortSize == SUPPORTED_SIZE[EMOBJECTLISTCUSTOM_V7_2]) &&
          (requestPortVersionInfo.Equals(EM_OBJECTLIST_CUSTOM_VERSIONS[EMOBJECTLISTCUSTOM_V7_2])))
        {
          // Destination port of V7_2 is m_BufV7_2
          v_Convert_v7_to_v7_2(&m_BufV7_2, pSrc);
          *pOutData = &m_BufV7_2;
          ulOutSize = sizeof(m_BufV7_2);
          lRet = SIM_ERR_OK;
        }
        else if ((ulRPortSize == SUPPORTED_SIZE[EMOBJECTLISTCUSTOM_V5]) &&
          (requestPortVersionInfo.Equals(EM_OBJECTLIST_CUSTOM_VERSIONS[EMOBJECTLISTCUSTOM_V5])))
        {
          // Destination port of V5 is m_BufV5
          v_Convert_v7_to_v5(&m_BufV5, pSrc);
          *pOutData = &m_BufV5;
          ulOutSize = sizeof(m_BufV5);
          lRet = SIM_ERR_OK;
        }
        else if ((ulRPortSize == SUPPORTED_SIZE[EMOBJECTLISTCUSTOM_V4]) &&
          (requestPortVersionInfo.Equals(EM_OBJECTLIST_CUSTOM_VERSIONS[EMOBJECTLISTCUSTOM_V4])))
        {
          // Destination port of V4 is m_BufV4
          v_Convert_v7_to_v4(&m_BufV4, pSrc);
          *pOutData = &m_BufV4;
          ulOutSize = sizeof(m_BufV4);
          lRet = SIM_ERR_OK;
        }
      }
      else if ((ulPPortSize == SUPPORTED_SIZE[EMOBJECTLISTCUSTOM_V5]) &&
        ((pProvidePortVersionInfo == NULL) || pProvidePortVersionInfo->Equals(EM_OBJECTLIST_CUSTOM_VERSIONS[EMOBJECTLISTCUSTOM_V5])))
      {
        const EM_t_ObjectList_Custom_V5::EM_t_ObjectList_Custom *pSrc = reinterpret_cast<EM_t_ObjectList_Custom_V5::EM_t_ObjectList_Custom *>(pPPortData);
        // Then decide which version we are converting to
        if ((ulRPortSize == SUPPORTED_SIZE[EMOBJECTLISTCUSTOM_V7_2]) &&
          (requestPortVersionInfo.Equals(EM_OBJECTLIST_CUSTOM_VERSIONS[EMOBJECTLISTCUSTOM_V7_2])))
        {
          // Destination port of V7_2 is m_BufV7_2
          v_Convert_v5_to_v7_2(&m_BufV7_2, pSrc);
          *pOutData = &m_BufV7_2;
          ulOutSize = sizeof(m_BufV7_2);
          lRet = SIM_ERR_OK;
        }
        else if ((ulRPortSize == SUPPORTED_SIZE[EMOBJECTLISTCUSTOM_V7]) &&
          (requestPortVersionInfo.Equals(EM_OBJECTLIST_CUSTOM_VERSIONS[EMOBJECTLISTCUSTOM_V7])))
        {
          // Destination port of V7 is m_BufV7
          v_Convert_v5_to_v7(&m_BufV7, pSrc);
          *pOutData = &m_BufV7;
          ulOutSize = sizeof(m_BufV7);
          lRet = SIM_ERR_OK;
        }
        else if ((ulRPortSize == SUPPORTED_SIZE[EMOBJECTLISTCUSTOM_V4]) &&
          (requestPortVersionInfo.Equals(EM_OBJECTLIST_CUSTOM_VERSIONS[EMOBJECTLISTCUSTOM_V4])))
        {
          // Destination port of V4 is m_BufV4
          v_Convert_v5_to_v4(&m_BufV4, pSrc);
          *pOutData = &m_BufV4;
          ulOutSize = sizeof(m_BufV4);
          lRet = SIM_ERR_OK;
        }
      }
      else if ((ulPPortSize == SUPPORTED_SIZE[EMOBJECTLISTCUSTOM_V4]) &&
        ((pProvidePortVersionInfo == NULL) || pProvidePortVersionInfo->Equals(EM_OBJECTLIST_CUSTOM_VERSIONS[EMOBJECTLISTCUSTOM_V4])))
      {
        const EM_t_ObjectList_Custom_V4::EM_t_ObjectList_Custom *pSrc = reinterpret_cast<EM_t_ObjectList_Custom_V4::EM_t_ObjectList_Custom *>(pPPortData);
        // Then decide which version we are converting to
        if ((ulRPortSize == SUPPORTED_SIZE[EMOBJECTLISTCUSTOM_V7_2]) &&
          (requestPortVersionInfo.Equals(EM_OBJECTLIST_CUSTOM_VERSIONS[EMOBJECTLISTCUSTOM_V7_2])))
        {
          // Destination port of V7 is m_BufV7
          v_Convert_v4_to_v7_2(&m_BufV7_2, pSrc);
          *pOutData = &m_BufV7_2;
          ulOutSize = sizeof(m_BufV7_2);
          lRet = SIM_ERR_OK;
        }
        else if ((ulRPortSize == SUPPORTED_SIZE[EMOBJECTLISTCUSTOM_V7]) &&
          (requestPortVersionInfo.Equals(EM_OBJECTLIST_CUSTOM_VERSIONS[EMOBJECTLISTCUSTOM_V7])))
        {
          // Destination port of V7 is m_BufV7
          v_Convert_v4_to_v7(&m_BufV7, pSrc);
          *pOutData = &m_BufV7;
          ulOutSize = sizeof(m_BufV7);
          lRet = SIM_ERR_OK;
        }
        else if ((ulRPortSize == SUPPORTED_SIZE[EMOBJECTLISTCUSTOM_V5]) &&
          (requestPortVersionInfo.Equals(EM_OBJECTLIST_CUSTOM_VERSIONS[EMOBJECTLISTCUSTOM_V5])))
        {
          // Destination port of V5 is m_BufV5
          v_Convert_v4_to_v5(&m_BufV5, pSrc);
          *pOutData = &m_BufV5;
          ulOutSize = sizeof(m_BufV5);
          lRet = SIM_ERR_OK;
        }
      }
    }
  }
  return lRet;
}

/** returns:
 *   SIM_ERR_OK - when this value can be used
 *   SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT - when the default vaule is not implememnted here
 *                                            and the default value from Request Port must be used
 */
long CConvEmObjectlistCustom::GetDefaultValue(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
  void **pDefaultData, unsigned long &ulDefaultSize)
{
  long lRet = SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT;
  if (eRPortType == simOPAQUE_t)
  {
    if ((ulRPortSize == SUPPORTED_SIZE[EMOBJECTLISTCUSTOM_V7_2]) && requestPortVersionInfo.Equals(EM_OBJECTLIST_CUSTOM_VERSIONS[EMOBJECTLISTCUSTOM_V7]))
    {
      InitVx(m_BufV7_2);
      *pDefaultData = &m_BufV7_2;
      ulDefaultSize = SUPPORTED_SIZE[EMOBJECTLISTCUSTOM_V7_2];
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == SUPPORTED_SIZE[EMOBJECTLISTCUSTOM_V7]) && requestPortVersionInfo.Equals(EM_OBJECTLIST_CUSTOM_VERSIONS[EMOBJECTLISTCUSTOM_V7]))
    {
      InitVx(m_BufV7);
      *pDefaultData = &m_BufV7;
      ulDefaultSize = SUPPORTED_SIZE[EMOBJECTLISTCUSTOM_V7];
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == SUPPORTED_SIZE[EMOBJECTLISTCUSTOM_V5]) && requestPortVersionInfo.Equals(EM_OBJECTLIST_CUSTOM_VERSIONS[EMOBJECTLISTCUSTOM_V5]))
    {
      InitVx(m_BufV5);
      *pDefaultData = &m_BufV5;
      ulDefaultSize = SUPPORTED_SIZE[EMOBJECTLISTCUSTOM_V5];
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == SUPPORTED_SIZE[EMOBJECTLISTCUSTOM_V4])/* && requestPortVersionInfo.Equals(EM_OBJECTLIST_CUSTOM_VERSIONS[EMOBJECTLISTCUSTOM_V4])*/)
    {
      InitVx(m_BufV4);
      *pDefaultData = &m_BufV4;
      ulDefaultSize = SUPPORTED_SIZE[EMOBJECTLISTCUSTOM_V4];
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
bool CConvEmObjectlistCustom::IsVersionCompatibleWithType(
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
  return bResult;
}

// used to check if ports are compatible between different versions
bool CConvEmObjectlistCustom::AreVersionsCompatible(
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
  return bResult;
}

//
// Main factory class returning conversion class
//
IConverter *CreateEmObjectlistCustomConvClass(void)
{
  return new CConvEmObjectlistCustom();
}
