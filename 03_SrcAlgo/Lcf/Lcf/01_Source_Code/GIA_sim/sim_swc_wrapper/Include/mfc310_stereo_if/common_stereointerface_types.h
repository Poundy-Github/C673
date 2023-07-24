/*! \file **********************************************************************

COMPANY:        Continental AG

PROJECT:        MFC300

CPU:            

COMPONENT:      CCT - Common Camera Toolbox

MODULNAME:      common_stereo_interface_types.h

DESCRIPTION:    Common Stereo Interface Types

AUTHOR:         M. Friebertshaeuser, N. Stache, J. Spruck

CREATION DATE:  28.10.2011

VERSION:        $Revision: 1.1 $

CHANGES:        $Log: common_stereointerface_types.h  $
CHANGES:        Revision 1.1 2021/12/13 17:26:24CET Wang, David (Wangd3) 
CHANGES:        Initial revision
CHANGES:        Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310_stereo_if/project.pj
CHANGES:        Revision 1.0 2017/03/03 10:37:28CET Sorge, Sven (uidg3181) 
CHANGES:        Initial revision
CHANGES:        Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310_stereo_if/project.pj
CHANGES:        Revision 1.2 2014/04/01 10:50:06CEST Sorge, Sven (uidg3181) 
CHANGES:        Removed Enums
CHANGES:        - Added comments -  uidg3181 [Apr 1, 2014 10:50:06 AM CEST]
CHANGES:        Change Package : 217703:2 http://mks-psad:7002/im/viewissue?selection=217703
CHANGES:        Revision 1.1 2014/03/13 15:12:57CET Sorge-EXT, Sven (uidg3181) 
CHANGES:        Initial revision
CHANGES:        Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310_stereo_if/project.pj
CHANGES:        Revision 1.9 2012/05/04 09:57:33CEST Garcia, Lucien (uid26778) 
CHANGES:        Remove pc-lint
CHANGES:        --- Added comments ---  uid26778 [May 4, 2012 9:57:33 AM CEST]
CHANGES:        Change Package : 80273:1 http://mks-psad:7002/im/viewissue?selection=80273
CHANGES:        Revision 1.8 2012/02/09 13:38:31CET Exner, Christian (uidt8578) 
CHANGES:        - renamed typedef SPODObjectList_t -> CCT_SPODObjectList_t and the according struct name and the version number constant
CHANGES:        --- Added comments ---  uidt8578 [Feb 9, 2012 1:38:31 PM CET]
CHANGES:        Change Package : 90232:1 http://mks-psad:7002/im/viewissue?selection=90232
CHANGES:        Revision 1.7 2012/02/02 09:10:06CET Spruck, Jochen (spruckj) 
CHANGES:        Update calib interface
CHANGES:        --- Added comments ---  spruckj [Feb 2, 2012 9:10:08 AM CET]
CHANGES:        Change Package : 86836:2 http://mks-psad:7002/im/viewissue?selection=86836
CHANGES:        Revision 1.6 2011/11/25 19:06:41CET Stache Nicolaj (uidt6711) (uidt6711) 
CHANGES:        update
CHANGES:        --- Added comments ---  uidt6711 [Nov 25, 2011 7:06:41 PM CET]
CHANGES:        Change Package : 67326:3 http://mks-psad:7002/im/viewissue?selection=67326
CHANGES:        Revision 1.5 2011/11/25 15:01:30CET Garcia, Lucien (uid26778) 
CHANGES:        Split LUT generation in 2 frames (runtime improvement)
CHANGES:        --- Added comments ---  uid26778 [Nov 25, 2011 3:01:30 PM CET]
CHANGES:        Change Package : 87584:1 http://mks-psad:7002/im/viewissue?selection=87584
CHANGES:        Revision 1.4 2011/11/16 14:13:38CET Wagner Ulrich (uid04769) (uid04769) 
CHANGES:        Bugfixed compile-error
CHANGES:        --- Added comments ---  uid04769 [Nov 16, 2011 2:13:38 PM CET]
CHANGES:        Change Package : 64593:1 http://mks-psad:7002/im/viewissue?selection=64593
CHANGES:        Revision 1.3 2011/11/16 11:33:01CET Spruck Jochen (spruckj) (spruckj) 
CHANGES:        Rename SFODObjectList version number to CCT_SFODObjectList_VersionNumber
CHANGES:        --- Added comments ---  spruckj [Nov 16, 2011 11:33:01 AM CET]
CHANGES:        Change Package : 86836:2 http://mks-psad:7002/im/viewissue?selection=86836
CHANGES:        Revision 1.2 2011/11/15 18:41:18CET Spruck Jochen (spruckj) (spruckj) 
CHANGES:        Rename SFODObjectList to CCT_SFODObjectList
CHANGES:        --- Added comments ---  spruckj [Nov 15, 2011 6:41:18 PM CET]
CHANGES:        Change Package : 86836:2 http://mks-psad:7002/im/viewissue?selection=86836
CHANGES:        Revision 1.1 2011/11/04 12:20:33CET Spruck Jochen (spruckj) (spruckj) 
CHANGES:        Initial revision
CHANGES:        Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/SAC_StereoAutoCalibration/04_Engineering/01_Source_Code/common/project.pj

**************************************************************************** */

#ifndef COMMON_STEREO_INTERFACE_TYPES_H__
#define COMMON_STEREO_INTERFACE_TYPES_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "cct_base_type.h"
#include "common_interface_defines.h"


/*------------  The CalibrationData interface -----------------*/
static const ui32_t CalibrationData_VersionNumber = 1;

typedef struct // _CalibrationData 
{
  DEFINE_VERSION_MEMBER(CalibrationData);

  Algo64DataTimeStamp_t Timestamp_usec;  /*!< Microsec Timestamp from when the calibration has been carried out, corresponding framecounter*/
  AlgoFrameCounter_t    FrameCounter;    /*!< Actuall frame counter */
  AlgoSignalState_t     SigState;        /*!< valid flag */

  // Extrinsic Camera Parameters
  fDistance_t PositionX;  /*!< X-position of camera in meters */
  fDistance_t PositionY;  /*!< Y-position of camera in meters */
  fDistance_t PositionZ;  /*!< Z-position of camera in meters */
  
  /* rotation from vehicle (AUTOSAR) to camera coordinates
  rotation order: X(Roll) --> Y(Pitch) --> Z(Yaw)
  right handed, image rows coincie with x-axis, columns with y-axis, z to optical axis */
  mat3_t RotMat; /*!< Corresponding rotation matrix */

  fAngle_t fRoll;  /* Roll angle  */
  fAngle_t fPitch; /* Pitch angle */
  fAngle_t fYaw;   /* Yaw angle   */

  /* rectified data Intrinsic Calibration Data */
  fPixel_t    CenterX;    /*!< X-coordinate of camera center point in image [pixel] */
  fPixel_t    CenterY;    /*!< Y-coordinate of camera center point in image [pixel] */
  fPixel_t    FocalX;     /*!< camera X-coordinate focal length [pixel] */
  fPixel_t    FocalY;     /*!< camera Y-coordinate focal length [pixel] */
  fDistance_t Baseline_m; /*!< camera stereo baseline [m] */

  ParameterID_t ParameterIdRectPars;    /*!< identifier for rectified images which belong to this parameter set, the corresponding LUTs have the same parameter ID */

} CalibrationData_t;

/* pdo meas freeze defines for SAC component */
//#ifdef __PDO__
//#define SAC_MEAS_ID_CALIBRATION_DATA
///*! @vaddr:SAC_MEAS_ID_CALIBRATION_DATA @cycleid:SAC_CYCLE @vname: SACCalibrationData  */
//typedef CalibrationData_t PDO_CalibrationData;
//#endif

/*------------  The Object interface -----------------*/

/* Object of interest enumeration @min: -1 @max:5 */
//typedef enum
//{
//  OBJ_NOT_OOI             = -1,
//  OBJ_NEXT_OOI            = 0,
//  OBJ_HIDDEN_NEXT_OOI     = 1,
//  OBJ_NEXT_LONG_LEFT_OOI  = 2,
//  OBJ_NEXT_LONG_RIGHT_OOI = 3,
//  OBJ_NEXT_LAT_LEFT_OOI   = 4,
//  OBJ_NEXT_LAT_RIGHT_OOI  = 5
//} eObjOOI_t;

/* This signal indicates wether the object is moving, stationary or oncoming, based on comparison of the longitudinal relative velocity with the host vehicle velocity. @min: 0 @max:2 */
typedef enum
{
  OBJECT_PROPERTY_ONCOMING   = 2,
  OBJECT_PROPERTY_STATIONARY = 1,
  OBJECT_PROPERTY_MOVING    =0
} eDynamicProperty_t;

/* This signal indicates wether the object is moving, stationary or stopped over ground, based on the absolute object velocity (independent on ist orientation). @min: 0 @max:2 */
typedef enum
{
  OBJECT_MOVSTATE_STOPPED    = 1,
  OBJECT_MOVSTATE_STATIONARY = 0,
  OBJECT_MOVSTATE_MOVING     = 2
} eAbsMovingState_t;

/* This signal indicates the class of the object.Optimizes for ACC function. Classification limitation especially for pedestrians and bicycles @min: 0 @max:7 */
typedef enum
{
  OBJCLASS_POINT        = 0,
  OBJCLASS_CAR          = 1,
  OBJCLASS_TRUCK        = 2,
  OBJCLASS_PEDESTRIAN   = 3,
  OBJCLASS_MOTORCYCLE   = 4,
  OBJCLASS_BICYCLE      = 5,
  OBJCLASS_WIDE         = 6,
  OBJCLASS_UNCLASSIFIED = 7
} eClassification_t;

/* Indicate the adminstration state of object @min: 0 @max:5 */
typedef enum
{
  MT_STATE_DELETED      = 0,
  MT_STATE_NEW          = 1,
  MT_STATE_MEASURED     = 2,
  MT_STATE_PREDICTED    = 3,
  MT_STATE_MERGE_DELETED= 4,
  MT_STATE_MERGE_NEW    = 5
} eObjMaintenanceState_t;

/* Differs between several kinds of obstacles @min: 0 @max:6 */
typedef enum
{
  OBST_CLASS_UNKNOWN = 0,
  OBST_CLASS_BRIDGE  = 1,
  OBST_CLASS_VEHICLE = 2,
  OBST_CLASS_TRAFFIC_SIGN = 3,
  OBST_CLASS_TUNNEL    = 4,
  OBST_CLASS_GUARDRAIL = 5,
  OBST_CLASS_BUTTJOINT = 6
} eObstacleClass_t;

typedef struct
{
  fDistance_t fDistX;                             /* Longitudinal displacement: Horizontal distance between the front of the host vehicle and the   middle of the rear (front for oncoming traffic) of the object vehicle in longitudinal direction. @min:-250.0 @max:250.0 */
  fStdDev_t   fDistXStd;                          /* Longitudinal displacement standard deviation: Set to negative value (-1.0) if signal not available*/
  fDistance_t fDistY;                             /* Lateral displacement: Horizontal distance between the host vehicle's longitudinal axis and the middle of the rear of the object vehicle in lateral direction. @min:-250.0 @max:250.0 */
  fStdDev_t   fDistYStd;                          /* Lateral displacement standard deviation: Set to negative value (-1.0) if signal not available.*/
  fDistance_t fDistZ;                             /* Vertical displacement: Vertical distance between the host vehicle's lower and upper bound. @min:-25.0 @max:25.0 */
  fStdDev_t   fDistZStd;                          /* Vertical displacement standard deviation: Set to negative value (-1.0) if signal not available. @min:-250.0 @max:250.0 */
  fDistance_t fVrelX;                             /* Relative longitudinal velocity: Difference in longitudinal velocity of the host and the object. This value shall be positive when the object velocity is higher than the host velocity (opening velocity). @min:-128.0 @max:128.0 */
  fStdDev_t   fVrelXStd;                          /* Relative longitudinal velocity variance: Set to negative value (-1.0) if signal not available.*/
  fDistance_t fVrelY;                             /* Relative lateral velocity: Velocity of the object in lateral direction, relative to the host vehicle. This value shall be positive when the object is moving towards the left. @min:-128.0 @max:128.0 */
  fStdDev_t   fVrelYStd;                          /* Relative lateral velocity variance: Set to negative value (-1.0) if signal not available.*/
  fDistance_t fArelX;                             /* Relative longitudinal acceleration: Difference in longitudinal acceleration of the host and the object. This value shall be positive when the object acceleration is higher than the host acceleration. @min:-25.0 @max:25.0 */
  fStdDev_t   fArelXStd;                          /* Relative longitudinal acceleration variance: Set to negative value (-1.0) if signal not available.*/
  fDistance_t fArelY;                             /* Relative lateral acceleration: Acceleration in lateral direction of the object, relative to the host vehicle. This value shall be positive when the object accelerates towards the right. @min:-25.0 @max:25.0 */
  fStdDev_t   fArelYStd;                          /* Relative lateral acceleration variance: Set to negative value (-1.0) if signal not available.*/
} Kinematic_t; /* Kinematic object properties */


typedef struct
{
  Point2D_t  Left;                              /*!< coordinates of leftmost point [m] */
  Point2D_t  Inter;                             /*!< coordinates of intermediate point [m] */
  Point2D_t  Right;                             /*!< coordinates of rightmost point [m] */
} LShape_t;  /* coordinates of points for object representation, Stereo-806, 807 in vehicle coordinates */



typedef struct
{
  fDistance_t fWidth;                             /* Object width (lateral dimension) based on measurement supported by the assumed object width as a function of the object class @min:0.0 @max:40.0 */
  fStdDev_t   fWidthStd;                          /* Object width (lateral dimension) @min:0.0 @max:40.0 */
  fDistance_t fLength;                            /* Object length (longitunal dimension) @min:0.0 @max:40.0 */
  fStdDev_t   fLengthStd;                         /* Object lenght (longitunal dimension) @min:0.0 @max:40.0 */
  fDistance_t fHeight;                            /* Object height (vertical dimension) @min:0.0 @max:40.0 */
  fStdDev_t   fHeightStd;                         /* Object height (vertical dimension) @min:0.0 @max:40.0 */
  fAccel_t    fOrientation;                       /* Motion direction of object relative to ego vehicle */
  fStdDev_t   fOrientationStd;                    /* Standerd deviation of motion direction of object relative to ego vehicle @min:0.0 */
} Geometry_t; /* Object size related properties */

typedef struct
{
  eDynamicProperty_t eDynamicProperty;          /* This signal indicates wether the object is moving, stationary or oncoming, based on comparison of the longitudinal relative velocity with the host vehicle velocity. */
  ui8_t              uiStoppedConfidence;       /* This signal indicates, complemetary to the eDynamicConfidence, that the object was detected moving before, but is stationary now. */
  eAbsMovingState_t  eAbsMovingState;           /* This signal indicates wether the object is moving, stationary or stopped over ground, based on the absolute object velocity (independent on ist orientation). */
  eClassification_t  eClassification;           /* This signal indicates the class of the object. Optimizes for ACC function. Classification limitation especially for pedestrians and bicycles */
  ui8_t              uiClassConfidence;         /* Confidence of estimated object class @min:0.0 @max:1.0 @resolution:0.01 */
  i8_t               cObjectOccluded;           /* object is covered by closer objects in sensing direction */
} Attributes_t; /* Dynamic object properties */

typedef struct
{
  ObjID_t                uiObjectID;            /* The actual Object ID */
  eObjOOI_t              eObjOOI;               /* Object of interest enumeration */
  fTime_t                fLifeTime;             /* Time period in seconds since object creation @min:0.0 */
  Algo64DataTimeStamp_t  fTimeStamp;            /* Last update of object in global time (relative / absolute) @min:-71.45 @max:71.448 @resolution:0.00218166156499291 */
  eObjMaintenanceState_t eObjMaintenanceState;  /* Indicate the adminstration state of object */
  ObjID_t                cObjMergingID;         /* Indicate the adminstration state of object @min:-1.0 @max:40 */
} General_t;  /* Global object properities */

typedef struct
{
  fProbability_t   fProbabilityOfExistence;     /* Likelihood that object is present. Probability that the object is a real object. @min:0.0 @max:1.0 */
  ui8_t            ucObstacleProbability;       /* Likelihood that obstacle is present. Probability that the object is an obstacle and can not be driven under/over. @min:0.0 @max:100.0 */
  eObstacleClass_t eObstacleClass;              /* Differs between several kinds of obstacles */
} Qualifiers_t; /* Charakteristic properties */

typedef struct
{
  Kinematic_t  Kinematic;                       /* Kinematic object properties */
  Geometry_t   Geometry;                        /* Object size related properties */
  Attributes_t Attributes;                      /* Dynamic object properties */
  General_t    General;                         /* Global object properities */
  Qualifiers_t Qualifiers;                      /* Charakteristic properties */
} Objects_t; /* Object list properties */


typedef struct
{
  ObjID_t iNumOfUsedObjects;                      /* Current number of tracked objects @min:0.0 @max:40 */
} HeaderObjList_t; /* Header Object list properties */

/*------------  The ObjectList interface(s) -----------------*/

/*------------  SFOD ObjectList -----------------*/
#define         NUMBER_OF_SFOD_OBJECTS         (14U)

static const ui32_t CCT_SFODObjectList_VersionNumber = 1;

typedef struct _SFODObjectList
{
  DEFINE_VERSION_MEMBER(CCT_SFODObjectList);
  Algo64DataTimeStamp_t Timestamp_usec;             /*!< Microsec Timestamp of the SFOD object list*/
  AlgoFrameCounter_t    FrameCounter;               /*!< Actuall frame counter */
  AlgoSignalState_t     SigState;                   /*!< valid flag */

  HeaderObjList_t HeaderObjList;                    /*!< Header Object list properties */
  Objects_t       Objects[NUMBER_OF_SFOD_OBJECTS];  /*!< Object list properties */

} CCT_SFODObjectList_t; /* CCT SFOD Object list properties  */

/* pdo meas freeze defines for SPOD component */
//#ifdef __PDO__
//#define SFOD_MEAS_ID_PUBLIC_OBJECT_LIST
///*! @vaddr:SFOD_MEAS_ID_PUBLIC_OBJECT_LIST @cycleid:SFOD_CYCLE @vname:SFODPublicObjData  */
//typedef CCT_SFODObjectList_t PDO_SFODPublicObjData;
//#endif


/*------------  SPOD ObjectList -----------------*/
#define         NUMBER_OF_SPOD_OBJECTS         (3U)

static const ui32_t CCT_SPODObjectList_VersionNumber = 1;

typedef struct _CCT_SPODObjectList
{
  DEFINE_VERSION_MEMBER(CCT_SPODObjectList);
  Algo64DataTimeStamp_t Timestamp_usec;             /*!< Microsec Timestamp of the SPOD Object List*/
  AlgoFrameCounter_t    FrameCounter;               /*!< Actuall frame counter */
  AlgoSignalState_t     SigState;                   /*!< valid flag */

  HeaderObjList_t HeaderObjList;                    /*!< Header Object list properties */
  Objects_t       Objects[NUMBER_OF_SPOD_OBJECTS];  /*!< Object list properties */

} CCT_SPODObjectList_t; /* SPOD Object list properties  */

/* pdo meas freeze defines for SPOD component */
//#ifdef __PDO__
//#define SPOD_MEAS_ID_PUBLIC_OBJECT_LIST
///*! @vaddr:SPOD_MEAS_ID_PUBLIC_OBJECT_LIST @cycleid:SPOD_CYCLE @vname:SPODPublicObjData  */
//typedef SPODObjectList_t PDO_SPODPublicObjData;
//#endif


#ifdef __cplusplus
}
#endif

#endif //COMMON_STEREO_INTERFACE_TYPES_H__
