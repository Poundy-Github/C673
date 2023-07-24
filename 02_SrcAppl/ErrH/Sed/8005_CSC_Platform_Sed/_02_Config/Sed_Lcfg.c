/**
 * \file Sed_Lcfg.c
 *
 * \brief
 *
 * \version refer the Sed_Core.h.
 *
 */
/*==================[inclusions]============================================*/
#include "Sed_Lcfg.h"
#include "Sed_Stubs.h"
#include "Dem_IntEvtId.h"

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/
extern const s_Sed_ErrorDetectionConfig_t Sed_ErrorDetectionConfigTable[SED_ERROR_DETECTION_NUMBER] =
{/*						EventId,								MonitorCycle,	DebounceEnable,			Mode,				Op_CheckPreCond,				Op_TestFailed,						Op_TestPassed*/
	/* 0*/ {DemConf_DemEventParameter_DEM_VMON_BATT_LOW, 			10, 			STD_ON, 		Sed_ErrDetMode_Mutex, 		NULL_PTR, 		Sed_Cot_TestFailed_BattVoltTooLow, 					NULL_PTR }
	/* 1*/,{DemConf_DemEventParameter_DEM_VMON_BATT_HIGH, 			10, 			STD_ON, 		Sed_ErrDetMode_Mutex, 		NULL_PTR, 		Sed_Cot_TestFailed_BattVoltTooHigh, 				NULL_PTR }
};

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

