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

/*==================[inclusions]=================================================================*/
#include <ComStack_Types.h>                               /* AUTOSAR standard types */
#include <Dcm_Int.h>
/*==================[macros]=====================================================================*/

/*==================[type definitions]===========================================================*/

/*==================[external function declarations]=============================================*/

/*==================[internal function declarations]=============================================*/

/*==================[internal constants]=========================================================*/

/*==================[internal data]==============================================================*/

#define DCM_START_SEC_CONST_UNSPECIFIED
#include <Dcm_MemMap.h>

/* The configuration array for RxPduIDs.
*
* A Dcm Connection basically receives data from a number of RxPduIDs and transmits it to only ONE TxPduId.
* In order to identify which Connection to use we will always need to use the RxPduId of the incoming
* reception and from this infer all the data which we need to further handle reception, processing and transmission.
*
*/

/* !LINKSTO Dcm.Dsn.LowerLayerInterfaces.PduRInterface.BufferManager.ConfigurationDataElements,1 */
/* Initialize global array holding the configuration for each buffer which is referenced from anywhere */
CONST(Dcm_BufferConfigType, DCM_CONST) Dcm_BufferConfig[DCM_NUM_CONFIGURED_BUFFERS] =
{
/* The index used for pointer to buffer */
  {
    /* Size of buffer */
    4096U,
    /* Pointer to buffer */
    &Dcm_Buffers[0],
  },
/* The index used for pointer to buffer */
  {
    /* Size of buffer */
    8U,
    /* Pointer to buffer */
    &Dcm_Buffers[4096],
  },
/* The index used for pointer to buffer */
  {
    /* Size of buffer */
    4096U,
    /* Pointer to buffer */
    &Dcm_Buffers[4104],
  },
/* The index used for pointer to buffer */
  {
    /* Size of buffer */
    8U,
    /* Pointer to buffer */
    &Dcm_Buffers[8200],
  },
/* The index used for pointer to buffer */
  {
    /* Size of buffer */
    128U,
    /* Pointer to buffer */
    &Dcm_Buffers[8208],
  },
};

/* !LINKSTO Dcm.Dsn.LowerLayerInterfaces.PduRInterface.RxConnection.ConfigurationDataElements,1 */
/* Initialize global array holding the configuration for each RxPduId */
CONST(Dcm_RxPduIdConfigType, DCM_CONST) Dcm_RxPduIdConfig[DCM_NUM_RX_PDU_ID] =
{
  {
    /* This is the configuration of RxPduId 0 */
    DCM_NOT_CONFIGURED_ECUC_PDUID, /* GenericConnectionUsage is disabled */
    DCM_PHYSICAL_TYPE, /* AddressingType */
    2U, /* BufferIndex */
    0U, /* MainConnectionIndex */
    0U  /* ChannelIdConfigIndex */
  },
  {
    /* This is the configuration of RxPduId 1 */
    DCM_NOT_CONFIGURED_ECUC_PDUID, /* GenericConnectionUsage is disabled */
    DCM_FUNCTIONAL_TYPE, /* AddressingType */
    1U, /* BufferIndex */
    0U, /* MainConnectionIndex */
    0U  /* ChannelIdConfigIndex */
  },
  {
    /* This is the configuration of RxPduId 2 */
    DCM_NOT_CONFIGURED_ECUC_PDUID, /* GenericConnectionUsage is disabled */
    DCM_PHYSICAL_TYPE, /* AddressingType */
    4U, /* BufferIndex */
    1U, /* MainConnectionIndex */
    0U  /* ChannelIdConfigIndex */
  },
  {
    /* This is the configuration of RxPduId 3 */
    DCM_NOT_CONFIGURED_ECUC_PDUID, /* GenericConnectionUsage is disabled */
    DCM_FUNCTIONAL_TYPE, /* AddressingType */
    3U, /* BufferIndex */
    1U, /* MainConnectionIndex */
    0U  /* ChannelIdConfigIndex */
  },
};

/* !LINKSTO Dcm.Dsn.DiagnosticSessionLayer.ConfigurationDataElements,1 */
/* Initialize global array holding the protocol configuration */
CONST(Dcm_ProtocolConfigType, DCM_CONST) Dcm_ProtocolConfig[DCM_NUM_PROTOCOLS] =
{
  {
    0U, /*P2ServerAdjustTime*/
    0U, /*P2StarServerAdjustTime */
    1U, /* Protocol preemption timeout */
    0U, /* Tx buffer Index */
    DCM_UDS_ON_CAN, /* Protocol ID */
    0U, /* Protocol priority */
    0U, /* Protocol stack number */
    /* !LINKSTO Dcm.LinktoServiceTable.ProtocolInit,2 */
    0U, /* Dcm_SidTabConfigType */
    TRUE, /* endianness Conversion */
    TRUE, /* Send RP OnTransToBoot */
    /* !LINKSTO Dcm.EB.ObdOptionalNrc.SupressNRC.OBD_0x00,1 */
    /* !LINKSTO Dcm.EB.ObdOptionalNrc.SupressNRC.OBD_0x01,1 */
    /* !LINKSTO Dcm.EB.ObdOptionalNrc.SupressNRC.OBD_0x02,1 */
    /* !LINKSTO Dcm.EB.ObdOptionalNrc.SupressNRC.OBD_0x03,1 */
    /* !LINKSTO Dcm.EB.ObdOptionalNrc.SupressNRC.OBD_0x04,1 */
    /* !LINKSTO Dcm.EB.ObdOptionalNrc.SupressNRC.OBD_0x06,1 */
    /* !LINKSTO Dcm.EB.ObdOptionalNrc.SupressNRC.OBD_0x07,1 */
    /* !LINKSTO Dcm.EB.ObdOptionalNrc.SupressNRC.OBD_0x08,1 */
    /* !LINKSTO Dcm.EB.ObdOptionalNrc.SupressNRC.OBD_0x09,1 */
    /* !LINKSTO Dcm.EB.ObdOptionalNrc.SupressNRC.OBD_0x0A,1 */
    /* !LINKSTO Dcm.EB.ObdOptionalNrc.SupressNRC.OBD_0x0B-0x0F,1 */
    /* !LINKSTO Dcm.EB.ObdOptionalNrc.DoNotSupressNRC.OBD_0x00,1 */
    /* !LINKSTO Dcm.EB.ObdOptionalNrc.DoNotSupressNRC.OBD_0x01,1 */
    /* !LINKSTO Dcm.EB.ObdOptionalNrc.DoNotSupressNRC.OBD_0x02,1 */
    /* !LINKSTO Dcm.EB.ObdOptionalNrc.DoNotSupressNRC.OBD_0x03,1 */
    /* !LINKSTO Dcm.EB.ObdOptionalNrc.DoNotSupressNRC.OBD_0x04,1 */
    /* !LINKSTO Dcm.EB.ObdOptionalNrc.DoNotSupressNRC.OBD_0x06,1 */
    /* !LINKSTO Dcm.EB.ObdOptionalNrc.DoNotSupressNRC.OBD_0x07,1 */
    /* !LINKSTO Dcm.EB.ObdOptionalNrc.DoNotSupressNRC.OBD_0x08,1 */
    /* !LINKSTO Dcm.EB.ObdOptionalNrc.DoNotSupressNRC.OBD_0x09,1 */
    /* !LINKSTO Dcm.EB.ObdOptionalNrc.DoNotSupressNRC.OBD_0x0A,1 */
    /* !LINKSTO Dcm.EB.ObdOptionalNrc.DoNotSupressNRC.OBD_0x0B-0x0F,1 */
    FALSE, /* Supress Service Not Supported NRC */
    0U /* DemClientId */
  },
};

/* !LINKSTO Dcm.Dsn.LowerLayerInterfaces.PduRInterface.TxConnection.ConfigurationDataElements,1 */
/* !LINKSTO Dcm.Eb.MainConnectionConfig,1 */
/* !LINKSTO Dcm.Eb.Virtual.TxConnectionPduId,1 */
/* Initialize global array holding the configuration for each DcmDslMainConnection */
CONST(Dcm_MainConnectionConfigType, DCM_CONST) Dcm_MainConnectionConfig[DCM_NUM_MAIN_CONNECTIONS] =
{
  {
    0U, /* TxPduId */
    0U, /* TxConfirmationPduId*/
    DCM_NOT_CONFIGURED_ECUC_PDUID, /* GenericConnectionUsage is disabled */
    0, /* TesterSourceAddress */
    0, /* ProtocolIndex */
    DCM_NUM_GENERIC_CONNECTIONS,
    FALSE /* GenericConnectionUsage is disabled. */
  },
  {
    1U, /* TxPduId */
    1U, /* TxConfirmationPduId*/
    DCM_NOT_CONFIGURED_ECUC_PDUID, /* GenericConnectionUsage is disabled */
    0, /* TesterSourceAddress */
    0, /* ProtocolIndex */
    DCM_NUM_GENERIC_CONNECTIONS,
    FALSE /* GenericConnectionUsage is disabled. */
  },
};


#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include <Dcm_MemMap.h>

#define DCM_START_SEC_CONST_8
#include <Dcm_MemMap.h>

/* Array holding the channel identifiers configured and the current state the channel is in */
CONST(NetworkHandleType, DCM_CONST) Dcm_RxComMChannelIDs[DCM_NUM_RX_COMM_CHANNELS] =
{
  0U,
};

#define DCM_STOP_SEC_CONST_8
#include <Dcm_MemMap.h>
/*==================[external constants]=========================================================*/

/*==================[external data]==============================================================*/

#define DCM_START_SEC_CONST_8
#include <Dcm_MemMap.h>

/* Array holding the Dem Client Ids referenced by Dcm */
CONST(uint8, DCM_CONST) Dcm_DemClientIds[DCM_NUM_DEM_CLIENTS] =
{
  0U,
};

#define DCM_STOP_SEC_CONST_8
#include <Dcm_MemMap.h>

/*==================[external function definitions]==============================================*/

/*==================[internal function definitions]==============================================*/

/*==================[end of file]================================================================*/
