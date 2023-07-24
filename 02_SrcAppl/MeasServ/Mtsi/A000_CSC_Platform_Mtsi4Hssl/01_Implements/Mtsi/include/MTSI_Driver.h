// Copyright (C) Continental AG
// All Rights Reserved
// COMPONENT: MTSI
// VERSION:   $Revision: 1.4 $ 

#ifndef MTSI_Driver_H
#define MTSI_Driver_H

#include <MTSI_Types.h>
#include <Meas.h>

#ifdef __cplusplus
extern "C"
{
#endif

/// Operations
/// @brief      Initialization of MTSI driver module
/// @pre        The statistic module must be initialized previously
/// @post       Accomplish initialization of PAL and custom module.
///             Initialize the synchronous buffers and asynchronous queues for all cores.
/// @param      none
/// @return     void
/// @globals    @ref ModuleState [MODULE_PREINITIALIZED, MODULE_INITIALIZED, MODULE_DE_INIT_REQUESTED, MODULE_DEINITIALIZED]
/// @InOutCorrelation
///   ModuleState is set to MODULE_PREINITIALIZED or MODULE_INITIALIZED if the calls for PreInit or PostInit functions were successfully finished after ModuleState was MODULE_UNINITIALIZED.
/// @callsequence
/// @image html MTSI_DriverInit.png Sequence Diagram
/// @testmethod
///   1) @ref TEST_MTSI_DriverInit_1 : test functionality for all possible module states: initialized, deinitialized, uninitialized, preinitialized. \n
/// @traceability
///   <a href="doors://RBGS854A:40000/?version=2&prodID=0&view=00000006&urn=urn:telelogic::1-503e822e5ec3651e-O-675-0005ebe0"><strong> MTSI_DriverInit L4 Design Specification</strong></a>
void MTSI_DriverInit(void);


/// @brief    Deinitialization of MTSI driver module
/// @pre      none
/// @post     none
/// @param    none
/// @return   void
/// @globals  none
/// @InOutCorrelation
///   If no MTA frame is active it will finalize the de-initialization and change the module state to MODULE_DEINITIALIZED,
///   otherwise the de-initialization of module is requested (postponed) and ModuleState is set to MODULE_DE_INIT_REQUESTED.
/// @callsequence
/// @image html MTSI_DriverDeInit.png Sequence Diagram
/// @testmethod
///   1) @ref TEST_MTSI_DriverDeInit_1 : test functionality for correct de-initialization of driver module in case no MTA frame is currently active. \n
/// @traceability
///   <a href="doors://RBGS854A:40000/?version=2&prodID=0&view=00000006&urn=urn:telelogic::1-503e822e5ec3651e-O-676-0005ebe0"><strong> MTSI_DriverDeInit L4 Design Specification</strong></a>
void MTSI_DriverDeInit(void);


/// @brief  Cyclic runnable for the MTSi functionality. It handles the periodic sending of the statistic/checkpoint data
///         and triggers the cyclic transmission of the MTSi data. Also triggers the post initialization phase at startup.
/// @pre    This runnable must be called every 10ms by the BSW.
/// @post   none
/// @param  none
/// @return void
/// @globals
///   @ref ModuleState [MODULE_PREINITIALIZED, MODULE_INITIALIZED, MODULE_DE_INIT_REQUESTED, MODULE_DEINITIALIZED] \n
///   @ref CounterStaticStatistics \n
/// @InOutCorrelation none
/// @callsequence
/// @image html MTSI_DriverMainFunction.png Sequence Diagram
/// @testmethod
///   1) @ref TEST_MTSI_DriverMainFunction_1 : test functionality when the cyclic statistic/checkpoint transmission is active/inactive. Cover post-initialization phase. \n
/// @traceability
///   <a href="doors://RBGS854A:40000/?version=2&prodID=0&view=00000006&urn=urn:telelogic::1-503e822e5ec3651e-O-677-0005ebe0"><strong> MTSI_DriverMainFunction L4 Design Specification</strong></a>
void MTSI_DriverMainFunction(void);


/// @brief  Create MTS packet header regarding given freeze information
/// @pre    none
/// @post   none
/// @param[in]      p_FreezeInfo  Information about MTS freeze \n
/// @param[in]      p_Header      MTS packet header \n
/// @param[out]     p_Header      MTS packet header
/// @return   void
/// @globals  none
/// @InOutCorrelation
///   If the input data for the requested freeze and header are valid, it will update the virtual address, control field and pay-load length,
///   task identifier, task counter, timestamp and the padding bytes within the Header structure, otherwise it will set a checkpoint(error).
/// @callsequence
/// @image html MTSI_DriverPrepareHeader.png Sequence Diagram
/// @testmethod
///   1) @ref TEST_MTSI_DriverPrepareHeader_1 :test functionality for both valid/invalid input parameters. (valid/invalid Header/FreezeInfo references) \n
/// @traceability
///   <a href="doors://RBGS854A:40000/?version=2&prodID=0&view=00000006&urn=urn:telelogic::1-503e822e5ec3651e-O-679-0005ebe0"><strong> MTSI_DriverPrepareHeader L4 Design Specification</strong></a>
void MTSI_DriverPrepareHeader(MTSI_t_FreezeInfo const * const p_FreezeInfo, MTSI_t_Header* const p_Header);


/// @brief   Store synchronous job (buffered freeze)
///          Writes header and application provided data to the corresponding MTSI internal sync buffer.
/// @pre     MTSI module is initialized.
/// @post    Header and application provided data are written in the MTSI internal sync buffer.
/// @param[in] p_Header     Pointer to the MTS header for this job \n
/// @param[in] p_Data       Pointer to the data for this job \n
/// @param[in] p_Callback   Callback function for this job
/// @return  Return values of Meas freeze function
/// @globals @ref ModuleState [MODULE_PREINITIALIZED, MODULE_INITIALIZED, MODULE_DE_INIT_REQUESTED, MODULE_DEINITIALIZED]
/// @InOutCorrelation
///   Return no error (MEAS_OK) if no initialization is done, or other values of Meas freeze function when the initialization is done by to the appropriate buffer.
/// @callsequence
/// @image html MTSI_DriverStoreSyncJob.png Sequence Diagram
/// @testmethod
///   1) @ref TEST_MTSI_DriverStoreSyncJob_1 : test functionality for the use case where the MTSi driver is initialized. \n
///   2) @ref TEST_MTSI_DriverStoreSyncJob_2 : test functionality for the use case where the MTSi driver is not initialized. \n
/// @traceability
///   <a href="doors://RBGS854A:40000/?version=2&prodID=0&view=00000006&urn=urn:telelogic::1-503e822e5ec3651e-O-681-0005ebe0"><strong> MTSI_DriverStoreSyncJob L4 Design Specification</strong></a>
MEASReturn_t MTSI_DriverStoreSyncJob(MTSI_t_Header * const p_Header, void const * const p_Data, const MTSI_t_Callback p_Callback);


/// @brief    Store asynchronous job (unbuffered freeze)
/// @pre      MTSI module is initialized.
/// @post     Add asynchronous job to the corresponding core job queue
/// @param[in] LaneId   LaneId of lane on which job shall be sent \n
/// @param[in] p_Header   Pointer to the MTS header of this job \n
/// @param[in] p_Data     Pointer to the data of this job \n
/// @param[in] p_Callback   Callback function of this job
/// @return   Return values of Meas freeze function
/// @globals  @ref ModuleState [MODULE_PREINITIALIZED, MODULE_INITIALIZED, MODULE_DE_INIT_REQUESTED, MODULE_DEINITIALIZED]
/// @InOutCorrelation
///   Return no error (MEAS_OK) if no initialization is done, or other values of Meas freeze function when the initialization is done by to the appropriate queue.
/// @callsequence
/// @image html MTSI_DriverStoreAsyncJob.png Sequence Diagram
/// @testmethod
///   1) @ref TEST_MTSI_DriverStoreAsyncJob_1 : test functionality for the use case where the MTSi driver is initialized. \n
///   2) @ref TEST_MTSI_DriverStoreAsyncJob_2 : test functionality for the use case where the MTSi driver is not initialized. \n
/// @traceability
///   <a href="doors://RBGS854A:40000/?version=2&prodID=0&view=00000006&urn=urn:telelogic::1-503e822e5ec3651e-O-682-0005ebe0"><strong> MTSI_DriverStoreAsyncJob L4 Design Specification</strong></a>
MEASReturn_t MTSI_DriverStoreAsyncJob(const uint8 LaneId, MTSI_t_Header * const p_Header, void const * const p_Data, const MTSI_t_Callback p_Callback);


/// @brief  Start new MTA cycle
///         Finish the current MTA cycle and start a new one.
/// @pre    MTSI module is initialized.
/// @post   This function is not required in case the MTA cycle is handled by the PAL.
/// @param[in] LaneId  Lane on that new MTA frame shall be started
/// @return void
/// @globals
///   @ref ModuleState [MODULE_PREINITIALIZED, MODULE_INITIALIZED, MODULE_DE_INIT_REQUESTED, MODULE_DEINITIALIZED] \n
///   @ref LaneState
/// @InOutCorrelation
///   Module checks the internal state of the provided LaneId. If the state is IDLE, it shall trigger the lower level (PAL) actions
///   to reinitialize (stop/start) the MTA frame. If the Lane state is not IDLE, set a "reminder" flag, so that the Lane re-initialization
///   will be done once the ongoing transmission is completed. All the actions shall be done in the MTSI Exclusive Area.
///   If the lane state is idle, a new MTA frame will start.
/// @callsequence
/// @image html MTSI_DriverStartMTACycle.png Sequence Diagram
/// @testmethod
///   1) @ref TEST_MTSI_DriverStartMTACycle_1 : test functionality for the usecase where the module is neither initialized or deinitialization requested.  \n
///   2) @ref TEST_MTSI_DriverStartMTACycle_2 : test functionality when invalid parameters are provided (invalid LaneID). \n
///   3) @ref TEST_MTSI_DriverStartMTACycle_3 : test functionality with valid parameters and cover both cases where a MTA frame needs to be triggered now (LaneState is INIT/IDLE) or scheduled. \n
/// @traceability
///   <a href="doors://RBGS854A:40000/?version=2&prodID=0&view=00000006&urn=urn:telelogic::1-503e822e5ec3651e-O-683-0005ebe0"><strong> MTSI_DriverStartMTACycle L4 Design Specification</strong></a>
void MTSI_DriverStartMTACycle(const uint8 LaneId);


/// @brief  Start new task cycle
/// @pre    MTSI module is initialized.
/// @post   The requested task cycle is triggered.
/// @param[in] TaskId  Task, for which a new cycle shall be started.
/// @return void
/// @globals
///   @ref ModuleState [MODULE_PREINITIALIZED, MODULE_INITIALIZED, MODULE_DE_INIT_REQUESTED, MODULE_DEINITIALIZED]
/// @InOutCorrelation
///   The module shall search for the provided TaskID within the internal TaskInfo table.
///   If found, it shall increment the TaskCounter. (if it reached the limit of 65535 the counter will reset)
///   If not found, it shall create a new entry in the TaskInfo table for the provided TaskId.
/// @callsequence
/// @image html MTSI_DriverStartTaskCycle.png Sequence Diagram
/// @testmethod
///   1) @ref TEST_MTSI_DriverStartTaskCycle_1 : test functionality in the use-case where the MTSI driver module is not initialized. \n
///   2) @ref TEST_MTSI_DriverStartTaskCycle_2 : module is initialized, find valid NEW entry in the TaskInfo table. (TaskId not present before in the buffer) \n
///   3) @ref TEST_MTSI_DriverStartTaskCycle_3 : module is initialized, find valid OLD entry in the TaskInfo table, (TaskId present before in the buffer), TaskCounter less than MTSI_MAX_VALUE_TASK_COUNTER. \n
///   4) @ref TEST_MTSI_DriverStartTaskCycle_4 : module is initialized, find valid OLD entry in the TaskInfo table, (TaskId present before in the buffer), TaskCounter == MTSI_MAX_VALUE_TASK_COUNTER. \n
///   5) @ref TEST_MTSI_DriverStartTaskCycle_5 : module is initialized, no valid entry found in the TaskInfo table \n
/// @traceability
///   <a href="doors://RBGS854A:40000/?version=2&prodID=0&view=00000006&urn=urn:telelogic::1-503e822e5ec3651e-O-684-0005ebe0"><strong> MTSI_DriverStartTaskCycle L4 Design Specification</strong></a>
void MTSI_DriverStartTaskCycle(const uint16 TaskId);

#ifdef __cplusplus
}
#endif

#endif
