// Copyright (C) Continental AG
// All Rights Reserved
// COMPONENT: MTSI
// VERSION:   $Revision: 1.28 $  
/// @file


#ifndef Meas_H
#define Meas_H
// PRQA S 0388, 0810 6
// Msg(3:0388) [L] '#include glob_comp_id.h and glob_type.h ' causes nesting to exceed 15 levels - program does not conform strictly to ISO:C99.
// Msg(3:0810) [L] '#include glob_comp_id.h and glob_type.h' causes nesting to exceed 8 levels - program does not conform strictly to ISO:C90.
// reason: solve preliminary, SW architecture problem
// Reviewed by P. Andrei on 2019-09-10
#include "glob_comp_id.h"
#include "glob_type.h"

#ifdef __cplusplus
extern "C"
{
#endif


/// @brief LEGACY: Function ID
/// 
/// Only used to support old implementations.
typedef uint8 MEASFuncID_t;

/// @brief LEGACY: Function channel ID
/// 
/// Only used to support old implementations.
typedef uint8 MEASFuncChannelID_t;

/// @brief    LEGACY: Freeze info
/// 
/// Only used to support old implementations.
typedef struct
{
  uint32 VirtualAddress;
  uint32 Length;
  MEASFuncID_t FuncID;
  MEASFuncChannelID_t FuncChannelID;
} MEASInfo_t;

/// @brief LEGACY: Meas freeze callback function
/// 
/// Only used to support old implementations.
typedef void (*MEAS_Callback_t)(void);

/// @brief LEGACY: Return values of Meas freeze function
/// 
/// Only used to support old implementations.
typedef enum {
  MTS_LC_CONFIG_1 = 0,
  MTS_LC_CONFIG_2 = 1,
  MTS_LC_CONFIG_3 = 2,
  MTS_LC_CONFIG_4 = 3,
  MTS_LC_ALL_OFF_EMV = 248,
  MTS_LC_ALL_OFF = 249,
  MTS_LC_ERR = 250,
  MTS_LC_UNDEF = 251
} MTS_LaneConfig;

/// Only used to support old implementations.
typedef enum {
  MEAS_OK = 0,                                          ///< No error
    MEAS_NOT_OK = 1,                                      ///< Error
    MEAS_JOB_LIMIT = 2,                                   ///< Error: Job limit
    MEAS_FULL_BUFFER = 3,                                 ///< Error: Full buffer
    MEAS_BAD_GROUP_ID = 4,                                ///< Error: Bad group ID
    MEAS_BAD_DATA_ALIGNMENT = 5,                          ///< Error: Bad data alignment
    MEAS_CALL_FROM_IRQ_LEVEL = 6,                         ///< Error: Call from IRQ level
    MEAS_JOB_REJECTED = 7,                                ///< Error: Job rejected in start phase
    MEAS_BUFFER_SIZE_TOO_BIG = 8,                         ///< Error: Buffer size too big
    MEAS_INFOBLOCK_WRONG = 9,                             ///< Error: Meas Infoblock wrong
    MEAS_SYNC_JOB_ACCEPTED =10,                           ///< Sync job accepted
    MEAS_SYNC_JOB_REJECTED_NO_BUFFER = 11,                ///< Error: No buffer is available to store the job
    MEAS_SYNC_JOB_REJECTED_FULL_BUFFER  = 12,             ///< Error: Freeze length exceeds buffer size
    MEAS_MUTEX_NOT_ENTERED = 13,                          ///< Error: Mutex region has not been entered
    MEAS_SYNC_JOB_INVALID_CORE_ID = 14,                   ///< Error: Invalid core id
    MEAS_SYNC_JOB_INVALID_INPUT_PARAM = 15,               ///< Error: Invalid input parameters
    MEAS_ASYNC_JOB_ACCEPTED = 16,                         ///< Async job accepted
    MEAS_ASYNC_JOB_REJECTED_QUEUE_FULL = 17,              ///< Error: Queue is full
    MEAS_ASYNC_JOB_REJECTED_QUEUE_ZERO = 18,              ///< Error: Size of queue is 0
    MEAS_ASYNC_JOB_INVALID_CORE_ID = 19,                  ///< Error: Invalid core id
    MEAS_ASYNC_JOB_INVALID_INPUT_PARAM = 20,              ///< Error: Invalid input parameters
    MEAS_PRIO_JOB_ACCEPTED = 21,                          ///< Prio job accepted
    MEAS_PRIO_JOB_REJECTED_QUEUE_FULL = 22,               ///< Error: Queue is full
    MEAS_PRIO_JOB_REJECTED_QUEUE_ZERO = 23,               ///< Error: Size of queue is 0
    MEAS_PRIO_JOB_INVALID_CORE_ID = 24,                   ///< Error: Invalid core id
    MEAS_PRIO_JOB_INVALID_INPUT_PARAM = 25,               ///< Error: Invalid input parameters
    MEAS_FREEZE_DATA_INVALID_ADD = 26,                    ///< Error: Invalid virtual address
    MEAS_FREEZE_DATA_INPUT_PARAM = 27,                    ///< Error: Invalid input parameters
    MEAS_FREEZE_FORCED_SYNC_FREEZE_LENGTH = 28,           ///< Error: Component forced a sync freeze (callback was null), but it exceeded the lenght limit
    MEAS_NOT_INITIALIZED = 29,                            ///< Error: Initialization not completed (pre-initialized)
    MEAS_RETURN_FORCE_32 = 65536                          ///< Should not be used - force to 32 bits.
} MEASReturn_t;

//    User explicit entries


// Operations

/// @brief  LEGACY: Freeze MTS data
/// 
/// Only used to support old implementations.
/// Shall be replace as far as the new interface is available.  
///
/// @pre
///   none
/// @post
///   none
/// @param  [In] p_MeasInfo  :  Info about current meas freeze
/// @param  [In] p_MeasData  : Data to be sent
/// @param  [In] p_MeasFct   : Callback function of this meas freeze
///
/// @return MEASReturn_MEASFreezeDataMTS
///
/// @globals
///   none
/// @InOutCorrelation
///   Information about freeze.
///   This function set VirtualAddress, Length and FunctionId for meas freeze
/// @callsequence
/// @image html MEASFreezeDataMTS_diargam.png Sequence Diagram
/// @startuml "MEASFreezeDataMTS_diargam.png"
/// title Sequence diagram for MEASFreezeDataMTS
/// participant ENV
/// participant MTSI as MTSIA
/// participant MTSI as MTSIB
/// activate ENV
/// ENV --> MTSIA : MEASFreezeDataMTS(const MEASInfo_t * p_MeasInfo, void * p_MeasData, MEAS_Callback_t p_MeasFct)
/// activate MTSIA
/// note over MTSIA : Get information \nabout freeze
/// MTSIA -> MTSIB: MTSI_FreezeData(&FreezeInfo, p_MeasData, p_MeasFct)
/// activate MTSIB
/// MTSIA <- MTSIB: MEASReturn_MEASFreezeDataMTS
/// deactivate MTSIB
/// MTSIA-> ENV : MEASReturn_MEASFreezeDataMTS=MEAS_OK
/// deactivate MTSIA
/// deactivate ENV
/// @enduml
/// @testmethod
///   1) @ref TEST_MEASFreezeDataMTS_1 : Coverage for function, in case of valid input parameters, and setting the  VirtualAddress, Length FunctionId and additional option for meas freeze. \n
/// @traceability
///   <a href="doors://RBGS854A:40000/?version=2&prodID=0&view=00000006&urn=urn:telelogic::1-503e822e5ec3651e-O-460-0005ebe0"><strong> MEASFreezeDataMTS L4 Design Specification</strong></a>

// PRQA S 3208, 3209 5
// Msg(3:3208) 'MEASFreezeDataMTS()' returns a value which is sometimes ignored.
// Msg(3:3209) 'MEASFreezeDataMTS()' returns a value which is always ignored.
// Reason: evaluation of returned value by MEASFreezeDataMTS function is in the responsibility of the caller of the function
// Reviewed by P. Andrei on 2019-09-17
MEASReturn_t MEASFreezeDataMTS(const MEASInfo_t * p_MeasInfo, void * p_MeasData, MEAS_Callback_t p_MeasFct);

#ifdef __cplusplus
}
#endif
#endif


