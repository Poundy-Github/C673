/**
 * \file DataConvert.h
 *
 * \brief
 *
 * \version
 * --------------------------------------------------------------------------------------------
 * Version	| 		Date		|		Author			| 	Comments
 * V0.0.1		2022.03.15			Mingfen XIAO			Init version
 * V0.0.2       2022.05.03          Mingfen XIAO            Optimize code and remove unreasonable conversions
 * V0.1.0		2022.11.20			Mingfen XIAO			The V0.1.0 develop base line.
 * V1.1.1       2022.12.25          Mingfen XIAO            Created the DataConvert_MemMap.h files
 *                                                          Added Round calculation,update into some functions.
 */

#ifndef _DATACONVERT_H_
#define _DATACONVERT_H_

/*==================[inclusions]============================================*/
#include "Std_Types.h" /* AUTOSAR standard types */
#include "CSC_Platform_Common_Type.h"

/*==================[macros]=================================================*/
/*
 * \brief 	DATACONVERT_SW_MAJOR_VERSION,
 * */
#ifndef DATACONVERT_SW_MAJOR_VERSION
#define DATACONVERT_SW_MAJOR_VERSION			(0u)
#endif

/*TODO : Check the version number range*/
#if (DATACONVERT_SW_MAJOR_VERSION > 99)
#error DATACONVERT_SW_MAJOR_VERSION out of range
#endif

/*
 * \brief 	DATACONVERT_SW_MINOR_VERSION,
 * */
#ifndef DATACONVERT_SW_MINOR_VERSION
#define DATACONVERT_SW_MINOR_VERSION			(1u)
#endif

/*TODO : Check the version number range*/
#if (DATACONVERT_SW_MINOR_VERSION > 99)
#error DATACONVERT_SW_MINOR_VERSION out of range
#endif

/*
 * \brief 	DATACONVERT_SW_PATCH_VERSION,
 * */
#ifndef DATACONVERT_SW_PATCH_VERSION
#define DATACONVERT_SW_PATCH_VERSION			(1u)
#endif

/*TODO : Check the version number range*/
#if (DATACONVERT_SW_PATCH_VERSION > 99)
#error DATACONVERT_SW_PATCH_VERSION out of range
#endif

/*
 * \brief 	DATACONVERT_ROUND,
 *          When there is floating-point data converted to integer data, add or subtract 0.5 first, and then cast the type to achieve rounding
 * */
#define DATACONVERT_ROUND(source)   ((source)>=0?(source+0.5f):(source-0.5f))

/*==================[type definitions]=======================================*/

/*==================[external function declarations]========================*/
#define DATACONVERT_START_SEC_CODE
#include "DataConvert_MemMap.h"

extern uint8 DataConvert_TypeConvert_Boolean2Boolean(boolean source,boolean *target);
extern uint8 DataConvert_TypeConvert_Boolean2Uint8(boolean source,uint8 *target);
extern uint8 DataConvert_TypeConvert_Boolean2Uint16(boolean source,uint16 *target);
extern uint8 DataConvert_TypeConvert_Boolean2Uint32(boolean source,uint32 *target);
extern uint8 DataConvert_TypeConvert_Boolean2Uint64(boolean source,uint64 *target);
extern uint8 DataConvert_TypeConvert_Boolean2Sint8(boolean source,sint8 *target);
extern uint8 DataConvert_TypeConvert_Boolean2Sint16(boolean source,sint16 *target);
extern uint8 DataConvert_TypeConvert_Boolean2Sint32(boolean source,sint32 *target);
extern uint8 DataConvert_TypeConvert_Boolean2Sint64(boolean source,sint64 *target);
extern uint8 DataConvert_TypeConvert_Boolean2Float32(boolean source,float32 *target);
extern uint8 DataConvert_TypeConvert_Boolean2Float64(boolean source,float64 *target);
extern uint8 DataConvert_TypeConvert_Uint82Boolean(uint8 source,boolean *target);
extern uint8 DataConvert_TypeConvert_Uint82Uint8(uint8 source,uint8 *target);
extern uint8 DataConvert_TypeConvert_Uint82Uint16(uint8 source,uint16 *target);
extern uint8 DataConvert_TypeConvert_Uint82Uint32(uint8 source,uint32 *target);
extern uint8 DataConvert_TypeConvert_Uint82Uint64(uint8 source,uint64 *target);
extern uint8 DataConvert_TypeConvert_Uint82Sint8(uint8 source,sint8 *target);
extern uint8 DataConvert_TypeConvert_Uint82Sint16(uint8 source,sint16 *target);
extern uint8 DataConvert_TypeConvert_Uint82Sint32(uint8 source,sint32 *target);
extern uint8 DataConvert_TypeConvert_Uint82Sint64(uint8 source,sint64 *target);
extern uint8 DataConvert_TypeConvert_Uint82Float32(uint8 source,float32 *target);
extern uint8 DataConvert_TypeConvert_Uint82Float64(uint8 source,float64 *target);
extern uint8 DataConvert_TypeConvert_Uint162Boolean(uint16 source,boolean *target);
extern uint8 DataConvert_TypeConvert_Uint162Uint8(uint16 source,uint8 *target);
extern uint8 DataConvert_TypeConvert_Uint162Uint16(uint16 source,uint16 *target);
extern uint8 DataConvert_TypeConvert_Uint162Uint32(uint16 source,uint32 *target);
extern uint8 DataConvert_TypeConvert_Uint162Uint64(uint16 source,uint64 *target);
extern uint8 DataConvert_TypeConvert_Uint162Sint8(uint16 source,sint8 *target);
extern uint8 DataConvert_TypeConvert_Uint162Sint16(uint16 source,sint16 *target);
extern uint8 DataConvert_TypeConvert_Uint162Sint32(uint16 source,sint32 *target);
extern uint8 DataConvert_TypeConvert_Uint162Sint64(uint16 source,sint64 *target);
extern uint8 DataConvert_TypeConvert_Uint162Float32(uint16 source,float32 *target);
extern uint8 DataConvert_TypeConvert_Uint162Float64(uint16 source,float64 *target);
extern uint8 DataConvert_TypeConvert_Uint322Boolean(uint32 source,boolean *target);
extern uint8 DataConvert_TypeConvert_Uint322Uint8(uint32 source,uint8 *target);
extern uint8 DataConvert_TypeConvert_Uint322Uint16(uint32 source,uint16 *target);
extern uint8 DataConvert_TypeConvert_Uint322Uint32(uint32 source,uint32 *target);
extern uint8 DataConvert_TypeConvert_Uint322Uint64(uint32 source,uint64 *target);
extern uint8 DataConvert_TypeConvert_Uint322Sint8(uint32 source,sint8 *target);
extern uint8 DataConvert_TypeConvert_Uint322Sint16(uint32 source,sint16 *target);
extern uint8 DataConvert_TypeConvert_Uint322Sint32(uint32 source,sint32 *target);
extern uint8 DataConvert_TypeConvert_Uint322Sint64(uint32 source,sint64 *target);
extern uint8 DataConvert_TypeConvert_Uint322Float32(uint32 source,float32 *target);
extern uint8 DataConvert_TypeConvert_Uint322Float64(uint32 source,float64 *target);
extern uint8 DataConvert_TypeConvert_Uint642Boolean(uint64 source,boolean *target);
extern uint8 DataConvert_TypeConvert_Uint642Uint8(uint64 source,uint8 *target);
extern uint8 DataConvert_TypeConvert_Uint642Uint16(uint64 source,uint16 *target);
extern uint8 DataConvert_TypeConvert_Uint642Uint32(uint64 source,uint32 *target);
extern uint8 DataConvert_TypeConvert_Uint642Uint64(uint64 source,uint64 *target);
extern uint8 DataConvert_TypeConvert_Uint642Sint8(uint64 source,sint8 *target);
extern uint8 DataConvert_TypeConvert_Uint642Sint16(uint64 source,sint16 *target);
extern uint8 DataConvert_TypeConvert_Uint642Sint32(uint64 source,sint32 *target);
extern uint8 DataConvert_TypeConvert_Uint642Sint64(uint64 source,sint64 *target);
extern uint8 DataConvert_TypeConvert_Uint642Float32(uint64 source,float32 *target);
extern uint8 DataConvert_TypeConvert_Uint642Float64(uint64 source,float64 *target);
extern uint8 DataConvert_TypeConvert_Sint82Boolean(sint8 source,boolean *target);
extern uint8 DataConvert_TypeConvert_Sint82Uint8(sint8 source,uint8 *target);
extern uint8 DataConvert_TypeConvert_Sint82Uint16(sint8 source,uint16 *target);
extern uint8 DataConvert_TypeConvert_Sint82Uint32(sint8 source,uint32 *target);
extern uint8 DataConvert_TypeConvert_Sint82Uint64(sint8 source,uint64 *target);
extern uint8 DataConvert_TypeConvert_Sint82Sint8(sint8 source,sint8 *target);
extern uint8 DataConvert_TypeConvert_Sint82Sint16(sint8 source,sint16 *target);
extern uint8 DataConvert_TypeConvert_Sint82Sint32(sint8 source,sint32 *target);
extern uint8 DataConvert_TypeConvert_Sint82Sint64(sint8 source,sint64 *target);
extern uint8 DataConvert_TypeConvert_Sint82Float32(sint8 source,float32 *target);
extern uint8 DataConvert_TypeConvert_Sint82Float64(sint8 source,float64 *target);
extern uint8 DataConvert_TypeConvert_Sint162Boolean(sint16 source,boolean *target);
extern uint8 DataConvert_TypeConvert_Sint162Uint8(sint16 source,uint8 *target);
extern uint8 DataConvert_TypeConvert_Sint162Uint16(sint16 source,uint16 *target);
extern uint8 DataConvert_TypeConvert_Sint162Uint32(sint16 source,uint32 *target);
extern uint8 DataConvert_TypeConvert_Sint162Uint64(sint16 source,uint64 *target);
extern uint8 DataConvert_TypeConvert_Sint162Sint8(sint16 source,sint8 *target);
extern uint8 DataConvert_TypeConvert_Sint162Sint16(sint16 source,sint16 *target);
extern uint8 DataConvert_TypeConvert_Sint162Sint32(sint16 source,sint32 *target);
extern uint8 DataConvert_TypeConvert_Sint162Sint64(sint16 source,sint64 *target);
extern uint8 DataConvert_TypeConvert_Sint162Float32(sint16 source,float32 *target);
extern uint8 DataConvert_TypeConvert_Sint162Float64(sint16 source,float64 *target);
extern uint8 DataConvert_TypeConvert_Sint322Boolean(sint32 source,boolean *target);
extern uint8 DataConvert_TypeConvert_Sint322Uint8(sint32 source,uint8 *target);
extern uint8 DataConvert_TypeConvert_Sint322Uint16(sint32 source,uint16 *target);
extern uint8 DataConvert_TypeConvert_Sint322Uint32(sint32 source,uint32 *target);
extern uint8 DataConvert_TypeConvert_Sint322Uint64(sint32 source,uint64 *target);
extern uint8 DataConvert_TypeConvert_Sint322Sint8(sint32 source,sint8 *target);
extern uint8 DataConvert_TypeConvert_Sint322Sint16(sint32 source,sint16 *target);
extern uint8 DataConvert_TypeConvert_Sint322Sint32(sint32 source,sint32 *target);
extern uint8 DataConvert_TypeConvert_Sint322Sint64(sint32 source,sint64 *target);
extern uint8 DataConvert_TypeConvert_Sint322Float32(sint32 source,float32 *target);
extern uint8 DataConvert_TypeConvert_Sint322Float64(sint32 source,float64 *target);
extern uint8 DataConvert_TypeConvert_Sint642Boolean(sint64 source,boolean *target);
extern uint8 DataConvert_TypeConvert_Sint642Uint8(sint64 source,uint8 *target);
extern uint8 DataConvert_TypeConvert_Sint642Uint16(sint64 source,uint16 *target);
extern uint8 DataConvert_TypeConvert_Sint642Uint32(sint64 source,uint32 *target);
extern uint8 DataConvert_TypeConvert_Sint642Uint64(sint64 source,uint64 *target);
extern uint8 DataConvert_TypeConvert_Sint642Sint8(sint64 source,sint8 *target);
extern uint8 DataConvert_TypeConvert_Sint642Sint16(sint64 source,sint16 *target);
extern uint8 DataConvert_TypeConvert_Sint642Sint32(sint64 source,sint32 *target);
extern uint8 DataConvert_TypeConvert_Sint642Sint64(sint64 source,sint64 *target);
extern uint8 DataConvert_TypeConvert_Sint642Float32(sint64 source,float32 *target);
extern uint8 DataConvert_TypeConvert_Sint642Float64(sint64 source,float64 *target);
extern uint8 DataConvert_TypeConvert_Float322Boolean(float32 source,boolean *target);
extern uint8 DataConvert_TypeConvert_Float322Uint8(float32 source,uint8 *target);
extern uint8 DataConvert_TypeConvert_Float322Uint16(float32 source,uint16 *target);
extern uint8 DataConvert_TypeConvert_Float322Uint32(float32 source,uint32 *target);
extern uint8 DataConvert_TypeConvert_Float322Uint64(float32 source,uint64 *target);
extern uint8 DataConvert_TypeConvert_Float322Sint8(float32 source,sint8 *target);
extern uint8 DataConvert_TypeConvert_Float322Sint16(float32 source,sint16 *target);
extern uint8 DataConvert_TypeConvert_Float322Sint32(float32 source,sint32 *target);
extern uint8 DataConvert_TypeConvert_Float322Sint64(float32 source,sint64 *target);
extern uint8 DataConvert_TypeConvert_Float322Float32(float32 source,float32 *target);
extern uint8 DataConvert_TypeConvert_Float322Float64(float32 source,float64 *target);
extern uint8 DataConvert_TypeConvert_Float642Boolean(float64 source,boolean *target);
extern uint8 DataConvert_TypeConvert_Float642Uint8(float64 source,uint8 *target);
extern uint8 DataConvert_TypeConvert_Float642Uint16(float64 source,uint16 *target);
extern uint8 DataConvert_TypeConvert_Float642Uint32(float64 source,uint32 *target);
extern uint8 DataConvert_TypeConvert_Float642Uint64(float64 source,uint64 *target);
extern uint8 DataConvert_TypeConvert_Float642Sint8(float64 source,sint8 *target);
extern uint8 DataConvert_TypeConvert_Float642Sint16(float64 source,sint16 *target);
extern uint8 DataConvert_TypeConvert_Float642Sint32(float64 source,sint32 *target);
extern uint8 DataConvert_TypeConvert_Float642Sint64(float64 source,sint64 *target);
extern uint8 DataConvert_TypeConvert_Float642Float32(float64 source,float32 *target);
extern uint8 DataConvert_TypeConvert_Float642Float64(float64 source,float64 *target);

extern uint8 DataConvert_LinearConvert_Uint82Boolean(float32 factor,float32 offset,uint8 source,boolean *target);
extern uint8 DataConvert_LinearConvert_Uint82Uint8(float32 factor,float32 offset,uint8 source,uint8 *target);
extern uint8 DataConvert_LinearConvert_Uint82Uint16(float32 factor,float32 offset,uint8 source,uint16 *target);
extern uint8 DataConvert_LinearConvert_Uint82Uint32(float32 factor,float32 offset,uint8 source,uint32 *target);
extern uint8 DataConvert_LinearConvert_Uint82Uint64(float32 factor,float32 offset,uint8 source,uint64 *target);
extern uint8 DataConvert_LinearConvert_Uint82Sint8(float32 factor,float32 offset,uint8 source,sint8 *target);
extern uint8 DataConvert_LinearConvert_Uint82Sint16(float32 factor,float32 offset,uint8 source,sint16 *target);
extern uint8 DataConvert_LinearConvert_Uint82Sint32(float32 factor,float32 offset,uint8 source,sint32 *target);
extern uint8 DataConvert_LinearConvert_Uint82Sint64(float32 factor,float32 offset,uint8 source,sint64 *target);
extern uint8 DataConvert_LinearConvert_Uint82Float32(float32 factor,float32 offset,uint8 source,float32 *target);
extern uint8 DataConvert_LinearConvert_Uint82Float64(float32 factor,float32 offset,uint8 source,float64 *target);
extern uint8 DataConvert_LinearConvert_Uint162Boolean(float32 factor,float32 offset,uint16 source,boolean *target);
extern uint8 DataConvert_LinearConvert_Uint162Uint8(float32 factor,float32 offset,uint16 source,uint8 *target);
extern uint8 DataConvert_LinearConvert_Uint162Uint16(float32 factor,float32 offset,uint16 source,uint16 *target);
extern uint8 DataConvert_LinearConvert_Uint162Uint32(float32 factor,float32 offset,uint16 source,uint32 *target);
extern uint8 DataConvert_LinearConvert_Uint162Uint64(float32 factor,float32 offset,uint16 source,uint64 *target);
extern uint8 DataConvert_LinearConvert_Uint162Sint8(float32 factor,float32 offset,uint16 source,sint8 *target);
extern uint8 DataConvert_LinearConvert_Uint162Sint16(float32 factor,float32 offset,uint16 source,sint16 *target);
extern uint8 DataConvert_LinearConvert_Uint162Sint32(float32 factor,float32 offset,uint16 source,sint32 *target);
extern uint8 DataConvert_LinearConvert_Uint162Sint64(float32 factor,float32 offset,uint16 source,sint64 *target);
extern uint8 DataConvert_LinearConvert_Uint162Float32(float32 factor,float32 offset,uint16 source,float32 *target);
extern uint8 DataConvert_LinearConvert_Uint162Float64(float32 factor,float32 offset,uint16 source,float64 *target);
extern uint8 DataConvert_LinearConvert_Uint322Boolean(float32 factor,float32 offset,uint32 source,boolean *target);
extern uint8 DataConvert_LinearConvert_Uint322Uint8(float32 factor,float32 offset,uint32 source,uint8 *target);
extern uint8 DataConvert_LinearConvert_Uint322Uint16(float32 factor,float32 offset,uint32 source,uint16 *target);
extern uint8 DataConvert_LinearConvert_Uint322Uint32(float32 factor,float32 offset,uint32 source,uint32 *target);
extern uint8 DataConvert_LinearConvert_Uint322Uint64(float32 factor,float32 offset,uint32 source,uint64 *target);
extern uint8 DataConvert_LinearConvert_Uint322Sint8(float32 factor,float32 offset,uint32 source,sint8 *target);
extern uint8 DataConvert_LinearConvert_Uint322Sint16(float32 factor,float32 offset,uint32 source,sint16 *target);
extern uint8 DataConvert_LinearConvert_Uint322Sint32(float32 factor,float32 offset,uint32 source,sint32 *target);
extern uint8 DataConvert_LinearConvert_Uint322Sint64(float32 factor,float32 offset,uint32 source,sint64 *target);
extern uint8 DataConvert_LinearConvert_Uint322Float32(float32 factor,float32 offset,uint32 source,float32 *target);
extern uint8 DataConvert_LinearConvert_Uint322Float64(float32 factor,float32 offset,uint32 source,float64 *target);
extern uint8 DataConvert_LinearConvert_Uint642Boolean(float32 factor,float32 offset,uint64 source,boolean *target);
extern uint8 DataConvert_LinearConvert_Uint642Uint8(float32 factor,float32 offset,uint64 source,uint8 *target);
extern uint8 DataConvert_LinearConvert_Uint642Uint16(float32 factor,float32 offset,uint64 source,uint16 *target);
extern uint8 DataConvert_LinearConvert_Uint642Uint32(float32 factor,float32 offset,uint64 source,uint32 *target);
extern uint8 DataConvert_LinearConvert_Uint642Uint64(float32 factor,float32 offset,uint64 source,uint64 *target);
extern uint8 DataConvert_LinearConvert_Uint642Sint8(float32 factor,float32 offset,uint64 source,sint8 *target);
extern uint8 DataConvert_LinearConvert_Uint642Sint16(float32 factor,float32 offset,uint64 source,sint16 *target);
extern uint8 DataConvert_LinearConvert_Uint642Sint32(float32 factor,float32 offset,uint64 source,sint32 *target);
extern uint8 DataConvert_LinearConvert_Uint642Sint64(float32 factor,float32 offset,uint64 source,sint64 *target);
extern uint8 DataConvert_LinearConvert_Uint642Float32(float32 factor,float32 offset,uint64 source,float32 *target);
extern uint8 DataConvert_LinearConvert_Uint642Float64(float32 factor,float32 offset,uint64 source,float64 *target);
extern uint8 DataConvert_LinearConvert_Sint82Boolean(float32 factor,float32 offset,sint8 source,boolean *target);
extern uint8 DataConvert_LinearConvert_Sint82Uint8(float32 factor,float32 offset,sint8 source,uint8 *target);
extern uint8 DataConvert_LinearConvert_Sint82Uint16(float32 factor,float32 offset,sint8 source,uint16 *target);
extern uint8 DataConvert_LinearConvert_Sint82Uint32(float32 factor,float32 offset,sint8 source,uint32 *target);
extern uint8 DataConvert_LinearConvert_Sint82Uint64(float32 factor,float32 offset,sint8 source,uint64 *target);
extern uint8 DataConvert_LinearConvert_Sint82Sint8(float32 factor,float32 offset,sint8 source,sint8 *target);
extern uint8 DataConvert_LinearConvert_Sint82Sint16(float32 factor,float32 offset,sint8 source,sint16 *target);
extern uint8 DataConvert_LinearConvert_Sint82Sint32(float32 factor,float32 offset,sint8 source,sint32 *target);
extern uint8 DataConvert_LinearConvert_Sint82Sint64(float32 factor,float32 offset,sint8 source,sint64 *target);
extern uint8 DataConvert_LinearConvert_Sint82Float32(float32 factor,float32 offset,sint8 source,float32 *target);
extern uint8 DataConvert_LinearConvert_Sint82Float64(float32 factor,float32 offset,sint8 source,float64 *target);
extern uint8 DataConvert_LinearConvert_Sint162Boolean(float32 factor,float32 offset,sint16 source,boolean *target);
extern uint8 DataConvert_LinearConvert_Sint162Uint8(float32 factor,float32 offset,sint16 source,uint8 *target);
extern uint8 DataConvert_LinearConvert_Sint162Uint16(float32 factor,float32 offset,sint16 source,uint16 *target);
extern uint8 DataConvert_LinearConvert_Sint162Uint32(float32 factor,float32 offset,sint16 source,uint32 *target);
extern uint8 DataConvert_LinearConvert_Sint162Uint64(float32 factor,float32 offset,sint16 source,uint64 *target);
extern uint8 DataConvert_LinearConvert_Sint162Sint8(float32 factor,float32 offset,sint16 source,sint8 *target);
extern uint8 DataConvert_LinearConvert_Sint162Sint16(float32 factor,float32 offset,sint16 source,sint16 *target);
extern uint8 DataConvert_LinearConvert_Sint162Sint32(float32 factor,float32 offset,sint16 source,sint32 *target);
extern uint8 DataConvert_LinearConvert_Sint162Sint64(float32 factor,float32 offset,sint16 source,sint64 *target);
extern uint8 DataConvert_LinearConvert_Sint162Float32(float32 factor,float32 offset,sint16 source,float32 *target);
extern uint8 DataConvert_LinearConvert_Sint162Float64(float32 factor,float32 offset,sint16 source,float64 *target);
extern uint8 DataConvert_LinearConvert_Sint322Boolean(float32 factor,float32 offset,sint32 source,boolean *target);
extern uint8 DataConvert_LinearConvert_Sint322Uint8(float32 factor,float32 offset,sint32 source,uint8 *target);
extern uint8 DataConvert_LinearConvert_Sint322Uint16(float32 factor,float32 offset,sint32 source,uint16 *target);
extern uint8 DataConvert_LinearConvert_Sint322Uint32(float32 factor,float32 offset,sint32 source,uint32 *target);
extern uint8 DataConvert_LinearConvert_Sint322Uint64(float32 factor,float32 offset,sint32 source,uint64 *target);
extern uint8 DataConvert_LinearConvert_Sint322Sint8(float32 factor,float32 offset,sint32 source,sint8 *target);
extern uint8 DataConvert_LinearConvert_Sint322Sint16(float32 factor,float32 offset,sint32 source,sint16 *target);
extern uint8 DataConvert_LinearConvert_Sint322Sint32(float32 factor,float32 offset,sint32 source,sint32 *target);
extern uint8 DataConvert_LinearConvert_Sint322Sint64(float32 factor,float32 offset,sint32 source,sint64 *target);
extern uint8 DataConvert_LinearConvert_Sint322Float32(float32 factor,float32 offset,sint32 source,float32 *target);
extern uint8 DataConvert_LinearConvert_Sint322Float64(float32 factor,float32 offset,sint32 source,float64 *target);
extern uint8 DataConvert_LinearConvert_Sint642Boolean(float32 factor,float32 offset,sint64 source,boolean *target);
extern uint8 DataConvert_LinearConvert_Sint642Uint8(float32 factor,float32 offset,sint64 source,uint8 *target);
extern uint8 DataConvert_LinearConvert_Sint642Uint16(float32 factor,float32 offset,sint64 source,uint16 *target);
extern uint8 DataConvert_LinearConvert_Sint642Uint32(float32 factor,float32 offset,sint64 source,uint32 *target);
extern uint8 DataConvert_LinearConvert_Sint642Uint64(float32 factor,float32 offset,sint64 source,uint64 *target);
extern uint8 DataConvert_LinearConvert_Sint642Sint8(float32 factor,float32 offset,sint64 source,sint8 *target);
extern uint8 DataConvert_LinearConvert_Sint642Sint16(float32 factor,float32 offset,sint64 source,sint16 *target);
extern uint8 DataConvert_LinearConvert_Sint642Sint32(float32 factor,float32 offset,sint64 source,sint32 *target);
extern uint8 DataConvert_LinearConvert_Sint642Sint64(float32 factor,float32 offset,sint64 source,sint64 *target);
extern uint8 DataConvert_LinearConvert_Sint642Float32(float32 factor,float32 offset,sint64 source,float32 *target);
extern uint8 DataConvert_LinearConvert_Sint642Float64(float32 factor,float32 offset,sint64 source,float64 *target);
extern uint8 DataConvert_LinearConvert_Float322Boolean(float32 factor,float32 offset,float32 source,boolean *target);
extern uint8 DataConvert_LinearConvert_Float322Uint8(float32 factor,float32 offset,float32 source,uint8 *target);
extern uint8 DataConvert_LinearConvert_Float322Uint16(float32 factor,float32 offset,float32 source,uint16 *target);
extern uint8 DataConvert_LinearConvert_Float322Uint32(float32 factor,float32 offset,float32 source,uint32 *target);
extern uint8 DataConvert_LinearConvert_Float322Uint64(float32 factor,float32 offset,float32 source,uint64 *target);
extern uint8 DataConvert_LinearConvert_Float322Sint8(float32 factor,float32 offset,float32 source,sint8 *target);
extern uint8 DataConvert_LinearConvert_Float322Sint16(float32 factor,float32 offset,float32 source,sint16 *target);
extern uint8 DataConvert_LinearConvert_Float322Sint32(float32 factor,float32 offset,float32 source,sint32 *target);
extern uint8 DataConvert_LinearConvert_Float322Sint64(float32 factor,float32 offset,float32 source,sint64 *target);
extern uint8 DataConvert_LinearConvert_Float322Float32(float32 factor,float32 offset,float32 source,float32 *target);
extern uint8 DataConvert_LinearConvert_Float322Float64(float32 factor,float32 offset,float32 source,float64 *target);
extern uint8 DataConvert_LinearConvert_Float642Boolean(float32 factor,float32 offset,float64 source,boolean *target);
extern uint8 DataConvert_LinearConvert_Float642Uint8(float32 factor,float32 offset,float64 source,uint8 *target);
extern uint8 DataConvert_LinearConvert_Float642Uint16(float32 factor,float32 offset,float64 source,uint16 *target);
extern uint8 DataConvert_LinearConvert_Float642Uint32(float32 factor,float32 offset,float64 source,uint32 *target);
extern uint8 DataConvert_LinearConvert_Float642Uint64(float32 factor,float32 offset,float64 source,uint64 *target);
extern uint8 DataConvert_LinearConvert_Float642Sint8(float32 factor,float32 offset,float64 source,sint8 *target);
extern uint8 DataConvert_LinearConvert_Float642Sint16(float32 factor,float32 offset,float64 source,sint16 *target);
extern uint8 DataConvert_LinearConvert_Float642Sint32(float32 factor,float32 offset,float64 source,sint32 *target);
extern uint8 DataConvert_LinearConvert_Float642Sint64(float32 factor,float32 offset,float64 source,sint64 *target);
extern uint8 DataConvert_LinearConvert_Float642Float32(float32 factor,float32 offset,float64 source,float32 *target);
extern uint8 DataConvert_LinearConvert_Float642Float64(float32 factor,float32 offset,float64 source,float64 *target);

extern uint8 DataConvert_DeLinearConvert_Uint82Boolean(float32 factor,float32 offset,uint8 source,boolean *target);
extern uint8 DataConvert_DeLinearConvert_Uint82Uint8(float32 factor,float32 offset,uint8 source,uint8 *target);
extern uint8 DataConvert_DeLinearConvert_Uint82Uint16(float32 factor,float32 offset,uint8 source,uint16 *target);
extern uint8 DataConvert_DeLinearConvert_Uint82Uint32(float32 factor,float32 offset,uint8 source,uint32 *target);
extern uint8 DataConvert_DeLinearConvert_Uint82Uint64(float32 factor,float32 offset,uint8 source,uint64 *target);
extern uint8 DataConvert_DeLinearConvert_Uint82Sint8(float32 factor,float32 offset,uint8 source,sint8 *target);
extern uint8 DataConvert_DeLinearConvert_Uint82Sint16(float32 factor,float32 offset,uint8 source,sint16 *target);
extern uint8 DataConvert_DeLinearConvert_Uint82Sint32(float32 factor,float32 offset,uint8 source,sint32 *target);
extern uint8 DataConvert_DeLinearConvert_Uint82Sint64(float32 factor,float32 offset,uint8 source,sint64 *target);
extern uint8 DataConvert_DeLinearConvert_Uint82Float32(float32 factor,float32 offset,uint8 source,float32 *target);
extern uint8 DataConvert_DeLinearConvert_Uint82Float64(float32 factor,float32 offset,uint8 source,float64 *target);
extern uint8 DataConvert_DeLinearConvert_Uint162Boolean(float32 factor,float32 offset,uint16 source,boolean *target);
extern uint8 DataConvert_DeLinearConvert_Uint162Uint8(float32 factor,float32 offset,uint16 source,uint8 *target);
extern uint8 DataConvert_DeLinearConvert_Uint162Uint16(float32 factor,float32 offset,uint16 source,uint16 *target);
extern uint8 DataConvert_DeLinearConvert_Uint162Uint32(float32 factor,float32 offset,uint16 source,uint32 *target);
extern uint8 DataConvert_DeLinearConvert_Uint162Uint64(float32 factor,float32 offset,uint16 source,uint64 *target);
extern uint8 DataConvert_DeLinearConvert_Uint162Sint8(float32 factor,float32 offset,uint16 source,sint8 *target);
extern uint8 DataConvert_DeLinearConvert_Uint162Sint16(float32 factor,float32 offset,uint16 source,sint16 *target);
extern uint8 DataConvert_DeLinearConvert_Uint162Sint32(float32 factor,float32 offset,uint16 source,sint32 *target);
extern uint8 DataConvert_DeLinearConvert_Uint162Sint64(float32 factor,float32 offset,uint16 source,sint64 *target);
extern uint8 DataConvert_DeLinearConvert_Uint162Float32(float32 factor,float32 offset,uint16 source,float32 *target);
extern uint8 DataConvert_DeLinearConvert_Uint162Float64(float32 factor,float32 offset,uint16 source,float64 *target);
extern uint8 DataConvert_DeLinearConvert_Uint322Boolean(float32 factor,float32 offset,uint32 source,boolean *target);
extern uint8 DataConvert_DeLinearConvert_Uint322Uint8(float32 factor,float32 offset,uint32 source,uint8 *target);
extern uint8 DataConvert_DeLinearConvert_Uint322Uint16(float32 factor,float32 offset,uint32 source,uint16 *target);
extern uint8 DataConvert_DeLinearConvert_Uint322Uint32(float32 factor,float32 offset,uint32 source,uint32 *target);
extern uint8 DataConvert_DeLinearConvert_Uint322Uint64(float32 factor,float32 offset,uint32 source,uint64 *target);
extern uint8 DataConvert_DeLinearConvert_Uint322Sint8(float32 factor,float32 offset,uint32 source,sint8 *target);
extern uint8 DataConvert_DeLinearConvert_Uint322Sint16(float32 factor,float32 offset,uint32 source,sint16 *target);
extern uint8 DataConvert_DeLinearConvert_Uint322Sint32(float32 factor,float32 offset,uint32 source,sint32 *target);
extern uint8 DataConvert_DeLinearConvert_Uint322Sint64(float32 factor,float32 offset,uint32 source,sint64 *target);
extern uint8 DataConvert_DeLinearConvert_Uint322Float32(float32 factor,float32 offset,uint32 source,float32 *target);
extern uint8 DataConvert_DeLinearConvert_Uint322Float64(float32 factor,float32 offset,uint32 source,float64 *target);
extern uint8 DataConvert_DeLinearConvert_Uint642Boolean(float32 factor,float32 offset,uint64 source,boolean *target);
extern uint8 DataConvert_DeLinearConvert_Uint642Uint8(float32 factor,float32 offset,uint64 source,uint8 *target);
extern uint8 DataConvert_DeLinearConvert_Uint642Uint16(float32 factor,float32 offset,uint64 source,uint16 *target);
extern uint8 DataConvert_DeLinearConvert_Uint642Uint32(float32 factor,float32 offset,uint64 source,uint32 *target);
extern uint8 DataConvert_DeLinearConvert_Uint642Uint64(float32 factor,float32 offset,uint64 source,uint64 *target);
extern uint8 DataConvert_DeLinearConvert_Uint642Sint8(float32 factor,float32 offset,uint64 source,sint8 *target);
extern uint8 DataConvert_DeLinearConvert_Uint642Sint16(float32 factor,float32 offset,uint64 source,sint16 *target);
extern uint8 DataConvert_DeLinearConvert_Uint642Sint32(float32 factor,float32 offset,uint64 source,sint32 *target);
extern uint8 DataConvert_DeLinearConvert_Uint642Sint64(float32 factor,float32 offset,uint64 source,sint64 *target);
extern uint8 DataConvert_DeLinearConvert_Uint642Float32(float32 factor,float32 offset,uint64 source,float32 *target);
extern uint8 DataConvert_DeLinearConvert_Uint642Float64(float32 factor,float32 offset,uint64 source,float64 *target);
extern uint8 DataConvert_DeLinearConvert_Sint82Boolean(float32 factor,float32 offset,sint8 source,boolean *target);
extern uint8 DataConvert_DeLinearConvert_Sint82Uint8(float32 factor,float32 offset,sint8 source,uint8 *target);
extern uint8 DataConvert_DeLinearConvert_Sint82Uint16(float32 factor,float32 offset,sint8 source,uint16 *target);
extern uint8 DataConvert_DeLinearConvert_Sint82Uint32(float32 factor,float32 offset,sint8 source,uint32 *target);
extern uint8 DataConvert_DeLinearConvert_Sint82Uint64(float32 factor,float32 offset,sint8 source,uint64 *target);
extern uint8 DataConvert_DeLinearConvert_Sint82Sint8(float32 factor,float32 offset,sint8 source,sint8 *target);
extern uint8 DataConvert_DeLinearConvert_Sint82Sint16(float32 factor,float32 offset,sint8 source,sint16 *target);
extern uint8 DataConvert_DeLinearConvert_Sint82Sint32(float32 factor,float32 offset,sint8 source,sint32 *target);
extern uint8 DataConvert_DeLinearConvert_Sint82Sint64(float32 factor,float32 offset,sint8 source,sint64 *target);
extern uint8 DataConvert_DeLinearConvert_Sint82Float32(float32 factor,float32 offset,sint8 source,float32 *target);
extern uint8 DataConvert_DeLinearConvert_Sint82Float64(float32 factor,float32 offset,sint8 source,float64 *target);
extern uint8 DataConvert_DeLinearConvert_Sint162Boolean(float32 factor,float32 offset,sint16 source,boolean *target);
extern uint8 DataConvert_DeLinearConvert_Sint162Uint8(float32 factor,float32 offset,sint16 source,uint8 *target);
extern uint8 DataConvert_DeLinearConvert_Sint162Uint16(float32 factor,float32 offset,sint16 source,uint16 *target);
extern uint8 DataConvert_DeLinearConvert_Sint162Uint32(float32 factor,float32 offset,sint16 source,uint32 *target);
extern uint8 DataConvert_DeLinearConvert_Sint162Uint64(float32 factor,float32 offset,sint16 source,uint64 *target);
extern uint8 DataConvert_DeLinearConvert_Sint162Sint8(float32 factor,float32 offset,sint16 source,sint8 *target);
extern uint8 DataConvert_DeLinearConvert_Sint162Sint16(float32 factor,float32 offset,sint16 source,sint16 *target);
extern uint8 DataConvert_DeLinearConvert_Sint162Sint32(float32 factor,float32 offset,sint16 source,sint32 *target);
extern uint8 DataConvert_DeLinearConvert_Sint162Sint64(float32 factor,float32 offset,sint16 source,sint64 *target);
extern uint8 DataConvert_DeLinearConvert_Sint162Float32(float32 factor,float32 offset,sint16 source,float32 *target);
extern uint8 DataConvert_DeLinearConvert_Sint162Float64(float32 factor,float32 offset,sint16 source,float64 *target);
extern uint8 DataConvert_DeLinearConvert_Sint322Boolean(float32 factor,float32 offset,sint32 source,boolean *target);
extern uint8 DataConvert_DeLinearConvert_Sint322Uint8(float32 factor,float32 offset,sint32 source,uint8 *target);
extern uint8 DataConvert_DeLinearConvert_Sint322Uint16(float32 factor,float32 offset,sint32 source,uint16 *target);
extern uint8 DataConvert_DeLinearConvert_Sint322Uint32(float32 factor,float32 offset,sint32 source,uint32 *target);
extern uint8 DataConvert_DeLinearConvert_Sint322Uint64(float32 factor,float32 offset,sint32 source,uint64 *target);
extern uint8 DataConvert_DeLinearConvert_Sint322Sint8(float32 factor,float32 offset,sint32 source,sint8 *target);
extern uint8 DataConvert_DeLinearConvert_Sint322Sint16(float32 factor,float32 offset,sint32 source,sint16 *target);
extern uint8 DataConvert_DeLinearConvert_Sint322Sint32(float32 factor,float32 offset,sint32 source,sint32 *target);
extern uint8 DataConvert_DeLinearConvert_Sint322Sint64(float32 factor,float32 offset,sint32 source,sint64 *target);
extern uint8 DataConvert_DeLinearConvert_Sint322Float32(float32 factor,float32 offset,sint32 source,float32 *target);
extern uint8 DataConvert_DeLinearConvert_Sint322Float64(float32 factor,float32 offset,sint32 source,float64 *target);
extern uint8 DataConvert_DeLinearConvert_Sint642Boolean(float32 factor,float32 offset,sint64 source,boolean *target);
extern uint8 DataConvert_DeLinearConvert_Sint642Uint8(float32 factor,float32 offset,sint64 source,uint8 *target);
extern uint8 DataConvert_DeLinearConvert_Sint642Uint16(float32 factor,float32 offset,sint64 source,uint16 *target);
extern uint8 DataConvert_DeLinearConvert_Sint642Uint32(float32 factor,float32 offset,sint64 source,uint32 *target);
extern uint8 DataConvert_DeLinearConvert_Sint642Uint64(float32 factor,float32 offset,sint64 source,uint64 *target);
extern uint8 DataConvert_DeLinearConvert_Sint642Sint8(float32 factor,float32 offset,sint64 source,sint8 *target);
extern uint8 DataConvert_DeLinearConvert_Sint642Sint16(float32 factor,float32 offset,sint64 source,sint16 *target);
extern uint8 DataConvert_DeLinearConvert_Sint642Sint32(float32 factor,float32 offset,sint64 source,sint32 *target);
extern uint8 DataConvert_DeLinearConvert_Sint642Sint64(float32 factor,float32 offset,sint64 source,sint64 *target);
extern uint8 DataConvert_DeLinearConvert_Sint642Float32(float32 factor,float32 offset,sint64 source,float32 *target);
extern uint8 DataConvert_DeLinearConvert_Sint642Float64(float32 factor,float32 offset,sint64 source,float64 *target);
extern uint8 DataConvert_DeLinearConvert_Float322Boolean(float32 factor,float32 offset,float32 source,boolean *target);
extern uint8 DataConvert_DeLinearConvert_Float322Uint8(float32 factor,float32 offset,float32 source,uint8 *target);
extern uint8 DataConvert_DeLinearConvert_Float322Uint16(float32 factor,float32 offset,float32 source,uint16 *target);
extern uint8 DataConvert_DeLinearConvert_Float322Uint32(float32 factor,float32 offset,float32 source,uint32 *target);
extern uint8 DataConvert_DeLinearConvert_Float322Uint64(float32 factor,float32 offset,float32 source,uint64 *target);
extern uint8 DataConvert_DeLinearConvert_Float322Sint8(float32 factor,float32 offset,float32 source,sint8 *target);
extern uint8 DataConvert_DeLinearConvert_Float322Sint16(float32 factor,float32 offset,float32 source,sint16 *target);
extern uint8 DataConvert_DeLinearConvert_Float322Sint32(float32 factor,float32 offset,float32 source,sint32 *target);
extern uint8 DataConvert_DeLinearConvert_Float322Sint64(float32 factor,float32 offset,float32 source,sint64 *target);
extern uint8 DataConvert_DeLinearConvert_Float322Float32(float32 factor,float32 offset,float32 source,float32 *target);
extern uint8 DataConvert_DeLinearConvert_Float322Float64(float32 factor,float32 offset,float32 source,float64 *target);
extern uint8 DataConvert_DeLinearConvert_Float642Boolean(float32 factor,float32 offset,float64 source,boolean *target);
extern uint8 DataConvert_DeLinearConvert_Float642Uint8(float32 factor,float32 offset,float64 source,uint8 *target);
extern uint8 DataConvert_DeLinearConvert_Float642Uint16(float32 factor,float32 offset,float64 source,uint16 *target);
extern uint8 DataConvert_DeLinearConvert_Float642Uint32(float32 factor,float32 offset,float64 source,uint32 *target);
extern uint8 DataConvert_DeLinearConvert_Float642Uint64(float32 factor,float32 offset,float64 source,uint64 *target);
extern uint8 DataConvert_DeLinearConvert_Float642Sint8(float32 factor,float32 offset,float64 source,sint8 *target);
extern uint8 DataConvert_DeLinearConvert_Float642Sint16(float32 factor,float32 offset,float64 source,sint16 *target);
extern uint8 DataConvert_DeLinearConvert_Float642Sint32(float32 factor,float32 offset,float64 source,sint32 *target);
extern uint8 DataConvert_DeLinearConvert_Float642Sint64(float32 factor,float32 offset,float64 source,sint64 *target);
extern uint8 DataConvert_DeLinearConvert_Float642Float32(float32 factor,float32 offset,float64 source,float32 *target);
extern uint8 DataConvert_DeLinearConvert_Float642Float64(float32 factor,float32 offset,float64 source,float64 *target);

#define DATACONVERT_STOP_SEC_CODE
#include "DataConvert_MemMap.h"

#endif /* _DATACONVERT_H_ */
