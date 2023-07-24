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
 * on Tue Feb 28 15:54:31 CST 2023. !!!IGNORE-LINE!!!
 */

/*
 * \addtogroup Rte Runtime Environment
 * @{
 */

/* ==================[Includes]=============================================== */
#include <Rte_LcfAdapter.h>

/* ==================[Definition of functions with external linkage]========== */
/* ------------------------[runnable entity skeletons]------------------------ */
#define LcfAdapter_START_SEC_CODE
#include <LcfAdapter_MemMap.h>
FUNC(void, RTE_CODE) LcfAdapter_InitFunction (void)
{
  LCF_SenGenericOutputs_t arg_Write_data = 
  {
    0U,
    {
      0U,
      0U,
      0U,
      0U,
      {0U, 0U, 0U}
    },
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    {
      {
        {
          0.0f,
          0.0f,
          0.0f,
          0.0f,
          0.0f,
          0.0f
        },
        {
          0.0f,
          0.0f,
          0.0f,
          0.0f,
          0.0f,
          0.0f
        },
        {
          0.0f,
          0.0f,
          0.0f,
          0.0f,
          0.0f,
          0.0f
        },
        {
          0.0f,
          0.0f,
          0.0f,
          0.0f,
          0.0f,
          0.0f
        },
        {
          0.0f,
          0.0f,
          0.0f,
          0.0f,
          0.0f,
          0.0f
        }
      },
      0U,
      {0U, 0U, 0U},
      0.0f
    },
    {
      0U,
      0U,
      0U,
      0U,
      0U,
      0U,
      0U
    },
    0.0f,
    0.0f,
    {
      0U,
      0U,
      0U,
      0U,
      0U,
      0U,
      0U,
      0U
    },
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    {0U, 0U, 0U}
  };
  Std_ReturnType ret_Write;
  LCF_VehGenericOutputs_t arg_Write_data_0 = 
  {
    0U,
    {
      0U,
      0U,
      0U,
      0U,
      {0U, 0U, 0U}
    },
    0U,
    0U,
    0U,
    0U,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0U,
    0U,
    0U,
    0U,
    {
      0U,
      0U,
      0U,
      0U
    },
    {
      0U,
      {0U, 0U, 0U}
    }
  };
  Std_ReturnType ret_Write_0;
  AbdOutputData_t arg_Read_data;
  Std_ReturnType ret_Read;
  BaseCtrlData_t arg_Read_data_0;
  Std_ReturnType ret_Read_0;
  EM_t_GenObjectList arg_Read_data_1;
  Std_ReturnType ret_Read_1;
  LCF_GenericInputs_t arg_Read_data_2;
  Std_ReturnType ret_Read_2;
  VDYOffsets_t arg_Read_data_3;
  Std_ReturnType ret_Read_3;
  VehDyn_t arg_Read_data_4;
  Std_ReturnType ret_Read_4;
  VehPar_t arg_Read_data_5;
  Std_ReturnType ret_Read_5;
  VehSig_t arg_Read_data_6;
  Std_ReturnType ret_Read_6;

  ret_Write = Rte_Write_PP_LcfAdapter_LcfSenGenericOutputData_LcfSenGenericOutputData(&arg_Write_data);
  (void)ret_Write;
  ret_Write_0 = Rte_Write_PP_LcfAdapter_LcfVehGenericOutputData_LcfVehGenricOutputData(&arg_Write_data_0);
  (void)ret_Write_0;
  ret_Read = Rte_Read_RP_Sdc_Perception_AbdOutputData_AbdOutputData_t(&arg_Read_data);
  (void)ret_Read;
  ret_Read_0 = Rte_Read_RP_Fcu_BaseCtrlData_BaseCtrlData(&arg_Read_data_0);
  (void)ret_Read_0;
  ret_Read_1 = Rte_Read_RP_Sdc_Cem_GenObjectList_GenObjectList(&arg_Read_data_1);
  (void)ret_Read_1;
  ret_Read_2 = Rte_Read_RP_Fcu_LcfGenericInputData_LcfGenericInputData(&arg_Read_data_2);
  (void)ret_Read_2;
  ret_Read_3 = Rte_Read_RP_VdyAdapter_VdyOffsets_VdyOffsets(&arg_Read_data_3);
  (void)ret_Read_3;
  ret_Read_4 = Rte_Read_RP_VdyAdapter_VehDyn_VehDyn(&arg_Read_data_4);
  (void)ret_Read_4;
  ret_Read_5 = Rte_Read_RP_Fcu_VehPar_VehPar(&arg_Read_data_5);
  (void)ret_Read_5;
  ret_Read_6 = Rte_Read_RP_Fcu_VehSig_VehSig(&arg_Read_data_6);
  (void)ret_Read_6;

} /* FUNC(void, RTE_CODE) LcfAdapter_InitFunction (void) */

#define LcfAdapter_STOP_SEC_CODE
#include <LcfAdapter_MemMap.h>

#define LcfAdapter_START_SEC_CODE
#include <LcfAdapter_MemMap.h>
FUNC(void, RTE_CODE) LcfAdapter_LcfSenExec (void)
{
  LCF_SenGenericOutputs_t arg_Write_data = 
  {
    0U,
    {
      0U,
      0U,
      0U,
      0U,
      {0U, 0U, 0U}
    },
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    {
      {
        {
          0.0f,
          0.0f,
          0.0f,
          0.0f,
          0.0f,
          0.0f
        },
        {
          0.0f,
          0.0f,
          0.0f,
          0.0f,
          0.0f,
          0.0f
        },
        {
          0.0f,
          0.0f,
          0.0f,
          0.0f,
          0.0f,
          0.0f
        },
        {
          0.0f,
          0.0f,
          0.0f,
          0.0f,
          0.0f,
          0.0f
        },
        {
          0.0f,
          0.0f,
          0.0f,
          0.0f,
          0.0f,
          0.0f
        }
      },
      0U,
      {0U, 0U, 0U},
      0.0f
    },
    {
      0U,
      0U,
      0U,
      0U,
      0U,
      0U,
      0U
    },
    0.0f,
    0.0f,
    {
      0U,
      0U,
      0U,
      0U,
      0U,
      0U,
      0U,
      0U
    },
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    {0U, 0U, 0U}
  };
  Std_ReturnType ret_Write;
  LCF_VehGenericOutputs_t arg_Write_data_0 = 
  {
    0U,
    {
      0U,
      0U,
      0U,
      0U,
      {0U, 0U, 0U}
    },
    0U,
    0U,
    0U,
    0U,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0U,
    0U,
    0U,
    0U,
    {
      0U,
      0U,
      0U,
      0U
    },
    {
      0U,
      {0U, 0U, 0U}
    }
  };
  Std_ReturnType ret_Write_0;
  AbdOutputData_t arg_Read_data;
  Std_ReturnType ret_Read;
  BaseCtrlData_t arg_Read_data_0;
  Std_ReturnType ret_Read_0;
  EM_t_GenObjectList arg_Read_data_1;
  Std_ReturnType ret_Read_1;
  LCF_GenericInputs_t arg_Read_data_2;
  Std_ReturnType ret_Read_2;
  VDYOffsets_t arg_Read_data_3;
  Std_ReturnType ret_Read_3;
  VehDyn_t arg_Read_data_4;
  Std_ReturnType ret_Read_4;
  VehPar_t arg_Read_data_5;
  Std_ReturnType ret_Read_5;
  VehSig_t arg_Read_data_6;
  Std_ReturnType ret_Read_6;

  ret_Write = Rte_Write_PP_LcfAdapter_LcfSenGenericOutputData_LcfSenGenericOutputData(&arg_Write_data);
  (void)ret_Write;
  ret_Write_0 = Rte_Write_PP_LcfAdapter_LcfVehGenericOutputData_LcfVehGenricOutputData(&arg_Write_data_0);
  (void)ret_Write_0;
  ret_Read = Rte_Read_RP_Sdc_Perception_AbdOutputData_AbdOutputData_t(&arg_Read_data);
  (void)ret_Read;
  ret_Read_0 = Rte_Read_RP_Fcu_BaseCtrlData_BaseCtrlData(&arg_Read_data_0);
  (void)ret_Read_0;
  ret_Read_1 = Rte_Read_RP_Sdc_Cem_GenObjectList_GenObjectList(&arg_Read_data_1);
  (void)ret_Read_1;
  ret_Read_2 = Rte_Read_RP_Fcu_LcfGenericInputData_LcfGenericInputData(&arg_Read_data_2);
  (void)ret_Read_2;
  ret_Read_3 = Rte_Read_RP_VdyAdapter_VdyOffsets_VdyOffsets(&arg_Read_data_3);
  (void)ret_Read_3;
  ret_Read_4 = Rte_Read_RP_VdyAdapter_VehDyn_VehDyn(&arg_Read_data_4);
  (void)ret_Read_4;
  ret_Read_5 = Rte_Read_RP_Fcu_VehPar_VehPar(&arg_Read_data_5);
  (void)ret_Read_5;
  ret_Read_6 = Rte_Read_RP_Fcu_VehSig_VehSig(&arg_Read_data_6);
  (void)ret_Read_6;

} /* FUNC(void, RTE_CODE) LcfAdapter_LcfSenExec (void) */

#define LcfAdapter_STOP_SEC_CODE
#include <LcfAdapter_MemMap.h>

#define LcfAdapter_START_SEC_CODE
#include <LcfAdapter_MemMap.h>
FUNC(void, RTE_CODE) LcfAdapter_LcfVehExec (void)
{
  LCF_SenGenericOutputs_t arg_Write_data = 
  {
    0U,
    {
      0U,
      0U,
      0U,
      0U,
      {0U, 0U, 0U}
    },
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    {
      {
        {
          0.0f,
          0.0f,
          0.0f,
          0.0f,
          0.0f,
          0.0f
        },
        {
          0.0f,
          0.0f,
          0.0f,
          0.0f,
          0.0f,
          0.0f
        },
        {
          0.0f,
          0.0f,
          0.0f,
          0.0f,
          0.0f,
          0.0f
        },
        {
          0.0f,
          0.0f,
          0.0f,
          0.0f,
          0.0f,
          0.0f
        },
        {
          0.0f,
          0.0f,
          0.0f,
          0.0f,
          0.0f,
          0.0f
        }
      },
      0U,
      {0U, 0U, 0U},
      0.0f
    },
    {
      0U,
      0U,
      0U,
      0U,
      0U,
      0U,
      0U
    },
    0.0f,
    0.0f,
    {
      0U,
      0U,
      0U,
      0U,
      0U,
      0U,
      0U,
      0U
    },
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    {0U, 0U, 0U}
  };
  Std_ReturnType ret_Write;
  LCF_VehGenericOutputs_t arg_Write_data_0 = 
  {
    0U,
    {
      0U,
      0U,
      0U,
      0U,
      {0U, 0U, 0U}
    },
    0U,
    0U,
    0U,
    0U,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0U,
    0U,
    0U,
    0U,
    {
      0U,
      0U,
      0U,
      0U
    },
    {
      0U,
      {0U, 0U, 0U}
    }
  };
  Std_ReturnType ret_Write_0;
  AbdOutputData_t arg_Read_data;
  Std_ReturnType ret_Read;
  BaseCtrlData_t arg_Read_data_0;
  Std_ReturnType ret_Read_0;
  EM_t_GenObjectList arg_Read_data_1;
  Std_ReturnType ret_Read_1;
  LCF_GenericInputs_t arg_Read_data_2;
  Std_ReturnType ret_Read_2;
  VDYOffsets_t arg_Read_data_3;
  Std_ReturnType ret_Read_3;
  VehDyn_t arg_Read_data_4;
  Std_ReturnType ret_Read_4;
  VehPar_t arg_Read_data_5;
  Std_ReturnType ret_Read_5;
  VehSig_t arg_Read_data_6;
  Std_ReturnType ret_Read_6;

  ret_Write = Rte_Write_PP_LcfAdapter_LcfSenGenericOutputData_LcfSenGenericOutputData(&arg_Write_data);
  (void)ret_Write;
  ret_Write_0 = Rte_Write_PP_LcfAdapter_LcfVehGenericOutputData_LcfVehGenricOutputData(&arg_Write_data_0);
  (void)ret_Write_0;
  ret_Read = Rte_Read_RP_Sdc_Perception_AbdOutputData_AbdOutputData_t(&arg_Read_data);
  (void)ret_Read;
  ret_Read_0 = Rte_Read_RP_Fcu_BaseCtrlData_BaseCtrlData(&arg_Read_data_0);
  (void)ret_Read_0;
  ret_Read_1 = Rte_Read_RP_Sdc_Cem_GenObjectList_GenObjectList(&arg_Read_data_1);
  (void)ret_Read_1;
  ret_Read_2 = Rte_Read_RP_Fcu_LcfGenericInputData_LcfGenericInputData(&arg_Read_data_2);
  (void)ret_Read_2;
  ret_Read_3 = Rte_Read_RP_VdyAdapter_VdyOffsets_VdyOffsets(&arg_Read_data_3);
  (void)ret_Read_3;
  ret_Read_4 = Rte_Read_RP_VdyAdapter_VehDyn_VehDyn(&arg_Read_data_4);
  (void)ret_Read_4;
  ret_Read_5 = Rte_Read_RP_Fcu_VehPar_VehPar(&arg_Read_data_5);
  (void)ret_Read_5;
  ret_Read_6 = Rte_Read_RP_Fcu_VehSig_VehSig(&arg_Read_data_6);
  (void)ret_Read_6;

} /* FUNC(void, RTE_CODE) LcfAdapter_LcfVehExec (void) */

#define LcfAdapter_STOP_SEC_CODE
#include <LcfAdapter_MemMap.h>

#define LcfAdapter_START_SEC_CODE
#include <LcfAdapter_MemMap.h>
FUNC(void, RTE_CODE) LcfAdapter_MainFunction (void)
{
  LCF_SenGenericOutputs_t arg_Write_data = 
  {
    0U,
    {
      0U,
      0U,
      0U,
      0U,
      {0U, 0U, 0U}
    },
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    {
      {
        {
          0.0f,
          0.0f,
          0.0f,
          0.0f,
          0.0f,
          0.0f
        },
        {
          0.0f,
          0.0f,
          0.0f,
          0.0f,
          0.0f,
          0.0f
        },
        {
          0.0f,
          0.0f,
          0.0f,
          0.0f,
          0.0f,
          0.0f
        },
        {
          0.0f,
          0.0f,
          0.0f,
          0.0f,
          0.0f,
          0.0f
        },
        {
          0.0f,
          0.0f,
          0.0f,
          0.0f,
          0.0f,
          0.0f
        }
      },
      0U,
      {0U, 0U, 0U},
      0.0f
    },
    {
      0U,
      0U,
      0U,
      0U,
      0U,
      0U,
      0U
    },
    0.0f,
    0.0f,
    {
      0U,
      0U,
      0U,
      0U,
      0U,
      0U,
      0U,
      0U
    },
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    {0U, 0U, 0U}
  };
  Std_ReturnType ret_Write;
  LCF_VehGenericOutputs_t arg_Write_data_0 = 
  {
    0U,
    {
      0U,
      0U,
      0U,
      0U,
      {0U, 0U, 0U}
    },
    0U,
    0U,
    0U,
    0U,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0U,
    0U,
    0U,
    0U,
    {
      0U,
      0U,
      0U,
      0U
    },
    {
      0U,
      {0U, 0U, 0U}
    }
  };
  Std_ReturnType ret_Write_0;
  AbdOutputData_t arg_Read_data;
  Std_ReturnType ret_Read;
  BaseCtrlData_t arg_Read_data_0;
  Std_ReturnType ret_Read_0;
  EM_t_GenObjectList arg_Read_data_1;
  Std_ReturnType ret_Read_1;
  LCF_GenericInputs_t arg_Read_data_2;
  Std_ReturnType ret_Read_2;
  VDYOffsets_t arg_Read_data_3;
  Std_ReturnType ret_Read_3;
  VehDyn_t arg_Read_data_4;
  Std_ReturnType ret_Read_4;
  VehPar_t arg_Read_data_5;
  Std_ReturnType ret_Read_5;
  VehSig_t arg_Read_data_6;
  Std_ReturnType ret_Read_6;
  uint32_t arg_Call_VirtualAddress = 0U;
  uint32_t arg_Call_FunctionId = 0U;
  VoidPtr_t arg_Call_Data = NULL_PTR;
  uint32_t arg_Call_Length = 0U;
  Std_ReturnType ret_Call;
  uint16_t arg_Call_TaskId = 0U;
  Std_ReturnType ret_Call_0;

  ret_Write = Rte_Write_PP_LcfAdapter_LcfSenGenericOutputData_LcfSenGenericOutputData(&arg_Write_data);
  (void)ret_Write;
  ret_Write_0 = Rte_Write_PP_LcfAdapter_LcfVehGenericOutputData_LcfVehGenricOutputData(&arg_Write_data_0);
  (void)ret_Write_0;
  ret_Read = Rte_Read_RP_Sdc_Perception_AbdOutputData_AbdOutputData_t(&arg_Read_data);
  (void)ret_Read;
  ret_Read_0 = Rte_Read_RP_Fcu_BaseCtrlData_BaseCtrlData(&arg_Read_data_0);
  (void)ret_Read_0;
  ret_Read_1 = Rte_Read_RP_Sdc_Cem_GenObjectList_GenObjectList(&arg_Read_data_1);
  (void)ret_Read_1;
  ret_Read_2 = Rte_Read_RP_Fcu_LcfGenericInputData_LcfGenericInputData(&arg_Read_data_2);
  (void)ret_Read_2;
  ret_Read_3 = Rte_Read_RP_VdyAdapter_VdyOffsets_VdyOffsets(&arg_Read_data_3);
  (void)ret_Read_3;
  ret_Read_4 = Rte_Read_RP_VdyAdapter_VehDyn_VehDyn(&arg_Read_data_4);
  (void)ret_Read_4;
  ret_Read_5 = Rte_Read_RP_Fcu_VehPar_VehPar(&arg_Read_data_5);
  (void)ret_Read_5;
  ret_Read_6 = Rte_Read_RP_Fcu_VehSig_VehSig(&arg_Read_data_6);
  (void)ret_Read_6;
  ret_Call = Rte_Call_RP_MtsiAdapter_MeasFreezeData_MeasFreezeData(arg_Call_VirtualAddress, arg_Call_FunctionId, arg_Call_Data, arg_Call_Length);
  (void)ret_Call;
  ret_Call_0 = Rte_Call_RP_MtsiAdapter_UpdateTaskCycle_UpdateTaskCycle(arg_Call_TaskId);
  (void)ret_Call_0;

} /* FUNC(void, RTE_CODE) LcfAdapter_MainFunction (void) */

#define LcfAdapter_STOP_SEC_CODE
#include <LcfAdapter_MemMap.h>

/*
  ------------------------[runnable-independent API]-------------------------

  Copy and paste the following API to those runnable entity functions where
  you want to use them.

  ------------------------[port handle API]----------------------------------
  ------------------------[per instance memory API]--------------------------
 */

/** @} doxygen end group definition  */
/* ==================[end of file]============================================ */
