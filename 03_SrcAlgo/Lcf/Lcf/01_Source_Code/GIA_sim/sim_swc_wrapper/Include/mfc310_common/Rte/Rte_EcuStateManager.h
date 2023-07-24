/**************************************************************************
This file is generated automatically by the RTE generator
Filename:	Rte_EcuStateManager.h
CESSAR-CT Version: 3.1.1.11
RTE Version: 3.2.0.1.3.0
Generated on:	Fri Feb 03 12:37:32 CET 2012
**************************************************************************/


#ifndef _RTE_EcuStateManager_H_
#define _RTE_EcuStateManager_H_



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
  typedef CONSTP2CONST(Rte_CDS_EcuStateManager, AUTOMATIC, RTE_CONST) Rte_Instance;
#endif /* RTE_C */

/* SWC:EcuStateManager Indirect API */
	/* The name of the instance handle is Rte_Inst_<c> [Satisfies_rte sws 3793]. */
extern CONST(Rte_CDS_EcuStateManager, RTE_CONST) Rte_Instance_EcuStateManager;

#ifndef RTE_C

	/*  Provided ports */



	/*  Required ports */


#endif



/* runnable entry points (symbol) */



/* application error code */
#ifndef RTE_E_EcuM_StateRequest_E_NOT_OK
  #define RTE_E_EcuM_StateRequest_E_NOT_OK 1
#endif
#ifndef RTE_E_EcuM_ApplicationMode_E_NOT_OK
  #define RTE_E_EcuM_ApplicationMode_E_NOT_OK 1
#endif
#ifndef RTE_E_EcuM_BootTarget_E_NOT_OK
  #define RTE_E_EcuM_BootTarget_E_NOT_OK 1
#endif
#ifndef RTE_E_EcuM_ShutdownTarget_E_NOT_OK
  #define RTE_E_EcuM_ShutdownTarget_E_NOT_OK 1
#endif









/* Mode API mapping */
extern FUNC(Rte_ModeType_EcuM_Mode, RTE_CODE) Rte_Mode_EcuStateManager_currentMode_currentMode( void );
#ifndef RTE_C
	#define Rte_Mode_currentMode_currentMode  \
		Rte_Mode_EcuStateManager_currentMode_currentMode
#endif


/* Mode API mapping */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_EcuStateManager_currentMode_currentMode(IN Rte_ModeType_EcuM_Mode arg1);
#ifndef RTE_C
	#define Rte_Switch_currentMode_currentMode(arg1)  Rte_Switch_EcuStateManager_currentMode_currentMode(arg1)
#endif






#ifdef __cplusplus
	} /* extern "C" */
#endif /* __cplusplus */


#endif
