/**
 * \file MemMap_Common.h
 *
 * \brief
 *
 * \version
 * --------------------------------------------------------------------------------------------
 * Version	  | 		  Date		  |		    Author			  | 	Comments
 * V0.0.1		      2022.12.24			  Mingfen XIAO			    1.Init version
 */
/******************************************************************
 * Code Flash Memory Map : Core0 QM Code Section
 * ****************************************************************/
#ifdef MEMMAP_COMMON_START_SEC_CORE0_QM_CODE
  #undef MEMMAP_COMMON_START_SEC_CORE0_QM_CODE                        
  #define START_SEC_ROM_CORE0_QM_CODE_SECTION                            
#endif
#ifdef MEMMAP_COMMON_STOP_SEC_CORE0_QM_CODE
  #undef MEMMAP_COMMON_STOP_SEC_CORE0_QM_CODE                        
  #define STOP_SEC_ROM_CORE0_QM_CODE_SECTION
#endif

/******************************************************************
 * Code Flash Memory Map : Core0 ASIL Code Section
 * ****************************************************************/
#ifdef MEMMAP_COMMON_START_SEC_CORE0_ASIL_CODE
  #undef MEMMAP_COMMON_START_SEC_CORE0_ASIL_CODE                        
  #define START_SEC_ROM_CORE0_ASIL_CODE_SECTION                            
#endif
#ifdef MEMMAP_COMMON_STOP_SEC_CORE0_ASIL_CODE
  #undef MEMMAP_COMMON_STOP_SEC_CORE0_ASIL_CODE                        
  #define STOP_SEC_ROM_CORE0_ASIL_CODE_SECTION
#endif

/******************************************************************
 * Code Flash Memory Map : Core1 QM Code Section
 * ****************************************************************/
#ifdef MEMMAP_COMMON_START_SEC_CORE1_QM_CODE
  #unde MEMMAP_COMMON_START_SEC_CORE1_QM_CODE                        
  #define START_SEC_ROM_CORE1_QM_CODE_SECTION                            
#endif
#ifdef MEMMAP_COMMON_STOP_SEC_CORE1_QM_CODE
  #undef MEMMAP_COMMON_STOP_SEC_CORE1_QM_CODE                        
  #define STOP_SEC_ROM_CORE1_QM_CODE_SECTION
#endif

/******************************************************************
 * Code Flash Memory Map : Core1 ASIL Code Section
 * ****************************************************************/
#ifdef MEMMAP_COMMON_START_SEC_CORE1_ASIL_CODE
  #undef MEMMAP_COMMON_START_SEC_CORE1_ASIL_CODE                        
  #define START_SEC_ROM_CORE1_ASIL_CODE_SECTION                            
#endif
#ifdef MEMMAP_COMMON_STOP_SEC_CORE1_ASIL_CODE
  #undef MEMMAP_COMMON_STOP_SEC_CORE1_ASIL_CODE                        
  #define STOP_SEC_ROM_CORE1_ASIL_CODE_SECTION
#endif

/******************************************************************
 * Code Flash Memory Map : Core2 QM Code Section
 * ****************************************************************/
#ifdef MEMMAP_COMMON_START_SEC_CORE2_QM_CODE
  #undef MEMMAP_COMMON_START_SEC_CORE2_QM_CODE                        
  #define START_SEC_ROM_CORE2_QM_CODE_SECTION                            
#endif
#ifdef MEMMAP_COMMON_STOP_SEC_CORE2_QM_CODE
  #undef MEMMAP_COMMON_STOP_SEC_CORE2_QM_CODE                        
  #define STOP_SEC_ROM_CORE2_QM_CODE_SECTION
#endif

/******************************************************************
 * Code Flash Memory Map : Core2 ASIL Code Section
 * ****************************************************************/
#ifdef MEMMAP_COMMON_START_SEC_CORE2_ASIL_CODE
  #undef MEMMAP_COMMON_START_SEC_CORE2_ASIL_CODE                        
  #define START_SEC_ROM_CORE2_ASIL_CODE_SECTION                            
#endif
#ifdef MEMMAP_COMMON_STOP_SEC_CORE2_ASIL_CODE
  #undef MEMMAP_COMMON_STOP_SEC_CORE2_ASIL_CODE                        
  #define STOP_SEC_ROM_CORE2_ASIL_CODE_SECTION
#endif

/******************************************************************
 * Code Flash Memory Map : Core3 QM Code Section
 * ****************************************************************/
#ifdef MEMMAP_COMMON_START_SEC_CORE3_QM_CODE
  #undef MEMMAP_COMMON_START_SEC_CORE3_QM_CODE                        
  #define START_SEC_ROM_CORE3_QM_CODE_SECTION                            
#endif
#ifdef MEMMAP_COMMON_STOP_SEC_CORE3_QM_CODE
  #undef MEMMAP_COMMON_STOP_SEC_CORE3_QM_CODE                        
  #define STOP_SEC_ROM_CORE3_QM_CODE_SECTION
#endif

/******************************************************************
 * Code Flash Memory Map : Core3 ASIL Code Section
 * ****************************************************************/
#ifdef MEMMAP_COMMON_START_SEC_CORE3_ASIL_CODE
  #undef MEMMAP_COMMON_START_SEC_CORE3_ASIL_CODE                        
  #define START_SEC_ROM_CORE3_ASIL_CODE_SECTION                            
#endif
#ifdef MEMMAP_COMMON_STOP_SEC_CORE3_ASIL_CODE
  #undef MEMMAP_COMMON_STOP_SEC_CORE3_ASIL_CODE                        
  #define STOP_SEC_ROM_CORE3_ASIL_CODE_SECTION
#endif

/******************************************************************
 * Code Flash Memory Map : Core0 QM Const Section
 * ****************************************************************/
#ifdef MEMMAP_COMMON_START_SEC_CORE0_QM_CONST
  #undef MEMMAP_COMMON_START_SEC_CORE0_QM_CONST                        
  #define START_SEC_ROM_CORE0_QM_CONST_SECTION                            
#endif
#ifdef MEMMAP_COMMON_STOP_SEC_CORE0_QM_CONST
  #undef MEMMAP_COMMON_STOP_SEC_CORE0_QM_CONST                        
  #define STOP_SEC_ROM_CORE0_QM_CONST_SECTION
#endif

/******************************************************************
 * Code Flash Memory Map : Core0 ASIL Const Section
 * ****************************************************************/
#ifdef MEMMAP_COMMON_START_SEC_CORE0_ASIL_CONST
  #undef MEMMAP_COMMON_START_SEC_CORE0_ASIL_CONST                        
  #define START_SEC_ROM_CORE0_ASIL_CONST_SECTION                            
#endif
#ifdef MEMMAP_COMMON_STOP_SEC_CORE0_ASIL_CONST
  #undef MEMMAP_COMMON_STOP_SEC_CORE0_ASIL_CONST                        
  #define STOP_SEC_ROM_CORE0_ASIL_CONST_SECTION
#endif

/******************************************************************
 * Code Flash Memory Map : Core1 QM Const Section
 * ****************************************************************/
#ifdef MEMMAP_COMMON_START_SEC_CORE1_QM_CONST
  #undef MEMMAP_COMMON_START_SEC_CORE1_QM_CONST                        
  #define START_SEC_ROM_CORE1_QM_CONST_SECTION                            
#endif
#ifdef MEMMAP_COMMON_STOP_SEC_CORE1_QM_CONST
  #undef MEMMAP_COMMON_STOP_SEC_CORE1_QM_CONST                        
  #define STOP_SEC_ROM_CORE1_QM_CONST_SECTION
#endif

/******************************************************************
 * Code Flash Memory Map : Core1 ASIL Const Section
 * ****************************************************************/
#ifdef MEMMAP_COMMON_START_SEC_CORE1_ASIL_CONST
  #undef MEMMAP_COMMON_START_SEC_CORE1_ASIL_CONST                        
  #define START_SEC_ROM_CORE1_ASIL_CONST_SECTION                            
#endif
#ifdef MEMMAP_COMMON_STOP_SEC_CORE1_ASIL_CONST
  #undef MEMMAP_COMMON_STOP_SEC_CORE1_ASIL_CONST                        
  #define STOP_SEC_ROM_CORE1_ASIL_CONST_SECTION
#endif

/******************************************************************
 * Code Flash Memory Map : Core2 QM Const Section
 * ****************************************************************/
#ifdef MEMMAP_COMMON_START_SEC_CORE2_QM_CONST
  #undef MEMMAP_COMMON_START_SEC_CORE2_QM_CONST                        
  #define START_SEC_ROM_CORE2_QM_CONST_SECTION                            
#endif
#ifdef MEMMAP_COMMON_STOP_SEC_CORE2_QM_CONST
  #undef MEMMAP_COMMON_STOP_SEC_CORE2_QM_CONST                        
  #define STOP_SEC_ROM_CORE2_QM_CONST_SECTION
#endif

/******************************************************************
 * Code Flash Memory Map : Core2 ASIL Const Section
 * ****************************************************************/
#ifdef MEMMAP_COMMON_START_SEC_CORE2_ASIL_CONST
  #undef MEMMAP_COMMON_START_SEC_CORE2_ASIL_CONST                        
  #define START_SEC_ROM_CORE2_ASIL_CONST_SECTION                            
#endif
#ifdef MEMMAP_COMMON_STOP_SEC_CORE2_ASIL_CONST
  #undef MEMMAP_COMMON_STOP_SEC_CORE2_ASIL_CONST                        
  #define STOP_SEC_ROM_CORE2_ASIL_CONST_SECTION
#endif

/******************************************************************
 * Code Flash Memory Map : Core3 QM Const Section
 * ****************************************************************/
#ifdef MEMMAP_COMMON_START_SEC_CORE3_QM_CONST
  #undef MEMMAP_COMMON_START_SEC_CORE3_QM_CONST                        
  #define START_SEC_ROM_CORE3_QM_CONST_SECTION                            
#endif
#ifdef MEMMAP_COMMON_STOP_SEC_CORE3_QM_CONST
  #undef MEMMAP_COMMON_STOP_SEC_CORE3_QM_CONST                        
  #define STOP_SEC_ROM_CORE3_QM_CONST_SECTION
#endif

/******************************************************************
 * Code Flash Memory Map : Core3 ASIL Const Section
 * ****************************************************************/
#ifdef MEMMAP_COMMON_START_SEC_CORE3_ASIL_CONST
  #undef MEMMAP_COMMON_START_SEC_CORE3_ASIL_CONST                        
  #define START_SEC_ROM_CORE3_ASIL_CONST_SECTION                            
#endif
#ifdef MEMMAP_COMMON_STOP_SEC_CORE3_ASIL_CONST
  #undef MEMMAP_COMMON_STOP_SEC_CORE3_ASIL_CONST                        
  #define STOP_SEC_ROM_CORE3_ASIL_CONST_SECTION
#endif

/******************************************************************
 * DSPR Memory Map : Core0 QM Bss Section
 * ****************************************************************/
#ifdef MEMMAP_COMMON_START_SEC_DSPR_CORE0_QM_VAR_CLEARED
  #undef MEMMAP_COMMON_START_SEC_DSPR_CORE0_QM_VAR_CLEARED                        
  #define START_SEC_RAM_DSPR_CORE0_QM_VAR_CLEARED_SECTION                            
#endif
#ifdef MEMMAP_COMMON_STOP_SEC_DSPR_CORE0_QM_VAR_CLEARED
  #undef MEMMAP_COMMON_STOP_SEC_DSPR_CORE0_QM_VAR_CLEARED                        
  #define STOP_SEC_RAM_DSPR_CORE0_QM_VAR_CLEARED_SECTION
#endif

/******************************************************************
 * DSPR Memory Map : Core0 ASIL Bss Section
 * ****************************************************************/
#ifdef MEMMAP_COMMON_START_SEC_DSPR_CORE0_ASIL_VAR_CLEARED
  #undef MEMMAP_COMMON_START_SEC_DSPR_CORE0_ASIL_VAR_CLEARED                        
  #define START_SEC_RAM_DSPR_CORE0_ASIL_VAR_CLEARED_SECTION                            
#endif
#ifdef MEMMAP_COMMON_STOP_SEC_DSPR_CORE0_ASIL_VAR_CLEARED
  #undef MEMMAP_COMMON_STOP_SEC_DSPR_CORE0_ASIL_VAR_CLEARED                        
  #define STOP_SEC_RAM_DSPR_CORE0_ASIL_VAR_CLEARED_SECTION
#endif

/******************************************************************
 * DSPR Memory Map : Core1 QM Bss Section
 * ****************************************************************/
#ifdef MEMMAP_COMMON_START_SEC_DSPR_CORE1_QM_VAR_CLEARED
  #undef MEMMAP_COMMON_START_SEC_DSPR_CORE1_QM_VAR_CLEARED                        
  #define START_SEC_RAM_DSPR_CORE1_QM_VAR_CLEARED_SECTION                            
#endif
#ifdef MEMMAP_COMMON_STOP_SEC_DSPR_CORE1_QM_VAR_CLEARED
  #undef MEMMAP_COMMON_STOP_SEC_DSPR_CORE1_QM_VAR_CLEARED                        
  #define STOP_SEC_RAM_DSPR_CORE1_QM_VAR_CLEARED_SECTION
#endif

/******************************************************************
 * DSPR Memory Map : Core1 ASIL Bss Section
 * ****************************************************************/
#ifdef MEMMAP_COMMON_START_SEC_DSPR_CORE1_ASIL_VAR_CLEARED
  #undef MEMMAP_COMMON_START_SEC_DSPR_CORE1_ASIL_VAR_CLEARED                        
  #define START_SEC_RAM_DSPR_CORE1_ASIL_VAR_CLEARED_SECTION                            
#endif
#ifdef MEMMAP_COMMON_STOP_SEC_DSPR_CORE1_ASIL_VAR_CLEARED
  #undef MEMMAP_COMMON_STOP_SEC_DSPR_CORE1_ASIL_VAR_CLEARED                        
  #define STOP_SEC_RAM_DSPR_CORE1_ASIL_VAR_CLEARED_SECTION
#endif

/******************************************************************
 * DSPR Memory Map : Core2 QM Bss Section
 * ****************************************************************/
#ifdef MEMMAP_COMMON_START_SEC_DSPR_CORE2_QM_VAR_CLEARED
  #undef MEMMAP_COMMON_START_SEC_DSPR_CORE2_QM_VAR_CLEARED                        
  #define START_SEC_RAM_DSPR_CORE2_QM_VAR_CLEARED_SECTION                            
#endif
#ifdef MEMMAP_COMMON_STOP_SEC_DSPR_CORE2_QM_VAR_CLEARED
  #undef MEMMAP_COMMON_STOP_SEC_DSPR_CORE2_QM_VAR_CLEARED                        
  #define STOP_SEC_RAM_DSPR_CORE2_QM_VAR_CLEARED_SECTION
#endif

/******************************************************************
 * DSPR Memory Map : Core2 ASIL Bss Section
 * ****************************************************************/
#ifdef MEMMAP_COMMON_START_SEC_DSPR_CORE2_ASIL_VAR_CLEARED
  #undef MEMMAP_COMMON_START_SEC_DSPR_CORE2_ASIL_VAR_CLEARED                        
  #define START_SEC_RAM_DSPR_CORE2_ASIL_VAR_CLEARED_SECTION                            
#endif
#ifdef MEMMAP_COMMON_STOP_SEC_DSPR_CORE2_ASIL_VAR_CLEARED
  #undef MEMMAP_COMMON_STOP_SEC_DSPR_CORE2_ASIL_VAR_CLEARED                        
  #define STOP_SEC_RAM_DSPR_CORE2_ASIL_VAR_CLEARED_SECTION
#endif

/******************************************************************
 * DSPR Memory Map : Core3 QM Bss Section
 * ****************************************************************/
#ifdef MEMMAP_COMMON_START_SEC_DSPR_CORE3_QM_VAR_CLEARED
  #undef MEMMAP_COMMON_START_SEC_DSPR_CORE3_QM_VAR_CLEARED                        
  #define START_SEC_RAM_DSPR_CORE3_QM_VAR_CLEARED_SECTION                            
#endif
#ifdef MEMMAP_COMMON_STOP_SEC_DSPR_CORE3_QM_VAR_CLEARED
  #undef MEMMAP_COMMON_STOP_SEC_DSPR_CORE3_QM_VAR_CLEARED                        
  #define STOP_SEC_RAM_DSPR_CORE3_QM_VAR_CLEARED_SECTION
#endif

/******************************************************************
 * DSPR Memory Map : Core3 ASIL Bss Section
 * ****************************************************************/
#ifdef MEMMAP_COMMON_START_SEC_DSPR_CORE3_ASIL_VAR_CLEARED
  #undef MEMMAP_COMMON_START_SEC_DSPR_CORE3_ASIL_VAR_CLEARED                        
  #define START_SEC_RAM_DSPR_CORE3_ASIL_VAR_CLEARED_SECTION                            
#endif
#ifdef MEMMAP_COMMON_STOP_SEC_DSPR_CORE3_ASIL_VAR_CLEARED
  #undef MEMMAP_COMMON_STOP_SEC_DSPR_CORE3_ASIL_VAR_CLEARED                        
  #define STOP_SEC_RAM_DSPR_CORE3_ASIL_VAR_CLEARED_SECTION
#endif

/******************************************************************
 * PSPR Memory Map : Core0 QM Bss Section
 * ****************************************************************/
#ifdef MEMMAP_COMMON_START_SEC_PSPR_CORE0_QM_VAR_CLEARED
  #undef MEMMAP_COMMON_START_SEC_PSPR_CORE0_QM_VAR_CLEARED                        
  #define START_SEC_RAM_PSPR_CORE0_QM_VAR_CLEARED_SECTION                            
#endif
#ifdef MEMMAP_COMMON_STOP_SEC_PSPR_CORE0_QM_VAR_CLEARED
  #undef MEMMAP_COMMON_STOP_SEC_PSPR_CORE0_QM_VAR_CLEARED                        
  #define STOP_SEC_RAM_PSPR_CORE0_QM_VAR_CLEARED_SECTION
#endif

/******************************************************************
 * PSPR Memory Map : Core0 ASIL Bss Section
 * ****************************************************************/
#ifdef MEMMAP_COMMON_START_SEC_PSPR_CORE0_ASIL_VAR_CLEARED
  #undef MEMMAP_COMMON_START_SEC_PSPR_CORE0_ASIL_VAR_CLEARED                        
  #define START_SEC_RAM_PSPR_CORE0_ASIL_VAR_CLEARED_SECTION                            
#endif
#ifdef MEMMAP_COMMON_STOP_SEC_PSPR_CORE0_ASIL_VAR_CLEARED
  #undef MEMMAP_COMMON_STOP_SEC_PSPR_CORE0_ASIL_VAR_CLEARED                        
  #define STOP_SEC_RAM_PSPR_CORE0_ASIL_VAR_CLEARED_SECTION
#endif

/******************************************************************
 * PSPR Memory Map : Core1 QM Bss Section
 * ****************************************************************/
#ifdef MEMMAP_COMMON_START_SEC_PSPR_CORE1_QM_VAR_CLEARED
  #undef MEMMAP_COMMON_START_SEC_PSPR_CORE1_QM_VAR_CLEARED                        
  #define START_SEC_RAM_PSPR_CORE1_QM_VAR_CLEARED_SECTION                            
#endif
#ifdef MEMMAP_COMMON_STOP_SEC_PSPR_CORE1_QM_VAR_CLEARED
  #undef MEMMAP_COMMON_STOP_SEC_PSPR_CORE1_QM_VAR_CLEARED                        
  #define STOP_SEC_RAM_PSPR_CORE1_QM_VAR_CLEARED_SECTION
#endif

/******************************************************************
 * PSPR Memory Map : Core1 ASIL Bss Section
 * ****************************************************************/
#ifdef MEMMAP_COMMON_START_SEC_PSPR_CORE1_ASIL_VAR_CLEARED
  #undef MEMMAP_COMMON_START_SEC_PSPR_CORE1_ASIL_VAR_CLEARED                        
  #define START_SEC_RAM_PSPR_CORE1_ASIL_VAR_CLEARED_SECTION                            
#endif
#ifdef MEMMAP_COMMON_STOP_SEC_PSPR_CORE1_ASIL_VAR_CLEARED
  #undef MEMMAP_COMMON_STOP_SEC_PSPR_CORE1_ASIL_VAR_CLEARED                        
  #define STOP_SEC_RAM_PSPR_CORE1_ASIL_VAR_CLEARED_SECTION
#endif

/******************************************************************
 * PSPR Memory Map : Core2 QM Bss Section
 * ****************************************************************/
#ifdef MEMMAP_COMMON_START_SEC_PSPR_CORE2_QM_VAR_CLEARED
  #undef MEMMAP_COMMON_START_SEC_PSPR_CORE2_QM_VAR_CLEARED                        
  #define START_SEC_RAM_PSPR_CORE2_QM_VAR_CLEARED_SECTION                            
#endif
#ifdef MEMMAP_COMMON_STOP_SEC_PSPR_CORE2_QM_VAR_CLEARED
  #undef MEMMAP_COMMON_STOP_SEC_PSPR_CORE2_QM_VAR_CLEARED                        
  #define STOP_SEC_RAM_PSPR_CORE2_QM_VAR_CLEARED_SECTION
#endif

/******************************************************************
 * PSPR Memory Map : Core2 ASIL Bss Section
 * ****************************************************************/
#ifdef MEMMAP_COMMON_START_SEC_PSPR_CORE2_ASIL_VAR_CLEARED
  #undef MEMMAP_COMMON_START_SEC_PSPR_CORE2_ASIL_VAR_CLEARED                        
  #define START_SEC_RAM_PSPR_CORE2_ASIL_VAR_CLEARED_SECTION                            
#endif
#ifdef MEMMAP_COMMON_STOP_SEC_PSPR_CORE2_ASIL_VAR_CLEARED
  #undef MEMMAP_COMMON_STOP_SEC_PSPR_CORE2_ASIL_VAR_CLEARED                        
  #define STOP_SEC_RAM_PSPR_CORE2_ASIL_VAR_CLEARED_SECTION
#endif

/******************************************************************
 * PSPR Memory Map : Core3 QM Bss Section
 * ****************************************************************/
#ifdef MEMMAP_COMMON_START_SEC_PSPR_CORE3_QM_VAR_CLEARED
  #undef MEMMAP_COMMON_START_SEC_PSPR_CORE3_QM_VAR_CLEARED                        
  #define START_SEC_RAM_PSPR_CORE3_QM_VAR_CLEARED_SECTION                            
#endif
#ifdef MEMMAP_COMMON_STOP_SEC_PSPR_CORE3_QM_VAR_CLEARED
  #undef MEMMAP_COMMON_STOP_SEC_PSPR_CORE3_QM_VAR_CLEARED                        
  #define STOP_SEC_RAM_PSPR_CORE3_QM_VAR_CLEARED_SECTION
#endif

/******************************************************************
 * PSPR Memory Map : Core3 ASIL Bss Section
 * ****************************************************************/
#ifdef MEMMAP_COMMON_START_SEC_PSPR_CORE3_ASIL_VAR_CLEARED
  #undef MEMMAP_COMMON_START_SEC_PSPR_CORE3_ASIL_VAR_CLEARED                        
  #define START_SEC_RAM_PSPR_CORE3_ASIL_VAR_CLEARED_SECTION                            
#endif
#ifdef MEMMAP_COMMON_STOP_SEC_PSPR_CORE3_ASIL_VAR_CLEARED
  #undef MEMMAP_COMMON_STOP_SEC_PSPR_CORE3_ASIL_VAR_CLEARED                        
  #define STOP_SEC_RAM_PSPR_CORE3_ASIL_VAR_CLEARED_SECTION
#endif

/******************************************************************
 * DSPR Memory Map : Core0 QM Data Section
 * ****************************************************************/
#ifdef MEMMAP_COMMON_START_SEC_DSPR_CORE0_QM_VAR_INIT
  #undef MEMMAP_COMMON_START_SEC_DSPR_CORE0_QM_VAR_INIT                        
  #define START_SEC_RAM_DSPR_CORE0_QM_VAR_INIT_SECTION                            
#endif
#ifdef MEMMAP_COMMON_STOP_SEC_DSPR_CORE0_QM_VAR_INIT
  #undef MEMMAP_COMMON_STOP_SEC_DSPR_CORE0_QM_VAR_INIT                        
  #define STOP_SEC_RAM_DSPR_CORE0_QM_VAR_INIT_SECTION
#endif

/******************************************************************
 * DSPR Memory Map : Core0 ASIL Data Section
 * ****************************************************************/
#ifdef MEMMAP_COMMON_START_SEC_DSPR_CORE0_ASIL_VAR_INIT
  #undef MEMMAP_COMMON_START_SEC_DSPR_CORE0_ASIL_VAR_INIT                        
  #define START_SEC_RAM_DSPR_CORE0_ASIL_VAR_INIT_SECTION                            
#endif
#ifdef MEMMAP_COMMON_STOP_SEC_DSPR_CORE0_ASIL_VAR_INIT
  #undef MEMMAP_COMMON_STOP_SEC_DSPR_CORE0_ASIL_VAR_INIT                        
  #define STOP_SEC_RAM_DSPR_CORE0_ASIL_VAR_INIT_SECTION
#endif

/******************************************************************
 * DSPR Memory Map : Core1 QM Data Section
 * ****************************************************************/
#ifdef MEMMAP_COMMON_START_SEC_DSPR_CORE1_QM_VAR_INIT
  #undef MEMMAP_COMMON_START_SEC_DSPR_CORE1_QM_VAR_INIT                        
  #define START_SEC_RAM_DSPR_CORE1_QM_VAR_INIT_SECTION                            
#endif
#ifdef MEMMAP_COMMON_STOP_SEC_DSPR_CORE1_QM_VAR_INIT
  #undef MEMMAP_COMMON_STOP_SEC_DSPR_CORE1_QM_VAR_INIT                        
  #define STOP_SEC_RAM_DSPR_CORE1_QM_VAR_INIT_SECTION
#endif

/******************************************************************
 * DSPR Memory Map : Core1 ASIL Data Section
 * ****************************************************************/
#ifdef MEMMAP_COMMON_START_SEC_DSPR_CORE1_ASIL_VAR_INIT
  #undef MEMMAP_COMMON_START_SEC_DSPR_CORE1_ASIL_VAR_INIT                        
  #define START_SEC_RAM_DSPR_CORE1_ASIL_VAR_INIT_SECTION                            
#endif
#ifdef MEMMAP_COMMON_STOP_SEC_DSPR_CORE1_ASIL_VAR_INIT
  #undef MEMMAP_COMMON_STOP_SEC_DSPR_CORE1_ASIL_VAR_INIT                        
  #define STOP_SEC_RAM_DSPR_CORE1_ASIL_VAR_INIT_SECTION
#endif

/******************************************************************
 * DSPR Memory Map : Core2 QM Data Section
 * ****************************************************************/
#ifdef MEMMAP_COMMON_START_SEC_DSPR_CORE2_QM_VAR_INIT
  #undef MEMMAP_COMMON_START_SEC_DSPR_CORE2_QM_VAR_INIT                        
  #define START_SEC_RAM_DSPR_CORE2_QM_VAR_INIT_SECTION                            
#endif
#ifdef MEMMAP_COMMON_STOP_SEC_DSPR_CORE2_QM_VAR_INIT
  #undef MEMMAP_COMMON_STOP_SEC_DSPR_CORE2_QM_VAR_INIT                        
  #define STOP_SEC_RAM_DSPR_CORE2_QM_VAR_INIT_SECTION
#endif

/******************************************************************
 * DSPR Memory Map : Core2 ASIL Data Section
 * ****************************************************************/
#ifdef MEMMAP_COMMON_START_SEC_DSPR_CORE2_ASIL_VAR_INIT
  #undef MEMMAP_COMMON_START_SEC_DSPR_CORE2_ASIL_VAR_INIT                        
  #define START_SEC_RAM_DSPR_CORE2_ASIL_VAR_INIT_SECTION                            
#endif
#ifdef MEMMAP_COMMON_STOP_SEC_DSPR_CORE2_ASIL_VAR_INIT
  #undef MEMMAP_COMMON_STOP_SEC_DSPR_CORE2_ASIL_VAR_INIT                        
  #define STOP_SEC_RAM_DSPR_CORE2_ASIL_VAR_INIT_SECTION
#endif

/******************************************************************
 * DSPR Memory Map : Core3 QM Data Section
 * ****************************************************************/
#ifdef MEMMAP_COMMON_START_SEC_DSPR_CORE3_QM_VAR_INIT
  #undef MEMMAP_COMMON_START_SEC_DSPR_CORE3_QM_VAR_INIT                        
  #define START_SEC_RAM_DSPR_CORE3_QM_VAR_INIT_SECTION                            
#endif
#ifdef MEMMAP_COMMON_STOP_SEC_DSPR_CORE3_QM_VAR_INIT
  #undef MEMMAP_COMMON_STOP_SEC_DSPR_CORE3_QM_VAR_INIT                        
  #define STOP_SEC_RAM_DSPR_CORE3_QM_VAR_INIT_SECTION
#endif

/******************************************************************
 * DSPR Memory Map : Core3 ASIL Data Section
 * ****************************************************************/
#ifdef MEMMAP_COMMON_START_SEC_DSPR_CORE3_ASIL_VAR_INIT
  #undef MEMMAP_COMMON_START_SEC_DSPR_CORE3_ASIL_VAR_INIT                        
  #define START_SEC_RAM_DSPR_CORE3_ASIL_VAR_INIT_SECTION                            
#endif
#ifdef MEMMAP_COMMON_STOP_SEC_DSPR_CORE3_ASIL_VAR_INIT
  #undef MEMMAP_COMMON_STOP_SEC_DSPR_CORE3_ASIL_VAR_INIT                        
  #define STOP_SEC_RAM_DSPR_CORE3_ASIL_VAR_INIT_SECTION
#endif

/******************************************************************
 * PSPR Memory Map : Core0 QM Data Section
 * ****************************************************************/
#ifdef MEMMAP_COMMON_START_SEC_PSPR_CORE0_QM_VAR_INIT
  #undef MEMMAP_COMMON_START_SEC_PSPR_CORE0_QM_VAR_INIT                        
  #define START_SEC_RAM_PSPR_CORE0_QM_VAR_INIT_SECTION                            
#endif
#ifdef MEMMAP_COMMON_STOP_SEC_PSPR_CORE0_QM_VAR_INIT
  #undef MEMMAP_COMMON_STOP_SEC_PSPR_CORE0_QM_VAR_INIT                        
  #define STOP_SEC_RAM_PSPR_CORE0_QM_VAR_INIT_SECTION
#endif

/******************************************************************
 * PSPR Memory Map : Core0 ASIL Data Section
 * ****************************************************************/
#ifdef MEMMAP_COMMON_START_SEC_PSPR_CORE0_ASIL_VAR_INIT
  #undef MEMMAP_COMMON_START_SEC_PSPR_CORE0_ASIL_VAR_INIT                        
  #define START_SEC_RAM_PSPR_CORE0_ASIL_VAR_INIT_SECTION                            
#endif
#ifdef MEMMAP_COMMON_STOP_SEC_PSPR_CORE0_ASIL_VAR_INIT
  #undef MEMMAP_COMMON_STOP_SEC_PSPR_CORE0_ASIL_VAR_INIT                        
  #define STOP_SEC_RAM_PSPR_CORE0_ASIL_VAR_INIT_SECTION
#endif

/******************************************************************
 * PSPR Memory Map : Core1 QM Data Section
 * ****************************************************************/
#ifdef MEMMAP_COMMON_START_SEC_PSPR_CORE1_QM_VAR_INIT
  #undef MEMMAP_COMMON_START_SEC_PSPR_CORE1_QM_VAR_INIT                        
  #define START_SEC_RAM_PSPR_CORE1_QM_VAR_INIT_SECTION                            
#endif
#ifdef MEMMAP_COMMON_STOP_SEC_PSPR_CORE1_QM_VAR_INIT
  #undef MEMMAP_COMMON_STOP_SEC_PSPR_CORE1_QM_VAR_INIT                        
  #define STOP_SEC_RAM_PSPR_CORE1_QM_VAR_INIT_SECTION
#endif

/******************************************************************
 * PSPR Memory Map : Core1 ASIL Data Section
 * ****************************************************************/
#ifdef MEMMAP_COMMON_START_SEC_PSPR_CORE1_ASIL_VAR_INIT
  #undef MEMMAP_COMMON_START_SEC_PSPR_CORE1_ASIL_VAR_INIT                        
  #define START_SEC_RAM_PSPR_CORE1_ASIL_VAR_INIT_SECTION                            
#endif
#ifdef MEMMAP_COMMON_STOP_SEC_PSPR_CORE1_ASIL_VAR_INIT
  #undef MEMMAP_COMMON_STOP_SEC_PSPR_CORE1_ASIL_VAR_INIT                        
  #define STOP_SEC_RAM_PSPR_CORE1_ASIL_VAR_INIT_SECTION
#endif

/******************************************************************
 * PSPR Memory Map : Core2 QM Data Section
 * ****************************************************************/
#ifdef MEMMAP_COMMON_START_SEC_PSPR_CORE2_QM_VAR_INIT
  #undef MEMMAP_COMMON_START_SEC_PSPR_CORE2_QM_VAR_INIT                        
  #define START_SEC_RAM_PSPR_CORE2_QM_VAR_INIT_SECTION                            
#endif
#ifdef MEMMAP_COMMON_STOP_SEC_PSPR_CORE2_QM_VAR_INIT
  #undef MEMMAP_COMMON_STOP_SEC_PSPR_CORE2_QM_VAR_INIT                        
  #define STOP_SEC_RAM_PSPR_CORE2_QM_VAR_INIT_SECTION
#endif

/******************************************************************
 * PSPR Memory Map : Core2 ASIL Data Section
 * ****************************************************************/
#ifdef MEMMAP_COMMON_START_SEC_PSPR_CORE2_ASIL_VAR_INIT
  #undef MEMMAP_COMMON_START_SEC_PSPR_CORE2_ASIL_VAR_INIT                        
  #define START_SEC_RAM_PSPR_CORE2_ASIL_VAR_INIT_SECTION                            
#endif
#ifdef MEMMAP_COMMON_STOP_SEC_PSPR_CORE2_ASIL_VAR_INIT
  #undef MEMMAP_COMMON_STOP_SEC_PSPR_CORE2_ASIL_VAR_INIT                        
  #define STOP_SEC_RAM_PSPR_CORE2_ASIL_VAR_INIT_SECTION
#endif

/******************************************************************
 * PSPR Memory Map : Core3 QM Data Section
 * ****************************************************************/
#ifdef MEMMAP_COMMON_START_SEC_PSPR_CORE3_QM_VAR_INIT
  #undef MEMMAP_COMMON_START_SEC_PSPR_CORE3_QM_VAR_INIT                        
  #define START_SEC_RAM_PSPR_CORE3_QM_VAR_INIT_SECTION                            
#endif
#ifdef MEMMAP_COMMON_STOP_SEC_PSPR_CORE3_QM_VAR_INIT
  #undef MEMMAP_COMMON_STOP_SEC_PSPR_CORE3_QM_VAR_INIT                        
  #define STOP_SEC_RAM_PSPR_CORE3_QM_VAR_INIT_SECTION
#endif

/******************************************************************
 * PSPR Memory Map : Core3 ASIL Data Section
 * ****************************************************************/
#ifdef MEMMAP_COMMON_START_SEC_PSPR_CORE3_ASIL_VAR_INIT
  #undef MEMMAP_COMMON_START_SEC_PSPR_CORE3_ASIL_VAR_INIT                        
  #define START_SEC_RAM_PSPR_CORE3_ASIL_VAR_INIT_SECTION                            
#endif
#ifdef MEMMAP_COMMON_STOP_SEC_PSPR_CORE3_ASIL_VAR_INIT
  #undef MEMMAP_COMMON_STOP_SEC_PSPR_CORE3_ASIL_VAR_INIT                        
  #define STOP_SEC_RAM_PSPR_CORE3_ASIL_VAR_INIT_SECTION
#endif


#include "MemMap_MemorySection.h"
