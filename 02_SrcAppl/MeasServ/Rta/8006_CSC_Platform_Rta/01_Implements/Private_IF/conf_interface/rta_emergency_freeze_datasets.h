// Copyright (C) Continental AG
// All Rights Reserved
// COMPONENT: RTA - RealTimeAnalysis
/// \file
/// \brief This file declares the configuration interface for the emergency buffer freeze feature.

#ifndef RTA_EMERGEMCY_FREEZE_DATA_SETS_H
#define RTA_EMERGEMCY_FREEZE_DATA_SETS_H

//includes
#include <rta_common.h>

#ifdef __cplusplus
extern "C"
{
#endif


/// This structure contains all constant parameters of the RTA for one core required for emergency freeze.
typedef struct
{
  /// a list of pointers to the RTA_t_Buffers. The list contains two entries as these buffers
  /// are used as toggle buffers. While the one is written to the other one is provided to mts.
  RTA_t_BufferGeneric*  a_ptrRtaBuffer[RTA_NO_OF_BUFFERS];
  /// The buildUnit to which the core of this paramSet belongs to
  RTA_t_BuildUnits buildUnit;
  /// virtual address of the rtaBuffer for this core. \n
  /// Range: It has to be equal to RTA_MEAS_VIRT_ADDRESS or equal to RTA_MEAS_VIRT_ADDRESS_CORE_1 on core 1 of IUC, ...
  uint32 u_virtAddrRtaBuffer;
  /// functionID for the rtaBuffer \n
  /// Range: It has to be equal to RTA_MEAS_FUNC_ID or equal to RTA_MEAS_FUNC_ID_CORE_1 on core 1 of IUC, ...
  uint8  u_functionId;
}RTA_t_EmergencyFreezeParamSet;


typedef struct
{
  RTA_t_EmergencyFreezeParamSet** p_paramSets;          /// Pointer array to the paramSets of all dpuCores
  uint32                          u_numberOfCores;      /// Number of cores - the length of the pointer array defined above
}RTA_t_EmergencyFreezeParamSetHandler;

extern const RTA_t_EmergencyFreezeParamSetHandler rta_emergencyFreezeParamSetHandler;


#ifdef __cplusplus
}
#endif

#endif // #ifndef RTA_EMERGEMCY_FREEZE_DATA_SETS_H
