/***********************************************************************************
  COMPANY:     Continental Automotive
  PROJECT:     Mainstream
  MODULENAME:  MTSI
  VERSION:     $Revision: 1.5 $
 **********************************************************************************/
#ifndef MTSI_Cfg_H
#define MTSI_Cfg_H

#include <Std_Types.h>
#include "Time.h"
#ifdef __cplusplus
extern "C"
{
#endif

/** @brief    	Major version of MTSI module
 Major version must be set as defined in the mainstream concept.
 @range    	0 - 999
*/ 
#define MTSI_MODULE_MAJOR_VERSION (uint16)15


/** @brief   	Minor version of MTSI module
 Minor version must be set as defined in the mainstream concept.
 @range    	0 - 99
*/
#define MTSI_MODULE_MINOR_VERSION (uint8)0


/* @brief    	Patch version of MTSI module
 Patch version must be set as defined in the mainstream concept.
 @range    	0 - 99
*/
#define MTSI_MODULE_PATCH_VERSION (uint8)0

/** @brief Size of sync buffer for core 0.
 Size of the core specific sync buffer, where the synchronous jobs are stored.
 Value should be a multiple of CFG_MTSI_NUMBER_OF_TOGGLE_BUFFERS to avoid inconsistencies.
 Range: 0 - 0xFFFFFFFF
*/
#define CFG_MTSI_SIZE_OF_SYNC_BUFFER_CORE_0 1024u

/** @brief Lane for core 0 sync buffer.
 The lane on which the sync buffer for core 0 shall be sent.
 Range: 0 - (CFG_MTSI_NUMBER_OF_LANES - 1)
*/
#define CFG_MTSI_LANE_FOR_SYNC_BUFFER_CORE_0 0u

/** @brief Size of async queue for core X.
 Size of the core specific queue, where the asynchronous jobs are stored.
 The queue is separated into inferior queues for each lane.
 Range: 0 - 0xFFFF
 @attention DEPPER THE QUEUE SET, LARGER PERIOD OF MTSI MAIN TASK SHOULD BE SETS !!!
*/
#define CFG_MTSI_SIZE_OF_ASYNC_QUEUE_CORE_0 100u
#define CFG_MTSI_SIZE_OF_ASYNC_QUEUE_CORE_1 100u
#define CFG_MTSI_SIZE_OF_ASYNC_QUEUE_CORE_2 10u
#define CFG_MTSI_SIZE_OF_ASYNC_QUEUE_CORE_3 200u

/** @brief Compare function macro for finding bigger queue size of 2 queues.
*/
#define BIGGER_QUEUE(a,b) ((a)>(b) ? (a):(b))

/** @brief Find the biggest queue size among the implementation above
 * 
*/
#define CFG_MTSI_SIZE_OF_ASYNC_QUEUE_MAX \
BIGGER_QUEUE(CFG_MTSI_SIZE_OF_ASYNC_QUEUE_CORE_0,\
BIGGER_QUEUE(CFG_MTSI_SIZE_OF_ASYNC_QUEUE_CORE_1,\
BIGGER_QUEUE(CFG_MTSI_SIZE_OF_ASYNC_QUEUE_CORE_2,\
CFG_MTSI_SIZE_OF_ASYNC_QUEUE_CORE_3)))

/** @brief Maximum number of checkpoints for core 0.
 Maximum number of MTSI checkpoints that can be set for this core. The overall number of checkpoints for all
 cores must not exceed 0x1000.
 Range: 0 - 255
*/
#define CFG_MTSI_NUMBER_OF_CHECKPOINTS_CORE_0 16u

/** @brief Master core for MTSI 
 * Range: 0 - 3
*/
#define CFG_MTSI_MASTER_CORE  3u


/** @brief Number of cores for which MTSI is configured.
    Range: 1 - 10
 */
#define CFG_MTSI_NUMBER_OF_CORES 4u

/** @brief Number of lanes on which data output is possible.
 Range: 1 - 10
*/
#define CFG_MTSI_NUMBER_OF_LANES 1u

/** @brief Number of toggle buffers for each core.
 In case a buffer is full or just transmitted, new data can be written in the next buffer.
 At the moment it is intended to have exactly 2 toggle buffers.
 Range: 2
*/
#define CFG_MTSI_NUMBER_OF_TOGGLE_BUFFERS 2u

/** @brief Minimum size of an asynchronous job.
 The minimum allowed data size of an asynchronous job.
 If the size is less, the job will be handled like a synchronous job.
 Range: 0 - UINT32_MAX
*/
#define CFG_MTSI_MINIMUM_SIZE_OF_ASYNC_JOB 10uL 

/** @brief Use function id in MTS header.
 This flag indicates if a function id shall be used in MTS packet header.
 Range: FALSE, TRUE
*/
#define CFG_MTSI_HEADER_USE_FUNCTION_ID FALSE

/** @brief Use packet counter in MTS header.
 This flag indicates if a packet counter shall be used in MTS packet header.
 Range: FALSE, TRUE
*/
#define CFG_MTSI_HEADER_USE_PACKET_COUNTER FALSE

/** @brief Use high resolution timestamp in MTS header.
 This flag indicated if a high resolution timestamp shall be used in MTS packet header.
 Range: FALSE, TRUE
*/
#define CFG_MTSI_HEADER_USE_HIGH_RES_TIMESTAMP TRUE

/** @brief Use absolute timestamp in MTS header.
 This flag indicates if an absolute timestamp shall be used in MTS packet header
 Range: FALSE, TRUE
*/
#define CFG_MTSI_HEADER_USE_ABSOLUTE_TIMESTAMP TRUE

/** @brief Use checksum in MTS header.
 This constant indicates if a checksum shall be used in MTS packet header.
 Range: 0 - 2 (None, MISC, CRC-32)
*/
#define CFG_MTSI_HEADER_USE_CHECKSUM 0u

/** @brief Number of header padding bytes.
 The number of padding bytes that must be added to the MTS packet header.
 Padding bytes can be used to adapt the header size to the platform specific byte alignment.
 Range: 0 - 0xFFFF
*/
#define CFG_MTSI_HEADER_NUMBER_OF_PADDING_BYTES 6u

/** @brief Maximum number of tasks.
 The maximum number of tasks which must be supported.
 Range: 0 - 255
*/
#define CFG_MTSI_MAXIMUM_NUMBER_OF_TASKS 30u

/** @brief Byte alignment of meas freezes.
 Depending on the used HW interface, it might be necessary to apply a byte alignment for meas freezes
 Range: 1 - 8
*/
#define CFG_MTSI_MEAS_FREEZE_BYTE_ALIGNMENT 4u

/** @brief Cycle time of cyclic runnable.
 Cycle time in milliseconds in which the main function shall be called.
 Range: 0 - 0xFFFF
*/
#define CFG_MTSI_CYCLE_TIME_CYCLIC_RUNNABLE 20u

/** @brief Cycle time in ms for static statistic data.
 Cycle time in milliseconds in which static statistic data shall be sent.
 Range: 0 - 0xFFFF
*/
#define CFG_MTSI_STATISTICS_CYCLE_TIME_MS 1000u

/** @brief Task id of data that is sent at the start of an MTA frame.
 The least significant half-byte indicates the related lane.
 Lane 0 : 0xFFF0
 Lane 1 : 0xFFF1
 ...
*/
#define CFG_MTSI_MTA_FRAME_TASK_BASE_ID (uint16)100

/** @brief Enable/disable MTSi specific test code
  Range: FALSE, TRUE
*/
#define CFG_MTSI_TST_ENABLED FALSE

/** @brief Macro used to enble/Disable the Static & Dynamic MTSi statistic data.
*/
#define MTSI_ENABLE_STATISTIC_DATA TRUE

/** @brief Macro used to enble/Disable the RTA instrumentation.
*/
#define CFG_MTSI_RTA_USAGE_ENABLED FALSE

/** @brief Declaration attribute: for alignament purposes
*/
#define CFG_MTSI_DECLARATION_ATTRIBUTE __attribute__((aligned (64)))

/** @brief    Virtual address of static statistics. */
#define MTSI_STATIC_STATS_VIRT_ADDR 0x80050500uL

/** @brief Total number of checkpoints in all configured cores. This is required for calculating the VirtualAddress range required for the Checkpoints freeze. */
#define MTSI_TOTAL_NB_OF_CHECKPOINTS 16u

/// @brief  Unique identifier of data source across all projects:\n
/// 4 Bit for data channel (optional; zero, if not used) + 12 Bit for SW component
/* MTSI */
#define MTSI_FUNCTION_ID_MTSI         (uint16)0x0085
#define MTSI_FUNCTION_ID_MTSI_STATIC  (uint16)0x4085
#define MTSI_FUNCTION_ID_MTSI_MTA     (uint16)0x5085
/*****************************************************************************************************************/
// Custom Parameters
/*****************************************************************************************************************/
#define CFG_MTSI_AURIX_TC38X
/** @brief Resolution of timestamp source used for SW packet timestamps 
 * 1,000,000 for millisecond, 1,000 for microsecond
*/
#define MTSI_TIME_BASE_RESOLUTION 1000uL
/** @brief  */
#define CFG_MTSI_HSSL_FIRST_FRAGMENT_OFFSET 8u 
/** @brief  */
#define CFG_MTSI_HSSL_BYTE_ALIGNMENT 32u 

/*Interface configuration*/
#define MTSI_GetCoreID                          GetCoreID
#define MTSI_GetTimeStampMs                     Time_GetTimeStampMs
#define MTSI_GetTimeStampSec                    Time_GetTimeStampSec


#ifdef __cplusplus
}
#endif

#endif
