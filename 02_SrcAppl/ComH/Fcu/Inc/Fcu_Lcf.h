/**
 * \file Fcu_Lcf.h
 *
 * \brief
 *
 * \version
 * --------------------------------------------------------------------------------------------
 * Version	| 		Data		|		Author			| 	Comments
 * V0.0.1		2023.02.08			  Kun Zhang			Init version
 * 
 *
 *
 */
#ifndef __FCU_LCF_H_
#define __FCU_LCF_H_

/*==================[inclusions]============================================*/
#include "Std_Types.h" /* AUTOSAR standard types */
#include "Fcu_Type.h"


/*==================[type definitions]=======================================*/


/*==================[external constants declarations]========================*/
 

/*==================[external data declarations]=============================*/

/*==================[external function declarations]=========================*/
extern FUNC(void, RTE_CODE) Fcu_Lcf_InitFunction(void);
extern FUNC(void, RTE_CODE) Fcu_Lcf_MainFunction(const s_Fcu_Rte_Input_SignalData_t *const ptr_Fcu_Rte_input_Signal,s_Fcu_Rte_Output_SignalData_t * const ptr_Fcu_Rte_Output_Signal);

#endif /* __FCU_LCF_H_ */