/**************************************************************************
This file is generated automatically by the RTE generator
Filename:	Rte_SWCDiag.h
CESSAR-CT Version: 3.1.1.11
RTE Version: 3.2.0.1.3.0
Generated on:	Tue Jun 19 11:26:15 CEST 2012
**************************************************************************/


#ifndef _RTE_SWCDiag_H_
#define _RTE_SWCDiag_H_



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
  typedef CONSTP2CONST(Rte_CDS_SWCDiag, AUTOMATIC, RTE_CONST) Rte_Instance;
#endif /* RTE_C */

/* SWC:SWCDiag Indirect API */
	/* The name of the instance handle is Rte_Inst_<c> [Satisfies_rte sws 3793]. */
extern CONST(Rte_CDS_SWCDiag, RTE_CONST) Rte_Instance_SWCDiag;

#ifndef RTE_C

	/*  Provided ports */



	/*  Required ports */


#endif



/* runnable entry points (symbol) */

extern void RE_Diag (void); 


/* application error code */
#ifndef RTE_E_CSI_IcGetSensorIDs_ICA_e_ERR_ILLEGAL_ARGUMENT
  #define RTE_E_CSI_IcGetSensorIDs_ICA_e_ERR_ILLEGAL_ARGUMENT 54
#endif
#ifndef RTE_E_CSI_IcGetSensorIDs_ICA_e_ERR_NULLPOINTER
  #define RTE_E_CSI_IcGetSensorIDs_ICA_e_ERR_NULLPOINTER 41
#endif
#ifndef RTE_E_CSI_IcGetSensorIDs_ICA_e_ERR_OK
  #define RTE_E_CSI_IcGetSensorIDs_ICA_e_ERR_OK 0
#endif
#ifndef RTE_E_CSI_IcGetSensorIDs_ICA_e_ERR_WRONG_STATE
  #define RTE_E_CSI_IcGetSensorIDs_ICA_e_ERR_WRONG_STATE 1
#endif
#ifndef RTE_E_CSI_IcGetTemperature_ICA_e_ERR_NOTAVAILABLE
  #define RTE_E_CSI_IcGetTemperature_ICA_e_ERR_NOTAVAILABLE 40
#endif
#ifndef RTE_E_CSI_IcGetTemperature_ICA_e_ERR_OK
  #define RTE_E_CSI_IcGetTemperature_ICA_e_ERR_OK 0
#endif
#ifndef RTE_E_CSI_NormGetAlgoVersion_E_NOT_OK
  #define RTE_E_CSI_NormGetAlgoVersion_E_NOT_OK 1
#endif
#ifndef RTE_E_CSI_NormGetAlgoVersion_E_OK
  #define RTE_E_CSI_NormGetAlgoVersion_E_OK 0
#endif
#ifndef RTE_E_CSI_Timer64GetTimerValue_E_NOT_OK
  #define RTE_E_CSI_Timer64GetTimerValue_E_NOT_OK 1
#endif



/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/COMPONENTTYPES/IntBehDiag/RunEntDiag/SSCP_DiagBswGetAdcData */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWCDiag_RPortDiagBswGetAdcData_OPGetAdcData( IN VAR(uint8,AUTOMATIC) AdcChannel, OUT P2VAR(float32,AUTOMATIC,RTE_APPL_DATA) CalcVal, OUT P2VAR(uint32,AUTOMATIC,RTE_APPL_DATA) Timestamp);
#ifndef RTE_C
  #define Rte_Call_RPortDiagBswGetAdcData_OPGetAdcData Rte_Call_SWCDiag_RPortDiagBswGetAdcData_OPGetAdcData
#endif


/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/COMPONENTTYPES/IntBehDiag/RunEntDiag/SSCP_DiagIcGetSensorIDs */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWCDiag_RPortDiagIcGetSensorIDs_OPIcGetSensorIDs( IN VAR(RTE_ICA_E_IMAGER_TYPE,AUTOMATIC) e_Imager, OUT P2VAR(RTE_t_ICA_S_SensorIDs,AUTOMATIC,RTE_APPL_DATA) ps_SensIdOut);
#ifndef RTE_C
  #define Rte_Call_RPortDiagIcGetSensorIDs_OPIcGetSensorIDs Rte_Call_SWCDiag_RPortDiagIcGetSensorIDs_OPIcGetSensorIDs
#endif


/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/COMPONENTTYPES/IntBehDiag/RunEntDiag/SSCP_DiagIcGetTemperature */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWCDiag_RPortDiagIcGetTemperature_OPIcGetTemperature( IN VAR(RTE_ICA_E_IMAGER_TYPE,AUTOMATIC) e_Imager, OUT P2VAR(float32,AUTOMATIC,RTE_APPL_DATA) pf32_Temp);
#ifndef RTE_C
  #define Rte_Call_RPortDiagIcGetTemperature_OPIcGetTemperature Rte_Call_SWCDiag_RPortDiagIcGetTemperature_OPIcGetTemperature
#endif


/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/COMPONENTTYPES/IntBehDiag/RunEntDiag/SSCP_DiagNormGetAlgoVersion */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWCDiag_RPortDiagNormGetAlgoVersion_OPNormGetAlgoVersion( IN VAR(RTE_t_eAlgoId,AUTOMATIC) AlgoId, OUT P2VAR(uint32,AUTOMATIC,RTE_APPL_DATA) Version);
#ifndef RTE_C
  #define Rte_Call_RPortDiagNormGetAlgoVersion_OPNormGetAlgoVersion Rte_Call_SWCDiag_RPortDiagNormGetAlgoVersion_OPNormGetAlgoVersion
#endif


/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/COMPONENTTYPES/IntBehDiag/RunEntDiag/SSCP_DiagTimer64GetTimerValue */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWCDiag_RPortDiagTimer64GetTimerValue_OPTimer64GetTimerValue( OUT P2VAR(uint64,AUTOMATIC,RTE_APPL_DATA) timerValue);
#ifndef RTE_C
  #define Rte_Call_RPortDiagTimer64GetTimerValue_OPTimer64GetTimerValue Rte_Call_SWCDiag_RPortDiagTimer64GetTimerValue_OPTimer64GetTimerValue
#endif






#ifndef RTE_C
  #define Rte_InitValue_RPortDiagCaliStatus_DEP_CaliStatus (0)
#endif

#ifndef RTE_C
  #define Rte_InitValue_RPortDiagTsaDispTest_DEPTsaDispTest (0)
#endif

#ifndef RTE_C
  #define Rte_InitValue_PPortDiagAldwOpMode_DEP_FctAldwOpMode (0)
#endif

#ifndef RTE_C
  #define Rte_InitValue_PPortDiagAldwVibMotRq_DEPFctAldwVibMotRq (0)
#endif

#ifndef RTE_C
  #define Rte_InitValue_PPortDiagAldwVibTm_DEPAldwVibTm (0)
#endif

#ifndef RTE_C
  #define Rte_InitValue_PPortDiagCaliMode_DEP_CaliMode (0)
#endif

#ifndef RTE_C
  #define Rte_InitValue_PPortDiagCalibPatternType_DEPCalibPatternType (0)
#endif

#ifndef RTE_C
  #define Rte_InitValue_PPortDiagFctDebugMode_DEPAlgoDebugMode (0)
#endif

#ifndef RTE_C
  #define Rte_InitValue_PPortDiagFodDebugMode_DEPAlgoDebugMode (0)
#endif

#ifndef RTE_C
  #define Rte_InitValue_PPortDiagGbDebugMode_DEPAlgoDebugMode (0)
#endif

#ifndef RTE_C
  #define Rte_InitValue_PPortDiagHlaDebugMode_DEPAlgoDebugMode (0)
#endif

#ifndef RTE_C
  #define Rte_InitValue_PPortDiagLdDebugMode_DEPAlgoDebugMode (0)
#endif

#ifndef RTE_C
  #define Rte_InitValue_PPortDiagLrDebugMode_DEPAlgoDebugMode (0)
#endif

#ifndef RTE_C
  #define Rte_InitValue_PPortDiagMapDebugMode_DEPAlgoDebugMode (0)
#endif

#ifndef RTE_C
  #define Rte_InitValue_PPortDiagPodDebugMode_DEPAlgoDebugMode (0)
#endif

#ifndef RTE_C
  #define Rte_InitValue_PPortDiagPrDebugMode_DEPAlgoDebugMode (0)
#endif

#ifndef RTE_C
  #define Rte_InitValue_PPortDiagPvDebugMode_DEPAlgoDebugMode (0)
#endif

#ifndef RTE_C
  #define Rte_InitValue_PPortDiagSacDebugMode_DEPAlgoDebugMode (0)
#endif

#ifndef RTE_C
  #define Rte_InitValue_PPortDiagSlneDebugMode_DEPAlgoDebugMode (0)
#endif

#ifndef RTE_C
  #define Rte_InitValue_PPortDiagSrDebugMode_DEPAlgoDebugMode (0)
#endif

#ifndef RTE_C
  #define Rte_InitValue_PPortDiagTsaDebugMode_DEPAlgoDebugMode (0)
#endif

#ifndef RTE_C
  #define Rte_InitValue_PPortDiagTsaDiagInput_DEPRequestDataSrc (0)
#endif

#ifndef RTE_C
  #define Rte_InitValue_PPortDiagTsaDiagInput_DEPResetBlockageData (0)
#endif

#ifndef RTE_C
  #define Rte_InitValue_PPortDiagTsaDispTest_DEPTsaDispTest (0)
#endif

#ifndef RTE_C
  #define Rte_InitValue_PPortDiagVdyDebugMode_DEPAlgoDebugMode (0)
#endif

#ifndef RTE_C
  #define Rte_InitValue_PPortDiagVlnDebugMode_DEPAlgoDebugMode (0)
#endif

#ifndef RTE_C
  #define Rte_InitValue_PPortHeatDiagIO_DEP_HeatDiagIO (0)
#endif


  /* Rte_Read Api mapping  [Satisfies_rte sws 1091].*/
  /* Std_ReturnType Rte_Read_<p>_<o>([IN Rte_Instance <instance>],OUT <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWCDiag_RPortDiagTsaDispTest_DEPTsaDispTest(OUT P2VAR(RTE_t_eTSADispTest, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Read_RPortDiagTsaDispTest_DEPTsaDispTest Rte_Read_SWCDiag_RPortDiagTsaDispTest_DEPTsaDispTest
#endif


  /* Rte_Write Api mapping  [Satisfies_rte sws 1071], [Satisfies_rte sws 1280].*/
  /* Std_ReturnType Rte_Write_<p>_<o>([IN Rte_Instance <instance>],IN <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWCDiag_PPortDiagAldwVibMotRq_DEPFctAldwVibMotRq(IN VAR(RTE_t_eALDWVibMotRq, AUTOMATIC) arg1);
#ifndef RTE_C
  #define Rte_Write_PPortDiagAldwVibMotRq_DEPFctAldwVibMotRq Rte_Write_SWCDiag_PPortDiagAldwVibMotRq_DEPFctAldwVibMotRq
#endif


  /* Rte_Write Api mapping  [Satisfies_rte sws 1071], [Satisfies_rte sws 1280].*/
  /* Std_ReturnType Rte_Write_<p>_<o>([IN Rte_Instance <instance>],IN <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWCDiag_PPortDiagAldwVibTm_DEPAldwVibTm(IN VAR(uint16, AUTOMATIC) arg1);
#ifndef RTE_C
  #define Rte_Write_PPortDiagAldwVibTm_DEPAldwVibTm Rte_Write_SWCDiag_PPortDiagAldwVibTm_DEPAldwVibTm
#endif


  /* Rte_Write Api mapping  [Satisfies_rte sws 1071], [Satisfies_rte sws 1280].*/
  /* Std_ReturnType Rte_Write_<p>_<o>([IN Rte_Instance <instance>],IN <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWCDiag_PPortDiagCaliMode_DEP_CaliMode(IN VAR(RTE_CALI_t_eCALIMode, AUTOMATIC) arg1);
#ifndef RTE_C
  #define Rte_Write_PPortDiagCaliMode_DEP_CaliMode Rte_Write_SWCDiag_PPortDiagCaliMode_DEP_CaliMode
#endif


  /* Rte_Write Api mapping  [Satisfies_rte sws 1071], [Satisfies_rte sws 1280].*/
  /* Std_ReturnType Rte_Write_<p>_<o>([IN Rte_Instance <instance>],IN <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWCDiag_PPortDiagCaliPatPos_DEP_CaliPatternPosition(IN P2VAR(RTE_t_DiagPatternPosition, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Write_PPortDiagCaliPatPos_DEP_CaliPatternPosition Rte_Write_SWCDiag_PPortDiagCaliPatPos_DEP_CaliPatternPosition
#endif


  /* Rte_Write Api mapping  [Satisfies_rte sws 1071], [Satisfies_rte sws 1280].*/
  /* Std_ReturnType Rte_Write_<p>_<o>([IN Rte_Instance <instance>],IN <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWCDiag_PPortDiagCamSocket_DEP_CaliDiagCamSocket(IN P2VAR(RTE_t_DiagCamSocket, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Write_PPortDiagCamSocket_DEP_CaliDiagCamSocket Rte_Write_SWCDiag_PPortDiagCamSocket_DEP_CaliDiagCamSocket
#endif


  /* Rte_Write Api mapping  [Satisfies_rte sws 1071], [Satisfies_rte sws 1280].*/
  /* Std_ReturnType Rte_Write_<p>_<o>([IN Rte_Instance <instance>],IN <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWCDiag_PPortDiagFctDebugMode_DEPAlgoDebugMode(IN VAR(RTE_t_eAlgoDebugMode, AUTOMATIC) arg1);
#ifndef RTE_C
  #define Rte_Write_PPortDiagFctDebugMode_DEPAlgoDebugMode Rte_Write_SWCDiag_PPortDiagFctDebugMode_DEPAlgoDebugMode
#endif


  /* Rte_Write Api mapping  [Satisfies_rte sws 1071], [Satisfies_rte sws 1280].*/
  /* Std_ReturnType Rte_Write_<p>_<o>([IN Rte_Instance <instance>],IN <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWCDiag_PPortDiagFodDebugMode_DEPAlgoDebugMode(IN VAR(RTE_t_eAlgoDebugMode, AUTOMATIC) arg1);
#ifndef RTE_C
  #define Rte_Write_PPortDiagFodDebugMode_DEPAlgoDebugMode Rte_Write_SWCDiag_PPortDiagFodDebugMode_DEPAlgoDebugMode
#endif


  /* Rte_Write Api mapping  [Satisfies_rte sws 1071], [Satisfies_rte sws 1280].*/
  /* Std_ReturnType Rte_Write_<p>_<o>([IN Rte_Instance <instance>],IN <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWCDiag_PPortDiagGbDebugMode_DEPAlgoDebugMode(IN VAR(RTE_t_eAlgoDebugMode, AUTOMATIC) arg1);
#ifndef RTE_C
  #define Rte_Write_PPortDiagGbDebugMode_DEPAlgoDebugMode Rte_Write_SWCDiag_PPortDiagGbDebugMode_DEPAlgoDebugMode
#endif


  /* Rte_Write Api mapping  [Satisfies_rte sws 1071], [Satisfies_rte sws 1280].*/
  /* Std_ReturnType Rte_Write_<p>_<o>([IN Rte_Instance <instance>],IN <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWCDiag_PPortDiagHlaDebugMode_DEPAlgoDebugMode(IN VAR(RTE_t_eAlgoDebugMode, AUTOMATIC) arg1);
#ifndef RTE_C
  #define Rte_Write_PPortDiagHlaDebugMode_DEPAlgoDebugMode Rte_Write_SWCDiag_PPortDiagHlaDebugMode_DEPAlgoDebugMode
#endif


  /* Rte_Write Api mapping  [Satisfies_rte sws 1071], [Satisfies_rte sws 1280].*/
  /* Std_ReturnType Rte_Write_<p>_<o>([IN Rte_Instance <instance>],IN <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWCDiag_PPortDiagIcParameters_DEP_IcParameter(IN P2VAR(NvM_t_ICParameter, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Write_PPortDiagIcParameters_DEP_IcParameter Rte_Write_SWCDiag_PPortDiagIcParameters_DEP_IcParameter
#endif


  /* Rte_Write Api mapping  [Satisfies_rte sws 1071], [Satisfies_rte sws 1280].*/
  /* Std_ReturnType Rte_Write_<p>_<o>([IN Rte_Instance <instance>],IN <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWCDiag_PPortDiagLdDebugMode_DEPAlgoDebugMode(IN VAR(RTE_t_eAlgoDebugMode, AUTOMATIC) arg1);
#ifndef RTE_C
  #define Rte_Write_PPortDiagLdDebugMode_DEPAlgoDebugMode Rte_Write_SWCDiag_PPortDiagLdDebugMode_DEPAlgoDebugMode
#endif


  /* Rte_Write Api mapping  [Satisfies_rte sws 1071], [Satisfies_rte sws 1280].*/
  /* Std_ReturnType Rte_Write_<p>_<o>([IN Rte_Instance <instance>],IN <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWCDiag_PPortDiagLrDebugMode_DEPAlgoDebugMode(IN VAR(RTE_t_eAlgoDebugMode, AUTOMATIC) arg1);
#ifndef RTE_C
  #define Rte_Write_PPortDiagLrDebugMode_DEPAlgoDebugMode Rte_Write_SWCDiag_PPortDiagLrDebugMode_DEPAlgoDebugMode
#endif


  /* Rte_Write Api mapping  [Satisfies_rte sws 1071], [Satisfies_rte sws 1280].*/
  /* Std_ReturnType Rte_Write_<p>_<o>([IN Rte_Instance <instance>],IN <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWCDiag_PPortDiagMapDebugMode_DEPAlgoDebugMode(IN VAR(RTE_t_eAlgoDebugMode, AUTOMATIC) arg1);
#ifndef RTE_C
  #define Rte_Write_PPortDiagMapDebugMode_DEPAlgoDebugMode Rte_Write_SWCDiag_PPortDiagMapDebugMode_DEPAlgoDebugMode
#endif


  /* Rte_Write Api mapping  [Satisfies_rte sws 1071], [Satisfies_rte sws 1280].*/
  /* Std_ReturnType Rte_Write_<p>_<o>([IN Rte_Instance <instance>],IN <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWCDiag_PPortDiagPodDebugMode_DEPAlgoDebugMode(IN VAR(RTE_t_eAlgoDebugMode, AUTOMATIC) arg1);
#ifndef RTE_C
  #define Rte_Write_PPortDiagPodDebugMode_DEPAlgoDebugMode Rte_Write_SWCDiag_PPortDiagPodDebugMode_DEPAlgoDebugMode
#endif


  /* Rte_Write Api mapping  [Satisfies_rte sws 1071], [Satisfies_rte sws 1280].*/
  /* Std_ReturnType Rte_Write_<p>_<o>([IN Rte_Instance <instance>],IN <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWCDiag_PPortDiagPrDebugMode_DEPAlgoDebugMode(IN VAR(RTE_t_eAlgoDebugMode, AUTOMATIC) arg1);
#ifndef RTE_C
  #define Rte_Write_PPortDiagPrDebugMode_DEPAlgoDebugMode Rte_Write_SWCDiag_PPortDiagPrDebugMode_DEPAlgoDebugMode
#endif


  /* Rte_Write Api mapping  [Satisfies_rte sws 1071], [Satisfies_rte sws 1280].*/
  /* Std_ReturnType Rte_Write_<p>_<o>([IN Rte_Instance <instance>],IN <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWCDiag_PPortDiagPvDebugMode_DEPAlgoDebugMode(IN VAR(RTE_t_eAlgoDebugMode, AUTOMATIC) arg1);
#ifndef RTE_C
  #define Rte_Write_PPortDiagPvDebugMode_DEPAlgoDebugMode Rte_Write_SWCDiag_PPortDiagPvDebugMode_DEPAlgoDebugMode
#endif


  /* Rte_Write Api mapping  [Satisfies_rte sws 1071], [Satisfies_rte sws 1280].*/
  /* Std_ReturnType Rte_Write_<p>_<o>([IN Rte_Instance <instance>],IN <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWCDiag_PPortDiagSacDebugMode_DEPAlgoDebugMode(IN VAR(RTE_t_eAlgoDebugMode, AUTOMATIC) arg1);
#ifndef RTE_C
  #define Rte_Write_PPortDiagSacDebugMode_DEPAlgoDebugMode Rte_Write_SWCDiag_PPortDiagSacDebugMode_DEPAlgoDebugMode
#endif


  /* Rte_Write Api mapping  [Satisfies_rte sws 1071], [Satisfies_rte sws 1280].*/
  /* Std_ReturnType Rte_Write_<p>_<o>([IN Rte_Instance <instance>],IN <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWCDiag_PPortDiagSlneDebugMode_DEPAlgoDebugMode(IN VAR(RTE_t_eAlgoDebugMode, AUTOMATIC) arg1);
#ifndef RTE_C
  #define Rte_Write_PPortDiagSlneDebugMode_DEPAlgoDebugMode Rte_Write_SWCDiag_PPortDiagSlneDebugMode_DEPAlgoDebugMode
#endif


  /* Rte_Write Api mapping  [Satisfies_rte sws 1071], [Satisfies_rte sws 1280].*/
  /* Std_ReturnType Rte_Write_<p>_<o>([IN Rte_Instance <instance>],IN <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWCDiag_PPortDiagSrDebugMode_DEPAlgoDebugMode(IN VAR(RTE_t_eAlgoDebugMode, AUTOMATIC) arg1);
#ifndef RTE_C
  #define Rte_Write_PPortDiagSrDebugMode_DEPAlgoDebugMode Rte_Write_SWCDiag_PPortDiagSrDebugMode_DEPAlgoDebugMode
#endif


  /* Rte_Write Api mapping  [Satisfies_rte sws 1071], [Satisfies_rte sws 1280].*/
  /* Std_ReturnType Rte_Write_<p>_<o>([IN Rte_Instance <instance>],IN <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWCDiag_PPortDiagTsaDebugMode_DEPAlgoDebugMode(IN VAR(RTE_t_eAlgoDebugMode, AUTOMATIC) arg1);
#ifndef RTE_C
  #define Rte_Write_PPortDiagTsaDebugMode_DEPAlgoDebugMode Rte_Write_SWCDiag_PPortDiagTsaDebugMode_DEPAlgoDebugMode
#endif


  /* Rte_Write Api mapping  [Satisfies_rte sws 1071], [Satisfies_rte sws 1280].*/
  /* Std_ReturnType Rte_Write_<p>_<o>([IN Rte_Instance <instance>],IN <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWCDiag_PPortDiagTsaDispTest_DEPTsaDispTest(IN VAR(RTE_t_eTSADispTest, AUTOMATIC) arg1);
#ifndef RTE_C
  #define Rte_Write_PPortDiagTsaDispTest_DEPTsaDispTest Rte_Write_SWCDiag_PPortDiagTsaDispTest_DEPTsaDispTest
#endif


  /* Rte_Write Api mapping  [Satisfies_rte sws 1071], [Satisfies_rte sws 1280].*/
  /* Std_ReturnType Rte_Write_<p>_<o>([IN Rte_Instance <instance>],IN <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWCDiag_PPortDiagVdyDebugMode_DEPAlgoDebugMode(IN VAR(RTE_t_eAlgoDebugMode, AUTOMATIC) arg1);
#ifndef RTE_C
  #define Rte_Write_PPortDiagVdyDebugMode_DEPAlgoDebugMode Rte_Write_SWCDiag_PPortDiagVdyDebugMode_DEPAlgoDebugMode
#endif


  /* Rte_Write Api mapping  [Satisfies_rte sws 1071], [Satisfies_rte sws 1280].*/
  /* Std_ReturnType Rte_Write_<p>_<o>([IN Rte_Instance <instance>],IN <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWCDiag_PPortDiagVlnDebugMode_DEPAlgoDebugMode(IN VAR(RTE_t_eAlgoDebugMode, AUTOMATIC) arg1);
#ifndef RTE_C
  #define Rte_Write_PPortDiagVlnDebugMode_DEPAlgoDebugMode Rte_Write_SWCDiag_PPortDiagVlnDebugMode_DEPAlgoDebugMode
#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(RTE_t_AdcReads, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCDiag_RunEntDiag_RPortDiagAdcData_DEPAdcData(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntDiag_RPortDiagAdcData_DEPAdcData \
    Rte_IRead_SWCDiag_RunEntDiag_RPortDiagAdcData_DEPAdcData

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(RTE_t_DiagAlgoStates, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCDiag_RunEntDiag_RPortDiagAlgoStates_DEPDiagAlgoStates(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntDiag_RPortDiagAlgoStates_DEPDiagAlgoStates \
    Rte_IRead_SWCDiag_RunEntDiag_RPortDiagAlgoStates_DEPDiagAlgoStates

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(RTE_CALI_t_EnvData, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCDiag_RunEntDiag_RPortDiagCaliEnvData_DEP_CaliEnvData(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntDiag_RPortDiagCaliEnvData_DEP_CaliEnvData \
    Rte_IRead_SWCDiag_RunEntDiag_RPortDiagCaliEnvData_DEP_CaliEnvData

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(VAR(RTE_CALI_t_eStatus, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCDiag_RunEntDiag_RPortDiagCaliStatus_DEP_CaliStatus(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntDiag_RPortDiagCaliStatus_DEP_CaliStatus \
    Rte_IRead_SWCDiag_RunEntDiag_RPortDiagCaliStatus_DEP_CaliStatus

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(S_CamPos_CALIOutput, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCDiag_RunEntDiag_RPortDiagCamPos_DEP_SensorAngles(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntDiag_RPortDiagCamPos_DEP_SensorAngles \
    Rte_IRead_SWCDiag_RunEntDiag_RPortDiagCamPos_DEP_SensorAngles

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(RTE_t_HeatOutput, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCDiag_RunEntDiag_RPortDiagHeatState_DEP_HeatStateOutput(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntDiag_RPortDiagHeatState_DEP_HeatStateOutput \
    Rte_IRead_SWCDiag_RunEntDiag_RPortDiagHeatState_DEP_HeatStateOutput

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(RTE_t_HeatStatistics, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCDiag_RunEntDiag_RPortDiagHeatStatistics_DEP_HeatStatistics(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntDiag_RPortDiagHeatStatistics_DEP_HeatStatistics \
    Rte_IRead_SWCDiag_RunEntDiag_RPortDiagHeatStatistics_DEP_HeatStatistics

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(RTE_t_MaxTemperature, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCDiag_RunEntDiag_RPortDiagMaxTemperature_DEPMaxTemperature(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntDiag_RPortDiagMaxTemperature_DEPMaxTemperature \
    Rte_IRead_SWCDiag_RunEntDiag_RPortDiagMaxTemperature_DEPMaxTemperature

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(RTE_t_PPARImagerIntrinsics, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCDiag_RunEntDiag_RPortDiagPparImgIntrins_DEP_PPARImagerIntrinsRight(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntDiag_RPortDiagPparImgIntrins_DEP_PPARImagerIntrinsRight \
    Rte_IRead_SWCDiag_RunEntDiag_RPortDiagPparImgIntrins_DEP_PPARImagerIntrinsRight

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(S_SacDistTestFromToNVM, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCDiag_RunEntDiag_RPortDiagSacDistTestResult_DEPSacDistTestResult(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntDiag_RPortDiagSacDistTestResult_DEPSacDistTestResult \
    Rte_IRead_SWCDiag_RunEntDiag_RPortDiagSacDistTestResult_DEPSacDistTestResult

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(RTE_t_SACOutput, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCDiag_RunEntDiag_RPortDiagSacOutput_DEPSacOutput(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntDiag_RPortDiagSacOutput_DEPSacOutput \
    Rte_IRead_SWCDiag_RunEntDiag_RPortDiagSacOutput_DEPSacOutput

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(RTE_t_VCVehicleData, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCDiag_RunEntDiag_RPortDiagVcVehicleData_DEP_VCVehicleData(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntDiag_RPortDiagVcVehicleData_DEP_VCVehicleData \
    Rte_IRead_SWCDiag_RunEntDiag_RPortDiagVcVehicleData_DEP_VCVehicleData

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(RTE_t_VehicleLevel, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCDiag_RunEntDiag_RPortDiagVehLvl_DEP_VehLvl(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntDiag_RPortDiagVehLvl_DEP_VehLvl \
    Rte_IRead_SWCDiag_RunEntDiag_RPortDiagVehLvl_DEP_VehLvl

#endif


  /* Rte_IWrite Api mapping  [Satisfies_rte sws 3744], [Satisfies_rte sws 1302], [Satisfies_rte sws 3746], [Satisfies_rte sws 3747].*/
  /* void Rte_IWrite_<re>_<p>_<d>([IN RTE_Instance], IN <type>) */
extern FUNC(void, RTE_CODE) Rte_IWrite_SWCDiag_RunEntDiag_PPortDiagAldwOpMode_DEP_FctAldwOpMode(VAR(eALDWOpMode_t, RTE_APPL_DATA) arg1);
extern FUNC( P2VAR(eALDWOpMode_t, AUTOMATIC, RTE_APPL_DATA), RTE_CODE ) Rte_IWriteRef_SWCDiag_RunEntDiag_PPortDiagAldwOpMode_DEP_FctAldwOpMode();

#ifndef RTE_C
  #define Rte_IWrite_RunEntDiag_PPortDiagAldwOpMode_DEP_FctAldwOpMode \
    Rte_IWrite_SWCDiag_RunEntDiag_PPortDiagAldwOpMode_DEP_FctAldwOpMode

  #define Rte_IWriteRef_RunEntDiag_PPortDiagAldwOpMode_DEP_FctAldwOpMode \
    Rte_IWriteRef_SWCDiag_RunEntDiag_PPortDiagAldwOpMode_DEP_FctAldwOpMode

#endif

  /* Rte_IWrite Api mapping  [Satisfies_rte sws 3744], [Satisfies_rte sws 1302], [Satisfies_rte sws 3746], [Satisfies_rte sws 3747].*/
  /* void Rte_IWrite_<re>_<p>_<d>([IN RTE_Instance], IN <type>) */
extern FUNC(void, RTE_CODE) Rte_IWrite_SWCDiag_RunEntDiag_PPortDiagCaliCarBody_DEP_CaliCarBody(P2VAR(RTE_CALI_t_HeightCarBody, AUTOMATIC, RTE_APPL_DATA) arg1);
extern FUNC( P2VAR(RTE_CALI_t_HeightCarBody, AUTOMATIC, RTE_APPL_DATA), RTE_CODE ) Rte_IWriteRef_SWCDiag_RunEntDiag_PPortDiagCaliCarBody_DEP_CaliCarBody();

#ifndef RTE_C
  #define Rte_IWrite_RunEntDiag_PPortDiagCaliCarBody_DEP_CaliCarBody \
    Rte_IWrite_SWCDiag_RunEntDiag_PPortDiagCaliCarBody_DEP_CaliCarBody

  #define Rte_IWriteRef_RunEntDiag_PPortDiagCaliCarBody_DEP_CaliCarBody \
    Rte_IWriteRef_SWCDiag_RunEntDiag_PPortDiagCaliCarBody_DEP_CaliCarBody

#endif

  /* Rte_IWrite Api mapping  [Satisfies_rte sws 3744], [Satisfies_rte sws 1302], [Satisfies_rte sws 3746], [Satisfies_rte sws 3747].*/
  /* void Rte_IWrite_<re>_<p>_<d>([IN RTE_Instance], IN <type>) */
extern FUNC(void, RTE_CODE) Rte_IWrite_SWCDiag_RunEntDiag_PPortDiagCalibPatternType_DEPCalibPatternType(VAR(RTE_t_CalibPatternType, RTE_APPL_DATA) arg1);
extern FUNC( P2VAR(RTE_t_CalibPatternType, AUTOMATIC, RTE_APPL_DATA), RTE_CODE ) Rte_IWriteRef_SWCDiag_RunEntDiag_PPortDiagCalibPatternType_DEPCalibPatternType();

#ifndef RTE_C
  #define Rte_IWrite_RunEntDiag_PPortDiagCalibPatternType_DEPCalibPatternType \
    Rte_IWrite_SWCDiag_RunEntDiag_PPortDiagCalibPatternType_DEPCalibPatternType

  #define Rte_IWriteRef_RunEntDiag_PPortDiagCalibPatternType_DEPCalibPatternType \
    Rte_IWriteRef_SWCDiag_RunEntDiag_PPortDiagCalibPatternType_DEPCalibPatternType

#endif

  /* Rte_IWrite Api mapping  [Satisfies_rte sws 3744], [Satisfies_rte sws 1302], [Satisfies_rte sws 3746], [Satisfies_rte sws 3747].*/
  /* void Rte_IWrite_<re>_<p>_<d>([IN RTE_Instance], IN <type>) */
extern FUNC(void, RTE_CODE) Rte_IWrite_SWCDiag_RunEntDiag_PPortDiagSacDistTestInput_DEPSacDistTestInput(P2VAR(S_SacDistTestInput, AUTOMATIC, RTE_APPL_DATA) arg1);
extern FUNC( P2VAR(S_SacDistTestInput, AUTOMATIC, RTE_APPL_DATA), RTE_CODE ) Rte_IWriteRef_SWCDiag_RunEntDiag_PPortDiagSacDistTestInput_DEPSacDistTestInput();

#ifndef RTE_C
  #define Rte_IWrite_RunEntDiag_PPortDiagSacDistTestInput_DEPSacDistTestInput \
    Rte_IWrite_SWCDiag_RunEntDiag_PPortDiagSacDistTestInput_DEPSacDistTestInput

  #define Rte_IWriteRef_RunEntDiag_PPortDiagSacDistTestInput_DEPSacDistTestInput \
    Rte_IWriteRef_SWCDiag_RunEntDiag_PPortDiagSacDistTestInput_DEPSacDistTestInput

#endif

  /* Rte_IWrite Api mapping  [Satisfies_rte sws 3744], [Satisfies_rte sws 1302], [Satisfies_rte sws 3746], [Satisfies_rte sws 3747].*/
  /* void Rte_IWrite_<re>_<p>_<d>([IN RTE_Instance], IN <type>) */
extern FUNC(void, RTE_CODE) Rte_IWrite_SWCDiag_RunEntDiag_PPortDiagSacOutput_DEPSacOutput(P2VAR(RTE_t_SACOutput, AUTOMATIC, RTE_APPL_DATA) arg1);
extern FUNC( P2VAR(RTE_t_SACOutput, AUTOMATIC, RTE_APPL_DATA), RTE_CODE ) Rte_IWriteRef_SWCDiag_RunEntDiag_PPortDiagSacOutput_DEPSacOutput();

#ifndef RTE_C
  #define Rte_IWrite_RunEntDiag_PPortDiagSacOutput_DEPSacOutput \
    Rte_IWrite_SWCDiag_RunEntDiag_PPortDiagSacOutput_DEPSacOutput

  #define Rte_IWriteRef_RunEntDiag_PPortDiagSacOutput_DEPSacOutput \
    Rte_IWriteRef_SWCDiag_RunEntDiag_PPortDiagSacOutput_DEPSacOutput

#endif

  /* Rte_IWrite Api mapping  [Satisfies_rte sws 3744], [Satisfies_rte sws 1302], [Satisfies_rte sws 3746], [Satisfies_rte sws 3747].*/
  /* void Rte_IWrite_<re>_<p>_<d>([IN RTE_Instance], IN <type>) */
extern FUNC(void, RTE_CODE) Rte_IWrite_SWCDiag_RunEntDiag_PPortDiagTsaDiagInput_DEPRequestDataSrc(VAR(uint8, RTE_APPL_DATA) arg1);
extern FUNC( P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA), RTE_CODE ) Rte_IWriteRef_SWCDiag_RunEntDiag_PPortDiagTsaDiagInput_DEPRequestDataSrc();

#ifndef RTE_C
  #define Rte_IWrite_RunEntDiag_PPortDiagTsaDiagInput_DEPRequestDataSrc \
    Rte_IWrite_SWCDiag_RunEntDiag_PPortDiagTsaDiagInput_DEPRequestDataSrc

  #define Rte_IWriteRef_RunEntDiag_PPortDiagTsaDiagInput_DEPRequestDataSrc \
    Rte_IWriteRef_SWCDiag_RunEntDiag_PPortDiagTsaDiagInput_DEPRequestDataSrc

#endif

  /* Rte_IWrite Api mapping  [Satisfies_rte sws 3744], [Satisfies_rte sws 1302], [Satisfies_rte sws 3746], [Satisfies_rte sws 3747].*/
  /* void Rte_IWrite_<re>_<p>_<d>([IN RTE_Instance], IN <type>) */
extern FUNC(void, RTE_CODE) Rte_IWrite_SWCDiag_RunEntDiag_PPortDiagTsaDiagInput_DEPResetBlockageData(VAR(boolean, RTE_APPL_DATA) arg1);
extern FUNC( P2VAR(boolean, AUTOMATIC, RTE_APPL_DATA), RTE_CODE ) Rte_IWriteRef_SWCDiag_RunEntDiag_PPortDiagTsaDiagInput_DEPResetBlockageData();

#ifndef RTE_C
  #define Rte_IWrite_RunEntDiag_PPortDiagTsaDiagInput_DEPResetBlockageData \
    Rte_IWrite_SWCDiag_RunEntDiag_PPortDiagTsaDiagInput_DEPResetBlockageData

  #define Rte_IWriteRef_RunEntDiag_PPortDiagTsaDiagInput_DEPResetBlockageData \
    Rte_IWriteRef_SWCDiag_RunEntDiag_PPortDiagTsaDiagInput_DEPResetBlockageData

#endif

  /* Rte_IWrite Api mapping  [Satisfies_rte sws 3744], [Satisfies_rte sws 1302], [Satisfies_rte sws 3746], [Satisfies_rte sws 3747].*/
  /* void Rte_IWrite_<re>_<p>_<d>([IN RTE_Instance], IN <type>) */
extern FUNC(void, RTE_CODE) Rte_IWrite_SWCDiag_RunEntDiag_PPortHeatDiagIO_DEP_HeatDiagIO(VAR(RTE_t_DiagHeatRq, RTE_APPL_DATA) arg1);
extern FUNC( P2VAR(RTE_t_DiagHeatRq, AUTOMATIC, RTE_APPL_DATA), RTE_CODE ) Rte_IWriteRef_SWCDiag_RunEntDiag_PPortHeatDiagIO_DEP_HeatDiagIO();

#ifndef RTE_C
  #define Rte_IWrite_RunEntDiag_PPortHeatDiagIO_DEP_HeatDiagIO \
    Rte_IWrite_SWCDiag_RunEntDiag_PPortHeatDiagIO_DEP_HeatDiagIO

  #define Rte_IWriteRef_RunEntDiag_PPortHeatDiagIO_DEP_HeatDiagIO \
    Rte_IWriteRef_SWCDiag_RunEntDiag_PPortHeatDiagIO_DEP_HeatDiagIO

#endif








#ifdef __cplusplus
	} /* extern "C" */
#endif /* __cplusplus */


#endif
