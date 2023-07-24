/**
 * \file   Cdd_SpiServ.c
 *
 * \brief  Configuration data and stubs function of SpiServ.
 *
 * \version refer the Cdd_SpiServ.h.
 *
 * \copyright  2022 - 2023 Conti Smart Core
 *
 */
/*==================[inclusions]============================================*/
#include <Rte_CtCdSPI.h>
#include "Cdd_SpiServ.h"
#include "IfxSrc_reg.h"
#include "IfxStm_reg.h"
#include "Dio_Cfg.h"
#include "Dio.h"
#include "Spi.h"
#include "common_platform.h"
#include "hb_Memory.h"
#include "SpiTpMaster.h"
#include "Sdc.h"

/*==================[internal data]=========================================*/


/*==================[external data]=========================================*/



/*==================[internal function declarations]========================*/
static void Cdd_SpiServ_InitDMAUsr(void);


/*==================[external function definitions]=========================*/
FUNC(void, RTE_CODE) CtCdSPI_5ms(void) //Core0_Appl_5ms
{
	SpiTp_MasterMainFunction();
} /* FUNC(void, RTE_CODE) CtCdSPI_5ms (void) */


FUNC(void, RTE_CODE) CtCdSPI_Init(void) 
{

} /* FUNC(void, RTE_CODE) CtCdSPI_Init (void) */


/**
 * \functions Cdd_SpiServ_Init
 *
 * \brief Initial Spi DMA channel and SpiTP layer protocol.
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return none,
 * \comments This function shall be call after SPI_Init()
 *
 */
void Cdd_SpiServ_Init(void)
{
    Cdd_SpiServ_InitDMAUsr();
    
	/* Set spi async transmit to use interrupt mode */
	Spi_SetAsyncMode(SPI_INTERRUPT_MODE);

	/* hr spitp memory init*/
	hb_Memory_Init();

	/* hr spitp init */
	SpiTp_MasterInit();

	/* Hr service init */
	Sdc_InitFunction();

	/* SpiTp interrupt enable initial */
	SpiTp_vHwIntEnable();

	Dio_WriteChannel(DioConf_DioChannel_DIO_DO_MCU_SPI3_CS_B, STD_HIGH);		/* J3 CS*/
	
	Dio_WriteChannel(DioConf_DioChannel_DIO_DO_MCU_P1007_J3_GPIO22_IND, STD_HIGH);		/* J3 IND*/
}

/*==================[internal function definitions]=========================*/
/**
 * \functions Cdd_SpiServ_InitDMAUsr
 *
 * \brief Initial register of Spi DMA channel.
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return none,
 * \comments 
 *
 */
static void Cdd_SpiServ_InitDMAUsr(void)
{
	Ifx_SRC_SRCR txDMA, rxDMA;
	txDMA.U = 0U;
	rxDMA.U = 0U;

	SRC_QSPI_QSPI3_TX.U = QSPI_SCR_CLR_MASK;
	SRC_QSPI_QSPI3_RX.U = QSPI_SCR_CLR_MASK;

	/* Set Type of Service to 'DMA' */
	txDMA.B.TOS = QSPI_SCR_DMA_MODE;
	rxDMA.B.TOS = QSPI_SCR_DMA_MODE;

	/* Set Service Request Priority Number aka 'DMA channel' */
	txDMA.B.SRPN = QSPI3_SCR_TX_PRIO;
	rxDMA.B.SRPN = QSPI3_SCR_RX_PRIO;

	/* Service Request Enable bit */
	txDMA.B.SRE = QSPI_SCR_EN_SRE;
	rxDMA.B.SRE = QSPI_SCR_EN_SRE;

	/* Write to QSPI3 Service Request registers */
	SRC_QSPI_QSPI3_TX.U = txDMA.U;
	SRC_QSPI_QSPI3_RX.U = rxDMA.U;

	/* SPI 3 Interrupt enable */
	SRC_DMACH15.U |= 0x400U;
	SRC_DMACH16.U |= 0x400U;
	SRC_QSPI3RX.U |= 0x400;
	SRC_QSPI3ERR.U |= 0x400;
	SRC_QSPI3TX.U |= 0x400;
	SRC_QSPI3PT.U |= 0x400;
}

