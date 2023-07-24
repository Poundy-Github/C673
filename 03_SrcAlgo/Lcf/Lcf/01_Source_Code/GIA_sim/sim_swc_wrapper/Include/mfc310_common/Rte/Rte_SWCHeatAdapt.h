/**************************************************************************
This file is generated automatically by the RTE generator
Filename:	Rte_SWCHeatAdapt.h
CESSAR-CT Version: 3.1.1.11
RTE Version: 3.2.0.1.3.0
Generated on:	Wed May 30 16:11:02 CEST 2012
**************************************************************************/


#ifndef _RTE_SWCHeatAdapt_H_
#define _RTE_SWCHeatAdapt_H_



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
  typedef CONSTP2CONST(Rte_CDS_SWCHeatAdapt, AUTOMATIC, RTE_CONST) Rte_Instance;
#endif /* RTE_C */

/* SWC:SWCHeatAdapt Indirect API */
	/* The name of the instance handle is Rte_Inst_<c> [Satisfies_rte sws 3793]. */
extern CONST(Rte_CDS_SWCHeatAdapt, RTE_CONST) Rte_Instance_SWCHeatAdapt;

#ifndef RTE_C

	/*  Provided ports */



	/*  Required ports */


#endif



/* runnable entry points (symbol) */

extern void HEAT_v_AdaptInit (void); 
extern void HEAT_v_AdaptExec (void); 


/* application error code */
#ifndef RTE_E_CSI_Timer64GetTimerValue_E_NOT_OK
  #define RTE_E_CSI_Timer64GetTimerValue_E_NOT_OK 1
#endif



/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/COMPONENTTYPES/IntBehHeatAdapt/RE_HeatExec/SSCP_HeatBswGetAdcData */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWCHeatAdapt_RPortHeatBswGetAdcData_OPGetAdcData( IN VAR(uint8,AUTOMATIC) AdcChannel, OUT P2VAR(float32,AUTOMATIC,RTE_APPL_DATA) CalcVal, OUT P2VAR(uint32,AUTOMATIC,RTE_APPL_DATA) Timestamp);
#ifndef RTE_C
  #define Rte_Call_RPortHeatBswGetAdcData_OPGetAdcData Rte_Call_SWCHeatAdapt_RPortHeatBswGetAdcData_OPGetAdcData
#endif


/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/COMPONENTTYPES/IntBehHeatAdapt/RE_HeatExec/SSCP_HeatTimer64GetTimerValue */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWCHeatAdapt_RPortHeatTimer64GetTimerValue_OPTimer64GetTimerValue( OUT P2VAR(uint64,AUTOMATIC,RTE_APPL_DATA) timerValue);
#ifndef RTE_C
  #define Rte_Call_RPortHeatTimer64GetTimerValue_OPTimer64GetTimerValue Rte_Call_SWCHeatAdapt_RPortHeatTimer64GetTimerValue_OPTimer64GetTimerValue
#endif






#ifndef RTE_C
  #define Rte_InitValue_RPortHeatAirTempOut_DEP_AirTempOutside (0)
#endif

#ifndef RTE_C
  #define Rte_InitValue_RPortHeatDefrostButton_DEPDefrostButton (0)
#endif

#ifndef RTE_C
  #define Rte_InitValue_RPortHeatDiagIO_DEP_HeatDiagIO (0)
#endif

#ifndef RTE_C
  #define Rte_InitValue_RPortHeatNightviewState_DEPNightviewState (0)
#endif

#ifndef RTE_C
  #define Rte_InitValue_RPortHeatRollTestMd_DEP_RollTestMd (0)
#endif

#ifndef RTE_C
  #define Rte_InitValue_RPortIgnState_DEPIgnState (0)
#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(RTE_t_AdcReads, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCHeatAdapt_RE_HeatExec_RPortHeatAdcData_DEPAdcData(void);

#ifndef RTE_C
  #define Rte_IRead_RE_HeatExec_RPortHeatAdcData_DEPAdcData \
    Rte_IRead_SWCHeatAdapt_RE_HeatExec_RPortHeatAdcData_DEPAdcData

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(VAR(RTE_f32_AirTempOutsd, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCHeatAdapt_RE_HeatExec_RPortHeatAirTempOut_DEP_AirTempOutside(void);

#ifndef RTE_C
  #define Rte_IRead_RE_HeatExec_RPortHeatAirTempOut_DEP_AirTempOutside \
    Rte_IRead_SWCHeatAdapt_RE_HeatExec_RPortHeatAirTempOut_DEP_AirTempOutside

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(VAR(uint8, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCHeatAdapt_RE_HeatExec_RPortHeatDefrostButton_DEPDefrostButton(void);

#ifndef RTE_C
  #define Rte_IRead_RE_HeatExec_RPortHeatDefrostButton_DEPDefrostButton \
    Rte_IRead_SWCHeatAdapt_RE_HeatExec_RPortHeatDefrostButton_DEPDefrostButton

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(VAR(RTE_t_DiagHeatRq, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCHeatAdapt_RE_HeatExec_RPortHeatDiagIO_DEP_HeatDiagIO(void);

#ifndef RTE_C
  #define Rte_IRead_RE_HeatExec_RPortHeatDiagIO_DEP_HeatDiagIO \
    Rte_IRead_SWCHeatAdapt_RE_HeatExec_RPortHeatDiagIO_DEP_HeatDiagIO

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(VAR(NORM_t_eIgnState, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCHeatAdapt_RE_HeatExec_RPortIgnState_DEPIgnState(void);

#ifndef RTE_C
  #define Rte_IRead_RE_HeatExec_RPortIgnState_DEPIgnState \
    Rte_IRead_SWCHeatAdapt_RE_HeatExec_RPortIgnState_DEPIgnState

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(VAR(uint8, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCHeatAdapt_RE_HeatExec_RPortHeatNightviewState_DEPNightviewState(void);

#ifndef RTE_C
  #define Rte_IRead_RE_HeatExec_RPortHeatNightviewState_DEPNightviewState \
    Rte_IRead_SWCHeatAdapt_RE_HeatExec_RPortHeatNightviewState_DEPNightviewState

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(VAR(RTE_b_RollTestMd, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCHeatAdapt_RE_HeatExec_RPortHeatRollTestMd_DEP_RollTestMd(void);

#ifndef RTE_C
  #define Rte_IRead_RE_HeatExec_RPortHeatRollTestMd_DEP_RollTestMd \
    Rte_IRead_SWCHeatAdapt_RE_HeatExec_RPortHeatRollTestMd_DEP_RollTestMd

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(RTE_t_VdyOutput, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCHeatAdapt_RE_HeatExec_RPortHeatVdyOutput_DEPVdyOutput(void);

#ifndef RTE_C
  #define Rte_IRead_RE_HeatExec_RPortHeatVdyOutput_DEPVdyOutput \
    Rte_IRead_SWCHeatAdapt_RE_HeatExec_RPortHeatVdyOutput_DEPVdyOutput

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(RTE_t_VehAddSignals, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCHeatAdapt_RE_HeatExec_RPortVehAddSignals_DEPVehAddSig(void);

#ifndef RTE_C
  #define Rte_IRead_RE_HeatExec_RPortVehAddSignals_DEPVehAddSig \
    Rte_IRead_SWCHeatAdapt_RE_HeatExec_RPortVehAddSignals_DEPVehAddSig

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(RTE_t_WiperInfo, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCHeatAdapt_RE_HeatExec_RPortHeatWiperSignals_DEP_WiperSignals(void);

#ifndef RTE_C
  #define Rte_IRead_RE_HeatExec_RPortHeatWiperSignals_DEP_WiperSignals \
    Rte_IRead_SWCHeatAdapt_RE_HeatExec_RPortHeatWiperSignals_DEP_WiperSignals

#endif


  /* Rte_IWrite Api mapping  [Satisfies_rte sws 3744], [Satisfies_rte sws 1302], [Satisfies_rte sws 3746], [Satisfies_rte sws 3747].*/
  /* void Rte_IWrite_<re>_<p>_<d>([IN RTE_Instance], IN <type>) */
extern FUNC(void, RTE_CODE) Rte_IWrite_SWCHeatAdapt_RE_HeatExec_PPortHeatState_DEP_HeatStateOutput(P2VAR(RTE_t_HeatOutput, AUTOMATIC, RTE_APPL_DATA) arg1);
extern FUNC( P2VAR(RTE_t_HeatOutput, AUTOMATIC, RTE_APPL_DATA), RTE_CODE ) Rte_IWriteRef_SWCHeatAdapt_RE_HeatExec_PPortHeatState_DEP_HeatStateOutput();

#ifndef RTE_C
  #define Rte_IWrite_RE_HeatExec_PPortHeatState_DEP_HeatStateOutput \
    Rte_IWrite_SWCHeatAdapt_RE_HeatExec_PPortHeatState_DEP_HeatStateOutput

  #define Rte_IWriteRef_RE_HeatExec_PPortHeatState_DEP_HeatStateOutput \
    Rte_IWriteRef_SWCHeatAdapt_RE_HeatExec_PPortHeatState_DEP_HeatStateOutput

#endif

  /* Rte_IWrite Api mapping  [Satisfies_rte sws 3744], [Satisfies_rte sws 1302], [Satisfies_rte sws 3746], [Satisfies_rte sws 3747].*/
  /* void Rte_IWrite_<re>_<p>_<d>([IN RTE_Instance], IN <type>) */
extern FUNC(void, RTE_CODE) Rte_IWrite_SWCHeatAdapt_RE_HeatExec_PPortHeatStatistics_DEP_HeatStatistics(P2VAR(RTE_t_HeatStatistics, AUTOMATIC, RTE_APPL_DATA) arg1);
extern FUNC( P2VAR(RTE_t_HeatStatistics, AUTOMATIC, RTE_APPL_DATA), RTE_CODE ) Rte_IWriteRef_SWCHeatAdapt_RE_HeatExec_PPortHeatStatistics_DEP_HeatStatistics();

#ifndef RTE_C
  #define Rte_IWrite_RE_HeatExec_PPortHeatStatistics_DEP_HeatStatistics \
    Rte_IWrite_SWCHeatAdapt_RE_HeatExec_PPortHeatStatistics_DEP_HeatStatistics

  #define Rte_IWriteRef_RE_HeatExec_PPortHeatStatistics_DEP_HeatStatistics \
    Rte_IWriteRef_SWCHeatAdapt_RE_HeatExec_PPortHeatStatistics_DEP_HeatStatistics

#endif


/* Mode API mapping */
extern FUNC(Rte_ModeType_EcuM_Mode, RTE_CODE) Rte_Mode_SWCHeatAdapt_RPortEcuMModeSwitch_currentMode( void );
#ifndef RTE_C
	#define Rte_Mode_RPortEcuMModeSwitch_currentMode  \
		Rte_Mode_SWCHeatAdapt_RPortEcuMModeSwitch_currentMode
#endif







#ifdef __cplusplus
	} /* extern "C" */
#endif /* __cplusplus */


#endif
