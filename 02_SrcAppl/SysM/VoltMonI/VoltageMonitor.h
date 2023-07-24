/**
 * \file VoltageMonitor.h
 *
 * \brief This file contains the implementation of the  module VoltageMonitor.
 *
 * \version
 * --------------------------------------------------------------------------------------------
 * Version	| 		Date		|		Author			| 	Comments
 * V0.0.1		2022.11.28		 Jinlong Zhang			Init version          
 * V0.0.2       2023.02.01       Jinlong Zhang          changes voltage state to subfunction for decrease cyclomatic complexity
 * V0.0.3       2023.02.28       Jinlong Zhang          For cover the spec of ChangAn C673,modify calibration parameter
 * V0.0.4       2023.03.22       Jinlong Zhang          Delete report Event Status interface in our side.
 * \copyright  2021 - 2022 Conti Smart Core
 * 
 */
#ifndef _VOLTAGEMONITOR_H_
#define _VOLTAGEMONITOR_H_ //PRQA S 0602,0603

/*==================[inclusions]============================================*/
#include "Std_Types.h" /* AUTOSAR standard types */
#include "VoltageMonitor_Cfg.h"


/*==================[macros definitions]====================================*/


/*==================[type definitions]=======================================*/
/*
 * \brief 	e_VoltMonI_voltageState_t,
 *			When the runing Voltage machine ,the voltage state shall be in below list,
 * */
typedef enum
{
	VoltMonI_VoltageNormal = 0,
    VoltMonI_VoltageLow,
	VoltMonI_VoltageUnderLow,
	VoltMonI_VoltageHigh,
	VoltMonI_VoltageOverHigh,
	VoltMonI_VoltageMin,
	VoltMonI_VoltageMax,
    VoltMonI_VoltageInit,
	VoltMonI_VoltageInvalid
}e_VoltMonI_voltageState_t;

/*
 * \brief 	s_VoltMonI_DelayTime_t,
 *			When the runing Voltage machine ,the calibration paramter shall be in below list,
 * */
typedef struct 
{
    uint16 DelayTime_Thsld;
    uint16 DelayTime_Recover_Thsld;
}s_VoltMonI_DelayTime_t;

/*
 * \brief 	s_VoltMonI_calParm_t,
 *			When the runing Voltage machine ,the calibration paramter shall be in below list,
 * */
typedef struct 
{
    const float  Volt_Thsld;
    const float  Volt_Recover_Thsld;
    const uint16 Volt_FreezeTime_Thsld;   //base cycle :10ms
    const uint16 Volt_FreezeTime_Recover_Thsld;
}s_VoltMonI_calParm_t;

/*
 * \brief 	s_VoltMonI_Event_t,
 *			When the voltage not in normal scrope ,shall be call the below functionn to set event in Dem,
 * */
#if 0
typedef struct 
{
    uint8 (*Set_Low_Volt_EventStatus)(uint8 EventStatus);
    uint8 (*Set_High_Volt_EventStatus)(uint8 EventStatus);
}s_VoltMonI_Event_t;
#endif

/*
 * \brief 	s_VoltMonI_Action_t,
 *			 The statemachine shall be call the below action to trigger different opertion,
 * */
typedef struct 
{
    boolean Disablecommunication; /*True: disable communication, FALSE: enable communication*/
    boolean DisableSoc; /*True: Power off Soc, FALSE: Power on Soc*/
    boolean DisableECU; /*True: Power off ECU, FALSE: Power on ECU*/
}s_VoltMonI_Action_t;

/*
 * \brief 	s_VoltMonI_ConfigType_t,
 *			 The statemachine shall be call the below paramter to in life cycle ,
 * */
typedef struct 
{
    s_VoltMonI_calParm_t Min;
    s_VoltMonI_calParm_t Max;
    s_VoltMonI_calParm_t Under_Low;
    s_VoltMonI_calParm_t Low;
    s_VoltMonI_calParm_t Over_High;
    s_VoltMonI_calParm_t High; 
	boolean (*VoltMonI_StartupPrecondition)(void);
    void (*VoltMonI_Input)(void);
    void (*VoltMonI_Output)(void);
    void (*EntryInitVolt_CallBack)(void);
    void (*EntryNormalVolt_CallBack)(void);
    void (*EntryLowVolt_CallBack)(void);
    void (*EntryUnderLowVolt_CallBack)(void);
    void (*EntryHighVolt_CallBack)(void);
    void (*EntryOverHighVolt_CallBack)(void);
    void (*EntryMinVolt_CallBack)(void);
    void (*EntryMaxVolt_CallBack)(void);
}s_VoltMonI_ConfigType_t;

/*
 * \brief 	s_VoltMonI_ConfigType_t,
 *			 The run statemachine shall be call the temp paramter to in life cycle ,
 * */
typedef struct 
{   
    float inputVolt;
    uint16 Volt_Timer;
    uint16 Volt_Recover_Timer; 
    e_VoltMonI_voltageState_t globalVoltState;
    s_VoltMonI_Action_t Action;
    s_VoltMonI_DelayTime_t Min;
    s_VoltMonI_DelayTime_t Max;
    s_VoltMonI_DelayTime_t Under_Low;
    s_VoltMonI_DelayTime_t Low;
    s_VoltMonI_DelayTime_t Over_High;
    s_VoltMonI_DelayTime_t High;
}s_VoltMonI_voltmonitor_t;

/*==================[external constants declarations]========================*/
#define VoltMonI_START_SEC_CONST
#include <VoltMonI_MemMap.h>
extern const s_VoltMonI_ConfigType_t s_VoltMonI_Config;
#define VoltMonI_STOP_SEC_CONST
#include <VoltMonI_MemMap.h>

/*==================[external data declarations]=============================*/

/*==================[external function declarations]=========================*/
#define VoltMonI_START_SEC_CODE
#include <VoltMonI_MemMap.h>
extern FUNC(e_VoltMonI_voltageState_t, RTE_CODE) VoltMonI_u_GetCurrentVoltageState(void);
extern FUNC(boolean, RTE_CODE) VoltMonI_u_GetAction_Disablecommunication(void);
extern FUNC(boolean, RTE_CODE) VoltMonI_u_GetAction_DisableECU(void);
extern FUNC(boolean, RTE_CODE) VoltMonI_u_GetAction_DisableSoc(void);
extern FUNC(Std_ReturnType, RTE_CODE) VoltMonI_u_SetAction_Disablecommunication(const boolean b_State);
extern FUNC(Std_ReturnType, RTE_CODE) VoltMonI_u_SetAction_DisableECU(const boolean b_State);
extern FUNC(Std_ReturnType, RTE_CODE) VoltMonI_u_SetAction_DisableSoc(const boolean b_State);
#if (VOLTAGEMONITOR_STATE_CHANGE_NOTIFICATION_CALLOUT == STD_ON)
extern FUNC(Std_ReturnType, RTE_CODE) VoltMonI_u_StateChangeNotificationCallout(const e_VoltMonI_voltageState_t VoltMonI_PreviousState,const e_VoltMonI_voltageState_t VoltMonI_CurrentState);
#endif
extern FUNC(Std_ReturnType, RTE_CODE) VoltMonI_u_SetInputVoltage(const float f_InputVolt);
#define VoltMonI_STOP_SEC_CODE
#include <VoltMonI_MemMap.h>

#endif /*_VOLTAGEMONITOR_H_*/

