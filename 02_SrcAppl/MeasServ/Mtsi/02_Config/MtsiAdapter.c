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
#include "lcf_veh_iface.h"
#include "lcf_sen_iface.h"
/*==================[external AEB data]=========================================*/
FCTCtrlData_t MtsiAdapter_FctMeasData_FctCtrlData;// 2
VehDyn_t MtsiAdapter_FctMeasData_VehDynData; //2 
VehPar_t MtsiAdapter_FctMeasData_VehParData; // 2
DIMInputGeneric_t MtsiAdapter_FctMeasData_DimInputGenericData;
DIMInputCustom_t  MtsiAdapter_FctMeasData_DimInputCustomData;
HypothesisIntf_t MtsiAdapter_FctMeasData_HypothesisIntf_Veh;
HEADInputGeneric_t MtsiAdapter_FctMeasData_HeadInputGenericData;
HEADInputCustom_t MtsiAdapter_FctMeasData_HeadInputCustomData;
VehSig_t MtsiAdapter_FctMeasData_VehSigData;
FCTVehCustomInput_t MtsiAdapter_FctMeasData_FctVehCustomInputData;

DIMOutputCustom_t MtsiAdapter_FctMeasData_DimOutputCustom;
LongCtrlOutput_t MtsiAdapter_FctMeasData_LongCtrlOutput;
HEADOutputGeneric_t MtsiAdapter_FctMeasData_HeadOutputGeneric;
HEADOutputCustom_t MtsiAdapter_FctMeasData_HeadOutputCustom;
FCTVehErrorOut_t MtsiAdapter_FctMeasData_FctVehErrorOut;
FctVeh2SenInfo_t MtsiAdapter_FctMeasData_FctVeh2SenInfo_Veh;

EmFctCycleMode_t MtsiAdapter_FctMeasData_FctCycleMode;
EM_t_GenObjectList MtsiAdapter_FctMeasData_GenObjectList;
EM_t_ARSObjectList MtsiAdapter_FctMeasData_ArsObjectList;
FctVeh2SenInfo_t MtsiAdapter_FctMeasData_FctVeh2SenInfo_Sen;
EM_t_FusionObjectList MtsiAdapter_FctMeasData_FusionObjectList;

AssessedObjList_t MtsiAdapter_FctMeasData_AssesedObjectList;
SysPerfMonStates_t MtsiAdapter_FctMeasData_SysPerfMonStates;
FCTCustomOutput_t MtsiAdapter_FctMeasData_FCTCustomOutput;
FCTCDOutputCustom_t MtsiAdapter_FctMeasData_FctCdOutputCustomData;
HypothesisIntf_t MtsiAdapter_FctMeasData_HypothesisIntf_Sen;
FCTSenErrorOut_t MtsiAdapter_FctMeasData_FctSenErrorOut;
/*==================[external LCF data]=========================================*/
AlgoCompState_t MtsiAdapter_LcfAdapter_AlgoCompState_Sen;
LCF_SenGenericOutputs_t MtsiAdapter_LcfAdapter_LcfSenOutputData_SenOut;
LCF_SenToVeh_t MtsiAdapter_LcfAdapter_LcfVehInputFromSenData_SenOut;
/*==================[external VDY data]=========================================*/
VehDyn_t MtsiAdapter_VdyAdapter_VehDyn;//Out
VDYOffsets_t MtsiAdapter_VdyAdapter_VdyOffsets;//Out
VDYErrors_t MtsiAdapter_VdyAdapter_VdyErrors;//Out
VDYNvIoData_t MtsiAdapter_VdyAdapter_VdyNvMData_Out;//Out
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
	// Mtsi_UpdateViaSTM0Time_Ns();//Make sure at least Update current time every main function cycle
	// Mtsi_UpdateViaSTM1Time_Ns();
	// Mtsi_UpdateViaSTM2Time_Ns();
	// Mtsi_UpdateViaSTM3Time_Ns();
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



