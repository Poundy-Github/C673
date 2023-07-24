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

#define MEMMAP_ERROR_CTCDSPI

/*------------------[Start of a module]--------------------------------------*/

/* Memory section macros for CtCdSPI */

#if (defined CtCdSPI_START_SEC_CODE)
  #ifdef MEMMAP_SECTION_OPENED
    #undef MEMMAP_ERROR_CTCDSPI
    #error Tried to open section CtCdSPI_START_SEC_CODE within an already open section.
  #else
    #pragma section code Grp_ROM_Core0_QM_Code_Section
    #define MEMMAP_SECTION_OPENED
    #define MEMMAP_SECTION_OPENED_STARTSEC_CODE
    #undef CtCdSPI_START_SEC_CODE
    #undef MEMMAP_ERROR_CTCDSPI
  #endif
#elif (defined CtCdSPI_STOP_SEC_CODE)
  #if (defined MEMMAP_SECTION_OPENED) && (defined MEMMAP_SECTION_OPENED_STARTSEC_CODE)
    #pragma section code restore
    #undef MEMMAP_SECTION_OPENED
    #undef MEMMAP_SECTION_OPENED_STARTSEC_CODE
    #undef CtCdSPI_STOP_SEC_CODE
    #undef MEMMAP_ERROR_CTCDSPI
  #else
    #undef MEMMAP_ERROR_CTCDSPI
    #error Tried to close section CtCdSPI_STOP_SEC_CODE without prior opening CtCdSPI_START_SEC_CODE.
  #endif

#endif

#ifdef MEMMAP_ERROR_CTCDSPI
  #undef MEMMAP_ERROR_CTCDSPI
  #error MEMMAP_ERROR_CTCDSPI the included memory section was not defined within the SWC-IMPLEMENTATION of CtCdSPI.
#endif
