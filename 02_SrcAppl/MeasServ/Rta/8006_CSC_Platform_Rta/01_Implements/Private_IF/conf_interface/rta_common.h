// Copyright (C) Continental AG
// All Rights Reserved
// COMPONENT: RTA - RealTimeAnalysis
/// \file
/// \brief This header declares types and defines which are used in the generic implementation (-> adas_embed_mon)
///        and in the configuration files of the projects (-> adas_embed_mon_proj) as well.

#ifndef RTA_COMMON_H
#define RTA_COMMON_H

#ifdef __cplusplus
extern "C"
{
#endif


/// holds the current interface version of the RTA. \n
/// It is used to ensure compatibility with the MO.
#define RTA_IF_VERSION (3u)


/// This define shall be used to set/clear the bufferOverflow bit in u_CtrlFlags of the rtaBuffers.
/// In u_CtrlFlags bit 0 is used as bufferOverflow bit.
#define RTA_BUFFER_OVERFLOW_FLAG ((uint8)0x1)


/// number of buffers within one dataSet \n
/// As the dataSet is handled as toggleBuffer the number has to be always 2!
#define RTA_NO_OF_BUFFERS (2uL)


/// the structure of an RTA event \n
/// It has to be compatible to the MO.
typedef struct
{
  /// The relative time to the cycleStart stored in u_RefTs_us. \n
  /// Range:       0x0 ... 0xFFFFFFFF \n
  /// Resolution:  1 us \n
  /// Unit:        us
  uint32 u_RelTime_us;
  /// The type of event as described in enum RTA_t_Events. \n
  /// Note: Here an uint 8 is used instead of the enum to ensure the size of 8 bit.
  uint8 u_EventType;
  /// used for visualization on the MO, especially to map an event to a certain
  /// "eventGroup". All used values have to be defined in related xml-file (RTA_CORES.xml)
  /// which is used by MO for data interpretation. \n
  /// Range:       0x0 ... 0xFF
  uint8 u_GlobalId;
  /// used for visualization on the MO, especially to interpret an event with its
  /// symbolic name . All used values have to be defined in related xml-file which is used by MO for
  /// data interpretation. \n
  /// Range:       0x0 ... 0xFF
  uint8 u_LocalId;
  /// intended to hold additional information like error ID, cluster ID. \n
  /// Here the user is completely free how to use it. \n
  /// Range:       0x0 ... 0xFF
  uint8 u_OptData;
} RTA_t_EventData;


/// structure of the RtaBufferHeader  \n
/// It has to be compatible to the MO!
typedef struct
{
  /// holds the RTA version. It ensures compatibility with the MO. \n
  /// Range: Only the value of RTA_IF_VERSION is allowed.
  uint32 u_Version;
  /// has to be filled with the related coreID. It is used by the MO to map all the
  /// events in this buffer to the correct core in the visualization. \n
  /// Range: Only the value of the coreDefines (RTA_CORE_ID, RTA_CORE_ID_1, ....) is allowed.
  uint32 u_CoreID;
  /// systemTimeStamp taken at bufferChange has to be stored. BufferChange should be done
  /// near to cycleStart. \n
  /// Range:       0x0 ... 0xFFFF FFFF FFFF FFFF  \n
  /// Resolution:  1 us \n
  /// Unit:        us
  uint64 u_RefTs_us;
  /// Padding byte - not used, just to ensure correct alignment
  uint8  u_Padding_00;
  /// Padding byte - not used, just to ensure correct alignment
  uint8  u_Padding_01;
  /// Padding byte - not used, just to ensure correct alignment
  uint8  u_Padding_02;
  /// ControlFlags to provide information to the RTA MOs
  /// Bit 0: 0 - No BufferOverflow, 1 - BufferOverflow, not all events could be stored!!
  /// Bits 1 - 7: Currently not in use
  uint8  u_CtrlFlags;
  /// Padding byte - not used, just to ensure correct alignment
  uint8  u_Padding_10;
  /// Padding byte - not used, just to ensure correct alignment
  uint8  u_Padding_11;
  /// Padding byte - not used, just to ensure correct alignment
  uint8  u_Padding_12;
  /// Counter holding the running number of the buffer which is required by the MOs to check if there are buffers lost. \n
  /// Range: 0x0 ... 0xFF  \n
  uint8  u_BufferCnt;
  /// holds the number of currently filled events in the eventContainer. \n
  /// It has to be incremented at each entry of a new event. \n
  /// Range: 0x0 ... RTA_NO_OF_EVENTS
  uint32 u_MaxEventIndex;
  /// holds the size of the eventContainer. \n
  /// Range: It has to be equal to RTA_NO_OF_EVENTS.
  uint32 u_ContainerSize;
}RTA_t_BufferHeader;


typedef struct
{
  RTA_t_BufferHeader RtaBufferHeader;
  RTA_t_EventData    a_EventContainer[1];
} RTA_t_BufferGeneric;


/// contains the current state of the RTA component. It holds the information of all
/// errors and warnings currently detected. \n
typedef struct
{
  /// used as an bitField which collects all errors. For every error the related bit is set. \n
  /// Range: 0x0 ... 0xFFFFFFFF
  uint32 u_errors;
  /// used as an bitField which collects all warnings. For every warning the related bit is set. \n
  /// Range: 0x0 ... 0xFFFFFFFF
  uint32 u_warnings;
}RTA_t_ComponentStatus;


/// intended to collect all relevant information of the rtaComponent like version, status to be
/// put on MTS.
typedef struct
{
  /// current componentVersion.\n
  /// Range: 0x0 ... 0xFFFFFFFF
  uint32 u_rtaVersion;
  /// current status of the rtaComponent. For details see declaration of RTA_t_ComponentStatus. \n
  RTA_t_ComponentStatus status;
  /// counter which is incremented whenever a rtaEvent could not be set due to bufferOverflow. \n
  /// Range: 0x0 ... 0xFFFFFFFF
  uint32 u_eventBufferFullCnt;
  /// counter which is incremented at every cycle in which the rtaBuffer usage was beyond the
  /// warningLevel defined by RTA_LIMIT_MAX_BUFFER_USAGE_PERC. \n
  /// Range: 0x0 ... 0xFFFFFFFF
  uint32 u_eventBufferLimitCnt;
  /// counter which is incremented whenever an error occurred in freezing the rtaEventBuffer. \n
  /// Range: 0x0 ... 0xFFFFFFFF
  uint32 u_bufferFreezeErrorCnt;
  /// This counter is incremented whenever one rtaBuffer has not been frozen since last buffer switch at the time of the
  /// next buffer switch. It holds the total number of occurrences within the powerCycle. \n
  /// Range: 0x0 ... 0xFFFFFFFF
  uint32 u_BufferNotFrozenCnt;
  /// counter which is incremented whenever the previously started asynchronous bufferFreeze
  /// has not been finished in time (when the rtaToggleBuffer shall be switched). It holds the total number of occurrences
  /// within the powerCycle. \n
  /// Range: 0x0 ... 0xFFFFFFFF
  uint32 u_asyncFreezeNotFinishedCnt;
  /// shows the current rtaBuffer usage in percent. \n
  /// Range: 0 ... 100
  uint8 u_eventBufferCurrentUsagePerc;
  /// shows the maximum rtaBuffer usage in percent within this powerCycle.\n
  /// Range: 0... 100
  uint8 u_eventBufferMaxUsagePerc;
  /// Counter incremented when two tasks tried to use the same RTA buffer index
  uint32 u_retryAllocIndex;
  /// Counter incremented when an attempt to store data in the RTA buffer failed.
  /// This is not an error, the procedure will be repeated.
  uint32 u_retryStore;
  /// Counter incremented when an RTA event was stored to a RTA buffer that is
  /// not active anymore (i.e. double-buffers were switched meanwhile).
  /// This is not an error, the procedure will be repeated.
  uint32 u_retryBuffSwapped;
  /// Counter incremented when RTA event index update was skipped since a higher
  /// priority thread did increment it already beyond our index.
  uint32 u_earlyStopIndexUpdate;
  /// Counter incremented when RTA event could not be stored into the event buffer
  /// after number of tries expired.
  uint32 u_retryGiveUpCount;
  /// Counter incremented whenever an index correction takes place in RTA_v_SwitchBuffer function.
  /// Normally maxEventIndex is incremented in v_insertEvent function but it may happen that the
  /// exclusive store fails there. To ensure that all generated events are sent to MTS the index
  /// correction is done here - if needed.
  uint32 u_indexCorrBuffSwitch;
}RTA_t_Info;


/// contains all needed variables for one core to drive the rta
typedef struct
{
  /// contains all relevant information and the current state of the rta for one core
  /// Details see in description of  RTA_t_Info.\n
  RTA_t_Info componentInfo;
  /// stores the localTime at time of bufferChange. It is used to calculate the
  /// deltaTime of the single events. \n
  /// Range: 0x0 ... 0xFFFFFFFF
  uint32     u_localTime;
  /// holds the index of that buffer of a_rtaBuffer to which currently rtaEvents shall be written to. \n
  /// Range: 0x0 ... (RTA_NO_OF_BUFFERS - 1)
  volatile uint32     u_rtaBufferIndex;
  /// contains two information: the threadType in the high word (bit 16 ... 31) and the threadID in the low word (bit 0 .. 15).  \n
  /// Range: 0x0 ... 0xFFFFFFFF
  uint32 u_IdCurrentThread;
  /// indicates whether there is a rtaBuffer to be frozen or not. In the same way it provides the information
  /// whether the previous rtaBuffer has been frozen since the last bufferSwitch or not. This flag is set right after
  /// set right after the bufferSwitch and is reset right after the bufferFreeze.\n
  /// Range: 0x0 ... 0xFFFFFFFF
  uint32     u_rtaBufferNotFrozenCnt;
  /// used to count the cycles in a row in which the bufferFreeze is pending. It is used for recovery.
  /// If this counter reaches that value defined in RTA_FREEZE_PENDING_CYCLES_2_RECOVER the flag b_bufferFreezePending
  /// will be reset and the current buffer will be frozen. \n
  /// Range:       0x0 ... 0xFF
  uint32     u_freezePendingCnt;
  /// holds the value which the related callbackCounter shall have.
  /// Note: Only relevant when the rtaBuffer is frozen in asynchronousMode. In syncMode this
  /// member must not be changed.  \n
  /// Range: 0x0 ... 0xFFFFFFFF
  uint32     u_expectedCallBackCntValue;
  /// flag indicating whether RTA buffer has been frozen and is ready to be switched
  /// Range: \n
  /// - b_FALSE: Previous buffer already frozen, buffer can be toggled
  /// - b_TRUE:  Previous buffer not frozen , buffer must not be switched
  boolean    b_freezeRtaBuffer;
  /// Boolean value indicating whether RTA has been initialized or not.\n
  /// Range: \n
  /// - b_FALSE - not initialized
  /// - b_TRUE  - initialized
  boolean     b_initialized;
  /// Counter incremented at every bufferSwitch.\n
  /// Range:        0x0 ... 0xFF
  volatile uint8 u_bufferSwitchCnt;
}RTA_t_Ctrl;


/// This enumeration defines the generic buildUnits which shall be used in context of emergencyBufferFreezing.
typedef enum
{
  RTA_BUILD_UNIT_0   = 0x1,
  RTA_BUILD_UNIT_1   = 0x2,
  RTA_BUILD_UNIT_2   = 0x4,
  RTA_BUILD_UNIT_3   = 0x8,
  RTA_BUILD_UNIT_4   = 0x10,
  RTA_BUILD_UNIT_5   = 0x20,
  RTA_BUILD_UNIT_6   = 0x40,
  RTA_BUILD_UNIT_7   = 0x80,
  RTA_BUILD_UNIT_ALL = 0xFFFFFFFF
}RTA_t_BuildUnits;


#ifdef __cplusplus
}
#endif

#endif // #ifndef RTA_COMMON_H
