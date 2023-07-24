// Copyright (C) Continental AG
// All Rights Reserved
// COMPONENT: MTSI
// VERSION:   $Revision: 1.11 $

#ifndef MTSI_Statistics_H
#define MTSI_Statistics_H

#include <MTSI_Types.h>

#if ( (defined CFG_MTSI_RTA_USAGE_ENABLED) && (CFG_MTSI_RTA_USAGE_ENABLED == TRUE) )
#include <RTA.h>
#endif

///Collection and output of statistical data for analysis

#ifdef __cplusplus
extern "C"
{
#endif

/// @brief    Length of project id at detailed version info
#define MTSI_VERSION_INFO_PROJECT_ID_LENGTH 12

/// @brief    	Detailed SW version from INFOBLOCK
///Appropriate information are retrieved from INFOBLOCK component
///and must be sent within version info packet at the beginning of each MTA frame.
typedef struct
{
	/// @brief	Major version
	uint8 Major;
	/// @brief	Minor version
	uint8 Minor;
	/// @brief	Patch version
	uint8 PatchLevel;
	/// @brief	Selected build type
	uint8 SelectedBuildType;
} MTSI_t_DetailedVersion;


/// @brief    	Detailed date from INFOBLOCK
/// Appropriate information are retrieved from INFOBLOCK component
/// and must be sent within version info packet at the beginning of each MTA frame.
typedef struct
{
	/// @brief	Reserved byte
	uint8 Reserved;
	/// @brief	Year of SW build
	uint8 Year;
	/// @brief	Month of SW build
	uint8 Month;
	/// @brief	Day of SW build
	uint8 Day;
} MTSI_t_DetailedDate;


/// @brief    	Detailed time from INFOBLOCK
/// Appropriate information are retrieved from INFOBLOCK component
/// and must be sent within version info packet at the beginning of each MTA frame.
typedef struct
{
	/// @brief	Reserved byte
	uint8 Reserved;
	/// @brief	Hour of SW build
	uint8 Hour;
	/// @brief	Minute of SW build
	uint8 Minute;
	/// @brief	Second of SW build
	uint8 Second;
} MTSI_t_DetailedTime;


/// @brief    Version info packet of the SW
/// Appropriate information are retrieved from INFOBLOCK component
/// and must be sent at the beginning of each MTA frame.
typedef struct
{
	/// @brief    Padding used to make the VersionVerification packet match the expected MeasApp size. (28bytes)
	uint8 ui8_FrontPadding[4u];
	/// @brief    Detailed version information
	MTSI_t_DetailedVersion Version;
	/// @brief    Detailed date information
	MTSI_t_DetailedDate Date;
	/// @brief    Detailed time information
	MTSI_t_DetailedTime Time;
	/// @brief    Checksum of the mot file
	uint32 Checksum;
	/// @brief    Project ID
	uint8 ProjectId[MTSI_VERSION_INFO_PROJECT_ID_LENGTH];
} MTSI_t_VersionInfoPacket;


/// @brief  enumeration of the local ID's of RunTimeAssessment events. These are used to uniquely indicate the
///         location in the implementation where the Error occurred. (eg function & error condition)
/*PRQA S 0779 ++*//* "Identifier does not differ from other identifier(s) (e.g. '%s') within the specified number of significant characters." */
// Proven in use, not a problem.
typedef enum
{
	MTSI_CHKPT_ID_FUNC_DUMMY,
	MTSI_CHKPT_ID_FUNC_FREEZE_DATA,
	MTSI_CHKPT_ID_FUNC_FREEZE_DATA_ID1,
	MTSI_CHKPT_ID_FUNC_FREEZE_DATA_ID2,
	MTSI_CHKPT_ID_FUNC_PREPARE_HEADER,
	MTSI_CHKPT_ID_FUNC_STORE_SYNC_JOB,
	MTSI_CHKPT_ID_FUNC_STORE_ASYNC_JOB,
	MTSI_CHKPT_ID_FUNC_START_MTA_CYCLE,
	MTSI_CHKPT_ID_FUNC_START_TASK_CYCLE,
	MTSI_CHKPT_ID_FUNC_START_TASK_CYCLE_ID1,
	MTSI_CHKPT_ID_FUNC_START_TASK_CYCLE_ID2,
	MTSI_CHKPT_ID_FUNC_INIT_SYNC_BUFFER,
	MTSI_CHKPT_ID_FUNC_INIT_ASYNC_QUEUE,
	MTSI_CHKPT_ID_FUNC_WRITE_TO_BUFFER,
	MTSI_CHKPT_ID_FUNC_WRITE_TO_BUFFER_ID1,
	MTSI_CHKPT_ID_FUNC_WRITE_TO_BUFFER_ID2,
	MTSI_CHKPT_ID_FUNC_CHECK_SYNC_BUFFER_TRANSMISSION_STATUS,
	MTSI_CHKPT_ID_FUNC_WRITE_TO_QUEUE,
	MTSI_CHKPT_ID_FUNC_WRITE_TO_QUEUE_ID1,
	MTSI_CHKPT_ID_FUNC_WRITE_TO_QUEUE_ID2,
	MTSI_CHKPT_ID_FUNC_WRITE_TO_QUEUE_ID3,
	MTSI_CHKPT_ID_FUNC_TRIGGER_TRANSMISSION,
	MTSI_CHKPT_ID_FUNC_TRIGGER_TRANSMISSION_ID1,
	MTSI_CHKPT_ID_FUNC_TRIGGER_SYNC_BUFFER_TRANSMISSION,
	MTSI_CHKPT_ID_FUNC_TRIGGER_ASYNC_QUEUE_TRANSMISSION,
	MTSI_CHKPT_ID_FUNC_TRANSMISSION_DONE_CALLBACK,
	MTSI_CHKPT_ID_FUNC_TRANSMISSION_DONE_CALLBACK_ID1,
	MTSI_CHKPT_ID_FUNC_TRANSMISSION_DONE_CALLBACK_ID2,
	MTSI_CHKPT_ID_FUNC_FINALIZE_SYNC_BUFFER_TRANSMISSION,
	MTSI_CHKPT_ID_FUNC_FINALIZE_ASYNC_QUEUE_TRANSMISSION,
	MTSI_CHKPT_ID_FUNC_STORE_VERSION_VERIFICATION,
	MTSI_CHKPT_ID_FUNC_STORE_STATIC_STATISTIC_DATA,
	MTSI_CHKPT_ID_FUNC_STORE_STATIC_STATISTIC_DATA_ID1,
	MTSI_CHKPT_ID_FUNC_STORE_STATIC_STATISTIC_DATA_ID2,
	MTSI_CHKPT_ID_FUNC_STORE_DYNAMIC_STATISTIC_DATA,
	MTSI_CHKPT_ID_FUNC_STORE_DYNAMIC_STATISTIC_DATA_ID1,
	MTSI_CHKPT_ID_FUNC_STORE_DYNAMIC_STATISTIC_DATA_ID2,
	MTSI_CHKPT_ID_FUNC_STORE_CHECKPOINTS,
	MTSI_CHKPT_ID_FUNC_STORE_CHECKPOINTS_ID1,
	MTSI_CHKPT_ID_FUNC_STORE_CHECKPOINTS_ID2,
	MTSI_CHKPT_ID_FUNC_START_MTA_FRAME,
	MTSI_CHKPT_ID_FUNC_START_MTA_FRAME_ID1,
	MTSI_CHKPT_ID_FUNC_START_MTA_FRAME_ID2,
	MTSI_CHKPT_ID_FUNC_GET_TASK_COUNTER,
	MTSI_CHKPT_ID_SYNC_JOB_REJECTED,
	MTSI_CHKPT_ID_SYNC_JOB_REJECTED_LANE1,
	MTSI_CHKPT_ID_SYNC_JOB_REJECTED_LANE2,
	MTSI_CHKPT_ID_SYNC_JOB_REJECTED_LANE3,
	MTSI_CHKPT_ID_ASYNC_JOB_REJECTED,
	MTSI_CHKPT_ID_ASYNC_JOB_REJECTED_LANE1,
	MTSI_CHKPT_ID_ASYNC_JOB_REJECTED_LANE2,
	MTSI_CHKPT_ID_ASYNC_JOB_REJECTED_LANE3,
	MTSI_CHKPT_ID_SYNC_BUFFER_TRANSMISSION_REJECTED_BY_PAL,
	MTSI_CHKPT_ID_SYNC_BUFFER_TRANSMISSION_REJECTED_BY_PAL_LANE1,
	MTSI_CHKPT_ID_SYNC_BUFFER_TRANSMISSION_REJECTED_BY_PAL_LANE2,
	MTSI_CHKPT_ID_SYNC_BUFFER_TRANSMISSION_REJECTED_BY_PAL_LANE3,
	MTSI_CHKPT_ID_ASYNC_QUEUE_TRANSMISSION_REJECTED_BY_PAL,
	MTSI_CHKPT_ID_ASYNC_QUEUE_TRANSMISSION_REJECTED_BY_PAL_LANE1,
	MTSI_CHKPT_ID_ASYNC_QUEUE_TRANSMISSION_REJECTED_BY_PAL_LANE2,
	MTSI_CHKPT_ID_ASYNC_QUEUE_TRANSMISSION_REJECTED_BY_PAL_LANE3,
	MTSI_CHKPT_ID_FUNC_CUSTOM_0,
	MTSI_CHKPT_ID_FUNC_CUSTOM_1,
	MTSI_CHKPT_ID_FUNC_CUSTOM_2,
	MTSI_CHKPT_ID_FUNC_CUSTOM_3,
	MTSI_CHKPT_ID_FUNC_CUSTOM_4,
	MTSI_CHKPT_ID_FUNC_CUSTOM_5,
	MTA_FRAME_LANE_0,
	MTA_FRAME_LANE_1,
	MTA_FRAME_LANE_2,
	MTA_FRAME_LANE_3,
	MTSI_STATS_CHKP_STORE_ERR_C0,
	MTSI_STATS_CHKP_STORE_ERR_C1,
	MTSI_STATS_CHKP_STORE_ERR_C2,
	MTSI_STATS_CHKP_STORE_ERR_C3,
	MTSI_STATS_CHKP_STORE_ERR_C4,
	MTSI_MAIN_FUNCTION,
	MTSI_PAL_HW_DATA_TRANSMISSION, /* RTA_XML_GEN_PARAMS: non-interruptible*/
	MTSI_PAL_SW_DATA_TRANSMISSION /* RTA_XML_GEN_PARAMS: non-interruptible*/
}MTSI_t_LocalIDs; /* RTA_LOCAL_ID_FOR_XML_GENERATION */
/*PRQA S 0779 --*/

/// @brief    	Checkpoint function sub IDs
/// This ID is used to separate between different paths within one function.
typedef enum
{
    MTSI_CHKPT_ERR_ID_0 = 0,
    MTSI_CHKPT_ERR_ID_1 = 1,
    MTSI_CHKPT_ERR_ID_2 = 2,
    MTSI_CHKPT_ERR_ID_3 = 3,
    MTSI_CHKPT_ERR_ID_4 = 4
} MTSI_t_CheckpointErrorId;


#if ( (defined CFG_MTSI_RTA_USAGE_ENABLED) && (CFG_MTSI_RTA_USAGE_ENABLED == TRUE) )
 /// @brief    Symbolic constant for event type MARKER
 #define MTSI_EVENT_TYPE_MARKER RTA_EVT_MARKER
 /// @brief    Symbolic constant for event type START
 #define MTSI_EVENT_TYPE_START RTA_EVT_ALGOSTART
 /// @brief    Symbolic constant for event type END
 #define MTSI_EVENT_TYPE_END RTA_EVT_ALGOEND
#else
 /// @brief    Symbolic constant for event type MARKER
 #define MTSI_EVENT_TYPE_MARKER 0u
 /// @brief    Symbolic constant for event type START
 #define MTSI_EVENT_TYPE_START 0u
 /// @brief    Symbolic constant for event type END
 #define MTSI_EVENT_TYPE_END 0u
#endif

/// @brief    	Virtual address for statistic data
/// All virtual addresses, starting from this one,
///are reserved for the statistic data.
#define MTSI_STATISTIC_DATA_VIRT_ADDR 0x80050000uL

/// User explicit entries
/// Operations

/// @brief  Initialize the statistic data (both Statis & Dynamic), as well as the checkpoint structure of MTSI
/// @pre    none
/// @post   none
/// @param[in] MajorVersion 	Major version of module \n
/// @param[in] MinorVersion 	Minor version of module \n
/// @param[in] PatchVersion 	Patch version of module \n
/// @return void
/// @globals none
/// @InOutCorrelation
///   It will initialize the version info packet, static statistic data, dynamic statistic data and MTSI checkpoints and set the error counter to 0.
/// @callsequence
///   @image html MTSI_StatsInit.png Sequence Diagram
/// @testmethod
///  1) @ref TEST_MTSI_StatsInit_1 : Call function MTSI_StatsInit() for coverage.
/// @traceability
///   <a href="doors://rbgs854a:40000/?version=2&prodID=0&view=00000006&urn=urn:telelogic::1-503e822e5ec3651e-O-769-0005ebe0"><strong> MTSI_StatsInit L4 Design Specification</strong></a>
void MTSI_StatsInit(const uint16 MajorVersion, const uint8 MinorVersion, const uint8 PatchVersion);


/// @brief    Store static statistic data
/// @pre      none
/// @post     none
/// @param    none
/// @return   void
/// @InOutCorrelation
///   If the pointer for retrieving static statistics is valid, store the statistic data content for the next MTSi transmission.
///   If the pointer for retrieving static statistics is not valid or the measurement freeze request was rejected, set a error checkpoint.
/// @globals none
/// @callsequence
/// @image html StoreStaticStatistics.png Sequence Diagram
/// @testmethod
///   1) @ref TEST_StoreStaticStatistics_1 : Test functionality when the Static structure is both valid/not valid(NULL) and the structure freeze is both successful/unsuccessful. \n
///   <a href="doors://rbgs854a:40000/?version=2&prodID=0&view=00000006&urn=urn:telelogic::1-503e822e5ec3651e-O-803-0005ebe0"><strong> StoreStaticStatistics L4 Design Specification</strong></a>
void StoreStaticStatistics(void);


/// @brief  Store the configuration settings of MTSI
/// @pre    none
/// @post   none
/// @param[in] Mode Output  mode that has been set at custom module \n
/// @param[in] InstanceNr 	Instance number of ECU that has been set at custom module \n
/// @return void
/// @globals
///   @ref StaticStatistics
/// @InOutCorrelation
///   In the static statistic it will store the output mode of MTSI and the instance number of this ECU.
/// @callsequence
/// @image html MTSI_StatsStoreConfigurationSettings.png Sequence Diagram
/// @testmethod
///  1) @ref TEST_MTSI_StatsStoreConfigurationSettings_1 : Call function MTSI_StatsStoreConfigurationSettings() for coverage.
/// @traceability
///   <a href="doors://rbgs854a:40000/?version=2&prodID=0&view=00000006&urn=urn:telelogic::1-503e822e5ec3651e-O-780-0005ebe0"><strong> MTSI_StatsStoreConfigurationSettings L4 Design Specification</strong></a>
void MTSI_StatsStoreConfigurationSettings(const uint8 Mode, const uint8 InstanceNr);


/// @brief  Store sync buffer configuration at static statistics
/// @pre    none
/// @post   none
/// @param  [in] CoreId		Core that is related to this buffer \n
/// @param  [in] LaneId		Lane on that this buffer is sent \n
/// @param  [in] BufferSize 	Size of buffer \n
/// @return void
/// @globals
///   @ref MTSI_t_StaticStatistics StaticStatistics
/// @InOutCorrelation
///   In case the input parameters are valid, in the static statistic will store the used lane and size for sync buffer.
/// @callsequence
/// @image html MTSI_StatsStoreSyncBufferStatistic.png Sequence Diagram
/// @testmethod
///  1) @ref TEST_MTSI_StatsStoreSyncBufferStatistic_1 : test functionality for both valid/invalid input data (CoreID and LaneId).
/// @traceability
///   <a href="doors://rbgs854a:40000/?version=2&prodID=0&view=00000006&urn=urn:telelogic::1-503e822e5ec3651e-O-779-0005ebe0"><strong> MTSI_StatsStoreSyncBufferStatistic L4 Design Specification</strong></a>
void MTSI_StatsStoreSyncBufferStatistic(const uint8 CoreId, const uint8 LaneId, const uint32 BufferSize);


/// @brief  Store async queue configuration at static statistics
/// @pre    none
/// @post   none
/// @param[in] CoreId 		Core that is related to this queue \n
/// @param[in] LaneId 		Lane on that this queue is sent \n
/// @param[in] QueueSize 	Size of queue \n
/// @return void
/// @globals
///   @ref MTSI_t_StaticStatistics StaticStatistics
/// @InOutCorrelation
///    In case the input parameters are valid, it shall store the size of async queues in the static statistic.
/// @callsequence
/// @image html MTSI_StatsStoreAsyncQueueStatistic.png Sequence Diagram
/// @testmethod
///  1) @ref TEST_MTSI_StatsStoreAsyncQueueStatistic_1 : test functionality for both valid/invalid input data (CoreID/LaneId boundary check for CFG_MTSI_NUMBER_OF_CORES/CFG_MTSI_NUMBER_OF_LANES).
/// @traceability
///   <a href="doors://rbgs854a:40000/?version=2&prodID=0&view=00000006&urn=urn:telelogic::1-503e822e5ec3651e-O-778-0005ebe0"><strong> MTSI_StatsStoreAsyncQueueStatistic L4 Design Specification</strong></a>
void MTSI_StatsStoreAsyncQueueStatistic(const uint8 CoreId, const uint8 LaneId, const uint16 QueueSize);


/// @brief  Set statistic checkpoint
/// If configured, checkpoints will be stored and RTA events will be set therefore.
/// @pre    none
/// @post   none
/// @param[in] CheckpointMainId 	Main ID of this checkpoint \n
/// @param[in] CheckpointSubId 	Sub ID of this checkpoint \n
/// @param[in] p_Header 			MTS Header \n
/// @return   void
/// @globals  None
/// @InOutCorrelation   None
/// @callsequence
/// @image html MTSI_StatsSetCheckpoint.png Sequence Diagram
/// @testmethod
///  1) @ref TEST_MTSI_StatsSetCheckpoint_1 : test functionality (checkpoint storage) for valid/invalid input parameters. (CoreID less than, equal, greater than CFG_MTSI_NUMBER_OF_CORES- boundary check)
/// @traceability
///   <a href="doors://rbgs854a:40000/?version=2&prodID=0&view=00000006&urn=urn:telelogic::1-503e822e5ec3651e-O-782-0005ebe0"><strong> MTSI_StatsSetCheckpoint L4 Design Specification</strong></a>
void MTSI_StatsSetCheckpoint(const uint8 CheckpointMainId, const uint8 CheckpointSubId, MTSI_t_Header const * const p_Header);


/// @brief    	Set RTA event.
///             Possible event types are MARKER, START and END.
/// @pre   none
/// @post  none
/// @param[in] EventType 	Type of event [MARKER, START, END] \n
/// @param[in] EventId      Identifier of event \n
/// @param[in] AddInfo 	    Additional information \n
/// @return   void
/// @globals  None
/// @InOutCorrelation   None
/// @callsequence
/// @image html MTSI_StatsSetEvent.png Sequence Diagram
/// @testmethod
///  1) @ref TEST_MTSI_StatsSetEvent_1 : Code coverage for function.
/// @traceability
///   <a href="doors://rbgs854a:40000/?version=2&prodID=0&view=00000006&urn=urn:telelogic::1-503e822e5ec3651e-O-770-0005ebe0"><strong> MTSI_StatsSetEvent L4 Design Specification</strong></a>
void MTSI_StatsSetEvent(const uint8 EventType, const uint8 EventId, const uint8 AddInfo);


/// @brief   Store version verification in the priority queue
/// @pre     none
/// @post    none
/// @param[in] LaneId ID of lane for that version verification shall be stored
/// @return  void
/// @globals none
/// @InOutCorrelation
///   If the pointer for the version info packet of the SW is valid, it will set the freeze information, create the MTS header , adapt the task id and counter,
///   update time sync packet and store the data in a priority queue. Otherwise it will set a error checkpoint.
/// @callsequence
/// @image html StoreVersionVerification.png Sequence Diagram
/// @testmethod
///   1) @ref TEST_StoreVersionVerification_1 : Test functionality for both valid/invalid(NULL) VersionInfo packet provided by the statistics module. \n
/// @traceability
///   <a href="doors://rbgs854a:40000/?version=2&prodID=0&view=00000006&urn=urn:telelogic::1-503e822e5ec3651e-O-804-0005ebe0"><strong> StoreVersionVerification L4 Design Specification</strong></a>
#if( (defined CFG_MTSI_ENABLE_VERSION_VERIFICATION) && (TRUE == CFG_MTSI_ENABLE_VERSION_VERIFICATION) )
void StoreVersionVerification(const uint8 LaneId);
#endif


/// @brief   Store dynamic statistic data
/// @pre     none
/// @post    none
/// @param[in] LaneId ID of lane for that dynamic statistics shall be stored
/// @return  void
/// @globals none
/// @InOutCorrelation
///   If the pointer for retrieving the dynamic statistic structure is valid, update the content and store it for the next transmission.
///   A error checkpoint shall be set if either a dynamic data structure is not properly configured of sending out the
///   computed dynamic data information was not successful.
/// @callsequence
/// @image html StoreDynamicStatistics.png Sequence Diagram
/// @testmethod
///   1) @ref TEST_StoreDynamicStatistics_1 : Test functionality when the Dynamic structure is both valid/not valid(NULL) and the structure freeze is both successful/unsuccessful. \n
/// @traceability
///   <a href="doors://rbgs854a:40000/?version=2&prodID=0&view=00000006&urn=urn:telelogic::1-503e822e5ec3651e-O-805-0005ebe0"><strong> StoreDynamicStatistics L4 Design Specification</strong></a>
void StoreDynamicStatistics(const uint8 LaneId);


/// @brief  Retrieve dynamic statistic data
/// @pre    none
/// @post   none
/// @param[in] CoreId 	ID of core whose statistic data is required \n
/// @param[in] LaneId 	ID of lane whose statistic data is required \n
/// @return MTSI_t_DynamicStatistics
/// @globals
///   @ref StatisticControl
/// @InOutCorrelation   None
/// @callsequence
/// @image html MTSI_StatsGetDynamicStatistics.png Sequence Diagram
/// @testmethod
///  1) @ref TEST_MTSI_StatsGetDynamicStatistics_1 : Code coverage for function.
/// @traceability
///   <a href="doors://rbgs854a:40000/?version=2&prodID=0&view=00000006&urn=urn:telelogic::1-503e822e5ec3651e-O-776-0005ebe0"><strong> MTSI_StatsGetDynamicStatistics L4 Design Specification</strong></a>
MTSI_t_DynamicStatistics * MTSI_StatsGetDynamicStatistics(const uint8 CoreId, const uint8 LaneId);


/// @brief  Clear dynamic statistic data
/// @pre    none
/// @post   none
/// @param[in] CoreId 	ID of core whose dynamic statistics shall be cleared \n
/// @param[in] LaneId 	ID of lane whose dynamic statistics shall be cleared \n
/// @return  void
/// @globals
///   @ref StatisticControl
/// @InOutCorrelation
///   When the pointer for retrieving dynamic statistics of MTSI module is valid it will clear the statistics of async and sync jobs and data.
/// @callsequence
/// @image html MTSI_StatsClearDynamicStatistics.png Sequence Diagram
/// @testmethod
///  1) @ref TEST_MTSI_StatsClearDynamicStatistics_1 : test DynamicStatistic data clear, for both cases where a valid reference is provided or not.
/// @traceability
///   <a href="doors://rbgs854a:40000/?version=2&prodID=0&view=00000006&urn=urn:telelogic::1-503e822e5ec3651e-O-775-0005ebe0"><strong> MTSI_StatsClearDynamicStatistics L4 Design Specification</strong></a>
void MTSI_StatsClearDynamicStatistics(const uint8 CoreId, const uint8 LaneId);


/// @brief     Finish dynamic statistic data
/// @pre       none
/// @post      none
/// @param[in] CoreId Core whose dynamic statistics shall be finished \n
/// @param[in] LaneId Lane whose dynamic statistics shall be finished
/// @return    void
/// @globals   None
/// @InOutCorrelation
///    When the pointer for retrieving dynamic statistics of MTSI module is valid it will check/update the statistic of of async and sync jobs and data.
/// @callsequence
/// @image html MTSI_StatsFinishDynamicStatistics.png Sequence Diagram
/// @testmethod
///  1) @ref TEST_MTSI_StatsFinishDynamicStatistics_1 : test DynamicStatistic data update, for both cases where a valid reference is provided or not.
/// @traceability
///   <a href="doors://rbgs854a:40000/?version=2&prodID=0&view=00000006&urn=urn:telelogic::1-503e822e5ec3651e-O-774-0005ebe0"><strong> MTSI_StatsFinishDynamicStatistics L4 Design Specification</strong></a>
void MTSI_StatsFinishDynamicStatistics(const uint8 CoreId, const uint8 LaneId);


/// @brief      Store MTSI checkpoints
/// @pre        none
/// @post       none
/// @param      none
/// @return     void
/// @globals    none
/// @InOutCorrelation
///   For each core, if the pointer for MTSI checkpoint control is valid and configured for each core, it will get the payload length, set the freeze info,
///   adapt the virtual address offset, create MTS header and store the data in a sync buffer.
///   If the checkpoints could not be sent to the MTS System it will set an RTA event, otherwise the meas job was ok.
/// @callsequence
/// @image html StoreCheckpoints.png Sequence Diagram
/// @testmethod
///   1) @ref TEST_StoreCheckpoints_1 : Test functionality for valid (not NULL) Checkpoints structure, data to be sent (Size <> 0) and successful/unsuccessful measFreze. \n
///   2) @ref TEST_StoreCheckpoints_2 : Test functionality for invalid parameters (Checkpoint structure address is NULL) / no data to be sent (Size == 0) \n
/// @traceability
///   <a href="doors://rbgs854a:40000/?version=2&prodID=0&view=00000006&urn=urn:telelogic::1-503e822e5ec3651e-O-806-0005ebe0"><strong> StoreCheckpoints L4 Design Specification</strong></a>
void StoreCheckpoints(void);

#ifdef __cplusplus
}
#endif

#endif
