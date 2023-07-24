/**************************************************************************
This file is generated automatically by the RTE generator
Filename:	Rte_SWCActl.h
CESSAR-CT Version: 3.1.1.11
RTE Version: 3.2.0.1.3.0
Generated on:	Thu Oct 18 14:08:55 CEST 2012
**************************************************************************/


#ifndef _RTE_SWCActl_H_
#define _RTE_SWCActl_H_



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
  typedef CONSTP2CONST(Rte_CDS_SWCActl, AUTOMATIC, RTE_CONST) Rte_Instance;
#endif /* RTE_C */

/* SWC:SWCActl Indirect API */
	/* The name of the instance handle is Rte_Inst_<c> [Satisfies_rte sws 3793]. */
extern CONST(Rte_CDS_SWCActl, RTE_CONST) Rte_Instance_SWCActl;

#ifndef RTE_C

	/*  Provided ports */



	/*  Required ports */


#endif



/* runnable entry points (symbol) */

extern void ACTL_v_Init (void); 
extern void ACTL_v_RteDummy (void); 
extern void CCC_v_MainFunction (void); 


/* application error code */



/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/COMPONENTTYPES/IntBehActl/RunEntActl/SSCP_ActlGetMCUSystemData */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWCActl_RPortActlGetMCUSystemData_OPNormGetMCUSystemData( OUT P2VAR(RTE_t_MCUSystemData,AUTOMATIC,RTE_APPL_DATA) ps_mcusysdata);
#ifndef RTE_C
  #define Rte_Call_RPortActlGetMCUSystemData_OPNormGetMCUSystemData Rte_Call_SWCActl_RPortActlGetMCUSystemData_OPNormGetMCUSystemData
#endif


/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/COMPONENTTYPES/IntBehActl/RunEntActl/SSCP_ActlGetMonoDSPSystemData */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWCActl_RPortActlGetMonoDSPSystemData_OPNormGetMonoDSPSystemData( OUT P2VAR(RTE_t_DSPMonoSystemData,AUTOMATIC,RTE_APPL_DATA) ps_monosysdata);
#ifndef RTE_C
  #define Rte_Call_RPortActlGetMonoDSPSystemData_OPNormGetMonoDSPSystemData Rte_Call_SWCActl_RPortActlGetMonoDSPSystemData_OPNormGetMonoDSPSystemData
#endif


/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/COMPONENTTYPES/IntBehActl/RunEntActl/SSCP_ActlGetStereoDSPSystemData */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWCActl_RPortActlGetStereoDSPSystemData_OPNormGetStereoDSPSystemData( OUT P2VAR(RTE_t_DSPStereoSystemData,AUTOMATIC,RTE_APPL_DATA) ps_stereosysdata);
#ifndef RTE_C
  #define Rte_Call_RPortActlGetStereoDSPSystemData_OPNormGetStereoDSPSystemData Rte_Call_SWCActl_RPortActlGetStereoDSPSystemData_OPNormGetStereoDSPSystemData
#endif


/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/COMPONENTTYPES/IntBehActl/RunEntActl/SSCP_ActlSetMCUSystemData */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWCActl_RPortActlSetMCUSystemData_OPNormSetMCUSystemData( IN VAR(uint8,AUTOMATIC) FillType);
#ifndef RTE_C
  #define Rte_Call_RPortActlSetMCUSystemData_OPNormSetMCUSystemData Rte_Call_SWCActl_RPortActlSetMCUSystemData_OPNormSetMCUSystemData
#endif


/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/COMPONENTTYPES/IntBehActl/RunEntActl/SSCP_ActlSetReqMonoDspState */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWCActl_RPortActlSetReqMonoDspState_OPNormSetReqMonoDspState( IN VAR(uint8,AUTOMATIC) NewState);
#ifndef RTE_C
  #define Rte_Call_RPortActlSetReqMonoDspState_OPNormSetReqMonoDspState Rte_Call_SWCActl_RPortActlSetReqMonoDspState_OPNormSetReqMonoDspState
#endif


/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/COMPONENTTYPES/IntBehActl/RunEntActl/SSCP_ActlSetReqStereoDspState */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWCActl_RPortActlSetReqStereoDspState_OPNormSetReqStereoDspState( IN VAR(uint8,AUTOMATIC) NewState);
#ifndef RTE_C
  #define Rte_Call_RPortActlSetReqStereoDspState_OPNormSetReqStereoDspState Rte_Call_SWCActl_RPortActlSetReqStereoDspState_OPNormSetReqStereoDspState
#endif






#ifndef RTE_C
  #define Rte_InitValue_RPortActlClearanceMeasurementHla_DEPClearanceMeasurement (0)
#endif

#ifndef RTE_C
  #define Rte_InitValue_RPortActlClearanceMeasurementVln_DEPClearanceMeasurement (0)
#endif

#ifndef RTE_C
  #define Rte_InitValue_RPortActlControlDTCStatus_DEPCurDemCtrlDTCSetting (0)
#endif

#ifndef RTE_C
  #define Rte_InitValue_RPortActlTsaProcessState_DEPTsaProcessState (0)
#endif

#ifndef RTE_C
  #define Rte_InitValue_RPortIgnState_DEPIgnState (0)
#endif


  /* Rte_Read Api mapping  [Satisfies_rte sws 1091].*/
  /* Std_ReturnType Rte_Read_<p>_<o>([IN Rte_Instance <instance>],OUT <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWCActl_RPortActlClearanceMeasurementHla_DEPClearanceMeasurement(OUT P2VAR(uint32, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Read_RPortActlClearanceMeasurementHla_DEPClearanceMeasurement Rte_Read_SWCActl_RPortActlClearanceMeasurementHla_DEPClearanceMeasurement
#endif


  /* Rte_Read Api mapping  [Satisfies_rte sws 1091].*/
  /* Std_ReturnType Rte_Read_<p>_<o>([IN Rte_Instance <instance>],OUT <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWCActl_RPortActlClearanceMeasurementVln_DEPClearanceMeasurement(OUT P2VAR(uint32, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Read_RPortActlClearanceMeasurementVln_DEPClearanceMeasurement Rte_Read_SWCActl_RPortActlClearanceMeasurementVln_DEPClearanceMeasurement
#endif


  /* Rte_Read Api mapping  [Satisfies_rte sws 1091].*/
  /* Std_ReturnType Rte_Read_<p>_<o>([IN Rte_Instance <instance>],OUT <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWCActl_RPortActlControlDTCStatus_DEPCurDemCtrlDTCSetting(OUT P2VAR(SwcDemSc_ScStatusType, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Read_RPortActlControlDTCStatus_DEPCurDemCtrlDTCSetting Rte_Read_SWCActl_RPortActlControlDTCStatus_DEPCurDemCtrlDTCSetting
#endif


  /* Rte_Read Api mapping  [Satisfies_rte sws 1091].*/
  /* Std_ReturnType Rte_Read_<p>_<o>([IN Rte_Instance <instance>],OUT <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWCActl_RPortActlTsaProcessState_DEPTsaProcessState(OUT P2VAR(RTE_eTSAIFOutputProcessState, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Read_RPortActlTsaProcessState_DEPTsaProcessState Rte_Read_SWCActl_RPortActlTsaProcessState_DEPTsaProcessState
#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(VAR(NORM_t_eIgnState, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCActl_RunEntActl_RPortIgnState_DEPIgnState(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntActl_RPortIgnState_DEPIgnState \
    Rte_IRead_SWCActl_RunEntActl_RPortIgnState_DEPIgnState

#endif


  /* Rte_IWrite Api mapping  [Satisfies_rte sws 3744], [Satisfies_rte sws 1302], [Satisfies_rte sws 3746], [Satisfies_rte sws 3747].*/
  /* void Rte_IWrite_<re>_<p>_<d>([IN RTE_Instance], IN <type>) */
extern FUNC(void, RTE_CODE) Rte_IWrite_SWCActl_RunEntActl_PPortActltoVdy_DEPVdyCtrlData(P2VAR(BSW_s_VDYCtrlData_t, AUTOMATIC, RTE_APPL_DATA) arg1);
extern FUNC( P2VAR(BSW_s_VDYCtrlData_t, AUTOMATIC, RTE_APPL_DATA), RTE_CODE ) Rte_IWriteRef_SWCActl_RunEntActl_PPortActltoVdy_DEPVdyCtrlData();

#ifndef RTE_C
  #define Rte_IWrite_RunEntActl_PPortActltoVdy_DEPVdyCtrlData \
    Rte_IWrite_SWCActl_RunEntActl_PPortActltoVdy_DEPVdyCtrlData

  #define Rte_IWriteRef_RunEntActl_PPortActltoVdy_DEPVdyCtrlData \
    Rte_IWriteRef_SWCActl_RunEntActl_PPortActltoVdy_DEPVdyCtrlData

#endif


/* Mode API mapping */
extern FUNC(Rte_ModeType_EcuM_Mode, RTE_CODE) Rte_Mode_SWCActl_RPModeActl_currentMode( void );
#ifndef RTE_C
	#define Rte_Mode_RPModeActl_currentMode  \
		Rte_Mode_SWCActl_RPModeActl_currentMode
#endif







#ifdef __cplusplus
	} /* extern "C" */
#endif /* __cplusplus */


#endif
