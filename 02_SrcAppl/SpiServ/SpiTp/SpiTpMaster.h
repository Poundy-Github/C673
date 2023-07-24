//
// Copyright 2020 Horizon Robotics.
//

#ifndef SPITPMASTER_H_
#define SPITPMASTER_H_

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/
#include "common_platform.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/
 //#define SPITP_CRC16
/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/
typedef enum {
  SPITP_E_OK = 0,
  SPITP_E_NOT_OK,
  SPITP_E_PARAM_POINTER,
  SPITP_E_PARAM_LENGTH,
  SPITP_E_UNINIT
} SpiTp_RetType;

typedef enum {
  SPITP_STATE_UNINIT = 0,
  SPITP_STATE_INIT
} SpiTp_StateType;

enum {
  SPITP_FAULT_INJECT_NONE = 0,
  SPITP_FAULT_INJECT_SEND_RDY,
  SPITP_FAULT_INJECT_RECV_RDY,
  SPITP_FAULT_INJECT_TP_START,
  SPITP_FAULT_INJECT_TP_CONSECUTIVE,
  SPITP_FAULT_INJECT_TP_END,
  SPITP_FAULT_INJECT_DL_RC,
  SPITP_FAULT_INJECT_DL_CHK,
  SPITP_FAULT_INJECT_SPLIT_SIZE
};



/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*------------------------------Global variables------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*-------------------------Function Prototypes--------------------------------*/
/******************************************************************************/
extern void SpiTp_MasterInit(void);
extern void SpiTp_MasterDeInit(void);
extern void SpiTp_MasterMainFunction(void);
extern SpiTp_RetType SpiTp_masterSend(const uint8 *data, uint16 length);
extern uint16 SpiTp_masterRecieve(uint8 *data);
extern void SpiTp_setFailInject(uint8 fail);
extern boolean SpiTp_RxMsgIsUpdated(void);

extern uint32 ServiceSpi_GetCrc(void);
extern uint32 ServiceSpi_Getrc(void);

#endif  // SPITPMASTER_H_
