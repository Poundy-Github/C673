/**
 * \file
 *
 * \brief AUTOSAR MemMap
 *
 * This file contains the implementation of the AUTOSAR
 * module MemMap.
 *
 * \version 1.3.6
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2020 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

/*==================[inclusions]=============================================*/

#define MEMMAP_ERROR_CANTRCV_TJA1043

/*------------------[Start of a module]--------------------------------------*/

/* Memory section macros for CANTRCV_TJA1043 */

#if (defined CANTRCV_TJA1043_START_SEC_CODE)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_CANTRCV_TJA1043
    #error Tried to open section CANTRCV_TJA1043_START_SEC_CODE within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CODE
    #undef CANTRCV_TJA1043_START_SEC_CODE
    #undef MEMMAP_ERROR_CANTRCV_TJA1043
  #endif
#elif (defined CANTRCV_TJA1043_STOP_SEC_CODE)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CODE)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CODE
    #undef CANTRCV_TJA1043_STOP_SEC_CODE
    #undef MEMMAP_ERROR_CANTRCV_TJA1043
  #else
    #undef MEMMAP_ERROR_CANTRCV_TJA1043
    #error Tried to close section CANTRCV_TJA1043_STOP_SEC_CODE without prior opening CANTRCV_TJA1043_START_SEC_CODE.
  #endif

#elif (defined CANTRCV_TJA1043_START_SEC_CONFIG_DATA_UNSPECIFIED)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_CANTRCV_TJA1043
    #error Tried to open section CANTRCV_TJA1043_START_SEC_CONFIG_DATA_UNSPECIFIED within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CONFIG_DATA_UNSPECIFIED
    #undef CANTRCV_TJA1043_START_SEC_CONFIG_DATA_UNSPECIFIED
    #undef MEMMAP_ERROR_CANTRCV_TJA1043
  #endif
#elif (defined CANTRCV_TJA1043_STOP_SEC_CONFIG_DATA_UNSPECIFIED)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CONFIG_DATA_UNSPECIFIED)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CONFIG_DATA_UNSPECIFIED
    #undef CANTRCV_TJA1043_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    #undef MEMMAP_ERROR_CANTRCV_TJA1043
  #else
    #undef MEMMAP_ERROR_CANTRCV_TJA1043
    #error Tried to close section CANTRCV_TJA1043_STOP_SEC_CONFIG_DATA_UNSPECIFIED without prior opening CANTRCV_TJA1043_START_SEC_CONFIG_DATA_UNSPECIFIED.
  #endif

#elif (defined CANTRCV_TJA1043_START_CONFIG_DATA_UNSPECIFIED)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_CANTRCV_TJA1043
    #error Tried to open section CANTRCV_TJA1043_START_CONFIG_DATA_UNSPECIFIED within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTCONFIG_DATA_UNSPECIFIED
    #undef CANTRCV_TJA1043_START_CONFIG_DATA_UNSPECIFIED
    #undef MEMMAP_ERROR_CANTRCV_TJA1043
  #endif
#elif (defined CANTRCV_TJA1043_STOP_CONFIG_DATA_UNSPECIFIED)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTCONFIG_DATA_UNSPECIFIED)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTCONFIG_DATA_UNSPECIFIED
    #undef CANTRCV_TJA1043_STOP_CONFIG_DATA_UNSPECIFIED
    #undef MEMMAP_ERROR_CANTRCV_TJA1043
  #else
    #undef MEMMAP_ERROR_CANTRCV_TJA1043
    #error Tried to close section CANTRCV_TJA1043_STOP_CONFIG_DATA_UNSPECIFIED without prior opening CANTRCV_TJA1043_START_CONFIG_DATA_UNSPECIFIED.
  #endif

#elif (defined CANTRCV_TJA1043_START_SEC_CONST_32BIT)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_CANTRCV_TJA1043
    #error Tried to open section CANTRCV_TJA1043_START_SEC_CONST_32BIT within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CONST_32
    #undef CANTRCV_TJA1043_START_SEC_CONST_32BIT
    #undef MEMMAP_ERROR_CANTRCV_TJA1043
  #endif
#elif (defined CANTRCV_TJA1043_STOP_SEC_CONST_32BIT)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CONST_32)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CONST_32
    #undef CANTRCV_TJA1043_STOP_SEC_CONST_32BIT
    #undef MEMMAP_ERROR_CANTRCV_TJA1043
  #else
    #undef MEMMAP_ERROR_CANTRCV_TJA1043
    #error Tried to close section CANTRCV_TJA1043_STOP_SEC_CONST_32BIT without prior opening CANTRCV_TJA1043_START_SEC_CONST_32BIT.
  #endif

#elif (defined CANTRCV_TJA1043_START_SEC_CONST_8BIT)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_CANTRCV_TJA1043
    #error Tried to open section CANTRCV_TJA1043_START_SEC_CONST_8BIT within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CONST_8
    #undef CANTRCV_TJA1043_START_SEC_CONST_8BIT
    #undef MEMMAP_ERROR_CANTRCV_TJA1043
  #endif
#elif (defined CANTRCV_TJA1043_STOP_SEC_CONST_8BIT)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CONST_8)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CONST_8
    #undef CANTRCV_TJA1043_STOP_SEC_CONST_8BIT
    #undef MEMMAP_ERROR_CANTRCV_TJA1043
  #else
    #undef MEMMAP_ERROR_CANTRCV_TJA1043
    #error Tried to close section CANTRCV_TJA1043_STOP_SEC_CONST_8BIT without prior opening CANTRCV_TJA1043_START_SEC_CONST_8BIT.
  #endif

#elif (defined CANTRCV_TJA1043_START_SEC_CONST_UNSPECIFIED)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_CANTRCV_TJA1043
    #error Tried to open section CANTRCV_TJA1043_START_SEC_CONST_UNSPECIFIED within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CONST_UNSPECIFIED
    #undef CANTRCV_TJA1043_START_SEC_CONST_UNSPECIFIED
    #undef MEMMAP_ERROR_CANTRCV_TJA1043
  #endif
#elif (defined CANTRCV_TJA1043_STOP_SEC_CONST_UNSPECIFIED)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CONST_UNSPECIFIED)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CONST_UNSPECIFIED
    #undef CANTRCV_TJA1043_STOP_SEC_CONST_UNSPECIFIED
    #undef MEMMAP_ERROR_CANTRCV_TJA1043
  #else
    #undef MEMMAP_ERROR_CANTRCV_TJA1043
    #error Tried to close section CANTRCV_TJA1043_STOP_SEC_CONST_UNSPECIFIED without prior opening CANTRCV_TJA1043_START_SEC_CONST_UNSPECIFIED.
  #endif

#elif (defined CANTRCV_TJA1043_START_SEC_VAR_CLEARED_16)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_CANTRCV_TJA1043
    #error Tried to open section CANTRCV_TJA1043_START_SEC_VAR_CLEARED_16 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_16
    #undef CANTRCV_TJA1043_START_SEC_VAR_CLEARED_16
    #undef MEMMAP_ERROR_CANTRCV_TJA1043
  #endif
#elif (defined CANTRCV_TJA1043_STOP_SEC_VAR_CLEARED_16)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_16)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_16
    #undef CANTRCV_TJA1043_STOP_SEC_VAR_CLEARED_16
    #undef MEMMAP_ERROR_CANTRCV_TJA1043
  #else
    #undef MEMMAP_ERROR_CANTRCV_TJA1043
    #error Tried to close section CANTRCV_TJA1043_STOP_SEC_VAR_CLEARED_16 without prior opening CANTRCV_TJA1043_START_SEC_VAR_CLEARED_16.
  #endif

#elif (defined CANTRCV_TJA1043_START_SEC_VAR_CLEARED_32)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_CANTRCV_TJA1043
    #error Tried to open section CANTRCV_TJA1043_START_SEC_VAR_CLEARED_32 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_32
    #undef CANTRCV_TJA1043_START_SEC_VAR_CLEARED_32
    #undef MEMMAP_ERROR_CANTRCV_TJA1043
  #endif
#elif (defined CANTRCV_TJA1043_STOP_SEC_VAR_CLEARED_32)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_32)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_32
    #undef CANTRCV_TJA1043_STOP_SEC_VAR_CLEARED_32
    #undef MEMMAP_ERROR_CANTRCV_TJA1043
  #else
    #undef MEMMAP_ERROR_CANTRCV_TJA1043
    #error Tried to close section CANTRCV_TJA1043_STOP_SEC_VAR_CLEARED_32 without prior opening CANTRCV_TJA1043_START_SEC_VAR_CLEARED_32.
  #endif

#elif (defined CANTRCV_TJA1043_START_SEC_VAR_CLEARED_8)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_CANTRCV_TJA1043
    #error Tried to open section CANTRCV_TJA1043_START_SEC_VAR_CLEARED_8 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_8
    #undef CANTRCV_TJA1043_START_SEC_VAR_CLEARED_8
    #undef MEMMAP_ERROR_CANTRCV_TJA1043
  #endif
#elif (defined CANTRCV_TJA1043_STOP_SEC_VAR_CLEARED_8)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_8)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_8
    #undef CANTRCV_TJA1043_STOP_SEC_VAR_CLEARED_8
    #undef MEMMAP_ERROR_CANTRCV_TJA1043
  #else
    #undef MEMMAP_ERROR_CANTRCV_TJA1043
    #error Tried to close section CANTRCV_TJA1043_STOP_SEC_VAR_CLEARED_8 without prior opening CANTRCV_TJA1043_START_SEC_VAR_CLEARED_8.
  #endif

#elif (defined CANTRCV_TJA1043_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_CANTRCV_TJA1043
    #error Tried to open section CANTRCV_TJA1043_START_SEC_VAR_CLEARED_UNSPECIFIED within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_UNSPECIFIED
    #undef CANTRCV_TJA1043_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef MEMMAP_ERROR_CANTRCV_TJA1043
  #endif
#elif (defined CANTRCV_TJA1043_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_UNSPECIFIED)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_UNSPECIFIED
    #undef CANTRCV_TJA1043_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef MEMMAP_ERROR_CANTRCV_TJA1043
  #else
    #undef MEMMAP_ERROR_CANTRCV_TJA1043
    #error Tried to close section CANTRCV_TJA1043_STOP_SEC_VAR_CLEARED_UNSPECIFIED without prior opening CANTRCV_TJA1043_START_SEC_VAR_CLEARED_UNSPECIFIED.
  #endif

#elif (defined CANTRCV_TJA1043_START_SEC_VAR_FAST_INIT_UNSPECIFIED)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_CANTRCV_TJA1043
    #error Tried to open section CANTRCV_TJA1043_START_SEC_VAR_FAST_INIT_UNSPECIFIED within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_FAST_INIT_UNSPECIFIED
    #undef CANTRCV_TJA1043_START_SEC_VAR_FAST_INIT_UNSPECIFIED
    #undef MEMMAP_ERROR_CANTRCV_TJA1043
  #endif
#elif (defined CANTRCV_TJA1043_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_FAST_INIT_UNSPECIFIED)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_FAST_INIT_UNSPECIFIED
    #undef CANTRCV_TJA1043_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED
    #undef MEMMAP_ERROR_CANTRCV_TJA1043
  #else
    #undef MEMMAP_ERROR_CANTRCV_TJA1043
    #error Tried to close section CANTRCV_TJA1043_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED without prior opening CANTRCV_TJA1043_START_SEC_VAR_FAST_INIT_UNSPECIFIED.
  #endif

#elif (defined CANTRCV_TJA1043_START_SEC_VAR_INIT_8)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_CANTRCV_TJA1043
    #error Tried to open section CANTRCV_TJA1043_START_SEC_VAR_INIT_8 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_INIT_8
    #undef CANTRCV_TJA1043_START_SEC_VAR_INIT_8
    #undef MEMMAP_ERROR_CANTRCV_TJA1043
  #endif
#elif (defined CANTRCV_TJA1043_STOP_SEC_VAR_INIT_8)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_INIT_8)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_INIT_8
    #undef CANTRCV_TJA1043_STOP_SEC_VAR_INIT_8
    #undef MEMMAP_ERROR_CANTRCV_TJA1043
  #else
    #undef MEMMAP_ERROR_CANTRCV_TJA1043
    #error Tried to close section CANTRCV_TJA1043_STOP_SEC_VAR_INIT_8 without prior opening CANTRCV_TJA1043_START_SEC_VAR_INIT_8.
  #endif

#elif (defined CANTRCV_TJA1043_START_SEC_VAR_INIT_UNSPECIFIED)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_CANTRCV_TJA1043
    #error Tried to open section CANTRCV_TJA1043_START_SEC_VAR_INIT_UNSPECIFIED within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_INIT_UNSPECIFIED
    #undef CANTRCV_TJA1043_START_SEC_VAR_INIT_UNSPECIFIED
    #undef MEMMAP_ERROR_CANTRCV_TJA1043
  #endif
#elif (defined CANTRCV_TJA1043_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_INIT_UNSPECIFIED)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_INIT_UNSPECIFIED
    #undef CANTRCV_TJA1043_STOP_SEC_VAR_INIT_UNSPECIFIED
    #undef MEMMAP_ERROR_CANTRCV_TJA1043
  #else
    #undef MEMMAP_ERROR_CANTRCV_TJA1043
    #error Tried to close section CANTRCV_TJA1043_STOP_SEC_VAR_INIT_UNSPECIFIED without prior opening CANTRCV_TJA1043_START_SEC_VAR_INIT_UNSPECIFIED.
  #endif

#endif

#if 0
#if ((!defined MEMMAP_ERROR_CANTRCV_TJA1043) && (defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR
#elif ((defined MEMMAP_ERROR_CANTRCV_TJA1043) && (!defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR_CANTRCV_TJA1043
  #error MEMMAP_ERROR_CANTRCV_TJA1043 the included memory section was not defined within the BSW-IMPLEMENTATION of CANTRCV_TJA1043.
#endif
#endif