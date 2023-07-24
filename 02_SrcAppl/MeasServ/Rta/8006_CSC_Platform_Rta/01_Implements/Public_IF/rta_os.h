// Copyright (C) Continental AG
// All Rights Reserved
// COMPONENT: RTA - RealTimeAnalysis
/// \file
/// \brief The RTA public interface for OS with PreTask- and PreISR-hooks

#ifndef RTA_OS_H
#define RTA_OS_H


#ifdef __cplusplus
extern "C"
{
#endif
typedef unsigned long uint32;
/// @brief
/// 	Function provides task measuring.\nFunction is called by OS before the execution of a task context switch.\nFunction is created in order to fulfill needs for measuring thread switching on normal operating systems.\n
///  @pre
///    RTA shall be initialized, and OS shall call this function before executing task.
///  @post
///    Data for measuring tasks added to RTA buffer
///  @param
///    [in] id: id of current task
///  @return
///    void
/// @InOutCorrelation
/// 	Update thread info for a specific core.
/// @callsequence
/// @image html RTA_v_PreTaskHook.png
/// @startuml "RTA_v_PreTaskHook"
/// title RTA_v_PreTaskHook Sequence Diagram
/// [--> RTA_OS_Hooks_Normal : RTA_v_PreTaskHook(const uint32 u_TASK_ID)
/// activate RTA_OS_Hooks_Normal
/// RTA_OS_Hooks_Normal -> RTA_Basics: RTA_p_GetDataSet()
/// activate RTA_Basics
/// RTA_Basics --> RTA_OS_Hooks_Normal: // return DataSet //
/// deactivate RTA_Basics
/// alt if pointer != NULL
/// RTA_OS_Hooks_Normal -> RTA_Suspend: RTA_b_Suspended()
/// activate RTA_Suspend
/// RTA_Suspend --> RTA_OS_Hooks_Normal: // return status //
/// deactivate RTA_Suspend
/// alt if control for core is initialized && status == b_FALSE
/// RTA_OS_Hooks_Normal -> RTA_OS_Hooks: RTA_v_PreTaskHookIntern(p_dataSet, u_TASK_ID)
/// activate RTA_OS_Hooks
/// RTA_OS_Hooks --> RTA_OS_Hooks_Normal: // done //
/// deactivate RTA_OS_Hooks
/// end
/// end
/// [<-- RTA_OS_Hooks_Normal : // done //
/// deactivate RTA_OS_Hooks_Normal
/// @enduml
/// @testmethod
/// 	@ref TEST01_RTA_v_PreTaskHook \n
/// 	@ref TEST02_RTA_v_PreTaskHook \n
/// 	@ref TEST03_RTA_v_PreTaskHook \n
/// @traceability
/// 	to be added
void RTA_v_PreTaskHook(const uint32 u_TASK_ID);

/// @brief
/// 	Function provides RTA switch events and measuring for interrupts.\nFunction is called by OS before the execution of interrupt routine.\nFunction is created in order to fulfill needs for measuring thread switching on normal EB operating system.\n
///  @pre
///    RTA shall be initialized, and OS shall call this function before executing ISR and interrupt measurement must be activated.
///  @post
///    Data for measuring interrupts added to RTA buffer
///  @param
///    [in] u_ISR_ID : id of current ISR
///  @return
///    void
/// @InOutCorrelation
/// 	Provide switch events and measuring for interrupts for a specific core.
/// @callsequence
/// @image html RTA_v_PreIsrHook.png
/// @startuml "RTA_v_PreIsrHook"
/// title RTA_v_PreIsrHook Sequence Diagram
/// [--> RTA_OS_Hooks_Normal : RTA_v_PreIsrHook(const uint32 u_ISR_ID)
/// activate RTA_OS_Hooks_Normal
/// RTA_OS_Hooks_Normal -> RTA_Basics: RTA_p_GetDataSet()
/// activate RTA_Basics
/// RTA_Basics --> RTA_OS_Hooks_Normal: // return DataSet //
/// deactivate RTA_Basics
/// alt if pointer != NULL
/// RTA_OS_Hooks_Normal -> RTA_Suspend: RTA_b_Suspended()
/// activate RTA_Suspend
/// RTA_Suspend --> RTA_OS_Hooks_Normal: // return status //
/// deactivate RTA_Suspend
/// alt if control for core is initialized && status == b_FALSE
/// RTA_OS_Hooks_Normal -> RTA_OS_Hooks: RTA_v_PreIsrHookIntern(p_dataSet, u_ISR_ID)
/// activate RTA_OS_Hooks
/// RTA_OS_Hooks --> RTA_OS_Hooks_Normal: // done //
/// deactivate RTA_OS_Hooks
/// end
/// end
/// [<-- RTA_OS_Hooks_Normal : // done //
/// deactivate RTA_OS_Hooks_Normal
/// @enduml
/// @testmethod
/// 	@ref TEST01_RTA_v_PreIsrHook \n
/// 	@ref TEST02_RTA_v_PreIsrHook \n
/// 	@ref TEST03_RTA_v_PreIsrHook \n
/// @traceability
/// 	to be added
void RTA_v_PreIsrHook(const uint32 u_ISR_ID);

#ifdef __cplusplus
}
#endif


#endif // #ifndef RTA_OS_H

