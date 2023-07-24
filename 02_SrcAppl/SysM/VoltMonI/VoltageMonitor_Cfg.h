/**
 * \file VoltageMonitor_Cfg.h
 *
 * \brief This file contains the implementation of the  module VoltageMonitor.
 *
 * \version
 * --------------------------------------------------------------------------------------------
 * Version	| 		Date		|		Author			| 	Comments
 * V0.0.1		2022.11.28		 Jinlong Zhang			Init version          
 *
 * \copyright  2021 - 2022 Conti Smart Core
 * 
 */
#ifndef _VOLTAGEMONITOR_CFG_H_
#define _VOLTAGEMONITOR_CFG_H_ //PRQA S 0602,0603
/*==================[inclusions]============================================*/

/*==================[macros definitions]====================================*/
/** \brief Definition for voltage monitor component enabled */
#define VOLTAGEMONITOR_FUNCTION_ENABLED           STD_ON

/** \brief Definition for voltage monitor State notifcation enabled */
#define VOLTAGEMONITOR_STATE_CHANGE_NOTIFICATION_CALLOUT    STD_ON

/** \brief Definition for periodic cyclic task time in milliseconds */
#define VOLTAGEMONITOR_TASK_TIME                   (10U)

#define VOLTAGEMONITOR_VOLTAGE_INITVAL             (12.0f)

#define VOLTAGEMONITOR_IGN_ON_THSLD                (6.0f)

/*==================[type definitions]=======================================*/

/*==================[external constants declarations]========================*/

/*==================[external data declarations]=============================*/

/*==================[external function declarations]=========================*/
#define VoltMonI_START_SEC_CODE
#include <VoltMonI_MemMap.h>
extern FUNC(boolean, RTE_CODE) VoltMonI_u_StartupPrecondition(void);
extern FUNC(void, RTE_CODE) VoltMonI_u_Input(void);
extern FUNC(void, RTE_CODE) VoltMonI_u_Output(void);
extern FUNC(void, RTE_CODE) VoltMonI_u_EntryInitVolt_CallBack(void);
extern FUNC(void, RTE_CODE) VoltMonI_u_EntryNormalVolt_CallBack(void);
extern FUNC(void, RTE_CODE) VoltMonI_u_EntryLowVolt_CallBack(void);
extern FUNC(void, RTE_CODE) VoltMonI_u_EntryUnderLowVolt_CallBack(void);
extern FUNC(void, RTE_CODE) VoltMonI_u_EntryHighVolt_CallBack(void);
extern FUNC(void, RTE_CODE) VoltMonI_u_EntryOverHighVolt_CallBack(void);
extern FUNC(void, RTE_CODE) VoltMonI_u_EntryMinVolt_CallBack(void);
extern FUNC(void, RTE_CODE) VoltMonI_u_EntryMaxVolt_CallBack(void);
#define VoltMonI_STOP_SEC_CODE
#include <VoltMonI_MemMap.h>

#endif /*_VOLTAGEMONITOR_CFG_H_*/













