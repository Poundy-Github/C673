/*! \file VelodyneHDL64EPointCloud.h
*******************************************************************************
COMPANY:          (C) Copyright Continental AG, All rights reserved.

AUTHOR:           Markus Gressmann

DESCRIPTION:      Describes the data packages sent by the VelodyneProcessor MO
                  using the Velodyne HDL-64E laser scanner.

CREATION DATE:    10.02.2016

VERSION:		  1.0

*******************************************************************************/

#ifndef _VELODYNE_HDL64E_POINTCLOUD_
#define _VELODYNE_HDL64E_POINTCLOUD_


// The documentation for this sensor can be found under:
// http://velodynelidar.com/docs/manuals/63-HDL64ES2h%20HDL-64E%20S2%20CD%20Users%20Manual.pdf

// In the following, "vehicle coordinates" refers to an AUTOSAR-coordinate system (North-West-Up) with its origin on the ground in the middle of the front axle
// "Velodyne coordinates" are relative to the sensor center and use a East-North-Up convention for their X- Y- and Z-axis

enum {MAX_NUMBER_VELODYNE_CLOUD_POINTS = 266627};  // The maximum number of 3D points that can be transmitted by the Velodyne HDL-64E in one revolution
enum {VELODYNE_PROCESSOR_INTERFACE_VERSION = 1};   // Increase the version number each time this interface is changed

#pragma pack(push, 1)
typedef struct 
{
  unsigned __int32  ui_versionNumber;                       // The version of the interface, is filled with VELODYNE_PROCESSOR_INTERFACE_VERSION by the processor
  unsigned __int64  ui64_timestampSystemMicrosecondsMTS;    // "System timestamp" from MTS package of the first measurement of current revolution [usec]
  unsigned __int64  ui64_timestampUTCMicrosecondsMTS;       // "UTC timestamp" from MTS package of the first measurement of current revolution [usec]
  unsigned __int64  ui64_revolutionCounter;                 // Increases with each full revolution of the Velodyne sensor head  
  bool              b_signalValid;                          // True if this signal is valid
} VelodyneHDL64ECloudSignalHeader_t;

typedef struct 
{
  float             f_sensorPositionAutosarX;               // X-position (longitudinal) of the sensor in vehicle coordinates [m]
  float             f_sensorPositionAutosarY;               // Y-position (lateral) of the sensor in vehicle coordinates [m]
  float             f_sensorPositionAutosarZ;               // Z-position (height) of the sensor in vehicle coordinates [m]
  float             f_sensorRollRad;                        // Rotation of the sensor around its X-axis (longitudinal) relative to the vehicle coordinate system [rad]
  float             f_sensorPitchRad;                       // Rotation of the sensor around its Y-axis (lateral) relative to the vehicle coordinate system [rad]
  float             f_sensorYawRad;                         // Rotation of the sensor around its Z-axis (up) relative to the vehicle coordinate system [rad]
} VelodyneHDL64EPositionOrientation_t;

typedef struct 
{  
  unsigned __int8   uc_hours;                               // GPS time of the first measurement of current revolution, hour component. There can be a little offset compared to the complete timestamp.
  unsigned __int8   uc_minutes;                             // GPS time the first measurement of current revolution, minute component. There can be a little offset compared to the complete timestamp.
  unsigned __int8   uc_seconds;                             // GPS time the first measurement of current revolution, seconds component. There can be a little offset compared to the complete timestamp.
  unsigned __int8   uc_day;                                 // GPS time the first measurement of current revolution, day component. There can be a little offset compared to the complete timestamp.
  unsigned __int8   uc_month;                               // GPS time the first measurement of current revolution, month component. There can be a little offset compared to the complete timestamp.
  unsigned __int8   uc_year;                                // GPS time the first measurement of current revolution, year component. There can be a little offset compared to the complete timestamp.
  unsigned __int16  us_reserved;                            // Reserved for further use and padding
  unsigned __int64  ui64_UTCTimestampMicroseconds;          // GPS timestamp of the first measurement of current revolution converted into UTC timestamp (0h 1970-01-01) [usec from GPS time zero (0h 1980-01-06) ]
  unsigned __int32  ui_GPSTimestampMicrosecondsHourBased;   // GPS timestamp of the first measurement of current revolution from the top of the hour, obtained directly from sensor [usec from GPS time zero (0h 1980-01-06) ]
  
  bool              b_GPSConnectionEstablished;             // true if sensor has established GPS connection, see sensor manual for details
  bool              b_PPSConnectionEstablished;             // true if sensor has established PPS connection, see sensor manual for details
} VelodyneHDL64EStatus_t;

typedef struct 
{
  VelodyneHDL64ECloudSignalHeader_t     s_signalHeader;     // Signal details
  VelodyneHDL64EStatus_t                s_status;           // Sensor status and timestamps
  VelodyneHDL64EPositionOrientation_t   s_pose;             // Position and orientation of sensor
  unsigned __int32                      ui_numValidPoints;  // Number of valid points contained in the following array
  
  __int16   s16q7_X[MAX_NUMBER_VELODYNE_CLOUD_POINTS];                            // X-position of the current measurement in vehicle coordinates [m], resolution 2^(-7)m, fixpoint
  __int16   s16q7_Y[MAX_NUMBER_VELODYNE_CLOUD_POINTS];                            // Y-position of the current measurement in vehicle coordinates [m], resolution 2^(-7)m, fixpoint
  __int16   s16q7_Z[MAX_NUMBER_VELODYNE_CLOUD_POINTS];                            // Z-position of the current measurement in vehicle coordinates [m], resolution 2^(-7)m, fixpoint
  unsigned __int8   uc_intensity[MAX_NUMBER_VELODYNE_CLOUD_POINTS];                       // Intensity of the returned laser pulse for this point [0 - 255]
  unsigned __int8   uc_laserID[MAX_NUMBER_VELODYNE_CLOUD_POINTS];                         // ID of the laser which has measured this point [0-63]
  unsigned __int32  ui_relativeTimestampMicroSeconds[MAX_NUMBER_VELODYNE_CLOUD_POINTS];   // Point in time this point was measured relative to the beginning of the current revolution [usec]
							                                                              // Absolute timestamp = u_UTCTimestampMicroseconds + u_relativeTimestampMicroSeconds.
} VelodyneHDL64EPointCloud_t;
#pragma pack(pop)

#endif _VELODYNE_HDL64E_POINTCLOUD_