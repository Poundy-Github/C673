/**************************************************************************
This file is generated automatically by the RTE generator
Filename:	Rte_Dem.h
CESSAR-CT Version: 3.1.1.11
RTE Version: 3.2.0.1.3.0
Generated on:	Tue Feb 28 11:49:17 CET 2012
**************************************************************************/


#ifndef _RTE_Dem_H_
#define _RTE_Dem_H_



#ifdef RTE_APPLICATION_HEADER_FILE
	#ifndef RTE_C
		#error Multiple application header files included. 
	#endif /* RTE_C */
#endif /* RTE_APPLICATION_HEADER_FILE */

#define RTE_APPLICATION_HEADER_FILE
/* Multiple application header file must not be included in the same module [Satisfies_rte sws 1004], [Satisfies_rte sws 1006] */


#include "Rte_Type.h"
#include "Rte_Hook.h"   /*RTE trace API hook functions */


#ifdef __cplusplus
	extern "C" {
#endif /* __cplusplus */




#ifndef RTE_C
  typedef CONSTP2CONST(Rte_CDS_Dem, AUTOMATIC, RTE_CONST) Rte_Instance;
#endif /* RTE_C */

/* SWC:Dem Indirect API */
	/* The name of the instance handle is Rte_Inst_<c> [Satisfies_rte sws 3793]. */
extern CONST(Rte_CDS_Dem, RTE_CONST) Rte_Instance_Dem;

#ifndef RTE_C

	/*  Provided ports */



	/*  Required ports */


#endif



/* runnable entry points (symbol) */

extern void Dem_MainFunction (void); 
/* runnable entry points (symbol) for servers */
extern FUNC(Std_ReturnType, RTE_APPL_CODE) Dem_GetDTCStatusAvailabilityMask( OUT P2VAR(UInt8,AUTOMATIC,RTE_APPL_DATA) sam);
extern FUNC(Std_ReturnType, RTE_APPL_CODE) Dem_GetIndicatorStatus( IN VAR(UInt8,AUTOMATIC) parg0, OUT P2VAR(Dem_IndicatorStatusType,AUTOMATIC,RTE_APPL_DATA) IndicatorStatus);
extern FUNC(Std_ReturnType, RTE_APPL_CODE) Dem_SetEnableCondition( IN VAR(UInt8,AUTOMATIC) parg0, IN VAR(Boolean,AUTOMATIC) ConditionFulfilled);
extern FUNC(Std_ReturnType, RTE_APPL_CODE) Dem_SetOperationCycleState( IN VAR(Dem_OperationCycleIdType,AUTOMATIC) parg0, IN VAR(Dem_OperationCycleStateType,AUTOMATIC) CycleState);



/* application error code */
#ifndef RTE_E_CallbackControlDTCStatus_E_NOT_OK
  #define RTE_E_CallbackControlDTCStatus_E_NOT_OK 1
#endif
#ifndef RTE_E_CallbackDTCStatusChange_E_NOT_OK
  #define RTE_E_CallbackDTCStatusChange_E_NOT_OK 1
#endif
#ifndef RTE_E_EnvironmentalValues_E_NOT_OK
  #define RTE_E_EnvironmentalValues_E_NOT_OK 1
#endif
#ifndef RTE_E_StatusAvailabilityMask_E_NOT_OK
  #define RTE_E_StatusAvailabilityMask_E_NOT_OK 1
#endif
#ifndef RTE_E_IndicatorStatus_E_NOT_OK
  #define RTE_E_IndicatorStatus_E_NOT_OK 1
#endif
#ifndef RTE_E_EnableCondition_E_NOT_OK
  #define RTE_E_EnableCondition_E_NOT_OK 1
#endif
#ifndef RTE_E_OperationCycle_DEM_E_QUEUE_OVERFLOW
  #define RTE_E_OperationCycle_DEM_E_QUEUE_OVERFLOW 15
#endif
#ifndef RTE_E_OperationCycle_E_NOT_OK
  #define RTE_E_OperationCycle_E_NOT_OK 1
#endif



/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/COMPONENTTYPES/IntBehDem/RunEntDemMain/SSCP_DemControlDTCStatusChanged */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_CBControlDTCStatus_ControlDTCStatusChanged( IN VAR(Boolean,AUTOMATIC) status);
#ifndef RTE_C
  #define Rte_Call_CBControlDTCStatus_ControlDTCStatusChanged Rte_Call_Dem_CBControlDTCStatus_ControlDTCStatusChanged
#endif


/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/COMPONENTTYPES/IntBehDem/RunEntDemMain/SSCP_DemDTCStatusChanged */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_CBStatusDTC_RoELight_DTCStatusChanged( IN VAR(Dem_DTCType,AUTOMATIC) DTC, IN VAR(Dem_DTCKindType,AUTOMATIC) DTCKind, IN VAR(Dem_DTCStatusMaskType,AUTOMATIC) DTCStatusOld, IN VAR(Dem_DTCStatusMaskType,AUTOMATIC) DTCStatusNew);
#ifndef RTE_C
  #define Rte_Call_CBStatusDTC_RoELight_DTCStatusChanged Rte_Call_Dem_CBStatusDTC_RoELight_DTCStatusChanged
#endif


/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/COMPONENTTYPES/IntBehDem/RunEntDemMain/SSCP_DemGetCurrentOdometer */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_EnvironmentalValues_GetCurrentOdometer( OUT P2VAR(UInt32,AUTOMATIC,RTE_APPL_DATA) odometer);
#ifndef RTE_C
  #define Rte_Call_EnvironmentalValues_GetCurrentOdometer Rte_Call_Dem_EnvironmentalValues_GetCurrentOdometer
#endif


/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/COMPONENTTYPES/IntBehDem/RunEntDemMain/SSCP_DemGetExternalTesterStatus */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_EnvironmentalValues_GetExternalTesterStatus( OUT P2VAR(Boolean,AUTOMATIC,RTE_APPL_DATA) testerPresent);
#ifndef RTE_C
  #define Rte_Call_EnvironmentalValues_GetExternalTesterStatus Rte_Call_Dem_EnvironmentalValues_GetExternalTesterStatus
#endif


/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/COMPONENTTYPES/IntBehDem/RunEntDemMain/SSCP_DemBswGetAdcData */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_RPortDemBswGetAdcData_OPGetAdcData( IN VAR(uint8,AUTOMATIC) AdcChannel, OUT P2VAR(float32,AUTOMATIC,RTE_APPL_DATA) CalcVal, OUT P2VAR(uint32,AUTOMATIC,RTE_APPL_DATA) Timestamp);
#ifndef RTE_C
  #define Rte_Call_RPortDemBswGetAdcData_OPGetAdcData Rte_Call_Dem_RPortDemBswGetAdcData_OPGetAdcData
#endif






  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(RTE_t_AdcReads, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_Dem_RunEntDemMain_RPortDemAdcData_DEPAdcData(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntDemMain_RPortDemAdcData_DEPAdcData \
    Rte_IRead_Dem_RunEntDemMain_RPortDemAdcData_DEPAdcData

#endif









#ifdef __cplusplus
	} /* extern "C" */
#endif /* __cplusplus */


#endif
