/**
 * \file
 *
 * \brief AUTOSAR Dcm
 *
 * This file contains the implementation of the AUTOSAR
 * module Dcm.
 *
 * \version 5.0.10
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2021 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

 /* MISRA-C:2004 Deviation List
  *
  * MISRA-1) Deviated Rule: 12.4 (required)
  *     The right-hand operand of a logical '&&' or '||' operator
  *     shall not contain side effects.
  *
  *     Reason:
  *     Logical operators '&&' and '||' are used here purposefully. The sub-expression shall not be
  *      evaluated if the first expression of a '&&' operation is FALSE. Similarly the
  *      sub-expression shall not be evaluated if the first expression of a '||' operation is TRUE.
  *      There is no side effects.
  *
  * MISRA-2) Deviated Rule: 11.4 (advisory)
  *     A cast should not be performed between a pointer to object type and a
  *     different pointer to object type.
  *
  *     Reason:
  *     A cast to unsigned is necessary here to copy data bit by bit and
  *     there is no alignment issues.
  *
  * MISRA-3) Deviated Rule: 11.1 (required)
  *     Conversions shall not be performed between a pointer to a function and
  *     any type other than an integral type.
  *
  *     Reason:
  *     In order to save memory, the function pointers necessary for DID operations are generated
  *     as an array of unions (union type which contains all such possible function pointers),
  *     instead of an array of structures containing all possible pointer types.
  *     The array containing the function pointers is initialized using brace-enclosed initializer
  *     list and C90 standard allows only the initialization of the first union member.
  *     The solution is to use a "generic function pointer" and use that type to define the array,
  *     and use explicit casts for each initialized member.
  *     Casting one function pointer type to the general type at initialization and then back again
  *     to the original type is guaranteed to preserve the correct data.
  *
  */

 /* MISRA-C:2012 Deviation List
  *
  *  MISRAC2012-1) Deviated Rule: 11.1 (required)
  *     "Conversions shall not be performed between a pointer to a function and any other type."
  *
  *     Reason:
  *     In order to save memory, the function pointers necessary for DID operations are generated
  *     as an array of unions (union type which contains all such possible function pointers),
  *     instead of an array of structures containing all possible pointer types.
  *     The array containing the function pointers is initialized using brace-enclosed initializer
  *     list and C90 standard allows only the initialization of the first union member.
  *     The solution is to use a "generic function pointer" and use that type to define the array,
  *     and use explicit casts for each initialized member.
  *     Casting one function pointer type to the general type at initialization and then back again
  *     to the original type is guaranteed to preserve the correct data.
  *
  *  MISRAC2012-2) Deviated Rule: 13.5 (required)
  *     "The right hand operand of a logical && or || operator shall not contain persistent
  *     side effects."
  *
  *     Reason:
  *     Logical operators '&&' and '||' are used here purposefully. The sub-expression shall not be
  *     evaluated if the first expression of a '&&' operation is FALSE. Similarly the
  *     sub-expression shall not be evaluated if the first expression of a '||' operation is TRUE.
  *     There is no side effects.
  *
  *  MISRAC2012-3) Deviated Rule: 11.3 (required)
  *     "A cast should not be performed between a pointer to object type and a different pointer to
  *     object type."
  *
  *     Reason:
  *     A cast to UINT8 is necessary here to copy data bit by bit and to be flexible for all
  *     the types, being no alignment issues.
  *     There is no side effects.
  *
  *  MISRAC2012-4) Deviated Rule: 8.9 (advisory)
  *     "An object should be defined at block scope if its identifier only
  *     appears in a single function."
  *
  *     Reason:
  *     The object is defined in this way because the values that are stored
  *     in them are required for the next call of this function and should be
  *     hold in the data segment memory.
  */

/*==================[inclusions]=================================================================*/
#include <ComStack_Types.h>                                            /* AUTOSAR standard types */
#include <Dcm_Cfg.h>                                           /* Generated configuration header */
#include <Dcm_API_Cfg.h>                                  /*  Configurable function declarations */
#include <Dcm_Hsm.h>                                                        /* Dcm State Machine */
#include <Dcm_Int.h>                                       /* Module internal header static part */
#include <Dcm_DspExternal.h>                          /* Callbacks provided by Central Diag SwC  */
#include <Dcm_Dsl_Supervisor.h>                                       /* Module internal header static part */

/* OBD Service 0x01 and 0x02*/
#if(DCM_DSP_USE_SERVICE_0X01 == STD_ON) || \
(DCM_DSP_USE_SERVICE_0X02 == STD_ON) || \
(DCM_NUM_PID_CFG > 0U)
#include <Dcm_Dsp_PidServices.h>
#endif

#if (DCM_DSP_USE_SERVICE_0X06 == STD_ON)
#include <Dcm_Dsp_SvcH_RequestOnboardMonitoringTestResults.h>
#endif

#if (DCM_DSP_USE_SERVICE_0X08 == STD_ON)
#include <Dcm_Dsp_SvcH_RequestControlOfOnBoardSysTstComp.h>
#endif

#if (DCM_DSP_USE_SERVICE_0X09 == STD_ON)
/* OBD Service 0x09 */
#include <Dcm_Dsp_SvcH_RequestVehicleInformation.h>
#endif

#if ( (DCM_DSP_USE_SERVICE_0X19 == STD_ON) || (DCM_DSP_USE_SERVICE_0XAF == STD_ON) )
#include <Dcm_Dsp_SvcH_ReadDTCInformation.h>
#endif

#if (DCM_DSP_USE_SERVICE_0X22 == STD_ON)
#include <Dcm_Dsp_SvcH_ReadDataByIdentifier.h>
#endif

#if (DCM_DSP_USE_SERVICE_0X23 == STD_ON)
#include <Dcm_Dsp_SvcH_ReadMemoryByAddress.h>
#endif

#if (DCM_DSP_USE_SERVICE_0X24 == STD_ON)
#include <Dcm_Dsp_SvcH_ReadScalingDataByIdentifier.h>
#endif

#if (DCM_DSP_USE_SERVICE_0X2E == STD_ON)
#include <Dcm_Dsp_SvcH_WriteDataByIdentifier.h>
#endif

#if (DCM_DSP_USE_SERVICE_0X34 == STD_ON)
#include <Dcm_Dsp_SvcH_RequestDownload.h>
#endif

#if (DCM_DSP_USE_SERVICE_0X35 == STD_ON)
#include <Dcm_Dsp_SvcH_RequestUpload.h>
#endif

#if (DCM_DSP_USE_SERVICE_0X36 == STD_ON)
#include <Dcm_Dsp_SvcH_TransferData.h>
#endif

#if (DCM_DSP_USE_SERVICE_0X37 == STD_ON)
#include <Dcm_Dsp_SvcH_RequestTransferExit.h>
#endif

#if (DCM_DSP_USE_SERVICE_0X3D == STD_ON)
#include <Dcm_Dsp_SvcH_WriteMemoryByAddress.h>
#endif

#if (DCM_DSP_USE_DIDSERVICES == STD_ON)
/* Include DidServices SW unit header for IO control */
#include <Dcm_Dsp_DidServices.h>
#endif

#if (DCM_DSP_USE_SERVICE_0X85 == STD_ON)
#include <Dcm_Dsp_SvcH_ControlDTCSetting.h>
#endif

#if (DCM_DSP_USE_SERVICE_0X86 == STD_ON)
#include <Dcm_Dsp_SvcH_ResponseOnEvent.h>
#endif

#if (DCM_DSP_USE_ROESERVICES == STD_ON)
#include <Dcm_Dsl_RoeServices.h>
#endif

#if (DCM_DSP_USE_SERVICE_0X2C == STD_ON)
#include <Dcm_Dsp_SvcH_DynamicallyDefineDataIdentifier.h>
#endif

#if(DCM_DSP_USE_SERVICE_0X28 == STD_ON)
#include <Dcm_Dsp_SvcH_CommunicationControl.h>
#endif

#if (DCM_DSP_USE_SERVICE_0X87 == STD_ON)
#include <Dcm_Dsp_SvcH_LinkControl.h>
#endif

#if(DCM_DSP_USE_SERVICE_0X27 == STD_ON)
#include <Dcm_Dsp_SvcH_SecurityAccess.h>
#endif

#if(DCM_DSP_USE_MEMORYSERVICES == STD_ON)
#include <Dcm_Dsp_MemoryServices.h>
#endif

#if(DCM_DSP_USE_SERVICE_0X3E == STD_ON)
#include <Dcm_Dsp_SvcH_TesterPresent.h>
#endif

#if(DCM_DSP_USE_SERVICE_0X2F == STD_ON)
#include <Dcm_Dsp_SvcH_InputOutputControlByIdentifier.h>
#endif

#if(DCM_DSP_USE_SERVICE_0X31 == STD_ON)
#include <Dcm_Dsp_SvcH_RoutineControl.h>
#endif


#if ((DCM_DSP_USE_DIDSERVICES == STD_ON) && (DCM_DSP_USE_SENDERRECEIVER_INTERFACES == STD_ON))
#include <Dcm_Dsp_EndiannessInterpretation.h>
#endif

#include <SchM_Dcm.h>

/*==================[macros]=====================================================================*/

/*==================[type definitions]===========================================================*/

/*==================[external function declarations]=============================================*/

/*==================[internal function declarations]=============================================*/
#define DCM_START_SEC_CODE
#include <Dcm_MemMap.h>

#define DCM_STOP_SEC_CODE
#include <Dcm_MemMap.h>
/*==================[internal constants]=========================================================*/

#define DCM_START_SEC_CONST_8
#include <Dcm_MemMap.h>

/* Array of session types for all Subservices */
STATIC CONST(Dcm_SesCtrlType,DCM_CONST) Dcm_SubSidTabSesLevels[15] =
{
  0x01U, /* DCM_DEFAULT_SESSION of DiagnosticSessionControl referred by its subservice defaultSession */
  0x03U, /* DCM_EXTENDED_DIAGNOSTIC_SESSION of DiagnosticSessionControl referred by its subservice defaultSession */
  0x02U, /* DCM_PROGRAMMING_SESSION of DiagnosticSessionControl referred by its subservice programmingSession */
  0x03U, /* DCM_EXTENDED_DIAGNOSTIC_SESSION of DiagnosticSessionControl referred by its subservice programmingSession */
  0x03U, /* DCM_EXTENDED_DIAGNOSTIC_SESSION of DiagnosticSessionControl referred by its subservice extendedDiagnosticSession */
  0x01U, /* DCM_DEFAULT_SESSION of DiagnosticSessionControl referred by its subservice extendedDiagnosticSession */
  0x02U, /* DCM_PROGRAMMING_SESSION of DiagnosticSessionControl referred by its subservice extendedDiagnosticSession */
  0x01U, /* DCM_DEFAULT_SESSION of EcuReset referred by its subservice hardReset */
  0x03U, /* DCM_EXTENDED_DIAGNOSTIC_SESSION of EcuReset referred by its subservice hardReset */
  0x02U, /* DCM_PROGRAMMING_SESSION of EcuReset referred by its subservice hardReset */
  0x01U, /* DCM_DEFAULT_SESSION of EcuReset referred by its subservice softReset */
  0x02U, /* DCM_PROGRAMMING_SESSION of EcuReset referred by its subservice softReset */
  0x03U, /* DCM_EXTENDED_DIAGNOSTIC_SESSION of EcuReset referred by its subservice softReset */
  0x03U, /* DCM_EXTENDED_DIAGNOSTIC_SESSION of SecurityAccess referred by its subservice DcmDsdSubService_0 */
  0x03U, /* DCM_EXTENDED_DIAGNOSTIC_SESSION of SecurityAccess referred by its subservice DcmDsdSubService_1 */
};

/* Array of session types for all services */
STATIC CONST(Dcm_SesCtrlType,DCM_CONST) Dcm_SidTabSesLevels[16] =
{
  0x01U, /* DCM_DEFAULT_SESSION referred to by ClearDiagnosticInformation */
  0x03U, /* DCM_EXTENDED_DIAGNOSTIC_SESSION referred to by ClearDiagnosticInformation */
  0x01U, /* DCM_DEFAULT_SESSION referred to by ReadDTCInformation */
  0x03U, /* DCM_EXTENDED_DIAGNOSTIC_SESSION referred to by ReadDTCInformation */
  0xffU, /* DCM_ALL_SESSION_LEVEL referred to by ReadDid */
  0x03U, /* DCM_EXTENDED_DIAGNOSTIC_SESSION referred to by SecurityAccess */
  0x02U, /* DCM_PROGRAMMING_SESSION referred to by SecurityAccess */
  0x03U, /* DCM_EXTENDED_DIAGNOSTIC_SESSION referred to by CommunicationControl */
  0x03U, /* DCM_EXTENDED_DIAGNOSTIC_SESSION referred to by ReadDataByPeriodicIdentifier */
  0x03U, /* DCM_EXTENDED_DIAGNOSTIC_SESSION referred to by WriteDid */
  0x02U, /* DCM_PROGRAMMING_SESSION referred to by WriteDid */
  0x03U, /* DCM_EXTENDED_DIAGNOSTIC_SESSION referred to by InputOutputControlByIdentifier */
  0x02U, /* DCM_PROGRAMMING_SESSION referred to by RoutineControl */
  0x03U, /* DCM_EXTENDED_DIAGNOSTIC_SESSION referred to by RoutineControl */
  0xffU, /* DCM_ALL_SESSION_LEVEL referred to by TesterPresent */
  0x03U, /* DCM_EXTENDED_DIAGNOSTIC_SESSION referred to by ControlDTCSetting */
};

/* Array of security types for all services */
STATIC CONST(Dcm_SecLevelType, DCM_CONST) Dcm_SidTabSecLevels[1] =
{
  0x01U, /* SA_Level1 referred to by WriteDid */
};

#define DCM_STOP_SEC_CONST_8
#include <Dcm_MemMap.h>

#define DCM_START_SEC_CONST_UNSPECIFIED
#include <Dcm_MemMap.h>

/* Array of Subservices for Service 'DiagnosticSessionControl' */
STATIC CONST(Dcm_SubSidTabEntryConfigType, DCM_CONST) Dcm_SidTabEntryConfig0_SubSidTabEntryConfig16[3] =
{
  {
    &( Dcm_SubSidTabSesLevels[0]), /* Pointer to subservice sessions */
    NULL_PTR, /* Pointer to subservice security levels */
    NULL_PTR, /* Pointer to External Subservice function */
    &Dcm_DspInternal_DiagnosticSessionControlCommon_SSvcH, /* Pointer to Internal Subservice function */
    NULL_PTR, /* Pointer to Mode rule function */
    0x01U, /* SubServiceId */
    2U, /* Number of sub service session levels */
    0U, /* Number of sub service security levels */
  },
  {
    &( Dcm_SubSidTabSesLevels[2]), /* Pointer to subservice sessions */
    NULL_PTR, /* Pointer to subservice security levels */
    NULL_PTR, /* Pointer to External Subservice function */
    &Dcm_DspInternal_DiagnosticSessionControlCommon_SSvcH, /* Pointer to Internal Subservice function */
    NULL_PTR, /* Pointer to Mode rule function */
    0x02U, /* SubServiceId */
    2U, /* Number of sub service session levels */
    0U, /* Number of sub service security levels */
  },
  {
    &( Dcm_SubSidTabSesLevels[4]), /* Pointer to subservice sessions */
    NULL_PTR, /* Pointer to subservice security levels */
    NULL_PTR, /* Pointer to External Subservice function */
    &Dcm_DspInternal_DiagnosticSessionControlCommon_SSvcH, /* Pointer to Internal Subservice function */
    NULL_PTR, /* Pointer to Mode rule function */
    0x03U, /* SubServiceId */
    3U, /* Number of sub service session levels */
    0U, /* Number of sub service security levels */
  },
};

/* Array of Subservices for Service 'EcuReset' */
STATIC CONST(Dcm_SubSidTabEntryConfigType, DCM_CONST) Dcm_SidTabEntryConfig0_SubSidTabEntryConfig17[2] =
{
  {
    &( Dcm_SubSidTabSesLevels[7]), /* Pointer to subservice sessions */
    NULL_PTR, /* Pointer to subservice security levels */
    NULL_PTR, /* Pointer to External Subservice function */
    &Dcm_DspInternal_HardReset_SSvcH, /* Pointer to Internal Subservice function */
    NULL_PTR, /* Pointer to Mode rule function */
    0x01U, /* SubServiceId */
    3U, /* Number of sub service session levels */
    0U, /* Number of sub service security levels */
  },
  {
    &( Dcm_SubSidTabSesLevels[10]), /* Pointer to subservice sessions */
    NULL_PTR, /* Pointer to subservice security levels */
    NULL_PTR, /* Pointer to External Subservice function */
    &Dcm_DspInternal_SoftReset_SSvcH, /* Pointer to Internal Subservice function */
    NULL_PTR, /* Pointer to Mode rule function */
    0x03U, /* SubServiceId */
    3U, /* Number of sub service session levels */
    0U, /* Number of sub service security levels */
  },
};

/* Array of Subservices for Service 'ReadDTCInformation' */
STATIC CONST(Dcm_SubSidTabEntryConfigType, DCM_CONST) Dcm_SidTabEntryConfig0_SubSidTabEntryConfig25[5] =
{
  {
    NULL_PTR, /* Pointer to subservice sessions */
    NULL_PTR, /* Pointer to subservice security levels */
    NULL_PTR, /* Pointer to External Subservice function */
    &Dcm_DspInternal_ReportNumberOfDTCByStatusMask_SSvcH, /* Pointer to Internal Subservice function */
    NULL_PTR, /* Pointer to Mode rule function */
    0x01U, /* SubServiceId */
    0U, /* Number of sub service session levels */
    0U, /* Number of sub service security levels */
  },
  {
    NULL_PTR, /* Pointer to subservice sessions */
    NULL_PTR, /* Pointer to subservice security levels */
    NULL_PTR, /* Pointer to External Subservice function */
    &Dcm_DspInternal_ReportDTCByStatusMask_SSvcH, /* Pointer to Internal Subservice function */
    NULL_PTR, /* Pointer to Mode rule function */
    0x02U, /* SubServiceId */
    0U, /* Number of sub service session levels */
    0U, /* Number of sub service security levels */
  },
  {
    NULL_PTR, /* Pointer to subservice sessions */
    NULL_PTR, /* Pointer to subservice security levels */
    NULL_PTR, /* Pointer to External Subservice function */
    &Dcm_DspInternal_ReportDtcSnapshotRecordByDtcNumber_SSvcH, /* Pointer to Internal Subservice function */
    NULL_PTR, /* Pointer to Mode rule function */
    0x04U, /* SubServiceId */
    0U, /* Number of sub service session levels */
    0U, /* Number of sub service security levels */
  },
  {
    NULL_PTR, /* Pointer to subservice sessions */
    NULL_PTR, /* Pointer to subservice security levels */
    NULL_PTR, /* Pointer to External Subservice function */
    &Dcm_DspInternal_ReportDtcExtendedDataRecordByDtcNumber_SSvcH, /* Pointer to Internal Subservice function */
    NULL_PTR, /* Pointer to Mode rule function */
    0x06U, /* SubServiceId */
    0U, /* Number of sub service session levels */
    0U, /* Number of sub service security levels */
  },
  {
    NULL_PTR, /* Pointer to subservice sessions */
    NULL_PTR, /* Pointer to subservice security levels */
    NULL_PTR, /* Pointer to External Subservice function */
    &Dcm_DspInternal_ReportSupportedDtcs_SSvcH, /* Pointer to Internal Subservice function */
    NULL_PTR, /* Pointer to Mode rule function */
    0x0aU, /* SubServiceId */
    0U, /* Number of sub service session levels */
    0U, /* Number of sub service security levels */
  },
};

/* Array of Subservices for Service 'SecurityAccess' */
STATIC CONST(Dcm_SubSidTabEntryConfigType, DCM_CONST) Dcm_SidTabEntryConfig0_SubSidTabEntryConfig39[2] =
{
  {
    &( Dcm_SubSidTabSesLevels[13]), /* Pointer to subservice sessions */
    NULL_PTR, /* Pointer to subservice security levels */
    NULL_PTR, /* Pointer to External Subservice function */
    NULL_PTR, /* Pointer to Internal Subservice function */
    NULL_PTR, /* Pointer to Mode rule function */
    0x01U, /* SubServiceId */
    1U, /* Number of sub service session levels */
    0U, /* Number of sub service security levels */
  },
  {
    &( Dcm_SubSidTabSesLevels[14]), /* Pointer to subservice sessions */
    NULL_PTR, /* Pointer to subservice security levels */
    NULL_PTR, /* Pointer to External Subservice function */
    NULL_PTR, /* Pointer to Internal Subservice function */
    NULL_PTR, /* Pointer to Mode rule function */
    0x02U, /* SubServiceId */
    1U, /* Number of sub service session levels */
    0U, /* Number of sub service security levels */
  },
};

/* Array of Subservices for Service 'CommunicationControl' */
STATIC CONST(Dcm_SubSidTabEntryConfigType, DCM_CONST) Dcm_SidTabEntryConfig0_SubSidTabEntryConfig40[2] =
{
  {
    NULL_PTR, /* Pointer to subservice sessions */
    NULL_PTR, /* Pointer to subservice security levels */
    NULL_PTR, /* Pointer to External Subservice function */
    &Dcm_Dsp_CommunicationControl_EnableRxAndTx_SSvcH, /* Pointer to Internal Subservice function */
    NULL_PTR, /* Pointer to Mode rule function */
    0x00U, /* SubServiceId */
    0U, /* Number of sub service session levels */
    0U, /* Number of sub service security levels */
  },
  {
    NULL_PTR, /* Pointer to subservice sessions */
    NULL_PTR, /* Pointer to subservice security levels */
    NULL_PTR, /* Pointer to External Subservice function */
    &Dcm_Dsp_CommunicationControl_DisableRxAndTx_SSvcH, /* Pointer to Internal Subservice function */
    NULL_PTR, /* Pointer to Mode rule function */
    0x03U, /* SubServiceId */
    0U, /* Number of sub service session levels */
    0U, /* Number of sub service security levels */
  },
};

/* Array of Subservices for Service 'RoutineControl' */
STATIC CONST(Dcm_SubSidTabEntryConfigType, DCM_CONST) Dcm_SidTabEntryConfig0_SubSidTabEntryConfig49[3] =
{
  {
    NULL_PTR, /* Pointer to subservice sessions */
    NULL_PTR, /* Pointer to subservice security levels */
    NULL_PTR, /* Pointer to External Subservice function */
    &Dcm_Dsp_RoutineControl_StartRoutine_SSvcH, /* Pointer to Internal Subservice function */
    NULL_PTR, /* Pointer to Mode rule function */
    0x01U, /* SubServiceId */
    0x00U, /* Number of sub service session levels */
    0x00U, /* Number of sub service security levels */
  },

  {
    NULL_PTR, /* Pointer to subservice sessions */
    NULL_PTR, /* Pointer to subservice security levels */
    NULL_PTR, /* Pointer to External Subservice function */
    &Dcm_Dsp_RoutineControl_StopRoutine_SSvcH, /* Pointer to Internal Subservice function */
    NULL_PTR, /* Pointer to Mode rule function */
    0x02U, /* SubServiceId */
    0x00U, /* Number of sub service session levels */
    0x00U, /* Number of sub service security levels */
  },

  {
    NULL_PTR, /* Pointer to subservice sessions */
    NULL_PTR, /* Pointer to subservice security levels */
    NULL_PTR, /* Pointer to External Subservice function */
    &Dcm_Dsp_RoutineControl_RequestResults_SSvcH, /* Pointer to Internal Subservice function */
    NULL_PTR, /* Pointer to Mode rule function */
    0x03U, /* SubServiceId */
    0x00U, /* Number of sub service session levels */
    0x00U, /* Number of sub service security levels */
  }
};
/* Array of Subservices for Service 'TesterPresent' */
STATIC CONST(Dcm_SubSidTabEntryConfigType, DCM_CONST) Dcm_SidTabEntryConfig0_SubSidTabEntryConfig62[1] =
{
  {
    NULL_PTR, /* Pointer to subservice sessions */
    NULL_PTR, /* Pointer to subservice security levels */
    NULL_PTR, /* Pointer to External Subservice function */
    &Dcm_Dsp_TesterPresent_ZeroSubFunction_SSvcH, /* Pointer to Internal Subservice function */
    NULL_PTR, /* Pointer to Mode rule function */
    0x00U, /* SubServiceId */
    0U, /* Number of sub service session levels */
    0U, /* Number of sub service security levels */
  },
};

/* Array of Subservices for Service 'ControlDTCSetting' */
STATIC CONST(Dcm_SubSidTabEntryConfigType, DCM_CONST) Dcm_SidTabEntryConfig0_SubSidTabEntryConfig133[2] =
{
  {
    NULL_PTR, /* Pointer to subservice sessions */
    NULL_PTR, /* Pointer to subservice security levels */
    NULL_PTR, /* Pointer to External Subservice function */
    &Dcm_Dsp_ControlDTCSetting_On_SSvcH, /* Pointer to Internal Subservice function */
    NULL_PTR, /* Pointer to Mode rule function */
    0x01U, /* SubServiceId */
    0U, /* Number of sub service session levels */
    0U, /* Number of sub service security levels */
  },
  {
    NULL_PTR, /* Pointer to subservice sessions */
    NULL_PTR, /* Pointer to subservice security levels */
    NULL_PTR, /* Pointer to External Subservice function */
    &Dcm_Dsp_ControlDTCSetting_Off_SSvcH, /* Pointer to Internal Subservice function */
    NULL_PTR, /* Pointer to Mode rule function */
    0x02U, /* SubServiceId */
    0U, /* Number of sub service session levels */
    0U, /* Number of sub service security levels */
  },
};

/* Array of services for Service table 'DcmDsdServiceTable_0' (id 0) */
STATIC CONST(Dcm_SidTabEntryConfigType, DCM_CONST) Dcm_SidTabEntryConfig0[13] =
{
  {
    NULL_PTR,
    NULL_PTR,
    (Dcm_SidTabEntryConfig0_SubSidTabEntryConfig16), /*Pointer to subservices array. */
    NULL_PTR,
    &Dcm_DspInternal_DiagnosticSessionControl_SvcH,  /* Pointer to internal service function */
    NULL_PTR,
    0x10U, /* ServiceId */
    0U, /* Number of sessions */
    0U, /* Number of security levels */
    3U, /* Number of subservices */
    TRUE, /* Subfunction available */
    FALSE /* AsyncServiceExecution available */
  },
  {
    NULL_PTR,
    NULL_PTR,
    (Dcm_SidTabEntryConfig0_SubSidTabEntryConfig17), /*Pointer to subservices array. */
    NULL_PTR,
    &Dcm_DspInternal_ECUReset_SvcH,  /* Pointer to internal service function */
    NULL_PTR,
    0x11U, /* ServiceId */
    0U, /* Number of sessions */
    0U, /* Number of security levels */
    2U, /* Number of subservices */
    TRUE, /* Subfunction available */
    FALSE /* AsyncServiceExecution available */
  },
  {
    &( Dcm_SidTabSesLevels[0]), /* Pointer to sessions */
    NULL_PTR,
    NULL_PTR, /*Pointer to subservices array. */
    NULL_PTR,
    &Dcm_DspInternal_ClearDiagnosticInformation_SvcH,  /* Pointer to internal service function */
    NULL_PTR,
    0x14U, /* ServiceId */
    2U, /* Number of sessions */
    0U, /* Number of security levels */
    0U, /* Number of subservices */
    FALSE, /* Subfunction available */
    FALSE /* AsyncServiceExecution available */
  },
  {
    &( Dcm_SidTabSesLevels[2]), /* Pointer to sessions */
    NULL_PTR,
    (Dcm_SidTabEntryConfig0_SubSidTabEntryConfig25), /*Pointer to subservices array. */
    NULL_PTR,
    &Dcm_DspInternal_ReadDTCInformation_SvcH,  /* Pointer to internal service function */
    NULL_PTR,
    0x19U, /* ServiceId */
    2U, /* Number of sessions */
    0U, /* Number of security levels */
    5U, /* Number of subservices */
    TRUE, /* Subfunction available */
    FALSE /* AsyncServiceExecution available */
  },
  {
    &( Dcm_SidTabSesLevels[4]), /* Pointer to sessions */
    NULL_PTR,
    NULL_PTR, /*Pointer to subservices array. */
    NULL_PTR,
    &Dcm_Dsp_ReadDataByIdentifier_SvcH,  /* Pointer to internal service function */
    NULL_PTR,
    0x22U, /* ServiceId */
    1U, /* Number of sessions */
    0U, /* Number of security levels */
    0U, /* Number of subservices */
    FALSE, /* Subfunction available */
    FALSE /* AsyncServiceExecution available */
  },
  {
    &( Dcm_SidTabSesLevels[5]), /* Pointer to sessions */
    NULL_PTR,
    (Dcm_SidTabEntryConfig0_SubSidTabEntryConfig39), /*Pointer to subservices array. */
    NULL_PTR,
    &Dcm_Dsp_SecurityAccess_SvcH,  /* Pointer to internal service function */
    NULL_PTR,
    0x27U, /* ServiceId */
    2U, /* Number of sessions */
    0U, /* Number of security levels */
    2U, /* Number of subservices */
    TRUE, /* Subfunction available */
    FALSE /* AsyncServiceExecution available */
  },
  {
    &( Dcm_SidTabSesLevels[7]), /* Pointer to sessions */
    NULL_PTR,
    (Dcm_SidTabEntryConfig0_SubSidTabEntryConfig40), /*Pointer to subservices array. */
    NULL_PTR,
    &Dcm_Dsp_CommunicationControl_SvcH,  /* Pointer to internal service function */
    NULL_PTR,
    0x28U, /* ServiceId */
    1U, /* Number of sessions */
    0U, /* Number of security levels */
    2U, /* Number of subservices */
    TRUE, /* Subfunction available */
    FALSE /* AsyncServiceExecution available */
  },
  {
    &( Dcm_SidTabSesLevels[8]), /* Pointer to sessions */
    NULL_PTR,
    NULL_PTR, /*Pointer to subservices array. */
    NULL_PTR,
    &Dcm_Dsp_ReadDataByPeriodicIdentifier_SvcH,  /* Pointer to internal service function */
    NULL_PTR,
    0x2aU, /* ServiceId */
    1U, /* Number of sessions */
    0U, /* Number of security levels */
    0U, /* Number of subservices */
    FALSE, /* Subfunction available */
    FALSE /* AsyncServiceExecution available */
  },
  {
    &( Dcm_SidTabSesLevels[9]), /* Pointer to sessions */
    &( Dcm_SidTabSecLevels[0]),/* Pointer to security levels */
    NULL_PTR, /*Pointer to subservices array. */
    NULL_PTR,
    &Dcm_Dsp_WriteDataByIdentifier_SvcH,  /* Pointer to internal service function */
    NULL_PTR,
    0x2eU, /* ServiceId */
    2U, /* Number of sessions */
    1U, /* Number of security levels */
    0U, /* Number of subservices */
    FALSE, /* Subfunction available */
    FALSE /* AsyncServiceExecution available */
  },
  {
    &( Dcm_SidTabSesLevels[11]), /* Pointer to sessions */
    NULL_PTR,
    NULL_PTR, /*Pointer to subservices array. */
    NULL_PTR,
    &Dcm_Dsp_InputOutputControlByIdentifier_SvcH,  /* Pointer to internal service function */
    NULL_PTR,
    0x2fU, /* ServiceId */
    1U, /* Number of sessions */
    0U, /* Number of security levels */
    0U, /* Number of subservices */
    FALSE, /* Subfunction available */
    FALSE /* AsyncServiceExecution available */
  },
  {
    &( Dcm_SidTabSesLevels[12]), /* Pointer to sessions */
    NULL_PTR,
    (Dcm_SidTabEntryConfig0_SubSidTabEntryConfig49), /*Pointer to subservices array. */
    NULL_PTR,
    &Dcm_Dsp_RoutineControl_SvcH,  /* Pointer to internal service function */
    NULL_PTR,
    0x31U, /* ServiceId */
    2U, /* Number of sessions */
    0U, /* Number of security levels */
    3U, /* Number of subservices */
    TRUE, /* Subfunction available */
    FALSE /* AsyncServiceExecution available */
  },
  {
    &( Dcm_SidTabSesLevels[14]), /* Pointer to sessions */
    NULL_PTR,
    (Dcm_SidTabEntryConfig0_SubSidTabEntryConfig62), /*Pointer to subservices array. */
    NULL_PTR,
    &Dcm_Dsp_TesterPresent_SvcH,  /* Pointer to internal service function */
    NULL_PTR,
    0x3eU, /* ServiceId */
    1U, /* Number of sessions */
    0U, /* Number of security levels */
    1U, /* Number of subservices */
    TRUE, /* Subfunction available */
    FALSE /* AsyncServiceExecution available */
  },
  {
    &( Dcm_SidTabSesLevels[15]), /* Pointer to sessions */
    NULL_PTR,
    (Dcm_SidTabEntryConfig0_SubSidTabEntryConfig133), /*Pointer to subservices array. */
    NULL_PTR,
    &Dcm_Dsp_ControlDTCSetting_SvcH,  /* Pointer to internal service function */
    NULL_PTR,
    0x85U, /* ServiceId */
    1U, /* Number of sessions */
    0U, /* Number of security levels */
    2U, /* Number of subservices */
    TRUE, /* Subfunction available */
    FALSE /* AsyncServiceExecution available */
  },
};

#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include <Dcm_MemMap.h>

#define DCM_START_SEC_CONST_8
#include <Dcm_MemMap.h>


#define DCM_STOP_SEC_CONST_8
#include <Dcm_MemMap.h>

#define DCM_START_SEC_CONST_UNSPECIFIED
#include <Dcm_MemMap.h>

#if (DCM_DSP_USE_DIDSERVICES == STD_ON)
/* Array of signals configured Did services */
/* !LINKSTO Dcm.Dsn.DidSignals.ConfigurationData.DidSignals,1 */
CONST(Dcm_DidSignalType,DCM_CONST) Dcm_DidSignals[DCM_DID_SIGNALS_COUNT] =
{
  { 0U, 21U }, /* signal 0 of Did DcmDspDid_Invalid_Key_Counter */
  { 0U, 29U }, /* signal 0 of Did DcmDspDid_ECU_Supplier_voltage */
  { 0U, 25U }, /* signal 0 of Did DcmDspDid_ECU_Temperature */
  { 0U, 20U }, /* signal 0 of Did DcmDspDid_Calibration_Board_Distance */
  { 0U, 51U }, /* signal 0 of Did DcmDspDid_APPDownloadArea */
  { 0U, 4U }, /* signal 0 of Did DcmDspDid_ECUHardwareVersionNumberDataIdentifier */
  { 0U, 0U }, /* signal 0 of Did DcmDspDid_NetworkInformationDataIdentifier */
  { 0U, 1U }, /* signal 0 of Did DcmDspDid_FunctionSpecificationDataIdentifier */
  { 0U, 2U }, /* signal 0 of Did DcmDspDid_DiagnosticDefinitionDataIdentifier */
  { 0U, 13U }, /* signal 0 of Did DcmDspDid_Calibration_DataIdentifier */
  { 0U, 9U }, /* signal 0 of Did DcmDspDid_FBL_Version_Information */
  { 0U, 10U }, /* signal 0 of Did DcmDspDid_FBL_Requirement_Specification */
  { 0U, 11U }, /* signal 0 of Did DcmDspDid_Fingerprint */
  { 0U, 30U }, /* signal 0 of Did DcmDspDid_ActiveDiagnosticSessionDataIdentifier */
  { 0U, 5U }, /* signal 0 of Did DcmDspDid_Part_Number */
  { 0U, 12U }, /* signal 0 of Did DcmDspDid_Software_Number */
  { 0U, 3U }, /* signal 0 of Did DcmDspDid_ECUSoftwareVersionNumberDataIdentifier */
  { 0U, 6U }, /* signal 0 of Did DcmDspDid_System_Supplier_Identifier */
  { 0U, 7U }, /* signal 0 of Did DcmDspDid_ECUSerialNumberDataIdentifier */
  { 0U, 8U }, /* signal 0 of Did DcmDspDid_VINDataIdentifier */
  { 0U, 14U }, /* signal 0 of Did DcmDspDid_ECU_Hardware_version_number */
  { 0U, 15U }, /* signal 0 of Did DcmDspDid_Supplier_Software_number */
  { 0U, 52U }, /* signal 0 of Did DcmDspDid_MACAddress */
  { 0U, 53U }, /* signal 0 of Did DcmDspDid_PHYLinkState */
  { 0U, 54U }, /* signal 0 of Did DcmDspDid_PHYSignalQualityIndex */
  { 0U, 55U }, /* signal 0 of Did DcmDspDid_NumberOfPorts */
  { 0U, 56U }, /* signal 0 of Did DcmDspDid_PortConfiguration */
  { 0U, 57U }, /* signal 0 of Did DcmDspDid_CommunicationReadyStatus */
  { 0U, 58U }, /* signal 0 of Did DcmDspDid_MasterSlaveConfigures */
  { 0U, 59U }, /* signal 0 of Did DcmDspDid_MACLayerStatistics */
  { 0U, 45U }, /* signal 0 of Did DcmDspDid_Vehicle_type */
  { 0U, 16U }, /* signal 0 of Did DcmDspDid_FAB_switch */
  { 0U, 17U }, /* signal 0 of Did DcmDspDid_TSR_switch */
  { 0U, 18U }, /* signal 0 of Did DcmDspDid_TLA_switch */
  { 0U, 19U }, /* signal 0 of Did DcmDspDid_Body_height_wheelhouse_edge */
  { 0U, 22U }, /* signal 0 of Did DcmDspDid_Calibration_Status */
  { 0U, 23U }, /* signal 0 of Did DcmDspDid_Current_static_calibration_details */
  { 0U, 24U }, /* signal 0 of Did DcmDspDid_EOL_calibration_parameters */
  { 0U, 26U }, /* signal 0 of Did DcmDspDid_Can_read_the_Previuos_customer_plant_EOL_result */
  { 0U, 27U }, /* signal 0 of Did DcmDspDid_Can_read_the_Previuos_Previous_customer_plant_EOL_result */
  { 0U, 28U }, /* signal 0 of Did DcmDspDid_Can_read_Previous_SDA_result */
  { 0U, 63U }, /* signal 0 of Did DcmDspDid_MFC5J3_EcuOperationMode */
  { 0U, 31U }, /* signal 0 of Did DcmDspDid_Lane_Function_Configuration */
  { 0U, 32U }, /* signal 0 of Did DcmDspDid_EOL_Mode_Gate */
  { 0U, 64U }, /* signal 0 of Did DcmDspDid_MFC5J3_SocResetControl */
  { 0U, 33U }, /* signal 0 of Did DcmDspDid_FCW_Lastbutoneappeared */
  { 0U, 34U }, /* signal 0 of Did DcmDspDid_AWB_Lastbutoneappeared */
  { 0U, 35U }, /* signal 0 of Did DcmDspDid_AEB_Lastbutoneappeared */
  { 0U, 36U }, /* signal 0 of Did DcmDspDid_FCW_Lastappeared */
  { 0U, 37U }, /* signal 0 of Did DcmDspDid_AWB_Lastappeared */
  { 0U, 38U }, /* signal 0 of Did DcmDspDid_AEB_Lastappeared */
  { 0U, 39U }, /* signal 0 of Did DcmDspDid_Internal_SocTemperature */
  { 0U, 40U }, /* signal 0 of Did DcmDspDid_SOC_software_version */
  { 0U, 41U }, /* signal 0 of Did DcmDspDid_OM_calibration_status */
  { 0U, 42U }, /* signal 0 of Did DcmDspDid_Project_ID */
  { 0U, 43U }, /* signal 0 of Did DcmDspDid_OM_SN */
  { 0U, 44U }, /* signal 0 of Did DcmDspDid_Boot_sensor */
  { 0U, 46U }, /* signal 0 of Did DcmDspDid_PCBASerialNumberDataIdentifier */
  { 0U, 50U }, /* signal 0 of Did DcmDspDid_ImagerTemperature */
  { 0U, 47U }, /* signal 0 of Did DcmDspDid_MCUAbankerror */
  { 0U, 48U }, /* signal 0 of Did DcmDspDid_MCUBbankerror */
  { 0U, 49U }, /* signal 0 of Did DcmDspDid_MCUinternelSWversion */
  { 0U, 60U }, /* signal 0 of Did DcmDspDid_J3_Software_Number */
  { 0U, 65U }, /* signal 0 of Did DcmDspDid_Fusa_Log */
  { 0U, 62U }, /* signal 0 of Did DcmDspDid_MFC5J3_Internal_Test_Mode */
  { 0U, 61U }, /* signal 0 of Did DcmDspDid_Secure_Updating_Log */
};
#endif /* #if (DCM_DSP_USE_DIDSERVICES == STD_ON) */

#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include <Dcm_MemMap.h>

#define DCM_START_SEC_CONST_8
#include <Dcm_MemMap.h>

/** \brief Array that holds the configured sessions for read access of the didinfo entries */
STATIC CONST(Dcm_SesCtrlType, DCM_CONST) Dcm_ReadDidSesTypes[] =
{
  0x01U,0x03U,
  0x01U,0x03U,
  0x01U,0x03U,
  0x01U,0x03U,
  0xffU,
  0xffU,
  0x01U,0x03U,
  0x01U,0x03U,
  0x01U,0x03U,
  0x01U,0x03U,
  0xffU,
  0xffU,
  0xffU,
  0x01U,0x03U,
  0x01U,0x03U,
  0x01U,0x03U,
  0xffU,
  0xffU,
  0x01U,0x03U,
  0x01U,0x03U,
  0xffU,
  0x01U,0x03U,
  0x01U,0x03U,
  0x01U,0x03U,
  0x01U,0x03U,
  0x01U,0x03U,
  0x01U,0x03U,
  0x01U,0x03U,
  0x01U,0x03U,
  0x01U,0x03U,
  0x01U,0x03U,
  0x01U,0x03U,
  0x01U,0x03U,
  0x01U,0x03U,
  0x01U,0x03U,
  0x01U,0x03U,
  0x01U,0x03U,
  0x01U,0x03U,
  0x01U,0x03U,
  0x01U,0x03U,
  0x01U,0x03U,
  0x01U,0x03U,
  0x01U,0x03U,
  0x01U,0x03U,
  0x01U,0x03U,
  0x01U,0x03U,
  0x01U,0x03U,
  0x01U,0x03U,
  0x01U,0x03U,
  0x01U,0x03U,
  0x01U,0x03U,
  0x01U,0x03U,
  0x01U,0x03U,
  0x01U,0x03U,
  0x01U,0x03U,
  0x01U,0x03U,
  0x01U,0x03U,
  0x01U,0x03U,
  0x01U,0x03U,
  0xffU,
  0xffU,
  0x01U,0x03U,
  0x01U,0x03U,
  0x01U,0x03U,
  0xffU,
};

/** \brief Array that holds the configured security levels for write access of the didinfo
entries */
STATIC CONST(Dcm_SecLevelType, DCM_CONST) Dcm_WriteDidSecTypes[] =
{
  0x01U,
  0x01U,
  0x01U,
  0x01U,
  0x01U,
  0x01U,
  0x01U,
  0x01U,
  0x01U,
  0x01U,
  0x01U,
  0x01U,
  0x01U,
  0x01U,
  0x01U,
  0x01U,
};

/** \brief Array that holds the configured sessions for write access of the didinfo entries */
STATIC CONST(Dcm_SesCtrlType, DCM_CONST) Dcm_WriteDidSesTypes[] =
{
  0x03U,
  0x03U,0x01U,
  0x03U,
  0x03U,
  0x03U,0x01U,
  0x03U,
  0x01U,0x03U,
  0x01U,0x03U,
  0x01U,0x03U,
  0x03U,
  0x03U,0x01U,
  0x03U,0x01U,
  0x03U,
  0x03U,0x01U,
  0x03U,
  0x03U,0x01U,
};


#define DCM_STOP_SEC_CONST_8
#include <Dcm_MemMap.h>

#define DCM_START_SEC_CONST_UNSPECIFIED
#include <Dcm_MemMap.h>

/* !LINKSTO Dcm.Dsn.DidServices.ConfigurationData.DidReadAccessInfo,1 */
/** \brief Array that holds the configured read access information of the didinfo entries */
CONST(Dcm_DidReadAccessInfoType, DCM_CONST) Dcm_DidReadAccessInfo[] =
{
  {
    {
      NULL_PTR, /* SecLevels */
      &(Dcm_ReadDidSesTypes[0]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      0, /* NumSecLevels */
      2, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      NULL_PTR, /* SecLevels */
      &(Dcm_ReadDidSesTypes[2]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      0, /* NumSecLevels */
      2, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      NULL_PTR, /* SecLevels */
      &(Dcm_ReadDidSesTypes[4]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      0, /* NumSecLevels */
      2, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      NULL_PTR, /* SecLevels */
      &(Dcm_ReadDidSesTypes[6]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      0, /* NumSecLevels */
      2, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      NULL_PTR, /* SecLevels */
      &(Dcm_ReadDidSesTypes[8]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      0, /* NumSecLevels */
      1, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      NULL_PTR, /* SecLevels */
      &(Dcm_ReadDidSesTypes[9]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      0, /* NumSecLevels */
      1, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      NULL_PTR, /* SecLevels */
      &(Dcm_ReadDidSesTypes[10]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      0, /* NumSecLevels */
      2, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      NULL_PTR, /* SecLevels */
      &(Dcm_ReadDidSesTypes[12]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      0, /* NumSecLevels */
      2, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      NULL_PTR, /* SecLevels */
      &(Dcm_ReadDidSesTypes[14]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      0, /* NumSecLevels */
      2, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      NULL_PTR, /* SecLevels */
      &(Dcm_ReadDidSesTypes[16]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      0, /* NumSecLevels */
      2, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      NULL_PTR, /* SecLevels */
      &(Dcm_ReadDidSesTypes[18]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      0, /* NumSecLevels */
      1, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      NULL_PTR, /* SecLevels */
      &(Dcm_ReadDidSesTypes[19]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      0, /* NumSecLevels */
      1, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      NULL_PTR, /* SecLevels */
      &(Dcm_ReadDidSesTypes[20]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      0, /* NumSecLevels */
      1, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      NULL_PTR, /* SecLevels */
      &(Dcm_ReadDidSesTypes[21]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      0, /* NumSecLevels */
      2, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      NULL_PTR, /* SecLevels */
      &(Dcm_ReadDidSesTypes[23]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      0, /* NumSecLevels */
      2, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      NULL_PTR, /* SecLevels */
      &(Dcm_ReadDidSesTypes[25]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      0, /* NumSecLevels */
      2, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      NULL_PTR, /* SecLevels */
      &(Dcm_ReadDidSesTypes[27]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      0, /* NumSecLevels */
      1, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      NULL_PTR, /* SecLevels */
      &(Dcm_ReadDidSesTypes[28]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      0, /* NumSecLevels */
      1, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      NULL_PTR, /* SecLevels */
      &(Dcm_ReadDidSesTypes[29]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      0, /* NumSecLevels */
      2, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      NULL_PTR, /* SecLevels */
      &(Dcm_ReadDidSesTypes[31]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      0, /* NumSecLevels */
      2, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      NULL_PTR, /* SecLevels */
      &(Dcm_ReadDidSesTypes[33]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      0, /* NumSecLevels */
      1, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      NULL_PTR, /* SecLevels */
      &(Dcm_ReadDidSesTypes[34]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      0, /* NumSecLevels */
      2, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      NULL_PTR, /* SecLevels */
      &(Dcm_ReadDidSesTypes[36]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      0, /* NumSecLevels */
      2, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      NULL_PTR, /* SecLevels */
      &(Dcm_ReadDidSesTypes[38]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      0, /* NumSecLevels */
      2, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      NULL_PTR, /* SecLevels */
      &(Dcm_ReadDidSesTypes[40]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      0, /* NumSecLevels */
      2, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      NULL_PTR, /* SecLevels */
      &(Dcm_ReadDidSesTypes[42]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      0, /* NumSecLevels */
      2, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      NULL_PTR, /* SecLevels */
      &(Dcm_ReadDidSesTypes[44]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      0, /* NumSecLevels */
      2, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      NULL_PTR, /* SecLevels */
      &(Dcm_ReadDidSesTypes[46]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      0, /* NumSecLevels */
      2, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      NULL_PTR, /* SecLevels */
      &(Dcm_ReadDidSesTypes[48]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      0, /* NumSecLevels */
      2, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      NULL_PTR, /* SecLevels */
      &(Dcm_ReadDidSesTypes[50]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      0, /* NumSecLevels */
      2, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      NULL_PTR, /* SecLevels */
      &(Dcm_ReadDidSesTypes[52]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      0, /* NumSecLevels */
      2, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      NULL_PTR, /* SecLevels */
      &(Dcm_ReadDidSesTypes[54]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      0, /* NumSecLevels */
      2, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      NULL_PTR, /* SecLevels */
      &(Dcm_ReadDidSesTypes[56]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      0, /* NumSecLevels */
      2, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      NULL_PTR, /* SecLevels */
      &(Dcm_ReadDidSesTypes[58]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      0, /* NumSecLevels */
      2, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      NULL_PTR, /* SecLevels */
      &(Dcm_ReadDidSesTypes[60]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      0, /* NumSecLevels */
      2, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      NULL_PTR, /* SecLevels */
      &(Dcm_ReadDidSesTypes[62]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      0, /* NumSecLevels */
      2, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      NULL_PTR, /* SecLevels */
      &(Dcm_ReadDidSesTypes[64]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      0, /* NumSecLevels */
      2, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      NULL_PTR, /* SecLevels */
      &(Dcm_ReadDidSesTypes[66]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      0, /* NumSecLevels */
      2, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      NULL_PTR, /* SecLevels */
      &(Dcm_ReadDidSesTypes[68]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      0, /* NumSecLevels */
      2, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      NULL_PTR, /* SecLevels */
      &(Dcm_ReadDidSesTypes[70]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      0, /* NumSecLevels */
      2, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      NULL_PTR, /* SecLevels */
      &(Dcm_ReadDidSesTypes[72]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      0, /* NumSecLevels */
      2, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      NULL_PTR, /* SecLevels */
      &(Dcm_ReadDidSesTypes[74]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      0, /* NumSecLevels */
      2, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      NULL_PTR, /* SecLevels */
      &(Dcm_ReadDidSesTypes[76]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      0, /* NumSecLevels */
      2, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      NULL_PTR, /* SecLevels */
      &(Dcm_ReadDidSesTypes[78]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      0, /* NumSecLevels */
      2, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      NULL_PTR, /* SecLevels */
      &(Dcm_ReadDidSesTypes[80]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      0, /* NumSecLevels */
      2, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      NULL_PTR, /* SecLevels */
      &(Dcm_ReadDidSesTypes[82]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      0, /* NumSecLevels */
      2, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      NULL_PTR, /* SecLevels */
      &(Dcm_ReadDidSesTypes[84]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      0, /* NumSecLevels */
      2, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      NULL_PTR, /* SecLevels */
      &(Dcm_ReadDidSesTypes[86]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      0, /* NumSecLevels */
      2, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      NULL_PTR, /* SecLevels */
      &(Dcm_ReadDidSesTypes[88]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      0, /* NumSecLevels */
      2, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      NULL_PTR, /* SecLevels */
      &(Dcm_ReadDidSesTypes[90]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      0, /* NumSecLevels */
      2, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      NULL_PTR, /* SecLevels */
      &(Dcm_ReadDidSesTypes[92]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      0, /* NumSecLevels */
      2, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      NULL_PTR, /* SecLevels */
      &(Dcm_ReadDidSesTypes[94]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      0, /* NumSecLevels */
      2, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      NULL_PTR, /* SecLevels */
      &(Dcm_ReadDidSesTypes[96]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      0, /* NumSecLevels */
      2, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      NULL_PTR, /* SecLevels */
      &(Dcm_ReadDidSesTypes[98]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      0, /* NumSecLevels */
      2, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      NULL_PTR, /* SecLevels */
      &(Dcm_ReadDidSesTypes[100]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      0, /* NumSecLevels */
      2, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      NULL_PTR, /* SecLevels */
      &(Dcm_ReadDidSesTypes[102]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      0, /* NumSecLevels */
      2, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      NULL_PTR, /* SecLevels */
      &(Dcm_ReadDidSesTypes[104]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      0, /* NumSecLevels */
      2, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      NULL_PTR, /* SecLevels */
      &(Dcm_ReadDidSesTypes[106]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      0, /* NumSecLevels */
      2, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      NULL_PTR, /* SecLevels */
      &(Dcm_ReadDidSesTypes[108]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      0, /* NumSecLevels */
      2, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      NULL_PTR, /* SecLevels */
      &(Dcm_ReadDidSesTypes[110]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      0, /* NumSecLevels */
      1, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      NULL_PTR, /* SecLevels */
      &(Dcm_ReadDidSesTypes[111]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      0, /* NumSecLevels */
      1, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      NULL_PTR, /* SecLevels */
      NULL_PTR, /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      0, /* NumSecLevels */
      0, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      NULL_PTR, /* SecLevels */
      &(Dcm_ReadDidSesTypes[112]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      0, /* NumSecLevels */
      2, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      NULL_PTR, /* SecLevels */
      &(Dcm_ReadDidSesTypes[114]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      0, /* NumSecLevels */
      2, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      NULL_PTR, /* SecLevels */
      &(Dcm_ReadDidSesTypes[116]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      0, /* NumSecLevels */
      2, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      NULL_PTR, /* SecLevels */
      &(Dcm_ReadDidSesTypes[118]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      0, /* NumSecLevels */
      1, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
};

/* !LINKSTO Dcm.Dsn.DidServices.ConfigurationData.DidWriteAccessInfo,1 */
/** \brief Array that holds the configured write access information of the didinfo entries */
CONST(Dcm_DidWriteAccessInfoType, DCM_CONST) Dcm_DidWriteAccessInfo[] =
{
  {
    {
      &(Dcm_WriteDidSecTypes[0]), /* SecLevels */
      &(Dcm_WriteDidSesTypes[0]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      1, /* NumSecLevels */
      1, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      &(Dcm_WriteDidSecTypes[1]), /* SecLevels */
      &(Dcm_WriteDidSesTypes[1]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      1, /* NumSecLevels */
      2, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      &(Dcm_WriteDidSecTypes[2]), /* SecLevels */
      &(Dcm_WriteDidSesTypes[3]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      1, /* NumSecLevels */
      1, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      &(Dcm_WriteDidSecTypes[3]), /* SecLevels */
      &(Dcm_WriteDidSesTypes[4]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      1, /* NumSecLevels */
      1, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      &(Dcm_WriteDidSecTypes[4]), /* SecLevels */
      &(Dcm_WriteDidSesTypes[5]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      1, /* NumSecLevels */
      2, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      &(Dcm_WriteDidSecTypes[5]), /* SecLevels */
      &(Dcm_WriteDidSesTypes[7]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      1, /* NumSecLevels */
      1, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      &(Dcm_WriteDidSecTypes[6]), /* SecLevels */
      &(Dcm_WriteDidSesTypes[8]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      1, /* NumSecLevels */
      2, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      &(Dcm_WriteDidSecTypes[7]), /* SecLevels */
      &(Dcm_WriteDidSesTypes[10]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      1, /* NumSecLevels */
      2, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      &(Dcm_WriteDidSecTypes[8]), /* SecLevels */
      &(Dcm_WriteDidSesTypes[12]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      1, /* NumSecLevels */
      2, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      &(Dcm_WriteDidSecTypes[9]), /* SecLevels */
      &(Dcm_WriteDidSesTypes[14]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      1, /* NumSecLevels */
      1, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      &(Dcm_WriteDidSecTypes[10]), /* SecLevels */
      &(Dcm_WriteDidSesTypes[15]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      1, /* NumSecLevels */
      2, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      &(Dcm_WriteDidSecTypes[11]), /* SecLevels */
      &(Dcm_WriteDidSesTypes[17]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      1, /* NumSecLevels */
      2, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      &(Dcm_WriteDidSecTypes[12]), /* SecLevels */
      &(Dcm_WriteDidSesTypes[19]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      1, /* NumSecLevels */
      1, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      &(Dcm_WriteDidSecTypes[13]), /* SecLevels */
      &(Dcm_WriteDidSesTypes[20]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      1, /* NumSecLevels */
      2, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      &(Dcm_WriteDidSecTypes[14]), /* SecLevels */
      &(Dcm_WriteDidSesTypes[22]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      1, /* NumSecLevels */
      1, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
  {
    {
      &(Dcm_WriteDidSecTypes[15]), /* SecLevels */
      &(Dcm_WriteDidSesTypes[23]), /* SesCtrls */
      NULL_PTR, /* ModeRuleDidFunction */
      1, /* NumSecLevels */
      2, /* NumSesCtrls */
    } /* AccessInfoBase */
  },
};

/* !LINKSTO Dcm.Dsn.DidServices.ConfigurationData.DidIoctlAccessInfo,1 */
/* !LINKSTO Dcm.Dsn.DidServices.ConfigurationData.DidReadScalingAccessInfo,1 */
/* !LINKSTO Dcm.Dsn.DidServices.ConfigurationData.DidInfo,1 */
/** \brief Array that holds the configured didinfo entries that are enabled */
CONST(Dcm_DidInfoType, DCM_CONST) Dcm_DidInfo[] =
{
  {
    0, /* ReadAccessInfoIdx */
    DCM_DIDWRITEACCESSINFOIDX_INVALID, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
  {
    1, /* ReadAccessInfoIdx */
    DCM_DIDWRITEACCESSINFOIDX_INVALID, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
  {
    2, /* ReadAccessInfoIdx */
    DCM_DIDWRITEACCESSINFOIDX_INVALID, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
  {
    3, /* ReadAccessInfoIdx */
    DCM_DIDWRITEACCESSINFOIDX_INVALID, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
  {
    4, /* ReadAccessInfoIdx */
    DCM_DIDWRITEACCESSINFOIDX_INVALID, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
  {
    5, /* ReadAccessInfoIdx */
    0, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
  {
    6, /* ReadAccessInfoIdx */
    DCM_DIDWRITEACCESSINFOIDX_INVALID, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
  {
    7, /* ReadAccessInfoIdx */
    DCM_DIDWRITEACCESSINFOIDX_INVALID, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
  {
    8, /* ReadAccessInfoIdx */
    DCM_DIDWRITEACCESSINFOIDX_INVALID, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
  {
    9, /* ReadAccessInfoIdx */
    DCM_DIDWRITEACCESSINFOIDX_INVALID, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
  {
    10, /* ReadAccessInfoIdx */
    DCM_DIDWRITEACCESSINFOIDX_INVALID, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
  {
    11, /* ReadAccessInfoIdx */
    DCM_DIDWRITEACCESSINFOIDX_INVALID, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
  {
    12, /* ReadAccessInfoIdx */
    DCM_DIDWRITEACCESSINFOIDX_INVALID, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
  {
    13, /* ReadAccessInfoIdx */
    DCM_DIDWRITEACCESSINFOIDX_INVALID, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
  {
    14, /* ReadAccessInfoIdx */
    1, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
  {
    15, /* ReadAccessInfoIdx */
    DCM_DIDWRITEACCESSINFOIDX_INVALID, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
  {
    16, /* ReadAccessInfoIdx */
    DCM_DIDWRITEACCESSINFOIDX_INVALID, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
  {
    17, /* ReadAccessInfoIdx */
    2, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
  {
    18, /* ReadAccessInfoIdx */
    3, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
  {
    19, /* ReadAccessInfoIdx */
    4, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
  {
    20, /* ReadAccessInfoIdx */
    DCM_DIDWRITEACCESSINFOIDX_INVALID, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
  {
    21, /* ReadAccessInfoIdx */
    DCM_DIDWRITEACCESSINFOIDX_INVALID, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
  {
    22, /* ReadAccessInfoIdx */
    DCM_DIDWRITEACCESSINFOIDX_INVALID, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
  {
    23, /* ReadAccessInfoIdx */
    DCM_DIDWRITEACCESSINFOIDX_INVALID, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
  {
    24, /* ReadAccessInfoIdx */
    DCM_DIDWRITEACCESSINFOIDX_INVALID, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
  {
    25, /* ReadAccessInfoIdx */
    DCM_DIDWRITEACCESSINFOIDX_INVALID, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
  {
    26, /* ReadAccessInfoIdx */
    DCM_DIDWRITEACCESSINFOIDX_INVALID, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
  {
    27, /* ReadAccessInfoIdx */
    DCM_DIDWRITEACCESSINFOIDX_INVALID, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
  {
    28, /* ReadAccessInfoIdx */
    DCM_DIDWRITEACCESSINFOIDX_INVALID, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
  {
    29, /* ReadAccessInfoIdx */
    DCM_DIDWRITEACCESSINFOIDX_INVALID, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
  {
    30, /* ReadAccessInfoIdx */
    5, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
  {
    31, /* ReadAccessInfoIdx */
    6, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
  {
    32, /* ReadAccessInfoIdx */
    7, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
  {
    33, /* ReadAccessInfoIdx */
    8, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
  {
    34, /* ReadAccessInfoIdx */
    DCM_DIDWRITEACCESSINFOIDX_INVALID, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
  {
    35, /* ReadAccessInfoIdx */
    DCM_DIDWRITEACCESSINFOIDX_INVALID, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
  {
    36, /* ReadAccessInfoIdx */
    DCM_DIDWRITEACCESSINFOIDX_INVALID, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
  {
    37, /* ReadAccessInfoIdx */
    DCM_DIDWRITEACCESSINFOIDX_INVALID, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
  {
    38, /* ReadAccessInfoIdx */
    DCM_DIDWRITEACCESSINFOIDX_INVALID, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
  {
    39, /* ReadAccessInfoIdx */
    DCM_DIDWRITEACCESSINFOIDX_INVALID, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
  {
    40, /* ReadAccessInfoIdx */
    DCM_DIDWRITEACCESSINFOIDX_INVALID, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
  {
    41, /* ReadAccessInfoIdx */
    9, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
  {
    42, /* ReadAccessInfoIdx */
    10, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
  {
    43, /* ReadAccessInfoIdx */
    11, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
  {
    44, /* ReadAccessInfoIdx */
    12, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
  {
    45, /* ReadAccessInfoIdx */
    DCM_DIDWRITEACCESSINFOIDX_INVALID, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
  {
    46, /* ReadAccessInfoIdx */
    DCM_DIDWRITEACCESSINFOIDX_INVALID, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
  {
    47, /* ReadAccessInfoIdx */
    DCM_DIDWRITEACCESSINFOIDX_INVALID, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
  {
    48, /* ReadAccessInfoIdx */
    DCM_DIDWRITEACCESSINFOIDX_INVALID, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
  {
    49, /* ReadAccessInfoIdx */
    DCM_DIDWRITEACCESSINFOIDX_INVALID, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
  {
    50, /* ReadAccessInfoIdx */
    DCM_DIDWRITEACCESSINFOIDX_INVALID, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
  {
    51, /* ReadAccessInfoIdx */
    DCM_DIDWRITEACCESSINFOIDX_INVALID, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
  {
    52, /* ReadAccessInfoIdx */
    DCM_DIDWRITEACCESSINFOIDX_INVALID, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
  {
    53, /* ReadAccessInfoIdx */
    DCM_DIDWRITEACCESSINFOIDX_INVALID, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
  {
    54, /* ReadAccessInfoIdx */
    DCM_DIDWRITEACCESSINFOIDX_INVALID, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
  {
    55, /* ReadAccessInfoIdx */
    DCM_DIDWRITEACCESSINFOIDX_INVALID, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
  {
    56, /* ReadAccessInfoIdx */
    DCM_DIDWRITEACCESSINFOIDX_INVALID, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
  {
    57, /* ReadAccessInfoIdx */
    13, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
  {
    58, /* ReadAccessInfoIdx */
    DCM_DIDWRITEACCESSINFOIDX_INVALID, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
  {
    59, /* ReadAccessInfoIdx */
    DCM_DIDWRITEACCESSINFOIDX_INVALID, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
  {
    60, /* ReadAccessInfoIdx */
    DCM_DIDWRITEACCESSINFOIDX_INVALID, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
  {
    61, /* ReadAccessInfoIdx */
    DCM_DIDWRITEACCESSINFOIDX_INVALID, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
  {
    62, /* ReadAccessInfoIdx */
    DCM_DIDWRITEACCESSINFOIDX_INVALID, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
  {
    63, /* ReadAccessInfoIdx */
    14, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
  {
    64, /* ReadAccessInfoIdx */
    15, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
  {
    65, /* ReadAccessInfoIdx */
    DCM_DIDWRITEACCESSINFOIDX_INVALID, /* WriteAccessInfoIdx */
    DCM_DIDIOCTLACCESSINFOIDX_INVALID, /* IoctlAccessInfoIdx */
  },
};

/* !LINKSTO Dcm.Dsn.DidServices.ConfigurationData.DidRangeConfig,1 */

#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include <Dcm_MemMap.h>

#if ((DCM_DSP_USE_DIDSERVICES == STD_ON) && (DCM_DID_REF_COUNT > 0))
#define DCM_START_SEC_CONST_16
#include <Dcm_MemMap.h>

/* !LINKSTO Dcm.Dsn.DidServices.ConfigurationData.DidRefers,1 */
/* Array for Dids which is referred from other Dids. */
CONST(uint16,DCM_CONST) Dcm_DidRefers[DCM_DID_REF_COUNT] =
{
};

#define DCM_STOP_SEC_CONST_16
#include <Dcm_MemMap.h>
#endif /* #if ((DCM_DSP_USE_DIDSERVICES == STD_ON) && (DCM_DID_REF_COUNT > 0)) */
/*==================[internal data]==============================================================*/

/*==================[external constants]=========================================================*/
#define DCM_START_SEC_CONST_UNSPECIFIED
#include <Dcm_MemMap.h>

/* !LINKSTO Dcm.Dsn.DidServices.ConfigurationData.DidConfig,1 */
CONST(Dcm_DidConfigType, DCM_CONST) Dcm_DidConfig[] =
{
  {
    0x103U, /* Did */
    1U, /* NumSignals */
    0U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    0U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 21 */
  {
    0x11b5U, /* Did */
    1U, /* NumSignals */
    1U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    1U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 29 */
  {
    0x11b7U, /* Did */
    1U, /* NumSignals */
    2U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    2U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 25 */
  {
    0x3bafU, /* Did */
    1U, /* NumSignals */
    3U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    3U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 20 */
  {
    0xf010U, /* Did */
    1U, /* NumSignals */
    4U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    4U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 51 */
  {
    0xf089U, /* Did */
    1U, /* NumSignals */
    5U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    5U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 4 */
  {
    0xf120U, /* Did */
    1U, /* NumSignals */
    6U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    6U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 0 */
  {
    0xf121U, /* Did */
    1U, /* NumSignals */
    7U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    7U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 1 */
  {
    0xf122U, /* Did */
    1U, /* NumSignals */
    8U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    8U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 2 */
  {
    0xf123U, /* Did */
    1U, /* NumSignals */
    9U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    9U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 13 */
  {
    0xf170U, /* Did */
    1U, /* NumSignals */
    10U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    10U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 9 */
  {
    0xf171U, /* Did */
    1U, /* NumSignals */
    11U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    11U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 10 */
  {
    0xf184U, /* Did */
    1U, /* NumSignals */
    12U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    12U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 11 */
  {
    0xf186U, /* Did */
    1U, /* NumSignals */
    13U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    13U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 30 */
  {
    0xf187U, /* Did */
    1U, /* NumSignals */
    14U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    14U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 5 */
  {
    0xf188U, /* Did */
    1U, /* NumSignals */
    15U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    15U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 12 */
  {
    0xf189U, /* Did */
    1U, /* NumSignals */
    16U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    16U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 3 */
  {
    0xf18aU, /* Did */
    1U, /* NumSignals */
    17U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    17U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 6 */
  {
    0xf18cU, /* Did */
    1U, /* NumSignals */
    18U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    18U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 7 */
  {
    0xf190U, /* Did */
    1U, /* NumSignals */
    19U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    19U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 8 */
  {
    0xf191U, /* Did */
    1U, /* NumSignals */
    20U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    20U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 14 */
  {
    0xf194U, /* Did */
    1U, /* NumSignals */
    21U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    21U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 15 */
  {
    0xf1a3U, /* Did */
    1U, /* NumSignals */
    22U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    22U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 52 */
  {
    0xf1a4U, /* Did */
    1U, /* NumSignals */
    23U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    23U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 53 */
  {
    0xf1a5U, /* Did */
    1U, /* NumSignals */
    24U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    24U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 54 */
  {
    0xf1a7U, /* Did */
    1U, /* NumSignals */
    25U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    25U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 55 */
  {
    0xf1a8U, /* Did */
    1U, /* NumSignals */
    26U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    26U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 56 */
  {
    0xf1a9U, /* Did */
    1U, /* NumSignals */
    27U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    27U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 57 */
  {
    0xf1aaU, /* Did */
    1U, /* NumSignals */
    28U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    28U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 58 */
  {
    0xf1abU, /* Did */
    1U, /* NumSignals */
    29U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    29U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 59 */
  {
    0xf1f0U, /* Did */
    1U, /* NumSignals */
    30U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    30U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 45 */
  {
    0xf1f1U, /* Did */
    1U, /* NumSignals */
    31U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    31U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 16 */
  {
    0xf1f2U, /* Did */
    1U, /* NumSignals */
    32U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    32U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 17 */
  {
    0xf1f3U, /* Did */
    1U, /* NumSignals */
    33U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    33U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 18 */
  {
    0xf1f5U, /* Did */
    1U, /* NumSignals */
    34U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    34U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 19 */
  {
    0xf1f7U, /* Did */
    1U, /* NumSignals */
    35U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    35U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 22 */
  {
    0xf1f8U, /* Did */
    1U, /* NumSignals */
    36U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    36U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 23 */
  {
    0xf1f9U, /* Did */
    1U, /* NumSignals */
    37U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    37U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 24 */
  {
    0xf1faU, /* Did */
    1U, /* NumSignals */
    38U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    38U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 26 */
  {
    0xf1fbU, /* Did */
    1U, /* NumSignals */
    39U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    39U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 27 */
  {
    0xf1fcU, /* Did */
    1U, /* NumSignals */
    40U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    40U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 28 */
  {
    0xf1fdU, /* Did */
    1U, /* NumSignals */
    41U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    41U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 63 */
  {
    0xf1feU, /* Did */
    1U, /* NumSignals */
    42U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    42U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 31 */
  {
    0xf1ffU, /* Did */
    1U, /* NumSignals */
    43U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    43U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 32 */
  {
    0xfd00U, /* Did */
    1U, /* NumSignals */
    44U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    44U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 64 */
  {
    0xfd14U, /* Did */
    1U, /* NumSignals */
    45U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    45U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 33 */
  {
    0xfd15U, /* Did */
    1U, /* NumSignals */
    46U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    46U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 34 */
  {
    0xfd16U, /* Did */
    1U, /* NumSignals */
    47U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    47U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 35 */
  {
    0xfd17U, /* Did */
    1U, /* NumSignals */
    48U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    48U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 36 */
  {
    0xfd18U, /* Did */
    1U, /* NumSignals */
    49U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    49U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 37 */
  {
    0xfd19U, /* Did */
    1U, /* NumSignals */
    50U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    50U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 38 */
  {
    0xfd1eU, /* Did */
    1U, /* NumSignals */
    51U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    51U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 39 */
  {
    0xfd1fU, /* Did */
    1U, /* NumSignals */
    52U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    52U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 40 */
  {
    0xfd20U, /* Did */
    1U, /* NumSignals */
    53U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    53U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 41 */
  {
    0xfd21U, /* Did */
    1U, /* NumSignals */
    54U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    54U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 42 */
  {
    0xfd22U, /* Did */
    1U, /* NumSignals */
    55U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    55U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 43 */
  {
    0xfd23U, /* Did */
    1U, /* NumSignals */
    56U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    56U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 44 */
  {
    0xfd24U, /* Did */
    1U, /* NumSignals */
    57U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    57U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 46 */
  {
    0xfd25U, /* Did */
    1U, /* NumSignals */
    58U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    58U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 47 */
  {
    0xfd26U, /* Did */
    1U, /* NumSignals */
    59U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    59U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 48 */
  {
    0xfd27U, /* Did */
    1U, /* NumSignals */
    60U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    60U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 49 */
  {
    0xfd28U, /* Did */
    1U, /* NumSignals */
    61U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    61U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 50 */
  {
    0xfd29U, /* Did */
    1U, /* NumSignals */
    62U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    62U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 60 */
  {
    0xfd2aU, /* Did */
    1U, /* NumSignals */
    63U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    63U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 65 */
  {
    0xfdffU, /* Did */
    1U, /* NumSignals */
    64U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    64U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 62 */
  {
    0xfec0U, /* Did */
    1U, /* NumSignals */
    65U, /* DidInfoIdx */
    DCM_DIDREFERSIDX_INVALID, /* DidRefersIdx */
    65U, /* DidSignalsIdx */
    0U, /* NumRefDids */
  }, /* index: 61 */
};

/* Constant holding the pointer to the configured mode rule to be used when re-enabling DTC */
CONST(Dcm_ModeRuleFunctionType, DCM_CONST) Dcm_DspModeRuleDTCFunction =
  NULL_PTR;

#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include <Dcm_MemMap.h>

#define DCM_START_SEC_CONST_8
#include <Dcm_MemMap.h>

/** \brief Configuration structure */
CONST(Dcm_ConfigType, DCM_CONST) DcmConfigSet_0 = { 0U };


/* Array of configuration information of all Supported AddressAndLengthFormatIdentifiers */
CONST(uint8, DCM_CONST) Dcm_SupportedAddAndLenFormatIds[DCM_NUM_ADDR_LENGTH_FORMAT_IDENTIFIER] =
{
  0x44U,
};


#define DCM_STOP_SEC_CONST_8
#include <Dcm_MemMap.h>

#define DCM_START_SEC_CONST_UNSPECIFIED
#include <Dcm_MemMap.h>

/* Array of configuration information for diagnostic sessions */
STATIC CONST(Dcm_SesTabEntryConfigType, DCM_CONST) Dcm_SesTabEntryConfig0[4] =
{
  {
    500U,/*P2StarMaxTime*/
    5U, /*P2MaxTime*/
    1U,/* Maximum number of ResponsePending messages */
    DCM_NO_BOOT,/*specifies whether this session allows
    to jump to Bootloader */
    1U,/* Session type */
    RTE_MODE_DcmDiagnosticSessionControl_DCM_DEFAULT_SESSION /* Session type generate by Rte */
  },
  {
    500U,/*P2StarMaxTime*/
    5U, /*P2MaxTime*/
    1U,/* Maximum number of ResponsePending messages */
    DCM_NO_BOOT,/*specifies whether this session allows
    to jump to Bootloader */
    3U,/* Session type */
    RTE_MODE_DcmDiagnosticSessionControl_DCM_EXTENDED_DIAGNOSTIC_SESSION /* Session type generate by Rte */
  },
  {
    500U,/*P2StarMaxTime*/
    5U, /*P2MaxTime*/
    1U,/* Maximum number of ResponsePending messages */
    DCM_SYS_BOOT,/*specifies whether this session allows
    to jump to Bootloader */
    2U,/* Session type */
    RTE_MODE_DcmDiagnosticSessionControl_DCM_PROGRAMMING_SESSION /* Session type generate by Rte */
  },
  {
    500U,/*P2StarMaxTime*/
    50U, /*P2MaxTime*/
    1U,/* Maximum number of ResponsePending messages */
    DCM_NO_BOOT,/*specifies whether this session allows
    to jump to Bootloader */
    255U,/* Session type */
    RTE_MODE_DcmDiagnosticSessionControl_DCM_ALL_SESSION_LEVEL /* Session type generate by Rte */
  },
};

/* Holds configuration information for diagnostic sessions */
CONST(Dcm_SesTabConfigType, DCM_CONST) Dcm_SesTabConfig[DCM_NUM_PROTOCOL] =
{
  {
    Dcm_SesTabEntryConfig0, /* Pointer to session configurations */
    4U, /* Number of configured sessions */
    0U /* Index of default session */
  },
};

/* Initialize global array holding the configuration for the service Id table */
CONST(Dcm_SidTabConfigType, DCM_CONST) Dcm_SidTabConfig[1] =
{
  {
    Dcm_SidTabEntryConfig0, /* Pointer to array of service table entries */
    13U /* Number of service entries within this table */
  },
};



#if ((DCM_DID_DATA_TABLE_SIZE > 0U) && (DCM_DID_SIGNALS_COUNT > 0))
/* !LINKSTO Dcm.Dsn.DidSignals.ConfigurationData.DidDataTable,1 */
CONST(Dcm_VariableFunctionPointerRecordType, DCM_CONST) Dcm_DidDataTable[DCM_DID_DATA_TABLE_SIZE] =
{
  /* Deviation MISRAC2012-1 <START> */ /* Deviation MISRA-3  <START> */
  
  /* Available function pointers for DcmDspData_F120 */
  /* ReadData sync c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DcmDspData_F120_ReadData},

  /* Available function pointers for DcmDspData_F121 */
  /* ReadData sync c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DcmDspData_F121_ReadData},

  /* Available function pointers for DcmDspData_F122 */
  /* ReadData sync c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DcmDspData_F122_ReadData},

  /* Available function pointers for DcmDspData_F189 */
  /* ReadData sync c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DcmDspData_F189_ReadData},

  /* Available function pointers for DcmDspData_F089 */
  /* CallReadData async c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DcmDspData_F089_ReadData},
  /* Write async c-s fixed length */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DcmDspData_F089_WriteData},

  /* Available function pointers for DcmDspData_F187 */
  /* CallReadData async c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DcmDspData_F187_ReadData},
  /* Write async c-s fixed length */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DcmDspData_F187_WriteData},

  /* Available function pointers for DcmDspData_F18A */
  /* CallReadData async c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DcmDspData_F18A_ReadData},
  /* Write async c-s fixed length */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DcmDspData_F18A_WriteData},

  /* Available function pointers for DcmDspData_F18C */
  /* CallReadData async c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DcmDspData_F18C_ReadData},
  /* Write async c-s fixed length */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DcmDspData_F18C_WriteData},

  /* Available function pointers for DcmDspData_F190 */
  /* CallReadData async c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DcmDspData_F190_ReadData},
  /* Write async c-s fixed length */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DcmDspData_F190_WriteData},

  /* Available function pointers for DcmDspData_F170 */
  /* ReadData sync c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DcmDspData_F170_ReadData},

  /* Available function pointers for DcmDspData_F171 */
  /* ReadData sync c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DcmDspData_F171_ReadData},

  /* Available function pointers for DcmDspData_F184 */
  /* CallReadData async c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DcmDspData_F184_ReadData},

  /* Available function pointers for DcmDspData_F188 */
  /* ReadData sync c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DcmDspData_F188_ReadData},

  /* Available function pointers for DcmDspData_F123 */
  /* ReadData sync c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DcmDspData_F123_ReadData},

  /* Available function pointers for DcmDspData_F191 */
  /* ReadData sync c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DcmDspData_F191_ReadData},

  /* Available function pointers for DcmDspData_F194 */
  /* CallReadData async c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DcmDspData_F194_ReadData},

  /* Available function pointers for DcmDspData_F1F1 */
  /* CallReadData async c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DcmDspData_F1F1_ReadData},
  /* Write async c-s fixed length */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DcmDspData_F1F1_WriteData},

  /* Available function pointers for DcmDspData_F1F2 */
  /* CallReadData async c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DcmDspData_F1F2_ReadData},
  /* Write async c-s fixed length */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DcmDspData_F1F2_WriteData},

  /* Available function pointers for DcmDspData_F1F3 */
  /* CallReadData async c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DcmDspData_F1F3_ReadData},
  /* Write async c-s fixed length */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DcmDspData_F1F3_WriteData},

  /* Available function pointers for DcmDspData_F1F5 */
  /* CallReadData async c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DcmDspData_F1F5_ReadData},

  /* Available function pointers for DcmDspData_3BAF */
  /* CallReadData async c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DcmDspData_3BAF_ReadData},

  /* Available function pointers for DcmDspData_0103 */
  /* CallReadData async c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DcmDspData_0103_ReadData},

  /* Available function pointers for DcmDspData_F1F7 */
  /* CallReadData async c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DcmDspData_F1F7_ReadData},

  /* Available function pointers for DcmDspData_F1F8 */
  /* CallReadData async c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DcmDspData_F1F8_ReadData},

  /* Available function pointers for DcmDspData_F1F9 */
  /* CallReadData async c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DcmDspData_F1F9_ReadData},

  /* Available function pointers for DcmDspData_11B7 */
  /* ReadData sync c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DcmDspData_11B7_ReadData},

  /* Available function pointers for DcmDspData_F1FA */
  /* CallReadData async c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DcmDspData_F1FA_ReadData},

  /* Available function pointers for DcmDspData_F1FB */
  /* CallReadData async c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DcmDspData_F1FB_ReadData},

  /* Available function pointers for DcmDspData_F1FC */
  /* CallReadData async c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DcmDspData_F1FC_ReadData},

  /* Available function pointers for DcmDspData_11B5 */
  /* ReadData sync c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DcmDspData_11B5_ReadData},

  /* Available function pointers for DcmDspData_F186 */
  /* ReadData sync c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DcmDspData_F186_ReadData},

  /* Available function pointers for DcmDspData_F1FE */
  /* CallReadData async c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DcmDspData_F1FE_ReadData},
  /* Write async c-s fixed length */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DcmDspData_F1FE_WriteData},

  /* Available function pointers for DcmDspData_F1FF */
  /* CallReadData async c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DcmDspData_F1FF_ReadData},
  /* Write async c-s fixed length */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DcmDspData_F1FF_WriteData},

  /* Available function pointers for DcmDspData_FD14 */
  /* CallReadData async c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DcmDspData_FD14_ReadData},

  /* Available function pointers for DcmDspData_FD15 */
  /* CallReadData async c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DcmDspData_FD15_ReadData},

  /* Available function pointers for DcmDspData_FD16 */
  /* CallReadData async c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DcmDspData_FD16_ReadData},

  /* Available function pointers for DcmDspData_FD17 */
  /* CallReadData async c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DcmDspData_FD17_ReadData},

  /* Available function pointers for DcmDspData_FD18 */
  /* CallReadData async c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DcmDspData_FD18_ReadData},

  /* Available function pointers for DcmDspData_FD19 */
  /* CallReadData async c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DcmDspData_FD19_ReadData},

  /* Available function pointers for DcmDspData_FD1E */
  /* CallReadData async c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DcmDspData_FD1E_ReadData},

  /* Available function pointers for DcmDspData_FD1F */
  /* CallReadData async c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DcmDspData_FD1F_ReadData},

  /* Available function pointers for DcmDspData_FD20 */
  /* CallReadData async c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DcmDspData_FD20_ReadData},

  /* Available function pointers for DcmDspData_FD21 */
  /* ReadData sync c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DcmDspData_FD21_ReadData},

  /* Available function pointers for DcmDspData_FD22 */
  /* CallReadData async c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DcmDspData_FD22_ReadData},

  /* Available function pointers for DcmDspData_FD23 */
  /* CallReadData async c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DcmDspData_FD23_ReadData},

  /* Available function pointers for DcmDspData_F1F0 */
  /* CallReadData async c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DcmDspData_F1F0_ReadData},
  /* Write async c-s fixed length */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DcmDspData_F1F0_WriteData},

  /* Available function pointers for DcmDspData_FD24 */
  /* CallReadData async c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DcmDspData_FD24_ReadData},
  /* Write async c-s fixed length */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DcmDspData_FD24_WriteData},

  /* Available function pointers for DcmDspData_FD26 */
  /* ReadData sync c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DcmDspData_FD26_ReadData},

  /* Available function pointers for DcmDspData_FD27 */
  /* ReadData sync c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DcmDspData_FD27_ReadData},

  /* Available function pointers for DcmDspData_FD28 */
  /* ReadData sync c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DcmDspData_FD28_ReadData},

  /* Available function pointers for DcmDspData_FD25 */
  /* CallReadData async c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DcmDspData_FD25_ReadData},

  /* Available function pointers for DcmDspData_F010 */
  /* Ptr to ConditionCheckRead() for sync operation client-server */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DcmDspData_F010_ConditionCheckRead},
  /* ReadData sync c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DcmDspData_F010_ReadData},

  /* Available function pointers for DcmDspData_F1A3 */
  /* CallReadData async c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DcmDspData_F1A3_ReadData},

  /* Available function pointers for DcmDspData_F1A4 */
  /* CallReadData async c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DcmDspData_F1A4_ReadData},

  /* Available function pointers for DcmDspData_F1A5 */
  /* CallReadData async c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DcmDspData_F1A5_ReadData},

  /* Available function pointers for DcmDspData_F1A7 */
  /* CallReadData async c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DcmDspData_F1A7_ReadData},

  /* Available function pointers for DcmDspData_F1A8 */
  /* CallReadData async c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DcmDspData_F1A8_ReadData},

  /* Available function pointers for DcmDspData_F1A9 */
  /* CallReadData async c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DcmDspData_F1A9_ReadData},

  /* Available function pointers for DcmDspData_F1AA */
  /* CallReadData async c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DcmDspData_F1AA_ReadData},

  /* Available function pointers for DcmDspData_F1AB */
  /* CallReadData async c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DcmDspData_F1AB_ReadData},

  /* Available function pointers for DcmDspData_FD29 */
  /* CallReadData async c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DcmDspData_FD29_ReadData},

  /* Available function pointers for DcmDspData_FEC0 */
  /* CallReadData async c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DcmDspData_FEC0_ReadData},

  /* Available function pointers for DcmDspData_FDFF */
  /* CallReadData async c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DcmDspData_FDFF_ReadData},
  /* Write async c-s fixed length */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DcmDspData_FDFF_WriteData},

  /* Available function pointers for DcmDspData_F1FD */
  /* CallReadData async c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DcmDspData_F1FD_ReadData},
  /* Write async c-s fixed length */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DcmDspData_F1FD_WriteData},

  /* Available function pointers for DcmDspData_FD00 */
  /* CallReadData async c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DcmDspData_FD00_ReadData},
  /* Write async c-s fixed length */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DcmDspData_FD00_WriteData},

  /* Available function pointers for DcmDspData_FD2A */
  /* CallReadData async c-s */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DcmDspData_FD2A_ReadData},
  /* Write async c-s fixed length */
  {(Dcm_GeneralDidOperationFuncType)&Rte_Call_DataServices_DcmDspData_FD2A_WriteData},

  /* Deviation MISRA-3  <STOP> */ /* Deviation MISRAC2012-1 <STOP> */
};
#endif

/* !LINKSTO Dcm.Dsn.DidSignals.ConfigurationData.DidDataIndexingArray,1 */
CONST(Dcm_DidDataIndexingArrayEntryType, DCM_CONST) Dcm_DidDataIndexingArray[DCM_NUM_DID_DATA] =
{
    {
    /* Index in Dcm_DidDataTable */
    0U,
    /* Data descriptor */
    0x1bcU,
  },
  {
    /* Index in Dcm_DidDataTable */
    1U,
    /* Data descriptor */
    0x1bcU,
  },
  {
    /* Index in Dcm_DidDataTable */
    2U,
    /* Data descriptor */
    0x1bcU,
  },
  {
    /* Index in Dcm_DidDataTable */
    3U,
    /* Data descriptor */
    0x1bcU,
  },
  {
    /* Index in Dcm_DidDataTable */
    4U,
    /* Data descriptor */
    0x9b9U,
  },
  {
    /* Index in Dcm_DidDataTable */
    6U,
    /* Data descriptor */
    0x9b9U,
  },
  {
    /* Index in Dcm_DidDataTable */
    8U,
    /* Data descriptor */
    0x9b9U,
  },
  {
    /* Index in Dcm_DidDataTable */
    10U,
    /* Data descriptor */
    0x9b9U,
  },
  {
    /* Index in Dcm_DidDataTable */
    12U,
    /* Data descriptor */
    0x9b9U,
  },
  {
    /* Index in Dcm_DidDataTable */
    14U,
    /* Data descriptor */
    0x1bcU,
  },
  {
    /* Index in Dcm_DidDataTable */
    15U,
    /* Data descriptor */
    0x1bcU,
  },
  {
    /* Index in Dcm_DidDataTable */
    16U,
    /* Data descriptor */
    0x1b9U,
  },
  {
    /* Index in Dcm_DidDataTable */
    17U,
    /* Data descriptor */
    0x1bcU,
  },
  {
    /* Index in Dcm_DidDataTable */
    18U,
    /* Data descriptor */
    0x1bcU,
  },
  {
    /* Index in Dcm_DidDataTable */
    19U,
    /* Data descriptor */
    0x1bcU,
  },
  {
    /* Index in Dcm_DidDataTable */
    20U,
    /* Data descriptor */
    0x1b9U,
  },
  {
    /* Index in Dcm_DidDataTable */
    21U,
    /* Data descriptor */
    0x9b9U,
  },
  {
    /* Index in Dcm_DidDataTable */
    23U,
    /* Data descriptor */
    0x9b9U,
  },
  {
    /* Index in Dcm_DidDataTable */
    25U,
    /* Data descriptor */
    0x9b9U,
  },
  {
    /* Index in Dcm_DidDataTable */
    27U,
    /* Data descriptor */
    0x1b9U,
  },
  {
    /* Index in Dcm_DidDataTable */
    28U,
    /* Data descriptor */
    0x1b9U,
  },
  {
    /* Index in Dcm_DidDataTable */
    29U,
    /* Data descriptor */
    0x1b9U,
  },
  {
    /* Index in Dcm_DidDataTable */
    30U,
    /* Data descriptor */
    0x1b9U,
  },
  {
    /* Index in Dcm_DidDataTable */
    31U,
    /* Data descriptor */
    0x1b9U,
  },
  {
    /* Index in Dcm_DidDataTable */
    32U,
    /* Data descriptor */
    0x1b9U,
  },
  {
    /* Index in Dcm_DidDataTable */
    33U,
    /* Data descriptor */
    0x1bcU,
  },
  {
    /* Index in Dcm_DidDataTable */
    34U,
    /* Data descriptor */
    0x1b9U,
  },
  {
    /* Index in Dcm_DidDataTable */
    35U,
    /* Data descriptor */
    0x1b9U,
  },
  {
    /* Index in Dcm_DidDataTable */
    36U,
    /* Data descriptor */
    0x1b9U,
  },
  {
    /* Index in Dcm_DidDataTable */
    37U,
    /* Data descriptor */
    0x1bcU,
  },
  {
    /* Index in Dcm_DidDataTable */
    38U,
    /* Data descriptor */
    0x1bcU,
  },
  {
    /* Index in Dcm_DidDataTable */
    39U,
    /* Data descriptor */
    0x9b9U,
  },
  {
    /* Index in Dcm_DidDataTable */
    41U,
    /* Data descriptor */
    0x9b9U,
  },
  {
    /* Index in Dcm_DidDataTable */
    43U,
    /* Data descriptor */
    0x1b9U,
  },
  {
    /* Index in Dcm_DidDataTable */
    44U,
    /* Data descriptor */
    0x1b9U,
  },
  {
    /* Index in Dcm_DidDataTable */
    45U,
    /* Data descriptor */
    0x1b9U,
  },
  {
    /* Index in Dcm_DidDataTable */
    46U,
    /* Data descriptor */
    0x1b9U,
  },
  {
    /* Index in Dcm_DidDataTable */
    47U,
    /* Data descriptor */
    0x1b9U,
  },
  {
    /* Index in Dcm_DidDataTable */
    48U,
    /* Data descriptor */
    0x1b9U,
  },
  {
    /* Index in Dcm_DidDataTable */
    49U,
    /* Data descriptor */
    0x1b9U,
  },
  {
    /* Index in Dcm_DidDataTable */
    50U,
    /* Data descriptor */
    0x1b9U,
  },
  {
    /* Index in Dcm_DidDataTable */
    51U,
    /* Data descriptor */
    0x1b9U,
  },
  {
    /* Index in Dcm_DidDataTable */
    52U,
    /* Data descriptor */
    0x1bcU,
  },
  {
    /* Index in Dcm_DidDataTable */
    53U,
    /* Data descriptor */
    0x1b9U,
  },
  {
    /* Index in Dcm_DidDataTable */
    54U,
    /* Data descriptor */
    0x1b9U,
  },
  {
    /* Index in Dcm_DidDataTable */
    55U,
    /* Data descriptor */
    0x9b9U,
  },
  {
    /* Index in Dcm_DidDataTable */
    57U,
    /* Data descriptor */
    0x9b9U,
  },
  {
    /* Index in Dcm_DidDataTable */
    59U,
    /* Data descriptor */
    0x1bcU,
  },
  {
    /* Index in Dcm_DidDataTable */
    60U,
    /* Data descriptor */
    0x1bcU,
  },
  {
    /* Index in Dcm_DidDataTable */
    61U,
    /* Data descriptor */
    0x1bcU,
  },
  {
    /* Index in Dcm_DidDataTable */
    62U,
    /* Data descriptor */
    0x1b9U,
  },
  {
    /* Index in Dcm_DidDataTable */
    63U,
    /* Data descriptor */
    0x5bcU,
  },
  {
    /* Index in Dcm_DidDataTable */
    65U,
    /* Data descriptor */
    0x1b9U,
  },
  {
    /* Index in Dcm_DidDataTable */
    66U,
    /* Data descriptor */
    0x1b9U,
  },
  {
    /* Index in Dcm_DidDataTable */
    67U,
    /* Data descriptor */
    0x1b9U,
  },
  {
    /* Index in Dcm_DidDataTable */
    68U,
    /* Data descriptor */
    0x1b9U,
  },
  {
    /* Index in Dcm_DidDataTable */
    69U,
    /* Data descriptor */
    0x1b9U,
  },
  {
    /* Index in Dcm_DidDataTable */
    70U,
    /* Data descriptor */
    0x1b9U,
  },
  {
    /* Index in Dcm_DidDataTable */
    71U,
    /* Data descriptor */
    0x1b9U,
  },
  {
    /* Index in Dcm_DidDataTable */
    72U,
    /* Data descriptor */
    0x1b9U,
  },
  {
    /* Index in Dcm_DidDataTable */
    73U,
    /* Data descriptor */
    0x1b9U,
  },
  {
    /* Index in Dcm_DidDataTable */
    74U,
    /* Data descriptor */
    0x1b9U,
  },
  {
    /* Index in Dcm_DidDataTable */
    75U,
    /* Data descriptor */
    0x9b9U,
  },
  {
    /* Index in Dcm_DidDataTable */
    77U,
    /* Data descriptor */
    0x9b9U,
  },
  {
    /* Index in Dcm_DidDataTable */
    79U,
    /* Data descriptor */
    0x9b9U,
  },
  {
    /* Index in Dcm_DidDataTable */
    81U,
    /* Data descriptor */
    0x9b9U,
  },
};


/* !LINKSTO Dcm.Dsn.DidSignals.ConfigurationData.DidScalingDataSignalsIndexingArray,1 */
#if (DCM_DSP_USE_SERVICE_0X24 == STD_ON)
#if (DCM_NUM_READSCALING_DID_DATA > 0)
CONST(Dcm_DidScalingDataSignalsIndexingArrayEntryType, DCM_CONST) Dcm_DidScalingDataSignalsIndexingArray[DCM_NUM_READSCALING_DID_DATA] =
{
};
#endif /* #if (DCM_NUM_READSCALING_DID_DATA > 0) */
#endif /* #if (DCM_DSP_USE_SERVICE_0X24 == STD_ON) */
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include <Dcm_MemMap.h>

#define DCM_START_SEC_CONST_16
#include <Dcm_MemMap.h>
/* !LINKSTO Dcm.Dsn.DidSignals.ConfigurationData.DidDataSizeArray,1 */
CONST(uint16, DCM_CONST) Dcm_DidDataSizeArray[DCM_NUM_DID_DATA] =
{
  32,
  32,
  32,
  64,
  64,
  168,
  56,
  104,
  136,
  32,
  32,
  56,
  160,
  160,
  72,
  64,
  8,
  8,
  8,
  64,
  16,
  8,
  8,
  8,
  64,
  16,
  8,
  8,
  8,
  8,
  8,
  16,
  16,
  392,
  392,
  392,
  392,
  392,
  392,
  16,
  64,
  8,
  16,
  32,
  8,
  8,
  40,
  8,
  8,
  40,
  16,
  8,
  64,
  16,
  16,
  8,
  16,
  16,
  16,
  704,
  160,
  128,
  8,
  8,
  8,
  1312,
};

#define DCM_STOP_SEC_CONST_16
#include <Dcm_MemMap.h>

#define DCM_START_SEC_CONST_UNSPECIFIED
#include <Dcm_MemMap.h>

/** \brief RTE function pointer table for Supplier Notification */
CONST(Dcm_RteRequestNotificationType, DCM_CONST)
  Dcm_RteSupplierNotificationTable[DCM_RTE_TABLE_REQUEST_SUPPLIER_SIZE] =
{
{      &Rte_Call_ServiceRequestSupplierNotification_ServiceRequestSupplierNotification_Indication,
    &Rte_Call_ServiceRequestSupplierNotification_ServiceRequestSupplierNotification_Confirmation
  },
};


#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include <Dcm_MemMap.h>


#define DCM_START_SEC_CONST_UNSPECIFIED
#include <Dcm_MemMap.h>


#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include <Dcm_MemMap.h>


#define DCM_START_SEC_CALIB_8
#include <Dcm_MemMap.h>

/* Initialize global array holding the configuration for the service usage */

CONST(uint8, DCM_CONST) Dcm_DsdServiceUsed[DCM_DSP_SRV_TABLES_USED_BUF_SIZE][DCM_DSP_SERVICE_USED_BUF_SIZE] =
{
  {
    127U,
    29U,
  },
};




#define DCM_STOP_SEC_CALIB_8
#include <Dcm_MemMap.h>

/*==================[external data]==============================================================*/

/*==================[external function definitions]==============================================*/
#define DCM_START_SEC_CODE
#include <Dcm_MemMap.h>

#define DCM_STOP_SEC_CODE
#include <Dcm_MemMap.h>
/*==================[internal function definitions]==============================================*/
#define DCM_START_SEC_CODE
#include <Dcm_MemMap.h>

#define DCM_STOP_SEC_CODE
#include <Dcm_MemMap.h>

/*==================[end of file]================================================================*/
