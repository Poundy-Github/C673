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
 *          File:  Components/Rte_Dcm.h
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
#ifndef _RTE_DCM_H
# define _RTE_DCM_H

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


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_PassiveModeService_OnChange(Boolean passiveState);

# define RTE_STOP_SEC_CODE
# include "MemMap.h"


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplComControlService_CheckCondition(UInt8 subNetId, UInt8 msgType, Boolean rxState, Boolean txState);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_ComControlService_CheckCondition RE_CT_DiagnosticsApplComControlService_CheckCondition
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0102_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0102_ConditionCheckRead RE_CT_DiagnosticsApplDidServices_0x0102_ConditionCheckRead
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0102_ConditionCheckWrite(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0102_ConditionCheckWrite RE_CT_DiagnosticsApplDidServices_0x0102_ConditionCheckWrite
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0102_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0102_ReadData(P2VAR(Dcm_12Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0102_ReadData RE_CT_DiagnosticsApplDidServices_0x0102_ReadData
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0102_WriteData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0102_WriteData(P2VAR(Dcm_12Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0102_WriteData RE_CT_DiagnosticsApplDidServices_0x0102_WriteData
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x010c_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x010c_ConditionCheckRead RE_CT_DiagnosticsApplDidServices_0x010c_ConditionCheckRead
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x010c_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x010c_ReadData(P2VAR(Dcm_3Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x010c_ReadData RE_CT_DiagnosticsApplDidServices_0x010c_ReadData
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x010d_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x010d_ConditionCheckRead RE_CT_DiagnosticsApplDidServices_0x010d_ConditionCheckRead
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x010d_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x010d_ReadData(P2VAR(Dcm_33Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x010d_ReadData RE_CT_DiagnosticsApplDidServices_0x010d_ReadData
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0210_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0210_ConditionCheckRead RE_CT_DiagnosticsApplDidServices_0x0210_ConditionCheckRead
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0210_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0210_ReadData(P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0210_ReadData RE_CT_DiagnosticsApplDidServices_0x0210_ReadData
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0212_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0212_ConditionCheckRead RE_CT_DiagnosticsApplDidServices_0x0212_ConditionCheckRead
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0212_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0212_ReadData(P2VAR(Dcm_12Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0212_ReadData RE_CT_DiagnosticsApplDidServices_0x0212_ReadData
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0213_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0213_ConditionCheckRead RE_CT_DiagnosticsApplDidServices_0x0213_ConditionCheckRead
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0213_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0213_ReadData(P2VAR(Dcm_62Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0213_ReadData RE_CT_DiagnosticsApplDidServices_0x0213_ReadData
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0214_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0214_ConditionCheckRead RE_CT_DiagnosticsApplDidServices_0x0214_ConditionCheckRead
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0214_ConditionCheckWrite(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0214_ConditionCheckWrite RE_CT_DiagnosticsApplDidServices_0x0214_ConditionCheckWrite
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0214_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0214_ReadData(P2VAR(Dcm_20Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0214_ReadData RE_CT_DiagnosticsApplDidServices_0x0214_ReadData
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0214_WriteData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0214_WriteData(P2VAR(Dcm_20Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0214_WriteData RE_CT_DiagnosticsApplDidServices_0x0214_WriteData
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0215_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0215_ConditionCheckRead RE_CT_DiagnosticsApplDidServices_0x0215_ConditionCheckRead
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0215_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0215_ReadData(P2VAR(Dcm_6Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0215_ReadData RE_CT_DiagnosticsApplDidServices_0x0215_ReadData
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0216_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0216_ConditionCheckRead RE_CT_DiagnosticsApplDidServices_0x0216_ConditionCheckRead
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0216_ConditionCheckWrite(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0216_ConditionCheckWrite RE_CT_DiagnosticsApplDidServices_0x0216_ConditionCheckWrite
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0216_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0216_ReadData(P2VAR(Dcm_15Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0216_ReadData RE_CT_DiagnosticsApplDidServices_0x0216_ReadData
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0216_WriteData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0216_WriteData(P2VAR(Dcm_15Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0216_WriteData RE_CT_DiagnosticsApplDidServices_0x0216_WriteData
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0217_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0217_ConditionCheckRead RE_CT_DiagnosticsApplDidServices_0x0217_ConditionCheckRead
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0217_ConditionCheckWrite(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0217_ConditionCheckWrite RE_CT_DiagnosticsApplDidServices_0x0217_ConditionCheckWrite
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0217_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0217_ReadData(P2VAR(Dcm_16Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0217_ReadData RE_CT_DiagnosticsApplDidServices_0x0217_ReadData
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0217_WriteData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0217_WriteData(P2VAR(Dcm_16Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0217_WriteData RE_CT_DiagnosticsApplDidServices_0x0217_WriteData


//REMARK Andreas Gilch: Add manually
// DID 218:
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0218_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0218_ConditionCheckRead RE_CT_DiagnosticsApplDidServices_0x0218_ConditionCheckRead
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0218_ConditionCheckWrite(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0218_ConditionCheckWrite RE_CT_DiagnosticsApplDidServices_0x0218_ConditionCheckWrite
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0218_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0218_ReadData(P2VAR(Dcm_42Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0218_ReadData RE_CT_DiagnosticsApplDidServices_0x0218_ReadData
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0218_WriteData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0218_WriteData(P2VAR(Dcm_42Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0218_WriteData RE_CT_DiagnosticsApplDidServices_0x0218_WriteData


// DID 219:
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0219_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0219_ConditionCheckRead RE_CT_DiagnosticsApplDidServices_0x0219_ConditionCheckRead
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0219_ConditionCheckWrite(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0219_ConditionCheckWrite RE_CT_DiagnosticsApplDidServices_0x0219_ConditionCheckWrite
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0219_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0219_ReadData(P2VAR(Dcm_50Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0219_ReadData RE_CT_DiagnosticsApplDidServices_0x0219_ReadData
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0219_WriteData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0219_WriteData(P2VAR(Dcm_50Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0219_WriteData RE_CT_DiagnosticsApplDidServices_0x0219_WriteData



// DID 230:
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0230_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0230_ConditionCheckRead RE_CT_DiagnosticsApplDidServices_0x0230_ConditionCheckRead
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0230_ConditionCheckWrite(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0230_ConditionCheckWrite RE_CT_DiagnosticsApplDidServices_0x0230_ConditionCheckWrite
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0230_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0230_ReadData(P2VAR(Dcm_12Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0230_ReadData RE_CT_DiagnosticsApplDidServices_0x0230_ReadData
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0230_WriteData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0230_WriteData(P2VAR(Dcm_12Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0230_WriteData RE_CT_DiagnosticsApplDidServices_0x0230_WriteData



// DID 231:
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0231_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0231_ConditionCheckRead RE_CT_DiagnosticsApplDidServices_0x0231_ConditionCheckRead
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0231_ConditionCheckWrite(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0231_ConditionCheckWrite RE_CT_DiagnosticsApplDidServices_0x0231_ConditionCheckWrite
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0231_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0231_ReadData(P2VAR(Dcm_16Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0231_ReadData RE_CT_DiagnosticsApplDidServices_0x0231_ReadData
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0231_WriteData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0231_WriteData(P2VAR(Dcm_16Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0231_WriteData RE_CT_DiagnosticsApplDidServices_0x0231_WriteData



// DID 232:
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0232_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0232_ConditionCheckRead RE_CT_DiagnosticsApplDidServices_0x0232_ConditionCheckRead
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0232_ConditionCheckWrite(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0232_ConditionCheckWrite RE_CT_DiagnosticsApplDidServices_0x0232_ConditionCheckWrite
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0232_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0232_ReadData(P2VAR(Dcm_24Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0232_ReadData RE_CT_DiagnosticsApplDidServices_0x0232_ReadData
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0232_WriteData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0232_WriteData(P2VAR(Dcm_24Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0232_WriteData RE_CT_DiagnosticsApplDidServices_0x0232_WriteData



// DID 233:
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0233_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0233_ConditionCheckRead RE_CT_DiagnosticsApplDidServices_0x0233_ConditionCheckRead
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0233_ConditionCheckWrite(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0233_ConditionCheckWrite RE_CT_DiagnosticsApplDidServices_0x0233_ConditionCheckWrite
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0233_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0233_ReadData(P2VAR(Dcm_34Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0233_ReadData RE_CT_DiagnosticsApplDidServices_0x0233_ReadData
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0233_WriteData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0233_WriteData(P2VAR(Dcm_34Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0233_WriteData RE_CT_DiagnosticsApplDidServices_0x0233_WriteData



// DID 234:
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0234_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0234_ConditionCheckRead RE_CT_DiagnosticsApplDidServices_0x0234_ConditionCheckRead
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0234_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0234_ReadData(P2VAR(Dcm_10Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0234_ReadData RE_CT_DiagnosticsApplDidServices_0x0234_ReadData



// DID 239:
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0239_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0239_ConditionCheckRead RE_CT_DiagnosticsApplDidServices_0x0239_ConditionCheckRead
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0239_ConditionCheckWrite(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0239_ConditionCheckWrite RE_CT_DiagnosticsApplDidServices_0x0239_ConditionCheckWrite
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0239_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0239_ReadData(P2VAR(Dcm_76Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0239_ReadData RE_CT_DiagnosticsApplDidServices_0x0239_ReadData
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0239_WriteData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0239_WriteData(P2VAR(Dcm_76Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0239_WriteData RE_CT_DiagnosticsApplDidServices_0x0239_WriteData



// DID 290:
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0290_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0290_ConditionCheckRead RE_CT_DiagnosticsApplDidServices_0x0290_ConditionCheckRead
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0290_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0290_ReadData(P2VAR(Dcm_11Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0290_ReadData RE_CT_DiagnosticsApplDidServices_0x0290_ReadData



// DID 291:
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0291_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0291_ConditionCheckRead RE_CT_DiagnosticsApplDidServices_0x0291_ConditionCheckRead
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0291_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0291_ReadData(P2VAR(Dcm_11Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0291_ReadData RE_CT_DiagnosticsApplDidServices_0x0291_ReadData



//REMARK Andreas Gilch: END of "Add manually"


#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0236_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0236_ConditionCheckRead RE_CT_DiagnosticsApplDidServices_0x0236_ConditionCheckRead
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0236_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0236_ReadData(P2VAR(Dcm_8Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0236_ReadData RE_CT_DiagnosticsApplDidServices_0x0236_ReadData
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0238_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0238_ConditionCheckRead RE_CT_DiagnosticsApplDidServices_0x0238_ConditionCheckRead
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0238_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0238_ReadData(P2VAR(Dcm_38Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"


/*Start of 0x0240*/
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0240_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0240_ConditionCheckRead RE_CT_DiagnosticsApplDidServices_0x0240_ConditionCheckRead
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0240_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0240_ReadData(P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0240_ReadData RE_CT_DiagnosticsApplDidServices_0x0240_ReadData
/*End of 0x0240*/


#  define Rte_Call_DidServices_0x0238_ReadData RE_CT_DiagnosticsApplDidServices_0x0238_ReadData
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0242_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0242_ConditionCheckRead RE_CT_DiagnosticsApplDidServices_0x0242_ConditionCheckRead
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0242_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0242_ReadData(P2VAR(Dcm_2Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0242_ReadData RE_CT_DiagnosticsApplDidServices_0x0242_ReadData

/* START manual code */
/* DID 0x0243 */
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0243_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0243_ConditionCheckRead RE_CT_DiagnosticsApplDidServices_0x0243_ConditionCheckRead
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0243_ConditionCheckWrite(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0243_ConditionCheckWrite RE_CT_DiagnosticsApplDidServices_0x0243_ConditionCheckWrite
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0243_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0243_ReadData(P2VAR(Dcm_67Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0243_ReadData RE_CT_DiagnosticsApplDidServices_0x0243_ReadData
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0243_WriteData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0243_WriteData(P2VAR(Dcm_67Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0243_WriteData RE_CT_DiagnosticsApplDidServices_0x0243_WriteData


/* DID 0x0244 */
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0244_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0244_ConditionCheckRead RE_CT_DiagnosticsApplDidServices_0x0244_ConditionCheckRead
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0244_ConditionCheckWrite(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0244_ConditionCheckWrite RE_CT_DiagnosticsApplDidServices_0x0244_ConditionCheckWrite
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0244_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0244_ReadData(P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0244_ReadData RE_CT_DiagnosticsApplDidServices_0x0244_ReadData
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0244_WriteData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0244_WriteData(P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0244_WriteData RE_CT_DiagnosticsApplDidServices_0x0244_WriteData

/* END manual code */

/*Start of 0x0245*/

/* DID 0x0245 */
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0245_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0245_ConditionCheckRead RE_CT_DiagnosticsApplDidServices_0x0245_ConditionCheckRead
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0245_ConditionCheckWrite(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0245_ConditionCheckWrite RE_CT_DiagnosticsApplDidServices_0x0245_ConditionCheckWrite
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0245_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0245_ReadData(P2VAR(Dcm_452Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0245_ReadData RE_CT_DiagnosticsApplDidServices_0x0245_ReadData
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0245_WriteData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0245_WriteData(P2VAR(Dcm_452Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0245_WriteData RE_CT_DiagnosticsApplDidServices_0x0245_WriteData

/*End of 0x0245*/


/*Start of 0x0246*/

#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0246_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0246_ConditionCheckRead RE_CT_DiagnosticsApplDidServices_0x0246_ConditionCheckRead
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0246_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0246_ReadData(P2VAR(Dcm_20Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0246_ReadData RE_CT_DiagnosticsApplDidServices_0x0246_ReadData

/*End of 0x0246*/

/* DID 0x0247 */
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0247_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0247_ConditionCheckRead RE_CT_DiagnosticsApplDidServices_0x0247_ConditionCheckRead
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0247_ConditionCheckWrite(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0247_ConditionCheckWrite RE_CT_DiagnosticsApplDidServices_0x0247_ConditionCheckWrite
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0247_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0247_ReadData(P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0247_ReadData RE_CT_DiagnosticsApplDidServices_0x0247_ReadData
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0247_WriteData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0247_WriteData(P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0247_WriteData RE_CT_DiagnosticsApplDidServices_0x0247_WriteData

/* END manual code 0x0247*/

/* DID 0x0248 */
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0248_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0248_ConditionCheckRead RE_CT_DiagnosticsApplDidServices_0x0248_ConditionCheckRead
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0248_ConditionCheckWrite(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0248_ConditionCheckWrite RE_CT_DiagnosticsApplDidServices_0x0248_ConditionCheckWrite
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0248_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0248_ReadData(P2VAR(Dcm_8Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0248_ReadData RE_CT_DiagnosticsApplDidServices_0x0248_ReadData
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0248_WriteData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0248_WriteData(P2VAR(Dcm_8Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0248_WriteData RE_CT_DiagnosticsApplDidServices_0x0248_WriteData

/* END manual code 0x0248*/


#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0260_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0260_ConditionCheckRead RE_CT_DiagnosticsApplDidServices_0x0260_ConditionCheckRead
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0260_ConditionCheckWrite(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0260_ConditionCheckWrite RE_CT_DiagnosticsApplDidServices_0x0260_ConditionCheckWrite
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0260_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0260_ReadData(P2VAR(Dcm_61Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0260_ReadData RE_CT_DiagnosticsApplDidServices_0x0260_ReadData
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0260_WriteData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0260_WriteData(P2VAR(Dcm_61Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0260_WriteData RE_CT_DiagnosticsApplDidServices_0x0260_WriteData
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0261_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0261_ConditionCheckRead RE_CT_DiagnosticsApplDidServices_0x0261_ConditionCheckRead
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0261_ConditionCheckWrite(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0261_ConditionCheckWrite RE_CT_DiagnosticsApplDidServices_0x0261_ConditionCheckWrite
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0261_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0261_ReadData(P2VAR(Dcm_61Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0261_ReadData RE_CT_DiagnosticsApplDidServices_0x0261_ReadData
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0261_WriteData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0261_WriteData(P2VAR(Dcm_61Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0261_WriteData RE_CT_DiagnosticsApplDidServices_0x0261_WriteData
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0262_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0262_ConditionCheckRead RE_CT_DiagnosticsApplDidServices_0x0262_ConditionCheckRead
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0262_ConditionCheckWrite(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0262_ConditionCheckWrite RE_CT_DiagnosticsApplDidServices_0x0262_ConditionCheckWrite
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0262_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0262_ReadData(P2VAR(Dcm_57Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0262_ReadData RE_CT_DiagnosticsApplDidServices_0x0262_ReadData
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0262_WriteData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0262_WriteData(P2VAR(Dcm_57Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0262_WriteData RE_CT_DiagnosticsApplDidServices_0x0262_WriteData
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0263_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0263_ConditionCheckRead RE_CT_DiagnosticsApplDidServices_0x0263_ConditionCheckRead
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0263_ConditionCheckWrite(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0263_ConditionCheckWrite RE_CT_DiagnosticsApplDidServices_0x0263_ConditionCheckWrite
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0263_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0263_ReadData(P2VAR(Dcm_24Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0263_ReadData RE_CT_DiagnosticsApplDidServices_0x0263_ReadData
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0263_WriteData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0263_WriteData(P2VAR(Dcm_24Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0263_WriteData RE_CT_DiagnosticsApplDidServices_0x0263_WriteData
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0266_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0266_ConditionCheckRead RE_CT_DiagnosticsApplDidServices_0x0266_ConditionCheckRead
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0266_ConditionCheckWrite(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0266_ConditionCheckWrite RE_CT_DiagnosticsApplDidServices_0x0266_ConditionCheckWrite
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0266_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0266_ReadData(P2VAR(Dcm_14Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0266_ReadData RE_CT_DiagnosticsApplDidServices_0x0266_ReadData
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0266_WriteData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0266_WriteData(P2VAR(Dcm_14Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0266_WriteData RE_CT_DiagnosticsApplDidServices_0x0266_WriteData
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0271_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0271_ConditionCheckRead RE_CT_DiagnosticsApplDidServices_0x0271_ConditionCheckRead
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0271_ConditionCheckWrite(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0271_ConditionCheckWrite RE_CT_DiagnosticsApplDidServices_0x0271_ConditionCheckWrite
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0271_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0271_ReadData(P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0271_ReadData RE_CT_DiagnosticsApplDidServices_0x0271_ReadData
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0271_WriteData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0271_WriteData(P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0271_WriteData RE_CT_DiagnosticsApplDidServices_0x0271_WriteData
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0272_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0272_ConditionCheckRead RE_CT_DiagnosticsApplDidServices_0x0272_ConditionCheckRead
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0272_ConditionCheckWrite(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0272_ConditionCheckWrite RE_CT_DiagnosticsApplDidServices_0x0272_ConditionCheckWrite
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0272_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0272_ReadData(P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0272_ReadData RE_CT_DiagnosticsApplDidServices_0x0272_ReadData
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0272_WriteData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0272_WriteData(P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0272_WriteData RE_CT_DiagnosticsApplDidServices_0x0272_WriteData
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0273_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0273_ConditionCheckRead RE_CT_DiagnosticsApplDidServices_0x0273_ConditionCheckRead
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0273_ConditionCheckWrite(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0274_ConditionCheckRead RE_CT_DiagnosticsApplDidServices_0x0274_ConditionCheckRead
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0274_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0274_ConditionCheckWrite RE_CT_DiagnosticsApplDidServices_0x0274_ConditionCheckWrite
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0274_ConditionCheckWrite(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0274_ReadData RE_CT_DiagnosticsApplDidServices_0x0274_ReadData
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0274_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0274_ReadData(P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0274_WriteData RE_CT_DiagnosticsApplDidServices_0x0274_WriteData
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0274_WriteData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0274_WriteData(P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0273_ConditionCheckWrite RE_CT_DiagnosticsApplDidServices_0x0273_ConditionCheckWrite
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0273_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0273_ReadData(P2VAR(Dcm_4Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0273_ReadData RE_CT_DiagnosticsApplDidServices_0x0273_ReadData
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0273_WriteData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0273_WriteData(P2VAR(Dcm_4Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0273_WriteData RE_CT_DiagnosticsApplDidServices_0x0273_WriteData
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0280_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0280_ConditionCheckRead RE_CT_DiagnosticsApplDidServices_0x0280_ConditionCheckRead
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0280_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0280_ReadData(P2VAR(Dcm_4Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0280_ReadData RE_CT_DiagnosticsApplDidServices_0x0280_ReadData
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0281_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0281_ConditionCheckRead RE_CT_DiagnosticsApplDidServices_0x0281_ConditionCheckRead
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0281_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0281_ReadData(P2VAR(Dcm_2Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0281_ReadData RE_CT_DiagnosticsApplDidServices_0x0281_ReadData
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0282_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0282_ConditionCheckRead RE_CT_DiagnosticsApplDidServices_0x0282_ConditionCheckRead
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0282_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0282_ReadData(P2VAR(Dcm_2Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0282_ReadData RE_CT_DiagnosticsApplDidServices_0x0282_ReadData
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0283_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0283_ConditionCheckRead RE_CT_DiagnosticsApplDidServices_0x0283_ConditionCheckRead
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0283_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0283_ReadData(P2VAR(Dcm_12Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0283_ReadData RE_CT_DiagnosticsApplDidServices_0x0283_ReadData
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0284_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0284_ConditionCheckRead RE_CT_DiagnosticsApplDidServices_0x0284_ConditionCheckRead
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0284_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0284_ReadData(P2VAR(Dcm_12Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0284_ReadData RE_CT_DiagnosticsApplDidServices_0x0284_ReadData
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02a0_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x02a0_ConditionCheckRead RE_CT_DiagnosticsApplDidServices_0x02a0_ConditionCheckRead
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02a0_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02a0_ReadData(P2VAR(Dcm_26Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x02a0_ReadData RE_CT_DiagnosticsApplDidServices_0x02a0_ReadData
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02a1_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x02a1_ConditionCheckRead RE_CT_DiagnosticsApplDidServices_0x02a1_ConditionCheckRead
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02a1_ConditionCheckWrite(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x02a1_ConditionCheckWrite RE_CT_DiagnosticsApplDidServices_0x02a1_ConditionCheckWrite
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02a1_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02a1_ReadData(P2VAR(Dcm_14Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x02a1_ReadData RE_CT_DiagnosticsApplDidServices_0x02a1_ReadData
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02a1_WriteData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02a1_WriteData(P2VAR(Dcm_14Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x02a1_WriteData RE_CT_DiagnosticsApplDidServices_0x02a1_WriteData


/*Start of 0x02a2*/
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02a2_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x02a2_ConditionCheckRead RE_CT_DiagnosticsApplDidServices_0x02a2_ConditionCheckRead
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02a2_ConditionCheckWrite(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x02a2_ConditionCheckWrite RE_CT_DiagnosticsApplDidServices_0x02a2_ConditionCheckWrite
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02a2_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02a2_ReadData(P2VAR(Dcm_5Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x02a2_ReadData RE_CT_DiagnosticsApplDidServices_0x02a2_ReadData
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02a2_WriteData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02a2_WriteData(P2VAR(Dcm_5Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x02a2_WriteData RE_CT_DiagnosticsApplDidServices_0x02a2_WriteData
/*End of 0x02a2*/


/*Start of 0x02a3*/
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02a3_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x02a3_ConditionCheckRead RE_CT_DiagnosticsApplDidServices_0x02a3_ConditionCheckRead
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02a3_ConditionCheckWrite(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x02a3_ConditionCheckWrite RE_CT_DiagnosticsApplDidServices_0x02a3_ConditionCheckWrite
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02a3_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02a3_ReadData(P2VAR(Dcm_2Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x02a3_ReadData RE_CT_DiagnosticsApplDidServices_0x02a3_ReadData
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02a3_WriteData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02a3_WriteData(P2VAR(Dcm_2Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x02a3_WriteData RE_CT_DiagnosticsApplDidServices_0x02a3_WriteData
/*End of 0x02a3*/


/*Start of 0x02a4*/
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02a4_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x02a4_ConditionCheckRead RE_CT_DiagnosticsApplDidServices_0x02a4_ConditionCheckRead
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02a4_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02a4_ReadData(P2VAR(Dcm_632Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x02a4_ReadData RE_CT_DiagnosticsApplDidServices_0x02a4_ReadData
/*End of 0x02a4*/


/*Start of 0x02a5*/
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02a5_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x02a5_ConditionCheckRead RE_CT_DiagnosticsApplDidServices_0x02a5_ConditionCheckRead
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02a5_ConditionCheckWrite(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x02a5_ConditionCheckWrite RE_CT_DiagnosticsApplDidServices_0x02a5_ConditionCheckWrite
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02a5_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02a5_ReadData(P2VAR(Dcm_164Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x02a5_ReadData RE_CT_DiagnosticsApplDidServices_0x02a5_ReadData
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02a5_WriteData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02a5_WriteData(P2VAR(Dcm_164Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x02a5_WriteData RE_CT_DiagnosticsApplDidServices_0x02a5_WriteData
/*End of 0x02a5*/


/*Start of 0x02a6*/
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02a6_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x02a6_ConditionCheckRead RE_CT_DiagnosticsApplDidServices_0x02a6_ConditionCheckRead
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02a6_ConditionCheckWrite(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x02a6_ConditionCheckWrite RE_CT_DiagnosticsApplDidServices_0x02a6_ConditionCheckWrite
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02a6_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02a6_ReadData(P2VAR(Dcm_8Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x02a6_ReadData RE_CT_DiagnosticsApplDidServices_0x02a6_ReadData
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02a6_WriteData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02a6_WriteData(P2VAR(Dcm_8Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x02a6_WriteData RE_CT_DiagnosticsApplDidServices_0x02a6_WriteData
/*End of 0x02a6*/


/*Start of 0x02a7*/
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02a7_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x02a7_ConditionCheckRead RE_CT_DiagnosticsApplDidServices_0x02a7_ConditionCheckRead
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02a7_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02a7_ReadData(P2VAR(Dcm_100Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x02a7_ReadData RE_CT_DiagnosticsApplDidServices_0x02a7_ReadData
/*End of 0x02a7*/


/*Start of 0x02a8*/
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02a8_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x02a8_ConditionCheckRead RE_CT_DiagnosticsApplDidServices_0x02a8_ConditionCheckRead
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02a8_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02a8_ReadData(P2VAR(Dcm_100Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x02a8_ReadData RE_CT_DiagnosticsApplDidServices_0x02a8_ReadData
/*End of 0x02a8*/

/*Start of 0x02a9*/
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02a9_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x02a9_ConditionCheckRead RE_CT_DiagnosticsApplDidServices_0x02a9_ConditionCheckRead
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02a9_ConditionCheckWrite(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x02a9_ConditionCheckWrite RE_CT_DiagnosticsApplDidServices_0x02a9_ConditionCheckWrite
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02a9_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02a9_ReadData(P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x02a9_ReadData RE_CT_DiagnosticsApplDidServices_0x02a9_ReadData
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02a9_WriteData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02a9_WriteData(P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x02a9_WriteData RE_CT_DiagnosticsApplDidServices_0x02a9_WriteData
/*End of 0x02a9*/

/*Start of 0x02aa*/
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02aa_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x02aa_ConditionCheckRead RE_CT_DiagnosticsApplDidServices_0x02aa_ConditionCheckRead
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02aa_ConditionCheckWrite(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x02aa_ConditionCheckWrite RE_CT_DiagnosticsApplDidServices_0x02aa_ConditionCheckWrite
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02aa_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02aa_ReadData(P2VAR(Dcm_460Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x02aa_ReadData RE_CT_DiagnosticsApplDidServices_0x02aa_ReadData
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02aa_WriteData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02aa_WriteData(P2VAR(Dcm_460Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x02aa_WriteData RE_CT_DiagnosticsApplDidServices_0x02aa_WriteData
/*End of 0x02aa*/

/*Start of 0x02ab*/
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02ab_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x02ab_ConditionCheckRead RE_CT_DiagnosticsApplDidServices_0x02ab_ConditionCheckRead
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02ab_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02ab_ReadData(P2VAR(Dcm_256Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x02ab_ReadData RE_CT_DiagnosticsApplDidServices_0x02ab_ReadData
/*End of 0x02ab*/


/*Start of 0x02ac*/
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02ac_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x02ac_ConditionCheckRead RE_CT_DiagnosticsApplDidServices_0x02ac_ConditionCheckRead
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02ac_ConditionCheckWrite(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x02ac_ConditionCheckWrite RE_CT_DiagnosticsApplDidServices_0x02ac_ConditionCheckWrite
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02ac_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02ac_ReadData(P2VAR(Dcm_4Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x02ac_ReadData RE_CT_DiagnosticsApplDidServices_0x02ac_ReadData
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02ac_WriteData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02ac_WriteData(P2VAR(Dcm_4Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x02ac_WriteData RE_CT_DiagnosticsApplDidServices_0x02ac_WriteData
/*End of 0x02ac*/


#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02b0_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
#  define Rte_Call_DidServices_0x02b0_ConditionCheckRead RE_CT_DiagnosticsApplDidServices_0x02b0_ConditionCheckRead

#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02b0_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x02b0_ReadData(P2VAR(Dcm_10Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
#  define Rte_Call_DidServices_0x02b0_ReadData RE_CT_DiagnosticsApplDidServices_0x02b0_ReadData

#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0380_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0380_ConditionCheckRead RE_CT_DiagnosticsApplDidServices_0x0380_ConditionCheckRead
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0380_ConditionCheckWrite(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0380_ConditionCheckWrite RE_CT_DiagnosticsApplDidServices_0x0380_ConditionCheckWrite
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0380_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0380_ReadData(P2VAR(Dcm_53Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0380_ReadData RE_CT_DiagnosticsApplDidServices_0x0380_ReadData
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0380_WriteData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0380_WriteData(P2VAR(Dcm_53Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0380_WriteData RE_CT_DiagnosticsApplDidServices_0x0380_WriteData
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0381_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0381_ConditionCheckRead RE_CT_DiagnosticsApplDidServices_0x0381_ConditionCheckRead
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0381_ConditionCheckWrite(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0381_ConditionCheckWrite RE_CT_DiagnosticsApplDidServices_0x0381_ConditionCheckWrite
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0381_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0381_ReadData(P2VAR(Dcm_50Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0381_ReadData RE_CT_DiagnosticsApplDidServices_0x0381_ReadData
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0381_WriteData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0381_WriteData(P2VAR(Dcm_50Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0381_WriteData RE_CT_DiagnosticsApplDidServices_0x0381_WriteData
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0382_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0382_ConditionCheckRead RE_CT_DiagnosticsApplDidServices_0x0382_ConditionCheckRead
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0382_ConditionCheckWrite(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0382_ConditionCheckWrite RE_CT_DiagnosticsApplDidServices_0x0382_ConditionCheckWrite
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0382_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0382_ReadData(P2VAR(Dcm_9Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0382_ReadData RE_CT_DiagnosticsApplDidServices_0x0382_ReadData
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0382_WriteData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0382_WriteData(P2VAR(Dcm_9Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0382_WriteData RE_CT_DiagnosticsApplDidServices_0x0382_WriteData
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0383_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0383_ConditionCheckRead RE_CT_DiagnosticsApplDidServices_0x0383_ConditionCheckRead
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0383_ConditionCheckWrite(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0383_ConditionCheckWrite RE_CT_DiagnosticsApplDidServices_0x0383_ConditionCheckWrite
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0383_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0383_ReadData(P2VAR(Dcm_26Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0383_ReadData RE_CT_DiagnosticsApplDidServices_0x0383_ReadData
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0383_WriteData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0383_WriteData(P2VAR(Dcm_26Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0383_WriteData RE_CT_DiagnosticsApplDidServices_0x0383_WriteData
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0384_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0384_ConditionCheckRead RE_CT_DiagnosticsApplDidServices_0x0384_ConditionCheckRead
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0384_ConditionCheckWrite(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0384_ConditionCheckWrite RE_CT_DiagnosticsApplDidServices_0x0384_ConditionCheckWrite
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0384_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0384_ReadData(P2VAR(Dcm_24Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0384_ReadData RE_CT_DiagnosticsApplDidServices_0x0384_ReadData
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0384_WriteData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0x0384_WriteData(P2VAR(Dcm_24Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data, UInt16 dataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0x0384_WriteData RE_CT_DiagnosticsApplDidServices_0x0384_WriteData
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0xd000_ReturnControlToECU(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0xd000_ReturnControlToECU(P2VAR(Dcm_0Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(Dcm_0Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xd000_ReturnControlToECU RE_CT_DiagnosticsApplDidServices_0xd000_ReturnControlToECU
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0xd000_ShortTermAdjustment(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0xd000_ShortTermAdjustment(P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(Dcm_0Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xd000_ShortTermAdjustment RE_CT_DiagnosticsApplDidServices_0xd000_ShortTermAdjustment

/* REMARK Andreas Gilch: Removed from cdd.
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0xef02_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xef02_ConditionCheckRead RE_CT_DiagnosticsApplDidServices_0xef02_ConditionCheckRead
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0xef02_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0xef02_ReadData(P2VAR(Dcm_8Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xef02_ReadData RE_CT_DiagnosticsApplDidServices_0xef02_ReadData
*/

#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0xef03_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xef03_ConditionCheckRead RE_CT_DiagnosticsApplDidServices_0xef03_ConditionCheckRead
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0xef03_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0xef03_ReadData(P2VAR(Dcm_8Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xef03_ReadData RE_CT_DiagnosticsApplDidServices_0xef03_ReadData
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0xf100_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xf100_ConditionCheckRead RE_CT_DiagnosticsApplDidServices_0xf100_ConditionCheckRead
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0xf100_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0xf100_ReadData(P2VAR(Dcm_4Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xf100_ReadData RE_CT_DiagnosticsApplDidServices_0xf100_ReadData
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0xf10d_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xf10d_ConditionCheckRead RE_CT_DiagnosticsApplDidServices_0xf10d_ConditionCheckRead
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0xf10d_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0xf10d_ReadData(P2VAR(Dcm_3Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xf10d_ReadData RE_CT_DiagnosticsApplDidServices_0xf10d_ReadData
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0xf170_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xf170_ConditionCheckRead RE_CT_DiagnosticsApplDidServices_0xf170_ConditionCheckRead
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0xf170_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0xf170_ReadData(P2VAR(Dcm_20Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xf170_ReadData RE_CT_DiagnosticsApplDidServices_0xf170_ReadData
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0xf18c_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xf18c_ConditionCheckRead RE_CT_DiagnosticsApplDidServices_0xf18c_ConditionCheckRead
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0xf18c_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0xf18c_ReadData(P2VAR(Dcm_13Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xf18c_ReadData RE_CT_DiagnosticsApplDidServices_0xf18c_ReadData
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0xf195_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xf195_ConditionCheckRead RE_CT_DiagnosticsApplDidServices_0xf195_ConditionCheckRead
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0xf195_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0xf195_ReadData(P2VAR(Dcm_60Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xf195_ReadData RE_CT_DiagnosticsApplDidServices_0xf195_ReadData
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0xf1a2_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xf1a2_ConditionCheckRead RE_CT_DiagnosticsApplDidServices_0xf1a2_ConditionCheckRead
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0xf1a2_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0xf1a2_ReadData(P2VAR(Dcm_2Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xf1a2_ReadData RE_CT_DiagnosticsApplDidServices_0xf1a2_ReadData
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0xf1a3_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xf1a3_ConditionCheckRead RE_CT_DiagnosticsApplDidServices_0xf1a3_ConditionCheckRead
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0xf1a3_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0xf1a3_ReadData(P2VAR(Dcm_2Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xf1a3_ReadData RE_CT_DiagnosticsApplDidServices_0xf1a3_ReadData
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0xf1a5_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xf1a5_ConditionCheckRead RE_CT_DiagnosticsApplDidServices_0xf1a5_ConditionCheckRead
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0xf1a5_ReadData(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplDidServices_0xf1a5_ReadData(P2VAR(Dcm_2Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) data);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DidServices_0xf1a5_ReadData RE_CT_DiagnosticsApplDidServices_0xf1a5_ReadData
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplPassiveModeService_CheckCondition(void);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_PassiveModeService_CheckCondition RE_CT_DiagnosticsApplPassiveModeService_CheckCondition
#  define Rte_Call_PassiveModeService_OnChange Rte_Call_Dcm_PassiveModeService_OnChange
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplResetService_EcuReset(UInt8 resetType, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_ResetService_EcuReset RE_CT_DiagnosticsApplResetService_EcuReset
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0201_Start(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0201_Start(P2VAR(Dcm_0Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(Dcm_0Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_RoutineServices_0x0201_Start RE_CT_DiagnosticsApplRoutineServices_0x0201_Start
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0300_RequestResults(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0300_RequestResults(P2VAR(Dcm_0Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(Dcm_62Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_RoutineServices_0x0300_RequestResults RE_CT_DiagnosticsApplRoutineServices_0x0300_RequestResults
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0300_Start(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0300_Start(P2VAR(Dcm_13Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_RoutineServices_0x0300_Start RE_CT_DiagnosticsApplRoutineServices_0x0300_Start
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0301_RequestResults(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0301_RequestResults(P2VAR(Dcm_0Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(Dcm_62Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_RoutineServices_0x0301_RequestResults RE_CT_DiagnosticsApplRoutineServices_0x0301_RequestResults
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0301_Start(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0301_Start(P2VAR(Dcm_21Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_RoutineServices_0x0301_Start RE_CT_DiagnosticsApplRoutineServices_0x0301_Start
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0303_RequestResults(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0303_RequestResults(P2VAR(Dcm_0Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(Dcm_110Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_RoutineServices_0x0303_RequestResults RE_CT_DiagnosticsApplRoutineServices_0x0303_RequestResults
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0303_Start(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0303_Start(P2VAR(Dcm_21Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_RoutineServices_0x0303_Start RE_CT_DiagnosticsApplRoutineServices_0x0303_Start
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0304_RequestResults(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0304_RequestResults(P2VAR(Dcm_0Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(Dcm_42Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_RoutineServices_0x0304_RequestResults RE_CT_DiagnosticsApplRoutineServices_0x0304_RequestResults
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0304_Start(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0304_Start(P2VAR(Dcm_0Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_RoutineServices_0x0304_Start RE_CT_DiagnosticsApplRoutineServices_0x0304_Start


/*Start of 0x0305_Start*/
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0305_Start(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0305_Start(P2VAR(Dcm_0Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_RoutineServices_0x0305_Start RE_CT_DiagnosticsApplRoutineServices_0x0305_Start
/*End of 0x0305_Start*/


/*Start of 0x0306_Start*/
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0306_Start(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0306_Start(P2VAR(Dcm_36Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_RoutineServices_0x0306_Start RE_CT_DiagnosticsApplRoutineServices_0x0306_Start
/*End of 0x0306_Start*/


/*Start of 0x0306_RequestResults*/
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0306_RequestResults(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0306_RequestResults(P2VAR(Dcm_0Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(Dcm_60Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_RoutineServices_0x0306_RequestResults RE_CT_DiagnosticsApplRoutineServices_0x0306_RequestResults
/*End of 0x0306_RequestResults*/




#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0310_Start(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0310_Start(P2VAR(Dcm_0Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_RoutineServices_0x0310_Start RE_CT_DiagnosticsApplRoutineServices_0x0310_Start


/*Start of 0x0312_Start*/
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0312_Start(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0312_Start(P2VAR(Dcm_0Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_RoutineServices_0x0312_Start RE_CT_DiagnosticsApplRoutineServices_0x0312_Start
/*End of 0x0312_Start*/


/*Start of 0x0320_Start*/
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0320_Start(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0320_Start(P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_RoutineServices_0x0320_Start RE_CT_DiagnosticsApplRoutineServices_0x0320_Start
/*End of 0x0320_Start*/


#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0321_Start(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0321_Start(P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_RoutineServices_0x0321_Start RE_CT_DiagnosticsApplRoutineServices_0x0321_Start
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0321_Stop(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0321_Stop(P2VAR(Dcm_0Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_RoutineServices_0x0321_Stop RE_CT_DiagnosticsApplRoutineServices_0x0321_Stop
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0325_Start(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0325_Start(P2VAR(Dcm_4Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_RoutineServices_0x0325_Start RE_CT_DiagnosticsApplRoutineServices_0x0325_Start
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0330_RequestResults(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0330_RequestResults(P2VAR(Dcm_0Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_RoutineServices_0x0330_RequestResults RE_CT_DiagnosticsApplRoutineServices_0x0330_RequestResults
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0330_Start(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0330_Start(P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_RoutineServices_0x0330_Start RE_CT_DiagnosticsApplRoutineServices_0x0330_Start
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0330_Stop(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0330_Stop(P2VAR(Dcm_0Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(Dcm_0Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_RoutineServices_0x0330_Stop RE_CT_DiagnosticsApplRoutineServices_0x0330_Stop


/*Start of 0x0332_Start*/
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0332_Start(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0332_Start(P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_RoutineServices_0x0332_Start RE_CT_DiagnosticsApplRoutineServices_0x0332_Start
/*End of 0x0332_Start*/


/*Start of 0x0332_Stop*/
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0332_Stop(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0332_Stop(P2VAR(Dcm_0Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(Dcm_0Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_RoutineServices_0x0332_Stop RE_CT_DiagnosticsApplRoutineServices_0x0332_Stop
/*End of 0x0332_Stop*/


/*Start of 0x0332_RequestResults*/
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0332_RequestResults(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0332_RequestResults(P2VAR(Dcm_0Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_RoutineServices_0x0332_RequestResults RE_CT_DiagnosticsApplRoutineServices_0x0332_RequestResults
/*End of 0x0332_RequestResults*/


/*Start of 0x0333_Start*/
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0333_Start(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0333_Start(P2VAR(Dcm_0Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(Dcm_0Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_RoutineServices_0x0333_Start RE_CT_DiagnosticsApplRoutineServices_0x0333_Start
/*End of 0x0333_Start*/


/*Start of 0x0334_Start*/
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0334_Start(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0334_Start(P2VAR(Dcm_0Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_RoutineServices_0x0334_Start RE_CT_DiagnosticsApplRoutineServices_0x0334_Start
/*End of 0x0334_Start*/


/*Start of 0x0340_Start*/
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0340_Start(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0340_Start(P2VAR(Dcm_0Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_RoutineServices_0x0340_Start RE_CT_DiagnosticsApplRoutineServices_0x0340_Start
/*End of 0x0340_Start*/


/*Start of 0x0341_Start*/
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0341_Start(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0341_Start(P2VAR(Dcm_0Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_RoutineServices_0x0341_Start RE_CT_DiagnosticsApplRoutineServices_0x0341_Start
/*End of 0x0341_Start*/


/*Start of 0x0342_Start*/
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0342_Start(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0342_Start(P2VAR(Dcm_0Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_RoutineServices_0x0342_Start RE_CT_DiagnosticsApplRoutineServices_0x0342_Start
/*End of 0x0342_Start*/


/*Start of 0x0350_Start*/
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0350_Start(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0350_Start(P2VAR(Dcm_0Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_RoutineServices_0x0350_Start RE_CT_DiagnosticsApplRoutineServices_0x0350_Start
/*End of 0x0350_Start*/


/*Start of 0x0352_Start*/
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0352_Start(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0352_Start(P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_RoutineServices_0x0352_Start RE_CT_DiagnosticsApplRoutineServices_0x0352_Start
/*End of 0x0352_Start*/


#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0354_Start(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0354_Start(P2VAR(Dcm_0Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
#  define Rte_Call_RoutineServices_0x0354_Start RE_CT_DiagnosticsApplRoutineServices_0x0354_Start

#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0355_Start(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0355_Start(P2VAR(Dcm_0Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
#  define Rte_Call_RoutineServices_0x0355_Start RE_CT_DiagnosticsApplRoutineServices_0x0355_Start

#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0356_Start(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0356_Start(P2VAR(Dcm_0Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
#  define Rte_Call_RoutineServices_0x0356_Start RE_CT_DiagnosticsApplRoutineServices_0x0356_Start

#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0357_Start(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0357_Start(P2VAR(Dcm_0Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(Dcm_1Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
#  define Rte_Call_RoutineServices_0x0357_Start RE_CT_DiagnosticsApplRoutineServices_0x0357_Start

#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0360_Start(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0360_Start(P2VAR(Dcm_2Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(Dcm_23Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
#  define Rte_Call_RoutineServices_0x0360_Start RE_CT_DiagnosticsApplRoutineServices_0x0360_Start


/*Start of 0x0361_Start*/
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0361_Start(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0361_Start(P2VAR(Dcm_0Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(Dcm_0Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_RoutineServices_0x0361_Start RE_CT_DiagnosticsApplRoutineServices_0x0361_Start
/*End of 0x0361_Start*/


/*Start of 0x0362_Start*/
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0362_Start(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0362_Start(P2VAR(Dcm_0Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(Dcm_9Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_RoutineServices_0x0362_Start RE_CT_DiagnosticsApplRoutineServices_0x0362_Start
/*End of 0x0362_Start*/


/*Start of 0x0363_Start*/
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0363_Start(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0363_Start(P2VAR(Dcm_0Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(Dcm_0Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_RoutineServices_0x0363_Start RE_CT_DiagnosticsApplRoutineServices_0x0363_Start
/*End of 0x0363_Start*/


/*Start of 0x0364_Start*/
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0364_Start(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0364_Start(P2VAR(Dcm_0Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(Dcm_0Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_RoutineServices_0x0364_Start RE_CT_DiagnosticsApplRoutineServices_0x0364_Start
/*End of 0x0364_Start*/


/*Start of 0x0365_Start*/
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0365_Start(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0365_Start(P2VAR(Dcm_0Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(Dcm_0Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_RoutineServices_0x0365_Start RE_CT_DiagnosticsApplRoutineServices_0x0365_Start
/*End of 0x0365_Start*/

/*Start of 0x0366_Start*/
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0366_Start(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0x0366_Start(P2VAR(Dcm_9Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(Dcm_512Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_RoutineServices_0x0366_Start RE_CT_DiagnosticsApplRoutineServices_0x0366_Start
/*End of 0x0365_Start*/

#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0xff03_Start(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplRoutineServices_0xff03_Start(P2VAR(Dcm_0Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) RequestData, UInt16 RequestDataLength, P2VAR(Dcm_2Byte_Type, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseData, P2VAR(UInt16, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ResponseDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
#  define Rte_Call_RoutineServices_0xff03_Start RE_CT_DiagnosticsApplRoutineServices_0xff03_Start

#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplSecurityAccess_1_CompareKey(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) Key);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplSecurityAccess_1_CompareKey(P2VAR(Dcm_SecAccess_1_KeyType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) Key);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
#  define Rte_Call_SecurityAccess_1_CompareKey RE_CT_DiagnosticsApplSecurityAccess_1_CompareKey

#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplSecurityAccess_1_GetSeed(P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) securityAccessDataRecord, P2VAR(UInt8, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) Seed, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# else
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplSecurityAccess_1_GetSeed(P2VAR(Dcm_SecAccess_1_DataRecType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) securityAccessDataRecord, P2VAR(Dcm_SecAccess_1_SeedType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) Seed, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_VAR) ErrorCode);
# endif
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_SecurityAccess_1_GetSeed RE_CT_DiagnosticsApplSecurityAccess_1_GetSeed
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplSessionControl_ChangeIndication(Dcm_SesCtrlType SesCtrlTypeOld, Dcm_SesCtrlType SesCtrlTypeNew);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_SessionControl_ChangeIndication RE_CT_DiagnosticsApplSessionControl_ChangeIndication
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplSessionControl_ConfirmationRespPending(Dcm_ConfirmationStatusType status);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_SessionControl_ConfirmationRespPending RE_CT_DiagnosticsApplSessionControl_ConfirmationRespPending
#  define RTE_START_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_CP_AP_DIAGNOSTICSAPPL_APPL_CODE) RE_CT_DiagnosticsApplSessionControl_GetSesChgPermission(Dcm_SesCtrlType SesCtrlTypeActive, Dcm_SesCtrlType SesCtrlTypeNew);
#  define RTE_STOP_SEC_CP_AP_DIAGNOSTICSAPPL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_SessionControl_GetSesChgPermission RE_CT_DiagnosticsApplSessionControl_GetSesChgPermission


# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_DCM_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

FUNC(void, RTE_DCM_APPL_CODE) Dcm_MainFunction(void);

FUNC(Std_ReturnType, RTE_DCM_APPL_CODE) Dcm_GetSecurityLevel(P2VAR(Dcm_SecLevelType, AUTOMATIC, RTE_DCM_APPL_VAR) SecLevel);

FUNC(Std_ReturnType, RTE_DCM_APPL_CODE) Dcm_GetSesCtrlType(P2VAR(Dcm_SesCtrlType, AUTOMATIC, RTE_DCM_APPL_VAR) SessionCtrlType);

FUNC(Std_ReturnType, RTE_DCM_APPL_CODE) Dcm_LeavePassiveMode(void);

# define RTE_STOP_SEC_DCM_APPL_CODE
# include "MemMap.h"


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_ComControlService_E_COM_CTRL_NOT_ACCEPTED (40u)

#  define RTE_E_ComControlService_E_PENDING (10u)

#  define RTE_E_DCMServices_E_NOT_OK (1u)

#  define RTE_E_DCMServices_E_PENDING (10u)

#  define RTE_E_DidServices_0x0102_E_NOT_OK (1u)

#  define RTE_E_DidServices_0x0102_E_PENDING (10u)

#  define RTE_E_DidServices_0x010c_E_NOT_OK (1u)

#  define RTE_E_DidServices_0x010c_E_PENDING (10u)

#  define RTE_E_DidServices_0x010d_E_NOT_OK (1u)

#  define RTE_E_DidServices_0x010d_E_PENDING (10u)

#  define RTE_E_DidServices_0x0210_E_NOT_OK (1u)

#  define RTE_E_DidServices_0x0210_E_PENDING (10u)

#  define RTE_E_DidServices_0x0212_E_NOT_OK (1u)

#  define RTE_E_DidServices_0x0212_E_PENDING (10u)

#  define RTE_E_DidServices_0x0213_E_NOT_OK (1u)

#  define RTE_E_DidServices_0x0213_E_PENDING (10u)

#  define RTE_E_DidServices_0x0214_E_NOT_OK (1u)

#  define RTE_E_DidServices_0x0214_E_PENDING (10u)

#  define RTE_E_DidServices_0x0215_E_NOT_OK (1u)

#  define RTE_E_DidServices_0x0215_E_PENDING (10u)

#  define RTE_E_DidServices_0x0216_E_NOT_OK (1u)

#  define RTE_E_DidServices_0x0216_E_PENDING (10u)

#  define RTE_E_DidServices_0x0217_E_NOT_OK (1u)

#  define RTE_E_DidServices_0x0217_E_PENDING (10u)

#  define RTE_E_DidServices_0x0236_E_NOT_OK (1u)

#  define RTE_E_DidServices_0x0236_E_PENDING (10u)

#  define RTE_E_DidServices_0x0238_E_NOT_OK (1u)

#  define RTE_E_DidServices_0x0238_E_PENDING (10u)

#  define RTE_E_DidServices_0x0242_E_NOT_OK (1u)

#  define RTE_E_DidServices_0x0242_E_PENDING (10u)

#  define RTE_E_DidServices_0x0260_E_NOT_OK (1u)

#  define RTE_E_DidServices_0x0260_E_PENDING (10u)

#  define RTE_E_DidServices_0x0261_E_NOT_OK (1u)

#  define RTE_E_DidServices_0x0261_E_PENDING (10u)

#  define RTE_E_DidServices_0x0262_E_NOT_OK (1u)

#  define RTE_E_DidServices_0x0262_E_PENDING (10u)

#  define RTE_E_DidServices_0x0263_E_NOT_OK (1u)

#  define RTE_E_DidServices_0x0263_E_PENDING (10u)

#  define RTE_E_DidServices_0x0266_E_NOT_OK (1u)

#  define RTE_E_DidServices_0x0266_E_PENDING (10u)

#  define RTE_E_DidServices_0x0271_E_NOT_OK (1u)

#  define RTE_E_DidServices_0x0271_E_PENDING (10u)

#  define RTE_E_DidServices_0x0272_E_NOT_OK (1u)

#  define RTE_E_DidServices_0x0272_E_PENDING (10u)

#  define RTE_E_DidServices_0x0273_E_NOT_OK (1u)

#  define RTE_E_DidServices_0x0273_E_PENDING (10u)

#  define RTE_E_DidServices_0x0280_E_NOT_OK (1u)

#  define RTE_E_DidServices_0x0280_E_PENDING (10u)

#  define RTE_E_DidServices_0x0281_E_NOT_OK (1u)

#  define RTE_E_DidServices_0x0281_E_PENDING (10u)

#  define RTE_E_DidServices_0x0282_E_NOT_OK (1u)

#  define RTE_E_DidServices_0x0282_E_PENDING (10u)

#  define RTE_E_DidServices_0x0283_E_NOT_OK (1u)

#  define RTE_E_DidServices_0x0283_E_PENDING (10u)

#  define RTE_E_DidServices_0x0284_E_NOT_OK (1u)

#  define RTE_E_DidServices_0x0284_E_PENDING (10u)

#  define RTE_E_DidServices_0x02a0_E_NOT_OK (1u)

#  define RTE_E_DidServices_0x02a0_E_PENDING (10u)

#  define RTE_E_DidServices_0x02a1_E_NOT_OK (1u)

#  define RTE_E_DidServices_0x02a1_E_PENDING (10u)

#  define RTE_E_DidServices_0x0380_E_NOT_OK (1u)

#  define RTE_E_DidServices_0x0380_E_PENDING (10u)

#  define RTE_E_DidServices_0x0381_E_NOT_OK (1u)

#  define RTE_E_DidServices_0x0381_E_PENDING (10u)

#  define RTE_E_DidServices_0x0382_E_NOT_OK (1u)

#  define RTE_E_DidServices_0x0382_E_PENDING (10u)

#  define RTE_E_DidServices_0x0383_E_NOT_OK (1u)

#  define RTE_E_DidServices_0x0383_E_PENDING (10u)

#  define RTE_E_DidServices_0x0384_E_NOT_OK (1u)

#  define RTE_E_DidServices_0x0384_E_PENDING (10u)

#  define RTE_E_DidServices_0xd000_E_PENDING (10u)

#  define RTE_E_DidServices_0xef02_E_NOT_OK (1u)

#  define RTE_E_DidServices_0xef02_E_PENDING (10u)

#  define RTE_E_DidServices_0xef03_E_NOT_OK (1u)

#  define RTE_E_DidServices_0xef03_E_PENDING (10u)

#  define RTE_E_DidServices_0xf100_E_NOT_OK (1u)

#  define RTE_E_DidServices_0xf100_E_PENDING (10u)

#  define RTE_E_DidServices_0xf10d_E_NOT_OK (1u)

#  define RTE_E_DidServices_0xf10d_E_PENDING (10u)

#  define RTE_E_DidServices_0xf170_E_NOT_OK (1u)

#  define RTE_E_DidServices_0xf170_E_PENDING (10u)

#  define RTE_E_DidServices_0xf18c_E_NOT_OK (1u)

#  define RTE_E_DidServices_0xf18c_E_PENDING (10u)

#  define RTE_E_DidServices_0xf195_E_NOT_OK (1u)

#  define RTE_E_DidServices_0xf195_E_PENDING (10u)

#  define RTE_E_DidServices_0xf1a2_E_NOT_OK (1u)

#  define RTE_E_DidServices_0xf1a2_E_PENDING (10u)

#  define RTE_E_DidServices_0xf1a3_E_NOT_OK (1u)

#  define RTE_E_DidServices_0xf1a3_E_PENDING (10u)

#  define RTE_E_DidServices_0xf1a5_E_NOT_OK (1u)

#  define RTE_E_DidServices_0xf1a5_E_PENDING (10u)

#  define RTE_E_PassiveMode_E_NOT_OK (1u)

#  define RTE_E_PassiveMode_E_PENDING (10u)

#  define RTE_E_ResetService_E_NOT_OK (1u)

#  define RTE_E_ResetService_E_PENDING (10u)

#  define RTE_E_RoutineServices_0x0201_E_PENDING (10u)

#  define RTE_E_RoutineServices_0x0300_E_PENDING (10u)

#  define RTE_E_RoutineServices_0x0301_E_PENDING (10u)

#  define RTE_E_RoutineServices_0x0303_E_PENDING (10u)

#  define RTE_E_RoutineServices_0x0304_E_PENDING (10u)

#  define RTE_E_RoutineServices_0x0310_E_PENDING (10u)

#  define RTE_E_RoutineServices_0x0321_E_PENDING (10u)

#  define RTE_E_RoutineServices_0x0325_E_PENDING (10u)

#  define RTE_E_RoutineServices_0x0330_E_PENDING (10u)

#  define RTE_E_RoutineServices_0xff03_E_PENDING (10u)

#  define RTE_E_SecurityAccess_1_E_COMPARE_KEY_FAILED (11u)

#  define RTE_E_SecurityAccess_1_E_NOT_OK (1u)

#  define RTE_E_SecurityAccess_1_E_PENDING (10u)

#  define RTE_E_SessionControl_E_FORCE_RCRRP (12u)

#  define RTE_E_SessionControl_E_NOT_OK (1u)

#  define RTE_E_SessionControl_E_PENDING (10u)

#  define RTE_E_SessionControl_E_SESSION_NOT_ALLOWED (4u)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1310030428
#    error "The magic number of the generated file <D:/Sandboxes/MFC300/MFC300_Base/05_Software/MCU/03_Design/05_DaVinci/MPC/Rte/Components/Rte_Dcm.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1310030428
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_DCM_H */
