/**
 * \file LctAdapter.h
 *
 * \brief
 *
 * \version
 * --------------------------------------------------------------------------------------------
 * Version	| 		Data		|		Author			| 	Comments
 * V0.0.1		2022.03.05			Mingfen XIAO			Init version
 * V
 *
 *
 */
#ifndef LCFADAPTER_H
#define LCFADAPTER_H

/*==================[inclusions]============================================*/
#include "Std_Types.h" /* AUTOSAR standard types */
#include "CSC_Platform_Common.h"
#include "lcf_veh_iface.h"
#include "lcf_sen_main.h"
/*==================[macros]=================================================*/
#define __PDO__
/*==================[external function declarations]========================*/

extern LCF_VehDebugData_t LCFVeh_pstDbgData;
extern LCF_SenDebugData_t LCFSen_pstDbgData;


#endif /* LCFADAPTER_H */
