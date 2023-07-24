/* --------{ EB Automotive C Source File }-------- */

/*==[Includes]================================================================*/

#include <Eth_GeneralTypes.h>
#include <EthTrcv_Types.h>
#include <EthTrcv.h>
#include <EBStubs_Cfg.h>

/*==[Macros]==================================================================*/

/*==[Types]===================================================================*/

#if (!defined EBSTUBS_FUNCTION_TRACE)
#define EBSTUBS_FUNCTION_TRACE STD_OFF
#endif

#if (!defined EBSTUBS_FUNCTION_TRACE_ETHTRCV)
#define EBSTUBS_FUNCTION_TRACE_ETHTRCV STD_ON
#endif

#if (!defined EBSTUBS_FUNCTION_TRACE_ETHTRCV_GETBAUDRATE)
#define EBSTUBS_FUNCTION_TRACE_ETHTRCV_GETBAUDRATE EBSTUBS_FUNCTION_TRACE_ETHTRCV
#endif

#if (!defined EBSTUBS_FUNCTION_TRACE_ETHTRCV_GETDUPLEXMODE)
#define EBSTUBS_FUNCTION_TRACE_ETHTRCV_GETDUPLEXMODE EBSTUBS_FUNCTION_TRACE_ETHTRCV
#endif

#if (!defined EBSTUBS_FUNCTION_TRACE_ETHTRCV_GETLINKSTATE)
#define EBSTUBS_FUNCTION_TRACE_ETHTRCV_GETLINKSTATE EBSTUBS_FUNCTION_TRACE_ETHTRCV
#endif

#if (!defined EBSTUBS_FUNCTION_TRACE_ETHTRCV_GETTRANSCEIVERMODE)
#define EBSTUBS_FUNCTION_TRACE_ETHTRCV_GETTRANSCEIVERMODE EBSTUBS_FUNCTION_TRACE_ETHTRCV
#endif

#if (!defined EBSTUBS_FUNCTION_TRACE_ETHTRCV_GETVERSIONINFO)
#define EBSTUBS_FUNCTION_TRACE_ETHTRCV_GETVERSIONINFO EBSTUBS_FUNCTION_TRACE_ETHTRCV
#endif

#if (!defined EBSTUBS_FUNCTION_TRACE_ETHTRCV_INIT)
#define EBSTUBS_FUNCTION_TRACE_ETHTRCV_INIT EBSTUBS_FUNCTION_TRACE_ETHTRCV
#endif

#if (!defined EBSTUBS_FUNCTION_TRACE_ETHTRCV_SETTRANSCEIVERMODE)
#define EBSTUBS_FUNCTION_TRACE_ETHTRCV_SETTRANSCEIVERMODE EBSTUBS_FUNCTION_TRACE_ETHTRCV
#endif

#if (!defined EBSTUBS_FUNCTION_TRACE_ETHTRCV_STARTAUTONEGOTIATION)
#define EBSTUBS_FUNCTION_TRACE_ETHTRCV_STARTAUTONEGOTIATION EBSTUBS_FUNCTION_TRACE_ETHTRCV
#endif

#if (!defined EBSTUBS_FUNCTION_TRACE_ETHTRCV_TRANSCEIVERINIT)
#define EBSTUBS_FUNCTION_TRACE_ETHTRCV_TRANSCEIVERINIT EBSTUBS_FUNCTION_TRACE_ETHTRCV
#endif

#if (EBSTUBS_FUNCTION_TRACE == STD_ON)
#include <EBStubs_Trace.h>
#endif

/*==[Declaration of functions with internal linkage]==========================*/

/*==[Constants with internal linkage]=========================================*/

/*==[Variables with internal linkage]=========================================*/

/*==[Constants with external linkage]=========================================*/

/*==[Variables with external linkage]=========================================*/

#define EBSTUBS_START_SEC_VAR_UNSPECIFIED
#include <MemMap.h>

#if (EBSTUBS_FUNCENABLED_ETHTRCV_GETTRANSCEIVERMODE == STD_ON)
VAR(EthTrcv_GetTransceiverMode_StubType, EBSTUBS_VAR)
   EthTrcv_GetTransceiverMode_Stub;
#endif

#if (EBSTUBS_FUNCENABLED_ETHTRCV_INIT == STD_ON)
VAR(EthTrcv_Init_StubType, EBSTUBS_VAR)
   EthTrcv_Init_Stub;
#endif

#if (EBSTUBS_FUNCENABLED_ETHTRCV_GETDUPLEXMODE == STD_ON)
VAR(EthTrcv_GetDuplexMode_StubType, EBSTUBS_VAR)
   EthTrcv_GetDuplexMode_Stub;
#endif

#if (EBSTUBS_FUNCENABLED_ETHTRCV_GETLINKSTATE == STD_ON)
VAR(EthTrcv_GetLinkState_StubType, EBSTUBS_VAR)
   EthTrcv_GetLinkState_Stub;
#endif

#if (EBSTUBS_FUNCENABLED_ETHTRCV_GETBAUDRATE == STD_ON)
VAR(EthTrcv_GetBaudRate_StubType, EBSTUBS_VAR)
   EthTrcv_GetBaudRate_Stub;
#endif

#if (EBSTUBS_FUNCENABLED_ETHTRCV_TRANSCEIVERINIT == STD_ON)
VAR(EthTrcv_TransceiverInit_StubType, EBSTUBS_VAR)
   EthTrcv_TransceiverInit_Stub;
#endif

#if (EBSTUBS_FUNCENABLED_ETHTRCV_GETVERSIONINFO == STD_ON)
VAR(EthTrcv_GetVersionInfo_StubType, EBSTUBS_VAR)
   EthTrcv_GetVersionInfo_Stub;
#endif

#if (EBSTUBS_FUNCENABLED_ETHTRCV_SETTRANSCEIVERMODE == STD_ON)
VAR(EthTrcv_SetTransceiverMode_StubType, EBSTUBS_VAR)
   EthTrcv_SetTransceiverMode_Stub;
#endif

#if (EBSTUBS_FUNCENABLED_ETHTRCV_STARTAUTONEGOTIATION == STD_ON)
VAR(EthTrcv_StartAutoNegotiation_StubType, EBSTUBS_VAR)
   EthTrcv_StartAutoNegotiation_Stub;
#endif

#define EBSTUBS_STOP_SEC_VAR_UNSPECIFIED
#include <MemMap.h>

/*==[Definition of functions with external linkage]===========================*/

#define EBSTUBS_START_SEC_CODE
#include <MemMap.h>

#if (EBSTUBS_FUNCENABLED_ETHTRCV_GETBAUDRATE == STD_ON)
FUNC(Std_ReturnType, EBSTUBS_CODE) EthTrcv_GetBaudRate
(
  uint8 TrcvIdx,
  EthTrcv_BaudRateType BaudRatePtr
)
{
  Std_ReturnType result;

#if (EBSTUBS_MAX_CALLS_ETHTRCV_GETBAUDRATE > 1)
  uint32 count = EthTrcv_GetBaudRate_Stub.Count;
#endif

  result = EthTrcv_GetBaudRate_Stub.RetVal;
  EthTrcv_GetBaudRate_Stub.TrcvIdx = TrcvIdx;
  EthTrcv_GetBaudRate_Stub.BaudRatePtr = BaudRatePtr;

#if (EBSTUBS_MAX_CALLS_ETHTRCV_GETBAUDRATE > 1)
  if( count < EBSTUBS_MAX_CALLS_ETHTRCV_GETBAUDRATE )
  {
    EthTrcv_GetBaudRate_Stub.TrcvIdx_Ary[count] = TrcvIdx;
    EthTrcv_GetBaudRate_Stub.BaudRatePtr_Ary[count] = BaudRatePtr;
    result = EthTrcv_GetBaudRate_Stub.RetVal_Ary[count];
  }
#endif

  if ( EthTrcv_GetBaudRate_Stub.Callout != NULL_PTR )
  {
    result = EthTrcv_GetBaudRate_Stub.Callout(TrcvIdx, BaudRatePtr);
  }
  else
  {

#if (EBSTUBS_MAX_CALLS_ETHTRCV_GETBAUDRATE > 1)
    if( count < EBSTUBS_MAX_CALLS_ETHTRCV_GETBAUDRATE )
    {
    }
#endif
  }

  EthTrcv_GetBaudRate_Stub.Count++;

#if ((EBSTUBS_FUNCTION_TRACE == STD_ON) && (EBSTUBS_FUNCTION_TRACE_ETHTRCV_GETBAUDRATE == STD_ON))
  EBSTUBS_TRACE_PUSH(EthTrcv_GetBaudRate);
#endif

  return result;
}
#endif

#if (EBSTUBS_FUNCENABLED_ETHTRCV_GETDUPLEXMODE == STD_ON)
FUNC(Std_ReturnType, EBSTUBS_CODE) EthTrcv_GetDuplexMode
(
  uint8 TrcvIdx,
  P2VAR(EthTrcv_DuplexModeType, AUTOMATIC, EBSTUBS_APPL_DATA) DuplexModePtr
)
{
  Std_ReturnType result;

#if (EBSTUBS_MAX_CALLS_ETHTRCV_GETDUPLEXMODE > 1)
  uint32 count = EthTrcv_GetDuplexMode_Stub.Count;
#endif

  result = EthTrcv_GetDuplexMode_Stub.RetVal;
  EthTrcv_GetDuplexMode_Stub.TrcvIdx = TrcvIdx;
  *DuplexModePtr = EthTrcv_GetDuplexMode_Stub.DuplexModePtr_Out;

#if (EBSTUBS_MAX_CALLS_ETHTRCV_GETDUPLEXMODE > 1)
  if( count < EBSTUBS_MAX_CALLS_ETHTRCV_GETDUPLEXMODE )
  {
    EthTrcv_GetDuplexMode_Stub.TrcvIdx_Ary[count] = TrcvIdx;
    *DuplexModePtr = EthTrcv_GetDuplexMode_Stub.DuplexModePtr_Out_Ary[count];
    result = EthTrcv_GetDuplexMode_Stub.RetVal_Ary[count];
  }
#endif

  if ( EthTrcv_GetDuplexMode_Stub.Callout != NULL_PTR )
  {
    result = EthTrcv_GetDuplexMode_Stub.Callout(TrcvIdx, DuplexModePtr);
  }
  else
  {

#if (EBSTUBS_MAX_CALLS_ETHTRCV_GETDUPLEXMODE > 1)
    if( count < EBSTUBS_MAX_CALLS_ETHTRCV_GETDUPLEXMODE )
    {
    }
#endif
  }

  EthTrcv_GetDuplexMode_Stub.Count++;

#if ((EBSTUBS_FUNCTION_TRACE == STD_ON) && (EBSTUBS_FUNCTION_TRACE_ETHTRCV_GETDUPLEXMODE == STD_ON))
  EBSTUBS_TRACE_PUSH(EthTrcv_GetDuplexMode);
#endif

  return result;
}
#endif

#if (EBSTUBS_FUNCENABLED_ETHTRCV_GETLINKSTATE == STD_ON)
FUNC(Std_ReturnType, EBSTUBS_CODE) EthTrcv_GetLinkState
(
  uint8 TrcvIdx,
  P2VAR(EthTrcv_LinkStateType, AUTOMATIC, EBSTUBS_APPL_DATA) LinkStatePtr
)
{
  Std_ReturnType result;

#if (EBSTUBS_MAX_CALLS_ETHTRCV_GETLINKSTATE > 1)
  uint32 count = EthTrcv_GetLinkState_Stub.Count;
#endif

  result = EthTrcv_GetLinkState_Stub.RetVal;
  EthTrcv_GetLinkState_Stub.TrcvIdx = TrcvIdx;
  *LinkStatePtr = EthTrcv_GetLinkState_Stub.LinkStatePtr_Out;

#if (EBSTUBS_MAX_CALLS_ETHTRCV_GETLINKSTATE > 1)
  if( count < EBSTUBS_MAX_CALLS_ETHTRCV_GETLINKSTATE )
  {
    EthTrcv_GetLinkState_Stub.TrcvIdx_Ary[count] = TrcvIdx;
    *LinkStatePtr = EthTrcv_GetLinkState_Stub.LinkStatePtr_Out_Ary[count];
    result = EthTrcv_GetLinkState_Stub.RetVal_Ary[count];
  }
#endif

  if ( EthTrcv_GetLinkState_Stub.Callout != NULL_PTR )
  {
    result = EthTrcv_GetLinkState_Stub.Callout(TrcvIdx, LinkStatePtr);
  }
  else
  {

#if (EBSTUBS_MAX_CALLS_ETHTRCV_GETLINKSTATE > 1)
    if( count < EBSTUBS_MAX_CALLS_ETHTRCV_GETLINKSTATE )
    {
    }
#endif
  }

  EthTrcv_GetLinkState_Stub.Count++;

#if ((EBSTUBS_FUNCTION_TRACE == STD_ON) && (EBSTUBS_FUNCTION_TRACE_ETHTRCV_GETLINKSTATE == STD_ON))
  EBSTUBS_TRACE_PUSH(EthTrcv_GetLinkState);
#endif

  return result;
}
#endif

#if (EBSTUBS_FUNCENABLED_ETHTRCV_GETTRANSCEIVERMODE == STD_ON)
FUNC(Std_ReturnType, EBSTUBS_CODE) EthTrcv_GetTransceiverMode
(
  uint8 TrcvIdx,
  P2VAR(EthTrcv_ModeType, AUTOMATIC, EBSTUBS_APPL_DATA) TrcvModePtr
)
{
  Std_ReturnType result;

#if (EBSTUBS_MAX_CALLS_ETHTRCV_GETTRANSCEIVERMODE > 1)
  uint32 count = EthTrcv_GetTransceiverMode_Stub.Count;
#endif

  result = EthTrcv_GetTransceiverMode_Stub.RetVal;
  EthTrcv_GetTransceiverMode_Stub.TrcvIdx = TrcvIdx;
  *TrcvModePtr = EthTrcv_GetTransceiverMode_Stub.TrcvModePtr_Out;

#if (EBSTUBS_MAX_CALLS_ETHTRCV_GETTRANSCEIVERMODE > 1)
  if( count < EBSTUBS_MAX_CALLS_ETHTRCV_GETTRANSCEIVERMODE )
  {
    EthTrcv_GetTransceiverMode_Stub.TrcvIdx_Ary[count] = TrcvIdx;
    *TrcvModePtr = EthTrcv_GetTransceiverMode_Stub.TrcvModePtr_Out_Ary[count];
    result = EthTrcv_GetTransceiverMode_Stub.RetVal_Ary[count];
  }
#endif

  if ( EthTrcv_GetTransceiverMode_Stub.Callout != NULL_PTR )
  {
    result = EthTrcv_GetTransceiverMode_Stub.Callout(TrcvIdx, TrcvModePtr);
  }
  else
  {

#if (EBSTUBS_MAX_CALLS_ETHTRCV_GETTRANSCEIVERMODE > 1)
    if( count < EBSTUBS_MAX_CALLS_ETHTRCV_GETTRANSCEIVERMODE )
    {
    }
#endif
  }

  EthTrcv_GetTransceiverMode_Stub.Count++;

#if ((EBSTUBS_FUNCTION_TRACE == STD_ON) && (EBSTUBS_FUNCTION_TRACE_ETHTRCV_GETTRANSCEIVERMODE == STD_ON))
  EBSTUBS_TRACE_PUSH(EthTrcv_GetTransceiverMode);
#endif

  return result;
}
#endif

#if (EBSTUBS_FUNCENABLED_ETHTRCV_GETVERSIONINFO == STD_ON)
FUNC(void, EBSTUBS_CODE) EthTrcv_GetVersionInfo
(
  P2VAR(Std_VersionInfoType, AUTOMATIC, EBSTUBS_APPL_DATA) VersionInfoPtr
)
{

#if (EBSTUBS_MAX_CALLS_ETHTRCV_GETVERSIONINFO > 1)
  uint32 count = EthTrcv_GetVersionInfo_Stub.Count;
#endif

  *VersionInfoPtr = EthTrcv_GetVersionInfo_Stub.VersionInfoPtr_Out;

#if (EBSTUBS_MAX_CALLS_ETHTRCV_GETVERSIONINFO > 1)
  if( count < EBSTUBS_MAX_CALLS_ETHTRCV_GETVERSIONINFO )
  {
    *VersionInfoPtr = EthTrcv_GetVersionInfo_Stub.VersionInfoPtr_Out_Ary[count];
  }
#endif

  if ( EthTrcv_GetVersionInfo_Stub.Callout != NULL_PTR )
  {
    EthTrcv_GetVersionInfo_Stub.Callout(VersionInfoPtr);
  }
  else
  {

#if (EBSTUBS_MAX_CALLS_ETHTRCV_GETVERSIONINFO > 1)
    if( count < EBSTUBS_MAX_CALLS_ETHTRCV_GETVERSIONINFO )
    {
    }
#endif
  }

  EthTrcv_GetVersionInfo_Stub.Count++;

#if ((EBSTUBS_FUNCTION_TRACE == STD_ON) && (EBSTUBS_FUNCTION_TRACE_ETHTRCV_GETVERSIONINFO == STD_ON))
  EBSTUBS_TRACE_PUSH(EthTrcv_GetVersionInfo);
#endif
}
#endif

#if (EBSTUBS_FUNCENABLED_ETHTRCV_INIT == STD_ON)
FUNC(void, EBSTUBS_CODE) EthTrcv_Init
(
  P2CONST(EthTrcv_ConfigType, AUTOMATIC, EBSTUBS_APPL_CONST) CfgPtr
)
{

#if (EBSTUBS_MAX_CALLS_ETHTRCV_INIT > 1)
  uint32 count = EthTrcv_Init_Stub.Count;
#endif

  EthTrcv_Init_Stub.CfgPtr = CfgPtr;

#if (EBSTUBS_MAX_CALLS_ETHTRCV_INIT > 1)
  if( count < EBSTUBS_MAX_CALLS_ETHTRCV_INIT )
  {
    EthTrcv_Init_Stub.CfgPtr_Ary[count] = CfgPtr;
  }
#endif

  if ( EthTrcv_Init_Stub.Callout != NULL_PTR )
  {
    EthTrcv_Init_Stub.Callout(CfgPtr);
  }
  else
  {

#if (EBSTUBS_MAX_CALLS_ETHTRCV_INIT > 1)
    if( count < EBSTUBS_MAX_CALLS_ETHTRCV_INIT )
    {
    }
#endif
  }

  EthTrcv_Init_Stub.Count++;

#if ((EBSTUBS_FUNCTION_TRACE == STD_ON) && (EBSTUBS_FUNCTION_TRACE_ETHTRCV_INIT == STD_ON))
  EBSTUBS_TRACE_PUSH(EthTrcv_Init);
#endif
}
#endif

#if (EBSTUBS_FUNCENABLED_ETHTRCV_SETTRANSCEIVERMODE == STD_ON)
FUNC(Std_ReturnType, EBSTUBS_CODE) EthTrcv_SetTransceiverMode
(
  uint8 TrcvIdx,
  EthTrcv_ModeType CtrlMode
)
{
  Std_ReturnType result;

#if (EBSTUBS_MAX_CALLS_ETHTRCV_SETTRANSCEIVERMODE > 1)
  uint32 count = EthTrcv_SetTransceiverMode_Stub.Count;
#endif

  result = EthTrcv_SetTransceiverMode_Stub.RetVal;
  EthTrcv_SetTransceiverMode_Stub.TrcvIdx = TrcvIdx;
  EthTrcv_SetTransceiverMode_Stub.CtrlMode = CtrlMode;

#if (EBSTUBS_MAX_CALLS_ETHTRCV_SETTRANSCEIVERMODE > 1)
  if( count < EBSTUBS_MAX_CALLS_ETHTRCV_SETTRANSCEIVERMODE )
  {
    EthTrcv_SetTransceiverMode_Stub.TrcvIdx_Ary[count] = TrcvIdx;
    EthTrcv_SetTransceiverMode_Stub.CtrlMode_Ary[count] = CtrlMode;
    result = EthTrcv_SetTransceiverMode_Stub.RetVal_Ary[count];
  }
#endif

  if ( EthTrcv_SetTransceiverMode_Stub.Callout != NULL_PTR )
  {
    result = EthTrcv_SetTransceiverMode_Stub.Callout(TrcvIdx, CtrlMode);
  }
  else
  {

#if (EBSTUBS_MAX_CALLS_ETHTRCV_SETTRANSCEIVERMODE > 1)
    if( count < EBSTUBS_MAX_CALLS_ETHTRCV_SETTRANSCEIVERMODE )
    {
    }
#endif
  }

  EthTrcv_SetTransceiverMode_Stub.Count++;

#if ((EBSTUBS_FUNCTION_TRACE == STD_ON) && (EBSTUBS_FUNCTION_TRACE_ETHTRCV_SETTRANSCEIVERMODE == STD_ON))
  EBSTUBS_TRACE_PUSH(EthTrcv_SetTransceiverMode);
#endif

  return result;
}
#endif

#if (EBSTUBS_FUNCENABLED_ETHTRCV_STARTAUTONEGOTIATION == STD_ON)
FUNC(Std_ReturnType, EBSTUBS_CODE) EthTrcv_StartAutoNegotiation
(
  uint8 TrcvIdx
)
{
  Std_ReturnType result;

#if (EBSTUBS_MAX_CALLS_ETHTRCV_STARTAUTONEGOTIATION > 1)
  uint32 count = EthTrcv_StartAutoNegotiation_Stub.Count;
#endif

  result = EthTrcv_StartAutoNegotiation_Stub.RetVal;
  EthTrcv_StartAutoNegotiation_Stub.TrcvIdx = TrcvIdx;

#if (EBSTUBS_MAX_CALLS_ETHTRCV_STARTAUTONEGOTIATION > 1)
  if( count < EBSTUBS_MAX_CALLS_ETHTRCV_STARTAUTONEGOTIATION )
  {
    EthTrcv_StartAutoNegotiation_Stub.TrcvIdx_Ary[count] = TrcvIdx;
    result = EthTrcv_StartAutoNegotiation_Stub.RetVal_Ary[count];
  }
#endif

  if ( EthTrcv_StartAutoNegotiation_Stub.Callout != NULL_PTR )
  {
    result = EthTrcv_StartAutoNegotiation_Stub.Callout(TrcvIdx);
  }
  else
  {

#if (EBSTUBS_MAX_CALLS_ETHTRCV_STARTAUTONEGOTIATION > 1)
    if( count < EBSTUBS_MAX_CALLS_ETHTRCV_STARTAUTONEGOTIATION )
    {
    }
#endif
  }

  EthTrcv_StartAutoNegotiation_Stub.Count++;

#if ((EBSTUBS_FUNCTION_TRACE == STD_ON) && (EBSTUBS_FUNCTION_TRACE_ETHTRCV_STARTAUTONEGOTIATION == STD_ON))
  EBSTUBS_TRACE_PUSH(EthTrcv_StartAutoNegotiation);
#endif

  return result;
}
#endif

#if (EBSTUBS_FUNCENABLED_ETHTRCV_TRANSCEIVERINIT == STD_ON)
FUNC(Std_ReturnType, EBSTUBS_CODE) EthTrcv_TransceiverInit
(
  uint8 TrcvIdx,
  uint8 CfgIdx
)
{
  Std_ReturnType result;

#if (EBSTUBS_MAX_CALLS_ETHTRCV_TRANSCEIVERINIT > 1)
  uint32 count = EthTrcv_TransceiverInit_Stub.Count;
#endif

  result = EthTrcv_TransceiverInit_Stub.RetVal;
  EthTrcv_TransceiverInit_Stub.TrcvIdx = TrcvIdx;
  EthTrcv_TransceiverInit_Stub.CfgIdx = CfgIdx;

#if (EBSTUBS_MAX_CALLS_ETHTRCV_TRANSCEIVERINIT > 1)
  if( count < EBSTUBS_MAX_CALLS_ETHTRCV_TRANSCEIVERINIT )
  {
    EthTrcv_TransceiverInit_Stub.TrcvIdx_Ary[count] = TrcvIdx;
    EthTrcv_TransceiverInit_Stub.CfgIdx_Ary[count] = CfgIdx;
    result = EthTrcv_TransceiverInit_Stub.RetVal_Ary[count];
  }
#endif

  if ( EthTrcv_TransceiverInit_Stub.Callout != NULL_PTR )
  {
    result = EthTrcv_TransceiverInit_Stub.Callout(TrcvIdx, CfgIdx);
  }
  else
  {

#if (EBSTUBS_MAX_CALLS_ETHTRCV_TRANSCEIVERINIT > 1)
    if( count < EBSTUBS_MAX_CALLS_ETHTRCV_TRANSCEIVERINIT )
    {
    }
#endif
  }

  EthTrcv_TransceiverInit_Stub.Count++;

#if ((EBSTUBS_FUNCTION_TRACE == STD_ON) && (EBSTUBS_FUNCTION_TRACE_ETHTRCV_TRANSCEIVERINIT == STD_ON))
  EBSTUBS_TRACE_PUSH(EthTrcv_TransceiverInit);
#endif

  return result;
}
#endif

#define EBSTUBS_STOP_SEC_CODE
#include <MemMap.h>

/*==[Definition of functions with internal linkage]===========================*/

