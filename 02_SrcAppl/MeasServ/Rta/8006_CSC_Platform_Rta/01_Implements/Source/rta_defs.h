// Copyright (C) Continental AG
// All Rights Reserved
// COMPONENT: RTA - RealTimeAnalysis
/// \file
/// \brief This header contains defines and type declarations which are used in multiple places in the RTA.

#ifndef RTA_DEFS_H
#define RTA_DEFS_H

#ifdef __cplusplus
extern "C"
{
#endif


/// This define can be used to mask the three least significant bits of an uint8 variable.
#define RTA_MASK_3_LSB ( (uint8) 0x7 )


/// This define simple defines the value 3. It can be used e.g. for shiftOperation in context of uint8 variables.
#define RTA_SHIFT_BY_3 ( (uint8) 0x3 )


/// This define is used to access 64-bit program counter address into two 32-bit variables.
#define RTA_SHIFT_BY_32 ( (uint8) (32) )


/// This define determines the number of erroneous cycles after which a recovery is done.
/// It is especially used for the errors RTA_BUFFER_NOT_FROZEN and  RTA_ASYNC_FREEZE_NOT_FINISHED.
#define RTA_CYCLES_TO_RECOVER (5uL)


/// This define is simple the value 100. It can be used to calculate the relative usage of the rtaEventBuffer.
#define RTA_QUOTIENT_2_PERCENT (100uL)


/// This define determines the warning limit.
#define RTA_LIMIT_MAX_BUFFER_USAGE_PERC ((uint8)80)


/// This define is used to filter out the threadID - task or ISR - from u_IdCurrentThread
/// which is composite of threadType and threadID.\n
#define MASK_THREAD_ID    (0xFFuL)


/// This define is used to shift the threadType to its desired place in order to fill it into u_IdCurrentThread.
#define SHIFT_THREAD_TYPE (16)


/// This define holds the maxValue of an uint8
#define UINT8_MAX_VALUE ((uint8)0xFF)


/// This define holds the maxValue of an uint64
#define UINT64_MAX_VALUE 0xFFFFFFFFFFFFFFFFu

/// This define holds the maxValue of 12 bits
#define RTA_12_BIT_MAX_VALUE ((uint16)0xFFF)

/// RTA local IDs
typedef enum
{
  RTA_SWITCH_FUNC,
  RTA_FREEZE_FUNC,
  RTA_SWITCH_BUFFER,
  RTA_WARNING_BUFFER_NOT_FROZEN,
  RTA_WARNING_BUFFER_FREEZE_PENDING
}RTA_t_RtaLocalIds; /* RTA_LOCAL_ID_FOR_XML_GENERATION */


/// all errors thrown by RTA
typedef enum
{
  RTA_NO_ERROR,                     ///< No error, anything is OK
  RTA_CORE_ID_CFG_INVALID,          ///< Error in coreID configuration, invalid coreID received
  RTA_EVENTBUFFER_FULL,             ///< EventBuffer is full, provided event cannot be stored and will be lost
  RTA_BUFFER_FREEZE_ERROR,          ///< rtaBuffer could not be frozen
  RTA_NO_TASK_ID_LUT,               ///< taskIdLut not obtained
  RTA_BUFFER_NOT_FROZEN,            ///< The RTA buffer has not been frozen since last buffer switch
  RTA_ASYNC_FREEZE_NOT_FINISHED,    ///< Asynchronous freeze of RtaBuffer has not been finished in time
  RTA_NUMBER_OF_ERRORS
} RTA_t_Error;


/// all warnings thrown by RTA.
typedef enum
{
  RTA_NO_WARNING,                   ///< No warning, anything is OK
  RTA_NOT_INIT,                     ///< The RTA was tried to be used without preceding initialization
  RTA_ALREADY_INIT,                 ///< The initRoutine has been called more than once
  RTA_INFO_FREEZE_ERROR,            ///< rtaInfo could not be frozen
  RTA_EVENTBUFFER_LIMIT_EXCEEDED,   ///< the usage of the rtaBuffer is beyond 80% - it shall be increased
  RTA_NUMBER_OF_WARNINGS
} RTA_t_Warning;


#ifdef __cplusplus
}
#endif

#endif // RTA_DEFS_H
