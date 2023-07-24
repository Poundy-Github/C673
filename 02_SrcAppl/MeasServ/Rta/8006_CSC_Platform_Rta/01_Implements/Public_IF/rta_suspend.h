// Copyright (C) Continental AG
// All Rights Reserved
// COMPONENT: RTA - RealTimeAnalysis
/// \file
/// \brief The public interface of the RTA component used for suspending the RTA

#ifndef RTA_SUSPEND_H
#define RTA_SUSPEND_H


#ifdef __cplusplus
extern "C"
{
#endif


/// state transition of RTA measurement
typedef enum
{
  RTA_SUSPEND_TRANSITION_SUSPEND_MEAS_FREEZING,
  RTA_SUSPEND_TRANSITION_RESUME_MEAS_FREEZING,
  RTA_SUSPEND_TRANSITION_SWITCH_AND_FREEZE_BUFFERS
} RTA_SuspendStateTransition;


/// suspends the RTA to prevent processing of any events until RTA_v_Resume was called
/// @pre
///   RTA has to be initialized.
/// @post
///   After successful run of this function no event will be processed by RTA
/// @param
///   void
/// @return
///   void
void RTA_v_Suspend(void);


/// resumes the RTA after it was suspended
/// @pre
///   RTA has to be initialized
/// @post
///   After successful run of this function RTA will process incomming events
/// @param
///   void
/// @return
///   void
void RTA_v_Resume(void);


/// Special function which is needed when we use the special EDP mode and more than one core. \n
/// The RTA processing of all cores are suspended with the same time. So, a drifting of the RTA \n
/// markers is avoided. Used by RTA_SuspendMulticore.c but has to stay in RTA_Suspend cause
/// it is necessary to use the RTA_STATIC variables.
/// @param
///   \-
/// @return
///   \-
/// @testmethod
///   \-
/// @traceability
///   \-
void RTA_v_SuspendAllCores(void);

/// Special function which is needed when we use the special EDP mode and more than one core. \n
/// The RTA processing of all cores are resumed with the same time. So, a drifting of the RTA \n
/// markers is avoided. Used by RTA_SuspendMulticore.c but has to stay in RTA_Suspend cause
/// it is necessary to use the RTA_STATIC variables.
/// @param
///   \-
/// @return
///   \-
/// @testmethod
///   \-
/// @traceability
///   \-
void RTA_v_ResumeAllCores(void);

/// Entry function for external callers to change the RTA state.\n
/// \n
/// The core on which this function is called is called Master Core.\n
/// The other cores defined in the RTA_Cfg.h (RTA_SuspendSlaveTaskMap[]) are called Slave Cores.\n
/// \n
/// Suspend/Resume:\n
/// It is important for the so called slave cores to Suspend/Resume always in the same dedicated Task. Otherwise we will\n
/// see not plausible Tasks in the MTS. This is the reason for this function.\n
/// \n
/// This function will bring the Slave Cores to this dedicated Task (sync) where the Slaves are waiting.\n
/// Then the Master calls RTA_v_SuspendAllCores()/ResumeAllCores().\n
/// In the end, Master Core tells the Slaves to leave the sync state again.\n
/// \n
/// Switch Buffer/Freeze Buffer:\n
/// It is also important to do this at the same time. Otherwise we will see a large shift of the MTS markers.\n
/// The function uses the same mechanism as for suspend/resume: sync, switch/freeze, leave sync.\n
/// \n
/// This will even work if CoreNumber is just 1.\n
/// \n
/// @param
///   [in] e_state: used to change the state of RTA \n
///          RTA_SUSPEND_SUSPEND_MEAS_FREEZING     - will synchronized suspend the RTA among all cores
///          RTA_SUSPEND_RESUME_MEAS_FREEZING      - will synchronized resum the RTA among all cores
///          RTA_SUSPEND_SWITCH_AND_FREEZE_BUFFERS - will synchronized switch the RTA buffers and freeze them among all cores\n
///                                                  (every Core (Master+Slaves) will do the switch/freeze on its own.)
///
void RTA_v_SuspendSyncChangeStateMultiCore(const RTA_SuspendStateTransition e_state);

/// Slave Cores has to call this function in their Tasks where the RTA synchronization should take place.\n
/// The functions listens for commands of the Master Core (switch/freeze buffers; leave sync state).\n
/// \n
/// Beware: This function disables the Interrupts and should therefore be called out of a high priority Task.\n
void RTA_v_SuspendSyncOnSlave(void);


#ifdef __cplusplus
}
#endif


#endif // #ifndef RTA_SUSPEND_H

