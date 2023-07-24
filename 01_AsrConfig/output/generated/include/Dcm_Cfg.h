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
#ifndef DCM_CFG_H
#define DCM_CFG_H

/*==================[includes]===================================================================*/

#include <Std_Types.h>


/*==================[macros]=====================================================================*/

#if (defined DCM_CONTROL_MASK_EXTERNAL_ENABLED)
#error DCM_CONTROL_MASK_EXTERNAL_ENABLED is already defined
#endif

/** \brief Set to STD_ON if at least on DcmDspDidControlMask is set to DCM_CONTROLMASK_EXTERNAL */

#define DCM_CONTROL_MASK_EXTERNAL_ENABLED STD_OFF


#if (defined DCM_CONTROLMASK_EXTERNAL)
#error DCM_CONTROLMASK_EXTERNAL is already defined
#endif

/** \brief Definition of DCM_CONTROLMASK_EXTERNAL */
#define DCM_CONTROLMASK_EXTERNAL 0U

#if (defined DCM_CONTROLMASK_NOT_DEFINED)
#error DCM_CONTROLMASK_NOT_DEFINED is already defined
#endif

/** \brief Definition of DcmDspDidControlMask where DcmDspDidControlMask is set to something different then DCM_CONTROLMASK_EXTERNAL */
#define DCM_CONTROLMASK_NOT_DEFINED 1U

#if (defined DCM_CFG_SIGNATURE)
#error DCM_CFG_SIGNATURE is already defined
#endif
/* !LINKSTO Dcm.EB.Config.Id,1 */
/** \brief Sign a certain configuration with unique hash
 */
#define DCM_CFG_SIGNATURE 767292725U


/* !LINKSTO ecuc_sws_2108,1 */
/** \brief Export symbolic name value for DcmDslProtocolRow_0_DcmDslMainConnection_DcmDslProtocolTx */
#if (defined DcmConf_DcmDslProtocolRow_0_DcmDslConnection_FD_DcmDslProtocolTx)
#error "DcmConf_DcmDslProtocolRow_0_DcmDslConnection_FD_DcmDslProtocolTx is already defined"
#endif
#define DcmConf_DcmDslProtocolRow_0_DcmDslConnection_FD_DcmDslProtocolTx   0U

/* !LINKSTO ecuc_sws_2108,1 */
/** \brief Export symbolic name value for DcmDslProtocolRow_0_DcmDslMainConnection_DcmDslProtocolTx */
#if (defined DcmConf_DcmDslProtocolRow_0_DcmDslConnection_DcmDslProtocolTx)
#error "DcmConf_DcmDslProtocolRow_0_DcmDslConnection_DcmDslProtocolTx is already defined"
#endif
#define DcmConf_DcmDslProtocolRow_0_DcmDslConnection_DcmDslProtocolTx   1U

#if (defined DCM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined Dcm_DcmDslProtocolRow_0_DcmDslProtocolTx_0)
#error Dcm_DcmDslProtocolRow_0_DcmDslProtocolTx_0 already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only
**        (AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define Dcm_DcmDslProtocolRow_0_DcmDslProtocolTx_0 0
#endif /* defined DCM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined DCM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined Dcm_DcmDslProtocolRow_0_DcmDslProtocolTx_1)
#error Dcm_DcmDslProtocolRow_0_DcmDslProtocolTx_1 already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only
**        (AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define Dcm_DcmDslProtocolRow_0_DcmDslProtocolTx_1 1
#endif /* defined DCM_PROVIDE_LEGACY_SYMBOLIC_NAMES */


#if (defined DcmConf_DcmDslProtocolRow_0_DcmDslProtocolRx_Phy)
#error DcmConf_DcmDslProtocolRow_0_DcmDslProtocolRx_Phy already defined
#endif
/** \brief Export symbolic name value */
#define DcmConf_DcmDslProtocolRow_0_DcmDslProtocolRx_Phy 0

#if (defined DCM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined Dcm_DcmDslProtocolRow_0_DcmDslProtocolRx_Phy)
#error Dcm_DcmDslProtocolRow_0_DcmDslProtocolRx_Phy already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only
 **        (AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define Dcm_DcmDslProtocolRow_0_DcmDslProtocolRx_Phy 0
#endif /* defined DCM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined DcmConf_DcmDslProtocolRow_0_DcmDslProtocolRx_Fun)
#error DcmConf_DcmDslProtocolRow_0_DcmDslProtocolRx_Fun already defined
#endif
/** \brief Export symbolic name value */
#define DcmConf_DcmDslProtocolRow_0_DcmDslProtocolRx_Fun 1

#if (defined DCM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined Dcm_DcmDslProtocolRow_0_DcmDslProtocolRx_Fun)
#error Dcm_DcmDslProtocolRow_0_DcmDslProtocolRx_Fun already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only
 **        (AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define Dcm_DcmDslProtocolRow_0_DcmDslProtocolRx_Fun 1
#endif /* defined DCM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined DcmConf_DcmDslProtocolRow_0_DcmDslProtocolRx_Phys)
#error DcmConf_DcmDslProtocolRow_0_DcmDslProtocolRx_Phys already defined
#endif
/** \brief Export symbolic name value */
#define DcmConf_DcmDslProtocolRow_0_DcmDslProtocolRx_Phys 2

#if (defined DCM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined Dcm_DcmDslProtocolRow_0_DcmDslProtocolRx_Phys)
#error Dcm_DcmDslProtocolRow_0_DcmDslProtocolRx_Phys already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only
 **        (AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define Dcm_DcmDslProtocolRow_0_DcmDslProtocolRx_Phys 2
#endif /* defined DCM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined DcmConf_DcmDslProtocolRow_0_DcmDslProtocolRx_Func)
#error DcmConf_DcmDslProtocolRow_0_DcmDslProtocolRx_Func already defined
#endif
/** \brief Export symbolic name value */
#define DcmConf_DcmDslProtocolRow_0_DcmDslProtocolRx_Func 3

#if (defined DCM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined Dcm_DcmDslProtocolRow_0_DcmDslProtocolRx_Func)
#error Dcm_DcmDslProtocolRow_0_DcmDslProtocolRx_Func already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only
 **        (AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define Dcm_DcmDslProtocolRow_0_DcmDslProtocolRx_Func 3
#endif /* defined DCM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined DCM_NUM_PROTOCOL)       /* To prevent double declaration */
#error DCM_NUM_PROTOCOL already defined
#endif /* if (defined DCM_NUM_PROTOCOL) */

/** \brief Definition of number of protocols  */
#define DCM_NUM_PROTOCOL                     1U

#if (defined DcmConf_DcmDslProtocol_DcmDslProtocolRow_0)
#error DcmConf_DcmDslProtocol_DcmDslProtocolRow_0 already defined
#endif
/** \brief Export symbolic name value */
#define DcmConf_DcmDslProtocol_DcmDslProtocolRow_0 DCM_UDS_ON_CAN

#if (defined DCM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined Dcm_DcmDslProtocolRow_0)
#error Dcm_DcmDslProtocolRow_0 already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define Dcm_DcmDslProtocolRow_0 DCM_UDS_ON_CAN
#endif /* defined DCM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined DCM_MAX_BUFFER_SIZE) /* To prevent double declaration */
#error DCM_MAX_BUFFER_SIZE already defined
#endif /* if (defined DCM_MAX_BUFFER_SIZE) */

/** \brief Definition of number of buffers */
#define DCM_MAX_BUFFER_SIZE                       4096U

#if (defined DCM_NUM_SID_TABLE) /* To prevent double declaration */
#error DCM_NUM_SID_TABLE already defined
#endif /* if (defined DCM_NUM_SID_TABLE) */

/** \brief Number Service ID table entries configured */
#define DCM_NUM_SID_TABLE                    1U

#if (defined DCM_ROE_ONDTCSTATUSCHANGE_SHORT_RESPONSE )  /* To prevent double declaration */
#error DCM_ROE_ONDTCSTATUSCHANGE_SHORT_RESPONSE already defined
#endif /* #if (defined DCM_ROE_ONDTCSTATUSCHANGE_SHORT_RESPONSE ) */
/** \brief Number of ROE Service that respond on DTC status change with a short message */
#define DCM_ROE_ONDTCSTATUSCHANGE_SHORT_RESPONSE      0U

#if (defined DCM_NUM_SES_TAB_ENTRY) /* To prevent double declaration */
#error DCM_NUM_SES_TAB_ENTRY already defined
#endif /* if (defined DCM_NUM_SES_TAB_ENTRY) */

/** \brief Number of configured diagnostic sessions */
#define DCM_NUM_SES_TAB_ENTRY                4U

#if (defined DCM_DSP_RETURN_CONTROLTOECU_TIMEOUT) /* To prevent double declaration */
#error DCM_DSP_RETURN_CONTROLTOECU_TIMEOUT already defined
#endif /* if (defined DCM_DSP_RETURN_CONTROLTOECU_TIMEOUT) */

/** \brief Processing time allowed for returncontroltoecu completion */
#define DCM_DSP_RETURN_CONTROLTOECU_TIMEOUT                100U

#if (defined DCM_DSP_RETURN_CONTROLTOECU_TIMEOUT_REPORT) /* To prevent double declaration */
#error DCM_DSP_RETURN_CONTROLTOECU_TIMEOUT_REPORT already defined
#endif /* if (defined DCM_DSP_RETURN_CONTROLTOECU_TIMEOUT_REPORT) */

/** \brief Det error report for returnControlToEcu is enables or not */
#define DCM_DSP_RETURN_CONTROLTOECU_TIMEOUT_REPORT                STD_ON
#if (defined DCM_DSP_POWER_DOWN_TIME) /* To prevent double declaration */
#error DCM_DSP_POWER_DOWN_TIME already defined
#endif /* if (defined DCM_DSP_POWER_DOWN_TIME) */

/** \brief Minimum stand-by time the server will remain in the power-down sequence */
#define DCM_DSP_POWER_DOWN_TIME                10U

#if (defined DCM_PAGEDBUFFER_ENABLED)   /* To prevent double declaration */
#error DCM_PAGEDBUFFER_ENABLED already defined
#endif /* if (defined DCM_PAGEDBUFFER_ENABLED) */

/** \brief Definition if paged buffer handling is enabled */
#define DCM_PAGEDBUFFER_ENABLED              STD_OFF

#if (defined DCM_PAGED_BUFFER_TIMEOUT) /* To prevent double declaration */
#error DCM_PAGED_BUFFER_TIMEOUT already defined
#endif /* if (defined DCM_PAGED_BUFFER_TIMEOUT) */

/** \brief Definition of Timeout for Paged buffer transmission.  This timeout
 ** is counted in units of DCM_TASK_TIME */
#define DCM_PAGED_BUFFER_TIMEOUT             5U

#if (defined DCM_DEV_ERROR_DETECT)
#error DCM_DEV_ERROR_DETECT already defined
#endif
/** \brief Switch, indicating if development error detection is activated for
 ** DCM */
#define DCM_DEV_ERROR_DETECT                 STD_ON

#if (defined DCM_DIAG_SES_RESP_PEND_ENABLED )
#error DCM_DIAG_SES_RESP_PEND_ENABLED already defined
#endif /* #if (defined DCM_DIAG_SES_RESP_PEND_ENABLED ) */

/** \brief Enable if are any number of Pending responses provided per session */
#define DCM_DIAG_SES_RESP_PEND_ENABLED      STD_ON

#if (defined DCM_DIAG_RESP_MAX_NUM_RESP_PEND )  /* To prevent double declaration */
#error DCM_DIAG_RESP_MAX_NUM_RESP_PEND already defined
#endif /* #if (defined DCM_DIAG_RESP_MAX_NUM_RESP_PEND ) */

/** \brief Maximum number of Pending responses possible */
#define DCM_DIAG_RESP_MAX_NUM_RESP_PEND      5U

#if (defined DCM_DIAG_DSL_INFINITY_LIMIT_RESP_PEND ) /* To prevent double declaration */
#error DCM_DIAG_DSL_INFINITY_LIMIT_RESP_PEND already defined
#endif /* #if (defined DCM_DIAG_DSL_INFINITY_LIMIT_RESP_PEND) */
/** \brief Infinity limit (255 or 65535) for transmitting infinite ResponsePending NRC (0x78) */
#define DCM_DIAG_DSL_INFINITY_LIMIT_RESP_PEND      255U

#if (defined DCM_VERSION_INFO_API)
#error DCM_VERSION_INFO_API already defined
#endif
/** \brief Switch, indicating if Dcm_GetVersionInfo() API is activated for
 ** DCM */
#define DCM_VERSION_INFO_API                 STD_ON

#if (defined DCM_INCLUDE_RTE)
#error DCM_INCLUDE_RTE already defined
#endif
/** \brief Switch, indicating if RTE is available and can be used from DCM */
#define DCM_INCLUDE_RTE                      STD_ON

#if (defined DCM_RTETYPES_PROTECTION_AT_FILE_LEVEL)
#error DCM_RTETYPES_PROTECTION_AT_FILE_LEVEL already defined
#endif
/** \brief Switch, indicating if DCM uses the protection at file level */
#define DCM_RTETYPES_PROTECTION_AT_FILE_LEVEL         STD_OFF

#if (defined DCM_SECURITYACCESS_STRICT)
#error DCM_SECURITYACCESS_STRICT already defined
#endif
/** \brief Switch, indicating whether the strict SecurityAccess mechanism is activated for the DCM */
#define DCM_SECURITYACCESS_STRICT            STD_OFF

#if (defined DCM_MODEDECLARATION_SUPPORT)
#error DCM_MODEDECLARATION_SUPPORT already defined
#endif
/** \brief Switch, indicating if Mode declaration support is enabled and SchM switch APIs
 ** are generated by RTE to be used for notifying mode switches to mode users */
#define DCM_MODEDECLARATION_SUPPORT          STD_ON

#if (defined DCM_MODE_DECLARATION_OEM_BL) /* To prevent double declaration */
#error DCM_MODE_DECLARATION_OEM_BL already defined
#endif /* if (defined DCM_MODE_DECLARATION_OEM_BL) */

/** \brief Indicates, if OEM boot support and mode declaration is enabled */
#define DCM_MODE_DECLARATION_OEM_BL           STD_OFF
#if (defined DCM_MODE_DECLARATION_SYS_BL) /* To prevent double declaration */
#error DCM_MODE_DECLARATION_SYS_BL already defined
#endif /* if (defined DCM_MODE_DECLARATION_SYS_BL) */

/** \brief Indicates, if SYS boot support and mode declaration is enabled */
#define DCM_MODE_DECLARATION_SYS_BL            STD_ON
/** \brief Switch, indicating availability of timing values in positive response of 0x10 and JumpFromBL */
#if (defined DCM_TIMING_VALUES_IN_POSITIVE_RESPONSE)
  #error "DCM_TIMING_VALUES_IN_POSITIVE_RESPONSE is already defined"
#endif
#define DCM_TIMING_VALUES_IN_POSITIVE_RESPONSE                      STD_ON

#if (defined DCM_ASYNC_SERVICE_HANDLER)
#error DCM_ASYNC_SERVICE_HANDLER already defined
#endif
/** \brief Switch, indicating if Async service handler is available */
#define DCM_ASYNC_SERVICE_HANDLER             STD_OFF

#if (defined DCM_ASYNC_DID_SERVICES)
#error DCM_ASYNC_DID_SERVICES already defined
#endif
/** \brief Switch, indicating if either of services 0x22, 0x2E or 0x2F use an Async service handler */
#define DCM_ASYNC_DID_SERVICES                STD_OFF

#if (defined DCM_READ_DID_BLOCK_ID_CONFIGURED) /* To prevent double declaration */
#error DCM_READ_DID_BLOCK_ID_CONFIGURED already defined
#endif /* if (defined DCM_READ_DID_BLOCK_ID_CONFIGURED) */

/** \brief Indicates, if a DID is configured with read access and having signal with Data Access
 **  Interface as block-id */
#define DCM_READ_DID_BLOCK_ID_CONFIGURED           STD_OFF
#if (defined DCM_WRITE_DID_BLOCK_ID_CONFIGURED) /* To prevent double declaration */
#error DCM_WRITE_DID_BLOCK_ID_CONFIGURED already defined
#endif /* if (defined DCM_WRITE_DID_BLOCK_ID_CONFIGURED) */

/** \brief Indicates, if a DID is configured with write access and having signal with Data Access
 **  Interface as block-id */
#define DCM_WRITE_DID_BLOCK_ID_CONFIGURED           STD_OFF
#if (defined DCM_DID_BLOCK_ID_CONFIGURED) /* To prevent double declaration */
#error DCM_DID_BLOCK_ID_CONFIGURED already defined
#endif /* if (defined DCM_DID_BLOCK_ID_CONFIGURED) */
/** \brief Indicates, if a DID is configured with read or write access and having signal with Data Access
 **  Interface as block-id */
#define DCM_DID_BLOCK_ID_CONFIGURED           STD_OFF
#if (defined DCM_NVM_USAGE_REQUIRED) /* To prevent double declaration */
#error DCM_NVM_USAGE_REQUIRED already defined
#endif /* if (defined DCM_NVM_USAGE_REQUIRED) */

/** \brief Indicates, if NvM.h is required */
#define DCM_NVM_USAGE_REQUIRED           STD_OFF
#if (defined DCM_JUMP_TO_BL_ENABLED) /* To prevent double declaration */
#error DCM_JUMP_TO_BL_ENABLED already defined
#endif /* if (defined DCM_JUMP_TO_BL_ENABLED) */

/** \brief Indicates, if SYS or OEM boot support is enabled */
#define DCM_JUMP_TO_BL_ENABLED            STD_ON
#if (defined DCM_ENDIANNESS_CONVERSION) /* To prevent double declaration */
#error DCM_ENDIANNESS_CONVERSION already defined
#endif /* if (defined DCM_ENDIANNESS_CONVERSION) */
/** \brief Indicates, if endianness conversion is enabled */
#define DCM_ENDIANNESS_CONVERSION            STD_ON
#if (defined DCM_DID_ENDIANNESS_CONVERSION) /* To prevent double declaration */
#error DCM_DID_ENDIANNESS_CONVERSION already defined
#endif /* if (defined DCM_DID_ENDIANNESS_CONVERSION) */
/** \brief Indicates if endianness conversion for DIDs is enabled */
#define DCM_DID_ENDIANNESS_CONVERSION            STD_ON
#if (defined DCM_GET_SIZEOFEDRBYDTC_OPTIMIZATION)
#error DCM_GET_SIZEOFEDRBYDTC_OPTIMIZATION already defined
#endif
/** \brief Switch, for the optimized service handling of ReadDTCInformation(0x19),
 ** Subfunction 0x06 and 0x19.
 ** Handling of sub services 0x06 and 0x19 of service
 ** ReadDTCInformation (0x19) is optimized if Dem provides the size of UDS Extended data record
 ** number along with the extended data bytes size (according to AUTOSAR R4.1) */
#define DCM_GET_SIZEOFEDRBYDTC_OPTIMIZATION                 STD_OFF
#if (defined DCM_RTE_TABLE_DID_SERVICES_SIZE)
#error DCM_RTE_TABLE_DID_SERVICES_SIZE already defined
#endif
/** \brief Did Services count */
#define DCM_RTE_TABLE_DID_SERVICES_SIZE   66U

#if (defined DCM_CALLBACK_REQUEST_SIZE)
#error DCM_CALLBACK_REQUEST_SIZE already defined
#endif
/** \brief Callback Request count */
#define DCM_CALLBACK_REQUEST_SIZE   0U

#if (defined DCM_TASK_TIME) /* To prevent double declaration */
#error DCM_TASK_TIME already defined
#endif /* if (defined DCM_TASK_TIME) */

/** \brief Definition for periodic cyclic task time in milliseconds */
#define DCM_TASK_TIME             10U

#if (defined DCM_DSP_DIDSERVICES_NUM_DIDS) /* To prevent double declaration */
#error DCM_DSP_DIDSERVICES_NUM_DIDS already defined
#endif /* if (defined DCM_DSP_DIDSERVICES_NUM_DIDS) */

/** \brief Number of enabled DIDs */
 /* !LINKSTO SWS_Dcm_01096,1 */
#define DCM_DSP_DIDSERVICES_NUM_DIDS          66U


#if (defined DCM_DSP_DIDSERVICES_NUM_DID_RANGES) /* To prevent double declaration */
#error DCM_DSP_DIDSERVICES_NUM_DID_RANGES already defined
#endif /* if (defined DCM_DSP_DIDSERVICES_NUM_DID_RANGES) */

/** \brief Number of DID ranges configured */
#define DCM_DSP_DIDSERVICES_NUM_DID_RANGES    0U

#if (defined DCM_DSP_USE_DIDRANGES) /* To prevent double declaration */
#error DCM_DSP_USE_DIDRANGES already defined
#endif /* if (defined DCM_DSP_USE_DIDRANGES) */

/** \brief STD_ON if at least one DID range is configured. STD_OFF otherwise */
#define DCM_DSP_USE_DIDRANGES                 STD_OFF

#if (defined DCM_DSP_DIDSERVICES_NUM_DID_INFO) /* To prevent double declaration */
#error DCM_DSP_DIDSERVICES_NUM_DID_INFO already defined
#endif /* if (defined DCM_DSP_DIDSERVICES_NUM_DID_INFO) */

/** \brief Number of DID info containers configured */
#define DCM_DSP_DIDSERVICES_NUM_DID_INFO             66U

#if (defined DCM_DSP_DIDSERVICES_DIDRANGES_MAX_DATA_LENGTH) /* To prevent double declaration */
#error DCM_DSP_DIDSERVICES_DIDRANGES_MAX_DATA_LENGTH already defined
#endif /* if (defined DCM_DSP_DIDSERVICES_DIDRANGES_MAX_DATA_LENGTH) */

/** \brief The biggest maximum data length value of the configured DID ranges */
#define DCM_DSP_DIDSERVICES_DIDRANGES_MAX_DATA_LENGTH             0U

#if (defined DCM_DSP_DIDSERVICES_NUM_DID_READACCESS_INFO) /* To prevent double declaration */
#error DCM_DSP_DIDSERVICES_NUM_DID_READACCESS_INFO already defined
#endif /* if (defined DCM_DSP_DIDSERVICES_NUM_DID_READACCESS_INFO) */

/** \brief Number of DID read access info structures configured */
#define DCM_DSP_DIDSERVICES_NUM_DID_READACCESS_INFO             66U

#if (defined DCM_DSP_DIDSERVICES_NUM_DID_WRITEACCESS_INFO) /* To prevent double declaration */
#error DCM_DSP_DIDSERVICES_NUM_DID_WRITEACCESS_INFO already defined
#endif /* if (defined DCM_DSP_DIDSERVICES_NUM_DID_WRITEACCESS_INFO) */

/** \brief Number of DID write access info structures configured */
#define DCM_DSP_DIDSERVICES_NUM_DID_WRITEACCESS_INFO             16U

#if (defined DCM_DSP_DIDSERVICES_NUM_DID_IOCTLACCESS_INFO) /* To prevent double declaration */
#error DCM_DSP_DIDSERVICES_NUM_DID_IOCTLACCESS_INFO already defined
#endif /* if (defined DCM_DSP_DIDSERVICES_NUM_DID_IOCTLACCESS_INFO) */

/** \brief Number of DID control access info structures configured */
#define DCM_DSP_DIDSERVICES_NUM_DID_IOCTLACCESS_INFO             0U

#if (defined DCM_DSP_DIDSERVICES_NUM_DID_READSCALINGACCESS_INFO) /* To prevent double declaration */
#error DCM_DSP_DIDSERVICES_NUM_DID_READSCALINGACCESS_INFO already defined
#endif /* if (defined DCM_DSP_DIDSERVICES_NUM_DID_READSCALINGACCESS_INFO) */

/** \brief Number of DID read scaling access info structures configured */
#define DCM_DSP_DIDSERVICES_NUM_DID_READSCALINGACCESS_INFO             0U

/** \brief Return control to ECU is to be defined and executed only if both 0x2F
 ** service is enabled and if at least one DID list is configured with control access */
#if (defined DCM_RETURNCONTROLTOECU_ENABLED)
#error DCM_RETURNCONTROLTOECU_ENABLED already defined
#endif /* #if (defined  DCM_RETURNCONTROLTOECU_ENABLED) */

#define DCM_RETURNCONTROLTOECU_ENABLED     STD_OFF

#if (defined DCM_DSP_PRECONF_ADDRESS_LENGTH_FORMATIDENTIFIER)
#error DCM_DSP_PRECONF_ADDRESS_LENGTH_FORMATIDENTIFIER already defined
#endif /* if (defined DCM_DSP_PRECONF_ADDRESS_LENGTH_FORMATIDENTIFIER) */

/** \brief Indicates AddressAndLengthFormatIdentifier is configured or not */
#define DCM_DSP_PRECONF_ADDRESS_LENGTH_FORMATIDENTIFIER             STD_ON
#if (defined DCM_NUM_ADDR_LENGTH_FORMAT_IDENTIFIER)
#error DCM_NUM_ADDR_LENGTH_FORMAT_IDENTIFIER already defined
#endif /* if (defined DCM_NUM_ADDR_LENGTH_FORMAT_IDENTIFIER) */

/** \brief number of AddressAndLengthFormatIdentifiers supported */
#define DCM_NUM_ADDR_LENGTH_FORMAT_IDENTIFIER 1U

#if (defined DCM_NUM_MEMORY_IDINFO)
#error DCM_NUM_MEMORY_IDINFO defined
#endif /* if (defined DCM_NUM_MEMORY_IDINFO) */

/** \brief Number of MemoryIdInfos configured */
#define DCM_NUM_MEMORY_IDINFO                 1U

#if (defined DCM_USE_MEMORY_ID)
#error DCM_USE_MEMORY_ID defined
#endif /* if (defined DCM_USE_MEMORY_ID) */

#if (defined DCM_MAX_NUM_READ_RANGES)
#error DCM_MAX_NUM_READ_RANGES defined
#endif /* if (defined DCM_MAX_NUM_READ_RANGES) */

/** \brief Max Number of Read Ranges configured on a memory table*/
#define DCM_MAX_NUM_READ_RANGES                 1U

#if (defined DCM_MAX_NUM_WRITE_RANGES)
#error DCM_MAX_NUM_WRITE_RANGES defined
#endif /* if (defined DCM_MAX_NUM_WRITE_RANGES) */

/** \brief Max Number of Read Ranges configured on a memory table*/
#define DCM_MAX_NUM_WRITE_RANGES                 1U

/** \brief Defines whether Dcm shall use the MemoryIdentifier parameter */
#define DCM_USE_MEMORY_ID   FALSE
#if (defined DCM_NUM_DID_DATA) /* To prevent double declaration */
#error DCM_NUM_DID_DATA already defined
#endif /* if (defined DCM_NUM_DID_DATA) */


/** \brief Number of DID Datas configured */
#define DCM_NUM_DID_DATA                      66U

#if (defined DCM_DID_REF_COUNT) /* To prevent double declaration */
#error DCM_DID_REF_COUNT already defined
#endif /* if (defined DCM_DID_REF_COUNT) */

/** \brief Total number of references of each DID */
#define DCM_DID_REF_COUNT                     0U

#if (defined DCM_DID_SIGNALS_COUNT) /* To prevent double declaration */
#error DCM_DID_SIGNALS_COUNT already defined
#endif /* if (defined DCM_DID_SIGNALS_COUNT) */

/** \brief Total number of signals of each DID */
#define DCM_DID_SIGNALS_COUNT                 66U

#if (defined DCM_READ_DID_MAX) /* To prevent double declaration */
#error DCM_READ_DID_MAX already defined
#endif /* if (defined DCM_READ_DID_MAX) */

/** \brief Size of the biggest DID configured including OBD MIDs/PIDs */
#if (defined DCM_DID_MAX_SIZE)
#error "DCM_DID_MAX_SIZE is already defined"
#endif
#define DCM_DID_MAX_SIZE                      164U

/** \brief Maximum number of Dids that can be requested in a single read */
#define DCM_READ_DID_MAX                      5U

#if (defined DCM_DID_DATA_TABLE_SIZE) /* To prevent double declaration */
#error DCM_DID_DATA_TABLE_SIZE already defined
#endif /* if (defined DCM_DID_DATA_TABLE_SIZE) */

/** \brief Size of Dcm_DidDataTable */
#define DCM_DID_DATA_TABLE_SIZE               83U

#if (defined DCM_DSP_USE_SENDERRECEIVER_INTERFACES) /* To prevent double declaration */
#error DCM_DSP_USE_SENDERRECEIVER_INTERFACES already defined
#endif /* if (defined DCM_DSP_USE_SENDERRECEIVER_INTERFACES) */

/** \brief Indicates if any DID which has read, write or control access has a DcmDspData with
  * DcmDspDataUsePort equal to USE_DATA_SENDER_RECEIVER or USE_DATA_SENDER_RECEIVER_AS_SERVICE */
#define DCM_DSP_USE_SENDERRECEIVER_INTERFACES                 STD_OFF
/** \brief Maximum allowed periodicDIDs which can be read in a single "ReadDataByPeriodicIdentifier" request */
#if (defined DCM_MAX_PERIODIC_DID_READ)
  #error "DCM_MAX_PERIODIC_DID_READ is already defined"
#endif
#define DCM_MAX_PERIODIC_DID_READ               1U

/** \brief Maximum number of periodicDataIdentifiers that can be scheduled concurrently */
#if (defined DCM_MAX_PERIODIC_DID_SCHEDULER)
  #error "DCM_MAX_PERIODIC_DID_SCHEDULER is already defined"
#endif
#define DCM_MAX_PERIODIC_DID_SCHEDULER          10U

/** \brief Size of a single sampling bufer to which periodic DIDs are sampled */
#if (defined DCM_PERIODIC_DID_SAMPLING_BUFFER_SIZE)
  #error "DCM_PERIODIC_DID_SAMPLING_BUFFER_SIZE is already defined"
#endif
#define DCM_PERIODIC_DID_SAMPLING_BUFFER_SIZE   8U

/** \brief Number of individual sampling buffers in the periodic DID transmission ring */
#if (defined DCM_PERIODIC_DID_TRANSMISSION_RING_ENTRIES)
  #error "DCM_PERIODIC_DID_TRANSMISSION_RING_ENTRIES is already defined"
#endif
#define DCM_PERIODIC_DID_TRANSMISSION_RING_ENTRIES      64U

/** \brief Maximum data length of periodic DDDID */
#if (defined DCM_PERIODIC_DDDID_MAX_LENGTH)
  #error "DCM_PERIODIC_DDDID_MAX_LENGTH is already defined"
#endif
#define DCM_PERIODIC_DDDID_MAX_LENGTH      0U

/* !LINKSTO Dcm.PeriodicDid.Dsn.GenTrRate,1 */

/** \brief Slow transmission rate for periodicDataIdentifiers */
#if (defined DCM_PERIODIC_TRANSMISSION_SLOW_RATE)
  #error "DCM_PERIODIC_TRANSMISSION_SLOW_RATE is already defined"
#endif
#define DCM_PERIODIC_TRANSMISSION_SLOW_RATE      0U

/** \brief Medium transmission rate for periodicDataIdentifiers */
#if (defined DCM_PERIODIC_TRANSMISSION_MEDIUM_RATE)
  #error "DCM_PERIODIC_TRANSMISSION_MEDIUM_RATE is already defined"
#endif
#define DCM_PERIODIC_TRANSMISSION_MEDIUM_RATE      0U

/** \brief Fast transmission rate for periodicDataIdentifiers */
#if (defined DCM_PERIODIC_TRANSMISSION_FAST_RATE)
  #error "DCM_PERIODIC_TRANSMISSION_FAST_RATE is already defined"
#endif
#define DCM_PERIODIC_TRANSMISSION_FAST_RATE      0U



/* A uint32 buffer size is considered here since a union is created between arrays of all DID data types
 * to ensure 32 bit alignment for the signals buffer for safe casting from uint8* to 16/32*
 * The respective cast is needed for sender/receiver interfaces which require pointers to int16/32 as
 * parameters */
/** \brief Maximum size that a DID signal can occupy in a uint32 array */

/** \brief Maximum size that a DID data defined as range can occupy in a uint32 array*/

/** \brief The maximum size that a ReadScaling DID needs. */




#if (defined DCM_DATA_MAX_SIZE_DWORD_ARRAY) /* To prevent double declaration */
#error DCM_DATA_MAX_SIZE_DWORD_ARRAY already defined
#endif /* if (defined DCM_DATA_MAX_SIZE_DWORD_ARRAY) */

#define DCM_DATA_MAX_SIZE_DWORD_ARRAY   41U

/* Even if the value of this macro is not generated it is strictly dependent on a macro generated
 * above and has a similar meaning so for better readability/code understanding it is placed here */
#if (defined DCM_DATA_MAX_SIZE_WORD_ARRAY) /* To prevent double declaration */
#error DCM_DATA_MAX_SIZE_WORD_ARRAY already defined
#endif /* if (defined DCM_DATA_MAX_SIZE_WORD_ARRAY) */

#define DCM_DATA_MAX_SIZE_WORD_ARRAY    (2U * DCM_DATA_MAX_SIZE_DWORD_ARRAY)

/* Even if the value of this macro is not generated it is strictly dependent on a macro generated
 * above and has a similar meaning so for better readability/code understanding it is placed here
 * If the max length of DID data defined by ranges is bigger then max length of DID data
 * defined by signals then the buffer size need to be updated. */
#if (defined DCM_DATA_MAX_SIZE_BYTE_ARRAY) /* To prevent double declaration */
#error DCM_DATA_MAX_SIZE_BYTE_ARRAY already defined
#endif /* if (defined DCM_DATA_MAX_SIZE_BYTE_ARRAY) */

#define DCM_DATA_MAX_SIZE_BYTE_ARRAY    (4U * DCM_DATA_MAX_SIZE_DWORD_ARRAY)



#if (defined DCM_REQUEST_MANUFACTURER_NOTIFICATION_ENABLED)
#error DCM_REQUEST_MANUFACTURER_NOTIFICATION_ENABLED already defined
#endif
/** \brief Switch, indicating if Service request manufacturer notification is available */
#define DCM_REQUEST_MANUFACTURER_NOTIFICATION_ENABLED       STD_OFF

#if (defined DCM_REQUEST_SUPPLIER_NOTIFICATION_ENABLED)
#error DCM_REQUEST_SUPPLIER_NOTIFICATION_ENABLED already defined
#endif
/** \brief Switch, indicating if Service request supplier notification is available */
#define DCM_REQUEST_SUPPLIER_NOTIFICATION_ENABLED       STD_ON

#if (defined DCM_RTE_TABLE_REQUEST_MANUFACTURER_SIZE)
#error DCM_RTE_TABLE_REQUEST_MANUFACTURER_SIZE already defined
#endif
/** \brief Service request manufacturer notification count */
#define DCM_RTE_TABLE_REQUEST_MANUFACTURER_SIZE   0U

#if (defined DCM_RTE_TABLE_REQUEST_SUPPLIER_SIZE)
#error DCM_RTE_TABLE_REQUEST_SUPPLIER_SIZE already defined
#endif
/** \brief Service request supplier notification count */
#define DCM_RTE_TABLE_REQUEST_SUPPLIER_SIZE   1U

/** \brief Indicates, if application will be notified of transmission confirmation */
#if (defined DCM_APPL_TXCONFIRMATION_NOTIFICATION) /* To prevent double declaration */
#error DCM_APPL_TXCONFIRMATION_NOTIFICATION already defined
#endif /* if defined DCM_APPL_TXCONFIRMATION_NOTIFICATION */
#define DCM_APPL_TXCONFIRMATION_NOTIFICATION                      STD_OFF
/** \brief Macro to check that if common buffer is used for Rx and Tx */
#if (defined DCM_COMMON_BUFF_CONFIGURED)
  #error "DCM_COMMON_BUFF_CONFIGURED is already defined"
#endif
#define DCM_COMMON_BUFF_CONFIGURED STD_OFF

#if (defined DCM_RTE_DEFAULTSESSION_MODE) /* To prevent double declaration */
#error DCM_RTE_DEFAULTSESSION_MODE already defined
#endif
/** \brief  Definition if DCM_DEFAULT_SESSION has another name */
#define DCM_RTE_DEFAULTSESSION_MODE   RTE_MODE_DcmDiagnosticSessionControl_DCM_DEFAULT_SESSION



/** \brief Switch that enables/disables BusyRepeatRequest responses */
#if (defined DCM_RESPOND_WITH_BUSYREPEATREQUEST)
#error DCM_RESPOND_WITH_BUSYREPEATREQUEST already defined
#endif
/** \brief Switch, indicating if a BusyRepeastRequest response is send or not */
#define DCM_RESPOND_WITH_BUSYREPEATREQUEST       STD_OFF
#if (DCM_INCLUDE_RTE == STD_OFF)

/*------------------[definitions of security levels]----------------------------------------------*/

#if (defined DcmConf_DcmDspSecurity_SA_Level1)
#error DcmConf_DcmDspSecurity_SA_Level1 already defined
#endif
/** \brief Export symbolic name value */
#define DcmConf_DcmDspSecurity_SA_Level1 1U

#if (defined DCM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined Dcm_SA_Level1)
#error Dcm_SA_Level1 already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only
 **        (AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define Dcm_SA_Level1 1U
#endif /* defined DCM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#endif /* if (DCM_INCLUDE_RTE == STD_OFF) */

#if (defined DCM_DSL_ENABLE_SET_ACTIVE_DIAGNOSIS) /* To prevent double declaration */
#error DCM_DSL_ENABLE_SET_ACTIVE_DIAGNOSIS already defined
#endif /* if (defined DCM_DSL_ENABLE_SET_ACTIVE_DIAGNOSIS) */

/** \brief Indicates that the active diagnosis functionality was enabled */
#define DCM_DSL_ENABLE_SET_ACTIVE_DIAGNOSIS           STD_OFF
#if (defined DCM_COMM_MULTICORE_ENABLED) /* To prevent double declaration */
#error DCM_COMM_MULTICORE_ENABLED already defined
#endif /* if (defined DCM_COMM_MULTICORE_ENABLED) */

/** \brief Indicates that Dcm ComM inter-partition communication is enabled */
#define DCM_COMM_MULTICORE_ENABLED           STD_OFF
#if (defined DCM_DDDID_PERSISTENCE) /* To prevent double declaration */
#error DCM_DDDID_PERSISTENCE already defined
#endif /* if (defined DCM_DDDID_PERSISTENCE) */

/** \brief Indicates if the DDDID persistence feature support is enabled */
#define DCM_DDDID_PERSISTENCE           STD_OFF
#if (defined DCM_DDDID_CHECK_SOURCES) /* To prevent double declaration */
#error DCM_DDDID_CHECK_SOURCES already defined
#endif /* if (defined DCM_DDDID_CHECK_SOURCES) */

/** \brief If the DDDID sources must be checked each time they are read */
#define DCM_DDDID_CHECK_SOURCES           STD_OFF
#if (defined DCM_NUM_DDDID_SRCTAB_ELEMENTS)
#error DCM_NUM_DDDID_SRCTAB_ELEMENTS already defined
#endif /* if (defined DCM_NUM_DDDID_SRCTAB_ELEMENTS) */

/** \brief Number of pre configured DDDID sources */
#define DCM_NUM_DDDID_SRCTAB_ELEMENTS   0U

#if (defined DCM_DDDID_NVM_BLOCK_ID) /* To prevent double declaration */
#error DCM_DDDID_NVM_BLOCK_ID already defined
#endif /* if (defined DCM_DDDID_NVM_BLOCK_ID) */

/* !LINKSTO Dcm.EB.DcmDspDDDIDBlockIdRef,2 */
/** \brief Block Id of NvM to store DDDID Data for persistence */
#define DCM_DDDID_NVM_BLOCK_ID           0xFFU

/* !LINKSTO Dcm.ROE.Enabled,3 */
/* DcmDslResponseOnEvent is verified in xdm */
#if (defined DCM_DSP_USE_ROESERVICES)
  #error "DCM_DSP_USE_ROESERVICES is already defined"
#endif
#define DCM_DSP_USE_ROESERVICES       STD_OFF

/* Define used for prototype generation in Dcm.h even if ROE is not present */
#define DCM_ROE_NUM_PRECONF_EVENT   0U

#if (defined DCM_ROE_NUM_ONCHANGEOFDATAIDENTIFIER_EVENTS) /* To prevent double declaration */
#error DCM_ROE_NUM_ONCHANGEOFDATAIDENTIFIER_EVENTS already defined
#endif /* if (defined DCM_ROE_NUM_ONCHANGEOFDATAIDENTIFIER_EVENTS) */

/** \brief Number of available OnChangeOfDataIdentifier ROE events */
#define DCM_ROE_NUM_ONCHANGEOFDATAIDENTIFIER_EVENTS 0U

#if (defined DCM_ROE_NUM_ROEONDTCSTATUSCHANGE) /* To prevent double declaration */
#error DCM_ROE_NUM_ROEONDTCSTATUSCHANGE already defined
#endif /* if (defined DCM_ROE_NUM_ROEONDTCSTATUSCHANGE) */

/** \brief Number of available RoeOnDTCStatusChange ROE events */
#define DCM_ROE_NUM_ROEONDTCSTATUSCHANGE   0U

#if (defined DCM_HAS_ROE_TYPE2) /* To prevent double declaration */
#error DCM_HAS_ROE_TYPE2 already defined
#endif /* if (defined DCM_HAS_ROE_TYPE2) */

/** \brief Indicates if TYPE2 ROE are enabled */
#define DCM_HAS_ROE_TYPE2           STD_OFF

#if (defined DCM_MAX_CONSEC_GET_EXT_DATA_REC) /* To prevent double declaration */
#error DCM_MAX_CONSEC_GET_EXT_DATA_REC already defined
#endif /* if (defined DCM_MAX_CONSEC_GET_EXT_DATA_REC) */

/** \brief The maximum number of consecutive Get Extended Data Record executions for service 0xAF */
#define DCM_MAX_CONSEC_GET_EXT_DATA_REC   0U
#if (defined DCM_HAS_PERIODIC_RESPONSE_TYPE2) /* To prevent double declaration */
#error DCM_HAS_PERIODIC_RESPONSE_TYPE2 already defined
#endif /* if (defined DCM_HAS_PERIODIC_RESPONSE_TYPE2) */

/** \brief Indicates if TYPE2 periodic responses are enabled */
#define DCM_HAS_PERIODIC_RESPONSE_TYPE2           STD_OFF

/*------------------[Services configured]--------------------------------------------------------*/

#if (defined DCM_DSP_USE_SERVICE_0XAF ) /* To prevent double declaration */
#error DCM_DSP_USE_SERVICE_0XAF already defined
#endif /* if (defined DCM_DSP_USE_SERVICE_0XAF) */

#define DCM_DSP_USE_SERVICE_0XAF           STD_OFF

#if (defined DCM_DSP_USE_SERVICE_0X3E ) /* To prevent double declaration */
#error DCM_DSP_USE_SERVICE_0X3E already defined
#endif /* if (defined DCM_DSP_USE_SERVICE_0X3E) */

#define DCM_DSP_USE_SERVICE_0X3E           STD_ON

#if (defined DCM_DSP_USE_SERVICE_0X14 ) /* To prevent double declaration */
#error DCM_DSP_USE_SERVICE_0X14 already defined
#endif /* if (defined DCM_DSP_USE_SERVICE_0X14) */

#define DCM_DSP_USE_SERVICE_0X14           STD_ON

#if (defined DCM_DSP_USE_SERVICE_0X19 ) /* To prevent double declaration */
#error DCM_DSP_USE_SERVICE_0X19 already defined
#endif /* if (defined DCM_DSP_USE_SERVICE_0X19) */

#define DCM_DSP_USE_SERVICE_0X19           STD_ON

#if (defined DCM_DSP_USE_SERVICE_0X27 ) /* To prevent double declaration */
#error DCM_DSP_USE_SERVICE_0X27 already defined
#endif /* if (defined DCM_DSP_USE_SERVICE_0X27) */

#define DCM_DSP_USE_SERVICE_0X27           STD_ON

#if (defined DCM_DSP_USE_SERVICE_0X10 ) /* To prevent double declaration */
#error DCM_DSP_USE_SERVICE_0X10  already defined
#endif /* if (defined DCM_DSP_USE_SERVICE_0X10 ) */

#define DCM_DSP_USE_SERVICE_0X10           STD_ON

#if (defined DCM_DSP_USE_SERVICE_0X22 ) /* To prevent double declaration */
#error DCM_DSP_USE_SERVICE_0X22  already defined
#endif /* if (defined DCM_DSP_USE_SERVICE_0X22 ) */

#define DCM_DSP_USE_SERVICE_0X22           STD_ON

#if (defined DCM_DSP_SERVICE_0X22_ASYNC ) /* To prevent double declaration */
#error DCM_DSP_SERVICE_0X22_ASYNC  already defined
#endif /* if (defined DCM_DSP_SERVICE_0X22_ASYNC ) */

#define DCM_DSP_SERVICE_0X22_ASYNC         STD_OFF

#if (defined DCM_DSP_USE_SERVICE_0X24 ) /* To prevent double declaration */
#error DCM_DSP_USE_SERVICE_0X24  already defined
#endif /* if (defined DCM_DSP_USE_SERVICE_0X24 ) */

#define DCM_DSP_USE_SERVICE_0X24           STD_OFF

#if (defined DCM_DSP_USE_SERVICE_0X2A ) /* To prevent double declaration */
#error DCM_DSP_USE_SERVICE_0X2A  already defined
#endif /* if (defined DCM_DSP_USE_SERVICE_0X2A ) */

#define DCM_DSP_USE_SERVICE_0X2A           STD_ON

#if (defined DCM_DSP_USE_SERVICE_0X23 ) /* To prevent double declaration */
#error DCM_DSP_USE_SERVICE_0X23  already defined
#endif /* if (defined DCM_DSP_USE_SERVICE_0X23 ) */

#define DCM_DSP_USE_SERVICE_0X23           STD_OFF

#if (defined DCM_DSP_USE_SERVICE_0X3D ) /* To prevent double declaration */
#error DCM_DSP_USE_SERVICE_0X3D  already defined
#endif /* if (defined DCM_DSP_USE_SERVICE_0X3D ) */

#define DCM_DSP_USE_SERVICE_0X3D           STD_OFF

#if (defined DCM_DSP_USE_SERVICE_0X2E ) /* To prevent double declaration */
#error DCM_DSP_USE_SERVICE_0X2E  already defined
#endif /* if (defined DCM_DSP_USE_SERVICE_0X2E ) */

#define DCM_DSP_USE_SERVICE_0X2E           STD_ON

#if (defined DCM_DSP_SERVICE_0X2E_ASYNC ) /* To prevent double declaration */
#error DCM_DSP_SERVICE_0X2E_ASYNC  already defined
#endif /* if (defined DCM_DSP_SERVICE_0X2E_ASYNC ) */

#define DCM_DSP_SERVICE_0X2E_ASYNC          STD_OFF

#if (defined DCM_DSP_USE_SERVICE_0X2F ) /* To prevent double declaration */
#error DCM_DSP_USE_SERVICE_0X2F  already defined
#endif /* if (defined DCM_DSP_USE_SERVICE_0X2F ) */

#define DCM_DSP_USE_SERVICE_0X2F           STD_ON

#if (defined DCM_DSP_SERVICE_0X2F_ASYNC ) /* To prevent double declaration */
#error DCM_DSP_SERVICE_0X2F_ASYNC  already defined
#endif /* if (defined DCM_DSP_SERVICE_0X2F_ASYNC ) */

#define DCM_DSP_SERVICE_0X2F_ASYNC         STD_OFF

#if (defined DCM_DSP_USE_SERVICE_0X31 ) /* To prevent double declaration */
#error DCM_DSP_USE_SERVICE_0X31  already defined
#endif /* if (defined DCM_DSP_USE_SERVICE_0X31 ) */

#define DCM_DSP_USE_SERVICE_0X31           STD_ON

#if (defined DCM_DSP_USE_SERVICE_0X11 ) /* To prevent double declaration */
#error DCM_DSP_USE_SERVICE_0X11  already defined
#endif /* if (defined DCM_DSP_USE_SERVICE_0X11 ) */

#define DCM_DSP_USE_SERVICE_0X11           STD_ON

#if (defined DCM_DSP_USE_SERVICE_0X34 ) /* To prevent double declaration */
#error DCM_DSP_USE_SERVICE_0X34  already defined
#endif /* if (defined DCM_DSP_USE_SERVICE_0X34 ) */

#define DCM_DSP_USE_SERVICE_0X34           STD_OFF

#if (defined DCM_DSP_USE_SERVICE_0X35 ) /* To prevent double declaration */
#error DCM_DSP_USE_SERVICE_0X35  already defined
#endif /* if (defined DCM_DSP_USE_SERVICE_0X35 ) */

#define DCM_DSP_USE_SERVICE_0X35           STD_OFF

#if (defined DCM_DSP_USE_SERVICE_0X36 ) /* To prevent double declaration */
#error DCM_DSP_USE_SERVICE_0X36  already defined
#endif /* if (defined DCM_DSP_USE_SERVICE_0X36 ) */

#define DCM_DSP_USE_SERVICE_0X36           STD_OFF

#if (defined DCM_DSP_USE_SERVICE_0X37 ) /* To prevent double declaration */
#error DCM_DSP_USE_SERVICE_0X37  already defined
#endif /* if (defined DCM_DSP_USE_SERVICE_0X37 ) */

#define DCM_DSP_USE_SERVICE_0X37           STD_OFF

#if (defined DCM_DSP_USE_SERVICE_0X28 ) /* To prevent double declaration */
#error DCM_DSP_USE_SERVICE_0X28  already defined
#endif /* if (defined DCM_DSP_USE_SERVICE_0X28 ) */

#define DCM_DSP_USE_SERVICE_0X28           STD_ON

#if (defined DCM_DSP_USE_SERVICE_0X2C) /* To prevent double declaration */
#error DCM_DSP_USE_SERVICE_0X2C  already defined
#endif /* if (defined DCM_DSP_USE_SERVICE_0X2C) */

#define DCM_DSP_USE_SERVICE_0X2C           STD_OFF

#if (defined DCM_DSP_USE_SERVICE_0X87 ) /* To prevent double declaration */
#error DCM_DSP_USE_SERVICE_0X87  already defined
#endif /* if (defined DCM_DSP_USE_SERVICE_0X87 ) */

#define DCM_DSP_USE_SERVICE_0X87           STD_OFF

#if (defined DCM_DSP_USE_SERVICE_0X86 ) /* To prevent double declaration */
#error DCM_DSP_USE_SERVICE_0X86  already defined
#endif /* if (defined DCM_DSP_USE_SERVICE_0X86 ) */

#define DCM_DSP_USE_SERVICE_0X86           STD_OFF

#if (defined DCM_DSP_USE_SERVICE_0X85 ) /* To prevent double declaration */
#error DCM_DSP_USE_SERVICE_0X85  already defined
#endif /* if (defined DCM_DSP_USE_SERVICE_0X85 ) */

#define DCM_DSP_USE_SERVICE_0X85           STD_ON

/* begin define macros for OBD services */
#if (defined DCM_DSP_USE_OBDSERVICES) /* To prevent double declaration */
#error DCM_DSP_USE_OBDSERVICES  already defined
#endif /* #if(defined DCM_DSP_USE_OBDSERVICES) */

#define DCM_DSP_USE_OBDSERVICES            STD_OFF
/* begin define macros for OBD data services (0x01, 0x02, 0x06, 0x08, 0x09) */
#if (defined DCM_DSP_USE_OBDDATASERVICES) /* To prevent double declaration */
#error DCM_DSP_USE_OBDDATASERVICES  already defined
#endif /* #if(defined DCM_DSP_USE_OBDDATASERVICES) */

#define DCM_DSP_USE_OBDDATASERVICES        STD_OFF
#if (defined DCM_DSP_USE_SERVICE_0X01) /* To prevent double declaration */
#error DCM_DSP_USE_SERVICE_0X01  already defined
#endif /* #if(defined DCM_DSP_USE_SERVICE_0X01) */

#define DCM_DSP_USE_SERVICE_0X01           STD_OFF

#if (defined DCM_DSP_USE_SERVICE_0X02) /* To prevent double declaration */
#error DCM_DSP_USE_SERVICE_0X02  already defined
#endif /* #if(defined DCM_DSP_USE_SERVICE_0X02) */

#define DCM_DSP_USE_SERVICE_0X02           STD_OFF

#if (defined DCM_DSP_USE_SERVICE_0X03) /* To prevent double declaration */
#error DCM_DSP_USE_SERVICE_0X03  already defined
#endif /* #if(defined DCM_DSP_USE_SERVICE_0X03) */

#define DCM_DSP_USE_SERVICE_0X03           STD_OFF

#if (defined DCM_DSP_USE_SERVICE_0X04) /* To prevent double declaration */
#error DCM_DSP_USE_SERVICE_0X04  already defined
#endif /* #if(defined DCM_DSP_USE_SERVICE_0X04) */

#define DCM_DSP_USE_SERVICE_0X04           STD_OFF

#if (defined DCM_DSP_USE_SERVICE_0X06) /* To prevent double declaration */
#error DCM_DSP_USE_SERVICE_0X06  already defined
#endif /* #if(defined DCM_DSP_USE_SERVICE_0X06) */

#define DCM_DSP_USE_SERVICE_0X06           STD_OFF

#if (defined DCM_DSP_SERVICE_0X06_ASYNC ) /* To prevent double declaration */
#error DCM_DSP_SERVICE_0X06_ASYNC  already defined
#endif /* if (defined DCM_DSP_SERVICE_0X06_ASYNC ) */

#define DCM_DSP_SERVICE_0X06_ASYNC         STD_OFF

#if (defined DCM_DSP_USE_SERVICE_0X07) /* To prevent double declaration */
#error DCM_DSP_USE_SERVICE_0X07  already defined
#endif /* #if(defined DCM_DSP_USE_SERVICE_0X07) */

#define DCM_DSP_USE_SERVICE_0X07           STD_OFF

#if (defined DCM_DSP_USE_SERVICE_0X08) /* To prevent double declaration */
#error DCM_DSP_USE_SERVICE_0X08  already defined
#endif /* #if(defined DCM_DSP_USE_SERVICE_0X08) */

#define DCM_DSP_USE_SERVICE_0X08           STD_OFF

#if (defined DCM_DSP_USE_SERVICE_0X0A) /* To prevent double declaration */
#error DCM_DSP_USE_SERVICE_0X0A  already defined
#endif /* #if(defined DCM_DSP_USE_SERVICE_0X0A) */

#define DCM_DSP_USE_SERVICE_0X0A           STD_OFF

#if (defined DCM_DSP_USE_SERVICE_0X09)
  #error "DCM_DSP_USE_SERVICE_0X09 is already defined"
#endif
#define DCM_DSP_USE_SERVICE_0X09           STD_OFF
/* end define macros for OBD services */

#if (defined DCM_EXTSVC_ENABLED ) /* To prevent double declaration */
#error DCM_EXTSVC_ENABLED  already defined
#endif /* if (defined DCM_EXTSVC_ENABLED ) */

/** \brief External handler is configured for any service or not */
#define DCM_EXTSVC_ENABLED           STD_OFF

#if (defined DCM_DSP_USE_DIDSERVICES ) /* To prevent double declaration */
#error DCM_DSP_USE_DIDSERVICES  already defined
#endif /* if (defined DCM_DSP_USE_DIDSERVICES ) */

/** \brief Indicates if there are internal service handlers enabled that need DID services */
#define DCM_DSP_USE_DIDSERVICES            STD_ON

#if (defined DCM_DSP_USE_MEMORYSERVICES ) /* To prevent double declaration */
#error DCM_DSP_USE_MEMORYSERVICES  already defined
#endif /* if (defined DCM_DSP_USE_MEMORYSERVICES ) */

/** \brief Indicates if there are internal service handlers enabled that need DID services */
#define DCM_DSP_USE_MEMORYSERVICES         STD_OFF

#if (defined DCM_DSP_USE_DATATRANSFERSERVICES ) /* To prevent double declaration */
#error DCM_DSP_USE_DATATRANSFERSERVICES  already defined
#endif /* if (defined DCM_DSP_USE_DATATRANSFERSERVICES ) */

/** \brief Indicates if there are internal service handlers enabled that need DID services */
#define DCM_DSP_USE_DATATRANSFERSERVICES   STD_OFF

#if (defined DCM_DSP_USE_DEMFACADE ) /* To prevent double declaration */
#error DCM_DSP_USE_DEMFACADE  already defined
#endif /* if (defined DCM_DSP_USE_DEMFACADE ) */

/** \brief Indicates if there are internal service handlers enabled that need DID services */
#define DCM_DSP_USE_DEMFACADE            STD_ON

#if (defined DCM_USE_API_CALLER_GENERIC_SVCH_IMPLEMENTATION) /* To prevent double declaration */
#error DCM_USE_API_CALLER_GENERIC_SVCH_IMPLEMENTATION  already defined
#endif /* if (defined DCM_USE_API_CALLER_GENERIC_SVCH_IMPLEMENTATION ) */

/** \brief Indicates if there are external service handlers enabled, that also have generic internal service handler enabled */
#define DCM_USE_API_CALLER_GENERIC_SVCH_IMPLEMENTATION STD_OFF

/** \brief This is a Vendor Specific parameter of the Dcm.
  *        Defines whether the DCM Module shall call Application default interfaces for each unsupported (unconfigured or unused)
  *        DID (Service 0x22 - ReadDataByIdentifier, Service 0x2E - WriteDataByIdentifier, Service 0x2F - InputOutputControlByIdentifier).
  *        - TRUE: DIDs which are not configured are considered supported and they are handled by the supplier.
  *        - FALSE: DIDs which are not configured are considered not supported. */

 #define DCM_REQUEST_SUPPLIER_DEFAULT_DID_READ  STD_OFF

/*------------------[Sub Services configured ]----------------------------------------------------*/

#if (defined DCM_DSP_SUBSERVICE_DIAGNOSTICSESSIONCONTROL_0x01 ) /* To prevent double declaration */
#error DCM_DSP_SUBSERVICE_DIAGNOSTICSESSIONCONTROL_0x01  already defined
#endif /* if (defined DCM_DSP_SUBSERVICE_DIAGNOSTICSESSIONCONTROL_0x01 ) */

/** \brief Subservice 0x01 for 0x10 enabled or not */
#define DCM_DSP_SUBSERVICE_DIAGNOSTICSESSIONCONTROL_0x01           STD_ON

#if (defined DCM_DSP_SUBSERVICE_DIAGNOSTICSESSIONCONTROL_0x02 ) /* To prevent double declaration */
#error DCM_DSP_SUBSERVICE_DIAGNOSTICSESSIONCONTROL_0x02  already defined
#endif /* if (defined DCM_DSP_SUBSERVICE_DIAGNOSTICSESSIONCONTROL_0x02 ) */

/** \brief Subservice 0x02 for 0x10 enabled or not */
#define DCM_DSP_SUBSERVICE_DIAGNOSTICSESSIONCONTROL_0x02           STD_ON

#if (defined DCM_DSP_SUBSERVICE_DIAGNOSTICSESSIONCONTROL_0x03 ) /* To prevent double declaration */
#error DCM_DSP_SUBSERVICE_DIAGNOSTICSESSIONCONTROL_0x03  already defined
#endif /* if (defined DCM_DSP_SUBSERVICE_DIAGNOSTICSESSIONCONTROL_0x03 ) */

/** \brief Subservice 0x03 for 0x10 enabled or not */
#define DCM_DSP_SUBSERVICE_DIAGNOSTICSESSIONCONTROL_0x03           STD_ON

#if (defined DCM_DSP_SUBSERVICE_DIAGNOSTICSESSIONCONTROL_0x2B ) /* To prevent double declaration */
#error DCM_DSP_SUBSERVICE_DIAGNOSTICSESSIONCONTROL_0x2B  already defined
#endif /* if (defined DCM_DSP_SUBSERVICE_DIAGNOSTICSESSIONCONTROL_0x2B ) */

/** \brief Subservice 0x2B for 0x10 enabled or not */
#define DCM_DSP_SUBSERVICE_DIAGNOSTICSESSIONCONTROL_0x2B           STD_OFF

#if (defined DCM_DSP_SUBSERVICE_DIAGNOSTICSESSIONCONTROL_0x2C ) /* To prevent double declaration */
#error DCM_DSP_SUBSERVICE_DIAGNOSTICSESSIONCONTROL_0x2C  already defined
#endif /* if (defined DCM_DSP_SUBSERVICE_DIAGNOSTICSESSIONCONTROL_0x2C ) */

/** \brief Subservice 0x2C for 0x10 enabled or not */
#define DCM_DSP_SUBSERVICE_DIAGNOSTICSESSIONCONTROL_0x2C           STD_OFF

#if (defined DCM_DSP_SUBSERVICE_HARDRESET_0x01 ) /* To prevent double declaration */
#error DCM_DSP_SUBSERVICE_HARDRESET_0x01  already defined
#endif /* if (defined DCM_DSP_SUBSERVICE_HARDRESET_0x01 ) */

/** \brief Subservice 0x01 for 0x11 enabled or not */
#define DCM_DSP_SUBSERVICE_HARDRESET_0x01           STD_ON

#if (defined DCM_DSP_SUBSERVICE_KEYOFFONRESET_0x02 ) /* To prevent double declaration */
#error DCM_DSP_SUBSERVICE_KEYOFFONRESET_0x02  already defined
#endif /* if (defined DCM_DSP_SUBSERVICE_KEYOFFONRESET_0x02 ) */

/** \brief Subservice 0x02 for 0x11 enabled or not */
#define DCM_DSP_SUBSERVICE_KEYOFFONRESET_0x02           STD_OFF

#if (defined DCM_DSP_SUBSERVICE_SOFTRESET_0x03 ) /* To prevent double declaration */
#error DCM_DSP_SUBSERVICE_SOFTRESET_0x03  already defined
#endif /* if (defined DCM_DSP_SUBSERVICE_SOFTRESET_0x03 ) */

/** \brief Subservice 0x03 for 0x11 enabled or not */
#define DCM_DSP_SUBSERVICE_SOFTRESET_0x03           STD_ON

#if (defined DCM_DSP_SUBSERVICE_ENABLERAPIDPOWERSHUTDOWN_0x04 ) /* To prevent double declaration */
#error DCM_DSP_SUBSERVICE_ENABLERAPIDPOWERSHUTDOWN_0x04  already defined
#endif /* if (defined DCM_DSP_SUBSERVICE_ENABLERAPIDPOWERSHUTDOWN_0x04 ) */

/** \brief Subservice 0x04 for 0x11 enabled or not */
#define DCM_DSP_SUBSERVICE_ENABLERAPIDPOWERSHUTDOWN_0x04           STD_OFF

#if (defined DCM_DSP_SUBSERVICE_DISABLERAPIDPOWERSHUTDOWN_0x05 ) /* To prevent double declaration */
#error DCM_DSP_SUBSERVICE_DISABLERAPIDPOWERSHUTDOWN_0x05  already defined
#endif /* if (defined DCM_DSP_SUBSERVICE_DISABLERAPIDPOWERSHUTDOWN_0x05 ) */

/** \brief Subservice 0x05 for 0x11 enabled or not */
#define DCM_DSP_SUBSERVICE_DISABLERAPIDPOWERSHUTDOWN_0x05           STD_OFF

#if (defined DCM_0X2C_0X01_SSVC_ENABLED) /* To prevent double declaration */
#error DCM_0X2C_0X01_SSVC_ENABLED already defined
#endif /* if (defined DCM_0X2C_0X01_SSVC_ENABLED) */

/** \brief Subservice 0x01 for 0x2C enabled or not */
#define DCM_0X2C_0X01_SSVC_ENABLED           STD_OFF

#if (defined DCM_0X2C_0X02_SSVC_ENABLED) /* To prevent double declaration */
#error DCM_0X2C_0X02_SSVC_ENABLED already defined
#endif /* if (defined DCM_0X2C_0X02_SSVC_ENABLED) */

/** \brief Subservice 0x02 for 0x2C enabled or not */
#define DCM_0X2C_0X02_SSVC_ENABLED           STD_OFF

#if (defined DCM_0X2C_0X03_SSVC_ENABLED) /* To prevent double declaration */
#error DCM_0X2C_0X03_SSVC_ENABLED already defined
#endif /* if (defined DCM_0X2C_0X03_SSVC_ENABLED) */

/** \brief Subservice 0x03 for 0x2C enabled or not */
#define DCM_0X2C_0X03_SSVC_ENABLED           STD_OFF

#if (defined DCM_DSP_SUBSERVICE_READDTCINFORMATION_0x01 ) /* To prevent double declaration */
#error DCM_DSP_SUBSERVICE_READDTCINFORMATION_0x01  already defined
#endif /* if (defined DCM_DSP_SUBSERVICE_READDTCINFORMATION_0x01 ) */

/** \brief Subservice 0x01 for 0x19 enabled or not */
#define DCM_DSP_SUBSERVICE_READDTCINFORMATION_0x01           STD_ON

#if (defined DCM_DSP_SUBSERVICE_READDTCINFORMATION_0x02 ) /* To prevent double declaration */
#error DCM_DSP_SUBSERVICE_READDTCINFORMATION_0x02  already defined
#endif /* if (defined DCM_DSP_SUBSERVICE_READDTCINFORMATION_0x02 ) */

/** \brief Subservice 0x02 for 0x19 enabled or not */
#define DCM_DSP_SUBSERVICE_READDTCINFORMATION_0x02           STD_ON

#if (defined DCM_DSP_SUBSERVICE_READDTCINFORMATION_0x03 ) /* To prevent double declaration */
#error DCM_DSP_SUBSERVICE_READDTCINFORMATION_0x03  already defined
#endif /* if (defined DCM_DSP_SUBSERVICE_READDTCINFORMATION_0x03 ) */

/** \brief Subservice 0x03 for 0x19 enabled or not */
#define DCM_DSP_SUBSERVICE_READDTCINFORMATION_0x03           STD_OFF

#if (defined DCM_DSP_SUBSERVICE_READDTCINFORMATION_0x04 ) /* To prevent double declaration */
#error DCM_DSP_SUBSERVICE_READDTCINFORMATION_0x04  already defined
#endif /* if (defined DCM_DSP_SUBSERVICE_READDTCINFORMATION_0x04 ) */

/** \brief Subservice 0x04 for 0x19 enabled or not */
#define DCM_DSP_SUBSERVICE_READDTCINFORMATION_0x04           STD_ON

#if (defined DCM_DSP_SUBSERVICE_READDTCINFORMATION_0x06 ) /* To prevent double declaration */
#error DCM_DSP_SUBSERVICE_READDTCINFORMATION_0x06  already defined
#endif /* if (defined DCM_DSP_SUBSERVICE_READDTCINFORMATION_0x06 ) */

/** \brief Subservice 0x06 for 0x19 enabled or not */
#define DCM_DSP_SUBSERVICE_READDTCINFORMATION_0x06           STD_ON

#if (defined DCM_DSP_SUBSERVICE_READDTCINFORMATION_0x07 ) /* To prevent double declaration */
#error DCM_DSP_SUBSERVICE_READDTCINFORMATION_0x07  already defined
#endif /* if (defined DCM_DSP_SUBSERVICE_READDTCINFORMATION_0x07 ) */

/** \brief Subservice 0x07 for 0x19 enabled or not */
#define DCM_DSP_SUBSERVICE_READDTCINFORMATION_0x07           STD_OFF

#if (defined DCM_DSP_SUBSERVICE_READDTCINFORMATION_0x08 ) /* To prevent double declaration */
#error DCM_DSP_SUBSERVICE_READDTCINFORMATION_0x08  already defined
#endif /* if (defined DCM_DSP_SUBSERVICE_READDTCINFORMATION_0x08 ) */

/** \brief Subservice 0x08 for 0x19 enabled or not */
#define DCM_DSP_SUBSERVICE_READDTCINFORMATION_0x08           STD_OFF

#if (defined DCM_DSP_SUBSERVICE_READDTCINFORMATION_0x09 ) /* To prevent double declaration */
#error DCM_DSP_SUBSERVICE_READDTCINFORMATION_0x09  already defined
#endif /* if (defined DCM_DSP_SUBSERVICE_READDTCINFORMATION_0x09 ) */

/** \brief Subservice 0x09 for 0x19 enabled or not */
#define DCM_DSP_SUBSERVICE_READDTCINFORMATION_0x09           STD_OFF

#if (defined DCM_DSP_SUBSERVICE_READDTCINFORMATION_0x0A ) /* To prevent double declaration */
#error DCM_DSP_SUBSERVICE_READDTCINFORMATION_0x0A  already defined
#endif /* if (defined DCM_DSP_SUBSERVICE_READDTCINFORMATION_0x0A ) */

/** \brief Subservice 0x0A for 0x19 enabled or not */
#define DCM_DSP_SUBSERVICE_READDTCINFORMATION_0x0A           STD_ON

#if (defined DCM_DSP_SUBSERVICE_READDTCINFORMATION_0x0B ) /* To prevent double declaration */
#error DCM_DSP_SUBSERVICE_READDTCINFORMATION_0x0B  already defined
#endif /* if (defined DCM_DSP_SUBSERVICE_READDTCINFORMATION_0x0B ) */

/** \brief Subservice 0x0B for 0x19 enabled or not */
#define DCM_DSP_SUBSERVICE_READDTCINFORMATION_0x0B           STD_OFF

#if (defined DCM_DSP_SUBSERVICE_READDTCINFORMATION_0x0C ) /* To prevent double declaration */
#error DCM_DSP_SUBSERVICE_READDTCINFORMATION_0x0C  already defined
#endif /* if (defined DCM_DSP_SUBSERVICE_READDTCINFORMATION_0x0C ) */

/** \brief Subservice 0x0C for 0x19 enabled or not */
#define DCM_DSP_SUBSERVICE_READDTCINFORMATION_0x0C           STD_OFF

#if (defined DCM_DSP_SUBSERVICE_READDTCINFORMATION_0x0D ) /* To prevent double declaration */
#error DCM_DSP_SUBSERVICE_READDTCINFORMATION_0x0D  already defined
#endif /* if (defined DCM_DSP_SUBSERVICE_READDTCINFORMATION_0x0D ) */

/** \brief Subservice 0x0D for 0x19 enabled or not */
#define DCM_DSP_SUBSERVICE_READDTCINFORMATION_0x0D           STD_OFF

#if (defined DCM_DSP_SUBSERVICE_READDTCINFORMATION_0x0E ) /* To prevent double declaration */
#error DCM_DSP_SUBSERVICE_READDTCINFORMATION_0x0E  already defined
#endif /* if (defined DCM_DSP_SUBSERVICE_READDTCINFORMATION_0x0E ) */

/** \brief Subservice 0x0E for 0x19 enabled or not */
#define DCM_DSP_SUBSERVICE_READDTCINFORMATION_0x0E           STD_OFF

#if (defined DCM_DSP_SUBSERVICE_READDTCINFORMATION_0x13 ) /* To prevent double declaration */
#error DCM_DSP_SUBSERVICE_READDTCINFORMATION_0x13  already defined
#endif /* if (defined DCM_DSP_SUBSERVICE_READDTCINFORMATION_0x13 ) */

/** \brief Subservice 0x13 for 0x19 enabled or not */
#define DCM_DSP_SUBSERVICE_READDTCINFORMATION_0x13           STD_OFF

#if (defined DCM_DSP_SUBSERVICE_READDTCINFORMATION_0x14 ) /* To prevent double declaration */
#error DCM_DSP_SUBSERVICE_READDTCINFORMATION_0x14  already defined
#endif /* if (defined DCM_DSP_SUBSERVICE_READDTCINFORMATION_0x14 ) */

/** \brief Subservice 0x14 for 0x19 enabled or not */
#define DCM_DSP_SUBSERVICE_READDTCINFORMATION_0x14           STD_OFF

#if (defined DCM_DSP_SUBSERVICE_READDTCINFORMATION_0x15 ) /* To prevent double declaration */
#error DCM_DSP_SUBSERVICE_READDTCINFORMATION_0x15  already defined
#endif /* if (defined DCM_DSP_SUBSERVICE_READDTCINFORMATION_0x15 ) */

/** \brief Subservice 0x15 for 0x19 enabled or not */
#define DCM_DSP_SUBSERVICE_READDTCINFORMATION_0x15           STD_OFF

#if (defined DCM_DSP_SUBSERVICE_READDTCINFORMATION_0x17 ) /* To prevent double declaration */
#error DCM_DSP_SUBSERVICE_READDTCINFORMATION_0x17  already defined
#endif /* if (defined DCM_DSP_SUBSERVICE_READDTCINFORMATION_0x17 ) */

/** \brief Subservice 0x17 for 0x19 enabled or not */
#define DCM_DSP_SUBSERVICE_READDTCINFORMATION_0x17           STD_OFF

#if (defined DCM_DSP_SUBSERVICE_READDTCINFORMATION_0x18 ) /* To prevent double declaration */
#error DCM_DSP_SUBSERVICE_READDTCINFORMATION_0x18  already defined
#endif /* if (defined DCM_DSP_SUBSERVICE_READDTCINFORMATION_0x18 ) */

/** \brief Subservice 0x18 for 0x19 enabled or not */
#define DCM_DSP_SUBSERVICE_READDTCINFORMATION_0x18           STD_OFF

#if (defined DCM_DSP_SUBSERVICE_READDTCINFORMATION_0x19 ) /* To prevent double declaration */
#error DCM_DSP_SUBSERVICE_READDTCINFORMATION_0x19  already defined
#endif /* if (defined DCM_DSP_SUBSERVICE_READDTCINFORMATION_0x19 ) */

/** \brief Subservice 0x19 for 0x19 enabled or not */
#define DCM_DSP_SUBSERVICE_READDTCINFORMATION_0x19           STD_OFF

/* !LINKSTO Dcm.EB.ReadDTC.ProcPageFunc,1 */
#if (defined DCM_DSP_SUBSERVICES_READDTCINFORMATION_EXTSVC_ENABLED ) /* To prevent double declaration */
#error DCM_DSP_SUBSERVICES_READDTCINFORMATION_EXTSVC_ENABLED  already defined
#endif /* if (defined DCM_DSP_SUBSERVICES_READDTCINFORMATION_EXTSVC_ENABLED ) */

/** \brief External handlers are enabled for all subservices for 0x19  */
#define DCM_DSP_SUBSERVICES_READDTCINFORMATION_EXTSVC_ENABLED             STD_OFF

#if (defined DCM_DSP_SUBSERVICE_RESPONSEONEVENT_0x05 ) /* To prevent double declaration */
#error DCM_DSP_SUBSERVICE_RESPONSEONEVENT_0x05  already defined
#endif /* if (defined DCM_DSP_SUBSERVICE_RESPONSEONEVENT_0x05 ) */

/** \brief Subservice 0x05 for 0x86 enabled or not */
#define DCM_DSP_SUBSERVICE_RESPONSEONEVENT_0x05           STD_OFF

#if (defined DCM_DSP_SUBSERVICE_RESPONSEONEVENT_0x45 ) /* To prevent double declaration */
#error DCM_DSP_SUBSERVICE_RESPONSEONEVENT_0x45  already defined
#endif /* if (defined DCM_DSP_SUBSERVICE_RESPONSEONEVENT_0x45 ) */

/** \brief Subservice 0x45 for 0x86 enabled or not */
#define DCM_DSP_SUBSERVICE_RESPONSEONEVENT_0x45           STD_OFF

#if (defined DCM_DSP_SUBSERVICE_RESPONSEONEVENT_0x00 ) /* To prevent double declaration */
#error DCM_DSP_SUBSERVICE_RESPONSEONEVENT_0x00  already defined
#endif /* if (defined DCM_DSP_SUBSERVICE_RESPONSEONEVENT_0x00 ) */

/** \brief Subservice 0x00 for 0x86 enabled or not */
#define DCM_DSP_SUBSERVICE_RESPONSEONEVENT_0x00           STD_OFF

#if (defined DCM_DSP_SUBSERVICE_RESPONSEONEVENT_0x40 ) /* To prevent double declaration */
#error DCM_DSP_SUBSERVICE_RESPONSEONEVENT_0x40  already defined
#endif /* if (defined DCM_DSP_SUBSERVICE_RESPONSEONEVENT_0x40 ) */

/** \brief Subservice 0x40 for 0x86 enabled or not */
#define DCM_DSP_SUBSERVICE_RESPONSEONEVENT_0x40           STD_OFF

#if (defined DCM_DSP_SUBSERVICE_RESPONSEONEVENT_0x01 ) /* To prevent double declaration */
#error DCM_DSP_SUBSERVICE_RESPONSEONEVENT_0x01  already defined
#endif /* if (defined DCM_DSP_SUBSERVICE_RESPONSEONEVENT_0x01 ) */

/** \brief Subservice 0x01 for 0x86 enabled or not */
#define DCM_DSP_SUBSERVICE_RESPONSEONEVENT_0x01           STD_OFF

#if (defined DCM_DSP_SUBSERVICE_RESPONSEONEVENT_0x41 ) /* To prevent double declaration */
#error DCM_DSP_SUBSERVICE_RESPONSEONEVENT_0x41  already defined
#endif /* if (defined DCM_DSP_SUBSERVICE_RESPONSEONEVENT_0x41 ) */

/** \brief Subservice 0x41 for 0x86 enabled or not */
#define DCM_DSP_SUBSERVICE_RESPONSEONEVENT_0x41           STD_OFF

#if (defined DCM_DSP_SUBSERVICE_RESPONSEONEVENT_0x03 ) /* To prevent double declaration */
#error DCM_DSP_SUBSERVICE_RESPONSEONEVENT_0x03  already defined
#endif /* if (defined DCM_DSP_SUBSERVICE_RESPONSEONEVENT_0x03 ) */

/** \brief Subservice 0x03 for 0x86 enabled or not */
#define DCM_DSP_SUBSERVICE_RESPONSEONEVENT_0x03           STD_OFF

#if (defined DCM_DSP_SUBSERVICE_RESPONSEONEVENT_0x43 ) /* To prevent double declaration */
#error DCM_DSP_SUBSERVICE_RESPONSEONEVENT_0x43  already defined
#endif /* if (defined DCM_DSP_SUBSERVICE_RESPONSEONEVENT_0x43 ) */

/** \brief Subservice 0x43 for 0x86 enabled or not */
#define DCM_DSP_SUBSERVICE_RESPONSEONEVENT_0x43           STD_OFF

#if (defined DCM_DSP_SUBSERVICE_RESPONSEONEVENT_0x04 ) /* To prevent double declaration */
#error DCM_DSP_SUBSERVICE_RESPONSEONEVENT_0x04  already defined
#endif /* if (defined DCM_DSP_SUBSERVICE_RESPONSEONEVENT_0x04 ) */

/** \brief Subservice 0x04 for 0x86 enabled or not */
#define DCM_DSP_SUBSERVICE_RESPONSEONEVENT_0x04           STD_OFF

#if (defined DCM_DSP_SUBSERVICE_RESPONSEONEVENT_0x06 ) /* To prevent double declaration */
#error DCM_DSP_SUBSERVICE_RESPONSEONEVENT_0x06  already defined
#endif /* if (defined DCM_DSP_SUBSERVICE_RESPONSEONEVENT_0x06 ) */

/** \brief Subservice 0x06 for 0x86 enabled or not */
#define DCM_DSP_SUBSERVICE_RESPONSEONEVENT_0x06           STD_OFF

#if (defined DCM_0X85_0X01_SSVC_ENABLED ) /* To prevent double declaration */
#error DCM_0X85_0X01_SSVC_ENABLED  already defined
#endif /* if (defined DCM_0X85_0X01_SSVC_ENABLED ) */

/** \brief Subservice 0x01 for 0x85 enabled or not */
#define DCM_0X85_0X01_SSVC_ENABLED           STD_ON

#if (defined DCM_0X85_0X02_SSVC_ENABLED ) /* To prevent double declaration */
#error DCM_0X85_0X02_SSVC_ENABLED  already defined
#endif /* if (defined DCM_0X85_0X02_SSVC_ENABLED ) */

/** \brief Subservice 0x02 for 0x85 enabled or not */
#define DCM_0X85_0X02_SSVC_ENABLED           STD_ON

#if (defined DCM_0X85_CONTROLOPTIONRECORD_ENABLED ) /* To prevent double declaration */
#error DCM_0X85_CONTROLOPTIONRECORD_ENABLED  already defined
#endif /* if (defined DCM_0X85_CONTROLOPTIONRECORD_ENABLED ) */

/** \brief ControlOptionRecord enabled or not */
#define DCM_0X85_CONTROLOPTIONRECORD_ENABLED           STD_OFF
#if (defined DCM_0X85_CONTROLOPTIONRECORD_SIZE ) /* To prevent double declaration */
#error DCM_0X85_CONTROLOPTIONRECORD_SIZE  already defined
#endif /* if (defined DCM_0X85_CONTROLOPTIONRECORD_SIZE ) */

/** \brief size of ControlOptionRecord in the request */
#define DCM_0X85_CONTROLOPTIONRECORD_SIZE           0U

#if (defined DCM_DSP_SUBSERVICE_LINKCONTROL_0x01 ) /* To prevent double declaration */
#error DCM_DSP_SUBSERVICE_LINKCONTROL_0x01  already defined
#endif /* if (defined DCM_DSP_SUBSERVICE_LINKCONTROL_0x01 ) */

#define DCM_DSP_SUBSERVICE_LINKCONTROL_0x01           STD_OFF

#if (defined DCM_DSP_SUBSERVICE_LINKCONTROL_0x02 ) /* To prevent double declaration */
#error DCM_DSP_SUBSERVICE_LINKCONTROL_0x02  already defined
#endif /* if (defined DCM_DSP_SUBSERVICE_LINKCONTROL_0x02 ) */

#define DCM_DSP_SUBSERVICE_LINKCONTROL_0x02           STD_OFF

#if (defined DCM_DSP_SUBSERVICE_LINKCONTROL_0x03 ) /* To prevent double declaration */
#error DCM_DSP_SUBSERVICE_LINKCONTROL_0x03  already defined
#endif /* if (defined DCM_DSP_SUBSERVICE_LINKCONTROL_0x03 ) */

#define DCM_DSP_SUBSERVICE_LINKCONTROL_0x03           STD_OFF

#if (defined DCM_BSWM_API_ENABLED ) /* To prevent double declaration */
#error DCM_BSWM_API_ENABLED  already defined
#endif /* if defined (DCM_BSWM_API_ENABLED ) */

/** \brief BswM-Dcm interaction enabled or not */
#define DCM_BSWM_API_ENABLED           STD_ON

#if (defined DCM_0XAF_EXT_SSVCH_ENABLED ) /* To prevent double declaration */
#error DCM_0XAF_EXT_SSVCH_ENABLED  already defined
#endif /* if (defined DCM_0XAF_EXT_SSVCH_ENABLED ) */

/** \brief External Subservice for 0xAF enabled or not */
#define DCM_0XAF_EXT_SSVCH_ENABLED           STD_OFF

#if (defined DATA_TRANSFER_SERVICES_AUTOSAR_403)
#error DATA_TRANSFER_SERVICES_AUTOSAR_403 already defined
#endif
/** \brief Macro for using ASR 4.0 for DataTransfer services */
#define DATA_TRANSFER_SERVICES_AUTOSAR_403 0U

#if (defined DATA_TRANSFER_SERVICES_AUTOSAR_422)
#error DATA_TRANSFER_SERVICES_AUTOSAR_422 already defined
#endif
/** \brief Macro for using ASR 4.2.2 for DataTransfer services */
#define DATA_TRANSFER_SERVICES_AUTOSAR_422 1U

#if (defined DATA_TRANSFER_SERVICES_AUTOSAR_430)
#error DATA_TRANSFER_SERVICES_AUTOSAR_430 already defined
#endif
/** \brief Macro for using ASR 4.3 for DataTransfer services */
#define DATA_TRANSFER_SERVICES_AUTOSAR_430 2U

#if (defined DCM_DATATRANSFER_SERVICES_ASR_VERSION)
#error DCM_DATATRANSFER_SERVICES_ASR_VERSION already defined
#endif
/** \brief ASR version compatibility for DataTransfer services */
#define DCM_DATATRANSFER_SERVICES_ASR_VERSION                   DATA_TRANSFER_SERVICES_AUTOSAR_403

#if (defined DCM_ENABLE_DATA_TRANSFER_MEMRANGE_AND_SECURITY_CHECK)
#error DCM_ENABLE_DATA_TRANSFER_MEMRANGE_AND_SECURITY_CHECK already defined
#endif
/** \brief Define whether memory range and security checks
 ** are enabled for RequestDownload and RequestUpload */
#define DCM_ENABLE_DATA_TRANSFER_MEMRANGE_AND_SECURITY_CHECK                   STD_OFF
#if (defined DCM_ENABLE_DATA_TRANSFER_MEM_ID_CHECK)
#error DCM_ENABLE_DATA_TRANSFER_MEM_ID_CHECK already defined
#endif
/** \brief Define whether memory Id check is enabled for RequestDownload and RequestUpload */
#define DCM_ENABLE_DATA_TRANSFER_MEM_ID_CHECK                   STD_OFF
/*------------------[ Service API ]----------------------------------------------------*/

#if (defined DCM_SERVICE_API_NONE)
#error DCM_SERVICE_API_NONE already defined
#endif
/** \brief Definition that no default service API is set */
#define DCM_SERVICE_API_NONE   0U

#if (defined DCM_SERVICE_API_ASR40)
#error DCM_SERVICE_API_ASR40 already defined
#endif
/** \brief Definition that AUTOSAR 4.0 service API is set as default */
#define DCM_SERVICE_API_ASR40 40U

#if (defined DCM_SERVICE_API_ASR42)
#error DCM_SERVICE_API_ASR42 already defined
#endif
/** \brief Definition that AUTOSAR 4.2 service API is set as default */
#define DCM_SERVICE_API_ASR42 42U

#if (defined DCM_ISO14229_2006)
#error DCM_ISO14229_2006 already defined
#endif
/** \brief Definition that ISO14229_2006 is set */
#define DCM_ISO14229_2006 6U

#if (defined DCM_ISO14229_2013)
#error DCM_ISO14229_2013 already defined
#endif
/** \brief Definition that ISO14229_2013 is set */
#define DCM_ISO14229_2013 13U

#if (defined DCM_ENABLE_ASR40_SERVICE_API)
#error DCM_ENABLE_ASR40_SERVICE_API already defined
#endif
/** \brief Definition whether AUTOSAR 4.0 service API for Dcm is enabled */
#define DCM_ENABLE_ASR40_SERVICE_API                   STD_OFF
#if (defined DCM_ENABLE_ASR42_SERVICE_API)
#error DCM_ENABLE_ASR42_SERVICE_API already defined
#endif
/** \brief Definition whether AUTOSAR 4.2 service API for Dcm is enabled */
#define DCM_ENABLE_ASR42_SERVICE_API                   STD_OFF
#if (defined DCM_DEFAULT_ASR_SERVICE_API)
#error DCM_DEFAULT_ASR_SERVICE_API already defined
#endif
/** \brief Definition of default service API */
#define DCM_DEFAULT_ASR_SERVICE_API                    DCM_SERVICE_API_ASR40

#if (defined DCM_NRC_POLICY_ISO_VERSION)
#error DCM_NRC_POLICY_ISO_VERSION already defined
#endif
/** \brief Definition of ISO ISO14229_2006 or ISO14229_2013*/
#define DCM_NRC_POLICY_ISO_VERSION        DCM_ISO14229_2013

#if (defined DCM_DSP_SRV_TABLES_USED_BUF_SIZE) /* To prevent double declaration */
#error DCM_DSP_SRV_TABLES_USED_BUF_SIZE already defined
#endif /* if (defined DCM_DSP_SRV_TABLES_USED_BUF_SIZE) */
/** \brief Size of Service Tables Used Buffer */
#define DCM_DSP_SRV_TABLES_USED_BUF_SIZE 1U

#if (defined DCM_DSP_SERVICE_USED_BUF_SIZE) /* To prevent double declaration */
#error DCM_DSP_SERVICE_USED_BUF_SIZE already defined
#endif /* if (defined DCM_DSP_SERVICE_USED_BUF_SIZE) */
/** \brief Maximum Size of Service Used Buffer for a Service Table */
#define DCM_DSP_SERVICE_USED_BUF_SIZE 2U

/*------------------[ Service $01 ]----------------------------------------------------*/

#if (defined DCM_NUM_PID_CFG)
#error DCM_NUM_PID_CFG already defined
#endif /* if (defined DCM_NUM_PID_CFG) */

/** \brief Number of PIDs configured */
#define DCM_NUM_PID_CFG             0U

#if (defined DCM_DSP_PID_DATA_NUM) /* To prevent double declaration */
#error DCM_DSP_PID_DATA_NUM already defined
#endif /* if (defined DCM_DSP_PID_DATA_NUM) */

/** \brief Number of PID Data configured */
#define DCM_DSP_PID_DATA_NUM 0U

#if (defined DCM_DSP_PID_USED_BUF_SIZE) /* To prevent double declaration */
#error DCM_DSP_PID_USED_BUF_SIZE already defined
#endif /* if (defined DCM_DSP_PID_USED_BUF_SIZE) */

/** \brief Size of Pid Used Buffer */
#define DCM_DSP_PID_USED_BUF_SIZE 0U

#if (defined DCM_DSP_PID_SUPINFO_DATA_NUM) /* To prevent double declaration */
#error DCM_DSP_PID_SUPINFO_DATA_NUM already defined
#endif /* if (defined DCM_DSP_PID_SUPINFO_DATA_NUM) */

/** \brief Number of Elements in SupportInfoData Array */
#define DCM_DSP_PID_SUPINFO_DATA_NUM 0U

#if (defined DCM_DSP_PID_SUPINFO_CONFIG_NUM) /* To prevent double declaration */
#error DCM_DSP_PID_SUPINFO_CONFIG_NUM already defined
#endif /* if (defined DCM_DSP_PID_SUPINFO_CONFIG_NUM) */

/** \brief Number of SupInfo Config */
#define DCM_DSP_PID_SUPINFO_CONFIG_NUM 0U

#if (defined DCM_PID_DATA_MAX_SIZE) /* To prevent double declaration */
#error DCM_PID_DATA_MAX_SIZE already defined
#endif /* if (defined DCM_PID_DATA_MAX_SIZE) */

/* !LINKSTO Dcm.Dsn.OBDPidServices.PidDataBufferSize,1 */
/** \brief Maximum size of a PID Data configured in bytes */
#define DCM_PID_DATA_MAX_SIZE      0U

/** \brief OBD Service $08 Support */
#if (defined DCM_DSP_NUM_REQUESTCONTROL_CFG)
#error DCM_DSP_NUM_REQUESTCONTROL_CFG already defined
#endif /* if (defined DCM_DSP_NUM_REQUESTCONTROL_CFG) */

/** \brief Number of RequestControl items configured */
#define DCM_DSP_NUM_REQUESTCONTROL_CFG             0U

/*------------------[ Complex conditions ]----------------------------------------------------*/

#if (defined DCM_DSP_USE_ADDRESSLENGTHANDFORMAT_VERIFICATION ) /* To prevent double declaration */
#error DCM_DSP_USE_ADDRESSLENGTHANDFORMAT_VERIFICATION  already defined
#endif /* if (defined DCM_DSP_USE_ADDRESSLENGTHANDFORMAT_VERIFICATION ) */

/** \brief Indicates whether AddressLengthAndFormat_Verification is required or not  */
#define DCM_DSP_USE_ADDRESSLENGTHANDFORMAT_VERIFICATION           STD_OFF

#if (defined DCM_DSP_USE_GETMEMORYADDRESSANDSIZE ) /* To prevent double declaration */
#error DCM_DSP_USE_GETMEMORYADDRESSANDSIZE  already defined
#endif /* if (defined DCM_DSP_USE_GETMEMORYADDRESSANDSIZE ) */

/** \brief Indicates whether GetMemoryAddressAndSize is required or not  */
#define DCM_DSP_USE_GETMEMORYADDRESSANDSIZE           STD_OFF

/*-----------[  Dynamically defined DID initialization related configuration items ]--------------*/

/** \brief Defines the existence of configured S3 timeout notification callout function. */
#if (defined DCM_S3TIMEOUTNOTIFICATION)
  #error "DCM_S3TIMEOUTNOTIFICATION is already defined"
#endif
#define DCM_S3TIMEOUTNOTIFICATION     STD_OFF

#if (defined DCM_META_DATA_HANDLING_ENABLED)
  #error "DCM_META_DATA_HANDLING_ENABLED is already defined"
#endif
#define DCM_META_DATA_HANDLING_ENABLED         STD_OFF
/*==================[type definitions]===========================================================*/
/** \brief Define the size of the read scaling info */
typedef uint8 Dcm_ReadScalingSignalSizeType;

/*------------------[Dcm_ConfigType]----------------------------------------*/

/** \brief This type of the external data structure shall contain the post
 **  build initialization data for the Dcm.
 **
 ** \note Type is unused, as only pre-compile time support is implemented. */
typedef uint8 Dcm_ConfigType;

/*==================[external function declarations]=============================================*/

#define DCM_START_SEC_CODE
#include <Dcm_MemMap.h>

extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DefaultSessionModeEntry(void);

extern FUNC(Std_ReturnType, DCM_CODE) Dcm_ExtendedDiagnosticSessionModeEntry(void);

extern FUNC(Std_ReturnType, DCM_CODE) Dcm_ProgrammingSessionModeEntry(void);

#define DCM_STOP_SEC_CODE
#include <Dcm_MemMap.h>

/*==================[internal function declarations]=============================================*/

/*==================[external constants]=========================================================*/

#define DCM_START_SEC_CONST_8
#include <Dcm_MemMap.h>

/** \brief Configuration structure */
extern CONST(Dcm_ConfigType, DCM_CONST) DcmConfigSet_0;

#define DCM_STOP_SEC_CONST_8
#include <Dcm_MemMap.h>

/*==================[internal data]==============================================================*/

#if (defined DCM_WRITEMIDBEFORETID_ENABLED)
#error DCM_WRITEMIDBEFORETID_ENABLED already defined
#endif /* if (defined DCM_WRITEMIDBEFORETID_ENABLED) */

/** \brief Flage indicates whether OBDMID shall be written before every TID,
 * in case it's requested via service 0x22. */
#define DCM_WRITEMIDBEFORETID_ENABLED             FALSE

/* !LINKSTO Dcm.dsn.OBDMIDSupport,1 */
#if (defined DCM_OBDMID_SUPPORT_SWC)
#error DCM_OBDMID_SUPPORT_SWC already defined
#endif
/* define SWC support to obtain info for Obdmids */
#define DCM_OBDMID_SUPPORT_SWC                          STD_OFF

/* This macro tells if the used Pdu router is supplied by Elektrobit or not. Elektrobit has vendorID '1' */
#if (defined DCM_USE_ELEKTROBIT_SUPPLIED_PDUR)
#error DCM_USE_ELEKTROBIT_SUPPLIED_PDUR already defined
#endif
#define DCM_USE_ELEKTROBIT_SUPPLIED_PDUR                STD_ON
/** \brief This macro is defined when the defined upper limits of the defined memory ranges are to be
* excluded from the defined range. */
#if (defined DCM_EXCLUDE_UPPER_LIMITS)
#error DCM_EXCLUDE_UPPER_LIMITS already defined
#endif

#define DCM_EXCLUDE_UPPER_LIMITS                          STD_OFF
/*==================[external function definitions]==============================================*/


/*==================[internal function definitions]==============================================*/

#endif /* ifndef DCM_CFG_H */
/*==================[end of file]================================================================*/
