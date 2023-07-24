/**
 * \file Dbg.h
 *
 * \brief This commponents use for enable software releated function,for example,debug,integration test and etc.
 *
 * \version
 * --------------------------------------------------------------------------------------------
 * Version	| 		Date		|		Author			| 	Comments
 * V0.0.1		2022.09.19			Mingfen XIAO			Init version
 * V0.1.0		2022.11.20			Mingfen XIAO			V0.1.0 develop baseline
 */

#ifndef _DBG_H_
#define _DBG_H_

#include "Std_Types.h" /* AUTOSAR standard types */
#include "CSC_Platform_Common_Type.h"
#include "Dbg_Cfg.h"

/*==================[macros]=================================================*/
/*
 * \brief 	DBG_SW_MAJOR_VERSION,
 * */
#ifndef DBG_SW_MAJOR_VERSION
#define DBG_SW_MAJOR_VERSION			(0u)
#endif

/*TODO : Check the version number range*/
#if (DBG_SW_MAJOR_VERSION > 99)
#error DBG_SW_MAJOR_VERSION out of range
#endif

/*
 * \brief 	DBG_SW_MINOR_VERSION,
 * */
#ifndef DBG_SW_MINOR_VERSION
#define DBG_SW_MINOR_VERSION			(0u)
#endif

/*TODO : Check the version number range*/
#if (DBG_SW_MINOR_VERSION > 99)
#error DBG_SW_MINOR_VERSION out of range
#endif

/*
 * \brief 	DBG_SW_PATCH_VERSION,
 * */
#ifndef DBG_SW_PATCH_VERSION
#define DBG_SW_PATCH_VERSION			(1u)
#endif

/*TODO : Check the version number range*/
#if (DBG_SW_PATCH_VERSION > 99)
#error DBG_SW_PATCH_VERSION out of range
#endif


#endif
