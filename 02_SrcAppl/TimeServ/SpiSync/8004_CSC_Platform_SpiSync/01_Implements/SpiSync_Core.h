/**
 * \file SpiSync_Core.h
 *
 * \brief
 *
 * \version
 * --------------------------------------------------------------------------------------------
 * Version	| 		Date		|		Author			| 	Comments
 * V0.0.1		2022.05.17			Mingfen XIAO			Init version
 * V0.0.2       2022.05.17          Mingfen XIAO            Updated the state machine
 * V0.0.3       2022.05.20          Mingfen XIAO            Added the SpiSync Enable switch
 * V0.0.4       2022.05.22          Mingfen XIAO            Added Debug switch macro of SPISYNC_DEBUG_ENABLE
 *                                                          Added the macro of SPISYNC_TIMESYNC_CHECK_GLOBAL_STATUS
 * V0.0.5       2022.06.07          Mingfen XIAO            Modified by the SpiSync MainFunction Cycle from 10ms to 5ms
 * V0.0.6       2022.06.10          Mingfen XIAO            Fixed the issue which Spi Time Sync Message time stamp unit is ns.
 *                                                          Updated arxml of SpiSync
 *                                                          Replace the Spi Time Sync message API
 * V0.0.7       2022.07.03          Mingfen XIAO            Replace the Spi Time Sync message Api,the Api rename.
 * V0.0.8       2022.07.17          Mingfen XIAO            The Tims sync message api repace the marco.
 * V0.0.9       2022.10.22          Mingfen XIAO            1.Add the Dynamic offset logic,and modified some macro name
 *                                                          2.Add User Functions(Init Function and Main Function)
 *                                                          3.Add two files,they are SpiSync_Stubs.c,SpiSync_Stubs.h
 * V0.0.10      2022.11.07          Gu      HAN             Convert Offset to uint64 by multiply unsigned long long (ull)
 * V0.1.0		2022.11.20			Mingfen XIAO			V0.1.0 baseline
 * V0.1.1		2023.01.04			Gu      HAN			    As per system new req, add a configurable timer in SpiSync start up phase
 * V0.1.2		2023.06.07			Wenlong YUAN			Add TimeSync Rte portable
 *  
 */

#ifndef _SPISYNC_CORE_H_
#define _SPISYNC_CORE_H_

/*==================[inclusions]============================================*/
#include "CSC_Platform_Common_Type.h"
#include "SpiSync_Cfg.h"
#include "SpiSync_Lcfg.h"

/*==================[macros]=================================================*/
/*
 * \brief 	SPISYNC_MODULE_ID,
 * */
#ifndef SPISYNC_MODULE_ID
#define SPISYNC_MODULE_ID			        (0x8004ul)
#endif

/*
 * \brief 	SPISYNC_SW_MAJOR_VERSION,
 * */
#ifndef SPISYNC_SW_MAJOR_VERSION
#define SPISYNC_SW_MAJOR_VERSION			(0u)
#endif

/*TODO : Check the version number range*/
#if (SPISYNC_SW_MAJOR_VERSION > 99)
#error SPISYNC_SW_MAJOR_VERSION out of range
#endif

/*
 * \brief 	SPISYNC_SW_MINOR_VERSION,
 * */
#ifndef SPISYNC_SW_MINOR_VERSION
#define SPISYNC_SW_MINOR_VERSION			(1u)
#endif

/*TODO : Check the version number range*/
#if (SPISYNC_SW_MINOR_VERSION > 99)
#error SPISYNC_SW_MINOR_VERSION out of range
#endif

/*
 * \brief 	SPISYNC_SW_PATCH_VERSION,
 * */
#ifndef SPISYNC_SW_PATCH_VERSION
#define SPISYNC_SW_PATCH_VERSION			(2u)
#endif

/*TODO : Check the version number range*/
#if (SPISYNC_SW_PATCH_VERSION > 99)
#error SPISYNC_SW_PATCH_VERSION out of range
#endif

/*
 * \brief 	SPISYNC_CORE_DEBUG_ENABLE,
 * */
#ifndef  SPISYNC_CORE_DEBUG_ENABLE
#define  SPISYNC_CORE_DEBUG_ENABLE		STD_OFF
#endif

/*==================[type definitions]=======================================*/

/*==================[external function declarations]========================*/
extern void SpiSync_Core_InitFunction(void);
extern void SpiSync_Core_MainFunction(void);
extern void SpiSync_Core_GetTimestampOffset(uint64 *timestamp);
extern void SpiSync_Core_GetSpiTimeSyncStatus(e_SpiSync_TimeSyncState_t *status);

#endif /* _SPISYNC_CORE_H_ */
