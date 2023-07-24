/*! \file **********************************************************************

  @defgroup VDYMonModuleUnit VDY Input Output Monitor Module Unit Design
	@ingroup VDYHandCode
  @{

  $Company:			Continental AG $

  $Component:		VDY (Vehicle Dynamics Observer) $

  $Module:			vdy_mon.c $

  @brief			This module contains the monitoring functions

  $Descripion:		$
  
  $Revision: 1.17.1.4 $

  CHANGES:
  ---*/ /*---
  CHANGE:           $Log: vdy_mon.c  $
  CHANGE:           Revision 1.17.1.4 2020/07/29 09:16:16CEST Chinnaswamy, Ramachandra (uids4735) (uids4735) 
  CHANGE:           Detailed Design Update
  CHANGE:           Revision 1.17.1.3 2020/07/09 14:32:39CEST Patle, Mahesh (uidr0487) 
  CHANGE:           - vdy_mon.c file update for CML function to float variable for QA-C update.
  CHANGE:           Revision 1.17.1.1 2019/06/11 08:36:14CEST Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           QAF Fixes
  CHANGE:           Revision 1.17 2019/03/13 12:23:24CET Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           Meas opitimization and vdy memset definition
  CHANGE:           Revision 1.16 2019/01/31 07:25:24CET Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           Detailed Design Update
  CHANGE:           Revision 1.15 2019/01/26 21:23:58CET Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           Followed camel case convention for methods
  CHANGE:           Revision 1.14 2019/01/26 09:22:12CET Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           QAC fixes
  CHANGE:           Revision 1.13 2019/01/09 13:36:55CET Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           Detailed Design - Doors Linking
  CHANGE:           Revision 1.12 2019/01/07 14:04:22CET Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           SW requirmnet link to necessary C-Functions
  CHANGE:           Revision 1.11 2019/01/03 10:44:35CET Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           Detailed Design Update - UML for functions
  CHANGE:           Revision 1.10 2018/12/14 03:12:56CET Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           Disable steer ratio check,EG and Rear Steer check for projects having no SWA Processing
  CHANGE:           Revision 1.9 2018/12/06 05:07:00CET Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           QAC fixes
  CHANGE:           Revision 1.8 2018/12/05 10:53:15CET Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           QAC fixes
  CHANGE:           Revision 1.7 2018/11/28 12:07:31CET Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           QAC fixes
  CHANGE:           Revision 1.6 2018/11/15 10:41:22CET Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           PDO tool support
  CHANGE:           Revision 1.5 2018/09/17 14:00:05CEST Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           Support for courage environment: Defined STATIC_VAR
  CHANGE:           Revision 1.4 2018/09/12 16:23:14CEST Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           Support for courage environment
  CHANGE:           Revision 1.3 2018/09/04 12:00:04CEST Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           Detailed Design Update
  CHANGE:           Revision 1.2 2018/08/28 13:29:29CEST Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           Detailed Unit Design Update
  CHANGE:           Revision 1.1 2018/08/09 10:40:55CEST Singh, Sanjiv (uidr1340) 
  CHANGE:           Initial revision
  CHANGE:           Member added to project /ADAS/SW/Components/VDY_VehicleDynamics/04_Engineering/01_Source_Code/VDY/vdy/project.pj
  CHANGE:           Revision 1.65.1.3.1.1 2018/07/25 11:48:54CEST Singh, Sanjiv (uidr1340) 
  CHANGE:           VDY mearged code for ARS and MFC : Mainstream
  CHANGE:           Revision 1.65.1.3 2018/03/14 11:21:17CET Singh, Sanjiv (uidr1340) 
  CHANGE:           Yaw Rate and Curve state improvement- Vdy Yaw Rate and Curve output based on Velocity and SWA&Gye status . For detail - Look into the attached excel sheet of RO.
  CHANGE:           Revision 1.65.1.2 2018/03/14 10:27:59CET Singh, Sanjiv (uidr1340) 
  CHANGE:           Yaw Rate and Curve state improvement-
  CHANGE:           Vdy Yaw Rate and Curve output based on Velocity and SWA&Gye status .
  CHANGE:           For detail -
  CHANGE:           Look into the attached excel sheet of RO.
  CHANGE:           Revision 1.65.1.1 2017/03/31 05:31:54CEST Singh, Sanjiv (uidr1340) 
  CHANGE:           Adaptation of latest VDY Base changes to ARS510
  CHANGE:           Revision 1.65 2017/02/28 13:44:01CET Berwal, Anuj (uidp1444) 
  CHANGE:           Included checks for Rear Steering Wheel Angle.
  CHANGE:           Revision 1.64 2016/06/01 08:14:27CEST Singh, Sanjiv (uidr1340) 
  CHANGE:           Lateral and Longitudinal Acceleration threshold are separated.
  CHANGE:           Please add a new parameter in par.c and par.h for using this file.
  CHANGE:           Revision 1.63 2016/03/15 15:57:21CET Mani, Yugesh (uidj6870) 
  CHANGE:           -VDY_VEH_YWR_NOT_AVAIL DEM should not be set based on the yaw rate variance
  CHANGE:           -VDY_FS_YR_VS_WSP should not be set to active from VDY ( State will be always UNKNOWN)
  CHANGE:           Revision 1.62 2016/03/02 15:26:53CET Mani, Yugesh (uidj6870) 
  CHANGE:           - ABS and traction control timer threshold is set to 0 , From Custom it has to be changed for needed projects
  CHANGE:           Revision 1.61 2016/03/02 12:16:43CET Mani, Yugesh (uidj6870) 
  CHANGE:           - Fixed the QAC mandatory issues
  CHANGE:           Revision 1.60 2016/02/26 10:26:01CET Mani, Yugesh (uidj6870) 
  CHANGE:           - Added BMW switch for the Long ACCEL Signal introduced in peak checking
  CHANGE:           Revision 1.59 2016/02/24 09:00:33CET Singh, Sanjiv (uidr1340) 
  CHANGE:           update to latest version of mon.c(1.58)
  CHANGE:           +
  CHANGE:           addition of monitoring of BMW specific signal(longAccel) in side a switch
  CHANGE:           Revision 1.58 2016/02/04 09:18:57CET Mani, Yugesh (uidj6870) 
  CHANGE:           - variance check Debouncing error  is corrected and variance check for DEM setting is disabled 
  CHANGE:           - DEM is not set for 20s when Traction control is ON
  CHANGE:           Revision 1.57 2015/10/30 11:54:04CET Mani, Yugesh (uidj6870) 
  CHANGE:           Velocity Variance and Velocity not available DEM should not set when the ABS is active for more than 20 sec
  CHANGE:           - Added comments -  uidj6870 [Oct 30, 2015 11:54:04 AM CET]
  CHANGE:           Change Package : 392016:1 http://mks-psad:7002/im/viewissue?selection=392016
  CHANGE:           Revision 1.56 2015/09/22 12:17:04CEST Singh, Sanjiv (uidr1340) 
  CHANGE:           Including Turn Table Changes and ABS control during high braking
  CHANGE:           --- Added comments ---  uidr1340 [Sep 22, 2015 12:17:04 PM CEST]
  CHANGE:           Change Package : 379106:1 http://mks-psad:7002/im/viewissue?selection=379106
  CHANGE:           Revision 1.55 2015/08/17 13:46:26CEST Singh, Sanjiv (uidr1340) 
  CHANGE:           QAC fix
  CHANGE:           --- Added comments ---  uidr1340 [Aug 17, 2015 1:46:27 PM CEST]
  CHANGE:           Change Package : 368255:1 http://mks-psad:7002/im/viewissue?selection=368255
  CHANGE:           Revision 1.54 2015/07/23 09:16:42CEST Pakeer, Sudhakarreddy (uidj6215) 
  CHANGE:           --> added compiler switch for the initialized output debouncing variable to avoid QAC warning
  CHANGE:           --- Added comments ---  uidj6215 [Jul 23, 2015 9:16:42 AM CEST]
  CHANGE:           Change Package : 359415:2 http://mks-psad:7002/im/viewissue?selection=359415
  CHANGE:           Revision 1.53 2015/07/01 16:00:46CEST Pakeer, Sudhakarreddy (uidj6215) 
  CHANGE:           --> code made simple for VDYMonitorOutput and VDYMonitorVelocityOutput function and kept available for all projects
  CHANGE:           --> Initialized the output debouncing variable
  CHANGE:           --- Added comments ---  uidj6215 [Jul 1, 2015 4:00:46 PM CEST]
  CHANGE:           Change Package : 352803:1 http://mks-psad:7002/im/viewissue?selection=352803
  CHANGE:           Revision 1.52 2015/05/29 15:49:07CEST Wolter, Frank (wolterf) 
  CHANGE:           - corrected value limitation in signal peak check
  CHANGE:           - initialized remaining signals for signal peak check
  CHANGE:           - added compiler switch for output debouncing to keep code available
  CHANGE:           - removed magic constant in velocity variance check
  CHANGE:           --- Added comments ---  wolterf [May 29, 2015 3:49:07 PM CEST]
  CHANGE:           Change Package : 342733:1 http://mks-psad:7002/im/viewissue?selection=342733
  CHANGE:           Revision 1.51 2015/03/20 12:34:12CET Balachandra, Swathi (uidj2447) 
  CHANGE:           addition of debouncing for invalid outputs
  CHANGE:           --- Added comments ---  uidj2447 [Mar 20, 2015 12:34:13 PM CET]
  CHANGE:           Change Package : 318985:2 http://mks-psad:7002/im/viewissue?selection=318985
  CHANGE:           Revision 1.50 2015/01/27 11:08:50CET Mani, Yugesh (uidj6870) 
  CHANGE:           Added the velocity Threshold for dynamic acceleration
  CHANGE:           --- Added comments ---  uidj6870 [Jan 27, 2015 11:08:50 AM CET]
  CHANGE:           Change Package : 300000:1 http://mks-psad:7002/im/viewissue?selection=300000
  CHANGE:           Revision 1.49 2014/12/03 11:07:03CET Balachandra, Swathi (uidj2447) 
  CHANGE:           Fix on MISRA Violations
  CHANGE:           --- Added comments ---  uidj2447 [Dec 3, 2014 11:07:03 AM CET]
  CHANGE:           Change Package : 278585:1 http://mks-psad:7002/im/viewissue?selection=278585
  CHANGE:           Revision 1.48 2014/07/10 12:22:21CEST Wolter, Frank (wolterf) 
  CHANGE:           - serperated signal peak check and init of peak check signals
  CHANGE:           --- Added comments ---  wolterf [Jul 10, 2014 12:22:21 PM CEST]
  CHANGE:           Change Package : 245598:1 http://mks-psad:7002/im/viewissue?selection=245598
  CHANGE:           Revision 1.47 2014/07/08 12:48:21CEST Wolter, Frank (wolterf) 
  CHANGE:           - removed MISRA violations
  CHANGE:           --- Added comments ---  wolterf [Jul 8, 2014 12:48:21 PM CEST]
  CHANGE:           Change Package : 247012:1 http://mks-psad:7002/im/viewissue?selection=247012
  CHANGE:           Revision 1.46 2014/06/25 16:26:23CEST Wolter, Frank (wolterf) 
  CHANGE:           Allowing the setting of signal and parameter monitoring limits in the custom config
  CHANGE:           --- Added comments ---  wolterf [Jun 25, 2014 4:26:24 PM CEST]
  CHANGE:           Change Package : 244400:1 http://mks-psad:7002/im/viewissue?selection=244400
  CHANGE:           Revision 1.45 2014/05/06 17:09:54CEST Wolter, Frank (wolterf) 
  CHANGE:           - corrected threshold for yaw rate output range check
  CHANGE:           - no parameter fault if parameters are on default values and states
  CHANGE:           --- Added comments ---  wolterf [May 6, 2014 5:09:54 PM CEST]
  CHANGE:           Change Package : 226472:1 http://mks-psad:7002/im/viewissue?selection=226472
  CHANGE:           Revision 1.44 2014/04/08 15:00:08CEST Wolter, Frank (wolterf) 
  CHANGE:           - doxygen function header
  CHANGE:           - removed MISRA violations
  CHANGE:           --- Added comments ---  wolterf [Apr 8, 2014 3:00:09 PM CEST]
  CHANGE:           Change Package : 226472:1 http://mks-psad:7002/im/viewissue?selection=226472
  CHANGE:           Revision 1.43 2014/03/15 16:23:40CET Wolter, Frank (wolterf) 
  CHANGE:           - range check for parameters (as defined in TSC):
  CHANGE:           -- added self steering gradient, wheelticks, center of gravity height, wheel circumference, axle load distribution, wheel load dependency front and rear
  CHANGE:           -- defined lower and upper ranges
  CHANGE:           - input signal state degradation if range or peak fault is detected
  CHANGE:           - removed velocity dependency of yaw rate range check
  CHANGE:           - set longitudinal acceleration to invalid if range check failes
  CHANGE:           - set lateral acceleration to invalid if range check failes
  CHANGE:           - moved setting VDY_FS_VEH_CORR_MON fault to VDYVelMon to remove dependency to CFG_VDY_DIS_WHEEL_PRE_PROCESSING
  CHANGE:           - removed MISRA violations
  CHANGE:           --- Added comments ---  wolterf [Mar 15, 2014 4:23:41 PM CET]
  CHANGE:           Change Package : 225491:1 http://mks-psad:7002/im/viewissue?selection=225491
  CHANGE:           Revision 1.42 2014/03/11 16:18:00CET Wolter, Frank (wolterf) 
  CHANGE:           Input signal range check for lateral acceleration
  CHANGE:           --- Added comments ---  wolterf [Mar 11, 2014 4:18:00 PM CET]
  CHANGE:           Change Package : 224521:1 http://mks-psad:7002/im/viewissue?selection=224521
  CHANGE:           Revision 1.41 2014/03/07 09:29:31CET Wolter, Frank (wolterf) 
  CHANGE:           - removed QAC warnings
  CHANGE:           - removed compiler warnings
  CHANGE:           --- Added comments ---  wolterf [Mar 7, 2014 9:29:32 AM CET]
  CHANGE:           Change Package : 223834:1 http://mks-psad:7002/im/viewissue?selection=223834
  CHANGE:           Revision 1.40 2014/01/29 09:39:42CET Wolter, Frank (wolterf) 
  CHANGE:           Adapted signal states to new defintion
  CHANGE:           --- Added comments ---  wolterf [Jan 29, 2014 9:39:42 AM CET]
  CHANGE:           Change Package : 208447:1 http://mks-psad:7002/im/viewissue?selection=208447
  CHANGE:           Revision 1.39 2014/01/24 11:06:43CET Wolter, Frank (wolterf) 
  CHANGE:           Corrrected wheel base parameter check
  CHANGE:           --- Added comments ---  wolterf [Jan 24, 2014 11:06:44 AM CET]
  CHANGE:           Change Package : 198593:1 http://mks-psad:7002/im/viewissue?selection=198593
  CHANGE:           Revision 1.38 2013/11/29 11:07:11CET Wolter, Frank (wolterf) 
  CHANGE:           - implemented range check for input signals and parameters
  CHANGE:           - added acceleration and velocity to gradient check
  CHANGE:           --- Added comments ---  wolterf [Nov 29, 2013 11:07:12 AM CET]
  CHANGE:           Change Package : 198819:1 http://mks-psad:7002/im/viewissue?selection=198819
  CHANGE:           Revision 1.37 2013/09/24 13:31:59CEST Wolter, Frank (wolterf) 
  CHANGE:           - critical parameters must be valid and not 0
  CHANGE:           - misra updates
  CHANGE:           --- Added comments ---  wolterf [Sep 24, 2013 1:32:00 PM CEST]
  CHANGE:           Change Package : 198593:1 http://mks-psad:7002/im/viewissue?selection=198593
  CHANGE:           Revision 1.36 2013/07/22 16:37:05CEST Wolter, Frank (wolterf) 
  CHANGE:           - switched types to Autosar types
  CHANGE:           - fixed lint errors
  CHANGE:           - layout/spelling corrections
  CHANGE:           --- Added comments ---  wolterf [Jul 22, 2013 4:37:05 PM CEST]
  CHANGE:           Change Package : 188036:1 http://mks-psad:7002/im/viewissue?selection=188036
  CHANGE:           

*****************************************************************************/
/* PRQA S 7013 EOF */
/*  date: Unknown, reviewer: Suggested TCI Code Review, reason: Legacy code of ARS301, reducing lines of code changes component structure." */

/* PRQA S 7004 EOF */
/* date: Unknown, reviewer: Suggested TCI Code Review, reason: Legacy code of ARS301, reducing complexity adds risk and effort." */

/* PRQA S 3112 EOF */
/* date: Unknown, reviewer: Suggested TCI Code Review, reason: Legacy code of ARS301, Unused statement for some configurations " */

/* PRQA S 3218 EOF */
/* date: Unknown, reviewer: Suggested TCI Code Review, reason: Legacy code of ARS301, Mentioned Static Variables are used in two different functions" */

/* PRQA S 3116 EOF */
/* date: Unknown, reviewer: Suggested TCI Code Review, reason: Legacy code of MFC400, This pragma is VDY specific and necessary " */

/* PRQA S 3206 EOF */
/* date: Unknown, reviewer: Suggested TCI Code Review, reason: Legacy code of MFC400, proport is disabled by customer specific switch  " */

/* QAC Level 1 & 2 Warning Suppression */
/* PRQA S 2211, 3212, 3227, 3469, 1532 EOF */
/* date: 2019-06-10, reviewer: Mahesh Patle (uidr0487), reason: This operation is intended */

/* PRQA S 3447, 2824 EOF */
/* date: 2019-12-30, reviewer: Ramachandra Chinnaswamy (uids4735), reason: Fucntional Safe and Intended */

/*****************************************************************************
  INCLUDES
*****************************************************************************/

/// Activate interface to internal data
#define VDY_DACQ_IF   1L      
/* PRQA S 0380 EOF */
/* date: 2019-06-10, reviewer: Mahesh Patle (uidr0487), reason: No Risk */
/* PRQA S 1881 EOF */
/* date: 2019-06-10, reviewer: Mahesh Patle (uidr0487), reason: No Risk */
#include "vdy.h"

/* Use for NaN check */
#if ( (!defined(__MATH_H)) && (defined(__M32R__)))
/// NaN Check
#define ISNAN(_x) isnan(_x) 
#else
#if (!defined(__MATH_H))
/// NaN Check
#define ISNAN(_x)     FALSE 
#else
/// NaN Check
#define ISNAN(_x)     isnan(_x) 
#endif
#endif

#ifndef PC_SIM
/// Disable VDY SIM if PC is not defined
#define VDY_SIMU    0
#else
/// Enable VDY SIM if PC is defined
#define VDY_SIMU    1
#endif

/*****************************************************************************
  SYMBOLIC CONSTANTS
*****************************************************************************/
#if !(defined(CFG_VDY_DIS_FUNCTIONAL_SAFETY_MON) && (CFG_VDY_DIS_FUNCTIONAL_SAFETY_MON))

#if ( (!defined(CFG_VDY_DIS_WHEEL_PRE_PROCESSING)) || (!CFG_VDY_DIS_WHEEL_PRE_PROCESSING) )
/// if the yaw rates are above this threshold the distance is exeeded 
#define VDY_FS_WHEEL_YAW_RATE_THRESHOLD          (0.04F) 
/// threshold velocities, above yaw rate error monitoring is active 
#define MIN_WHEEL_YAW_RATE_VELOCITY        (15.0F) 
/// threshold variance, above yaw rate error monitoring is active 
#define MAX_WHEEL_YAW_RATE_VARIANCE        (99.0F) 
#endif

#if ( (!defined(CFG_VDY_DIS_LAT_ACCEL_SENSOR_PRE_PROCESSING)) || (!CFG_VDY_DIS_LAT_ACCEL_SENSOR_PRE_PROCESSING) )
/// if the yaw rates are above this threshold the distance is exeeded 
#define VDY_FS_LAT_ACCEL_YAW_RATE_THRESHOLD      (0.01F) 
/// threshold velocities, above yaw rate error monitoring is active 
#define MIN_LAT_ACCEL_YAW_RATE_VELOCITY    (10.0F) 
#endif

#if ( (!defined(CFG_VDY_DIS_STW_ANGLE_SENSOR_PRE_PROCESSING)) || (!CFG_VDY_DIS_STW_ANGLE_SENSOR_PRE_PROCESSING) )
/// if the yaw rates are above this threshold the distance is exeeded 
#define VDY_FS_SWA_YAW_RATE_THRESHOLD            (0.045F) 
///  threshold velocities, above yaw rate error monitoring is active 
#define MIN_SWA_YAW_RATE_VELOCITY          (10.0F) 
#endif

/// after this distance the yaw rate out of bounce error is released
#define VDY_FS_YAW_RATE_DIST_THRESHOLD     (150.0F) 


/// curve threshold, only below this the yaw rate is monitored 
#define MAX_CURVE_GRAD                     (0.0005F) 
/// the distance after that the mean of the deltas is calculated 
#define VDY_FS_MEAN_DRIVE_DISTANCE         (50.0F) 
///  reduce the mean after the driven distance with factor 
#define VDY_FS_DISTANCE_REDUCE_FACTOR      (0.5F) 


/// Plausibility check of course prediction parameter
#define VDY_FS_PRED_HORZ_TIME              (3.0F) 
/// Plausibility check of course prediction parameter
#define VDY_FS_MAX_LAT_DIST_ERROR          (1.5F) 
/// Plausibility check of course prediction parameter 
#define VDY_FS_MAX_LAT_DIST_COUNTER        (15U) 


/// Weights of wheel curve for course prediction monitoring
#define VDY_WYE_CURVECHECK_WEIGHT          (3.0F) 
/// Weights of lataccel curve for course prediction monitoring
#define VDY_AYE_CURVECHECK_WEIGHT          (4.0F) 
/// Weights of steering curve for course prediction monitoring
#define VDY_SYE_CURVECHECK_WEIGHT          (4.0F) 

#endif

/* signal ranges */
#ifndef MAX_VELOCITY
/// highest possible output velocity in m/s 
//#define MAX_VELOCITY                       (115.0F) //Modified by Mingfen
#define MAX_VELOCITY                       (130.0F)
#endif
#ifndef MAX_ACCELERATION
/// highest possible longitudinal and lateral output acceleration in m/s2
//#define MAX_ACCELERATION                    (15.0F)//Modified by Mingfen
#define MAX_ACCELERATION                    (32.0F)
#endif
#ifndef MAX_YAWRATE
/// highest possible output yaw rate in deg/s 
#define MAX_YAWRATE           (CML_Deg2Rad(150.0F))   
#endif
#ifndef MAX_STEERING_ANGLE
/// highest possible steering angle of the road wheels in deg 
#define MAX_STEERING_ANGLE     (CML_Deg2Rad(90.0F))
#endif

/* parameter ranges: minimum and maximum allowed range, default value if outside */
/* vehicle (curb) weight */
#ifndef MINIMUM_VEH_WEIGHT
/// minimum allowed range Vehicle (curb) weight
#define MINIMUM_VEH_WEIGHT         (500.0F) 
#endif
#ifndef MAXIMUM_VEH_WEIGHT
/// maximum allowed range Vehicle (curb) weight
#define MAXIMUM_VEH_WEIGHT        (7500.0F) 
#endif
#ifndef DEFAULT_VEH_WEIGHT
/// default Vehicle (curb) weight if outside the range
#define DEFAULT_VEH_WEIGHT        (1800.0F) 
#endif

/* track width front and rear axle */
#ifndef MINIMUM_TRACK_WIDTH
/// minimum allowed range track width front and rear axle
#define MINIMUM_TRACK_WIDTH          (1.0F) 
#endif
#ifndef MAXIMUM_TRACK_WIDTH
/// maximum allowed range track width front and rear axle
#define MAXIMUM_TRACK_WIDTH          (2.0F) 
#endif
#ifndef DEFAULT_TRACK_WIDTH
/// default Vtrack width front and rear axle if outside the range
#define DEFAULT_TRACK_WIDTH          (2.0F) 
#endif

/* wheel base */
#ifndef MINIMUM_WHEEL_BASE
/// minimum allowed range wheel base
#define MINIMUM_WHEEL_BASE           (2.0F) 
#endif
#ifndef MAXIMUM_WHEEL_BASE
/// maximum allowed range wheel base
#define MAXIMUM_WHEEL_BASE           (4.5F) 
#endif
#ifndef DEFAULT_WHEEL_BASE
/// default wheel base if outside the range
#define DEFAULT_WHEEL_BASE           (3.0F) 
#endif

/* steering angle ratio */
#ifndef MINIMUM_STEERING_RATIO
/// minimum allowed range steering angle ratio
#define MINIMUM_STEERING_RATIO       (1.0F) 
#endif
#ifndef MAXIMUM_STEERING_RATIO
/// maximum allowed range steering angle ratio
#define MAXIMUM_STEERING_RATIO     (500.0F) 
#endif
#ifndef DEFAULT_STEERING_RATIO
/// default steering angle ratio if outside the range
#define DEFAULT_STEERING_RATIO      (15.0F) 
#endif

/* self steering gradient */
#ifndef MINIMUM_SELF_STEERING_GRAD
/// minimum allowed range self steering gradient
#define MINIMUM_SELF_STEERING_GRAD   (CML_Deg2Rad(0.1F)) 
#endif
#ifndef MAXIMUM_SELF_STEERING_GRAD
/// maximum allowed range self steering gradient
#define MAXIMUM_SELF_STEERING_GRAD   (CML_Deg2Rad(0.4F)) 
#endif
#ifndef DEFAULT_SELF_STEERING_GRAD
/// default self steering gradient if outside the range
#define DEFAULT_SELF_STEERING_GRAD   (CML_Deg2Rad(0.2F)) 
#endif

/* wheel pulses per revolution */
#ifndef MINIMUM_WHEEL_TICKS_REV 
/// minimum allowed range wheel pulses per revolution
#define MINIMUM_WHEEL_TICKS_REV        (1U) 
#endif
#ifndef MAXIMUM_WHEEL_TICKS_REV
/// maximum allowed range wheel pulses per revolution
#define MAXIMUM_WHEEL_TICKS_REV      (250U) 
#endif
#ifndef DEFAULT_WHEEL_TICKS_REV
/// default wheel pulses per revolution if outside the range
#define DEFAULT_WHEEL_TICKS_REV       (96U) 
#endif

/* center of gravity heigth */
#ifndef MINIMUM_COGH
/// minimum allowed range center of gravity heigth
#define MINIMUM_COGH                (0.02F) 
#endif
#ifndef MAXIMUM_COGH
/// maximum allowed range center of gravity heigth
#define MAXIMUM_COGH                 (1.0F) 
#endif
#ifndef DEFAULT_COGH
/// default center of gravity heigth if outside the range
#define DEFAULT_COGH                 (0.8F) 
#endif

/* wheel cirumference */
#ifndef MINIMUM_WHEEL_CIRCUM  
/// minimum allowed range wheel cirumference
#define MINIMUM_WHEEL_CIRCUM         (1.5F) 
#endif
#ifndef MAXIMUM_WHEEL_CIRCUM  
/// maximum allowed range wheel cirumference
#define MAXIMUM_WHEEL_CIRCUM         (2.5F) 
#endif
#ifndef DEFAULT_WHEEL_CIRCUM
/// default wheel cirumference if outside the range
#define DEFAULT_WHEEL_CIRCUM         (2.0F) 
#endif

/* axle load distribution */
#ifndef MINIMUM_AXLE_LOAD_DISTR
/// minimum allowed range axle load distribution
#define MINIMUM_AXLE_LOAD_DISTR      (0.2F) 
#endif
#ifndef MAXIMUM_AXLE_LOAD_DISTR
/// maximum allowed range axle load distribution
#define MAXIMUM_AXLE_LOAD_DISTR      (0.8F) 
#endif
#ifndef DEFAULT_AXLE_LOAD_DISTR
/// default axle load distribution if outside the range
#define DEFAULT_AXLE_LOAD_DISTR      (0.5F) 
#endif

/* wheel load distribution */
#ifndef MINIMUM_WHEEL_LOAD_DEP    
/// minimum allowed range wheel load distribution
#define MINIMUM_WHEEL_LOAD_DEP       (0.0F) 
#endif
#ifndef MAXIMUM_WHEEL_LOAD_DEP    
/// maximum allowed range wheel load distribution
#define MAXIMUM_WHEEL_LOAD_DEP       (3.0F) 
#endif
#ifndef DEFAULT_WHEEL_LOAD_DEP
/// default wheel load distribution if outside the range
#define DEFAULT_WHEEL_LOAD_DEP       (2.0F) 
#endif


#ifndef VDY_ACC_THRESHOLD_INC_VELOCITY_VAR
/// acceleration threshold for increased allowed velocity variance 
#define VDY_ACC_THRESHOLD_INC_VELOCITY_VAR		(0.5F) 
#endif

#if ( (defined(CFG_VDY_DEBOUNCE_OUTPUTS)) && (CFG_VDY_DEBOUNCE_OUTPUTS) )
#ifndef VDY_MAX_OUTPUT_DEBOUNCING   
/// maximum debouncing of faulty outputs 
#define VDY_MAX_OUTPUT_DEBOUNCING		(0.0F) 
#endif
#endif


#ifndef OUTPUT_VEL_MON_DEACTIVATION_ABS 
/// maximum vdy cycles to deactivate the output Velocity monitor when abs is active 
#define OUTPUT_VEL_MON_DEACTIVATION_ABS	  (0.0F) 
#endif


#ifndef OUTPUT_VEL_MON_DEACTIVATION_TSC 
/// maximum vdy cycles to deactivate the output Velocity monitor when TSC is active 
#define OUTPUT_VEL_MON_DEACTIVATION_TSC   (0.0F) 
#endif

#if (CFG_VDY_YWR_OFFSET_MONITOR)
/// Velocity threshold for setting vehicle halt in case of vehicle standstill 
#define VDY_YWR_MON_VEL_STST_THRHD           ((fVelocity_t)(10.0F/C_KMH_MS))

/// Yaw rate differentiator time constant for offset monitor 
#define VDY_YWR_MON_DIFF_FILT                ((fTime_t) 1.5F)
/// Maximum yaw acceleration during standstill for calibration 
#define VDY_YWR_MON_YWR_GRAD_MAX             (fGradient_t) DEG2RAD(0.50F)
/// Maximum monitor standstill time for monitoring 
#define VDY_YWR_MON_TIME_MAX                 ((fTime_t) 3600.F)

/// Yaw rate threshold during vehicle-halt 
#define VDY_YWR_MON_VHALT_YWR_MAX            ((fYawRate_t) DEG2RAD(20.F))
/// Maximum allowed time span for yaw rate above threshold at standstill 
#define VDY_YWR_MON_VHALT_TIME_MAX           ((fTime_t) 0.2F)

/// Yaw rate threshold before drive-off 
#define VDY_YWR_MON_VDOFF_YWR_MAX            ((fYawRate_t) DEG2RAD(10.F))
/// Maximum allowed time span for yaw rate above threshold before drive-off 
#define VDY_YWR_MON_VDOFF_TIME_MAX           ((fTime_t) 4.5F)

/// Maximum allowed difference of yaw rate during vehicle-halt and drive-off 
#define VDY_YWR_MON_VHTDR_DIFF_MAX            DEG2RAD(13.0F)
/// Window length for yaw rate sample evaluation during vehicle-halt and drive-off 
#define VDY_YWR_MON_VHTDR_WIN_LEN             20.F
/// Maximum permitted standard deviation to take window-mean as offset 
#define VDY_YWR_MON_VHTDR_WIN_DEV             DEG2RAD(0.5F)

/// Maximum permitted vehicle halt time without standstill calibration 
#define VDY_YWR_MON_CAL_MAX_TIME              ((fTime_t) 3.0F)

/// Threshold (hysteresis) to enable active error indication 
#define VDY_YWR_MON_CAL_VEL_START_THRHD       ((fVelocity_t)(15.0F/C_KMH_MS))

#endif

#if ( (defined(CFG_VDY_ALIGNMENT_OFFSET_MONITOR)) && (CFG_VDY_ALIGNMENT_OFFSET_MONITOR) )
/// used by ALN if no yawrate could have been calculated 
#define VDY_ALN_OFFSET_MON_NO_DATA            (1E30F)  
#endif

/*****************************************************************************
  MACROS
*****************************************************************************/
#if (CFG_VDY_USE_VELO_MONITOR)
/// Access to Velocity Monitor Data
#define VMON_GET_ME                  (&VDYVelMonData)
#endif

#if (CFG_VDY_YWR_OFFSET_MONITOR)
/// Access to Global Yaw Rate Monitor Data
#define YWR_GET_MON_DATA             (&VDYYwrMonGlobData)
#endif


/*****************************************************************************
  TYPEDEFS
*****************************************************************************/
#if (CFG_VDY_YWR_OFFSET_MONITOR)
/// \brief Yaw rate monitoring common data
typedef struct {
  fTime_t		timeVehHalt;	///< Time elapsed when vehicle is StandStill
  fYawRate_t	ywRate;			///< Yaw Rate
  fTime_t		cycTime;		///< Cycle Time (Sampling Rate)
  boolean		StSt;			///< Standstill Indicator
  boolean		VehStSt;		///< Indicator for active vehicle halt
  fVelocity_t	Velocity;		///< Vehicle Velocity
} VDYYwrMonDataLoc_t;
#endif


/*****************************************************************************
  CONSTS
*****************************************************************************/



/*****************************************************************************
  VARIABLES
*****************************************************************************/
#if (CFG_VDY_USE_VELO_MONITOR)
/// Velocity Monitor Data
SET_MEMSEC_VAR(VDYVelMonData)
STATIC_VAR VDYVelMon_t VDYVelMonData;
#endif

#if (CFG_VDY_YWR_OFFSET_MONITOR)
SET_MEMSEC_VAR(VDYYwrMonGlobData)
STATIC_VAR VDYYwrMonData_t VDYYwrMonGlobData;	/*!< Global yaw rate monitor data \n @VADDR: VDY_MEAS_ID_YWR_MON \n @VNAME: VDYYwrMon \n @ALLOW: vdy_priv \n @cycleid: vdy_cycle_id */
#endif

#if ( (defined(CFG_VDY_ALIGNMENT_OFFSET_MONITOR)) && (CFG_VDY_ALIGNMENT_OFFSET_MONITOR) )
SET_MEMSEC_VAR(ACCThldTime)
/// acc threshold time
STATIC_VAR uint32   ACCThldTime;
SET_MEMSEC_VAR(CGThldTime)
/// cg threshold time
STATIC_VAR uint32   CGThldTime;
#endif

SET_MEMSEC_VAR(LastInputSignals)
/// Previous Input signal
STATIC_VAR VDYLastInSig_t LastInputSignals;

#if ( (defined(CFG_VDY_MON_OUTPUT_PEAKS)) && (CFG_VDY_MON_OUTPUT_PEAKS) )
SET_MEMSEC_VAR(LastOutputSignals)
/// Previous Output signal for peak monitoring
STATIC_VAR VDYLastOutSig_t LastOutputSignals;
#endif

#if !(defined(CFG_VDY_DIS_FUNCTIONAL_SAFETY_MON) && (CFG_VDY_DIS_FUNCTIONAL_SAFETY_MON))
SET_MEMSEC_VAR(gVDYFSData)
/// VDY Functional Safety Data
STATIC_VAR VDYFSData_t gVDYFSData;
#endif

#if ( (!defined(CFG_VDY_DIS_YWR_OFFSET_COMP)) || (!CFG_VDY_DIS_YWR_OFFSET_COMP) )
SET_MEMSEC_VAR(oldOffset)
/// yaw rate offset of previous cycle
STATIC_VAR float32 oldOffset;
SET_MEMSEC_VAR(StandStillOffset)
/// yaw rate standstill offset
STATIC_VAR float32 StandStillOffset;
#endif

/// Velocity Monitor when ABS is active
STATIC_VAR uint16 u_velMonitorOFFCounter_ABS ;

/// Velocity Monitor when TSC is active
STATIC_VAR uint16 u_velMonitorOFFCounter_TSC ;

#if ( (defined(CFG_VDY_DEBOUNCE_OUTPUTS)) && (CFG_VDY_DEBOUNCE_OUTPUTS) )  
/// vehicle velocity debouncing output counter 
STATIC_VAR uint8 u_Debouce_VDY_VEH_VEL_NOT_AVAILABLE ;
#endif

/*****************************************************************************
  LOCAL FUNCTION PROTOTYPES
*****************************************************************************/

#if !(defined(CFG_VDY_DIS_FUNCTIONAL_SAFETY_MON) && (CFG_VDY_DIS_FUNCTIONAL_SAFETY_MON))

/* **********************************************************************
  @fn               vdyFSVelocityMonitoring  */ /*!
  @brief           Functional safety velocity monitoring

  @description     Sets FuSi related output faults if velocity faults were detected

  @return          static void

  @param[in]       *proPorts : provided ports
  @param[in,out]   *VDYFSData : FS data

  @c_switch_part   
					  - CFG_VDY_USE_VELO_MONITOR : Enables monitoring of external vehicle velocity. The velocity is compared with estimated velocity based on wheel speeds
					  - CFG_VDY_DO_VELOCITY_CORR : Enables the velocity correction
					  - CFG_VDY_FS_VELO_CORR_MON : Enables the fast velocity to stationary targets monitor
  @c_switch_full   CFG_VDY_DIS_FUNCTIONAL_SAFETY_MON : Disable functional safety monitoring

  @pre             None
  @post            No changes
  @InOutCorrelation

	@startuml
	start
		if ( defined(CFG_VDY_USE_VELO_MONITOR) && (CFG_VDY_USE_VELO_MONITOR) ) then (YES)
			:this error was determined by the velo internal external mon function (vdyVelMonExec) \n VDYFSData->FSMonErrorStates.FSIntExtVeloCheck = proPorts->pVDYErrors->OutPutErrors.VelMonLt;
		else (NO)
			:VDYFSData->FSMonErrorStates.FSIntExtVeloCheck = VDY_ERR_STATE_UNKNOWN;
		endif
		if ( defined(CFG_VDY_DO_VELOCITY_CORR) && (CFG_VDY_DO_VELOCITY_CORR) ) then (YES)
			:this error was determined by the velo corr module \n VDYFSData->FSMonErrorStates.FSCorrVeloCheck = proPorts->pVDYErrors->OutPutErrors.VelCorrRg;
		else (NO)
			:VDYFSData->FSMonErrorStates.FSCorrVeloCheck = VDY_ERR_STATE_UNKNOWN;
		endif
		if ((defined(CFG_VDY_FS_VELO_CORR_MON)) && (CFG_VDY_FS_VELO_CORR_MON)) then (YES)
			if (If the fast velocity monitor detects a fault, raise correction factor variance to inhibit CMS reactions \n (proPorts->pVDYErrors->OutPutErrors.VDY_FS_VEH_CORR_MON == VDY_ERR_STATE_ACTIVE)) then (YES)
				:proPorts->pVehicleDynamicSignals->Longitudinal.varVelocity = 100.0F;
			endif
		endif
	stop
	@enduml

  @testmethod			- Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_mon.c -> TEST_vdyFSVelocityMonitoring_001()
	- Algo Req Test
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-733-0002220d
  @traceability			 
  - L3
    - doors://RBGS854A:40000/?version=2&prodID=0&view=000000b9&urn=urn:telelogic::1-503e822e5ec3651e-O-1301-000221c8
  - L4
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-640-00026448
**************************************************************************** */
STATIC_MTD void vdyFSVelocityMonitoring(const proVdyPrtList_t *proPorts, VDYFSData_t *VDYFSData);


/* **********************************************************************
  @fn               vdyFSYawRateMonitoring */ /*!
  @brief           Functional safety yaw rate monitoring

  @description     While driving straight the difference between the internal yaw rates
                   are checked
                   Sets FuSi related output faults if differences were detected
                   over a defined distance

  @return          static void

  @param[in]       *IntData : VDY Internal Data
  @param[in]       *proPorts : Provide Port
  @param[in]       *VDYModIf : VDY Module Interface Data
  @param[in,out]   *VDYFSData : VDY Functional Safety Data

  @c_switch_part   
				  - CFG_VDY_DIS_LAT_ACCEL_SENSOR_PRE_PROCESSING : Disables the lateral acceleration sensor pre processing, 
																			   - lateral sensor offset estimation
																			   - yaw rate from lateral acceleration sensor estimation
				  - CFG_VDY_DIS_WHEEL_PRE_PROCESSING : Disables the wheel speed pre processing, 
																	- wheel offset estimation
																	- wheel velocity <-> puls fusion
																	- vehicle speed estimation
																	- wheel load dependancy estimation
																	- dynamic (drift) sensor yaw rate offset estimation
																	- wheel velocity yaw rate estimation
				  - CFG_VDY_DIS_STW_ANGLE_SENSOR_PRE_PROCESSING : Disables the steering wheel angle sensor pre processing, 
																			   - steering wheel angle sensor offset estimation
																			   - estimation of self steering gradient
																			   - driver intended curvature
																			   - yaw rate from steering wheel sensor estimation
  @c_switch_full   None 

  @pre             None
  @post            No changes
  @InOutCorrelation
  
  @startuml
  start
	if ( (!defined(CFG_VDY_DIS_LAT_ACCEL_SENSOR_PRE_PROCESSING)) || (!CFG_VDY_DIS_LAT_ACCEL_SENSOR_PRE_PROCESSING) ) then (YES)
		:fDeltaDist = IntData->vdy_ve_out.veh_velo * VDYModIf->CycleTime;
	endif
	if (( (!defined(CFG_VDY_DIS_WHEEL_PRE_PROCESSING)) || (!CFG_VDY_DIS_WHEEL_PRE_PROCESSING) ) && (CFG_VDY_FS_YR_VS_WSP_ENABLE)) then (YES)
		:threshold velocities, above yaw rate error monitoring is active, curve threshold, only below this the yaw rate is monitored \n vdyFSMonitorWheelYawRate(IntData, proPorts, VDYModIf, VDYFSData);
	else (NO)
		:proPorts->pVDYErrors->OutPutErrors.VDY_FS_YR_VS_WSP = VDY_ERR_STATE_UNKNOWN;
	endif
	if ( (!defined(CFG_VDY_DIS_LAT_ACCEL_SENSOR_PRE_PROCESSING)) || (!CFG_VDY_DIS_LAT_ACCEL_SENSOR_PRE_PROCESSING) ) then (YES)
		if ( Is the vehicle velocity above the yaw rate velocity, Is the curve threshold below this the yaw rate  \n ((CML_f_Abs(IntData->vdy_ye_out.veh_merge_curve_grad) <= MAX_CURVE_GRAD) && (IntData->vdy_ve_out.veh_velo >= MIN_LAT_ACCEL_YAW_RATE_VELOCITY) ) ) then (YES)
			:VDYFSData->VDYFSYawRateCheck.fYawLatAccelDelta = IntData->vdy_gye_out.gier_yaw_rate-IntData->vdy_aye_out.ay_yaw_rate;
			:add the delta value to the statistic data \n  vdyStatIntervalAdd(&(VDYFSData->VDYFSCurveCheck.VDYFSAyeGyeStat),VDYFSData->VDYFSYawRateCheck.fYawLatAccelDelta,fDeltaDist);
			if ( Check if above threshold \n (CML_f_Abs(VDYFSData->VDYFSYawRateCheck.fYawLatAccelDelta) >VDY_FS_LAT_ACCEL_YAW_RATE_THRESHOLD)) then (YES)
				:VDYFSData->VDYFSYawRateCheck.fYawLatAccelOutDist += fDeltaDist;
			else (NO)
				:VDYFSData->VDYFSYawRateCheck.fYawLatAccelOutDist = VDY_ZERO_F;
			endif
		else (NO)
			:VDYFSData->VDYFSYawRateCheck.fYawLatAccelOutDist = VDY_ZERO_F;
		endif
		:set the error state;
		if (VDYFSData->VDYFSYawRateCheck.fYawLatAccelOutDist > VDY_FS_YAW_RATE_DIST_THRESHOLD) then (YES)
			if (  (proPorts->pVDYErrors->OutPutErrors.VDY_FS_YR_VS_AY == (VDYErrState_t)VDY_ERR_STATE_INACTIVE) ||(proPorts->pVDYErrors->OutPutErrors.VDY_FS_YR_VS_AY == (VDYErrState_t)VDY_ERR_STATE_UNKNOWN)) then (YES)
				:increase occurence counter, only used for fault analysis, overrun used to continue counting \n VDYFSData->VDYFSYawRateCheck.nLatAccelErrorCounter++;
			endif
			:proPorts->pVDYErrors->OutPutErrors.VDY_FS_YR_VS_AY  = VDY_ERR_STATE_ACTIVE;
		else
			:proPorts->pVDYErrors->OutPutErrors.VDY_FS_YR_VS_AY = VDY_ERR_STATE_INACTIVE;
		endif
	else (NO)
		:proPorts->pVDYErrors->OutPutErrors.VDY_FS_YR_VS_AY = VDY_ERR_STATE_UNKNOWN;
	endif
	if ( (!defined(CFG_VDY_DIS_STW_ANGLE_SENSOR_PRE_PROCESSING)) || (!CFG_VDY_DIS_STW_ANGLE_SENSOR_PRE_PROCESSING) ) then (YES) 
		if (    (CML_f_Abs(IntData->vdy_ye_out.veh_merge_curve_grad) <= MAX_CURVE_GRAD) && (IntData->vdy_ve_out.veh_velo >= MIN_SWA_YAW_RATE_VELOCITY)) then (YES)
			:VDYFSData->VDYFSYawRateCheck.fYawSteerDelta = IntData->vdy_gye_out.gier_yaw_rate-IntData->vdy_sye_out.stw_yaw_rate;
			:add the delta value to the statistic data \n vdyStatIntervalAdd(&(VDYFSData->VDYFSCurveCheck.VDYFSSyeGyeStat),VDYFSData->VDYFSYawRateCheck.fYawSteerDelta,fDeltaDist);
			if ( Check if above threshold \n CML_f_Abs(VDYFSData->VDYFSYawRateCheck.fYawSteerDelta) > VDY_FS_SWA_YAW_RATE_THRESHOLD) then (YES)
				:VDYFSData->VDYFSYawRateCheck.fYawSteerOutDist += fDeltaDist;
			else (NO)
				:VDYFSData->VDYFSYawRateCheck.fYawSteerOutDist = VDY_ZERO_F;
			endif
		else (NO)
			:VDYFSData->VDYFSYawRateCheck.fYawSteerOutDist = VDY_ZERO_F;
		endif
		:set the error state;
		if (VDYFSData->VDYFSYawRateCheck.fYawSteerOutDist > VDY_FS_YAW_RATE_DIST_THRESHOLD) then (YES)
			if (  (proPorts->pVDYErrors->OutPutErrors.VDY_FS_YR_VS_SWA == (VDYErrState_t)VDY_ERR_STATE_INACTIVE) ||(proPorts->pVDYErrors->OutPutErrors.VDY_FS_YR_VS_SWA == (VDYErrState_t)VDY_ERR_STATE_UNKNOWN)) then (YES)
				:VDYFSData->VDYFSYawRateCheck.nSwaErrorCounter++;
			else
				:proPorts->pVDYErrors->OutPutErrors.VDY_FS_YR_VS_SWA = VDY_ERR_STATE_ACTIVE;
			endif
		else (NO)
			:proPorts->pVDYErrors->OutPutErrors.VDY_FS_YR_VS_SWA = VDY_ERR_STATE_INACTIVE;
		endif
	else
		:proPorts->pVDYErrors->OutPutErrors.VDY_FS_YR_VS_SWA = VDY_ERR_STATE_UNKNOWN;
	endif
  stop
  @enduml

  @testmethod		- Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_mon.c ->	 \n
                            TEST_vdyFSYawRateMonitoring_001(), \n
                            TEST_vdyFSYawRateMonitoring_002(), \n
                            TEST_vdyFSYawRateMonitoring_003(), \n
                            TEST_vdyFSYawRateMonitoring_004(), \n
                            TEST_vdyFSYawRateMonitoring_005(), \n
                            TEST_vdyFSYawRateMonitoring_006()

  @traceability			  
  - L3
    - doors://RBGS854A:40000/?version=2&prodID=0&view=000000b9&urn=urn:telelogic::1-503e822e5ec3651e-O-1305-000221c8
  - L4
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-648-00026448
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-649-00026448
**************************************************************************** */
STATIC_MTD void vdyFSYawRateMonitoring(const VDYInternalData_t *IntData, const proVdyPrtList_t *proPorts, const VDYModIf_t *VDYModIf, VDYFSData_t *VDYFSData);


/* **********************************************************************
  @fn               vdyFSCalcDeltaYawRate */ /*!
  @brief           Functional safety, calculate the delta yaw rate need by the curve prediction monitoring

  @description     Updates yaw rate data for lateral acceleration, steering wheel and wheels
                   If one yaw rate was collected over a defined distance, the overall statistic data
                   is calculated and the curve prediction fault is calculated
                   If the difference is above a fault threshold, a delta counter is increased

  @return          static void

  @param[in,out]   *VDYFSData : VDY Functional Safety Data
  @param[in]       *IntData : Internal Data

  @c_switch_part   None 
  @c_switch_full   None 

  @pre             None
  @post            No changes
  @InOutCorrelation
					  - Check if the WyeGye, AyeGye and SyeGye intervall is above volume threshold to calc the mean/std and reduce the intervall
					  - If yes,
						- calculate the overall mean and std
						- Calculate the curve prediction error
						- Check if DeltaY is above threshold and increment counters otherwise reset the counter. 
  
	@startuml
	start
		:bCalcOverAll = FALSE;
		if (check if the WyeGye interval is above volume threshold to calc the mean/std and reduce the intervall \n VDYFSData->VDYFSCurveCheck.VDYFSWyeGyeStat.Volume >= VDY_FS_MEAN_DRIVE_DISTANCE) then (YES)
			:vdyStatIntervalMeanDev(&(VDYFSData->VDYFSCurveCheck.VDYFSWyeGyeStat));
			:vdyStatIntervalReduce(&(VDYFSData->VDYFSCurveCheck.VDYFSWyeGyeStat),VDY_FS_DISTANCE_REDUCE_FACTOR);
			:bCalcOverAll = TRUE;
		endif
		if (check if the AyeGye interval is above volume threshold to calc the mean/std and reduce the interval \n VDYFSData->VDYFSCurveCheck.VDYFSAyeGyeStat.Volume >= VDY_FS_MEAN_DRIVE_DISTANCE) then (YES)
			:vdyStatIntervalMeanDev(&(VDYFSData->VDYFSCurveCheck.VDYFSAyeGyeStat));
			:vdyStatIntervalReduce(&(VDYFSData->VDYFSCurveCheck.VDYFSAyeGyeStat),VDY_FS_DISTANCE_REDUCE_FACTOR);
			:bCalcOverAll = TRUE;
		endif
		if (check if the SyeGye interval is above volume threshold to calc the mean/std and reduce the interval \n VDYFSData->VDYFSCurveCheck.VDYFSSyeGyeStat.Volume >= VDY_FS_MEAN_DRIVE_DISTANCE) then (YES)
			:vdyStatIntervalMeanDev(&(VDYFSData->VDYFSCurveCheck.VDYFSSyeGyeStat));
			:vdyStatIntervalReduce(&(VDYFSData->VDYFSCurveCheck.VDYFSSyeGyeStat),VDY_FS_DISTANCE_REDUCE_FACTOR);
			:bCalcOverAll = TRUE;
		endif
		if (bCalcOverAll == TRUE) then (YES)
			:calculate the overall mean and std
				vdyStatIntervalInit(&(VDYFSData->VDYFSCurveCheck.VDYFSAllOverIntervall))
				vdyStatIntervalAdd(&(VDYFSData->VDYFSCurveCheck.VDYFSAllOverIntervall), VDYFSData->VDYFSCurveCheck.VDYFSWyeGyeStat.Mean, VDY_WYE_CURVECHECK_WEIGHT)
				vdyStatIntervalAdd(&(VDYFSData->VDYFSCurveCheck.VDYFSAllOverIntervall), VDYFSData->VDYFSCurveCheck.VDYFSAyeGyeStat.Mean, VDY_AYE_CURVECHECK_WEIGHT)
				vdyStatIntervalAdd(&(VDYFSData->VDYFSCurveCheck.VDYFSAllOverIntervall), VDYFSData->VDYFSCurveCheck.VDYFSSyeGyeStat.Mean, VDY_SYE_CURVECHECK_WEIGHT)
				vdyStatIntervalMeanDev(&(VDYFSData->VDYFSCurveCheck.VDYFSAllOverIntervall));
			: Calculate the curve prediction error \n VDYFSData->VDYFSCurveCheck.fDeltaY = VDY_FIFTY_CENT * IntData->vdy_ve_out.veh_velo*VDY_FS_PRED_HORZ_TIME*VDY_FS_PRED_HORZ_TIME*VDYFSData->VDYFSCurveCheck.VDYFSAllOverIntervall.Mean;
			if ( Check if DeltaY is above threshold and exeed counters \n (VDYFSData->VDYFSCurveCheck.fDeltaY >= VDY_FS_MAX_LAT_DIST_ERROR) && 
				(VDYFSData->VDYFSCurveCheck.nDeltaYCounter <= (uint8)(VDY_FS_MAX_LAT_DIST_COUNTER)) ) then (YES)
				:VDYFSData->VDYFSCurveCheck.nDeltaYCounter++;
			else (NO)
				:VDYFSData->VDYFSCurveCheck.nDeltaYCounter = 0U;
			endif
		endif
	stop
	@enduml
  @testmethod			  
  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_mon.c -> \n
                            TEST_vdyFSCalcDeltaYawRate_001(), \n
                            TEST_vdyFSCalcDeltaYawRate_002(), \n
                            TEST_vdyFSCalcDeltaYawRate_003(), \n
                            TEST_vdyFSCalcDeltaYawRate_004()
  @traceability			  
  - L3
    - doors://RBGS854A:40000/?version=2&prodID=0&view=000000b9&urn=urn:telelogic::1-503e822e5ec3651e-O-1305-000221c8
  - L4
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-647-00026448
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-648-00026448
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-649-00026448
**************************************************************************** */
STATIC_MTD void vdyFSCalcDeltaYawRate(VDYFSData_t *VDYFSData, const VDYInternalData_t *IntData);

/* **********************************************************************
  @fn               vdyFSCurvePredictionMonitoring */ /*!
  @brief           Functional safety curve prediction monitoring

  @description     Sets fault if curve prediction delta counter is above theshold
                   see vdyFSCalcDeltaYawRate() for delta counter calculation

  @return          static void

  @param[in]       *IntData : VDY Internal Data
  @param[in,out]   *VDYFSData : VDY Functional Safety Data

  @c_switch_part   None 
  @c_switch_full   None 

  @pre             None
  @post            No changes
  @InOutCorrelation
				  - Caculate the yaw rate delta
				  - Check if error condition is valid 
					- if yes, set error otherwise reset error
	@startuml
	start
		:Caculate the yaw rate delta \n vdyFSCalcDeltaYawRate(VDYFSData, IntData);
		if ( Check if error condition is valid \n (VDYFSData->VDYFSCurveCheck.nDeltaYCounter >= (uint8)(VDY_FS_MAX_LAT_DIST_COUNTER)) ) then (YES)
			if (  (VDYFSData->FSMonErrorStates.FSMaxLatDisplacementError == (VDYErrState_t)VDY_ERR_STATE_INACTIVE) ||
				(VDYFSData->FSMonErrorStates.FSMaxLatDisplacementError == (VDYErrState_t)VDY_ERR_STATE_UNKNOWN)) then (YES)
				:VDYFSData->VDYFSCurveCheck.nCurveErrorCounter++;
			endif
			:VDYFSData->FSMonErrorStates.FSMaxLatDisplacementError = VDY_ERR_STATE_ACTIVE;
		else (NO)
			:VDYFSData->FSMonErrorStates.FSMaxLatDisplacementError = VDY_ERR_STATE_INACTIVE;
		endif
	stop
	@enduml
  @testmethod			  
	- Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_mon.c -> \n
                            TEST_vdyFSCurvePredictionMonitoring_001(), \n
                            TEST_vdyFSCurvePredictionMonitoring_002(), \n
                            TEST_vdyFSCurvePredictionMonitoring_003()
  @traceability			  
  - L3
    - NA
  - L4
    - NA
**************************************************************************** */
STATIC_MTD void vdyFSCurvePredictionMonitoring(const VDYInternalData_t *IntData, VDYFSData_t *VDYFSData);
#endif

#if ( (    (!(defined(CFG_VDY_DIS_FUNCTIONAL_SAFETY_MON) && (CFG_VDY_DIS_FUNCTIONAL_SAFETY_MON))) \
      && ( (!defined(CFG_VDY_DIS_WHEEL_PRE_PROCESSING)) || (!CFG_VDY_DIS_WHEEL_PRE_PROCESSING) )) \
      && (CFG_VDY_FS_YR_VS_WSP_ENABLE) )
/* **********************************************************************
  @fn               vdyFSMonitorWheelYawRate */ /*!
  @brief           Monitors wheel yaw rate distance

  @description     If the wheel yaw rate become greater than the threashold,
                   the yaw rate out of bounce error becomes active

  @return          static void

  @param[in]       *pIntData : 
  @param[in]       *proPorts : 
  @param[in]       *pVDYModIf : 
  @param[in,out]   *pVDYFSData : 

  @c_switch_part   None 
  @c_switch_full   CFG_VDY_DIS_WHEEL_PRE_PROCESSING : Disables the wheel speed pre processing, 
                                                    - wheel offset estimation
                                                    - wheel velocity <-> puls fusion
                                                    - vehicle speed estimation
                                                    - wheel load dependancy estimation
                                                    - dynamic (drift) sensor yaw rate offset estimation
                                                    - wheel velocity yaw rate estimation 

  @pre             None
  @post            No changes
  @InOutCorrelation		  - 
  
  @testmethod			  
	- Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_mon.c -> \n
                            TEST_vdyFSMonitorWheelYawRate_001(), \n
                            TEST_vdyFSMonitorWheelYawRate_002(), \n
                            TEST_vdyFSMonitorWheelYawRate_003(), \n
                            TEST_vdyFSMonitorWheelYawRate_004(), \n
                            TEST_vdyFSMonitorWheelYawRate_005(), \n
                            TEST_vdyFSMonitorWheelYawRate_006(), \n
                            TEST_vdyFSMonitorWheelYawRate_007()
  @traceability			  
  - L3
    - doors://RBGS854A:40000/?version=2&prodID=0&view=000000b9&urn=urn:telelogic::1-503e822e5ec3651e-O-1305-000221c8
  - L4
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-647-00026448
  @author           Witek Konarski
**************************************************************************** */
STATIC_MTD void vdyFSMonitorWheelYawRate(const VDYInternalData_t *pIntData, const proVdyPrtList_t *proPorts, const VDYModIf_t *pVDYModIf, VDYFSData_t *pVDYFSData);
#endif

#if (CFG_VDY_USE_VELO_MONITOR)	
/* **********************************************************************
  @fn               vdyVelMon */ /*!
  @brief           Monitors velocity for faults

  @description     Compares externally provided velocity against velocity
                   calculated internally from wheel speeds
                   Checks result of fast velocity monitoring
                   Sets output fault states correspondingly

  @return          static void

  @param[in]       *in : 
  @param[in]       *ve : 
  @param[in,out]   *pErr : 

  @glob_in         None 
  @glob_out        VMON_GET_ME : velocity monitor data

  @c_switch_part   None 
  @c_switch_full   CFG_VDY_USE_VELO_MONITOR : Enables monitoring of external vehicle velocity. The velocity is compared with estimated 
                                              velocity based on wheel speeds 
  
	@startuml
	start
		:incErrCnt_c = 1U;
		:decErrCnt_c = 1U;
		:ratThrhd_c = 0.01F;
		:lastVeloVar = VDY_ZERO_F;
		:*pVelMon = VMON_GET_ME
		:Default output error states \n pErr->OutPutErrors.VelMon   = VDY_ERR_STATE_UNKNOWN \n pErr->OutPutErrors.VelMonLt = VDY_ERR_STATE_UNKNOWN;
		if (Monitoring only active when signal is valid \n VDY_GET_IO_STATE(VDY_SIN_POS_VEHVEL_EXT, in->State) == VDY_IO_STATE_VALID ) then (YES)
			:velDiff = in->VehVelocityExt - ve->veh_velo;
			if (ve->veh_velo_var < VDY_ZERO_F) then (YES)
				:uncVel  = VDY_FOUR_F * VDY_SQRT(lastVeloVar);
			else (NO)
				:uncVel  = VDY_FOUR_F * VDY_SQRT(ve->veh_velo_var);
				:lastVeloVar = ve->veh_velo_var;
			endif
			if ( if external velocity is outside of estimated velocity range, increment error count \n (CML_f_Abs(velDiff) - uncVel) > (ve->veh_velo * ratThrhd_c) ) then (YES)
				:pVelMon->cntOutSide += incErrCnt_c;
			else (NO)
				:decrement error count \n pVelMon->cntOutSide = (pVelMon->cntOutSide > decErrCnt_c) ? (pVelMon->cntOutSide - decErrCnt_c) : 0U;
			endif
			if ( test counter thresholds \n pVelMon->cntOutSide >= VDY_PAR_VMON_CYCLE_OUT_LT) then (YES)
				:Counter above long-term limit \n pVelMon->cntOutSide = MIN(pVelMon->cntOutSide, VDY_PAR_VMON_CYCLE_OUT_LT + VDY_TWO_U) \n pErr->OutPutErrors.VelMon   = VDY_ERR_STATE_INACTIVE \n pErr->OutPutErrors.VelMonLt = VDY_ERR_STATE_ACTIVE;
			else if (pVelMon->cntOutSide >= VDY_PAR_VMON_CYCLE_OUT) then (YES)
				:Counter above short limit \n pErr->OutPutErrors.VelMon   = VDY_ERR_STATE_ACTIVE \n pErr->OutPutErrors.VelMonLt = VDY_ERR_STATE_INACTIVE;
			else (NO)
				:pErr->OutPutErrors.VelMon   = VDY_ERR_STATE_INACTIVE \n pErr->OutPutErrors.VelMonLt = VDY_ERR_STATE_INACTIVE;
			endif
		endif
			:return;
	stop
	@enduml

  @pre             None
  @post            No changes
  @InOutCorrelation		  - 
  
  @testmethod			  
	- Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_mon.c -> \n
                            TEST_vdyVelMon_001(), \n
                            TEST_vdyVelMon_002(), \n
                            TEST_vdyVelMon_003(), \n
                            TEST_vdyVelMon_004(), \n
                            TEST_vdyVelMon_005(), \n
                            TEST_vdyVelMon_006()

  @traceability			  
  - L3
    - doors://RBGS854A:40000/?version=2&prodID=0&view=000000b9&urn=urn:telelogic::1-503e822e5ec3651e-O-1301-000221c8  
  - L4
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-640-00026448
**************************************************************************** */
STATIC_MTD void vdyVelMon(const VehSigMain_t *in, const vdy_ve_out_t *ve, VDYErrors_t *pErr);
#endif

/* **********************************************************************
  @fn               vdyMonitorInputSignals */ /*!
  @brief           Monitor input signals and parameters

  @description     Does plausibility check of wheel speeds and vehicle velocity
                   (they might be set to a negative value, so the absolute values are used)
                   Checks the ranges of these input signals:
                   -yaw rate
                   -steering wheel angle
                   -all 4 wheel velocities
                   -lateral acceleration
                   -longitudinal acceleration
                   -vehicle velocity
                   If there is a range violation, the signal is limited
                   to the maximum allowed value, a SignalFault is set and
                   the corresponding signals set to degraded state

  @return          static void

  @param[in,out]   *input : Current Input Data
  @param[in,out]   *VDYErrors : VDY Error Signals

  @c_switch_part   
						  - CFG_VDY_DIS_STW_ANGLE_SENSOR_PRE_PROCESSING : Disables the steering wheel angle sensor pre processing, 
																					   - steering wheel angle sensor offset estimation
																					   - estimation of self steering gradient
																					   - driver intended curvature
																					   - yaw rate from steering wheel sensor estimation
						  - CFG_VDY_DIS_WHEEL_PRE_PROCESSING : Disables the wheel speed pre processing, 
																			- wheel offset estimation
																			- wheel velocity <-> puls fusion
																			- vehicle speed estimation
																			- wheel load dependancy estimation
																			- dynamic (drift) sensor yaw rate offset estimation
																			- wheel velocity yaw rate estimation 
						  - CFG_VDY_USE_EX_LONG_VELO : Use external provided longitudinal velocity signal
						  - CFG_VDY_USE_EX_LONG_ACCEL : Use external provided longitudinal acceleration signal
						  - CFG_VDY_BMW_LONG_ACCEL_MODEL : Enables the new Long Accel estimation method only for BMW projects
						  - CFG_VDY_DIS_LAT_ACCEL_SENSOR_PRE_PROCESSING : Disables the lateral acceleration sensor pre processing, 
																					   - lateral sensor offset estimation
																					   - yaw rate from lateral acceleration sensor estimation
  @c_switch_full   None 

  @pre             None
  @post            No changes
  @InOutCorrelation
					  - Check if Signals are valid and Check if allowed maximum value is exceeded
						- yaw rate
						- steering angle
						- wheel velocity front left
						- wheel velocity front right
						- wheel velocity rear left
						- wheel velocity rear right
						- External vehicle velocity
						- External longitudinal acceleration
						- lateral acceleration
					  - Set signal error status, Active / Inactive, in input signal struct
  

	@startuml
	start
		:SignalError = VDY_STAT_INACTIVE;
		if ( Yaw Rate \n VDY_GET_IO_STATE(VDY_SIN_POS_YWR, input->Signals.State) == VDY_IO_STATE_VALID) then (YES)
			if ( Check if allowed maximum value is exceeded \n input->Signals.YawRate > MAX_YAWRATE) then (YES)
				:SignalError = VDY_STAT_ACTIVE;
				:input->Signals.YawRate = MAX_YAWRATE;
				:VDY_SET_IO_STATE(VDY_SIN_POS_YWR, VDY_IO_STATE_SUBSTITUE, input->Signals.State);
			else if (input->Signals.YawRate < -MAX_YAWRATE) then (YES)
				:SignalError = VDY_STAT_ACTIVE;
				:input->Signals.YawRate = -MAX_YAWRATE;
				:VDY_SET_IO_STATE(VDY_SIN_POS_YWR, VDY_IO_STATE_SUBSTITUE, input->Signals.State);
			else (NO)
			endif
		endif

		if ( Check steering angle if CFG_VDY_DIS_STW_ANGLE_SENSOR_PRE_PROCESSING is disabled ) then (YES)
			if (VDY_GET_IO_STATE(VDY_SIN_POS_SWA, input->Signals.State) == VDY_IO_STATE_VALID) then (YES)
				if ( Check if allowed maximum value is exceeded \n input->Signals.StWheelAngle > (MAX_STEERING_ANGLE * input->Parameter.SteeringRatio.swa.rat[1]) )then (YES)
					:SignalError = VDY_STAT_ACTIVE
					:input->Signals.StWheelAngle = (MAX_STEERING_ANGLE * input->Parameter.SteeringRatio.swa.rat[1]);
					:VDY_SET_IO_STATE(VDY_SIN_POS_SWA, VDY_IO_STATE_SUBSTITUE, input->Signals.State);
				else if (input->Signals.StWheelAngle < -(MAX_STEERING_ANGLE * input->Parameter.SteeringRatio.swa.rat[1])) then (YES)
					:SignalError = VDY_STAT_ACTIVE;
					:input->Signals.StWheelAngle = -(MAX_STEERING_ANGLE * input->Parameter.SteeringRatio.swa.rat[1]);
					:VDY_SET_IO_STATE(VDY_SIN_POS_SWA, VDY_IO_STATE_SUBSTITUE, input->Signals.State);
				else (NO)
				endif
			endif
		endif

		if ( Check Rear steering angle then CFG_VDY_REAR_WHEEL_STEERING enabled) the (YES)
			if (VDY_GET_IO_STATE(VDY_SIN_POS_RSTA, input->Signals.State) == VDY_IO_STATE_VALID ) then (YES)
				if (Check if allowed maximum value is exceeded \n input->Signals.RearWhlAngle > (MAX_STEERING_ANGLE * input->Parameter.SteeringRatio.swa.rat[1])) then (YES)
					:SignalError = VDY_STAT_ACTIVE;
					:input->Signals.RearWhlAngle = (MAX_STEERING_ANGLE * input->Parameter.SteeringRatio.swa.rat[1]);
					:VDY_SET_IO_STATE(VDY_SIN_POS_RSTA, VDY_IO_STATE_SUBSTITUE, input->Signals.State);
				else if (input->Signals.RearWhlAngle < -(MAX_STEERING_ANGLE * input->Parameter.SteeringRatio.swa.rat[1])) then (YES)
					:SignalError = VDY_STAT_ACTIVE;
					:input->Signals.RearWhlAngle = -(MAX_STEERING_ANGLE * input->Parameter.SteeringRatio.swa.rat[1]);
					:VDY_SET_IO_STATE(VDY_SIN_POS_RSTA, VDY_IO_STATE_SUBSTITUE, input->Signals.State);
				else (NO)
				endif
			endif
		endif

		if (Check wheel velocities if CFG_VDY_DIS_WHEEL_PRE_PROCESSING is enabled) then (YES)
			:wheel velocity front left;
			if (input->Signals.WhlVelFrLeft < VDY_ZERO_F) then (YES)
				:input->Signals.WhlVelFrLeft = -(input->Signals.WhlVelFrLeft);
			endif
			if ((sint32)VDY_GET_IO_STATE(VDY_SIN_POS_WVEL_FL, input->Signals.State) == VDY_IO_STATE_VALID) then (YES)
				if (input->Signals.WhlVelFrLeft > MAX_VELOCITY) then (YES)
					:input->Signals.WhlVelFrLeft = MAX_VELOCITY;
					:SignalError = VDY_STAT_ACTIVE;
					:VDY_SET_IO_STATE(VDY_SIN_POS_WVEL_FL, VDY_IO_STATE_SUBSTITUE, input->Signals.State);
				endif
			endif			
			:wheel velocity front right;
			if (input->Signals.WhlVelFrRight < VDY_ZERO_F) then (YES)
				:input->Signals.WhlVelFrRight = -(input->Signals.WhlVelFrRight);
			endif
			if ((sint32)VDY_GET_IO_STATE(VDY_SIN_POS_WVEL_FR, input->Signals.State) == VDY_IO_STATE_VALID)  then (YES)
				if (input->Signals.WhlVelFrRight > MAX_VELOCITY) then (YES)
					:input->Signals.WhlVelFrRight = MAX_VELOCITY;
					:SignalError = VDY_STAT_ACTIVE;
					:VDY_SET_IO_STATE(VDY_SIN_POS_WVEL_FR, VDY_IO_STATE_SUBSTITUE, input->Signals.State);
				endif
			endif			
			:wheel velocity rear left;
			if (input->Signals.WhlVelReLeft < VDY_ZERO_F) then (YES)
				:input->Signals.WhlVelReLeft = -(input->Signals.WhlVelReLeft);
			endif
			if ((sint32)VDY_GET_IO_STATE(VDY_SIN_POS_WVEL_RL, input->Signals.State) == VDY_IO_STATE_VALID)  then (YES)
				if (input->Signals.WhlVelReLeft > MAX_VELOCITY) then (YES)
					:input->Signals.WhlVelReLeft = MAX_VELOCITY;
					:SignalError = VDY_STAT_ACTIVE;
					:VDY_SET_IO_STATE(VDY_SIN_POS_WVEL_RL, VDY_IO_STATE_SUBSTITUE, input->Signals.State);
				endif
			endif
			:wheel velocity rear right;
			if(input->Signals.WhlVelReRight < VDY_ZERO_F)  then (YES)
				:input->Signals.WhlVelReRight = -(input->Signals.WhlVelReRight);
			endif
			if ((sint32)VDY_GET_IO_STATE(VDY_SIN_POS_WVEL_RR, input->Signals.State) == VDY_IO_STATE_VALID) then (YES)
				if (input->Signals.WhlVelReRight > MAX_VELOCITY) then (YES)
					:input->Signals.WhlVelReRight = MAX_VELOCITY;
					:SignalError = VDY_STAT_ACTIVE;
					:VDY_SET_IO_STATE(VDY_SIN_POS_WVEL_RR, VDY_IO_STATE_SUBSTITUE, input->Signals.State);
				endif
			endif
		endif
		:Section A;
		stop
	@enduml
- Section A
	@startuml
	start
		if(in case algo is using external velocity and CFG_VDY_USE_EX_LONG_VELO is enabled then Check vehicle velocity) then (YES)
			:input->Signals.VehVelocityExt = CML_u_Abs(input->Signals.VehVelocityExt);
			if (VDY_GET_IO_STATE(VDY_SIN_POS_VEHVEL_EXT, input->Signals.State) == VDY_IO_STATE_VALID) then (YES)
				if ( Check if allowed maximum value is exceeded \n input->Signals.VehVelocityExt > MAX_VELOCITY)
					:input->Signals.VehVelocityExt = MAX_VELOCITY;
					:SignalError = VDY_STAT_ACTIVE;
					:VDY_SET_IO_STATE(VDY_SIN_POS_VEHVEL_EXT, VDY_IO_STATE_SUBSTITUE, input->Signals.State);
				endif
			endif
		endif
		if (in case algo is using external acceleration and CFG_VDY_USE_EX_LONG_ACCEL is enabled then Check vehicle longitudinal acceleration) then (YES)
			if ((sint32)VDY_GET_IO_STATE(VDY_SIN_POS_VEHACL_EXT, input->Signals.State) == VDY_IO_STATE_VALID) then (YES)
				if ( Check if allowed maximum value is exceeded \ninput->Signals.VehLongAccelExt > MAX_ACCELERATION) then (YES)
					:SignalError = VDY_STAT_ACTIVE;
					:input->Signals.VehLongAccelExt = MAX_ACCELERATION;
					:VDY_SET_IO_STATE(VDY_SIN_POS_VEHACL_EXT, VDY_IO_STATE_SUBSTITUE, input->Signals.State);
				endif
				if (input->Signals.VehLongAccelExt < -MAX_ACCELERATION) then (YES)
					:SignalError = VDY_STAT_ACTIVE;
					:input->Signals.VehLongAccelExt = -MAX_ACCELERATION;
					:VDY_SET_IO_STATE(VDY_SIN_POS_VEHACL_EXT, VDY_IO_STATE_SUBSTITUE, input->Signals.State);
				endif
			endif
		endif
		if ( Check lateral acceleration in case CFG_VDY_DIS_LAT_ACCEL_SENSOR_PRE_PROCESSING is disabled ) then (YES)
			if ((sint32)VDY_GET_IO_STATE(VDY_SIN_POS_LATA, input->Signals.State) == VDY_IO_STATE_VALID)  then (YES)
				if (Check if allowed maximum value is exceeded \n input->Signals.LatAccel > MAX_ACCELERATION)  then (YES)
					:SignalError = VDY_STAT_ACTIVE;
					:input->Signals.LatAccel = MAX_ACCELERATION;
					:VDY_SET_IO_STATE(VDY_SIN_POS_LATA, VDY_IO_STATE_SUBSTITUE, input->Signals.State);
				endif
				if (input->Signals.LatAccel < -MAX_ACCELERATION)  then (YES)
					:SignalError = VDY_STAT_ACTIVE;
					:input->Signals.LatAccel = -MAX_ACCELERATION;
					:VDY_SET_IO_STATE(VDY_SIN_POS_LATA, VDY_IO_STATE_SUBSTITUE, input->Signals.State);
				endif
			endif
		endif
		if (Set signal error in input signal struct \n SignalError == VDY_STAT_ACTIVE) then (YES)
			:VDYErrors->SignalInputErrors.InputSignalError = VDY_ERR_STATE_ACTIVE;
		else (NO)
			:VDYErrors->SignalInputErrors.InputSignalError = VDY_ERR_STATE_INACTIVE;
		endif
	stop
	@enduml
  @testmethod			  
	- Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_mon.c -> \n
                            TEST_vdyMonitorInputSignals_001(), \n
                            TEST_vdyMonitorInputSignals_002(), \n
                            TEST_vdyMonitorInputSignals_003(), \n
                            TEST_vdyMonitorInputSignals_004(), \n
                            TEST_vdyMonitorInputSignals_005(), \n
                            TEST_vdyMonitorInputSignals_006()
  @traceability			  
  - L3
    - Yaw Rate					
      - doors://RBGS854A:40000/?version=2&prodID=0&view=000000b9&urn=urn:telelogic::1-503e822e5ec3651e-O-1404-000221c8 
    - SWA						
      - doors://RBGS854A:40000/?version=2&prodID=0&view=000000b9&urn=urn:telelogic::1-503e822e5ec3651e-O-1405-000221c8 
    - Rear Steering				
      - doors://RBGS854A:40000/?version=2&prodID=0&view=000000b9&urn=urn:telelogic::1-503e822e5ec3651e-O-1726-000221c8 
    - 4 wheel speeds			
      - doors://RBGS854A:40000/?version=2&prodID=0&view=000000b9&urn=urn:telelogic::1-503e822e5ec3651e-O-1409-000221c8
    - external velocity			
      - doors://RBGS854A:40000/?version=2&prodID=0&view=000000b9&urn=urn:telelogic::1-503e822e5ec3651e-O-1408-000221c8 
    - external Acceleration		
      - doors://RBGS854A:40000/?version=2&prodID=0&view=000000b9&urn=urn:telelogic::1-503e822e5ec3651e-O-1407-000221c8  
    - Lateral Acceleration		
      - doors://RBGS854A:40000/?version=2&prodID=0&view=000000b9&urn=urn:telelogic::1-503e822e5ec3651e-O-1406-000221c8 
  - L4
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-695-00026448
**************************************************************************** */
STATIC_MTD void vdyMonitorInputSignals(VDYInputData_t *input, VDYErrors_t *VDYErrors);


/* **********************************************************************
  @fn               vdyMonitorInputParameters */ /*!
  @brief           Monitor input parameters

  @description     Checks that parameters are within specifiaction and that they are
                   set as valid
                   If a parameter is outside of the specified range, it
                   will be set to a default to avoid any calculation issues
                   and the parameter state is set to invalid
                   If any parameters is either invalid or out-of-range, 
                   it triggers a parameter fault

  @return          static void

  @param[in,out]   *input : Current Input Data
  @param[in,out]   *VDYErrors : VDY Error Signals

  @c_switch_part   
				  - CFG_VDY_DIS_SIDE_SLIP_ANGLE_ESTIMATION : Disables the side slip angle estimation
				  - CFG_VDY_DIS_WHEEL_PRE_PROCESSING : Disables the wheel speed pre processing, 
																	- wheel offset estimation
																	- wheel velocity <-> puls fusion
																	- vehicle speed estimation
																	- wheel load dependancy estimation
																	- dynamic (drift) sensor yaw rate offset estimation
																	- wheel velocity yaw rate estimation
  @c_switch_full   None 

  @pre             None
  @post            No changes
  @InOutCorrelation
					  - Check if parameters are valid (might be on a default if not valid) and check if parameters are within range
						- vehicle weight
						- track width front
						- track width rear
						- wheel base
						- steering ratio
						- self steering gradient
						- wheelticks
						- center of gravity height
						- wheel circumference
						- axle load distribution
						- wheel load dependency front
						- wheel load dependency rear
					  - Set parameter error status, Active / Inactive, in input parameter struct
  
	@startuml
	start
		:check for signal peaks between the current and the last cycle \n fDiff = *pInputSignal - *pLastInputSignal;
		if ((CML_f_Abs(fDiff) > Threshold) && ((sint32)VDY_GET_IO_STATE(Signal, pInputSignalState) == VDY_IO_STATE_VALID) && ((sint32)VDY_GET_IO_STATE(Signal, pLastInputSignalState) == VDY_IO_STATE_VALID)) then (YES)
			if (Limit the signal gain to the threshold \n fDiff > VDY_ZERO_F) then (YES)
				:*pLastInputSignal = *pLastInputSignal + Threshold;
			else (NO)
				:*pLastInputSignal = *pLastInputSignal - Threshold;
			endif
			:*pInputSignal     = *pLastInputSignal;
			:SignalPeakError   = VDY_STAT_ACTIVE;
			:VDY_SET_IO_STATE(Signal, VDY_IO_STATE_DECREASED, pInputSignalState);
		else (NO)
			:*pLastInputSignal = *pInputSignal;
		endif
		:store the signal state of the previous cycle signal value \n VDY_SET_IO_STATE(Signal, VDY_GET_IO_STATE(Signal, pInputSignalState), pLastInputSignalState);
		:return (SignalPeakError);
	stop
	@enduml
  @testmethod			  
	- Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_mon.c -> \n
                            TEST_vdyMonitorInputParameters_001(), \n
                            TEST_vdyMonitorInputParameters_002(), \n
                            TEST_vdyMonitorInputParameters_003()
  @traceability			  
  - L3
    - vehicle weight		
      - doors://RBGS854A:40000/?version=2&prodID=0&view=000000b9&urn=urn:telelogic::1-503e822e5ec3651e-O-1422-000221c8
    - track width front		
      - doors://RBGS854A:40000/?version=2&prodID=0&view=000000b9&urn=urn:telelogic::1-503e822e5ec3651e-O-1413-000221c8
    - track width rear		
      - doors://RBGS854A:40000/?version=2&prodID=0&view=000000b9&urn=urn:telelogic::1-503e822e5ec3651e-O-1414-000221c8
    - Wheel Base 			
      - doors://RBGS854A:40000/?version=2&prodID=0&view=000000b9&urn=urn:telelogic::1-503e822e5ec3651e-O-1412-000221c8
      - doors://RBGS854A:40000/?version=2&prodID=0&view=000000b9&urn=urn:telelogic::1-503e822e5ec3651e-O-1564-000221c8	
    - steering ratio		
      - doors://RBGS854A:40000/?version=2&prodID=0&view=000000b9&urn=urn:telelogic::1-503e822e5ec3651e-O-1421-000221c8
    - steering gradient		
      - doors://RBGS854A:40000/?version=2&prodID=0&view=000000b9&urn=urn:telelogic::1-503e822e5ec3651e-O-1415-000221c8
    - Wheel Ticks			
      - doors://RBGS854A:40000/?version=2&prodID=0&view=000000b9&urn=urn:telelogic::1-503e822e5ec3651e-O-1416-000221c8
    - COGH				
      - doors://RBGS854A:40000/?version=2&prodID=0&view=000000b9&urn=urn:telelogic::1-503e822e5ec3651e-O-1417-000221c8
    - wheel circumference		
      - doors://RBGS854A:40000/?version=2&prodID=0&view=000000b9&urn=urn:telelogic::1-503e822e5ec3651e-O-1418-000221c8
    - axle load distribution 	
      - doors://RBGS854A:40000/?version=2&prodID=0&view=000000b9&urn=urn:telelogic::1-503e822e5ec3651e-O-1419-000221c8
    - wheel load dependency front	
      - doors://RBGS854A:40000/?version=2&prodID=0&view=000000b9&urn=urn:telelogic::1-503e822e5ec3651e-O-1420-000221c8
    - wheel load dependency rear	
      - doors://RBGS854A:40000/?version=2&prodID=0&view=000000b9&urn=urn:telelogic::1-503e822e5ec3651e-O-1440-000221c8
  - L4
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-692-00026448
**************************************************************************** */
STATIC_MTD void vdyMonitorInputParameters(VDYInputData_t *input, VDYErrors_t *VDYErrors);
#if (VDY_VEH_DYN_INTFVER <= 5)
STATIC_MTD VDYActState_t vdyCheckSignalPeakError(float32 *pInputSignal, float32 *pLastInputSignal, VDYIoState_t const *pInputSignalState, VDYIoState_t *pLastInputSignalState, uint32 Signal, float32 Threshold);
#else
/* **********************************************************************
  @fn               vdyCheckSignalPeakError */ /*!
  @brief           Monitors input signal for peak errors

  @description     All input signals are analysed and if it is
                   considered active, the Input Signal Peak Error
                   is set to active, the signal state is set to decreased
                   and the signal is limited to the value
                   with the maximum allowed gradient

  @return          static VDYActState_t

  @param[in,out]   *pInputSignal : Current Input Signal
  @param[in,out]   *pLastInputSignal : Last Input Signal
  @param[in]       *pInputSignalState : Current Input Signal Validity
  @param[in,out]   *pLastInputSignalState : Last Input Signal Validity
  @param[in]       Signal : Current Sggnal Validity Index
  @param[in]       Threshold : Threshold

  @c_switch_part   None 
  @c_switch_full   None 

  @pre             None
  @post            No changes
  @InOutCorrelation
				  - check for signal peaks between the current and the last cycle
				  - If difference is greater than Threshold and the signals are valid
						- Limit the signal gain to the threshold
						- Set peak error
				  - Otherwise, make current signal as last signal
  
	@startuml
	start
		:SignalPeakError = VDY_STAT_INACTIVE;
		:check for signal peaks between the current and the last cycle \n fDiff = *pInputSignal - *pLastInputSignal;
		if ((CML_f_Abs(fDiff) > Threshold) && ((sint32)VDY_GET_IO_STATE(Signal, pInputSignalState) == VDY_IO_STATE_VALID) && ((sint32)VDY_GET_IO_STATE(Signal, pLastInputSignalState) == VDY_IO_STATE_VALID)) then (YES)
			:Limit the signal gain to the threshold;
			if (fDiff > VDY_ZERO_F) then (YES)
				:*pLastInputSignal = *pLastInputSignal + Threshold;
			else (NO)
				:*pLastInputSignal = *pLastInputSignal - Threshold;
			endif
			:*pInputSignal     = *pLastInputSignal;
			:SignalPeakError   = VDY_STAT_ACTIVE;
			:VDY_SET_IO_STATE(Signal, VDY_IO_STATE_DECREASED, pInputSignalState);
		else (NO)
			:*pLastInputSignal = *pInputSignal;
		endif
		:store the signal state of the previous cycle signal value \n VDY_SET_IO_STATE(Signal, VDY_GET_IO_STATE(Signal, pInputSignalState), pLastInputSignalState);
		:return SignalPeakError;
	stop
	@enduml

  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_mon.c -> \n
                            TEST_vdyCheckSignalPeakError_001(), \n
                            TEST_vdyCheckSignalPeakError_002(), \n
                            TEST_vdyCheckSignalPeakError_003(), \n
                            TEST_vdyCheckSignalPeakError_004(), \n
                            TEST_vdyCheckSignalPeakError_005()
  @traceability			  -	NA
  @author           Jochen Spruck
**************************************************************************** */
STATIC_MTD VDYActState_t vdyCheckSignalPeakError(float32 *pInputSignal, float32 *pLastInputSignal, VDYIoStateTypes_t pInputSignalState[], VDYIoStateTypes_t pLastInputSignalState[], uint32 Signal, float32 Threshold);
#endif

/* **********************************************************************
  @fn               vdyCheckForSignalPeakErrors */ /*!
  @brief           Monitors input signals for peak errors

  @description     All input signals are analysed and if any of them
                   are considered active the Input Signal Peak Error
                   is set to active

  @return          static void

  @param[in,out]   *pInput : Input Signals
  @param[in,out]   *pVDYErrors : VDY Error Signals

  @c_switch_part   
					  - CFG_VDY_DIS_YAW_SENSOR_PRE_PROCESSING : Disables the sensor yaw rate pre processing, 
																			  - static (stand still)yaw rate offset
																			  - yaw rate from yaw rate sensor estimation 
					  - CFG_VDY_DIS_STW_ANGLE_SENSOR_PRE_PROCESSING : Disables the steering wheel angle sensor pre processing, 
																					- steering wheel angle sensor offset estimation
																					- estimation of self steering gradient
																					- driver intended curvature
																					- yaw rate from steering wheel sensor estimation 
					  - CFG_VDY_USE_EX_LONG_VELO : Use external provided longitudinal velocity signal 
					  - CFG_VDY_DIS_LAT_ACCEL_SENSOR_PRE_PROCESSING : Disables the lateral acceleration sensor pre processing, 
																					- lateral sensor offset estimation
																					- yaw rate from lateral acceleration sensor estimation
					  - CFG_VDY_DIS_WHEEL_PRE_PROCESSING : Disables the wheel speed pre processing, 
																		- wheel offset estimation
																		- wheel velocity <-> puls fusion
																		- vehicle speed estimation
																		- wheel load dependancy estimation
																		- dynamic (drift) sensor yaw rate offset estimation
																		- wheel velocity yaw rate estimation
					  - CFG_VDY_USE_EX_LONG_ACCEL : Use external provided longitudinal acceleration signal
					  - CFG_VDY_BMW_LONG_ACCEL_MODEL : Enables the new Long Accel estimation method only for BMW projects
  @c_switch_full   None

  @pre             None
  @post            No changes
  @InOutCorrelation
				  - check for signal peaks between the actual and the last cycle
					- yaw rate
					- steering wheel angle
					- vehicle velocity
					- lateral acceleration
					- WhlVelFrLeft
					- WhlVelFrRight
					- WhlVelReLeft
					- WhlVelReRight
				   - Set signal Peak error (Active / Inactive) in the input signal struct
				   .
  
	@startuml
	start
		:check for signal peaks between the actual and the last cycle;
		if ( Yaw Rate \n (vdyCheckSignalPeakError(&pInput->Signals.YawRate,
                              &LastInputSignals.YawRate,
                              pInput->Signals.State,
                              LastInputSignals.State,
                              VDY_SIN_POS_YWR,
                              VDY_PAR_YAW_RATE_INPUT_PEAK) == VDY_STAT_ACTIVE)) then (Yes)
			:SignalPeakError = VDY_STAT_ACTIVE;
		else (NO)
		endif
		if( Steering Wheel Angle \n (vdyCheckSignalPeakError(&pInput->Signals.StWheelAngle,
                              &LastInputSignals.StWheelAngle,
                              pInput->Signals.State,
                              LastInputSignals.State,
                              VDY_SIN_POS_SWA,
                              VDY_PAR_SWA_INPUT_PEAK) == VDY_STAT_ACTIVE)) then (YES)
			:SignalPeakError = VDY_STAT_ACTIVE;
		else (NO)
		endif
		if( Rear steering wheel angle \n (vdyCheckSignalPeakError(&pInput->Signals.RearWhlAngle,
                              &LastInputSignals.RearWhlAngle,
                              pInput->Signals.State,
                              LastInputSignals.State,
                              VDY_SIN_POS_RSTA,
                              VDY_PAR_SWA_INPUT_PEAK) == VDY_STAT_ACTIVE)) then (YES)
			:SignalPeakError = VDY_STAT_ACTIVE;
		else (NO)
		endif
		if( Vehicle Velocity \n (vdyCheckSignalPeakError(&pInput->Signals.VehVelocityExt,
                              &LastInputSignals.VehVelocityExt,
                              pInput->Signals.State,
                              LastInputSignals.State,
                              VDY_SIN_POS_VEHVEL_EXT,
                              VDY_PAR_WHEEL_VELO_INPUT_PEAK) == VDY_STAT_ACTIVE)) then (YES)
			:SignalPeakError = VDY_STAT_ACTIVE;
		else (NO)
		endif
		if( Lateral Acceleration  \n (vdyCheckSignalPeakError(&pInput->Signals.LatAccel,
                                &LastInputSignals.LatAccel,
                                pInput->Signals.State,
                                LastInputSignals.State,
                                VDY_SIN_POS_LATA,
                                VDY_PAR_LAT_ACCEL_INPUT_PEAK) == VDY_STAT_ACTIVE)) then (YES)
			:SignalPeakError = VDY_STAT_ACTIVE;
		else (NO)
		endif
		if( WhlVelFrLeft  \n (vdyCheckSignalPeakError(&pInput->Signals.WhlVelFrLeft,
                              &LastInputSignals.WhlVelFrLeft,
                              pInput->Signals.State,
                              LastInputSignals.State,
                              VDY_SIN_POS_WVEL_FL,
                              VDY_PAR_WHEEL_VELO_INPUT_PEAK) == VDY_STAT_ACTIVE)) then (YES)
			:SignalPeakError = VDY_STAT_ACTIVE;
		else (NO)
		endif
		if( WhlVelFrRight  \n (vdyCheckSignalPeakError(&pInput->Signals.WhlVelFrRight,
                              &LastInputSignals.WhlVelFrRight,
                              pInput->Signals.State,
                              LastInputSignals.State,
                              VDY_SIN_POS_WVEL_FR,
                              VDY_PAR_WHEEL_VELO_INPUT_PEAK) == VDY_STAT_ACTIVE)) then (YES)
			:SignalPeakError = VDY_STAT_ACTIVE;
		else (NO)
		endif
		if( WhlVelReLeft  \n (vdyCheckSignalPeakError(&pInput->Signals.WhlVelReLeft,
                              &LastInputSignals.WhlVelReLeft,
                              pInput->Signals.State,
                              LastInputSignals.State,
                              VDY_SIN_POS_WVEL_RL,
                              VDY_PAR_WHEEL_VELO_INPUT_PEAK) == VDY_STAT_ACTIVE)) then (YES)
			:SignalPeakError = VDY_STAT_ACTIVE;
		else (NO)
		endif
		if( WhlVelReRight  \n (vdyCheckSignalPeakError(&pInput->Signals.WhlVelReRight,
                              &LastInputSignals.WhlVelReRight,
                              pInput->Signals.State,
                              LastInputSignals.State,
                              VDY_SIN_POS_WVEL_RR,
                              VDY_PAR_WHEEL_VELO_INPUT_PEAK) == VDY_STAT_ACTIVE)) then (YES)
			:SignalPeakError = VDY_STAT_ACTIVE;
		else (NO)
		endif
		if( Longitudinal Acceleration  \n (vdyCheckSignalPeakError(&pInput->Signals.VehLongAccelExt,
                              &LastInputSignals.VehLongAccelExt,
                              pInput->Signals.State,
                              LastInputSignals.State,
                              VDY_SIN_POS_VEHACL_EXT,
                              VDY_PAR_LONG_ACCEL_INPUT_PEAK) == VDY_STAT_ACTIVE)) then (YES)
			:SignalPeakError = VDY_STAT_ACTIVE;
		else (NO)
		endif
		if (SignalPeakError == VDY_STAT_ACTIVE) then (YES)
			:pVDYErrors->SignalInputErrors.InputSignalPeakError = VDY_ERR_STATE_ACTIVE;
		else (NO)
			:pVDYErrors->SignalInputErrors.InputSignalPeakError = VDY_ERR_STATE_INACTIVE;
		endif
	stop
	@enduml
  @testmethod			  
	- Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_mon.c -> TEST_vdyCheckForSignalPeakErrors_001()
  @traceability			  
  - L3
    - yaw rate		
      - doors://RBGS854A:40000/?version=2&prodID=0&view=000000b9&urn=urn:telelogic::1-503e822e5ec3651e-O-1396-000221c8
    - steering wheel angle	
      - doors://RBGS854A:40000/?version=2&prodID=0&view=000000b9&urn=urn:telelogic::1-503e822e5ec3651e-O-1402-000221c8
      - doors://RBGS854A:40000/?version=2&prodID=0&view=000000b9&urn=urn:telelogic::1-503e822e5ec3651e-O-1563-000221c8 
    - vehicle velocity	
      - doors://RBGS854A:40000/?version=2&prodID=0&view=000000b9&urn=urn:telelogic::1-503e822e5ec3651e-O-1403-000221c8
    - Vehicle Acceleration
      - doors://rbgs854a:40000/?version=2&prodID=0&view=0000012f&urn=urn:telelogic::1-503e822e5ec3651e-O-1401-000221c8
    - lateral acceleration	
      - doors://RBGS854A:40000/?version=2&prodID=0&view=000000b9&urn=urn:telelogic::1-503e822e5ec3651e-O-1399-000221c8
    - 4 Wheel Speeds	
      - doors://RBGS854A:40000/?version=2&prodID=0&view=000000b9&urn=urn:telelogic::1-503e822e5ec3651e-O-1410-000221c8
  - L4
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-691-00026448
  @author           Witek Konarski
**************************************************************************** */
STATIC_MTD void vdyCheckForSignalPeakErrors(VDYInputData_t *pInput, VDYErrors_t *pVDYErrors);


/* **********************************************************************
  @fn               vdyMonitorVelocityOutput */ /*!

  @brief           Check the vdy velocity output data

  @description     Sets fault if vehicle velocity could not be calculated

  @return          static void

  @param[in]       *proPorts : Provide Ports
  @param[in]       *input : Current input Signal

  @glob_in         None 
  @glob_out        u_Debouce_VDY_VEH_VEL_NOT_AVAILABLE : debouncing ouput counter

  @c_switch_part   
				  - CFG_VDY_VELO_VARIANCE_CHECK : Enables the Velocity varaince check for setting the velocity Not available DEM
				  - CFG_VDY_DEBOUNCE_OUTPUTS : Enables the max debouncing ouput counter
  @c_switch_full   None ? : Compiler switch used around this function/file

  @pre             None
  @post            No changes
  @InOutCorrelation
					  - Check for validity VehDyn Velocity state if valid
						- If not valid set error state active
					  - Check for veocity variance
						- If external longitudinal acceleration is greater than VDY_ACC_THRESHOLD_INC_VELOCITY_VAR (0.5F) and velocity variance is greater than VDY_VELOCITY_MAX_VARIANCE_DYNAMIC (55.0F) then set error state active
						- If external longitudinal acceleration is lesser than VDY_ACC_THRESHOLD_INC_VELOCITY_VAR (0.5F) and velocity variance is greater than VDY_VELOCITY_MAX_VARIANCE (30.0F) then set error state active
						- Otherwise set error state inactive
  
	@startuml
	start
		if(VDY_GET_IO_STATE(VDY_SOUT_POS_VELOCITY, proPorts->pVehicleDynamicSignals->State) != VDY_IO_STATE_VALID) then (YES)
			:proPorts->pVDYErrors->OutPutErrors.VDY_VEH_VEL_NOT_AVAILABLE = VDY_ERR_STATE_ACTIVE;
		else (NO)
		endif

	
	stop
	@enduml


  @testmethod			  
	- Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_mon.c -> TEST_vdyMonitorVelocityOutput_001(), TEST_vdyMonitorVelocityOutput_002()
  @traceability			  
  - L3
    - doors://RBGS854A:40000/?version=2&prodID=0&view=000000b9&urn=urn:telelogic::1-503e822e5ec3651e-O-1649-000221c8
  - L4
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-870-00026448
**************************************************************************** */
STATIC_MTD void vdyMonitorVelocityOutput(const proVdyPrtList_t *proPorts, const VDYInputData_t *input);


/* **********************************************************************
  @fn               vdyMonitorYawrateOutput */ /*!

  @brief           Check the vdy yawrate output data

  @description     Sets fault if yaw rate could not be calculated while
                   vehicle was moving
                   Current fault state will not be changed but kept while vehicle
                   is stationary

  @return          static void

  @param[in]       *proPorts : Provide Ports

  @c_switch_part   None 
  @c_switch_full   None 

  @pre             None
  @post            No changes
  @InOutCorrelation
					- Check for vehicle is moving in reverse direction
					- Check if output yaw rate is not valid and if vehicle is moving then set error VDY_VEH_YWR_NOT_AVAILABLE = VDY_ERR_STATE_ACTIVE

	@startuml
	start
		:check velocity \n fVelocity = proPorts->pVehicleDynamicSignals->Longitudinal.Velocity;
		if ((proPorts->pVehicleDynamicSignals->MotionState.MotState == (MotState_t)VDY_LONG_MOT_STATE_MOVE_RWD) && (fVelocity > VDY_ZERO_F)) then (YES)
			:fVelocity = -fVelocity;
		endif
		if (((sint32)VDY_GET_IO_STATE(VDY_SOUT_POS_YAWRATE, proPorts->pVehicleDynamicSignals->State) != VDY_IO_STATE_VALID ) &&
			((sint32)VDY_GET_IO_STATE(VDY_SOUT_POS_YAWRATE, proPorts->pVehicleDynamicSignals->State) != VDY_IO_STATE_DECREASED )) then (YES)
			if (fVelocity > VDY_YAWRATE_MIN_VELOCITY) then (YES)
				:proPorts->pVDYErrors->OutPutErrors.VDY_VEH_YWR_NOT_AVAILABLE = VDY_ERR_STATE_ACTIVE;
			else (NO)
				:stay in current mode;
			endif
		else (NO) 
			if ( when CFG_VDY_YAWRATE_VARIANCE_CHECK enabled \nproPorts->pVehicleDynamicSignals->Lateral.YawRate.Variance > VDY_YAWRATE_MAX_VARIANCE) then (YES)
				if (fVelocity > VDY_YAWRATE_MIN_VELOCITY)
					:proPorts->pVDYErrors->OutPutErrors.VDY_VEH_YWR_NOT_AVAILABLE = VDY_ERR_STATE_ACTIVE;
				else (NO)
					:stay in current mode;
				endif
			else (NO)
				:proPorts->pVDYErrors->OutPutErrors.VDY_VEH_YWR_NOT_AVAILABLE = VDY_ERR_STATE_INACTIVE;
			endif
		endif
	stop
	@enduml
  @testmethod			  
	- Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_mon.c -> \n
                            TEST_vdyMonitorYawrateOutput_001(), \n
                            TEST_vdyMonitorYawrateOutput_002(), \n
                            TEST_vdyMonitorYawrateOutput_003(), \n
                            TEST_vdyMonitorYawrateOutput_004(), \n
                            TEST_vdyMonitorYawrateOutput_005(), \n
                            TEST_vdyMonitorYawrateOutput_006(), \n
                            TEST_vdyMonitorYawrateOutput_007(), \n
                            TEST_vdyMonitorYawrateOutput_008()
  @traceability		
  - L3
    - doors://RBGS854A:40000/?version=2&prodID=0&view=000000b9&urn=urn:telelogic::1-503e822e5ec3651e-O-1495-000221c8
  - L4
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-871-00026448
**************************************************************************** */
STATIC_MTD void vdyMonitorYawrateOutput(const proVdyPrtList_t *proPorts);


/* **********************************************************************
  @fn               vdyMonitorOutputRanges */ /*!

  @brief           Check the vdy output ranges of the yaw rate and velocity data

  @description     Checks calculated output values of yaw rate, velocity and
                   longitudinal acceleration against absolute limits
                   (sanity check)
                   Fault is set if above limit

  @return          static void

  @param[in]       *proPorts : Provide Ports

  @c_switch_part   CFG_VDY_DIS_YAW_SENSOR_OUTPUT : Disables the alignment yaw rate output,
                                                 - yaw rate from yaw rate sensor with filtered offset estimation
  @c_switch_full   None 

  @pre             None
  @post            No changes
  @InOutCorrelation
					- Check longitudinal motion and if vehicle velocity is in range 0 - +400 kph and vehicle acceleration is below 15 m/s^2 and velocity is not NaN
						- set VelocityErr = VDY_ERR_STATE_INACTIVE
						- check estimated yaw rate; Invalid yaw rate input sensor signal during standstill must not lead to invalid output yaw rate 
					- Otherwise, Velocity value is out of range or NaN and set VelocityErr = VDY_ERR_STATE_ACTIVE
					- If yaw rate is in range -150 °/s - +150 °/s and lateral acceleration is below 15 m /s^2
						- set YawRateErr = VDY_ERR_STATE_INACTIVE
					- Otherwise set YawRateErr = VDY_ERR_STATE_ACTIVE
  
	@startuml
	start
		:absolute output values \n
			f_VelocityAbs = CML_f_Abs(proPorts->pVehicleDynamicSignals->Longitudinal.Velocity)
			f_LongAccelAbs = CML_f_Abs(proPorts->pVehicleDynamicSignals->Longitudinal.Accel)
			f_YawRateAbs = CML_f_Abs(proPorts->pVehicleDynamicSignals->Lateral.YawRate.YawRate)
			f_LatAccelAbs = CML_f_Abs(proPorts->pVehicleDynamicSignals->Lateral.Accel.LatAccel);
		if (check longitudinal motion \n if vehicle velocity is in range 0 - +400 kph and vehicle acceleration is below 15 m/s^2 and velocity is not NaN \n (f_VelocityAbs < MAX_VELOCITY) && (f_LongAccelAbs < MAX_ACCELERATION) && (ISNAN(proPorts->pVehicleDynamicSignals->Longitudinal.MotVar.Velocity) == FALSE)  ) then (YES)
			:proPorts->pVDYErrors->OutPutErrors.VelocityErr = VDY_ERR_STATE_INACTIVE;
			if (check estimated yaw rate \n Invalid yaw rate input sensor signal during standstill must not lead to invalid output yaw rate \n (    (((sint32)VDY_GET_IO_STATE(VDY_SOUT_POS_YAWRATE, proPorts->pVehicleDynamicSignals->State) != VDY_IO_STATE_VALID) &&
				((sint32)VDY_GET_IO_STATE(VDY_SOUT_POS_YAWRATE, proPorts->pVehicleDynamicSignals->State) != VDY_IO_STATE_DECREASED )) && ((sint32)VDY_GET_IO_STATE(VDY_SOUT_POS_VELOCITY, proPorts->pVehicleDynamicSignals->State) == VDY_IO_STATE_VALID) && (proPorts->pVehicleDynamicSignals->Longitudinal.Velocity < VDY_ONE_F )  ) ) then (YES)
				:VDY_SET_IO_STATE(VDY_SOUT_POS_YAWRATE, VDY_IO_STATE_VALID, proPorts->pVehicleDynamicSignals->State);
			endif
		else (NO)
			:Velocity value is out of range or NaN \n 
				VDY_SET_IO_STATE(VDY_SOUT_POS_VELOCITY, VDY_IO_STATE_INVALID, proPorts->pVehicleDynamicSignals->State)
				VDY_SET_IO_STATE(VDY_SOUT_POS_ACCEL, VDY_IO_STATE_INVALID, proPorts->pVehicleDynamicSignals->State)
				proPorts->pVDYErrors->OutPutErrors.VelocityErr = VDY_ERR_STATE_ACTIVE;
		endif
		if ( yaw rate is in range -150 °/s - +150 °/s and lateral acceleration is below 15 m /s^2 \n (f_YawRateAbs < MAX_YAWRATE) && (f_LatAccelAbs < MAX_ACCELERATION) ) then (YES)
			:proPorts->pVDYErrors->OutPutErrors.YawRateErr = VDY_ERR_STATE_INACTIVE;
		else (NO)
			:VDY_SET_IO_STATE(VDY_SOUT_POS_YAWRATE, VDY_IO_STATE_INVALID, proPorts->pVehicleDynamicSignals->State)
				VDY_SET_IO_STATE(VDY_SOUT_POS_LATERALACCEL, VDY_IO_STATE_INVALID, proPorts->pVehicleDynamicSignals->State)
				proPorts->pVDYErrors->OutPutErrors.YawRateErr = VDY_ERR_STATE_ACTIVE;
		endif
	stop
	@enduml
  @testmethod			  
	- Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_mon.c -> TEST_vdyMonitorOutputRanges_001()
  @traceability		
  - L3
    - Velocity Error 
      - doors://RBGS854A:40000/?version=2&prodID=0&view=000000b9&urn=urn:telelogic::1-503e822e5ec3651e-O-1499-000221c8
    - Yaw Rate Error 
      - doors://RBGS854A:40000/?version=2&prodID=0&view=000000b9&urn=urn:telelogic::1-503e822e5ec3651e-O-1433-000221c8
  - L4
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-638-00026448
**************************************************************************** */
STATIC_MTD void vdyMonitorOutputRanges(const proVdyPrtList_t *proPorts);

#if ( (defined(CFG_VDY_MON_OUTPUT_PEAKS)) && (CFG_VDY_MON_OUTPUT_PEAKS) )
/* **********************************************************************
  @fn               vdyMonitorOutputPeaks */ /*!

  @brief           Check and limit curve output value

  @description     Change in curve output is limited to avoid output jumps in signal
                   when switching to yawrate based curve (steering input becomes invalid)
                   Limitation value is based on max. input signal peak

  @return          static void

  @param[in]       *pInput : 
  @param[in]       *proPorts : 

  @glob_in         VDY_PAR_SWA_INPUT_PEAK : threshold steering wheel angle input signal diff peak
  @glob_in         LastOutputSignals : Some last valid Output Signals
  @glob_out        LastOutputSignals : Some last valid Output Signals

  @c_switch_part   None 
  @c_switch_full   CFG_VDY_MON_OUTPUT_PEAKS : Enables the output peak monitoring

  @pre             None
  @post            No changes
  @InOutCorrelation		  - 
  
  @testmethod			  -	NA
  @traceability			  -	NA
**************************************************************************** */
STATIC_MTD void vdyMonitorOutputPeaks(const VDYInputData_t *pInput, const proVdyPrtList_t *proPorts);
#endif

#if (CFG_VDY_YWR_OFFSET_MONITOR)
	
/* **********************************************************************
  @fn                 vdyYwrMonVehHalt */ /*!
  @brief           Monitor amount of the yaw rate at vehicle-halt

  @description     A yaw rate sensor offset failure is detected, if the
                   absolute value of the yaw rate sensor signal at vehicle
                   standstill is higher than a limit for longer time 

  @return          static VDYErrState_t

  @param[in]       *pMon : 
  @param[in,out]   *pVehHalt : 

  @c_switch_part   None
  @c_switch_full   CFG_VDY_YWR_OFFSET_MONITOR : Enables monitoring of yaw rate at vehicle-stop, during vehicle-stop and vehicle drive-off. During this driving
                                                conditions zero point offset is roughly observeable. Exceedance of limits are indicated by error events

  @pre             None
  @post            No changes
  @InOutCorrelation		  - 
  
  @testmethod			  -	NA
  @traceability			  -	NA
**************************************************************************** */
STATIC_MTD VDYErrState_t vdyYwrMonVehHalt(const VDYYwrMonDataLoc_t *pMon, VDYYwrMonVehHalt_t *pVehHalt);


/* **********************************************************************
  @fn                 vdyYwrMonVehHaltDrv */ /*!
  @brief           Comparison of the yaw rate at the start and at the
                   end of the vehicle standstill

  @description     At vehicle-halt the current is intermediate-stored, 
                   when the yaw rate sensor signal gets constant. At the
                   driving away the measured yaw rate is compared with 
                   the previously stored value. A yaw rate sensor offset
                   failure is stored, if the difference between both value
                   is greater than limit

  @return          static VDYErrState_t

  @param[in]       *pMon : 
  @param[in,out]   *pVehHtDrv : 

  @c_switch_part   None 
  @c_switch_full   CFG_VDY_YWR_OFFSET_MONITOR : Enables monitoring of yaw rate at vehicle-stop, during vehicle-stop and vehicle drive-off. During this driving
                                                conditions zero point offset is roughly observeable. Exceedance of limits are indicated by error events

  @pre             None
  @post            No changes
  @InOutCorrelation		  - 
  
  @testmethod			  -	NA
  @traceability			  -	NA
**************************************************************************** */
STATIC_MTD VDYErrState_t vdyYwrMonVehHaltDrv(const VDYYwrMonDataLoc_t *pMon, VDYYwrMonVehHaltDrv_t *pVehHtDrv);

/* **********************************************************************
  @fn                 vdyYwrMonVehHaltCal */ /*!
  @brief           Monitor yaw rate calibration during vehicle standstill

  @description     Monitor during vehicle standstill if it possible to
                   determine zero point yaw rate offset in given time.

  @return          static VDYErrState_t

  @param[in]       *pMon : 
  @param[in,out]   *pVehHaltCal : 

  @c_switch_part   None 
  @c_switch_full   CFG_VDY_YWR_OFFSET_MONITOR : Enables monitoring of yaw rate at vehicle-stop, during vehicle-stop and vehicle drive-off. During this driving
                                                conditions zero point offset is roughly observeable. Exceedance of limits are indicated by error events

  @pre             None
  @post            No changes
  @InOutCorrelation		  - 
  
  @testmethod			  -	NA
  @traceability			  -	NA
**************************************************************************** */
STATIC_MTD VDYErrState_t vdyYwrMonVehHaltCal(const VDYYwrMonDataLoc_t *pMon, VDYYwrMonVehHaltCal_t *pVehHaltCal);


/* **********************************************************************
  @fn                 vdyYwrMonVehDriveOff */ /*!
  @brief           Monitor amount of the vehicle drive-off

  @description     A yaw rate sensor offset failure is detected, if the
                   absolute value of the yaw rate sensor signal at vehicle
                   standstill was higher than a limit for a minimum time 
                   before the vehicle is driving off

  @return          static VDYErrState_t

  @param[in]       *pMon : 
  @param[in,out]   *pDrvOff : 

  @c_switch_part   None 
  @c_switch_full   CFG_VDY_YWR_OFFSET_MONITOR : Enables monitoring of yaw rate at vehicle-stop, during vehicle-stop and vehicle drive-off. During this driving
                                                conditions zero point offset is roughly observeable. Exceedance of limits are indicated by error events

  @pre             None
  @post            No changes
  @InOutCorrelation		  - 
  
  @testmethod			  -	NA
  @traceability			  -	NA
**************************************************************************** */
STATIC_MTD VDYErrState_t vdyYwrMonVehDriveOff(const VDYYwrMonDataLoc_t *pMon, VDYYwrMonVehDriveOff_t *pDrvOff);
#endif

/* PRQA S 3449, 3451 EOF */
/* date: 2019-06-10, reviewer: Mahesh Patle (uidr0487), reason: Functional Safe */
/* **********************************************************************
  @fn               vdyInitDynYwrOffsetMonitor */ /*!

  @brief           Init the dynamic yaw rate offset Monitor

  @description     Initalizes the dynamic montoring data in the simulation

  @return          void

  @param[in]       YwrOffset : 

  @glob_in         None 
  @glob_out        oldOffset : old offset
  @glob_out        StandStillOffset : stand still offset

  @c_switch_part   None 
  @c_switch_full   
					  VDY_SIMU :   
					  CFG_VDY_DIS_YWR_OFFSET_COMP : Disables zero point offset compensation of input yaw rate signal
  @pre             None
  @post            No changes
  @InOutCorrelation		  - 
  
  @startuml
	start
		:oldOffset = YwrOffset;
		:StandStillOffset = YwrOffset;
	stop
	@enduml
  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_mon.c -> TEST_vdyInitDynYwrOffsetMonitor_001()
  @traceability			  -	NA
**************************************************************************** */
void vdyInitDynYwrOffsetMonitor( float32 YwrOffset );

#if !(defined(CFG_VDY_DIS_FUNCTIONAL_SAFETY_MON) && (CFG_VDY_DIS_FUNCTIONAL_SAFETY_MON))
/* **********************************************************************
  @fn                     vdyFSMonGetPrivateData */ /*!
  @brief           Get the private date of the functional safety monitoring

  @description     Returns pointer to FuSi monitor data to allow MTS output

  @return          VDYFSData_t : VDY Functional Safety Data

  @glob_in         None 
  @glob_out        gVDYFSData : Functional safety internal data

  @c_switch_part   None 
  @c_switch_full   None 

  @pre             None
  @post            No changes
  @InOutCorrelation
  - Returns pointer to FuSi monitor data to allow MTS output
  
	@startuml
	start
		:return (&gVDYFSData);
	stop
	@enduml
  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_mon.c -> TEST_vdyFSMonGetPrivateData_001()
  @traceability			  -	NA
**************************************************************************** */
VDYFSData_t       *vdyFSMonGetPrivateData(void);
#endif

/* **********************************************************************
  @fn               vdyGetMonitorInput */ /*!
  @brief           Get the vdy Monitor input signals

  @description     Returns pointer to the last input signals monitor data
                   to allow access to this data in the simulation

  @return          VDYLastInSig_t : last valid Input Signals

  @param[in]       -

  @glob_in         None 
  @glob_out        LastInputSignals : Some last valid Input Signals

  @c_switch_part   None 
  @c_switch_full   VDY_SIMU :

  @pre             None
  @post            No changes
  @InOutCorrelation
  
	@startuml
	start
		:return &LastInputSignals;
	stop
	@enduml
  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_mon.c -> TEST_vdyGetMonitorInput_001()
  @traceability			  -	NA
**************************************************************************** */
VDYLastInSig_t    *vdyGetMonitorInput(void);





#if !(defined(CFG_VDY_DIS_FUNCTIONAL_SAFETY_MON) && (CFG_VDY_DIS_FUNCTIONAL_SAFETY_MON))
/* **********************************************************************
	Unit Design for vdyFSVelocityMonitoring is found in Declaration Section
**************************************************************************** */
STATIC_MTD void vdyFSVelocityMonitoring(const proVdyPrtList_t *proPorts, VDYFSData_t *VDYFSData)
{
  /* this error was determined by the velo internal external mon function (vdyVelMonExec) */
#if ( defined(CFG_VDY_USE_VELO_MONITOR) && (CFG_VDY_USE_VELO_MONITOR) )
  VDYFSData->FSMonErrorStates.FSIntExtVeloCheck = proPorts->pVDYErrors->OutPutErrors.VelMonLt;
#else
  VDYFSData->FSMonErrorStates.FSIntExtVeloCheck = VDY_ERR_STATE_UNKNOWN;
#endif

#if ( defined(CFG_VDY_DO_VELOCITY_CORR) && (CFG_VDY_DO_VELOCITY_CORR) )
  /* this error was determined by the velo corr module */
  VDYFSData->FSMonErrorStates.FSCorrVeloCheck = proPorts->pVDYErrors->OutPutErrors.VelCorrRg;
#else
  VDYFSData->FSMonErrorStates.FSCorrVeloCheck = VDY_ERR_STATE_UNKNOWN;
#ifdef _WIN32
#pragma message(__FILE__"("STRING_QUOTE(__LINE__)"): Can not check for functional safety corr velo errors, please switch on CFG_VDY_DO_VELOCITY_CORR")
/* <ln_offset:-1 PCLINT Error 975: reviewer name: Jochen Spruck date: 27-09-2010  reason: only todo message */
#endif
#endif

#if ((defined(CFG_VDY_FS_VELO_CORR_MON)) && (CFG_VDY_FS_VELO_CORR_MON))
  /* If the fast velocity monitor detects a fault, raise correction factor variance to inhibit CMS reactions */
  if (proPorts->pVDYErrors->OutPutErrors.VDY_FS_VEH_CORR_MON == VDY_ERR_STATE_ACTIVE)
  {
    proPorts->pVehicleDynamicSignals->Longitudinal.varVelocity = 100.0F;
  }
#endif
}


/* **********************************************************************
	Unit Design for vdyFSYawRateMonitoring is found in Declaration Section
**************************************************************************** */

STATIC_MTD void vdyFSYawRateMonitoring(const VDYInternalData_t *IntData, const proVdyPrtList_t *proPorts, const VDYModIf_t *VDYModIf, VDYFSData_t *VDYFSData)
{
#if ( (!defined(CFG_VDY_DIS_LAT_ACCEL_SENSOR_PRE_PROCESSING)) || (!CFG_VDY_DIS_LAT_ACCEL_SENSOR_PRE_PROCESSING) )
  float32   fDeltaDist = IntData->vdy_ve_out.veh_velo * VDYModIf->CycleTime;
#endif

#if (( (!defined(CFG_VDY_DIS_WHEEL_PRE_PROCESSING)) || (!CFG_VDY_DIS_WHEEL_PRE_PROCESSING) ) && (CFG_VDY_FS_YR_VS_WSP_ENABLE))
  /* threshold velocities, above yaw rate error monitoring is active */
  /* curve threshold, only below this the yaw rate is monitored */
  vdyFSMonitorWheelYawRate(IntData, proPorts, VDYModIf, VDYFSData);
#else
  proPorts->pVDYErrors->OutPutErrors.VDY_FS_YR_VS_WSP = VDY_ERR_STATE_UNKNOWN;
#ifdef _WIN32
#pragma message(__FILE__"("STRING_QUOTE(__LINE__)"): Can not check for functional safety wheel yaw rate to yaw rate, please switch on CFG_VDY_DIS_WHEEL_PRE_PROCESSING and CFG_VDY_FS_YR_VS_WSP_ENABLE")
/* <ln_offset:-1 PCLINT Error 975: reviewer name: Jochen Spruck date: 27-09-2010  reason: only todo message */
#endif
#endif

#if ( (!defined(CFG_VDY_DIS_LAT_ACCEL_SENSOR_PRE_PROCESSING)) || (!CFG_VDY_DIS_LAT_ACCEL_SENSOR_PRE_PROCESSING) )
  /* Is the vehicle velocity above the yaw rate velocity */
  /* Is the curve threshold below this the yaw rate */
  if (   (CML_f_Abs(IntData->vdy_ye_out.veh_merge_curve_grad) <= MAX_CURVE_GRAD)
      && (IntData->vdy_ve_out.veh_velo >= MIN_LAT_ACCEL_YAW_RATE_VELOCITY) )
  {
    VDYFSData->VDYFSYawRateCheck.fYawLatAccelDelta = IntData->vdy_gye_out.gier_yaw_rate-IntData->vdy_aye_out.ay_yaw_rate;
    /* add the delta value to the statistic data */
    vdyStatIntervalAdd(&(VDYFSData->VDYFSCurveCheck.VDYFSAyeGyeStat),VDYFSData->VDYFSYawRateCheck.fYawLatAccelDelta,fDeltaDist);
    /* Check if above threshold */
    if (CML_f_Abs(VDYFSData->VDYFSYawRateCheck.fYawLatAccelDelta) >VDY_FS_LAT_ACCEL_YAW_RATE_THRESHOLD)
    {
      VDYFSData->VDYFSYawRateCheck.fYawLatAccelOutDist += fDeltaDist;
    }
    else
    {
      VDYFSData->VDYFSYawRateCheck.fYawLatAccelOutDist = VDY_ZERO_F;
    }
  }
  else
  {
    VDYFSData->VDYFSYawRateCheck.fYawLatAccelOutDist = VDY_ZERO_F;
  }

  /* set the error state */
  if (VDYFSData->VDYFSYawRateCheck.fYawLatAccelOutDist > VDY_FS_YAW_RATE_DIST_THRESHOLD)
  {
    if (  (proPorts->pVDYErrors->OutPutErrors.VDY_FS_YR_VS_AY == (VDYErrState_t)VDY_ERR_STATE_INACTIVE)
        ||(proPorts->pVDYErrors->OutPutErrors.VDY_FS_YR_VS_AY == (VDYErrState_t)VDY_ERR_STATE_UNKNOWN))
    {
      /* increase occurence counter, only used for fault analysis, overrun used to continue counting */
      VDYFSData->VDYFSYawRateCheck.nLatAccelErrorCounter++;
    }
    proPorts->pVDYErrors->OutPutErrors.VDY_FS_YR_VS_AY  = VDY_ERR_STATE_ACTIVE;
  }
  else
  {
    proPorts->pVDYErrors->OutPutErrors.VDY_FS_YR_VS_AY = VDY_ERR_STATE_INACTIVE;
  }
#else
  proPorts->pVDYErrors->OutPutErrors.VDY_FS_YR_VS_AY = VDY_ERR_STATE_UNKNOWN;
#endif

#if ( (!defined(CFG_VDY_DIS_STW_ANGLE_SENSOR_PRE_PROCESSING)) || (!CFG_VDY_DIS_STW_ANGLE_SENSOR_PRE_PROCESSING) )
  if (    (CML_f_Abs(IntData->vdy_ye_out.veh_merge_curve_grad) <= MAX_CURVE_GRAD)
       && (IntData->vdy_ve_out.veh_velo >= MIN_SWA_YAW_RATE_VELOCITY))
  {
    VDYFSData->VDYFSYawRateCheck.fYawSteerDelta = IntData->vdy_gye_out.gier_yaw_rate-IntData->vdy_sye_out.stw_yaw_rate;
    /* add the delta value to the statistic data */
    vdyStatIntervalAdd(&(VDYFSData->VDYFSCurveCheck.VDYFSSyeGyeStat),VDYFSData->VDYFSYawRateCheck.fYawSteerDelta,fDeltaDist);
    /* Check if above threshold */
    if (CML_f_Abs(VDYFSData->VDYFSYawRateCheck.fYawSteerDelta) > VDY_FS_SWA_YAW_RATE_THRESHOLD)
    {
      VDYFSData->VDYFSYawRateCheck.fYawSteerOutDist += fDeltaDist;
    }
    else
    {
      VDYFSData->VDYFSYawRateCheck.fYawSteerOutDist = VDY_ZERO_F;
    }
  }
  else
  {
    VDYFSData->VDYFSYawRateCheck.fYawSteerOutDist = VDY_ZERO_F;
  }

  /* set the error state */
  if (VDYFSData->VDYFSYawRateCheck.fYawSteerOutDist > VDY_FS_YAW_RATE_DIST_THRESHOLD)
  {
    if (  (proPorts->pVDYErrors->OutPutErrors.VDY_FS_YR_VS_SWA == (VDYErrState_t)VDY_ERR_STATE_INACTIVE)
        ||(proPorts->pVDYErrors->OutPutErrors.VDY_FS_YR_VS_SWA == (VDYErrState_t)VDY_ERR_STATE_UNKNOWN))
    {
      VDYFSData->VDYFSYawRateCheck.nSwaErrorCounter++;
    }
    proPorts->pVDYErrors->OutPutErrors.VDY_FS_YR_VS_SWA = VDY_ERR_STATE_ACTIVE;
  }
  else
  {
    proPorts->pVDYErrors->OutPutErrors.VDY_FS_YR_VS_SWA = VDY_ERR_STATE_INACTIVE;
  }
#else
  proPorts->pVDYErrors->OutPutErrors.VDY_FS_YR_VS_SWA = VDY_ERR_STATE_UNKNOWN;
#endif
}


#if (( (!defined(CFG_VDY_DIS_WHEEL_PRE_PROCESSING)) || (!CFG_VDY_DIS_WHEEL_PRE_PROCESSING) ) &&(CFG_VDY_FS_YR_VS_WSP_ENABLE))
/* **********************************************************************
	Unit Design for vdyFSMonitorWheelYawRate is found in Declaration Section
**************************************************************************** */

STATIC_MTD void vdyFSMonitorWheelYawRate(const VDYInternalData_t *pIntData, const proVdyPrtList_t *proPorts, const VDYModIf_t *pVDYModIf, VDYFSData_t *pVDYFSData)
{
  float32   fDeltaDist = pIntData->vdy_ve_out.veh_velo * pVDYModIf->CycleTime;
  /* threshold velocities, equal or above yaw rate error monitoring is active */
  /* curve threshold, only equal or below this the yaw rate is monitored */
  /* wheel yaw rate variance, only if wheel yaw rate is available the fault monitoring is active */
  if (   (CML_f_Abs(pIntData->vdy_ye_out.veh_merge_curve_grad) <= MAX_CURVE_GRAD)
      && (pIntData->vdy_ve_out.veh_velo >= MIN_WHEEL_YAW_RATE_VELOCITY)
      && (pIntData->vdy_wye_out.whl_yaw_rate_var < MAX_WHEEL_YAW_RATE_VARIANCE)  )
  {
    pVDYFSData->VDYFSYawRateCheck.fYawWheelDelta = pIntData->vdy_gye_out.gier_yaw_rate - pIntData->vdy_wye_out.whl_yaw_rate;
    /* add the delta value to the statistic data */
    vdyStatIntervalAdd(&(pVDYFSData->VDYFSCurveCheck.VDYFSWyeGyeStat), pVDYFSData->VDYFSYawRateCheck.fYawWheelDelta, fDeltaDist);
    /* Check if above threshold */
    if (CML_f_Abs(pVDYFSData->VDYFSYawRateCheck.fYawWheelDelta) > VDY_FS_WHEEL_YAW_RATE_THRESHOLD)
    {
      pVDYFSData->VDYFSYawRateCheck.fYawWheelOutDist += fDeltaDist;
    }
    else
    {
      pVDYFSData->VDYFSYawRateCheck.fYawWheelOutDist = VDY_ZERO_F;
    }
  }
  else
  {
    pVDYFSData->VDYFSYawRateCheck.fYawWheelOutDist = VDY_ZERO_F;
  }

  /* set the error state */
  if (pVDYFSData->VDYFSYawRateCheck.fYawWheelOutDist > VDY_FS_YAW_RATE_DIST_THRESHOLD)
  {
    if (  (proPorts->pVDYErrors->OutPutErrors.VDY_FS_YR_VS_WSP == (VDYErrState_t)VDY_ERR_STATE_INACTIVE)
        ||(proPorts->pVDYErrors->OutPutErrors.VDY_FS_YR_VS_WSP == (VDYErrState_t)VDY_ERR_STATE_UNKNOWN))
    {
      /* increase occurence counter, only used for fault analysis, overrun used to continue counting */
      pVDYFSData->VDYFSYawRateCheck.nWheelErrorCounter++;
    }
    proPorts->pVDYErrors->OutPutErrors.VDY_FS_YR_VS_WSP  = VDY_ERR_STATE_ACTIVE;
  }
  else
  {
    proPorts->pVDYErrors->OutPutErrors.VDY_FS_YR_VS_WSP = VDY_ERR_STATE_INACTIVE;
  }
}
#endif


/* **********************************************************************
	Unit Design for vdyFSCalcDeltaYawRate is found in Declaration Section
**************************************************************************** */

STATIC_MTD void vdyFSCalcDeltaYawRate(VDYFSData_t *VDYFSData, const VDYInternalData_t *IntData)
{
  boolean bCalcOverAll = (boolean)FALSE;

  /* check if the WyeGye intervall is above volume threshold to calc the mean/std and reduce the intervall */
  if (VDYFSData->VDYFSCurveCheck.VDYFSWyeGyeStat.Volume >= VDY_FS_MEAN_DRIVE_DISTANCE)
  {
    vdyStatIntervalMeanDev(&(VDYFSData->VDYFSCurveCheck.VDYFSWyeGyeStat));
    vdyStatIntervalReduce(&(VDYFSData->VDYFSCurveCheck.VDYFSWyeGyeStat),VDY_FS_DISTANCE_REDUCE_FACTOR);
    bCalcOverAll = (boolean)TRUE;
  }

  /* check if the AyeGye intervall is above volume threshold to calc the mean/std and reduce the intervall */
  if (VDYFSData->VDYFSCurveCheck.VDYFSAyeGyeStat.Volume >= VDY_FS_MEAN_DRIVE_DISTANCE)
  {
    vdyStatIntervalMeanDev(&(VDYFSData->VDYFSCurveCheck.VDYFSAyeGyeStat));
    vdyStatIntervalReduce(&(VDYFSData->VDYFSCurveCheck.VDYFSAyeGyeStat),VDY_FS_DISTANCE_REDUCE_FACTOR);
    bCalcOverAll = (boolean)TRUE;
  }

  /* check if the SyeGye intervall is above volume threshold to calc the mean/std and reduce the intervall */
  if (VDYFSData->VDYFSCurveCheck.VDYFSSyeGyeStat.Volume >= VDY_FS_MEAN_DRIVE_DISTANCE)
  {
    vdyStatIntervalMeanDev(&(VDYFSData->VDYFSCurveCheck.VDYFSSyeGyeStat));
    vdyStatIntervalReduce(&(VDYFSData->VDYFSCurveCheck.VDYFSSyeGyeStat),VDY_FS_DISTANCE_REDUCE_FACTOR);
    bCalcOverAll = (boolean)TRUE;
  }

  /* calculate the overall mean and std */
  if ( bCalcOverAll == (boolean)TRUE )
  {
    vdyStatIntervalInit(&(VDYFSData->VDYFSCurveCheck.VDYFSAllOverIntervall));
    vdyStatIntervalAdd(&(VDYFSData->VDYFSCurveCheck.VDYFSAllOverIntervall), VDYFSData->VDYFSCurveCheck.VDYFSWyeGyeStat.Mean, VDY_WYE_CURVECHECK_WEIGHT);
    vdyStatIntervalAdd(&(VDYFSData->VDYFSCurveCheck.VDYFSAllOverIntervall), VDYFSData->VDYFSCurveCheck.VDYFSAyeGyeStat.Mean, VDY_AYE_CURVECHECK_WEIGHT);
    vdyStatIntervalAdd(&(VDYFSData->VDYFSCurveCheck.VDYFSAllOverIntervall), VDYFSData->VDYFSCurveCheck.VDYFSSyeGyeStat.Mean, VDY_SYE_CURVECHECK_WEIGHT);
    vdyStatIntervalMeanDev(&(VDYFSData->VDYFSCurveCheck.VDYFSAllOverIntervall));

    /* Calculate the curve prediction error */
    VDYFSData->VDYFSCurveCheck.fDeltaY = VDY_FIFTY_CENT * IntData->vdy_ve_out.veh_velo*VDY_FS_PRED_HORZ_TIME*VDY_FS_PRED_HORZ_TIME*VDYFSData->VDYFSCurveCheck.VDYFSAllOverIntervall.Mean;

    /* Check if DeltaY is above threshold and exeed counters */
    if (  (VDYFSData->VDYFSCurveCheck.fDeltaY >= VDY_FS_MAX_LAT_DIST_ERROR)
       && (VDYFSData->VDYFSCurveCheck.nDeltaYCounter <= (uint8)(VDY_FS_MAX_LAT_DIST_COUNTER)) )
    {
      VDYFSData->VDYFSCurveCheck.nDeltaYCounter++;
    }
    else
    {
      VDYFSData->VDYFSCurveCheck.nDeltaYCounter = 0U;
    }
  }
}


/* **********************************************************************
	Unit Design for vdyFSCurvePredictionMonitoring is found in Declaration Section
**************************************************************************** */

STATIC_MTD void vdyFSCurvePredictionMonitoring(const VDYInternalData_t *IntData, VDYFSData_t *VDYFSData)
{
  /* Caculate the yaw rate delta */
  vdyFSCalcDeltaYawRate(VDYFSData, IntData);

  /* Check if error condition is valid */
  if (VDYFSData->VDYFSCurveCheck.nDeltaYCounter >= (uint8)(VDY_FS_MAX_LAT_DIST_COUNTER))
  {
    if (  (VDYFSData->FSMonErrorStates.FSMaxLatDisplacementError == (VDYErrState_t)VDY_ERR_STATE_INACTIVE)
        ||(VDYFSData->FSMonErrorStates.FSMaxLatDisplacementError == (VDYErrState_t)VDY_ERR_STATE_UNKNOWN))
    {
        VDYFSData->VDYFSCurveCheck.nCurveErrorCounter++;
    }
    VDYFSData->FSMonErrorStates.FSMaxLatDisplacementError = VDY_ERR_STATE_ACTIVE;
  }
  else
  {
    VDYFSData->FSMonErrorStates.FSMaxLatDisplacementError = VDY_ERR_STATE_INACTIVE;
  }
}


/* **********************************************************************
	Unit Design for vdyFSMonitor is found in vdy.h
**************************************************************************** */
void vdyFSMonitor(const VDYInternalData_t *IntData, const VDYModIf_t *VDYModIf, const proVdyPrtList_t *proPorts)
{

  /* Do the functional safety velocity monitoring */
  vdyFSVelocityMonitoring(proPorts, &gVDYFSData);

  /* Do the functional safety yawrate monitoring */
  vdyFSYawRateMonitoring(IntData, proPorts, VDYModIf, &gVDYFSData);

  /* Do the functional safety curve prediction monitoring */
  vdyFSCurvePredictionMonitoring(IntData, &gVDYFSData);

}


/* **********************************************************************
	Unit Design for vdyFSInit is found in vdy.h
**************************************************************************** */
void vdyFSInit(void)
{
  /* Init the statistic data buffers */
  vdyStatIntervalInit(&(gVDYFSData.VDYFSCurveCheck.VDYFSWyeGyeStat));
  vdyStatIntervalInit(&(gVDYFSData.VDYFSCurveCheck.VDYFSAyeGyeStat));
  vdyStatIntervalInit(&(gVDYFSData.VDYFSCurveCheck.VDYFSSyeGyeStat));
  gVDYFSData.VDYFSCurveCheck.nCurveErrorCounter    = VDY_ZERO_U;

  /* Init yaw rate monitoring */
  gVDYFSData.VDYFSYawRateCheck.fYawWheelDelta      = VDY_ZERO_F;
  gVDYFSData.VDYFSYawRateCheck.fYawWheelOutDist    = VDY_ZERO_F;
  gVDYFSData.VDYFSYawRateCheck.fYawLatAccelDelta   = VDY_ZERO_F;
  gVDYFSData.VDYFSYawRateCheck.fYawLatAccelOutDist = VDY_ZERO_F;
  gVDYFSData.VDYFSYawRateCheck.fYawSteerDelta      = VDY_ZERO_F;
  gVDYFSData.VDYFSYawRateCheck.fYawSteerOutDist    = VDY_ZERO_F;
  gVDYFSData.VDYFSYawRateCheck.nWheelErrorCounter    = VDY_ZERO_U;
  gVDYFSData.VDYFSYawRateCheck.nLatAccelErrorCounter = VDY_ZERO_U;
  gVDYFSData.VDYFSYawRateCheck.nSwaErrorCounter      = VDY_ZERO_U;

  /* Init all error states to unkown */
  gVDYFSData.FSMonErrorStates.FSIntExtVeloCheck            = VDY_ERR_STATE_UNKNOWN;
  gVDYFSData.FSMonErrorStates.FSCorrVeloCheck              = VDY_ERR_STATE_UNKNOWN;

  gVDYFSData.FSMonErrorStates.FSMaxLatDisplacementError    = VDY_ERR_STATE_UNKNOWN;
}


/* **********************************************************************
	Unit Design for vdyFSMonGetPrivateData is found in vdy.h
**************************************************************************** */

VDYFSData_t *vdyFSMonGetPrivateData(void)
{
  return (&gVDYFSData);
}
#endif


#if defined(VDY_SIMU)
/* **********************************************************************
	Unit Design for vdyGetMonitorInput is found in vdy.h
**************************************************************************** */

VDYLastInSig_t * vdyGetMonitorInput(void)
{
  return &LastInputSignals;
}


#if ( (defined(CFG_VDY_MON_OUTPUT_PEAKS)) && (CFG_VDY_MON_OUTPUT_PEAKS) )
/* **********************************************************************
	Unit Design for vdyGetMonitorOutputPeaksData is found in vdy.h
**************************************************************************** */

VDYLastOutSig_t * vdyGetMonitorOutputPeaksData(void)
{
 return &LastOutputSignals;
}
#endif
#endif


/* **********************************************************************
	Unit Design for vdyMonitorInput is found in vdy.h
**************************************************************************** */

void vdyMonitorInput(VDYInputData_t *input, VDYErrors_t *VDYErrors)
{
  /* check for invalid parameter values or undefined parameters */
  vdyMonitorInputParameters(input, VDYErrors);

  /* check for invalid signal values */
  vdyMonitorInputSignals(input, VDYErrors);

  /* check for signal peaks between the actual and the last cycle */
  vdyCheckForSignalPeakErrors(input, VDYErrors);
}


/* **********************************************************************
	Unit Design for vdyMonitorInputParameters is found in Declaration Section
**************************************************************************** */

STATIC_MTD void vdyMonitorInputParameters(VDYInputData_t *input, VDYErrors_t *VDYErrors)
{
  VDYActState_t ParameterError = VDY_STAT_INACTIVE;

  /* Check for invalid parameter if parameter is used */
#if (   ((!defined(CFG_VDY_DIS_SIDE_SLIP_ANGLE_ESTIMATION)) || (!CFG_VDY_DIS_SIDE_SLIP_ANGLE_ESTIMATION)) \
     || ((!defined(CFG_VDY_DIS_WHEEL_PRE_PROCESSING)) || (!CFG_VDY_DIS_WHEEL_PRE_PROCESSING)) )
  /* Check that vehicle weight parameter is valid (might be on a default if not valid) */
  if (    ((sint32)VDY_GET_IO_STATE(VDY_PAR_POS_VEHWGT, input->Parameter.State) != VDY_IO_STATE_VALID)
       && ((sint32)VDY_GET_IO_STATE(VDY_PAR_POS_VEHWGT, input->Parameter.State) != VDY_IO_STATE_SUBSTITUE)  )
  {
    ParameterError = VDY_STAT_ACTIVE;
  }
  /* Check that vehicle weight parameter is within range */
  if ((input->Parameter.VehWeight < MINIMUM_VEH_WEIGHT) || (input->Parameter.VehWeight > MAXIMUM_VEH_WEIGHT))
  {
    ParameterError = VDY_STAT_ACTIVE;
    input->Parameter.VehWeight = DEFAULT_VEH_WEIGHT;
    VDY_SET_IO_STATE(VDY_PAR_POS_VEHWGT, VDY_IO_STATE_SUBSTITUE, input->Parameter.State);
  }
#endif

#if ( (!defined(CFG_VDY_DIS_WHEEL_PRE_PROCESSING)) || (!CFG_VDY_DIS_WHEEL_PRE_PROCESSING) )
  /* Check that track width front parameter is valid (might be on a default if not valid) */
  if (    ((sint32)VDY_GET_IO_STATE(VDY_PAR_POS_TWDFR, input->Parameter.State) != VDY_IO_STATE_VALID)
       && ((sint32)VDY_GET_IO_STATE(VDY_PAR_POS_TWDFR, input->Parameter.State) != VDY_IO_STATE_SUBSTITUE)  )
  {
    ParameterError = VDY_STAT_ACTIVE;
  }
  /* Check that track width front parameter is within range */
  if ((input->Parameter.TrackWidthFront < MINIMUM_TRACK_WIDTH) || (input->Parameter.TrackWidthFront > MAXIMUM_TRACK_WIDTH))
  {
    ParameterError = VDY_STAT_ACTIVE;
    input->Parameter.TrackWidthFront = DEFAULT_TRACK_WIDTH;
    VDY_SET_IO_STATE(VDY_PAR_POS_TWDFR, VDY_IO_STATE_SUBSTITUE, input->Parameter.State);
  }

  /* Check that track width rear parameter is valid (might be on a default if not valid) */
  if (    ((sint32)VDY_GET_IO_STATE(VDY_PAR_POS_TWDRE, input->Parameter.State) != VDY_IO_STATE_VALID)
       && ((sint32)VDY_GET_IO_STATE(VDY_PAR_POS_TWDRE, input->Parameter.State) != VDY_IO_STATE_SUBSTITUE)  )
  {
    ParameterError = VDY_STAT_ACTIVE;
  }
  /* Check that track width parameter rear is within range */
  if ((input->Parameter.TrackWidthRear < MINIMUM_TRACK_WIDTH) || (input->Parameter.TrackWidthRear > MAXIMUM_TRACK_WIDTH))
  {
    ParameterError = VDY_STAT_ACTIVE;
    input->Parameter.TrackWidthRear = DEFAULT_TRACK_WIDTH;
    VDY_SET_IO_STATE(VDY_PAR_POS_TWDRE, VDY_IO_STATE_SUBSTITUE, input->Parameter.State);
  }
#endif

  /* Check that wheel base parameter is valid (might be on a default if not valid) */
  if (    ((sint32)VDY_GET_IO_STATE(VDY_PAR_POS_WBASE, input->Parameter.State) != VDY_IO_STATE_VALID)
       && ((sint32)VDY_GET_IO_STATE(VDY_PAR_POS_WBASE, input->Parameter.State) != VDY_IO_STATE_SUBSTITUE)  )
  {
    ParameterError = VDY_STAT_ACTIVE;
  }
  /* Check that wheel base parameter is within range */
  if ((input->Parameter.WheelBase < MINIMUM_WHEEL_BASE) || (input->Parameter.WheelBase > MAXIMUM_WHEEL_BASE))
  {
    ParameterError = VDY_STAT_ACTIVE;
    input->Parameter.WheelBase = DEFAULT_WHEEL_BASE;
    VDY_SET_IO_STATE(VDY_PAR_POS_WBASE, VDY_IO_STATE_SUBSTITUE, input->Parameter.State);
  }

  /* Check that steering ratio parameter is valid (might be on a default if not valid) */
  if (    ((sint32)VDY_GET_IO_STATE(VDY_PAR_POS_SWARAT, input->Parameter.State) != VDY_IO_STATE_VALID)
       && ((sint32)VDY_GET_IO_STATE(VDY_PAR_POS_SWARAT, input->Parameter.State) != VDY_IO_STATE_SUBSTITUE)  )
  {
    ParameterError = VDY_STAT_ACTIVE;
  }
#if (!CFG_VDY_DIS_STW_ANGLE_SENSOR_PRE_PROCESSING)
  /* Check that steering ratio parameter is within range */
  if ((input->Parameter.SteeringRatio.swa.rat[1] < MINIMUM_STEERING_RATIO) || (input->Parameter.SteeringRatio.swa.rat[1] > MAXIMUM_STEERING_RATIO))
  {
    ParameterError = VDY_STAT_ACTIVE;
    input->Parameter.SteeringRatio.swa.rat[1] = DEFAULT_STEERING_RATIO;
    VDY_SET_IO_STATE(VDY_PAR_POS_SWARAT, VDY_IO_STATE_SUBSTITUE, input->Parameter.State);
  }

  /* Check that self steering gradient parameter is valid (might be on a default if not valid) */
  if (    ((sint32)VDY_GET_IO_STATE(VDY_PAR_POS_SSG, input->Parameter.State) != VDY_IO_STATE_VALID)
       && ((sint32)VDY_GET_IO_STATE(VDY_PAR_POS_SSG, input->Parameter.State) != VDY_IO_STATE_SUBSTITUE)  )
  {
    ParameterError = VDY_STAT_ACTIVE;
  }
  /* Check that steering gradient parameter is within range */
  if ((input->Parameter.SelfSteerGrad < MINIMUM_SELF_STEERING_GRAD) || (input->Parameter.SelfSteerGrad > MAXIMUM_SELF_STEERING_GRAD))
  {
    ParameterError = VDY_STAT_ACTIVE;
    input->Parameter.SelfSteerGrad = DEFAULT_SELF_STEERING_GRAD;
    VDY_SET_IO_STATE(VDY_PAR_POS_SSG, VDY_IO_STATE_SUBSTITUE, input->Parameter.State);
  }
#endif

#if ( (!defined(CFG_VDY_DIS_WHEEL_PRE_PROCESSING)) || (!CFG_VDY_DIS_WHEEL_PRE_PROCESSING) )
  /* Check that wheelticks parameter is valid (might be on a default if not valid) */
  if (    ((sint32)VDY_GET_IO_STATE(VDY_PAR_POS_WTCKSREV, input->Parameter.State) != VDY_IO_STATE_VALID)
       && ((sint32)VDY_GET_IO_STATE(VDY_PAR_POS_WTCKSREV, input->Parameter.State) != VDY_IO_STATE_SUBSTITUE)  )
  {
    ParameterError = VDY_STAT_ACTIVE;
  }
  /* Check that wheelticks parameter is within range */
  if ((input->Parameter.WhlTcksPerRev < MINIMUM_WHEEL_TICKS_REV) || (input->Parameter.WhlTcksPerRev > MAXIMUM_WHEEL_TICKS_REV))
  {
    ParameterError = VDY_STAT_ACTIVE;
    input->Parameter.WhlTcksPerRev = DEFAULT_WHEEL_TICKS_REV;
    VDY_SET_IO_STATE(VDY_PAR_POS_WTCKSREV, VDY_IO_STATE_SUBSTITUE, input->Parameter.State);
  }
#endif

#if ( (!defined(CFG_VDY_DIS_WHEEL_PRE_PROCESSING)) || (!CFG_VDY_DIS_WHEEL_PRE_PROCESSING) )
  /* Check that center of gravity height parameter is valid (might be on a default if not valid) */
  if (    ((sint32)VDY_GET_IO_STATE(VDY_PAR_POS_COGH, input->Parameter.State) != VDY_IO_STATE_VALID)
       && ((sint32)VDY_GET_IO_STATE(VDY_PAR_POS_COGH, input->Parameter.State) != VDY_IO_STATE_SUBSTITUE)  )
  {
    ParameterError = VDY_STAT_ACTIVE;
  }
  /* Check that center of gravity height parameter is within range */
  if ((input->Parameter.CntrOfGravHeight < MINIMUM_COGH) || (input->Parameter.CntrOfGravHeight > MAXIMUM_COGH))
  {
    ParameterError = VDY_STAT_ACTIVE;
    input->Parameter.CntrOfGravHeight = DEFAULT_COGH;
    VDY_SET_IO_STATE(VDY_PAR_POS_COGH, VDY_IO_STATE_SUBSTITUE, input->Parameter.State);
  }
#endif

#if ( (!defined(CFG_VDY_DIS_WHEEL_PRE_PROCESSING)) || (!CFG_VDY_DIS_WHEEL_PRE_PROCESSING) )
  /* Check that wheel circumference parameter is valid (might be on a default if not valid) */
  if (    ((sint32)VDY_GET_IO_STATE(VDY_PAR_POS_WHLCIR, input->Parameter.State) != VDY_IO_STATE_VALID)
       && ((sint32)VDY_GET_IO_STATE(VDY_PAR_POS_WHLCIR, input->Parameter.State) != VDY_IO_STATE_SUBSTITUE)  )
  {
    ParameterError = VDY_STAT_ACTIVE;
  }
  /* Check that wheel circumference parameter is within range */
  if ((input->Parameter.WhlCircumference < MINIMUM_WHEEL_CIRCUM) || (input->Parameter.WhlCircumference > MAXIMUM_WHEEL_CIRCUM))
  {
    ParameterError = VDY_STAT_ACTIVE;
    input->Parameter.WhlCircumference = DEFAULT_WHEEL_CIRCUM;
    VDY_SET_IO_STATE(VDY_PAR_POS_WHLCIR, VDY_IO_STATE_SUBSTITUE, input->Parameter.State);
  }
#endif

#if ( (!defined(CFG_VDY_DIS_WHEEL_PRE_PROCESSING)) || (!CFG_VDY_DIS_WHEEL_PRE_PROCESSING) )
  /* Check that axle load distribution parameter is valid (might be on a default if not valid) */
  if (    ((sint32)VDY_GET_IO_STATE(VDY_PAR_POS_AXLD, input->Parameter.State) != VDY_IO_STATE_VALID)
       && ((sint32)VDY_GET_IO_STATE(VDY_PAR_POS_AXLD, input->Parameter.State) != VDY_IO_STATE_SUBSTITUE)  )
  {
    ParameterError = VDY_STAT_ACTIVE;
  }
  /* Check that axle load distribution parameter is within range */
  if ((input->Parameter.AxisLoadDistr < MINIMUM_AXLE_LOAD_DISTR) || (input->Parameter.AxisLoadDistr > MAXIMUM_AXLE_LOAD_DISTR))
  {
    ParameterError = VDY_STAT_ACTIVE;
    input->Parameter.AxisLoadDistr = DEFAULT_AXLE_LOAD_DISTR;
    VDY_SET_IO_STATE(VDY_PAR_POS_AXLD, VDY_IO_STATE_SUBSTITUE, input->Parameter.State);
  }
#endif

#if ( (!defined(CFG_VDY_DIS_WHEEL_PRE_PROCESSING)) || (!CFG_VDY_DIS_WHEEL_PRE_PROCESSING) )
  /* Check that wheel load dependency front parameter is valid (might be on a default if not valid) */
  if (    ((sint32)VDY_GET_IO_STATE(VDY_PAR_POS_WHLDFR, input->Parameter.State) != VDY_IO_STATE_VALID)
       && ((sint32)VDY_GET_IO_STATE(VDY_PAR_POS_WHLDFR, input->Parameter.State) != VDY_IO_STATE_SUBSTITUE)  )
  {
    ParameterError = VDY_STAT_ACTIVE;
  }
  /* Check that wheel load dependency front parameter is within range */
  if ((input->Parameter.WhlLoadDepFrontAxle < MINIMUM_WHEEL_LOAD_DEP) || (input->Parameter.WhlLoadDepFrontAxle > MAXIMUM_WHEEL_LOAD_DEP))
  {
    ParameterError = VDY_STAT_ACTIVE;
    input->Parameter.WhlLoadDepFrontAxle = DEFAULT_WHEEL_LOAD_DEP;
    VDY_SET_IO_STATE(VDY_PAR_POS_WHLDFR, VDY_IO_STATE_SUBSTITUE, input->Parameter.State);
  }
#endif

#if ( (!defined(CFG_VDY_DIS_WHEEL_PRE_PROCESSING)) || (!CFG_VDY_DIS_WHEEL_PRE_PROCESSING) )
  /* Check that wheel load dependency rear parameter is valid (might be on a default if not valid) */
  if (    ((sint32)VDY_GET_IO_STATE(VDY_PAR_POS_WHLDRE, input->Parameter.State) != VDY_IO_STATE_VALID)
       && ((sint32)VDY_GET_IO_STATE(VDY_PAR_POS_WHLDRE, input->Parameter.State) != VDY_IO_STATE_SUBSTITUE)  )
  {
    ParameterError = VDY_STAT_ACTIVE;
  }
  /* Check that wheel load dependency rear parameter is within range */
  if ((input->Parameter.WhlLoadDepRearAxle < MINIMUM_WHEEL_LOAD_DEP) || (input->Parameter.WhlLoadDepRearAxle > MAXIMUM_WHEEL_LOAD_DEP))
  {
    ParameterError = VDY_STAT_ACTIVE;
    input->Parameter.WhlLoadDepRearAxle = DEFAULT_WHEEL_LOAD_DEP;
    VDY_SET_IO_STATE(VDY_PAR_POS_WHLDRE, VDY_IO_STATE_SUBSTITUE, input->Parameter.State);
  }
#endif

  /* Set parameter error in input parameter struct */
  if (ParameterError == VDY_STAT_ACTIVE)
  {
    VDYErrors->ParInputErrors.InputParameterError = VDY_ERR_STATE_ACTIVE;
  }
  else
  {
    VDYErrors->ParInputErrors.InputParameterError = VDY_ERR_STATE_INACTIVE;
  }
}


/* **********************************************************************
	Unit Design for vdyMonitorInputSignals is found in Declaration Section
**************************************************************************** */

STATIC_MTD void vdyMonitorInputSignals(VDYInputData_t *input, VDYErrors_t *VDYErrors)
{
  VDYActState_t SignalError = VDY_STAT_INACTIVE;

  /* Check yaw rate */
  if ((sint32)VDY_GET_IO_STATE(VDY_SIN_POS_YWR, input->Signals.State) == VDY_IO_STATE_VALID)
  {
    /* Check if allowed maximum value is exceeded */
    if (input->Signals.YawRate > MAX_YAWRATE)
    {
      SignalError = VDY_STAT_ACTIVE;
      input->Signals.YawRate = MAX_YAWRATE;
      VDY_SET_IO_STATE(VDY_SIN_POS_YWR, VDY_IO_STATE_SUBSTITUE, input->Signals.State);
    }
    else if (input->Signals.YawRate < -MAX_YAWRATE)
    {
      SignalError = VDY_STAT_ACTIVE;
      input->Signals.YawRate = -MAX_YAWRATE;
      VDY_SET_IO_STATE(VDY_SIN_POS_YWR, VDY_IO_STATE_SUBSTITUE, input->Signals.State);
    }
    else
    {
      /* nothing to do */
    }
  }

#if ((!defined(CFG_VDY_DIS_STW_ANGLE_SENSOR_PRE_PROCESSING)) || (!CFG_VDY_DIS_STW_ANGLE_SENSOR_PRE_PROCESSING))
  /* Check steering angle */
  if ((sint32)VDY_GET_IO_STATE(VDY_SIN_POS_SWA, input->Signals.State) == VDY_IO_STATE_VALID)
  {
    /* Check if allowed maximum value is exceeded */
    if (input->Signals.StWheelAngle > (MAX_STEERING_ANGLE * input->Parameter.SteeringRatio.swa.rat[1]))
    {
      SignalError = VDY_STAT_ACTIVE;
      input->Signals.StWheelAngle = (MAX_STEERING_ANGLE * input->Parameter.SteeringRatio.swa.rat[1]);
      VDY_SET_IO_STATE(VDY_SIN_POS_SWA, VDY_IO_STATE_SUBSTITUE, input->Signals.State);
    }
    else if (input->Signals.StWheelAngle < -(MAX_STEERING_ANGLE * input->Parameter.SteeringRatio.swa.rat[1]))
    {
      SignalError = VDY_STAT_ACTIVE;
      input->Signals.StWheelAngle = -(MAX_STEERING_ANGLE * input->Parameter.SteeringRatio.swa.rat[1]);
      VDY_SET_IO_STATE(VDY_SIN_POS_SWA, VDY_IO_STATE_SUBSTITUE, input->Signals.State);
    }
    else
    {
      /* nothing to do */
    }
  }
#endif
#if ((!defined(CFG_VDY_REAR_WHEEL_STEERING)) || (CFG_VDY_REAR_WHEEL_STEERING))
    /* Check Rear steering angle */
  if ((sint32)VDY_GET_IO_STATE(VDY_SIN_POS_RSTA, input->Signals.State) == VDY_IO_STATE_VALID)
  {
    /* Check if allowed maximum value is exceeded */
    if (input->Signals.RearWhlAngle > (MAX_STEERING_ANGLE * input->Parameter.SteeringRatio.swa.rat[1]))
    {
      SignalError = VDY_STAT_ACTIVE;
      input->Signals.RearWhlAngle = (MAX_STEERING_ANGLE * input->Parameter.SteeringRatio.swa.rat[1]);
      VDY_SET_IO_STATE(VDY_SIN_POS_RSTA, VDY_IO_STATE_SUBSTITUE, input->Signals.State);
    }
    else if (input->Signals.RearWhlAngle < -(MAX_STEERING_ANGLE * input->Parameter.SteeringRatio.swa.rat[1]))
    {
      SignalError = VDY_STAT_ACTIVE;
      input->Signals.RearWhlAngle = -(MAX_STEERING_ANGLE * input->Parameter.SteeringRatio.swa.rat[1]);
      VDY_SET_IO_STATE(VDY_SIN_POS_RSTA, VDY_IO_STATE_SUBSTITUE, input->Signals.State);
    }
    else
    {
      /* nothing to do */
    }
  }
#endif

#if ((!defined(CFG_VDY_DIS_WHEEL_PRE_PROCESSING)) || (!CFG_VDY_DIS_WHEEL_PRE_PROCESSING))
  /* Check wheel velocity front left */
  //input->Signals.WhlVelFrLeft = (float32)CML_u_Abs(input->Signals.WhlVelFrLeft);
  if(input->Signals.WhlVelFrLeft < VDY_ZERO_F) 
  {
	  input->Signals.WhlVelFrLeft = -(input->Signals.WhlVelFrLeft);
  }
  if ((sint32)VDY_GET_IO_STATE(VDY_SIN_POS_WVEL_FL, input->Signals.State) == VDY_IO_STATE_VALID)
  {
    if (input->Signals.WhlVelFrLeft > MAX_VELOCITY)
    {
      input->Signals.WhlVelFrLeft = MAX_VELOCITY;
      SignalError = VDY_STAT_ACTIVE;
      VDY_SET_IO_STATE(VDY_SIN_POS_WVEL_FL, VDY_IO_STATE_SUBSTITUE, input->Signals.State);
    }
  }

  /* Check wheel velocity front right */
  //input->Signals.WhlVelFrRight = (float32)CML_u_Abs(input->Signals.WhlVelFrRight);
  if(input->Signals.WhlVelFrRight < VDY_ZERO_F) 
  {
	  input->Signals.WhlVelFrRight = -(input->Signals.WhlVelFrRight);
  }
  if ((sint32)VDY_GET_IO_STATE(VDY_SIN_POS_WVEL_FR, input->Signals.State) == VDY_IO_STATE_VALID) 
  {
    if (input->Signals.WhlVelFrRight > MAX_VELOCITY)
    {
      input->Signals.WhlVelFrRight = MAX_VELOCITY;
      SignalError = VDY_STAT_ACTIVE;
      VDY_SET_IO_STATE(VDY_SIN_POS_WVEL_FR, VDY_IO_STATE_SUBSTITUE, input->Signals.State);
    }
  }

  /* Check wheel velocity rear left */
  //input->Signals.WhlVelReLeft = (float32)CML_u_Abs(input->Signals.WhlVelReLeft);
  if(input->Signals.WhlVelReLeft < VDY_ZERO_F) 
  {
	  input->Signals.WhlVelReLeft = -(input->Signals.WhlVelReLeft);
  }
  if ((sint32)VDY_GET_IO_STATE(VDY_SIN_POS_WVEL_RL, input->Signals.State) == VDY_IO_STATE_VALID) 
  {
    if (input->Signals.WhlVelReLeft > MAX_VELOCITY)
    {
      input->Signals.WhlVelReLeft = MAX_VELOCITY;
      SignalError = VDY_STAT_ACTIVE;
      VDY_SET_IO_STATE(VDY_SIN_POS_WVEL_RL, VDY_IO_STATE_SUBSTITUE, input->Signals.State);
    }
  }

  /* Check wheel velocity rear right */
  //input->Signals.WhlVelReRight = (float32)CML_u_Abs(input->Signals.WhlVelReRight);
  if(input->Signals.WhlVelReRight < VDY_ZERO_F) 
  {
	  input->Signals.WhlVelReRight = -(input->Signals.WhlVelReRight);
  }
  if ((sint32)VDY_GET_IO_STATE(VDY_SIN_POS_WVEL_RR, input->Signals.State) == VDY_IO_STATE_VALID) 
  {
    if (input->Signals.WhlVelReRight > MAX_VELOCITY)
    {
      input->Signals.WhlVelReRight = MAX_VELOCITY;
      SignalError = VDY_STAT_ACTIVE;
      VDY_SET_IO_STATE(VDY_SIN_POS_WVEL_RR, VDY_IO_STATE_SUBSTITUE, input->Signals.State);
    }
  }
#endif

#if ((defined(CFG_VDY_USE_EX_LONG_VELO)) && (CFG_VDY_USE_EX_LONG_VELO))
  /* Check vehicle velocity */
  input->Signals.VehVelocityExt = CML_f_Abs(input->Signals.VehVelocityExt);
  if ((sint32)VDY_GET_IO_STATE(VDY_SIN_POS_VEHVEL_EXT, input->Signals.State) == VDY_IO_STATE_VALID)
  {
    /* Check if allowed maximum value is exceeded */
    if (input->Signals.VehVelocityExt > MAX_VELOCITY)
    {
      input->Signals.VehVelocityExt = MAX_VELOCITY;
      SignalError = VDY_STAT_ACTIVE;
      VDY_SET_IO_STATE(VDY_SIN_POS_VEHVEL_EXT, VDY_IO_STATE_SUBSTITUE, input->Signals.State);
    }
  }
#endif

#if ((defined(CFG_VDY_USE_EX_LONG_ACCEL)) && (CFG_VDY_USE_EX_LONG_ACCEL))
  /* Check longitudinal acceleration */
  if ((sint32)VDY_GET_IO_STATE(VDY_SIN_POS_VEHACL_EXT, input->Signals.State) == VDY_IO_STATE_VALID)
  {
    /* Check if allowed maximum value is exceeded */
    if (input->Signals.VehLongAccelExt > MAX_ACCELERATION)
    {
      SignalError = VDY_STAT_ACTIVE;
      input->Signals.VehLongAccelExt = MAX_ACCELERATION;
      VDY_SET_IO_STATE(VDY_SIN_POS_VEHACL_EXT, VDY_IO_STATE_SUBSTITUE, input->Signals.State);
    }
    if (input->Signals.VehLongAccelExt < -MAX_ACCELERATION)
    {
      SignalError = VDY_STAT_ACTIVE;
      input->Signals.VehLongAccelExt = -MAX_ACCELERATION;
      VDY_SET_IO_STATE(VDY_SIN_POS_VEHACL_EXT, VDY_IO_STATE_SUBSTITUE, input->Signals.State);
    }
  }
#endif

#if ((defined(CFG_VDY_BMW_LONG_ACCEL_MODEL)) && (CFG_VDY_BMW_LONG_ACCEL_MODEL))
  /* Check longitudinal acceleration */
  if ((sint32)VDY_GET_IO_STATE(VDY_SIN_POS_LONGA, input->Signals.State) == VDY_IO_STATE_VALID)
  {
    /* Check if allowed maximum value is exceeded */
    if (input->Signals.LongAccel > MAX_ACCELERATION)
    {
      SignalError = VDY_STAT_ACTIVE;
      input->Signals.LongAccel = MAX_ACCELERATION;
      VDY_SET_IO_STATE(VDY_SIN_POS_LONGA, VDY_IO_STATE_SUBSTITUE, input->Signals.State);
    }
    if (input->Signals.LongAccel < -MAX_ACCELERATION)
    {
      SignalError = VDY_STAT_ACTIVE;
      input->Signals.LongAccel = -MAX_ACCELERATION;
      VDY_SET_IO_STATE(VDY_SIN_POS_LONGA, VDY_IO_STATE_SUBSTITUE, input->Signals.State);
    }
  }
#endif
  
#if ((!defined(CFG_VDY_DIS_LAT_ACCEL_SENSOR_PRE_PROCESSING)) || (!CFG_VDY_DIS_LAT_ACCEL_SENSOR_PRE_PROCESSING))
  /* Check lateral acceleration */
  if ((sint32)VDY_GET_IO_STATE(VDY_SIN_POS_LATA, input->Signals.State) == VDY_IO_STATE_VALID)
  {
    /* Check if allowed maximum value is exceeded */
    if (input->Signals.LatAccel > MAX_ACCELERATION)
    {
      SignalError = VDY_STAT_ACTIVE;
      input->Signals.LatAccel = MAX_ACCELERATION;
      VDY_SET_IO_STATE(VDY_SIN_POS_LATA, VDY_IO_STATE_SUBSTITUE, input->Signals.State);
    }
    if (input->Signals.LatAccel < -MAX_ACCELERATION)
    {
      SignalError = VDY_STAT_ACTIVE;
      input->Signals.LatAccel = -MAX_ACCELERATION;
      VDY_SET_IO_STATE(VDY_SIN_POS_LATA, VDY_IO_STATE_SUBSTITUE, input->Signals.State);
    }
  }
#endif

  /* Set signal error in input signal struct */
  if (SignalError == VDY_STAT_ACTIVE)
  {
    VDYErrors->SignalInputErrors.InputSignalError = VDY_ERR_STATE_ACTIVE;
  }
  else
  {
    VDYErrors->SignalInputErrors.InputSignalError = VDY_ERR_STATE_INACTIVE;
  }
}


/* **********************************************************************
	Unit Design for vdyCheckSignalPeakError is found in Declaration Section
**************************************************************************** */

#if (VDY_VEH_DYN_INTFVER <= 5)
STATIC_MTD VDYActState_t vdyCheckSignalPeakError(float32 *pInputSignal, float32 *pLastInputSignal, VDYIoState_t const *pInputSignalState, VDYIoState_t *pLastInputSignalState, uint32 Signal, float32 Threshold)
#else
STATIC_MTD VDYActState_t vdyCheckSignalPeakError(float32 *pInputSignal, float32 *pLastInputSignal, VDYIoStateTypes_t pInputSignalState[], VDYIoStateTypes_t pLastInputSignalState[], uint32 Signal, float32 Threshold)
#endif
{
  VDYActState_t SignalPeakError = VDY_STAT_INACTIVE;
  float32 fDiff;

  /* check for signal peaks between the current and the last cycle */
  fDiff = *pInputSignal - *pLastInputSignal;
  if ((CML_f_Abs(fDiff) > Threshold) && ((sint32)VDY_GET_IO_STATE(Signal, pInputSignalState) == VDY_IO_STATE_VALID) && ((sint32)VDY_GET_IO_STATE(Signal, pLastInputSignalState) == VDY_IO_STATE_VALID))
  {
    /* Limit the signal gain to the threshold */
    if (fDiff > VDY_ZERO_F)
    {
      *pLastInputSignal = *pLastInputSignal + Threshold;
    }
    else
    {
      *pLastInputSignal = *pLastInputSignal - Threshold;
    }
    *pInputSignal     = *pLastInputSignal;
    SignalPeakError   = VDY_STAT_ACTIVE;
    VDY_SET_IO_STATE(Signal, VDY_IO_STATE_DECREASED, pInputSignalState);
  }
  else
  {
    *pLastInputSignal = *pInputSignal;
  }
  /* store the signal state of the previous cycle signal value */
  VDY_SET_IO_STATE(Signal, VDY_GET_IO_STATE(Signal, pInputSignalState), pLastInputSignalState);

  return SignalPeakError;
}


/* **********************************************************************
	Unit Design for vdyInitForCheckSignalPeakErrors is found in vdy.h
**************************************************************************** */

void vdyInitForCheckSignalPeakErrors(const VDYInputData_t *pInput)
{
  LastInputSignals.YawRate              = pInput->Signals.YawRate;
  VDY_SET_IO_STATE(VDY_SIN_POS_YWR,VDY_GET_IO_STATE(VDY_SIN_POS_YWR, pInput->Signals.State),LastInputSignals.State);
  LastInputSignals.StWheelAngle         = pInput->Signals.StWheelAngle;
  VDY_SET_IO_STATE(VDY_SIN_POS_SWA,VDY_GET_IO_STATE(VDY_SIN_POS_SWA, pInput->Signals.State),LastInputSignals.State);
  LastInputSignals.VehVelocityExt       = pInput->Signals.VehVelocityExt;
  VDY_SET_IO_STATE(VDY_SIN_POS_VEHVEL_EXT,VDY_GET_IO_STATE(VDY_SIN_POS_VEHVEL_EXT, pInput->Signals.State),LastInputSignals.State);
  LastInputSignals.LatAccel             = pInput->Signals.LatAccel;
  VDY_SET_IO_STATE(VDY_SIN_POS_LATA,VDY_GET_IO_STATE(VDY_SIN_POS_LATA, pInput->Signals.State),LastInputSignals.State);
  LastInputSignals.WhlVelFrLeft         = pInput->Signals.WhlVelFrLeft;
  VDY_SET_IO_STATE(VDY_SIN_POS_WVEL_FL,VDY_GET_IO_STATE(VDY_SIN_POS_WVEL_FL, pInput->Signals.State),LastInputSignals.State);
  LastInputSignals.WhlVelFrRight        = pInput->Signals.WhlVelFrRight;
  VDY_SET_IO_STATE(VDY_SIN_POS_WVEL_FR,VDY_GET_IO_STATE(VDY_SIN_POS_WVEL_FR, pInput->Signals.State),LastInputSignals.State);
  LastInputSignals.WhlVelReLeft         = pInput->Signals.WhlVelReLeft;
  VDY_SET_IO_STATE(VDY_SIN_POS_WVEL_RL,VDY_GET_IO_STATE(VDY_SIN_POS_WVEL_RL, pInput->Signals.State),LastInputSignals.State);
  LastInputSignals.WhlVelReRight        = pInput->Signals.WhlVelReRight;
  VDY_SET_IO_STATE(VDY_SIN_POS_WVEL_RR,VDY_GET_IO_STATE(VDY_SIN_POS_WVEL_RR, pInput->Signals.State),LastInputSignals.State);
  LastInputSignals.VehLongAccelExt      = pInput->Signals.VehLongAccelExt;
  VDY_SET_IO_STATE(VDY_SIN_POS_VEHACL_EXT,VDY_GET_IO_STATE(VDY_SIN_POS_VEHACL_EXT, pInput->Signals.State),LastInputSignals.State);
  LastInputSignals.RearWhlAngle         = pInput->Signals.RearWhlAngle;
  VDY_SET_IO_STATE(VDY_SIN_POS_RSTA,VDY_GET_IO_STATE(VDY_SIN_POS_RSTA, pInput->Signals.State),LastInputSignals.State);
  #if ((defined(CFG_VDY_BMW_LONG_ACCEL_MODEL)) && (CFG_VDY_BMW_LONG_ACCEL_MODEL))
  LastInputSignals.LongAccel		    = pInput->Signals.LongAccel;
  VDY_SET_IO_STATE(VDY_SIN_POS_LONGA,VDY_GET_IO_STATE(VDY_SIN_POS_LONGA, pInput->Signals.State),LastInputSignals.State);
  #endif
}


/* **********************************************************************
	Unit Design for vdyCheckForSignalPeakErrors is found in Declaration Section
**************************************************************************** */

STATIC_MTD void vdyCheckForSignalPeakErrors( VDYInputData_t *pInput, VDYErrors_t *pVDYErrors)
{
  VDYActState_t SignalPeakError = VDY_STAT_INACTIVE;

  /* check for signal peaks between the actual and the last cycle */
  /* yaw rate */
#if ( (!defined(CFG_VDY_DIS_YAW_SENSOR_PRE_PROCESSING)) || (!CFG_VDY_DIS_YAW_SENSOR_PRE_PROCESSING) )
  if (vdyCheckSignalPeakError(&pInput->Signals.YawRate,
                              &LastInputSignals.YawRate,
                              pInput->Signals.State,
                              LastInputSignals.State,
                              VDY_SIN_POS_YWR,
                              VDY_PAR_YAW_RATE_INPUT_PEAK) == VDY_STAT_ACTIVE)
  {
    SignalPeakError = VDY_STAT_ACTIVE;
  }
  else
  {
    // nothing to do
  }
#endif

  /* steering wheel angle */
#if ((!defined(CFG_VDY_DIS_STW_ANGLE_SENSOR_PRE_PROCESSING)) || (!CFG_VDY_DIS_STW_ANGLE_SENSOR_PRE_PROCESSING))
  if (vdyCheckSignalPeakError(&pInput->Signals.StWheelAngle,
                              &LastInputSignals.StWheelAngle,
                              pInput->Signals.State,
                              LastInputSignals.State,
                              VDY_SIN_POS_SWA,
                              VDY_PAR_SWA_INPUT_PEAK) == VDY_STAT_ACTIVE)
  {
    SignalPeakError = VDY_STAT_ACTIVE;
  }
  else
  {
    // nothing to do
  }
#endif

  /* Rear steering wheel angle */
  if (vdyCheckSignalPeakError(&pInput->Signals.RearWhlAngle,
                              &LastInputSignals.RearWhlAngle,
                              pInput->Signals.State,
                              LastInputSignals.State,
                              VDY_SIN_POS_RSTA,
                              VDY_PAR_SWA_INPUT_PEAK) == VDY_STAT_ACTIVE)
  {
    SignalPeakError = VDY_STAT_ACTIVE;
  }
  else
  {
    // nothing to do
  }


  /* vehicle velocity */
#if ((defined(CFG_VDY_USE_EX_LONG_VELO)) && (CFG_VDY_USE_EX_LONG_VELO))
  if (vdyCheckSignalPeakError(&pInput->Signals.VehVelocityExt,
                              &LastInputSignals.VehVelocityExt,
                              pInput->Signals.State,
                              LastInputSignals.State,
                              VDY_SIN_POS_VEHVEL_EXT,
                              VDY_PAR_WHEEL_VELO_INPUT_PEAK) == VDY_STAT_ACTIVE)
  {
    SignalPeakError = VDY_STAT_ACTIVE;
  }
  else
  {
    // nothing to do
  }
#endif

  /* lateral acceleration */
#if ((!defined(CFG_VDY_DIS_LAT_ACCEL_SENSOR_PRE_PROCESSING)) || (!CFG_VDY_DIS_LAT_ACCEL_SENSOR_PRE_PROCESSING))
  if (vdyCheckSignalPeakError(&pInput->Signals.LatAccel,
                                &LastInputSignals.LatAccel,
                                pInput->Signals.State,
                                LastInputSignals.State,
                                VDY_SIN_POS_LATA,
                                VDY_PAR_LAT_ACCEL_INPUT_PEAK) == VDY_STAT_ACTIVE)
  {
    SignalPeakError = VDY_STAT_ACTIVE;
  }
  else
  {
    // nothing to do
  }
#endif

#if ( (!defined(CFG_VDY_DIS_WHEEL_PRE_PROCESSING)) || (!CFG_VDY_DIS_WHEEL_PRE_PROCESSING) )
  /* WhlVelFrLeft */
  if (vdyCheckSignalPeakError(&pInput->Signals.WhlVelFrLeft,
                              &LastInputSignals.WhlVelFrLeft,
                              pInput->Signals.State,
                              LastInputSignals.State,
                              VDY_SIN_POS_WVEL_FL,
                              VDY_PAR_WHEEL_VELO_INPUT_PEAK) == VDY_STAT_ACTIVE)
  {
    SignalPeakError = VDY_STAT_ACTIVE;
  }
  else
  {
    // nothing to do
  }

  /* WhlVelFrRight */
  if (vdyCheckSignalPeakError(&pInput->Signals.WhlVelFrRight,
                              &LastInputSignals.WhlVelFrRight,
                              pInput->Signals.State,
                              LastInputSignals.State,
                              VDY_SIN_POS_WVEL_FR,
                              VDY_PAR_WHEEL_VELO_INPUT_PEAK) == VDY_STAT_ACTIVE)
  {
    SignalPeakError = VDY_STAT_ACTIVE;
  }
  else
  {
    // nothing to do
  }

  /* WhlVelReLeft */
  if (vdyCheckSignalPeakError(&pInput->Signals.WhlVelReLeft,
                              &LastInputSignals.WhlVelReLeft,
                              pInput->Signals.State,
                              LastInputSignals.State,
                              VDY_SIN_POS_WVEL_RL,
                              VDY_PAR_WHEEL_VELO_INPUT_PEAK) == VDY_STAT_ACTIVE)
  {
    SignalPeakError = VDY_STAT_ACTIVE;
  }
  else
  {
    // nothing to do
  }

  /* WhlVelReRight */
  if (vdyCheckSignalPeakError(&pInput->Signals.WhlVelReRight,
                              &LastInputSignals.WhlVelReRight,
                              pInput->Signals.State,
                              LastInputSignals.State,
                              VDY_SIN_POS_WVEL_RR,
                              VDY_PAR_WHEEL_VELO_INPUT_PEAK) == VDY_STAT_ACTIVE)
  {
    SignalPeakError = VDY_STAT_ACTIVE;
  }
  else
  {
    // nothing to do
  }
#endif

#if ((defined(CFG_VDY_USE_EX_LONG_ACCEL)) && (CFG_VDY_USE_EX_LONG_ACCEL))
  if (vdyCheckSignalPeakError(&pInput->Signals.VehLongAccelExt,
                              &LastInputSignals.VehLongAccelExt,
                              pInput->Signals.State,
                              LastInputSignals.State,
                              VDY_SIN_POS_VEHACL_EXT,
                              VDY_PAR_LONG_ACCEL_INPUT_PEAK) == VDY_STAT_ACTIVE)
  {
    SignalPeakError = VDY_STAT_ACTIVE;
  }
  else
  {
    // nothing to do
  }
#endif

#if ((defined(CFG_VDY_BMW_LONG_ACCEL_MODEL)) && (CFG_VDY_BMW_LONG_ACCEL_MODEL))
  if (vdyCheckSignalPeakError(&pInput->Signals.LongAccel,
                              &LastInputSignals.LongAccel,
                              pInput->Signals.State,
                              LastInputSignals.State,
                              VDY_SIN_POS_LONGA,
                              VDY_PAR_LONG_ACCEL_INPUT_PEAK) == VDY_STAT_ACTIVE)
  {
    SignalPeakError = VDY_STAT_ACTIVE;
  }
  else
  {
    // nothing to do
  }
#endif

  /* Set signal Peak error in the input signal struct */
  if (SignalPeakError == VDY_STAT_ACTIVE)
  {
    pVDYErrors->SignalInputErrors.InputSignalPeakError = VDY_ERR_STATE_ACTIVE;
  }
  else
  {
    pVDYErrors->SignalInputErrors.InputSignalPeakError = VDY_ERR_STATE_INACTIVE;
  }
}


/* **********************************************************************
	Unit Design for vdyMonitorVelocityOutput is found in Declaration Section
**************************************************************************** */

STATIC_MTD void vdyMonitorVelocityOutput(const proVdyPrtList_t *proPorts, const VDYInputData_t *input)
{
  if ((sint32)VDY_GET_IO_STATE(VDY_SOUT_POS_VELOCITY, proPorts->pVehicleDynamicSignals->State) != VDY_IO_STATE_VALID)
  {
    proPorts->pVDYErrors->OutPutErrors.VDY_VEH_VEL_NOT_AVAILABLE = VDY_ERR_STATE_ACTIVE;
  }

  #if ( (defined(CFG_VDY_VELO_VARIANCE_CHECK)) && (CFG_VDY_VELO_VARIANCE_CHECK) )
  else
  {
      if ((CML_f_Abs(input->Signals.VehLongAccelExt) > VDY_ACC_THRESHOLD_INC_VELOCITY_VAR) && (proPorts->pVehicleDynamicSignals->Longitudinal.varVelocity > VDY_VELOCITY_MAX_VARIANCE_DYNAMIC))
    {
      #if ( (defined(CFG_VDY_DEBOUNCE_OUTPUTS)) && (CFG_VDY_DEBOUNCE_OUTPUTS) )
      if (u_Debouce_VDY_VEH_VEL_NOT_AVAILABLE >= VDY_MAX_OUTPUT_DEBOUNCING)
      {
        proPorts->pVDYErrors->OutPutErrors.VDY_VEH_VEL_NOT_AVAILABLE = VDY_ERR_STATE_ACTIVE;
      }
      else
      {
        (u_Debouce_VDY_VEH_VEL_NOT_AVAILABLE)++;
      }
      #else
      proPorts->pVDYErrors->OutPutErrors.VDY_VEH_VEL_NOT_AVAILABLE = VDY_ERR_STATE_ACTIVE;
      #endif
    }

    else if ((CML_f_Abs(input->Signals.VehLongAccelExt) <= VDY_ACC_THRESHOLD_INC_VELOCITY_VAR) && (proPorts->pVehicleDynamicSignals->Longitudinal.varVelocity > VDY_VELOCITY_MAX_VARIANCE))
    {
      #if ( (defined(CFG_VDY_DEBOUNCE_OUTPUTS)) && (CFG_VDY_DEBOUNCE_OUTPUTS) )
      if (u_Debouce_VDY_VEH_VEL_NOT_AVAILABLE >= VDY_MAX_OUTPUT_DEBOUNCING)
      {
        proPorts->pVDYErrors->OutPutErrors.VDY_VEH_VEL_NOT_AVAILABLE = VDY_ERR_STATE_ACTIVE;
      }
      else
      {
        (u_Debouce_VDY_VEH_VEL_NOT_AVAILABLE)++;
      }
      #else
      proPorts->pVDYErrors->OutPutErrors.VDY_VEH_VEL_NOT_AVAILABLE = VDY_ERR_STATE_ACTIVE;
      #endif
    }

    else
    {
      proPorts->pVDYErrors->OutPutErrors.VDY_VEH_VEL_NOT_AVAILABLE = VDY_ERR_STATE_INACTIVE;

      #if ( (defined(CFG_VDY_DEBOUNCE_OUTPUTS)) && (CFG_VDY_DEBOUNCE_OUTPUTS) )
      u_Debouce_VDY_VEH_VEL_NOT_AVAILABLE = 0;
      #endif
    }
  }
  #else

  else
  {
    proPorts->pVDYErrors->OutPutErrors.VDY_VEH_VEL_NOT_AVAILABLE = VDY_ERR_STATE_INACTIVE;
  }

#endif

}


/* **********************************************************************
	Unit Design for vdyMonitorYawrateOutput is found in Declaration Section
**************************************************************************** */

STATIC_MTD void vdyMonitorYawrateOutput(const proVdyPrtList_t *proPorts)
{
  fVelocity_t fVelocity;
  /*check velocity*/
  fVelocity = proPorts->pVehicleDynamicSignals->Longitudinal.Velocity;
  if ((proPorts->pVehicleDynamicSignals->MotionState.MotState == (MotState_t)VDY_LONG_MOT_STATE_MOVE_RWD) && (fVelocity > VDY_ZERO_F))
  {
    fVelocity = -fVelocity;
  }

  /*check yaw rate*/
  /* <ln_offset:+1 PCLINT Error 845: reviewer name: Jochen Spruck date: 3-08-2011 reason: proven in use */
  if(((sint32)VDY_GET_IO_STATE(VDY_SOUT_POS_YAWRATE, proPorts->pVehicleDynamicSignals->State) != VDY_IO_STATE_VALID ) &&
     ((sint32)VDY_GET_IO_STATE(VDY_SOUT_POS_YAWRATE, proPorts->pVehicleDynamicSignals->State) != VDY_IO_STATE_DECREASED ))
  {
    if(fVelocity > VDY_YAWRATE_MIN_VELOCITY)
    {
      proPorts->pVDYErrors->OutPutErrors.VDY_VEH_YWR_NOT_AVAILABLE = VDY_ERR_STATE_ACTIVE;
    }
    else
    {
      /* stay in current mode */
    }
  }

  #if ( (defined(CFG_VDY_YAWRATE_VARIANCE_CHECK)) && (CFG_VDY_YAWRATE_VARIANCE_CHECK) )
  else
  {
    if(proPorts->pVehicleDynamicSignals->Lateral.YawRate.Variance > VDY_YAWRATE_MAX_VARIANCE)
    {
      if(fVelocity > VDY_YAWRATE_MIN_VELOCITY)
      {
        proPorts->pVDYErrors->OutPutErrors.VDY_VEH_YWR_NOT_AVAILABLE = VDY_ERR_STATE_ACTIVE;
      }
      else
      {
        /* stay in current mode */
      }
    }
    else
    {
      proPorts->pVDYErrors->OutPutErrors.VDY_VEH_YWR_NOT_AVAILABLE = VDY_ERR_STATE_INACTIVE;
    }
  }
  #else

  else
  {
    proPorts->pVDYErrors->OutPutErrors.VDY_VEH_YWR_NOT_AVAILABLE = VDY_ERR_STATE_INACTIVE;
  }

  #endif
}


#if ( (defined(CFG_VDY_MON_OUTPUT_PEAKS)) && (CFG_VDY_MON_OUTPUT_PEAKS) )
/* **********************************************************************
	Unit Design for vdyMonitorOutputPeaks is found in Declaration Section
**************************************************************************** */

STATIC_MTD void vdyMonitorOutputPeaks(const VDYInputData_t *pInput, const proVdyPrtList_t *proPorts)
{
  float32 fDiff;
  float32 Threshold;
  VDYErrState_t CurrentInputStwState = (VDYErrState_t)VDY_GET_IO_STATE(VDY_SIN_POS_SWA, pInput->Signals.State);
  VDYErrState_t CurrentOutputCurveState = (VDYErrState_t)VDY_GET_IO_STATE(VDY_SOUT_POS_CURVE, proPorts->pVehicleDynamicSignals->State);

  /* Check if steering wheel input got invalid or decreased this cycle */
  if (    ( ((CurrentInputStwState == VDY_IO_STATE_INVALID) || (CurrentInputStwState == VDY_IO_STATE_DECREASED)) && (LastOutputSignals.InputStwState == VDY_IO_STATE_VALID) )
       || ( (CurrentInputStwState == VDY_IO_STATE_VALID) && ((LastOutputSignals.InputStwState == VDY_IO_STATE_INVALID) || (LastOutputSignals.InputStwState == VDY_IO_STATE_DECREASED)) )  )
  {
    LastOutputSignals.LimitCurve = TRUE;
  }

  /* only limit curve if vehicle is moving and the steering wheel input just got invalid */
  if ((proPorts->pVehicleDynamicSignals->Longitudinal.VeloCorr.corrVelo > C_F32_DELTA) && (LastOutputSignals.LimitCurve == TRUE))
  {
    /* steering ratio and wheelbase are both not 0 or a parameter fault would be active, the values would have been set to safe defaults and VDY disabled */
    /* but check anyway to be safe */
    if (CML_f_IsNonZero(pInput->Parameter.SteeringRatio.swa.rat[1]) &&  CML_f_IsNonZero(pInput->Parameter.WheelBase))
    {
      Threshold = VDY_PAR_SWA_INPUT_PEAK / (pInput->Parameter.SteeringRatio.swa.rat[1] * pInput->Parameter.WheelBase);

      /* check for signal peaks between the actual and the last cycle */
      fDiff = LastOutputSignals.Curve - proPorts->pVehicleDynamicSignals->Lateral.Curve.Curve;
      if ((CML_f_Abs(fDiff) > Threshold) && (LastOutputSignals.CurveState == VDY_IO_STATE_VALID) && ((CurrentOutputCurveState == VDY_IO_STATE_VALID) || (CurrentOutputCurveState == VDY_IO_STATE_DECREASED))
      {
        /* Limit the signal gain to the threshold */
        if (fDiff > VDY_ZERO_F)
        {
          LastOutputSignals.Curve = LastOutputSignals.Curve + Threshold;
        }
        else
        {
          LastOutputSignals.Curve = LastOutputSignals.Curve - Threshold;
        }
        proPorts->pVehicleDynamicSignals->Lateral.Curve.Curve = LastOutputSignals.Curve;
        LastOutputSignals.OutputPeakError = VDY_STAT_ACTIVE;
      }
      else
      {
        /* Within limits, take value, stop limiting the signal */
        LastOutputSignals.Curve = proPorts->pVehicleDynamicSignals->Lateral.Curve.Curve;
        LastOutputSignals.OutputPeakError = VDY_STAT_INACTIVE;
        LastOutputSignals.LimitCurve = FALSE;
      }
    }
    else
    {
      /* Store values if vehicle is not moving, no peak check necessary */
      LastOutputSignals.Curve = proPorts->pVehicleDynamicSignals->Lateral.Curve.Curve;
      LastOutputSignals.OutputPeakError = VDY_STAT_INACTIVE;
    }

    /* store the signal state of the previous cycle */
    LastOutputSignals.CurveState = CurrentOutputCurveState;
    LastOutputSignals.InputStwState = CurrentInputStwState;
  }
  else
  {
    /* do nothing as parameters are corrupt */
  }
}
#endif


/* **********************************************************************
	Unit Design for vdyMonitorOutputRanges is found in Declaration Section
**************************************************************************** */

STATIC_MTD void vdyMonitorOutputRanges(const proVdyPrtList_t *proPorts)
{
  /* absolute output values */
  float32 f_VelocityAbs = CML_f_Abs(proPorts->pVehicleDynamicSignals->Longitudinal.Velocity);
  float32 f_LongAccelAbs = CML_f_Abs(proPorts->pVehicleDynamicSignals->Longitudinal.Accel);
  float32 f_YawRateAbs = CML_f_Abs(proPorts->pVehicleDynamicSignals->Lateral.YawRate.YawRate);
  float32 f_LatAccelAbs = CML_f_Abs(proPorts->pVehicleDynamicSignals->Lateral.Accel.LatAccel);

  /* check longitudinal motion */
  /* if vehicle velocity is in range 0 - +400 kph and vehicle acceleration is below 15 m/s^2 and velocity is not NaN */
  if (    (f_VelocityAbs < MAX_VELOCITY)
       && (f_LongAccelAbs < MAX_ACCELERATION)
       && (ISNAN(proPorts->pVehicleDynamicSignals->Longitudinal.MotVar.Velocity) == FALSE)  )
  {
    proPorts->pVDYErrors->OutPutErrors.VelocityErr = VDY_ERR_STATE_INACTIVE;

    /* check estimated yaw rate */
    /* Invalid yaw rate input sensor signal during standstill must not lead to invalid output yaw rate */
    if (    (((sint32)VDY_GET_IO_STATE(VDY_SOUT_POS_YAWRATE, proPorts->pVehicleDynamicSignals->State) != VDY_IO_STATE_VALID) &&
             ((sint32)VDY_GET_IO_STATE(VDY_SOUT_POS_YAWRATE, proPorts->pVehicleDynamicSignals->State) != VDY_IO_STATE_DECREASED ))
         && ((sint32)VDY_GET_IO_STATE(VDY_SOUT_POS_VELOCITY, proPorts->pVehicleDynamicSignals->State) == VDY_IO_STATE_VALID)
         && (proPorts->pVehicleDynamicSignals->Longitudinal.Velocity < VDY_ONE_F )  )
    {
      VDY_SET_IO_STATE(VDY_SOUT_POS_YAWRATE, VDY_IO_STATE_VALID, proPorts->pVehicleDynamicSignals->State);
#if ( (!defined(CFG_VDY_DIS_YAW_SENSOR_OUTPUT)) || (!CFG_VDY_DIS_YAW_SENSOR_OUTPUT)  )
      proPorts->pALNYawRate->bSenYawRateState = TRUE;
#endif
    }
    else
    {
      /* nothing to do */
    }
  }
  else
  {
    /* Velocity value is out of range or NaN*/
    VDY_SET_IO_STATE(VDY_SOUT_POS_VELOCITY, VDY_IO_STATE_INVALID, proPorts->pVehicleDynamicSignals->State);
    VDY_SET_IO_STATE(VDY_SOUT_POS_ACCEL, VDY_IO_STATE_INVALID, proPorts->pVehicleDynamicSignals->State);
    proPorts->pVDYErrors->OutPutErrors.VelocityErr = VDY_ERR_STATE_ACTIVE;
  }

  /* if yaw rate is in range -150 °/s - +150 °/s and lateral acceleration is below 15 m /s^2*/
  if (    (f_YawRateAbs < MAX_YAWRATE)
       && (f_LatAccelAbs < MAX_ACCELERATION)  )
  {
#if ( (!defined(CFG_VDY_DIS_YAW_SENSOR_OUTPUT)) || (!CFG_VDY_DIS_YAW_SENSOR_OUTPUT) )
    proPorts->pALNYawRate->bSenYawRateState = TRUE;
#endif
    proPorts->pVDYErrors->OutPutErrors.YawRateErr = VDY_ERR_STATE_INACTIVE;
  }
  else
  {
    VDY_SET_IO_STATE(VDY_SOUT_POS_YAWRATE, VDY_IO_STATE_INVALID, proPorts->pVehicleDynamicSignals->State);
    VDY_SET_IO_STATE(VDY_SOUT_POS_LATERALACCEL, VDY_IO_STATE_INVALID, proPorts->pVehicleDynamicSignals->State);
    proPorts->pVDYErrors->OutPutErrors.YawRateErr = VDY_ERR_STATE_ACTIVE;
  }
}


/* **********************************************************************
	Unit Design for vdyMonitorOutput is found in vdy.h
**************************************************************************** */

void vdyMonitorOutput(const VDYInputData_t *input, const proVdyPrtList_t *proPorts, const reqVdyPrtList_t *reqPorts)
{
#if ( (defined(CFG_VDY_MON_OUTPUT_PEAKS)) && (CFG_VDY_MON_OUTPUT_PEAKS) )
  /* monitoring of the curve output gradient */
  vdyMonitorOutputPeaks(input, proPorts);
#else
  /* PRQA S 3119 EOF */
  /* date: 2019-06-10, reviewer: Mahesh Patle (uidr0487), reason: No Risk */
  (void)input;  /* remove compiler warning, input data is not used in this configuration */
#endif
  /* monitoring of the yaw rate/lat accel and velocity/long accel output value range */
  vdyMonitorOutputRanges(proPorts);
 
  /* PRQA S 1881 EOF */
  /* date: 2019-06-10, reviewer: Mahesh Patle (uidr0487), reason: No Risk */
  if(((sint32)VDY_GET_IO_STATE(VEH_SIG_BRAKE_ABS, reqPorts->pVehicleInputSignals->Brake.State) == VDY_IO_STATE_VALID) && (reqPorts->pVehicleInputSignals->Brake.ABSCtrl == (boolean)FALSE))
  {
    u_velMonitorOFFCounter_ABS = 0U;
  }
  if(((sint32)VDY_GET_IO_STATE(VEH_SIG_BRAKE_TSC, reqPorts->pVehicleInputSignals->Brake.State) == VDY_IO_STATE_VALID) && (reqPorts->pVehicleInputSignals->Brake.TCSCtrl == (boolean)FALSE))
  {
    u_velMonitorOFFCounter_TSC = 0U;
  }
  /* global monitoring of the velocity output, if the velocity is not sufficient for the other components */
  /* sensor op mode should be changed (temporary not available) */

  /* When ABS / TSC is active set the Vehicle velocity not available error as Inactive for 20 sec */

  if ((((sint32)VDY_GET_IO_STATE(VEH_SIG_BRAKE_ABS, reqPorts->pVehicleInputSignals->Brake.State) == VDY_IO_STATE_VALID) &&
      (reqPorts->pVehicleInputSignals->Brake.ABSCtrl == (boolean)TRUE) &&
      ((float32)u_velMonitorOFFCounter_ABS < OUTPUT_VEL_MON_DEACTIVATION_ABS)) ||

      (((sint32)VDY_GET_IO_STATE(VEH_SIG_BRAKE_TSC, reqPorts->pVehicleInputSignals->Brake.State) == VDY_IO_STATE_VALID) &&
       (reqPorts->pVehicleInputSignals->Brake.TCSCtrl == (boolean)TRUE) &&
       ((float32)u_velMonitorOFFCounter_TSC < OUTPUT_VEL_MON_DEACTIVATION_TSC)))
  {

     proPorts->pVDYErrors->OutPutErrors.VDY_VEH_VEL_NOT_AVAILABLE = VDY_ERR_STATE_INACTIVE;  

     if(((sint32)VDY_GET_IO_STATE(VEH_SIG_BRAKE_ABS, reqPorts->pVehicleInputSignals->Brake.State) == VDY_IO_STATE_VALID) &&
        (reqPorts->pVehicleInputSignals->Brake.ABSCtrl == (boolean)TRUE))
     {
       u_velMonitorOFFCounter_ABS ++;
     }

     if(((sint32)VDY_GET_IO_STATE(VEH_SIG_BRAKE_TSC, reqPorts->pVehicleInputSignals->Brake.State) == VDY_IO_STATE_VALID) &&
       (reqPorts->pVehicleInputSignals->Brake.TCSCtrl == (boolean)TRUE))
     {
       u_velMonitorOFFCounter_TSC ++;
     }

  }

  else
  {
    vdyMonitorVelocityOutput(proPorts, input);
  }

  /* global monitoring of the yaw rate output, if the yaw rate is not sufficient for the other components */
  /* sensor op mode should be changed (temporary not available) */
  vdyMonitorYawrateOutput(proPorts);
}


#if ( (!defined(CFG_VDY_DIS_YWR_OFFSET_COMP)) || (!CFG_VDY_DIS_YWR_OFFSET_COMP) )
/* **********************************************************************
	Unit Design for vdyMonitorDynYwrOffset is found in vdy.h
**************************************************************************** */

void vdyMonitorDynYwrOffset(const ToAutocode_t *Input, VDYInternalData_t *IntData)
{
  if (  (   (CML_f_Abs(IntData->vdy_offsets_in.vdy_yaw_offset.offset - Input->OffsData.offset) > DEG2RAD(VDY_TEN_CENT))
         && (Input->OffsData.state == (uint8)(VDY_YAWRATE_STATE_NVM))       /* eeprom offset */)
     || (Input->OffsData.state == (uint8)(VDY_YAWRATE_STATE_STANDSTILL))    /* stand still offset */) 
  {
	/* PRQA S 0315 EOF */
	/* date: 2019-06-10, reviewer: Mahesh Patle (uidr0487), reason: No Risk */
    (void)vdy_memcpy_s(&IntData->vdy_offsets_in.vdy_yaw_offset, &Input->OffsData, sizeof(vdy_yaw_offset_t));
    /* set old offset to stand still offset */
    oldOffset = Input->OffsData.offset;
    /* store stand still offset */
    StandStillOffset = oldOffset;
  }
  else
  {
    (void)vdy_memcpy_s(&IntData->vdy_offsets_in.vdy_yaw_offset, &Input->OffsData, sizeof(vdy_yaw_offset_t));
  }

  if (    ( CML_f_Abs(IntData->vdy_wye_out.raw_est_yaw_offset - IntData->vdy_offsets_in.vdy_yaw_offset.offset) > VDY_YAWRATE_DYN_MAX_DIFF)
       && ( (IntData->vdy_offsets_in.vdy_yaw_offset.state == (uint8)(VDY_YAWRATE_STATE_KEEP_TYPE)) && (Input->IsDynamic == (boolean)FALSE) )  )
  {
    /* Set internal data input yaw rate offset temporarily to the old offset (one step byside the stand still offset) */
    IntData->vdy_offsets_in.vdy_yaw_offset.offset = oldOffset;
    /* reinit the dynamic yaw rate offset state with the oldOffset */
    IntData->vdy_offsets_in.vdy_yaw_offset.state  = VDY_YAWRATE_STATE_STANDSTILL;
  }
  else
  {
    /* Reset internal data input yaw rate offset to original stand still offset */
    IntData->vdy_offsets_in.vdy_yaw_offset.offset = StandStillOffset;
    /* Set oldoffset to actual estimated dynamic offset */
    oldOffset = IntData->vdy_wye_out.gier_yaw_rate_offset;
  }
}
#endif


#if defined(VDY_SIMU)
#if ( (!defined(CFG_VDY_DIS_YWR_OFFSET_COMP)) || (!CFG_VDY_DIS_YWR_OFFSET_COMP) )
/* **********************************************************************
	Unit Design for vdyInitDynYwrOffsetMonitor is found in Declaration Section
**************************************************************************** */

void vdyInitDynYwrOffsetMonitor( float32 YwrOffset )
{
  oldOffset = YwrOffset;
  StandStillOffset = YwrOffset;
}
#endif
#endif


#if (CFG_VDY_USE_VELO_MONITOR)
/* **********************************************************************
	Unit Design for vdyVelMonGetPrivateData is found in vdy.h
**************************************************************************** */

VDYVelMon_t *vdyVelMonGetPrivateData(void)
{
  return (VMON_GET_ME);
}


/* **********************************************************************
	Unit Design for vdyVelMon is found in Declaration Section
**************************************************************************** */

STATIC_MTD void vdyVelMon(const VehSigMain_t *in, const vdy_ve_out_t *ve, VDYErrors_t *pErr)
{
  const uint32 incErrCnt_c = 1U;   /* Increment step size */
  const uint32 decErrCnt_c = 1U;   /* Decrement step size */
  const float32 ratThrhd_c = 0.01F;   /* Ratio to determine threshold by means of absolute velocity */
  STATIC_VAR float32 lastVeloVar = VDY_ZERO_F;

  fVelocity_t    velDiff;
  fUncertainty_t uncVel;
  VDYVelMon_t *pVelMon = VMON_GET_ME;

  /* Default output error states */
  pErr->OutPutErrors.VelMon   = VDY_ERR_STATE_UNKNOWN;
  pErr->OutPutErrors.VelMonLt = VDY_ERR_STATE_UNKNOWN;
  
  /* Monitoring only active when signal is valid */
  if ((sint32)VDY_GET_IO_STATE(VDY_SIN_POS_VEHVEL_EXT, in->State) == VDY_IO_STATE_VALID)
  {
    /* Calculate difference and uncertainty of estimated velocity and check for negative variance */
    velDiff = in->VehVelocityExt - ve->veh_velo;
    if (ve->veh_velo_var < VDY_ZERO_F)
    {
      uncVel  = VDY_FOUR_F * VDY_SQRT(lastVeloVar);
    }
    else
    {
      uncVel  = VDY_FOUR_F * VDY_SQRT(ve->veh_velo_var);
      lastVeloVar = ve->veh_velo_var;
    }
    
    /* if external velocity is outside of estimated velocity range, increment error count */
    if ( (CML_f_Abs(velDiff) - uncVel) > (ve->veh_velo * ratThrhd_c) )
    {
      pVelMon->cntOutSide += incErrCnt_c;
    }
    else
    {
      /* decrement error count */
      pVelMon->cntOutSide = (pVelMon->cntOutSide > decErrCnt_c) ? (pVelMon->cntOutSide - decErrCnt_c) : 0U;
    }
    
    /* test counter thresholds */
    if (pVelMon->cntOutSide >= VDY_PAR_VMON_CYCLE_OUT_LT)
    {
      /* Counter above long-term limit */
      pVelMon->cntOutSide = MIN(pVelMon->cntOutSide, VDY_PAR_VMON_CYCLE_OUT_LT + VDY_TWO_U);
      pErr->OutPutErrors.VelMon   = VDY_ERR_STATE_INACTIVE;
      pErr->OutPutErrors.VelMonLt = VDY_ERR_STATE_ACTIVE;
    }
    else if (pVelMon->cntOutSide >= VDY_PAR_VMON_CYCLE_OUT)
    {
      /* Counter above short limit */
      pErr->OutPutErrors.VelMon   = VDY_ERR_STATE_ACTIVE;
      pErr->OutPutErrors.VelMonLt = VDY_ERR_STATE_INACTIVE;
    }
    else
    {
      pErr->OutPutErrors.VelMon   = VDY_ERR_STATE_INACTIVE;
      pErr->OutPutErrors.VelMonLt = VDY_ERR_STATE_INACTIVE;
    }
  }
  return;
}


/* **********************************************************************
	Unit Design for vdyVelMonInit is found in vdy.h
**************************************************************************** */

void vdyVelMonInit(VDYErrors_t *pErr)
{
  VDYVelMon_t *pVelMon = VMON_GET_ME;

  pErr->OutPutErrors.VelMon   = VDY_ERR_STATE_UNKNOWN;
  pErr->OutPutErrors.VelMonLt = VDY_ERR_STATE_UNKNOWN;

  pVelMon->cntOutSide = 0U;

  return;
}


/* **********************************************************************
	Unit Design for vdyVelMonExec is found in vdy.h
**************************************************************************** */

void vdyVelMonExec(const VDYInputData_t *input, const vdy_ve_out_t *ve, VDYErrors_t *pErr)
{
#if ((!defined(CFG_VDY_DIS_WHEEL_PRE_PROCESSING)) || (!CFG_VDY_DIS_WHEEL_PRE_PROCESSING))
  /* if vdy control mode is init */
#if (!CFG_VDY_MFC)
    if (VDY_CTRL_GET_STATE((VDYCtrlState_t)VDY_CTRL_STATE_INIT, input->Frame.CtrlMode))
#else
    if (VDY_CTRL_GET_STATE( (BaseOpMode_t)BASE_OM_RESET, input->Frame.OpMode) )
#endif
  {
    vdyVelMonInit(pErr);
  }
  else
  {
    vdyVelMon(&input->Signals, ve, pErr);
  }
#endif

#if ((defined(CFG_VDY_FS_VELO_CORR_MON)) && (CFG_VDY_FS_VELO_CORR_MON))
#if (!CFG_VDY_MFC)
    if (VDY_CTRL_GET_STATE((VDYCtrlState_t)VDY_CTRL_STATE_INIT, input->Frame.CtrlMode))
#else
    if (VDY_CTRL_GET_STATE( (BaseOpMode_t)BASE_OM_RESET, input->Frame.OpMode) )
#endif
  {
    pErr->OutPutErrors.VDY_FS_VEH_CORR_MON = VDY_ERR_STATE_UNKNOWN;
  }
  else
  {
    VDYFSVelCorrMon_t *pCorrMonData = VDYFSVelCorrMonGetPrivateData();

    /* check if FS velocity monitor detected a fault */
    if (pCorrMonData->fault == VDY_ERR_STATE_ACTIVE)
    {
      pErr->OutPutErrors.VDY_FS_VEH_CORR_MON = VDY_ERR_STATE_ACTIVE;
    }
    else
    {
      pErr->OutPutErrors.VDY_FS_VEH_CORR_MON = VDY_ERR_STATE_INACTIVE;
    }
  }
#endif
}

#endif


#if (CFG_VDY_YWR_OFFSET_MONITOR)
/* **********************************************************************
	Unit Design for vdyYwrMonVehHalt is found in Declaration Section
**************************************************************************** */

STATIC_MTD VDYErrState_t vdyYwrMonVehHalt(const VDYYwrMonDataLoc_t *pMon, VDYYwrMonVehHalt_t *pVehHalt)
{
  VDYErrState_t ret = VDY_ERR_STATE_UNKNOWN;
  
  if (pMon->StSt != FALSE)
  {
    /* Vehice is halted */
    if ( CML_f_Abs(pMon->ywRate) > VDY_YWR_MON_VHALT_YWR_MAX )
    {
      /* Count time for yaw rate at standstill above limit */
      pVehHalt->timeAboveThrhd += pMon->cycTime;
    }
    else
    {
      /* Reset counted time */
      pVehHalt->timeAboveThrhd = 0.F;
    }
  
    /* Vehicle must be standstill for certain time to monitor the yaw rate ofset */
    if (pMon->timeVehHalt > VDY_YWR_MON_VHALT_TIME_MAX)
    {
      if ( pVehHalt->timeAboveThrhd > VDY_YWR_MON_VHALT_TIME_MAX )
      {
        /* Period of maximum permitted yaw rate has been elapsed */
        ret = VDY_ERR_STATE_ACTIVE;
      }
      else
      {
        /* Period of maximum permitted yaw rate has not been elapsed */
        ret = VDY_ERR_STATE_INACTIVE;
      }
    }
  }
  else
  {
    /* Vehicle is moving, reset monitor state variables */
    pVehHalt->timeAboveThrhd = 0.F;
  }

  /* Keep timer values inside defined limits */
  pVehHalt->timeAboveThrhd = MIN_FLOAT(pVehHalt->timeAboveThrhd, VDY_YWR_MON_VHALT_TIME_MAX + C_F32_DELTA);
  
  return ret;
}


/* **********************************************************************
	Unit Design for vdyYwrMonVehDriveOff is found in Declaration Section
**************************************************************************** */

STATIC_MTD VDYErrState_t vdyYwrMonVehDriveOff(const VDYYwrMonDataLoc_t *pMon, VDYYwrMonVehDriveOff_t *pDrvOff)
{
  VDYErrState_t ret = VDY_ERR_STATE_UNKNOWN;

  if (pMon->StSt != FALSE)
  {
    /* Vehice is standstill */
    if ( CML_f_Abs(pMon->ywRate) > VDY_YWR_MON_VDOFF_YWR_MAX )
    {
      /* Count time above max. permitted threshold */
      pDrvOff->timeAboveThrhd += pMon->cycTime;
    }
    else
    {
      /* Reset counted time */
      pDrvOff->timeAboveThrhd = 0.F;
    }
  }
  else
  {
    /* Vehicle is moving, monitored offset is */
    if (pMon->timeVehHalt > VDY_YWR_MON_VDOFF_TIME_MAX)
    {
      if (pDrvOff->timeAboveThrhd > VDY_YWR_MON_VDOFF_TIME_MAX)
      {
        /* Period of maximum permitted yaw rate has been elapsed */
        ret = VDY_ERR_STATE_ACTIVE;
      }
      else
      {
        /* Period of maximum permitted yaw rate has not been elapsed */
        ret = VDY_ERR_STATE_INACTIVE;
      }
    }
    
    /* reset monitor state variables */
    pDrvOff->timeAboveThrhd = 0.F;
  }

  /* Keep timer values inside defined limits */
  pDrvOff->timeAboveThrhd = MIN_FLOAT(pDrvOff->timeAboveThrhd, VDY_YWR_MON_VDOFF_TIME_MAX + C_F32_DELTA);

  return ret;
}


/* **********************************************************************
	Unit Design for vdyYwrMonVehHaltDrv is found in Declaration Section
**************************************************************************** */

STATIC_MTD VDYErrState_t vdyYwrMonVehHaltDrv(const VDYYwrMonDataLoc_t *pMon, VDYYwrMonVehHaltDrv_t *pVehHtDrv)
{
  VDYErrState_t ret = VDY_ERR_STATE_UNKNOWN;
  
  if (pMon->StSt != FALSE)
  {
    /* Vehicle is standing still */

    if ((VDYYwrMonVehHaltDrvState_t)pVehHtDrv->State == (VDYYwrMonVehHaltDrvState_t)VDY_YWR_MON_STATE_HALTING)
    {
      /* Acquiring offset value at standstill begin */
      if (pVehHtDrv->ivSample.Volume < VDY_YWR_MON_VHTDR_WIN_LEN )
      {
        vdyStatIntervalAdd(&pVehHtDrv->ivSample, pMon->ywRate, 1.0F);
      }
      else
      {
        /* Sampling intervall is full, evaluate the data */
        vdyStatIntervalMeanDev(&pVehHtDrv->ivSample);

        /* Use the mean as offset, if the sampled data has no big variance */
        if (pVehHtDrv->ivSample.Dev < VDY_YWR_MON_VHTDR_WIN_DEV)
        {
          pVehHtDrv->ywrStStOn  = pVehHtDrv->ivSample.Mean;
          pVehHtDrv->State = (VDYYwrMonVehHaltDrvState_t)VDY_YWR_MON_STATE_STANDING;
        }
        /* Clear grabbed data */
        vdyStatIntervalInit(&pVehHtDrv->ivSample);
      }
    }
    else
    {
      /* Acquiring offset value for coming standstill end */
      
      if (pVehHtDrv->ivSample.Volume < VDY_YWR_MON_VHTDR_WIN_LEN )
      {
        vdyStatIntervalAdd(&pVehHtDrv->ivSample, pMon->ywRate, 1.0F);
      }
      else
      {
        /* Sampling intervall is full, evaluate the data */
        vdyStatIntervalMeanDev(&pVehHtDrv->ivSample);

        /* Use the mean as offset, if the sampled data has no big variance */        
        if (pVehHtDrv->ivSample.Dev < VDY_YWR_MON_VHTDR_WIN_DEV)
        {
          pVehHtDrv->ywrStStOff  = pVehHtDrv->ivSample.Mean;
          pVehHtDrv->State = (VDYYwrMonVehHaltDrvState_t)VDY_YWR_MON_STATE_WAITING;
        }
        /* Clear grabbed data */        
        vdyStatIntervalInit(&pVehHtDrv->ivSample);
      }
    }
  }
  else
  {
    /* Monitoring only possible if values at vehicle-halt and vehicle drive-off are available */
    if ((uint8)pVehHtDrv->State == (uint8)VDY_YWR_MON_STATE_WAITING)
    {
      /* Test if difference exceeds allowed value */
      if ( CML_f_Abs(pVehHtDrv->ywrStStOn - pVehHtDrv->ywrStStOff) > VDY_YWR_MON_VHTDR_DIFF_MAX )
      {
        ret = VDY_ERR_STATE_ACTIVE;
      }
      else
      {
        ret = VDY_ERR_STATE_INACTIVE;
      }
    }
    
    /* reset monitor state variables */
    vdyStatIntervalInit(&pVehHtDrv->ivSample);
    pVehHtDrv->State = (VDYYwrMonVehHaltDrvState_t)VDY_YWR_MON_STATE_HALTING;
  }
  return ret;
}


/* **********************************************************************
	Unit Design for vdyYwrMonVehHaltCal is found in Declaration Section
**************************************************************************** */

STATIC_MTD VDYErrState_t vdyYwrMonVehHaltCal(const VDYYwrMonDataLoc_t *pMon, VDYYwrMonVehHaltCal_t *pVehHaltCal)
{
  const fTime_t CycTime_c = 0.020F;
  const uint8 maxCalCyc_c = (uint8) 2UL;
  
  VDYErrState_t ret = VDY_ERR_STATE_UNKNOWN;

  /* Enable active error reporting once, if velocity has exceeded threshold */
  if (pVehHaltCal->State == VDY_YWR_MON_CAL_STATE_MUTE)
  {
    if (pMon->Velocity > VDY_YWR_MON_CAL_VEL_START_THRHD)
    {
      pVehHaltCal->State = VDY_YWR_MON_CAL_STATE_ARMED;
    }
  }

  /* Test for active vehicle halt */
  if ((pMon->VehStSt != FALSE) && (pMon->Velocity < VDY_YWR_MON_VEL_STST_THRHD))
  {
    /* Increase time since reported vehicle standstill */
    pVehHaltCal->timeStStToCalib += pMon->cycTime;

    /* Test for standstill appropriate for calibration */
    if (pMon->StSt != FALSE)
    {
      /* Sample yaw rate values */
      vdyStatIntervalAdd(&pVehHaltCal->ivSample, pMon->ywRate, 1.0F);

      /* Evaluate sampled yaw rate if enough samples have been acquired */
      if (pVehHaltCal->ivSample.Volume >= (VDY_PAR_YWR_STST_CAL_TIME_MIN / CycTime_c) )
      {
        /* Calculte mean and standard deviation of observed interval */
        vdyStatIntervalMeanDev(&pVehHaltCal->ivSample);
        
        /* Increase number of successfull executed calibration cycles, if deviation is small */
        if (   (pVehHaltCal->ivSample.Dev < STANDST_STDABW_MAX) 
            && (pVehHaltCal->cntCalCycle < (uint8) maxCalCyc_c) )
        {
          pVehHaltCal->cntCalCycle++;
        }
        /* Init sample interval */
        vdyStatIntervalInit(&pVehHaltCal->ivSample);
      }
    }
  }
  else
  {
    /* Reset time since vehicle standstill */
    pVehHaltCal->timeStStToCalib = 0.F;

    /* In case of moving vehicle init collected data */
    vdyStatIntervalInit(&pVehHaltCal->ivSample);
    pVehHaltCal->cntCalCycle = (uint8) 0UL;
  }

  /* After certain time in vehicle halt, successfull calibration is expected */
  if (pVehHaltCal->timeStStToCalib > VDY_YWR_MON_CAL_MAX_TIME)
  {
    if (pVehHaltCal->cntCalCycle < (uint8) maxCalCyc_c)
    {
      /* Calibration was not completed */

      /* Report error active error only, after first time exceeding velocity threshold */
      if (pVehHaltCal->State == VDY_YWR_MON_CAL_STATE_ARMED)
      {
        ret = VDY_ERR_STATE_ACTIVE;
      }
    }
    else
    {
      /* Calibration was successfull */
      ret = VDY_ERR_STATE_INACTIVE;
    }
    
    /* Disable active error reporting, wait for exceeding velocity threshold */
    pVehHaltCal->State = VDY_YWR_MON_CAL_STATE_MUTE;

    /* Limit maximum value and keep it above thershold */
    pVehHaltCal->timeStStToCalib = VDY_YWR_MON_CAL_MAX_TIME + CycTime_c;
  }

  return ret;
}


/* **********************************************************************
	Unit Design for vdyYwrMonInit is found in vdy.h
**************************************************************************** */

void vdyYwrMonInit(const VDYInputData_t *input, const VDYModIf_t *mif, VDYErrors_t *VDYErrors)
{
  VDYYwrMonData_t *pMonData = YWR_GET_MON_DATA;

  (void)*input;
  (void)*mif;

  pMonData->ywRateOld = 0.F;
  pMonData->Gradient  = 0.F;
  pMonData->timeVehHalt = 0.F;
  
  pMonData->VehDriveOff.timeAboveThrhd = 0.F;
  pMonData->VehHalt.timeAboveThrhd = 0.F;
  
  pMonData->VehHaltDrv.ywrStStOff = 0.F;
  pMonData->VehHaltDrv.State = (VDYYwrMonVehHaltDrvState_t)VDY_YWR_MON_STATE_HALTING;
  pMonData->VehHaltDrv.ywrStStOff = 0.F;
  pMonData->VehHaltDrv.ywrStStOn  = 0.F;
  vdyStatIntervalInit(&pMonData->VehHaltDrv.ivSample);

  pMonData->VehHaltCal.State = VDY_YWR_MON_CAL_STATE_MUTE;
  pMonData->VehHaltCal.timeStStToCalib = 0.F;
  pMonData->VehHaltCal.cntCalCycle = (uint8) 0UL;
  vdyStatIntervalInit(&pMonData->VehHaltCal.ivSample);

  /* Initialize error output states */
  VDYErrors->OutPutErrors.YwrMonVehHalt    = VDY_ERR_STATE_UNKNOWN;
  VDYErrors->OutPutErrors.YwrMonVehDOff    = VDY_ERR_STATE_UNKNOWN;
  VDYErrors->OutPutErrors.YwrMonAdmWdrwl   = VDY_ERR_STATE_UNKNOWN;
  VDYErrors->OutPutErrors.YwrMonVehHaltCal = VDY_ERR_STATE_UNKNOWN;

  return;
}


/* **********************************************************************
	Unit Design for vdyYwrMonExec is found in vdy.h
**************************************************************************** */

void vdyYwrMonExec(const VDYInputData_t *input, const VDYModIf_t *mif, const proVdyPrtList_t *proPorts)
{
  VDYYwrMonDataLoc_t Mon;

  VDYYwrMonData_t *pMonData = YWR_GET_MON_DATA;

  /* Initialize error output states */
  proPorts->pVDYErrors->OutPutErrors.YwrMonVehHalt    = VDY_ERR_STATE_UNKNOWN;
  proPorts->pVDYErrors->OutPutErrors.YwrMonVehDOff    = VDY_ERR_STATE_UNKNOWN;
  proPorts->pVDYErrors->OutPutErrors.YwrMonAdmWdrwl   = VDY_ERR_STATE_UNKNOWN;
  proPorts->pVDYErrors->OutPutErrors.YwrMonVehHaltCal = VDY_ERR_STATE_UNKNOWN;

#if (CFG_VDY_INT_GYRO)
  /* Monitoring of internal yaw rate */
  Mon.ywRate = input->Signals.YawRateInt;
#else
  /* Monitoring of external yaw rate */
  Mon.ywRate = input->Signals.YawRate;
#endif

  /* Get vehicle velocity */
  if (VDY_GET_IO_STATE(VDY_SOUT_POS_VEL,proPorts->pVehicleDynamicSignals->State)==VDY_IO_STATE_VALID)
  {
    Mon.Velocity = mif->LongMot.VehVelocityCorr;
  }
  else
  {
    Mon.Velocity = 0.F;
  }

  if (mif->LongMot.MotState.MotState == VDY_LONG_MOT_STATE_STDST)
  {
    Mon.VehStSt = TRUE;
  }
  else
  {
    Mon.VehStSt = FALSE;
  }

  /* Set monitor cycle time */
  Mon.cycTime = vdyGetCycleTime();
  Mon.timeVehHalt = pMonData->timeVehHalt;

  /* <ln_offset:+2 PCLINT Error 845: reviewer name: Frank Wolter date: 28-06-2013 reason: error because of first state mask is zero */
  /* <ln_offset:+1 PCLINT Error 835: reviewer name: Frank Wolter date: 28-06-2013 reason: error because of first state mask is zero */
  if ( VDY_GET_IO_STATE(VDY_SIN_POS_YWR,input->Signals.State)  != VDY_IO_STATE_VALID)
  {
    /* Calculate gradient of yaw rate signal */
    pMonData->Gradient = VDY_IIR_DIFF(Mon.ywRate, pMonData->ywRateOld, pMonData->Gradient, VDY_YWR_MON_DIFF_FILT, Mon.cycTime);
    
    /* Enable monitoring if standstill is detected and yaw rate signal is stable */
    if (   (mif->LongMot.MotState.MotState == VDY_LONG_MOT_STATE_STDST)
        && (mif->LongMot.MotState.Confidence > VDY_PAR_YWR_STST_CONF_MIN) 
        && (CML_f_Abs(pMonData->Gradient) < VDY_YWR_MON_YWR_GRAD_MAX) )
    {
      /* Activate standstill flag and count time */
      Mon.StSt = TRUE;
      pMonData->timeVehHalt += Mon.cycTime;
    }
    else
    {
      /* reset standstill flag and count time */
      Mon.StSt = FALSE;
      pMonData->timeVehHalt = VDY_ZERO_F;
    }
    
    /* Run several yaw rate offset monitors */
    proPorts->pVDYErrors->OutPutErrors.YwrMonVehHalt    = vdyYwrMonVehHalt(&Mon, &pMonData->VehHalt);
    proPorts->pVDYErrors->OutPutErrors.YwrMonVehDOff    = vdyYwrMonVehDriveOff(&Mon, &pMonData->VehDriveOff);
    proPorts->pVDYErrors->OutPutErrors.YwrMonAdmWdrwl   = vdyYwrMonVehHaltDrv(&Mon, &pMonData->VehHaltDrv);
    proPorts->pVDYErrors->OutPutErrors.YwrMonVehHaltCal = vdyYwrMonVehHaltCal(&Mon, &pMonData->VehHaltCal);

    /* Keep timer values inside defined limits */
    pMonData->timeVehHalt = MIN_FLOAT(pMonData->timeVehHalt, VDY_YWR_MON_TIME_MAX);

    /* Save current yaw rate for next cycle */
    pMonData->ywRateOld = Mon.ywRate;
  }
  return;
}


/* **********************************************************************
	Unit Design for vdyYwrMonGetPrivateData is found in vdy.h
**************************************************************************** */

VDYYwrMonData_t *vdyYwrMonGetPrivateData(void)
{
  return(YWR_GET_MON_DATA);
}
#endif


#if ( (defined(CFG_VDY_ALIGNMENT_OFFSET_MONITOR)) && (CFG_VDY_ALIGNMENT_OFFSET_MONITOR) )
/* **********************************************************************
	Unit Design for vdyAlignmentYawOffsMonitor is found in vdy.h
**************************************************************************** */

void vdyAlignmentYawOffsMonitor(const reqVdyPrtList_t *reqPorts, const VDYInputData_t *input, const VDYInternalData_t *IntData, VDYErrors_t *VDYErrors)
{
  fYawRate_t CorrYawRateError  = VDY_ZERO_F;
  fYawRate_t DiffYawRateOffset = VDY_ZERO_F;

  /* check if alignment yaw rate offset contains data */
  if ( reqPorts->pAlignEstYawRateOffset->f_YROEStd < (fYawRate_t)(VDY_ALN_OFFSET_MON_NO_DATA) )
  {
    /* Correct filtered vdy yaw rate offset with alignment yaw rate error*/
    CorrYawRateError =  IntData->vdy_gye_out_filt.raw_est_yaw_offset_filt
      - reqPorts->pAlignEstYawRateOffset->f_YawRateOffsetError;
    /* Difference between corrected filterd yaw rate offset and not filterd yaw rate offset*/
    DiffYawRateOffset = CML_f_Abs(CorrYawRateError - IntData->vdy_wye_out.gier_yaw_rate_offset);

    /* if this difference is above the acc threshold set the acc error event */
    if (DiffYawRateOffset > DEG2RAD(VDY_PAR_ACC_YAW_RATE_OFFS_ERROR))
    {
      /* Absolute threshold time */
      ACCThldTime = ACCThldTime + input->Frame.CycleTime;

      /* if threshold time is above parameter set ACC offset error event */
      if (ACCThldTime > VDY_PAR_ACC_YAW_RATE_OFFS_THLD_TIME)
      {
        VDYErrors->OutPutErrors.YwrACCMonAlignm  = VDY_ERR_STATE_ACTIVE;
      }
      else
      {
        VDYErrors->OutPutErrors.YwrACCMonAlignm  = VDY_ERR_STATE_INACTIVE;
      }
    }
    else
    {
      ACCThldTime = 0U;
      if (DiffYawRateOffset <= DEG2RAD(VDY_PAR_ACC_YAW_RATE_OFFS_ERROR_OFF))
      {
        VDYErrors->OutPutErrors.YwrACCMonAlignm  = VDY_ERR_STATE_INACTIVE;
      }
      else
      {
        /* use old error value, VDYOut stuct is static */
      }
    }

    /* if this difference is above the cg threshold set the cg error event */
    if (DiffYawRateOffset > DEG2RAD(VDY_PAR_CG_YAW_RATE_OFFS_ERROR))
    {
      /* Absolute threshold time */
      CGThldTime = CGThldTime + input->Frame.CycleTime;

      /* if threshold time is above parameter set CG offset error event */
      if (CGThldTime > VDY_PAR_CG_YAW_RATE_OFFS_THLD_TIME)
      {
        VDYErrors->OutPutErrors.YwrCGMonAlignm  = VDY_ERR_STATE_ACTIVE;
      }
      else
      {
        VDYErrors->OutPutErrors.YwrCGMonAlignm  = VDY_ERR_STATE_INACTIVE;
      }
    }
    else
    {
      CGThldTime = 0U;
      if (DiffYawRateOffset <= DEG2RAD(VDY_PAR_CG_YAW_RATE_OFFS_ERROR_OFF))
      {
        VDYErrors->OutPutErrors.YwrCGMonAlignm  = VDY_ERR_STATE_INACTIVE;
      }
      else
      {
        /* use old error value, VDYOut stuct is static */
      }
    }

  }
  else
  {
    /* use old error values, VDYOut stuct is static */
  }
}
#endif


/* **********************************************************************
	Unit Design for vdyInitMon is found in vdy.h
**************************************************************************** */

void vdyInitMon(void)
{
  /* Init alignment monitoring offsets */
#if ( (defined(CFG_VDY_ALIGNMENT_OFFSET_MONITOR)) && (CFG_VDY_ALIGNMENT_OFFSET_MONITOR) )
  ACCThldTime = 0U;
  CGThldTime  = 0U;
#endif

#if ( (defined(CFG_VDY_MON_OUTPUT_PEAKS)) && (CFG_VDY_MON_OUTPUT_PEAKS) )
  /* Init the lastoutput signals to safe defaults
     setting CurveState to INVALID will deactivate peak monitoring in the very first cycle */
  LastOutputSignals.Curve = VDY_ZERO_F;
  LastOutputSignals.CurveState = (VDYErrState_t)VDY_IO_STATE_INVALID;
  LastOutputSignals.OutputPeakError = VDY_STAT_INACTIVE;
  LastOutputSignals.InputStwState = (VDYErrState_t)VDY_IO_STATE_VALID;
  LastOutputSignals.LimitCurve = FALSE;
#endif

#if ( (!defined(CFG_VDY_DIS_YWR_OFFSET_COMP)) || (!CFG_VDY_DIS_YWR_OFFSET_COMP) )
  oldOffset = VDY_ZERO_F;
  StandStillOffset = VDY_ZERO_F;
#endif

  u_velMonitorOFFCounter_ABS = VDY_ZERO_U;

  u_velMonitorOFFCounter_TSC = VDY_ZERO_U;

  #if ( (defined(CFG_VDY_DEBOUNCE_OUTPUTS)) && (CFG_VDY_DEBOUNCE_OUTPUTS) ) 
  u_Debouce_VDY_VEH_VEL_NOT_AVAILABLE = VDY_ZERO_U;
  #endif

}


/** @} */ 
/* EOF */
