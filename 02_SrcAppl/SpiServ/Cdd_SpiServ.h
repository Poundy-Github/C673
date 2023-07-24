/**
 * \file Cdd_SpiServ_Cfg.h
 *
 * \brief  SpiServ parameter configuration
 *
 * \version
 * --------------------------------------------------------------------------------------------
 * Version	| 		Date		|		Author			         | 	Comments
 * V0.0.1		2022.02.12			    xxx(xxx)		           Init version
 *
 *
 * \copyright  2021 - 2023 Conti Smart Core
 */
#ifndef __CDD_SPISERV_H__
#define __CDD_SPISERV_H__ 

/*==================[inclusions]============================================*/



/*==================[macros definitions]====================================*/

#define QSPI3_SCR_TX_PRIO 16U
#define QSPI3_SCR_RX_PRIO 15U

#define QSPI4_SCR_TX_PRIO 18U
#define QSPI4_SCR_RX_PRIO 17U

#define QSPI_SCR_CLR_MASK (0x02000000u)
/** \brief Set ToS to DMA */
#define QSPI_SCR_DMA_MODE (1u)

/** \brief Bit to enable service request */
#define QSPI_SCR_EN_SRE   (1u)


extern void Cdd_SpiServ_Init(void);

#endif


