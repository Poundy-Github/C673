


/**
 * \file
 *
 * \brief AUTOSAR BswM
 *
 * This file contains the implementation of the AUTOSAR
 * module BswM.
 *
 * \version 1.4.1
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2021 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

#ifndef BSWM_CFGTYPES_H
#define BSWM_CFGTYPES_H



/*==================[inclusions]=============================================*/

#include <Platform_Types.h>
#include <TSAutosar.h>
#define TS_RELOCATABLE_CFG_ENABLE STD_ON
#define TS_PB_CFG_PTR_CLASS BSWM_APPL_CONST
#include <TSPBConfig_Types.h>


/*==================[macros]=================================================*/


/*==================[type definitions]=======================================*/

typedef VAR( uint8, TYPEDEF ) UInt8Symbol;

typedef struct /* BswMPduGroupSwitchActionType */ {
    VAR( uint8, TYPEDEF ) EnableMask[4];
    VAR( uint8, TYPEDEF ) DisableMask[4];
    VAR( uint8, TYPEDEF ) RequestInit;
} BswMPduGroupSwitchActionType;

typedef struct /* BswMActionListItemType */ {
    VAR( uint16, TYPEDEF ) ArtifactIndex;
    VAR( uint8, TYPEDEF ) ActionListItemType;
    VAR( uint8, TYPEDEF ) IsAbortOnFail;
    VAR( uint8, TYPEDEF ) ActionType;
} BswMActionListItemType;

typedef struct /* BswMRangeType */ {
    VAR( uint16, TYPEDEF ) Head;
    VAR( uint16, TYPEDEF ) Tail;
} BswMRangeType;

typedef struct /* BswMRuleType */ {
    VAR( uint16, TYPEDEF ) ID;
    VAR( uint16, TYPEDEF ) LogicalExprIndex;
    VAR( uint16, TYPEDEF ) TrueActionListIndex;
    VAR( uint16, TYPEDEF ) FalseActionListIndex;
    VAR( uint8, TYPEDEF ) RuleInitState;
} BswMRuleType;

typedef struct /* BswMActionListType */ {
    VAR( BswMRangeType, TYPEDEF ) ActionListItemSegment;
    VAR( uint8, TYPEDEF ) IsTriggered;
} BswMActionListType;

typedef struct /* BswM_ConfigType */ {
    TS_REF2CFG( BswMRuleType )  RuleTable;
    TS_REF2CFG( uint16 )  RuleDependencyTable;
    TS_REF2CFG( BswMRangeType )  RuleDependencyListRangeTable;
    TS_REF2CFG( BswMActionListType )  ActionListTable;
    TS_REF2CFG( BswMActionListItemType )  ActionListItemTable;
    TS_REF2CFG( BswMPduGroupSwitchActionType )  PduGroupSwitchActionTable;
    TS_REF2CFG( UInt8Symbol )  UInt8InitialValuesTable;
    TS_REF2CFG( uint16 )  UInt16InitialValuesTable;
    TS_REF2CFG( uint32 )  UInt32InitialValuesTable;
    VAR( uint32, TYPEDEF ) PlatformSignature;
    VAR( uint32, TYPEDEF ) LcfgSignature;
    VAR( uint32, TYPEDEF ) CfgSignature;
    VAR( uint32, TYPEDEF ) PublicInfoSignature;
    VAR( uint16, TYPEDEF ) NumRules;
    VAR( uint16, TYPEDEF ) NumRulesDeferred;
    VAR( uint16, TYPEDEF ) NumActionLists;
} BswM_ConfigType;


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

#endif /* BSWM_CFGTYPES_H */

/*==================[end of file]============================================*/

