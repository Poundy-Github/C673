/**
 * \file Cpr_Cfg.h
 *
 * \brief This file contains related data types of Cpr.
 *
 * \version refer the Cpr_Core.h.
 *
 */

#ifndef _CPR_CFG_H_
#define _CPR_CFG_H_

/*==================[inclusions]============================================*/
#include "Std_Types.h" /* AUTOSAR standard types */

/*==================[macros]=================================================*/
/*
 * \brief 	CPR_USE_RTE_RECEIVE_SIGNAL,
 * */
#define CPR_USE_RTE_RECEIVE_SIGNAL								STD_OFF

/*
 * \brief 	CPR_RECEIVE_SIGNAL_STATUS_NOTIFICATION,
 * */
#define CPR_RECEIVE_SIGNAL_STATUS_NOTIFICATION			STD_ON

#if (CPR_RECEIVE_SIGNAL_STATUS_NOTIFICATION == STD_ON)
/*
 * \brief 	CPR_RECEIVE_SIGNAL_STATUS_CHANGED_NOTIFICATION,
 * */
#define CPR_RECEIVE_SIGNAL_STATUS_CHANGED_NOTIFICATION			STD_OFF
#endif

/*
 * \brief 	CPR_RECEIVE_SIGNAL_TIMEOUT_CHECK_ENABLE,
 * */
#define CPR_RECEIVE_SIGNAL_TIMEOUT_CHECK_ENABLE					STD_ON


/*
 * \brief 	CPR_RECEIVE_SIGNAL_VALUE_RANGE_CHECK_ENABLE,
 * */
#define CPR_RECEIVE_SIGNAL_VALUE_RANGE_CHECK_ENABLE				STD_ON

/*unit is ms*/
#define CPR_MAIN_FUNCTION_PERIOD_TIME			10U

/*
 * \brief 	CPR_USER_MAIN_FUNCTION_ENABLE,
 * */

/*
 * \brief 	CPR_USER_MAIN_FUNCTION_ENABLE,
 * */
#define CPR_USER_MAIN_FUNCTION_ENABLE			STD_ON
#if (CPR_USER_MAIN_FUNCTION_ENABLE == STD_ON)
extern void Cpr_UserInitFunction(void);
#endif

#define CPR_USER_MAIN_FUNCTION_ENABLE			STD_ON
#if (CPR_USER_MAIN_FUNCTION_ENABLE == STD_ON)
extern void Cpr_UserMainFunction(void);
#endif

#define CPR_REVEIVE_SIGNAL_NUMBER				(128U)

#define CPR_CHECK_SIGNALSTAUTS_NUMBER           (111U)


#endif /* _CPR_CFG_H_ */
