/*
 * Sdc_Core.h
 *
 *  Created on: May 6, 2023
 *      Author: uif69946
 */

#ifndef _SDC_CORE_H_
#define _SDC_CORE_H_

/*==================[inclusions]============================================*/
#include "Sdc_Core_Type.h"
#include "Sdc_Cfg.h"
#include "Sdc_Diag.h"


/*==================[type definitions]======================================*/


/*==================[function declaration]============================================*/
/*==================[.text]==============================*/
#define SDC_START_SEC_CODE
#include "Sdc_MemMap.h"

extern uint8 Sdc_SendHandler_TimeSyncMsg(const void *data, uint16 length);





extern void Sdc_Core_InitFunction(void);
extern void Sdc_Core_MainFunction(void);

e_Sdc_HandShakeState_t Sdc_Core_Handshake_GetStatus(void);
uint8 Sdc_Core_Handshake_Request(uint8 sync);
void Sdc_Core_QaMonitorHandler_HandlerKey(uint8 Key);





#define SDC_STOP_SEC_CODE
#include "Sdc_MemMap.h"

#endif /* _SDC_CORE_H_ */
