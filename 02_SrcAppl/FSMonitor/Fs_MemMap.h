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

#define MEMMAP_ERROR_FS

/*------------------[Start of a module]--------------------------------------*/

/* Memory section macros for FlsLoader */

#if (defined FS_START_SEC_CODE_LOCAL)
  #pragma section code "code.fs"
  #undef FS_START_SEC_CODE_LOCAL
  #undef MEMMAP_ERROR_FS
#elif (defined FS_STOP_SEC_CODE_LOCAL)
  #pragma section code restore
  #undef FS_STOP_SEC_CODE_LOCAL
  #undef MEMMAP_ERROR_FS

#elif (defined FS_START_SEC_CONST_LOCAL)
  #pragma section farrom "const.fs"
  #undef FS_START_SEC_CONST_LOCAL
  #undef MEMMAP_ERROR_FS
#elif (defined FS_STOP_SEC_CONST_LOCAL)
  #pragma section farrom restore
  #undef FS_STOP_SEC_CONST_LOCAL
  #undef MEMMAP_ERROR_FS

#elif (defined FS_START_SEC_VAR_CLEARED_LOCAL)
  #pragma section fardata "cleared.fs"
  #undef FS_START_SEC_VAR_CLEARED_LOCAL
  #undef MEMMAP_ERROR_FS
#elif (defined FS_STOP_SEC_VAR_CLEARED_LOCAL)
  #pragma section fardata restore
  #undef FS_STOP_SEC_VAR_CLEARED_LOCAL
  #undef MEMMAP_ERROR_FS

#elif (defined FS_START_SEC_VAR_NON_CLEARED)
  #pragma section farbss "nonclear.fs"
  #undef FS_START_SEC_VAR_NON_CLEARED
  #undef MEMMAP_ERROR_FS
#elif (defined FS_STOP_SEC_VAR_NON_CLEARED)
  #pragma section farbss restore
  #undef FS_STOP_SEC_VAR_NON_CLEARED
  #undef MEMMAP_ERROR_FS
\
#endif

#if ((!defined MEMMAP_ERROR_FS) && (defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR
#elif ((defined MEMMAP_ERROR_FS) && (!defined MEMMAP_ERROR))
  #undef MEMMAP_ERROR_FS
  #error MEMMAP_ERROR_FS the included memory section was not defined within the BSW-IMPLEMENTATION of FlsLoader.
#endif
