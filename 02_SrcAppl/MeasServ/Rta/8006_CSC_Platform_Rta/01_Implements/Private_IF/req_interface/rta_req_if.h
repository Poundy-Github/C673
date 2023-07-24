// Copyright (C) Continental AG
// All Rights Reserved
// COMPONENT: RTA - RealTimeAnalysis
/// \file
/// \brief This header declares all interface functions required by the RTA component. These functions must be implemented in adas_embed_mon_proj for every project.

#ifndef RTA_REQ_IF_H
#define RTA_REQ_IF_H

#include <rta.h>
#include "Rte_Type.h"
#ifdef __cplusplus
extern "C"
{
#endif


/// For compatibility check in rta_req_if.c - for elektroBit OS
#define RTA_EXP_MK_SW_MAJOR_VERSION         2U
#define RTA_EXP_MK_SW_MINOR_VERSION         0U
#define RTA_EXP_MK_SW_PATCH_VERSION_MIN   135U
#define RTA_EXP_MK_SW_PATCH_VERSION_MAX   144U


/// For compatibility check in rta_req_if.c - for vector OS
#define RTA_EXP_OS_VENDOR_ID              (30u)
#define RTA_EXP_OS_SW_MAJOR_VERSION       (2u)
#define RTA_EXP_OS_SW_MINOR_VERSION_MIN   (59u)
#define RTA_EXP_OS_SW_MINOR_VERSION_MAX   (65u)
#define RTA_EXP_OS_SW_PATCH_VERSION       (0u)


typedef void (*RTA_t_MeasCallback)(void);


/// Struct to collect all required information for doing a measFreeze.
typedef struct
{
  void*              p_data;       ///< Pointer to the date which shall be frozen
  uint32             u_lenght;     ///< Length of data in byte
  uint32             u_virtAddr;   ///< The virtual address
  uint16             u_functionId; ///< The functionId
  RTA_t_MeasCallback p_callBack;   ///< The function which shall be called once the asynchronous freeze is completed, NULL in case of synchronous freezes
} RTA_t_MeasFreezeInfo;


// RTA_GET_LOCALTIME_COUNTER_TICKS
uint32 RTA_ReqIf_u_GetLocalTimeInUs(void);


// RTA_GET_SYSTEM_TIME_US
uint64 RTA_ReqIf_u_GetSystemTimeInUs(void);


// RTA_DISABLE_INTERRUPTS
void RTA_ReqIf_v_DisableInterrupts(void);


// RTA_ENABLE_INTERRUPTS
void RTA_ReqIf_v_EnableInterrupts(void);


// RTA_GET_CORE_ID
uint32 RTA_ReqIf_u_GetCoreId(void);


// RTA_MEAS_FREEZE_DATA
uint32 RTA_ReqIf_u_MeasFreezeData(const RTA_t_MeasFreezeInfo* const p_measFreezeInfo);


// RTA_CACHE_WRITEBACK_ACTIVATED
void RTA_ReqIf_v_WritebackCache(void* const p_block, const uint32 u_length);


// RTA_MEM_SET
void RTA_ReqIf_v_MemSet(void* const p_dest, const uint8 u_value, const uint32 u_length);


uint64 RTA_ReqIf_u_GetInterruptedAddress(void);


// Only required in case emergencyFreeze is enabled
void RTA_ReqIf_v_PrepareEmergencyMeasFreeze(void);
void RTA_ReqIf_v_FinishEmergencyMeasFreeze(void);
uint32 RTA_ReqIf_u_EmergencyMeasFreezeData(const RTA_t_MeasFreezeInfo* const p_measFreezeInfo);


// Only required in case of active auxiliary cores
void RTA_ReqIf_v_GetSpinLock(const uint32 u_SPIN_LOCK_ID);
void RTA_ReqIf_v_ReleaseSpinLock(const uint32 u_SPIN_LOCK_ID);
void RTA_ReqIf_v_SetOsEdpSyncEvent(const uint32 u_osTaskId);


// This function gives the possibility to block single globalIDs if needed
// TODO: Switch to RTA_t_GlobalID as soon as adas_embed_mon_if 3.1.1 is integrated!
//       Currently the standard type is used to make an integration into the projects possible even without 3.1.1
//boolean RTA_ReqIf_v_IsGlobalIdEnabled(const RTA_t_GlobalID u_globalID)
boolean RTA_ReqIf_v_IsGlobalIdEnabled(const uint16 u_globalID);

#ifdef __cplusplus
}
#endif

#endif // #ifndef RTA_REQ_IF_H
