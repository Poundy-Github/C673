/*! \file **********************************************************************
  COMPANY:                Continental Temic, PC DAS, A.D.C. GmbH

  PROJECT:                MFC431LO19

  CPU:                    ARM Cortex M3

  COMPONENT:              vdy

  MODULNAME:              vdy_cfg_ext.h

  DESCRIPTION:        	  Set vdy compiler straps for specific customer project

  AUTHOR:                 Jochen Spruck

  CREATION DATE:          17.09.2009
  
  VERSION:                $Revision: 1.1 $


 @defgroup GlobalProjectConfiguration Configuration
 This is the current configuration of the project.
 (1) functionality available
 (0) functionality not available
 @{
*/


/* conditional include */
#ifndef VDY_CFG_INCLUDED
#define VDY_CFG_INCLUDED

#include "vdy_ver.h"

/******************************************************************************************************************/
/******************************************************************************************************************/
/*                                                                                                                */
/*                                              vdy  component configuration                                      */
/*                                                                                                                */
/******************************************************************************************************************/
/******************************************************************************************************************/
/// Component version number as 4 byte BCD CC.MM.SS.FF \n
///  - CC: Custom Config identifier.  This identifier specifies the generation of Software \n
///  - For fifth gen project it should be "0x05"
#define VDY_CUSTOM_CONFIG_NO               (AlgoComponentVersionNumber_t)(0x05U)

///  MM: Main version number. This identifier specifies the Project .Ex-
///		- ARS441 		: "0x01"
///		- ARS510 		: "0x02"
///		- ARS510VW19	: "0x03"
///		- ARS540 		: "0x04"
///		- HFL110 		: "0x05"
///		- HFL130 		: "0x06"
///		- MFC431 		: "0x07"
///		- MFC431LO19	: "0x08"
///		- MFC431SC19	: "0x09"
///		- MFC431TA19	: "0x10"
///		- MFC510		: "0x11"
///		- MFC520 		: "0x12"
///		- MFC431SW19	: "0x13"
#define VDY_CUSTOM_MAIN_VER_NO             (AlgoComponentVersionNumber_t)(0x13U)

///  SS: Sub version number. This number reflects any change in custom files.
#define VDY_CUSTOM_SUB_VER_NO              (AlgoComponentVersionNumber_t)(0x00U)

///  FF: Bug fix level number. This number is of no use as of now.
#define VDY_CUSTOM_BUG_FIX_LEV             (AlgoComponentVersionNumber_t)(0x00U)

/// Enable measurement  
#define CFG_VDY_MEASUREMENT                                 (1U)

/// Enable dynamic gyro offst compensation 
#define CFG_VDY_YW_DYN_AVG                                  (1U)

/// Enable offset storage  in nonvolatile memory 
#define CFG_VDY_EX_YWR_NVM                                  (1U)

/// Enable internal yaw rate sensor processing 
#define CFG_VDY_INT_GYRO                                    (0U)

/// Enable optimized math function approximation (only possible with IEEE754 float format). if deactivated standard functions of  compiler runtime library will be used 
#define CFG_VDY_FPM_754                                     (1U)

/// Use external provided longitudinal acceleration signal  
#define CFG_VDY_USE_EX_LONG_ACCEL                   (0U)

/*! Use external provided longitudinal velocity signal  */
#define CFG_VDY_USE_EX_LONG_VELO                    (0U)

///  Enable motion state processing 
#define CFG_VDY_MOT_STATE                                   (1U)

///  Enables the velocity correction   
#define CFG_VDY_DO_VELOCITY_CORR                            (0U)

///  Enables ALN calculated velocity as input for velocity correction   
#define VEL_CORR_ALN                                        (0U)

///  Enables stationary targets as input for velocity correction   
#define VEL_CORR_HIST_STATIONARY_TARGETS                    (0U)

///  Enable lower max. variance of velocity correction factor variance if one measurement update is available 
#define CFG_VDY_USE_CORRECT_VELO_CORR_VAR                   (0U)

/// Enables usage of external curve as vdy output curve  
#define CFG_VDY_USE_EXT_PROC_CURVATURE                      (0U)

/// Enables usage of external yaw rate as vdy output yaw rate  
#define CFG_VDY_USE_EXT_PROC_YAW_RATE                       (0U)

/// Enables usage of external side slip angle as vdy ouput side slip angle  
#define CFG_VDY_USE_EXT_PROC_SIDE_SLIP_ANGLE                (0U)

/// Disables zero point offset compensation of input steering wheel angle signal 
#define CFG_VDY_DIS_SWA_OFFSET_COMP                         (0U)

/// Disables zero point offset compensation of input yaw rate signal 
#define CFG_VDY_DIS_YWR_OFFSET_COMP                         (0U)

/// Disables offset compensation between left and right wheel on vehicle axle 
#define CFG_VDY_DIS_WHS_OFFSET_COMP                         (0U)

/// Disables zero point offset compensation of input lateral acceleration signal 
#define CFG_VDY_DIS_LAT_OFFSET_COMP                         (0U)

/// Enables usage external estimated understeer gradient (characteristic velocity) as input parameter 
#define CFG_VDY_USE_EXT_PROC_UNDERSTEER_GRAD                (0U)

/// Enables usage of internal estimated understeer gradient instead of input parameter 
#define VDY_USE_LEARNED_UNDERSTEER_GRAD                     (1U)

/// If the estimated wheel load dep should be used 0-not use WLD, 1-use est wld front, 2-use external front wld parameter 
#define VDY_USE_EST_WLD_DEP                                 (1U)

/// Enables monitoring of external vehicle velocity. The velocity is compared with estimated velocity based on wheel speeds
#define CFG_VDY_USE_VELO_MONITOR                    (1U)

/// Enables monitoring of yaw rate at vehicle-stop, during vehicle-stop and vehicle drive-off. During this driving conditions zero point offset is roughly observeable. Exceedance of limits are indicated by error events
#define CFG_VDY_YWR_OFFSET_MONITOR                          (0U)

/// Disables the wheel speed pre processing, 
///    - wheel offset estimation
///    - wheel velocity <-> puls fusion
///    - vehicle speed estimation
///    - wheel load dependancy estimation
///    - dynamic (drift) sensor yaw rate offset estimation
///    - wheel velocity yaw rate estimation 
#define CFG_VDY_DIS_WHEEL_PRE_PROCESSING            (0U)

/// Disables the sensor yaw rate pre processing, 
///    - static (stand still)yaw rate offset
///    - yaw rate from yaw rate sensor estimation
#define CFG_VDY_DIS_YAW_SENSOR_PRE_PROCESSING               (0U)

/// Disables the alignment yaw rate offset pre filtering, 
///    - yaw rate from yaw rate sensor with filtered offset estimation
#define CFG_VDY_DIS_YAW_SENSOR_OFFS_PRE_FILTERING           (0U)

/// Disables the alignment yaw rate output,
///    - yaw rate from yaw rate sensor with filtered offset estimation
#define CFG_VDY_DIS_YAW_SENSOR_OUTPUT                       (1U)

/// Disables the lateral acceleration sensor pre processing, 
///    - lateral sensor offset estimation
///    - yaw rate from lateral acceleration sensor estimation
#define CFG_VDY_DIS_LAT_ACCEL_SENSOR_PRE_PROCESSING         (0U)

/// Disables the steering wheel angle sensor pre processing, 
///    - steering wheel angle sensor offset estimation
///    - estimation of self steering gradient
///    - driver intended curvature
///    - yaw rate from steering wheel sensor estimation
#define CFG_VDY_DIS_STW_ANGLE_SENSOR_PRE_PROCESSING         (0U)

/// Disables the side slip angle estimation
#define CFG_VDY_DIS_SIDE_SLIP_ANGLE_ESTIMATION              (0U)

/// Generated a velocity variance by deviation of the acceleration 
#define CFG_VDY_GEN_VELOCITY_VARIANCE                       (0U)

/// Do yaw rate offset monitoring with alignment offset estimation input 
#define CFG_VDY_ALIGNMENT_OFFSET_MONITOR                    (0U)

/// Disable functional safety monitoring  
#define CFG_VDY_DIS_FUNCTIONAL_SAFETY_MON                   (0U)

/// If the timing should be calculated 
#define CFG_VDY_CALC_VDY_TIMING                             (0U)

/// Enables the 64 bit Timestamp interface 
#define CFG_VDY_64BIT_TIMESTAMP_INTERV                      (0U)

/// Disable the additional VDY curve output 
#define CFG_VDY_DIS_CURVE_OUTPUT                            (0U)

/// Enables the fast velocity to stationary targets monitor  
#define CFG_VDY_FS_VELO_CORR_MON                            (0U)

/// Enables the output peak monitoring 
#define CFG_VDY_MON_OUTPUT_PEAKS                            (0U)

/// Enables runtime measurement and profiling 
#define VDY_PROFILING_ENABLED                               (1U)

/// Enables the compstate output 
#define CFG_VDY_USE_ALGOCOMPSTATE                           (1U)

/// Enables setting DEM events by VDY, otherwise only the VDYError flags are set 
#define CFG_VDY_SET_DEM_EVENTS                              (1U)

/// Enables reaction to roll bench detection 
#define CFG_VDY_ROLLBENCH_DETECTION                         (0U)

/// Enables setting DEM event VelMon
#define CFG_VDY_FS_VELO_CONF_MON_FAULT                      (0U)

/// Enables the increase of correction factor for trucks 
#define CFG_VDY_TRUCK_CORRFACT                              (0U)

/// Enables the max debouncing ouput counter 
#define CFG_VDY_DEBOUNCE_OUTPUTS                            (0U)

/// Enables the Turn Table detection and limit max. delta 4deg/sec yaw rate offset compensation at one learning cycle 
#define CFG_VDY_TURNTABLE_DETECTION                         (1U)

/// Enables the increase of correction factor to 30% for ARS4D2 
#define CFG_VDY_CORRFACT_ARS4D2                             (0U)

/// Disables Valid Or Invalid check before reading NVM and writes NVM data  in every vdy cycle to the provide port for camera(MDB) projects for steering wheel angle , Ay ,Yaw offset also SSD and WLD data 
#define CFG_VDY_SWA_AY_YAW_SSD_WLD_DIS_NVM_VALID_CHECK      (1U)

/// Enables the velocity variance check for setting the velocity not available DEM  
#define CFG_VDY_VELO_VARIANCE_CHECK                         (0U)

/// Enables the corrected velocity monitoring based on the new minimum and maximum velocity signals   
#define CFG_VDY_VELO_MONITOR_MIN_MAX                        (0U)

/// Enables the code for reducing the curve error after software reset
#define CFG_VDY_REDUCE_CURVE_ERROR                          (0U)

/// Enable DEM relates NVM learning values to ensure no corrupted data is written to flash memory 
#define CFG_VDY_NVM_LEARN_DATA_ERROR                        (1U)

/// Disable unused function throwing red error in polyspace  
#define CFG_VDY_POLYSPACE_ERROR_DISABLE                     (0U)

/// Enable measfreezing of VDY Structure VDYNvIoDataRD  
#define CFG_VDY_VDYNVIODATARD_MEASFREEZ_ENABLE              (1U)

/// Enables the switch to stop toggling the DEM for trucks 
#define CFG_VDY_INIT_MODE_AS_STARTUP_MODE                   (0U)

/// Enables the switch to Rear Wheel Steer 
#define CFG_VDY_REAR_WHEEL_STEERING                         (0U)

/// Enables the FS_YR_VS_WSP DEM  
#define CFG_VDY_FS_YR_VS_WSP_ENABLE                         (1U)

/// Enables the BMW acceleration Model  
#define CFG_VDY_BMW_LONG_ACCEL_MODEL                        (0U)

/// Enables the yaw rate variance check for yaw rate not available DEM 
#define CFG_VDY_YAWRATE_VARIANCE_CHECK                      (1U)

/// Enables the monitor of corrected velocity and ALN velocity error 
#define CFG_VDY_FS_VELO_CORR_MON_ERROR                      (0U)

/// Enables the code to stop toggling of FS_VEH_CORR_MON DEM
#define CFG_VDY_FS_VEH_CORR_MON_TOGGLING                    (0U) 

/// VDY Custom Software Version
#define VDY_CUSTOM_VERSION_NUMBER      ((VDY_CUSTOM_CONFIG_NO << 24U) | (VDY_CUSTOM_MAIN_VER_NO << 16U) | (VDY_CUSTOM_SUB_VER_NO << 8U)|(VDY_CUSTOM_BUG_FIX_LEV))

/// VDY Algo Software Version
#define VDY_SW_VERSION_NUMBER          ((VDY_SW_MAIN_VER_NO << 16U) | (VDY_SW_SUB_VER_NO << 8U) | (VDY_SW_BUG_FIX_LEV))

/// VDY Algo Software Version Info
#define VDY_SW_ALGO_VERSION_INFO	"SW_VDY_15.00.09"

/// Enables MFC specific logic 
#define CFG_VDY_MFC                                         (1U)

/// Enables MFC5xx specific logic 
#define CFG_VDY_MFC_VX                                      (0U)

/// Enable HFL specific logic
#define CFG_VDY_HFL											(0U)

/// Enables usage of ABS/TCS info in velocity and accel estimation
#define CFG_VDY_INT_TCS_ABS                                 (0U)

/// Enables Acceleration Fusion
#define CFG_VDY_FUSE_ACCEL                                  (0U)

/// Enables WheelPulse Processing in MotionState 
/// Note : For code gen always set to 1 
#define CFG_VDY_WHL_PULSE_MOT                               (1U)

/// Enables WheelDir Processing in MotionState 
/// Note : For code gen always set to 1 
#define CFG_VDY_WHL_DIR_MOT                                 (1U)

/// Enables BrkTrq Processing in MotionState 
/// Note : For code gen always set to 1 
#define CFG_VDY_BRK_TRQ_MOT                                 (0U)

/// Enables Longitudinal Acceleration Limit 
#define  CFG_VDY_LONG_ACCEL_LIMIT                           (1U)

/// Enables the RAW_YAW_RATE for WABCO  
#define CFG_VDY_RAW_YAW_RATE_WABCO                          (0U)


#endif /* VDY_CFG_INCLUDED */

/** @} */ 

/* EOF */
