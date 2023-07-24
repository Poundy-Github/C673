/**
 * \file
 *
 * \brief AUTOSAR CanTp
 *
 * This file contains the implementation of the AUTOSAR
 * module CanTp.
 *
 * \version 6.8.45
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2021 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

#ifndef CANTP_INTERNALCFG_H
#define CANTP_INTERNALCFG_H

/*==================[includes]===============================================*/








    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    




 

 
 
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 





#include <TSAutosar.h>              /* EB specific standard types */
#include <CanTp_InternalLib.h>      /* internal macros and variables */
#include <CanTp_Cfg.h>              /* CanTp configuration */

/*==================[macros]=================================================*/

#if (defined CANTP_PADDING_BYTE) /* to prevent double declaration */
#error CANTP_PADDING_BYTE is already defined
#endif /* if (defined CANTP_PADDING_BYTE) */

/** \brief defines padding value for unused bytes for CAN 2.0 frames and CAN FD frames if no certain FD Padding byte is configured. */
#define CANTP_PADDING_BYTE                0U

#if (defined CANTP_PADDING_BYTE_CANFD) /* to prevent double declaration */
#error CANTP_PADDING_BYTE_CANFD is already defined
#endif /* if (defined CANTP_PADDING_BYTE_CANFD) */

       /** \brief defines padding value for unused bytes for CAN FD frames */
#define CANTP_PADDING_BYTE_CANFD          0U


#if (defined CANTP_GET_ADDR_FORMAT) /* to prevent double declaration */
#error CANTP_GET_ADDR_FORMAT is already defined
#endif /* if (defined CANTP_GET_ADDR_FORMAT) */

/** \def CANTP_GET_ADDR_FORMAT(PduPtr)
 **
 ** \brief Macro to read the addressing format of N-PDUs
 **
 ** This macro is used to read the addressing format of the N-PDU given
 ** as a pointer as parameter.
 **
 ** \param[in] PduPtr Pointer to element of type CanTp_RxNPduTableType,
 **            CanTp_RxNSduConfigType or CanTp_TxNSduConfigType
 **
 ** \return CanTp addressing format
 */
#define CANTP_GET_ADDR_FORMAT(PduPtr)         ((PduPtr)->AddressingFormat)


#if (defined CANTP_GET_CH_MODE) /* to prevent double declaration */
#error CANTP_GET_CH_MODE is already defined
#endif /* if (defined CANTP_GET_CH_MODE) */

/** \def CANTP_GET_CH_MODE(PduPtr)
 **
 ** \brief Macro to read the channel mode
 **
 ** This macro is used to read the mode of channel corresponding to N-PDU given
 ** as a pointer as parameter.
 **
 ** \param[in] PduPtr Pointer to element of type CanTp_RxNPduTableType,
 **            CanTp_RxNSduConfigType or CanTp_TxNSduConfigType
 **
 ** \return CanTp Channel mode
 */
#define CANTP_GET_CH_MODE(PduPtr)             ((PduPtr)->ChannelMode)


#if (defined CANTP_GET_RX_PDU_BLOCK_SIZE) /* to prevent double declaration */
#error CANTP_GET_RX_PDU_BLOCK_SIZE is already defined
#endif /* if (defined CANTP_GET_RX_PDU_BLOCK_SIZE) */

/** \def CANTP_GET_RX_PDU_BLOCK_SIZE(NSduId)
 **
 ** \brief Macro to read the block size format of Rx N-PDUs
 **
 ** This macro is used to read the block size (BS)
 **
 ** \param[in] NSduId N-SDU ID of the Rx PDU
 **
 ** \return Block size of the Rx N-SDU
 */
#define CANTP_GET_RX_PDU_BLOCK_SIZE(NSduId)   (CANTP_CFG_GET_RXNSDU_CONFIG(NSduId).BS)


#if (defined CANTP_SET_RX_PDU_BLOCK_SIZE) /* to prevent double declaration */
#error CANTP_SET_RX_PDU_BLOCK_SIZE is already defined
#endif /* if (defined CANTP_SET_RX_PDU_BLOCK_SIZE) */

/** \brief Macro to write the block size format of Rx N-PDUs
 **
 ** This macro is used to write the block size (BS) of the Rx N-PDU given
 ** as N-SduId. This macro is only active if the API CanTp_ChangeParameter() is
 ** enabled and therefore it is allowed to change the block size during runtime.
 ** Otherwise the block size is a read-only parameter.
 **
 ** \param[in] NSduId N-SDU ID of the Rx PDU
 ** \param[in] value new value for the block size
 **
 ** \return Block size of the Rx N-SDU
 */


#if (defined CANTP_GET_RX_PDU_N_AR) /* to prevent double declaration */
#error CANTP_GET_RX_PDU_N_AR is already defined
#endif /* if (defined CANTP_GET_RX_PDU_N_AR) */

/** \brief Get N_Ar for a Rx PDU
 **
 ** This macro is used to read the N_Ar TP parameter for the given Rx N-SDU.
 **
 ** \param[in] PduPtr Pointer to element of type CanTp_RxNSduConfigType
 */
#define CANTP_GET_RX_PDU_N_AR(PduPtr)         ((PduPtr)->N_Ar)


#if (defined CANTP_GET_RX_PDU_N_BR) /* to prevent double declaration */
#error CANTP_GET_RX_PDU_N_BR is already defined
#endif /* if (defined CANTP_GET_RX_PDU_N_BR) */

/** \brief Get N_Br for a Rx PDU
 **
 ** This macro is used to read the N_Br TP parameter for the given Rx N-SDU.
 **
 ** \param[in] PduPtr Pointer to element of type CanTp_RxNSduConfigType
 */
#define CANTP_GET_RX_PDU_N_BR(PduPtr)         ((PduPtr)->N_Br)


#if (defined CANTP_GET_RX_PDU_N_CR) /* to prevent double declaration */
#error CANTP_GET_RX_PDU_N_CR is already defined
#endif /* if (defined CANTP_GET_RX_PDU_N_CR) */

/** \brief Get N_Cr for a Rx PDU
 **
 ** This macro is used to read the N_Cr TP parameter for the given Rx N-SDU.
 **
 ** \param[in] PduPtr Pointer to element of type CanTp_RxNSduConfigType
 */
#define CANTP_GET_RX_PDU_N_CR(PduPtr)         ((PduPtr)->N_Cr)


#if (defined CANTP_GET_RX_PDU_WFT_MAX) /* to prevent double declaration */
#error CANTP_GET_RX_PDU_WFT_MAX is already defined
#endif /* if (defined CANTP_GET_RX_PDU_WFT_MAX) */

/** \brief Get maximum number of wait frames for a Rx PDU
 **
 ** This macro is used to read the WftMax parameter for the given Rx N-SDU.
 **
 ** \param[in] PduPtr Pointer to element of type CanTp_RxNSduConfigType
 */
#define CANTP_GET_RX_PDU_WFT_MAX(PduPtr)      ((PduPtr)->WftMax)


#if (defined CANTP_GET_RX_PDU_ST_MIN) /* to prevent double declaration */
#error CANTP_GET_RX_PDU_ST_MIN is already defined
#endif /* if (defined CANTP_GET_RX_PDU_ST_MIN) */

/** \brief Get minimum separation time (STmin) for a Rx PDU
 **
 ** This macro is used to read the STmin parameter for the given Rx N-SDU.
 **
 ** \param[in] NSduId N-SDU ID of the Rx PDU
 */
#define CANTP_GET_RX_PDU_ST_MIN(NSduId)       CANTP_CFG_GET_RXNSDU_CONFIG((NSduId)).STmin;



#if (defined CANTP_GET_TX_PDU_N_AS) /* to prevent double declaration */
#error CANTP_GET_TX_PDU_N_AS is already defined
#endif /* if (defined CANTP_GET_TX_PDU_N_AS) */

/** \brief Get N_As for a Tx PDU
 **
 ** This macro is used to read the N_As TP parameter for the given Tx N-SDU.
 **
 ** \param[in] PduPtr Pointer to element of type CanTp_TxNSduConfigType
 */
#define CANTP_GET_TX_PDU_N_AS(PduPtr)         ((PduPtr)->N_As)


#if (defined CANTP_GET_TX_PDU_N_BS) /* to prevent double declaration */
#error CANTP_GET_TX_PDU_N_BS is already defined
#endif /* if (defined CANTP_GET_TX_PDU_N_BS) */

/** \def CANTP_GET_TX_PDU_N_BS(PduPtr)
 **
 ** \brief Get N_Bs for a Tx PDU
 **
 ** This macro is used to read the N_Bs TP parameter for the given Tx N-SDU.
 **
 ** \param[in] PduPtr Pointer to element of type CanTp_TxNSduConfigType
 */
#define CANTP_GET_TX_PDU_N_BS(PduPtr)         ((PduPtr)->N_Bs)


#if (defined CANTP_GET_TX_PDU_N_CS) /* to prevent double declaration */
#error CANTP_GET_TX_PDU_N_CS is already defined
#endif /* if (defined CANTP_GET_TX_PDU_N_CS) */

/** \def CANTP_GET_TX_PDU_N_CS(PduPtr)
 **
 ** \brief Get N_Cs for a Tx PDU
 **
 ** This macro is used to read the N_Cs TP parameter for the given Tx N-SDU.
 **
 ** \param[in] PduPtr Pointer to element of type CanTp_TxNSduConfigType
 */
#define CANTP_GET_TX_PDU_N_CS(PduPtr)         ((PduPtr)->N_Cs)

/*==================[type definitions]=======================================*/

/** \brief Type for CanTp internal variables that shall be initialized during
 **        startup. */
typedef struct
{
  uint8 State;    /**< CanTp state (CANTP_ON/CANTP_OFF) */
} CanTp_InitVariableType;

/*==================[external constants]=====================================*/

/*==================[external data]==========================================*/
#define CANTP_START_SEC_VAR_CLEARED_8
#include <CanTp_MemMap.h>



#if(CANTP_DYNAMIC_NSA_ENABLED == STD_ON)
/** \brief If dynamic setting of N_SA values is enabled, the N_SA values are
 *         stored in following array
 */
extern VAR(uint8, CANTP_VAR) CanTp_NSaValues[CANTP_MAX_RX_NSDUS + CANTP_MAX_FC_PDUS];
#endif

#define CANTP_STOP_SEC_VAR_CLEARED_8
#include <CanTp_MemMap.h>


#define CANTP_START_SEC_VAR_CLEARED_UNSPECIFIED
#include <CanTp_MemMap.h>

/** \brief CanTp channel state(s) */
extern VAR(CanTp_ChannelType, CANTP_VAR) CanTp_Channel[CANTP_MAX_TX_CHANNELS + CANTP_MAX_RX_CHANNELS];

/** \brief PduR buffer availability */
extern VAR(BufReq_ReturnType, CANTP_VAR) RetVal_DataReq;

#define CANTP_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include <CanTp_MemMap.h>


#define CANTP_START_SEC_VAR_INIT_JUMP_TABLE_SHARED_UNSPECIFIED
#include <CanTp_MemMap.h>

/** \brief Internal CanTp variables to be initialized by the C startup code */
extern VAR(CanTp_InitVariableType, CANTP_VAR) CanTp_InitVars;

#define CANTP_STOP_SEC_VAR_INIT_JUMP_TABLE_SHARED_UNSPECIFIED
#include <CanTp_MemMap.h>



/** \brief Internal CanTp Counter for checking if all channels are idle or not (0 means all channels are IDLE) */
#if((CANTP_MAX_TX_CHANNELS + CANTP_MAX_RX_CHANNELS) > 255U)

  #define CANTP_START_SEC_VAR_CLEARED_16
  #include <CanTp_MemMap.h>

  extern VAR(uint16, CANTP_VAR) CanTp_NonIdleChannelCounter;

  #define CANTP_STOP_SEC_VAR_CLEARED_16
  #include <CanTp_MemMap.h>

#else /* (CANTP_MAX_TX_CHANNELS + CANTP_MAX_RX_CHANNELS <= 255U)*/

  #define CANTP_START_SEC_VAR_CLEARED_8
  #include <CanTp_MemMap.h>

  extern VAR(uint8, CANTP_VAR) CanTp_NonIdleChannelCounter;

  #define CANTP_STOP_SEC_VAR_CLEARED_8
  #include <CanTp_MemMap.h>
#endif /* (CANTP_MAX_TX_CHANNELS + CANTP_MAX_RX_CHANNELS > 255U) */

/*==================[external function declarations]=========================*/

/*==================[end of file]============================================*/
#endif /* ifndef CANTP_INTERNALCFG_H */
