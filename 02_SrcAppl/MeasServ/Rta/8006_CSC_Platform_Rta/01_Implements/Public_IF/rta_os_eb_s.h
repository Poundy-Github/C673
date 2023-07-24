// Copyright (C) Continental AG
// All Rights Reserved
// COMPONENT: RTA - RealTimeAnalysis
/// \file
/// \brief The RTA public interface for ElektroBit Safety OS

#ifndef RTA_OS_EB_S_H
#define RTA_OS_EB_S_H


#ifdef __cplusplus
extern "C"
{
#endif


/// Generates an RTA switchEvent whenever a new thread goes into state "RUNNING" \n
/// Provides the information concerning current task and InterruptHistory to PMA
/// @pre
///   RTA must be initialized, OS running, state change of any thread occurred, called by EB MicroKernel
/// @post
///   task and interrupt data in PMA updated, RTA events generated
/// @param [in] objType: type of the current object (task, isr, ...), range defined by OS (mk_objecttype_t)
/// @param [in] s_objId: id of the current object, range:  0x0 ... 0xFFFF
/// @param [in] stateold: old state of the current object of type mk_threadstate_t
/// @param [in] statenew: new state of the current object of type mk_threadstate_t
/// @return
///   void
/// @InOutCorrelation
///     Generate an RTA switchEvent and provide data to PMA.
///
/// @callsequence
/// @image html RTA_v_DumpThreadStateChange.png
/// @startuml "RTA_v_DumpThreadStateChange"
/// title RTA_v_DumpThreadStateChange Sequence Diagram
/// [--> RTA_OS_EB_S : RTA_v_DumpThreadStateChange(const uint32 u_objType, const sint16 s_objId, const uint32 u_stateOld, const uint32 u_stateNew)
/// activate RTA_OS_EB_S
/// alt if RTA_THREAD_OBJECT_STATE_RUNNING != u_stateOld&&\nRTA_THREAD_OBJECT_STATE_RUNNING == u_stateNew&&\n(RTA_THREAD_OBJECT_TYPE_TASK  == u_objType||\nRTA_THREAD_OBJECT_TYPE_ISR   == u_objType)
/// RTA_OS_EB_S -> RTA_Basics : RTA_p_GetDataSet()
/// activate RTA_Basics
/// RTA_Basics --> RTA_OS_EB_S : // return DataSet //
/// deactivate RTA_Basics
/// alt if pointer != NULL
/// alt if we have a different thread than before
/// RTA_OS_EB_S -> RTA_Suspend : RTA_b_Suspended()
/// activate RTA_Suspend
/// RTA_Suspend --> RTA_OS_EB_S : // return status //
/// deactivate RTA_Suspend
/// alt if control is initialized for the core && status == b_FALSE
/// alt if RTA_THREAD_OBJECT_TYPE_TASK == u_objType
/// RTA_OS_EB_S -> RTA_OS_Hooks : RTA_v_PreTaskHookIntern(p_dataSet, (uint32)s_objId)
/// activate RTA_OS_Hooks
/// RTA_OS_Hooks --> RTA_OS_EB_S : // done //
/// deactivate RTA_OS_Hooks
/// end
/// end
/// end
/// end
/// RTA_OS_EB_S -> RTA_Task_Isr_Info_Priv : v_updateTaskIsrInfo(u_objType, s_objId, u_stateOld)
/// activate RTA_Task_Isr_Info_Priv
/// RTA_Task_Isr_Info_Priv --> RTA_OS_EB_S : // done //
/// deactivate RTA_Task_Isr_Info_Priv
/// end
/// [<-- RTA_OS_EB_S : // done //
/// @enduml
/// @testmethod
/// 	@ref TEST01_RTA_v_DumpThreadStateChange \n
/// 	@ref TEST02_RTA_v_DumpThreadStateChange \n
/// 	@ref TEST03_RTA_v_DumpThreadStateChange \n
/// 	@ref TEST04_RTA_v_DumpThreadStateChange \n
/// 	@ref TEST05_RTA_v_DumpThreadStateChange \n
/// 	@ref TEST06_RTA_v_DumpThreadStateChange \n
/// 	@ref TEST07_RTA_v_DumpThreadStateChange \n
/// 	@ref TEST08_RTA_v_DumpThreadStateChange \n
/// 	@ref TEST09_RTA_v_DumpThreadStateChange \n
/// @traceability
/// 	to be added
void RTA_v_DumpThreadStateChange(const uint32 u_objType, const sint16 s_objId, const uint32 u_stateOld, const uint32 u_stateNew);


#ifdef __cplusplus
}
#endif


#endif // #ifndef RTA_OS_EB_S_H

