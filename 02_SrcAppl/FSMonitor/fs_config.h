#ifndef FS_CONFIG_H
#define FS_CONFIG_H

#include "Dbg.h"

#ifndef DBG_FUSA_ENABLE
#error "DBG_FUSA_ENABLE not defined"
#endif

#ifndef DBG_FUSA_MTS_ENABLE
#error "DBG_FUSA_MTS_ENABLE not defined"
#endif

#if DBG_FUSA_ENABLE == STD_ON
    #define FS_EXEC_DISABLED 0
#else 
    #define FS_EXEC_DISABLED 1
#endif /* DBG_FUSA_ENABLE == STD_ON */


#if DBG_FUSA_MTS_ENABLE == STD_ON
    #define FS_PDO_ENABLED 1
#else  /* DBG_FUSA_MTS_ENABLE == STD_ON */
    #define FS_PDO_ENABLED 0
#endif /* DBG_FUSA_MTS_ENABLE == STD_ON */

/** 
 * FS takes control of records dem 
 *
 * Should be turn off (0) currently.
 *
 * Because there already be apps that also
 * monitoring dem fault trigger,and controls dem.
 * 
*/
#define FS_FEATURE_RECORD_DEM 0

/** 
 * FS takes control CanTrcv 
 *
 * When set to 1,`FS_CanTrcv_SetOpMode` must replaces 
 * the config in CanIf_Cfg.c
 * both FS and CanIf will call CanTrcv's SetOpMode.
 * 
 * unknown error will occurs
 * 
 * Ensure :
 * sed -i "" 's/CanTrcv_8_Tja1043_SetOpMode/FS_CanTrcv_SetOpMode/' output/generated/src/CanIf_Cfg.c
*/
// add header
// sed -i "" '/.*CanTrcv_8_Tja1043.h.*/a\
#include "function_safety.h"\
' output/generated/src/CanIf_Cfg.c

#define FS_FEATURE_CAN_TRCV_CONTROL 1

/** 
 * FS takes open api for replaces the can default data
 *
 * It is ok 0 or 1.
 * 
 * When set to 0.no related API is provides. 
 * Ram/Rom space will reduced
 * 
*/
#define FS_FEATURE_CAN_DEFAULT_DATA_CONTROL 0


/** 
 * When cat2 happens.
 * Reset immediately.
 * 
 * Set to 0 if delayed reset is needed.
 *  For example,waiting for dem recording.
 * 
 * Set to 1 for more simple and safe logic.
 * 
*/
#define FS_OPTION_IMMEDIATELY_CAT2_RESET 1

/** 
 * Turn on debug backdoor/logs
*/
#define FS_DEBUG 0


#if FS_OPTION_IMMEDIATELY_CAT2_RESET == 0
/** 
 * When DEM is on `FS_OPTION_IMMEDIATELY_CAT2_RESET` must be 0
 * and cat2 will wait `FS_CONFIG_DEM_CAT2_TIMEOUT` before reset
*/
#define FS_CONFIG_DEM_CAT2_TIMEOUT 50
/** 
 * Not used
*/
#define FS_CONFIG_DEM_CAT3_TIMEOUT 50

#endif /**FS_FEATURE_RECORD_DEM */
#endif /* FS_CONFIG_H */