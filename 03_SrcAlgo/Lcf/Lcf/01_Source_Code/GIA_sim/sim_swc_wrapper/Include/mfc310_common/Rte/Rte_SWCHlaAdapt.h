/**************************************************************************
This file is generated automatically by the RTE generator
Filename:	Rte_SWCHlaAdapt.h
CESSAR-CT Version: 3.1.1.11
RTE Version: 3.2.0.1.3.0
Generated on:	Tue Jun 19 11:26:15 CEST 2012
**************************************************************************/


#ifndef _RTE_SWCHlaAdapt_H_
#define _RTE_SWCHlaAdapt_H_



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
  typedef CONSTP2CONST(Rte_CDS_SWCHlaAdapt, AUTOMATIC, RTE_CONST) Rte_Instance;
#endif /* RTE_C */

/* SWC:SWCHlaAdapt Indirect API */
	/* The name of the instance handle is Rte_Inst_<c> [Satisfies_rte sws 3793]. */
extern CONST(Rte_CDS_SWCHlaAdapt, RTE_CONST) Rte_Instance_SWCHlaAdapt;

#ifndef RTE_C

	/*  Provided ports */



	/*  Required ports */


#endif



/* runnable entry points (symbol) */

extern void HLA_v_AdaptExec (void); 
extern void HLA_v_AdaptInit (GLB_fctp_AlgoInitialized_Callback* HLA_fctp_Init_Callback); 
extern void HLA_v_AdaptDeInit (GLB_fctp_AlgoInitialized_Callback* HLA_fctp_Init_Callback); 
/* runnable entry points (symbol) for servers */
extern FUNC(void, RTE_APPL_CODE) HLA_v_SetImageCharacteristics( INOUT P2VAR(RTE_t_IC_S_ImageCharacteristics,AUTOMATIC,RTE_APPL_DATA) ImageChar);



/* application error code */
#ifndef RTE_E_CSI_Timer64GetTimerValue_E_NOT_OK
  #define RTE_E_CSI_Timer64GetTimerValue_E_NOT_OK 1
#endif



/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/COMPONENTTYPES/IntBehHlaAdapt/RunEntHlaAdaptExec/SSCP_HlaTimer64GetTimerValue */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWCHlaAdapt_RPortHlaTimer64GetTimerValue_OPTimer64GetTimerValue( OUT P2VAR(uint64,AUTOMATIC,RTE_APPL_DATA) timerValue);
#ifndef RTE_C
  #define Rte_Call_RPortHlaTimer64GetTimerValue_OPTimer64GetTimerValue Rte_Call_SWCHlaAdapt_RPortHlaTimer64GetTimerValue_OPTimer64GetTimerValue
#endif






#ifndef RTE_C
  #define Rte_InitValue_RPortHlaDebugMode_DEPAlgoDebugMode (0)
#endif

#ifndef RTE_C
  #define Rte_InitValue_PPortHlaClearanceMeasurement_DEPClearanceMeasurement (0)
#endif


  /* Rte_Read Api mapping  [Satisfies_rte sws 1091].*/
  /* Std_ReturnType Rte_Read_<p>_<o>([IN Rte_Instance <instance>],OUT <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWCHlaAdapt_RPortHlaAvailability_DEPHlaAvailability(OUT P2VAR(RTE_HLA_t_Availability, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Read_RPortHlaAvailability_DEPHlaAvailability Rte_Read_SWCHlaAdapt_RPortHlaAvailability_DEPHlaAvailability
#endif


  /* Rte_Read Api mapping  [Satisfies_rte sws 1091].*/
  /* Std_ReturnType Rte_Read_<p>_<o>([IN Rte_Instance <instance>],OUT <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWCHlaAdapt_RPortHlaDebugMode_DEPAlgoDebugMode(OUT P2VAR(RTE_t_eAlgoDebugMode, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Read_RPortHlaDebugMode_DEPAlgoDebugMode Rte_Read_SWCHlaAdapt_RPortHlaDebugMode_DEPAlgoDebugMode
#endif


  /* Rte_Read Api mapping  [Satisfies_rte sws 1091].*/
  /* Std_ReturnType Rte_Read_<p>_<o>([IN Rte_Instance <instance>],OUT <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
  extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWCHlaAdapt_RPortHlaGbAoiBlockage_DEPGbAoiBlockage  (OUT P2VAR(RTE_GB_t_AOIBlockage, AUTOMATIC, RTE_APPL_DATA) arg1);
#else
  extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWCHlaAdapt_RPortHlaGbAoiBlockage_DEPGbAoiBlockage(OUT P2VAR(RTE_GB_t_AOIBlockage_array, AUTOMATIC, RTE_APPL_DATA) arg1);
#endif
#ifndef RTE_C
  #define Rte_Read_RPortHlaGbAoiBlockage_DEPGbAoiBlockage Rte_Read_SWCHlaAdapt_RPortHlaGbAoiBlockage_DEPGbAoiBlockage
#endif


  /* Rte_Read Api mapping  [Satisfies_rte sws 1091].*/
  /* Std_ReturnType Rte_Read_<p>_<o>([IN Rte_Instance <instance>],OUT <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWCHlaAdapt_RPortHlaHeadlightState_DEP_HeadlightState(OUT P2VAR(RTE_HLA_t_HeadlightState, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Read_RPortHlaHeadlightState_DEP_HeadlightState Rte_Read_SWCHlaAdapt_RPortHlaHeadlightState_DEP_HeadlightState
#endif


  /* Rte_Read Api mapping  [Satisfies_rte sws 1091].*/
  /* Std_ReturnType Rte_Read_<p>_<o>([IN Rte_Instance <instance>],OUT <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWCHlaAdapt_RPortHlaIcImageCharEven_DEPIcImageCharacteristics(OUT P2VAR(RTE_t_IC_S_ImageCharacteristics, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Read_RPortHlaIcImageCharEven_DEPIcImageCharacteristics Rte_Read_SWCHlaAdapt_RPortHlaIcImageCharEven_DEPIcImageCharacteristics
#endif


  /* Rte_Read Api mapping  [Satisfies_rte sws 1091].*/
  /* Std_ReturnType Rte_Read_<p>_<o>([IN Rte_Instance <instance>],OUT <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWCHlaAdapt_RPortHlaIcImageCharOdd_DEPIcImageCharacteristics(OUT P2VAR(RTE_t_IC_S_ImageCharacteristics, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Read_RPortHlaIcImageCharOdd_DEPIcImageCharacteristics Rte_Read_SWCHlaAdapt_RPortHlaIcImageCharOdd_DEPIcImageCharacteristics
#endif


  /* Rte_Read Api mapping  [Satisfies_rte sws 1091].*/
  /* Std_ReturnType Rte_Read_<p>_<o>([IN Rte_Instance <instance>],OUT <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWCHlaAdapt_RPortHlaIcStatResultsEven_DEPIcStatisticalResults(OUT P2VAR(RTE_t_IC_S_StatisticalResults, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Read_RPortHlaIcStatResultsEven_DEPIcStatisticalResults Rte_Read_SWCHlaAdapt_RPortHlaIcStatResultsEven_DEPIcStatisticalResults
#endif


  /* Rte_Read Api mapping  [Satisfies_rte sws 1091].*/
  /* Std_ReturnType Rte_Read_<p>_<o>([IN Rte_Instance <instance>],OUT <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWCHlaAdapt_RPortHlaIcStatResultsOdd_DEPIcStatisticalResults(OUT P2VAR(RTE_t_IC_S_StatisticalResults, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Read_RPortHlaIcStatResultsOdd_DEPIcStatisticalResults Rte_Read_SWCHlaAdapt_RPortHlaIcStatResultsOdd_DEPIcStatisticalResults
#endif


  /* Rte_Read Api mapping  [Satisfies_rte sws 1091].*/
  /* Std_ReturnType Rte_Read_<p>_<o>([IN Rte_Instance <instance>],OUT <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWCHlaAdapt_RPortHlaNvObject_DEP_HlaNvObject(OUT P2VAR(RTE_HLAF_t_NightView, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Read_RPortHlaNvObject_DEP_HlaNvObject Rte_Read_SWCHlaAdapt_RPortHlaNvObject_DEP_HlaNvObject
#endif


  /* Rte_Read Api mapping  [Satisfies_rte sws 1091].*/
  /* Std_ReturnType Rte_Read_<p>_<o>([IN Rte_Instance <instance>],OUT <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWCHlaAdapt_RPortHlaVehSpdDisp_DEP_VehSpdDisp(OUT P2VAR(RTE_t_VehSpdDisp, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Read_RPortHlaVehSpdDisp_DEP_VehSpdDisp Rte_Read_SWCHlaAdapt_RPortHlaVehSpdDisp_DEP_VehSpdDisp
#endif


  /* Rte_Read Api mapping  [Satisfies_rte sws 1091].*/
  /* Std_ReturnType Rte_Read_<p>_<o>([IN Rte_Instance <instance>],OUT <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWCHlaAdapt_RPortHlaVehicleState_DEPVehicleState(OUT P2VAR(RTE_HLA_t_VehicleState, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Read_RPortHlaVehicleState_DEPVehicleState Rte_Read_SWCHlaAdapt_RPortHlaVehicleState_DEPVehicleState
#endif


  /* Rte_Write Api mapping  [Satisfies_rte sws 1071], [Satisfies_rte sws 1280].*/
  /* Std_ReturnType Rte_Write_<p>_<o>([IN Rte_Instance <instance>],IN <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWCHlaAdapt_PPortHlaAlgoVersion_DEPAlgoVersion(IN P2VAR(RTE_t_AlgoVersion, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Write_PPortHlaAlgoVersion_DEPAlgoVersion Rte_Write_SWCHlaAdapt_PPortHlaAlgoVersion_DEPAlgoVersion
#endif


  /* Rte_Write Api mapping  [Satisfies_rte sws 1071], [Satisfies_rte sws 1280].*/
  /* Std_ReturnType Rte_Write_<p>_<o>([IN Rte_Instance <instance>],IN <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWCHlaAdapt_PPortHlaClearanceMeasurement_DEPClearanceMeasurement(IN VAR(uint32, AUTOMATIC) arg1);
#ifndef RTE_C
  #define Rte_Write_PPortHlaClearanceMeasurement_DEPClearanceMeasurement Rte_Write_SWCHlaAdapt_PPortHlaClearanceMeasurement_DEPClearanceMeasurement
#endif


  /* Rte_Write Api mapping  [Satisfies_rte sws 1071], [Satisfies_rte sws 1280].*/
  /* Std_ReturnType Rte_Write_<p>_<o>([IN Rte_Instance <instance>],IN <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWCHlaAdapt_PPortHlaNvObject_DEP_HlaNvObject(IN P2VAR(RTE_HLAF_t_NightView, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Write_PPortHlaNvObject_DEP_HlaNvObject Rte_Write_SWCHlaAdapt_PPortHlaNvObject_DEP_HlaNvObject
#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(RTE_CALI_t_HeightCarBody, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCHlaAdapt_RunEntHlaAdaptExec_RPortHlaCaliCarBody_DEP_CaliCarBody(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntHlaAdaptExec_RPortHlaCaliCarBody_DEP_CaliCarBody \
    Rte_IRead_SWCHlaAdapt_RunEntHlaAdaptExec_RPortHlaCaliCarBody_DEP_CaliCarBody

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(S_CamPos_CALIOutput, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCHlaAdapt_RunEntHlaAdaptExec_RPortHlaCamPos_DEP_SensorAngles(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntHlaAdaptExec_RPortHlaCamPos_DEP_SensorAngles \
    Rte_IRead_SWCHlaAdapt_RunEntHlaAdaptExec_RPortHlaCamPos_DEP_SensorAngles

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(RTE_GB_t_FctBlockageData, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCHlaAdapt_RunEntHlaAdaptExec_RPortHlaGbFctBlockage_DEPGbFctBlockage(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntHlaAdaptExec_RPortHlaGbFctBlockage_DEPGbFctBlockage \
    Rte_IRead_SWCHlaAdapt_RunEntHlaAdaptExec_RPortHlaGbFctBlockage_DEPGbFctBlockage

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(RTE_t_PPARImagerIntrinsics, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCHlaAdapt_RunEntHlaAdaptExec_RPortHlaImgIntrinsics_DEP_PPARImagerIntrinsRight(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntHlaAdaptExec_RPortHlaImgIntrinsics_DEP_PPARImagerIntrinsRight \
    Rte_IRead_SWCHlaAdapt_RunEntHlaAdaptExec_RPortHlaImgIntrinsics_DEP_PPARImagerIntrinsRight

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(RTE_t_VdyOutput, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCHlaAdapt_RunEntHlaAdaptExec_RPortHlaVdyOutput_DEPVdyOutput(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntHlaAdaptExec_RPortHlaVdyOutput_DEPVdyOutput \
    Rte_IRead_SWCHlaAdapt_RunEntHlaAdaptExec_RPortHlaVdyOutput_DEPVdyOutput

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(VehSig_t, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCHlaAdapt_RunEntHlaAdaptExec_RPortHlaVehSig_DEPBswVehSig(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntHlaAdaptExec_RPortHlaVehSig_DEPBswVehSig \
    Rte_IRead_SWCHlaAdapt_RunEntHlaAdaptExec_RPortHlaVehSig_DEPBswVehSig

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(RTE_HLA_t_VehicleParameter, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCHlaAdapt_RunEntHlaAdaptExec_RPortHlaVehicleParameter_DEPHlaVehicleParameter(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntHlaAdaptExec_RPortHlaVehicleParameter_DEPHlaVehicleParameter \
    Rte_IRead_SWCHlaAdapt_RunEntHlaAdaptExec_RPortHlaVehicleParameter_DEPHlaVehicleParameter

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(RTE_t_VCVehicleData, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCHlaAdapt_RunEntHlaAdaptInit_RPortHlaVcVehicleData_DEP_VCVehicleData(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntHlaAdaptInit_RPortHlaVcVehicleData_DEP_VCVehicleData \
    Rte_IRead_SWCHlaAdapt_RunEntHlaAdaptInit_RPortHlaVcVehicleData_DEP_VCVehicleData

#endif


  /* Rte_IWrite Api mapping  [Satisfies_rte sws 3744], [Satisfies_rte sws 1302], [Satisfies_rte sws 3746], [Satisfies_rte sws 3747].*/
  /* void Rte_IWrite_<re>_<p>_<d>([IN RTE_Instance], IN <type>) */
extern FUNC(void, RTE_CODE) Rte_IWrite_SWCHlaAdapt_RunEntHlaAdaptExec_PPortHlaCaliOnline_DEPHlaCaliOnline(P2VAR(RTE_HLA_t_CaliOnline, AUTOMATIC, RTE_APPL_DATA) arg1);
extern FUNC( P2VAR(RTE_HLA_t_CaliOnline, AUTOMATIC, RTE_APPL_DATA), RTE_CODE ) Rte_IWriteRef_SWCHlaAdapt_RunEntHlaAdaptExec_PPortHlaCaliOnline_DEPHlaCaliOnline();

#ifndef RTE_C
  #define Rte_IWrite_RunEntHlaAdaptExec_PPortHlaCaliOnline_DEPHlaCaliOnline \
    Rte_IWrite_SWCHlaAdapt_RunEntHlaAdaptExec_PPortHlaCaliOnline_DEPHlaCaliOnline

  #define Rte_IWriteRef_RunEntHlaAdaptExec_PPortHlaCaliOnline_DEPHlaCaliOnline \
    Rte_IWriteRef_SWCHlaAdapt_RunEntHlaAdaptExec_PPortHlaCaliOnline_DEPHlaCaliOnline

#endif

  /* Rte_IWrite Api mapping  [Satisfies_rte sws 3744], [Satisfies_rte sws 1302], [Satisfies_rte sws 3746], [Satisfies_rte sws 3747].*/
  /* void Rte_IWrite_<re>_<p>_<d>([IN RTE_Instance], IN <type>) */
extern FUNC(void, RTE_CODE) Rte_IWrite_SWCHlaAdapt_RunEntHlaAdaptExec_PPortHlaEnvironmentData_DEPHlaEnvironmentData(P2VAR(RTE_HLA_t_EnvironmentData, AUTOMATIC, RTE_APPL_DATA) arg1);
extern FUNC( P2VAR(RTE_HLA_t_EnvironmentData, AUTOMATIC, RTE_APPL_DATA), RTE_CODE ) Rte_IWriteRef_SWCHlaAdapt_RunEntHlaAdaptExec_PPortHlaEnvironmentData_DEPHlaEnvironmentData();

#ifndef RTE_C
  #define Rte_IWrite_RunEntHlaAdaptExec_PPortHlaEnvironmentData_DEPHlaEnvironmentData \
    Rte_IWrite_SWCHlaAdapt_RunEntHlaAdaptExec_PPortHlaEnvironmentData_DEPHlaEnvironmentData

  #define Rte_IWriteRef_RunEntHlaAdaptExec_PPortHlaEnvironmentData_DEPHlaEnvironmentData \
    Rte_IWriteRef_SWCHlaAdapt_RunEntHlaAdaptExec_PPortHlaEnvironmentData_DEPHlaEnvironmentData

#endif

  /* Rte_IWrite Api mapping  [Satisfies_rte sws 3744], [Satisfies_rte sws 1302], [Satisfies_rte sws 3746], [Satisfies_rte sws 3747].*/
  /* void Rte_IWrite_<re>_<p>_<d>([IN RTE_Instance], IN <type>) */
extern FUNC(void, RTE_CODE) Rte_IWrite_SWCHlaAdapt_RunEntHlaAdaptExec_PPortHlaObjectList_DEPHlaObjectList(P2VAR(RTE_HLA_t_ObjectList, AUTOMATIC, RTE_APPL_DATA) arg1);
extern FUNC( P2VAR(RTE_HLA_t_ObjectList, AUTOMATIC, RTE_APPL_DATA), RTE_CODE ) Rte_IWriteRef_SWCHlaAdapt_RunEntHlaAdaptExec_PPortHlaObjectList_DEPHlaObjectList();

#ifndef RTE_C
  #define Rte_IWrite_RunEntHlaAdaptExec_PPortHlaObjectList_DEPHlaObjectList \
    Rte_IWrite_SWCHlaAdapt_RunEntHlaAdaptExec_PPortHlaObjectList_DEPHlaObjectList

  #define Rte_IWriteRef_RunEntHlaAdaptExec_PPortHlaObjectList_DEPHlaObjectList \
    Rte_IWriteRef_SWCHlaAdapt_RunEntHlaAdaptExec_PPortHlaObjectList_DEPHlaObjectList

#endif

  /* Rte_IWrite Api mapping  [Satisfies_rte sws 3744], [Satisfies_rte sws 1302], [Satisfies_rte sws 3746], [Satisfies_rte sws 3747].*/
  /* void Rte_IWrite_<re>_<p>_<d>([IN RTE_Instance], IN <type>) */
extern FUNC(void, RTE_CODE) Rte_IWrite_SWCHlaAdapt_RunEntHlaAdaptExec_PPortHlaOutput_DEP_HlaOutput(P2VAR(RTE_HLA_t_HeadlightControl, AUTOMATIC, RTE_APPL_DATA) arg1);
extern FUNC( P2VAR(RTE_HLA_t_HeadlightControl, AUTOMATIC, RTE_APPL_DATA), RTE_CODE ) Rte_IWriteRef_SWCHlaAdapt_RunEntHlaAdaptExec_PPortHlaOutput_DEP_HlaOutput();

#ifndef RTE_C
  #define Rte_IWrite_RunEntHlaAdaptExec_PPortHlaOutput_DEP_HlaOutput \
    Rte_IWrite_SWCHlaAdapt_RunEntHlaAdaptExec_PPortHlaOutput_DEP_HlaOutput

  #define Rte_IWriteRef_RunEntHlaAdaptExec_PPortHlaOutput_DEP_HlaOutput \
    Rte_IWriteRef_SWCHlaAdapt_RunEntHlaAdaptExec_PPortHlaOutput_DEP_HlaOutput

#endif


/* Mode API mapping */
extern FUNC(Rte_ModeType_EcuM_Mode, RTE_CODE) Rte_Mode_SWCHlaAdapt_RPortModeHlaAdapt_currentMode( void );
#ifndef RTE_C
	#define Rte_Mode_RPortModeHlaAdapt_currentMode  \
		Rte_Mode_SWCHlaAdapt_RPortModeHlaAdapt_currentMode
#endif







#ifdef __cplusplus
	} /* extern "C" */
#endif /* __cplusplus */


#endif
