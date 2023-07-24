/**EB_Automotive_C_Source_File */

#ifndef PLATFORMS_MODULES_H
#define PLATFORMS_MODULES_H

#define BASE_MCU_CONFIG_PTR              &Mcu_Config

#define SPI_INIT_FUNC              Spi_Init

#define BASE_SPI_CONFIG_PTR              &Spi_Config

#define FLS_INIT_FUNC              Fls_17_Dmu_Init

#define BASE_FLS_CONFIG_PTR              &Fls_17_Dmu_Config

#define FEE_INIT_FUNC              Fee_Init

#define BASE_FEE_CONFIG_PTR              &Fee_Config

#define CANTRCV_8_TJA1043_INIT_FUNC              CanTrcv_8_Tja1043_Init

#define BASE_CANTRCV_8_CONFIG_PTR              &CanTrcv_Tja1043_ConfigTypePtr

#define CAN_INIT_FUNC              Can_17_McmCan_Init

#define BASE_CAN_CONFIG_PTR              &Can_17_McmCan_Config

#define LIN_INIT_FUNC              Lin_17_AscLin_Init

#define BASE_LIN_CONFIG_PTR              &Lin_17_AscLin_Config

#define FR_INIT_FUNC              Fr_17_Eray_Init

#define BASE_FR_CONFIG_PTR              &Fr_17_Eray_Config

#define ETH_INIT_FUNC              Eth_17_GEthMac_Init

#define BASE_ETH_CONFIG_PTR              &Eth_17_GEthMac_Config

#endif /* ifndef PLATFORMS_MODULES_H */

/*==================[end of file]===========================================*/
