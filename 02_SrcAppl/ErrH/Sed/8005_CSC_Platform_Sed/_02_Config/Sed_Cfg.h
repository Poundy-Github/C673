/**
 * \file Sed_Cfg.h
 *
 * \brief This file contains configuration macro.
 *
 * \version refer the Sed_Core.h.
 *
 */

#ifndef SED_CFG_H
#define SED_CFG_H

/*==================[inclusions]============================================*/
#include "Std_Types.h" /* AUTOSAR standard types */

/*==================[macros]=================================================*/
#define SED_USE_RTE_REPORT_EVENT_STATUS		                STD_OFF

#define SED_ERROR_DETECTION_STATUS_CHANGED_NOTIFICATION		STD_OFF

/*
 * \brief 	SED_MAIN_FUNCTION_PERIOD_TIME
 *          unit is ms
 * */
#define SED_MAIN_FUNCTION_PERIOD_TIME			            10U

/*
 * \brief 	SED_ERROR_DETECTION_NUMBER
 * */
#define SED_ERROR_DETECTION_NUMBER			                2U 

/*
 * \brief 	SED_USERFUNCTION_ENABLE
 *          STD_ON  : Sed_UserMainFunction  enable
 *          STD_OFF : Sed_UserMainFunction disable
 * */
#define SED_USERFUNCTION_ENABLE                         STD_ON
#if(SED_USERFUNCTION_ENABLE == STD_ON)
extern void Sed_UserMainFunction(void);
extern void Sed_UserInitFunction (void);
#endif
#endif /* Sed_CFG_H */
