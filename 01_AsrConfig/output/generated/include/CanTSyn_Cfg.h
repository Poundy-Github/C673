/**
 * \file
 *
 * \brief AUTOSAR CanTSyn
 *
 * This file contains the implementation of the AUTOSAR
 * module CanTSyn.
 *
 * \version 3.0.0
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2021 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */


#ifndef CANTSYN_CFG_H
#define CANTSYN_CFG_H

/*==================[includes]==============================================*/




#include <TSAutosar.h>              /* global configuration */
#include <CanTSyn_Types.h>

/*==================[macros]=================================================*/

#if (defined CANTSYN_DEV_ERROR_DETECT) /* to prevent double declaration */
#error CANTSYN_DEV_ERROR_DETECT is already defined
#endif /* if (defined CANTSYN_DEV_ERROR_DETECT) */

/** \brief Switch for DET usage */ /* !LINKSTO CanTSyn.ASR20-11.ECUC_CanTSyn_00002,1 */
#define CANTSYN_DEV_ERROR_DETECT        STD_OFF

#if (defined CANTSYN_VERSION_INFO_API)
#error CANTSYN_VERSION_INFO_API is already defined
#endif /* if (defined CANTSYN_VERSION_INFO_API) */

/** \brief Support of CanTSyn_GetVersionInfo()
  ** This constant defines whether the CanTSyn_GetVersionInfo is
  ** provided.
  ** STD_ON    Function is provided
  ** STD_OFF   Function is not provided
*/
/* !LINKSTO CanTSyn.ASR20-11.ECUC_CanTSyn_00023,1 */
#define CANTSYN_VERSION_INFO_API       STD_OFF

#if (defined CANTSYN_TX_CRC_USED)
#error CANTSYN_TX_CRC_USED is already defined
#endif /* if (defined CANTSYN_TX_CRC_USED) */

/** \brief Support of Crc_CalculateCRC8H2F()
  ** This constant defines whether the Crc_CalculateCRC8H2F is
  ** used for the master feature.
  ** STD_ON    Function is used
  ** STD_OFF   Function is not used
*/
#define CANTSYN_TX_CRC_USED            STD_OFF

#if (defined CANTSYN_TX_IMMEDIATE_TRANSMISSION)
#error CANTSYN_TX_IMMEDIATE_TRANSMISSION is already defined
#endif /* if (defined CANTSYN_TX_IMMEDIATE_TRANSMISSION) */

 /** \brief Support for immediate transmission of TimeSync messages.
   ** This constant defines whether Immediate Transmission is
   ** supported for the master feature or not.
   ** STD_ON    Immediate Transmission is used
   ** STD_OFF   Immediate Transmission is not used
 */
#define CANTSYN_TX_IMMEDIATE_TRANSMISSION   STD_OFF


#if (defined CANTSYN_RX_CRC_USED)
#error CANTSYN_RX_CRC_USED is already defined
#endif /* if (defined CANTSYN_RX_CRC_USED) */

/** \brief Support of Crc_CalculateCRC8H2F()
  ** This constant defines whether the Crc_CalculateCRC8H2F is
  ** used for the Slave feature.
  ** STD_ON    Function is used
  ** STD_OFF   Function is not used
*/
#define CANTSYN_RX_CRC_USED            STD_ON

#if (defined CANTSYN_TX_OFFSET_USED)
#error CANTSYN_TX_OFFSET_USED is already defined
#endif /* if (defined CANTSYN_TX_OFFSET_USED) */

/** \brief Support of TxOffset functionality
  ** This constant defines whether the Tx Offset functionality is
  ** available.
  ** STD_ON    Functionality available
  ** STD_OFF   Functionality is not available
*/
#define CANTSYN_TX_OFFSET_USED    STD_OFF

#if (defined CANTSYN_RX_OFFSET_USED)
#error CANTSYN_RX_OFFSET_USED is already defined
#endif /* if (defined CANTSYN_RX_OFFSET_USED) */

/** \brief Support of RxOffset functionality
  ** This constant defines whether the Rx Offset functionality is
  ** available.
  ** STD_ON    Functionality available
  ** STD_OFF   Functionality is not available
*/
#define CANTSYN_RX_OFFSET_USED    STD_OFF

#if (defined CANTSYN_TX_SYNC_USED)
#error CANTSYN_TX_SYNC_USED is already defined
#endif /* if (defined CANTSYN_TX_SYNC_USED) */

/** \brief Support of TxSync functionality
  ** This constant defines whether the TX Sync functionality is
  ** available.
  ** STD_ON    Functionality available
  ** STD_OFF   Functionality is not available */
#define CANTSYN_TX_SYNC_USED     STD_OFF

#if (defined CANTSYN_RX_SYNC_USED)
#error CANTSYN_RX_SYNC_USED is already defined
#endif /* if (defined CANTSYN_RX_SYNC_USED) */

/** \brief Support of RxSync functionality
  ** This constant defines whether the Rx Sync functionality is
  ** available.
  ** STD_ON    Functionality available
  ** STD_OFF   Functionality is not available
*/
 #define CANTSYN_RX_SYNC_USED     STD_ON

#if (defined CANTSYN_NUMBER_OF_SYNC_MASTERS)
#error CANTSYN_NUMBER_OF_SYNC_MASTERS is already defined
#endif /* if (defined CANTSYN_NUMBER_OF_SYNC_MASTERS) */

/** \brief Number of the Time Master Domains with Domain Ids used for SYNC-FUP sequence */
#define CANTSYN_NUMBER_OF_SYNC_MASTERS        0U

#if (defined CANTSYN_NUMBER_OF_OFFSET_MASTERS)
#error CANTSYN_NUMBER_OF_OFFSET_MASTERS is already defined
#endif /* if (defined CANTSYN_NUMBER_OF_OFFSET_MASTERS) */

/** \brief Number of the Time Master Domains with Domain Ids used for OFS-OFNS sequence */
#define CANTSYN_NUMBER_OF_OFFSET_MASTERS        0U

#if (defined CANTSYN_NUMBER_OF_MASTERS)
#error CANTSYN_NUMBER_OF_MASTERS is already defined
#endif /* if (defined CANTSYN_NUMBER_OF_MASTERS) */

/** \brief Number of the total Time Master Domains */
#define CANTSYN_NUMBER_OF_MASTERS               0U

#if (defined CANTSYN_NUMBER_OF_SYNC_SLAVES)
#error CANTSYN_NUMBER_OF_SYNC_SLAVES is already defined
#endif /* if (defined CANTSYN_NUMBER_OF_SYNC_SLAVES) */

/** \brief Number of the Time Slave Domains with Domain Ids used for SYNC-FUP sequence */
#define CANTSYN_NUMBER_OF_SYNC_SLAVES           1U

#if (defined CANTSYN_NUMBER_OF_OFFSET_SLAVES)
#error CANTSYN_NUMBER_OF_OFFSET_SLAVES is already defined
#endif /* if (defined CANTSYN_NUMBER_OF_OFFSET_SLAVES) */

/** \brief Number of the Time Slave Domains with Domain Ids used for OFS-OFNS sequence */
#define CANTSYN_NUMBER_OF_OFFSET_SLAVES        0U

#if (defined CANTSYN_NUMBER_OF_SLAVES)
#error CANTSYN_NUMBER_OF_SLAVES is already defined
#endif /* if (defined CANTSYN_NUMBER_OF_SLAVES) */

/** \brief Number of the total Time Slave Domains */
#define CANTSYN_NUMBER_OF_SLAVES                1U

#if (defined CANTSYN_NUMBER_OF_CONTROLLERS)
#error CANTSYN_NUMBER_OF_CONTROLLERS is already defined
#endif /* if (defined CANTSYN_NUMBER_OF_CONTROLLERS) */

/** \brief Number of referenced controllers */
#define CANTSYN_NUMBER_OF_CONTROLLERS           0U


/** \brief Macros used for the CRC support for each Master Time Domain */

#if (defined CANTSYN_CRC_SUPPORTED)
#error CANTSYN_CRC_SUPPORTED is already defined
#endif /* if (defined CANTSYN_CRC_SUPPORTED) */
#define CANTSYN_CRC_SUPPORTED                 0U

#if (defined CANTSYN_CRC_NOT_SUPPORTED)
#error CANTSYN_CRC_NOT_SUPPORTED is already defined
#endif /* if (defined CANTSYN_CRC_NOT_SUPPORTED) */
#define CANTSYN_CRC_NOT_SUPPORTED             1U

 /** \brief Macros used for the CRC support for each Slave Time Domain */

#if (defined CANTSYN_CRC_VALIDATED)
#error CANTSYN_CRC_VALIDATED is already defined
#endif /* if (defined CANTSYN_CRC_VALIDATED) */
#define CANTSYN_CRC_VALIDATED                 0U

#if (defined CANTSYN_CRC_OPTIONAL)
#error CANTSYN_CRC_OPTIONAL is already defined
#endif /* if (defined CANTSYN_CRC_OPTIONAL) */
#define CANTSYN_CRC_OPTIONAL                  1U

#if (defined CANTSYN_CRC_NOT_VALIDATED)
#error CANTSYN_CRC_NOT_VALIDATED is already defined
#endif /* if (defined CANTSYN_CRC_NOT_VALIDATED) */
#define CANTSYN_CRC_NOT_VALIDATED             2U

#if (defined CANTSYN_CRC_IGNORED)
#error CANTSYN_CRC_IGNORED is already defined
#endif /* if (defined CANTSYN_CRC_IGNORED) */
#define CANTSYN_CRC_IGNORED                   3U

#if (defined CANTSYN_TX_MAX_MSG_LEN)
#error CANTSYN_TX_MAX_MSG_LEN is already defined
#endif /* if (defined CANTSYN_TX_MAX_MSG_LEN) */

#define CANTSYN_TX_MAX_MSG_LEN                   8U

#if (defined CANTSYN_RX_MAX_MSG_LEN)
#error CANTSYN_RX_MAX_MSG_LEN is already defined
#endif /* if (defined CANTSYN_RX_MAX_MSG_LEN) */
#define CANTSYN_RX_MAX_MSG_LEN                   16U

#if (defined CANTSYN_TX_USE_EXTENDED_MSG)
#error CANTSYN_TX_USE_EXTENDED_MSG is already defined
#endif /* if (defined CANTSYN_TX_USE_EXTENDED_MSG) */

#define CANTSYN_TX_USE_EXTENDED_MSG              STD_OFF

#if (defined CANTSYN_RX_USE_EXTENDED_MSG)
#error CANTSYN_RX_USE_EXTENDED_MSG is already defined
#endif /* if (defined CANTSYN_RX_USE_EXTENDED_MSG) */
#define CANTSYN_RX_USE_EXTENDED_MSG              STD_ON

#if (defined CANTSYN_RX_FOLLOWUP_TIMEOUT_USED)
#error CANTSYN_RX_FOLLOWUP_TIMEOUT_USED is already defined
#endif /* if (defined CANTSYN_RX_FOLLOWUP_TIMEOUT_USED) */

#define CANTSYN_RX_FOLLOWUP_TIMEOUT_USED     STD_ON

#if (defined CANTSYN_IS_PDUINDEX_USED)
#error CANTSYN_IS_PDUINDEX_USED is already defined
#endif /* if (defined CANTSYN_IS_PDUINDEX_USED) */

#define CANTSYN_IS_PDUINDEX_USED     STD_ON

#if (defined CANTSYN_MASTER_TIME_DOMAIN_VALIDATION_SUPPORT)
#error CANTSYN_MASTER_TIME_DOMAIN_VALIDATION_SUPPORT is already defined
#endif /* if (defined CANTSYN_MASTER_TIME_DOMAIN_VALIDATION_SUPPORT) */

#define CANTSYN_MASTER_TIME_DOMAIN_VALIDATION_SUPPORT STD_OFF

#if (defined CANTSYN_SLAVE_TIME_DOMAIN_VALIDATION_SUPPORT)
#error CANTSYN_SLAVE_TIME_DOMAIN_VALIDATION_SUPPORT is already defined
#endif /* if (defined CANTSYN_SLAVE_TIME_DOMAIN_VALIDATION_SUPPORT) */

#define CANTSYN_SLAVE_TIME_DOMAIN_VALIDATION_SUPPORT STD_OFF
/** \brief Support of CanTSyn_TxConfirmation() according to AUTOSAR R20-11.
  ** This constant defines whether the reliable TxConfirmation feature is used.
  ** STD_ON    feature is used
  ** STD_OFF   feature is not used
*/
#if (defined CANTSYN_RELIABLE_TXCONF)
#error CANTSYN_RELIABLE_TXCONF is already defined
#endif
/** \brief Pre-processor switch for supporting CanTSyn_TxConfirmation() according to AUTOSAR R20-11. */
#define CANTSYN_RELIABLE_TXCONF STD_OFF
/** \brief Value of NetworkSegmentId when CanTSynEnableTimeValidation is false */

/* !LINKSTO CanTSyn.ASR20-11.ECUC_CanTSyn_00008,1 */
/** \brief Definitions of symbolic names for all CanTSynGlobalTimeMasterConfirmationHandleIds */

/* !LINKSTO CanTSyn.ASR20-11.ECUC_CanTSyn_00013,1 */
/** \brief Definitions of symbolic names for all CanTSynGlobalTimeSlaveHandleIds */
#define CanTSynConf_CanTSynGlobalTimeSlavePdu_CanTSynGlobalTimeDomain_0  0U

/*==================[type definitions]=======================================*/

/*==================[external function declarations]=========================*/

/*==================[internal function declarations]=========================*/

/*==================[external constants]=====================================*/

#define CANTSYN_START_SEC_CONFIG_DATA_UNSPECIFIED
#include <CanTSyn_MemMap.h>


/** \brief CanTSyn Slave configuration
 **
 ** This is the CanTSyn Slave configuration.
 ** Please note that the name of this element is configuration dependent.
 */
extern CONST(CanTSyn_TimeSlaveDomainConfigType, CANTSYN_APPL_CONST) CanTSyn_TimeSlaveConfig[1];

#define CANTSYN_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include <CanTSyn_MemMap.h>

/*==================[internal constants]=====================================*/

/*==================[external data]==========================================*/

/*==================[internal data]==========================================*/

/*==================[external function definitions]==========================*/

/*==================[internal function definitions]==========================*/

#endif /* ifndef CANTSYN_CFG_H */

/*==================[end of file]============================================*/



