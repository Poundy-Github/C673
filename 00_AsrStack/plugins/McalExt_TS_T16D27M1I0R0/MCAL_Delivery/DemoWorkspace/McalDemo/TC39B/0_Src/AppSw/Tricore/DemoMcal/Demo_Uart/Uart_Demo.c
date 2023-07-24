/******************************************************************************
**                                                                           **
** Copyright (C) Infineon Technologies (2016)                                **
**                                                                           **
** All rights reserved.                                                      **
**                                                                           **
** This document contains proprietary information belonging to Infineon      **
** Technologies. Passing on and copying of this document, and communication  **
** of its contents is not permitted without prior written authorization.     **
**                                                                           **
*******************************************************************************
**                                                                           **
**  FILENAME   : Uart_Demo.c                                                 **
**                                                                           **
**  VERSION    : 0.0.2                                                       **
**                                                                           **
**  DATE       : 2019-07-16                                                  **
**                                                                           **
**  VARIANT    : NA                                                          **
**                                                                           **
**  PLATFORM   : Infineon AURIX2G                                            **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains                                         **
**                - Demo application for Uart driver                         **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: Yes                                     **
**                                                                           **
******************************************************************************/

/******************************************************************************
**                      Includes                                             **
******************************************************************************/
#include "Std_Types.h"

// #include "Ifx_reg.h"
#include "IfxAsclin_reg.h"
#include "IfxSrc_reg.h"

#include "Test_Print.h"
#include "Test_Time.h"
#include "DemoApp_Cfg.h"
#include "Irq.h"
#include "Uart.h"
#include "Uart_Demo.h"

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

#define UART_NINE_BIT_DATA_MASK   (0x01FFU)
#define UART_TX_DATA_COUNT        (20U)
#define UART_MAX_DATA_COUNT       (200U)
#define UART_CHANNEL_Id           (0U)
#define UART_SRC_SET_SRE          (1U)

/*******************************************************************************
**                      Private Variable Declarations                         **
*******************************************************************************/

extern const Uart_ConfigType Uart_Config;

#define UART_START_SEC_CONST_ASIL_B_LOCAL_32
#include "Uart_MemMap.h"

#if ((defined UART_NINEBITS_USED ) && (UART_NINEBITS_USED == STD_ON))
const uint16 Uart_TxDataBuff[52] = \
{
  0x1111, 0x2222, 0x3333, 0x4444, 0x5555, 0x6666, 0x7777, 0x8888, 0x9999, 0x11AA,
  0xAAAA, 0xBBBB, 0xCCCC, 0xDDDD, 0xEEEE, 0xFFFF, 0xAABB, 0xCCDD, 0xEEFF, 0xAAFF,
  0x1234, 0x2345, 0x3456, 0x4567, 0x5678, 0x6789, 0x789A, 0x89AB, 0x9ABC, 0xABCD,
  0xBCDE, 0xCDEF, 0x22BB, 0x33CC, 0x44DD, 0x55EE, 0x66FF, 0x7788, 0x8899, 0x99AA,
  0x1111, 0x2222, 0x3333, 0x4444, 0x5555, 0x6666, 0x7777, 0x8888, 0x9999, 0x11AA, 0, 0
};
#else
const uint8 Uart_TxDataBuff[208] = \
{ 'I', 'n', 'f', 'i', 'n', 'e', 'o', 'n', 't'
  , 'e', 'c', 'h', 'n', 'o', 'l', 'o', 'g', 'i',
  'e', 's', 'p', 'r', 'i', 'v', 'a', 't', 'e',
  'l', 'i', 'm', 'i', 't', 'e', 'd', 'b', 'a',
  'n', 'g', 'a', 'l', 'o', 'r', 'e','I', 'n', 
  'f', 'i', 'n', 'e', 'o', 'n', 't', 'e', 'c',
  'h', 'n', 'o', 'l', 'o', 'g', 'i','e', 's', 
  'p', 'r', 'i', 'v', 'a', 't', 'e','l', 'i', 
  'm', 'i', 't', 'e', 'd', 'b', 'a','n', 'g',
  'a', 'l', 'o', 'r', 'e','I', 'n', 'f', 'i', 
  'e', 'c', 'h', 'n', 'o', 'l', 'o', 'g', 'i',
  'e', 's', 'p', 'r', 'i', 'v', 'a', 't', 'e',
  'l', 'i', 'm', 'i', 't', 'e', 'd', 'b', 'a',
  'n', 'g', 'a', 'l', 'o', 'r', 'e','I', 'n', 
  'f', 'i', 'n', 'e', 'o', 'n', 't', 'e', 'c',
  'h', 'n', 'o', 'l', 'o', 'g', 'i','e', 's', 
  'p', 'r', 'i', 'v', 'a', 't', 'e','l', 'i', 
  'm', 'i', 't', 'e', 'd', 'b', 'a','n', 'g',
  'a', 'l', 'o', 'r', 'e','n', 'e', 'o', 'n', 't'
};
#endif

#define UART_STOP_SEC_CONST_ASIL_B_LOCAL_32
#include "Uart_MemMap.h"

#if ((defined UART_NINEBITS_USED ) && (UART_NINEBITS_USED == STD_ON))
uint16 Uart_RxDataBuff[52];
#else
uint8 Uart_RxDataBuff[208];
#endif

/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/

/******************************************************************************/
/********************Function to validate the recieved data********************/
/******************************************************************************/
uint8 UartDemo_ValidateData(uint16 UartRxDataCnt)
{
  uint16 idx;
  uint8 RsltDataCheck = 0;

  #if ((defined UART_NINEBITS_USED ) && (UART_NINEBITS_USED == STD_ON))
  UartRxDataCnt = UartRxDataCnt / 2;
  #endif

  for(idx = 0; idx < UartRxDataCnt; idx++)
  {
    /*Compare Data Read with the Data Written for the Channel*/
	#if ((defined UART_NINEBITS_USED ) && (UART_NINEBITS_USED == STD_ON))
    if((Uart_TxDataBuff[idx] & UART_NINE_BIT_DATA_MASK) == \
        Uart_RxDataBuff[idx])
    #else
    if(Uart_TxDataBuff[idx] == Uart_RxDataBuff[idx])
    #endif
    {
      RsltDataCheck = 0;
    }
    else
    {
      RsltDataCheck = 1;
      break;
    }
  }

  /*Clear the App Rx Data Buffer for Next Operation*/
  for(idx = 0; idx < UartRxDataCnt; idx++)
  {
    Uart_RxDataBuff[idx] = 0;
  }

  return RsltDataCheck;
}

/******************************************************************************/
/********************Function to Get the UART Channel Status*******************/
/******************************************************************************/
void UartDemo_GetChStatus()
{
  Uart_StatusType ChStatus;

  ChStatus = Uart_GetStatus(UART_CHANNEL_Id);

  switch (ChStatus)
  {
    case UART_IDLE:
    {
      print_f("\n--------------- Uart Channel 0 is IDLE ---------------\n");
      StartResult();
      print_f("Result = Pass;");
      EndResult();
      break;
    }
    default:
    {
      print_f("\n--------------- Uart Channel 0 is BUSY ---------------\n");
      break;
    }
  }
}

/******************************************************************************/
/********************Function to Transmit and Recieve Data and Validate it*****/
/******************************************************************************/
void UartDemo_ReadWrite()
{
  Uart_ReturnType RetReadApi, RetWriteApi;
  uint8 DataCheck;
  Uart_StatusType ChStatus;
  Uart_SizeType TxDataCount = UART_TX_DATA_COUNT;
  volatile uint16 idx;

  print_f("\n---------- Calling Read function [Channel 0 to read %d bytes] \
  ----------\n", TxDataCount);

  RetReadApi = Uart_Read(UART_CHANNEL_Id, (Uart_MemType*)Uart_RxDataBuff, TxDataCount);

  if (RetReadApi == UART_E_OK)
  {
    print_f("\n Read Operation Initiated successfully \n");
  }
  else
  {
    print_f("\n Read Operation Initiation was unsuccessful \n");
  }

  print_f("\n--------- Calling Write function [Channel 0 to Write %d bytes] \
  -----------\n", TxDataCount);

  RetWriteApi = Uart_Write(UART_CHANNEL_Id, (Uart_MemType*)Uart_TxDataBuff, TxDataCount);

  if (RetWriteApi == UART_E_OK)
  {
    print_f("\n Write Operation Initiated successfully \n");
  }
  else
  {
    print_f("\n Write Operation Initiation was unsuccessful \n");
  }

  do
  {
    ChStatus = Uart_GetStatus(UART_CHANNEL_Id);
  } while(ChStatus != UART_IDLE);

  for(idx = 0; idx < 10000; idx++)
  {}

  DataCheck = UartDemo_ValidateData(TxDataCount);

  if (DataCheck == 0)
  {
    print_f("\n Data Transfer is SUCCESSFULL \n");
    UartDemo_GetChStatus();
  }
  else
  {
    print_f("\n Data Transfer is UNSUCCESSFULL \n");
  }

}

/******************************************************************************/
/******* Function to Get Data Transfer Info(Data Txd/Rxd before Last
         Abort Api Call)****************/
/******************************************************************************/
void UartDemo_GetDataTxnInfo()
{
  #if (UART_ABORT_WRITE_API == STD_ON)
  Uart_SizeType  RetAbortWrite;
  #endif

  #if (UART_ABORT_READ_API == STD_ON)
  Uart_SizeType RetAbortRead;
  #endif

  #if (UART_ABORT_WRITE_API == STD_ON)
  print_f("\n--------------- Calling AbortWrite function ---------------\n");

  RetAbortWrite = Uart_AbortWrite(UART_CHANNEL_Id);

  print_f("\n Number of bytes transmitted before Aborting the\
  Write Operation= %d \n", RetAbortWrite);
  #endif

  #if (UART_ABORT_READ_API == STD_ON)
  print_f("\n--------------- Calling AbortRead function ---------------\n");

  RetAbortRead = Uart_AbortRead(UART_CHANNEL_Id);

  print_f("\n Number of bytes received before Aborting the\
  Read Operation= %d \n", RetAbortRead);
  #endif

  UartDemo_GetChStatus();
}

/******************************************************************************/
/*****************Function to Abort On-Going Data Transmission and Reception***/
/******************************************************************************/
void UartDemo_AbortReadWrite()
{
  Uart_ReturnType RetReadApi, RetWriteApi;
  Uart_SizeType TxDataCount,RxDataCount;

  #if (UART_ABORT_WRITE_API == STD_ON)
  Uart_SizeType  RetAbortWrite;
  #endif

  #if (UART_ABORT_READ_API == STD_ON)
  Uart_SizeType RetAbortRead;
  #endif

  TxDataCount = UART_MAX_DATA_COUNT;
  RxDataCount = UART_MAX_DATA_COUNT;

  print_f("\n------------ Calling Read function ------------\n");

  RetReadApi = Uart_Read(UART_CHANNEL_Id, (Uart_MemType*)Uart_RxDataBuff, RxDataCount);

  if (RetReadApi == UART_E_OK)
  {
    print_f("\n Read Operation Initiated Successfully \n");
  }
  else
  {
    print_f("\n Read function call is not Successful \n");
  }

  print_f("\n------------ Calling Write function ------------\n");

  RetWriteApi = Uart_Write(UART_CHANNEL_Id, (Uart_MemType*)Uart_TxDataBuff, TxDataCount);
  
  Timer_DelayMs(10);

  #if (UART_ABORT_WRITE_API == STD_ON)
  RetAbortWrite = Uart_AbortWrite(UART_CHANNEL_Id);
  #endif

  Timer_DelayMs(10);

  #if (UART_ABORT_READ_API == STD_ON)
  RetAbortRead = Uart_AbortRead(UART_CHANNEL_Id);
  #endif

  if(RetWriteApi == UART_E_OK)
  {
    print_f("\n Initiated UART Write Operation of %d bytes \n", TxDataCount);
    StartResult();
    print_f("Result = Pass;");
    EndResult();
  }
  else if(RetWriteApi == UART_E_NOT_OK)
  {
    print_f("\n UART Write Operation UNSUCCESSFUL \n");
  }
  else if(RetWriteApi == UART_E_BUSY)
  {
    print_f("\n UART Write Operation couldn't be Initiated as UART HW \
              is BUSY with some other Operation \n");
  }

  #if (UART_ABORT_WRITE_API == STD_ON)

  print_f("\n ABORT WRITE SUCCESSFUL :Bytes Transmitted before\
   aborting the operation = %d \n", RetAbortWrite);

  #endif

  #if (UART_ABORT_READ_API == STD_ON)

  print_f("\n ABORT READ SUCCESSFUL :Bytes Received before\
   aborting the operation = %d \n", RetAbortRead);

  #endif
}

/******************************************************************************/
/******************************** UART Driver Demo  ***************************/
/******************************************************************************/

void Uart_Demo()
{
  char szString[80];
  uint8 UartLoopVar = 0;
  const Uart_ConfigType * ConfigPtr = NULL;
  ConfigPtr = &Uart_Config;
  Uart_Init(ConfigPtr);
  IrqAsclin_Init();

  SRC_ASCLIN2TX.B.SRE = UART_SRC_SET_SRE;
  SRC_ASCLIN2RX.B.SRE = UART_SRC_SET_SRE;
  SRC_ASCLIN2ERR.B.SRE = UART_SRC_SET_SRE;

  do
  {
    print_f("\n\n");
    print_f("\n/***********************************************************");
    print_f("*************/\n");
    print_f("\n                 UART DRIVER DEMOAPP MENU                 \n");
    print_f("                      ENTER YOUR OPTION                       ");
    print_f("\n     <1>  Get UART Channel Status                           ");
    print_f("\n     <2>  Transmit and Receive Data on the UART Channel     ");
    print_f("\n     <3>  Abort After Data Transmission and Reception       ");
    print_f("\n     <4>  Abort On-Going Data Transmission and Reception    ");
    print_f("\n     <.>  Back To Main Menu                                 ");
    print_f("\n/***********************************************************");
    print_f("*************/\n");
    print_f("Enter Your Option: ");

    getline(szString, sizeof szString - 1);
    print_f("\n\n");

    switch (*szString)
    {
      case '1':
      {
        UartDemo_GetChStatus();
        break;
      }

      case '2':
      {
        UartDemo_ReadWrite();
        break;
      }

      case '3':
      {
        UartDemo_GetDataTxnInfo();
        break;
      }

      case '4':
      {
        UartDemo_AbortReadWrite();
        break;
      }

      case '.':
      {
        UartLoopVar = 1;
        break;
      }
    }
  } while(UartLoopVar == 0);

  print_f("\n---------------  End of UART Driver Demo ---------------\n");
}
