/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  Copyright (c) 2006-2010 by Vector Informatik GmbH.                                             All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Components/Rte_ComM.h
 *     Workspace:  D:/Sandboxes/MFC300/MFC300_Base/05_Software/MCU/03_Design/05_DaVinci/mfc310_SMPC.dev
 *   ECU-Project:  MPC
 *  Generated at:  Thu Jul  7 11:15:49 2011
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.3
 *       License:  License CBD1000091 valid for CBD1000091 A.D.C. GmbH Continental  Package: Daimler Car SLP10  Micro: MPC567xK / MPC5675K  Compiler: Metrowerks V4.0.0
 *
 *   Description:  Application header file for SW-C
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_COMM_H
# define _RTE_COMM_H

# ifndef RTE_CORE
#  ifdef RTE_APPLICATION_HEADER_FILE
#   error Multiple application header files included.
#  endif
#  define RTE_APPLICATION_HEADER_FILE
# endif

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Rte_Type.h"


# define RTE_START_SEC_COMM_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

FUNC(void, RTE_COMM_APPL_CODE) ComM_MainFunction_0(void);

FUNC(Std_ReturnType, RTE_COMM_APPL_CODE) ComM_GetCurrentComMode(ComM_UserHandleType parg0, P2VAR(ComM_ModeType, AUTOMATIC, RTE_COMM_APPL_VAR) ComMode);

FUNC(Std_ReturnType, RTE_COMM_APPL_CODE) ComM_GetInhibitionStatus(ComM_NetworkHandleType parg0, P2VAR(ComM_InhibitionStatusType, AUTOMATIC, RTE_COMM_APPL_VAR) Status);

FUNC(Std_ReturnType, RTE_COMM_APPL_CODE) ComM_GetMaxComMode(ComM_UserHandleType parg0, P2VAR(ComM_ModeType, AUTOMATIC, RTE_COMM_APPL_VAR) ComMode);

FUNC(Std_ReturnType, RTE_COMM_APPL_CODE) ComM_GetRequestedComMode(ComM_UserHandleType parg0, P2VAR(ComM_ModeType, AUTOMATIC, RTE_COMM_APPL_VAR) ComMode);

FUNC(Std_ReturnType, RTE_COMM_APPL_CODE) ComM_ServiceLimitChannelToNoComMode(ComM_NetworkHandleType parg0, Boolean Status);

FUNC(Std_ReturnType, RTE_COMM_APPL_CODE) ComM_LimitECUToNoComMode(Boolean Status);

FUNC(Std_ReturnType, RTE_COMM_APPL_CODE) ComM_ServicePreventWakeUp(ComM_NetworkHandleType parg0, Boolean Status);

FUNC(Std_ReturnType, RTE_COMM_APPL_CODE) ComM_ReadInhibitCounter(P2VAR(UInt16, AUTOMATIC, RTE_COMM_APPL_VAR) CounterValue);

FUNC(Std_ReturnType, RTE_COMM_APPL_CODE) ComM_RequestComMode(ComM_UserHandleType parg0, ComM_ModeType ComMode);

FUNC(Std_ReturnType, RTE_COMM_APPL_CODE) ComM_ResetInhibitCounter(void);

FUNC(Std_ReturnType, RTE_COMM_APPL_CODE) ComM_SetECUGroupClassification(ComM_InhibitionStatusType Status);

# define RTE_STOP_SEC_COMM_APPL_CODE
# include "MemMap.h"


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_ComM_ChannelLimitation_E_NOT_OK (1u)

#  define RTE_E_ComM_ChannelWakeUp_E_NOT_OK (1u)

#  define RTE_E_ComM_ECUModeLimitation_E_NOT_OK (1u)

#  define RTE_E_ComM_UserRequest_COMM_E_MODE_LIMITATION (2u)

#  define RTE_E_ComM_UserRequest_E_NOT_OK (1u)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1310030428
#    error "The magic number of the generated file <D:/Sandboxes/MFC300/MFC300_Base/05_Software/MCU/03_Design/05_DaVinci/MPC/Rte/Components/Rte_ComM.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1310030428
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_COMM_H */
