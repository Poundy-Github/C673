#ifndef FS_SOC_H
#define FS_SOC_H

#include <stdbool.h>
#include "fs_common.h"
#include "Platform_Types.h"


enum fs_exec_soc_state_t
{
    FS_EXEC_SOC_POWER_UNKNOWN,
    FS_EXEC_SOC_POWER_ON,
    FS_EXEC_SOC_POWER_OFF,
    FS_EXEC_SOC_WARM_RESET,
    FS_EXEC_SOC_COLD_RESET
};

#define FS_START_SEC_CODE_LOCAL
#include "Fs_MemMap.h"

/**
 * @brief Init SoC pwr control module
*/
extern void FSExec_SocInit(void);
/**
 * @brief DeInit SoC pwr control module
*/
extern void FSExec_SocDeInit(void);
/**
 * @brief Power off the Soc
 * @retval FS_RET_CODE_OK constantly
*/
extern fs_ret_code_t FSExec_SocPowerOff(void);
/**
 * @brief Power on the Soc
 * @retval FS_RET_CODE_OK constantly
*/
extern fs_ret_code_t FSExec_SocPowerOn(void);

/**
 * @brief Power Async Reset the Soc
 * @retval FS_RET_CODE_OK constantly
*/
extern fs_ret_code_t FSExec_SocWarmReset_Async(void);
/**
 * @brief Power Async Reset the Soc
 * @retval FS_RET_CODE_OK constantly
*/
extern fs_ret_code_t FSExec_SocColdReset_Async(void);
/**
 * @brief  Query current SoC pwr state
 * @retval the state
*/
extern enum fs_exec_soc_state_t FSExec_SocPowerState(void);
/**
 * @brief  Query current SoC Reset state
 * @retval the state
*/
extern enum fs_exec_soc_state_t FSExec_SocResetState(void);
/**
 * @brief Reset the Soc
 * @retval FS_RET_CODE_OK constantly
*/
extern void FSExec_SocRequestReset(enum fs_exec_soc_state_t state);

#define FS_STOP_SEC_CODE_LOCAL
#include "Fs_MemMap.h"

#endif /** FS_SOC_H */