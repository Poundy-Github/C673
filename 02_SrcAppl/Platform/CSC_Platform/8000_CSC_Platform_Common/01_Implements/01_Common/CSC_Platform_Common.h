/**
 * \file CSC_Platform_Common.h
 *
 * \brief
 *
 * \version
 * --------------------------------------------------------------------------------------------
 * Version	| 		Date		|		Author			| 	Comments
 * V0.0.1		2022.04.19			Mingfen XIAO			1.Init version
 * V0.0.2       2022.05.03          Mingfen XIAO            1.New the file of CSC_Platform_Common_Type.h use for definition the data type.
 * V0.0.3       2022.05.16          Mingfen XIAO            1.Added the submodule of Time
 *                                                          2.Added the data type in CSC_Platform_Common_Type.h
 *                                                          3.Update the file structure
 * V0.0.4       2022.05.23          Mingfen XIAO            1.Time : Added Total and Average time of s_Time_RunCycleMeas_t and s_Time_RunIntervalMeas_t.
 * V0.0.5       2022.06.07          Mingfen XIAO            1.Time : Fixed the MeasRunCycle Average issue
 * V0.0.6       2022.06.10          Mingfen XIAO            The sub components of Time updated to V0.0.4
 *                                                          1.Time : Not used the Time_StbmTimeStamp.secondsHi to generated timestamp;
 *                                                          2.Time : Added a global variable to store the StbM global timestamp,useful debug
 *                                                          3.Time : Added a function of Time_InitFunction when the ecu is timesync master,shall be called this funcion.
 * V0.0.7       2022.08.27          Chengyao SHI            1.Time : fixed bug get Time_StbmTimeStamp ns 
 * V0.0.8       2022.09.13          Mingfen XIAO            1.Time : Get the StbM global time via RTE interface
 *                                                          2.Time : Provied the Get Time stamp interface via RTE;
 * V0.0.9       2022.09.14          Mingfen XIAO            1.Time : Fixed an issue;
 * V0.0.10      2022.09.20          Mingfen XIAO            1.Dbg : Created the components which use for enable the debug/integration/unit test variable or code;
 *                                                          2.Time : Updated the arxml,fixed the sybmol name incorrect with the function name.
 * V0.1.0		2022.11.20			Mingfen XIAO			V0.1.0 develop base line
 * V0.1.1       2022.12.24          Mingfen XIAO            1.Create the module of MemMap
 *                                                          2.Time : Created the Time_MemMap.h files
 *                                                          3.Time : Fixed the byte alignment in MTS
 *                                                          4.DataConvert : Created the DataConvert_MemMap.h files
 *                                                          5.DataConvert : Added the macro of ROUND,use for data type convert from float to init
 * V0.1.2       2022.12.24          KUN ZHANG               1.Bug fix MemMap_Common.h   
 * V0.2.0       2023.01.30          Mingfen XIAO            1.Removed the software component of Time to CSC_Platform.                                          
 *
 */

#ifndef _CSC_PLATFORM_COMMON_H_
#define _CSC_PLATFORM_COMMON_H_

/*==================[inclusions]============================================*/
#include "DataConvert.h"
#include "Time.h"
#include "Dbg.h"

/*==================[macros]=================================================*/
/*
 * \brief 	CSC_PLATFORM_COMMON_MODULE_ID,
 * */
#ifndef CSC_PLATFORM_COMMON_MODULE_ID
#define CSC_PLATFORM_COMMON_MODULE_ID			(0x8000ul)
#endif

/*
 * \brief 	CSC_PLATFORM_COMMON_SW_MAJOR_VERSION,
 * */
#ifndef CSC_PLATFORM_COMMON_SW_MAJOR_VERSION
#define CSC_PLATFORM_COMMON_SW_MAJOR_VERSION			(0u)
#endif

/*TODO : Check the version number range*/
#if (CSC_PLATFORM_COMMON_SW_MAJOR_VERSION > 99)
#error CSC_PLATFORM_COMMON_SW_MAJOR_VERSION out of range
#endif

/*
 * \brief 	CSC_PLATFORM_COMMON_SW_MINOR_VERSION,
 * */
#ifndef CSC_PLATFORM_COMMON_SW_MINOR_VERSION
#define CSC_PLATFORM_COMMON_SW_MINOR_VERSION			(1u)
#endif

/*TODO : Check the version number range*/
#if (CSC_PLATFORM_COMMON_SW_MINOR_VERSION > 99)
#error CSC_PLATFORM_COMMON_SW_MINOR_VERSION out of range
#endif

/*
 * \brief 	CSC_PLATFORM_COMMON_SW_PATCH_VERSION,
 * */
#ifndef CSC_PLATFORM_COMMON_SW_PATCH_VERSION
#define CSC_PLATFORM_COMMON_SW_PATCH_VERSION			(2u)
#endif

/*TODO : Check the version number range*/
#if (CSC_PLATFORM_COMMON_SW_PATCH_VERSION > 99)
#error CSC_PLATFORM_COMMON_SW_PATCH_VERSION out of range
#endif

/*
 * \brief 	CSC_PLATFORM_COMMON_CORE_DEBUG_ENABLE,
 * */
#ifndef  CSC_PLATFORM_COMMON_CORE_DEBUG_ENABLE
#define CSC_PLATFORM_COMMON_CORE_DEBUG_ENABLE		STD_OFF
#endif

/*==================[external function declarations]========================*/


#endif /* _CSC_PLATFORM_COMMON_H_ */
