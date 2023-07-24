/**
 * \file
 *
 * \brief AUTOSAR FiM
 *
 * This file contains the implementation of the AUTOSAR
 * module FiM.
 *
 * \version 2.5.4
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2021 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

/*==================[inclusions]============================================*/
/* !LINKSTO dsn.FiM.IncludeStr,1 */

#include <Std_Types.h>         /* AUTOSAR standard types */

#include <Dem.h>               /* Dem event IDs */

#include <FiM.h>               /* Module public API */
#include <FiM_Int.h>           /* Module internal interface */

/*==================[macros]================================================*/

/* bit masks for the inhibition mask configuration part of the event link
 * configuration */

#if (defined FIM_LAST_FAILED_CFG_MASK)
#error FIM_LAST_FAILED_CFG_MASK already defined
#endif
/** \brief FiM last failed inhibition mask index configuration mask
 * (used by FiM_EvtConfigData[] and FiM_FidConfigData[]) */
#define FIM_LAST_FAILED_CFG_MASK                ((uint16)0U << FIM_CONFIG_INHIBITION_MASK_OFFSET)

#if (defined FIM_NOT_TESTED_CFG_MASK)
#error FIM_NOT_TESTED_CFG_MASK already defined
#endif
/** \brief FiM not tested inhibition mask index configuration mask
 * (used by FiM_EvtConfigData[] and FiM_FidConfigData[]) */
#define FIM_NOT_TESTED_CFG_MASK                 ((uint16)1U << FIM_CONFIG_INHIBITION_MASK_OFFSET)

#if (defined FIM_TESTED_CFG_MASK)
#error FIM_TESTED_CFG_MASK already defined
#endif
/** \brief FiM tested inhibition mask index configuration mask
 * (used by FiM_EvtConfigData[] and FiM_FidConfigData[]) */
#define FIM_TESTED_CFG_MASK                     ((uint16)2U << FIM_CONFIG_INHIBITION_MASK_OFFSET)

#if (defined FIM_TESTED_AND_FAILED_CFG_MASK)
#error FIM_TESTED_AND_FAILED_CFG_MASK already defined
#endif
/** \brief FiM tested and failed inhibition mask index configuration mask
 * (used by FiM_EvtConfigData[] and FiM_FidConfigData[]) */
#define FIM_TESTED_AND_FAILED_CFG_MASK          ((uint16)3U << FIM_CONFIG_INHIBITION_MASK_OFFSET)


#if (FIM_EXTENDED_LEVEL != FIM_NO_EXTENSION)

#if (defined FIM_FAILED_THIS_OP_CYCLE_CFG_MASK)
#error FIM_FAILED_THIS_OP_CYCLE_CFG_MASK already defined
#endif
/** \brief UDS status byte bit 1 (testFailedThisOperationCycle) inhibition mask index configuration mask
 * (used by FiM_EvtConfigData[] and FiM_FidConfigData[]) */
#define FIM_FAILED_THIS_OP_CYCLE_CFG_MASK       ((uint16)4U << FIM_CONFIG_INHIBITION_MASK_OFFSET)

#if (defined FIM_LAST_UNCONFIRMED_CFG_MASK)
#error FIM_LAST_UNCONFIRMED_CFG_MASK already defined
#endif
/** \brief SI30 status byte bit 0 (UnconfirmedDTC) inhibition mask index configuration mask
 * (used by FiM_EvtConfigData[] and FiM_FidConfigData[]) */
#define FIM_LAST_UNCONFIRMED_CFG_MASK           ((uint16)5U << FIM_CONFIG_INHIBITION_MASK_OFFSET)

#if (defined FIM_UNCONFIRMED_THIS_OP_CYCLE_CFG_MASK)
#error FIM_UNCONFIRMED_THIS_OP_CYCLE_CFG_MASK already defined
#endif
/** \brief SI30 status byte bit 1 (UnconfirmedDTCThisOperationCycle) inhibition mask index configuration mask
 * (used by FiM_EvtConfigData[] and FiM_FidConfigData[]) */
#define FIM_UNCONFIRMED_THIS_OP_CYCLE_CFG_MASK  ((uint16)6U << FIM_CONFIG_INHIBITION_MASK_OFFSET)

#endif

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[internal constants]====================================*/

/*==================[external constants]====================================*/


#define FIM_START_SEC_CONST_UNSPECIFIED
#include <FiM_MemMap.h>

CONST(FiM_ConfigType, FIM_CONST) FiM_Config_0 = 0U;

#define FIM_STOP_SEC_CONST_UNSPECIFIED
#include <FiM_MemMap.h>

#define FIM_START_SEC_CONST_UNSPECIFIED
#include <FiM_MemMap.h>

/* !LINKSTO dsn.FIM.DataStructure.AccessedByFID,1, dsn.FIM.DataStructure.PollingMode,1 */
/** \brief Array of start index of the corresponding Dem events in the data array */
CONST(FiM_FidConfigStartIndexType, FIM_CONST) FiM_FidConfigStartIndex[FIM_FID_STARTINDEX_NUM] =
{
  0U,
  59U,
  116U,
  169U,
  169U,
  220U,
  278U,
  278U,
  300U,
  301U,
};

#define FIM_STOP_SEC_CONST_UNSPECIFIED
#include <FiM_MemMap.h>

#define FIM_START_SEC_CALIB_16
#include <FiM_MemMap.h>

/* !LINKSTO dsn.FIM.DataStructure.Calibration,1, dsn.FiM.VCC.HighPriorityInhibition,1 */
/** \brief Array of all calibrated inhibition mask and Dem events for FIDs */
CONST(FiM_FidConfigDataType, FIM_CONST) FiM_FidConfigData[FIM_FID_CONFIGDATA_NUM] =
{
  /* ----- Events associated with FID 'FID_AEB' ----- */
  /* Dem event links of the event summary EVENT_SUMMARY_AEB_Deactive */
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_VCU_Accr_Pedl_Posn_Invld,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_VCU_Gear_Posn_Invld,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_BCM_Brake_Lamp_Error,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_ESP_Veh_Spd_Invld,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_ESP_ABS_Fault,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_ESP_TCS_Fault,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_Esp_Ebd_Failr,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_ESP_ABA_NOT_Available,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_ESP_AEB_NOT_Available,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_ESP_AWB_NOT_Available,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_Whl_Spd_Pls_Invld,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_Whl_Spd_Dir_Invld,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_Whl_Spd_Data_Invld,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_IB_Brk_Pedl_Invld,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_EPS_Sas_NOT_Cal,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_EPS_Actual_Motor_Torq_Invld,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_EPS_Steer_AgSens_Fault,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_SRS_Drvr_BucSwt_Invld,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_ESP_Lat_Accel_Invld,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_ESP_Long_Accel_Invld,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_ESP_Yaw_Rate_Invld,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_EPS_Fault,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_EPS_APA_Epas_Fault,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_VCU_All_Node_Missing,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_ESP_All_Node_Missing,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_EPS_All_Node_Missing,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_BCM_All_Node_Missing,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_SRS_All_Node_Missing,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_FR_All_Node_Missing,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_ADC_All_Node_Missing,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_VCU_Message_Alive_Counter_Error,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_ESP_Message_Alive_Counter_Error,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_EPS_Message_Alive_Counter_Error_20ms,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_BCM_Message_Alive_Counter_Error_40ms,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_Front_Radar_Alive_Counter_Error,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_ADC_Message_Alive_Counter_Error,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_SRS_Message_Alive_Counter_Error,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_VMON_BATT_HIGH,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_VMON_BATT_LOW,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_MCU_TEMP_INITIAL_HIGH,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_MCU_TEMP_EXT_HIGH,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_MCU_TEMP_EXT_LOW,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_CAMERA_CALIBRATION_FAILURE,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_CAMERA_ONLINE_CALIBRATION_FAILURE,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_Fradar_not_calibration_or_blockage,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_Fradar_hardware_error,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_Private_CAN_Bus_Off,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_Public_CAN_Bus_Off,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_SPI_DRIVER_ERROR,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_J3_Time_Sync_Error,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_J3_SYS_KERNEL_SW,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_J3_SOC_System_Service_Error,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_J3_Camera_Error,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_J3_SOC_Perception_Error,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_J3_SOC_Safetylib_Error,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_J3_SOC_CPU_Error_PWM_Missing,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_SOCJ3_TEMP_EXT_HIGH,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_ESP_Message_Alive_Counter_Error_100ms,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_EPS_Message_Alive_Counter_Error_10ms,
  /* ----- Events associated with FID 'FID_ELK' ----- */
  /* Dem event links of the event summary EVENT_SUMMARY_ELK_Deactive */
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_VCU_Gear_Posn_Invld,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_ESP_Veh_Spd_Invld,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_ESP_ABS_Fault,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_ESP_TCS_Fault,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_Esp_Ebd_Failr,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_Whl_Spd_Pls_Invld,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_Whl_Spd_Dir_Invld,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_Whl_Spd_Data_Invld,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_EPS_Actual_Torsion_Torq_Invld,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_EPS_Actual_Motor_Invld,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_EPS_Sas_NOT_Cal,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_EPS_Actual_Motor_Torq_Invld,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_EPS_Steer_AgSens_Fault,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_SRS_Drvr_BucSwt_Invld,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_EPS_Pinionang_Invld,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_EPS_Pinionang_Fault,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_ESP_Lat_Accel_Invld,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_ESP_Long_Accel_Invld,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_ESP_Yaw_Rate_Invld,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_EPS_Fault,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_EPS_APA_Epas_Fault,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_BCM_EmgyLi_Fault,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_EPS_Driver_hand_torque_invalid,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_VCU_All_Node_Missing,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_ESP_All_Node_Missing,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_EPS_All_Node_Missing,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_BCM_All_Node_Missing,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_SRS_All_Node_Missing,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_ADC_All_Node_Missing,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_VCU_Message_Alive_Counter_Error,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_ESP_Message_Alive_Counter_Error,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_EPS_Message_Alive_Counter_Error_20ms,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_BCM_Message_Alive_Counter_Error_40ms,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_ADC_Message_Alive_Counter_Error,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_RLR_Message_Alive_Counter_Error,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_SRS_Message_Alive_Counter_Error,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_VMON_BATT_HIGH,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_VMON_BATT_LOW,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_MCU_TEMP_INITIAL_HIGH,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_MCU_TEMP_EXT_HIGH,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_MCU_TEMP_EXT_LOW,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_CAMERA_CALIBRATION_FAILURE,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_CAMERA_ONLINE_CALIBRATION_FAILURE,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_J3_Camera_Blockage,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_Private_CAN_Bus_Off,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_Public_CAN_Bus_Off,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_SPI_DRIVER_ERROR,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_J3_Time_Sync_Error,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_J3_SYS_KERNEL_SW,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_J3_SOC_System_Service_Error,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_J3_Camera_Error,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_J3_SOC_Perception_Error,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_J3_SOC_Safetylib_Error,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_J3_SOC_CPU_Error_PWM_Missing,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_SOCJ3_TEMP_EXT_HIGH,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_ESP_Message_Alive_Counter_Error_100ms,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_EPS_Message_Alive_Counter_Error_10ms,
  /* ----- Events associated with FID 'FID_FCW' ----- */
  /* Dem event links of the event summary EVENT_SUMMARY_FCW_Deactive */
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_VCU_Accr_Pedl_Posn_Invld,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_VCU_Gear_Posn_Invld,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_BCM_Brake_Lamp_Error,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_ESP_Veh_Spd_Invld,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_Whl_Spd_Pls_Invld,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_Whl_Spd_Dir_Invld,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_Whl_Spd_Data_Invld,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_IB_Brk_Pedl_Invld,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_EPS_Sas_NOT_Cal,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_EPS_Actual_Motor_Torq_Invld,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_EPS_Steer_AgSens_Fault,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_SRS_Drvr_BucSwt_Invld,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_ESP_Lat_Accel_Invld,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_ESP_Long_Accel_Invld,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_ESP_Yaw_Rate_Invld,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_EPS_Fault,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_EPS_APA_Epas_Fault,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_VCU_All_Node_Missing,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_ESP_All_Node_Missing,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_EPS_All_Node_Missing,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_BCM_All_Node_Missing,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_SRS_All_Node_Missing,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_FR_All_Node_Missing,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_ADC_All_Node_Missing,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_VCU_Message_Alive_Counter_Error,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_ESP_Message_Alive_Counter_Error,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_EPS_Message_Alive_Counter_Error_20ms,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_BCM_Message_Alive_Counter_Error_40ms,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_Front_Radar_Alive_Counter_Error,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_ADC_Message_Alive_Counter_Error,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_SRS_Message_Alive_Counter_Error,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_VMON_BATT_HIGH,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_VMON_BATT_LOW,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_MCU_TEMP_INITIAL_HIGH,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_MCU_TEMP_EXT_HIGH,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_MCU_TEMP_EXT_LOW,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_CAMERA_CALIBRATION_FAILURE,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_CAMERA_ONLINE_CALIBRATION_FAILURE,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_Fradar_not_calibration_or_blockage,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_Fradar_hardware_error,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_Private_CAN_Bus_Off,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_Public_CAN_Bus_Off,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_SPI_DRIVER_ERROR,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_J3_Time_Sync_Error,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_J3_SYS_KERNEL_SW,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_J3_SOC_System_Service_Error,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_J3_Camera_Error,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_J3_SOC_Perception_Error,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_J3_SOC_Safetylib_Error,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_J3_SOC_CPU_Error_PWM_Missing,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_SOCJ3_TEMP_EXT_HIGH,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_ESP_Message_Alive_Counter_Error_100ms,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_EPS_Message_Alive_Counter_Error_10ms,
  /* ----- Events associated with FID 'FID_HLA' ----- */
  /* Dem event links of the event summary EVENT_SUMMARY_HLA_Deactive */
  /* ----- Events associated with FID 'FID_LDW' ----- */
  /* Dem event links of the event summary EVENT_SUMMARY_LDW_Deactive */
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_VCU_Accr_Pedl_Posn_Invld,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_VCU_Gear_Posn_Invld,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_BCM_Turn_Indcr_Light_Fault,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_ESP_Veh_Spd_Invld,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_Whl_Spd_Pls_Invld,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_Whl_Spd_Dir_Invld,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_Whl_Spd_Data_Invld,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_EPS_Sas_NOT_Cal,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_EPS_Actual_Motor_Torq_Invld,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_EPS_Steer_AgSens_Fault,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_SRS_Drvr_BucSwt_Invld,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_ESP_Lat_Accel_Invld,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_ESP_Long_Accel_Invld,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_ESP_Yaw_Rate_Invld,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_EPS_Fault,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_EPS_APA_Epas_Fault,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_BCM_EmgyLi_Fault,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_EPS_Driver_hand_torque_invalid,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_VCU_All_Node_Missing,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_ESP_All_Node_Missing,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_EPS_All_Node_Missing,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_BCM_All_Node_Missing,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_SRS_All_Node_Missing,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_ADC_All_Node_Missing,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_VCU_Message_Alive_Counter_Error,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_ESP_Message_Alive_Counter_Error,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_EPS_Message_Alive_Counter_Error_20ms,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_BCM_Message_Alive_Counter_Error_40ms,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_ADC_Message_Alive_Counter_Error,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_SRS_Message_Alive_Counter_Error,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_VMON_BATT_HIGH,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_VMON_BATT_LOW,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_MCU_TEMP_INITIAL_HIGH,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_MCU_TEMP_EXT_HIGH,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_MCU_TEMP_EXT_LOW,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_CAMERA_CALIBRATION_FAILURE,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_CAMERA_ONLINE_CALIBRATION_FAILURE,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_J3_Camera_Blockage,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_Private_CAN_Bus_Off,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_Public_CAN_Bus_Off,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_SPI_DRIVER_ERROR,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_J3_Time_Sync_Error,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_J3_SYS_KERNEL_SW,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_J3_SOC_System_Service_Error,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_J3_Camera_Error,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_J3_SOC_Perception_Error,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_J3_SOC_Safetylib_Error,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_J3_SOC_CPU_Error_PWM_Missing,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_SOCJ3_TEMP_EXT_HIGH,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_ESP_Message_Alive_Counter_Error_100ms,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_EPS_Message_Alive_Counter_Error_10ms,
  /* ----- Events associated with FID 'FID_LKA' ----- */
  /* Dem event links of the event summary EVENT_SUMMARY_LKA_Deactive */
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_VCU_Accr_Pedl_Posn_Invld,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_VCU_Gear_Posn_Invld,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_BCM_Turn_Indcr_Light_Fault,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_ESP_Veh_Spd_Invld,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_ESP_ABS_Fault,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_ESP_TCS_Fault,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_Esp_Ebd_Failr,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_Whl_Spd_Pls_Invld,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_Whl_Spd_Dir_Invld,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_Whl_Spd_Data_Invld,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_EPS_Actual_Torsion_Torq_Invld,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_EPS_Actual_Motor_Invld,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_EPS_Sas_NOT_Cal,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_EPS_Actual_Motor_Torq_Invld,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_EPS_Steer_AgSens_Fault,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_SRS_Drvr_BucSwt_Invld,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_EPS_Pinionang_Invld,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_EPS_Pinionang_Fault,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_ESP_Lat_Accel_Invld,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_ESP_Long_Accel_Invld,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_ESP_Yaw_Rate_Invld,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_EPS_Fault,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_EPS_APA_Epas_Fault,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_BCM_EmgyLi_Fault,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_EPS_Driver_hand_torque_invalid,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_VCU_All_Node_Missing,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_ESP_All_Node_Missing,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_EPS_All_Node_Missing,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_BCM_All_Node_Missing,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_SRS_All_Node_Missing,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_ADC_All_Node_Missing,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_VCU_Message_Alive_Counter_Error,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_ESP_Message_Alive_Counter_Error,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_EPS_Message_Alive_Counter_Error_20ms,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_BCM_Message_Alive_Counter_Error_40ms,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_ADC_Message_Alive_Counter_Error,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_SRS_Message_Alive_Counter_Error,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_VMON_BATT_HIGH,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_VMON_BATT_LOW,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_MCU_TEMP_INITIAL_HIGH,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_MCU_TEMP_EXT_HIGH,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_MCU_TEMP_EXT_LOW,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_CAMERA_CALIBRATION_FAILURE,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_CAMERA_ONLINE_CALIBRATION_FAILURE,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_J3_Camera_Blockage,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_Private_CAN_Bus_Off,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_Public_CAN_Bus_Off,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_SPI_DRIVER_ERROR,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_J3_Time_Sync_Error,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_J3_SYS_KERNEL_SW,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_J3_SOC_System_Service_Error,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_J3_Camera_Error,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_J3_SOC_Perception_Error,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_J3_SOC_Safetylib_Error,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_J3_SOC_CPU_Error_PWM_Missing,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_SOCJ3_TEMP_EXT_HIGH,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_ESP_Message_Alive_Counter_Error_100ms,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_EPS_Message_Alive_Counter_Error_10ms,
  /* ----- Events associated with FID 'FID_TSA' ----- */
  /* Dem event links of the event summary EVENT_SUMMARY_TSA_Deactive */
  /* ----- Events associated with FID 'FID_FAB' ----- */
  /* Dem event links of the event summary EVENT_SUMMARY_FAB_Deactive */
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_ESP_Veh_Spd_Invld,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_ESP_All_Node_Missing,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_ESP_Message_Alive_Counter_Error,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_VMON_BATT_HIGH,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_VMON_BATT_LOW,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_MCU_TEMP_INITIAL_HIGH,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_MCU_TEMP_EXT_HIGH,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_MCU_TEMP_EXT_LOW,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_CAMERA_CALIBRATION_FAILURE,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_CAMERA_ONLINE_CALIBRATION_FAILURE,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_J3_Camera_Blockage,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_Private_CAN_Bus_Off,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_Public_CAN_Bus_Off,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_SPI_DRIVER_ERROR,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_J3_SYS_KERNEL_SW,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_J3_SOC_System_Service_Error,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_J3_Camera_Error,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_J3_SOC_Perception_Error,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_J3_SOC_Safetylib_Error,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_J3_SOC_CPU_Error_PWM_Missing,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_SOCJ3_TEMP_EXT_HIGH,
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_ESP_Message_Alive_Counter_Error_100ms,
  /* ----- Events associated with FID 'FID_U17A1F0' ----- */
  /* single Dem event link */
  FIM_LAST_FAILED_CFG_MASK | DemConf_DemEventParameter_DEM_DTC_EPS_Steering_wheel_vibration_failure,
};

#define FIM_STOP_SEC_CALIB_16
#include <FiM_MemMap.h>


/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

/*==================[internal function definitions]=========================*/

/*==================[end of file]===========================================*/
