// COMPANY:   Continental Automotive
// COMPONENT: Types
// VERSION:   $Revision: 1.15 $
// 00_Projects\MFC431\common\GLOB\glob_cfg.h
/// Global types and definitions for MFC431
/// @file

#ifndef GLOB_CFG_H
#define GLOB_CFG_H

#ifdef __cplusplus
extern "C"
{
#endif //-- __cplusplus

/// Description:  usage of memchr() from SYS component \n
/// Range:        1 (STD_ON on Infra), 0 (STD_OFF on Infra) \n
/// Resolution:   - \n
/// Unit:         -
#define SYS_MEMCHR_ENABLED  0u

/// Description:  Switch for enabling/disabling the debug pin for debugging purposes \n
/// Range:        {0, 1} \n
/// Resolution:   Boolean
#ifndef GLOB_DBG_PIN_ACTIVE
#define GLOB_DBG_PIN_ACTIVE 0u
#endif

/// Description:  Switch for enabling/disabling the time measurements for debugging purposes (interrupts, etc.) \n
/// Range:        {0, 1} \n
/// Resolution:   Boolean
#ifndef GLOB_DBG_TIME_MEAS_ACTIVE
#define GLOB_DBG_TIME_MEAS_ACTIVE 1u
#endif

/// Description: System clock frequency in MHz \n
/// Range:    - \n
/// Resolution: - \n
/// Unit:   MHz
#ifndef GLOB_SYS_FREQUENCY
#define GLOB_SYS_FREQUENCY 120u
#endif

/// Description: Nominal battery voltage \n
/// Nominal battery voltage in millivolt (float) \n
/// Range       Any floating point number \n
/// Resolution  1 \n
/// Unit        mV
#ifndef GLOB_BATTERY_VOLTAGE
#define GLOB_BATTERY_VOLTAGE  12000.0f
#endif

/// TODO remove - Most likely obsolete flags
#define GLOB_SENSOR_TECH_ARS400PP (0)
#define GLOB_SENSOR_TECH_ARS400PR (1)
#define GLOB_SENSOR_TECH_ARS400EN (2)
#define GLOB_SENSOR_TECH_SRR300 (3)
#define GLOB_SENSOR_TECH GLOB_SENSOR_TECH_SRR300

/// Description:  Switch for enabling/disabling the CRC32P4 function and the generation of its table \n
/// Range:        {0, 1} \n
/// Resolution:   Boolean
#define GLOB_CRC32P4_SERVICE_ENABLED (0)

/// Description:  Switch for enabling/disabling the use of Elektrobit vs. Vector OS \n
///               0 - Vector OS is used \n
///               1 - Elektrobit OS is used \n
/// Range:        {0, 1} \n
/// Resolution:   Boolean
#define GLOB_FEATURE_OS_ELEKTROBIT_USED 1u

/// Flags for DPU
#define CFG_MFC_STEREO (0)
#define CFG_MFC_MONO (1)
#define MFC_STEREO (0)

/// DSP IPC Response Time
#define CFG_IPC_DSP_RESPONSE_TIME_PRE_IMAGEOVERBUS_MS     (10000)

/// enum for boolean
typedef enum
{
  TRUE16 = 0xA5A5, ///< pattern for true
  FALSE16 = 0x5A5A ///< pattern for false
} boolean16;

/// Function pointer for void function without parameter
typedef void (*pfunc)(void);

#ifdef __cplusplus
}
#endif //-- __cplusplus

#endif //-- GLOB_CFG_H
