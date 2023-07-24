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
/* CHECK: NOPARSE */

#ifndef CANTP_SYMBOLICNAMES_PBCFG_H
#define CANTP_SYMBOLICNAMES_PBCFG_H









    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    




 

 
 
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 





/*==================[includes]==============================================*/

/*==================[macros]================================================*/

/* Generate macros for CanTpRxNSdus */

/*------------------------ CanTpRxNSdu_CAN---------------------------------- */


#if (defined CanTpConf_CanTpRxNSdu_CanTpRxNSdu_CAN) /* to prevent double declaration */
#error CanTpConf_CanTpRxNSdu_CanTpRxNSdu_CAN is already defined
#endif /* if (defined CanTpConf_CanTpRxNSdu_CanTpRxNSdu_CAN) */

/** \brief Export symbolic name value for PhysChannel_CanTpRxNSdu_CAN */
#define CanTpConf_CanTpRxNSdu_CanTpRxNSdu_CAN   0U

#if (defined CANTP_PROVIDE_LEGACY_SYMBOLIC_NAMES)

#if (defined CanTp_PhysChannel_CanTpRxNSdu_CAN) /* to prevent double declaration */
#error CanTp_PhysChannel_CanTpRxNSdu_CAN is already defined
#endif /* if (defined CanTp_PhysChannel_CanTpRxNSdu_CAN) */

/** \brief Export symbolic name value with module abbreviation as prefix only
 *         (AUTOSAR 4.0 rev2 <= AUTOSAR version )
 */
#define CanTp_PhysChannel_CanTpRxNSdu_CAN       0U
#endif /* defined CANTP_PROVIDE_LEGACY_SYMBOLIC_NAMES */


#if (defined CanTpConf_PhysChannel_CanTpRxNSdu_CAN_CanTpRxNPdu) /* to prevent double declaration */
#error CanTpConf_PhysChannel_CanTpRxNSdu_CAN_CanTpRxNPdu is already defined
#endif /* if (defined CanTpConf_PhysChannel_CanTpRxNSdu_CAN_CanTpRxNPdu) */

/** \brief Export symbolic name value for PhysChannel_CanTpRxNSdu_CAN_CanTpRxNPdu */
#define CanTpConf_PhysChannel_CanTpRxNSdu_CAN_CanTpRxNPdu  0U

#if (defined CANTP_PROVIDE_LEGACY_SYMBOLIC_NAMES)

#if (defined CanTp_PhysChannel_CanTpRxNSdu_CAN_CanTpRxNPdu) /* to prevent double declaration */
#error CanTp_PhysChannel_CanTpRxNSdu_CAN_CanTpRxNPdu is already defined
#endif /* if (defined CanTp_PhysChannel_CanTpRxNSdu_CAN_CanTpRxNPdu) */

/** \brief Export symbolic name value with module abbreviation as prefix only
           (AUTOSAR 4.0 rev2 <= AUTOSAR version )                               */
#define CanTp_PhysChannel_CanTpRxNSdu_CAN_CanTpRxNPdu       0U
#endif /* defined CANTP_PROVIDE_LEGACY_SYMBOLIC_NAMES */


#if (defined CanTpConf_PhysChannel_CanTpRxNSdu_CAN_CanTpTxFcNPdu) /* to prevent double declaration */
#error CanTpConf_PhysChannel_CanTpRxNSdu_CAN_CanTpTxFcNPdu is already defined
#endif /* if (defined CanTpConf_PhysChannel_CanTpRxNSdu_CAN_CanTpTxFcNPdu) */

/** \brief Export symbolic name value for PhysChannel_CanTpRxNSdu_CAN_CanTpTxFcNPdu */
#define CanTpConf_PhysChannel_CanTpRxNSdu_CAN_CanTpTxFcNPdu   2U

#if (defined CANTP_PROVIDE_LEGACY_SYMBOLIC_NAMES)
/** \brief Export symbolic name value with module abbreviation as prefix only
           (AUTOSAR 4.0 rev2 <= AUTOSAR version )                               */

#if (defined CanTp_PhysChannel_CanTpRxNSdu_CAN_CanTpTxFcNPdu) /* to prevent double declaration */
#error CanTp_PhysChannel_CanTpRxNSdu_CAN_CanTpTxFcNPdu is already defined
#endif /* if (defined CanTp_PhysChannel_CanTpRxNSdu_CAN_CanTpTxFcNPdu) */

#define CanTp_PhysChannel_CanTpRxNSdu_CAN_CanTpTxFcNPdu       2U
#endif /* defined CANTP_PROVIDE_LEGACY_SYMBOLIC_NAMES */

/*------------------------ CanTpRxNSdu_FD---------------------------------- */


#if (defined CanTpConf_CanTpRxNSdu_CanTpRxNSdu_FD) /* to prevent double declaration */
#error CanTpConf_CanTpRxNSdu_CanTpRxNSdu_FD is already defined
#endif /* if (defined CanTpConf_CanTpRxNSdu_CanTpRxNSdu_FD) */

/** \brief Export symbolic name value for PhysChannel_CanTpRxNSdu_FD */
#define CanTpConf_CanTpRxNSdu_CanTpRxNSdu_FD   1U

#if (defined CANTP_PROVIDE_LEGACY_SYMBOLIC_NAMES)

#if (defined CanTp_PhysChannel_CanTpRxNSdu_FD) /* to prevent double declaration */
#error CanTp_PhysChannel_CanTpRxNSdu_FD is already defined
#endif /* if (defined CanTp_PhysChannel_CanTpRxNSdu_FD) */

/** \brief Export symbolic name value with module abbreviation as prefix only
 *         (AUTOSAR 4.0 rev2 <= AUTOSAR version )
 */
#define CanTp_PhysChannel_CanTpRxNSdu_FD       1U
#endif /* defined CANTP_PROVIDE_LEGACY_SYMBOLIC_NAMES */


#if (defined CanTpConf_PhysChannel_CanTpRxNSdu_FD_CanTpRxNPdu) /* to prevent double declaration */
#error CanTpConf_PhysChannel_CanTpRxNSdu_FD_CanTpRxNPdu is already defined
#endif /* if (defined CanTpConf_PhysChannel_CanTpRxNSdu_FD_CanTpRxNPdu) */

/** \brief Export symbolic name value for PhysChannel_CanTpRxNSdu_FD_CanTpRxNPdu */
#define CanTpConf_PhysChannel_CanTpRxNSdu_FD_CanTpRxNPdu  1U

#if (defined CANTP_PROVIDE_LEGACY_SYMBOLIC_NAMES)

#if (defined CanTp_PhysChannel_CanTpRxNSdu_FD_CanTpRxNPdu) /* to prevent double declaration */
#error CanTp_PhysChannel_CanTpRxNSdu_FD_CanTpRxNPdu is already defined
#endif /* if (defined CanTp_PhysChannel_CanTpRxNSdu_FD_CanTpRxNPdu) */

/** \brief Export symbolic name value with module abbreviation as prefix only
           (AUTOSAR 4.0 rev2 <= AUTOSAR version )                               */
#define CanTp_PhysChannel_CanTpRxNSdu_FD_CanTpRxNPdu       1U
#endif /* defined CANTP_PROVIDE_LEGACY_SYMBOLIC_NAMES */


#if (defined CanTpConf_PhysChannel_CanTpRxNSdu_FD_CanTpTxFcNPdu) /* to prevent double declaration */
#error CanTpConf_PhysChannel_CanTpRxNSdu_FD_CanTpTxFcNPdu is already defined
#endif /* if (defined CanTpConf_PhysChannel_CanTpRxNSdu_FD_CanTpTxFcNPdu) */

/** \brief Export symbolic name value for PhysChannel_CanTpRxNSdu_FD_CanTpTxFcNPdu */
#define CanTpConf_PhysChannel_CanTpRxNSdu_FD_CanTpTxFcNPdu   3U

#if (defined CANTP_PROVIDE_LEGACY_SYMBOLIC_NAMES)
/** \brief Export symbolic name value with module abbreviation as prefix only
           (AUTOSAR 4.0 rev2 <= AUTOSAR version )                               */

#if (defined CanTp_PhysChannel_CanTpRxNSdu_FD_CanTpTxFcNPdu) /* to prevent double declaration */
#error CanTp_PhysChannel_CanTpRxNSdu_FD_CanTpTxFcNPdu is already defined
#endif /* if (defined CanTp_PhysChannel_CanTpRxNSdu_FD_CanTpTxFcNPdu) */

#define CanTp_PhysChannel_CanTpRxNSdu_FD_CanTpTxFcNPdu       3U
#endif /* defined CANTP_PROVIDE_LEGACY_SYMBOLIC_NAMES */

/*------------------------ CanTpRxNSdu_FuncFD---------------------------------- */


#if (defined CanTpConf_CanTpRxNSdu_CanTpRxNSdu_FuncFD) /* to prevent double declaration */
#error CanTpConf_CanTpRxNSdu_CanTpRxNSdu_FuncFD is already defined
#endif /* if (defined CanTpConf_CanTpRxNSdu_CanTpRxNSdu_FuncFD) */

/** \brief Export symbolic name value for FuncChannel_CanTpRxNSdu_FuncFD */
#define CanTpConf_CanTpRxNSdu_CanTpRxNSdu_FuncFD   2U

#if (defined CANTP_PROVIDE_LEGACY_SYMBOLIC_NAMES)

#if (defined CanTp_FuncChannel_CanTpRxNSdu_FuncFD) /* to prevent double declaration */
#error CanTp_FuncChannel_CanTpRxNSdu_FuncFD is already defined
#endif /* if (defined CanTp_FuncChannel_CanTpRxNSdu_FuncFD) */

/** \brief Export symbolic name value with module abbreviation as prefix only
 *         (AUTOSAR 4.0 rev2 <= AUTOSAR version )
 */
#define CanTp_FuncChannel_CanTpRxNSdu_FuncFD       2U
#endif /* defined CANTP_PROVIDE_LEGACY_SYMBOLIC_NAMES */


#if (defined CanTpConf_FuncChannel_CanTpRxNSdu_FuncFD_CanTpRxNPdu) /* to prevent double declaration */
#error CanTpConf_FuncChannel_CanTpRxNSdu_FuncFD_CanTpRxNPdu is already defined
#endif /* if (defined CanTpConf_FuncChannel_CanTpRxNSdu_FuncFD_CanTpRxNPdu) */

/** \brief Export symbolic name value for FuncChannel_CanTpRxNSdu_FuncFD_CanTpRxNPdu */
#define CanTpConf_FuncChannel_CanTpRxNSdu_FuncFD_CanTpRxNPdu  2U

#if (defined CANTP_PROVIDE_LEGACY_SYMBOLIC_NAMES)

#if (defined CanTp_FuncChannel_CanTpRxNSdu_FuncFD_CanTpRxNPdu) /* to prevent double declaration */
#error CanTp_FuncChannel_CanTpRxNSdu_FuncFD_CanTpRxNPdu is already defined
#endif /* if (defined CanTp_FuncChannel_CanTpRxNSdu_FuncFD_CanTpRxNPdu) */

/** \brief Export symbolic name value with module abbreviation as prefix only
           (AUTOSAR 4.0 rev2 <= AUTOSAR version )                               */
#define CanTp_FuncChannel_CanTpRxNSdu_FuncFD_CanTpRxNPdu       2U
#endif /* defined CANTP_PROVIDE_LEGACY_SYMBOLIC_NAMES */


/*------------------------ CanTpRxNSdu_Func---------------------------------- */


#if (defined CanTpConf_CanTpRxNSdu_CanTpRxNSdu_Func) /* to prevent double declaration */
#error CanTpConf_CanTpRxNSdu_CanTpRxNSdu_Func is already defined
#endif /* if (defined CanTpConf_CanTpRxNSdu_CanTpRxNSdu_Func) */

/** \brief Export symbolic name value for FuncChannel_CanTpRxNSdu_Func */
#define CanTpConf_CanTpRxNSdu_CanTpRxNSdu_Func   3U

#if (defined CANTP_PROVIDE_LEGACY_SYMBOLIC_NAMES)

#if (defined CanTp_FuncChannel_CanTpRxNSdu_Func) /* to prevent double declaration */
#error CanTp_FuncChannel_CanTpRxNSdu_Func is already defined
#endif /* if (defined CanTp_FuncChannel_CanTpRxNSdu_Func) */

/** \brief Export symbolic name value with module abbreviation as prefix only
 *         (AUTOSAR 4.0 rev2 <= AUTOSAR version )
 */
#define CanTp_FuncChannel_CanTpRxNSdu_Func       3U
#endif /* defined CANTP_PROVIDE_LEGACY_SYMBOLIC_NAMES */


#if (defined CanTpConf_FuncChannel_CanTpRxNSdu_Func_CanTpRxNPdu) /* to prevent double declaration */
#error CanTpConf_FuncChannel_CanTpRxNSdu_Func_CanTpRxNPdu is already defined
#endif /* if (defined CanTpConf_FuncChannel_CanTpRxNSdu_Func_CanTpRxNPdu) */

/** \brief Export symbolic name value for FuncChannel_CanTpRxNSdu_Func_CanTpRxNPdu */
#define CanTpConf_FuncChannel_CanTpRxNSdu_Func_CanTpRxNPdu  3U

#if (defined CANTP_PROVIDE_LEGACY_SYMBOLIC_NAMES)

#if (defined CanTp_FuncChannel_CanTpRxNSdu_Func_CanTpRxNPdu) /* to prevent double declaration */
#error CanTp_FuncChannel_CanTpRxNSdu_Func_CanTpRxNPdu is already defined
#endif /* if (defined CanTp_FuncChannel_CanTpRxNSdu_Func_CanTpRxNPdu) */

/** \brief Export symbolic name value with module abbreviation as prefix only
           (AUTOSAR 4.0 rev2 <= AUTOSAR version )                               */
#define CanTp_FuncChannel_CanTpRxNSdu_Func_CanTpRxNPdu       3U
#endif /* defined CANTP_PROVIDE_LEGACY_SYMBOLIC_NAMES */


/* generate macros for CanTpTxNSdus */


/*------------------------ CanTpTxNSdu_CAN---------------------------------- */


#if (defined CanTpConf_CanTpTxNSdu_CanTpTxNSdu_CAN) /* to prevent double declaration */
#error CanTpConf_CanTpTxNSdu_CanTpTxNSdu_CAN is already defined
#endif /* if (defined CanTpConf_CanTpTxNSdu_CanTpTxNSdu_CAN) */

/** \brief Export symbolic name value for PhysChannel_CanTpTxNSdu_CAN */
#define CanTpConf_CanTpTxNSdu_CanTpTxNSdu_CAN           0U

#if (defined CANTP_PROVIDE_LEGACY_SYMBOLIC_NAMES)

#if (defined CanTp_PhysChannel_CanTpTxNSdu_CAN) /* to prevent double declaration */
#error CanTp_PhysChannel_CanTpTxNSdu_CAN is already defined
#endif /* if (defined CanTp_PhysChannel_CanTpTxNSdu_CAN) */

/** \brief Export symbolic name value with module abbreviation as prefix only
 *         (AUTOSAR 4.0 rev2 <= AUTOSAR version )
 */
#define CanTp_PhysChannel_CanTpTxNSdu_CAN               0U
#endif /* defined CANTP_PROVIDE_LEGACY_SYMBOLIC_NAMES */


#if (defined CanTpConf_PhysChannel_CanTpTxNSdu_CAN_CanTpRxFcNPdu) /* to prevent double declaration */
#error CanTpConf_PhysChannel_CanTpTxNSdu_CAN_CanTpRxFcNPdu is already defined
#endif /* if (defined CanTpConf_PhysChannel_CanTpTxNSdu_CAN_CanTpRxFcNPdu) */

/** \brief Export symbolic name value for PhysChannel_CanTpTxNSdu_CAN_CanTpRxFcNPdu */
#define CanTpConf_PhysChannel_CanTpTxNSdu_CAN_CanTpRxFcNPdu  0U

#if (defined CANTP_PROVIDE_LEGACY_SYMBOLIC_NAMES)

#if (defined CanTp_PhysChannel_CanTpTxNSdu_CAN_CanTpRxFcNPdu) /* to prevent double declaration */
#error CanTp_PhysChannel_CanTpTxNSdu_CAN_CanTpRxFcNPdu is already defined
#endif /* if (defined CanTp_PhysChannel_CanTpTxNSdu_CAN_CanTpRxFcNPdu) */

/** \brief Export symbolic name value with module abbreviation as prefix only
           (AUTOSAR 4.0 rev2 <= AUTOSAR version )                               */
#define CanTp_PhysChannel_CanTpTxNSdu_CAN_CanTpRxFcNPdu      0U
#endif /* defined CANTP_PROVIDE_LEGACY_SYMBOLIC_NAMES */


#if (defined CanTpConf_PhysChannel_CanTpTxNSdu_CAN_CanTpTxNPdu) /* to prevent double declaration */
#error CanTpConf_PhysChannel_CanTpTxNSdu_CAN_CanTpTxNPdu is already defined
#endif /* if (defined CanTpConf_PhysChannel_CanTpTxNSdu_CAN_CanTpTxNPdu) */

/** \brief Export symbolic name value for PhysChannel_CanTpTxNSdu_CAN_CanTpTxNPdu */
#define CanTpConf_PhysChannel_CanTpTxNSdu_CAN_CanTpTxNPdu   0U

#if (defined CANTP_PROVIDE_LEGACY_SYMBOLIC_NAMES)

#if (defined CanTp_PhysChannel_CanTpTxNSdu_CAN_CanTpTxNPdu) /* to prevent double declaration */
#error CanTp_PhysChannel_CanTpTxNSdu_CAN_CanTpTxNPdu is already defined
#endif /* if (defined CanTp_PhysChannel_CanTpTxNSdu_CAN_CanTpTxNPdu) */

/** \brief Export symbolic name value with module abbreviation as prefix only
           (AUTOSAR 4.0 rev2 <= AUTOSAR version )                               */
#define CanTp_PhysChannel_CanTpTxNSdu_CAN_CanTpTxNPdu       0U
#endif /* defined CANTP_PROVIDE_LEGACY_SYMBOLIC_NAMES */

/*------------------------ CanTpTxNSdu_FD---------------------------------- */


#if (defined CanTpConf_CanTpTxNSdu_CanTpTxNSdu_FD) /* to prevent double declaration */
#error CanTpConf_CanTpTxNSdu_CanTpTxNSdu_FD is already defined
#endif /* if (defined CanTpConf_CanTpTxNSdu_CanTpTxNSdu_FD) */

/** \brief Export symbolic name value for PhysChannel_CanTpTxNSdu_FD */
#define CanTpConf_CanTpTxNSdu_CanTpTxNSdu_FD           1U

#if (defined CANTP_PROVIDE_LEGACY_SYMBOLIC_NAMES)

#if (defined CanTp_PhysChannel_CanTpTxNSdu_FD) /* to prevent double declaration */
#error CanTp_PhysChannel_CanTpTxNSdu_FD is already defined
#endif /* if (defined CanTp_PhysChannel_CanTpTxNSdu_FD) */

/** \brief Export symbolic name value with module abbreviation as prefix only
 *         (AUTOSAR 4.0 rev2 <= AUTOSAR version )
 */
#define CanTp_PhysChannel_CanTpTxNSdu_FD               1U
#endif /* defined CANTP_PROVIDE_LEGACY_SYMBOLIC_NAMES */


#if (defined CanTpConf_PhysChannel_CanTpTxNSdu_FD_CanTpRxFcNPdu) /* to prevent double declaration */
#error CanTpConf_PhysChannel_CanTpTxNSdu_FD_CanTpRxFcNPdu is already defined
#endif /* if (defined CanTpConf_PhysChannel_CanTpTxNSdu_FD_CanTpRxFcNPdu) */

/** \brief Export symbolic name value for PhysChannel_CanTpTxNSdu_FD_CanTpRxFcNPdu */
#define CanTpConf_PhysChannel_CanTpTxNSdu_FD_CanTpRxFcNPdu  1U

#if (defined CANTP_PROVIDE_LEGACY_SYMBOLIC_NAMES)

#if (defined CanTp_PhysChannel_CanTpTxNSdu_FD_CanTpRxFcNPdu) /* to prevent double declaration */
#error CanTp_PhysChannel_CanTpTxNSdu_FD_CanTpRxFcNPdu is already defined
#endif /* if (defined CanTp_PhysChannel_CanTpTxNSdu_FD_CanTpRxFcNPdu) */

/** \brief Export symbolic name value with module abbreviation as prefix only
           (AUTOSAR 4.0 rev2 <= AUTOSAR version )                               */
#define CanTp_PhysChannel_CanTpTxNSdu_FD_CanTpRxFcNPdu      1U
#endif /* defined CANTP_PROVIDE_LEGACY_SYMBOLIC_NAMES */


#if (defined CanTpConf_PhysChannel_CanTpTxNSdu_FD_CanTpTxNPdu) /* to prevent double declaration */
#error CanTpConf_PhysChannel_CanTpTxNSdu_FD_CanTpTxNPdu is already defined
#endif /* if (defined CanTpConf_PhysChannel_CanTpTxNSdu_FD_CanTpTxNPdu) */

/** \brief Export symbolic name value for PhysChannel_CanTpTxNSdu_FD_CanTpTxNPdu */
#define CanTpConf_PhysChannel_CanTpTxNSdu_FD_CanTpTxNPdu   1U

#if (defined CANTP_PROVIDE_LEGACY_SYMBOLIC_NAMES)

#if (defined CanTp_PhysChannel_CanTpTxNSdu_FD_CanTpTxNPdu) /* to prevent double declaration */
#error CanTp_PhysChannel_CanTpTxNSdu_FD_CanTpTxNPdu is already defined
#endif /* if (defined CanTp_PhysChannel_CanTpTxNSdu_FD_CanTpTxNPdu) */

/** \brief Export symbolic name value with module abbreviation as prefix only
           (AUTOSAR 4.0 rev2 <= AUTOSAR version )                               */
#define CanTp_PhysChannel_CanTpTxNSdu_FD_CanTpTxNPdu       1U
#endif /* defined CANTP_PROVIDE_LEGACY_SYMBOLIC_NAMES */

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

/*==================[internal function definitions]=========================*/


#endif /* ifndef CANTP_SYMBOLICNAMES_PBCFG_H */
/*==================[end of file]===========================================*/
/* CHECK: PARSE */
