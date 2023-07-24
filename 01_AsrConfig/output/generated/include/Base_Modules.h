/**
 * \file
 *
 * \brief AUTOSAR Base
 *
 * This file contains the implementation of the AUTOSAR
 * module Base.
 *
 * \version 5.1.0
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2021 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

/* !LINKSTO Base.ModuleInfo.HeaderFile,1 */
#ifndef BASE_MODULES_H
#define BASE_MODULES_H

/*==================[macros]=================================================*/

#ifndef BASE_ADC_ENABLED
/** \brief Enable status of the module Adc (/Adc/Adc) (VariantPostBuild) */
#define BASE_ADC_ENABLED STD_ON
#endif

#ifndef BASE_ADC_HEADER
/** \brief Name of the Adc (/Adc/Adc) module's main header file */
#define BASE_ADC_HEADER <Adc.h>
#endif

#ifndef BASE_BASE_ENABLED
/** \brief Enable status of the module Base (/Base/Base) (VariantPreCompile) */
#define BASE_BASE_ENABLED STD_ON
#endif

#ifndef BASE_BASE_HEADER
/** \brief Name of the Base (/Base/Base) module's main header file */
#define BASE_BASE_HEADER <Base.h>
#endif

#ifndef BASE_BSWM_ENABLED
/** \brief Enable status of the module BswM (/BswM/BswM) (VariantPostBuild) */
#define BASE_BSWM_ENABLED STD_ON
#endif

#ifndef BASE_BSWM_HEADER
/** \brief Name of the BswM (/BswM/BswM) module's main header file */
#define BASE_BSWM_HEADER <BswM.h>
#endif

#ifndef BASE_CAN_ENABLED
/** \brief Enable status of the module Can (/Can/Can) (VariantPostBuild) */
#define BASE_CAN_ENABLED STD_ON
#endif

#ifndef BASE_CAN_17_MCMCAN_ENABLED
/** \brief Enable status of the module Can (/Can/Can) (VariantPostBuild) */
#define BASE_CAN_17_MCMCAN_ENABLED STD_ON
#endif

#ifndef BASE_CAN_HEADER
/** \brief Name of the Can (/Can/Can) module's main header file */
#define BASE_CAN_HEADER <Can_17_McmCan.h>
#endif

#ifndef BASE_CAN_17_MCMCAN_HEADER
/** \brief Name of the Can (/Can/Can) module's main header file */
#define BASE_CAN_17_MCMCAN_HEADER <Can_17_McmCan.h>
#endif

#ifndef BASE_CANIF_ENABLED
/** \brief Enable status of the module CanIf (/CanIf/CanIf) (VariantPostBuild) */
#define BASE_CANIF_ENABLED STD_ON
#endif


#ifndef BASE_CANIF_CONFIG_PTR
/** \brief Address of the first multiple configuration container for CanIf (/CanIf/CanIf) */
#define BASE_CANIF_CONFIG_PTR (&CanIfInitCfg)
#endif

#ifndef BASE_CANIF_HEADER
/** \brief Name of the CanIf (/CanIf/CanIf) module's main header file */
#define BASE_CANIF_HEADER <CanIf.h>
#endif

#ifndef BASE_CANNM_ENABLED
/** \brief Enable status of the module CanNm (/CanNm/CanNm) (VariantPostBuild) */
#define BASE_CANNM_ENABLED STD_ON
#endif


#ifndef BASE_CANNM_CONFIG_PTR
/** \brief Address of the first multiple configuration container for CanNm (/CanNm/CanNm) */
#define BASE_CANNM_CONFIG_PTR (&CanNm_Config_0)
#endif

#ifndef BASE_CANNM_HEADER
/** \brief Name of the CanNm (/CanNm/CanNm) module's main header file */
#define BASE_CANNM_HEADER <CanNm.h>
#endif

#ifndef BASE_CANSM_ENABLED
/** \brief Enable status of the module CanSM (/CanSM/CanSM) (VariantPostBuild) */
#define BASE_CANSM_ENABLED STD_ON
#endif


#ifndef BASE_CANSM_CONFIG_PTR
/** \brief Address of the first multiple configuration container for CanSM (/CanSM/CanSM) */
#define BASE_CANSM_CONFIG_PTR (&CanSMConfiguration)
#endif

#ifndef BASE_CANSM_HEADER
/** \brief Name of the CanSM (/CanSM/CanSM) module's main header file */
#define BASE_CANSM_HEADER <CanSM.h>
#endif

#ifndef BASE_CANTSYN_ENABLED
/** \brief Enable status of the module CanTSyn (/CanTSyn/CanTSyn) (VariantPreCompile) */
#define BASE_CANTSYN_ENABLED STD_ON
#endif

#ifndef BASE_CANTSYN_HEADER
/** \brief Name of the CanTSyn (/CanTSyn/CanTSyn) module's main header file */
#define BASE_CANTSYN_HEADER <CanTSyn.h>
#endif

#ifndef BASE_CANTP_ENABLED
/** \brief Enable status of the module CanTp (/CanTp/CanTp) (VariantPostBuild) */
#define BASE_CANTP_ENABLED STD_ON
#endif


#ifndef BASE_CANTP_CONFIG_PTR
/** \brief Address of the first multiple configuration container for CanTp (/CanTp/CanTp) */
#define BASE_CANTP_CONFIG_PTR (&CanTpConfig_0)
#endif

#ifndef BASE_CANTP_HEADER
/** \brief Name of the CanTp (/CanTp/CanTp) module's main header file */
#define BASE_CANTP_HEADER <CanTp.h>
#endif

#ifndef BASE_CANTRCV_ENABLED
/** \brief Enable status of the module CanTrcv (/CanTrcv3/CanTrcv) (VariantPreCompile) */
#define BASE_CANTRCV_ENABLED STD_ON
#endif

#ifndef BASE_CANTRCV_8_TJA1043_ENABLED
/** \brief Enable status of the module CanTrcv (/CanTrcv3/CanTrcv) (VariantPreCompile) */
#define BASE_CANTRCV_8_TJA1043_ENABLED STD_ON
#endif

#ifndef BASE_CANTRCV_HEADER
/** \brief Name of the CanTrcv (/CanTrcv3/CanTrcv) module's main header file */
#define BASE_CANTRCV_HEADER <CanTrcv_8_Tja1043.h>
#endif

#ifndef BASE_CANTRCV_8_TJA1043_HEADER
/** \brief Name of the CanTrcv (/CanTrcv3/CanTrcv) module's main header file */
#define BASE_CANTRCV_8_TJA1043_HEADER <CanTrcv_8_Tja1043.h>
#endif

#ifndef BASE_COM_ENABLED
/** \brief Enable status of the module Com (/Com/Com) (VariantPostBuild) */
#define BASE_COM_ENABLED STD_ON
#endif


#ifndef BASE_COM_CONFIG_PTR
/** \brief Address of the first multiple configuration container for Com (/Com/Com) */
#define BASE_COM_CONFIG_PTR (&ComConfig)
#endif

#ifndef BASE_COM_HEADER
/** \brief Name of the Com (/Com/Com) module's main header file */
#define BASE_COM_HEADER <Com.h>
#endif

#ifndef BASE_COMM_ENABLED
/** \brief Enable status of the module ComM (/ComM/ComM) (VariantPostBuild) */
#define BASE_COMM_ENABLED STD_ON
#endif


#ifndef BASE_COMM_CONFIG_PTR
/** \brief Address of the first multiple configuration container for ComM (/ComM/ComM) */
#define BASE_COMM_CONFIG_PTR (&ComMConfigSet)
#endif

#ifndef BASE_COMM_HEADER
/** \brief Name of the ComM (/ComM/ComM) module's main header file */
#define BASE_COMM_HEADER <ComM.h>
#endif

#ifndef BASE_COMPILER_ENABLED
/** \brief Enable status of the module Compiler (/Compiler/Compiler) (VariantPreCompile) */
#define BASE_COMPILER_ENABLED STD_ON
#endif

#ifndef BASE_COMPILER_HEADER
/** \brief Name of the Compiler (/Compiler/Compiler) module's main header file */
#define BASE_COMPILER_HEADER <Compiler.h>
#endif

#ifndef BASE_CRC_ENABLED
/** \brief Enable status of the module Crc (/Crc/Crc) (VariantPreCompile) */
#define BASE_CRC_ENABLED STD_ON
#endif

#ifndef BASE_CRC_HEADER
/** \brief Name of the Crc (/Crc/Crc) module's main header file */
#define BASE_CRC_HEADER <Crc.h>
#endif

#ifndef BASE_DCM_ENABLED
/** \brief Enable status of the module Dcm (/Dcm/Dcm) (VariantPreCompile) */
#define BASE_DCM_ENABLED STD_ON
#endif


#ifndef BASE_DCM_CONFIG_PTR
/** \brief Address of the first multiple configuration container for Dcm (/Dcm/Dcm) */
#define BASE_DCM_CONFIG_PTR (&DcmConfigSet_0)
#endif

#ifndef BASE_DCM_HEADER
/** \brief Name of the Dcm (/Dcm/Dcm) module's main header file */
#define BASE_DCM_HEADER <Dcm.h>
#endif

#ifndef BASE_DEM_ENABLED
/** \brief Enable status of the module Dem (/Dem/Dem) (VariantPreCompile) */
#define BASE_DEM_ENABLED STD_ON
#endif


#ifndef BASE_DEM_CONFIG_PTR
/** \brief Address of the first multiple configuration container for Dem (/Dem/Dem) */
#define BASE_DEM_CONFIG_PTR (&DemConfigSet_0)
#endif

#ifndef BASE_DEM_HEADER
/** \brief Name of the Dem (/Dem/Dem) module's main header file */
#define BASE_DEM_HEADER <Dem.h>
#endif

#ifndef BASE_DET_ENABLED
/** \brief Enable status of the module Det (/Det/Det) (VariantPreCompile) */
#define BASE_DET_ENABLED STD_ON
#endif

#ifndef BASE_DET_HEADER
/** \brief Name of the Det (/Det/Det) module's main header file */
#define BASE_DET_HEADER <Det.h>
#endif

#ifndef BASE_DIO_ENABLED
/** \brief Enable status of the module Dio (/Dio/Dio) (VariantLinkTime) */
#define BASE_DIO_ENABLED STD_ON
#endif

#ifndef BASE_DIO_HEADER
/** \brief Name of the Dio (/Dio/Dio) module's main header file */
#define BASE_DIO_HEADER <Dio.h>
#endif

#ifndef BASE_DMA_ENABLED
/** \brief Enable status of the module Dma (/Dma/Dma) (VariantPostBuild) */
#define BASE_DMA_ENABLED STD_ON
#endif

#ifndef BASE_DMA_HEADER
/** \brief Name of the Dma (/Dma/Dma) module's main header file */
#define BASE_DMA_HEADER <Dma.h>
#endif

#ifndef BASE_ECUC_ENABLED
/** \brief Enable status of the module EcuC (/EcuC/EcuC) (VariantPostBuild) */
#define BASE_ECUC_ENABLED STD_ON
#endif

#ifndef BASE_ECUC_HEADER
/** \brief Name of the EcuC (/EcuC/EcuC) module's main header file */
#define BASE_ECUC_HEADER <EcuC.h>
#endif

#ifndef BASE_ECUM_ENABLED
/** \brief Enable status of the module EcuM (/EcuM/EcuM) (VariantPostBuild) */
#define BASE_ECUM_ENABLED STD_ON
#endif


#ifndef BASE_ECUM_CONFIG_PTR
/** \brief Address of the first multiple configuration container for EcuM (/EcuM/EcuM) */
#define BASE_ECUM_CONFIG_PTR (&EcuM_Config_0)
#endif

#ifndef BASE_ECUM_HEADER
/** \brief Name of the EcuM (/EcuM/EcuM) module's main header file */
#define BASE_ECUM_HEADER <EcuM.h>
#endif

#ifndef BASE_FEE_ENABLED
/** \brief Enable status of the module Fee (/Fee/Fee) (VariantPostBuild) */
#define BASE_FEE_ENABLED STD_ON
#endif

#ifndef BASE_FEE_HEADER
/** \brief Name of the Fee (/Fee/Fee) module's main header file */
#define BASE_FEE_HEADER <Fee.h>
#endif

#ifndef BASE_FIM_ENABLED
/** \brief Enable status of the module FiM (/FiM/FiM) (VariantPreCompile) */
#define BASE_FIM_ENABLED STD_ON
#endif


#ifndef BASE_FIM_CONFIG_PTR
/** \brief Address of the first multiple configuration container for FiM (/FiM/FiM) */
#define BASE_FIM_CONFIG_PTR (&FiM_Config_0)
#endif

#ifndef BASE_FIM_HEADER
/** \brief Name of the FiM (/FiM/FiM) module's main header file */
#define BASE_FIM_HEADER <FiM.h>
#endif

#ifndef BASE_FLS_ENABLED
/** \brief Enable status of the module Fls (/Fls/Fls) (VariantPostBuild) */
#define BASE_FLS_ENABLED STD_ON
#endif

#ifndef BASE_FLS_17_DMU_ENABLED
/** \brief Enable status of the module Fls (/Fls/Fls) (VariantPostBuild) */
#define BASE_FLS_17_DMU_ENABLED STD_ON
#endif

#ifndef BASE_FLS_HEADER
/** \brief Name of the Fls (/Fls/Fls) module's main header file */
#define BASE_FLS_HEADER <Fls_17_Dmu.h>
#endif

#ifndef BASE_FLS_17_DMU_HEADER
/** \brief Name of the Fls (/Fls/Fls) module's main header file */
#define BASE_FLS_17_DMU_HEADER <Fls_17_Dmu.h>
#endif

#ifndef BASE_I2C_ENABLED
/** \brief Enable status of the module I2c (/I2c/I2c) (VariantPostBuild) */
#define BASE_I2C_ENABLED STD_ON
#endif

#ifndef BASE_I2C_HEADER
/** \brief Name of the I2c (/I2c/I2c) module's main header file */
#define BASE_I2C_HEADER <I2c.h>
#endif

#ifndef BASE_ICU_ENABLED
/** \brief Enable status of the module Icu (/Icu/Icu) (VariantPostBuild) */
#define BASE_ICU_ENABLED STD_ON
#endif

#ifndef BASE_ICU_17_TIMERIP_ENABLED
/** \brief Enable status of the module Icu (/Icu/Icu) (VariantPostBuild) */
#define BASE_ICU_17_TIMERIP_ENABLED STD_ON
#endif

#ifndef BASE_ICU_HEADER
/** \brief Name of the Icu (/Icu/Icu) module's main header file */
#define BASE_ICU_HEADER <Icu_17_TimerIp.h>
#endif

#ifndef BASE_ICU_17_TIMERIP_HEADER
/** \brief Name of the Icu (/Icu/Icu) module's main header file */
#define BASE_ICU_17_TIMERIP_HEADER <Icu_17_TimerIp.h>
#endif

#ifndef BASE_MCALEXT_ENABLED
/** \brief Enable status of the module McalExt (/McalExt/McalExt) (VariantPreCompile) */
#define BASE_MCALEXT_ENABLED STD_ON
#endif

#ifndef BASE_MCALEXT_HEADER
/** \brief Name of the McalExt (/McalExt/McalExt) module's main header file */
#define BASE_MCALEXT_HEADER <McalExt.h>
#endif

#ifndef BASE_MCALLIB_ENABLED
/** \brief Enable status of the module McalLib (/McalLib/McalLib) (VariantPreCompile) */
#define BASE_MCALLIB_ENABLED STD_ON
#endif

#ifndef BASE_MCALLIB_HEADER
/** \brief Name of the McalLib (/McalLib/McalLib) module's main header file */
#define BASE_MCALLIB_HEADER <McalLib.h>
#endif

#ifndef BASE_MCU_ENABLED
/** \brief Enable status of the module Mcu (/Mcu/Mcu) (VariantPostBuild) */
#define BASE_MCU_ENABLED STD_ON
#endif

#ifndef BASE_MCU_HEADER
/** \brief Name of the Mcu (/Mcu/Mcu) module's main header file */
#define BASE_MCU_HEADER <Mcu.h>
#endif

#ifndef BASE_MEMIF_ENABLED
/** \brief Enable status of the module MemIf (/MemIf/MemIf) (VariantPreCompile) */
#define BASE_MEMIF_ENABLED STD_ON
#endif

#ifndef BASE_MEMIF_HEADER
/** \brief Name of the MemIf (/MemIf/MemIf) module's main header file */
#define BASE_MEMIF_HEADER <MemIf.h>
#endif

#ifndef BASE_MEMMAP_ENABLED
/** \brief Enable status of the module MemMap (/MemMap/MemMap) (VariantPreCompile) */
#define BASE_MEMMAP_ENABLED STD_ON
#endif

#ifndef BASE_MEMMAP_HEADER
/** \brief Name of the MemMap (/MemMap/MemMap) module's main header file */
#define BASE_MEMMAP_HEADER <MemMap.h>
#endif

#ifndef BASE_NM_ENABLED
/** \brief Enable status of the module Nm (/Nm/Nm) (VariantPreCompile) */
#define BASE_NM_ENABLED STD_ON
#endif

#ifndef BASE_NM_HEADER
/** \brief Name of the Nm (/Nm/Nm) module's main header file */
#define BASE_NM_HEADER <Nm.h>
#endif

#ifndef BASE_NVM_ENABLED
/** \brief Enable status of the module NvM (/NvM/NvM) (VariantPreCompile) */
#define BASE_NVM_ENABLED STD_ON
#endif

#ifndef BASE_NVM_HEADER
/** \brief Name of the NvM (/NvM/NvM) module's main header file */
#define BASE_NVM_HEADER <NvM.h>
#endif

#ifndef BASE_OS_ENABLED
/** \brief Enable status of the module Os (/Os/Os) (VariantPreCompile) */
#define BASE_OS_ENABLED STD_ON
#endif

#ifndef BASE_OS_HEADER
/** \brief Name of the Os (/Os/Os) module's main header file */
#define BASE_OS_HEADER <Os.h>
#endif

#ifndef BASE_PBCFGM_ENABLED
/** \brief Enable status of the module PbcfgM (/PbcfgM/PbcfgM) (VariantPostBuild) */
#define BASE_PBCFGM_ENABLED STD_ON
#endif

#ifndef BASE_PBCFGM_CONFIG_PTR
/** \brief Address of the post build configuration for PbcfgM */
#define BASE_PBCFGM_CONFIG_PTR (&(PbcfgM_Config.PbcfgM_RootConfig))
#endif

#ifndef BASE_PBCFGM_HEADER
/** \brief Name of the PbcfgM (/PbcfgM/PbcfgM) module's main header file */
#define BASE_PBCFGM_HEADER <PbcfgM.h>
#endif

#ifndef BASE_PDUR_ENABLED
/** \brief Enable status of the module PduR (/PduR/PduR) (VariantPostBuild) */
#define BASE_PDUR_ENABLED STD_ON
#endif


#ifndef BASE_PDUR_CONFIG_PTR
/** \brief Address of the first multiple configuration container for PduR (/PduR/PduR) */
#define BASE_PDUR_CONFIG_PTR (&PduRRoutingTables)
#endif

#ifndef BASE_PDUR_HEADER
/** \brief Name of the PduR (/PduR/PduR) module's main header file */
#define BASE_PDUR_HEADER <PduR.h>
#endif

#ifndef BASE_PORT_ENABLED
/** \brief Enable status of the module Port (/Port/Port) (VariantPostBuild) */
#define BASE_PORT_ENABLED STD_ON
#endif

#ifndef BASE_PORT_HEADER
/** \brief Name of the Port (/Port/Port) module's main header file */
#define BASE_PORT_HEADER <Port.h>
#endif

#ifndef BASE_PWM_ENABLED
/** \brief Enable status of the module Pwm (/Pwm/Pwm) (VariantPostBuild) */
#define BASE_PWM_ENABLED STD_ON
#endif

#ifndef BASE_PWM_17_GTMCCU6_ENABLED
/** \brief Enable status of the module Pwm (/Pwm/Pwm) (VariantPostBuild) */
#define BASE_PWM_17_GTMCCU6_ENABLED STD_ON
#endif

#ifndef BASE_PWM_HEADER
/** \brief Name of the Pwm (/Pwm/Pwm) module's main header file */
#define BASE_PWM_HEADER <Pwm_17_GtmCcu6.h>
#endif

#ifndef BASE_PWM_17_GTMCCU6_HEADER
/** \brief Name of the Pwm (/Pwm/Pwm) module's main header file */
#define BASE_PWM_17_GTMCCU6_HEADER <Pwm_17_GtmCcu6.h>
#endif

#ifndef BASE_RESOURCEM_ENABLED
/** \brief Enable status of the module ResourceM (/ResourceM/ResourceM) (VariantPreCompile) */
#define BASE_RESOURCEM_ENABLED STD_ON
#endif

#ifndef BASE_RESOURCEM_HEADER
/** \brief Name of the ResourceM (/ResourceM/ResourceM) module's main header file */
#define BASE_RESOURCEM_HEADER <ResourceM.h>
#endif

#ifndef BASE_RTE_ENABLED
/** \brief Enable status of the module Rte (/Rte/Rte) (VariantPreCompile) */
#define BASE_RTE_ENABLED STD_ON
#endif

#ifndef BASE_RTE_HEADER
/** \brief Name of the Rte (/Rte/Rte) module's main header file */
#define BASE_RTE_HEADER <Rte.h>
#endif

#ifndef BASE_SMU_ENABLED
/** \brief Enable status of the module Smu (/Smu/Smu) (VariantPostBuild) */
#define BASE_SMU_ENABLED STD_ON
#endif

#ifndef BASE_SMU_HEADER
/** \brief Name of the Smu (/Smu/Smu) module's main header file */
#define BASE_SMU_HEADER <Smu.h>
#endif

#ifndef BASE_SPI_ENABLED
/** \brief Enable status of the module Spi (/Spi/Spi) (VariantPostBuild) */
#define BASE_SPI_ENABLED STD_ON
#endif

#ifndef BASE_SPI_HEADER
/** \brief Name of the Spi (/Spi/Spi) module's main header file */
#define BASE_SPI_HEADER <Spi.h>
#endif

#ifndef BASE_STBM_ENABLED
/** \brief Enable status of the module StbM (/StbM/StbM) (VariantPreCompile) */
#define BASE_STBM_ENABLED STD_ON
#endif

#ifndef BASE_STBM_HEADER
/** \brief Name of the StbM (/StbM/StbM) module's main header file */
#define BASE_STBM_HEADER <StbM.h>
#endif

#ifndef BASE_WDG_ENABLED
/** \brief Enable status of the module Wdg (/Wdg/Wdg) (VariantPostBuild) */
#define BASE_WDG_ENABLED STD_ON
#endif

#ifndef BASE_WDG_17_SCU_ENABLED
/** \brief Enable status of the module Wdg (/Wdg/Wdg) (VariantPostBuild) */
#define BASE_WDG_17_SCU_ENABLED STD_ON
#endif

#ifndef BASE_WDG_HEADER
/** \brief Name of the Wdg (/Wdg/Wdg) module's main header file */
#define BASE_WDG_HEADER <Wdg_17_Scu.h>
#endif

#ifndef BASE_WDG_17_SCU_HEADER
/** \brief Name of the Wdg (/Wdg/Wdg) module's main header file */
#define BASE_WDG_17_SCU_HEADER <Wdg_17_Scu.h>
#endif

#ifndef BASE_WDGIF_ENABLED
/** \brief Enable status of the module WdgIf (/WdgIf/WdgIf) (VariantPreCompile) */
#define BASE_WDGIF_ENABLED STD_ON
#endif

#ifndef BASE_WDGIF_HEADER
/** \brief Name of the WdgIf (/WdgIf/WdgIf) module's main header file */
#define BASE_WDGIF_HEADER <WdgIf.h>
#endif

#ifndef BASE_WDGM_ENABLED
/** \brief Enable status of the module WdgM (/WdgM/WdgM) (VariantPreCompile) */
#define BASE_WDGM_ENABLED STD_ON
#endif


#ifndef BASE_WDGM_CONFIG_PTR
/** \brief Address of the first multiple configuration container for WdgM (/WdgM/WdgM) */
#define BASE_WDGM_CONFIG_PTR (&WdgM_Config)
#endif

#ifndef BASE_WDGM_HEADER
/** \brief Name of the WdgM (/WdgM/WdgM) module's main header file */
#define BASE_WDGM_HEADER <WdgM.h>
#endif

#ifndef BASE_XCP_ENABLED
/** \brief Enable status of the module Xcp (/Xcp/Xcp) (VariantPreCompile) */
#define BASE_XCP_ENABLED STD_ON
#endif


#ifndef BASE_XCP_CONFIG_PTR
/** \brief Address of the first multiple configuration container for Xcp (/Xcp/Xcp) */
#define BASE_XCP_CONFIG_PTR (&XcpConfig_0)
#endif

#ifndef BASE_XCP_HEADER
/** \brief Name of the Xcp (/Xcp/Xcp) module's main header file */
#define BASE_XCP_HEADER <Xcp.h>
#endif

#endif /* ifndef BASE_MODULES_H */
/*==================[end of file]============================================*/
