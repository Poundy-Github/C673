


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


/* MISRA-C:2012 Deviation List
 *
 * MISRAC2012-1) Deviated Rule: 1.3 (required)
 *    There shall be no occurrence of undefined or critical unspecified behaviour.
 *
 *    Reason:
 *    The postbuild macro TS_MAKEREF2CFG requires the usage of the
 *    C standard macro 'offsetof'.
 *    According to the C90 standard, the usage of 'offsetof' produces
 *    an undefined behaviour when the member designator parameter
 *    is a bit-field or when it is an invalid right operator of the
 *    '.' operator for the type parameter.
 *    This is not the case here as the parameter of TS_MAKEREF2CFG
 *    is always a member of TS_PB_CFG_LAYOUT_TYPE and bitfields are
 *    never used when defining the postbuild structure members.
 *
 * MISRAC2012-2) Deviated Rule: 11.4 (advisory)
 *    A cast should not be performed between a pointer type and an integral
 *    type.
 *
 *    Reason:
 *    Relocatable postbuild macro requires the cast between pointer and
 *    integral type.
 *
 * MISRAC2012-3) Deviated Rule: 11.9 (required)
 *    The macro NULL shall be the only permitted form of integer null pointer constant.
 *
 *    Reason:
 *    Macros are used in order to check the alignment for different data types.
 *
 */

/*==================[inclusions]=============================================*/

#include <CanSM_PBcfg.h>
#include <TSAutosar.h>
#include <Compiler.h>
#define TS_RELOCATABLE_CFG_ENABLE STD_OFF
#define TS_PB_CFG_NAME CanSM_ConfigLayout
#define TS_PB_CFG_LAYOUT_TYPE CanSM_ConstConfigLayoutType
#include <TSPBConfig_Init.h>

/*==================[macros]=================================================*/


/*==================[type definitions]=======================================*/


/*==================[external function declarations]=========================*/


/*==================[internal function declarations]=========================*/


/*==================[external constants]=====================================*/

#define CANSM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include <CanSM_MemMap.h>

/* Deviation MISRAC2012-1, MISRAC2012-2, MISRAC2012-3 <START> */
CanSM_ConstConfigLayoutType CanSM_ConfigLayout = {
    { /* RootCfg */
        TS_MAKEREF2CFG( CanSM_Net[0] ), /* NetRef */
        UINT16_C( 2 ), /* ModeReqRepTime */
        UINT8_C( 5 ) /* ModeReqRepMax */
    },
    { /* CanSM_Net */
        { /* CanSM_Net[0] */
            TS_MAKEREF2CFG( CanSM_Ctrl[0] ), /* CtrlRef */
            UINT16_C( 10 ), /* BorCounterL1ToL2 */
            UINT16_C( 8 ), /* BorTimeL1 */
            UINT16_C( 200 ), /* BorTimeL2 */
            UINT16_C( 200 ), /* BorTimeTxEnsured */
            UINT16_C( 84 ), /* DemEventId */
            UINT8_C( 0 ), /* ComMChId */
            UINT8_C( 0 ), /* TrcvId */
            UINT8_C( 1 ), /* NumNwCtrl */
            BOOLEAN_C( 0 ) /* BorTxConfirmationPolling */
        },
        { /* CanSM_Net[1] */
            TS_MAKEREF2CFG( CanSM_Ctrl[1] ), /* CtrlRef */
            UINT16_C( 10 ), /* BorCounterL1ToL2 */
            UINT16_C( 8 ), /* BorTimeL1 */
            UINT16_C( 200 ), /* BorTimeL2 */
            UINT16_C( 200 ), /* BorTimeTxEnsured */
            UINT16_C( 83 ), /* DemEventId */
            UINT8_C( 1 ), /* ComMChId */
            UINT8_C( 255 ), /* TrcvId */
            UINT8_C( 1 ), /* NumNwCtrl */
            BOOLEAN_C( 0 ) /* BorTxConfirmationPolling */
        }
    },
    { /* CanSM_Ctrl */
        { /* CanSM_Ctrl[0] */
            UINT8_C( 0 ) /* ControllerId */
        },
        { /* CanSM_Ctrl[1] */
            UINT8_C( 1 ) /* ControllerId */
        }
    }
};

/* Deviation MISRAC2012-1, MISRAC2012-2, MISRAC2012-3 <STOP> */

#define CANSM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include <CanSM_MemMap.h>

/*==================[internal constants]=====================================*/


/*==================[external data]==========================================*/


/*==================[internal data]==========================================*/


/*==================[external function definitions]==========================*/


/*==================[internal function definitions]==========================*/


/*==================[end of file]============================================*/

