/**
 * \file fs_adc.h
 *
 * \brief
 *
 * \version
 * --------------------------------------------------------------------------------------------
 * Version	| 		Date		|		Author			| 	Comments
 * V0.0.1		2022.01.04			    xxx			       Init version
 *
 * \copyright  2021 - 2022 Conti Smart Core
 * 
 */
#ifndef _FS_ADC_H_
#define _FS_ADC_H_

/*==================[inclusions]============================================*/
#include <Std_Types.h>                            /* AUTOSAR standard types */

/*==================[macros definitions]====================================*/
#define FS_ADC_CHANNEL_VOLT_BATT             (0U)
#define FS_ADC_CHANNEL_VOLT_IGN              (1U)
#define FS_ADC_CHANNEL_VOLT_OM_1V0           (2U)
#define FS_ADC_CHANNEL_VOLT_OM_3V3           (3U)
#define FS_ADC_CHANNEL_TEMP_MCU_EXT          (4U)
#define FS_ADC_CHANNEL_TEMP_SOC_EXT          (5U)
#define FS_ADC_CHANNEL_TEMP_PMIC_FS84        (6U)
#define FS_ADC_CHANNEL_TEMP_PMIC_PF8200      (7U)
#define FS_ADC_CHANNEL_NUM                   (8U)


#define FS_ADC_STATUS_INVALID                (1U)
#define FS_ADC_STATUS_VALID                  (0U)


/*==================[type definitions]=======================================*/
/*
 * \brief 	s_FSAdcInfo_t,
 *			Store the adc value and status in data buffer.
 * */

typedef struct
{
    uint32  Status;
    float   Value;
}s_FSAdcInfo_t;

/*==================[external constants declarations]========================*/

/*==================[external data declarations]=============================*/

/*==================[external function declarations]=========================*/

#define FS_START_SEC_CODE_LOCAL
#include "Fs_MemMap.h"

extern void FSAdc_InitFunction(void);
extern void FSAdc_MainFunction(void);
extern void FSAdc_SelfCheckMainFunction(void);
extern Std_ReturnType FSAdc_ReadChannel(uint8 Channel, float* Value);

#define FS_STOP_SEC_CODE_LOCAL
#include "Fs_MemMap.h"


#endif /*_FS_ADC_H_*/
