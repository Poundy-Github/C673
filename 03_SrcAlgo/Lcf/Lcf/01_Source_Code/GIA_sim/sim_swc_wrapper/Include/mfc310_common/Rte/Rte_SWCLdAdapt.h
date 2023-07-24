/**************************************************************************
This file is generated automatically by the RTE generator
Filename:	Rte_SWCLdAdapt.h
CESSAR-CT Version: 3.1.1.11
RTE Version: 3.2.0.1.3.0
Generated on:	Thu Jun 14 15:20:19 CEST 2012
**************************************************************************/


#ifndef _RTE_SWCLdAdapt_H_
#define _RTE_SWCLdAdapt_H_



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
  typedef CONSTP2CONST(Rte_CDS_SWCLdAdapt, AUTOMATIC, RTE_CONST) Rte_Instance;
#endif /* RTE_C */

/* SWC:SWCLdAdapt Indirect API */
	/* The name of the instance handle is Rte_Inst_<c> [Satisfies_rte sws 3793]. */
extern CONST(Rte_CDS_SWCLdAdapt, RTE_CONST) Rte_Instance_SWCLdAdapt;

#ifndef RTE_C

	/*  Provided ports */



	/*  Required ports */


#endif



/* runnable entry points (symbol) */

extern void LD_v_AdaptInit (GLB_fctp_AlgoInitialized_Callback* LD_fctp_Init_Callback); 
extern void LD_v_RteDummy (void); 


/* application error code */
#ifndef RTE_E_CSI_Timer64GetTimerValue_E_NOT_OK
  #define RTE_E_CSI_Timer64GetTimerValue_E_NOT_OK 1
#endif



/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/COMPONENTTYPES/IntBehLdAdapt/RunEntLdAdapt/SSCP_LDStoreOnlineCali */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWCLdAdapt_RPortLDStoreOnlineCali_OPNormLdStoreOnlineCali( INOUT P2VAR(S_MonoOnlineCalibration,AUTOMATIC,RTE_APPL_DATA) OnlineCali);
#ifndef RTE_C
  #define Rte_Call_RPortLDStoreOnlineCali_OPNormLdStoreOnlineCali Rte_Call_SWCLdAdapt_RPortLDStoreOnlineCali_OPNormLdStoreOnlineCali
#endif


/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/COMPONENTTYPES/IntBehLdAdapt/RunEntLdAdapt/SSCP_LDTimer64GetTimerValue */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWCLdAdapt_RPortLDTimer64GetTimerValue_OPTimer64GetTimerValue( OUT P2VAR(uint64,AUTOMATIC,RTE_APPL_DATA) timerValue);
#ifndef RTE_C
  #define Rte_Call_RPortLDTimer64GetTimerValue_OPTimer64GetTimerValue Rte_Call_SWCLdAdapt_RPortLDTimer64GetTimerValue_OPTimer64GetTimerValue
#endif






#ifndef RTE_C
  #define Rte_InitValue_RPortLDDebugMode_DEPAlgoDebugMode (0)
#endif


  /* Rte_Read Api mapping  [Satisfies_rte sws 1091].*/
  /* Std_ReturnType Rte_Read_<p>_<o>([IN Rte_Instance <instance>],OUT <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWCLdAdapt_RPortLDDebugMode_DEPAlgoDebugMode(OUT P2VAR(RTE_t_eAlgoDebugMode, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Read_RPortLDDebugMode_DEPAlgoDebugMode Rte_Read_SWCLdAdapt_RPortLDDebugMode_DEPAlgoDebugMode
#endif


  /* Rte_Read Api mapping  [Satisfies_rte sws 1091].*/
  /* Std_ReturnType Rte_Read_<p>_<o>([IN Rte_Instance <instance>],OUT <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWCLdAdapt_RPortLDIcImageCharOdd_DEPIcImageCharacteristics(OUT P2VAR(RTE_t_IC_S_ImageCharacteristics, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Read_RPortLDIcImageCharOdd_DEPIcImageCharacteristics Rte_Read_SWCLdAdapt_RPortLDIcImageCharOdd_DEPIcImageCharacteristics
#endif


  /* Rte_Read Api mapping  [Satisfies_rte sws 1091].*/
  /* Std_ReturnType Rte_Read_<p>_<o>([IN Rte_Instance <instance>],OUT <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWCLdAdapt_RPortLDIcStatResultsOdd_DEPIcStatisticalResults(OUT P2VAR(RTE_t_IC_S_StatisticalResults, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Read_RPortLDIcStatResultsOdd_DEPIcStatisticalResults Rte_Read_SWCLdAdapt_RPortLDIcStatResultsOdd_DEPIcStatisticalResults
#endif


  /* Rte_Read Api mapping  [Satisfies_rte sws 1091].*/
  /* Std_ReturnType Rte_Read_<p>_<o>([IN Rte_Instance <instance>],OUT <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWCLdAdapt_RPortLDLdpWarnRq_DEPLdpWarnRq(OUT P2VAR(LDPWarnRq_t, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Read_RPortLDLdpWarnRq_DEPLdpWarnRq Rte_Read_SWCLdAdapt_RPortLDLdpWarnRq_DEPLdpWarnRq
#endif


  /* Rte_Write Api mapping  [Satisfies_rte sws 1071], [Satisfies_rte sws 1280].*/
  /* Std_ReturnType Rte_Write_<p>_<o>([IN Rte_Instance <instance>],IN <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWCLdAdapt_PPortLDAlgoVersion_DEPAlgoVersion(IN P2VAR(RTE_t_AlgoVersion, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Write_PPortLDAlgoVersion_DEPAlgoVersion Rte_Write_SWCLdAdapt_PPortLDAlgoVersion_DEPAlgoVersion
#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(RTE_GB_t_FctBlockageData, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCLdAdapt_RunEntLdAdapt_RPortLDGbFctBlockage_DEPGbFctBlockage(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntLdAdapt_RPortLDGbFctBlockage_DEPGbFctBlockage \
    Rte_IRead_SWCLdAdapt_RunEntLdAdapt_RPortLDGbFctBlockage_DEPGbFctBlockage

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(RTE_t_TSAIFOutput, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCLdAdapt_RunEntLdAdapt_RPortLDTsaOutput_DEP_TsaOutput(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntLdAdapt_RPortLDTsaOutput_DEP_TsaOutput \
    Rte_IRead_SWCLdAdapt_RunEntLdAdapt_RPortLDTsaOutput_DEP_TsaOutput

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(RTE_t_VdyOutput, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCLdAdapt_RunEntLdAdapt_RPortLDVdyOutput_DEPVdyOutput(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntLdAdapt_RPortLDVdyOutput_DEPVdyOutput \
    Rte_IRead_SWCLdAdapt_RunEntLdAdapt_RPortLDVdyOutput_DEPVdyOutput

#endif


  /* Rte_IWrite Api mapping  [Satisfies_rte sws 3744], [Satisfies_rte sws 1302], [Satisfies_rte sws 3746], [Satisfies_rte sws 3747].*/
  /* void Rte_IWrite_<re>_<p>_<d>([IN RTE_Instance], IN <type>) */
extern FUNC(void, RTE_CODE) Rte_IWrite_SWCLdAdapt_RunEntLdAdapt_PPortLDOutput_DEP_LDLaneOutput(P2VAR(RTE_t_LDOutput, AUTOMATIC, RTE_APPL_DATA) arg1);
extern FUNC( P2VAR(RTE_t_LDOutput, AUTOMATIC, RTE_APPL_DATA), RTE_CODE ) Rte_IWriteRef_SWCLdAdapt_RunEntLdAdapt_PPortLDOutput_DEP_LDLaneOutput();

#ifndef RTE_C
  #define Rte_IWrite_RunEntLdAdapt_PPortLDOutput_DEP_LDLaneOutput \
    Rte_IWrite_SWCLdAdapt_RunEntLdAdapt_PPortLDOutput_DEP_LDLaneOutput

  #define Rte_IWriteRef_RunEntLdAdapt_PPortLDOutput_DEP_LDLaneOutput \
    Rte_IWriteRef_SWCLdAdapt_RunEntLdAdapt_PPortLDOutput_DEP_LDLaneOutput

#endif

  /* Rte_IWrite Api mapping  [Satisfies_rte sws 3744], [Satisfies_rte sws 1302], [Satisfies_rte sws 3746], [Satisfies_rte sws 3747].*/
  /* void Rte_IWrite_<re>_<p>_<d>([IN RTE_Instance], IN <type>) */
extern FUNC(void, RTE_CODE) Rte_IWrite_SWCLdAdapt_RunEntLdAdapt_PPortLDParameterInOut_DEPLDParameterInOut(P2VAR(S_MonoOnlineCalibration, AUTOMATIC, RTE_APPL_DATA) arg1);
extern FUNC( P2VAR(S_MonoOnlineCalibration, AUTOMATIC, RTE_APPL_DATA), RTE_CODE ) Rte_IWriteRef_SWCLdAdapt_RunEntLdAdapt_PPortLDParameterInOut_DEPLDParameterInOut();

#ifndef RTE_C
  #define Rte_IWrite_RunEntLdAdapt_PPortLDParameterInOut_DEPLDParameterInOut \
    Rte_IWrite_SWCLdAdapt_RunEntLdAdapt_PPortLDParameterInOut_DEPLDParameterInOut

  #define Rte_IWriteRef_RunEntLdAdapt_PPortLDParameterInOut_DEPLDParameterInOut \
    Rte_IWriteRef_SWCLdAdapt_RunEntLdAdapt_PPortLDParameterInOut_DEPLDParameterInOut

#endif


/* Mode API mapping */
extern FUNC(Rte_ModeType_EcuM_Mode, RTE_CODE) Rte_Mode_SWCLdAdapt_RPortModeLdAdapt_currentMode( void );
#ifndef RTE_C
	#define Rte_Mode_RPortModeLdAdapt_currentMode  \
		Rte_Mode_SWCLdAdapt_RPortModeLdAdapt_currentMode
#endif







#ifdef __cplusplus
	} /* extern "C" */
#endif /* __cplusplus */


#endif
