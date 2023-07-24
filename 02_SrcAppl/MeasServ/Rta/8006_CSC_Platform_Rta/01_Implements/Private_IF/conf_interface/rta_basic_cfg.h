// Copyright (C) Continental AG
// All Rights Reserved
// COMPONENT: RTA - RealTimeAnalysis
/// \file
/// \brief This header declares the configuration interface for basic settings of the RTA.

#ifndef RTA_BASIC_CFG_H
#define RTA_BASIC_CFG_H

#ifdef __cplusplus
extern "C"
{
#endif


/// This define determines the size of the array a_GLOBAL_ID_ENABLE_FLAGS.
/// It has to be 32 as we have to handle the maximal possible numbers of gobalIDs which is 256 (range of uint8).
/// With one entry 8 globalIDs are addressed ->  32 * 8 = 256
#define RTA_ARRAY_LENGTH_GLOBALID_ENABLE_FLAGS (32)


typedef struct
{
  const uint8* p_taskIdLut;                                                    ///< Pointer to the taskID lookup table
  uint32       u_sizeOfTaskIdLut;                                              ///< The size of the taskIdLut
  uint8        u_isrLocalIdOffset;                                             ///< The offset of IsrLocalIDs
  uint8        u_taskIdInterrupts;                                             ///< The taskIDs of the interrupts
}RTA_t_BasicCfg;


extern const RTA_t_BasicCfg rta_basicCfg;


#ifdef __cplusplus
}
#endif

#endif // #ifndef RTA_BASIC_CFG_H
