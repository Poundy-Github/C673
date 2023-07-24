// Copyright (C) Continental AG
// All Rights Reserved
// COMPONENT: RTA - RealTimeAnalysis
/// \file
/// \brief This file implements the basic functionality for the RTA related to the OS.
///        Especially here the functions RTA_v_PreIsrHookIntern() and RTA_v_PreTaskHookIntern() are implemented.
///        Due to the different ISR instrumentation possibilities of the interrupts there are three variants available:
///        - ISR basic instrumentation (This variant shall be also used in case of ISR off.)
///        - ISR start instrumentation
///        - ISR duration instrumentation (full)
///        Here the variant "ISR duration instrumentation" is implemented

#include <Std_Types.h>
#include <rta_os_hooks.h>
#include <rta.h>
#include <rta_globalids.h>
#include <rta_basics.h>
#include <rta_req_if.h>
#include <rta_add_event.h>
#include <rta_suspend_priv.h>

#ifdef __cplusplus
extern "C"
{
#endif


#define CddSwc_RTA_START_SEC_CODE
#include <rta_memmap_cfg.h>

void RTA_v_PreIsrHookIntern(const uint32 u_ISR_ID)
{
  boolean                       b_Suspended;
  const RTA_t_DataSet* const    p_dataSet       = RTA_p_GetDataSet();

  // Check whether we got a dataSet
  if(NULL != p_dataSet)
  {
    if(b_TRUE  == p_dataSet->p_ctrl->b_initialized)
    {
      b_Suspended = RTA_b_Suspended();
      if(b_FALSE == b_Suspended)
      {
        // Check whether we have a different thread than before
        if((((uint32)RTA_THREAD_TYPE_ISR << SHIFT_THREAD_TYPE) | u_ISR_ID) != p_dataSet->p_ctrl->u_IdCurrentThread)
        {
          RTA_t_EventData eventData;

          // Check if the last thread was an interrupt
          if((uint8)RTA_THREAD_TYPE_ISR != (uint8)(p_dataSet->p_ctrl->u_IdCurrentThread >> SHIFT_THREAD_TYPE))
          {
            // We generate taskSwitch event only if the last thread was not an interrupt
            // Here we have a taskSwitchEvent -> no need to fill localID and optData
            eventData.u_EventType  = (uint8)RTA_EVT_TASKSWITCH;
            eventData.u_GlobalId   = rta_basicCfg.u_taskIdInterrupts;

            v_AddEvent_OS_Context(p_dataSet, &eventData);
          }
          else
          {
            // last thread was an interrupt, generate the related AlgoEnd event
            eventData.u_EventType  = (uint8)RTA_EVT_ALGOEND;
            eventData.u_GlobalId   = RTA_GLOBALID_INTERRUPTS;
            eventData.u_LocalId    = (uint8)p_dataSet->p_ctrl->u_IdCurrentThread + rta_basicCfg.u_isrLocalIdOffset;
            eventData.u_OptData    = (uint8)0;

            v_AddEvent_OS_Context(p_dataSet, &eventData);
          }
          // Generate also a startEvent for the new interrupt
          eventData.u_EventType  = (uint8)RTA_EVT_ALGOSTART;
          eventData.u_GlobalId   = RTA_GLOBALID_INTERRUPTS;
          eventData.u_LocalId    = (uint8)u_ISR_ID + rta_basicCfg.u_isrLocalIdOffset;
          eventData.u_OptData    = (uint8)0;

          v_AddEvent_OS_Context(p_dataSet, &eventData);

          // Finally update currentThread
          p_dataSet->p_ctrl->u_IdCurrentThread=(((uint32)RTA_THREAD_TYPE_ISR<<SHIFT_THREAD_TYPE) | u_ISR_ID);
        }
      }
    }
  }
}


void RTA_v_PreTaskHookIntern(const uint32 u_TASK_ID)
{
  boolean                       b_Suspended;
  const RTA_t_DataSet* const    p_dataSet       = RTA_p_GetDataSet();

  // Check whether we got a dataSet
  if(NULL != p_dataSet)
  {
    if(b_TRUE  == p_dataSet->p_ctrl->b_initialized)
    {
      b_Suspended = RTA_b_Suspended();
      if(b_FALSE == b_Suspended)
      {
        // Check whether we have a different thread than before
        if((((uint32)RTA_THREAD_TYPE_TASK << SHIFT_THREAD_TYPE) | u_TASK_ID) != p_dataSet->p_ctrl->u_IdCurrentThread)
        {
          RTA_t_EventData eventData;

          // Check if the last thread was an interrupt
          if((uint8)RTA_THREAD_TYPE_ISR == (uint8)(p_dataSet->p_ctrl->u_IdCurrentThread >> SHIFT_THREAD_TYPE))
          {
            // The last thread was an interrupt - generate related ENDEVENT
            eventData.u_EventType  = (uint8)RTA_EVT_ALGOEND;
            eventData.u_GlobalId   = RTA_GLOBALID_INTERRUPTS;
            eventData.u_LocalId    = (uint8)p_dataSet->p_ctrl->u_IdCurrentThread + rta_basicCfg.u_isrLocalIdOffset;
            eventData.u_OptData    = (uint8)0;

            v_AddEvent_OS_Context(p_dataSet, &eventData);
          }

          // Add the taskSwitchEvent -> no need to fill localID and optData
          eventData.u_EventType  = (uint8)RTA_EVT_TASKSWITCH;
          eventData.u_GlobalId   = u_GetRtaTaskID(u_TASK_ID);
          v_AddEvent_OS_Context(p_dataSet, &eventData);

          // Finally update currentThread
          p_dataSet->p_ctrl->u_IdCurrentThread = (((uint32)RTA_THREAD_TYPE_TASK << SHIFT_THREAD_TYPE) | u_TASK_ID);
        }
      }
    }
  }
}

#define CddSwc_RTA_STOP_SEC_CODE
#include <rta_memmap_cfg.h>


#ifdef __cplusplus
}
#endif
