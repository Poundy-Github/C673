/* PRQA S 0777 EOF */ /* MD_MSR_Rule5.1 */
/* PRQA S 0779 EOF */ /* MD_MSR_Rule5.2 */

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
#include "CanTrcv_8_Tja1043_Cfg.h"


[!//
[!/* Select MODULE-CONFIGURATION as context-node */!][!//
[!SELECT "(as:stod( 'AURIX2G_Tja1043/EcucDefs/CanTrcv'))"!][!//
[!VAR "CanTrcvConfigSetName" = "'CanTrcvConfigSet'"!][!//
[!//

/**********************************************************************************************************************
  VERSION DEFINES (Adapted with: ESCAN00086365)
**********************************************************************************************************************/
#if (DRVTRANS_CAN_TJA1043_GENTOOL_CFG5_MAJOR_VERSION != 0x03u)
# error "CanTrcv_Tja1043_Cfg.c : Incompatible DRVTRANS_TJA1043_GENTOOL_CFG5_MAJOR_VERSION in generated File!"
#endif

#if (DRVTRANS_CAN_TJA1043_GENTOOL_CFG5_MINOR_VERSION != 0x03u)
# error "CanTrcv_Tja1043_Cfg.c : Incompatible DRVTRANS_TJA1043_GENTOOL_CFG5_MINOR_VERSION in generated File!"
#endif

#if (DRVTRANS_CAN_TJA1043_GENTOOL_CFG5_PATCH_VERSION != 0x00u)
# error "CanTrcv_Tja1043_Cfg.c : Incompatible DRVTRANS_TJA1043_GENTOOL_CFG5_PATCH_VERSION in generated File!"
#endif


[!SELECT "node:ref($CanTrcvConfigSetName)"!][!//
  [!VAR "TotalCanTrcvChannels" = "num:i(0)"!][!//
  [!LOOP "CanTrcvChannel/*"!][!//
    [!VAR "CanTrcvChUsed" = "./CanTrcvChannelUsed"!][!//
      [!IF "$CanTrcvChUsed = 'true'"!][!//
        [!VAR "TotalCanTrcvChannels" = "num:i($TotalCanTrcvChannels + num:i(1))"!][!//
      [!ENDIF!][!//
  [!ENDLOOP!][!//
  [!INDENT "0"!][!//
  /*[cover parentID={152B4BF1-9AF6-4cf8-B4D8-184F7B3C2E77}][/cover]*/
  [!CR!][!//
/**********************************************************************************************************************
  GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CanTrcv_Tja1043_ChannelUsed
**********************************************************************************************************************/
#define CANTRCV_TJA1043_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "CanTrcv_8_Tja1043_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTrcv_Tja1043_ChannelUsedType, CANTRCV_TJA1043_CONST) CanTrcv_Tja1043_ChannelUsed[CANTRCV_TJA1043_MAX_CHANNEL] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  [!INDENT "2"!][!//
    [!VAR "ChannelCount1" = "num:i(0)"!][!//
    [!LOOP "node:order(CanTrcvChannel/*, './CanTrcvChannelId')"!][!//
      [!VAR "CanTrcv_ChannelId" = "./CanTrcvChannelId"!]
      [!VAR "CanTrcvChUsed" = "./CanTrcvChannelUsed"!][!//
      [!IF "$CanTrcvChUsed = 'true'"!][!//
      [!VAR "ChannelCount1" = "num:i($ChannelCount1 + num:i(1))"!][!//
      TRUE
      [!ELSE!][!//
      FALSE
      [!ENDIF!][!//
      [!IF "$ChannelCount1 < num:i($TotalCanTrcvChannels)"!],[!CR!][!ENDIF!][!//
    [!ENDLOOP!][!//
    [!CR!][!//
  [!ENDINDENT!][!//
};
#define CANTRCV_TJA1043_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "CanTrcv_8_Tja1043_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTrcv_Tja1043_DioConfiguration
**********************************************************************************************************************/
/** 
  \var    CanTrcv_Tja1043_DioConfiguration
  \details
  Element    Description
  PinEN  
  PinERR 
  PinRXD 
  PinSTB 
*/ 
#define CANTRCV_TJA1043_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTrcv_8_Tja1043_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTrcv_Tja1043_DioConfigurationType, CANTRCV_TJA1043_CONST) CanTrcv_Tja1043_DioConfiguration[CANTRCV_TJA1043_MAX_CHANNEL] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    PinEN                       PinERR                       PinRXD                       PinSTB                      */
  [!INDENT "2"!][!//
    [!VAR "ChannelCount1" = "num:i(0)"!][!//
    [!LOOP "node:order(CanTrcvChannel/*, './CanTrcvChannelId')"!][!//
      [!VAR "CanTrcv_ChannelId" = "./CanTrcvChannelId"!]
      [!VAR "CanTrcvChUsed" = "./CanTrcvChannelUsed"!][!//
      [!IF "$CanTrcvChUsed = 'true'"!][!//
        [!VAR "ChannelCount1" = "num:i($ChannelCount1 + num:i(1))"!][!//
        {
        [!LOOP "./CanTrcvAccess/CanTrcvDioChannelAccess/*"!][!//
        [!IF "CanTrcvHardwareInterfaceName1 = 'STB'"!][!//
            [!VAR "DioChannelName" = "node:name(node:ref(CanTrcvDioSymNameRef1))"!][!//
            DioConf_DioChannel_[!"$DioChannelName"!],
        [!ENDIF!][!//
        [!IF "CanTrcvHardwareInterfaceName2 = 'EN'"!][!//
            [!VAR "DioChannelName" = "node:name(node:ref(CanTrcvDioSymNameRef2))"!][!//
            DioConf_DioChannel_[!"$DioChannelName"!],
        [!ENDIF!][!//
        [!IF "CanTrcvHardwareInterfaceName3 = 'ERR'"!][!//
            [!VAR "DioChannelName" = "node:name(node:ref(CanTrcvDioSymNameRef3))"!][!//
            DioConf_DioChannel_[!"$DioChannelName"!],
        [!ENDIF!][!//
        [!IF "CanTrcvHardwareInterfaceName4 = 'CANRXD'"!][!//
            [!VAR "DioChannelName" = "node:name(node:ref(CanTrcvDioSymNameRef4))"!][!//
            DioConf_DioChannel_[!"$DioChannelName"!]
        [!ENDIF!][!//
        [!ENDLOOP!][!//
        }[!IF "$ChannelCount1 < num:i($TotalCanTrcvChannels)"!],[!CR!][!ENDIF!][!//
      [!ENDIF!][!//
    [!ENDLOOP!][!//
    [!CR!][!//
  [!ENDINDENT!][!//
};
#define CANTRCV_TJA1043_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTrcv_8_Tja1043_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTrcv_Tja1043_Hw_VariantGroup
**********************************************************************************************************************/
#define CANTRCV_TJA1043_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "CanTrcv_8_Tja1043_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTrcv_Tja1043_Hw_VariantGroupType, CANTRCV_TJA1043_CONST) CanTrcv_Tja1043_Hw_VariantGroup[CANTRCV_TJA1043_MAX_CHANNEL] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     Hw_VariantGroup      Comment */
  /*     0 */            0x00u   /* [Tja1043 Reference Group] */
};
#define CANTRCV_TJA1043_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "CanTrcv_8_Tja1043_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTrcv_Tja1043_WakeupByBusUsed
**********************************************************************************************************************/
#define CANTRCV_TJA1043_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "CanTrcv_8_Tja1043_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTrcv_Tja1043_WakeupByBusUsedType, CANTRCV_TJA1043_CONST) CanTrcv_Tja1043_WakeupByBusUsed[CANTRCV_TJA1043_MAX_CHANNEL] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     WakeupByBusUsed  */
  [!INDENT "2"!][!//
    [!VAR "ChannelCount1" = "num:i(0)"!][!//
    [!LOOP "node:order(CanTrcvChannel/*, './CanTrcvChannelId')"!][!//
      [!VAR "CanTrcv_ChannelId" = "./CanTrcvChannelId"!]
      [!VAR "CanTrcvChUsed" = "./CanTrcvChannelUsed"!][!//
      [!IF "$CanTrcvChUsed = 'true'"!][!//
      [!VAR "ChannelCount1" = "num:i($ChannelCount1 + num:i(1))"!][!//
        [!IF "./CanTrcvWakeupByBusUsed = 'true'"!][!//
        TRUE
        [!ELSE!][!//
        FALSE
        [!ENDIF!][!//
      [!ENDIF!][!//
      [!IF "$ChannelCount1 < num:i($TotalCanTrcvChannels)"!],[!CR!][!ENDIF!][!//
    [!ENDLOOP!][!//
    [!CR!][!//
  [!ENDINDENT!][!//
};
#define CANTRCV_TJA1043_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "CanTrcv_8_Tja1043_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTrcv_Tja1043_WakeupSource
**********************************************************************************************************************/
#define CANTRCV_TJA1043_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "CanTrcv_8_Tja1043_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTrcv_Tja1043_WakeupSourceType, CANTRCV_TJA1043_CONST) CanTrcv_Tja1043_WakeupSource[CANTRCV_TJA1043_MAX_CHANNEL] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     WakeupSource  */
  [!INDENT "2"!][!//
    [!VAR "ChannelCount1" = "num:i(0)"!][!//
    [!LOOP "node:order(CanTrcvChannel/*, './CanTrcvChannelId')"!][!//
      [!VAR "CanTrcv_ChannelId" = "./CanTrcvChannelId"!]
      [!VAR "CanTrcvChUsed" = "./CanTrcvChannelUsed"!][!//
      [!IF "$CanTrcvChUsed = 'true'"!][!//
      [!VAR "ChannelCount1" = "num:i($ChannelCount1 + num:i(1))"!][!//
        [!IF "./CanTrcvWakeupByBusUsed = 'true'"!][!//
          [!IF "node:refexists(./CanTrcvWakeupSourceRef/*[1]) ='true'"!][!//
            [!"node:ref(./CanTrcvWakeupSourceRef/*[1])/EcuMWakeupSourceId"!]U,
          [!ELSE!][!//
            [!ERROR!][!//
              CanTrcv_Tja1043 Code Generator: In CanTransceiver Channel_[!"./CanTrcvChannelId "!],If CanTrcvWakeupByBusUsed parameter is enabled, then CanTrcvWakeupSourceRef parameter must be configured.
            [!ENDERROR!][!//
          [!ENDIF!]
        [!ELSE!][!//
          0x00u
        [!ENDIF!][!//
      [!ENDIF!][!//
      [!IF "$ChannelCount1 < num:i($TotalCanTrcvChannels)"!],[!CR!][!ENDIF!][!//
    [!ENDLOOP!][!//
    [!CR!][!//
  [!ENDINDENT!][!//
};
#define CANTRCV_TJA1043_STOP_SEC_CONST_BIT
/*lint -save -esym(961, 19.1) */
#include "CanTrcv_8_Tja1043_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

#define CANTRCV_TJA1043_START_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "CanTrcv_8_Tja1043_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
#if (CANTRCV_TJA1043_DEM_REPORT_SUPPORT == STD_ON)
CONST(Dem_EventIdType, CANTRCV_TJA1043_CONST) CanTrcv_TJA1043_DemIdList[CANTRCV_TJA1043_MAX_CHANNEL][2] = 
{
  [!INDENT "2"!][!//
    [!VAR "ChannelCount1" = "num:i(0)"!][!//
    [!LOOP "node:order(CanTrcvChannel/*, './CanTrcvChannelId')"!][!//
      [!VAR "CanTrcv_ChannelId" = "./CanTrcvChannelId"!]
      [!VAR "CanTrcvChUsed" = "./CanTrcvChannelUsed"!][!//
      [!IF "$CanTrcvChUsed = 'true'"!][!//
      [!VAR "ChannelCount1" = "num:i($ChannelCount1 + num:i(1))"!][!//
        [!IF "./CanTrcvDemReportSupport = 'true'"!][!//
          [!IF "node:refexists(./CanTrcvDemEventParameterRefs/CanTrcvDemEventParameterRefs_0/CANTRCV_E_BUS_ERROR/*[1]) ='true'"!][!//
            {
            DemConf_DemEventParameter_[!"node:name(node:ref(./CanTrcvDemEventParameterRefs/CanTrcvDemEventParameterRefs_0/CANTRCV_E_BUS_ERROR/__1))"!],
          [!ELSE!][!//
            [!ERROR!][!//
              CanTrcv_Tja1043 Code Generator: In CanTransceiver Channel_[!"./CanTrcvChannelId "!],If CanTrcvDemReport parameter is enabled, then CanTrcvDemEventParameterRefs parameter must be configured.
            [!ENDERROR!][!//
          [!ENDIF!]
          [!IF "node:refexists(./CanTrcvDemEventParameterRefs/CanTrcvDemEventParameterRefs_0/CANTRCV_E_BUS_ERROR/*[2]) ='true'"!][!//
            DemConf_DemEventParameter_[!"node:name(node:ref(./CanTrcvDemEventParameterRefs/CanTrcvDemEventParameterRefs_0/CANTRCV_E_BUS_ERROR/__2))"!]
            }
          [!ELSE!][!//
            [!ERROR!][!//
              CanTrcv_Tja1043 Code Generator: In CanTransceiver Channel_[!"./CanTrcvChannelId "!],If CanTrcvDemReport parameter is enabled, then CanTrcvDemEventParameterRefs parameter must be configured.
            [!ENDERROR!][!//
          [!ENDIF!]
        [!ELSE!][!//
          0x00u
        [!ENDIF!][!//
      [!ENDIF!][!//
      [!IF "$ChannelCount1 < num:i($TotalCanTrcvChannels)"!],[!CR!][!ENDIF!][!//
    [!ENDLOOP!][!//
    [!CR!][!//
  [!ENDINDENT!][!//
};
#endif

#define CANTRCV_TJA1043_STOP_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "CanTrcv_8_Tja1043_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

const CanTrcv_Tja1043_ConfigType* CanTrcv_Tja1043_ConfigTypePtr = NULL_PTR;

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL DATA
**********************************************************************************************************************/
[!ENDINDENT!][!//
[!ENDSELECT!][!//
[!ENDSELECT!]



