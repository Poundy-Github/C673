/*
 * Sdc_Fusion.h
 *
 *  Created on: May 6, 2023
 *      Author: uif69946
 */

#ifndef _SDC_FUSION_H_
#define _SDC_FUSION_H_

/*==================[inclusions]============================================*/
#include "Std_Types.h" /* AUTOSAR standard types */

/*==================[type definitions]======================================*/


/*==================[function declaration]============================================*/
/*==================[.text]==============================*/
#define SDC_START_SEC_CODE
#include "Sdc_MemMap.h"

FUNC(void, RTE_CODE) Sdc_Fusion_InitFunction(void);
FUNC(void, RTE_CODE) Sdc_Fusion_MainFunction(void);
FUNC(void, RTE_CODE) Sdc_Fusion_RcvCemDataFromJ3(const uint8 *data, uint16 length);

#define SDC_STOP_SEC_CODE
#include "Sdc_MemMap.h"

#endif /* _SDC_FUSION_H_ */
