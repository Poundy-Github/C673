/**
 * \file CSC_Platform_CSC_MEMMAP.h
 *
 * \brief
 *
 * \version
 * --------------------------------------------------------------------------------------------
 * Version	| 		Date		|		Author			| 	Comments
 * V0.0.1		2022.12.24			Mingfen XIAO			1.Init version
 */

/*==================[macros]=================================================*/
/*
 * \brief 	CSC_MEMMAP_SW_MAJOR_VERSION,
 * */
#ifndef CSC_MEMMAP_SW_MAJOR_VERSION
#define CSC_MEMMAP_SW_MAJOR_VERSION			(0u)
#endif

/*TODO : Check the version number range*/
#if (CSC_MEMMAP_SW_MAJOR_VERSION > 99)
#error CSC_MEMMAP_SW_MAJOR_VERSION out of range
#endif

/*
 * \brief 	CSC_MEMMAP_SW_MINOR_VERSION,
 * */
#ifndef CSC_MEMMAP_SW_MINOR_VERSION
#define CSC_MEMMAP_SW_MINOR_VERSION			(0u)
#endif

/*TODO : Check the version number range*/
#if (CSC_MEMMAP_SW_MINOR_VERSION > 99)
#error CSC_MEMMAP_SW_MINOR_VERSION out of range
#endif

/*
 * \brief 	CSC_MEMMAP_SW_PATCH_VERSION,
 * */
#ifndef CSC_MEMMAP_SW_PATCH_VERSION
#define CSC_MEMMAP_SW_PATCH_VERSION			(1u)
#endif

/*TODO : Check the version number range*/
#if (CSC_MEMMAP_SW_PATCH_VERSION > 99)
#error CSC_MEMMAP_SW_PATCH_VERSION out of range
#endif

/******************************************************************
 * CSC Platform START
 * ****************************************************************/
/******************************************************************
 * Code Flash Memory Map : Core0 QM Code Section
 * ****************************************************************/
#ifdef CSC_PLATFORM_START_SEC_CORE0_QM_CODE
  #undef CSC_PLATFORM_START_SEC_CORE0_QM_CODE                        
  #define MEMMAP_COMMON_START_SEC_CORE0_QM_CODE                            
#endif
#ifdef CSC_PLATFORM_STOP_SEC_CORE0_QM_CODE
  #undef CSC_PLATFORM_STOP_SEC_CORE0_QM_CODE                        
  #define MEMMAP_COMMON_STOP_SEC_CORE0_QM_CODE
#endif

/******************************************************************
 * Code Flash Memory Map : Core0 ASIL Code Section
 * ****************************************************************/
#ifdef CSC_PLATFORM_START_SEC_CORE0_ASIL_CODE
  #undef CSC_PLATFORM_START_SEC_CORE0_ASIL_CODE                        
  #define MEMMAP_COMMON_START_SEC_CORE0_ASIL_CODE                            
#endif
#ifdef CSC_PLATFORM_STOP_SEC_CORE0_ASIL_CODE
  #undef CSC_PLATFORM_STOP_SEC_CORE0_ASIL_CODE                        
  #define MEMMAP_COMMON_STOP_SEC_CORE0_ASIL_CODE
#endif

/******************************************************************
 * Code Flash Memory Map : Core1 QM Code Section
 * ****************************************************************/
#ifdef CSC_PLATFORM_START_SEC_CORE1_QM_CODE
  #unde CSC_PLATFORM_START_SEC_CORE1_QM_CODE                        
  #define MEMMAP_COMMON_START_SEC_CORE1_QM_CODE                            
#endif
#ifdef CSC_PLATFORM_STOP_SEC_CORE1_QM_CODE
  #undef CSC_PLATFORM_STOP_SEC_CORE1_QM_CODE                        
  #define MEMMAP_COMMON_STOP_SEC_CORE1_QM_CODE
#endif

/******************************************************************
 * Code Flash Memory Map : Core1 ASIL Code Section
 * ****************************************************************/
#ifdef CSC_PLATFORM_START_SEC_CORE1_ASIL_CODE
  #undef CSC_PLATFORM_START_SEC_CORE1_ASIL_CODE                        
  #define MEMMAP_COMMON_START_SEC_CORE1_ASIL_CODE                            
#endif
#ifdef CSC_PLATFORM_STOP_SEC_CORE1_ASIL_CODE
  #undef CSC_PLATFORM_STOP_SEC_CORE1_ASIL_CODE                        
  #define MEMMAP_COMMON_STOP_SEC_CORE1_ASIL_CODE
#endif

/******************************************************************
 * Code Flash Memory Map : Core2 QM Code Section
 * ****************************************************************/
#ifdef CSC_PLATFORM_START_SEC_CORE2_QM_CODE
  #undef CSC_PLATFORM_START_SEC_CORE2_QM_CODE                        
  #define MEMMAP_COMMON_START_SEC_CORE2_QM_CODE                            
#endif
#ifdef CSC_PLATFORM_STOP_SEC_CORE2_QM_CODE
  #undef CSC_PLATFORM_STOP_SEC_CORE2_QM_CODE                        
  #define MEMMAP_COMMON_STOP_SEC_CORE2_QM_CODE
#endif

/******************************************************************
 * Code Flash Memory Map : Core2 ASIL Code Section
 * ****************************************************************/
#ifdef CSC_PLATFORM_START_SEC_CORE2_ASIL_CODE
  #undef CSC_PLATFORM_START_SEC_CORE2_ASIL_CODE                        
  #define MEMMAP_COMMON_START_SEC_CORE2_ASIL_CODE                            
#endif
#ifdef CSC_PLATFORM_STOP_SEC_CORE2_ASIL_CODE
  #undef CSC_PLATFORM_STOP_SEC_CORE2_ASIL_CODE                        
  #define MEMMAP_COMMON_STOP_SEC_CORE2_ASIL_CODE
#endif

/******************************************************************
 * Code Flash Memory Map : Core3 QM Code Section
 * ****************************************************************/
#ifdef CSC_PLATFORM_START_SEC_CORE3_QM_CODE
  #undef CSC_PLATFORM_START_SEC_CORE3_QM_CODE                        
  #define MEMMAP_COMMON_START_SEC_CORE3_QM_CODE                            
#endif
#ifdef CSC_PLATFORM_STOP_SEC_CORE3_QM_CODE
  #undef CSC_PLATFORM_STOP_SEC_CORE3_QM_CODE                        
  #define MEMMAP_COMMON_STOP_SEC_CORE3_QM_CODE
#endif

/******************************************************************
 * Code Flash Memory Map : Core3 ASIL Code Section
 * ****************************************************************/
#ifdef CSC_PLATFORM_START_SEC_CORE3_ASIL_CODE
  #undef CSC_PLATFORM_START_SEC_CORE3_ASIL_CODE                        
  #define MEMMAP_COMMON_START_SEC_CORE3_ASIL_CODE                            
#endif
#ifdef CSC_PLATFORM_STOP_SEC_CORE3_ASIL_CODE
  #undef CSC_PLATFORM_STOP_SEC_CORE3_ASIL_CODE                        
  #define MEMMAP_COMMON_STOP_SEC_CORE3_ASIL_CODE
#endif

/******************************************************************
 * Code Flash Memory Map : Core0 QM Const Section
 * ****************************************************************/
#ifdef CSC_PLATFORM_START_SEC_CORE0_QM_CONST
  #undef CSC_PLATFORM_START_SEC_CORE0_QM_CONST                        
  #define MEMMAP_COMMON_START_SEC_CORE0_QM_CONST                            
#endif
#ifdef CSC_PLATFORM_STOP_SEC_CORE0_QM_CONST
  #undef CSC_PLATFORM_STOP_SEC_CORE0_QM_CONST                        
  #define MEMMAP_COMMON_STOP_SEC_CORE0_QM_CONST
#endif

/******************************************************************
 * Code Flash Memory Map : Core0 ASIL Const Section
 * ****************************************************************/
#ifdef CSC_PLATFORM_START_SEC_CORE0_ASIL_CONST
  #undef CSC_PLATFORM_START_SEC_CORE0_ASIL_CONST                        
  #define MEMMAP_COMMON_START_SEC_CORE0_ASIL_CONST                            
#endif
#ifdef CSC_PLATFORM_STOP_SEC_CORE0_ASIL_CONST
  #undef CSC_PLATFORM_STOP_SEC_CORE0_ASIL_CONST                        
  #define MEMMAP_COMMON_STOP_SEC_CORE0_ASIL_CONST
#endif

/******************************************************************
 * Code Flash Memory Map : Core1 QM Const Section
 * ****************************************************************/
#ifdef CSC_PLATFORM_START_SEC_CORE1_QM_CONST
  #undef CSC_PLATFORM_START_SEC_CORE1_QM_CONST                        
  #define MEMMAP_COMMON_START_SEC_CORE1_QM_CONST                            
#endif
#ifdef CSC_PLATFORM_STOP_SEC_CORE1_QM_CONST
  #undef CSC_PLATFORM_STOP_SEC_CORE1_QM_CONST                        
  #define MEMMAP_COMMON_STOP_SEC_CORE1_QM_CONST
#endif

/******************************************************************
 * Code Flash Memory Map : Core1 ASIL Const Section
 * ****************************************************************/
#ifdef CSC_PLATFORM_START_SEC_CORE1_ASIL_CONST
  #undef CSC_PLATFORM_START_SEC_CORE1_ASIL_CONST                        
  #define MEMMAP_COMMON_START_SEC_CORE1_ASIL_CONST                            
#endif
#ifdef CSC_PLATFORM_STOP_SEC_CORE1_ASIL_CONST
  #undef CSC_PLATFORM_STOP_SEC_CORE1_ASIL_CONST                        
  #define MEMMAP_COMMON_STOP_SEC_CORE1_ASIL_CONST
#endif

/******************************************************************
 * Code Flash Memory Map : Core2 QM Const Section
 * ****************************************************************/
#ifdef CSC_PLATFORM_START_SEC_CORE2_QM_CONST
  #undef CSC_PLATFORM_START_SEC_CORE2_QM_CONST                        
  #define MEMMAP_COMMON_START_SEC_CORE2_QM_CONST                            
#endif
#ifdef CSC_PLATFORM_STOP_SEC_CORE2_QM_CONST
  #undef CSC_PLATFORM_STOP_SEC_CORE2_QM_CONST                        
  #define MEMMAP_COMMON_STOP_SEC_CORE2_QM_CONST
#endif

/******************************************************************
 * Code Flash Memory Map : Core2 ASIL Const Section
 * ****************************************************************/
#ifdef CSC_PLATFORM_START_SEC_CORE2_ASIL_CONST
  #undef CSC_PLATFORM_START_SEC_CORE2_ASIL_CONST                        
  #define MEMMAP_COMMON_START_SEC_CORE2_ASIL_CONST                            
#endif
#ifdef CSC_PLATFORM_STOP_SEC_CORE2_ASIL_CONST
  #undef CSC_PLATFORM_STOP_SEC_CORE2_ASIL_CONST                        
  #define MEMMAP_COMMON_STOP_SEC_CORE2_ASIL_CONST
#endif

/******************************************************************
 * Code Flash Memory Map : Core3 QM Const Section
 * ****************************************************************/
#ifdef CSC_PLATFORM_START_SEC_CORE3_QM_CONST
  #undef CSC_PLATFORM_START_SEC_CORE3_QM_CONST                        
  #define MEMMAP_COMMON_START_SEC_CORE3_QM_CONST                            
#endif
#ifdef CSC_PLATFORM_STOP_SEC_CORE3_QM_CONST
  #undef CSC_PLATFORM_STOP_SEC_CORE3_QM_CONST                        
  #define MEMMAP_COMMON_STOP_SEC_CORE3_QM_CONST
#endif

/******************************************************************
 * Code Flash Memory Map : Core3 ASIL Const Section
 * ****************************************************************/
#ifdef CSC_PLATFORM_START_SEC_CORE3_ASIL_CONST
  #undef CSC_PLATFORM_START_SEC_CORE3_ASIL_CONST                        
  #define MEMMAP_COMMON_START_SEC_CORE3_ASIL_CONST                            
#endif
#ifdef CSC_PLATFORM_STOP_SEC_CORE3_ASIL_CONST
  #undef CSC_PLATFORM_STOP_SEC_CORE3_ASIL_CONST                        
  #define MEMMAP_COMMON_STOP_SEC_CORE3_ASIL_CONST
#endif

/******************************************************************
 * DSPR Memory Map : Core0 QM Bss Section
 * ****************************************************************/
#ifdef CSC_PLATFORM_START_SEC_DSPR_CORE0_QM_VAR_CLEARED
  #undef CSC_PLATFORM_START_SEC_DSPR_CORE0_QM_VAR_CLEARED                        
  #define MEMMAP_COMMON_START_SEC_DSPR_CORE0_QM_VAR_CLEARED                            
#endif
#ifdef CSC_PLATFORM_STOP_SEC_DSPR_CORE0_QM_VAR_CLEARED
  #undef CSC_PLATFORM_STOP_SEC_DSPR_CORE0_QM_VAR_CLEARED                        
  #define MEMMAP_COMMON_STOP_SEC_DSPR_CORE0_QM_VAR_CLEARED
#endif

/******************************************************************
 * DSPR Memory Map : Core0 ASIL Bss Section
 * ****************************************************************/
#ifdef CSC_PLATFORM_START_SEC_DSPR_CORE0_ASIL_VAR_CLEARED
  #undef CSC_PLATFORM_START_SEC_DSPR_CORE0_ASIL_VAR_CLEARED                        
  #define MEMMAP_COMMON_START_SEC_DSPR_CORE0_ASIL_VAR_CLEARED                            
#endif
#ifdef CSC_PLATFORM_STOP_SEC_DSPR_CORE0_ASIL_VAR_CLEARED
  #undef CSC_PLATFORM_STOP_SEC_DSPR_CORE0_ASIL_VAR_CLEARED                        
  #define MEMMAP_COMMON_STOP_SEC_DSPR_CORE0_ASIL_VAR_CLEARED
#endif

/******************************************************************
 * DSPR Memory Map : Core1 QM Bss Section
 * ****************************************************************/
#ifdef CSC_PLATFORM_START_SEC_DSPR_CORE1_QM_VAR_CLEARED
  #undef CSC_PLATFORM_START_SEC_DSPR_CORE1_QM_VAR_CLEARED                        
  #define MEMMAP_COMMON_START_SEC_DSPR_CORE1_QM_VAR_CLEARED                            
#endif
#ifdef CSC_PLATFORM_STOP_SEC_DSPR_CORE1_QM_VAR_CLEARED
  #undef CSC_PLATFORM_STOP_SEC_DSPR_CORE1_QM_VAR_CLEARED                        
  #define MEMMAP_COMMON_STOP_SEC_DSPR_CORE1_QM_VAR_CLEARED
#endif

/******************************************************************
 * DSPR Memory Map : Core1 ASIL Bss Section
 * ****************************************************************/
#ifdef CSC_PLATFORM_START_SEC_DSPR_CORE1_ASIL_VAR_CLEARED
  #undef CSC_PLATFORM_START_SEC_DSPR_CORE1_ASIL_VAR_CLEARED                        
  #define MEMMAP_COMMON_START_SEC_DSPR_CORE1_ASIL_VAR_CLEARED                            
#endif
#ifdef CSC_PLATFORM_STOP_SEC_DSPR_CORE1_ASIL_VAR_CLEARED
  #undef CSC_PLATFORM_STOP_SEC_DSPR_CORE1_ASIL_VAR_CLEARED                        
  #define MEMMAP_COMMON_STOP_SEC_DSPR_CORE1_ASIL_VAR_CLEARED
#endif

/******************************************************************
 * DSPR Memory Map : Core2 QM Bss Section
 * ****************************************************************/
#ifdef CSC_PLATFORM_START_SEC_DSPR_CORE2_QM_VAR_CLEARED
  #undef CSC_PLATFORM_START_SEC_DSPR_CORE2_QM_VAR_CLEARED                        
  #define MEMMAP_COMMON_START_SEC_DSPR_CORE2_QM_VAR_CLEARED                            
#endif
#ifdef CSC_PLATFORM_STOP_SEC_DSPR_CORE2_QM_VAR_CLEARED
  #undef CSC_PLATFORM_STOP_SEC_DSPR_CORE2_QM_VAR_CLEARED                        
  #define MEMMAP_COMMON_STOP_SEC_DSPR_CORE2_QM_VAR_CLEARED
#endif

/******************************************************************
 * DSPR Memory Map : Core2 ASIL Bss Section
 * ****************************************************************/
#ifdef CSC_PLATFORM_START_SEC_DSPR_CORE2_ASIL_VAR_CLEARED
  #undef CSC_PLATFORM_START_SEC_DSPR_CORE2_ASIL_VAR_CLEARED                        
  #define MEMMAP_COMMON_START_SEC_DSPR_CORE2_ASIL_VAR_CLEARED                            
#endif
#ifdef CSC_PLATFORM_STOP_SEC_DSPR_CORE2_ASIL_VAR_CLEARED
  #undef CSC_PLATFORM_STOP_SEC_DSPR_CORE2_ASIL_VAR_CLEARED                        
  #define MEMMAP_COMMON_STOP_SEC_DSPR_CORE2_ASIL_VAR_CLEARED
#endif

/******************************************************************
 * DSPR Memory Map : Core3 QM Bss Section
 * ****************************************************************/
#ifdef CSC_PLATFORM_START_SEC_DSPR_CORE3_QM_VAR_CLEARED
  #undef CSC_PLATFORM_START_SEC_DSPR_CORE3_QM_VAR_CLEARED                        
  #define MEMMAP_COMMON_START_SEC_DSPR_CORE3_QM_VAR_CLEARED                            
#endif
#ifdef CSC_PLATFORM_STOP_SEC_DSPR_CORE3_QM_VAR_CLEARED
  #undef CSC_PLATFORM_STOP_SEC_DSPR_CORE3_QM_VAR_CLEARED                        
  #define MEMMAP_COMMON_STOP_SEC_DSPR_CORE3_QM_VAR_CLEARED
#endif

/******************************************************************
 * DSPR Memory Map : Core3 ASIL Bss Section
 * ****************************************************************/
#ifdef CSC_PLATFORM_START_SEC_DSPR_CORE3_ASIL_VAR_CLEARED
  #undef CSC_PLATFORM_START_SEC_DSPR_CORE3_ASIL_VAR_CLEARED                        
  #define MEMMAP_COMMON_START_SEC_DSPR_CORE3_ASIL_VAR_CLEARED                            
#endif
#ifdef CSC_PLATFORM_STOP_SEC_DSPR_CORE3_ASIL_VAR_CLEARED
  #undef CSC_PLATFORM_STOP_SEC_DSPR_CORE3_ASIL_VAR_CLEARED                        
  #define MEMMAP_COMMON_STOP_SEC_DSPR_CORE3_ASIL_VAR_CLEARED
#endif

/******************************************************************
 * PSPR Memory Map : Core0 QM Bss Section
 * ****************************************************************/
#ifdef CSC_PLATFORM_START_SEC_PSPR_CORE0_QM_VAR_CLEARED
  #undef CSC_PLATFORM_START_SEC_PSPR_CORE0_QM_VAR_CLEARED                        
  #define MEMMAP_COMMON_START_SEC_PSPR_CORE0_QM_VAR_CLEARED                            
#endif
#ifdef CSC_PLATFORM_STOP_SEC_PSPR_CORE0_QM_VAR_CLEARED
  #undef CSC_PLATFORM_STOP_SEC_PSPR_CORE0_QM_VAR_CLEARED                        
  #define MEMMAP_COMMON_STOP_SEC_PSPR_CORE0_QM_VAR_CLEARED
#endif

/******************************************************************
 * PSPR Memory Map : Core0 ASIL Bss Section
 * ****************************************************************/
#ifdef CSC_PLATFORM_START_SEC_PSPR_CORE0_ASIL_VAR_CLEARED
  #undef CSC_PLATFORM_START_SEC_PSPR_CORE0_ASIL_VAR_CLEARED                        
  #define MEMMAP_COMMON_START_SEC_PSPR_CORE0_ASIL_VAR_CLEARED                            
#endif
#ifdef CSC_PLATFORM_STOP_SEC_PSPR_CORE0_ASIL_VAR_CLEARED
  #undef CSC_PLATFORM_STOP_SEC_PSPR_CORE0_ASIL_VAR_CLEARED                        
  #define MEMMAP_COMMON_STOP_SEC_PSPR_CORE0_ASIL_VAR_CLEARED
#endif

/******************************************************************
 * PSPR Memory Map : Core1 QM Bss Section
 * ****************************************************************/
#ifdef CSC_PLATFORM_START_SEC_PSPR_CORE1_QM_VAR_CLEARED
  #undef CSC_PLATFORM_START_SEC_PSPR_CORE1_QM_VAR_CLEARED                        
  #define MEMMAP_COMMON_START_SEC_PSPR_CORE1_QM_VAR_CLEARED                            
#endif
#ifdef CSC_PLATFORM_STOP_SEC_PSPR_CORE1_QM_VAR_CLEARED
  #undef CSC_PLATFORM_STOP_SEC_PSPR_CORE1_QM_VAR_CLEARED                        
  #define MEMMAP_COMMON_STOP_SEC_PSPR_CORE1_QM_VAR_CLEARED
#endif

/******************************************************************
 * PSPR Memory Map : Core1 ASIL Bss Section
 * ****************************************************************/
#ifdef CSC_PLATFORM_START_SEC_PSPR_CORE1_ASIL_VAR_CLEARED
  #undef CSC_PLATFORM_START_SEC_PSPR_CORE1_ASIL_VAR_CLEARED                        
  #define MEMMAP_COMMON_START_SEC_PSPR_CORE1_ASIL_VAR_CLEARED                            
#endif
#ifdef CSC_PLATFORM_STOP_SEC_PSPR_CORE1_ASIL_VAR_CLEARED
  #undef CSC_PLATFORM_STOP_SEC_PSPR_CORE1_ASIL_VAR_CLEARED                        
  #define MEMMAP_COMMON_STOP_SEC_PSPR_CORE1_ASIL_VAR_CLEARED
#endif

/******************************************************************
 * PSPR Memory Map : Core2 QM Bss Section
 * ****************************************************************/
#ifdef CSC_PLATFORM_START_SEC_PSPR_CORE2_QM_VAR_CLEARED
  #undef CSC_PLATFORM_START_SEC_PSPR_CORE2_QM_VAR_CLEARED                        
  #define MEMMAP_COMMON_START_SEC_PSPR_CORE2_QM_VAR_CLEARED                            
#endif
#ifdef CSC_PLATFORM_STOP_SEC_PSPR_CORE2_QM_VAR_CLEARED
  #undef CSC_PLATFORM_STOP_SEC_PSPR_CORE2_QM_VAR_CLEARED                        
  #define MEMMAP_COMMON_STOP_SEC_PSPR_CORE2_QM_VAR_CLEARED
#endif

/******************************************************************
 * PSPR Memory Map : Core2 ASIL Bss Section
 * ****************************************************************/
#ifdef CSC_PLATFORM_START_SEC_PSPR_CORE2_ASIL_VAR_CLEARED
  #undef CSC_PLATFORM_START_SEC_PSPR_CORE2_ASIL_VAR_CLEARED                        
  #define MEMMAP_COMMON_START_SEC_PSPR_CORE2_ASIL_VAR_CLEARED                            
#endif
#ifdef CSC_PLATFORM_STOP_SEC_PSPR_CORE2_ASIL_VAR_CLEARED
  #undef CSC_PLATFORM_STOP_SEC_PSPR_CORE2_ASIL_VAR_CLEARED                        
  #define MEMMAP_COMMON_STOP_SEC_PSPR_CORE2_ASIL_VAR_CLEARED
#endif

/******************************************************************
 * PSPR Memory Map : Core3 QM Bss Section
 * ****************************************************************/
#ifdef CSC_PLATFORM_START_SEC_PSPR_CORE3_QM_VAR_CLEARED
  #undef CSC_PLATFORM_START_SEC_PSPR_CORE3_QM_VAR_CLEARED                        
  #define MEMMAP_COMMON_START_SEC_PSPR_CORE3_QM_VAR_CLEARED                            
#endif
#ifdef CSC_PLATFORM_STOP_SEC_PSPR_CORE3_QM_VAR_CLEARED
  #undef CSC_PLATFORM_STOP_SEC_PSPR_CORE3_QM_VAR_CLEARED                        
  #define MEMMAP_COMMON_STOP_SEC_PSPR_CORE3_QM_VAR_CLEARED
#endif

/******************************************************************
 * PSPR Memory Map : Core3 ASIL Bss Section
 * ****************************************************************/
#ifdef CSC_PLATFORM_START_SEC_PSPR_CORE3_ASIL_VAR_CLEARED
  #undef CSC_PLATFORM_START_SEC_PSPR_CORE3_ASIL_VAR_CLEARED                        
  #define MEMMAP_COMMON_START_SEC_PSPR_CORE3_ASIL_VAR_CLEARED                            
#endif
#ifdef CSC_PLATFORM_STOP_SEC_PSPR_CORE3_ASIL_VAR_CLEARED
  #undef CSC_PLATFORM_STOP_SEC_PSPR_CORE3_ASIL_VAR_CLEARED                        
  #define MEMMAP_COMMON_STOP_SEC_PSPR_CORE3_ASIL_VAR_CLEARED
#endif

/******************************************************************
 * DSPR Memory Map : Core0 QM Data Section
 * ****************************************************************/
#ifdef CSC_PLATFORM_START_SEC_DSPR_CORE0_QM_VAR_INIT
  #undef CSC_PLATFORM_START_SEC_DSPR_CORE0_QM_VAR_INIT                        
  #define MEMMAP_COMMON_START_SEC_DSPR_CORE0_QM_VAR_INIT                            
#endif
#ifdef CSC_PLATFORM_STOP_SEC_DSPR_CORE0_QM_VAR_INIT
  #undef CSC_PLATFORM_STOP_SEC_DSPR_CORE0_QM_VAR_INIT                        
  #define MEMMAP_COMMON_STOP_SEC_DSPR_CORE0_QM_VAR_INIT
#endif

/******************************************************************
 * DSPR Memory Map : Core0 ASIL Data Section
 * ****************************************************************/
#ifdef CSC_PLATFORM_START_SEC_DSPR_CORE0_ASIL_VAR_INIT
  #undef CSC_PLATFORM_START_SEC_DSPR_CORE0_ASIL_VAR_INIT                        
  #define MEMMAP_COMMON_START_SEC_DSPR_CORE0_ASIL_VAR_INIT                            
#endif
#ifdef CSC_PLATFORM_STOP_SEC_DSPR_CORE0_ASIL_VAR_INIT
  #undef CSC_PLATFORM_STOP_SEC_DSPR_CORE0_ASIL_VAR_INIT                        
  #define MEMMAP_COMMON_STOP_SEC_DSPR_CORE0_ASIL_VAR_INIT
#endif

/******************************************************************
 * DSPR Memory Map : Core1 QM Data Section
 * ****************************************************************/
#ifdef CSC_PLATFORM_START_SEC_DSPR_CORE1_QM_VAR_INIT
  #undef CSC_PLATFORM_START_SEC_DSPR_CORE1_QM_VAR_INIT                        
  #define MEMMAP_COMMON_START_SEC_DSPR_CORE1_QM_VAR_INIT                            
#endif
#ifdef CSC_PLATFORM_STOP_SEC_DSPR_CORE1_QM_VAR_INIT
  #undef CSC_PLATFORM_STOP_SEC_DSPR_CORE1_QM_VAR_INIT                        
  #define MEMMAP_COMMON_STOP_SEC_DSPR_CORE1_QM_VAR_INIT
#endif

/******************************************************************
 * DSPR Memory Map : Core1 ASIL Data Section
 * ****************************************************************/
#ifdef CSC_PLATFORM_START_SEC_DSPR_CORE1_ASIL_VAR_INIT
  #undef CSC_PLATFORM_START_SEC_DSPR_CORE1_ASIL_VAR_INIT                        
  #define MEMMAP_COMMON_START_SEC_DSPR_CORE1_ASIL_VAR_INIT                            
#endif
#ifdef CSC_PLATFORM_STOP_SEC_DSPR_CORE1_ASIL_VAR_INIT
  #undef CSC_PLATFORM_STOP_SEC_DSPR_CORE1_ASIL_VAR_INIT                        
  #define MEMMAP_COMMON_STOP_SEC_DSPR_CORE1_ASIL_VAR_INIT
#endif

/******************************************************************
 * DSPR Memory Map : Core2 QM Data Section
 * ****************************************************************/
#ifdef CSC_PLATFORM_START_SEC_DSPR_CORE2_QM_VAR_INIT
  #undef CSC_PLATFORM_START_SEC_DSPR_CORE2_QM_VAR_INIT                        
  #define MEMMAP_COMMON_START_SEC_DSPR_CORE2_QM_VAR_INIT                            
#endif
#ifdef CSC_PLATFORM_STOP_SEC_DSPR_CORE2_QM_VAR_INIT
  #undef CSC_PLATFORM_STOP_SEC_DSPR_CORE2_QM_VAR_INIT                        
  #define MEMMAP_COMMON_STOP_SEC_DSPR_CORE2_QM_VAR_INIT
#endif

/******************************************************************
 * DSPR Memory Map : Core2 ASIL Data Section
 * ****************************************************************/
#ifdef CSC_PLATFORM_START_SEC_DSPR_CORE2_ASIL_VAR_INIT
  #undef CSC_PLATFORM_START_SEC_DSPR_CORE2_ASIL_VAR_INIT                        
  #define MEMMAP_COMMON_START_SEC_DSPR_CORE2_ASIL_VAR_INIT                            
#endif
#ifdef CSC_PLATFORM_STOP_SEC_DSPR_CORE2_ASIL_VAR_INIT
  #undef CSC_PLATFORM_STOP_SEC_DSPR_CORE2_ASIL_VAR_INIT                        
  #define MEMMAP_COMMON_STOP_SEC_DSPR_CORE2_ASIL_VAR_INIT
#endif

/******************************************************************
 * DSPR Memory Map : Core3 QM Data Section
 * ****************************************************************/
#ifdef CSC_PLATFORM_START_SEC_DSPR_CORE3_QM_VAR_INIT
  #undef CSC_PLATFORM_START_SEC_DSPR_CORE3_QM_VAR_INIT                        
  #define MEMMAP_COMMON_START_SEC_DSPR_CORE3_QM_VAR_INIT                            
#endif
#ifdef CSC_PLATFORM_STOP_SEC_DSPR_CORE3_QM_VAR_INIT
  #undef CSC_PLATFORM_STOP_SEC_DSPR_CORE3_QM_VAR_INIT                        
  #define MEMMAP_COMMON_STOP_SEC_DSPR_CORE3_QM_VAR_INIT
#endif

/******************************************************************
 * DSPR Memory Map : Core3 ASIL Data Section
 * ****************************************************************/
#ifdef CSC_PLATFORM_START_SEC_DSPR_CORE3_ASIL_VAR_INIT
  #undef CSC_PLATFORM_START_SEC_DSPR_CORE3_ASIL_VAR_INIT                        
  #define MEMMAP_COMMON_START_SEC_DSPR_CORE3_ASIL_VAR_INIT                            
#endif
#ifdef CSC_PLATFORM_STOP_SEC_DSPR_CORE3_ASIL_VAR_INIT
  #undef CSC_PLATFORM_STOP_SEC_DSPR_CORE3_ASIL_VAR_INIT                        
  #define MEMMAP_COMMON_STOP_SEC_DSPR_CORE3_ASIL_VAR_INIT
#endif

/******************************************************************
 * PSPR Memory Map : Core0 QM Data Section
 * ****************************************************************/
#ifdef CSC_PLATFORM_START_SEC_PSPR_CORE0_QM_VAR_INIT
  #undef CSC_PLATFORM_START_SEC_PSPR_CORE0_QM_VAR_INIT                        
  #define MEMMAP_COMMON_START_SEC_PSPR_CORE0_QM_VAR_INIT                            
#endif
#ifdef CSC_PLATFORM_STOP_SEC_PSPR_CORE0_QM_VAR_INIT
  #undef CSC_PLATFORM_STOP_SEC_PSPR_CORE0_QM_VAR_INIT                        
  #define MEMMAP_COMMON_STOP_SEC_PSPR_CORE0_QM_VAR_INIT
#endif

/******************************************************************
 * PSPR Memory Map : Core0 ASIL Data Section
 * ****************************************************************/
#ifdef CSC_PLATFORM_START_SEC_PSPR_CORE0_ASIL_VAR_INIT
  #undef CSC_PLATFORM_START_SEC_PSPR_CORE0_ASIL_VAR_INIT                        
  #define MEMMAP_COMMON_START_SEC_PSPR_CORE0_ASIL_VAR_INIT                            
#endif
#ifdef CSC_PLATFORM_STOP_SEC_PSPR_CORE0_ASIL_VAR_INIT
  #undef CSC_PLATFORM_STOP_SEC_PSPR_CORE0_ASIL_VAR_INIT                        
  #define MEMMAP_COMMON_STOP_SEC_PSPR_CORE0_ASIL_VAR_INIT
#endif

/******************************************************************
 * PSPR Memory Map : Core1 QM Data Section
 * ****************************************************************/
#ifdef CSC_PLATFORM_START_SEC_PSPR_CORE1_QM_VAR_INIT
  #undef CSC_PLATFORM_START_SEC_PSPR_CORE1_QM_VAR_INIT                        
  #define MEMMAP_COMMON_START_SEC_PSPR_CORE1_QM_VAR_INIT                            
#endif
#ifdef CSC_PLATFORM_STOP_SEC_PSPR_CORE1_QM_VAR_INIT
  #undef CSC_PLATFORM_STOP_SEC_PSPR_CORE1_QM_VAR_INIT                        
  #define MEMMAP_COMMON_STOP_SEC_PSPR_CORE1_QM_VAR_INIT
#endif

/******************************************************************
 * PSPR Memory Map : Core1 ASIL Data Section
 * ****************************************************************/
#ifdef CSC_PLATFORM_START_SEC_PSPR_CORE1_ASIL_VAR_INIT
  #undef CSC_PLATFORM_START_SEC_PSPR_CORE1_ASIL_VAR_INIT                        
  #define MEMMAP_COMMON_START_SEC_PSPR_CORE1_ASIL_VAR_INIT                            
#endif
#ifdef CSC_PLATFORM_STOP_SEC_PSPR_CORE1_ASIL_VAR_INIT
  #undef CSC_PLATFORM_STOP_SEC_PSPR_CORE1_ASIL_VAR_INIT                        
  #define MEMMAP_COMMON_STOP_SEC_PSPR_CORE1_ASIL_VAR_INIT
#endif

/******************************************************************
 * PSPR Memory Map : Core2 QM Data Section
 * ****************************************************************/
#ifdef CSC_PLATFORM_START_SEC_PSPR_CORE2_QM_VAR_INIT
  #undef CSC_PLATFORM_START_SEC_PSPR_CORE2_QM_VAR_INIT                        
  #define MEMMAP_COMMON_START_SEC_PSPR_CORE2_QM_VAR_INIT                            
#endif
#ifdef CSC_PLATFORM_STOP_SEC_PSPR_CORE2_QM_VAR_INIT
  #undef CSC_PLATFORM_STOP_SEC_PSPR_CORE2_QM_VAR_INIT                        
  #define MEMMAP_COMMON_STOP_SEC_PSPR_CORE2_QM_VAR_INIT
#endif

/******************************************************************
 * PSPR Memory Map : Core2 ASIL Data Section
 * ****************************************************************/
#ifdef CSC_PLATFORM_START_SEC_PSPR_CORE2_ASIL_VAR_INIT
  #undef CSC_PLATFORM_START_SEC_PSPR_CORE2_ASIL_VAR_INIT                        
  #define MEMMAP_COMMON_START_SEC_PSPR_CORE2_ASIL_VAR_INIT                            
#endif
#ifdef CSC_PLATFORM_STOP_SEC_PSPR_CORE2_ASIL_VAR_INIT
  #undef CSC_PLATFORM_STOP_SEC_PSPR_CORE2_ASIL_VAR_INIT                        
  #define MEMMAP_COMMON_STOP_SEC_PSPR_CORE2_ASIL_VAR_INIT
#endif

/******************************************************************
 * PSPR Memory Map : Core3 QM Data Section
 * ****************************************************************/
#ifdef CSC_PLATFORM_START_SEC_PSPR_CORE3_QM_VAR_INIT
  #undef CSC_PLATFORM_START_SEC_PSPR_CORE3_QM_VAR_INIT                        
  #define MEMMAP_COMMON_START_SEC_PSPR_CORE3_QM_VAR_INIT                            
#endif
#ifdef CSC_PLATFORM_STOP_SEC_PSPR_CORE3_QM_VAR_INIT
  #undef CSC_PLATFORM_STOP_SEC_PSPR_CORE3_QM_VAR_INIT                        
  #define MEMMAP_COMMON_STOP_SEC_PSPR_CORE3_QM_VAR_INIT
#endif

/******************************************************************
 * PSPR Memory Map : Core3 ASIL Data Section
 * ****************************************************************/
#ifdef CSC_PLATFORM_START_SEC_PSPR_CORE3_ASIL_VAR_INIT
  #undef CSC_PLATFORM_START_SEC_PSPR_CORE3_ASIL_VAR_INIT                        
  #define MEMMAP_COMMON_START_SEC_PSPR_CORE3_ASIL_VAR_INIT                            
#endif
#ifdef CSC_PLATFORM_STOP_SEC_PSPR_CORE3_ASIL_VAR_INIT
  #undef CSC_PLATFORM_STOP_SEC_PSPR_CORE3_ASIL_VAR_INIT                        
  #define MEMMAP_COMMON_STOP_SEC_PSPR_CORE3_ASIL_VAR_INIT
#endif


#include "MemMap_Common.h"

