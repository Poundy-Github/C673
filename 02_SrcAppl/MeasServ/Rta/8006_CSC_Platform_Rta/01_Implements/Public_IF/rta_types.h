// Copyright (C) Continental AG
// All Rights Reserved
// COMPONENT: RTA - Real-Time Analysis
/// \file
/// \brief The types used in the public interface of the RTA component

#ifndef RTA_TYPES_H
#define RTA_TYPES_H

#ifdef __cplusplus
extern "C"
{
#endif


/// The enumeration defining all existing rtaEventTypes
/// defines all eventTypes provided by RTA
typedef enum
{
  RTA_EVT_MARKER,           ///< 0; Visualize an event
  RTA_EVT_ALGOSTART,        ///< 1; Mark the start of a time period
  RTA_EVT_ALGOEND,          ///< 2; Mark the end of a time period
  RTA_EVT_TASKSWITCH,       ///< 3; Mark a task switch
  RTA_EVT_TASKRDY,          ///< 4; Mark the task as ready
  RTA_EVT_SAMPLEVALUE,      ///< 5;
  RTA_EVT_SAMPLESELECT,     ///< 6;
  RTA_EVT_ERRTRACK,         ///< 7; Visualize tracked component errors
  RTA_EVT_MAX_TYPES         ///Has to be smaller than 256
} RTA_t_Events;

/// The type for globalIDs. It is used as an argument in the RTA_v_AddEvent() function
typedef uint16 RTA_t_GlobalID;

/// The type for localIDs. It is used as an argument in the RTA_v_AddEvent() function
/// The components are responsible for their localIDs. It is necessary
typedef uint16 RTA_t_LocalID;

/// The type for optional data. It is used as an argument in the RTA_v_AddEvent() function
typedef uint8 RTA_t_OptData;

#ifndef NULL  
#define NULL ((void *)0)
#endif

#ifndef b_TRUE
#define b_TRUE (boolean)1u
#endif

#ifndef b_FALSE
#define b_FALSE (boolean)0u
#endif

#ifndef True
#define True (boolean)1
#endif

#ifndef False
#define False (boolean)0
#endif

#ifdef __cplusplus
}
#endif

#endif // #ifndef RTA_TYPES_H
