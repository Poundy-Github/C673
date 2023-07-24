/*
 * Sdc.h
 *
 *  Created on: Feb 26, 2022
 *      Author: uie77979
 */

#ifndef _SDC_SDC_H_
#define _SDC_SDC_H_

/*==================[inclusions]============================================*/
#include "Std_Types.h" /* AUTOSAR standard types */
#include "Sdc_Type.h"
#include "Rte_Type.h"
#include "CSC_Platform_Common.h"

/*==================[type definitions]=======================================*/



/*==================[external function declarations definitions]=======================================*/


/*==================[internal function declarations]========================*/
/*==================[.text]==============================*/
#define SDC_START_SEC_CODE
#include "Sdc_MemMap.h"



#define SDC_STOP_SEC_CODE
#include "Sdc_MemMap.h"

#endif /* _SDC_SDC_H_ */
