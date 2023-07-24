/**
 * \file
 *
 * \brief AUTOSAR FrTp
 *
 * This file contains the implementation of the AUTOSAR
 * module FrTp.
 *
 * \version 4.4.27
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2021 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */
/* Editing futile - file generated by 'make compile' */

#ifndef FRTP_GUARDS_H
#define FRTP_GUARDS_H

#ifdef FRTP_CFG_GET_PTR_TO_CONNECTION
  #error FRTP_CFG_GET_PTR_TO_CONNECTION already defined
#endif

#ifdef FRTP_CFG_GET_PTR_TO_CONNECTION_LIMIT_CONFIG
  #error FRTP_CFG_GET_PTR_TO_CONNECTION_LIMIT_CONFIG already defined
#endif

#ifdef FRTP_CFG_GET_PTR_TO_TXPDU
  #error FRTP_CFG_GET_PTR_TO_TXPDU already defined
#endif

#ifdef FRTP_CFG_GET_TXCONFLOOKUPTABLE
  #error FRTP_CFG_GET_TXCONFLOOKUPTABLE already defined
#endif

#ifdef FRTP_CHNL_RX_ABORT
  #error FRTP_CHNL_RX_ABORT already defined
#endif

#ifdef FRTP_CHNL_RX_ABORT_ML_MISMATCH
  #error FRTP_CHNL_RX_ABORT_ML_MISMATCH already defined
#endif

#ifdef FRTP_CHNL_RX_ABORT_NO_BUFFER
  #error FRTP_CHNL_RX_ABORT_NO_BUFFER already defined
#endif

#ifdef FRTP_CHNL_RX_ABORT_WRONG_SN
  #error FRTP_CHNL_RX_ABORT_WRONG_SN already defined
#endif

#ifdef FRTP_CHNL_RX_ACK
  #error FRTP_CHNL_RX_ACK already defined
#endif

#ifdef FRTP_CHNL_RX_CTS
  #error FRTP_CHNL_RX_CTS already defined
#endif

#ifdef FRTP_CHNL_RX_DATA
  #error FRTP_CHNL_RX_DATA already defined
#endif

#ifdef FRTP_CHNL_RX_IDLE
  #error FRTP_CHNL_RX_IDLE already defined
#endif

#ifdef FRTP_CHNL_RX_OVFL
  #error FRTP_CHNL_RX_OVFL already defined
#endif

#ifdef FRTP_CHNL_RX_RETRY
  #error FRTP_CHNL_RX_RETRY already defined
#endif

#ifdef FRTP_CHNL_RX_STF_RETRY
  #error FRTP_CHNL_RX_STF_RETRY already defined
#endif

#ifdef FRTP_CHNL_RX_WAIT
  #error FRTP_CHNL_RX_WAIT already defined
#endif

#ifdef FRTP_CHNL_RX_WAITTX_MASK
  #error FRTP_CHNL_RX_WAITTX_MASK already defined
#endif

#ifdef FRTP_CHNL_STATE_DIRECTION_MASK
  #error FRTP_CHNL_STATE_DIRECTION_MASK already defined
#endif

#ifdef FRTP_CHNL_STATE_DIRECTION_RX
  #error FRTP_CHNL_STATE_DIRECTION_RX already defined
#endif

#ifdef FRTP_CHNL_STATE_DIRECTION_TX
  #error FRTP_CHNL_STATE_DIRECTION_TX already defined
#endif

#ifdef FRTP_CHNL_STATE_MASK
  #error FRTP_CHNL_STATE_MASK already defined
#endif

#ifdef FRTP_CHNL_SUBSTATE_MASK
  #error FRTP_CHNL_SUBSTATE_MASK already defined
#endif

#ifdef FRTP_CHNL_TX_ABORT_PENDING
  #error FRTP_CHNL_TX_ABORT_PENDING already defined
#endif

#ifdef FRTP_CHNL_TX_DATA
  #error FRTP_CHNL_TX_DATA already defined
#endif

#ifdef FRTP_CHNL_TX_IDLE
  #error FRTP_CHNL_TX_IDLE already defined
#endif

#ifdef FRTP_CHNL_TX_WAIT_ACK
  #error FRTP_CHNL_TX_WAIT_ACK already defined
#endif

#ifdef FRTP_CHNL_TX_WAIT_FC
  #error FRTP_CHNL_TX_WAIT_FC already defined
#endif

#ifdef FRTP_CHNL_TX_WAIT_TX
  #error FRTP_CHNL_TX_WAIT_TX already defined
#endif

#ifdef FRTP_CONNECTION_HASACK
  #error FRTP_CONNECTION_HASACK already defined
#endif

#ifdef FRTP_CONNECTION_HASBCLIMIT
  #error FRTP_CONNECTION_HASBCLIMIT already defined
#endif

#ifdef FRTP_CONNECTION_INVALID
  #error FRTP_CONNECTION_INVALID already defined
#endif

#ifdef FRTP_CONNECTION_ISBROADCAST
  #error FRTP_CONNECTION_ISBROADCAST already defined
#endif

#ifdef FRTP_DET_GENERIC_INSTANCE_ID
  #error FRTP_DET_GENERIC_INSTANCE_ID already defined
#endif

#ifdef FRTP_INIT
  #error FRTP_INIT already defined
#endif

#ifdef FRTP_INSTANCE_ID
  #error FRTP_INSTANCE_ID already defined
#endif

#ifdef FRTP_INTERNAL_API_ID
  #error FRTP_INTERNAL_API_ID already defined
#endif

#ifdef FRTP_INVARIANT_ASSERT
  #error FRTP_INVARIANT_ASSERT already defined
#endif

#ifdef FRTP_INVARIANT_ASSERT_NO_EVAL
  #error FRTP_INVARIANT_ASSERT_NO_EVAL already defined
#endif

#ifdef FRTP_PBCFG_ACCESS
  #error FRTP_PBCFG_ACCESS already defined
#endif

#ifdef FRTP_PCITYPE_ACK_RET_ACK
  #error FRTP_PCITYPE_ACK_RET_ACK already defined
#endif

#ifdef FRTP_PCITYPE_ACK_RET_RETRY
  #error FRTP_PCITYPE_ACK_RET_RETRY already defined
#endif

#ifdef FRTP_PCITYPE_CF1
  #error FRTP_PCITYPE_CF1 already defined
#endif

#ifdef FRTP_PCITYPE_CF2
  #error FRTP_PCITYPE_CF2 already defined
#endif

#ifdef FRTP_PCITYPE_CFI_MASK
  #error FRTP_PCITYPE_CFI_MASK already defined
#endif

#ifdef FRTP_PCITYPE_CF_MASK
  #error FRTP_PCITYPE_CF_MASK already defined
#endif

#ifdef FRTP_PCITYPE_EOB
  #error FRTP_PCITYPE_EOB already defined
#endif

#ifdef FRTP_PCITYPE_FC
  #error FRTP_PCITYPE_FC already defined
#endif

#ifdef FRTP_PCITYPE_FC_ABT
  #error FRTP_PCITYPE_FC_ABT already defined
#endif

#ifdef FRTP_PCITYPE_FC_ACK_RET
  #error FRTP_PCITYPE_FC_ACK_RET already defined
#endif

#ifdef FRTP_PCITYPE_FC_CTS
  #error FRTP_PCITYPE_FC_CTS already defined
#endif

#ifdef FRTP_PCITYPE_FC_OVFLW
  #error FRTP_PCITYPE_FC_OVFLW already defined
#endif

#ifdef FRTP_PCITYPE_FC_WT
  #error FRTP_PCITYPE_FC_WT already defined
#endif

#ifdef FRTP_PCITYPE_LF
  #error FRTP_PCITYPE_LF already defined
#endif

#ifdef FRTP_PCITYPE_SN_MASK
  #error FRTP_PCITYPE_SN_MASK already defined
#endif

#ifdef FRTP_PCITYPE_STFA
  #error FRTP_PCITYPE_STFA already defined
#endif

#ifdef FRTP_PCITYPE_STFU
  #error FRTP_PCITYPE_STFU already defined
#endif

#ifdef FRTP_POSTCONDITION_ASSERT
  #error FRTP_POSTCONDITION_ASSERT already defined
#endif

#ifdef FRTP_POSTCONDITION_ASSERT_NO_EVAL
  #error FRTP_POSTCONDITION_ASSERT_NO_EVAL already defined
#endif

#ifdef FRTP_PRECONDITION_ASSERT
  #error FRTP_PRECONDITION_ASSERT already defined
#endif

#ifdef FRTP_PRECONDITION_ASSERT_NO_EVAL
  #error FRTP_PRECONDITION_ASSERT_NO_EVAL already defined
#endif

#ifdef FRTP_STATIC_ASSERT
  #error FRTP_STATIC_ASSERT already defined
#endif

#ifdef FRTP_TXPDUTYPE_DATA_CF
  #error FRTP_TXPDUTYPE_DATA_CF already defined
#endif

#ifdef FRTP_TXPDUTYPE_DATA_CFEOB
  #error FRTP_TXPDUTYPE_DATA_CFEOB already defined
#endif

#ifdef FRTP_TXPDUTYPE_DATA_LF
  #error FRTP_TXPDUTYPE_DATA_LF already defined
#endif

#ifdef FRTP_TXPDUTYPE_DATA_SF
  #error FRTP_TXPDUTYPE_DATA_SF already defined
#endif

#ifdef FRTP_TXPDUTYPE_FC
  #error FRTP_TXPDUTYPE_FC already defined
#endif

#ifdef FRTP_TXPDU_INVALID
  #error FRTP_TXPDU_INVALID already defined
#endif

#ifdef FRTP_UNINIT
  #error FRTP_UNINIT already defined
#endif

#ifdef FRTP_UNREACHABLE_CODE_ASSERT
  #error FRTP_UNREACHABLE_CODE_ASSERT already defined
#endif

#ifdef FrTp_Chnl_GetRxState
  #error FrTp_Chnl_GetRxState already defined
#endif

#ifdef FrTp_Chnl_GetRxSubState
  #error FrTp_Chnl_GetRxSubState already defined
#endif

#ifdef FrTp_Chnl_GetTxState
  #error FrTp_Chnl_GetTxState already defined
#endif

#ifdef FrTp_Chnl_IsRxState
  #error FrTp_Chnl_IsRxState already defined
#endif

#ifdef FrTp_Chnl_IsTxPending
  #error FrTp_Chnl_IsTxPending already defined
#endif

#ifdef FrTp_Chnl_IsTxState
  #error FrTp_Chnl_IsTxState already defined
#endif

#ifdef FrTp_FieldToUint16
  #error FrTp_FieldToUint16 already defined
#endif

#ifdef FrTp_GetAI_Source
  #error FrTp_GetAI_Source already defined
#endif

#ifdef FrTp_GetAI_Target
  #error FrTp_GetAI_Target already defined
#endif

#ifdef FrTp_GetAckRet_BP
  #error FrTp_GetAckRet_BP already defined
#endif

#ifdef FrTp_GetCTS_BC
  #error FrTp_GetCTS_BC already defined
#endif

#ifdef FrTp_GetCTS_BfS
  #error FrTp_GetCTS_BfS already defined
#endif

#ifdef FrTp_GetFPL
  #error FrTp_GetFPL already defined
#endif

#ifdef FrTp_GetML
  #error FrTp_GetML already defined
#endif

#ifdef FrTp_GetPCI
  #error FrTp_GetPCI already defined
#endif

#ifdef FrTp_GetPCIAckType
  #error FrTp_GetPCIAckType already defined
#endif

#ifdef FrTp_GetPayload_CF
  #error FrTp_GetPayload_CF already defined
#endif

#ifdef FrTp_GetPayload_LF
  #error FrTp_GetPayload_LF already defined
#endif

#ifdef FrTp_GetPayload_STF
  #error FrTp_GetPayload_STF already defined
#endif

#ifdef FrTp_Header_Offset_ACK
  #error FrTp_Header_Offset_ACK already defined
#endif

#ifdef FrTp_Header_Offset_AI_SA_High
  #error FrTp_Header_Offset_AI_SA_High already defined
#endif

#ifdef FrTp_Header_Offset_AI_SA_Low
  #error FrTp_Header_Offset_AI_SA_Low already defined
#endif

#ifdef FrTp_Header_Offset_AI_TA_High
  #error FrTp_Header_Offset_AI_TA_High already defined
#endif

#ifdef FrTp_Header_Offset_AI_TA_Low
  #error FrTp_Header_Offset_AI_TA_Low already defined
#endif

#ifdef FrTp_Header_Offset_BC
  #error FrTp_Header_Offset_BC already defined
#endif

#ifdef FrTp_Header_Offset_BP_High
  #error FrTp_Header_Offset_BP_High already defined
#endif

#ifdef FrTp_Header_Offset_BP_Low
  #error FrTp_Header_Offset_BP_Low already defined
#endif

#ifdef FrTp_Header_Offset_BfS_High
  #error FrTp_Header_Offset_BfS_High already defined
#endif

#ifdef FrTp_Header_Offset_BfS_Low
  #error FrTp_Header_Offset_BfS_Low already defined
#endif

#ifdef FrTp_Header_Offset_FPL
  #error FrTp_Header_Offset_FPL already defined
#endif

#ifdef FrTp_Header_Offset_ML_High
  #error FrTp_Header_Offset_ML_High already defined
#endif

#ifdef FrTp_Header_Offset_ML_Low
  #error FrTp_Header_Offset_ML_Low already defined
#endif

#ifdef FrTp_Header_Offset_PCI_Type
  #error FrTp_Header_Offset_PCI_Type already defined
#endif

#ifdef FrTp_Limit_uint16
  #error FrTp_Limit_uint16 already defined
#endif

#ifdef FrTp_Limit_uint32
  #error FrTp_Limit_uint32 already defined
#endif

#ifdef FrTp_Limit_uint8
  #error FrTp_Limit_uint8 already defined
#endif

#ifdef FrTp_Max_FPL_STF
  #error FrTp_Max_FPL_STF already defined
#endif

#ifdef FrTp_SetAI
  #error FrTp_SetAI already defined
#endif

#ifdef FrTp_SetPCI_ABT
  #error FrTp_SetPCI_ABT already defined
#endif

#ifdef FrTp_SetPCI_ACK
  #error FrTp_SetPCI_ACK already defined
#endif

#ifdef FrTp_SetPCI_CF
  #error FrTp_SetPCI_CF already defined
#endif

#ifdef FrTp_SetPCI_CTS
  #error FrTp_SetPCI_CTS already defined
#endif

#ifdef FrTp_SetPCI_LF
  #error FrTp_SetPCI_LF already defined
#endif

#ifdef FrTp_SetPCI_OVFLW
  #error FrTp_SetPCI_OVFLW already defined
#endif

#ifdef FrTp_SetPCI_RET
  #error FrTp_SetPCI_RET already defined
#endif

#ifdef FrTp_SetPCI_SF
  #error FrTp_SetPCI_SF already defined
#endif

#ifdef FrTp_SetPCI_SF_Hlp
  #error FrTp_SetPCI_SF_Hlp already defined
#endif

#ifdef FrTp_SetPCI_WAIT
  #error FrTp_SetPCI_WAIT already defined
#endif

#ifdef FrTp_Size_Header_CF
  #error FrTp_Size_Header_CF already defined
#endif

#ifdef FrTp_Size_Header_FC
  #error FrTp_Size_Header_FC already defined
#endif

#ifdef FrTp_Size_Header_FC_ACK_RET
  #error FrTp_Size_Header_FC_ACK_RET already defined
#endif

#ifdef FrTp_Size_Header_FC_CTS
  #error FrTp_Size_Header_FC_CTS already defined
#endif

#ifdef FrTp_Size_Header_LF
  #error FrTp_Size_Header_LF already defined
#endif

#ifdef FrTp_Size_Header_PCI
  #error FrTp_Size_Header_PCI already defined
#endif

#ifdef FrTp_Size_Header_STF
  #error FrTp_Size_Header_STF already defined
#endif

#ifdef FrTp_Size_Header_STF_LF
  #error FrTp_Size_Header_STF_LF already defined
#endif

#ifdef FrTp_StartTimer
  #error FrTp_StartTimer already defined
#endif

#ifdef FrTp_StopTimer
  #error FrTp_StopTimer already defined
#endif

#ifdef FrTp_Uint16ToField
  #error FrTp_Uint16ToField already defined
#endif

#endif /* defined FRTP_GUARDS_H */
