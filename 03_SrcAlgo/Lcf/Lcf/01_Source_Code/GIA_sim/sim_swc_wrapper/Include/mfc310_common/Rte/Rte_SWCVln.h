/**************************************************************************
This file is generated automatically by the RTE generator
Filename:	Rte_SWCVln.h
CESSAR-CT Version: 3.1.1.11
RTE Version: 3.2.0.1.3.0
Generated on:	Thu Jun 14 15:20:19 CEST 2012
**************************************************************************/


#ifndef _RTE_SWCVln_H_
#define _RTE_SWCVln_H_



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
  typedef CONSTP2CONST(Rte_CDS_SWCVln, AUTOMATIC, RTE_CONST) Rte_Instance;
#endif /* RTE_C */

/* SWC:SWCVln Indirect API */
	/* The name of the instance handle is Rte_Inst_<c> [Satisfies_rte sws 3793]. */
extern CONST(Rte_CDS_SWCVln, RTE_CONST) Rte_Instance_SWCVln;

#ifndef RTE_C

	/*  Provided ports */



	/*  Required ports */


#endif



/* runnable entry points (symbol) */

extern void VLN_v_AdaptInit (void); 
extern void VLN_v_Main (void); 


/* application error code */
#ifndef RTE_E_CSI_Timer64GetTimerValue_E_NOT_OK
  #define RTE_E_CSI_Timer64GetTimerValue_E_NOT_OK 1
#endif



/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/COMPONENTTYPES/IntBehVln/RunEntVln/SSCP_VlnTimer64GetTimerValue */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWCVln_RPortVlnTimer64GetTimerValue_OPTimer64GetTimerValue( OUT P2VAR(uint64,AUTOMATIC,RTE_APPL_DATA) timerValue);
#ifndef RTE_C
  #define Rte_Call_RPortVlnTimer64GetTimerValue_OPTimer64GetTimerValue Rte_Call_SWCVln_RPortVlnTimer64GetTimerValue_OPTimer64GetTimerValue
#endif






#ifndef RTE_C
  #define Rte_InitValue_RPortVlnDebugMode_DEPAlgoDebugMode (0)
#endif

#ifndef RTE_C
  #define Rte_InitValue_PPortVlnClearanceMeasurement_DEPClearanceMeasurement (0)
#endif


  /* Rte_Read Api mapping  [Satisfies_rte sws 1091].*/
  /* Std_ReturnType Rte_Read_<p>_<o>([IN Rte_Instance <instance>],OUT <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWCVln_RPortVlnDebugMode_DEPAlgoDebugMode(OUT P2VAR(RTE_t_eAlgoDebugMode, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Read_RPortVlnDebugMode_DEPAlgoDebugMode Rte_Read_SWCVln_RPortVlnDebugMode_DEPAlgoDebugMode
#endif


  /* Rte_Write Api mapping  [Satisfies_rte sws 1071], [Satisfies_rte sws 1280].*/
  /* Std_ReturnType Rte_Write_<p>_<o>([IN Rte_Instance <instance>],IN <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWCVln_PPortVlnAlgoVersion_DEPAlgoVersion(IN P2VAR(RTE_t_AlgoVersion, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Write_PPortVlnAlgoVersion_DEPAlgoVersion Rte_Write_SWCVln_PPortVlnAlgoVersion_DEPAlgoVersion
#endif


  /* Rte_Write Api mapping  [Satisfies_rte sws 1071], [Satisfies_rte sws 1280].*/
  /* Std_ReturnType Rte_Write_<p>_<o>([IN Rte_Instance <instance>],IN <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWCVln_PPortVlnClearanceMeasurement_DEPClearanceMeasurement(IN VAR(uint32, AUTOMATIC) arg1);
#ifndef RTE_C
  #define Rte_Write_PPortVlnClearanceMeasurement_DEPClearanceMeasurement Rte_Write_SWCVln_PPortVlnClearanceMeasurement_DEPClearanceMeasurement
#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(RTE_t_LDOutput, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCVln_RunEntVln_RPortVlnLDOutput_DEP_LDLaneOutput(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntVln_RPortVlnLDOutput_DEP_LDLaneOutput \
    Rte_IRead_SWCVln_RunEntVln_RPortVlnLDOutput_DEP_LDLaneOutput

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(S_MonoOnlineCalibration, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCVln_RunEntVln_RPortVlnLDParameterInOut_DEPLDParameterInOut(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntVln_RPortVlnLDParameterInOut_DEPLDParameterInOut \
    Rte_IRead_SWCVln_RunEntVln_RPortVlnLDParameterInOut_DEPLDParameterInOut

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(RTE_t_LDOutput, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCVln_RunEntVln_RPortVlnLROutput_DEP_LDLaneOutput(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntVln_RPortVlnLROutput_DEP_LDLaneOutput \
    Rte_IRead_SWCVln_RunEntVln_RPortVlnLROutput_DEP_LDLaneOutput

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(S_MonoOnlineCalibration, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCVln_RunEntVln_RPortVlnLRParameterInOut_DEPLDParameterInOut(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntVln_RPortVlnLRParameterInOut_DEPLDParameterInOut \
    Rte_IRead_SWCVln_RunEntVln_RPortVlnLRParameterInOut_DEPLDParameterInOut

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(LKAOutputCustom_t, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCVln_RunEntVln_RPortVlnLkaOutputCustom_DEP_FctLkaOutputCustom(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntVln_RPortVlnLkaOutputCustom_DEP_FctLkaOutputCustom \
    Rte_IRead_SWCVln_RunEntVln_RPortVlnLkaOutputCustom_DEP_FctLkaOutputCustom

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(RTE_t_VdyOutput, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCVln_RunEntVln_RPortVlnVdyOutput_DEPVdyOutput(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntVln_RPortVlnVdyOutput_DEPVdyOutput \
    Rte_IRead_SWCVln_RunEntVln_RPortVlnVdyOutput_DEPVdyOutput

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(RTE_GB_t_FctBlockageData, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCVln_RunEntVln_RPortVlnGbFctBlockage_DEPGbFctBlockage(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntVln_RPortVlnGbFctBlockage_DEPGbFctBlockage \
    Rte_IRead_SWCVln_RunEntVln_RPortVlnGbFctBlockage_DEPGbFctBlockage

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(RTE_t_SLEOutput, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCVln_RunEntVln_RPortVlnSleOutput_DEPSleOutput(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntVln_RPortVlnSleOutput_DEPSleOutput \
    Rte_IRead_SWCVln_RunEntVln_RPortVlnSleOutput_DEPSleOutput

#endif


  /* Rte_IWrite Api mapping  [Satisfies_rte sws 3744], [Satisfies_rte sws 1302], [Satisfies_rte sws 3746], [Satisfies_rte sws 3747].*/
  /* void Rte_IWrite_<re>_<p>_<d>([IN RTE_Instance], IN <type>) */
extern FUNC(void, RTE_CODE) Rte_IWrite_SWCVln_RunEntVln_PPortVlnLCOutput_DEPLCOutput(P2VAR(RTE_t_LCOutput, AUTOMATIC, RTE_APPL_DATA) arg1);
extern FUNC( P2VAR(RTE_t_LCOutput, AUTOMATIC, RTE_APPL_DATA), RTE_CODE ) Rte_IWriteRef_SWCVln_RunEntVln_PPortVlnLCOutput_DEPLCOutput();

#ifndef RTE_C
  #define Rte_IWrite_RunEntVln_PPortVlnLCOutput_DEPLCOutput \
    Rte_IWrite_SWCVln_RunEntVln_PPortVlnLCOutput_DEPLCOutput

  #define Rte_IWriteRef_RunEntVln_PPortVlnLCOutput_DEPLCOutput \
    Rte_IWriteRef_SWCVln_RunEntVln_PPortVlnLCOutput_DEPLCOutput

#endif


/* Mode API mapping */
extern FUNC(Rte_ModeType_EcuM_Mode, RTE_CODE) Rte_Mode_SWCVln_RPortModeVln_currentMode( void );
#ifndef RTE_C
	#define Rte_Mode_RPortModeVln_currentMode  \
		Rte_Mode_SWCVln_RPortModeVln_currentMode
#endif







#ifdef __cplusplus
	} /* extern "C" */
#endif /* __cplusplus */


#endif
