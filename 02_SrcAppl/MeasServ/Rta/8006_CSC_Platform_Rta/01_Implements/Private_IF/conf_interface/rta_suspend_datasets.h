// Copyright (C) Continental AG
// All Rights Reserved
// COMPONENT: RTA - RealTimeAnalysis
/// \file
/// \brief This file declares the configuration interface for the suspend feature which is used especially for EDP.

#ifndef RTA_SUSPEND_DATA_SETS_H
#define RTA_SUSPEND_DATA_SETS_H

#ifdef __cplusplus
extern "C"
{
#endif


/// Commands send to slave cores
typedef enum
{
  RTA_SUSPEND_CMD_IDLE,
  RTA_SUSPEND_CMD_SYNC,
  RTA_SUSPEND_CMD_SWITCH_MEAS
} RTA_SuspendSyncCommand;


/// State of slave cores
typedef enum
{
  RTA_SUSPEND_SLAVE_STATE_IDLE,
  RTA_SUSPEND_SLAVE_STATE_IN_SYNC,
  RTA_SUSPEND_SLAVE_STATE_JOB_DONE
} RTA_SuspendSlaveState;


/// contains all needed variables for suspending the RTA.
typedef struct
{
  /// Stores the local time when suspending the RTA was requested
  /// Range: 0x0 ... 0xFFFFFFFF
  uint32 u_timeSuspendStart;

  /// Stores the suspended time span in a cycle between 2 buffer switches
  /// Range: 0x0 ... 0xFFFFFFFF
  uint32 u_timeSuspendedCycle;

  /// Stores the suspended time span
  /// Range: 0x0 ... 0xFFFFFFFFFFFFFFFF
  uint64 u_timeSuspendedAll;
}RTA_t_SuspendDataSet;


typedef struct
{
  volatile RTA_SuspendSyncCommand suspendSyncCmd;
  volatile uint8                  u_coreAllowedToFreeze;
}RTA_t_CtrlSuspendMultiCore;


typedef struct
{
  const uint32*                   p_suspendSyncSlaveTaskMap;
  volatile RTA_SuspendSlaveState* p_suspendSlaveStates;
  RTA_t_CtrlSuspendMultiCore*     p_ctrl;
}RTA_t_SuspendMulticoreDataSet;


typedef struct
{
  RTA_t_SuspendDataSet*const*const           p_suspendDataSets;
  const RTA_t_SuspendMulticoreDataSet*const  p_suspendMultiCoreDataSet;
  uint32                                     u_numberOfCores;
}RTA_t_SuspendDataSetHandler;


extern const RTA_t_SuspendDataSetHandler rta_suspendDataSetHandler;


#ifdef __cplusplus
}
#endif

#endif // #ifndef RTA_SUSPEND_DATA_SETS_H
