// Copyright (C) Continental AG
// All Rights Reserved
// COMPONENT: RTA - RealTimeAnalysis
/// @file
/// @brief    TODO


#include <Std_Types.h>
#include <rta_task_isr_datasets.h>
#include <rta_cfg.h>
#include <rta_req_if.h>

#ifdef __cplusplus
extern "C"
{
#endif


/** ***********************************************************************************************
\description This array contains pointers to all available taskIsrDataSets.
             See description of RTA_t_taskIsrDataSet for details.
***************************************************************************************************/

#define CddSwc_RTA_START_SEC_VAR_INIT_UNSPECIFIED
#include <rta_memmap_cfg.h>

static RTA_t_TaskIsrInfo* a_TaskIsrInfoList[RTA_NO_OF_CORES] =
{
  NULL
};
#define CddSwc_RTA_STOP_SEC_VAR_INIT_UNSPECIFIED
#include <rta_memmap_cfg.h>


#define CddSwc_RTA_START_SEC_CONST_UNSPECIFIED
#include <rta_memmap_cfg.h>

const RTA_t_TaskIsrInfoHandler rta_taskIsrInfoHandler =
{
  (RTA_t_TaskIsrInfo**)a_TaskIsrInfoList,  //taskIsrInfoHandler
  RTA_NO_OF_CORES                          //u_numberOfCores
};

#define CddSwc_RTA_STOP_SEC_CONST_UNSPECIFIED
#include <rta_memmap_cfg.h>


#ifdef __cplusplus
}
#endif

