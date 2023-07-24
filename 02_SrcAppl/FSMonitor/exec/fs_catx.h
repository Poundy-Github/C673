#ifndef _FS_CATX_H_
#define _FS_CATX_H_

/*==================[inclusions]============================================*/
#include <stdint.h>
#include "function_safety.h"
#include "fs_common.h"
#include "Dem_Cfg.h"
#include "Dem.h"

 /*==================[macros definitions]====================================*/
#define fs_cat_reset_reason_t       uint8_t
#define fs_cat_count_t              uint8_t
#define fs_catx_id_t                uint32_t


//If need report event to Dem ,shall be reply event number in below macro
#define FS_CAT3_SOC_TEMP_EXT_LOW            0x801u
#define FS_CAT3_SOC_TEMP_EXT_HIGH           0x802u
#define FS_CAT3_MODULE_TEMP_OUT_OF_RANGE    0x803u
#define FS_CAT3_SOC_STATE_ERROR             0x804u
#define FS_CAT3_SOC_TEMP_OUT_OF_RANGE       0x805u
#define FS_CAT3_MCU_VMON_BATT_LOW           0x806u
#define FS_CAT3_MCU_VMON_BATT_HIGH          0x807u
#define FS_CAT3_MCU_TEMP_EXT_LOW            0x808u
#define FS_CAT3_MCU_TEMP_EXT_HIGH           0x809u
#define FS_CAT2_MCU_VMON_BATT_LOW           0x810u
#define FS_CAT2_MCU_VMON_BATT_HIGH          0x811u
#define FS_CAT2_MCU_TEMP_EXT_LOW            0x812u
#define FS_CAT2_MCU_TEMP_EXT_HIGH           0x813u
#define FS_CAT3_SOC_PWM_ERROR               0x814u

#define FS_CAT_RESET_REASON_UNKNOWN            (0u)
#define FS_CAT_RESET_REASON_RESET              (1u)
#define FS_CAT_RESET_REASON_SHUTDOWN           (2u)
#define FS_CAT_RESET_REASON_CAT2               (3u)

#define FS_CAT_MAGIC_SIZE                     (16u)
#define FS_EXEC_MAX_RECORD_CAT3_COUNT         (16u)

/**
 * @brief CAT1 count
 * @note CAT1 is not implemented
*/
#define FSCat_Cat1Count() (g_fs_cat1_count)
/**
 * @brief CAT3 count
*/
#define FSCat_Cat2Count() (g_fs_cat2_count)

/**
 * @brief Increase the number of CAT1
 * @note CAT1 is not implemented
*/
#define FSCat_Cat1Increase() (g_fs_cat1_count++)
/**
 * @brief Increase the number of CAT3
*/
#define FSCat_Cat2Increase() (g_fs_cat2_count++)

/**
 * @brief Reset CAT1 count
 * @note CAT1 is not implemented
*/
#define FSCat_Cat1CountReset() (g_fs_cat1_count=0)
/**
 * @brief Reset CAT2 count
*/
#define FSCat_Cat2CountReset() (g_fs_cat2_count=0)

/**
 * @brief Get Last Reset reason
 * @note not work in this version because CAT1 is not implemented
*/
#define FSCat_LastResetReason() (g_fs_last_reset_reason)
/**
 * @brief Get Last Reset reason
 * @note not work in this version because CAT1 is not implemented
*/
#define FSCat_SetResetReason(r)  (g_fs_last_reset_reason=r)


/*==================[type definitions]=======================================*/
// struct fs_cat_t
// {
//     fs_catx_id_t cat3s[FS_EXEC_MAX_RECORD_CAT3_COUNT];
// };

struct fs_cat2_t
{
    fs_catx_id_t cat2id;
};

struct fs_cat3_t
{
    fs_catx_id_t cat3id;
#if FS_FEATURE_RECORD_DEM
    bool is_dem;
#endif /* FS_FEATURE_RECORD_DEM */
};

/*==================[external constants declarations]========================*/

/*==================[external data declarations]=============================*/
#define FS_START_SEC_VAR_NON_CLEARED
#include "Fs_MemMap.h"

extern fs_cat_reset_reason_t g_fs_last_reset_reason;
extern fs_cat_count_t g_fs_cat1_count;
extern fs_cat_count_t g_fs_cat2_count;
	
#define FS_STOP_SEC_VAR_NON_CLEARED
#include "Fs_MemMap.h"

/*==================[external function declarations]=========================*/
#define FS_START_SEC_CODE_LOCAL
#include "Fs_MemMap.h"
/**
 * @brief Init FSCat module
 * 
 * FSCat is the module take control of CAT1/CAT2/CAT3 count
*/
extern void FSCat_Init(void);
/**
 * @brief DeInit FSCat module
*/
extern void FSCat_DeInit(void);
/**
 * @brief Get the number of Cat3 count.
 * @retval the CAT3 number
*/
extern fs_cat_count_t FSCat_Cat3Count(void);
/**
 * Cat2 record dem is done at where calles FSCat_Cat2Increase
*/
// void FSCat_RecordCat2(fs_catx_id_t cat2id);

/**
 * @brief Add a CAT3 error
 * 
 * The cat3 id is stored in internel.
 * Calling `FSCat_Cat3Count` for getting current total number of CAT3s;
 * 
 * After calling `FSCat_ClearCat3`,the correspond cat3 will be cleared.
 * 
 * @param cat3id the cat3id,it is either a Dem_EventIdType or FS_CAT3_XX
 * 
*/
extern void FSCat_AddCat3(fs_catx_id_t cat3id);

/**
 * @brief Clear a CAT3 error
 * 
 * Clear the cat3 id stored in internel.
 * 
 * @param cat3id the cat3id,it is either a Dem_EventIdType or FS_CAT3_XX
 * 
*/
extern void FSCat_ClearCat3(fs_catx_id_t cat3id);
/**
 * @brief Check is the cat3 is allready stored
 * 
 * Check is the cat3 is allready stored
 * 
 * @param cat3id the cat3id,it is either a Dem_EventIdType or FS_CAT3_XX
 * @retval true the CAT3 is allready stored,false not recorded.
 * 
*/
extern bool FSCat_HasCat3(fs_catx_id_t cat3id);

#define FS_STOP_SEC_CODE_LOCAL
#include "Fs_MemMap.h"

#endif /** FS_CATX_H */