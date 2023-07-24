


/**
 * \file
 *
 * \brief AUTOSAR PbcfgM
 *
 * This file contains the implementation of the AUTOSAR
 * module PbcfgM.
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

#include <PbcfgM_PBcfg.h>
#include <BswM_Int_Cfg.h>
#include <TSAutosar.h>
#include <Compiler.h>
#define TS_RELOCATABLE_CFG_ENABLE STD_ON
#define TS_PB_CFG_NAME PbcfgM_Config
#define TS_PB_CFG_LAYOUT_TYPE PbcfgM_ConstConfigLayoutType
#include <TSPBConfig_Init.h>

/*==================[macros]=================================================*/


/*==================[type definitions]=======================================*/


/*==================[external function declarations]=========================*/


/*==================[internal function declarations]=========================*/


/*==================[external constants]=====================================*/

#define PBCFGM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include <PbcfgM_MemMap.h>

/* Deviation MISRAC2012-1, MISRAC2012-2, MISRAC2012-3 <START> */
PbcfgM_ConstConfigLayoutType PbcfgM_Config = {
    { /* PbcfgM_RootConfig */
        UINT32_C( 2281703698 ), /* PlatformSignature */
        UINT32_C( 3958107115 ), /* LcfgSignature */
        UINT32_C( 2582618360 ), /* CfgSignature */
        UINT32_C( 3637186157 ), /* PublicInfoSignature */
        UINT16_C( 1 ), /* numConfigEntry */
        TS_MAKEREF2CFG( ConfigEntries[0] ) /* ConfigEntryRef */
    },
    { /* ConfigEntries */
        { /* ConfigEntries[0] */
            TS_MAKEREF2CFG( ConfigBswM ), /* ConfigRef */
            UINT16_C( 42 ), /* ModuleId */
            UINT16_C( 0 ) /* InstanceId */
        }
    },


#undef TS_PB_CFG_LAYOUT_TYPE
#define TS_PB_CFG_LAYOUT_TYPE BswM_ConfigLayoutType

#undef TS_PB_CFG_NAME
#define TS_PB_CFG_NAME PbcfgM_Config.ConfigBswM
#include <TSPBConfig_Init.h>

    { /* ConfigBswM */
        { /* BswM_RootConfig */
            { /* BswM_RootConfig[0] */
                TS_MAKEREF2CFG( RuleTable[0] ), /* RuleTable */
                TS_MAKEREF2CFG( RuleDependencyTable[0] ), /* RuleDependencyTable */
                TS_MAKEREF2CFG( RuleDependencyListRangeTable[0] ), /* RuleDependencyListRangeTable */
                TS_MAKEREF2CFG( ActionListTable[0] ), /* ActionListTable */
                TS_MAKEREF2CFG( ActionListItemTable[0] ), /* ActionListItemTable */
                TS_MAKEREF2CFG( PduGroupSwitchActionTable[0] ), /* PduGroupSwitchActionTable */
                TS_MAKEREF2CFG( UInt8InitialValuesTable[0] ), /* UInt8InitialValuesTable */
                TS_MAKEREF2CFG( UInt16InitialValuesTable[0] ), /* UInt16InitialValuesTable */
                TS_MAKENULLREF2CFG, /* UInt32InitialValuesTable */
                UINT32_C( 2281703698 ), /* PlatformSignature */
                UINT32_C( 1858847467 ), /* LcfgSignature */
                UINT32_C( 662634896 ), /* CfgSignature */
                UINT32_C( 3585052355 ), /* PublicInfoSignature */
                UINT16_C( 27 ), /* NumRules */
                UINT16_C( 24 ), /* NumRulesDeferred */
                UINT16_C( 29 ) /* NumActionLists */
            },
            { /* BswM_RootConfig[1] */
                TS_MAKEREF2CFG( RuleTable[27] ), /* RuleTable */
                TS_MAKEREF2CFG( RuleDependencyTable[28] ), /* RuleDependencyTable */
                TS_MAKEREF2CFG( RuleDependencyListRangeTable[8] ), /* RuleDependencyListRangeTable */
                TS_MAKEREF2CFG( ActionListTable[29] ), /* ActionListTable */
                TS_MAKEREF2CFG( ActionListItemTable[55] ), /* ActionListItemTable */
                TS_MAKENULLREF2CFG, /* PduGroupSwitchActionTable */
                TS_MAKEREF2CFG( UInt8InitialValuesTable[5] ), /* UInt8InitialValuesTable */
                TS_MAKEREF2CFG( UInt16InitialValuesTable[1] ), /* UInt16InitialValuesTable */
                TS_MAKENULLREF2CFG, /* UInt32InitialValuesTable */
                UINT32_C( 2281703698 ), /* PlatformSignature */
                UINT32_C( 1858847467 ), /* LcfgSignature */
                UINT32_C( 662634896 ), /* CfgSignature */
                UINT32_C( 3585052355 ), /* PublicInfoSignature */
                UINT16_C( 6 ), /* NumRules */
                UINT16_C( 0 ), /* NumRulesDeferred */
                UINT16_C( 6 ) /* NumActionLists */
            },
            { /* BswM_RootConfig[2] */
                TS_MAKEREF2CFG( RuleTable[33] ), /* RuleTable */
                TS_MAKEREF2CFG( RuleDependencyTable[34] ), /* RuleDependencyTable */
                TS_MAKEREF2CFG( RuleDependencyListRangeTable[10] ), /* RuleDependencyListRangeTable */
                TS_MAKEREF2CFG( ActionListTable[35] ), /* ActionListTable */
                TS_MAKEREF2CFG( ActionListItemTable[61] ), /* ActionListItemTable */
                TS_MAKENULLREF2CFG, /* PduGroupSwitchActionTable */
                TS_MAKEREF2CFG( UInt8InitialValuesTable[6] ), /* UInt8InitialValuesTable */
                TS_MAKEREF2CFG( UInt16InitialValuesTable[2] ), /* UInt16InitialValuesTable */
                TS_MAKENULLREF2CFG, /* UInt32InitialValuesTable */
                UINT32_C( 2281703698 ), /* PlatformSignature */
                UINT32_C( 1858847467 ), /* LcfgSignature */
                UINT32_C( 662634896 ), /* CfgSignature */
                UINT32_C( 3585052355 ), /* PublicInfoSignature */
                UINT16_C( 6 ), /* NumRules */
                UINT16_C( 0 ), /* NumRulesDeferred */
                UINT16_C( 6 ) /* NumActionLists */
            },
            { /* BswM_RootConfig[3] */
                TS_MAKEREF2CFG( RuleTable[39] ), /* RuleTable */
                TS_MAKEREF2CFG( RuleDependencyTable[40] ), /* RuleDependencyTable */
                TS_MAKEREF2CFG( RuleDependencyListRangeTable[12] ), /* RuleDependencyListRangeTable */
                TS_MAKEREF2CFG( ActionListTable[41] ), /* ActionListTable */
                TS_MAKEREF2CFG( ActionListItemTable[67] ), /* ActionListItemTable */
                TS_MAKENULLREF2CFG, /* PduGroupSwitchActionTable */
                TS_MAKEREF2CFG( UInt8InitialValuesTable[7] ), /* UInt8InitialValuesTable */
                TS_MAKEREF2CFG( UInt16InitialValuesTable[3] ), /* UInt16InitialValuesTable */
                TS_MAKENULLREF2CFG, /* UInt32InitialValuesTable */
                UINT32_C( 2281703698 ), /* PlatformSignature */
                UINT32_C( 1858847467 ), /* LcfgSignature */
                UINT32_C( 662634896 ), /* CfgSignature */
                UINT32_C( 3585052355 ), /* PublicInfoSignature */
                UINT16_C( 6 ), /* NumRules */
                UINT16_C( 0 ), /* NumRulesDeferred */
                UINT16_C( 6 ) /* NumActionLists */
            }
        },
        { /* RuleTable */
            { /* RuleTable[0] -- BswM_EB_Rule_BswMRule_Dcm_EcuReset_JUMPTOSYSSUPPLIERBOOTLOADER */
                UINT16_C( 26 ), /* ID */
                UINT16_C( 26 ), /* LogicalExprIndex */
                UINT16_C( 28 ), /* TrueActionListIndex */
                UINT16_C( 65535 ), /* FalseActionListIndex */
                UINT8_C( 0 ) /* RuleInitState */
            },
            { /* RuleTable[1] -- BswM_EB_Rule_BswMRule_Dcm_EcuReset_SOFT */
                UINT16_C( 25 ), /* ID */
                UINT16_C( 25 ), /* LogicalExprIndex */
                UINT16_C( 27 ), /* TrueActionListIndex */
                UINT16_C( 65535 ), /* FalseActionListIndex */
                UINT8_C( 0 ) /* RuleInitState */
            },
            { /* RuleTable[2] -- BswM_EB_Rule_BswMRule_Dcm_EcuReset_HARD */
                UINT16_C( 24 ), /* ID */
                UINT16_C( 24 ), /* LogicalExprIndex */
                UINT16_C( 26 ), /* TrueActionListIndex */
                UINT16_C( 65535 ), /* FalseActionListIndex */
                UINT8_C( 0 ) /* RuleInitState */
            },
            { /* RuleTable[3] -- BswM_EB_Rule_BswMRule_Dcm_EcuReset_EXECUTE */
                UINT16_C( 23 ), /* ID */
                UINT16_C( 23 ), /* LogicalExprIndex */
                UINT16_C( 25 ), /* TrueActionListIndex */
                UINT16_C( 65535 ), /* FalseActionListIndex */
                UINT8_C( 0 ) /* RuleInitState */
            },
            { /* RuleTable[4] -- BswM_EB_Rule_BswMRule_Dcm_280003_EnRxTx_Norm_NM */
                UINT16_C( 20 ), /* ID */
                UINT16_C( 20 ), /* LogicalExprIndex */
                UINT16_C( 20 ), /* TrueActionListIndex */
                UINT16_C( 65535 ), /* FalseActionListIndex */
                UINT8_C( 0 ) /* RuleInitState */
            },
            { /* RuleTable[5] -- BswM_EB_Rule_BswMRule_Dcm_280303_DisRxTx_Norm_NM */
                UINT16_C( 19 ), /* ID */
                UINT16_C( 19 ), /* LogicalExprIndex */
                UINT16_C( 19 ), /* TrueActionListIndex */
                UINT16_C( 65535 ), /* FalseActionListIndex */
                UINT8_C( 0 ) /* RuleInitState */
            },
            { /* RuleTable[6] -- BswM_EB_Rule_BswMRule_Dcm_280002_EnRxTx_NM */
                UINT16_C( 18 ), /* ID */
                UINT16_C( 18 ), /* LogicalExprIndex */
                UINT16_C( 18 ), /* TrueActionListIndex */
                UINT16_C( 65535 ), /* FalseActionListIndex */
                UINT8_C( 0 ) /* RuleInitState */
            },
            { /* RuleTable[7] -- BswM_EB_Rule_BswMRule_Dcm_280302_DisRxTx_NM */
                UINT16_C( 17 ), /* ID */
                UINT16_C( 17 ), /* LogicalExprIndex */
                UINT16_C( 17 ), /* TrueActionListIndex */
                UINT16_C( 65535 ), /* FalseActionListIndex */
                UINT8_C( 0 ) /* RuleInitState */
            },
            { /* RuleTable[8] -- BswM_EB_Rule_BswMRule_Dcm_280001_EnRxTx_Norm */
                UINT16_C( 16 ), /* ID */
                UINT16_C( 16 ), /* LogicalExprIndex */
                UINT16_C( 16 ), /* TrueActionListIndex */
                UINT16_C( 65535 ), /* FalseActionListIndex */
                UINT8_C( 1 ) /* RuleInitState */
            },
            { /* RuleTable[9] -- BswM_EB_Rule_BswMRule_Dcm_280301_DisRxTx_Norm */
                UINT16_C( 15 ), /* ID */
                UINT16_C( 15 ), /* LogicalExprIndex */
                UINT16_C( 15 ), /* TrueActionListIndex */
                UINT16_C( 65535 ), /* FalseActionListIndex */
                UINT8_C( 0 ) /* RuleInitState */
            },
            { /* RuleTable[10] -- BswM_EB_Rule_BswMRule_CanSmNoCom_PrivateCan */
                UINT16_C( 13 ), /* ID */
                UINT16_C( 10 ), /* LogicalExprIndex */
                UINT16_C( 10 ), /* TrueActionListIndex */
                UINT16_C( 65535 ), /* FalseActionListIndex */
                UINT8_C( 0 ) /* RuleInitState */
            },
            { /* RuleTable[11] -- BswM_EB_Rule_BswMRule_CanSmBusoff_PrivateCan */
                UINT16_C( 12 ), /* ID */
                UINT16_C( 12 ), /* LogicalExprIndex */
                UINT16_C( 12 ), /* TrueActionListIndex */
                UINT16_C( 65535 ), /* FalseActionListIndex */
                UINT8_C( 0 ) /* RuleInitState */
            },
            { /* RuleTable[12] -- BswM_EB_Rule_BswMRule_CanSmSilentCom_PrivateCan */
                UINT16_C( 11 ), /* ID */
                UINT16_C( 11 ), /* LogicalExprIndex */
                UINT16_C( 11 ), /* TrueActionListIndex */
                UINT16_C( 65535 ), /* FalseActionListIndex */
                UINT8_C( 0 ) /* RuleInitState */
            },
            { /* RuleTable[13] -- BswM_EB_Rule_BswMRule_CanSmFullCom_PrivateCan */
                UINT16_C( 10 ), /* ID */
                UINT16_C( 13 ), /* LogicalExprIndex */
                UINT16_C( 13 ), /* TrueActionListIndex */
                UINT16_C( 65535 ), /* FalseActionListIndex */
                UINT8_C( 0 ) /* RuleInitState */
            },
            { /* RuleTable[14] -- BswM_EB_Rule_BswMRule_CanSmFullCom_PublicCan */
                UINT16_C( 9 ), /* ID */
                UINT16_C( 9 ), /* LogicalExprIndex */
                UINT16_C( 8 ), /* TrueActionListIndex */
                UINT16_C( 65535 ), /* FalseActionListIndex */
                UINT8_C( 0 ) /* RuleInitState */
            },
            { /* RuleTable[15] -- BswM_EB_Rule_BswMRule_CanSmBusoff_PublicCan */
                UINT16_C( 8 ), /* ID */
                UINT16_C( 8 ), /* LogicalExprIndex */
                UINT16_C( 7 ), /* TrueActionListIndex */
                UINT16_C( 65535 ), /* FalseActionListIndex */
                UINT8_C( 0 ) /* RuleInitState */
            },
            { /* RuleTable[16] -- BswM_EB_Rule_BswMRule_CanSmSilentCom_PublicCan */
                UINT16_C( 7 ), /* ID */
                UINT16_C( 7 ), /* LogicalExprIndex */
                UINT16_C( 6 ), /* TrueActionListIndex */
                UINT16_C( 65535 ), /* FalseActionListIndex */
                UINT8_C( 0 ) /* RuleInitState */
            },
            { /* RuleTable[17] -- BswM_EB_Rule_BswMRule_CanSmNoCom_PublicCan */
                UINT16_C( 6 ), /* ID */
                UINT16_C( 6 ), /* LogicalExprIndex */
                UINT16_C( 5 ), /* TrueActionListIndex */
                UINT16_C( 65535 ), /* FalseActionListIndex */
                UINT8_C( 0 ) /* RuleInitState */
            },
            { /* RuleTable[18] -- BswM_EB_Rule_BswMRule_PrepShutdown */
                UINT16_C( 5 ), /* ID */
                UINT16_C( 5 ), /* LogicalExprIndex */
                UINT16_C( 9 ), /* TrueActionListIndex */
                UINT16_C( 65535 ), /* FalseActionListIndex */
                UINT8_C( 0 ) /* RuleInitState */
            },
            { /* RuleTable[19] -- BswM_EB_Rule_BswMRule_RunTwo */
                UINT16_C( 4 ), /* ID */
                UINT16_C( 1 ), /* LogicalExprIndex */
                UINT16_C( 2 ), /* TrueActionListIndex */
                UINT16_C( 65535 ), /* FalseActionListIndex */
                UINT8_C( 0 ) /* RuleInitState */
            },
            { /* RuleTable[20] -- BswM_EB_Rule_BswMRule_GoOffOneB */
                UINT16_C( 3 ), /* ID */
                UINT16_C( 3 ), /* LogicalExprIndex */
                UINT16_C( 1 ), /* TrueActionListIndex */
                UINT16_C( 65535 ), /* FalseActionListIndex */
                UINT8_C( 0 ) /* RuleInitState */
            },
            { /* RuleTable[21] -- BswM_EB_Rule_BswMRule_GoOffOneA */
                UINT16_C( 2 ), /* ID */
                UINT16_C( 2 ), /* LogicalExprIndex */
                UINT16_C( 0 ), /* TrueActionListIndex */
                UINT16_C( 65535 ), /* FalseActionListIndex */
                UINT8_C( 0 ) /* RuleInitState */
            },
            { /* RuleTable[22] -- BswM_EB_Rule_BswMRule_StartupTwoB */
                UINT16_C( 1 ), /* ID */
                UINT16_C( 4 ), /* LogicalExprIndex */
                UINT16_C( 4 ), /* TrueActionListIndex */
                UINT16_C( 65535 ), /* FalseActionListIndex */
                UINT8_C( 0 ) /* RuleInitState */
            },
            { /* RuleTable[23] -- BswM_EB_Rule_BswMRule_StartupTwoA */
                UINT16_C( 0 ), /* ID */
                UINT16_C( 0 ), /* LogicalExprIndex */
                UINT16_C( 3 ), /* TrueActionListIndex */
                UINT16_C( 65535 ), /* FalseActionListIndex */
                UINT8_C( 0 ) /* RuleInitState */
            },
            { /* RuleTable[24] -- BswM_EB_Rule_BswMRule_Comco_PduGroupSwitchTxReq */
                UINT16_C( 22 ), /* ID */
                UINT16_C( 22 ), /* LogicalExprIndex */
                UINT16_C( 23 ), /* TrueActionListIndex */
                UINT16_C( 24 ), /* FalseActionListIndex */
                UINT8_C( 0 ) /* RuleInitState */
            },
            { /* RuleTable[25] -- BswM_EB_Rule_BswMRule_Comco_PduGroupSwitchRxReq */
                UINT16_C( 21 ), /* ID */
                UINT16_C( 21 ), /* LogicalExprIndex */
                UINT16_C( 21 ), /* TrueActionListIndex */
                UINT16_C( 22 ), /* FalseActionListIndex */
                UINT8_C( 0 ) /* RuleInitState */
            },
            { /* RuleTable[26] -- BswM_EB_Rule_BswMRule_WakupValidation_PublicCan */
                UINT16_C( 14 ), /* ID */
                UINT16_C( 14 ), /* LogicalExprIndex */
                UINT16_C( 14 ), /* TrueActionListIndex */
                UINT16_C( 65535 ), /* FalseActionListIndex */
                UINT8_C( 0 ) /* RuleInitState */
            },
            { /* RuleTable[27] -- BswM_EB_Rule_BswMRule_PrepShutdown */
                UINT16_C( 5 ), /* ID */
                UINT16_C( 5 ), /* LogicalExprIndex */
                UINT16_C( 5 ), /* TrueActionListIndex */
                UINT16_C( 65535 ), /* FalseActionListIndex */
                UINT8_C( 0 ) /* RuleInitState */
            },
            { /* RuleTable[28] -- BswM_EB_Rule_BswMRule_GoOffOneD */
                UINT16_C( 4 ), /* ID */
                UINT16_C( 4 ), /* LogicalExprIndex */
                UINT16_C( 4 ), /* TrueActionListIndex */
                UINT16_C( 65535 ), /* FalseActionListIndex */
                UINT8_C( 0 ) /* RuleInitState */
            },
            { /* RuleTable[29] -- BswM_EB_Rule_BswMRule_GoOffOneC */
                UINT16_C( 3 ), /* ID */
                UINT16_C( 3 ), /* LogicalExprIndex */
                UINT16_C( 3 ), /* TrueActionListIndex */
                UINT16_C( 65535 ), /* FalseActionListIndex */
                UINT8_C( 0 ) /* RuleInitState */
            },
            { /* RuleTable[30] -- BswM_EB_Rule_BswMRule_RunTwo */
                UINT16_C( 2 ), /* ID */
                UINT16_C( 2 ), /* LogicalExprIndex */
                UINT16_C( 0 ), /* TrueActionListIndex */
                UINT16_C( 65535 ), /* FalseActionListIndex */
                UINT8_C( 0 ) /* RuleInitState */
            },
            { /* RuleTable[31] -- BswM_EB_Rule_BswMRule_StartupTwoD */
                UINT16_C( 1 ), /* ID */
                UINT16_C( 1 ), /* LogicalExprIndex */
                UINT16_C( 2 ), /* TrueActionListIndex */
                UINT16_C( 65535 ), /* FalseActionListIndex */
                UINT8_C( 0 ) /* RuleInitState */
            },
            { /* RuleTable[32] -- BswM_EB_Rule_BswMRule_StartupTwoC */
                UINT16_C( 0 ), /* ID */
                UINT16_C( 0 ), /* LogicalExprIndex */
                UINT16_C( 1 ), /* TrueActionListIndex */
                UINT16_C( 65535 ), /* FalseActionListIndex */
                UINT8_C( 0 ) /* RuleInitState */
            },
            { /* RuleTable[33] -- BswM_EB_Rule_BswMRule_StartupTwoD */
                UINT16_C( 5 ), /* ID */
                UINT16_C( 1 ), /* LogicalExprIndex */
                UINT16_C( 5 ), /* TrueActionListIndex */
                UINT16_C( 65535 ), /* FalseActionListIndex */
                UINT8_C( 0 ) /* RuleInitState */
            },
            { /* RuleTable[34] -- BswM_EB_Rule_BswMRule_PrepShutdown */
                UINT16_C( 4 ), /* ID */
                UINT16_C( 5 ), /* LogicalExprIndex */
                UINT16_C( 4 ), /* TrueActionListIndex */
                UINT16_C( 65535 ), /* FalseActionListIndex */
                UINT8_C( 0 ) /* RuleInitState */
            },
            { /* RuleTable[35] -- BswM_EB_Rule_BswMRule_GoOffOneD */
                UINT16_C( 3 ), /* ID */
                UINT16_C( 4 ), /* LogicalExprIndex */
                UINT16_C( 3 ), /* TrueActionListIndex */
                UINT16_C( 65535 ), /* FalseActionListIndex */
                UINT8_C( 0 ) /* RuleInitState */
            },
            { /* RuleTable[36] -- BswM_EB_Rule_BswMRule_GoOffOneC */
                UINT16_C( 2 ), /* ID */
                UINT16_C( 3 ), /* LogicalExprIndex */
                UINT16_C( 2 ), /* TrueActionListIndex */
                UINT16_C( 65535 ), /* FalseActionListIndex */
                UINT8_C( 0 ) /* RuleInitState */
            },
            { /* RuleTable[37] -- BswM_EB_Rule_BswMRule_Runtwo */
                UINT16_C( 1 ), /* ID */
                UINT16_C( 2 ), /* LogicalExprIndex */
                UINT16_C( 0 ), /* TrueActionListIndex */
                UINT16_C( 65535 ), /* FalseActionListIndex */
                UINT8_C( 0 ) /* RuleInitState */
            },
            { /* RuleTable[38] -- BswM_EB_Rule_BswMRule_StartupTwoC */
                UINT16_C( 0 ), /* ID */
                UINT16_C( 0 ), /* LogicalExprIndex */
                UINT16_C( 1 ), /* TrueActionListIndex */
                UINT16_C( 65535 ), /* FalseActionListIndex */
                UINT8_C( 0 ) /* RuleInitState */
            },
            { /* RuleTable[39] -- BswM_EB_Rule_BswMRule_StartupTwoD */
                UINT16_C( 5 ), /* ID */
                UINT16_C( 1 ), /* LogicalExprIndex */
                UINT16_C( 5 ), /* TrueActionListIndex */
                UINT16_C( 65535 ), /* FalseActionListIndex */
                UINT8_C( 0 ) /* RuleInitState */
            },
            { /* RuleTable[40] -- BswM_EB_Rule_BswMRule_PrepShutdown */
                UINT16_C( 4 ), /* ID */
                UINT16_C( 5 ), /* LogicalExprIndex */
                UINT16_C( 4 ), /* TrueActionListIndex */
                UINT16_C( 65535 ), /* FalseActionListIndex */
                UINT8_C( 0 ) /* RuleInitState */
            },
            { /* RuleTable[41] -- BswM_EB_Rule_BswMRule_GoOffOneD */
                UINT16_C( 3 ), /* ID */
                UINT16_C( 4 ), /* LogicalExprIndex */
                UINT16_C( 3 ), /* TrueActionListIndex */
                UINT16_C( 65535 ), /* FalseActionListIndex */
                UINT8_C( 0 ) /* RuleInitState */
            },
            { /* RuleTable[42] -- BswM_EB_Rule_BswMRule_GoOffOneC */
                UINT16_C( 2 ), /* ID */
                UINT16_C( 3 ), /* LogicalExprIndex */
                UINT16_C( 2 ), /* TrueActionListIndex */
                UINT16_C( 65535 ), /* FalseActionListIndex */
                UINT8_C( 0 ) /* RuleInitState */
            },
            { /* RuleTable[43] -- BswM_EB_Rule_BswMRule_Runtwo */
                UINT16_C( 1 ), /* ID */
                UINT16_C( 2 ), /* LogicalExprIndex */
                UINT16_C( 0 ), /* TrueActionListIndex */
                UINT16_C( 65535 ), /* FalseActionListIndex */
                UINT8_C( 0 ) /* RuleInitState */
            },
            { /* RuleTable[44] -- BswM_EB_Rule_BswMRule_StartupTwoC */
                UINT16_C( 0 ), /* ID */
                UINT16_C( 0 ), /* LogicalExprIndex */
                UINT16_C( 1 ), /* TrueActionListIndex */
                UINT16_C( 65535 ), /* FalseActionListIndex */
                UINT8_C( 0 ) /* RuleInitState */
            }
        },
        { /* RuleDependencyTable */
            UINT16_C( 23 ), /* RuleDependencyTable[0] -- BswM_EB_Rule_BswMRule_StartupTwoA */
            UINT16_C( 22 ), /* RuleDependencyTable[1] -- BswM_EB_Rule_BswMRule_StartupTwoB */
            UINT16_C( 21 ), /* RuleDependencyTable[2] -- BswM_EB_Rule_BswMRule_GoOffOneA */
            UINT16_C( 20 ), /* RuleDependencyTable[3] -- BswM_EB_Rule_BswMRule_GoOffOneB */
            UINT16_C( 19 ), /* RuleDependencyTable[4] -- BswM_EB_Rule_BswMRule_RunTwo */
            UINT16_C( 18 ), /* RuleDependencyTable[5] -- BswM_EB_Rule_BswMRule_PrepShutdown */
            UINT16_C( 22 ), /* RuleDependencyTable[6] -- BswM_EB_Rule_BswMRule_StartupTwoB */
            UINT16_C( 17 ), /* RuleDependencyTable[7] -- BswM_EB_Rule_BswMRule_CanSmNoCom_PublicCan */
            UINT16_C( 16 ), /* RuleDependencyTable[8] -- BswM_EB_Rule_BswMRule_CanSmSilentCom_PublicCan */
            UINT16_C( 15 ), /* RuleDependencyTable[9] -- BswM_EB_Rule_BswMRule_CanSmBusoff_PublicCan */
            UINT16_C( 14 ), /* RuleDependencyTable[10] -- BswM_EB_Rule_BswMRule_CanSmFullCom_PublicCan */
            UINT16_C( 13 ), /* RuleDependencyTable[11] -- BswM_EB_Rule_BswMRule_CanSmFullCom_PrivateCan */
            UINT16_C( 12 ), /* RuleDependencyTable[12] -- BswM_EB_Rule_BswMRule_CanSmSilentCom_PrivateCan */
            UINT16_C( 11 ), /* RuleDependencyTable[13] -- BswM_EB_Rule_BswMRule_CanSmBusoff_PrivateCan */
            UINT16_C( 10 ), /* RuleDependencyTable[14] -- BswM_EB_Rule_BswMRule_CanSmNoCom_PrivateCan */
            UINT16_C( 26 ), /* RuleDependencyTable[15] -- BswM_EB_Rule_BswMRule_WakupValidation_PublicCan */
            UINT16_C( 3 ), /* RuleDependencyTable[16] -- BswM_EB_Rule_BswMRule_Dcm_EcuReset_EXECUTE */
            UINT16_C( 2 ), /* RuleDependencyTable[17] -- BswM_EB_Rule_BswMRule_Dcm_EcuReset_HARD */
            UINT16_C( 1 ), /* RuleDependencyTable[18] -- BswM_EB_Rule_BswMRule_Dcm_EcuReset_SOFT */
            UINT16_C( 0 ), /* RuleDependencyTable[19] -- BswM_EB_Rule_BswMRule_Dcm_EcuReset_JUMPTOSYSSUPPLIERBOOTLOADER */
            UINT16_C( 9 ), /* RuleDependencyTable[20] -- BswM_EB_Rule_BswMRule_Dcm_280301_DisRxTx_Norm */
            UINT16_C( 8 ), /* RuleDependencyTable[21] -- BswM_EB_Rule_BswMRule_Dcm_280001_EnRxTx_Norm */
            UINT16_C( 7 ), /* RuleDependencyTable[22] -- BswM_EB_Rule_BswMRule_Dcm_280302_DisRxTx_NM */
            UINT16_C( 6 ), /* RuleDependencyTable[23] -- BswM_EB_Rule_BswMRule_Dcm_280002_EnRxTx_NM */
            UINT16_C( 5 ), /* RuleDependencyTable[24] -- BswM_EB_Rule_BswMRule_Dcm_280303_DisRxTx_Norm_NM */
            UINT16_C( 4 ), /* RuleDependencyTable[25] -- BswM_EB_Rule_BswMRule_Dcm_280003_EnRxTx_Norm_NM */
            UINT16_C( 25 ), /* RuleDependencyTable[26] -- BswM_EB_Rule_BswMRule_Comco_PduGroupSwitchRxReq */
            UINT16_C( 24 ), /* RuleDependencyTable[27] -- BswM_EB_Rule_BswMRule_Comco_PduGroupSwitchTxReq */
            UINT16_C( 5 ), /* RuleDependencyTable[28] -- BswM_EB_Rule_BswMRule_StartupTwoC */
            UINT16_C( 3 ), /* RuleDependencyTable[29] -- BswM_EB_Rule_BswMRule_RunTwo */
            UINT16_C( 2 ), /* RuleDependencyTable[30] -- BswM_EB_Rule_BswMRule_GoOffOneC */
            UINT16_C( 4 ), /* RuleDependencyTable[31] -- BswM_EB_Rule_BswMRule_StartupTwoD */
            UINT16_C( 1 ), /* RuleDependencyTable[32] -- BswM_EB_Rule_BswMRule_GoOffOneD */
            UINT16_C( 0 ), /* RuleDependencyTable[33] -- BswM_EB_Rule_BswMRule_PrepShutdown */
            UINT16_C( 5 ), /* RuleDependencyTable[34] -- BswM_EB_Rule_BswMRule_StartupTwoC */
            UINT16_C( 4 ), /* RuleDependencyTable[35] -- BswM_EB_Rule_BswMRule_Runtwo */
            UINT16_C( 3 ), /* RuleDependencyTable[36] -- BswM_EB_Rule_BswMRule_GoOffOneC */
            UINT16_C( 2 ), /* RuleDependencyTable[37] -- BswM_EB_Rule_BswMRule_GoOffOneD */
            UINT16_C( 1 ), /* RuleDependencyTable[38] -- BswM_EB_Rule_BswMRule_PrepShutdown */
            UINT16_C( 0 ), /* RuleDependencyTable[39] -- BswM_EB_Rule_BswMRule_StartupTwoD */
            UINT16_C( 5 ), /* RuleDependencyTable[40] -- BswM_EB_Rule_BswMRule_StartupTwoC */
            UINT16_C( 4 ), /* RuleDependencyTable[41] -- BswM_EB_Rule_BswMRule_Runtwo */
            UINT16_C( 3 ), /* RuleDependencyTable[42] -- BswM_EB_Rule_BswMRule_GoOffOneC */
            UINT16_C( 2 ), /* RuleDependencyTable[43] -- BswM_EB_Rule_BswMRule_GoOffOneD */
            UINT16_C( 1 ), /* RuleDependencyTable[44] -- BswM_EB_Rule_BswMRule_PrepShutdown */
            UINT16_C( 0 ) /* RuleDependencyTable[45] -- BswM_EB_Rule_BswMRule_StartupTwoD */
        },
        { /* RuleDependencyListRangeTable */
            { /* RuleDependencyListRangeTable[0] -- BswM_ReqPort */
                UINT16_C( 0 ), /* Head */
                UINT16_C( 6 ) /* Tail */
            },
            { /* RuleDependencyListRangeTable[1] -- CanSm_CurrentStatePort_PublicCan */
                UINT16_C( 6 ), /* Head */
                UINT16_C( 11 ) /* Tail */
            },
            { /* RuleDependencyListRangeTable[2] -- CanSm_CurrentStatePort_PrivateCan */
                UINT16_C( 11 ), /* Head */
                UINT16_C( 15 ) /* Tail */
            },
            { /* RuleDependencyListRangeTable[3] -- EcuM_WakeupValidation_PublicCan */
                UINT16_C( 15 ), /* Head */
                UINT16_C( 16 ) /* Tail */
            },
            { /* RuleDependencyListRangeTable[4] -- BswMBswModeNotification_DcmEcuReset */
                UINT16_C( 16 ), /* Head */
                UINT16_C( 20 ) /* Tail */
            },
            { /* RuleDependencyListRangeTable[5] -- BswMBswModeNotification_DcmCommunicationControl */
                UINT16_C( 20 ), /* Head */
                UINT16_C( 26 ) /* Tail */
            },
            { /* RuleDependencyListRangeTable[6] -- BswMSwcModeNotification_Comco_RxReq */
                UINT16_C( 26 ), /* Head */
                UINT16_C( 27 ) /* Tail */
            },
            { /* RuleDependencyListRangeTable[7] -- BswMSwcModeNotification_Comco_TxReq */
                UINT16_C( 27 ), /* Head */
                UINT16_C( 28 ) /* Tail */
            },
            { /* RuleDependencyListRangeTable[8] -- BswM_ReqPort */
                UINT16_C( 0 ), /* Head */
                UINT16_C( 3 ) /* Tail */
            },
            { /* RuleDependencyListRangeTable[9] -- BswMModeRequestPort_Slave */
                UINT16_C( 3 ), /* Head */
                UINT16_C( 6 ) /* Tail */
            },
            { /* RuleDependencyListRangeTable[10] -- BswM_ReqPort */
                UINT16_C( 0 ), /* Head */
                UINT16_C( 3 ) /* Tail */
            },
            { /* RuleDependencyListRangeTable[11] -- BswMModeRequestPort_Slave */
                UINT16_C( 3 ), /* Head */
                UINT16_C( 6 ) /* Tail */
            },
            { /* RuleDependencyListRangeTable[12] -- BswM_ReqPort */
                UINT16_C( 0 ), /* Head */
                UINT16_C( 3 ) /* Tail */
            },
            { /* RuleDependencyListRangeTable[13] -- BswMModeRequestPort_Slave */
                UINT16_C( 3 ), /* Head */
                UINT16_C( 6 ) /* Tail */
            }
        },
        { /* ActionListTable */
            { /* ActionListTable[0] -- BswM_ActLst_GoOffOneA */
                { /* ActionListItemSegment */
                    UINT16_C( 0 ), /* Head */
                    UINT16_C( 2 ) /* Tail */
                },
                UINT8_C( 0 ) /* IsTriggered */
            },
            { /* ActionListTable[1] -- BswM_ActLst_GoOffOneB */
                { /* ActionListItemSegment */
                    UINT16_C( 2 ), /* Head */
                    UINT16_C( 5 ) /* Tail */
                },
                UINT8_C( 1 ) /* IsTriggered */
            },
            { /* ActionListTable[2] -- BswM_ActLst_RunTwo */
                { /* ActionListItemSegment */
                    UINT16_C( 5 ), /* Head */
                    UINT16_C( 8 ) /* Tail */
                },
                UINT8_C( 1 ) /* IsTriggered */
            },
            { /* ActionListTable[3] -- BswM_ActLst_StartupTwoA */
                { /* ActionListItemSegment */
                    UINT16_C( 8 ), /* Head */
                    UINT16_C( 10 ) /* Tail */
                },
                UINT8_C( 1 ) /* IsTriggered */
            },
            { /* ActionListTable[4] -- BswM_ActLst_StartupTwoB */
                { /* ActionListItemSegment */
                    UINT16_C( 10 ), /* Head */
                    UINT16_C( 14 ) /* Tail */
                },
                UINT8_C( 1 ) /* IsTriggered */
            },
            { /* ActionListTable[5] -- BswM_ActLst_CanNoCom_PublicCan */
                { /* ActionListItemSegment */
                    UINT16_C( 14 ), /* Head */
                    UINT16_C( 16 ) /* Tail */
                },
                UINT8_C( 1 ) /* IsTriggered */
            },
            { /* ActionListTable[6] -- BswM_ActLst_CanSilentCom_PublicCan */
                { /* ActionListItemSegment */
                    UINT16_C( 16 ), /* Head */
                    UINT16_C( 18 ) /* Tail */
                },
                UINT8_C( 1 ) /* IsTriggered */
            },
            { /* ActionListTable[7] -- BswM_ActLst_CanBusoff_PublicCan */
                { /* ActionListItemSegment */
                    UINT16_C( 18 ), /* Head */
                    UINT16_C( 20 ) /* Tail */
                },
                UINT8_C( 1 ) /* IsTriggered */
            },
            { /* ActionListTable[8] -- BswM_ActLst_CanFullCom_PublicCan */
                { /* ActionListItemSegment */
                    UINT16_C( 20 ), /* Head */
                    UINT16_C( 22 ) /* Tail */
                },
                UINT8_C( 1 ) /* IsTriggered */
            },
            { /* ActionListTable[9] -- BswM_ActLst_PrpShutdown */
                { /* ActionListItemSegment */
                    UINT16_C( 22 ), /* Head */
                    UINT16_C( 25 ) /* Tail */
                },
                UINT8_C( 1 ) /* IsTriggered */
            },
            { /* ActionListTable[10] -- BswM_ActLst_CanNoCom_PrivateCan */
                { /* ActionListItemSegment */
                    UINT16_C( 25 ), /* Head */
                    UINT16_C( 27 ) /* Tail */
                },
                UINT8_C( 1 ) /* IsTriggered */
            },
            { /* ActionListTable[11] -- BswM_ActLst_CanSilentCom_PrivateCan */
                { /* ActionListItemSegment */
                    UINT16_C( 27 ), /* Head */
                    UINT16_C( 29 ) /* Tail */
                },
                UINT8_C( 1 ) /* IsTriggered */
            },
            { /* ActionListTable[12] -- BswM_ActLst_CanBusoff_PrivateCan */
                { /* ActionListItemSegment */
                    UINT16_C( 29 ), /* Head */
                    UINT16_C( 30 ) /* Tail */
                },
                UINT8_C( 1 ) /* IsTriggered */
            },
            { /* ActionListTable[13] -- BswM_ActLst_CanFullCom_PrivateCan */
                { /* ActionListItemSegment */
                    UINT16_C( 30 ), /* Head */
                    UINT16_C( 32 ) /* Tail */
                },
                UINT8_C( 1 ) /* IsTriggered */
            },
            { /* ActionListTable[14] -- BswM_ActLst_WakupValidation_PublicCan */
                { /* ActionListItemSegment */
                    UINT16_C( 32 ), /* Head */
                    UINT16_C( 33 ) /* Tail */
                },
                UINT8_C( 1 ) /* IsTriggered */
            },
            { /* ActionListTable[15] -- BswM_ActLst_Dcm_280301_DisRxTx_Norm */
                { /* ActionListItemSegment */
                    UINT16_C( 33 ), /* Head */
                    UINT16_C( 35 ) /* Tail */
                },
                UINT8_C( 1 ) /* IsTriggered */
            },
            { /* ActionListTable[16] -- BswM_ActLst_Dcm_280001_EnRxTx_Norm */
                { /* ActionListItemSegment */
                    UINT16_C( 35 ), /* Head */
                    UINT16_C( 37 ) /* Tail */
                },
                UINT8_C( 1 ) /* IsTriggered */
            },
            { /* ActionListTable[17] -- BswM_ActLst_Dcm_280302_DisRxTx_NM */
                { /* ActionListItemSegment */
                    UINT16_C( 37 ), /* Head */
                    UINT16_C( 39 ) /* Tail */
                },
                UINT8_C( 1 ) /* IsTriggered */
            },
            { /* ActionListTable[18] -- BswM_ActLst_Dcm_280002_EnRxTx_NM */
                { /* ActionListItemSegment */
                    UINT16_C( 39 ), /* Head */
                    UINT16_C( 41 ) /* Tail */
                },
                UINT8_C( 1 ) /* IsTriggered */
            },
            { /* ActionListTable[19] -- BswM_ActLst_Dcm_280303_DisRxTx_Norm_NM */
                { /* ActionListItemSegment */
                    UINT16_C( 41 ), /* Head */
                    UINT16_C( 44 ) /* Tail */
                },
                UINT8_C( 1 ) /* IsTriggered */
            },
            { /* ActionListTable[20] -- BswM_ActLst_Dcm_280003_EnRxTx_Norm_NM */
                { /* ActionListItemSegment */
                    UINT16_C( 44 ), /* Head */
                    UINT16_C( 47 ) /* Tail */
                },
                UINT8_C( 1 ) /* IsTriggered */
            },
            { /* ActionListTable[21] -- BswM_ActLst_Comco_Pdu_RxGroup_Active */
                { /* ActionListItemSegment */
                    UINT16_C( 47 ), /* Head */
                    UINT16_C( 48 ) /* Tail */
                },
                UINT8_C( 1 ) /* IsTriggered */
            },
            { /* ActionListTable[22] -- BswM_ActLst_Comco_Pdu_RxGroup_InActive */
                { /* ActionListItemSegment */
                    UINT16_C( 48 ), /* Head */
                    UINT16_C( 49 ) /* Tail */
                },
                UINT8_C( 1 ) /* IsTriggered */
            },
            { /* ActionListTable[23] -- BswM_ActLst_Comco_Pdu_TxGroup_Active */
                { /* ActionListItemSegment */
                    UINT16_C( 49 ), /* Head */
                    UINT16_C( 50 ) /* Tail */
                },
                UINT8_C( 1 ) /* IsTriggered */
            },
            { /* ActionListTable[24] -- BswM_ActLst_Comco_Pdu_TxGroup_InActive */
                { /* ActionListItemSegment */
                    UINT16_C( 50 ), /* Head */
                    UINT16_C( 51 ) /* Tail */
                },
                UINT8_C( 1 ) /* IsTriggered */
            },
            { /* ActionListTable[25] -- BswM_ActLst_Dcm_EcuReset_EXECUTE */
                { /* ActionListItemSegment */
                    UINT16_C( 51 ), /* Head */
                    UINT16_C( 52 ) /* Tail */
                },
                UINT8_C( 1 ) /* IsTriggered */
            },
            { /* ActionListTable[26] -- BswM_ActLst_Dcm_EcuReset_HARD */
                { /* ActionListItemSegment */
                    UINT16_C( 52 ), /* Head */
                    UINT16_C( 53 ) /* Tail */
                },
                UINT8_C( 1 ) /* IsTriggered */
            },
            { /* ActionListTable[27] -- BswM_ActLst_Dcm_EcuReset_SOFT */
                { /* ActionListItemSegment */
                    UINT16_C( 53 ), /* Head */
                    UINT16_C( 54 ) /* Tail */
                },
                UINT8_C( 1 ) /* IsTriggered */
            },
            { /* ActionListTable[28] -- BswM_ActLst_Dcm_EcuReset_JUMPTOSYSSUPPLIERBOOTLOADER */
                { /* ActionListItemSegment */
                    UINT16_C( 54 ), /* Head */
                    UINT16_C( 55 ) /* Tail */
                },
                UINT8_C( 1 ) /* IsTriggered */
            },
            { /* ActionListTable[29] -- BswM_ActLst_RunTwo */
                { /* ActionListItemSegment */
                    UINT16_C( 0 ), /* Head */
                    UINT16_C( 1 ) /* Tail */
                },
                UINT8_C( 1 ) /* IsTriggered */
            },
            { /* ActionListTable[30] -- BswM_ActLst_StartupTwoC */
                { /* ActionListItemSegment */
                    UINT16_C( 1 ), /* Head */
                    UINT16_C( 2 ) /* Tail */
                },
                UINT8_C( 1 ) /* IsTriggered */
            },
            { /* ActionListTable[31] -- BswM_ActLst_StartupTwoD */
                { /* ActionListItemSegment */
                    UINT16_C( 2 ), /* Head */
                    UINT16_C( 3 ) /* Tail */
                },
                UINT8_C( 1 ) /* IsTriggered */
            },
            { /* ActionListTable[32] -- BswM_ActLst_GoOffOneC */
                { /* ActionListItemSegment */
                    UINT16_C( 3 ), /* Head */
                    UINT16_C( 4 ) /* Tail */
                },
                UINT8_C( 1 ) /* IsTriggered */
            },
            { /* ActionListTable[33] -- BswM_ActLst_GoOffOneD */
                { /* ActionListItemSegment */
                    UINT16_C( 4 ), /* Head */
                    UINT16_C( 5 ) /* Tail */
                },
                UINT8_C( 1 ) /* IsTriggered */
            },
            { /* ActionListTable[34] -- BswM_ActLst_PrepShutdown */
                { /* ActionListItemSegment */
                    UINT16_C( 5 ), /* Head */
                    UINT16_C( 6 ) /* Tail */
                },
                UINT8_C( 1 ) /* IsTriggered */
            },
            { /* ActionListTable[35] -- BswM_ActLst_RunTwo */
                { /* ActionListItemSegment */
                    UINT16_C( 0 ), /* Head */
                    UINT16_C( 1 ) /* Tail */
                },
                UINT8_C( 1 ) /* IsTriggered */
            },
            { /* ActionListTable[36] -- BswM_ActLst_StartupTwoC */
                { /* ActionListItemSegment */
                    UINT16_C( 1 ), /* Head */
                    UINT16_C( 2 ) /* Tail */
                },
                UINT8_C( 1 ) /* IsTriggered */
            },
            { /* ActionListTable[37] -- BswM_ActLst_GoOffOneC */
                { /* ActionListItemSegment */
                    UINT16_C( 2 ), /* Head */
                    UINT16_C( 3 ) /* Tail */
                },
                UINT8_C( 1 ) /* IsTriggered */
            },
            { /* ActionListTable[38] -- BswM_ActLst_GoOffOneD */
                { /* ActionListItemSegment */
                    UINT16_C( 3 ), /* Head */
                    UINT16_C( 4 ) /* Tail */
                },
                UINT8_C( 1 ) /* IsTriggered */
            },
            { /* ActionListTable[39] -- BswM_ActLst_PrepShutdown */
                { /* ActionListItemSegment */
                    UINT16_C( 4 ), /* Head */
                    UINT16_C( 5 ) /* Tail */
                },
                UINT8_C( 1 ) /* IsTriggered */
            },
            { /* ActionListTable[40] -- BswM_ActLst_StartupTwoD */
                { /* ActionListItemSegment */
                    UINT16_C( 5 ), /* Head */
                    UINT16_C( 6 ) /* Tail */
                },
                UINT8_C( 1 ) /* IsTriggered */
            },
            { /* ActionListTable[41] -- BswM_ActLst_RunTwo */
                { /* ActionListItemSegment */
                    UINT16_C( 0 ), /* Head */
                    UINT16_C( 1 ) /* Tail */
                },
                UINT8_C( 1 ) /* IsTriggered */
            },
            { /* ActionListTable[42] -- BswM_ActLst_StartupTwoC */
                { /* ActionListItemSegment */
                    UINT16_C( 1 ), /* Head */
                    UINT16_C( 2 ) /* Tail */
                },
                UINT8_C( 1 ) /* IsTriggered */
            },
            { /* ActionListTable[43] -- BswM_ActLst_GoOffOneC */
                { /* ActionListItemSegment */
                    UINT16_C( 2 ), /* Head */
                    UINT16_C( 3 ) /* Tail */
                },
                UINT8_C( 1 ) /* IsTriggered */
            },
            { /* ActionListTable[44] -- BswM_ActLst_GoOffOneD */
                { /* ActionListItemSegment */
                    UINT16_C( 3 ), /* Head */
                    UINT16_C( 4 ) /* Tail */
                },
                UINT8_C( 1 ) /* IsTriggered */
            },
            { /* ActionListTable[45] -- BswM_ActLst_PrepShutdown */
                { /* ActionListItemSegment */
                    UINT16_C( 4 ), /* Head */
                    UINT16_C( 5 ) /* Tail */
                },
                UINT8_C( 1 ) /* IsTriggered */
            },
            { /* ActionListTable[46] -- BswM_ActLst_StartupTwoD */
                { /* ActionListItemSegment */
                    UINT16_C( 5 ), /* Head */
                    UINT16_C( 6 ) /* Tail */
                },
                UINT8_C( 1 ) /* IsTriggered */
            }
        },
        { /* ActionListItemTable */
            { /* ActionListItemTable[0] */
                UINT16_C( 6 ), /* ArtifactIndex -- BswM_Act_RteSwitch_GoOffOneA */
                UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
                UINT8_C( 0 ), /* IsAbortOnFail */
                UINT8_C( 0 ) /* ActionType */
            },
            { /* ActionListItemTable[1] */
                UINT16_C( 4 ), /* ArtifactIndex -- BswM_Act_GoOffOneA */
                UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
                UINT8_C( 0 ), /* IsAbortOnFail */
                UINT8_C( 0 ) /* ActionType */
            },
            { /* ActionListItemTable[2] */
                UINT16_C( 7 ), /* ArtifactIndex -- BswM_Act_RteSwitch_GoOffOneB */
                UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
                UINT8_C( 0 ), /* IsAbortOnFail */
                UINT8_C( 0 ) /* ActionType */
            },
            { /* ActionListItemTable[3] */
                UINT16_C( 21 ), /* ArtifactIndex -- BswM_Act_GO_OFF_ONE_D */
                UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
                UINT8_C( 0 ), /* IsAbortOnFail */
                UINT8_C( 0 ) /* ActionType */
            },
            { /* ActionListItemTable[4] */
                UINT16_C( 5 ), /* ArtifactIndex -- BswM_Act_GoOffOneB */
                UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
                UINT8_C( 0 ), /* IsAbortOnFail */
                UINT8_C( 0 ) /* ActionType */
            },
            { /* ActionListItemTable[5] */
                UINT16_C( 2 ), /* ArtifactIndex -- BswM_Act_RunTwo */
                UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
                UINT8_C( 0 ), /* IsAbortOnFail */
                UINT8_C( 0 ) /* ActionType */
            },
            { /* ActionListItemTable[6] */
                UINT16_C( 8 ), /* ArtifactIndex -- BswM_Act_RteSwitch_RunTwo */
                UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
                UINT8_C( 0 ), /* IsAbortOnFail */
                UINT8_C( 0 ) /* ActionType */
            },
            { /* ActionListItemTable[7] */
                UINT16_C( 26 ), /* ArtifactIndex -- Act_UserCallout_Comco_Init */
                UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
                UINT8_C( 0 ), /* IsAbortOnFail */
                UINT8_C( 0 ) /* ActionType */
            },
            { /* ActionListItemTable[8] */
                UINT16_C( 0 ), /* ArtifactIndex -- BswM_Act_StartupTwoA */
                UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
                UINT8_C( 0 ), /* IsAbortOnFail */
                UINT8_C( 0 ) /* ActionType */
            },
            { /* ActionListItemTable[9] */
                UINT16_C( 9 ), /* ArtifactIndex -- BswM_Act_RteSwitch_StartupTwoA */
                UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
                UINT8_C( 0 ), /* IsAbortOnFail */
                UINT8_C( 0 ) /* ActionType */
            },
            { /* ActionListItemTable[10] */
                UINT16_C( 1 ), /* ArtifactIndex -- BswM_Act_StartupTwoB */
                UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
                UINT8_C( 0 ), /* IsAbortOnFail */
                UINT8_C( 0 ) /* ActionType */
            },
            { /* ActionListItemTable[11] */
                UINT16_C( 20 ), /* ArtifactIndex -- BswM_Act_STARTUP_TWO_D */
                UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
                UINT8_C( 0 ), /* IsAbortOnFail */
                UINT8_C( 0 ) /* ActionType */
            },
            { /* ActionListItemTable[12] */
                UINT16_C( 3 ), /* ArtifactIndex -- BswM_Act_RequestRunTwo */
                UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
                UINT8_C( 0 ), /* IsAbortOnFail */
                UINT8_C( 0 ) /* ActionType */
            },
            { /* ActionListItemTable[13] */
                UINT16_C( 10 ), /* ArtifactIndex -- BswM_Act_RteSwitch_StartupTwoB */
                UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
                UINT8_C( 0 ), /* IsAbortOnFail */
                UINT8_C( 0 ) /* ActionType */
            },
            { /* ActionListItemTable[14] */
                UINT16_C( 11 ), /* ArtifactIndex -- BswM_Act_CanNoComPublicCan */
                UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
                UINT8_C( 0 ), /* IsAbortOnFail */
                UINT8_C( 1 ) /* ActionType */
            },
            { /* ActionListItemTable[15] */
                UINT16_C( 38 ), /* ArtifactIndex -- Act_RteSwitch_CanSMStatePublic_NoCom */
                UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
                UINT8_C( 0 ), /* IsAbortOnFail */
                UINT8_C( 0 ) /* ActionType */
            },
            { /* ActionListItemTable[16] */
                UINT16_C( 12 ), /* ArtifactIndex -- BswM_Act_CanSilentComPublicCan */
                UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
                UINT8_C( 0 ), /* IsAbortOnFail */
                UINT8_C( 1 ) /* ActionType */
            },
            { /* ActionListItemTable[17] */
                UINT16_C( 37 ), /* ArtifactIndex -- Act_RteSwitch_CanSMStatePublic_SlientCom */
                UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
                UINT8_C( 0 ), /* IsAbortOnFail */
                UINT8_C( 0 ) /* ActionType */
            },
            { /* ActionListItemTable[18] */
                UINT16_C( 35 ), /* ArtifactIndex -- Act_RteSwitch_CanSMStatePublic_Busoff */
                UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
                UINT8_C( 0 ), /* IsAbortOnFail */
                UINT8_C( 0 ) /* ActionType */
            },
            { /* ActionListItemTable[19] */
                UINT16_C( 50 ), /* ArtifactIndex -- Act_PublicCAN_BusOff_Recorvery_Tja1043 */
                UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
                UINT8_C( 0 ), /* IsAbortOnFail */
                UINT8_C( 0 ) /* ActionType */
            },
            { /* ActionListItemTable[20] */
                UINT16_C( 13 ), /* ArtifactIndex -- BswM_Act_CanFullComPublicCan */
                UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
                UINT8_C( 0 ), /* IsAbortOnFail */
                UINT8_C( 1 ) /* ActionType */
            },
            { /* ActionListItemTable[21] */
                UINT16_C( 36 ), /* ArtifactIndex -- Act_RteSwitch_CanSMStatePublic_FullCom */
                UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
                UINT8_C( 0 ), /* IsAbortOnFail */
                UINT8_C( 0 ) /* ActionType */
            },
            { /* ActionListItemTable[22] */
                UINT16_C( 15 ), /* ArtifactIndex -- BswM_Act_RteSwitch_PrpShutdown */
                UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
                UINT8_C( 0 ), /* IsAbortOnFail */
                UINT8_C( 0 ) /* ActionType */
            },
            { /* ActionListItemTable[23] */
                UINT16_C( 14 ), /* ArtifactIndex -- BswM_Act_PrepShutdown */
                UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
                UINT8_C( 0 ), /* IsAbortOnFail */
                UINT8_C( 0 ) /* ActionType */
            },
            { /* ActionListItemTable[24] */
                UINT16_C( 43 ), /* ArtifactIndex -- BswM_Act_PrepShutdown_C1 */
                UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
                UINT8_C( 0 ), /* IsAbortOnFail */
                UINT8_C( 0 ) /* ActionType */
            },
            { /* ActionListItemTable[25] */
                UINT16_C( 16 ), /* ArtifactIndex -- BswM_Act_CanNoComPrivateCan */
                UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
                UINT8_C( 0 ), /* IsAbortOnFail */
                UINT8_C( 1 ) /* ActionType */
            },
            { /* ActionListItemTable[26] */
                UINT16_C( 42 ), /* ArtifactIndex -- Act_RteSwitch_CanSMStatePrivate_NoCom */
                UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
                UINT8_C( 0 ), /* IsAbortOnFail */
                UINT8_C( 0 ) /* ActionType */
            },
            { /* ActionListItemTable[27] */
                UINT16_C( 17 ), /* ArtifactIndex -- BswM_Act_CanSilentComPrivateCan */
                UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
                UINT8_C( 0 ), /* IsAbortOnFail */
                UINT8_C( 1 ) /* ActionType */
            },
            { /* ActionListItemTable[28] */
                UINT16_C( 41 ), /* ArtifactIndex -- Act_RteSwitch_CanSMStatePrivate_SlientCom */
                UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
                UINT8_C( 0 ), /* IsAbortOnFail */
                UINT8_C( 0 ) /* ActionType */
            },
            { /* ActionListItemTable[29] */
                UINT16_C( 39 ), /* ArtifactIndex -- Act_RteSwitch_CanSMStatePrivate_Busoff */
                UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
                UINT8_C( 0 ), /* IsAbortOnFail */
                UINT8_C( 0 ) /* ActionType */
            },
            { /* ActionListItemTable[30] */
                UINT16_C( 18 ), /* ArtifactIndex -- BswM_Act_CanFullComPrivateCan */
                UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
                UINT8_C( 0 ), /* IsAbortOnFail */
                UINT8_C( 1 ) /* ActionType */
            },
            { /* ActionListItemTable[31] */
                UINT16_C( 40 ), /* ArtifactIndex -- Act_RteSwitch_CanSMStatePrivate_FullCom */
                UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
                UINT8_C( 0 ), /* IsAbortOnFail */
                UINT8_C( 0 ) /* ActionType */
            },
            { /* ActionListItemTable[32] */
                UINT16_C( 19 ), /* ArtifactIndex -- BswMAction_WakupValidation_PublicCan */
                UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
                UINT8_C( 0 ), /* IsAbortOnFail */
                UINT8_C( 0 ) /* ActionType */
            },
            { /* ActionListItemTable[33] */
                UINT16_C( 22 ), /* ArtifactIndex -- Act_Dcm_0x280301_DisRxTx_Norm */
                UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
                UINT8_C( 0 ), /* IsAbortOnFail */
                UINT8_C( 1 ) /* ActionType */
            },
            { /* ActionListItemTable[34] */
                UINT16_C( 44 ), /* ArtifactIndex -- Act_RteSwitch_DiagComControl_DisRxTxNorM */
                UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
                UINT8_C( 1 ), /* IsAbortOnFail */
                UINT8_C( 0 ) /* ActionType */
            },
            { /* ActionListItemTable[35] */
                UINT16_C( 23 ), /* ArtifactIndex -- Act_Dcm_0x280001_EnRxTx_Norm */
                UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
                UINT8_C( 0 ), /* IsAbortOnFail */
                UINT8_C( 1 ) /* ActionType */
            },
            { /* ActionListItemTable[36] */
                UINT16_C( 45 ), /* ArtifactIndex -- Act_RteSwitch_DiagComControl_EnRxTxNorM */
                UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
                UINT8_C( 0 ), /* IsAbortOnFail */
                UINT8_C( 0 ) /* ActionType */
            },
            { /* ActionListItemTable[37] */
                UINT16_C( 24 ), /* ArtifactIndex -- Act_Dcm_0x280302_DisRxTx_NM */
                UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
                UINT8_C( 0 ), /* IsAbortOnFail */
                UINT8_C( 0 ) /* ActionType */
            },
            { /* ActionListItemTable[38] */
                UINT16_C( 47 ), /* ArtifactIndex -- Act_RteSwitch_DiagComControl_DisRxTxNM */
                UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
                UINT8_C( 0 ), /* IsAbortOnFail */
                UINT8_C( 0 ) /* ActionType */
            },
            { /* ActionListItemTable[39] */
                UINT16_C( 25 ), /* ArtifactIndex -- Act_Dcm_0x280002_EnRxTx_NM */
                UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
                UINT8_C( 0 ), /* IsAbortOnFail */
                UINT8_C( 0 ) /* ActionType */
            },
            { /* ActionListItemTable[40] */
                UINT16_C( 46 ), /* ArtifactIndex -- Act_RteSwitch_DiagComControl_EnRxTxNM */
                UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
                UINT8_C( 0 ), /* IsAbortOnFail */
                UINT8_C( 0 ) /* ActionType */
            },
            { /* ActionListItemTable[41] */
                UINT16_C( 22 ), /* ArtifactIndex -- Act_Dcm_0x280301_DisRxTx_Norm */
                UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
                UINT8_C( 0 ), /* IsAbortOnFail */
                UINT8_C( 1 ) /* ActionType */
            },
            { /* ActionListItemTable[42] */
                UINT16_C( 24 ), /* ArtifactIndex -- Act_Dcm_0x280302_DisRxTx_NM */
                UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
                UINT8_C( 0 ), /* IsAbortOnFail */
                UINT8_C( 0 ) /* ActionType */
            },
            { /* ActionListItemTable[43] */
                UINT16_C( 49 ), /* ArtifactIndex -- Act_RteSwitch_DiagComControl_DisRxTxNorM_NM */
                UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
                UINT8_C( 0 ), /* IsAbortOnFail */
                UINT8_C( 0 ) /* ActionType */
            },
            { /* ActionListItemTable[44] */
                UINT16_C( 23 ), /* ArtifactIndex -- Act_Dcm_0x280001_EnRxTx_Norm */
                UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
                UINT8_C( 0 ), /* IsAbortOnFail */
                UINT8_C( 1 ) /* ActionType */
            },
            { /* ActionListItemTable[45] */
                UINT16_C( 25 ), /* ArtifactIndex -- Act_Dcm_0x280002_EnRxTx_NM */
                UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
                UINT8_C( 0 ), /* IsAbortOnFail */
                UINT8_C( 0 ) /* ActionType */
            },
            { /* ActionListItemTable[46] */
                UINT16_C( 48 ), /* ArtifactIndex -- Act_RteSwitch_DiagComControl_EnRxTxNorM_NM */
                UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
                UINT8_C( 0 ), /* IsAbortOnFail */
                UINT8_C( 0 ) /* ActionType */
            },
            { /* ActionListItemTable[47] */
                UINT16_C( 27 ), /* ArtifactIndex -- Act_Comco_Pdu_RxGroup_Active */
                UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
                UINT8_C( 0 ), /* IsAbortOnFail */
                UINT8_C( 1 ) /* ActionType */
            },
            { /* ActionListItemTable[48] */
                UINT16_C( 28 ), /* ArtifactIndex -- Act_Comco_Pdu_RxGroup_InActive */
                UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
                UINT8_C( 0 ), /* IsAbortOnFail */
                UINT8_C( 1 ) /* ActionType */
            },
            { /* ActionListItemTable[49] */
                UINT16_C( 29 ), /* ArtifactIndex -- Act_Comco_Pdu_TxGroup_Active */
                UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
                UINT8_C( 0 ), /* IsAbortOnFail */
                UINT8_C( 1 ) /* ActionType */
            },
            { /* ActionListItemTable[50] */
                UINT16_C( 30 ), /* ArtifactIndex -- Act_Comco_Pdu_TxGroup_InActive */
                UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
                UINT8_C( 0 ), /* IsAbortOnFail */
                UINT8_C( 1 ) /* ActionType */
            },
            { /* ActionListItemTable[51] */
                UINT16_C( 31 ), /* ArtifactIndex -- Act_Dcm_EcuReset_EXECUTE */
                UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
                UINT8_C( 0 ), /* IsAbortOnFail */
                UINT8_C( 0 ) /* ActionType */
            },
            { /* ActionListItemTable[52] */
                UINT16_C( 32 ), /* ArtifactIndex -- Act_Dcm_EcuReset_HARD */
                UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
                UINT8_C( 0 ), /* IsAbortOnFail */
                UINT8_C( 0 ) /* ActionType */
            },
            { /* ActionListItemTable[53] */
                UINT16_C( 33 ), /* ArtifactIndex -- Act_Dcm_EcuReset_SOFT */
                UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
                UINT8_C( 0 ), /* IsAbortOnFail */
                UINT8_C( 0 ) /* ActionType */
            },
            { /* ActionListItemTable[54] */
                UINT16_C( 34 ), /* ArtifactIndex -- Act_Dcm_EcuReset_JUMPTOSYSSUPPLIERBOOTLOADER */
                UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
                UINT8_C( 0 ), /* IsAbortOnFail */
                UINT8_C( 0 ) /* ActionType */
            },
            { /* ActionListItemTable[55] */
                UINT16_C( 2 ), /* ArtifactIndex -- BswM_Act_RunTwo */
                UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
                UINT8_C( 0 ), /* IsAbortOnFail */
                UINT8_C( 0 ) /* ActionType */
            },
            { /* ActionListItemTable[56] */
                UINT16_C( 0 ), /* ArtifactIndex -- BswM_Act_StartupTwoC */
                UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
                UINT8_C( 0 ), /* IsAbortOnFail */
                UINT8_C( 0 ) /* ActionType */
            },
            { /* ActionListItemTable[57] */
                UINT16_C( 1 ), /* ArtifactIndex -- BswM_Act_StartupTwoD */
                UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
                UINT8_C( 0 ), /* IsAbortOnFail */
                UINT8_C( 0 ) /* ActionType */
            },
            { /* ActionListItemTable[58] */
                UINT16_C( 3 ), /* ArtifactIndex -- BswM_Act_GoOffOneC */
                UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
                UINT8_C( 0 ), /* IsAbortOnFail */
                UINT8_C( 0 ) /* ActionType */
            },
            { /* ActionListItemTable[59] */
                UINT16_C( 4 ), /* ArtifactIndex -- BswM_Act_GoOffOneD */
                UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
                UINT8_C( 0 ), /* IsAbortOnFail */
                UINT8_C( 0 ) /* ActionType */
            },
            { /* ActionListItemTable[60] */
                UINT16_C( 5 ), /* ArtifactIndex -- BswM_Act_PrepShutdown */
                UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
                UINT8_C( 0 ), /* IsAbortOnFail */
                UINT8_C( 0 ) /* ActionType */
            },
            { /* ActionListItemTable[61] */
                UINT16_C( 1 ), /* ArtifactIndex -- BswM_Act_RunTwo */
                UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
                UINT8_C( 0 ), /* IsAbortOnFail */
                UINT8_C( 0 ) /* ActionType */
            },
            { /* ActionListItemTable[62] */
                UINT16_C( 0 ), /* ArtifactIndex -- BswM_Act_StartupTwoC */
                UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
                UINT8_C( 0 ), /* IsAbortOnFail */
                UINT8_C( 0 ) /* ActionType */
            },
            { /* ActionListItemTable[63] */
                UINT16_C( 2 ), /* ArtifactIndex -- BswM_Act_GoOffOneC */
                UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
                UINT8_C( 0 ), /* IsAbortOnFail */
                UINT8_C( 0 ) /* ActionType */
            },
            { /* ActionListItemTable[64] */
                UINT16_C( 3 ), /* ArtifactIndex -- BswM_Act_GoOffOneD */
                UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
                UINT8_C( 0 ), /* IsAbortOnFail */
                UINT8_C( 0 ) /* ActionType */
            },
            { /* ActionListItemTable[65] */
                UINT16_C( 4 ), /* ArtifactIndex -- BswM_Act_PrepShutdown */
                UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
                UINT8_C( 0 ), /* IsAbortOnFail */
                UINT8_C( 0 ) /* ActionType */
            },
            { /* ActionListItemTable[66] */
                UINT16_C( 5 ), /* ArtifactIndex -- BswM_Act_StartupTwoD */
                UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
                UINT8_C( 0 ), /* IsAbortOnFail */
                UINT8_C( 0 ) /* ActionType */
            },
            { /* ActionListItemTable[67] */
                UINT16_C( 1 ), /* ArtifactIndex -- BswM_Act_RunTwo */
                UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
                UINT8_C( 0 ), /* IsAbortOnFail */
                UINT8_C( 0 ) /* ActionType */
            },
            { /* ActionListItemTable[68] */
                UINT16_C( 0 ), /* ArtifactIndex -- BswM_Act_StartupTwoC */
                UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
                UINT8_C( 0 ), /* IsAbortOnFail */
                UINT8_C( 0 ) /* ActionType */
            },
            { /* ActionListItemTable[69] */
                UINT16_C( 2 ), /* ArtifactIndex -- BswM_Act_GoOffOneC */
                UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
                UINT8_C( 0 ), /* IsAbortOnFail */
                UINT8_C( 0 ) /* ActionType */
            },
            { /* ActionListItemTable[70] */
                UINT16_C( 3 ), /* ArtifactIndex -- BswM_Act_GoOffOneD */
                UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
                UINT8_C( 0 ), /* IsAbortOnFail */
                UINT8_C( 0 ) /* ActionType */
            },
            { /* ActionListItemTable[71] */
                UINT16_C( 4 ), /* ArtifactIndex -- BswM_Act_PrepShutdown */
                UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
                UINT8_C( 0 ), /* IsAbortOnFail */
                UINT8_C( 0 ) /* ActionType */
            },
            { /* ActionListItemTable[72] */
                UINT16_C( 5 ), /* ArtifactIndex -- BswM_Act_StartupTwoD */
                UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
                UINT8_C( 0 ), /* IsAbortOnFail */
                UINT8_C( 0 ) /* ActionType */
            }
        },
        { /* PduGroupSwitchActionTable */
            { /* PduGroupSwitchActionTable[0] */
                { /* EnableMask */
                    UINT8_C( 0 ), /* EnableMask[0] */
                    UINT8_C( 0 ), /* EnableMask[1] */
                    UINT8_C( 0 ), /* EnableMask[2] */
                    UINT8_C( 0 ) /* EnableMask[3] */
                },
                { /* DisableMask */
                    UINT8_C( 252 ), /* DisableMask[0] */
                    UINT8_C( 255 ), /* DisableMask[1] */
                    UINT8_C( 255 ), /* DisableMask[2] */
                    UINT8_C( 255 ) /* DisableMask[3] */
                },
                UINT8_C( 0 ) /* RequestInit */
            },
            { /* PduGroupSwitchActionTable[1] */
                { /* EnableMask */
                    UINT8_C( 4 ), /* EnableMask[0] */
                    UINT8_C( 0 ), /* EnableMask[1] */
                    UINT8_C( 0 ), /* EnableMask[2] */
                    UINT8_C( 0 ) /* EnableMask[3] */
                },
                { /* DisableMask */
                    UINT8_C( 254 ), /* DisableMask[0] */
                    UINT8_C( 255 ), /* DisableMask[1] */
                    UINT8_C( 255 ), /* DisableMask[2] */
                    UINT8_C( 255 ) /* DisableMask[3] */
                },
                UINT8_C( 0 ) /* RequestInit */
            },
            { /* PduGroupSwitchActionTable[2] */
                { /* EnableMask */
                    UINT8_C( 3 ), /* EnableMask[0] */
                    UINT8_C( 0 ), /* EnableMask[1] */
                    UINT8_C( 0 ), /* EnableMask[2] */
                    UINT8_C( 0 ) /* EnableMask[3] */
                },
                { /* DisableMask */
                    UINT8_C( 255 ), /* DisableMask[0] */
                    UINT8_C( 255 ), /* DisableMask[1] */
                    UINT8_C( 255 ), /* DisableMask[2] */
                    UINT8_C( 255 ) /* DisableMask[3] */
                },
                UINT8_C( 0 ) /* RequestInit */
            },
            { /* PduGroupSwitchActionTable[3] */
                { /* EnableMask */
                    UINT8_C( 0 ), /* EnableMask[0] */
                    UINT8_C( 0 ), /* EnableMask[1] */
                    UINT8_C( 0 ), /* EnableMask[2] */
                    UINT8_C( 0 ) /* EnableMask[3] */
                },
                { /* DisableMask */
                    UINT8_C( 243 ), /* DisableMask[0] */
                    UINT8_C( 255 ), /* DisableMask[1] */
                    UINT8_C( 255 ), /* DisableMask[2] */
                    UINT8_C( 255 ) /* DisableMask[3] */
                },
                UINT8_C( 0 ) /* RequestInit */
            },
            { /* PduGroupSwitchActionTable[4] */
                { /* EnableMask */
                    UINT8_C( 4 ), /* EnableMask[0] */
                    UINT8_C( 0 ), /* EnableMask[1] */
                    UINT8_C( 0 ), /* EnableMask[2] */
                    UINT8_C( 0 ) /* EnableMask[3] */
                },
                { /* DisableMask */
                    UINT8_C( 247 ), /* DisableMask[0] */
                    UINT8_C( 255 ), /* DisableMask[1] */
                    UINT8_C( 255 ), /* DisableMask[2] */
                    UINT8_C( 255 ) /* DisableMask[3] */
                },
                UINT8_C( 0 ) /* RequestInit */
            },
            { /* PduGroupSwitchActionTable[5] */
                { /* EnableMask */
                    UINT8_C( 12 ), /* EnableMask[0] */
                    UINT8_C( 0 ), /* EnableMask[1] */
                    UINT8_C( 0 ), /* EnableMask[2] */
                    UINT8_C( 0 ) /* EnableMask[3] */
                },
                { /* DisableMask */
                    UINT8_C( 255 ), /* DisableMask[0] */
                    UINT8_C( 255 ), /* DisableMask[1] */
                    UINT8_C( 255 ), /* DisableMask[2] */
                    UINT8_C( 255 ) /* DisableMask[3] */
                },
                UINT8_C( 0 ) /* RequestInit */
            },
            { /* PduGroupSwitchActionTable[6] */
                { /* EnableMask */
                    UINT8_C( 0 ), /* EnableMask[0] */
                    UINT8_C( 0 ), /* EnableMask[1] */
                    UINT8_C( 0 ), /* EnableMask[2] */
                    UINT8_C( 0 ) /* EnableMask[3] */
                },
                { /* DisableMask */
                    UINT8_C( 240 ), /* DisableMask[0] */
                    UINT8_C( 255 ), /* DisableMask[1] */
                    UINT8_C( 255 ), /* DisableMask[2] */
                    UINT8_C( 255 ) /* DisableMask[3] */
                },
                UINT8_C( 0 ) /* RequestInit */
            },
            { /* PduGroupSwitchActionTable[7] */
                { /* EnableMask */
                    UINT8_C( 15 ), /* EnableMask[0] */
                    UINT8_C( 0 ), /* EnableMask[1] */
                    UINT8_C( 0 ), /* EnableMask[2] */
                    UINT8_C( 0 ) /* EnableMask[3] */
                },
                { /* DisableMask */
                    UINT8_C( 255 ), /* DisableMask[0] */
                    UINT8_C( 255 ), /* DisableMask[1] */
                    UINT8_C( 255 ), /* DisableMask[2] */
                    UINT8_C( 255 ) /* DisableMask[3] */
                },
                UINT8_C( 0 ) /* RequestInit */
            },
            { /* PduGroupSwitchActionTable[8] */
                { /* EnableMask */
                    UINT8_C( 5 ), /* EnableMask[0] */
                    UINT8_C( 0 ), /* EnableMask[1] */
                    UINT8_C( 0 ), /* EnableMask[2] */
                    UINT8_C( 0 ) /* EnableMask[3] */
                },
                { /* DisableMask */
                    UINT8_C( 255 ), /* DisableMask[0] */
                    UINT8_C( 255 ), /* DisableMask[1] */
                    UINT8_C( 255 ), /* DisableMask[2] */
                    UINT8_C( 255 ) /* DisableMask[3] */
                },
                UINT8_C( 0 ) /* RequestInit */
            },
            { /* PduGroupSwitchActionTable[9] */
                { /* EnableMask */
                    UINT8_C( 0 ), /* EnableMask[0] */
                    UINT8_C( 0 ), /* EnableMask[1] */
                    UINT8_C( 0 ), /* EnableMask[2] */
                    UINT8_C( 0 ) /* EnableMask[3] */
                },
                { /* DisableMask */
                    UINT8_C( 250 ), /* DisableMask[0] */
                    UINT8_C( 255 ), /* DisableMask[1] */
                    UINT8_C( 255 ), /* DisableMask[2] */
                    UINT8_C( 255 ) /* DisableMask[3] */
                },
                UINT8_C( 0 ) /* RequestInit */
            },
            { /* PduGroupSwitchActionTable[10] */
                { /* EnableMask */
                    UINT8_C( 10 ), /* EnableMask[0] */
                    UINT8_C( 0 ), /* EnableMask[1] */
                    UINT8_C( 0 ), /* EnableMask[2] */
                    UINT8_C( 0 ) /* EnableMask[3] */
                },
                { /* DisableMask */
                    UINT8_C( 255 ), /* DisableMask[0] */
                    UINT8_C( 255 ), /* DisableMask[1] */
                    UINT8_C( 255 ), /* DisableMask[2] */
                    UINT8_C( 255 ) /* DisableMask[3] */
                },
                UINT8_C( 0 ) /* RequestInit */
            },
            { /* PduGroupSwitchActionTable[11] */
                { /* EnableMask */
                    UINT8_C( 0 ), /* EnableMask[0] */
                    UINT8_C( 0 ), /* EnableMask[1] */
                    UINT8_C( 0 ), /* EnableMask[2] */
                    UINT8_C( 0 ) /* EnableMask[3] */
                },
                { /* DisableMask */
                    UINT8_C( 245 ), /* DisableMask[0] */
                    UINT8_C( 255 ), /* DisableMask[1] */
                    UINT8_C( 255 ), /* DisableMask[2] */
                    UINT8_C( 255 ) /* DisableMask[3] */
                },
                UINT8_C( 0 ) /* RequestInit */
            }
        },
        { /* UInt16InitialValuesTable */
            UINT16_C( 0 ), /* UInt16InitialValuesTable[0] -- Initial value of Port BswM_ReqPort */
            UINT16_C( 0 ), /* UInt16InitialValuesTable[1] -- Initial value of Port BswM_ReqPort */
            UINT16_C( 0 ), /* UInt16InitialValuesTable[2] -- Initial value of Port BswM_ReqPort */
            UINT16_C( 0 ) /* UInt16InitialValuesTable[3] -- Initial value of Port BswM_ReqPort */
        },
        { /* UInt8InitialValuesTable */
            ECUM_WKSTATUS_NONE, /* UInt8InitialValuesTable[0] -- Initial value of Port EcuM_WakeupValidation_PublicCan */
            UINT8_C( 5 ), /* UInt8InitialValuesTable[1] -- Initial value of Port BswMBswModeNotification_DcmEcuReset */
            UINT8_C( 0 ), /* UInt8InitialValuesTable[2] -- Initial value of Port BswMBswModeNotification_DcmCommunicationControl */
            UINT8_C( 0 ), /* UInt8InitialValuesTable[3] -- Initial value of Port BswMSwcModeNotification_Comco_RxReq */
            UINT8_C( 0 ), /* UInt8InitialValuesTable[4] -- Initial value of Port BswMSwcModeNotification_Comco_TxReq */
            UINT8_C( 1 ), /* UInt8InitialValuesTable[5] -- Initial value of Port BswMModeRequestPort_Slave */
            UINT8_C( 1 ), /* UInt8InitialValuesTable[6] -- Initial value of Port BswMModeRequestPort_Slave */
            UINT8_C( 1 ) /* UInt8InitialValuesTable[7] -- Initial value of Port BswMModeRequestPort_Slave */
        }
    }
};

/* Deviation MISRAC2012-1, MISRAC2012-2, MISRAC2012-3 <STOP> */

#define PBCFGM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include <PbcfgM_MemMap.h>

/*==================[internal constants]=====================================*/


/*==================[external data]==========================================*/


/*==================[internal data]==========================================*/


/*==================[external function definitions]==========================*/


/*==================[internal function definitions]==========================*/


/*==================[end of file]============================================*/

