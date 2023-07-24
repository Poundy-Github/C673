#ifndef RTE_ESH_TYPE_H
#define RTE_ESH_TYPE_H
/**
 * \file
 *
 * \brief AUTOSAR Rte
 *
 * This file contains the implementation of the AUTOSAR
 * module Rte.
 *
 * \version 6.6.3
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2021 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

/*
 * This file contains the application-specific types for component type Esh
 *
 * This file has been automatically generated by
 * EB tresos AutoCore Rte Generator Version 6.6.3
 * on Mon Jul 10 12:27:55 CST 2023. !!!IGNORE-LINE!!!
 */

/*
 * \addtogroup Rte Runtime Environment
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
/* ==================[Includes]=============================================== */
#include <Rte_Type.h>

/* ==================[Macros]================================================= */
/* ------------------[enumeration constants]---------------------------------- */
#ifndef RTE_CORE /* if included by software component */
#ifndef DemConf_DemEventParameter_MCU_E_CLOCK_FAILURE
#define DemConf_DemEventParameter_MCU_E_CLOCK_FAILURE 1U
#endif
#ifndef DemConf_DemEventParameter_MCU_E_OSC_FAILURE
#define DemConf_DemEventParameter_MCU_E_OSC_FAILURE 2U
#endif
#ifndef DemConf_DemEventParameter_MCU_E_SYSTEM_PLL_TIMEOUT_ERR
#define DemConf_DemEventParameter_MCU_E_SYSTEM_PLL_TIMEOUT_ERR 3U
#endif
#ifndef DemConf_DemEventParameter_MCU_E_PERIPHERAL_PLL_TIMEOUT_ERR
#define DemConf_DemEventParameter_MCU_E_PERIPHERAL_PLL_TIMEOUT_ERR 4U
#endif
#ifndef DemConf_DemEventParameter_MCU_E_SYSTEM_PLL_LOCK_LOSS
#define DemConf_DemEventParameter_MCU_E_SYSTEM_PLL_LOCK_LOSS 5U
#endif
#ifndef DemConf_DemEventParameter_MCU_E_PERIPHERAL_PLL_LOCK_LOSS
#define DemConf_DemEventParameter_MCU_E_PERIPHERAL_PLL_LOCK_LOSS 6U
#endif
#ifndef DemConf_DemEventParameter_MCU_E_GTM_CLC_ENABLE_ERR
#define DemConf_DemEventParameter_MCU_E_GTM_CLC_ENABLE_ERR 7U
#endif
#ifndef DemConf_DemEventParameter_MCU_E_GTM_CLC_DISABLE_ERR
#define DemConf_DemEventParameter_MCU_E_GTM_CLC_DISABLE_ERR 8U
#endif
#ifndef DemConf_DemEventParameter_MCU_E_CONVCTRL_CLC_ENABLE_ERR
#define DemConf_DemEventParameter_MCU_E_CONVCTRL_CLC_ENABLE_ERR 9U
#endif
#ifndef DemConf_DemEventParameter_MCU_E_CONVCTRL_CLC_DISABLE_ERR
#define DemConf_DemEventParameter_MCU_E_CONVCTRL_CLC_DISABLE_ERR 10U
#endif
#ifndef DemConf_DemEventParameter_MCU_E_CCUCON_UPDATE_ERR
#define DemConf_DemEventParameter_MCU_E_CCUCON_UPDATE_ERR 11U
#endif
#ifndef DemConf_DemEventParameter_MCU_E_CCU6_CLC_ENABLE_ERR
#define DemConf_DemEventParameter_MCU_E_CCU6_CLC_ENABLE_ERR 12U
#endif
#ifndef DemConf_DemEventParameter_MCU_E_CCU6_CLC_DISABLE_ERR
#define DemConf_DemEventParameter_MCU_E_CCU6_CLC_DISABLE_ERR 13U
#endif
#ifndef DemConf_DemEventParameter_MCU_E_GPT12_CLC_ENABLE_ERR
#define DemConf_DemEventParameter_MCU_E_GPT12_CLC_ENABLE_ERR 14U
#endif
#ifndef DemConf_DemEventParameter_MCU_E_GPT12_CLC_DISABLE_ERR
#define DemConf_DemEventParameter_MCU_E_GPT12_CLC_DISABLE_ERR 15U
#endif
#ifndef DemConf_DemEventParameter_MCU_E_PMSWCR_UPDATE_ERR
#define DemConf_DemEventParameter_MCU_E_PMSWCR_UPDATE_ERR 16U
#endif
#ifndef DemConf_DemEventParameter_CANSM_BUSOFF_PublicCAN
#define DemConf_DemEventParameter_CANSM_BUSOFF_PublicCAN 17U
#endif
#ifndef DemConf_DemEventParameter_SPI_E_HARDWARE_ERROR
#define DemConf_DemEventParameter_SPI_E_HARDWARE_ERROR 18U
#endif
#ifndef DemConf_DemEventParameter_DEM_VMON_BATT_HIGH
#define DemConf_DemEventParameter_DEM_VMON_BATT_HIGH 19U
#endif
#ifndef DemConf_DemEventParameter_DEM_VMON_BATT_LOW
#define DemConf_DemEventParameter_DEM_VMON_BATT_LOW 20U
#endif
#ifndef DemConf_DemEventParameter_DEM_MCU_TEMP_EXT_HIGH
#define DemConf_DemEventParameter_DEM_MCU_TEMP_EXT_HIGH 21U
#endif
#ifndef DemConf_DemEventParameter_DEM_MCU_TEMP_EXT_LOW
#define DemConf_DemEventParameter_DEM_MCU_TEMP_EXT_LOW 22U
#endif
#ifndef DemConf_DemEventParameter_DEM_SOCJ3_TEMP_EXT_HIGH
#define DemConf_DemEventParameter_DEM_SOCJ3_TEMP_EXT_HIGH 23U
#endif
#ifndef DemConf_DemEventParameter_DEM_J3_SYS_KERNEL_SW
#define DemConf_DemEventParameter_DEM_J3_SYS_KERNEL_SW 24U
#endif
#ifndef DemConf_DemEventParameter_AdcClcFailureNotification
#define DemConf_DemEventParameter_AdcClcFailureNotification 25U
#endif
#ifndef DemConf_DemEventParameter_AdcConvStopTimeNotification
#define DemConf_DemEventParameter_AdcConvStopTimeNotification 26U
#endif
#ifndef DemConf_DemEventParameter_FEE_E_GC_INIT
#define DemConf_DemEventParameter_FEE_E_GC_INIT 27U
#endif
#ifndef DemConf_DemEventParameter_FEE_E_WRITE
#define DemConf_DemEventParameter_FEE_E_WRITE 28U
#endif
#ifndef DemConf_DemEventParameter_FEE_E_READ
#define DemConf_DemEventParameter_FEE_E_READ 29U
#endif
#ifndef DemConf_DemEventParameter_FEE_E_GC_READ
#define DemConf_DemEventParameter_FEE_E_GC_READ 30U
#endif
#ifndef DemConf_DemEventParameter_FEE_E_GC_WRITE
#define DemConf_DemEventParameter_FEE_E_GC_WRITE 31U
#endif
#ifndef DemConf_DemEventParameter_FEE_E_GC_ERASE
#define DemConf_DemEventParameter_FEE_E_GC_ERASE 32U
#endif
#ifndef DemConf_DemEventParameter_FEE_E_INVALIDATE
#define DemConf_DemEventParameter_FEE_E_INVALIDATE 33U
#endif
#ifndef DemConf_DemEventParameter_FEE_E_WRITE_CYCLES_EXHAUSTED
#define DemConf_DemEventParameter_FEE_E_WRITE_CYCLES_EXHAUSTED 34U
#endif
#ifndef DemConf_DemEventParameter_FEE_E_GC_TRIG
#define DemConf_DemEventParameter_FEE_E_GC_TRIG 35U
#endif
#ifndef DemConf_DemEventParameter_FEE_E_UNCONFIG_BLK_EXCEEDED
#define DemConf_DemEventParameter_FEE_E_UNCONFIG_BLK_EXCEEDED 36U
#endif
#ifndef DemConf_DemEventParameter_FLS_E_COMPARE_FAILED
#define DemConf_DemEventParameter_FLS_E_COMPARE_FAILED 37U
#endif
#ifndef DemConf_DemEventParameter_FLS_E_ERASE_FAILED
#define DemConf_DemEventParameter_FLS_E_ERASE_FAILED 38U
#endif
#ifndef DemConf_DemEventParameter_FLS_E_READ_FAILED
#define DemConf_DemEventParameter_FLS_E_READ_FAILED 39U
#endif
#ifndef DemConf_DemEventParameter_FLS_E_UNEXPECTED_FLASH_ID
#define DemConf_DemEventParameter_FLS_E_UNEXPECTED_FLASH_ID 40U
#endif
#ifndef DemConf_DemEventParameter_FLS_E_WRITE_FAILED
#define DemConf_DemEventParameter_FLS_E_WRITE_FAILED 41U
#endif
#ifndef DemConf_DemEventParameter_DEM_CAMERA_CALIBRATION_FAILURE
#define DemConf_DemEventParameter_DEM_CAMERA_CALIBRATION_FAILURE 42U
#endif
#ifndef DemConf_DemEventParameter_DEM_CAMERA_ONLINE_CALIBRATION_FAILURE
#define DemConf_DemEventParameter_DEM_CAMERA_ONLINE_CALIBRATION_FAILURE 43U
#endif
#ifndef DemConf_DemEventParameter_CANSM_BUSOFF_PrivateCAN
#define DemConf_DemEventParameter_CANSM_BUSOFF_PrivateCAN 44U
#endif
#ifndef DemConf_DemEventParameter_DEM_DTC_VCU_Accr_Pedl_Posn_Invld
#define DemConf_DemEventParameter_DEM_DTC_VCU_Accr_Pedl_Posn_Invld 45U
#endif
#ifndef DemConf_DemEventParameter_DEM_DTC_VCU_Gear_Posn_Invld
#define DemConf_DemEventParameter_DEM_DTC_VCU_Gear_Posn_Invld 46U
#endif
#ifndef DemConf_DemEventParameter_DEM_DTC_BCM_Turn_Indcr_Light_Fault
#define DemConf_DemEventParameter_DEM_DTC_BCM_Turn_Indcr_Light_Fault 47U
#endif
#ifndef DemConf_DemEventParameter_DEM_DTC_BCM_Frnt_Wiper_Sts_Fault
#define DemConf_DemEventParameter_DEM_DTC_BCM_Frnt_Wiper_Sts_Fault 48U
#endif
#ifndef DemConf_DemEventParameter_DEM_DTC_ESP_Veh_Spd_Invld
#define DemConf_DemEventParameter_DEM_DTC_ESP_Veh_Spd_Invld 49U
#endif
#ifndef DemConf_DemEventParameter_DEM_DTC_Whl_Spd_Pls_Invld
#define DemConf_DemEventParameter_DEM_DTC_Whl_Spd_Pls_Invld 50U
#endif
#ifndef DemConf_DemEventParameter_DEM_DTC_Whl_Spd_Dir_Invld
#define DemConf_DemEventParameter_DEM_DTC_Whl_Spd_Dir_Invld 51U
#endif
#ifndef DemConf_DemEventParameter_DEM_DTC_Whl_Spd_Data_Invld
#define DemConf_DemEventParameter_DEM_DTC_Whl_Spd_Data_Invld 52U
#endif
#ifndef DemConf_DemEventParameter_DEM_DTC_EPS_Sas_NOT_Cal
#define DemConf_DemEventParameter_DEM_DTC_EPS_Sas_NOT_Cal 53U
#endif
#ifndef DemConf_DemEventParameter_DEM_DTC_EPS_Actual_Motor_Torq_Invld
#define DemConf_DemEventParameter_DEM_DTC_EPS_Actual_Motor_Torq_Invld 54U
#endif
#ifndef DemConf_DemEventParameter_DEM_DTC_ESP_Lat_Accel_Invld
#define DemConf_DemEventParameter_DEM_DTC_ESP_Lat_Accel_Invld 55U
#endif
#ifndef DemConf_DemEventParameter_DEM_DTC_ESP_Long_Accel_Invld
#define DemConf_DemEventParameter_DEM_DTC_ESP_Long_Accel_Invld 56U
#endif
#ifndef DemConf_DemEventParameter_DEM_DTC_ESP_Yaw_Rate_Invld
#define DemConf_DemEventParameter_DEM_DTC_ESP_Yaw_Rate_Invld 57U
#endif
#ifndef DemConf_DemEventParameter_DEM_DTC_EPS_Fault
#define DemConf_DemEventParameter_DEM_DTC_EPS_Fault 58U
#endif
#ifndef DemConf_DemEventParameter_DEM_DTC_VCU_All_Node_Missing
#define DemConf_DemEventParameter_DEM_DTC_VCU_All_Node_Missing 59U
#endif
#ifndef DemConf_DemEventParameter_DEM_DTC_ESP_All_Node_Missing
#define DemConf_DemEventParameter_DEM_DTC_ESP_All_Node_Missing 60U
#endif
#ifndef DemConf_DemEventParameter_DEM_DTC_EPS_All_Node_Missing
#define DemConf_DemEventParameter_DEM_DTC_EPS_All_Node_Missing 61U
#endif
#ifndef DemConf_DemEventParameter_DEM_DTC_VCU_Message_Alive_Counter_Error
#define DemConf_DemEventParameter_DEM_DTC_VCU_Message_Alive_Counter_Error 62U
#endif
#ifndef DemConf_DemEventParameter_DEM_DTC_ESP_Message_Alive_Counter_Error
#define DemConf_DemEventParameter_DEM_DTC_ESP_Message_Alive_Counter_Error 63U
#endif
#ifndef DemConf_DemEventParameter_DEM_DTC_EPS_Message_Alive_Counter_Error_10ms
#define DemConf_DemEventParameter_DEM_DTC_EPS_Message_Alive_Counter_Error_10ms 64U
#endif
#ifndef DemConf_DemEventParameter_DEM_DTC_Front_Radar_Alive_Counter_Error
#define DemConf_DemEventParameter_DEM_DTC_Front_Radar_Alive_Counter_Error 65U
#endif
#ifndef DemConf_DemEventParameter_DEM_DTC_ESP_ABS_Fault
#define DemConf_DemEventParameter_DEM_DTC_ESP_ABS_Fault 66U
#endif
#ifndef DemConf_DemEventParameter_DEM_DTC_ESP_TCS_Fault
#define DemConf_DemEventParameter_DEM_DTC_ESP_TCS_Fault 67U
#endif
#ifndef DemConf_DemEventParameter_DEM_DTC_ESP_ABA_NOT_Available
#define DemConf_DemEventParameter_DEM_DTC_ESP_ABA_NOT_Available 68U
#endif
#ifndef DemConf_DemEventParameter_DEM_DTC_ESP_AEB_NOT_Available
#define DemConf_DemEventParameter_DEM_DTC_ESP_AEB_NOT_Available 69U
#endif
#ifndef DemConf_DemEventParameter_DEM_DTC_ESP_AWB_NOT_Available
#define DemConf_DemEventParameter_DEM_DTC_ESP_AWB_NOT_Available 70U
#endif
#ifndef DemConf_DemEventParameter_DEM_DTC_IB_Brk_Pedl_Invld
#define DemConf_DemEventParameter_DEM_DTC_IB_Brk_Pedl_Invld 71U
#endif
#ifndef DemConf_DemEventParameter_DEM_DTC_EPS_Actual_Torsion_Torq_Invld
#define DemConf_DemEventParameter_DEM_DTC_EPS_Actual_Torsion_Torq_Invld 72U
#endif
#ifndef DemConf_DemEventParameter_DEM_DTC_EPS_Actual_Motor_Invld
#define DemConf_DemEventParameter_DEM_DTC_EPS_Actual_Motor_Invld 73U
#endif
#ifndef DemConf_DemEventParameter_DEM_DTC_EPS_Steer_AgSens_Fault
#define DemConf_DemEventParameter_DEM_DTC_EPS_Steer_AgSens_Fault 74U
#endif
#ifndef DemConf_DemEventParameter_DEM_DTC_SRS_Drvr_BucSwt_Invld
#define DemConf_DemEventParameter_DEM_DTC_SRS_Drvr_BucSwt_Invld 75U
#endif
#ifndef DemConf_DemEventParameter_DEM_DTC_EPS_Pinionang_Invld
#define DemConf_DemEventParameter_DEM_DTC_EPS_Pinionang_Invld 76U
#endif
#ifndef DemConf_DemEventParameter_DEM_DTC_EPS_Pinionang_Fault
#define DemConf_DemEventParameter_DEM_DTC_EPS_Pinionang_Fault 77U
#endif
#ifndef DemConf_DemEventParameter_DEM_DTC_EPS_APA_Epas_Fault
#define DemConf_DemEventParameter_DEM_DTC_EPS_APA_Epas_Fault 78U
#endif
#ifndef DemConf_DemEventParameter_DEM_DTC_BCM_EmgyLi_Fault
#define DemConf_DemEventParameter_DEM_DTC_BCM_EmgyLi_Fault 79U
#endif
#ifndef DemConf_DemEventParameter_DEM_DTC_BCM_All_Node_Missing
#define DemConf_DemEventParameter_DEM_DTC_BCM_All_Node_Missing 80U
#endif
#ifndef DemConf_DemEventParameter_DEM_DTC_BCM_Message_Alive_Counter_Error_40ms
#define DemConf_DemEventParameter_DEM_DTC_BCM_Message_Alive_Counter_Error_40ms 81U
#endif
#ifndef DemConf_DemEventParameter_DEM_DTC_J3_Camera_Blockage
#define DemConf_DemEventParameter_DEM_DTC_J3_Camera_Blockage 82U
#endif
#ifndef DemConf_DemEventParameter_DEM_DTC_Private_CAN_Bus_Off
#define DemConf_DemEventParameter_DEM_DTC_Private_CAN_Bus_Off 83U
#endif
#ifndef DemConf_DemEventParameter_DEM_DTC_Public_CAN_Bus_Off
#define DemConf_DemEventParameter_DEM_DTC_Public_CAN_Bus_Off 84U
#endif
#ifndef DemConf_DemEventParameter_DEM_DTC_Ethernet_Unexpected_Link_Down
#define DemConf_DemEventParameter_DEM_DTC_Ethernet_Unexpected_Link_Down 85U
#endif
#ifndef DemConf_DemEventParameter_DEM_DTC_J3_SoC_ETH_IP_Ubnormal
#define DemConf_DemEventParameter_DEM_DTC_J3_SoC_ETH_IP_Ubnormal 86U
#endif
#ifndef DemConf_DemEventParameter_ECUM_E_RAM_CHECK_FAILED
#define DemConf_DemEventParameter_ECUM_E_RAM_CHECK_FAILED 87U
#endif
#ifndef DemConf_DemEventParameter_DEM_DTC_J3_SOC_Safetylib_Error
#define DemConf_DemEventParameter_DEM_DTC_J3_SOC_Safetylib_Error 88U
#endif
#ifndef DemConf_DemEventParameter_DEM_DTC_EPS_Steering_wheel_vibration_failure
#define DemConf_DemEventParameter_DEM_DTC_EPS_Steering_wheel_vibration_failure 89U
#endif
#ifndef DemConf_DemEventParameter_DEM_DTC_EPS_Driver_hand_torque_invalid
#define DemConf_DemEventParameter_DEM_DTC_EPS_Driver_hand_torque_invalid 90U
#endif
#ifndef DemConf_DemEventParameter_DEM_DTC_IP_warning_invalid
#define DemConf_DemEventParameter_DEM_DTC_IP_warning_invalid 91U
#endif
#ifndef DemConf_DemEventParameter_DEM_DTC_IP_node_missing
#define DemConf_DemEventParameter_DEM_DTC_IP_node_missing 92U
#endif
#ifndef DemConf_DemEventParameter_DEM_DTC_IP_message_alive_counter_error
#define DemConf_DemEventParameter_DEM_DTC_IP_message_alive_counter_error 93U
#endif
#ifndef DemConf_DemEventParameter_DEM_DTC_Fradar_not_calibration_or_blockage
#define DemConf_DemEventParameter_DEM_DTC_Fradar_not_calibration_or_blockage 94U
#endif
#ifndef DemConf_DemEventParameter_DEM_DTC_Fradar_hardware_error
#define DemConf_DemEventParameter_DEM_DTC_Fradar_hardware_error 95U
#endif
#ifndef DemConf_DemEventParameter_DEM_DTC_SRS_All_Node_Missing
#define DemConf_DemEventParameter_DEM_DTC_SRS_All_Node_Missing 96U
#endif
#ifndef DemConf_DemEventParameter_DEM_DTC_ADC_Message_Alive_Counter_Error
#define DemConf_DemEventParameter_DEM_DTC_ADC_Message_Alive_Counter_Error 97U
#endif
#ifndef DemConf_DemEventParameter_DEM_DTC_RLR_Message_Alive_Counter_Error
#define DemConf_DemEventParameter_DEM_DTC_RLR_Message_Alive_Counter_Error 98U
#endif
#ifndef DemConf_DemEventParameter_DEM_DTC_SRS_Message_Alive_Counter_Error
#define DemConf_DemEventParameter_DEM_DTC_SRS_Message_Alive_Counter_Error 99U
#endif
#ifndef DemConf_DemEventParameter_DEM_DTC_EPS_Message_Alive_Counter_Error_20ms
#define DemConf_DemEventParameter_DEM_DTC_EPS_Message_Alive_Counter_Error_20ms 100U
#endif
#ifndef DemConf_DemEventParameter_DEM_DTC_BCM_Message_Alive_Counter_Error_100ms
#define DemConf_DemEventParameter_DEM_DTC_BCM_Message_Alive_Counter_Error_100ms 101U
#endif
#ifndef DemConf_DemEventParameter_DEM_DTC_Private_CAN_Bus_Off_TOCAN
#define DemConf_DemEventParameter_DEM_DTC_Private_CAN_Bus_Off_TOCAN 102U
#endif
#ifndef DemConf_DemEventParameter_DEM_DTC_Public_CAN_Bus_Off_TOCAN
#define DemConf_DemEventParameter_DEM_DTC_Public_CAN_Bus_Off_TOCAN 103U
#endif
#ifndef DemConf_DemEventParameter_DEM_DTC_J3_Heavy_Rain_Detected
#define DemConf_DemEventParameter_DEM_DTC_J3_Heavy_Rain_Detected 104U
#endif
#ifndef DemConf_DemEventParameter_DEM_DTC_J3_Snow_Detected
#define DemConf_DemEventParameter_DEM_DTC_J3_Snow_Detected 105U
#endif
#ifndef DemConf_DemEventParameter_DEM_DTC_J3_Low_Sun_Detected
#define DemConf_DemEventParameter_DEM_DTC_J3_Low_Sun_Detected 106U
#endif
#ifndef DemConf_DemEventParameter_DEM_DTC_J3_SOC_System_Service_Error
#define DemConf_DemEventParameter_DEM_DTC_J3_SOC_System_Service_Error 107U
#endif
#ifndef DemConf_DemEventParameter_DEM_DTC_J3_Camera_Error
#define DemConf_DemEventParameter_DEM_DTC_J3_Camera_Error 108U
#endif
#ifndef DemConf_DemEventParameter_DEM_DTC_J3_SOC_CPU_Error_PWM_Missing
#define DemConf_DemEventParameter_DEM_DTC_J3_SOC_CPU_Error_PWM_Missing 109U
#endif
#ifndef DemConf_DemEventParameter_DEM_DTC_J3_SOC_Perception_Error
#define DemConf_DemEventParameter_DEM_DTC_J3_SOC_Perception_Error 110U
#endif
#ifndef DemConf_DemEventParameter_DEM_DTC_ETH_CRC_ERROR
#define DemConf_DemEventParameter_DEM_DTC_ETH_CRC_ERROR 111U
#endif
#ifndef DemConf_DemEventParameter_DEM_DTC_ETH_LINK_SIGNAL_WAKE
#define DemConf_DemEventParameter_DEM_DTC_ETH_LINK_SIGNAL_WAKE 112U
#endif
#ifndef DemConf_DemEventParameter_DEM_DTC_ETH_CABLE_FAULT
#define DemConf_DemEventParameter_DEM_DTC_ETH_CABLE_FAULT 113U
#endif
#ifndef DemConf_DemEventParameter_DEM_DTC_ETH_ICMP_ERROR
#define DemConf_DemEventParameter_DEM_DTC_ETH_ICMP_ERROR 114U
#endif
#ifndef DemConf_DemEventParameter_DEM_DTC_SPI_DRIVER_ERROR
#define DemConf_DemEventParameter_DEM_DTC_SPI_DRIVER_ERROR 115U
#endif
#ifndef DemConf_DemEventParameter_DEM_DTC_DFLASH_ERROR
#define DemConf_DemEventParameter_DEM_DTC_DFLASH_ERROR 116U
#endif
#ifndef DemConf_DemEventParameter_DEM_DTC_BCM_Brake_Lamp_Error
#define DemConf_DemEventParameter_DEM_DTC_BCM_Brake_Lamp_Error 117U
#endif
#ifndef DemConf_DemEventParameter_DEM_DTC_Esp_Ebd_Failr
#define DemConf_DemEventParameter_DEM_DTC_Esp_Ebd_Failr 118U
#endif
#ifndef DemConf_DemEventParameter_DEM_DTC_FR_All_Node_Missing
#define DemConf_DemEventParameter_DEM_DTC_FR_All_Node_Missing 119U
#endif
#ifndef DemConf_DemEventParameter_DEM_DTC_ADC_All_Node_Missing
#define DemConf_DemEventParameter_DEM_DTC_ADC_All_Node_Missing 120U
#endif
#ifndef DemConf_DemEventParameter_DEM_DTC_J3_Time_Sync_Error
#define DemConf_DemEventParameter_DEM_DTC_J3_Time_Sync_Error 121U
#endif
#ifndef DemConf_DemEventParameter_NVM_E_INTEGRITY_FAILED
#define DemConf_DemEventParameter_NVM_E_INTEGRITY_FAILED 122U
#endif
#ifndef DemConf_DemEventParameter_NVM_E_REQ_FAILED
#define DemConf_DemEventParameter_NVM_E_REQ_FAILED 123U
#endif
#ifndef DemConf_DemEventParameter_NVM_E_WRONG_BLOCK_ID
#define DemConf_DemEventParameter_NVM_E_WRONG_BLOCK_ID 124U
#endif
#ifndef DemConf_DemEventParameter_NVM_E_VERIFY_FAILED
#define DemConf_DemEventParameter_NVM_E_VERIFY_FAILED 125U
#endif
#ifndef DemConf_DemEventParameter_NVM_E_WRITE_PROTECTED
#define DemConf_DemEventParameter_NVM_E_WRITE_PROTECTED 126U
#endif
#ifndef DemConf_DemEventParameter_DEM_DTC_MCU_TEMP_INITIAL_HIGH
#define DemConf_DemEventParameter_DEM_DTC_MCU_TEMP_INITIAL_HIGH 127U
#endif
#ifndef DemConf_DemEventParameter_DEM_DTC_ESP_Message_Alive_Counter_Error_100ms
#define DemConf_DemEventParameter_DEM_DTC_ESP_Message_Alive_Counter_Error_100ms 128U
#endif
#ifndef DemConf_DemEventParameter_WDG_E_DISABLE_REJECTED
#define DemConf_DemEventParameter_WDG_E_DISABLE_REJECTED 129U
#endif
#ifndef DemConf_DemEventParameter_WDG_E_MODE_FAILED
#define DemConf_DemEventParameter_WDG_E_MODE_FAILED 130U
#endif
#ifndef DemConf_DemEventParameter_SmuActivateRunStateFailureNotification
#define DemConf_DemEventParameter_SmuActivateRunStateFailureNotification 131U
#endif
#ifndef DemConf_DemEventParameter_SmuClearAlarmStatusFailureNotification
#define DemConf_DemEventParameter_SmuClearAlarmStatusFailureNotification 132U
#endif
#ifndef DemConf_DemEventParameter_SmuReleaseFSPFailureNotification
#define DemConf_DemEventParameter_SmuReleaseFSPFailureNotification 133U
#endif
#ifndef DemConf_DemEventParameter_SmuCoreAliveFailureNotification
#define DemConf_DemEventParameter_SmuCoreAliveFailureNotification 134U
#endif
#ifndef DemConf_DemEventParameter_SmuRTStopFailureNotification
#define DemConf_DemEventParameter_SmuRTStopFailureNotification 135U
#endif
#ifndef DemConf_DemEventParameter_SmuActivatePESFailureNotification
#define DemConf_DemEventParameter_SmuActivatePESFailureNotification 136U
#endif
#ifndef DemConf_DemEventParameter_SmuActivateFSPFailureNotification
#define DemConf_DemEventParameter_SmuActivateFSPFailureNotification 137U
#endif
#ifndef DemConf_DemEventParameter_SmuSetAlarmStatusFailureNotification
#define DemConf_DemEventParameter_SmuSetAlarmStatusFailureNotification 138U
#endif
#ifndef DemConf_DemEventParameter_SmuSffFailureNotification
#define DemConf_DemEventParameter_SmuSffFailureNotification 139U
#endif
#ifndef FALSE
#define FALSE 0U
#endif
#ifndef TRUE
#define TRUE 1U
#endif
#ifndef E_SIG_STATUS_NONE
#define E_SIG_STATUS_NONE 0U
#endif
#ifndef E_SIG_STATUS_VALID
#define E_SIG_STATUS_VALID 1U
#endif
#ifndef E_SIG_STATUS_INVALID
#define E_SIG_STATUS_INVALID 16U
#endif
#ifndef E_SIG_STATUS_TOUT
#define E_SIG_STATUS_TOUT 17U
#endif
#ifndef E_SIG_STATUS_OUTOFRANGE
#define E_SIG_STATUS_OUTOFRANGE 19U
#endif
#ifndef E_SIG_STATUS_CRC
#define E_SIG_STATUS_CRC 18U
#endif
#ifndef E_SIG_STATUS_ROLLINGCNT
#define E_SIG_STATUS_ROLLINGCNT 20U
#endif
#ifndef E_SIG_STATUS_CRC_AND_ROLLINGCNT
#define E_SIG_STATUS_CRC_AND_ROLLINGCNT 21U
#endif
#ifndef E_SIG_STATUS_MAX
#define E_SIG_STATUS_MAX 255U
#endif
#ifndef DEM_CYCLE_STATE_START
#define DEM_CYCLE_STATE_START 0U
#endif
#ifndef DEM_CYCLE_STATE_END
#define DEM_CYCLE_STATE_END 1U
#endif
#endif

/* ------------------[range definitions]-------------------------------------- */
#ifndef RTE_CORE /* if included by software component */
#endif

/* ------------------[invalid values]----------------------------------------- */
#ifndef RTE_CORE /* if included by software component */
#endif

/* ------------------[mode declarations]-------------------------------------- */
#ifndef RTE_CORE /* if included by software component */
#ifndef RTE_TRANSITION_CANSM_ModeGroup
#define RTE_TRANSITION_CANSM_ModeGroup 4U
#endif
#ifndef RTE_MODE_CANSM_ModeGroup_CANSM_BSWM_BUS_OFF
#define RTE_MODE_CANSM_ModeGroup_CANSM_BSWM_BUS_OFF 0U
#endif
#ifndef RTE_MODE_CANSM_ModeGroup_CANSM_BSWM_FULL_COMMUNICATION
#define RTE_MODE_CANSM_ModeGroup_CANSM_BSWM_FULL_COMMUNICATION 1U
#endif
#ifndef RTE_MODE_CANSM_ModeGroup_CANSM_BSWM_NO_COMMUNICATION
#define RTE_MODE_CANSM_ModeGroup_CANSM_BSWM_NO_COMMUNICATION 2U
#endif
#ifndef RTE_MODE_CANSM_ModeGroup_CANSM_BSWM_SILENT_COMMUNICATION
#define RTE_MODE_CANSM_ModeGroup_CANSM_BSWM_SILENT_COMMUNICATION 3U
#endif
#endif

/* ------------------[API]---------------------------------------------------- */
#ifndef RTE_CORE /* if included by software component */
#endif

/* ==================[Types]================================================== */
/* ------------------[mode declaration group types]--------------------------- */
#ifndef RTE_CORE /* if included by software component */
#ifndef RTE_MODETYPE_CANSM_ModeGroup
#define RTE_MODETYPE_CANSM_ModeGroup
typedef VAR(uint8, TYPEDEF) Rte_ModeType_CANSM_ModeGroup;
#endif
#endif

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif
/** @} doxygen end group definition  */
/* ==================[end of file]============================================ */
