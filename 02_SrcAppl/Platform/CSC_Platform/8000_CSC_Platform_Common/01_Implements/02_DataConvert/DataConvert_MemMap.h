/**
 * \file DataConvert_MemMap.h
 *
 * \brief
 *
 * \version Please refer the "DataConvert.h"
 * 
 */
/******************************************************************
 * ROM Memory Map : Code Section
 * ****************************************************************/
#ifdef DATACONVERT_START_SEC_CODE
  #undef DATACONVERT_START_SEC_CODE                        
  #define MEMMAP_COMMON_START_SEC_CORE0_QM_CODE                            
#endif
#ifdef DATACONVERT_STOP_SEC_CODE
  #undef DATACONVERT_STOP_SEC_CODE                        
  #define MEMMAP_COMMON_STOP_SEC_CORE0_QM_CODE
#endif

/******************************************************************
 * ROM Memory Map : Const Section
 * ****************************************************************/
#ifdef DATACONVERT_START_SEC_CONST_UNSPECIFIED
  #undef DATACONVERT_START_SEC_CONST_UNSPECIFIED                        
  #define MEMMAP_COMMON_START_SEC_CORE0_QM_CONST                            
#endif
#ifdef DATACONVERT_STOP_SEC_CONST_UNSPECIFIED
  #undef DATACONVERT_STOP_SEC_CONST_UNSPECIFIED                        
  #define MEMMAP_COMMON_STOP_SEC_CORE0_QM_CONST
#endif

/******************************************************************
 * RAM Memory Map : Bss Section
 * ****************************************************************/
#ifdef DATACONVERT_START_SEC_VAR_CLEARED_UNSPECIFIED
  #undef DATACONVERT_START_SEC_VAR_CLEARED_UNSPECIFIED                        
  #define MEMMAP_COMMON_START_SEC_DSPR_CORE0_QM_VAR_CLEARED                            
#endif
#ifdef DATACONVERT_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #undef DATACONVERT_STOP_SEC_VAR_CLEARED_UNSPECIFIED                        
  #define MEMMAP_COMMON_STOP_SEC_DSPR_CORE0_QM_VAR_CLEARED
#endif

/******************************************************************
 * RAM Memory Map : Data Section
 * ****************************************************************/
#ifdef DATACONVERT_START_SEC_VAR_INIT_UNSPECIFIED
  #undef DATACONVERT_START_SEC_VAR_INIT_UNSPECIFIED                        
  #define MEMMAP_COMMON_START_SEC_DSPR_CORE0_QM_VAR_INIT                            
#endif
#ifdef DATACONVERT_STOP_SEC_VAR_INIT_UNSPECIFIED
  #undef DATACONVERT_STOP_SEC_VAR_INIT_UNSPECIFIED                        
  #define MEMMAP_COMMON_STOP_SEC_DSPR_CORE0_QM_VAR_INIT
#endif

#include "MemMap_Common.h"
