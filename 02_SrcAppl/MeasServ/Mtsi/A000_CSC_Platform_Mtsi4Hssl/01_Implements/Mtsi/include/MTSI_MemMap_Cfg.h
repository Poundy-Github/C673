// Copyright (C) Continental AG
// All Rights Reserved
// COMPONENT: MTSI
// VERSION:   $Revision: 1.5 $
/// @file



#if (!defined MTSI_MEMMAP_EB_IS_USED) || (MTSI_MEMMAP_EB_IS_USED == STD_OFF) // PRQA S 0883 
/// date: 2018--16, reviewer: AnMo, Reason: The code is not protected against repeated inclusion of MTSI_MemMap_Cfg.h .

#include <MTSI_MemMap.h>

#else

#include <MemMap.h>

#endif

#ifndef MTSI_MEMMAP_CFG_H_
#define MTSI_MEMMAP_CFG_H_

///  \brief  Switch to de/activate usage of EB MEMMAP
///
///  STD_ON  - MEMMAP mechanism from EB is used
///  STD_OFF - MEMMAP mechanism from EB is not used
///
///  \range      STD_ON, STD_OFF
///  \resolution Boolean
///  \unit       None
///
//#include <MTSI_MemMap_Control.h>

#endif // MTSI_MEMMAP_CFG_H_ 
