// Copyright (C) Continental AG
// All Rights Reserved
// COMPONENT: RTA - RealTimeAnalysis
/// \file
/// \brief This file declares the configuration interface for the auxiliary core feature.

#ifndef RTA_AUX_CORE_DATA_SETS_H
#define RTA_AUX_CORE_DATA_SETS_H

#include <rta_common.h>

#ifdef __cplusplus
extern "C"
{
#endif


/// This structure contains all constant parameter of the RTA for one core.
typedef struct
{
  /// a list of pointers to the RTA_t_Buffers. The list contains two entries as these buffers
  /// are used as toggle buffers. While the one is written to the other one is provided to mts.
  RTA_t_BufferGeneric*  a_ptrRtaBuffer[RTA_NO_OF_BUFFERS];
  /// should hold address of the related measCallBack function.
  void (*p_measCallbackFct)(void);
  /// The spinlock ID required
  uint32 u_spinlockId;
  /// maximum number of rtaEvents for this core, which is limited by the bufferSize. \n
  /// Range: One of the following: RTA_NO_OF_EVENTS, RTA_NO_OF_EVENTS_CORE_1, RTA_NO_OF_EVENTS_CORE_2
  uint32 u_maxNumberOfRtaEvents;
  /// coreID of this core. \n
  /// Range: It has to be equal to RTA_CORE_ID or equal to RTA_CORE_ID_CORE_1 on core 1 of IUC, ...
  uint32 u_CoreID;
  /// virtual address of the rtaBuffer for this core. \n
  /// Range: It has to be equal to RTA_MEAS_VIRT_ADDRESS or equal to RTA_MEAS_VIRT_ADDRESS_CORE_1 on core 1 of IUC, ...
  uint32 u_virtAddrRtaBuffer;
  /// virtual address of the rtaComponentInfo for this core.
  uint32 u_virtAddrRtaInfo;
  /// functionID for the rtaBuffer \n
  /// Range: It has to be equal to RTA_MEAS_FUNC_ID or equal to RTA_MEAS_FUNC_ID_CORE_1 on core 1 of IUC, ...
  uint8  u_functionId;
}RTA_t_AuxCoreParams;


typedef struct
{
  /// pointer to all constant parameters for the particular core. \n
  /// Details see in description of  RTA_t_Params.
  const RTA_t_AuxCoreParams* p_params;
  /// pointer to all control variables needed for the particular core to drive the rta. \n
  /// Details see in description of  RTA_t_Ctrl.\n
  RTA_t_Ctrl* p_ctrl;
  /// pointer the callbackCounter which is incremented by the related callbackFunction. \n
  /// Note: Here a pointer is used instead of a direct variable in order to be able to link the real
  /// counter variable into a specific ram section.
  uint32* p_callbackCnt;
}RTA_t_AuxCoreDataSet;


typedef struct
{
  const RTA_t_AuxCoreDataSet**const p_dataSets;
  uint32                            u_numberOfCores;
}RTA_t_AuxCoreDataSetHandler;


extern const RTA_t_AuxCoreDataSetHandler rta_auxCoreDataSetHandler;


#ifdef __cplusplus
}
#endif

#endif // #ifndef RTA_AUX_CORE_DATA_SETS_H
