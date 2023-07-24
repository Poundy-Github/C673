/**
 * \file
 *
 * \brief AUTOSAR Rte
 *
 * This file contains the implementation of the AUTOSAR
 * module Rte.
 *
 * \version 6.6.3
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2021 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

/*
 * This file contains an Rte component template / example code
 *
 * This file has been automatically generated by
 * EB tresos AutoCore Rte Generator Version 6.6.3
 * on Sun Apr 23 14:33:46 CST 2023. !!!IGNORE-LINE!!!
 */

/*
 * \addtogroup Rte Runtime Environment
 * @{
 */

/* ==================[Includes]=============================================== */
#include <Rte_Comco.h>

/* ==================[Definition of functions with external linkage]========== */
/* ------------------------[runnable entity skeletons]------------------------ */
#define Comco_START_SEC_CODE
#include <Comco_MemMap.h>
FUNC(void, RTE_CODE) Comco_MainFunction (void)
{
  uint16 arg_Read_data;
  Std_ReturnType ret_Read;
  uint8 arg_Read_data_0;
  Std_ReturnType ret_Read_0;
  boolean arg_Read_data_1;
  Std_ReturnType ret_Read_1;
  float32_t arg_Call_value = 0.0f;
  Std_ReturnType ret_Call;
  ComM_ModeType arg_Call_ComMode = 0U;
  Std_ReturnType ret_Call_0;
  ComM_ModeType arg_Call_ComMode_0 = 0U;
  Std_ReturnType ret_Call_1;
  uint8 arg_Switch_mode = 0U;
  Std_ReturnType ret_Switch;
  uint8 arg_Switch_mode_0 = 0U;
  Std_ReturnType ret_Switch_0;
  uint8 ret_Mode;

  ret_Read = Rte_Read_RP_Com_SRI_EspVehSpd_DE_EspVehSpd(&arg_Read_data);
  (void)ret_Read;
  ret_Read_0 = Rte_Read_RP_Com_SRI_EspVehSpdVld_DE_EspVehSpdVld(&arg_Read_data_0);
  (void)ret_Read_0;
  ret_Read_1 = Rte_Read_RP_VoltMonI_SRI_DisableCommunication_DE_VoltMonI_DisableCommunication(&arg_Read_data_1);
  (void)ret_Read_1;
  ret_Call = Rte_Call_RP_EvAdc_GetValue_VMON_IGN_GetPhyValue(&arg_Call_value);
  (void)ret_Call;
  ret_Call_0 = Rte_Call_RP_ComM_UserRequest_Public_RequestComMode(arg_Call_ComMode);
  (void)ret_Call_0;
  ret_Call_1 = Rte_Call_RP_ComM_UserRequest_Private_RequestComMode(arg_Call_ComMode_0);
  (void)ret_Call_1;
  ret_Switch = Rte_Switch_PP_Comco_MSI_RxPduGroupSwitch_proto_MDG_IPduGroupSwitch(arg_Switch_mode);
  (void)ret_Switch;
  ret_Switch_0 = Rte_Switch_PP_Comco_MSI_TxPduGroupSwitch_proto_MDG_IPduGroupSwitch(arg_Switch_mode_0);
  (void)ret_Switch_0;
  ret_Mode = Rte_Mode_RP_BswM_MSI_DiagComControlMode_proto_DcmCommunicationControl();
  (void)ret_Mode;

} /* FUNC(void, RTE_CODE) Comco_MainFunction (void) */

#define Comco_STOP_SEC_CODE
#include <Comco_MemMap.h>

#define Comco_START_SEC_CODE
#include <Comco_MemMap.h>
FUNC(Std_ReturnType, RTE_CODE) Comco_u_NMWakupFlag_Read (P2VAR(uint8_t, AUTOMATIC, RTE_APPL_DATA) u_WakeupFlag)
{
  /* suppress compiler warnings about unused arguments */
  (void)*u_WakeupFlag;
  return RTE_E_OK;
} /* FUNC(Std_ReturnType, RTE_CODE) Comco_u_NMWakupFlag_Read (P2VAR(uint8_t, AUTOMATIC, RTE_APPL_DATA) u_WakeupFlag) */

#define Comco_STOP_SEC_CODE
#include <Comco_MemMap.h>

#define Comco_START_SEC_CODE
#include <Comco_MemMap.h>
FUNC(Std_ReturnType, RTE_CODE) Comco_u_nmCurrentState_Read (P2VAR(uint8_t, AUTOMATIC, RTE_APPL_DATA) u_CurNmState)
{
  /* suppress compiler warnings about unused arguments */
  (void)*u_CurNmState;
  return RTE_E_OK;
} /* FUNC(Std_ReturnType, RTE_CODE) Comco_u_nmCurrentState_Read (P2VAR(uint8_t, AUTOMATIC, RTE_APPL_DATA) u_CurNmState) */

#define Comco_STOP_SEC_CODE
#include <Comco_MemMap.h>

#define Comco_START_SEC_CODE
#include <Comco_MemMap.h>
FUNC(Std_ReturnType, RTE_CODE) Comco_u_nmPreviousState_Read (P2VAR(uint8_t, AUTOMATIC, RTE_APPL_DATA) u_PreNmState)
{
  /* suppress compiler warnings about unused arguments */
  (void)*u_PreNmState;
  return RTE_E_OK;
} /* FUNC(Std_ReturnType, RTE_CODE) Comco_u_nmPreviousState_Read (P2VAR(uint8_t, AUTOMATIC, RTE_APPL_DATA) u_PreNmState) */

#define Comco_STOP_SEC_CODE
#include <Comco_MemMap.h>

/*
  ------------------------[runnable-independent API]-------------------------

  Copy and paste the following API to those runnable entity functions where
  you want to use them.

  ------------------------[port handle API]----------------------------------
  ------------------------[per instance memory API]--------------------------
 */

/** @} doxygen end group definition  */
/* ==================[end of file]============================================ */