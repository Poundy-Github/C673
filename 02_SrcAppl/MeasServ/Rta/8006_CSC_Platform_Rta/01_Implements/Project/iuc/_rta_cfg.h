// Copyright (C) Continental AG
// All Rights Reserved
// COMPONENT: RTA - RealTimeAnalysis
/// \file
/// \brief This file contains the RTA configuration for the related buildUnit.

#ifndef RTA_Cfg_H
#define RTA_Cfg_H

#include <rta_prj_cfg.h>

#ifdef __cplusplus
extern "C"
{
#endif


/** ***********************************************************************************************
\description This define is used in context of the ISR instrumentation for providing the localID to
             the start/Stop or marker event. This offset is added to the interruptID provided by
             the OS. Normally in case we have only one OS in the whole system then this offset is
             simply 0. In case we have to separate OS in the system like in MFC510 where we have
             one OS for the R7 (IUC) and another one for both A53-cores we have to specify the offset
             for one OS (for one buildUnint) different then 0 eg. 100. This has to be done in the
             related RTA_Cfg.h  \n
***************************************************************************************************/
#define RTA_INTERRUPT_LOCAL_ID_OFFSET ((uint8)0)

/** ***********************************************************************************************
\description  This define determines the number of cores which are compiled within the build. \n
***************************************************************************************************/
#define RTA_NO_OF_CORES                      RTA_NO_OF_CORES___IUC

/** ***********************************************************************************************
\description  This define determines the number of events which can be stored in the rtaBuffer.
***************************************************************************************************/
#define RTA_NO_OF_EVENTS_CORE_0              RTA_NO_OF_EVENTS___IUC_CORE_0
#define RTA_NO_OF_EVENTS_CORE_1              RTA_NO_OF_EVENTS___IUC_CORE_1
#define RTA_NO_OF_EVENTS_CORE_2              RTA_NO_OF_EVENTS___IUC_CORE_3
#define RTA_NO_OF_EVENTS_CORE_3              RTA_NO_OF_EVENTS___IUC_CORE_2

/** ***********************************************************************************************
\description  The coreID for Core 0
***************************************************************************************************/
#define RTA_CORE_ID_CORE_0                   RTA_CORE_ID___IUC_CORE_0
#define RTA_CORE_ID_CORE_1                   RTA_CORE_ID___IUC_CORE_1
#define RTA_CORE_ID_CORE_2                   RTA_CORE_ID___IUC_CORE_2
#define RTA_CORE_ID_CORE_3                   RTA_CORE_ID___IUC_CORE_3
/** ***********************************************************************************************
\description  The funcID for Core 0
***************************************************************************************************/
#define RTA_MEAS_FUNC_ID_CORE_0              RTA_MEAS_FUNCTION_ID___IUC_CORE_0
#define RTA_MEAS_FUNC_ID_CORE_1              RTA_MEAS_FUNCTION_ID___IUC_CORE_1
#define RTA_MEAS_FUNC_ID_CORE_2              RTA_MEAS_FUNCTION_ID___IUC_CORE_2
#define RTA_MEAS_FUNC_ID_CORE_3              RTA_MEAS_FUNCTION_ID___IUC_CORE_3
/** ***********************************************************************************************
\description  The virtualAddress for the RTABuffer for Core 0
***************************************************************************************************/
#define RTA_MEAS_VIRT_ADDRESS_CORE_0         RTA_MEAS_VIRT_ADDRESS___IUC_CORE_0
#define RTA_MEAS_VIRT_ADDRESS_CORE_1         RTA_MEAS_VIRT_ADDRESS___IUC_CORE_1
#define RTA_MEAS_VIRT_ADDRESS_CORE_2         RTA_MEAS_VIRT_ADDRESS___IUC_CORE_2
#define RTA_MEAS_VIRT_ADDRESS_CORE_3         RTA_MEAS_VIRT_ADDRESS___IUC_CORE_3
/** ***********************************************************************************************
\description  The virtualAddress for the RTABuffer for Core 0
***************************************************************************************************/
#define RTA_MEAS_VIRT_ADDRESS_INFO_CORE_0    RTA_MEAS_VIRT_ADDRESS_INFO___IUC_CORE_0
#define RTA_MEAS_VIRT_ADDRESS_INFO_CORE_1    RTA_MEAS_VIRT_ADDRESS_INFO___IUC_CORE_1
#define RTA_MEAS_VIRT_ADDRESS_INFO_CORE_2    RTA_MEAS_VIRT_ADDRESS_INFO___IUC_CORE_2
#define RTA_MEAS_VIRT_ADDRESS_INFO_CORE_3    RTA_MEAS_VIRT_ADDRESS_INFO___IUC_CORE_3

#define __PDO__

#ifdef __cplusplus
}
#endif

#endif
