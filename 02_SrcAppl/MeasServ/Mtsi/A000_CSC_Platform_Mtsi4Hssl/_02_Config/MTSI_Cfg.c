/***********************************************************************************
  COMPANY:     Continental Automotive
  PROJECT:     Mainstream
  MODULENAME:  MTSI
  VERSION:     $Revision: 1.6 $
 **********************************************************************************/
#include <MTSI_Cfg_Int.h>
#include <glob_defs.h>
#include "MTSI_Driver.h"

/** @defgroup Configuration Configuration Code
 *  @{
 */

 /** @defgroup MTSI_CFG MTSI_CFG
 *  @{
 */

#ifdef __cplusplus
extern "C"
{
#endif

/* PRQA S 3678 EOF *//* "The object referenced by '%1s' is not modified through it, so '%1s' could be declared with type '%2s'. */
/* QAF detects the data structures are not modified within this unit and suggests adding the "const" type-qualifier,
 * but they are modified outside the unit, so it cannot be done. */
/* PRQA S 0612 EOF *//* "[L] Size of object '%s' exceeds 32767 bytes - program does not conform strictly to ISO:C90. */
/* The MTSI functionality requires buffers with a greater size */
/* PRQA S 0779 EOF *//* "[U] Identifier does not differ from other identifier(s) (e.g. '%s') within the specified number of significant characters." */
/* Not a problem - proven in use. */
/* PRQA S 3120 EOF *//* "Hard-coded 'magic' integer constant, '%s'." */
/* This is a generated file; readability and maintainability are not affected. */

/* PRQA S 0342 2 *//* "Using the glue operator '##'." *//* Required for the generic implementation of the generated code. */
/** @brief    Macro to get the size of a toggle buffer */
#define MTSI_GET_SIZE_OF_TOGGLE_BUFFER(CoreId) (CFG_MTSI_SIZE_OF_SYNC_BUFFER_CORE_##CoreId / CFG_MTSI_NUMBER_OF_TOGGLE_BUFFERS)

/** @brief Define for init var on asil b with unspecified cache */
#define MTSI_START_SEC_VAR_INIT_ASIL_B_CACHED_UNSPECIFIED
#include <MTSI_MemMap_Cfg.h>


//******************************************************************************************************************************
// CORE 0 Data
//******************************************************************************************************************************

/** @brief      Sync buffer of core 0.
       Buffer to handle the synchronous jobs of core 0.
       Size of buffer has to be defined at MTSI_Cfg.h.
*/
static uint8 SyncBufferCore0[CFG_MTSI_NUMBER_OF_TOGGLE_BUFFERS][MTSI_GET_SIZE_OF_TOGGLE_BUFFER(0)] CFG_MTSI_DECLARATION_ATTRIBUTE = { { 0u }, { 0u } };

/** @brief      Control variable of first toggle buffer for core 0.
       Contains all required information to handle the first toggle buffer of core 0.
*/
static t_ToggleBuffer SyncBufferControlCore0_ToggleBuffer0 CFG_MTSI_DECLARATION_ATTRIBUTE = { BUFFER_STATE_FREE, MTSI_GET_SIZE_OF_TOGGLE_BUFFER(0), 0u, &SyncBufferCore0[0][0] };

/** @brief      Control variable of second toggle buffer for core 0.
       Contains all required information to handle the second toggle buffer of core 0.
*/
static t_ToggleBuffer SyncBufferControlCore0_ToggleBuffer1 CFG_MTSI_DECLARATION_ATTRIBUTE = { BUFFER_STATE_FREE, MTSI_GET_SIZE_OF_TOGGLE_BUFFER(0), 0u, &SyncBufferCore0[1][0] };

/** @brief      Sync buffer control variable for core 0.
       Contains all required information to handle the sync buffer of core 0.
*/
static t_SyncBufferControl SyncBufferControlCore0 CFG_MTSI_DECLARATION_ATTRIBUTE = {
  CFG_MTSI_SIZE_OF_SYNC_BUFFER_CORE_0, CFG_MTSI_LANE_FOR_SYNC_BUFFER_CORE_0, 0u, 0u, 0u,
  {
    &SyncBufferControlCore0_ToggleBuffer0,
    &SyncBufferControlCore0_ToggleBuffer1
  }
};

/** @brief      Async queue of core 0.
       Queue to handle the asynchronous jobs of core 0.
       Size of queue has to be defined at MTSI_Cfg.h.
       An extra element is necessary for each lane
       due to the kind of queue handling (queue-head, queue-tail).
*/
static t_AsyncJob AsyncQueueCore0[CFG_MTSI_SIZE_OF_ASYNC_QUEUE_CORE_0 + CFG_MTSI_NUMBER_OF_LANES] CFG_MTSI_DECLARATION_ATTRIBUTE  = { { { 0u }, 0u, 0u } };
static t_AsyncJob AsyncQueueCore1[CFG_MTSI_SIZE_OF_ASYNC_QUEUE_CORE_1 + CFG_MTSI_NUMBER_OF_LANES] CFG_MTSI_DECLARATION_ATTRIBUTE  = { { { 0u }, 0u, 0u } };
static t_AsyncJob AsyncQueueCore2[CFG_MTSI_SIZE_OF_ASYNC_QUEUE_CORE_2 + CFG_MTSI_NUMBER_OF_LANES] CFG_MTSI_DECLARATION_ATTRIBUTE  = { { { 0u }, 0u, 0u } };
static t_AsyncJob AsyncQueueCore3[CFG_MTSI_SIZE_OF_ASYNC_QUEUE_CORE_3 + CFG_MTSI_NUMBER_OF_LANES] CFG_MTSI_DECLARATION_ATTRIBUTE  = { { { 0u }, 0u, 0u } };

/** @brief      Control variable of async queue for lane 0 at core 0.
      Contains all required information to handle the async queue for lane 0 of core 0.
*/
static t_AsyncQueue AsyncQueueControlCore0_AsyncQueueLane0 CFG_MTSI_DECLARATION_ATTRIBUTE = { CFG_MTSI_SIZE_OF_ASYNC_QUEUE_CORE_0, 0u, 0u, 0u, &AsyncQueueCore0[0] };
static t_AsyncQueue AsyncQueueControlCore1_AsyncQueueLane0 CFG_MTSI_DECLARATION_ATTRIBUTE = { CFG_MTSI_SIZE_OF_ASYNC_QUEUE_CORE_1, 0u, 0u, 0u, &AsyncQueueCore1[0] };
static t_AsyncQueue AsyncQueueControlCore2_AsyncQueueLane0 CFG_MTSI_DECLARATION_ATTRIBUTE = { CFG_MTSI_SIZE_OF_ASYNC_QUEUE_CORE_2, 0u, 0u, 0u, &AsyncQueueCore2[0] };
static t_AsyncQueue AsyncQueueControlCore3_AsyncQueueLane0 CFG_MTSI_DECLARATION_ATTRIBUTE = { CFG_MTSI_SIZE_OF_ASYNC_QUEUE_CORE_3, 0u, 0u, 0u, &AsyncQueueCore3[0] };


/** @brief      Async queue control variable for core 0.
       Contains all required information to handle the async queues of core 0.
*/
static t_AsyncQueueControl AsyncQueueControlCore0 CFG_MTSI_DECLARATION_ATTRIBUTE = {
  {
    &AsyncQueueControlCore0_AsyncQueueLane0,
  }
};
static t_AsyncQueueControl AsyncQueueControlCore1 CFG_MTSI_DECLARATION_ATTRIBUTE = {
  {
    &AsyncQueueControlCore1_AsyncQueueLane0,
  }
};
static t_AsyncQueueControl AsyncQueueControlCore2 CFG_MTSI_DECLARATION_ATTRIBUTE = {
  {
    &AsyncQueueControlCore2_AsyncQueueLane0,
  }
};
static t_AsyncQueueControl AsyncQueueControlCore3 CFG_MTSI_DECLARATION_ATTRIBUTE = {
  {
    &AsyncQueueControlCore3_AsyncQueueLane0,
  }
};

/** @brief      Dynamic statistic data of MTSI module regarding core 0.
      Contains performance data, etc. of core 0.
*/
/*! @vaddr: MTSI_GET_DYNAMIC_STATS_VIRT_ADDR(0, 0)  @vname: MTSI_DynamicStatisticsCore0 @cycleid: MTSI_CYCLIC_10MS */
static MTSI_t_DynamicStatistics DynamicStatisticsCore0[CFG_MTSI_NUMBER_OF_LANES] = { { { 0u }, { 0u }, { 0u  } } };

/** @brief      Control variable for dynamic statistics of core 0
      Control over dynamic statistic data of core 0.
*/
static MTSI_t_DynamicStatisticControl DynamicStatisticControlCore0 = {
  {
    &DynamicStatisticsCore0[0u]
  }
};

/** @brief    Virtual address of MTSI checkpoints of core 0 */
#define MTSI_CHECKPOINTS_CORE_0_VIRT_ADDR MTSI_CHECKPOINTS_VIRT_ADDR

/** @brief      Checkpoint list of core 0.
      Contains all checkpoints related to core 0.
*/
/*! @vaddr: MTSI_CHECKPOINTS_CORE_0_VIRT_ADDR  @vname: MTSI_CheckpointsCore0 @cycleid: MTSI_CYCLIC_10MS */
static MTSI_t_Checkpoint CheckpointsCore0[CFG_MTSI_NUMBER_OF_CHECKPOINTS_CORE_0] = { { 0u } };

/** @brief      Control variable for checkpoints of core 0.
      Control over all checkpoints of core 0.
*/
static MTSI_t_CheckpointControl CheckpointControlCore0 = { CFG_MTSI_NUMBER_OF_CHECKPOINTS_CORE_0, 0u, CheckpointsCore0 };




#define MTSI_STOP_SEC_VAR_INIT_ASIL_B_CACHED_UNSPECIFIED
#include <MTSI_MemMap_Cfg.h>

//******************************************************************************************************************************
// Generic Data
//******************************************************************************************************************************

#define MTSI_START_SEC_CODE_ASIL_B
#include <MTSI_MemMap_Cfg.h>

/** @brief    Main control of job handling.
 Contains all required information to handle
 both synchronous and asynchronous jobs.
*/
const t_MainControl MainControl[CFG_MTSI_NUMBER_OF_CORES] =
{
  // Add references to control variables of core 0,1,2,3 but use the same sync buffer for all cores
  { &SyncBufferControlCore0, &AsyncQueueControlCore0 },
  { &SyncBufferControlCore0, &AsyncQueueControlCore1 },
  { &SyncBufferControlCore0, &AsyncQueueControlCore2 },
  { &SyncBufferControlCore0, &AsyncQueueControlCore3 },

};

/** @brief    Control variable of statistic data */
const MTSI_t_StatisticControl StatisticControl[CFG_MTSI_NUMBER_OF_CORES] =
{
  // Add references to control variables of core 0
  { &DynamicStatisticControlCore0, &CheckpointControlCore0 },
  { &DynamicStatisticControlCore0, &CheckpointControlCore0 },
  { &DynamicStatisticControlCore0, &CheckpointControlCore0 },
  { &DynamicStatisticControlCore0, &CheckpointControlCore0 },

};

#ifdef __cplusplus
}
#endif
/** @} doxygen end group definition  */

/** @} doxygen end group definition  */
