
/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/
#include "common_platform.h"
#include "dio.h"
#include "IfxStm_reg.h"
#include "IfxSrc_reg.h"
#include "Icu_17_TimerIp.h"
#include "Dma.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/
#define DENOMINATOR_MS 100000
/******************************************************************************/
/*------------------------------Global variables------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*------------------------------Static variables------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*-------------------------Function Prototypes--------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*-------------------------_Globale Function----------------------------------*/
/******************************************************************************/
SpiIf_Status hb_SpiMaster_getStatus(void) {

  SpiIf_Status status;
  Spi_SequenceType temp_S;

  temp_S = Spi_GetSequenceResult(SpiConf_SpiSequence_SeqSPI3_J3);

  /* Different return value enum */
  if(SPI_SEQ_OK == temp_S)
  {
	  status = SpiIf_Status_ok;
  }
  else if(SPI_SEQ_PENDING == temp_S)
  {
	  status = SpiIf_Status_busy;
  }
  else
  {
	  status = SpiIf_Status_unknown;
  }

  return status;
}


SpiIf_Status hb_SpiMaster_exchange(const void *src, void *dest, uint32 count) {
  SpiIf_Status status;

  static uint8 TxCnt = 0u;

  TxCnt++;

  Spi_SetupEB( SPITP_J2_CHANNEL,
			   (Spi_DataBufferType *)src,
			   (Spi_DataBufferType *)dest,
			    (Spi_NumberOfDataType)count
		     );
  status = Spi_AsyncTransmit(SPITP_J2_SEQUENCE);



  return status;
}

void hb_masterPrepareNotify(void) {

	static uint8 J3A_PrepareCnt = 0u;

	Dio_WriteChannel(DioConf_DioChannel_DIO_DO_MCU_P1007_J3_GPIO22_IND, STD_LOW);

	J3A_PrepareCnt++;

	Dio_WriteChannel(DioConf_DioChannel_DIO_DO_MCU_P1007_J3_GPIO22_IND, STD_HIGH);

  return;
}


void hb_timerReset(uint32 *time) {
	*time = STM0_TIM0.U;
  return;
}

boolean hb_timerCheck(uint32 time, uint32 expired) {

  /* set the current timestamp */
  boolean timeout;
  uint32 timePost;
  uint32 expiredTime;

  timeout = FALSE;

  timePost = STM0_TIM0.U;
  expiredTime = expired * DENOMINATOR_MS;

  if (timePost >= time) {
    if ((timePost - time) >= expiredTime) {
      timeout = TRUE;
    }
  } else {
    if ((0xFFFFFFFF - time + timePost) >= expiredTime) {
      timeout = TRUE;
    }
  }

  return timeout;
}

/*******************************************************************************
** Function Name	: SpiTp_vHwIntEnable
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	: None
** Description	  	: Enable Rdy, Ack interrupt
*******************************************************************************/
void SpiTp_vHwIntEnable(void)
{
	/* Rdy */
	SRC_GTMTIM25.B.SRE = TRUE;
	Icu_17_TimerIp_EnableNotification(IcuConf_IcuChannel_IcuChannel_J3_RDY);

	/* Ack */
	SRC_GTMTIM15.B.SRE = TRUE;
	Icu_17_TimerIp_EnableNotification(IcuConf_IcuChannel_IcuChannel_J3_ACK);
}

/******************************************************************************/
/*---------------------------Static Function----------------------------------*/
/******************************************************************************/
