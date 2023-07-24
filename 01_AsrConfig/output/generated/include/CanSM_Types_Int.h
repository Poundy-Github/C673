


/**
 * \file
 *
 * \brief AUTOSAR CanSM
 *
 * This file contains the implementation of the AUTOSAR
 * module CanSM.
 *
 * \version 1.4.1
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2021 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

#ifndef CANSM_TYPES_INT_H
#define CANSM_TYPES_INT_H



/*==================[inclusions]=============================================*/

#include <Platform_Types.h>
#include <TSAutosar.h>
#define TS_RELOCATABLE_CFG_ENABLE STD_OFF
#define TS_PB_CFG_PTR_CLASS CANSM_APPL_CONST
#include <TSPBConfig_Types.h>


/*==================[macros]=================================================*/


/*==================[type definitions]=======================================*/

typedef struct /* CanSMControllerType */ {
    VAR( uint8, TYPEDEF ) ControllerId; /* ID of CAN controller. */
} CanSMControllerType;

typedef struct /* CanSMNetworkType */ {
    TS_REF2CFG( CanSMControllerType )  CtrlRef; /* Reference to CanSM configured controllers. */
    VAR( uint16, TYPEDEF ) BorCounterL1ToL2; /* Bus-off recovery L1 to L2 Threshold. */
    VAR( uint16, TYPEDEF ) BorTimeL1; /* Duration to stay in level 1 check before restart of communication. */
    VAR( uint16, TYPEDEF ) BorTimeL2; /* Duration to stay in level 2 check before restart of communication. */
    VAR( uint16, TYPEDEF ) BorTimeTxEnsured; /* Duration until bus-off free communication is assumed. */
    VAR( uint16, TYPEDEF ) DemEventId; /* ID of referenced DEM event to be reported in case of bus-off errors. */
    VAR( uint8, TYPEDEF ) ComMChId; /* ID of referenced ComM channel. */
    VAR( uint8, TYPEDEF ) TrcvId; /* ID of CAN Transceiver. */
    VAR( uint8, TYPEDEF ) NumNwCtrl; /* Number of controllers per network. */
    VAR( boolean, TYPEDEF ) BorTxConfirmationPolling; /* BOR Tx Confirmation Polling. */
} CanSMNetworkType;

typedef struct /* CanSM_ConfigType */ {
    TS_REF2CFG( CanSMNetworkType )  NetRef; /* Reference to CanSM networks. */
    VAR( uint16, TYPEDEF ) ModeReqRepTime; /* Time duration after which a mode change request is repeated (in ticks). */
    VAR( uint8, TYPEDEF ) ModeReqRepMax; /* Maximum amount of mode change request repetitions. */
} CanSM_ConfigType;


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

#endif /* CANSM_TYPES_INT_H */

/*==================[end of file]============================================*/

