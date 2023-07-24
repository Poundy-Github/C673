// Copyright (C) Continental AG
// All Rights Reserved
// COMPONENT: RTA - RealTimeAnalysis
/// \file
/// \brief This header contains the configuration interface regarding the task- and isr-Information which is provided to PMA.

#ifndef RTA_TASK_ISR_DATA_SETS_H
#define RTA_TASK_ISR_DATA_SETS_H

#include <rta_task_isr_info.h>

#ifdef __cplusplus
extern "C"
{
#endif


typedef struct
{
  RTA_t_TaskIsrInfo** p_taskIsrInfo;
  uint32              u_numberOfCores;
}RTA_t_TaskIsrInfoHandler;


extern const RTA_t_TaskIsrInfoHandler rta_taskIsrInfoHandler;


#ifdef __cplusplus
}
#endif

#endif // #ifndef RTA_TASK_ISR_DATA_SETS_H
