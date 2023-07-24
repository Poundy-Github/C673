// Copyright (C) Continental AG
// All Rights Reserved
// COMPONENT: RTA - real time analysis
/// @file     RTA_PrjCfg.h
/// @brief    This header contains all relevant configuration defines like NumberOfCores, CoreIDs, NumberOfEvents, virtAddresses, ... of all cores in the target

#ifndef RTA_PRJ_CFG_H
#define RTA_PRJ_CFG_H

#include <glob_comp_id.h>
#include "Os_Config.h"

#ifdef __cplusplus
extern "C"
{
#endif

//All defines related to IUC ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// The number of IUC cores
#define RTA_NO_OF_CORES___IUC (4uL)

/// The number of RtaEvents on IUC core X (the rtaBufferSize in events)
#define RTA_NO_OF_EVENTS___IUC_CORE_0 (1810uL)
#define RTA_NO_OF_EVENTS___IUC_CORE_1 (512uL)
#define RTA_NO_OF_EVENTS___IUC_CORE_2 (512uL)
#define RTA_NO_OF_EVENTS___IUC_CORE_3 (512uL)

/// The coreID of IUC core X (the coreID which is sent to the rtaMOs)
#define RTA_CORE_ID___IUC_CORE_0 (0uL)
#define RTA_CORE_ID___IUC_CORE_1 (1uL)
#define RTA_CORE_ID___IUC_CORE_2 (2uL)
#define RTA_CORE_ID___IUC_CORE_3 (3uL)

/// The measFunctionID of IUC core X (shall be used as FuncID and as FuncChannelID as well)
#define RTA_MEAS_FUNCTION_ID___IUC_CORE_0 (140u) // (TASK_ID_M11)
#define RTA_MEAS_FUNCTION_ID___IUC_CORE_1 (141u) // (TASK_ID_M11)
#define RTA_MEAS_FUNCTION_ID___IUC_CORE_2 (142u) // (TASK_ID_M11)
#define RTA_MEAS_FUNCTION_ID___IUC_CORE_3 (143u) // (TASK_ID_M11)


/// The virtual address for the rtaBuffer of IUC core X
#define RTA_MEAS_VIRT_ADDRESS___IUC_CORE_0         (0x50000000uL)
#define RTA_MEAS_VIRT_ADDRESS___IUC_CORE_1         (0x60000000uL)
#define RTA_MEAS_VIRT_ADDRESS___IUC_CORE_2         (0x70000000uL)
#define RTA_MEAS_VIRT_ADDRESS___IUC_CORE_3         (0x80000000uL)
/// The virtual address for the rtaDebugInfo of IUC core X
#define RTA_MEAS_VIRT_ADDRESS_INFO___IUC_CORE_0    (0x5000ff00uL)
#define RTA_MEAS_VIRT_ADDRESS_INFO___IUC_CORE_1    (0x6000ff00uL)
#define RTA_MEAS_VIRT_ADDRESS_INFO___IUC_CORE_2    (0x7000ff00uL)
#define RTA_MEAS_VIRT_ADDRESS_INFO___IUC_CORE_3    (0x8000ff00uL)

#define OS_NUMBER_OF_TASKS OS_NTASKS

#ifdef __cplusplus
}
#endif


#endif // #ifndef RTA_PRJ_CFG_H

