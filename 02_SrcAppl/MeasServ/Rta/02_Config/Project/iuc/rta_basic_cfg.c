// Copyright (C) Continental AG
// All Rights Reserved
// COMPONENT: RTA - RealTimeAnalysis
/// \file
/// \brief This file contains the basic configuration of the RTA

#include <Std_Types.h>
#include <rta_cfg.h>
#include <rta_basic_cfg.h>
#include <rta_globalids.h>
#include "os_rta_taskid_lut_cfg.h"
#include "os_rta_task_ids.h"
#include "rta_prj_cfg.h"
#ifdef __cplusplus
extern "C"
{
#endif


#define CddSwc_RTA_START_SEC_CONST_UNSPECIFIED
#include <rta_memmap_cfg.h>

static const uint8 a_taskIdLut[OS_NUMBER_OF_TASKS] =
{
    OS_RTA_TASKID_LUT_INITIALIZER
};

#define CddSwc_RTA_STOP_SEC_CONST_UNSPECIFIED
#include <rta_memmap_cfg.h>


#define CddSwc_RTA_START_SEC_CONST_UNSPECIFIED
#include <rta_memmap_cfg.h>

const RTA_t_BasicCfg rta_basicCfg =
{
  a_taskIdLut,                             // p_taskIdLut
  OS_NUMBER_OF_TASKS,                      // u_sizeOfTaskIdLut
  RTA_INTERRUPT_LOCAL_ID_OFFSET,           // u_isrLocalIdOffset
  (uint8)OS_RTA_TASKID_Interrupts          // u_taskIdInterrupts
};

#define CddSwc_RTA_STOP_SEC_CONST_UNSPECIFIED
#include <rta_memmap_cfg.h>


#ifdef __cplusplus
}
#endif
