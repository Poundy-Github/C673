/**************************************************************************
This file is generated automatically by the RTE generator
Filename:	Rte_SWCNorm.h
CESSAR-CT Version: 3.1.1.11
RTE Version: 3.2.0.1.3.0
Generated on:	Thu Oct 18 18:23:12 CEST 2012
**************************************************************************/


#ifndef _RTE_SWCNorm_H_
#define _RTE_SWCNorm_H_



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
  typedef CONSTP2CONST(Rte_CDS_SWCNorm, AUTOMATIC, RTE_CONST) Rte_Instance;
#endif /* RTE_C */

/* SWC:SWCNorm Indirect API */
	/* The name of the instance handle is Rte_Inst_<c> [Satisfies_rte sws 3793]. */
extern CONST(Rte_CDS_SWCNorm, RTE_CONST) Rte_Instance_SWCNorm;

#ifndef RTE_C

	/*  Provided ports */



	/*  Required ports */


#endif



/* runnable entry points (symbol) */

extern void Norm_v_InitRx (void); 
extern void Norm_v_InitTx (void); 
extern void NORM_v_HLA_finished (void); 
extern void Norm_v_DemScRx (void); 
extern void NORM_v_FCT_finished (void); 
extern void NORM_v_FCT_RxFct (void); 
extern void NORM_v_Hla_RxFct (void); 
extern void NORM_v_IpcFinished (void); 
extern void NORM_v_MAP_RxFct (void); 
extern void Norm_v_SendFODObjSeq (void); 
extern void NORM_v_TSA_finished (void); 
extern void NORM_v_TSA_RxFct (void); 
extern void NORM_v_VdyFinished (void); 
extern void NORM_v_VlnFinished (void); 
extern void NORM_v_CommonRxFct (void); 
/* runnable entry points (symbol) for servers */
extern FUNC(Std_ReturnType, RTE_APPL_CODE) NORM_v_GetAlgoVersion( IN VAR(RTE_t_eAlgoId,AUTOMATIC) AlgoId, OUT P2VAR(uint32,AUTOMATIC,RTE_APPL_DATA) Version);
extern FUNC(void, RTE_APPL_CODE) Norm_v_GetMCUSystemData( OUT P2VAR(RTE_t_MCUSystemData,AUTOMATIC,RTE_APPL_DATA) ps_mcusysdata);
extern FUNC(void, RTE_APPL_CODE) Norm_v_GetMonoDSPSystemData( OUT P2VAR(RTE_t_DSPMonoSystemData,AUTOMATIC,RTE_APPL_DATA) ps_monosysdata);
extern FUNC(void, RTE_APPL_CODE) Norm_v_GetStereoDSPSystemData( OUT P2VAR(RTE_t_DSPStereoSystemData,AUTOMATIC,RTE_APPL_DATA) ps_stereosysdata);
extern FUNC(void, RTE_APPL_CODE) NORM_v_LD_StoreOnlineCali( INOUT P2VAR(S_MonoOnlineCalibration,AUTOMATIC,RTE_APPL_DATA) OnlineCali);
extern FUNC(void, RTE_APPL_CODE) Norm_v_SendRoE( INOUT P2VAR(SwcRoElite_MsgType,AUTOMATIC,RTE_APPL_DATA) data);
extern FUNC(void, RTE_APPL_CODE) Norm_v_SetMCUSystemData( IN VAR(uint8,AUTOMATIC) FillType);
extern FUNC(void, RTE_APPL_CODE) Norm_v_SetReqMonoDspState( IN VAR(uint8,AUTOMATIC) NewState);
extern FUNC(void, RTE_APPL_CODE) NORM_v_SetSignal_FrontWhlAngel( IN VAR(uint8,AUTOMATIC) FrTick);
extern FUNC(void, RTE_APPL_CODE) NORM_v_SetSignal_PreviewAccel( IN VAR(uint8,AUTOMATIC) FrTick);
extern FUNC(void, RTE_APPL_CODE) NORM_v_SetSignal_StWhlAngel( IN VAR(uint8,AUTOMATIC) FrTick);
extern FUNC(void, RTE_APPL_CODE) NORM_v_SetSignal_TachoSpd( IN VAR(uint8,AUTOMATIC) FrTick);
extern FUNC(void, RTE_APPL_CODE) NORM_v_SetSignal_VehDynAccel( IN VAR(uint8,AUTOMATIC) FrTick);
extern FUNC(void, RTE_APPL_CODE) NORM_v_SetSignal_WheelLT( IN VAR(uint8,AUTOMATIC) FrTick);
extern FUNC(void, RTE_APPL_CODE) NORM_v_SetSignal_WheelRT( IN VAR(uint8,AUTOMATIC) FrTick);
extern FUNC(void, RTE_APPL_CODE) NORM_v_SetSignal_YawRate( IN VAR(uint8,AUTOMATIC) FrTick);
extern FUNC(void, RTE_APPL_CODE) Norm_v_SetReqStereoDspState( IN VAR(uint8,AUTOMATIC) NewState);
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
  extern FUNC(Std_ReturnType, RTE_APPL_CODE) Norm_v_NvMToRteHandler( IN VAR(BlockIdType pdav_0, AUTOMATIC), IN P2CONST(UInt8,AUTOMATIC,RTE_APPL_DATA) DstPtr);
#else
  extern FUNC(Std_ReturnType, RTE_APPL_CODE) Norm_v_NvMToRteHandler( IN VAR(BlockIdType pdav_0, AUTOMATIC), IN P2CONST(DstPtrType,AUTOMATIC,RTE_APPL_DATA) DstPtr);
#endif



/* application error code */
#ifndef RTE_E_CSI_Timer64GetTimerValue_E_NOT_OK
  #define RTE_E_CSI_Timer64GetTimerValue_E_NOT_OK 1
#endif
#ifndef RTE_E_NvMService_E_NOK
  #define RTE_E_NvMService_E_NOK 1
#endif
#ifndef RTE_E_NvMService_E_OK
  #define RTE_E_NvMService_E_OK 0
#endif
#ifndef RTE_E_CSI_NormGetAlgoVersion_E_NOT_OK
  #define RTE_E_CSI_NormGetAlgoVersion_E_NOT_OK 1
#endif
#ifndef RTE_E_CSI_NormGetAlgoVersion_E_OK
  #define RTE_E_CSI_NormGetAlgoVersion_E_OK 0
#endif



/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/COMPONENTTYPES/IntBehNorm/RunEntNormIpc/SSCP_NormBswGetAdcData */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWCNorm_RPortNormBswGetAdcData_OPGetAdcData( IN VAR(uint8,AUTOMATIC) AdcChannel, OUT P2VAR(float32,AUTOMATIC,RTE_APPL_DATA) CalcVal, OUT P2VAR(uint32,AUTOMATIC,RTE_APPL_DATA) Timestamp);
#ifndef RTE_C
  #define Rte_Call_RPortNormBswGetAdcData_OPGetAdcData Rte_Call_SWCNorm_RPortNormBswGetAdcData_OPGetAdcData
#endif


/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/COMPONENTTYPES/IntBehNorm/RunEntNormRx/SSCP_NormTimer64GetTimerValue */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWCNorm_RPortNormTimer64GetTimerValue_OPTimer64GetTimerValue( OUT P2VAR(uint64,AUTOMATIC,RTE_APPL_DATA) timerValue);
#ifndef RTE_C
  #define Rte_Call_RPortNormTimer64GetTimerValue_OPTimer64GetTimerValue Rte_Call_SWCNorm_RPortNormTimer64GetTimerValue_OPTimer64GetTimerValue
#endif


/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/COMPONENTTYPES/IntBehNorm/RunEntNormNvmToRteHandler/SSCP_NormNvmSrLearnValues */
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
  extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWCNorm_RPortNvMSrLearValue_ReadBlock( IN P2CONST(UInt8,AUTOMATIC,RTE_APPL_DATA) DstPtr);
#else
  extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWCNorm_RPortNvMSrLearValue_ReadBlock( IN P2CONST(DstPtrType,AUTOMATIC,RTE_APPL_DATA) DstPtr);
#endif
#ifndef RTE_C
  #define Rte_Call_RPortNvMSrLearValue_ReadBlock Rte_Call_SWCNorm_RPortNvMSrLearValue_ReadBlock
#endif






#ifndef RTE_C
  #define Rte_InitValue_RPortNormCalibPatternType_DEPCalibPatternType (0)
#endif

#ifndef RTE_C
  #define Rte_InitValue_RPortNormFodDebugMode_DEPAlgoDebugMode (0)
#endif

#ifndef RTE_C
  #define Rte_InitValue_RPortNormLrDebugMode_DEPAlgoDebugMode (0)
#endif

#ifndef RTE_C
  #define Rte_InitValue_RPortNormPodDebugMode_DEPAlgoDebugMode (0)
#endif

#ifndef RTE_C
  #define Rte_InitValue_RPortNormPrDebugMode_DEPAlgoDebugMode (0)
#endif

#ifndef RTE_C
  #define Rte_InitValue_RPortNormPvDebugMode_DEPAlgoDebugMode (0)
#endif

#ifndef RTE_C
  #define Rte_InitValue_RPortNormSacDebugMode_DEPAlgoDebugMode (0)
#endif

#ifndef RTE_C
  #define Rte_InitValue_RPortNormSlneDebugMode_DEPAlgoDebugMode (0)
#endif

#ifndef RTE_C
  #define Rte_InitValue_RPortNormSrDebugMode_DEPAlgoDebugMode (0)
#endif

#ifndef RTE_C
  #define Rte_InitValue_PPortAirTempOutside_DEP_AirTempOutside (0)
#endif

#ifndef RTE_C
  #define Rte_InitValue_PPortIgnState_DEPIgnState (0)
#endif

#ifndef RTE_C
  #define Rte_InitValue_PPortNormAldwMode_DEP_FctAldwMode (0)
#endif

#ifndef RTE_C
  #define Rte_InitValue_PPortNormDefrostButton_DEPDefrostButton (0)
#endif

#ifndef RTE_C
  #define Rte_InitValue_PPortNormNightviewState_DEPNightviewState (0)
#endif

#ifndef RTE_C
  #define Rte_InitValue_PPortNormSrTriggerRef_DEPTriggerRef (0)
#endif

#ifndef RTE_C
  #define Rte_InitValue_PPortNormSysExtTester_DidA_ExtTest_Pres (0)
#endif

#ifndef RTE_C
  #define Rte_InitValue_PPortNormSysOdometer_Odo (0)
#endif

#ifndef RTE_C
  #define Rte_InitValue_PPortNormSysTransportationMode_PN14_TransMd_Stat (0)
#endif

#ifndef RTE_C
  #define Rte_InitValue_PPortNormTsaModeSelect_DEPTsaModeSelect (0)
#endif

#ifndef RTE_C
  #define Rte_InitValue_PPortRollTestMd_DEP_RollTestMd (0)
#endif


  /* Rte_Read Api mapping  [Satisfies_rte sws 1091].*/
  /* Std_ReturnType Rte_Read_<p>_<o>([IN Rte_Instance <instance>],OUT <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWCNorm_RPortNormCaliAlgoVersion_DEPAlgoVersion(OUT P2VAR(RTE_t_AlgoVersion, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Read_RPortNormCaliAlgoVersion_DEPAlgoVersion Rte_Read_SWCNorm_RPortNormCaliAlgoVersion_DEPAlgoVersion
#endif


  /* Rte_Read Api mapping  [Satisfies_rte sws 1091].*/
  /* Std_ReturnType Rte_Read_<p>_<o>([IN Rte_Instance <instance>],OUT <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWCNorm_RPortNormFctAlgoVersion_DEPAlgoVersion(OUT P2VAR(RTE_t_AlgoVersion, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Read_RPortNormFctAlgoVersion_DEPAlgoVersion Rte_Read_SWCNorm_RPortNormFctAlgoVersion_DEPAlgoVersion
#endif


  /* Rte_Read Api mapping  [Satisfies_rte sws 1091].*/
  /* Std_ReturnType Rte_Read_<p>_<o>([IN Rte_Instance <instance>],OUT <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWCNorm_RPortNormGbAlgoVersion_DEPAlgoVersion(OUT P2VAR(RTE_t_AlgoVersion, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Read_RPortNormGbAlgoVersion_DEPAlgoVersion Rte_Read_SWCNorm_RPortNormGbAlgoVersion_DEPAlgoVersion
#endif


  /* Rte_Read Api mapping  [Satisfies_rte sws 1091].*/
  /* Std_ReturnType Rte_Read_<p>_<o>([IN Rte_Instance <instance>],OUT <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWCNorm_RPortNormHlaAlgoVersion_DEPAlgoVersion(OUT P2VAR(RTE_t_AlgoVersion, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Read_RPortNormHlaAlgoVersion_DEPAlgoVersion Rte_Read_SWCNorm_RPortNormHlaAlgoVersion_DEPAlgoVersion
#endif


  /* Rte_Read Api mapping  [Satisfies_rte sws 1091].*/
  /* Std_ReturnType Rte_Read_<p>_<o>([IN Rte_Instance <instance>],OUT <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWCNorm_RPortNormIcVersion_DEPAlgoVersion(OUT P2VAR(RTE_t_AlgoVersion, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Read_RPortNormIcVersion_DEPAlgoVersion Rte_Read_SWCNorm_RPortNormIcVersion_DEPAlgoVersion
#endif


  /* Rte_Read Api mapping  [Satisfies_rte sws 1091].*/
  /* Std_ReturnType Rte_Read_<p>_<o>([IN Rte_Instance <instance>],OUT <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWCNorm_RPortNormLdAlgoVersion_DEPAlgoVersion(OUT P2VAR(RTE_t_AlgoVersion, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Read_RPortNormLdAlgoVersion_DEPAlgoVersion Rte_Read_SWCNorm_RPortNormLdAlgoVersion_DEPAlgoVersion
#endif


  /* Rte_Read Api mapping  [Satisfies_rte sws 1091].*/
  /* Std_ReturnType Rte_Read_<p>_<o>([IN Rte_Instance <instance>],OUT <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWCNorm_RPortNormMapAlgoVersion_DEPAlgoVersion(OUT P2VAR(RTE_t_AlgoVersion, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Read_RPortNormMapAlgoVersion_DEPAlgoVersion Rte_Read_SWCNorm_RPortNormMapAlgoVersion_DEPAlgoVersion
#endif


  /* Rte_Read Api mapping  [Satisfies_rte sws 1091].*/
  /* Std_ReturnType Rte_Read_<p>_<o>([IN Rte_Instance <instance>],OUT <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWCNorm_RPortNormTsaAlgoVersion_DEPAlgoVersion(OUT P2VAR(RTE_t_AlgoVersion, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Read_RPortNormTsaAlgoVersion_DEPAlgoVersion Rte_Read_SWCNorm_RPortNormTsaAlgoVersion_DEPAlgoVersion
#endif


  /* Rte_Read Api mapping  [Satisfies_rte sws 1091].*/
  /* Std_ReturnType Rte_Read_<p>_<o>([IN Rte_Instance <instance>],OUT <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWCNorm_RPortNormVdyAlgoVersion_DEPAlgoVersion(OUT P2VAR(RTE_t_AlgoVersion, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Read_RPortNormVdyAlgoVersion_DEPAlgoVersion Rte_Read_SWCNorm_RPortNormVdyAlgoVersion_DEPAlgoVersion
#endif


  /* Rte_Read Api mapping  [Satisfies_rte sws 1091].*/
  /* Std_ReturnType Rte_Read_<p>_<o>([IN Rte_Instance <instance>],OUT <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWCNorm_RPortNormVlnAlgoVersion_DEPAlgoVersion(OUT P2VAR(RTE_t_AlgoVersion, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Read_RPortNormVlnAlgoVersion_DEPAlgoVersion Rte_Read_SWCNorm_RPortNormVlnAlgoVersion_DEPAlgoVersion
#endif


  /* Rte_Read Api mapping  [Satisfies_rte sws 1091].*/
  /* Std_ReturnType Rte_Read_<p>_<o>([IN Rte_Instance <instance>],OUT <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWCNorm_RPortNormNvObject_DEP_HlaNvObject(OUT P2VAR(RTE_HLAF_t_NightView, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Read_RPortNormNvObject_DEP_HlaNvObject Rte_Read_SWCNorm_RPortNormNvObject_DEP_HlaNvObject
#endif


  /* Rte_Read Api mapping  [Satisfies_rte sws 1091].*/
  /* Std_ReturnType Rte_Read_<p>_<o>([IN Rte_Instance <instance>],OUT <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWCNorm_RPortNormCaliPatPos_DEP_CaliPatternPosition(OUT P2VAR(RTE_t_DiagPatternPosition, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Read_RPortNormCaliPatPos_DEP_CaliPatternPosition Rte_Read_SWCNorm_RPortNormCaliPatPos_DEP_CaliPatternPosition
#endif


  /* Rte_Read Api mapping  [Satisfies_rte sws 1091].*/
  /* Std_ReturnType Rte_Read_<p>_<o>([IN Rte_Instance <instance>],OUT <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWCNorm_RPortNormFodDebugMode_DEPAlgoDebugMode(OUT P2VAR(RTE_t_eAlgoDebugMode, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Read_RPortNormFodDebugMode_DEPAlgoDebugMode Rte_Read_SWCNorm_RPortNormFodDebugMode_DEPAlgoDebugMode
#endif


  /* Rte_Read Api mapping  [Satisfies_rte sws 1091].*/
  /* Std_ReturnType Rte_Read_<p>_<o>([IN Rte_Instance <instance>],OUT <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
  extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWCNorm_RPortNormGbAoiBlockage_DEPGbAoiBlockage  (OUT P2VAR(RTE_GB_t_AOIBlockage, AUTOMATIC, RTE_APPL_DATA) arg1);
#else
  extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWCNorm_RPortNormGbAoiBlockage_DEPGbAoiBlockage(OUT P2VAR(RTE_GB_t_AOIBlockage_array, AUTOMATIC, RTE_APPL_DATA) arg1);
#endif
#ifndef RTE_C
  #define Rte_Read_RPortNormGbAoiBlockage_DEPGbAoiBlockage Rte_Read_SWCNorm_RPortNormGbAoiBlockage_DEPGbAoiBlockage
#endif


  /* Rte_Read Api mapping  [Satisfies_rte sws 1091].*/
  /* Std_ReturnType Rte_Read_<p>_<o>([IN Rte_Instance <instance>],OUT <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWCNorm_RPortNormIcImageCharEven_DEPIcImageCharacteristics(OUT P2VAR(RTE_t_IC_S_ImageCharacteristics, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Read_RPortNormIcImageCharEven_DEPIcImageCharacteristics Rte_Read_SWCNorm_RPortNormIcImageCharEven_DEPIcImageCharacteristics
#endif


  /* Rte_Read Api mapping  [Satisfies_rte sws 1091].*/
  /* Std_ReturnType Rte_Read_<p>_<o>([IN Rte_Instance <instance>],OUT <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWCNorm_RPortNormIcImageCharOdd_DEPIcImageCharacteristics(OUT P2VAR(RTE_t_IC_S_ImageCharacteristics, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Read_RPortNormIcImageCharOdd_DEPIcImageCharacteristics Rte_Read_SWCNorm_RPortNormIcImageCharOdd_DEPIcImageCharacteristics
#endif


  /* Rte_Read Api mapping  [Satisfies_rte sws 1091].*/
  /* Std_ReturnType Rte_Read_<p>_<o>([IN Rte_Instance <instance>],OUT <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWCNorm_RPortNormIcParameters_DEP_IcParameter(OUT P2VAR(NvM_t_ICParameter, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Read_RPortNormIcParameters_DEP_IcParameter Rte_Read_SWCNorm_RPortNormIcParameters_DEP_IcParameter
#endif


  /* Rte_Read Api mapping  [Satisfies_rte sws 1091].*/
  /* Std_ReturnType Rte_Read_<p>_<o>([IN Rte_Instance <instance>],OUT <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWCNorm_RPortNormIcStatResultsEven_DEPIcStatisticalResults(OUT P2VAR(RTE_t_IC_S_StatisticalResults, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Read_RPortNormIcStatResultsEven_DEPIcStatisticalResults Rte_Read_SWCNorm_RPortNormIcStatResultsEven_DEPIcStatisticalResults
#endif


  /* Rte_Read Api mapping  [Satisfies_rte sws 1091].*/
  /* Std_ReturnType Rte_Read_<p>_<o>([IN Rte_Instance <instance>],OUT <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWCNorm_RPortNormIcStatResultsOdd_DEPIcStatisticalResults(OUT P2VAR(RTE_t_IC_S_StatisticalResults, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Read_RPortNormIcStatResultsOdd_DEPIcStatisticalResults Rte_Read_SWCNorm_RPortNormIcStatResultsOdd_DEPIcStatisticalResults
#endif


  /* Rte_Read Api mapping  [Satisfies_rte sws 1091].*/
  /* Std_ReturnType Rte_Read_<p>_<o>([IN Rte_Instance <instance>],OUT <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWCNorm_RPortNormLrDebugMode_DEPAlgoDebugMode(OUT P2VAR(RTE_t_eAlgoDebugMode, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Read_RPortNormLrDebugMode_DEPAlgoDebugMode Rte_Read_SWCNorm_RPortNormLrDebugMode_DEPAlgoDebugMode
#endif


  /* Rte_Read Api mapping  [Satisfies_rte sws 1091].*/
  /* Std_ReturnType Rte_Read_<p>_<o>([IN Rte_Instance <instance>],OUT <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWCNorm_RPortNormPodDebugMode_DEPAlgoDebugMode(OUT P2VAR(RTE_t_eAlgoDebugMode, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Read_RPortNormPodDebugMode_DEPAlgoDebugMode Rte_Read_SWCNorm_RPortNormPodDebugMode_DEPAlgoDebugMode
#endif


  /* Rte_Read Api mapping  [Satisfies_rte sws 1091].*/
  /* Std_ReturnType Rte_Read_<p>_<o>([IN Rte_Instance <instance>],OUT <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWCNorm_RPortNormPrDebugMode_DEPAlgoDebugMode(OUT P2VAR(RTE_t_eAlgoDebugMode, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Read_RPortNormPrDebugMode_DEPAlgoDebugMode Rte_Read_SWCNorm_RPortNormPrDebugMode_DEPAlgoDebugMode
#endif


  /* Rte_Read Api mapping  [Satisfies_rte sws 1091].*/
  /* Std_ReturnType Rte_Read_<p>_<o>([IN Rte_Instance <instance>],OUT <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWCNorm_RPortNormPvDebugMode_DEPAlgoDebugMode(OUT P2VAR(RTE_t_eAlgoDebugMode, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Read_RPortNormPvDebugMode_DEPAlgoDebugMode Rte_Read_SWCNorm_RPortNormPvDebugMode_DEPAlgoDebugMode
#endif


  /* Rte_Read Api mapping  [Satisfies_rte sws 1091].*/
  /* Std_ReturnType Rte_Read_<p>_<o>([IN Rte_Instance <instance>],OUT <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWCNorm_RPortNormSacDebugMode_DEPAlgoDebugMode(OUT P2VAR(RTE_t_eAlgoDebugMode, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Read_RPortNormSacDebugMode_DEPAlgoDebugMode Rte_Read_SWCNorm_RPortNormSacDebugMode_DEPAlgoDebugMode
#endif


  /* Rte_Read Api mapping  [Satisfies_rte sws 1091].*/
  /* Std_ReturnType Rte_Read_<p>_<o>([IN Rte_Instance <instance>],OUT <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWCNorm_RPortNormSlneDebugMode_DEPAlgoDebugMode(OUT P2VAR(RTE_t_eAlgoDebugMode, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Read_RPortNormSlneDebugMode_DEPAlgoDebugMode Rte_Read_SWCNorm_RPortNormSlneDebugMode_DEPAlgoDebugMode
#endif


  /* Rte_Read Api mapping  [Satisfies_rte sws 1091].*/
  /* Std_ReturnType Rte_Read_<p>_<o>([IN Rte_Instance <instance>],OUT <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWCNorm_RPortNormSrDebugMode_DEPAlgoDebugMode(OUT P2VAR(RTE_t_eAlgoDebugMode, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Read_RPortNormSrDebugMode_DEPAlgoDebugMode Rte_Read_SWCNorm_RPortNormSrDebugMode_DEPAlgoDebugMode
#endif


  /* Rte_Write Api mapping  [Satisfies_rte sws 1071], [Satisfies_rte sws 1280].*/
  /* Std_ReturnType Rte_Write_<p>_<o>([IN Rte_Instance <instance>],IN <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWCNorm_PPortNormSysExtTester_DidA_ExtTest_Pres(IN VAR(DC_BOOL, AUTOMATIC) arg1);
#ifndef RTE_C
  #define Rte_Write_PPortNormSysExtTester_DidA_ExtTest_Pres Rte_Write_SWCNorm_PPortNormSysExtTester_DidA_ExtTest_Pres
#endif


  /* Rte_Write Api mapping  [Satisfies_rte sws 1071], [Satisfies_rte sws 1280].*/
  /* Std_ReturnType Rte_Write_<p>_<o>([IN Rte_Instance <instance>],IN <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWCNorm_PPortNormSysIgnition_Ign_Stat(IN P2VAR(SwcDemSc_IgnStat_GrpType, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Write_PPortNormSysIgnition_Ign_Stat Rte_Write_SWCNorm_PPortNormSysIgnition_Ign_Stat
#endif


  /* Rte_Write Api mapping  [Satisfies_rte sws 1071], [Satisfies_rte sws 1280].*/
  /* Std_ReturnType Rte_Write_<p>_<o>([IN Rte_Instance <instance>],IN <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWCNorm_PPortNormSysOdometer_Odo(IN VAR(c24_km_0_999999k9_0k1, AUTOMATIC) arg1);
#ifndef RTE_C
  #define Rte_Write_PPortNormSysOdometer_Odo Rte_Write_SWCNorm_PPortNormSysOdometer_Odo
#endif


  /* Rte_Write Api mapping  [Satisfies_rte sws 1071], [Satisfies_rte sws 1280].*/
  /* Std_ReturnType Rte_Write_<p>_<o>([IN Rte_Instance <instance>],IN <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWCNorm_PPortNormSysTransportationMode_PN14_TransMd_Stat(IN VAR(c02_TransMd_Stat, AUTOMATIC) arg1);
#ifndef RTE_C
  #define Rte_Write_PPortNormSysTransportationMode_PN14_TransMd_Stat Rte_Write_SWCNorm_PPortNormSysTransportationMode_PN14_TransMd_Stat
#endif


  /* Rte_Write Api mapping  [Satisfies_rte sws 1071], [Satisfies_rte sws 1280].*/
  /* Std_ReturnType Rte_Write_<p>_<o>([IN Rte_Instance <instance>],IN <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWCNorm_PPortNormSysVehicleEngineStartup_Eng_Rs_EngCtrl(IN P2VAR(SwcDemSc_EngRsEngCtrl_GrpType, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Write_PPortNormSysVehicleEngineStartup_Eng_Rs_EngCtrl Rte_Write_SWCNorm_PPortNormSysVehicleEngineStartup_Eng_Rs_EngCtrl
#endif


  /* Rte_Write Api mapping  [Satisfies_rte sws 1071], [Satisfies_rte sws 1280].*/
  /* Std_ReturnType Rte_Write_<p>_<o>([IN Rte_Instance <instance>],IN <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWCNorm_PPortNormSysVoltage_PN14_SupBat_Stat(IN P2VAR(SwcDemSc_PN14SupBatStat_GrpType, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Write_PPortNormSysVoltage_PN14_SupBat_Stat Rte_Write_SWCNorm_PPortNormSysVoltage_PN14_SupBat_Stat
#endif


  /* Rte_Write Api mapping  [Satisfies_rte sws 1071], [Satisfies_rte sws 1280].*/
  /* Std_ReturnType Rte_Write_<p>_<o>([IN Rte_Instance <instance>],IN <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWCNorm_PPortHlaHeadlightState_DEP_HeadlightState(IN P2VAR(RTE_HLA_t_HeadlightState, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Write_PPortHlaHeadlightState_DEP_HeadlightState Rte_Write_SWCNorm_PPortHlaHeadlightState_DEP_HeadlightState
#endif


  /* Rte_Write Api mapping  [Satisfies_rte sws 1071], [Satisfies_rte sws 1280].*/
  /* Std_ReturnType Rte_Write_<p>_<o>([IN Rte_Instance <instance>],IN <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWCNorm_PPortNormHlaAvailability_DEPHlaAvailability(IN P2VAR(RTE_HLA_t_Availability, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Write_PPortNormHlaAvailability_DEPHlaAvailability Rte_Write_SWCNorm_PPortNormHlaAvailability_DEPHlaAvailability
#endif


  /* Rte_Write Api mapping  [Satisfies_rte sws 1071], [Satisfies_rte sws 1280].*/
  /* Std_ReturnType Rte_Write_<p>_<o>([IN Rte_Instance <instance>],IN <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWCNorm_PPortNormNvObject_DEP_HlaNvObject(IN P2VAR(RTE_HLAF_t_NightView, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Write_PPortNormNvObject_DEP_HlaNvObject Rte_Write_SWCNorm_PPortNormNvObject_DEP_HlaNvObject
#endif


  /* Rte_Write Api mapping  [Satisfies_rte sws 1071], [Satisfies_rte sws 1280].*/
  /* Std_ReturnType Rte_Write_<p>_<o>([IN Rte_Instance <instance>],IN <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWCNorm_PPortNormVehicleState_DEPVehicleState(IN P2VAR(RTE_HLA_t_VehicleState, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Write_PPortNormVehicleState_DEPVehicleState Rte_Write_SWCNorm_PPortNormVehicleState_DEPVehicleState
#endif


  /* Rte_Write Api mapping  [Satisfies_rte sws 1071], [Satisfies_rte sws 1280].*/
  /* Std_ReturnType Rte_Write_<p>_<o>([IN Rte_Instance <instance>],IN <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWCNorm_PPortNormAldwLdpCfgBits_DEPAldwLdpCfgBits(IN P2VAR(RTE_t_AldwLdpCfgBits, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Write_PPortNormAldwLdpCfgBits_DEPAldwLdpCfgBits Rte_Write_SWCNorm_PPortNormAldwLdpCfgBits_DEPAldwLdpCfgBits
#endif


  /* Rte_Write Api mapping  [Satisfies_rte sws 1071], [Satisfies_rte sws 1280].*/
  /* Std_ReturnType Rte_Write_<p>_<o>([IN Rte_Instance <instance>],IN <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWCNorm_PPortNormLdpWarnRq_DEPLdpWarnRq(IN P2VAR(LDPWarnRq_t, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Write_PPortNormLdpWarnRq_DEPLdpWarnRq Rte_Write_SWCNorm_PPortNormLdpWarnRq_DEPLdpWarnRq
#endif


  /* Rte_Write Api mapping  [Satisfies_rte sws 1071], [Satisfies_rte sws 1280].*/
  /* Std_ReturnType Rte_Write_<p>_<o>([IN Rte_Instance <instance>],IN <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWCNorm_PPortNormVehSpdDisp_DEP_VehSpdDisp(IN P2VAR(RTE_t_VehSpdDisp, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Write_PPortNormVehSpdDisp_DEP_VehSpdDisp Rte_Write_SWCNorm_PPortNormVehSpdDisp_DEP_VehSpdDisp
#endif


  /* Rte_Write Api mapping  [Satisfies_rte sws 1071], [Satisfies_rte sws 1280].*/
  /* Std_ReturnType Rte_Write_<p>_<o>([IN Rte_Instance <instance>],IN <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWCNorm_PPortNormTsaDate_DEPTsaDate(IN P2VAR(RTE_t_TSAIFInputDate, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Write_PPortNormTsaDate_DEPTsaDate Rte_Write_SWCNorm_PPortNormTsaDate_DEPTsaDate
#endif


  /* Rte_Write Api mapping  [Satisfies_rte sws 1071], [Satisfies_rte sws 1280].*/
  /* Std_ReturnType Rte_Write_<p>_<o>([IN Rte_Instance <instance>],IN <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWCNorm_PPortNormTsaModeSelect_DEPTsaModeSelect(IN VAR(RTE_t_TSAIFModeSelect, AUTOMATIC) arg1);
#ifndef RTE_C
  #define Rte_Write_PPortNormTsaModeSelect_DEPTsaModeSelect Rte_Write_SWCNorm_PPortNormTsaModeSelect_DEPTsaModeSelect
#endif


  /* Rte_Write Api mapping  [Satisfies_rte sws 1071], [Satisfies_rte sws 1280].*/
  /* Std_ReturnType Rte_Write_<p>_<o>([IN Rte_Instance <instance>],IN <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWCNorm_PPortNormTsaTime_DEPTsaTime(IN P2VAR(RTE_t_TSAIFInputTime, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Write_PPortNormTsaTime_DEPTsaTime Rte_Write_SWCNorm_PPortNormTsaTime_DEPTsaTime
#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(LKAOutputCustom_t, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCNorm_RunEntNormFctFinished_RPortLkaOutputCustom_DEP_FctLkaOutputCustom(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntNormFctFinished_RPortLkaOutputCustom_DEP_FctLkaOutputCustom \
    Rte_IRead_SWCNorm_RunEntNormFctFinished_RPortLkaOutputCustom_DEP_FctLkaOutputCustom

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(RTE_HLA_t_HeadlightControl, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCNorm_RunEntNormHlaFinished_RPortHlaOutput_DEP_HlaOutput(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntNormHlaFinished_RPortHlaOutput_DEP_HlaOutput \
    Rte_IRead_SWCNorm_RunEntNormHlaFinished_RPortHlaOutput_DEP_HlaOutput

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(RTE_HLA_t_CaliOnline, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCNorm_RunEntNormHlaFinished_RPortNormHlaCaliOnline_DEPHlaCaliOnline(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntNormHlaFinished_RPortNormHlaCaliOnline_DEPHlaCaliOnline \
    Rte_IRead_SWCNorm_RunEntNormHlaFinished_RPortNormHlaCaliOnline_DEPHlaCaliOnline

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(RTE_CALI_t_TargetExtraction, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCNorm_RunEntNormIpc_RPortNormCaliTargetExtraction_DEPCaliTargetExtraction(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntNormIpc_RPortNormCaliTargetExtraction_DEPCaliTargetExtraction \
    Rte_IRead_SWCNorm_RunEntNormIpc_RPortNormCaliTargetExtraction_DEPCaliTargetExtraction

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(VAR(RTE_t_CalibPatternType, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCNorm_RunEntNormIpc_RPortNormCalibPatternType_DEPCalibPatternType(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntNormIpc_RPortNormCalibPatternType_DEPCalibPatternType \
    Rte_IRead_SWCNorm_RunEntNormIpc_RPortNormCalibPatternType_DEPCalibPatternType

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(S_CamPos_CALIOutput, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCNorm_RunEntNormIpc_RPortNormCamPos_DEP_SensorAngles(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntNormIpc_RPortNormCamPos_DEP_SensorAngles \
    Rte_IRead_SWCNorm_RunEntNormIpc_RPortNormCamPos_DEP_SensorAngles

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(RTE_GB_t_FctBlockageData, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCNorm_RunEntNormIpc_RPortNormGbFctBlockage_DEPGbFctBlockage(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntNormIpc_RPortNormGbFctBlockage_DEPGbFctBlockage \
    Rte_IRead_SWCNorm_RunEntNormIpc_RPortNormGbFctBlockage_DEPGbFctBlockage

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(RTE_t_HeatOutput, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCNorm_RunEntNormIpc_RPortNormHeatState_DEP_HeatStateOutput(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntNormIpc_RPortNormHeatState_DEP_HeatStateOutput \
    Rte_IRead_SWCNorm_RunEntNormIpc_RPortNormHeatState_DEP_HeatStateOutput

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(RTE_HLA_t_EnvironmentData, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCNorm_RunEntNormIpc_RPortNormHlaEnvironmentData_DEPHlaEnvironmentData(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntNormIpc_RPortNormHlaEnvironmentData_DEPHlaEnvironmentData \
    Rte_IRead_SWCNorm_RunEntNormIpc_RPortNormHlaEnvironmentData_DEPHlaEnvironmentData

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(RTE_HLA_t_ObjectList, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCNorm_RunEntNormIpc_RPortNormHlaObjectList_DEPHlaObjectList(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntNormIpc_RPortNormHlaObjectList_DEPHlaObjectList \
    Rte_IRead_SWCNorm_RunEntNormIpc_RPortNormHlaObjectList_DEPHlaObjectList

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(RTE_t_ImageRegisterRequest, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCNorm_RunEntNormIpc_RPortNormImageRegisterRequest_DEPImageRegisterRequest(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntNormIpc_RPortNormImageRegisterRequest_DEPImageRegisterRequest \
    Rte_IRead_SWCNorm_RunEntNormIpc_RPortNormImageRegisterRequest_DEPImageRegisterRequest

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(RTE_t_LDOutput, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCNorm_RunEntNormIpc_RPortNormLDOutput_DEP_LDLaneOutput(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntNormIpc_RPortNormLDOutput_DEP_LDLaneOutput \
    Rte_IRead_SWCNorm_RunEntNormIpc_RPortNormLDOutput_DEP_LDLaneOutput

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(S_MonoOnlineCalibration, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCNorm_RunEntNormIpc_RPortNormLDParameterInOut_DEPLDParameterInOut(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntNormIpc_RPortNormLDParameterInOut_DEPLDParameterInOut \
    Rte_IRead_SWCNorm_RunEntNormIpc_RPortNormLDParameterInOut_DEPLDParameterInOut

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(RTE_t_MAPIFMapData, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCNorm_RunEntNormIpc_RPortNormMapOutput_DEP_MapData(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntNormIpc_RPortNormMapOutput_DEP_MapData \
    Rte_IRead_SWCNorm_RunEntNormIpc_RPortNormMapOutput_DEP_MapData

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(S_SacDistTestInput, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCNorm_RunEntNormIpc_RPortNormSacDistTestInput_DEPSacDistTestInput(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntNormIpc_RPortNormSacDistTestInput_DEPSacDistTestInput \
    Rte_IRead_SWCNorm_RunEntNormIpc_RPortNormSacDistTestInput_DEPSacDistTestInput

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(RTE_t_SACOutput, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCNorm_RunEntNormIpc_RPortNormSacOutput_DEPSacOutput(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntNormIpc_RPortNormSacOutput_DEPSacOutput \
    Rte_IRead_SWCNorm_RunEntNormIpc_RPortNormSacOutput_DEPSacOutput

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(RTE_t_TSAIFOutput, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCNorm_RunEntNormTsaFinished_RPortTsaOutput_DEP_TsaOutput(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntNormTsaFinished_RPortTsaOutput_DEP_TsaOutput \
    Rte_IRead_SWCNorm_RunEntNormTsaFinished_RPortTsaOutput_DEP_TsaOutput

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(RTE_t_VdyOutput, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCNorm_RunEntNormVdyFinished_RPortVdyOutput_DEPVdyOutput(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntNormVdyFinished_RPortVdyOutput_DEPVdyOutput \
    Rte_IRead_SWCNorm_RunEntNormVdyFinished_RPortVdyOutput_DEPVdyOutput

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(RTE_t_LCOutput, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCNorm_RunEntNormVlnFinished_RPortNormLCOutput_DEPLCOutput(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntNormVlnFinished_RPortNormLCOutput_DEPLCOutput \
    Rte_IRead_SWCNorm_RunEntNormVlnFinished_RPortNormLCOutput_DEPLCOutput

#endif


  /* Rte_IWrite Api mapping  [Satisfies_rte sws 3744], [Satisfies_rte sws 1302], [Satisfies_rte sws 3746], [Satisfies_rte sws 3747].*/
  /* void Rte_IWrite_<re>_<p>_<d>([IN RTE_Instance], IN <type>) */
extern FUNC(void, RTE_CODE) Rte_IWrite_SWCNorm_RunEntNormInitTx_PPortNormPparImagerIntrinsRight_DEP_PPARImagerIntrinsRight(P2VAR(RTE_t_PPARImagerIntrinsics, AUTOMATIC, RTE_APPL_DATA) arg1);
extern FUNC( P2VAR(RTE_t_PPARImagerIntrinsics, AUTOMATIC, RTE_APPL_DATA), RTE_CODE ) Rte_IWriteRef_SWCNorm_RunEntNormInitTx_PPortNormPparImagerIntrinsRight_DEP_PPARImagerIntrinsRight();

#ifndef RTE_C
  #define Rte_IWrite_RunEntNormInitTx_PPortNormPparImagerIntrinsRight_DEP_PPARImagerIntrinsRight \
    Rte_IWrite_SWCNorm_RunEntNormInitTx_PPortNormPparImagerIntrinsRight_DEP_PPARImagerIntrinsRight

  #define Rte_IWriteRef_RunEntNormInitTx_PPortNormPparImagerIntrinsRight_DEP_PPARImagerIntrinsRight \
    Rte_IWriteRef_SWCNorm_RunEntNormInitTx_PPortNormPparImagerIntrinsRight_DEP_PPARImagerIntrinsRight

#endif

  /* Rte_IWrite Api mapping  [Satisfies_rte sws 3744], [Satisfies_rte sws 1302], [Satisfies_rte sws 3746], [Satisfies_rte sws 3747].*/
  /* void Rte_IWrite_<re>_<p>_<d>([IN RTE_Instance], IN <type>) */
extern FUNC(void, RTE_CODE) Rte_IWrite_SWCNorm_RunEntNormIpc_PPortNormLROutput_DEP_LDLaneOutput(P2VAR(RTE_t_LDOutput, AUTOMATIC, RTE_APPL_DATA) arg1);
extern FUNC( P2VAR(RTE_t_LDOutput, AUTOMATIC, RTE_APPL_DATA), RTE_CODE ) Rte_IWriteRef_SWCNorm_RunEntNormIpc_PPortNormLROutput_DEP_LDLaneOutput();

#ifndef RTE_C
  #define Rte_IWrite_RunEntNormIpc_PPortNormLROutput_DEP_LDLaneOutput \
    Rte_IWrite_SWCNorm_RunEntNormIpc_PPortNormLROutput_DEP_LDLaneOutput

  #define Rte_IWriteRef_RunEntNormIpc_PPortNormLROutput_DEP_LDLaneOutput \
    Rte_IWriteRef_SWCNorm_RunEntNormIpc_PPortNormLROutput_DEP_LDLaneOutput

#endif

  /* Rte_IWrite Api mapping  [Satisfies_rte sws 3744], [Satisfies_rte sws 1302], [Satisfies_rte sws 3746], [Satisfies_rte sws 3747].*/
  /* void Rte_IWrite_<re>_<p>_<d>([IN RTE_Instance], IN <type>) */
extern FUNC(void, RTE_CODE) Rte_IWrite_SWCNorm_RunEntNormIpc_PPortNormLRParameterInOut_DEPLDParameterInOut(P2VAR(S_MonoOnlineCalibration, AUTOMATIC, RTE_APPL_DATA) arg1);
extern FUNC( P2VAR(S_MonoOnlineCalibration, AUTOMATIC, RTE_APPL_DATA), RTE_CODE ) Rte_IWriteRef_SWCNorm_RunEntNormIpc_PPortNormLRParameterInOut_DEPLDParameterInOut();

#ifndef RTE_C
  #define Rte_IWrite_RunEntNormIpc_PPortNormLRParameterInOut_DEPLDParameterInOut \
    Rte_IWrite_SWCNorm_RunEntNormIpc_PPortNormLRParameterInOut_DEPLDParameterInOut

  #define Rte_IWriteRef_RunEntNormIpc_PPortNormLRParameterInOut_DEPLDParameterInOut \
    Rte_IWriteRef_SWCNorm_RunEntNormIpc_PPortNormLRParameterInOut_DEPLDParameterInOut

#endif

  /* Rte_IWrite Api mapping  [Satisfies_rte sws 3744], [Satisfies_rte sws 1302], [Satisfies_rte sws 3746], [Satisfies_rte sws 3747].*/
  /* void Rte_IWrite_<re>_<p>_<d>([IN RTE_Instance], IN <type>) */
extern FUNC(void, RTE_CODE) Rte_IWrite_SWCNorm_RunEntNormIpc_PPortNormDiagAlgoStates_DEPDiagAlgoStates(P2VAR(RTE_t_DiagAlgoStates, AUTOMATIC, RTE_APPL_DATA) arg1);
extern FUNC( P2VAR(RTE_t_DiagAlgoStates, AUTOMATIC, RTE_APPL_DATA), RTE_CODE ) Rte_IWriteRef_SWCNorm_RunEntNormIpc_PPortNormDiagAlgoStates_DEPDiagAlgoStates();

#ifndef RTE_C
  #define Rte_IWrite_RunEntNormIpc_PPortNormDiagAlgoStates_DEPDiagAlgoStates \
    Rte_IWrite_SWCNorm_RunEntNormIpc_PPortNormDiagAlgoStates_DEPDiagAlgoStates

  #define Rte_IWriteRef_RunEntNormIpc_PPortNormDiagAlgoStates_DEPDiagAlgoStates \
    Rte_IWriteRef_SWCNorm_RunEntNormIpc_PPortNormDiagAlgoStates_DEPDiagAlgoStates

#endif

  /* Rte_IWrite Api mapping  [Satisfies_rte sws 3744], [Satisfies_rte sws 1302], [Satisfies_rte sws 3746], [Satisfies_rte sws 3747].*/
  /* void Rte_IWrite_<re>_<p>_<d>([IN RTE_Instance], IN <type>) */
extern FUNC(void, RTE_CODE) Rte_IWrite_SWCNorm_RunEntNormIpc_PPortNormImageRegisterResponse_DEPImageRegisterResponse(P2VAR(RTE_t_ImageRegisterResponse, AUTOMATIC, RTE_APPL_DATA) arg1);
extern FUNC( P2VAR(RTE_t_ImageRegisterResponse, AUTOMATIC, RTE_APPL_DATA), RTE_CODE ) Rte_IWriteRef_SWCNorm_RunEntNormIpc_PPortNormImageRegisterResponse_DEPImageRegisterResponse();

#ifndef RTE_C
  #define Rte_IWrite_RunEntNormIpc_PPortNormImageRegisterResponse_DEPImageRegisterResponse \
    Rte_IWrite_SWCNorm_RunEntNormIpc_PPortNormImageRegisterResponse_DEPImageRegisterResponse

  #define Rte_IWriteRef_RunEntNormIpc_PPortNormImageRegisterResponse_DEPImageRegisterResponse \
    Rte_IWriteRef_SWCNorm_RunEntNormIpc_PPortNormImageRegisterResponse_DEPImageRegisterResponse

#endif

  /* Rte_IWrite Api mapping  [Satisfies_rte sws 3744], [Satisfies_rte sws 1302], [Satisfies_rte sws 3746], [Satisfies_rte sws 3747].*/
  /* void Rte_IWrite_<re>_<p>_<d>([IN RTE_Instance], IN <type>) */
extern FUNC(void, RTE_CODE) Rte_IWrite_SWCNorm_RunEntNormIpc_PPortNormObjData_DEPObjData(P2VAR(RTE_t_TSAIFObjData, AUTOMATIC, RTE_APPL_DATA) arg1);
extern FUNC( P2VAR(RTE_t_TSAIFObjData, AUTOMATIC, RTE_APPL_DATA), RTE_CODE ) Rte_IWriteRef_SWCNorm_RunEntNormIpc_PPortNormObjData_DEPObjData();

#ifndef RTE_C
  #define Rte_IWrite_RunEntNormIpc_PPortNormObjData_DEPObjData \
    Rte_IWrite_SWCNorm_RunEntNormIpc_PPortNormObjData_DEPObjData

  #define Rte_IWriteRef_RunEntNormIpc_PPortNormObjData_DEPObjData \
    Rte_IWriteRef_SWCNorm_RunEntNormIpc_PPortNormObjData_DEPObjData

#endif

  /* Rte_IWrite Api mapping  [Satisfies_rte sws 3744], [Satisfies_rte sws 1302], [Satisfies_rte sws 3746], [Satisfies_rte sws 3747].*/
  /* void Rte_IWrite_<re>_<p>_<d>([IN RTE_Instance], IN <type>) */
extern FUNC(void, RTE_CODE) Rte_IWrite_SWCNorm_RunEntNormIpc_PPortNormSacDistTestResult_DEPSacDistTestResult(P2VAR(S_SacDistTestFromToNVM, AUTOMATIC, RTE_APPL_DATA) arg1);
extern FUNC( P2VAR(S_SacDistTestFromToNVM, AUTOMATIC, RTE_APPL_DATA), RTE_CODE ) Rte_IWriteRef_SWCNorm_RunEntNormIpc_PPortNormSacDistTestResult_DEPSacDistTestResult();

#ifndef RTE_C
  #define Rte_IWrite_RunEntNormIpc_PPortNormSacDistTestResult_DEPSacDistTestResult \
    Rte_IWrite_SWCNorm_RunEntNormIpc_PPortNormSacDistTestResult_DEPSacDistTestResult

  #define Rte_IWriteRef_RunEntNormIpc_PPortNormSacDistTestResult_DEPSacDistTestResult \
    Rte_IWriteRef_SWCNorm_RunEntNormIpc_PPortNormSacDistTestResult_DEPSacDistTestResult

#endif

  /* Rte_IWrite Api mapping  [Satisfies_rte sws 3744], [Satisfies_rte sws 1302], [Satisfies_rte sws 3746], [Satisfies_rte sws 3747].*/
  /* void Rte_IWrite_<re>_<p>_<d>([IN RTE_Instance], IN <type>) */
extern FUNC(void, RTE_CODE) Rte_IWrite_SWCNorm_RunEntNormIpc_PPortNormSacOutput_DEPSacOutput(P2VAR(RTE_t_SACOutput, AUTOMATIC, RTE_APPL_DATA) arg1);
extern FUNC( P2VAR(RTE_t_SACOutput, AUTOMATIC, RTE_APPL_DATA), RTE_CODE ) Rte_IWriteRef_SWCNorm_RunEntNormIpc_PPortNormSacOutput_DEPSacOutput();

#ifndef RTE_C
  #define Rte_IWrite_RunEntNormIpc_PPortNormSacOutput_DEPSacOutput \
    Rte_IWrite_SWCNorm_RunEntNormIpc_PPortNormSacOutput_DEPSacOutput

  #define Rte_IWriteRef_RunEntNormIpc_PPortNormSacOutput_DEPSacOutput \
    Rte_IWriteRef_SWCNorm_RunEntNormIpc_PPortNormSacOutput_DEPSacOutput

#endif

  /* Rte_IWrite Api mapping  [Satisfies_rte sws 3744], [Satisfies_rte sws 1302], [Satisfies_rte sws 3746], [Satisfies_rte sws 3747].*/
  /* void Rte_IWrite_<re>_<p>_<d>([IN RTE_Instance], IN <type>) */
extern FUNC(void, RTE_CODE) Rte_IWrite_SWCNorm_RunEntNormIpc_PPortNormSleOutput_DEPSleOutput(P2VAR(RTE_t_SLEOutput, AUTOMATIC, RTE_APPL_DATA) arg1);
extern FUNC( P2VAR(RTE_t_SLEOutput, AUTOMATIC, RTE_APPL_DATA), RTE_CODE ) Rte_IWriteRef_SWCNorm_RunEntNormIpc_PPortNormSleOutput_DEPSleOutput();

#ifndef RTE_C
  #define Rte_IWrite_RunEntNormIpc_PPortNormSleOutput_DEPSleOutput \
    Rte_IWrite_SWCNorm_RunEntNormIpc_PPortNormSleOutput_DEPSleOutput

  #define Rte_IWriteRef_RunEntNormIpc_PPortNormSleOutput_DEPSleOutput \
    Rte_IWriteRef_SWCNorm_RunEntNormIpc_PPortNormSleOutput_DEPSleOutput

#endif

  /* Rte_IWrite Api mapping  [Satisfies_rte sws 3744], [Satisfies_rte sws 1302], [Satisfies_rte sws 3746], [Satisfies_rte sws 3747].*/
  /* void Rte_IWrite_<re>_<p>_<d>([IN RTE_Instance], IN <type>) */
extern FUNC(void, RTE_CODE) Rte_IWrite_SWCNorm_RunEntNormIpc_PPortNormSrTriggerRef_DEPTriggerRef(VAR(uint64, RTE_APPL_DATA) arg1);
extern FUNC( P2VAR(uint64, AUTOMATIC, RTE_APPL_DATA), RTE_CODE ) Rte_IWriteRef_SWCNorm_RunEntNormIpc_PPortNormSrTriggerRef_DEPTriggerRef();

#ifndef RTE_C
  #define Rte_IWrite_RunEntNormIpc_PPortNormSrTriggerRef_DEPTriggerRef \
    Rte_IWrite_SWCNorm_RunEntNormIpc_PPortNormSrTriggerRef_DEPTriggerRef

  #define Rte_IWriteRef_RunEntNormIpc_PPortNormSrTriggerRef_DEPTriggerRef \
    Rte_IWriteRef_SWCNorm_RunEntNormIpc_PPortNormSrTriggerRef_DEPTriggerRef

#endif

  /* Rte_IWrite Api mapping  [Satisfies_rte sws 3744], [Satisfies_rte sws 1302], [Satisfies_rte sws 3746], [Satisfies_rte sws 3747].*/
  /* void Rte_IWrite_<re>_<p>_<d>([IN RTE_Instance], IN <type>) */
extern FUNC(void, RTE_CODE) Rte_IWrite_SWCNorm_RunEntNormIpc_PPortSrOutput_DEP_SrOutput(P2VAR(RTE_t_TSAIFSRData, AUTOMATIC, RTE_APPL_DATA) arg1);
extern FUNC( P2VAR(RTE_t_TSAIFSRData, AUTOMATIC, RTE_APPL_DATA), RTE_CODE ) Rte_IWriteRef_SWCNorm_RunEntNormIpc_PPortSrOutput_DEP_SrOutput();

#ifndef RTE_C
  #define Rte_IWrite_RunEntNormIpc_PPortSrOutput_DEP_SrOutput \
    Rte_IWrite_SWCNorm_RunEntNormIpc_PPortSrOutput_DEP_SrOutput

  #define Rte_IWriteRef_RunEntNormIpc_PPortSrOutput_DEP_SrOutput \
    Rte_IWriteRef_SWCNorm_RunEntNormIpc_PPortSrOutput_DEP_SrOutput

#endif

  /* Rte_IWrite Api mapping  [Satisfies_rte sws 3744], [Satisfies_rte sws 1302], [Satisfies_rte sws 3746], [Satisfies_rte sws 3747].*/
  /* void Rte_IWrite_<re>_<p>_<d>([IN RTE_Instance], IN <type>) */
extern FUNC(void, RTE_CODE) Rte_IWrite_SWCNorm_RunEntNormMapRx_PPortMapInput_DEPMapInput(P2VAR(RTE_t_MAPIFInput, AUTOMATIC, RTE_APPL_DATA) arg1);
extern FUNC( P2VAR(RTE_t_MAPIFInput, AUTOMATIC, RTE_APPL_DATA), RTE_CODE ) Rte_IWriteRef_SWCNorm_RunEntNormMapRx_PPortMapInput_DEPMapInput();

#ifndef RTE_C
  #define Rte_IWrite_RunEntNormMapRx_PPortMapInput_DEPMapInput \
    Rte_IWrite_SWCNorm_RunEntNormMapRx_PPortMapInput_DEPMapInput

  #define Rte_IWriteRef_RunEntNormMapRx_PPortMapInput_DEPMapInput \
    Rte_IWriteRef_SWCNorm_RunEntNormMapRx_PPortMapInput_DEPMapInput

#endif

  /* Rte_IWrite Api mapping  [Satisfies_rte sws 3744], [Satisfies_rte sws 1302], [Satisfies_rte sws 3746], [Satisfies_rte sws 3747].*/
  /* void Rte_IWrite_<re>_<p>_<d>([IN RTE_Instance], IN <type>) */
extern FUNC(void, RTE_CODE) Rte_IWrite_SWCNorm_RunEntNormMapRx_PPortMapMetaData_DEPMapMetaData(P2VAR(RTE_t_MAPIFMetaData, AUTOMATIC, RTE_APPL_DATA) arg1);
extern FUNC( P2VAR(RTE_t_MAPIFMetaData, AUTOMATIC, RTE_APPL_DATA), RTE_CODE ) Rte_IWriteRef_SWCNorm_RunEntNormMapRx_PPortMapMetaData_DEPMapMetaData();

#ifndef RTE_C
  #define Rte_IWrite_RunEntNormMapRx_PPortMapMetaData_DEPMapMetaData \
    Rte_IWrite_SWCNorm_RunEntNormMapRx_PPortMapMetaData_DEPMapMetaData

  #define Rte_IWriteRef_RunEntNormMapRx_PPortMapMetaData_DEPMapMetaData \
    Rte_IWriteRef_SWCNorm_RunEntNormMapRx_PPortMapMetaData_DEPMapMetaData

#endif

  /* Rte_IWrite Api mapping  [Satisfies_rte sws 3744], [Satisfies_rte sws 1302], [Satisfies_rte sws 3746], [Satisfies_rte sws 3747].*/
  /* void Rte_IWrite_<re>_<p>_<d>([IN RTE_Instance], IN <type>) */
extern FUNC(void, RTE_CODE) Rte_IWrite_SWCNorm_RunEntNormMapRx_PPortMapPosition_DEPMapPosition(P2VAR(RTE_t_MAPIFPosition, AUTOMATIC, RTE_APPL_DATA) arg1);
extern FUNC( P2VAR(RTE_t_MAPIFPosition, AUTOMATIC, RTE_APPL_DATA), RTE_CODE ) Rte_IWriteRef_SWCNorm_RunEntNormMapRx_PPortMapPosition_DEPMapPosition();

#ifndef RTE_C
  #define Rte_IWrite_RunEntNormMapRx_PPortMapPosition_DEPMapPosition \
    Rte_IWrite_SWCNorm_RunEntNormMapRx_PPortMapPosition_DEPMapPosition

  #define Rte_IWriteRef_RunEntNormMapRx_PPortMapPosition_DEPMapPosition \
    Rte_IWriteRef_SWCNorm_RunEntNormMapRx_PPortMapPosition_DEPMapPosition

#endif

  /* Rte_IWrite Api mapping  [Satisfies_rte sws 3744], [Satisfies_rte sws 1302], [Satisfies_rte sws 3746], [Satisfies_rte sws 3747].*/
  /* void Rte_IWrite_<re>_<p>_<d>([IN RTE_Instance], IN <type>) */
extern FUNC(void, RTE_CODE) Rte_IWrite_SWCNorm_RunEntNormMapRx_PPortMapProfileLong_DEPMapProfile(P2VAR(RTE_t_MAPIFProfile, AUTOMATIC, RTE_APPL_DATA) arg1);
extern FUNC( P2VAR(RTE_t_MAPIFProfile, AUTOMATIC, RTE_APPL_DATA), RTE_CODE ) Rte_IWriteRef_SWCNorm_RunEntNormMapRx_PPortMapProfileLong_DEPMapProfile();

#ifndef RTE_C
  #define Rte_IWrite_RunEntNormMapRx_PPortMapProfileLong_DEPMapProfile \
    Rte_IWrite_SWCNorm_RunEntNormMapRx_PPortMapProfileLong_DEPMapProfile

  #define Rte_IWriteRef_RunEntNormMapRx_PPortMapProfileLong_DEPMapProfile \
    Rte_IWriteRef_SWCNorm_RunEntNormMapRx_PPortMapProfileLong_DEPMapProfile

#endif

  /* Rte_IWrite Api mapping  [Satisfies_rte sws 3744], [Satisfies_rte sws 1302], [Satisfies_rte sws 3746], [Satisfies_rte sws 3747].*/
  /* void Rte_IWrite_<re>_<p>_<d>([IN RTE_Instance], IN <type>) */
extern FUNC(void, RTE_CODE) Rte_IWrite_SWCNorm_RunEntNormMapRx_PPortMapProfileShort0_DEPMapProfile(P2VAR(RTE_t_MAPIFProfile, AUTOMATIC, RTE_APPL_DATA) arg1);
extern FUNC( P2VAR(RTE_t_MAPIFProfile, AUTOMATIC, RTE_APPL_DATA), RTE_CODE ) Rte_IWriteRef_SWCNorm_RunEntNormMapRx_PPortMapProfileShort0_DEPMapProfile();

#ifndef RTE_C
  #define Rte_IWrite_RunEntNormMapRx_PPortMapProfileShort0_DEPMapProfile \
    Rte_IWrite_SWCNorm_RunEntNormMapRx_PPortMapProfileShort0_DEPMapProfile

  #define Rte_IWriteRef_RunEntNormMapRx_PPortMapProfileShort0_DEPMapProfile \
    Rte_IWriteRef_SWCNorm_RunEntNormMapRx_PPortMapProfileShort0_DEPMapProfile

#endif

  /* Rte_IWrite Api mapping  [Satisfies_rte sws 3744], [Satisfies_rte sws 1302], [Satisfies_rte sws 3746], [Satisfies_rte sws 3747].*/
  /* void Rte_IWrite_<re>_<p>_<d>([IN RTE_Instance], IN <type>) */
extern FUNC(void, RTE_CODE) Rte_IWrite_SWCNorm_RunEntNormMapRx_PPortMapProfileShort1_DEPMapProfile(P2VAR(RTE_t_MAPIFProfile, AUTOMATIC, RTE_APPL_DATA) arg1);
extern FUNC( P2VAR(RTE_t_MAPIFProfile, AUTOMATIC, RTE_APPL_DATA), RTE_CODE ) Rte_IWriteRef_SWCNorm_RunEntNormMapRx_PPortMapProfileShort1_DEPMapProfile();

#ifndef RTE_C
  #define Rte_IWrite_RunEntNormMapRx_PPortMapProfileShort1_DEPMapProfile \
    Rte_IWrite_SWCNorm_RunEntNormMapRx_PPortMapProfileShort1_DEPMapProfile

  #define Rte_IWriteRef_RunEntNormMapRx_PPortMapProfileShort1_DEPMapProfile \
    Rte_IWriteRef_SWCNorm_RunEntNormMapRx_PPortMapProfileShort1_DEPMapProfile

#endif

  /* Rte_IWrite Api mapping  [Satisfies_rte sws 3744], [Satisfies_rte sws 1302], [Satisfies_rte sws 3746], [Satisfies_rte sws 3747].*/
  /* void Rte_IWrite_<re>_<p>_<d>([IN RTE_Instance], IN <type>) */
extern FUNC(void, RTE_CODE) Rte_IWrite_SWCNorm_RunEntNormMapRx_PPortMapSegment_DEPMapSegment(P2VAR(RTE_t_MAPIFSegment, AUTOMATIC, RTE_APPL_DATA) arg1);
extern FUNC( P2VAR(RTE_t_MAPIFSegment, AUTOMATIC, RTE_APPL_DATA), RTE_CODE ) Rte_IWriteRef_SWCNorm_RunEntNormMapRx_PPortMapSegment_DEPMapSegment();

#ifndef RTE_C
  #define Rte_IWrite_RunEntNormMapRx_PPortMapSegment_DEPMapSegment \
    Rte_IWrite_SWCNorm_RunEntNormMapRx_PPortMapSegment_DEPMapSegment

  #define Rte_IWriteRef_RunEntNormMapRx_PPortMapSegment_DEPMapSegment \
    Rte_IWriteRef_SWCNorm_RunEntNormMapRx_PPortMapSegment_DEPMapSegment

#endif

  /* Rte_IWrite Api mapping  [Satisfies_rte sws 3744], [Satisfies_rte sws 1302], [Satisfies_rte sws 3746], [Satisfies_rte sws 3747].*/
  /* void Rte_IWrite_<re>_<p>_<d>([IN RTE_Instance], IN <type>) */
extern FUNC(void, RTE_CODE) Rte_IWrite_SWCNorm_RunEntNormMapRx_PPortMapStub_DEPMapStub(P2VAR(RTE_t_MAPIFStub, AUTOMATIC, RTE_APPL_DATA) arg1);
extern FUNC( P2VAR(RTE_t_MAPIFStub, AUTOMATIC, RTE_APPL_DATA), RTE_CODE ) Rte_IWriteRef_SWCNorm_RunEntNormMapRx_PPortMapStub_DEPMapStub();

#ifndef RTE_C
  #define Rte_IWrite_RunEntNormMapRx_PPortMapStub_DEPMapStub \
    Rte_IWrite_SWCNorm_RunEntNormMapRx_PPortMapStub_DEPMapStub

  #define Rte_IWriteRef_RunEntNormMapRx_PPortMapStub_DEPMapStub \
    Rte_IWriteRef_SWCNorm_RunEntNormMapRx_PPortMapStub_DEPMapStub

#endif

  /* Rte_IWrite Api mapping  [Satisfies_rte sws 3744], [Satisfies_rte sws 1302], [Satisfies_rte sws 3746], [Satisfies_rte sws 3747].*/
  /* void Rte_IWrite_<re>_<p>_<d>([IN RTE_Instance], IN <type>) */
extern FUNC(void, RTE_CODE) Rte_IWrite_SWCNorm_RunEntNormMapRx_PPortMapTimeMetaData_DEPMapTimestamp(P2VAR(RTE_t_MAPIFInputTimestamp, AUTOMATIC, RTE_APPL_DATA) arg1);
extern FUNC( P2VAR(RTE_t_MAPIFInputTimestamp, AUTOMATIC, RTE_APPL_DATA), RTE_CODE ) Rte_IWriteRef_SWCNorm_RunEntNormMapRx_PPortMapTimeMetaData_DEPMapTimestamp();

#ifndef RTE_C
  #define Rte_IWrite_RunEntNormMapRx_PPortMapTimeMetaData_DEPMapTimestamp \
    Rte_IWrite_SWCNorm_RunEntNormMapRx_PPortMapTimeMetaData_DEPMapTimestamp

  #define Rte_IWriteRef_RunEntNormMapRx_PPortMapTimeMetaData_DEPMapTimestamp \
    Rte_IWriteRef_SWCNorm_RunEntNormMapRx_PPortMapTimeMetaData_DEPMapTimestamp

#endif

  /* Rte_IWrite Api mapping  [Satisfies_rte sws 3744], [Satisfies_rte sws 1302], [Satisfies_rte sws 3746], [Satisfies_rte sws 3747].*/
  /* void Rte_IWrite_<re>_<p>_<d>([IN RTE_Instance], IN <type>) */
extern FUNC(void, RTE_CODE) Rte_IWrite_SWCNorm_RunEntNormMapRx_PPortMapTimeNewStub_DEPMapTimestamp(P2VAR(RTE_t_MAPIFInputTimestamp, AUTOMATIC, RTE_APPL_DATA) arg1);
extern FUNC( P2VAR(RTE_t_MAPIFInputTimestamp, AUTOMATIC, RTE_APPL_DATA), RTE_CODE ) Rte_IWriteRef_SWCNorm_RunEntNormMapRx_PPortMapTimeNewStub_DEPMapTimestamp();

#ifndef RTE_C
  #define Rte_IWrite_RunEntNormMapRx_PPortMapTimeNewStub_DEPMapTimestamp \
    Rte_IWrite_SWCNorm_RunEntNormMapRx_PPortMapTimeNewStub_DEPMapTimestamp

  #define Rte_IWriteRef_RunEntNormMapRx_PPortMapTimeNewStub_DEPMapTimestamp \
    Rte_IWriteRef_SWCNorm_RunEntNormMapRx_PPortMapTimeNewStub_DEPMapTimestamp

#endif

  /* Rte_IWrite Api mapping  [Satisfies_rte sws 3744], [Satisfies_rte sws 1302], [Satisfies_rte sws 3746], [Satisfies_rte sws 3747].*/
  /* void Rte_IWrite_<re>_<p>_<d>([IN RTE_Instance], IN <type>) */
extern FUNC(void, RTE_CODE) Rte_IWrite_SWCNorm_RunEntNormMapRx_PPortMapTimePosition_DEPMapTimestamp(P2VAR(RTE_t_MAPIFInputTimestamp, AUTOMATIC, RTE_APPL_DATA) arg1);
extern FUNC( P2VAR(RTE_t_MAPIFInputTimestamp, AUTOMATIC, RTE_APPL_DATA), RTE_CODE ) Rte_IWriteRef_SWCNorm_RunEntNormMapRx_PPortMapTimePosition_DEPMapTimestamp();

#ifndef RTE_C
  #define Rte_IWrite_RunEntNormMapRx_PPortMapTimePosition_DEPMapTimestamp \
    Rte_IWrite_SWCNorm_RunEntNormMapRx_PPortMapTimePosition_DEPMapTimestamp

  #define Rte_IWriteRef_RunEntNormMapRx_PPortMapTimePosition_DEPMapTimestamp \
    Rte_IWriteRef_SWCNorm_RunEntNormMapRx_PPortMapTimePosition_DEPMapTimestamp

#endif

  /* Rte_IWrite Api mapping  [Satisfies_rte sws 3744], [Satisfies_rte sws 1302], [Satisfies_rte sws 3746], [Satisfies_rte sws 3747].*/
  /* void Rte_IWrite_<re>_<p>_<d>([IN RTE_Instance], IN <type>) */
extern FUNC(void, RTE_CODE) Rte_IWrite_SWCNorm_RunEntNormMapRx_PPortMapTimeProfileLong_DEPMapTimestamp(P2VAR(RTE_t_MAPIFInputTimestamp, AUTOMATIC, RTE_APPL_DATA) arg1);
extern FUNC( P2VAR(RTE_t_MAPIFInputTimestamp, AUTOMATIC, RTE_APPL_DATA), RTE_CODE ) Rte_IWriteRef_SWCNorm_RunEntNormMapRx_PPortMapTimeProfileLong_DEPMapTimestamp();

#ifndef RTE_C
  #define Rte_IWrite_RunEntNormMapRx_PPortMapTimeProfileLong_DEPMapTimestamp \
    Rte_IWrite_SWCNorm_RunEntNormMapRx_PPortMapTimeProfileLong_DEPMapTimestamp

  #define Rte_IWriteRef_RunEntNormMapRx_PPortMapTimeProfileLong_DEPMapTimestamp \
    Rte_IWriteRef_SWCNorm_RunEntNormMapRx_PPortMapTimeProfileLong_DEPMapTimestamp

#endif

  /* Rte_IWrite Api mapping  [Satisfies_rte sws 3744], [Satisfies_rte sws 1302], [Satisfies_rte sws 3746], [Satisfies_rte sws 3747].*/
  /* void Rte_IWrite_<re>_<p>_<d>([IN RTE_Instance], IN <type>) */
extern FUNC(void, RTE_CODE) Rte_IWrite_SWCNorm_RunEntNormMapRx_PPortMapTimeProfileShort_DEPMapTimestamp(P2VAR(RTE_t_MAPIFInputTimestamp, AUTOMATIC, RTE_APPL_DATA) arg1);
extern FUNC( P2VAR(RTE_t_MAPIFInputTimestamp, AUTOMATIC, RTE_APPL_DATA), RTE_CODE ) Rte_IWriteRef_SWCNorm_RunEntNormMapRx_PPortMapTimeProfileShort_DEPMapTimestamp();

#ifndef RTE_C
  #define Rte_IWrite_RunEntNormMapRx_PPortMapTimeProfileShort_DEPMapTimestamp \
    Rte_IWrite_SWCNorm_RunEntNormMapRx_PPortMapTimeProfileShort_DEPMapTimestamp

  #define Rte_IWriteRef_RunEntNormMapRx_PPortMapTimeProfileShort_DEPMapTimestamp \
    Rte_IWriteRef_SWCNorm_RunEntNormMapRx_PPortMapTimeProfileShort_DEPMapTimestamp

#endif

  /* Rte_IWrite Api mapping  [Satisfies_rte sws 3744], [Satisfies_rte sws 1302], [Satisfies_rte sws 3746], [Satisfies_rte sws 3747].*/
  /* void Rte_IWrite_<re>_<p>_<d>([IN RTE_Instance], IN <type>) */
extern FUNC(void, RTE_CODE) Rte_IWrite_SWCNorm_RunEntNormMapRx_PPortMapTimeSegment_DEPMapTimestamp(P2VAR(RTE_t_MAPIFInputTimestamp, AUTOMATIC, RTE_APPL_DATA) arg1);
extern FUNC( P2VAR(RTE_t_MAPIFInputTimestamp, AUTOMATIC, RTE_APPL_DATA), RTE_CODE ) Rte_IWriteRef_SWCNorm_RunEntNormMapRx_PPortMapTimeSegment_DEPMapTimestamp();

#ifndef RTE_C
  #define Rte_IWrite_RunEntNormMapRx_PPortMapTimeSegment_DEPMapTimestamp \
    Rte_IWrite_SWCNorm_RunEntNormMapRx_PPortMapTimeSegment_DEPMapTimestamp

  #define Rte_IWriteRef_RunEntNormMapRx_PPortMapTimeSegment_DEPMapTimestamp \
    Rte_IWriteRef_SWCNorm_RunEntNormMapRx_PPortMapTimeSegment_DEPMapTimestamp

#endif

  /* Rte_IWrite Api mapping  [Satisfies_rte sws 3744], [Satisfies_rte sws 1302], [Satisfies_rte sws 3746], [Satisfies_rte sws 3747].*/
  /* void Rte_IWrite_<re>_<p>_<d>([IN RTE_Instance], IN <type>) */
extern FUNC(void, RTE_CODE) Rte_IWrite_SWCNorm_RunEntNormMapRx_PPortNormGPSPos_DEPGPSPos(P2VAR(RTE_t_TSAIFInputGPSPos, AUTOMATIC, RTE_APPL_DATA) arg1);
extern FUNC( P2VAR(RTE_t_TSAIFInputGPSPos, AUTOMATIC, RTE_APPL_DATA), RTE_CODE ) Rte_IWriteRef_SWCNorm_RunEntNormMapRx_PPortNormGPSPos_DEPGPSPos();

#ifndef RTE_C
  #define Rte_IWrite_RunEntNormMapRx_PPortNormGPSPos_DEPGPSPos \
    Rte_IWrite_SWCNorm_RunEntNormMapRx_PPortNormGPSPos_DEPGPSPos

  #define Rte_IWriteRef_RunEntNormMapRx_PPortNormGPSPos_DEPGPSPos \
    Rte_IWriteRef_SWCNorm_RunEntNormMapRx_PPortNormGPSPos_DEPGPSPos

#endif

  /* Rte_IWrite Api mapping  [Satisfies_rte sws 3744], [Satisfies_rte sws 1302], [Satisfies_rte sws 3746], [Satisfies_rte sws 3747].*/
  /* void Rte_IWrite_<re>_<p>_<d>([IN RTE_Instance], IN <type>) */
extern FUNC(void, RTE_CODE) Rte_IWrite_SWCNorm_RunEntNormMapRx_PPortNormMapCuA_DEPMapCuA(P2VAR(RTE_t_MAPIFCuA, AUTOMATIC, RTE_APPL_DATA) arg1);
extern FUNC( P2VAR(RTE_t_MAPIFCuA, AUTOMATIC, RTE_APPL_DATA), RTE_CODE ) Rte_IWriteRef_SWCNorm_RunEntNormMapRx_PPortNormMapCuA_DEPMapCuA();

#ifndef RTE_C
  #define Rte_IWrite_RunEntNormMapRx_PPortNormMapCuA_DEPMapCuA \
    Rte_IWrite_SWCNorm_RunEntNormMapRx_PPortNormMapCuA_DEPMapCuA

  #define Rte_IWriteRef_RunEntNormMapRx_PPortNormMapCuA_DEPMapCuA \
    Rte_IWriteRef_SWCNorm_RunEntNormMapRx_PPortNormMapCuA_DEPMapCuA

#endif

  /* Rte_IWrite Api mapping  [Satisfies_rte sws 3744], [Satisfies_rte sws 1302], [Satisfies_rte sws 3746], [Satisfies_rte sws 3747].*/
  /* void Rte_IWrite_<re>_<p>_<d>([IN RTE_Instance], IN <type>) */
extern FUNC(void, RTE_CODE) Rte_IWrite_SWCNorm_RunEntNormRx_PPortAirTempOutside_DEP_AirTempOutside(VAR(RTE_f32_AirTempOutsd, RTE_APPL_DATA) arg1);
extern FUNC( P2VAR(RTE_f32_AirTempOutsd, AUTOMATIC, RTE_APPL_DATA), RTE_CODE ) Rte_IWriteRef_SWCNorm_RunEntNormRx_PPortAirTempOutside_DEP_AirTempOutside();

#ifndef RTE_C
  #define Rte_IWrite_RunEntNormRx_PPortAirTempOutside_DEP_AirTempOutside \
    Rte_IWrite_SWCNorm_RunEntNormRx_PPortAirTempOutside_DEP_AirTempOutside

  #define Rte_IWriteRef_RunEntNormRx_PPortAirTempOutside_DEP_AirTempOutside \
    Rte_IWriteRef_SWCNorm_RunEntNormRx_PPortAirTempOutside_DEP_AirTempOutside

#endif

  /* Rte_IWrite Api mapping  [Satisfies_rte sws 3744], [Satisfies_rte sws 1302], [Satisfies_rte sws 3746], [Satisfies_rte sws 3747].*/
  /* void Rte_IWrite_<re>_<p>_<d>([IN RTE_Instance], IN <type>) */
extern FUNC(void, RTE_CODE) Rte_IWrite_SWCNorm_RunEntNormRx_PPortNormAldwButtons_DEP_FctAldwButtons(P2VAR(lka_aldw_buttons_t, AUTOMATIC, RTE_APPL_DATA) arg1);
extern FUNC( P2VAR(lka_aldw_buttons_t, AUTOMATIC, RTE_APPL_DATA), RTE_CODE ) Rte_IWriteRef_SWCNorm_RunEntNormRx_PPortNormAldwButtons_DEP_FctAldwButtons();

#ifndef RTE_C
  #define Rte_IWrite_RunEntNormRx_PPortNormAldwButtons_DEP_FctAldwButtons \
    Rte_IWrite_SWCNorm_RunEntNormRx_PPortNormAldwButtons_DEP_FctAldwButtons

  #define Rte_IWriteRef_RunEntNormRx_PPortNormAldwButtons_DEP_FctAldwButtons \
    Rte_IWriteRef_SWCNorm_RunEntNormRx_PPortNormAldwButtons_DEP_FctAldwButtons

#endif

  /* Rte_IWrite Api mapping  [Satisfies_rte sws 3744], [Satisfies_rte sws 1302], [Satisfies_rte sws 3746], [Satisfies_rte sws 3747].*/
  /* void Rte_IWrite_<re>_<p>_<d>([IN RTE_Instance], IN <type>) */
extern FUNC(void, RTE_CODE) Rte_IWrite_SWCNorm_RunEntNormRx_PPortNormAldwMode_DEP_FctAldwMode(VAR(eALDWMode_t, RTE_APPL_DATA) arg1);
extern FUNC( P2VAR(eALDWMode_t, AUTOMATIC, RTE_APPL_DATA), RTE_CODE ) Rte_IWriteRef_SWCNorm_RunEntNormRx_PPortNormAldwMode_DEP_FctAldwMode();

#ifndef RTE_C
  #define Rte_IWrite_RunEntNormRx_PPortNormAldwMode_DEP_FctAldwMode \
    Rte_IWrite_SWCNorm_RunEntNormRx_PPortNormAldwMode_DEP_FctAldwMode

  #define Rte_IWriteRef_RunEntNormRx_PPortNormAldwMode_DEP_FctAldwMode \
    Rte_IWriteRef_SWCNorm_RunEntNormRx_PPortNormAldwMode_DEP_FctAldwMode

#endif

  /* Rte_IWrite Api mapping  [Satisfies_rte sws 3744], [Satisfies_rte sws 1302], [Satisfies_rte sws 3746], [Satisfies_rte sws 3747].*/
  /* void Rte_IWrite_<re>_<p>_<d>([IN RTE_Instance], IN <type>) */
extern FUNC(void, RTE_CODE) Rte_IWrite_SWCNorm_RunEntNormRx_PPortIgnState_DEPIgnState(VAR(NORM_t_eIgnState, RTE_APPL_DATA) arg1);
extern FUNC( P2VAR(NORM_t_eIgnState, AUTOMATIC, RTE_APPL_DATA), RTE_CODE ) Rte_IWriteRef_SWCNorm_RunEntNormRx_PPortIgnState_DEPIgnState();

#ifndef RTE_C
  #define Rte_IWrite_RunEntNormRx_PPortIgnState_DEPIgnState \
    Rte_IWrite_SWCNorm_RunEntNormRx_PPortIgnState_DEPIgnState

  #define Rte_IWriteRef_RunEntNormRx_PPortIgnState_DEPIgnState \
    Rte_IWriteRef_SWCNorm_RunEntNormRx_PPortIgnState_DEPIgnState

#endif

  /* Rte_IWrite Api mapping  [Satisfies_rte sws 3744], [Satisfies_rte sws 1302], [Satisfies_rte sws 3746], [Satisfies_rte sws 3747].*/
  /* void Rte_IWrite_<re>_<p>_<d>([IN RTE_Instance], IN <type>) */
extern FUNC(void, RTE_CODE) Rte_IWrite_SWCNorm_RunEntNormRx_PPortLkaDriverInput_DEP_LkaDriverInput(P2VAR(lka_driver_input_t, AUTOMATIC, RTE_APPL_DATA) arg1);
extern FUNC( P2VAR(lka_driver_input_t, AUTOMATIC, RTE_APPL_DATA), RTE_CODE ) Rte_IWriteRef_SWCNorm_RunEntNormRx_PPortLkaDriverInput_DEP_LkaDriverInput();

#ifndef RTE_C
  #define Rte_IWrite_RunEntNormRx_PPortLkaDriverInput_DEP_LkaDriverInput \
    Rte_IWrite_SWCNorm_RunEntNormRx_PPortLkaDriverInput_DEP_LkaDriverInput

  #define Rte_IWriteRef_RunEntNormRx_PPortLkaDriverInput_DEP_LkaDriverInput \
    Rte_IWriteRef_SWCNorm_RunEntNormRx_PPortLkaDriverInput_DEP_LkaDriverInput

#endif

  /* Rte_IWrite Api mapping  [Satisfies_rte sws 3744], [Satisfies_rte sws 1302], [Satisfies_rte sws 3746], [Satisfies_rte sws 3747].*/
  /* void Rte_IWrite_<re>_<p>_<d>([IN RTE_Instance], IN <type>) */
extern FUNC(void, RTE_CODE) Rte_IWrite_SWCNorm_RunEntNormRx_PPortNormDefrostButton_DEPDefrostButton(VAR(uint8, RTE_APPL_DATA) arg1);
extern FUNC( P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA), RTE_CODE ) Rte_IWriteRef_SWCNorm_RunEntNormRx_PPortNormDefrostButton_DEPDefrostButton();

#ifndef RTE_C
  #define Rte_IWrite_RunEntNormRx_PPortNormDefrostButton_DEPDefrostButton \
    Rte_IWrite_SWCNorm_RunEntNormRx_PPortNormDefrostButton_DEPDefrostButton

  #define Rte_IWriteRef_RunEntNormRx_PPortNormDefrostButton_DEPDefrostButton \
    Rte_IWriteRef_SWCNorm_RunEntNormRx_PPortNormDefrostButton_DEPDefrostButton

#endif

  /* Rte_IWrite Api mapping  [Satisfies_rte sws 3744], [Satisfies_rte sws 1302], [Satisfies_rte sws 3746], [Satisfies_rte sws 3747].*/
  /* void Rte_IWrite_<re>_<p>_<d>([IN RTE_Instance], IN <type>) */
extern FUNC(void, RTE_CODE) Rte_IWrite_SWCNorm_RunEntNormRx_PPortNormHlaVehicleParameter_DEPHlaVehicleParameter(P2VAR(RTE_HLA_t_VehicleParameter, AUTOMATIC, RTE_APPL_DATA) arg1);
extern FUNC( P2VAR(RTE_HLA_t_VehicleParameter, AUTOMATIC, RTE_APPL_DATA), RTE_CODE ) Rte_IWriteRef_SWCNorm_RunEntNormRx_PPortNormHlaVehicleParameter_DEPHlaVehicleParameter();

#ifndef RTE_C
  #define Rte_IWrite_RunEntNormRx_PPortNormHlaVehicleParameter_DEPHlaVehicleParameter \
    Rte_IWrite_SWCNorm_RunEntNormRx_PPortNormHlaVehicleParameter_DEPHlaVehicleParameter

  #define Rte_IWriteRef_RunEntNormRx_PPortNormHlaVehicleParameter_DEPHlaVehicleParameter \
    Rte_IWriteRef_SWCNorm_RunEntNormRx_PPortNormHlaVehicleParameter_DEPHlaVehicleParameter

#endif

  /* Rte_IWrite Api mapping  [Satisfies_rte sws 3744], [Satisfies_rte sws 1302], [Satisfies_rte sws 3746], [Satisfies_rte sws 3747].*/
  /* void Rte_IWrite_<re>_<p>_<d>([IN RTE_Instance], IN <type>) */
extern FUNC(void, RTE_CODE) Rte_IWrite_SWCNorm_RunEntNormRx_PPortNormNightviewState_DEPNightviewState(VAR(uint8, RTE_APPL_DATA) arg1);
extern FUNC( P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA), RTE_CODE ) Rte_IWriteRef_SWCNorm_RunEntNormRx_PPortNormNightviewState_DEPNightviewState();

#ifndef RTE_C
  #define Rte_IWrite_RunEntNormRx_PPortNormNightviewState_DEPNightviewState \
    Rte_IWrite_SWCNorm_RunEntNormRx_PPortNormNightviewState_DEPNightviewState

  #define Rte_IWriteRef_RunEntNormRx_PPortNormNightviewState_DEPNightviewState \
    Rte_IWriteRef_SWCNorm_RunEntNormRx_PPortNormNightviewState_DEPNightviewState

#endif

  /* Rte_IWrite Api mapping  [Satisfies_rte sws 3744], [Satisfies_rte sws 1302], [Satisfies_rte sws 3746], [Satisfies_rte sws 3747].*/
  /* void Rte_IWrite_<re>_<p>_<d>([IN RTE_Instance], IN <type>) */
extern FUNC(void, RTE_CODE) Rte_IWrite_SWCNorm_RunEntNormRx_PPortNormVcVehicleData_DEP_VCVehicleData(P2VAR(RTE_t_VCVehicleData, AUTOMATIC, RTE_APPL_DATA) arg1);
extern FUNC( P2VAR(RTE_t_VCVehicleData, AUTOMATIC, RTE_APPL_DATA), RTE_CODE ) Rte_IWriteRef_SWCNorm_RunEntNormRx_PPortNormVcVehicleData_DEP_VCVehicleData();

#ifndef RTE_C
  #define Rte_IWrite_RunEntNormRx_PPortNormVcVehicleData_DEP_VCVehicleData \
    Rte_IWrite_SWCNorm_RunEntNormRx_PPortNormVcVehicleData_DEP_VCVehicleData

  #define Rte_IWriteRef_RunEntNormRx_PPortNormVcVehicleData_DEP_VCVehicleData \
    Rte_IWriteRef_SWCNorm_RunEntNormRx_PPortNormVcVehicleData_DEP_VCVehicleData

#endif

  /* Rte_IWrite Api mapping  [Satisfies_rte sws 3744], [Satisfies_rte sws 1302], [Satisfies_rte sws 3746], [Satisfies_rte sws 3747].*/
  /* void Rte_IWrite_<re>_<p>_<d>([IN RTE_Instance], IN <type>) */
extern FUNC(void, RTE_CODE) Rte_IWrite_SWCNorm_RunEntNormRx_PPortRollTestMd_DEP_RollTestMd(VAR(RTE_b_RollTestMd, RTE_APPL_DATA) arg1);
extern FUNC( P2VAR(RTE_b_RollTestMd, AUTOMATIC, RTE_APPL_DATA), RTE_CODE ) Rte_IWriteRef_SWCNorm_RunEntNormRx_PPortRollTestMd_DEP_RollTestMd();

#ifndef RTE_C
  #define Rte_IWrite_RunEntNormRx_PPortRollTestMd_DEP_RollTestMd \
    Rte_IWrite_SWCNorm_RunEntNormRx_PPortRollTestMd_DEP_RollTestMd

  #define Rte_IWriteRef_RunEntNormRx_PPortRollTestMd_DEP_RollTestMd \
    Rte_IWriteRef_SWCNorm_RunEntNormRx_PPortRollTestMd_DEP_RollTestMd

#endif

  /* Rte_IWrite Api mapping  [Satisfies_rte sws 3744], [Satisfies_rte sws 1302], [Satisfies_rte sws 3746], [Satisfies_rte sws 3747].*/
  /* void Rte_IWrite_<re>_<p>_<d>([IN RTE_Instance], IN <type>) */
extern FUNC(void, RTE_CODE) Rte_IWrite_SWCNorm_RunEntNormRx_PPortTsaSettings_DEP_TsaSettings(P2VAR(RTE_t_TSAIFSettings, AUTOMATIC, RTE_APPL_DATA) arg1);
extern FUNC( P2VAR(RTE_t_TSAIFSettings, AUTOMATIC, RTE_APPL_DATA), RTE_CODE ) Rte_IWriteRef_SWCNorm_RunEntNormRx_PPortTsaSettings_DEP_TsaSettings();

#ifndef RTE_C
  #define Rte_IWrite_RunEntNormRx_PPortTsaSettings_DEP_TsaSettings \
    Rte_IWrite_SWCNorm_RunEntNormRx_PPortTsaSettings_DEP_TsaSettings

  #define Rte_IWriteRef_RunEntNormRx_PPortTsaSettings_DEP_TsaSettings \
    Rte_IWriteRef_SWCNorm_RunEntNormRx_PPortTsaSettings_DEP_TsaSettings

#endif

  /* Rte_IWrite Api mapping  [Satisfies_rte sws 3744], [Satisfies_rte sws 1302], [Satisfies_rte sws 3746], [Satisfies_rte sws 3747].*/
  /* void Rte_IWrite_<re>_<p>_<d>([IN RTE_Instance], IN <type>) */
extern FUNC(void, RTE_CODE) Rte_IWrite_SWCNorm_RunEntNormRx_PPortVehAddSig_DEPVehAddSig(P2VAR(RTE_t_VehAddSignals, AUTOMATIC, RTE_APPL_DATA) arg1);
extern FUNC( P2VAR(RTE_t_VehAddSignals, AUTOMATIC, RTE_APPL_DATA), RTE_CODE ) Rte_IWriteRef_SWCNorm_RunEntNormRx_PPortVehAddSig_DEPVehAddSig();

#ifndef RTE_C
  #define Rte_IWrite_RunEntNormRx_PPortVehAddSig_DEPVehAddSig \
    Rte_IWrite_SWCNorm_RunEntNormRx_PPortVehAddSig_DEPVehAddSig

  #define Rte_IWriteRef_RunEntNormRx_PPortVehAddSig_DEPVehAddSig \
    Rte_IWriteRef_SWCNorm_RunEntNormRx_PPortVehAddSig_DEPVehAddSig

#endif

  /* Rte_IWrite Api mapping  [Satisfies_rte sws 3744], [Satisfies_rte sws 1302], [Satisfies_rte sws 3746], [Satisfies_rte sws 3747].*/
  /* void Rte_IWrite_<re>_<p>_<d>([IN RTE_Instance], IN <type>) */
extern FUNC(void, RTE_CODE) Rte_IWrite_SWCNorm_RunEntNormRx_PPortVehLvl_DEP_VehLvl(P2VAR(RTE_t_VehicleLevel, AUTOMATIC, RTE_APPL_DATA) arg1);
extern FUNC( P2VAR(RTE_t_VehicleLevel, AUTOMATIC, RTE_APPL_DATA), RTE_CODE ) Rte_IWriteRef_SWCNorm_RunEntNormRx_PPortVehLvl_DEP_VehLvl();

#ifndef RTE_C
  #define Rte_IWrite_RunEntNormRx_PPortVehLvl_DEP_VehLvl \
    Rte_IWrite_SWCNorm_RunEntNormRx_PPortVehLvl_DEP_VehLvl

  #define Rte_IWriteRef_RunEntNormRx_PPortVehLvl_DEP_VehLvl \
    Rte_IWriteRef_SWCNorm_RunEntNormRx_PPortVehLvl_DEP_VehLvl

#endif

  /* Rte_IWrite Api mapping  [Satisfies_rte sws 3744], [Satisfies_rte sws 1302], [Satisfies_rte sws 3746], [Satisfies_rte sws 3747].*/
  /* void Rte_IWrite_<re>_<p>_<d>([IN RTE_Instance], IN <type>) */
extern FUNC(void, RTE_CODE) Rte_IWrite_SWCNorm_RunEntNormRx_PPortVehSig_DEPBswVehSig(P2VAR(VehSig_t, AUTOMATIC, RTE_APPL_DATA) arg1);
extern FUNC( P2VAR(VehSig_t, AUTOMATIC, RTE_APPL_DATA), RTE_CODE ) Rte_IWriteRef_SWCNorm_RunEntNormRx_PPortVehSig_DEPBswVehSig();

#ifndef RTE_C
  #define Rte_IWrite_RunEntNormRx_PPortVehSig_DEPBswVehSig \
    Rte_IWrite_SWCNorm_RunEntNormRx_PPortVehSig_DEPBswVehSig

  #define Rte_IWriteRef_RunEntNormRx_PPortVehSig_DEPBswVehSig \
    Rte_IWriteRef_SWCNorm_RunEntNormRx_PPortVehSig_DEPBswVehSig

#endif

  /* Rte_IWrite Api mapping  [Satisfies_rte sws 3744], [Satisfies_rte sws 1302], [Satisfies_rte sws 3746], [Satisfies_rte sws 3747].*/
  /* void Rte_IWrite_<re>_<p>_<d>([IN RTE_Instance], IN <type>) */
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
  extern FUNC(void, RTE_CODE) Rte_IWrite_SWCNorm_RunEntNormRx_PPortVin_DEP_CaliVin(P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) arg1);
#else
  extern FUNC(void, RTE_CODE) Rte_IWrite_SWCNorm_RunEntNormRx_PPortVin_DEP_CaliVin(P2VAR(RTE_aui8_VIN, AUTOMATIC, RTE_APPL_DATA) arg1);
#endif
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
  extern FUNC( P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA), RTE_CODE ) Rte_IWriteRef_SWCNorm_RunEntNormRx_PPortVin_DEP_CaliVin();
#else
  extern FUNC( P2VAR(RTE_aui8_VIN, AUTOMATIC, RTE_APPL_DATA), RTE_CODE ) Rte_IWriteRef_SWCNorm_RunEntNormRx_PPortVin_DEP_CaliVin();
#endif

#ifndef RTE_C
  #define Rte_IWrite_RunEntNormRx_PPortVin_DEP_CaliVin \
    Rte_IWrite_SWCNorm_RunEntNormRx_PPortVin_DEP_CaliVin

  #define Rte_IWriteRef_RunEntNormRx_PPortVin_DEP_CaliVin \
    Rte_IWriteRef_SWCNorm_RunEntNormRx_PPortVin_DEP_CaliVin

#endif

  /* Rte_IWrite Api mapping  [Satisfies_rte sws 3744], [Satisfies_rte sws 1302], [Satisfies_rte sws 3746], [Satisfies_rte sws 3747].*/
  /* void Rte_IWrite_<re>_<p>_<d>([IN RTE_Instance], IN <type>) */
extern FUNC(void, RTE_CODE) Rte_IWrite_SWCNorm_RunEntNormRx_PPortWiperSignals_DEP_WiperSignals(P2VAR(RTE_t_WiperInfo, AUTOMATIC, RTE_APPL_DATA) arg1);
extern FUNC( P2VAR(RTE_t_WiperInfo, AUTOMATIC, RTE_APPL_DATA), RTE_CODE ) Rte_IWriteRef_SWCNorm_RunEntNormRx_PPortWiperSignals_DEP_WiperSignals();

#ifndef RTE_C
  #define Rte_IWrite_RunEntNormRx_PPortWiperSignals_DEP_WiperSignals \
    Rte_IWrite_SWCNorm_RunEntNormRx_PPortWiperSignals_DEP_WiperSignals

  #define Rte_IWriteRef_RunEntNormRx_PPortWiperSignals_DEP_WiperSignals \
    Rte_IWriteRef_SWCNorm_RunEntNormRx_PPortWiperSignals_DEP_WiperSignals

#endif

  /* Rte_IWrite Api mapping  [Satisfies_rte sws 3744], [Satisfies_rte sws 1302], [Satisfies_rte sws 3746], [Satisfies_rte sws 3747].*/
  /* void Rte_IWrite_<re>_<p>_<d>([IN RTE_Instance], IN <type>) */
extern FUNC(void, RTE_CODE) Rte_IWrite_SWCNorm_RunEntNormTsaRx_PPortNormOnlineCali_DEPOnlineCalibrationInfo(P2VAR(RTE_t_TSAIFOnlineCalibrationInfo, AUTOMATIC, RTE_APPL_DATA) arg1);
extern FUNC( P2VAR(RTE_t_TSAIFOnlineCalibrationInfo, AUTOMATIC, RTE_APPL_DATA), RTE_CODE ) Rte_IWriteRef_SWCNorm_RunEntNormTsaRx_PPortNormOnlineCali_DEPOnlineCalibrationInfo();

#ifndef RTE_C
  #define Rte_IWrite_RunEntNormTsaRx_PPortNormOnlineCali_DEPOnlineCalibrationInfo \
    Rte_IWrite_SWCNorm_RunEntNormTsaRx_PPortNormOnlineCali_DEPOnlineCalibrationInfo

  #define Rte_IWriteRef_RunEntNormTsaRx_PPortNormOnlineCali_DEPOnlineCalibrationInfo \
    Rte_IWriteRef_SWCNorm_RunEntNormTsaRx_PPortNormOnlineCali_DEPOnlineCalibrationInfo

#endif

  /* Rte_IWrite Api mapping  [Satisfies_rte sws 3744], [Satisfies_rte sws 1302], [Satisfies_rte sws 3746], [Satisfies_rte sws 3747].*/
  /* void Rte_IWrite_<re>_<p>_<d>([IN RTE_Instance], IN <type>) */
extern FUNC(void, RTE_CODE) Rte_IWrite_SWCNorm_RunEntNormTsaRx_PPortNormStWhlAnglStat_DEPStWhlAnglStat(P2VAR(RTE_t_StWhlAnglStat, AUTOMATIC, RTE_APPL_DATA) arg1);
extern FUNC( P2VAR(RTE_t_StWhlAnglStat, AUTOMATIC, RTE_APPL_DATA), RTE_CODE ) Rte_IWriteRef_SWCNorm_RunEntNormTsaRx_PPortNormStWhlAnglStat_DEPStWhlAnglStat();

#ifndef RTE_C
  #define Rte_IWrite_RunEntNormTsaRx_PPortNormStWhlAnglStat_DEPStWhlAnglStat \
    Rte_IWrite_SWCNorm_RunEntNormTsaRx_PPortNormStWhlAnglStat_DEPStWhlAnglStat

  #define Rte_IWriteRef_RunEntNormTsaRx_PPortNormStWhlAnglStat_DEPStWhlAnglStat \
    Rte_IWriteRef_SWCNorm_RunEntNormTsaRx_PPortNormStWhlAnglStat_DEPStWhlAnglStat

#endif

  /* Rte_IWrite Api mapping  [Satisfies_rte sws 3744], [Satisfies_rte sws 1302], [Satisfies_rte sws 3746], [Satisfies_rte sws 3747].*/
  /* void Rte_IWrite_<re>_<p>_<d>([IN RTE_Instance], IN <type>) */
extern FUNC(void, RTE_CODE) Rte_IWrite_SWCNorm_RunEntNormTsaRx_PPortNormVehTrailerState_DEPVehTrailerState(P2VAR(RTE_t_TSAIFInputVehTrailerState, AUTOMATIC, RTE_APPL_DATA) arg1);
extern FUNC( P2VAR(RTE_t_TSAIFInputVehTrailerState, AUTOMATIC, RTE_APPL_DATA), RTE_CODE ) Rte_IWriteRef_SWCNorm_RunEntNormTsaRx_PPortNormVehTrailerState_DEPVehTrailerState();

#ifndef RTE_C
  #define Rte_IWrite_RunEntNormTsaRx_PPortNormVehTrailerState_DEPVehTrailerState \
    Rte_IWrite_SWCNorm_RunEntNormTsaRx_PPortNormVehTrailerState_DEPVehTrailerState

  #define Rte_IWriteRef_RunEntNormTsaRx_PPortNormVehTrailerState_DEPVehTrailerState \
    Rte_IWriteRef_SWCNorm_RunEntNormTsaRx_PPortNormVehTrailerState_DEPVehTrailerState

#endif

  /* Rte_IWrite Api mapping  [Satisfies_rte sws 3744], [Satisfies_rte sws 1302], [Satisfies_rte sws 3746], [Satisfies_rte sws 3747].*/
  /* void Rte_IWrite_<re>_<p>_<d>([IN RTE_Instance], IN <type>) */
extern FUNC(void, RTE_CODE) Rte_IWrite_SWCNorm_RunEntNormTsaRx_PPortNormTachometerSpeed_DEPTachometerSpeed(P2VAR(RTE_t_TSAIFInputFloat32, AUTOMATIC, RTE_APPL_DATA) arg1);
extern FUNC( P2VAR(RTE_t_TSAIFInputFloat32, AUTOMATIC, RTE_APPL_DATA), RTE_CODE ) Rte_IWriteRef_SWCNorm_RunEntNormTsaRx_PPortNormTachometerSpeed_DEPTachometerSpeed();

#ifndef RTE_C
  #define Rte_IWrite_RunEntNormTsaRx_PPortNormTachometerSpeed_DEPTachometerSpeed \
    Rte_IWrite_SWCNorm_RunEntNormTsaRx_PPortNormTachometerSpeed_DEPTachometerSpeed

  #define Rte_IWriteRef_RunEntNormTsaRx_PPortNormTachometerSpeed_DEPTachometerSpeed \
    Rte_IWriteRef_SWCNorm_RunEntNormTsaRx_PPortNormTachometerSpeed_DEPTachometerSpeed

#endif


/* Mode API mapping */
extern FUNC(Rte_ModeType_EcuM_Mode, RTE_CODE) Rte_Mode_SWCNorm_RPModeNorm_currentMode( void );
#ifndef RTE_C
	#define Rte_Mode_RPModeNorm_currentMode  \
		Rte_Mode_SWCNorm_RPModeNorm_currentMode
#endif







#ifdef __cplusplus
	} /* extern "C" */
#endif /* __cplusplus */


#endif
