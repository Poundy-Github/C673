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
 * on Wed Jun 07 14:41:23 CST 2023. !!!IGNORE-LINE!!!
 */

/*
 * \addtogroup Rte Runtime Environment
 * @{
 */

/* ==================[Includes]=============================================== */
#include <Rte_Sed.h>

/* ==================[Definition of functions with external linkage]========== */
/* ------------------------[runnable entity skeletons]------------------------ */
#define Sed_START_SEC_CODE
#include <Sed_MemMap.h>
FUNC(void, RTE_CODE) Sed_InitFunction (void)
{

} /* FUNC(void, RTE_CODE) Sed_InitFunction (void) */

#define Sed_STOP_SEC_CODE
#include <Sed_MemMap.h>

#define Sed_START_SEC_CODE
#include <Sed_MemMap.h>
FUNC(void, RTE_CODE) Sed_MainFunction (void)
{
  uint8_t arg_Call_data;
  uint16_t arg_Call_length = 0U;
  Std_ReturnType ret_Call;
  uint8_t arg_Call_data_0;
  uint16_t arg_Call_length_0 = 0U;
  Std_ReturnType ret_Call_0;
  uint8_t arg_Call_data_1;
  uint16_t arg_Call_length_1 = 0U;
  Std_ReturnType ret_Call_1;
  uint8_t arg_Call_data_2;
  uint16_t arg_Call_length_2 = 0U;
  Std_ReturnType ret_Call_2;
  uint8_t arg_Call_group_id = 0U;
  void_t arg_Call_socDiagInfo;
  Std_ReturnType ret_Call_3;

  ret_Call = Rte_Call_RP_Sdc_SendInterface_Eth_EthCableFault_Read(&arg_Call_data, arg_Call_length);
  (void)ret_Call;
  ret_Call_0 = Rte_Call_RP_Sdc_SendInterface_Eth_EthCrcError_Read(&arg_Call_data_0, arg_Call_length_0);
  (void)ret_Call_0;
  ret_Call_1 = Rte_Call_RP_Sdc_SendInterface_Eth_EthIcmpError_Read(&arg_Call_data_1, arg_Call_length_1);
  (void)ret_Call_1;
  ret_Call_2 = Rte_Call_RP_Sdc_SendInterface_Eth_EthSQI_Read(&arg_Call_data_2, arg_Call_length_2);
  (void)ret_Call_2;
  ret_Call_3 = Rte_Call_RP_Sdc_SendInterface_Diag_SocDiagInfo_Read(arg_Call_group_id, &arg_Call_socDiagInfo);
  (void)ret_Call_3;

} /* FUNC(void, RTE_CODE) Sed_MainFunction (void) */

#define Sed_STOP_SEC_CODE
#include <Sed_MemMap.h>

/*
  ------------------------[runnable-independent API]-------------------------

  Copy and paste the following API to those runnable entity functions where
  you want to use them.

  ------------------------[port handle API]----------------------------------
  ------------------------[per instance memory API]--------------------------
 */

/** @} doxygen end group definition  */
/* ==================[end of file]============================================ */