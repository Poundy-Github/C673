/**
 * \file Med_Core.h
 *
 * \brief This file contains related functions,variables and etc.
 *
 * \version
 * --------------------------------------------------------------------------------------------
 * Version	| 	Author			| 	Comments
 * V0.0.1		Mingfen XIAO		Init version
 * V0.0.2       Xing JI             Add MED_USERMAINFUNCTION_ENABLE to switch Med_UserMainFunction
 *
 *
 */

#ifndef MED_CORE_H
#define MED_CORE_H

/*==================[inclusions]============================================*/
#include "Med_Type.h"
#include "Med_Cfg.h"
#include "Med_Lcfg.h"

/*==================[macros]=================================================*/
/*
 * \brief 	MED_MODULE_ID,
 * */
#ifndef MED_MODULE_ID
#define MED_MODULE_ID			(0x8003ul)
#endif

/*
 * \brief 	MED_SW_MAJOR_VERSION,
 * */
#ifndef MED_SW_MAJOR_VERSION
#define MED_SW_MAJOR_VERSION			(0u)
#endif

/*TODO : Check the version number range*/
#if (MED_SW_MAJOR_VERSION > 99)
#error MED_SW_MAJOR_VERSION out of range
#endif

/*
 * \brief 	MED_SW_MINOR_VERSION,
 * */
#ifndef MED_SW_MINOR_VERSION
#define MED_SW_MINOR_VERSION			(0u)
#endif

/*TODO : Check the version number range*/
#if (MED_SW_MINOR_VERSION > 99)
#error MED_SW_MINOR_VERSION out of range
#endif

/*
 * \brief 	MED_SW_PATCH_VERSION,
 * */
#ifndef MED_SW_PATCH_VERSION
#define MED_SW_PATCH_VERSION			(2u)
#endif

/*TODO : Check the version number range*/
#if (MED_SW_PATCH_VERSION > 99)
#error MED_SW_PATCH_VERSION out of range
#endif

/*
 * \brief 	MED_CORE_DEBUG_ENABLE,
 * */
#ifndef  MED_CORE_DEBUG_ENABLE
#define MED_CORE_DEBUG_ENABLE		STD_OFF
#endif

/*==================[external function declarations]========================*/
extern void Med_Core_InitFunction(void);
extern void Med_Core_MainFunction(void);

#if(MED_USERMAINFUNCTION_ENABLE == STD_ON)
    extern void Med_UserMainFunction(void);
#endif

#if ((defined MED_USERINITFUNCION_ENABLED) && (MED_USERINITFUNCION_ENABLED == STD_ON))
extern void Med_UserInitFunction(void);
#endif

#if ((defined MED_INJECTION_ENABLED) && (MED_INJECTION_ENABLED == STD_ON))
extern void Med_Injection(void);
#endif

#endif /* MED_CORE_H */
