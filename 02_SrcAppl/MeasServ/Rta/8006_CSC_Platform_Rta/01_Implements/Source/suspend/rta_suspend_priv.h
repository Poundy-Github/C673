// Copyright (C) Continental AG
// All Rights Reserved
// COMPONENT: RTA - RealTimeAnalysis
/// \file
/// \brief This header declares all public functions related to the feature 'suspend' which are called inside the RTA.

#ifndef RTA_SUSPEND_PRIV_H
#define RTA_SUSPEND_PRIV_H

#ifdef __cplusplus
extern "C"
{
#endif


/// \brief detects if RTA is suspended or not
///
/// \pre
///   RTA has to be initialized.
/// \post
///   depending on return value to RTA global functions, RTA functionality is on or off
/// \param
///   void
/// \return
///   b_suspended : boolean with range 0 = False and 1 = True
/// \globals
///   [in, out] RTA_t_SuspendTimes stores all time related information to make the supend / resume
///           function of RTA possible
/// \InOutCorrelation
///   Under following conditions the function shall return b_suspended = True: \n
///   - p_GetSuspendTime returns a valid pointer to the core specific a_suspendTimeList and
///   - u_timeSuspendStart > 0
/// \callsequence
///   \image html RTA_b_Suspended.png Sequence Diagram
///   \startuml RTA_b_Suspended.png
///   legend left
///     Task: called from any task or interrupt context
///     Task priority: any
///     Cycle time: not cyclically
///   endlegend
///     RTA -> RTA_Suspend: RTA_X() calls RTA_b_Suspended()
///     activate RTA_Suspend
///     RTA_Suspend -> RTA_Suspend: p_GetSuspendTime
///     activate RTA_Suspend
///     RTA_Suspend -> RTA_Ial: RTA_GET_CORE_ID
///     deactivate RTA_Suspend
///     activate RTA_Ial
///     RTA_Ial -> SysPal: GET_CORE_ID
///     deactivate RTA_Ial
///     activate SysPal
///     SysPal -> RTA_Suspend
///     deactivate SysPal
///     activate RTA_Suspend
///     alt RTA_NO_OF_CORES > u_CORE_ID
///     rnote over RTA_Suspend: p_suspendTime = a_suspendTimeList[u_CORE_ID]
///     else p_suspendTime = NULL
///     end
///     deactivate RTA_Suspend
///     opt p_suspendTime != NULL
///     opt p_suspendTime->u_timeSuspendStart > 0
///     rnote over RTA_Suspend: b_suspended = True
///     end
///     end
///     RTA_Suspend -->> RTA: b_suspended
///     deactivate RTA_Suspend
///   \enduml
///
/// \traceability
///   <a href="doors://rbgs854a:40000/?version=2&prodID=0&view=00000006&urn=urn:telelogic::1-503e822e5ec3651e-O-689-0005ebe0">
///            doors://rbgs854a:40000/?version=2&prodID=0&view=00000006&urn=urn:telelogic::1-503e822e5ec3651e-O-689-0005ebe0</a>
boolean RTA_b_Suspended(void);


/// \brief returns the system time reduced by the suspended time
///
/// \pre
///   RTA has to be initialized
/// \post
///   RTA_v_SwitchBuffer can set the reference time stamp u_RefTs_us and eliminates the suspended time gaps
/// \param
///   void
/// \return
///   uint64 reference time, range 0x00 ... 0x0000 0000 0000 0000, unit: us
/// \globals
///   [in, out] p_suspendTime, type RTA_t_SuspendTimes
/// \InOutCorrelation
///   When RTA is not suspended, u_timeSuspendedCycle is added to u_timeSuspendedAll, afterward u_timeSuspendedCycle is reset.
///   u_timeSuspendedCycle is set in RTA_v_Resume, so the suspended time is added one time after RTA is resumed.
///   return value is system time reduced by u_timeSuspendedAll converted in microseconds. \n
///   If p_suspendTime == NULL it returns simply the system time in microseconds
///
/// \callsequence
///   \image html RTA_u_GetSystemTime.png Sequence Diagram
///   \startuml RTA_u_GetSystemTime.png
///   legend left
///     Task: called by RTA_v_SwitchBuffer either from a cyclical interrupt or a task
///     Task priority: depends on plattform
///     Cycle time: system cycle or more frequently from RTE task context
///   endlegend
///     RTA -> RTA_Suspend: RTA_v_SwitchBuffer() calls RTA_u_GetSystemTime()
///     activate RTA_Suspend
///     RTA_Suspend -> RTA_Suspend: p_GetSuspendTime \n returns pointer to core specific dataset p_suspendTime
///     RTA_Suspend -> RTA_Ial: RTA_GET_SYSTEM_TIME_US
///     deactivate RTA_Suspend
///     activate RTA_Ial
///     RTA_Ial -> sys_time: GET_SYSTEM_TIME_US
///     deactivate RTA_Ial
///     activate sys_time
///     sys_time -->> RTA_Suspend
///     deactivate sys_time
///     activate RTA_Suspend
///     RTA_Suspend -> RTA_Suspend: RTA_b_Suspended
///     opt p_suspendTime != NULL
///       opt b_suspended == False
///         rnote over RTA_Suspend: u_timeSuspendedAll+=u_timeSuspendedCycle \n u_timeSuspendedCycle = 0
///       end
///       RTA_Suspend -> RTA_Ial: RTA_PAL_TICKS_TO_US
///       deactivate RTA_Suspend
///       activate RTA_Ial
///       RTA_Ial -> sys_pal: PAL_TICKS_TO_US (u_timeSuspendedAll)
///       deactivate RTA_Ial
///       activate sys_pal
///       sys_pal -->> RTA_Suspend
///       activate RTA_Suspend
///       rnote over RTA_Suspend: u_SystemTime - u_timeSuspendedAll
///     end
///     RTA_Suspend -->> RTA: returns system time minus suspended time
///     deactivate RTA_Suspend
///   \enduml
///
/// \traceability
///   <a href="doors://rbgs854a:40000/?version=2&prodID=0&view=00000006&urn=urn:telelogic::1-503e822e5ec3651e-O-690-0005ebe0">
///            doors://rbgs854a:40000/?version=2&prodID=0&view=00000006&urn=urn:telelogic::1-503e822e5ec3651e-O-690-0005ebe0"</a>
uint64 RTA_u_GetSystemTime(void);


/// \brief Function which returns local time reduced of u_referenceTime and u_timeSuspendedCycle \n
///        When RTA events are added this relative time (u_RelTime_us) must be set.
///
/// \param
///   u_referenceTime \n
///   range: uint32, \n
///   unit: us
/// \return
///   u_relativeTime \n
///   range: uint32 \n
///   unit: us
/// \InOutCorrelation
///   Get relative local time.
/// \callsequence
/// \image html RTA_u_GetRelativeLocalTime.png
/// \startuml "RTA_u_GetRelativeLocalTime"
/// title RTA_u_GetRelativeLocalTime Sequence Diagram
/// [--> RTA_Suspend : uint32 RTA_u_GetRelativeLocalTime(const uint32 u_referenceTime)
/// activate RTA_Suspend
/// RTA_Suspend -> RTA_Suspend: p_GetSuspendDataSet()
/// activate RTA_Suspend
/// deactivate RTA_Suspend
/// RTA_Suspend -> RTA_Req_If: RTA_ReqIf_u_GetLocalTimeInUs()
/// activate RTA_Req_If
/// RTA_Req_If --> RTA_Suspend: // return local time //
/// deactivate RTA_Req_If
/// alt if pointer NOT NULL
/// note right of RTA_Suspend: Update relative time
/// end
/// [<-- RTA_Suspend : // return u_relativeTime //
/// deactivate RTA_Suspend
/// \enduml
///
/// \traceability
///   <a href="doors://rbgs854a:40000/?version=2&prodID=0&view=00000006&urn=urn:telelogic::1-503e822e5ec3651e-O-691-0005ebe0">
///            doors://rbgs854a:40000/?version=2&prodID=0&view=00000006&urn=urn:telelogic::1-503e822e5ec3651e-O-691-0005ebe0</a>
uint32 RTA_u_GetRelativeLocalTime(const uint32 u_referenceTime);


#ifdef __cplusplus
}
#endif

#endif // #define RTA_SUSPEND_PRIV_H
