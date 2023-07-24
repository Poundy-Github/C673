/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC/LOPC/KMC (Adaptive Cruise Control - Longitudinal Planner and Controller - Kinematic Motion Control)

PACKAGENAME:               kmc_main.c

DESCRIPTION:               This file contains sequencing and main functions
                           concerning CruiseControl functionality

AUTHOR:                    Mistry Niraj (uidq5738)

CREATION DATE:             24.02.2017

VERSION:                   $Revision: 1.17 $

LEGACY VERSION:            Revision: 1.26.1.2

**************************************************************************** */

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/** 
@defgroup   kmc_main Kmc_Main
@ingroup    kmc
@brief      Main KMC functions
@{ */ 

#include "kmc.h"
#define CC_MAX_ACCEL_LAT_LIM_INIT_VALUE (acceleration_t)(10000)

#if ((FCT_CFG_LOPC_COMPONENT) && (FCT_CFG_CC) && (LOPC_CFG_KMC))

static void KMC_v_InitCCStatus(cc_status_t *cc_status);

/*************************************************************************************************************************
  Functionname:    KMC_v_InitCCStatus                                                                               */ /*!

  @brief           This function initializes the passed cc_status structure

  @description     This function initializes the passed cc_status structure

@startuml
Start
Partition KMC_v_InitCCStatus(){
: This Function Initializes;
      Note right
       Initialisation of Minimum Commanded Accelration\n
       Initialisation of Maximum Commanded Accelration\n
       Initialisation of Maximum requested Accelration\n
 	Initilaisation of deceleration limit Override Active\n
       Initialisation of Set Speed Level 1 and level2\n
       Initialisation of Operation mode\n
      End note
   }
End
@enduml

  @return          void

  @param[in,out]   *cc_status : Pointer to cc_status_t type structure containing CC status data
                        cc_status->CC_ACCEL_CONTROL_DATA.MINIMUM_COMMANDED_ACCELERATION :                   [full range of acceleration_t type as defined in Rte_Type.h]
                        cc_status->CC_ACCEL_CONTROL_DATA.MAXIMUM_COMMANDED_ACCELERATION :                   [full range of acceleration_t type as defined in Rte_Type.h]
                        cc_status->CC_ACCEL_CONTROL_DATA.MINIMUM_REQUESTED_ACCELERATION :                   [full range of acceleration_t type as defined in Rte_Type.h]
                        cc_status->CC_ACCEL_CONTROL_DATA.MAXIMUM_REQUESTED_ACCELERATION :                   [full range of acceleration_t type as defined in Rte_Type.h]
                        cc_status->CC_ACCEL_CONTROL_DATA.MINIMUM_REQUESTED_ACCELERATION_LAST_CYCLE :        [full range of acceleration_t type as defined in Rte_Type.h]
                        cc_status->CC_ACCEL_CONTROL_DATA.MAXIMUM_REQUESTED_ACCELERATION_LAST_CYCLE :        [full range of acceleration_t type as defined in Rte_Type.h]
                        cc_status->CC_ACCEL_CONTROL_DATA.MIN_ACCEL_POS_BAND :                               [full range of acceleration_t type as defined in Rte_Type.h]
                        cc_status->CC_ACCEL_CONTROL_DATA.MIN_ACCEL_NEG_BAND :                               [full range of acceleration_t type as defined in Rte_Type.h]
                        cc_status->CC_ACCEL_CONTROL_DATA.MAX_ACCEL_POS_BAND :                               [full range of acceleration_t type as defined in Rte_Type.h]
                        cc_status->CC_ACCEL_CONTROL_DATA.MAX_ACCEL_NEG_BAND :                               [full range of acceleration_t type as defined in Rte_Type.h]
                        cc_status->CC_ACCEL_CONTROL_DATA.MAXIMUM_ACCELERATION_LATERAL_LIMITED :             [full range of acceleration_t type as defined in Rte_Type.h]
                        cc_status->CC_ACCEL_CONTROL_DATA.ACCEL_STATUS.LAT_ACCEL_LIM_ACTIVE :                [ubit8_t type as defined in algo_types.h] [0u..1u]
                        cc_status->CC_ACCEL_CONTROL_DATA.ACCEL_STATUS.ACCEL_RAMP_ACTIVE :                   [ubit8_t type as defined in algo_types.h] [0u..1u]
                        cc_status->CC_ACCEL_CONTROL_DATA.ACCEL_STATUS.DECEL_LIM_ENGAGE :                    [ubit8_t type as defined in algo_types.h] [0u..1u]
                        cc_status->CC_ACCEL_CONTROL_DATA.ACCEL_STATUS.OBJECT_EFFECTIVE :                    [ubit8_t type as defined in algo_types.h] [0u..1u]
                        cc_status->CC_ACCEL_CONTROL_DATA.MIN_ALLOWED_ACCEL :                                [full range of acceleration_t type as defined in Rte_Type.h]
                        cc_status->CC_ACCEL_CONTROL_DATA.MAX_ALLOWED_ACCEL :                                [full range of acceleration_t type as defined in Rte_Type.h]
                        cc_status->CC_ACCEL_CONTROL_DATA.MIN_CUSTOM_ALLOWED_ACCEL :                         [full range of acceleration_t type as defined in Rte_Type.h]
                        cc_status->CC_ACCEL_CONTROL_DATA.MAX_CUSTOM_ALLOWED_ACCEL :                         [full range of acceleration_t type as defined in Rte_Type.h]
                        cc_status->CC_CONTROL_DATA.CC_ACCELERATION :                                        [full range of acceleration_t type as defined in Rte_Type.h]
                        cc_status->CC_CONTROL_DATA.LIM_ACCELERATION :                                       [full range of acceleration_t type as defined in Rte_Type.h]
                        cc_status->CC_CONTROL_DATA.MAXIMUM_ACCELERATION_LIMIT :                             [full range of acceleration_t type as defined in Rte_Type.h]
                        cc_status->CC_CONTROL_DATA.MINIMUM_ACCELERATION_LIMIT :                             [full range of acceleration_t type as defined in Rte_Type.h]
                        cc_status->CC_CONTROL_DATA.DECEL_LIM_OVERRIDE_ACTIVE :                              [full range of uint8 type as defined in Platform_Types.h]
                        cc_status->CC_CONTROL_DATA.CC_ACC_TO_CC_TRANSITION :                                [full range of uint8 type as defined in Platform_Types.h]
                        cc_status->CC_CONTROL_DATA.ACCELERATION_REQUEST_GRAD :                              [gradient_t type as defined in fct_types.h]
                        cc_status->CC_DRIVER_REQUESTS.SETSPEED_STEP_LEVEL_1 :                               [setspeed_t type as defined in fct_type.h] [0u..255u]
                        cc_status->CC_DRIVER_REQUESTS.SETSPEED_STEP_LEVEL_2 :                               [setspeed_t type as defined in fct_type.h] [0u..255u]
                        cc_status->CC_DRIVER_REQUESTS.CC_SETSPEED :                                         [setspeed_t type as defined in fct_type.h] [0u..255u]
                        cc_status->CC_DRIVER_REQUESTS.MIN_CC_SETSPEED :                                     [setspeed_t type as defined in fct_type.h] [0u..255u]
                        cc_status->CC_DRIVER_REQUESTS.MAX_CC_SETSPEED :                                     [setspeed_t type as defined in fct_type.h] [0u..255u]
                        cc_status->CC_DRIVER_REQUESTS.MAX_CC_SPEED :                                        [setspeed_t type as defined in fct_type.h] [0u..255u]
                        cc_status->CC_DRIVER_REQUESTS.CC_DISENGAGE_THRESHOLD :                              [setspeed_t type as defined in fct_type.h] [0u..255u]
                        cc_status->CC_DRIVER_REQUESTS.LIM_SETSPEED :                                        [setspeed_t type as defined in fct_type.h] [0u..255u]
                        cc_status->CC_DRIVER_REQUESTS.MIN_LIM_SETSPEED :                                    [setspeed_t type as defined in fct_type.h] [0u..255u]
                        cc_status->CC_DRIVER_REQUESTS.MAX_LIM_SETSPEED :                                    [setspeed_t type as defined in fct_type.h] [0u..255u]
                        cc_status->CC_DRIVER_REQUESTS.PLIM_THRESHOLD :                                      [setspeed_t type as defined in fct_type.h] [0u..255u]
                        cc_status->CC_DRIVER_REQUESTS.PLIM_HYST :                                           [setspeed_t type as defined in fct_type.h] [0u..255u]
                        cc_status->CC_DRIVER_REQUESTS.CONTROL_STATE_LAST_CYCLE :                            [full range of cc_control_state_t type as defined in cc_ext.h]
                        cc_status->CC_DRIVER_REQUESTS.CONTROL_STATE :                                       [full range of cc_control_state_t type as defined in cc_ext.h]
                        cc_status->CC_DRIVER_REQUESTS.CONTROL_STATE_PLIM :                                  [full range of cc_control_state_t type as defined in cc_ext.h]
                        cc_status->CC_DRIVER_REQUESTS.OPERATIONAL_MODE :                                    [full range of display_op_status_t type as defined in Rte_Type.h]
                        cc_status->CC_DRIVER_REQUESTS.DRIVER_REQUEST_STATUS.ACTUAL_SPEED_TAKEN_OVERRIDE :   [ubit8_t type as defined in algo_types.h] [0u..1u]
                        cc_status->CC_DRIVER_REQUESTS.DRIVER_REQUEST_STATUS.SELECTED_FUNCTION_ACTIVE :      [ubit8_t type as defined in algo_types.h] [0u..1u]
                        cc_status->CC_DRIVER_REQUESTS.DRIVER_REQUEST_STATUS.ACTUAL_SPEED_TAKEN_SET :        [ubit8_t type as defined in algo_types.h] [0u..1u]
                        cc_status->CC_DRIVER_REQUESTS.DRIVER_REQUEST_STATUS.TIMED_INCREMENT :               [ubit8_t type as defined in algo_types.h] [0u..1u]
                        cc_status->CC_DRIVER_REQUESTS.DRIVER_REQUEST_STATUS.TIMED_DECREMENT :               [ubit8_t type as defined in algo_types.h] [0u..1u]
                        cc_status->CC_DRIVER_REQUESTS.PLIM_VLIMIT :                                         [speedometer_speed_t as defined in fct_type.h] [-330..+330]
                        cc_status->CC_DRIVER_REQUESTS.SPEEDOMETER_VEHICLE_SPEED :                           [speedometer_speed_t as defined in fct_type.h] [-330..+330]
                        cc_status->CC_DRIVER_REQUESTS.SPEEDOMETER_VEHICLE_SPEED_OFFSET :                    [speedometer_speed_t as defined in fct_type.h] [-330..+330]
                        cc_status->CC_DRIVER_REQUESTS.DRIVER_OPERATIONS.SWITCH_SPEED_UNIT :                 [ubit8_t type as defined in algo_types.h] [0u..1u]
                        cc_status->CC_DRIVER_REQUESTS.DRIVE_OFF_TIME :                                      [full range of times_t type as defined in cc_ext.h]
                        cc_status->CC_DRIVER_REQUESTS.STAND_STILL_TIME :                                    [full range of times_t type as defined in cc_ext.h]

  @glob_in         -
  @glob_out        -

  @c_switch_part   CFG_FCT_CC_SMOOTH_ACCEL_REQUEST : Switch to configure filter to prevent oscillations and other discontinuous waveforms 
                                                               in acceleration request, which could lead to uncomfortable system behavior

  @c_switch_full   FCT_CFG_LOPC_COMPONENT : Configuration switch for enabling LOPC processing
                   FCT_CFG_CC : Configuration switch enabeling Cruise Control functionality (no object evaluation)

  @pre             -
  @post            -

  @created         -
  @changed         5/31/2016

  @author          -
*************************************************************************************************************************/
static void KMC_v_InitCCStatus(cc_status_t *cc_status)
{

  cc_status->CC_ACCEL_CONTROL_DATA.MINIMUM_COMMANDED_ACCELERATION = (acceleration_t)0;
  cc_status->CC_ACCEL_CONTROL_DATA.MAXIMUM_COMMANDED_ACCELERATION = (acceleration_t)0;
  cc_status->CC_ACCEL_CONTROL_DATA.MINIMUM_REQUESTED_ACCELERATION = (acceleration_t)0;
  cc_status->CC_ACCEL_CONTROL_DATA.MAXIMUM_REQUESTED_ACCELERATION = (acceleration_t)0;
#if (CFG_FCT_CC_SMOOTH_ACCEL_REQUEST)
  cc_status->CC_ACCEL_CONTROL_DATA.MINIMUM_REQUESTED_ACCELERATION_FILTERED = (acceleration_t)0;
  cc_status->CC_ACCEL_CONTROL_DATA.MAXIMUM_REQUESTED_ACCELERATION_FILTERED = (acceleration_t)0;
#endif
  cc_status->CC_ACCEL_CONTROL_DATA.MINIMUM_REQUESTED_ACCELERATION_LAST_CYCLE = (acceleration_t)0;
  cc_status->CC_ACCEL_CONTROL_DATA.MAXIMUM_REQUESTED_ACCELERATION_LAST_CYCLE = (acceleration_t)0;
#if(CFG_FCT_CC_USE_ACCEL_BAND_MODIFICATION)
  cc_status->CC_ACCEL_CONTROL_DATA.MIN_ACCEL_POS_BAND = (acceleration_t)0;
  cc_status->CC_ACCEL_CONTROL_DATA.MIN_ACCEL_NEG_BAND = (acceleration_t)0;
  cc_status->CC_ACCEL_CONTROL_DATA.MAX_ACCEL_POS_BAND = (acceleration_t)0;
  cc_status->CC_ACCEL_CONTROL_DATA.MAX_ACCEL_NEG_BAND = (acceleration_t)0;
#endif
  cc_status->CC_ACCEL_CONTROL_DATA.MAXIMUM_ACCELERATION_LATERAL_LIMITED = CC_MAX_ACCEL_LAT_LIM_INIT_VALUE;
#if (KMC_CFG_CUSTOM_LAT_LIM)  
  cc_status->CC_ACCEL_CONTROL_DATA.MAXIMUM_ACCELERATION_LATERAL_LIMITED_CUSTOM = CC_MAX_ACCEL_LAT_LIM_INIT_VALUE;
#endif   
  cc_status->CC_ACCEL_CONTROL_DATA.ACCEL_STATUS.LAT_ACCEL_LIM_ACTIVE = FALSE;
  cc_status->CC_ACCEL_CONTROL_DATA.ACCEL_STATUS.ACCEL_RAMP_ACTIVE = FALSE;
  cc_status->CC_ACCEL_CONTROL_DATA.ACCEL_STATUS.DECEL_LIM_ENGAGE = FALSE;
  cc_status->CC_ACCEL_CONTROL_DATA.ACCEL_STATUS.OBJECT_EFFECTIVE = FALSE;
  cc_status->CC_ACCEL_CONTROL_DATA.MIN_ALLOWED_ACCEL = (acceleration_t)0;
  cc_status->CC_ACCEL_CONTROL_DATA.MAX_ALLOWED_ACCEL = (acceleration_t)0;
  cc_status->CC_ACCEL_CONTROL_DATA.MIN_CUSTOM_ALLOWED_ACCEL = Accel_min;
  cc_status->CC_ACCEL_CONTROL_DATA.MAX_CUSTOM_ALLOWED_ACCEL = Accel_max;
  cc_status->CC_ACCEL_CONTROL_DATA.MIN_CUSTOM_ALLOWED_GRAD = Accelgradient_min;
  cc_status->CC_ACCEL_CONTROL_DATA.MAX_CUSTOM_ALLOWED_GRAD = Accelgradient_max;

  cc_status->CC_CONTROL_DATA.CC_ACCELERATION = (acceleration_t)0;
  cc_status->CC_CONTROL_DATA.LIM_ACCELERATION = (acceleration_t)0;
  cc_status->CC_CONTROL_DATA.MAXIMUM_ACCELERATION_LIMIT = Accel_max;
  cc_status->CC_CONTROL_DATA.MINIMUM_ACCELERATION_LIMIT = Accel_min;
  cc_status->CC_CONTROL_DATA.DECEL_LIM_OVERRIDE_ACTIVE = FALSE;
  cc_status->CC_CONTROL_DATA.CC_ACC_TO_CC_TRANSITION = FALSE;
  cc_status->CC_CONTROL_DATA.ACCELERATION_REQUEST_GRAD = (gradient_t)0;
#if(CFG_FCT_CC_SMOOTH_ACCEL_REQUEST)
  cc_status->CC_CONTROL_DATA.CC_ACCEL_FILTER_TIME = criticality_accel_filter_time[1]; /* Default value */
#endif

#if(LONG_CFG_USE_EXTERN_ACC_STATE_MACHINE)
  cc_status->CC_DRIVER_REQUESTS.CC_SETSPEED_CUSTOM = (cc_setspeed16_t)0;
#else
  cc_status->CC_DRIVER_REQUESTS.SETSPEED_STEP_LEVEL_1 = (setspeed_t)1;
  cc_status->CC_DRIVER_REQUESTS.SETSPEED_STEP_LEVEL_2 = (setspeed_t)1;
#endif
  cc_status->CC_DRIVER_REQUESTS.CC_SETSPEED = (setspeed_t)0;
  cc_status->CC_DRIVER_REQUESTS.MIN_CC_SETSPEED = (setspeed_t)0;
  cc_status->CC_DRIVER_REQUESTS.MAX_CC_SETSPEED = Cc_speed_default_value;
  cc_status->CC_DRIVER_REQUESTS.MAX_CC_SPEED = Cc_speed_default_value;
  cc_status->CC_DRIVER_REQUESTS.CC_DISENGAGE_THRESHOLD = (setspeed_t)0;
#if (CFG_FCT_LIM || CFG_FCT_PLIM)
  cc_status->CC_DRIVER_REQUESTS.LIM_SETSPEED = (setspeed_t)0;
  cc_status->CC_DRIVER_REQUESTS.MIN_LIM_SETSPEED = (setspeed_t)0;
  cc_status->CC_DRIVER_REQUESTS.MAX_LIM_SETSPEED = Cc_speed_default_value;
  cc_status->CC_DRIVER_REQUESTS.PLIM_THRESHOLD = (setspeed_t)0;
  cc_status->CC_DRIVER_REQUESTS.PLIM_HYST = (setspeed_t)0;
  cc_status->CC_DRIVER_REQUESTS.PLIM_VLIMIT = (speedometer_speed_t)0;
#endif
  cc_status->CC_DRIVER_REQUESTS.CONTROL_STATE_LAST_CYCLE = Cc_cc_off;
  cc_status->CC_DRIVER_REQUESTS.CONTROL_STATE = Cc_cc_off;
  cc_status->CC_DRIVER_REQUESTS.CONTROL_STATE_PLIM = Cc_cc_off;
  cc_status->CC_DRIVER_REQUESTS.OPERATIONAL_MODE = Display_op_none;
  cc_status->CC_DRIVER_REQUESTS.DRIVER_REQUEST_STATUS.ACTUAL_SPEED_TAKEN_OVERRIDE = FALSE;
  cc_status->CC_DRIVER_REQUESTS.DRIVER_REQUEST_STATUS.SELECTED_FUNCTION_ACTIVE = FALSE;
  cc_status->CC_DRIVER_REQUESTS.DRIVER_REQUEST_STATUS.ACTUAL_SPEED_TAKEN_SET = FALSE;
  cc_status->CC_DRIVER_REQUESTS.DRIVER_REQUEST_STATUS.TIMED_INCREMENT = FALSE;
  cc_status->CC_DRIVER_REQUESTS.DRIVER_REQUEST_STATUS.TIMED_DECREMENT = FALSE;
  cc_status->CC_DRIVER_REQUESTS.SPEEDOMETER_VEHICLE_SPEED = (speedometer_speed_t)0;
  cc_status->CC_DRIVER_REQUESTS.SPEEDOMETER_VEHICLE_SPEED_OFFSET = (speedometer_speed_t)0;
  cc_status->CC_DRIVER_REQUESTS.DRIVER_OPERATIONS.SWITCH_SPEED_UNIT = FALSE;
  cc_status->CC_DRIVER_REQUESTS.DRIVE_OFF_TIME = Cc_drive_off_smooth_time;
  cc_status->CC_DRIVER_REQUESTS.STAND_STILL_TIME = (times_t)0;

  #if (FCT_CFG_SLA_FEATURE)
  /* init SLA HMI structure */
  cc_status->CC_SLA_HMI_DATA.e_SLA_State = SLA_STATE_IDLE;
  cc_status->CC_SLA_HMI_DATA.SLA_Event.b_SLA_SAVE_DRIVER_SETSPEED = FALSE;
  cc_status->CC_SLA_HMI_DATA.SLA_Event.b_SLA_SET_DRIVER_SETSPEED = FALSE;
  cc_status->CC_SLA_HMI_DATA.SLA_Event.b_SLA_USAGE_AVAILABLE = FALSE;
  cc_status->CC_SLA_HMI_DATA.u_SLA_DriverLastSetSpeed = 0u;
  cc_status->CC_SLA_HMI_DATA.u_SLA_LastSetSpeedForTakeOver = 0u;
  cc_status->CC_SLA_HMI_DATA.SLA_SpeedLimitActualAccepted.u_SpeedLimit = 0u;
  cc_status->CC_SLA_HMI_DATA.SLA_SpeedLimitActualAccepted.u_SpeedLimitIncOffset = 0u;
  cc_status->CC_SLA_HMI_DATA.s_SLA_Offset = 0;
  cc_status->CC_SLA_HMI_DATA.SLA_SpeedLimitActualAccepted.u_SpeedLimitDistance = 0u;
  cc_status->CC_SLA_HMI_DATA.u_SLA_SpeedLimitLastAccepted = 0u;
  cc_status->CC_SLA_HMI_DATA.u_SLA_SpeedLimitLastDeclined = 0u;
  /* init SLA control structure */
  cc_status->CC_CONTROL_DATA.CC_SLA_CTRL_DATA.SLA_CtrlState.SLA_ACCEL_REQUEST_GRANTED = FALSE;
  cc_status->CC_CONTROL_DATA.CC_SLA_CTRL_DATA.s_SlaCtrlAccelRequest = (acceleration_t)0;
#endif
}

/*************************************************************************************************************************
  Functionname:    KMC_v_InitCC                                                                                     */ /*!

  @brief           This function initializes all data at system start.
                   This function needs to be called once before EXEC_CC is called

  @description     This function initializes all data at system start.
                   This function needs to be called once before EXEC_CC is called

@startuml
Start
Partition KMC_v_InitCC(){
:This function initializes all data at system start;
: Initialization;
note right
	Initialization of Acceleration Gradient\n
	Initialization of validity of lateral acceleration\n
	Initialization of validity of actual gear, Speedometer Vehicle Speed, Sports Mode\n
	Initialization of Vehicle Speed Limit and Current Speed Limit\n
	Initialization of speed Limit Distance and Offset\n
	Initialization of SLA Speed Status\n
	Initialization of Vehicle Status\n
end note
stop
@enduml


  @return          void

  @param[in,out]   *cc_input : Pointer to cc_input_data_t type structure containing input data to CC
                        cc_input->ACCELERATION_GRADIENT : Accelertion Gradient                          [gradient_t type as defined in fct_types.h]
                        cc_input->LATERAL_ACCELERATION : Lateral acceleration in y-direction            [full range of acceleration_t type as defined in Rte_Type.h]
                        cc_input->ACTUAL_GEAR : Gear position                                           [pt_gear_t type as defined in pt_ext.h] [Range as per TransmissionGear_t defined in Rte_Type.h]
                        cc_input->DATA_VALIDITY.LATERAL_ACCEL : Validity of lateral acceleration        [ubit8_t type as defined in algo_types.h] [0u..1u]
                        cc_input->DATA_VALIDITY.ACTUAL_GEAR : Validity of gear position                 [ubit8_t type as defined in algo_types.h] [0u..1u]
                        cc_input->DATA_VALIDITY.SPEEDO_SPEED : Validity of speed                        [ubit8_t type as defined in algo_types.h] [0u..1u]
                        cc_input->INHIBIT.CC_DISENGAGEMENT_DECEL_ONLY : Inhibition bit for deceleration [ubit8_t type as defined in algo_types.h] [0u..1u]
                        cc_input->INHIBIT.CC_DISENGAGEMENT_RAMP : Inhibition bit for ramp               [ubit8_t type as defined in algo_types.h] [0u..1u]
                        cc_input->INHIBIT.CC_DISENGAGEMENT_NO_RAMP : Inhibition bit for no ramp         [ubit8_t type as defined in algo_types.h] [0u..1u]
                        cc_input->VEHICLE_STATUS.SPEED_UNIT_KMH : status bit for speed unit             [ubit8_t type as defined in algo_types.h] [0u..1u]
                        cc_input->VEHICLE_STATUS.SPORTS_MODE : status bit for sports mode               [ubit8_t type as defined in algo_types.h] [0u..1u]
                        cc_input->SPEEDOMETER_VEHICLE_SPEED : Vehicle speed as per speedo meter         [speedometer_speed_t as defined in fct_type.h] [-330..+330]
                        cc_input->PERMANENT_LIMITER_SETSPEED : Maximum speed limitation                 [setspeed_t type as defined in fct_type.h] [0u..255u]
                        cc_input->COUNTRY_CODE : Country code                                           [full range of cc_country_code_t type as defined in cc_ext.h]
                        cc_input->VEHICLE_SPEED_LIMIT : Vehicle speed limit                             [setspeed_t type as defined in fct_type.h] [0u..255u]
                        cc_input->CURRENT_SPEED_LIMIT : Current speed limit                             [setspeed_t type as defined in fct_type.h] [0u..255u]

  @param[in,out]   *driver_controls : Pointer to cc_driver_controls_t type structure containing selected CC function
                        driver_controls->SELECTED_FUNCTION : selected function mode                     [cc_selected_function_t type as defined in cc_ext.h]
                        driver_controls->SELECTED_FUNCTION_LAST_CYCLE : selected function last cycle    [cc_selected_function_t type as defined in cc_ext.h]

  @param[in,out]   *cc_status : Pointer to cc_status_t type structure containing CC status data
                        cc_status->CC_LAT_ACCEL_LAST_CYCLE : lateral acceleration of last cycle         [full range of acceleration_t type as defined in Rte_Type.h]
                        cc_status->CC_LAT_ACCEL_GRAD_LAST_CYCLE : Accelertion Gradient of last cycle    [gradient_t type as defined in fct_types.h]
                        cc_status->CC_CONTROL_DATA.DECEL_LIM_ACTIVE_COUNTER : Counter for tracking 
                                                                              deceleration limit activation duration   [full range of uint16 as defined in Platform_Types.h]
                        cc_status->CC_ENGAGE_OVERRIDE_COUNTER : Counter for overriding cc engagement                   [full range of uint16 as defined in Platform_Types.h]

  @glob_in         -
  @glob_out        -

  @c_switch_part   LONG_CFG_USE_EXTERN_ACC_STATE_MACHINE : Configuration switch to use external ACC state machine (other ECU manages
                                                                  driver input switches and state handling (Currently ARS4T0 specific)
  @c_switch_full   FCT_CFG_LOPC_COMPONENT : Configuration switch for enabling LOPC processing
                   FCT_CFG_CC : Configuration switch enabeling Cruise Control functionality (no object evaluation)

  @pre             -
  @post            -

  @created         -
  @changed         5/31/2016
  @traceability    doors://rbgs854a:40000/?version=2&prodID=0&view=00000002&urn=urn:telelogic::1-503e822e5ec3651e-O-150-0008a220
  @author          Chintan Raval | chintan.raval-ext@continental-corporation.com | +91 (80) 6679-6480
*************************************************************************************************************************/
void KMC_v_InitCC(cc_input_data_t* cc_input, cc_driver_controls_t* driver_controls, cc_status_t *cc_status)
{
  cc_status->CC_LAT_ACCEL_LAST_CYCLE = (acceleration_t)0;
  cc_status->CC_LAT_ACCEL_GRAD_LAST_CYCLE = (gradient_t)0;
#if (CFG_FCT_CC_USE_DECEL_LIM_OVERRIDE)
  cc_status->CC_CONTROL_DATA.DECEL_LIM_ACTIVE_COUNTER = Cc_max_decel_limit_time;
#endif
  cc_status->CC_ENGAGE_OVERRIDE_COUNTER = 0u;

  driver_controls->SELECTED_FUNCTION = Cc_function_none;
  driver_controls->SELECTED_FUNCTION_LAST_CYCLE = Cc_function_none;

  cc_input->ACCELERATION_GRADIENT = (gradient_t)0;
  cc_input->LATERAL_ACCELERATION = (acceleration_t)0;
  cc_input->ACTUAL_GEAR = Pt_gear_park;
  cc_input->DATA_VALIDITY.LATERAL_ACCEL = FALSE;
  cc_input->DATA_VALIDITY.ACTUAL_GEAR = FALSE;
  cc_input->DATA_VALIDITY.SPEEDO_SPEED = FALSE;
  cc_input->INHIBIT.CC_DISENGAGEMENT_DECEL_ONLY = FALSE;
  cc_input->INHIBIT.CC_DISENGAGEMENT_RAMP = FALSE;
  cc_input->INHIBIT.CC_DISENGAGEMENT_NO_RAMP = FALSE;
  cc_input->INHIBIT.CC_DISENGAGEMENT_RAPID_RAMP = FALSE;
  cc_input->INHIBIT.CC_INHIBIT_ENGAGEMENT = FALSE;
  cc_input->INHIBIT.CC_SIGNALCHECK_FAIL = FALSE;
  cc_input->VEHICLE_STATUS.SPEED_UNIT_KMH = TRUE;
  cc_input->VEHICLE_STATUS.SPORTS_MODE = FALSE;
  cc_input->SPEEDOMETER_VEHICLE_SPEED = (speedometer_speed_t)0;
  cc_input->PERMANENT_LIMITER_SETSPEED = Cc_speed_default_value;
  cc_input->COUNTRY_CODE  = (cc_country_code_t)0;
  cc_input->VEHICLE_SPEED_LIMIT = (setspeed_t)0;
  cc_input->CURRENT_SPEED_LIMIT = (setspeed_t)0;
#if (FCT_CFG_SLA_FEATURE)
  cc_input->SLA_INPUT_DATA.SLA_SpeedLimit.u_SpeedLimit = (setspeed_t)0;
  cc_input->SLA_INPUT_DATA.SLA_SpeedLimit.u_SpeedLimitIncOffset = 0;
  cc_input->SLA_INPUT_DATA.SLA_SpeedLimit.u_SpeedLimitDistance = (t_u_DistanceLong)0;
  cc_input->SLA_INPUT_DATA.SLA_InputStatus.b_SLA_SET_ENGAGED = FALSE;
  cc_input->SLA_INPUT_DATA.SLA_InputStatus.b_SLA_SET_AUTOMATIC = FALSE;
  cc_input->SLA_INPUT_DATA.SLA_SpeedLimit.SpeedLimitType.b_SLA_CONTROL_BEFOR_LIMIT = FALSE;
  cc_input->SLA_INPUT_DATA.SLA_SpeedLimit.SpeedLimitType.b_SLA_CONTROL_AFTER_LIMIT = FALSE;
  cc_input->SLA_INPUT_DATA.SLA_InputStatus.b_SLA_NEW_SPEED_AVAILABLE = FALSE;
  cc_input->SLA_INPUT_DATA.SLA_InputStatus.b_SLA_SPEED_ABORTED = FALSE;
  cc_input->SLA_INPUT_DATA.SLA_InputStatus.b_SLA_SPEED_ACCEPTED = FALSE;
  cc_input->SLA_INPUT_DATA.SLA_InputStatus.b_SLA_SPEED_DECLINED = FALSE;
  cc_input->SLA_INPUT_DATA.SLA_InputStatus.b_SLA_RETAKE_SPEED = FALSE;
#endif
#if (LONG_CFG_USE_EXTERN_ACC_STATE_MACHINE)
  cc_input->pENGINE_ECU_INPUT = NULL;
#endif
  KMC_v_InitHMI(cc_input, cc_status);
  KMC_v_InitCCStatus(cc_status);

#if (FCT_CFG_ERROR_OUTPUT_VEH)
  LOPC_pErrorOut->VehicleSpeedUnplausible = AL_ERR_STATE_UNKNOWN;
  LOPC_pErrorOut->PortError               = AL_ERR_STATE_UNKNOWN;
#endif
}

/*************************************************************************************************************************
  Functionname:    KMC_v_ProcessMain                                                                                */ /*!

  @brief           This function determines the sequence of calculating
                   output data every control_task_cycle_time [ms]

  @description     This function determines the sequence of calculating
                   output data every control_task_cycle_time [ms]

@startuml
Start
Partition KMC_v_ProcessMain(){
: This function determines the sequence of calculating output data every control_task_cycle_time [ms];
: Processing of the interpretation of driver_controls like Determination of Speed Limits, engagment Conditions, Control State, set Speed and Speed Limit Assit Speed;
: Processing of Commanded Acceleration calculated and arbitrated based on inputs from Cruise Control, Speed Limit Assist, ACC Object Control;
}
End
@enduml

  @return          void

  @param[in]       cycle_time : Cycle time in mseconds     [full range of times_t type as defined in cc_ext.h]
  @param[in,out]   *driver_controls : Pointer to cc_driver_controls_t type structure containing selected CC function as defined in Rte_Type.h

  @param[in]       *cc_input : Pointer to cc_input_data_t type structure containing input data to CC as defined in cc_ext.h

  @param[in,out]   *error_data : Pointer to cc_error_data_t type structure containing CC error data as defined in cc_ext.h

  @param[in]       *das_input : Pointer to cart_das_input_data_t type structure containing Data from longitudinal dynamics 
                                                           management to driver assistance system as defined in cart_ext.h

  @param[in,out]   *das_output : Pointer to cart_das_output_data_t structure containing Data from driver assistance system 
                                                                  to longitudinal dynamics management as defined cart_ext.h

  @param[in]       *acc_output : Pointer to acc_output_data_t type structure containing ACC output data from FCT_SEN to FCT_VEH as defined in Rte_Type.h
  @param[in,out]   *cc_status : Pointer to cc_status_t type structure containing CC status data as defined in cc_ext.h

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_LOPC_COMPONENT : Configuration switch for enabling LOPC processing
                   FCT_CFG_CC : Configuration switch enabling Cruise Control functionality (no object evaluation)

  @pre             -
  @post            -

  @created         -
  @changed         5/31/2016
  @traceability    doors://rbgs854a:40000/?version=2&prodID=0&view=00000002&urn=urn:telelogic::1-503e822e5ec3651e-O-151-0008a220
  @author          -
*************************************************************************************************************************/
DLLEXPORT void KMC_v_ProcessMain(const times_t cycle_time,
                                 cc_driver_controls_t* driver_controls,
                                 const cc_input_data_t* cc_input,
                                 cc_error_data_t *error_data,
                                 const cart_das_input_data_t* das_input,
                                 cart_das_output_data_t* das_output,
#if (FCT_CFG_ACC_HEADWAY_PLANNER)
                                const acc_output_data_t* acc_output,
#endif
                                cc_status_t *cc_status)
{
  KMC_v_DetermineControlstateSetspeed(cycle_time, das_input, driver_controls, cc_input, error_data, das_output, cc_status, acc_output);

  KMC_v_CommandAcceleration(cycle_time, cc_input, das_input, acc_output, das_output, cc_status);

}

#endif  /* (FCT_CFG_LOPC_COMPONENT) && (FCT_CFG_CC) && (LOPC_CFG_KMC) */

/** @} end defgroup */
