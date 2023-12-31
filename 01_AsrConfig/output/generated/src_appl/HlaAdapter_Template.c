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
 * on Wed Mar 29 10:30:46 CST 2023. !!!IGNORE-LINE!!!
 */

/*
 * \addtogroup Rte Runtime Environment
 * @{
 */

/* ==================[Includes]=============================================== */
#include <Rte_HlaAdapter.h>

/* ==================[Definition of functions with external linkage]========== */
/* ------------------------[runnable entity skeletons]------------------------ */
#define HlaAdapter_START_SEC_CODE
#include <HlaAdapter_MemMap.h>
FUNC(void, RTE_CODE) HlaAdapter_HlaExec (void)
{
  BaseCtrlData_t arg_Read_data;
  Std_ReturnType ret_Read;
  VehSig_t arg_Read_data_0;
  Std_ReturnType ret_Read_0;

  ret_Read = Rte_Read_RP_Fcu_BaseCtrlData_BaseCtrlData(&arg_Read_data);
  (void)ret_Read;
  ret_Read_0 = Rte_Read_RP_Fcu_VehSig_VehSig(&arg_Read_data_0);
  (void)ret_Read_0;

} /* FUNC(void, RTE_CODE) HlaAdapter_HlaExec (void) */

#define HlaAdapter_STOP_SEC_CODE
#include <HlaAdapter_MemMap.h>

#define HlaAdapter_START_SEC_CODE
#include <HlaAdapter_MemMap.h>
FUNC(void, RTE_CODE) HlaAdapter_InitFunction (void)
{
  BaseCtrlData_t arg_Read_data;
  Std_ReturnType ret_Read;
  VehSig_t arg_Read_data_0;
  Std_ReturnType ret_Read_0;

  ret_Read = Rte_Read_RP_Fcu_BaseCtrlData_BaseCtrlData(&arg_Read_data);
  (void)ret_Read;
  ret_Read_0 = Rte_Read_RP_Fcu_VehSig_VehSig(&arg_Read_data_0);
  (void)ret_Read_0;

} /* FUNC(void, RTE_CODE) HlaAdapter_InitFunction (void) */

#define HlaAdapter_STOP_SEC_CODE
#include <HlaAdapter_MemMap.h>

#define HlaAdapter_START_SEC_CODE
#include <HlaAdapter_MemMap.h>
FUNC(void, RTE_CODE) HlaAdapter_MainFunction (void)
{
  Hla_OutputSignals_t arg_Write_data = 
  {
    0U,
    0U,
    0U,
    {0U, 0U, 0U}
  };
  Std_ReturnType ret_Write;
  BaseCtrlData_t arg_Read_data;
  Std_ReturnType ret_Read;
  VehDyn_t arg_Read_data_0;
  Std_ReturnType ret_Read_0;
  Hla_InputSignals_t arg_Read_data_1;
  Std_ReturnType ret_Read_1;
  VehSig_t arg_Read_data_2;
  Std_ReturnType ret_Read_2;
  uint32_t arg_Call_VirtualAddress = 0U;
  uint32_t arg_Call_FunctionId = 0U;
  VoidPtr_t arg_Call_Data = NULL_PTR;
  uint32_t arg_Call_Length = 0U;
  Std_ReturnType ret_Call;
  uint16_t arg_Call_TaskId = 0U;
  Std_ReturnType ret_Call_0;

  ret_Write = Rte_Write_PP_HlaAdapter_OutputData_Hla_OutputSignals_t(&arg_Write_data);
  (void)ret_Write;
  ret_Read = Rte_Read_RP_Fcu_BaseCtrlData_BaseCtrlData(&arg_Read_data);
  (void)ret_Read;
  ret_Read_0 = Rte_Read_RP_VdyAdapter_VehDynData_VehDyn(&arg_Read_data_0);
  (void)ret_Read_0;
  ret_Read_1 = Rte_Read_RP_Fcu_HlaInputData_Hla_InputSignals_t(&arg_Read_data_1);
  (void)ret_Read_1;
  ret_Read_2 = Rte_Read_RP_Fcu_VehSig_VehSig(&arg_Read_data_2);
  (void)ret_Read_2;
  ret_Call = Rte_Call_RP_MtsiAdapter_MeasFreezeData_MeasFreezeData(arg_Call_VirtualAddress, arg_Call_FunctionId, arg_Call_Data, arg_Call_Length);
  (void)ret_Call;
  ret_Call_0 = Rte_Call_RP_UpdateTaskCycle_UpdateTaskCycle(arg_Call_TaskId);
  (void)ret_Call_0;

} /* FUNC(void, RTE_CODE) HlaAdapter_MainFunction (void) */

#define HlaAdapter_STOP_SEC_CODE
#include <HlaAdapter_MemMap.h>

/*
  ------------------------[runnable-independent API]-------------------------

  Copy and paste the following API to those runnable entity functions where
  you want to use them.

  ------------------------[port handle API]----------------------------------
  ------------------------[per instance memory API]--------------------------
 */

/** @} doxygen end group definition  */
/* ==================[end of file]============================================ */
