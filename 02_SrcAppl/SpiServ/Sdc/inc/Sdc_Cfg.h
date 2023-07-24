/*
 * Sdc_Cfg.h
 *
 *  Created on: May 6, 2023
 *      Author: uif69946
 */

#ifndef _SDC_CFG_H_
#define _SDC_CFG_H_

/*==================[inclusions]============================================*/
#include "Std_Types.h" /* AUTOSAR standard types */
// #include "Sdc_Core_Type.h"

/*==================[macros]=================================================*/
#define SDC_DEBUG_ENABLE                                                STD_ON

#define SDC_DIAG_INJECTION_ENABLED                                      STD_ON


#define SDC_PAYLOAD_MAX_LENGTH                                          (4096u) /*TODO : the length use for limit the SPI message payload,which include header and data*/
#define SDC_PROTOCOL_TYPE_SPI                                           (0x00535049UL)
#define SDC_PROTOCOL_TYPE                                               SDC_PROTOCOL_TYPE_SPI   

#define SDC_HANDSHAKE_SYNC              0x47
#define SDC_HANDSHAKE_ACK               0x74

#define SDC_QAMONITOR_TXSEED_CYCLE                                      1000u   /*unit is ms*/
#define SDC_QAMONITOR_RXKEY_TIMEWINDOW_THRESHOLD                        200u    /*unit is ms,Notes : When setting to 100,someties it occurred timeout*/
#define SDC_QAMONITOR_CONTINUOUSKEYERROR_COUNTER_THRESHOLD              16u
#define SDC_QAMONITOR_CONTINUOUSTIMEOUTERROR_COUNTER_THRESHOLD          16u     
#define SDC_QAMONITOR_SEED_KEY_NUMBER                                   8u

#define SDC_MAIN_FUNCTION_PERIOD_TIME                                   5u
#define SDC_TX_MAIN_FUNCTION_PERIOD_TIME                                10u
#define SDC_RX_MAIN_FUNCTION_PERIOD_TIME                                10u

//Sdc_SpiReceiveHandlerTable
#define SDC_SPIRECEIVEHANDLERTABLE_SIZE                             11  /*receive msg number*/
#define SDC_SOC_REPLY_SUBFUNC_SIZE                                  2
#define SDC_SENDHANDLER_CYCLEMSG_SIZE                               4   /*cycle msg number*/
#define SDC_SENDHANDLER_EVENTMSG_TABLESIZE                          7   /*event msg pool number*/
#define SDC_SENDHANDLER_EVENTMSG_MAXSIZE                            100 /*event msg pool buffer length*/
/*==================[type definitions]======================================*/

/*==================[internal constants]====================================*/


/*==================[function declaration]============================================*/

#endif /* _SDC_CFG_H_ */
