// Copyright (C) Continental AG
// All Rights Reserved
// COMPONENT: MTSI
// VERSION:   $Revision: 1.18 $
/// @file
 
/* PRQA S 839 16 */
/* Multiple includes are caused implicitly by other components and can therefore not be avoided here. */

#include <MTSI_Driver.h>
#include <MTSI_Cfg_Int.h>
#include <MTSI_Statistics.h>
#include <MTSI_Callouts.h>
#include <MTSI_Pal.h>

#ifndef __IPL_CANTPP__
//#include <sys_mem.h>
#endif

#include <MTSI_Custom.h>

/* PRQA S 2201,6001,6011,6013,6021,6023,6030,6040 EOF *//* Suppress naming rule warnings - level 1 */

/* PRQA S 838, 861, 5087 EOF */
/* Multiple include of MTSI_MemMap_Cfg.h within source code is required for core specific memory mapping of static variables. */
/* PRQA S 2211 EOF *//* '%s' is not aligned with the previously declared identifier. */
/* The current indentation method works, no need to change it. */
/* PRQA S 2052 EOF *//* This line comment appears to comment out source code. */
/* Required to properly visualize the #if/#else/#endif matching conditions */
/* PRQA S 2981 EOF *//* This initialization is redundant. The value of this object is never used before being modified. */
/* Not a problem, keep it this way. */
#ifdef __cplusplus
extern "C"
{
#endif

/// @brief    Status of the MTSI driver module
typedef enum
{
  MODULE_UNINITIALIZED     = 0, ///< Module is not initialized
  MODULE_PREINITIALIZED    = 1, ///< Preinitialization of module is done
  MODULE_INITIALIZED       = 2, ///< Complete initialization of module is done
  MODULE_DE_INIT_REQUESTED = 3, ///< Deinitialization of module has been requested
  MODULE_DEINITIALIZED     = 4  ///< Module has been deinitialized
} t_ModuleState;


/// @brief    Status of an MTA frame
typedef enum
{
  MTA_FRAME_INACTIVE = 0, ///< MTA frame is currently not active 
  MTA_FRAME_ACTIVE   = 1  ///< MTA frame is currently active
} t_MTAFrameState;

/* For Grouped job processing, do not use a enum to identify lane states; instead split the states bitwise.
 * This is because for every Lane we have a unique LaneState variable, but it's possible to have
 * several states in parallel due to the grouped handling.
 * Eg: we may send both the SyncBuffer and AsyncQueue in one transfer... both LANE_STATE_SYNC_BUFFER_TRANSMISSION
 * and LANE_STATE_ASYNC_QUEUE_TRANSMISSION states need to be active at the same time to ensure both the
 * FinalizeSync... and FinalizeAsync... operations are called.  */
#define LANE_STATE_INIT                                               (uint8)0x00u  ///< Lane has to be initialized
#define LANE_STATE_SYNC_BUFFER_TRANSMISSION                           (uint8)0x01u  ///< Bit indicating that a Sync buffer transmission is ongoing
#define LANE_STATE_ASYNC_QUEUE_TRANSMISSION                           (uint8)0x02u  ///< Bit indicating that a Async Queue transmission is ongoing
#define LANE_STATE_TRANSMISSION_WITH_MTA_FRAME_REQUEST                (uint8)0x04u  ///< Bit indicating that a MTS frame Start must be initiated after the current ongoing transmission
#define LANE_STATE_IDLE                                               (uint8)0x08u  ///< Lane is currently idle (no ongoing job)

/* For Grouped job processing, we may have to store in the Multiplexer variable more than just one CoreID,
 * since it's possible to have in one transfer several jobs assigned to different cores.
 * This is done by assigning 2 bits (for now) to each core, one for each supported job type: Sync/Async. */
#define MTSI_SYNCJOB_MARK_INDICATOR  (uint8)0x01 ///< Indicates (when multiplied with the core index) the position in the Multiplexer where the SyncJob triggered indicator is located.
#define MTSI_ASYNCJOB_MARK_INDICATOR (uint8)0x02 ///< Indicates (when multiplied with the core index) the position in the Multiplexer where the AsyncJob triggered indicator is located.
#define MTSI_JOB_NUM_INDICATORS      (uint8)0x02 ///< Maximum number of Job indicators that can be stored in the Job Multiplexer. (currently 2 as only Sync/Async jobs can be handled)

/// @brief    Data type used for maintaining the transmission lane state. It is handled as a bitfield.
///           Possible values: @ref LANE_STATE_INIT , @ref LANE_STATE_SYNC_BUFFER_TRANSMISSION ,@ref LANE_STATE_ASYNC_QUEUE_TRANSMISSION , @ref LANE_STATE_TRANSMISSION_WITH_MTA_FRAME_REQUEST , @ref LANE_STATE_IDLE
typedef uint8 t_LaneState;

/// @brief    Union pointer for correction of data alignment
typedef union
{
  /// Generic pointer
  void const * Pointer;
  /// Value of pointer
  uint32       Value;
} t_AlignmentPointer;

/// @brief    Bit shift for function id at header control field
#define MTSI_CTRL_FIELD_FUNCTION_ID_SHIFT 0u

/// @brief    Bit shift for packet counter at header control field
#define MTSI_CTRL_FIELD_PACKET_COUNTER_SHIFT 1u

/// @brief    Bit shift for high res timestamp at header control field
#define MTSI_CTRL_FIELD_HIGH_RES_TIMESTAMP_SHIFT 2u

/// @brief    Bit shift for absolute timestamp at header control field
#define MTSI_CTRL_FIELD_ABSOLUTE_TIMESTAMP_SHIFT 3u

/// @brief    Bit shift for checksum at header control field
#define MTSI_CTRL_FIELD_CHECKSUM_SHIFT 4u

/// @brief    Bit mask for checksum at header control field
#define MTSI_CTRL_FIELD_CHECKSUM_MASK 7u

/// @brief      Invalid task id. Used to indicate an empty task info entry.
#define MTSI_INVALID_TASK_ID (uint16)0xFFFF

/// @brief      Maximum value of task counter. Task counter will be set back to 0 if this threshold is exceeded.
/// @range      0 - UINT16_MAX
#define MTSI_MAX_VALUE_TASK_COUNTER (uint16)0xFFFFu

#define MTSI_START_SEC_VAR_INIT_ASIL_B_CACHED_UNSPECIFIED
#include <MTSI_MemMap_Cfg.h>

/// @brief    Status of MTSI driver module
/// @range    0 - 4
static t_ModuleState ModuleState = MODULE_UNINITIALIZED;

/// @brief    Status of MTA frames
/// @range    0 - 1
static t_MTAFrameState MTAFrameState[CFG_MTSI_NUMBER_OF_LANES] = { MTA_FRAME_INACTIVE };

/// @brief    Status of lanes
/// @range    0 - 4
static t_LaneState LaneState[CFG_MTSI_NUMBER_OF_LANES] = { LANE_STATE_INIT };

/// @brief    Transmission multiplexer. \n
///           Each lane has its own multiplexer to handle the job transmission.
///           The multiplexer is set to the core that will be processed next or is in process.
/// @range    0 - (CFG_MTSI_NUMBER_OF_CORES - 1)
static uint16 Multiplexer[CFG_MTSI_NUMBER_OF_LANES] = { 0u };

/// @brief    Indicator of the current Lane Job status. Used to determine whether a new transmission 
///           must be initiated on the selected Lane or not.
static t_MTSi_Std_ReturnType LaneTriggerStatus[CFG_MTSI_NUMBER_OF_LANES] = { MTSI_E_NO_REQUEST };

/// @brief    Contains the MTSi TaskIds and their corresponding TaskCounters that are used by the application.
///           These are dynamically added/updated during runtime via the dedicated interface. ( @ref MTSI_DriverStartTaskCycle )
static t_TaskInfo TaskInfoTable[CFG_MTSI_MAXIMUM_NUMBER_OF_TASKS] CFG_MTSI_DECLARATION_ATTRIBUTE = { { 0u } };

/// @brief    Start timestamp of MTA frame
/// @unit     1 �s           (in case high-res timestamp is configured)
///           100 �s         (in case low-res timestamp is configured)
/// @range    0 - UINT32_MAX (in case high-res timestamp is configured)
///           0 - UINT16_MAX (in case low-res timestamp is configured)
static MTSI_t_AbsoluteTimestamp TimestampFrameStart[CFG_MTSI_NUMBER_OF_LANES] = { 0u };

#if( (defined CFG_MTSI_HEADER_USE_PACKET_COUNTER) && (TRUE == CFG_MTSI_HEADER_USE_PACKET_COUNTER) )
static MTSI_t_sw_packet_counter Packet_Counter[CFG_MTSI_NUMBER_OF_LANES] = { 0u };
#endif

/* PRQA S 3218 2 *//* Global declaration required since it has to be encapsulated within macros section. */
/// @brief Time synchronization packet. Must be sent once within a MTA frame and contains the time reference for that particular frame.
static t_TimeSyncPacket TimeSyncPacket = { 0u };

/* PRQA S 3218 2 *//* Global declaration required since it has to be encapsulated within macros section. */
/// @brief Global counter used to calculate the time period when the Statistic data has to be sent out via the dedicated interface.
static uint8 CounterStaticStatistics = (uint8)0x00;

#if(MTSIADAPTER_DEBUG_ENABLE == STD_ON)
volatile static uint16 debug_loss_TaskId[4][5];
static uint8 debug_Taskid_index[4];
#endif
#define MTSI_STOP_SEC_VAR_INIT_ASIL_B_CACHED_UNSPECIFIED
#include <MTSI_MemMap_Cfg.h>


/// @brief      Pre initialization of MTSI driver module
/// @pre        none
/// @post       Perform initialization of sync buffers and async queues of all cores.
/// @param      none
/// @return     void
/// @globals
///   @ref ModuleState [MODULE_PREINITIALIZED, MODULE_INITIALIZED, MODULE_DE_INIT_REQUESTED, MODULE_DEINITIALIZED]
/// @InOutCorrelation
///   Initializes the sync buffer, async queues and the task info IDs/Counters.
/// @callsequence
/// @image html PreInit.png Sequence Diagram
/// @testmethod
///   1) @ref TEST_PreInit_1 : Code coverage for PreInit() function. \n
///
/// @traceability N/A
static void PreInit(void);

  /// @brief      Post initialization of MTSI driver module
  /// @pre        none
  /// @post       Perform initialization of PAL and custom module.
  /// @param      none
  /// @return     void
  /// @globals
  ///   @ref  ModuleState [MODULE_PREINITIALIZED, MODULE_INITIALIZED, MODULE_DE_INIT_REQUESTED, MODULE_DEINITIALIZED]
  /// @InOutCorrelation
  ///   Based on the common settings custom specific initialization, if the status is E_OK, it will initialize PAL and change the
  ///   status of MTSI driver module to done complete initialization of module (MODULE_INITIALIZED).
  /// @callsequence
  /// @image html PostInit.png Sequence Diagram
  /// @testmethod
  ///   1) @ref TEST_PostInit_1 : Code coverage for PostInit() function. Both cases - where the custom part is/is not initialized successfully - are covered. \n
  ///
  /// @traceability N/A
  static void PostInit(void);

  /// @brief        Initialize buffer for synchronous jobs
  /// @pre          none
  /// @post         none
  /// @param[in]    p_SyncBuffer Control of sync buffer to be initialized \n
  /// @param[in]    CoreId Core that is related to this buffer
  /// @return       void
  /// @globals      none
  /// @InOutCorrelation
  ///   When the pointer for sync buffer is not valid it will set a checkpoint. Otherwise it will initialize the indices, reset the transmition info, initialize the toggle buffers and core specific values and store the sync buffer config at statistic data .
  /// @callsequence
  /// @image html InitSyncBuffer.png Sequence Diagram
  /// @testmethod
  ///   1) @ref TEST_InitSyncBuffer_1 : Code coverage for function InitSyncBuffer() in case of invalid parameters (non initialized sync buffer pointer). \n
  ///   2) @ref TEST_InitSyncBuffer_2 : Code coverage for InitSyncBuffer(t_SyncBufferControl,uint8) function at regular circumstances. \n
  /// @traceability
  static void InitSyncBuffer(t_SyncBufferControl *const p_SyncBuffer, const uint8 CoreId);

/// @brief Initialize queue for asynchronous jobs
/// @pre   none
/// @post  none
/// @param[in] p_AsyncQueue   Async queue to be initialized \n
/// @param CoreId         Core that is related to this queue \n
/// @param LaneId         Lane that is related to this queue \n
/// @return void
/// @globals none
/// @InOutCorrelation
///   If the input parameters are not valid it will set a error checkpoint.
///	  Otherwise it will update the queue size, calculate the queue offset in case of multiple lanes and initialize the internal queue structure.
/// @callsequence
/// @image html InitAsyncQueue.png Sequence Diagram
/// @testmethod
///   1) @ref TEST_InitAsyncQueue_1 : Code coverage for InitAsyncQueue() function for both valid or invalid parameters. " \n
///
/// @traceability
static void InitAsyncQueue(t_AsyncQueue * const p_AsyncQueue, const uint8 CoreId, const uint8 LaneId);

/// @brief        Write synchronous job to buffer
///         Store sync job in toggle buffer
///         - Check if size of buffer is sufficient for this job
///         - Get buffer where job shall be stored
///         - Store job in appropriate buffer
///         The header is always stored in big-endian.
/// @pre    none
/// @post   none
/// @param[in]  p_Header    Pointer to the MTS header of this job \n
/// @param[in]  p_Data      Pointer to the data of this job \n
/// @param[in]  p_Callback  Callback function of this job \n
/// @return MEASReturn_t
/// @globals
///   @ref ModuleState [MODULE_PREINITIALIZED, MODULE_INITIALIZED, MODULE_DE_INIT_REQUESTED, MODULE_DEINITIALIZED]
/// @InOutCorrelation 
///   If the buffer update is done without errors, the function shall return "Sync job accepted" (MEAS_SYNC_JOB_ACCEPTED)
///   If no sync buffer is available for the job, it will return MEEAS_SYNC_JOB_REJECTED_NO_BUFFER.
//    f the freeze length exceeded the buffer size we will have MEAS_SYNC_JOB_REJECTED_FULL_BUFFER.
///   If the buffer update is requested from a invalid core, it shall return MEAS_SYNC_JOB_INVALID_CORE_ID.
/// @callsequence
/// @image html WriteToBuffer.png Sequence Diagram
/// @testmethod
///   1) @ref TEST_WriteToBuffer_1 : Test functionality in case of invalid Core: ID is equal/greater than(boundary) CFG_MTSI_NUMBER_OF_CORES \n
///   2) @ref TEST_WriteToBuffer_2 : Test functionality for null/non null LengthOverlap value. The FreezeLength exceeds the allocated BufferSize \n
///   3) @ref TEST_WriteToBuffer_3 : Test functionality for valid core ID; FreezeLength fits in the allocated BufferSize (both equal/less than - boundary values - covered).  \n
///                                  Check functionality for both allocated/non allocated ToogleBuffers and allocated/non allocated callback functions. \n
/// @traceability N/A
static MEASReturn_t WriteToBuffer(MTSI_t_Header * const p_Header, void const * const p_Data, const MTSI_t_Callback p_Callback);

/// @brief     Retrieve buffer size of specified core
///            The buffer sizes for each core are specified in MTSI_Cfg.h.
/// @pre       none
/// @post      none
/// @param[in] CoreId Core whose buffer size is required
/// @return    uint32
/// @globals
///   @ref MainControl
/// @InOutCorrelation   none
/// @callsequence
/// @image html GetBufferSize.png Sequence Diagram
/// @testmethod
///   1) @ref TEST_GetBufferSize_1 : Code coverage for function GetBufferSize() in case of regular circumstances or invalid parameters. \n
/// @traceability
static uint32 GetBufferSize(const uint8 CoreId);

/// @brief      Retrieves the next toggle buffer
///             NULL pointer will be returned in case there is currently no free toggle buffer available.
/// @pre        none
/// @post       none
/// @param[in]  CoreId   Core for that a free toggle buffer is required
/// @return     t_ToggleBuffer
/// @globals
///   @ref MainControl
/// @InOutCorrelation   none
/// @callsequence
/// @image html GetNextToggleBuffer.png Sequence Diagram
/// @testmethod
///   1) @ref TEST_GetNextToggleBuffer_1 : Test functionality of GetNextToggleBuffer() for both valid/invalid cores. CoreID equal/less than/ greater than CFG_MTSI_NUMBER_OF_CORES \n
/// @traceability
static t_ToggleBuffer * GetNextToggleBuffer(const uint8 CoreId);

/// @brief      Retrieve toggle buffer in that job can be stored
///             NULL pointer will be returned in case there is currently no free toggle buffer available.
/// @pre        none
/// @post       none
/// @param[in]  CoreId     Core for that a free toggle buffer is required \n
/// @param[in]  DataLength Length of data to be stored
/// @return     t_ToggleBuffer
/// @globals
///   @ref MainControl
/// @InOutCorrelation  none
/// @callsequence
/// @image html GetToggleBuffer.png Sequence Diagram
/// @testmethod
///   1) @ref TEST_GetToggleBuffer_1 : Test functionality in case both Active & Next ToogleBuffers are invalid (NULL) \n
///   2) @ref TEST_GetToggleBuffer_2 : Test functionality for FREE ActiveToogleBuffer, with the freeze DataLength fitting the ActiveBufferSize (both equal/less than - boundary check) \n
///   3) @ref TEST_GetToggleBuffer_3 : Test functionality for FREE ActiveToogleBuffer, insufficient remaining BufferSize, FREE NextToogleBuffer, with freeze DataLength within/outside the remaining NextBufferSize (boundary check) \n
///   3) @ref TEST_GetToggleBuffer_4 : Test functionality for FREE ActiveToogleBuffer, insufficient remaining BufferSize, OVERDUE Next ToogleBuffer, with freeze DataLength within/outside the remaining NextBufferSize (boundary check) \n
///   5) @ref TEST_GetToggleBuffer_5 : Test functionality for OVERDUE ActiveToogleBuffer, FREE Next ToogleBuffer, with freeze DataLength within/outside the remaining NextBufferSize (boundary check) \n
///   6) @ref TEST_GetToggleBuffer_6 : Test functionality for OVERDUE ActiveToogleBuffer, FULL Next ToogleBuffer, with freeze DataLength within/outside the remaining ActiveBufferSize (boundary check) \n
///   7) @ref TEST_GetToggleBuffer_7 : Test functionality for FULL ActiveToogleBuffer, FREE/OVERDUE Next ToogleBuffer, with freeze DataLength within the remaining NextBufferSize (boundary check) \n
///   8) @ref TEST_GetToggleBuffer_8 : Test functionality for REJECTED ActiveToogleBuffer, FREE/OVERDUE Next ToogleBuffer, with freeze DataLength outside the remaining NextBufferSize (boundary check) \n
///   9) @ref TEST_GetToggleBuffer_9 : Test functionality for PENDING ActiveToogleBuffer, FREE/OVERDUE Next ToogleBuffer, with freeze DataLength within/outside the remaining NextBufferSize (boundary check) \n
///
/// @traceability
static t_ToggleBuffer * GetToggleBuffer(const uint8 CoreId, const uint32 DataLength);

/// @brief       Retrieve currently active toggle buffer of specified core
/// @pre         none
/// @post        none
/// @param[in]   CoreId Core whose currently active toggle buffer is required
/// @return      t_ToggleBuffer
/// @globals
///   @ref MainControl
/// @InOutCorrelation   none
/// @callsequence
/// @image html GetActiveToggleBuffer.png Sequence Diagram
/// @testmethod
///   1) @ref TEST_GetActiveToggleBuffer_1 : Test GetActiveToggleBuffer functionality for the provided CoreId. \n
/// @traceability N/A
static t_ToggleBuffer * GetActiveToggleBuffer(const uint8 CoreId);

/// @brief       Update the Read Index to the next valid Sync Buffer -> Toggle Buffer
/// @pre         none
/// @post        none
/// @param[in]   CoreId Active core for which the toggle buffer is required
/// @return      t_ToggleBuffer
/// @globals
///   @ref MainControl
/// @InOutCorrelation   Update the Read Index to the next valid Sync Buffer -> Toggle Buffer
/// @callsequence
/// @image html SetNextToggleBufferReadActive.png Sequence Diagram
/// @testmethod
///   1) @ref TEST_SetNextToggleBufferReadActive_1 : Test functionality for OVERDUE/FULL ToogleBuffer state. \n
///   2) @ref TEST_SetNextToggleBufferReadActive_2 : Test functionality for FREE ToogleBuffer state. \n
/// @traceability N/A
static void SetNextToggleBufferReadActive(const uint8 CoreId);

/// @brief          Set next toggle buffer of specified core active
/// @pre            none
/// @post           none
/// @param[in]      CoreId   Core whose next buffer will be set active
/// @return         void
/// @globals
///   @ref MainControl
/// @InOutCorrelation   none
/// @callsequence
/// @image html SetNextToggleBufferWriteActive.png Sequence Diagram
/// @testmethod
///   1) @ref TEST_SetNextToggleBufferActive_1 : Test SetNextToggleBufferActive() functionality. \n
/// @traceability N/A
static void SetNextToggleBufferWriteActive(const uint8 CoreId);

/// @brief      Check transmission status of all sync buffers
///             Check if the transmission of any sync buffer is overdue.
/// @pre        none
/// @post       none
/// @param      none
/// @return     void
/// @globals
///   @ref MainControl
/// @InOutCorrelation 
///   The function sets the active buffer to OVERDUE, if the remaining toggle buffers are free.
///   If the active buffer is overdue, is valid and has valid data to transmit, it shall be marked as OVERDUE for the next transmission.
/// @callsequence
/// @image html CheckSyncBufferTransmissionStatus.png Sequence Diagram
/// @testmethod
///   1) @ref TEST_CheckSyncBufferTransmissionStatus_1 : Test functionality for invalid parameters: invalid ToogleBuffer, ToogleBuffer Level is 0.  \n
///   2) @ref TEST_CheckSyncBufferTransmissionStatus_2 : Test functionality for valid parameters with Overdue check requested. \n
/// @traceability N/A
static void CheckSyncBufferTransmissionStatus(void);

/// @brief      Write asynchronous job to queue
///       Store freeze in async queue
///       - Get queue where job can be stored
///       - Store job in appropriate queue
/// The header is always stored in big-endian.  
/// @pre       none
/// @post      none
/// @param[in] LaneId     Lane in whose queue the job shall be stored \n
/// @param[in] p_Header   Header of asynchronous job \n
/// @param[in] p_Data     Data of asynchronous job \n
/// @param[in] p_Callback Callback function of asynchronous job
/// @return MEASReturn_t
/// @globals
///  @ref  MainControl
/// @InOutCorrelation
///   If the input parameters (executing core, requested LaneID, data and header buffers) it will align the data pointer and payload length depending
///   the configured byte alignment, add the job in queue, update the MTSI internal structure and return MEAS_ASYNC_JOB_ACCEPTED.
///   If the queue does not have any free entries to store the job, MEAS_ASYNC_JOB_REJECTED_QUEUE_FULL shall be returned and a error checkpoint set.
///   If the size of the async queues is 0 it will return MEAS_ASYNC_JOB_REJECTED_QUEUE_ZERO and set a error checkpoint.
///   If the core id context is not valid it will return MEAS_ASYNC_JOB_INVALID_CORE_ID and set a error checkpoint.
///   If the input parameters are not valid it will return MEAS_ASYNC_JOB_INVALID_INPUT_PARAM and set a error checkpoint.
/// @callsequence
/// @image html WriteToQueue.png Sequence Diagram
/// @testmethod
///   1) @ref TEST_WriteToQueue_1 : Check functionality for valid parameters: CoreId equal/less than CFG_MTSI_NUMBER_OF_CORES (boundary check), valid LaneId, and free entries in the AsyncQueue. \n
///   2) @ref TEST_WriteToQueue_2 : Code coverage for invalid parameters: invalid CoreId; invalid LaneId; no entries available in the AsyncQueue. \n
/// @traceability
static MEASReturn_t WriteToQueue(const uint8 LaneId, MTSI_t_Header * const p_Header, void const * const p_Data, const MTSI_t_Callback p_Callback);

/// @brief      Trigger data transmission at the lower level. (MTSi PAL level)
///       This is done in 2 stages:
///       - first, the available Async and Sync jobs from the Driver level are sent towards the PAL level.
///       There is no actual transmission done at this point, the jobs are only intended for queuing by PAL. \n
///       - if queuing was done without errors, the actual transmission is triggered.
/// @pre       none
/// @post      none
/// @param[in] none
/// @return    void
/// @globals  
///   @ref ModuleState [MODULE_PREINITIALIZED, MODULE_INITIALIZED, MODULE_DE_INIT_REQUESTED, MODULE_DEINITIALIZED] \n
///   @ref LaneState [LANE_STATE_INIT] \n
///   @ref LaneTriggerStatus [MTSI_E_NO_REQUEST] \n
///   @ref Multiplexer
/// @InOutCorrelation 
///   Parse through ALL configured lanes, and for each individual one, if the LaneState is IDLE, send ALL the available jobs to PAL for queuing. \n
///   If the PAL queue is full, set this info in the LaneTriggerStatus variable, so it can be used later in the TransmissionDone callback to
///   retrigger a new Transmission process. \n
///   If the PAL queue is full or all the available jobs have been setup successfully, add in the Multiplexer variable the necessary information
///   (what job type: Sync/Async and for which core: 0..CFG_MTSI_NUMBER_OF_CORES ) that shall be later used in the TransmissionDone callback
///   to trigger the necessary Finalize operations.
/// @callsequence
/// @image html MTSI_TriggerGroupTransmission_SeqDiagram.png Sequence Diagram
/// @testmethod
///  1) @ref TEST_TriggerGroupTransmission_1 : Test functionality for INITIALIZED moduleState, Master CoreID (0), IDLE LaneState, Sync/Async Queuing Status reported as OK/TRIG_REQUEST. \n
///  2) @ref TEST_TriggerGroupTransmission_2 : Test functionality for INITIALIZED moduleState, Master CoreID (0), IDLE LaneState, Sync/Async Queuing Status reported as NOK. \n
///  3) @ref TEST_TriggerGroupTransmission_3 : Test functionality for INITIALIZED moduleState, Master CoreID (0), IDLE LaneState, both Sync/Async Queuing Status reported as NO_REQUEST. \n
///  4) @ref TEST_TriggerGroupTransmission_4 : Test functionality for INITIALIZED moduleState, Master CoreID (0), IDLE LaneState, Sync/Async Queuing Status reported as OK, but PAL TransmissionTrigger fails. \n
///  5) @ref TEST_TriggerGroupTransmission_5 : Test functionality invalid parameters: moduleState is DEINITIALIZED, CoreID is not the MasterCore (1), LaneState is not IDLE. \n
/// @traceability N/A
static void TriggerGroupTransmission(void);

/// @brief     In case the transmission of the Sync/Async data is rejected at MTSI PAL level, this function resets the internal
///            MTSi Driver structures so that a new transmission could be attempted in the next main function iteration.
/// @pre       MTSI data transmission is rejected by the MTSi PAL layer.
/// @post      none
/// @param[in] LaneId - Lane for which the internal structures must be reset.
/// @return    void
/// @globals
///   @ref MainControl  \n
///   @ref LaneState \n
///   @ref LaneTriggerStatus \n
///   @ref Multiplexer
/// @InOutCorrelation
///   Parse through all configured cores, and if the core SyncBuffer is configured for the LaneId provided as parameter,
///   it will check the ToogleBuffer state. If the current state is TRANSMISSION_PENDING, it shall reset it to TRANSMISSION_REJECTED.
///   LaneState is set to IDLE and the TriggerStatus is set to TRIG_REQUEST, as the transmission needs to be retried in the next iteration.
/// @callsequence
/// @image html MTSI_ResetGroupTrasmissionContext_SeqDiagram.png Sequence Diagram
/// @testmethod
///  1) @ref TEST_ResetGroupTrasmissionContext_1 : Test functionality for the LaneID matching the SyncBuffer configured lane, and BufferState is TRANSMISSION_PENDING. \n
///  2) @ref TEST_ResetGroupTrasmissionContext_2 : Test functionality for the LaneID matching the SyncBuffer configured lane, and BufferState is FREE. \n
/// @traceability N/A
static void ResetGroupTrasmissionContext(const uint8 LaneId);

/// @brief      Parse through the configured SyncBuffers (considering the Lane / Core assignment) and, if the corresponding buffer
///             is FULL, OVERDUE or REJECTED, forward it to the PAL level where is shall be queued, then later transmitted during the batch
///             transmission trigger.
/// @pre        none
/// @post       none
/// @param[in]  CoreId Core whose buffer shall be sent
/// @param[in]  LaneId Lane whose buffer shall be sent
/// @return     @ref t_MTSi_Std_ReturnType
/// @globals  
///   @ref ModuleState [MODULE_PREINITIALIZED, MODULE_INITIALIZED, MODULE_DE_INIT_REQUESTED, MODULE_DEINITIALIZED] \n
///   @ref LaneState [LANE_STATE_INIT] \n
///   @ref LaneTriggerStatus [MTSI_E_NO_REQUEST] \n
///   @ref Multiplexer
/// @InOutCorrelation 
///   Check the state of the SyncBuffer allocated to the LaneId/CoreId input parameters. If the buffer state is FULL/OVERDUE
///   or it was REJECTED in a previous transmission, forward the Sync job to the PAL level where it shall be queued again, 
///   then retransmitted during the batch transmission job. In this case, the SyncBuffer state is marked as 
///   BUFFER_STATE_TRANSMISSION_PENDING.
///   If there are SyncBuffer jobs available, mark the corresponding @ref LaneState bit [LANE_STATE_SYNC_BUFFER_TRANSMISSION active].
/// @callsequence
/// @image html MTSI_TriggerSyncBufferGroupTransmission_SeqDiagram.png Sequence Diagram
/// @testmethod
///  1) @ref TEST_TriggerSyncBufferGroupTransmission_1 : Test functionality when the selected CoreId SyncBuffer matches the provided LaneId. Buffer State is FULL/OVERDUE/REJECTED, queuing at PAL level is OK.  \n
///  2) @ref TEST_TriggerSyncBufferGroupTransmission_2 : Test functionality when the selected CoreId SyncBuffer matches the provided LaneId. Buffer State is FULL/OVERDUE/REJECTED, queuing at PAL level is REJECTED.  \n
///  3) @ref TEST_TriggerSyncBufferGroupTransmission_3 : Test functionality when the selected CoreId SyncBuffer does NOT match the provided LaneId. \n
/// @traceability N/A
static t_MTSi_Std_ReturnType TriggerSyncBufferGroupTransmission(const uint8 CoreId, const uint8 LaneId);

/// @brief      Parse through the Async Queue and forward all the available Async jobs to the
///             PAL level where they will be queued until the batch transmission is triggered.
/// @pre        none
/// @post       none
/// @param[in]  CoreId Core whose queue shall be sent
/// @param[in]  LaneId Lane whose queue shall be sent
/// @return     @ref t_MTSi_Std_ReturnType
/// @globals  
///   @ref LaneState [LANE_STATE_INIT] \n
///   @ref MainControl \n
/// @InOutCorrelation 
///   Parse through the Lane and Core specific AsyncQueue, starting with the current AsyncQueue Head index. \n
///   For every valid Async job, pass it to the PAL level for queuing and increment the AsyncQueue Reference index.
///   If there are AsyncQueue jobs available, mark the corresponding @ref LaneState bit [LANE_STATE_ASYNC_QUEUE_TRANSMISSION active].
/// @callsequence
/// @image html MTSI_TriggerAsyncQueueGroupTransmission_SeqDiagram.png Sequence Diagram
/// @testmethod
///  1) @ref TEST_TriggerAsyncQueueGroupTransmission_1 : Test functionality for valid data to send (Head <> Tail) with both successful/failed queuing at PAL level. \n
///  2) @ref TEST_TriggerAsyncQueueGroupTransmission_2 : Test functionality for the use case with no data to send (Head == Tail). \n
/// @traceability N/A
static t_MTSi_Std_ReturnType TriggerAsyncQueueGroupTransmission(const uint8 CoreId, const uint8 LaneId);

/// @brief   Callback triggered by the PAL lower layer when a MTSi transmission if completed.
/// @pre     none
/// @post    none
/// @param[in] LaneId Lane on that transmission was completed
/// @return  void
/// @globals  
///   @ref LaneState [LANE_STATE_INIT] \n
///   @ref Multiplexer \n
///   @ref LaneTriggerStatus [MTSI_E_NO_REQUEST] \n
/// @InOutCorrelation 
///   Base on the content of the input Lane and global Multiplexer (containing indication onto the Core[0..CFG_MTSI_NUMBER_OF_CORES]/
///   Type[Sync/Async] performed transmission, the corresponding FinalizeSync/FinalizeAsync operations are triggered.
///   The @ref LaneState is set to IDLE and the Multiplexer is reset (0).
/// @callsequence
/// @image html MTSI_TransmissionGroupDoneCallback_SeqDiagram.png Sequence Diagram
/// @testmethod
///  1) @ref TEST_TransmissionGroupDoneCallback_1 : Test functionality for valid LaneID (less than/equal to CFG_MTSI_NUMBER_OF_LANES); SyncBuffer transmission completed (Sync bit set in the LaneState). \n
///  2) @ref TEST_TransmissionGroupDoneCallback_2 : Test functionality for valid LaneID (less than/equal to CFG_MTSI_NUMBER_OF_LANES); AsyncBuffer transmission completed (Async bit set in the LaneState). \n
///  3) @ref TEST_TransmissionGroupDoneCallback_3 : Test functionality when a new MTA frame has to be triggered of not; check if new GroupTransmission has to be triggered or not. \n
///  4) @ref TEST_TransmissionGroupDoneCallback_4 : Test functionality for invalid parameters: invalid LaneID; Lane State set to INIT. \n
/// @traceability N/A
static void TransmissionGroupDoneCallback(const uint8 LaneId);

/// @brief   MTSi internal structure update to mark the completion of the AsyncQueue Transmission.
/// @pre     none
/// @post    none
/// @param[in] CoreId ID of core of related async queue
/// @param[in] LaneId Lane on that transmission was done
/// @return  void
/// @globals  
///   @ref MainControl
/// @InOutCorrelation 
///   Parse through the AsyncQueue jobs that have been transmitted during the completed batch job, from
///   the AsyncQueue->Head towards the AsyncQueue->Reference. For each job, trigger - if available - 
///   the corresponding external callback and increment the AsyncQueue->Reference.
/// @callsequence
/// @image html MTSI_FinalizeAsyncGroupQueueTransmission_SeqDiagram.png Sequence Diagram
/// @testmethod
///  1) @ref TEST_FinalizeAsyncGroupQueueTransmission_1 : Test functionality for valid data sent (Head <> Tail), and both valid/invalid callback function are provided.  \n
///  2) @ref TEST_FinalizeAsyncGroupQueueTransmission_2 : Test functionality no valid data was sent (Head == Tail). \n
/// @traceability N/A
static void FinalizeAsyncGroupQueueTransmission(const uint8 CoreId, const uint8 LaneId);

/// @brief    Finalize transmission of sync buffer
/// @pre      none
/// @post     none
/// @param[in] CoreId ID of core of related sync buffer
/// @return   void
/// @globals  @ref MainControl
/// @InOutCorrelation
///   If the sync buffer has been transmitted (BUFFER_STATE_TRANSMISSION_PENDING), it will clear the toggle buffer (level and state), and get the next toggle buffer.
/// @callsequence
/// @image html FinalizeSyncBufferTransmission.png Sequence Diagram
/// @testmethod
///   1) @ref TEST_FinalizeSyncBufferTransmission_1 : Test functionality for both valid sent SyncBuffer (State == TRANSMISSION_PENDING) and invalid SyncBuffer .\n
/// @traceability N/A
static void FinalizeSyncBufferTransmission(const uint8 CoreId);

/// @brief    Store time sync packet in the priority queue
/// @pre      none
/// @post     none
/// @param[in] LaneId ID of lane for that time sync packet shall be stored
/// @return   void
/// @globals  none
/// @InOutCorrelation 
///   it will set the freeze information, create the MTS header , adapt the task id and counter, update time sync packet and store the data in a priority queue. 
/// @callsequence
/// @image html StoreTimeSyncPacket.png Sequence Diagram
/// @testmethod
///   1) TEST_StoreTimeSyncPacket_1: Test functionality for both successful/unsuccessful measfreeze of the TimeSync packet. \n
/// @traceability N/A
static void StoreTimeSyncPacket(const uint8 LaneId);

/// @brief     Start a new MTA frame on the specified lane
/// @pre       none
/// @post      none
/// @param[in] LaneId ID of lane on that new MTA frame shall be started
/// @return    void
/// @globals
///   @ref MTAFrameState  \n
///   @ref ModuleState  \n
///   @ref LaneState \n
/// @InOutCorrelation 
///   In case of valid lane id and MTA frame active, it will update the status of the MTA frame to MTA_FRAME_INACTIVE. If, additionally, a de-initialization
///   of the module has been requested (MODULE_DE_INIT_REQUESTED) it will trigger the corresponding actions if no other MTA frame is active.
///   If the MTA frame was not started successfully it shall set a error checkpoint.
///   If the lane id is not valid it will set a error checkpoint.
/// @callsequence
/// @image html StartMTAFrame.png Sequence Diagram
/// @testmethod
///   1) @ref TEST_StartMTAFrame_1 : Test functionality for the normal use case: valid LaneId; MTA frame state is Active: successful Finish/Start of the MTA frame. \n
///   2) @ref TEST_StartMTAFrame_2 : Test functionality for valid LaneId; MTA frame state is Active: request de-initialization of the module. \n
///   3) @ref TEST_StartMTAFrame_3 : Test functionality for valid LaneId, with failed finish of the MTA frame at PAL level. \n
///   4) @ref TEST_StartMTAFrame_4 : Test functionality for valid LaneId, with successful finish, but failed start of the MTA frame at PAL level. \n
/// @traceability N/A
static void StartMTAFrame(const uint8 LaneId);

/// @brief   Retrieve the header control field
///          The header control field will be built regarding configuration at MTSI_Cfg.
/// @pre     none
/// @post    none
/// @param   none
/// @return  uint8
/// @globals none
/// @InOutCorrelation
///   It will generate byte with Config-Specific control field and will return it.
/// @callsequence
/// @image html GetHeaderCtrlField.png Sequence Diagram
/// @testmethod
///  1) @ref TEST_GetHeaderCtrlField_1 : Code coverage for function GetHeaderCtrlField() - updating the value for control field of MTSI header. \n
/// @traceability N/A
static uint8 GetHeaderCtrlField(void);

/// @brief     Get task info entry
///            Retrieve task info depending on current core and task.
/// @pre       none
/// @post      none
/// @param[in] TaskId Task, for which cycle counter shall be returned.
/// @return    uint16
/// @globals   @ref MainControl[CFG_MTSI_NUMBER_OF_CORES]
/// @InOutCorrelation
///  It will get the core id from Pal function MTSI_PalGetCoreId(), checks the validity of id and while the number of tasks is not maximal, it will get the entry of task info table. 
///	 If the input patameter is the same as the task ID from OS, it will change the value of the task counter. 
///  If the core id is not valid it will set a checkpoint and return the default value of the task counter. 
/// @callsequence
/// @image html GetTaskCounter.png Sequence Diagram
/// @testmethod
///   1) @ref TEST_GetTaskCounter_1 : Test functionality when a unused TaskId is provided. (boundary check : TaskIndex reaches CFG_MTSI_MAXIMUM_NUMBER_OF_TASKS) \n
///   2) @ref TEST_GetTaskCounter_2 : Test functionality when a used/existing TaskId is provided. \n
/// @traceability N/A
static uint16 GetTaskCounter(const uint16 TaskId);

/// @brief    Adapt alignment of async job
///           Data pointer and data length are adapted to a platform specific alignment (e.g. 16 bit or 32bit), depending on the HW capabilities.
///
///           Data pointer is corrected to the next lower address (i.e. address is divisible by platform specific alignment).
///           Pointer correction is compensated by increasing the number of padding bytes in MTS header.
/// 
///           Data length is corrected to the next higher length (i.e. length is a multiple of platform specific alignment).
///           Length correction is not compensated. Additional bytes are not described in sdl file and not visible on MTS.
/// @pre     none
/// @post    none
/// @param[in] p_Header Header of job, which shall be aligned.
/// @param[in] p_Data  Data of job, which shall be aligned.
/// @return  void
/// @globals none
/// @InOutCorrelation
///    When the input parameters are valid, it will get the number of bytes for the required alignment for length and additional bytes for pointer offset, and then get the correct length of payload. 
/// @callsequence
/// @image html AdjustJobAlignment.png Sequence Diagram
/// @testmethod
///   1) @ref TEST_AdjustJobAlignment_1 : Test functionality for both use-cases: when length alignment must be adjusted and when not. \n
/// @traceability N/A
static void AdjustJobAlignment(MTSI_t_Header * const p_Header, void const ** p_Data);

/// @brief    Check if any MTA frame is currently active  
/// @pre      none
/// @post     none
/// @param    none
/// @return   boolean
/// @globals
///   @ref MTAFrameState[CFG_MTSI_NUMBER_OF_LANES]
/// @InOutCorrelation
///   Returns b_FALSE by default, otherwise if any MTA frame of the current lane is active it will return b_TRUE.
/// @callsequence
/// @image html IsMTAFrameActive.png Sequence Diagram
/// @testmethod
///   1) @ref TEST_IsMTAFrameActive_1 : Test functionality in case MTA frame is/is not currently active. \n
/// @traceability
static boolean IsMTAFrameActive(void);

#define MTSI_START_SEC_CODE_ASIL_B
#include <MTSI_MemMap_Cfg.h>

void MTSI_DriverInit(void)
{
  
  // Check if module is currently not initialized
  if( (MODULE_UNINITIALIZED == ModuleState) || (MODULE_DEINITIALIZED == ModuleState) )
  {
    // Accomplish pre-initialization
    PreInit();
  
    // Accomplish post-initialization
    PostInit();
  }
  else
  {
    // Nothing needs to be done
  }
}

void MTSI_DriverDeInit(void)
{
  // Status of MTA frames
  boolean MTAFrameActive = b_FALSE;
  
  // Accomplish deinitialization of PAL
  MTSI_PalDeInit();
  
  // Check if any MTA frame is active
  MTAFrameActive = IsMTAFrameActive();
  
  // Finalize deinitialization in case no MTA frame is currently active
  if( b_FALSE == MTAFrameActive )
  {
    // Change module state regarding finished deinitialization
    ModuleState = MODULE_DEINITIALIZED;
  }
  else
  {
    // Change module state regarding requested deinitialization *
    ModuleState = MODULE_DE_INIT_REQUESTED;
  }
}

void MTSI_DriverMainFunction(void)
{
  uint8 ui8_LaneIndex = 0u;

  // Check if necessary to handle the statistics
  if( (uint8)0x00 == (CounterStaticStatistics % (CFG_MTSI_STATISTICS_CYCLE_TIME_MS / CFG_MTSI_CYCLE_TIME_CYCLIC_RUNNABLE)) )
  {
    // Store static statistics
    // StoreStaticStatistics();

    // Store checkpoints if enabled
    // StoreCheckpoints();

    // Reset counter
    CounterStaticStatistics = (uint8)0x00;
  }
  else
  {
    // Nothing needs to be done
  }

  /* PRQA S 2877 1 *//* "This loop will never be executed more than once." *//* Loop required for MTSI generic handling: number of cores/lanes may be > 1 */
  for (ui8_LaneIndex = 0; ui8_LaneIndex<CFG_MTSI_NUMBER_OF_LANES; ui8_LaneIndex++)
  {
    // StoreDynamicStatistics(ui8_LaneIndex);
  }

  // Increment counters
  CounterStaticStatistics++;
  
  // Check if post-initialization is still missing
  if( MODULE_PREINITIALIZED == ModuleState )
  {
    // Accomplish post-initialization
    PostInit();
  }
  else
  {
    // Nothing needs to be done
  }        

  /* Force transmission of the SyncBuffer. Do this here, and not within the TriggerGroupTransmissionStatus(),
   * since the TriggerGroupTransmissionStatus may also be called from within the Transmission Done callback
   * function, and we don't want to force the sync transmission there. */
  CheckSyncBufferTransmissionStatus();

  TriggerGroupTransmission();
}

void MTSI_DriverPrepareHeader(MTSI_t_FreezeInfo const *const p_FreezeInfo, MTSI_t_Header *const p_Header)
{
  // Check validity of input parameters
  if ((NULL != p_FreezeInfo) && (NULL != p_Header))
  {
    // Retrieve task id
    const uint16 TaskId = p_FreezeInfo->FunctionId;

#if ((defined CFG_MTSI_HEADER_USE_PACKET_COUNTER) && (TRUE == CFG_MTSI_HEADER_USE_PACKET_COUNTER))
    const uint8 LaneId = MTSI_CustomGetLaneId(p_FreezeInfo->FunctionId);
#endif

    // Set virtual address
    p_Header->VirtualAddress = p_FreezeInfo->VirtualAddress;

    // Set control field and payload length
    p_Header->CtrlFieldAndPayloadLength = (uint32)GetHeaderCtrlField() << MTSI_CTRL_FIELD_BIT_SHIFT;
    p_Header->CtrlFieldAndPayloadLength |= (p_FreezeInfo->Length & MTSI_PAYLOAD_LENGTH_BIT_MASK);

    // Set task identifier and counter
    p_Header->TaskIdentifier = TaskId;
    p_Header->TaskCounter = GetTaskCounter(TaskId);

// Set function information
#if ((defined CFG_MTSI_HEADER_USE_FUNCTION_ID) && (TRUE == CFG_MTSI_HEADER_USE_FUNCTION_ID))
    p_Header->FunctionId = p_FreezeInfo->FunctionId;
#endif

// Set packet counter
#if ((defined CFG_MTSI_HEADER_USE_PACKET_COUNTER) && (TRUE == CFG_MTSI_HEADER_USE_PACKET_COUNTER))
    Packet_Counter[LaneId]++;
    p_Header->PacketCounter = Packet_Counter[LaneId];
#endif

    // Set timestamp
    // - Always an absolute timestamp is set here
    p_Header->Timestamp.Absolute = MTSI_PalGetTimestamp();

// Set padding bytes
#if ((defined CFG_MTSI_HEADER_NUMBER_OF_PADDING_BYTES) && (0u != CFG_MTSI_HEADER_NUMBER_OF_PADDING_BYTES))
    p_Header->PaddingLength = CFG_MTSI_HEADER_NUMBER_OF_PADDING_BYTES;
    /* PRQA S 314 1 */ /* Cast to void-pointer is required because of generic interface of memset. */
    (void)memset((void *)p_Header->PaddingBytes, 0, sizeof(p_Header->PaddingBytes));
#else
  p_Header->PaddingLength = 0u;
#endif
  }
  else
  {
    // Set checkpoint because of invalid input parameters
    MTSI_StatsSetCheckpoint((uint8)MTSI_CHKPT_ID_FUNC_PREPARE_HEADER, (uint8)MTSI_CHKPT_ERR_ID_0, p_Header);
  }
}

MEASReturn_t MTSI_DriverStoreSyncJob(MTSI_t_Header *const p_Header, void const *const p_Data, const MTSI_t_Callback p_Callback)
{
  MEASReturn_t MEASReturn_DriverStoreSyncJob = MEAS_OK;

  // Check if initialization is done
  if (MODULE_INITIALIZED == ModuleState)
  {
    // Write job to the appropriate buffer
    MEASReturn_DriverStoreSyncJob = WriteToBuffer(p_Header, p_Data, p_Callback);
  }
  else
  {
    // Nothing needs to be done
  }

  return MEASReturn_DriverStoreSyncJob;
}

MEASReturn_t MTSI_DriverStoreAsyncJob(const uint8 LaneId, MTSI_t_Header *const p_Header, void const *const p_Data, const MTSI_t_Callback p_Callback)
{
  MEASReturn_t MEASReturn_DriverStoreAsyncJob = MEAS_OK;

  // Check if initialization is done
  if (MODULE_INITIALIZED == ModuleState)
  {
    // Write job to the appropriate queue
    MEASReturn_DriverStoreAsyncJob = WriteToQueue(LaneId, p_Header, p_Data, p_Callback);
  }
  else
  {
    // Nothing needs to be done
  }

  return MEASReturn_DriverStoreAsyncJob;
}

void MTSI_DriverStartMTACycle(const uint8 LaneId)
{
  // Check if initialization is done
  if ((MODULE_INITIALIZED == ModuleState) || (MODULE_DE_INIT_REQUESTED == ModuleState))
  {
    // Check validity of lane id */
    if ((uint8)CFG_MTSI_NUMBER_OF_LANES > LaneId)
    {
      // Variable for incoming lane state
      t_LaneState OldLaneState;

      // Flag to indicate idle lane
      boolean LaneIdle = b_FALSE;

      // Suspend interrupts
      (void)MTSI_PalEnterExclusiveArea();

      // Store incoming lane state
      OldLaneState = LaneState[LaneId];

      if ((OldLaneState == LANE_STATE_INIT) || (OldLaneState == LANE_STATE_IDLE))
      {
        LaneIdle = b_TRUE;
      }
      else
      {
        // Mark in the LaneState that a MTA frame Start is requested. This will be interpreted in the
        // TransmisisonDoneCallback and the FrameStart shall be triggered there.
        LaneState[LaneId] |= LANE_STATE_TRANSMISSION_WITH_MTA_FRAME_REQUEST;
      }

      // Check if MTA frame can be started immediately
      if (b_TRUE == LaneIdle)
      {
        // Start new MTA frame
        StartMTAFrame(LaneId);
      }
      else
      {
        // Nothing needs to be done
      }

      // Resume interrupts
      MTSI_PalExitExclusiveArea();
    }
    else
    {
      // Set checkpoint because lane id is out of range
      MTSI_StatsSetCheckpoint((uint8)MTSI_CHKPT_ID_FUNC_START_MTA_CYCLE, (uint8)MTSI_CHKPT_ERR_ID_0, NULL);
    }
  }
  else
  {
    // Nothing needs to be done
  }
}

void MTSI_DriverStartTaskCycle(const uint16 TaskId)
{
  // Check if initialization is done
  if (MODULE_INITIALIZED == ModuleState)
  {
    // Variables for task handling
    t_TaskInfo *p_TaskInfo = NULL;
    uint8 TaskIndex = (uint8)0x00;

    // Retrieve info about this task
    while (((uint8)CFG_MTSI_MAXIMUM_NUMBER_OF_TASKS > TaskIndex) && (NULL == p_TaskInfo))
    {
      // Retrieve entry of task info table
      /* PRQA S 491 1 */ /* Array subscription of pointer required because of generic handling. */
      t_TaskInfo *p_TaskInfoEntry = &TaskInfoTable[TaskIndex];

      // Check if current task info entry must be used
      if (TaskId == p_TaskInfoEntry->TaskIdentifier)
      {
        // Get task info
        p_TaskInfo = p_TaskInfoEntry;
      }
      else if (MTSI_INVALID_TASK_ID == p_TaskInfoEntry->TaskIdentifier)
      {
        // Create new task info entry
        p_TaskInfoEntry->TaskIdentifier = TaskId;

        // Get task info
        p_TaskInfo = p_TaskInfoEntry;
      }
      else
      {
        // Nothing needs to be done
      }
      // Increment task index
      TaskIndex++;
    }

    // Check if task info entry is available
    if( NULL != p_TaskInfo )
    {
      if ( MTSI_MAX_VALUE_TASK_COUNTER == p_TaskInfo->TaskCounter )
      {
        // If limit of 65535 was reached in the past cycle, reset the counter
        p_TaskInfo->TaskCounter = 0x0U;
      }
      else
      {
        // Increment task counter
        p_TaskInfo->TaskCounter = p_TaskInfo->TaskCounter + (uint16)0x01U;
      }
    }
    else
    {
      // Set checkpoint because maximum number of processable tasks is exceeded
      MTSI_StatsSetCheckpoint((uint8)MTSI_CHKPT_ID_FUNC_START_TASK_CYCLE, (uint8)MTSI_CHKPT_ERR_ID_1, NULL);
    }

    /* PRQA S 0314 1 *//* Cast from a pointer to object type to a pointer to void. Needed due to the generic defined interface. */
    MTSI_PalFlushCache((const void *)&TaskInfoTable[0], (uint32)sizeof(TaskInfoTable));
  }
  else
  {
    // Set checkpoint because core id is out of range
    MTSI_StatsSetCheckpoint((uint8)MTSI_CHKPT_ID_FUNC_START_TASK_CYCLE, (uint8)MTSI_CHKPT_ERR_ID_0, NULL);
  }
}


static void PreInit(void)
{
  // Indices */
  uint8 CoreIndex;
  uint8 LaneIndex;
  uint8 TaskIndex;
  
  // Initialize control variables 
  /* PRQA S 2877 1 */ /* For loop required because it is possible that module has to support more than one core. */
  for(CoreIndex = 0u; (uint8)CFG_MTSI_NUMBER_OF_CORES > CoreIndex; CoreIndex++)
  {
    // Initialize sync buffer
    InitSyncBuffer(MainControl[CoreIndex].p_SyncBufferControl, CoreIndex);
  
    // Initialize async queues 
    /* PRQA S 2877 1 */ /* For loop required because it is possible that module has to support more than one lane. */
    for(LaneIndex = 0u; (uint8)CFG_MTSI_NUMBER_OF_LANES > LaneIndex; LaneIndex++)
    {
      InitAsyncQueue(MainControl[CoreIndex].p_AsyncQueueControl->p_AsyncQueues[LaneIndex], CoreIndex, LaneIndex);
    }
  }
  
  // Initialize task info
  for(TaskIndex = 0u; (uint8)CFG_MTSI_MAXIMUM_NUMBER_OF_TASKS > TaskIndex; TaskIndex++)
  {
    /* PRQA S 491 3 */ /* Array subscription of pointer required because of generic handling. */
    TaskInfoTable[TaskIndex].TaskIdentifier = MTSI_INVALID_TASK_ID;
    TaskInfoTable[TaskIndex].TaskCounter    = (uint16)0x00;
  }
  
  // Change module state regarding done preinitialization
  ModuleState = MODULE_PREINITIALIZED;
}


static void PostInit(void)
{
  // Status of custom initialization
  Std_ReturnType StatusCustomInit = E_NOT_OK;
  
  // Common settings
  uint8 Mode       = MTSI_OUTPUTMODE_OFF;
  uint8 InstanceNr = (uint8)0x00;
  
  // Accomplish custom specific initialization
  StatusCustomInit = MTSI_CustomInit(&Mode, &InstanceNr);
  
  // Store module configuration at statistic data
  MTSI_StatsStoreConfigurationSettings(Mode, InstanceNr);
  
  // Check if custom part has been initialized
  if( (Std_ReturnType)E_OK == StatusCustomInit )
  {
    // Initialize PAL
    MTSI_PalInit(Mode, InstanceNr, &TransmissionGroupDoneCallback, &StartMTAFrame, &TriggerGroupTransmission);
  
    // Change module state regarding done postinitialization
    ModuleState = MODULE_INITIALIZED;
  }
  else
  {
    // Nothing needs to be done
  }
}


static void InitSyncBuffer(t_SyncBufferControl * const p_SyncBuffer, const uint8 CoreId)
{
  // Check pointer validity
  if( NULL != p_SyncBuffer )
  {
    // Initialize indices
    p_SyncBuffer->ReadIndex  = 0u;
    p_SyncBuffer->WriteIndex = 0u;
  
    // Reset transmission info
    p_SyncBuffer->SentWithinMTACycle = b_FALSE;

    // Store sync buffer config at statistic data
    MTSI_StatsStoreSyncBufferStatistic(CoreId, p_SyncBuffer->LaneId, p_SyncBuffer->Size);
  }
  else
  {
    // Set checkpoint because of invalid pointer to sync buffer
    MTSI_StatsSetCheckpoint((uint8)MTSI_CHKPT_ID_FUNC_INIT_SYNC_BUFFER, (uint8)MTSI_CHKPT_ERR_ID_0, NULL);
  }
}


static void InitAsyncQueue(t_AsyncQueue * const p_AsyncQueue, const uint8 CoreId, const uint8 LaneId)
{
   // Initialize common values
   p_AsyncQueue->Head      = 0u;
   p_AsyncQueue->Tail      = 0u;
   p_AsyncQueue->Reference = 0u;

   // Store async queue config at statistic data
   MTSI_StatsStoreAsyncQueueStatistic(CoreId, LaneId, p_AsyncQueue->Size);
}


static MEASReturn_t WriteToBuffer(MTSI_t_Header * const p_Header, void const * const p_Data, const MTSI_t_Callback p_Callback)
{
  MEASReturn_t MEASReturn_WriteToBuffer = MEAS_OK;

  // Retrieve core id from PAL
  const uint8 CoreId = MTSI_PalGetCoreId();

  // Check validity of core id
  if( (uint8)CFG_MTSI_NUMBER_OF_CORES > CoreId )
  {
    // Local variables
    uint32 FreezeLength = 0u;
    uint32 BufferSize   = 0u;

    // Retrieve the sync buffer control structure (used for statistics)
    t_SyncBufferControl const* p_SyncBufferControl = MainControl[CoreId].p_SyncBufferControl;
    // Retrieve the dynamic statistics structure
    MTSI_t_DynamicStatistics * p_DynamicStatistics = MTSI_StatsGetDynamicStatistics(CoreId, p_SyncBufferControl->LaneId);

    // Adapt length of payload in header to required alignment
    const uint32 LengthOverlap = p_Header->CtrlFieldAndPayloadLength % CFG_MTSI_MEAS_FREEZE_BYTE_ALIGNMENT;
  
    if (LengthOverlap != 0uL)
    {
      p_Header->CtrlFieldAndPayloadLength += CFG_MTSI_MEAS_FREEZE_BYTE_ALIGNMENT;
      p_Header->CtrlFieldAndPayloadLength -= LengthOverlap;
    }
  
    // Calculate length of freeze
    FreezeLength  = (uint32)sizeof(MTSI_t_Header);
    FreezeLength += (p_Header->CtrlFieldAndPayloadLength & MTSI_PAYLOAD_LENGTH_BIT_MASK);
  
    // Retrieve size of buffer
    BufferSize = GetBufferSize(CoreId);
  
    // Check that freeze length does not exceed the buffer size
    if( BufferSize >= FreezeLength )
    {
      // Retrieve toggle buffer in that the data can be stored
      t_ToggleBuffer * const p_ToggleBuffer = GetToggleBuffer(CoreId, FreezeLength);
  
      // Check if toggle buffer is available
      if( NULL != p_ToggleBuffer )
      {
        // Header with converted endianness, only required in case of low byte first order
        #if( (defined CPU_BYTE_ORDER) && (LOW_BYTE_FIRST == CPU_BYTE_ORDER) )
        MTSI_t_Header ConvertedHeader;
        #endif
  
        // Get payload length
        const uint32 PayloadLength = p_Header->CtrlFieldAndPayloadLength & MTSI_PAYLOAD_LENGTH_BIT_MASK;
  
        // Copy header to buffer
        #if( (defined CPU_BYTE_ORDER) && (LOW_BYTE_FIRST == CPU_BYTE_ORDER) )
        ConvertedHeader = MTSI_PalConvertHeaderEndianness(p_Header);
        /* PRQA S 314, 491 6 */
        /* Casts to void-pointer are required because of generic interface of memcpy. */
        /* Array subscription of pointer required because of generic module structure. */
        (void)memcpy((void *)&p_ToggleBuffer->p_Buffer[p_ToggleBuffer->Level], (void *)&ConvertedHeader, sizeof(MTSI_t_Header));
        #else
        (void)memcpy((void *)&p_ToggleBuffer->p_Buffer[p_ToggleBuffer->Level], (void *)p_Header, sizeof(MTSI_t_Header));
        #endif
  
        // Copy data to buffer
        /* PRQA S 314, 491 4 */
        /* Casts to void-pointer are required because of generic interface of memcpy. */
        /* Array subscription of pointer required because of generic module structure. */
          (void)memcpy((void *)&p_ToggleBuffer->p_Buffer[p_ToggleBuffer->Level + (uint32)sizeof(MTSI_t_Header)], p_Data, PayloadLength);
  
        // Adapt buffer levels
        p_ToggleBuffer->Level += FreezeLength;
  
        /* PRQA S 0314 2 *//* Cast from a pointer to object type to a pointer to void. Needed due to the generic defined interface. */
        MTSI_PalFlushCache((const void *) &p_ToggleBuffer->p_Buffer[p_ToggleBuffer->Level - FreezeLength], FreezeLength);
        MTSI_PalFlushCache((const void *) p_ToggleBuffer, (uint32) sizeof(t_ToggleBuffer));

        // Call callback function if available
        if( NULL != p_Callback )
        {
          p_Callback();
        }
        else
        {
          // Nothing needs to be done
        }

        MEASReturn_WriteToBuffer = MEAS_SYNC_JOB_ACCEPTED;

        p_DynamicStatistics->SyncData.CurrentValue += FreezeLength;
      }
      else
      {
        // Set checkpoint + debug value + RTA marker because no buffer is available to store the job
        MTSI_StatsSetCheckpoint((uint8)MTSI_CHKPT_ID_SYNC_JOB_REJECTED, MainControl[CoreId].p_SyncBufferControl->LaneId, p_Header);
        p_DynamicStatistics->SyncData.ErrorCnt_DataLost++;

        MEASReturn_WriteToBuffer = MEAS_SYNC_JOB_REJECTED_NO_BUFFER;
      }
    }
    else
    {
      // Set checkpoint + debug value + RTA marker because freeze length exceeds buffer size
      MTSI_StatsSetCheckpoint((uint8)MTSI_CHKPT_ID_FUNC_WRITE_TO_BUFFER, (uint8)MTSI_CHKPT_ERR_ID_1, p_Header);
      p_DynamicStatistics->SyncData.ErrorCnt_DataLost++;

      MEASReturn_WriteToBuffer = MEAS_SYNC_JOB_REJECTED_FULL_BUFFER;
    }
  }
  else
  {
    // Set checkpoint because of invalid core id
    MTSI_StatsSetCheckpoint((uint8)MTSI_CHKPT_ID_FUNC_WRITE_TO_BUFFER, (uint8)MTSI_CHKPT_ERR_ID_0, p_Header);

    MEASReturn_WriteToBuffer = MEAS_SYNC_JOB_INVALID_CORE_ID;
  }

  return MEASReturn_WriteToBuffer;
}


static uint32 GetBufferSize(const uint8 CoreId)
{
  // Local variables
  uint32 BufferSize = 0u;
      
  // Retrieve buffer size of specified core
  BufferSize = MainControl[CoreId].p_SyncBufferControl->p_ToggleBuffers[0]->Size;
  
  return BufferSize;
}


static t_ToggleBuffer * GetNextToggleBuffer(const uint8 CoreId)
{
  t_ToggleBuffer* p_ToggleBuffer = NULL;
  uint8 ui8_index;

  // Check validity of core id
  if( (uint8)CFG_MTSI_NUMBER_OF_CORES > CoreId )
  {
    // Retrieve sync buffer control of specified core
    t_SyncBufferControl const* p_SyncBuffer = MainControl[CoreId].p_SyncBufferControl;

    // Increment toggle buffer write index
    ui8_index = (p_SyncBuffer->WriteIndex + (uint8)0x01) % (uint8)CFG_MTSI_NUMBER_OF_TOGGLE_BUFFERS;
    p_ToggleBuffer = p_SyncBuffer->p_ToggleBuffers[ui8_index];
  }
  else
  {
    // Nothing needs to be done
  }

  return p_ToggleBuffer;
}


static t_ToggleBuffer * GetToggleBuffer(const uint8 CoreId, const uint32 DataLength)
{
  // Local variables
  t_ToggleBuffer* p_ToggleBuffer      = NULL;
  t_ToggleBuffer* p_NextToggleBuffer  = NULL;

  /* Retrieve related buffer */
  t_SyncBufferControl * const p_SyncBuffer   = MainControl[CoreId].p_SyncBufferControl;

  // Retrieve active toggle buffer
  t_ToggleBuffer * const p_ActiveToggleBuffer = GetActiveToggleBuffer(CoreId);

  // Retrieve other toggle buffer
  p_NextToggleBuffer = GetNextToggleBuffer(CoreId);

  // Check validity of buffers
  if ( ( NULL != p_ActiveToggleBuffer ) && ( NULL != p_NextToggleBuffer ) )
  {
    // Retrieve remaining buffer sizes
    uint32 RemainingBufferSize = p_ActiveToggleBuffer->Size - p_ActiveToggleBuffer->Level;
    uint32 RemainingBufferSizeNextBuffer = p_NextToggleBuffer->Size - p_NextToggleBuffer->Level;

    // Following is an algorithm for determining a returnable free buffer
    if ( BUFFER_STATE_FREE == p_ActiveToggleBuffer->State )
    {
      // Check if remaining buffer size is sufficient
      if( RemainingBufferSize >= DataLength )
      {
        // Currently active toggle buffer can be used
        p_ToggleBuffer = p_ActiveToggleBuffer;
      }
      else
      {
        // Allowed state change: FREE --> FULL
        p_ActiveToggleBuffer->State = BUFFER_STATE_FULL;

        // We still have no buffer to return => check if , by any chance, the next buffer is FREE or OVERDUE and return it accordingly
        if ( BUFFER_STATE_FREE == p_NextToggleBuffer->State )
        {
          // In this particular case (one buffer becomes FULL), we have to take care that the read index is on the FULL buffer, not on the next FREE one
          // In case the next buffer is not FREE, then we do not care
          p_SyncBuffer->ReadIndex = p_SyncBuffer->WriteIndex;

          // Check if remaining buffer size is sufficient
          if( RemainingBufferSizeNextBuffer >= DataLength )
          {
            p_ToggleBuffer = p_NextToggleBuffer;

            // Returning the next buffer implies that the write index has to be adapted
            SetNextToggleBufferWriteActive(CoreId);
          }
          else
          {
            // Allowed state change: FREE --> FULL
            // Set the state for the next buffer, in case there is no room there
            p_NextToggleBuffer->State = BUFFER_STATE_FULL;
          }
        }
        else if ( BUFFER_STATE_OVERDUE == p_NextToggleBuffer->State )
        {
          // Check if remaining buffer size is sufficient
          if( RemainingBufferSizeNextBuffer >= DataLength )
          {
            p_ToggleBuffer = p_NextToggleBuffer;

            // Returning the next buffer implies that the write index has to be adapted
            SetNextToggleBufferWriteActive(CoreId);
          }
          else
          {
            // Buffer is overdue so we might sneak some data in, but the data does not fit => NULL will be returned in this case and freeze will be lost
          }
        }
        else
        {
          // No buffer can be returned. NULL will thus be returned and the freeze will be lost
        }
      }
    }
    else if ( BUFFER_STATE_OVERDUE == p_ActiveToggleBuffer->State )
    {
      // Overdue buffer should only be used in extreme cases (only if there is no buffer space left in the other toggle buffer)
      // Thus we will first check if the next buffer is free
      if ( BUFFER_STATE_FREE == p_NextToggleBuffer->State )
      {
        // Check if remaining buffer size is sufficient
        if( RemainingBufferSizeNextBuffer >= DataLength )
        {
          p_ToggleBuffer = p_NextToggleBuffer;

          // Returning the next buffer implies that the write index has to be adapted
          SetNextToggleBufferWriteActive(CoreId);
        }
        else
        {
          p_NextToggleBuffer->State = BUFFER_STATE_FULL;
          // Next buffer is not free, we shall write here. But first we check if there is space left in the buffer (this is always mandatory)
          if( p_ActiveToggleBuffer->Size - p_ActiveToggleBuffer->Level >= DataLength )
          {
            // Currently active toggle buffer can be used, even if it is OVERDUE (we can still "sneak" some data insisde)
            p_ToggleBuffer = p_ActiveToggleBuffer;
          }
          else
          {
            // No buffer can be returned. NULL will thus be returned and the freeze will be lost
          }
        }
      }
      else
      {
        // Next buffer is not free, we shall write here. But first we check if there is space left in the buffer (this is always mandatory)
        if( RemainingBufferSize >= DataLength )
        {
          // Currently active toggle buffer can be used, even if it is OVERDUE (we can still "sneak" some data insisde)
          p_ToggleBuffer = p_ActiveToggleBuffer;
        }
        else
        {
          // No buffer can be returned. NULL will thus be returned and the freeze will be lost
        }
      }
    }
    else // In case the buffer is FULL or TRANSMISSION_PENDING or TRANSMISSION_REJECTED, simply check if there is room in the next buffer (if it is FREE or OVERDUE)
    {
      if ( ( BUFFER_STATE_FREE == p_NextToggleBuffer->State ) || ( BUFFER_STATE_OVERDUE == p_NextToggleBuffer->State ) )
      {
        // Of course, always check if the size is sufficient if we want to write to the buffer
        if( RemainingBufferSizeNextBuffer >= DataLength )
        {
          p_ToggleBuffer = p_NextToggleBuffer;

          // Returning the next buffer implies that the write index has to be adapted
          SetNextToggleBufferWriteActive(CoreId);
        }
        else
        {
          // No buffer can be returned. NULL will thus be returned and the freeze will be lost
        }
      }
      else
      {
        // Nothing needs to be done. All buffers are occupied, thus NULL will be returned and freeze will be missed.
      }
    }
  }
  else
  {
    // Nothing needs to be done
  }

  return p_ToggleBuffer;
}


static t_ToggleBuffer * GetActiveToggleBuffer(const uint8 CoreId)
{
  // Local variables
  t_ToggleBuffer* p_ActiveToggleBuffer = NULL;

  // Retrieve sync buffer control of specified core
  t_SyncBufferControl const* p_SyncBuffer = MainControl[CoreId].p_SyncBufferControl;
  
  // Retrieve active toggle buffer of specified core
  p_ActiveToggleBuffer = p_SyncBuffer->p_ToggleBuffers[p_SyncBuffer->WriteIndex];

  return p_ActiveToggleBuffer;
}


static void SetNextToggleBufferReadActive(const uint8 CoreId)
{
  // Retrieve sync buffer control of specified core
  t_SyncBufferControl *p_SyncBuffer = MainControl[CoreId].p_SyncBufferControl;

  // Just to be safe, if the current buffer state is OVEDUE (high priority) or FULL (must be sent immediately), do not change ReadIndex
  if ( (BUFFER_STATE_OVERDUE  == p_SyncBuffer->p_ToggleBuffers[p_SyncBuffer->ReadIndex]->State) ||
       (BUFFER_STATE_FULL     == p_SyncBuffer->p_ToggleBuffers[p_SyncBuffer->ReadIndex]->State) )
  {
    // Do nothing
  }
  else
  {
    // Simply increment toggle buffer ReadIndex
    p_SyncBuffer->ReadIndex = (p_SyncBuffer->ReadIndex + (uint8)0x01) % (uint8)CFG_MTSI_NUMBER_OF_TOGGLE_BUFFERS;
  }

  /* PRQA S 0314 1 *//* Cast from a pointer to object type to a pointer to void. Needed due to the generic defined interface. */
  MTSI_PalFlushCache((const void *) p_SyncBuffer, (uint32) sizeof(t_SyncBufferControl));
}


static void SetNextToggleBufferWriteActive(const uint8 CoreId)
{
  // Retrieve sync buffer control of specified core
  t_SyncBufferControl *p_SyncBuffer = MainControl[CoreId].p_SyncBufferControl;

  // Increment toggle buffer write index
  p_SyncBuffer->WriteIndex = (p_SyncBuffer->WriteIndex + (uint8)0x01) % (uint8)CFG_MTSI_NUMBER_OF_TOGGLE_BUFFERS;

  /* PRQA S 0314 1 *//* Cast from a pointer to object type to a pointer to void. Needed due to the generic defined interface. */
  MTSI_PalFlushCache((const void *) p_SyncBuffer, (uint32) sizeof(t_SyncBufferControl));
}


static void CheckSyncBufferTransmissionStatus(void)
{
  // Index
  uint8 CoreIndex = 0u;
  uint8 ToggleIndex = 0u;
  boolean OverdueCheck;
  
  // Check sync buffers of all cores 
  /* PRQA S 2877 1 */ /* For loop required because it is possible that module has to support more than one core. */
  for(CoreIndex = 0u; (uint8)CFG_MTSI_NUMBER_OF_CORES > CoreIndex; CoreIndex++)
  {
	//Enter Exclusive Area
    (void)MTSI_PalEnterExclusiveArea();
  
    // Only if all buffers are free, the active buffer may be set to overdue.
    // Thus transmission if forced regularly, even if buffer is not full. And the other buffers remain free to receive new data.
    OverdueCheck = b_TRUE;

    for(ToggleIndex = 0u; (uint8)CFG_MTSI_NUMBER_OF_TOGGLE_BUFFERS > ToggleIndex; ToggleIndex++)
    {
      if (BUFFER_STATE_FREE != MainControl[CoreIndex].p_SyncBufferControl->p_ToggleBuffers[ToggleIndex]->State)
      {
        OverdueCheck = b_FALSE;
      }
      else
      {
        // Do nothing
      }
    }
  
    if( b_TRUE == OverdueCheck )
    {
      // Retrieve currently active toggle buffer
      t_ToggleBuffer * const p_ToggleBuffer = GetActiveToggleBuffer(CoreIndex);

      // Check validity of toggle buffer
      if( NULL != p_ToggleBuffer )
      {
        // Check if data is stored within this toggle buffer
        if( 0x00uL < p_ToggleBuffer->Level )
        {
          // Change state of this toggle buffer
          p_ToggleBuffer->State = BUFFER_STATE_OVERDUE;

          if (BUFFER_STATE_OVERDUE  == MainControl[CoreIndex].p_SyncBufferControl->p_ToggleBuffers[0U]->State)
          {
            MainControl[CoreIndex].p_SyncBufferControl->ReadIndex = 0U;
          }
          else if (BUFFER_STATE_OVERDUE  == MainControl[CoreIndex].p_SyncBufferControl->p_ToggleBuffers[1U]->State)
          {
            MainControl[CoreIndex].p_SyncBufferControl->ReadIndex = 1U;
          }
          else
          {
            // Do nothing
          }

          /* PRQA S 0314 1 *//* Cast from a pointer to object type to a pointer to void. Needed due to the generic defined interface. */
          MTSI_PalFlushCache((const void *) p_ToggleBuffer, (uint32) sizeof(t_ToggleBuffer));
        }
        else
        {
          // Nothing needs to be done
        }
      }
      else
      {
        // Nothing needs to be done
      }
    }
    else
    {
      // Nothing needs to be done
    }

    //Exit Exclusive Area
    MTSI_PalExitExclusiveArea();
  }
}


static MEASReturn_t WriteToQueue(const uint8 LaneId, MTSI_t_Header * const p_Header, void const * const p_Data, const MTSI_t_Callback p_Callback)
{
  MEASReturn_t MEASReturn_WriteToQueue = MEAS_OK;
  uint16 ui16_TailOld = 0u;

  // Check validity of input parameters
  if( (uint8)CFG_MTSI_NUMBER_OF_LANES > LaneId )
  {
    // Retrieve core id from HAL
    const uint8 CoreId = MTSI_PalGetCoreId();
  
    // Check validity of core id
    if( (uint8)CFG_MTSI_NUMBER_OF_CORES > CoreId )
    {
      // Retrieve appropriate queue
      t_AsyncQueue * const p_AsyncQueue = MainControl[CoreId].p_AsyncQueueControl->p_AsyncQueues[LaneId];

      // Retrieve the dynamic statistics structure
      MTSI_t_DynamicStatistics * p_DynamicStatistics = MTSI_StatsGetDynamicStatistics(CoreId, LaneId);
  
      // Ensure that queue size is not 0
      if( (uint16)0x00 != p_AsyncQueue->Size )
      {
        // Check status of queue
        if( p_AsyncQueue->Head != ((p_AsyncQueue->Tail + (uint16)0x01) % p_AsyncQueue->Size) )
        {
          // Adapt data pointer and payload length depending on byte alignment
          void const * p_AlignedData = p_Data;

          //Do not Adjust the job alignment for the VersionVerification package. The MeasApp is expecting it to be
          //28 bytes long but due to the size alignment done @8bytes, it is increased to 32bytes, which causes errors.
          //Not the most elegant solution, and not a generic one, but for now no alternative exists.
          if ( p_Header->VirtualAddress != MTSI_VERSION_INFO_PACKET_VIRT_ADDR)
          {
            AdjustJobAlignment(p_Header, &p_AlignedData);
          }
  
          // Store job in queue, header is always stored in big-endian
          /* PRQA S 491 7 */ /* Array subscription of pointer required because of generic module structure. */
          #if( (defined CPU_BYTE_ORDER) && (LOW_BYTE_FIRST == CPU_BYTE_ORDER) )
          p_AsyncQueue->p_Queue[p_AsyncQueue->Tail].Header     = MTSI_PalConvertHeaderEndianness(p_Header);
          #else
          p_AsyncQueue->p_Queue[p_AsyncQueue->Tail].Header     = *p_Header;
          #endif
          p_AsyncQueue->p_Queue[p_AsyncQueue->Tail].p_Data     = p_AlignedData;
          p_AsyncQueue->p_Queue[p_AsyncQueue->Tail].p_Callback = p_Callback;

          ui16_TailOld = p_AsyncQueue->Tail;

          // Adapt queue tail
          p_AsyncQueue->Tail = (p_AsyncQueue->Tail + (uint16)0x01) % p_AsyncQueue->Size;

          /* PRQA S 0491,314 3 *//* Array subscripting applied to an object of pointer type & Cast from a pointer to object type to a pointer to void.
           * Needed due to the generic defined interface & asynch queue structure. */
          MTSI_PalFlushCache((const void *) &p_AsyncQueue->p_Queue[ui16_TailOld], (uint32) sizeof(t_AsyncJob));
          MTSI_PalFlushCache((const void *) p_AsyncQueue, (uint32) sizeof(t_AsyncQueue));

          /* cacheFlush the data to be freezed out. */
          MTSI_PalFlushCache((const void *) p_AlignedData, p_Header->CtrlFieldAndPayloadLength & MTSI_PAYLOAD_LENGTH_BIT_MASK );

          MEASReturn_WriteToQueue = MEAS_ASYNC_JOB_ACCEPTED;

          p_DynamicStatistics->AsyncJobs.CurrentValue++;
        }
        else
        {
#         if(MTSIADAPTER_DEBUG_ENABLE == STD_ON)
          debug_Taskid_index[CoreId] = ((debug_Taskid_index[CoreId] + 1) % 5);
          debug_loss_TaskId[CoreId][debug_Taskid_index[CoreId]] = p_Header->TaskIdentifier;
#         endif
          // Set checkpoint + debug value + RTA marker because queue is full
          MTSI_StatsSetCheckpoint((uint8)MTSI_CHKPT_ID_ASYNC_JOB_REJECTED, LaneId, p_Header);
          p_DynamicStatistics->AsyncJobs.ErrorCnt_DataLost++;

          MEASReturn_WriteToQueue = MEAS_ASYNC_JOB_REJECTED_QUEUE_FULL;
        }
      }
      else
      {
        // Set checkpoint + debug value + RTA marker because size of queue is 0 */
        MTSI_StatsSetCheckpoint((uint8)MTSI_CHKPT_ID_FUNC_WRITE_TO_QUEUE, (uint8)MTSI_CHKPT_ERR_ID_2, p_Header);
        p_DynamicStatistics->AsyncJobs.ErrorCnt_DataLost++;

        MEASReturn_WriteToQueue = MEAS_ASYNC_JOB_REJECTED_QUEUE_ZERO;
      }
    }
    else
    {
      // Set checkpoint because of invalid core id
      MTSI_StatsSetCheckpoint((uint8)MTSI_CHKPT_ID_FUNC_WRITE_TO_QUEUE, (uint8)MTSI_CHKPT_ERR_ID_1, p_Header);

      MEASReturn_WriteToQueue = MEAS_ASYNC_JOB_INVALID_CORE_ID;
    }
  }
  else
  {
    // Set checkpoint because of invalid input parameters
    MTSI_StatsSetCheckpoint((uint8)MTSI_CHKPT_ID_FUNC_WRITE_TO_QUEUE, (uint8)MTSI_CHKPT_ERR_ID_0, p_Header);

    MEASReturn_WriteToQueue = MEAS_ASYNC_JOB_INVALID_INPUT_PARAM;
  }

  return MEASReturn_WriteToQueue;
}

  /*======================================================================================================================*/
  static void TriggerGroupTransmission(void)
  {
    /* Local variables */
    uint8 LaneIndex = 0u;
    uint8 CoreIndex = 0u;
    boolean TransmissionTriggered = b_FALSE;
    t_MTSi_Std_ReturnType TransmissionStatus = MTSI_E_NO_REQUEST;

    /* Check if initialization is done */
    if (MODULE_INITIALIZED == ModuleState)
    {
      /* Retrieve id of currently active core */
      const uint8 CoreId = MTSI_PalGetCoreId();

      /* Trigger transmission only in case the master core (core 3) is active */
      if (CFG_MTSI_MASTER_CORE == CoreId)
      {
        /* Enter ExclusiveArea */
        (void)MTSI_PalEnterExclusiveArea();

        /* Trigger all lanes */
        /* PRQA S 2877 1 */ /* For loop required because it is possible that module has to support more than one lane. */
        for (LaneIndex = 0u; (uint8)CFG_MTSI_NUMBER_OF_LANES > LaneIndex; LaneIndex++)
        {
          /* Check if lane is idle */
          if (LANE_STATE_IDLE == LaneState[LaneIndex])
          {
            LaneTriggerStatus[LaneIndex] = MTSI_E_NO_REQUEST;

            /* Lane is Idle. Start filling the PAL transfer queue. */

            CoreIndex = 0u;
            /* Go through cores to get next job to be sent. We still consider the Lane as IDLE, since the actual transfer is not triggered yet.
             * Note! There are no actual transmissions triggered here. This is done only in the MTSI_PalTriggerTransmission,
             * if there are any jobs available in the PAL queue after parsing of Priority/Async Queues and the SyncBuffers. */
            /* PRQA S 2877 1 */ /* For loop required because it is possible that the module has to support more than one core. */
            while ((uint8)CFG_MTSI_NUMBER_OF_CORES > CoreIndex)
            {
              /* Trigger transmission of sync buffer */
              TransmissionStatus = TriggerSyncBufferGroupTransmission(CoreIndex, LaneIndex);

              if ((TransmissionStatus == MTSI_E_OK) || (TransmissionStatus == MTSI_E_TRIG_REQUEST))
              {
                /* If any jobs were added successfully (MTSI_E_OK) or the PAL transmission queue is already
                 * full (MTSI_E_TRIG_REQUEST), trigger a transmission request. */
                TransmissionTriggered = b_TRUE;

                /* Signal in the Multiplexer that the SyncJob for Core "CoreIndex" has been marked for transmission. */
                Multiplexer[LaneIndex] |= (uint16)(MTSI_SYNCJOB_MARK_INDICATOR << (CoreIndex * MTSI_JOB_NUM_INDICATORS));
              }

              /* Low level queue full. Make sure we trigger another queue filling and batch transmission. */
              if (TransmissionStatus == MTSI_E_TRIG_REQUEST)
              {
                LaneTriggerStatus[LaneIndex] = MTSI_E_TRIG_REQUEST;
              }

              /* Increment core index */
              CoreIndex++;
            }

            CoreIndex = 0u;
            /* Go through cores to get next job to be sent. Note that we still consider the Lane as IDLE, since the actual transfer is not triggered yet.
             * Note! There are no actual transmissions triggered here. This is done only in the MTSI_PalTriggerTransmission,
             * if there are any jobs available in the PAL queue after parsing of Priority/Async Queues and the SyncBuffers. */
            /* PRQA S 2877 1 */ /* For loop required because it is possible that module has to support more than one core. */
            while ((uint8)CFG_MTSI_NUMBER_OF_CORES > CoreIndex)
            {
              /* Trigger transmission of the AsyncQueue in grouped mode, eg for project where several async jobs
               * can be handled in one burst by DMA. (eg DMA chaining is supported). */
              TransmissionStatus = TriggerAsyncQueueGroupTransmission(CoreIndex, LaneIndex);

              if ((TransmissionStatus == MTSI_E_OK) || (TransmissionStatus == MTSI_E_TRIG_REQUEST))
              {
                /* If any jobs were added successfully (MTSI_E_OK) or the PAL transmission queue is already
                 * full (MTSI_E_TRIG_REQUEST), trigger a transmission request. */
                TransmissionTriggered = b_TRUE;

                /* Signal in the Multiplexer that jobs from the AsyncQueue for Core "CoreIndex" are marked for transmission. */
                Multiplexer[LaneIndex] |= (uint16)(MTSI_ASYNCJOB_MARK_INDICATOR << (CoreIndex * MTSI_JOB_NUM_INDICATORS));
              }

              /* Low level queue full. Make sure we trigger another queue filling and batch transmission. */
              if (TransmissionStatus == MTSI_E_TRIG_REQUEST)
              {
                LaneTriggerStatus[LaneIndex] = MTSI_E_TRIG_REQUEST;
              }
              /* Increment core index */
              CoreIndex++;
            }

            if (b_TRUE == TransmissionTriggered)
            {
              /* Trigger the actual transmission, if there were any jobs queued so far. */
              TransmissionStatus = MTSI_PalTriggerTransmission(LaneIndex);

              if (TransmissionStatus != MTSI_E_OK)
              {
                /* Queuing the data was successful, but the transmission could not be triggered.
                 * Need to go back to the pre-queuing state*/
                ResetGroupTrasmissionContext(LaneIndex);
              }
              else
              {
                /* Transmission triggered successfully. */
              }
            }
            else
            {
              /* Nothing to transmit */
            }
          }
          else
          {
            /* A transmission is triggered/intended for the current Lane, but the lane state is not IDLE, meaning a transmission is already ongoing.
             * Set the Lane Trigger Status to MTSI_E_TRIG_REQUEST, so a new Transmission is initiated in the next TransmissionDone callback. */
            LaneTriggerStatus[LaneIndex] = MTSI_E_TRIG_REQUEST;
          }
        }

        /* Exit the ExclusiveArea */
        MTSI_PalExitExclusiveArea();
      }
      else
      {
        /* Set event on the master core (core 0) */
        MTSI_PalSetTriggerTransmissionEvent();
      }
    }
    else
    {
      /* Set checkpoint because of missing initialization */
      MTSI_StatsSetCheckpoint((uint8)MTSI_CHKPT_ID_FUNC_TRIGGER_TRANSMISSION, (uint8)MTSI_CHKPT_ERR_ID_0, NULL);
    }
  }

  static void ResetGroupTrasmissionContext(const uint8 LaneId)
  {
    uint8 CoreIndex = 0u;

    LaneTriggerStatus[LaneId] = MTSI_E_TRIG_REQUEST;
    Multiplexer[LaneId] = 0u;            /* reset multiplexer        */
    LaneState[LaneId] = LANE_STATE_IDLE; /* reset LaneState          */

    /* PRQA S 2877 1 */ /* For loop required because it is possible that the module has to support more than one core. */
    while ((uint8)CFG_MTSI_NUMBER_OF_CORES > CoreIndex)
    {
      /* Retrieve sync buffer control */
      t_SyncBufferControl const *p_SyncBuffer = MainControl[CoreIndex].p_SyncBufferControl;

      if (LaneId == p_SyncBuffer->LaneId)
      {
        /* Retrieve current toggle buffer */
        t_ToggleBuffer *const p_ToggleBuffer = p_SyncBuffer->p_ToggleBuffers[p_SyncBuffer->ReadIndex];
        if (p_ToggleBuffer->State == BUFFER_STATE_TRANSMISSION_PENDING)
        {
          /* Change back the ToogleBuffer state, to ensure it is sent next time. */
          p_ToggleBuffer->State = BUFFER_STATE_TRANSMISSION_REJECTED;
        }
      }

      CoreIndex++; /* Increment core index */
    }

    /* For Async queue handling, the .Reference is also modified, but no need to reset it here.
     * It is reset back to the .Head in the next iteration anyway. */
  }

  static t_MTSi_Std_ReturnType TriggerSyncBufferGroupTransmission(const uint8 CoreId, const uint8 LaneId)
  {
    /* Local variables */
    t_MTSi_Std_ReturnType TransmissionStatus = MTSI_E_NOK; /* Status of transmission */

    /* Check validity of input parameters */
    /* Retrieve sync buffer control. validity of input parameters is checked in the calling function. */
    /* Retrieve sync buffer control */
    t_SyncBufferControl const *p_SyncBuffer = MainControl[CoreId].p_SyncBufferControl;

    /* Check if buffer is assigned to be sent on this lane */
    if (LaneId == p_SyncBuffer->LaneId)
    {
      /* Retrieve current toggle buffer */
      t_ToggleBuffer *const p_ToggleBuffer = p_SyncBuffer->p_ToggleBuffers[p_SyncBuffer->ReadIndex];

      /* Check if buffer is full, overdue or has been rejected by the PAL last time */
      if ((p_ToggleBuffer->State == BUFFER_STATE_FULL) ||
          (p_ToggleBuffer->State == BUFFER_STATE_OVERDUE) ||
          (p_ToggleBuffer->State == BUFFER_STATE_TRANSMISSION_REJECTED))
      {
        /* Send sync buffer */
        /* PRQA S 314 1 */ /* Cast of p_Buffer to void-pointer is required because of predefined interface. */
        TransmissionStatus = MTSI_PalQueueSyncBuffer(LaneId, (void *)p_ToggleBuffer->p_Buffer, p_ToggleBuffer->Level);

        /* Check if job was sent successfully */
        if ((t_MTSi_Std_ReturnType)MTSI_E_NOK != TransmissionStatus)
        {
          // Retrieve dynamic statistics
          MTSI_t_DynamicStatistics *const p_DynamicStatistics = MTSI_StatsGetDynamicStatistics(CoreId, LaneId);

          // Update statistics data
          p_DynamicStatistics->SyncBufferUsage.CurrentValue = p_ToggleBuffer->Level;

          /* Change state of lane */
          LaneState[LaneId] |= LANE_STATE_SYNC_BUFFER_TRANSMISSION;

          /* Change state of buffer */
          p_ToggleBuffer->State = BUFFER_STATE_TRANSMISSION_PENDING;
        }
        else
        {
          /* Change state of buffer. It's not the actual transmission that is rejected, but rather the MTSi Pal "queuing" of the sync job
           * (the transmission is triggered separately at the end of TriggerGropuTransmission). But we can use this state for further processing. */
          p_ToggleBuffer->State = BUFFER_STATE_TRANSMISSION_REJECTED;

          /* Set checkpoint regarding accepted transmission */
          MTSI_StatsSetCheckpoint((uint8)MTSI_CHKPT_ID_SYNC_BUFFER_TRANSMISSION_REJECTED_BY_PAL, LaneId, NULL);
        }
      }
      else
      {
        /* The SyncBuffes from the selected CoreID is associated with the selected LaneID, but there is no data to transmit.
         * Inform the TriggerGroupTransmission that there are no transfer requests. */
        TransmissionStatus = MTSI_E_NO_REQUEST;
      }
    }
    else
    {
      /* The SyncBuffer from the selected CoreID is NOT associated with the selected LaneID. */
      TransmissionStatus = MTSI_E_NO_REQUEST;
    }

    return (TransmissionStatus);
  }

  static t_MTSi_Std_ReturnType TriggerAsyncQueueGroupTransmission(const uint8 CoreId, const uint8 LaneId)
  {
    /* Local variables */
    t_MTSi_Std_ReturnType TransmissionStatus = MTSI_E_NOK; /* Status of transmission */
    t_AsyncJob const *p_AsyncJob = NULL;

    /* Retrieve priority queue. CoreID / LaneID validity is handled in the calling function:
     * "for" loop iterates until max number of Cores (CFG_MTSI_NUMBER_OF_CORES) and Lanes (CFG_MTSI_NUMBER_OF_LANES)  */
    /* Retrieve async queue */
    t_AsyncQueue *const p_AsyncQueue = MainControl[CoreId].p_AsyncQueueControl->p_AsyncQueues[LaneId];

    /* Check if any async jobs to be sent are available (hereby it is implicitly checked if queue is available) */
    if (p_AsyncQueue->Head != p_AsyncQueue->Tail)
    {
      /* Set the Reference to the Head value to begin with. The Reference shall be incremented as we go through
       * the Async jobs, while the Head remains untouched. (should change only in the Finalize... operation) */
      p_AsyncQueue->Reference = p_AsyncQueue->Head;

      /* One by one, pass the async jobs to the PAL level, either until
       * - there are none left to process (Head reached the Tail) or
       * - the maximum number of jobs that can be processed in one batch was reached. ( MTSi PAL will return MTSI_E_TRIG_REQUEST ) or
       * - a error occured at the PAL level ( MTSi PAL will return MTSI_E_NOK ) */
      do
      {
        /* Retrieve job to be sent within the current iteration. */
        /* PRQA S 491 1 */ /* Array subscription of pointer required because of generic module structure. */
        p_AsyncJob = &p_AsyncQueue->p_Queue[p_AsyncQueue->Reference];

        /* Send async job to PAL */
        TransmissionStatus = MTSI_PalQueueAsyncJob(LaneId, &p_AsyncJob->Header, p_AsyncJob->p_Data);

        if ((t_MTSi_Std_ReturnType)MTSI_E_OK == TransmissionStatus)
        {
          p_AsyncQueue->Reference = (p_AsyncQueue->Reference + (uint16)0x01) % p_AsyncQueue->Size;
        }
        else
        {
          /* no action */
        }

      } while ((p_AsyncQueue->Reference != p_AsyncQueue->Tail) &&
               ((t_MTSi_Std_ReturnType)MTSI_E_OK == TransmissionStatus));

      /* Check if job was sent successfully */
      if ((t_MTSi_Std_ReturnType)MTSI_E_NOK != TransmissionStatus)
      {
        /* Change state of lane. should not be a problem to keep the ASYNC_QUEUE state, as it is not possible to have
         * in parallel both handlling via simple AsyncQueue and batch AsyncQueue transmissions. */
        LaneState[LaneId] |= LANE_STATE_ASYNC_QUEUE_TRANSMISSION;
      }
      else
      {
        /* Set checkpoint regarding rejected transmission */
        MTSI_StatsSetCheckpoint((uint8)MTSI_CHKPT_ID_ASYNC_QUEUE_TRANSMISSION_REJECTED_BY_PAL, LaneId, &p_AsyncJob->Header);
      }
    }
    else
    {
      /* Inform the TriggerGroupTransmission that there are no transfer requests. */
      TransmissionStatus = MTSI_E_NO_REQUEST;
    }

    return (TransmissionStatus);
  }

  static void TransmissionGroupDoneCallback(const uint8 LaneId)
  {
    uint8 ui8_CoreIndex = 0u;

    MTSI_StatsSetEvent(MTSI_EVENT_TYPE_START, ((uint8)MTSI_CHKPT_ID_FUNC_TRANSMISSION_DONE_CALLBACK), 0u);

    /* Check validity of lane id */
    if ((uint8)CFG_MTSI_NUMBER_OF_LANES > LaneId)
    {
      /* Check if lane is already initialized */
      if (LANE_STATE_INIT != LaneState[LaneId])
      {
        /* Retrieve id of core that is currently handled at this lane */
        const uint16 GroupedCoreId = Multiplexer[LaneId];

        /* Store incoming lane state */
        const t_LaneState OldLaneState = LaneState[LaneId];

        /* Change state of lane */
        LaneState[LaneId] = LANE_STATE_IDLE;

        if ((OldLaneState & LANE_STATE_SYNC_BUFFER_TRANSMISSION) == LANE_STATE_SYNC_BUFFER_TRANSMISSION)
        {
          /* It may be that the SyncBuffers of several cores are allocated to a Lane, so parse through all the available cores. */
          /* PRQA S 2877 1 */ /* "This loop will never be executed more than once." */ /* Loop required for MTSI generic handling: number of cores/lanes may be > 1 */
          for (ui8_CoreIndex = 0u; ui8_CoreIndex < CFG_MTSI_NUMBER_OF_CORES; ui8_CoreIndex++)
          {
            if ((GroupedCoreId & (uint16)(MTSI_SYNCJOB_MARK_INDICATOR << (ui8_CoreIndex * MTSI_JOB_NUM_INDICATORS))) != 0u)
            {
              FinalizeSyncBufferTransmission(ui8_CoreIndex);
            }
          }
        }

        if ((OldLaneState & LANE_STATE_ASYNC_QUEUE_TRANSMISSION) == LANE_STATE_ASYNC_QUEUE_TRANSMISSION)
        {
          /* It may be that the AsyncQueues of several cores are allocated to a Lane, so parse through all the available cores. */
          /* PRQA S 2877 1 */ /* "This loop will never be executed more than once." */ /* Loop required for MTSI generic handling: number of cores/lanes may be > 1 */
          for (ui8_CoreIndex = 0u; ui8_CoreIndex < CFG_MTSI_NUMBER_OF_CORES; ui8_CoreIndex++)
          {
            if ((GroupedCoreId & (uint16)(MTSI_ASYNCJOB_MARK_INDICATOR << (ui8_CoreIndex * MTSI_JOB_NUM_INDICATORS))) != 0u)
            {
              FinalizeAsyncGroupQueueTransmission(ui8_CoreIndex, LaneId);
            }
          }
        }

        if ((OldLaneState & LANE_STATE_TRANSMISSION_WITH_MTA_FRAME_REQUEST) == LANE_STATE_TRANSMISSION_WITH_MTA_FRAME_REQUEST)
        {
          StartMTAFrame(LaneId);
        }

        /* reset multiplexer */
        Multiplexer[LaneId] = 0u;

        /* Trigger transmission of next job only if there are still jobs left from the previous Trigger. (previous task)
         * Note that there may be additional jobs triggered between the MTSi_MainFunction trigger and the DMA callback,
         * but these will be processed in the next MTSi MainFunction. */
        if (LaneTriggerStatus[LaneId] == MTSI_E_TRIG_REQUEST)
        {
          TriggerGroupTransmission();
        }
      }
      else
      {
        /* Set checkpoint because lane id is out of range */
        MTSI_StatsSetCheckpoint((uint8)MTSI_CHKPT_ID_FUNC_TRANSMISSION_DONE_CALLBACK, (uint8)MTSI_CHKPT_ERR_ID_1, NULL);
      }
    }
    else
    {
      /* Set checkpoint because lane id is out of range */
      MTSI_StatsSetCheckpoint((uint8)MTSI_CHKPT_ID_FUNC_TRANSMISSION_DONE_CALLBACK, (uint8)MTSI_CHKPT_ERR_ID_0, NULL);
    }

    MTSI_StatsSetEvent(MTSI_EVENT_TYPE_END, ((uint8)MTSI_CHKPT_ID_FUNC_TRANSMISSION_DONE_CALLBACK), 0u);
  }

  static void FinalizeAsyncGroupQueueTransmission(const uint8 CoreId, const uint8 LaneId)
  {
    t_AsyncJob const *p_AsyncJob = NULL;

    /* Retrieve async queue. validity of input parameters is checked in the calling function. */
    t_AsyncQueue *const p_AsyncQueue = MainControl[CoreId].p_AsyncQueueControl->p_AsyncQueues[LaneId];

    /* Check if async queue has really been transmitted */
    if (p_AsyncQueue->Head != p_AsyncQueue->Tail)
    {
      do
      {
        /* Retrieve async job */
        /* PRQA S 491 1 */ /* Array subscription of pointer required because of generic module structure.*/
        p_AsyncJob = &p_AsyncQueue->p_Queue[p_AsyncQueue->Head];

        /* Invoke callback function */
        if (NULL != p_AsyncJob->p_Callback)
        {
          p_AsyncJob->p_Callback();
        }

        /* Adapt queue head */
        p_AsyncQueue->Head = (p_AsyncQueue->Head + (uint16)0x01) % p_AsyncQueue->Size;
      } while (p_AsyncQueue->Head != p_AsyncQueue->Reference);
    }
    else
    {
      /* Set checkpoint because async queue has not been sent */
      MTSI_StatsSetCheckpoint((uint8)MTSI_CHKPT_ID_FUNC_FINALIZE_ASYNC_QUEUE_TRANSMISSION, (uint8)MTSI_CHKPT_ERR_ID_0, NULL);
    }
  }

  static void FinalizeSyncBufferTransmission(const uint8 CoreId)
  {
    /* Retrieve related buffer. validity of input parameters is checked in the calling function. */
    t_SyncBufferControl *const p_SyncBuffer = MainControl[CoreId].p_SyncBufferControl;
    t_ToggleBuffer *p_ToggleBuffer = p_SyncBuffer->p_ToggleBuffers[p_SyncBuffer->ReadIndex];

    // Check if sync buffer has really been transmitted
    if (BUFFER_STATE_TRANSMISSION_PENDING == p_ToggleBuffer->State)
    {
      // Clear toggle buffer
      p_ToggleBuffer->Level = 0u;
      p_ToggleBuffer->State = BUFFER_STATE_FREE;

      // Set transmission info
      p_SyncBuffer->SentWithinMTACycle = b_TRUE;

      // Determine the toggle buffer that has to be read by PAL the next time the transmission is triggered
      SetNextToggleBufferReadActive(CoreId);
    }
    else
    {
      // Set checkpoint because no sync buffer has been sent
      MTSI_StatsSetCheckpoint((uint8)MTSI_CHKPT_ID_FUNC_FINALIZE_SYNC_BUFFER_TRANSMISSION, (uint8)MTSI_CHKPT_ERR_ID_0, NULL);
    }
  }

static void StoreTimeSyncPacket(const uint8 LaneId)
{
  // Local variables
  MTSI_t_FreezeInfo FreezeInfo;
  MTSI_t_Header MTSHeader;

  MEASReturn_t ret_WriteToBuff;
  const uint32 resolution = MTSI_TIME_BASE_RESOLUTION;

  // Set freeze info
  FreezeInfo.VirtualAddress = MTSI_TIME_SYNC_PACKET_VIRT_ADDR;
  FreezeInfo.FunctionId = CFG_MTSI_MTA_FRAME_TASK_BASE_ID;
  FreezeInfo.Length = (uint32)sizeof(t_TimeSyncPacket);
  FreezeInfo.Options = MTSI_OPTION_NONE;

  // Enter exclusive area
  (void)MTSI_PalEnterExclusiveArea();

  // Create MTS header
  MTSI_DriverPrepareHeader(&FreezeInfo, &MTSHeader);
  
  // Adapt task id and counter
  //MTSHeader.TaskIdentifier = CFG_MTSI_MTA_FRAME_TASK_BASE_ID + (uint16)LaneId;

    // Do not overwrite the TaskCounter. The TimeSync package is sent with a TaksID (eg: 130...) for which the TaskCounter
    // is incremented with a different recurrence (eg: every 10ms) compared to the MTA FrameCounter (eg: once per cycle, every 60ms).
    //  This difference may cause MeasApp warnings: "Received package with a newer timestamp but smaller cycle counter then the newest package...

  // Update time sync packet
#if ((defined CPU_BYTE_ORDER) && (LOW_BYTE_FIRST == CPU_BYTE_ORDER))
  TimeSyncPacket.TimeBaseRes = MTSI_PalSwapUINT32(&resolution);
  TimeSyncPacket.FrameStartRef = MTSI_PalSwapUINT32(&(TimestampFrameStart[LaneId]));
#else
TimeSyncPacket.TimeBaseRes = resolution;
TimeSyncPacket.FrameStartRef = TimestampFrameStart[LaneId];
#endif /*( (defined CPU_BYTE_ORDER) && (LOW_BYTE_FIRST == CPU_BYTE_ORDER) ) */

  /* Try to add the TimeSyncPacket to the SyncBuffer. If unsuccessful, use the AsyncQueue */
  /* PRQA S 314 1 */ /* Cast of TimeSyncPacket-address to void-pointer is required because of generic interface of WriteToQueue.*/
  ret_WriteToBuff = MTSI_DriverStoreSyncJob(&MTSHeader, (void *)&TimeSyncPacket, NULL);
  if (ret_WriteToBuff != MEAS_SYNC_JOB_ACCEPTED)
  {
    // Store data in async queue
    /* PRQA S 314 1 */ /* Cast of TimeSyncPacket-address to void-pointer is required because of generic interface of WriteToQueue.*/
    (void)MTSI_DriverStoreAsyncJob(LaneId, &MTSHeader, (void *)&TimeSyncPacket, NULL);
  }

    // Exit exclusive area
    MTSI_PalExitExclusiveArea();
  }

  static void StartMTAFrame(const uint8 LaneId)
  {
    // Check validity of lane id
    if ((uint8)CFG_MTSI_NUMBER_OF_LANES > LaneId)
    {
      // Check if MTA frame is active
      if (MTA_FRAME_ACTIVE == MTAFrameState[LaneId])
      {
        // Finish current MTA frame
        const Std_ReturnType Status = MTSI_PalFinishMTAFrame(LaneId);

        // Check if MTA frame was finished successfully
        if ((Std_ReturnType)E_OK == Status)
        {
          // Update status of MTA frame
          MTAFrameState[LaneId] = MTA_FRAME_INACTIVE;

          // Check if deinitialization of the module has been requested
          if (MODULE_DE_INIT_REQUESTED == ModuleState)
          {
            // Check if any other MTA frame is active
            const boolean MTAFrameActive = IsMTAFrameActive();

            // Finalize deinitialization in case no other MTA frame is active
            if (b_FALSE == MTAFrameActive)
            {
              // Change module state regarding finished deinitialization
              ModuleState = MODULE_DEINITIALIZED;
            }
            else
            {
              // Nothing needs to be done
            }
          }
        }
        else
        {
          // Set checkpoint because MTA frame could not be finished
          MTSI_StatsSetCheckpoint((uint8)MTSI_CHKPT_ID_FUNC_START_MTA_FRAME, (uint8)MTSI_CHKPT_ERR_ID_1, NULL);
        }
      }
      else
      {
        // Nothing needs to be done
      }

      // Only start new MTA frame in case the module is at least preinitialized
      if ((MODULE_INITIALIZED == ModuleState) || (MODULE_PREINITIALIZED == ModuleState))
      {
        // Ensure that no MTA frame is active
        if (MTA_FRAME_INACTIVE == MTAFrameState[LaneId])
        {
          // Start new MTA frame
          const Std_ReturnType Status = MTSI_PalStartMTAFrame(LaneId);

          // Check if MTA frame was started successfully
          if ((Std_ReturnType)E_OK == Status)
          {
            // Get timestamp of MTA frame start
            const uint32 CurrentTimestamp = MTSI_PalGetMtaFrameStart(LaneId);
            const uint8 ui8_MTAFrameCnt = (uint8)MTSI_PalGetMtaFrameCounter(LaneId);

            // Store start timestamp
            TimestampFrameStart[LaneId] = CurrentTimestamp;

            // Update status of MTA frame
            MTAFrameState[LaneId] = MTA_FRAME_ACTIVE;

            // Set RTA event
            MTSI_StatsSetEvent(MTSI_EVENT_TYPE_MARKER, ((uint8)MTA_FRAME_LANE_0 + LaneId), ui8_MTAFrameCnt);

            // Store time sync packet
            StoreTimeSyncPacket(LaneId);

// Store SW version verification packet
#if ((defined CFG_MTSI_ENABLE_VERSION_VERIFICATION) && (TRUE == CFG_MTSI_ENABLE_VERSION_VERIFICATION))
            StoreVersionVerification(LaneId);
#endif

            // Check if lane is just initialized
            if (LANE_STATE_INIT == LaneState[LaneId])
            {
              // Release lane
              LaneState[LaneId] = LANE_STATE_IDLE;
            }
            else
            {
              // no action
            }
          }
          else
          {
            // Set checkpoint because MTA frame could not be started
            MTSI_StatsSetCheckpoint((uint8)MTSI_CHKPT_ID_FUNC_START_MTA_FRAME, (uint8)MTSI_CHKPT_ERR_ID_2, NULL);
          }
        }
        else
        {
          // Nothing needs to be done, checkpoint is already set above
        }
      }
      else
      {
        // Nothing needs to be done
      }
    }
    else
    {
      // Set checkpoint because lane id is out of range
      MTSI_StatsSetCheckpoint((uint8)MTSI_CHKPT_ID_FUNC_START_MTA_FRAME, (uint8)MTSI_CHKPT_ERR_ID_0, NULL);
    }
  }

  static uint8 GetHeaderCtrlField(void)
  {
    // Local variables
    uint8 CtrlField = 0u;

    // Set control bits
    CtrlField |= (uint8)((uint8)CFG_MTSI_HEADER_USE_FUNCTION_ID << MTSI_CTRL_FIELD_FUNCTION_ID_SHIFT);
    CtrlField |= (uint8)((uint8)CFG_MTSI_HEADER_USE_PACKET_COUNTER << MTSI_CTRL_FIELD_PACKET_COUNTER_SHIFT);
    CtrlField |= (uint8)((uint8)CFG_MTSI_HEADER_USE_HIGH_RES_TIMESTAMP << MTSI_CTRL_FIELD_HIGH_RES_TIMESTAMP_SHIFT);
    CtrlField |= (uint8)((uint8)CFG_MTSI_HEADER_USE_ABSOLUTE_TIMESTAMP << MTSI_CTRL_FIELD_ABSOLUTE_TIMESTAMP_SHIFT);
    CtrlField |= (uint8)(((uint8)CFG_MTSI_HEADER_USE_CHECKSUM & (uint8)MTSI_CTRL_FIELD_CHECKSUM_MASK) << MTSI_CTRL_FIELD_CHECKSUM_SHIFT);

    return CtrlField;
  }

  static uint16 GetTaskCounter(const uint16 TaskId)
  {
    // Task counter to be returned
    uint16 ReturnValue = 0u;

    // Task index
    uint8 TaskIndex = (uint8)0x00;
    // debug start
    volatile static uint16 TestTaskId = 0;
    volatile uint8 debug = 0;
    if (TaskId == TestTaskId)
    {
      debug = 1;
    }
    // debug end
    //  Retrieve info about this task
    while ((uint8)CFG_MTSI_MAXIMUM_NUMBER_OF_TASKS > TaskIndex)
    {
      // Retrieve entry of task info table
      /* PRQA S 491 1 */ /* Array subscription of pointer required because of generic handling. */
      t_TaskInfo const *p_TaskInfoEntry = &TaskInfoTable[TaskIndex];

      // Check task info entry
      if (TaskId == p_TaskInfoEntry->TaskIdentifier)
      {
        // Get task info
        ReturnValue = p_TaskInfoEntry->TaskCounter;
        // Force end of loop
        TaskIndex = CFG_MTSI_MAXIMUM_NUMBER_OF_TASKS;
      }
      else
      {
        // Increment task index
        TaskIndex++;
      }
    }

    return ReturnValue;
  }

  static void AdjustJobAlignment(MTSI_t_Header *const p_Header, void const **p_Data)
  {
    // Local variables
    uint32 PointerOffset;
    uint32 LengthOverlap;
    t_AlignmentPointer p_AlignedData;

    // Use union to treat data pointer like a value for pointer adjustment
    // Pointer arithmetic on void pointer is not possible
    p_AlignedData.Pointer = *p_Data;

    // Get number of bytes, by which data pointer shall be shifted to the left for required alignment
    PointerOffset = p_AlignedData.Value % CFG_MTSI_MEAS_FREEZE_BYTE_ALIGNMENT;

    // Reduce data pointer by number of bytes
    p_AlignedData.Value -= PointerOffset;

    // Increase padding bytes by number of bytes to compensate pointer correction
    p_Header->PaddingLength += (uint16)PointerOffset;

    // Update p_Data with adjusted value
    *p_Data = p_AlignedData.Pointer;

    // Get number of bytes, by which length shall be increased to achieve required alignment also for the length
    // Consider additional bytes for pointer offset, which have to be transmitted together with payload
    LengthOverlap = (p_Header->CtrlFieldAndPayloadLength + PointerOffset) % CFG_MTSI_MEAS_FREEZE_BYTE_ALIGNMENT;

    // Correct length of payload
    if (LengthOverlap != 0uL)
    {
      p_Header->CtrlFieldAndPayloadLength += CFG_MTSI_MEAS_FREEZE_BYTE_ALIGNMENT;
      p_Header->CtrlFieldAndPayloadLength -= LengthOverlap;
    }
    else
    {
      // Nothing needs to be done
    }
  }

  static boolean IsMTAFrameActive(void)
  {
    // Local variables
    boolean MTAFrameActive = b_FALSE;
    uint8 LaneIndex = 0u;

    // Check if any MTA frame is currently active
    /* PRQA S 2877 1 */ /* For loop required because it is possible that module has to support more than one lane. */
    for (LaneIndex = 0u; (uint8)CFG_MTSI_NUMBER_OF_LANES > LaneIndex; LaneIndex++)
    {
      // Check if MTA frame of current lane is active
      if (MTA_FRAME_ACTIVE == MTAFrameState[LaneIndex])
      {
        MTAFrameActive = b_TRUE;
      }
      else
      {
        // Nothing needs to be done
      }
    }

    return MTAFrameActive;
  }

#define MTSI_STOP_SEC_CODE_ASIL_B
#include <MTSI_MemMap_Cfg.h>

#ifdef __cplusplus
}
#endif
