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
 * on Thu Jun 29 13:57:44 CST 2023. !!!IGNORE-LINE!!!
 */

/*
 * \addtogroup Rte Runtime Environment
 * @{
 */

/* ==================[Includes]=============================================== */
#include <Rte_FSMonitor.h>

/* ==================[Definition of functions with external linkage]========== */
/* ------------------------[runnable entity skeletons]------------------------ */
#define FSMonitor_START_SEC_CODE
#include <FSMonitor_MemMap.h>
FUNC(void, RTE_CODE) FSMonitor_InitFunction (void)
{

} /* FUNC(void, RTE_CODE) FSMonitor_InitFunction (void) */

#define FSMonitor_STOP_SEC_CODE
#include <FSMonitor_MemMap.h>

#define FSMonitor_START_SEC_CODE
#include <FSMonitor_MemMap.h>
FUNC(void, RTE_CODE) FSMonitor_MainFunction (void)
{
  Com_Receive_EspVehSpd arg_Read_data;
  Std_ReturnType ret_Read;
  float32_t arg_Call_value = 0.0f;
  Std_ReturnType ret_Call;
  float32_t arg_Call_value_0 = 0.0f;
  Std_ReturnType ret_Call_0;
  float32_t arg_Call_value_1 = 0.0f;
  Std_ReturnType ret_Call_1;
  float32_t arg_Call_value_2 = 0.0f;
  Std_ReturnType ret_Call_2;

  ret_Read = Rte_Read_RP_Fs_Chassis_Data_EspVehSpd_Status_EspVehSpd(&arg_Read_data);
  (void)ret_Read;
  ret_Call = Rte_Call_RP_Fs_EvAdc_GetValue_VMON_BATT_GetPhyValue(&arg_Call_value);
  (void)ret_Call;
  ret_Call_0 = Rte_Call_RP_Fs_EvAdc_GetValue_VMON_IGN_GetPhyValue(&arg_Call_value_0);
  (void)ret_Call_0;
  ret_Call_1 = Rte_Call_RP_Fs_EvAdc_GetValue_VMON_McuExtTemp_GetPhyValue(&arg_Call_value_1);
  (void)ret_Call_1;
  ret_Call_2 = Rte_Call_RP_Fs_EvAdc_GetValue_VMON_SocExtTemp_GetPhyValue(&arg_Call_value_2);
  (void)ret_Call_2;

} /* FUNC(void, RTE_CODE) FSMonitor_MainFunction (void) */

#define FSMonitor_STOP_SEC_CODE
#include <FSMonitor_MemMap.h>

/*
  ------------------------[runnable-independent API]-------------------------

  Copy and paste the following API to those runnable entity functions where
  you want to use them.

  ------------------------[port handle API]----------------------------------
  ------------------------[per instance memory API]--------------------------
 */

/** @} doxygen end group definition  */
/* ==================[end of file]============================================ */
