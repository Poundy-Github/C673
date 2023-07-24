/**
 * \file ModM.h
 *
 * \brief  Ecu Mode management
 *
 * \version
 * --------------------------------------------------------------------------------------------
 * Version	| 		Date		|		Author			| 	Comments
 * V0.0.1		2023.05.25			Jinlong Zhang			Init version
 *
 *
 */

#ifndef _MODM_H_ 
#define _MODM_H_ //PRQA S 0602,0603
/*==================[inclusions]============================================*/
#include "Std_Types.h" /* AUTOSAR standard types */
#include "ModM_cfg.h"
#include "Det.h"

#define MODM_MODEINDEX                                               (((uint8)ModM_MAX) - 1u)

#define MODM_MODULE_ID                                               (0x201u)
#define MODM_INSTANCE_ID                                             (1u)
#define MODM_INSTANCE_ID_DET                                         (MODM_INSTANCE_ID)

/*Application id*/
#define MODM_API_ID_INIT                                             (0u)
#define MODM_API_ID_MAIN                                             (1u)
/*Error Code id */
#define MODM_ERROR_CODE_OUTOFRANGE                                   (0u)
#define MODM_ERROR_CODE_UNINIT                                       (1u)
#define MODM_ERROR_CODE_STATE_ERR                                    (2u)
#define MODM_ERROR_CODE_NULL_PTR                                     (3u)

/*
* Mapping of error reporting macro
*/
#if (MODM_DEV_ERROR_DETECT == STD_ON)

#define MODM_DET_REPORTERROR(API_ID, ERROR_CODE) \
    ((void)Det_ReportError((uint16)MODM_MODULE_ID, (uint8)MODM_INSTANCE_ID_DET, (uint8)(API_ID), (uint8)(ERROR_CODE)))
#else

#define MODM_DET_REPORTERROR(API_ID, ERROR_CODE) \
    /*Define an void function*/
#endif

/** \brief Function point type for access to the operation mode of a logical
 ** expression. */
typedef P2FUNC(void, TYPEDEF, OperationModeCalloutFunc)(void); /*PRQA S 3432*/


/*==================[type definitions]=======================================*/
typedef enum
{
    ModM_Normal  = 0x01,
	ModM_Trans   = 0x02,
	ModM_Test    = 0x03,
	ModM_Debug   = 0x04,
    ModM_Factory = 0x05, 
    ModM_MAX
}e_ModM_Operationmode_t;

typedef struct
{
	e_ModM_Operationmode_t State;
	 OperationModeCalloutFunc SetOp;
}s_ModM_Config_t;

typedef struct
{
	e_ModM_Operationmode_t currentstate;
	e_ModM_Operationmode_t NextState;
}s_ModM_InstStruct_t;

/*==================[macros definitions]====================================*/

#define GET_ModM_CurrentState()     (s_ModM_handle.currentstate) /*PRQA S 3472*/

#define SET_ModM_CurrentState(val)  (s_ModM_handle.currentstate = val)

#define GET_ModM_NextState()        (s_ModM_handle.NextState) /*PRQA S 3472*/

#define SET_ModM_NextState(val)     (s_ModM_handle.NextState = val)

/*==================[external constants declarations]========================*/


/*==================[external data declarations]=============================*/
#define ModM_START_SEC_CONST
#include <ModM_MemMap.h>
extern const s_ModM_Config_t s_ModM_Config[ModM_MAX-1]; /*PRQA S 4521*/
#define ModM_STOP_SEC_CONST
#include <ModM_MemMap.h>


/*==================[external function declarations]=========================*/
#define ModM_START_SEC_CODE
#include <ModM_MemMap.h>
extern FUNC(void, RTE_CODE) ModM_InitFunction(const s_ModM_Config_t * const ConfigPtr);
extern FUNC(void, RTE_CODE) ModM_MainExec(void);
extern FUNC(Std_ReturnType, RTE_CODE) ModM_u_GetCurrentMode(uint8 * const mode);
extern FUNC(Std_ReturnType, RTE_CODE) ModM_u_GetNextMode(uint8 * const mode);
#define ModM_STOP_SEC_CODE
#include <ModM_MemMap.h>

#endif /*_MODM_H_*/



