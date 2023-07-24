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


/* !LINKSTO Dcm.Dsn.File.RoutineControlOperations.ConfigC,1 */

 /* MISRA-C:2004 Deviation List
  *
  * MISRA-1) Deviated Rule: 11.4 (advisory)
  *     A cast should not be performed between a pointer to object type and a
  *     different pointer to object type.
  *
  *     Reason:
  *     A cast to unsigned is necessary here to copy data bit by bit and
  *     there is no alignment issues.
  *
  */

 /* MISRA-C:2012 Deviation List
  *
  *  MISRAC2012-1) Deviated Rule: 11.3 (required)
  *     "A cast should not be performed between a pointer to object type and a different pointer to
  *     object type."
  *
  *     Reason:
  *     A cast to UINT8 is necessary here to copy data bit by bit and to be flexible for all
  *     the types, being no alignment issues.
  *     There is no side effects.
  *
  *  MISRAC2012-2) Deviated Rule: 8.9 (advisory)
  *     "An object should be defined at block scope if its identifier only
  *     appears in a single function."
  *
  *     Reason:
  *     The object is defined in this way because the values that are stored
  *     in them are required for the next call of this function and should be
  *     hold in the data segment memory.
  *
  */

/*==================[inclusions]=================================================================*/

#include <Dcm_RoutineControl_Cfg.h>                             /*  RoutineControl Configuration */
#include <Dcm_API_Cfg.h>                                  /*  Configurable function declarations */
#include <Dcm_DspExternal.h>                           /* Callbacks provided by Central Diag SwC */
#include <Dcm_Dsl_Supervisor.h>                        /* Dcm Dsl Supervisor header file */
#include <TSMem.h>
/*==================[macros]=====================================================================*/

/* The minimum length of a positive response (without the SID which is already added in the Dsd) is:
 * byte Subservice ID + 2 bytes RoutineId. */
#define DCM_SUBSERVICEID_AND_ROUTINEID_LENGTH 3U

/*==================[type definitions]===========================================================*/

/*==================[external function declarations]=============================================*/

/*==================[internal function declarations]=============================================*/


#define DCM_START_SEC_CODE
#include <Dcm_MemMap.h>

STATIC FUNC(void, DCM_CODE) Dcm_Dsp_RoutineControl_ClearInternalArrays(void);

#if (DCM_ROUTINE_ENDIANNESS_CONVERSION == STD_ON)
STATIC FUNC(void, DCM_CODE) Dcm_Dsp_RoutineControl_SwapBytes_U16(uint16* SignalData, uint32 SignalLength);



#endif

#define DCM_STOP_SEC_CODE
#include <Dcm_MemMap.h>

/*==================[internal constants]=========================================================*/

/*==================[internal data]==============================================================*/

#define DCM_START_SEC_VAR_CLEARED_8
#include <Dcm_MemMap.h>

/* Defining global uint8 buffer for API parameters used by Routine Control service */
STATIC VAR(uint8, DCM_VAR) Uint8Array[33];

#define DCM_STOP_SEC_VAR_CLEARED_8
#include <Dcm_MemMap.h>

#define DCM_START_SEC_VAR_CLEARED_16
#include <Dcm_MemMap.h>

/* Defining global uint16 buffer for API parameters used by Routine Control service */
STATIC VAR(uint16, DCM_VAR) Uint16Array[7];

#define DCM_STOP_SEC_VAR_CLEARED_16
#include <Dcm_MemMap.h>

/*==================[external constants]=========================================================*/

/*==================[external data]==============================================================*/

/*==================[external function definitions]==============================================*/
#define DCM_START_SEC_CODE
#include <Dcm_MemMap.h>

FUNC(Std_ReturnType, DCM_CODE) Dcm_DcmDspRoutine_0x800B_Start(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode)
{
  Std_ReturnType ServiceProcessStatus = DCM_E_NOT_OK;
  /* Parameter to store the configuration for current protocol */
  Dcm_ProtocolConfigType CurProtocolConfig;

  /* Parameter to store the length of input data (2U indicates the 2-byte RoutineID) received */
  Dcm_MsgLenType InDataLength = pMsgContext->reqDataLen - 2U;

  /* This is executed in the context of the SvcH and the protocol on which the request was made is
   * surely started */
  (void) Dcm_Dsl_Supervisor_GetLatestExternalUDSProtocolConfig(&CurProtocolConfig);

  if (DCM_INITIAL == OpStatus)
  {
    /* Total input data length check */
    if (InDataLength == 15U)
    {

      Dcm_Dsp_RoutineControl_ClearInternalArrays();

      /* Deviation MISRAC2012-1 <+2> */
      /* Deviation MISRA-1 <+2> */
      Dcm_DspInternal_CopySignalData((P2VAR(uint8, AUTOMATIC, DCM_VAR))&(pMsgContext->reqData[2]),
                                     (P2VAR(uint8, AUTOMATIC, DCM_VAR))&Uint8Array[0],
                                     0U,
                                     0U,
                                     8U,
                                     DCM_COPY_FROM_INBUFFER_OPAQUE,
                                     DCM_BYTE_DIRECTION_INCREMENT);

      /* Deviation MISRAC2012-1 <+2> */
      /* Deviation MISRA-1 <+2> */
      Dcm_DspInternal_CopySignalData((P2VAR(uint8, AUTOMATIC, DCM_VAR))&(pMsgContext->reqData[2]),
                                     (P2VAR(uint8, AUTOMATIC, DCM_VAR))&Uint16Array[0],
                                     8U,
                                     0U,
                                     16U,
                                     DCM_COPY_FROM_INBUFFER_OPAQUE,
                                     DCM_BYTE_DIRECTION_INCREMENT);

      /* Deviation MISRAC2012-1 <+2> */
      /* Deviation MISRA-1 <+2> */
      Dcm_DspInternal_CopySignalData((P2VAR(uint8, AUTOMATIC, DCM_VAR))&(pMsgContext->reqData[2]),
                                     (P2VAR(uint8, AUTOMATIC, DCM_VAR))&Uint16Array[1],
                                     24U,
                                     0U,
                                     16U,
                                     DCM_COPY_FROM_INBUFFER_OPAQUE,
                                     DCM_BYTE_DIRECTION_INCREMENT);

      /* Deviation MISRAC2012-1 <+2> */
      /* Deviation MISRA-1 <+2> */
      Dcm_DspInternal_CopySignalData((P2VAR(uint8, AUTOMATIC, DCM_VAR))&(pMsgContext->reqData[2]),
                                     (P2VAR(uint8, AUTOMATIC, DCM_VAR))&Uint16Array[2],
                                     40U,
                                     0U,
                                     16U,
                                     DCM_COPY_FROM_INBUFFER_OPAQUE,
                                     DCM_BYTE_DIRECTION_INCREMENT);

      /* Deviation MISRAC2012-1 <+2> */
      /* Deviation MISRA-1 <+2> */
      Dcm_DspInternal_CopySignalData((P2VAR(uint8, AUTOMATIC, DCM_VAR))&(pMsgContext->reqData[2]),
                                     (P2VAR(uint8, AUTOMATIC, DCM_VAR))&Uint16Array[3],
                                     56U,
                                     0U,
                                     16U,
                                     DCM_COPY_FROM_INBUFFER_OPAQUE,
                                     DCM_BYTE_DIRECTION_INCREMENT);

      /* Deviation MISRAC2012-1 <+2> */
      /* Deviation MISRA-1 <+2> */
      Dcm_DspInternal_CopySignalData((P2VAR(uint8, AUTOMATIC, DCM_VAR))&(pMsgContext->reqData[2]),
                                     (P2VAR(uint8, AUTOMATIC, DCM_VAR))&Uint16Array[4],
                                     72U,
                                     0U,
                                     16U,
                                     DCM_COPY_FROM_INBUFFER_OPAQUE,
                                     DCM_BYTE_DIRECTION_INCREMENT);

      /* Deviation MISRAC2012-1 <+2> */
      /* Deviation MISRA-1 <+2> */
      Dcm_DspInternal_CopySignalData((P2VAR(uint8, AUTOMATIC, DCM_VAR))&(pMsgContext->reqData[2]),
                                     (P2VAR(uint8, AUTOMATIC, DCM_VAR))&Uint16Array[5],
                                     88U,
                                     0U,
                                     16U,
                                     DCM_COPY_FROM_INBUFFER_OPAQUE,
                                     DCM_BYTE_DIRECTION_INCREMENT);

      /* Deviation MISRAC2012-1 <+2> */
      /* Deviation MISRA-1 <+2> */
      Dcm_DspInternal_CopySignalData((P2VAR(uint8, AUTOMATIC, DCM_VAR))&(pMsgContext->reqData[2]),
                                     (P2VAR(uint8, AUTOMATIC, DCM_VAR))&Uint16Array[6],
                                     104U,
                                     0U,
                                     16U,
                                     DCM_COPY_FROM_INBUFFER_OPAQUE,
                                     DCM_BYTE_DIRECTION_INCREMENT);

#if (DCM_ROUTINE_ENDIANNESS_CONVERSION == STD_ON)
      /* !LINKSTO Dcm.EB.RoutineControl.EndiannessEnabled,1 */
      if(CurProtocolConfig.EndiannessConversion == TRUE)
      {
        Dcm_Dsp_RoutineControl_SwapBytes_U16(&Uint16Array[0], 7U);
      }
#endif /*(DCM_ROUTINE_ENDIANNESS_CONVERSION == STD_ON)*/

      ServiceProcessStatus = Rte_Call_RoutineServices_DcmDspRoutine_0x800B_Start(Uint8Array[0], Uint16Array[0], Uint16Array[1], Uint16Array[2], Uint16Array[3], Uint16Array[4], Uint16Array[5], Uint16Array[6], DCM_INITIAL, ErrorCode);

    }
    else
    {
      /* Invalid total data length */
      *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
      ServiceProcessStatus = DCM_E_NOT_OK;
    }
  }
  else
  {
    ServiceProcessStatus = Rte_Call_RoutineServices_DcmDspRoutine_0x800B_Start(Uint8Array[0], Uint16Array[0], Uint16Array[1], Uint16Array[2], Uint16Array[3], Uint16Array[4], Uint16Array[5], Uint16Array[6], OpStatus, ErrorCode);
  }

  if (ServiceProcessStatus == E_OK)
  {
    pMsgContext->resDataLen = 3U;

    ServiceProcessStatus = DCM_E_OK;
  }
  else if(ServiceProcessStatus == E_NOT_OK)
  {
    ServiceProcessStatus = DCM_E_NOT_OK;
  }
  else
  {
    /* ServiceProcessStatus is DCM_E_PENDING, DCM_E_FORCE_RCRRP or unknown and these
     * cases are processed in service handler */
  }

  return ServiceProcessStatus;
}

FUNC(Std_ReturnType, DCM_CODE) Dcm_DcmDspRoutine_0x800B_RequestResults(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode)
{
  Std_ReturnType ServiceProcessStatus = DCM_E_NOT_OK;
  /* Parameter to store the length of input data (2U indicates the 2-byte RoutineID) received */
  Dcm_MsgLenType InDataLength = pMsgContext->reqDataLen - 2U;

  if (DCM_INITIAL == OpStatus)
  {
    /* Total input data length check */
    if (InDataLength == 0U)
    {

      Dcm_Dsp_RoutineControl_ClearInternalArrays();

      ServiceProcessStatus = Rte_Call_RoutineServices_DcmDspRoutine_0x800B_RequestResults(DCM_INITIAL, &Uint8Array[0], &Uint8Array[1], ErrorCode);

    }
    else
    {
      /* Invalid total data length */
      *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
      ServiceProcessStatus = DCM_E_NOT_OK;
    }
  }
  else
  {
    ServiceProcessStatus = Rte_Call_RoutineServices_DcmDspRoutine_0x800B_RequestResults(OpStatus, &Uint8Array[0], &Uint8Array[1], ErrorCode);
  }

  if (ServiceProcessStatus == E_OK)
  {
    pMsgContext->resDataLen = 5U;
    /* Deviation MISRAC2012-1 <+2> */
    /* Deviation MISRA-1 <+2> */
    Dcm_DspInternal_CopySignalData((P2VAR(uint8, AUTOMATIC, DCM_VAR))&Uint8Array[0],
                                   (P2VAR(uint8, AUTOMATIC, DCM_VAR))&(pMsgContext->resData[3]),
                                   0U,
                                   0U,
                                   8U,
                                   DCM_COPY_TO_OUTBUFFER_OPAQUE,
                                   DCM_BYTE_DIRECTION_INCREMENT);
    /* Deviation MISRAC2012-1 <+2> */
    /* Deviation MISRA-1 <+2> */
    Dcm_DspInternal_CopySignalData((P2VAR(uint8, AUTOMATIC, DCM_VAR))&Uint8Array[1],
                                   (P2VAR(uint8, AUTOMATIC, DCM_VAR))&(pMsgContext->resData[3]),
                                   0U,
                                   8U,
                                   8U,
                                   DCM_COPY_TO_OUTBUFFER_OPAQUE,
                                   DCM_BYTE_DIRECTION_INCREMENT);

    ServiceProcessStatus = DCM_E_OK;
  }
  else if(ServiceProcessStatus == E_NOT_OK)
  {
    ServiceProcessStatus = DCM_E_NOT_OK;
  }
  else
  {
    /* ServiceProcessStatus is DCM_E_PENDING, DCM_E_FORCE_RCRRP or unknown and these
     * cases are processed in service handler */
  }

  return ServiceProcessStatus;
}

FUNC(Std_ReturnType, DCM_CODE) Dcm_DcmDspRoutine_0x800C_Start(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode)
{
  Std_ReturnType ServiceProcessStatus = DCM_E_NOT_OK;
  /* Parameter to store the length of input data (2U indicates the 2-byte RoutineID) received */
  Dcm_MsgLenType InDataLength = pMsgContext->reqDataLen - 2U;

  if (DCM_INITIAL == OpStatus)
  {
    /* Total input data length check */
    if (InDataLength == 0U)
    {

      Dcm_Dsp_RoutineControl_ClearInternalArrays();

      ServiceProcessStatus = Rte_Call_RoutineServices_DcmDspRoutine_0x800C_Start(DCM_INITIAL, ErrorCode);

    }
    else
    {
      /* Invalid total data length */
      *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
      ServiceProcessStatus = DCM_E_NOT_OK;
    }
  }
  else
  {
    ServiceProcessStatus = Rte_Call_RoutineServices_DcmDspRoutine_0x800C_Start(OpStatus, ErrorCode);
  }

  if (ServiceProcessStatus == E_OK)
  {
    pMsgContext->resDataLen = 3U;

    ServiceProcessStatus = DCM_E_OK;
  }
  else if(ServiceProcessStatus == E_NOT_OK)
  {
    ServiceProcessStatus = DCM_E_NOT_OK;
  }
  else
  {
    /* ServiceProcessStatus is DCM_E_PENDING, DCM_E_FORCE_RCRRP or unknown and these
     * cases are processed in service handler */
  }

  return ServiceProcessStatus;
}

FUNC(Std_ReturnType, DCM_CODE) Dcm_DcmDspRoutine_0x800C_RequestResults(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode)
{
  Std_ReturnType ServiceProcessStatus = DCM_E_NOT_OK;
  /* Parameter to store the length of input data (2U indicates the 2-byte RoutineID) received */
  Dcm_MsgLenType InDataLength = pMsgContext->reqDataLen - 2U;

  if (DCM_INITIAL == OpStatus)
  {
    /* Total input data length check */
    if (InDataLength == 0U)
    {

      Dcm_Dsp_RoutineControl_ClearInternalArrays();

      ServiceProcessStatus = Rte_Call_RoutineServices_DcmDspRoutine_0x800C_RequestResults(DCM_INITIAL, &Uint8Array[0], &Uint8Array[1], ErrorCode);

    }
    else
    {
      /* Invalid total data length */
      *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
      ServiceProcessStatus = DCM_E_NOT_OK;
    }
  }
  else
  {
    ServiceProcessStatus = Rte_Call_RoutineServices_DcmDspRoutine_0x800C_RequestResults(OpStatus, &Uint8Array[0], &Uint8Array[1], ErrorCode);
  }

  if (ServiceProcessStatus == E_OK)
  {
    pMsgContext->resDataLen = 5U;
    /* Deviation MISRAC2012-1 <+2> */
    /* Deviation MISRA-1 <+2> */
    Dcm_DspInternal_CopySignalData((P2VAR(uint8, AUTOMATIC, DCM_VAR))&Uint8Array[0],
                                   (P2VAR(uint8, AUTOMATIC, DCM_VAR))&(pMsgContext->resData[3]),
                                   0U,
                                   0U,
                                   8U,
                                   DCM_COPY_TO_OUTBUFFER_OPAQUE,
                                   DCM_BYTE_DIRECTION_INCREMENT);
    /* Deviation MISRAC2012-1 <+2> */
    /* Deviation MISRA-1 <+2> */
    Dcm_DspInternal_CopySignalData((P2VAR(uint8, AUTOMATIC, DCM_VAR))&Uint8Array[1],
                                   (P2VAR(uint8, AUTOMATIC, DCM_VAR))&(pMsgContext->resData[3]),
                                   0U,
                                   8U,
                                   8U,
                                   DCM_COPY_TO_OUTBUFFER_OPAQUE,
                                   DCM_BYTE_DIRECTION_INCREMENT);

    ServiceProcessStatus = DCM_E_OK;
  }
  else if(ServiceProcessStatus == E_NOT_OK)
  {
    ServiceProcessStatus = DCM_E_NOT_OK;
  }
  else
  {
    /* ServiceProcessStatus is DCM_E_PENDING, DCM_E_FORCE_RCRRP or unknown and these
     * cases are processed in service handler */
  }

  return ServiceProcessStatus;
}

FUNC(Std_ReturnType, DCM_CODE) Dcm_DcmDspRoutine_0x0203_Start(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode)
{
  Std_ReturnType ServiceProcessStatus = DCM_E_NOT_OK;
  /* Parameter to store the length of input data (2U indicates the 2-byte RoutineID) received */
  Dcm_MsgLenType InDataLength = pMsgContext->reqDataLen - 2U;

  if (DCM_INITIAL == OpStatus)
  {
    /* Total input data length check */
    if (InDataLength == 0U)
    {

      Dcm_Dsp_RoutineControl_ClearInternalArrays();

      ServiceProcessStatus = Rte_Call_RoutineServices_DcmDspRoutine_0x0203_Start(DCM_INITIAL, ErrorCode);

    }
    else
    {
      /* Invalid total data length */
      *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
      ServiceProcessStatus = DCM_E_NOT_OK;
    }
  }
  else
  {
    ServiceProcessStatus = Rte_Call_RoutineServices_DcmDspRoutine_0x0203_Start(OpStatus, ErrorCode);
  }

  if (ServiceProcessStatus == E_OK)
  {
    pMsgContext->resDataLen = 3U;

    ServiceProcessStatus = DCM_E_OK;
  }
  else if(ServiceProcessStatus == E_NOT_OK)
  {
    ServiceProcessStatus = DCM_E_NOT_OK;
  }
  else
  {
    /* ServiceProcessStatus is DCM_E_PENDING, DCM_E_FORCE_RCRRP or unknown and these
     * cases are processed in service handler */
  }

  return ServiceProcessStatus;
}

FUNC(Std_ReturnType, DCM_CODE) Dcm_DcmDspRoutine_0x0204_Start(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode)
{
  Std_ReturnType ServiceProcessStatus = DCM_E_NOT_OK;
  /* Parameter to store the length of input data (2U indicates the 2-byte RoutineID) received */
  Dcm_MsgLenType InDataLength = pMsgContext->reqDataLen - 2U;

  if (DCM_INITIAL == OpStatus)
  {
    /* Total input data length check */
    if (InDataLength == 0U)
    {

      Dcm_Dsp_RoutineControl_ClearInternalArrays();

      ServiceProcessStatus = Rte_Call_RoutineServices_DcmDspRoutine_0x0204_Start(DCM_INITIAL, ErrorCode);

    }
    else
    {
      /* Invalid total data length */
      *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
      ServiceProcessStatus = DCM_E_NOT_OK;
    }
  }
  else
  {
    ServiceProcessStatus = Rte_Call_RoutineServices_DcmDspRoutine_0x0204_Start(OpStatus, ErrorCode);
  }

  if (ServiceProcessStatus == E_OK)
  {
    pMsgContext->resDataLen = 3U;

    ServiceProcessStatus = DCM_E_OK;
  }
  else if(ServiceProcessStatus == E_NOT_OK)
  {
    ServiceProcessStatus = DCM_E_NOT_OK;
  }
  else
  {
    /* ServiceProcessStatus is DCM_E_PENDING, DCM_E_FORCE_RCRRP or unknown and these
     * cases are processed in service handler */
  }

  return ServiceProcessStatus;
}

FUNC(Std_ReturnType, DCM_CODE) Dcm_DcmDspRoutine_0x0205_Start(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode)
{
  Std_ReturnType ServiceProcessStatus = DCM_E_NOT_OK;
  /* Parameter to store the length of input data (2U indicates the 2-byte RoutineID) received */
  Dcm_MsgLenType InDataLength = pMsgContext->reqDataLen - 2U;

  if (DCM_INITIAL == OpStatus)
  {
    /* Total input data length check */
    if (InDataLength == 0U)
    {

      Dcm_Dsp_RoutineControl_ClearInternalArrays();

      ServiceProcessStatus = Rte_Call_RoutineServices_DcmDspRoutine_0x0205_Start(DCM_INITIAL, ErrorCode);

    }
    else
    {
      /* Invalid total data length */
      *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
      ServiceProcessStatus = DCM_E_NOT_OK;
    }
  }
  else
  {
    ServiceProcessStatus = Rte_Call_RoutineServices_DcmDspRoutine_0x0205_Start(OpStatus, ErrorCode);
  }

  if (ServiceProcessStatus == E_OK)
  {
    pMsgContext->resDataLen = 3U;

    ServiceProcessStatus = DCM_E_OK;
  }
  else if(ServiceProcessStatus == E_NOT_OK)
  {
    ServiceProcessStatus = DCM_E_NOT_OK;
  }
  else
  {
    /* ServiceProcessStatus is DCM_E_PENDING, DCM_E_FORCE_RCRRP or unknown and these
     * cases are processed in service handler */
  }

  return ServiceProcessStatus;
}

FUNC(Std_ReturnType, DCM_CODE) Dcm_DcmDspRoutine_0x8010_Start(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode)
{
  Std_ReturnType ServiceProcessStatus = DCM_E_NOT_OK;
  /* Parameter to store the length of input data (2U indicates the 2-byte RoutineID) received */
  Dcm_MsgLenType InDataLength = pMsgContext->reqDataLen - 2U;

  if (DCM_INITIAL == OpStatus)
  {
    /* Total input data length check */
    if (InDataLength == 32U)
    {

      Dcm_Dsp_RoutineControl_ClearInternalArrays();

      /* Deviation MISRAC2012-1 <+2> */
      /* Deviation MISRA-1 <+2> */
      Dcm_DspInternal_CopySignalData((P2VAR(uint8, AUTOMATIC, DCM_VAR))&(pMsgContext->reqData[2]),
                                     (P2VAR(uint8, AUTOMATIC, DCM_VAR))&Uint8Array[0],
                                     0U,
                                     0U,
                                     256U,
                                     DCM_COPY_FROM_INBUFFER_OPAQUE,
                                     DCM_BYTE_DIRECTION_INCREMENT);

      ServiceProcessStatus = Rte_Call_RoutineServices_DcmDspRoutine_0x8010_Start(&Uint8Array[0], DCM_INITIAL, &Uint8Array[32], ErrorCode);

    }
    else
    {
      /* Invalid total data length */
      *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
      ServiceProcessStatus = DCM_E_NOT_OK;
    }
  }
  else
  {
    ServiceProcessStatus = Rte_Call_RoutineServices_DcmDspRoutine_0x8010_Start(&Uint8Array[0], OpStatus, &Uint8Array[32], ErrorCode);
  }

  if (ServiceProcessStatus == E_OK)
  {
    pMsgContext->resDataLen = 4U;
    /* Deviation MISRAC2012-1 <+2> */
    /* Deviation MISRA-1 <+2> */
    Dcm_DspInternal_CopySignalData((P2VAR(uint8, AUTOMATIC, DCM_VAR))&Uint8Array[32],
                                   (P2VAR(uint8, AUTOMATIC, DCM_VAR))&(pMsgContext->resData[3]),
                                   0U,
                                   0U,
                                   8U,
                                   DCM_COPY_TO_OUTBUFFER_OPAQUE,
                                   DCM_BYTE_DIRECTION_INCREMENT);

    ServiceProcessStatus = DCM_E_OK;
  }
  else if(ServiceProcessStatus == E_NOT_OK)
  {
    ServiceProcessStatus = DCM_E_NOT_OK;
  }
  else
  {
    /* ServiceProcessStatus is DCM_E_PENDING, DCM_E_FORCE_RCRRP or unknown and these
     * cases are processed in service handler */
  }

  return ServiceProcessStatus;
}

FUNC(Std_ReturnType, DCM_CODE) Dcm_DcmDspRoutine_0x8010_RequestResults(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode)
{
  Std_ReturnType ServiceProcessStatus = DCM_E_NOT_OK;
  /* Parameter to store the length of input data (2U indicates the 2-byte RoutineID) received */
  Dcm_MsgLenType InDataLength = pMsgContext->reqDataLen - 2U;

  if (DCM_INITIAL == OpStatus)
  {
    /* Total input data length check */
    if (InDataLength == 0U)
    {

      Dcm_Dsp_RoutineControl_ClearInternalArrays();

      ServiceProcessStatus = Rte_Call_RoutineServices_DcmDspRoutine_0x8010_RequestResults(DCM_INITIAL, &Uint8Array[0], &Uint8Array[1], ErrorCode);

    }
    else
    {
      /* Invalid total data length */
      *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
      ServiceProcessStatus = DCM_E_NOT_OK;
    }
  }
  else
  {
    ServiceProcessStatus = Rte_Call_RoutineServices_DcmDspRoutine_0x8010_RequestResults(OpStatus, &Uint8Array[0], &Uint8Array[1], ErrorCode);
  }

  if (ServiceProcessStatus == E_OK)
  {
    pMsgContext->resDataLen = 5U;
    /* Deviation MISRAC2012-1 <+2> */
    /* Deviation MISRA-1 <+2> */
    Dcm_DspInternal_CopySignalData((P2VAR(uint8, AUTOMATIC, DCM_VAR))&Uint8Array[0],
                                   (P2VAR(uint8, AUTOMATIC, DCM_VAR))&(pMsgContext->resData[3]),
                                   0U,
                                   0U,
                                   8U,
                                   DCM_COPY_TO_OUTBUFFER_OPAQUE,
                                   DCM_BYTE_DIRECTION_INCREMENT);
    /* Deviation MISRAC2012-1 <+2> */
    /* Deviation MISRA-1 <+2> */
    Dcm_DspInternal_CopySignalData((P2VAR(uint8, AUTOMATIC, DCM_VAR))&Uint8Array[1],
                                   (P2VAR(uint8, AUTOMATIC, DCM_VAR))&(pMsgContext->resData[3]),
                                   0U,
                                   8U,
                                   8U,
                                   DCM_COPY_TO_OUTBUFFER_OPAQUE,
                                   DCM_BYTE_DIRECTION_INCREMENT);

    ServiceProcessStatus = DCM_E_OK;
  }
  else if(ServiceProcessStatus == E_NOT_OK)
  {
    ServiceProcessStatus = DCM_E_NOT_OK;
  }
  else
  {
    /* ServiceProcessStatus is DCM_E_PENDING, DCM_E_FORCE_RCRRP or unknown and these
     * cases are processed in service handler */
  }

  return ServiceProcessStatus;
}

FUNC(Std_ReturnType, DCM_CODE) Dcm_DcmDspRoutine_0x0301_Start(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode)
{
  Std_ReturnType ServiceProcessStatus = DCM_E_NOT_OK;
  /* Parameter to store the length of input data (2U indicates the 2-byte RoutineID) received */
  Dcm_MsgLenType InDataLength = pMsgContext->reqDataLen - 2U;

  if (DCM_INITIAL == OpStatus)
  {
    /* Total input data length check */
    if (InDataLength == 1U)
    {

      Dcm_Dsp_RoutineControl_ClearInternalArrays();

      /* Deviation MISRAC2012-1 <+2> */
      /* Deviation MISRA-1 <+2> */
      Dcm_DspInternal_CopySignalData((P2VAR(uint8, AUTOMATIC, DCM_VAR))&(pMsgContext->reqData[2]),
                                     (P2VAR(uint8, AUTOMATIC, DCM_VAR))&Uint8Array[0],
                                     0U,
                                     0U,
                                     8U,
                                     DCM_COPY_FROM_INBUFFER_OPAQUE,
                                     DCM_BYTE_DIRECTION_INCREMENT);

      ServiceProcessStatus = Rte_Call_RoutineServices_DcmDspRoutine_0x0301_Start(Uint8Array[0], DCM_INITIAL, ErrorCode);

    }
    else
    {
      /* Invalid total data length */
      *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
      ServiceProcessStatus = DCM_E_NOT_OK;
    }
  }
  else
  {
    ServiceProcessStatus = Rte_Call_RoutineServices_DcmDspRoutine_0x0301_Start(Uint8Array[0], OpStatus, ErrorCode);
  }

  if (ServiceProcessStatus == E_OK)
  {
    pMsgContext->resDataLen = 3U;

    ServiceProcessStatus = DCM_E_OK;
  }
  else if(ServiceProcessStatus == E_NOT_OK)
  {
    ServiceProcessStatus = DCM_E_NOT_OK;
  }
  else
  {
    /* ServiceProcessStatus is DCM_E_PENDING, DCM_E_FORCE_RCRRP or unknown and these
     * cases are processed in service handler */
  }

  return ServiceProcessStatus;
}

FUNC(Std_ReturnType, DCM_CODE) Dcm_DcmDspRoutine_0x0301_RequestResults(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode)
{
  Std_ReturnType ServiceProcessStatus = DCM_E_NOT_OK;
  /* Parameter to store the length of input data (2U indicates the 2-byte RoutineID) received */
  Dcm_MsgLenType InDataLength = pMsgContext->reqDataLen - 2U;

  if (DCM_INITIAL == OpStatus)
  {
    /* Total input data length check */
    if (InDataLength == 0U)
    {

      Dcm_Dsp_RoutineControl_ClearInternalArrays();

      ServiceProcessStatus = Rte_Call_RoutineServices_DcmDspRoutine_0x0301_RequestResults(DCM_INITIAL, &Uint8Array[0], ErrorCode);

    }
    else
    {
      /* Invalid total data length */
      *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
      ServiceProcessStatus = DCM_E_NOT_OK;
    }
  }
  else
  {
    ServiceProcessStatus = Rte_Call_RoutineServices_DcmDspRoutine_0x0301_RequestResults(OpStatus, &Uint8Array[0], ErrorCode);
  }

  if (ServiceProcessStatus == E_OK)
  {
    pMsgContext->resDataLen = 4U;
    /* Deviation MISRAC2012-1 <+2> */
    /* Deviation MISRA-1 <+2> */
    Dcm_DspInternal_CopySignalData((P2VAR(uint8, AUTOMATIC, DCM_VAR))&Uint8Array[0],
                                   (P2VAR(uint8, AUTOMATIC, DCM_VAR))&(pMsgContext->resData[3]),
                                   0U,
                                   0U,
                                   8U,
                                   DCM_COPY_TO_OUTBUFFER_OPAQUE,
                                   DCM_BYTE_DIRECTION_INCREMENT);

    ServiceProcessStatus = DCM_E_OK;
  }
  else if(ServiceProcessStatus == E_NOT_OK)
  {
    ServiceProcessStatus = DCM_E_NOT_OK;
  }
  else
  {
    /* ServiceProcessStatus is DCM_E_PENDING, DCM_E_FORCE_RCRRP or unknown and these
     * cases are processed in service handler */
  }

  return ServiceProcessStatus;
}

FUNC(Std_ReturnType, DCM_CODE) Dcm_DcmDspRoutine_0x0303_Start(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode)
{
  Std_ReturnType ServiceProcessStatus = DCM_E_NOT_OK;
  /* Parameter to store the length of input data (2U indicates the 2-byte RoutineID) received */
  Dcm_MsgLenType InDataLength = pMsgContext->reqDataLen - 2U;

  if (DCM_INITIAL == OpStatus)
  {
    /* Total input data length check */
    if (InDataLength == 11U)
    {

      Dcm_Dsp_RoutineControl_ClearInternalArrays();

      /* Deviation MISRAC2012-1 <+2> */
      /* Deviation MISRA-1 <+2> */
      Dcm_DspInternal_CopySignalData((P2VAR(uint8, AUTOMATIC, DCM_VAR))&(pMsgContext->reqData[2]),
                                     (P2VAR(uint8, AUTOMATIC, DCM_VAR))&Uint8Array[0],
                                     0U,
                                     0U,
                                     8U,
                                     DCM_COPY_FROM_INBUFFER_OPAQUE,
                                     DCM_BYTE_DIRECTION_INCREMENT);

      /* Deviation MISRAC2012-1 <+2> */
      /* Deviation MISRA-1 <+2> */
      Dcm_DspInternal_CopySignalData((P2VAR(uint8, AUTOMATIC, DCM_VAR))&(pMsgContext->reqData[2]),
                                     (P2VAR(uint8, AUTOMATIC, DCM_VAR))&Uint8Array[1],
                                     8U,
                                     0U,
                                     8U,
                                     DCM_COPY_FROM_INBUFFER_OPAQUE,
                                     DCM_BYTE_DIRECTION_INCREMENT);

      /* Deviation MISRAC2012-1 <+2> */
      /* Deviation MISRA-1 <+2> */
      Dcm_DspInternal_CopySignalData((P2VAR(uint8, AUTOMATIC, DCM_VAR))&(pMsgContext->reqData[2]),
                                     (P2VAR(uint8, AUTOMATIC, DCM_VAR))&Uint8Array[2],
                                     16U,
                                     0U,
                                     8U,
                                     DCM_COPY_FROM_INBUFFER_OPAQUE,
                                     DCM_BYTE_DIRECTION_INCREMENT);

      /* Deviation MISRAC2012-1 <+2> */
      /* Deviation MISRA-1 <+2> */
      Dcm_DspInternal_CopySignalData((P2VAR(uint8, AUTOMATIC, DCM_VAR))&(pMsgContext->reqData[2]),
                                     (P2VAR(uint8, AUTOMATIC, DCM_VAR))&Uint8Array[3],
                                     24U,
                                     0U,
                                     8U,
                                     DCM_COPY_FROM_INBUFFER_OPAQUE,
                                     DCM_BYTE_DIRECTION_INCREMENT);

      /* Deviation MISRAC2012-1 <+2> */
      /* Deviation MISRA-1 <+2> */
      Dcm_DspInternal_CopySignalData((P2VAR(uint8, AUTOMATIC, DCM_VAR))&(pMsgContext->reqData[2]),
                                     (P2VAR(uint8, AUTOMATIC, DCM_VAR))&Uint8Array[4],
                                     32U,
                                     0U,
                                     8U,
                                     DCM_COPY_FROM_INBUFFER_OPAQUE,
                                     DCM_BYTE_DIRECTION_INCREMENT);

      /* Deviation MISRAC2012-1 <+2> */
      /* Deviation MISRA-1 <+2> */
      Dcm_DspInternal_CopySignalData((P2VAR(uint8, AUTOMATIC, DCM_VAR))&(pMsgContext->reqData[2]),
                                     (P2VAR(uint8, AUTOMATIC, DCM_VAR))&Uint8Array[5],
                                     40U,
                                     0U,
                                     8U,
                                     DCM_COPY_FROM_INBUFFER_OPAQUE,
                                     DCM_BYTE_DIRECTION_INCREMENT);

      /* Deviation MISRAC2012-1 <+2> */
      /* Deviation MISRA-1 <+2> */
      Dcm_DspInternal_CopySignalData((P2VAR(uint8, AUTOMATIC, DCM_VAR))&(pMsgContext->reqData[2]),
                                     (P2VAR(uint8, AUTOMATIC, DCM_VAR))&Uint8Array[6],
                                     48U,
                                     0U,
                                     8U,
                                     DCM_COPY_FROM_INBUFFER_OPAQUE,
                                     DCM_BYTE_DIRECTION_INCREMENT);

      /* Deviation MISRAC2012-1 <+2> */
      /* Deviation MISRA-1 <+2> */
      Dcm_DspInternal_CopySignalData((P2VAR(uint8, AUTOMATIC, DCM_VAR))&(pMsgContext->reqData[2]),
                                     (P2VAR(uint8, AUTOMATIC, DCM_VAR))&Uint8Array[7],
                                     56U,
                                     0U,
                                     8U,
                                     DCM_COPY_FROM_INBUFFER_OPAQUE,
                                     DCM_BYTE_DIRECTION_INCREMENT);

      /* Deviation MISRAC2012-1 <+2> */
      /* Deviation MISRA-1 <+2> */
      Dcm_DspInternal_CopySignalData((P2VAR(uint8, AUTOMATIC, DCM_VAR))&(pMsgContext->reqData[2]),
                                     (P2VAR(uint8, AUTOMATIC, DCM_VAR))&Uint8Array[8],
                                     64U,
                                     0U,
                                     8U,
                                     DCM_COPY_FROM_INBUFFER_OPAQUE,
                                     DCM_BYTE_DIRECTION_INCREMENT);

      /* Deviation MISRAC2012-1 <+2> */
      /* Deviation MISRA-1 <+2> */
      Dcm_DspInternal_CopySignalData((P2VAR(uint8, AUTOMATIC, DCM_VAR))&(pMsgContext->reqData[2]),
                                     (P2VAR(uint8, AUTOMATIC, DCM_VAR))&Uint8Array[9],
                                     72U,
                                     0U,
                                     8U,
                                     DCM_COPY_FROM_INBUFFER_OPAQUE,
                                     DCM_BYTE_DIRECTION_INCREMENT);

      /* Deviation MISRAC2012-1 <+2> */
      /* Deviation MISRA-1 <+2> */
      Dcm_DspInternal_CopySignalData((P2VAR(uint8, AUTOMATIC, DCM_VAR))&(pMsgContext->reqData[2]),
                                     (P2VAR(uint8, AUTOMATIC, DCM_VAR))&Uint8Array[10],
                                     80U,
                                     0U,
                                     8U,
                                     DCM_COPY_FROM_INBUFFER_OPAQUE,
                                     DCM_BYTE_DIRECTION_INCREMENT);

      ServiceProcessStatus = Rte_Call_RoutineServices_DcmDspRoutine_0x0303_Start(Uint8Array[0], Uint8Array[1], Uint8Array[2], Uint8Array[3], Uint8Array[4], Uint8Array[5], Uint8Array[6], Uint8Array[7], Uint8Array[8], Uint8Array[9], Uint8Array[10], DCM_INITIAL, ErrorCode);

    }
    else
    {
      /* Invalid total data length */
      *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
      ServiceProcessStatus = DCM_E_NOT_OK;
    }
  }
  else
  {
    ServiceProcessStatus = Rte_Call_RoutineServices_DcmDspRoutine_0x0303_Start(Uint8Array[0], Uint8Array[1], Uint8Array[2], Uint8Array[3], Uint8Array[4], Uint8Array[5], Uint8Array[6], Uint8Array[7], Uint8Array[8], Uint8Array[9], Uint8Array[10], OpStatus, ErrorCode);
  }

  if (ServiceProcessStatus == E_OK)
  {
    pMsgContext->resDataLen = 3U;

    ServiceProcessStatus = DCM_E_OK;
  }
  else if(ServiceProcessStatus == E_NOT_OK)
  {
    ServiceProcessStatus = DCM_E_NOT_OK;
  }
  else
  {
    /* ServiceProcessStatus is DCM_E_PENDING, DCM_E_FORCE_RCRRP or unknown and these
     * cases are processed in service handler */
  }

  return ServiceProcessStatus;
}

FUNC(Std_ReturnType, DCM_CODE) Dcm_DcmDspRoutine_0x0303_RequestResults(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode)
{
  Std_ReturnType ServiceProcessStatus = DCM_E_NOT_OK;
  /* Parameter to store the length of input data (2U indicates the 2-byte RoutineID) received */
  Dcm_MsgLenType InDataLength = pMsgContext->reqDataLen - 2U;

  if (DCM_INITIAL == OpStatus)
  {
    /* Total input data length check */
    if (InDataLength == 0U)
    {

      Dcm_Dsp_RoutineControl_ClearInternalArrays();

      ServiceProcessStatus = Rte_Call_RoutineServices_DcmDspRoutine_0x0303_RequestResults(DCM_INITIAL, &Uint8Array[0], ErrorCode);

    }
    else
    {
      /* Invalid total data length */
      *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
      ServiceProcessStatus = DCM_E_NOT_OK;
    }
  }
  else
  {
    ServiceProcessStatus = Rte_Call_RoutineServices_DcmDspRoutine_0x0303_RequestResults(OpStatus, &Uint8Array[0], ErrorCode);
  }

  if (ServiceProcessStatus == E_OK)
  {
    pMsgContext->resDataLen = 6U;
    /* Deviation MISRAC2012-1 <+2> */
    /* Deviation MISRA-1 <+2> */
    Dcm_DspInternal_CopySignalData((P2VAR(uint8, AUTOMATIC, DCM_VAR))&Uint8Array[0],
                                   (P2VAR(uint8, AUTOMATIC, DCM_VAR))&(pMsgContext->resData[3]),
                                   0U,
                                   0U,
                                   24U,
                                   DCM_COPY_TO_OUTBUFFER_OPAQUE,
                                   DCM_BYTE_DIRECTION_INCREMENT);

    ServiceProcessStatus = DCM_E_OK;
  }
  else if(ServiceProcessStatus == E_NOT_OK)
  {
    ServiceProcessStatus = DCM_E_NOT_OK;
  }
  else
  {
    /* ServiceProcessStatus is DCM_E_PENDING, DCM_E_FORCE_RCRRP or unknown and these
     * cases are processed in service handler */
  }

  return ServiceProcessStatus;
}

FUNC(Std_ReturnType, DCM_CODE) Dcm_DcmDspRoutine_0x0302_Start(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode)
{
  Std_ReturnType ServiceProcessStatus = DCM_E_NOT_OK;
  /* Parameter to store the length of input data (2U indicates the 2-byte RoutineID) received */
  Dcm_MsgLenType InDataLength = pMsgContext->reqDataLen - 2U;

  if (DCM_INITIAL == OpStatus)
  {
    /* Total input data length check */
    if (InDataLength == 0U)
    {

      Dcm_Dsp_RoutineControl_ClearInternalArrays();

      ServiceProcessStatus = Rte_Call_RoutineServices_DcmDspRoutine_0x0302_Start(DCM_INITIAL, ErrorCode);

    }
    else
    {
      /* Invalid total data length */
      *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
      ServiceProcessStatus = DCM_E_NOT_OK;
    }
  }
  else
  {
    ServiceProcessStatus = Rte_Call_RoutineServices_DcmDspRoutine_0x0302_Start(OpStatus, ErrorCode);
  }

  if (ServiceProcessStatus == E_OK)
  {
    pMsgContext->resDataLen = 3U;

    ServiceProcessStatus = DCM_E_OK;
  }
  else if(ServiceProcessStatus == E_NOT_OK)
  {
    ServiceProcessStatus = DCM_E_NOT_OK;
  }
  else
  {
    /* ServiceProcessStatus is DCM_E_PENDING, DCM_E_FORCE_RCRRP or unknown and these
     * cases are processed in service handler */
  }

  return ServiceProcessStatus;
}

FUNC(Std_ReturnType, DCM_CODE) Dcm_DcmDspRoutine_0x0302_RequestResults(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode)
{
  Std_ReturnType ServiceProcessStatus = DCM_E_NOT_OK;
  /* Parameter to store the length of input data (2U indicates the 2-byte RoutineID) received */
  Dcm_MsgLenType InDataLength = pMsgContext->reqDataLen - 2U;

  if (DCM_INITIAL == OpStatus)
  {
    /* Total input data length check */
    if (InDataLength == 0U)
    {

      Dcm_Dsp_RoutineControl_ClearInternalArrays();

      ServiceProcessStatus = Rte_Call_RoutineServices_DcmDspRoutine_0x0302_RequestResults(DCM_INITIAL, &Uint8Array[0], ErrorCode);

    }
    else
    {
      /* Invalid total data length */
      *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
      ServiceProcessStatus = DCM_E_NOT_OK;
    }
  }
  else
  {
    ServiceProcessStatus = Rte_Call_RoutineServices_DcmDspRoutine_0x0302_RequestResults(OpStatus, &Uint8Array[0], ErrorCode);
  }

  if (ServiceProcessStatus == E_OK)
  {
    pMsgContext->resDataLen = 4U;
    /* Deviation MISRAC2012-1 <+2> */
    /* Deviation MISRA-1 <+2> */
    Dcm_DspInternal_CopySignalData((P2VAR(uint8, AUTOMATIC, DCM_VAR))&Uint8Array[0],
                                   (P2VAR(uint8, AUTOMATIC, DCM_VAR))&(pMsgContext->resData[3]),
                                   0U,
                                   0U,
                                   8U,
                                   DCM_COPY_TO_OUTBUFFER_OPAQUE,
                                   DCM_BYTE_DIRECTION_INCREMENT);

    ServiceProcessStatus = DCM_E_OK;
  }
  else if(ServiceProcessStatus == E_NOT_OK)
  {
    ServiceProcessStatus = DCM_E_NOT_OK;
  }
  else
  {
    /* ServiceProcessStatus is DCM_E_PENDING, DCM_E_FORCE_RCRRP or unknown and these
     * cases are processed in service handler */
  }

  return ServiceProcessStatus;
}

FUNC(Std_ReturnType, DCM_CODE) Dcm_DcmDspRoutine_0x0305_Start(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode)
{
  Std_ReturnType ServiceProcessStatus = DCM_E_NOT_OK;
  /* Parameter to store the length of input data (2U indicates the 2-byte RoutineID) received */
  Dcm_MsgLenType InDataLength = pMsgContext->reqDataLen - 2U;

  if (DCM_INITIAL == OpStatus)
  {
    /* Total input data length check */
    if (InDataLength == 1U)
    {

      Dcm_Dsp_RoutineControl_ClearInternalArrays();

      /* Deviation MISRAC2012-1 <+2> */
      /* Deviation MISRA-1 <+2> */
      Dcm_DspInternal_CopySignalData((P2VAR(uint8, AUTOMATIC, DCM_VAR))&(pMsgContext->reqData[2]),
                                     (P2VAR(uint8, AUTOMATIC, DCM_VAR))&Uint8Array[0],
                                     0U,
                                     0U,
                                     8U,
                                     DCM_COPY_FROM_INBUFFER_OPAQUE,
                                     DCM_BYTE_DIRECTION_INCREMENT);

      ServiceProcessStatus = Rte_Call_RoutineServices_DcmDspRoutine_0x0305_Start(Uint8Array[0], DCM_INITIAL, ErrorCode);

    }
    else
    {
      /* Invalid total data length */
      *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
      ServiceProcessStatus = DCM_E_NOT_OK;
    }
  }
  else
  {
    ServiceProcessStatus = Rte_Call_RoutineServices_DcmDspRoutine_0x0305_Start(Uint8Array[0], OpStatus, ErrorCode);
  }

  if (ServiceProcessStatus == E_OK)
  {
    pMsgContext->resDataLen = 3U;

    ServiceProcessStatus = DCM_E_OK;
  }
  else if(ServiceProcessStatus == E_NOT_OK)
  {
    ServiceProcessStatus = DCM_E_NOT_OK;
  }
  else
  {
    /* ServiceProcessStatus is DCM_E_PENDING, DCM_E_FORCE_RCRRP or unknown and these
     * cases are processed in service handler */
  }

  return ServiceProcessStatus;
}

FUNC(Std_ReturnType, DCM_CODE) Dcm_DcmDspRoutine_0x0305_RequestResults(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode)
{
  Std_ReturnType ServiceProcessStatus = DCM_E_NOT_OK;
  /* Parameter to store the length of input data (2U indicates the 2-byte RoutineID) received */
  Dcm_MsgLenType InDataLength = pMsgContext->reqDataLen - 2U;

  if (DCM_INITIAL == OpStatus)
  {
    /* Total input data length check */
    if (InDataLength == 0U)
    {

      Dcm_Dsp_RoutineControl_ClearInternalArrays();

      ServiceProcessStatus = Rte_Call_RoutineServices_DcmDspRoutine_0x0305_RequestResults(DCM_INITIAL, &Uint8Array[0], ErrorCode);

    }
    else
    {
      /* Invalid total data length */
      *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
      ServiceProcessStatus = DCM_E_NOT_OK;
    }
  }
  else
  {
    ServiceProcessStatus = Rte_Call_RoutineServices_DcmDspRoutine_0x0305_RequestResults(OpStatus, &Uint8Array[0], ErrorCode);
  }

  if (ServiceProcessStatus == E_OK)
  {
    pMsgContext->resDataLen = 4U;
    /* Deviation MISRAC2012-1 <+2> */
    /* Deviation MISRA-1 <+2> */
    Dcm_DspInternal_CopySignalData((P2VAR(uint8, AUTOMATIC, DCM_VAR))&Uint8Array[0],
                                   (P2VAR(uint8, AUTOMATIC, DCM_VAR))&(pMsgContext->resData[3]),
                                   0U,
                                   0U,
                                   8U,
                                   DCM_COPY_TO_OUTBUFFER_OPAQUE,
                                   DCM_BYTE_DIRECTION_INCREMENT);

    ServiceProcessStatus = DCM_E_OK;
  }
  else if(ServiceProcessStatus == E_NOT_OK)
  {
    ServiceProcessStatus = DCM_E_NOT_OK;
  }
  else
  {
    /* ServiceProcessStatus is DCM_E_PENDING, DCM_E_FORCE_RCRRP or unknown and these
     * cases are processed in service handler */
  }

  return ServiceProcessStatus;
}

FUNC(Std_ReturnType, DCM_CODE) Dcm_DcmDspRoutine_0x0306_Start(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode)
{
  Std_ReturnType ServiceProcessStatus = DCM_E_NOT_OK;
  /* Parameter to store the length of input data (2U indicates the 2-byte RoutineID) received */
  Dcm_MsgLenType InDataLength = pMsgContext->reqDataLen - 2U;

  if (DCM_INITIAL == OpStatus)
  {
    /* Total input data length check */
    if (InDataLength == 3U)
    {

      Dcm_Dsp_RoutineControl_ClearInternalArrays();

      /* Deviation MISRAC2012-1 <+2> */
      /* Deviation MISRA-1 <+2> */
      Dcm_DspInternal_CopySignalData((P2VAR(uint8, AUTOMATIC, DCM_VAR))&(pMsgContext->reqData[2]),
                                     (P2VAR(uint8, AUTOMATIC, DCM_VAR))&Uint8Array[0],
                                     0U,
                                     0U,
                                     8U,
                                     DCM_COPY_FROM_INBUFFER_OPAQUE,
                                     DCM_BYTE_DIRECTION_INCREMENT);

      /* Deviation MISRAC2012-1 <+2> */
      /* Deviation MISRA-1 <+2> */
      Dcm_DspInternal_CopySignalData((P2VAR(uint8, AUTOMATIC, DCM_VAR))&(pMsgContext->reqData[2]),
                                     (P2VAR(uint8, AUTOMATIC, DCM_VAR))&Uint8Array[1],
                                     8U,
                                     0U,
                                     8U,
                                     DCM_COPY_FROM_INBUFFER_OPAQUE,
                                     DCM_BYTE_DIRECTION_INCREMENT);

      /* Deviation MISRAC2012-1 <+2> */
      /* Deviation MISRA-1 <+2> */
      Dcm_DspInternal_CopySignalData((P2VAR(uint8, AUTOMATIC, DCM_VAR))&(pMsgContext->reqData[2]),
                                     (P2VAR(uint8, AUTOMATIC, DCM_VAR))&Uint8Array[2],
                                     16U,
                                     0U,
                                     8U,
                                     DCM_COPY_FROM_INBUFFER_OPAQUE,
                                     DCM_BYTE_DIRECTION_INCREMENT);

      ServiceProcessStatus = Rte_Call_RoutineServices_DcmDspRoutine_0x0306_Start(Uint8Array[0], Uint8Array[1], Uint8Array[2], DCM_INITIAL, ErrorCode);

    }
    else
    {
      /* Invalid total data length */
      *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
      ServiceProcessStatus = DCM_E_NOT_OK;
    }
  }
  else
  {
    ServiceProcessStatus = Rte_Call_RoutineServices_DcmDspRoutine_0x0306_Start(Uint8Array[0], Uint8Array[1], Uint8Array[2], OpStatus, ErrorCode);
  }

  if (ServiceProcessStatus == E_OK)
  {
    pMsgContext->resDataLen = 3U;

    ServiceProcessStatus = DCM_E_OK;
  }
  else if(ServiceProcessStatus == E_NOT_OK)
  {
    ServiceProcessStatus = DCM_E_NOT_OK;
  }
  else
  {
    /* ServiceProcessStatus is DCM_E_PENDING, DCM_E_FORCE_RCRRP or unknown and these
     * cases are processed in service handler */
  }

  return ServiceProcessStatus;
}

FUNC(Std_ReturnType, DCM_CODE) Dcm_DcmDspRoutine_0x0306_Stop(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode)
{
  Std_ReturnType ServiceProcessStatus = DCM_E_NOT_OK;
  /* Parameter to store the length of input data (2U indicates the 2-byte RoutineID) received */
  Dcm_MsgLenType InDataLength = pMsgContext->reqDataLen - 2U;

  if (DCM_INITIAL == OpStatus)
  {
    /* Total input data length check */
    if (InDataLength == 0U)
    {

      Dcm_Dsp_RoutineControl_ClearInternalArrays();

      ServiceProcessStatus = Rte_Call_RoutineServices_DcmDspRoutine_0x0306_Stop(DCM_INITIAL, ErrorCode);

    }
    else
    {
      /* Invalid total data length */
      *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
      ServiceProcessStatus = DCM_E_NOT_OK;
    }
  }
  else
  {
    ServiceProcessStatus = Rte_Call_RoutineServices_DcmDspRoutine_0x0306_Stop(OpStatus, ErrorCode);
  }

  if (ServiceProcessStatus == E_OK)
  {
    pMsgContext->resDataLen = 3U;

    ServiceProcessStatus = DCM_E_OK;
  }
  else if(ServiceProcessStatus == E_NOT_OK)
  {
    ServiceProcessStatus = DCM_E_NOT_OK;
  }
  else
  {
    /* ServiceProcessStatus is DCM_E_PENDING, DCM_E_FORCE_RCRRP or unknown and these
     * cases are processed in service handler */
  }

  return ServiceProcessStatus;
}

FUNC(Std_ReturnType, DCM_CODE) Dcm_DcmDspRoutine_0x0306_RequestResults(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode)
{
  Std_ReturnType ServiceProcessStatus = DCM_E_NOT_OK;
  /* Parameter to store the length of input data (2U indicates the 2-byte RoutineID) received */
  Dcm_MsgLenType InDataLength = pMsgContext->reqDataLen - 2U;

  if (DCM_INITIAL == OpStatus)
  {
    /* Total input data length check */
    if (InDataLength == 0U)
    {

      Dcm_Dsp_RoutineControl_ClearInternalArrays();

      ServiceProcessStatus = Rte_Call_RoutineServices_DcmDspRoutine_0x0306_RequestResults(DCM_INITIAL, &Uint8Array[0], ErrorCode);

    }
    else
    {
      /* Invalid total data length */
      *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
      ServiceProcessStatus = DCM_E_NOT_OK;
    }
  }
  else
  {
    ServiceProcessStatus = Rte_Call_RoutineServices_DcmDspRoutine_0x0306_RequestResults(OpStatus, &Uint8Array[0], ErrorCode);
  }

  if (ServiceProcessStatus == E_OK)
  {
    pMsgContext->resDataLen = 4U;
    /* Deviation MISRAC2012-1 <+2> */
    /* Deviation MISRA-1 <+2> */
    Dcm_DspInternal_CopySignalData((P2VAR(uint8, AUTOMATIC, DCM_VAR))&Uint8Array[0],
                                   (P2VAR(uint8, AUTOMATIC, DCM_VAR))&(pMsgContext->resData[3]),
                                   0U,
                                   0U,
                                   8U,
                                   DCM_COPY_TO_OUTBUFFER_OPAQUE,
                                   DCM_BYTE_DIRECTION_INCREMENT);

    ServiceProcessStatus = DCM_E_OK;
  }
  else if(ServiceProcessStatus == E_NOT_OK)
  {
    ServiceProcessStatus = DCM_E_NOT_OK;
  }
  else
  {
    /* ServiceProcessStatus is DCM_E_PENDING, DCM_E_FORCE_RCRRP or unknown and these
     * cases are processed in service handler */
  }

  return ServiceProcessStatus;
}

FUNC(Std_ReturnType, DCM_CODE) Dcm_DcmDspRoutine_0x0307_Start(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode)
{
  Std_ReturnType ServiceProcessStatus = DCM_E_NOT_OK;
  /* Parameter to store the length of input data (2U indicates the 2-byte RoutineID) received */
  Dcm_MsgLenType InDataLength = pMsgContext->reqDataLen - 2U;

  if (DCM_INITIAL == OpStatus)
  {
    /* Total input data length check */
    if (InDataLength == 2U)
    {

      Dcm_Dsp_RoutineControl_ClearInternalArrays();

      /* Deviation MISRAC2012-1 <+2> */
      /* Deviation MISRA-1 <+2> */
      Dcm_DspInternal_CopySignalData((P2VAR(uint8, AUTOMATIC, DCM_VAR))&(pMsgContext->reqData[2]),
                                     (P2VAR(uint8, AUTOMATIC, DCM_VAR))&Uint8Array[0],
                                     0U,
                                     0U,
                                     8U,
                                     DCM_COPY_FROM_INBUFFER_OPAQUE,
                                     DCM_BYTE_DIRECTION_INCREMENT);

      /* Deviation MISRAC2012-1 <+2> */
      /* Deviation MISRA-1 <+2> */
      Dcm_DspInternal_CopySignalData((P2VAR(uint8, AUTOMATIC, DCM_VAR))&(pMsgContext->reqData[2]),
                                     (P2VAR(uint8, AUTOMATIC, DCM_VAR))&Uint8Array[1],
                                     8U,
                                     0U,
                                     8U,
                                     DCM_COPY_FROM_INBUFFER_OPAQUE,
                                     DCM_BYTE_DIRECTION_INCREMENT);

      ServiceProcessStatus = Rte_Call_RoutineServices_DcmDspRoutine_0x0307_Start(Uint8Array[0], Uint8Array[1], DCM_INITIAL, ErrorCode);

    }
    else
    {
      /* Invalid total data length */
      *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
      ServiceProcessStatus = DCM_E_NOT_OK;
    }
  }
  else
  {
    ServiceProcessStatus = Rte_Call_RoutineServices_DcmDspRoutine_0x0307_Start(Uint8Array[0], Uint8Array[1], OpStatus, ErrorCode);
  }

  if (ServiceProcessStatus == E_OK)
  {
    pMsgContext->resDataLen = 3U;

    ServiceProcessStatus = DCM_E_OK;
  }
  else if(ServiceProcessStatus == E_NOT_OK)
  {
    ServiceProcessStatus = DCM_E_NOT_OK;
  }
  else
  {
    /* ServiceProcessStatus is DCM_E_PENDING, DCM_E_FORCE_RCRRP or unknown and these
     * cases are processed in service handler */
  }

  return ServiceProcessStatus;
}

FUNC(Std_ReturnType, DCM_CODE) Dcm_DcmDspRoutine_0x0307_Stop(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode)
{
  Std_ReturnType ServiceProcessStatus = DCM_E_NOT_OK;
  /* Parameter to store the length of input data (2U indicates the 2-byte RoutineID) received */
  Dcm_MsgLenType InDataLength = pMsgContext->reqDataLen - 2U;

  if (DCM_INITIAL == OpStatus)
  {
    /* Total input data length check */
    if (InDataLength == 0U)
    {

      Dcm_Dsp_RoutineControl_ClearInternalArrays();

      ServiceProcessStatus = Rte_Call_RoutineServices_DcmDspRoutine_0x0307_Stop(DCM_INITIAL, ErrorCode);

    }
    else
    {
      /* Invalid total data length */
      *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
      ServiceProcessStatus = DCM_E_NOT_OK;
    }
  }
  else
  {
    ServiceProcessStatus = Rte_Call_RoutineServices_DcmDspRoutine_0x0307_Stop(OpStatus, ErrorCode);
  }

  if (ServiceProcessStatus == E_OK)
  {
    pMsgContext->resDataLen = 3U;

    ServiceProcessStatus = DCM_E_OK;
  }
  else if(ServiceProcessStatus == E_NOT_OK)
  {
    ServiceProcessStatus = DCM_E_NOT_OK;
  }
  else
  {
    /* ServiceProcessStatus is DCM_E_PENDING, DCM_E_FORCE_RCRRP or unknown and these
     * cases are processed in service handler */
  }

  return ServiceProcessStatus;
}

FUNC(Std_ReturnType, DCM_CODE) Dcm_DcmDspRoutine_0x0307_RequestResults(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode)
{
  Std_ReturnType ServiceProcessStatus = DCM_E_NOT_OK;
  /* Parameter to store the length of input data (2U indicates the 2-byte RoutineID) received */
  Dcm_MsgLenType InDataLength = pMsgContext->reqDataLen - 2U;

  if (DCM_INITIAL == OpStatus)
  {
    /* Total input data length check */
    if (InDataLength == 0U)
    {

      Dcm_Dsp_RoutineControl_ClearInternalArrays();

      ServiceProcessStatus = Rte_Call_RoutineServices_DcmDspRoutine_0x0307_RequestResults(DCM_INITIAL, &Uint8Array[0], ErrorCode);

    }
    else
    {
      /* Invalid total data length */
      *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
      ServiceProcessStatus = DCM_E_NOT_OK;
    }
  }
  else
  {
    ServiceProcessStatus = Rte_Call_RoutineServices_DcmDspRoutine_0x0307_RequestResults(OpStatus, &Uint8Array[0], ErrorCode);
  }

  if (ServiceProcessStatus == E_OK)
  {
    pMsgContext->resDataLen = 4U;
    /* Deviation MISRAC2012-1 <+2> */
    /* Deviation MISRA-1 <+2> */
    Dcm_DspInternal_CopySignalData((P2VAR(uint8, AUTOMATIC, DCM_VAR))&Uint8Array[0],
                                   (P2VAR(uint8, AUTOMATIC, DCM_VAR))&(pMsgContext->resData[3]),
                                   0U,
                                   0U,
                                   8U,
                                   DCM_COPY_TO_OUTBUFFER_OPAQUE,
                                   DCM_BYTE_DIRECTION_INCREMENT);

    ServiceProcessStatus = DCM_E_OK;
  }
  else if(ServiceProcessStatus == E_NOT_OK)
  {
    ServiceProcessStatus = DCM_E_NOT_OK;
  }
  else
  {
    /* ServiceProcessStatus is DCM_E_PENDING, DCM_E_FORCE_RCRRP or unknown and these
     * cases are processed in service handler */
  }

  return ServiceProcessStatus;
}

FUNC(Std_ReturnType, DCM_CODE) Dcm_DcmDspRoutine_0x0308_Start(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode)
{
  Std_ReturnType ServiceProcessStatus = DCM_E_NOT_OK;
  /* Parameter to store the length of input data (2U indicates the 2-byte RoutineID) received */
  Dcm_MsgLenType InDataLength = pMsgContext->reqDataLen - 2U;

  if (DCM_INITIAL == OpStatus)
  {
    /* Total input data length check */
    if (InDataLength == 1U)
    {

      Dcm_Dsp_RoutineControl_ClearInternalArrays();

      /* Deviation MISRAC2012-1 <+2> */
      /* Deviation MISRA-1 <+2> */
      Dcm_DspInternal_CopySignalData((P2VAR(uint8, AUTOMATIC, DCM_VAR))&(pMsgContext->reqData[2]),
                                     (P2VAR(uint8, AUTOMATIC, DCM_VAR))&Uint8Array[0],
                                     0U,
                                     0U,
                                     8U,
                                     DCM_COPY_FROM_INBUFFER_OPAQUE,
                                     DCM_BYTE_DIRECTION_INCREMENT);

      ServiceProcessStatus = Rte_Call_RoutineServices_DcmDspRoutine_0x0308_Start(Uint8Array[0], DCM_INITIAL, ErrorCode);

    }
    else
    {
      /* Invalid total data length */
      *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
      ServiceProcessStatus = DCM_E_NOT_OK;
    }
  }
  else
  {
    ServiceProcessStatus = Rte_Call_RoutineServices_DcmDspRoutine_0x0308_Start(Uint8Array[0], OpStatus, ErrorCode);
  }

  if (ServiceProcessStatus == E_OK)
  {
    pMsgContext->resDataLen = 3U;

    ServiceProcessStatus = DCM_E_OK;
  }
  else if(ServiceProcessStatus == E_NOT_OK)
  {
    ServiceProcessStatus = DCM_E_NOT_OK;
  }
  else
  {
    /* ServiceProcessStatus is DCM_E_PENDING, DCM_E_FORCE_RCRRP or unknown and these
     * cases are processed in service handler */
  }

  return ServiceProcessStatus;
}

FUNC(Std_ReturnType, DCM_CODE) Dcm_DcmDspRoutine_0x0308_RequestResults(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode)
{
  Std_ReturnType ServiceProcessStatus = DCM_E_NOT_OK;
  /* Parameter to store the length of input data (2U indicates the 2-byte RoutineID) received */
  Dcm_MsgLenType InDataLength = pMsgContext->reqDataLen - 2U;

  if (DCM_INITIAL == OpStatus)
  {
    /* Total input data length check */
    if (InDataLength == 0U)
    {

      Dcm_Dsp_RoutineControl_ClearInternalArrays();

      ServiceProcessStatus = Rte_Call_RoutineServices_DcmDspRoutine_0x0308_RequestResults(DCM_INITIAL, &Uint8Array[0], ErrorCode);

    }
    else
    {
      /* Invalid total data length */
      *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
      ServiceProcessStatus = DCM_E_NOT_OK;
    }
  }
  else
  {
    ServiceProcessStatus = Rte_Call_RoutineServices_DcmDspRoutine_0x0308_RequestResults(OpStatus, &Uint8Array[0], ErrorCode);
  }

  if (ServiceProcessStatus == E_OK)
  {
    pMsgContext->resDataLen = 4U;
    /* Deviation MISRAC2012-1 <+2> */
    /* Deviation MISRA-1 <+2> */
    Dcm_DspInternal_CopySignalData((P2VAR(uint8, AUTOMATIC, DCM_VAR))&Uint8Array[0],
                                   (P2VAR(uint8, AUTOMATIC, DCM_VAR))&(pMsgContext->resData[3]),
                                   0U,
                                   0U,
                                   8U,
                                   DCM_COPY_TO_OUTBUFFER_OPAQUE,
                                   DCM_BYTE_DIRECTION_INCREMENT);

    ServiceProcessStatus = DCM_E_OK;
  }
  else if(ServiceProcessStatus == E_NOT_OK)
  {
    ServiceProcessStatus = DCM_E_NOT_OK;
  }
  else
  {
    /* ServiceProcessStatus is DCM_E_PENDING, DCM_E_FORCE_RCRRP or unknown and these
     * cases are processed in service handler */
  }

  return ServiceProcessStatus;
}

FUNC(Std_ReturnType, DCM_CODE) Dcm_DcmDspRoutine_0x0309_Start(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode)
{
  Std_ReturnType ServiceProcessStatus = DCM_E_NOT_OK;
  /* Parameter to store the length of input data (2U indicates the 2-byte RoutineID) received */
  Dcm_MsgLenType InDataLength = pMsgContext->reqDataLen - 2U;

  if (DCM_INITIAL == OpStatus)
  {
    /* Total input data length check */
    if (InDataLength == 1U)
    {

      Dcm_Dsp_RoutineControl_ClearInternalArrays();

      /* Deviation MISRAC2012-1 <+2> */
      /* Deviation MISRA-1 <+2> */
      Dcm_DspInternal_CopySignalData((P2VAR(uint8, AUTOMATIC, DCM_VAR))&(pMsgContext->reqData[2]),
                                     (P2VAR(uint8, AUTOMATIC, DCM_VAR))&Uint8Array[0],
                                     0U,
                                     0U,
                                     8U,
                                     DCM_COPY_FROM_INBUFFER_OPAQUE,
                                     DCM_BYTE_DIRECTION_INCREMENT);

      ServiceProcessStatus = Rte_Call_RoutineServices_DcmDspRoutine_0x0309_Start(Uint8Array[0], DCM_INITIAL, ErrorCode);

    }
    else
    {
      /* Invalid total data length */
      *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
      ServiceProcessStatus = DCM_E_NOT_OK;
    }
  }
  else
  {
    ServiceProcessStatus = Rte_Call_RoutineServices_DcmDspRoutine_0x0309_Start(Uint8Array[0], OpStatus, ErrorCode);
  }

  if (ServiceProcessStatus == E_OK)
  {
    pMsgContext->resDataLen = 3U;

    ServiceProcessStatus = DCM_E_OK;
  }
  else if(ServiceProcessStatus == E_NOT_OK)
  {
    ServiceProcessStatus = DCM_E_NOT_OK;
  }
  else
  {
    /* ServiceProcessStatus is DCM_E_PENDING, DCM_E_FORCE_RCRRP or unknown and these
     * cases are processed in service handler */
  }

  return ServiceProcessStatus;
}

FUNC(Std_ReturnType, DCM_CODE) Dcm_DcmDspRoutine_0x0309_RequestResults(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode)
{
  Std_ReturnType ServiceProcessStatus = DCM_E_NOT_OK;
  /* Parameter to store the length of input data (2U indicates the 2-byte RoutineID) received */
  Dcm_MsgLenType InDataLength = pMsgContext->reqDataLen - 2U;

  if (DCM_INITIAL == OpStatus)
  {
    /* Total input data length check */
    if (InDataLength == 0U)
    {

      Dcm_Dsp_RoutineControl_ClearInternalArrays();

      ServiceProcessStatus = Rte_Call_RoutineServices_DcmDspRoutine_0x0309_RequestResults(DCM_INITIAL, &Uint8Array[0], ErrorCode);

    }
    else
    {
      /* Invalid total data length */
      *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
      ServiceProcessStatus = DCM_E_NOT_OK;
    }
  }
  else
  {
    ServiceProcessStatus = Rte_Call_RoutineServices_DcmDspRoutine_0x0309_RequestResults(OpStatus, &Uint8Array[0], ErrorCode);
  }

  if (ServiceProcessStatus == E_OK)
  {
    pMsgContext->resDataLen = 4U;
    /* Deviation MISRAC2012-1 <+2> */
    /* Deviation MISRA-1 <+2> */
    Dcm_DspInternal_CopySignalData((P2VAR(uint8, AUTOMATIC, DCM_VAR))&Uint8Array[0],
                                   (P2VAR(uint8, AUTOMATIC, DCM_VAR))&(pMsgContext->resData[3]),
                                   0U,
                                   0U,
                                   8U,
                                   DCM_COPY_TO_OUTBUFFER_OPAQUE,
                                   DCM_BYTE_DIRECTION_INCREMENT);

    ServiceProcessStatus = DCM_E_OK;
  }
  else if(ServiceProcessStatus == E_NOT_OK)
  {
    ServiceProcessStatus = DCM_E_NOT_OK;
  }
  else
  {
    /* ServiceProcessStatus is DCM_E_PENDING, DCM_E_FORCE_RCRRP or unknown and these
     * cases are processed in service handler */
  }

  return ServiceProcessStatus;
}

FUNC(Std_ReturnType, DCM_CODE) Dcm_DcmDspRoutine_0x030A_Start(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode)
{
  Std_ReturnType ServiceProcessStatus = DCM_E_NOT_OK;
  /* Parameter to store the length of input data (2U indicates the 2-byte RoutineID) received */
  Dcm_MsgLenType InDataLength = pMsgContext->reqDataLen - 2U;

  if (DCM_INITIAL == OpStatus)
  {
    /* Total input data length check */
    if (InDataLength == 1U)
    {

      Dcm_Dsp_RoutineControl_ClearInternalArrays();

      /* Deviation MISRAC2012-1 <+2> */
      /* Deviation MISRA-1 <+2> */
      Dcm_DspInternal_CopySignalData((P2VAR(uint8, AUTOMATIC, DCM_VAR))&(pMsgContext->reqData[2]),
                                     (P2VAR(uint8, AUTOMATIC, DCM_VAR))&Uint8Array[0],
                                     0U,
                                     0U,
                                     8U,
                                     DCM_COPY_FROM_INBUFFER_OPAQUE,
                                     DCM_BYTE_DIRECTION_INCREMENT);

      ServiceProcessStatus = Rte_Call_RoutineServices_DcmDspRoutine_0x030A_Start(Uint8Array[0], DCM_INITIAL, ErrorCode);

    }
    else
    {
      /* Invalid total data length */
      *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
      ServiceProcessStatus = DCM_E_NOT_OK;
    }
  }
  else
  {
    ServiceProcessStatus = Rte_Call_RoutineServices_DcmDspRoutine_0x030A_Start(Uint8Array[0], OpStatus, ErrorCode);
  }

  if (ServiceProcessStatus == E_OK)
  {
    pMsgContext->resDataLen = 3U;

    ServiceProcessStatus = DCM_E_OK;
  }
  else if(ServiceProcessStatus == E_NOT_OK)
  {
    ServiceProcessStatus = DCM_E_NOT_OK;
  }
  else
  {
    /* ServiceProcessStatus is DCM_E_PENDING, DCM_E_FORCE_RCRRP or unknown and these
     * cases are processed in service handler */
  }

  return ServiceProcessStatus;
}

FUNC(Std_ReturnType, DCM_CODE) Dcm_DcmDspRoutine_0x030A_RequestResults(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode)
{
  Std_ReturnType ServiceProcessStatus = DCM_E_NOT_OK;
  /* Parameter to store the length of input data (2U indicates the 2-byte RoutineID) received */
  Dcm_MsgLenType InDataLength = pMsgContext->reqDataLen - 2U;

  if (DCM_INITIAL == OpStatus)
  {
    /* Total input data length check */
    if (InDataLength == 0U)
    {

      Dcm_Dsp_RoutineControl_ClearInternalArrays();

      ServiceProcessStatus = Rte_Call_RoutineServices_DcmDspRoutine_0x030A_RequestResults(DCM_INITIAL, &Uint8Array[0], ErrorCode);

    }
    else
    {
      /* Invalid total data length */
      *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
      ServiceProcessStatus = DCM_E_NOT_OK;
    }
  }
  else
  {
    ServiceProcessStatus = Rte_Call_RoutineServices_DcmDspRoutine_0x030A_RequestResults(OpStatus, &Uint8Array[0], ErrorCode);
  }

  if (ServiceProcessStatus == E_OK)
  {
    pMsgContext->resDataLen = 4U;
    /* Deviation MISRAC2012-1 <+2> */
    /* Deviation MISRA-1 <+2> */
    Dcm_DspInternal_CopySignalData((P2VAR(uint8, AUTOMATIC, DCM_VAR))&Uint8Array[0],
                                   (P2VAR(uint8, AUTOMATIC, DCM_VAR))&(pMsgContext->resData[3]),
                                   0U,
                                   0U,
                                   8U,
                                   DCM_COPY_TO_OUTBUFFER_OPAQUE,
                                   DCM_BYTE_DIRECTION_INCREMENT);

    ServiceProcessStatus = DCM_E_OK;
  }
  else if(ServiceProcessStatus == E_NOT_OK)
  {
    ServiceProcessStatus = DCM_E_NOT_OK;
  }
  else
  {
    /* ServiceProcessStatus is DCM_E_PENDING, DCM_E_FORCE_RCRRP or unknown and these
     * cases are processed in service handler */
  }

  return ServiceProcessStatus;
}

FUNC(Std_ReturnType, DCM_CODE) Dcm_DcmDspRoutine_0x8011_Start(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode)
{
  Std_ReturnType ServiceProcessStatus = DCM_E_NOT_OK;
  /* Parameter to store the length of input data (2U indicates the 2-byte RoutineID) received */
  Dcm_MsgLenType InDataLength = pMsgContext->reqDataLen - 2U;

  if (DCM_INITIAL == OpStatus)
  {
    /* Total input data length check */
    if (InDataLength == 1U)
    {

      Dcm_Dsp_RoutineControl_ClearInternalArrays();

      /* Deviation MISRAC2012-1 <+2> */
      /* Deviation MISRA-1 <+2> */
      Dcm_DspInternal_CopySignalData((P2VAR(uint8, AUTOMATIC, DCM_VAR))&(pMsgContext->reqData[2]),
                                     (P2VAR(uint8, AUTOMATIC, DCM_VAR))&Uint8Array[0],
                                     0U,
                                     0U,
                                     8U,
                                     DCM_COPY_FROM_INBUFFER_OPAQUE,
                                     DCM_BYTE_DIRECTION_INCREMENT);

      ServiceProcessStatus = Rte_Call_RoutineServices_DcmDspRoutine_0x8011_Start(Uint8Array[0], DCM_INITIAL, ErrorCode);

    }
    else
    {
      /* Invalid total data length */
      *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
      ServiceProcessStatus = DCM_E_NOT_OK;
    }
  }
  else
  {
    ServiceProcessStatus = Rte_Call_RoutineServices_DcmDspRoutine_0x8011_Start(Uint8Array[0], OpStatus, ErrorCode);
  }

  if (ServiceProcessStatus == E_OK)
  {
    pMsgContext->resDataLen = 3U;

    ServiceProcessStatus = DCM_E_OK;
  }
  else if(ServiceProcessStatus == E_NOT_OK)
  {
    ServiceProcessStatus = DCM_E_NOT_OK;
  }
  else
  {
    /* ServiceProcessStatus is DCM_E_PENDING, DCM_E_FORCE_RCRRP or unknown and these
     * cases are processed in service handler */
  }

  return ServiceProcessStatus;
}

FUNC(Std_ReturnType, DCM_CODE) Dcm_DcmDspRoutine_0x8011_RequestResults(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode)
{
  Std_ReturnType ServiceProcessStatus = DCM_E_NOT_OK;
  /* Parameter to store the length of input data (2U indicates the 2-byte RoutineID) received */
  Dcm_MsgLenType InDataLength = pMsgContext->reqDataLen - 2U;

  if (DCM_INITIAL == OpStatus)
  {
    /* Total input data length check */
    if (InDataLength == 0U)
    {

      Dcm_Dsp_RoutineControl_ClearInternalArrays();

      ServiceProcessStatus = Rte_Call_RoutineServices_DcmDspRoutine_0x8011_RequestResults(DCM_INITIAL, &Uint8Array[0], ErrorCode);

    }
    else
    {
      /* Invalid total data length */
      *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
      ServiceProcessStatus = DCM_E_NOT_OK;
    }
  }
  else
  {
    ServiceProcessStatus = Rte_Call_RoutineServices_DcmDspRoutine_0x8011_RequestResults(OpStatus, &Uint8Array[0], ErrorCode);
  }

  if (ServiceProcessStatus == E_OK)
  {
    pMsgContext->resDataLen = 4U;
    /* Deviation MISRAC2012-1 <+2> */
    /* Deviation MISRA-1 <+2> */
    Dcm_DspInternal_CopySignalData((P2VAR(uint8, AUTOMATIC, DCM_VAR))&Uint8Array[0],
                                   (P2VAR(uint8, AUTOMATIC, DCM_VAR))&(pMsgContext->resData[3]),
                                   0U,
                                   0U,
                                   8U,
                                   DCM_COPY_TO_OUTBUFFER_OPAQUE,
                                   DCM_BYTE_DIRECTION_INCREMENT);

    ServiceProcessStatus = DCM_E_OK;
  }
  else if(ServiceProcessStatus == E_NOT_OK)
  {
    ServiceProcessStatus = DCM_E_NOT_OK;
  }
  else
  {
    /* ServiceProcessStatus is DCM_E_PENDING, DCM_E_FORCE_RCRRP or unknown and these
     * cases are processed in service handler */
  }

  return ServiceProcessStatus;
}

FUNC(Std_ReturnType, DCM_CODE) Dcm_DcmDspRoutine_0xF012_Start(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode)
{
  Std_ReturnType ServiceProcessStatus = DCM_E_NOT_OK;
  /* Parameter to store the length of input data (2U indicates the 2-byte RoutineID) received */
  Dcm_MsgLenType InDataLength = pMsgContext->reqDataLen - 2U;

  if (DCM_INITIAL == OpStatus)
  {
    /* Total input data length check */
    if (InDataLength == 1U)
    {

      Dcm_Dsp_RoutineControl_ClearInternalArrays();

      /* Deviation MISRAC2012-1 <+2> */
      /* Deviation MISRA-1 <+2> */
      Dcm_DspInternal_CopySignalData((P2VAR(uint8, AUTOMATIC, DCM_VAR))&(pMsgContext->reqData[2]),
                                     (P2VAR(uint8, AUTOMATIC, DCM_VAR))&Uint8Array[0],
                                     0U,
                                     0U,
                                     8U,
                                     DCM_COPY_FROM_INBUFFER_OPAQUE,
                                     DCM_BYTE_DIRECTION_INCREMENT);

      ServiceProcessStatus = Rte_Call_RoutineServices_DcmDspRoutine_0xF012_Start(Uint8Array[0], DCM_INITIAL, ErrorCode);

    }
    else
    {
      /* Invalid total data length */
      *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
      ServiceProcessStatus = DCM_E_NOT_OK;
    }
  }
  else
  {
    ServiceProcessStatus = Rte_Call_RoutineServices_DcmDspRoutine_0xF012_Start(Uint8Array[0], OpStatus, ErrorCode);
  }

  if (ServiceProcessStatus == E_OK)
  {
    pMsgContext->resDataLen = 3U;

    ServiceProcessStatus = DCM_E_OK;
  }
  else if(ServiceProcessStatus == E_NOT_OK)
  {
    ServiceProcessStatus = DCM_E_NOT_OK;
  }
  else
  {
    /* ServiceProcessStatus is DCM_E_PENDING, DCM_E_FORCE_RCRRP or unknown and these
     * cases are processed in service handler */
  }

  return ServiceProcessStatus;
}

FUNC(Std_ReturnType, DCM_CODE) Dcm_DcmDspRoutine_0xF012_RequestResults(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode)
{
  Std_ReturnType ServiceProcessStatus = DCM_E_NOT_OK;
  /* Parameter to store the length of input data (2U indicates the 2-byte RoutineID) received */
  Dcm_MsgLenType InDataLength = pMsgContext->reqDataLen - 2U;

  if (DCM_INITIAL == OpStatus)
  {
    /* Total input data length check */
    if (InDataLength == 1U)
    {

      Dcm_Dsp_RoutineControl_ClearInternalArrays();

      /* Deviation MISRAC2012-1 <+2> */
      /* Deviation MISRA-1 <+2> */
      Dcm_DspInternal_CopySignalData((P2VAR(uint8, AUTOMATIC, DCM_VAR))&(pMsgContext->reqData[2]),
                                     (P2VAR(uint8, AUTOMATIC, DCM_VAR))&Uint8Array[0],
                                     0U,
                                     0U,
                                     8U,
                                     DCM_COPY_FROM_INBUFFER_OPAQUE,
                                     DCM_BYTE_DIRECTION_INCREMENT);

      ServiceProcessStatus = Rte_Call_RoutineServices_DcmDspRoutine_0xF012_RequestResults(Uint8Array[0], DCM_INITIAL, &Uint8Array[1], &Uint8Array[2], ErrorCode);

    }
    else
    {
      /* Invalid total data length */
      *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
      ServiceProcessStatus = DCM_E_NOT_OK;
    }
  }
  else
  {
    ServiceProcessStatus = Rte_Call_RoutineServices_DcmDspRoutine_0xF012_RequestResults(Uint8Array[0], OpStatus, &Uint8Array[1], &Uint8Array[2], ErrorCode);
  }

  if (ServiceProcessStatus == E_OK)
  {
    pMsgContext->resDataLen = 5U;
    /* Deviation MISRAC2012-1 <+2> */
    /* Deviation MISRA-1 <+2> */
    Dcm_DspInternal_CopySignalData((P2VAR(uint8, AUTOMATIC, DCM_VAR))&Uint8Array[1],
                                   (P2VAR(uint8, AUTOMATIC, DCM_VAR))&(pMsgContext->resData[3]),
                                   0U,
                                   0U,
                                   8U,
                                   DCM_COPY_TO_OUTBUFFER_OPAQUE,
                                   DCM_BYTE_DIRECTION_INCREMENT);
    /* Deviation MISRAC2012-1 <+2> */
    /* Deviation MISRA-1 <+2> */
    Dcm_DspInternal_CopySignalData((P2VAR(uint8, AUTOMATIC, DCM_VAR))&Uint8Array[2],
                                   (P2VAR(uint8, AUTOMATIC, DCM_VAR))&(pMsgContext->resData[3]),
                                   0U,
                                   8U,
                                   8U,
                                   DCM_COPY_TO_OUTBUFFER_OPAQUE,
                                   DCM_BYTE_DIRECTION_INCREMENT);

    ServiceProcessStatus = DCM_E_OK;
  }
  else if(ServiceProcessStatus == E_NOT_OK)
  {
    ServiceProcessStatus = DCM_E_NOT_OK;
  }
  else
  {
    /* ServiceProcessStatus is DCM_E_PENDING, DCM_E_FORCE_RCRRP or unknown and these
     * cases are processed in service handler */
  }

  return ServiceProcessStatus;
}

FUNC(Std_ReturnType, DCM_CODE) Dcm_DcmDspRoutine_0xF013_Start(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode)
{
  Std_ReturnType ServiceProcessStatus = DCM_E_NOT_OK;
  /* Parameter to store the length of input data (2U indicates the 2-byte RoutineID) received */
  Dcm_MsgLenType InDataLength = pMsgContext->reqDataLen - 2U;

  if (DCM_INITIAL == OpStatus)
  {
    /* Total input data length check */
    if (InDataLength == 0U)
    {

      Dcm_Dsp_RoutineControl_ClearInternalArrays();

      ServiceProcessStatus = Rte_Call_RoutineServices_DcmDspRoutine_0xF013_Start(DCM_INITIAL, ErrorCode);

    }
    else
    {
      /* Invalid total data length */
      *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
      ServiceProcessStatus = DCM_E_NOT_OK;
    }
  }
  else
  {
    ServiceProcessStatus = Rte_Call_RoutineServices_DcmDspRoutine_0xF013_Start(OpStatus, ErrorCode);
  }

  if (ServiceProcessStatus == E_OK)
  {
    pMsgContext->resDataLen = 3U;

    ServiceProcessStatus = DCM_E_OK;
  }
  else if(ServiceProcessStatus == E_NOT_OK)
  {
    ServiceProcessStatus = DCM_E_NOT_OK;
  }
  else
  {
    /* ServiceProcessStatus is DCM_E_PENDING, DCM_E_FORCE_RCRRP or unknown and these
     * cases are processed in service handler */
  }

  return ServiceProcessStatus;
}

FUNC(Std_ReturnType, DCM_CODE) Dcm_DcmDspRoutine_0xF013_RequestResults(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode)
{
  Std_ReturnType ServiceProcessStatus = DCM_E_NOT_OK;
  /* Parameter to store the length of input data (2U indicates the 2-byte RoutineID) received */
  Dcm_MsgLenType InDataLength = pMsgContext->reqDataLen - 2U;

  if (DCM_INITIAL == OpStatus)
  {
    /* Total input data length check */
    if (InDataLength == 0U)
    {

      Dcm_Dsp_RoutineControl_ClearInternalArrays();

      ServiceProcessStatus = Rte_Call_RoutineServices_DcmDspRoutine_0xF013_RequestResults(DCM_INITIAL, &Uint8Array[0], ErrorCode);

    }
    else
    {
      /* Invalid total data length */
      *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
      ServiceProcessStatus = DCM_E_NOT_OK;
    }
  }
  else
  {
    ServiceProcessStatus = Rte_Call_RoutineServices_DcmDspRoutine_0xF013_RequestResults(OpStatus, &Uint8Array[0], ErrorCode);
  }

  if (ServiceProcessStatus == E_OK)
  {
    pMsgContext->resDataLen = 4U;
    /* Deviation MISRAC2012-1 <+2> */
    /* Deviation MISRA-1 <+2> */
    Dcm_DspInternal_CopySignalData((P2VAR(uint8, AUTOMATIC, DCM_VAR))&Uint8Array[0],
                                   (P2VAR(uint8, AUTOMATIC, DCM_VAR))&(pMsgContext->resData[3]),
                                   0U,
                                   0U,
                                   8U,
                                   DCM_COPY_TO_OUTBUFFER_OPAQUE,
                                   DCM_BYTE_DIRECTION_INCREMENT);

    ServiceProcessStatus = DCM_E_OK;
  }
  else if(ServiceProcessStatus == E_NOT_OK)
  {
    ServiceProcessStatus = DCM_E_NOT_OK;
  }
  else
  {
    /* ServiceProcessStatus is DCM_E_PENDING, DCM_E_FORCE_RCRRP or unknown and these
     * cases are processed in service handler */
  }

  return ServiceProcessStatus;
}

/*==================[internal function definitions]==============================================*/

STATIC FUNC(void, DCM_CODE) Dcm_Dsp_RoutineControl_ClearInternalArrays(void)
{

  TS_MemSet(Uint8Array,0U,sizeof(Uint8Array));

  TS_MemSet(Uint16Array,0U,sizeof(Uint16Array));

}
#if (DCM_ROUTINE_ENDIANNESS_CONVERSION == STD_ON)

STATIC FUNC(void, DCM_CODE) Dcm_Dsp_RoutineControl_SwapBytes_U16(uint16* SignalData, uint32 SignalLength)
{
  uint16_least ArrayIndex;
  for(ArrayIndex = 0U; ArrayIndex < SignalLength; ArrayIndex++)
  {
    const uint16 TempParameter = (SignalData[ArrayIndex] >> 8U) | (SignalData[ArrayIndex] << 8U);
    SignalData[ArrayIndex] = TempParameter;
  }
}



#endif

#define DCM_STOP_SEC_CODE
#include <Dcm_MemMap.h>
/*==================[end of file]================================================================*/
