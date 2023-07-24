/**
 * \file
 *
 * \brief AUTOSAR Xcp
 *
 * This file contains the implementation of the AUTOSAR
 * module Xcp.
 *
 * \version 2.12.2
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2021 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

/* 
 * MISRA-C:2012 Deviation List
 *
 * MISRAC2012-1) Deviated Rule: 11.3 (required)
 * A cast shall not be performed between a pointer to object type and a pointer to a different object type.
 *
 * Reason:
 * The cast is required and unavoidable since there is no way of knowing what the configured memory area points to.
 * This is also used for converting the uint8 pointers in the Xcp_OdtAddressTableRAM array to usize pointers in order
 * to be compatible with the OdtEntry field of the Xcp_OdtType structure.
 *
 * MISRAC2012-2) Deviated Rule: 11.6 (required)
 * A cast shall not be performed between pointer to void and an arithmetic type.
 *
 * Reason:
 * According to this rule, casting a pointer to void to an integer arithmetic type is not considered safe because the
 * the resulting value can be outside the allowed range for the type. However, the cast of the void pointer is made to
 * type usize which is guaranteed to hold a pointer.
 *
 * MISRAC2012-3) Deviated Rule: 11.4 (advisory)
 * A conversion should not be performed between a pointer to object and an integer type.
 *
 * Reason:
 * Required in order to determine if the pointer parameter of Xcp_GetOdtEntryData is in the address space of the Xcp_OdtAddressTableRAM
 */
/*==================[inclusions]============================================*/

#include <Std_Types.h>         /* AUTOSAR standard types */
#include <Xcp.h>               /* Module public API */
#if ( (XCP_DEFAULT_XCP_MODULE_STATE == STD_ON) || (XCP_ENABLE_XCP_CONTROL_API == STD_ON) )
#include <Xcp_Int.h>           /* Module internal interface */

#if (XCP_ON_CDD_ENABLED == STD_ON)
#endif



/*==================[macros]================================================*/


/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[internal constants]====================================*/



#define XCP_START_SEC_CONST_UNSPECIFIED
#include <Xcp_MemMap.h>

/** \brief List of Xcp Tx PDUs ordered by connection and by Xcp internal Id. */
STATIC CONST(PduIdType, XCP_CONST) Xcp_TxPduIdCfgList[XCP_NO_OF_TX_PDU_IDS] =
{
  /* Tx Pdu configuration for the XcpConnectionCfg_0 connection */
  0U,
};

#define XCP_STOP_SEC_CONST_UNSPECIFIED
#include <Xcp_MemMap.h>

/*==================[external constants]====================================*/


#define XCP_START_SEC_CONST_UNSPECIFIED
#include <Xcp_MemMap.h>

/** \brief Configuration placeholder for Xcp_Init() call. */
CONST( Xcp_ConfigType, XCP_CONST ) XcpConfig_0 = { 0U };


/*----------------------------TxPduInfo--------------------------------------*/

/** \brief Tx Pdu Ids configured by the transport layer.
 **
 ** This Ids are used store information regarding:
 ** * mapping PDU toward connection
 ** * destination PDU id into transport layer configuration
 ** * start position of the PDU data inside the Tx PDU buffer area
 ** * supported Xcp communication transfer object types. */
CONST(Xcp_TxLPduIdConfType, XCP_CONST )  Xcp_TxLPduIdConf[XCP_NO_OF_TX_PDU_IDS] =
{
  { /* Mapping information for XcpTxPdu_XcpPdu_Tx Pdu. */
    1538U,  /* CAN/CANFD ID of the package */
    0U,  /* LPdu data start position into Tx buffer data */
    14U,  /* CanIf destination PDU id */
    0U,  /* associated internal buffer Id */
    0U,  /* Xcp connection Id(XcpTxPduConnectionInfo_0) */
    XCP_SUPPORT_FOR_RESERR_CTO_PDU, /* Properties and supported types for this PDU */
  },
};

/*----------------------------RxPduInfo--------------------------------------*/

/** \brief Rx Pdu Ids configured by the transport layer.
 **
 ** This Ids are used store information regarding:
 ** * mapping PDU toward connection
 ** * start position of the PDU data inside the Rx PDU buffer area
 ** * supported Xcp communication transfer object types. */
CONST(Xcp_RxLPduIdConfType, XCP_CONST )  Xcp_RxLPduIdConf[XCP_NO_OF_RX_PDU_IDS] =
{
  { /* Mapping information for XcpRxPdu_XcpPdu_Rx Pdu. */
    1536U,  /* CAN ID of the package */
    0U,  /* LPdu data start position into Rx buffer data */
    0U,  /* associated internal buffer Id */
    0U,  /* Xcp connection Id(XcpConnectionCfg_0) */
    XCP_SUPPORT_FOR_CMD_CTO_PDU, /* Properties and supported types for this PDU */
  },
};

/*----------------------------XcpConnectionCfg--------------------------------------*/

/** \brief Connection configuration info */
CONST(Xcp_ConnectionCfgType, XCP_CONST) Xcp_ConnectionCfg[XCP_NO_OF_CONNECTIONS] =
{
  /* configuration information for XcpConnectionCfg_0 connection(Xcp over CAN). */
  {
    &Xcp_TxPduIdCfgList[0U], /* start position for the mapped Tx Pdu list */
    &CanIf_Transmit, /* pointer to transmit function */
    8U, /* PDU maximum length */
    0U, /* PDU header size */
    1U, /* number of mapped Tx PDUs towards connection */
    1U, /* number of mapped Rx PDUs towards connection */
    0U, /* Xcp PDU channel, used to receive all CMD's but GET_SLAVE_ID. */
    0U, /* Xcp PDU channel, used to receive the broadcasted GET_SLAVE_ID CMD. */
    XCP_IGNORED_CNT_ID,  
    0U, /* connection flags */
    XCP_CONNECTION_OVER_CAN, /* connection type */
    8U, /* connection specific MAX_CTO */
    8U, /* connection specific MAX_DTO */
/* XcpPgmSupported = 'true' */
/* XcpDaqSupported = 'true' */
  },
};



 





#define XCP_STOP_SEC_CONST_UNSPECIFIED
#include <Xcp_MemMap.h>

#define XCP_START_SEC_CONST_8
#include <Xcp_MemMap.h>

#if (XCP_ON_ETHERNET_ENABLED == STD_ON)

/** \brief Array that holds information about which connections are on IPv6 */
CONST(uint8, XCP_CONST) Xcp_Connections_IPv6[XCP_CONNECTION_FLAG_SIZE] =
{
  0U
};

#endif

#define XCP_STOP_SEC_CONST_8
#include <Xcp_MemMap.h>

#define XCP_START_SEC_CONST_16
#include <Xcp_MemMap.h>


#define XCP_STOP_SEC_CONST_16
#include <Xcp_MemMap.h>

/*==================[internal data]=========================================*/


/*-------------[Xcp BSW distribution internal data]-------------------------*/



/*==================[external data]=========================================*/
#define XCP_START_SEC_VAR_UNSPECIFIED
#include <Xcp_MemMap.h>

#define XCP_STOP_SEC_VAR_UNSPECIFIED
#include <Xcp_MemMap.h>

#define XCP_START_SEC_VAR_CONTROL_API_8
#include <Xcp_MemMap.h>

VAR(uint8, XCP_VAR) Xcp_ControlStateOfXcpModule =          XCP_STATE_ACTIVE;

#define XCP_STOP_SEC_VAR_CONTROL_API_8
#include <Xcp_MemMap.h>
/*==================[external function definitions]=========================*/

/*-------------[Xcp BSW distribution external function definitions]---------------*/



/*==================[external function definitions]=========================*/




#endif /*( (XCP_DEFAULT_XCP_MODULE_STATE == STD_ON) || (XCP_ENABLE_XCP_CONTROL_API == STD_ON) )*/
/*==================[end of file]===========================================*/
