/*
 * Sdc_Lcfg.h
 *
 *  Created on: May 19, 2023
 *      Author: uif69946
 */

#ifndef _SDC_LCFG_H_
#define _SDC_LCFG_H_

/*==================[inclusions]============================================*/
#include "Std_Types.h" /* AUTOSAR standard types */
#include "Sdc_Core_Type.h"

/*==================[internal constants]====================================*/
extern const s_Sdc_HandlerTable_t Sdc_SpiReceiveHandlerTable[SDC_SPIRECEIVEHANDLERTABLE_SIZE];
extern const s_Sdc_MsgSendHandleDataInfo_Cycle_st Sdc_MsgSendHandleTable_Cycle[SDC_SENDHANDLER_CYCLEMSG_SIZE];

/*==================[type definitions]======================================*/


/*==================[function declaration]============================================*/

#endif /* _SDC_LCFG_H_ */
