/**
 * \file Med_Cfg.h
 *
 * \brief This file contains configuration macro.
 *
 * \version refer the Med_Core.h.
 *
 */

#ifndef MED_CFG_H
#define MED_CFG_H

/*==================[inclusions]============================================*/
#include "Std_Types.h" /* AUTOSAR standard types */
#include "Dem_Cfg.h"

/*==================[macros]=================================================*/
#define MED_USE_RTE_REPORT_EVENT_STATUS		STD_OFF

#define MED_ERROR_DETECTION_STATUS_CHANGED_NOTIFICATION		STD_OFF

/*unit is ms*/
#define MED_MAIN_FUNCTION_PERIOD_TIME			10U

#define MED_ERROR_DETECTION_NUMBER			61U /*MED61*/

#define MED_EVENT_TOTAL_NUMBER              DEM_NUMBER_OF_EVENTS

#define MED_USERMAINFUNCTION_ENABLE         STD_ON

#define MED_INJECTION_ENABLED               STD_ON

#define MED_USERINITFUNCION_ENABLED         STD_ON

#define MED_ENABLECONDITION_ENABLED         STD_ON

#define MED_SENDFCSTATUS_ENABLED            STD_ON

#define MED_PARENTDTC_ENABLED               STD_ON

#define MED_ENABLECONDITION_ENABLED         STD_ON

#define MED_CANINFO_RTE_UPDATE_ENABLED      STD_ON

#define MED_HWINFO_RTE_UPDATE_ENABLED       STD_ON

/*==================[Sed bit mask definition end]==================*/

#endif /* MED_CFG_H */
