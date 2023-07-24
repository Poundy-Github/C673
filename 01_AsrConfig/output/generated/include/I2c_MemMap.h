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

#define MEMMAP_ERROR_I2C

/*------------------[Start of a module]--------------------------------------*/

/* Memory section macros for I2c */

#if (defined I2C_START_SEC_CODE_QM_LOCAL)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_I2C
    #error Tried to open section I2C_START_SEC_CODE_QM_LOCAL within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CODE_QM_LOCAL
    #undef I2C_START_SEC_CODE_QM_LOCAL
    #undef MEMMAP_ERROR_I2C
  #endif
#elif (defined I2C_STOP_SEC_CODE_QM_LOCAL)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CODE_QM_LOCAL)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CODE_QM_LOCAL
    #undef I2C_STOP_SEC_CODE_QM_LOCAL
    #undef MEMMAP_ERROR_I2C
  #else
    #undef MEMMAP_ERROR_I2C
    #error Tried to close section I2C_STOP_SEC_CODE_QM_LOCAL without prior opening I2C_START_SEC_CODE_QM_LOCAL.
  #endif

#elif (defined I2C_START_SEC_CONFIG_DATA_QM_LOCAL_UNSPECIFIED)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_I2C
    #error Tried to open section I2C_START_SEC_CONFIG_DATA_QM_LOCAL_UNSPECIFIED within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CONFIG_DATA_QM_LOCAL_UNSPECIFIED
    #undef I2C_START_SEC_CONFIG_DATA_QM_LOCAL_UNSPECIFIED
    #undef MEMMAP_ERROR_I2C
  #endif
#elif (defined I2C_STOP_SEC_CONFIG_DATA_QM_LOCAL_UNSPECIFIED)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CONFIG_DATA_QM_LOCAL_UNSPECIFIED)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CONFIG_DATA_QM_LOCAL_UNSPECIFIED
    #undef I2C_STOP_SEC_CONFIG_DATA_QM_LOCAL_UNSPECIFIED
    #undef MEMMAP_ERROR_I2C
  #else
    #undef MEMMAP_ERROR_I2C
    #error Tried to close section I2C_STOP_SEC_CONFIG_DATA_QM_LOCAL_UNSPECIFIED without prior opening I2C_START_SEC_CONFIG_DATA_QM_LOCAL_UNSPECIFIED.
  #endif

#elif (defined I2C_START_CONFIG_DATA_QM_LOCAL_UNSPECIFIED)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_I2C
    #error Tried to open section I2C_START_CONFIG_DATA_QM_LOCAL_UNSPECIFIED within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTCONFIG_DATA_QM_LOCAL_UNSPECIFIED
    #undef I2C_START_CONFIG_DATA_QM_LOCAL_UNSPECIFIED
    #undef MEMMAP_ERROR_I2C
  #endif
#elif (defined I2C_STOP_CONFIG_DATA_QM_LOCAL_UNSPECIFIED)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTCONFIG_DATA_QM_LOCAL_UNSPECIFIED)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTCONFIG_DATA_QM_LOCAL_UNSPECIFIED
    #undef I2C_STOP_CONFIG_DATA_QM_LOCAL_UNSPECIFIED
    #undef MEMMAP_ERROR_I2C
  #else
    #undef MEMMAP_ERROR_I2C
    #error Tried to close section I2C_STOP_CONFIG_DATA_QM_LOCAL_UNSPECIFIED without prior opening I2C_START_CONFIG_DATA_QM_LOCAL_UNSPECIFIED.
  #endif

#elif (defined I2C_START_SEC_CONST_QM_LOCAL_32)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_I2C
    #error Tried to open section I2C_START_SEC_CONST_QM_LOCAL_32 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CONST_QM_LOCAL_32
    #undef I2C_START_SEC_CONST_QM_LOCAL_32
    #undef MEMMAP_ERROR_I2C
  #endif
#elif (defined I2C_STOP_SEC_CONST_QM_LOCAL_32)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CONST_QM_LOCAL_32)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CONST_QM_LOCAL_32
    #undef I2C_STOP_SEC_CONST_QM_LOCAL_32
    #undef MEMMAP_ERROR_I2C
  #else
    #undef MEMMAP_ERROR_I2C
    #error Tried to close section I2C_STOP_SEC_CONST_QM_LOCAL_32 without prior opening I2C_START_SEC_CONST_QM_LOCAL_32.
  #endif

#elif (defined I2C_START_SEC_VAR_CLEARED_QM_LOCAL_32)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_I2C
    #error Tried to open section I2C_START_SEC_VAR_CLEARED_QM_LOCAL_32 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_QM_LOCAL_32
    #undef I2C_START_SEC_VAR_CLEARED_QM_LOCAL_32
    #undef MEMMAP_ERROR_I2C
  #endif
#elif (defined I2C_STOP_SEC_VAR_CLEARED_QM_LOCAL_32)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_QM_LOCAL_32)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_QM_LOCAL_32
    #undef I2C_STOP_SEC_VAR_CLEARED_QM_LOCAL_32
    #undef MEMMAP_ERROR_I2C
  #else
    #undef MEMMAP_ERROR_I2C
    #error Tried to close section I2C_STOP_SEC_VAR_CLEARED_QM_LOCAL_32 without prior opening I2C_START_SEC_VAR_CLEARED_QM_LOCAL_32.
  #endif

#elif (defined I2C_START_SEC_VAR_CLEARED_QM_LOCAL_8)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_I2C
    #error Tried to open section I2C_START_SEC_VAR_CLEARED_QM_LOCAL_8 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_QM_LOCAL_8
    #undef I2C_START_SEC_VAR_CLEARED_QM_LOCAL_8
    #undef MEMMAP_ERROR_I2C
  #endif
#elif (defined I2C_STOP_SEC_VAR_CLEARED_QM_LOCAL_8)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_QM_LOCAL_8)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_QM_LOCAL_8
    #undef I2C_STOP_SEC_VAR_CLEARED_QM_LOCAL_8
    #undef MEMMAP_ERROR_I2C
  #else
    #undef MEMMAP_ERROR_I2C
    #error Tried to close section I2C_STOP_SEC_VAR_CLEARED_QM_LOCAL_8 without prior opening I2C_START_SEC_VAR_CLEARED_QM_LOCAL_8.
  #endif

#elif (defined I2C_START_SEC_VAR_CLEARED_QM_LOCAL_UNSPECIFIED)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_I2C
    #error Tried to open section I2C_START_SEC_VAR_CLEARED_QM_LOCAL_UNSPECIFIED within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_QM_LOCAL_UNSPECIFIED
    #undef I2C_START_SEC_VAR_CLEARED_QM_LOCAL_UNSPECIFIED
    #undef MEMMAP_ERROR_I2C
  #endif
#elif (defined I2C_STOP_SEC_VAR_CLEARED_QM_LOCAL_UNSPECIFIED)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_QM_LOCAL_UNSPECIFIED)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_CLEARED_QM_LOCAL_UNSPECIFIED
    #undef I2C_STOP_SEC_VAR_CLEARED_QM_LOCAL_UNSPECIFIED
    #undef MEMMAP_ERROR_I2C
  #else
    #undef MEMMAP_ERROR_I2C
    #error Tried to close section I2C_STOP_SEC_VAR_CLEARED_QM_LOCAL_UNSPECIFIED without prior opening I2C_START_SEC_VAR_CLEARED_QM_LOCAL_UNSPECIFIED.
  #endif

#endif

#if ((!defined MEMMAP_ERROR_I2C) && (defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR
#elif ((defined MEMMAP_ERROR_I2C) && (!defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR_I2C
  #error MEMMAP_ERROR_I2C the included memory section was not defined within the BSW-IMPLEMENTATION of I2c.
#endif
