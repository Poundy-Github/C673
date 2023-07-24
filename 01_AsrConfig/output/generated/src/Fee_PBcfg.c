/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2021)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME    : Fee_PBCfg.c                                                 **
**                                                                            **
**  VERSION     : 12.0.0                                                      **
**                                                                            **
**  DATE, TIME  : 2023-06-28, 11:21:43   !!!IGNORE-LINE!!!                **
**                                                                            **
**  GENERATOR   : Build b211016-0103                                        **
**                                                                            **
**  BSW MODULE DECRIPTION : Fee.bmd                                           **
**                                                                            **
**  VARIANT     : Variant PB                                                  **
**                                                                            **
**  PLATFORM    : Infineon AURIX2G                                            **
**                                                                            **
**  AUTHOR      : DL-AUTOSAR-Engineering                                      **
**                                                                            **
**  VENDOR      : Infineon Technologies                                       **
**                                                                            **
**  DESCRIPTION :  Fee configuration generated out of ECUC file               **
**                                                                            **
**  SPECIFICATION(S) : Specification of Fee Driver,                           **
**                     AUTOSAR Release 4.2.2 and 4.4.0                        **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/


/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
/* Include Fee Module Header File */
#include "Fee.h"
/*******************************************************************************
**                      Imported Compiler Switch Checks                       **
*******************************************************************************/

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/

/* Job End Notification Function */
extern void QS_JobEndNotification(void);
/* Job Error Notification Function */
extern void QS_JobErrorNotification(void);
/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/
/* Allocate space for state data variables in RAM */
#define FEE_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED
/*MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
without safegaurd. It complies to Autosar guidelines. */
/*MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar
guideline. */
#include "Fee_MemMap.h"

/* Fee State Variable structure */
/*MISRA2012_RULE_8_7_JUSTIFICATION: Fee_StateVar has not been declared as static
as this structure is being passed to the Fee.c file. It has scope beyond the 
file.*/
/*MISRA2012_RULE_8_4_JUSTIFICATION: MISRA is assuming as a function but it 
branches out as assembly equivalent or compiler routine..*/
Fee_StateDataType Fee_StateVar;
#define FEE_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED
/*MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
without safegaurd. It complies to Autosar guidelines. */
/*MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar
guideline. */
#include "Fee_MemMap.h"


/* User configured logical block initialization structure */
#define FEE_START_SEC_CONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED
/*MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
without safegaurd. It complies to Autosar guidelines. */
/*MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar
guideline. */
#include "Fee_MemMap.h"
/*[cover parentID={01870B59-CB19-45ea-8F7F-F16AC029FB7A}][/cover]*/ 
static const Fee_BlockType Fee_BlockConfig[] =
{
  {
    16777215U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA, /* Block type is Immediate */
    16U, /* Block number */
    4U, /* Fee Block Size */
    0x00U, /* Fee Block address */
    0U, /* Fee Block instance */
    FEE_NVM_USER /* Fee quasi/NVM manager */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    16777215U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA, /* Block type is Immediate */
    17U, /* Block number */
    4U, /* Fee Block Size */
    0x00U, /* Fee Block address */
    0U, /* Fee Block instance */
    FEE_NVM_USER /* Fee quasi/NVM manager */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    16777215U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    32U, /* Block number */
    644U, /* Fee Block Size */
    0x00U, /* Fee Block address */
    0U, /* Fee Block instance */
    FEE_NVM_USER /* Fee quasi/NVM manager */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    16777215U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    48U, /* Block number */
    68U, /* Fee Block Size */
    0x00U, /* Fee Block address */
    0U, /* Fee Block instance */
    FEE_NVM_USER /* Fee quasi/NVM manager */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    16777215U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    49U, /* Block number */
    68U, /* Fee Block Size */
    0x00U, /* Fee Block address */
    0U, /* Fee Block instance */
    FEE_NVM_USER /* Fee quasi/NVM manager */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    16777215U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    50U, /* Block number */
    68U, /* Fee Block Size */
    0x00U, /* Fee Block address */
    0U, /* Fee Block instance */
    FEE_NVM_USER /* Fee quasi/NVM manager */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    16777215U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    51U, /* Block number */
    68U, /* Fee Block Size */
    0x00U, /* Fee Block address */
    0U, /* Fee Block instance */
    FEE_NVM_USER /* Fee quasi/NVM manager */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    16777215U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    52U, /* Block number */
    68U, /* Fee Block Size */
    0x00U, /* Fee Block address */
    0U, /* Fee Block instance */
    FEE_NVM_USER /* Fee quasi/NVM manager */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    16777215U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    53U, /* Block number */
    68U, /* Fee Block Size */
    0x00U, /* Fee Block address */
    0U, /* Fee Block instance */
    FEE_NVM_USER /* Fee quasi/NVM manager */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    16777215U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    54U, /* Block number */
    68U, /* Fee Block Size */
    0x00U, /* Fee Block address */
    0U, /* Fee Block instance */
    FEE_NVM_USER /* Fee quasi/NVM manager */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    16777215U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    55U, /* Block number */
    68U, /* Fee Block Size */
    0x00U, /* Fee Block address */
    0U, /* Fee Block instance */
    FEE_NVM_USER /* Fee quasi/NVM manager */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    16777215U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    56U, /* Block number */
    68U, /* Fee Block Size */
    0x00U, /* Fee Block address */
    0U, /* Fee Block instance */
    FEE_NVM_USER /* Fee quasi/NVM manager */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    16777215U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    57U, /* Block number */
    68U, /* Fee Block Size */
    0x00U, /* Fee Block address */
    0U, /* Fee Block instance */
    FEE_NVM_USER /* Fee quasi/NVM manager */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    16777215U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    58U, /* Block number */
    68U, /* Fee Block Size */
    0x00U, /* Fee Block address */
    0U, /* Fee Block instance */
    FEE_NVM_USER /* Fee quasi/NVM manager */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    16777215U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    59U, /* Block number */
    68U, /* Fee Block Size */
    0x00U, /* Fee Block address */
    0U, /* Fee Block instance */
    FEE_NVM_USER /* Fee quasi/NVM manager */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    16777215U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    60U, /* Block number */
    68U, /* Fee Block Size */
    0x00U, /* Fee Block address */
    0U, /* Fee Block instance */
    FEE_NVM_USER /* Fee quasi/NVM manager */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    16777215U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    61U, /* Block number */
    68U, /* Fee Block Size */
    0x00U, /* Fee Block address */
    0U, /* Fee Block instance */
    FEE_NVM_USER /* Fee quasi/NVM manager */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    16777215U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    62U, /* Block number */
    68U, /* Fee Block Size */
    0x00U, /* Fee Block address */
    0U, /* Fee Block instance */
    FEE_NVM_USER /* Fee quasi/NVM manager */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    16777215U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    63U, /* Block number */
    68U, /* Fee Block Size */
    0x00U, /* Fee Block address */
    0U, /* Fee Block instance */
    FEE_NVM_USER /* Fee quasi/NVM manager */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    16777215U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA, /* Block type is Immediate */
    64U, /* Block number */
    17U, /* Fee Block Size */
    0x00U, /* Fee Block address */
    0U, /* Fee Block instance */
    FEE_NVM_USER /* Fee quasi/NVM manager */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    16777215U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA, /* Block type is Immediate */
    80U, /* Block number */
    10U, /* Fee Block Size */
    0x00U, /* Fee Block address */
    0U, /* Fee Block instance */
    FEE_NVM_USER /* Fee quasi/NVM manager */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    16777215U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA, /* Block type is Immediate */
    96U, /* Block number */
    15U, /* Fee Block Size */
    0x00U, /* Fee Block address */
    0U, /* Fee Block instance */
    FEE_NVM_USER /* Fee quasi/NVM manager */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    16777215U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA, /* Block type is Immediate */
    112U, /* Block number */
    1U, /* Fee Block Size */
    0x00U, /* Fee Block address */
    0U, /* Fee Block instance */
    FEE_NVM_USER /* Fee quasi/NVM manager */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    16777215U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA, /* Block type is Immediate */
    128U, /* Block number */
    1U, /* Fee Block Size */
    0x00U, /* Fee Block address */
    0U, /* Fee Block instance */
    FEE_NVM_USER /* Fee quasi/NVM manager */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    16777215U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA, /* Block type is Immediate */
    144U, /* Block number */
    1U, /* Fee Block Size */
    0x00U, /* Fee Block address */
    0U, /* Fee Block instance */
    FEE_NVM_USER /* Fee quasi/NVM manager */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    16777215U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA, /* Block type is Immediate */
    160U, /* Block number */
    4U, /* Fee Block Size */
    0x00U, /* Fee Block address */
    0U, /* Fee Block instance */
    FEE_NVM_USER /* Fee quasi/NVM manager */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    16777215U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    256U, /* Block number */
    11U, /* Fee Block Size */
    0x00U, /* Fee Block address */
    0U, /* Fee Block instance */
    FEE_NVM_USER /* Fee quasi/NVM manager */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    16777215U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA, /* Block type is Immediate */
    272U, /* Block number */
    3U, /* Fee Block Size */
    0x00U, /* Fee Block address */
    0U, /* Fee Block instance */
    FEE_NVM_USER /* Fee quasi/NVM manager */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    16777215U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA, /* Block type is Immediate */
    288U, /* Block number */
    7U, /* Fee Block Size */
    0x00U, /* Fee Block address */
    0U, /* Fee Block instance */
    FEE_NVM_USER /* Fee quasi/NVM manager */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    16777215U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA, /* Block type is Immediate */
    304U, /* Block number */
    5U, /* Fee Block Size */
    0x00U, /* Fee Block address */
    0U, /* Fee Block instance */
    FEE_NVM_USER /* Fee quasi/NVM manager */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    16777215U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA, /* Block type is Immediate */
    320U, /* Block number */
    22U, /* Fee Block Size */
    0x00U, /* Fee Block address */
    0U, /* Fee Block instance */
    FEE_NVM_USER /* Fee quasi/NVM manager */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    16777215U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA, /* Block type is Immediate */
    336U, /* Block number */
    3U, /* Fee Block Size */
    0x00U, /* Fee Block address */
    0U, /* Fee Block instance */
    FEE_NVM_USER /* Fee quasi/NVM manager */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    16777215U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA, /* Block type is Immediate */
    352U, /* Block number */
    8U, /* Fee Block Size */
    0x00U, /* Fee Block address */
    0U, /* Fee Block instance */
    FEE_NVM_USER /* Fee quasi/NVM manager */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    16777215U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA, /* Block type is Immediate */
    368U, /* Block number */
    9U, /* Fee Block Size */
    0x00U, /* Fee Block address */
    0U, /* Fee Block instance */
    FEE_NVM_USER /* Fee quasi/NVM manager */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    16777215U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA, /* Block type is Immediate */
    384U, /* Block number */
    49U, /* Fee Block Size */
    0x00U, /* Fee Block address */
    0U, /* Fee Block instance */
    FEE_NVM_USER /* Fee quasi/NVM manager */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    16777215U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA, /* Block type is Immediate */
    400U, /* Block number */
    49U, /* Fee Block Size */
    0x00U, /* Fee Block address */
    0U, /* Fee Block instance */
    FEE_NVM_USER /* Fee quasi/NVM manager */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    16777215U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA, /* Block type is Immediate */
    416U, /* Block number */
    49U, /* Fee Block Size */
    0x00U, /* Fee Block address */
    0U, /* Fee Block instance */
    FEE_NVM_USER /* Fee quasi/NVM manager */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    16777215U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA, /* Block type is Immediate */
    432U, /* Block number */
    49U, /* Fee Block Size */
    0x00U, /* Fee Block address */
    0U, /* Fee Block instance */
    FEE_NVM_USER /* Fee quasi/NVM manager */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    16777215U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA, /* Block type is Immediate */
    448U, /* Block number */
    49U, /* Fee Block Size */
    0x00U, /* Fee Block address */
    0U, /* Fee Block instance */
    FEE_NVM_USER /* Fee quasi/NVM manager */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    16777215U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA, /* Block type is Immediate */
    464U, /* Block number */
    49U, /* Fee Block Size */
    0x00U, /* Fee Block address */
    0U, /* Fee Block instance */
    FEE_NVM_USER /* Fee quasi/NVM manager */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    10000U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA, /* Block type is Immediate */
    480U, /* Block number */
    108U, /* Fee Block Size */
    0x00U, /* Fee Block address */
    0U, /* Fee Block instance */
    FEE_NVM_USER /* Fee quasi/NVM manager */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    16777215U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    496U, /* Block number */
    164U, /* Fee Block Size */
    0x00U, /* Fee Block address */
    0U, /* Fee Block instance */
    FEE_NVM_USER /* Fee quasi/NVM manager */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  { 
    16777215U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,     /* Block typeQS is Normal */
    176U, /* Block number */
    4096U, /* Fee Block Size */
    503808U, /* Fee Block address */
    1U, /* Fee Block instance */
    FEE_QUASI_STATIC_USER /* Fee quasi manager */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable 
to the initializer {0} which may be used to initialize an aggregate. 
Here it is defined as enum and first element initialized to 0.
*/
  },
  { 
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,     /* Block typeQS is Normal */
    192U, /* Block number */
    4096U, /* Fee Block Size */
    507904U, /* Fee Block address */
    1U, /* Fee Block instance */
    FEE_QUASI_STATIC_USER /* Fee quasi manager */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable 
to the initializer {0} which may be used to initialize an aggregate. 
Here it is defined as enum and first element initialized to 0.
*/
  },
  { 
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,     /* Block typeQS is Normal */
    208U, /* Block number */
    4096U, /* Fee Block Size */
    512000U, /* Fee Block address */
    1U, /* Fee Block instance */
    FEE_QUASI_STATIC_USER /* Fee quasi manager */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable 
to the initializer {0} which may be used to initialize an aggregate. 
Here it is defined as enum and first element initialized to 0.
*/
  },
  { 
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,     /* Block typeQS is Normal */
    224U, /* Block number */
    4096U, /* Fee Block Size */
    516096U, /* Fee Block address */
    1U, /* Fee Block instance */
    FEE_QUASI_STATIC_USER /* Fee quasi manager */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable 
to the initializer {0} which may be used to initialize an aggregate. 
Here it is defined as enum and first element initialized to 0.
*/
  },
  { 
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,     /* Block typeQS is Normal */
    240U, /* Block number */
    4096U, /* Fee Block Size */
    520192U, /* Fee Block address */
    1U, /* Fee Block instance */
    FEE_QUASI_STATIC_USER /* Fee quasi manager */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable 
to the initializer {0} which may be used to initialize an aggregate. 
Here it is defined as enum and first element initialized to 0.
*/
  },
};
const Fee_ConfigType Fee_Config =
{  
  /* Fee State Data Structure */
  &Fee_StateVar,
  /* Pointer to logical block configurations */
  &Fee_BlockConfig[0],

  /* Fee Job end notification API */
  &NvM_JobEndNotification,

  /* Fee Job error notification API */
  &NvM_JobErrorNotification,

  /* Fee QS Job end notification API */
  &QS_JobEndNotification,

  /* Fee QS Job error notification API */
  &QS_JobErrorNotification,
  /* Fee threshold value */
  200U,
  /* Number of blocks configured */
  47U,
  {
    /* Ignore the unconfigured blocks */
    FEE_UNCONFIG_BLOCK_IGNORE,
    /* Restart Garbage Collection during initialization */
    FEE_GC_RESTART_INIT,
    /* Erase Suspend feature is disabled */
    FEE_ERASE_SUSPEND_DISABLED,
    
    /* Reserved */
    0U
  },


/*MISRA2012_RULE_11_3_JUSTIFICATION: Pointers are accessing the correct memory 
range locations. Out of bounds checks were checked during functional verification. */
  
  /* Fee NVM Illegal State notification */
  (Fee_NotifFunctionPtrType)NULL_PTR,

/*MISRA2012_RULE_11_3_JUSTIFICATION: Pointers are accessing the correct memory 
range locations. Out of bounds checks were checked during functional verification. */
  
  /* Fee QS Illegal State notification */
  (Fee_NotifFunctionPtrType)NULL_PTR,
/*MISRA2012_RULE_11_3_JUSTIFICATION: Pointers are accessing the correct memory 
range locations. Out of bounds checks were checked during functional verification. */
  /* QS Hardening Error notification */
  (Fee_NotifFunctionPtrType)NULL_PTR,
  /* Erase All feature is disabled */
  (boolean)FALSE


};

#define FEE_STOP_SEC_CONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED
/*MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
without safegaurd. It complies to Autosar guidelines. */
/*MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar
guideline. */
#include "Fee_MemMap.h"
