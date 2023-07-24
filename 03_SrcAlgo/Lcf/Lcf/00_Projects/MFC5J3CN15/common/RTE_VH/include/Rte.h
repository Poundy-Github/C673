/**************************************************************************
This file is manually written
Filename:	Rte.h
**************************************************************************/

#ifndef RTE_H
#define RTE_H

#ifdef __cplusplus
	extern "C" {
#endif /* __cplusplus */

#include "Std_Types.h"    /* [Satisfies_rte sws 1164] */

#define FAMO_MFC431_RELEASE_0800_RTE_INT01 1
#define LCF_MFC431_RELEASE_0800_RTE_INT01 1

//#define SW_SOC_MCU_CDRCONFIG_INTVER (4)
//#define LCF_IUC2SOC_INTFVER (2)
#define ABD_OUTPUT_DATA_INTFVER (2)

#define UDW_RTE_8_3 (1)
#define TSA_RTE_8_3 (1)
#define LCF_RTE_8_3 (1)
#define CB_RTE_8_3 (1)

#define IN
#define OUT
#define INOUT
#define PACKED   

/* [PLATFORM54], [PLATFORM55], [PLATFORM56] */
/* MISRA-C:2004 19.4 VIOLATION: Refer to REF 1 above */
#ifndef TRUE
    #define TRUE ((boolean) 1)
#endif

#ifndef FALSE
    #define FALSE ((boolean) 0)
#endif

#ifdef __cplusplus
	} /* extern "C" */
#endif /* __cplusplus */


#endif /* RTE_H */
