// Copyright (C) Continental AG
// All Rights Reserved
// COMPONENT: RTA - RealTimeAnalysis
/// \file
/// \brief This header declares all public functions of the feature 'lockless add event', which are called inside the RTA.

#ifndef RTA_ADD_EVENT_H
#define RTA_ADD_EVENT_H

#include <rta_datasets.h>

#ifdef __cplusplus
extern "C"
{
#endif


/// \brief Function which prepares buffers at the buffer switch stage.
///
/// \pre
///   None
/// \post
///   None
/// \param
///   [in] p_dataSet - Points to the dataSet \n
///   [in] p_oldRtaBuffer - Pointer to the old buffer \n
///   [in] p_newRtaBuffer - Pointer to the new buffer \n
///
/// \InOutCorrelation
///   The old buffer will be checked to see if the maxEventIndex is up to date.\nPerform updates and update the new RTA Buffer for lockFree RTA.
///
/// \return
///   None
///
/// \globals
///   None
///
/// \callsequence
/// \image html RTA_v_PrepareBuffersAtBufferswitch.png Sequence Diagram
/// \startuml "RTA_v_PrepareBuffersAtBufferswitch"
/// title RTA_v_PrepareBuffersAtBufferswitch Sequence Diagram
/// [--> RTA_Add_Event: v_DetermineBufferSendOrder(void)
/// activate RTA_Add_Event
/// loop Maximum number of RTA Events
/// note right of RTA_Add_Event : Get entry ID from the old RTA Buffer.
/// alt if entry_value == MAX_VALUE
/// note right of RTA_Add_Event: Index is up to date -> terminate the loop
/// else ELSE
/// note right of RTA_Add_Event: Current entry is filled -> increment index.
/// end
/// end
/// RTA_Add_Event -> RTA_Req_If: (void)RTA_ReqIf_v_MemSet(p_newRtaBuffer->a_EventContainer, (sint16)UINT8_MAX_VALUE, (uint32)sizeof(RTA_t_EventData)*(p_newRtaBuffer->RtaBufferHeader.u_MaxEventIndex));
/// activate RTA_Req_If
/// RTA_Req_If --> RTA_Add_Event: // done //
/// deactivate RTA_Req_If
/// [<-- RTA_Add_Event : // done //
/// deactivate RTA_Add_Event
/// \enduml
///
/// \InOutCorrelation
///   This function fills the a_bufferSendList with pointers to the rtaBuffers in correct send order.
///   The older buffer has to be send first. Normally that buffer with the lower bufferCounter is the older one.
///   But in case of counterOverflow it is vice versa.
///
/// \traceability
///   TODO
void RTA_v_PrepareBuffersAtBufferswitch(const RTA_t_DataSet* const p_dataSet, RTA_t_BufferGeneric* const p_oldRtaBuffer,  RTA_t_BufferGeneric* const p_newRtaBuffer);


/// \brief Function which prepares buffers at the buffer switch stage.
///
/// \pre
///   None
/// \post
///   None
/// \param
///   [in] p_dataSet - Points to the dataSet \n
///   [in] p_EVENT_DATA - Pointer to the structure of an RTA Event \n
///
/// \InOutCorrelation
///   This function will add an internal RTA Event by trying for maximum 20 times in order to avoid blocking OS.
///
/// \return
///   void
///
/// \globals
///   None
///
/// \callsequence
/// \image html RTA_v_InternalAddEvent.png Sequence Diagram
/// \startuml "RTA_v_InternalAddEvent"
/// title RTA_v_InternalAddEvent Sequence Diagram
/// [--> RTA_Add_Event: RTA_v_InternalAddEvent(const RTA_t_DataSet* const p_dataSet, const RTA_t_EventData* const p_EVENT_DATA)
/// activate RTA_Add_Event
/// RTA_Add_Event -> RTA_Suspend: RTA_b_Suspended()
/// activate RTA_Suspend
/// RTA_Suspend --> RTA_Add_Event: // return status //
/// deactivate RTA_Suspend
/// note right of RTA_Add_Event: Try until RTA Event is stored.
/// loop 0 < s_retry
/// note right of RTA_Add_Event: Check if it is place in the eventContainer
/// alt if index_ID < maxNumberOfRtaEvents
/// note right of RTA_Add_Event: Find next free index
/// loop UINT64_MAX_VALUE != (*((const uint64*)&eventDataExcl))
/// RTA_Add_Event -> RTA_ExLoadStore: RTA_LdrexEvent(p_curEventOut)
/// activate RTA_ExLoadStore
/// RTA_ExLoadStore --> RTA_Add_Event: // return result //
/// alt if load_result != UINT64_MAX_VALUE
/// note right of RTA_Add_Event: Go to next index, unless buffer is full.
/// alt if index_ID == maxNumberOfRtaEvents
/// note right of RTA_Add_Event: Buffer full - set OverFlow bit and abort\nbreak from loop
/// end
/// end
/// end loop
/// note right of RTA_Add_Event: Attempt to store event data
/// alt if 0 < s_retry
/// alt if bufferSwitchCnt == u_bufferSwitchCnt
/// note right of RTA_Add_Event: Prepare event data
/// RTA_Add_Event -> RTA_Suspend: RTA_u_GetRelativeLocalTime(p_dataSet->p_ctrl->u_localTime)
/// activate RTA_Suspend
/// RTA_Suspend --> RTA_Add_Event: // return relative time //
/// deactivate RTA_Suspend
/// RTA_Add_Event -> RTA_ExLoadStore: RTA_b_StrexEvent(p_curEventOut, &eventData)
/// activate RTA_ExLoadStore
/// RTA_ExLoadStore --> RTA_Add_Event: // return ((uint32)0 == u_result) //
/// deactivate RTA_ExLoadStore
/// alt if result == 0
/// note right of RTA_Add_Event: Increment the event index\nExclusive load of u_MaxEventIndex
/// RTA_Add_Event -> RTA_ExLoadStore: RTA_u_Ldrex32(&(p_rtaBuffer->RtaBufferHeader.u_MaxEventIndex))
/// activate RTA_ExLoadStore
/// RTA_ExLoadStore --> RTA_Add_Event: // return result //
/// deactivate RTA_ExLoadStore
/// alt if now_IndexID < Index_ID && bufferSwitchCnt == u_bufferSwitchCnt
/// RTA_Add_Event -> RTA_ExLoadStore: (void)RTA_b_Strex32(&p_rtaBuffer->RtaBufferHeader.u_MaxEventIndex, u_idx)
/// activate RTA_ExLoadStore
/// RTA_ExLoadStore --> RTA_Add_Event: // return result //
/// deactivate RTA_ExLoadStore
/// else ELSE
/// note right of RTA_Add_Event: RTA Event stored, stop here.
/// end
/// else ELSE
/// note right of RTA_Add_Event: Try again in next round\nIncrement retryBuffSwapped
/// end
/// end
/// else ELSE
/// note right of RTA_Add_Event: Buffer full - set bufferOverFlow bit.
/// end loop
/// alt it s_retry == 0
/// note right of RTA_Add_Event: increment counter
/// end
/// end
/// end
/// [<-- RTA_Add_Event : // done //
/// deactivate RTA_Add_Event
/// \enduml
///
/// \traceability
///   to be added
void RTA_v_InternalAddEvent(const RTA_t_DataSet* const p_dataSet, const RTA_t_EventData* const p_EVENT_DATA);


/// \brief This function inserts a new rtaEvent into current rtaBuffer of the corresponding dataSet.
///
///This function must be called only from micro kernel context (by the function MK_QmDumpThreadStateChange).
///
/// \pre
///   None
/// \post
///   None
/// \param  [in] p_dataSet - Pointer to corresponding dataset \n
/// \param  [in] p_EVENT_DATA - Pointer to the rtaEventData which shall be generated \n
/// \return
///   void
///
/// \InOutCorrelation
///   Given rtaEvent is stored at the next free entry of currently active rtaBuffer.
///
/// \callsequence
/// \image html v_AddEvent_OS_Context.png
/// \startuml "v_AddEvent_OS_Context"
/// title v_AddEvent_OS_Context Sequence Diagram
/// [--> RTA_Add_Event : v_AddEvent_OS_Context(const RTA_t_DataSet* const p_dataSet, const RTA_t_EventData* const p_EVENT_DATA)
/// activate RTA_Add_Event
/// RTA_Add_Event -> RTA_Add_Event: RTA_v_InternalAddEvent(p_dataSet, p_EVENT_DATA)
/// activate RTA_Add_Event
/// deactivate RTA_Add_Event
/// [<-- RTA_Add_Event : // done //
/// deactivate RTA_Add_Event
/// \enduml
///
/// traceability
///   <a href="doors://rbgs854a:40000/?version=2&prodID=0&view=00000006&urn=urn:telelogic::1-503e822e5ec3651e-O-843-0005ebe0">Link to L4 Design Spec</a>
void v_AddEvent_OS_Context(const RTA_t_DataSet* const p_dataSet, const RTA_t_EventData* const p_EVENT_DATA);


#ifdef __cplusplus
}
#endif

#endif //#ifndef RTA_ADD_EVENT_H
