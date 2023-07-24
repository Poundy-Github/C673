/*! \file **********************************************************************

  COMPANY:        Continental AG

  PROJECT:        MFC300

  CPU:

  COMPONENT:      SPOD - Stereo Precise Object Detection

  MODULNAME:      spod_interface.h

  DESCRIPTION:    input/output structure handling for SPOD data

  AUTHOR:         J. Schmidt

  CREATION DATE:  20.07.2009

  VERSION:        $Revision: 1.1 $

**************************************************************************** */

#ifndef SPOD_INTERFACE_H
#define SPOD_INTERFACE_H

#include "cct_type.h"
#include "common_interface_defines.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*! \brief  maximum number of objects in input list (for init) */
#define SPOD_INPUTOBJECTLIST_MAXOBJECTS  14

/*! \brief  maximum number of objects in output list */
#define SPOD_OUTPUTOBJECTLIST_MAXOBJECTS  3

/*! \brief  max number in m distance in current implementation */
#define SPOD_CARPET_MAXELEMENTS 100

/*! \brief  max number in m distance in current implementation */
#define SPOD_CORRIDOR_MAXELEMENTS 100



/*! \brief  signal/variable state */
typedef enum
{
  SPOD_SIG_NOT_OK = 0U,  /*!< signal not available */
  SPOD_SIG_OK     = 1U   /*!< signal available */
}SPODSignalState_t;


/*! \brief dynamic property */
typedef enum
{
  SPOD_E_DYN_UNCLASSIFIED = 0U,  /*!<  unclassified */
  SPOD_E_DYN_MOVING       = 1U,  /*!<  moving object */
  SPOD_E_DYN_STATIONARY   = 2U,  /*!<  stationary object */
  SPOD_E_DYN_ONCOMING     = 3U,  /*!<  oncoming object */
  SPOD_E_DYN_STOPPED      = 4U,  /*!<  stopped object */
  SPOD_E_DYN_CROSSING     = 5U,  /*!<  crossing object */
  SPOD_E_DYN_CUT_IN       = 6U,  /*!<  cut in */
  SPOD_E_DYN_CUT_OUT      = 7U,  /*!<  cut out */
  SPOD_E_DYN_OVERTAKING   = 8U,  /*!<  overtaking object */
  SPOD_E_DYN_BREAKING     = 9U,  /*!<  breaking */
  SPOD_E_DYN_BACKSLIDING  = 10U /*!<  backsliding */
  
}SPODDynamicProperty_e;


/*! \brief  object of interest numbering, taken from radar ACC objects */
typedef enum
{
  SPOD_OBJ_NOT_OOI              = -1,
  SPOD_OBJ_NEXT_OOI             = 0,
  SPOD_OBJ_HIDDEN_NEXT_OOI      = 1,
  SPOD_OBJ_NEXT_LONG_LEFT_OOI   = 2,
  SPOD_OBJ_NEXT_LONG_RIGHT_OOI  = 3,
  SPOD_OBJ_NEXT_LAT_LEFT_OOI    = 4,
  SPOD_OBJ_NEXT_LAT_RIGHT_OOI   = 5
} SPODInputObjectOOI_t;

typedef enum
{
  SPOD_REL        = 0U,           /*!< Relevant Object in front */
  SPOD_LEFT       = 1U,           /*!< Object on left track */
  SPOD_RIGHT      = 2U,           /*!< Object on right track */
  SPOD_NO_OBJECT  = 3U            /*!< No relevant object detected */
} SPODRelevantType_t;

typedef enum
{
  SPOD_N_DTCT             = 0U,   /*!< No object detected */
  SPOD_DTCT_N_TRACK       = 1U,   /*!< Object detected but not tracked */
  SPOD_DTCT_TRACK         = 2U,   /*!< Object detected and tracked */
  SPOD_PART_OCCL_TRACK    = 3U,   /*!< Object partially occluded and tracked */
  SPOD_PART_VSBL_TRACK    = 4U,   /*!< Object partially visible and tracked */
  SPOD_PART_OCCL_EXTPOL   = 5U,   /*!< Object partially occluded and extrapolated */
  SPOD_COMPL_OCCL_EXTPOL  = 6U    /*!< Object completely occluded and extrapolated */
} SPODObjectState_t;

/** Describes the overall spod cam state */
typedef enum E_SPODCamState
{
  SPOD_CAM_STATE_FAULT   = 0U, /*!< POD failed permanently */
  SPOD_CAM_STATE_OK      = 1U, /*!< POD ready and running */
  SPOD_CAM_STATE_NA_TEMP = 2U, /*!< POD temporarily not available */
  SPOD_CAM_STATE_NA_IDLE = 3U  /*!< POD idle */
} SPODCamState_t;

static const ui32_t SPODMountingCalibrationData_VersionNumber = 1U;

typedef struct _SPODMountingCalibrationData
{
  DEFINE_VERSION_MEMBER(SPODMountingCalibrationData);          /*!< Version number */

  /* cameraposition in AUTOSAR - coordinates  */
  f32_t PositionX;                /*!< X-position of camera in meters */
  f32_t PositionY;                /*!< Y-position of camera in meters */
  f32_t PositionZ;                /*!< Z-position of camera in meters */

  /* rotation from vehicle to camera coordinates
  right handed, image rows coincide with x-axis, columns with y-axis, z to optical axis */
  f32_t Pitch;            /*!< x-rotation (pitch) [rad] */
  f32_t Roll;             /*!< y-rotation (roll)  [rad] */
  f32_t Yaw;              /*!< z-rotation (yaw)   [rad] */
} SPODMountingCalibrationData_t;


static const ui32_t SPODRectifiedCalibrationData_VersionNumber = 1U;

typedef struct _SPODRectifiedCalibrationData
{
  DEFINE_VERSION_MEMBER(SPODRectifiedCalibrationData);       /*!< Version number */

  f32_t FocalX;               /*!< camera X-coordinate focal length [pixel] */
  f32_t FocalY;               /*!< camera Y-coordinate focal length [pixel] */
  f32_t CenterX;              /*!< X-coordinate of camera center point in image [pixel] */
  f32_t CenterY;              /*!< Y-coordinate of camera center point in image [pixel] */
  f32_t Baseline_m;           /*!< camera stereo baseline [m] */
} SPODRectifiedCalibrationData_t;


static const ui32_t SPODVehicleData_VersionNumber = 2U;

typedef struct _SPODVehicleData
{
  DEFINE_VERSION_MEMBER(SPODVehicleData);                           /*!< Version number */

  f32_t      velocity_m_per_s;                        /*!< Closest measured velocity wrt image timestamp*/
  ui64_t     velocityTimestamp_usec;                  /*!< time stamp when velocity was measured in micro-sec */
  SPODSignalState_t SignalStateVelocity;              /*!< signal state of velocity_m_per_s */

  f32_t      yawRate_rad_per_s;                       /*!< Closest measured yaw rate wrt image timestamp, offset compensated*/
  ui64_t     yawRateTimestamp_usec;                   /*!< time stamp when yawRate was measured in micro-sec */
  SPODSignalState_t SignalStateYawRate_rad_per_s;     /*!< signal state of yawRate_rad_per_s */

  f32_t      steeringAngle_rad;                       /*!< Closest measured steering angle wrt image timestamp; steering_Angle_rad = SteeringWheelAngle / SteeringRatio; */
  ui64_t     steeringAngleTimestamp_usec;             /*!< time stamp when steeringAnegle was measured in micro-sec */
  SPODSignalState_t SignalStateSteeringAngle_rad;     /*!< signal state of steeringAngle_rad */

  f32_t      DistanceFront2RearAxis_m;                /*!< distance between front and rear axis, for Ackermann model, [m] */

} SPODVehicleData_t;


static const ui32_t SPODLaneData_VersionNumber = 2U;

typedef struct _SPODLaneData
{
  DEFINE_VERSION_MEMBER(SPODLaneData);

  i32_t AvailableLeft;
  i32_t QualityLeft;
  f32_t DistanceLeft;
  f32_t CurvatureLeft;
  f32_t CurvatureRateLeft;
  f32_t YawLeft;
  f32_t LookaheadDistanceLeft;

  i32_t AvailableRight;
  i32_t QualityRight;
  f32_t DistanceRight;
  f32_t CurvatureRight;
  f32_t CurvatureRateRight;
  f32_t YawRight;
  f32_t LookaheadDistanceRight;

  f32_t PitchAngle;
} SPODLaneData_t;


static const ui32_t SPODImage_VersionNumber = 3U;

/*!< used for disparity maps */
typedef struct _SPODImage
{
  DEFINE_VERSION_MEMBER(SPODImage);   /*!< Version number */

  ui16_t*  image_p;

  ui32_t  FrameID;              /*!< frame ID wrt to image (for disparity maps the ID of the image pair on which the map is based has to be used)*/
  ui64_t  timestamp_usec;       /*!< Timestamp wrt image (for disparity maps the timestamp of the image pair on which the map is based has to be used) */

  i32_t   StartX_px;            /*!< Start of disparity ROI wrt image, x */
  i32_t   StartY_px;            /*!< Start of disparity ROI wrt image, y */
  i32_t   imageWidth_px;
  i32_t   imageHeight_px;

  ui32_t  validPixelCount;      /*!< Number of valid pixel elements in image_p */

} SPODImage_t;


/*!< optical flow */
typedef struct s_SPODOpticalFlowData
{
  i8_t DU;               /*!< */
  i8_t DV;               /*!< */
} SPODOpticalFlowData_t;


static const ui32_t SPODOpticalFlow_VersionNumber = 2U;

typedef struct _SPODOpticalFlow
{
  DEFINE_VERSION_MEMBER(SPODOpticalFlow);       /*!< Version number */

  SPODOpticalFlowData_t *data_p;

  ui32_t  FrameID;            /*!< Frame ID wrt to image on which optical flow is based */
  ui64_t  timestamp_usec;     /*!< Timestamp wrt image on which optical flow is based in milliseconds */

  i32_t   StartX_px;          /*!< Start of optical flow ROI wrt image, x */
  i32_t   StartY_px;          /*!< Start of optical flow ROI wrt image, y */
  i32_t   Width_px;           /*!< Width of optical flow ROI */
  i32_t   Height_px;          /*!< Height of optical flow ROI */

} SPODOpticalFlow_t;


static const ui32_t SPODInputObject_VersionNumber = 4U;

/*!< input object for init (presently taken from radar) */
typedef struct _SPODInputObject
{
  DEFINE_VERSION_MEMBER(SPODInputObject);              /*!< Version number */

  SPODSignalState_t SignalStateObjectData;  /*!< OK if data valid, NOK if data invalid */

  ui32_t   objID;                    /*!< object ID */
  ui64_t   timestamp_usec;           /*!< Timestamp for which the properties of the object are estimated (for an ARS300 Radar this is the timestamp of the according raw data measurement) */

  SPODInputObjectOOI_t OOINumber;

  f32_t    distance_m;                    /*!< longitudinal distance in m in VEHICLE (!) coordinate system */
  f32_t    lateralPosition_m;             /*!< lateral position in m in VEHICLE (!) coordinate system */
  f32_t    relativeVelocityLong_m_s;      /*!< relative longitudinal velocity in meter per sec in VEHICLE (!) coordinate system */
  f32_t    relativeVelocityLatLeft_m_s;   /*!< relative lateral velocity in meter per sec in VEHICLE (!) coordinate system */
  f32_t    relativeVelocityLatRight_m_s;  /*!< relative lateral velocity in meter per sec in VEHICLE (!) coordinate system */

  /* coordinates of points for object representation, Stereo-806, 807
     in vehicle coordinates */
  f32_t    XLeft_m, YLeft_m;         /*!< coordinates of leftmost point [m] */
  f32_t    XInter_m, YInter_m;       /*!< coordinates of intermediate point [m] */
  f32_t    XRight_m, YRight_m;       /*!< coordinates of rightmost point [m] */

  f32_t    HeightBottom_m;
  f32_t    HeightTop_m;

  ui32_t   Lifetime;                 /*!< lifetime of object, Stereo-800, unit frames */

  i32_t    RelevantObjectFlag;       /*!< Relevant flag from FOD */
                                     /*!< 0 = not relevant */
                                     /*!< 1 = relevant center */
                                     /*!< 2 = relevant left/right??? */
                                     /*!< 3 = relevant left/right??? */

  ui32_t   Priority;                 /*!< object priority [1...9] */

  i32_t    Blocked;                  /*!< object is detected as blocked */

} SPODInputObject_t;


static const ui32_t SPODInputObjectList_VersionNumber = 1U;

typedef struct _SPODInputObjectList
{
  DEFINE_VERSION_MEMBER(SPODInputObjectList);

  ui32_t nNumberOfObjects;

  SPODInputObject_t SPODInputObject[SPOD_INPUTOBJECTLIST_MAXOBJECTS];

} SPODInputObjectList_t;


static const ui32_t SPODCorridorSegment_VersionNumber = 1U;

typedef struct _SPODCorridorSegment
{
  DEFINE_VERSION_MEMBER(SPODCorridorSegment);

  /* Corridor segment coordinates in world and AUTOSAR */
  f32_t x_left_m;
  f32_t y_left_m;
  f32_t x_right_m;
  f32_t y_right_m;

} SPODCorridorSegment_t;


static const ui32_t SPODCorridor_VersionNumber = 2U;

typedef struct _SPODCorridor
{
  DEFINE_VERSION_MEMBER(SPODCorridor);

  SPODSignalState_t SignalStateCorridorData;

  ui32_t nNumberOfSegments;                       /*!< Number of defined Corridor Segments in array "segments" */
  SPODCorridorSegment_t segment[SPOD_CORRIDOR_MAXELEMENTS];     /*!< Array of Corridor Segments */

} SPODCorridor_t;


static const ui32_t SPODCarpetSegment_VersionNumber = 1U;

typedef struct _SPODCarpetSegment_t
{
  DEFINE_VERSION_MEMBER(SPODCarpetSegment);

  f32_t HeightProfile;                                  /*!< contains carpet height profile*/
  
  ui32_t x_left_px;                                     /*!< left border control point of carpet in pixel*/
  ui32_t y_left_px;
  ui32_t x_right_px;                                    /*!< right border control point of carpet in pixel*/
  ui32_t y_right_px;

} SPODCarpetSegment_t;


static const ui32_t SPODCarpet_VersionNumber = 2U;

typedef struct _SPODCarpet
{
  DEFINE_VERSION_MEMBER(SPODCarpet);

  SPODSignalState_t   SignalStateCarpetData;

  f32_t               CarpetStartX;                                  /*!< carpet starting point along X in meter (AUTOSAR) */
  f32_t               CarpetSegmentLength;                           /*!< carpet segment length along X in meter */

  ui32_t              NumberOfCarpetElements_ui32;                    /*!< contains number of valid carpet elements */
  SPODCarpetSegment_t segment[SPOD_CARPET_MAXELEMENTS];        /*!< contains carpet height profile, etc. */

} SPODCarpet_t;


/*! Type definition for Blockage status. */
typedef enum E_SPODBlockageStatus
{
  SPOD_BS_UNKNOWN_STATUS     = 0U, /*!< Unknown status (init error, communication error,...) */
  SPOD_BS_NO_BLOCKAGE        = 1U, /*!< No Blockage */
  SPOD_BS_TOLERATED_BLOCKAGE = 2U, /*!< Tolerated Blockage */
  SPOD_BS_CONDENSATION       = 3U, /*!< Condensation */
  SPOD_BS_PART_BLOCKAGE      = 4U, /*!< Partial Blockage */
  SPOD_BS_LOW_VISIBILITY     = 5U, /*!< Low Visibility */
  SPOD_BS_BLOCKAGE           = 6U  /*!< Blockage */
} SPODBlockageStatus_t;

static const ui32_t SPODBlockageData_VersionNumber = 1U;

/*! Type definition for the blockage of a MPC function */
typedef struct S_SPODBlockageData_t
{	
  DEFINE_VERSION_MEMBER(SPODBlockageData);

  SPODBlockageStatus_t status;             /*!< Blockage Status */
  ui8_t                statusConfidence; /*!< confidence (0..100) */
} SPODBlockageData_t;

static const ui32_t SPODDynamicInputData_VersionNumber = 5U;

typedef struct _SPODDynamicInputData
{
  DEFINE_VERSION_MEMBER(SPODDynamicInputData);   /*!< Version number */

  SPODMountingCalibrationData_t  MountRight;                /*!< transformation vehicle to right camera coordinate system */
  SPODRectifiedCalibrationData_t RectifiedCalibrationData;  /*!< camera parameters of rectified stereo system */

  SPODVehicleData_t VehicleData;                            /*!< vehicle data required by SPOD */

  SPODImage_t DisparityImageOverview;                       /*!< disparity map (overview) */
  SPODImage_t DisparityImageDetail;                         /*!< disparity map (detail) */
  SPODImage_t DisparityImageVicpMerged;                     /*!< disparity map (merged map => merge is done by VICP => REMEMBER: merged map is not valid before calling SW-FW-polling-service pfct_sl_VICPMergeDispWait!!!) */

  SPODOpticalFlow_t OpticalFlow;                            /*!< optical flow data */

  SPODLaneData_t LaneData;

  SPODInputObjectList_t SPODInputObjects;

  SPODCorridor_t Corridor;

  SPODCarpet_t Carpet;

  i32_t useRadarInit;                                       /*!< set to 1, if radar initialization is used; 0, if FOD initialization is used */

  i32_t IsRaining;                                          /*!< set to 1, if rain detected by external sensor or algo, 0 if no rain detected, 2 if SNA */   
  i32_t IsDay;                                              /*!< set to 1, if IC is in day mode, 0 if IC is in night mode, 2 if SNA */   

  SPODMountingCalibrationData_t  MountRadar;                /*!< Mounting Position of Radar */
                                                            /*!< Note: This needs to be stored in the Camera and is critical for a resimulation */
                                                            /*!< So maybe this should be freezed out as a general calibration parameter */
  SPODBlockageData_t Blockage;                              /*!< Information given from a blockage detection */

} SPODDynamicInputData_t;

static const ui32_t SPODObjectQuality_VersionNumber = 2U;

typedef struct _SPODObjectQuality
{
  DEFINE_VERSION_MEMBER(SPODObjectQuality); /*!< version of structure */

  f32_t  confidenceByAge;               /*!< confidence estimated from the objects age */
  f32_t  confidenceByWidth;             /*!< confidence estimated from the change of width */
  f32_t  confidenceByFeatureCount;      /*!< confidence estimated from the number of features used for the object tracking */
  f32_t  confidenceByDisparity;         /*!< confidence estimated from the disparityInRangeRatio */
  f32_t  confidenceByFOD;               /*!< confidence estimated from the existance of a fod object that could be assigned to this object */
  f32_t  confidenceByMovementCondition; /*!< confidence estimated from the movement condition (stationary or not) of the object */

  f32_t  disparityInRangeRatio;  /*!< area to amount ratio of disparity values considered inliers w.r.t. to the back of the vehicle */
  f32_t  disparityTooCloseRatio; /*!< area to amount ratio of disparity values considered too close w.r.t. to the back of the vehicle */

  f32_t  widthVariance;

  bool_t widthInRange;                /*!< width of object fullfills output requirements */
  bool_t widthVarianceInRange;        /*!< variance of width fullfills output requirements */
  bool_t lateralVelocityInRange;      /*!< lateral velocity of object fullfills output requirements */
  bool_t longitudinalVelocityInRange; /*!< longitudinal velocity of object fullfills output requirements */
  bool_t confidenceValid;             /*!< overall confidence fullfills output requirements */

  i8_t   framesUntilValidChange; /*!< number of frames left, the change of the valid flag is delayed */

} SPODObjectQuality_t;

static const ui32_t SPODObject_VersionNumber = 4U;

typedef struct _SPODObject
{
  DEFINE_VERSION_MEMBER(SPODObject);                        /*!< version of structure */

  SPODSignalState_t SignalStateObjectData;                  /*!< OK if data valid, NOK if data invalid */
                                                            /*!< This flag is used to decide if an object is usable or not */
                                                            /*!< It is not guaranteed that an object stays at the same position */
                                                            /*!< within the object list while being perceived. */

  ui32_t   objID;                                           /*!< object ID */
  ui64_t   timestamp_usec;                                  /*!< timestamp for which the object properties are estimated   */
                                                            /*!< note: not all objects in the objectlist necessarily have the same timestamp */
  ui32_t   FOD_ID;                                          /*!< ID from relevant/triggered/associated FOD object */
  ui32_t   Radar_ID;                                        /*!< ID from relevant/triggered/associated radar object */

  /* status information */
  i32_t    ObservedFlag;                                    /*!< object observed in current frame?  0 = false, 1 = true, 2 = SNA; false -> flag extrapolated from Stereo-1460 = 1*/
  ui32_t   LifetimeCycles;                                  /*!< lifetime of object [cylces] */
  ui32_t   TrackingCycles;                                  /*!< number of cycles that the object has been tracked continuously [cylces] */
  SPODRelevantType_t RelevantType;                          /*!< Type of object */
  i32_t    Usable;                                          /*!< 0 = false, 1 = true, 2 = SNA, Stereo-1456 */
  f32_t    Confidence;                                      /*!< overall object confidence [0.0; 1.0], Stereo-283 */
  SPODObjectState_t ObjectState;                            /*!< Current state of POD-Object */

  SPODDynamicProperty_e DynamicProperty;

  /* coordinates of reference point */
  f32_t    RefPointX, RefPointY, RefPointZ;                  /*!< reference point coordinates in vehicle coordinate system */

  f32_t    LongitudinalDistance_m;                           /*!< Longitudinal distance to object [m] */
  f32_t    LateralDistance_m;                                /*!< Lateral distance to object [m] */
  f32_t    Altitude_m;                                       /*!< Height above ground (Autosar Z = 0) [m] */
  f32_t    Width_m;                                          /*!< width of object [m] */

  f32_t    AbsoluteVelocityX_ms;
  f32_t    SigmaAbsVX;

  f32_t    RelativeVelocityX_ms;                             /*!< relative velocity in longitudinal direction [m/s]*/
  f32_t    SigmaRelVX;                                       /*!< standard deviation (1-sigma) for relative velocity in X direction */

  f32_t    AbsoluteVelocityY_ms;
  f32_t    SigmaAbsVY;

  f32_t    RelativeVelocityY_ms;                             /*!< relative velocity in lateral direction [m/s] */
  f32_t    SigmaRelVY;                                       /*!< standard deviation (1-sigma) for relative velocity in Y direction */

  f32_t    AbsoluteAcceleration_ms2;                         /*!< absoute acceleration of object [m/s^2]*/
  f32_t    SigmaAbsAcc;                                      /*!< standard deviation (1-sigma) for absoute acceleration */

  f32_t    RelativeAcceleration_ms2;
  f32_t    SigmaRelAcc;

  f32_t    AbsoluteYawRate_rad_per_s;                        /*!< absoute yaw rate of object [rad/s]*/
  f32_t    SigmaAbsYR;                                       /*!< standard deviation (1-sigma) for absoute yaw rate */

  f32_t    RelativeYawRate_rad_per_s;
  f32_t    SigmaRelYR;

  /*!< object bounding box (3D) */
  f32_t    x_bl_m;                                          //!< x back left corner of object 
  f32_t    y_bl_m;                                          //!< y back left corner of object 
  f32_t    x_br_m;                                          //!< x back right corner of object 
  f32_t    y_br_m;                                          //!< y back right corner of object 
  f32_t    x_fl_m;                                          //!< x front left corner of object 
  f32_t    y_fl_m;                                          //!< y front left corner of object 
  f32_t    x_fr_m;                                          //!< x front right corner of object 
  f32_t    y_fr_m;                                          //!< y front right corner of object 

  SPODObjectQuality_t Quality; /*!< quality measures for this object */
} SPODObject_t;

/* error output section */

/*!
 * definition of external error check status type
 * check failed means that the check was performed and an error detected
 */
typedef enum E_SPODErrorStatus
{
  SPOD_ERROR_CHECK_NOT_DONE         = 0U,  /*!< status of error unknown, i.e. error was not (completely) checked */
  SPOD_ERROR_CHECK_DONE_AND_PASSED  = 1U,  /*!< error did not occur */
  SPOD_ERROR_CHECK_DONE_AND_FAILED  = 2U   /*!< error did occur */
} SPODErrorStatus_t;

/*!
 * definition of external error ids (basic categories; algo can define additional ones)
 * parameter: erroneous input parameter (static  "configuration" data)
 * blockage : function not available due to blockage
 * vehicle data : erroneous vehicle data input (speed, yaw rate, ...)
 * image data : erroneous image data (wrong size, timestamp delta too large/small, non-incrementing frame counter ...)
 * calibration: calibration data error (special case of input error since often encountered)
 * input: erroneous dynamic input data (other sources)
 * software: internal software error (index, pointer, function parameter etc.)
 * fatal: serious, non-recoverable error
 * NOTE: Assumption is that first error has value 0
 */
typedef enum E_SPODErrorId
{
  SPOD_ERROR_PARAMETER        = 0U,  /*!< error group: parameter --> error occurred during init */
  SPOD_ERROR_BLOCKAGE         = 1U,  /*!< error group: blockage */
  SPOD_ERROR_VEHICLE_DATA     = 2U,  /*!< error group: error in vehicle input data */
  SPOD_ERROR_IMAGE_DATA       = 3U,  /*!< error group: error in image input data */
  SPOD_ERROR_CALIBRATION      = 4U,  /*!< error group: error in calibration input */
  SPOD_ERROR_INPUT            = 5U,  /*!< error group: (other) input error*/
  SPOD_ERROR_SOFTWARE         = 6U,  /*!< error group: software, e.g. NULL ptr */
  SPOD_ERROR_FATAL            = 7U,  /*!< error group: fatal, e.g. HW-error */
  SPOD_ERROR_OUTPUT           = 8U,  /*!< error group: output data */
  SPOD_NUM_ERROR_LIST_ENTRIES = 9U   /*!< pseudo entry for number of errors */
} SPODErrorId_t;

static const ui32_t SPODError_VersionNumber = 1U; /*!< Version of SPODError_t */

/*!
 * definition of external error list entry type
 */
typedef struct S_SPODError
{
  DEFINE_VERSION_MEMBER(SPODError);  /*!< Version number */

  SPODErrorStatus_t status;  /*!< status of error */
  ui32_t            optData; /*!< optional data */
} SPODError_t;

static const ui32_t SPODOutputErrors_VersionNumber = 1U; /*!< Version of SPODOutputErrors_t */

/*!
 * definition of external error list
 */
typedef struct S_SPODOutputErrors
{
  DEFINE_VERSION_MEMBER(SPODOutputErrors);  /*!< Version number */

  SPODError_t error[SPOD_NUM_ERROR_LIST_ENTRIES];  /*!< error entries, indexed by SPODErrorId_t defined above */
} SPODOutputErrors_t;

/*!
 * definition of algo state type
 */
typedef enum E_SPODState
{
  SPOD_STATE_NOT_INITIALIZED     = 0U,  /*!< algo has not been initialized yet, state before init() function */
  SPOD_STATE_RUNNING             = 1U,  /*!< algo has been initialized and is running fine */
  SPOD_STATE_TEMP_NOT_AVAILABLE  = 2U,  /*!< algo has been initialized but is temporarily not available */
  SPOD_STATE_FAILURE             = 3U   /*!< algo is in failure mode, needs to be reinitialized by frame SW */
} SPODState_t;

static const ui32_t SPODSystemInfo_VersionNumber = 1U; /*!< version of SPODSystemInfo_t */

/*!
 * definition of system info type
 * this structure is passed to algo init() and run() functions as output argument, algo updates it at each call.
 * e.g. init(..., SPODSystemInfo_t *sysInfo, ...);
 */
typedef struct S_SPODSystemInfo
{
  DEFINE_VERSION_MEMBER(SPODSystemInfo);  /*!< Version number */

  SPODOutputErrors_t errors;
  SPODState_t        state;
} SPODSystemInfo_t;

/* full output structure */
static const ui32_t SPODOutputData_VersionNumber = 4U; /*!< version of SPODOutputData_t */

typedef struct _SPODOutputData
{
  DEFINE_VERSION_MEMBER(SPODOutputData);   /*!< Version number */

  ui32_t            FrameID;                                      /*!< Frame ID of input data for synchronisation (identical to frame ID of input data) */
  SPODObject_t      SPODObject[SPOD_OUTPUTOBJECTLIST_MAXOBJECTS]; /*!< List of SPOD objects detected / tracked by the algorithm */
  SPODCamState_t    AlgoState;                                    /*!< Overall algorithm state */
  ui64_t            DiagState;                                    /*!< 60 bit diagnosis field (the 4 msb are reserved) */
} SPODOutputData_t;


static const ui32_t SPODMeasFreezeControl_VersionNumber = 1U;

/*!< used to control the MeasFreezeOutput of the algorithm */
/*!< as the output bandwidth is limited this structure is used */
/*!< to select which MeasFreezeData is sent */
/*!< SPODAlgo needs to verify that a valid setting is choosen */
typedef struct s_SPODMeasFreezeControl
{
  DEFINE_VERSION_MEMBER(SPODMeasFreezeControl);  /*!< Version number */

  bool_t FreezeSixD;
  bool_t FreezeSWM;

  ui32_t reserved;                         /*!< reserved for development */

} SPODMeasFreezeControl_t;


/*! \brief  signal/variable state */
typedef enum 
{
  SPOD_DISABLED                = 0U, /*!< disabled, SPOD algo running */
  SPOD_ENABLED_CHECK_DISPVICP  = 1U, /*!< enabled, SPOD algo disabled, sends test data in output list and checks only disparity from vicp  */ 
  SPOD_ENABLED_MEASFREEZE_ONLY = 2U  /*!< enabled, SPOD algo disabled, generates only measfreeze */
} SPODDebugState_t;


static const ui32_t SPODDebugControl_VersionNumber = 1U;

/*!< used to control the Debug behaviour of the algorithm */
/*!< can be used during integration to test the output for example */
typedef struct _SPODDebugControl
{
  DEFINE_VERSION_MEMBER(SPODDebugControl);             /*!< Version number */

  SPODDebugState_t   sendTestOutputData;               /*!< when enabled algorithm is not run and testOutput is sent */ 
  ui32_t             reserved;

} SPODDebugControl_t;

static const ui32_t SPODAlgoVersion_VersionNumber = 1U;

typedef struct _SPODAlgoVersion
{
  DEFINE_VERSION_MEMBER(SPODAlgoVersion); /*!< Version number */

  ui32_t    AlgoVersionNumber;    /*!< Version Number of algo */
  i8_t      AlgoVersionInfo[51];  /*!< string */
} SPODAlgoVersion_t;


/* interface typedefs of used services */

/* service for cache invalidation */
typedef void (*Fct_v_CacheInvalidateAll)(void);

/* service for starting a DMA transfer 
(pv_Src -> pv_Dest)[sl_Size] */
typedef i32_t (*Fct_sl_DMACopy)(void *pv_Dest, void *pv_Src, i32_t sl_Size, i32_t *psl_Handle);

/* service for starting a 2D-DMA transfer */
typedef i32_t (*Fct_sl_DMACopy_2D)(void *pv_Dst, void *pv_Src,
                                   i32_t sl_DstPitch, i32_t sl_SrcPitch,
                                   i32_t sl_Width, i32_t sl_Height,
                                   i32_t *psl_Handle);

/* service for starting a chained DMA transfer 
(pv_PreSrc -> pv_PreDest)[sl_PreSize] followed by 
(pv_PostSrc-> pv_PostDest)[sl_PostSize] */
typedef i32_t (*Fct_sl_DMACopyChained)(void *pv_PreDest, void *pv_PreSrc, i32_t sl_PreSize,
                                       void *pv_PostDest, void *pv_PostSrc, i32_t sl_PostSize,
                                       i32_t *psl_PostHandle);

/* service for filling memory with sl_Size 32bit words */
typedef i32_t (*Fct_sl_DMAMemSet)(void *pDest, ui32_t Pattern, i32_t sl_Size, i32_t *psl_Handle);

/* service for waiting for the DMA transfer specified by sl_Handle */
typedef i32_t (*Fct_sl_DMAWait)(i32_t sl_Handle);

/* MeasFreeze service */
typedef i32_t (*Fct_sl_MEASFreeze) (void *pData, i32_t size, i32_t VirtAddr);

/* service for waiting for the VICP processing to be ready (VICP-Merge-Disparity-Maps) */
typedef i32_t (*Fct_sl_VICPMergeDispWait)();

/* *****************************************************************************
Functionname : SPODInit                                                    */ /*!
Description  : initialize SPOD algorithm with FW services

@param[in]     function pointers
@return        i32_SPOD_NO_ERROR or error code
@pre           -
@post          -
@author        Jochen Schmidt
**************************************************************************** */
i32_t SPODInit(SPODSystemInfo_t* const        pSystemInfo,
               const Fct_v_CacheInvalidateAll pfct_v_CacheInvalidateAll,
               const Fct_sl_DMACopy           pfct_sl_DMACopy,
               const Fct_sl_DMACopy_2D        pfct_sl_DMACopy_2D,
               const Fct_sl_DMACopyChained    pfct_sl_DMACopyChained,
               const Fct_sl_DMAMemSet         pfct_sl_DMAMemSet,
               const Fct_sl_DMAWait           pfct_sl_DMAWait,
               const Fct_sl_MEASFreeze        pfct_sl_MEASFreeze,
               const Fct_sl_VICPMergeDispWait pfct_sl_VICPMergeDispWait);

/* *****************************************************************************
Functionname : SPODOpen                                                    */ /*!
Description  : open SPOD algorithm

@param[in]     pStaticInputData: static algo data
@return        i32_SPOD_NO_ERROR or error code
@pre           -
@post          -
@author        Jochen Schmidt
**************************************************************************** */
i32_t SPODOpen(SPODSystemInfo_t* const pSystemInfo);

/* **************************************************************************** 
Functionname : SPODRun                                                    */ /*!  
Description  : run SPOD algorithm

@param[in]     pDynamicInputData: dynamic input data
@param[out]    pOutputData: output data to fill

@return        i32_SPOD_NO_ERROR or error code
@pre           -
@post          -
@author        Jochen Schmidt
**************************************************************************** */
i32_t SPODRun(const SPODDynamicInputData_t* const  pDynamicInputData,
              SPODOutputData_t* const              pOutputData,
              SPODSystemInfo_t* const              pSystemInfo,
              const SPODMeasFreezeControl_t* const pMeasFreezeControl,
              const SPODDebugControl_t* const      pDebugControl,
              void* const                          pvd_L2Ram,
              const i32_t                          i32_SizeOfL2Bytes);


/* **************************************************************************** 
Functionname : SPODClose                                                  */ /*!  
Description  : close SPOD algorithm

@return        i32_SPOD_NO_ERROR or error code
@pre           -
@post          -
@author        Jochen Schmidt
**************************************************************************** */
i32_t SPODClose(SPODSystemInfo_t* const pSystemInfo);


/* **************************************************************************** 
Functionname : si32_SPODGetInternalState                                       */ /*!  
Description  : Get complete internal state of the Algo in current frame

@return        0 ok, 1 not ok
@pre           -
@post          -
@author        Markus Friebertshaeuser
**************************************************************************** */
i32_t SPODGetInternalState(void** const SPOD_AlgoState, ui32_t* const length);


/* **************************************************************************** 
Functionname : si32_SPODGetInternalState                                       */ /*!  
Description  : Get complete internal state of the Algo in current frame

@return        Current Version of the Algo
@pre           -
@post          -
@author        Markus Friebertshaeuser
**************************************************************************** */
i32_t SPODGetAlgoVersion(SPODAlgoVersion_t* const pAlgoVersion);



#ifdef __cplusplus
}
#endif

#endif /* SPOD_INTERFACE_H */

