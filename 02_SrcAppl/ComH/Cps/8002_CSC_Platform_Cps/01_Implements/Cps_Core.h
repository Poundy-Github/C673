/**
 * \file Cps_Core.h
 *
 * \brief
 *
 * \version
 * --------------------------------------------------------------------------------------------
 * Version	| 		Date		|		Author			| 	Comments
 * V0.0.1		2022.03.15			Mingfen XIAO			Init version
 * V0.0.2       2022.05.03          Mingfen XIAO            Optimize code and remove unreasonable conversions function called.
 * V0.0.3       2022.09.20          Mingfen XIAO            Updated the Dbg switch,When you can added the stubs or debug code,you shall refer the Dbg components.
 * V0.1.0		2022.11.20			Mingfen XIAO			V0.1.0 develop base line
 * V0.1.1       2023.3.9            KUN     Zhang           Nerly increased Cps_UserMainFunction
 * V0.1.2       2023.3.23           KUN     Zhang           Nerly increased Cps_UserInitFunction
 * V0.1.3       2023.5.22           Qiuyan  Zhang           Modify logic of substitute value for error signal value
 */
#ifndef _CPS_CORE_H_
#define _CPS_CORE_H_

/*==================[inclusions]============================================*/
#include "Cps_Type.h"
#include "Cps_Cfg.h"
#include "Cps_Lcfg.h"
#include "CSC_Platform_Common.h"

/*==================[macros]=================================================*/
/*
 * \brief 	CPS_MODULE_ID,
 * */
#ifndef CPS_MODULE_ID
#define CPS_MODULE_ID			(0x8002ul)
#endif

/*
 * \brief 	CPR_SW_MAJOR_VERSION,
 * */
#ifndef CPS_SW_MAJOR_VERSION
#define CPS_SW_MAJOR_VERSION			(0u)
#endif

/*TODO : Check the version number range*/
#if (CPS_SW_MAJOR_VERSION > 99)
#error CPS_SW_MAJOR_VERSION out of range
#endif

/*
 * \brief 	CPS_SW_MINOR_VERSION,
 * */
#ifndef CPS_SW_MINOR_VERSION
#define CPS_SW_MINOR_VERSION			(1u)
#endif

/*TODO : Check the version number range*/
#if (CPS_SW_MINOR_VERSION > 99)
#error CPS_SW_MINOR_VERSION out of range
#endif

/*
 * \brief 	CPS_SW_PATCH_VERSION,
 * */
#ifndef CPS_SW_PATCH_VERSION
#define CPS_SW_PATCH_VERSION			(3u)
#endif

/* 
* \brief   CPS_USER_MAIN_FUNCTION_ENABLE, 
* */

#define CPS_USER_MAIN_FUNCTION_ENABLE   STD_ON
#if (CPS_USER_MAIN_FUNCTION_ENABLE == STD_ON)
extern void Cps_UserInitFunction(void);
#endif

#define CPS_USER_MAIN_FUNCTION_ENABLE   STD_ON
#if (CPS_USER_MAIN_FUNCTION_ENABLE == STD_ON)
extern void Cps_UserMainFunction(void);
#endif

/*TODO : Check the version number range*/
#if (CPS_SW_PATCH_VERSION > 99)
#error CPS_SW_PATCH_VERSION out of range
#endif

/*==================[external function declarations]========================*/
extern void Cps_Core_InitFunction(void);
extern void Cps_Core_MainFunction(void);


#endif /* _CPS_CORE_H_ */
