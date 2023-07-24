/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2020)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME   : LinIf_Cbk.c                                                  **
**                                                                            **
**  VERSION    : 5.0.0                                                        **
**                                                                            **
**  DATE       : 2020-11-13                                                   **
**                                                                            **
**  VARIANT    : NA                                                           **
**                                                                            **
**  PLATFORM   : Infineon AURIX2G                                             **
**                                                                            **
**  AUTHOR      : DL-AUTOSAR-Engineering                                      **
**                                                                            **
**  VENDOR      : Infineon Technologies                                       **
**                                                                            **
**  DESCRIPTION : Implementation of LIN Interface (LinIf) callback functions  **
**                Note : This file is for Evaluation Purpose Only             **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: Yes                                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "LinIf_Cbk.h"
/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
#if (MCAL_AR_VERSION == MCAL_AR_422)
#define TEST_LIN_MODULE_ID      (82U)  /* 0x52 */
#endif
/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/
#if (MCAL_AR_VERSION == MCAL_AR_422)
#if((APP_SW == TEST_APP)&&(BASE_TEST_MODULE_ID == TEST_LIN_MODULE_ID))
extern void LinIfTest_WakeupConfirmation(EcuM_WakeupSourceType WakeupSource);
#endif
#endif
/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/

/*******************************************************************************
** Syntax : void LinIf_WakeupConfirmation( EcuM_WakeupSourceType WakeupSource)**
**                                                                            **
** Service ID: none                                                           **
**                                                                            **
** Sync/Async:  none                                                          **
**                                                                            **
** Reentrancy:  none                                                          **
**                                                                            **
** Parameters (in): none                                                      **
**                                                                            **
** Parameters (out):  none                                                    **
**                                                                            **
** Return value:  none                                                        **
**                                                                            **
** Description : This function is called in LIN Driver or                     **
**               LIN Transceiver Driver.                                      **
**                                                                            **
*******************************************************************************/
#if (MCAL_AR_VERSION == MCAL_AR_422)
void LinIf_WakeupConfirmation(EcuM_WakeupSourceType WakeupSource)
{
  #if((APP_SW == TEST_APP)&&(BASE_TEST_MODULE_ID == TEST_LIN_MODULE_ID))
  LinIfTest_WakeupConfirmation(WakeupSource);
  #endif
}
#endif
/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/
