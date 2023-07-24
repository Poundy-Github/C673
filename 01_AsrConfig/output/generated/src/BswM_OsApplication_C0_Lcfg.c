
/**
 * \file
 *
 * \brief AUTOSAR BswM
 *
 * This file contains the implementation of the AUTOSAR
 * module BswM.
 *
 * \version 1.15.7
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2021 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

 /* \addtogroup Mode Management Stack
  * @{ */

/* !LINKSTO BswM0024,1 */
/* The BswM_Lcfg.c contains all link-time configuration parameters. */

/* !LINKSTO BswM.Impl.SourceFile.BswM_Partition_Lcfg_c,1 */

/* MISRA-C:2012 Deviation List
 *
 * MISRAC2012-1) Deviated Rule: 17.8 (advisory)
 * A function parameter should not be modified.
 *
 * Reason:
 * For BswMJ1939DcmBroadcastStatus ports the mode parameter has no significance
 * and it intentionally set to 0 when calling the HandleStaticRequest function.
 * It is then directly modified in order to call the BswM_HandleRequest function
 * with the correct mode (depending on the current channel) in order to avoid
 * creating a new stack variable.
 */

/*==================[inclusions]============================================*/

#include <BswM_Trace.h>       /* Dbg macros */
#include <BswM.h>
#include <BswM_Int_Cfg.h>
#include <BswM_Int.h>
#include <TSMem.h>            /* Used for TS_MemSet */
#include <SchM_BswM_1_OsApplication_C0.h>        /* SchM API for BswM         */

#include <Rte_BswM_OsApplication_C0.h>         /* RTE-generated BswM header */

#include <BswM_OsApplication_C0_Lcfg.h>

/*==================[macros]================================================*/

#define BSWM_INVALID_INITIAL_VALUE_INDEX 0xFFU

/*==================[type definitions]======================================*/

/*==================[internal function declarations]========================*/

/* !LINKSTO BswM.Impl.MemoryMapping.InstanceCode,1 */
#define BSWM_1_OsApplication_C0_START_SEC_CODE
#include <BswM_1_OsApplication_C0_MemMap.h>

STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_OsApplication_C0_BswM_LogEx_StartupTwoA(void);
STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_OsApplication_C0_BswM_LogEx_RunTwo(void);
STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_OsApplication_C0_BswM_LogEx_GoOffOneA(void);
STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_OsApplication_C0_BswM_LogEx_GoOffOneB(void);
STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_OsApplication_C0_BswM_LogEx_StartupTwoB(void);
STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_OsApplication_C0_BswM_LogEx_Prep_Shutdown(void);
STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_OsApplication_C0_BswM_LogEx_CanSmNoCom_PublicCan(void);
STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_OsApplication_C0_BswM_LogEx_CanSmSilentCom_PublicCan(void);
STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_OsApplication_C0_BswM_LogEx_CanSmBusoff_PublicCan(void);
STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_OsApplication_C0_BswM_LogEx_CanSmFullCom_PublicCan(void);
STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_OsApplication_C0_BswM_LogEx_CanSmNoCom_PrivateCan(void);
STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_OsApplication_C0_BswM_LogEx_CanSmSilentCom_PrivateCan(void);
STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_OsApplication_C0_BswM_LogEx_CanSmBusoff_PrivateCan(void);
STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_OsApplication_C0_BswM_LogEx_CanSmFullCom_PrivateCan(void);
STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_OsApplication_C0_BswM_LogEx_WakupValidation_PublicCan(void);
STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_OsApplication_C0_BswM_LogEx_Dcm_280301_DisRxTx_Norm(void);
STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_OsApplication_C0_BswM_LogEx_Dcm_280001_EnRxTx_Norm(void);
STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_OsApplication_C0_BswM_LogEx_Dcm_280302_DisRxTx_NM(void);
STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_OsApplication_C0_BswM_LogEx_Dcm_280002_EnRxTx_NM(void);
STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_OsApplication_C0_BswM_LogEx_Dcm_280303_DisRxTx_Norm_NM(void);
STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_OsApplication_C0_BswM_LogEx_Dcm_280003_EnRxTx_Norm_NM(void);
STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_OsApplication_C0_BswM_LogEx_Comco_PduRxReq(void);
STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_OsApplication_C0_BswM_LogEx_Comco_PduTxReq(void);
STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_OsApplication_C0_BswM_LogEx_Dcm_EcuReset_EXECUTE(void);
STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_OsApplication_C0_BswM_LogEx_Dcm_EcuReset_HARD(void);
STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_OsApplication_C0_BswM_LogEx_Dcm_EcuReset_SOFT(void);
STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_OsApplication_C0_BswM_LogEx_Dcm_EcuReset_JUMPTOSYSSUPPLIERBOOTLOADER(void);

STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_OsApplication_C0_BswM_LogEx_StartupTwoA(void);
STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_OsApplication_C0_BswM_LogEx_RunTwo(void);
STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_OsApplication_C0_BswM_LogEx_GoOffOneA(void);
STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_OsApplication_C0_BswM_LogEx_GoOffOneB(void);
STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_OsApplication_C0_BswM_LogEx_StartupTwoB(void);
STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_OsApplication_C0_BswM_LogEx_Prep_Shutdown(void);
STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_OsApplication_C0_BswM_LogEx_CanSmNoCom_PublicCan(void);
STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_OsApplication_C0_BswM_LogEx_CanSmSilentCom_PublicCan(void);
STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_OsApplication_C0_BswM_LogEx_CanSmBusoff_PublicCan(void);
STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_OsApplication_C0_BswM_LogEx_CanSmFullCom_PublicCan(void);
STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_OsApplication_C0_BswM_LogEx_CanSmNoCom_PrivateCan(void);
STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_OsApplication_C0_BswM_LogEx_CanSmSilentCom_PrivateCan(void);
STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_OsApplication_C0_BswM_LogEx_CanSmBusoff_PrivateCan(void);
STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_OsApplication_C0_BswM_LogEx_CanSmFullCom_PrivateCan(void);
STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_OsApplication_C0_BswM_LogEx_WakupValidation_PublicCan(void);
STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_OsApplication_C0_BswM_LogEx_Dcm_280301_DisRxTx_Norm(void);
STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_OsApplication_C0_BswM_LogEx_Dcm_280001_EnRxTx_Norm(void);
STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_OsApplication_C0_BswM_LogEx_Dcm_280302_DisRxTx_NM(void);
STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_OsApplication_C0_BswM_LogEx_Dcm_280002_EnRxTx_NM(void);
STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_OsApplication_C0_BswM_LogEx_Dcm_280303_DisRxTx_Norm_NM(void);
STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_OsApplication_C0_BswM_LogEx_Dcm_280003_EnRxTx_Norm_NM(void);
STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_OsApplication_C0_BswM_LogEx_Comco_PduRxReq(void);
STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_OsApplication_C0_BswM_LogEx_Comco_PduTxReq(void);
STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_OsApplication_C0_BswM_LogEx_Dcm_EcuReset_EXECUTE(void);
STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_OsApplication_C0_BswM_LogEx_Dcm_EcuReset_HARD(void);
STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_OsApplication_C0_BswM_LogEx_Dcm_EcuReset_SOFT(void);
STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_OsApplication_C0_BswM_LogEx_Dcm_EcuReset_JUMPTOSYSSUPPLIERBOOTLOADER(void);

STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_OsApplication_C0_BswM_Act_StartupTwoA(void);
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_OsApplication_C0_BswM_Act_StartupTwoB(void);
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_OsApplication_C0_BswM_Act_RunTwo(void);
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_OsApplication_C0_BswM_Act_RequestRunTwo(void);
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_OsApplication_C0_BswM_Act_GoOffOneA(void);
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_OsApplication_C0_BswM_Act_GoOffOneB(void);
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_OsApplication_C0_BswM_Act_RteSwitch_GoOffOneA(void);
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_OsApplication_C0_BswM_Act_RteSwitch_GoOffOneB(void);
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_OsApplication_C0_BswM_Act_RteSwitch_RunTwo(void);
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_OsApplication_C0_BswM_Act_RteSwitch_StartupTwoA(void);
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_OsApplication_C0_BswM_Act_RteSwitch_StartupTwoB(void);
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_OsApplication_C0_BswM_Act_CanNoComPublicCan(void);
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_OsApplication_C0_BswM_Act_CanSilentComPublicCan(void);
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_OsApplication_C0_BswM_Act_CanFullComPublicCan(void);
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_OsApplication_C0_BswM_Act_PrepShutdown(void);
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_OsApplication_C0_BswM_Act_RteSwitch_PrpShutdown(void);
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_OsApplication_C0_BswM_Act_CanNoComPrivateCan(void);
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_OsApplication_C0_BswM_Act_CanSilentComPrivateCan(void);
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_OsApplication_C0_BswM_Act_CanFullComPrivateCan(void);
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_OsApplication_C0_BswMAction_WakupValidation_PublicCan(void);
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_OsApplication_C0_BswM_Act_STARTUP_TWO_D(void);
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_OsApplication_C0_BswM_Act_GO_OFF_ONE_D(void);
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_OsApplication_C0_Act_Dcm_0x280301_DisRxTx_Norm(void);
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_OsApplication_C0_Act_Dcm_0x280001_EnRxTx_Norm(void);
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_OsApplication_C0_Act_Dcm_0x280302_DisRxTx_NM(void);
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_OsApplication_C0_Act_Dcm_0x280002_EnRxTx_NM(void);
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_OsApplication_C0_Act_UserCallout_Comco_Init(void);
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_OsApplication_C0_Act_Comco_Pdu_RxGroup_Active(void);
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_OsApplication_C0_Act_Comco_Pdu_RxGroup_InActive(void);
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_OsApplication_C0_Act_Comco_Pdu_TxGroup_Active(void);
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_OsApplication_C0_Act_Comco_Pdu_TxGroup_InActive(void);
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_OsApplication_C0_Act_Dcm_EcuReset_EXECUTE(void);
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_OsApplication_C0_Act_Dcm_EcuReset_HARD(void);
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_OsApplication_C0_Act_Dcm_EcuReset_SOFT(void);
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_OsApplication_C0_Act_Dcm_EcuReset_JUMPTOSYSSUPPLIERBOOTLOADER(void);
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_OsApplication_C0_Act_RteSwitch_CanSMStatePublic_Busoff(void);
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_OsApplication_C0_Act_RteSwitch_CanSMStatePublic_FullCom(void);
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_OsApplication_C0_Act_RteSwitch_CanSMStatePublic_SlientCom(void);
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_OsApplication_C0_Act_RteSwitch_CanSMStatePublic_NoCom(void);
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_OsApplication_C0_Act_RteSwitch_CanSMStatePrivate_Busoff(void);
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_OsApplication_C0_Act_RteSwitch_CanSMStatePrivate_FullCom(void);
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_OsApplication_C0_Act_RteSwitch_CanSMStatePrivate_SlientCom(void);
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_OsApplication_C0_Act_RteSwitch_CanSMStatePrivate_NoCom(void);
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_OsApplication_C0_BswM_Act_PrepShutdown_C1(void);
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_OsApplication_C0_Act_RteSwitch_DiagComControl_DisRxTxNorM(void);
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_OsApplication_C0_Act_RteSwitch_DiagComControl_EnRxTxNorM(void);
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_OsApplication_C0_Act_RteSwitch_DiagComControl_EnRxTxNM(void);
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_OsApplication_C0_Act_RteSwitch_DiagComControl_DisRxTxNM(void);
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_OsApplication_C0_Act_RteSwitch_DiagComControl_EnRxTxNorM_NM(void);
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_OsApplication_C0_Act_RteSwitch_DiagComControl_DisRxTxNorM_NM(void);
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_OsApplication_C0_Act_PublicCAN_BusOff_Recorvery_Tja1043(void);

STATIC FUNC(BswMResultType, BSWM_CODE) BswM_OsApplication_C0_ExprGetState(uint16 exprIndex);
STATIC FUNC(BswMResultType, BSWM_CODE) BswM_OsApplication_C0_ExprGetResult(uint16 exprIndex);

STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_OsApplication_C0_ExecuteAction(uint16 actionIndex);

STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_OsApplication_C0_HandleStaticRequest(uint32 channel, uint16 mode, uint8 source, uint8 sid);

STATIC FUNC(void, BSWM_CODE) BswM_OsApplication_C0_InitRteModeRequestPorts(void);

#define BSWM_1_OsApplication_C0_STOP_SEC_CODE
#include <BswM_1_OsApplication_C0_MemMap.h>

/*==================[external function declarations]========================*/

/*==================[internal constants]====================================*/

/*==================[external constants]====================================*/

/*==================[internal data]=========================================*/

#define BSWM_1_OsApplication_C0_START_SEC_CONST_UNSPECIFIED
#include <BswM_1_OsApplication_C0_MemMap.h>

STATIC CONST(uint8, AUTOMATIC) BswM_OsApplication_C0_InitialValueMappings[8] = 
{
  /* BswM_ReqPort */
  0U,
  /* CanSm_CurrentStatePort_PublicCan */
  0xFFU,
  /* CanSm_CurrentStatePort_PrivateCan */
  0xFFU,
  /* EcuM_WakeupValidation_PublicCan */
  0U,
  /* BswMBswModeNotification_DcmEcuReset */
  1U,
  /* BswMBswModeNotification_DcmCommunicationControl */
  2U,
  /* BswMSwcModeNotification_Comco_RxReq */
  3U,
  /* BswMSwcModeNotification_Comco_TxReq */
  4U,
};

/**
 * BswM_OsApplication_C0_NumModeRequestPortsTable
 */
STATIC CONST( uint16 , AUTOMATIC ) BswM_OsApplication_C0_NumModeRequestPortsTable[13] = 
{
  UINT16_C( 2 ), /* Number of ports of type BSWM_CAN_SM_INDICATION */
  UINT16_C( 0 ), /* Number of ports of type BSWM_COMM_INDICATION */
  UINT16_C( 0 ), /* Number of ports of type BSWM_COMM_INITIATE_RESET */
  UINT16_C( 0 ), /* Number of ports of type BSWM_COMM_PNC_REQUEST */
  UINT16_C( 0 ), /* Number of ports of type BSWM_DCM_APPLICATION_UPDATED_INDICATION */
  UINT16_C( 0 ), /* Number of ports of type BSWM_DCM_COM_MODE_CURRENT_STATE */
  UINT16_C( 0 ), /* Number of ports of type BSWM_DCM_COM_MODE_REQUEST */
  UINT16_C( 0 ), /* Number of ports of type BSWM_DCM_RESET_MODE_REQUEST */
  UINT16_C( 0 ), /* Number of ports of type BSWM_DCM_SESSION_MODE_REQUEST */
  UINT16_C( 0 ), /* Number of ports of type BSWM_ECUM_INDICATION */
  UINT16_C( 1 ), /* Number of ports of type BSWM_ECUM_WAKEUP_SOURCE */
  UINT16_C( 1 ), /* Number of ports of type BSWM_GENERIC_REQUEST */
  UINT16_C( 0 )  /* Number of ports of type BSWM_NM_CAR_WAKEUP_INDICATION */
};

/*
 * The logical expressions table contains both the state
 * and the result function pointers for each defined logical
 * expression configured in the current BswM instance.
 */
/**
 * BswM_OsApplication_C0_LogicalExprTable
 */
STATIC CONST( BswMLogicalExprType , AUTOMATIC ) BswM_OsApplication_C0_LogicalExprTable[27] = 
{
  { /* [0] */
    &BswM_ExprState_OsApplication_C0_BswM_LogEx_StartupTwoA, /* GetState */
    &BswM_ExprResult_OsApplication_C0_BswM_LogEx_StartupTwoA  /* GetResult */
  },
  { /* [1] */
    &BswM_ExprState_OsApplication_C0_BswM_LogEx_RunTwo, /* GetState */
    &BswM_ExprResult_OsApplication_C0_BswM_LogEx_RunTwo  /* GetResult */
  },
  { /* [2] */
    &BswM_ExprState_OsApplication_C0_BswM_LogEx_GoOffOneA, /* GetState */
    &BswM_ExprResult_OsApplication_C0_BswM_LogEx_GoOffOneA  /* GetResult */
  },
  { /* [3] */
    &BswM_ExprState_OsApplication_C0_BswM_LogEx_GoOffOneB, /* GetState */
    &BswM_ExprResult_OsApplication_C0_BswM_LogEx_GoOffOneB  /* GetResult */
  },
  { /* [4] */
    &BswM_ExprState_OsApplication_C0_BswM_LogEx_StartupTwoB, /* GetState */
    &BswM_ExprResult_OsApplication_C0_BswM_LogEx_StartupTwoB  /* GetResult */
  },
  { /* [5] */
    &BswM_ExprState_OsApplication_C0_BswM_LogEx_Prep_Shutdown, /* GetState */
    &BswM_ExprResult_OsApplication_C0_BswM_LogEx_Prep_Shutdown  /* GetResult */
  },
  { /* [6] */
    &BswM_ExprState_OsApplication_C0_BswM_LogEx_CanSmNoCom_PublicCan, /* GetState */
    &BswM_ExprResult_OsApplication_C0_BswM_LogEx_CanSmNoCom_PublicCan  /* GetResult */
  },
  { /* [7] */
    &BswM_ExprState_OsApplication_C0_BswM_LogEx_CanSmSilentCom_PublicCan, /* GetState */
    &BswM_ExprResult_OsApplication_C0_BswM_LogEx_CanSmSilentCom_PublicCan  /* GetResult */
  },
  { /* [8] */
    &BswM_ExprState_OsApplication_C0_BswM_LogEx_CanSmBusoff_PublicCan, /* GetState */
    &BswM_ExprResult_OsApplication_C0_BswM_LogEx_CanSmBusoff_PublicCan  /* GetResult */
  },
  { /* [9] */
    &BswM_ExprState_OsApplication_C0_BswM_LogEx_CanSmFullCom_PublicCan, /* GetState */
    &BswM_ExprResult_OsApplication_C0_BswM_LogEx_CanSmFullCom_PublicCan  /* GetResult */
  },
  { /* [10] */
    &BswM_ExprState_OsApplication_C0_BswM_LogEx_CanSmNoCom_PrivateCan, /* GetState */
    &BswM_ExprResult_OsApplication_C0_BswM_LogEx_CanSmNoCom_PrivateCan  /* GetResult */
  },
  { /* [11] */
    &BswM_ExprState_OsApplication_C0_BswM_LogEx_CanSmSilentCom_PrivateCan, /* GetState */
    &BswM_ExprResult_OsApplication_C0_BswM_LogEx_CanSmSilentCom_PrivateCan  /* GetResult */
  },
  { /* [12] */
    &BswM_ExprState_OsApplication_C0_BswM_LogEx_CanSmBusoff_PrivateCan, /* GetState */
    &BswM_ExprResult_OsApplication_C0_BswM_LogEx_CanSmBusoff_PrivateCan  /* GetResult */
  },
  { /* [13] */
    &BswM_ExprState_OsApplication_C0_BswM_LogEx_CanSmFullCom_PrivateCan, /* GetState */
    &BswM_ExprResult_OsApplication_C0_BswM_LogEx_CanSmFullCom_PrivateCan  /* GetResult */
  },
  { /* [14] */
    &BswM_ExprState_OsApplication_C0_BswM_LogEx_WakupValidation_PublicCan, /* GetState */
    &BswM_ExprResult_OsApplication_C0_BswM_LogEx_WakupValidation_PublicCan  /* GetResult */
  },
  { /* [15] */
    &BswM_ExprState_OsApplication_C0_BswM_LogEx_Dcm_280301_DisRxTx_Norm, /* GetState */
    &BswM_ExprResult_OsApplication_C0_BswM_LogEx_Dcm_280301_DisRxTx_Norm  /* GetResult */
  },
  { /* [16] */
    &BswM_ExprState_OsApplication_C0_BswM_LogEx_Dcm_280001_EnRxTx_Norm, /* GetState */
    &BswM_ExprResult_OsApplication_C0_BswM_LogEx_Dcm_280001_EnRxTx_Norm  /* GetResult */
  },
  { /* [17] */
    &BswM_ExprState_OsApplication_C0_BswM_LogEx_Dcm_280302_DisRxTx_NM, /* GetState */
    &BswM_ExprResult_OsApplication_C0_BswM_LogEx_Dcm_280302_DisRxTx_NM  /* GetResult */
  },
  { /* [18] */
    &BswM_ExprState_OsApplication_C0_BswM_LogEx_Dcm_280002_EnRxTx_NM, /* GetState */
    &BswM_ExprResult_OsApplication_C0_BswM_LogEx_Dcm_280002_EnRxTx_NM  /* GetResult */
  },
  { /* [19] */
    &BswM_ExprState_OsApplication_C0_BswM_LogEx_Dcm_280303_DisRxTx_Norm_NM, /* GetState */
    &BswM_ExprResult_OsApplication_C0_BswM_LogEx_Dcm_280303_DisRxTx_Norm_NM  /* GetResult */
  },
  { /* [20] */
    &BswM_ExprState_OsApplication_C0_BswM_LogEx_Dcm_280003_EnRxTx_Norm_NM, /* GetState */
    &BswM_ExprResult_OsApplication_C0_BswM_LogEx_Dcm_280003_EnRxTx_Norm_NM  /* GetResult */
  },
  { /* [21] */
    &BswM_ExprState_OsApplication_C0_BswM_LogEx_Comco_PduRxReq, /* GetState */
    &BswM_ExprResult_OsApplication_C0_BswM_LogEx_Comco_PduRxReq  /* GetResult */
  },
  { /* [22] */
    &BswM_ExprState_OsApplication_C0_BswM_LogEx_Comco_PduTxReq, /* GetState */
    &BswM_ExprResult_OsApplication_C0_BswM_LogEx_Comco_PduTxReq  /* GetResult */
  },
  { /* [23] */
    &BswM_ExprState_OsApplication_C0_BswM_LogEx_Dcm_EcuReset_EXECUTE, /* GetState */
    &BswM_ExprResult_OsApplication_C0_BswM_LogEx_Dcm_EcuReset_EXECUTE  /* GetResult */
  },
  { /* [24] */
    &BswM_ExprState_OsApplication_C0_BswM_LogEx_Dcm_EcuReset_HARD, /* GetState */
    &BswM_ExprResult_OsApplication_C0_BswM_LogEx_Dcm_EcuReset_HARD  /* GetResult */
  },
  { /* [25] */
    &BswM_ExprState_OsApplication_C0_BswM_LogEx_Dcm_EcuReset_SOFT, /* GetState */
    &BswM_ExprResult_OsApplication_C0_BswM_LogEx_Dcm_EcuReset_SOFT  /* GetResult */
  },
  { /* [26] */
    &BswM_ExprState_OsApplication_C0_BswM_LogEx_Dcm_EcuReset_JUMPTOSYSSUPPLIERBOOTLOADER, /* GetState */
    &BswM_ExprResult_OsApplication_C0_BswM_LogEx_Dcm_EcuReset_JUMPTOSYSSUPPLIERBOOTLOADER  /* GetResult */
  }
};

/*
 * The action table contains function pointers to all configured
 * actions within the current BswM instance.
 */
/**
 * BswM_OsApplication_C0_ActionTable
 */
STATIC CONST( BswMActionFuncPtrType , AUTOMATIC ) BswM_OsApplication_C0_ActionTable[51] = 
{
  &BswM_Action_OsApplication_C0_BswM_Act_StartupTwoA, /* [0] */
  &BswM_Action_OsApplication_C0_BswM_Act_StartupTwoB, /* [1] */
  &BswM_Action_OsApplication_C0_BswM_Act_RunTwo, /* [2] */
  &BswM_Action_OsApplication_C0_BswM_Act_RequestRunTwo, /* [3] */
  &BswM_Action_OsApplication_C0_BswM_Act_GoOffOneA, /* [4] */
  &BswM_Action_OsApplication_C0_BswM_Act_GoOffOneB, /* [5] */
  &BswM_Action_OsApplication_C0_BswM_Act_RteSwitch_GoOffOneA, /* [6] */
  &BswM_Action_OsApplication_C0_BswM_Act_RteSwitch_GoOffOneB, /* [7] */
  &BswM_Action_OsApplication_C0_BswM_Act_RteSwitch_RunTwo, /* [8] */
  &BswM_Action_OsApplication_C0_BswM_Act_RteSwitch_StartupTwoA, /* [9] */
  &BswM_Action_OsApplication_C0_BswM_Act_RteSwitch_StartupTwoB, /* [10] */
  &BswM_Action_OsApplication_C0_BswM_Act_CanNoComPublicCan, /* [11] */
  &BswM_Action_OsApplication_C0_BswM_Act_CanSilentComPublicCan, /* [12] */
  &BswM_Action_OsApplication_C0_BswM_Act_CanFullComPublicCan, /* [13] */
  &BswM_Action_OsApplication_C0_BswM_Act_PrepShutdown, /* [14] */
  &BswM_Action_OsApplication_C0_BswM_Act_RteSwitch_PrpShutdown, /* [15] */
  &BswM_Action_OsApplication_C0_BswM_Act_CanNoComPrivateCan, /* [16] */
  &BswM_Action_OsApplication_C0_BswM_Act_CanSilentComPrivateCan, /* [17] */
  &BswM_Action_OsApplication_C0_BswM_Act_CanFullComPrivateCan, /* [18] */
  &BswM_Action_OsApplication_C0_BswMAction_WakupValidation_PublicCan, /* [19] */
  &BswM_Action_OsApplication_C0_BswM_Act_STARTUP_TWO_D, /* [20] */
  &BswM_Action_OsApplication_C0_BswM_Act_GO_OFF_ONE_D, /* [21] */
  &BswM_Action_OsApplication_C0_Act_Dcm_0x280301_DisRxTx_Norm, /* [22] */
  &BswM_Action_OsApplication_C0_Act_Dcm_0x280001_EnRxTx_Norm, /* [23] */
  &BswM_Action_OsApplication_C0_Act_Dcm_0x280302_DisRxTx_NM, /* [24] */
  &BswM_Action_OsApplication_C0_Act_Dcm_0x280002_EnRxTx_NM, /* [25] */
  &BswM_Action_OsApplication_C0_Act_UserCallout_Comco_Init, /* [26] */
  &BswM_Action_OsApplication_C0_Act_Comco_Pdu_RxGroup_Active, /* [27] */
  &BswM_Action_OsApplication_C0_Act_Comco_Pdu_RxGroup_InActive, /* [28] */
  &BswM_Action_OsApplication_C0_Act_Comco_Pdu_TxGroup_Active, /* [29] */
  &BswM_Action_OsApplication_C0_Act_Comco_Pdu_TxGroup_InActive, /* [30] */
  &BswM_Action_OsApplication_C0_Act_Dcm_EcuReset_EXECUTE, /* [31] */
  &BswM_Action_OsApplication_C0_Act_Dcm_EcuReset_HARD, /* [32] */
  &BswM_Action_OsApplication_C0_Act_Dcm_EcuReset_SOFT, /* [33] */
  &BswM_Action_OsApplication_C0_Act_Dcm_EcuReset_JUMPTOSYSSUPPLIERBOOTLOADER, /* [34] */
  &BswM_Action_OsApplication_C0_Act_RteSwitch_CanSMStatePublic_Busoff, /* [35] */
  &BswM_Action_OsApplication_C0_Act_RteSwitch_CanSMStatePublic_FullCom, /* [36] */
  &BswM_Action_OsApplication_C0_Act_RteSwitch_CanSMStatePublic_SlientCom, /* [37] */
  &BswM_Action_OsApplication_C0_Act_RteSwitch_CanSMStatePublic_NoCom, /* [38] */
  &BswM_Action_OsApplication_C0_Act_RteSwitch_CanSMStatePrivate_Busoff, /* [39] */
  &BswM_Action_OsApplication_C0_Act_RteSwitch_CanSMStatePrivate_FullCom, /* [40] */
  &BswM_Action_OsApplication_C0_Act_RteSwitch_CanSMStatePrivate_SlientCom, /* [41] */
  &BswM_Action_OsApplication_C0_Act_RteSwitch_CanSMStatePrivate_NoCom, /* [42] */
  &BswM_Action_OsApplication_C0_BswM_Act_PrepShutdown_C1, /* [43] */
  &BswM_Action_OsApplication_C0_Act_RteSwitch_DiagComControl_DisRxTxNorM, /* [44] */
  &BswM_Action_OsApplication_C0_Act_RteSwitch_DiagComControl_EnRxTxNorM, /* [45] */
  &BswM_Action_OsApplication_C0_Act_RteSwitch_DiagComControl_EnRxTxNM, /* [46] */
  &BswM_Action_OsApplication_C0_Act_RteSwitch_DiagComControl_DisRxTxNM, /* [47] */
  &BswM_Action_OsApplication_C0_Act_RteSwitch_DiagComControl_EnRxTxNorM_NM, /* [48] */
  &BswM_Action_OsApplication_C0_Act_RteSwitch_DiagComControl_DisRxTxNorM_NM, /* [49] */
  &BswM_Action_OsApplication_C0_Act_PublicCAN_BusOff_Recorvery_Tja1043  /* [50] */
};

#define BSWM_1_OsApplication_C0_STOP_SEC_CONST_UNSPECIFIED
#include <BswM_1_OsApplication_C0_MemMap.h>

/* !LINKSTO BswM.Impl.MemoryMapping.InstanceData,1 */
#define BSWM_1_OsApplication_C0_START_SEC_VAR_INIT_UNSPECIFIED
#include <BswM_1_OsApplication_C0_MemMap.h>

/* Dynamically Generated Mode Request Ports */
/**
 * BswM_OsApplication_C0_UInt8RteRequestPortTable
 */
STATIC BswMUInt8RteModeRequestPortType BswM_OsApplication_C0_UInt8RteRequestPortTable[4] = 
{
  { /* BswMSwcModeNotification_Comco_RxReq */
    { /* base */
      UINT16_C( 6 ), /* id */
      UINT8_C( 1 ), /* isImmediate */
      UINT8_C( 0 )  /* isDefined */
    },
    UINT8_C( 0 )  /* mode */
  },
  { /* BswMSwcModeNotification_Comco_TxReq */
    { /* base */
      UINT16_C( 7 ), /* id */
      UINT8_C( 1 ), /* isImmediate */
      UINT8_C( 0 )  /* isDefined */
    },
    UINT8_C( 0 )  /* mode */
  },
  { /* BswMBswModeNotification_DcmEcuReset */
    { /* base */
      UINT16_C( 4 ), /* id */
      UINT8_C( 0 ), /* isImmediate */
      UINT8_C( 0 )  /* isDefined */
    },
    UINT8_C( 5 )  /* mode */
  },
  { /* BswMBswModeNotification_DcmCommunicationControl */
    { /* base */
      UINT16_C( 5 ), /* id */
      UINT8_C( 0 ), /* isImmediate */
      UINT8_C( 0 )  /* isDefined */
    },
    UINT8_C( 0 )  /* mode */
  }
};

/**
 * BswMCanSMIndication_OsApplication_C0_PortTable
 */
BswMModeRequestPortType BswMCanSMIndication_OsApplication_C0_PortTable[2] = 
{
  { /* [0] */
    { /* base */
      UINT16_C( 1 ), /* id */
      UINT8_C( 0 ), /* isImmediate */
      UINT8_C( 0 )  /* isDefined */
    },
    0U, /* channel */
    UINT8_C( 0 )  /* mode */
  },
  { /* [1] */
    { /* base */
      UINT16_C( 2 ), /* id */
      UINT8_C( 0 ), /* isImmediate */
      UINT8_C( 0 )  /* isDefined */
    },
    1U, /* channel */
    UINT8_C( 0 )  /* mode */
  }
};

/**
 * BswMEcuMWakeupSource_OsApplication_C0_PortTable
 */
BswMModeRequestPortType BswMEcuMWakeupSource_OsApplication_C0_PortTable[1] = 
{
  { /* [0] */
    { /* base */
      UINT16_C( 3 ), /* id */
      UINT8_C( 1 ), /* isImmediate */
      UINT8_C( 0 )  /* isDefined */
    },
    EcuMConf_EcuMWakeupSource_ECUM_WKSOURCE_PUBLIC_CAN, /* channel */
    UINT8_C( 0 )  /* mode */
  }
};

/**
 * BswMGenericRequest_OsApplication_C0_PortTable
 */
BswMGenericRequestPortType BswMGenericRequest_OsApplication_C0_PortTable[1] = 
{
  { /* [0] */
    { /* base */
      UINT16_C( 0 ), /* id */
      UINT8_C( 0 ), /* isImmediate */
      UINT8_C( 0 )  /* isDefined */
    },
    UINT16_C( 0 ), /* channel */
    UINT16_C( 0 )  /* mode */
  }
};

#define BSWM_1_OsApplication_C0_STOP_SEC_VAR_INIT_UNSPECIFIED
#include <BswM_1_OsApplication_C0_MemMap.h>

#define BSWM_1_OsApplication_C0_START_SEC_CONST_UNSPECIFIED
#include <BswM_1_OsApplication_C0_MemMap.h>
/**
 * BswM_OsApplication_C0_PtrModeRequestPortsTable
 */
STATIC CONSTP2VAR( BswMModeRequestPortType, BSWM_CONST, BSWM_VAR ) BswM_OsApplication_C0_PtrModeRequestPortsTable[13] = 
{
  &BswMCanSMIndication_OsApplication_C0_PortTable[0], /* BSWM_CAN_SM_INDICATION */
  NULL_PTR, /* BSWM_COMM_INDICATION */
  NULL_PTR, /* BSWM_COMM_INITIATE_RESET */
  NULL_PTR, /* BSWM_COMM_PNC_REQUEST */
  NULL_PTR, /* BSWM_DCM_APPLICATION_UPDATED_INDICATION */
  NULL_PTR, /* BSWM_DCM_COM_MODE_CURRENT_STATE */
  NULL_PTR, /* BSWM_DCM_COM_MODE_REQUEST */
  NULL_PTR, /* BSWM_DCM_RESET_MODE_REQUEST */
  NULL_PTR, /* BSWM_DCM_SESSION_MODE_REQUEST */
  NULL_PTR, /* BSWM_ECUM_INDICATION */
  &BswMEcuMWakeupSource_OsApplication_C0_PortTable[0], /* BSWM_ECUM_WAKEUP_SOURCE */
  NULL_PTR, /* BSWM_GENERIC_REQUEST */
  NULL_PTR  /* BSWM_NM_CAR_WAKEUP_INDICATION */
};

#define BSWM_1_OsApplication_C0_STOP_SEC_CONST_UNSPECIFIED
#include <BswM_1_OsApplication_C0_MemMap.h>

/*==================[external data]=========================================*/

#define BSWM_1_OsApplication_C0_START_SEC_VAR_INIT_UNSPECIFIED
#include <BswM_1_OsApplication_C0_MemMap.h>
/**
 * BswM_OsApplication_C0_LinkTimeContext
 */
STATIC BswM_LinkTimeContextType BswM_OsApplication_C0_LinkTimeContext = 
{
  &BswM_OsApplication_C0_ExprGetState, /* logicalExprGetStateFuncPtr */
  &BswM_OsApplication_C0_ExprGetResult, /* logicalExprGetResultFuncPtr */
  &BswM_OsApplication_C0_ExecuteAction, /* executeActionFuncPtr */
  &BswM_OsApplication_C0_HandleStaticRequest, /* handleStaticRequestFuncPtr */
  &BswMGenericRequest_OsApplication_C0_PortTable[0], /* genericRequestPortsTablePtr */
  UINT16_C( 1 ), /* numBswMGenericRequestPorts */
  UINT16_C( 27 )  /* numBswMExpressions */
};

/**
 * BswM_OsApplication_C0_Context
 */
BswM_PartitionContextType BswM_OsApplication_C0_Context = 
{
  &SchM_Enter_BswM_1_OsApplication_C0_SCHM_BSWM_EXCLUSIVE_AREA, /* SchMEnter */
  &SchM_Exit_BswM_1_OsApplication_C0_SCHM_BSWM_EXCLUSIVE_AREA, /* SchMExit */
  &BswM_OsApplication_C0_LinkTimeContext, /* LinkTimeContext */
  { /* RunTimeContext */
    { /* IPduGroupReInitVector */
      UINT8_C( 0 ), /* [0] */
      UINT8_C( 0 ), /* [1] */
      UINT8_C( 0 ), /* [2] */
      UINT8_C( 0 )  /* [3] */
    },
    { /* IPduGroupVector */
      UINT8_C( 0 ), /* [0] */
      UINT8_C( 0 ), /* [1] */
      UINT8_C( 0 ), /* [2] */
      UINT8_C( 0 )  /* [3] */
    },
    { /* RuleResultTable */
      UINT8_C( 0 ), /* [0] */
      UINT8_C( 0 ), /* [1] */
      UINT8_C( 0 ), /* [2] */
      UINT8_C( 0 ), /* [3] */
      UINT8_C( 0 ), /* [4] */
      UINT8_C( 0 ), /* [5] */
      UINT8_C( 0 ), /* [6] */
      UINT8_C( 0 ), /* [7] */
      UINT8_C( 0 ), /* [8] */
      UINT8_C( 0 ), /* [9] */
      UINT8_C( 0 ), /* [10] */
      UINT8_C( 0 ), /* [11] */
      UINT8_C( 0 ), /* [12] */
      UINT8_C( 0 ), /* [13] */
      UINT8_C( 0 ), /* [14] */
      UINT8_C( 0 ), /* [15] */
      UINT8_C( 0 ), /* [16] */
      UINT8_C( 0 ), /* [17] */
      UINT8_C( 0 ), /* [18] */
      UINT8_C( 0 ), /* [19] */
      UINT8_C( 0 ), /* [20] */
      UINT8_C( 0 ), /* [21] */
      UINT8_C( 0 ), /* [22] */
      UINT8_C( 0 ), /* [23] */
      UINT8_C( 0 ), /* [24] */
      UINT8_C( 0 ), /* [25] */
      UINT8_C( 0 ), /* [26] */
      UINT8_C( 0 ), /* [27] */
      UINT8_C( 0 ), /* [28] */
      UINT8_C( 0 ), /* [29] */
      UINT8_C( 0 ), /* [30] */
      UINT8_C( 0 ), /* [31] */
      UINT8_C( 0 ), /* [32] */
      UINT8_C( 0 ), /* [33] */
      UINT8_C( 0 ), /* [34] */
      UINT8_C( 0 ), /* [35] */
      UINT8_C( 0 ), /* [36] */
      UINT8_C( 0 ), /* [37] */
      UINT8_C( 0 ), /* [38] */
      UINT8_C( 0 ), /* [39] */
      UINT8_C( 0 ), /* [40] */
      UINT8_C( 0 ), /* [41] */
      UINT8_C( 0 ), /* [42] */
      UINT8_C( 0 ), /* [43] */
      UINT8_C( 0 ), /* [44] */
      UINT8_C( 0 ), /* [45] */
      UINT8_C( 0 ), /* [46] */
      UINT8_C( 0 ), /* [47] */
      UINT8_C( 0 ), /* [48] */
      UINT8_C( 0 ), /* [49] */
      UINT8_C( 0 ), /* [50] */
      UINT8_C( 0 ), /* [51] */
      UINT8_C( 0 ), /* [52] */
      UINT8_C( 0 ), /* [53] */
      UINT8_C( 0 ), /* [54] */
      UINT8_C( 0 ), /* [55] */
      UINT8_C( 0 ), /* [56] */
      UINT8_C( 0 ), /* [57] */
      UINT8_C( 0 ), /* [58] */
      UINT8_C( 0 ), /* [59] */
      UINT8_C( 0 ), /* [60] */
      UINT8_C( 0 ), /* [61] */
      UINT8_C( 0 ), /* [62] */
      UINT8_C( 0 ), /* [63] */
      UINT8_C( 0 ), /* [64] */
      UINT8_C( 0 ), /* [65] */
      UINT8_C( 0 ), /* [66] */
      UINT8_C( 0 ), /* [67] */
      UINT8_C( 0 ), /* [68] */
      UINT8_C( 0 ), /* [69] */
      UINT8_C( 0 ), /* [70] */
      UINT8_C( 0 ), /* [71] */
      UINT8_C( 0 ), /* [72] */
      UINT8_C( 0 ), /* [73] */
      UINT8_C( 0 ), /* [74] */
      UINT8_C( 0 ), /* [75] */
      UINT8_C( 0 ), /* [76] */
      UINT8_C( 0 ), /* [77] */
      UINT8_C( 0 ), /* [78] */
      UINT8_C( 0 )  /* [79] */
    },
    { /* LogicalExprInitStatus */
      UINT8_C( 0 ), /* [0] */
      UINT8_C( 0 ), /* [1] */
      UINT8_C( 0 ), /* [2] */
      UINT8_C( 0 ), /* [3] */
      UINT8_C( 0 ), /* [4] */
      UINT8_C( 0 ), /* [5] */
      UINT8_C( 0 ), /* [6] */
      UINT8_C( 0 ), /* [7] */
      UINT8_C( 0 ), /* [8] */
      UINT8_C( 0 ), /* [9] */
      UINT8_C( 0 ), /* [10] */
      UINT8_C( 0 ), /* [11] */
      UINT8_C( 0 ), /* [12] */
      UINT8_C( 0 ), /* [13] */
      UINT8_C( 0 ), /* [14] */
      UINT8_C( 0 ), /* [15] */
      UINT8_C( 0 ), /* [16] */
      UINT8_C( 0 ), /* [17] */
      UINT8_C( 0 ), /* [18] */
      UINT8_C( 0 ), /* [19] */
      UINT8_C( 0 ), /* [20] */
      UINT8_C( 0 ), /* [21] */
      UINT8_C( 0 ), /* [22] */
      UINT8_C( 0 ), /* [23] */
      UINT8_C( 0 ), /* [24] */
      UINT8_C( 0 ), /* [25] */
      UINT8_C( 0 )  /* [26] */
    },
    UINT8_C( 0 ), /* IsInitialized */
    UINT8_C( 0 ), /* PduGroupSwitchTriggered */
    UINT8_C( 0 )  /* PduGroupSwitchReInitTriggered */
  },
  UINT8_C( 0 )  /* ID */
};

#define BSWM_1_OsApplication_C0_STOP_SEC_VAR_INIT_UNSPECIFIED
#include <BswM_1_OsApplication_C0_MemMap.h>

/*==================[external function definitions]=========================*/

#define BswM_OsApplication_C0_START_SEC_CODE
#include <BswM_OsApplication_C0_MemMap.h>

FUNC(void, BswM_OsApplication_C0_CODE) BswM_1_OsApplication_C0_MRPFunc_BswMSwcModeNotification_Comco_RxReq(void)
{
  if (TRUE == BswM_OsApplication_C0_Context.RunTimeContext.IsInitialized)
  {
    uint8 prevMode;
    uint8 nextMode;
    (void)Rte_Mode_ModeNotificationPort_BswMSwcModeNotification_Comco_RxReq_proto_MDG_IPduGroupSwitch(&prevMode, &nextMode);
    BswM_HandleRequest(&BswM_OsApplication_C0_Context, &BswM_OsApplication_C0_UInt8RteRequestPortTable[0], nextMode, BSWM_ARBITRATION_RTE_PORT_UINT8, BSWM_SID_INVALID, BswM_OsApplication_C0_UInt8RteRequestPortTable[0].base.isImmediate);
  }
  else
  {
    /* No arbitration shall be performed if BswM is not initialized */
  }
}
FUNC(void, BswM_OsApplication_C0_CODE) BswM_1_OsApplication_C0_MRPFunc_BswMSwcModeNotification_Comco_TxReq(void)
{
  if (TRUE == BswM_OsApplication_C0_Context.RunTimeContext.IsInitialized)
  {
    uint8 prevMode;
    uint8 nextMode;
    (void)Rte_Mode_ModeNotificationPort_BswMSwcModeNotification_Comco_TxReq_proto_MDG_IPduGroupSwitch(&prevMode, &nextMode);
    BswM_HandleRequest(&BswM_OsApplication_C0_Context, &BswM_OsApplication_C0_UInt8RteRequestPortTable[1], nextMode, BSWM_ARBITRATION_RTE_PORT_UINT8, BSWM_SID_INVALID, BswM_OsApplication_C0_UInt8RteRequestPortTable[1].base.isImmediate);
  }
  else
  {
    /* No arbitration shall be performed if BswM is not initialized */
  }
}

#define BswM_OsApplication_C0_STOP_SEC_CODE
#include <BswM_OsApplication_C0_MemMap.h>

#define BSWM_1_OsApplication_C0_START_SEC_CODE
#include <BswM_1_OsApplication_C0_MemMap.h>

/*
 *  The declaration of this function is provided by the Rte.
 */
/* !LINKSTO BswM.Impl.Api.BswM_MainFunction_Partition,1 */
FUNC(void, BSWM_1_OsApplication_C0_CODE) BswM_1_OsApplication_C0_MainFunction(void)
{
  BswM_MainFunction();
}

STATIC FUNC(void, BSWM_CODE) BswM_OsApplication_C0_InitRteModeRequestPorts(void)
{
  {
    BswM_IndexType i;
    for ( i = 0; i < 4U; i++)
    {
      uint16 table_index = BswM_OsApplication_C0_InitialValueMappings[BswM_OsApplication_C0_UInt8RteRequestPortTable[i].base.id];
      if (table_index != BSWM_INVALID_INITIAL_VALUE_INDEX)
      {
        BswM_OsApplication_C0_UInt8RteRequestPortTable[i].mode = BSWM_GET_UINT8_INITIAL_VALUES_TABLE(BswM_OsApplication_C0_Context.ID)[table_index];
        BswM_OsApplication_C0_UInt8RteRequestPortTable[i].base.isDefined = TRUE;
      }
      else
      {
        BswM_OsApplication_C0_UInt8RteRequestPortTable[i].base.isDefined = FALSE;
      }
    }
  }

}

FUNC(void, BSWM_CODE) BswM_LT_OsApplication_C0_Init(void)
{
  DBG_BSWM_LT_OSAPPLICATION_C0_INIT_ENTRY();

  BswM_OsApplication_C0_InitRteModeRequestPorts();

  {
    BswM_IndexType i,j;
    for (i = 0U; i < 13U; i++)
    {
      BswMModeRequestPortType* arrPtr = BswM_OsApplication_C0_PtrModeRequestPortsTable[i];
      if ( arrPtr != NULL_PTR)
      {
        for (j = 0U; j < BswM_OsApplication_C0_NumModeRequestPortsTable[i]; j++)
        {
          uint16 table_index = BswM_OsApplication_C0_InitialValueMappings[arrPtr[j].base.id];
          if (table_index != BSWM_INVALID_INITIAL_VALUE_INDEX)
          {
            arrPtr[j].mode = BSWM_GET_UINT8_INITIAL_VALUES_TABLE(BswM_OsApplication_C0_Context.ID)[table_index];
            arrPtr[j].base.isDefined = TRUE;
          }
          else
          {
            arrPtr[j].base.isDefined = FALSE;
          }
        }
      }
    }
  }

  {
    BswM_IndexType i;
    for (i = 0U; i < BswM_OsApplication_C0_NumModeRequestPortsTable[BSWM_GENERIC_REQUEST]; i++)
    {
      uint16 table_index = BswM_OsApplication_C0_InitialValueMappings[BswMGenericRequest_OsApplication_C0_PortTable[i].base.id];
      if (table_index != BSWM_INVALID_INITIAL_VALUE_INDEX)
      {
        BswMGenericRequest_OsApplication_C0_PortTable[i].mode = BSWM_GET_UINT16_INITIAL_VALUES_TABLE(BswM_OsApplication_C0_Context.ID)[table_index];
        BswMGenericRequest_OsApplication_C0_PortTable[i].base.isDefined = TRUE;
      }
      else
      {
        BswMGenericRequest_OsApplication_C0_PortTable[i].base.isDefined = FALSE;
      }
    }
  }

  /* !LINKSTO SWS_BswM_00251,1 */

  DBG_BSWM_LT_OSAPPLICATION_C0_INIT_EXIT();
}

FUNC(void, BSWM_1_OsApplication_C0_CODE) BswM_1_OsApplication_C0_MRPFunc_BswMBswModeNotification_DcmEcuReset_NONE(void)
{
  if (TRUE == BswM_OsApplication_C0_Context.RunTimeContext.IsInitialized)
  {
    BswM_HandleRequest(&BswM_OsApplication_C0_Context, &BswM_OsApplication_C0_UInt8RteRequestPortTable[2], RTE_MODE_DcmEcuReset_NONE, BSWM_ARBITRATION_RTE_PORT_UINT8, BSWM_SID_INVALID, BswM_OsApplication_C0_UInt8RteRequestPortTable[2].base.isImmediate);
  }
  else
  {
    /* No arbitration shall be performed if BswM is not initialized */
  }
}
FUNC(void, BSWM_1_OsApplication_C0_CODE) BswM_1_OsApplication_C0_MRPFunc_BswMBswModeNotification_DcmEcuReset_HARD(void)
{
  if (TRUE == BswM_OsApplication_C0_Context.RunTimeContext.IsInitialized)
  {
    BswM_HandleRequest(&BswM_OsApplication_C0_Context, &BswM_OsApplication_C0_UInt8RteRequestPortTable[2], RTE_MODE_DcmEcuReset_HARD, BSWM_ARBITRATION_RTE_PORT_UINT8, BSWM_SID_INVALID, BswM_OsApplication_C0_UInt8RteRequestPortTable[2].base.isImmediate);
  }
  else
  {
    /* No arbitration shall be performed if BswM is not initialized */
  }
}
FUNC(void, BSWM_1_OsApplication_C0_CODE) BswM_1_OsApplication_C0_MRPFunc_BswMBswModeNotification_DcmEcuReset_KEYONOFF(void)
{
  if (TRUE == BswM_OsApplication_C0_Context.RunTimeContext.IsInitialized)
  {
    BswM_HandleRequest(&BswM_OsApplication_C0_Context, &BswM_OsApplication_C0_UInt8RteRequestPortTable[2], RTE_MODE_DcmEcuReset_KEYONOFF, BSWM_ARBITRATION_RTE_PORT_UINT8, BSWM_SID_INVALID, BswM_OsApplication_C0_UInt8RteRequestPortTable[2].base.isImmediate);
  }
  else
  {
    /* No arbitration shall be performed if BswM is not initialized */
  }
}
FUNC(void, BSWM_1_OsApplication_C0_CODE) BswM_1_OsApplication_C0_MRPFunc_BswMBswModeNotification_DcmEcuReset_SOFT(void)
{
  if (TRUE == BswM_OsApplication_C0_Context.RunTimeContext.IsInitialized)
  {
    BswM_HandleRequest(&BswM_OsApplication_C0_Context, &BswM_OsApplication_C0_UInt8RteRequestPortTable[2], RTE_MODE_DcmEcuReset_SOFT, BSWM_ARBITRATION_RTE_PORT_UINT8, BSWM_SID_INVALID, BswM_OsApplication_C0_UInt8RteRequestPortTable[2].base.isImmediate);
  }
  else
  {
    /* No arbitration shall be performed if BswM is not initialized */
  }
}
FUNC(void, BSWM_1_OsApplication_C0_CODE) BswM_1_OsApplication_C0_MRPFunc_BswMBswModeNotification_DcmEcuReset_JUMPTOBOOTLOADER(void)
{
  if (TRUE == BswM_OsApplication_C0_Context.RunTimeContext.IsInitialized)
  {
    BswM_HandleRequest(&BswM_OsApplication_C0_Context, &BswM_OsApplication_C0_UInt8RteRequestPortTable[2], RTE_MODE_DcmEcuReset_JUMPTOBOOTLOADER, BSWM_ARBITRATION_RTE_PORT_UINT8, BSWM_SID_INVALID, BswM_OsApplication_C0_UInt8RteRequestPortTable[2].base.isImmediate);
  }
  else
  {
    /* No arbitration shall be performed if BswM is not initialized */
  }
}
FUNC(void, BSWM_1_OsApplication_C0_CODE) BswM_1_OsApplication_C0_MRPFunc_BswMBswModeNotification_DcmEcuReset_JUMPTOSYSSUPPLIERBOOTLOADER(void)
{
  if (TRUE == BswM_OsApplication_C0_Context.RunTimeContext.IsInitialized)
  {
    BswM_HandleRequest(&BswM_OsApplication_C0_Context, &BswM_OsApplication_C0_UInt8RteRequestPortTable[2], RTE_MODE_DcmEcuReset_JUMPTOSYSSUPPLIERBOOTLOADER, BSWM_ARBITRATION_RTE_PORT_UINT8, BSWM_SID_INVALID, BswM_OsApplication_C0_UInt8RteRequestPortTable[2].base.isImmediate);
  }
  else
  {
    /* No arbitration shall be performed if BswM is not initialized */
  }
}
FUNC(void, BSWM_1_OsApplication_C0_CODE) BswM_1_OsApplication_C0_MRPFunc_BswMBswModeNotification_DcmEcuReset_EXECUTE(void)
{
  if (TRUE == BswM_OsApplication_C0_Context.RunTimeContext.IsInitialized)
  {
    BswM_HandleRequest(&BswM_OsApplication_C0_Context, &BswM_OsApplication_C0_UInt8RteRequestPortTable[2], RTE_MODE_DcmEcuReset_EXECUTE, BSWM_ARBITRATION_RTE_PORT_UINT8, BSWM_SID_INVALID, BswM_OsApplication_C0_UInt8RteRequestPortTable[2].base.isImmediate);
  }
  else
  {
    /* No arbitration shall be performed if BswM is not initialized */
  }
}
FUNC(void, BSWM_1_OsApplication_C0_CODE) BswM_1_OsApplication_C0_MRPFunc_BswMBswModeNotification_DcmCommunicationControl_DCM_ENABLE_RX_TX_NORM(void)
{
  if (TRUE == BswM_OsApplication_C0_Context.RunTimeContext.IsInitialized)
  {
    BswM_HandleRequest(&BswM_OsApplication_C0_Context, &BswM_OsApplication_C0_UInt8RteRequestPortTable[3], RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_TX_NORM, BSWM_ARBITRATION_RTE_PORT_UINT8, BSWM_SID_INVALID, BswM_OsApplication_C0_UInt8RteRequestPortTable[3].base.isImmediate);
  }
  else
  {
    /* No arbitration shall be performed if BswM is not initialized */
  }
}
FUNC(void, BSWM_1_OsApplication_C0_CODE) BswM_1_OsApplication_C0_MRPFunc_BswMBswModeNotification_DcmCommunicationControl_DCM_ENABLE_RX_DISABLE_TX_NORM(void)
{
  if (TRUE == BswM_OsApplication_C0_Context.RunTimeContext.IsInitialized)
  {
    BswM_HandleRequest(&BswM_OsApplication_C0_Context, &BswM_OsApplication_C0_UInt8RteRequestPortTable[3], RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_DISABLE_TX_NORM, BSWM_ARBITRATION_RTE_PORT_UINT8, BSWM_SID_INVALID, BswM_OsApplication_C0_UInt8RteRequestPortTable[3].base.isImmediate);
  }
  else
  {
    /* No arbitration shall be performed if BswM is not initialized */
  }
}
FUNC(void, BSWM_1_OsApplication_C0_CODE) BswM_1_OsApplication_C0_MRPFunc_BswMBswModeNotification_DcmCommunicationControl_DCM_DISABLE_RX_ENABLE_TX_NORM(void)
{
  if (TRUE == BswM_OsApplication_C0_Context.RunTimeContext.IsInitialized)
  {
    BswM_HandleRequest(&BswM_OsApplication_C0_Context, &BswM_OsApplication_C0_UInt8RteRequestPortTable[3], RTE_MODE_DcmCommunicationControl_DCM_DISABLE_RX_ENABLE_TX_NORM, BSWM_ARBITRATION_RTE_PORT_UINT8, BSWM_SID_INVALID, BswM_OsApplication_C0_UInt8RteRequestPortTable[3].base.isImmediate);
  }
  else
  {
    /* No arbitration shall be performed if BswM is not initialized */
  }
}
FUNC(void, BSWM_1_OsApplication_C0_CODE) BswM_1_OsApplication_C0_MRPFunc_BswMBswModeNotification_DcmCommunicationControl_DCM_DISABLE_RX_TX_NORM(void)
{
  if (TRUE == BswM_OsApplication_C0_Context.RunTimeContext.IsInitialized)
  {
    BswM_HandleRequest(&BswM_OsApplication_C0_Context, &BswM_OsApplication_C0_UInt8RteRequestPortTable[3], RTE_MODE_DcmCommunicationControl_DCM_DISABLE_RX_TX_NORM, BSWM_ARBITRATION_RTE_PORT_UINT8, BSWM_SID_INVALID, BswM_OsApplication_C0_UInt8RteRequestPortTable[3].base.isImmediate);
  }
  else
  {
    /* No arbitration shall be performed if BswM is not initialized */
  }
}
FUNC(void, BSWM_1_OsApplication_C0_CODE) BswM_1_OsApplication_C0_MRPFunc_BswMBswModeNotification_DcmCommunicationControl_DCM_ENABLE_RX_TX_NM(void)
{
  if (TRUE == BswM_OsApplication_C0_Context.RunTimeContext.IsInitialized)
  {
    BswM_HandleRequest(&BswM_OsApplication_C0_Context, &BswM_OsApplication_C0_UInt8RteRequestPortTable[3], RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_TX_NM, BSWM_ARBITRATION_RTE_PORT_UINT8, BSWM_SID_INVALID, BswM_OsApplication_C0_UInt8RteRequestPortTable[3].base.isImmediate);
  }
  else
  {
    /* No arbitration shall be performed if BswM is not initialized */
  }
}
FUNC(void, BSWM_1_OsApplication_C0_CODE) BswM_1_OsApplication_C0_MRPFunc_BswMBswModeNotification_DcmCommunicationControl_DCM_ENABLE_RX_DISABLE_TX_NM(void)
{
  if (TRUE == BswM_OsApplication_C0_Context.RunTimeContext.IsInitialized)
  {
    BswM_HandleRequest(&BswM_OsApplication_C0_Context, &BswM_OsApplication_C0_UInt8RteRequestPortTable[3], RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_DISABLE_TX_NM, BSWM_ARBITRATION_RTE_PORT_UINT8, BSWM_SID_INVALID, BswM_OsApplication_C0_UInt8RteRequestPortTable[3].base.isImmediate);
  }
  else
  {
    /* No arbitration shall be performed if BswM is not initialized */
  }
}
FUNC(void, BSWM_1_OsApplication_C0_CODE) BswM_1_OsApplication_C0_MRPFunc_BswMBswModeNotification_DcmCommunicationControl_DCM_DISABLE_RX_ENABLE_TX_NM(void)
{
  if (TRUE == BswM_OsApplication_C0_Context.RunTimeContext.IsInitialized)
  {
    BswM_HandleRequest(&BswM_OsApplication_C0_Context, &BswM_OsApplication_C0_UInt8RteRequestPortTable[3], RTE_MODE_DcmCommunicationControl_DCM_DISABLE_RX_ENABLE_TX_NM, BSWM_ARBITRATION_RTE_PORT_UINT8, BSWM_SID_INVALID, BswM_OsApplication_C0_UInt8RteRequestPortTable[3].base.isImmediate);
  }
  else
  {
    /* No arbitration shall be performed if BswM is not initialized */
  }
}
FUNC(void, BSWM_1_OsApplication_C0_CODE) BswM_1_OsApplication_C0_MRPFunc_BswMBswModeNotification_DcmCommunicationControl_DCM_DISABLE_RX_TX_NM(void)
{
  if (TRUE == BswM_OsApplication_C0_Context.RunTimeContext.IsInitialized)
  {
    BswM_HandleRequest(&BswM_OsApplication_C0_Context, &BswM_OsApplication_C0_UInt8RteRequestPortTable[3], RTE_MODE_DcmCommunicationControl_DCM_DISABLE_RX_TX_NM, BSWM_ARBITRATION_RTE_PORT_UINT8, BSWM_SID_INVALID, BswM_OsApplication_C0_UInt8RteRequestPortTable[3].base.isImmediate);
  }
  else
  {
    /* No arbitration shall be performed if BswM is not initialized */
  }
}
FUNC(void, BSWM_1_OsApplication_C0_CODE) BswM_1_OsApplication_C0_MRPFunc_BswMBswModeNotification_DcmCommunicationControl_DCM_ENABLE_RX_TX_NORM_NM(void)
{
  if (TRUE == BswM_OsApplication_C0_Context.RunTimeContext.IsInitialized)
  {
    BswM_HandleRequest(&BswM_OsApplication_C0_Context, &BswM_OsApplication_C0_UInt8RteRequestPortTable[3], RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_TX_NORM_NM, BSWM_ARBITRATION_RTE_PORT_UINT8, BSWM_SID_INVALID, BswM_OsApplication_C0_UInt8RteRequestPortTable[3].base.isImmediate);
  }
  else
  {
    /* No arbitration shall be performed if BswM is not initialized */
  }
}
FUNC(void, BSWM_1_OsApplication_C0_CODE) BswM_1_OsApplication_C0_MRPFunc_BswMBswModeNotification_DcmCommunicationControl_DCM_ENABLE_RX_DISABLE_TX_NORM_NM(void)
{
  if (TRUE == BswM_OsApplication_C0_Context.RunTimeContext.IsInitialized)
  {
    BswM_HandleRequest(&BswM_OsApplication_C0_Context, &BswM_OsApplication_C0_UInt8RteRequestPortTable[3], RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_DISABLE_TX_NORM_NM, BSWM_ARBITRATION_RTE_PORT_UINT8, BSWM_SID_INVALID, BswM_OsApplication_C0_UInt8RteRequestPortTable[3].base.isImmediate);
  }
  else
  {
    /* No arbitration shall be performed if BswM is not initialized */
  }
}
FUNC(void, BSWM_1_OsApplication_C0_CODE) BswM_1_OsApplication_C0_MRPFunc_BswMBswModeNotification_DcmCommunicationControl_DCM_DISABLE_RX_ENABLE_TX_NORM_NM(void)
{
  if (TRUE == BswM_OsApplication_C0_Context.RunTimeContext.IsInitialized)
  {
    BswM_HandleRequest(&BswM_OsApplication_C0_Context, &BswM_OsApplication_C0_UInt8RteRequestPortTable[3], RTE_MODE_DcmCommunicationControl_DCM_DISABLE_RX_ENABLE_TX_NORM_NM, BSWM_ARBITRATION_RTE_PORT_UINT8, BSWM_SID_INVALID, BswM_OsApplication_C0_UInt8RteRequestPortTable[3].base.isImmediate);
  }
  else
  {
    /* No arbitration shall be performed if BswM is not initialized */
  }
}
FUNC(void, BSWM_1_OsApplication_C0_CODE) BswM_1_OsApplication_C0_MRPFunc_BswMBswModeNotification_DcmCommunicationControl_DCM_DISABLE_RX_TX_NORM_NM(void)
{
  if (TRUE == BswM_OsApplication_C0_Context.RunTimeContext.IsInitialized)
  {
    BswM_HandleRequest(&BswM_OsApplication_C0_Context, &BswM_OsApplication_C0_UInt8RteRequestPortTable[3], RTE_MODE_DcmCommunicationControl_DCM_DISABLE_RX_TX_NORM_NM, BSWM_ARBITRATION_RTE_PORT_UINT8, BSWM_SID_INVALID, BswM_OsApplication_C0_UInt8RteRequestPortTable[3].base.isImmediate);
  }
  else
  {
    /* No arbitration shall be performed if BswM is not initialized */
  }
}

/*==================[internal function definitions]=========================*/

/* INDENT:OFF */
STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_OsApplication_C0_BswM_LogEx_StartupTwoA(void)
{
  return
  (
    (BswMGenericRequest_OsApplication_C0_PortTable[0U].mode == EB_INTGR_BSWM_STARTUP_TWO_A)
  ) ? BSWM_TRUE : BSWM_FALSE;
}

STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_OsApplication_C0_BswM_LogEx_RunTwo(void)
{
  return
  (
    (BswMGenericRequest_OsApplication_C0_PortTable[0U].mode == EB_INTGR_BSWM_RUN_TWO)
  ) ? BSWM_TRUE : BSWM_FALSE;
}

STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_OsApplication_C0_BswM_LogEx_GoOffOneA(void)
{
  return
  (
    (BswMGenericRequest_OsApplication_C0_PortTable[0U].mode == EB_INTGR_BSWM_GO_OFF_ONE_A)
  ) ? BSWM_TRUE : BSWM_FALSE;
}

STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_OsApplication_C0_BswM_LogEx_GoOffOneB(void)
{
  return
  (
    (BswMGenericRequest_OsApplication_C0_PortTable[0U].mode == EB_INTGR_BSWM_GO_OFF_ONE_B)
  ) ? BSWM_TRUE : BSWM_FALSE;
}

STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_OsApplication_C0_BswM_LogEx_StartupTwoB(void)
{
  return
  (
    (BswMGenericRequest_OsApplication_C0_PortTable[0U].mode == EB_INTGR_BSWM_STARTUP_TWO_B) &&
    (BswMCanSMIndication_OsApplication_C0_PortTable[0U].mode == CANSM_BSWM_NO_COMMUNICATION)
  ) ? BSWM_TRUE : BSWM_FALSE;
}

STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_OsApplication_C0_BswM_LogEx_Prep_Shutdown(void)
{
  return
  (
    (BswMGenericRequest_OsApplication_C0_PortTable[0U].mode == EB_INTGR_BSWM_SWC_CYCLIC_SHUTDOWN)
  ) ? BSWM_TRUE : BSWM_FALSE;
}

STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_OsApplication_C0_BswM_LogEx_CanSmNoCom_PublicCan(void)
{
  return
  (
    (BswMCanSMIndication_OsApplication_C0_PortTable[0U].mode == CANSM_BSWM_NO_COMMUNICATION)
  ) ? BSWM_TRUE : BSWM_FALSE;
}

STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_OsApplication_C0_BswM_LogEx_CanSmSilentCom_PublicCan(void)
{
  return
  (
    (BswMCanSMIndication_OsApplication_C0_PortTable[0U].mode == CANSM_BSWM_SILENT_COMMUNICATION)
  ) ? BSWM_TRUE : BSWM_FALSE;
}

STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_OsApplication_C0_BswM_LogEx_CanSmBusoff_PublicCan(void)
{
  return
  (
    (BswMCanSMIndication_OsApplication_C0_PortTable[0U].mode == CANSM_BSWM_BUS_OFF)
  ) ? BSWM_TRUE : BSWM_FALSE;
}

STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_OsApplication_C0_BswM_LogEx_CanSmFullCom_PublicCan(void)
{
  return
  (
    (BswMCanSMIndication_OsApplication_C0_PortTable[0U].mode == CANSM_BSWM_FULL_COMMUNICATION)
  ) ? BSWM_TRUE : BSWM_FALSE;
}

STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_OsApplication_C0_BswM_LogEx_CanSmNoCom_PrivateCan(void)
{
  return
  (
    (BswMCanSMIndication_OsApplication_C0_PortTable[1U].mode == CANSM_BSWM_NO_COMMUNICATION)
  ) ? BSWM_TRUE : BSWM_FALSE;
}

STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_OsApplication_C0_BswM_LogEx_CanSmSilentCom_PrivateCan(void)
{
  return
  (
    (BswMCanSMIndication_OsApplication_C0_PortTable[1U].mode == CANSM_BSWM_SILENT_COMMUNICATION)
  ) ? BSWM_TRUE : BSWM_FALSE;
}

STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_OsApplication_C0_BswM_LogEx_CanSmBusoff_PrivateCan(void)
{
  return
  (
    (BswMCanSMIndication_OsApplication_C0_PortTable[1U].mode == CANSM_BSWM_BUS_OFF)
  ) ? BSWM_TRUE : BSWM_FALSE;
}

STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_OsApplication_C0_BswM_LogEx_CanSmFullCom_PrivateCan(void)
{
  return
  (
    (BswMCanSMIndication_OsApplication_C0_PortTable[1U].mode == CANSM_BSWM_FULL_COMMUNICATION)
  ) ? BSWM_TRUE : BSWM_FALSE;
}

STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_OsApplication_C0_BswM_LogEx_WakupValidation_PublicCan(void)
{
  return
  (
    (BswMEcuMWakeupSource_OsApplication_C0_PortTable[0U].mode == ECUM_WKSTATUS_VALIDATED)
  ) ? BSWM_TRUE : BSWM_FALSE;
}

STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_OsApplication_C0_BswM_LogEx_Dcm_280301_DisRxTx_Norm(void)
{
  return
  (
    (BswM_OsApplication_C0_UInt8RteRequestPortTable[3].mode == RTE_MODE_DcmCommunicationControl_DCM_DISABLE_RX_TX_NORM)
  ) ? BSWM_TRUE : BSWM_FALSE;
}

STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_OsApplication_C0_BswM_LogEx_Dcm_280001_EnRxTx_Norm(void)
{
  return
  (
    (BswM_OsApplication_C0_UInt8RteRequestPortTable[3].mode == RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_TX_NORM)
  ) ? BSWM_TRUE : BSWM_FALSE;
}

STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_OsApplication_C0_BswM_LogEx_Dcm_280302_DisRxTx_NM(void)
{
  return
  (
    (BswM_OsApplication_C0_UInt8RteRequestPortTable[3].mode == RTE_MODE_DcmCommunicationControl_DCM_DISABLE_RX_TX_NM)
  ) ? BSWM_TRUE : BSWM_FALSE;
}

STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_OsApplication_C0_BswM_LogEx_Dcm_280002_EnRxTx_NM(void)
{
  return
  (
    (BswM_OsApplication_C0_UInt8RteRequestPortTable[3].mode == RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_TX_NM)
  ) ? BSWM_TRUE : BSWM_FALSE;
}

STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_OsApplication_C0_BswM_LogEx_Dcm_280303_DisRxTx_Norm_NM(void)
{
  return
  (
    (BswM_OsApplication_C0_UInt8RteRequestPortTable[3].mode == RTE_MODE_DcmCommunicationControl_DCM_DISABLE_RX_TX_NORM_NM)
  ) ? BSWM_TRUE : BSWM_FALSE;
}

STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_OsApplication_C0_BswM_LogEx_Dcm_280003_EnRxTx_Norm_NM(void)
{
  return
  (
    (BswM_OsApplication_C0_UInt8RteRequestPortTable[3].mode == RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_TX_NORM_NM)
  ) ? BSWM_TRUE : BSWM_FALSE;
}

STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_OsApplication_C0_BswM_LogEx_Comco_PduRxReq(void)
{
  return
  (
    (BswM_OsApplication_C0_UInt8RteRequestPortTable[0].mode == RTE_MODE_BSWM_MDG_IPduGroupSwitch_PDU_GROUP_START)
  ) ? BSWM_TRUE : BSWM_FALSE;
}

STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_OsApplication_C0_BswM_LogEx_Comco_PduTxReq(void)
{
  return
  (
    (BswM_OsApplication_C0_UInt8RteRequestPortTable[1].mode == RTE_MODE_BSWM_MDG_IPduGroupSwitch_PDU_GROUP_START)
  ) ? BSWM_TRUE : BSWM_FALSE;
}

STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_OsApplication_C0_BswM_LogEx_Dcm_EcuReset_EXECUTE(void)
{
  return
  (
    (BswM_OsApplication_C0_UInt8RteRequestPortTable[2].mode == RTE_MODE_DcmEcuReset_EXECUTE)
  ) ? BSWM_TRUE : BSWM_FALSE;
}

STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_OsApplication_C0_BswM_LogEx_Dcm_EcuReset_HARD(void)
{
  return
  (
    (BswM_OsApplication_C0_UInt8RteRequestPortTable[2].mode == RTE_MODE_DcmEcuReset_HARD)
  ) ? BSWM_TRUE : BSWM_FALSE;
}

STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_OsApplication_C0_BswM_LogEx_Dcm_EcuReset_SOFT(void)
{
  return
  (
    (BswM_OsApplication_C0_UInt8RteRequestPortTable[2].mode == RTE_MODE_DcmEcuReset_SOFT)
  ) ? BSWM_TRUE : BSWM_FALSE;
}

STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_OsApplication_C0_BswM_LogEx_Dcm_EcuReset_JUMPTOSYSSUPPLIERBOOTLOADER(void)
{
  return
  (
    (BswM_OsApplication_C0_UInt8RteRequestPortTable[2].mode == RTE_MODE_DcmEcuReset_JUMPTOSYSSUPPLIERBOOTLOADER)
  ) ? BSWM_TRUE : BSWM_FALSE;
}

STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_OsApplication_C0_BswM_LogEx_StartupTwoA(void)
{
  return
  (
    (TRUE == BswMGenericRequest_OsApplication_C0_PortTable[0U].base.isDefined)
  ) ? TRUE : FALSE;
}

STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_OsApplication_C0_BswM_LogEx_RunTwo(void)
{
  return
  (
    (TRUE == BswMGenericRequest_OsApplication_C0_PortTable[0U].base.isDefined)
  ) ? TRUE : FALSE;
}

STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_OsApplication_C0_BswM_LogEx_GoOffOneA(void)
{
  return
  (
    (TRUE == BswMGenericRequest_OsApplication_C0_PortTable[0U].base.isDefined)
  ) ? TRUE : FALSE;
}

STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_OsApplication_C0_BswM_LogEx_GoOffOneB(void)
{
  return
  (
    (TRUE == BswMGenericRequest_OsApplication_C0_PortTable[0U].base.isDefined)
  ) ? TRUE : FALSE;
}

STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_OsApplication_C0_BswM_LogEx_StartupTwoB(void)
{
  return
  (
    (TRUE == BswMGenericRequest_OsApplication_C0_PortTable[0U].base.isDefined) && 
    (TRUE == BswMCanSMIndication_OsApplication_C0_PortTable[0U].base.isDefined)
  ) ? TRUE : FALSE;
}

STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_OsApplication_C0_BswM_LogEx_Prep_Shutdown(void)
{
  return
  (
    (TRUE == BswMGenericRequest_OsApplication_C0_PortTable[0U].base.isDefined)
  ) ? TRUE : FALSE;
}

STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_OsApplication_C0_BswM_LogEx_CanSmNoCom_PublicCan(void)
{
  return
  (
    (TRUE == BswMCanSMIndication_OsApplication_C0_PortTable[0U].base.isDefined)
  ) ? TRUE : FALSE;
}

STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_OsApplication_C0_BswM_LogEx_CanSmSilentCom_PublicCan(void)
{
  return
  (
    (TRUE == BswMCanSMIndication_OsApplication_C0_PortTable[0U].base.isDefined)
  ) ? TRUE : FALSE;
}

STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_OsApplication_C0_BswM_LogEx_CanSmBusoff_PublicCan(void)
{
  return
  (
    (TRUE == BswMCanSMIndication_OsApplication_C0_PortTable[0U].base.isDefined)
  ) ? TRUE : FALSE;
}

STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_OsApplication_C0_BswM_LogEx_CanSmFullCom_PublicCan(void)
{
  return
  (
    (TRUE == BswMCanSMIndication_OsApplication_C0_PortTable[0U].base.isDefined)
  ) ? TRUE : FALSE;
}

STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_OsApplication_C0_BswM_LogEx_CanSmNoCom_PrivateCan(void)
{
  return
  (
    (TRUE == BswMCanSMIndication_OsApplication_C0_PortTable[1U].base.isDefined)
  ) ? TRUE : FALSE;
}

STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_OsApplication_C0_BswM_LogEx_CanSmSilentCom_PrivateCan(void)
{
  return
  (
    (TRUE == BswMCanSMIndication_OsApplication_C0_PortTable[1U].base.isDefined)
  ) ? TRUE : FALSE;
}

STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_OsApplication_C0_BswM_LogEx_CanSmBusoff_PrivateCan(void)
{
  return
  (
    (TRUE == BswMCanSMIndication_OsApplication_C0_PortTable[1U].base.isDefined)
  ) ? TRUE : FALSE;
}

STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_OsApplication_C0_BswM_LogEx_CanSmFullCom_PrivateCan(void)
{
  return
  (
    (TRUE == BswMCanSMIndication_OsApplication_C0_PortTable[1U].base.isDefined)
  ) ? TRUE : FALSE;
}

STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_OsApplication_C0_BswM_LogEx_WakupValidation_PublicCan(void)
{
  return
  (
    (TRUE == BswMEcuMWakeupSource_OsApplication_C0_PortTable[0U].base.isDefined)
  ) ? TRUE : FALSE;
}

STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_OsApplication_C0_BswM_LogEx_Dcm_280301_DisRxTx_Norm(void)
{
  return
  (
    (TRUE == BswM_OsApplication_C0_UInt8RteRequestPortTable[3].base.isDefined)
  ) ? TRUE : FALSE;
}

STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_OsApplication_C0_BswM_LogEx_Dcm_280001_EnRxTx_Norm(void)
{
  return
  (
    (TRUE == BswM_OsApplication_C0_UInt8RteRequestPortTable[3].base.isDefined)
  ) ? TRUE : FALSE;
}

STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_OsApplication_C0_BswM_LogEx_Dcm_280302_DisRxTx_NM(void)
{
  return
  (
    (TRUE == BswM_OsApplication_C0_UInt8RteRequestPortTable[3].base.isDefined)
  ) ? TRUE : FALSE;
}

STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_OsApplication_C0_BswM_LogEx_Dcm_280002_EnRxTx_NM(void)
{
  return
  (
    (TRUE == BswM_OsApplication_C0_UInt8RteRequestPortTable[3].base.isDefined)
  ) ? TRUE : FALSE;
}

STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_OsApplication_C0_BswM_LogEx_Dcm_280303_DisRxTx_Norm_NM(void)
{
  return
  (
    (TRUE == BswM_OsApplication_C0_UInt8RteRequestPortTable[3].base.isDefined)
  ) ? TRUE : FALSE;
}

STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_OsApplication_C0_BswM_LogEx_Dcm_280003_EnRxTx_Norm_NM(void)
{
  return
  (
    (TRUE == BswM_OsApplication_C0_UInt8RteRequestPortTable[3].base.isDefined)
  ) ? TRUE : FALSE;
}

STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_OsApplication_C0_BswM_LogEx_Comco_PduRxReq(void)
{
  return
  (
    (TRUE == BswM_OsApplication_C0_UInt8RteRequestPortTable[0].base.isDefined)
  ) ? TRUE : FALSE;
}

STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_OsApplication_C0_BswM_LogEx_Comco_PduTxReq(void)
{
  return
  (
    (TRUE == BswM_OsApplication_C0_UInt8RteRequestPortTable[1].base.isDefined)
  ) ? TRUE : FALSE;
}

STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_OsApplication_C0_BswM_LogEx_Dcm_EcuReset_EXECUTE(void)
{
  return
  (
    (TRUE == BswM_OsApplication_C0_UInt8RteRequestPortTable[2].base.isDefined)
  ) ? TRUE : FALSE;
}

STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_OsApplication_C0_BswM_LogEx_Dcm_EcuReset_HARD(void)
{
  return
  (
    (TRUE == BswM_OsApplication_C0_UInt8RteRequestPortTable[2].base.isDefined)
  ) ? TRUE : FALSE;
}

STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_OsApplication_C0_BswM_LogEx_Dcm_EcuReset_SOFT(void)
{
  return
  (
    (TRUE == BswM_OsApplication_C0_UInt8RteRequestPortTable[2].base.isDefined)
  ) ? TRUE : FALSE;
}

STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_OsApplication_C0_BswM_LogEx_Dcm_EcuReset_JUMPTOSYSSUPPLIERBOOTLOADER(void)
{
  return
  (
    (TRUE == BswM_OsApplication_C0_UInt8RteRequestPortTable[2].base.isDefined)
  ) ? TRUE : FALSE;
}


/* INDENT:ON */

STATIC FUNC(Std_ReturnType, BSWM_CODE)BswM_Action_OsApplication_C0_BswM_Act_StartupTwoA(void)
{
  DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_STARTUPTWOA_ENTRY();
  (void)Eb_Intgr_BswM_OnStartupTwoA();
  DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_STARTUPTWOA_EXIT();
  return E_OK;
}

STATIC FUNC(Std_ReturnType, BSWM_CODE)BswM_Action_OsApplication_C0_BswM_Act_StartupTwoB(void)
{
  DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_STARTUPTWOB_ENTRY();
  (void)Eb_Intgr_BswM_OnStartupTwoB();
  DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_STARTUPTWOB_EXIT();
  return E_OK;
}

STATIC FUNC(Std_ReturnType, BSWM_CODE)BswM_Action_OsApplication_C0_BswM_Act_RunTwo(void)
{
  DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_RUNTWO_ENTRY();
  (void)Eb_Intgr_BswM_OnRunTwo();
  DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_RUNTWO_EXIT();
  return E_OK;
}

STATIC FUNC(Std_ReturnType, BSWM_CODE)BswM_Action_OsApplication_C0_BswM_Act_RequestRunTwo(void)
{
  DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_REQUESTRUNTWO_ENTRY();
  (void)Eb_Intgr_BswM_CheckRunTwoCondition();
  DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_REQUESTRUNTWO_EXIT();
  return E_OK;
}

STATIC FUNC(Std_ReturnType, BSWM_CODE)BswM_Action_OsApplication_C0_BswM_Act_GoOffOneA(void)
{
  DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_GOOFFONEA_ENTRY();
  (void)Eb_Intgr_BswM_OnGoOffOneA();
  DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_GOOFFONEA_EXIT();
  return E_OK;
}

STATIC FUNC(Std_ReturnType, BSWM_CODE)BswM_Action_OsApplication_C0_BswM_Act_GoOffOneB(void)
{
  DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_GOOFFONEB_ENTRY();
  (void)Eb_Intgr_BswM_OnGoOffOneB();
  DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_GOOFFONEB_EXIT();
  return E_OK;
}

STATIC FUNC(Std_ReturnType, BSWM_CODE)BswM_Action_OsApplication_C0_BswM_Act_RteSwitch_GoOffOneA(void)
{
  Std_ReturnType result;
  DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_RTESWITCH_GOOFFONEA_ENTRY();
  result = Rte_Switch_BswM_ModeSwitchPort_OsApplication_C0_BswMSwitchPort_Rte_CurrentMode(RTE_MODE_BSWM_BswMModeGroup_EB_INTGR_BSWM_GO_OFF_ONE_A);
  DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_RTESWITCH_GOOFFONEA_EXIT(result);
  return result;
}

STATIC FUNC(Std_ReturnType, BSWM_CODE)BswM_Action_OsApplication_C0_BswM_Act_RteSwitch_GoOffOneB(void)
{
  Std_ReturnType result;
  DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_RTESWITCH_GOOFFONEB_ENTRY();
  result = Rte_Switch_BswM_ModeSwitchPort_OsApplication_C0_BswMSwitchPort_Rte_CurrentMode(RTE_MODE_BSWM_BswMModeGroup_EB_INTGR_BSWM_GO_OFF_ONE_B);
  DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_RTESWITCH_GOOFFONEB_EXIT(result);
  return result;
}

STATIC FUNC(Std_ReturnType, BSWM_CODE)BswM_Action_OsApplication_C0_BswM_Act_RteSwitch_RunTwo(void)
{
  Std_ReturnType result;
  DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_RTESWITCH_RUNTWO_ENTRY();
  result = Rte_Switch_BswM_ModeSwitchPort_OsApplication_C0_BswMSwitchPort_Rte_CurrentMode(RTE_MODE_BSWM_BswMModeGroup_EB_INTGR_BSWM_RUN_TWO);
  DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_RTESWITCH_RUNTWO_EXIT(result);
  return result;
}

STATIC FUNC(Std_ReturnType, BSWM_CODE)BswM_Action_OsApplication_C0_BswM_Act_RteSwitch_StartupTwoA(void)
{
  Std_ReturnType result;
  DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_RTESWITCH_STARTUPTWOA_ENTRY();
  result = Rte_Switch_BswM_ModeSwitchPort_OsApplication_C0_BswMSwitchPort_Rte_CurrentMode(RTE_MODE_BSWM_BswMModeGroup_EB_INTGR_BSWM_STARTUP_TWO_A);
  DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_RTESWITCH_STARTUPTWOA_EXIT(result);
  return result;
}

STATIC FUNC(Std_ReturnType, BSWM_CODE)BswM_Action_OsApplication_C0_BswM_Act_RteSwitch_StartupTwoB(void)
{
  Std_ReturnType result;
  DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_RTESWITCH_STARTUPTWOB_ENTRY();
  result = Rte_Switch_BswM_ModeSwitchPort_OsApplication_C0_BswMSwitchPort_Rte_CurrentMode(RTE_MODE_BSWM_BswMModeGroup_EB_INTGR_BSWM_STARTUP_TWO_B);
  DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_RTESWITCH_STARTUPTWOB_EXIT(result);
  return result;
}

STATIC FUNC(Std_ReturnType, BSWM_CODE)BswM_Action_OsApplication_C0_BswM_Act_CanNoComPublicCan(void)
{
  DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_CANNOCOMPUBLICCAN_ENTRY();
  BswM_ExecutePduGroupSwitchAction(&BswM_OsApplication_C0_Context, 0U);
  DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_CANNOCOMPUBLICCAN_EXIT();
  return E_OK;
}

STATIC FUNC(Std_ReturnType, BSWM_CODE)BswM_Action_OsApplication_C0_BswM_Act_CanSilentComPublicCan(void)
{
  DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_CANSILENTCOMPUBLICCAN_ENTRY();
  BswM_ExecutePduGroupSwitchAction(&BswM_OsApplication_C0_Context, 1U);
  DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_CANSILENTCOMPUBLICCAN_EXIT();
  return E_OK;
}

STATIC FUNC(Std_ReturnType, BSWM_CODE)BswM_Action_OsApplication_C0_BswM_Act_CanFullComPublicCan(void)
{
  DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_CANFULLCOMPUBLICCAN_ENTRY();
  BswM_ExecutePduGroupSwitchAction(&BswM_OsApplication_C0_Context, 2U);
  DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_CANFULLCOMPUBLICCAN_EXIT();
  return E_OK;
}

STATIC FUNC(Std_ReturnType, BSWM_CODE)BswM_Action_OsApplication_C0_BswM_Act_PrepShutdown(void)
{
  DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_PREPSHUTDOWN_ENTRY();
  (void)Eb_Intgr_BswM_OnPrpShutdown();
  DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_PREPSHUTDOWN_EXIT();
  return E_OK;
}

STATIC FUNC(Std_ReturnType, BSWM_CODE)BswM_Action_OsApplication_C0_BswM_Act_RteSwitch_PrpShutdown(void)
{
  Std_ReturnType result;
  DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_RTESWITCH_PRPSHUTDOWN_ENTRY();
  result = Rte_Switch_BswM_ModeSwitchPort_OsApplication_C0_BswMSwitchPort_Rte_CurrentMode(RTE_MODE_BSWM_BswMModeGroup_EB_INTGR_BSWM_PRP_SHUTDOWN);
  DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_RTESWITCH_PRPSHUTDOWN_EXIT(result);
  return result;
}

STATIC FUNC(Std_ReturnType, BSWM_CODE)BswM_Action_OsApplication_C0_BswM_Act_CanNoComPrivateCan(void)
{
  DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_CANNOCOMPRIVATECAN_ENTRY();
  BswM_ExecutePduGroupSwitchAction(&BswM_OsApplication_C0_Context, 3U);
  DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_CANNOCOMPRIVATECAN_EXIT();
  return E_OK;
}

STATIC FUNC(Std_ReturnType, BSWM_CODE)BswM_Action_OsApplication_C0_BswM_Act_CanSilentComPrivateCan(void)
{
  DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_CANSILENTCOMPRIVATECAN_ENTRY();
  BswM_ExecutePduGroupSwitchAction(&BswM_OsApplication_C0_Context, 4U);
  DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_CANSILENTCOMPRIVATECAN_EXIT();
  return E_OK;
}

STATIC FUNC(Std_ReturnType, BSWM_CODE)BswM_Action_OsApplication_C0_BswM_Act_CanFullComPrivateCan(void)
{
  DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_CANFULLCOMPRIVATECAN_ENTRY();
  BswM_ExecutePduGroupSwitchAction(&BswM_OsApplication_C0_Context, 5U);
  DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_CANFULLCOMPRIVATECAN_EXIT();
  return E_OK;
}

STATIC FUNC(Std_ReturnType, BSWM_CODE)BswM_Action_OsApplication_C0_BswMAction_WakupValidation_PublicCan(void)
{
  DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWMACTION_WAKUPVALIDATION_PUBLICCAN_ENTRY();
  (void)BswM_RequestMode(EB_INTGR_BSWM_BSWM_SM, EB_INTGR_BSWM_RUN_TWO);
  DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWMACTION_WAKUPVALIDATION_PUBLICCAN_EXIT();
  return E_OK;
}

STATIC FUNC(Std_ReturnType, BSWM_CODE)BswM_Action_OsApplication_C0_BswM_Act_STARTUP_TWO_D(void)
{
  Std_ReturnType result;
  DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_STARTUP_TWO_D_ENTRY();
  result = SchM_Switch_BswM_1_OsApplication_C0_BswM_ModeSwitchPort_OsApplication_C0_BswMSwitchPort_Master(RTE_MODE_BSWM_ModeGroupCrossCore_BSWM_STARTUP_TWO_D);
  DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_STARTUP_TWO_D_EXIT(result);
  return result;
}

STATIC FUNC(Std_ReturnType, BSWM_CODE)BswM_Action_OsApplication_C0_BswM_Act_GO_OFF_ONE_D(void)
{
  Std_ReturnType result;
  DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_GO_OFF_ONE_D_ENTRY();
  result = SchM_Switch_BswM_1_OsApplication_C0_BswM_ModeSwitchPort_OsApplication_C0_BswMSwitchPort_Master(RTE_MODE_BSWM_ModeGroupCrossCore_BSWM_GO_OFF_ONE_D);
  DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_GO_OFF_ONE_D_EXIT(result);
  return result;
}

STATIC FUNC(Std_ReturnType, BSWM_CODE)BswM_Action_OsApplication_C0_Act_Dcm_0x280301_DisRxTx_Norm(void)
{
  DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_DCM_0X280301_DISRXTX_NORM_ENTRY();
  BswM_ExecutePduGroupSwitchAction(&BswM_OsApplication_C0_Context, 6U);
  DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_DCM_0X280301_DISRXTX_NORM_EXIT();
  return E_OK;
}

STATIC FUNC(Std_ReturnType, BSWM_CODE)BswM_Action_OsApplication_C0_Act_Dcm_0x280001_EnRxTx_Norm(void)
{
  DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_DCM_0X280001_ENRXTX_NORM_ENTRY();
  BswM_ExecutePduGroupSwitchAction(&BswM_OsApplication_C0_Context, 7U);
  DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_DCM_0X280001_ENRXTX_NORM_EXIT();
  return E_OK;
}

STATIC FUNC(Std_ReturnType, BSWM_CODE)BswM_Action_OsApplication_C0_Act_Dcm_0x280302_DisRxTx_NM(void)
{
  Std_ReturnType result;
  DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_DCM_0X280302_DISRXTX_NM_ENTRY();
  result = (Nm_DisableCommunication(0) == E_OK) ? E_OK : E_NOT_OK;
  DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_DCM_0X280302_DISRXTX_NM_EXIT(result);
  return result;
}

STATIC FUNC(Std_ReturnType, BSWM_CODE)BswM_Action_OsApplication_C0_Act_Dcm_0x280002_EnRxTx_NM(void)
{
  Std_ReturnType result;
  DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_DCM_0X280002_ENRXTX_NM_ENTRY();
  result = (Nm_EnableCommunication(0) == E_OK) ? E_OK : E_NOT_OK;
  DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_DCM_0X280002_ENRXTX_NM_EXIT(result);
  return result;
}

STATIC FUNC(Std_ReturnType, BSWM_CODE)BswM_Action_OsApplication_C0_Act_UserCallout_Comco_Init(void)
{
  DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_USERCALLOUT_COMCO_INIT_ENTRY();
  (void)Comco_Init();
  DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_USERCALLOUT_COMCO_INIT_EXIT();
  return E_OK;
}

STATIC FUNC(Std_ReturnType, BSWM_CODE)BswM_Action_OsApplication_C0_Act_Comco_Pdu_RxGroup_Active(void)
{
  DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_COMCO_PDU_RXGROUP_ACTIVE_ENTRY();
  BswM_ExecutePduGroupSwitchAction(&BswM_OsApplication_C0_Context, 8U);
  DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_COMCO_PDU_RXGROUP_ACTIVE_EXIT();
  return E_OK;
}

STATIC FUNC(Std_ReturnType, BSWM_CODE)BswM_Action_OsApplication_C0_Act_Comco_Pdu_RxGroup_InActive(void)
{
  DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_COMCO_PDU_RXGROUP_INACTIVE_ENTRY();
  BswM_ExecutePduGroupSwitchAction(&BswM_OsApplication_C0_Context, 9U);
  DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_COMCO_PDU_RXGROUP_INACTIVE_EXIT();
  return E_OK;
}

STATIC FUNC(Std_ReturnType, BSWM_CODE)BswM_Action_OsApplication_C0_Act_Comco_Pdu_TxGroup_Active(void)
{
  DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_COMCO_PDU_TXGROUP_ACTIVE_ENTRY();
  BswM_ExecutePduGroupSwitchAction(&BswM_OsApplication_C0_Context, 10U);
  DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_COMCO_PDU_TXGROUP_ACTIVE_EXIT();
  return E_OK;
}

STATIC FUNC(Std_ReturnType, BSWM_CODE)BswM_Action_OsApplication_C0_Act_Comco_Pdu_TxGroup_InActive(void)
{
  DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_COMCO_PDU_TXGROUP_INACTIVE_ENTRY();
  BswM_ExecutePduGroupSwitchAction(&BswM_OsApplication_C0_Context, 11U);
  DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_COMCO_PDU_TXGROUP_INACTIVE_EXIT();
  return E_OK;
}

STATIC FUNC(Std_ReturnType, BSWM_CODE)BswM_Action_OsApplication_C0_Act_Dcm_EcuReset_EXECUTE(void)
{
  DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_DCM_ECURESET_EXECUTE_ENTRY();
  (void)Dsm_v_EcuReset();
  DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_DCM_ECURESET_EXECUTE_EXIT();
  return E_OK;
}

STATIC FUNC(Std_ReturnType, BSWM_CODE)BswM_Action_OsApplication_C0_Act_Dcm_EcuReset_HARD(void)
{
  DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_DCM_ECURESET_HARD_ENTRY();
  (void)Dsm_v_HardReset_CallBack();
  DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_DCM_ECURESET_HARD_EXIT();
  return E_OK;
}

STATIC FUNC(Std_ReturnType, BSWM_CODE)BswM_Action_OsApplication_C0_Act_Dcm_EcuReset_SOFT(void)
{
  DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_DCM_ECURESET_SOFT_ENTRY();
  (void)Dsm_v_SoftReset_CallBack();
  DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_DCM_ECURESET_SOFT_EXIT();
  return E_OK;
}

STATIC FUNC(Std_ReturnType, BSWM_CODE)BswM_Action_OsApplication_C0_Act_Dcm_EcuReset_JUMPTOSYSSUPPLIERBOOTLOADER(void)
{
  DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_DCM_ECURESET_JUMPTOSYSSUPPLIERBOOTLOADER_ENTRY();
  (void)Dsm_v_ProgrammingReset_CallBack();
  DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_DCM_ECURESET_JUMPTOSYSSUPPLIERBOOTLOADER_EXIT();
  return E_OK;
}

STATIC FUNC(Std_ReturnType, BSWM_CODE)BswM_Action_OsApplication_C0_Act_RteSwitch_CanSMStatePublic_Busoff(void)
{
  Std_ReturnType result;
  DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_RTESWITCH_CANSMSTATEPUBLIC_BUSOFF_ENTRY();
  result = Rte_Switch_BswM_ModeSwitchPort_OsApplication_C0_CanSMState_PublicCan_proto_CANSM_ModeGroup(RTE_MODE_BSWM_CANSM_ModeGroup_CANSM_BSWM_BUS_OFF);
  DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_RTESWITCH_CANSMSTATEPUBLIC_BUSOFF_EXIT(result);
  return result;
}

STATIC FUNC(Std_ReturnType, BSWM_CODE)BswM_Action_OsApplication_C0_Act_RteSwitch_CanSMStatePublic_FullCom(void)
{
  Std_ReturnType result;
  DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_RTESWITCH_CANSMSTATEPUBLIC_FULLCOM_ENTRY();
  result = Rte_Switch_BswM_ModeSwitchPort_OsApplication_C0_CanSMState_PublicCan_proto_CANSM_ModeGroup(RTE_MODE_BSWM_CANSM_ModeGroup_CANSM_BSWM_FULL_COMMUNICATION);
  DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_RTESWITCH_CANSMSTATEPUBLIC_FULLCOM_EXIT(result);
  return result;
}

STATIC FUNC(Std_ReturnType, BSWM_CODE)BswM_Action_OsApplication_C0_Act_RteSwitch_CanSMStatePublic_SlientCom(void)
{
  Std_ReturnType result;
  DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_RTESWITCH_CANSMSTATEPUBLIC_SLIENTCOM_ENTRY();
  result = Rte_Switch_BswM_ModeSwitchPort_OsApplication_C0_CanSMState_PublicCan_proto_CANSM_ModeGroup(RTE_MODE_BSWM_CANSM_ModeGroup_CANSM_BSWM_SILENT_COMMUNICATION);
  DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_RTESWITCH_CANSMSTATEPUBLIC_SLIENTCOM_EXIT(result);
  return result;
}

STATIC FUNC(Std_ReturnType, BSWM_CODE)BswM_Action_OsApplication_C0_Act_RteSwitch_CanSMStatePublic_NoCom(void)
{
  Std_ReturnType result;
  DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_RTESWITCH_CANSMSTATEPUBLIC_NOCOM_ENTRY();
  result = Rte_Switch_BswM_ModeSwitchPort_OsApplication_C0_CanSMState_PublicCan_proto_CANSM_ModeGroup(RTE_MODE_BSWM_CANSM_ModeGroup_CANSM_BSWM_NO_COMMUNICATION);
  DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_RTESWITCH_CANSMSTATEPUBLIC_NOCOM_EXIT(result);
  return result;
}

STATIC FUNC(Std_ReturnType, BSWM_CODE)BswM_Action_OsApplication_C0_Act_RteSwitch_CanSMStatePrivate_Busoff(void)
{
  Std_ReturnType result;
  DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_RTESWITCH_CANSMSTATEPRIVATE_BUSOFF_ENTRY();
  result = Rte_Switch_BswM_ModeSwitchPort_OsApplication_C0_CanSMState_PrivateCan_proto_CANSM_ModeGroup(RTE_MODE_BSWM_CANSM_ModeGroup_CANSM_BSWM_BUS_OFF);
  DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_RTESWITCH_CANSMSTATEPRIVATE_BUSOFF_EXIT(result);
  return result;
}

STATIC FUNC(Std_ReturnType, BSWM_CODE)BswM_Action_OsApplication_C0_Act_RteSwitch_CanSMStatePrivate_FullCom(void)
{
  Std_ReturnType result;
  DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_RTESWITCH_CANSMSTATEPRIVATE_FULLCOM_ENTRY();
  result = Rte_Switch_BswM_ModeSwitchPort_OsApplication_C0_CanSMState_PrivateCan_proto_CANSM_ModeGroup(RTE_MODE_BSWM_CANSM_ModeGroup_CANSM_BSWM_FULL_COMMUNICATION);
  DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_RTESWITCH_CANSMSTATEPRIVATE_FULLCOM_EXIT(result);
  return result;
}

STATIC FUNC(Std_ReturnType, BSWM_CODE)BswM_Action_OsApplication_C0_Act_RteSwitch_CanSMStatePrivate_SlientCom(void)
{
  Std_ReturnType result;
  DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_RTESWITCH_CANSMSTATEPRIVATE_SLIENTCOM_ENTRY();
  result = Rte_Switch_BswM_ModeSwitchPort_OsApplication_C0_CanSMState_PrivateCan_proto_CANSM_ModeGroup(RTE_MODE_BSWM_CANSM_ModeGroup_CANSM_BSWM_SILENT_COMMUNICATION);
  DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_RTESWITCH_CANSMSTATEPRIVATE_SLIENTCOM_EXIT(result);
  return result;
}

STATIC FUNC(Std_ReturnType, BSWM_CODE)BswM_Action_OsApplication_C0_Act_RteSwitch_CanSMStatePrivate_NoCom(void)
{
  Std_ReturnType result;
  DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_RTESWITCH_CANSMSTATEPRIVATE_NOCOM_ENTRY();
  result = Rte_Switch_BswM_ModeSwitchPort_OsApplication_C0_CanSMState_PrivateCan_proto_CANSM_ModeGroup(RTE_MODE_BSWM_CANSM_ModeGroup_CANSM_BSWM_NO_COMMUNICATION);
  DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_RTESWITCH_CANSMSTATEPRIVATE_NOCOM_EXIT(result);
  return result;
}

STATIC FUNC(Std_ReturnType, BSWM_CODE)BswM_Action_OsApplication_C0_BswM_Act_PrepShutdown_C1(void)
{
  Std_ReturnType result;
  DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_PREPSHUTDOWN_C1_ENTRY();
  result = SchM_Switch_BswM_1_OsApplication_C0_BswM_ModeSwitchPort_OsApplication_C0_BswMSwitchPort_Master(RTE_MODE_BSWM_ModeGroupCrossCore_BSWM_SWC_CYCLIC_SHUTDOWN_C1);
  DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_PREPSHUTDOWN_C1_EXIT(result);
  return result;
}

STATIC FUNC(Std_ReturnType, BSWM_CODE)BswM_Action_OsApplication_C0_Act_RteSwitch_DiagComControl_DisRxTxNorM(void)
{
  Std_ReturnType result;
  DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_RTESWITCH_DIAGCOMCONTROL_DISRXTXNORM_ENTRY();
  result = Rte_Switch_BswM_ModeSwitchPort_OsApplication_C0_BswMSwitchPort_DiagComControlState_proto_DcmCommunicationControl(RTE_MODE_BSWM_DcmCommunicationControl_DCM_DISABLE_RX_TX_NORM);
  DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_RTESWITCH_DIAGCOMCONTROL_DISRXTXNORM_EXIT(result);
  return result;
}

STATIC FUNC(Std_ReturnType, BSWM_CODE)BswM_Action_OsApplication_C0_Act_RteSwitch_DiagComControl_EnRxTxNorM(void)
{
  Std_ReturnType result;
  DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_RTESWITCH_DIAGCOMCONTROL_ENRXTXNORM_ENTRY();
  result = Rte_Switch_BswM_ModeSwitchPort_OsApplication_C0_BswMSwitchPort_DiagComControlState_proto_DcmCommunicationControl(RTE_MODE_BSWM_DcmCommunicationControl_DCM_ENABLE_RX_TX_NORM);
  DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_RTESWITCH_DIAGCOMCONTROL_ENRXTXNORM_EXIT(result);
  return result;
}

STATIC FUNC(Std_ReturnType, BSWM_CODE)BswM_Action_OsApplication_C0_Act_RteSwitch_DiagComControl_EnRxTxNM(void)
{
  Std_ReturnType result;
  DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_RTESWITCH_DIAGCOMCONTROL_ENRXTXNM_ENTRY();
  result = Rte_Switch_BswM_ModeSwitchPort_OsApplication_C0_BswMSwitchPort_DiagComControlState_proto_DcmCommunicationControl(RTE_MODE_BSWM_DcmCommunicationControl_DCM_ENABLE_RX_TX_NM);
  DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_RTESWITCH_DIAGCOMCONTROL_ENRXTXNM_EXIT(result);
  return result;
}

STATIC FUNC(Std_ReturnType, BSWM_CODE)BswM_Action_OsApplication_C0_Act_RteSwitch_DiagComControl_DisRxTxNM(void)
{
  Std_ReturnType result;
  DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_RTESWITCH_DIAGCOMCONTROL_DISRXTXNM_ENTRY();
  result = Rte_Switch_BswM_ModeSwitchPort_OsApplication_C0_BswMSwitchPort_DiagComControlState_proto_DcmCommunicationControl(RTE_MODE_BSWM_DcmCommunicationControl_DCM_DISABLE_RX_TX_NM);
  DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_RTESWITCH_DIAGCOMCONTROL_DISRXTXNM_EXIT(result);
  return result;
}

STATIC FUNC(Std_ReturnType, BSWM_CODE)BswM_Action_OsApplication_C0_Act_RteSwitch_DiagComControl_EnRxTxNorM_NM(void)
{
  Std_ReturnType result;
  DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_RTESWITCH_DIAGCOMCONTROL_ENRXTXNORM_NM_ENTRY();
  result = Rte_Switch_BswM_ModeSwitchPort_OsApplication_C0_BswMSwitchPort_DiagComControlState_proto_DcmCommunicationControl(RTE_MODE_BSWM_DcmCommunicationControl_DCM_ENABLE_RX_TX_NORM_NM);
  DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_RTESWITCH_DIAGCOMCONTROL_ENRXTXNORM_NM_EXIT(result);
  return result;
}

STATIC FUNC(Std_ReturnType, BSWM_CODE)BswM_Action_OsApplication_C0_Act_RteSwitch_DiagComControl_DisRxTxNorM_NM(void)
{
  Std_ReturnType result;
  DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_RTESWITCH_DIAGCOMCONTROL_DISRXTXNORM_NM_ENTRY();
  result = Rte_Switch_BswM_ModeSwitchPort_OsApplication_C0_BswMSwitchPort_DiagComControlState_proto_DcmCommunicationControl(RTE_MODE_BSWM_DcmCommunicationControl_DCM_DISABLE_RX_TX_NORM_NM);
  DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_RTESWITCH_DIAGCOMCONTROL_DISRXTXNORM_NM_EXIT(result);
  return result;
}

STATIC FUNC(Std_ReturnType, BSWM_CODE)BswM_Action_OsApplication_C0_Act_PublicCAN_BusOff_Recorvery_Tja1043(void)
{
  DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_PUBLICCAN_BUSOFF_RECORVERY_TJA1043_ENTRY();
  (void)Tja1043_RecorveryFun();
  DBG_BSWM_ACTION_OSAPPLICATION_C0_ACT_PUBLICCAN_BUSOFF_RECORVERY_TJA1043_EXIT();
  return E_OK;
}

STATIC FUNC(BswMResultType, BSWM_CODE) BswM_OsApplication_C0_ExprGetState(uint16 exprIndex)
{
  return BswM_OsApplication_C0_LogicalExprTable[exprIndex].GetState();
}

STATIC FUNC(BswMResultType, BSWM_CODE) BswM_OsApplication_C0_ExprGetResult(uint16 exprIndex)
{
  return BswM_OsApplication_C0_LogicalExprTable[exprIndex].GetResult();
}

STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_OsApplication_C0_ExecuteAction(uint16 actionIndex)
{
  return BswM_OsApplication_C0_ActionTable[actionIndex]();
}

STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_OsApplication_C0_HandleStaticRequest(uint32 channel, uint16 mode, uint8 source, uint8 sid)
{
  if (BswM_OsApplication_C0_Context.RunTimeContext.IsInitialized == TRUE)
  {
    BswMModeRequestPortType* arrPtr = BswM_OsApplication_C0_PtrModeRequestPortsTable[source];
    uint16 i;
    boolean eval;
    for (i= 0U; i < BswM_OsApplication_C0_NumModeRequestPortsTable[source]; i++)
    {
      switch(source)
      {
        case BSWM_ECUM_WAKEUP_SOURCE:
        eval = ((((uint32)1U << arrPtr[i].channel) & channel) != 0U);
        break;
        default:
        eval = (arrPtr[i].channel == channel);
        break;
      }
      if (eval == TRUE)
      {
        BswM_HandleRequest(&BswM_OsApplication_C0_Context, &arrPtr[i], mode, BSWM_ARBITRATION_STATIC_HANDLER_PORT, sid, arrPtr[i].base.isImmediate);
      }
    }
  }
  return E_OK;
}

#define BSWM_1_OsApplication_C0_STOP_SEC_CODE
#include <BswM_1_OsApplication_C0_MemMap.h>

/** @} doxygen end group definition */
/*==================[end of file]===========================================*/
