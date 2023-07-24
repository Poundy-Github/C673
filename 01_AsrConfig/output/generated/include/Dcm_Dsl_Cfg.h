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

#ifndef DCM_DSL_CFG_H
#define DCM_DSL_CFG_H

/*==================[includes]===================================================================*/

#include <Std_Types.h>

/*==================[macros]=====================================================================*/

/* Allocate memory of buffers configured for the Dcm module */

#if (defined DCM_NUM_RX_PDU_ID) /* To prevent double declaration */
#error DCM_NUM_RX_PDU_ID already defined
#endif /* if (defined DCM_NUM_RX_PDU_ID) */

/** \brief Definition of number of reception(Rx) Pdu Ids */
#define DCM_NUM_RX_PDU_ID                   4U

#if (defined DCM_NUM_TX_PDU_ID) /* To prevent double declaration */
#error DCM_NUM_TX_PDU_ID already defined
#endif /* if (defined DCM_NUM_TX_PDU_ID) */

/** \brief Definition of number of Transmission(Tx) Pdu Ids */
/* !LINKSTO Dcm.Eb.NumberOf.TxConnections,1 */
/* Amount of TX connections is calculated from the total of ROE Connections, Periodic
   connections and Main (real and virtual) connections. */
#define DCM_NUM_TX_PDU_ID                   2U

#if (defined DCM_NUM_CONFIRMATION_TX_PDU_ID) /* To prevent double declaration */
#error DCM_NUM_CONFIRMATION_TX_PDU_ID already defined
#endif /* if (defined DCM_NUM_CONFIRMATION_TX_PDU_ID) */

/** \brief Definition of number of Transmission(Tx) Confirmation Pdu Ids */
#define DCM_NUM_CONFIRMATION_TX_PDU_ID      DCM_NUM_TX_PDU_ID

#if defined DCM_TOTAL_CONFIGURED_BUFFER_SIZE /* To prevent double declaration */
#error DCM_TOTAL_CONFIGURED_BUFFER_SIZE already defined
#endif /* if defined DCM_TOTAL_CONFIGURED_BUFFER_SIZE */

#define DCM_TOTAL_CONFIGURED_BUFFER_SIZE    8336U

#if defined DCM_TOTAL_RX_CONFIGURED_BUFFER_SIZE /* To prevent double declaration */
#error DCM_TOTAL_RX_CONFIGURED_BUFFER_SIZE already defined
#endif /* if defined DCM_TOTAL_RX_CONFIGURED_BUFFER_SIZE */

#define DCM_TOTAL_RX_CONFIGURED_BUFFER_SIZE    4240U

/* !LINKSTO Dcm.Dsn.LowerLayerInterfaces.PduRInterface.Buffer.Types,2 */
#if (defined DCM_NUM_CONFIGURED_BUFFERS) /* To prevent double declaration */
#error DCM_NUM_CONFIGURED_BUFFERS already defined
#endif /* if (defined DCM_NUM_CONFIGURED_BUFFERS) */

/** \brief Definition of number of configured buffers */
#define DCM_NUM_CONFIGURED_BUFFERS          5U

#if defined DCM_NUM_MAIN_CONNECTIONS /* To prevent double declaration */
#error DCM_NUM_MAIN_CONNECTIONS already defined
#endif /* if defined DCM_NUM_MAIN_CONNECTIONS */

#define DCM_NUM_MAIN_CONNECTIONS            2U

#if defined DCM_NUM_GENERIC_CONNECTIONS /* To prevent double declaration */
#error DCM_NUM_GENERIC_CONNECTIONS already defined
#endif /* if defined DCM_NUM_GENERIC_CONNECTIONS */

#define DCM_NUM_GENERIC_CONNECTIONS            0U

#if defined DCM_NUM_PROTOCOLS /* To prevent double declaration */
#error DCM_NUM_PROTOCOLS already defined
#endif /* if defined DCM_NUM_PROTOCOLS */

#define DCM_NUM_PROTOCOLS                   1U

#if defined DCM_DEM_CLIENT_REF_USED /* To prevent double declaration */
#error DCM_DEM_CLIENT_REF_USED already defined
#endif /* if defined DCM_DEM_CLIENT_REF_USED */
#define DCM_DEM_CLIENT_REF_USED             STD_ON
#if defined DCM_NUM_DEM_CLIENTS /* To prevent double declaration */
#error DCM_NUM_DEM_CLIENTS already defined
#endif /* if defined DCM_NUM_DEM_CLIENTS */

#define DCM_NUM_DEM_CLIENTS                 1U

#if defined DCM_NUM_STACKS
#error DCM_NUM_STACKS already defined
#endif

#define DCM_NUM_STACKS           1U

/* !LINKSTO Dcm.Dsn.LowerLayerInterfaces.PduRInterface.Buffer.Types,2 */
#if (defined DCM_NUM_NRC_BUFFERS) /* To prevent double declaration */
#error DCM_NUM_NRC_BUFFERS already defined
#endif /* if (defined DCM_NUM_NRC_BUFFERS) */

/** \brief Definition of number of NRC buffers */
#define DCM_NUM_NRC_BUFFERS                 DCM_NUM_TX_PDU_ID

#if (defined DCM_NUM_DEFAULT_BUFFERS) /* To prevent double declaration */
#error DCM_NUM_DEFAULT_BUFFERS already defined
#endif /* if (DCM_NUM_DEFAULT_BUFFERS) */

/** \brief Definition of number of default 2-byte buffers */
#define DCM_NUM_DEFAULT_BUFFERS             DCM_NUM_RX_PDU_ID

#if defined DCM_PERIODIC_USED /* To prevent double declaration */
#error DCM_PERIODIC_USED already defined
#endif /* if defined DCM_PERIODIC_USED */

#define DCM_PERIODIC_USED                   STD_ON

#if defined DCM_NUM_ROE_CONNECTIONS /* To prevent double declaration */
#error DCM_NUM_ROE_CONNECTIONS already defined
#endif /* if defined DCM_NUM_ROE_CONNECTIONS */

#define DCM_NUM_ROE_CONNECTIONS             0U

#if defined DCM_NUM_PERIODIC_TRANSMISSIONS /* To prevent double declaration */
#error DCM_NUM_PERIODIC_TRANSMISSIONS already defined
#endif /* if defined DCM_NUM_PERIODIC_TRANSMISSIONS */

#define DCM_NUM_PERIODIC_TRANSMISSIONS      0U

#if defined DCM_NUM_PERIODIC_CONNECTIONS /* To prevent double declaration */
#error DCM_NUM_PERIODIC_CONNECTIONS already defined
#endif /* if defined DCM_NUM_PERIODIC_CONNECTIONS */

#define DCM_NUM_PERIODIC_CONNECTIONS        0U

#if defined DCM_VIRTUAL_TX_CONNECTION
#error DCM_VIRTUAL_TX_CONNECTION already defined
#endif

#define DCM_VIRTUAL_TX_CONNECTION   0xffffU

#if defined DCM_TOTAL_NUMBER_OF_REAL_TX_CONNECTIONS
#error DCM_TOTAL_NUMBER_OF_REAL_TX_CONNECTIONS already defined
#endif

#define DCM_TOTAL_NUMBER_OF_REAL_TX_CONNECTIONS         2U

#if defined DCM_VIRTUAL_TX_CONNECTIONS_PRESENT
#error DCM_VIRTUAL_TX_CONNECTIONS_PRESENT already defined
#endif
#define DCM_VIRTUAL_TX_CONNECTIONS_PRESENT         STD_OFF

/** \brief Definition of number of channel Identifiers configured. */
#if (defined DCM_NUM_RX_COMM_CHANNELS)
  #error "DCM_NUM_RX_COMM_CHANNELS is already defined"
#endif
#define DCM_NUM_RX_COMM_CHANNELS                     1U

#if (defined DCM_DSL_APPLICATION_DIAGNOSTIC_REQUESTS) /* To prevent double declaration */
#error DCM_DSL_APPLICATION_DIAGNOSTIC_REQUESTS already defined
#endif /* if (defined DCM_DSL_APPLICATION_DIAGNOSTIC_REQUESTS) */

/** \brief Application Diagnostic Request is enabled or not */
#define DCM_DSL_APPLICATION_DIAGNOSTIC_REQUESTS                STD_OFF

/*==================[type definitions]===========================================================*/


/*==================[external function declarations]=============================================*/

/*==================[internal function declarations]=============================================*/

/*==================[external constants]=========================================================*/

/*==================[external data]==============================================================*/

#define DCM_START_SEC_CONST_8
#include <Dcm_MemMap.h>

extern CONST(uint8, DCM_CONST) Dcm_DemClientIds[DCM_NUM_DEM_CLIENTS];

#define DCM_STOP_SEC_CONST_8
#include <Dcm_MemMap.h>

/*==================[internal data]==============================================================*/

#define DCM_START_SEC_CONST_8
#include <Dcm_MemMap.h>

extern CONST(NetworkHandleType, DCM_CONST) Dcm_RxComMChannelIDs[DCM_NUM_RX_COMM_CHANNELS];

#define DCM_STOP_SEC_CONST_8
#include <Dcm_MemMap.h>

/*==================[external function definitions]==============================================*/

/*==================[internal function definitions]==============================================*/

#endif /* ifndef DCM_DSL_CFG_H */
/*==================[end of file]================================================================*/
