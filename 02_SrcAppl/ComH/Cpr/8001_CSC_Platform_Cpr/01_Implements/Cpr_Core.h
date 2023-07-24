/**
 * \file Cpr_Core.h
 *
 * \brief
 *
 * \version
 * --------------------------------------------------------------------------------------------
 * Version	| 		Date		|		Author			| 	Comments
 * V0.0.1		2022.01.22			Mingfen XIAO			Init version
 * V0.0.2		2022.02.13			Mingfen XIAO            
 * V0.0.3       2022.05.03          Mingfen XIAO            Optimize code and added some of conversions function called.
 * V0.0.4       2022.09.20          Mingfen XIAO            Updated the Dbg switch,When you can added the stubs or debug code,you shall refer the Dbg components.
 * V0.1.0		2022.11.20			Mingfen XIAO			V0.1.0 develop base line
 * V0.1.1		2023.3 .9			ZHANG    KUN			V0.1.1 New Cpr_UserMainFunction Function
 */
#ifndef _CPR_CORE_H_
#define _CPR_CORE_H_

/*==================[inclusions]============================================*/
#include "Cpr_Type.h"
#include "Cpr_Cfg.h"
#include "Cpr_Lcfg.h"
#include "CSC_Platform_Common.h"

/*==================[macros]=================================================*/
/*
 * \brief 	CPR_MODULE_ID,
 * */
#ifndef CPR_MODULE_ID
#define CPR_MODULE_ID			(0x8001ul)
#endif

/*
 * \brief 	CPR_SW_MAJOR_VERSION,
 * */
#ifndef CPR_SW_MAJOR_VERSION
#define CPR_SW_MAJOR_VERSION			(0u)
#endif

/*TODO : Check the version number range*/
#if (CPR_SW_MAJOR_VERSION > 99)
#error CPR_SW_MAJOR_VERSION out of range
#endif

/*
 * \brief 	CPR_SW_MINOR_VERSION,
 * */
#ifndef CPR_SW_MINOR_VERSION
#define CPR_SW_MINOR_VERSION			(0u)
#endif

/*TODO : Check the version number range*/
#if (CPR_SW_MINOR_VERSION > 99)
#error CPR_SW_MINOR_VERSION out of range
#endif

/*
 * \brief 	CPR_SW_PATCH_VERSION,
 * */
#ifndef CPR_SW_PATCH_VERSION
#define CPR_SW_PATCH_VERSION			(4u)
#endif

/*TODO : Check the version number range*/
#if (CPR_SW_PATCH_VERSION > 99)
#error CPR_SW_PATCH_VERSION out of range
#endif

/*==================[external function declarations]========================*/
extern void Cpr_Core_InitFunction(void);
extern void Cpr_Core_MainFunction(void);

#endif /* _CPR_CORE_H_ */
