


/**
 * \file
 *
 * \brief AUTOSAR PduR
 *
 * This file contains the implementation of the AUTOSAR
 * module PduR.
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

#include <PduR_PBcfg.h>
#include <TSAutosar.h>
#include <Compiler.h>
#define TS_RELOCATABLE_CFG_ENABLE STD_OFF
#define TS_PB_CFG_NAME PduR_ConfigLayout
#define TS_PB_CFG_LAYOUT_TYPE PduR_ConstConfigLayoutType
#include <TSPBConfig_Init.h>

/*==================[macros]=================================================*/


/*==================[type definitions]=======================================*/


/*==================[external function declarations]=========================*/


/*==================[internal function declarations]=========================*/


/*==================[external constants]=====================================*/

#define PDUR_START_SEC_CONFIG_DATA_UNSPECIFIED
#include <PduR_MemMap.h>

/* Deviation MISRAC2012-1, MISRAC2012-2, MISRAC2012-3 <START> */
PduR_ConstConfigLayoutType PduR_ConfigLayout = {
    { /* PduR_RootConfig */
        UINT32_C( 2281703698 ), /* PduR_PlatformSignature */
        UINT32_C( 3287861272 ), /* PduR_PublicInfoSignature */
        UINT32_C( 2503975737 ), /* PduR_CfgSignature */
        UINT32_C( 3958107115 ), /* PduR_LcfgSignature */
        TS_MAKENULLREF2CFG, /* PduR_BufDefaultRef */
        TS_MAKENULLREF2CFG, /* PduR_BufSbConfigRef */
        TS_MAKENULLREF2CFG, /* PduR_BufDfConfigRef */
        TS_MAKENULLREF2CFG, /* PduR_BufTfConfigRef */
        TS_MAKENULLREF2CFG, /* PduR_BufSbDynPyldConfigRef */
        TS_MAKENULLREF2CFG, /* PduR_BufDfDynPyldConfigRef */
        TS_MAKENULLREF2CFG, /* PduR_BufTfDynPyldConfigRef */
        TS_MAKENULLREF2CFG, /* PduR_BufTpConfigRef */
        { /* PduR_MTabLoIfConfig */
            TS_MAKENULLREF2CFG, /* MTabRxRef */
            UINT16_C( 0 ) /* MTabRxCount */
        },
        { /* PduR_MTabUpIfConfig */
            TS_MAKENULLREF2CFG, /* MTabTxRef */
            UINT16_C( 0 ) /* MTabTxCount */
        },
        { /* PduR_MTabUpTpConfig */
            TS_MAKENULLREF2CFG, /* MTabTxRef */
            UINT16_C( 0 ) /* MTabTxCount */
        },
        { /* PduR_GTabIfConfig */
            TS_MAKENULLREF2CFG, /* GTabRxRef */
            UINT16_C( 0 ) /* GTabRxCount */
        },
        { /* PduR_GTabTpConfig */
            TS_MAKENULLREF2CFG, /* GTabRxRef */
            UINT16_C( 0 ) /* GTabRxCount */
        },
        { /* PduR_Nto1TabTpConfig */
            TS_MAKENULLREF2CFG, /* Nto1TabTpRef */
            UINT16_C( 0 ) /* Nto1TabTpCount */
        },
        { /* PduR_RTabLoIfConfig */
            { /* PduR_RTabLoIfConfig[0] -- CanIf */
                TS_MAKEREF2CFG( PduR_RTabLoIfRx[0] ), /* RTabRxRef */
                TS_MAKEREF2CFG( PduR_RTabLoIfTx[0] ), /* RTabTxRef */
                UINT16_C( 47 ), /* RTabRxCount */
                UINT16_C( 47 ) /* RTabTxCount */
            },
            { /* PduR_RTabLoIfConfig[1] -- CanNm */
                TS_MAKENULLREF2CFG, /* RTabRxRef */
                TS_MAKENULLREF2CFG, /* RTabTxRef */
                UINT16_C( 0 ), /* RTabRxCount */
                UINT16_C( 0 ) /* RTabTxCount */
            }
        },
        { /* PduR_RTabUpIfTxConfig */
            { /* PduR_RTabUpIfTxConfig[0] -- Com */
                TS_MAKEREF2CFG( PduR_RTabUpIfTx[0] ), /* RTabTxRef */
                UINT16_C( 47 ) /* RTabTxCount */
            },
            { /* PduR_RTabUpIfTxConfig[1] -- Dcm */
                TS_MAKENULLREF2CFG, /* RTabTxRef */
                UINT16_C( 0 ) /* RTabTxCount */
            }
        },
        { /* PduR_RTabLoTpConfig */
            { /* PduR_RTabLoTpConfig[0] -- CanTp */
                TS_MAKEREF2CFG( PduR_RTabLoTpRx[0] ), /* RTabRxRef */
                TS_MAKEREF2CFG( PduR_RTabLoTpTx[0] ), /* RTabTxRef */
                UINT16_C( 4 ), /* RTabRxCount */
                UINT16_C( 2 ) /* RTabTxCount */
            }
        },
        { /* PduR_RTabUpTpConfig */
            { /* PduR_RTabUpTpConfig[0] -- Dcm */
                TS_MAKEREF2CFG( PduR_RTabUpTpTx[0] ), /* RTabTxRef */
                TS_MAKEREF2CFG( PduR_RTabUpTpRx[0] ), /* RTabRxRef */
                UINT16_C( 2 ), /* RTabTxCount */
                UINT16_C( 4 ) /* RTabRxCount */
            }
        },
        UINT16_C( 0 ), /* PduR_ConfigurationId */
        UINT16_C( 0 ), /* PduR_BufSbCount */
        UINT16_C( 0 ), /* PduR_BufDfCount */
        UINT16_C( 0 ), /* PduR_BufTfCount */
        UINT16_C( 0 ), /* PduR_BufSbDynPyldCount */
        UINT16_C( 0 ), /* PduR_BufDfDynPyldCount */
        UINT16_C( 0 ), /* PduR_BufTfDynPyldCount */
        UINT16_C( 0 ), /* PduR_BufTpCount */
        UINT16_C( 0 ), /* PduR_MultiTpTxSessionInfoRef */
        UINT16_C( 0 ), /* PduR_MultiIfTxInfoRef */
        UINT16_C( 0 ), /* PduR_BufSbDynPyldInfoRef */
        UINT16_C( 0 ), /* PduR_BufDfInfoRef */
        UINT16_C( 0 ), /* PduR_BufDfDynPyldInfoRef */
        UINT16_C( 0 ), /* PduR_BufTfInfoRef */
        UINT16_C( 0 ), /* PduR_BufTfDynPyldInfoRef */
        UINT16_C( 0 ), /* PduR_GateTpSessionInfoRef */
        UINT8_C( 0 ) /* PduR_MultiTpTxRPathsMax */
    },
    { /* PduR_RTabLoIfRx */
        { /* PduR_RTabLoIfRx[0] -- Routing path:'GW_50_80R', calling module:'CanIf-LO-IF', PDU ID:0 */
            UINT16_C( 0 ), /* TargetPduId */
            UINT16_C( 0 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: Com */
        },
        { /* PduR_RTabLoIfRx[1] -- Routing path:'VCU_161_353R', calling module:'CanIf-LO-IF', PDU ID:1 */
            UINT16_C( 1 ), /* TargetPduId */
            UINT16_C( 0 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: Com */
        },
        { /* PduR_RTabLoIfRx[2] -- Routing path:'GW_170_368R', calling module:'CanIf-LO-IF', PDU ID:2 */
            UINT16_C( 2 ), /* TargetPduId */
            UINT16_C( 0 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: Com */
        },
        { /* PduR_RTabLoIfRx[3] -- Routing path:'GW_17A_378R', calling module:'CanIf-LO-IF', PDU ID:3 */
            UINT16_C( 3 ), /* TargetPduId */
            UINT16_C( 0 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: Com */
        },
        { /* PduR_RTabLoIfRx[4] -- Routing path:'GW_17E_382R', calling module:'CanIf-LO-IF', PDU ID:4 */
            UINT16_C( 4 ), /* TargetPduId */
            UINT16_C( 0 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: Com */
        },
        { /* PduR_RTabLoIfRx[5] -- Routing path:'GW_180_384R', calling module:'CanIf-LO-IF', PDU ID:5 */
            UINT16_C( 5 ), /* TargetPduId */
            UINT16_C( 0 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: Com */
        },
        { /* PduR_RTabLoIfRx[6] -- Routing path:'GW_1C2_450R', calling module:'CanIf-LO-IF', PDU ID:6 */
            UINT16_C( 6 ), /* TargetPduId */
            UINT16_C( 0 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: Com */
        },
        { /* PduR_RTabLoIfRx[7] -- Routing path:'GW_20B_523R', calling module:'CanIf-LO-IF', PDU ID:7 */
            UINT16_C( 7 ), /* TargetPduId */
            UINT16_C( 0 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: Com */
        },
        { /* PduR_RTabLoIfRx[8] -- Routing path:'GW_24F_591R', calling module:'CanIf-LO-IF', PDU ID:8 */
            UINT16_C( 8 ), /* TargetPduId */
            UINT16_C( 0 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: Com */
        },
        { /* PduR_RTabLoIfRx[9] -- Routing path:'GW_278_632R', calling module:'CanIf-LO-IF', PDU ID:9 */
            UINT16_C( 9 ), /* TargetPduId */
            UINT16_C( 0 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: Com */
        },
        { /* PduR_RTabLoIfRx[10] -- Routing path:'GW_288_648R', calling module:'CanIf-LO-IF', PDU ID:10 */
            UINT16_C( 10 ), /* TargetPduId */
            UINT16_C( 0 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: Com */
        },
        { /* PduR_RTabLoIfRx[11] -- Routing path:'GW_28B_651R', calling module:'CanIf-LO-IF', PDU ID:11 */
            UINT16_C( 11 ), /* TargetPduId */
            UINT16_C( 0 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: Com */
        },
        { /* PduR_RTabLoIfRx[12] -- Routing path:'GW_2A8_680R', calling module:'CanIf-LO-IF', PDU ID:12 */
            UINT16_C( 12 ), /* TargetPduId */
            UINT16_C( 0 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: Com */
        },
        { /* PduR_RTabLoIfRx[13] -- Routing path:'GW_2C2_706R', calling module:'CanIf-LO-IF', PDU ID:13 */
            UINT16_C( 13 ), /* TargetPduId */
            UINT16_C( 0 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: Com */
        },
        { /* PduR_RTabLoIfRx[14] -- Routing path:'GW_2D2_722R', calling module:'CanIf-LO-IF', PDU ID:14 */
            UINT16_C( 14 ), /* TargetPduId */
            UINT16_C( 0 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: Com */
        },
        { /* PduR_RTabLoIfRx[15] -- Routing path:'GW_2DE_734R', calling module:'CanIf-LO-IF', PDU ID:15 */
            UINT16_C( 15 ), /* TargetPduId */
            UINT16_C( 0 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: Com */
        },
        { /* PduR_RTabLoIfRx[16] -- Routing path:'TBOX_2F7_759R', calling module:'CanIf-LO-IF', PDU ID:16 */
            UINT16_C( 16 ), /* TargetPduId */
            UINT16_C( 0 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: Com */
        },
        { /* PduR_RTabLoIfRx[17] -- Routing path:'VCU_38A_906R', calling module:'CanIf-LO-IF', PDU ID:17 */
            UINT16_C( 17 ), /* TargetPduId */
            UINT16_C( 0 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: Com */
        },
        { /* PduR_RTabLoIfRx[18] -- Routing path:'GW_3AF_943R', calling module:'CanIf-LO-IF', PDU ID:18 */
            UINT16_C( 18 ), /* TargetPduId */
            UINT16_C( 0 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: Com */
        },
        { /* PduR_RTabLoIfRx[19] -- Routing path:'GW_3BD_957R', calling module:'CanIf-LO-IF', PDU ID:19 */
            UINT16_C( 19 ), /* TargetPduId */
            UINT16_C( 0 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: Com */
        },
        { /* PduR_RTabLoIfRx[20] -- Routing path:'GW_3C2_962R', calling module:'CanIf-LO-IF', PDU ID:20 */
            UINT16_C( 20 ), /* TargetPduId */
            UINT16_C( 0 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: Com */
        },
        { /* PduR_RTabLoIfRx[21] -- Routing path:'GW_507_1287R', calling module:'CanIf-LO-IF', PDU ID:21 */
            UINT16_C( 21 ), /* TargetPduId */
            UINT16_C( 0 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: Com */
        },
        { /* PduR_RTabLoIfRx[22] -- Routing path:'FR_111_273R', calling module:'CanIf-LO-IF', PDU ID:22 */
            UINT16_C( 22 ), /* TargetPduId */
            UINT16_C( 0 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: Com */
        },
        { /* PduR_RTabLoIfRx[23] -- Routing path:'FR_112_274R', calling module:'CanIf-LO-IF', PDU ID:23 */
            UINT16_C( 23 ), /* TargetPduId */
            UINT16_C( 0 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: Com */
        },
        { /* PduR_RTabLoIfRx[24] -- Routing path:'FR_113_275R', calling module:'CanIf-LO-IF', PDU ID:24 */
            UINT16_C( 24 ), /* TargetPduId */
            UINT16_C( 0 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: Com */
        },
        { /* PduR_RTabLoIfRx[25] -- Routing path:'FR_114_276R', calling module:'CanIf-LO-IF', PDU ID:25 */
            UINT16_C( 25 ), /* TargetPduId */
            UINT16_C( 0 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: Com */
        },
        { /* PduR_RTabLoIfRx[26] -- Routing path:'FR_115_277R', calling module:'CanIf-LO-IF', PDU ID:26 */
            UINT16_C( 26 ), /* TargetPduId */
            UINT16_C( 0 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: Com */
        },
        { /* PduR_RTabLoIfRx[27] -- Routing path:'FR_116_278R', calling module:'CanIf-LO-IF', PDU ID:27 */
            UINT16_C( 27 ), /* TargetPduId */
            UINT16_C( 0 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: Com */
        },
        { /* PduR_RTabLoIfRx[28] -- Routing path:'FR_117_279R', calling module:'CanIf-LO-IF', PDU ID:28 */
            UINT16_C( 28 ), /* TargetPduId */
            UINT16_C( 0 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: Com */
        },
        { /* PduR_RTabLoIfRx[29] -- Routing path:'FR_118_280R', calling module:'CanIf-LO-IF', PDU ID:29 */
            UINT16_C( 29 ), /* TargetPduId */
            UINT16_C( 0 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: Com */
        },
        { /* PduR_RTabLoIfRx[30] -- Routing path:'FR_119_281R', calling module:'CanIf-LO-IF', PDU ID:30 */
            UINT16_C( 30 ), /* TargetPduId */
            UINT16_C( 0 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: Com */
        },
        { /* PduR_RTabLoIfRx[31] -- Routing path:'FR_11A_282R', calling module:'CanIf-LO-IF', PDU ID:31 */
            UINT16_C( 31 ), /* TargetPduId */
            UINT16_C( 0 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: Com */
        },
        { /* PduR_RTabLoIfRx[32] -- Routing path:'FR_11B_283R', calling module:'CanIf-LO-IF', PDU ID:32 */
            UINT16_C( 32 ), /* TargetPduId */
            UINT16_C( 0 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: Com */
        },
        { /* PduR_RTabLoIfRx[33] -- Routing path:'FR_11C_284R', calling module:'CanIf-LO-IF', PDU ID:33 */
            UINT16_C( 33 ), /* TargetPduId */
            UINT16_C( 0 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: Com */
        },
        { /* PduR_RTabLoIfRx[34] -- Routing path:'FR_11D_285R', calling module:'CanIf-LO-IF', PDU ID:34 */
            UINT16_C( 34 ), /* TargetPduId */
            UINT16_C( 0 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: Com */
        },
        { /* PduR_RTabLoIfRx[35] -- Routing path:'FR_11E_286R', calling module:'CanIf-LO-IF', PDU ID:35 */
            UINT16_C( 35 ), /* TargetPduId */
            UINT16_C( 0 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: Com */
        },
        { /* PduR_RTabLoIfRx[36] -- Routing path:'FR_11F_287R', calling module:'CanIf-LO-IF', PDU ID:36 */
            UINT16_C( 36 ), /* TargetPduId */
            UINT16_C( 0 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: Com */
        },
        { /* PduR_RTabLoIfRx[37] -- Routing path:'FR_120_288R', calling module:'CanIf-LO-IF', PDU ID:37 */
            UINT16_C( 37 ), /* TargetPduId */
            UINT16_C( 0 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: Com */
        },
        { /* PduR_RTabLoIfRx[38] -- Routing path:'FR_136_310R', calling module:'CanIf-LO-IF', PDU ID:38 */
            UINT16_C( 38 ), /* TargetPduId */
            UINT16_C( 0 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: Com */
        },
        { /* PduR_RTabLoIfRx[39] -- Routing path:'FR_138_312R', calling module:'CanIf-LO-IF', PDU ID:39 */
            UINT16_C( 39 ), /* TargetPduId */
            UINT16_C( 0 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: Com */
        },
        { /* PduR_RTabLoIfRx[40] -- Routing path:'ADC_19B_411R', calling module:'CanIf-LO-IF', PDU ID:40 */
            UINT16_C( 40 ), /* TargetPduId */
            UINT16_C( 0 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: Com */
        },
        { /* PduR_RTabLoIfRx[41] -- Routing path:'ADC_1F1_497R', calling module:'CanIf-LO-IF', PDU ID:41 */
            UINT16_C( 43 ), /* TargetPduId */
            UINT16_C( 0 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: Com */
        },
        { /* PduR_RTabLoIfRx[42] -- Routing path:'ADC_200_512R', calling module:'CanIf-LO-IF', PDU ID:42 */
            UINT16_C( 41 ), /* TargetPduId */
            UINT16_C( 0 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: Com */
        },
        { /* PduR_RTabLoIfRx[43] -- Routing path:'ADC_201_513R', calling module:'CanIf-LO-IF', PDU ID:43 */
            UINT16_C( 42 ), /* TargetPduId */
            UINT16_C( 0 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: Com */
        },
        { /* PduR_RTabLoIfRx[44] -- Routing path:'ADC_344_836R', calling module:'CanIf-LO-IF', PDU ID:44 */
            UINT16_C( 44 ), /* TargetPduId */
            UINT16_C( 0 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: Com */
        },
        { /* PduR_RTabLoIfRx[45] -- Routing path:'ADC_345_837R', calling module:'CanIf-LO-IF', PDU ID:45 */
            UINT16_C( 45 ), /* TargetPduId */
            UINT16_C( 0 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: Com */
        },
        { /* PduR_RTabLoIfRx[46] -- Routing path:'ADC_346_838R', calling module:'CanIf-LO-IF', PDU ID:46 */
            UINT16_C( 46 ), /* TargetPduId */
            UINT16_C( 0 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: Com */
        }
    },
    { /* PduR_RTabLoIfTx */
        { /* PduR_RTabLoIfTx[0] -- Routing path:'FC_1BA_442T', calling module:'CanIf-LO-IF', PDU ID:0 */
            UINT16_C( 35 ), /* TargetPduId */
            UINT16_C( 0 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: Com */
        },
        { /* PduR_RTabLoIfTx[1] -- Routing path:'FC_244_580T', calling module:'CanIf-LO-IF', PDU ID:1 */
            UINT16_C( 39 ), /* TargetPduId */
            UINT16_C( 0 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: Com */
        },
        { /* PduR_RTabLoIfTx[2] -- Routing path:'FC_307_775T', calling module:'CanIf-LO-IF', PDU ID:2 */
            UINT16_C( 40 ), /* TargetPduId */
            UINT16_C( 0 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: Com */
        },
        { /* PduR_RTabLoIfTx[3] -- Routing path:'FC_312_786T', calling module:'CanIf-LO-IF', PDU ID:3 */
            UINT16_C( 41 ), /* TargetPduId */
            UINT16_C( 0 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: Com */
        },
        { /* PduR_RTabLoIfTx[4] -- Routing path:'FC_31A_794T', calling module:'CanIf-LO-IF', PDU ID:4 */
            UINT16_C( 42 ), /* TargetPduId */
            UINT16_C( 0 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: Com */
        },
        { /* PduR_RTabLoIfTx[5] -- Routing path:'FC_571_1393T', calling module:'CanIf-LO-IF', PDU ID:5 */
            UINT16_C( 43 ), /* TargetPduId */
            UINT16_C( 0 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: Com */
        },
        { /* PduR_RTabLoIfTx[6] -- Routing path:'FC_592_1426T', calling module:'CanIf-LO-IF', PDU ID:6 */
            UINT16_C( 44 ), /* TargetPduId */
            UINT16_C( 0 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: Com */
        },
        { /* PduR_RTabLoIfTx[7] -- Routing path:'FC_694_1684T', calling module:'CanIf-LO-IF', PDU ID:7 */
            UINT16_C( 46 ), /* TargetPduId */
            UINT16_C( 0 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: Com */
        },
        { /* PduR_RTabLoIfTx[8] -- Routing path:'FC_107_263T', calling module:'CanIf-LO-IF', PDU ID:8 */
            UINT16_C( 0 ), /* TargetPduId */
            UINT16_C( 0 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: Com */
        },
        { /* PduR_RTabLoIfTx[9] -- Routing path:'FC_108_264T', calling module:'CanIf-LO-IF', PDU ID:9 */
            UINT16_C( 1 ), /* TargetPduId */
            UINT16_C( 0 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: Com */
        },
        { /* PduR_RTabLoIfTx[10] -- Routing path:'FC_150_336T', calling module:'CanIf-LO-IF', PDU ID:10 */
            UINT16_C( 2 ), /* TargetPduId */
            UINT16_C( 0 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: Com */
        },
        { /* PduR_RTabLoIfTx[11] -- Routing path:'FC_151_337T', calling module:'CanIf-LO-IF', PDU ID:11 */
            UINT16_C( 3 ), /* TargetPduId */
            UINT16_C( 0 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: Com */
        },
        { /* PduR_RTabLoIfTx[12] -- Routing path:'FC_152_338T', calling module:'CanIf-LO-IF', PDU ID:12 */
            UINT16_C( 4 ), /* TargetPduId */
            UINT16_C( 0 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: Com */
        },
        { /* PduR_RTabLoIfTx[13] -- Routing path:'FC_153_339T', calling module:'CanIf-LO-IF', PDU ID:13 */
            UINT16_C( 5 ), /* TargetPduId */
            UINT16_C( 0 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: Com */
        },
        { /* PduR_RTabLoIfTx[14] -- Routing path:'FC_154_340T', calling module:'CanIf-LO-IF', PDU ID:14 */
            UINT16_C( 6 ), /* TargetPduId */
            UINT16_C( 0 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: Com */
        },
        { /* PduR_RTabLoIfTx[15] -- Routing path:'FC_160_352T', calling module:'CanIf-LO-IF', PDU ID:15 */
            UINT16_C( 7 ), /* TargetPduId */
            UINT16_C( 0 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: Com */
        },
        { /* PduR_RTabLoIfTx[16] -- Routing path:'FC_161_353T', calling module:'CanIf-LO-IF', PDU ID:16 */
            UINT16_C( 8 ), /* TargetPduId */
            UINT16_C( 0 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: Com */
        },
        { /* PduR_RTabLoIfTx[17] -- Routing path:'FC_162_354T', calling module:'CanIf-LO-IF', PDU ID:17 */
            UINT16_C( 9 ), /* TargetPduId */
            UINT16_C( 0 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: Com */
        },
        { /* PduR_RTabLoIfTx[18] -- Routing path:'FC_163_355T', calling module:'CanIf-LO-IF', PDU ID:18 */
            UINT16_C( 10 ), /* TargetPduId */
            UINT16_C( 0 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: Com */
        },
        { /* PduR_RTabLoIfTx[19] -- Routing path:'FC_164_356T', calling module:'CanIf-LO-IF', PDU ID:19 */
            UINT16_C( 11 ), /* TargetPduId */
            UINT16_C( 0 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: Com */
        },
        { /* PduR_RTabLoIfTx[20] -- Routing path:'FC_165_357T', calling module:'CanIf-LO-IF', PDU ID:20 */
            UINT16_C( 12 ), /* TargetPduId */
            UINT16_C( 0 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: Com */
        },
        { /* PduR_RTabLoIfTx[21] -- Routing path:'FC_166_358T', calling module:'CanIf-LO-IF', PDU ID:21 */
            UINT16_C( 13 ), /* TargetPduId */
            UINT16_C( 0 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: Com */
        },
        { /* PduR_RTabLoIfTx[22] -- Routing path:'FC_167_359T', calling module:'CanIf-LO-IF', PDU ID:22 */
            UINT16_C( 14 ), /* TargetPduId */
            UINT16_C( 0 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: Com */
        },
        { /* PduR_RTabLoIfTx[23] -- Routing path:'FC_168_360T', calling module:'CanIf-LO-IF', PDU ID:23 */
            UINT16_C( 15 ), /* TargetPduId */
            UINT16_C( 0 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: Com */
        },
        { /* PduR_RTabLoIfTx[24] -- Routing path:'FC_169_361T', calling module:'CanIf-LO-IF', PDU ID:24 */
            UINT16_C( 16 ), /* TargetPduId */
            UINT16_C( 0 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: Com */
        },
        { /* PduR_RTabLoIfTx[25] -- Routing path:'FC_170_368T', calling module:'CanIf-LO-IF', PDU ID:25 */
            UINT16_C( 17 ), /* TargetPduId */
            UINT16_C( 0 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: Com */
        },
        { /* PduR_RTabLoIfTx[26] -- Routing path:'FC_171_369T', calling module:'CanIf-LO-IF', PDU ID:26 */
            UINT16_C( 18 ), /* TargetPduId */
            UINT16_C( 0 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: Com */
        },
        { /* PduR_RTabLoIfTx[27] -- Routing path:'FC_172_370T', calling module:'CanIf-LO-IF', PDU ID:27 */
            UINT16_C( 19 ), /* TargetPduId */
            UINT16_C( 0 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: Com */
        },
        { /* PduR_RTabLoIfTx[28] -- Routing path:'FC_173_371T', calling module:'CanIf-LO-IF', PDU ID:28 */
            UINT16_C( 20 ), /* TargetPduId */
            UINT16_C( 0 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: Com */
        },
        { /* PduR_RTabLoIfTx[29] -- Routing path:'FC_174_372T', calling module:'CanIf-LO-IF', PDU ID:29 */
            UINT16_C( 21 ), /* TargetPduId */
            UINT16_C( 0 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: Com */
        },
        { /* PduR_RTabLoIfTx[30] -- Routing path:'FC_175_373T', calling module:'CanIf-LO-IF', PDU ID:30 */
            UINT16_C( 22 ), /* TargetPduId */
            UINT16_C( 0 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: Com */
        },
        { /* PduR_RTabLoIfTx[31] -- Routing path:'FC_176_374T', calling module:'CanIf-LO-IF', PDU ID:31 */
            UINT16_C( 23 ), /* TargetPduId */
            UINT16_C( 0 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: Com */
        },
        { /* PduR_RTabLoIfTx[32] -- Routing path:'FC_177_375T', calling module:'CanIf-LO-IF', PDU ID:32 */
            UINT16_C( 24 ), /* TargetPduId */
            UINT16_C( 0 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: Com */
        },
        { /* PduR_RTabLoIfTx[33] -- Routing path:'FC_178_376T', calling module:'CanIf-LO-IF', PDU ID:33 */
            UINT16_C( 25 ), /* TargetPduId */
            UINT16_C( 0 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: Com */
        },
        { /* PduR_RTabLoIfTx[34] -- Routing path:'FC_179_377T', calling module:'CanIf-LO-IF', PDU ID:34 */
            UINT16_C( 26 ), /* TargetPduId */
            UINT16_C( 0 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: Com */
        },
        { /* PduR_RTabLoIfTx[35] -- Routing path:'FC_180_384T', calling module:'CanIf-LO-IF', PDU ID:35 */
            UINT16_C( 27 ), /* TargetPduId */
            UINT16_C( 0 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: Com */
        },
        { /* PduR_RTabLoIfTx[36] -- Routing path:'FC_181_385T', calling module:'CanIf-LO-IF', PDU ID:36 */
            UINT16_C( 28 ), /* TargetPduId */
            UINT16_C( 0 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: Com */
        },
        { /* PduR_RTabLoIfTx[37] -- Routing path:'FC_190_400T', calling module:'CanIf-LO-IF', PDU ID:37 */
            UINT16_C( 29 ), /* TargetPduId */
            UINT16_C( 0 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: Com */
        },
        { /* PduR_RTabLoIfTx[38] -- Routing path:'FC_193_403T', calling module:'CanIf-LO-IF', PDU ID:38 */
            UINT16_C( 30 ), /* TargetPduId */
            UINT16_C( 0 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: Com */
        },
        { /* PduR_RTabLoIfTx[39] -- Routing path:'FC_195_405T', calling module:'CanIf-LO-IF', PDU ID:39 */
            UINT16_C( 31 ), /* TargetPduId */
            UINT16_C( 0 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: Com */
        },
        { /* PduR_RTabLoIfTx[40] -- Routing path:'FC_196_406T', calling module:'CanIf-LO-IF', PDU ID:40 */
            UINT16_C( 32 ), /* TargetPduId */
            UINT16_C( 0 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: Com */
        },
        { /* PduR_RTabLoIfTx[41] -- Routing path:'FC_197_407T', calling module:'CanIf-LO-IF', PDU ID:41 */
            UINT16_C( 33 ), /* TargetPduId */
            UINT16_C( 0 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: Com */
        },
        { /* PduR_RTabLoIfTx[42] -- Routing path:'FC_198_408T', calling module:'CanIf-LO-IF', PDU ID:42 */
            UINT16_C( 34 ), /* TargetPduId */
            UINT16_C( 0 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: Com */
        },
        { /* PduR_RTabLoIfTx[43] -- Routing path:'FC_1F2_498T', calling module:'CanIf-LO-IF', PDU ID:43 */
            UINT16_C( 36 ), /* TargetPduId */
            UINT16_C( 0 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: Com */
        },
        { /* PduR_RTabLoIfTx[44] -- Routing path:'FC_204_516T', calling module:'CanIf-LO-IF', PDU ID:44 */
            UINT16_C( 37 ), /* TargetPduId */
            UINT16_C( 0 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: Com */
        },
        { /* PduR_RTabLoIfTx[45] -- Routing path:'FC_207_519T', calling module:'CanIf-LO-IF', PDU ID:45 */
            UINT16_C( 38 ), /* TargetPduId */
            UINT16_C( 0 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: Com */
        },
        { /* PduR_RTabLoIfTx[46] -- Routing path:'FC_620_1568T', calling module:'CanIf-LO-IF', PDU ID:46 */
            UINT16_C( 45 ), /* TargetPduId */
            UINT16_C( 0 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: Com */
        }
    },
    { /* PduR_RTabUpIfTx */
        { /* PduR_RTabUpIfTx[0] -- Routing path:'FC_1BA_442T', calling module:'Com-UP-IF', PDU ID:0 */
            UINT16_C( 0 ), /* TargetPduId */
            UINT16_C( 2 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: CanIf */
        },
        { /* PduR_RTabUpIfTx[1] -- Routing path:'FC_244_580T', calling module:'Com-UP-IF', PDU ID:1 */
            UINT16_C( 1 ), /* TargetPduId */
            UINT16_C( 2 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: CanIf */
        },
        { /* PduR_RTabUpIfTx[2] -- Routing path:'FC_307_775T', calling module:'Com-UP-IF', PDU ID:2 */
            UINT16_C( 2 ), /* TargetPduId */
            UINT16_C( 2 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: CanIf */
        },
        { /* PduR_RTabUpIfTx[3] -- Routing path:'FC_312_786T', calling module:'Com-UP-IF', PDU ID:3 */
            UINT16_C( 3 ), /* TargetPduId */
            UINT16_C( 2 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: CanIf */
        },
        { /* PduR_RTabUpIfTx[4] -- Routing path:'FC_31A_794T', calling module:'Com-UP-IF', PDU ID:4 */
            UINT16_C( 4 ), /* TargetPduId */
            UINT16_C( 2 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: CanIf */
        },
        { /* PduR_RTabUpIfTx[5] -- Routing path:'FC_571_1393T', calling module:'Com-UP-IF', PDU ID:5 */
            UINT16_C( 5 ), /* TargetPduId */
            UINT16_C( 2 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: CanIf */
        },
        { /* PduR_RTabUpIfTx[6] -- Routing path:'FC_592_1426T', calling module:'Com-UP-IF', PDU ID:6 */
            UINT16_C( 6 ), /* TargetPduId */
            UINT16_C( 2 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: CanIf */
        },
        { /* PduR_RTabUpIfTx[7] -- Routing path:'FC_694_1684T', calling module:'Com-UP-IF', PDU ID:7 */
            UINT16_C( 7 ), /* TargetPduId */
            UINT16_C( 2 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: CanIf */
        },
        { /* PduR_RTabUpIfTx[8] -- Routing path:'FC_107_263T', calling module:'Com-UP-IF', PDU ID:8 */
            UINT16_C( 12 ), /* TargetPduId */
            UINT16_C( 2 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: CanIf */
        },
        { /* PduR_RTabUpIfTx[9] -- Routing path:'FC_108_264T', calling module:'Com-UP-IF', PDU ID:9 */
            UINT16_C( 13 ), /* TargetPduId */
            UINT16_C( 2 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: CanIf */
        },
        { /* PduR_RTabUpIfTx[10] -- Routing path:'FC_150_336T', calling module:'Com-UP-IF', PDU ID:10 */
            UINT16_C( 15 ), /* TargetPduId */
            UINT16_C( 2 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: CanIf */
        },
        { /* PduR_RTabUpIfTx[11] -- Routing path:'FC_151_337T', calling module:'Com-UP-IF', PDU ID:11 */
            UINT16_C( 16 ), /* TargetPduId */
            UINT16_C( 2 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: CanIf */
        },
        { /* PduR_RTabUpIfTx[12] -- Routing path:'FC_152_338T', calling module:'Com-UP-IF', PDU ID:12 */
            UINT16_C( 17 ), /* TargetPduId */
            UINT16_C( 2 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: CanIf */
        },
        { /* PduR_RTabUpIfTx[13] -- Routing path:'FC_153_339T', calling module:'Com-UP-IF', PDU ID:13 */
            UINT16_C( 18 ), /* TargetPduId */
            UINT16_C( 2 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: CanIf */
        },
        { /* PduR_RTabUpIfTx[14] -- Routing path:'FC_154_340T', calling module:'Com-UP-IF', PDU ID:14 */
            UINT16_C( 19 ), /* TargetPduId */
            UINT16_C( 2 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: CanIf */
        },
        { /* PduR_RTabUpIfTx[15] -- Routing path:'FC_160_352T', calling module:'Com-UP-IF', PDU ID:15 */
            UINT16_C( 20 ), /* TargetPduId */
            UINT16_C( 2 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: CanIf */
        },
        { /* PduR_RTabUpIfTx[16] -- Routing path:'FC_161_353T', calling module:'Com-UP-IF', PDU ID:16 */
            UINT16_C( 21 ), /* TargetPduId */
            UINT16_C( 2 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: CanIf */
        },
        { /* PduR_RTabUpIfTx[17] -- Routing path:'FC_162_354T', calling module:'Com-UP-IF', PDU ID:17 */
            UINT16_C( 22 ), /* TargetPduId */
            UINT16_C( 2 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: CanIf */
        },
        { /* PduR_RTabUpIfTx[18] -- Routing path:'FC_163_355T', calling module:'Com-UP-IF', PDU ID:18 */
            UINT16_C( 23 ), /* TargetPduId */
            UINT16_C( 2 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: CanIf */
        },
        { /* PduR_RTabUpIfTx[19] -- Routing path:'FC_164_356T', calling module:'Com-UP-IF', PDU ID:19 */
            UINT16_C( 24 ), /* TargetPduId */
            UINT16_C( 2 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: CanIf */
        },
        { /* PduR_RTabUpIfTx[20] -- Routing path:'FC_165_357T', calling module:'Com-UP-IF', PDU ID:20 */
            UINT16_C( 25 ), /* TargetPduId */
            UINT16_C( 2 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: CanIf */
        },
        { /* PduR_RTabUpIfTx[21] -- Routing path:'FC_166_358T', calling module:'Com-UP-IF', PDU ID:21 */
            UINT16_C( 26 ), /* TargetPduId */
            UINT16_C( 2 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: CanIf */
        },
        { /* PduR_RTabUpIfTx[22] -- Routing path:'FC_167_359T', calling module:'Com-UP-IF', PDU ID:22 */
            UINT16_C( 27 ), /* TargetPduId */
            UINT16_C( 2 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: CanIf */
        },
        { /* PduR_RTabUpIfTx[23] -- Routing path:'FC_168_360T', calling module:'Com-UP-IF', PDU ID:23 */
            UINT16_C( 28 ), /* TargetPduId */
            UINT16_C( 2 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: CanIf */
        },
        { /* PduR_RTabUpIfTx[24] -- Routing path:'FC_169_361T', calling module:'Com-UP-IF', PDU ID:24 */
            UINT16_C( 29 ), /* TargetPduId */
            UINT16_C( 2 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: CanIf */
        },
        { /* PduR_RTabUpIfTx[25] -- Routing path:'FC_170_368T', calling module:'Com-UP-IF', PDU ID:25 */
            UINT16_C( 30 ), /* TargetPduId */
            UINT16_C( 2 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: CanIf */
        },
        { /* PduR_RTabUpIfTx[26] -- Routing path:'FC_171_369T', calling module:'Com-UP-IF', PDU ID:26 */
            UINT16_C( 31 ), /* TargetPduId */
            UINT16_C( 2 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: CanIf */
        },
        { /* PduR_RTabUpIfTx[27] -- Routing path:'FC_172_370T', calling module:'Com-UP-IF', PDU ID:27 */
            UINT16_C( 32 ), /* TargetPduId */
            UINT16_C( 2 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: CanIf */
        },
        { /* PduR_RTabUpIfTx[28] -- Routing path:'FC_173_371T', calling module:'Com-UP-IF', PDU ID:28 */
            UINT16_C( 33 ), /* TargetPduId */
            UINT16_C( 2 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: CanIf */
        },
        { /* PduR_RTabUpIfTx[29] -- Routing path:'FC_174_372T', calling module:'Com-UP-IF', PDU ID:29 */
            UINT16_C( 34 ), /* TargetPduId */
            UINT16_C( 2 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: CanIf */
        },
        { /* PduR_RTabUpIfTx[30] -- Routing path:'FC_175_373T', calling module:'Com-UP-IF', PDU ID:30 */
            UINT16_C( 35 ), /* TargetPduId */
            UINT16_C( 2 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: CanIf */
        },
        { /* PduR_RTabUpIfTx[31] -- Routing path:'FC_176_374T', calling module:'Com-UP-IF', PDU ID:31 */
            UINT16_C( 36 ), /* TargetPduId */
            UINT16_C( 2 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: CanIf */
        },
        { /* PduR_RTabUpIfTx[32] -- Routing path:'FC_177_375T', calling module:'Com-UP-IF', PDU ID:32 */
            UINT16_C( 37 ), /* TargetPduId */
            UINT16_C( 2 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: CanIf */
        },
        { /* PduR_RTabUpIfTx[33] -- Routing path:'FC_178_376T', calling module:'Com-UP-IF', PDU ID:33 */
            UINT16_C( 38 ), /* TargetPduId */
            UINT16_C( 2 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: CanIf */
        },
        { /* PduR_RTabUpIfTx[34] -- Routing path:'FC_179_377T', calling module:'Com-UP-IF', PDU ID:34 */
            UINT16_C( 39 ), /* TargetPduId */
            UINT16_C( 2 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: CanIf */
        },
        { /* PduR_RTabUpIfTx[35] -- Routing path:'FC_180_384T', calling module:'Com-UP-IF', PDU ID:35 */
            UINT16_C( 40 ), /* TargetPduId */
            UINT16_C( 2 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: CanIf */
        },
        { /* PduR_RTabUpIfTx[36] -- Routing path:'FC_181_385T', calling module:'Com-UP-IF', PDU ID:36 */
            UINT16_C( 41 ), /* TargetPduId */
            UINT16_C( 2 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: CanIf */
        },
        { /* PduR_RTabUpIfTx[37] -- Routing path:'FC_190_400T', calling module:'Com-UP-IF', PDU ID:37 */
            UINT16_C( 42 ), /* TargetPduId */
            UINT16_C( 2 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: CanIf */
        },
        { /* PduR_RTabUpIfTx[38] -- Routing path:'FC_193_403T', calling module:'Com-UP-IF', PDU ID:38 */
            UINT16_C( 43 ), /* TargetPduId */
            UINT16_C( 2 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: CanIf */
        },
        { /* PduR_RTabUpIfTx[39] -- Routing path:'FC_195_405T', calling module:'Com-UP-IF', PDU ID:39 */
            UINT16_C( 44 ), /* TargetPduId */
            UINT16_C( 2 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: CanIf */
        },
        { /* PduR_RTabUpIfTx[40] -- Routing path:'FC_196_406T', calling module:'Com-UP-IF', PDU ID:40 */
            UINT16_C( 45 ), /* TargetPduId */
            UINT16_C( 2 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: CanIf */
        },
        { /* PduR_RTabUpIfTx[41] -- Routing path:'FC_197_407T', calling module:'Com-UP-IF', PDU ID:41 */
            UINT16_C( 46 ), /* TargetPduId */
            UINT16_C( 2 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: CanIf */
        },
        { /* PduR_RTabUpIfTx[42] -- Routing path:'FC_198_408T', calling module:'Com-UP-IF', PDU ID:42 */
            UINT16_C( 47 ), /* TargetPduId */
            UINT16_C( 2 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: CanIf */
        },
        { /* PduR_RTabUpIfTx[43] -- Routing path:'FC_1F2_498T', calling module:'Com-UP-IF', PDU ID:43 */
            UINT16_C( 48 ), /* TargetPduId */
            UINT16_C( 2 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: CanIf */
        },
        { /* PduR_RTabUpIfTx[44] -- Routing path:'FC_204_516T', calling module:'Com-UP-IF', PDU ID:44 */
            UINT16_C( 50 ), /* TargetPduId */
            UINT16_C( 2 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: CanIf */
        },
        { /* PduR_RTabUpIfTx[45] -- Routing path:'FC_207_519T', calling module:'Com-UP-IF', PDU ID:45 */
            UINT16_C( 51 ), /* TargetPduId */
            UINT16_C( 2 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: CanIf */
        },
        { /* PduR_RTabUpIfTx[46] -- Routing path:'FC_620_1568T', calling module:'Com-UP-IF', PDU ID:46 */
            UINT16_C( 52 ), /* TargetPduId */
            UINT16_C( 2 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: CanIf */
        }
    },
    { /* PduR_RTabLoTpRx */
        { /* PduR_RTabLoTpRx[0] -- Routing path:'Diag_Func_IpduR', calling module:'CanTp-LO-TP', PDU ID:0 */
            UINT16_C( 3 ), /* TargetPduId */
            UINT16_C( 1 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: Dcm */
        },
        { /* PduR_RTabLoTpRx[1] -- Routing path:'Diag_FuncFD_IpduR', calling module:'CanTp-LO-TP', PDU ID:1 */
            UINT16_C( 1 ), /* TargetPduId */
            UINT16_C( 1 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: Dcm */
        },
        { /* PduR_RTabLoTpRx[2] -- Routing path:'Diag_Phys_IpduR', calling module:'CanTp-LO-TP', PDU ID:2 */
            UINT16_C( 2 ), /* TargetPduId */
            UINT16_C( 1 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: Dcm */
        },
        { /* PduR_RTabLoTpRx[3] -- Routing path:'Diag_PhysFD_IpduR', calling module:'CanTp-LO-TP', PDU ID:3 */
            UINT16_C( 0 ), /* TargetPduId */
            UINT16_C( 1 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: Dcm */
        }
    },
    { /* PduR_RTabLoTpTx */
        { /* PduR_RTabLoTpTx[0] -- Routing path:'Diag_DataRespFD_IpduT', calling module:'CanTp-LO-TP', PDU ID:0 */
            UINT16_C( 0 ), /* TargetPduId */
            UINT16_C( 1 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: Dcm */
        },
        { /* PduR_RTabLoTpTx[1] -- Routing path:'Diag_DataResp_IpduT', calling module:'CanTp-LO-TP', PDU ID:1 */
            UINT16_C( 1 ), /* TargetPduId */
            UINT16_C( 1 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: Dcm */
        }
    },
    { /* PduR_RTabUpTpTx */
        { /* PduR_RTabUpTpTx[0] -- Routing path:'Diag_DataRespFD_IpduT', calling module:'Dcm-UP-TP', PDU ID:0 */
            UINT16_C( 1 ), /* TargetPduId */
            UINT16_C( 0 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: CanTp */
        },
        { /* PduR_RTabUpTpTx[1] -- Routing path:'Diag_DataResp_IpduT', calling module:'Dcm-UP-TP', PDU ID:1 */
            UINT16_C( 0 ), /* TargetPduId */
            UINT16_C( 0 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: CanTp */
        }
    },
    { /* PduR_RTabUpTpRx */
        { /* PduR_RTabUpTpRx[0] -- Routing path:'Diag_Func_IpduR', calling module:'Dcm-UP-TP', PDU ID:0 */
            UINT16_C( 3 ), /* TargetPduId */
            UINT16_C( 0 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: CanTp */
        },
        { /* PduR_RTabUpTpRx[1] -- Routing path:'Diag_FuncFD_IpduR', calling module:'Dcm-UP-TP', PDU ID:1 */
            UINT16_C( 2 ), /* TargetPduId */
            UINT16_C( 0 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: CanTp */
        },
        { /* PduR_RTabUpTpRx[2] -- Routing path:'Diag_Phys_IpduR', calling module:'Dcm-UP-TP', PDU ID:2 */
            UINT16_C( 0 ), /* TargetPduId */
            UINT16_C( 0 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: CanTp */
        },
        { /* PduR_RTabUpTpRx[3] -- Routing path:'Diag_PhysFD_IpduR', calling module:'Dcm-UP-TP', PDU ID:3 */
            UINT16_C( 1 ), /* TargetPduId */
            UINT16_C( 0 ) /* TargetModuleAPIRef -- TargetModuleAPIRef: CanTp */
        }
    }
};

/* Deviation MISRAC2012-1, MISRAC2012-2, MISRAC2012-3 <STOP> */

#define PDUR_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include <PduR_MemMap.h>

/*==================[internal constants]=====================================*/


/*==================[external data]==========================================*/


/*==================[internal data]==========================================*/


/*==================[external function definitions]==========================*/


/*==================[internal function definitions]==========================*/


/*==================[end of file]============================================*/

