/**
 * \file
 *
 * \brief AUTOSAR MemMap
 *
 * This file contains the implementation of the AUTOSAR
 * module MemMap.
 *
 * \version 1.3.10
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2021 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

/*==================[inclusions]=============================================*/

#define MEMMAP_ERROR_XCP

/*------------------[Start of a module]--------------------------------------*/

/* Memory section macros for Xcp */

#if (defined XCP_START_SEC_APPL_CODE)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_XCP
    #error Tried to open section XCP_START_SEC_APPL_CODE within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_APPL_CODE
    #undef XCP_START_SEC_APPL_CODE
    #undef MEMMAP_ERROR_XCP
  #endif
#elif (defined XCP_STOP_SEC_APPL_CODE)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_APPL_CODE)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_APPL_CODE
    #undef XCP_STOP_SEC_APPL_CODE
    #undef MEMMAP_ERROR_XCP
  #else
    #undef MEMMAP_ERROR_XCP
    #error Tried to close section XCP_STOP_SEC_APPL_CODE without prior opening XCP_START_SEC_APPL_CODE.
  #endif

#elif (defined XCP_START_SEC_CODE)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_XCP
    #error Tried to open section XCP_START_SEC_CODE within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CODE
    #undef XCP_START_SEC_CODE
    #undef MEMMAP_ERROR_XCP
  #endif
#elif (defined XCP_STOP_SEC_CODE)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CODE)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CODE
    #undef XCP_STOP_SEC_CODE
    #undef MEMMAP_ERROR_XCP
  #else
    #undef MEMMAP_ERROR_XCP
    #error Tried to close section XCP_STOP_SEC_CODE without prior opening XCP_START_SEC_CODE.
  #endif

#elif (defined XCP_START_SEC_CONST_16)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_XCP
    #error Tried to open section XCP_START_SEC_CONST_16 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CONST_16
    #undef XCP_START_SEC_CONST_16
    #undef MEMMAP_ERROR_XCP
  #endif
#elif (defined XCP_STOP_SEC_CONST_16)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CONST_16)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CONST_16
    #undef XCP_STOP_SEC_CONST_16
    #undef MEMMAP_ERROR_XCP
  #else
    #undef MEMMAP_ERROR_XCP
    #error Tried to close section XCP_STOP_SEC_CONST_16 without prior opening XCP_START_SEC_CONST_16.
  #endif

#elif (defined XCP_START_SEC_CONST_8)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_XCP
    #error Tried to open section XCP_START_SEC_CONST_8 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CONST_8
    #undef XCP_START_SEC_CONST_8
    #undef MEMMAP_ERROR_XCP
  #endif
#elif (defined XCP_STOP_SEC_CONST_8)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CONST_8)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CONST_8
    #undef XCP_STOP_SEC_CONST_8
    #undef MEMMAP_ERROR_XCP
  #else
    #undef MEMMAP_ERROR_XCP
    #error Tried to close section XCP_STOP_SEC_CONST_8 without prior opening XCP_START_SEC_CONST_8.
  #endif

#elif (defined XCP_START_SEC_CONST_UNSPECIFIED)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_XCP
    #error Tried to open section XCP_START_SEC_CONST_UNSPECIFIED within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CONST_UNSPECIFIED
    #undef XCP_START_SEC_CONST_UNSPECIFIED
    #undef MEMMAP_ERROR_XCP
  #endif
#elif (defined XCP_STOP_SEC_CONST_UNSPECIFIED)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CONST_UNSPECIFIED)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CONST_UNSPECIFIED
    #undef XCP_STOP_SEC_CONST_UNSPECIFIED
    #undef MEMMAP_ERROR_XCP
  #else
    #undef MEMMAP_ERROR_XCP
    #error Tried to close section XCP_STOP_SEC_CONST_UNSPECIFIED without prior opening XCP_START_SEC_CONST_UNSPECIFIED.
  #endif

#elif (defined XCP_START_SEC_VAR_16)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_XCP
    #error Tried to open section XCP_START_SEC_VAR_16 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_16
    #undef XCP_START_SEC_VAR_16
    #undef MEMMAP_ERROR_XCP
  #endif
#elif (defined XCP_STOP_SEC_VAR_16)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_16)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_16
    #undef XCP_STOP_SEC_VAR_16
    #undef MEMMAP_ERROR_XCP
  #else
    #undef MEMMAP_ERROR_XCP
    #error Tried to close section XCP_STOP_SEC_VAR_16 without prior opening XCP_START_SEC_VAR_16.
  #endif

#elif (defined XCP_START_SEC_VAR_8)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_XCP
    #error Tried to open section XCP_START_SEC_VAR_8 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_8
    #undef XCP_START_SEC_VAR_8
    #undef MEMMAP_ERROR_XCP
  #endif
#elif (defined XCP_STOP_SEC_VAR_8)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_8)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_8
    #undef XCP_STOP_SEC_VAR_8
    #undef MEMMAP_ERROR_XCP
  #else
    #undef MEMMAP_ERROR_XCP
    #error Tried to close section XCP_STOP_SEC_VAR_8 without prior opening XCP_START_SEC_VAR_8.
  #endif

#elif (defined XCP_START_SEC_VAR_CLEARED_16)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_XCP
    #error Tried to open section XCP_START_SEC_VAR_CLEARED_16 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_16
    #undef XCP_START_SEC_VAR_CLEARED_16
    #undef MEMMAP_ERROR_XCP
  #endif
#elif (defined XCP_STOP_SEC_VAR_CLEARED_16)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_16)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_16
    #undef XCP_STOP_SEC_VAR_CLEARED_16
    #undef MEMMAP_ERROR_XCP
  #else
    #undef MEMMAP_ERROR_XCP
    #error Tried to close section XCP_STOP_SEC_VAR_CLEARED_16 without prior opening XCP_START_SEC_VAR_CLEARED_16.
  #endif

#elif (defined XCP_START_SEC_VAR_CLEARED_8)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_XCP
    #error Tried to open section XCP_START_SEC_VAR_CLEARED_8 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_8
    #undef XCP_START_SEC_VAR_CLEARED_8
    #undef MEMMAP_ERROR_XCP
  #endif
#elif (defined XCP_STOP_SEC_VAR_CLEARED_8)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_8)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_8
    #undef XCP_STOP_SEC_VAR_CLEARED_8
    #undef MEMMAP_ERROR_XCP
  #else
    #undef MEMMAP_ERROR_XCP
    #error Tried to close section XCP_STOP_SEC_VAR_CLEARED_8 without prior opening XCP_START_SEC_VAR_CLEARED_8.
  #endif

#elif (defined XCP_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_XCP
    #error Tried to open section XCP_START_SEC_VAR_CLEARED_UNSPECIFIED within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_UNSPECIFIED
    #undef XCP_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef MEMMAP_ERROR_XCP
  #endif
#elif (defined XCP_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_UNSPECIFIED)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_UNSPECIFIED
    #undef XCP_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef MEMMAP_ERROR_XCP
  #else
    #undef MEMMAP_ERROR_XCP
    #error Tried to close section XCP_STOP_SEC_VAR_CLEARED_UNSPECIFIED without prior opening XCP_START_SEC_VAR_CLEARED_UNSPECIFIED.
  #endif

#elif (defined XCP_START_SEC_VAR_CONTROL_API_8)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_XCP
    #error Tried to open section XCP_START_SEC_VAR_CONTROL_API_8 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_CONTROL_API_8
    #undef XCP_START_SEC_VAR_CONTROL_API_8
    #undef MEMMAP_ERROR_XCP
  #endif
#elif (defined XCP_STOP_SEC_VAR_CONTROL_API_8)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_CONTROL_API_8)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_CONTROL_API_8
    #undef XCP_STOP_SEC_VAR_CONTROL_API_8
    #undef MEMMAP_ERROR_XCP
  #else
    #undef MEMMAP_ERROR_XCP
    #error Tried to close section XCP_STOP_SEC_VAR_CONTROL_API_8 without prior opening XCP_START_SEC_VAR_CONTROL_API_8.
  #endif

#elif (defined XCP_START_SEC_VAR_SAVED_ZONE_UNSPECIFIED)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_XCP
    #error Tried to open section XCP_START_SEC_VAR_SAVED_ZONE_UNSPECIFIED within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_SAVED_ZONE_UNSPECIFIED
    #undef XCP_START_SEC_VAR_SAVED_ZONE_UNSPECIFIED
    #undef MEMMAP_ERROR_XCP
  #endif
#elif (defined XCP_STOP_SEC_VAR_SAVED_ZONE_UNSPECIFIED)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_SAVED_ZONE_UNSPECIFIED)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_SAVED_ZONE_UNSPECIFIED
    #undef XCP_STOP_SEC_VAR_SAVED_ZONE_UNSPECIFIED
    #undef MEMMAP_ERROR_XCP
  #else
    #undef MEMMAP_ERROR_XCP
    #error Tried to close section XCP_STOP_SEC_VAR_SAVED_ZONE_UNSPECIFIED without prior opening XCP_START_SEC_VAR_SAVED_ZONE_UNSPECIFIED.
  #endif

#elif (defined XCP_START_SEC_VAR_SAVED_ZONE_UNSPECIFIED_8)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_XCP
    #error Tried to open section XCP_START_SEC_VAR_SAVED_ZONE_UNSPECIFIED_8 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_SAVED_ZONE_UNSPECIFIED_8
    #undef XCP_START_SEC_VAR_SAVED_ZONE_UNSPECIFIED_8
    #undef MEMMAP_ERROR_XCP
  #endif
#elif (defined XCP_STOP_SEC_VAR_SAVED_ZONE_UNSPECIFIED_8)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_SAVED_ZONE_UNSPECIFIED_8)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_SAVED_ZONE_UNSPECIFIED_8
    #undef XCP_STOP_SEC_VAR_SAVED_ZONE_UNSPECIFIED_8
    #undef MEMMAP_ERROR_XCP
  #else
    #undef MEMMAP_ERROR_XCP
    #error Tried to close section XCP_STOP_SEC_VAR_SAVED_ZONE_UNSPECIFIED_8 without prior opening XCP_START_SEC_VAR_SAVED_ZONE_UNSPECIFIED_8.
  #endif

#elif (defined XCP_START_SEC_VAR_UNSPECIFIED)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_XCP
    #error Tried to open section XCP_START_SEC_VAR_UNSPECIFIED within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_UNSPECIFIED
    #undef XCP_START_SEC_VAR_UNSPECIFIED
    #undef MEMMAP_ERROR_XCP
  #endif
#elif (defined XCP_STOP_SEC_VAR_UNSPECIFIED)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_UNSPECIFIED)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_UNSPECIFIED
    #undef XCP_STOP_SEC_VAR_UNSPECIFIED
    #undef MEMMAP_ERROR_XCP
  #else
    #undef MEMMAP_ERROR_XCP
    #error Tried to close section XCP_STOP_SEC_VAR_UNSPECIFIED without prior opening XCP_START_SEC_VAR_UNSPECIFIED.
  #endif

#elif (defined XCP_WRAPPER_START_SEC_WRAPPER_CODE)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_XCP
    #error Tried to open section XCP_WRAPPER_START_SEC_WRAPPER_CODE within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_WRAPPER_CODE
    #undef XCP_WRAPPER_START_SEC_WRAPPER_CODE
    #undef MEMMAP_ERROR_XCP
  #endif
#elif (defined XCP_WRAPPER_STOP_SEC_WRAPPER_CODE)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_WRAPPER_CODE)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_WRAPPER_CODE
    #undef XCP_WRAPPER_STOP_SEC_WRAPPER_CODE
    #undef MEMMAP_ERROR_XCP
  #else
    #undef MEMMAP_ERROR_XCP
    #error Tried to close section XCP_WRAPPER_STOP_SEC_WRAPPER_CODE without prior opening XCP_WRAPPER_START_SEC_WRAPPER_CODE.
  #endif

#endif

#if ((!defined MEMMAP_ERROR_XCP) && (defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR
#elif ((defined MEMMAP_ERROR_XCP) && (!defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR_XCP
  #error MEMMAP_ERROR_XCP the included memory section was not defined within the BSW-IMPLEMENTATION of Xcp.
#endif
