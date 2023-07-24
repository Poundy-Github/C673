/**************************************************************************
This file is generated automatically by the RTE generator
Filename:	Rte_SWCImageCtrl.h
CESSAR-CT Version: 3.1.1.11
RTE Version: 3.2.0.1.3.0
Generated on:	Thu Jun 14 15:20:19 CEST 2012
**************************************************************************/


#ifndef _RTE_SWCImageCtrl_H_
#define _RTE_SWCImageCtrl_H_



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
  typedef CONSTP2CONST(Rte_CDS_SWCImageCtrl, AUTOMATIC, RTE_CONST) Rte_Instance;
#endif /* RTE_C */

/* SWC:SWCImageCtrl Indirect API */
	/* The name of the instance handle is Rte_Inst_<c> [Satisfies_rte sws 3793]. */
extern CONST(Rte_CDS_SWCImageCtrl, RTE_CONST) Rte_Instance_SWCImageCtrl;

#ifndef RTE_C

	/*  Provided ports */



	/*  Required ports */


#endif



/* runnable entry points (symbol) */

extern void IC_v_Init (void); 
extern void ROILineTaskFunc (void); 
/* runnable entry points (symbol) for servers */
//extern FUNC(Std_ReturnType , RTE_APPL_CODE)ICA_e_GetSensorIDs( IN VAR(RTE_ICA_E_IMAGER_TYPE,AUTOMATIC) e_Imager, OUT P2VAR(RTE_t_ICA_S_SensorIDs,AUTOMATIC,RTE_APPL_DATA) ps_SensIdOut );
//extern FUNC(Std_ReturnType , RTE_APPL_CODE)ICA_e_GetTemperature( IN VAR(RTE_ICA_E_IMAGER_TYPE,AUTOMATIC) e_Imager, OUT P2VAR(float32,AUTOMATIC,RTE_APPL_DATA) pf32_Temp );



/* application error code */
#ifndef RTE_E_CSI_Timer64AdjustTimerValue_E_NOT_OK
  #define RTE_E_CSI_Timer64AdjustTimerValue_E_NOT_OK 1
#endif
#ifndef RTE_E_CSI_Timer64GetTimerValue_E_NOT_OK
  #define RTE_E_CSI_Timer64GetTimerValue_E_NOT_OK 1
#endif
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



/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/COMPONENTTYPES/IntBehImageCtrl/RunEntImageCtrl/SSCP_IcHlaSetImageChar */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWCImageCtrl_RPortIcHlaSetImageChar_OPHlaSetImageChar( INOUT P2VAR(RTE_t_IC_S_ImageCharacteristics,AUTOMATIC,RTE_APPL_DATA) ImageChar);
#ifndef RTE_C
  #define Rte_Call_RPortIcHlaSetImageChar_OPHlaSetImageChar Rte_Call_SWCImageCtrl_RPortIcHlaSetImageChar_OPHlaSetImageChar
#endif


/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/COMPONENTTYPES/IntBehImageCtrl/RunEntImageCtrl/SSCP_IcTimer64AdjustTimerValue */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWCImageCtrl_RPortIcTimer64AdjustTimerValue_OPTimer64AdjustTimerValue( IN VAR(sint64,AUTOMATIC) offset);
#ifndef RTE_C
  #define Rte_Call_RPortIcTimer64AdjustTimerValue_OPTimer64AdjustTimerValue Rte_Call_SWCImageCtrl_RPortIcTimer64AdjustTimerValue_OPTimer64AdjustTimerValue
#endif


/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/COMPONENTTYPES/IntBehImageCtrl/RunEntImageCtrl/SSCP_IcTimer64GetTimerValue */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWCImageCtrl_RPortIcTimer64GetTimerValue_OPTimer64GetTimerValue( OUT P2VAR(uint64,AUTOMATIC,RTE_APPL_DATA) timerValue);
#ifndef RTE_C
  #define Rte_Call_RPortIcTimer64GetTimerValue_OPTimer64GetTimerValue Rte_Call_SWCImageCtrl_RPortIcTimer64GetTimerValue_OPTimer64GetTimerValue
#endif







  /* Rte_Write Api mapping  [Satisfies_rte sws 1071], [Satisfies_rte sws 1280].*/
  /* Std_ReturnType Rte_Write_<p>_<o>([IN Rte_Instance <instance>],IN <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWCImageCtrl_PPortIcImageCharEven_DEPIcImageCharacteristics(IN P2VAR(RTE_t_IC_S_ImageCharacteristics, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Write_PPortIcImageCharEven_DEPIcImageCharacteristics Rte_Write_SWCImageCtrl_PPortIcImageCharEven_DEPIcImageCharacteristics
#endif


  /* Rte_Write Api mapping  [Satisfies_rte sws 1071], [Satisfies_rte sws 1280].*/
  /* Std_ReturnType Rte_Write_<p>_<o>([IN Rte_Instance <instance>],IN <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWCImageCtrl_PPortIcImageCharOdd_DEPIcImageCharacteristics(IN P2VAR(RTE_t_IC_S_ImageCharacteristics, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Write_PPortIcImageCharOdd_DEPIcImageCharacteristics Rte_Write_SWCImageCtrl_PPortIcImageCharOdd_DEPIcImageCharacteristics
#endif


  /* Rte_Write Api mapping  [Satisfies_rte sws 1071], [Satisfies_rte sws 1280].*/
  /* Std_ReturnType Rte_Write_<p>_<o>([IN Rte_Instance <instance>],IN <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWCImageCtrl_PPortIcStatResultsEven_DEPIcStatisticalResults(IN P2VAR(RTE_t_IC_S_StatisticalResults, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Write_PPortIcStatResultsEven_DEPIcStatisticalResults Rte_Write_SWCImageCtrl_PPortIcStatResultsEven_DEPIcStatisticalResults
#endif


  /* Rte_Write Api mapping  [Satisfies_rte sws 1071], [Satisfies_rte sws 1280].*/
  /* Std_ReturnType Rte_Write_<p>_<o>([IN Rte_Instance <instance>],IN <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWCImageCtrl_PPortIcStatResultsOdd_DEPIcStatisticalResults(IN P2VAR(RTE_t_IC_S_StatisticalResults, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Write_PPortIcStatResultsOdd_DEPIcStatisticalResults Rte_Write_SWCImageCtrl_PPortIcStatResultsOdd_DEPIcStatisticalResults
#endif


  /* Rte_Write Api mapping  [Satisfies_rte sws 1071], [Satisfies_rte sws 1280].*/
  /* Std_ReturnType Rte_Write_<p>_<o>([IN Rte_Instance <instance>],IN <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWCImageCtrl_PPortIcVersion_DEPAlgoVersion(IN P2VAR(RTE_t_AlgoVersion, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Write_PPortIcVersion_DEPAlgoVersion Rte_Write_SWCImageCtrl_PPortIcVersion_DEPAlgoVersion
#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(S_CamPos_CALIOutput, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCImageCtrl_RunEntImageCtrl_RPortIcCamPos_DEP_SensorAngles(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntImageCtrl_RPortIcCamPos_DEP_SensorAngles \
    Rte_IRead_SWCImageCtrl_RunEntImageCtrl_RPortIcCamPos_DEP_SensorAngles

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(RTE_t_ImageRegisterResponse, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCImageCtrl_RunEntImageCtrl_RPortIcImageRegisterResponse_DEPImageRegisterResponse(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntImageCtrl_RPortIcImageRegisterResponse_DEPImageRegisterResponse \
    Rte_IRead_SWCImageCtrl_RunEntImageCtrl_RPortIcImageRegisterResponse_DEPImageRegisterResponse

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(RTE_t_LDOutput, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCImageCtrl_RunEntImageCtrl_RPortIcLDOutput_DEP_LDLaneOutput(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntImageCtrl_RPortIcLDOutput_DEP_LDLaneOutput \
    Rte_IRead_SWCImageCtrl_RunEntImageCtrl_RPortIcLDOutput_DEP_LDLaneOutput

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(S_MonoOnlineCalibration, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCImageCtrl_RunEntImageCtrl_RPortIcLDParameterInOut_DEPLDParameterInOut(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntImageCtrl_RPortIcLDParameterInOut_DEPLDParameterInOut \
    Rte_IRead_SWCImageCtrl_RunEntImageCtrl_RPortIcLDParameterInOut_DEPLDParameterInOut

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(RTE_t_SACOutput, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCImageCtrl_RunEntImageCtrl_RPortIcSacOutput_DEPSacOutput(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntImageCtrl_RPortIcSacOutput_DEPSacOutput \
    Rte_IRead_SWCImageCtrl_RunEntImageCtrl_RPortIcSacOutput_DEPSacOutput

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(RTE_t_VdyOutput, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCImageCtrl_RunEntImageCtrl_RPortIcVdyOutput_DEPVdyOutput(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntImageCtrl_RPortIcVdyOutput_DEPVdyOutput \
    Rte_IRead_SWCImageCtrl_RunEntImageCtrl_RPortIcVdyOutput_DEPVdyOutput

#endif


  /* Rte_IWrite Api mapping  [Satisfies_rte sws 3744], [Satisfies_rte sws 1302], [Satisfies_rte sws 3746], [Satisfies_rte sws 3747].*/
  /* void Rte_IWrite_<re>_<p>_<d>([IN RTE_Instance], IN <type>) */
extern FUNC(void, RTE_CODE) Rte_IWrite_SWCImageCtrl_RunEntImageCtrl_PPortIcImageRegisterRequest_DEPImageRegisterRequest(P2VAR(RTE_t_ImageRegisterRequest, AUTOMATIC, RTE_APPL_DATA) arg1);
extern FUNC( P2VAR(RTE_t_ImageRegisterRequest, AUTOMATIC, RTE_APPL_DATA), RTE_CODE ) Rte_IWriteRef_SWCImageCtrl_RunEntImageCtrl_PPortIcImageRegisterRequest_DEPImageRegisterRequest();

#ifndef RTE_C
  #define Rte_IWrite_RunEntImageCtrl_PPortIcImageRegisterRequest_DEPImageRegisterRequest \
    Rte_IWrite_SWCImageCtrl_RunEntImageCtrl_PPortIcImageRegisterRequest_DEPImageRegisterRequest

  #define Rte_IWriteRef_RunEntImageCtrl_PPortIcImageRegisterRequest_DEPImageRegisterRequest \
    Rte_IWriteRef_SWCImageCtrl_RunEntImageCtrl_PPortIcImageRegisterRequest_DEPImageRegisterRequest

#endif


/* Mode API mapping */
extern FUNC(Rte_ModeType_EcuM_Mode, RTE_CODE) Rte_Mode_SWCImageCtrl_RPortModeImageCtrl_currentMode( void );
#ifndef RTE_C
	#define Rte_Mode_RPortModeImageCtrl_currentMode  \
		Rte_Mode_SWCImageCtrl_RPortModeImageCtrl_currentMode
#endif







#ifdef __cplusplus
	} /* extern "C" */
#endif /* __cplusplus */


#endif
