/**************************************************************************
This file is generated automatically by the RTE generator
Filename:	Rte_SwcRoElite.h
CESSAR-CT Version: 3.1.1.11
RTE Version: 3.2.0.1.3.0
Generated on:	Thu Oct 18 18:23:12 CEST 2012
**************************************************************************/


#ifndef _RTE_SwcRoElite_H_
#define _RTE_SwcRoElite_H_



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
  typedef CONSTP2CONST(Rte_CDS_SwcRoElite, AUTOMATIC, RTE_CONST) Rte_Instance;
#endif /* RTE_C */

/* SWC:SwcRoElite Indirect API */
	/* The name of the instance handle is Rte_Inst_<c> [Satisfies_rte sws 3793]. */
extern CONST(Rte_CDS_SwcRoElite, RTE_CONST) Rte_Instance_SwcRoElite;

#ifndef RTE_C

	/*  Provided ports */



	/*  Required ports */


#endif



/* runnable entry points (symbol) */

extern void SwcRoElite_Init (void); 
extern void SwcRoElite_Cyclic (void); 
/* runnable entry points (symbol) for servers */
extern FUNC(Std_ReturnType, RTE_APPL_CODE) SwcRoElite_StatusChangeHandler( IN VAR(Dem_DTCType,AUTOMATIC) DTC, IN VAR(Dem_DTCKindType,AUTOMATIC) DTCKind, IN VAR(Dem_DTCStatusMaskType,AUTOMATIC) DTCStatusOld, IN VAR(Dem_DTCStatusMaskType,AUTOMATIC) DTCStatusNew);


typedef Rte_PimType_SwcRoElite_SwcRoElite_MsgTypeU SwcRoElite_MsgTypeU;      /* [Satisfies_rte sws 3782] */

typedef Rte_PimType_SwcRoElite_SwcRoElite_QueueTypeU SwcRoElite_QueueTypeU;      /* [Satisfies_rte sws 3782] */

    /* The Rte_Pim Api is defined as: <type> Rte_Pim_<name>([IN Rte_Instance <instance>]) [Satisfies_rte sws 1118].*/
    /*  The Rte_Pim Api exists for every PerInstanceMemory [Satisfies_rte sws 1299].*/
    /*  The Rte_Pim Api returns a pointer to the Pim [Satisfies_rte sws 1119].*/

extern FUNC(P2VAR(Rte_PimType_SwcRoElite_SwcRoElite_MsgTypeU, AUTOMATIC, RTE_APPL_DATA),RTE_CODE) Rte_Pim_SwcRoElite_SwcRoElite_DiagData(void);
#ifndef RTE_C
  /* The macro generated for the Rte Pim and Rte CData API calls shall map to the relevant fields of the CDS. */
  #define Rte_Pim_SwcRoElite_DiagData Rte_Pim_SwcRoElite_SwcRoElite_DiagData 
#endif

extern FUNC(P2VAR(Rte_PimType_SwcRoElite_SwcRoElite_QueueTypeU, AUTOMATIC, RTE_APPL_DATA),RTE_CODE) Rte_Pim_SwcRoElite_SwcRoElite_Queue(void);
#ifndef RTE_C
  /* The macro generated for the Rte Pim and Rte CData API calls shall map to the relevant fields of the CDS. */
  #define Rte_Pim_SwcRoElite_Queue Rte_Pim_SwcRoElite_SwcRoElite_Queue 
#endif


/* application error code */
#ifndef RTE_E_StatusAvailabilityMask_E_NOT_OK
  #define RTE_E_StatusAvailabilityMask_E_NOT_OK 1
#endif
#ifndef RTE_E_CallbackDTCStatusChange_E_NOT_OK
  #define RTE_E_CallbackDTCStatusChange_E_NOT_OK 1
#endif



/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/COMPONENTTYPES/SwcRoElite_InternalBehavior/SwcRoElite_Cyclic/SSCP_RoEliteSendRoE */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SwcRoElite_RPortRoEliteSendRoE_OPSendRoE( INOUT P2VAR(SwcRoElite_MsgType,AUTOMATIC,RTE_APPL_DATA) data);
#ifndef RTE_C
  #define Rte_Call_RPortRoEliteSendRoE_OPSendRoE Rte_Call_SwcRoElite_RPortRoEliteSendRoE_OPSendRoE
#endif


/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/COMPONENTTYPES/SwcRoElite_InternalBehavior/SwcRoElite_Init/SC_SwcRoElite_GetStatusM727F04C5 */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SwcRoElite_SwcRoElite_GetStatusMask_GetStatusMask( OUT P2VAR(UInt8,AUTOMATIC,RTE_APPL_DATA) sam);
#ifndef RTE_C
  #define Rte_Call_SwcRoElite_GetStatusMask_GetStatusMask Rte_Call_SwcRoElite_SwcRoElite_GetStatusMask_GetStatusMask
#endif







/* Exclusive areas API mapping */
  /* Rte Enter Api mapping  [Satisfies_rte sws 1120], [Satisfies_rte sws 1307], [Satisfies_rte sws 1122], [Satisfies_rte sws 3515].    */
  /* void Rte_Enter_<name>([IN Rte_Instance <instance>]) */
extern FUNC(void, RTE_CODE) Rte_Enter_SwcRoElite_ExclusiveArea_FifoQueue( );
#ifndef RTE_C
#define Rte_Enter_ExclusiveArea_FifoQueue( )  Rte_Enter_SwcRoElite_ExclusiveArea_FifoQueue( ); 
#endif

  /* Rte Exit Api mapping  [Satisfies_rte sws 1123], [Satisfies_rte sws 1308], [Satisfies_rte sws 3515].    */
  /* void Rte_Exit_<name>([IN Rte_Instance <instance>]) */
extern FUNC(void, RTE_CODE) Rte_Exit_SwcRoElite_ExclusiveArea_FifoQueue( );
#ifndef RTE_C
#define Rte_Exit_ExclusiveArea_FifoQueue( )  Rte_Exit_SwcRoElite_ExclusiveArea_FifoQueue( ); 
#endif



/* Explicit Inter Runnable Variable mapping */
  /* Rte_IrvRead Api mapping [Satisfies_rte sws 3560], [Satisfies_rte sws 1305], [Satisfies_rte sws 3562], [Satisfies_rte sws 3563]*/
extern FUNC(UInt8, RTE_CODE) Rte_IrvRead_SwcRoElite_SwcRoElite_Cyclic_QueueEntries(void);
#ifndef RTE_C
  #define Rte_IrvRead_SwcRoElite_Cyclic_QueueEntries Rte_IrvRead_SwcRoElite_SwcRoElite_Cyclic_QueueEntries
#endif

  /* Rte_IrvRead Api mapping [Satisfies_rte sws 3560], [Satisfies_rte sws 1305], [Satisfies_rte sws 3562], [Satisfies_rte sws 3563]*/
extern FUNC(UInt8, RTE_CODE) Rte_IrvRead_SwcRoElite_SwcRoElite_Cyclic_QueueReadIndex(void);
#ifndef RTE_C
  #define Rte_IrvRead_SwcRoElite_Cyclic_QueueReadIndex Rte_IrvRead_SwcRoElite_SwcRoElite_Cyclic_QueueReadIndex
#endif

/* Rte_IrvWrite Api mapping [Satisfies_rte sws 3565], [Satisfies_rte sws 1306], [Satisfies_rte sws 3567], [Satisfies_rte sws 3569] */
/* void Rte_IrvWrite_<re>_<name>([IN RTE_Instance <instance>], IN <data>) */
extern FUNC(void, RTE_CODE) Rte_IrvWrite_SwcRoElite_SwcRoElite_Cyclic_QueueEntries(UInt8 val);
#ifndef RTE_C
  #define Rte_IrvWrite_SwcRoElite_Cyclic_QueueEntries Rte_IrvWrite_SwcRoElite_SwcRoElite_Cyclic_QueueEntries  /* [Satisfies_rte sws 1348] */
#endif

/* Rte_IrvWrite Api mapping [Satisfies_rte sws 3565], [Satisfies_rte sws 1306], [Satisfies_rte sws 3567], [Satisfies_rte sws 3569] */
/* void Rte_IrvWrite_<re>_<name>([IN RTE_Instance <instance>], IN <data>) */
extern FUNC(void, RTE_CODE) Rte_IrvWrite_SwcRoElite_SwcRoElite_Cyclic_QueueReadIndex(UInt8 val);
#ifndef RTE_C
  #define Rte_IrvWrite_SwcRoElite_Cyclic_QueueReadIndex Rte_IrvWrite_SwcRoElite_SwcRoElite_Cyclic_QueueReadIndex  /* [Satisfies_rte sws 1348] */
#endif

  /* Rte_IrvRead Api mapping [Satisfies_rte sws 3560], [Satisfies_rte sws 1305], [Satisfies_rte sws 3562], [Satisfies_rte sws 3563]*/
extern FUNC(UInt8, RTE_CODE) Rte_IrvRead_SwcRoElite_SwcRoElite_StatusChangeHandler_QueueEntries(void);
#ifndef RTE_C
  #define Rte_IrvRead_SwcRoElite_StatusChangeHandler_QueueEntries Rte_IrvRead_SwcRoElite_SwcRoElite_StatusChangeHandler_QueueEntries
#endif

  /* Rte_IrvRead Api mapping [Satisfies_rte sws 3560], [Satisfies_rte sws 1305], [Satisfies_rte sws 3562], [Satisfies_rte sws 3563]*/
extern FUNC(UInt8, RTE_CODE) Rte_IrvRead_SwcRoElite_SwcRoElite_StatusChangeHandler_QueueReadIndex(void);
#ifndef RTE_C
  #define Rte_IrvRead_SwcRoElite_StatusChangeHandler_QueueReadIndex Rte_IrvRead_SwcRoElite_SwcRoElite_StatusChangeHandler_QueueReadIndex
#endif

  /* Rte_IrvRead Api mapping [Satisfies_rte sws 3560], [Satisfies_rte sws 1305], [Satisfies_rte sws 3562], [Satisfies_rte sws 3563]*/
extern FUNC(UInt8, RTE_CODE) Rte_IrvRead_SwcRoElite_SwcRoElite_StatusChangeHandler_QueueWriteIndex(void);
#ifndef RTE_C
  #define Rte_IrvRead_SwcRoElite_StatusChangeHandler_QueueWriteIndex Rte_IrvRead_SwcRoElite_SwcRoElite_StatusChangeHandler_QueueWriteIndex
#endif

/* Rte_IrvWrite Api mapping [Satisfies_rte sws 3565], [Satisfies_rte sws 1306], [Satisfies_rte sws 3567], [Satisfies_rte sws 3569] */
/* void Rte_IrvWrite_<re>_<name>([IN RTE_Instance <instance>], IN <data>) */
extern FUNC(void, RTE_CODE) Rte_IrvWrite_SwcRoElite_SwcRoElite_StatusChangeHandler_QueueEntries(UInt8 val);
#ifndef RTE_C
  #define Rte_IrvWrite_SwcRoElite_StatusChangeHandler_QueueEntries Rte_IrvWrite_SwcRoElite_SwcRoElite_StatusChangeHandler_QueueEntries  /* [Satisfies_rte sws 1348] */
#endif

/* Rte_IrvWrite Api mapping [Satisfies_rte sws 3565], [Satisfies_rte sws 1306], [Satisfies_rte sws 3567], [Satisfies_rte sws 3569] */
/* void Rte_IrvWrite_<re>_<name>([IN RTE_Instance <instance>], IN <data>) */
extern FUNC(void, RTE_CODE) Rte_IrvWrite_SwcRoElite_SwcRoElite_StatusChangeHandler_QueueReadIndex(UInt8 val);
#ifndef RTE_C
  #define Rte_IrvWrite_SwcRoElite_StatusChangeHandler_QueueReadIndex Rte_IrvWrite_SwcRoElite_SwcRoElite_StatusChangeHandler_QueueReadIndex  /* [Satisfies_rte sws 1348] */
#endif

/* Rte_IrvWrite Api mapping [Satisfies_rte sws 3565], [Satisfies_rte sws 1306], [Satisfies_rte sws 3567], [Satisfies_rte sws 3569] */
/* void Rte_IrvWrite_<re>_<name>([IN RTE_Instance <instance>], IN <data>) */
extern FUNC(void, RTE_CODE) Rte_IrvWrite_SwcRoElite_SwcRoElite_StatusChangeHandler_QueueWriteIndex(UInt8 val);
#ifndef RTE_C
  #define Rte_IrvWrite_SwcRoElite_StatusChangeHandler_QueueWriteIndex Rte_IrvWrite_SwcRoElite_SwcRoElite_StatusChangeHandler_QueueWriteIndex  /* [Satisfies_rte sws 1348] */
#endif


/* Mode API mapping */
extern FUNC(Rte_ModeType_EcuM_Mode, RTE_CODE) Rte_Mode_SwcRoElite_RPortRoEliteMode_currentMode( void );
#ifndef RTE_C
	#define Rte_Mode_RPortRoEliteMode_currentMode  \
		Rte_Mode_SwcRoElite_RPortRoEliteMode_currentMode
#endif







#ifdef __cplusplus
	} /* extern "C" */
#endif /* __cplusplus */


#endif
