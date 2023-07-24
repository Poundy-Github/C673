/**************************************************************************
This file is generated automatically by the RTE generator
Filename:	Rte_SWCCaliAdapt.h
CESSAR-CT Version: 3.1.1.11
RTE Version: 3.2.0.1.3.0
Generated on:	Tue Jun 19 11:26:15 CEST 2012
**************************************************************************/


#ifndef _RTE_SWCCaliAdapt_H_
#define _RTE_SWCCaliAdapt_H_



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
  typedef CONSTP2CONST(Rte_CDS_SWCCaliAdapt, AUTOMATIC, RTE_CONST) Rte_Instance;
#endif /* RTE_C */

/* SWC:SWCCaliAdapt Indirect API */
	/* The name of the instance handle is Rte_Inst_<c> [Satisfies_rte sws 3793]. */
extern CONST(Rte_CDS_SWCCaliAdapt, RTE_CONST) Rte_Instance_SWCCaliAdapt;

#ifndef RTE_C

	/*  Provided ports */



	/*  Required ports */


#endif



/* runnable entry points (symbol) */

extern void CALI_v_AdaptInit (void); 
extern void CALI_v_AdaptExec (void); 


/* application error code */
#ifndef RTE_E_CSI_Timer64GetTimerValue_E_NOT_OK
  #define RTE_E_CSI_Timer64GetTimerValue_E_NOT_OK 1
#endif



/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/COMPONENTTYPES/IntBehCaliAdapt/RunEntCaliAdaptExec/SSCP_CaliTimer64GetTimerValue */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWCCaliAdapt_RPortCaliTimer64GetTimerValue_OPTimer64GetTimerValue( OUT P2VAR(uint64,AUTOMATIC,RTE_APPL_DATA) timerValue);
#ifndef RTE_C
  #define Rte_Call_RPortCaliTimer64GetTimerValue_OPTimer64GetTimerValue Rte_Call_SWCCaliAdapt_RPortCaliTimer64GetTimerValue_OPTimer64GetTimerValue
#endif






#ifndef RTE_C
  #define Rte_InitValue_RPortCaliCalibPatternType_DEPCalibPatternType (0)
#endif

#ifndef RTE_C
  #define Rte_InitValue_RPortCaliMode_DEP_CaliMode (0)
#endif

#ifndef RTE_C
  #define Rte_InitValue_PPortCaliSigState_DEP_CaliSigStatus (0)
#endif

#ifndef RTE_C
  #define Rte_InitValue_PPortCaliStatus_DEP_CaliStatus (0)
#endif


  /* Rte_Read Api mapping  [Satisfies_rte sws 1091].*/
  /* Std_ReturnType Rte_Read_<p>_<o>([IN Rte_Instance <instance>],OUT <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWCCaliAdapt_RPortCaliCamSocketDiag_DEP_CaliDiagCamSocket(OUT P2VAR(RTE_t_DiagCamSocket, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Read_RPortCaliCamSocketDiag_DEP_CaliDiagCamSocket Rte_Read_SWCCaliAdapt_RPortCaliCamSocketDiag_DEP_CaliDiagCamSocket
#endif


  /* Rte_Read Api mapping  [Satisfies_rte sws 1091].*/
  /* Std_ReturnType Rte_Read_<p>_<o>([IN Rte_Instance <instance>],OUT <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWCCaliAdapt_RPortCaliIcImageCharEven_DEPIcImageCharacteristics(OUT P2VAR(RTE_t_IC_S_ImageCharacteristics, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Read_RPortCaliIcImageCharEven_DEPIcImageCharacteristics Rte_Read_SWCCaliAdapt_RPortCaliIcImageCharEven_DEPIcImageCharacteristics
#endif


  /* Rte_Read Api mapping  [Satisfies_rte sws 1091].*/
  /* Std_ReturnType Rte_Read_<p>_<o>([IN Rte_Instance <instance>],OUT <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWCCaliAdapt_RPortCaliIcImageCharOdd_DEPIcImageCharacteristics(OUT P2VAR(RTE_t_IC_S_ImageCharacteristics, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Read_RPortCaliIcImageCharOdd_DEPIcImageCharacteristics Rte_Read_SWCCaliAdapt_RPortCaliIcImageCharOdd_DEPIcImageCharacteristics
#endif


  /* Rte_Read Api mapping  [Satisfies_rte sws 1091].*/
  /* Std_ReturnType Rte_Read_<p>_<o>([IN Rte_Instance <instance>],OUT <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWCCaliAdapt_RPortCaliIcStatResultsEven_DEPIcStatisticalResults(OUT P2VAR(RTE_t_IC_S_StatisticalResults, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Read_RPortCaliIcStatResultsEven_DEPIcStatisticalResults Rte_Read_SWCCaliAdapt_RPortCaliIcStatResultsEven_DEPIcStatisticalResults
#endif


  /* Rte_Read Api mapping  [Satisfies_rte sws 1091].*/
  /* Std_ReturnType Rte_Read_<p>_<o>([IN Rte_Instance <instance>],OUT <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWCCaliAdapt_RPortCaliIcStatResultsOdd_DEPIcStatisticalResults(OUT P2VAR(RTE_t_IC_S_StatisticalResults, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Read_RPortCaliIcStatResultsOdd_DEPIcStatisticalResults Rte_Read_SWCCaliAdapt_RPortCaliIcStatResultsOdd_DEPIcStatisticalResults
#endif


  /* Rte_Read Api mapping  [Satisfies_rte sws 1091].*/
  /* Std_ReturnType Rte_Read_<p>_<o>([IN Rte_Instance <instance>],OUT <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWCCaliAdapt_RPortCaliMode_DEP_CaliMode(OUT P2VAR(RTE_CALI_t_eCALIMode, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Read_RPortCaliMode_DEP_CaliMode Rte_Read_SWCCaliAdapt_RPortCaliMode_DEP_CaliMode
#endif


  /* Rte_Read Api mapping  [Satisfies_rte sws 1091].*/
  /* Std_ReturnType Rte_Read_<p>_<o>([IN Rte_Instance <instance>],OUT <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWCCaliAdapt_RPortCaliPatPosDiag_DEP_CaliPatternPosition(OUT P2VAR(RTE_t_DiagPatternPosition, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Read_RPortCaliPatPosDiag_DEP_CaliPatternPosition Rte_Read_SWCCaliAdapt_RPortCaliPatPosDiag_DEP_CaliPatternPosition
#endif


  /* Rte_Write Api mapping  [Satisfies_rte sws 1071], [Satisfies_rte sws 1280].*/
  /* Std_ReturnType Rte_Write_<p>_<o>([IN Rte_Instance <instance>],IN <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWCCaliAdapt_PPortCaliAlgoVersion_DEPAlgoVersion(IN P2VAR(RTE_t_AlgoVersion, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Write_PPortCaliAlgoVersion_DEPAlgoVersion Rte_Write_SWCCaliAdapt_PPortCaliAlgoVersion_DEPAlgoVersion
#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(VAR(RTE_t_CalibPatternType, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCCaliAdapt_RunEntCaliAdaptExec_RPortCaliCalibPatternType_DEPCalibPatternType(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntCaliAdaptExec_RPortCaliCalibPatternType_DEPCalibPatternType \
    Rte_IRead_SWCCaliAdapt_RunEntCaliAdaptExec_RPortCaliCalibPatternType_DEPCalibPatternType

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(RTE_CALI_t_HeightCarBody, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCCaliAdapt_RunEntCaliAdaptExec_RPortCaliCarBody_DEP_CaliCarBody(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntCaliAdaptExec_RPortCaliCarBody_DEP_CaliCarBody \
    Rte_IRead_SWCCaliAdapt_RunEntCaliAdaptExec_RPortCaliCarBody_DEP_CaliCarBody

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(RTE_t_PPARImagerIntrinsics, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCCaliAdapt_RunEntCaliAdaptExec_RPortCaliPparImgIntrins_DEP_PPARImagerIntrinsRight(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntCaliAdaptExec_RPortCaliPparImgIntrins_DEP_PPARImagerIntrinsRight \
    Rte_IRead_SWCCaliAdapt_RunEntCaliAdaptExec_RPortCaliPparImgIntrins_DEP_PPARImagerIntrinsRight

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(RTE_t_VCVehicleData, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCCaliAdapt_RunEntCaliAdaptExec_RPortCaliVcVehicleData_DEP_VCVehicleData(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntCaliAdaptExec_RPortCaliVcVehicleData_DEP_VCVehicleData \
    Rte_IRead_SWCCaliAdapt_RunEntCaliAdaptExec_RPortCaliVcVehicleData_DEP_VCVehicleData

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(RTE_t_VehicleLevel, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCCaliAdapt_RunEntCaliAdaptExec_RPortCaliVehLvl_DEP_VehLvl(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntCaliAdaptExec_RPortCaliVehLvl_DEP_VehLvl \
    Rte_IRead_SWCCaliAdapt_RunEntCaliAdaptExec_RPortCaliVehLvl_DEP_VehLvl

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
  extern FUNC(P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCCaliAdapt_RunEntCaliAdaptExec_RPortCaliVin_DEP_CaliVin(void);
#else
  extern FUNC(P2VAR(RTE_aui8_VIN, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCCaliAdapt_RunEntCaliAdaptExec_RPortCaliVin_DEP_CaliVin(void);
#endif

#ifndef RTE_C
  #define Rte_IRead_RunEntCaliAdaptExec_RPortCaliVin_DEP_CaliVin \
    Rte_IRead_SWCCaliAdapt_RunEntCaliAdaptExec_RPortCaliVin_DEP_CaliVin

#endif


  /* Rte_IWrite Api mapping  [Satisfies_rte sws 3744], [Satisfies_rte sws 1302], [Satisfies_rte sws 3746], [Satisfies_rte sws 3747].*/
  /* void Rte_IWrite_<re>_<p>_<d>([IN RTE_Instance], IN <type>) */
extern FUNC(void, RTE_CODE) Rte_IWrite_SWCCaliAdapt_RunEntCaliAdaptExec_PPortCaliCamPos_DEP_SensorAngles(P2VAR(S_CamPos_CALIOutput, AUTOMATIC, RTE_APPL_DATA) arg1);
extern FUNC( P2VAR(S_CamPos_CALIOutput, AUTOMATIC, RTE_APPL_DATA), RTE_CODE ) Rte_IWriteRef_SWCCaliAdapt_RunEntCaliAdaptExec_PPortCaliCamPos_DEP_SensorAngles();

#ifndef RTE_C
  #define Rte_IWrite_RunEntCaliAdaptExec_PPortCaliCamPos_DEP_SensorAngles \
    Rte_IWrite_SWCCaliAdapt_RunEntCaliAdaptExec_PPortCaliCamPos_DEP_SensorAngles

  #define Rte_IWriteRef_RunEntCaliAdaptExec_PPortCaliCamPos_DEP_SensorAngles \
    Rte_IWriteRef_SWCCaliAdapt_RunEntCaliAdaptExec_PPortCaliCamPos_DEP_SensorAngles

#endif

  /* Rte_IWrite Api mapping  [Satisfies_rte sws 3744], [Satisfies_rte sws 1302], [Satisfies_rte sws 3746], [Satisfies_rte sws 3747].*/
  /* void Rte_IWrite_<re>_<p>_<d>([IN RTE_Instance], IN <type>) */
extern FUNC(void, RTE_CODE) Rte_IWrite_SWCCaliAdapt_RunEntCaliAdaptExec_PPortCaliEnvData_DEP_CaliEnvData(P2VAR(RTE_CALI_t_EnvData, AUTOMATIC, RTE_APPL_DATA) arg1);
extern FUNC( P2VAR(RTE_CALI_t_EnvData, AUTOMATIC, RTE_APPL_DATA), RTE_CODE ) Rte_IWriteRef_SWCCaliAdapt_RunEntCaliAdaptExec_PPortCaliEnvData_DEP_CaliEnvData();

#ifndef RTE_C
  #define Rte_IWrite_RunEntCaliAdaptExec_PPortCaliEnvData_DEP_CaliEnvData \
    Rte_IWrite_SWCCaliAdapt_RunEntCaliAdaptExec_PPortCaliEnvData_DEP_CaliEnvData

  #define Rte_IWriteRef_RunEntCaliAdaptExec_PPortCaliEnvData_DEP_CaliEnvData \
    Rte_IWriteRef_SWCCaliAdapt_RunEntCaliAdaptExec_PPortCaliEnvData_DEP_CaliEnvData

#endif

  /* Rte_IWrite Api mapping  [Satisfies_rte sws 3744], [Satisfies_rte sws 1302], [Satisfies_rte sws 3746], [Satisfies_rte sws 3747].*/
  /* void Rte_IWrite_<re>_<p>_<d>([IN RTE_Instance], IN <type>) */
extern FUNC(void, RTE_CODE) Rte_IWrite_SWCCaliAdapt_RunEntCaliAdaptExec_PPortCaliFoV_DEP_CaliFoV(P2VAR(RTE_CALI_t_FieldOfView, AUTOMATIC, RTE_APPL_DATA) arg1);
extern FUNC( P2VAR(RTE_CALI_t_FieldOfView, AUTOMATIC, RTE_APPL_DATA), RTE_CODE ) Rte_IWriteRef_SWCCaliAdapt_RunEntCaliAdaptExec_PPortCaliFoV_DEP_CaliFoV();

#ifndef RTE_C
  #define Rte_IWrite_RunEntCaliAdaptExec_PPortCaliFoV_DEP_CaliFoV \
    Rte_IWrite_SWCCaliAdapt_RunEntCaliAdaptExec_PPortCaliFoV_DEP_CaliFoV

  #define Rte_IWriteRef_RunEntCaliAdaptExec_PPortCaliFoV_DEP_CaliFoV \
    Rte_IWriteRef_SWCCaliAdapt_RunEntCaliAdaptExec_PPortCaliFoV_DEP_CaliFoV

#endif

  /* Rte_IWrite Api mapping  [Satisfies_rte sws 3744], [Satisfies_rte sws 1302], [Satisfies_rte sws 3746], [Satisfies_rte sws 3747].*/
  /* void Rte_IWrite_<re>_<p>_<d>([IN RTE_Instance], IN <type>) */
extern FUNC(void, RTE_CODE) Rte_IWrite_SWCCaliAdapt_RunEntCaliAdaptExec_PPortCaliSigState_DEP_CaliSigStatus(VAR(RTE_CALI_t_eSigStatus, RTE_APPL_DATA) arg1);
extern FUNC( P2VAR(RTE_CALI_t_eSigStatus, AUTOMATIC, RTE_APPL_DATA), RTE_CODE ) Rte_IWriteRef_SWCCaliAdapt_RunEntCaliAdaptExec_PPortCaliSigState_DEP_CaliSigStatus();

#ifndef RTE_C
  #define Rte_IWrite_RunEntCaliAdaptExec_PPortCaliSigState_DEP_CaliSigStatus \
    Rte_IWrite_SWCCaliAdapt_RunEntCaliAdaptExec_PPortCaliSigState_DEP_CaliSigStatus

  #define Rte_IWriteRef_RunEntCaliAdaptExec_PPortCaliSigState_DEP_CaliSigStatus \
    Rte_IWriteRef_SWCCaliAdapt_RunEntCaliAdaptExec_PPortCaliSigState_DEP_CaliSigStatus

#endif

  /* Rte_IWrite Api mapping  [Satisfies_rte sws 3744], [Satisfies_rte sws 1302], [Satisfies_rte sws 3746], [Satisfies_rte sws 3747].*/
  /* void Rte_IWrite_<re>_<p>_<d>([IN RTE_Instance], IN <type>) */
extern FUNC(void, RTE_CODE) Rte_IWrite_SWCCaliAdapt_RunEntCaliAdaptExec_PPortCaliStatus_DEP_CaliStatus(VAR(RTE_CALI_t_eStatus, RTE_APPL_DATA) arg1);
extern FUNC( P2VAR(RTE_CALI_t_eStatus, AUTOMATIC, RTE_APPL_DATA), RTE_CODE ) Rte_IWriteRef_SWCCaliAdapt_RunEntCaliAdaptExec_PPortCaliStatus_DEP_CaliStatus();

#ifndef RTE_C
  #define Rte_IWrite_RunEntCaliAdaptExec_PPortCaliStatus_DEP_CaliStatus \
    Rte_IWrite_SWCCaliAdapt_RunEntCaliAdaptExec_PPortCaliStatus_DEP_CaliStatus

  #define Rte_IWriteRef_RunEntCaliAdaptExec_PPortCaliStatus_DEP_CaliStatus \
    Rte_IWriteRef_SWCCaliAdapt_RunEntCaliAdaptExec_PPortCaliStatus_DEP_CaliStatus

#endif

  /* Rte_IWrite Api mapping  [Satisfies_rte sws 3744], [Satisfies_rte sws 1302], [Satisfies_rte sws 3746], [Satisfies_rte sws 3747].*/
  /* void Rte_IWrite_<re>_<p>_<d>([IN RTE_Instance], IN <type>) */
extern FUNC(void, RTE_CODE) Rte_IWrite_SWCCaliAdapt_RunEntCaliAdaptExec_PPortCaliTargetExtraction_DEPCaliTargetExtraction(P2VAR(RTE_CALI_t_TargetExtraction, AUTOMATIC, RTE_APPL_DATA) arg1);
extern FUNC( P2VAR(RTE_CALI_t_TargetExtraction, AUTOMATIC, RTE_APPL_DATA), RTE_CODE ) Rte_IWriteRef_SWCCaliAdapt_RunEntCaliAdaptExec_PPortCaliTargetExtraction_DEPCaliTargetExtraction();

#ifndef RTE_C
  #define Rte_IWrite_RunEntCaliAdaptExec_PPortCaliTargetExtraction_DEPCaliTargetExtraction \
    Rte_IWrite_SWCCaliAdapt_RunEntCaliAdaptExec_PPortCaliTargetExtraction_DEPCaliTargetExtraction

  #define Rte_IWriteRef_RunEntCaliAdaptExec_PPortCaliTargetExtraction_DEPCaliTargetExtraction \
    Rte_IWriteRef_SWCCaliAdapt_RunEntCaliAdaptExec_PPortCaliTargetExtraction_DEPCaliTargetExtraction

#endif


/* Mode API mapping */
extern FUNC(Rte_ModeType_EcuM_Mode, RTE_CODE) Rte_Mode_SWCCaliAdapt_RPortModeCaliAdapt_currentMode( void );
#ifndef RTE_C
	#define Rte_Mode_RPortModeCaliAdapt_currentMode  \
		Rte_Mode_SWCCaliAdapt_RPortModeCaliAdapt_currentMode
#endif







#ifdef __cplusplus
	} /* extern "C" */
#endif /* __cplusplus */


#endif
