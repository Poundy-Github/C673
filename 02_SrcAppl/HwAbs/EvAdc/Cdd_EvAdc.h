/**
 * \file Cdd_EvAdc.h
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
#ifndef _CDD_EVADC_H_
#define _CDD_EVADC_H_

/*==================[inclusions]============================================*/
#include "Cdd_EvAdc_Cfg.h"

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
#define EVADC_SW_PATCH_VERSION			(4u)
#endif

/*TODO : Check the version number range*/
#if (EVADC_SW_PATCH_VERSION > 99)
#error EVADC_SW_PATCH_VERSION out of range
#endif


#define EVADC_CODE            


#define EVADC_MODULE_ID                                               (0x200u)
#define EVADC_INSTANCE_ID                                             (1u)
#define EVADC_INSTANCE_ID_DET                                         (EVADC_INSTANCE_ID)

/*Application id*/
#define EVADC_API_ID_INIT                                             (0u)
#define EVADC_API_ID_MAIN                                             (1u)
#define EVADC_API_ID_GETREGVALUE                                      (2u)
/*Error Code id */
#define EVADC_ERROR_CODE_CORE_ERR                                     (0u)
#define EVADC_ERROR_CODE_UNINIT                                       (1u)
#define EVADC_ERROR_CODE_CHANNEL_ERR                                  (2u)
#define EVADC_ERROR_CODE_NULL_PTR                                     (3u)

#define SchM_Enter_EvAdc_SyncLock                                     SuspendAllInterrupts
#define SchM_Exit_EvAdc_SyncLock                                      ResumeAllInterrupts


/*
* Mapping of error reporting macro
*/
#if (EVADC_DEV_ERROR_DETECT == STD_ON)

#define EVADC_DET_REPORTERROR(API_ID, ERROR_CODE) \
    ((void)Det_ReportError((uint16)EVADC_MODULE_ID, (uint8)EVADC_INSTANCE_ID_DET, (uint8)(API_ID), (uint8)(ERROR_CODE)))
#else

#define EVADC_DET_REPORTERROR(API_ID, ERROR_CODE) \
    /*Define an void function*/
#endif

/*==================[type definitions]=======================================*/
/*
 * \brief 	e_EVADC_InitStatus_t,
 *			When the status is Unint status,the software shall not run the main logic
 * */
typedef enum
{
	EVADC_InitStatus_None 		= 0x00,
	EVADC_InitStatus_Uninit 	= 0x01,
	EVADC_InitStatus_Init 		= 0x02,
	EVADC_InitStatus_Max 		= 0xFF
}e_EVADC_InitStatus_t;

/*
 * \brief 	s_EvAdcBaseBuffData_t,
 *			When the status is Unint status,the software shall not run the main logic
 * */
typedef struct
{
    uint16  RegValue;
    float32 PhyValue;
    const uint16 RegValueMin;
    const uint16 RegValueMax;
    uint8 Status;
}s_EvAdc_AdcBaseBuffData_t;


/*==================[external constants declarations]========================*/

/*==================[external data declarations]=============================*/

/*data with no initial value*/
#define EVADC_START_SEC_DSPR_CORE0_QM_VAR_CLEARED
#include "EvAdc_MemMap.h"

extern EVADC_DMA_TYPE EvAdc_DMADataBufferPtr[EVADC_SIGNAL_NUMBER_ALL];

#define EVADC_STOP_SEC_DSPR_CORE0_QM_VAR_CLEARED
#include "EvAdc_MemMap.h"


/*==================[external function declarations]=========================*/
#define EVADC_START_SEC_CORE0_QM_CODE
#include "EvAdc_MemMap.h"

extern void Cdd_EvAdc_InitFunction(void);
extern void Cdd_EvAdc_MainFunction(void);
extern FUNC(Std_ReturnType, RTE_CODE) Cdd_EvAdc_GetRegValue (uint8 channel, P2VAR(uint16, AUTOMATIC, RTE_APPL_DATA) value);
extern FUNC(Std_ReturnType, RTE_CODE) Cdd_EvAdc_GetRhyValue (uint8 channel, P2VAR(float32, AUTOMATIC, RTE_APPL_DATA) value);
extern FUNC(EVADC_DMA_TYPE, RTE_CODE) Cdd_EvAdc_GetRegValue100us (uint8 channel);
#define EVADC_STOP_SEC_CORE0_QM_CODE
#include "EvAdc_MemMap.h"

#endif /* _EVADC_H_ */
