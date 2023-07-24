/**
 * \file Fcu_Tsa.h
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
#ifndef __FCU_TSA_H_
#define __FCU_TSA_H_

/*==================[inclusions]============================================*/
#include "Std_Types.h" /* AUTOSAR standard types */
#include "Fcu_Type.h"
/*==================[type definitions]=======================================*/



/*==================[external constants declarations]========================*/


/*==================[external data declarations]=============================*/

/*==================[external function declarations]=========================*/
extern FUNC(void, RTE_CODE) Fcu_Tsa_InitFunction (void);
extern FUNC(void, RTE_CODE) Fcu_Tsa_MainFunction (void);

#endif /* __FCU_TSA_H_ */