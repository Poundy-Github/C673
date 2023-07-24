/**
 * \file
 *
 * \brief AUTOSAR Rte
 *
 * This file contains the implementation of the AUTOSAR
 * module Rte.
 *
 * \version 6.4.3
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2020 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

/*
 * This file contains an Rte component template / example code
 *
 * This file has been automatically generated by
 * EB tresos AutoCore Rte Generator Version 6.4.3
 * on Thu Mar 10 17:32:52 CST 2022. !!!IGNORE-LINE!!!
 */

/*
 * \addtogroup Rte Runtime Environment
 * @{
 */

/* ==================[Includes]=============================================== */
#include "MtsiAdapter.h"
#include "algo_service_types.h"
#include <Rte_MtsiAdapter.h>
#include "CSC_Platform_Common.h"
#include "MTSI.h"
#include "MTSI_Pal.h"
#include "HSSL_HSCT_Cfg.h"
#include "MTSI_Cfg.h"

/*==================[internal data]=========================================*/
#if (MTSIADAPTER_DEBUG_ENABLE == STD_ON)
uint32 MtsiAdapter_MainFunction_Counter;
s_Time_RunCycleMeas_t Debug_MtsiAdapter_Cycle;
s_Time_RunIntervalMeas_t Debug_MtsiAdapter_RunInterval;
#endif
/*==================[internal function declarations]========================*/
/*==================[external function definitions]=========================*/
FUNC(void, RTE_CODE) MtsiAdapter_InitFunction (void)
{
#if (MTSIADAPTER_DEBUG_ENABLE == STD_ON)
	MtsiAdapter_MainFunction_Counter = 0x00;
#endif

#if (MTSIADAPTER_FUNCTION_ENABLE == STD_ON)

#	ifdef CFG_MTSI_AURIX_TC38X
	HSCT_Init(&HSCT_Cfg);
	HSSL_Init(&HSSL_Cfg);
#	endif
	MTSI_Init();

#endif
}

FUNC(void, RTE_CODE) MtsiAdapter_MainFunction (void)
{
#if (MTSIADAPTER_DEBUG_ENABLE == STD_ON)
    Time_MeasRunCycleTimeMs(&Debug_MtsiAdapter_Cycle);
    Time_MeasRunIntervalTimeMs_Start(&Debug_MtsiAdapter_RunInterval);
	MtsiAdapter_MainFunction_Counter++;
#endif

#if (MTSIADAPTER_FUNCTION_ENABLE == STD_ON)

#	ifdef CFG_MTSI_AURIX_TC38X 
	HSCT_MainFunction();
	HSSL_MainFunction();
# 	endif

	MTSI_StartMtaCycle();
	MTSI_StartTaskCycle_BSWCyclic();
	MTSI_MainFunction();
#endif

#if (MTSIADAPTER_DEBUG_ENABLE == STD_ON)
    Time_MeasRunIntervalTimeMs_End(&Debug_MtsiAdapter_RunInterval);
#endif
}

FUNC(void, RTE_CODE) CDD_MTSI_Callback (void)
{
	(void)CDD_MTSI_Tx_Callback();
}

FUNC(Std_ReturnType, RTE_CODE) MtsiAdapter_MeasFreezeData (uint32_t VirtualAddress, uint32_t FunctionId, VoidPtr_t Data, uint32_t Length)
{
#if (MTSIADAPTER_FUNCTION_ENABLE == STD_ON)
	AS_t_MeasInfo meas_info;

	meas_info.VirtualAddress = VirtualAddress;
	meas_info.Length = Length;
	meas_info.FuncID = (uint16)FunctionId;
	MEASFreezeDataMTS(&meas_info, Data, NULL_PTR);

#endif
	return RTE_E_OK;
}

FUNC(void, RTE_CODE) MtsiAdapter_UpdateTaskCycle (uint16_t TaskId)
{
#if (MTSIADAPTER_FUNCTION_ENABLE == STD_ON)
	(void)MTSI_DriverStartTaskCycle(TaskId);
#endif
}
/*==================[internal function definitions]=========================*/


