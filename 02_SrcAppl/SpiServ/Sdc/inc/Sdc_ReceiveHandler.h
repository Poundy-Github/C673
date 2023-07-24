/*
 * Sdc_ReceiveHandler.h
 *
 *  Created on: April 12, 2023
 *      Author: uif69946
 */

#ifndef _SDC_RECEIVEHANDLER_H_
#define _SDC_RECEIVEHANDLER_H_

/*==================[inclusions]============================================*/
#include "Std_Types.h" /* AUTOSAR standard types */

/*==================[type definitions]======================================*/


/*==================[function declaration]============================================*/
/*==================[.text]==============================*/
#define SDC_START_SEC_CODE
#include "Sdc_MemMap.h"

void Sdc_ReceiveHandler_InitFunction(void);
void Sdc_ReceiveHandler_MainFunction(void);
uint8 Sdc_ReceiveHandler_SocSysInfo(const uint8 *Data, uint16 Length);
uint8 Sdc_ReceiveHandler_Handshake(const uint8 *Data, uint16 Length);
uint8 Sdc_ReceiveHandler_SocReplyInfo(const uint8 *Data, uint16 Length);
uint8 Sdc_ReceiveHandler_QaAnswer(const uint8 *Data, uint16 Length);
uint8 Sdc_ReceiveHandler_CemOut(const uint8 *Data, uint16 Length);
uint8 Sdc_ReceiveHandler_Perception(const uint8 *Data, uint16 Length);
uint8 Sdc_ReceiveHandler_DriveModeChangeRequest(const uint8 *Data, uint16 Length);
uint8 Sdc_ReceiveHandler_DriveModeChangeResponse(const uint8 *Data, uint16 Length);
uint8 Sdc_Diag_ReceiveHandler_ID0902(const uint8* Data, uint16 Length);
uint8 Sdc_Diag_ReceiveHandler_ID0903(const uint8* Data, uint16 Length);

#define SDC_STOP_SEC_CODE
#include "Sdc_MemMap.h"
#endif /* _SDC_RECEIVEHANDLER_H_ */
