/**
 * \file Sdc_MemMap.h
 *
 * \brief
 *
 * \version Please refer the "Sdc_MemMap.h"
 * 
 */

/******************************************************************
 * ROM Memory Map : Code Section
 * ****************************************************************/
#ifdef SDC_START_SEC_CODE
  #undef SDC_START_SEC_CODE                        
  #define MEMMAP_COMMON_START_SEC_CORE0_QM_CODE                            
#endif
#ifdef SDC_STOP_SEC_CODE
  #undef SDC_STOP_SEC_CODE                        
  #define MEMMAP_COMMON_STOP_SEC_CORE0_QM_CODE
#endif

/******************************************************************
 * ROM Memory Map : Const Section
 * ****************************************************************/
#ifdef SDC_START_SEC_CONST_UNSPECIFIED
  #undef SDC_START_SEC_CONST_UNSPECIFIED                        
  #define MEMMAP_COMMON_START_SEC_CORE0_QM_CONST                            
#endif
#ifdef SDC_STOP_SEC_CONST_UNSPECIFIED
  #undef SDC_STOP_SEC_CONST_UNSPECIFIED                        
  #define MEMMAP_COMMON_STOP_SEC_CORE0_QM_CONST
#endif

/******************************************************************
 * RAM Memory Map : Bss Section
 * ****************************************************************/
#ifdef SDC_START_SEC_VAR_CLEARED_UNSPECIFIED
  #undef SDC_START_SEC_VAR_CLEARED_UNSPECIFIED                        
  #define MEMMAP_COMMON_START_SEC_PSPR_CORE0_QM_VAR_CLEARED                            
#endif
#ifdef SDC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #undef SDC_STOP_SEC_VAR_CLEARED_UNSPECIFIED                        
  #define MEMMAP_COMMON_STOP_SEC_PSPR_CORE0_QM_VAR_CLEARED
#endif

/******************************************************************
 * RAM Memory Map : Data Section
 * ****************************************************************/
#ifdef SDC_START_SEC_VAR_INIT_UNSPECIFIED
  #undef SDC_START_SEC_VAR_INIT_UNSPECIFIED                        
  #define MEMMAP_COMMON_START_SEC_PSPR_CORE0_ASIL_VAR_INIT                            
#endif
#ifdef SDC_STOP_SEC_VAR_INIT_UNSPECIFIED
  #undef SDC_STOP_SEC_VAR_INIT_UNSPECIFIED                        
  #define MEMMAP_COMMON_STOP_SEC_PSPR_CORE0_ASIL_VAR_INIT
#endif


#include "MemMap_Common.h"