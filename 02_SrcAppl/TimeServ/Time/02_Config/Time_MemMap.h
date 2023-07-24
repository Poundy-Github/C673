/**
 * \file Time_MemMap.h
 *
 * \brief
 *
 * \version Please refer the "Time.h"
 * 
 */
/******************************************************************
 * ROM Memory Map : Code Section
 * ****************************************************************/
#ifdef TIME_START_SEC_CODE
  #undef TIME_START_SEC_CODE                        
  #define MEMMAP_COMMON_START_SEC_CORE0_QM_CODE                            
#endif
#ifdef TIME_STOP_SEC_CODE
  #undef TIME_STOP_SEC_CODE                        
  #define MEMMAP_COMMON_STOP_SEC_CORE0_QM_CODE
#endif

/******************************************************************
 * ROM Memory Map : Const Section
 * ****************************************************************/
#ifdef TIME_START_SEC_CONST_UNSPECIFIED
  #undef TIME_START_SEC_CONST_UNSPECIFIED                        
  #define MEMMAP_COMMON_START_SEC_CORE0_QM_CONST                            
#endif
#ifdef TIME_STOP_SEC_CONST_UNSPECIFIED
  #undef TIME_STOP_SEC_CONST_UNSPECIFIED                        
  #define MEMMAP_COMMON_STOP_SEC_CORE0_QM_CONST
#endif

/******************************************************************
 * RAM Memory Map : Bss Section
 * ****************************************************************/
#ifdef TIME_START_SEC_VAR_CLEARED_UNSPECIFIED
  #undef TIME_START_SEC_VAR_CLEARED_UNSPECIFIED                        
  #define MEMMAP_COMMON_START_SEC_DSPR_CORE0_QM_VAR_CLEARED                            
#endif
#ifdef TIME_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #undef TIME_STOP_SEC_VAR_CLEARED_UNSPECIFIED                        
  #define MEMMAP_COMMON_STOP_SEC_DSPR_CORE0_QM_VAR_CLEARED
#endif

/******************************************************************
 * RAM Memory Map : Data Section
 * ****************************************************************/
#ifdef TIME_START_SEC_VAR_INIT_UNSPECIFIED
  #undef TIME_START_SEC_VAR_INIT_UNSPECIFIED                        
  #define MEMMAP_COMMON_START_SEC_DSPR_CORE0_QM_VAR_INIT                            
#endif
#ifdef TIME_STOP_SEC_VAR_INIT_UNSPECIFIED
  #undef TIME_STOP_SEC_VAR_INIT_UNSPECIFIED                        
  #define MEMMAP_COMMON_STOP_SEC_DSPR_CORE0_QM_VAR_INIT
#endif

#include "MemMap_Common.h"
