/**
 * \file Cdd_EvAdc_Cfg.h
 *
 * \brief
 *
 * \version
 * --------------------------------------------------------------------------------------------
 * Version	| 		Date		|		Author			| 	Comments
 * V0.0.1		2022.01.04			Xiong Yating			Init version
 *
 * \copyright  2021 - 2022 Conti Smart Core
 * 
 */
#ifndef _CDD_EVADC_CFG_H_
#define _CDD_EVADC_CFG_H_

/*==================[inclusions]============================================*/
#include "Adc.h"
#include "Dma.h"
#include "Platform_Types.h"

/*==================[macros definitions]====================================*/

/*
 * \brief 	EVADC_SW_MAJOR_VERSION,
 * */
#ifndef EVADC_SW_MAJOR_VERSION
#define EVADC_SW_MAJOR_VERSION			(0u)
#endif

/*TODO : Check the version number range*/
#if (EVADC_SW_MAJOR_VERSION > 99)
#error EVADC_SW_MAJOR_VERSION out of range
#endif

/*
 * \brief 	EVADC_SW_MINOR_VERSION,
 * */
#ifndef EVADC_SW_MINOR_VERSION
#define EVADC_SW_MINOR_VERSION			(0u)
#endif

/*TODO : Check the version number range*/
#if (EVADC_SW_MINOR_VERSION > 99)
#error EVADC_SW_MINOR_VERSION out of range
#endif

/*
 * \brief 	EVADC_SW_PATCH_VERSION,
 * */
#ifndef EVADC_SW_PATCH_VERSION
#define EVADC_SW_PATCH_VERSION			(1u)
#endif

/*TODO : Check the version number range*/
#if (EVADC_SW_PATCH_VERSION > 99)
#error EVADC_SW_PATCH_VERSION out of range
#endif

/*Total number of signals to measure*/
#define EVADC_SIGNAL_NUMBER_ALL                 (8u)
/* number of Group 0 channel*/
#define EVADC_GROUP0_CHANNEL_NUMBER             (4u)
/* number of Group 2 channel*/
#define EVADC_GROUP2_CHANNEL_NUMBER             (4u)
/*Whether to enable calibration*/
#define EVADC_CALIBRATION_SWITCH                (STD_ON)

/*Used Dma channel id*/
#define EVADC_GROUP0_USED_DMA_CHANNEL_ID        (0u)
#define EVADC_GROUP2_USED_DMA_CHANNEL_ID        (1u)

/*AN Channel id*/
#define EVADC_VMON_BATT_AN0                     (0u)
#define EVADC_VMON_IGN_AN1                      (1u)
#define EVADC_J3_PMIC_8200_AMUX_OUT_AN3         (2u)
#define EVADC_PMIC_FS84_AMUX_OUT_AN4            (3u)
#define EVADC_VMON_1V0_GEPHY_AN17               (4u)
#define EVADC_VMON_3V3_GEPHY_AN19               (5u)
#define EVADC_TMON_SYS1_SOC_J3_TEMP_AN20        (6u)
#define EVADC_TMON_SYS2_MCU_TEMP_AN21           (7u)

#define EVADC_VOLT_REFERENCE                    (3.3f)

#define EVADC_NTC_TABLE_NUM                     (191u)

/*define DMA Transfer Data Type*/
typedef unsigned short EVADC_DMA_U16_TYPE;
typedef unsigned long EVADC_DMA_U32_TYPE;
#define EVADC_DMA_TYPE                          EVADC_DMA_U16_TYPE

/*==================[type definitions]=======================================*/
typedef struct
{
    uint16 Volt;
    sint16 Temperature;
}s_EvAdc_NtcType_t;


/*==================[internal constants definition]=========================*/

#define EVADC_START_SEC_CORE0_QM_CONST
#include "EvAdc_MemMap.h"

extern const Adc_GroupType EvAdc_AdcGroupId0;
extern const Adc_GroupType EvAdc_AdcGroupId2;
extern const s_EvAdc_NtcType_t EvAdc_NtcTempTable[EVADC_NTC_TABLE_NUM];

#define EVADC_STOP_SEC_CORE0_QM_CONST
#include "EvAdc_MemMap.h"

/*==================[external constants declarations]========================*/

/*==================[external data declarations]=============================*/

/*==================[external function declarations]=========================*/

#endif /* _EVADC_H_ */
