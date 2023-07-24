/* --------{ EB Automotive C Source File }-------- */

#if (!defined ETHTRCV_H)
#define ETHTRCV_H

/*==[Includes]================================================================*/

#include <EthTrcv_StubCfg.h>
#include <EthTrcv_Types.h>

/*==[Macros]==================================================================*/

/* Configuration macros */
#if (!defined EBSTUBS_MAX_CALLS_ETHTRCV)
#define EBSTUBS_MAX_CALLS_ETHTRCV 1U
#endif

#if (!defined EBSTUBS_MAX_CALLS_ETHTRCV_GETBAUDRATE)
#define EBSTUBS_MAX_CALLS_ETHTRCV_GETBAUDRATE EBSTUBS_MAX_CALLS_ETHTRCV
#endif

#if (!defined EBSTUBS_MAX_CALLS_ETHTRCV_GETDUPLEXMODE)
#define EBSTUBS_MAX_CALLS_ETHTRCV_GETDUPLEXMODE EBSTUBS_MAX_CALLS_ETHTRCV
#endif

#if (!defined EBSTUBS_MAX_CALLS_ETHTRCV_GETLINKSTATE)
#define EBSTUBS_MAX_CALLS_ETHTRCV_GETLINKSTATE EBSTUBS_MAX_CALLS_ETHTRCV
#endif

#if (!defined EBSTUBS_MAX_CALLS_ETHTRCV_GETTRANSCEIVERMODE)
#define EBSTUBS_MAX_CALLS_ETHTRCV_GETTRANSCEIVERMODE EBSTUBS_MAX_CALLS_ETHTRCV
#endif

#if (!defined EBSTUBS_MAX_CALLS_ETHTRCV_GETVERSIONINFO)
#define EBSTUBS_MAX_CALLS_ETHTRCV_GETVERSIONINFO EBSTUBS_MAX_CALLS_ETHTRCV
#endif

#if (!defined EBSTUBS_MAX_CALLS_ETHTRCV_INIT)
#define EBSTUBS_MAX_CALLS_ETHTRCV_INIT EBSTUBS_MAX_CALLS_ETHTRCV
#endif

#if (!defined EBSTUBS_MAX_CALLS_ETHTRCV_SETTRANSCEIVERMODE)
#define EBSTUBS_MAX_CALLS_ETHTRCV_SETTRANSCEIVERMODE EBSTUBS_MAX_CALLS_ETHTRCV
#endif

#if (!defined EBSTUBS_MAX_CALLS_ETHTRCV_STARTAUTONEGOTIATION)
#define EBSTUBS_MAX_CALLS_ETHTRCV_STARTAUTONEGOTIATION EBSTUBS_MAX_CALLS_ETHTRCV
#endif

#if (!defined EBSTUBS_MAX_CALLS_ETHTRCV_TRANSCEIVERINIT)
#define EBSTUBS_MAX_CALLS_ETHTRCV_TRANSCEIVERINIT EBSTUBS_MAX_CALLS_ETHTRCV
#endif

#if (!defined EBSTUBS_FUNCENABLED_ETHTRCV)
#define EBSTUBS_FUNCENABLED_ETHTRCV STD_ON
#endif

#if (!defined EBSTUBS_FUNCENABLED_ETHTRCV_GETBAUDRATE)
#define EBSTUBS_FUNCENABLED_ETHTRCV_GETBAUDRATE EBSTUBS_FUNCENABLED_ETHTRCV
#endif

#if (!defined EBSTUBS_FUNCENABLED_ETHTRCV_GETDUPLEXMODE)
#define EBSTUBS_FUNCENABLED_ETHTRCV_GETDUPLEXMODE EBSTUBS_FUNCENABLED_ETHTRCV
#endif

#if (!defined EBSTUBS_FUNCENABLED_ETHTRCV_GETLINKSTATE)
#define EBSTUBS_FUNCENABLED_ETHTRCV_GETLINKSTATE EBSTUBS_FUNCENABLED_ETHTRCV
#endif

#if (!defined EBSTUBS_FUNCENABLED_ETHTRCV_GETTRANSCEIVERMODE)
#define EBSTUBS_FUNCENABLED_ETHTRCV_GETTRANSCEIVERMODE EBSTUBS_FUNCENABLED_ETHTRCV
#endif

#if (!defined EBSTUBS_FUNCENABLED_ETHTRCV_GETVERSIONINFO)
#define EBSTUBS_FUNCENABLED_ETHTRCV_GETVERSIONINFO EBSTUBS_FUNCENABLED_ETHTRCV
#endif

#if (!defined EBSTUBS_FUNCENABLED_ETHTRCV_INIT)
#define EBSTUBS_FUNCENABLED_ETHTRCV_INIT EBSTUBS_FUNCENABLED_ETHTRCV
#endif

#if (!defined EBSTUBS_FUNCENABLED_ETHTRCV_SETTRANSCEIVERMODE)
#define EBSTUBS_FUNCENABLED_ETHTRCV_SETTRANSCEIVERMODE EBSTUBS_FUNCENABLED_ETHTRCV
#endif

#if (!defined EBSTUBS_FUNCENABLED_ETHTRCV_STARTAUTONEGOTIATION)
#define EBSTUBS_FUNCENABLED_ETHTRCV_STARTAUTONEGOTIATION EBSTUBS_FUNCENABLED_ETHTRCV
#endif

#if (!defined EBSTUBS_FUNCENABLED_ETHTRCV_TRANSCEIVERINIT)
#define EBSTUBS_FUNCENABLED_ETHTRCV_TRANSCEIVERINIT EBSTUBS_FUNCENABLED_ETHTRCV
#endif

/* EthTrcv_VersionMacros_Dummy */
#define ETHTRCV_AR_RELEASE_MAJOR_VERSION 4U
#define ETHTRCV_AR_RELEASE_MINOR_VERSION 0U

/*==[Types]===================================================================*/

typedef uint8 EthTrcv_VersionMacros_Dummy;

#if (EBSTUBS_FUNCENABLED_ETHTRCV_GETBAUDRATE == STD_ON)
typedef Std_ReturnType(*EthTrcv_GetBaudRate_CalloutType)
(
   uint8,
   EthTrcv_BaudRateType
);
typedef struct
{
   uint32 Count;
   EthTrcv_GetBaudRate_CalloutType Callout;

#if (EBSTUBS_MAX_CALLS_ETHTRCV_GETBAUDRATE > 1)
    uint8 TrcvIdx_Ary[EBSTUBS_MAX_CALLS_ETHTRCV_GETBAUDRATE];
    EthTrcv_BaudRateType BaudRatePtr_Ary[EBSTUBS_MAX_CALLS_ETHTRCV_GETBAUDRATE];
   Std_ReturnType RetVal_Ary[EBSTUBS_MAX_CALLS_ETHTRCV_GETBAUDRATE];
#endif

    uint8 TrcvIdx;
    EthTrcv_BaudRateType BaudRatePtr;
   Std_ReturnType RetVal;
} EthTrcv_GetBaudRate_StubType;
#endif

#if (EBSTUBS_FUNCENABLED_ETHTRCV_GETDUPLEXMODE == STD_ON)
typedef Std_ReturnType(*EthTrcv_GetDuplexMode_CalloutType)
(
   uint8,
   P2VAR(EthTrcv_DuplexModeType, TYPEDEF, EBSTUBS_APPL_DATA)
);
typedef struct
{
   uint32 Count;
   EthTrcv_GetDuplexMode_CalloutType Callout;

#if (EBSTUBS_MAX_CALLS_ETHTRCV_GETDUPLEXMODE > 1)
    uint8 TrcvIdx_Ary[EBSTUBS_MAX_CALLS_ETHTRCV_GETDUPLEXMODE];
    EthTrcv_DuplexModeType DuplexModePtr_Out_Ary[EBSTUBS_MAX_CALLS_ETHTRCV_GETDUPLEXMODE];
   Std_ReturnType RetVal_Ary[EBSTUBS_MAX_CALLS_ETHTRCV_GETDUPLEXMODE];
#endif

    uint8 TrcvIdx;
    EthTrcv_DuplexModeType DuplexModePtr_Out;
   Std_ReturnType RetVal;
} EthTrcv_GetDuplexMode_StubType;
#endif

#if (EBSTUBS_FUNCENABLED_ETHTRCV_GETLINKSTATE == STD_ON)
typedef Std_ReturnType(*EthTrcv_GetLinkState_CalloutType)
(
   uint8,
   P2VAR(EthTrcv_LinkStateType, TYPEDEF, EBSTUBS_APPL_DATA)
);
typedef struct
{
   uint32 Count;
   EthTrcv_GetLinkState_CalloutType Callout;

#if (EBSTUBS_MAX_CALLS_ETHTRCV_GETLINKSTATE > 1)
    uint8 TrcvIdx_Ary[EBSTUBS_MAX_CALLS_ETHTRCV_GETLINKSTATE];
    EthTrcv_LinkStateType LinkStatePtr_Out_Ary[EBSTUBS_MAX_CALLS_ETHTRCV_GETLINKSTATE];
   Std_ReturnType RetVal_Ary[EBSTUBS_MAX_CALLS_ETHTRCV_GETLINKSTATE];
#endif

    uint8 TrcvIdx;
    EthTrcv_LinkStateType LinkStatePtr_Out;
   Std_ReturnType RetVal;
} EthTrcv_GetLinkState_StubType;
#endif

#if (EBSTUBS_FUNCENABLED_ETHTRCV_GETTRANSCEIVERMODE == STD_ON)
typedef Std_ReturnType(*EthTrcv_GetTransceiverMode_CalloutType)
(
   uint8,
   P2VAR(EthTrcv_ModeType, TYPEDEF, EBSTUBS_APPL_DATA)
);
typedef struct
{
   uint32 Count;
   EthTrcv_GetTransceiverMode_CalloutType Callout;

#if (EBSTUBS_MAX_CALLS_ETHTRCV_GETTRANSCEIVERMODE > 1)
    uint8 TrcvIdx_Ary[EBSTUBS_MAX_CALLS_ETHTRCV_GETTRANSCEIVERMODE];
    EthTrcv_ModeType TrcvModePtr_Out_Ary[EBSTUBS_MAX_CALLS_ETHTRCV_GETTRANSCEIVERMODE];
   Std_ReturnType RetVal_Ary[EBSTUBS_MAX_CALLS_ETHTRCV_GETTRANSCEIVERMODE];
#endif

    uint8 TrcvIdx;
    EthTrcv_ModeType TrcvModePtr_Out;
   Std_ReturnType RetVal;
} EthTrcv_GetTransceiverMode_StubType;
#endif

#if (EBSTUBS_FUNCENABLED_ETHTRCV_GETVERSIONINFO == STD_ON)
typedef void(*EthTrcv_GetVersionInfo_CalloutType)
(
   P2VAR(Std_VersionInfoType, TYPEDEF, EBSTUBS_APPL_DATA)
);
typedef struct
{
   uint32 Count;
   EthTrcv_GetVersionInfo_CalloutType Callout;

#if (EBSTUBS_MAX_CALLS_ETHTRCV_GETVERSIONINFO > 1)
    Std_VersionInfoType VersionInfoPtr_Out_Ary[EBSTUBS_MAX_CALLS_ETHTRCV_GETVERSIONINFO];
#endif

    Std_VersionInfoType VersionInfoPtr_Out;
} EthTrcv_GetVersionInfo_StubType;
#endif

#if (EBSTUBS_FUNCENABLED_ETHTRCV_INIT == STD_ON)
typedef void(*EthTrcv_Init_CalloutType)
(
   P2CONST(EthTrcv_ConfigType, TYPEDEF, EBSTUBS_APPL_CONST)
);
typedef struct
{
   uint32 Count;
   EthTrcv_Init_CalloutType Callout;

#if (EBSTUBS_MAX_CALLS_ETHTRCV_INIT > 1)
    P2CONST(EthTrcv_ConfigType, TYPEDEF, EBSTUBS_APPL_CONST) CfgPtr_Ary[EBSTUBS_MAX_CALLS_ETHTRCV_INIT];
#endif

    P2CONST(EthTrcv_ConfigType, TYPEDEF, EBSTUBS_APPL_CONST) CfgPtr;
} EthTrcv_Init_StubType;
#endif

#if (EBSTUBS_FUNCENABLED_ETHTRCV_SETTRANSCEIVERMODE == STD_ON)
typedef Std_ReturnType(*EthTrcv_SetTransceiverMode_CalloutType)
(
   uint8,
   EthTrcv_ModeType
);
typedef struct
{
   uint32 Count;
   EthTrcv_SetTransceiverMode_CalloutType Callout;

#if (EBSTUBS_MAX_CALLS_ETHTRCV_SETTRANSCEIVERMODE > 1)
    uint8 TrcvIdx_Ary[EBSTUBS_MAX_CALLS_ETHTRCV_SETTRANSCEIVERMODE];
    EthTrcv_ModeType CtrlMode_Ary[EBSTUBS_MAX_CALLS_ETHTRCV_SETTRANSCEIVERMODE];
   Std_ReturnType RetVal_Ary[EBSTUBS_MAX_CALLS_ETHTRCV_SETTRANSCEIVERMODE];
#endif

    uint8 TrcvIdx;
    EthTrcv_ModeType CtrlMode;
   Std_ReturnType RetVal;
} EthTrcv_SetTransceiverMode_StubType;
#endif

#if (EBSTUBS_FUNCENABLED_ETHTRCV_STARTAUTONEGOTIATION == STD_ON)
typedef Std_ReturnType(*EthTrcv_StartAutoNegotiation_CalloutType)
(
   uint8
);
typedef struct
{
   uint32 Count;
   EthTrcv_StartAutoNegotiation_CalloutType Callout;

#if (EBSTUBS_MAX_CALLS_ETHTRCV_STARTAUTONEGOTIATION > 1)
    uint8 TrcvIdx_Ary[EBSTUBS_MAX_CALLS_ETHTRCV_STARTAUTONEGOTIATION];
   Std_ReturnType RetVal_Ary[EBSTUBS_MAX_CALLS_ETHTRCV_STARTAUTONEGOTIATION];
#endif

    uint8 TrcvIdx;
   Std_ReturnType RetVal;
} EthTrcv_StartAutoNegotiation_StubType;
#endif

#if (EBSTUBS_FUNCENABLED_ETHTRCV_TRANSCEIVERINIT == STD_ON)
typedef Std_ReturnType(*EthTrcv_TransceiverInit_CalloutType)
(
   uint8,
   uint8
);
typedef struct
{
   uint32 Count;
   EthTrcv_TransceiverInit_CalloutType Callout;

#if (EBSTUBS_MAX_CALLS_ETHTRCV_TRANSCEIVERINIT > 1)
    uint8 TrcvIdx_Ary[EBSTUBS_MAX_CALLS_ETHTRCV_TRANSCEIVERINIT];
    uint8 CfgIdx_Ary[EBSTUBS_MAX_CALLS_ETHTRCV_TRANSCEIVERINIT];
   Std_ReturnType RetVal_Ary[EBSTUBS_MAX_CALLS_ETHTRCV_TRANSCEIVERINIT];
#endif

    uint8 TrcvIdx;
    uint8 CfgIdx;
   Std_ReturnType RetVal;
} EthTrcv_TransceiverInit_StubType;
#endif

/*==[Declaration of functions with external linkage]==========================*/

#define EBSTUBS_START_SEC_CODE
#include <MemMap.h>

#if (EBSTUBS_FUNCENABLED_ETHTRCV_GETBAUDRATE == STD_ON)
extern FUNC(Std_ReturnType, EBSTUBS_CODE) EthTrcv_GetBaudRate
(
  uint8 TrcvIdx,
  EthTrcv_BaudRateType BaudRatePtr
);
#endif

#if (EBSTUBS_FUNCENABLED_ETHTRCV_GETDUPLEXMODE == STD_ON)
extern FUNC(Std_ReturnType, EBSTUBS_CODE) EthTrcv_GetDuplexMode
(
  uint8 TrcvIdx,
  P2VAR(EthTrcv_DuplexModeType, AUTOMATIC, EBSTUBS_APPL_DATA) DuplexModePtr
);
#endif

#if (EBSTUBS_FUNCENABLED_ETHTRCV_GETLINKSTATE == STD_ON)
extern FUNC(Std_ReturnType, EBSTUBS_CODE) EthTrcv_GetLinkState
(
  uint8 TrcvIdx,
  P2VAR(EthTrcv_LinkStateType, AUTOMATIC, EBSTUBS_APPL_DATA) LinkStatePtr
);
#endif

#if (EBSTUBS_FUNCENABLED_ETHTRCV_GETTRANSCEIVERMODE == STD_ON)
extern FUNC(Std_ReturnType, EBSTUBS_CODE) EthTrcv_GetTransceiverMode
(
  uint8 TrcvIdx,
  P2VAR(EthTrcv_ModeType, AUTOMATIC, EBSTUBS_APPL_DATA) TrcvModePtr
);
#endif

#if (EBSTUBS_FUNCENABLED_ETHTRCV_GETVERSIONINFO == STD_ON)
extern FUNC(void, EBSTUBS_CODE) EthTrcv_GetVersionInfo
(
  P2VAR(Std_VersionInfoType, AUTOMATIC, EBSTUBS_APPL_DATA) VersionInfoPtr
);
#endif

#if (EBSTUBS_FUNCENABLED_ETHTRCV_INIT == STD_ON)
extern FUNC(void, EBSTUBS_CODE) EthTrcv_Init
(
  P2CONST(EthTrcv_ConfigType, AUTOMATIC, EBSTUBS_APPL_CONST) CfgPtr
);
#endif

#if (EBSTUBS_FUNCENABLED_ETHTRCV_SETTRANSCEIVERMODE == STD_ON)
extern FUNC(Std_ReturnType, EBSTUBS_CODE) EthTrcv_SetTransceiverMode
(
  uint8 TrcvIdx,
  EthTrcv_ModeType CtrlMode
);
#endif

#if (EBSTUBS_FUNCENABLED_ETHTRCV_STARTAUTONEGOTIATION == STD_ON)
extern FUNC(Std_ReturnType, EBSTUBS_CODE) EthTrcv_StartAutoNegotiation
(
  uint8 TrcvIdx
);
#endif

#if (EBSTUBS_FUNCENABLED_ETHTRCV_TRANSCEIVERINIT == STD_ON)
extern FUNC(Std_ReturnType, EBSTUBS_CODE) EthTrcv_TransceiverInit
(
  uint8 TrcvIdx,
  uint8 CfgIdx
);
#endif

#define EBSTUBS_STOP_SEC_CODE
#include <MemMap.h>

/*==[Constants with external linkage]=========================================*/

/*==[Variables with external linkage]=========================================*/

#define EBSTUBS_START_SEC_VAR_UNSPECIFIED
#include <MemMap.h>

#if (EBSTUBS_FUNCENABLED_ETHTRCV_GETBAUDRATE == STD_ON)
extern VAR(EthTrcv_GetBaudRate_StubType, EBSTUBS_VAR)
   EthTrcv_GetBaudRate_Stub;
#endif

#if (EBSTUBS_FUNCENABLED_ETHTRCV_GETDUPLEXMODE == STD_ON)
extern VAR(EthTrcv_GetDuplexMode_StubType, EBSTUBS_VAR)
   EthTrcv_GetDuplexMode_Stub;
#endif

#if (EBSTUBS_FUNCENABLED_ETHTRCV_GETLINKSTATE == STD_ON)
extern VAR(EthTrcv_GetLinkState_StubType, EBSTUBS_VAR)
   EthTrcv_GetLinkState_Stub;
#endif

#if (EBSTUBS_FUNCENABLED_ETHTRCV_GETTRANSCEIVERMODE == STD_ON)
extern VAR(EthTrcv_GetTransceiverMode_StubType, EBSTUBS_VAR)
   EthTrcv_GetTransceiverMode_Stub;
#endif

#if (EBSTUBS_FUNCENABLED_ETHTRCV_GETVERSIONINFO == STD_ON)
extern VAR(EthTrcv_GetVersionInfo_StubType, EBSTUBS_VAR)
   EthTrcv_GetVersionInfo_Stub;
#endif

#if (EBSTUBS_FUNCENABLED_ETHTRCV_INIT == STD_ON)
extern VAR(EthTrcv_Init_StubType, EBSTUBS_VAR)
   EthTrcv_Init_Stub;
#endif

#if (EBSTUBS_FUNCENABLED_ETHTRCV_SETTRANSCEIVERMODE == STD_ON)
extern VAR(EthTrcv_SetTransceiverMode_StubType, EBSTUBS_VAR)
   EthTrcv_SetTransceiverMode_Stub;
#endif

#if (EBSTUBS_FUNCENABLED_ETHTRCV_STARTAUTONEGOTIATION == STD_ON)
extern VAR(EthTrcv_StartAutoNegotiation_StubType, EBSTUBS_VAR)
   EthTrcv_StartAutoNegotiation_Stub;
#endif

#if (EBSTUBS_FUNCENABLED_ETHTRCV_TRANSCEIVERINIT == STD_ON)
extern VAR(EthTrcv_TransceiverInit_StubType, EBSTUBS_VAR)
   EthTrcv_TransceiverInit_Stub;
#endif


#define EBSTUBS_STOP_SEC_VAR_UNSPECIFIED
#include <MemMap.h>

/* stub extension header file */
#include <EthTrcv_StubExt.h>

#endif /* !defined ETHTRCV_H */
