/**
 * \file Esh_Main.h
 *
 * \brief  Error Status Handling
 *
 * \version
 * --------------------------------------------------------------------------------------------
 * Version	| 		Date		|		Author			         | 	Comments
 * V0.0.1		2022.02.12			Jinlong Zhang(uif30295)		 Init version
 *
 *
 * \copyright  2021 - 2023 Conti Smart Core
 */
#ifndef _ESH_MAIN_H_
#define _ESH_MAIN_H_

/*==================[inclusions]============================================*/
#include "Std_Types.h" /* AUTOSAR standard types */
#include "Dbg_Cfg.h"

/*==================[macros definitions]====================================*/
#define GET_Esh_FIMSts_U17A1F0_ACTIVED()    (FALSE == Esh_FIMSts_U17A1F0)

#define GET_Esh_FIMSts_U17A1F0_NOT_ACTIVED()  (TRUE == Esh_FIMSts_U17A1F0)

#define SET_Esh_FIMSts_U17A1F0(val)  (Esh_FIMSts_U17A1F0 = val)

#define ESH_STATE_INIT            0x00U

#define ESH_STATE_INACTIVE        0x01U

#define ESH_STATE_ACTIVE          0x02U

#define ESH_STATE_STOP            0x03U

#define ESH_MAINFUNCTION_TASK_CYCLE    0x0Au   //10ms

#define ESH_FEAT_SETOPERATIONCYCLE_ENABLE                   STD_ON

#define ESH_FEAT_FUNCTIONINHIBITIION_ENABLE                 STD_ON

#define ESH_FEAT_EnableCond_PowerOnTimer_ENABLE             STD_ON

#define ESH_FEAT_EnableCond_BattVoltage_ENABLE              STD_ON

#define ESH_FEAT_EnableCond_PublicBusoff_ENABLE             STD_ON

#define ESH_FEAT_EnableCond_PrivateBusoff_ENABLE            STD_ON

#define ESH_FEAT_EnableCond_BCMPowerModeState_ENABLE        STD_ON

#define ESH_FEAT_EnableCond_ESPVehicleSpeed_ENABLE          STD_ON

#define ESH_FEAT_EnableCond_PowerOn15000ms_ENABLE           STD_ON

#define ESH_FEAT_EnableCond_PowerOn30000ms_ENABLE           STD_ON

#define ESH_FEAT_EnableCond_RTE_USED                        STD_ON

#define ESH_ENABLECONDITION_ENABLED                         STD_ON

/*==================[type definitions]=======================================*/
#if ((defined DBG_ESH_UNIT_TEST_ENABLE) && (DBG_ESH_UNIT_TEST_ENABLE == STD_ON))
typedef struct
{
  uint8 Debug_AEBStatus;
  uint8 Debug_ELKStatus;
  uint8 Debug_FCWStatus;
  uint8 Debug_HLAStatus;
  uint8 Debug_LDWStatus;
  uint8 Debug_LKAStatus;
  uint8 Debug_TSAStatus;
  uint8 Debug_FABStatus;
} s_Esh_FI_Debug_t;
#endif

#if ((defined ESH_ENABLECONDITION_ENABLED) && (ESH_ENABLECONDITION_ENABLED == STD_ON))
typedef struct
{
    /* data */
    uint8 VoltageNormal;
    uint8 Poweron3000ms;
	uint8 Poweron15000ms;
    uint8 Poweron30000ms;
    uint8 NoBusOffPublicCAN;
    uint8 NoBusOffPrivateCAN;
    uint8 VehicleSpeedNot0;
	uint8 BCMPowerModeState;
}s_Esh_EnableCondition_t;
#endif



/*==================[external constants declarations]========================*/


/*==================[external data declarations]=============================*/
extern boolean Esh_FIMSts_U17A1F0;


/*==================[external function declarations]=========================*/
extern FUNC(void, RTE_CODE) Esh_Core_OperationCycleMainFunction(void);
extern FUNC(void, RTE_CODE) Esh_Core_EnableConditionMainFunction(void);
extern FUNC(void, RTE_CODE) Esh_Core_FunctionInhibitionMainFunction(void);
#if ((defined ESH_ENABLECONDITION_ENABLED) && (ESH_ENABLECONDITION_ENABLED == STD_ON))
extern FUNC(Std_ReturnType, RTE_CODE) Esh_u_EnableCondition_Read(s_Esh_EnableCondition_t * EnableCondition);
#endif

#endif /*_ESH_MAIN_H_*/


