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

/*==================[macros]=================================================*/
#define MED_USE_RTE_REPORT_EVENT_STATUS		                STD_OFF

#define MED_ERROR_DETECTION_STATUS_CHANGED_NOTIFICATION		STD_OFF

/*
 * \brief 	MED_MAIN_FUNCTION_PERIOD_TIME
 *          unit is ms
 * */
#define MED_MAIN_FUNCTION_PERIOD_TIME			            10U

/*
 * \brief 	MED_ERROR_DETECTION_NUMBER
 * */
#define MED_ERROR_DETECTION_NUMBER			                43U 

/*
 * \brief 	MED_USERMAINFUNCTION_ENABLE
 *          STD_ON  : Med_UserMainFunction  enable
 *          STD_OFF : Med_UserMainFunction disable
 * */
#define MED_USERMAINFUNCTION_ENABLE                         STD_ON

#endif /* MED_CFG_H */
