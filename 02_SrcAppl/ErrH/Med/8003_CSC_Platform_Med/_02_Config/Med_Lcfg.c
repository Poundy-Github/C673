/**
 * \file Med_Lcfg.c
 *
 * \brief
 *
 * \version refer the Med_Core.h.
 *
 */
/*==================[inclusions]============================================*/
#include "Med_Lcfg.h"
#include "Med_Stubs.h"
#include "Dem_IntEvtId.h"

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/
extern const s_Med_ErrorDetectionConfig_t Med_ErrorDetectionConfigTable[MED_ERROR_DETECTION_NUMBER] =
{/*						EventId,								MonitorCycle,	DebounceEnable,			Mode,				Op_CheckPreCond,				Op_TestFailed,						Op_TestPassed*/
	/* 0*/ {DemConf_DemEventParameter_DEM_VMON_BATT_LOW, 			10, 			STD_ON, 		Med_ErrDetMode_Mutex, 		NULL_PTR, 		Med_Cot_TestFailed_BattVoltTooLow, 					NULL_PTR }
	/* 1*/,{DemConf_DemEventParameter_DEM_VMON_BATT_HIGH, 			10, 			STD_ON, 		Med_ErrDetMode_Mutex, 		NULL_PTR, 		Med_Cot_TestFailed_BattVoltTooHigh, 				NULL_PTR }
};

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

