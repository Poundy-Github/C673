/**************************************************************************
This file is generated automatically by the RTE generator
Filename:	Rte_SWCBsw.h
CESSAR-CT Version: 3.1.1.11
RTE Version: 3.2.0.1.3.0
Generated on:	Fri Mar 02 11:11:42 CET 2012
**************************************************************************/


#ifndef _RTE_SWCBsw_H_
#define _RTE_SWCBsw_H_



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
  typedef CONSTP2CONST(Rte_CDS_SWCBsw, AUTOMATIC, RTE_CONST) Rte_Instance;
#endif /* RTE_C */

/* SWC:SWCBsw Indirect API */
	/* The name of the instance handle is Rte_Inst_<c> [Satisfies_rte sws 3793]. */
extern CONST(Rte_CDS_SWCBsw, RTE_CONST) Rte_Instance_SWCBsw;

#ifndef RTE_C

	/*  Provided ports */



	/*  Required ports */


#endif



/* runnable entry points (symbol) */

extern void RE_BswInit (void); 
extern void SchM_v_BswCyclicMain (void); 
/* runnable entry points (symbol) for servers */
extern FUNC(void, RTE_APPL_CODE) IoHwAb_v_GetPhysicalValue( IN VAR(uint8,AUTOMATIC) AdcChannel, OUT P2VAR(float32,AUTOMATIC,RTE_APPL_DATA) CalcVal, OUT P2VAR(uint32,AUTOMATIC,RTE_APPL_DATA) Timestamp);
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
  extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_LearnValueHandler( IN VAR(BlockIdType pdav_0, AUTOMATIC), IN P2CONST(UInt8,AUTOMATIC,RTE_APPL_DATA) DstPtr);
#else
  extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_LearnValueHandler( IN VAR(BlockIdType pdav_0, AUTOMATIC), IN P2CONST(DstPtrType,AUTOMATIC,RTE_APPL_DATA) DstPtr);
#endif



/* application error code */
#ifndef RTE_E_NvMService_E_NOK
  #define RTE_E_NvMService_E_NOK 1
#endif
#ifndef RTE_E_NvMService_E_OK
  #define RTE_E_NvMService_E_OK 0
#endif



/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/COMPONENTTYPES/IntBehBsw/RunEntBsw/SSCP_NormSetSignalFrontWhlAngel */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWCBsw_RPortBswNormSetSignal_OPNormSetSignalFrontWhlAngel( IN VAR(uint8,AUTOMATIC) FrTick);
#ifndef RTE_C
  #define Rte_Call_RPortBswNormSetSignal_OPNormSetSignalFrontWhlAngel Rte_Call_SWCBsw_RPortBswNormSetSignal_OPNormSetSignalFrontWhlAngel
#endif


/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/COMPONENTTYPES/IntBehBsw/RunEntBsw/SSCP_NormSetSignalPreviewAccel */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWCBsw_RPortBswNormSetSignal_OPNormSetSignalPreviewAccel( IN VAR(uint8,AUTOMATIC) FrTick);
#ifndef RTE_C
  #define Rte_Call_RPortBswNormSetSignal_OPNormSetSignalPreviewAccel Rte_Call_SWCBsw_RPortBswNormSetSignal_OPNormSetSignalPreviewAccel
#endif


/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/COMPONENTTYPES/IntBehBsw/RunEntBsw/SSCP_NormSetSignalStWhlAngel */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWCBsw_RPortBswNormSetSignal_OPNormSetSignalStWhlAngel( IN VAR(uint8,AUTOMATIC) FrTick);
#ifndef RTE_C
  #define Rte_Call_RPortBswNormSetSignal_OPNormSetSignalStWhlAngel Rte_Call_SWCBsw_RPortBswNormSetSignal_OPNormSetSignalStWhlAngel
#endif


/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/COMPONENTTYPES/IntBehBsw/RunEntBsw/SSCP_NormSetSignalTachoSpd */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWCBsw_RPortBswNormSetSignal_OPNormSetSignalTachoSpd( IN VAR(uint8,AUTOMATIC) FrTick);
#ifndef RTE_C
  #define Rte_Call_RPortBswNormSetSignal_OPNormSetSignalTachoSpd Rte_Call_SWCBsw_RPortBswNormSetSignal_OPNormSetSignalTachoSpd
#endif


/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/COMPONENTTYPES/IntBehBsw/RunEntBsw/SSCP_NormSetSignalVehDynAccel */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWCBsw_RPortBswNormSetSignal_OPNormSetSignalVehDynAccel( IN VAR(uint8,AUTOMATIC) FrTick);
#ifndef RTE_C
  #define Rte_Call_RPortBswNormSetSignal_OPNormSetSignalVehDynAccel Rte_Call_SWCBsw_RPortBswNormSetSignal_OPNormSetSignalVehDynAccel
#endif


/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/COMPONENTTYPES/IntBehBsw/RunEntBsw/SSCP_NormSetSignalWheelLT */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWCBsw_RPortBswNormSetSignal_OPNormSetSignalWheelLT( IN VAR(uint8,AUTOMATIC) FrTick);
#ifndef RTE_C
  #define Rte_Call_RPortBswNormSetSignal_OPNormSetSignalWheelLT Rte_Call_SWCBsw_RPortBswNormSetSignal_OPNormSetSignalWheelLT
#endif


/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/COMPONENTTYPES/IntBehBsw/RunEntBsw/SSCP_NormSetSignalWheelRT */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWCBsw_RPortBswNormSetSignal_OPNormSetSignalWheelRT( IN VAR(uint8,AUTOMATIC) FrTick);
#ifndef RTE_C
  #define Rte_Call_RPortBswNormSetSignal_OPNormSetSignalWheelRT Rte_Call_SWCBsw_RPortBswNormSetSignal_OPNormSetSignalWheelRT
#endif


/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/COMPONENTTYPES/IntBehBsw/RunEntBsw/SSCP_NormSetSignalYawRate */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWCBsw_RPortBswNormSetSignal_OPNormSetSignalYawRate( IN VAR(uint8,AUTOMATIC) FrTick);
#ifndef RTE_C
  #define Rte_Call_RPortBswNormSetSignal_OPNormSetSignalYawRate Rte_Call_SWCBsw_RPortBswNormSetSignal_OPNormSetSignalYawRate
#endif


/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/COMPONENTTYPES/IntBehBsw/RunEntLearnValueHandler/SSCP_NvMSrLearnValues_ReadBlock */
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
  extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWCBsw_RPortBswNvMReadBlock_ReadBlock( IN P2CONST(UInt8,AUTOMATIC,RTE_APPL_DATA) DstPtr);
#else
  extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWCBsw_RPortBswNvMReadBlock_ReadBlock( IN P2CONST(DstPtrType,AUTOMATIC,RTE_APPL_DATA) DstPtr);
#endif
#ifndef RTE_C
  #define Rte_Call_RPortBswNvMReadBlock_ReadBlock Rte_Call_SWCBsw_RPortBswNvMReadBlock_ReadBlock
#endif






#ifndef RTE_C
  #define Rte_InitValue_RPortBswIgnState_DEPIgnState (0)
#endif

#ifndef RTE_C
  #define Rte_InitValue_RPortBswVehicleTaskState_DEP_VehicleAlgoTaskState (0)
#endif


  /* Rte_Read Api mapping  [Satisfies_rte sws 1091].*/
  /* Std_ReturnType Rte_Read_<p>_<o>([IN Rte_Instance <instance>],OUT <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWCBsw_RPortBswVehicleTaskState_DEP_VehicleAlgoTaskState(OUT P2VAR(RTE_t_SYSMultiRunTaskState, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Read_RPortBswVehicleTaskState_DEP_VehicleAlgoTaskState Rte_Read_SWCBsw_RPortBswVehicleTaskState_DEP_VehicleAlgoTaskState
#endif


  /* Rte_Write Api mapping  [Satisfies_rte sws 1071], [Satisfies_rte sws 1280].*/
  /* Std_ReturnType Rte_Write_<p>_<o>([IN Rte_Instance <instance>],IN <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWCBsw_PPortAdcData_DEPAdcData(IN P2VAR(RTE_t_AdcReads, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Write_PPortAdcData_DEPAdcData Rte_Write_SWCBsw_PPortAdcData_DEPAdcData
#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(VAR(NORM_t_eIgnState, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCBsw_RunEntBsw_RPortBswIgnState_DEPIgnState(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntBsw_RPortBswIgnState_DEPIgnState \
    Rte_IRead_SWCBsw_RunEntBsw_RPortBswIgnState_DEPIgnState

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(RTE_t_VdyOutput, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCBsw_RunEntBsw_RPortVdyOutput_DEPVdyOutput(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntBsw_RPortVdyOutput_DEPVdyOutput \
    Rte_IRead_SWCBsw_RunEntBsw_RPortVdyOutput_DEPVdyOutput

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(VehSig_t, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCBsw_RunEntBsw_RPortBswVehSig_DEPBswVehSig(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntBsw_RPortBswVehSig_DEPBswVehSig \
    Rte_IRead_SWCBsw_RunEntBsw_RPortBswVehSig_DEPBswVehSig

#endif


  /* Rte_IWrite Api mapping  [Satisfies_rte sws 3744], [Satisfies_rte sws 1302], [Satisfies_rte sws 3746], [Satisfies_rte sws 3747].*/
  /* void Rte_IWrite_<re>_<p>_<d>([IN RTE_Instance], IN <type>) */
extern FUNC(void, RTE_CODE) Rte_IWrite_SWCBsw_RunEntBsw_PPortMaxTemperature_DEPMaxTemperature(P2VAR(RTE_t_MaxTemperature, AUTOMATIC, RTE_APPL_DATA) arg1);
extern FUNC( P2VAR(RTE_t_MaxTemperature, AUTOMATIC, RTE_APPL_DATA), RTE_CODE ) Rte_IWriteRef_SWCBsw_RunEntBsw_PPortMaxTemperature_DEPMaxTemperature();

#ifndef RTE_C
  #define Rte_IWrite_RunEntBsw_PPortMaxTemperature_DEPMaxTemperature \
    Rte_IWrite_SWCBsw_RunEntBsw_PPortMaxTemperature_DEPMaxTemperature

  #define Rte_IWriteRef_RunEntBsw_PPortMaxTemperature_DEPMaxTemperature \
    Rte_IWriteRef_SWCBsw_RunEntBsw_PPortMaxTemperature_DEPMaxTemperature

#endif


/* Mode API mapping */
extern FUNC(Rte_ModeType_EcuM_Mode, RTE_CODE) Rte_Mode_SWCBsw_RPModeBsw_currentMode( void );
#ifndef RTE_C
	#define Rte_Mode_RPModeBsw_currentMode  \
		Rte_Mode_SWCBsw_RPModeBsw_currentMode
#endif







#ifdef __cplusplus
	} /* extern "C" */
#endif /* __cplusplus */


#endif
