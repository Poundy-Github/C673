/**************************************************************************
This file is generated automatically by the RTE generator
Filename:	Rte_SWCFctAdapt.h
CESSAR-CT Version: 3.1.1.11
RTE Version: 3.2.0.1.3.0
Generated on:	Tue Jun 19 11:26:15 CEST 2012
**************************************************************************/


#ifndef _RTE_SWCFctAdapt_H_
#define _RTE_SWCFctAdapt_H_



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
  //typedef CONSTP2CONST(Rte_CDS_SWCFctAdapt, AUTOMATIC, RTE_CONST) Rte_Instance;
#endif /* RTE_C */

/* SWC:SWCFctAdapt Indirect API */
	/* The name of the instance handle is Rte_Inst_<c> [Satisfies_rte sws 3793]. */
extern CONST(Rte_CDS_SWCFctAdapt, RTE_CONST) Rte_Instance_SWCFctAdapt;

#ifndef RTE_C

	/*  Provided ports */



	/*  Required ports */


#endif



/* runnable entry points (symbol) */

extern void ALDW_v_AdaptInit (void); 
extern void ALDW_v_AdaptMain (void); 


/* application error code */
#ifndef RTE_E_CSI_Timer64GetTimerValue_E_NOT_OK
  #define RTE_E_CSI_Timer64GetTimerValue_E_NOT_OK 1
#endif



/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/COMPONENTTYPES/IntBehFctAdapt/RunEntFctAdapt/SSCP_FctTimer64GetTimerValue */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWCFctAdapt_RPortFctTimer64GetTimerValue_OPTimer64GetTimerValue( OUT P2VAR(uint64,AUTOMATIC,RTE_APPL_DATA) timerValue);
#ifndef RTE_C
  #define Rte_Call_RPortFctTimer64GetTimerValue_OPTimer64GetTimerValue Rte_Call_SWCFctAdapt_RPortFctTimer64GetTimerValue_OPTimer64GetTimerValue
#endif






#ifndef RTE_C
  #define Rte_InitValue_RPortFctAldwMode_DEP_FctAldwMode (0)
#endif

#ifndef RTE_C
  #define Rte_InitValue_RPortFctAldwOpMode_DEP_FctAldwOpMode (0)
#endif

#ifndef RTE_C
  #define Rte_InitValue_RPortFctAldwVibMotRq_DEPFctAldwVibMotRq (0)
#endif

#ifndef RTE_C
  #define Rte_InitValue_RPortFctAldwVibTm_DEPAldwVibTm (0)
#endif

#ifndef RTE_C
  #define Rte_InitValue_RPortFctDebugMode_DEPAlgoDebugMode (0)
#endif

#ifndef RTE_C
  #define Rte_InitValue_RPortIgnState_DEPIgnState (0)
#endif

#ifndef RTE_C
  #define Rte_InitValue_PPortFctTaskState_DEP_VehicleAlgoTaskState (0)
#endif


  /* Rte_Read Api mapping  [Satisfies_rte sws 1091].*/
  /* Std_ReturnType Rte_Read_<p>_<o>([IN Rte_Instance <instance>],OUT <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWCFctAdapt_RPortFctAldwLdpCfgBits_DEPAldwLdpCfgBits(OUT P2VAR(RTE_t_AldwLdpCfgBits, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Read_RPortFctAldwLdpCfgBits_DEPAldwLdpCfgBits Rte_Read_SWCFctAdapt_RPortFctAldwLdpCfgBits_DEPAldwLdpCfgBits
#endif


  /* Rte_Read Api mapping  [Satisfies_rte sws 1091].*/
  /* Std_ReturnType Rte_Read_<p>_<o>([IN Rte_Instance <instance>],OUT <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWCFctAdapt_RPortFctAldwVibMotRq_DEPFctAldwVibMotRq(OUT P2VAR(RTE_t_eALDWVibMotRq, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Read_RPortFctAldwVibMotRq_DEPFctAldwVibMotRq Rte_Read_SWCFctAdapt_RPortFctAldwVibMotRq_DEPFctAldwVibMotRq
#endif


  /* Rte_Read Api mapping  [Satisfies_rte sws 1091].*/
  /* Std_ReturnType Rte_Read_<p>_<o>([IN Rte_Instance <instance>],OUT <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWCFctAdapt_RPortFctAldwVibTm_DEPAldwVibTm(OUT P2VAR(uint16, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Read_RPortFctAldwVibTm_DEPAldwVibTm Rte_Read_SWCFctAdapt_RPortFctAldwVibTm_DEPAldwVibTm
#endif


  /* Rte_Read Api mapping  [Satisfies_rte sws 1091].*/
  /* Std_ReturnType Rte_Read_<p>_<o>([IN Rte_Instance <instance>],OUT <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWCFctAdapt_RPortFctDebugMode_DEPAlgoDebugMode(OUT P2VAR(RTE_t_eAlgoDebugMode, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Read_RPortFctDebugMode_DEPAlgoDebugMode Rte_Read_SWCFctAdapt_RPortFctDebugMode_DEPAlgoDebugMode
#endif


  /* Rte_Read Api mapping  [Satisfies_rte sws 1091].*/
  /* Std_ReturnType Rte_Read_<p>_<o>([IN Rte_Instance <instance>],OUT <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWCFctAdapt_RPortFctLdpWarnRq_DEPLdpWarnRq(OUT P2VAR(LDPWarnRq_t, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Read_RPortFctLdpWarnRq_DEPLdpWarnRq Rte_Read_SWCFctAdapt_RPortFctLdpWarnRq_DEPLdpWarnRq
#endif


  /* Rte_Read Api mapping  [Satisfies_rte sws 1091].*/
  /* Std_ReturnType Rte_Read_<p>_<o>([IN Rte_Instance <instance>],OUT <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWCFctAdapt_RPortFctVehSpdDisp_DEP_VehSpdDisp(OUT P2VAR(RTE_t_VehSpdDisp, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Read_RPortFctVehSpdDisp_DEP_VehSpdDisp Rte_Read_SWCFctAdapt_RPortFctVehSpdDisp_DEP_VehSpdDisp
#endif


  /* Rte_Write Api mapping  [Satisfies_rte sws 1071], [Satisfies_rte sws 1280].*/
  /* Std_ReturnType Rte_Write_<p>_<o>([IN Rte_Instance <instance>],IN <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWCFctAdapt_PPortFctAlgoVersion_DEPAlgoVersion(IN P2VAR(RTE_t_AlgoVersion, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Write_PPortFctAlgoVersion_DEPAlgoVersion Rte_Write_SWCFctAdapt_PPortFctAlgoVersion_DEPAlgoVersion
#endif


  /* Rte_Write Api mapping  [Satisfies_rte sws 1071], [Satisfies_rte sws 1280].*/
  /* Std_ReturnType Rte_Write_<p>_<o>([IN Rte_Instance <instance>],IN <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWCFctAdapt_PPortFctTaskState_DEP_VehicleAlgoTaskState(IN VAR(RTE_t_SYSMultiRunTaskState, AUTOMATIC) arg1);
#ifndef RTE_C
  #define Rte_Write_PPortFctTaskState_DEP_VehicleAlgoTaskState Rte_Write_SWCFctAdapt_PPortFctTaskState_DEP_VehicleAlgoTaskState
#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(lka_aldw_buttons_t, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCFctAdapt_RunEntFctAdapt_RPortFctAldwButtons_DEP_FctAldwButtons(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntFctAdapt_RPortFctAldwButtons_DEP_FctAldwButtons \
    Rte_IRead_SWCFctAdapt_RunEntFctAdapt_RPortFctAldwButtons_DEP_FctAldwButtons

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(VAR(eALDWMode_t, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCFctAdapt_RunEntFctAdapt_RPortFctAldwMode_DEP_FctAldwMode(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntFctAdapt_RPortFctAldwMode_DEP_FctAldwMode \
    Rte_IRead_SWCFctAdapt_RunEntFctAdapt_RPortFctAldwMode_DEP_FctAldwMode

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(VAR(eALDWOpMode_t, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCFctAdapt_RunEntFctAdapt_RPortFctAldwOpMode_DEP_FctAldwOpMode(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntFctAdapt_RPortFctAldwOpMode_DEP_FctAldwOpMode \
    Rte_IRead_SWCFctAdapt_RunEntFctAdapt_RPortFctAldwOpMode_DEP_FctAldwOpMode

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(RTE_GB_t_FctBlockageData, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCFctAdapt_RunEntFctAdapt_RPortFctGbFctBlockage_DEPGbFctBlockage(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntFctAdapt_RPortFctGbFctBlockage_DEPGbFctBlockage \
    Rte_IRead_SWCFctAdapt_RunEntFctAdapt_RPortFctGbFctBlockage_DEPGbFctBlockage

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(RTE_t_LDOutput, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCFctAdapt_RunEntFctAdapt_RPortFctLDOutput_DEP_LDLaneOutput(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntFctAdapt_RPortFctLDOutput_DEP_LDLaneOutput \
    Rte_IRead_SWCFctAdapt_RunEntFctAdapt_RPortFctLDOutput_DEP_LDLaneOutput

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(S_MonoOnlineCalibration, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCFctAdapt_RunEntFctAdapt_RPortFctLDParameterInOut_DEPLDParameterInOut(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntFctAdapt_RPortFctLDParameterInOut_DEPLDParameterInOut \
    Rte_IRead_SWCFctAdapt_RunEntFctAdapt_RPortFctLDParameterInOut_DEPLDParameterInOut

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(lka_driver_input_t, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCFctAdapt_RunEntFctAdapt_RPortFctLkaDriverInput_DEP_LkaDriverInput(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntFctAdapt_RPortFctLkaDriverInput_DEP_LkaDriverInput \
    Rte_IRead_SWCFctAdapt_RunEntFctAdapt_RPortFctLkaDriverInput_DEP_LkaDriverInput

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(RTE_t_SLEOutput, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCFctAdapt_RunEntFctAdapt_RPortFctSleOutput_DEPSleOutput(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntFctAdapt_RPortFctSleOutput_DEPSleOutput \
    Rte_IRead_SWCFctAdapt_RunEntFctAdapt_RPortFctSleOutput_DEPSleOutput

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(RTE_t_VCVehicleData, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCFctAdapt_RunEntFctAdapt_RPortFctVcVehicleData_DEP_VCVehicleData(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntFctAdapt_RPortFctVcVehicleData_DEP_VCVehicleData \
    Rte_IRead_SWCFctAdapt_RunEntFctAdapt_RPortFctVcVehicleData_DEP_VCVehicleData

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(RTE_t_VdyOutput, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCFctAdapt_RunEntFctAdapt_RPortFctVdyOutput_DEPVdyOutput(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntFctAdapt_RPortFctVdyOutput_DEPVdyOutput \
    Rte_IRead_SWCFctAdapt_RunEntFctAdapt_RPortFctVdyOutput_DEPVdyOutput

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(RTE_t_VehAddSignals, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCFctAdapt_RunEntFctAdapt_RPortFctVehAddSig_DEPVehAddSig(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntFctAdapt_RPortFctVehAddSig_DEPVehAddSig \
    Rte_IRead_SWCFctAdapt_RunEntFctAdapt_RPortFctVehAddSig_DEPVehAddSig

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(VehSig_t, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCFctAdapt_RunEntFctAdapt_RPortFctVehSig_DEPBswVehSig(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntFctAdapt_RPortFctVehSig_DEPBswVehSig \
    Rte_IRead_SWCFctAdapt_RunEntFctAdapt_RPortFctVehSig_DEPBswVehSig

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(VAR(NORM_t_eIgnState, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCFctAdapt_RunEntFctAdapt_RPortIgnState_DEPIgnState(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntFctAdapt_RPortIgnState_DEPIgnState \
    Rte_IRead_SWCFctAdapt_RunEntFctAdapt_RPortIgnState_DEPIgnState

#endif


  /* Rte_IWrite Api mapping  [Satisfies_rte sws 3744], [Satisfies_rte sws 1302], [Satisfies_rte sws 3746], [Satisfies_rte sws 3747].*/
  /* void Rte_IWrite_<re>_<p>_<d>([IN RTE_Instance], IN <type>) */
extern FUNC(void, RTE_CODE) Rte_IWrite_SWCFctAdapt_RunEntFctAdapt_PPortFctLkaOutputCustom_DEP_FctLkaOutputCustom(P2VAR(LKAOutputCustom_t, AUTOMATIC, RTE_APPL_DATA) arg1);
extern FUNC( P2VAR(LKAOutputCustom_t, AUTOMATIC, RTE_APPL_DATA), RTE_CODE ) Rte_IWriteRef_SWCFctAdapt_RunEntFctAdapt_PPortFctLkaOutputCustom_DEP_FctLkaOutputCustom();

#ifndef RTE_C
  #define Rte_IWrite_RunEntFctAdapt_PPortFctLkaOutputCustom_DEP_FctLkaOutputCustom \
    Rte_IWrite_SWCFctAdapt_RunEntFctAdapt_PPortFctLkaOutputCustom_DEP_FctLkaOutputCustom

  #define Rte_IWriteRef_RunEntFctAdapt_PPortFctLkaOutputCustom_DEP_FctLkaOutputCustom \
    Rte_IWriteRef_SWCFctAdapt_RunEntFctAdapt_PPortFctLkaOutputCustom_DEP_FctLkaOutputCustom

#endif


/* Mode API mapping */
extern FUNC(Rte_ModeType_EcuM_Mode, RTE_CODE) Rte_Mode_SWCFctAdapt_RPModeFct_currentMode( void );
#ifndef RTE_C
	#define Rte_Mode_RPModeFct_currentMode  \
		Rte_Mode_SWCFctAdapt_RPModeFct_currentMode
#endif







#ifdef __cplusplus
	} /* extern "C" */
#endif /* __cplusplus */


#endif
