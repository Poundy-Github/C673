//
// Copyright 2020 Horizon Robotics.
//

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/
#include "SpiTpMaster.h"
#include "hb_Memory.h"
#include "IfxStm_reg.h"
#include "Os_api.h"
/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/
#define SPITP_MASTER_POOL_SIZE 10u

#define SPITP_MASTER_SPLIT_SIZE 256u
#define SPITP_DL_HEADER_SIZE 4u
#define SPITP_TP_HEADER_FF_SIZE 4u
#define SPITP_TP_HEADER_CF_SIZE 2u
#define SPITP_MASTER_FIRST_FRAME_LENTH  \
        (SPITP_MASTER_SPLIT_SIZE -      \
         SPITP_DL_HEADER_SIZE -         \
         SPITP_TP_HEADER_FF_SIZE)
#define SPITP_MASTER_FRAME_LENTH        \
       (SPITP_MASTER_SPLIT_SIZE -       \
        SPITP_DL_HEADER_SIZE -          \
        SPITP_TP_HEADER_CF_SIZE)

#define SPITP_MASTER_DATA_MAX_SIZE 4096u
#define SPITP_MASTER_SYNC_CODE 0x47u

#define SPITP_MASTER_TRANSFER_TIMEOUT 100u

/* #pragma pack 2 */
/* Changed by Crazy, 20210219, "dataPtr" has alignment > 2 bytes */
typedef struct {
  uint8 head;
  uint8 tail;
  uint8 counter;
  uint16 length[SPITP_MASTER_POOL_SIZE];
  void *dataPtr[SPITP_MASTER_POOL_SIZE];
} SpiTpPoolType;

#pragma pack 2
typedef struct {
  uint8 start : 1;
  uint8 consecutive : 1;
  uint8 end : 1;
  uint8 reserve : 5;
  uint8 count : 8;
} SpiTpHeaderType;

typedef struct {
  uint8 sync;
  uint8 rc;
  uint16 chk;
} SpiDlHeaderType;

typedef struct {
  uint16 length;
  uint8 data[SPITP_MASTER_FIRST_FRAME_LENTH];
} SpiTpFstFrameType;

typedef struct {
  uint8 data[SPITP_MASTER_FRAME_LENTH];
} SpiTpFrameType;

typedef union {
  SpiTpFstFrameType first_frame;
  SpiTpFrameType frame;
} SpiTpDataType;

typedef struct {
  SpiDlHeaderType dl_header;
  SpiTpHeaderType tp_header;
  SpiTpDataType dl_frame;
} SpiTpBufType;
#pragma pack 0

typedef struct {
  uint8 curCnt;
  uint8 ttlCnt;
  uint16 length;
  SpiTpBufType buf;
} SpiTpBufInfoType;

typedef struct {
  uint8 curCnt;
  uint8 ttlCnt;
  uint8 start_flag;
  uint16 length;
  SpiTpBufType buf;
} SpiTpBufRxInfoType;

typedef struct {
  uint8 send;
  uint8 recv;
  uint8 preemptive;
  uint8 tx_rc;
  uint8 rx_rc;
  SpiTpBufInfoType txBuf;
  SpiTpBufRxInfoType rxBuf;
} SpiTpSpiBufType;

typedef struct {
  uint32 err_crc;
  uint32 err_rc;
  uint32 err_start;
  uint32 err_consecutive;
  uint32 err_end;
  uint32 err_tx_timeout;
} SpiTpErrStatisc_type;
/******************************************************************************/
/*------------------------------Global variables------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*------------------------------Static variables------------------------------*/
/******************************************************************************/
static uint8 SpiTp_masterState;
static uint8 * SpiTp_masterTxBuf;
static uint8 * SpiTp_masterRxBuf;
static SpiTpPoolType SpiTp_masterRxPool;
static SpiTpPoolType SpiTp_masterTxPool;

static SpiTpSpiBufType SpiTp_masterPtlInfo;


static uint32 SpiTp_masterTransTime;
static boolean SpiTp_masterTransTimeSetup;

static SpiTpErrStatisc_type SpiTp_errStatics;
static uint8 SpiTp_failInject;
static uint8 SpiTp_failInjectJ2;
/******************************************************************************/
/*-------------------------Function Prototypes--------------------------------*/
/******************************************************************************/
static void SpiTp_masterFrameConcrete(void);
static void SpiTp_masterRecvPars(void);
static void SpiTp_masterPreTransmit(const uint8 *data, uint16 length);
static void SpiTp_setTransmitState(boolean state);
static void SpiTp_setRecvState(boolean state);
static void SpiTp_masterTransmitConcrete(void);
static boolean SpiTp_getMasterTransferState(void);

static void SpiTp_masterInitPtlInfo(void);
static void SpiTp_masterBufferInit(void);
static boolean SpiTp_poolIsFull(SpiTpPoolType *pool);
static boolean SpiTp_poolIsEmpty(SpiTpPoolType *pool);
static SpiTp_RetType SpiTp_poolPush(SpiTpPoolType *pool, const uint8 *data,
                           uint16 length);
static void SpiTp_poolPop(SpiTpPoolType *pool);

static boolean SpiTp_getRecvState(void);
static boolean SpiTp_getTransmitState(void);

static void SpiTp_masterTransmit(void);

static void SpiTp_setTransTimer(void);
static void SpiTp_transTimerCheck(void);

static void SpiTp_masterTransferIntPreemp(void);

static void SpiTp_setIntPreemState(boolean state);
static boolean SpiTp_getIntPreemState(void);
static boolean SpiTp_intPreemCheck(void);
static uint16 SpiTp_offsetCalc(uint8 curCnt);
static uint8 SpiTp_masterCntCalc(uint16 length);
static void SpiTp_cancelMasterTransTimer(void);
#ifdef SPITP_CRC16
static uint16 SpiTp_CRC16_CCITT(uint8 *data, uint32 datalen);
#else
static uint16 SpiTp_Checksum16_Calc(uint8 *data, uint32 datalen);
#endif
static void InvertUint16(uint16 *dBuf, uint16 *srcBuf);
static void InvertUint8(uint8 *dBuf, uint8 *srcBuf);
static SpiTp_RetType SpiTp_masterDlCheck(SpiTpSpiBufType * info);
static SpiTp_RetType SpiTp_masterTpPackage(SpiTpBufRxInfoType * info);
static SpiTp_RetType SpiTp_masterTpCheck(SpiTpBufRxInfoType * info);
static void SpiTp_masterRecvCancel(void);
SpiTp_RetType SpiTp_poolCheckAll(SpiTpPoolType *pool);
/******************************************************************************/
/*-------------------------_Globale Function----------------------------------*/
/******************************************************************************/
void SpiTp_MasterInit(void) {
  SpiTp_masterInitPtlInfo();
  SpiTp_masterBufferInit();
  SpiTp_masterTxBuf = (uint8 *)(NULL_PTR);
  SpiTp_masterRxBuf = (uint8 *)(NULL_PTR);
  SpiTp_masterState = SPITP_STATE_INIT;
  SpiTp_masterTransTimeSetup = FALSE;
  hb_memset(&SpiTp_errStatics, 0, sizeof(SpiTp_errStatics));
  SpiTp_failInject = SPITP_FAULT_INJECT_NONE;
  SpiTp_failInjectJ2 = SPITP_FAULT_INJECT_NONE;
  return;
}

void SpiTp_MasterDeInit(void) {
  SpiTp_masterBufferInit();
  SpiTp_masterState = SPITP_STATE_UNINIT;
  SpiTp_failInject = SPITP_FAULT_INJECT_NONE;
  SpiTp_failInjectJ2 = SPITP_FAULT_INJECT_NONE;
  return;
}

void SpiTp_MasterMainFunction(void) {

  if (SpiTp_masterState == SPITP_STATE_UNINIT) {
    ;  // Do noting
  } else {
    if (SpiTp_failInject == SPITP_FAULT_INJECT_SPLIT_SIZE) {
      SpiIf_Status status;
      status = hb_SpiMaster_getStatus();

      if (status != SpiIf_Status_busy) {
        hb_SpiMaster_exchange(NULL_PTR, NULL_PTR, 253);
        SpiTp_failInject = SPITP_FAULT_INJECT_NONE;
      }
    }

    SpiTp_masterTransmit();
    SpiTp_transTimerCheck();
  }

  return;
}

SpiTp_RetType SpiTp_masterSend(const uint8 *data, uint16 length) {
  boolean full;
  SpiTp_RetType retVal;
  uint8 * data_ptr = NULL_PTR;

  retVal = SPITP_E_OK;

  if (SpiTp_masterState == SPITP_STATE_UNINIT) {
    retVal = SPITP_E_UNINIT;
  } else if (data == NULL_PTR) {
    retVal = SPITP_E_PARAM_POINTER;
  } else if (length > SPITP_MASTER_DATA_MAX_SIZE) {
    retVal = SPITP_E_PARAM_LENGTH;
  } else {
    ;
  }

  if (retVal == SPITP_E_OK) {
    full = SpiTp_poolIsFull(&SpiTp_masterTxPool);
    if (full == FALSE) {
      SPITP_MASTER_ENTER();
      data_ptr = (uint8 *)hb_Memory_malloc(length);
      if (data_ptr != NULL_PTR) {
        hb_memcpy(data_ptr, data, length);
        retVal = SpiTp_poolPush(&SpiTp_masterTxPool, data_ptr, length);
      }
      SPITP_MASTER_EXIT();
    } else {
      retVal = SPITP_E_NOT_OK;
    }
  }

  return retVal;
}
boolean SpiTp_RxMsgIsUpdated(void)
{
    boolean ret = FALSE;

    ret = SpiTp_poolIsEmpty(&SpiTp_masterRxPool);

    return (!ret);
}

uint16 SpiTp_masterRecieve(uint8 *data) {
  boolean empty;
  uint8 head = 0;
  uint16 length = 0;

  SPITP_MASTER_ENTER();
  empty = SpiTp_poolIsEmpty(&SpiTp_masterRxPool);
  if (empty == FALSE) {
    head = SpiTp_masterRxPool.head;
    length = SpiTp_masterRxPool.length[head];
    if (SpiTp_masterRxPool.dataPtr[head] != NULL_PTR) {
      hb_memcpy(data, SpiTp_masterRxPool.dataPtr[head], length);
    }
    
    SpiTp_poolPop(&SpiTp_masterRxPool);
  }
	SPITP_MASTER_EXIT();
  return length;
}

void SpiTp_masterFrameExchange(void) {
  SpiIf_Status status;
  boolean recvState;
  boolean sendState;

  status = hb_SpiMaster_getStatus();

  if (status != SpiIf_Status_busy) {
    hb_memset((void *)&SpiTp_masterPtlInfo.rxBuf.buf, 0,
              SPITP_MASTER_SPLIT_SIZE);

    sendState = SpiTp_getTransmitState();
    recvState = SpiTp_getRecvState();

    if (sendState == FALSE) {
      if (recvState == FALSE) {
        SpiTp_setRecvState(TRUE);
      }

      hb_memset((void *)&SpiTp_masterPtlInfo.txBuf.buf, 0xFD,
                SPITP_MASTER_SPLIT_SIZE);
    }

    if (sendState == FALSE && SpiTp_failInject == SPITP_FAULT_INJECT_RECV_RDY) {
      SpiTp_setRecvState(FALSE);
      SpiTp_failInject = SPITP_FAULT_INJECT_NONE;
      return;
    }
    if (sendState == TRUE && SpiTp_failInject == SPITP_FAULT_INJECT_SEND_RDY) {
      SpiTp_setTransmitState(FALSE);
      SpiTp_cancelMasterTransTimer();
      SpiTp_failInject = SPITP_FAULT_INJECT_NONE;
      return;
    }
    if (SpiTp_masterPtlInfo.txBuf.curCnt == SpiTp_masterPtlInfo.txBuf.ttlCnt) 
    {
      SpiTp_poolPop(&SpiTp_masterTxPool);
    } 
    hb_SpiMaster_exchange(&SpiTp_masterPtlInfo.txBuf.buf,
                        &SpiTp_masterPtlInfo.rxBuf.buf,
                        SPITP_MASTER_SPLIT_SIZE);
  }

  return;
}

void SpiTp_masterFiniNotification(void) {
  boolean sendState;
  boolean intPreemState;

  SPITP_MASTER_ENTER();

  intPreemState = SpiTp_intPreemCheck();

  if (intPreemState == FALSE) {
    sendState = SpiTp_getTransmitState();
    if (sendState == TRUE) {
      SpiTp_masterTransmitConcrete();

    } else {
      SpiTp_masterRecvPars();
    }

  } else {
    SpiTp_masterTransferIntPreemp();
  }


  

  SPITP_MASTER_EXIT();

  return;
}

void SpiTp_masterErrNotification(void) {
  SpiTp_setTransmitState(FALSE);
  SpiTp_setRecvState(FALSE);

  SpiTp_cancelMasterTransTimer();

  return;
}

void SpiTp_masterAck(void) {
  boolean intPreemState;
  boolean send_state;
  send_state = SpiTp_getTransmitState();
#if 0
  if (send_state == TRUE) {
    intPreemState = SpiTp_getIntPreemState();
    if (intPreemState == TRUE) {
        SpiTp_setIntPreemState(FALSE);
    }
    SpiTp_setTransmitState(FALSE);
    SpiTp_masterTransmit();
  }
#endif
}

void SpiTp_setFailInject(uint8 fail) {
  SpiTp_failInject = fail;
}

void SpiTp_setFailInjectJ2(uint8 fail) {
  SpiTp_failInjectJ2 = fail;
}
/******************************************************************************/
/*---------------------------Static Function----------------------------------*/
/******************************************************************************/
static void SpiTp_masterInitPtlInfo(void) {
  hb_memset((void *)&SpiTp_masterPtlInfo, 0, sizeof(SpiTpSpiBufType));

  return;
}

static void SpiTp_masterBufferInit(void) {
  hb_memset(&SpiTp_masterRxPool, 0, sizeof(SpiTpPoolType));
  hb_memset(&SpiTp_masterTxPool, 0, sizeof(SpiTpPoolType));
}

static void SpiTp_masterTransmit(void) {
  boolean empty;
  void *dataPtr;
  boolean tranState;
  SpiIf_Status status;
  uint16 length;

  SPITP_MASTER_ENTER();
  empty = SpiTp_poolIsEmpty(&SpiTp_masterTxPool);

  if (empty == FALSE) {
    
    tranState = SpiTp_getMasterTransferState();
    if (tranState == FALSE) 
    {
        status = hb_SpiMaster_getStatus();
        if (status != SpiIf_Status_busy) 
        {
            dataPtr = SpiTp_masterTxPool.dataPtr[SpiTp_masterTxPool.head];
            length = SpiTp_masterTxPool.length[SpiTp_masterTxPool.head];
            SpiTp_masterPreTransmit(dataPtr, length);
            SpiTp_masterFrameConcrete();
            hb_masterPrepareNotify();
            SpiTp_setTransTimer();
            SpiTp_setTransmitState(TRUE);
        }
      }
    
  }
  SPITP_MASTER_EXIT();
  return;
}

static void SpiTp_masterTransmitConcrete(void) {
  if (SpiTp_masterPtlInfo.txBuf.curCnt != SpiTp_masterPtlInfo.txBuf.ttlCnt) {
    SpiTp_masterFrameConcrete();
  } else {
    hb_memset(&SpiTp_masterPtlInfo.txBuf.buf, 0xFD, SPITP_MASTER_SPLIT_SIZE);
    SpiTp_masterPtlInfo.txBuf.ttlCnt = 0;
    // SpiTp_poolPop(&SpiTp_masterTxPool);
    SpiTp_setTransmitState(FALSE);
    SpiTp_cancelMasterTransTimer();
    SpiTp_masterTransmit();
  }
}

static void SpiTp_masterPreTransmit(const uint8 *data, uint16 length) {
  /* Copy the request data into module buffer */
  SpiTp_masterTxBuf = (uint8*)data;

  SpiTp_masterPtlInfo.txBuf.length = length;
  /* Calcaulate the package number to be transmitted */
  SpiTp_masterPtlInfo.txBuf.ttlCnt = SpiTp_masterCntCalc(length);

  /* Reset the current transmitted package */
  SpiTp_masterPtlInfo.txBuf.curCnt = 0;

  return;
}

static uint8 SpiTp_masterCntCalc(uint16 length) {
  uint8 size;
  uint16 tmp;
  if (length <= SPITP_MASTER_FIRST_FRAME_LENTH) {
    size = 1;
  } else {
    size = 1;
    tmp = (length - SPITP_MASTER_FIRST_FRAME_LENTH);
    size += tmp / SPITP_MASTER_FRAME_LENTH;
    if (tmp % SPITP_MASTER_FRAME_LENTH) {
      size++;
    }
  }
  return size;
}

static void SpiTp_masterFrameConcrete(void) {
  uint16 offset;

  offset = SpiTp_offsetCalc(SpiTp_masterPtlInfo.txBuf.curCnt);

  SpiTp_masterPtlInfo.txBuf.buf.dl_header.sync = SPITP_MASTER_SYNC_CODE;
  SpiTp_masterPtlInfo.txBuf.buf.dl_header.rc = SpiTp_masterPtlInfo.tx_rc;
  SpiTp_masterPtlInfo.tx_rc++;
  SpiTp_masterPtlInfo.txBuf.buf.tp_header.count =
      SpiTp_masterPtlInfo.txBuf.curCnt;
  if (SpiTp_failInject == SPITP_FAULT_INJECT_DL_RC) {
    SpiTp_masterPtlInfo.txBuf.buf.dl_header.rc++;
    SpiTp_masterPtlInfo.tx_rc = SpiTp_masterPtlInfo.txBuf.buf.dl_header.rc + 1;
    SpiTp_failInject = SPITP_FAULT_INJECT_NONE;
  }

  SpiTp_masterPtlInfo.txBuf.curCnt++;

  if (SpiTp_masterPtlInfo.txBuf.curCnt == 1) {
    SpiTp_masterPtlInfo.txBuf.buf.dl_frame.first_frame.length =
        SpiTp_masterPtlInfo.txBuf.length;
    hb_memcpy(SpiTp_masterPtlInfo.txBuf.buf.dl_frame.first_frame.data,
              (SpiTp_masterTxBuf + offset), SPITP_MASTER_FIRST_FRAME_LENTH);
    if (SpiTp_failInject != SPITP_FAULT_INJECT_TP_START) {
      SpiTp_masterPtlInfo.txBuf.buf.tp_header.start = 1;
    } else {
      SpiTp_masterPtlInfo.txBuf.buf.tp_header.start = 0;
      SpiTp_failInject = SPITP_FAULT_INJECT_NONE;
    }

  } else {
    hb_memcpy(SpiTp_masterPtlInfo.txBuf.buf.dl_frame.frame.data,
              (SpiTp_masterTxBuf + offset), SPITP_MASTER_FRAME_LENTH);
    SpiTp_masterPtlInfo.txBuf.buf.tp_header.start = 0;
  }

  if (SpiTp_masterPtlInfo.txBuf.curCnt == SpiTp_masterPtlInfo.txBuf.ttlCnt) {
    if (SpiTp_failInject != SPITP_FAULT_INJECT_TP_END) {
      SpiTp_masterPtlInfo.txBuf.buf.tp_header.end = 1;
    } else {
      SpiTp_masterPtlInfo.txBuf.buf.tp_header.end = 0;
      SpiTp_failInject = SPITP_FAULT_INJECT_NONE;
    }

  } else {
    SpiTp_masterPtlInfo.txBuf.buf.tp_header.end = 0;
  }

  if (SpiTp_masterPtlInfo.txBuf.buf.tp_header.start == 0) {
    if (SpiTp_failInject != SPITP_FAULT_INJECT_TP_CONSECUTIVE) {
      SpiTp_masterPtlInfo.txBuf.buf.tp_header.consecutive = 1;
    } else {
      SpiTp_masterPtlInfo.txBuf.buf.tp_header.consecutive = 0;
      SpiTp_failInject = SPITP_FAULT_INJECT_NONE;
    }
  } else {
    SpiTp_masterPtlInfo.txBuf.buf.tp_header.consecutive = 0;
  }
  SpiTp_masterPtlInfo.txBuf.buf.tp_header.reserve = 0;
  SpiTp_masterPtlInfo.txBuf.buf.dl_header.chk = 0;
#ifdef SPITP_CRC16
  SpiTp_masterPtlInfo.txBuf.buf.dl_header.chk = SpiTp_CRC16_CCITT(
      (uint8 *)&SpiTp_masterPtlInfo.txBuf.buf, SPITP_MASTER_SPLIT_SIZE);
#else
  SpiTp_masterPtlInfo.txBuf.buf.dl_header.chk = SpiTp_Checksum16_Calc(
      (uint8 *)&SpiTp_masterPtlInfo.txBuf.buf, SPITP_MASTER_SPLIT_SIZE);
#endif
  if (SpiTp_failInject == SPITP_FAULT_INJECT_DL_CHK) {
    SpiTp_masterPtlInfo.txBuf.buf.dl_header.chk++;
    SpiTp_failInject = SPITP_FAULT_INJECT_NONE;
  }
  return;
}

static SpiTp_RetType SpiTp_masterDlCheck(SpiTpSpiBufType * info) {
  SpiTp_RetType ret;
  uint16 chk = 0;
  uint16 chk_calc = 0;
  ret = SPITP_E_OK;
  if (info->rxBuf.buf.dl_header.sync == SPITP_MASTER_SYNC_CODE) {
    chk = info->rxBuf.buf.dl_header.chk;
    info->rxBuf.buf.dl_header.chk = 0;
#ifdef SPITP_CRC16
    chk_calc = SpiTp_CRC16_CCITT((uint8 *)&info->rxBuf.buf,
                             SPITP_MASTER_SPLIT_SIZE);
#else
    chk_calc = SpiTp_Checksum16_Calc((uint8 *)&info->rxBuf.buf,
                             SPITP_MASTER_SPLIT_SIZE);
#endif
    if (chk != chk_calc) {
      SpiTp_errStatics.err_crc++;
      ret = SPITP_E_NOT_OK;
    }

    if (info->rx_rc != info->rxBuf.buf.dl_header.rc) {
      SpiTp_errStatics.err_rc++;
    }
    info->rx_rc = (uint8)(info->rxBuf.buf.dl_header.rc + 1);

  } else {
    ret = SPITP_E_NOT_OK;
    SpiTp_setRecvState(FALSE);
  }
  return ret;
}

static SpiTp_RetType SpiTp_masterTpCheck(SpiTpBufRxInfoType * info) {
  SpiTp_RetType ret;
  ret = SPITP_E_OK;

  if (info->start_flag == 1 && info->buf.tp_header.start == 1) {
    SpiTp_masterRecvCancel();
    SpiTp_errStatics.err_start++;
  }

  if (info->start_flag == 1 && info->buf.tp_header.consecutive != 1) {
    SpiTp_errStatics.err_consecutive++;
    ret = SPITP_E_NOT_OK;
  } else if (info->start_flag == 0 && info->buf.tp_header.start == 0) {
    if (info->buf.tp_header.consecutive == 1) {
      SpiTp_errStatics.err_consecutive++;
      ret = SPITP_E_NOT_OK;
    }

    if (info->buf.tp_header.end == 1) {
      SpiTp_errStatics.err_end++;
      ret = SPITP_E_NOT_OK;
    }
  } else {
  }
  return ret;
}

static SpiTp_RetType SpiTp_masterTpPackage(SpiTpBufRxInfoType * info) {
  SpiTp_RetType ret;
  SpiTp_RetType ret_push;
  uint16 offset = 0;
  uint16 data_len = 0;
  ret = SPITP_E_OK;

  ret = SpiTp_masterTpCheck(info);
  if (ret == SPITP_E_OK) {
    if (info->buf.tp_header.start == 1) {
        info->start_flag = 1;
        info->length =
          info->buf.dl_frame.first_frame.length;
        info->curCnt = 0;
    } else {
      info->curCnt++;
    }

    if (info->buf.tp_header.count != info->curCnt) {
      SpiTp_errStatics.err_consecutive++;
      ret = SPITP_E_NOT_OK;
      return ret;
    }

    offset = SpiTp_offsetCalc(info->curCnt);
    if (info->buf.tp_header.start == 1) {
      data_len = info->buf.dl_frame.first_frame.length;
      SpiTp_masterRxBuf = (uint8*)hb_Memory_malloc(data_len);
      if (info->buf.tp_header.end == 1) {
        if (SpiTp_masterRxBuf != NULL_PTR) {
          hb_memcpy((SpiTp_masterRxBuf + offset),
                    info->buf.dl_frame.first_frame.data,
                    info->length);
        }
      } else {
        if (SpiTp_masterRxBuf != NULL_PTR) {
          hb_memcpy((SpiTp_masterRxBuf + offset),
                  info->buf.dl_frame.first_frame.data,
                  SPITP_MASTER_FIRST_FRAME_LENTH);
        }
      }
    } else if (info->buf.tp_header.start == 0 &&
              info->buf.tp_header.end == 0) {
      if (SpiTp_masterRxBuf != NULL_PTR) {
        hb_memcpy((SpiTp_masterRxBuf + offset),
                info->buf.dl_frame.frame.data,
                SPITP_MASTER_FRAME_LENTH);
      }
    } else if (info->buf.tp_header.end == 1) {
      if (SpiTp_masterRxBuf != NULL_PTR) {
        hb_memcpy((SpiTp_masterRxBuf + offset),
                info->buf.dl_frame.frame.data,
                info->length - offset);
      }
    }

    if (info->buf.tp_header.end == 1) {
      if (SpiTp_masterRxBuf != NULL_PTR) {
        ret_push = SpiTp_poolPush(&SpiTp_masterRxPool, SpiTp_masterRxBuf,
                      info->length);
        SpiTp_masterRxBuf = NULL_PTR;
      }
      info->start_flag = 0;
      info->curCnt = 0;
      SpiTp_setRecvState(FALSE);
      SpiTp_masterTransmit();
    }
  }
  return ret;
}

static void SpiTp_masterRecvCancel(void) {
  if (SpiTp_masterRxBuf != NULL_PTR) {
    hb_Memory_free(SpiTp_masterRxBuf);
    SpiTp_masterRxBuf = NULL_PTR;
  }
  SpiTp_masterPtlInfo.rxBuf.start_flag = 0;
  SpiTp_masterPtlInfo.rxBuf.curCnt = 0;
  SpiTp_setRecvState(FALSE);
}

static void SpiTp_masterRecvPars(void) {
  SpiTp_RetType ret;
  ret = SpiTp_masterDlCheck(&SpiTp_masterPtlInfo);
  if (ret == SPITP_E_OK) {
    ret = SpiTp_masterTpPackage(&SpiTp_masterPtlInfo.rxBuf);
    if (ret == SPITP_E_NOT_OK) {
      SpiTp_masterRecvCancel();
    }
  } else {
    SpiTp_masterRecvCancel();
  }
  return;
}

static boolean SpiTp_getMasterTransferState(void) {
  return (SpiTp_masterPtlInfo.recv || SpiTp_masterPtlInfo.send);
}

static void SpiTp_setTransmitState(boolean state) {
  SpiTp_masterPtlInfo.send = state;

  return;
}

static boolean SpiTp_getTransmitState(void) { return SpiTp_masterPtlInfo.send; }

static void SpiTp_setRecvState(boolean state) {
  SpiTp_masterPtlInfo.recv = state;

  return;
}

static boolean SpiTp_getRecvState(void) { return SpiTp_masterPtlInfo.recv; }

static boolean SpiTp_poolIsFull(SpiTpPoolType *pool) {
  return (pool->counter >= SPITP_MASTER_POOL_SIZE);
}

static boolean SpiTp_poolIsEmpty(SpiTpPoolType *pool) {
  return (pool->counter == 0);
}
SpiTp_RetType SpiTp_poolCheckAll(SpiTpPoolType *pool)
{

  volatile uint8 tempCnt ;
  volatile uint8 tempHead ;
  volatile uint8 tempLen = 0;
  volatile SpiTp_RetType retVal ;
  volatile SpiTpPoolType SpiTpPoolInst;

 
  SuspendAllInterrupts();
  hb_memcpy(&SpiTpPoolInst,pool,sizeof(SpiTpPoolType));

  retVal = SPITP_E_OK;

  if(pool->counter > 0)
  {
    if (pool->length[pool->head] == 0 || pool->dataPtr[pool->head] == NULL_PTR)
    {
      retVal = SPITP_E_NOT_OK;
    }

  }
  
  ResumeAllInterrupts();
  return retVal;
}
static SpiTp_RetType SpiTp_poolPush(SpiTpPoolType *pool, const uint8 *data,
                           uint16 length) {
  boolean full;
  void *dataPtr;
  SpiTp_RetType retVal;

  SPITP_MASTER_ENTER();
  GetSpinlock(OsSpinlock_SpiBuffer);
  retVal = SPITP_E_OK;

  full = SpiTp_poolIsFull(pool);
  if (full != TRUE) {
    dataPtr = (void *)data;
    if (dataPtr != NULL_PTR) {
      pool->dataPtr[pool->tail] = dataPtr;

      pool->counter++;
      pool->length[pool->tail] = length;
      pool->tail = (pool->tail + 1) % SPITP_MASTER_POOL_SIZE;
    }
  } else {
    retVal = SPITP_E_NOT_OK;
  }
  ReleaseSpinlock(OsSpinlock_SpiBuffer);
  SPITP_MASTER_EXIT();
  return retVal;
}

static void SpiTp_poolPop(SpiTpPoolType *pool) {
  boolean empty;
  SPITP_MASTER_ENTER();
  GetSpinlock(OsSpinlock_SpiBuffer);
  empty = SpiTp_poolIsEmpty(pool);
  if (empty != TRUE) {
    hb_Memory_free(pool->dataPtr[pool->head]);
    pool->dataPtr[pool->head] = NULL_PTR;
    pool->length[pool->head] = 0;
    pool->counter--;
    pool->head = (pool->head + 1) % SPITP_MASTER_POOL_SIZE;
  }
  ReleaseSpinlock(OsSpinlock_SpiBuffer);
  SPITP_MASTER_EXIT();
  return;
}

static void SpiTp_setTransTimer(void) {
  hb_timerReset(&SpiTp_masterTransTime);
  SpiTp_masterTransTimeSetup = TRUE;

  return;
}

static void SpiTp_transTimerCheck(void) {
  boolean timeout;

  timeout = FALSE;

  if (SpiTp_masterTransTimeSetup == TRUE) {
    timeout =
        hb_timerCheck(SpiTp_masterTransTime, SPITP_MASTER_TRANSFER_TIMEOUT);

    if (timeout == TRUE) {
      SpiTp_errStatics.err_tx_timeout++;
      hb_masterPrepareNotify();
      SpiTp_setTransTimer();
    }
  }
  return;
}

static void SpiTp_cancelMasterTransTimer(void) {
  SpiTp_masterTransTimeSetup = FALSE;

  return;
}

static void SpiTp_masterTransferIntPreemp(void) {
  uint16 offset = 0;
  uint16 chk = 0;
  uint16 chk_calc = 0;
  uint16 data_len = 0;
  SpiTp_RetType ret;
  if (SpiTp_masterPtlInfo.txBuf.curCnt != SpiTp_masterPtlInfo.txBuf.ttlCnt) {
    SpiTp_masterFrameConcrete();
  } else {
    hb_memset(&SpiTp_masterPtlInfo.txBuf.buf, 0xFD, SPITP_MASTER_SPLIT_SIZE);
    SpiTp_masterPtlInfo.txBuf.curCnt = 0;
    SpiTp_setTransmitState(FALSE);
    SpiTp_cancelMasterTransTimer();
    SpiTp_setIntPreemState(FALSE);
  }

  if (SpiTp_masterPtlInfo.rxBuf.buf.dl_header.sync == SPITP_MASTER_SYNC_CODE) {
    ret = SpiTp_masterDlCheck(&SpiTp_masterPtlInfo);
    if (ret == SPITP_E_OK) {
      ret = SpiTp_masterTpPackage(&SpiTp_masterPtlInfo.rxBuf);
      if (ret == SPITP_E_NOT_OK) {
        SpiTp_masterRecvCancel();
      }
    } else {
      SpiTp_masterRecvCancel();
    }
  }

  return;
}

static uint16 SpiTp_offsetCalc(uint8 curCnt) {
  uint16 offset;
  if (curCnt == 0) {
    offset = 0;
  } else {
    offset = SPITP_MASTER_FIRST_FRAME_LENTH +
             SPITP_MASTER_FRAME_LENTH * (curCnt - 1);
  }
  return offset;
}

static void SpiTp_setIntPreemState(boolean state) {
  SpiTp_masterPtlInfo.preemptive = state;
}

static boolean SpiTp_getIntPreemState(void) {
  return SpiTp_masterPtlInfo.preemptive;
}

static boolean SpiTp_intPreemCheck(void) {
  boolean retVal;
  boolean preemState;
  boolean sendState;

  retVal = FALSE;

  preemState = SpiTp_getIntPreemState();

  if (preemState == FALSE) {
    sendState = SpiTp_getTransmitState();

    if (sendState == TRUE) {
      if (SpiTp_masterPtlInfo.rxBuf.buf.dl_header.sync ==
          SPITP_MASTER_SYNC_CODE) {
        SpiTp_setIntPreemState(TRUE);
        SpiTp_setRecvState(TRUE);
        retVal = TRUE;
      }
    }
  } else {
    retVal = TRUE;
  }

  return retVal;
}
#ifdef SPITP_CRC16
static uint16 SpiTp_CRC16_CCITT(uint8 *data, uint32 datalen) {
  uint16 wCRCin = 0x0000;
  uint16 wCPoly = 0x1021;
  uint8 wChar = 0;
  int i = 0;

  while (datalen--) {
    wChar = *(data++);
    InvertUint8(&wChar, &wChar);
    wCRCin ^= (wChar << 8);
    for (i = 0; i < 8; i++) {
      if (wCRCin & 0x8000)
        wCRCin = (wCRCin << 1) ^ wCPoly;
      else
        wCRCin = wCRCin << 1;
    }
  }
  InvertUint16(&wCRCin, &wCRCin);
  return (wCRCin);
}
#else
static uint16 SpiTp_Checksum16_Calc(uint8 *data, uint32 datalen) {
  uint16 checksum = 0;
  uint32 i;
  uint32 ck_no = datalen >> 1;
  uint16 * dataPtr = (uint16 *)data;
  for (i = 0; i < ck_no; i++) {
    checksum += dataPtr[i];
  }
  return (checksum);
}
#endif
static void InvertUint16(uint16 *dBuf, uint16 *srcBuf) {
  int i;
  uint16 tmp[4] = {0};

  for (i = 0; i < 16; i++) {
    if (srcBuf[0] & (1 << i))
      tmp[0] |= 1 << (15 - i);
  }
  dBuf[0] = tmp[0];
}

static void InvertUint8(uint8 *dBuf, uint8 *srcBuf) {
  int i;
  uint8 tmp[4] = {0};

  for (i = 0; i < 8; i++) {
    if (srcBuf[0] & (1 << i))
      tmp[0] |= 1 << (7 - i);
  }
  dBuf[0] = tmp[0];
}



uint32 ServiceSpi_GetCrc(void){
	return SpiTp_errStatics.err_crc;
}

uint32 ServiceSpi_Getrc(void){
	return SpiTp_errStatics.err_rc;
}
