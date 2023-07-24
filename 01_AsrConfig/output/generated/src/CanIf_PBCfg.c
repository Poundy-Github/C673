


/**
 * \file
 *
 * \brief AUTOSAR CanIf
 *
 * This file contains the implementation of the AUTOSAR
 * module CanIf.
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

#include <CanIf_PBcfg.h>
#include <TSAutosar.h>
#include <Compiler.h>
#define TS_RELOCATABLE_CFG_ENABLE STD_ON
#define TS_PB_CFG_NAME CanIf_ConfigLayout
#define TS_PB_CFG_LAYOUT_TYPE CanIf_ConstConfigLayoutType
#include <TSPBConfig_Init.h>

/*==================[macros]=================================================*/


/*==================[type definitions]=======================================*/


/*==================[external function declarations]=========================*/


/*==================[internal function declarations]=========================*/


/*==================[external constants]=====================================*/

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include <CanIf_MemMap.h>

/* Deviation MISRAC2012-1, MISRAC2012-2, MISRAC2012-3 <START> */
CanIf_ConstConfigLayoutType CanIf_ConfigLayout = {
    { /* RootCfg */
        UINT32_C( 2281703698 ), /* PlatformSignature */
        UINT32_C( 1140991788 ), /* LcfgSignature */
        UINT32_C( 309991485 ), /* CfgSignature */
        UINT32_C( 3439262691 ), /* PublicInfoSignature */
        TS_MAKEREF2CFG( txLPduConfig[0] ), /* txLPduConfigPtr */
        TS_MAKEREF2CFG( rxLPduConfig[0] ), /* rxLPduConfigPtr */
        TS_MAKEREF2CFG( sortedRxLPduConfig[0] ), /* sortedRxLPduConfigPtr */
        TS_MAKEREF2CFG( canDriverConfig[0] ), /* driverConfigPtr */
        TS_MAKEREF2CFG( canTrcvChnlConfig[0] ), /* trcvChnlConfigPtr */
        UINT16_C( 53 ), /* nrOfStaticTxLPdus */
        UINT16_C( 53 ), /* nrOfTxLPdus */
        UINT16_C( 54 ), /* nrOfRxLPdus */
        UINT16_C( 53 ), /* nrOfTxBuffers */
        UINT8_C( 1 ), /* maxCanControllerId */
        UINT8_C( 1 ) /* nrOfTransceivers */
    },
    { /* txLPduConfig */
        { /* txLPduConfig[0] */
            UINT32_C( 1073742266 ), /* canId */
            UINT8_C( 52 ), /* hth */
            UINT16_C( 0 ), /* bufferIndex */
            UINT16_C( 0 ), /* memIndex */
            UINT16_C( 0 ), /* sourcePduId_UL */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 0 ), /* intCtrlIdx */
            UINT16_C( 32 ), /* PduLength */
            UINT8_C( 3 ) /* truncateOptions */
        },
        { /* txLPduConfig[1] */
            UINT32_C( 1073742404 ), /* canId */
            UINT8_C( 52 ), /* hth */
            UINT16_C( 1 ), /* bufferIndex */
            UINT16_C( 64 ), /* memIndex */
            UINT16_C( 1 ), /* sourcePduId_UL */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 0 ), /* intCtrlIdx */
            UINT16_C( 64 ), /* PduLength */
            UINT8_C( 3 ) /* truncateOptions */
        },
        { /* txLPduConfig[2] */
            UINT32_C( 1073742599 ), /* canId */
            UINT8_C( 52 ), /* hth */
            UINT16_C( 2 ), /* bufferIndex */
            UINT16_C( 128 ), /* memIndex */
            UINT16_C( 2 ), /* sourcePduId_UL */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 0 ), /* intCtrlIdx */
            UINT16_C( 64 ), /* PduLength */
            UINT8_C( 3 ) /* truncateOptions */
        },
        { /* txLPduConfig[3] */
            UINT32_C( 1073742610 ), /* canId */
            UINT8_C( 52 ), /* hth */
            UINT16_C( 3 ), /* bufferIndex */
            UINT16_C( 192 ), /* memIndex */
            UINT16_C( 3 ), /* sourcePduId_UL */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 0 ), /* intCtrlIdx */
            UINT16_C( 64 ), /* PduLength */
            UINT8_C( 3 ) /* truncateOptions */
        },
        { /* txLPduConfig[4] */
            UINT32_C( 1073742618 ), /* canId */
            UINT8_C( 52 ), /* hth */
            UINT16_C( 4 ), /* bufferIndex */
            UINT16_C( 256 ), /* memIndex */
            UINT16_C( 4 ), /* sourcePduId_UL */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 0 ), /* intCtrlIdx */
            UINT16_C( 64 ), /* PduLength */
            UINT8_C( 3 ) /* truncateOptions */
        },
        { /* txLPduConfig[5] */
            UINT32_C( 1073743217 ), /* canId */
            UINT8_C( 52 ), /* hth */
            UINT16_C( 5 ), /* bufferIndex */
            UINT16_C( 320 ), /* memIndex */
            UINT16_C( 5 ), /* sourcePduId_UL */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 0 ), /* intCtrlIdx */
            UINT16_C( 16 ), /* PduLength */
            UINT8_C( 3 ) /* truncateOptions */
        },
        { /* txLPduConfig[6] */
            UINT32_C( 1073743250 ), /* canId */
            UINT8_C( 52 ), /* hth */
            UINT16_C( 6 ), /* bufferIndex */
            UINT16_C( 384 ), /* memIndex */
            UINT16_C( 6 ), /* sourcePduId_UL */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 0 ), /* intCtrlIdx */
            UINT16_C( 8 ), /* PduLength */
            UINT8_C( 3 ) /* truncateOptions */
        },
        { /* txLPduConfig[7] */
            UINT32_C( 1073743508 ), /* canId */
            UINT8_C( 52 ), /* hth */
            UINT16_C( 7 ), /* bufferIndex */
            UINT16_C( 448 ), /* memIndex */
            UINT16_C( 7 ), /* sourcePduId_UL */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 0 ), /* intCtrlIdx */
            UINT16_C( 8 ), /* PduLength */
            UINT8_C( 3 ) /* truncateOptions */
        },
        { /* txLPduConfig[8] */
            UINT32_C( 1899 ), /* canId */
            UINT8_C( 52 ), /* hth */
            UINT16_C( 8 ), /* bufferIndex */
            UINT16_C( 512 ), /* memIndex */
            UINT16_C( 0 ), /* sourcePduId_UL */
            UINT8_C( 1 ), /* userType */
            UINT8_C( 0 ), /* intCtrlIdx */
            UINT16_C( 8 ), /* PduLength */
            UINT8_C( 3 ) /* truncateOptions */
        },
        { /* txLPduConfig[9] */
            UINT32_C( 1899 ), /* canId */
            UINT8_C( 52 ), /* hth */
            UINT16_C( 9 ), /* bufferIndex */
            UINT16_C( 520 ), /* memIndex */
            UINT16_C( 2 ), /* sourcePduId_UL */
            UINT8_C( 1 ), /* userType */
            UINT8_C( 0 ), /* intCtrlIdx */
            UINT16_C( 8 ), /* PduLength */
            UINT8_C( 3 ) /* truncateOptions */
        },
        { /* txLPduConfig[10] */
            UINT32_C( 1073743706 ), /* canId */
            UINT8_C( 52 ), /* hth */
            UINT16_C( 10 ), /* bufferIndex */
            UINT16_C( 528 ), /* memIndex */
            UINT16_C( 1 ), /* sourcePduId_UL */
            UINT8_C( 1 ), /* userType */
            UINT8_C( 0 ), /* intCtrlIdx */
            UINT16_C( 64 ), /* PduLength */
            UINT8_C( 3 ) /* truncateOptions */
        },
        { /* txLPduConfig[11] */
            UINT32_C( 1073743706 ), /* canId */
            UINT8_C( 52 ), /* hth */
            UINT16_C( 11 ), /* bufferIndex */
            UINT16_C( 592 ), /* memIndex */
            UINT16_C( 3 ), /* sourcePduId_UL */
            UINT8_C( 1 ), /* userType */
            UINT8_C( 0 ), /* intCtrlIdx */
            UINT16_C( 64 ), /* PduLength */
            UINT8_C( 3 ) /* truncateOptions */
        },
        { /* txLPduConfig[12] */
            UINT32_C( 1073742087 ), /* canId */
            UINT8_C( 53 ), /* hth */
            UINT16_C( 12 ), /* bufferIndex */
            UINT16_C( 656 ), /* memIndex */
            UINT16_C( 8 ), /* sourcePduId_UL */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 1 ), /* intCtrlIdx */
            UINT16_C( 64 ), /* PduLength */
            UINT8_C( 3 ) /* truncateOptions */
        },
        { /* txLPduConfig[13] */
            UINT32_C( 1073742088 ), /* canId */
            UINT8_C( 53 ), /* hth */
            UINT16_C( 13 ), /* bufferIndex */
            UINT16_C( 720 ), /* memIndex */
            UINT16_C( 9 ), /* sourcePduId_UL */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 1 ), /* intCtrlIdx */
            UINT16_C( 64 ), /* PduLength */
            UINT8_C( 3 ) /* truncateOptions */
        },
        { /* txLPduConfig[14] */
            UINT32_C( 1538 ), /* canId */
            UINT8_C( 52 ), /* hth */
            UINT16_C( 14 ), /* bufferIndex */
            UINT16_C( 784 ), /* memIndex */
            UINT16_C( 0 ), /* sourcePduId_UL */
            UINT8_C( 2 ), /* userType */
            UINT8_C( 0 ), /* intCtrlIdx */
            UINT16_C( 8 ), /* PduLength */
            UINT8_C( 3 ) /* truncateOptions */
        },
        { /* txLPduConfig[15] */
            UINT32_C( 1073742160 ), /* canId */
            UINT8_C( 53 ), /* hth */
            UINT16_C( 15 ), /* bufferIndex */
            UINT16_C( 792 ), /* memIndex */
            UINT16_C( 10 ), /* sourcePduId_UL */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 1 ), /* intCtrlIdx */
            UINT16_C( 64 ), /* PduLength */
            UINT8_C( 3 ) /* truncateOptions */
        },
        { /* txLPduConfig[16] */
            UINT32_C( 1073742161 ), /* canId */
            UINT8_C( 53 ), /* hth */
            UINT16_C( 16 ), /* bufferIndex */
            UINT16_C( 856 ), /* memIndex */
            UINT16_C( 11 ), /* sourcePduId_UL */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 1 ), /* intCtrlIdx */
            UINT16_C( 64 ), /* PduLength */
            UINT8_C( 3 ) /* truncateOptions */
        },
        { /* txLPduConfig[17] */
            UINT32_C( 1073742162 ), /* canId */
            UINT8_C( 53 ), /* hth */
            UINT16_C( 17 ), /* bufferIndex */
            UINT16_C( 920 ), /* memIndex */
            UINT16_C( 12 ), /* sourcePduId_UL */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 1 ), /* intCtrlIdx */
            UINT16_C( 64 ), /* PduLength */
            UINT8_C( 3 ) /* truncateOptions */
        },
        { /* txLPduConfig[18] */
            UINT32_C( 1073742163 ), /* canId */
            UINT8_C( 53 ), /* hth */
            UINT16_C( 18 ), /* bufferIndex */
            UINT16_C( 984 ), /* memIndex */
            UINT16_C( 13 ), /* sourcePduId_UL */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 1 ), /* intCtrlIdx */
            UINT16_C( 64 ), /* PduLength */
            UINT8_C( 3 ) /* truncateOptions */
        },
        { /* txLPduConfig[19] */
            UINT32_C( 1073742164 ), /* canId */
            UINT8_C( 53 ), /* hth */
            UINT16_C( 19 ), /* bufferIndex */
            UINT16_C( 1048 ), /* memIndex */
            UINT16_C( 14 ), /* sourcePduId_UL */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 1 ), /* intCtrlIdx */
            UINT16_C( 64 ), /* PduLength */
            UINT8_C( 3 ) /* truncateOptions */
        },
        { /* txLPduConfig[20] */
            UINT32_C( 1073742176 ), /* canId */
            UINT8_C( 53 ), /* hth */
            UINT16_C( 20 ), /* bufferIndex */
            UINT16_C( 1112 ), /* memIndex */
            UINT16_C( 15 ), /* sourcePduId_UL */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 1 ), /* intCtrlIdx */
            UINT16_C( 64 ), /* PduLength */
            UINT8_C( 3 ) /* truncateOptions */
        },
        { /* txLPduConfig[21] */
            UINT32_C( 1073742177 ), /* canId */
            UINT8_C( 53 ), /* hth */
            UINT16_C( 21 ), /* bufferIndex */
            UINT16_C( 1176 ), /* memIndex */
            UINT16_C( 16 ), /* sourcePduId_UL */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 1 ), /* intCtrlIdx */
            UINT16_C( 64 ), /* PduLength */
            UINT8_C( 3 ) /* truncateOptions */
        },
        { /* txLPduConfig[22] */
            UINT32_C( 1073742178 ), /* canId */
            UINT8_C( 53 ), /* hth */
            UINT16_C( 22 ), /* bufferIndex */
            UINT16_C( 1240 ), /* memIndex */
            UINT16_C( 17 ), /* sourcePduId_UL */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 1 ), /* intCtrlIdx */
            UINT16_C( 64 ), /* PduLength */
            UINT8_C( 3 ) /* truncateOptions */
        },
        { /* txLPduConfig[23] */
            UINT32_C( 1073742179 ), /* canId */
            UINT8_C( 53 ), /* hth */
            UINT16_C( 23 ), /* bufferIndex */
            UINT16_C( 1304 ), /* memIndex */
            UINT16_C( 18 ), /* sourcePduId_UL */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 1 ), /* intCtrlIdx */
            UINT16_C( 64 ), /* PduLength */
            UINT8_C( 3 ) /* truncateOptions */
        },
        { /* txLPduConfig[24] */
            UINT32_C( 1073742180 ), /* canId */
            UINT8_C( 53 ), /* hth */
            UINT16_C( 24 ), /* bufferIndex */
            UINT16_C( 1368 ), /* memIndex */
            UINT16_C( 19 ), /* sourcePduId_UL */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 1 ), /* intCtrlIdx */
            UINT16_C( 64 ), /* PduLength */
            UINT8_C( 3 ) /* truncateOptions */
        },
        { /* txLPduConfig[25] */
            UINT32_C( 1073742181 ), /* canId */
            UINT8_C( 53 ), /* hth */
            UINT16_C( 25 ), /* bufferIndex */
            UINT16_C( 1432 ), /* memIndex */
            UINT16_C( 20 ), /* sourcePduId_UL */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 1 ), /* intCtrlIdx */
            UINT16_C( 64 ), /* PduLength */
            UINT8_C( 3 ) /* truncateOptions */
        },
        { /* txLPduConfig[26] */
            UINT32_C( 1073742182 ), /* canId */
            UINT8_C( 53 ), /* hth */
            UINT16_C( 26 ), /* bufferIndex */
            UINT16_C( 1496 ), /* memIndex */
            UINT16_C( 21 ), /* sourcePduId_UL */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 1 ), /* intCtrlIdx */
            UINT16_C( 64 ), /* PduLength */
            UINT8_C( 3 ) /* truncateOptions */
        },
        { /* txLPduConfig[27] */
            UINT32_C( 1073742183 ), /* canId */
            UINT8_C( 53 ), /* hth */
            UINT16_C( 27 ), /* bufferIndex */
            UINT16_C( 1560 ), /* memIndex */
            UINT16_C( 22 ), /* sourcePduId_UL */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 1 ), /* intCtrlIdx */
            UINT16_C( 64 ), /* PduLength */
            UINT8_C( 3 ) /* truncateOptions */
        },
        { /* txLPduConfig[28] */
            UINT32_C( 1073742184 ), /* canId */
            UINT8_C( 53 ), /* hth */
            UINT16_C( 28 ), /* bufferIndex */
            UINT16_C( 1624 ), /* memIndex */
            UINT16_C( 23 ), /* sourcePduId_UL */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 1 ), /* intCtrlIdx */
            UINT16_C( 64 ), /* PduLength */
            UINT8_C( 3 ) /* truncateOptions */
        },
        { /* txLPduConfig[29] */
            UINT32_C( 1073742185 ), /* canId */
            UINT8_C( 53 ), /* hth */
            UINT16_C( 29 ), /* bufferIndex */
            UINT16_C( 1688 ), /* memIndex */
            UINT16_C( 24 ), /* sourcePduId_UL */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 1 ), /* intCtrlIdx */
            UINT16_C( 64 ), /* PduLength */
            UINT8_C( 3 ) /* truncateOptions */
        },
        { /* txLPduConfig[30] */
            UINT32_C( 1073742192 ), /* canId */
            UINT8_C( 53 ), /* hth */
            UINT16_C( 30 ), /* bufferIndex */
            UINT16_C( 1752 ), /* memIndex */
            UINT16_C( 25 ), /* sourcePduId_UL */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 1 ), /* intCtrlIdx */
            UINT16_C( 64 ), /* PduLength */
            UINT8_C( 3 ) /* truncateOptions */
        },
        { /* txLPduConfig[31] */
            UINT32_C( 1073742193 ), /* canId */
            UINT8_C( 53 ), /* hth */
            UINT16_C( 31 ), /* bufferIndex */
            UINT16_C( 1816 ), /* memIndex */
            UINT16_C( 26 ), /* sourcePduId_UL */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 1 ), /* intCtrlIdx */
            UINT16_C( 64 ), /* PduLength */
            UINT8_C( 3 ) /* truncateOptions */
        },
        { /* txLPduConfig[32] */
            UINT32_C( 1073742194 ), /* canId */
            UINT8_C( 53 ), /* hth */
            UINT16_C( 32 ), /* bufferIndex */
            UINT16_C( 1880 ), /* memIndex */
            UINT16_C( 27 ), /* sourcePduId_UL */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 1 ), /* intCtrlIdx */
            UINT16_C( 64 ), /* PduLength */
            UINT8_C( 3 ) /* truncateOptions */
        },
        { /* txLPduConfig[33] */
            UINT32_C( 1073742195 ), /* canId */
            UINT8_C( 53 ), /* hth */
            UINT16_C( 33 ), /* bufferIndex */
            UINT16_C( 1944 ), /* memIndex */
            UINT16_C( 28 ), /* sourcePduId_UL */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 1 ), /* intCtrlIdx */
            UINT16_C( 64 ), /* PduLength */
            UINT8_C( 3 ) /* truncateOptions */
        },
        { /* txLPduConfig[34] */
            UINT32_C( 1073742196 ), /* canId */
            UINT8_C( 53 ), /* hth */
            UINT16_C( 34 ), /* bufferIndex */
            UINT16_C( 2008 ), /* memIndex */
            UINT16_C( 29 ), /* sourcePduId_UL */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 1 ), /* intCtrlIdx */
            UINT16_C( 64 ), /* PduLength */
            UINT8_C( 3 ) /* truncateOptions */
        },
        { /* txLPduConfig[35] */
            UINT32_C( 1073742197 ), /* canId */
            UINT8_C( 53 ), /* hth */
            UINT16_C( 35 ), /* bufferIndex */
            UINT16_C( 2072 ), /* memIndex */
            UINT16_C( 30 ), /* sourcePduId_UL */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 1 ), /* intCtrlIdx */
            UINT16_C( 64 ), /* PduLength */
            UINT8_C( 3 ) /* truncateOptions */
        },
        { /* txLPduConfig[36] */
            UINT32_C( 1073742198 ), /* canId */
            UINT8_C( 53 ), /* hth */
            UINT16_C( 36 ), /* bufferIndex */
            UINT16_C( 2136 ), /* memIndex */
            UINT16_C( 31 ), /* sourcePduId_UL */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 1 ), /* intCtrlIdx */
            UINT16_C( 64 ), /* PduLength */
            UINT8_C( 3 ) /* truncateOptions */
        },
        { /* txLPduConfig[37] */
            UINT32_C( 1073742199 ), /* canId */
            UINT8_C( 53 ), /* hth */
            UINT16_C( 37 ), /* bufferIndex */
            UINT16_C( 2200 ), /* memIndex */
            UINT16_C( 32 ), /* sourcePduId_UL */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 1 ), /* intCtrlIdx */
            UINT16_C( 64 ), /* PduLength */
            UINT8_C( 3 ) /* truncateOptions */
        },
        { /* txLPduConfig[38] */
            UINT32_C( 1073742200 ), /* canId */
            UINT8_C( 53 ), /* hth */
            UINT16_C( 38 ), /* bufferIndex */
            UINT16_C( 2264 ), /* memIndex */
            UINT16_C( 33 ), /* sourcePduId_UL */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 1 ), /* intCtrlIdx */
            UINT16_C( 64 ), /* PduLength */
            UINT8_C( 3 ) /* truncateOptions */
        },
        { /* txLPduConfig[39] */
            UINT32_C( 1073742201 ), /* canId */
            UINT8_C( 53 ), /* hth */
            UINT16_C( 39 ), /* bufferIndex */
            UINT16_C( 2328 ), /* memIndex */
            UINT16_C( 34 ), /* sourcePduId_UL */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 1 ), /* intCtrlIdx */
            UINT16_C( 64 ), /* PduLength */
            UINT8_C( 3 ) /* truncateOptions */
        },
        { /* txLPduConfig[40] */
            UINT32_C( 1073742208 ), /* canId */
            UINT8_C( 53 ), /* hth */
            UINT16_C( 40 ), /* bufferIndex */
            UINT16_C( 2392 ), /* memIndex */
            UINT16_C( 35 ), /* sourcePduId_UL */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 1 ), /* intCtrlIdx */
            UINT16_C( 64 ), /* PduLength */
            UINT8_C( 3 ) /* truncateOptions */
        },
        { /* txLPduConfig[41] */
            UINT32_C( 1073742209 ), /* canId */
            UINT8_C( 53 ), /* hth */
            UINT16_C( 41 ), /* bufferIndex */
            UINT16_C( 2456 ), /* memIndex */
            UINT16_C( 36 ), /* sourcePduId_UL */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 1 ), /* intCtrlIdx */
            UINT16_C( 64 ), /* PduLength */
            UINT8_C( 3 ) /* truncateOptions */
        },
        { /* txLPduConfig[42] */
            UINT32_C( 1073742224 ), /* canId */
            UINT8_C( 53 ), /* hth */
            UINT16_C( 42 ), /* bufferIndex */
            UINT16_C( 2520 ), /* memIndex */
            UINT16_C( 37 ), /* sourcePduId_UL */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 1 ), /* intCtrlIdx */
            UINT16_C( 64 ), /* PduLength */
            UINT8_C( 3 ) /* truncateOptions */
        },
        { /* txLPduConfig[43] */
            UINT32_C( 1073742227 ), /* canId */
            UINT8_C( 53 ), /* hth */
            UINT16_C( 43 ), /* bufferIndex */
            UINT16_C( 2584 ), /* memIndex */
            UINT16_C( 38 ), /* sourcePduId_UL */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 1 ), /* intCtrlIdx */
            UINT16_C( 64 ), /* PduLength */
            UINT8_C( 3 ) /* truncateOptions */
        },
        { /* txLPduConfig[44] */
            UINT32_C( 1073742229 ), /* canId */
            UINT8_C( 53 ), /* hth */
            UINT16_C( 44 ), /* bufferIndex */
            UINT16_C( 2648 ), /* memIndex */
            UINT16_C( 39 ), /* sourcePduId_UL */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 1 ), /* intCtrlIdx */
            UINT16_C( 64 ), /* PduLength */
            UINT8_C( 3 ) /* truncateOptions */
        },
        { /* txLPduConfig[45] */
            UINT32_C( 1073742230 ), /* canId */
            UINT8_C( 53 ), /* hth */
            UINT16_C( 45 ), /* bufferIndex */
            UINT16_C( 2712 ), /* memIndex */
            UINT16_C( 40 ), /* sourcePduId_UL */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 1 ), /* intCtrlIdx */
            UINT16_C( 64 ), /* PduLength */
            UINT8_C( 3 ) /* truncateOptions */
        },
        { /* txLPduConfig[46] */
            UINT32_C( 1073742231 ), /* canId */
            UINT8_C( 53 ), /* hth */
            UINT16_C( 46 ), /* bufferIndex */
            UINT16_C( 2776 ), /* memIndex */
            UINT16_C( 41 ), /* sourcePduId_UL */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 1 ), /* intCtrlIdx */
            UINT16_C( 64 ), /* PduLength */
            UINT8_C( 3 ) /* truncateOptions */
        },
        { /* txLPduConfig[47] */
            UINT32_C( 1073742232 ), /* canId */
            UINT8_C( 53 ), /* hth */
            UINT16_C( 47 ), /* bufferIndex */
            UINT16_C( 2840 ), /* memIndex */
            UINT16_C( 42 ), /* sourcePduId_UL */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 1 ), /* intCtrlIdx */
            UINT16_C( 64 ), /* PduLength */
            UINT8_C( 3 ) /* truncateOptions */
        },
        { /* txLPduConfig[48] */
            UINT32_C( 1073742322 ), /* canId */
            UINT8_C( 53 ), /* hth */
            UINT16_C( 48 ), /* bufferIndex */
            UINT16_C( 2904 ), /* memIndex */
            UINT16_C( 43 ), /* sourcePduId_UL */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 1 ), /* intCtrlIdx */
            UINT16_C( 8 ), /* PduLength */
            UINT8_C( 3 ) /* truncateOptions */
        },
        { /* txLPduConfig[49] */
            UINT32_C( 1106 ), /* canId */
            UINT8_C( 52 ), /* hth */
            UINT16_C( 49 ), /* bufferIndex */
            UINT16_C( 2968 ), /* memIndex */
            UINT16_C( 0 ), /* sourcePduId_UL */
            UINT8_C( 5 ), /* userType */
            UINT8_C( 0 ), /* intCtrlIdx */
            UINT16_C( 8 ), /* PduLength */
            UINT8_C( 3 ) /* truncateOptions */
        },
        { /* txLPduConfig[50] */
            UINT32_C( 1073742340 ), /* canId */
            UINT8_C( 53 ), /* hth */
            UINT16_C( 50 ), /* bufferIndex */
            UINT16_C( 2976 ), /* memIndex */
            UINT16_C( 44 ), /* sourcePduId_UL */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 1 ), /* intCtrlIdx */
            UINT16_C( 64 ), /* PduLength */
            UINT8_C( 3 ) /* truncateOptions */
        },
        { /* txLPduConfig[51] */
            UINT32_C( 1073742343 ), /* canId */
            UINT8_C( 53 ), /* hth */
            UINT16_C( 51 ), /* bufferIndex */
            UINT16_C( 3040 ), /* memIndex */
            UINT16_C( 45 ), /* sourcePduId_UL */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 1 ), /* intCtrlIdx */
            UINT16_C( 64 ), /* PduLength */
            UINT8_C( 3 ) /* truncateOptions */
        },
        { /* txLPduConfig[52] */
            UINT32_C( 1073743392 ), /* canId */
            UINT8_C( 53 ), /* hth */
            UINT16_C( 52 ), /* bufferIndex */
            UINT16_C( 3104 ), /* memIndex */
            UINT16_C( 0 ), /* sourcePduId_UL */
            UINT8_C( 255 ), /* userType */
            UINT8_C( 1 ), /* intCtrlIdx */
            UINT16_C( 64 ), /* PduLength */
            UINT8_C( 3 ) /* truncateOptions */
        }
    },
    { /* rxLPduConfig */
        { /* rxLPduConfig[0] */
            UINT16_C( 0 ), /* targetPduId */
            UINT8_C( 8 ), /* limitedPduLength */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 8 ) /* dlc */
        },
        { /* rxLPduConfig[1] */
            UINT16_C( 1 ), /* targetPduId */
            UINT8_C( 64 ), /* limitedPduLength */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 64 ) /* dlc */
        },
        { /* rxLPduConfig[2] */
            UINT16_C( 2 ), /* targetPduId */
            UINT8_C( 8 ), /* limitedPduLength */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 8 ) /* dlc */
        },
        { /* rxLPduConfig[3] */
            UINT16_C( 3 ), /* targetPduId */
            UINT8_C( 64 ), /* limitedPduLength */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 8 ) /* dlc */
        },
        { /* rxLPduConfig[4] */
            UINT16_C( 4 ), /* targetPduId */
            UINT8_C( 8 ), /* limitedPduLength */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 8 ) /* dlc */
        },
        { /* rxLPduConfig[5] */
            UINT16_C( 5 ), /* targetPduId */
            UINT8_C( 8 ), /* limitedPduLength */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 8 ) /* dlc */
        },
        { /* rxLPduConfig[6] */
            UINT16_C( 6 ), /* targetPduId */
            UINT8_C( 64 ), /* limitedPduLength */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 64 ) /* dlc */
        },
        { /* rxLPduConfig[7] */
            UINT16_C( 7 ), /* targetPduId */
            UINT8_C( 64 ), /* limitedPduLength */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 64 ) /* dlc */
        },
        { /* rxLPduConfig[8] */
            UINT16_C( 8 ), /* targetPduId */
            UINT8_C( 8 ), /* limitedPduLength */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 8 ) /* dlc */
        },
        { /* rxLPduConfig[9] */
            UINT16_C( 9 ), /* targetPduId */
            UINT8_C( 8 ), /* limitedPduLength */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 8 ) /* dlc */
        },
        { /* rxLPduConfig[10] */
            UINT16_C( 10 ), /* targetPduId */
            UINT8_C( 8 ), /* limitedPduLength */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 8 ) /* dlc */
        },
        { /* rxLPduConfig[11] */
            UINT16_C( 11 ), /* targetPduId */
            UINT8_C( 8 ), /* limitedPduLength */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 8 ) /* dlc */
        },
        { /* rxLPduConfig[12] */
            UINT16_C( 12 ), /* targetPduId */
            UINT8_C( 64 ), /* limitedPduLength */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 64 ) /* dlc */
        },
        { /* rxLPduConfig[13] */
            UINT16_C( 13 ), /* targetPduId */
            UINT8_C( 64 ), /* limitedPduLength */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 64 ) /* dlc */
        },
        { /* rxLPduConfig[14] */
            UINT16_C( 14 ), /* targetPduId */
            UINT8_C( 64 ), /* limitedPduLength */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 64 ) /* dlc */
        },
        { /* rxLPduConfig[15] */
            UINT16_C( 15 ), /* targetPduId */
            UINT8_C( 8 ), /* limitedPduLength */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 8 ) /* dlc */
        },
        { /* rxLPduConfig[16] */
            UINT16_C( 16 ), /* targetPduId */
            UINT8_C( 64 ), /* limitedPduLength */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 64 ) /* dlc */
        },
        { /* rxLPduConfig[17] */
            UINT16_C( 17 ), /* targetPduId */
            UINT8_C( 8 ), /* limitedPduLength */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 8 ) /* dlc */
        },
        { /* rxLPduConfig[18] */
            UINT16_C( 18 ), /* targetPduId */
            UINT8_C( 64 ), /* limitedPduLength */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 64 ) /* dlc */
        },
        { /* rxLPduConfig[19] */
            UINT16_C( 0 ), /* targetPduId */
            UINT8_C( 16 ), /* limitedPduLength */
            UINT8_C( 3 ), /* userType */
            UINT8_C( 16 ) /* dlc */
        },
        { /* rxLPduConfig[20] */
            UINT16_C( 19 ), /* targetPduId */
            UINT8_C( 64 ), /* limitedPduLength */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 64 ) /* dlc */
        },
        { /* rxLPduConfig[21] */
            UINT16_C( 20 ), /* targetPduId */
            UINT8_C( 64 ), /* limitedPduLength */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 64 ) /* dlc */
        },
        { /* rxLPduConfig[22] */
            UINT16_C( 21 ), /* targetPduId */
            UINT8_C( 64 ), /* limitedPduLength */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 64 ) /* dlc */
        },
        { /* rxLPduConfig[23] */
            UINT16_C( 3 ), /* targetPduId */
            UINT8_C( 8 ), /* limitedPduLength */
            UINT8_C( 1 ), /* userType */
            UINT8_C( 0 ) /* dlc */
        },
        { /* rxLPduConfig[24] */
            UINT16_C( 0 ), /* targetPduId */
            UINT8_C( 8 ), /* limitedPduLength */
            UINT8_C( 1 ), /* userType */
            UINT8_C( 0 ) /* dlc */
        },
        { /* rxLPduConfig[25] */
            UINT16_C( 2 ), /* targetPduId */
            UINT8_C( 64 ), /* limitedPduLength */
            UINT8_C( 1 ), /* userType */
            UINT8_C( 0 ) /* dlc */
        },
        { /* rxLPduConfig[26] */
            UINT16_C( 1 ), /* targetPduId */
            UINT8_C( 64 ), /* limitedPduLength */
            UINT8_C( 1 ), /* userType */
            UINT8_C( 0 ) /* dlc */
        },
        { /* rxLPduConfig[27] */
            UINT16_C( 22 ), /* targetPduId */
            UINT8_C( 64 ), /* limitedPduLength */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 64 ) /* dlc */
        },
        { /* rxLPduConfig[28] */
            UINT16_C( 23 ), /* targetPduId */
            UINT8_C( 64 ), /* limitedPduLength */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 64 ) /* dlc */
        },
        { /* rxLPduConfig[29] */
            UINT16_C( 24 ), /* targetPduId */
            UINT8_C( 64 ), /* limitedPduLength */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 64 ) /* dlc */
        },
        { /* rxLPduConfig[30] */
            UINT16_C( 0 ), /* targetPduId */
            UINT8_C( 8 ), /* limitedPduLength */
            UINT8_C( 2 ), /* userType */
            UINT8_C( 8 ) /* dlc */
        },
        { /* rxLPduConfig[31] */
            UINT16_C( 25 ), /* targetPduId */
            UINT8_C( 64 ), /* limitedPduLength */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 64 ) /* dlc */
        },
        { /* rxLPduConfig[32] */
            UINT16_C( 26 ), /* targetPduId */
            UINT8_C( 64 ), /* limitedPduLength */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 64 ) /* dlc */
        },
        { /* rxLPduConfig[33] */
            UINT16_C( 27 ), /* targetPduId */
            UINT8_C( 64 ), /* limitedPduLength */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 64 ) /* dlc */
        },
        { /* rxLPduConfig[34] */
            UINT16_C( 28 ), /* targetPduId */
            UINT8_C( 64 ), /* limitedPduLength */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 64 ) /* dlc */
        },
        { /* rxLPduConfig[35] */
            UINT16_C( 29 ), /* targetPduId */
            UINT8_C( 64 ), /* limitedPduLength */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 64 ) /* dlc */
        },
        { /* rxLPduConfig[36] */
            UINT16_C( 30 ), /* targetPduId */
            UINT8_C( 64 ), /* limitedPduLength */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 64 ) /* dlc */
        },
        { /* rxLPduConfig[37] */
            UINT16_C( 31 ), /* targetPduId */
            UINT8_C( 64 ), /* limitedPduLength */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 64 ) /* dlc */
        },
        { /* rxLPduConfig[38] */
            UINT16_C( 32 ), /* targetPduId */
            UINT8_C( 64 ), /* limitedPduLength */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 64 ) /* dlc */
        },
        { /* rxLPduConfig[39] */
            UINT16_C( 33 ), /* targetPduId */
            UINT8_C( 64 ), /* limitedPduLength */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 64 ) /* dlc */
        },
        { /* rxLPduConfig[40] */
            UINT16_C( 34 ), /* targetPduId */
            UINT8_C( 64 ), /* limitedPduLength */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 64 ) /* dlc */
        },
        { /* rxLPduConfig[41] */
            UINT16_C( 35 ), /* targetPduId */
            UINT8_C( 64 ), /* limitedPduLength */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 64 ) /* dlc */
        },
        { /* rxLPduConfig[42] */
            UINT16_C( 36 ), /* targetPduId */
            UINT8_C( 64 ), /* limitedPduLength */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 64 ) /* dlc */
        },
        { /* rxLPduConfig[43] */
            UINT16_C( 37 ), /* targetPduId */
            UINT8_C( 64 ), /* limitedPduLength */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 64 ) /* dlc */
        },
        { /* rxLPduConfig[44] */
            UINT16_C( 38 ), /* targetPduId */
            UINT8_C( 64 ), /* limitedPduLength */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 64 ) /* dlc */
        },
        { /* rxLPduConfig[45] */
            UINT16_C( 39 ), /* targetPduId */
            UINT8_C( 64 ), /* limitedPduLength */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 64 ) /* dlc */
        },
        { /* rxLPduConfig[46] */
            UINT16_C( 40 ), /* targetPduId */
            UINT8_C( 64 ), /* limitedPduLength */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 64 ) /* dlc */
        },
        { /* rxLPduConfig[47] */
            UINT16_C( 41 ), /* targetPduId */
            UINT8_C( 8 ), /* limitedPduLength */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 0 ) /* dlc */
        },
        { /* rxLPduConfig[48] */
            UINT16_C( 42 ), /* targetPduId */
            UINT8_C( 8 ), /* limitedPduLength */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 0 ) /* dlc */
        },
        { /* rxLPduConfig[49] */
            UINT16_C( 43 ), /* targetPduId */
            UINT8_C( 8 ), /* limitedPduLength */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 0 ) /* dlc */
        },
        { /* rxLPduConfig[50] */
            UINT16_C( 0 ), /* targetPduId */
            UINT8_C( 8 ), /* limitedPduLength */
            UINT8_C( 5 ), /* userType */
            UINT8_C( 8 ) /* dlc */
        },
        { /* rxLPduConfig[51] */
            UINT16_C( 44 ), /* targetPduId */
            UINT8_C( 64 ), /* limitedPduLength */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 64 ) /* dlc */
        },
        { /* rxLPduConfig[52] */
            UINT16_C( 45 ), /* targetPduId */
            UINT8_C( 64 ), /* limitedPduLength */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 64 ) /* dlc */
        },
        { /* rxLPduConfig[53] */
            UINT16_C( 46 ), /* targetPduId */
            UINT8_C( 64 ), /* limitedPduLength */
            UINT8_C( 0 ), /* userType */
            UINT8_C( 64 ) /* dlc */
        }
    },
    { /* driverHthConfig */
        { /* driverHthConfig[0] */
            UINT16_C( 0 ), /* firstIndex */
            UINT8_C( 0 ) /* intCtrlIdx */
        },
        { /* driverHthConfig[1] */
            UINT16_C( 14 ), /* firstIndex */
            UINT8_C( 1 ) /* intCtrlIdx */
        }
    },
    { /* driverHrhConfig */
        { /* driverHrhConfig[0] */
            UINT16_C( 0 ), /* firstIndex */
            UINT16_C( 0 ), /* lastIndex */
            UINT8_C( 255 ), /* swFiltering */
            UINT8_C( 0 ) /* intCtrlIdx */
        },
        { /* driverHrhConfig[1] */
            UINT16_C( 1 ), /* firstIndex */
            UINT16_C( 1 ), /* lastIndex */
            UINT8_C( 255 ), /* swFiltering */
            UINT8_C( 0 ) /* intCtrlIdx */
        },
        { /* driverHrhConfig[2] */
            UINT16_C( 2 ), /* firstIndex */
            UINT16_C( 2 ), /* lastIndex */
            UINT8_C( 255 ), /* swFiltering */
            UINT8_C( 0 ) /* intCtrlIdx */
        },
        { /* driverHrhConfig[3] */
            UINT16_C( 3 ), /* firstIndex */
            UINT16_C( 3 ), /* lastIndex */
            UINT8_C( 255 ), /* swFiltering */
            UINT8_C( 0 ) /* intCtrlIdx */
        },
        { /* driverHrhConfig[4] */
            UINT16_C( 4 ), /* firstIndex */
            UINT16_C( 4 ), /* lastIndex */
            UINT8_C( 255 ), /* swFiltering */
            UINT8_C( 0 ) /* intCtrlIdx */
        },
        { /* driverHrhConfig[5] */
            UINT16_C( 5 ), /* firstIndex */
            UINT16_C( 5 ), /* lastIndex */
            UINT8_C( 255 ), /* swFiltering */
            UINT8_C( 0 ) /* intCtrlIdx */
        },
        { /* driverHrhConfig[6] */
            UINT16_C( 6 ), /* firstIndex */
            UINT16_C( 6 ), /* lastIndex */
            UINT8_C( 255 ), /* swFiltering */
            UINT8_C( 0 ) /* intCtrlIdx */
        },
        { /* driverHrhConfig[7] */
            UINT16_C( 7 ), /* firstIndex */
            UINT16_C( 7 ), /* lastIndex */
            UINT8_C( 255 ), /* swFiltering */
            UINT8_C( 0 ) /* intCtrlIdx */
        },
        { /* driverHrhConfig[8] */
            UINT16_C( 8 ), /* firstIndex */
            UINT16_C( 8 ), /* lastIndex */
            UINT8_C( 255 ), /* swFiltering */
            UINT8_C( 0 ) /* intCtrlIdx */
        },
        { /* driverHrhConfig[9] */
            UINT16_C( 9 ), /* firstIndex */
            UINT16_C( 9 ), /* lastIndex */
            UINT8_C( 255 ), /* swFiltering */
            UINT8_C( 0 ) /* intCtrlIdx */
        },
        { /* driverHrhConfig[10] */
            UINT16_C( 10 ), /* firstIndex */
            UINT16_C( 10 ), /* lastIndex */
            UINT8_C( 255 ), /* swFiltering */
            UINT8_C( 0 ) /* intCtrlIdx */
        },
        { /* driverHrhConfig[11] */
            UINT16_C( 11 ), /* firstIndex */
            UINT16_C( 11 ), /* lastIndex */
            UINT8_C( 255 ), /* swFiltering */
            UINT8_C( 0 ) /* intCtrlIdx */
        },
        { /* driverHrhConfig[12] */
            UINT16_C( 12 ), /* firstIndex */
            UINT16_C( 12 ), /* lastIndex */
            UINT8_C( 255 ), /* swFiltering */
            UINT8_C( 0 ) /* intCtrlIdx */
        },
        { /* driverHrhConfig[13] */
            UINT16_C( 13 ), /* firstIndex */
            UINT16_C( 13 ), /* lastIndex */
            UINT8_C( 255 ), /* swFiltering */
            UINT8_C( 0 ) /* intCtrlIdx */
        },
        { /* driverHrhConfig[14] */
            UINT16_C( 14 ), /* firstIndex */
            UINT16_C( 14 ), /* lastIndex */
            UINT8_C( 255 ), /* swFiltering */
            UINT8_C( 0 ) /* intCtrlIdx */
        },
        { /* driverHrhConfig[15] */
            UINT16_C( 15 ), /* firstIndex */
            UINT16_C( 15 ), /* lastIndex */
            UINT8_C( 255 ), /* swFiltering */
            UINT8_C( 0 ) /* intCtrlIdx */
        },
        { /* driverHrhConfig[16] */
            UINT16_C( 16 ), /* firstIndex */
            UINT16_C( 16 ), /* lastIndex */
            UINT8_C( 255 ), /* swFiltering */
            UINT8_C( 0 ) /* intCtrlIdx */
        },
        { /* driverHrhConfig[17] */
            UINT16_C( 17 ), /* firstIndex */
            UINT16_C( 17 ), /* lastIndex */
            UINT8_C( 255 ), /* swFiltering */
            UINT8_C( 0 ) /* intCtrlIdx */
        },
        { /* driverHrhConfig[18] */
            UINT16_C( 18 ), /* firstIndex */
            UINT16_C( 18 ), /* lastIndex */
            UINT8_C( 255 ), /* swFiltering */
            UINT8_C( 0 ) /* intCtrlIdx */
        },
        { /* driverHrhConfig[19] */
            UINT16_C( 19 ), /* firstIndex */
            UINT16_C( 19 ), /* lastIndex */
            UINT8_C( 255 ), /* swFiltering */
            UINT8_C( 0 ) /* intCtrlIdx */
        },
        { /* driverHrhConfig[20] */
            UINT16_C( 20 ), /* firstIndex */
            UINT16_C( 20 ), /* lastIndex */
            UINT8_C( 255 ), /* swFiltering */
            UINT8_C( 0 ) /* intCtrlIdx */
        },
        { /* driverHrhConfig[21] */
            UINT16_C( 21 ), /* firstIndex */
            UINT16_C( 21 ), /* lastIndex */
            UINT8_C( 255 ), /* swFiltering */
            UINT8_C( 0 ) /* intCtrlIdx */
        },
        { /* driverHrhConfig[22] */
            UINT16_C( 22 ), /* firstIndex */
            UINT16_C( 23 ), /* lastIndex */
            UINT8_C( 0 ), /* swFiltering */
            UINT8_C( 0 ) /* intCtrlIdx */
        },
        { /* driverHrhConfig[23] */
            UINT16_C( 24 ), /* firstIndex */
            UINT16_C( 24 ), /* lastIndex */
            UINT8_C( 255 ), /* swFiltering */
            UINT8_C( 0 ) /* intCtrlIdx */
        },
        { /* driverHrhConfig[24] */
            UINT16_C( 25 ), /* firstIndex */
            UINT16_C( 25 ), /* lastIndex */
            UINT8_C( 255 ), /* swFiltering */
            UINT8_C( 0 ) /* intCtrlIdx */
        },
        { /* driverHrhConfig[25] */
            UINT16_C( 26 ), /* firstIndex */
            UINT16_C( 26 ), /* lastIndex */
            UINT8_C( 255 ), /* swFiltering */
            UINT8_C( 0 ) /* intCtrlIdx */
        },
        { /* driverHrhConfig[26] */
            UINT16_C( 27 ), /* firstIndex */
            UINT16_C( 28 ), /* lastIndex */
            UINT8_C( 255 ), /* swFiltering */
            UINT8_C( 0 ) /* intCtrlIdx */
        },
        { /* driverHrhConfig[27] */
            UINT16_C( 29 ), /* firstIndex */
            UINT16_C( 30 ), /* lastIndex */
            UINT8_C( 0 ), /* swFiltering */
            UINT8_C( 1 ) /* intCtrlIdx */
        },
        { /* driverHrhConfig[28] */
            UINT16_C( 31 ), /* firstIndex */
            UINT16_C( 31 ), /* lastIndex */
            UINT8_C( 255 ), /* swFiltering */
            UINT8_C( 1 ) /* intCtrlIdx */
        },
        { /* driverHrhConfig[29] */
            UINT16_C( 32 ), /* firstIndex */
            UINT16_C( 32 ), /* lastIndex */
            UINT8_C( 255 ), /* swFiltering */
            UINT8_C( 1 ) /* intCtrlIdx */
        },
        { /* driverHrhConfig[30] */
            UINT16_C( 33 ), /* firstIndex */
            UINT16_C( 33 ), /* lastIndex */
            UINT8_C( 255 ), /* swFiltering */
            UINT8_C( 1 ) /* intCtrlIdx */
        },
        { /* driverHrhConfig[31] */
            UINT16_C( 34 ), /* firstIndex */
            UINT16_C( 34 ), /* lastIndex */
            UINT8_C( 255 ), /* swFiltering */
            UINT8_C( 1 ) /* intCtrlIdx */
        },
        { /* driverHrhConfig[32] */
            UINT16_C( 35 ), /* firstIndex */
            UINT16_C( 35 ), /* lastIndex */
            UINT8_C( 255 ), /* swFiltering */
            UINT8_C( 1 ) /* intCtrlIdx */
        },
        { /* driverHrhConfig[33] */
            UINT16_C( 36 ), /* firstIndex */
            UINT16_C( 36 ), /* lastIndex */
            UINT8_C( 255 ), /* swFiltering */
            UINT8_C( 1 ) /* intCtrlIdx */
        },
        { /* driverHrhConfig[34] */
            UINT16_C( 37 ), /* firstIndex */
            UINT16_C( 37 ), /* lastIndex */
            UINT8_C( 255 ), /* swFiltering */
            UINT8_C( 1 ) /* intCtrlIdx */
        },
        { /* driverHrhConfig[35] */
            UINT16_C( 38 ), /* firstIndex */
            UINT16_C( 38 ), /* lastIndex */
            UINT8_C( 255 ), /* swFiltering */
            UINT8_C( 1 ) /* intCtrlIdx */
        },
        { /* driverHrhConfig[36] */
            UINT16_C( 39 ), /* firstIndex */
            UINT16_C( 39 ), /* lastIndex */
            UINT8_C( 255 ), /* swFiltering */
            UINT8_C( 1 ) /* intCtrlIdx */
        },
        { /* driverHrhConfig[37] */
            UINT16_C( 40 ), /* firstIndex */
            UINT16_C( 40 ), /* lastIndex */
            UINT8_C( 255 ), /* swFiltering */
            UINT8_C( 1 ) /* intCtrlIdx */
        },
        { /* driverHrhConfig[38] */
            UINT16_C( 41 ), /* firstIndex */
            UINT16_C( 41 ), /* lastIndex */
            UINT8_C( 255 ), /* swFiltering */
            UINT8_C( 1 ) /* intCtrlIdx */
        },
        { /* driverHrhConfig[39] */
            UINT16_C( 42 ), /* firstIndex */
            UINT16_C( 42 ), /* lastIndex */
            UINT8_C( 255 ), /* swFiltering */
            UINT8_C( 1 ) /* intCtrlIdx */
        },
        { /* driverHrhConfig[40] */
            UINT16_C( 43 ), /* firstIndex */
            UINT16_C( 43 ), /* lastIndex */
            UINT8_C( 255 ), /* swFiltering */
            UINT8_C( 1 ) /* intCtrlIdx */
        },
        { /* driverHrhConfig[41] */
            UINT16_C( 44 ), /* firstIndex */
            UINT16_C( 44 ), /* lastIndex */
            UINT8_C( 255 ), /* swFiltering */
            UINT8_C( 1 ) /* intCtrlIdx */
        },
        { /* driverHrhConfig[42] */
            UINT16_C( 45 ), /* firstIndex */
            UINT16_C( 45 ), /* lastIndex */
            UINT8_C( 255 ), /* swFiltering */
            UINT8_C( 1 ) /* intCtrlIdx */
        },
        { /* driverHrhConfig[43] */
            UINT16_C( 46 ), /* firstIndex */
            UINT16_C( 46 ), /* lastIndex */
            UINT8_C( 255 ), /* swFiltering */
            UINT8_C( 1 ) /* intCtrlIdx */
        },
        { /* driverHrhConfig[44] */
            UINT16_C( 47 ), /* firstIndex */
            UINT16_C( 47 ), /* lastIndex */
            UINT8_C( 255 ), /* swFiltering */
            UINT8_C( 1 ) /* intCtrlIdx */
        },
        { /* driverHrhConfig[45] */
            UINT16_C( 48 ), /* firstIndex */
            UINT16_C( 48 ), /* lastIndex */
            UINT8_C( 255 ), /* swFiltering */
            UINT8_C( 1 ) /* intCtrlIdx */
        },
        { /* driverHrhConfig[46] */
            UINT16_C( 49 ), /* firstIndex */
            UINT16_C( 49 ), /* lastIndex */
            UINT8_C( 255 ), /* swFiltering */
            UINT8_C( 1 ) /* intCtrlIdx */
        },
        { /* driverHrhConfig[47] */
            UINT16_C( 50 ), /* firstIndex */
            UINT16_C( 50 ), /* lastIndex */
            UINT8_C( 255 ), /* swFiltering */
            UINT8_C( 1 ) /* intCtrlIdx */
        },
        { /* driverHrhConfig[48] */
            UINT16_C( 51 ), /* firstIndex */
            UINT16_C( 51 ), /* lastIndex */
            UINT8_C( 255 ), /* swFiltering */
            UINT8_C( 1 ) /* intCtrlIdx */
        },
        { /* driverHrhConfig[49] */
            UINT16_C( 52 ), /* firstIndex */
            UINT16_C( 52 ), /* lastIndex */
            UINT8_C( 255 ), /* swFiltering */
            UINT8_C( 1 ) /* intCtrlIdx */
        },
        { /* driverHrhConfig[50] */
            UINT16_C( 53 ), /* firstIndex */
            UINT16_C( 53 ), /* lastIndex */
            UINT8_C( 255 ), /* swFiltering */
            UINT8_C( 1 ) /* intCtrlIdx */
        },
        { /* driverHrhConfig[51] */
            UINT16_C( 54 ), /* firstIndex */
            UINT16_C( 54 ), /* lastIndex */
            UINT8_C( 255 ), /* swFiltering */
            UINT8_C( 1 ) /* intCtrlIdx */
        }
    },
    { /* hohIdToCanIfIdx */
        UINT16_C( 0 ), /* hohIdToCanIfIdx[0] */
        UINT16_C( 1 ), /* hohIdToCanIfIdx[1] */
        UINT16_C( 2 ), /* hohIdToCanIfIdx[2] */
        UINT16_C( 3 ), /* hohIdToCanIfIdx[3] */
        UINT16_C( 4 ), /* hohIdToCanIfIdx[4] */
        UINT16_C( 5 ), /* hohIdToCanIfIdx[5] */
        UINT16_C( 6 ), /* hohIdToCanIfIdx[6] */
        UINT16_C( 7 ), /* hohIdToCanIfIdx[7] */
        UINT16_C( 8 ), /* hohIdToCanIfIdx[8] */
        UINT16_C( 9 ), /* hohIdToCanIfIdx[9] */
        UINT16_C( 10 ), /* hohIdToCanIfIdx[10] */
        UINT16_C( 11 ), /* hohIdToCanIfIdx[11] */
        UINT16_C( 12 ), /* hohIdToCanIfIdx[12] */
        UINT16_C( 13 ), /* hohIdToCanIfIdx[13] */
        UINT16_C( 14 ), /* hohIdToCanIfIdx[14] */
        UINT16_C( 15 ), /* hohIdToCanIfIdx[15] */
        UINT16_C( 16 ), /* hohIdToCanIfIdx[16] */
        UINT16_C( 17 ), /* hohIdToCanIfIdx[17] */
        UINT16_C( 18 ), /* hohIdToCanIfIdx[18] */
        UINT16_C( 19 ), /* hohIdToCanIfIdx[19] */
        UINT16_C( 20 ), /* hohIdToCanIfIdx[20] */
        UINT16_C( 21 ), /* hohIdToCanIfIdx[21] */
        UINT16_C( 22 ), /* hohIdToCanIfIdx[22] */
        UINT16_C( 23 ), /* hohIdToCanIfIdx[23] */
        UINT16_C( 24 ), /* hohIdToCanIfIdx[24] */
        UINT16_C( 25 ), /* hohIdToCanIfIdx[25] */
        UINT16_C( 26 ), /* hohIdToCanIfIdx[26] */
        UINT16_C( 27 ), /* hohIdToCanIfIdx[27] */
        UINT16_C( 28 ), /* hohIdToCanIfIdx[28] */
        UINT16_C( 29 ), /* hohIdToCanIfIdx[29] */
        UINT16_C( 30 ), /* hohIdToCanIfIdx[30] */
        UINT16_C( 31 ), /* hohIdToCanIfIdx[31] */
        UINT16_C( 32 ), /* hohIdToCanIfIdx[32] */
        UINT16_C( 33 ), /* hohIdToCanIfIdx[33] */
        UINT16_C( 34 ), /* hohIdToCanIfIdx[34] */
        UINT16_C( 35 ), /* hohIdToCanIfIdx[35] */
        UINT16_C( 36 ), /* hohIdToCanIfIdx[36] */
        UINT16_C( 37 ), /* hohIdToCanIfIdx[37] */
        UINT16_C( 38 ), /* hohIdToCanIfIdx[38] */
        UINT16_C( 39 ), /* hohIdToCanIfIdx[39] */
        UINT16_C( 40 ), /* hohIdToCanIfIdx[40] */
        UINT16_C( 41 ), /* hohIdToCanIfIdx[41] */
        UINT16_C( 42 ), /* hohIdToCanIfIdx[42] */
        UINT16_C( 43 ), /* hohIdToCanIfIdx[43] */
        UINT16_C( 44 ), /* hohIdToCanIfIdx[44] */
        UINT16_C( 45 ), /* hohIdToCanIfIdx[45] */
        UINT16_C( 46 ), /* hohIdToCanIfIdx[46] */
        UINT16_C( 47 ), /* hohIdToCanIfIdx[47] */
        UINT16_C( 48 ), /* hohIdToCanIfIdx[48] */
        UINT16_C( 49 ), /* hohIdToCanIfIdx[49] */
        UINT16_C( 50 ), /* hohIdToCanIfIdx[50] */
        UINT16_C( 51 ), /* hohIdToCanIfIdx[51] */
        UINT16_C( 32768 ), /* hohIdToCanIfIdx[52] */
        UINT16_C( 32769 ) /* hohIdToCanIfIdx[53] */
    },
    { /* canControllerConfig */
        { /* canControllerConfig[0] */
            UINT8_C( 0 ), /* controllerId */
            UINT8_C( 0 ) /* driverIndex */
        },
        { /* canControllerConfig[1] */
            UINT8_C( 1 ), /* controllerId */
            UINT8_C( 0 ) /* driverIndex */
        }
    },
    { /* canDriverConfig */
        { /* canDriverConfig[0] */
            TS_MAKEREF2CFG( canControllerConfig[0] ), /* ctrlConfigPtr */
            TS_MAKEREF2CFG( hohIdToCanIfIdx[0] ), /* hohIdToCanIfIdxPtr */
            TS_MAKEREF2CFG( driverHthConfig[0] ), /* hthConfigPtr */
            TS_MAKEREF2CFG( driverHrhConfig[0] ), /* hrhConfigPtr */
            UINT8_C( 54 ), /* upperHohIdLimit */
            UINT8_C( 2 ), /* nrOfHths */
            UINT8_C( 2 ) /* nrOfControllers */
        }
    },
    { /* sortedRxLPduConfig */
        { /* sortedRxLPduConfig[0] */
            UINT32_C( 4294967295 ), /* upperRangeCanId */
            UINT32_C( 1073741904 ), /* canId */
            UINT16_C( 0 ) /* rxLPduIndex */
        },
        { /* sortedRxLPduConfig[1] */
            UINT32_C( 4294967295 ), /* upperRangeCanId */
            UINT32_C( 1073742177 ), /* canId */
            UINT16_C( 1 ) /* rxLPduIndex */
        },
        { /* sortedRxLPduConfig[2] */
            UINT32_C( 4294967295 ), /* upperRangeCanId */
            UINT32_C( 1073742192 ), /* canId */
            UINT16_C( 2 ) /* rxLPduIndex */
        },
        { /* sortedRxLPduConfig[3] */
            UINT32_C( 4294967295 ), /* upperRangeCanId */
            UINT32_C( 1073742202 ), /* canId */
            UINT16_C( 3 ) /* rxLPduIndex */
        },
        { /* sortedRxLPduConfig[4] */
            UINT32_C( 4294967295 ), /* upperRangeCanId */
            UINT32_C( 1073742206 ), /* canId */
            UINT16_C( 4 ) /* rxLPduIndex */
        },
        { /* sortedRxLPduConfig[5] */
            UINT32_C( 4294967295 ), /* upperRangeCanId */
            UINT32_C( 1073742208 ), /* canId */
            UINT16_C( 5 ) /* rxLPduIndex */
        },
        { /* sortedRxLPduConfig[6] */
            UINT32_C( 4294967295 ), /* upperRangeCanId */
            UINT32_C( 1073742274 ), /* canId */
            UINT16_C( 6 ) /* rxLPduIndex */
        },
        { /* sortedRxLPduConfig[7] */
            UINT32_C( 4294967295 ), /* upperRangeCanId */
            UINT32_C( 1073742347 ), /* canId */
            UINT16_C( 7 ) /* rxLPduIndex */
        },
        { /* sortedRxLPduConfig[8] */
            UINT32_C( 4294967295 ), /* upperRangeCanId */
            UINT32_C( 1073742415 ), /* canId */
            UINT16_C( 8 ) /* rxLPduIndex */
        },
        { /* sortedRxLPduConfig[9] */
            UINT32_C( 4294967295 ), /* upperRangeCanId */
            UINT32_C( 1073742456 ), /* canId */
            UINT16_C( 9 ) /* rxLPduIndex */
        },
        { /* sortedRxLPduConfig[10] */
            UINT32_C( 4294967295 ), /* upperRangeCanId */
            UINT32_C( 1073742472 ), /* canId */
            UINT16_C( 10 ) /* rxLPduIndex */
        },
        { /* sortedRxLPduConfig[11] */
            UINT32_C( 4294967295 ), /* upperRangeCanId */
            UINT32_C( 1073742475 ), /* canId */
            UINT16_C( 11 ) /* rxLPduIndex */
        },
        { /* sortedRxLPduConfig[12] */
            UINT32_C( 4294967295 ), /* upperRangeCanId */
            UINT32_C( 1073742504 ), /* canId */
            UINT16_C( 12 ) /* rxLPduIndex */
        },
        { /* sortedRxLPduConfig[13] */
            UINT32_C( 4294967295 ), /* upperRangeCanId */
            UINT32_C( 1073742530 ), /* canId */
            UINT16_C( 13 ) /* rxLPduIndex */
        },
        { /* sortedRxLPduConfig[14] */
            UINT32_C( 4294967295 ), /* upperRangeCanId */
            UINT32_C( 1073742546 ), /* canId */
            UINT16_C( 14 ) /* rxLPduIndex */
        },
        { /* sortedRxLPduConfig[15] */
            UINT32_C( 4294967295 ), /* upperRangeCanId */
            UINT32_C( 1073742558 ), /* canId */
            UINT16_C( 15 ) /* rxLPduIndex */
        },
        { /* sortedRxLPduConfig[16] */
            UINT32_C( 4294967295 ), /* upperRangeCanId */
            UINT32_C( 1073742583 ), /* canId */
            UINT16_C( 16 ) /* rxLPduIndex */
        },
        { /* sortedRxLPduConfig[17] */
            UINT32_C( 4294967295 ), /* upperRangeCanId */
            UINT32_C( 1073742730 ), /* canId */
            UINT16_C( 17 ) /* rxLPduIndex */
        },
        { /* sortedRxLPduConfig[18] */
            UINT32_C( 4294967295 ), /* upperRangeCanId */
            UINT32_C( 1073742767 ), /* canId */
            UINT16_C( 18 ) /* rxLPduIndex */
        },
        { /* sortedRxLPduConfig[19] */
            UINT32_C( 4294967295 ), /* upperRangeCanId */
            UINT32_C( 1073742781 ), /* canId */
            UINT16_C( 20 ) /* rxLPduIndex */
        },
        { /* sortedRxLPduConfig[20] */
            UINT32_C( 4294967295 ), /* upperRangeCanId */
            UINT32_C( 1073742786 ), /* canId */
            UINT16_C( 21 ) /* rxLPduIndex */
        },
        { /* sortedRxLPduConfig[21] */
            UINT32_C( 4294967295 ), /* upperRangeCanId */
            UINT32_C( 1073743111 ), /* canId */
            UINT16_C( 22 ) /* rxLPduIndex */
        },
        { /* sortedRxLPduConfig[22] */
            UINT32_C( 4294967295 ), /* upperRangeCanId */
            UINT32_C( 2015 ), /* canId */
            UINT16_C( 23 ) /* rxLPduIndex */
        },
        { /* sortedRxLPduConfig[23] */
            UINT32_C( 4294967295 ), /* upperRangeCanId */
            UINT32_C( 1073743839 ), /* canId */
            UINT16_C( 25 ) /* rxLPduIndex */
        },
        { /* sortedRxLPduConfig[24] */
            UINT32_C( 4294967295 ), /* upperRangeCanId */
            UINT32_C( 1891 ), /* canId */
            UINT16_C( 24 ) /* rxLPduIndex */
        },
        { /* sortedRxLPduConfig[25] */
            UINT32_C( 4294967295 ), /* upperRangeCanId */
            UINT32_C( 1073743698 ), /* canId */
            UINT16_C( 26 ) /* rxLPduIndex */
        },
        { /* sortedRxLPduConfig[26] */
            UINT32_C( 4294967295 ), /* upperRangeCanId */
            UINT32_C( 1536 ), /* canId */
            UINT16_C( 30 ) /* rxLPduIndex */
        },
        { /* sortedRxLPduConfig[27] */
            UINT32_C( 1087 ), /* upperRangeCanId */
            UINT32_C( 1072 ), /* canId */
            UINT16_C( 50 ) /* rxLPduIndex */
        },
        { /* sortedRxLPduConfig[28] */
            UINT32_C( 1073742911 ), /* upperRangeCanId */
            UINT32_C( 1073742896 ), /* canId */
            UINT16_C( 50 ) /* rxLPduIndex */
        },
        { /* sortedRxLPduConfig[29] */
            UINT32_C( 4294967295 ), /* upperRangeCanId */
            UINT32_C( 512 ), /* canId */
            UINT16_C( 48 ) /* rxLPduIndex */
        },
        { /* sortedRxLPduConfig[30] */
            UINT32_C( 4294967295 ), /* upperRangeCanId */
            UINT32_C( 1073742336 ), /* canId */
            UINT16_C( 19 ) /* rxLPduIndex */
        },
        { /* sortedRxLPduConfig[31] */
            UINT32_C( 4294967295 ), /* upperRangeCanId */
            UINT32_C( 1073742097 ), /* canId */
            UINT16_C( 27 ) /* rxLPduIndex */
        },
        { /* sortedRxLPduConfig[32] */
            UINT32_C( 4294967295 ), /* upperRangeCanId */
            UINT32_C( 1073742098 ), /* canId */
            UINT16_C( 28 ) /* rxLPduIndex */
        },
        { /* sortedRxLPduConfig[33] */
            UINT32_C( 4294967295 ), /* upperRangeCanId */
            UINT32_C( 1073742099 ), /* canId */
            UINT16_C( 29 ) /* rxLPduIndex */
        },
        { /* sortedRxLPduConfig[34] */
            UINT32_C( 4294967295 ), /* upperRangeCanId */
            UINT32_C( 1073742100 ), /* canId */
            UINT16_C( 31 ) /* rxLPduIndex */
        },
        { /* sortedRxLPduConfig[35] */
            UINT32_C( 4294967295 ), /* upperRangeCanId */
            UINT32_C( 1073742101 ), /* canId */
            UINT16_C( 32 ) /* rxLPduIndex */
        },
        { /* sortedRxLPduConfig[36] */
            UINT32_C( 4294967295 ), /* upperRangeCanId */
            UINT32_C( 1073742102 ), /* canId */
            UINT16_C( 33 ) /* rxLPduIndex */
        },
        { /* sortedRxLPduConfig[37] */
            UINT32_C( 4294967295 ), /* upperRangeCanId */
            UINT32_C( 1073742103 ), /* canId */
            UINT16_C( 34 ) /* rxLPduIndex */
        },
        { /* sortedRxLPduConfig[38] */
            UINT32_C( 4294967295 ), /* upperRangeCanId */
            UINT32_C( 1073742104 ), /* canId */
            UINT16_C( 35 ) /* rxLPduIndex */
        },
        { /* sortedRxLPduConfig[39] */
            UINT32_C( 4294967295 ), /* upperRangeCanId */
            UINT32_C( 1073742105 ), /* canId */
            UINT16_C( 36 ) /* rxLPduIndex */
        },
        { /* sortedRxLPduConfig[40] */
            UINT32_C( 4294967295 ), /* upperRangeCanId */
            UINT32_C( 1073742106 ), /* canId */
            UINT16_C( 37 ) /* rxLPduIndex */
        },
        { /* sortedRxLPduConfig[41] */
            UINT32_C( 4294967295 ), /* upperRangeCanId */
            UINT32_C( 1073742107 ), /* canId */
            UINT16_C( 38 ) /* rxLPduIndex */
        },
        { /* sortedRxLPduConfig[42] */
            UINT32_C( 4294967295 ), /* upperRangeCanId */
            UINT32_C( 1073742108 ), /* canId */
            UINT16_C( 39 ) /* rxLPduIndex */
        },
        { /* sortedRxLPduConfig[43] */
            UINT32_C( 4294967295 ), /* upperRangeCanId */
            UINT32_C( 1073742109 ), /* canId */
            UINT16_C( 40 ) /* rxLPduIndex */
        },
        { /* sortedRxLPduConfig[44] */
            UINT32_C( 4294967295 ), /* upperRangeCanId */
            UINT32_C( 1073742110 ), /* canId */
            UINT16_C( 41 ) /* rxLPduIndex */
        },
        { /* sortedRxLPduConfig[45] */
            UINT32_C( 4294967295 ), /* upperRangeCanId */
            UINT32_C( 1073742111 ), /* canId */
            UINT16_C( 42 ) /* rxLPduIndex */
        },
        { /* sortedRxLPduConfig[46] */
            UINT32_C( 4294967295 ), /* upperRangeCanId */
            UINT32_C( 1073742112 ), /* canId */
            UINT16_C( 43 ) /* rxLPduIndex */
        },
        { /* sortedRxLPduConfig[47] */
            UINT32_C( 4294967295 ), /* upperRangeCanId */
            UINT32_C( 1073742134 ), /* canId */
            UINT16_C( 44 ) /* rxLPduIndex */
        },
        { /* sortedRxLPduConfig[48] */
            UINT32_C( 4294967295 ), /* upperRangeCanId */
            UINT32_C( 1073742136 ), /* canId */
            UINT16_C( 45 ) /* rxLPduIndex */
        },
        { /* sortedRxLPduConfig[49] */
            UINT32_C( 4294967295 ), /* upperRangeCanId */
            UINT32_C( 1073742235 ), /* canId */
            UINT16_C( 46 ) /* rxLPduIndex */
        },
        { /* sortedRxLPduConfig[50] */
            UINT32_C( 4294967295 ), /* upperRangeCanId */
            UINT32_C( 1073742321 ), /* canId */
            UINT16_C( 47 ) /* rxLPduIndex */
        },
        { /* sortedRxLPduConfig[51] */
            UINT32_C( 4294967295 ), /* upperRangeCanId */
            UINT32_C( 1073742337 ), /* canId */
            UINT16_C( 49 ) /* rxLPduIndex */
        },
        { /* sortedRxLPduConfig[52] */
            UINT32_C( 4294967295 ), /* upperRangeCanId */
            UINT32_C( 1073742660 ), /* canId */
            UINT16_C( 51 ) /* rxLPduIndex */
        },
        { /* sortedRxLPduConfig[53] */
            UINT32_C( 4294967295 ), /* upperRangeCanId */
            UINT32_C( 1073742661 ), /* canId */
            UINT16_C( 52 ) /* rxLPduIndex */
        },
        { /* sortedRxLPduConfig[54] */
            UINT32_C( 4294967295 ), /* upperRangeCanId */
            UINT32_C( 1073742662 ), /* canId */
            UINT16_C( 53 ) /* rxLPduIndex */
        }
    },
    { /* canTrcvChnlConfig */
        { /* canTrcvChnlConfig[0] */
            UINT8_C( 0 ), /* trcvChnlId */
            UINT8_C( 0 ) /* trcvDrvIdx */
        }
    }
};

/* Deviation MISRAC2012-1, MISRAC2012-2, MISRAC2012-3 <STOP> */

#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include <CanIf_MemMap.h>

/*==================[internal constants]=====================================*/


/*==================[external data]==========================================*/


/*==================[internal data]==========================================*/


/*==================[external function definitions]==========================*/


/*==================[internal function definitions]==========================*/


/*==================[end of file]============================================*/

