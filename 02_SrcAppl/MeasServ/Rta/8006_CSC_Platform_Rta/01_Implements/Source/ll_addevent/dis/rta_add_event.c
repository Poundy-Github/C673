// Copyright (C) Continental AG
// All Rights Reserved
// COMPONENT: RTA - RealTimeAnalysis
/// \file
/// \brief This file implements all public functions for the feature 'lockless add event'.
///        It is intended for the case where the feature 'lockless add event' shall be disabled.
///        This means that here disable/Enable interrupts is used to ensure data consistency in the rtaBuffers.

#include <Std_Types.h>
#include <rta_add_event.h>
#include <rta_req_if.h>
#include <rta_defs.h>
#include <rta_suspend_priv.h>

#ifdef __cplusplus
extern "C"
{
#endif


#define CddSwc_RTA_START_SEC_CODE
#include <rta_memmap_cfg.h>

 void RTA_v_PrepareBuffersAtBufferswitch(const RTA_t_DataSet* const p_dataSet, RTA_t_BufferGeneric* const p_oldRtaBuffer,  RTA_t_BufferGeneric* const p_newRtaBuffer)
{
  // Nothing to do in case of normal addEvent
}


void RTA_v_InternalAddEvent(const RTA_t_DataSet* const p_dataSet, const RTA_t_EventData* const p_EVENT_DATA)
{
  // Disable interrupts
  RTA_ReqIf_v_DisableInterrupts();

  if(b_FALSE == RTA_b_Suspended())
  {
    // Get address of current rtaBuffer and get the current eventIndex
    RTA_t_BufferGeneric* const p_rtaBuffer = p_dataSet->p_params->a_ptrRtaBuffer[p_dataSet->p_ctrl->u_rtaBufferIndex];

    //Check if there is still place in eventContainer
    if (p_dataSet->p_params->u_maxNumberOfRtaEvents > p_rtaBuffer->RtaBufferHeader.u_MaxEventIndex)
    {
      // Get next free index of the eventContainer
      RTA_t_EventData* const p_eventData = &p_rtaBuffer->a_EventContainer[p_rtaBuffer->RtaBufferHeader.u_MaxEventIndex];
      // Fill in the relevant data
      p_eventData->u_RelTime_us = RTA_u_GetRelativeLocalTime(p_dataSet->p_ctrl->u_localTime);

      p_eventData->u_EventType  = p_EVENT_DATA->u_EventType;
      p_eventData->u_GlobalId   = p_EVENT_DATA->u_GlobalId;
      p_eventData->u_LocalId    = p_EVENT_DATA->u_LocalId;
      p_eventData->u_OptData    = p_EVENT_DATA->u_OptData;
      // Increment the event index
      p_rtaBuffer->RtaBufferHeader.u_MaxEventIndex++;
    }
    else
    {
      // Buffer is full - set the bufferOverflowBit in ctrlFlags of the buffer
      p_rtaBuffer->RtaBufferHeader.u_CtrlFlags |= RTA_BUFFER_OVERFLOW_FLAG;
    }
  }

  // Enable interrupts again
  RTA_ReqIf_v_EnableInterrupts();
}


void v_AddEvent_OS_Context(const RTA_t_DataSet* const p_dataSet, const RTA_t_EventData* const p_EVENT_DATA)
{
  RTA_t_BufferGeneric* const p_rtaBuffer = p_dataSet->p_params->a_ptrRtaBuffer[p_dataSet->p_ctrl->u_rtaBufferIndex];

  // Check if buffer is already full
  if(p_dataSet->p_params->u_maxNumberOfRtaEvents > p_rtaBuffer->RtaBufferHeader.u_MaxEventIndex)
  {
    // Buffer not full - fill next event
    RTA_t_EventData* const p_eventData = &p_rtaBuffer->a_EventContainer[p_rtaBuffer->RtaBufferHeader.u_MaxEventIndex];
    p_eventData->u_RelTime_us = RTA_u_GetRelativeLocalTime(p_dataSet->p_ctrl->u_localTime);
    p_eventData->u_EventType  = p_EVENT_DATA->u_EventType;
    p_eventData->u_GlobalId   = p_EVENT_DATA->u_GlobalId;
    p_eventData->u_LocalId    = p_EVENT_DATA->u_LocalId;
    p_eventData->u_OptData    = p_EVENT_DATA->u_OptData;
    // Increment index
    p_rtaBuffer->RtaBufferHeader.u_MaxEventIndex++;
  }
  else
  {
    // Buffer is full - set the bufferOverflowBit in ctrlFlags of the buffer
    p_rtaBuffer->RtaBufferHeader.u_CtrlFlags |= RTA_BUFFER_OVERFLOW_FLAG;
  }

}

#define CddSwc_RTA_STOP_SEC_CODE
#include <rta_memmap_cfg.h>


#ifdef __cplusplus
}
#endif
