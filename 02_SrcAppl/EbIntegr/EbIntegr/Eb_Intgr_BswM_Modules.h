/**
 * \file
 *
 * \brief AUTOSAR ApplTemplates
 *
 * This file contains the implementation of the AUTOSAR
 * module ApplTemplates.
 *
 * \version 6.8.0
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2020 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

#ifndef EB_INTGR_BSWM_MODULES_H
#define EB_INTGR_BSWM_MODULES_H


/*==================[includes]==============================================*/

/*==================[macros]================================================*/

/*
 * Common initialization function invocations
 *
 * In the following you find macros for defining the init function calls.
 *
 * The config pointer names are generated by the Base module in Base_Modules.h.
 * It is assumed that the name of the config pointer corresponds to the name
 * of the multiple configuration container. Base always uses the first
 * multiple configuration container found.
 *
 * When a module is not AUTOSAR compliant and expects a different config
 * pointer or if you want to use a different multiple configuration
 * container, you can define the config pointer names in the header file
 * "Platforms_Modules.h". These definitions precede the ones defined by the
 * Base module.
 */


/* ###### INIT FUNCTIONS ###### */

/* ### BSW standard init functions ### */

#ifndef CANIF_INIT_FUNC
#define CANIF_INIT_FUNC CanIf_Init
#endif  /* #ifndef CANIF_INIT_FUNC */

#ifndef CANNM_INIT_FUNC
#define CANNM_INIT_FUNC CanNm_Init
#endif  /* #ifndef CANNM_INIT_FUNC */

#ifndef CANSM_INIT_FUNC
#define CANSM_INIT_FUNC CanSM_Init
#endif  /* #ifndef CANSM_INIT_FUNC */

#ifndef CANTP_INIT_FUNC
#define CANTP_INIT_FUNC CanTp_Init
#endif  /* #ifndef CANTP_INIT_FUNC */

#ifndef COM_INIT_FUNC
#define COM_INIT_FUNC Com_Init
#endif  /* #ifndef COM_INIT_FUNC */

#ifndef COMM_INIT_FUNC
#define COMM_INIT_FUNC ComM_Init
#endif  /* #ifndef COMM_INIT_FUNC */

#ifndef DCM_INIT_FUNC
#define DCM_INIT_FUNC Dcm_Init
#endif  /* #ifndef DCM_INIT_FUNC */

#ifndef DEM_INIT_FUNC
#define DEM_INIT_FUNC Dem_Init
#endif  /* #ifndef DEM_INIT_FUNC */

#ifndef EA_INIT_FUNC
#define EA_INIT_FUNC Ea_Init
#endif  /* #ifndef EA_INIT_FUNC */

#ifndef ETH_INIT_FUNC
#define ETH_INIT_FUNC Eth_Init
#endif  /* #ifndef ETH_INIT_FUNC */

#ifndef ETHIF_INIT_FUNC
#define ETHIF_INIT_FUNC EthIf_Init
#endif /* #ifndef ETHIF_INIT_FUNC */

#ifndef ETHSM_INIT_FUNC
#define ETHSM_INIT_FUNC EthSM_Init
#endif /* #ifndef ETHSM_INIT_FUNC */

#ifndef ETHTRCV_INIT_FUNC
#define ETHTRCV_INIT_FUNC EthTrcv_Init
#endif  /* #ifndef ETHTRCV_INIT_FUNC */

#ifndef FEE_INIT_FUNC
#define FEE_INIT_FUNC Fee_Init
#endif  /* #ifndef FEE_INIT_FUNC */

#ifndef FIM_INIT_FUNC
#define FIM_INIT_FUNC FiM_Init
#endif  /* #ifndef FIM_INIT_FUNC */

#ifndef FRIF_INIT_FUNC
#define FRIF_INIT_FUNC FrIf_Init
#endif  /* #ifndef FRIF_INIT_FUNC */

#ifndef FRNM_INIT_FUNC
#define FRNM_INIT_FUNC FrNm_Init
#endif  /* #ifndef FRNM_INIT_FUNC */

#ifndef FRSM_INIT_FUNC
#define FRSM_INIT_FUNC FrSM_Init
#endif  /* #ifndef FRSM_INIT_FUNC */

#ifndef FRTP_INIT_FUNC
#define FRTP_INIT_FUNC FrTp_Init
#endif  /* #ifndef FRTP_INIT_FUNC */

#ifndef IPDUM_INIT_FUNC
#define IPDUM_INIT_FUNC IpduM_Init
#endif  /* #ifndef IPDUM_INIT_FUNC */

#ifndef LINIF_INIT_FUNC
#define LINIF_INIT_FUNC LinIf_Init
#endif  /* #ifndef LINIF_INIT_FUNC */

#ifndef LINSM_INIT_FUNC
#define LINSM_INIT_FUNC LinSM_Init
#endif  /* #ifndef LINSM_INIT_FUNC */

#ifndef LINTP_INIT_FUNC
#define LINTP_INIT_FUNC LinTp_Init
#endif  /* #ifndef LINTP_INIT_FUNC */

#ifndef NM_INIT_FUNC
#define NM_INIT_FUNC Nm_Init
#endif  /* #ifndef NM_INIT_FUNC */

#ifndef NVM_INIT_FUNC
#define NVM_INIT_FUNC NvM_Init
#endif  /* #ifndef NVM_INIT_FUNC */

#ifndef PDUR_INIT_FUNC
#define PDUR_INIT_FUNC PduR_Init
#endif  /* #ifndef PDUR_INIT_FUNC */

#ifndef SOAD_INIT_FUNC
#define SOAD_INIT_FUNC SoAd_Init
#endif /* #ifndef SOAD_INIT_FUNC */

#ifndef SD_INIT_FUNC
#define SD_INIT_FUNC Sd_Init
#endif  /* #ifndef SD_INIT_FUNC */

#ifndef TCPIP_INIT_FUNC
#define TCPIP_INIT_FUNC TcpIp_Init
#endif /* #ifndef TCPIP_INIT_FUNC */

#ifndef UDPNM_INIT_FUNC
#define UDPNM_INIT_FUNC UdpNm_Init
#endif  /* #ifndef UDPNM_INIT_FUNC */

#ifndef XCP_INIT_FUNC
#define XCP_INIT_FUNC Xcp_Init
#endif  /* #ifndef XCP_INIT_FUNC */

/* ### MCAL standard init functions ### */

#ifndef CAN_INIT_FUNC
#define CAN_INIT_FUNC Can_Init
#endif  /* #ifndef CAN_INIT_FUNC */

#ifndef CANTRCV_INIT_FUNC
#define CANTRCV_INIT_FUNC CANTRCV_8_TJA1043_INIT_FUNC
#endif  /* #ifndef CANTRCV_INIT_FUNC */

#ifndef EEP_INIT_FUNC
#define EEP_INIT_FUNC Eep_Init
#endif  /* #ifndef EEP_INIT_FUNC */

#ifndef FLS_INIT_FUNC
#define FLS_INIT_FUNC Fls_Init
#endif  /* #ifndef FLS_INIT_FUNC */

#ifndef FR_INIT_FUNC
#define FR_INIT_FUNC Fr_Init
#endif  /* #ifndef FR_INIT_FUNC */

#ifndef FRTRCV_INIT_FUNC
#define FRTRCV_INIT_FUNC FrTrcv_Init
#endif  /* #ifndef FRTRCV_INIT_FUNC */

#ifndef LIN_INIT_FUNC
#define LIN_INIT_FUNC Lin_Init
#endif  /* #ifndef LIN_INIT_FUNC */

#ifndef LINTRCV_INIT_FUNC
#define LINTRCV_INIT_FUNC LinTrcv_Init
#endif  /* #ifndef LINTRCV_INIT_FUNC */

#ifndef RAMTST_INIT_FUNC
#define RAMTST_INIT_FUNC RamTst_Init
#endif  /* #ifndef RAMTST_INIT_FUNC */

#ifndef SPI_INIT_FUNC
#define SPI_INIT_FUNC Spi_Init
#endif  /* #ifndef SPI_INIT_FUNC */

/* ### Miscellaneous init functions ### */

#ifndef MCU_CLOCK_INIT_FUNC
#define MCU_CLOCK_INIT_FUNC Mcu_InitClock
#endif  /* #ifndef MCU_CLOCK_INIT_FUNC */

#ifndef PBCFGM_INIT_FUNC
#define PBCFGM_INIT_FUNC PbcfgM_Init
#endif  /* #ifndef PBCFGM_INIT_FUNC */

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

/*==================[internal function definitions]=========================*/

#endif /* ifndef EB_INTGR_BSWM_MODULES_H */

/*==================[end of file]===========================================*/