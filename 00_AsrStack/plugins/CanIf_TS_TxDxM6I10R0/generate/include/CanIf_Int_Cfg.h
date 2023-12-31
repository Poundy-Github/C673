/**
 * \file
 *
 * \brief AUTOSAR CanIf
 *
 * This file contains the implementation of the AUTOSAR
 * module CanIf.
 *
 * \version 6.10.19
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2021 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */
[!CODE!]
[!AUTOSPACING!]
#ifndef CANIF_INT_CFG_H
#define CANIF_INT_CFG_H


/*==================[includes]===============================================*/
#define CANIF_NO_PBCFG_REQUIRED
#include <TSAutosar.h>          /* EB specific standard types */
#include <ComStack_Types.h>     /* Autosar standard types */
#include <CanIf.h>            /* CanIf interface */

[!SELECT "as:modconf('CanIf')[1]/CanIfDispatchCfg"!]
[!IF "    (CanIfDispatchUserCtrlBusOffUL = 'CAN_SM')
       or (CanIfDispatchUserCtrlModeIndicationUL = 'CAN_SM')
       or (     (node:exists(../CanIfTrcvDrvCfg/*))
            and (    (CanIfDispatchUserTrcvModeIndicationUL = 'CAN_SM')
                  or (     (../CanIfPublicCfg/CanIfPublicPnSupport = 'true')
                       and (    (CanIfDispatchUserConfirmPnAvailabilityUL = 'CAN_SM')
                             or (CanIfDispatchUserClearTrcvWufFlagIndicationUL = 'CAN_SM')
                             or (CanIfDispatchUserCheckTrcvWakeFlagIndicationUL = 'CAN_SM')
                           )
                     )
                )
          )
     "!]
#include <CanSM_Cbk.h>                /* AUTOSAR CanSM callback definitions */
[!ENDIF!]
[!ENDSELECT!]

[!LOOP "CanIfPublicCfg/CanIfPublicCddHeaderFile/*"!][!//
#include <[!"."!]>   /* CDD header file */
[!ENDLOOP!][!//

/* !LINKSTO CanIf.EB.HookOnReception.Header,1 */
[!IF "CanIfPublicCfg/CanIfHookOnReceptionSupport = 'true'"!]
#include <[!"CanIfHookOnRxSupport/CanIfHookOnReceptionHeader"!]>   /* Rx Hook CDD header file */
[!ENDIF!]

/*==================[macros]=================================================*/

/*==================[type definitions]=======================================*/

/*==================[external function declarations]=========================*/

/*==================[internal function declarations]=========================*/

/*==================[external constants]=====================================*/

/*==================[internal constants]=====================================*/

/*==================[external data]==========================================*/

#if(( CANIF_READTXPDU_NOTIF_STATUS_API == STD_ON ) || ( CANIF_READRXPDU_NOTIF_STATUS_API == STD_ON ))
#define CANIF_START_SEC_VAR_CLEARED_8
#include <CanIf_MemMap.h>

[!IF "CanIfPublicCfg/CanIfMultiCoreSupport = 'true'"!]
#if( CANIF_READTXPDU_NOTIF_STATUS_API == STD_ON )
  /** \brief Pointer to the Tx notification flags (if enabled)
 **
 ** This array contains a pointer to the Tx notification flag for each controller for which
 ** this feature is enabled.
 */
extern VAR(CanIf_TxLPduNotifyFlagType, CANIF_VAR)
  CanIf_ControllerTxLPduNotifyFlag[];
#endif /* CANIF_READTXPDU_NOTIF_STATUS_API == STD_ON */

#if( CANIF_READRXPDU_NOTIF_STATUS_API == STD_ON )
  /** \brief Pointer to the Rx notification flags (if enabled)
 **
 ** This array contains a pointer to the Rx notification flag for each controller for which
 ** this feature is enabled.
 */
extern VAR(CanIf_RxLPduNotifyFlagType, CANIF_VAR)
  CanIf_ControllerRxLPduNotifyFlag[];
#endif /* CANIF_READRXPDU_NOTIF_STATUS_API == STD_ON */
[!ELSE!]
#if( CANIF_READTXPDU_NOTIF_STATUS_API == STD_ON )
/** \brief Bit-array of Tx notification flags (if enabled)
 **
 ** This array contains a Tx notification flag for each Tx L-PDU for which
 ** this feature is enabled.
 */
extern VAR( uint8, CANIF_VAR )
  CanIf_TxLPduNotifyFlags[];
#endif /* CANIF_READTXPDU_NOTIF_STATUS_API == STD_ON */

#if( CANIF_READRXPDU_NOTIF_STATUS_API == STD_ON )
/** \brief Bit-array of Rx notification flags (if enabled)
 **
 ** This array contains a Rx notification flag for each Rx L-PDU for which
 ** this feature is enabled.
 */
extern VAR( uint8, CANIF_VAR )
  CanIf_RxLPduNotifyFlags[];
#endif /* CANIF_READRXPDU_NOTIF_STATUS_API == STD_ON */
[!ENDIF!]

#define CANIF_STOP_SEC_VAR_CLEARED_8
#include <CanIf_MemMap.h>

#endif /* ( CANIF_READTXPDU_NOTIF_STATUS_API == STD_ON ) || ( CANIF_READRXPDU_NOTIF_STATUS_API == STD_ON ) */
/*==================[internal data]==========================================*/

/*==================[external function definitions]==========================*/

/*==================[internal function definitions]==========================*/

#endif /* ifndef CANIF_INT_CFG_H */
/*==================[end of file]============================================*/
[!ENDCODE!]
