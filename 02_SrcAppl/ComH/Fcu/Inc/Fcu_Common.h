/**
 * \file Fcu_Common.h
 *
 * \brief
 *
 * \version
 * --------------------------------------------------------------------------------------------
 * Version	| 		Data		|		Author			| 	Comments
 * V0.0.1		2023.02.08			  Kun Zhang			Init version
 * V
 *
 *
 */
#ifndef __FCU_COMMON_H_
#define __FCU_COMMON_H_

/*==================[inclusions]============================================*/
#include "Std_Types.h" /* AUTOSAR standard types */
#include "Fcu_Type.h"
#include "TSMem.h"

/*==================[macros definitions]====================================*/
#define GET_FCU_HMI_COMMAND(val)      (FCU_SwitchData[val])

#define GET_FCU_FIMSTATE_AEB()        (Fcu_ErrorStatusInfo.AEB)

#define GET_FCU_FIMSTATE_ELK()        (Fcu_ErrorStatusInfo.ELK)

#define GET_FCU_FIMSTATE_FAB()        (Fcu_ErrorStatusInfo.FAB)

#define GET_FCU_FIMSTATE_FCW()        (Fcu_ErrorStatusInfo.FCW)

#define GET_FCU_FIMSTATE_HLA()        (Fcu_ErrorStatusInfo.HLA)

#define GET_FCU_FIMSTATE_LDW()        (Fcu_ErrorStatusInfo.LDW)

#define GET_FCU_FIMSTATE_LKA()        (Fcu_ErrorStatusInfo.LKA)

#define GET_FCU_FIMSTATE_TSA()        (Fcu_ErrorStatusInfo.TSA)

/*==================[type definitions]=======================================*/
#ifndef Fcu_const
#define Fcu_const      const
#endif
#ifndef Fcu_Static 
#define Fcu_Static     static 
#endif
#ifndef Fcu_volatile
#define Fcu_volatile   volatile
#endif
/*==================[external constants declarations]========================*/


/*==================[external data declarations]=============================*/
extern uint8 FCU_SwitchData[7];
extern s_Esh_ErrorStatusInfo_t Fcu_ErrorStatusInfo;

/*==================[external function declarations]=========================*/
extern FUNC(void, RTE_CODE) Fcu_Common_InitFunction (s_Fcu_Rte_Output_SignalData_t *ptr_Fcu_Rte_Output_Signal);
extern FUNC(void, RTE_CODE) Fcu_Common_MainFunction (void);
extern FUNC(void, RTE_CODE)  Fcu_TxProcess_FuncSwitch_WriteNvm(uint8 Switch_ID, uint8 Func_Enable);

#endif /* __FCU_COMMON_H_ */