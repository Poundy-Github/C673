/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2018)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME  : Spi_MemMap.h                                                  **
**                                                                            **
**  VERSION   :                                                               **
**                                                                            **
**  DATE      :                                                               **
**                                                                            **
**  VARIANT   : NA                                                            **
**                                                                            **
**  PLATFORM  : Infineon AURIX2G                                              **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  TRACEABILITY :                                                            **
**                                                                            **
**  DESCRIPTION  : This file contains the mapping of Memory Section           **
**                                                                            **
**  [/cover]                                                                  **
**                                                                            **
**  SPECIFICATION(S) : Specification of SPI Driver,                           **
**   AUTOSAR Release <4.2.2>                                                  **
**                                                                            **
**  MAY BE CHANGED BY USER : Yes                                              **
**                                                                            **
*******************************************************************************/
#define MEMMAP_ERROR
#if ((APP_SW == DEMO_APP) || (APP_SW == TEST_APP))
/*DATA Section*/
/*To be used for all global or static variables.*/
/*Variable to be cleared at startup or reset is palced here - .bss*/
#if defined SPI_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
#ifdef _TASKING_C_TRICORE_
#pragma section farbss "ClearedData.LmuNC.32bit"
#pragma align 4
#pragma section_name_with_symbol on
#elif defined _GNU_C_TRICORE_
#pragma section "ClearedData.LmuNC.32bit" aw 4
#elif defined _GHS_C_TRICORE_
#pragma ghs section bss = ".ClearedData.LmuNC.32bit"

#elif defined _DIABDATA_C_TRICORE_
#pragma section DATA "InitData.LmuNC.32bit" "ClearedData.LmuNC.32bit" far-absolute RW
#pragma align_variables 4
#endif
#undef  SPI_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
#undef MEMMAP_ERROR
#elif defined SPI_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
#ifdef _TASKING_C_TRICORE_
#pragma align restore
#pragma section farbss restore
#pragma section_name_with_symbol off
#elif defined _GNU_C_TRICORE_
#pragma section
#elif defined _GHS_C_TRICORE_
#pragma ghs section
#elif defined _DIABDATA_C_TRICORE_
#pragma align_variables
#pragma section 
#endif
#undef  SPI_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
#undef MEMMAP_ERROR

#elif defined SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE0_32
#ifdef _TASKING_C_TRICORE_
#pragma section farbss "ClearedData.Cpu0.32bit"
#pragma align 4
#pragma section_name_with_symbol on
#elif defined _GNU_C_TRICORE_
#pragma section "ClearedData.Cpu0.32bit" aw 4
#elif defined _GHS_C_TRICORE_
#pragma ghs section bss = ".ClearedData.Cpu0.32bit"

#elif defined _DIABDATA_C_TRICORE_
#pragma section DATA "InitData.Cpu0.32bit" "ClearedData.Cpu0.32bit" far-absolute RW
#pragma align_variables 4
#endif
#undef  SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE0_32
#undef MEMMAP_ERROR
#elif defined SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE0_32
#ifdef _TASKING_C_TRICORE_
#pragma align restore
#pragma section farbss restore
#pragma section_name_with_symbol off
#elif defined _GNU_C_TRICORE_
#pragma section
#elif defined _GHS_C_TRICORE_
#pragma ghs section
#elif defined _DIABDATA_C_TRICORE_
#pragma align_variables
#pragma section 
#endif
#undef  SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE0_32
#undef MEMMAP_ERROR

#elif defined SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE1_32
#ifdef _TASKING_C_TRICORE_
#pragma section farbss "ClearedData.Cpu1.32bit"
#pragma align 4
#pragma section_name_with_symbol on
#elif defined _GNU_C_TRICORE_
#pragma section "ClearedData.Cpu1.32bit" aw 4
#elif defined _GHS_C_TRICORE_
#pragma ghs section bss = ".ClearedData.Cpu1.32bit"

#elif defined _DIABDATA_C_TRICORE_
#pragma section DATA "InitData.Cpu1.32bit" "ClearedData.Cpu1.32bit" far-absolute RW
#pragma align_variables 4
#endif
#undef  SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE1_32
#undef MEMMAP_ERROR
#elif defined SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE1_32
#ifdef _TASKING_C_TRICORE_
#pragma align restore
#pragma section farbss restore
#pragma section_name_with_symbol off
#elif defined _GNU_C_TRICORE_
#pragma section
#elif defined _GHS_C_TRICORE_
#pragma ghs section
#elif defined _DIABDATA_C_TRICORE_
#pragma align_variables
#pragma section 
#endif
#undef  SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE1_32
#undef MEMMAP_ERROR

#elif defined SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE2_32
#ifdef _TASKING_C_TRICORE_
#pragma section farbss "ClearedData.Cpu2.32bit"
#pragma align 4
#pragma section_name_with_symbol on
#elif defined _GNU_C_TRICORE_
#pragma section "ClearedData.Cpu2.32bit" aw 4
#elif defined _GHS_C_TRICORE_
#pragma ghs section bss = ".ClearedData.Cpu2.32bit"

#elif defined _DIABDATA_C_TRICORE_
#pragma section DATA "InitData.Cpu2.32bit" "ClearedData.Cpu2.32bit" far-absolute RW
#pragma align_variables 4
#endif
#undef  SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE2_32
#undef MEMMAP_ERROR
#elif defined SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE2_32
#ifdef _TASKING_C_TRICORE_
#pragma align restore
#pragma section farbss restore
#pragma section_name_with_symbol off
#elif defined _GNU_C_TRICORE_
#pragma section
#elif defined _GHS_C_TRICORE_
#pragma ghs section
#elif defined _DIABDATA_C_TRICORE_
#pragma align_variables
#pragma section 
#endif
#undef  SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE2_32
#undef MEMMAP_ERROR

#elif defined SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE3_32
#ifdef _TASKING_C_TRICORE_
#pragma section farbss "ClearedData.Cpu3.32bit"
#pragma align 4
#pragma section_name_with_symbol on
#elif defined _GNU_C_TRICORE_
#pragma section "ClearedData.Cpu3.32bit" aw 4
#elif defined _GHS_C_TRICORE_
#pragma ghs section bss = ".ClearedData.Cpu3.32bit"

#elif defined _DIABDATA_C_TRICORE_
#pragma section DATA "InitData.Cpu3.32bit" "ClearedData.Cpu3.32bit" far-absolute RW
#pragma align_variables 4
#endif
#undef  SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE3_32
#undef MEMMAP_ERROR
#elif defined SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE3_32
#ifdef _TASKING_C_TRICORE_
#pragma align restore
#pragma section farbss restore
#pragma section_name_with_symbol off
#elif defined _GNU_C_TRICORE_
#pragma section
#elif defined _GHS_C_TRICORE_
#pragma ghs section
#elif defined _DIABDATA_C_TRICORE_
#pragma align_variables
#pragma section 
#endif
#undef  SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE3_32
#undef MEMMAP_ERROR

#elif defined SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE4_32
#ifdef _TASKING_C_TRICORE_
#pragma section farbss "ClearedData.Cpu4.32bit"
#pragma align 4
#pragma section_name_with_symbol on
#elif defined _GNU_C_TRICORE_
#pragma section "ClearedData.Cpu4.32bit" aw 4
#elif defined _GHS_C_TRICORE_
#pragma ghs section bss = ".ClearedData.Cpu4.32bit"

#elif defined _DIABDATA_C_TRICORE_
#pragma section DATA "InitData.Cpu4.32bit" "ClearedData.Cpu4.32bit" far-absolute RW
#pragma align_variables 4
#endif
#undef  SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE4_32
#undef MEMMAP_ERROR
#elif defined SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE4_32
#ifdef _TASKING_C_TRICORE_
#pragma align restore
#pragma section farbss restore
#pragma section_name_with_symbol off
#elif defined _GNU_C_TRICORE_
#pragma section
#elif defined _GHS_C_TRICORE_
#pragma ghs section
#elif defined _DIABDATA_C_TRICORE_
#pragma align_variables
#pragma section 
#endif
#undef  SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE4_32
#undef MEMMAP_ERROR

#elif defined SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE5_32
#ifdef _TASKING_C_TRICORE_
#pragma section farbss "ClearedData.Cpu5.32bit"
#pragma align 4
#pragma section_name_with_symbol on
#elif defined _GNU_C_TRICORE_
#pragma section "ClearedData.Cpu5.32bit" aw 4
#elif defined _GHS_C_TRICORE_
#pragma ghs section bss = ".ClearedData.Cpu5.32bit"

#elif defined _DIABDATA_C_TRICORE_
#pragma section DATA "InitData.Cpu5.32bit" "ClearedData.Cpu5.32bit" far-absolute RW
#pragma align_variables 4
#endif
#undef  SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE5_32
#undef MEMMAP_ERROR
#elif defined SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE5_32
#ifdef _TASKING_C_TRICORE_
#pragma align restore
#pragma section farbss restore
#pragma section_name_with_symbol off
#elif defined _GNU_C_TRICORE_
#pragma section
#elif defined _GHS_C_TRICORE_
#pragma ghs section
#elif defined _DIABDATA_C_TRICORE_
#pragma align_variables
#pragma section 
#endif
#undef  SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE5_32
#undef MEMMAP_ERROR

#elif defined SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE0_256
#ifdef _TASKING_C_TRICORE_
#pragma section farbss "ClearedData.Cpu0.256bit"
#pragma align 32
#pragma section_name_with_symbol on
#elif defined _GNU_C_TRICORE_
#pragma section "ClearedData.Cpu0.256bit" aw 32
#elif defined _GHS_C_TRICORE_
#pragma ghs section bss = ".ClearedData.Cpu0.256bit"

#elif defined _DIABDATA_C_TRICORE_
#pragma section DATA "InitData.Cpu0.256bit" "ClearedData.Cpu0.256bit" far-absolute RW
#pragma align_variables 32
#endif
#undef  SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE0_256
#undef MEMMAP_ERROR
#elif defined SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE0_256
#ifdef _TASKING_C_TRICORE_
#pragma align restore
#pragma section farbss restore
#pragma section_name_with_symbol off
#elif defined _GNU_C_TRICORE_
#pragma section
#elif defined _GHS_C_TRICORE_
#pragma ghs section
#elif defined _DIABDATA_C_TRICORE_
#pragma align_variables
#pragma section 
#endif
#undef  SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE0_256
#undef MEMMAP_ERROR

#elif defined SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE1_256
#ifdef _TASKING_C_TRICORE_
#pragma section farbss "ClearedData.Cpu1.256bit"
#pragma align 32
#pragma section_name_with_symbol on
#elif defined _GNU_C_TRICORE_
#pragma section "ClearedData.Cpu1.256bit" aw 32
#elif defined _GHS_C_TRICORE_
#pragma ghs section bss = ".ClearedData.Cpu1.256bit"

#elif defined _DIABDATA_C_TRICORE_
#pragma section DATA "InitData.Cpu1.256bit" "ClearedData.Cpu1.256bit" far-absolute RW
#pragma align_variables 32
#endif
#undef  SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE1_256
#undef MEMMAP_ERROR
#elif defined SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE1_256
#ifdef _TASKING_C_TRICORE_
#pragma align restore
#pragma section farbss restore
#pragma section_name_with_symbol off
#elif defined _GNU_C_TRICORE_
#pragma section
#elif defined _GHS_C_TRICORE_
#pragma ghs section
#elif defined _DIABDATA_C_TRICORE_
#pragma align_variables
#pragma section 
#endif
#undef  SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE1_256
#undef MEMMAP_ERROR

#elif defined SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE2_256
#ifdef _TASKING_C_TRICORE_
#pragma section farbss "ClearedData.Cpu2.256bit"
#pragma align 32
#pragma section_name_with_symbol on
#elif defined _GNU_C_TRICORE_
#pragma section "ClearedData.Cpu2.256bit" aw 32
#elif defined _GHS_C_TRICORE_
#pragma ghs section bss = ".ClearedData.Cpu2.256bit"

#elif defined _DIABDATA_C_TRICORE_
#pragma section DATA "InitData.Cpu2.256bit" "ClearedData.Cpu2.256bit" far-absolute RW
#pragma align_variables 32
#endif
#undef  SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE2_256
#undef MEMMAP_ERROR
#elif defined SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE2_256
#ifdef _TASKING_C_TRICORE_
#pragma align restore
#pragma section farbss restore
#pragma section_name_with_symbol off
#elif defined _GNU_C_TRICORE_
#pragma section
#elif defined _GHS_C_TRICORE_
#pragma ghs section
#elif defined _DIABDATA_C_TRICORE_
#pragma align_variables
#pragma section 
#endif
#undef  SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE2_256
#undef MEMMAP_ERROR

#elif defined SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE3_256
#ifdef _TASKING_C_TRICORE_
#pragma section farbss "ClearedData.Cpu3.256bit"
#pragma align 32
#pragma section_name_with_symbol on
#elif defined _GNU_C_TRICORE_
#pragma section "ClearedData.Cpu3.256bit" aw 32
#elif defined _GHS_C_TRICORE_
#pragma ghs section bss = ".ClearedData.Cpu3.256bit"

#elif defined _DIABDATA_C_TRICORE_
#pragma section DATA "InitData.Cpu3.256bit" "ClearedData.Cpu3.256bit" far-absolute RW
#pragma align_variables 32
#endif
#undef  SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE3_256
#undef MEMMAP_ERROR
#elif defined SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE3_256
#ifdef _TASKING_C_TRICORE_
#pragma align restore
#pragma section farbss restore
#pragma section_name_with_symbol off
#elif defined _GNU_C_TRICORE_
#pragma section
#elif defined _GHS_C_TRICORE_
#pragma ghs section
#elif defined _DIABDATA_C_TRICORE_
#pragma align_variables
#pragma section 
#endif
#undef  SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE3_256
#undef MEMMAP_ERROR

#elif defined SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE4_256
#ifdef _TASKING_C_TRICORE_
#pragma section farbss "ClearedData.Cpu4.256bit"
#pragma align 32
#pragma section_name_with_symbol on
#elif defined _GNU_C_TRICORE_
#pragma section "ClearedData.Cpu4.256bit" aw 32
#elif defined _GHS_C_TRICORE_
#pragma ghs section bss = ".ClearedData.Cpu4.256bit"

#elif defined _DIABDATA_C_TRICORE_
#pragma section DATA "InitData.Cpu4.256bit" "ClearedData.Cpu4.256bit" far-absolute RW
#pragma align_variables 32
#endif
#undef  SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE4_256
#undef MEMMAP_ERROR
#elif defined SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE4_256
#ifdef _TASKING_C_TRICORE_
#pragma align restore
#pragma section farbss restore
#pragma section_name_with_symbol off
#elif defined _GNU_C_TRICORE_
#pragma section
#elif defined _GHS_C_TRICORE_
#pragma ghs section
#elif defined _DIABDATA_C_TRICORE_
#pragma align_variables
#pragma section 
#endif
#undef  SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE4_256
#undef MEMMAP_ERROR

#elif defined SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE5_256
#ifdef _TASKING_C_TRICORE_
#pragma section farbss "ClearedData.Cpu5.256bit"
#pragma align 32
#pragma section_name_with_symbol on
#elif defined _GNU_C_TRICORE_
#pragma section "ClearedData.Cpu5.256bit" aw 32
#elif defined _GHS_C_TRICORE_
#pragma ghs section bss = ".ClearedData.Cpu5.256bit"

#elif defined _DIABDATA_C_TRICORE_
#pragma section DATA "InitData.Cpu5.256bit" "ClearedData.Cpu5.256bit" far-absolute RW
#pragma align_variables 32
#endif
#undef  SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE5_256
#undef MEMMAP_ERROR
#elif defined SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE5_256
#ifdef _TASKING_C_TRICORE_
#pragma align restore
#pragma section farbss restore
#pragma section_name_with_symbol off
#elif defined _GNU_C_TRICORE_
#pragma section
#elif defined _GHS_C_TRICORE_
#pragma ghs section
#elif defined _DIABDATA_C_TRICORE_
#pragma align_variables
#pragma section 
#endif
#undef  SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE5_256
#undef MEMMAP_ERROR

#elif defined SPI_START_SEC_VAR_INIT_ASIL_B_GLOBAL_8
#ifdef _TASKING_C_TRICORE_
#pragma section fardata "InitData.LmuNC.8bit"
#pragma section_name_with_symbol on
#elif defined _GNU_C_TRICORE_
#pragma section "InitData.LmuNC.8bit" aw
#elif defined _GHS_C_TRICORE_
#pragma ghs section data = ".InitData.LmuNC.8bit"
#elif defined _DIABDATA_C_TRICORE_
#pragma section DATA "InitData.LmuNC.8bit"  "ClearedData.LmuNC.8bit" far-absolute RW
#endif
#undef  SPI_START_SEC_VAR_INIT_ASIL_B_GLOBAL_8
#undef MEMMAP_ERROR
#elif defined SPI_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_8
#ifdef _TASKING_C_TRICORE_
#pragma section fardata restore
#pragma section_name_with_symbol off
#elif defined _GNU_C_TRICORE_
#pragma section
#elif defined _GHS_C_TRICORE_
#pragma ghs section
#elif defined _DIABDATA_C_TRICORE_
#pragma section 
#endif
#undef  SPI_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_8
#undef MEMMAP_ERROR

#elif defined SPI_START_SEC_VAR_INIT_ASIL_B_GLOBAL_16
#ifdef _TASKING_C_TRICORE_
#pragma section fardata "InitData.LmuNC.16bit"
#pragma align 2
#pragma section_name_with_symbol on
#elif defined _GNU_C_TRICORE_
#pragma section "InitData.LmuNC.16bit" aw 2
#elif defined _GHS_C_TRICORE_
#pragma ghs section data = ".InitData.LmuNC.16bit"

#elif defined _DIABDATA_C_TRICORE_
#pragma section DATA "InitData.LmuNC.16bit"  "ClearedData.LmuNC.16bit" far-absolute RW
#pragma align_variables 2
#endif
#undef  SPI_START_SEC_VAR_INIT_ASIL_B_GLOBAL_16
#undef MEMMAP_ERROR
#elif defined SPI_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_16
#ifdef _TASKING_C_TRICORE_
#pragma align restore
#pragma section fardata restore
#pragma section_name_with_symbol off
#elif defined _GNU_C_TRICORE_
#pragma section
#elif defined _GHS_C_TRICORE_
#pragma ghs section
#elif defined _DIABDATA_C_TRICORE_
#pragma align_variables
#pragma section 
#endif
#undef  SPI_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_16
#undef MEMMAP_ERROR

#elif defined SPI_START_SEC_VAR_INIT_ASIL_B_GLOBAL_32
#ifdef _TASKING_C_TRICORE_
#pragma section fardata "InitData.LmuNC.32bit"
#pragma align 4
#pragma section_name_with_symbol on
#elif defined _GNU_C_TRICORE_
#pragma section "InitData.LmuNC.32bit" aw 4
#elif defined _GHS_C_TRICORE_
#pragma ghs section data = ".InitData.LmuNC.32bit"

#elif defined _DIABDATA_C_TRICORE_
#pragma section DATA "InitData.LmuNC.32bit"  "ClearedData.LmuNC.32bit" far-absolute RW
#pragma align_variables 4
#endif
#undef  SPI_START_SEC_VAR_INIT_ASIL_B_GLOBAL_32
#undef MEMMAP_ERROR
#elif defined SPI_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_32
#ifdef _TASKING_C_TRICORE_
#pragma align restore
#pragma section fardata restore
#pragma section_name_with_symbol off
#elif defined _GNU_C_TRICORE_
#pragma section
#elif defined _GHS_C_TRICORE_
#pragma ghs section
#elif defined _DIABDATA_C_TRICORE_
#pragma align_variables
#pragma section 
#endif
#undef  SPI_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_32
#undef MEMMAP_ERROR

#elif defined SPI_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_8
#ifdef _TASKING_C_TRICORE_
#pragma section farbss "ClearedData.LmuNC.8bit"
#pragma section_name_with_symbol on
#elif defined _GNU_C_TRICORE_
#pragma section "ClearedData.LmuNC.8bit" aw
#elif defined _GHS_C_TRICORE_
#pragma ghs section bss = ".ClearedData.LmuNC.8bit"
#elif defined _DIABDATA_C_TRICORE_
#pragma section DATA "InitData.LmuNC.8bit" "ClearedData.LmuNC.8bit" far-absolute RW
#endif
#undef  SPI_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_8
#undef MEMMAP_ERROR
#elif defined SPI_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_8
#ifdef _TASKING_C_TRICORE_
#pragma section farbss restore
#pragma section_name_with_symbol off
#elif defined _GNU_C_TRICORE_
#pragma section
#elif defined _GHS_C_TRICORE_
#pragma ghs section
#elif defined _DIABDATA_C_TRICORE_
#pragma section 
#endif
#undef  SPI_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_8
#undef MEMMAP_ERROR

#elif defined SPI_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_16
#ifdef _TASKING_C_TRICORE_
#pragma section farbss "ClearedData.LmuNC.16bit"
#pragma align 2
#pragma section_name_with_symbol on
#elif defined _GNU_C_TRICORE_
#pragma section "ClearedData.LmuNC.16bit" aw 2
#elif defined _GHS_C_TRICORE_
#pragma ghs section bss = ".ClearedData.LmuNC.16bit"

#elif defined _DIABDATA_C_TRICORE_
#pragma section DATA "InitData.LmuNC.16bit" "ClearedData.LmuNC.16bit" far-absolute RW
#pragma align_variables 2
#endif
#undef  SPI_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_16
#undef MEMMAP_ERROR
#elif defined SPI_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_16
#ifdef _TASKING_C_TRICORE_
#pragma align restore
#pragma section farbss restore
#pragma section_name_with_symbol off
#elif defined _GNU_C_TRICORE_
#pragma section
#elif defined _GHS_C_TRICORE_
#pragma ghs section
#elif defined _DIABDATA_C_TRICORE_
#pragma align_variables
#pragma section 
#endif
#undef  SPI_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_16
#undef MEMMAP_ERROR

/******************* Config Data Sections *************************/
#elif defined SPI_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_32
#ifdef _TASKING_C_TRICORE_
#pragma section farrom "Config.Cpu0.32bit"
#pragma align 4
#pragma section_name_with_symbol on
#elif defined _GNU_C_TRICORE_
#pragma section "Config.Cpu0.32bit" a 4
#elif defined _GHS_C_TRICORE_
#pragma ghs section rodata = ".Config.Cpu0.32bit"

#elif defined _DIABDATA_C_TRICORE_
#pragma section CONST "Config.Cpu0.32bit" far-absolute R
#pragma align_variables 4
#endif
#undef  SPI_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_32
#undef MEMMAP_ERROR
#elif defined SPI_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_32
#ifdef _TASKING_C_TRICORE_
#pragma align restore
#pragma section farrom restore
#pragma section_name_with_symbol off
#elif defined _GNU_C_TRICORE_
#pragma section
#elif defined _GHS_C_TRICORE_
#pragma ghs section
#elif defined _DIABDATA_C_TRICORE_
#pragma align_variables
#pragma section 
#endif
#undef  SPI_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_32
#undef MEMMAP_ERROR

#elif defined SPI_START_SEC_CONFIG_DATA_ASIL_B_CORE0_32
#ifdef _TASKING_C_TRICORE_
#pragma section farrom "Config.Cpu0.32bit"
#pragma align 4
#pragma section_name_with_symbol on
#elif defined _GNU_C_TRICORE_
#pragma section "Config.Cpu0.32bit" a 4
#elif defined _GHS_C_TRICORE_
#pragma ghs section rodata = ".Config.Cpu0.32bit"

#elif defined _DIABDATA_C_TRICORE_
#pragma section CONST "Config.Cpu0.32bit" far-absolute R
#pragma align_variables 4
#endif
#undef  SPI_START_SEC_CONFIG_DATA_ASIL_B_CORE0_32
#undef MEMMAP_ERROR
#elif defined SPI_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_32
#ifdef _TASKING_C_TRICORE_
#pragma align restore
#pragma section farrom restore
#pragma section_name_with_symbol off
#elif defined _GNU_C_TRICORE_
#pragma section
#elif defined _GHS_C_TRICORE_
#pragma ghs section
#elif defined _DIABDATA_C_TRICORE_
#pragma align_variables
#pragma section 
#endif
#undef  SPI_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_32
#undef MEMMAP_ERROR

#elif defined SPI_START_SEC_CONFIG_DATA_ASIL_B_CORE1_32
#ifdef _TASKING_C_TRICORE_
#pragma section farrom "Config.Cpu1.32bit"
#pragma align 4
#pragma section_name_with_symbol on
#elif defined _GNU_C_TRICORE_
#pragma section "Config.Cpu1.32bit" a 4
#elif defined _GHS_C_TRICORE_
#pragma ghs section rodata = ".Config.Cpu1.32bit"

#elif defined _DIABDATA_C_TRICORE_
#pragma section CONST "Config.Cpu1.32bit" far-absolute R
#pragma align_variables 4
#endif
#undef  SPI_START_SEC_CONFIG_DATA_ASIL_B_CORE1_32
#undef MEMMAP_ERROR
#elif defined SPI_STOP_SEC_CONFIG_DATA_ASIL_B_CORE1_32
#ifdef _TASKING_C_TRICORE_
#pragma align restore
#pragma section farrom restore
#pragma section_name_with_symbol off
#elif defined _GNU_C_TRICORE_
#pragma section
#elif defined _GHS_C_TRICORE_
#pragma ghs section
#elif defined _DIABDATA_C_TRICORE_
#pragma align_variables
#pragma section 
#endif
#undef  SPI_STOP_SEC_CONFIG_DATA_ASIL_B_CORE1_32
#undef MEMMAP_ERROR

#elif defined SPI_START_SEC_CONFIG_DATA_ASIL_B_CORE2_32
#ifdef _TASKING_C_TRICORE_
#pragma section farrom "Config.Cpu2.32bit"
#pragma align 4
#pragma section_name_with_symbol on
#elif defined _GNU_C_TRICORE_
#pragma section "Config.Cpu2.32bit" a 4
#elif defined _GHS_C_TRICORE_
#pragma ghs section rodata = ".Config.Cpu2.32bit"

#elif defined _DIABDATA_C_TRICORE_
#pragma section CONST "Config.Cpu2.32bit" far-absolute R
#pragma align_variables 4
#endif
#undef  SPI_START_SEC_CONFIG_DATA_ASIL_B_CORE2_32
#undef MEMMAP_ERROR
#elif defined SPI_STOP_SEC_CONFIG_DATA_ASIL_B_CORE2_32
#ifdef _TASKING_C_TRICORE_
#pragma align restore
#pragma section farrom restore
#pragma section_name_with_symbol off
#elif defined _GNU_C_TRICORE_
#pragma section
#elif defined _GHS_C_TRICORE_
#pragma ghs section
#elif defined _DIABDATA_C_TRICORE_
#pragma align_variables
#pragma section 
#endif
#undef  SPI_STOP_SEC_CONFIG_DATA_ASIL_B_CORE2_32
#undef MEMMAP_ERROR

#elif defined SPI_START_SEC_CONFIG_DATA_ASIL_B_CORE3_32
#ifdef _TASKING_C_TRICORE_
#pragma section farrom "Config.Cpu3.32bit"
#pragma align 4
#pragma section_name_with_symbol on
#elif defined _GNU_C_TRICORE_
#pragma section "Config.Cpu3.32bit" a 4
#elif defined _GHS_C_TRICORE_
#pragma ghs section rodata = ".Config.Cpu3.32bit"

#elif defined _DIABDATA_C_TRICORE_
#pragma section CONST "Config.Cpu3.32bit" far-absolute R
#pragma align_variables 4
#endif
#undef  SPI_START_SEC_CONFIG_DATA_ASIL_B_CORE3_32
#undef MEMMAP_ERROR
#elif defined SPI_STOP_SEC_CONFIG_DATA_ASIL_B_CORE3_32
#ifdef _TASKING_C_TRICORE_
#pragma align restore
#pragma section farrom restore
#pragma section_name_with_symbol off
#elif defined _GNU_C_TRICORE_
#pragma section
#elif defined _GHS_C_TRICORE_
#pragma ghs section
#elif defined _DIABDATA_C_TRICORE_
#pragma align_variables
#pragma section 
#endif
#undef  SPI_STOP_SEC_CONFIG_DATA_ASIL_B_CORE3_32
#undef MEMMAP_ERROR

#elif defined SPI_START_SEC_CONFIG_DATA_ASIL_B_CORE4_32
#ifdef _TASKING_C_TRICORE_
#pragma section farrom "Config.Cpu4.32bit"
#pragma align 4
#pragma section_name_with_symbol on
#elif defined _GNU_C_TRICORE_
#pragma section "Config.Cpu4.32bit" a 4
#elif defined _GHS_C_TRICORE_
#pragma ghs section rodata = ".Config.Cpu4.32bit"

#elif defined _DIABDATA_C_TRICORE_
#pragma section CONST "Config.Cpu4.32bit" far-absolute R
#pragma align_variables 4
#endif
#undef  SPI_START_SEC_CONFIG_DATA_ASIL_B_CORE4_32
#undef MEMMAP_ERROR
#elif defined SPI_STOP_SEC_CONFIG_DATA_ASIL_B_CORE4_32
#ifdef _TASKING_C_TRICORE_
#pragma align restore
#pragma section farrom restore
#pragma section_name_with_symbol off
#elif defined _GNU_C_TRICORE_
#pragma section
#elif defined _GHS_C_TRICORE_
#pragma ghs section
#elif defined _DIABDATA_C_TRICORE_
#pragma align_variables
#pragma section 
#endif
#undef  SPI_STOP_SEC_CONFIG_DATA_ASIL_B_CORE4_32
#undef MEMMAP_ERROR

#elif defined SPI_START_SEC_CONFIG_DATA_ASIL_B_CORE5_32
#ifdef _TASKING_C_TRICORE_
#pragma section farrom "Config.Cpu5.32bit"
#pragma align 4
#pragma section_name_with_symbol on
#elif defined _GNU_C_TRICORE_
#pragma section "Config.Cpu5.32bit" a 4
#elif defined _GHS_C_TRICORE_
#pragma ghs section rodata = ".Config.Cpu5.32bit"

#elif defined _DIABDATA_C_TRICORE_
#pragma section CONST "Config.Cpu5.32bit" far-absolute R
#pragma align_variables 4
#endif
#undef  SPI_START_SEC_CONFIG_DATA_ASIL_B_CORE5_32
#undef MEMMAP_ERROR
#elif defined SPI_STOP_SEC_CONFIG_DATA_ASIL_B_CORE5_32
#ifdef _TASKING_C_TRICORE_
#pragma align restore
#pragma section farrom restore
#pragma section_name_with_symbol off
#elif defined _GNU_C_TRICORE_
#pragma section
#elif defined _GHS_C_TRICORE_
#pragma ghs section
#elif defined _DIABDATA_C_TRICORE_
#pragma align_variables
#pragma section 
#endif
#undef  SPI_STOP_SEC_CONFIG_DATA_ASIL_B_CORE5_32
#undef MEMMAP_ERROR

/* Code Sections */
/*
To be used for mapping code to application block, boot block, external flash etc.
codePeriod is the typical period time value and unit of the ExecutableEntitys in this MemorySection.
The name part _{codePeriod} is optional. Units are:
- US microseconds
- MS milli second
- S second
*/
#elif defined SPI_START_SEC_CODE_ASIL_B_GLOBAL
#ifdef _TASKING_C_TRICORE_
#pragma section code "Code.Cpu0"
#pragma section_name_with_symbol on
#elif defined _GNU_C_TRICORE_
#pragma section "Code.Cpu0" ax
#elif defined _GHS_C_TRICORE_
#pragma ghs section text = ".Code.Cpu0"
#elif defined _DIABDATA_C_TRICORE_
#pragma section CODE "Code.Cpu0" RX
#endif
#undef  SPI_START_SEC_CODE_ASIL_B_GLOBAL
#undef MEMMAP_ERROR
#elif defined SPI_STOP_SEC_CODE_ASIL_B_GLOBAL
#ifdef _TASKING_C_TRICORE_
#pragma section code restore
#pragma section_name_with_symbol off
#elif defined _GNU_C_TRICORE_
#pragma section
#elif defined _GHS_C_TRICORE_
#pragma ghs section
#elif defined _DIABDATA_C_TRICORE_
#pragma section 
#endif
#undef  SPI_STOP_SEC_CODE_ASIL_B_GLOBAL
#undef MEMMAP_ERROR

#endif

#else  /*#if ((APP_SW == DEMO_APP) || (APP_SW == TEST_APP))*/ 
/************************EMPTY SECTIONS***************************************/
#if defined SPI_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
#undef  SPI_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
#undef MEMMAP_ERROR
#elif defined SPI_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
#undef  SPI_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
#undef MEMMAP_ERROR
#elif defined SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE0_32
#undef  SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE0_32
#undef MEMMAP_ERROR
#elif defined SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE0_32
#undef  SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE0_32
#undef MEMMAP_ERROR
#elif defined SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE1_32
#undef  SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE1_32
#undef MEMMAP_ERROR
#elif defined SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE1_32
#undef  SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE1_32
#undef MEMMAP_ERROR
#elif defined SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE2_32
#undef  SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE2_32
#undef MEMMAP_ERROR
#elif defined SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE2_32
#undef  SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE2_32
#undef MEMMAP_ERROR
#elif defined SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE3_32
#undef  SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE3_32
#undef MEMMAP_ERROR
#elif defined SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE3_32
#undef  SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE3_32
#undef MEMMAP_ERROR
#elif defined SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE4_32
#undef  SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE4_32
#undef MEMMAP_ERROR
#elif defined SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE4_32
#undef  SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE4_32
#undef MEMMAP_ERROR
#elif defined SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE5_32
#undef  SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE5_32
#undef MEMMAP_ERROR
#elif defined SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE5_32
#undef  SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE5_32
#undef MEMMAP_ERROR
#elif defined SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE0_256
#undef  SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE0_256
#undef MEMMAP_ERROR
#elif defined SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE0_256
#undef  SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE0_256
#undef MEMMAP_ERROR
#elif defined SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE1_256
#undef  SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE1_256
#undef MEMMAP_ERROR
#elif defined SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE1_256
#undef  SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE1_256
#undef MEMMAP_ERROR
#elif defined SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE2_256
#undef  SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE2_256
#undef MEMMAP_ERROR
#elif defined SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE2_256
#undef  SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE2_256
#undef MEMMAP_ERROR
#elif defined SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE3_256
#undef  SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE3_256
#undef MEMMAP_ERROR
#elif defined SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE3_256
#undef  SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE3_256
#undef MEMMAP_ERROR
#elif defined SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE4_256
#undef  SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE4_256
#undef MEMMAP_ERROR
#elif defined SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE4_256
#undef  SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE4_256
#undef MEMMAP_ERROR
#elif defined SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE5_256
#undef  SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE5_256
#undef MEMMAP_ERROR
#elif defined SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE5_256
#undef  SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE5_256
#undef MEMMAP_ERROR
#elif defined SPI_START_SEC_VAR_INIT_ASIL_B_GLOBAL_8
#undef  SPI_START_SEC_VAR_INIT_ASIL_B_GLOBAL_8
#undef MEMMAP_ERROR
#elif defined SPI_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_8
#undef  SPI_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_8
#undef MEMMAP_ERROR
#elif defined SPI_START_SEC_VAR_INIT_ASIL_B_GLOBAL_16
#undef  SPI_START_SEC_VAR_INIT_ASIL_B_GLOBAL_16
#undef MEMMAP_ERROR
#elif defined SPI_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_16
#undef  SPI_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_16
#undef MEMMAP_ERROR
#elif defined SPI_START_SEC_VAR_INIT_ASIL_B_GLOBAL_32
#undef  SPI_START_SEC_VAR_INIT_ASIL_B_GLOBAL_32
#undef MEMMAP_ERROR
#elif defined SPI_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_32
#undef  SPI_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_32
#undef MEMMAP_ERROR
#elif defined SPI_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_8
#undef  SPI_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_8
#undef MEMMAP_ERROR
#elif defined SPI_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_8
#undef  SPI_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_8
#undef MEMMAP_ERROR
#elif defined SPI_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_16
#undef  SPI_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_16
#undef MEMMAP_ERROR
#elif defined SPI_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_16
#undef  SPI_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_16
#undef MEMMAP_ERROR
#elif defined SPI_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_32
#undef  SPI_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_32
#undef MEMMAP_ERROR
#elif defined SPI_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_32
#undef  SPI_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_32
#undef MEMMAP_ERROR
#elif defined SPI_START_SEC_CONFIG_DATA_ASIL_B_CORE0_32
#undef  SPI_START_SEC_CONFIG_DATA_ASIL_B_CORE0_32
#undef MEMMAP_ERROR
#elif defined SPI_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_32
#undef  SPI_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_32
#undef MEMMAP_ERROR
#elif defined SPI_START_SEC_CONFIG_DATA_ASIL_B_CORE1_32
#undef  SPI_START_SEC_CONFIG_DATA_ASIL_B_CORE1_32
#undef MEMMAP_ERROR
#elif defined SPI_STOP_SEC_CONFIG_DATA_ASIL_B_CORE1_32
#undef  SPI_STOP_SEC_CONFIG_DATA_ASIL_B_CORE1_32
#undef MEMMAP_ERROR
#elif defined SPI_START_SEC_CONFIG_DATA_ASIL_B_CORE2_32
#undef  SPI_START_SEC_CONFIG_DATA_ASIL_B_CORE2_32
#undef MEMMAP_ERROR
#elif defined SPI_STOP_SEC_CONFIG_DATA_ASIL_B_CORE2_32
#undef  SPI_STOP_SEC_CONFIG_DATA_ASIL_B_CORE2_32
#undef MEMMAP_ERROR
#elif defined SPI_START_SEC_CONFIG_DATA_ASIL_B_CORE3_32
#undef  SPI_START_SEC_CONFIG_DATA_ASIL_B_CORE3_32
#undef MEMMAP_ERROR
#elif defined SPI_STOP_SEC_CONFIG_DATA_ASIL_B_CORE3_32
#undef  SPI_STOP_SEC_CONFIG_DATA_ASIL_B_CORE3_32
#undef MEMMAP_ERROR
#elif defined SPI_START_SEC_CONFIG_DATA_ASIL_B_CORE4_32
#undef  SPI_START_SEC_CONFIG_DATA_ASIL_B_CORE4_32
#undef MEMMAP_ERROR
#elif defined SPI_STOP_SEC_CONFIG_DATA_ASIL_B_CORE4_32
#undef  SPI_STOP_SEC_CONFIG_DATA_ASIL_B_CORE4_32
#undef MEMMAP_ERROR
#elif defined SPI_START_SEC_CONFIG_DATA_ASIL_B_CORE5_32
#undef  SPI_START_SEC_CONFIG_DATA_ASIL_B_CORE5_32
#undef MEMMAP_ERROR
#elif defined SPI_STOP_SEC_CONFIG_DATA_ASIL_B_CORE5_32
#undef  SPI_STOP_SEC_CONFIG_DATA_ASIL_B_CORE5_32
#undef MEMMAP_ERROR
#elif defined SPI_START_SEC_CODE_ASIL_B_GLOBAL
#undef  SPI_START_SEC_CODE_ASIL_B_GLOBAL
#undef MEMMAP_ERROR
#elif defined SPI_STOP_SEC_CODE_ASIL_B_GLOBAL
#undef  SPI_STOP_SEC_CODE_ASIL_B_GLOBAL
#undef MEMMAP_ERROR
#endif

#endif /*#if ((APP_SW == DEMO_APP) || (APP_SW == TEST_APP))*/ 

#if defined MEMMAP_ERROR
#error "Spi_MemMap.h, wrong pragma command"
#endif
