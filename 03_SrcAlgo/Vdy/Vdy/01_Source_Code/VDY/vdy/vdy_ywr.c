/*! \file **********************************************************************

  @defgroup YWRSensorSignalProcessingUnit VDY Offset Estimation - YWR Unit Design
	@ingroup VDYHandCode
  @{
	  
  $Company:			Continental AG $

  $Component:		VDY (Vehicle Dynamics Observer) $

  $Module:			vdy_ywr.c $

  @brief			This module contains the yaw rate sensor signal processing and offset calculation
  
  $Descripion:		$

  $Revision: 1.31 $

  CHANGES:
  ---*/ /*---
  CHANGE:           $Log: vdy_ywr.c  $
  CHANGE:           Revision 1.31 2020/06/09 12:21:17CEST Chinnaswamy, Ramachandra (uids4735) (uids4735) 
  CHANGE:           vdy_ywr reversion
  CHANGE:           Revision 1.30 2020/06/04 21:57:05CEST Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           Test Cases Links Update
  CHANGE:           Revision 1.29 2020/06/01 15:39:41CEST Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           Detailed Design Update
  CHANGE:           Revision 1.28 2020/05/31 23:26:37CEST Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           Test Scripts Linking
  CHANGE:           Revision 1.27 2020/05/14 02:00:38CEST Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           Detailed Design Update
  CHANGE:           Revision 1.26 2020/05/13 01:00:50CEST Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           Detailed Design update - Traceability
  CHANGE:           Revision 1.25 2020/05/06 08:46:56CEST Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           PRQA Template Update
  CHANGE:           Revision 1.24 2020/05/04 23:06:20CEST Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           Detailed Design Update
  CHANGE:           Revision 1.23 2020/04/25 22:23:11CEST Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           Detailed Design Update
  CHANGE:           Revision 1.22 2020/04/15 15:49:56CEST Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           L4 Design Link
  CHANGE:           Revision 1.21 2019/12/31 12:24:39CET Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           QAC Fixes
  CHANGE:           Revision 1.20 2019/10/28 13:03:54CET Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           Yaw rate offset learning when external motion state is used
  CHANGE:           Revision 1.19 2019/06/11 08:36:21CEST Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           QAF Fixes
  CHANGE:           Revision 1.18 2019/03/13 13:15:27CET Singh, Sanjiv (uidr1340) 
  CHANGE:           VDY MAinstream sync w.r.t-
  CHANGE:           
  CHANGE:           VDY checkpoint: AL_VDY_BASE_05.00.19_INT-1
  CHANGE:           CustomCP for ARS510TA19 : AL_VDY_ARS510TA19_CUS_05.00.19.30
  CHANGE:           Revision 1.17 2019/01/31 07:25:30CET Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           Detailed Design Update
  CHANGE:           Revision 1.16 2019/01/26 21:24:12CET Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           Followed camel case convention for methods
  CHANGE:           Revision 1.15 2019/01/26 09:22:11CET Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           QAC fixes
  CHANGE:           Revision 1.14 2019/01/10 09:30:11CET Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           DDD - UML Update
  CHANGE:           Revision 1.13 2019/01/09 13:36:54CET Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           Detailed Design - Doors Linking
  CHANGE:           Revision 1.12 2018/12/14 03:12:55CET Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           Disable steer ratio check,EG and Rear Steer check for projects having no SWA Processing
  CHANGE:           Revision 1.11 2018/12/05 10:53:14CET Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           QAC fixes
  CHANGE:           Revision 1.10 2018/11/28 12:07:31CET Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           QAC fixes
  CHANGE:           Revision 1.9 2018/11/15 10:41:21CET Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           PDO tool support
  CHANGE:           Revision 1.8 2018/10/26 15:49:14CEST Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           Accordance with AL_VDY_BASE_05.00.10_INT-0
  CHANGE:           Revision 1.7 2018/09/19 14:10:17CEST Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           static to STATIC_MTB and STATIC_VAR
  CHANGE:           Revision 1.6 2018/09/17 14:00:04CEST Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           Support for courage environment: Defined STATIC_VAR
  CHANGE:           Revision 1.5 2018/09/12 16:23:18CEST Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           Support for courage environment
  CHANGE:           Revision 1.4 2018/09/04 12:00:09CEST Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           Detailed Design Update
  CHANGE:           Revision 1.3 2018/08/28 13:29:40CEST Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           Detailed Unit Design Update
  CHANGE:           Revision 1.2 2018/08/24 15:32:15CEST Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           Unit Design Update
  CHANGE:           Revision 1.1 2018/08/09 10:41:29CEST Singh, Sanjiv (uidr1340) 
  CHANGE:           Initial revision
  CHANGE:           Member added to project /ADAS/SW/Components/VDY_VehicleDynamics/04_Engineering/01_Source_Code/VDY/vdy/project.pj
  CHANGE:           Revision 1.39.1.3 2018/07/27 08:42:52CEST Singh, Sanjiv (uidr1340) 
  CHANGE:           VDY mearged code for ARS and MFC : Mainstream
  CHANGE:           Revision 1.39.1.2 2018/07/27 08:32:40CEST Singh, Sanjiv (uidr1340) 
  CHANGE:           VDY mearged code for ARS and MFC : Mainstream
  CHANGE:           Revision 1.39.1.1 2018/07/25 11:48:56CEST Singh, Sanjiv (uidr1340) 
  CHANGE:           VDY mearged code for ARS and MFC : Mainstream
  CHANGE:           Revision 1.39 2018/05/28 11:59:13CEST Singh, Sanjiv (uidr1340) 
  CHANGE:           Consideration of External Velocity for Standstill offset learning
  CHANGE:           Revision 1.38 2018/05/13 13:13:05CEST Singh, Sanjiv (uidr1340) 
  CHANGE:           Aln data in Motion State and Gear info hold during neutral + Bank Road Detection +
  CHANGE:           Revision 1.37 2018/05/13 10:24:40CEST Singh, Sanjiv (uidr1340) 
  CHANGE:           Improvement of Yaw rate StandStill offset learning by considering Raw Wheel Speed and Wheel Ticks
  CHANGE:           Revision 1.36 2017/01/30 11:34:25CET Mani, Yugesh (uidj6870) 
  CHANGE:           -QAC Fix
  CHANGE:           Revision 1.35 2016/05/24 10:25:07CEST Singh, Sanjiv (uidr1340) 
  CHANGE:           Disabled ARS related NVM state check for camera project during NVM reading
  CHANGE:           Revision 1.34 2016/05/12 14:52:04CEST Singh, Sanjiv (uidr1340) 
  CHANGE:           Small Fix-
  CHANGE:           NVM State of yaw rate offset should be valid only during new learning
  CHANGE:           Revision 1.33 2016/02/26 10:36:52CET Mani, Yugesh (uidj6870) 
  CHANGE:           -Added CFG_VDY_NVM_LEARN_DATA_ERROR switch for declaration and definition of the function VDYYwrOffsetRangeOk
  CHANGE:           Revision 1.32 2016/02/22 12:49:07CET Singh, Sanjiv (uidr1340) 
  CHANGE:           QAC fixes
  CHANGE:           Revision 1.31 2016/02/19 07:40:06CET Singh, Sanjiv (uidr1340) 
  CHANGE:           adding and enabling of new the DEM(VDY_NVM_LEARN_DATA_ERROR)events logic:with new switch CFG_VDY_NVM_LEARN_DATA_ERROR.
  CHANGE:           Revision 1.30 2016/02/04 09:23:05CET Mani, Yugesh (uidj6870) 
  CHANGE:           - Integrated the turntable changes 
  CHANGE:           - Integrated the Camera NVM issue using switch
  CHANGE:           Revision 1.29 2016/01/08 16:44:04CET Singh, Sanjiv (uidr1340) 
  CHANGE:           Handling NVM cleared or Reset for Camera projects (MDB)
  CHANGE:           Revision 1.28 2016/01/05 15:51:39CET Singh, Sanjiv (uidr1340) 
  CHANGE:           writes NVM data  in every vdy cycle to the provide port for  camera(MDB) projects for steering wheel angle  Yaw  offset
  CHANGE:           Revision 1.27 2015/08/03 17:18:05CEST Singh, Sanjiv (uidr1340) 
  CHANGE:           Fix for YawRateOffset Peak nach Sensor-Reset.
  CHANGE:           In first cycle after hard reset.
  CHANGE:           For details -Analysis Task 363159
  CHANGE:           +
  CHANGE:           TurnTable Changes included
  CHANGE:           - Added comments -  uidr1340 [Aug 3, 2015 5:18:05 PM CEST]
  CHANGE:           Change Package : 363779:1 http://mks-psad:7002/im/viewissue?selection=363779
  CHANGE:           Revision 1.26 2015/06/11 17:57:56CEST Mani, Yugesh (uidj6870) 
  CHANGE:           - Turn table Changes adaptable for all projects
  CHANGE:           --- Added comments ---  uidj6870 [Jun 11, 2015 5:57:56 PM CEST]
  CHANGE:           Change Package : 346935:1 http://mks-psad:7002/im/viewissue?selection=346935
  CHANGE:           Revision 1.25 2014/12/03 11:15:03CET Balachandra, Swathi (uidj2447) 
  CHANGE:           Fix for MISRA violations
  CHANGE:           --- Added comments ---  uidj2447 [Dec 3, 2014 11:15:04 AM CET]
  CHANGE:           Change Package : 278585:1 http://mks-psad:7002/im/viewissue?selection=278585
  CHANGE:           Revision 1.24 2014/07/24 08:55:22CEST Wolter, Frank (wolterf) 
  CHANGE:           - changed true/false to work also in camera environments
  CHANGE:           --- Added comments ---  wolterf [Jul 24, 2014 8:55:22 AM CEST]
  CHANGE:           Change Package : 242151:1 http://mks-psad:7002/im/viewissue?selection=242151
  CHANGE:           Revision 1.23 2014/07/08 12:39:04CEST Wolter, Frank (wolterf) 
  CHANGE:           - removed MISRA violations
  CHANGE:           --- Added comments ---  wolterf [Jul 8, 2014 12:39:05 PM CEST]
  CHANGE:           Change Package : 247012:1 http://mks-psad:7002/im/viewissue?selection=247012
  CHANGE:           Revision 1.22 2014/04/08 14:49:17CEST Wolter, Frank (wolterf) 
  CHANGE:           - doxygen function header
  CHANGE:           - removed MISRA violations
  CHANGE:           --- Added comments ---  wolterf [Apr 8, 2014 2:49:18 PM CEST]
  CHANGE:           Change Package : 229561:1 http://mks-psad:7002/im/viewissue?selection=229561
  CHANGE:           Revision 1.21 2014/03/07 09:36:03CET Wolter, Frank (wolterf) 
  CHANGE:           - removed non-Autosar types
  CHANGE:           - removed QAC warnings
  CHANGE:           --- Added comments ---  wolterf [Mar 7, 2014 9:36:03 AM CET]
  CHANGE:           Change Package : 223834:1 http://mks-psad:7002/im/viewissue?selection=223834
  CHANGE:           Revision 1.20 2014/02/07 13:01:53CET Wolter, Frank (wolterf) 
  CHANGE:           - use of NVM state macros
  CHANGE:           - corrected descriptions and comment
  CHANGE:           --- Added comments ---  wolterf [Feb 7, 2014 1:01:53 PM CET]
  CHANGE:           Change Package : 217717:1 http://mks-psad:7002/im/viewissue?selection=217717
  CHANGE:           Revision 1.19 2013/09/26 13:48:47CEST Wolter, Frank (wolterf) 
  CHANGE:           - update code review by ICT
  CHANGE:           - Code Review #339136
  CHANGE:           - implemented QAC MISRA findings
  CHANGE:           - switched to Autosar types
  CHANGE:           - grammar/spelling corrections
  CHANGE:           --- Added comments ---  wolterf [Sep 26, 2013 1:48:48 PM CEST]
  CHANGE:           Change Package : 198819:1 http://mks-psad:7002/im/viewissue?selection=198819
  CHANGE:           

*****************************************************************************/
/* PRQA S 7013 EOF */
/* date: Unkown, reviewer: Suggested TCI Code Review, reason: Legacy code of ARS301, reducing lines of code changes component structure." */

/* PRQA S 7004 EOF */
/* date: Unkown, reviewer: Suggested TCI Code Review, reason: Legacy code of ARS301, reducing complexity adds risk and effort." */

/* PRQA S 3408 EOF */
/* date: Unkown, reviewer: Suggested TCI Code Review, reason: Legacy code of ARS301,It is already declared in header file but cant recognise since it is under MACRO condition  " */


/* QAC Level 1 & 2 Warning Suppression */
/* PRQA S 2919, 2211, 2981, 3206, 3212, 3227, 3469, 3473, 3678, 3679, 4330, 1505, 1532 EOF */
/* date: 2019-06-10, reviewer: Mahesh Patle (uidr0487), reason: This operation is intended */
/*****************************************************************************
  INCLUDES
*****************************************************************************/
/* PRQA S 0380 EOF */
/* date: 2019-06-10, reviewer: Mahesh Patle (uidr0487), reason: No Risk */

/* PRQA S 2755, 3447, 2743 EOF */
/* date: 2019-12-30, reviewer: Ramachandra Chinnaswamy (uids4735), reason: Fucntional Safe */

#include "vdy.h"


/*****************************************************************************
  SYMBOLIC CONSTANTS
*****************************************************************************/

/* Definitions for yaw rate filtering */

/// Minimum velocity for calculation of curvature out of yaw rate ; Min Vego for curvature calculation 
#define YWR_CURVE_V_MIN            C_F32_DELTA                  

/* Definitions for stand still offset calculation */

/// Max yaw rate gradient for stand still offset calculation  
#define VDY_YWR_OFF_STST_GRAD_ABS_MAX     DEG2RAD(1.2F)

/// Max averaging time for complete interval for stand still offset calculation 
#define VDY_YWR_OFF_STST_SUM_MAX_TIME     (60.0F)

/// Hold time after standstill for sampled yaw rate offset values for stand still offset calculation  
#define VDY_YWR_OFF_STST_INTERV_HOLD_TIME (60.0F)

/* Definitions for dyn. offset calculation */

 /// LP Max gradient for delta check for dyn. offset calculation
#define YWR_GRAD_DLT_DST_MAX      DEG2RAD(1.5F)

/* Definitions for quality */

/// Ecu time after which the offset is assumed tempered  
#define YWR_ELPSD_TIME_SENSOR_COOL (30.0F * 60.0F)

/// Zeit bis zur Guetereduzierung bei kaltem Sensor (Hochlauf)
#define YWR_TIME_SENSOR_COOL_MIN     (5.0F * 60.0F)

/// Zeit bis zur max Guetereduzierung bei kaltem Sensor (Hochlauf)    
#define YWR_TIME_SENSOR_COOL_MAX     (20.0F * 60.0F)

/// Faktor fuer maximale Guete bei kaltem Sensor  
#define YWR_Q_FACTOR_SENSOR_COOL_MAX           (1.0F)

/// Faktor fuer minimale Guete bei kaltem Sensor 
#define YWR_Q_FACTOR_SENSOR_COOL_MIN           (0.75F)

/// Zeit bis zur Guetereduzierung bei warmen Sensor (eingeschwungen)  
#define YWR_TIME_SENSOR_TEMP_MIN      (15.0F * 60.0F)

/// Zeit bis zur max Guetereduzierung bei warmen Sensor
#define YWR_TIME_SENSOR_TEMP_MAX      (25.0F * 60.0F)

/// Factor for maximum performance with warm sensor
#define YWR_Q_FACTOR_SENSOR_TEMP_MAX  (1.0F)

/// Factor for minimum performance with warm sensor
#define YWR_Q_FACTOR_SENSOR_TEMP_MIN  (0.85F)

#if (CFG_VDY_EX_YWR_NVM)
/// Minimum standstill adjust time to store offset in nonvolatile memory  
#define YWR_NVM_WRITE_MIN_ADJ_TIME     (3.0F)

/// Time gap between successive write access   
#define YWR_NVM_WRITE_NEW_GAP_TIME     (30.0F * 60.0F)

/// Time after gyro offset is assumed to be stable for first write  
#define YWR_NVM_OFFS_STABLE_TIME_1ST   (25.0F * 60.0F)

/// Time after gyro offset is assumed to be stable for non-first writes  
#define YWR_NVM_OFFS_STABLE_TIME       (35.0F * 60.0F)

/// After this Time gyro offset is written to NVM after first stand still and nvm offset state is 0 (no offset)  
#define YWR_NVM_WRITE_OFFS_ELAPS_TIME  (1.0F)

/// Max filter weight for filtering standstill for nvm storage  
#define YWR_NVM_FLT_MAX_WGHT            (10U)

/// Maximum value of nvm standstill offset status  
#define YWR_NVM_OFFSET_STATUS_MAX      (100U)

/// Maximum number of write accesses during one ignition cycle  
#define YWR_NVM_WRITE_IGN_MAX_NO         (2U)

/// Maximum status value for nvm standstill offset status
#define YWR_NVM_STATUS_MAX               (3U)

/* Linear ramp for nvm offset quality over time */

/// Start time with minimal confidence : Linear ramp for nvm offset quality over time 
#define YWR_TIME_Q_EEPROM_OFFSET_MIN     (0.0F)

/// End time with maximal confidence : Linear ramp for nvm offset quality over time
#define YWR_TIME_Q_EEPROM_OFFSET_MAX     YWR_TIME_SENSOR_TEMP_MAX

/// Minimum confidence : Linear ramp for nvm offset quality over time
#define YWR_Q_FACTOR_EEPROM_OFFSET_MIN   (0.75F)

/// Maximum confidence : Linear ramp for nvm offset quality over time
#define YWR_Q_FACTOR_EEPROM_OFFSET_MAX   (0.95F)

#endif


#if (CFG_VDY_YW_DYN_AVG)

/// Abtastdistanz fuer Filterung ueber Weg
#define YWR_DYNA_DIST_STEP         (40.F)

/// Zeit bis zur Guetereduzierung
#define YWR_TIME_DYNAVGOFF_MIN     (5.0F * 60.0F)

/// Zeit bis zur max Guetereduzierung
#define YWR_TIME_DYNAVGOFF_MAX     (15.0F * 60.0F)

/// Faktor fuer maximale Guete
#define YWR_Q_FACTOR_DYNAVGOFF_MAX (1.0F)

/// Faktor fuer minimale Guete
#define YWR_Q_FACTOR_DYNAVGOFF_MIN (0.60F)

/// Distanz bis zur Guetereduzierung
#define YWR_DIST_DYNAVGOFF_MIN     (3500.0F)

/// Distanz bis zur max Guetereduzierung
#define YWR_DIST_DYNAVGOFF_MAX     (5000.0F)

/// Faktor fuer maximale Guete
#define YWR_QUALITY_DYNAVGOFF_MAX  (0.95F)

/// Faktor fuer minimale Guete
#define YWR_QUALITY_DYNAVGOFF_MIN  (0.50F)

/// Zeit bis zur max Guetereduzierung
#define YWR_STDIST_SYMM_RESET      (7000.0F)

/// Offset Abweichung bis zur Guetereduzierung
#define YWR_OFFSET_DELTA_MIN       DEG2RAD(0.2F)

/// Offset Abweichung bis zur mittleren Reduzierung
#define YWR_OFFSET_DELTA_MED       DEG2RAD(0.5F)

/// Offset Abweichung bis zur maximalen Reduzierung
#define YWR_OFFSET_DELTA_MAX       DEG2RAD(0.7F)

/// Faktor fuer maximale Guete bei minimaler Abweichung
#define YWR_Q_FACTOR_DELTA_MAX        (1.0F)

/// Faktor fuer maximale Guete bei mittlerer Abweichung
#define YWR_Q_FACTOR_DELTA_MED        (0.75F)

/// Faktor fuer minimale Guete bei maximaler Abweichung
#define YWR_Q_FACTOR_DELTA_MIN        (0.0F)

/* Schwellen bei Dynamsicher Average-Offset bei Start */

/// Offsetzeit Start Guete
#define YWR_OFFSET_TIME_START_MIN     (0.F)

/// Offsetzeit End-Guete
#define YWR_OFFSET_TIME_START_MAX     (5.F*60.F)

/// Faktor fuer minimale Guete bei Start
#define YWR_Q_FACTOR_DELTA_START_MIN  (0.4F)

/// Faktor fuer maximale Guete bei Ende
#define YWR_Q_FACTOR_DELTA_START_MAX  (1.0F)

/// WSP minimale Eingangs-Guete
#define YWR_WSP_Q_START_MIN           (0.1F)

/// WSP maximale Eingangs-Guete
#define YWR_WSP_Q_END_MAX             (0.5F)

/// WSP minimaler Confidence Faktor zur Guetereduzierung
#define YWR_WSP_Q_CONF_START_MIN      (0.0F)

/// WSP maximaler Confidence Faktor zur Guetereduzierung 
#define YWR_WSP_Q_CONF_START_MAX      (1.0F)

/* Streckensymmetrie-Schwellen fuer Interims-Cache Offset */

/// Start Unsymmetrie Reduzierung
#define YWR_DYNC_STSYM_START          (1000.F)

/// Ende  Unsymmetrie Reduzierung
#define YWR_DYNC_STSYM_END            (2000.F)

/// Minimale Reduzierung des Einflusses
#define YWR_DYNC_Q_PERM_MAX           (1.F)

/// Maximale Reduzierung des Einflusses
#define YWR_DANC_Q_PERM_MIN           (0.F)

/// Mindest-Filter-Distanz zuer Guetereduzierung
#define YWR_DYNC_QRED_DIST_MIN        (3000.F)      

/// minimum driven distance to start dyn yawrate offset calculation
#define VDY_YWR_DYN_OFFSET_MIN_DIST   (2000.F)

#endif

/// offset data reduction if standstill offset calculation takes a long time
#define VDY_YWR_OFFSET_REDUCTION_FACTOR   (0.9F)

/// NVM Clear Indicator
#define NVM_CLEARED                    (0xFFFFFFFFU)

/* Mean velocity  for making obsereable flag TRUE */

/// Mean Velocity of VALID wheels 
#define WHL_VEL_MEAN            (0.05F)



/*****************************************************************************
  MACROS
*****************************************************************************/

/// Access to VDY YawRate Global Data
#define YWR_GET_ME                    (&VDYYwrGlobData)

/// Access to VDY YawRate Global Data Intra-Module Interface
#define YWR_GET_MIF_DATA              (VDYYwrGlobData.Io.mif)

/// Access to VDY YawRate Global NVM Read Data
#define YWR_GET_NVM_READ              (VDYYwrGlobData.Io.nv_read)

/// Access to VDY YawRate Global NVM Write Data
#define YWR_GET_NVM_WRITE             (VDYYwrGlobData.Io.nv_write)
#if ( (defined(CFG_VDY_NVM_LEARN_DATA_ERROR)) && (CFG_VDY_NVM_LEARN_DATA_ERROR) )
/// Check for valid values written into NVM
#define YWR_SET_NVM_WRITE             (*VDYYwrGlobData.Io.YwrNVMerrOffsRg)
#endif

/// Access to VDY YawRate Global Sensor Data
#define YWR_GET_DATA                  (&VDYYwrGlobData.Sensor)

/// Access to VDY YawRate Global Sensor Data
#define YWR_GET_OFFS                  (&VDYYwrGlobData.Offset) 


/*****************************************************************************
  TYPEDEFS
*****************************************************************************/


/*****************************************************************************
  VARIABLES
*****************************************************************************/
SET_MEMSEC_VAR(VDYYwrGlobData)
STATIC_VAR VDYYwrData_t  VDYYwrGlobData;	
#if ( (defined(CFG_VDY_TURNTABLE_DETECTION)) && (CFG_VDY_TURNTABLE_DETECTION) )
/// Previous Estimated Yaw Rate Offset Value
STATIC_VAR float32  PrevYawRateOffset; 
#endif

#if( (defined(CFG_VDY_SWA_AY_YAW_SSD_WLD_DIS_NVM_VALID_CHECK))&&(CFG_VDY_SWA_AY_YAW_SSD_WLD_DIS_NVM_VALID_CHECK))
SET_MEMSEC_VAR(LastYawNvmData)								
/// New structure for storing previous cycle yaw rate offset of NVM
STATIC_VAR VDYLastNvYawCal_t LastYawNvmData;
#endif


/*****************************************************************************
  LOCAL FUNCTION PROTOTYPES
*****************************************************************************/

/* **********************************************************************
  @fn                     vdyYwrCalcRunnigTime */ /*!
  @brief           Calculate run times required for offset calibration

  @description     Calculate run times required for offset calibration

  @return          static void

  @c_switch_part   CFG_VDY_EX_YWR_NVM : Enable offset storage  in nonvolatile memory
  @c_switch_full   None 

  @pre             None
  @post            No changes
  @InOutCorrelation
					  - Get cycle time
					  - Get reference to offset data
					  - Count Maximum ECU running time (10 days) and update ECU runtime up to maximum permitted value (10 days)
					  - Count Maximum time since last calibration (1 hour) and update time since last offset calibration up to maximum permitted value (1 hour)
					  - Start counting time after first value has been written and update time since last storage of standstill offset to nonvolatile memory
  
					  @startuml
						start
							if (pOffsData->EcuElpsdTime >= (10.0F * 24.0F * 60.0F * 60.0F)) then (YES)
									:Set the EcuElpsdTime to Maximum ECU running time 10 days;
								else (No)
									:keep on update EcuElpsdTime with CycleTime until it reaches to Maximum ECU running time;
							endif
							if (pOffsData->OffsElpsdTime >= (60.0F * 60.0F)) then (YES)
									:Set the Maximum time since last calibration ie 1 hour;
								else (No)
									:keep on update OffsElpsdTime with CycleTime until it reaches to Maximum offset calibration time;
							endif
							if (pOffsData->StandStillEepromOffset.TimeLastWrittenEepromOffset >= (60.0F * 60.0F)) then (YES)
									:Set the last storage of standstill offset to nonvolatile memory TimeLastWrittenEepromOffset to Maximum time  ie 1 hour;
								else (No)
									if (pOffsData->StandStillEepromOffset.NumOfWrittenOffsets > 0) then (YES)
										:next ignition cycle Start timer not until first value has been written, update TimeLastWrittenEepromOffset with cycle time till the max time;
									endif
							endif
						stop
					  @enduml
  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_ywr.c -> NA
  @traceability		
  - L4
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-878-00026448
**************************************************************************** */
STATIC_MTD void vdyYwrCalcRunnigTime(void);


/* **********************************************************************
  @fn                     vdyYwrInitYawRateData */ /*!
  @brief           Initialize Yaw rate sensor data  the data

  @description     Initialize Yaw rate sensor data  the data

  @return          static void

  @param[in,out]   *YawRateData : Yaw rate sensor data  

  @c_switch_part   None 
  @c_switch_full   None 

  @pre             None
  @post            No changes
  @InOutCorrelation
					- Initialize the data
  
					@startuml
							start
								:   YawRateData->YawRate           = VDY_ZERO_F;
                                :   YawRateData->YawRateOld        = VDY_ZERO_F;
                                :   YawRateData->YawRateCurveFilt1 = VDY_ZERO_F;
                                :   YawRateData->YawRateCurveFilt2 = VDY_ZERO_F;
                                :   YawRateData->YawRateCurveFilt3 = VDY_ZERO_F;
                                :   YawRateData->YwCurveOld        = VDY_ZERO_F;
                                :   YawRateData->Gradient          = VDY_ZERO_F;
                                :   YawRateData->GradientAbsOld    = VDY_ZERO_F;
                                :   YawRateData->DeltaDist         = VDY_ZERO_F;
                                :   YawRateData->Valid             = (boolean)FALSE;
                                :   YawRateData->YwFirstCycleDone  = (boolean)FALSE;
                                :   YawRateData->FilterTime        = VDY_ZERO_F;
							stop
					@enduml
  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_ywr.c -> NA
  @traceability			  - 
  - L4
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-880-00026448
**************************************************************************** */
STATIC_MTD void vdyYwrInitYawRateData(VDYYwrSenData_t *YawRateData);


/* **********************************************************************
  @fn                     vdyYwrCommonInit */ /*!
  @brief           Initialize Yaw Rate Sensor Data (not the offset data)

  @description     Create an instance of VDYYwrSenData_t (Yaw Rate Sensor Data) Initialize it  (not the offset data)

  @return          static void

  @glob_in         YWR_GET_DATA : Yaw rate sensor data
  @glob_out        None

  @c_switch_part   None 
  @c_switch_full   None 

  @pre             None
  @post            No changes
  @InOutCorrelation	
					 - Initialize Yaw rate data
  
					 @startuml
							start
								:Get Reference of Yaw Rate Data; 
								:Initialize Yaw Rate Data \n vdyYwrInitYawRateData(YawRateData);
							stop
					@enduml
  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_ywr.c -> NA
  @traceability			  
  - L4
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-880-00026448

  @author                 R.Ehrhardt
**************************************************************************** */
STATIC_MTD void vdyYwrCommonInit(void);


/* **********************************************************************
  @fn                     vdyYwrOffsetInit */ /*!
  @brief           Initialize Yaw Rate offset Data

  @description     Initialize Yaw Rate offset Data

  @return          static void

  @param[in]       *nv_read : vdy nvm input and output data

  @glob_in         YWR_GET_OFFS : Zero point offset
  @glob_out        None 

  @c_switch_part   CFG_VDY_EX_YWR_NVM : Enable offset storage  in nonvolatile memory
  @c_switch_full   None 

  @pre             None
  @post            No changes
  @InOutCorrelation
					- Initialize Yaw Rate offset Data
  
					@startuml
							start
								:Get an instance of Yaw rate offset data \n VDYYwrOffsData_t *OffsData \n  OffsData = YWR_GET_OFFS;
								:Initialize Yaw Rate offset Data \n vdyYwrInitOffsetData(OffsData);
								if(CFG_VDY_EX_YWR_NVM is enabled) then (YES)
										:Read Yaw rate offset from EEprom \n vdyYwrEepromReadYwOffset(&OffsData->StandStillEepromOffset.YawRateOffset, nv_read);
                                        :Calculate quality of eeprom yaw rate offset \n vdyYwrCalcEepromOffsetQuality(&OffsData->StandStillEepromOffset);
								endif
							stop
					@enduml
  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_ywr.c -> NA
  @traceability			  - NA
**************************************************************************** */
STATIC_MTD void vdyYwrOffsetInit(const VDYNvIoData_t *nv_read);


/* **********************************************************************
  @fn                     vdyYwrInitOffsetData */ /*!
  @brief           Initializes Yaw Rate Offset Data

  @description     Initializes Yaw Rate Offset Data

  @return          static void

  @param[in,out]   *OffsData : Zero point offset

  @glob_in         OFFS_NON : No offset type present
  @glob_out        None 

  @c_switch_part   
				  - CFG_VDY_EX_YWR_NVM : Enable offset storage  in nonvolatile memory
				  - CFG_VDY_YW_DYN_AVG : Enable dynamic gyro offst compensation
  @c_switch_full   None 

  @pre             None
  @post            No changes
  @InOutCorrelation
					- Initialize yaw rate module data
  
					@startuml
							start
								:  OffsData->YawRateOffset          = VDY_ZERO_F;
                                :  OffsData->Quality                = VDY_ZERO_F;
                                :  OffsData->MaxQuality             = VDY_ZERO_F;
                                :  OffsData->OffsElpsdTime          = VDY_ZERO_F;
                                :  OffsData->Temperature            = VDY_ZERO_F;
                                :  vdyYwrInitStandStillOffset(&OffsData->StandStillOffset);
                                :  vdyYwrInitStandStillEepromOffset(&OffsData->StandStillEepromOffset);
                                :  vdyYwrInitDynOffsAvg(&OffsData->DynOffsAvg);
                                :  vdyYwrInitDynOffsInterim(&OffsData->DynOffsAvg.IntOffs);
                                :  OffsData->QualNoRed              = OffsData->Quality;
                                :  OffsData->Cache.YawRateOffset    = VDY_ZERO_F;
                                :  OffsData->Cache.Quality          = VDY_ZERO_F;
                                :  OffsData->EcuElpsdTime           = VDY_ZERO_F;
                                :  OffsData->OffsCompOK             = (boolean)FALSE;
                                :  OffsData->TemperOK               = (boolean)FALSE;
                                :  OffsData->OffsType               = (VDYYwrOffsType_t)OFFS_NON;
							stop
					@enduml
  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_ywr.c -> NA
  @traceability			  - NA
**************************************************************************** */
STATIC_MTD void vdyYwrInitOffsetData( VDYYwrOffsData_t *OffsData);

/* **********************************************************************
  @fn                     vdyYwrCalcOffsetQualityTime */ /*!
  @brief           Calculates the current value of the yaw rate offset over the elapsed time

  @description     Calculates the current value of the yaw rate offset over the elapsed time

  @return          void

  @param[in,out]   *OffsQuality : Offset Quality
  @param[in]       MaxQuality : Max Quality
  @param[in,out]   OffsElpsdTime : Time since the last reconciliation in s
  @param[in]       TemperOK : Temerature Ok flag

  @c_switch_part   
				   - CFG_VDY_YW_DYN_AVG : Enable dynamic gyro offst compensation 
				   - CFG_VDY_EX_YWR_NVM : Enable offset storage  in nonvolatile memory
  @c_switch_full   None

  @pre             None
  @post            No changes
  @InOutCorrelation
					- Get yaw rate offset data
					- When dynamic gyro offst compensation is enabled 
						- When the distance is greater than Minimum filter distance to reduce the weight
							- When the variance is greater than minimum quality 
								- Set wghtPermit (factor for approved quality reduction) to 1
						- otherwise, calculate wghtPermit with Linear ramp function
						- Calculate quality reduction with Linear ramp function
						- When Offset is estimated by averaging 
							- Multiply quality reduction with Linear ramp function
						- Updat quality reduction with factor for approved quality reduction - OffsData->DynOffsAvg.QReduce =  1.0F - ((1.0F - OffsData->DynOffsAvg.QReduce) * wghtPermit)
					- Otherwise 
						- Set quality reduction to 1.
					- Depending on the effective offset type offset quality is updated
						- when dynamic gyro offset compensation is enabled
							- For Offset estimated by averaging  and OFFS_DYN_INTER
								- Reduce the quality
						- when offset storage in nonvolatile memory enabled
							- for Offset acquired from non-volatile memory
								- set offset quality to 1
					- For, No offset type present, Offset merged standstill and temp table, Offset acquired from standstill and  Offset acquired from temperature table
						- IfTemperOK, Annealed condition -> reduce quality
						- If not change quality
					- if dynamic gyro offset compensation enabled
						- set OffsData->QualNoRed Non-reduced value for takeover test to
						- Reduce Quality
  
						@startuml
							start
								:OffsData  = YWR_GET_OFFS;
								if(OffsData->OffsType==OFFS_STANDST_EEPROM) then (YES)
									:set offset quality to 1;
								endif
								if((OffsData->OffsType==OFFS_NON)||(OffsData->OffsType==OFFS_DYN_APPRX)||(OffsData->OffsType==OFFS_STANDST)||(OffsData->OffsType==OFFS_TEMPER_TABLE)) then (YES)
									if(TemperOK == (boolean)TRUE) then (YES)
										:slowly reduce quality;
									else
										::quickly reduce quality;
									endif
								endif
							stop
						@enduml
  @testmethod
	- Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_ywr.c -> \n
                            TEST_vdyYwrCalcOffsetQualityTime_001(),
                            TEST_vdyYwrCalcOffsetQualityTime_002(),
                            TEST_vdyYwrCalcOffsetQualityTime_003(),
                            TEST_vdyYwrCalcOffsetQualityTime_004(),
                            TEST_vdyYwrCalcOffsetQualityTime_005(),
                            TEST_vdyYwrCalcOffsetQualityTime_006()
  @traceability
  - L4
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-883-00026448
  @author                 M.Sachs
**************************************************************************** */
STATIC_MTD void vdyYwrCalcOffsetQualityTime(fQuality_t *OffsQuality,fQuality_t MaxQuality,fTime_t OffsElpsdTime,boolean TemperOK);



/* **********************************************************************
  @fn                     vdyYwrTakeOffs */ /*!
  @brief           Calculates the current value of the yaw rate offset over the elapsed time

  @description     Calculates the current value of the yaw rate offset over the elapsed time

  @return          static void

  @param[in,out]   *OffsData : Yaw Rate Offset Data
  @param[in]       Offset : Yaw Rate Offset
  @param[in]       Quality : Yaw Rate Offset Quality
  @param[in]       Type : Yaw Rate Offset Type

  @glob_in         YWR_GET_OFFS : Zero point offset
  @glob_out        None 

  @c_switch_part   CFG_VDY_YW_DYN_AVG : Enable dynamic gyro offst compensation
  @c_switch_full   None : 

  @pre             None
  @post            No changes
  @InOutCorrelation
					  - Check if a new offset is to be taken over 
					  - Take standstill offset, Quality type and Reset time to quality calculation
					  - Set the Temper flag if the ECU has been running longer
					  - Mark offset as taken over
  
					  @startuml
						start
							if ((Quality >= 0.0001F)&& ( (Type == (VDYYwrOffsType_t) OFFS_TEMPER_TABLE)|| (Quality >= OffsData->Quality))) then (YES)
									:takeof the new offset OffsData->YawRateOffset = Offset;
									:set the OffsData->MaxQuality = Quality;
									:set OffsData->OffsType = Type;
									:reset OffsData->OffsElpsdTime = 0;
								if (Type != (VDYYwrOffsType_t) OFFS_TEMPER_TABLE) then (YES)
									if (OffsData->EcuElpsdTime > YWR_ELPSD_TIME_SENSOR_COOL ) then (YES)
										:set OffsData->TemperOK = TRUE;
									endif
								endif
								:Set OffsetTaken to TRUE;								 
							endif
						stop
					@enduml
  @testmethod			  
	- Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_ywr.c -> \n
                            TEST_vdyYwrTakeOffs_001(),
                            TEST_vdyYwrTakeOffs_002(),
                            TEST_vdyYwrTakeOffs_003(),
                            TEST_vdyYwrTakeOffs_004(),
                            TEST_vdyYwrTakeOffs_005()

  @traceability			  
	- NA

  @author                 M.Sachs
**************************************************************************** */
STATIC_MTD boolean vdyYwrTakeOffs(VDYYwrOffsData_t *OffsData, fYawRate_t Offset,fQuality_t Quality, VDYYwrOffsType_t Type);

/* ***********************************************************************************************************************************************
  @fn                     vdyYwrCalcOffset */ /*!
  @brief           Calculation of Yaw rate offset from the Yaw rate

  @description     Calculation of Yaw rate offset from the Yaw rate

  @return          static void

  @param[in]       *YawRate : Yaw Rate Signal
  @param[in]       *proPorts : Provide Ports
  @param[in]       *input : VDY Input Data 
  @param[in]       RawVelo : Raw Velocity
  @param[in,out]   *OffsData : Offset Data

  @glob_in         CaliMode : Calibration inhibition states
  @glob_in         VehVelocityCorr : Longitudinal motion velocity correction
  @glob_out        None 

  @c_switch_part   
				   - CFG_VDY_TURNTABLE_DETECTION : Enables the Turn Table detection and limit max. delta 4deg/sec yaw rate offset compensation at one learning cycle
				   - CFG_VDY_EX_YWR_NVM : Enable offset storage  in nonvolatile memory
				   - CFG_VDY_YW_DYN_AVG : Enable dynamic gyro offst compensation
  @c_switch_full   None 

  @pre             None
  @post            No changes
  @InOutCorrelation
					- When CFG_VDY_TURNTABLE_DETECTION enabled
						- Detect the turn table and set the flag
							- (if the differences between Filtered wheel speeds yaw rate with wheel load departure - (Front & Rear) and measured yaw rate are greater than VDY_YAW_RATE_DIFF_THRESHOLD then turn table is detected and flag is set)
						- increment u_turntableCounter till VDY_TURN_TABLE_ENABLE_TIME (no. of cycles to come out of the b_turn_table_flag)
						- Otherwise decrement u_turntableCounter 
						- When u_turntableCounter is 0 reset turn table flag
						- During the Ignition On and the ego vehicle is in standstill mode initailizing the b_PrevStandstillOK to FALSE only in the first cycle for storing the PrevYawRateOffset value
					- Determine standstill for offset compensation (with help of motion state)
					- To compute offset the below four conditions must be true
						- Gradient must be less than 1.2 degree
						- Input Yaw Rate must be valid
						- Vehicle should not be on Turn Table
						- Vehicle should be in the standstill
					- if yaw rate offset is observable
						- copy yaw rate offset to PrevYawRateOffset
					- Start standstill offset calibration
					- Save standstill offset in nonvolatile memory
					- When dynamic gyro offst compensation is enabled
						- If Dynamic adjustment via averaged straight-ahead driving
							- Calculate dynamic offset data on averaged yaw rate
							- Calculate Dynamic offset for initialized steering angle status
						- Test dynamic interim offset for takeover - Calculates the current value of the spin rate offset over the elapsed time
						- Use (if) new dynamic median offset for takeover
					- Use (if) new Standstill offset for takeover
					- Calculate Offset Quality
					- If offset storage in nonvolatile memory enabled
						- if the standstill offset is not available, Use offset from EEPROM
							- Use EEPROM offset with existing MaxQuality
					- If Offset acquired from non-volailte memory 
						- Calculates the current value of the EEPROM off-set over the elapsed time
  
					@startuml
						start
							if ((yawRateDiffFront > VDY_YAW_RATE_DIFF_THRESHOLD) && (yawRateDiffRear > VDY_YAW_RATE_DIFF_THRESHOLD)) then (YES)
								:set b_turn_table_flag = TRUE;
								if (u_turntableCounter < 25) then (YES)
										:increment the turn table counter u_turntableCounter++;
								endif
							else (No)
								if(ifu_turntableCounter > 0U) then (YES)
									:decrement the turn table counter u_turntableCounter -- ;
								endif
							endif
							if(u_turntableCounter == 0U) then (YES)
								:set b_turn_table_flag = (boolean)FALSE;								 
							endif
							if(b_initFlag == (boolean)FALSE) then (YES)
								:During the Ignition On and the ego vehicle is in standstill mode initailizing the b_PrevStandstillOK to FALSE only in the first cycle for storing the PrevYawRateOffset value;
								:b_initFlag  = (boolean)TRUE;
							else (No)
								:set b_PrevStandstillOK = pStStOffs->StandstillOK;
							endif
							if (if any Wheel Ticks is/are valid) then (YES)
								:set WhltickValid = (VDYIoStateTypes_t)VDY_IO_STATE_VALID;
							else (No)
								if (if external velocity input state is valid) then (YES)
									:set MeanWhlVel = input->Signals.VehVelocityExt;
								endif
								:if CFG_VDY_MFC set MeanWhlVel = RawVelo;
								:else MeanWhlVel = proPorts->pVehicleDynamicSignals->Longitudinal.VelocityRaw;
							endif
							if (Check all four wheel pulse Probability of Standstill is greater than their respective wheel pulse Probability of Forward and reverse) then (YES)
								:set MAX_STDST = (boolean)TRUE;
							endif
							if((YawRate->Gradient<= VDY_YWR_OFF_STST_GRAD_ABS_MAX) && (YawRate->Valid != (boolean)FALSE) && (b_turn_table_flag == (boolean)FALSE) && (pStStOffs->StandstillOK != (boolean)FALSE) && (MeanWhlVel < WHL_VEL_MEAN) && (MAX_STDST == (boolean)TRUE)) then (Yes)
								:set pStStOffs->Observable true;
							else (No)
								:set pStStOffs->Observable false;
							endif
							if ((b_PrevStandstillOK == (boolean)FALSE) && (pStStOffs->StandstillOK == (boolean)TRUE)) then (YES)
								:set PrevYawRateOffset = pStStOffs->YawRateOffset;
							endif
							if (if CaliState is not of VDY_CAL_YWR_OFFS_STST) then (YES)
								:Start standstill offset calibration vdyYwrEstStandstillOffset(YawRate->YawRate, YawRate->Valid, pStStOffs);
							endif
							: Save standstill offset in nonvolatile memory vdyYwrSaveStandstillOffset(OffsData);
							: if new Standstill offset, takeover;
							: Calculate Offset Quality;
							if( (VehicleSpeed > YWR_CURVE_V_MIN) && (OffsData->OffsType == (VDYYwrOffsType_t) OFFS_NON) ) then (YES)
								:If there is no offset, use EEPROM offset with existing MaxQuality;
							else (No)
								:current standstill offset available;
							endif
							if (OffsData->OffsType == (VDYYwrOffsType_t) OFFS_STANDST_EEPROM) then (YES)
								:Determin the rate of rotation data based on EEPROM offset over time;
							else (No)
								:no EEPROM offset, no special benefit must be determined;
							endif
						stop
					@enduml
  @testmethod			  
	- Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_ywr.c -> \n
                            TEST_vdyYwrCalcOffset_001(),
                            TEST_vdyYwrCalcOffset_002(),
                            TEST_vdyYwrCalcOffset_003(),
                            TEST_vdyYwrCalcOffset_004(),
                            TEST_vdyYwrCalcOffset_005(),
                            TEST_vdyYwrCalcOffset_006(),
                            TEST_vdyYwrCalcOffset_007(),
                            TEST_vdyYwrCalcOffset_008(),
                            TEST_vdyYwrCalcOffset_009(),
                            TEST_vdyYwrCalcOffset_010()
  @traceability			  
  - L3
    - doors://RBGS854A:40000/?version=2&prodID=0&view=000000cd&urn=urn:telelogic::1-503e822e5ec3651e-O-285-000221c8 
    - doors://rbgs854a:40000/?version=2&prodID=0&view=0000012f&urn=urn:telelogic::1-503e822e5ec3651e-O-1606-000221c8
  - L4
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-730-00026448
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-877-00026448 
*************************************************************************************************************************************************************** */
#if (CFG_VDY_MFC)
STATIC_MTD void vdyYwrCalcOffset(const VDYYwrSenData_t *YawRate, VDYYwrOffsData_t *OffsData, const VDYInputData_t *input, const proVdyPrtList_t *proPorts, const float32 RawVelo);
#else
STATIC_MTD void vdyYwrCalcOffset(const VDYYwrSenData_t *YawRate, VDYYwrOffsData_t *OffsData, const VDYInputData_t *input, const proVdyPrtList_t *proPorts);
#endif


/* **********************************************************************
  @fn                     vdyYwrCalcToAutocode */ /*!
  @brief           Fill the interface to the autocode

  @description     Fill the interface to the autocode

  @return          static void

  @param[in,out]   *Offs : Offset Data

  @glob_in         
				  - VDY_YAWRATE_STATE_NVM : dynamic offset taken from NVM
				  - VDY_YAWRATE_STATE_STANDSTILL : dynamic offset is stand still offset
				  - VDY_YAWRATE_STATE_NOT_ESTIMATED : yaw rate stand still offset never ever estimated
  @glob_out        None 

  @c_switch_part   CFG_VDY_EX_YWR_NVM : Enable offset storage  in nonvolatile memory
  @c_switch_full   None 

  @pre             None
  @post            No changes
  @InOutCorrelation 
					- offset storage  in nonvolatile memory is enabled
					- When yaw rate change is detected
						- take the new offset value into autocode offset data
							- When offset type is OFFS_STANDST_EEPROM (Offset acquired from non-volailte memory)
 								- set autocode offset data state to Offset  to VDY_YAWRATE_STATE_NVM (dynamic offset taken from NVM)
							- Otherwise, set autocode offset data state to Offset  to VDY_YAWRATE_STATE_STANDSTILL (dynamic offset is stand still offset)
					- When Offset Type is OFFS_NON (No offset type present)
						- Set autocode offset data to 0 and state to VDY_YAWRATE_STATE_NOT_ESTIMATED (yaw rate stand still offset never ever estimated)
					- Otherwise set autocode offset data state to 0
					- Check if the offset is a dynamic offset and set the dynamic flag, accordingly set IsDynamic to True or False
  
					@startuml
						start
							if (((Offs->OffsElpsdTime < VDY_ONE_F) && (Offs->OffsType == (VDYYwrOffsType_t) OFFS_STANDST) )|| ( (Offs->OffsType==(VDYYwrOffsType_t) OFFS_TEMPER_TABLE) || (Offs->OffsType==(VDYYwrOffsType_t) OFFS_DYN_APPRX)  || (Offs->OffsType==(VDYYwrOffsType_t) OFFS_STANDST_EEPROM) ) || (( YWR_GET_MIF_DATA->FirstCycleDone == (boolean)FALSE ) && (Offs->OffsType != (VDYYwrOffsType_t) OFFS_NON))) then (YES)
								if (Offs->OffsType == (VDYYwrOffsType_t) OFFS_STANDST_EEPROM) then (YES)
										:Set Offs->ToAutocode.OffsData.state = 2;
								else (No)
										:Offs->ToAutocode.OffsData.state = 1;
								endif
								:new offset was taken Offs->ToAutocode.OffsData.offset = Offs->YawRateOffset;
							else (No)
								if (Offs->OffsType == (VDYYwrOffsType_t) OFFS_NON) then (YES)
									:set Offs->ToAutocode.OffsData.offset = 0;
									:set Offs->ToAutocode.OffsData.state = 3;
								else (No)
									:set Offs->ToAutocode.OffsData.state =0;
								endif
							endif
						stop
					@enduml
  @testmethod		- Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_ywr.c -> \n
                            TEST_vdyYwrCalcToAutocode_001(),
                            TEST_vdyYwrCalcToAutocode_002(),
                            TEST_vdyYwrCalcToAutocode_003(),
                            TEST_vdyYwrCalcToAutocode_004(),
                            TEST_vdyYwrCalcToAutocode_005(),
                            TEST_vdyYwrCalcToAutocode_006(),
                            TEST_vdyYwrCalcToAutocode_007(),
                            TEST_vdyYwrCalcToAutocode_008(),
                            TEST_vdyYwrCalcToAutocode_009(),
                            TEST_vdyYwrCalcToAutocode_010(),
                            TEST_vdyYwrCalcToAutocode_011(),
                            TEST_vdyYwrCalcToAutocode_012(),
                            TEST_vdyYwrCalcToAutocode_013()

  @traceability		- 
  - L4
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1120-00026448

  @author                 J.Spruck
**************************************************************************** */
STATIC_MTD void vdyYwrCalcToAutocode(VDYYwrOffsData_t *Offs);
#if ( (defined(CFG_VDY_NVM_LEARN_DATA_ERROR)) && (CFG_VDY_NVM_LEARN_DATA_ERROR) )
	
/* ***********************************************************************/ /*!
  Functionname:           vdyYwrOffsetRangeOk
  @brief                  Checks YawRate offset range

  @return                 Offset OK = TRUE, NOT_OK = FALSE
  @param[in]              Offset value
  @param[out]             -
  @InOutCorrelation - 
  
  @testmethod		- NA
  @traceability		- Not Supported anymore
**************************************************************************** */
STATIC_MTD boolean vdyYwrOffsetRangeOk(fYawRate_t Offset);
#endif
#if (CFG_VDY_YW_DYN_AVG)
	
/* **********************************************************************
  @fn                     vdyYwrInitDynOffsAvg */ /*!
  @brief           Initialize Dynamic yaw rate Matching data over averaged yaw rate  

  @description     Initialize Dynamic yaw rate Matching data over averaged yaw rate  

  @return          static void

  @param[in,out]   *DynOffsAvg : Dynamic yaw rate Matching data over averaged yaw rate 

  @c_switch_part   None 
  @c_switch_full   CFG_VDY_YW_DYN_AVG : Enable dynamic gyro offst compensation 

  @pre             None
  @post            No changes
  @InOutCorrelation
					  - Initialize  Dynamic Yaw rate offset data
  
                      @startuml
						start
							:  Take refernce Offset Data \n const VDYYwrOffsData_t *Offs  = YWR_GET_OFFS;
                            :  DynOffsAvg->YwFilt[0].fout = Offs->YawRateOffset;
                            :  DynOffsAvg->YwFilt[1].fout = Offs->YawRateOffset;
                            :  DynOffsAvg->YwFilt[0].fin  = Offs->YawRateOffset;
                            :  DynOffsAvg->YwFilt[1].fin  = Offs->YawRateOffset;
                            :  DynOffsAvg->YawRateOffset  = Offs->YawRateOffset;
                            :  DynOffsAvg->YwDist         = VDY_ZERO_F;
                            :  DynOffsAvg->MaxQuality     = VDY_ZERO_F;
                            :  DynOffsAvg->StDrv          = VDY_ZERO_F;
                            :  DynOffsAvg->YwDrvDistThr   = VDY_ZERO_F;
                            :  DynOffsAvg->DrvDistRed     = VDY_ZERO_F;
                            :  DynOffsAvg->YwFiltDet[0].fout = Offs->YawRateOffset;
                            :  DynOffsAvg->YwFiltDet[1].fout = Offs->YawRateOffset;
                            :  DynOffsAvg->YwFiltDet[0].fin  = Offs->YawRateOffset;
                            :  DynOffsAvg->YwFiltDet[1].fin  = Offs->YawRateOffset;
                            :  DynOffsAvg->YawRateDet        = Offs->YawRateOffset;
                            :  DynOffsAvg->QReduce           = VDY_ONE_F;
                            :  DynOffsAvg->FlStwAStat        = (boolean)FALSE;
                            : return;
						stop
					@enduml
  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_ywr.c -> NA
  @traceability			  - NA

  @author                 T.Diepolder
**************************************************************************** */
STATIC_MTD void vdyYwrInitDynOffsAvg(VDYYwrDynOffsAvg_t *DynOffsAvg);


/* **********************************************************************
  @fn                     vdyYwrInitDynOffsInterim */ /*!
  @brief           Initialization Dynamic Yaw Rate-Interims-Offset Data

  @description     Initialization Dynamic Yaw Rate-Interims-Offset Data

  @return          static void

  @param[in,out]   *DynOffsInter : Dynamic Yaw Rate-Interims-Offset for Initial state

  @c_switch_part   None 
  @c_switch_full   CFG_VDY_YW_DYN_AVG : Enable dynamic gyro offst compensation

  @pre             None
  @post            No changes
  @InOutCorrelation
					- Initialize interim offset data
  
                    @startuml
						start
							:  Take refernce Offset Data \n const VDYYwrOffsData_t *Offs  = YWR_GET_OFFS;
                            :  DynOffsInter->YawRateOffset  = Offs->YawRateOffset;
                            :  DynOffsInter->YwFiltInt[0].fout = Offs->YawRateOffset;
                            :  DynOffsInter->YwFiltInt[1].fout = Offs->YawRateOffset;
                            :  DynOffsInter->YwFiltInt[0].fin  = Offs->YawRateOffset;
                            :  DynOffsInter->YwFiltInt[1].fin  = Offs->YawRateOffset;
                            :  DynOffsInter->MaxQuality = VDY_ZERO_F;
                            :  DynOffsInter->DistThrd   = VDY_ZERO_F;
                            : return;
						stop
					@enduml
  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_ywr.c -> NA
  @traceability			  - NA

  @author                 T.Diepolder
**************************************************************************** */
STATIC_MTD void vdyYwrInitDynOffsInterim(VDYYwrDynOffsInter_t *DynOffsInter);



/* **********************************************************************
  @fn                     vdyYwrCalcDynOffsAvg */ /*!
  @brief           Caclulate dynamic offset data on averaged yaw rate

  @description     Offset determination over averaged yaw rate
                   Assuming is that on longer distance in the middle
                   Straight ahead

  @return          static float32

  @param[in]       *YawRateData : Yaw Rate Sensor Data
  @param[in,out]   *DynOffset : Dynamic Offset Data
  @param[in]       *Offs : Yaw Rate Offset Data

  @c_switch_part   CFG_VDY_EX_YWR_NVM : Enable offset storage  in nonvolatile memory
  @c_switch_full   CFG_VDY_YW_DYN_AVG : Enable dynamic gyro offst compensation

  @pre             None
  @post            No changes
  @InOutCorrelation
					- Offset determination over averaged yaw rate assuming is that on longer distance in the middle straight ahead
  
  @testmethod			  
	- Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_ywr.c ->
  @traceability		      
  - L3
    - doors://RBGS854A:40000/?version=2&prodID=0&view=000000cd&urn=urn:telelogic::1-503e822e5ec3651e-O-1397-000221c8
  - L4
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-652-00026448

  @author                 T.Diepolder
**************************************************************************** */
STATIC_MTD float32 vdyYwrCalcDynOffsAvg(const VDYYwrSenData_t *YawRateData, VDYYwrDynOffsAvg_t *DynOffset, const VDYYwrOffsData_t *Offs);


/* **********************************************************************
  @fn                     vdyYwrCalcQRedRamp */ /*!
  @brief           Ramp for good reduction or intermittent averaging

  @description     Ramp for good reduction or intermittent averaging

  @return          static float32

  @param[in]       *OffsData : Offset Data

  @c_switch_part   None 
  @c_switch_full   CFG_VDY_YW_DYN_AVG : Enable dynamic gyro offst compensation

  @pre             None
  @post            No changes
  @InOutCorrelation
					  - Q Red Ramp for good reduction or intermittent averaging
					  - Perform Two-stage ramp to reduce the weight
  
  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_ywr.c -> NA
  @traceability			  - NA
**************************************************************************** */
STATIC_MTD float32 vdyYwrCalcQRedRamp(const VDYYwrOffsData_t *OffsData);


/* **********************************************************************
  @fn                     vdyYwrMergeOffsetDrift */ /*!
  @brief           Fusion of previously effective offset with interims
                   Offset at high drift, since material reduction is not
                   sufficient

  @description     Fusion of previously effective offset with interims
                   Offset at high drift, since material reduction is not
                   sufficient

  @return          static void

  @param[in,out]   *OffsData : Yaw Rate Offset Data
  @param[in,out]   *DynOffsCache : Latch for offset averaged offset from various dynamic offset types  

  @glob_in         
					  - VDY_PAR_YW_Q_THRLD_SWA_UC : Quality threshold for uncalibrated steering wheel angle sensor
					  - VDY_PAR_YW_Q_THRLD_SWA_CAL : Quality threshold for calibrated steering wheel angle sensor
  @glob_out        None 

  @c_switch_part   None
  @c_switch_full   CFG_VDY_YW_DYN_AVG : Enable dynamic gyro offst compensation

  @pre             None
  @post            No changes
  @InOutCorrelation
					- Fusion of previously effective offset with interims Offset at high drift, since material reduction is not sufficient
  
  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_ywr.c -> NA
  @traceability			  - NA
**************************************************************************** */
STATIC_MTD void vdyYwrMergeOffsetDrift(VDYYwrOffsData_t *OffsData, VDYYwrDynOffsCache_t *DynOffsCache);


/* **********************************************************************
  @fn                     vdyYwrCalcDynOffsInterim */ /*!
  @brief           Dynamic offset for initialized steering angle status

  @description     Dynamic offset for initialized steering angle status

  @return          static void

  @param[in,out]   *DynOffsInter : Dynamic Yaw Rate-Interims-Offset for Initial state
  @param[in]       *Offs : Yaw RAte Offset Data
  @param[in]       dist : Distance

  @c_switch_part   None
  @c_switch_full   CFG_VDY_YW_DYN_AVG : Enable dynamic gyro offst compensation

  @pre             None
  @post            No changes
  @InOutCorrelation
					- Calculate Dyn. yaw rate interim offset
  
  @testmethod			  
	- Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_ywr.c -> NA
  @traceability		      
	- NA
**************************************************************************** */
STATIC_MTD void vdyYwrCalcDynOffsInterim(VDYYwrDynOffsInter_t *DynOffsInter, const VDYYwrOffsData_t *Offs, fDistance_t dist);
#endif

#if (CFG_VDY_EX_YWR_NVM)
	
/* **********************************************************************
  @fn                     vdyYwrEepromWriteYwOffset */ /*!
  @brief           Writes Yaw rate offset to EEprom

  @description    Writes Yaw rate offset to EEprom

  @return          static void

  @param[in]       *NVValue : Yaw rate EEPROM offset 
  @param[in]       *nvin : vdy nvm input data
  @param[in,out]   *nvout : vdy nvm output data

  @c_switch_part   None 
  @c_switch_full   CFG_VDY_EX_YWR_NVM : Enable offset storage  in nonvolatile memory

  @pre             None
  @post            No changes
  @InOutCorrelation
					  - Write Yaw offset into NVM in every excution cycle
  
  @testmethod			  
	- Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_ywr.c -> \n
                            TEST_vdyYwrEepromWriteYwOffset_001(),
                            TEST_vdyYwrEepromWriteYwOffset_002(), 
                            TEST_vdyYwrEepromWriteYwOffset_003(), 
                            TEST_vdyYwrEepromWriteYwOffset_004(), 
                            TEST_vdyYwrEepromWriteYwOffset_005()
  @traceability			  
	- NA
**************************************************************************** */
STATIC_MTD void vdyYwrEepromWriteYwOffset(const VDYYwrEepromOffset_t *NVValue, const VDYNvIoData_t *nvin, VDYNvIoData_t *nvout);


/* **********************************************************************
  @fn                     vdyYwrEepromReadYwOffset */ /*!
  @brief           Yaw Read rate offset from EEprom

  @description     Yaw Read rate offset from EEprom

  @return          static void

  @param[in,out]   *NVValue : Yaw rate EEPROM offset 
  @param[in]       *nvin : vdy nvm input data

  @c_switch_part   None 
  @c_switch_full   CFG_VDY_EX_YWR_NVM : Enable offset storage  in nonvolatile memory

  @pre             None
  @post            No changes
  @InOutCorrelation
					 - Read yaw rate offset from EEprom
  
  @testmethod			  
	- Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_ywr.c -> TEST_vdyYwrEepromReadYwOffset_001()
  @traceability			  
	- NA
**************************************************************************** */
STATIC_MTD void vdyYwrEepromReadYwOffset(VDYYwrEepromOffset_t *NVValue, const VDYNvIoData_t *nvin);


/* **********************************************************************
  @fn                     vdyYwrCalcEepromOffsetQuality */ /*!
  @brief           Computes the values of the EEPROM rotation rate offsets

  @description     Computes the values of the EEPROM rotation rate offsets

  @return          static void

  @param[in,out]   *pNvmOffs : Yaw rate standstill EEPROM offset  

  @c_switch_part   None 
  @c_switch_full   CFG_VDY_EX_YWR_NVM : Enable offset storage  in nonvolatile memory

  @pre             None
  @post            No changes
  @InOutCorrelation
					  - Compute the values of the EEPROM rotation rate offsets
					  - invNvmStatMax_c = 1.F / ((float32) YWR_NVM_STATUS_MAX);
					  - pNvmOffs->MaxQuality = ((float32)pNvmOffs->YawRateOffset.Status1 * invNvmStatMax_c);
					  - pNvmOffs->MaxQuality = MIN_FLOAT(1.F, pNvmOffs->MaxQuality);

  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_ywr.c -> NA
  @traceability			  - NA
**************************************************************************** */
STATIC_MTD void vdyYwrCalcEepromOffsetQuality(VDYYwrStandStillEepromOffs_t *pNvmOffs);


/* **********************************************************************
  @fn                     vdyYwrInitStandStillEepromOffset */ /*!
  @brief           Initializes Eeprom-Offset

  @description     Initializes Eeprom-Offset

  @return          static void

  @param[in,out]   *StandStEepromOffs : Yaw rate standstill EEPROM offset 

  @c_switch_part   None 
  @c_switch_full   CFG_VDY_EX_YWR_NVM : Enable offset storage  in nonvolatile memory

  @pre             None
  @post            No changes
  @InOutCorrelation
					- Initializes Eeprom-Offset
  
  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_ywr.c -> NA
  @traceability			  - NA
**************************************************************************** */
STATIC_MTD void vdyYwrInitStandStillEepromOffset(VDYYwrStandStillEepromOffs_t *StandStEepromOffs);

/* **********************************************************************
  @fn               vdyYwrSaveStandstillOffset */ /*!
  @brief           Save standstill offset to nonvolatile memory

  @description     Save standstill offset to nonvolatile memory

  @return          static void

  @param[in,out]   *OffsetData : Yaw Rate Offset Data

  @c_switch_part   None 
  @c_switch_full   CFG_VDY_EX_YWR_NVM : Enable offset storage  in nonvolatile memory

  @pre             None
  @post            No changes
  @InOutCorrelation
					- Get cycle time
					- If Required elapsed time since ignition start in dependence of prior write cycles greater than 0
						- YwTimeFirstWriteSec = YWR_NVM_OFFS_STABLE_TIME (Time after gyro offset is assumed to be stable for non-first writes)
						- else YwTimeFirstWriteSec = YWR_NVM_OFFS_STABLE_TIME_1ST (Time after gyro offset is assumed to be stable for first write)
					- If Prerequisite for storage of standstill offset in nonvolatile memory 
					- and Warmed-up gyro sensor (elapsed time since ignition start)
					- and Minimum quality of standstill offset
					- and Minimum standstill adjust time
					- and Maximum number of nvm write accesses not exceeded
					- and Time gap between successive write accesses 
					- or
					- and NVM offset state is 0 (no offset)
					- and The quality of the stand still offset should be good
					- and Store the offset 1 second after stand still
						- Determine filter gain
					- Filter standstill offset
					- Increment nvm yaw rate status
					- Store new values in non-volatile memory
					- Update nvm standstill offset quality
					- Reset time since last write access
					- Increment number of write accesses during this ignition cycle
  
  @testmethod			  
	- Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_ywr.c -> \n
                            TEST_vdyYwrSaveStandstillOffset_001(),
                            TEST_vdyYwrSaveStandstillOffset_002(),
                            TEST_vdyYwrSaveStandstillOffset_003(),
                            TEST_vdyYwrSaveStandstillOffset_004(),
                            TEST_vdyYwrSaveStandstillOffset_005(),
                            TEST_vdyYwrSaveStandstillOffset_006(),
                            TEST_vdyYwrSaveStandstillOffset_007(),
                            TEST_vdyYwrSaveStandstillOffset_008(),
                            TEST_vdyYwrSaveStandstillOffset_009(),
                            TEST_vdyYwrSaveStandstillOffset_010(),
                            TEST_vdyYwrSaveStandstillOffset_011()

  @traceability			  
	- NA
**************************************************************************** */
STATIC_MTD void vdyYwrSaveStandstillOffset(VDYYwrOffsData_t *OffsetData);

/* **********************************************************************
  @fn                     vdyYwrCalcEepromOffsetQualityTime */ /*!
  @brief           Calculates the current value of the EEPROM off-set
                   Over the elapsed time

  @description     Calculates the current value of the EEPROM off-set
                   Over the elapsed time

  @return          static void

  @param[in,out]   *OffsQuality : Yaw Rate Offset Quality
  @param[in]       MaxQuality : Yaw Rate Max Quality
  @param[in]       EcuElpsdTime : Time Since ECU Start in s

  @glob_in         YWR_GET_OFFS : Zero point offset
  @glob_out        None 

  @c_switch_part   CFG_VDY_YW_DYN_AVG : Enable dynamic gyro offset compensation
  @c_switch_full   CFG_VDY_EX_YWR_NVM : Enable offset storage  in nonvolatile memory

  @pre             None
  @post            No changes
  @InOutCorrelation
					  - Get yaw rate offset 
					  - Increase the Quality overtime
					  .
  
  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_ywr.c -> NA
  @traceability			  - NA
**************************************************************************** */
STATIC_MTD void vdyYwrCalcEepromOffsetQualityTime(fQuality_t *OffsQuality, fQuality_t MaxQuality, fTime_t EcuElpsdTime);
#else
/* **********************************************************************
Not Used
**************************************************************************** */
STATIC_MTD void vdyYwrCalcStandstillOffset(const VDYYwrSenData_t *YawRate, VDYYwrStandStillOffs_t *StandStillOffset);
#endif


/* **********************************************************************
  @fn                     vdyYwrGetPrivateData */ /*!
  @brief           Access to VDY YawRate Global Data

  @description     Access to VDY YawRate Global Data

  @return          VDYYwrData_t

  @glob_in         None 
  @glob_out        YWR_GET_ME : Yaw rate sensor data processing

  @c_switch_part   None 
  @c_switch_full   None 

  @pre             None
  @post            No changes
  @InOutCorrelation	
					- Return yaw rate sensor data
  
					@startuml
						start
							:return YWR_GET_ME;
						stop
					@enduml
  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_ywr.c -> TEST_vdyYwrGetPrivateData_001()
  @traceability			  - NA
**************************************************************************** */
VDYYwrData_t *vdyYwrGetPrivateData(void);


/* **********************************************************************
	Unit Design for vdyYwrExec is found in vdy.h
**************************************************************************** */
#if (CFG_VDY_MFC)
void vdyYwrExec(const reqVdyPrtList_t *reqPorts,const VDYInputData_t *input, VDYModIf_t *mif, const proVdyPrtList_t *proPorts, const float32 RawVelo)
#else
void vdyYwrExec(const reqVdyPrtList_t *reqPorts,const VDYInputData_t *input, VDYModIf_t *mif, const proVdyPrtList_t *proPorts)
#endif
{
  YWR_GET_ME->Io.in       = input;
  YWR_GET_ME->Io.nv_read  = reqPorts->pNVMRead;
  YWR_GET_ME->Io.nv_write = proPorts->pNVMWrite;
  YWR_GET_ME->Io.mif      = mif;

#if ( (defined(CFG_VDY_NVM_LEARN_DATA_ERROR)) && (CFG_VDY_NVM_LEARN_DATA_ERROR) )
  /* check for valid values written into NVM */
  YWR_GET_ME->Io.YwrNVMerrOffsRg  = &proPorts->pVDYErrors->OutPutErrors.YwrNVMOffsRg;
  proPorts->pVDYErrors->OutPutErrors.YwrNVMOffsRg   = VDY_ERR_STATE_UNKNOWN;
#endif


  /* Distinguish between different operating states */
#if (!CFG_VDY_MFC)
    if (VDY_CTRL_GET_STATE((VDYCtrlState_t)VDY_CTRL_STATE_RUNNING, input->Frame.CtrlMode))
#else
    if (VDY_CTRL_GET_STATE((BaseOpMode_t)BASE_OM_RUN, input->Frame.OpMode) )
#endif
  {
    /*<--- Execution path for normal operating mode --->*/
    VDYYwrSenData_t  *YawRateData      = YWR_GET_DATA;     /* General yaw rate data */
    VDYYwrOffsData_t *OffsData         = YWR_GET_OFFS;     /* Offset data */
    fYawRate_t       YawRateFilt       = VDY_ZERO_F;              /* Filtered yaw rate */

    /* Calculation of time variables which have to be calculated even if offset calculation is not done because input yaw rate is invalid */
    vdyYwrCalcRunnigTime();

#if (CFG_VDY_EX_YWR_NVM)
   #if( (!defined(CFG_VDY_SWA_AY_YAW_SSD_WLD_DIS_NVM_VALID_CHECK))||(!CFG_VDY_SWA_AY_YAW_SSD_WLD_DIS_NVM_VALID_CHECK)) 
    if (VDY_GET_NVM_IO_STATE(VDY_NVM_POS_YWR, &YWR_GET_NVM_READ->State)==VDY_IO_STATE_VALID)
   #endif
    {     
      vdyYwrEepromReadYwOffset(&OffsData->StandStillEepromOffset.YawRateOffset, YWR_GET_NVM_READ);
      vdyYwrCalcEepromOffsetQuality(&OffsData->StandStillEepromOffset);
    }
#endif

    /* <ln_offset:+2 PCLINT Error 845: reviewer name: Jochen Spruck date: 11-11-2010 reason: proven in use, error because of first state mask is zero */
    /* <ln_offset:+1 PCLINT Error 835: reviewer name: Jochen Spruck date: 11-11-2010 reason: proven in use, error because of first state mask is zero */
    if (VDY_GET_IO_STATE(VDY_SIN_POS_YWR, input->Signals.State)==(VDYIoStateTypes_t)VDY_IO_STATE_VALID)
    {
      YawRateData->YawRate = input->Signals.YawRate;
      YawRateData->Valid = (boolean)TRUE;
    }
    else
    {
      YawRateData->Valid = (boolean)FALSE;
    }
#if( (defined(CFG_VDY_SWA_AY_YAW_SSD_WLD_DIS_NVM_VALID_CHECK))&&(CFG_VDY_SWA_AY_YAW_SSD_WLD_DIS_NVM_VALID_CHECK))
	{
		/* PRQA S 1840, 1841, 4542 EOF */
		/* date: 2019-06-10, reviewer: Mahesh Patle (uidr0487), reason: Out of Scope of VDY */
	  VDY_SET_NVM_IO_STATE(VDY_NVM_POS_YWR, VDY_IO_STATE_INVALID, &proPorts->pNVMWrite->State);
	}
#endif
    /* doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-879-00026448 */
    if (YawRateData->Valid == (boolean)TRUE)
    {
      /* Calculate filtered yaw rate and yaw rate gradient */
      /* in case of first cycle, init old filt yaw rate with actual yaw rate */
      if (YawRateData->YwFirstCycleDone == (boolean)FALSE)
      {
        YawRateData->YawRateOld = YawRateData->YawRate;
      }

      YawRateFilt = vdyFilterCycleTime(YawRateData->YawRate, YawRateData->YawRateOld, VDY_PAR_YWR_YAWRATE_FT);
      YawRateData->Gradient = vdyCalcGradient(YawRateFilt, YawRateData->YawRateOld);
      YawRateData->YawRateOld = YawRateFilt;

      /* Check filtered yaw rate for high gradients over distance (only for dynamic offset calculation) */
      vdyCalcDistStblGrad(YWR_GRAD_DLT_DST_MAX, CML_f_Abs(YawRateData->Gradient), &YawRateData->GradientAbsOld, &YawRateData->DeltaDist, YWR_GET_MIF_DATA->LongMot.VehVelocityCorr);

      /* Offset calculation */
#if (CFG_VDY_MFC)
     vdyYwrCalcOffset(YawRateData,OffsData,input,proPorts,RawVelo);     
#else
      vdyYwrCalcOffset(YawRateData,OffsData,input,proPorts);       
#endif

#if (CFG_VDY_YW_DYN_AVG)
      /* Calculate mean value between effective and interims offset in case of drift */
      vdyYwrMergeOffsetDrift(OffsData, &OffsData->Cache);
#endif
   
#if( (defined(CFG_VDY_SWA_AY_YAW_SSD_WLD_DIS_NVM_VALID_CHECK))&&(CFG_VDY_SWA_AY_YAW_SSD_WLD_DIS_NVM_VALID_CHECK))
  {
	 VDYNvIoData_t *nvout = YWR_GET_NVM_WRITE;
     /* writing Yaw offset into NVM in every excution cycle */
     nvout->YwRate.ZeroRate = LastYawNvmData.ZeroRate;
     nvout->YwRate.CalStatus = LastYawNvmData.CalStatus;
     nvout->YwRate.ZeroRateMin = LastYawNvmData.ZeroRateMin;
     nvout->YwRate.ZeroRateMax = LastYawNvmData.ZeroRateMax;
  }
#endif
   

      /* First cycle done with valid yaw rate, filter are initialised now */
      YawRateData->YwFirstCycleDone = (boolean)TRUE;
    } 
    else
    {
#if( (defined(CFG_VDY_SWA_AY_YAW_SSD_WLD_DIS_NVM_VALID_CHECK))&&(CFG_VDY_SWA_AY_YAW_SSD_WLD_DIS_NVM_VALID_CHECK))
     VDYNvIoData_t *nvout = YWR_GET_NVM_WRITE;
     /* writing Yaw offset into NVM in every excution cycle */
     nvout->YwRate.ZeroRate = LastYawNvmData.ZeroRate;
     nvout->YwRate.CalStatus = LastYawNvmData.CalStatus;
     nvout->YwRate.ZeroRateMin = LastYawNvmData.ZeroRateMin;
     nvout->YwRate.ZeroRateMax = LastYawNvmData.ZeroRateMax;
#endif

      /* Yaw rate invalid */
      /* Initialise general yaw rate and standstill offset data to reset filter values and distance */
      vdyYwrInitYawRateData(YawRateData);
    }
  }
  else
  {
    /*<--- Execution path for initialization mode  --->*/
    vdyYwrCalcRunnigTime();
    vdyYwrCommonInit();
#if ( (defined(CFG_VDY_NVM_LEARN_DATA_ERROR)) && (CFG_VDY_NVM_LEARN_DATA_ERROR) )
    /* check for valid values written into NVM */
	YWR_GET_ME->Io.YwrNVMerrOffsRg = NULL;
#endif

  }
  
  /* Fill the autocode interface */
  vdyYwrCalcToAutocode(YWR_GET_OFFS);

  return;
}


/* **********************************************************************
	Unit Design for vdyYwrInit is found in vdy.h
**************************************************************************** */
/* PRQA S 3112 EOF */
/* date: Unknown, reviewer: Suggested TCI Code Review, reason: reqPorts and proPorts are added to remove compiler warning, they are not used in this configuration  " */

void vdyYwrInit(const reqVdyPrtList_t *reqPorts,const proVdyPrtList_t *proPorts)
{
  vdyYwrCommonInit();
  vdyYwrOffsetInit(reqPorts->pNVMRead);
#if ( (defined(CFG_VDY_TURNTABLE_DETECTION)) && (CFG_VDY_TURNTABLE_DETECTION) )
  PrevYawRateOffset = VDY_ZERO_F; 
#endif

#if( (defined(CFG_VDY_SWA_AY_YAW_SSD_WLD_DIS_NVM_VALID_CHECK))&&(CFG_VDY_SWA_AY_YAW_SSD_WLD_DIS_NVM_VALID_CHECK))
 {
  VDYIoState_t ioStateYaw;
  uint8 NAN_Err = 0;

  //NAN_Err |= (uint8)((boolean)(CML_f_Abs(reqPorts->pNVMRead->YwRate.ZeroRate) < VDY_PAR_YWR_OFFSET_LIMIT_MAX)== (boolean)FALSE );
  /* PRQA S 2986 EOF */
  /* date: 2019-06-10, reviewer: Mahesh Patle (uidr0487), reason: This is intended */
  NAN_Err |= ((CML_f_Abs(reqPorts->pNVMRead->YwRate.ZeroRate) < VDY_PAR_YWR_OFFSET_LIMIT_MAX) ? 0U : 1U);
  //NAN_Err |= (uint8)((boolean)(CML_f_Abs(reqPorts->pNVMRead->YwRate.ZeroRateMax) < VDY_PAR_YWR_OFFSET_LIMIT_MAX)== (boolean)FALSE );
  NAN_Err |= ((CML_f_Abs(reqPorts->pNVMRead->YwRate.ZeroRateMax) < VDY_PAR_YWR_OFFSET_LIMIT_MAX) ? 0U : 1U);
  //NAN_Err |= (uint8)((boolean)(CML_f_Abs(reqPorts->pNVMRead->YwRate.ZeroRateMin) < VDY_PAR_YWR_OFFSET_LIMIT_MAX)== (boolean)FALSE );
  NAN_Err |= ((CML_f_Abs(reqPorts->pNVMRead->YwRate.ZeroRateMin) < VDY_PAR_YWR_OFFSET_LIMIT_MAX) ? 0U : 1U);

  /* YAW offset writing in init mode */
 if((reqPorts->pNVMRead->State == NVM_CLEARED)
	|| (reqPorts->pNVMRead->YwRate.CalStatus >= YWR_NVM_OFFSET_STATUS_MAX)
	|| (NAN_Err == 1U))
 {
  LastYawNvmData.ZeroRate       = VDY_ZERO_F;
  LastYawNvmData.CalStatus       = VDY_ZERO_U;
  LastYawNvmData.ZeroRateMax       = VDY_ZERO_F;
  LastYawNvmData.ZeroRateMin       = VDY_ZERO_F;

  proPorts->pNVMWrite->YwRate.ZeroRate = VDY_ZERO_F;
  proPorts->pNVMWrite->YwRate.CalStatus = VDY_ZERO_U;
  proPorts->pNVMWrite->YwRate.ZeroRateMax = VDY_ZERO_F;
  proPorts->pNVMWrite->YwRate.ZeroRateMin = VDY_ZERO_F;
 }
 else
 {
  LastYawNvmData.ZeroRate       = reqPorts->pNVMRead->YwRate.ZeroRate;
  LastYawNvmData.CalStatus       = reqPorts->pNVMRead->YwRate.CalStatus;
  LastYawNvmData.ZeroRateMax       = reqPorts->pNVMRead->YwRate.ZeroRateMax;
  LastYawNvmData.ZeroRateMin       = reqPorts->pNVMRead->YwRate.ZeroRateMin;

  proPorts->pNVMWrite->YwRate.ZeroRate = reqPorts->pNVMRead->YwRate.ZeroRate;
  proPorts->pNVMWrite->YwRate.CalStatus = reqPorts->pNVMRead->YwRate.CalStatus;
  proPorts->pNVMWrite->YwRate.ZeroRateMax = reqPorts->pNVMRead->YwRate.ZeroRateMax;
  proPorts->pNVMWrite->YwRate.ZeroRateMin = reqPorts->pNVMRead->YwRate.ZeroRateMin;

  ioStateYaw = VDY_GET_NVM_IO_STATE(VDY_NVM_POS_YWR, &reqPorts->pNVMRead->State);
  VDY_SET_NVM_IO_STATE(VDY_NVM_POS_YWR, ioStateYaw, &proPorts->pNVMWrite->State);
 }
 }

#else

(void)proPorts;  /* remove compiler warning, proPorts is not used in this configuration */

#endif


return;
}

#if ( (defined(CFG_VDY_NVM_LEARN_DATA_ERROR)) && (CFG_VDY_NVM_LEARN_DATA_ERROR) )
/* **********************************************************************
	Unit Design for vdyYwrOffsetRangeOk is found in Declaration Section
**************************************************************************** */
STATIC_MTD boolean vdyYwrOffsetRangeOk(fYawRate_t Offset)
{
  boolean   YwrOffsOk      = (boolean)FALSE; 

  /* check the offset range */
  if (fABS(Offset) <= VDY_PAR_YWR_OFFSET_LIMIT_MAX)
  {
    /* offset within range  */
    YwrOffsOk = (boolean)TRUE;
  } 
  else
  {
    /* offset outside of range */
    YwrOffsOk = (boolean)FALSE;
  }

  return (YwrOffsOk);
}

#endif


/* **********************************************************************
	Unit Design for vdyYwrCalcToAutocode is found in Declaration Section
**************************************************************************** */
STATIC_MTD void vdyYwrCalcToAutocode(VDYYwrOffsData_t *Offs)
{
    Offs->ToAutocode.OffsData.quality = VDY_ONE_FIFTY_CENT;
    Offs->ToAutocode.OffsData.var    = VDY_ONE_NE_NINE;

    /* Detection of yaw rate offset changes */
#if (CFG_VDY_EX_YWR_NVM)
    if (   ( (Offs->OffsElpsdTime < VDY_ONE_F) && (Offs->OffsType == (VDYYwrOffsType_t) OFFS_STANDST) )
        || ( (Offs->OffsType==(VDYYwrOffsType_t) OFFS_TEMPER_TABLE) || (Offs->OffsType==(VDYYwrOffsType_t) OFFS_DYN_APPRX)  || (Offs->OffsType==(VDYYwrOffsType_t) OFFS_STANDST_EEPROM) )
        || (( YWR_GET_MIF_DATA->FirstCycleDone == (boolean)FALSE ) && (Offs->OffsType != (VDYYwrOffsType_t) OFFS_NON)) )
																 /* offset is checked for learning for first cycle AT363159 */
#else
    if (   ((Offs->OffsElpsdTime < (fTime_t) 1.0F) && (Offs->OffsType == (VDYYwrOffsType_t) OFFS_STANDST) )
        || ( (Offs->OffsType==(VDYYwrOffsType_t) OFFS_TEMPER_TABLE) || (Offs->OffsType==(VDYYwrOffsType_t) OFFS_DYN_APPRX) )
        || (( YWR_GET_MIF_DATA->FirstCycleDone == FALSE ) && (Offs->OffsType != (VDYYwrOffsType_t) OFFS_NON)) )
																 /* offset is checked for learning for first cycle AT363159 */
#endif
    {
      /* new offset was taken */
      /* set state */
#if (CFG_VDY_EX_YWR_NVM)
      if (Offs->OffsType == (VDYYwrOffsType_t) OFFS_STANDST_EEPROM)
      {
        /* state 2 = EEPROM offset */
        Offs->ToAutocode.OffsData.state = VDY_YAWRATE_STATE_NVM;
      }
      else
#endif
      {
        /* state = 1 -> set dynamic offset to stand still offset */
        Offs->ToAutocode.OffsData.state = VDY_YAWRATE_STATE_STANDSTILL;
      }
      Offs->ToAutocode.OffsData.offset = Offs->YawRateOffset;
    }
    else
    {
      if (Offs->OffsType == (VDYYwrOffsType_t) OFFS_NON)
      {
        /* state = 3 -> yaw stand still offset never ever estimated */
        Offs->ToAutocode.OffsData.offset = VDY_ZERO_F;
        Offs->ToAutocode.OffsData.state = VDY_YAWRATE_STATE_NOT_ESTIMATED;
      }
      else
      {
        Offs->ToAutocode.OffsData.state = VDY_ZERO_U;
      }
    }

    /* Check if the offset is a dynamic offset and set the dynamic flag */
    if  ((Offs->OffsType!=(VDYYwrOffsType_t) OFFS_DYN_INTER ) && (Offs->OffsType!=(VDYYwrOffsType_t) OFFS_DYN_AVG))
    {
      Offs->ToAutocode.IsDynamic = (boolean)FALSE;
    }
    else
    {
      Offs->ToAutocode.IsDynamic = (boolean)TRUE;
    }
}


#if (CFG_VDY_YW_DYN_AVG)
/* **********************************************************************
	Unit Design for vdyYwrCalcDynOffsAvg is found in Declaration Section
**************************************************************************** */
STATIC_MTD float32 vdyYwrCalcDynOffsAvg(const VDYYwrSenData_t *YawRateData, VDYYwrDynOffsAvg_t *DynOffset, const VDYYwrOffsData_t *Offs)
{
  /*--- FUNKTIONSLOKALE KONSTANTEN ---*/

  /* Mittelwert Filter-Konstanten. Filterung ueber Weg d. h. TS = 1sec enspricht 40 m */
  
  /* IIR-Tiefpass-Filterkonstanten Mittlerwert-Filter (Butterworth) */
  static const VDY_IIR2Coeff_t yw1s_c =    /* FC = 0.0007 Hz, FS = 1.0 Hz */
  {
    {1.0F * 0.48211046862777198e-5F,  1.000000000000000F },  /* num0, den0 */
    {2.0F * 0.48211046862777198e-5F, -1.993779983847134F },  /* num1, den1 */
    {1.0F * 0.48211046862777198e-5F,  0.993799268265879F },  /* num2, den2 */
  };

  /* IIR-Tiefpass-Filterkonstanten Detektion-Filter (Chebyshev Type II) */
  static const VDY_IIR2Coeff_t yw2s_c =    /* FC = 0.07 Hz, FS = 1.0 Hz */
  {
    { 1.0000000000F*0.3262393735e-2F,  1.00000000000F },  /* num0, den0 */
    {-1.8089025526F*0.3262393735e-2F, -1.96443350097F },  /* num1, den1 */
    { 1.0000000000F*0.3262393735e-2F,  0.96505693608F },  /* num2, den2 */
  };

  /* IIR-Tiefpass-Filterkonstanten Iterim-Filter (Chebyshev Type II) */    
  static const VDY_IIR2Coeff_t yw3s_c =    /* FC = 0.05 Hz, FS = 1.0 Hz, Astop = 60 dB */
  {
    { 1.00000000000F*0.1039709422e-2F,  1.00000000000F}, /* num0, den0 */
    {-1.80890255282F*0.1039709422e-2F, -1.97997659247F}, /* num1, den1 */
    { 1.00000000000F*0.1039709422e-2F,  0.98017527828F}, /* num2, den2 */
  };

  enum {FIR_LENGTH=20};                                  /* Laenge des FIR-Vorfilters              */
  const fYawRate_t  YwRateMax_c      = DEG2RAD(10.F);    /* Max. Gierrate fuer Filterung           */
  const fDistance_t DistMax_c        = 15000.F;          /* Max. Distanz in m fuer Gueteberechnung */
  const fDistance_t DistThrdOvrMin_c = 3000.F;           /* Mindest-Distanz ueber Threshold        */
  const fDistance_t DistThrdMin_c    = 15000.F;          /* Mindest-Distanz ueber Threshold        */
  
  const float32       VehSpeedMin_c    = 30.F/C_KMH_MS;    /* Mindestgeschwindigkeit fuer Filterung  */
  const float32       CrvStPreMin_c    = 1.F/(500.F);      /* Grenzradius fuer Kurvenfahrt           */
  const fTime_t     OffsTime_c       = 0.2F;             /* Offset-Zeit-Schwelle zur Detektion neuer Offset */
  const fTime_t     OffsTimeStart_c  = 1.F;              /* Offset-Zeit-Schwelle zur Detektion neuer Offset waehrend Startup */
  const fYawRate_t  YwOffsetMax_c    = DEG2RAD(5.F);     /* Max. moeglicher Offsetwert             */
  
  /*--- FUNKTIONSLOKALE VARIABLEN ---*/

  /*---- static -----*/
  static float32 YwFiltBuf[FIR_LENGTH] =   /* Buffer fuer FIR-Vorfilter */
  {
    VDY_ZERO_F, VDY_ZERO_F, VDY_ZERO_F, VDY_ZERO_F, VDY_ZERO_F, VDY_ZERO_F, VDY_ZERO_F, VDY_ZERO_F, VDY_ZERO_F, VDY_ZERO_F,
    VDY_ZERO_F, VDY_ZERO_F, VDY_ZERO_F, VDY_ZERO_F, VDY_ZERO_F, VDY_ZERO_F, VDY_ZERO_F, VDY_ZERO_F, VDY_ZERO_F, VDY_ZERO_F,
  };

  /*---- non-static ----- */
  float32       filtYwRate     = VDY_ZERO_F;      /* Vorgefilterte Gierrate (dezimation) */
  fTime_t     CycleTime;                 /* Zykluszeit                          */
  float32       distRet        = VDY_ZERO_F;      /* Distanz die in Filterung eingeht als Rueckgabewert  */
  fVelocity_t VehicleSpeed;              /* Eigengeschwindigkeit korrigiert     */
  fTime_t     OffsTimeThrd;

  /* Lenkwinkel-Daten */
  const VDYOutCurve_t SwaCurve = {0.F, 0.F, 0.F}; 
  const VDYOutCurve_t WspCurve = {0.F, 0.F, 0.F}; 

  const VDYOutCurve_t *StrgTrack;    /* Lenkwinkel-Spur        */
  const VDYOutCurve_t *WspTrack;     /* Raddrehzahlen-Spur     */
  
  /* Zykluszeit holen */
  CycleTime = vdyGetCycleTime();

  /* Eigengeschwindikeit holen */
  VehicleSpeed = YWR_GET_MIF_DATA->LongMot.VehVelocityCorr;

  /* Referenzen fuer Lenkwinkelspur-Daten  initialisieren */
  StrgTrack = &SwaCurve;

  /* Raddrehzahl Spur */ 
  /* PRQA S 2983 EOF */
  /* date: 2019-06-10, reviewer: Mahesh Patle (uidr0487), reason: Fucntional Safe */
  WspTrack = &WspCurve;

  /* Bei erstem Zyklus FIR-Filter Zaehler und akkumulierte Distanz zuruecksetzen */
  if(YawRateData->YwFirstCycleDone == (boolean)FALSE)
  {
    DynOffset->cntCycle  = VDY_ZERO_U;
    DynOffset->accYwDist = VDY_ZERO_F;
  }
  
  /* Solange kein Filterwert gelernt ist, Qualitaet des Lenkwinkel aktualisieren */
  /* Hinweis: derzeit kein Lernen des Filterwerts, damit keine Abhaengigkeit vom Lenkwinkel und Rundkurserkennung deaktiviert */
  DynOffset->FlStwAStat = (boolean)FALSE; 

  /* --------------------------------------------------------------------------
   *  ZYKLUSZEIT BASIERTE VORVERARBEITUNG
   * ------------------------------------------------------------------------*/

  /* Mindestgeschwindigkeit pruefen */
  if ( VehicleSpeed > VehSpeedMin_c )
  {
    const fCurve_t     CurvMin_c     = 1.F/(1800.F);  /* Mindestkruemmung fuer Richtungsbestimmung */

    float32 drvDist;                                     /* Gefahrende Distanz pro Zyklus */
    VDYCrvDirStatus_t StrgStat;                        /* Richtung Links/Rechts aus LW-Kruemmung  */
    VDYCrvDirStatus_t WspStat;                         /* Richtung Links/Rechts aus RDZ-Kruemmung */

    /* Gefahrene Wegstrecke pro Zyklus */
    drvDist = (VehicleSpeed*CycleTime);

    /*------- STRECKENCHARAKTERISTIK BERECHNEN  ---------------------------------*/
    
    /*  Charakteristik mit ausreichendem LW-Status moeglich*/
	/* PRQA S 2992, 2996, 2880 EOF */
	/* date: 2019-06-10, reviewer: Mahesh Patle (uidr0487), reason: Fucntional Safe */
    if (DynOffset->FlStwAStat != (boolean)FALSE)
    {
      const fQuality_t QMinWspCrv_c  = 0.3F;              /* Mindestqualitaet WSP Kruemmung    */
      const fQuality_t QMinStwCrv_c  = 0.4F;              /* Mindestqualitaet STW Kruemmung    */

      /* Streckencharakteristik ueber Lenkwinkel oder Raddrehzahl-Spur bestimmen */
      WspStat  =  vdyGetCurveDir(WspTrack,  CurvMin_c, QMinWspCrv_c);
      StrgStat =  vdyGetCurveDir(StrgTrack, CurvMin_c, QMinStwCrv_c);

      /* Kurve links */
      if ((StrgStat== (VDYCrvDirStatus_t) CRV_DIR_LEFT) || (WspStat== (VDYCrvDirStatus_t) CRV_DIR_LEFT))
      {
        DynOffset->StDrv -= drvDist;
      }

      /* Kurve rechts */
      if((StrgStat== (VDYCrvDirStatus_t) CRV_DIR_RIGHT) || (WspStat== (VDYCrvDirStatus_t) CRV_DIR_RIGHT) )
      {
        DynOffset->StDrv += drvDist;
      }

      /* Kursrichtung kann nicht bestimmt werden */
      if ((WspStat== (VDYCrvDirStatus_t) CRV_DIR_DONT_KNOW) && (StrgStat== (VDYCrvDirStatus_t) CRV_DIR_DONT_KNOW))
      {
        DynOffset->StDrv = VDY_ZERO_F;
      }
    }
    else
    {
      DynOffset->StDrv = VDY_ZERO_F;
    }
   
    /*------- VORFILTERUNG DER GIERRATE ----------------------------------------*/
    
    /* Bei vorhandenem Lenkradwinkel-Offset ausreichender Guete Grenzradius pruefen */
	/* PRQA S 2991, 2992, 2995 EOF */
	/* date: 2019-06-10, reviewer: Mahesh Patle (uidr0487), reason: Fucntional Safe */
    if( (CML_f_Abs(StrgTrack->Curve) < CrvStPreMin_c) || (!(DynOffset->FlStwAStat!=(boolean)FALSE)) )
    {
      uint32 ii;

      /* Gleitende Mittelwertbildung der Gierrate als Vorfilterung */
      if ( (CML_f_Abs(YawRateData->YawRate)<YwRateMax_c) && (YawRateData->Valid!=(boolean)FALSE) )
      {
        /* Weg aufintegrieren */
        DynOffset->accYwDist += drvDist;

        /* Filterspeicherwerte nach rechts schieben */
        for (ii = ((uint32)FIR_LENGTH - 1U); ii > 0U ; ii--)
        {
          YwFiltBuf[ii] = YwFiltBuf[ii-1U];
        }

        /* Eingangswert einlesen */
        YwFiltBuf[0] = YawRateData->YawRate;

        /* Gleitenden Mittelwert berechnen */
        for (ii = 0U; ii < (uint32)FIR_LENGTH; ii++)
        {
          filtYwRate += YwFiltBuf[ii];
        }
        filtYwRate *= VDY_ONE_F/(float32)FIR_LENGTH;

        if (DynOffset->cntCycle<(uint32)FIR_LENGTH)
        {
          DynOffset->cntCycle++;
        }
      }

      /*------- STRECKENCHARAKTERISTIK ALTERN  ---------------------------------*/
      /* Alterung erst ab einer Mindestdistanz und Mindestlenkwinkel-Status */
      if ( (DynOffset->FlStwAStat!=(boolean)FALSE) && (DynOffset->YwDist >= DistMax_c) )
      {
        const float32 StDrvAgingThrd_c   = 4000.F;   /* Schwelle ab der Streckensymmertrie gealtert wird */
        const fDistance_t DistRedMin_c  = 10000.F;  /* Mindestdistanz zur Symmertrie-Alterung           */
        
        /* Allgemein gefahrende Wegstrecke */
        DynOffset->DrvDistRed += drvDist;
        
        if ( (CML_f_Abs(DynOffset->StDrv) > StDrvAgingThrd_c) && (DynOffset->DrvDistRed > DistRedMin_c) )
        {
          const fDistance_t StrDrvRed_c = 500.F;      /*  Granularitaet der Reduzierung */
        
          if (DynOffset->StDrv > StrDrvRed_c)
          {
            DynOffset->StDrv -= StrDrvRed_c;         /* Oberhalb positiver Grenze  */
          }
          else if (DynOffset->StDrv < -StrDrvRed_c)
          {
            DynOffset->StDrv += StrDrvRed_c;         /* Unterhalb negativer Grenze */
          }
          else
          {
            DynOffset->StDrv = VDY_ZERO_F;       /* Innerhalb oberer und unterer Grenze */
          }
          DynOffset->DrvDistRed = VDY_ZERO_F;    /* Bei erfolgter Reduzierung Distanz zuruecksetzen */
        }
        else
        {
          const fDistance_t DistRedMax_c  = 15000.F;  /* Maximaldistanz zur Symmertrie-Alterung           */

          /* Gefahrene Distanz zum reduzieren der Asymmertrie begrenzen */
          DynOffset->DrvDistRed = MIN_FLOAT(DynOffset->DrvDistRed,DistRedMax_c);
        }
      }
      else
      {
        DynOffset->DrvDistRed = VDY_ZERO_F;      /* Reduzierung erst aktiv, wenn max. Distanz erreicht */
      }
    }
  }

  
  /* --------------------------------------------------------------------------
   *  DISTANZ BASIERTE VERARBEITUNG
   * ------------------------------------------------------------------------*/

  /* Langzeitmittelung fuer Gierrate ueber gefahrenem Weg ausfuehren ds = 40 m */
  if ( (DynOffset->cntCycle >= (uint32)FIR_LENGTH) && (DynOffset->accYwDist > YWR_DYNA_DIST_STEP) )
  {
    /*------- DISTANZ-FILTERUNG  ---------------------------------*/
    
    /* Filter nur aufrufen, wenn vorgefilterte Gierrate innerhalb der Grenzen */
    if (CML_f_Abs(filtYwRate)<YwRateMax_c)
    {
      /* <ln_offset:+1 PCLINT Error 717: reviewer name: Jochen Spruck date: 11-11-2010 reason: proven in use */
      VDY_IIR_FILTER2(filtYwRate,DynOffset->YawRateOffset,yw1s_c,DynOffset->YwFilt);     /* Abgleichfilter   */
      /* <ln_offset:+1 PCLINT Error 717: reviewer name: Jochen Spruck date: 11-11-2010 reason: proven in use */
      VDY_IIR_FILTER2(filtYwRate,DynOffset->YawRateDet,   yw2s_c,DynOffset->YwFiltDet);  /* Detektionsfilter */

      /* Interimsfilter  */
      /* <ln_offset:+1 PCLINT Error 717: reviewer name: Jochen Spruck date: 11-11-2010 reason: proven in use */
      VDY_IIR_FILTER2(filtYwRate,DynOffset->IntOffs.YawRateOffset,yw3s_c,DynOffset->IntOffs.YwFiltInt);

      DynOffset->YwDist    += DynOffset->accYwDist;
      DynOffset->YwDist     = MIN_FLOAT(DistMax_c,DynOffset->YwDist);  /*  Aufintegrieren mit Saettigung */
    }
    else
    {
      DynOffset->YwDist    -= DynOffset->accYwDist;
      DynOffset->YwDist     = MAX_FLOAT(VDY_ZERO_F,DynOffset->YwDist);       /* Abintegrieren mit Saettigung */
    }

    /*------- UEBERNAHME SCHWELLE AKTUALISIEREN ------------------------*/
    
    /* Ueberschreiten der Schwelle zur Aktivierung von diesem Offset-Typ 
       muss fuer eine bestimmte Wegstrecke erfuellt sein */
    if (DynOffset->YwDist >= DistThrdMin_c)
    {
      const float32 YwOffsThrFirst_c = DEG2RAD(0.37F);   /* Schwelle fuer erstmalige Uebernahme */
      const float32 YwOffsThrCons_c  = DEG2RAD(0.1F);    /* Schwelle fuer Folge-Uebernahmen     */

      /* Wenn dynamischer Offsettyp noch nicht aktiv ist, zusaetzliche Threshold-
         Bedingung fuer erstmalige Uebernahme aktiv */
      if ( (Offs->OffsType!=(VDYYwrOffsType_t) OFFS_DYN_AVG) && (Offs->OffsType!=(VDYYwrOffsType_t) OFFS_DYN_INTER) )
      {
        if (CML_f_Abs(Offs->YawRateOffset-DynOffset->YawRateOffset)>YwOffsThrFirst_c)
        {
          DynOffset->YwDrvDistThr += DynOffset->accYwDist;  /* Inkrementieren  */      
        }
        else
        {
          /* Dekrementieren bis auf Null */
          DynOffset->YwDrvDistThr = MAX_FLOAT(VDY_ZERO_F,DynOffset->YwDrvDistThr - DynOffset->accYwDist);
        }
      }
      else
      {
        /* Dynamischer Average oder Interims-Offset bereits wirksam */
        const float32 DistThrdOvr_c = DistThrdOvrMin_c + 1.0F;  /* Wert ueber Schwelle setzen */
        
        /* Bei Folgeabgleich Schwellenbedingung deaktivieren */
        if (CML_f_Abs(Offs->YawRateOffset-DynOffset->YawRateOffset) >= YwOffsThrCons_c)
        {
          DynOffset->YwDrvDistThr = DistThrdOvr_c;  /* Bei Folgeuebernahmen Bedingung auf TRUE */
        }
      }
    }
    else
    {
      /* Eingriffschwelle zuruecksetzen, wenn gefahrene Distanz zu gering */
      DynOffset->YwDrvDistThr = VDY_ZERO_F;
    }
    distRet  = DynOffset->accYwDist;  /* Distanz-Schritt als Rueckgabe-Wert speichern      */
    DynOffset->accYwDist = VDY_ZERO_F;       /* Distanz-Akummulation des Vorfilters zuruecksetzen */
  }
  else
  {
    distRet = VDY_ZERO_F;
  }


  /* --------------------------------------------------------------------------
   *  RUECKSETZ-BEDINGUNGEN 
   * ------------------------------------------------------------------------*/
  
  /*------- RUECKSETZEN WEGEN STRECKEN-UNSYMMETRIE (RUNDKURS) ---------------*/
  
  /* Streckencharakteristik ueber Lenkwinkel plausibilisieren */
  if (CML_f_Abs(DynOffset->StDrv) > YWR_STDIST_SYMM_RESET )
  {
    /* Wenn dynamischer Offset wirksam, Abgleichfilter nicht komplett zuruecksetzen */
    if (Offs->OffsType == (VDYYwrOffsType_t) OFFS_DYN_AVG)
    {
      DynOffset->YwDist         = MIN_FLOAT(DistMax_c / VDY_TWO_F, DynOffset->YwDist);
      DynOffset->MaxQuality     = VDY_ZERO_F;
      DynOffset->StDrv          = VDY_ZERO_F;
      DynOffset->YwDrvDistThr   = VDY_ZERO_F;
      DynOffset->DrvDistRed     = VDY_ZERO_F;
    }
    else
    {
      /* Re-initialize Offset Data */ 
      vdyYwrInitDynOffsAvg(DynOffset);
      vdyYwrInitDynOffsInterim(&DynOffset->IntOffs);
    }
  }

  /*------- RUECKSETZEN WEGEN ANDERER YAWRATE OFFSET-TYPEN ------------------*/

  /* Waehrend der Startup-Phase erhoehte Zeitschwelle notwendig, um Offset-Uebernahme zu detektieren */
  if (Offs->EcuElpsdTime < OffsTimeStart_c)
  {
    OffsTimeThrd = OffsTimeStart_c;
  }
  else
  {
    /* Im Falle einer ungueltigen Drehrate ist Offsetberechnung nicht aktiv, daher muss die Zeitschwelle
       entsprechend erhoeht werden, um einen Offsetwechsel noch ueber die Offsetzeit noch erkennen zu 
       koennen */
    OffsTimeThrd = OffsTime_c + (Offs->EcuElpsdTime - DynOffset->LastEcuTime);
  }

  /* Momentane ECU-Time speichern fuer naechsten Zyklus */
  DynOffset->LastEcuTime = Offs->EcuElpsdTime;
  
  /* Bei erfolgreichem Offset Abgleich anderen Typs und zu grossem Offsetwert Filter neu initialisieren */
  
  /* Zur Erkennung wird die Offsetdauer des wirksamen Offsets oder CycleDone verwendet */
  if (    (CML_f_Abs(DynOffset->YawRateOffset) > YwOffsetMax_c)                  /* Gelernter Offsetwert (absolut) plausibilisieren */
       || (    (Offs->OffsElpsdTime < OffsTimeThrd)  
            && (    (Offs->OffsType == (VDYYwrOffsType_t) OFFS_STANDST)          /* Ablgeich ueber Stillstand  */
#if (CFG_VDY_EX_YWR_NVM)
                 || (Offs->OffsType == (VDYYwrOffsType_t) OFFS_STANDST_EEPROM)   /* EEPROM                     */
#endif
                )  )  )
  {
    /* Dyn. Average Offset reinitialisieren */
    vdyYwrInitDynOffsAvg(DynOffset);
  
    /* Interims-Offset initialisieren */
    vdyYwrInitDynOffsInterim(&DynOffset->IntOffs);  
  }

  
  /*------- TEILRUECKSETZEN BEI UEBERNAHME VON DYN. AVERAGE OFFSET ----------*/
  
  /* Bei Uebernahme eines wirksamen Offsets Uebernahme-Schwelle zuruecksetzen 
     um sofortige Folgeuebernahmen zu vermeiden */
  if ((Offs->OffsElpsdTime < OffsTime_c) && (Offs->OffsType!=(VDYYwrOffsType_t) OFFS_DYN_INTER))
  {
    DynOffset->YwDrvDistThr = VDY_ZERO_F;  
    DynOffset->StDrv        = VDY_ZERO_F;  /* Verhinderung von Ruecksetzen kurz nach Folge-Uebernahme */
  }
  
  /* --------------------------------------------------------------------------
   *  QUALITAET(=KRITERIUM FUER OFFSETUEBERNAHME) BERECHNEN
   * ------------------------------------------------------------------------*/

  /* Guete in Abhaengigkeit von gefahrene Distanz ueber Einschreitschwelle 
     und Lenkwinkel-Spur Charakteristik (wenn vorhanden, ansonsten null) */
  DynOffset->MaxQuality = VDY_ZERO_F;  /* Defaultwert initialisieren */
  
  if ((DynOffset->YwDist >= DistMax_c) && (DynOffset->YwDrvDistThr > DistThrdOvrMin_c))
  {
    /* Bei aktivem Interims-Offset nur Ableich im Normal-Zustand und kleiner Abweichung  */
    if ( (Offs->OffsType!=(VDYYwrOffsType_t) OFFS_DYN_INTER) && (DynOffset->FlStwAStat!=(boolean)FALSE) )
    {
      /* Guete bei vorhandener Streckencharakteristik (Reduzierung ueber Unsymmetrie) bewerten */
      DynOffset->MaxQuality = vdyLFunction(CML_f_Abs(DynOffset->StDrv),
                                 YWR_DIST_DYNAVGOFF_MIN, YWR_DIST_DYNAVGOFF_MAX,
                                 YWR_QUALITY_DYNAVGOFF_MAX,YWR_QUALITY_DYNAVGOFF_MIN);
    }
    else
    {
      if ( (CML_f_Abs(DynOffset->YawRateOffset-DynOffset->IntOffs.YawRateOffset) < DEG2RAD(VDY_THIRTY_CENT)) && (Offs->OffsType==(VDYYwrOffsType_t) OFFS_DYN_INTER) )
      {
      /* Im Initialzustand soll durch diesen Filter die langsame Drifts kompensiert werden, 
         was durch die Ungenauigkeiten des Interimsfilter nicht moeglich ist */
        DynOffset->MaxQuality = VDY_ONE_F;
      }
    }
  }
  return distRet;
}


/* **********************************************************************
	Unit Design for vdyYwrCalcDynOffsInterim is found in Declaration Section
**************************************************************************** */
STATIC_MTD void vdyYwrCalcDynOffsInterim(VDYYwrDynOffsInter_t *DynOffsInter, const VDYYwrOffsData_t *Offs, fDistance_t dist)
{
  /* Pruefen, ob Filterung ueber zurueckgelegtem Weg aktualisiert worden ist d. h.
     Abgleich- und Detektionsfilter wurde aktualisiert */
  if (dist > VDY_ZERO_F)
  {
    /* Defaultwert initialisieren */
    DynOffsInter->MaxQuality = VDY_ZERO_F;

    /* Abgleich nur moeglich wenn Lenkwinkel-Offset unzureichend gelernt und Mindestdistanz gefahren  */
    if ((Offs->DynOffsAvg.FlStwAStat == (boolean)FALSE) && (Offs->DynOffsAvg.YwDist > VDY_YWR_DYN_OFFSET_MIN_DIST))
    {
      const fYawRate_t diffMaxDetInter_c = DEG2RAD(0.7F); /* Maximal-Differenz Detektionsfilter- und Interimsfilter */
      boolean preCond; /* Vorbedingung */
      fYawRate_t  diffIntCurr;

      diffIntCurr = CML_f_Abs(Offs->DynOffsAvg.IntOffs.YawRateOffset - Offs->YawRateOffset);

      /* Aussummieren der Strecke mit Abweichung ueber Schwelle */
      if (diffIntCurr > DEG2RAD(VDY_FIFTY_CENT))
      {
        DynOffsInter->DistThrd += dist;
      }
      else
      {
        /* Dekrementieren bis auf Null */
        DynOffsInter->DistThrd = MAX_FLOAT(VDY_ZERO_F,DynOffsInter->DistThrd-dist);
      }
    
      /* Abgleichbedingungen in Abhaengigkeit des momentan wirksamen Offsets pruefen */
      if (Offs->OffsType!=(VDYYwrOffsType_t) OFFS_DYN_INTER)
      {
        const fYawRate_t diffAvgCurr_c = DEG2RAD(0.2F);  /* Mindest-Differenz Mittelwert zu wirksamen Offset   */
        const fYawRate_t diffIntCurr_c = DEG2RAD(0.4F);  /* Mindest-Differenz Interimswert zu wirksamen Offset */

        float32 diffAvgCurr;
        boolean b_diffSignEqual;

        diffAvgCurr = CML_f_Abs(Offs->DynOffsAvg.YawRateOffset         - Offs->YawRateOffset);
        diffIntCurr = CML_f_Abs(Offs->DynOffsAvg.IntOffs.YawRateOffset - Offs->YawRateOffset);

        if (    ((diffAvgCurr > VDY_ZERO_F) && (diffIntCurr > VDY_ZERO_F))
             || ((diffAvgCurr < VDY_ZERO_F) && (diffIntCurr < VDY_ZERO_F))  )
        {
          b_diffSignEqual = (boolean)TRUE;
        }
        else
        {
          b_diffSignEqual = (boolean)FALSE;
        }

        preCond = (boolean)((    (DynOffsInter->DistThrd > VDY_YWR_DYN_OFFSET_MIN_DIST)
                             && (diffAvgCurr > diffAvgCurr_c) 
                             && (diffIntCurr > diffIntCurr_c) 
                             && (b_diffSignEqual == (boolean)TRUE) ) ? TRUE : FALSE);
        /* <ln_offset:-1 MISRA Rule 10.3: reviewer name: Jochen Spruck date: 27-09-2010 reason: proven in use */
      }
      else
      {
        /* Folgeuebernahmen mit nicht so strengen Kriterien um Drift besser zu folgen */
        float32 f_OffsetDiffMinInterAbs;
        float32 f_OffsetDiffAvgDetAbs;

        const fYawRate_t diffMinInter_c  = DEG2RAD(0.2F);   /* Mindest-Differenz Interims-Filter */
        const fYawRate_t diffMinAvgDet_c = DEG2RAD(0.3F);   /* Mindest-Differenz zwischen Mittelwert- und Detektionsfilter 
                                                               fuer thermisch eingeschwungenen Zustand */
        f_OffsetDiffMinInterAbs = CML_f_Abs(Offs->YawRateOffset - DynOffsInter->YawRateOffset);
        f_OffsetDiffAvgDetAbs = CML_f_Abs(Offs->DynOffsAvg.YawRateDet - Offs->DynOffsAvg.YawRateOffset);

        preCond = (boolean) ((   (f_OffsetDiffMinInterAbs > diffMinInter_c)
                             && (f_OffsetDiffAvgDetAbs > diffMinAvgDet_c)  ) ? TRUE : FALSE);
        /* <ln_offset:-1 MISRA Rule 10.3: reviewer name: Jochen Spruck date: 27-09-2010 reason: proven in use */
      }

      if ( (CML_f_Abs(Offs->DynOffsAvg.YawRateDet-DynOffsInter->YawRateOffset) < diffMaxDetInter_c) && (preCond == (boolean)TRUE) )
      {
        /* Abgleich aktivieren */
        DynOffsInter->MaxQuality = VDY_ONE_F;      
      }
    }
  }
  return;
}


/* **********************************************************************
	Unit Design for vdyYwrCalcQRedRamp is found in Declaration Section
**************************************************************************** */
STATIC_MTD float32 vdyYwrCalcQRedRamp(const VDYYwrOffsData_t *OffsData)
{
  float32 retRamp;

  /* Differenz zur Steuerung des Grades der Guetereduzierung */
  fYawRate_t diffYw = CML_f_Abs(OffsData->DynOffsAvg.YawRateDet - OffsData->YawRateOffset);
      
  /* Zweistufige Rampe zur Guetereduzierung */
  if (diffYw < YWR_OFFSET_DELTA_MED)
  {
    retRamp = vdyLFunction(diffYw, YWR_OFFSET_DELTA_MIN,YWR_OFFSET_DELTA_MED, 
                                   YWR_Q_FACTOR_DELTA_MAX,YWR_Q_FACTOR_DELTA_MED);
  }
  else
  {
    retRamp = vdyLFunction(diffYw, YWR_OFFSET_DELTA_MED,YWR_OFFSET_DELTA_MAX,
                                   YWR_Q_FACTOR_DELTA_MED,YWR_Q_FACTOR_DELTA_MIN);
  }
  return retRamp;
}


/* **********************************************************************
	Unit Design for vdyYwrMergeOffsetDrift is found in Declaration Section
**************************************************************************** */
STATIC_MTD void vdyYwrMergeOffsetDrift(VDYYwrOffsData_t *OffsData, VDYYwrDynOffsCache_t *DynOffsCache)
{
  fQuality_t qRed;
  fQuality_t qRedMax;

  /* Cache mit momentan wirksamen Offset initialisieren */
  DynOffsCache->YawRateOffset = OffsData->YawRateOffset;

  /* Moegliche Guete-Reduzierung berechnen */
  qRed = vdyYwrCalcQRedRamp(OffsData);

  /* Unterscheidung zwischen gelerntem Zustand und Initialzustand */  
  if (   (OffsData->DynOffsAvg.QReduce >= VDY_ONE_F)                   /* Guete-Reduzierung ist nicht aktiv  */
      && (qRed < VDY_ONE_F)                                            /* Guete wuerde bei ausreichend LW,WSP Qualitaet reduziert */
      && (OffsData->DynOffsAvg.YwDist > YWR_DYNC_QRED_DIST_MIN) ) /* Staerkere Wirkung erst zulassen, wenn Filter eingeschwungen */
  {
    /* max. Wirkung des Offsets zulassen */
    qRedMax  = VDY_PAR_YW_Q_THRLD_SWA_UC;   /* mind. Qualitaet fuer Gesamt-Gewichtung */
  }
  else
  {
    qRedMax  = VDY_PAR_YW_Q_THRLD_SWA_CAL;
  }

  /* Qualitaet berechnen auf Mindestniveau halten, damit Cache-Offset wirksam werden kann */  
  DynOffsCache->Quality = MAX_FLOAT(qRed,qRedMax);
  
  /* Reduzierung des Einflusses des Offsets bei Verdacht auf Rundkurs */
  DynOffsCache->Quality *= vdyLFunction(CML_f_Abs(OffsData->DynOffsAvg.StDrv), YWR_DYNC_STSYM_START, YWR_DYNC_STSYM_END, YWR_DYNC_Q_PERM_MAX, YWR_DANC_Q_PERM_MIN);

  /* Bedingungen fuer das teilweise Einblenden des Interims-Offset ohne Abgleich */
  if ( (qRed < qRedMax) && (OffsData->OffsType!=(VDYYwrOffsType_t) OFFS_DYN_INTER) )
  {
  
    /* Anpassen der Qualitaet des wirksamen Offset, damit Ueberlagerung wirksam wird */
    OffsData->Quality = OffsData->QualNoRed * DynOffsCache->Quality;

    /* Differenz zwischen wirksamen und Interims-Offset gewichtet ueberlagern */
    DynOffsCache->YawRateOffset  += (OffsData->DynOffsAvg.IntOffs.YawRateOffset - OffsData->YawRateOffset) * (VDY_ONE_F - qRed);
  }
  return;
}
#endif /* #if (CFG_VDY_YW_DYN_AVG) */


/* **********************************************************************
	Unit Design for vdyYwrInitYawRateData is found in Declaration Section
**************************************************************************** */
STATIC_MTD void vdyYwrInitYawRateData(VDYYwrSenData_t *YawRateData)
{
  YawRateData->DeltaDist         = VDY_ZERO_F;
  YawRateData->Gradient          = VDY_ZERO_F;
  YawRateData->GradientAbsOld    = VDY_ZERO_F;
  YawRateData->YawRate           = VDY_ZERO_F;
  YawRateData->YawRateCurveFilt1 = VDY_ZERO_F;
  YawRateData->YawRateCurveFilt2 = VDY_ZERO_F;
  YawRateData->YawRateCurveFilt3 = VDY_ZERO_F;
  YawRateData->YawRateOld        = VDY_ZERO_F;
  YawRateData->YwCurveOld        = VDY_ZERO_F;
  YawRateData->Valid             = (boolean)FALSE;
  YawRateData->YwFirstCycleDone  = (boolean)FALSE;
  YawRateData->FilterTime        = VDY_ZERO_F;

  return;
}


/* **********************************************************************
	Unit Design for vdyYwrInitStandStillOffset is found in Declaration Section
**************************************************************************** */
void vdyYwrInitStandStillOffset(VDYYwrStandStillOffs_t *StandStOffs)
{
  vdyStatIntervalInit(&StandStOffs->SampleInterval_1);
  vdyStatIntervalInit(&StandStOffs->SampleInterval_2);
  vdyStatIntervalInit(&StandStOffs->SampleInterval);

  StandStOffs->AdjustTime          = VDY_ZERO_F;
  StandStOffs->MaxQuality          = VDY_ZERO_F;
  StandStOffs->YawRateOffset       = VDY_ZERO_F;
  StandStOffs->StandstillOK        = (boolean)FALSE;

  return;
}


#if (CFG_VDY_EX_YWR_NVM)
/* **********************************************************************
	Unit Design for vdyYwrInitStandStillEepromOffset is found in Declaration Section
**************************************************************************** */
STATIC_MTD void vdyYwrInitStandStillEepromOffset(VDYYwrStandStillEepromOffs_t *StandStEepromOffs)
{
  StandStEepromOffs->YawRateOffset.Offset1       = VDY_ZERO_F;
  StandStEepromOffs->YawRateOffset.Status1       = VDY_ZERO_U;
  StandStEepromOffs->YawRateOffset.Offset2       = VDY_ZERO_F;
  StandStEepromOffs->YawRateOffset.Status2       = VDY_ZERO_U;
  StandStEepromOffs->TimeLastWrittenEepromOffset = YWR_OFFS_ELPSD_TIME_MAX;
  StandStEepromOffs->MaxQuality                  = VDY_ZERO_F;
  StandStEepromOffs->NumOfWrittenOffsets         = VDY_ZERO_U;
  
  return;
}
#endif 


#if (CFG_VDY_YW_DYN_AVG)
/* **********************************************************************
	Unit Design for vdyYwrInitDynOffsAvg is found in Declaration Section
**************************************************************************** */
STATIC_MTD void vdyYwrInitDynOffsAvg(VDYYwrDynOffsAvg_t *DynOffsAvg)
{
  const VDYYwrOffsData_t *Offs  = YWR_GET_OFFS;     /* Offsetdaten */

  DynOffsAvg->YwFilt[0].fout = Offs->YawRateOffset;
  DynOffsAvg->YwFilt[1].fout = Offs->YawRateOffset;
  DynOffsAvg->YwFilt[0].fin  = Offs->YawRateOffset;
  DynOffsAvg->YwFilt[1].fin  = Offs->YawRateOffset;
  DynOffsAvg->YawRateOffset  = Offs->YawRateOffset;

  DynOffsAvg->YwDist         = VDY_ZERO_F;
  DynOffsAvg->MaxQuality     = VDY_ZERO_F;

  DynOffsAvg->StDrv          = VDY_ZERO_F;
  DynOffsAvg->YwDrvDistThr   = VDY_ZERO_F;

  DynOffsAvg->DrvDistRed     = VDY_ZERO_F;

  DynOffsAvg->YwFiltDet[0].fout = Offs->YawRateOffset;
  DynOffsAvg->YwFiltDet[1].fout = Offs->YawRateOffset;
  DynOffsAvg->YwFiltDet[0].fin  = Offs->YawRateOffset;
  DynOffsAvg->YwFiltDet[1].fin  = Offs->YawRateOffset;
  DynOffsAvg->YawRateDet        = Offs->YawRateOffset;

  DynOffsAvg->QReduce           = VDY_ONE_F;
  DynOffsAvg->FlStwAStat        = (boolean)FALSE;


  return;
}


/* **********************************************************************
	Unit Design for vdyYwrInitDynOffsInterim is found in Declaration Section
**************************************************************************** */
STATIC_MTD void vdyYwrInitDynOffsInterim(VDYYwrDynOffsInter_t *DynOffsInter)
{
  const VDYYwrOffsData_t *Offs  = YWR_GET_OFFS;     /* Offsetdaten */

  DynOffsInter->YawRateOffset  = Offs->YawRateOffset;

  DynOffsInter->YwFiltInt[0].fout = Offs->YawRateOffset;
  DynOffsInter->YwFiltInt[1].fout = Offs->YawRateOffset;
  DynOffsInter->YwFiltInt[0].fin  = Offs->YawRateOffset;
  DynOffsInter->YwFiltInt[1].fin  = Offs->YawRateOffset;

  DynOffsInter->MaxQuality = VDY_ZERO_F;
  DynOffsInter->DistThrd   = VDY_ZERO_F;

  return;
}
#endif


/* **********************************************************************
	Unit Design for vdyYwrInitOffsetData is found in Declaration Section
**************************************************************************** */
STATIC_MTD void vdyYwrInitOffsetData( VDYYwrOffsData_t *OffsData)
{
  vdyYwrInitStandStillOffset(&OffsData->StandStillOffset);
#if (CFG_VDY_EX_YWR_NVM)
  vdyYwrInitStandStillEepromOffset(&OffsData->StandStillEepromOffset);
#endif

#if (CFG_VDY_YW_DYN_AVG)
  vdyYwrInitDynOffsAvg(&OffsData->DynOffsAvg);
  vdyYwrInitDynOffsInterim(&OffsData->DynOffsAvg.IntOffs);
#endif
  OffsData->EcuElpsdTime           = VDY_ZERO_F;
  OffsData->MaxQuality             = VDY_ZERO_F;
  OffsData->OffsCompOK             = (boolean)FALSE;
  OffsData->OffsElpsdTime          = VDY_ZERO_F;
  OffsData->OffsType               = (VDYYwrOffsType_t) OFFS_NON;
  OffsData->Quality                = VDY_ZERO_F;
#if (CFG_VDY_YW_DYN_AVG)
  OffsData->QualNoRed              = OffsData->Quality;
  OffsData->Cache.YawRateOffset    = VDY_ZERO_F;
  OffsData->Cache.Quality          = VDY_ZERO_F;
#endif
  OffsData->Temperature            = VDY_ZERO_F;
  OffsData->TemperOK               = (boolean)FALSE;
  OffsData->YawRateOffset          = VDY_ZERO_F;

  return;
}


/* **********************************************************************
	Unit Design for vdyYwrGetPrivateData is found in vdy.h
**************************************************************************** */
VDYYwrData_t *vdyYwrGetPrivateData(void)
{
  return (YWR_GET_ME);
}


#if (CFG_VDY_EX_YWR_NVM)
/* **********************************************************************
	Unit Design for vdyYwrEepromWriteYwOffset is found in Declaration Section
**************************************************************************** */
STATIC_MTD void vdyYwrEepromWriteYwOffset(const VDYYwrEepromOffset_t *NVValue, const VDYNvIoData_t *nvin, VDYNvIoData_t *nvout)
{
#if ( (defined(CFG_VDY_NVM_LEARN_DATA_ERROR)) && (CFG_VDY_NVM_LEARN_DATA_ERROR) )
  /* check for valid values written into NVM */
if (((vdyYwrOffsetRangeOk(NVValue->Offset1) == (boolean)TRUE)) && (NVValue->Status1 < YWR_NVM_OFFSET_STATUS_MAX))
    {
#endif
  nvout->YwRate.ZeroRate    = NVValue->Offset1;
  nvout->YwRate.CalStatus   = NVValue->Status1;

#if( (defined(CFG_VDY_SWA_AY_YAW_SSD_WLD_DIS_NVM_VALID_CHECK))&&(CFG_VDY_SWA_AY_YAW_SSD_WLD_DIS_NVM_VALID_CHECK))
/* writing Yaw offset into NVM in every excution cycle */
  LastYawNvmData.ZeroRate    = NVValue->Offset1;
  LastYawNvmData.CalStatus   = NVValue->Status1;
#endif

  /* check for new nvm min max yaw rate values */
  if (nvout->YwRate.CalStatus > 1U)
  {
    if (nvout->YwRate.ZeroRate < nvin->YwRate.ZeroRateMin)
    {
      nvout->YwRate.ZeroRateMin = nvout->YwRate.ZeroRate;
#if( (defined(CFG_VDY_SWA_AY_YAW_SSD_WLD_DIS_NVM_VALID_CHECK))&&(CFG_VDY_SWA_AY_YAW_SSD_WLD_DIS_NVM_VALID_CHECK))
  /* writing Yaw offset into NVM in every excution cycle */
      LastYawNvmData.ZeroRateMin = nvout->YwRate.ZeroRate;
#endif
    }
    if (nvout->YwRate.ZeroRate > nvin->YwRate.ZeroRateMax)
    {
      nvout->YwRate.ZeroRateMax = nvout->YwRate.ZeroRate;
#if( (defined(CFG_VDY_SWA_AY_YAW_SSD_WLD_DIS_NVM_VALID_CHECK))&&(CFG_VDY_SWA_AY_YAW_SSD_WLD_DIS_NVM_VALID_CHECK))
  /* writing Yaw offset into NVM in every excution cycle */
      LastYawNvmData.ZeroRateMax = nvout->YwRate.ZeroRate;
#endif
    }
  }
  else
  {
    /* first time that offset is written, set this offset as both min and max value */
    nvout->YwRate.ZeroRateMin = nvout->YwRate.ZeroRate;
    nvout->YwRate.ZeroRateMax = nvout->YwRate.ZeroRate;
#if( (defined(CFG_VDY_SWA_AY_YAW_SSD_WLD_DIS_NVM_VALID_CHECK))&&(CFG_VDY_SWA_AY_YAW_SSD_WLD_DIS_NVM_VALID_CHECK))
  /* writing Yaw offset into NVM in every excution cycle */
      LastYawNvmData.ZeroRateMin = nvout->YwRate.ZeroRate;
      LastYawNvmData.ZeroRateMax = nvout->YwRate.ZeroRate;
#endif

  }

  /* <ln_offset:+2 PCLINT Error 845: reviewer name: Jochen Spruck date: 11-11-2010 reason: proven in use, error because of first state mask is zero */
  /* <ln_offset:+1 PCLINT Error 835: reviewer name: Jochen Spruck date: 11-11-2010 reason: proven in use, error because of first state mask is zero */
  /* PRQA S 2985 EOF */
  /* date: 2019-06-10, reviewer: Mahesh Patle (uidr0487), reason: Out of Scope of VDY */
  VDY_SET_NVM_IO_STATE(VDY_NVM_POS_YWR, VDY_IO_STATE_VALID, &nvout->State);
#if ( (defined(CFG_VDY_NVM_LEARN_DATA_ERROR)) && (CFG_VDY_NVM_LEARN_DATA_ERROR) )
  /* check for valid values written into NVM */
     YWR_SET_NVM_WRITE = (VDY_ERR_STATE_INACTIVE);
    }
    else
    {
     YWR_SET_NVM_WRITE = (VDY_ERR_STATE_ACTIVE);
	 /*keep the old value into the NVM */ 
    }
#endif 

  return;
}
#endif


#if (CFG_VDY_EX_YWR_NVM)
/* **********************************************************************
	Unit Design for vdyYwrEepromReadYwOffset is found in Declaration Section
**************************************************************************** */
STATIC_MTD void vdyYwrEepromReadYwOffset(VDYYwrEepromOffset_t *NVValue, const VDYNvIoData_t *nvin)
{
#if( !(defined(CFG_VDY_SWA_AY_YAW_SSD_WLD_DIS_NVM_VALID_CHECK))||(!CFG_VDY_SWA_AY_YAW_SSD_WLD_DIS_NVM_VALID_CHECK))
  if (VDY_GET_NVM_IO_STATE(VDY_NVM_POS_YWR, &nvin->State) == VDY_IO_STATE_VALID)
#endif
  {
#if( (defined(CFG_VDY_SWA_AY_YAW_SSD_WLD_DIS_NVM_VALID_CHECK))&&(CFG_VDY_SWA_AY_YAW_SSD_WLD_DIS_NVM_VALID_CHECK))
  uint8 NAN_Err = 0;
  //NAN_Err |= (uint8)((boolean)(CML_f_Abs(nvin->YwRate.ZeroRate) < VDY_PAR_YWR_OFFSET_LIMIT_MAX)== (boolean)FALSE );
  NAN_Err |= ((CML_f_Abs(nvin->YwRate.ZeroRate) < VDY_PAR_YWR_OFFSET_LIMIT_MAX) ? 0U : 1U);
#endif
    if((nvin->State == NVM_CLEARED)
#if( (defined(CFG_VDY_SWA_AY_YAW_SSD_WLD_DIS_NVM_VALID_CHECK))&&(CFG_VDY_SWA_AY_YAW_SSD_WLD_DIS_NVM_VALID_CHECK))
	|| (nvin->YwRate.CalStatus >= YWR_NVM_OFFSET_STATUS_MAX)
	|| (NAN_Err == 1U)
#endif
	)
	{
	  NVValue->Offset1 = VDY_ZERO_F;
	  NVValue->Status1 = VDY_ZERO_U;
	}
	else
	{
      /* Upload data from nvmemory */
      NVValue->Offset1 = nvin->YwRate.ZeroRate;
      NVValue->Status1 = (uint8) (nvin->YwRate.CalStatus & VDY_X_FF_U);
	}
  }

  return;
}
#endif

/* **********************************************************************
	Unit Design for vdyYwrIsValid is found in vdy.h
**************************************************************************** */
boolean vdyYwrIsValid(void)
{
  return (YWR_GET_DATA->Valid);
}


/* **********************************************************************
	Unit Design for vdyYwrGetOffsData is found in vdy.h
**************************************************************************** */
/* <ln_offset:+2 MISRA Rule 8.3: reviewer name: Jochen Spruck date: 11-11-2010 reason: proven in use */
const VDYYwrOffsData_t *vdyYwrGetOffsData (void)
{
  return (YWR_GET_OFFS);
}


#if (CFG_VDY_YW_DYN_AVG)
/* **********************************************************************
	Unit Design for vdyYwrGetDynReduced is found in vdy.h
**************************************************************************** */
float32 vdyYwrGetDynReduced(void)
{
  VDYYwrOffsData_t *pYwOffsData  = YWR_GET_OFFS;
  fQuality_t ret;

  ret = vdyYwrCalcQRedRamp(pYwOffsData);

  return (ret);
}
#endif 


/* **********************************************************************
	Unit Design for vdyYwrCommonInit is found in Declaration Section
**************************************************************************** */
STATIC_MTD void vdyYwrCommonInit(void)
{
  /* Get Reference of Yaw Rate Data */
  VDYYwrSenData_t *YawRateData;     
  YawRateData = YWR_GET_DATA;

  /* Initialize Yaw Rate Data */
  vdyYwrInitYawRateData(YawRateData);

  return;
}


#if (CFG_VDY_EX_YWR_NVM)
/* **********************************************************************
	Unit Design for vdyYwrCalcEepromOffsetQuality is found in Declaration Section
**************************************************************************** */
STATIC_MTD void vdyYwrCalcEepromOffsetQuality(VDYYwrStandStillEepromOffs_t *pNvmOffs)
{
  const float32 invNvmStatMax_c = VDY_ONE_F / ((float32) YWR_NVM_STATUS_MAX);

  pNvmOffs->MaxQuality = ((float32)pNvmOffs->YawRateOffset.Status1 * invNvmStatMax_c);

  pNvmOffs->MaxQuality = MIN_FLOAT(VDY_ONE_F, pNvmOffs->MaxQuality);

  return;
} 
#endif


/* **********************************************************************
	Unit Design for vdyYwrOffsetInit is found in Declaration Section
**************************************************************************** */
STATIC_MTD void vdyYwrOffsetInit(const VDYNvIoData_t *nv_read)
{
    /* Get an instance of Yaw rate offset data */
  VDYYwrOffsData_t *OffsData;
  OffsData = YWR_GET_OFFS;

  /* Initialize Yaw Rate offset Data */
  vdyYwrInitOffsetData(OffsData);

#if (CFG_VDY_EX_YWR_NVM)
  /* Read Yaw rate offset from EEprom */
  vdyYwrEepromReadYwOffset(&OffsData->StandStillEepromOffset.YawRateOffset, nv_read);

  /* Calculate quality of eeprom yaw rate offset */
  vdyYwrCalcEepromOffsetQuality(&OffsData->StandStillEepromOffset);
#endif

  return;
}


#if (CFG_VDY_EX_YWR_NVM)
/* **********************************************************************
	Unit Design for vdyYwrSaveStandstillOffset is found in Declaration Section
**************************************************************************** */
STATIC_MTD void vdyYwrSaveStandstillOffset(VDYYwrOffsData_t *OffsetData)
{
  const VDYYwrStandStillOffs_t *pStStOffs    = &OffsetData->StandStillOffset;
  VDYYwrStandStillEepromOffs_t *pStStNvmOffs = &OffsetData->StandStillEepromOffset;

  float32 CycleTime;
  float32 YwTimeFirstWriteSec;

  /* Get cycle time */
  CycleTime = vdyGetCycleTime();

  /* Required elapsed time since ignition start in dependence of prior write cycles */
  if (OffsetData->StandStillEepromOffset.YawRateOffset.Status1 > (uint8) 0)
  {
    YwTimeFirstWriteSec = YWR_NVM_OFFS_STABLE_TIME;
  }
  else
  {
    YwTimeFirstWriteSec = YWR_NVM_OFFS_STABLE_TIME_1ST;
  }

  /*  Prerequisite for storage of standstill offset in nonvolatile memory 
   *   -> Warmed-up gyro sensor (elapsed time since ignition start)
   *   -> Minimum quality of standstill offset
   *   -> Minimum standstill adjust time
   *   -> Maximum number of nvm write accesses not exceeded
   *   -> Time gap between successive write accesses 
   or
   *   -> NVM offset state is 0 (no offset)
   *   -> The quality of the stand still offset should be good
   *   -> Store the offset 1 second after stand still  */
  if ( ( (OffsetData->EcuElpsdTime > YwTimeFirstWriteSec)
      && (pStStOffs->Observable != (boolean)FALSE)
      && (pStStOffs->MaxQuality > (VDY_YWR_OFF_STST_CALC_TIME_Q_MAX - C_F32_DELTA))
      && (pStStOffs->SampleInterval.Volume >= (YWR_NVM_WRITE_MIN_ADJ_TIME / CycleTime))
      && (pStStNvmOffs->NumOfWrittenOffsets < (uint8)YWR_NVM_WRITE_IGN_MAX_NO)
      && (pStStNvmOffs->TimeLastWrittenEepromOffset > YWR_NVM_WRITE_NEW_GAP_TIME) )
      || ( (OffsetData->StandStillEepromOffset.YawRateOffset.Status1 == (uint8)(0U)) 
        && (OffsetData->QualNoRed > (VDY_YWR_OFF_STST_CALC_TIME_Q_MAX - C_F32_DELTA))
        && (OffsetData->OffsElpsdTime > YWR_NVM_WRITE_OFFS_ELAPS_TIME )
        && (OffsetData->OffsType == (VDYYwrOffsType_t) OFFS_STANDST) ) )
  {
    float32 fltGain;
    
    /* Determine filter gain */
    if( pStStNvmOffs->YawRateOffset.Status1 > (uint8)YWR_NVM_FLT_MAX_WGHT )
    {
      fltGain = VDY_ONE_F / ((float32) YWR_NVM_FLT_MAX_WGHT + VDY_ONE_F);
    }
    else
    {
      fltGain = VDY_ONE_F / ((float32) pStStNvmOffs->YawRateOffset.Status1 + VDY_ONE_F);
    }

    /* Filter standstill offset */
    pStStNvmOffs->YawRateOffset.Offset1 =   ((VDY_ONE_F - fltGain) * pStStNvmOffs->YawRateOffset.Offset1) \
                                          + (fltGain * pStStOffs->SampleInterval.Mean);

    /* Increment nvm yaw rate status */
    if( pStStNvmOffs->YawRateOffset.Status1 < YWR_NVM_OFFSET_STATUS_MAX)
    {
      pStStNvmOffs->YawRateOffset.Status1 += (VDY_ONE_U);
    }

    /* Store new values in non-volatile memory */
    vdyYwrEepromWriteYwOffset(&pStStNvmOffs->YawRateOffset, YWR_GET_NVM_READ, YWR_GET_NVM_WRITE);

    /* Update nvm standstill offset quality */
    vdyYwrCalcEepromOffsetQuality(pStStNvmOffs);

    /* Reset time since last write access */
    OffsetData->StandStillEepromOffset.TimeLastWrittenEepromOffset = VDY_ZERO_F;

    /* Increment number of write accesses during this ignition cycle */
    pStStNvmOffs->NumOfWrittenOffsets += (uint8)(1U);
  }
  else
  {
    /* Prerequisite to store standstill offset are not given  */
  }
  return;
}
#endif


/* **********************************************************************
	Unit Design for vdyYwrEstStandstillOffset is found in Declaration Section
**************************************************************************** */
void vdyYwrEstStandstillOffset(fYawRate_t YwRate, boolean valYwr, VDYYwrStandStillOffs_t *pStStOff)
{
  fTime_t CycleTime;
  float32   invCycleTime;

  /* Get cycle time */
  CycleTime = vdyGetCycleTime();

  /* Initialize maximum quality */
  pStStOff->MaxQuality = VDY_ZERO_F;

  /* Test if yaw rate offset is observable */
  if (pStStOff->Observable != (boolean)FALSE)
  {
    /* Get inverse cycle time */
    invCycleTime = VDY_ONE_F / CycleTime;

    /* Yaw rate offset is observable */
    vdyStatIntervalAdd(&pStStOff->SampleInterval_1, YwRate, VDY_ONE_F);

    /* Test if offset samples collection time has been elapsed */
    if (pStStOff->SampleInterval_1.Volume >= (VDY_PAR_YWR_STST_CAL_TIME_MIN * invCycleTime))
    {
      /* Enough yaw rate offset samples are available */

      /* Add delay interval to evaluation interval */
      vdyStatIntervalMerge(&pStStOff->SampleInterval, &pStStOff->SampleInterval_2);
      vdyStatIntervalMeanDev(&pStStOff->SampleInterval);

      /* Reset elapsed time since last offset adjust */
      pStStOff->AdjustTime = VDY_ZERO_F;

      /* If deviation of sampled data is too large, discard all data */
      if (pStStOff->SampleInterval.Dev >= STANDST_STDABW_MAX)
      {
        vdyStatIntervalInit(&pStStOff->SampleInterval_1);
        vdyStatIntervalInit(&pStStOff->SampleInterval_2);
        vdyStatIntervalInit(&pStStOff->SampleInterval);
      }

      /* Check if enough time has been elapsed for offset calibration */
      if (pStStOff->SampleInterval.Volume >= (VDY_PAR_YWR_STST_CAL_TIME_MIN * invCycleTime))
      {        
        
      #if ( (defined(CFG_VDY_TURNTABLE_DETECTION)) && (CFG_VDY_TURNTABLE_DETECTION) )
        /* Take over new zero point offset if it the delta offset difference is under the MAX limit else take delta offset as previous offset +/-  4deg/sec*/
        if(CML_f_Abs(PrevYawRateOffset - pStStOff->SampleInterval.Mean) < MAX_LIMITATION_DELTA_YAW_RATE_OFFSET)
        {
          pStStOff->YawRateOffset = pStStOff->SampleInterval.Mean;
        }
        else
        {
          if (pStStOff->SampleInterval.Mean > PrevYawRateOffset)
          {
            pStStOff->YawRateOffset = PrevYawRateOffset + MAX_LIMITATION_DELTA_YAW_RATE_OFFSET;
          }
          else 
          {
            pStStOff->YawRateOffset = PrevYawRateOffset - MAX_LIMITATION_DELTA_YAW_RATE_OFFSET;
          }
        }
      #else
        /* Take over new zero point offset */
        pStStOff->YawRateOffset = pStStOff->SampleInterval.Mean;
		
      #endif
        
        /* Calculate quality by means of used samples */
        /* doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-881-00026448 */
        pStStOff->MaxQuality = vdyLFunction( (pStStOff->SampleInterval.Volume * CycleTime),
          VDY_PAR_YWR_STST_CAL_TIME_MIN    , VDY_PAR_YWR_STST_CAL_TIME_NORM,
          VDY_YWR_OFF_STST_CALC_TIME_Q_MIN  ,VDY_YWR_OFF_STST_CALC_TIME_Q_MAX);
      }

      /* If offset calibration last a long time fade memory data to preserve dynamic */
      if (pStStOff->SampleInterval.Volume >= (VDY_YWR_OFF_STST_SUM_MAX_TIME / CycleTime))
      {
          /* doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-885-00026448 */
        vdyStatIntervalReduce(&pStStOff->SampleInterval, VDY_YWR_OFFSET_REDUCTION_FACTOR);
      }

      /* Copy gathering inverval to delay interval */
      vdyStatIntervalInit(&pStStOff->SampleInterval_2);
      vdyStatIntervalMerge(&pStStOff->SampleInterval_2,  &pStStOff->SampleInterval_1 );

      /* Initialize gathering interval */
      vdyStatIntervalInit(&pStStOff->SampleInterval_1);
    }
  }
  else
  {    
    /* Yaw rate offset is not observable */

    if (  (pStStOff->StandstillOK == (boolean)FALSE)
        ||(valYwr == (boolean)FALSE) )
    {      
      /* Vehicle doesn't stand still */

      /* Initialize gathering and delay interval because of possibly wrong sampled data during drive-off */
      vdyStatIntervalInit(&pStStOff->SampleInterval_1);
      vdyStatIntervalInit(&pStStOff->SampleInterval_2);
    }

    /* Preserve evaluation interval for certain time to prevent initialization during 
       stop and go driving situations. This reduces the time to complete the learning of 
       offset value */
    if (pStStOff->SampleInterval.Volume > VDY_ZERO_F)
    {
      pStStOff->AdjustTime += CycleTime;
       
      if (pStStOff->AdjustTime >= VDY_YWR_OFF_STST_INTERV_HOLD_TIME)
      {
        vdyStatIntervalInit( &pStStOff->SampleInterval);
        pStStOff->AdjustTime = VDY_ZERO_F;
      }
    }
  }
  return;
}


/* **********************************************************************
	Unit Design for vdyYwrCalcOffsetQualityTime is found in Declaration Section
**************************************************************************** */
STATIC_MTD void vdyYwrCalcOffsetQualityTime(fQuality_t *OffsQuality,
                                fQuality_t MaxQuality,
                                fTime_t OffsElpsdTime,
                                boolean TemperOK)
{
  VDYYwrOffsData_t *OffsData;

  /* Get Yaw Rate Offset */
  OffsData  = YWR_GET_OFFS;

#if (CFG_VDY_YW_DYN_AVG)
   /* Bei grosser Abweichung zu dynamischen Offset, Guete reduzieren um Gewicht bei Gesamtspur
      zu minimieren */
  { 
    const VDYOutCurve_t WhsCurve_c = {0.F, 0.F, 0.F};
    const VDYOutCurve_t SwaLCurve_c = {0.F, 0.F, 0.F};
   
    const VDYOutCurve_t    *WspTrack      = &WhsCurve_c;      /* RDZ-Spur     */
    const VDYOutCurve_t    *StrgLogTrack  = &SwaLCurve_c;  /* Log.LW-Spur  */
    const fQuality_t  qualMinStLog_c = 0.1F;                 /* Mindest-Guete STA */

    /* Vorbedingung die fuer eine GueteReduzierung erfuellt sein muessen */
    if ( OffsData->DynOffsAvg.YwDist > YWR_DYNC_QRED_DIST_MIN )
    {
      float32 wghtPermit;  /* Faktor fuer zugelassene Guetereduzierung */

      /* Erlaubte Guetereduzierung in Abhaengigkeit von Lenkwinkel- und Raddrehzahlgueten */
      if (StrgLogTrack->Variance > qualMinStLog_c)
      {
        wghtPermit = VDY_ONE_F;  /* Maximale Reduzierung zulassen d. h. 1 -> 0 */
      }
      else
      {
        /* zugelassene Reduzierung in Abhaengigkeit der Raddrehzahlspur-Qualitaet 
          d. h. dQred =  (1 - Qred) * Permit, und QRedNeu = 1-dQred */
        wghtPermit = vdyLFunction(WspTrack->Variance, YWR_WSP_Q_START_MIN, YWR_WSP_Q_END_MAX, 
                                                    YWR_WSP_Q_CONF_START_MIN,YWR_WSP_Q_CONF_START_MAX);
      }
      
      /* Zweistufige Rampe zur Guetereduzierung */
      OffsData->DynOffsAvg.QReduce = vdyYwrCalcQRedRamp(OffsData);
      
      /* Bei dynamischen Average-Offset zugelassende Reduzierung in Abhaengigkeit von der wirksamen 
         Offsetzeit erhoehen, entspricht ansatzweise einer Gradientenbetrachtung */
      if (OffsData->OffsType==(VDYYwrOffsType_t) OFFS_DYN_AVG)
      {
        OffsData->DynOffsAvg.QReduce *= vdyLFunction(OffsData->OffsElpsdTime,YWR_OFFSET_TIME_START_MIN,YWR_OFFSET_TIME_START_MAX,
                                                         YWR_Q_FACTOR_DELTA_START_MIN,YWR_Q_FACTOR_DELTA_START_MAX);
      }
      
      /* Max. Reduzierung in Abhaengigkeit der restlichen Guetesignale zulassen  */
      OffsData->DynOffsAvg.QReduce =  VDY_ONE_F - ((VDY_ONE_F - OffsData->DynOffsAvg.QReduce) * wghtPermit);
    }
    else
    {
      OffsData->DynOffsAvg.QReduce = VDY_ONE_F; /* Default Wert setzen */    
    }
  }

#endif

  /* In Abhaengigkeit des wirksamen Offset-Typs Qualitaet altern */
  switch(OffsData->OffsType)
  {
#if (CFG_VDY_YW_DYN_AVG)
    case OFFS_DYN_AVG:
    case OFFS_DYN_INTER:
      /* DynAverageOffset, unsicher -> deshalb Guete schnell reduzieren */
      *OffsQuality = MaxQuality * vdyLFunction(OffsElpsdTime,
                                         YWR_TIME_DYNAVGOFF_MIN, YWR_TIME_DYNAVGOFF_MAX,
                                         YWR_Q_FACTOR_DYNAVGOFF_MAX,YWR_Q_FACTOR_DYNAVGOFF_MIN);
      break;
#endif

#if (CFG_VDY_EX_YWR_NVM)    
    case OFFS_STANDST_EEPROM:

      /* Qualitaet ueber Zeit wird in seperater Funktion speziell fuer EEPROM berechnet */
      *OffsQuality = VDY_ONE_F;
      
      break;
#endif

    case OFFS_NON:
    case OFFS_DYN_APPRX:
    case OFFS_STANDST:
    case OFFS_TEMPER_TABLE:
    default:
      if (TemperOK == (boolean)TRUE)
      {  /* Getemperter (eingeschwungener) Zustand -> Guete langsam reduzieren */
         *OffsQuality = MaxQuality * vdyLFunction(OffsElpsdTime,
                                     YWR_TIME_SENSOR_TEMP_MIN,YWR_TIME_SENSOR_TEMP_MAX,
                                     YWR_Q_FACTOR_SENSOR_TEMP_MAX,YWR_Q_FACTOR_SENSOR_TEMP_MIN);
      }
      else
      {  /* Nicht getemperter Zustand -> Guete schnell reduzieren */
         *OffsQuality = MaxQuality * vdyLFunction(OffsElpsdTime,
                                       YWR_TIME_SENSOR_COOL_MIN,YWR_TIME_SENSOR_COOL_MAX,
                                       YWR_Q_FACTOR_SENSOR_COOL_MAX,YWR_Q_FACTOR_SENSOR_COOL_MIN);
      }
      break;
  }

  
#if (CFG_VDY_YW_DYN_AVG)
  /* Nicht-reduzierte Guete speichern fuer Uebernahme-Test */
  OffsData->QualNoRed = *OffsQuality;

  /* zurueckgegebene Guete reduzieren fuer Gewichtung */
  *OffsQuality *=  OffsData->DynOffsAvg.QReduce;
#endif
} /* END:    void vdyYwrCalcOffsetQualityTime */


#if (CFG_VDY_EX_YWR_NVM)
/* **********************************************************************
	Unit Design for vdyYwrCalcEepromOffsetQualityTime is found in Declaration Section
**************************************************************************** */
STATIC_MTD void vdyYwrCalcEepromOffsetQualityTime(fQuality_t *OffsQuality, fQuality_t MaxQuality, fTime_t EcuElpsdTime)
{
  VDYYwrOffsData_t *OffsData;

  /* Hole Drehratenoffset */
  OffsData  = YWR_GET_OFFS;

  /* Erhoehen der Guete ueber Zeit */

  /* Getemperter (eingeschwungener) Zustand -> maximale Guete */
  *OffsQuality = MaxQuality * vdyLFunction(EcuElpsdTime,
                                   YWR_TIME_Q_EEPROM_OFFSET_MIN, YWR_TIME_Q_EEPROM_OFFSET_MAX,
                                   YWR_Q_FACTOR_EEPROM_OFFSET_MIN, YWR_Q_FACTOR_EEPROM_OFFSET_MAX);

#if (CFG_VDY_YW_DYN_AVG)
  /* Nicht-reduzierte Guete speichern fuer Uebernahme-Test */
  OffsData->QualNoRed = *OffsQuality;

  /* zurueckgegebene Guete reduzieren fuer Gewichtung */
  *OffsQuality *=  OffsData->DynOffsAvg.QReduce;
#endif

  return;
}
#endif


/* **********************************************************************
	Unit Design for vdyYwrTakeOffs is found in Declaration Section
**************************************************************************** */
STATIC_MTD boolean vdyYwrTakeOffs(VDYYwrOffsData_t *OffsData, fYawRate_t Offset,
                            fQuality_t Quality, VDYYwrOffsType_t Type)
{
  boolean OffsetTaken = (boolean)FALSE;

  /* Check whether a new offset should be adopted */
  if ( (Quality >= C_F32_DELTA)                                     /* Offset quality must be greater than 0 */
        && (   (Type == (VDYYwrOffsType_t) OFFS_TEMPER_TABLE)        /* If Offset type is Offset acquired from temperature table */
#if (CFG_VDY_YW_DYN_AVG)
        || (Quality >= OffsData->QualNoRed)   /* If new offset quality is greater than or equal to current offset quality */
#else
        || (Quality >= OffsData->Quality)     /* If new offset quality is greater than or equal to current offset quality  */ 
#endif
           )  )
  {
    /* Takeover new Offset */
    OffsData->YawRateOffset = Offset;

    /* Takeover new Quality  */
    OffsData->MaxQuality = Quality;

    /* Takeover new Offset type  */
    OffsData->OffsType = Type;

    /* Reset Elapsed Time since the last offset value is learnt */
    OffsData->OffsElpsdTime = VDY_ZERO_F;

    if (Type != (VDYYwrOffsType_t) OFFS_TEMPER_TABLE)
    {
      /* Set the temper flag if the ECU has been running for some time (half an hour) */
      if (OffsData->EcuElpsdTime > YWR_ELPSD_TIME_SENSOR_COOL )
      {
        OffsData->TemperOK = (boolean)TRUE;
      }
    }

    /* Mark offset as accepted or taken over */
    OffsetTaken = (boolean)TRUE;
  }
  
  return (OffsetTaken);
}


/* **********************************************************************
	Unit Design for vdyYwrCalcOffset is found in Declaration Section
**************************************************************************** */
#if (CFG_VDY_MFC)
STATIC_MTD void vdyYwrCalcOffset(const VDYYwrSenData_t *YawRate, VDYYwrOffsData_t *OffsData, const VDYInputData_t *input, const proVdyPrtList_t *proPorts, const float32 RawVelo)
#else
STATIC_MTD void vdyYwrCalcOffset(const VDYYwrSenData_t *YawRate, VDYYwrOffsData_t *OffsData, const VDYInputData_t *input, const proVdyPrtList_t *proPorts)  
#endif
{

#if ( (defined(CFG_VDY_TURNTABLE_DETECTION)) && (CFG_VDY_TURNTABLE_DETECTION) )
  /* Turn Table cycle counter */
  static uint8 u_turntableCounter ;
  /* Turn Table Flag */
  boolean b_turn_table_flag = (boolean)TRUE;
  /* Flag for storing the PrevYawRateOffset value */
  static boolean b_PrevStandstillOK = (boolean)FALSE;
  /* Initialization Flag */
  static boolean b_initFlag = (boolean)FALSE;
  /* Difference in rawrates of front & rear wheels yaw rates and sensor yaw rate*/
  float32 yawRateDiffFront, yawRateDiffRear;
#else
  /*will make to wait for 25 cycles once after coming out of turn table */
  boolean b_turn_table_flag = FALSE;
#endif
  /* Mean Wheel Velocity */
  float32 MeanWhlVel = VDY_ZERO_F;
  /* Flag if If SteerWheel Angle is more than +/- 90 degree and velocity is less than 0.05m/s then dont learn Yaw Offset. */
  boolean Steer_vs_Vel_Thresh = (boolean)TRUE;
  #if(CFG_VDY_MOT_STATE)
  /* Flag if Vehicle is StandStill */
  boolean MAX_STDST = (boolean)FALSE;
  #endif
  /* Flag to set if wheel ticks validity is Valid*/
  uint8 WhltickValid = 1U;
  /* Yaw Rate StandStill Offset Pointer */
  VDYYwrStandStillOffs_t *pStStOffs = &OffsData->StandStillOffset;
  /* Calibration Mode*/
  VDYCaliState_t CaliState = YWR_GET_ME->Io.in->Frame.CaliMode;

#if (CFG_VDY_EX_YWR_NVM)
  /* Corrected Vehhicle Velocity */
  fVelocity_t VehicleSpeed = YWR_GET_MIF_DATA->LongMot.VehVelocityCorr;
#endif

/* doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-730-00026448 */
#if ( (defined(CFG_VDY_TURNTABLE_DETECTION)) && (CFG_VDY_TURNTABLE_DETECTION) )

  yawRateDiffFront = CML_f_Abs(vdy_internal_data.vdy_wye_out.front_whl_yaw_rate_filt_wld - YawRate->YawRate );
  yawRateDiffRear =  CML_f_Abs(vdy_internal_data.vdy_wye_out.rear_whl_yaw_rate_filt_wld - YawRate->YawRate );

  /* will detect the vehicle turn table and set the flag  */
  if ((yawRateDiffFront > VDY_YAW_RATE_DIFF_THRESHOLD) && (yawRateDiffRear > VDY_YAW_RATE_DIFF_THRESHOLD)) 
  {
    b_turn_table_flag = (boolean)TRUE;

    if (u_turntableCounter < VDY_TURN_TABLE_ENABLE_TIME)
    {
      u_turntableCounter++;
    }
  }
  else
  {
    if(u_turntableCounter > 0U)
    {
      u_turntableCounter -- ;
    }
  }
   
  if(u_turntableCounter == 0U)
  {
    b_turn_table_flag = (boolean)FALSE;
  }

  /* During the Ignition On and the ego vehicle is in standstill mode initailizing the b_PrevStandstillOK to FALSE only in the first cycle for storing the PrevYawRateOffset value */
  if(b_initFlag == (boolean)FALSE)
  {
    b_PrevStandstillOK = (boolean)FALSE;
    b_initFlag  = (boolean)TRUE;
  }
  else
  {
    b_PrevStandstillOK = pStStOffs->StandstillOK;
  }
  
#endif

    /* Check if any Wheel Ticks is/are valid */
  if (   (VDY_GET_IO_STATE(VDY_SIN_POS_WTCKS_FL, input->Signals.State) == (VDYIoStateTypes_t)VDY_IO_STATE_VALID)
	  || (VDY_GET_IO_STATE(VDY_SIN_POS_WTCKS_FR, input->Signals.State) == (VDYIoStateTypes_t)VDY_IO_STATE_VALID)
	  || (VDY_GET_IO_STATE(VDY_SIN_POS_WTCKS_RL, input->Signals.State) == (VDYIoStateTypes_t)VDY_IO_STATE_VALID)
	  || (VDY_GET_IO_STATE(VDY_SIN_POS_WTCKS_RR, input->Signals.State) == (VDYIoStateTypes_t)VDY_IO_STATE_VALID))
  {
	 WhltickValid = (VDYIoStateTypes_t)VDY_IO_STATE_VALID;
  }
  else
  {
#if (CFG_VDY_USE_EX_LONG_VELO)
	   
	   if (VDY_GET_IO_STATE(VDY_SIN_POS_VEHVEL_EXT, input->Signals.State) == VDY_IO_STATE_VALID)
	   {
		   MeanWhlVel = input->Signals.VehVelocityExt;
		   (void)proPorts;  /* remove compiler warning, Services is not used in this configuration */
	   }
#else
		/* Mean velocity of all four wheels */
#if (CFG_VDY_MFC)
      MeanWhlVel = RawVelo;
#else
	  MeanWhlVel = proPorts->pVehicleDynamicSignals->Longitudinal.VelocityRaw;
#endif
  
#endif
  }
  
  /* Check all four wheel pulse Probability of Standstill is greater than their respective wheel pulse Probability of Forward and reverse */
  #if(CFG_VDY_MOT_STATE)
  if ((( (vdy_bayes_mot_states.mot_st_bayes_out.stage_1.ss > vdy_bayes_mot_states.mot_st_bayes_out.stage_1.fwd)
	  && (vdy_bayes_mot_states.mot_st_bayes_out.stage_1.ss > vdy_bayes_mot_states.mot_st_bayes_out.stage_1.rvs))
	  && (WhltickValid == (VDYIoStateTypes_t)VDY_IO_STATE_VALID))
	  || (WhltickValid == (VDYIoStateTypes_t)VDY_IO_STATE_INVALID))
  {
	  MAX_STDST = (boolean)TRUE;
  }
  #endif

  /* Determine standstill for offset compensation */
  pStStOffs->StandstillOK = (boolean) (((YWR_GET_MIF_DATA->LongMot.MotState.MotState == (MotState_t)VDY_LONG_MOT_STATE_STDST) && 
                                      (YWR_GET_MIF_DATA->LongMot.MotState.Confidence > VDY_PAR_YWR_STST_CONF_MIN)) ? TRUE : FALSE );

   /* If SteerWheel Angle is more than +/- 90 degree and velocity is less than 0.05m/s then dont learn Yaw Offset. */
  if((CML_f_Abs(input->Signals.StWheelAngle) > VDY_ONE_FIFTY_SEVEN_CENT) && (MeanWhlVel < WHL_VEL_MEAN))
    {
     Steer_vs_Vel_Thresh = (boolean)FALSE;
    }

  /* <ln_offset:-1 MISRA Rule 10.3: reviewer name: Jochen Spruck date: 27-09-2010 reason: proven in use */

  /* ##Code Review##: Since the condition check of b_turn_table_flag should allow for non Turn table situations , so it is acceptable " */
  /* PRQA S 3355 EOF */
  /* date: 27-09-2010, reviewer: Jochen Spruck, reason: Since the condition check of b_turn_table_flag should allow for non Turn table situations , so it is acceptable " */
  /* Determine if yaw rate offset is observable */
  /* doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-877-00026448 */

  if((CML_f_Abs(YawRate->Gradient) <= VDY_YWR_OFF_STST_GRAD_ABS_MAX)
      && (YawRate->Valid != (boolean)FALSE)
      && (b_turn_table_flag == (boolean)FALSE)
      && (pStStOffs->StandstillOK != (boolean)FALSE)
	  && (MeanWhlVel < WHL_VEL_MEAN)
      && (Steer_vs_Vel_Thresh == (boolean)TRUE)
	  #if(CFG_VDY_MOT_STATE)
	  && (MAX_STDST == (boolean)TRUE)
	  #endif
	  )
	  {
		    pStStOffs->Observable = (boolean)TRUE;
	  }
	  else
	  {
		    pStStOffs->Observable = (boolean)FALSE;
	  }
  

#if ( (defined(CFG_VDY_TURNTABLE_DETECTION)) && (CFG_VDY_TURNTABLE_DETECTION) )
  /*moving to standstill*/
  if ((b_PrevStandstillOK == (boolean)FALSE) && (pStStOffs->StandstillOK == (boolean)TRUE))
  {
    PrevYawRateOffset = pStStOffs->YawRateOffset;
  }
#endif

  /* Start standstill offset calibration */
  if (!VDY_CTRL_GET_STATE((VDYCaliState_t)VDY_CAL_YWR_OFFS_STST, CaliState))
  {
    vdyYwrEstStandstillOffset(YawRate->YawRate, YawRate->Valid, pStStOffs);
  }

#if (CFG_VDY_EX_YWR_NVM)
  /* Save standstill offset in nonvolatile memory */
  vdyYwrSaveStandstillOffset(OffsData);
#endif

#if (CFG_VDY_YW_DYN_AVG)  
  {
    fDistance_t distFilt;
    
    /*  Dynamic adjustment of yaw rate offset via averaged straight-ahead driving  */
    if (!VDY_CTRL_GET_STATE((VDYCaliState_t)VDY_CAL_YWR_OFFS_DYN, CaliState))
    {
      distFilt = vdyYwrCalcDynOffsAvg(YawRate, &OffsData->DynOffsAvg, OffsData);

      /*  Dynamic offset for initialized steering angle status */
      vdyYwrCalcDynOffsInterim(&OffsData->DynOffsAvg.IntOffs, OffsData, distFilt);
    }

    /* check and take new offset over dynamic interim offset */
    (void) vdyYwrTakeOffs(OffsData, OffsData->DynOffsAvg.IntOffs.YawRateOffset,
        OffsData->DynOffsAvg.IntOffs.MaxQuality, (VDYYwrOffsType_t) OFFS_DYN_INTER);

    /* check and take new offset over dynamic offset */
    (void) vdyYwrTakeOffs(OffsData, OffsData->DynOffsAvg.YawRateOffset,
        OffsData->DynOffsAvg.MaxQuality, (VDYYwrOffsType_t) OFFS_DYN_AVG);
  }
#endif

  /* check and take new offset over StandStill offset */
  (void) vdyYwrTakeOffs(OffsData, OffsData->StandStillOffset.YawRateOffset,
                         OffsData->StandStillOffset.MaxQuality, (VDYYwrOffsType_t) OFFS_STANDST);
  /* Calculate yaw rate offset quality over time */
  vdyYwrCalcOffsetQualityTime(&OffsData->Quality, OffsData->MaxQuality, 
                               OffsData->OffsElpsdTime, OffsData->TemperOK);

#if (CFG_VDY_EX_YWR_NVM)
  /* If there is no standstill offset, use offset from EEPROM */
  if( (VehicleSpeed > YWR_CURVE_V_MIN) && (OffsData->OffsType == (VDYYwrOffsType_t) OFFS_NON) )
  {
    /* If there is no offset yet, use EEPROM offset with existing MaxQuality */
    (void) vdyYwrTakeOffs( OffsData, OffsData->StandStillEepromOffset.YawRateOffset.Offset1,
                             OffsData->StandStillEepromOffset.MaxQuality, (VDYYwrOffsType_t) OFFS_STANDST_EEPROM);
  }
  else
  {
      /* current standstill offset available */
  }

  if (OffsData->OffsType == (VDYYwrOffsType_t) OFFS_STANDST_EEPROM)
  {
    /* Determination of the yaw rate quality based on the EEPROM offset over time */
    vdyYwrCalcEepromOffsetQualityTime(&OffsData->Quality, OffsData->StandStillEepromOffset.MaxQuality, OffsData->EcuElpsdTime);
  }
  else
  {
    /* kein EEPROM-Offset, es muss keine spezielle Guete bestimmt werden */
      /* no EEPROM offset, no special goods need to be determined */
  }
#endif

  return;
}


/* **********************************************************************
	Unit Design for vdyYwrGetYawRate is found in vdy.h
**************************************************************************** */
void vdyYwrGetYawRate(YawRateVehDyn_t *yawrate)
{
    /* Get reference of Yaw rate offset data */
  VDYYwrOffsData_t *pOffs = YWR_GET_OFFS;
  /* Get reference of yaw rate data */
  VDYYwrSenData_t  *pSen  = YWR_GET_DATA;

  /* Calculate offset compensated yaw rate */
  yawrate->YawRate = pSen->YawRate - pOffs->YawRateOffset;
  yawrate->Variance = VDY_ZERO_F;
  
  return;
}


/* **********************************************************************
	Unit Design for vdyYwrCalcRunnigTime is found in Declaration Section
**************************************************************************** */
STATIC_MTD void vdyYwrCalcRunnigTime(void)
{
  fTime_t          CycleTime;
  VDYYwrOffsData_t *pOffsData;

  /* Get cycle time */
  CycleTime = vdyGetCycleTime();

  /* Get reference to offset data */
  pOffsData = YWR_GET_OFFS;

  /* Update ECU runtime up to maximum permitted value */
  if( pOffsData->EcuElpsdTime >= YWR_ECU_ELPSD_TIME_MAX )
  {
    pOffsData->EcuElpsdTime = YWR_ECU_ELPSD_TIME_MAX;
  } 
  else
  {
    pOffsData->EcuElpsdTime += CycleTime;
  }

  /* Update time since last offset calibration up to maximum permitted value */
  if( pOffsData->OffsElpsdTime >= YWR_OFFS_ELPSD_TIME_MAX )
  {
    pOffsData->OffsElpsdTime = YWR_OFFS_ELPSD_TIME_MAX;
  } 
  else
  {
    pOffsData->OffsElpsdTime += CycleTime;
  }

#if (CFG_VDY_EX_YWR_NVM)
  /* Update time since last storage of standstill offset to nonvolatile memory */
  if( pOffsData->StandStillEepromOffset.TimeLastWrittenEepromOffset >= YWR_OFFS_ELPSD_TIME_MAX )
  {
    pOffsData->StandStillEepromOffset.TimeLastWrittenEepromOffset = YWR_OFFS_ELPSD_TIME_MAX;
  } 
  else
  {
    /* Start timing not until first value has been written */
    if( pOffsData->StandStillEepromOffset.NumOfWrittenOffsets > (uint8) 0)
    {
      pOffsData->StandStillEepromOffset.TimeLastWrittenEepromOffset += CycleTime;
    }
  }
#endif
  return;
}

/** @} */ 
/* EOF */
