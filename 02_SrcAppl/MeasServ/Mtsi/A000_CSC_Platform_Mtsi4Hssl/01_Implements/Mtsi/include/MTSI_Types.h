// Copyright (C) Continental AG
// All Rights Reserved
// COMPONENT: MTSI
// VERSION:   $Revision: 1.8 $

#ifndef MTSI_Types_H
#define MTSI_Types_H

#include <MTSI_Cfg.h>
#include <MTSI_CommonTypes.h>


#ifdef __cplusplus
extern "C"
{
#endif

/// @brief    Absolute timestamp
typedef uint32 MTSI_t_AbsoluteTimestamp; 

/// @brief    Relative timestamp
typedef sint32 MTSI_t_RelativeTimestamp; 

#if( (defined CFG_MTSI_HEADER_USE_PACKET_COUNTER) && (TRUE == CFG_MTSI_HEADER_USE_PACKET_COUNTER) )
typedef uint16 MTSI_t_sw_packet_counter;
#endif

///  @brief Timestamp at MTSI Header
typedef union
{
  MTSI_t_AbsoluteTimestamp Absolute;
  MTSI_t_RelativeTimestamp Relative;
} MTSI_t_Timestamp;

/// @brief MTS packet header.\n
/// Header that is required for each single MTS packet.
typedef struct
{ 
  uint32 VirtualAddress;              ///< Virtual address of MTS packet
  
  uint32 CtrlFieldAndPayloadLength;   ///< Control field and payload length.\n
                                      ///< The highest byte contains the control field,
                                      ///< the lower three bytes contains the payload length.
                                      
  uint16 TaskIdentifier;              ///< Task in which the packet was created
   
  uint16 TaskCounter;                 ///< Task counter
  
#if ( (defined CFG_MTSI_HEADER_USE_FUNCTION_ID) && (TRUE == CFG_MTSI_HEADER_USE_FUNCTION_ID) )
  uint16 FunctionId;                  ///< Function identifier
#endif /* ( (defined CFG_MTSI_HEADER_USE_FUNCTION_ID) && (TRUE == CFG_MTSI_HEADER_USE_FUNCTION_ID) ) */

#if ( (defined CFG_MTSI_HEADER_USE_PACKET_COUNTER) && (TRUE == CFG_MTSI_HEADER_USE_PACKET_COUNTER) )
  uint16 PacketCounter;                                         ///< Packet counter.
#endif /* ( (defined CFG_MTSI_HEADER_USE_PACKET_COUNTER) && (TRUE == CFG_MTSI_HEADER_USE_PACKET_COUNTER) ) */

  MTSI_t_Timestamp Timestamp;                                   ///< Timestamp.\n
                                                                /// Could be absolute with high or low resolution
                                                                /// or relative with high or low resolution.
                                                                
  uint16 PaddingLength;                                         ///< Number of padding bytes.\n
                                                                /// Padding bytes can be used to adapt the header size
                                                                /// to the platform specific byte alignment.
                                                                
#if ( (defined CFG_MTSI_HEADER_NUMBER_OF_PADDING_BYTES) && (0u != CFG_MTSI_HEADER_NUMBER_OF_PADDING_BYTES) )
  uint8 PaddingBytes[CFG_MTSI_HEADER_NUMBER_OF_PADDING_BYTES];  ///< Padding bytes.\n               
                                                                /// Padding bytes can be used to adapt the header size
                                                                /// to the platform specific byte alignment.
#endif /* ( (defined CFG_MTSI_HEADER_NUMBER_OF_PADDING_BYTES) && (0u != CFG_MTSI_HEADER_NUMBER_OF_PADDING_BYTES) ) */
} MTSI_t_Header;

/// @brief    Information about an async job
typedef struct AsyncJob_struct
{
/// @brief    Header of this job
///
/// The header is always stored in big-endian.
  MTSI_t_Header Header;

/// @brief    Data of this job
  const void *p_Data;

/// @brief    Callback function for this job
  MTSI_t_Callback p_Callback;
} t_AsyncJob;


/// @brief    Information about async queue
typedef struct AsyncQueue_struct
{
  uint16 Size; ///< Queue size (range: 0 - UINT16_MAX)
  uint16 Head; ///< Head of queue (range: 0 - UINT16_MAX)
  uint16 Tail; ///< Tail of queue (range: 0 - UINT16_MAX)
  uint16 Reference; ///< Reference used for grouped transmission (range: 0 - UINT16_MAX)
  t_AsyncJob *p_Queue; ///< Reference to queue
} t_AsyncQueue;

/// @brief    Information about async queues of one core
typedef struct AsyncQueueControl_struct
{
/// @brief    Reference to async queues
  t_AsyncQueue * const p_AsyncQueues[CFG_MTSI_NUMBER_OF_LANES];
} t_AsyncQueueControl;


/// @brief    Task information
typedef struct TaskInfo_struct
{
/// @brief Task ID from OS
  uint16 TaskIdentifier;

/// @brief Task counter
  uint16 TaskCounter;
} t_TaskInfo;


/// @brief    Current status of the toggle buffer
typedef enum
{
  BUFFER_STATE_FREE                  = 0, ///< Data can be written into this buffer
  BUFFER_STATE_FULL                  = 1, ///< Buffer is full and ready to be sent
  BUFFER_STATE_OVERDUE               = 2, ///< Transmission of this buffer is overdue
  BUFFER_STATE_TRANSMISSION_REJECTED = 3, ///< Transmission was rejected by PAL, but timestamps has already been adapted (only in case of relative timestamps)
  BUFFER_STATE_TRANSMISSION_PENDING  = 4  ///< Transmission of this buffer is currently pending
} t_BufferState;


/// @brief    Time synchronization packet. Must be sent once per MTA frame if Absolut TimeStamping is used.
typedef struct TimeSyncPacket_struct
{
  uint32 TimeBaseRes;
  uint32 FrameStartRef;
} t_TimeSyncPacket;


/// @brief    Information about a single toggle buffer
typedef struct ToggleBuffer_struct
{
/// @brief    Buffer state
/// @range    0 - 3 (FREE, FULL, OVERDUE, TRANSMISSION_PENDING)
  t_BufferState State;

/// @brief    Buffer size
/// @range    0 - UINT32_MAX
  uint32 Size;

/// @brief    Current buffer level
/// @range    0 - UINT32_MAX
  uint32 Level;

/// @brief    Reference to buffer
  uint8 *p_Buffer;
} t_ToggleBuffer;

/// @brief    Information about sync buffer of one core
typedef struct SyncBufferControl_struct
{
/// @brief    Size of sync buffer
/// @range    0 - UINT32_MAX
  uint32 Size;

/// @brief    Lane on which this buffer is sent
/// @range    0 - (CFG_MTSI_NUMBER_OF_LANES - 1)
  uint8 LaneId;

/// @brief    Index of toggle buffer to be read as next
/// @range    0 - (CFG_MTSI_NUMBER_OF_TOGGLE_BUFFERS - 1)
  uint8 ReadIndex;

/// @brief    Index of toggle buffer to be written into
/// @range    0 - (CFG_MTSI_NUMBER_OF_TOGGLE_BUFFERS - 1)
  uint8 WriteIndex;

/// @brief    Indicate if buffer has been sent within current MTA cycle
/// @range    b_TRUE, b_FALSE
  boolean SentWithinMTACycle;

/// @brief    Reference to toggle buffers
  t_ToggleBuffer * const p_ToggleBuffers[CFG_MTSI_NUMBER_OF_TOGGLE_BUFFERS];
} t_SyncBufferControl;


/// @brief    Main control of MTSI
///
/// Contains all information that is related to the job handling.
/// Each core must have its own control variable.\n
typedef struct MainControl_struct
{
/// Reference to control of sync buffer\n
  t_SyncBufferControl * const p_SyncBufferControl;

/// Reference to control of async queue\n
  t_AsyncQueueControl * const p_AsyncQueueControl;
} t_MainControl;


/// @brief    Dynamic statistic data
typedef struct
{
	/// @brief	Initialization flag
	boolean DataInitialized;
	/// @brief	Current value
	uint32 CurrentValue;
	/// @brief  Error counter indicating data loss
	uint32 ErrorCnt_DataLost;
	/// @brief	All time high  value
	uint32 AllTimeHigh;
	/// @brief	All time low value
	uint32 AllTimeLow;
} MTSI_t_DynamicStatisticData;
///

/// @brief    Dynamic statistics of MTSI module
typedef struct
{
	/// @brief	Statistic of synchronous jobs
	MTSI_t_DynamicStatisticData SyncBufferUsage;
	/// @brief	Statistic of synchronous data
	MTSI_t_DynamicStatisticData SyncData;
	/// @brief	Statistic of asynchronous jobs
	MTSI_t_DynamicStatisticData AsyncJobs;
} MTSI_t_DynamicStatistics;

/// @brief    Control of dynamic statistics
typedef struct
{
	///Reference to dynamic statistics
	MTSI_t_DynamicStatistics* p_DynamicStats[CFG_MTSI_NUMBER_OF_LANES];
} MTSI_t_DynamicStatisticControl;


/// @brief    MTSI checkpoint for analysis
typedef struct
{
	/// @brief	ID of this checkpoint
	uint8 CheckpointIdentifier;

	/// @brief	Reference to RTA event
	uint8 ReferenceIdentifier;

	/// @brief	Task ID of related meas freeze
	uint16 TaskIdentifier;

	/// @brief	Virtual address of related meas freeze
	uint32 VirtualAddress;
} MTSI_t_Checkpoint;


/// @brief    Control of MTSI checkpoints
typedef struct
{
	/// @brief	Size of checkpoint list
	uint8 Size;

	/// @brief	Current write index
	uint8 WriteIndex;

	/// @brief	Reference to checkpoint list
	MTSI_t_Checkpoint *p_Checkpoints;
} MTSI_t_CheckpointControl;


/// @brief    Control of statistic data
typedef struct
{
	/// @brief	Reference to control of dynamic statistics
	MTSI_t_DynamicStatisticControl * const p_DynamicStatisticControl;

	/// @brief	Reference to control of checkpoints
	MTSI_t_CheckpointControl * const p_CheckpointControl;
} MTSI_t_StatisticControl;

/// @brief    Common configuration parameters
typedef struct
{
	/// @brief    Number of used cores
	uint8 NumberOfCores;
	/// @brief    Number of used lanes
	uint8 NumberOfLanes;
	/// @brief    Number of used toggle buffers
	uint8 NumberOfToggleBuffers;
	/// @brief    Maximum number of tasks that can be handled
	uint8 MaximumNumberOfTasks;
	/// @brief    Instance number of this ECU
	uint8 InstanceNumber;
	/// @brief    Output mode of MTSI
	uint8 OutputMode;
} MTSI_t_CommonConfig;


/// @brief    Configuration of statistic module
typedef struct
{
	/// @brief    Activation status of MTS checkpoints
	boolean CheckpointsEnabled;
	/// @brief    Maximum number of checkpoints for each core
	uint8 NumberOfCheckpoints[CFG_MTSI_NUMBER_OF_CORES];
	/// @brief    Cycle time in ms on that static statistics shall be sent
	uint16 CycleTimeStaticStatistics;
	/// @brief    Cycle time in ms on that MTSI checkpoints shall be sent
	uint16 CycleTimeMTSICheckpoints;
} MTSI_t_StatisticConfig;


/// @brief    Configuration of MTS header
typedef struct
{
	/// @brief    Usage of function id
	uint8 UseFunctionId;
	/// @brief    Usage of packet counter
	uint8 UsePacketCounter;
	/// @brief    Usage of high resolution timestamp
	uint8 UseHighResTimestamp;
	/// @brief    Usage of absolute timestamp
	uint8 UseAbsoluteTimestamp;
	/// @brief    Usage of checksum
	uint8 UseChecksum;
	/// @brief    Number of used padding bytes
	uint16 NumberOfPaddingBytes;
} MTSI_t_HeaderConfig;


/// @brief    Core configuration
typedef struct
{
	/// @brief    Used lane for sync buffer
	uint8 SyncBufferLane;
	/// @brief    Size of sync buffer
	uint32 SyncBufferSize;
	/// @brief    Size of async queues
	uint16 AsyncQueueSize[CFG_MTSI_NUMBER_OF_LANES];
} MTSI_t_CoreConfig;


/// @brief    Configuration summary of MTSI module
typedef struct
{
	/// @brief    Common configuration parameters
	MTSI_t_CommonConfig CommonConfig;
	/// @brief    Configuration of statistic module
	MTSI_t_StatisticConfig StatisticConfig;
	/// @brief    Configuration of MTS header
	MTSI_t_HeaderConfig HeaderConfig;
	/// @brief    Configuration for each core
	MTSI_t_CoreConfig CoreConfig[CFG_MTSI_NUMBER_OF_CORES];
} MTSI_t_ModuleConfig;

/// @brief    Major, minor and patch version of this module
typedef struct
{
	/// @brief    Major version of MTS module
	uint16 MajorVersion;
	/// @brief    Minor version of MTS module
	uint8 MinorVersion;
	/// @brief    Patch version of MTS module
	uint8 PatchVersion;
} MTSI_t_ModuleVersion;


/// @brief    Static statistics of MTSI module
typedef struct
{
	/// @brief    Major, minor and patch version of MTSI module
	MTSI_t_ModuleVersion ModuleVersion;
	/// @brief    Configuration of MTSI module
	MTSI_t_ModuleConfig ModuleConfig;
} MTSI_t_StaticStatistics;


/// @brief    Symbolic constant for disabled MTSI
#define MTSI_OUTPUTMODE_OFF (uint8)0x00

/// @brief    	Symbolic constant for enabled MTSI, mode 1
///Behavior of this mode is implemented in the platform abstraction.
#define MTSI_OUTPUTMODE_1 (uint8)0x01

/// @brief    	Symbolic constant for enabled MTSI, mode 2
/// Behavior of this mode is implemented in the platform abstraction.
#define MTSI_OUTPUTMODE_2 (uint8)0x02

/// @brief    	Symbolic constant for enabled MTSI, mode 3
/// Behavior of this mode is implemented in the platform abstraction.
#define MTSI_OUTPUTMODE_3 (uint8)0x03

/// @brief   	Symbolic constant for enabled MTSI, mode 4
/// Behavior of this mode is implemented in the platform abstraction.
#define MTSI_OUTPUTMODE_4 (uint8)0x04

/// @brief    	Symbolic constant for lane 0
#define MTSI_ID_LANE_0 (uint8)0x00

/// @brief    	Symbolic constant for lane 1
#define MTSI_ID_LANE_1 (uint8)0x01

/// @brief 		Symbolic constant for core 0
#define MTSI_ID_CORE_0 (uint8)0x00

/// @brief		Symbolic constant for core 1
#define MTSI_ID_CORE_1 (uint8)0x01

/// @brief		Symbolic constant for core 2
#define MTSI_ID_CORE_2 (uint8)0x02

/// @brief		Symbolic constant for core 3
#define MTSI_ID_CORE_3 (uint8)0x03

/// @brief		Symbolic constant for core 4
#define MTSI_ID_CORE_4 (uint8)0x04

/// @brief    	Bit mask to get/set payload length
#define MTSI_PAYLOAD_LENGTH_BIT_MASK 0x00FFFFFFu

/// @brief    	Bits to be shifted to get/set the control field
#define MTSI_CTRL_FIELD_BIT_SHIFT 24uL

/// @brief    	Bit mask for function id
#define MTSI_FUNCTION_ID_MASK (uint16)0x0FFF

/// @brief    	Bit mask for function channel id
#define MTSI_FUNCTION_CHANNEL_ID_MASK (uint16)0xF000

/// @brief      Virtual address of time sync packet
#define MTSI_TIME_SYNC_PACKET_VIRT_ADDR 0xFFFFFFF0u

/// @brief      Virtual address of version info packet
#define MTSI_VERSION_INFO_PACKET_VIRT_ADDR 0xFFFFFFF1u

/***    User explicit entries    ***/

/// @brief    Virtual address of MTSI checkpoints
#define MTSI_CHECKPOINTS_VIRT_ADDR ( MTSI_STATIC_STATS_VIRT_ADDR + CFG_MTSI_MEAS_FREEZE_BYTE_ALIGNMENT + (uint32)sizeof(MTSI_t_StaticStatistics) )

/// @brief    Virtual address of dynamic statistics
#define MTSI_DYNAMIC_STATS_VIRT_ADDR ( MTSI_CHECKPOINTS_VIRT_ADDR + CFG_MTSI_MEAS_FREEZE_BYTE_ALIGNMENT + ( MTSI_TOTAL_NB_OF_CHECKPOINTS * (uint32)sizeof(MTSI_t_Checkpoint) ) )


/// @brief    Get virtual address of dynamic statistic data
/// PRQA S 3453 1 */ /* Macro can not be replaced by a function, because it is also used for the pdo tags.
#define MTSI_GET_DYNAMIC_STATS_VIRT_ADDR(CoreId, LaneId) (MTSI_DYNAMIC_STATS_VIRT_ADDR + ((((CoreId) * (uint32)CFG_MTSI_NUMBER_OF_LANES) + (LaneId)) * (uint32)sizeof(MTSI_t_DynamicStatistics)))


#ifdef __cplusplus
}
#endif


#endif


