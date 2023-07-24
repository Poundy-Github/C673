/**************************************************************************
This file is generated automatically by the RTE generator
Filename:	Rte_CDDTimer64.h
CESSAR-CT Version: 3.1.1.11
RTE Version: 3.2.0.1.3.0
Generated on:	Fri May 11 14:34:26 CEST 2012
**************************************************************************/


#ifndef _RTE_CDDTimer64_H_
#define _RTE_CDDTimer64_H_



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
  typedef CONSTP2CONST(Rte_CDS_CDDTimer64, AUTOMATIC, RTE_CONST) Rte_Instance;
#endif /* RTE_C */

/* SWC:CDDTimer64 Indirect API */
	/* The name of the instance handle is Rte_Inst_<c> [Satisfies_rte sws 3793]. */
extern CONST(Rte_CDS_CDDTimer64, RTE_CONST) Rte_Instance_CDDTimer64;

#ifndef RTE_C

	/*  Provided ports */



	/*  Required ports */


#endif



/* runnable entry points (symbol) */

/* runnable entry points (symbol) for servers */
extern FUNC(Std_ReturnType, RTE_APPL_CODE) Timer64_AdjustTimerValue( IN VAR(sint64,AUTOMATIC) offset);
extern FUNC(Std_ReturnType, RTE_APPL_CODE) Timer64_GetTimerValue( OUT P2VAR(uint64,AUTOMATIC,RTE_APPL_DATA) timerValue);



/* application error code */
#ifndef RTE_E_CSI_Timer64AdjustTimerValue_E_NOT_OK
  #define RTE_E_CSI_Timer64AdjustTimerValue_E_NOT_OK 1
#endif
#ifndef RTE_E_CSI_Timer64GetTimerValue_E_NOT_OK
  #define RTE_E_CSI_Timer64GetTimerValue_E_NOT_OK 1
#endif















#ifdef __cplusplus
	} /* extern "C" */
#endif /* __cplusplus */


#endif
