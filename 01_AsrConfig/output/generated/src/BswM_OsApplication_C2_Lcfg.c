
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

/* tasking Deviation List
 *
 * TASKING-1) Deviated Rule: W549
 * W549: condition is always true
 *
 * Reason:
 * The warning "condition is always true" is a tasking compiler issue (TCVX-41885).
 * If the condition were always true then an infinite loop would occur.
 */
/*==================[inclusions]============================================*/

#include <BswM_Trace.h>       /* Dbg macros */
#include <BswM.h>
#include <BswM_Int_Cfg.h>
#include <BswM_Int.h>
#include <TSMem.h>            /* Used for TS_MemSet */
#include <SchM_BswM_1_OsApplication_C2.h>        /* SchM API for BswM         */

#include <Rte_BswM_OsApplication_C2.h>         /* RTE-generated BswM header */

#include <BswM_OsApplication_C2_Lcfg.h>

/*==================[macros]================================================*/

#define BSWM_INVALID_INITIAL_VALUE_INDEX 0xFFU

/*==================[type definitions]======================================*/

/*==================[internal function declarations]========================*/

/* !LINKSTO BswM.Impl.MemoryMapping.InstanceCode,1 */
#define BSWM_1_OsApplication_C2_START_SEC_CODE
#include <BswM_1_OsApplication_C2_MemMap.h>

STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_OsApplication_C2_BswM_LogEx_StartupTwoC(void);
STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_OsApplication_C2_BswM_LogEx_StartupTwoD(void);
STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_OsApplication_C2_BswM_LogEx_RunTwo(void);
STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_OsApplication_C2_BswM_LogEx_GoOffOneC(void);
STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_OsApplication_C2_BswM_LogEx_GoOffOneD(void);
STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_OsApplication_C2_BswM_LogEx_PrepShutdown(void);

STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_OsApplication_C2_BswM_LogEx_StartupTwoC(void);
STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_OsApplication_C2_BswM_LogEx_StartupTwoD(void);
STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_OsApplication_C2_BswM_LogEx_RunTwo(void);
STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_OsApplication_C2_BswM_LogEx_GoOffOneC(void);
STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_OsApplication_C2_BswM_LogEx_GoOffOneD(void);
STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_OsApplication_C2_BswM_LogEx_PrepShutdown(void);

STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_OsApplication_C2_BswM_Act_StartupTwoC(void);
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_OsApplication_C2_BswM_Act_RunTwo(void);
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_OsApplication_C2_BswM_Act_GoOffOneC(void);
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_OsApplication_C2_BswM_Act_GoOffOneD(void);
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_OsApplication_C2_BswM_Act_PrepShutdown(void);
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_OsApplication_C2_BswM_Act_StartupTwoD(void);

STATIC FUNC(BswMResultType, BSWM_CODE) BswM_OsApplication_C2_ExprGetState(uint16 exprIndex);
STATIC FUNC(BswMResultType, BSWM_CODE) BswM_OsApplication_C2_ExprGetResult(uint16 exprIndex);

STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_OsApplication_C2_ExecuteAction(uint16 actionIndex);

STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_OsApplication_C2_HandleStaticRequest(uint32 channel, uint16 mode, uint8 source, uint8 sid);

STATIC FUNC(void, BSWM_CODE) BswM_OsApplication_C2_InitRteModeRequestPorts(void);

#define BSWM_1_OsApplication_C2_STOP_SEC_CODE
#include <BswM_1_OsApplication_C2_MemMap.h>

/*==================[external function declarations]========================*/

/*==================[internal constants]====================================*/

/*==================[external constants]====================================*/

/*==================[internal data]=========================================*/

#define BSWM_1_OsApplication_C2_START_SEC_CONST_UNSPECIFIED
#include <BswM_1_OsApplication_C2_MemMap.h>

STATIC CONST(uint8, AUTOMATIC) BswM_OsApplication_C2_InitialValueMappings[2] = 
{
  /* BswM_ReqPort */
  0U,
  /* BswMModeRequestPort_Slave */
  0U,
};

/**
 * BswM_OsApplication_C2_NumModeRequestPortsTable
 */
STATIC CONST( uint16 , AUTOMATIC ) BswM_OsApplication_C2_NumModeRequestPortsTable[13] = 
{
  UINT16_C( 0 ), /* Number of ports of type BSWM_CAN_SM_INDICATION */
  UINT16_C( 0 ), /* Number of ports of type BSWM_COMM_INDICATION */
  UINT16_C( 0 ), /* Number of ports of type BSWM_COMM_INITIATE_RESET */
  UINT16_C( 0 ), /* Number of ports of type BSWM_COMM_PNC_REQUEST */
  UINT16_C( 0 ), /* Number of ports of type BSWM_DCM_APPLICATION_UPDATED_INDICATION */
  UINT16_C( 0 ), /* Number of ports of type BSWM_DCM_COM_MODE_CURRENT_STATE */
  UINT16_C( 0 ), /* Number of ports of type BSWM_DCM_COM_MODE_REQUEST */
  UINT16_C( 0 ), /* Number of ports of type BSWM_DCM_RESET_MODE_REQUEST */
  UINT16_C( 0 ), /* Number of ports of type BSWM_DCM_SESSION_MODE_REQUEST */
  UINT16_C( 0 ), /* Number of ports of type BSWM_ECUM_INDICATION */
  UINT16_C( 0 ), /* Number of ports of type BSWM_ECUM_WAKEUP_SOURCE */
  UINT16_C( 1 ), /* Number of ports of type BSWM_GENERIC_REQUEST */
  UINT16_C( 0 )  /* Number of ports of type BSWM_NM_CAR_WAKEUP_INDICATION */
};

/*
 * The logical expressions table contains both the state
 * and the result function pointers for each defined logical
 * expression configured in the current BswM instance.
 */
/**
 * BswM_OsApplication_C2_LogicalExprTable
 */
STATIC CONST( BswMLogicalExprType , AUTOMATIC ) BswM_OsApplication_C2_LogicalExprTable[6] = 
{
  { /* [0] */
    &BswM_ExprState_OsApplication_C2_BswM_LogEx_StartupTwoC, /* GetState */
    &BswM_ExprResult_OsApplication_C2_BswM_LogEx_StartupTwoC  /* GetResult */
  },
  { /* [1] */
    &BswM_ExprState_OsApplication_C2_BswM_LogEx_StartupTwoD, /* GetState */
    &BswM_ExprResult_OsApplication_C2_BswM_LogEx_StartupTwoD  /* GetResult */
  },
  { /* [2] */
    &BswM_ExprState_OsApplication_C2_BswM_LogEx_RunTwo, /* GetState */
    &BswM_ExprResult_OsApplication_C2_BswM_LogEx_RunTwo  /* GetResult */
  },
  { /* [3] */
    &BswM_ExprState_OsApplication_C2_BswM_LogEx_GoOffOneC, /* GetState */
    &BswM_ExprResult_OsApplication_C2_BswM_LogEx_GoOffOneC  /* GetResult */
  },
  { /* [4] */
    &BswM_ExprState_OsApplication_C2_BswM_LogEx_GoOffOneD, /* GetState */
    &BswM_ExprResult_OsApplication_C2_BswM_LogEx_GoOffOneD  /* GetResult */
  },
  { /* [5] */
    &BswM_ExprState_OsApplication_C2_BswM_LogEx_PrepShutdown, /* GetState */
    &BswM_ExprResult_OsApplication_C2_BswM_LogEx_PrepShutdown  /* GetResult */
  }
};

/*
 * The action table contains function pointers to all configured
 * actions within the current BswM instance.
 */
/**
 * BswM_OsApplication_C2_ActionTable
 */
STATIC CONST( BswMActionFuncPtrType , AUTOMATIC ) BswM_OsApplication_C2_ActionTable[6] = 
{
  &BswM_Action_OsApplication_C2_BswM_Act_StartupTwoC, /* [0] */
  &BswM_Action_OsApplication_C2_BswM_Act_RunTwo, /* [1] */
  &BswM_Action_OsApplication_C2_BswM_Act_GoOffOneC, /* [2] */
  &BswM_Action_OsApplication_C2_BswM_Act_GoOffOneD, /* [3] */
  &BswM_Action_OsApplication_C2_BswM_Act_PrepShutdown, /* [4] */
  &BswM_Action_OsApplication_C2_BswM_Act_StartupTwoD  /* [5] */
};

#define BSWM_1_OsApplication_C2_STOP_SEC_CONST_UNSPECIFIED
#include <BswM_1_OsApplication_C2_MemMap.h>

/* !LINKSTO BswM.Impl.MemoryMapping.InstanceData,1 */
#define BSWM_1_OsApplication_C2_START_SEC_VAR_INIT_UNSPECIFIED
#include <BswM_1_OsApplication_C2_MemMap.h>

/* Dynamically Generated Mode Request Ports */
/**
 * BswM_OsApplication_C2_UInt8RteRequestPortTable
 */
STATIC BswMUInt8RteModeRequestPortType BswM_OsApplication_C2_UInt8RteRequestPortTable[1] = 
{
  { /* BswMModeRequestPort_Slave */
    { /* base */
      UINT16_C( 1 ), /* id */
      UINT8_C( 1 ), /* isImmediate */
      UINT8_C( 0 )  /* isDefined */
    },
    UINT8_C( 1 )  /* mode */
  }
};

/**
 * BswMGenericRequest_OsApplication_C2_PortTable
 */
BswMGenericRequestPortType BswMGenericRequest_OsApplication_C2_PortTable[1] = 
{
  { /* [0] */
    { /* base */
      UINT16_C( 0 ), /* id */
      UINT8_C( 1 ), /* isImmediate */
      UINT8_C( 0 )  /* isDefined */
    },
    UINT16_C( 0 ), /* channel */
    UINT16_C( 0 )  /* mode */
  }
};

#define BSWM_1_OsApplication_C2_STOP_SEC_VAR_INIT_UNSPECIFIED
#include <BswM_1_OsApplication_C2_MemMap.h>

#define BSWM_1_OsApplication_C2_START_SEC_CONST_UNSPECIFIED
#include <BswM_1_OsApplication_C2_MemMap.h>
/**
 * BswM_OsApplication_C2_PtrModeRequestPortsTable
 */
STATIC CONSTP2VAR( BswMModeRequestPortType, BSWM_CONST, BSWM_VAR ) BswM_OsApplication_C2_PtrModeRequestPortsTable[13] = 
{
  NULL_PTR, /* BSWM_CAN_SM_INDICATION */
  NULL_PTR, /* BSWM_COMM_INDICATION */
  NULL_PTR, /* BSWM_COMM_INITIATE_RESET */
  NULL_PTR, /* BSWM_COMM_PNC_REQUEST */
  NULL_PTR, /* BSWM_DCM_APPLICATION_UPDATED_INDICATION */
  NULL_PTR, /* BSWM_DCM_COM_MODE_CURRENT_STATE */
  NULL_PTR, /* BSWM_DCM_COM_MODE_REQUEST */
  NULL_PTR, /* BSWM_DCM_RESET_MODE_REQUEST */
  NULL_PTR, /* BSWM_DCM_SESSION_MODE_REQUEST */
  NULL_PTR, /* BSWM_ECUM_INDICATION */
  NULL_PTR, /* BSWM_ECUM_WAKEUP_SOURCE */
  NULL_PTR, /* BSWM_GENERIC_REQUEST */
  NULL_PTR  /* BSWM_NM_CAR_WAKEUP_INDICATION */
};

#define BSWM_1_OsApplication_C2_STOP_SEC_CONST_UNSPECIFIED
#include <BswM_1_OsApplication_C2_MemMap.h>

/*==================[external data]=========================================*/

#define BSWM_1_OsApplication_C2_START_SEC_VAR_INIT_UNSPECIFIED
#include <BswM_1_OsApplication_C2_MemMap.h>
/**
 * BswM_OsApplication_C2_LinkTimeContext
 */
STATIC BswM_LinkTimeContextType BswM_OsApplication_C2_LinkTimeContext = 
{
  &BswM_OsApplication_C2_ExprGetState, /* logicalExprGetStateFuncPtr */
  &BswM_OsApplication_C2_ExprGetResult, /* logicalExprGetResultFuncPtr */
  &BswM_OsApplication_C2_ExecuteAction, /* executeActionFuncPtr */
  &BswM_OsApplication_C2_HandleStaticRequest, /* handleStaticRequestFuncPtr */
  &BswMGenericRequest_OsApplication_C2_PortTable[0], /* genericRequestPortsTablePtr */
  UINT16_C( 1 ), /* numBswMGenericRequestPorts */
  UINT16_C( 6 )  /* numBswMExpressions */
};

/**
 * BswM_OsApplication_C2_Context
 */
BswM_PartitionContextType BswM_OsApplication_C2_Context = 
{
  &SchM_Enter_BswM_1_OsApplication_C2_SCHM_BSWM_EXCLUSIVE_AREA, /* SchMEnter */
  &SchM_Exit_BswM_1_OsApplication_C2_SCHM_BSWM_EXCLUSIVE_AREA, /* SchMExit */
  &BswM_OsApplication_C2_LinkTimeContext, /* LinkTimeContext */
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
  UINT8_C( 2 )  /* ID */
};

#define BSWM_1_OsApplication_C2_STOP_SEC_VAR_INIT_UNSPECIFIED
#include <BswM_1_OsApplication_C2_MemMap.h>

/*==================[external function definitions]=========================*/

#define BswM_OsApplication_C2_START_SEC_CODE
#include <BswM_OsApplication_C2_MemMap.h>

#define BswM_OsApplication_C2_STOP_SEC_CODE
#include <BswM_OsApplication_C2_MemMap.h>

#define BSWM_1_OsApplication_C2_START_SEC_CODE
#include <BswM_1_OsApplication_C2_MemMap.h>

/*
 *  The declaration of this function is provided by the Rte.
 */
/* !LINKSTO BswM.Impl.Api.BswM_MainFunction_Partition,1 */
FUNC(void, BSWM_1_OsApplication_C2_CODE) BswM_1_OsApplication_C2_MainFunction(void)
{
  BswM_MainFunction();
}

STATIC FUNC(void, BSWM_CODE) BswM_OsApplication_C2_InitRteModeRequestPorts(void)
{
  {
    BswM_IndexType i;
    /* Deviation TASKING-1 */
    for ( i = 0; i < 1U; i++)
    {
      uint16 table_index = BswM_OsApplication_C2_InitialValueMappings[BswM_OsApplication_C2_UInt8RteRequestPortTable[i].base.id];
      if (table_index != BSWM_INVALID_INITIAL_VALUE_INDEX)
      {
        BswM_OsApplication_C2_UInt8RteRequestPortTable[i].mode = BSWM_GET_UINT8_INITIAL_VALUES_TABLE(BswM_OsApplication_C2_Context.ID)[table_index];
        BswM_OsApplication_C2_UInt8RteRequestPortTable[i].base.isDefined = TRUE;
      }
      else
      {
        BswM_OsApplication_C2_UInt8RteRequestPortTable[i].base.isDefined = FALSE;
      }
    }
  }

}

FUNC(void, BSWM_CODE) BswM_LT_OsApplication_C2_Init(void)
{
  DBG_BSWM_LT_OSAPPLICATION_C2_INIT_ENTRY();

  BswM_OsApplication_C2_InitRteModeRequestPorts();

  {
    BswM_IndexType i,j;
    for (i = 0U; i < 13U; i++)
    {
      BswMModeRequestPortType* arrPtr = BswM_OsApplication_C2_PtrModeRequestPortsTable[i];
      if ( arrPtr != NULL_PTR)
      {
        for (j = 0U; j < BswM_OsApplication_C2_NumModeRequestPortsTable[i]; j++)
        {
          uint16 table_index = BswM_OsApplication_C2_InitialValueMappings[arrPtr[j].base.id];
          if (table_index != BSWM_INVALID_INITIAL_VALUE_INDEX)
          {
            arrPtr[j].mode = BSWM_GET_UINT8_INITIAL_VALUES_TABLE(BswM_OsApplication_C2_Context.ID)[table_index];
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
    for (i = 0U; i < BswM_OsApplication_C2_NumModeRequestPortsTable[BSWM_GENERIC_REQUEST]; i++)
    {
      uint16 table_index = BswM_OsApplication_C2_InitialValueMappings[BswMGenericRequest_OsApplication_C2_PortTable[i].base.id];
      if (table_index != BSWM_INVALID_INITIAL_VALUE_INDEX)
      {
        BswMGenericRequest_OsApplication_C2_PortTable[i].mode = BSWM_GET_UINT16_INITIAL_VALUES_TABLE(BswM_OsApplication_C2_Context.ID)[table_index];
        BswMGenericRequest_OsApplication_C2_PortTable[i].base.isDefined = TRUE;
      }
      else
      {
        BswMGenericRequest_OsApplication_C2_PortTable[i].base.isDefined = FALSE;
      }
    }
  }

  /* !LINKSTO SWS_BswM_00251,1 */

  DBG_BSWM_LT_OSAPPLICATION_C2_INIT_EXIT();
}

FUNC(void, BSWM_1_OsApplication_C2_CODE) BswM_1_OsApplication_C2_MRPFunc_BswMModeRequestPort_Slave_BSWM_GO_OFF_ONE_D(void)
{
  if (TRUE == BswM_OsApplication_C2_Context.RunTimeContext.IsInitialized)
  {
    BswM_HandleRequest(&BswM_OsApplication_C2_Context, &BswM_OsApplication_C2_UInt8RteRequestPortTable[0], RTE_MODE_BSWM_ModeGroupCrossCore_BSWM_GO_OFF_ONE_D, BSWM_ARBITRATION_RTE_PORT_UINT8, BSWM_SID_INVALID, BswM_OsApplication_C2_UInt8RteRequestPortTable[0].base.isImmediate);
  }
  else
  {
    /* No arbitration shall be performed if BswM is not initialized */
  }
}
FUNC(void, BSWM_1_OsApplication_C2_CODE) BswM_1_OsApplication_C2_MRPFunc_BswMModeRequestPort_Slave_BSWM_STARTUP_TWO_B(void)
{
  if (TRUE == BswM_OsApplication_C2_Context.RunTimeContext.IsInitialized)
  {
    BswM_HandleRequest(&BswM_OsApplication_C2_Context, &BswM_OsApplication_C2_UInt8RteRequestPortTable[0], RTE_MODE_BSWM_ModeGroupCrossCore_BSWM_STARTUP_TWO_B, BSWM_ARBITRATION_RTE_PORT_UINT8, BSWM_SID_INVALID, BswM_OsApplication_C2_UInt8RteRequestPortTable[0].base.isImmediate);
  }
  else
  {
    /* No arbitration shall be performed if BswM is not initialized */
  }
}
FUNC(void, BSWM_1_OsApplication_C2_CODE) BswM_1_OsApplication_C2_MRPFunc_BswMModeRequestPort_Slave_BSWM_STARTUP_TWO_D(void)
{
  if (TRUE == BswM_OsApplication_C2_Context.RunTimeContext.IsInitialized)
  {
    BswM_HandleRequest(&BswM_OsApplication_C2_Context, &BswM_OsApplication_C2_UInt8RteRequestPortTable[0], RTE_MODE_BSWM_ModeGroupCrossCore_BSWM_STARTUP_TWO_D, BSWM_ARBITRATION_RTE_PORT_UINT8, BSWM_SID_INVALID, BswM_OsApplication_C2_UInt8RteRequestPortTable[0].base.isImmediate);
  }
  else
  {
    /* No arbitration shall be performed if BswM is not initialized */
  }
}
FUNC(void, BSWM_1_OsApplication_C2_CODE) BswM_1_OsApplication_C2_MRPFunc_BswMModeRequestPort_Slave_BSWM_SWC_CYCLIC_SHUTDOWN_C1(void)
{
  if (TRUE == BswM_OsApplication_C2_Context.RunTimeContext.IsInitialized)
  {
    BswM_HandleRequest(&BswM_OsApplication_C2_Context, &BswM_OsApplication_C2_UInt8RteRequestPortTable[0], RTE_MODE_BSWM_ModeGroupCrossCore_BSWM_SWC_CYCLIC_SHUTDOWN_C1, BSWM_ARBITRATION_RTE_PORT_UINT8, BSWM_SID_INVALID, BswM_OsApplication_C2_UInt8RteRequestPortTable[0].base.isImmediate);
  }
  else
  {
    /* No arbitration shall be performed if BswM is not initialized */
  }
}

/*==================[internal function definitions]=========================*/

/* INDENT:OFF */
STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_OsApplication_C2_BswM_LogEx_StartupTwoC(void)
{
  return
  (
    (BswMGenericRequest_OsApplication_C2_PortTable[0U].mode == EB_INTGR_BSWM_STARTUP_TWO_C)
  ) ? BSWM_TRUE : BSWM_FALSE;
}

STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_OsApplication_C2_BswM_LogEx_StartupTwoD(void)
{
  return
  (
    (BswM_OsApplication_C2_UInt8RteRequestPortTable[0].mode == RTE_MODE_BSWM_ModeGroupCrossCore_BSWM_STARTUP_TWO_D)
  ) ? BSWM_TRUE : BSWM_FALSE;
}

STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_OsApplication_C2_BswM_LogEx_RunTwo(void)
{
  return
  (
    (BswMGenericRequest_OsApplication_C2_PortTable[0U].mode == EB_INTGR_BSWM_RUN_TWO_SLAVE)
  ) ? BSWM_TRUE : BSWM_FALSE;
}

STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_OsApplication_C2_BswM_LogEx_GoOffOneC(void)
{
  return
  (
    (BswMGenericRequest_OsApplication_C2_PortTable[0U].mode == EB_INTGR_BSWM_GO_OFF_ONE_C)
  ) ? BSWM_TRUE : BSWM_FALSE;
}

STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_OsApplication_C2_BswM_LogEx_GoOffOneD(void)
{
  return
  (
    (BswM_OsApplication_C2_UInt8RteRequestPortTable[0].mode == RTE_MODE_BSWM_ModeGroupCrossCore_BSWM_GO_OFF_ONE_D)
  ) ? BSWM_TRUE : BSWM_FALSE;
}

STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_OsApplication_C2_BswM_LogEx_PrepShutdown(void)
{
  return
  (
    (BswM_OsApplication_C2_UInt8RteRequestPortTable[0].mode == RTE_MODE_BSWM_ModeGroupCrossCore_BSWM_SWC_CYCLIC_SHUTDOWN_C1)
  ) ? BSWM_TRUE : BSWM_FALSE;
}

STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_OsApplication_C2_BswM_LogEx_StartupTwoC(void)
{
  return
  (
    (TRUE == BswMGenericRequest_OsApplication_C2_PortTable[0U].base.isDefined)
  ) ? TRUE : FALSE;
}

STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_OsApplication_C2_BswM_LogEx_StartupTwoD(void)
{
  return
  (
    (TRUE == BswM_OsApplication_C2_UInt8RteRequestPortTable[0].base.isDefined)
  ) ? TRUE : FALSE;
}

STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_OsApplication_C2_BswM_LogEx_RunTwo(void)
{
  return
  (
    (TRUE == BswMGenericRequest_OsApplication_C2_PortTable[0U].base.isDefined)
  ) ? TRUE : FALSE;
}

STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_OsApplication_C2_BswM_LogEx_GoOffOneC(void)
{
  return
  (
    (TRUE == BswMGenericRequest_OsApplication_C2_PortTable[0U].base.isDefined)
  ) ? TRUE : FALSE;
}

STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_OsApplication_C2_BswM_LogEx_GoOffOneD(void)
{
  return
  (
    (TRUE == BswM_OsApplication_C2_UInt8RteRequestPortTable[0].base.isDefined)
  ) ? TRUE : FALSE;
}

STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_OsApplication_C2_BswM_LogEx_PrepShutdown(void)
{
  return
  (
    (TRUE == BswM_OsApplication_C2_UInt8RteRequestPortTable[0].base.isDefined)
  ) ? TRUE : FALSE;
}


/* INDENT:ON */

STATIC FUNC(Std_ReturnType, BSWM_CODE)BswM_Action_OsApplication_C2_BswM_Act_StartupTwoC(void)
{
  DBG_BSWM_ACTION_OSAPPLICATION_C2_BSWM_ACT_STARTUPTWOC_ENTRY();
  (void)Eb_Intgr_BswM_OnStartupTwoC();
  DBG_BSWM_ACTION_OSAPPLICATION_C2_BSWM_ACT_STARTUPTWOC_EXIT();
  return E_OK;
}

STATIC FUNC(Std_ReturnType, BSWM_CODE)BswM_Action_OsApplication_C2_BswM_Act_RunTwo(void)
{
  DBG_BSWM_ACTION_OSAPPLICATION_C2_BSWM_ACT_RUNTWO_ENTRY();
  (void)Eb_Intgr_BswM_OnRunTwo_Slave();
  DBG_BSWM_ACTION_OSAPPLICATION_C2_BSWM_ACT_RUNTWO_EXIT();
  return E_OK;
}

STATIC FUNC(Std_ReturnType, BSWM_CODE)BswM_Action_OsApplication_C2_BswM_Act_GoOffOneC(void)
{
  DBG_BSWM_ACTION_OSAPPLICATION_C2_BSWM_ACT_GOOFFONEC_ENTRY();
  (void)Eb_Intgr_BswM_OnGoOffOneC();
  DBG_BSWM_ACTION_OSAPPLICATION_C2_BSWM_ACT_GOOFFONEC_EXIT();
  return E_OK;
}

STATIC FUNC(Std_ReturnType, BSWM_CODE)BswM_Action_OsApplication_C2_BswM_Act_GoOffOneD(void)
{
  DBG_BSWM_ACTION_OSAPPLICATION_C2_BSWM_ACT_GOOFFONED_ENTRY();
  (void)Eb_Intgr_BswM_OnGoOffOneD();
  DBG_BSWM_ACTION_OSAPPLICATION_C2_BSWM_ACT_GOOFFONED_EXIT();
  return E_OK;
}

STATIC FUNC(Std_ReturnType, BSWM_CODE)BswM_Action_OsApplication_C2_BswM_Act_PrepShutdown(void)
{
  DBG_BSWM_ACTION_OSAPPLICATION_C2_BSWM_ACT_PREPSHUTDOWN_ENTRY();
  (void)Eb_Intgr_BswM_OnPrpShutdown_C1();
  DBG_BSWM_ACTION_OSAPPLICATION_C2_BSWM_ACT_PREPSHUTDOWN_EXIT();
  return E_OK;
}

STATIC FUNC(Std_ReturnType, BSWM_CODE)BswM_Action_OsApplication_C2_BswM_Act_StartupTwoD(void)
{
  DBG_BSWM_ACTION_OSAPPLICATION_C2_BSWM_ACT_STARTUPTWOD_ENTRY();
  (void)Eb_Intgr_BswM_OnStartupTwoD();
  DBG_BSWM_ACTION_OSAPPLICATION_C2_BSWM_ACT_STARTUPTWOD_EXIT();
  return E_OK;
}

STATIC FUNC(BswMResultType, BSWM_CODE) BswM_OsApplication_C2_ExprGetState(uint16 exprIndex)
{
  return BswM_OsApplication_C2_LogicalExprTable[exprIndex].GetState();
}

STATIC FUNC(BswMResultType, BSWM_CODE) BswM_OsApplication_C2_ExprGetResult(uint16 exprIndex)
{
  return BswM_OsApplication_C2_LogicalExprTable[exprIndex].GetResult();
}

STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_OsApplication_C2_ExecuteAction(uint16 actionIndex)
{
  return BswM_OsApplication_C2_ActionTable[actionIndex]();
}

STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_OsApplication_C2_HandleStaticRequest(uint32 channel, uint16 mode, uint8 source, uint8 sid)
{
  if (BswM_OsApplication_C2_Context.RunTimeContext.IsInitialized == TRUE)
  {
    BswMModeRequestPortType* arrPtr = BswM_OsApplication_C2_PtrModeRequestPortsTable[source];
    uint16 i;
    boolean eval;
    for (i= 0U; i < BswM_OsApplication_C2_NumModeRequestPortsTable[source]; i++)
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
        BswM_HandleRequest(&BswM_OsApplication_C2_Context, &arrPtr[i], mode, BSWM_ARBITRATION_STATIC_HANDLER_PORT, sid, arrPtr[i].base.isImmediate);
      }
    }
  }
  return E_OK;
}

#define BSWM_1_OsApplication_C2_STOP_SEC_CODE
#include <BswM_1_OsApplication_C2_MemMap.h>

/** @} doxygen end group definition */
/*==================[end of file]===========================================*/
