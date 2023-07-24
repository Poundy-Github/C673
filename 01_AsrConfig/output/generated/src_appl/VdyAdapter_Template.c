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
 * on Thu Mar 16 15:33:14 CST 2023. !!!IGNORE-LINE!!!
 */

/*
 * \addtogroup Rte Runtime Environment
 * @{
 */

/* ==================[Includes]=============================================== */
#include <Rte_VdyAdapter.h>

/* ==================[Definition of functions with external linkage]========== */
/* ------------------------[runnable entity skeletons]------------------------ */
#define VdyAdapter_START_SEC_CODE
#include <VdyAdapter_MemMap.h>
FUNC(void, RTE_CODE) VdyAdapter_InitFunction (void)
{
  AlgoCompState_t arg_Write_data = 
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
    {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U},
    0U,
    0U,
    0U,
    0U
  };
  Std_ReturnType ret_Write;
  VDYErrors_t arg_Write_data_0 = 
  {
    0U,
    {
      0U,
      0U,
      0U,
      0U,
      {0U, 0U, 0U}
    },
    {
      0U,
      0U
    },
    {
      0U
    },
    {
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
      0U
    }
  };
  Std_ReturnType ret_Write_0;
  VDYEstCurves_t arg_Write_data_1 = 
  {
    0U,
    {
      0U,
      0U,
      0U,
      0U,
      {0U, 0U, 0U}
    },
    {
      0.0f
    },
    {
      0.0f
    },
    {
      0.0f
    },
    {
      0.0f
    },
    {
      0.0f
    },
    {
      0.0f
    },
    {
      0.0f
    },
    {
      0.0f
    }
  };
  Std_ReturnType ret_Write_1;
  VDYNvIoData_t arg_Write_data_2 = 
  {
    0U,
    {
      0U,
      0U,
      0U,
      0U,
      {0U, 0U, 0U}
    },
    {
      0.0f,
      0U
    },
    {
      0.0f,
      0U,
      0U,
      0,
      0U
    },
    {
      0.0f,
      0.0f,
      0.0f,
      0U
    },
    {
      0.0f,
      0U
    },
    {{
      0.0f,
      0.0f,
      0.0f
    }, 
    {
      0.0f,
      0.0f,
      0.0f
    }, 
    {
      0.0f,
      0.0f,
      0.0f
    }},
    {
      0.0f,
      0.0f,
      0U,
      0U
    },
    0U
  };
  Std_ReturnType ret_Write_2;
  VDYOffsets_t arg_Write_data_3 = 
  {
    0U,
    {
      0U,
      0U,
      0U,
      0U,
      {0U, 0U, 0U}
    },
    {
      0.0f,
      0,
      0.0f,
      0.0f
    },
    {
      0.0f,
      0.0f,
      0
    },
    {
      0.0f,
      0.0f,
      0
    }
  };
  Std_ReturnType ret_Write_3;
  VehDyn_t arg_Write_data_4 = 
  {
    0U,
    {
      0U,
      0U,
      0U,
      0U,
      {0U, 0U, 0U}
    },
    {
      0.0f,
      0.0f,
      0.0f,
      0.0f,
      {
        0.0f,
        {
          0U,
          0U,
          0U,
          0U,
          {0U, 0U, 0U}
        },
        0.0f,
        0.0f,
        {
          0U,
          0U,
          0U,
          0U,
          {0U, 0U, 0U}
        },
        0.0f,
        0.0f
      },
      {
        0.0f,
        0.0f,
        0.0f,
        0.0f,
        0.0f,
        0.0f,
        0U,
        0U,
        0U,
        0U
      },
      {
        0.0f,
        0.0f
      },
      0U,
      0U,
      0U,
      0U
    },
    {
      {
        0.0f,
        0.0f,
        0.0f,
        0.0f,
        0.0f
      },
      {
        0U,
        0U,
        0U,
        0U,
        {0U, 0U, 0U}
      },
      0.0f,
      {
        0.0f,
        {
          0U,
          0U,
          0U,
          0U,
          {0U, 0U, 0U}
        },
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
        0.0f
      },
      {
        0.0f,
        {
          0U,
          0U,
          0U,
          0U,
          {0U, 0U, 0U}
        },
        0.0f,
        0.0f
      },
      {
        0.0f,
        {
          0U,
          0U,
          0U,
          0U,
          {0U, 0U, 0U}
        },
        0.0f
      },
      {
        0.0f,
        0.0f
      },
      {
        0.0f,
        0.0f,
        0.0f,
        0.0f
      }
    },
    {
      0.0f,
      0U,
      0U,
      0U,
      0U
    },
    {
      0.0f,
      0U,
      0U,
      0U,
      0U
    },
    {0U, 0U, 0U},
    {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
  };
  Std_ReturnType ret_Write_4;
  BaseCtrlData_t arg_Read_data;
  Std_ReturnType ret_Read;
  VDYNvIoData_t arg_Read_data_0;
  Std_ReturnType ret_Read_0;
  VehPar_t arg_Read_data_1;
  Std_ReturnType ret_Read_1;
  VehSig_t arg_Read_data_2;
  Std_ReturnType ret_Read_2;

  ret_Write = Rte_Write_PP_VdyAdapter_AlgoCompState_AlgoCompState(&arg_Write_data);
  (void)ret_Write;
  ret_Write_0 = Rte_Write_PP_VdyAdapter_VdyErrors_VdyErrors(&arg_Write_data_0);
  (void)ret_Write_0;
  ret_Write_1 = Rte_Write_PP_VdyAdapter_VdyEstCurves_VdyEstCurves(&arg_Write_data_1);
  (void)ret_Write_1;
  ret_Write_2 = Rte_Write_PP_VdyAdapter_VdyOutputNvMData_VdyNvMInOutData(&arg_Write_data_2);
  (void)ret_Write_2;
  ret_Write_3 = Rte_Write_PP_VdyAdapter_VdyOffsets_VdyOffsets(&arg_Write_data_3);
  (void)ret_Write_3;
  ret_Write_4 = Rte_Write_PP_VdyAdapter_VehDyn_VehDyn(&arg_Write_data_4);
  (void)ret_Write_4;
  ret_Read = Rte_Read_RP_Fcu_BaseCtrlData_BaseCtrlData(&arg_Read_data);
  (void)ret_Read;
  ret_Read_0 = Rte_Read_RP_Cdm_VdyInputNvMData_VdyNvMInOutData(&arg_Read_data_0);
  (void)ret_Read_0;
  ret_Read_1 = Rte_Read_RP_Fcu_VehPar_VehPar(&arg_Read_data_1);
  (void)ret_Read_1;
  ret_Read_2 = Rte_Read_RP_Fcu_VehSig_VehSig(&arg_Read_data_2);
  (void)ret_Read_2;

} /* FUNC(void, RTE_CODE) VdyAdapter_InitFunction (void) */

#define VdyAdapter_STOP_SEC_CODE
#include <VdyAdapter_MemMap.h>

#define VdyAdapter_START_SEC_CODE
#include <VdyAdapter_MemMap.h>
FUNC(void, RTE_CODE) VdyAdapter_MainFunction (void)
{
  AlgoCompState_t arg_Write_data = 
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
    {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U},
    0U,
    0U,
    0U,
    0U
  };
  Std_ReturnType ret_Write;
  VDYErrors_t arg_Write_data_0 = 
  {
    0U,
    {
      0U,
      0U,
      0U,
      0U,
      {0U, 0U, 0U}
    },
    {
      0U,
      0U
    },
    {
      0U
    },
    {
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
      0U
    }
  };
  Std_ReturnType ret_Write_0;
  VDYEstCurves_t arg_Write_data_1 = 
  {
    0U,
    {
      0U,
      0U,
      0U,
      0U,
      {0U, 0U, 0U}
    },
    {
      0.0f
    },
    {
      0.0f
    },
    {
      0.0f
    },
    {
      0.0f
    },
    {
      0.0f
    },
    {
      0.0f
    },
    {
      0.0f
    },
    {
      0.0f
    }
  };
  Std_ReturnType ret_Write_1;
  VDYNvIoData_t arg_Write_data_2 = 
  {
    0U,
    {
      0U,
      0U,
      0U,
      0U,
      {0U, 0U, 0U}
    },
    {
      0.0f,
      0U
    },
    {
      0.0f,
      0U,
      0U,
      0,
      0U
    },
    {
      0.0f,
      0.0f,
      0.0f,
      0U
    },
    {
      0.0f,
      0U
    },
    {{
      0.0f,
      0.0f,
      0.0f
    }, 
    {
      0.0f,
      0.0f,
      0.0f
    }, 
    {
      0.0f,
      0.0f,
      0.0f
    }},
    {
      0.0f,
      0.0f,
      0U,
      0U
    },
    0U
  };
  Std_ReturnType ret_Write_2;
  VDYOffsets_t arg_Write_data_3 = 
  {
    0U,
    {
      0U,
      0U,
      0U,
      0U,
      {0U, 0U, 0U}
    },
    {
      0.0f,
      0,
      0.0f,
      0.0f
    },
    {
      0.0f,
      0.0f,
      0
    },
    {
      0.0f,
      0.0f,
      0
    }
  };
  Std_ReturnType ret_Write_3;
  VehDyn_t arg_Write_data_4 = 
  {
    0U,
    {
      0U,
      0U,
      0U,
      0U,
      {0U, 0U, 0U}
    },
    {
      0.0f,
      0.0f,
      0.0f,
      0.0f,
      {
        0.0f,
        {
          0U,
          0U,
          0U,
          0U,
          {0U, 0U, 0U}
        },
        0.0f,
        0.0f,
        {
          0U,
          0U,
          0U,
          0U,
          {0U, 0U, 0U}
        },
        0.0f,
        0.0f
      },
      {
        0.0f,
        0.0f,
        0.0f,
        0.0f,
        0.0f,
        0.0f,
        0U,
        0U,
        0U,
        0U
      },
      {
        0.0f,
        0.0f
      },
      0U,
      0U,
      0U,
      0U
    },
    {
      {
        0.0f,
        0.0f,
        0.0f,
        0.0f,
        0.0f
      },
      {
        0U,
        0U,
        0U,
        0U,
        {0U, 0U, 0U}
      },
      0.0f,
      {
        0.0f,
        {
          0U,
          0U,
          0U,
          0U,
          {0U, 0U, 0U}
        },
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
        0.0f
      },
      {
        0.0f,
        {
          0U,
          0U,
          0U,
          0U,
          {0U, 0U, 0U}
        },
        0.0f,
        0.0f
      },
      {
        0.0f,
        {
          0U,
          0U,
          0U,
          0U,
          {0U, 0U, 0U}
        },
        0.0f
      },
      {
        0.0f,
        0.0f
      },
      {
        0.0f,
        0.0f,
        0.0f,
        0.0f
      }
    },
    {
      0.0f,
      0U,
      0U,
      0U,
      0U
    },
    {
      0.0f,
      0U,
      0U,
      0U,
      0U
    },
    {0U, 0U, 0U},
    {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
  };
  Std_ReturnType ret_Write_4;
  BaseCtrlData_t arg_Read_data;
  Std_ReturnType ret_Read;
  VDYNvIoData_t arg_Read_data_0;
  Std_ReturnType ret_Read_0;
  VehPar_t arg_Read_data_1;
  Std_ReturnType ret_Read_1;
  VehSig_t arg_Read_data_2;
  Std_ReturnType ret_Read_2;
  NvM_RequestResultType arg_Call_RequestResultPtr;
  Std_ReturnType ret_Call;
  NvM_DstPtrType arg_Call_DstPtr = NULL_PTR;
  Std_ReturnType ret_Call_0;
  boolean arg_Call_BlockChanged = 0U;
  Std_ReturnType ret_Call_1;
  NvM_SrcPtrType arg_Call_SrcPtr = NULL_PTR;
  Std_ReturnType ret_Call_2;

  ret_Write = Rte_Write_PP_VdyAdapter_AlgoCompState_AlgoCompState(&arg_Write_data);
  (void)ret_Write;
  ret_Write_0 = Rte_Write_PP_VdyAdapter_VdyErrors_VdyErrors(&arg_Write_data_0);
  (void)ret_Write_0;
  ret_Write_1 = Rte_Write_PP_VdyAdapter_VdyEstCurves_VdyEstCurves(&arg_Write_data_1);
  (void)ret_Write_1;
  ret_Write_2 = Rte_Write_PP_VdyAdapter_VdyOutputNvMData_VdyNvMInOutData(&arg_Write_data_2);
  (void)ret_Write_2;
  ret_Write_3 = Rte_Write_PP_VdyAdapter_VdyOffsets_VdyOffsets(&arg_Write_data_3);
  (void)ret_Write_3;
  ret_Write_4 = Rte_Write_PP_VdyAdapter_VehDyn_VehDyn(&arg_Write_data_4);
  (void)ret_Write_4;
  ret_Read = Rte_Read_RP_Fcu_BaseCtrlData_BaseCtrlData(&arg_Read_data);
  (void)ret_Read;
  ret_Read_0 = Rte_Read_RP_Cdm_VdyInputNvMData_VdyNvMInOutData(&arg_Read_data_0);
  (void)ret_Read_0;
  ret_Read_1 = Rte_Read_RP_Fcu_VehPar_VehPar(&arg_Read_data_1);
  (void)ret_Read_1;
  ret_Read_2 = Rte_Read_RP_Fcu_VehSig_VehSig(&arg_Read_data_2);
  (void)ret_Read_2;
  ret_Call = Rte_Call_RP_NvM_VdyBlockOperation_GetErrorStatus(&arg_Call_RequestResultPtr);
  (void)ret_Call;
  ret_Call_0 = Rte_Call_RP_NvM_VdyBlockOperation_ReadBlock(arg_Call_DstPtr);
  (void)ret_Call_0;
  ret_Call_1 = Rte_Call_RP_NvM_VdyBlockOperation_SetRamBlockStatus(arg_Call_BlockChanged);
  (void)ret_Call_1;
  ret_Call_2 = Rte_Call_RP_NvM_VdyBlockOperation_WriteBlock(arg_Call_SrcPtr);
  (void)ret_Call_2;

} /* FUNC(void, RTE_CODE) VdyAdapter_MainFunction (void) */

#define VdyAdapter_STOP_SEC_CODE
#include <VdyAdapter_MemMap.h>

#define VdyAdapter_START_SEC_CODE
#include <VdyAdapter_MemMap.h>
FUNC(void, RTE_CODE) VdyAdapter_VdyExec (void)
{
  AlgoCompState_t arg_Write_data = 
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
    {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U},
    0U,
    0U,
    0U,
    0U
  };
  Std_ReturnType ret_Write;
  VDYErrors_t arg_Write_data_0 = 
  {
    0U,
    {
      0U,
      0U,
      0U,
      0U,
      {0U, 0U, 0U}
    },
    {
      0U,
      0U
    },
    {
      0U
    },
    {
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
      0U
    }
  };
  Std_ReturnType ret_Write_0;
  VDYEstCurves_t arg_Write_data_1 = 
  {
    0U,
    {
      0U,
      0U,
      0U,
      0U,
      {0U, 0U, 0U}
    },
    {
      0.0f
    },
    {
      0.0f
    },
    {
      0.0f
    },
    {
      0.0f
    },
    {
      0.0f
    },
    {
      0.0f
    },
    {
      0.0f
    },
    {
      0.0f
    }
  };
  Std_ReturnType ret_Write_1;
  VDYNvIoData_t arg_Write_data_2 = 
  {
    0U,
    {
      0U,
      0U,
      0U,
      0U,
      {0U, 0U, 0U}
    },
    {
      0.0f,
      0U
    },
    {
      0.0f,
      0U,
      0U,
      0,
      0U
    },
    {
      0.0f,
      0.0f,
      0.0f,
      0U
    },
    {
      0.0f,
      0U
    },
    {{
      0.0f,
      0.0f,
      0.0f
    }, 
    {
      0.0f,
      0.0f,
      0.0f
    }, 
    {
      0.0f,
      0.0f,
      0.0f
    }},
    {
      0.0f,
      0.0f,
      0U,
      0U
    },
    0U
  };
  Std_ReturnType ret_Write_2;
  VDYOffsets_t arg_Write_data_3 = 
  {
    0U,
    {
      0U,
      0U,
      0U,
      0U,
      {0U, 0U, 0U}
    },
    {
      0.0f,
      0,
      0.0f,
      0.0f
    },
    {
      0.0f,
      0.0f,
      0
    },
    {
      0.0f,
      0.0f,
      0
    }
  };
  Std_ReturnType ret_Write_3;
  VehDyn_t arg_Write_data_4 = 
  {
    0U,
    {
      0U,
      0U,
      0U,
      0U,
      {0U, 0U, 0U}
    },
    {
      0.0f,
      0.0f,
      0.0f,
      0.0f,
      {
        0.0f,
        {
          0U,
          0U,
          0U,
          0U,
          {0U, 0U, 0U}
        },
        0.0f,
        0.0f,
        {
          0U,
          0U,
          0U,
          0U,
          {0U, 0U, 0U}
        },
        0.0f,
        0.0f
      },
      {
        0.0f,
        0.0f,
        0.0f,
        0.0f,
        0.0f,
        0.0f,
        0U,
        0U,
        0U,
        0U
      },
      {
        0.0f,
        0.0f
      },
      0U,
      0U,
      0U,
      0U
    },
    {
      {
        0.0f,
        0.0f,
        0.0f,
        0.0f,
        0.0f
      },
      {
        0U,
        0U,
        0U,
        0U,
        {0U, 0U, 0U}
      },
      0.0f,
      {
        0.0f,
        {
          0U,
          0U,
          0U,
          0U,
          {0U, 0U, 0U}
        },
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
        0.0f
      },
      {
        0.0f,
        {
          0U,
          0U,
          0U,
          0U,
          {0U, 0U, 0U}
        },
        0.0f,
        0.0f
      },
      {
        0.0f,
        {
          0U,
          0U,
          0U,
          0U,
          {0U, 0U, 0U}
        },
        0.0f
      },
      {
        0.0f,
        0.0f
      },
      {
        0.0f,
        0.0f,
        0.0f,
        0.0f
      }
    },
    {
      0.0f,
      0U,
      0U,
      0U,
      0U
    },
    {
      0.0f,
      0U,
      0U,
      0U,
      0U
    },
    {0U, 0U, 0U},
    {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
  };
  Std_ReturnType ret_Write_4;
  BaseCtrlData_t arg_Read_data;
  Std_ReturnType ret_Read;
  VDYNvIoData_t arg_Read_data_0;
  Std_ReturnType ret_Read_0;
  VehPar_t arg_Read_data_1;
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

  ret_Write = Rte_Write_PP_VdyAdapter_AlgoCompState_AlgoCompState(&arg_Write_data);
  (void)ret_Write;
  ret_Write_0 = Rte_Write_PP_VdyAdapter_VdyErrors_VdyErrors(&arg_Write_data_0);
  (void)ret_Write_0;
  ret_Write_1 = Rte_Write_PP_VdyAdapter_VdyEstCurves_VdyEstCurves(&arg_Write_data_1);
  (void)ret_Write_1;
  ret_Write_2 = Rte_Write_PP_VdyAdapter_VdyOutputNvMData_VdyNvMInOutData(&arg_Write_data_2);
  (void)ret_Write_2;
  ret_Write_3 = Rte_Write_PP_VdyAdapter_VdyOffsets_VdyOffsets(&arg_Write_data_3);
  (void)ret_Write_3;
  ret_Write_4 = Rte_Write_PP_VdyAdapter_VehDyn_VehDyn(&arg_Write_data_4);
  (void)ret_Write_4;
  ret_Read = Rte_Read_RP_Fcu_BaseCtrlData_BaseCtrlData(&arg_Read_data);
  (void)ret_Read;
  ret_Read_0 = Rte_Read_RP_Cdm_VdyInputNvMData_VdyNvMInOutData(&arg_Read_data_0);
  (void)ret_Read_0;
  ret_Read_1 = Rte_Read_RP_Fcu_VehPar_VehPar(&arg_Read_data_1);
  (void)ret_Read_1;
  ret_Read_2 = Rte_Read_RP_Fcu_VehSig_VehSig(&arg_Read_data_2);
  (void)ret_Read_2;
  ret_Call = Rte_Call_RP_MtsiAdapter_MeasFreezeData_MeasFreezeData(arg_Call_VirtualAddress, arg_Call_FunctionId, arg_Call_Data, arg_Call_Length);
  (void)ret_Call;
  ret_Call_0 = Rte_Call_RP_MtsiAdapter_UpdateTaskCycle_UpdateTaskCycle(arg_Call_TaskId);
  (void)ret_Call_0;

} /* FUNC(void, RTE_CODE) VdyAdapter_VdyExec (void) */

#define VdyAdapter_STOP_SEC_CODE
#include <VdyAdapter_MemMap.h>

/*
  ------------------------[runnable-independent API]-------------------------

  Copy and paste the following API to those runnable entity functions where
  you want to use them.

  ------------------------[port handle API]----------------------------------
  ------------------------[per instance memory API]--------------------------
 */

/** @} doxygen end group definition  */
/* ==================[end of file]============================================ */