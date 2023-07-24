// Copyright (C) Continental AG
// All Rights Reserved
// COMPONENT: RTA - RealTimeAnalysis
/// \file
/// \brief The RTA public interface for vector OS

#ifndef RTA_OS_VECTOR_H
#define RTA_OS_VECTOR_H


#ifdef __cplusplus
extern "C"
{
#endif

/// Generates an RTA switchEvent whenever a new thread goes into state "RUNNING" \n
/// Provides the information concerning current task and InterruptHistory to PMA
///\pre
///   RTA must be initialized, OS running, state change of any thread occurred, called by vector OS -> macro OS_VTH_SCHEDULE
/// \post
///   task and interrupt data in PMA updated, RTA events generated
/// \param [in] u_toThreadId: The ID of the next thread (task, isr, ...) which will be run next, argument provided by macro OS_VTH_SCHEDULE
/// \param [in] u_toThreadReason: id of the current object, argument provided by macro OS_VTH_SCHEDULE
/// \param [in] u_toThreadReason: Number of tasks in the buildUnit, range: OS_TASKID_COUNT defined in Os_Types_Lcfg.h
/// \param [in] u_numberOfInterrupts: Number of interrupts in the buildUnit, range: OS_ISRID_COUNT defined in Os_Types_Lcfg.h
/// \return
///   void
/// \InOutCorrelation
///     Generate an RTA switchEvent and provide data to PMA.
///
/// \callsequence
///   TODO \n
/// @testmethod
///  TODO \n
/// @traceability
///   TODO
void RTA_v_OS_VTH_SCHEDULE(const uint32 u_toThreadId, const uint32 u_toThreadReason, const uint32 u_numberOfTasks, const uint32 u_numberOfInterrupts);

#ifdef __cplusplus
}
#endif

#endif // #ifndef RTA_OS_VECTOR_H
