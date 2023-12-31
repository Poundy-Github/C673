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
 * on Sat Jan 15 20:42:44 CST 2022. !!!IGNORE-LINE!!!
 */

/*
 * \addtogroup Rte Runtime Environment
 * @{
 */

/* ==================[Includes]=============================================== */
#include <Rte_VdyAdapter.h>
#include "VdyAdapter.h"
#include "vdy_ext.h"
#include "Ioc_gen.h"
#include "CSC_Platform_Common.h"
/*****************************************************************************
  Meas Freeze Virtual Addr Define
*****************************************************************************/
#define VDY_MEAS_ADDR_VEHSIG 		(0xA0100000u)
#define VDY_MEAS_ADDR_VEHPAR 		(0xA0101000u)
#define VDY_MEAS_ADDR_NV_IN 		(0xA0105000u)
#define VDY_MEAS_ADDR_VEHDYN 		(0xA0102000u)
#define VDY_MEAS_ADDR_OFFSET 		(0xA0103000u)
#define VDY_MEAS_ADDR_ERRORS 		(0xA0104000u)
#define VDY_MEAS_ADDR_NV_OUT 		(0xA0106000u)

/*****************************************************************************
  PDO
*****************************************************************************/
#ifdef __PDO__
/****** Vdy In******/
/*! @VADDR: VDY_MEAS_ADDR_VEHSIG @CYCLEID: CycleId_21 */
typedef VehSig_t Vdy_VehSig;
/*! @VADDR: VDY_MEAS_ADDR_VEHPAR @CYCLEID: CycleId_21 */
typedef VehPar_t Vdy_VehPar;
/*! @VADDR: VDY_MEAS_ADDR_NV_IN  @CYCLEID: CycleId_21 */
typedef VDYNvIoData_t VDYNvIoData_t_In;
/****** Vdy Out******/
/*! @VADDR: VDY_MEAS_ADDR_VEHDYN @CYCLEID: CycleId_21 */
typedef VehDyn_t Vdy_VehDyn;
/*! @VADDR: VDY_MEAS_ADDR_OFFSET @CYCLEID: CycleId_21 */
typedef VDYOffsets_t Vdy_VDYOffsets;
/*! @VADDR: VDY_MEAS_ADDR_ERRORS @CYCLEID: CycleId_21 */
typedef VDYErrors_t Vdy_VDYErrors_t;
/*! @VADDR: VDY_MEAS_ADDR_NV_OUT @CYCLEID: CycleId_21 */
typedef VDYNvIoData_t VDYNvIoData_t_Out;
#endif
/*==================[internal data]=========================================*/
#if (DBG_VDYADAPTER_DEBUG_ENABLE == STD_ON)
uint32 Debug_VdyAdapter_MainFunction_Counter;
uint32 Debug_VdyAdapter_VdyAdapter_VdyExec_Counter;
s_Time_RunCycleMeas_t Debug_VdyAdapter_VdyAdapter_VdyExec_Cycle;
s_Time_RunIntervalMeas_t Debug_VdyAdapter_VdyAdapter_VdyExec_RunInterval;
#endif/*DBG_VDYADAPTER_DEBUG_ENABLE*/

float32 Debug_VdyAdapter_LcfLaneChange_Velocity_ReadOnly; 
#if (DBG_VDYADAPTER_ALGO_ENABLE == STD_ON)
/*TODO : Definition of function parameters*/
reqVdyPrtList_t VdyAdapter_reqVdyPrtList;
proVdyPrtList_t VdyAdapter_proVdyPrtList;
AS_t_ServiceFuncts VdyAdapter_ServiceFunctions;

/*TODO : Data element shall mapping the reqVdyPrtList_t or proVdyPrtList_t*/
BaseCtrlData_t VdyAdapter_BaseCtrlData;//In
VDYNvIoData_t VdyAdapter_VdyNvMData_In;//In
VehSig_t VdyAdapter_VehInputSig;//In
VehPar_t VdyAdapter_VehPar;//In

AlgoCompState_t VdyAdapter_AlgoCompState;//Out
VDYErrors_t VdyAdapter_VdyErrors;//Out
VDYEstCurves_t VdyAdapter_VdyEstCurves;//Out
VDYOffsets_t VdyAdapter_VdyOffsets;//Out
VehDyn_t VdyAdapter_VehDyn;//Out
VDYNvIoData_t VdyAdapter_VdyNvMData_Out;//Out

extern VehDyn_t 		MtsiAdapter_VdyAdapter_VehDyn;//Out
extern VDYOffsets_t 	MtsiAdapter_VdyAdapter_VdyOffsets;//Out
extern VDYErrors_t 		MtsiAdapter_VdyAdapter_VdyErrors;//Out
extern VDYNvIoData_t 	MtsiAdapter_VdyAdapter_VdyNvMData_Out;//Out
#endif/*DBG_VDYADAPTER_ALGO_ENABLE*/

/*==================[internal function declarations]========================*/
#if (DBG_VDYADAPTER_ALGO_ENABLE == STD_ON)
AS_t_MeasReturn VdyAdapter_Cot_MeasHdlr(const AS_t_MeasInfo * const meas_info, const void * data, AS_t_MeasCallback callback);
AS_t_Dem_ReturnType VdyAdapter_Cot_Dem_SetEventStatus (const AS_t_Dem_EventIDType u_Dem_EventIdRaw,const AS_t_Dem_EventStatusType u_Dem_EventStatus);
AS_t_Dem_ReturnType VdyAdapter_Cot_Dem_SetEventStatusPreExtData (const AS_t_Dem_EventIDType u_Dem_EventIdRaw,const AS_t_Dem_EventStatusType u_Dem_EventStatus,const uint8* const p_Dem_pui8_PreExtData,uint8 u_Dem_PreExtDataSize);
sint32 VdyAdapter_Cot_RTAAlgoServiceAddEvent(const AS_t_RtaEventType RtaEvtType, const uint8 u_IdGlobal, const uint8 u_IdLocal, const uint8 u_OptData);
AS_t_MeasErrors VdyAdapter_Cot_MeasStartFuncCycle(const AS_t_MeasFuncID id);
static void VdyAdapter_Mtsi(uint32 VirtAdd, uint8 funcid, pvoid data_p, uint32 length);
static void VdyAdapter_MTSI_FreezeData_Proxy_21_In(void);
static void VdyAdapter_MTSI_FreezeData_Proxy_21_Out(void);
#endif

/* ==================[Definition of functions with external linkage]========== */
/* ------------------------[runnable entity skeletons]------------------------ */
FUNC(void, RTE_CODE) VdyAdapter_InitFunction (void)
{
#if (DBG_VDYADAPTER_ALGO_ENABLE == STD_ON)

	/*TODO : Clean the variable*/
	(void)memset(&VdyAdapter_reqVdyPrtList, 0x00, sizeof(reqVdyPrtList_t));//Input list
	(void)memset(&VdyAdapter_proVdyPrtList, 0x00, sizeof(proVdyPrtList_t));//Output list
	(void)memset(&VdyAdapter_ServiceFunctions, 0x00, sizeof(AS_t_ServiceFuncts));//Service function list
	(void)memset(&VdyAdapter_BaseCtrlData, 0x00, sizeof(BaseCtrlData_t));//In
	(void)memset(&VdyAdapter_VdyNvMData_In, 0x00, sizeof(VDYNvIoData_t));//In
	(void)memset(&VdyAdapter_VehInputSig, 0x00, sizeof(VehSig_t));//In
	(void)memset(&VdyAdapter_VehPar, 0x00, sizeof(VehPar_t));//In
	(void)memset(&VdyAdapter_AlgoCompState, 0x00, sizeof(AlgoCompState_t));//Out
	(void)memset(&VdyAdapter_VdyErrors, 0x00, sizeof(VDYErrors_t));//Out
	(void)memset(&VdyAdapter_VdyEstCurves, 0x00, sizeof(VDYEstCurves_t));//Out
	(void)memset(&VdyAdapter_VdyOffsets, 0x00, sizeof(VDYOffsets_t));//Out
	(void)memset(&VdyAdapter_VehDyn, 0x00, sizeof(VehDyn_t));//Out
    (void)memset(&VdyAdapter_VdyNvMData_Out, 0x00, sizeof(VDYNvIoData_t));//Out

	/*TODO : Mapping local variable to pointer of VdyAdapter_reqVdyPrtList*/
	VdyAdapter_reqVdyPrtList.pBaseCtrlData = &VdyAdapter_BaseCtrlData;
	VdyAdapter_reqVdyPrtList.pNVMRead = &VdyAdapter_VdyNvMData_In;
	VdyAdapter_reqVdyPrtList.pVehicleInputSignals = &VdyAdapter_VehInputSig;
	VdyAdapter_reqVdyPrtList.pVehicleParameter = &VdyAdapter_VehPar;

	/*TODO : Mapping local variable to pointer of VdyAdapter_proVdyPrtList*/
	VdyAdapter_proVdyPrtList.pAlgoCompState = &VdyAdapter_AlgoCompState;
	VdyAdapter_proVdyPrtList.pNVMWrite = &VdyAdapter_VdyNvMData_Out;
	VdyAdapter_proVdyPrtList.pVDYErrors = &VdyAdapter_VdyErrors;
	VdyAdapter_proVdyPrtList.pVDYEstCurves = &VdyAdapter_VdyEstCurves;
	VdyAdapter_proVdyPrtList.pVDYOffsets = &VdyAdapter_VdyOffsets;
	VdyAdapter_proVdyPrtList.pVehicleDynamicSignals = &VdyAdapter_VehDyn;

	/*TODO : Mapping local variable to pointer of VdyAdapter_ServiceFunctions*/
	VdyAdapter_ServiceFunctions.pfMeasFreeze = VdyAdapter_Cot_MeasHdlr;
	VdyAdapter_ServiceFunctions.pfDem_SetEventStatus = VdyAdapter_Cot_Dem_SetEventStatus;
	VdyAdapter_ServiceFunctions.pfDem_SetEventStatusPreExtData = VdyAdapter_Cot_Dem_SetEventStatusPreExtData;
	VdyAdapter_ServiceFunctions.pfRTAAlgoServiceAddEvent = VdyAdapter_Cot_RTAAlgoServiceAddEvent;
	VdyAdapter_ServiceFunctions.pfMeasStartFuncCycle = VdyAdapter_Cot_MeasStartFuncCycle;

	Rte_Read_RP_Cdm_VdyInputNvMData_VdyNvMInOutData(&VdyAdapter_VdyNvMData_In);

#endif/*DBG_VDYADAPTER_ALGO_ENABLE*/
} /* FUNC(void, RTE_CODE) VdyAdapter_InitFunction (void) */

FUNC(void, RTE_CODE) VdyAdapter_MainFunction (void)
{
#if	(DBG_VDYADAPTER_DEBUG_ENABLE ==STD_ON)
	Debug_VdyAdapter_MainFunction_Counter++;
    Time_MeasRunCycleTimeMs(&Debug_VdyAdapter_VdyAdapter_VdyExec_Cycle);
    Time_MeasRunIntervalTimeMs_Start(&Debug_VdyAdapter_VdyAdapter_VdyExec_RunInterval);
#endif

} /* FUNC(void, RTE_CODE) VdyAdapter_MainFunction (void) */

FUNC(void, RTE_CODE) VdyAdapter_VdyExec (void)
{
#if	(DBG_VDYADAPTER_DEBUG_ENABLE ==STD_ON)
	Debug_VdyAdapter_VdyAdapter_VdyExec_Counter++;
#endif
#if (DBG_VDYADAPTER_ALGO_ENABLE == STD_ON)

	/*TODO : Get the Input data from Rte*/
    Rte_Read_RP_Fcu_BaseCtrlData_BaseCtrlData(&VdyAdapter_BaseCtrlData);
    // Ioc_Read_Ioc_BaseCtrlData(&VdyAdapter_BaseCtrlData);
	Rte_Read_RP_Fcu_VehSig_VehSig(&VdyAdapter_VehInputSig);
    //Ioc_Read_Ioc_VehSig(&VdyAdapter_VehInputSig);
	Rte_Read_RP_Fcu_VehPar_VehPar(&VdyAdapter_VehPar);
    //Ioc_Read_Ioc_VehPar(&VdyAdapter_VehPar);

#	if(DBG_VDYADAPTER_MEASFREEZE_ENABLE == STD_ON)
	(void)MTSI_DriverStartTaskCycle(2); //For vdy_main.c internally use.
	(void)MTSI_DriverStartTaskCycle(21);
	VdyAdapter_MTSI_FreezeData_Proxy_21_In();
#	endif
    /*suspend interrupt*/
	// SuspendAllInterrupts();
	/*TODO : Call the main logic function*/
	/*VDY should log meas freeze data trough VdyAdapter_ServiceFunctions*/
	VdyExec(&VdyAdapter_reqVdyPrtList, &VdyAdapter_proVdyPrtList, &VdyAdapter_ServiceFunctions);
	/*resume interrupt*/
	// ResumeAllInterrupts();
	
	/*TODO : re-mapping,because the data type is mixed*/
	VdyAdapter_VehDyn.Longitudinal.MotVar.Velocity = VdyAdapter_VehDyn.Longitudinal.Velocity;
	VdyAdapter_VehDyn.Longitudinal.MotVar.Accel = VdyAdapter_VehDyn.Longitudinal.Accel;
	VdyAdapter_VehDyn.Longitudinal.MotVar.varVelocity = VdyAdapter_VehDyn.Longitudinal.varVelocity;
	VdyAdapter_VehDyn.Longitudinal.MotVar.varAccel = VdyAdapter_VehDyn.Longitudinal.varAccel;
	VdyAdapter_VehDyn.Longitudinal.VeloCorr.corrVelo = VdyAdapter_VehDyn.Longitudinal.Velocity;

	Debug_VdyAdapter_LcfLaneChange_Velocity_ReadOnly = VdyAdapter_VehDyn.Longitudinal.Velocity;

	/*TODO : set the output data To Rte*/
	// Rte_Write_PP_VdyAdapter_AlgoCompState_AlgoCompState(&VdyAdapter_AlgoCompState);
	// Rte_Write_PP_VdyAdapter_VdyErrors_VdyErrors(&VdyAdapter_VdyErrors);
	// Rte_Write_PP_VdyAdapter_VdyEstCurves_VdyEstCurves(&VdyAdapter_VdyEstCurves);
	Rte_Write_PP_VdyAdapter_VdyOffsets_VdyOffsets(&VdyAdapter_VdyOffsets);
    //Ioc_Write_Ioc_VDYOffsets(VdyAdapter_VdyOffsets);
	Rte_Write_PP_VdyAdapter_VehDyn_VehDyn(&VdyAdapter_VehDyn);
    //Ioc_Write_Ioc_VehDyn(VdyAdapter_VehDyn);
    Rte_Call_RP_NvM_VdyBlockOperation_SetRamBlockStatus(TRUE);
	Rte_Write_PP_VdyAdapter_VdyOutputNvMData_VdyNvMInOutData(&VdyAdapter_VdyNvMData_Out);
	memcpy(&VdyAdapter_VdyNvMData_In, &VdyAdapter_VdyNvMData_Out, sizeof(VDYNvIoData_t));

#	if(DBG_VDYADAPTER_MEASFREEZE_ENABLE == STD_ON)
	/* Log Meas Freeze data as per VdyAdapter_VdyExec calling frequence.*/
	VdyAdapter_MTSI_FreezeData_Proxy_21_Out();
#	endif
#endif
#if	(DBG_VDYADAPTER_DEBUG_ENABLE ==STD_ON)
    Time_MeasRunIntervalTimeMs_End(&Debug_VdyAdapter_VdyAdapter_VdyExec_RunInterval);
#endif

} /* FUNC(void, RTE_CODE) VdyAdapter_VdyExec (void) */


/*==================[internal function definitions]=========================*/
#if (DBG_VDYADAPTER_ALGO_ENABLE == STD_ON)
AS_t_MeasReturn VdyAdapter_Cot_MeasHdlr(const AS_t_MeasInfo * const meas_info, const void * data, AS_t_MeasCallback callback)
{
#if(DBG_VDYADAPTER_MEASFREEZE_ENABLE == STD_ON)
	MEASFreezeDataMTS(meas_info, data, NULL_PTR);
#endif
	return 0;
}

AS_t_Dem_ReturnType VdyAdapter_Cot_Dem_SetEventStatus (const AS_t_Dem_EventIDType u_Dem_EventIdRaw,const AS_t_Dem_EventStatusType u_Dem_EventStatus)
{
	return 0;
}

AS_t_Dem_ReturnType VdyAdapter_Cot_Dem_SetEventStatusPreExtData (const AS_t_Dem_EventIDType u_Dem_EventIdRaw,const AS_t_Dem_EventStatusType u_Dem_EventStatus,
                                   const uint8* const p_Dem_pui8_PreExtData,
                                   uint8 u_Dem_PreExtDataSize)
{
	return 0;
}

sint32 VdyAdapter_Cot_RTAAlgoServiceAddEvent(const AS_t_RtaEventType RtaEvtType, const uint8 u_IdGlobal, const uint8 u_IdLocal, const uint8 u_OptData)
{
	return 0;
}

AS_t_MeasErrors VdyAdapter_Cot_MeasStartFuncCycle(const AS_t_MeasFuncID id)
{
	/*mapped task id MTSI_DriverStartTaskCycle(id)*/
#if(DBG_VDYADAPTER_MEASFREEZE_ENABLE == STD_ON)
	(void)MTSI_DriverStartTaskCycle(20);
#endif
	return 0;
}
static void VdyAdapter_Mtsi(uint32 VirtAdd, uint8 funcid, pvoid data_p, uint32 length)
{
	AS_t_MeasInfo meas_info;
	meas_info.VirtualAddress = VirtAdd;
	meas_info.Length = length;
	meas_info.FuncID = funcid;
	MEASFreezeDataMTS(&meas_info, data_p, NULL_PTR);
}
static void VdyAdapter_MTSI_FreezeData_Proxy_21_In(void)
{
	VdyAdapter_Mtsi(VDY_MEAS_ADDR_VEHSIG	,21,&VdyAdapter_VehInputSig		,sizeof(VdyAdapter_VehInputSig));
	VdyAdapter_Mtsi(VDY_MEAS_ADDR_VEHPAR	,21,&VdyAdapter_VehPar			,sizeof(VdyAdapter_VehPar));
	VdyAdapter_Mtsi(VDY_MEAS_ADDR_NV_IN		,21,&VdyAdapter_VdyNvMData_In	,sizeof(VdyAdapter_VdyNvMData_In));
}
static void VdyAdapter_MTSI_FreezeData_Proxy_21_Out(void)
{
	MtsiAdapter_VdyAdapter_VehDyn			=	VdyAdapter_VehDyn			;
	MtsiAdapter_VdyAdapter_VdyOffsets		=	VdyAdapter_VdyOffsets		;
	MtsiAdapter_VdyAdapter_VdyErrors		=	VdyAdapter_VdyErrors		;
	MtsiAdapter_VdyAdapter_VdyNvMData_Out	=	VdyAdapter_VdyNvMData_Out	;
	VdyAdapter_Mtsi(VDY_MEAS_ADDR_VEHDYN	,21,&MtsiAdapter_VdyAdapter_VehDyn			,sizeof(MtsiAdapter_VdyAdapter_VehDyn));
	VdyAdapter_Mtsi(VDY_MEAS_ADDR_OFFSET	,21,&MtsiAdapter_VdyAdapter_VdyOffsets		,sizeof(MtsiAdapter_VdyAdapter_VdyOffsets));
	VdyAdapter_Mtsi(VDY_MEAS_ADDR_ERRORS	,21,&MtsiAdapter_VdyAdapter_VdyErrors		,sizeof(MtsiAdapter_VdyAdapter_VdyErrors));
	VdyAdapter_Mtsi(VDY_MEAS_ADDR_NV_OUT	,21,&MtsiAdapter_VdyAdapter_VdyNvMData_Out	,sizeof(MtsiAdapter_VdyAdapter_VdyNvMData_Out));
}

#endif
/* ==================[end of file]============================================ */
