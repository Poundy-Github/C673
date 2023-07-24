/**
 * \file Cps_Cfg.h
 *
 * \brief This file contains related data types of Cps.
 *
 * \version refer the Cps_Core.h.
 *
 */

#ifndef _CPS_CFG_H_
#define _CPS_CFG_H_
/*==================[inclusions]============================================*/
#include "Std_Types.h" /* AUTOSAR standard types */

/*==================[macros]=================================================*/
/*
 * \brief 	CPR_USE_RTE_RECEIVE_SIGNAL,
 * */
#define CPS_USE_RTE_SEND_SIGNAL								STD_OFF
/*
 * \brief 	CPS_SEND_SIGNAL_VALUE_RANGE_CHECK_ENABLE,
 * 			Check the phy vale,if the out of range,use the Error substitution value
 * */
#define CPS_SEND_SIGNAL_VALUE_RANGE_CHECK_ENABLE			STD_OFF
/*
 * \brief 	CPS_SEND_SIGNAL_STATUS_NOTIFICATION,
 * */
#define CPS_SEND_SIGNAL_STATUS_NOTIFICATION					STD_OFF
#if (CPS_SEND_SIGNAL_STATUS_NOTIFICATION == STD_ON)
/*
 * \brief 	CPS_SEND_SIGNAL_STATUS_CHANGED_NOTIFICATION,
 * */
#define CPS_SEND_SIGNAL_STATUS_CHANGED_NOTIFICATION			STD_OFF
#endif

/*
 * \brief 	CPS_USER_MAIN_FUNCTION_ENABLE,
 * */
#define CPS_USER_MAIN_FUNCTION_ENABLE			STD_ON
#if (CPS_USER_MAIN_FUNCTION_ENABLE == STD_ON)
extern void Cps_UserInitFunction(void);
#endif

#define CPS_USER_MAIN_FUNCTION_ENABLE			STD_ON
#if (CPS_USER_MAIN_FUNCTION_ENABLE == STD_ON)
extern void Cps_UserMainFunction(void);
#endif

#define CPS_MAIN_FUNCTION_PERIOD_TIME						10u
#define CPS_SEND_SIGNAL_NUMBER								1u

#endif /* _CPS_CFG_H_ */
