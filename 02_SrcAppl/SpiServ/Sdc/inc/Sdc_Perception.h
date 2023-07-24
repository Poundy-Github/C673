/*
 * Sdc_Perception.h
 *
 *  Created on: May 6, 2023
 *      Author: uif69946
 */

#ifndef _SDC_PERCEPTION_H_
#define _SDC_PERCEPTION_H_

/*==================[inclusions]============================================*/
#include "Std_Types.h" /* AUTOSAR standard types */

/*==================[type definitions]======================================*/

/*==================[function declaration]============================================*/
/*==================[.text]==============================*/
#define SDC_START_SEC_CODE
#include "Sdc_MemMap.h"

FUNC(void, RTE_CODE) Sdc_Perception_InitFunction(void);
FUNC(void, RTE_CODE) Sdc_Perception_MainFunction(void);
FUNC(void, RTE_CODE) Sdc_Perception_RcvPerceptionDataFromJ3(const uint8 *data, uint16 length);
FUNC(void, RTE_CODE) Sdc_Perception_DataCovert_LaneMarkerType(uint8 index, uint8 *type);
FUNC(void, RTE_CODE) Sdc_Perception_DataCovert_LaneDistanceFus(uint8 index, float32 *dist);

extern FUNC(Std_ReturnType, RTE_CODE) Sdc_Perception_J3_PerceptionData_Read(void* perceptionData, uint16 length);	//called by Fcu_Hla.c
extern FUNC(Std_ReturnType, RTE_CODE) Sdc_Perception_Len_to_Left_Lane_Read(sint16 *wigth);	    //called by Fcu_Lcf.c
extern FUNC(Std_ReturnType, RTE_CODE) Sdc_Perception_Len_to_Right_Lane_Read(sint16 *wigth);     //called by Fcu_Lcf.c
extern FUNC(Std_ReturnType, RTE_CODE) Sdc_Perception_HostLane_Left_flag_Read(uint16 *flag);     //called by Fcu_Lcf.c
extern FUNC(Std_ReturnType, RTE_CODE) Sdc_Perception_HostLane_Right_flag_Read(uint16 *flag);    //called by Fcu_Lcf.c

#define SDC_STOP_SEC_CODE
#include "Sdc_MemMap.h"
#endif /* _SDC_PERCEPTION_H_ */
