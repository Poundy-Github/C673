/******************************************************************************
**                                                                           **
** Copyright (C) Infineon Technologies (2019)                                **
**                                                                           **
** All rights reserved.                                                      **
**                                                                           **
** This document contains proprietary information belonging to Infineon      **
** Technologies. Passing on and copying of this document, and communication  **
** of its contents is not permitted without prior written authorization.     **
**                                                                           **
*******************************************************************************
**                                                                           **
**  FILENAME   : EthTrcv_Cbk.c                                            **
**                                                                           **
**  CC VERSION :  1.0.0                                                         **
**                                                                           **
**  $DATE       : 2019-07-01                                              **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains                                         **
**                Implementation of ETH interface callback functions         **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: Yes                                     **
**                                                                           **
******************************************************************************/

#include "EthTrcv_Cbk.h"
#if (APP_SW == TEST_APP)
#include "Test_EthTrcv_Cbk.h"
#endif /*#if (APP_SW == TEST_APP)*/

void EthTrcv_WriteMiiIndication( uint8 CtrlIdx, uint8 TrcvIdx, uint8 RegIdx )
{
  #if (APP_SW == TEST_APP)
  Test_EthTrcv_WriteMiiIndication(CtrlIdx,TrcvIdx,RegIdx);
  #endif /*#if (APP_SW == TEST_APP)*/
}

void EthTrcv_ReadMiiIndication( uint8 CtrlIdx, uint8 TrcvIdx, uint8 RegIdx, uint8 RegVal )
{
  #if (APP_SW == TEST_APP)
  Test_EthTrcv_ReadMiiIndication(CtrlIdx,TrcvIdx,RegIdx,RegVal);
  #endif /*#if (APP_SW == TEST_APP)*/
}
