/*
 * Sdc_SendHandler.h
 *
 *  Created on: May 28, 2023
 *      Author: uif69946
 */

#ifndef _SDC_SENDHANDLER_H_
#define _SDC_SENDHANDLER_H_

/*==================[inclusions]============================================*/
#include "Std_Types.h" /* AUTOSAR standard types */

/*==================[type definitions]======================================*/


/*==================[function declaration]============================================*/
/*==================[.text]==============================*/
#define SDC_START_SEC_CODE
#include "Sdc_MemMap.h"

void Sdc_SendHandler_InitFunction(void);
void Sdc_SendHandler_MainFunction(void);

void Sdc_SendHandler_SendEventMsg(const s_Sdc_MsgSendHandleDataInfo_Event_st Sdc_eventMsgInfo);


#define SDC_STOP_SEC_CODE
#include "Sdc_MemMap.h"
#endif /* _SDC_SENDHANDLER_H_ */
