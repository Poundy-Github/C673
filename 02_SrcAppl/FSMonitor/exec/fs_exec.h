#ifndef FS_EXEC_H
#define FS_EXEC_H

#include "function_safety.h"


#define FSEXEC_MAINFUNCTION_PERIOD               (5)

#define fs_self_test_error_flag_t int
#define FS_SELF_TEST_ERROR_FLAG_UBATT_HIGHT     (1<<0)
#define FS_SELF_TEST_ERROR_FLAG_UBATT_LOW       (1<<1)
#define FS_SELF_TEST_ERROR_FLAG_MCUTEMP_HIGH    (1<<4)
#define FS_SELF_TEST_ERROR_FLAG_MCUTEMP_LOW     (1<<5)
#define FS_SELF_TEST_ERROR_FLAG_RAM             (1<<6)
#define FS_SELF_TEST_ERROR_FLAG_DATA_FLASH      (1<<7)
#define FS_SELF_TEST_ERROR_FLAG_WDG             (1<<8)
#define FS_SELF_TEST_ERROR_FLAG_COM             (1<<9)

enum exec_range_t
{
    EXEC_RANGE_EXTREM_LOW,
    EXEC_RANGE_LOW,
    EXEC_RANGE_NORMAL,
    EXEC_RANGE_HIGH,
    EXEC_RANGE_EXTREM_HIGH
};

#define FS_START_SEC_CODE_LOCAL
#include "Fs_MemMap.h"

/**
 * @brief The Init function of FSExec
*/
extern void FSExec_Init(void);
/**
 * @brief The main function of FSExec
*/
extern void FSExec_MainFunction(void);
/** 
 * @brief Tell FSExec wheater APP is in eol state.
 * App calls `FS_SetAppIsEOL`,and Get the value through `FSExec_AppIsEOL`
 * 
 * @note Not set from app now,this function is disabled
 * 
 * @retval if is in EOL mode.
 */
extern bool FSExec_AppIsEOL(void);

/** 
 * @brief Polling function of FS Exec
 * @param ms interval
 */
extern void FSExec_Poll( unsigned int ms );
/** 
 * @brief Post CAT3 FS_CAT3_SOC_TEMP_OUT_OF_RANGE 
 */
extern void FSExec_SocInternalTempOutOfRange(void);
/** 
 * @brief Recovery CAT3 FS_CAT3_SOC_TEMP_OUT_OF_RANGE 
 */
extern void FSExec_SocInternalTempInRange(void);
/** 
 * @brief Post CAT3 FS_CAT3_MODULE_TEMP_OUT_OF_RANGE 
 */
extern void FSExec_ModuleTempOutOfRange(void);
/** 
 * @brief Recovery CAT3 FS_CAT3_MODULE_TEMP_OUT_OF_RANGE 
 */
extern void FSExec_ModuleTempInRange(void);
/** 
 * @brief Post CAT3 DEM_DTC_J3_SOC_CPU_Error_PWM_Missing 
 */
extern void FSExec_SpiPwmPostFailure(void);
/** 
 * @brief Recovery CAT3 DEM_DTC_J3_SOC_CPU_Error_PWM_Missing 
 */
extern void FSExec_SpiPwmRecoveryFailure(void);
/** 
 * @brief Post CAT3 FS_CAT3_SOC_STATE_ERROR 
 */
extern void FSExec_SoCStatePostFailure(void);
/** 
 * @brief Recovery CAT3 FS_CAT3_SOC_STATE_ERROR 
 */
extern void FSExec_SoCStateRecoveryFailure(void);

/** 
 * @brief Set the SoC Temperature State
 * 
 * if out of range, a CAT3  FS_CAT3_SOCJ3_TEMP_EXT_LOW/DEM_SOCJ3_TEMP_EXT_HIGH 
 * will be post
 * 
 * @param range the temperature range
 */
extern void FSExec_SetSoCTemperatureRange( enum exec_range_t range );
/** 
 * @brief Set the UBat State
 * 
 * if range is high or low, 
 * a CAT3 DEM_VMON_BATT_LOW/DEM_VMON_BATT_HIGH will be post
 * if range is extrem_high ot extrem_low
 * a CAT2 will be post
 * 
 * @param range the UBatt range
 */
extern void FSExec_SetUBattRange( enum exec_range_t range );

/** 
 * @brief Set the MCUTemperature State
 * 
 * if range is extrem_high /extrem_low
 * a CAT2 DDEM_MCU_TEMP_EXT_LOW/DEM_MCU_TEMP_EXT_HIGH will be post
 * 
 * @param range the MCUTemperatur range
 */
extern void FSExec_SetMCUTemperature( enum exec_range_t range );

/** 
 * @brief Set KL15 state
 * 
 * Only Low/extrem_low is working
 * When KL15 low,CAT2 count will reset
 * 
 * @param range the KL15 range
 */
extern void FSExec_SetKL15Range( enum exec_range_t range );

/** 
 * @brief Finish Self Test
 * 
 * Do State transition according SelfTest result
 * 
 * After Init,FS Exec is in SafeSilent mode.
 * only SelfTest finishs and the result is success.
 * It will transform to SafeCommunication mode.
 * 
 * If error detects.A Cat2 is recognized,
 * and will reset the MCU after increase CAT2 count.
 * 
 * @param error_flags the error flags
 */
extern void FSExec_FinishSelfTest(fs_self_test_error_flag_t error_flags);
/**
 * @brief Enter FS Endless mode
 * 
 * This function is to doing a endless loop.
 * The endless is suppose to maintain until ign off.
 * 
 * So at each loop, IGN value is read;
 * A reset is performed while the IGN belows the criticle 
 * level(As Ign off is recognized )
 * 
 * A smooth filter is applied to ign value.
 * 
*/
//void FSExe_EndlessMode(void);
#define FS_STOP_SEC_CODE_LOCAL
#include "Fs_MemMap.h"

#endif /** FS_EXEC_H */