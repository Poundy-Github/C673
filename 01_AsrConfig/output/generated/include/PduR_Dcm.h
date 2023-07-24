/**
 * \file
 *
 * \brief AUTOSAR PduR
 *
 * This file contains the implementation of the AUTOSAR
 * module PduR.
 *
 * \version 5.3.47
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2021 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */
#ifndef PDUR_DCM_H
#define PDUR_DCM_H

/*==================[includes]==============================================*/
#include <TSAutosar.h> /* EB specific standard types */
#include <ComStack_Types.h> /* AUTOSAR Communication Stack types */
/* Exclude post-build-time configuration include file if requested to do so */
#if (!defined PDUR_NO_PBCFG_REQUIRED) && (!defined PDUR_NO_CFG_REQUIRED)
#include <PduR_SymbolicNames_PBcfg.h>
#endif /* PDUR_NO_PBCFG_REQUIRED */

/*==================[macros]================================================*/

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function declarations]========================*/
#define PDUR_START_SEC_CODE
#include <PduR_MemMap.h>

/** \brief This function is called by Dcm module to request transmission of an I-PDU.
 **
 ** \param[in]  TxPduId      Identification of the Tx-PDU ID.
 ** \param[in]  PduInfoPtr   Length and pointer to the buffer of the I-PDU
 **
 ** \return Function execution success status
 ** \retval E_OK        Request is accepted by the destination module.
 ** \retval E_NOT_OK    Request is not accepted by the destination module.
 **
 ** \ServiceID{0x14}
 ** \Reentrancy{Reentrant for different PduIds. Non reentrant for the same PduId.}
 ** \Synchronicity{Synchronous}
 **/
extern FUNC(Std_ReturnType, PDUR_CODE) PduR_DcmIfTransmit
(
    PduIdType TxPduId,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) PduInfoPtr
);

/** \brief This function is called by Dcm module to request transmission of an I-PDU.
 **
 ** \param[in]  TxPduId      Identification of the Tx-PDU ID.
 ** \param[in]  PduInfoPtr   Length and pointer to the buffer of the I-PDU
 **
 ** \return Function execution success status
 ** \retval E_OK        Request is accepted by the destination module.
 ** \retval E_NOT_OK    Request is not accepted by the destination module.
 **
 ** \ServiceID{0x14}
 ** \Reentrancy{Reentrant for different PduIds. Non reentrant for the same PduId.}
 ** \Synchronicity{Synchronous}
 **/
extern FUNC(Std_ReturnType, PDUR_CODE) PduR_DcmTransmit
(
    PduIdType TxPduId,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) PduInfoPtr
);

/**
 ** \brief This service is called by the Dcm module for cancellation of an ongoing
 ** transmission of an transport protocol module I-PDU.
 **
 ** \param[in] TxPduId       Identification of the Tx-PDU ID to be canceled.
 **
 ** \return Function execution success status
 ** \retval E_OK        Request is accepted by the destination module.
 ** \retval E_NOT_OK    Request is not accepted by the destination module.
 **
 ** \ServiceID{0x1C}
 ** \Reentrancy{Reentrant}
 ** \Synchronicity{Asynchronous}
 **/
extern FUNC(Std_ReturnType, PDUR_CODE) PduR_DcmCancelTransmit
(
    PduIdType TxPduId
);

/**
 ** \brief This service is called by the Dcm module to request cancellation from an
 ** upper layer module of an I-PDU in a lower layer transport protocol module.
 **
 ** \param[in]  RxPduId      Identification of the Rx I-PDU.
 **
 ** \return Function execution success status
 ** \retval E_OK        Request accepted (but not yet performed).
 ** \retval E_NOT_OK    Request not accepted (e.g. cancellation not possible)
 **
 ** \ServiceID{0x21}
 ** \Reentrancy{Reentrant}
 ** \Synchronicity{Asynchronous}
 **/
extern FUNC(Std_ReturnType, PDUR_CODE) PduR_DcmCancelReceive
(
    PduIdType RxPduId
);

#define PDUR_STOP_SEC_CODE
#include <PduR_MemMap.h>

/*==================[internal function declarations]========================*/

#endif /* ifndef PDUR_DCM_H  */
/*==================[end of file]===========================================*/
