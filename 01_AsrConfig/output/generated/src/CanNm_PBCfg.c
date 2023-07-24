


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

#include <CanNm_PBcfg.h>
#include <TSAutosar.h>
#include <Compiler.h>
#define TS_RELOCATABLE_CFG_ENABLE STD_ON
#define TS_PB_CFG_NAME CanNm_ConfigLayout
#define TS_PB_CFG_LAYOUT_TYPE CanNm_ConstConfigLayoutType
#include <TSPBConfig_Init.h>

/*==================[macros]=================================================*/


/*==================[type definitions]=======================================*/


/*==================[external function declarations]=========================*/


/*==================[internal function declarations]=========================*/


/*==================[external constants]=====================================*/

#define CANNM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include <CanNm_MemMap.h>

/* Deviation MISRAC2012-1, MISRAC2012-2, MISRAC2012-3 <START> */
CanNm_ConstConfigLayoutType CanNm_ConfigLayout = {
    { /* RootCfg */
        UINT32_C( 2281703698 ), /* PlatformSignature */
        UINT32_C( 3958107115 ), /* LcfgSignature */
        UINT32_C( 670254499 ), /* CfgSignature */
        UINT32_C( 1750501377 ), /* PublicInfoSignature */
        { /* CanNm_ChannelData */
            { /* CanNm_ChannelData[0] */
                UINT32_C( 0 ), /* UserDataLength */
                UINT16_C( 1 ), /* CanNmMsgCycleOffset */
                UINT16_C( 8 ), /* RxPduLength */
                UINT16_C( 0 ), /* UserTxConfPduId */
                UINT16_C( 0 ), /* UserRxPduId */
                UINT16_C( 49 ), /* TxPduId */
                UINT8_C( 82 ), /* CanNmNodeId */
                BOOLEAN_C( 0 ) /* UserRxPduEnabled */
            }
        },
        { /* BufferOffsets */
            UINT32_C( 0 ) /* BufferOffsets[0] */
        },
        UINT32_C( 8 ), /* TxBufferOffset */
        UINT32_C( 16 ) /* PbRequiredCfgRamSize */
    }
};

/* Deviation MISRAC2012-1, MISRAC2012-2, MISRAC2012-3 <STOP> */

#define CANNM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include <CanNm_MemMap.h>

/*==================[internal constants]=====================================*/


/*==================[external data]==========================================*/


/*==================[internal data]==========================================*/


/*==================[external function definitions]==========================*/


/*==================[internal function definitions]==========================*/


/*==================[end of file]============================================*/

