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

#define MEMMAP_ERROR_SMU

/*------------------[Start of a module]--------------------------------------*/

/* Memory section macros for Smu */

#if (defined SMU_START_SEC_CODE_ASIL_B_GLOBAL)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_SMU
    #error Tried to open section SMU_START_SEC_CODE_ASIL_B_GLOBAL within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CODE_ASIL_B_GLOBAL
    #undef SMU_START_SEC_CODE_ASIL_B_GLOBAL
    #undef MEMMAP_ERROR_SMU
  #endif
#elif (defined SMU_STOP_SEC_CODE_ASIL_B_GLOBAL)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CODE_ASIL_B_GLOBAL)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CODE_ASIL_B_GLOBAL
    #undef SMU_STOP_SEC_CODE_ASIL_B_GLOBAL
    #undef MEMMAP_ERROR_SMU
  #else
    #undef MEMMAP_ERROR_SMU
    #error Tried to close section SMU_STOP_SEC_CODE_ASIL_B_GLOBAL without prior opening SMU_START_SEC_CODE_ASIL_B_GLOBAL.
  #endif

#elif (defined SMU_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_SMU
    #error Tried to open section SMU_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
    #undef SMU_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
    #undef MEMMAP_ERROR_SMU
  #endif
#elif (defined SMU_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
    #undef SMU_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
    #undef MEMMAP_ERROR_SMU
  #else
    #undef MEMMAP_ERROR_SMU
    #error Tried to close section SMU_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED without prior opening SMU_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED.
  #endif

#elif (defined SMU_START_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_SMU
    #error Tried to open section SMU_START_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTCONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
    #undef SMU_START_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
    #undef MEMMAP_ERROR_SMU
  #endif
#elif (defined SMU_STOP_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTCONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTCONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
    #undef SMU_STOP_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
    #undef MEMMAP_ERROR_SMU
  #else
    #undef MEMMAP_ERROR_SMU
    #error Tried to close section SMU_STOP_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED without prior opening SMU_START_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED.
  #endif

#elif (defined SMU_START_SEC_VAR_INIT_ASIL_B_GLOBAL_32)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_SMU
    #error Tried to open section SMU_START_SEC_VAR_INIT_ASIL_B_GLOBAL_32 within an already open section.
  #else
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_VAR_INIT_ASIL_B_GLOBAL_32
    #undef SMU_START_SEC_VAR_INIT_ASIL_B_GLOBAL_32
    #undef MEMMAP_ERROR_SMU
  #endif
#elif (defined SMU_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_32)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_VAR_INIT_ASIL_B_GLOBAL_32)
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_VAR_INIT_ASIL_B_GLOBAL_32
    #undef SMU_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_32
    #undef MEMMAP_ERROR_SMU
  #else
    #undef MEMMAP_ERROR_SMU
    #error Tried to close section SMU_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_32 without prior opening SMU_START_SEC_VAR_INIT_ASIL_B_GLOBAL_32.
  #endif

#endif

#if ((!defined MEMMAP_ERROR_SMU) && (defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR
#elif ((defined MEMMAP_ERROR_SMU) && (!defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR_SMU
  #error MEMMAP_ERROR_SMU the included memory section was not defined within the BSW-IMPLEMENTATION of Smu.
#endif
