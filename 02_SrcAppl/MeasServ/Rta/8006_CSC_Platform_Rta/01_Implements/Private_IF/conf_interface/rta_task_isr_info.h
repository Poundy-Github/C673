// Copyright (C) Continental AG
// All Rights Reserved
// COMPONENT: RTA - RealTimeAnalysis
/// \file
/// \brief This file declares all types required for task- and isr-Information.
///        Further it declares the setFunction which is used by PMA to provide the address of the corresponding task and isr-dataset.

#ifndef RTA_TASK_ISR_INFO_H
#define RTA_TASK_ISR_INFO_H

#ifdef __cplusplus
extern "C"
{
#endif


/// This define configures how many previous ISRs will be collected into ISR history.
#define RTA_CFG_SECTION_INT_STAT_SIZE     ((uint8)4)


/// The purpose of this define is to be used instead of magic number 3 if we need to reserve
/// 3 bytes in any structure. The main purpose of this is structure padding (aligning).
#define RTA_NUM_OF_RESERVED_BYTES_3    ((uint8)3)


/// Data type definition of the interrupt history data.
typedef struct
{
  /// \brief        Interrupt identifier
  /// \range        uint32
  /// \res          1
  /// \unit         -
  uint32 u_Id;

  /// \brief        Interrupt time stamp
  /// \range        uint32
  /// \res          1
  /// \unit         µs
  uint32 u_Timestamp;

  /// \brief        Interrupt program counter
  /// \range        uint32
  /// \res          1
  /// \unit         -
  uint32 u_InterruptedAddrLower32bits;

  /// \brief        Interrupt return address
  /// \range        uint32
  /// \res          1
  /// \unit         -
  uint32 u_InterruptedAddrHigher32bits;

} RTA_t_InterruptHistory;


/// Data type definition of the interrupt statistic data.
typedef struct
{
  /// \brief        History of interrupt identifier
  /// \range        PMA_t_InterruptHistory
  /// \res          1
  /// \unit         -
  RTA_t_InterruptHistory IntHist[RTA_CFG_SECTION_INT_STAT_SIZE];

  /// \brief        Contains index of last active interrupt
  /// \range        uint8
  /// \res          1
  /// \unit         -
  uint8 u_Index;

  /// \brief        Reserved for future use (Needed to align to 32 bit)
  /// \range        uint8[3]
  /// \res          1
  /// \unit         -
  uint8 a_Reserved[RTA_NUM_OF_RESERVED_BYTES_3];
} RTA_t_InterruptStatistic;


/// Data type definition of the global RTA data section.
typedef struct
{
  /// \brief        Interrupt statistic data
  /// \range        PMA_t_InterruptStatistic
  /// \res          1
  /// \unit         -
  RTA_t_InterruptStatistic  IntStat;

  /// \brief        Previous active task
  /// \range        uint8
  /// \res          1
  /// \unit         -
  uint8 u_OsPreviousTask;

  /// \brief        Current active task
  /// \range        uint8
  /// \res          1
  /// \unit         -
  uint8 u_OsCurrentTask;
}RTA_t_TaskIsrInfo;


/// \brief Function which returns the address of the RTA data.
///
/// \pre
///   None
/// \post
///   None
/// \param
///   p_TaskIsrInfo - pointer to the global RTA data section
/// \return
///   None
/// \InOutCorrelation
///   Set task interrupt relevant information for a specific core.
/// \callsequence
/// \image html RTA_v_SetTaskIsrInfo.png
/// \startuml "RTA_v_SetTaskIsrInfo"
/// title RTA_v_SetTaskIsrInfo Sequence Diagram
/// [--> RTA_Task_Isr_Info : RTA_v_SetTaskIsrInfo(RTA_t_TaskIsrInfo* const p_TaskIsrInfo)
/// activate RTA_Task_Isr_Info
/// RTA_Task_Isr_Info -> RTA_Req_If : RTA_ReqIf_u_GetCoreId()
/// activate RTA_Req_If
/// RTA_Req_If --> RTA_Task_Isr_Info: // return Core ID //
/// deactivate RTA_Req_If
/// note right of RTA_Task_Isr_Info: Update information for the core ID received.
/// [<-- RTA_Task_Isr_Info : // done //
/// deactivate RTA_Task_Isr_Info
/// \enduml
///
/// \traceability
///   <a href="doors://rbgs854a:40000/?version=2&prodID=0&view=00000006&urn=urn:telelogic::1-503e822e5ec3651e-O-574-0005ebe0">
///            doors://rbgs854a:40000/?version=2&prodID=0&view=00000006&urn=urn:telelogic::1-503e822e5ec3651e-O-574-0005ebe0</a>
void RTA_v_SetTaskIsrInfo(RTA_t_TaskIsrInfo* const p_TaskIsrInfo);


#ifdef __cplusplus
}
#endif

#endif // RTA_TASKISRINFO_H
