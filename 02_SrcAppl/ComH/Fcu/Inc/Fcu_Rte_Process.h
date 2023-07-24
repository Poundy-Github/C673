/**
 * \file Fcu_Rte_Process.h
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
#ifndef __FCU_RTE_PROCESS_H_
#define __FCU_RTE_PROCESS_H_

/*==================[inclusions]============================================*/
#include "Std_Types.h" /* AUTOSAR standard types */
#include "Fcu_Type.h"
/*==================[type definitions]=======================================*/


/*==================[external constants declarations]========================*/


/*==================[external data declarations]=============================*/

/*==================[external function declarations]=========================*/
extern FUNC(void, RTE_CODE) Fcu_Adas_Data_Process (s_Fcu_AdasDomain_SignalData_t *ptr_AdasDomainData);
extern FUNC(void, RTE_CODE) Fcu_Chassis_Data_Process (s_Fcu_ChassisDomain_SignalData_t *ptr_ChassisDomainData);
extern FUNC(void, RTE_CODE) Fcu_Body_Data_Process (s_Fcu_BodyDomain_SignalData_t *ptr_BodyDomainData);
extern FUNC(void, RTE_CODE) Fcu_Powertrain_Data_Process (s_Fcu_PowertrainDomain_SignalData_t *ptr_PowertrainData);
extern FUNC(void, RTE_CODE) Fcu_Aeb_Data_Process(s_Fcu_Aeb_SignalData_t *ptr_Aeb_Data);
extern FUNC(void, RTE_CODE) Fcu_Lcf_Data_Process(s_Fcu_Lcf_SignalData_t *ptr_Lcf_Data);
extern FUNC(void, RTE_CODE) Fcu_Acc_Data_Process(s_Fcu_Acc_SignalData_t *ptr_Acc_Data);
extern FUNC(void, RTE_CODE) Fcu_Hla_Data_Process(s_Fcu_Hla_SignalData_t *ptr_Hla_Data);
extern FUNC(void, RTE_CODE) Fcu_Interaction_Process (s_Fcu_Rte_Output_SignalData_t * const ptr_Fcu_Rte_Output_Signal);

#endif /* __FCU_VDY_H_ */





