/**************************************************************************
This file is generated automatically by the RTE generator
Filename:	Rte_SwcDemSc.h
CESSAR-CT Version: 3.1.1.11
RTE Version: 3.2.0.1.3.0
Generated on:	Wed Apr 04 18:14:39 CEST 2012
**************************************************************************/


#ifndef _RTE_SwcDemSc_H_
#define _RTE_SwcDemSc_H_



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
  typedef CONSTP2CONST(Rte_CDS_SwcDemSc, AUTOMATIC, RTE_CONST) Rte_Instance;
#endif /* RTE_C */

/* SWC:SwcDemSc Indirect API */
	/* The name of the instance handle is Rte_Inst_<c> [Satisfies_rte sws 3793]. */
extern CONST(Rte_CDS_SwcDemSc, RTE_CONST) Rte_Instance_SwcDemSc;

#ifndef RTE_C

	/*  Provided ports */



	/*  Required ports */


#endif



/* runnable entry points (symbol) */

extern void SwcDemSc_CheckStorageConditions (void); 
extern void SwcDemSc_GetIgnitionSignal (void); 
extern void SwcDemSc_HandleSysOdometer (void); 
extern void SwcDemSc_SetIgnitionCycle (void); 
extern void SwcDemSc_Chk_DEM_SL_ECU_LEVEL (void); 
extern void SwcDemSc_Chk_DEM_SL_NONE (void); 
extern void SwcDemSc_Chk_DEM_SL_NWCOM_NO_CL15 (void); 
extern void SwcDemSc_Chk_DEM_SL_NWCOM_WITH_CL15 (void); 
extern void SwcDemSc_Chk_DEM_SL_POWER_DIST (void); 
/* runnable entry points (symbol) for servers */
extern FUNC(Std_ReturnType, RTE_APPL_CODE) SwcDemSc_CallbackControlDTCStatus( IN VAR(Boolean,AUTOMATIC) status);
extern FUNC(Std_ReturnType, RTE_APPL_CODE) SwcDemSc_CallbackDTCStatusChange( IN VAR(Dem_DTCType,AUTOMATIC) DTC, IN VAR(Dem_DTCKindType,AUTOMATIC) DTCKind, IN VAR(Dem_DTCStatusMaskType,AUTOMATIC) DTCStatusOld, IN VAR(Dem_DTCStatusMaskType,AUTOMATIC) DTCStatusNew);
extern FUNC(Std_ReturnType, RTE_APPL_CODE) SwcDemSc_GetCurrentOdometer( OUT P2VAR(UInt32,AUTOMATIC,RTE_APPL_DATA) odometer);
extern FUNC(Std_ReturnType, RTE_APPL_CODE) SwcDemSc_GetExternalTesterStatus( OUT P2VAR(Boolean,AUTOMATIC,RTE_APPL_DATA) testerPresent);



/* application error code */
#ifndef RTE_E_EnableCondition_E_NOT_OK
  #define RTE_E_EnableCondition_E_NOT_OK 1
#endif
#ifndef RTE_E_IndicatorStatus_E_NOT_OK
  #define RTE_E_IndicatorStatus_E_NOT_OK 1
#endif
#ifndef RTE_E_OperationCycle_DEM_E_QUEUE_OVERFLOW
  #define RTE_E_OperationCycle_DEM_E_QUEUE_OVERFLOW 15
#endif
#ifndef RTE_E_OperationCycle_E_NOT_OK
  #define RTE_E_OperationCycle_E_NOT_OK 1
#endif
#ifndef RTE_E_CallbackControlDTCStatus_E_NOT_OK
  #define RTE_E_CallbackControlDTCStatus_E_NOT_OK 1
#endif
#ifndef RTE_E_CallbackDTCStatusChange_E_NOT_OK
  #define RTE_E_CallbackDTCStatusChange_E_NOT_OK 1
#endif
#ifndef RTE_E_EnvironmentalValues_E_NOT_OK
  #define RTE_E_EnvironmentalValues_E_NOT_OK 1
#endif



/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/COMPONENTTYPES/IntBehDemSc/Chk_DEM_SL_ECU_LEVEL/SSCP_EnCond_DEM_SL_ECU_LEVEL */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SwcDemSc_EnCond_DEM_SL_ECU_LEVEL_SetEnableCondition( IN VAR(UInt8,AUTOMATIC) parg0, IN VAR(Boolean,AUTOMATIC) ConditionFulfilled);
#ifndef RTE_C
  #define Rte_Call_EnCond_DEM_SL_ECU_LEVEL_SetEnableCondition Rte_Call_SwcDemSc_EnCond_DEM_SL_ECU_LEVEL_SetEnableCondition
#endif


/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/COMPONENTTYPES/IntBehDemSc/Chk_DEM_SL_NONE/SSCP_EnCond_DEM_SL_NONE */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SwcDemSc_EnCond_DEM_SL_NONE_SetEnableCondition( IN VAR(UInt8,AUTOMATIC) parg0, IN VAR(Boolean,AUTOMATIC) ConditionFulfilled);
#ifndef RTE_C
  #define Rte_Call_EnCond_DEM_SL_NONE_SetEnableCondition Rte_Call_SwcDemSc_EnCond_DEM_SL_NONE_SetEnableCondition
#endif


/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/COMPONENTTYPES/IntBehDemSc/Chk_DEM_SL_NWCOM_NO_CL15/SSCP_EnCond_DEM_SL_NWCOM_NO_CL15 */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SwcDemSc_EnCond_DEM_SL_NWCOM_NO_CL15_SetEnableCondition( IN VAR(UInt8,AUTOMATIC) parg0, IN VAR(Boolean,AUTOMATIC) ConditionFulfilled);
#ifndef RTE_C
  #define Rte_Call_EnCond_DEM_SL_NWCOM_NO_CL15_SetEnableCondition Rte_Call_SwcDemSc_EnCond_DEM_SL_NWCOM_NO_CL15_SetEnableCondition
#endif


/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/COMPONENTTYPES/IntBehDemSc/Chk_DEM_SL_NWCOM_WITH_CL15/SSCP_EnCond_SL_NWCOM_WITH_CL15 */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SwcDemSc_EnCond_DEM_SL_NWCOM_WITH_CL15_SetEnableCondition( IN VAR(UInt8,AUTOMATIC) parg0, IN VAR(Boolean,AUTOMATIC) ConditionFulfilled);
#ifndef RTE_C
  #define Rte_Call_EnCond_DEM_SL_NWCOM_WITH_CL15_SetEnableCondition Rte_Call_SwcDemSc_EnCond_DEM_SL_NWCOM_WITH_CL15_SetEnableCondition
#endif


/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/COMPONENTTYPES/IntBehDemSc/Chk_DEM_SL_POWER_DIST/SSCP_EnCond_DEM_SL_POWER_DIST */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SwcDemSc_EnCond_DEM_SL_POWER_DIST_SetEnableCondition( IN VAR(UInt8,AUTOMATIC) parg0, IN VAR(Boolean,AUTOMATIC) ConditionFulfilled);
#ifndef RTE_C
  #define Rte_Call_EnCond_DEM_SL_POWER_DIST_SetEnableCondition Rte_Call_SwcDemSc_EnCond_DEM_SL_POWER_DIST_SetEnableCondition
#endif


/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/COMPONENTTYPES/IntBehDemSc/CallbackDTCStatusChange/SSCP_IndStatus_DEM_IND_SC8_REL */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SwcDemSc_IndStatus_DEM_IND_SC8_RELEVANT_GetIndicatorStatus( IN VAR(UInt8,AUTOMATIC) parg0, OUT P2VAR(Dem_IndicatorStatusType,AUTOMATIC,RTE_APPL_DATA) IndicatorStatus);
#ifndef RTE_C
  #define Rte_Call_IndStatus_DEM_IND_SC8_RELEVANT_GetIndicatorStatus Rte_Call_SwcDemSc_IndStatus_DEM_IND_SC8_RELEVANT_GetIndicatorStatus
#endif


/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/COMPONENTTYPES/IntBehDemSc/SetIgnitionCycle/SSCP_OpCycle_DEM_IGNITION */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SwcDemSc_OpCycle_DEM_IGNITION_SetOperationCycleState( IN VAR(Dem_OperationCycleIdType,AUTOMATIC) parg0, IN VAR(Dem_OperationCycleStateType,AUTOMATIC) CycleState);
#ifndef RTE_C
  #define Rte_Call_OpCycle_DEM_IGNITION_SetOperationCycleState Rte_Call_SwcDemSc_OpCycle_DEM_IGNITION_SetOperationCycleState
#endif






#ifndef RTE_C
  #define Rte_InitValue_SwcDemSc_LocIgnition_Ign_Stat (7)
#endif

#ifndef RTE_C
  #define Rte_InitValue_SwcDemSc_LocIoDevice_Io_Stat (0)
#endif

#ifndef RTE_C
  #define Rte_InitValue_SwcDemSc_LocVoltage_SupBat_Volt (255)
#endif

#ifndef RTE_C
  #define Rte_InitValue_SwcDemSc_SysExtTester_DidA_ExtTest_Pres (FALSE)
#endif

#ifndef RTE_C
  #define Rte_InitValue_SwcDemSc_SysOdometer_Odo (16777215)
#endif

#ifndef RTE_C
  #define Rte_InitValue_SwcDemSc_SysTransportationMode_PN14_TransMd_Stat (3)
#endif

#ifndef RTE_C
  #define Rte_InitValue_PPortDemScControlDTCStatus_DEPCurDemCtrlDTCSetting (0)
#endif


  /* Rte_Read Api mapping  [Satisfies_rte sws 1091].*/
  /* Std_ReturnType Rte_Read_<p>_<o>([IN Rte_Instance <instance>],OUT <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SwcDemSc_SwcDemSc_LocIoDevice_Io_Stat(OUT P2VAR(SwcDemSc_StdReturnType, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Read_SwcDemSc_LocIoDevice_Io_Stat Rte_Read_SwcDemSc_SwcDemSc_LocIoDevice_Io_Stat
#endif


  /* Rte_Read Api mapping  [Satisfies_rte sws 1091].*/
  /* Std_ReturnType Rte_Read_<p>_<o>([IN Rte_Instance <instance>],OUT <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SwcDemSc_SwcDemSc_LocVoltage_SupBat_Volt(OUT P2VAR(c08_V_0_25k4_0k1, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Read_SwcDemSc_LocVoltage_SupBat_Volt Rte_Read_SwcDemSc_SwcDemSc_LocVoltage_SupBat_Volt
#endif


  /* Rte_Read Api mapping  [Satisfies_rte sws 1091].*/
  /* Std_ReturnType Rte_Read_<p>_<o>([IN Rte_Instance <instance>],OUT <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SwcDemSc_SwcDemSc_SysTransportationMode_PN14_TransMd_Stat(OUT P2VAR(c02_TransMd_Stat, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Read_SwcDemSc_SysTransportationMode_PN14_TransMd_Stat Rte_Read_SwcDemSc_SwcDemSc_SysTransportationMode_PN14_TransMd_Stat
#endif


  /* Rte_Read Api mapping  [Satisfies_rte sws 1091].*/
  /* Std_ReturnType Rte_Read_<p>_<o>([IN Rte_Instance <instance>],OUT <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SwcDemSc_SwcDemSc_SysVehicleEngineStartup_Eng_Rs_EngCtrl(OUT P2VAR(SwcDemSc_EngRsEngCtrl_GrpType, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Read_SwcDemSc_SysVehicleEngineStartup_Eng_Rs_EngCtrl Rte_Read_SwcDemSc_SwcDemSc_SysVehicleEngineStartup_Eng_Rs_EngCtrl
#endif


  /* Rte_Read Api mapping  [Satisfies_rte sws 1091].*/
  /* Std_ReturnType Rte_Read_<p>_<o>([IN Rte_Instance <instance>],OUT <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SwcDemSc_SwcDemSc_SysVoltage_PN14_SupBat_Stat(OUT P2VAR(SwcDemSc_PN14SupBatStat_GrpType, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Read_SwcDemSc_SysVoltage_PN14_SupBat_Stat Rte_Read_SwcDemSc_SwcDemSc_SysVoltage_PN14_SupBat_Stat
#endif


  /* Rte_Read Api mapping  [Satisfies_rte sws 1091].*/
  /* Std_ReturnType Rte_Read_<p>_<o>([IN Rte_Instance <instance>],OUT <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SwcDemSc_SwcDemSc_SysExtTester_DidA_ExtTest_Pres(OUT P2VAR(DC_BOOL, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Read_SwcDemSc_SysExtTester_DidA_ExtTest_Pres Rte_Read_SwcDemSc_SwcDemSc_SysExtTester_DidA_ExtTest_Pres
#endif


  /* Rte_Read Api mapping  [Satisfies_rte sws 1091].*/
  /* Std_ReturnType Rte_Read_<p>_<o>([IN Rte_Instance <instance>],OUT <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SwcDemSc_SwcDemSc_LocIgnition_Ign_Stat(OUT P2VAR(c03_ISw_Stat, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Read_SwcDemSc_LocIgnition_Ign_Stat Rte_Read_SwcDemSc_SwcDemSc_LocIgnition_Ign_Stat
#endif


  /* Rte_Read Api mapping  [Satisfies_rte sws 1091].*/
  /* Std_ReturnType Rte_Read_<p>_<o>([IN Rte_Instance <instance>],OUT <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SwcDemSc_SwcDemSc_SysIgnition_Ign_Stat(OUT P2VAR(SwcDemSc_IgnStat_GrpType, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Read_SwcDemSc_SysIgnition_Ign_Stat Rte_Read_SwcDemSc_SwcDemSc_SysIgnition_Ign_Stat
#endif


  /* Rte_Read Api mapping  [Satisfies_rte sws 1091].*/
  /* Std_ReturnType Rte_Read_<p>_<o>([IN Rte_Instance <instance>],OUT <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SwcDemSc_SwcDemSc_SysOdometer_Odo(OUT P2VAR(c24_km_0_999999k9_0k1, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Read_SwcDemSc_SysOdometer_Odo Rte_Read_SwcDemSc_SwcDemSc_SysOdometer_Odo
#endif


  /* Rte_Write Api mapping  [Satisfies_rte sws 1071], [Satisfies_rte sws 1280].*/
  /* Std_ReturnType Rte_Write_<p>_<o>([IN Rte_Instance <instance>],IN <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SwcDemSc_PPortDemScControlDTCStatus_DEPCurDemCtrlDTCSetting(IN VAR(SwcDemSc_ScStatusType, AUTOMATIC) arg1);
#ifndef RTE_C
  #define Rte_Write_PPortDemScControlDTCStatus_DEPCurDemCtrlDTCSetting Rte_Write_SwcDemSc_PPortDemScControlDTCStatus_DEPCurDemCtrlDTCSetting
#endif




/* Explicit Inter Runnable Variable mapping */
/* Rte_IrvWrite Api mapping [Satisfies_rte sws 3565], [Satisfies_rte sws 1306], [Satisfies_rte sws 3567], [Satisfies_rte sws 3569] */
/* void Rte_IrvWrite_<re>_<name>([IN RTE_Instance <instance>], IN <data>) */
extern FUNC(void, RTE_CODE) Rte_IrvWrite_SwcDemSc_CallbackControlDTCStatus_SC1_CurDemCtrlDTCSetting(SwcDemSc_ScStatusType val);
#ifndef RTE_C
  #define Rte_IrvWrite_CallbackControlDTCStatus_SC1_CurDemCtrlDTCSetting Rte_IrvWrite_SwcDemSc_CallbackControlDTCStatus_SC1_CurDemCtrlDTCSetting  /* [Satisfies_rte sws 1348] */
#endif

/* Rte_IrvWrite Api mapping [Satisfies_rte sws 3565], [Satisfies_rte sws 1306], [Satisfies_rte sws 3567], [Satisfies_rte sws 3569] */
/* void Rte_IrvWrite_<re>_<name>([IN RTE_Instance <instance>], IN <data>) */
extern FUNC(void, RTE_CODE) Rte_IrvWrite_SwcDemSc_CallbackDTCStatusChange_SC8_CurDemIndicatorStatus(SwcDemSc_ScStatusType val);
#ifndef RTE_C
  #define Rte_IrvWrite_CallbackDTCStatusChange_SC8_CurDemIndicatorStatus Rte_IrvWrite_SwcDemSc_CallbackDTCStatusChange_SC8_CurDemIndicatorStatus  /* [Satisfies_rte sws 1348] */
#endif

  /* Rte_IrvRead Api mapping [Satisfies_rte sws 3560], [Satisfies_rte sws 1305], [Satisfies_rte sws 3562], [Satisfies_rte sws 3563]*/
extern FUNC(SwcDemSc_ScStatusType, RTE_CODE) Rte_IrvRead_SwcDemSc_CheckStorageConditions_SC1_CurDemCtrlDTCSetting(void);
#ifndef RTE_C
  #define Rte_IrvRead_CheckStorageConditions_SC1_CurDemCtrlDTCSetting Rte_IrvRead_SwcDemSc_CheckStorageConditions_SC1_CurDemCtrlDTCSetting
#endif

  /* Rte_IrvRead Api mapping [Satisfies_rte sws 3560], [Satisfies_rte sws 1305], [Satisfies_rte sws 3562], [Satisfies_rte sws 3563]*/
extern FUNC(SwcDemSc_ScStatusType, RTE_CODE) Rte_IrvRead_SwcDemSc_CheckStorageConditions_SC8_CurDemIndicatorStatus(void);
#ifndef RTE_C
  #define Rte_IrvRead_CheckStorageConditions_SC8_CurDemIndicatorStatus Rte_IrvRead_SwcDemSc_CheckStorageConditions_SC8_CurDemIndicatorStatus
#endif

  /* Rte_IrvRead Api mapping [Satisfies_rte sws 3560], [Satisfies_rte sws 1305], [Satisfies_rte sws 3562], [Satisfies_rte sws 3563]*/
extern FUNC(c03_ISw_Stat, RTE_CODE) Rte_IrvRead_SwcDemSc_CheckStorageConditions_glbCurSig_Ignition(void);
#ifndef RTE_C
  #define Rte_IrvRead_CheckStorageConditions_glbCurSig_Ignition Rte_IrvRead_SwcDemSc_CheckStorageConditions_glbCurSig_Ignition
#endif

  /* Rte_IrvRead Api mapping [Satisfies_rte sws 3560], [Satisfies_rte sws 1305], [Satisfies_rte sws 3562], [Satisfies_rte sws 3563]*/
extern FUNC(SwcDemSc_glbScSigIndType, RTE_CODE) Rte_IrvRead_SwcDemSc_CheckStorageConditions_glbScSigInd(void);
#ifndef RTE_C
  #define Rte_IrvRead_CheckStorageConditions_glbScSigInd Rte_IrvRead_SwcDemSc_CheckStorageConditions_glbScSigInd
#endif

/* Rte_IrvWrite Api mapping [Satisfies_rte sws 3565], [Satisfies_rte sws 1306], [Satisfies_rte sws 3567], [Satisfies_rte sws 3569] */
/* void Rte_IrvWrite_<re>_<name>([IN RTE_Instance <instance>], IN <data>) */
extern FUNC(void, RTE_CODE) Rte_IrvWrite_SwcDemSc_CheckStorageConditions_SC11_CurVehEngStartupStatus(SwcDemSc_ScStatusType val);
#ifndef RTE_C
  #define Rte_IrvWrite_CheckStorageConditions_SC11_CurVehEngStartupStatus Rte_IrvWrite_SwcDemSc_CheckStorageConditions_SC11_CurVehEngStartupStatus  /* [Satisfies_rte sws 1348] */
#endif

/* Rte_IrvWrite Api mapping [Satisfies_rte sws 3565], [Satisfies_rte sws 1306], [Satisfies_rte sws 3567], [Satisfies_rte sws 3569] */
/* void Rte_IrvWrite_<re>_<name>([IN RTE_Instance <instance>], IN <data>) */
extern FUNC(void, RTE_CODE) Rte_IrvWrite_SwcDemSc_CheckStorageConditions_SC1_CurCtrlDTCSetting(SwcDemSc_ScStatusType val);
#ifndef RTE_C
  #define Rte_IrvWrite_CheckStorageConditions_SC1_CurCtrlDTCSetting Rte_IrvWrite_SwcDemSc_CheckStorageConditions_SC1_CurCtrlDTCSetting  /* [Satisfies_rte sws 1348] */
#endif

/* Rte_IrvWrite Api mapping [Satisfies_rte sws 3565], [Satisfies_rte sws 1306], [Satisfies_rte sws 3567], [Satisfies_rte sws 3569] */
/* void Rte_IrvWrite_<re>_<name>([IN RTE_Instance <instance>], IN <data>) */
extern FUNC(void, RTE_CODE) Rte_IrvWrite_SwcDemSc_CheckStorageConditions_SC2_CurIgStatus(SwcDemSc_ScStatusType val);
#ifndef RTE_C
  #define Rte_IrvWrite_CheckStorageConditions_SC2_CurIgStatus Rte_IrvWrite_SwcDemSc_CheckStorageConditions_SC2_CurIgStatus  /* [Satisfies_rte sws 1348] */
#endif

/* Rte_IrvWrite Api mapping [Satisfies_rte sws 3565], [Satisfies_rte sws 1306], [Satisfies_rte sws 3567], [Satisfies_rte sws 3569] */
/* void Rte_IrvWrite_<re>_<name>([IN RTE_Instance <instance>], IN <data>) */
extern FUNC(void, RTE_CODE) Rte_IrvWrite_SwcDemSc_CheckStorageConditions_SC3_CurLocVoltStatus(SwcDemSc_ScStatusType val);
#ifndef RTE_C
  #define Rte_IrvWrite_CheckStorageConditions_SC3_CurLocVoltStatus Rte_IrvWrite_SwcDemSc_CheckStorageConditions_SC3_CurLocVoltStatus  /* [Satisfies_rte sws 1348] */
#endif

/* Rte_IrvWrite Api mapping [Satisfies_rte sws 3565], [Satisfies_rte sws 1306], [Satisfies_rte sws 3567], [Satisfies_rte sws 3569] */
/* void Rte_IrvWrite_<re>_<name>([IN RTE_Instance <instance>], IN <data>) */
extern FUNC(void, RTE_CODE) Rte_IrvWrite_SwcDemSc_CheckStorageConditions_SC4_CurSysVoltStatus(SwcDemSc_ScStatusType val);
#ifndef RTE_C
  #define Rte_IrvWrite_CheckStorageConditions_SC4_CurSysVoltStatus Rte_IrvWrite_SwcDemSc_CheckStorageConditions_SC4_CurSysVoltStatus  /* [Satisfies_rte sws 1348] */
#endif

/* Rte_IrvWrite Api mapping [Satisfies_rte sws 3565], [Satisfies_rte sws 1306], [Satisfies_rte sws 3567], [Satisfies_rte sws 3569] */
/* void Rte_IrvWrite_<re>_<name>([IN RTE_Instance <instance>], IN <data>) */
extern FUNC(void, RTE_CODE) Rte_IrvWrite_SwcDemSc_CheckStorageConditions_SC5_CurTransModeStatus(SwcDemSc_ScStatusType val);
#ifndef RTE_C
  #define Rte_IrvWrite_CheckStorageConditions_SC5_CurTransModeStatus Rte_IrvWrite_SwcDemSc_CheckStorageConditions_SC5_CurTransModeStatus  /* [Satisfies_rte sws 1348] */
#endif

/* Rte_IrvWrite Api mapping [Satisfies_rte sws 3565], [Satisfies_rte sws 1306], [Satisfies_rte sws 3567], [Satisfies_rte sws 3569] */
/* void Rte_IrvWrite_<re>_<name>([IN RTE_Instance <instance>], IN <data>) */
extern FUNC(void, RTE_CODE) Rte_IrvWrite_SwcDemSc_CheckStorageConditions_SC8_CurPhysBusStatus(SwcDemSc_ScStatusType val);
#ifndef RTE_C
  #define Rte_IrvWrite_CheckStorageConditions_SC8_CurPhysBusStatus Rte_IrvWrite_SwcDemSc_CheckStorageConditions_SC8_CurPhysBusStatus  /* [Satisfies_rte sws 1348] */
#endif

/* Rte_IrvWrite Api mapping [Satisfies_rte sws 3565], [Satisfies_rte sws 1306], [Satisfies_rte sws 3567], [Satisfies_rte sws 3569] */
/* void Rte_IrvWrite_<re>_<name>([IN RTE_Instance <instance>], IN <data>) */
extern FUNC(void, RTE_CODE) Rte_IrvWrite_SwcDemSc_CheckStorageConditions_SC9_CurIoDevConfStatus(SwcDemSc_ScStatusType val);
#ifndef RTE_C
  #define Rte_IrvWrite_CheckStorageConditions_SC9_CurIoDevConfStatus Rte_IrvWrite_SwcDemSc_CheckStorageConditions_SC9_CurIoDevConfStatus  /* [Satisfies_rte sws 1348] */
#endif

/* Rte_IrvWrite Api mapping [Satisfies_rte sws 3565], [Satisfies_rte sws 1306], [Satisfies_rte sws 3567], [Satisfies_rte sws 3569] */
/* void Rte_IrvWrite_<re>_<name>([IN RTE_Instance <instance>], IN <data>) */
extern FUNC(void, RTE_CODE) Rte_IrvWrite_SwcDemSc_CheckStorageConditions_glbScSigInd(SwcDemSc_glbScSigIndType val);
#ifndef RTE_C
  #define Rte_IrvWrite_CheckStorageConditions_glbScSigInd Rte_IrvWrite_SwcDemSc_CheckStorageConditions_glbScSigInd  /* [Satisfies_rte sws 1348] */
#endif

  /* Rte_IrvRead Api mapping [Satisfies_rte sws 3560], [Satisfies_rte sws 1305], [Satisfies_rte sws 3562], [Satisfies_rte sws 3563]*/
extern FUNC(SwcDemSc_ScStatusType, RTE_CODE) Rte_IrvRead_SwcDemSc_Chk_DEM_SL_ECU_LEVEL_SC11_CurVehEngStartupStatus(void);
#ifndef RTE_C
  #define Rte_IrvRead_Chk_DEM_SL_ECU_LEVEL_SC11_CurVehEngStartupStatus Rte_IrvRead_SwcDemSc_Chk_DEM_SL_ECU_LEVEL_SC11_CurVehEngStartupStatus
#endif

  /* Rte_IrvRead Api mapping [Satisfies_rte sws 3560], [Satisfies_rte sws 1305], [Satisfies_rte sws 3562], [Satisfies_rte sws 3563]*/
extern FUNC(SwcDemSc_ScStatusType, RTE_CODE) Rte_IrvRead_SwcDemSc_Chk_DEM_SL_ECU_LEVEL_SC1_CurCtrlDTCSetting(void);
#ifndef RTE_C
  #define Rte_IrvRead_Chk_DEM_SL_ECU_LEVEL_SC1_CurCtrlDTCSetting Rte_IrvRead_SwcDemSc_Chk_DEM_SL_ECU_LEVEL_SC1_CurCtrlDTCSetting
#endif

  /* Rte_IrvRead Api mapping [Satisfies_rte sws 3560], [Satisfies_rte sws 1305], [Satisfies_rte sws 3562], [Satisfies_rte sws 3563]*/
extern FUNC(SwcDemSc_ScStatusType, RTE_CODE) Rte_IrvRead_SwcDemSc_Chk_DEM_SL_ECU_LEVEL_SC3_CurLocVoltStatus(void);
#ifndef RTE_C
  #define Rte_IrvRead_Chk_DEM_SL_ECU_LEVEL_SC3_CurLocVoltStatus Rte_IrvRead_SwcDemSc_Chk_DEM_SL_ECU_LEVEL_SC3_CurLocVoltStatus
#endif

  /* Rte_IrvRead Api mapping [Satisfies_rte sws 3560], [Satisfies_rte sws 1305], [Satisfies_rte sws 3562], [Satisfies_rte sws 3563]*/
extern FUNC(SwcDemSc_ScStatusType, RTE_CODE) Rte_IrvRead_SwcDemSc_Chk_DEM_SL_ECU_LEVEL_SC9_CurIoDevConfStatus(void);
#ifndef RTE_C
  #define Rte_IrvRead_Chk_DEM_SL_ECU_LEVEL_SC9_CurIoDevConfStatus Rte_IrvRead_SwcDemSc_Chk_DEM_SL_ECU_LEVEL_SC9_CurIoDevConfStatus
#endif

  /* Rte_IrvRead Api mapping [Satisfies_rte sws 3560], [Satisfies_rte sws 1305], [Satisfies_rte sws 3562], [Satisfies_rte sws 3563]*/
extern FUNC(SwcDemSc_ScStatusType, RTE_CODE) Rte_IrvRead_SwcDemSc_Chk_DEM_SL_ECU_LEVEL_flOldLev_DEM_SL_ECU_LEVEL(void);
#ifndef RTE_C
  #define Rte_IrvRead_Chk_DEM_SL_ECU_LEVEL_flOldLev_DEM_SL_ECU_LEVEL Rte_IrvRead_SwcDemSc_Chk_DEM_SL_ECU_LEVEL_flOldLev_DEM_SL_ECU_LEVEL
#endif

  /* Rte_IrvRead Api mapping [Satisfies_rte sws 3560], [Satisfies_rte sws 1305], [Satisfies_rte sws 3562], [Satisfies_rte sws 3563]*/
extern FUNC(SwcDemSc_FlReportType, RTE_CODE) Rte_IrvRead_SwcDemSc_Chk_DEM_SL_ECU_LEVEL_flRepStat_DEM_SL_ECU_LEVEL(void);
#ifndef RTE_C
  #define Rte_IrvRead_Chk_DEM_SL_ECU_LEVEL_flRepStat_DEM_SL_ECU_LEVEL Rte_IrvRead_SwcDemSc_Chk_DEM_SL_ECU_LEVEL_flRepStat_DEM_SL_ECU_LEVEL
#endif

/* Rte_IrvWrite Api mapping [Satisfies_rte sws 3565], [Satisfies_rte sws 1306], [Satisfies_rte sws 3567], [Satisfies_rte sws 3569] */
/* void Rte_IrvWrite_<re>_<name>([IN RTE_Instance <instance>], IN <data>) */
extern FUNC(void, RTE_CODE) Rte_IrvWrite_SwcDemSc_Chk_DEM_SL_ECU_LEVEL_flOldLev_DEM_SL_ECU_LEVEL(SwcDemSc_ScStatusType val);
#ifndef RTE_C
  #define Rte_IrvWrite_Chk_DEM_SL_ECU_LEVEL_flOldLev_DEM_SL_ECU_LEVEL Rte_IrvWrite_SwcDemSc_Chk_DEM_SL_ECU_LEVEL_flOldLev_DEM_SL_ECU_LEVEL  /* [Satisfies_rte sws 1348] */
#endif

/* Rte_IrvWrite Api mapping [Satisfies_rte sws 3565], [Satisfies_rte sws 1306], [Satisfies_rte sws 3567], [Satisfies_rte sws 3569] */
/* void Rte_IrvWrite_<re>_<name>([IN RTE_Instance <instance>], IN <data>) */
extern FUNC(void, RTE_CODE) Rte_IrvWrite_SwcDemSc_Chk_DEM_SL_ECU_LEVEL_flRepStat_DEM_SL_ECU_LEVEL(SwcDemSc_FlReportType val);
#ifndef RTE_C
  #define Rte_IrvWrite_Chk_DEM_SL_ECU_LEVEL_flRepStat_DEM_SL_ECU_LEVEL Rte_IrvWrite_SwcDemSc_Chk_DEM_SL_ECU_LEVEL_flRepStat_DEM_SL_ECU_LEVEL  /* [Satisfies_rte sws 1348] */
#endif

  /* Rte_IrvRead Api mapping [Satisfies_rte sws 3560], [Satisfies_rte sws 1305], [Satisfies_rte sws 3562], [Satisfies_rte sws 3563]*/
extern FUNC(SwcDemSc_ScStatusType, RTE_CODE) Rte_IrvRead_SwcDemSc_Chk_DEM_SL_NONE_SC1_CurCtrlDTCSetting(void);
#ifndef RTE_C
  #define Rte_IrvRead_Chk_DEM_SL_NONE_SC1_CurCtrlDTCSetting Rte_IrvRead_SwcDemSc_Chk_DEM_SL_NONE_SC1_CurCtrlDTCSetting
#endif

  /* Rte_IrvRead Api mapping [Satisfies_rte sws 3560], [Satisfies_rte sws 1305], [Satisfies_rte sws 3562], [Satisfies_rte sws 3563]*/
extern FUNC(SwcDemSc_ScStatusType, RTE_CODE) Rte_IrvRead_SwcDemSc_Chk_DEM_SL_NONE_flOldLev_DEM_SL_NONE(void);
#ifndef RTE_C
  #define Rte_IrvRead_Chk_DEM_SL_NONE_flOldLev_DEM_SL_NONE Rte_IrvRead_SwcDemSc_Chk_DEM_SL_NONE_flOldLev_DEM_SL_NONE
#endif

  /* Rte_IrvRead Api mapping [Satisfies_rte sws 3560], [Satisfies_rte sws 1305], [Satisfies_rte sws 3562], [Satisfies_rte sws 3563]*/
extern FUNC(SwcDemSc_FlReportType, RTE_CODE) Rte_IrvRead_SwcDemSc_Chk_DEM_SL_NONE_flRepStat_DEM_SL_NONE(void);
#ifndef RTE_C
  #define Rte_IrvRead_Chk_DEM_SL_NONE_flRepStat_DEM_SL_NONE Rte_IrvRead_SwcDemSc_Chk_DEM_SL_NONE_flRepStat_DEM_SL_NONE
#endif

/* Rte_IrvWrite Api mapping [Satisfies_rte sws 3565], [Satisfies_rte sws 1306], [Satisfies_rte sws 3567], [Satisfies_rte sws 3569] */
/* void Rte_IrvWrite_<re>_<name>([IN RTE_Instance <instance>], IN <data>) */
extern FUNC(void, RTE_CODE) Rte_IrvWrite_SwcDemSc_Chk_DEM_SL_NONE_flOldLev_DEM_SL_NONE(SwcDemSc_ScStatusType val);
#ifndef RTE_C
  #define Rte_IrvWrite_Chk_DEM_SL_NONE_flOldLev_DEM_SL_NONE Rte_IrvWrite_SwcDemSc_Chk_DEM_SL_NONE_flOldLev_DEM_SL_NONE  /* [Satisfies_rte sws 1348] */
#endif

/* Rte_IrvWrite Api mapping [Satisfies_rte sws 3565], [Satisfies_rte sws 1306], [Satisfies_rte sws 3567], [Satisfies_rte sws 3569] */
/* void Rte_IrvWrite_<re>_<name>([IN RTE_Instance <instance>], IN <data>) */
extern FUNC(void, RTE_CODE) Rte_IrvWrite_SwcDemSc_Chk_DEM_SL_NONE_flRepStat_DEM_SL_NONE(SwcDemSc_FlReportType val);
#ifndef RTE_C
  #define Rte_IrvWrite_Chk_DEM_SL_NONE_flRepStat_DEM_SL_NONE Rte_IrvWrite_SwcDemSc_Chk_DEM_SL_NONE_flRepStat_DEM_SL_NONE  /* [Satisfies_rte sws 1348] */
#endif

  /* Rte_IrvRead Api mapping [Satisfies_rte sws 3560], [Satisfies_rte sws 1305], [Satisfies_rte sws 3562], [Satisfies_rte sws 3563]*/
extern FUNC(SwcDemSc_DebTimType, RTE_CODE) Rte_IrvRead_SwcDemSc_Chk_DEM_SL_NWCOM_NO_CL15_SC10_dTim_DEM_SL_NWCOM_NO_CL15(void);
#ifndef RTE_C
  #define Rte_IrvRead_Chk_DEM_SL_NWCOM_NO_CL15_SC10_dTim_DEM_SL_NWCOM_NO_CL15 Rte_IrvRead_SwcDemSc_Chk_DEM_SL_NWCOM_NO_CL15_SC10_dTim_DEM_SL_NWCOM_NO_CL15
#endif

  /* Rte_IrvRead Api mapping [Satisfies_rte sws 3560], [Satisfies_rte sws 1305], [Satisfies_rte sws 3562], [Satisfies_rte sws 3563]*/
extern FUNC(SwcDemSc_ScStatusType, RTE_CODE) Rte_IrvRead_SwcDemSc_Chk_DEM_SL_NWCOM_NO_CL15_SC11_CurVehEngStartupStatus(void);
#ifndef RTE_C
  #define Rte_IrvRead_Chk_DEM_SL_NWCOM_NO_CL15_SC11_CurVehEngStartupStatus Rte_IrvRead_SwcDemSc_Chk_DEM_SL_NWCOM_NO_CL15_SC11_CurVehEngStartupStatus
#endif

  /* Rte_IrvRead Api mapping [Satisfies_rte sws 3560], [Satisfies_rte sws 1305], [Satisfies_rte sws 3562], [Satisfies_rte sws 3563]*/
extern FUNC(SwcDemSc_ScStatusType, RTE_CODE) Rte_IrvRead_SwcDemSc_Chk_DEM_SL_NWCOM_NO_CL15_SC1_CurCtrlDTCSetting(void);
#ifndef RTE_C
  #define Rte_IrvRead_Chk_DEM_SL_NWCOM_NO_CL15_SC1_CurCtrlDTCSetting Rte_IrvRead_SwcDemSc_Chk_DEM_SL_NWCOM_NO_CL15_SC1_CurCtrlDTCSetting
#endif

  /* Rte_IrvRead Api mapping [Satisfies_rte sws 3560], [Satisfies_rte sws 1305], [Satisfies_rte sws 3562], [Satisfies_rte sws 3563]*/
extern FUNC(SwcDemSc_ScStatusType, RTE_CODE) Rte_IrvRead_SwcDemSc_Chk_DEM_SL_NWCOM_NO_CL15_SC4_CurSysVoltStatus(void);
#ifndef RTE_C
  #define Rte_IrvRead_Chk_DEM_SL_NWCOM_NO_CL15_SC4_CurSysVoltStatus Rte_IrvRead_SwcDemSc_Chk_DEM_SL_NWCOM_NO_CL15_SC4_CurSysVoltStatus
#endif

  /* Rte_IrvRead Api mapping [Satisfies_rte sws 3560], [Satisfies_rte sws 1305], [Satisfies_rte sws 3562], [Satisfies_rte sws 3563]*/
extern FUNC(SwcDemSc_ScStatusType, RTE_CODE) Rte_IrvRead_SwcDemSc_Chk_DEM_SL_NWCOM_NO_CL15_SC5_CurTransModeStatus(void);
#ifndef RTE_C
  #define Rte_IrvRead_Chk_DEM_SL_NWCOM_NO_CL15_SC5_CurTransModeStatus Rte_IrvRead_SwcDemSc_Chk_DEM_SL_NWCOM_NO_CL15_SC5_CurTransModeStatus
#endif

  /* Rte_IrvRead Api mapping [Satisfies_rte sws 3560], [Satisfies_rte sws 1305], [Satisfies_rte sws 3562], [Satisfies_rte sws 3563]*/
extern FUNC(SwcDemSc_ScStatusType, RTE_CODE) Rte_IrvRead_SwcDemSc_Chk_DEM_SL_NWCOM_NO_CL15_SC8_CurPhysBusStatus(void);
#ifndef RTE_C
  #define Rte_IrvRead_Chk_DEM_SL_NWCOM_NO_CL15_SC8_CurPhysBusStatus Rte_IrvRead_SwcDemSc_Chk_DEM_SL_NWCOM_NO_CL15_SC8_CurPhysBusStatus
#endif

  /* Rte_IrvRead Api mapping [Satisfies_rte sws 3560], [Satisfies_rte sws 1305], [Satisfies_rte sws 3562], [Satisfies_rte sws 3563]*/
extern FUNC(SwcDemSc_ScStatusType, RTE_CODE) Rte_IrvRead_SwcDemSc_Chk_DEM_SL_NWCOM_NO_CL15_flOldLev_DEM_SL_NWCOM_NO_CL15(void);
#ifndef RTE_C
  #define Rte_IrvRead_Chk_DEM_SL_NWCOM_NO_CL15_flOldLev_DEM_SL_NWCOM_NO_CL15 Rte_IrvRead_SwcDemSc_Chk_DEM_SL_NWCOM_NO_CL15_flOldLev_DEM_SL_NWCOM_NO_CL15
#endif

  /* Rte_IrvRead Api mapping [Satisfies_rte sws 3560], [Satisfies_rte sws 1305], [Satisfies_rte sws 3562], [Satisfies_rte sws 3563]*/
extern FUNC(SwcDemSc_FlReportType, RTE_CODE) Rte_IrvRead_SwcDemSc_Chk_DEM_SL_NWCOM_NO_CL15_flRepStat_DEM_SL_NWCOM_NO_CL15(void);
#ifndef RTE_C
  #define Rte_IrvRead_Chk_DEM_SL_NWCOM_NO_CL15_flRepStat_DEM_SL_NWCOM_NO_CL15 Rte_IrvRead_SwcDemSc_Chk_DEM_SL_NWCOM_NO_CL15_flRepStat_DEM_SL_NWCOM_NO_CL15
#endif

/* Rte_IrvWrite Api mapping [Satisfies_rte sws 3565], [Satisfies_rte sws 1306], [Satisfies_rte sws 3567], [Satisfies_rte sws 3569] */
/* void Rte_IrvWrite_<re>_<name>([IN RTE_Instance <instance>], IN <data>) */
extern FUNC(void, RTE_CODE) Rte_IrvWrite_SwcDemSc_Chk_DEM_SL_NWCOM_NO_CL15_SC10_dTim_DEM_SL_NWCOM_NO_CL15(SwcDemSc_DebTimType val);
#ifndef RTE_C
  #define Rte_IrvWrite_Chk_DEM_SL_NWCOM_NO_CL15_SC10_dTim_DEM_SL_NWCOM_NO_CL15 Rte_IrvWrite_SwcDemSc_Chk_DEM_SL_NWCOM_NO_CL15_SC10_dTim_DEM_SL_NWCOM_NO_CL15  /* [Satisfies_rte sws 1348] */
#endif

/* Rte_IrvWrite Api mapping [Satisfies_rte sws 3565], [Satisfies_rte sws 1306], [Satisfies_rte sws 3567], [Satisfies_rte sws 3569] */
/* void Rte_IrvWrite_<re>_<name>([IN RTE_Instance <instance>], IN <data>) */
extern FUNC(void, RTE_CODE) Rte_IrvWrite_SwcDemSc_Chk_DEM_SL_NWCOM_NO_CL15_flOldLev_DEM_SL_NWCOM_NO_CL15(SwcDemSc_ScStatusType val);
#ifndef RTE_C
  #define Rte_IrvWrite_Chk_DEM_SL_NWCOM_NO_CL15_flOldLev_DEM_SL_NWCOM_NO_CL15 Rte_IrvWrite_SwcDemSc_Chk_DEM_SL_NWCOM_NO_CL15_flOldLev_DEM_SL_NWCOM_NO_CL15  /* [Satisfies_rte sws 1348] */
#endif

/* Rte_IrvWrite Api mapping [Satisfies_rte sws 3565], [Satisfies_rte sws 1306], [Satisfies_rte sws 3567], [Satisfies_rte sws 3569] */
/* void Rte_IrvWrite_<re>_<name>([IN RTE_Instance <instance>], IN <data>) */
extern FUNC(void, RTE_CODE) Rte_IrvWrite_SwcDemSc_Chk_DEM_SL_NWCOM_NO_CL15_flRepStat_DEM_SL_NWCOM_NO_CL15(SwcDemSc_FlReportType val);
#ifndef RTE_C
  #define Rte_IrvWrite_Chk_DEM_SL_NWCOM_NO_CL15_flRepStat_DEM_SL_NWCOM_NO_CL15 Rte_IrvWrite_SwcDemSc_Chk_DEM_SL_NWCOM_NO_CL15_flRepStat_DEM_SL_NWCOM_NO_CL15  /* [Satisfies_rte sws 1348] */
#endif

  /* Rte_IrvRead Api mapping [Satisfies_rte sws 3560], [Satisfies_rte sws 1305], [Satisfies_rte sws 3562], [Satisfies_rte sws 3563]*/
extern FUNC(SwcDemSc_DebTimType, RTE_CODE) Rte_IrvRead_SwcDemSc_Chk_DEM_SL_NWCOM_WITH_CL15_SC10_dTim_DEM_SL_NWCOM_WITH_CL15(void);
#ifndef RTE_C
  #define Rte_IrvRead_Chk_DEM_SL_NWCOM_WITH_CL15_SC10_dTim_DEM_SL_NWCOM_WITH_CL15 Rte_IrvRead_SwcDemSc_Chk_DEM_SL_NWCOM_WITH_CL15_SC10_dTim_DEM_SL_NWCOM_WITH_CL15
#endif

  /* Rte_IrvRead Api mapping [Satisfies_rte sws 3560], [Satisfies_rte sws 1305], [Satisfies_rte sws 3562], [Satisfies_rte sws 3563]*/
extern FUNC(SwcDemSc_ScStatusType, RTE_CODE) Rte_IrvRead_SwcDemSc_Chk_DEM_SL_NWCOM_WITH_CL15_SC11_CurVehEngStartupStatus(void);
#ifndef RTE_C
  #define Rte_IrvRead_Chk_DEM_SL_NWCOM_WITH_CL15_SC11_CurVehEngStartupStatus Rte_IrvRead_SwcDemSc_Chk_DEM_SL_NWCOM_WITH_CL15_SC11_CurVehEngStartupStatus
#endif

  /* Rte_IrvRead Api mapping [Satisfies_rte sws 3560], [Satisfies_rte sws 1305], [Satisfies_rte sws 3562], [Satisfies_rte sws 3563]*/
extern FUNC(SwcDemSc_ScStatusType, RTE_CODE) Rte_IrvRead_SwcDemSc_Chk_DEM_SL_NWCOM_WITH_CL15_SC1_CurCtrlDTCSetting(void);
#ifndef RTE_C
  #define Rte_IrvRead_Chk_DEM_SL_NWCOM_WITH_CL15_SC1_CurCtrlDTCSetting Rte_IrvRead_SwcDemSc_Chk_DEM_SL_NWCOM_WITH_CL15_SC1_CurCtrlDTCSetting
#endif

  /* Rte_IrvRead Api mapping [Satisfies_rte sws 3560], [Satisfies_rte sws 1305], [Satisfies_rte sws 3562], [Satisfies_rte sws 3563]*/
extern FUNC(SwcDemSc_ScStatusType, RTE_CODE) Rte_IrvRead_SwcDemSc_Chk_DEM_SL_NWCOM_WITH_CL15_SC2_CurIgStatus(void);
#ifndef RTE_C
  #define Rte_IrvRead_Chk_DEM_SL_NWCOM_WITH_CL15_SC2_CurIgStatus Rte_IrvRead_SwcDemSc_Chk_DEM_SL_NWCOM_WITH_CL15_SC2_CurIgStatus
#endif

  /* Rte_IrvRead Api mapping [Satisfies_rte sws 3560], [Satisfies_rte sws 1305], [Satisfies_rte sws 3562], [Satisfies_rte sws 3563]*/
extern FUNC(SwcDemSc_ScStatusType, RTE_CODE) Rte_IrvRead_SwcDemSc_Chk_DEM_SL_NWCOM_WITH_CL15_SC4_CurSysVoltStatus(void);
#ifndef RTE_C
  #define Rte_IrvRead_Chk_DEM_SL_NWCOM_WITH_CL15_SC4_CurSysVoltStatus Rte_IrvRead_SwcDemSc_Chk_DEM_SL_NWCOM_WITH_CL15_SC4_CurSysVoltStatus
#endif

  /* Rte_IrvRead Api mapping [Satisfies_rte sws 3560], [Satisfies_rte sws 1305], [Satisfies_rte sws 3562], [Satisfies_rte sws 3563]*/
extern FUNC(SwcDemSc_ScStatusType, RTE_CODE) Rte_IrvRead_SwcDemSc_Chk_DEM_SL_NWCOM_WITH_CL15_SC5_CurTransModeStatus(void);
#ifndef RTE_C
  #define Rte_IrvRead_Chk_DEM_SL_NWCOM_WITH_CL15_SC5_CurTransModeStatus Rte_IrvRead_SwcDemSc_Chk_DEM_SL_NWCOM_WITH_CL15_SC5_CurTransModeStatus
#endif

  /* Rte_IrvRead Api mapping [Satisfies_rte sws 3560], [Satisfies_rte sws 1305], [Satisfies_rte sws 3562], [Satisfies_rte sws 3563]*/
extern FUNC(SwcDemSc_ScStatusType, RTE_CODE) Rte_IrvRead_SwcDemSc_Chk_DEM_SL_NWCOM_WITH_CL15_SC8_CurPhysBusStatus(void);
#ifndef RTE_C
  #define Rte_IrvRead_Chk_DEM_SL_NWCOM_WITH_CL15_SC8_CurPhysBusStatus Rte_IrvRead_SwcDemSc_Chk_DEM_SL_NWCOM_WITH_CL15_SC8_CurPhysBusStatus
#endif

  /* Rte_IrvRead Api mapping [Satisfies_rte sws 3560], [Satisfies_rte sws 1305], [Satisfies_rte sws 3562], [Satisfies_rte sws 3563]*/
extern FUNC(SwcDemSc_ScStatusType, RTE_CODE) Rte_IrvRead_SwcDemSc_Chk_DEM_SL_NWCOM_WITH_CL15_flOldLev_DEM_SL_NWCOM_WITH_CL15(void);
#ifndef RTE_C
  #define Rte_IrvRead_Chk_DEM_SL_NWCOM_WITH_CL15_flOldLev_DEM_SL_NWCOM_WITH_CL15 Rte_IrvRead_SwcDemSc_Chk_DEM_SL_NWCOM_WITH_CL15_flOldLev_DEM_SL_NWCOM_WITH_CL15
#endif

  /* Rte_IrvRead Api mapping [Satisfies_rte sws 3560], [Satisfies_rte sws 1305], [Satisfies_rte sws 3562], [Satisfies_rte sws 3563]*/
extern FUNC(SwcDemSc_FlReportType, RTE_CODE) Rte_IrvRead_SwcDemSc_Chk_DEM_SL_NWCOM_WITH_CL15_flRepStat_DEM_SL_NWCOM_WITH_CL15(void);
#ifndef RTE_C
  #define Rte_IrvRead_Chk_DEM_SL_NWCOM_WITH_CL15_flRepStat_DEM_SL_NWCOM_WITH_CL15 Rte_IrvRead_SwcDemSc_Chk_DEM_SL_NWCOM_WITH_CL15_flRepStat_DEM_SL_NWCOM_WITH_CL15
#endif

/* Rte_IrvWrite Api mapping [Satisfies_rte sws 3565], [Satisfies_rte sws 1306], [Satisfies_rte sws 3567], [Satisfies_rte sws 3569] */
/* void Rte_IrvWrite_<re>_<name>([IN RTE_Instance <instance>], IN <data>) */
extern FUNC(void, RTE_CODE) Rte_IrvWrite_SwcDemSc_Chk_DEM_SL_NWCOM_WITH_CL15_SC10_dTim_DEM_SL_NWCOM_WITH_CL15(SwcDemSc_DebTimType val);
#ifndef RTE_C
  #define Rte_IrvWrite_Chk_DEM_SL_NWCOM_WITH_CL15_SC10_dTim_DEM_SL_NWCOM_WITH_CL15 Rte_IrvWrite_SwcDemSc_Chk_DEM_SL_NWCOM_WITH_CL15_SC10_dTim_DEM_SL_NWCOM_WITH_CL15  /* [Satisfies_rte sws 1348] */
#endif

/* Rte_IrvWrite Api mapping [Satisfies_rte sws 3565], [Satisfies_rte sws 1306], [Satisfies_rte sws 3567], [Satisfies_rte sws 3569] */
/* void Rte_IrvWrite_<re>_<name>([IN RTE_Instance <instance>], IN <data>) */
extern FUNC(void, RTE_CODE) Rte_IrvWrite_SwcDemSc_Chk_DEM_SL_NWCOM_WITH_CL15_flOldLev_DEM_SL_NWCOM_WITH_CL15(SwcDemSc_ScStatusType val);
#ifndef RTE_C
  #define Rte_IrvWrite_Chk_DEM_SL_NWCOM_WITH_CL15_flOldLev_DEM_SL_NWCOM_WITH_CL15 Rte_IrvWrite_SwcDemSc_Chk_DEM_SL_NWCOM_WITH_CL15_flOldLev_DEM_SL_NWCOM_WITH_CL15  /* [Satisfies_rte sws 1348] */
#endif

/* Rte_IrvWrite Api mapping [Satisfies_rte sws 3565], [Satisfies_rte sws 1306], [Satisfies_rte sws 3567], [Satisfies_rte sws 3569] */
/* void Rte_IrvWrite_<re>_<name>([IN RTE_Instance <instance>], IN <data>) */
extern FUNC(void, RTE_CODE) Rte_IrvWrite_SwcDemSc_Chk_DEM_SL_NWCOM_WITH_CL15_flRepStat_DEM_SL_NWCOM_WITH_CL15(SwcDemSc_FlReportType val);
#ifndef RTE_C
  #define Rte_IrvWrite_Chk_DEM_SL_NWCOM_WITH_CL15_flRepStat_DEM_SL_NWCOM_WITH_CL15 Rte_IrvWrite_SwcDemSc_Chk_DEM_SL_NWCOM_WITH_CL15_flRepStat_DEM_SL_NWCOM_WITH_CL15  /* [Satisfies_rte sws 1348] */
#endif

  /* Rte_IrvRead Api mapping [Satisfies_rte sws 3560], [Satisfies_rte sws 1305], [Satisfies_rte sws 3562], [Satisfies_rte sws 3563]*/
extern FUNC(SwcDemSc_DebTimType, RTE_CODE) Rte_IrvRead_SwcDemSc_Chk_DEM_SL_POWER_DIST_SC10_dTim_DEM_SL_POWER_DIST(void);
#ifndef RTE_C
  #define Rte_IrvRead_Chk_DEM_SL_POWER_DIST_SC10_dTim_DEM_SL_POWER_DIST Rte_IrvRead_SwcDemSc_Chk_DEM_SL_POWER_DIST_SC10_dTim_DEM_SL_POWER_DIST
#endif

  /* Rte_IrvRead Api mapping [Satisfies_rte sws 3560], [Satisfies_rte sws 1305], [Satisfies_rte sws 3562], [Satisfies_rte sws 3563]*/
extern FUNC(SwcDemSc_ScStatusType, RTE_CODE) Rte_IrvRead_SwcDemSc_Chk_DEM_SL_POWER_DIST_SC11_CurVehEngStartupStatus(void);
#ifndef RTE_C
  #define Rte_IrvRead_Chk_DEM_SL_POWER_DIST_SC11_CurVehEngStartupStatus Rte_IrvRead_SwcDemSc_Chk_DEM_SL_POWER_DIST_SC11_CurVehEngStartupStatus
#endif

  /* Rte_IrvRead Api mapping [Satisfies_rte sws 3560], [Satisfies_rte sws 1305], [Satisfies_rte sws 3562], [Satisfies_rte sws 3563]*/
extern FUNC(SwcDemSc_ScStatusType, RTE_CODE) Rte_IrvRead_SwcDemSc_Chk_DEM_SL_POWER_DIST_SC1_CurCtrlDTCSetting(void);
#ifndef RTE_C
  #define Rte_IrvRead_Chk_DEM_SL_POWER_DIST_SC1_CurCtrlDTCSetting Rte_IrvRead_SwcDemSc_Chk_DEM_SL_POWER_DIST_SC1_CurCtrlDTCSetting
#endif

  /* Rte_IrvRead Api mapping [Satisfies_rte sws 3560], [Satisfies_rte sws 1305], [Satisfies_rte sws 3562], [Satisfies_rte sws 3563]*/
extern FUNC(SwcDemSc_ScStatusType, RTE_CODE) Rte_IrvRead_SwcDemSc_Chk_DEM_SL_POWER_DIST_SC2_CurIgStatus(void);
#ifndef RTE_C
  #define Rte_IrvRead_Chk_DEM_SL_POWER_DIST_SC2_CurIgStatus Rte_IrvRead_SwcDemSc_Chk_DEM_SL_POWER_DIST_SC2_CurIgStatus
#endif

  /* Rte_IrvRead Api mapping [Satisfies_rte sws 3560], [Satisfies_rte sws 1305], [Satisfies_rte sws 3562], [Satisfies_rte sws 3563]*/
extern FUNC(SwcDemSc_ScStatusType, RTE_CODE) Rte_IrvRead_SwcDemSc_Chk_DEM_SL_POWER_DIST_flOldLev_DEM_SL_POWER_DIST(void);
#ifndef RTE_C
  #define Rte_IrvRead_Chk_DEM_SL_POWER_DIST_flOldLev_DEM_SL_POWER_DIST Rte_IrvRead_SwcDemSc_Chk_DEM_SL_POWER_DIST_flOldLev_DEM_SL_POWER_DIST
#endif

  /* Rte_IrvRead Api mapping [Satisfies_rte sws 3560], [Satisfies_rte sws 1305], [Satisfies_rte sws 3562], [Satisfies_rte sws 3563]*/
extern FUNC(SwcDemSc_FlReportType, RTE_CODE) Rte_IrvRead_SwcDemSc_Chk_DEM_SL_POWER_DIST_flRepStat_DEM_SL_POWER_DIST(void);
#ifndef RTE_C
  #define Rte_IrvRead_Chk_DEM_SL_POWER_DIST_flRepStat_DEM_SL_POWER_DIST Rte_IrvRead_SwcDemSc_Chk_DEM_SL_POWER_DIST_flRepStat_DEM_SL_POWER_DIST
#endif

/* Rte_IrvWrite Api mapping [Satisfies_rte sws 3565], [Satisfies_rte sws 1306], [Satisfies_rte sws 3567], [Satisfies_rte sws 3569] */
/* void Rte_IrvWrite_<re>_<name>([IN RTE_Instance <instance>], IN <data>) */
extern FUNC(void, RTE_CODE) Rte_IrvWrite_SwcDemSc_Chk_DEM_SL_POWER_DIST_SC10_dTim_DEM_SL_POWER_DIST(SwcDemSc_DebTimType val);
#ifndef RTE_C
  #define Rte_IrvWrite_Chk_DEM_SL_POWER_DIST_SC10_dTim_DEM_SL_POWER_DIST Rte_IrvWrite_SwcDemSc_Chk_DEM_SL_POWER_DIST_SC10_dTim_DEM_SL_POWER_DIST  /* [Satisfies_rte sws 1348] */
#endif

/* Rte_IrvWrite Api mapping [Satisfies_rte sws 3565], [Satisfies_rte sws 1306], [Satisfies_rte sws 3567], [Satisfies_rte sws 3569] */
/* void Rte_IrvWrite_<re>_<name>([IN RTE_Instance <instance>], IN <data>) */
extern FUNC(void, RTE_CODE) Rte_IrvWrite_SwcDemSc_Chk_DEM_SL_POWER_DIST_flOldLev_DEM_SL_POWER_DIST(SwcDemSc_ScStatusType val);
#ifndef RTE_C
  #define Rte_IrvWrite_Chk_DEM_SL_POWER_DIST_flOldLev_DEM_SL_POWER_DIST Rte_IrvWrite_SwcDemSc_Chk_DEM_SL_POWER_DIST_flOldLev_DEM_SL_POWER_DIST  /* [Satisfies_rte sws 1348] */
#endif

/* Rte_IrvWrite Api mapping [Satisfies_rte sws 3565], [Satisfies_rte sws 1306], [Satisfies_rte sws 3567], [Satisfies_rte sws 3569] */
/* void Rte_IrvWrite_<re>_<name>([IN RTE_Instance <instance>], IN <data>) */
extern FUNC(void, RTE_CODE) Rte_IrvWrite_SwcDemSc_Chk_DEM_SL_POWER_DIST_flRepStat_DEM_SL_POWER_DIST(SwcDemSc_FlReportType val);
#ifndef RTE_C
  #define Rte_IrvWrite_Chk_DEM_SL_POWER_DIST_flRepStat_DEM_SL_POWER_DIST Rte_IrvWrite_SwcDemSc_Chk_DEM_SL_POWER_DIST_flRepStat_DEM_SL_POWER_DIST  /* [Satisfies_rte sws 1348] */
#endif

  /* Rte_IrvRead Api mapping [Satisfies_rte sws 3560], [Satisfies_rte sws 1305], [Satisfies_rte sws 3562], [Satisfies_rte sws 3563]*/
extern FUNC(c24_km_0_999999k9_0k1, RTE_CODE) Rte_IrvRead_SwcDemSc_GetCurrentOdometer_glbSysOdometer(void);
#ifndef RTE_C
  #define Rte_IrvRead_GetCurrentOdometer_glbSysOdometer Rte_IrvRead_SwcDemSc_GetCurrentOdometer_glbSysOdometer
#endif

/* Rte_IrvWrite Api mapping [Satisfies_rte sws 3565], [Satisfies_rte sws 1306], [Satisfies_rte sws 3567], [Satisfies_rte sws 3569] */
/* void Rte_IrvWrite_<re>_<name>([IN RTE_Instance <instance>], IN <data>) */
extern FUNC(void, RTE_CODE) Rte_IrvWrite_SwcDemSc_GetIgnitionSignal_glbCurSig_Ignition(c03_ISw_Stat val);
#ifndef RTE_C
  #define Rte_IrvWrite_GetIgnitionSignal_glbCurSig_Ignition Rte_IrvWrite_SwcDemSc_GetIgnitionSignal_glbCurSig_Ignition  /* [Satisfies_rte sws 1348] */
#endif

  /* Rte_IrvRead Api mapping [Satisfies_rte sws 3560], [Satisfies_rte sws 1305], [Satisfies_rte sws 3562], [Satisfies_rte sws 3563]*/
extern FUNC(c24_km_0_999999k9_0k1, RTE_CODE) Rte_IrvRead_SwcDemSc_HandleSysOdometer_glbSysOdometer(void);
#ifndef RTE_C
  #define Rte_IrvRead_HandleSysOdometer_glbSysOdometer Rte_IrvRead_SwcDemSc_HandleSysOdometer_glbSysOdometer
#endif

/* Rte_IrvWrite Api mapping [Satisfies_rte sws 3565], [Satisfies_rte sws 1306], [Satisfies_rte sws 3567], [Satisfies_rte sws 3569] */
/* void Rte_IrvWrite_<re>_<name>([IN RTE_Instance <instance>], IN <data>) */
extern FUNC(void, RTE_CODE) Rte_IrvWrite_SwcDemSc_HandleSysOdometer_glbSysOdometer(c24_km_0_999999k9_0k1 val);
#ifndef RTE_C
  #define Rte_IrvWrite_HandleSysOdometer_glbSysOdometer Rte_IrvWrite_SwcDemSc_HandleSysOdometer_glbSysOdometer  /* [Satisfies_rte sws 1348] */
#endif

  /* Rte_IrvRead Api mapping [Satisfies_rte sws 3560], [Satisfies_rte sws 1305], [Satisfies_rte sws 3562], [Satisfies_rte sws 3563]*/
extern FUNC(SwcDemSc_DebTimType, RTE_CODE) Rte_IrvRead_SwcDemSc_SetIgnitionCycle_dTim_DEM_OC_IGNITION(void);
#ifndef RTE_C
  #define Rte_IrvRead_SetIgnitionCycle_dTim_DEM_OC_IGNITION Rte_IrvRead_SwcDemSc_SetIgnitionCycle_dTim_DEM_OC_IGNITION
#endif

  /* Rte_IrvRead Api mapping [Satisfies_rte sws 3560], [Satisfies_rte sws 1305], [Satisfies_rte sws 3562], [Satisfies_rte sws 3563]*/
extern FUNC(Dem_OperationCycleStateType, RTE_CODE) Rte_IrvRead_SwcDemSc_SetIgnitionCycle_flOldOc_DEM_OC_IGNITION(void);
#ifndef RTE_C
  #define Rte_IrvRead_SetIgnitionCycle_flOldOc_DEM_OC_IGNITION Rte_IrvRead_SwcDemSc_SetIgnitionCycle_flOldOc_DEM_OC_IGNITION
#endif

  /* Rte_IrvRead Api mapping [Satisfies_rte sws 3560], [Satisfies_rte sws 1305], [Satisfies_rte sws 3562], [Satisfies_rte sws 3563]*/
extern FUNC(SwcDemSc_FlReportType, RTE_CODE) Rte_IrvRead_SwcDemSc_SetIgnitionCycle_flRepStat_DEM_OC_IGNITION(void);
#ifndef RTE_C
  #define Rte_IrvRead_SetIgnitionCycle_flRepStat_DEM_OC_IGNITION Rte_IrvRead_SwcDemSc_SetIgnitionCycle_flRepStat_DEM_OC_IGNITION
#endif

  /* Rte_IrvRead Api mapping [Satisfies_rte sws 3560], [Satisfies_rte sws 1305], [Satisfies_rte sws 3562], [Satisfies_rte sws 3563]*/
extern FUNC(c03_ISw_Stat, RTE_CODE) Rte_IrvRead_SwcDemSc_SetIgnitionCycle_glbCurSig_Ignition(void);
#ifndef RTE_C
  #define Rte_IrvRead_SetIgnitionCycle_glbCurSig_Ignition Rte_IrvRead_SwcDemSc_SetIgnitionCycle_glbCurSig_Ignition
#endif

  /* Rte_IrvRead Api mapping [Satisfies_rte sws 3560], [Satisfies_rte sws 1305], [Satisfies_rte sws 3562], [Satisfies_rte sws 3563]*/
extern FUNC(c03_ISw_Stat, RTE_CODE) Rte_IrvRead_SwcDemSc_SetIgnitionCycle_glbOldSig_Ignition(void);
#ifndef RTE_C
  #define Rte_IrvRead_SetIgnitionCycle_glbOldSig_Ignition Rte_IrvRead_SwcDemSc_SetIgnitionCycle_glbOldSig_Ignition
#endif

/* Rte_IrvWrite Api mapping [Satisfies_rte sws 3565], [Satisfies_rte sws 1306], [Satisfies_rte sws 3567], [Satisfies_rte sws 3569] */
/* void Rte_IrvWrite_<re>_<name>([IN RTE_Instance <instance>], IN <data>) */
extern FUNC(void, RTE_CODE) Rte_IrvWrite_SwcDemSc_SetIgnitionCycle_dTim_DEM_OC_IGNITION(SwcDemSc_DebTimType val);
#ifndef RTE_C
  #define Rte_IrvWrite_SetIgnitionCycle_dTim_DEM_OC_IGNITION Rte_IrvWrite_SwcDemSc_SetIgnitionCycle_dTim_DEM_OC_IGNITION  /* [Satisfies_rte sws 1348] */
#endif

/* Rte_IrvWrite Api mapping [Satisfies_rte sws 3565], [Satisfies_rte sws 1306], [Satisfies_rte sws 3567], [Satisfies_rte sws 3569] */
/* void Rte_IrvWrite_<re>_<name>([IN RTE_Instance <instance>], IN <data>) */
extern FUNC(void, RTE_CODE) Rte_IrvWrite_SwcDemSc_SetIgnitionCycle_flOldOc_DEM_OC_IGNITION(Dem_OperationCycleStateType val);
#ifndef RTE_C
  #define Rte_IrvWrite_SetIgnitionCycle_flOldOc_DEM_OC_IGNITION Rte_IrvWrite_SwcDemSc_SetIgnitionCycle_flOldOc_DEM_OC_IGNITION  /* [Satisfies_rte sws 1348] */
#endif

/* Rte_IrvWrite Api mapping [Satisfies_rte sws 3565], [Satisfies_rte sws 1306], [Satisfies_rte sws 3567], [Satisfies_rte sws 3569] */
/* void Rte_IrvWrite_<re>_<name>([IN RTE_Instance <instance>], IN <data>) */
extern FUNC(void, RTE_CODE) Rte_IrvWrite_SwcDemSc_SetIgnitionCycle_flRepStat_DEM_OC_IGNITION(SwcDemSc_FlReportType val);
#ifndef RTE_C
  #define Rte_IrvWrite_SetIgnitionCycle_flRepStat_DEM_OC_IGNITION Rte_IrvWrite_SwcDemSc_SetIgnitionCycle_flRepStat_DEM_OC_IGNITION  /* [Satisfies_rte sws 1348] */
#endif

/* Rte_IrvWrite Api mapping [Satisfies_rte sws 3565], [Satisfies_rte sws 1306], [Satisfies_rte sws 3567], [Satisfies_rte sws 3569] */
/* void Rte_IrvWrite_<re>_<name>([IN RTE_Instance <instance>], IN <data>) */
extern FUNC(void, RTE_CODE) Rte_IrvWrite_SwcDemSc_SetIgnitionCycle_glbOldSig_Ignition(c03_ISw_Stat val);
#ifndef RTE_C
  #define Rte_IrvWrite_SetIgnitionCycle_glbOldSig_Ignition Rte_IrvWrite_SwcDemSc_SetIgnitionCycle_glbOldSig_Ignition  /* [Satisfies_rte sws 1348] */
#endif








#ifdef __cplusplus
	} /* extern "C" */
#endif /* __cplusplus */


#endif
