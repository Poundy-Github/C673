/**************************************************************************
This file is generated automatically by the RTE generator
Filename:	Rte_Algo.h
CESSAR-CT Version: 2016.2.0.0
RTE Version: 4.0.3.2.7.0
Generated on:	Mon Oct 29 13:36:50 EET 2018
**************************************************************************/


#ifndef RTE_Algo_H
#define RTE_Algo_H





#ifdef RTE_APPLICATION_HEADER_FILE
	#ifndef RTE_C
		#error Multiple application header files included. 
	#endif /* RTE_C */
#endif /* RTE_APPLICATION_HEADER_FILE */

#define RTE_APPLICATION_HEADER_FILE
/* Multiple application header file must not be included in the same module [Satisfies_rte_sws_1004], [Satisfies_rte_sws_1006] */


#include "Rte_Algo_Type.h"


#ifdef __cplusplus
	extern "C" {
#endif /* __cplusplus */



#if !defined(RTE_RUNNABLEAPI_RUNNABLEENTITY)
#define RTE_ALL_RUNNABLEAPI_ALGO
#endif

/**********************************************/
/* Component data structure (CDS)             */
/**********************************************/

/*
 * Port Data Section (PDS) types for SW-C: Algo
 */


/****
 * Component Data Structure type (CDS) for SW-C: Algo
 ****/

typedef struct Rte_CDS_Algo_S 
{

    uint8 _dummy;			/*lint !e960 _dummy is req. [Satisfies_rte_sws_3724] */

} Rte_CDS_Algo;



#ifndef RTE_C
  typedef CONSTP2CONST(Rte_CDS_Algo, AUTOMATIC, RTE_CONST) Rte_Instance;
#endif /* RTE_C */

/* SWC:Algo Indirect API */
	/* The name of the instance handle is Rte_Inst_<c> [Satisfies_rte_sws_3793]. */
#define RTE_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* [Satisfies_rte_sws_3788] */ 
	extern CONST(Rte_CDS_Algo, RTE_CONST) Rte_Instance_Algo;
#define RTE_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* [Satisfies_rte_sws_3788] */ 


#ifndef RTE_C

	/*  Provided ports */



	/*  Required ports */


#endif




/* runnable entry points (symbol) */












#ifdef __cplusplus
	} /* extern "C" */
#endif /* __cplusplus */


#endif
