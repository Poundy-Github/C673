// Copyright (C) Continental AG
// All Rights Reserved
// COMPONENT: RTA - real time analysis
/// \file
/// \brief This file contains the core specific types of the rtaBuffer 

#ifndef RTA_DATASETS_BUFFER_TYPES_H
#define RTA_DATASETS_BUFFER_TYPES_H

#include <rta_prj_cfg.h>
#include <rta_cfg.h>
#include <rta_datasets.h>

#ifdef __cplusplus
extern "C"
{
#endif

/// structure of an RTA buffer which is sent to the MO. \n
/// It has to be compatible to the MO!
/// Note: The bufferType is defined here as it is needed in both in rta_datasets.c and in rta_emergency_freeze_datasets.c if available
typedef struct
{
  RTA_t_BufferHeader RtaBufferHeader;
  RTA_t_EventData    EventContainer[RTA_NO_OF_EVENTS_CORE_0];
} RTA_t_Buffer_Core_0;

typedef struct
{
  RTA_t_BufferHeader RtaBufferHeader;
  RTA_t_EventData    EventContainer[RTA_NO_OF_EVENTS_CORE_1];
} RTA_t_Buffer_Core_1;

typedef struct
{
  RTA_t_BufferHeader RtaBufferHeader;
  RTA_t_EventData    EventContainer[RTA_NO_OF_EVENTS_CORE_2];
} RTA_t_Buffer_Core_2;

typedef struct
{
  RTA_t_BufferHeader RtaBufferHeader;
  RTA_t_EventData    EventContainer[RTA_NO_OF_EVENTS_CORE_3];
} RTA_t_Buffer_Core_3;

#ifdef __cplusplus
}
#endif

#endif
