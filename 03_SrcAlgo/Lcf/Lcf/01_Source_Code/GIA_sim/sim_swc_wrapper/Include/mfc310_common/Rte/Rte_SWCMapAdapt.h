/**************************************************************************
This file is generated automatically by the RTE generator
Filename:	Rte_SWCMapAdapt.h
CESSAR-CT Version: 3.1.1.11
RTE Version: 3.2.0.1.3.0
Generated on:	Mon Oct 15 14:15:06 CEST 2012
**************************************************************************/


#ifndef _RTE_SWCMapAdapt_H_
#define _RTE_SWCMapAdapt_H_



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
  typedef CONSTP2CONST(Rte_CDS_SWCMapAdapt, AUTOMATIC, RTE_CONST) Rte_Instance;
#endif /* RTE_C */

/* SWC:SWCMapAdapt Indirect API */
	/* The name of the instance handle is Rte_Inst_<c> [Satisfies_rte sws 3793]. */
extern CONST(Rte_CDS_SWCMapAdapt, RTE_CONST) Rte_Instance_SWCMapAdapt;

#ifndef RTE_C

	/*  Provided ports */



	/*  Required ports */


#endif



/* runnable entry points (symbol) */

extern void MAP_v_AdaptInit (void); 
extern void MAP_v_AdaptMain (void); 


/* application error code */
#ifndef RTE_E_CSI_Timer64GetTimerValue_E_NOT_OK
  #define RTE_E_CSI_Timer64GetTimerValue_E_NOT_OK 1
#endif



/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/COMPONENTTYPES/IntBehMapAdapt/RunEntMapAdapt/SSCP_MapTimer64GetTimerValue */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWCMapAdapt_RPortMapTimer64GetTimerValue_OPTimer64GetTimerValue( OUT P2VAR(uint64,AUTOMATIC,RTE_APPL_DATA) timerValue);
#ifndef RTE_C
  #define Rte_Call_RPortMapTimer64GetTimerValue_OPTimer64GetTimerValue Rte_Call_SWCMapAdapt_RPortMapTimer64GetTimerValue_OPTimer64GetTimerValue
#endif






#ifndef RTE_C
  #define Rte_InitValue_RPortMapDebugMode_DEPAlgoDebugMode (0)
#endif

#ifndef RTE_C
  #define Rte_InitValue_PPortMapTaskState_DEP_VehicleAlgoTaskState (0)
#endif


  /* Rte_Read Api mapping  [Satisfies_rte sws 1091].*/
  /* Std_ReturnType Rte_Read_<p>_<o>([IN Rte_Instance <instance>],OUT <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWCMapAdapt_RPortMapDebugMode_DEPAlgoDebugMode(OUT P2VAR(RTE_t_eAlgoDebugMode, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Read_RPortMapDebugMode_DEPAlgoDebugMode Rte_Read_SWCMapAdapt_RPortMapDebugMode_DEPAlgoDebugMode
#endif


  /* Rte_Write Api mapping  [Satisfies_rte sws 1071], [Satisfies_rte sws 1280].*/
  /* Std_ReturnType Rte_Write_<p>_<o>([IN Rte_Instance <instance>],IN <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWCMapAdapt_PPortMapAlgoVersion_DEPAlgoVersion(IN P2VAR(RTE_t_AlgoVersion, AUTOMATIC, RTE_APPL_DATA) arg1);
#ifndef RTE_C
  #define Rte_Write_PPortMapAlgoVersion_DEPAlgoVersion Rte_Write_SWCMapAdapt_PPortMapAlgoVersion_DEPAlgoVersion
#endif


  /* Rte_Write Api mapping  [Satisfies_rte sws 1071], [Satisfies_rte sws 1280].*/
  /* Std_ReturnType Rte_Write_<p>_<o>([IN Rte_Instance <instance>],IN <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWCMapAdapt_PPortMapTaskState_DEP_VehicleAlgoTaskState(IN VAR(RTE_t_SYSMultiRunTaskState, AUTOMATIC) arg1);
#ifndef RTE_C
  #define Rte_Write_PPortMapTaskState_DEP_VehicleAlgoTaskState Rte_Write_SWCMapAdapt_PPortMapTaskState_DEP_VehicleAlgoTaskState
#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(RTE_t_MAPIFCuA, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCMapAdapt_RunEntMapAdapt_RPortMapCuA_DEPMapCuA(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntMapAdapt_RPortMapCuA_DEPMapCuA \
    Rte_IRead_SWCMapAdapt_RunEntMapAdapt_RPortMapCuA_DEPMapCuA

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(RTE_t_TSAIFInputGPSPos, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCMapAdapt_RunEntMapAdapt_RPortMapGPSPos_DEPGPSPos(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntMapAdapt_RPortMapGPSPos_DEPGPSPos \
    Rte_IRead_SWCMapAdapt_RunEntMapAdapt_RPortMapGPSPos_DEPGPSPos

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(RTE_t_MAPIFInput, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCMapAdapt_RunEntMapAdapt_RPortMapInput_DEPMapInput(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntMapAdapt_RPortMapInput_DEPMapInput \
    Rte_IRead_SWCMapAdapt_RunEntMapAdapt_RPortMapInput_DEPMapInput

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(RTE_t_MAPIFMetaData, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCMapAdapt_RunEntMapAdapt_RPortMapMetaData_DEPMapMetaData(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntMapAdapt_RPortMapMetaData_DEPMapMetaData \
    Rte_IRead_SWCMapAdapt_RunEntMapAdapt_RPortMapMetaData_DEPMapMetaData

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(RTE_t_MAPIFPosition, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCMapAdapt_RunEntMapAdapt_RPortMapPosition_DEPMapPosition(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntMapAdapt_RPortMapPosition_DEPMapPosition \
    Rte_IRead_SWCMapAdapt_RunEntMapAdapt_RPortMapPosition_DEPMapPosition

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(RTE_t_MAPIFProfile, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCMapAdapt_RunEntMapAdapt_RPortMapProfileLong_DEPMapProfile(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntMapAdapt_RPortMapProfileLong_DEPMapProfile \
    Rte_IRead_SWCMapAdapt_RunEntMapAdapt_RPortMapProfileLong_DEPMapProfile

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(RTE_t_MAPIFProfile, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCMapAdapt_RunEntMapAdapt_RPortMapProfileShort0_DEPMapProfile(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntMapAdapt_RPortMapProfileShort0_DEPMapProfile \
    Rte_IRead_SWCMapAdapt_RunEntMapAdapt_RPortMapProfileShort0_DEPMapProfile

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(RTE_t_MAPIFProfile, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCMapAdapt_RunEntMapAdapt_RPortMapProfileShort1_DEPMapProfile(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntMapAdapt_RPortMapProfileShort1_DEPMapProfile \
    Rte_IRead_SWCMapAdapt_RunEntMapAdapt_RPortMapProfileShort1_DEPMapProfile

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(RTE_t_MAPIFSegment, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCMapAdapt_RunEntMapAdapt_RPortMapSegment_DEPMapSegment(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntMapAdapt_RPortMapSegment_DEPMapSegment \
    Rte_IRead_SWCMapAdapt_RunEntMapAdapt_RPortMapSegment_DEPMapSegment

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(RTE_t_MAPIFStub, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCMapAdapt_RunEntMapAdapt_RPortMapStub_DEPMapStub(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntMapAdapt_RPortMapStub_DEPMapStub \
    Rte_IRead_SWCMapAdapt_RunEntMapAdapt_RPortMapStub_DEPMapStub

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(RTE_t_MAPIFInputTimestamp, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCMapAdapt_RunEntMapAdapt_RPortMapTimeMetaData_DEPMapTimestamp(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntMapAdapt_RPortMapTimeMetaData_DEPMapTimestamp \
    Rte_IRead_SWCMapAdapt_RunEntMapAdapt_RPortMapTimeMetaData_DEPMapTimestamp

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(RTE_t_MAPIFInputTimestamp, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCMapAdapt_RunEntMapAdapt_RPortMapTimeNewStub_DEPMapTimestamp(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntMapAdapt_RPortMapTimeNewStub_DEPMapTimestamp \
    Rte_IRead_SWCMapAdapt_RunEntMapAdapt_RPortMapTimeNewStub_DEPMapTimestamp

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(RTE_t_MAPIFInputTimestamp, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCMapAdapt_RunEntMapAdapt_RPortMapTimePosition_DEPMapTimestamp(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntMapAdapt_RPortMapTimePosition_DEPMapTimestamp \
    Rte_IRead_SWCMapAdapt_RunEntMapAdapt_RPortMapTimePosition_DEPMapTimestamp

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(RTE_t_MAPIFInputTimestamp, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCMapAdapt_RunEntMapAdapt_RPortMapTimeProfileLong_DEPMapTimestamp(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntMapAdapt_RPortMapTimeProfileLong_DEPMapTimestamp \
    Rte_IRead_SWCMapAdapt_RunEntMapAdapt_RPortMapTimeProfileLong_DEPMapTimestamp

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(RTE_t_MAPIFInputTimestamp, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCMapAdapt_RunEntMapAdapt_RPortMapTimeProfileShort_DEPMapTimestamp(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntMapAdapt_RPortMapTimeProfileShort_DEPMapTimestamp \
    Rte_IRead_SWCMapAdapt_RunEntMapAdapt_RPortMapTimeProfileShort_DEPMapTimestamp

#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(RTE_t_MAPIFInputTimestamp, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_SWCMapAdapt_RunEntMapAdapt_RPortMapTimeSegment_DEPMapTimestamp(void);

#ifndef RTE_C
  #define Rte_IRead_RunEntMapAdapt_RPortMapTimeSegment_DEPMapTimestamp \
    Rte_IRead_SWCMapAdapt_RunEntMapAdapt_RPortMapTimeSegment_DEPMapTimestamp

#endif


  /* Rte_IWrite Api mapping  [Satisfies_rte sws 3744], [Satisfies_rte sws 1302], [Satisfies_rte sws 3746], [Satisfies_rte sws 3747].*/
  /* void Rte_IWrite_<re>_<p>_<d>([IN RTE_Instance], IN <type>) */
extern FUNC(void, RTE_CODE) Rte_IWrite_SWCMapAdapt_RunEntMapAdapt_PPortMapOutput_DEP_MapData(P2VAR(RTE_t_MAPIFMapData, AUTOMATIC, RTE_APPL_DATA) arg1);
extern FUNC( P2VAR(RTE_t_MAPIFMapData, AUTOMATIC, RTE_APPL_DATA), RTE_CODE ) Rte_IWriteRef_SWCMapAdapt_RunEntMapAdapt_PPortMapOutput_DEP_MapData();

#ifndef RTE_C
  #define Rte_IWrite_RunEntMapAdapt_PPortMapOutput_DEP_MapData \
    Rte_IWrite_SWCMapAdapt_RunEntMapAdapt_PPortMapOutput_DEP_MapData

  #define Rte_IWriteRef_RunEntMapAdapt_PPortMapOutput_DEP_MapData \
    Rte_IWriteRef_SWCMapAdapt_RunEntMapAdapt_PPortMapOutput_DEP_MapData

#endif

  /* Rte_IWrite Api mapping  [Satisfies_rte sws 3744], [Satisfies_rte sws 1302], [Satisfies_rte sws 3746], [Satisfies_rte sws 3747].*/
  /* void Rte_IWrite_<re>_<p>_<d>([IN RTE_Instance], IN <type>) */
extern FUNC(void, RTE_CODE) Rte_IWrite_SWCMapAdapt_RunEntMapAdapt_PPortMapSystemInfo_DEPMapSystemInfo(P2VAR(RTE_t_MAPIFOutputSystemInfo, AUTOMATIC, RTE_APPL_DATA) arg1);
extern FUNC( P2VAR(RTE_t_MAPIFOutputSystemInfo, AUTOMATIC, RTE_APPL_DATA), RTE_CODE ) Rte_IWriteRef_SWCMapAdapt_RunEntMapAdapt_PPortMapSystemInfo_DEPMapSystemInfo();

#ifndef RTE_C
  #define Rte_IWrite_RunEntMapAdapt_PPortMapSystemInfo_DEPMapSystemInfo \
    Rte_IWrite_SWCMapAdapt_RunEntMapAdapt_PPortMapSystemInfo_DEPMapSystemInfo

  #define Rte_IWriteRef_RunEntMapAdapt_PPortMapSystemInfo_DEPMapSystemInfo \
    Rte_IWriteRef_SWCMapAdapt_RunEntMapAdapt_PPortMapSystemInfo_DEPMapSystemInfo

#endif


/* Mode API mapping */
extern FUNC(Rte_ModeType_EcuM_Mode, RTE_CODE) Rte_Mode_SWCMapAdapt_RPortModeMapAdapt_currentMode( void );
#ifndef RTE_C
	#define Rte_Mode_RPortModeMapAdapt_currentMode  \
		Rte_Mode_SWCMapAdapt_RPortModeMapAdapt_currentMode
#endif







#ifdef __cplusplus
	} /* extern "C" */
#endif /* __cplusplus */


#endif
