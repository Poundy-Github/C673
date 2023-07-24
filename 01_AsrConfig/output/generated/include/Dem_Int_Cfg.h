/**
 * \file
 *
 * \brief AUTOSAR Dem
 *
 * This file contains the implementation of the AUTOSAR
 * module Dem.
 *
 * \version 6.4.3
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2021 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */
#ifndef DEM_INT_CFG_H
#define DEM_INT_CFG_H

/* This file contains the all module internal configuration declarations for
 * the AUTOSAR module Dem that are target independent. */



/*==================[includes]==============================================*/
/* !LINKSTO dsn.Dem.IncludeStr,1 */

/*------------------[callback header file inclusions]-----------------------*/


/*==================[macros]================================================*/

/*------------------[General]-----------------------------------------------*/

#if (defined DEM_USE_AGING)
#error DEM_USE_AGING already defined
#endif
/** \brief Macro for Enabling/Disabling aging functionality */
#define DEM_USE_AGING   STD_ON

#if (defined DEM_USE_INT_VAL_AREA)
#error DEM_USE_INT_VAL_AREA already defined
#endif
/** \brief Macro for Enabling/Disabling internal value area
 **
 ** In the current implementation the existance of the internal value area
 ** depends on aging only. */
#define DEM_USE_INT_VAL_AREA   DEM_USE_AGING

#if (defined DEM_USE_MAPPED_INT_DATA_ELEMENTS)
#error DEM_USE_MAPPED_INT_DATA_ELEMENTS already defined
#endif
/** \brief Macro for Enabling/Disabling internal data elements mapping */
#define DEM_USE_MAPPED_INT_DATA_ELEMENTS    STD_ON




/*------------------[Defensive programming]---------------------------------*/

#if (defined DEM_DEFENSIVE_PROGRAMMING_ENABLED)
#error DEM_DEFENSIVE_PROGRAMMING_ENABLED is already defined
#endif
/** \brief Defensive programming usage
 **
 ** En- or disables the usage of the defensive programming */
#define DEM_DEFENSIVE_PROGRAMMING_ENABLED   STD_OFF
#if (defined DEM_PRECONDITION_ASSERT_ENABLED)
#error DEM_PRECONDITION_ASSERT_ENABLED is already defined
#endif
/** \brief Precondition assertion usage
 **
 ** En- or disables the usage of precondition assertion checks */
#define DEM_PRECONDITION_ASSERT_ENABLED     STD_OFF
#if (defined DEM_POSTCONDITION_ASSERT_ENABLED)
#error DEM_POSTCONDITION_ASSERT_ENABLED is already defined
#endif
/** \brief Postcondition assertion usage
 **
 ** En- or disables the usage of postcondition assertion checks */
#define DEM_POSTCONDITION_ASSERT_ENABLED    STD_OFF
#if (defined DEM_UNREACHABLE_CODE_ASSERT_ENABLED)
#error DEM_UNREACHABLE_CODE_ASSERT_ENABLED is already defined
#endif
/** \brief Unreachable code assertion usage
 **
 ** En- or disables the usage of unreachable code assertion checks */
#define DEM_UNREACHABLE_CODE_ASSERT_ENABLED STD_OFF
#if (defined DEM_INVARIANT_ASSERT_ENABLED)
#error DEM_INVARIANT_ASSERT_ENABLED is already defined
#endif
/** \brief Invariant assertion usage
 **
 ** En- or disables the usage of invariant assertion checks */
#define DEM_INVARIANT_ASSERT_ENABLED        STD_OFF
#if (defined DEM_STATIC_ASSERT_ENABLED)
#error DEM_STATIC_ASSERT_ENABLED is already defined
#endif
/** \brief Static assertion usage
 **
 ** En- or disables the usage of static assertion checks */
#define DEM_STATIC_ASSERT_ENABLED           STD_OFF



/*------------------[Callback macros]---------------------------------------*/

#if (defined DEM_CB_TABLE_INIT_MONITOR_SIZE)
#error DEM_CB_TABLE_INIT_MONITOR_SIZE already defined
#endif
/** \brief Size of the generic callback function pointer table for InitMonitor */
#define DEM_CB_TABLE_INIT_MONITOR_SIZE 0U

#if (defined DEM_LOOKUP_TABLE_INIT_MONITOR_SIZE)
#error DEM_LOOKUP_TABLE_INIT_MONITOR_SIZE already defined
#endif
/** \brief Size of the generic lookup table for InitMonitor */
#define DEM_LOOKUP_TABLE_INIT_MONITOR_SIZE 0U

#if (defined DEM_USE_CB_INIT_MONITOR)
#error DEM_USE_CB_INIT_MONITOR already defined
#endif
/** \brief Macro for Enabling/Disabling init monitor callback functionality */
#if (DEM_CB_TABLE_INIT_MONITOR_SIZE > 0U)
#define DEM_USE_CB_INIT_MONITOR STD_ON
#else
#define DEM_USE_CB_INIT_MONITOR STD_OFF
#endif


#if (defined DEM_C_CALLBACK_TABLE_TRIG_ON_EVST_SIZE)
#error DEM_C_CALLBACK_TABLE_TRIG_ON_EVST_SIZE already defined
#endif
/** \brief Size of the C-callback function pointer table for TriggerOnEventStatus */
#define DEM_C_CALLBACK_TABLE_TRIG_ON_EVST_SIZE 0U

#if (defined DEM_RTE_CALLBACK_TABLE_TRIG_ON_EVST_SIZE)
#error DEM_RTE_CALLBACK_TABLE_TRIG_ON_EVST_SIZE already defined
#endif
/** \brief Size of the RTE-callback function pointer table for TriggerOnEventStatus */
#define DEM_RTE_CALLBACK_TABLE_TRIG_ON_EVST_SIZE 73U

#if (defined DEM_C_LOOKUP_TABLE_TRIG_ON_EVST_SIZE)
#error DEM_C_LOOKUP_TABLE_TRIG_ON_EVST_SIZE already defined
#endif
/** \brief Size of the C-lookup table for TriggerOnEventStatus */
#define DEM_C_LOOKUP_TABLE_TRIG_ON_EVST_SIZE 0U

#if (defined DEM_RTE_LOOKUP_TABLE_TRIG_ON_EVST_SIZE)
#error DEM_RTE_LOOKUP_TABLE_TRIG_ON_EVST_SIZE already defined
#endif
/** \brief Size of the RTE-lookup table for TriggerOnEventStatus */
#define DEM_RTE_LOOKUP_TABLE_TRIG_ON_EVST_SIZE 73U


#if (defined DEM_CB_TABLE_TRIG_ON_DTCST_SIZE)
#error DEM_CB_TABLE_TRIG_ON_DTCST_SIZE already defined
#endif
/** \brief Size of the C-callback function pointer table for TriggerOnDTCEventStatus */
#define DEM_CB_TABLE_TRIG_ON_DTCST_SIZE 0U

#if (defined DEM_USE_CB_TRIG_ON_STATUS_CHANGE)
#error DEM_USE_CB_TRIG_ON_STATUS_CHANGE already defined
#endif
/** \brief Macro for Enabling/Disabling trigger on event status or DTC event callback
 ** functionality */
#define DEM_USE_CB_TRIG_ON_STATUS_CHANGE STD_ON


#if (defined DEM_C_CB_TABLE_TRIG_ON_EVDAT_SIZE )
#error DEM_C_CB_TABLE_TRIG_ON_EVDAT_SIZE  already defined
#endif
/** \brief Size of the C-callback function pointer table for TriggerOnEventDataChanged */
#define DEM_C_CB_TABLE_TRIG_ON_EVDAT_SIZE  0U

#if (defined DEM_RTE_CB_TABLE_TRIG_ON_EVDAT_SIZE)
#error DEM_RTE_CB_TABLE_TRIG_ON_EVDAT_SIZE already defined
#endif
/** \brief Size of the RTE-callback function pointer table for TriggerOnEventDataChanged */
#define DEM_RTE_CB_TABLE_TRIG_ON_EVDAT_SIZE 0U

#if (defined DEM_C_LOOKUP_TABLE_TRIG_ON_EVDAT_SIZE)
#error DEM_C_LOOKUP_TABLE_TRIG_ON_EVDAT_SIZE already defined
#endif
/** \brief Size of the C-lookup table for TriggerOnEventDataChanged */
#define DEM_C_LOOKUP_TABLE_TRIG_ON_EVDAT_SIZE 0U

#if (defined DEM_RTE_LOOKUP_TABLE_TRIG_ON_EVDAT_SIZE)
#error DEM_RTE_LOOKUP_TABLE_TRIG_ON_EVDAT_SIZE already defined
#endif
/** \brief Size of the RTE-lookup table for TriggerOnEventDataChanged */
#define DEM_RTE_LOOKUP_TABLE_TRIG_ON_EVDAT_SIZE 0U

#if (defined DEM_USE_CB_TRIG_ON_EVDAT)
#error DEM_USE_CB_TRIG_ON_EVDAT already defined
#endif
/** \brief Macro for Enabling/Disabling trigger on event data changed callback functionality */
#if ( (DEM_RTE_CB_TABLE_TRIG_ON_EVDAT_SIZE > 0U) || \
      (DEM_C_CB_TABLE_TRIG_ON_EVDAT_SIZE > 0U) )
#define DEM_USE_CB_TRIG_ON_EVDAT STD_ON
#else
#define DEM_USE_CB_TRIG_ON_EVDAT STD_OFF
#endif


#if (defined DEM_C_CB_TABLE_CLEAR_EVENT_ALLOWED_SIZE)
#error DEM_C_CB_TABLE_CLEAR_EVENT_ALLOWED_SIZE  already defined
#endif
/** \brief Size of the C-callback function pointer table for ClearEventAllowed */
#define DEM_C_CB_TABLE_CLEAR_EVENT_ALLOWED_SIZE  0U

#if (defined DEM_RTE_CB_TABLE_CLEAR_EVENT_ALLOWED_SIZE)
#error DEM_RTE_CB_TABLE_CLEAR_EVENT_ALLOWED_SIZE already defined
#endif
/** \brief Size of the RTE-callback function pointer table for ClearEventAllowed */
#define DEM_RTE_CB_TABLE_CLEAR_EVENT_ALLOWED_SIZE 0U

#if (defined DEM_C_LOOKUP_TABLE_CLEAR_EVENT_ALLOWED_SIZE)
#error DEM_C_LOOKUP_TABLE_CLEAR_EVENT_ALLOWED_SIZE already defined
#endif
/** \brief Size of the C-lookup table for ClearEventAllowed */
#define DEM_C_LOOKUP_TABLE_CLEAR_EVENT_ALLOWED_SIZE 0U

#if (defined DEM_RTE_LOOKUP_TABLE_CLEAR_EVENT_ALLOWED_SIZE)
#error DEM_RTE_LOOKUP_TABLE_CLEAR_EVENT_ALLOWED_SIZE already defined
#endif
/** \brief Size of the RTE-lookup table for ClearEventAllowed */
#define DEM_RTE_LOOKUP_TABLE_CLEAR_EVENT_ALLOWED_SIZE 0U

#if (defined DEM_USE_CB_CLEAR_EVENT_ALLOWED)
#error DEM_USE_CB_CLEAR_EVENT_ALLOWED already defined
#endif
/** \brief Macro for Enabling/Disabling ClearEventAllowed callback functionality */
#if ( (DEM_RTE_CB_TABLE_CLEAR_EVENT_ALLOWED_SIZE > 0U) || \
      (DEM_C_CB_TABLE_CLEAR_EVENT_ALLOWED_SIZE > 0U) )
#define DEM_USE_CB_CLEAR_EVENT_ALLOWED STD_ON
#else
#define DEM_USE_CB_CLEAR_EVENT_ALLOWED STD_OFF
#endif


#if (defined DEM_CB_TABLE_GET_FDC_SIZE)
#error DEM_CB_TABLE_GET_FDC_SIZE already defined
#endif
/** \brief Size of the generic callback function pointer table for GetFaultDetectionCounter */
#define DEM_CB_TABLE_GET_FDC_SIZE 0U

#if (defined DEM_LOOKUP_TABLE_GET_FDC_SIZE)
#error DEM_LOOKUP_TABLE_GET_FDC_SIZE already defined
#endif
/** \brief Size of the generic lookup table for GetFaultDetectionCounter */
#define DEM_LOOKUP_TABLE_GET_FDC_SIZE 0U

#if (defined DEM_USE_CB_GET_FDC)
#error DEM_USE_CB_GET_FDC already defined
#endif
/** \brief Macro for Enabling/Disabling fault detection counter callback
 ** functionality */
#if (DEM_CB_TABLE_GET_FDC_SIZE > 0U)
#define DEM_USE_CB_GET_FDC STD_ON
#else
#define DEM_USE_CB_GET_FDC STD_OFF
#endif

/*------------------[Client configuration]----------------------------------*/
#if (defined DEM_NUMBER_OF_CLIENTS)
#error DEM_NUMBER_OF_CLIENTS is already defined
#endif
/** \brief Number of configured clients
 **/
#define DEM_NUMBER_OF_CLIENTS      1U

#if (defined DEM_NUM_CLIENTS_SIZE)
#error DEM_NUM_CLIENTS_SIZE is already defined
#endif
/** \brief Array size of clients filter set flag
 **/
#define DEM_NUM_CLIENTS_SIZE 1U



#if (defined DEM_NUMBER_OF_VIRTUAL_CLIENTS)
#error DEM_NUMBER_OF_VIRTUAL_CLIENTS already defined
#endif
/** \brief Number of virtual clients
 **/
#define DEM_NUMBER_OF_VIRTUAL_CLIENTS 0U

/*------------------[DTC groups configuration]------------------------------*/

/* Symbolic names of internal DTC group indexes */

#if (defined DEM_DTCGRP_IDX_POWERTRAIN_DTCS)
#error DEM_DTCGRP_IDX_POWERTRAIN_DTCS already defined
#endif
/** \brief Symbolic name of DTC group POWERTRAIN_DTCS index */
#define DEM_DTCGRP_IDX_POWERTRAIN_DTCS                 0U

#if (defined DEM_DTCGRP_IDX_CHASSIS_DTCS)
#error DEM_DTCGRP_IDX_CHASSIS_DTCS already defined
#endif
/** \brief Symbolic name of DTC group CHASSIS_DTCS index */
#define DEM_DTCGRP_IDX_CHASSIS_DTCS                    1U

#if (defined DEM_DTCGRP_IDX_BODY_DTCS)
#error DEM_DTCGRP_IDX_BODY_DTCS already defined
#endif
/** \brief Symbolic name of DTC group BODY_DTCS index */
#define DEM_DTCGRP_IDX_BODY_DTCS                       2U

#if (defined DEM_DTCGRP_IDX_NETWORK_COM_DTCS)
#error DEM_DTCGRP_IDX_NETWORK_COM_DTCS already defined
#endif
/** \brief Symbolic name of DTC group NETWORK_COM_DTCS index */
#define DEM_DTCGRP_IDX_NETWORK_COM_DTCS                3U

#if (defined DEM_DTCGRP_IDX_NO_DTC)
#error DEM_DTCGRP_IDX_NO_DTC already defined
#endif
/** \brief Symbolic name of DTC group index for events without a DTC */
#define DEM_DTCGRP_IDX_NO_DTC  (4U)

#if (defined DEM_NUM_DTC_GROUPS)
#error DEM_NUM_DTC_GROUPS already defined
#endif
/** \brief Number of DTC groups used to define a size of the Dem_DTCGroups[] array */
#define DEM_NUM_DTC_GROUPS 4U

#if (defined DEM_DTCGRP_IDX_INVALID)
#error DEM_DTCGRP_IDX_INVALID already defined
#endif
/** \brief Symbolic name of invalid DTC group index */
#define DEM_DTCGRP_IDX_INVALID  (DEM_NUM_DTC_GROUPS + 1U)

#if (defined DEM_DTCGRP_IDX_ALL_DTC)
#error DEM_DTCGRP_IDX_ALL_DTC already defined
#endif
/** \brief Symbolic name of unassigned DTC group index */
#define DEM_DTCGRP_IDX_ALL_DTC  (DEM_NUM_DTC_GROUPS + 2U)

/*------------------[Freeze frame configuration]----------------------------*/


/* Size of the freeze frame class DemFreezeFrameClass_A in bytes: 22 */
/* Size of the freeze frame class DemFreezeFrameClass_B in bytes: 32 */

#if (defined DEM_MAXSIZE_FFCLS)
#error DEM_MAXSIZE_FFCLS already defined
#endif
/** \brief Maximum size of a freeze frame class in bytes */
#define DEM_MAXSIZE_FFCLS 32U

/* Symblic names of internal freeze frame class indexes */
#if (defined DEM_FFCLS_IDX_DemFreezeFrameClass_A)
#error DEM_FFCLS_IDX_DemFreezeFrameClass_A already defined
#endif
/** \brief Symbolic name of freeze frame class DemFreezeFrameClass_A index */
#define DEM_FFCLS_IDX_DemFreezeFrameClass_A           0U
#if (defined DEM_FFCLS_IDX_DemFreezeFrameClass_B)
#error DEM_FFCLS_IDX_DemFreezeFrameClass_B already defined
#endif
/** \brief Symbolic name of freeze frame class DemFreezeFrameClass_B index */
#define DEM_FFCLS_IDX_DemFreezeFrameClass_B           1U

#if (defined DEM_FFCLS_NULL_IDX)
#error DEM_FFCLS_NULL_IDX already defined
#endif
/** \brief Symbolic name of freeze frame class null index */
#define DEM_FFCLS_NULL_IDX                             2U

#if (defined DEM_NUM_FFCLS)
#error DEM_NUM_FFCLS already defined
#endif
/** \brief Number of different freeze frame classes */
#define DEM_NUM_FFCLS 3U

#if (defined DEM_NUM_FFSEGS)
#error DEM_NUM_FFSEGS already defined
#endif
/** \brief Number of different freeze frame segments */
#define DEM_NUM_FFSEGS 10U

/*------------------[Freeze frame record number configuration]--------------*/

/*---------------------[Common Freeze Frame]--------------------------------*/

#if (defined DEM_COMMON_FF_CLASS_IDX)
#error DEM_COMMON_FF_CLASS_IDX already defined
#endif
/** \brief Defines the index of the regular common freeze frame class */
#define DEM_COMMON_FF_CLASS_IDX   DEM_FFCLS_NULL_IDX

/*------------------[Development Freeze Frame]------------------------------*/

/* !LINKSTO dsn.Dem.DevFF.DemCommonFFDataDevAClassRef,1 */
#if (defined DEM_COMMON_DEVFFA_CLASS_IDX)
#error DEM_COMMON_DEVFFA_CLASS_IDX already defined
#endif
/** \brief Switch, indicating if Development Freeze Frames are enabled */
#define DEM_COMMON_DEVFFA_CLASS_IDX   DEM_FFCLS_NULL_IDX

/*------------------[Prestored freeze frame configuration]------------------*/

#if (defined DEM_PFF_ZERO_END)
#error DEM_PFF_ZERO_END already defined
#endif
/** \brief Zero value to be added to each size, whose involved patterns could
 ** be none */
#define DEM_PFF_ZERO_END                  0U

#if (defined DEM_SIZE_PFF_ENTRY_DATA)
#error DEM_SIZE_PFF_ENTRY_DATA already defined
#endif
/** \brief Size of dynamic PFF entry data
 **
 ** All FF sizes of events with enabled prestorage are added.
 **/
#define DEM_SIZE_PFF_ENTRY_DATA \
  (22U +   DEM_PFF_ZERO_END)

/*------------------[Extended data configuration]---------------------------*/


/* Size of the extended data class DemExtendedDataClass_0 in bytes: 1 */

#if (defined DEM_MAXSIZE_EDCLS)
#error DEM_MAXSIZE_EDCLS already defined
#endif
/** \brief Maximum size of a extended data class in bytes */
#define DEM_MAXSIZE_EDCLS 1U

/* Symbolic names of internal extended data class indexes */

#if (defined DEM_EDCLS_IDX_DemExtendedDataClass_0)
#error DEM_EDCLS_IDX_DemExtendedDataClass_0 already defined
#endif
/** \brief Symbolic name of extended data class DemExtendedDataClass_0 index */
#define DEM_EDCLS_IDX_DemExtendedDataClass_0          0U

#if (defined DEM_EDCLS_NULL_IDX)
#error DEM_EDCLS_NULL_IDX already defined
#endif
/** \brief Symbolic name of extended data class null index */
#define DEM_EDCLS_NULL_IDX                             1U

#if (defined DEM_NUM_EDCLS)
#error DEM_NUM_EDCLS already defined
#endif
/** \brief Number of different extended data classes */
#define DEM_NUM_EDCLS 2U

#if (defined DEM_NUM_EDSEGS)
#error DEM_NUM_EDSEGS already defined
#endif
/** \brief Number of different extended data segments */
#define DEM_NUM_EDSEGS 1U

/*------------------[Data elements configuration]---------------------------*/

/*
 * IMPORTANT to synchronize the order with implementation in function
 * Dem_AssembleEDSegIntData(). Macro order is important to the algorithm
 * in the assamble function.
 *
 * Up to 35 internal data values reserved for internal use
 * based on maximum value of configuration parameter DemDataElementClass.
 */

#if (defined DEM_NUM_EXT_CS_DATAELEMENTS)
#error DEM_NUM_EXT_CS_DATAELEMENTS already defined
#endif
/** \brief Number of different data elements of type DemExternalCSDataElementClass */
#define DEM_NUM_EXT_CS_DATAELEMENTS 10U

#if (defined DEM_NUM_EXT_SR_DATAELEMENTS)
#error DEM_NUM_EXT_SR_DATAELEMENTS already defined
#endif
/** \brief Number of different data elements of type DemExternalSRDataElementClass */
#define DEM_NUM_EXT_SR_DATAELEMENTS 0U

#if (defined DEM_NUM_EXT_DATAELEMENTS)
#error DEM_NUM_EXT_DATAELEMENTS already defined
#endif
/** \brief Number of different external data elements both CS and SR */
#define DEM_NUM_EXT_DATAELEMENTS (DEM_NUM_EXT_CS_DATAELEMENTS + DEM_NUM_EXT_SR_DATAELEMENTS)

#if (defined DEM_INT_VAL_IDX_OCCCTR)
#error DEM_INT_VAL_IDX_OCCCTR already defined
#endif
/** \brief Macro for internal data element 'Occurrence counter' */
#define DEM_INT_VAL_IDX_OCCCTR    DEM_NUM_EXT_DATAELEMENTS

#if (defined DEM_INT_VAL_IDX_AGECTRUP)
#error DEM_INT_VAL_IDX_AGECTRUP already defined
#endif
/** \brief Macro for internal data element 'Aging counter' */
#define DEM_INT_VAL_IDX_AGECTRUP    (DEM_NUM_EXT_DATAELEMENTS + 1U)

#if (defined DEM_INT_VAL_IDX_AGECTRDWN)
#error DEM_INT_VAL_IDX_AGECTRDWN already defined
#endif
/** \brief Macro for internal data element 'Aging counter' */
#define DEM_INT_VAL_IDX_AGECTRDWN  (DEM_NUM_EXT_DATAELEMENTS + 2U)

#if (defined DEM_INT_VAL_IDX_OVFIND)
#error DEM_INT_VAL_IDX_OVFIND already defined
#endif
/** \brief Macro for internal data element 'Overflow indication' */
#define DEM_INT_VAL_IDX_OVFIND    (DEM_NUM_EXT_DATAELEMENTS + 3U)

#if (defined DEM_INT_VAL_IDX_EVSIGNIF)
#error DEM_INT_VAL_IDX_EVSIGNIF already defined
#endif
/** \brief Macro for internal data element 'Event significance' */
#define DEM_INT_VAL_IDX_EVSIGNIF  (DEM_NUM_EXT_DATAELEMENTS + 4U)

#if (defined DEM_INT_VAL_IDX_PRIO)
#error DEM_INT_VAL_IDX_PRIO already defined
#endif
/** \brief Macro for internal data element 'Event priority' */
#define DEM_INT_VAL_IDX_PRIO      (DEM_NUM_EXT_DATAELEMENTS + 5U)

#if (defined DEM_INT_VAL_IDX_EVENT_ID)
#error DEM_INT_VAL_IDX_EVENT_ID already defined
#endif
/** \brief Macro for internal data element 'EventID */
#define DEM_INT_VAL_IDX_EVENT_ID  (DEM_NUM_EXT_DATAELEMENTS + 6U)
#if (defined DEM_INT_VAL_IDX_CSLF)
#error DEM_INT_VAL_IDX_CSLF already defined
#endif

/** \brief Macro for internal data element 'number of operation cycles since the
 ** DTC fault detection counter last reached its maximum value +127' */
#define DEM_INT_VAL_IDX_CSLF        (DEM_NUM_EXT_DATAELEMENTS + 7U)
#if (defined DEM_INT_VAL_IDX_CSFF)

#error DEM_INT_VAL_IDX_CSFF already defined
#endif
/** \brief Macro for internal data element 'number of operation cycles since the
 ** DTC fault detection counter first reached its maximum value of +127' */
#define DEM_INT_VAL_IDX_CSFF        (DEM_NUM_EXT_DATAELEMENTS + 8U)

#if (defined DEM_INT_VAL_IDX_CURRENT_FDC)
#error DEM_INT_VAL_IDX_CURRENT_FDC already defined
#endif
/** \brief Macro for internal data element 'Fault detection counter' */
#define DEM_INT_VAL_IDX_CURRENT_FDC (DEM_NUM_EXT_DATAELEMENTS + 9U)

#if (defined DEM_INT_VAL_IDX_FDC12)
#error DEM_INT_VAL_IDX_FDC12 already defined
#endif
/** \brief Macro for internal data element 'Maximum fault detection
 ** counter since last clear' */
#define DEM_INT_VAL_IDX_FDC12      (DEM_NUM_EXT_DATAELEMENTS + 10U)

#if (defined DEM_INT_VAL_IDX_SI30)
#error DEM_INT_VAL_IDX_SI30 already defined
#endif
/** \brief Macro for internal data element 'DTC status indicators' */
#define DEM_INT_VAL_IDX_SI30      (DEM_NUM_EXT_DATAELEMENTS + 11U)

#if (defined DEM_INT_VAL_IDX_OCC1)
#error DEM_INT_VAL_IDX_OCC1 already defined
#endif
/** \brief Macro for internal data element 'Operation cycles since
 ** last unconfirmedDTC counter' */
#define DEM_INT_VAL_IDX_OCC1      (DEM_NUM_EXT_DATAELEMENTS + 12U)

#if (defined DEM_INT_VAL_IDX_OCC2)
#error DEM_INT_VAL_IDX_OCC2 already defined
#endif
/** \brief Macro for internal data element 'UnconfirmedDTC aging counter' */
#define DEM_INT_VAL_IDX_OCC2       (DEM_NUM_EXT_DATAELEMENTS + 13U)

#if (defined DEM_INT_VAL_IDX_OCC3)
#error DEM_INT_VAL_IDX_OCC3 already defined
#endif
/** \brief Macro for internal data element 'Operation cycles since first
 ** unconfirmedDTC counter' */
#define DEM_INT_VAL_IDX_OCC3      (DEM_NUM_EXT_DATAELEMENTS + 14U)

#if (defined DEM_INT_VAL_IDX_OCC4)
#error DEM_INT_VAL_IDX_OCC4 already defined
#endif
/** \brief Macro for internal data element 'UnconfirmedDTC operation cycle
 ** counter' */
#define DEM_INT_VAL_IDX_OCC4      (DEM_NUM_EXT_DATAELEMENTS + 15U)

#if (defined DEM_INT_VAL_IDX_OCC6)
#error DEM_INT_VAL_IDX_OCC6 already defined
#endif
/** \brief Macro for internal data element 'Consecutive failed operation cycle
 ** counter' */
#define DEM_INT_VAL_IDX_OCC6      (DEM_NUM_EXT_DATAELEMENTS + 16U)

#if (defined DEM_INT_VAL_IDX_OCC7)
#error DEM_INT_VAL_IDX_OCC7 already defined
#endif
/** \brief Macro for internal data element 'Qualified/unconfirmedDTC operation
 ** cycle counter' */
#define DEM_INT_VAL_IDX_OCC7      (DEM_NUM_EXT_DATAELEMENTS + 17U)

#if (defined DEM_INT_VAL_IDX_OCC5)
#error DEM_INT_VAL_IDX_OCC5 already defined
#endif
/** \brief Macro for internal data element 'Warm-up cycles (WUC) where event
 **  is reported as active until it becomes confirmed counter' */
#define DEM_INT_VAL_IDX_OCC5      (DEM_NUM_EXT_DATAELEMENTS + 18U)

#if (defined DEM_INT_VAL_IDX_ROOT_ID)
#error DEM_INT_VAL_IDX_ROOT_ID already defined
#endif
#define DEM_INT_VAL_IDX_ROOT_ID    (DEM_NUM_EXT_DATAELEMENTS + 19U)

#if (defined DEM_INT_VAL_UNUSED)
#error DEM_INT_VAL_UNUSED already defined
#endif
/** \brief Macro for no internal data element used for the
 **  Dem_CheckIntDataElementUsage() internal API */
#define DEM_INT_VAL_UNUSED        (DEM_NUM_EXT_DATAELEMENTS + 20U)

/*------------------[Events configuration]----------------------------------*/
/* 1st 32 bits of event description layout */

#if (defined DEM_UDS_DTC_OFFSET)
#error DEM_UDS_DTC_OFFSET already defined
#endif
/** \brief Offset of UDS DTC in 1st element of event desc */
#define DEM_UDS_DTC_OFFSET            0U

#if (defined DEM_DTCORIGIN_OFFSET)
#error DEM_DTCORIGIN_OFFSET already defined
#endif
/** \brief Offset of DTC origin in 1st element of event desc */
#define DEM_DTCORIGIN_OFFSET            24U

#if (defined DEM_DTCSEVERITY_OFFSET)
#error DEM_DTCSEVERITY_OFFSET already defined
#endif
/** \brief Offset of DTC severity in 1st element of event desc */
#define DEM_DTCSEVERITY_OFFSET            26U

#if (DEM_MAX_NUMBER_PRESTORED_FF > 0U)
#if (defined DEM_ENABLEPRESTORAGE_OFFSET)
#error DEM_ENABLEPRESTORAGE_OFFSET already defined
#endif
/** \brief Offset of Prestorage status in 1st element of event desc */
#define DEM_ENABLEPRESTORAGE_OFFSET            1U
#endif

#if (defined DEM_EVENTKIND_OFFSET)
#error DEM_EVENTKIND_OFFSET already defined
#endif
/** \brief Offset of Event kind in 1st element of event desc */
#define DEM_EVENTKIND_OFFSET            0U

#if (DEM_NUM_INDICATOR_LINKS > 0U)
#if (defined DEM_INDICATORUSED_OFFSET)
#error DEM_INDICATORUSED_OFFSET already defined
#endif
/** \brief Offset of indicator used status in 1st element of event desc */
#define DEM_INDICATORUSED_OFFSET            1U
#endif

#if (defined DEM_IMMEDIATESTORAGE_OFFSET)
#error DEM_IMMEDIATESTORAGE_OFFSET already defined
#endif
/** \brief Offset of Immediate storage status in 1st element of event desc */
#define DEM_IMMEDIATESTORAGE_OFFSET            28U

#if (defined DEM_UDS_DTC_WIDTH)
#error DEM_UDS_DTC_WIDTH already defined
#endif
/** \brief Number of bits to hold the value of DTC */
#define DEM_UDS_DTC_WIDTH              24U

#if (defined DEM_DTCORIGIN_WIDTH)
#error DEM_DTCORIGIN_WIDTH already defined
#endif
/** \brief Number of bits to hold the value of DTC origin */
#define DEM_DTCORIGIN_WIDTH            2U

#if (defined DEM_DTCGROUP_WIDTH)
#error DEM_DTCGROUP_WIDTH already defined
#endif
/** \brief Number of bits to hold the value of DTC group */
#define DEM_DTCGROUP_WIDTH             5U

#if (defined DEM_DTCGROUP_OFFSET)
#error DEM_DTCGROUP_OFFSET already defined
#endif
#define DEM_DTCGROUP_OFFSET            15U

#if (defined DEM_DTCCONFIDX_WIDTH)
#error DEM_DTCCONFIDX_WIDTH already defined
#endif
#define DEM_DTCCONFIDX_WIDTH           8U

#if (defined DEM_DTCCONFIDX_OFFSET)
#error DEM_DTCCONFIDX_OFFSET already defined
#endif
#define DEM_DTCCONFIDX_OFFSET          17U

#if (defined DEM_IMMEDIATESTORAGE_WIDTH)
#error DEM_IMMEDIATESTORAGE_WIDTH already defined
#endif
/** \brief Number of bits to hold the status of Immediate storage */
#define DEM_IMMEDIATESTORAGE_WIDTH     1U

#if (defined DEM_DTCSEVERITY_WIDTH)
#error DEM_DTCSEVERITY_WIDTH already defined
#endif
/** \brief Number of bits to hold the value of DTC severity */
#define DEM_DTCSEVERITY_WIDTH          2U

#if (DEM_MAX_NUMBER_PRESTORED_FF > 0U)
#if (defined DEM_ENABLEPRESTORAGE_WIDTH)
#error DEM_ENABLEPRESTORAGE_WIDTH already defined
#endif
/** \brief Number of bits to hold the status of Prestorage */
#define DEM_ENABLEPRESTORAGE_WIDTH     1U
#endif

#if (defined DEM_DEBOUNCEALGO_WIDTH)
#error DEM_DEBOUNCEALGO_WIDTH already defined
#endif
/** \brief Number of bits to hold the value of Debounce algorithm */
#define DEM_DEBOUNCEALGO_WIDTH         2U

#if (defined DEM_DEBOUNCEALGO_OFFSET)
#error DEM_DEBOUNCEALGO_OFFSET already defined
#endif
/** \brief Offset of Debounce algorithm in 3rd element of event desc */
#define DEM_DEBOUNCEALGO_OFFSET        2U

#if (defined DEM_EVENTSIGNIFICANCE_WIDTH)
#error DEM_EVENTSIGNIFICANCE_WIDTH already defined
#endif
/** \brief Number of bits to hold the value of Event Significance */
#define DEM_EVENTSIGNIFICANCE_WIDTH            1U

#if (defined DEM_EVENTSIGNIFICANCE_OFFSET)
#error DEM_EVENTSIGNIFICANCE_OFFSET already defined
#endif
/** \brief Number of bits to hold the value of Freeze frame class index */
#define DEM_EVENTSIGNIFICANCE_OFFSET            20U

#if (defined DEM_FFCLASSIDX_WIDTH)
#error DEM_FFCLASSIDX_WIDTH already defined
#endif
/** \brief  Offset of Event Significance in 2nd element of event desc */
#define DEM_FFCLASSIDX_WIDTH           2U

#if (defined DEM_FFCLASSIDX_OFFSET)
#error DEM_FFCLASSIDX_OFFSET already defined
#endif
/** \brief Offset of FF class index in 2nd element of event desc */
#define DEM_FFCLASSIDX_OFFSET          1U

#if (defined DEM_FFRECINFO_WIDTH)
#error DEM_FFRECINFO_WIDTH already defined
#endif
/** \brief Number of bits to hold the value of maximum number of freeze frames */
#define DEM_FFRECINFO_WIDTH            3U

#if (defined DEM_FFRECINFO_OFFSET)
#error DEM_FFRECINFO_OFFSET already defined
#endif
/** \brief Offset of maximum FF number (if record numeration type is calculated)
 ** or index to freeze frame record numeration class (if record numeration
 ** type is configured) in 2nd element of event desc
 */
#define DEM_FFRECINFO_OFFSET           3U

#if (defined DEM_EDCLASSIDX_WIDTH)
#error DEM_EDCLASSIDX_WIDTH already defined
#endif
/** \brief Number of bits to hold the value of Extended data class index */
#define DEM_EDCLASSIDX_WIDTH           1U

#if (defined DEM_EDCLASSIDX_OFFSET)
#error DEM_EDCLASSIDX_OFFSET already defined
#endif
/** \brief Offset of ED class index in 2nd element of event desc */
#define DEM_EDCLASSIDX_OFFSET          6U

#if (defined DEM_OPCYCLEIDX_WIDTH)
#error DEM_OPCYCLEIDX_WIDTH already defined
#endif
/** \brief Number of bits to hold the value of Operation cycle index */
#define DEM_OPCYCLEIDX_WIDTH           2U

#if (defined DEM_OPCYCLEIDX_OFFSET)
#error DEM_OPCYCLEIDX_OFFSET already defined
#endif
/** \brief Offset of Operation cycle index in 2nd element of event desc */
#define DEM_OPCYCLEIDX_OFFSET          15U

#if (defined DEM_AGINGCTRTHRESHOLD_WIDTH)
#error DEM_AGINGCTRTHRESHOLD_WIDTH already defined
#endif
/** \brief Number of bits to hold the value of number of Aging cycles */
#define DEM_AGINGCTRTHRESHOLD_WIDTH          6U

#if (defined DEM_AGINGCTRTHRESHOLD_OFFSET)
#error DEM_AGINGCTRTHRESHOLD_OFFSET already defined
#endif
/** \brief Offset of Aging cycle in 2nd element of event desc */
#define DEM_AGINGCTRTHRESHOLD_OFFSET         8U

/* Configurational value width in bits used for Dem_EventDescType */

#if (defined DEM_EVENTCLASSDESCIDX_WIDTH)
#error DEM_EVENTCLASSDESCIDX_WIDTH already defined
#endif
/** \brief Number of bits to hold the value of event class index */
#define DEM_EVENTCLASSDESCIDX_WIDTH    0U


#if (defined DEM_EVENTKIND_WIDTH)
#error DEM_EVENTKIND_WIDTH already defined
#endif
/** \brief Number of bits to hold the value of Event kind */
#define DEM_EVENTKIND_WIDTH            1U

#if (defined DEM_EVENTFAILURECLASSIDX_WIDTH)
#error DEM_EVENTFAILURECLASSIDX_WIDTH already defined
#endif
/** \brief Number of bits to hold the value of Event failure class index */
#define DEM_EVENTFAILURECLASSIDX_WIDTH 1U

#if (defined DEM_EVENTFAILURECLASSIDX_OFFSET)
#error DEM_EVENTFAILURECLASSIDX_OFFSET already defined
#endif
/** \brief Offset of Event failure class index in 3rd element of event desc */
#define DEM_EVENTFAILURECLASSIDX_OFFSET  14U

#if (defined DEM_ENCONDGRPIDX_WIDTH)
#error DEM_ENCONDGRPIDX_WIDTH already defined
#endif
/** \brief Number of bits to hold the value of Enable condition group index */
#define DEM_ENCONDGRPIDX_WIDTH            3U

#if (defined DEM_ENCONDGRPIDX_OFFSET)
#error DEM_ENCONDGRPIDX_OFFSET already defined
#endif
/** \brief Offset of Enable condition group index in 3rd element of event desc */
#define DEM_ENCONDGRPIDX_OFFSET           11U


#if (DEM_NUM_INDICATOR_LINKS > 0U)
#if (defined DEM_INDICATORUSED_WIDTH)
#error DEM_INDICATORUSED_WIDTH already defined
#endif
/** \brief Number of bits to hold the status of Indicators */
#define DEM_INDICATORUSED_WIDTH        1U
#endif

#if (defined DEM_PRIORITY_WIDTH)
#error DEM_PRIORITY_WIDTH already defined
#endif
/** \brief Number of bits to hold the value of Internal priority */
#define DEM_PRIORITY_WIDTH             1U

#if (defined DEM_PRIORITY_OFFSET)
#error DEM_PRIORITY_OFFSET already defined
#endif
/** \brief Offset of Internal priority in 3rd element of event desc */
#define DEM_PRIORITY_OFFSET            0U

#if (defined DEM_DEBOUNCEIDX_WIDTH)
#error DEM_DEBOUNCEIDX_WIDTH already defined
#endif
/** \brief Number of bits to hold the value of Debounce index */
#define DEM_DEBOUNCEIDX_WIDTH          7U

#if (defined DEM_DEBOUNCEIDX_OFFSET)
#error DEM_DEBOUNCEIDX_OFFSET already defined
#endif
/** \brief Offset of Debounce algorithm index in 3rd element of event desc */
#define DEM_DEBOUNCEIDX_OFFSET         4U

#if (defined DEM_DTCFUNCTIONALUNIT_WIDTH)
#error DEM_DTCFUNCTIONALUNIT_WIDTH already defined
#endif
/** \brief Number of bits to hold the value of DTC functional unit */
#define DEM_DTCFUNCTIONALUNIT_WIDTH    1U

#if (defined DEM_DTCFUNCTIONALUNIT_OFFSET)
#error DEM_DTCFUNCTIONALUNIT_OFFSET already defined
#endif
/** \brief Offset of DTC functional unit in 3rd element of event desc */
#define DEM_DTCFUNCTIONALUNIT_OFFSET   14

#if (defined DEM_AGINGCYCLEIDX_WIDTH)
#error DEM_AGINGCYCLEIDX_WIDTH already defined
#endif
/** \brief Number of bits to hold the value of relative Aging cycle index
 *
 * The invalid value :: DEM_NUM_AGINGCYCLES is also included in the width. */
#define DEM_AGINGCYCLEIDX_WIDTH        1U

#if (defined DEM_AGINGCYCLEIDX_OFFSET)
#error DEM_AGINGCYCLEIDX_OFFSET already defined
#endif
/** \brief Offset of Aging cycle index in 3rd element of event desc */
#define DEM_AGINGCYCLEIDX_OFFSET       7U

/*----------------------[OBD configuration offsets]-------------------------*/


/*------------------[Warning indicators configuration]----------------------*/

#if (defined DEM_NUM_HEALINGCYC_COUNTER_INFO_ELEMENTS)
#error DEM_NUM_HEALINGCYC_COUNTER_INFO_ELEMENTS already defined
#endif
/** \brief Number of healing cycle-counter information elements */
#define DEM_NUM_HEALINGCYC_COUNTER_INFO_ELEMENTS 0

#if (defined DEM_NUM_FAILURECYC_COUNTER_INFO_ELEMENTS)
#error DEM_NUM_FAILURECYC_COUNTER_INFO_ELEMENTS already defined
#endif
/** \brief Number of failure cycle-counter information elements */
#define DEM_NUM_FAILURECYC_COUNTER_INFO_ELEMENTS 0

/*------------------[Enable conditions configuration]-----------------------*/

#if (defined DEM_NUM_ENCONDGROUPS)
#error DEM_NUM_ENCONDGROUPS already defined
#endif
/** \brief Number of enable condition groups, used for further calculation */
#define DEM_NUM_ENCONDGROUPS   4U

#if (defined DEM_NUM_ENCONDGRP_SINGLEREF)
#error DEM_NUM_ENCONDGRP_SINGLEREF already defined
#endif
                                                                                                      /** \brief This macro specifies the number of enable conditions referred by condition groups.
 **
 **        The value is determined in the following way: first a verification is made for the
 **        enable condition in order to checked whether it has been referenced already by a
 **        condition group or not. If the enable condition has not been referenced by a condition
 **        group then the number of enable conditions referred by condition groups is incremented
 **        by 1U. In this way it is ensured that multiple references to one enable condition
 **        is counted once.
 */
#define DEM_NUM_ENCONDGRP_SINGLEREF   6U

#if (defined DEM_NUM_ENCONDGRP_LINKS)
#error DEM_NUM_ENCONDGRP_LINKS already defined
#endif
/** \brief Number of links to the dedicated enable condition group counters */
#define DEM_NUM_ENCONDGRP_LINKS   9U

/*------------------[Debouncing configuration]------------------------------*/

#if (defined DEM_NUM_DEBOUNCE_COUNTER_CLASSES)
#error DEM_NUM_DEBOUNCE_COUNTER_CLASSES already defined
#endif




/** \brief Number of counter based debounce classes */
#define DEM_NUM_DEBOUNCE_COUNTER_CLASSES   15U

#if (defined DEM_NUM_DEBOUNCE_COUNTER)
#error DEM_NUM_DEBOUNCE_COUNTER already defined
#endif
/** \brief Number of counter based debounced events */
#define DEM_NUM_DEBOUNCE_COUNTER   94U

#if (defined DEM_NUM_DEBOUNCE_TIME)
#error DEM_NUM_DEBOUNCE_TIME already defined
#endif
/** \brief Number of Time based debounced events */
#define DEM_NUM_DEBOUNCE_TIME      0U

#if (defined DEM_NUM_DEBOUNCE_TIME_CLASSES)
#error DEM_NUM_DEBOUNCE_TIME_CLASSES already defined
#endif

	


/** \brief Number of Time based debounce classes */
/* !LINKSTO Dem.Calibration.DemTimeBasedDebounceClassConcept,1 */
#define DEM_NUM_DEBOUNCE_TIME_CLASSES   0U

#if (defined DEM_NUM_DEBOUNCE_FREQUENCY)
#error DEM_NUM_DEBOUNCE_FREQUENCY already defined
#endif
/** \brief Number of counter based debounced events */
#define DEM_NUM_DEBOUNCE_FREQUENCY 0U

/*------------------[Fault confirmation configuration]----------------------*/

#if (defined DEM_NO_FAULT_CONFIRMATION)
#error DEM_NO_FAULT_CONFIRMATION already defined
#endif
/** \brief Symbolic name for failure class index if default configuration is used */
#define DEM_NO_FAULT_CONFIRMATION 0U

/*------------------[Immediate storage configuration]-----------------------*/

#if (defined DEM_STORAGEWAITNVMREADY)
#error DEM_STORAGEWAITNVMREADY already defined
#endif
/** \brief Macro for generic invocation of user-defined name of the Memory stack main function triggering callout function */
#define DEM_STORAGEWAITNVMREADY(BlockId) Appl_TriggerMemoryStack(BlockId);

/*------------------[Dynamic DTC configuration]-----------------------------*/


/*------------------[J1939 Freeze frame definitions]--------------*/

#if (defined DEM_J1939FFCLS_NULL_IDX)
#error DEM_J1939FFCLS_NULL_IDX already defined
#endif
/** \brief Symbolic name of J1939 freeze frame class null index */
#define DEM_J1939FFCLS_NULL_IDX                             0U

#if (defined DEM_NUM_J1939FFCLS)
#error DEM_NUM_J1939FFCLS already defined
#endif
/** \brief Number of different J1939 freeze frame classes */
#define DEM_NUM_J1939FFCLS 1U

#if (defined DEM_NUM_J1939FFSPNS)
#error DEM_NUM_J1939FFSPNS already defined
#endif
/** \brief Number of different J1939 freeze frame SPNs */
#define DEM_NUM_J1939FFSPNS 0U

/*----------------------------[J1939 Det]-------------------------*/

/*------------------[Dem BSW distribution macros]---------------------------------*/

#if (defined DEM_MASTER_INSTANCE)
#error DEM_MASTER_INSTANCE already defined
#endif
/** \brief Macro defining the core configured as master core */
#define DEM_MASTER_INSTANCE 0U

#if (defined DEM_NUMBER_OF_CORES)
#error DEM_NUMBER_OF_CORES already defined
#endif
/** \brief Dem number of cores */
#define DEM_NUMBER_OF_CORES 1U


/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

/*==================[internal function definitions]=========================*/

#endif /* ifndef DEM_INT_CFG_H */
/*==================[end of file]===========================================*/
