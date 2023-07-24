/**
 * \file 
 *
 * \brief 
 *
 * \version 
 * --------------------------------------------------------------------------------------------
 * Version	| 		Date		|		Author			| 	Comments
 * V0.0.1		2022.01.04			    xxx			        Init version
 * 
 * \copyright  2021 - 2023 Conti Smart Core
 *
 */
/*==================[inclusions]============================================*/
#include "fs_common.h"
#include "esm/fs_adc.h"
#include <Rte_FSMonitor.h>
#include "Cdd_EvAdc.h"

/*==================[external constants definition]=========================*/


/*==================[internal constants definition]=========================*/


/*==================[external data definition]==============================*/


/*==================[internal data definition]==============================*/

#define FS_START_SEC_VAR_CLEARED_LOCAL
#include "Fs_MemMap.h"

static s_FSAdcInfo_t FS_AdcInfo[FS_ADC_CHANNEL_NUM] = { 0 };

#define FS_STOP_SEC_VAR_CLEARED_LOCAL
#include "Fs_MemMap.h"



/*==================[external function definitions]=========================*/\
#define FS_START_SEC_CODE_LOCAL
#include "Fs_MemMap.h"
/**
 * \functions FSAdc_InitFunction
 *
 * \brief
 *
 * \parameters-in none
 *
 * \parameters-out none
 *
 * \return none
 *
 * \comments
 *
 */
void FSAdc_InitFunction(void)
{
    FS_LOG_INFO("%s", "FS Adc Init");

    for(uint8 ui8_Channel = (uint8)0; ui8_Channel < FS_ADC_CHANNEL_NUM; ui8_Channel++)
    {
        FS_AdcInfo[ui8_Channel].Status = FS_ADC_STATUS_INVALID;
        FS_AdcInfo[ui8_Channel].Value = 0.0f;
    }
}

/**
 * \functions FSAdc_MainFunction
 *
 * \brief
 *
 * \parameters-in none
 *
 * \parameters-out none
 *
 * \return none
 *
 * \comments
 *
 */
void FSAdc_MainFunction(void)
{   
    FS_AdcInfo[FS_ADC_CHANNEL_VOLT_BATT].Status = Rte_Call_RP_Fs_EvAdc_GetValue_VMON_BATT_GetPhyValue(&FS_AdcInfo[FS_ADC_CHANNEL_VOLT_BATT].Value);
    FS_AdcInfo[FS_ADC_CHANNEL_VOLT_IGN].Status = Rte_Call_RP_Fs_EvAdc_GetValue_VMON_IGN_GetPhyValue(&FS_AdcInfo[FS_ADC_CHANNEL_VOLT_IGN].Value);
    FS_AdcInfo[FS_ADC_CHANNEL_TEMP_SOC_EXT].Status = Rte_Call_RP_Fs_EvAdc_GetValue_VMON_McuExtTemp_GetPhyValue(&FS_AdcInfo[FS_ADC_CHANNEL_TEMP_SOC_EXT].Value);
    FS_AdcInfo[FS_ADC_CHANNEL_TEMP_MCU_EXT].Status = Rte_Call_RP_Fs_EvAdc_GetValue_VMON_SocExtTemp_GetPhyValue(&FS_AdcInfo[FS_ADC_CHANNEL_TEMP_MCU_EXT].Value);
}

/**
 * \functions FSAdc_SelfCheckMainFunction
 *
 * \brief
 *
 * \parameters-in none
 *
 * \parameters-out none
 *
 * \return none
 *
 * \comments
 *
 */
void FSAdc_SelfCheckMainFunction(void)
{
    Cdd_EvAdc_MainFunction();
    FSAdc_MainFunction();
}

/**
 * \functions FSAdc_ReadChannel
 *
 * \brief
 *
 * \parameters-in none
 *
 * \parameters-out none
 *
 * \return none
 *
 * \comments
 *
 */
Std_ReturnType FSAdc_ReadChannel(uint8 Channel, float* Value)
{
    uint8 ui8_Ret = FALSE;
    
    if ((Channel < FS_ADC_CHANNEL_NUM) && (Value != NULL_PTR))
    {
        if (FS_AdcInfo[Channel].Status != FS_ADC_STATUS_INVALID)
        {
            /* ADC value is valid */
            *Value = FS_AdcInfo[Channel].Value;
            ui8_Ret = TRUE;
        }
    }

    return ui8_Ret;
}

#define FS_STOP_SEC_CODE_LOCAL
#include "Fs_MemMap.h"

