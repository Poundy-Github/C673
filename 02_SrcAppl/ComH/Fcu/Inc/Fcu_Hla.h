/**
 * \file Fcu_Hla.h
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
#ifndef __FCU_HLA_H_
#define __FCU_HLA_H_

/*==================[inclusions]============================================*/
#include "Std_Types.h" /* AUTOSAR standard types */
#include "Fcu_Type.h"
/*==================[type definitions]=======================================*/
#define  HLA_PI  (3.141592653589793f)

#define  HLA_ESPVEHSPD_FACTOR       (0.98f)

#define  HLA_ESPVEHSPD_OFFSET        (2.0f)

typedef struct 
{
    sint64 s64_HlaWiperTime;
	sint64 s64_HlaFogTime;
	uint8  u8_HlaWiperStage;
	uint8 u8_HlaFogFlag;
	uint8 u8_HlaYawRateFlag;
    uint8 u8_HlaEspLatAccelFlag;
	uint8 u8_HlaBcmHiBeamStsFlag;
	uint8 u8_HlaVehicleObjFlag;
}s_Fcu_HlaInhibitCond_t;


/*==================[external constants declarations]========================*/


/*==================[external data declarations]=============================*/

/*==================[external function declarations]=========================*/
extern FUNC(void, RTE_CODE) Fcu_Hla_InitFunction (void);
extern FUNC(void, RTE_CODE) Fcu_Hla_MainFunction(const s_Fcu_Rte_Input_SignalData_t * const ptr_Fcu_Rte_input_Signal,s_Fcu_Rte_Output_SignalData_t * const ptr_Fcu_Rte_Output_Signal);

#endif /* __FCU_HLA_H_ */