/**
 * \file Med_Rmt.h
 *
 * \brief
 *
 * \version
 * --------------------------------------------------------------------------------------------
 * Version	| 		Date		|		Author			| 	Comments
 * V0.0.1		2022.10.26			Chunlin Wu			 Init version            
 *
 * \copyright  2021 - 2022 Conti Smart Core
 * 
 */
#ifndef MED_RMT_H_
#define MED_RMT_H_

/*==================[inclusions]============================================*/
#include "Med_Type.h"

/*==================[macros definitions]====================================*/


/*==================[type definitions]=======================================*/

typedef struct
{
	/**
	 * \brief  the index number of the DTC found in the med_DTC_Mapping_table is recorded.
	 * */
	uint8 Event_Index;
	/**
	 * \brief   send the DTC_Status.
	 * */
	uint8 Send_Status;
}s_Med_Send_CAN_t;
/*==================[external constants declarations]========================*/

/*==================[external data declarations]=============================*/

/*==================[external function declarations]=========================*/
void Med_Rmt_MainFunction(void);

#endif /* MED_RMT_H_ */
