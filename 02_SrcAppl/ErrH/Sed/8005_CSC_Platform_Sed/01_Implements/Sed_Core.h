/**
 * \file Sed_Core.h
 *
 * \brief This file contains related functions,variables and etc.
 *
 * \version
 * --------------------------------------------------------------------------------------------
 * Version	| 	Author			| 	Comments
 * V0.0.1		Mingfen XIAO		Init version
 * V0.0.2       Mingfen XIAO        Updated some Macro name
 *                                  Added a User Function of Sed_UserInitFunction
 *                                  Updated the template files conents.
 *
 */

#ifndef SED_CORE_H
#define SED_CORE_H

/*==================[inclusions]============================================*/
#include "Sed_Type.h"
#include "Sed_Cfg.h"
#include "Sed_Lcfg.h"

/*==================[macros]=================================================*/
/*
 * \brief 	SED_MODULE_ID,
 * */
#ifndef SED_MODULE_ID
#define SED_MODULE_ID			(0x8005ul)
#endif

/*
 * \brief 	SED_SW_MAJOR_VERSION,
 * */
#ifndef SED_SW_MAJOR_VERSION
#define SED_SW_MAJOR_VERSION			(0u)
#endif

/*TODO : Check the version number range*/
#if (SED_SW_MAJOR_VERSION > 99)
#error SED_SW_MAJOR_VERSION out of range
#endif

/*
 * \brief 	SED_SW_MINOR_VERSION,
 * */
#ifndef SED_SW_MINOR_VERSION
#define SED_SW_MINOR_VERSION			(0u)
#endif

/*TODO : Check the version number range*/
#if (SED_SW_MINOR_VERSION > 99)
#error SED_SW_MINOR_VERSION out of range
#endif

/*
 * \brief 	SED_SW_PATCH_VERSION,
 * */
#ifndef SED_SW_PATCH_VERSION
#define SED_SW_PATCH_VERSION			(2u)
#endif

/*TODO : Check the version number range*/
#if (SED_SW_PATCH_VERSION > 99)
#error SED_SW_PATCH_VERSION out of range
#endif

/*
 * \brief 	SED_CORE_DEBUG_ENABLE,
 * */
#ifndef  SED_CORE_DEBUG_ENABLE
#define SED_CORE_DEBUG_ENABLE		STD_OFF
#endif

/*==================[external function declarations]========================*/
extern void Sed_Core_InitFunction(void);
extern void Sed_Core_MainFunction(void);


#endif /* Sed_CORE_H */
