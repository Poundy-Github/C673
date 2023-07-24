/**
 * \file SystemData_CustomerCoding.h
 *
 * \brief  SystemData
 *
 * \version
 * --------------------------------------------------------------------------------------------
 * Version	| 		Date		|		Author			| 	Comments
 * V0.0.1		2023.01.22			Jinlong Zhang			Init version
 *
 *
 */
#ifndef _SYS_VEHICLEVARIANT_H_
#define _SYS_VEHICLEVARIANT_H_

/*==================[inclusions]============================================*/
#include "Std_Types.h" /* AUTOSAR standard types */
#include "Cdm_Cfg.h"
#include "Qsm_Lcfg.h" 

/*==================[macros definitions]====================================*/

#define SET_SYS_VEHVARIANT(val)    (RAM_NVM_BLOCK_Vehicletype[0] = val)

#define GET_SYS_VEHVARIANT()       (RAM_NVM_BLOCK_Vehicletype[0])


typedef enum
{
    SYS_C673_EVE         = 0x01,
	SYS_C673_PERFORMANCE = 0x02,
	SYS_C673_LBL         = 0x04, //Long battary life 
    SYS_C673_4WD         = 0x08
}e_Sys_Variant_t;

#endif

