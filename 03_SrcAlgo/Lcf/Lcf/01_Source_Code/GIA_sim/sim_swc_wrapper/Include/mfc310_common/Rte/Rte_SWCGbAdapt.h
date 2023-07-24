/**************************************************************************
This file is generated automatically by the RTE generator
Filename:	Rte_SWCGbAdapt.h
CESSAR-CT Version: 3.1.1.11
RTE Version: 3.2.0.1.3.0
Generated on:	Thu Jun 14 15:20:19 CEST 2012
**************************************************************************/


#ifndef _RTE_SWCGbAdapt_H_
#define _RTE_SWCGbAdapt_H_



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
  typedef CONSTP2CONST(Rte_CDS_SWCGbAdapt, AUTOMATIC, RTE_CONST) Rte_Instance;
#endif /* RTE_C */

/* SWC:SWCGbAdapt Indirect API */
	/* The name of the instance handle is Rte_Inst_<c> [Satisfies_rte sws 3793]. */
extern CONST(Rte_CDS_SWCGbAdapt, RTE_CONST) Rte_Instance_SWCGbAdapt;

#ifndef RTE_C

	/*  Provided ports */



	/*  Required ports */


#endif



/* runnable entry points (symbol) */

extern void GB_v_AdaptExec (void); 


/* application error code */
#ifndef RTE_E_CSI_IcGetTemperature_ICA_e_ERR_NOTAVAILABLE
  #define RTE_E_CSI_IcGetTemperature_ICA_e_ERR_NOTAVAILABLE 40
#endif
#ifndef RTE_E_CSI_IcGetTemperature_ICA_e_ERR_OK
  #define RTE_E_CSI_IcGetTemperature_ICA_e_ERR_OK 0
#endif



/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/COMPONENTTYPES/IntBehGbAdapt/RunEntGbAdapt/SSCP_GbIcGetTemperature */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWCGbAdapt_RPortGbIcGetTemperature_OPIcGetTemperature( IN VAR(RTE_ICA_E_IMAGER_TYPE,AUTOMATIC) e_Imager, OUT P2VAR(float32,AUTOMATIC,RTE_APPL_DATA) pf32_Temp);
#ifndef RTE_C
  #define Rte_Call_RPortGbIcGetTemperature_OPIcGetTemperature Rte_Call_SWCGbAdapt_RPortGbIcGetTemperature_OPIcGetTemperature
#endif






#ifndef RTE_C
  #define Rte_InitValue_RPortGbDebugMode_DEPAlgoDebugMode (0)
#endif

#ifndef RTE_C
  #define Rte_InitValue_RPortGbRollTestMd_DEP_RollTestMd (0)
#endif


  /* Rte_Read Api mapping  [Satisfies_rte sws 1091].*/
  /* Std_ReturnType Rte_Read_<p>_<o>([IN Rte_Instance <instance>],OUT <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWCGbAdapt_RPortGbDebugMode_DEPAlgoDebugMode(OUT P2VAR(RTE_t_eAlgoDebugMode, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Read_RPortGbDebugMode_DEPAlgoDebugMode Rte_Read_SWCGbAdapt_RPortGbDebugMode_DEPAlgoDebugMode
#endif


  /* Rte_Read Api mapping  [Satisfies_rte sws 1091].*/
  /* Std_ReturnType Rte_Read_<p>_<o>([IN Rte_Instance <instance>],OUT <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWCGbAdapt_RPortGbHeadlightState_DEP_HeadlightState(OUT P2VAR(RTE_HLA_t_HeadlightState, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Read_RPortGbHeadlightState_DEP_HeadlightState Rte_Read_SWCGbAdapt_RPortGbHeadlightState_DEP_HeadlightState
#endif


  /* Rte_Read Api mapping  [Satisfies_rte sws 1091].*/
  /* Std_ReturnType Rte_Read_<p>_<o>([IN Rte_Instance <instance>],OUT <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWCGbAdapt_RPortGbIcImageCharOdd_DEPIcImageCharacteristics(OUT P2VAR(RTE_t_IC_S_ImageCharacteristics, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Read_RPortGbIcImageCharOdd_DEPIcImageCharacteristics Rte_Read_SWCGbAdapt_RPortGbIcImageCharOdd_DEPIcImageCharacteristics
#endif


  /* Rte_Read Api mapping  [Satisfies_rte sws 1091].*/
  /* Std_ReturnType Rte_Read_<p>_<o>([IN Rte_Instance <instance>],OUT <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWCGbAdapt_RPortGbVehicleState_DEPVehicleState(OUT P2VAR(RTE_HLA_t_VehicleState, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Read_RPortGbVehicleState_DEPVehicleState Rte_Read_SWCGbAdapt_RPortGbVehicleState_DEPVehicleState
#endif


  /* Rte_Write Api mapping  [Satisfies_rte sws 1071], [Satisfies_rte sws 1280].*/
  /* Std_ReturnType Rte_Write_<p>_<o>([IN Rte_Instance <instance>],IN <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWCGbAdapt_PPortGbAlgoversion_DEPAlgoVersion(IN P2VAR(RTE_t_AlgoVersion, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Write_PPortGbAlgoversion_DEPAlgoVersion Rte_Write_SWCGbAdapt_PPortGbAlgoversion_DEPAlgoVersion
#endif


  /* Rte_Write Api mapping  [Satisfies_rte sws 1071], [Satisfies_rte sws 1280].*/
  /* Std_ReturnType Rte_Write_<p>_<o>([IN Rte_Instance <instance>],IN <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
  extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWCGbAdapt_PPortGbAoiBlockage_DEPGbAoiBlockage  (IN P2VAR(RTE_GB_t_AOIBlockage, AUTOMATIC, RTE_APPL_DATA) arg1);
#else
  extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWCGbAdapt_PPortGbAoiBlockage_DEPGbAoiBlockage(IN P2VAR(RTE_GB_t_AOIBlockage_array, AUTOMATIC, RTE_APPL_DATA) arg1);
#endif
#ifndef RTE_C
  #define Rte_Write_PPortGbAoiBlockage_DEPGbAoiBlockage Rte_Write_SWCGbAdapt_PPortGbAoiBlockage_DEPGbAoiBlockage
#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(S_CamPos_CALIOutput, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCGbAdapt_RunEntGbAdapt_RPortGbCamPos_DEP_SensorAngles(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntGbAdapt_RPortGbCamPos_DEP_SensorAngles \
    Rte_IRead_SWCGbAdapt_RunEntGbAdapt_RPortGbCamPos_DEP_SensorAngles

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(RTE_t_HeatOutput, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCGbAdapt_RunEntGbAdapt_RPortGbHeatOutput_DEP_HeatStateOutput(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntGbAdapt_RPortGbHeatOutput_DEP_HeatStateOutput \
    Rte_IRead_SWCGbAdapt_RunEntGbAdapt_RPortGbHeatOutput_DEP_HeatStateOutput

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(RTE_HLA_t_EnvironmentData, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCGbAdapt_RunEntGbAdapt_RPortGbHlaEnvironmentData_DEPHlaEnvironmentData(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntGbAdapt_RPortGbHlaEnvironmentData_DEPHlaEnvironmentData \
    Rte_IRead_SWCGbAdapt_RunEntGbAdapt_RPortGbHlaEnvironmentData_DEPHlaEnvironmentData

#endif

#if (CFG_MFC_MONO_ENTRY == 1)

extern FUNC(P2VAR(RTE_HLA_t_CaliOnline, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) 
Rte_IRead_SWCGbAdapt_RunEntGbAdapt_RPortGbHlaCaliOnline_DEPHlaCaliOnline(void);
#ifndef RTE_C
  #define Rte_IRead_RunEntGbAdapt_RPortGbHlaCaliOnline_DEPHlaCaliOnline \
    Rte_IRead_SWCGbAdapt_RunEntGbAdapt_RPortGbHlaCaliOnline_DEPHlaCaliOnline
#endif

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(RTE_HLA_t_ObjectList, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCGbAdapt_RunEntGbAdapt_RPortGbHlaObjectList_DEPHlaObjectList(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntGbAdapt_RPortGbHlaObjectList_DEPHlaObjectList \
    Rte_IRead_SWCGbAdapt_RunEntGbAdapt_RPortGbHlaObjectList_DEPHlaObjectList

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(RTE_HLA_t_HeadlightControl, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCGbAdapt_RunEntGbAdapt_RPortGbHlaOutput_DEP_HlaOutput(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntGbAdapt_RPortGbHlaOutput_DEP_HlaOutput \
    Rte_IRead_SWCGbAdapt_RunEntGbAdapt_RPortGbHlaOutput_DEP_HlaOutput

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(S_MonoOnlineCalibration, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCGbAdapt_RunEntGbAdapt_RPortGbLDParameterInOut_DEPLDParameterInOut(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntGbAdapt_RPortGbLDParameterInOut_DEPLDParameterInOut \
    Rte_IRead_SWCGbAdapt_RunEntGbAdapt_RPortGbLDParameterInOut_DEPLDParameterInOut

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(VAR(RTE_b_RollTestMd, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCGbAdapt_RunEntGbAdapt_RPortGbRollTestMd_DEP_RollTestMd(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntGbAdapt_RPortGbRollTestMd_DEP_RollTestMd \
    Rte_IRead_SWCGbAdapt_RunEntGbAdapt_RPortGbRollTestMd_DEP_RollTestMd

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(RTE_t_VdyOutput, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCGbAdapt_RunEntGbAdapt_RPortGbVdyOutput_DEPVdyOutput(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntGbAdapt_RPortGbVdyOutput_DEPVdyOutput \
    Rte_IRead_SWCGbAdapt_RunEntGbAdapt_RPortGbVdyOutput_DEPVdyOutput

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(VehSig_t, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCGbAdapt_RunEntGbAdapt_RPortGbVehSig_DEPBswVehSig(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntGbAdapt_RPortGbVehSig_DEPBswVehSig \
    Rte_IRead_SWCGbAdapt_RunEntGbAdapt_RPortGbVehSig_DEPBswVehSig

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(RTE_t_WiperInfo, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCGbAdapt_RunEntGbAdapt_RPortGbWiperState_DEP_WiperSignals(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntGbAdapt_RPortGbWiperState_DEP_WiperSignals \
    Rte_IRead_SWCGbAdapt_RunEntGbAdapt_RPortGbWiperState_DEP_WiperSignals

#endif


  /* Rte_IWrite Api mapping  [Satisfies_rte sws 3744], [Satisfies_rte sws 1302], [Satisfies_rte sws 3746], [Satisfies_rte sws 3747].*/
  /* void Rte_IWrite_<re>_<p>_<d>([IN RTE_Instance], IN <type>) */
extern FUNC(void, RTE_CODE) Rte_IWrite_SWCGbAdapt_RunEntGbAdapt_PPortGbFctBlockage_DEPGbFctBlockage(P2VAR(RTE_GB_t_FctBlockageData, AUTOMATIC, RTE_APPL_DATA) arg1);
extern FUNC( P2VAR(RTE_GB_t_FctBlockageData, AUTOMATIC, RTE_APPL_DATA), RTE_CODE ) Rte_IWriteRef_SWCGbAdapt_RunEntGbAdapt_PPortGbFctBlockage_DEPGbFctBlockage();

#ifndef RTE_C
  #define Rte_IWrite_RunEntGbAdapt_PPortGbFctBlockage_DEPGbFctBlockage \
    Rte_IWrite_SWCGbAdapt_RunEntGbAdapt_PPortGbFctBlockage_DEPGbFctBlockage

  #define Rte_IWriteRef_RunEntGbAdapt_PPortGbFctBlockage_DEPGbFctBlockage \
    Rte_IWriteRef_SWCGbAdapt_RunEntGbAdapt_PPortGbFctBlockage_DEPGbFctBlockage

#endif








#ifdef __cplusplus
	} /* extern "C" */
#endif /* __cplusplus */


#endif
