/**
 * \file
 *
 * \brief AUTOSAR CanNm
 *
 * This file contains the implementation of the AUTOSAR
 * module CanNm.
 *
 * \version 6.19.8
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2021 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */


/*==================[inclusions]============================================*/
#define CANNM_NO_CFGCLASSMIX_REQUIRED
#ifndef CANNM_NO_PBCFG_REQUIRED
#define CANNM_NO_PBCFG_REQUIRED
#endif

#include <CanNm_Api.h>        /* CanNm API definitions (own interface) */
#include <CanNm_Int.h>        /* CanNm internal dependent information */
#include <SchM_CanNm.h>

/*==================[macros]================================================*/

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[internal data]=========================================*/


/*==================[internal constants]====================================*/

/*==================[external constants]====================================*/
#define CANNM_START_SEC_CONST_UNSPECIFIED
#include <CanNm_MemMap.h>


/* !LINKSTO CANNM299,1 */
CONST(CanNm_ChanConfigType, CANNM_CONST)
  CanNm_ChanConfig[CANNM_NUMBER_OF_CHANNELS] =
{
  /* Configuration of CAN NM channel CanNmChannelConfig_0 with RxPduId 0 : */
  {

    /* !LINKSTO CANNM246,1 */
    800U, /* Nm Timeout Time */
    /* !LINKSTO CANNM247,1 */
    300U, /* Repeat Message Time */
    /* !LINKSTO CANNM248,1 */
    800U, /* Wait Bus Sleep Time */
    /* !LINKSTO CANNM249,1 */
    0U, /* Remote Sleep Indication Time */
    /* !LINKSTO CANNM056_Conf,1 */
    10U, /* Immediate Nm Transmissions count */
    4U, /* Immediate Nm Cycle Time */
    140U, /* Msg Cycle Time */
    60U, /* Msg Timeout Time */
    0U, /* Tx Confirmation PduId */
#if ((CANNM_REPEAT_MSG_IND_ENABLED == STD_ON) &&  \
     (CANNM_NODE_DETECTION_ENABLED == STD_ON))
    0U, /* Rx PduId */
#endif
    0xFF, /* User Data Tx PduId */
#if (CANNM_PN_ERA_CALC_ENABLED == STD_ON)

    0U, /* EraPduId */
    0U, /* EraCalcEnabled */
#endif
    0U, /* Channel Config Flags */
    CANNM_PDU_BYTE_0, /* Nid Position */
    CANNM_PDU_BYTE_1, /* Cbv Position */
    2U,            /* UserData first byte position */
    0U, /* ComMChannelId */
    /* !LINKSTO CANNM068_Conf,1 */
  FALSE, /* CanNmAllNmMessagesKeepAwake */
    FALSE, /* CanNmRepeatMsgIndEnabled */
    FALSE, /* CanNmNodeDetectionEnabled */
    TRUE,  /* CanNmNodeIdEnabled */
},

};

#define CANNM_STOP_SEC_CONST_UNSPECIFIED
#include <CanNm_MemMap.h>

#define CANNM_START_SEC_CONST_8
#include <CanNm_MemMap.h>

CONST(NetworkHandleType, CANNM_CONST)
  CanNm_IndexFromNmChannelHandle[CANNM_INDEXFROMNMCHANNELHANDLE_NUM] =
{
  0U, /* RxPduId of channel "CanNmChannelConfig_0" with ComMChannelHandle 0 */
};

#define CANNM_STOP_SEC_CONST_8
#include <CanNm_MemMap.h>

/*==================[external data]=========================================*/

/*==================[external function definitions]=========================*/

/*==================[internal function definitions]=========================*/

/*==================[end of file]===========================================*/
