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

#ifndef CANTP_CFG_H
#define CANTP_CFG_H

/* CanTp_Cfg.h shall define constant and customizable data for module configuration
   at pre-compile time.
 */
/* !LINKSTO CanTp.ASR40.CANTP001, 1 */
/*==================[includes]===============================================*/








    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    




 

 
 
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 





#include <TSAutosar.h>      /* EB specific standard types */
#include <ComStack_Types.h> /* typedefs for AUTOSAR com stack */

/*==================[macros]=================================================*/

#if (defined CANTP_PBCFGM_SUPPORT_ENABLED) /* to prevent double declaration */
#error CANTP_PBCFGM_SUPPORT_ENABLED is already defined
#endif /* if (defined CANTP_PBCFGM_SUPPORT_ENABLED) */


#if (defined CANTP_ISVALIDCONFIG_MMAP_ENABLED) /* to prevent double declaration */
#error CANTP_ISVALIDCONFIG_MMAP_ENABLED is already defined
#endif /* if (defined CANTP_ISVALIDCONFIG_MMAP_ENABLED) */

/** \brief switch for supporting PbcgfM module */

#define CANTP_PBCFGM_SUPPORT_ENABLED     STD_OFF

/** \brief switch reports that CanTp_IsValidConfig function shall be mapped to memory section CANIF_CODE_CC_BLOCK
*/
#define CANTP_ISVALIDCONFIG_MMAP_ENABLED STD_OFF



#if (defined CANTP_PARALLEL_CHANNELS_ENABLED) /* to prevent double declaration */
#error CANTP_PARALLEL_CHANNELS_ENABLED is already defined
#endif /* if (defined CANTP_PARALLEL_CHANNELS_ENABLED) */

/** \brief switch for supporting parallel channels
*/

#define CANTP_PARALLEL_CHANNELS_ENABLED STD_OFF


#if (defined CANTP_DEV_ERROR_DETECT) /* to prevent double declaration */
#error CANTP_DEV_ERROR_DETECT is already defined
#endif /* if (defined CANTP_DEV_ERROR_DETECT) */

/** \brief Switch for DET usage */

#define CANTP_DEV_ERROR_DETECT            STD_ON

#if (defined CANTP_VERSION_INFO_API) /* to prevent double declaration */
#error CANTP_VERSION_INFO_API is already defined
#endif /* if (defined CANTP_VERSION_INFO_API) */

/** \brief Switch for GetVersionInfo API */
#define CANTP_VERSION_INFO_API            STD_OFF

#if (defined CANTP_RX_CANCELLATION_API) /* to prevent double declaration */
#error CANTP_RX_CANCELLATION_API is already defined
#endif /* if (defined CANTP_RX_CANCELLATION_API) */

/** \brief Defines if receive cancellation API is available. */
#define CANTP_RX_CANCELLATION_API          STD_ON

#if (defined CANTP_TX_CANCELLATION_API) /* to prevent double declaration */
#error CANTP_TX_CANCELLATION_API is already defined
#endif /* if (defined CANTP_TX_CANCELLATION_API) */

/** \brief Defines if transmit cancellation API is available. */
#define CANTP_TX_CANCELLATION_API          STD_ON

/** \brief Handling of N_SA values
 **
 ** The macro CANTP_DYNAMIC_NSA_ENABLED is used to specify if N_SA values are fix values,
 ** which are specified at configuration time (normal Autosar behaviour) or
 ** it is possible to change the N_SA values for each
 ** Pdu at runtime. If enabled, change at runtime is possible.
 */

#if (defined CANTP_DYNAMIC_NSA_ENABLED) /* to prevent double declaration */
#error CANTP_DYNAMIC_NSA_ENABLED is already defined
#endif /* if (defined CANTP_DYNAMIC_NSA_ENABLED) */
#define CANTP_DYNAMIC_NSA_ENABLED   STD_OFF

#if (defined CANTP_DYNAMIC_NSA_API) /* to prevent double declaration */
#error CANTP_DYNAMIC_NSA_API is already defined
#endif /* if (defined CANTP_DYNAMIC_NSA_API) */
#define CANTP_DYNAMIC_NSA_API       STD_OFF


#if (defined CANTP_CHANGE_PARAMETER_REQ_API) /* to prevent double declaration */
#error CANTP_CHANGE_PARAMETER_REQ_API is already defined
#endif /* if (defined CANTP_CHANGE_PARAMETER_REQ_API) */

/** \brief defines if CanTp_ChangeParameter() is enabled */
#define CANTP_CHANGE_PARAMETER_REQ_API    STD_OFF

#if (defined CANTP_CHANGE_TX_PARAMETER_REQ_API) /* to prevent double declaration */
#error CANTP_CHANGE_TX_PARAMETER_REQ_API is already defined
#endif /* if (defined CANTP_CHANGE_TX_PARAMETER_REQ_API) */

/** \brief defines if CanTp_ChangeTxParameter() and CanTp_ResetTxParameter are enabled */
#define CANTP_CHANGE_TX_PARAMETER_REQ_API    STD_OFF


#if (defined CANTP_READ_PARAMETER_REQ_API)
#error CANTP_READ_PARAMETER_REQ_API is already defined
#endif /* #if (defined CANTP_READ_PARAMETER_REQ_API) */

/** \brief defines if CanTp_ReadParameter() is enabled */
#define CANTP_READ_PARAMETER_REQ_API    STD_OFF


#if (defined CANTP_N_BR_WAIT_SUPPORT) /* to prevent double declaration */
#error CANTP_N_BR_WAIT_SUPPORT is already defined
#endif /* if (defined CANTP_N_BR_WAIT_SUPPORT) */

/** \brief defines if N_BR WAIT support is enabled */
#define CANTP_N_BR_WAIT_SUPPORT           STD_OFF

#if (defined CANTP_STALLHANDLING_SUPPORT) /* to prevent double declaration */
#error CANTP_STALLHANDLING_SUPPORT is already defined
#endif /* if (defined CANTP_STALLHANDLING_SUPPORT) */

/** \brief defines if STALLHANDLING support of received meassages is enabled */
#define CANTP_STALLHANDLING_SUPPORT           STD_ON


/* jumptable related macros */

#if (defined CANTP_JUMPTABLE_OFF) /* to prevent double declaration */
#error CANTP_JUMPTABLE_OFF is already defined
#endif /* if (defined CANTP_JUMPTABLE_OFF) */

/** \brief Jumptable support is deactivated */
#define CANTP_JUMPTABLE_OFF             0U

#if (defined CANTP_JUMPTABLE_SERVER) /* to prevent double declaration */
#error CANTP_JUMPTABLE_SERVER is already defined
#endif /* if (defined CANTP_JUMPTABLE_SERVER) */

/** \brief Jumptable support is activated and module acts as server */
#define CANTP_JUMPTABLE_SERVER          1U

#if (defined CANTP_JUMPTABLE_CLIENT) /* to prevent double declaration */
#error CANTP_JUMPTABLE_CLIENT is already defined
#endif /* if (defined CANTP_JUMPTABLE_CLIENT) */

/** \brief Jumptable support is activated and module acts as client */
#define CANTP_JUMPTABLE_CLIENT          2U


#if (defined CANTP_JUMPTABLE_SUPPORT) /* to prevent double declaration */
#error CANTP_JUMPTABLE_SUPPORT is already defined
#endif /* if (defined CANTP_JUMPTABLE_SUPPORT) */

/** \brief General CanTp jumptable support */
#define CANTP_JUMPTABLE_SUPPORT           STD_OFF

#if (defined CANTP_JUMPTABLE_MODE) /* to prevent double declaration */
#error CANTP_JUMPTABLE_MODE is already defined
#endif /* if (defined CANTP_JUMPTABLE_MODE) */

/** \brief CanTp jumptable mode
 **
 ** This macro defines the current jumptable mode (not supported, server,
 ** client).
 */
#define CANTP_JUMPTABLE_MODE              CANTP_JUMPTABLE_OFF


#if (defined CANTP_EXIT_JUMPTABLE_WITH_SCHM) /* to prevent double declaration */
#error CANTP_EXIT_JUMPTABLE_WITH_SCHM is already defined
#endif /* if (defined CANTP_EXIT_JUMPTABLE_WITH_SCHM) */

/** \brief CanTp jumptable support: SchM used as macro
 **
 ** This macro defines, if the SchM functions shall be accessed via function
 ** pointers in the exit jumptable (value STD_ON) or if macros are defined
 ** and used for them (value STD_OFF).
 */
#define CANTP_EXIT_JUMPTABLE_WITH_SCHM    STD_OFF


#if (defined CANTP_PROVIDE_JUMPTABLE) /* to prevent double declaration */
#error CANTP_PROVIDE_JUMPTABLE is already defined
#endif /* if (defined CANTP_PROVIDE_JUMPTABLE) */

/** \brief CanTp jumptable configuration
 **
 ** This macro defines if the current CanTp shall provide the entry jumptable
 ** to the application (value STD_ON) or if the CanTp functions are provided
 ** (value STD_OFF).
 */
#define CANTP_PROVIDE_JUMPTABLE           STD_OFF


#if (defined CANTP_PROVIDE_API_FUNCTIONS) /* to prevent double declaration */
#error CANTP_PROVIDE_API_FUNCTIONS is already defined
#endif /* if (defined CANTP_PROVIDE_API_FUNCTIONS) */

/** \brief Defines if the CanTp provides all of its API functions
 **
 ** This macro defines if the CanTp shall provide all of its API functions. If
 ** jumptable support is on and wrapper macros shall be used, this macro has
 ** the value STD_OFF. Otherwise it is STD_ON.
 */
#define CANTP_PROVIDE_API_FUNCTIONS       STD_ON


#if (defined CANTP_USE_GPT) /* to prevent double declaration */
#error CANTP_USE_GPT is already defined
#endif /* if (defined CANTP_USE_GPT) */

/** \brief defines if general purpose timer is enabled for timeout handling of the channels */
#define CANTP_USE_GPT  STD_OFF

#if (defined CANTP_CANFD_ENABLED) /* to prevent double declaration */
#error CANTP_CANFD_ENABLED is already defined
#endif /* if (defined CANTP_CANFD_ENABLED) */

/** \brief Switch to define if CAN FD support is enabled. */
#define CANTP_CANFD_ENABLED STD_ON

#if (defined CANTP_DYNAMIC_ID_SUPPORT) /* to prevent double declaration */
#error CANTP_DYNAMIC_ID_SUPPORT is already defined
#endif /* if (defined CANTP_DYNAMIC_ID_SUPPORT) */

/** \brief Switch to define if dynamic ID via N-PDU MetaData support is enabled. */
#define CANTP_DYNAMIC_ID_SUPPORT STD_OFF

#if (defined CANTP_GENERIC_CONNECTION_SUPPORT) /* to prevent double declaration */
#error CANTP_GENERIC_CONNECTION_SUPPORT is already defined
#endif /* if (defined CANTP_GENERIC_CONNECTION_SUPPORT) */

/** \brief Switch to define if generic connection using N-SDU MetaData support is enabled. */
#define CANTP_GENERIC_CONNECTION_SUPPORT STD_OFF



#if (defined CANTP_MAX_TX_CHANNELS) /* to prevent double declaration */
#error CANTP_MAX_TX_CHANNELS is already defined
#endif /* if (defined CANTP_MAX_TX_CHANNELS) */

/** \brief Maximum number TX channels supported.
 */
#define CANTP_MAX_TX_CHANNELS 10U

#if (defined CANTP_MAX_RX_CHANNELS) /* to prevent double declaration */
#error CANTP_MAX_RX_CHANNELS is already defined
#endif /* if (defined CANTP_MAX_RX_CHANNELS) */

/** \brief Maximum number RX channels supported.
 */
#define CANTP_MAX_RX_CHANNELS 10U



#if (defined CANTP_MAX_TX_NSDUS) /* to prevent double declaration */
#error CANTP_MAX_TX_NSDUS is already defined
#endif /* if (defined CANTP_MAX_TX_NSDUS) */

/** \brief Maximum number TX N-SDUs supported.
 */
#define CANTP_MAX_TX_NSDUS 10U

#if (defined CANTP_MAX_RX_NSDUS) /* to prevent double declaration */
#error CANTP_MAX_RX_NSDUS is already defined
#endif /* if (defined CANTP_MAX_RX_NSDUS) */

/** \brief Maximum number RX N-SDUs supported.
 */
#define CANTP_MAX_RX_NSDUS 10U

#if (defined CANTP_MAX_FC_PDUS) /* to prevent double declaration */
#error CANTP_MAX_FC_PDUS is already defined
#endif /* if (defined CANTP_MAX_FC_PDUS) */

/** \brief Maximum number flow control PDUs supported.
 */
#define CANTP_MAX_FC_PDUS 10U

/* ----- Pre-processor switch to enable/disable relocateable postbuild config ----- */
#if(CANTP_PBCFGM_SUPPORT_ENABLED == STD_ON)

#if (defined CANTP_RELOCATABLE_CFG_ENABLE) /* to prevent double declaration */
#error CANTP_RELOCATABLE_CFG_ENABLE is already defined
#endif /* if (defined CANTP_RELOCATABLE_CFG_ENABLE) */

#define CANTP_RELOCATABLE_CFG_ENABLE  STD_ON

#else

#if (defined CANTP_RELOCATABLE_CFG_ENABLE) /* to prevent double declaration */
#error CANTP_RELOCATABLE_CFG_ENABLE is already defined
#endif /* if (defined CANTP_RELOCATABLE_CFG_ENABLE) */

#define CANTP_RELOCATABLE_CFG_ENABLE  STD_ON
#endif


#if (defined CANTP_CFG_SIGNATURE) /* to prevent double declaration */
#error CANTP_CFG_SIGNATURE is already defined
#endif /* if (defined CANTP_CFG_SIGNATURE) */

/** \brief Compile time verification value */
#define CANTP_CFG_SIGNATURE 1732989128U

#if (defined CANTP_PUBLIC_INFO_SIGNATURE) /* to prevent double declaration */
#error CANTP_PUBLIC_INFO_SIGNATURE is already defined
#endif /* if (defined CANTP_PUBLIC_INFO_SIGNATURE) */

/** \brief Compile time Published information configuration verification value */
#define CANTP_PUBLIC_INFO_SIGNATURE 1189933925U

/** \brief Enable multicore support*/
#if (defined CANTP_MULTICORE_SUPPORT)
#error CANTP_MULTICORE_SUPPORT already defined
#endif
#define CANTP_MULTICORE_SUPPORT           STD_OFF

/** \brief Enable Channels distribution support*/
#if (defined CANTP_DISTRIBUTED_CHANNEL_SUPPORT)
#error CANTP_DISTRIBUTED_CHANNEL_SUPPORT already defined
#endif
#define CANTP_DISTRIBUTED_CHANNEL_SUPPORT           STD_OFF

/** \brief Number of configured CanTp channels*/
#if (defined CANTP_NUMBER_CONFIGURED_CHANNELS)
#error CANTP_NUMBER_CONFIGURED_CHANNELS already defined
#endif
#define CANTP_NUMBER_CONFIGURED_CHANNELS 2U







/*------------------[Defensive programming]---------------------------------*/

#if (defined CANTP_DEFENSIVE_PROGRAMMING_ENABLED)
#error CANTP_DEFENSIVE_PROGRAMMING_ENABLED is already defined
#endif
/** \brief Defensive programming usage
 **
 ** En- or disables the usage of the defensive programming */
#define CANTP_DEFENSIVE_PROGRAMMING_ENABLED   STD_OFF

#if (defined CANTP_PRECONDITION_ASSERT_ENABLED)
#error CANTP_PRECONDITION_ASSERT_ENABLED is already defined
#endif
/** \brief Precondition assertion usage
 **
 ** En- or disables the usage of precondition assertion checks */
#define CANTP_PRECONDITION_ASSERT_ENABLED     STD_OFF

#if (defined CANTP_POSTCONDITION_ASSERT_ENABLED)
#error CANTP_POSTCONDITION_ASSERT_ENABLED is already defined
#endif
/** \brief Postcondition assertion usage
 **
 ** En- or disables the usage of postcondition assertion checks */
#define CANTP_POSTCONDITION_ASSERT_ENABLED    STD_OFF

#if (defined CANTP_UNREACHABLE_CODE_ASSERT_ENABLED)
#error CANTP_UNREACHABLE_CODE_ASSERT_ENABLED is already defined
#endif
/** \brief Unreachable code assertion usage
 **
 ** En- or disables the usage of unreachable code assertion checks */
#define CANTP_UNREACHABLE_CODE_ASSERT_ENABLED STD_OFF

#if (defined CANTP_INVARIANT_ASSERT_ENABLED)
#error CANTP_INVARIANT_ASSERT_ENABLED is already defined
#endif
/** \brief Invariant assertion usage
 **
 ** En- or disables the usage of invariant assertion checks */
#define CANTP_INVARIANT_ASSERT_ENABLED        STD_OFF

#if (defined CANTP_STATIC_ASSERT_ENABLED)
#error CANTP_STATIC_ASSERT_ENABLED is already defined
#endif
/** \brief Static assertion usage
 **
 ** En- or disables the usage of static assertion checks */
#define CANTP_STATIC_ASSERT_ENABLED           STD_OFF



/*====================[Symbolic Names]=======================================*/

/*==================[type definitions]=======================================*/

/*==================[external constants]=====================================*/

/*==================[external data]==========================================*/

/*==================[internal data]=========================================*/

/*==================[external function declarations]=========================*/

/*==================[end of file]============================================*/
#endif /* ifndef CANTP_CFG_H */

