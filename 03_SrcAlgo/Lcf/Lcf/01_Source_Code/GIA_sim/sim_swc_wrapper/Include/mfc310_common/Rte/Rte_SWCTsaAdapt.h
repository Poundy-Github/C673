/**************************************************************************
This file is generated automatically by the RTE generator
Filename:	Rte_SWCTsaAdapt.h
CESSAR-CT Version: 3.1.1.11
RTE Version: 3.2.0.1.3.0
Generated on:	Thu Oct 18 14:08:55 CEST 2012
**************************************************************************/


#ifndef _RTE_SWCTsaAdapt_H_
#define _RTE_SWCTsaAdapt_H_



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
  typedef CONSTP2CONST(Rte_CDS_SWCTsaAdapt, AUTOMATIC, RTE_CONST) Rte_Instance;
#endif /* RTE_C */

/* SWC:SWCTsaAdapt Indirect API */
	/* The name of the instance handle is Rte_Inst_<c> [Satisfies_rte sws 3793]. */
extern CONST(Rte_CDS_SWCTsaAdapt, RTE_CONST) Rte_Instance_SWCTsaAdapt;

#ifndef RTE_C

	/*  Provided ports */



	/*  Required ports */


#endif



/* runnable entry points (symbol) */

extern void TSA_v_AdaptInit (void); 
extern void TSA_v_AdaptExec (void); 


/* application error code */
#ifndef RTE_E_CSI_Timer64GetTimerValue_E_NOT_OK
  #define RTE_E_CSI_Timer64GetTimerValue_E_NOT_OK 1
#endif



/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/COMPONENTTYPES/IntBehTsaAdapt/RunEntTsaAdaptExec/SSCP_TsaTimer64GetTimerValue */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWCTsaAdapt_RPortTsaTimer64GetTimerValue_OPTimer64GetTimerValue( OUT P2VAR(uint64,AUTOMATIC,RTE_APPL_DATA) timerValue);
#ifndef RTE_C
  #define Rte_Call_RPortTsaTimer64GetTimerValue_OPTimer64GetTimerValue Rte_Call_SWCTsaAdapt_RPortTsaTimer64GetTimerValue_OPTimer64GetTimerValue
#endif






#ifndef RTE_C
  #define Rte_InitValue_RPortTsaDebugMode_DEPAlgoDebugMode (0)
#endif

#ifndef RTE_C
  #define Rte_InitValue_RPortTsaDiagInput_DEPRequestDataSrc (0)
#endif

#ifndef RTE_C
  #define Rte_InitValue_RPortTsaDiagInput_DEPResetBlockageData (0)
#endif

#ifndef RTE_C
  #define Rte_InitValue_RPortTsaDispTest_DEPTsaDispTest (0)
#endif

#ifndef RTE_C
  #define Rte_InitValue_RPortTsaIgnSwitchState_DEPIgnState (0)
#endif

#ifndef RTE_C
  #define Rte_InitValue_RPortTsaModeSelect_DEPTsaModeSelect (0)
#endif

#ifndef RTE_C
  #define Rte_InitValue_RPortTsaSrTriggerRef_DEPTriggerRef (0)
#endif

#ifndef RTE_C
  #define Rte_InitValue_PPortTsaDispTest_DEPTsaDispTest (0)
#endif

#ifndef RTE_C
  #define Rte_InitValue_PPortTsaProcessState_DEPTsaProcessState (0)
#endif

#ifndef RTE_C
  #define Rte_InitValue_PPortTsaTaskState_DEP_VehicleAlgoTaskState (0)
#endif


  /* Rte_Read Api mapping  [Satisfies_rte sws 1091].*/
  /* Std_ReturnType Rte_Read_<p>_<o>([IN Rte_Instance <instance>],OUT <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWCTsaAdapt_RPortTsaDate_DEPTsaDate(OUT P2VAR(RTE_t_TSAIFInputDate, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Read_RPortTsaDate_DEPTsaDate Rte_Read_SWCTsaAdapt_RPortTsaDate_DEPTsaDate
#endif


  /* Rte_Read Api mapping  [Satisfies_rte sws 1091].*/
  /* Std_ReturnType Rte_Read_<p>_<o>([IN Rte_Instance <instance>],OUT <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWCTsaAdapt_RPortTsaDebugMode_DEPAlgoDebugMode(OUT P2VAR(RTE_t_eAlgoDebugMode, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Read_RPortTsaDebugMode_DEPAlgoDebugMode Rte_Read_SWCTsaAdapt_RPortTsaDebugMode_DEPAlgoDebugMode
#endif


  /* Rte_Read Api mapping  [Satisfies_rte sws 1091].*/
  /* Std_ReturnType Rte_Read_<p>_<o>([IN Rte_Instance <instance>],OUT <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWCTsaAdapt_RPortTsaDispTest_DEPTsaDispTest(OUT P2VAR(RTE_t_eTSADispTest, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Read_RPortTsaDispTest_DEPTsaDispTest Rte_Read_SWCTsaAdapt_RPortTsaDispTest_DEPTsaDispTest
#endif


  /* Rte_Read Api mapping  [Satisfies_rte sws 1091].*/
  /* Std_ReturnType Rte_Read_<p>_<o>([IN Rte_Instance <instance>],OUT <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWCTsaAdapt_RPortTsaModeSelect_DEPTsaModeSelect(OUT P2VAR(RTE_t_TSAIFModeSelect, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Read_RPortTsaModeSelect_DEPTsaModeSelect Rte_Read_SWCTsaAdapt_RPortTsaModeSelect_DEPTsaModeSelect
#endif


  /* Rte_Read Api mapping  [Satisfies_rte sws 1091].*/
  /* Std_ReturnType Rte_Read_<p>_<o>([IN Rte_Instance <instance>],OUT <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWCTsaAdapt_RPortTsaTime_DEPTsaTime(OUT P2VAR(RTE_t_TSAIFInputTime, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Read_RPortTsaTime_DEPTsaTime Rte_Read_SWCTsaAdapt_RPortTsaTime_DEPTsaTime
#endif


  /* Rte_Write Api mapping  [Satisfies_rte sws 1071], [Satisfies_rte sws 1280].*/
  /* Std_ReturnType Rte_Write_<p>_<o>([IN Rte_Instance <instance>],IN <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWCTsaAdapt_PPortTsaAlgoVersion_DEPAlgoVersion(IN P2VAR(RTE_t_AlgoVersion, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Write_PPortTsaAlgoVersion_DEPAlgoVersion Rte_Write_SWCTsaAdapt_PPortTsaAlgoVersion_DEPAlgoVersion
#endif


  /* Rte_Write Api mapping  [Satisfies_rte sws 1071], [Satisfies_rte sws 1280].*/
  /* Std_ReturnType Rte_Write_<p>_<o>([IN Rte_Instance <instance>],IN <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWCTsaAdapt_PPortTsaDispTest_DEPTsaDispTest(IN VAR(RTE_t_eTSADispTest, AUTOMATIC) arg1);
#ifndef RTE_C
  #define Rte_Write_PPortTsaDispTest_DEPTsaDispTest Rte_Write_SWCTsaAdapt_PPortTsaDispTest_DEPTsaDispTest
#endif


  /* Rte_Write Api mapping  [Satisfies_rte sws 1071], [Satisfies_rte sws 1280].*/
  /* Std_ReturnType Rte_Write_<p>_<o>([IN Rte_Instance <instance>],IN <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWCTsaAdapt_PPortTsaProcessState_DEPTsaProcessState(IN VAR(RTE_eTSAIFOutputProcessState, AUTOMATIC) arg1);
#ifndef RTE_C
  #define Rte_Write_PPortTsaProcessState_DEPTsaProcessState Rte_Write_SWCTsaAdapt_PPortTsaProcessState_DEPTsaProcessState
#endif


  /* Rte_Write Api mapping  [Satisfies_rte sws 1071], [Satisfies_rte sws 1280].*/
  /* Std_ReturnType Rte_Write_<p>_<o>([IN Rte_Instance <instance>],IN <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWCTsaAdapt_PPortTsaTaskState_DEP_VehicleAlgoTaskState(IN VAR(RTE_t_SYSMultiRunTaskState, AUTOMATIC) arg1);
#ifndef RTE_C
  #define Rte_Write_PPortTsaTaskState_DEP_VehicleAlgoTaskState Rte_Write_SWCTsaAdapt_PPortTsaTaskState_DEP_VehicleAlgoTaskState
#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(RTE_t_TSAIFSRData, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCTsaAdapt_RunEntTsaAdaptExec_RPortSrOutput_DEP_SrOutput(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntTsaAdaptExec_RPortSrOutput_DEP_SrOutput \
    Rte_IRead_SWCTsaAdapt_RunEntTsaAdaptExec_RPortSrOutput_DEP_SrOutput

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(S_CamPos_CALIOutput, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCTsaAdapt_RunEntTsaAdaptExec_RPortTsaCamPos_DEP_SensorAngles(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntTsaAdaptExec_RPortTsaCamPos_DEP_SensorAngles \
    Rte_IRead_SWCTsaAdapt_RunEntTsaAdaptExec_RPortTsaCamPos_DEP_SensorAngles

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(VAR(uint8, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCTsaAdapt_RunEntTsaAdaptExec_RPortTsaDiagInput_DEPRequestDataSrc(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntTsaAdaptExec_RPortTsaDiagInput_DEPRequestDataSrc \
    Rte_IRead_SWCTsaAdapt_RunEntTsaAdaptExec_RPortTsaDiagInput_DEPRequestDataSrc

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(VAR(boolean, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCTsaAdapt_RunEntTsaAdaptExec_RPortTsaDiagInput_DEPResetBlockageData(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntTsaAdaptExec_RPortTsaDiagInput_DEPResetBlockageData \
    Rte_IRead_SWCTsaAdapt_RunEntTsaAdaptExec_RPortTsaDiagInput_DEPResetBlockageData

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(RTE_t_TSAIFInputGPSPos, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCTsaAdapt_RunEntTsaAdaptExec_RPortTsaGPSPos_DEPGPSPos(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntTsaAdaptExec_RPortTsaGPSPos_DEPGPSPos \
    Rte_IRead_SWCTsaAdapt_RunEntTsaAdaptExec_RPortTsaGPSPos_DEPGPSPos

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(RTE_GB_t_FctBlockageData, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCTsaAdapt_RunEntTsaAdaptExec_RPortTsaGbFctBlockage_DEPGbFctBlockage(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntTsaAdaptExec_RPortTsaGbFctBlockage_DEPGbFctBlockage \
    Rte_IRead_SWCTsaAdapt_RunEntTsaAdaptExec_RPortTsaGbFctBlockage_DEPGbFctBlockage

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(VAR(NORM_t_eIgnState, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCTsaAdapt_RunEntTsaAdaptExec_RPortTsaIgnSwitchState_DEPIgnState(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntTsaAdaptExec_RPortTsaIgnSwitchState_DEPIgnState \
    Rte_IRead_SWCTsaAdapt_RunEntTsaAdaptExec_RPortTsaIgnSwitchState_DEPIgnState

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(RTE_t_LDOutput, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCTsaAdapt_RunEntTsaAdaptExec_RPortTsaLDOutput_DEP_LDLaneOutput(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntTsaAdaptExec_RPortTsaLDOutput_DEP_LDLaneOutput \
    Rte_IRead_SWCTsaAdapt_RunEntTsaAdaptExec_RPortTsaLDOutput_DEP_LDLaneOutput

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(S_MonoOnlineCalibration, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCTsaAdapt_RunEntTsaAdaptExec_RPortTsaLDParameterInOut_DEPLDParameterInOut(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntTsaAdaptExec_RPortTsaLDParameterInOut_DEPLDParameterInOut \
    Rte_IRead_SWCTsaAdapt_RunEntTsaAdaptExec_RPortTsaLDParameterInOut_DEPLDParameterInOut

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(RTE_t_MAPIFMapData, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCTsaAdapt_RunEntTsaAdaptExec_RPortTsaMapData_DEP_MapData(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntTsaAdaptExec_RPortTsaMapData_DEP_MapData \
    Rte_IRead_SWCTsaAdapt_RunEntTsaAdaptExec_RPortTsaMapData_DEP_MapData

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(RTE_t_MAPIFOutputSystemInfo, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCTsaAdapt_RunEntTsaAdaptExec_RPortTsaMapSystemInfo_DEPMapSystemInfo(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntTsaAdaptExec_RPortTsaMapSystemInfo_DEPMapSystemInfo \
    Rte_IRead_SWCTsaAdapt_RunEntTsaAdaptExec_RPortTsaMapSystemInfo_DEPMapSystemInfo

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(RTE_t_TSAIFObjData, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCTsaAdapt_RunEntTsaAdaptExec_RPortTsaObjData_DEPObjData(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntTsaAdaptExec_RPortTsaObjData_DEPObjData \
    Rte_IRead_SWCTsaAdapt_RunEntTsaAdaptExec_RPortTsaObjData_DEPObjData

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(RTE_t_TSAIFOnlineCalibrationInfo, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCTsaAdapt_RunEntTsaAdaptExec_RPortTsaOnlineCali_DEPOnlineCalibrationInfo(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntTsaAdaptExec_RPortTsaOnlineCali_DEPOnlineCalibrationInfo \
    Rte_IRead_SWCTsaAdapt_RunEntTsaAdaptExec_RPortTsaOnlineCali_DEPOnlineCalibrationInfo

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(RTE_t_TSAIFSettings, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCTsaAdapt_RunEntTsaAdaptExec_RPortTsaSettings_DEP_TsaSettings(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntTsaAdaptExec_RPortTsaSettings_DEP_TsaSettings \
    Rte_IRead_SWCTsaAdapt_RunEntTsaAdaptExec_RPortTsaSettings_DEP_TsaSettings

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(VAR(uint64, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCTsaAdapt_RunEntTsaAdaptExec_RPortTsaSrTriggerRef_DEPTriggerRef(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntTsaAdaptExec_RPortTsaSrTriggerRef_DEPTriggerRef \
    Rte_IRead_SWCTsaAdapt_RunEntTsaAdaptExec_RPortTsaSrTriggerRef_DEPTriggerRef

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(RTE_t_StWhlAnglStat, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCTsaAdapt_RunEntTsaAdaptExec_RPortTsaStWhlAnglStat_DEPStWhlAnglStat(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntTsaAdaptExec_RPortTsaStWhlAnglStat_DEPStWhlAnglStat \
    Rte_IRead_SWCTsaAdapt_RunEntTsaAdaptExec_RPortTsaStWhlAnglStat_DEPStWhlAnglStat

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(RTE_t_TSAIFInputFloat32, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCTsaAdapt_RunEntTsaAdaptExec_RPortTsaTachometerSpeed_DEPTachometerSpeed(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntTsaAdaptExec_RPortTsaTachometerSpeed_DEPTachometerSpeed \
    Rte_IRead_SWCTsaAdapt_RunEntTsaAdaptExec_RPortTsaTachometerSpeed_DEPTachometerSpeed

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(RTE_t_VdyOutput, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCTsaAdapt_RunEntTsaAdaptExec_RPortTsaVdyOutput_DEPVdyOutput(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntTsaAdaptExec_RPortTsaVdyOutput_DEPVdyOutput \
    Rte_IRead_SWCTsaAdapt_RunEntTsaAdaptExec_RPortTsaVdyOutput_DEPVdyOutput

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(VehSig_t, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCTsaAdapt_RunEntTsaAdaptExec_RPortTsaVehSig_DEPBswVehSig(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntTsaAdaptExec_RPortTsaVehSig_DEPBswVehSig \
    Rte_IRead_SWCTsaAdapt_RunEntTsaAdaptExec_RPortTsaVehSig_DEPBswVehSig

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(RTE_t_TSAIFInputVehTrailerState, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCTsaAdapt_RunEntTsaAdaptExec_RPortTsaVehTrailerState_DEPVehTrailerState(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntTsaAdaptExec_RPortTsaVehTrailerState_DEPVehTrailerState \
    Rte_IRead_SWCTsaAdapt_RunEntTsaAdaptExec_RPortTsaVehTrailerState_DEPVehTrailerState

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(RTE_t_WiperInfo, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCTsaAdapt_RunEntTsaAdaptExec_RPortTsaWiperSignals_DEP_WiperSignals(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntTsaAdaptExec_RPortTsaWiperSignals_DEP_WiperSignals \
    Rte_IRead_SWCTsaAdapt_RunEntTsaAdaptExec_RPortTsaWiperSignals_DEP_WiperSignals

#endif


  /* Rte_IWrite Api mapping  [Satisfies_rte sws 3744], [Satisfies_rte sws 1302], [Satisfies_rte sws 3746], [Satisfies_rte sws 3747].*/
  /* void Rte_IWrite_<re>_<p>_<d>([IN RTE_Instance], IN <type>) */
extern FUNC(void, RTE_CODE) Rte_IWrite_SWCTsaAdapt_RunEntTsaAdaptExec_PPortTsaOutput_DEP_TsaOutput(P2VAR(RTE_t_TSAIFOutput, AUTOMATIC, RTE_APPL_DATA) arg1);
extern FUNC( P2VAR(RTE_t_TSAIFOutput, AUTOMATIC, RTE_APPL_DATA), RTE_CODE ) Rte_IWriteRef_SWCTsaAdapt_RunEntTsaAdaptExec_PPortTsaOutput_DEP_TsaOutput();

#ifndef RTE_C
  #define Rte_IWrite_RunEntTsaAdaptExec_PPortTsaOutput_DEP_TsaOutput \
    Rte_IWrite_SWCTsaAdapt_RunEntTsaAdaptExec_PPortTsaOutput_DEP_TsaOutput

  #define Rte_IWriteRef_RunEntTsaAdaptExec_PPortTsaOutput_DEP_TsaOutput \
    Rte_IWriteRef_SWCTsaAdapt_RunEntTsaAdaptExec_PPortTsaOutput_DEP_TsaOutput

#endif


/* Mode API mapping */
extern FUNC(Rte_ModeType_EcuM_Mode, RTE_CODE) Rte_Mode_SWCTsaAdapt_RPortModeTsaAdapt_currentMode( void );
#ifndef RTE_C
	#define Rte_Mode_RPortModeTsaAdapt_currentMode  \
		Rte_Mode_SWCTsaAdapt_RPortModeTsaAdapt_currentMode
#endif







#ifdef __cplusplus
	} /* extern "C" */
#endif /* __cplusplus */


#endif
