/**************************************************************************
This file is generated automatically by the RTE generator
Filename:	Rte_SWCVdyAdapt.h
CESSAR-CT Version: 3.1.1.11
RTE Version: 3.2.0.1.3.0
Generated on:	Tue Jun 19 11:26:15 CEST 2012
**************************************************************************/


#ifndef _RTE_SWCVdyAdapt_H_
#define _RTE_SWCVdyAdapt_H_



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
  typedef CONSTP2CONST(Rte_CDS_SWCVdyAdapt, AUTOMATIC, RTE_CONST) Rte_Instance;
#endif /* RTE_C */

/* SWC:SWCVdyAdapt Indirect API */
	/* The name of the instance handle is Rte_Inst_<c> [Satisfies_rte sws 3793]. */
extern CONST(Rte_CDS_SWCVdyAdapt, RTE_CONST) Rte_Instance_SWCVdyAdapt;

#ifndef RTE_C

	/*  Provided ports */



	/*  Required ports */


#endif



/* runnable entry points (symbol) */

extern void VDY_v_AdaptInit (void); 
extern void VDY_v_AdaptMain (void); 


/* application error code */
#ifndef RTE_E_NvMService_E_NOK
  #define RTE_E_NvMService_E_NOK 1
#endif
#ifndef RTE_E_NvMService_E_OK
  #define RTE_E_NvMService_E_OK 0
#endif
#ifndef RTE_E_CSI_Timer64GetTimerValue_E_NOT_OK
  #define RTE_E_CSI_Timer64GetTimerValue_E_NOT_OK 1
#endif



/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For asynchronous [Satisfies_rte sws 1293] server invocation of call pt.:/COMPONENTTYPES/IntBehVdyAdapt/RunEntVdyAdapt/ASCP_NvmLatAcc */
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
  extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWCVdyAdapt_RPortNvmLatAcc_ReadBlock( IN P2CONST(UInt8,AUTOMATIC,RTE_APPL_DATA) DstPtr);
#else
  extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWCVdyAdapt_RPortNvmLatAcc_ReadBlock( IN P2CONST(DstPtrType,AUTOMATIC,RTE_APPL_DATA) DstPtr);
#endif
#ifndef RTE_C
  #define Rte_Call_RPortNvmLatAcc_ReadBlock Rte_Call_SWCVdyAdapt_RPortNvmLatAcc_ReadBlock
#endif


/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For asynchronous [Satisfies_rte sws 1293] server invocation of call pt.:/COMPONENTTYPES/IntBehVdyAdapt/RunEntVdyAdapt/ASCP_NvmLatAcc */
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
  extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWCVdyAdapt_RPortNvmLatAcc_WriteBlock( IN P2CONST(UInt8,AUTOMATIC,RTE_APPL_DATA) SrcPtr);
#else
  extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWCVdyAdapt_RPortNvmLatAcc_WriteBlock( IN P2CONST(DstPtrType,AUTOMATIC,RTE_APPL_DATA) SrcPtr);
#endif
#ifndef RTE_C
  #define Rte_Call_RPortNvmLatAcc_WriteBlock Rte_Call_SWCVdyAdapt_RPortNvmLatAcc_WriteBlock
#endif


/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For asynchronous [Satisfies_rte sws 1293] server invocation of call pt.:/COMPONENTTYPES/IntBehVdyAdapt/RunEntVdyAdapt/ASCP_NvmSlfStrad */
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
  extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWCVdyAdapt_RPortNvmSlfStrad_ReadBlock( IN P2CONST(UInt8,AUTOMATIC,RTE_APPL_DATA) DstPtr);
#else
  extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWCVdyAdapt_RPortNvmSlfStrad_ReadBlock( IN P2CONST(DstPtrType,AUTOMATIC,RTE_APPL_DATA) DstPtr);
#endif
#ifndef RTE_C
  #define Rte_Call_RPortNvmSlfStrad_ReadBlock Rte_Call_SWCVdyAdapt_RPortNvmSlfStrad_ReadBlock
#endif


/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For asynchronous [Satisfies_rte sws 1293] server invocation of call pt.:/COMPONENTTYPES/IntBehVdyAdapt/RunEntVdyAdapt/ASCP_NvmSlfStrad */
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
  extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWCVdyAdapt_RPortNvmSlfStrad_WriteBlock( IN P2CONST(UInt8,AUTOMATIC,RTE_APPL_DATA) SrcPtr);
#else
  extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWCVdyAdapt_RPortNvmSlfStrad_WriteBlock( IN P2CONST(DstPtrType,AUTOMATIC,RTE_APPL_DATA) SrcPtr);
#endif
#ifndef RTE_C
  #define Rte_Call_RPortNvmSlfStrad_WriteBlock Rte_Call_SWCVdyAdapt_RPortNvmSlfStrad_WriteBlock
#endif


/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For asynchronous [Satisfies_rte sws 1293] server invocation of call pt.:/COMPONENTTYPES/IntBehVdyAdapt/RunEntVdyAdapt/ASCP_NvmStWhLang */
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
  extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWCVdyAdapt_RPortNvmStwhLang_ReadBlock( IN P2CONST(UInt8,AUTOMATIC,RTE_APPL_DATA) DstPtr);
#else
  extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWCVdyAdapt_RPortNvmStwhLang_ReadBlock( IN P2CONST(DstPtrType,AUTOMATIC,RTE_APPL_DATA) DstPtr);
#endif
#ifndef RTE_C
  #define Rte_Call_RPortNvmStwhLang_ReadBlock Rte_Call_SWCVdyAdapt_RPortNvmStwhLang_ReadBlock
#endif


/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For asynchronous [Satisfies_rte sws 1293] server invocation of call pt.:/COMPONENTTYPES/IntBehVdyAdapt/RunEntVdyAdapt/ASCP_NvmStWhLang */
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
  extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWCVdyAdapt_RPortNvmStwhLang_WriteBlock( IN P2CONST(UInt8,AUTOMATIC,RTE_APPL_DATA) SrcPtr);
#else
  extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWCVdyAdapt_RPortNvmStwhLang_WriteBlock( IN P2CONST(DstPtrType,AUTOMATIC,RTE_APPL_DATA) SrcPtr);
#endif
#ifndef RTE_C
  #define Rte_Call_RPortNvmStwhLang_WriteBlock Rte_Call_SWCVdyAdapt_RPortNvmStwhLang_WriteBlock
#endif


/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For asynchronous [Satisfies_rte sws 1293] server invocation of call pt.:/COMPONENTTYPES/IntBehVdyAdapt/RunEntVdyAdapt/ASCP_NvmVelCorr */
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
  extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWCVdyAdapt_RPortNvmVelCorr_ReadBlock( IN P2CONST(UInt8,AUTOMATIC,RTE_APPL_DATA) DstPtr);
#else
  extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWCVdyAdapt_RPortNvmVelCorr_ReadBlock( IN P2CONST(DstPtrType,AUTOMATIC,RTE_APPL_DATA) DstPtr);
#endif
#ifndef RTE_C
  #define Rte_Call_RPortNvmVelCorr_ReadBlock Rte_Call_SWCVdyAdapt_RPortNvmVelCorr_ReadBlock
#endif


/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For asynchronous [Satisfies_rte sws 1293] server invocation of call pt.:/COMPONENTTYPES/IntBehVdyAdapt/RunEntVdyAdapt/ASCP_NvmVelCorr */
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
  extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWCVdyAdapt_RPortNvmVelCorr_WriteBlock( IN P2CONST(UInt8,AUTOMATIC,RTE_APPL_DATA) SrcPtr);
#else
  extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWCVdyAdapt_RPortNvmVelCorr_WriteBlock( IN P2CONST(DstPtrType,AUTOMATIC,RTE_APPL_DATA) SrcPtr);
#endif
#ifndef RTE_C
  #define Rte_Call_RPortNvmVelCorr_WriteBlock Rte_Call_SWCVdyAdapt_RPortNvmVelCorr_WriteBlock
#endif


/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For asynchronous [Satisfies_rte sws 1293] server invocation of call pt.:/COMPONENTTYPES/IntBehVdyAdapt/RunEntVdyAdapt/ASCP_NvmYawRate */
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
  extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWCVdyAdapt_RPortNvmYawRate_ReadBlock( IN P2CONST(UInt8,AUTOMATIC,RTE_APPL_DATA) DstPtr);
#else
  extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWCVdyAdapt_RPortNvmYawRate_ReadBlock( IN P2CONST(DstPtrType,AUTOMATIC,RTE_APPL_DATA) DstPtr);
#endif
#ifndef RTE_C
  #define Rte_Call_RPortNvmYawRate_ReadBlock Rte_Call_SWCVdyAdapt_RPortNvmYawRate_ReadBlock
#endif


/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For asynchronous [Satisfies_rte sws 1293] server invocation of call pt.:/COMPONENTTYPES/IntBehVdyAdapt/RunEntVdyAdapt/ASCP_NvmYawRate */
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
  extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWCVdyAdapt_RPortNvmYawRate_WriteBlock( IN P2CONST(UInt8,AUTOMATIC,RTE_APPL_DATA) SrcPtr);
#else
  extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWCVdyAdapt_RPortNvmYawRate_WriteBlock( IN P2CONST(DstPtrType,AUTOMATIC,RTE_APPL_DATA) SrcPtr);
#endif
#ifndef RTE_C
  #define Rte_Call_RPortNvmYawRate_WriteBlock Rte_Call_SWCVdyAdapt_RPortNvmYawRate_WriteBlock
#endif


/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/COMPONENTTYPES/IntBehVdyAdapt/RunEntVdyAdapt/SSCP_VdyTimer64GetTimerValue */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWCVdyAdapt_RPortVdyTimer64GetTimerValue_OPTimer64GetTimerValue( OUT P2VAR(uint64,AUTOMATIC,RTE_APPL_DATA) timerValue);
#ifndef RTE_C
  #define Rte_Call_RPortVdyTimer64GetTimerValue_OPTimer64GetTimerValue Rte_Call_SWCVdyAdapt_RPortVdyTimer64GetTimerValue_OPTimer64GetTimerValue
#endif






#ifndef RTE_C
  #define Rte_InitValue_RPortVdyDebugMode_DEPAlgoDebugMode (0)
#endif

#ifndef RTE_C
  #define Rte_InitValue_PPortVdyTaskState_DEP_VehicleAlgoTaskState (0)
#endif


  /* Rte_Read Api mapping  [Satisfies_rte sws 1091].*/
  /* Std_ReturnType Rte_Read_<p>_<o>([IN Rte_Instance <instance>],OUT <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWCVdyAdapt_RPortVdyDebugMode_DEPAlgoDebugMode(OUT P2VAR(RTE_t_eAlgoDebugMode, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Read_RPortVdyDebugMode_DEPAlgoDebugMode Rte_Read_SWCVdyAdapt_RPortVdyDebugMode_DEPAlgoDebugMode
#endif


  /* Rte_Write Api mapping  [Satisfies_rte sws 1071], [Satisfies_rte sws 1280].*/
  /* Std_ReturnType Rte_Write_<p>_<o>([IN Rte_Instance <instance>],IN <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWCVdyAdapt_PPortVdyAlgoVersion_DEPAlgoVersion(IN P2VAR(RTE_t_AlgoVersion, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Write_PPortVdyAlgoVersion_DEPAlgoVersion Rte_Write_SWCVdyAdapt_PPortVdyAlgoVersion_DEPAlgoVersion
#endif


  /* Rte_Write Api mapping  [Satisfies_rte sws 1071], [Satisfies_rte sws 1280].*/
  /* Std_ReturnType Rte_Write_<p>_<o>([IN Rte_Instance <instance>],IN <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWCVdyAdapt_PPortVdyTaskState_DEP_VehicleAlgoTaskState(IN VAR(RTE_t_SYSMultiRunTaskState, AUTOMATIC) arg1);
#ifndef RTE_C
  #define Rte_Write_PPortVdyTaskState_DEP_VehicleAlgoTaskState Rte_Write_SWCVdyAdapt_PPortVdyTaskState_DEP_VehicleAlgoTaskState
#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(BSW_s_VDYCtrlData_t, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCVdyAdapt_RunEntVdyAdapt_RPortActltoVdy_DEPVdyCtrlData(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntVdyAdapt_RPortActltoVdy_DEPVdyCtrlData \
    Rte_IRead_SWCVdyAdapt_RunEntVdyAdapt_RPortActltoVdy_DEPVdyCtrlData

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(RTE_t_VCVehicleData, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCVdyAdapt_RunEntVdyAdapt_RPortVdyVcVehicleData_DEP_VCVehicleData(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntVdyAdapt_RPortVdyVcVehicleData_DEP_VCVehicleData \
    Rte_IRead_SWCVdyAdapt_RunEntVdyAdapt_RPortVdyVcVehicleData_DEP_VCVehicleData

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(VehSig_t, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCVdyAdapt_RunEntVdyAdapt_RPortVdyVehSig_DEPBswVehSig(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntVdyAdapt_RPortVdyVehSig_DEPBswVehSig \
    Rte_IRead_SWCVdyAdapt_RunEntVdyAdapt_RPortVdyVehSig_DEPBswVehSig

#endif


  /* Rte_IWrite Api mapping  [Satisfies_rte sws 3744], [Satisfies_rte sws 1302], [Satisfies_rte sws 3746], [Satisfies_rte sws 3747].*/
  /* void Rte_IWrite_<re>_<p>_<d>([IN RTE_Instance], IN <type>) */
extern FUNC(void, RTE_CODE) Rte_IWrite_SWCVdyAdapt_RunEntVdyAdapt_PPortVdyOutput_DEPVdyOutput(P2VAR(RTE_t_VdyOutput, AUTOMATIC, RTE_APPL_DATA) arg1);
extern FUNC( P2VAR(RTE_t_VdyOutput, AUTOMATIC, RTE_APPL_DATA), RTE_CODE ) Rte_IWriteRef_SWCVdyAdapt_RunEntVdyAdapt_PPortVdyOutput_DEPVdyOutput();

#ifndef RTE_C
  #define Rte_IWrite_RunEntVdyAdapt_PPortVdyOutput_DEPVdyOutput \
    Rte_IWrite_SWCVdyAdapt_RunEntVdyAdapt_PPortVdyOutput_DEPVdyOutput

  #define Rte_IWriteRef_RunEntVdyAdapt_PPortVdyOutput_DEPVdyOutput \
    Rte_IWriteRef_SWCVdyAdapt_RunEntVdyAdapt_PPortVdyOutput_DEPVdyOutput

#endif


/* Mode API mapping */
extern FUNC(Rte_ModeType_EcuM_Mode, RTE_CODE) Rte_Mode_SWCVdyAdapt_RPModeVdy_currentMode( void );
#ifndef RTE_C
	#define Rte_Mode_RPModeVdy_currentMode  \
		Rte_Mode_SWCVdyAdapt_RPModeVdy_currentMode
#endif







#ifdef __cplusplus
	} /* extern "C" */
#endif /* __cplusplus */


#endif
