// Copyright (C) Continental AG
// All Rights Reserved
// COMPONENT: RTA - RealTimeAnalysis
/// \file
/// \brief This header declares the internal PreTaskHook and internal PreIsrHook, which are called inside the RTA.

#ifndef RTA_OS_HOOKS_H
#define RTA_OS_HOOKS_H

#include <rta_basic_cfg.h>
#include <rta_defs.h>

#ifdef __cplusplus
extern "C"
{
#endif


typedef enum {
  RTA_THREAD_TYPE_NONE,
  RTA_THREAD_TYPE_ISR,
  RTA_THREAD_TYPE_TASK
}RTA_t_ThreadType;


#define CddSwc_RTA_START_SEC_CODE
#include <rta_memmap_cfg.h>

/// \brief This function gets the RTA Task ID.
///
/// \pre
///   none
/// \post
///   none
/// \globals
///     none
/// \param
///   u_TASK_ID - TaskID(uint32)
/// \return
///   u_rtaTaskID - TaskID
/// \InOutCorrelation
///     Get RTA Task ID
///
/// \callsequence
/// \image html u_GetRtaTaskID.png
/// \startuml "u_GetRtaTaskID"
/// title u_GetRtaTaskID Sequence Diagram
/// [--> RTA_OS_Hooks : u_GetRtaTaskID(const uint32 u_TASK_ID)
/// activate RTA_OS_Hooks
/// alt if sizeOfTaskID > u_TASK_ID
/// note right of RTA_OS_Hooks : Update TaskID
/// else ELSE
/// note right of RTA_OS_Hooks : Update TaskID
/// end
/// [<-- RTA_OS_Hooks : // return TaskID //
/// \enduml
///
/// \traceability
///   TODO
static inline uint8 u_GetRtaTaskID(const uint32 u_TASK_ID)
{
  uint8                       u_rtaTaskID;

  if(rta_basicCfg.u_sizeOfTaskIdLut > u_TASK_ID)
  {
    u_rtaTaskID = rta_basicCfg.p_taskIdLut[u_TASK_ID];
  }
  else
  {
    u_rtaTaskID = UINT8_MAX_VALUE;
  }

  return u_rtaTaskID;
}

#define CddSwc_RTA_STOP_SEC_CODE
#include <rta_memmap_cfg.h>


/// \brief This function generates the algo end for an interrupt.
///
/// \pre
///   none
/// \post
///   none
/// \globals
///     none
/// \param
///   u_ISR_ID  - Interrupt ID(uint32)
///   p_dataSet - Control pointer for a specific core.
/// \return
///   none
/// \InOutCorrelation
///     Generate taskSwitch for the last thread if that's an interrupt.
///
/// \callsequence
/// \image html RTA_v_PreIsrHookIntern.png
/// \startuml "RTA_v_PreIsrHookIntern"
/// title RTA_v_PreIsrHookIntern Sequence Diagram
/// [--> RTA_OS_Hooks : RTA_v_PreIsrHookIntern(const RTA_t_DataSet* const p_dataSet, const uint32 u_ISR_ID)
/// activate RTA_OS_Hooks
/// alt if last interrupt was an interrupt
/// noteover of RTA_OS_Hooks : Generate taskSwitch only if the last thread is not interrupt
/// RTA_OS_Hooks -> RTA_Add_Event : v_AddEvent_OS_Context(p_dataSet, &eventData)
/// activate RTA_Add_Event
/// RTA_Add_Event --> RTA_OS_Hooks : // done //
/// deactivate RTA_Add_Event
/// end
/// noteover of RTA_OS_Hooks : Update currentThread
/// [<-- RTA_OS_Hooks : // done //
/// \enduml
///
/// \traceability
///   TODO
void RTA_v_PreIsrHookIntern(const uint32 u_ISR_ID);


/// \brief This function generates the TSE for a specific task.
///
/// \pre
///   none
/// \post
///   none
/// \globals
///     none
/// \param
///   u_TASK_ID - TaskID(uint32)
///   p_dataSet - Control pointer for a specific core.
/// \return
///   none
/// \InOutCorrelation
///     Generate taskSwitch for the task ID.
///
/// \callsequence
/// \image html RTA_v_PreTaskHookIntern.png
/// \startuml "RTA_v_PreTaskHookIntern"
/// title RTA_v_PreTaskHookIntern Sequence Diagram
/// [--> RTA_OS_Hooks : RTA_v_PreTaskHookIntern(const RTA_t_DataSet* const p_dataSet, const uint32 u_TASK_ID)
/// activate RTA_OS_Hooks
/// note right of RTA_OS_Hooks : Add the taskSwitchEvent\nUpdate currentThread
/// [<-- RTA_OS_Hooks : // done //
/// \enduml
///
/// \traceability
///   TODO
void RTA_v_PreTaskHookIntern(const uint32 u_TASK_ID);


#ifdef __cplusplus
}
#endif

#endif // #ifndef RTA_OS_HOOKS_H
