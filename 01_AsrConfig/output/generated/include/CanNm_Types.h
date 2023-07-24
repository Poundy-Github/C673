


/**
 * \file
 *
 * \brief AUTOSAR CanNm
 *
 * This file contains the implementation of the AUTOSAR
 * module CanNm.
 *
 * \version 1.4.1
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2021 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

#ifndef CANNM_TYPES_H
#define CANNM_TYPES_H



/*==================[inclusions]=============================================*/

#include <Platform_Types.h>
#include <ComStack_Cfg.h>
#include <TSAutosar.h>
#define TS_RELOCATABLE_CFG_ENABLE STD_ON
#define TS_PB_CFG_PTR_CLASS CANNM_APPL_CONST
#include <TSPBConfig_Types.h>


/*==================[macros]=================================================*/


/*==================[type definitions]=======================================*/

typedef struct /* CanNm_ChannelDataType */ {
    VAR( uint32, TYPEDEF ) UserDataLength; /* User Data Length */
    VAR( uint16, TYPEDEF ) CanNmMsgCycleOffset; /* CanNmMsgCycleOffset */
    VAR( PduLengthType, TYPEDEF ) RxPduLength; /* PduLength array */
    VAR( PduIdType, TYPEDEF ) UserTxConfPduId; /* UserTxConfPduId array */
    VAR( PduIdType, TYPEDEF ) UserRxPduId; /* UserRxPduId */
    VAR( PduIdType, TYPEDEF ) TxPduId; /* Pdu ID if transmit PDU (from CanIf) */
    VAR( uint8, TYPEDEF ) CanNmNodeId; /* CanNmNodeId */
    VAR( boolean, TYPEDEF ) UserRxPduEnabled; /* UserRxPduEnabled */
} CanNm_ChannelDataType;

typedef struct /* CanNm_ConfigType */ {
    VAR( uint32, TYPEDEF ) PlatformSignature; /* Used to validate the platform */
    VAR( uint32, TYPEDEF ) LcfgSignature; /* Used to validate the post build configuration against the link time configuration */
    VAR( uint32, TYPEDEF ) CfgSignature; /* Used to validate the post build configuration against the precompile time configuration */
    VAR( uint32, TYPEDEF ) PublicInfoSignature; /* Used to validate Public information */
    VAR( CanNm_ChannelDataType, TYPEDEF ) CanNm_ChannelData[1]; /* CanNm_ChannelData */
    VAR( uint32, TYPEDEF ) BufferOffsets[1]; /* BufferOffsets array */
    VAR( uint32, TYPEDEF ) TxBufferOffset; /* Offset where Tx buffers starts */
    VAR( uint32, TYPEDEF ) PbRequiredCfgRamSize; /* Buffer size needed by TX and RX pdus */
} CanNm_ConfigType;


/*==================[external function declarations]=========================*/


/*==================[internal function declarations]=========================*/


/*==================[external constants]=====================================*/


/*==================[internal constants]=====================================*/


/*==================[external data]==========================================*/


/*==================[internal data]==========================================*/


/*==================[external function definitions]==========================*/


/*==================[internal function definitions]==========================*/



#undef TS_RELOCATABLE_CFG_ENABLE

#undef TS_PB_CFG_PTR_CLASS

#endif /* CANNM_TYPES_H */

/*==================[end of file]============================================*/

