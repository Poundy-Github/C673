// Copyright (C) Continental AG
// All Rights Reserved
// COMPONENT: MTSI
// VERSION:   $Revision: 1.19 $

#include <MTSI_Driver.h>
#include <MTSI_Statistics.h>
#include <MTSI_Cfg_Int.h>
#include <MTSI_Callouts.h>
#include <MTSI_Pal.h>
#include <MTSI_TaskId_Cfg.h>

#if( (defined CFG_MTSI_ENABLE_VERSION_VERIFICATION) && (TRUE == CFG_MTSI_ENABLE_VERSION_VERIFICATION) )
#include <InfoBlockContents.h>
#endif

#ifndef __IPL_CANTPP__
//#include <sys_mem.h>
#endif

#include <MTSI_Custom.h>

#include <glob_comp_id.h>

/* PRQA S 838, 861, 5087 EOF */
/* Multiple include of MTSI_MemMap_Cfg.h within source code is required for core specific memory mapping of static variables. */
/* PRQA S 2981 EOF *//* This initialization is redundant. The value of this object is never used before being modified. */
/* Not a problem, keep it this way. */
/* PRQA S 2052,2053 EOF *//* This line/block comment appears to comment out source code. */
/* Required to properly visualize the #if/#else/#endif matching conditions */

#ifdef __cplusplus
extern "C"
{
#endif

/// @brief    RTA global id for MTSI events
#define MTSI_GLOBAL_RTA_ID (uint8)RTA_GLOBALID_MTSI

#define MTSI_START_SEC_VAR_INIT_ASIL_B_CACHED_UNSPECIFIED
#include <MTSI_MemMap_Cfg.h>

#if( (defined CFG_MTSI_ENABLE_VERSION_VERIFICATION) && (TRUE == CFG_MTSI_ENABLE_VERSION_VERIFICATION) )
/// @brief    SW version info packet
/// Appropriate information are retrieved from INFOBLOCK component
/// and must be sent at the beginning of each MTA frame.
static MTSI_t_VersionInfoPacket VersionInfoPacket CFG_MTSI_DECLARATION_ATTRIBUTE = { { 0u } };
#endif /*( (defined CFG_MTSI_ENABLE_VERSION_VERIFICATION) && (TRUE == CFG_MTSI_ENABLE_VERSION_VERIFICATION) )*/

/// @brief      Static statistic data of MTSI module
/// Contains all configurable settings like activated features, buffer size etc.
/*! @vaddr: MTSI_STATIC_STATS_VIRT_ADDR  @vname: MTSI_StaticStatistics @cycleid: MTSI_CYCLIC_10MS */
static MTSI_t_StaticStatistics StaticStatistics = { { 0u } , { { 0u } } };

/// @brief      Reference identifier (occurrence order counter) used to indicate to order
///             in which the errors stored in the checkpoint structures occur.
static uint8 RefId = 0u; /* PRQA S 3218 */ /* date: 2018-03-06, reviewer: AnMo, Reason: Static local variables turned into global variables and encapsulate with section macros. */

#define MTSI_STOP_SEC_VAR_INIT_ASIL_B_CACHED_UNSPECIFIED
#include <MTSI_MemMap_Cfg.h>

#define MTSI_START_SEC_CODE_ASIL_B
#include <MTSI_MemMap_Cfg.h>

#if( (defined CFG_MTSI_ENABLE_VERSION_VERIFICATION) && (TRUE == CFG_MTSI_ENABLE_VERSION_VERIFICATION) )
/// @brief    Initialize the version info packet
/// Required information is retrieved from INFOBLOCK.
/// @pre     none
/// @post    none
/// @param   void
/// @return  void
/// @globals   @ref  VersionInfoPacket
/// @InOutCorrelation  Will retrieve detailed version, detailed date, detailed time, project id and checksum from infoblock.
/// @callsequence
/// @image html InitVersionInfoPacket.png Sequence Diagram
/// @testmethod
///  1) @ref TEST_InitVersionInfoPacket_1 : test initialization of all VersionInfoPacket members with the InfoBlock Data. Coverage assert.
/// @traceability
///  Not a public interface. Function called from MTSI_StatsInit \n
///  <a href="doors://rbgs854a:40000/?version=2&prodID=0&view=00000006&urn=urn:telelogic::1-503e822e5ec3651e-O-769-0005ebe0"><strong> MTSI_StatsInit L4 Design Specification</strong></a>
static void InitVersionInfoPacket(void);
#endif /*( (defined CFG_MTSI_ENABLE_VERSION_VERIFICATION) && (TRUE == CFG_MTSI_ENABLE_VERSION_VERIFICATION) )*/

/// @brief    Initialize the static statistic data  
/// @pre      none
/// @post     none
/// @param[in] MajorVersion:  Major version of module \n
/// @param[in] MinorVersion:  Minor version of module \n
/// @param[in] PatchVersion:  Patch version of module \n
/// @return   void
/// @globals  @ref  StaticStatistics
/// @InOutCorrelation
///   After it clears the static statistics, it will store the common module config, config of statistic module and config of MTS header.
/// @callsequence
/// @image html InitStaticStatistics.png Sequence Diagram
/// @testmethod
///   1) @ref TEST_InitStaticStatistics_1 : test initialization of all StaticStatistics members with the InfoBlock Data. Coverage assert.
/// @traceability
///  Not a public interface. Function called from MTSI_StatsInit \n
///  <a href="doors://rbgs854a:40000/?version=2&prodID=0&view=00000006&urn=urn:telelogic::1-503e822e5ec3651e-O-769-0005ebe0"><strong> MTSI_StatsInit L4 Design Specification</strong></a>
static void InitStaticStatistics(const uint16 MajorVersion, const uint8 MinorVersion, const uint8 PatchVersion);

/// @brief    Initialize the dynamic statistic data for each individual core.
/// @pre      none
/// @post     none
/// @param    void
/// @return   void
/// @globals  Dynamic statistic structures for each core.
/// @InOutCorrelation
///   It retrieve dynamic statistics of each core and lane, and if the pointer for dynamic statistics is valid, it will clear the dynamic statistics. 
/// @callsequence
/// @image html InitDynamicStatistics.png Sequence Diagram
/// @testmethod
///  1) @ref TEST_InitDynamicStatistics_1 : test initialization of dynamic statistic data, for all CoreIDs & LaneIDs, for both valid/invalid (non null/null) Dynamic structure references
/// @traceability
///  Not a public interface. Function called from MTSI_StatsInit \n
///  <a href="doors://rbgs854a:40000/?version=2&prodID=0&view=00000006&urn=urn:telelogic::1-503e822e5ec3651e-O-769-0005ebe0"><strong> MTSI_StatsInit L4 Design Specification</strong></a>
static void InitDynamicStatistics(void);

/// @brief    Initialize the MTSI checkpoints  
/// @pre      none
/// @post     none
/// @param 	  void
/// @return	  void
/// @globals  @ref   StatisticControl
/// @InOutCorrelation
///   Initializes the control variable for each core: checkpoint WriteIndex and checkpoint data, then updates the StaticStatistics checkpointSize element.
/// @callsequence
/// @image html InitCheckpoints.png Sequence Diagram
/// @testmethod
///  1) @ref TEST_InitCheckpoints_1 : Call function InitCheckpoints() at regular circumstances for coverage.
/// @traceability
///  Not a public interface. Function called from MTSI_StatsInit \n
///  <a href="doors://rbgs854a:40000/?version=2&prodID=0&view=00000006&urn=urn:telelogic::1-503e822e5ec3651e-O-769-0005ebe0"><strong> MTSI_StatsInit L4 Design Specification</strong></a>
static void InitCheckpoints(void);

/// @brief    	Clear MTSI checkpoints
/// @pre        none
/// @post       none
/// @param[in] 	CoreId Id of core whose checkpoints shall be cleared
/// @return     void
/// @globals
///   @ref  StatisticControl
/// @InOutCorrelation
///   Enter exclusive area, clear the checkpoints buffer and reset the write index.
/// @callsequence
/// @image html MTSI_StatsClearCheckpoints.png Sequence Diagram
/// @testmethod
///  1) @ref TEST_MTSI_StatsClearCheckpoints_1 : Code coverage for function.
/// @traceability
///  <a href="doors://rbgs854a:40000/?version=2&prodID=0&view=00000006&urn=urn:telelogic::1-503e822e5ec3651e-O-771-0005ebe0"><strong> MTSI_StatsClearCheckpoints L4 Design Specification</strong></a>
void MTSI_StatsClearCheckpoints(const uint8 CoreId);

/// @brief    Check dynamic statistic data  
/// @pre      none
/// @post     none
/// @param[inout] p_DynamicStatisticData:  Statistic data to be evaluated
/// @return   void
/// @globals  none
/// @InOutCorrelation
///   When the pointer for dynamic statistic data is valid and uninitialized, it will initialize the all time low and all time high value with the current value, then set the initialization flag to b_TRUE.
///   Otherwise, if the value has been initialized it will check all time high and low value and set them. 
/// @callsequence
/// @image html CheckDynamicStatisticData.png Sequence Diagram
/// @testmethod
///  1) @ref TEST_CheckDynamicStatisticData_1 : test update of DynamicStatistic data, for both covered cases: data not initialized(first run) and normal runtime (min/max update) \n
/// @traceability
///   Not a public interface. Function called from MTSI_StatsFinishDynamicStatistics \n
///  <a href="doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-774-0005ebe0"><strong> MTSI_StatsFinishDynamicStatistics L4 Design Specification</strong></a>
static void CheckDynamicStatisticData(MTSI_t_DynamicStatisticData * const p_DynamicStatisticData);

/// @brief    Store checkpoint into core specific list  
/// @pre      none
/// @post     none
/// @param[in] CheckpointMainId:  Main ID of this checkpoint \n
/// @param[in] CheckpointSubId:  Sub ID of this checkpoint \n
/// @param[in] CoreId:  ID of core that is related to this checkpoint \n
/// @param[in] ReferenceId:  Reference to RTA event \n
/// @param[in] p_Header:  Header that has been forwarded with this checkpoint
/// @return   void
/// @globals  @ref  StaticStatistics
/// @InOutCorrelation
/// If the core ID is valid the function will get the appropriate checkpoint control and will check the status of list then will get the checkpoint entry.
/// The checkpoint identifier will be set, the reference Id stored and write index will be incremented.
/// @callsequence
/// @image html StoreCheckpoint.png Sequence Diagram
/// @testmethod
///  1) @ref TEST_StoreCheckpoint_1 : test checkpoint storage in the Checkpoint buffer, for both cases: buffer still available(WriteIndex < BufferSize) / buffer full (WriteIndex >= BufferSize)
/// @traceability
///   Not a public interface. Function called from MTSI_StatsSetCheckpoint \n
///  <a href="doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-782-0005ebe0"><strong> MTSI_StatsSetCheckpoint L4 Design Specification</strong></a>
static void StoreCheckpoint(const uint8 CheckpointMainId, const uint8 CheckpointSubId, const uint8 CoreId, const uint8 ReferenceId, MTSI_t_Header const * const p_Header);


void MTSI_StatsInit(const uint16 MajorVersion, const uint8 MinorVersion, const uint8 PatchVersion)
{
#if ( (defined CFG_MTSI_ENABLE_VERSION_VERIFICATION) && (TRUE == CFG_MTSI_ENABLE_VERSION_VERIFICATION) )
  // Initialize the version info packet 
  InitVersionInfoPacket();
#endif /* ( (defined CFG_MTSI_ENABLE_VERSION_VERIFICATION) && (TRUE == CFG_MTSI_ENABLE_VERSION_VERIFICATION) )*/
  
  // Initialize static statistic data 
  InitStaticStatistics(MajorVersion, MinorVersion, PatchVersion);
  
  // Initialize dynamic statistic data 
  InitDynamicStatistics();
  
  // Initialize MTSI checkpoints 
  InitCheckpoints();
}

void MTSI_StatsStoreConfigurationSettings(const uint8 Mode, const uint8 InstanceNr)
{
  // Store instance number and output mode at static statistics 
  StaticStatistics.ModuleConfig.CommonConfig.OutputMode     = Mode;
  StaticStatistics.ModuleConfig.CommonConfig.InstanceNumber = InstanceNr;
}


void MTSI_StatsStoreSyncBufferStatistic(const uint8 CoreId, const uint8 LaneId, const uint32 BufferSize)
{
  // Store sync buffer config at statistic data
  StaticStatistics.ModuleConfig.CoreConfig[CoreId].SyncBufferLane = LaneId;
  StaticStatistics.ModuleConfig.CoreConfig[CoreId].SyncBufferSize = BufferSize;
}


void MTSI_StatsStoreAsyncQueueStatistic(const uint8 CoreId, const uint8 LaneId, const uint16 QueueSize)
{
  // Store async queue config at statistic data
  StaticStatistics.ModuleConfig.CoreConfig[CoreId].AsyncQueueSize[LaneId] = QueueSize;
}


// this function is to be called in error cases only
// purpose:
// - set a checkpoint that will be freezed out
// - set a RTA marker <- if RTA is enabled.
void MTSI_StatsSetCheckpoint(const uint8 CheckpointMainId, const uint8 CheckpointSubId, MTSI_t_Header const * const p_Header)
{
  // Retrieve core id */
  const uint8 CoreId = MTSI_PalGetCoreId();
  
  // Check validity of core id */
  if( (uint8)CFG_MTSI_NUMBER_OF_CORES > CoreId )
  {
    // Store checkpoint only in negative cases (disregard any positive case) 
    StoreCheckpoint(CheckpointMainId, CheckpointSubId, CoreId, RefId, p_Header);
    
    // Set RTA event 
    MTSI_StatsSetEvent(MTSI_EVENT_TYPE_MARKER, (CheckpointMainId + CheckpointSubId), RefId);
    
    // Increment reference identifier 
    RefId++;
  }
  else
  {
    // Nothing needs to be done 
  }
}


/*PRQA S 3206 2*//* "The parameter '%s' is not used in this function." - The parameter are used if the RTA instrumentation is enabled. */
void MTSI_StatsSetEvent(const uint8 EventType, const uint8 EventId, const uint8 AddInfo)
{
#if ( (defined CFG_MTSI_RTA_USAGE_ENABLED) && (CFG_MTSI_RTA_USAGE_ENABLED == TRUE) )
  RTA_v_AddEvent(EventType, MTSI_GLOBAL_RTA_ID, EventId, AddInfo);
#endif
}


void StoreDynamicStatistics(const uint8 LaneId)
{
  // Local variables
  uint8  CoreIndex                    = 0u;
  MEASReturn_t MEASReturn_FreezeData  = MEAS_NOT_OK;

  // Send dynamic statistics of each core
  /* PRQA S 2877 1 */ /* For loop required because it is possible that module has to support more than one core. */
  for(CoreIndex = 0u; (uint8)CFG_MTSI_NUMBER_OF_CORES > CoreIndex; CoreIndex++)
  {
    // Retrieve dynamic statistics
    MTSI_t_DynamicStatistics const* p_DynamicStatistics = MTSI_StatsGetDynamicStatistics(CoreIndex, LaneId);

    // Check validity of pointer
    if( NULL != p_DynamicStatistics )
    {
      // Local variables
      MTSI_t_FreezeInfo FreezeInfo;
      MTSI_t_Header     MTSHeader;

      // Set freeze info
      FreezeInfo.VirtualAddress = MTSI_GET_DYNAMIC_STATS_VIRT_ADDR(CoreIndex, LaneId);
      FreezeInfo.FunctionId     = MTSI_FUNCTION_ID_MTSI_MTA;
      FreezeInfo.Length         = (uint32)sizeof(MTSI_t_DynamicStatistics);
      FreezeInfo.Options        = MTSI_OPTION_NONE;

      // Enter exclusive area
      (void)MTSI_PalEnterExclusiveArea();

      // Finish dynamic statistics
      MTSI_StatsFinishDynamicStatistics(CoreIndex, LaneId);

      // Create MTS header
      MTSI_DriverPrepareHeader(&FreezeInfo, &MTSHeader);

      // Store data in sync buffer
      /* PRQA S 314 1 */ /* Cast of p_DynamicStatistics to void-pointer is required because of generic interface of MTSI_DriverStoreSyncJob. */
      MEASReturn_FreezeData = MTSI_DriverStoreSyncJob(&MTSHeader, (void const*)p_DynamicStatistics, NULL);

      // Clear dynamic statistics
      MTSI_StatsClearDynamicStatistics(CoreIndex, LaneId);

      MTSI_PalExitExclusiveArea();

      // Set RTA event in case the statistics could not be sent to the MTS System
      /* PRQA S 2996 1 */ /* 2018-12-03 C. Tudoran: Result of below logical operation cannot be always false because of the return value from MTSI_DriverStoreSyncJob */
      if (MEAS_SYNC_JOB_ACCEPTED == MEASReturn_FreezeData)
      {
        // Meas Job was OK
      }
      else
      {
        MTSI_StatsSetCheckpoint((uint8)MTSI_CHKPT_ID_FUNC_STORE_DYNAMIC_STATISTIC_DATA, (uint8)MTSI_CHKPT_ERR_ID_0, NULL);
      }
    }
    else
    {
      // Set checkpoint because of invalid pointer to dynamic statistics
      MTSI_StatsSetCheckpoint((uint8)MTSI_CHKPT_ID_FUNC_STORE_DYNAMIC_STATISTIC_DATA, (uint8)MTSI_CHKPT_ERR_ID_1, NULL);
    }
  }
}

MTSI_t_DynamicStatistics * MTSI_StatsGetDynamicStatistics(const uint8 CoreId, const uint8 LaneId)
{
  // Dynamic statistics to be returned 
  MTSI_t_DynamicStatistics* p_DynamicStatistics = NULL;

  // Retrieve dynamic statistics for this core and lane
  p_DynamicStatistics = StatisticControl[CoreId].p_DynamicStatisticControl->p_DynamicStats[LaneId];
  
  return p_DynamicStatistics;
}


void MTSI_StatsClearDynamicStatistics(const uint8 CoreId, const uint8 LaneId)
{
  // Retrieve dynamic statistics 
  MTSI_t_DynamicStatistics * const p_DynamicStatistics = MTSI_StatsGetDynamicStatistics(CoreId, LaneId);
  
  // Check pointer validity 
  if( NULL != p_DynamicStatistics )
  {
    // Clear statistics of sync jobs 
    p_DynamicStatistics->SyncBufferUsage.CurrentValue = 0u;
    // Clear statistics of async jobs 
    p_DynamicStatistics->AsyncJobs.CurrentValue       = 0u;
    // Clear statistics of sync data 
    p_DynamicStatistics->SyncData.CurrentValue        = 0u;
  }
  else
  {
    // Nothing needs to be done 
  }
}


void MTSI_StatsFinishDynamicStatistics(const uint8 CoreId, const uint8 LaneId)
{
  // Retrieve dynamic statistics 
  MTSI_t_DynamicStatistics * const p_DynamicStatistics = MTSI_StatsGetDynamicStatistics(CoreId, LaneId);
  
  // Check pointer validity 
  if( NULL != p_DynamicStatistics )
  {
    // Check statistic of sync jobs 
    CheckDynamicStatisticData(&p_DynamicStatistics->SyncBufferUsage);
    // Check statistic of sync data 
    CheckDynamicStatisticData(&p_DynamicStatistics->SyncData);
    // Check statistic of async jobs 
    CheckDynamicStatisticData(&p_DynamicStatistics->AsyncJobs);
  }
  else
  {
    // Nothing needs to be done 
  }
}


void StoreCheckpoints(void)
{
  // Local variables
  uint8  CoreIndex                    = 0u;
  uint32 VirtualAddressOffset         = 0u;
  MEASReturn_t MEASReturn_FreezeData  = MEAS_NOT_OK;

  // Send checkpoints of each core
  /* PRQA S 2877 1 */ /* For loop required because it is possible that module has to support more than one core. */
  for(CoreIndex = 0u; (uint8)CFG_MTSI_NUMBER_OF_CORES > CoreIndex; CoreIndex++)
  {
    // Retrieve checkpoint control
    MTSI_t_CheckpointControl const* p_CheckpointCtrl = StatisticControl[CoreIndex].p_CheckpointControl;

    // Check validity of pointer
    if( NULL != p_CheckpointCtrl )
    {
      // Check if checkpoints are configured for this core
      if( (uint8)0x00 < p_CheckpointCtrl->Size )
      {
        // Local variables
        MTSI_t_FreezeInfo FreezeInfo;
        MTSI_t_Header     MTSHeader;
        uint32            PayloadLength;

        // Get payload length
        PayloadLength = (uint32)p_CheckpointCtrl->Size * (uint32)sizeof(MTSI_t_Checkpoint);

        // Set freeze info
        FreezeInfo.VirtualAddress = MTSI_CHECKPOINTS_VIRT_ADDR + VirtualAddressOffset;
        FreezeInfo.FunctionId     = MTSI_FUNCTION_ID_MTSI;
        FreezeInfo.Length         = PayloadLength;
        FreezeInfo.Options        = MTSI_OPTION_NONE;

        // Adapt virtual address offset
        VirtualAddressOffset += PayloadLength;

        //Enter ExclusiveArea
        (void)MTSI_PalEnterExclusiveArea();

        // Create MTS header
        MTSI_DriverPrepareHeader(&FreezeInfo, &MTSHeader);

        // Store data in sync buffer
        /* PRQA S 314 1 */ /* Cast of p_CheckpointList to void-pointer is required because of generic interface of MTSI_DriverStoreSyncJob. */
        MEASReturn_FreezeData = MTSI_DriverStoreSyncJob(&MTSHeader, (void*)p_CheckpointCtrl->p_Checkpoints, NULL);

        // Clear checkpoints
        MTSI_StatsClearCheckpoints(CoreIndex);

        //Enter ExclusiveArea
        MTSI_PalExitExclusiveArea();

        // Set RTA event in case the statistics could not be sent to the MTS System
        /* PRQA S 2996 1 */ /* 2018-12-03 C. Tudoran: Result of below logical operation cannot be always false because of the return value from MTSI_DriverStoreSyncJob */
        if (MEAS_SYNC_JOB_ACCEPTED == MEASReturn_FreezeData)
        {
          // Meas Job was OK
        }
        else
        {
          MTSI_StatsSetCheckpoint((uint8)MTSI_CHKPT_ID_FUNC_STORE_CHECKPOINTS, (uint8)MTSI_CHKPT_ERR_ID_0, NULL);
        }
      }
      else
      {
        // Nothing needs to be done
      }
    }
    else
    {
      // Set checkpoint because of invalid pointer to checkpoint data
      MTSI_StatsSetCheckpoint((uint8)MTSI_CHKPT_ID_FUNC_STORE_CHECKPOINTS, (uint8)MTSI_CHKPT_ERR_ID_1, NULL);
    }
  }
}


void MTSI_StatsClearCheckpoints(const uint8 CoreId)
{
  // Retrieve checkpoint control
  MTSI_t_CheckpointControl * const p_CheckpointCtrl = StatisticControl[CoreId].p_CheckpointControl;
    
  // Enter exclusive area
  (void)MTSI_PalEnterExclusiveArea();
    
  // Clear checkpoints
  /* PRQA S 314 1 */ /* Cast of p_Checkpoints to void-pointer is required because of generic interface of memset. */
  (void)memset((void*)p_CheckpointCtrl->p_Checkpoints, 0, (p_CheckpointCtrl->Size * sizeof(MTSI_t_Checkpoint)));
  
  // Reset write index
  p_CheckpointCtrl->WriteIndex = 0u;
  
  // exit exclusive area
  MTSI_PalExitExclusiveArea();
}


#if( (defined CFG_MTSI_ENABLE_VERSION_VERIFICATION) && (TRUE == CFG_MTSI_ENABLE_VERSION_VERIFICATION) )
static void InitVersionInfoPacket(void)
{
  // Retrieve detailed version from infoblock
  VersionInfoPacket.Version.Major      = CurrentInfoBlock.s_IdentInfoBlock.s_Version.s_VersionDetail.ui8_Major;
  VersionInfoPacket.Version.Minor      = CurrentInfoBlock.s_IdentInfoBlock.s_Version.s_VersionDetail.ui8_Minor;
  VersionInfoPacket.Version.PatchLevel = CurrentInfoBlock.s_IdentInfoBlock.s_Version.s_VersionDetail.ui8_PatchLevel;
  VersionInfoPacket.Version.SelectedBuildType = CurrentInfoBlock.s_IdentInfoBlock.s_Version.s_VersionDetail.e_SelectedBuildType;

  // Retrieve detailed date from infoblock
  VersionInfoPacket.Date.Reserved = CurrentInfoBlock.s_IdentInfoBlock.s_Date.s_DateDetail.ui8_Reserved;
  VersionInfoPacket.Date.Year     = CurrentInfoBlock.s_IdentInfoBlock.s_Date.s_DateDetail.ui8_Year;
  VersionInfoPacket.Date.Month    = CurrentInfoBlock.s_IdentInfoBlock.s_Date.s_DateDetail.ui8_Month;
  VersionInfoPacket.Date.Day      = CurrentInfoBlock.s_IdentInfoBlock.s_Date.s_DateDetail.ui8_Day;

  // Retrieve detailed time from infoblock
  VersionInfoPacket.Time.Reserved = CurrentInfoBlock.s_IdentInfoBlock.s_Time.s_TimeDetail.ui8_Reserved;
  VersionInfoPacket.Time.Hour     = CurrentInfoBlock.s_IdentInfoBlock.s_Time.s_TimeDetail.ui8_Hour;
  VersionInfoPacket.Time.Minute   = CurrentInfoBlock.s_IdentInfoBlock.s_Time.s_TimeDetail.ui8_Minute;
  VersionInfoPacket.Time.Second   = CurrentInfoBlock.s_IdentInfoBlock.s_Time.s_TimeDetail.ui8_Second;

  // Retrieve project id from infoblock
  /* PRQA S 314 1 */ /* Pointer casts are required because of the generic interface of memcpy. */
  (void)memcpy((void*)VersionInfoPacket.ProjectId, (void const *)CurrentInfoBlock.s_IdentInfoBlock.ui8_ProjectID, InfoBlockStructure_PROJECT_ID_LENGTH);

  // Retrieve checksum from infoblock
  VersionInfoPacket.Checksum = CurrentInfoBlock.s_CommonInfoBlock.s_CrcBuffer.ui32_CrcChecksum;
}


void StoreVersionVerification(const uint8 LaneId)
{
  // Local variables
  MTSI_t_FreezeInfo FreezeInfo;
  MTSI_t_Header     MTSHeader;

  // Set freeze info
  FreezeInfo.VirtualAddress = MTSI_VERSION_INFO_PACKET_VIRT_ADDR;
  FreezeInfo.FunctionId     = MTSI_FUNCTION_ID_MTSI_MTA;
  FreezeInfo.Length         = (uint32)sizeof(MTSI_t_VersionInfoPacket) - 4u;
  FreezeInfo.Options        = MTSI_OPTION_NONE;

  // Enter exclusive area
  (void)MTSI_PalEnterExclusiveArea();

  // Create MTS header
  MTSI_DriverPrepareHeader(&FreezeInfo, &MTSHeader);

  // Adapt task id and counter
  MTSHeader.TaskIdentifier = CFG_MTSI_MTA_FRAME_TASK_BASE_ID + (uint16)LaneId;

  //For the version verification package, add a padding in front of the VersionInfoPacket (see data type MTSI_t_VersionInfoPacket)
  //and also increment the MTS SW header PaddingLength with the same value. This makes handling of the versionVerif packet non
  //generic but could not find a generic solution.
  //The current generic solution aligns all packages (both start address and length) to 8 bytes, making the VersionVerif packet
  //32 bytes in size, while MeasApp expect it to be 28 bytes long. (a error is thrown otherwise).
  MTSHeader.PaddingLength += 4u;

  /* Send the VersionVerification packet via the AsyncQueue. */
  /* PRQA S 314 1 */ /* Cast of TimeSyncPacket-address to void-pointer is required because of generic interface of WriteToQueue.*/
  (void)MTSI_DriverStoreAsyncJob(LaneId, &MTSHeader, (void*)&VersionInfoPacket, NULL);

  // Exit exclusive area
  MTSI_PalExitExclusiveArea();
}
#endif /*( (defined CFG_MTSI_ENABLE_VERSION_VERIFICATION) && (TRUE == CFG_MTSI_ENABLE_VERSION_VERIFICATION) )*/


static void InitStaticStatistics(const uint16 MajorVersion, const uint8 MinorVersion, const uint8 PatchVersion)
{
  // Clear static statistics 
  /* PRQA S 314 1 */ /* Cast of &StaticStatistics to void-pointer is required because of generic interface of memset. */
  (void)memset((void*)&StaticStatistics, 0, sizeof(StaticStatistics));
  
  // Store module version 
  StaticStatistics.ModuleVersion.MajorVersion = MajorVersion;
  StaticStatistics.ModuleVersion.MinorVersion = MinorVersion;
  StaticStatistics.ModuleVersion.PatchVersion = PatchVersion;
  
  // Store common module config 
  StaticStatistics.ModuleConfig.CommonConfig.NumberOfCores         = (uint8)CFG_MTSI_NUMBER_OF_CORES;
  StaticStatistics.ModuleConfig.CommonConfig.NumberOfLanes         = (uint8)CFG_MTSI_NUMBER_OF_LANES;
  StaticStatistics.ModuleConfig.CommonConfig.NumberOfToggleBuffers = (uint8)CFG_MTSI_NUMBER_OF_TOGGLE_BUFFERS;
  StaticStatistics.ModuleConfig.CommonConfig.MaximumNumberOfTasks  = (uint8)CFG_MTSI_MAXIMUM_NUMBER_OF_TASKS;
  
  // Store config of statistic module (number of checkpoints will be set at function "InitCheckpoints" 
  StaticStatistics.ModuleConfig.StatisticConfig.CheckpointsEnabled            = (boolean)FALSE;
  StaticStatistics.ModuleConfig.StatisticConfig.CycleTimeStaticStatistics     = (uint16)CFG_MTSI_STATISTICS_CYCLE_TIME_MS;
  StaticStatistics.ModuleConfig.StatisticConfig.CycleTimeMTSICheckpoints      = (uint16)CFG_MTSI_STATISTICS_CYCLE_TIME_MS;
  
  // Store config of MTS header 
  StaticStatistics.ModuleConfig.HeaderConfig.UseFunctionId         = (uint8)CFG_MTSI_HEADER_USE_FUNCTION_ID;
  StaticStatistics.ModuleConfig.HeaderConfig.UsePacketCounter      = (uint8)CFG_MTSI_HEADER_USE_PACKET_COUNTER;
  StaticStatistics.ModuleConfig.HeaderConfig.UseHighResTimestamp   = (uint8)CFG_MTSI_HEADER_USE_HIGH_RES_TIMESTAMP;
  StaticStatistics.ModuleConfig.HeaderConfig.UseAbsoluteTimestamp  = (uint8)CFG_MTSI_HEADER_USE_ABSOLUTE_TIMESTAMP;
  StaticStatistics.ModuleConfig.HeaderConfig.UseChecksum           = (uint8)CFG_MTSI_HEADER_USE_CHECKSUM;
  StaticStatistics.ModuleConfig.HeaderConfig.NumberOfPaddingBytes  = (uint8)CFG_MTSI_HEADER_NUMBER_OF_PADDING_BYTES;
}


void StoreStaticStatistics(void)
{
  // Local Variables
  MEASReturn_t MEASReturn_FreezeData  = MEAS_NOT_OK;

  // Local variables
  MTSI_t_FreezeInfo FreezeInfo;
  MTSI_t_Header     MTSHeader;

  const uint8 Lane = MTSI_CustomGetLaneId(MTSI_FUNCTION_ID_MTSI);

  // Set freeze info
  FreezeInfo.VirtualAddress = MTSI_STATIC_STATS_VIRT_ADDR;
  FreezeInfo.FunctionId     = MTSI_FUNCTION_ID_MTSI;
  FreezeInfo.Length         = (uint32)sizeof(MTSI_t_StaticStatistics);
  FreezeInfo.Options        = MTSI_OPTION_NONE;

  //Enter ExclusiveArea
  (void)MTSI_PalEnterExclusiveArea();

  // Create MTS header
  MTSI_DriverPrepareHeader(&FreezeInfo, &MTSHeader);

  // Store data in async queue
  /* PRQA S 314 1 */ /* Cast of p_StaticStatistics to void-pointer is required because of generic interface of MTSI_DriverStoreAsyncJob. */
  MEASReturn_FreezeData = MTSI_DriverStoreAsyncJob(Lane, &MTSHeader, (void const*)&StaticStatistics, NULL);

  //Exit ExclusiveArea
  MTSI_PalExitExclusiveArea();

  // Set RTA event in case the statistics could not be sent to the MTS System
  /* PRQA S 2996 1 */ /* 2018-12-03 C. Tudoran: Result of below logical operation cannot be always false because of the return value from MTSI_DriverStoreAsyncJob */
  if (MEAS_ASYNC_JOB_ACCEPTED == MEASReturn_FreezeData)
  {
    // Meas Job was OK
  }
  else
  {
    MTSI_StatsSetCheckpoint((uint8)MTSI_CHKPT_ID_FUNC_STORE_STATIC_STATISTIC_DATA, (uint8)MTSI_CHKPT_ERR_ID_0, NULL);
  }
}


static void InitDynamicStatistics(void)
{
  // Local variables 
  uint8 CoreIndex = 0u;
  uint8 LaneIndex = 0u;
  
  // Retrieve dynamic statistics of each core
  /* PRQA S 2877 1 */ /* For loop required because it is possible that module has to support more than one core.*/
  for(CoreIndex = 0u; (uint8)CFG_MTSI_NUMBER_OF_CORES > CoreIndex; CoreIndex++)
  {
    // Retrieve dynamic statistics of each lane 
    /* PRQA S 2877 1 */ /* For loop required because it is possible that module has to support more than one lane.*/
    for(LaneIndex = 0u; (uint8)CFG_MTSI_NUMBER_OF_LANES > LaneIndex; LaneIndex++)
    {
      // Retrieve dynamic statistics 
      MTSI_t_DynamicStatistics *p_DynamicStatistics = MTSI_StatsGetDynamicStatistics(CoreIndex, LaneIndex);
      
      // Check pointer validity 
      /* PRQA S 2991, 2995 1 */ /* Validity check required because NULL pointer might be possible due to invalid configuration.*/
      if( NULL != p_DynamicStatistics )
      {
        // Clear dynamic statistics 
        /* PRQA S 314 1 */ /* Cast of p_DynamicStatistics to void-pointer is required because of generic interface of memset. */
        (void)memset((void*)p_DynamicStatistics, 0, sizeof(MTSI_t_DynamicStatistics));
      }
      else
      {
        // Nothing needs to be done 
      }
    }
  }
}


static void InitCheckpoints(void)
{
  // Local variables 
  uint8 CoreIndex = 0u;
  
  // Initialize control variable for each core 
  /* PRQA S 2877 1 */ /* For loop required because it is possible that module has to support more than one core. */
  for(CoreIndex = 0u; (uint8)CFG_MTSI_NUMBER_OF_CORES > CoreIndex; CoreIndex++)
  {
    // Retrieve checkpoint control 
    MTSI_t_CheckpointControl * const p_CheckpointCtrl = StatisticControl[CoreIndex].p_CheckpointControl;
  
    // set default values
    p_CheckpointCtrl->WriteIndex    = 0u;

    // Clear checkpoints 
    MTSI_StatsClearCheckpoints(CoreIndex);
  
    // Add size to static statistics
    StaticStatistics.ModuleConfig.StatisticConfig.NumberOfCheckpoints[CoreIndex] = p_CheckpointCtrl->Size;
  }
}


static void CheckDynamicStatisticData(MTSI_t_DynamicStatisticData * const p_DynamicStatisticData)
{
  // Check pointer validity 
  if( NULL != p_DynamicStatisticData )
  {
    // Check if values has already been initialized 
    if( b_FALSE == p_DynamicStatisticData->DataInitialized )
    {
      // Initialize with current values 
      p_DynamicStatisticData->AllTimeLow  = p_DynamicStatisticData->CurrentValue;
      p_DynamicStatisticData->AllTimeHigh = p_DynamicStatisticData->CurrentValue;
      
      // Set initialization flag 
      p_DynamicStatisticData->DataInitialized = b_TRUE;
    }
    else
    {    
      // Check for all time high and low 
      if( p_DynamicStatisticData->AllTimeLow > p_DynamicStatisticData->CurrentValue )
      {
        // Set new all time low value 
        p_DynamicStatisticData->AllTimeLow = p_DynamicStatisticData->CurrentValue;
      }
      else if( p_DynamicStatisticData->AllTimeHigh < p_DynamicStatisticData->CurrentValue )
      {
        // Set new all time high value 
        p_DynamicStatisticData->AllTimeHigh = p_DynamicStatisticData->CurrentValue;
      }
      else
      {
        // Nothing needs to be done 
      }
    }
  }
}


static void StoreCheckpoint(const uint8 CheckpointMainId, const uint8 CheckpointSubId, const uint8 CoreId, const uint8 ReferenceId, MTSI_t_Header const * const p_Header)
{
  // Get appropriate checkpoint control
  MTSI_t_CheckpointControl * const p_CheckpointCtrl = StatisticControl[CoreId].p_CheckpointControl;

  // Enter exclusive area
  (void)MTSI_PalEnterExclusiveArea();

  // Check status of list (hereby it is implicitly checked if checkpoints are enabled)
  if( p_CheckpointCtrl->Size > p_CheckpointCtrl->WriteIndex )
  {
    // Get checkpoint entry
    /* PRQA S 491 1 */ /* Array subscription of pointer required because of generic module structure. */
    MTSI_t_Checkpoint * const p_Checkpoint = &p_CheckpointCtrl->p_Checkpoints[p_CheckpointCtrl->WriteIndex];

    /* Set checkpoint identifier */ /* PRQA S 3120 64 */ /* Hard-coded numbers required for clear representation of bit masks. */
    p_Checkpoint->CheckpointIdentifier = (uint8)(CheckpointMainId + CheckpointSubId);

    // Store reference id
    p_Checkpoint->ReferenceIdentifier = ReferenceId;
  
    // Store header info if available
    if( NULL != p_Header )
    {
      p_Checkpoint->TaskIdentifier = p_Header->TaskIdentifier;
      p_Checkpoint->VirtualAddress = p_Header->VirtualAddress;
    }
    else
    {
      p_Checkpoint->TaskIdentifier = 0u;
      p_Checkpoint->VirtualAddress = 0u;
    }

    // Increment write index
    p_CheckpointCtrl->WriteIndex++;
  }
  else
  {
    MTSI_StatsSetEvent(MTSI_EVENT_TYPE_MARKER, ((uint8)MTSI_STATS_CHKP_STORE_ERR_C0 + CoreId), (uint8)MTSI_CHKPT_ERR_ID_0);
  }

  //exit exclusive area
  MTSI_PalExitExclusiveArea();
}

#define MTSI_STOP_SEC_CODE_ASIL_B
#include <MTSI_MemMap_Cfg.h>

#ifdef __cplusplus
}
#endif
