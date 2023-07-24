/*
 * Sdc_Misc.h
 *
 *  Created on: May 21, 2023
 *      Author: uif69946
 */

#ifndef _SDC_MISC_H_
#define _SDC_MISC_H_

/*==================[inclusions]============================================*/
#include "Std_Types.h" /* AUTOSAR standard types */
#include "Sdc_Core_Type.h"
#include "Sdc_Cfg.h"

/*==================[type definitions]======================================*/


/*==================[function declaration]============================================*/
/*==================[.text]==============================*/
#define SDC_START_SEC_CODE
#include "Sdc_MemMap.h"
#include "Sdc_Core_Type.h"

typedef struct 
{
  uint8 head;
  uint8 tail;
  uint8 counter;
  s_Sdc_MsgSendHandleDataInfo_Event_st Sdc_MsgSendHandleDataInfo_Event[SDC_SENDHANDLER_EVENTMSG_TABLESIZE];
} s_SdcSendEventMsgPoolType_st;


boolean Sdc_Misc_EventSendMsg_poolIsFull(s_SdcSendEventMsgPoolType_st *pool);
boolean Sdc_Misc_EventSendMsg_poolIsEmpty(s_SdcSendEventMsgPoolType_st *pool);
uint8 Sdc_Misc_EventSendMsg_poolPush(s_SdcSendEventMsgPoolType_st *pool, const s_Sdc_MsgSendHandleDataInfo_Event_st *eventData);
void Sdc_Misc_EventSendMsg_poolPop(s_SdcSendEventMsgPoolType_st *pool, s_Sdc_MsgSendHandleDataInfo_Event_st *eventData);

#define SDC_STOP_SEC_CODE
#include "Sdc_MemMap.h"
#endif /* _SDC_MISC_H_ */
