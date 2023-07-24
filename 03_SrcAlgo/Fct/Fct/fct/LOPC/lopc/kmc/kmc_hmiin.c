/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC/LOPC/KMC (Adaptive Cruise Control - Longitudinal Planner and Controller - Kinematic Motion Control)

PACKAGENAME:               kmc_hmiin.c

DESCRIPTION:               This file contains functions concerning interpretation 
                           of driver requests such as set speed, control state

AUTHOR:                    Mistry Niraj (uidq5738)

CREATION DATE:             24.02.2017

VERSION:                   $Revision: 1.19 $

LEGACY VERSION:            Revision: 1.37

**************************************************************************** */

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/** 
@defgroup   kmc_hmiin Kmc_hmiin
@ingroup    kmc
@brief      KMC HMI and SM functions
@{ */ 

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "kmc.h"

#if ((FCT_CFG_LOPC_COMPONENT) && (FCT_CFG_CC) && (LOPC_CFG_KMC))

#define Speed_round_up (Velocity_s/2)
#if (!LONG_CFG_USE_EXTERN_ACC_STATE_MACHINE)
static void KMC_v_DetermineSetSpeed(const cc_input_data_t* input_data, const cc_error_data_t* error_data, cc_driver_requests_t* driver_requests);
#if (FCT_CFG_SLA_FEATURE)
static void KMC_v_DetermineSLASpeed(const t_SLA_InputData* sla_input_data, const cc_das_vehicle_status_t vehicle_status, cc_driver_requests_t* driver_requests,
                                    t_SLA_HMI_Data* cc_sla_hmi_data, t_SLA_Ctrl_Data* cc_sla_ctrl_data);
#endif
#endif
static void KMC_v_DetermineEngagementConditions(const times_t cycle_time, const cart_das_input_data_t* das_input, const cc_input_data_t* input, cc_acceleration_control_data_t* accel_control_data, cc_driver_requests_t* driver_requests, cc_status_t *cc_status, const cc_driver_controls_t* driver_controls, const acc_output_data_t* situation_output);
static void KMC_v_DetermineSpeedLimits(const cc_acceleration_control_data_t* accel_control_data, const cart_das_input_data_t* das_input, const cc_input_data_t* input, cc_driver_requests_t* driver_requests);
static void KMC_v_DetermineControlState(const cc_driver_controls_t* driver_controls, cc_acceleration_control_data_t* accel_control_data, const cart_das_input_data_t* das_input, cc_error_data_t* error_data, cc_driver_requests_t* driver_requests, cart_das_output_data_t* das_output, const cc_input_data_t* input_data);

/*************************************************************************************************************************
  Functionname:    KMC_v_InitHMI                                                                                    */ /*!

  @brief           Initialisation of Cruise control HMI

  @description     This function initializes all data at system start.
                   This function needs to be called once before EXEC_CC
                   is called

    @startuml
    Start
    Partition KMC_v_InitHMI {
      : Initialise variables from struct CC_STATUS \nincluding system counters and LODM_STAT_LAST_CYCLE ;
    }
    End
    @enduml

  @return          -

  @param[in]       input_data : Pointer to cc_input_data_t type structure containing input data to CC [cc_input_data_t as per cc_ext.h]
                    VEHICLE_STATUS.SPEED_UNIT_KMH : boolean indicating the speed unit, i.e. KMH or MPH [TRUE, FALSE]
  @param[in,out]   cc_status : Pointer to Cruisecontrol status [cc_status_t as per cc_ext.h]
                    CC_ESP_ACT_CNT : ESP acting counter [0u ... 65000u]
                    CC_TCS_ACT_CNT : TCS acting counter [0u ... 65000u]
                    CC_ABS_ACT_CNT : ABS acting counter [0u ... 65000u]
                    CC_SPEED_UNIT_LAST_CYCLE : Speed unit of previous cycle [TRUE, FALSE]
                    CC_DECEL_ONLY_MODE_CNT : Deceleration only mode counter [0u ... Cc_max_decel_only_time / cycle_time]
                    LODM_STAT_LAST_CYCLE.DAS_ENABLE : Boolean enabling driver assistance systems for previous cycle                     [TRUE, FALSE]
                    LODM_STAT_LAST_CYCLE.DAS_SHUTOFF_ACQ : Bit indicating DAS shutoff acknowledged by LODM                              [TRUE, FALSE]
                    LODM_STAT_LAST_CYCLE.DC_FAIL : (Currently not used)                                                                 [TRUE, FALSE]
                    LODM_STAT_LAST_CYCLE.DC_LIM_ACCEL : Boolean, if TRUE indicating acceleration request is limited for previous cycle  [TRUE, FALSE]
                    LODM_STAT_LAST_CYCLE.DC_LIM_DECEL : Boolean, if TRUE indicating acceleration request is limited for previous cycle  [TRUE, FALSE]
  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_LOPC_COMPONENT : Configuration switch for enabling LOPC processing
  @c_switch_full   FCT_CFG_CC : Configuration switch for enabling CC processing
  @traceability    doors://rbgs854a:40000/?version=2&prodID=0&view=00000002&urn=urn:telelogic::1-503e822e5ec3651e-O-149-0008a220
*************************************************************************************************************************/
void KMC_v_InitHMI(const cc_input_data_t* input_data, cc_status_t *cc_status)
{
  cc_status->LODM_STAT_LAST_CYCLE.DAS_ENABLE = FALSE;
  cc_status->LODM_STAT_LAST_CYCLE.DAS_SHUTOFF_ACQ = FALSE;
  cc_status->LODM_STAT_LAST_CYCLE.DC_FAIL= FALSE;
  cc_status->LODM_STAT_LAST_CYCLE.DC_LIM_ACCEL = FALSE;
  cc_status->LODM_STAT_LAST_CYCLE.DC_LIM_DECEL = FALSE;
  cc_status->CC_DECEL_ONLY_MODE_CNT = (uint32)0;
  cc_status->CC_SPEED_UNIT_LAST_CYCLE = (uint8)input_data->VEHICLE_STATUS.SPEED_UNIT_KMH;
  cc_status->CC_ABS_ACT_CNT = 0u;
  cc_status->CC_TCS_ACT_CNT = 0u;
  cc_status->CC_ESP_ACT_CNT = 0u;
}

/*************************************************************************************************************************
  Functionname:    KMC_v_DetermineEngagementConditions                                                              */ /*!

  @brief           Based on driver inputs and inhibition checks, the conditions of engagement of 
                   various control states are determined. This information is then used to transition
                   HMI control states.

  @description     Maximum and mimimum allowed accelerations are determined. Conditions for drive off possibilities are 
                   tested. Conditions for engaging as well as disengaging CC (with or without ramp) are tested. Automatic 
                   disengagement leads to CC_DECEL_ONLY state, at which point a counter is started. At end of counter, or 
                   due to braking or acceleration or standstill, this state is ended. Driver acceleration triggers Override
                   state. If vehicle acceleration and jerk is within CC limits, CC state changed from engaged to active state. 
                   Only in active state, accleration request can be provided. Conditions for engaging and disengaging limiter 
                   are also tested. All outputs are saved in structure driver_requests->ENGAGEMENT_CONDITIONS to be used to 
                   trigger state change. Permanent limiter speed limit is determined, if required, along with its engagement 
                   conditions.

    @startuml
    Start
      Partition KMC_v_DetermineEngagementConditions {
        : Initialise all engagement conditions;
        : Min and max allowed acceleration for the\n vehicle calculated based on ego speed;
        If (CONTROL_MODE == Cc_standstill_mode) then (yes)
          : CONTROL_TO_RELEVANT_OBJECT = TRUE;
          If (ACC is active, driver is not pressing brake pedal\n and vehicle ahead moving) then (yes)
            : DRIVE_OFF_POSSIBLE = TRUE;
          Else (no)
            : DRIVE_OFF_POSSIBLE = FALSE;
          Endif
        Else (no)
          : DRIVE_OFF_POSSIBLE = FALSE;
        Endif
        If (Ego speed is lower than MAX_CC_SPEED or KMC is initialised) then (yes)
          If (CC_INHIBIT_ENGAGEMENT == FALSE &&\n CC_DISENGAGEMENT_NO_RAMP == FALSE &&\n CC_DISENGAGEMENT_RAMP == FALSE &&\n CC_DISENGAGEMENT_RAPID_RAMP == FALSE &&\n CC_DISENGAGEMENT_DECEL_ONLY == FALSE) then (yes)
            If (CONTROL_STATE != Cc_cc_decel_only) then (yes)
              : CC_ENGAGEMENT_STAT = TRUE;
            Else (no)
            Endif
          Else (no)
          Endif
        Else (no)
        Endif
        note right
        INHIBIT struct used as input to set
        outputs in ENGAGEMENT_CONDITIONS
        endnote
        If (CC_ENGAGEMENT_STAT == TRUE) then (yes)
          If (CC_SETSPEED > 0\n OR \n CC_TAKE_ACTUAL_SPEED == TRUE) then (yes)
            : ACCEPT_CC_ENGAGEMENT = TRUE;
          Else (no)
          Endif
        Else (no)
        Endif
        If ( Ego speed is greater than MAX_CC_SPEED\n and KMC is not initialised this cycle\n OR \n CC_DISENGAGEMENT_RAMP == TRUE\n OR\n CC_DISENGAGEMENT_RAPID_RAMP == TRUE) then (yes)
          : ENGAGEMENT_CONDITIONS.CC_DISENGAGEMENT_RAMP = TRUE;
        Else (no)
        Endif
        note right
        INHIBIT struct used as input to set
        outputs in ENGAGEMENT_CONDITIONS
        endnote
        If ( CC_DISENGAGEMENT_NO_RAMP == TRUE\n OR \n SELECTED_FUNCTION == 0) then (yes)
          : ENGAGEMENT_CONDITIONS.CC_DISENGAGEMENT = TRUE;
        Else (no)
        Endif
        If (CC_DISENGAGEMENT_DECEL_ONLY == TRUE) then (yes)
          : CC_DECEL_ONLY = TRUE;
          : If previous state was not decel_only, start\n CC_DECEL_ONLY_MODE_CNT counter;
        Else (no)
        Endif
        If ( Driver pressed brake\n OR \n OVERRIDE_ACCEL == TRUE\n OR \n OVERRIDE_DECEL == TRUE\n OR \n STANDSTILL == TRUE\n OR \n Counter CC_DECEL_ONLY_MODE_CNT is over) then (yes)
          : CC_END_DECEL_ONLY = TRUE;
        Else (no)
        Endif
        note right
        LODM_STAT struct used as input to set
        outputs in ENGAGEMENT_CONDITIONS
        endnote
        If (OVERRIDE_ACCEL == TRUE) then (yes)
          : ENGAGEMENT_CONDITIONS.DRIVER_OVERRIDE = TRUE;
        Else (no)
        Endif
        If (Vehicle longitudinal acceleration \nand jerk are within ACC limits) then (yes)
          : END_CC_ENGAGEMENT = TRUE;
        Else (no)
        Endif
        If (ACCEL_RAMP_ACTIVE == FALSE) then (yes)
          : END_CC_DISENGAGEMENT = TRUE;
        Else (no)
        Endif
      }

    End
    @enduml

  @return          -

  @param[in]       cycle_time : cycle time of FCT_VEH cycle [0u ... 1000u] ms
  @param[in]       das_input : Pointer to input from longitudinal dynamics management to driver assistance system [cart_das_input_data_t as per cart_ext.h]
                    VEHICLE_SPEED : Ego speed with factor Velocity_s [-30000u ... 30000u] cm/s
                    VEHICLE_ACCEL : Ego longitudinal acceleration [-30000u ...+30000u] m/s2 (with factor Acceleration_s)
                    BRAKE_STAT.PEDAL_INIT_TRAVEL : Boolean indicating if brake pedal is pressed                 [TRUE, FALSE]
                    LODM_STAT.OVERRIDE_ACCEL : Boolean indicating driver override by accelerator pedal          [TRUE, FALSE]
                    LODM_STAT.OVERRIDE_DECEL : Boolean indicating driver override by decelerator pedal          [TRUE, FALSE]
                    LODM_STAT.DAS_ENABLE : Boolean enabling driver assistance systems for previous cycle        [TRUE, FALSE]
                    LODM_STAT.DAS_SHUTOFF_ACQ : Bit indicating DAS shutoff acknowledged by LODM                 [TRUE, FALSE]
                    PT_STAT.KICKDOWN : Boolean, if TRUE indicates kickdown mode                                 [TRUE, FALSE]
  @param[in]       input : Pointer to CC input interface [cc_input_data_t as per cc_ext.h]
                    INHIBIT.CC_INHIBIT_ENGAGEMENT : Inhibition bit for CC engagement                            [TRUE, FALSE]
                    INHIBIT.CC_DISENGAGEMENT_RAMP : Inhibition bit for ramp                                     [TRUE, FALSE]
                    INHIBIT.CC_DISENGAGEMENT_NO_RAMP : Inhibition bit for no ramp                               [TRUE, FALSE]
                    INHIBIT.CC_DISENGAGEMENT_RAPID_RAMP : Inhibition bit for rapid ramp                         [TRUE, FALSE]
                    INHIBIT.CC_DISENGAGEMENT_DECEL_ONLY : Inhibition bit for deceleration                       [TRUE, FALSE]
                    SPEEDOMETER_VEHICLE_SPEED : Current speedometer speed with factor Velocity_s [-30000u ... 30000u]
                    PERMANENT_LIMITER_SETSPEED : Maximum permanent (winter tire) limiter speed [0u ... 255u]
                    ACCELERATION_GRADIENT : Gradient of longitudinal acceleration [-100000u ... 100000u] m/s3 (with factor 1000)
                    ACTUAL_GEAR : Currently valid transmission gear of vehicle [TransmissionGear_t as per Rte_type.h]
  @param[in,out]   accel_control_data : Pointer to CC acceleration control data [cc_acceleration_control_data_t as per cc_ext.h]
                    MIN_ALLOWED_ACCEL : Minimum allowed acceleration for control object [-30000u ...+30000u] m/s2 (with factor Acceleration_s)
                    MAX_ALLOWED_ACCEL : Maximum allowed acceleration for control object [-30000u ...+30000u] m/s2 (with factor Acceleration_s)
                    ACCEL_STATUS.ACCEL_RAMP_ACTIVE : Boolean ,if TRUE indicating acceleration ramp active       [TRUE, FALSE]
  @param[in,out]   driver_requests : Pointer to driver request input structure [cc_driver_requests_t as per cc_ext.h]
                    CONTROL_MODE : Cruise control mode within the active state [full range of datatype cc_control_mode_t as in cc_ext.h]
                    CONTROL_STATE : Variable that reflects the state of the HMI state machine [full range of datatype cc_control_state_t as in cc_ext.h]
                    MAX_CC_SPEED : Maximum cruise control speed [0u ... 255u]
                    CC_SETSPEED : Current Cruise Control set speed [0u ... 255u] 
                    LIM_SETSPEED : Current limiter set speed [0u ... 255u]
                    PLIM_VLIMIT : Permanent limiter speed limit [-30000u ... 30000u]
                    PLIM_HYST : Hysteresis for disengagement of permanent limiter [0u ... 255u] 
                    PLIM_THRESHOLD : Threshold for engagement of permanent limiter below driver selected maximum speed [0u ... 255u]
                    DRIVER_OPERATIONS.CC_TAKE_ACTUAL_SPEED : Boolean, if TRUE take actual vehicle speedometer speed as CC_SETSPEED [TRUE, FALSE]
                    DRIVER_OPERATIONS.LIM_TAKE_ACTUAL_SPEED : Boolean, if TRUE take actual vehicle speedometer speed as LIM_SETSPEED [TRUE, FALSE]
                    ENGAGEMENT_CONDITIONS.ACCEPT_CC_ENGAGEMENT : Boolean, if TRUE engages Cruise control                [TRUE, FALSE]
                    ENGAGEMENT_CONDITIONS.ACCEPT_LIM_ENGAGEMENT : Boolean, if TRUE engages speed limiter                [TRUE, FALSE]
                    ENGAGEMENT_CONDITIONS.END_CC_ENGAGEMENT : Boolean, if TRUE ends CC engagement state                 [TRUE, FALSE]
                    ENGAGEMENT_CONDITIONS.DRIVER_OVERRIDE : Boolean indicating override condition by driver             [TRUE, FALSE]
                    ENGAGEMENT_CONDITIONS.CC_DISENGAGEMENT : Boolean, if TRUE disengages CC                             [TRUE, FALSE]
                    ENGAGEMENT_CONDITIONS.CC_DISENGAGEMENT_RAMP : Inhibition bit for ramp                               [TRUE, FALSE]
                    ENGAGEMENT_CONDITIONS.END_CC_DISENGAGEMENT : Boolean, if TRUE ends CC disengagement                 [TRUE, FALSE]
                    ENGAGEMENT_CONDITIONS.CC_DECEL_ONLY : Bit for HMI state decel_only                                  [TRUE, FALSE]
                    ENGAGEMENT_CONDITIONS.CC_END_DECEL_ONLY : Bit for ending HMI state decel_only                       [TRUE, FALSE]
                    ENGAGEMENT_CONDITIONS.LIM_DISENGAGEMENT : Boolean for disengagement of limiter                      [TRUE, FALSE]
                    ENGAGEMENT_CONDITIONS.END_LIM_DISENGAGEMENT : Boolean for ending limiter disengagement              [TRUE, FALSE]
                    ENGAGEMENT_CONDITIONS.GOTO_PERM_LIM : Boolean for enabling permanent limiter                        [TRUE, FALSE]
                    ENGAGEMENT_CONDITIONS.END_PERM_LIM : Boolean to end permanent limiter                               [TRUE, FALSE]
                    ENGAGEMENT_CONDITIONS.DRIVE_OFF_POSSIBLE : Boolean indicating drive off possible                    [TRUE, FALSE]
                    ENGAGEMENT_CONDITIONS.CC_ENGAGEMENT_STAT : Boolean enabling speed hold function                     [TRUE, FALSE]
                    ENGAGEMENT_CONDITIONS.CONTROL_TO_RELEVANT_OBJECT : Boolean indicating control to relevant object    [TRUE, FALSE]
  @param[in,out]   cc_status : Pointer to Cruisecontrol status [cc_status_t as per cc_ext.h]
                    CC_DECEL_ONLY_MODE_CNT : Deceleration only mode counter [0u ... 4294967290u]
                    LODM_STAT_LAST_CYCLE.DAS_SHUTOFF_ACQ : Bit indicating DAS shutoff acknowledged by LODM from last cycle [TRUE, FALSE]
  @param[in]       driver_controls : Pointer to Selected CC function by driver [cc_driver_controls_t as per cc_ext.h]
                    SELECTED_FUNCTION : This variable reflects which function is selected by the driver [cc_selected_function_t as per cc_ext.h]
  @param[in]       situation_output : Pointer to ACC output data from FCT Sen to FCT Veh [acc_output_data_t as per Rte_Type.h]
                    SITUATION_CLASS.SITUATION : Classifier of the current traffic situation [full range of datatype acc_situation_class_t as in Rte_Type.h]
  @glob_in         - 
  @glob_out        - 

  @c_switch_part   CFG_FCT_PLIM : Configuration switch for enabling permanent limiter function
  @c_switch_part   CFG_FCT_CC_USE_PLIM_CONTROL_STATE : Configuration switch for usage of permanent limiter in state machine
  @c_switch_part   FCT_CFG_FSRACC : Configuration switch enabling Full Speed Range Adaptive Cruise Control functionality (with object evaluation and stop and go capability)
  @c_switch_part   CFG_FCT_CART_USE_DISENGAGE_HANDSHAKE : Configuration switch for using handshake (disengagement request / acknowledge) over Cartronic
  @c_switch_part   CFG_FCT_LIM : Configuration switch for enabling limiter function
  @c_switch_part   LONG_CFG_USE_EXTERN_ACC_STATE_MACHINE : Configuration switch to use external ACC state machine
  @c_switch_full   FCT_CFG_LOPC_COMPONENT : Configuration switch for enabling LOPC processing
  @c_switch_full   FCT_CFG_CC : Configuration switch for enabling CC processing
*************************************************************************************************************************/
static void KMC_v_DetermineEngagementConditions(const times_t cycle_time,
                                               const cart_das_input_data_t* das_input,
                                               const cc_input_data_t* input,
                                               cc_acceleration_control_data_t* accel_control_data,
                                               cc_driver_requests_t* driver_requests,
                                               cc_status_t *cc_status,
                                               const cc_driver_controls_t* driver_controls,
                                               const acc_output_data_t* situation_output)
{
#if(CFG_FCT_PLIM && CFG_FCT_CC_USE_PLIM_CONTROL_STATE)
  speedometer_speed_t permanent_limiter_speedlimit_new;

  permanent_limiter_speedlimit_new = 0;
#endif

  /* Reset all Conditions */
  driver_requests->ENGAGEMENT_CONDITIONS.ACCEPT_CC_ENGAGEMENT = FALSE;
  driver_requests->ENGAGEMENT_CONDITIONS.ACCEPT_LIM_ENGAGEMENT = FALSE;
  driver_requests->ENGAGEMENT_CONDITIONS.END_CC_ENGAGEMENT = FALSE;
  driver_requests->ENGAGEMENT_CONDITIONS.DRIVER_OVERRIDE = FALSE;
  driver_requests->ENGAGEMENT_CONDITIONS.CC_DISENGAGEMENT = FALSE;
  driver_requests->ENGAGEMENT_CONDITIONS.CC_DISENGAGEMENT_RAMP = FALSE;
  driver_requests->ENGAGEMENT_CONDITIONS.END_CC_DISENGAGEMENT = FALSE;
  driver_requests->ENGAGEMENT_CONDITIONS.CC_DECEL_ONLY = FALSE;
  driver_requests->ENGAGEMENT_CONDITIONS.CC_END_DECEL_ONLY = FALSE;
  driver_requests->ENGAGEMENT_CONDITIONS.LIM_DISENGAGEMENT = FALSE;
  driver_requests->ENGAGEMENT_CONDITIONS.END_LIM_DISENGAGEMENT = FALSE;
  driver_requests->ENGAGEMENT_CONDITIONS.GOTO_PERM_LIM = FALSE;
  driver_requests->ENGAGEMENT_CONDITIONS.END_PERM_LIM = FALSE;
  driver_requests->ENGAGEMENT_CONDITIONS.DRIVE_OFF_POSSIBLE = FALSE;
  driver_requests->ENGAGEMENT_CONDITIONS.CC_ENGAGEMENT_STAT = FALSE;
  driver_requests->ENGAGEMENT_CONDITIONS.CONTROL_TO_RELEVANT_OBJECT = FALSE;


  /*! Determ max allowed vehicle acceleration and deceleration */
  accel_control_data->MIN_ALLOWED_ACCEL = MAT_CALCULATE_PARAM_VALUE1D(Cc_max_vehicle_decel,Cc_max_vehicle_decel_points, das_input->VEHICLE_SPEED);
  accel_control_data->MAX_ALLOWED_ACCEL = MAT_CALCULATE_PARAM_VALUE1D(Cc_max_vehicle_accel,Cc_max_vehicle_accel_points, das_input->VEHICLE_SPEED);

#if (FCT_CFG_FSRACC)
  if(
     (driver_requests->CONTROL_MODE == Cc_standstill_mode)
    )
  {
    driver_requests->ENGAGEMENT_CONDITIONS.CONTROL_TO_RELEVANT_OBJECT = TRUE;
    if(
       (driver_requests->CONTROL_STATE == Cc_cc_active)
       &&
       (das_input->BRAKE_STAT.PEDAL_INIT_TRAVEL == FALSE) 
       &&
       (situation_output->SITUATION_CLASS.SITUATION != Acc_sit_class_stop)
      )
    {
      /* Driver not braking and situation indicates vehicle ahead moving (drive off) */
      driver_requests->ENGAGEMENT_CONDITIONS.DRIVE_OFF_POSSIBLE = TRUE;
    }
    else
    {
      /* Either driver braking or vehicle ahead still stopped */
      driver_requests->ENGAGEMENT_CONDITIONS.DRIVE_OFF_POSSIBLE = FALSE;
    }
  }
  else
  {
    /* Either not in active state or not in stand-still. Either way a drive
    off is NOT possible */
    driver_requests->ENGAGEMENT_CONDITIONS.DRIVE_OFF_POSSIBLE = FALSE;
  }
#endif

  /* Can the HoldSpeed-Function be engaged? */
  if (
      (input->INHIBIT.CC_INHIBIT_ENGAGEMENT == FALSE )
      &&
      ((input->SPEEDOMETER_VEHICLE_SPEED <= ((speedometer_speed_t)driver_requests->MAX_CC_SPEED * Speedo_speed_s)) || (driver_requests->MAX_CC_SPEED == Cc_speed_default_value))
      &&
      (input->INHIBIT.CC_DISENGAGEMENT_NO_RAMP == FALSE)
      &&
      (input->INHIBIT.CC_DISENGAGEMENT_RAMP == FALSE)
      &&
      (input->INHIBIT.CC_DISENGAGEMENT_RAPID_RAMP == FALSE)
      &&
      (input->INHIBIT.CC_DISENGAGEMENT_DECEL_ONLY == FALSE)
      &&
      (driver_requests->CONTROL_STATE != Cc_cc_decel_only)
      )
  {
    driver_requests->ENGAGEMENT_CONDITIONS.CC_ENGAGEMENT_STAT = TRUE;
  }


  if (
      (driver_requests->ENGAGEMENT_CONDITIONS.CC_ENGAGEMENT_STAT == TRUE) 
      &&
      ((driver_requests->CC_SETSPEED > 0u) || (driver_requests->DRIVER_OPERATIONS.CC_TAKE_ACTUAL_SPEED == TRUE))
     )
  {
    driver_requests->ENGAGEMENT_CONDITIONS.ACCEPT_CC_ENGAGEMENT = TRUE;
  }

  if (
      ((input->SPEEDOMETER_VEHICLE_SPEED > ((speedometer_speed_t)driver_requests->MAX_CC_SPEED * Speedo_speed_s)) && (driver_requests->MAX_CC_SPEED != Cc_speed_default_value))
      ||
      (input->INHIBIT.CC_DISENGAGEMENT_RAMP == TRUE)
      ||
      (input->INHIBIT.CC_DISENGAGEMENT_RAPID_RAMP == TRUE)
     )
  {
    driver_requests->ENGAGEMENT_CONDITIONS.CC_DISENGAGEMENT_RAMP = TRUE;
  }

  if (input->INHIBIT.CC_DISENGAGEMENT_DECEL_ONLY == TRUE) 
  {
    driver_requests->ENGAGEMENT_CONDITIONS.CC_DECEL_ONLY = TRUE;

    if (driver_requests->CONTROL_STATE != Cc_cc_decel_only) 
    { 
      if(cycle_time > 0)
      {
        cc_status->CC_DECEL_ONLY_MODE_CNT = ((uint32)Cc_max_decel_only_time / cycle_time);
      }
      else
      {
        cc_status->CC_DECEL_ONLY_MODE_CNT = 0u;
      }
    }
  }

  if (
      (das_input->BRAKE_STAT.PEDAL_INIT_TRAVEL == TRUE)
      ||
      (das_input->LODM_STAT.OVERRIDE_ACCEL == TRUE)
      ||
      (das_input->LODM_STAT.OVERRIDE_DECEL == TRUE)
      ||
      (das_input->LODM_STAT.STANDSTILL == TRUE)
      ||
      (cc_status->CC_DECEL_ONLY_MODE_CNT == (uint32)0)
     )
  {
    driver_requests->ENGAGEMENT_CONDITIONS.CC_END_DECEL_ONLY = TRUE;
  }
  
  if (cc_status->CC_DECEL_ONLY_MODE_CNT > (uint32)0)
  {
    cc_status->CC_DECEL_ONLY_MODE_CNT--;
  }

  if (
      (input->INHIBIT.CC_DISENGAGEMENT_NO_RAMP == TRUE)
      ||
      (driver_controls->SELECTED_FUNCTION == Cc_function_none)
     )
  {
    driver_requests->ENGAGEMENT_CONDITIONS.CC_DISENGAGEMENT = TRUE;
  }

  if (das_input->LODM_STAT.OVERRIDE_ACCEL == TRUE)
  {
    driver_requests->ENGAGEMENT_CONDITIONS.DRIVER_OVERRIDE = TRUE;
  }
  
  if(
      (
        (input->ACCELERATION_GRADIENT >= Cc_min_engage_accel_gradient)
        &&
        (input->ACCELERATION_GRADIENT <= Cc_max_engage_accel_gradient)
      )
      &&
      (
        (das_input->VEHICLE_ACCEL <= accel_control_data->MAX_ALLOWED_ACCEL)
        &&
        (das_input->VEHICLE_ACCEL >= accel_control_data->MIN_ALLOWED_ACCEL)
      )
    )
  {
    driver_requests->ENGAGEMENT_CONDITIONS.END_CC_ENGAGEMENT = TRUE;
  }
  
#if (CFG_FCT_CART_USE_DISENGAGE_HANDSHAKE)
  if (
      (das_input->LODM_STAT.DAS_SHUTOFF_ACQ == TRUE) 
      && 
      (cc_status->LODM_STAT_LAST_CYCLE.DAS_SHUTOFF_ACQ == FALSE)
     ) 
  {
    driver_requests->ENGAGEMENT_CONDITIONS.END_CC_DISENGAGEMENT = TRUE;
    accel_control_data->ACCEL_STATUS.ACCEL_RAMP_ACTIVE = FALSE;
  }
  else
  {
    /*System will at least disengage if Acc_min/max_accel_disengage is reached*/
    if (accel_control_data->ACCEL_STATUS.ACCEL_RAMP_ACTIVE == FALSE)
    {
      driver_requests->ENGAGEMENT_CONDITIONS.END_CC_DISENGAGEMENT = TRUE;
    }
  }
#else
  if (accel_control_data->ACCEL_STATUS.ACCEL_RAMP_ACTIVE == FALSE) 
  {
    driver_requests->ENGAGEMENT_CONDITIONS.END_CC_DISENGAGEMENT = TRUE;
  }
#endif

  /* Can the LimSpeed-Function be engaged? */
#if (CFG_FCT_LIM)
  if (
      ((driver_requests->LIM_SETSPEED > 0) || (driver_requests->DRIVER_OPERATIONS.LIM_TAKE_ACTUAL_SPEED == TRUE))
      &&
      ((input->ACTUAL_GEAR != Pt_gear_neutral) && (input->ACTUAL_GEAR != Pt_gear_park) && (input->ACTUAL_GEAR != Pt_gear_reverse))
      &&
      (das_input->PT_STAT.KICKDOWN == FALSE)
      &&
      (das_input->LODM_STAT.DAS_ENABLE == TRUE)
     )
  {
    driver_requests->ENGAGEMENT_CONDITIONS.ACCEPT_LIM_ENGAGEMENT = TRUE;
  }
#endif

  if (das_input->PT_STAT.KICKDOWN == TRUE)
  {
    driver_requests->ENGAGEMENT_CONDITIONS.LIM_DISENGAGEMENT = TRUE;
  }
  
#if (CFG_FCT_CART_USE_DISENGAGE_HANDSHAKE)
  if (
      (das_input->LODM_STAT.DAS_SHUTOFF_ACQ == TRUE)
      && 
      (cc_status->LODM_STAT_LAST_CYCLE.DAS_SHUTOFF_ACQ == FALSE)
     )
  {
    driver_requests->ENGAGEMENT_CONDITIONS.END_LIM_DISENGAGEMENT = TRUE;
  }
  else
  {
    /*System will at least disengage if Acc_min/max_accel_disengage is reached*/
    if (accel_control_data->ACCEL_STATUS.ACCEL_RAMP_ACTIVE == FALSE)
    {
      driver_requests->ENGAGEMENT_CONDITIONS.END_LIM_DISENGAGEMENT = TRUE;
    }
  }
#else
  if (accel_control_data->ACCEL_STATUS.ACCEL_RAMP_ACTIVE == FALSE)
  {
    driver_requests->ENGAGEMENT_CONDITIONS.END_LIM_DISENGAGEMENT = TRUE;
  }
#endif

#if (LONG_CFG_USE_EXTERN_ACC_STATE_MACHINE)
  /* There is no control state for permanent limiter in external state machine */
#else

#if (CFG_FCT_PLIM && CFG_FCT_CC_USE_PLIM_CONTROL_STATE)
  /* New Speed limit for permanent Limiter */
  if (driver_requests->CONTROL_STATE != Cc_plim_active)
  {
    permanent_limiter_speedlimit_new = (speedometer_speed_t)MAT_MIN(((sint32)input->SPEEDOMETER_VEHICLE_SPEED + ((sint32)driver_requests->PLIM_HYST * (sint32)Speedo_speed_s)), (((sint32)input->PERMANENT_LIMITER_SETSPEED - (sint32)driver_requests->PLIM_THRESHOLD) * (sint32)Speedo_speed_s));
    driver_requests->PLIM_VLIMIT = (speedometer_speed_t)MAT_MIN((sint32)permanent_limiter_speedlimit_new, (sint32)driver_requests->PLIM_VLIMIT);
  }
  else
  {
    permanent_limiter_speedlimit_new = (speedometer_speed_t)MAT_MAX(((sint32)input->SPEEDOMETER_VEHICLE_SPEED - ((sint32)driver_requests->PLIM_HYST * (sint32)Speedo_speed_s)), (((sint32)input->PERMANENT_LIMITER_SETSPEED - (sint32)driver_requests->PLIM_THRESHOLD) * (sint32)Speedo_speed_s));
    driver_requests->PLIM_VLIMIT = (speedometer_speed_t)MAT_MAX((sint32)permanent_limiter_speedlimit_new, (sint32)driver_requests->PLIM_VLIMIT);
  }
  driver_requests->PLIM_VLIMIT = (speedometer_speed_t)MAT_MIN((sint32)driver_requests->PLIM_VLIMIT, (((sint32)input->PERMANENT_LIMITER_SETSPEED - (sint32)driver_requests->PLIM_HYST) * (sint32)Speedo_speed_s));
  driver_requests->PLIM_VLIMIT = (speedometer_speed_t)MAT_MAX((sint32)driver_requests->PLIM_VLIMIT, (((sint32)input->PERMANENT_LIMITER_SETSPEED - (sint32)driver_requests->PLIM_THRESHOLD) * (sint32)Speedo_speed_s));


  /* Should the permanent limiter be engaged? */
  if (
      (input->SPEEDOMETER_VEHICLE_SPEED < driver_requests->PLIM_VLIMIT)
      ||
      (input->PERMANENT_LIMITER_SETSPEED == Cc_speed_default_value)
     )
  {
    driver_requests->ENGAGEMENT_CONDITIONS.END_PERM_LIM = TRUE;
  }
  else
  {
    driver_requests->ENGAGEMENT_CONDITIONS.GOTO_PERM_LIM = TRUE;
  }
#else
    driver_requests->ENGAGEMENT_CONDITIONS.GOTO_PERM_LIM = FALSE;
#endif /* (CFG_FCT_PLIM && GFG_FCT_CC_USE_PLIM_CONTROL_STATE) */

#endif /* (LONG_CFG_USE_EXTERN_ACC_STATE_MACHINE) */

}

#if (!LONG_CFG_USE_EXTERN_ACC_STATE_MACHINE)
/*************************************************************************************************************************
  Functionname:    KMC_v_DetermineSetSpeed                                                                          */ /*!

  @brief           Determine SetSpeed according to DRIVER_OPERATIONS

  @description     Depending on driver inputs, which are stored in DRIVER_OPERATIONS struct, set speed will be determined 
                   for the Cruise Control function and for the Cruise Control Limiter function. Speeds are initially converted
                   if speed unit is changed by driver. Setspeed is either obtained by rounding up current vehicle speed or by 
                   taking an appropriate step from current speed. Setspeed is then limited to the maximum and minimum allowed
                   values. On reset, setspeed is set to 0.

    @startuml
    Start
    Partition KMC_v_DetermineSetSpeed {
      If (SWITCH_SPEED_UNIT == TRUE) then (yes)
        : CC_SETSPEED is converted \nfrom one unit to the other;
      Else (no)
      Endif
      
      If (error_data->CC_INHIBIT == FALSE) then (yes)
        If (OPERATIONAL_MODE == Display_op_cc_valid) then (yes)
          If (CC_TAKE_ACTUAL_SPEED == TRUE) then (yes)
            : Round up from \nSPEEDOMETER_VEHICLE_SPEED_OFFSET;
          Else if (ACCEL_MODE == TRUE) then (yes)
            : Round up from \nSPEEDOMETER_VEHICLE_SPEED_OFFSET\nif GREATER than CC_SETSPEED;
          Else if (DECEL_MODE == TRUE) then (yes)
            : Round up from \nSPEEDOMETER_VEHICLE_SPEED_OFFSET\nif SMALLER than CC_SETSPEED;
          Else (no)

            If (CC_INCREASE_SET_SPEED == TRUE) then (yes)
              If (SPEED_STEP_1 == TRUE) then (yes)
                : Increment and roundup with\n SETSPEED_STEP_LEVEL_1;
              Else (no)
                : Increment and roundup with\n SETSPEED_STEP_LEVEL_2;
              Endif
            Elseif (CC_DECREASE_SET_SPEED == TRUE) then (yes)
              If (SPEED_STEP_1 == TRUE) then (yes)
              : Decrement and roundup with\n SETSPEED_STEP_LEVEL_1;
              Else (no)
              : Decrement and roundup with\n SETSPEED_STEP_LEVEL_2;
              Endif
            Else (no)
              : Do nothing;
            Endif

          Endif
        Else (no)
          : CC_SETSPEED not calculated;
        Endif
      Else (no)
        : CC_SETSPEED not calculated \nbecause of inhibition (error);
      Endif
      : CC_SETSPEED limited between limits;
    }
    End
    @enduml

  @return          -

  @param[in]       input_data : Pointer to CC input interface [cc_input_data_t as per cc_ext.h]
                        PERMANENT_LIMITER_SETSPEED : Maximum permanent (winter tire) limiter speed [0u ... 255u]
                        VEHICLE_STATUS.SPEED_UNIT_KMH : Boolean if speed unit is kmh (TRUE: kmh, FALSE: mph) [TRUE, FALSE]
  @param[in]       error_data : Information about CC and CC Limiter error state [cc_error_data_t as per cc_ext.h]
                        CC_INHIBIT : Boolean if FALSE - no CC error, TRUE - CC error [TRUE, FALSE]
                        LIM_INHIBIT : Boolean if FALSE - no LIM error, TRUE - LIM error [TRUE, FALSE]
  @param[in,out]   driver_requests : Driver request input structure [cc_driver_requests_t as per cc_ext.h]
                        CC_SETSPEED : Current Cruise Control set speed [0u ... 255u]
                        LIM_SETSPEED : Current Limiter set speed [0u ... 255u]
                        OPERATIONAL_MODE : Display operational mode [full range of datatype display_op_status_t as in Rte_Type.h]
                        CONTROL_STATE : Current state of the longitudinal control state machine [full range of datatype cc_control_state_t]
                        SETSPEED_STEP_LEVEL_1 : Set speed step small [0u ... 255u]
                        SETSPEED_STEP_LEVEL_2 : Set speed step large [0u ... 255u]
                        MIN_LIM_SETSPEED : Minimum set speed for the Limiter function [0u ... 255u]
                        MAX_LIM_SETSPEED : Maximum set speed for the Limiter function [0u ... 255u]
                        SPEEDOMETER_VEHICLE_SPEED_OFFSET : Offset compensated speedometer speed [-30000u ... 30000u]
                        MAX_CC_SETSPEED : Maximal Cruise Control set speed [0u ... 255u]
                        MIN_CC_SETSPEED : Minimal Cruise Control set speed [0u ... 255u]
                        DRIVER_OPERATIONS.CC_TAKE_ACTUAL_SPEED : Boolean, if TRUE take actual vehicle speedometer speed as CC_SETSPEED [TRUE, FALSE]
                        DRIVER_OPERATIONS.ACCEL_MODE : Boolean indicating if acceleration with constant value [TRUE, FALSE]
                        DRIVER_OPERATIONS.DECEL_MODE : Boolean indicating if deceleration with constant value [TRUE, FALSE]
                        DRIVER_OPERATIONS.CC_INCREASE_SET_SPEED : Boolean, if TRUE increase the set speed [TRUE, FALSE]
                        DRIVER_OPERATIONS.CC_DECREASE_SET_SPEED : Boolean, if TRUE decrease the set speed [TRUE, FALSE]
                        DRIVER_OPERATIONS.SPEED_STEP_1 : Boolean, if TRUE increase or decrease the set speed for Set speed step small [TRUE, FALSE]
                        DRIVER_OPERATIONS.LIM_TAKE_ACTUAL_SPEED : Boolean, if TRUE take actual vehicle speedometer speed as LIM_SETSPEED [TRUE, FALSE]
                        DRIVER_OPERATIONS.CC_RESUME_SET_SPEED : Boolean, if TRUE use the stored set speed as CC_SETSPEED [TRUE, FALSE]
                        DRIVER_OPERATIONS.LIM_INCREASE_SET_SPEED : Boolean, if TRUE increase the limiter set speed [TRUE, FALSE]
                        DRIVER_OPERATIONS.LIM_DECREASE_SET_SPEED : Boolean, if TRUE decrease the limiter set speed [TRUE, FALSE]
                        DRIVER_OPERATIONS.RESET_SETSPEED : Boolean, if TRUE reset CC_SETSPEED and LIM_SETSPEED to 0 [TRUE, FALSE]
                        DRIVER_OPERATIONS.SWITCH_SPEED_UNIT : Boolean if speed unit is changed by driver [TRUE, FALSE]
  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_LOPC_COMPONENT : Configuration switch for enabling LOPC processing
  @c_switch_full   FCT_CFG_CC : Configuration switch enabeling Cruise Control functionality (no object evaluation)
  @c_switch_full   LONG_CFG_USE_EXTERN_ACC_STATE_MACHINE : Configuration switch to use external ACC state machine

  @pre             -
  @post            -

  @created         -
  @changed         22.04.2016

  @author          Simon Sinnstein | simon.sinnstein@continental-corporation.com | +49 (8382) 9699-160
*************************************************************************************************************************/
static void KMC_v_DetermineSetSpeed(const cc_input_data_t* input_data,
                                   const cc_error_data_t* error_data,
                                   cc_driver_requests_t* driver_requests)
{

  cc_setspeed16_t CC_SETSPEED;
#if (CFG_FCT_LIM || CFG_FCT_PLIM)
  cc_setspeed16_t LIM_SETSPEED;
#endif

  /* Driver setspeed to be converted in units before it is modified */
  if(driver_requests->DRIVER_OPERATIONS.SWITCH_SPEED_UNIT == TRUE)
  {
    setspeed_t min_set_speed, max_set_speed, *actual_set_speed;
    uint32           uHelp;

    actual_set_speed = &(driver_requests->CC_SETSPEED);
    min_set_speed = (setspeed_t)0;
    max_set_speed = (setspeed_t)0;

#if (CFG_FCT_LIM || CFG_FCT_PLIM)
    actual_set_speed = &(driver_requests->LIM_SETSPEED);

    if(driver_requests->LIM_SETSPEED > (setspeed_t)0)
    {
      actual_set_speed = &(driver_requests->LIM_SETSPEED);
      min_set_speed = driver_requests->MIN_LIM_SETSPEED;
      max_set_speed = driver_requests->MAX_LIM_SETSPEED;
    }
#endif

    if(driver_requests->CC_SETSPEED > (setspeed_t)0)
    {
      actual_set_speed = &(driver_requests->CC_SETSPEED);
      min_set_speed = driver_requests->MIN_CC_SETSPEED;
      max_set_speed = driver_requests->MAX_CC_SETSPEED;
    }

    uHelp = (uint32)(*actual_set_speed);
    if(input_data->VEHICLE_STATUS.SPEED_UNIT_KMH == TRUE)
    {
      uHelp*= (uint32)Speed_conv_factor_kmh;
      uHelp+= (uint32)Speed_conv_factor_mph / (uint32)2;
      uHelp/= (uint32)Speed_conv_factor_mph;
    }
    else
    {
      uHelp*= (uint32)Speed_conv_factor_mph;
      uHelp+= (uint32)Speed_conv_factor_kmh / (uint32)2;
      uHelp/= (uint32)Speed_conv_factor_kmh;
    }
    *actual_set_speed = (setspeed_t)MAT_LIM((sint32)uHelp, (sint32)min_set_speed, (sint32)max_set_speed);
  }

  CC_SETSPEED  = (cc_setspeed16_t)driver_requests->CC_SETSPEED;
#if (CFG_FCT_LIM || CFG_FCT_PLIM)
  LIM_SETSPEED = (cc_setspeed16_t)driver_requests->LIM_SETSPEED;
#endif

  if (error_data->CC_INHIBIT == FALSE)
  {
    /* Determine CC_SETSPEED */
    if (driver_requests->OPERATIONAL_MODE == Display_op_cc_valid)
    {
      if (
        (driver_requests->DRIVER_OPERATIONS.CC_TAKE_ACTUAL_SPEED == TRUE)
        ||
        (driver_requests->DRIVER_OPERATIONS.ACCEL_MODE == TRUE)
        ||
        (driver_requests->DRIVER_OPERATIONS.DECEL_MODE == TRUE)
        )
      {
        if (driver_requests->DRIVER_OPERATIONS.DECEL_MODE == TRUE)
        {
          CC_SETSPEED = (cc_setspeed16_t)MAT_MIN((((sint32)driver_requests->SPEEDOMETER_VEHICLE_SPEED_OFFSET + (sint32)Speed_round_up) / (sint32)Velocity_s), (sint32)CC_SETSPEED);
        }
        else
        {
          if (driver_requests->DRIVER_OPERATIONS.ACCEL_MODE == TRUE)
          {
            CC_SETSPEED = (cc_setspeed16_t)MAT_MAX((((sint32)driver_requests->SPEEDOMETER_VEHICLE_SPEED_OFFSET + (sint32)Speed_round_up) / (sint32)Velocity_s), (sint32)CC_SETSPEED);
          }
          else
          {
            CC_SETSPEED = (cc_setspeed16_t)((driver_requests->SPEEDOMETER_VEHICLE_SPEED_OFFSET + Speed_round_up) / Velocity_s);
          }
        }
        CC_SETSPEED = (cc_setspeed16_t)MAT_MAX((sint32)CC_SETSPEED, (sint32)driver_requests->MIN_CC_SETSPEED);
        CC_SETSPEED = (cc_setspeed16_t)MAT_MIN((sint32)CC_SETSPEED, (sint32)driver_requests->MAX_CC_SETSPEED);
      }
      else
      {
        if (driver_requests->DRIVER_OPERATIONS.CC_INCREASE_SET_SPEED == TRUE)
        {
          if (driver_requests->DRIVER_OPERATIONS.SPEED_STEP_1 == TRUE)
          {
            /* Calculate the modulus remained relative to SETSPEED_STEP_LEVEL_1 of the current speed, so that
            final set speed is a 'clean' multiple of it */
            const sint32 iRemainSpeed = ((sint32)CC_SETSPEED % (sint32)driver_requests->SETSPEED_STEP_LEVEL_1);
            CC_SETSPEED = (cc_setspeed16_t)((sint32)CC_SETSPEED + ((sint32)driver_requests->SETSPEED_STEP_LEVEL_1 - iRemainSpeed));
          }
          else
          {
            /* Calculate the modulus remained relative to SETSPEED_STEP_LEVEL_2 of the current speed, so that
            final set speed is a 'clean' multiple of it */
            const sint32 iRemainSpeed = ((sint32)CC_SETSPEED % (sint32)driver_requests->SETSPEED_STEP_LEVEL_2);
            CC_SETSPEED = (cc_setspeed16_t)((sint32)CC_SETSPEED + ((sint32)driver_requests->SETSPEED_STEP_LEVEL_2 - iRemainSpeed));
          }
          
          CC_SETSPEED = (cc_setspeed16_t)MAT_MIN((sint32)CC_SETSPEED, (sint32)driver_requests->MAX_CC_SETSPEED);
        }
        else
        {
          if (driver_requests->DRIVER_OPERATIONS.CC_DECREASE_SET_SPEED == TRUE) 
          {
            if (driver_requests->DRIVER_OPERATIONS.SPEED_STEP_1 == TRUE) 
            {
              if (CC_SETSPEED >= (cc_setspeed16_t)driver_requests->SETSPEED_STEP_LEVEL_1) 
              {
                if ((CC_SETSPEED % (cc_setspeed16_t)driver_requests->SETSPEED_STEP_LEVEL_1) != (cc_setspeed16_t)0) 
                {/* PRQA S 715 */
                 /* date: 2018-03-22, reviewer: Ravi kiran Gurrala (uidn6378), reason: Nested control structures exceeds 15, not safety critical */
                  CC_SETSPEED = (cc_setspeed16_t)(CC_SETSPEED - (CC_SETSPEED % (cc_setspeed16_t)driver_requests->SETSPEED_STEP_LEVEL_1));
                }
                else
                {/* PRQA S 715 */
                 /* date: 2018-03-22, reviewer: Ravi kiran Gurrala (uidn6378), reason: Nested control structures exceeds 15, not safety critical */
                  CC_SETSPEED = (cc_setspeed16_t)((sint32)CC_SETSPEED - (sint32)driver_requests->SETSPEED_STEP_LEVEL_1);
                }
              }
              else
              {
                  //setspeed to zero
              }
            }
            else
            {
              if (CC_SETSPEED >= (cc_setspeed16_t)driver_requests->SETSPEED_STEP_LEVEL_2) 
              {
                if ((CC_SETSPEED % (cc_setspeed16_t)driver_requests->SETSPEED_STEP_LEVEL_2) != (cc_setspeed16_t)0) 
                {/* PRQA S 715 */
                 /* date: 2018-03-22, reviewer: Ravi kiran Gurrala (uidn6378), reason: Nested control structures exceeds 15, not safety critical */
                  CC_SETSPEED = (cc_setspeed16_t)(CC_SETSPEED - (CC_SETSPEED % (cc_setspeed16_t)driver_requests->SETSPEED_STEP_LEVEL_2));
                }
                else
                {/* PRQA S 715 */
                 /* date: 2018-03-22, reviewer: Ravi kiran Gurrala (uidn6378), reason: Nested control structures exceeds 15, not safety critical */
                  CC_SETSPEED = (cc_setspeed16_t)((sint32)CC_SETSPEED - (sint32)driver_requests->SETSPEED_STEP_LEVEL_2);
                }
              }
              else
              {
                CC_SETSPEED = (cc_setspeed16_t)0;
              }
            }

            CC_SETSPEED = (cc_setspeed16_t)MAT_MAX((sint32)CC_SETSPEED, (sint32)driver_requests->MIN_CC_SETSPEED);
          }
        }
      }
      /*! Limiting valid set speed */
      CC_SETSPEED = (setspeed_t)MAT_LIM((sint32)CC_SETSPEED,(sint32)driver_requests->MIN_CC_SETSPEED, (sint32)driver_requests->MAX_CC_SETSPEED);
    }
    else
    {
      /* do nothing */
    }
  }
  else
  {
    /* do not change the set speed at INHIBITION case, it can be done in custom specific part, if required */
    /* do nothing */
  }

#if (CFG_FCT_LIM || CFG_FCT_PLIM)

  if (error_data->LIM_INHIBIT == FALSE)
  {
    /* Determine LIM_SETSPEED */
    if (driver_requests->OPERATIONAL_MODE == Display_op_lim_valid)
    {
      if (
        (driver_requests->DRIVER_OPERATIONS.LIM_TAKE_ACTUAL_SPEED == TRUE)
        ||
        (driver_requests->DRIVER_OPERATIONS.ACCEL_MODE == TRUE)
        ||
        (driver_requests->DRIVER_OPERATIONS.DECEL_MODE == TRUE)
        )
      {
        if (driver_requests->DRIVER_OPERATIONS.DECEL_MODE == TRUE)
        {
          LIM_SETSPEED = (cc_setspeed16_t)MAT_MIN((((sint32)driver_requests->SPEEDOMETER_VEHICLE_SPEED_OFFSET + (sint32)Speed_round_up) / (sint32)Velocity_s), (sint32)LIM_SETSPEED);
        }
        else
        {
          if (driver_requests->DRIVER_OPERATIONS.ACCEL_MODE == TRUE)
          {
            LIM_SETSPEED = (cc_setspeed16_t)MAT_MAX((((sint32)driver_requests->SPEEDOMETER_VEHICLE_SPEED_OFFSET + (sint32)Speed_round_up) / (sint32)Velocity_s), (sint32)LIM_SETSPEED);
          }
          else
          {
            LIM_SETSPEED = (cc_setspeed16_t)((sint32)driver_requests->SPEEDOMETER_VEHICLE_SPEED_OFFSET / (sint32)Velocity_s);
          }
        }
        LIM_SETSPEED = (cc_setspeed16_t)MAT_LIM((sint32)LIM_SETSPEED, (sint32)driver_requests->MIN_LIM_SETSPEED,(sint32)driver_requests->MAX_LIM_SETSPEED);
      }
      else
      {
        if (driver_requests->DRIVER_OPERATIONS.LIM_INCREASE_SET_SPEED == TRUE)
        {
          if (driver_requests->DRIVER_OPERATIONS.SPEED_STEP_1 == TRUE)
          {
            LIM_SETSPEED = (cc_setspeed16_t)(LIM_SETSPEED + (cc_setspeed16_t)driver_requests->SETSPEED_STEP_LEVEL_1);
          }
          else
          {
            LIM_SETSPEED = (cc_setspeed16_t)(LIM_SETSPEED + ((cc_setspeed16_t)driver_requests->SETSPEED_STEP_LEVEL_2 - (LIM_SETSPEED % (cc_setspeed16_t)driver_requests->SETSPEED_STEP_LEVEL_2)));
          }
          LIM_SETSPEED = (cc_setspeed16_t)MAT_MIN((sint32)LIM_SETSPEED, (sint32)driver_requests->MAX_LIM_SETSPEED);
        }
        else
        {
          if (driver_requests->DRIVER_OPERATIONS.LIM_DECREASE_SET_SPEED == TRUE)
          {
            if (driver_requests->DRIVER_OPERATIONS.SPEED_STEP_1 == TRUE)
            {
              LIM_SETSPEED = (cc_setspeed16_t)(LIM_SETSPEED - (cc_setspeed16_t)driver_requests->SETSPEED_STEP_LEVEL_1);
            }
            else
            {
              if ((LIM_SETSPEED % (cc_setspeed16_t)driver_requests->SETSPEED_STEP_LEVEL_2) != (cc_setspeed16_t)0)
              {
                LIM_SETSPEED = (cc_setspeed16_t)(LIM_SETSPEED - (LIM_SETSPEED % (cc_setspeed16_t)driver_requests->SETSPEED_STEP_LEVEL_2));
              }
              else
              {
                LIM_SETSPEED = (cc_setspeed16_t)((sint32)LIM_SETSPEED - (sint32)driver_requests->SETSPEED_STEP_LEVEL_2);
              }
            }
            LIM_SETSPEED = (cc_setspeed16_t)MAT_MAX((sint32)LIM_SETSPEED, (sint32)driver_requests->MIN_LIM_SETSPEED);
          }
        }
      }
    }
  }
  else
  {
    LIM_SETSPEED = (cc_setspeed16_t)0;
  }

  if (driver_requests->CONTROL_STATE != Cc_plim_active)
  {
    driver_requests->LIM_SETSPEED = (setspeed_t)(LIM_SETSPEED);
  }
  else
  {
    driver_requests->LIM_SETSPEED = input_data->PERMANENT_LIMITER_SETSPEED;
  }
#endif /* (CFG_FCT_LIM || CFG_FCT_PLIM) */

  /*! if the no valid set speed was saved, the CC_SETSPEED = 0
      it needs for driver operation logic for the first engage via RESUME
      the Winter Tire Limiter can change MAX_CC_SETSPEED */
  driver_requests->CC_SETSPEED = (setspeed_t)MAT_LIM((sint32)CC_SETSPEED, (sint32)0, (sint32)driver_requests->MAX_CC_SETSPEED);

  if (driver_requests->DRIVER_OPERATIONS.RESET_SETSPEED == TRUE)
  {
#if (CFG_FCT_LIM || CFG_FCT_PLIM)
    driver_requests->LIM_SETSPEED = (setspeed_t)0;
#endif
    driver_requests->CC_SETSPEED = (setspeed_t)0;
  }
}
#endif /* (!LONG_CFG_USE_EXTERN_ACC_STATE_MACHINE) */

/*************************************************************************************************************************
  Functionname:    KMC_v_DetermineControlState                                                                      */ /*!

  @brief           State of Cruise control HMI state machine determined in driver_requests->CONTROL_STATE. 
                   State selection between {off, ready, engage, active, override, disengage, decel_only, 
                   limiter_disengage, limiter_ready, limiter_active, limiter_override, plim_active} based
                   on driver inputs, inhibition values and engagement conditions.

  @description     The purpose of this function is to handle the internal state machine. It can be replaced with an external
                   state machine using the switch (LONG_CFG_USE_EXTERN_ACC_STATE_MACHINE).
                   The function comprises of three different functionalities: CC state machine, limiter state machine and 
                   permanent limiter. The limiter state machine is similar to the CC state machine.
                   The CC state can be transitioned from off to ready state if CC mainswitch is on and if available. Transition 
                   from ready to engaged state is possible if driver engages the function and all inhibition conditions are 
                   inactive. If vehicle acceleration and jerk is within CC limits, CC state changed from engaged to active state.
                   If override request is sent from dynamic motion control (DMC) component, state is changed to override from active.
                   CC is changed to disengaged state if any inhibition conditions become active. CC_DECEL_ONLY is a special condition
                   of disengaged which is customer-specific. CC can be engaged again from disengaged state based on driver requests. 
                   The active CC state is also set between standstill, follow and free modes. The operational mode state controlling 
                   driver display is also set here based on states and driver inputs.

    @startuml
    [*] --> ACC_State_Machine

    state ACC_State_Machine{
      [*] --> Cc_cc_off
      Cc_cc_off --> Cc_cc_ready           : 1
      Cc_cc_off --> Cc_plim_active        
      Cc_cc_off --> Cc_lim_ready          
      Cc_cc_ready --> Cc_cc_engage        : 2
      Cc_cc_ready --> Cc_plim_active      
      Cc_cc_ready --> Cc_lim_ready        
      Cc_cc_engage --> Cc_cc_active       : 3
      Cc_cc_active --> Cc_cc_disengage    : 4
      Cc_cc_active --> Cc_cc_ready        : 5
      Cc_cc_active --> Cc_cc_override     : 6
      Cc_cc_active --> Cc_cc_decel_only   : 7
      Cc_cc_active --> Cc_plim_active     
      Cc_cc_disengage --> Cc_cc_ready     : 8
      Cc_cc_disengage --> Cc_cc_engage    : 9
      Cc_cc_disengage --> Cc_cc_off       : 10
      Cc_cc_disengage --> Cc_lim_active   
      Cc_cc_disengage --> Cc_plim_active  
      Cc_cc_override --> Cc_cc_active     : 11
      Cc_cc_override --> Cc_cc_ready      : 12
      Cc_cc_override --> Cc_plim_active 
      Cc_cc_ready --> Cc_cc_off           : 13
      Cc_cc_decel_only --> Cc_cc_off      : 14
      Cc_cc_decel_only --> Cc_cc_ready    : 15
      Cc_cc_decel_only --> Cc_plim_active
      Cc_cc_decel_only --> Cc_lim_active
      Cc_plim_active --> Cc_lim_active
      Cc_plim_active --> Cc_cc_engage
      Cc_lim_ready --> Cc_plim_active
      Cc_lim_ready --> Cc_cc_off
      Cc_lim_ready --> Cc_cc_ready
      Cc_lim_ready --> Cc_lim_active
      Cc_lim_active --> Cc_lim_ready
      Cc_lim_active --> Cc_plim_active
      Cc_lim_active --> Cc_lim_disengage
      Cc_lim_override --> Cc_lim_active
      Cc_lim_override --> Cc_lim_ready
      Cc_lim_override --> Cc_plim_active
      Cc_lim_disengage --> Cc_cc_off
      Cc_lim_disengage --> Cc_lim_ready
      Cc_lim_disengage --> Cc_lim_active

      Cc_cc_off : DAS_ENGAGED = FALSE
      Cc_cc_off : DAS_LIM  = FALSE
      Cc_cc_off : DAS_OVERRIDE  = FALSE
      Cc_cc_off : DAS_SHUTOFF_REQ = FALSE
      Cc_cc_ready : DAS_ENGAGED = FALSE
      Cc_cc_ready : DAS_LIM  = FALSE
      Cc_cc_ready : DAS_OVERRIDE  = FALSE
      Cc_cc_ready : DAS_SHUTOFF_REQ = FALSE  
      Cc_cc_engage : DAS_ENGAGED = FALSE
      Cc_cc_engage : DAS_LIM  = FALSE
      Cc_cc_engage : DAS_OVERRIDE  = FALSE
      Cc_cc_engage : DAS_SHUTOFF_REQ = FALSE
      Cc_cc_active : DAS_ENGAGED = TRUE
      Cc_cc_active : DAS_LIM  = FALSE
      Cc_cc_active : DAS_OVERRIDE  = FALSE
      Cc_cc_active : DAS_SHUTOFF_REQ = FALSE
      Cc_cc_override : DAS_ENGAGED = TRUE
      Cc_cc_override : DAS_LIM  = FALSE
      Cc_cc_override : DAS_OVERRIDE  = FALSE
      Cc_cc_override : DAS_SHUTOFF_REQ = FALSE
      Cc_cc_disengage : DAS_ENGAGED = TRUE
      Cc_cc_disengage : DAS_LIM  = FALSE
      Cc_cc_disengage : DAS_OVERRIDE  = FALSE
      Cc_cc_disengage : DAS_SHUTOFF_REQ = TRUE
  
      }

      note as N1
      1  (off -> ready):        SELECTED_FUNCTION == Cc_function_cc && CC_INHIBIT == FALSE
      2  (ready -> engaged):    SELECTED_FUNCTION == Cc_function_cc && ACCEPT_CC_ENGAGEMENT == TRUE && (CC_TAKE_ACTUAL_SPEED || CC_RESUME_SET_SPEED)
      3  (engaged->active) :    END_CC_ENGAGEMENT == TRUE
      4  (active->disengage) :  CC_DISENGAGEMENT_RAMP == TRUE || CANCEL_FUNKTION == TRUE
      5  (active->ready) :      CC_DISENGAGEMENT == TRUE 
      6  (active->override) :   DRIVER_OVERRIDE == TRUE
      7  (active->decelonly) :  CC_DECEL_ONLY == TRUE
      8  (disengage->ready) :   CC_DISENGAGEMENT == TRUE || (END_CC_DISENGAGEMENT == TRUE && SELECTED_FUNCTION == Cc_function_cc)
      9  (disengage->engaged) : ACCEPT_CC_ENGAGEMENT == TRUE && (CC_TAKE_ACTUAL_SPEED || CC_RESUME_SET_SPEED)
      10 (disengage->off) :     END_CC_DISENGAGEMENT == TRUE && SELECTED_FUNCTION != Cc_function_cc
      11 (override->active) :   DRIVER_OVERRIDE == FALSE
      12 (override->ready) :    CC_DISENGAGEMENT == TRUE || CC_DISENGAGEMENT_RAMP == TRUE || CANCEL_FUNKTION == TRUE
      13 (ready->off) :         SELECTED_FUNCTION != Cc_function_cc
      14 (decelonly->off) :     CC_END_DECEL_ONLY == TRUE && SELECTED_FUNCTION != Cc_function_cc
      15 (decelonly->ready) :   CC_DISENGAGEMENT == TRUE || (CC_END_DECEL_ONLY == TRUE && SELECTED_FUNCTION == Cc_function_cc)
      endnote

    @enduml

    @startuml
    Start
          If (GOTO_PERM_LIM == 0) then (yes)
            If (DISENGAGE_DRIVER_INTERVENED == 0) then (yes)
              If (CC_DISENGAGEMENT == 1) then (yes)
                If (CONTROL_STATE  == ACTIVE or OVERRIDE) then (yes)
                  : DISENGAGE_SIGNAL = TRUE;
                Else (no)
                Endif
              Else (no)
                If (CONTROL_STATE  == ACTIVE) then (yes)
                  If (CC_DECEL_ONLY == 1) then (yes)
                    :DISENGAGE_SIGNAL = TRUE;
                  Elseif (CC_DISENGAGEMENT_RAMP == 1)
                    : DISENGAGE_SIGNAL = TRUE;
                  Else (no)
                  Endif
                Elseif (CONTROL_STATE == OVERRIDE) then (yes)
                  If (CC_DISENGAGEMENT_RAMP == 1)
                    :DISENGAGE_SIGNAL = TRUE;
                  Else (no)
                  Endif
                Else (no)
                Endif
              Endif
            Else (no)
            Endif
            If (CONTROL_STATE == Cc_cc_decel_only && CC_END_DECEL_ONLY == 0\n && CC_DISENGAGEMENT == 0 && CC_TAKE_ACTUAL_SPEED == 0\n && CC_RESUME_SET_SPEED == 0) then (yes)
              :DISENGAGE_SIGNAL = TRUE;
            Else (no)
            Endif
          Else (no)
          Endif
          If (LODM_STAT.STANDSTILL == TRUE) then (yes)
            : CONTROL_MODE = Cc_standstill_mode;
          Else (no)
            If (Effective object exists) then (yes)
              : CONTROL_MODE = Cc_follow_mode;
            Else (no)
              : CONTROL_MODE = Cc_free_mode;
            Endif
          Endif
    End
    @enduml
 
  @return          -

  @param[in]       driver_controls : Pointer to Selected CC function by driver [cc_driver_controls_t as per cc_ext.h]
                    SELECTED_FUNCTION : This variable reflects which function is selected by the driver [cc_selected_function_t as per cc_ext.h]
  @param[in,out]   accel_control_data : Pointer to CC acceleration control data [cc_acceleration_control_data_t as per cc_ext.h]
                    ACCEL_STATUS.CANCEL_RAMP : Boolean, if TRUE indicating acceleration ramp cancelled [TRUE, FALSE]
                    ACCEL_STATUS.OBJECT_EFFECTIVE : Boolean, if TRUE indicating effective OOI for ACC [TRUE, FALSE]
  @param[in]       das_input : Pointer to input from longitudinal dynamics management to driver assistance system [cart_das_input_data_t as per cart_ext.h]
                    LODM_STAT.STANDSTILL : Boolean indicating if vehicle standstill is detected [TRUE, FALSE]
  @param[in,out]   error_data : Information about CC and CC Limiter error state [cc_error_data_t as per cc_ext.h]
                    DISENGAGE_SIGNAL : This bit is set when the active function is disengaged without intervention from the driver [TRUE, FALSE]
                    LIM_INHIBIT : Boolean, if TRUE indicates limiter error [TRUE, FALSE]
                    CC_INHIBIT : Boolean, if TRUE indicates CC error [TRUE, FALSE]
  @param[in,out]   driver_requests : Pointer to driver request input structure [cc_driver_requests_t as per cc_ext.h]
                    CONTROL_STATE : Current state of the longitudinal control state machine [full range of datatype cc_control_state_t as in cc_ext.h]
                    CONTROL_STATE_LAST_CYCLE : State of the longitudinal control state machine as per last cycle [full range of datatype cc_control_state_t as in cc_ext.h]
                    OPERATIONAL_MODE : Display operational mode [full range of datatype display_op_status_t as in Rte_Type.h]
                    ENGAGEMENT_CONDITIONS.GOTO_PERM_LIM : Boolean for enabling permanent limiter [TRUE, FALSE]
                    CONTROL_STATE_PLIM : This variable reflects the CONTROL_STATE that will be next after PLIM [full range of datatype cc_control_state_t as in cc_ext.h]
                    DRIVER_OPERATIONS.ACCEL_MODE : Boolean indicating if acceleration with constant value [TRUE, FALSE]
                    DRIVER_OPERATIONS.DECEL_MODE : Boolean indicating if deceleration with constant value [TRUE, FALSE]
                    DRIVER_OPERATIONS.CC_TAKE_ACTUAL_SPEED : Boolean, if TRUE take actual vehicle speedometer speed as CC_SETSPEED [TRUE, FALSE]
                    DRIVER_OPERATIONS.CC_RESUME_SET_SPEED : Boolean, if TRUE use the stored set speed as CC_SETSPEED [TRUE, FALSE]
                    DRIVER_OPERATIONS.CC_INCREASE_SET_SPEED : Boolean, if TRUE increase the set speed [TRUE, FALSE]
                    DRIVER_OPERATIONS.CC_DECREASE_SET_SPEED : Boolean, if TRUE decrease the set speed [TRUE, FALSE]
                    DRIVER_OPERATIONS.SWITCH_SPEED_UNIT : Boolean if speed unit is changed by driver [TRUE, FALSE]
                    DRIVER_OPERATIONS.CANCEL_FUNKTION : Boolean to cancel CC function [TRUE, FALSE]
                    DRIVER_OPERATIONS.LIM_TAKE_ACTUAL_SPEED : Boolean, if TRUE take actual vehicle speedometer speed as LIM_SETSPEED [TRUE, FALSE]
                    DRIVER_OPERATIONS.LIM_RESUME_SET_SPEED : Boolean, if TRUE use the stored set speed as LIM_SETSPEED [TRUE, FALSE]
                    DRIVER_OPERATIONS.LIM_INCREASE_SET_SPEED : Boolean, if TRUE increase the limiter set speed [TRUE, FALSE]
                    DRIVER_OPERATIONS.LIM_DECREASE_SET_SPEED :Boolean, if TRUE decrease the limiter set speed [TRUE, FALSE]
                    DRIVER_OPERATIONS.DISENGAGE_DRIVER_INTERVENED : Boolean indicating disengagement due to driver intervention [TRUE, FALSE]
                    ENGAGEMENT_CONDITIONS.ACCEPT_CC_ENGAGEMENT : Boolean, if TRUE engages Cruise control [TRUE, FALSE]
                    ENGAGEMENT_CONDITIONS.ACCEPT_LIM_ENGAGEMENT : Boolean, if TRUE engages speed limiter [TRUE, FALSE]
                    ENGAGEMENT_CONDITIONS.END_CC_ENGAGEMENT : Boolean, if TRUE ends CC engagement state [TRUE, FALSE]
                    ENGAGEMENT_CONDITIONS.END_CC_DISENGAGEMENT : Boolean, if TRUE ends CC disengagement [TRUE, FALSE]
                    ENGAGEMENT_CONDITIONS.LIM_DISENGAGEMENT : Boolean for disengagement of limiter [TRUE, FALSE]
                    ENGAGEMENT_CONDITIONS.END_LIM_DISENGAGEMENT : Boolean for ending limiter disengagement [TRUE, FALSE]
                    ENGAGEMENT_CONDITIONS.CC_DISENGAGEMENT : Boolean, if TRUE disengages CC [TRUE, FALSE]
                    ENGAGEMENT_CONDITIONS.CC_DISENGAGEMENT_RAMP : Inhibition bit for ramp [TRUE, FALSE]
                    ENGAGEMENT_CONDITIONS.GOTO_PERM_LIM : Boolean for enabling permanent limiter [TRUE, FALSE]
                    ENGAGEMENT_CONDITIONS.CC_DECEL_ONLY : Bit for HMI state decel_only [TRUE, FALSE]
                    ENGAGEMENT_CONDITIONS.CC_END_DECEL_ONLY : Bit for ending HMI state decel_only [TRUE, FALSE]
                    ENGAGEMENT_CONDITIONS.DRIVER_OVERRIDE : Boolean indicating override condition by driver [TRUE, FALSE]
  @param[in,out]   das_output : Pointer to output data from driver assistance system to longitudinal dynamics management [cart_das_output_data_t as per cart_ext.h]
                    DAS_STAT.DAS_LIM : Status bit for limiter [TRUE, FALSE]
                    DAS_STAT.DAS_ENGAGED : Status bit for ACC engaged [TRUE, FALSE]
                    DAS_STAT.DAS_OVERRIDE : Status bit for driver override [TRUE, FALSE]
                    DAS_STAT.DAS_SHUTOFF_REQ : Status bit for shutting off ACC [TRUE, FALSE]
  @param[in]       input_data : Pointer to cc_input_data_t type structure containing input data to CC [cc_input_data_t as per cc_ext.h]

  @glob_in         -
  @glob_out        -

  @c_switch_part   LONG_CFG_USE_EXTERN_ACC_STATE_MACHINE : Configuration switch to use external ACC state machine
  @c_switch_part   CFG_FCT_CC_CHANGE_SETSPEED_WHILE_READY_MODE : Configuration switch to allow change of setspeed in ready mode
  @c_switch_full   FCT_CFG_LOPC_COMPONENT : Configuration switch for enabling LOPC processing
  @c_switch_full   FCT_CFG_CC : Configuration switch for enabling CC processing
*************************************************************************************************************************/
static void KMC_v_DetermineControlState(const cc_driver_controls_t* driver_controls,
                                       cc_acceleration_control_data_t* accel_control_data,
                                       const cart_das_input_data_t* das_input,
                                       cc_error_data_t* error_data,
                                       cc_driver_requests_t* driver_requests,
                                       cart_das_output_data_t* das_output,
                                       const cc_input_data_t* input_data)
{

  /* From the CONTROL_STATE of the last cycle, a new Controlmode is determined */
  driver_requests->CONTROL_STATE_LAST_CYCLE = driver_requests->CONTROL_STATE;

  error_data->DISENGAGE_SIGNAL = FALSE;

#if (LONG_CFG_USE_EXTERN_ACC_STATE_MACHINE)

  /* Custom function to process the states received from external interface / state machine */
  KMC_v_ProcessExternalACCInterfaces(input_data, error_data, driver_requests, das_output);
  _PARAM_UNUSED(driver_controls);

#else
  switch (driver_requests->CONTROL_STATE)
  {
    case Cc_cc_off:
    {
      das_output->DAS_STAT.DAS_ENGAGED = FALSE;
      das_output->DAS_STAT.DAS_LIM  = FALSE;
      das_output->DAS_STAT.DAS_OVERRIDE  = FALSE;
      das_output->DAS_STAT.DAS_SHUTOFF_REQ = FALSE;

      driver_requests->OPERATIONAL_MODE = Display_op_none;

#if (CFG_FCT_CC_USE_PLIM_CONTROL_STATE)
      if (driver_requests->ENGAGEMENT_CONDITIONS.GOTO_PERM_LIM == TRUE)
      {
        if (error_data->LIM_INHIBIT == FALSE)
        {
          /* Remind the CONTROL_STATE after Permanent Limiter */
          driver_requests->CONTROL_STATE_PLIM = Cc_cc_off;
          driver_requests->CONTROL_STATE = Cc_plim_active;
        }
        else
        {
          /* Stay in Mode "Off" */
        }
      }
      else
#endif /* CFG_FCT_CC_USE_PLIM_CONTROL_STATE */
      {
        if (driver_controls->SELECTED_FUNCTION == Cc_function_cc)
        {
          if (error_data->CC_INHIBIT == FALSE)
          {
            /* MainSwitch On and CC Selected: Standby to engage CC */
            driver_requests->CONTROL_STATE = Cc_cc_ready;
          }
          else
          {
            /* Stay in Mode "Off" */
          }
        }
        else
        {
          if (driver_controls->SELECTED_FUNCTION == Cc_function_lim)
          {
            if (error_data->LIM_INHIBIT == FALSE)
            {
              /* MainSwitch On and Limiter Selected: Standby to engage Limiter */
              driver_requests->CONTROL_STATE = Cc_lim_ready;
            }
            else
            {
              /* Stay in Mode "Off" */
            }
          }
          else
          {
            /* Stay in Mode "Off" */
          }
        }
      }
      break;
    }
    case Cc_cc_ready:
    {
      das_output->DAS_STAT.DAS_ENGAGED = FALSE;
      das_output->DAS_STAT.DAS_LIM  = FALSE;
      das_output->DAS_STAT.DAS_OVERRIDE  = FALSE;
      das_output->DAS_STAT.DAS_SHUTOFF_REQ = FALSE;

      driver_requests->OPERATIONAL_MODE = Display_op_cc_none;

#if (CFG_FCT_CC_USE_PLIM_CONTROL_STATE)
      if (driver_requests->ENGAGEMENT_CONDITIONS.GOTO_PERM_LIM == TRUE)
      {
        /* Remind the CONTROL_STATE after Permanent Limiter */
        driver_requests->CONTROL_STATE_PLIM = Cc_cc_ready;
        driver_requests->CONTROL_STATE = Cc_plim_active;
      }
      else
#endif /* CFG_FCT_CC_USE_PLIM_CONTROL_STATE */
      {
        if (driver_controls->SELECTED_FUNCTION == Cc_function_lim)
        {
          /* MainSwitch On and Limiter Selected: Standby to engage Limiter */
          driver_requests->CONTROL_STATE = Cc_lim_ready;
        }
        else
        {
          if (driver_controls->SELECTED_FUNCTION == Cc_function_cc)
          {
            if (
              (driver_requests->DRIVER_OPERATIONS.CC_TAKE_ACTUAL_SPEED == TRUE)
              ||
              (driver_requests->DRIVER_OPERATIONS.CC_RESUME_SET_SPEED == TRUE)
              )
            {
              if (driver_requests->ENGAGEMENT_CONDITIONS.ACCEPT_CC_ENGAGEMENT == TRUE)
              {
                /* Engage ACC */
                driver_requests->CONTROL_STATE = Cc_cc_engage;
                driver_requests->OPERATIONAL_MODE = Display_op_cc_valid;
              }
              else
              {
                driver_requests->OPERATIONAL_MODE = Display_op_cc_invalid;
              }
            }
            else
            {
              /* Stay in Mode "Ready" */
              if (
                  (driver_requests->DRIVER_OPERATIONS.CC_INCREASE_SET_SPEED) 
                  ||
                  (driver_requests->DRIVER_OPERATIONS.CC_DECREASE_SET_SPEED)
                 ) 
              {
#if (CFG_FCT_CC_CHANGE_SETSPEED_WHILE_READY_MODE)
                driver_requests->OPERATIONAL_MODE = Display_op_cc_valid;
#else
                driver_requests->OPERATIONAL_MODE = Display_op_cc_invalid;
#endif
              }

              if(driver_requests->DRIVER_OPERATIONS.SWITCH_SPEED_UNIT == TRUE)
              {
                driver_requests->OPERATIONAL_MODE = Display_op_cc_valid;
              }
            }
          }
          else
          {
            driver_requests->CONTROL_STATE = Cc_cc_off;
          }
        }
      }
      break;
    }
    case Cc_cc_engage:
    {
      das_output->DAS_STAT.DAS_ENGAGED = FALSE;
      das_output->DAS_STAT.DAS_LIM  = FALSE;
      das_output->DAS_STAT.DAS_OVERRIDE  = FALSE;
      das_output->DAS_STAT.DAS_SHUTOFF_REQ = FALSE;

      driver_requests->OPERATIONAL_MODE = Display_op_cc_none;

      if (driver_requests->ENGAGEMENT_CONDITIONS.END_CC_ENGAGEMENT == TRUE)
      {
        driver_requests->CONTROL_STATE = Cc_cc_active;
      }
      else
      {
        /* Stay in Mode "Engage" */
        if(driver_requests->DRIVER_OPERATIONS.SWITCH_SPEED_UNIT == TRUE)
        {
          driver_requests->OPERATIONAL_MODE = Display_op_cc_valid;
        }
      }
      break;
    }
    case Cc_cc_active:
    case Cc_cc_override:
    {
      if (driver_requests->DRIVER_OPERATIONS.CANCEL_FUNKTION == TRUE) 
      {
        accel_control_data->ACCEL_STATUS.CANCEL_RAMP = TRUE;
      }

      das_output->DAS_STAT.DAS_ENGAGED = TRUE;
      das_output->DAS_STAT.DAS_LIM  = FALSE;
      das_output->DAS_STAT.DAS_OVERRIDE  = FALSE;
      das_output->DAS_STAT.DAS_SHUTOFF_REQ = FALSE;

      if (driver_requests->ENGAGEMENT_CONDITIONS.CC_DISENGAGEMENT == TRUE)
      {
#if (CFG_FCT_CC_USE_PLIM_CONTROL_STATE)
        if (driver_requests->ENGAGEMENT_CONDITIONS.GOTO_PERM_LIM == TRUE)
        {
          /* Remind the CONTROL_STATE B4 Permanent Limiter */
          driver_requests->CONTROL_STATE_PLIM = Cc_cc_ready;
          driver_requests->CONTROL_STATE = Cc_plim_active;
        }
        else
#endif  /* CFG_FCT_CC_USE_PLIM_CONTROL_STATE */
        {
          driver_requests->CONTROL_STATE = Cc_cc_ready;
          driver_requests->OPERATIONAL_MODE = Display_op_cc_disengage;

          if (driver_requests->DRIVER_OPERATIONS.DISENGAGE_DRIVER_INTERVENED == FALSE)
          {
            error_data->DISENGAGE_SIGNAL = TRUE;
          }
        }
      }
      else
      {
        if (driver_requests->CONTROL_STATE == Cc_cc_active)
        {
          driver_requests->OPERATIONAL_MODE = Display_op_cc_active;

          if (driver_requests->ENGAGEMENT_CONDITIONS.CC_DECEL_ONLY == TRUE)
          {
#if (CFG_FCT_CC_USE_PLIM_CONTROL_STATE)
            if (driver_requests->ENGAGEMENT_CONDITIONS.GOTO_PERM_LIM == TRUE)
            {
              /* Remind the CONTROL_STATE after Permanent Limiter */
              driver_requests->CONTROL_STATE_PLIM = Cc_cc_ready;
              driver_requests->CONTROL_STATE = Cc_plim_active;
            }
            else
#endif  /* CFG_FCT_CC_USE_PLIM_CONTROL_STATE */
            {
              driver_requests->CONTROL_STATE = Cc_cc_decel_only;
              driver_requests->OPERATIONAL_MODE = Display_op_cc_disengage;

              if (driver_requests->DRIVER_OPERATIONS.DISENGAGE_DRIVER_INTERVENED == FALSE)
              {
                error_data->DISENGAGE_SIGNAL = TRUE;
              }
            }
          }
          else
          {
            if (driver_requests->ENGAGEMENT_CONDITIONS.CC_DISENGAGEMENT_RAMP == TRUE)
            {
#if (CFG_FCT_CC_USE_PLIM_CONTROL_STATE)
              if (driver_requests->ENGAGEMENT_CONDITIONS.GOTO_PERM_LIM == TRUE)
              {
                /* Remind the CONTROL_STATE after Permanent Limiter */
                driver_requests->CONTROL_STATE_PLIM = Cc_cc_ready;
                driver_requests->CONTROL_STATE = Cc_plim_active;
              }
              else
#endif /* CFG_FCT_CC_USE_PLIM_CONTROL_STATE */
              {
                driver_requests->CONTROL_STATE = Cc_cc_disengage;
                driver_requests->OPERATIONAL_MODE = Display_op_cc_disengage;

                if (driver_requests->DRIVER_OPERATIONS.DISENGAGE_DRIVER_INTERVENED == FALSE)
                {
                  error_data->DISENGAGE_SIGNAL = TRUE;
                }
              }
            }
            else
            {
              if (driver_requests->DRIVER_OPERATIONS.CANCEL_FUNKTION == TRUE)
              {
#if (CFG_FCT_CC_USE_PLIM_CONTROL_STATE)
                if (driver_requests->ENGAGEMENT_CONDITIONS.GOTO_PERM_LIM == TRUE)
                {
                  /* Remind the CONTROL_STATE B4 Permanent Limiter */
                  driver_requests->CONTROL_STATE_PLIM = Cc_cc_ready;
                  driver_requests->CONTROL_STATE = Cc_plim_active;
                }
                else
#endif  /* CFG_FCT_CC_USE_PLIM_CONTROL_STATE */
                {
                  driver_requests->CONTROL_STATE = Cc_cc_disengage;
                  driver_requests->OPERATIONAL_MODE = Display_op_cc_disengage;
                }
              }
              else
              {
                if (driver_requests->ENGAGEMENT_CONDITIONS.DRIVER_OVERRIDE == TRUE)
                {
#if (CFG_FCT_CC_USE_PLIM_CONTROL_STATE)
                  if (driver_requests->ENGAGEMENT_CONDITIONS.GOTO_PERM_LIM == TRUE)/* PRQA S 715 */
                 /* date: 2018-03-22, reviewer: Ravi kiran Gurrala (uidn6378), reason: Nested control structures exceeds 15, not safety critical */
                  {
                    /* Remind the CONTROL_STATE after Permanent Limiter */
                    driver_requests->CONTROL_STATE_PLIM = Cc_cc_active;
                    driver_requests->CONTROL_STATE = Cc_plim_active;
                  }
                  else
#endif  /* CFG_FCT_CC_USE_PLIM_CONTROL_STATE */
                  {	   //PRQA S 715
                    driver_requests->CONTROL_STATE = Cc_cc_override;
                  }
                }
                else
                {
                  /* Stay in Mode "HoldSpeed" */
                  if (
                    (driver_requests->DRIVER_OPERATIONS.CC_INCREASE_SET_SPEED == TRUE)/* PRQA S 715 */
                    /* date: 2018-03-22, reviewer: Ravi kiran Gurrala (uidn6378), reason: Nested control structures exceeds 15, not safety critical */
                    ||
                    (driver_requests->DRIVER_OPERATIONS.CC_DECREASE_SET_SPEED == TRUE)
                    ||
                    (driver_requests->DRIVER_OPERATIONS.ACCEL_MODE == TRUE)
                    ||
                    (driver_requests->DRIVER_OPERATIONS.DECEL_MODE == TRUE)
                    ||
                    (driver_requests->DRIVER_OPERATIONS.CC_TAKE_ACTUAL_SPEED == TRUE)
                    ||
                    (driver_requests->DRIVER_OPERATIONS.SWITCH_SPEED_UNIT == TRUE)
                    )
                  {
                    driver_requests->OPERATIONAL_MODE = Display_op_cc_valid;
                  }
                  else
                  {
                    if (driver_requests->DRIVER_OPERATIONS.CC_RESUME_SET_SPEED == TRUE)
                    {
                      driver_requests->OPERATIONAL_MODE = Display_op_cc_valid;
                    }
                    else
                    {
                      driver_requests->OPERATIONAL_MODE = Display_op_cc_active;
                    }
                  }
                }
              }
            }
          }
        }
        else
        {
          /* (driver_requests->CONTROL_STATE == Cc_cc_override) */
          das_output->DAS_STAT.DAS_OVERRIDE  = TRUE;

          driver_requests->OPERATIONAL_MODE = Display_op_cc_override;

          if (driver_requests->ENGAGEMENT_CONDITIONS.CC_DISENGAGEMENT_RAMP == TRUE)
          {
#if (CFG_FCT_CC_USE_PLIM_CONTROL_STATE)
            if (driver_requests->ENGAGEMENT_CONDITIONS.GOTO_PERM_LIM == TRUE)
            {
              /* Remind the CONTROL_STATE after Permanent Limiter */
              driver_requests->CONTROL_STATE_PLIM = Cc_cc_ready;
              driver_requests->CONTROL_STATE = Cc_plim_active;
            }
            else
#endif  /* CFG_FCT_CC_USE_PLIM_CONTROL_STATE */
            {
              driver_requests->CONTROL_STATE = Cc_cc_ready;
              driver_requests->OPERATIONAL_MODE = Display_op_cc_disengage;

              if (driver_requests->DRIVER_OPERATIONS.DISENGAGE_DRIVER_INTERVENED == FALSE)
              {
                error_data->DISENGAGE_SIGNAL = TRUE;
              }
            }
          }
          else
          {
            if (driver_requests->DRIVER_OPERATIONS.CANCEL_FUNKTION == TRUE)
            {
#if (CFG_FCT_CC_USE_PLIM_CONTROL_STATE)
              if (driver_requests->ENGAGEMENT_CONDITIONS.GOTO_PERM_LIM == TRUE)
              {
                /* Remind the CONTROL_STATE B4 Permanent Limiter */
                driver_requests->CONTROL_STATE_PLIM = Cc_cc_ready;
                driver_requests->CONTROL_STATE = Cc_plim_active;
              }
              else
#endif  /* CFG_FCT_CC_USE_PLIM_CONTROL_STATE */
              {
                driver_requests->CONTROL_STATE = Cc_cc_ready;
                driver_requests->OPERATIONAL_MODE = Display_op_cc_disengage;
              }
            }
            else
            {
              if (driver_requests->ENGAGEMENT_CONDITIONS.DRIVER_OVERRIDE == TRUE)
              {
#if (CFG_FCT_CC_USE_PLIM_CONTROL_STATE)
                if (driver_requests->ENGAGEMENT_CONDITIONS.GOTO_PERM_LIM == TRUE)
                {
                  /* Remind the CONTROL_STATE B4 Permanent Limiter */
                  driver_requests->CONTROL_STATE_PLIM = Cc_cc_active;
                  driver_requests->CONTROL_STATE = Cc_plim_active;
                }
                else
#endif  /* CFG_FCT_CC_USE_PLIM_CONTROL_STATE */
                {
                  /* Stay in Mode "Override HoldSpeed" */
                  if (
                    (driver_requests->DRIVER_OPERATIONS.CC_INCREASE_SET_SPEED == TRUE)/* PRQA S 715 */
                    /* date: 2018-03-22, reviewer: Ravi kiran Gurrala (uidn6378), reason: Nested control structures exceeds 15, not safety critical */
                    ||
                    (driver_requests->DRIVER_OPERATIONS.CC_DECREASE_SET_SPEED == TRUE)
                    ||
                    (driver_requests->DRIVER_OPERATIONS.ACCEL_MODE == TRUE)
                    ||
                    (driver_requests->DRIVER_OPERATIONS.DECEL_MODE == TRUE)
                    ||
                    (driver_requests->DRIVER_OPERATIONS.CC_TAKE_ACTUAL_SPEED == TRUE)
                    ||
                    (driver_requests->DRIVER_OPERATIONS.SWITCH_SPEED_UNIT == TRUE)
                    )
                  {	//PRQA S 715
                    driver_requests->OPERATIONAL_MODE = Display_op_cc_valid;
                  }
                  else
                  {	//PRQA S 715
                    driver_requests->OPERATIONAL_MODE = Display_op_cc_override;
                  }
                }
              }
              else
              {
                driver_requests->CONTROL_STATE = Cc_cc_active;
              }
            }
          }
        }
      }
      break;
    }
    case Cc_cc_disengage:
    case Cc_cc_decel_only:
    case Cc_lim_disengage:
    {
      das_output->DAS_STAT.DAS_ENGAGED = TRUE;
      das_output->DAS_STAT.DAS_LIM  = FALSE;
      das_output->DAS_STAT.DAS_OVERRIDE  = FALSE;

      if (
          (driver_requests->CONTROL_STATE == Cc_cc_disengage) 
          || 
          (driver_requests->CONTROL_STATE == Cc_lim_disengage)
         )
      {
        das_output->DAS_STAT.DAS_SHUTOFF_REQ = TRUE;
      }
      else
      {
        das_output->DAS_STAT.DAS_SHUTOFF_REQ = FALSE;
      }
      
      if (driver_requests->CONTROL_STATE == Cc_lim_disengage)
      {
        das_output->DAS_STAT.DAS_LIM = TRUE;
      }
      else
      {
        das_output->DAS_STAT.DAS_LIM = FALSE;
      }

#if (CFG_FCT_CC_USE_PLIM_CONTROL_STATE)
      if (driver_requests->ENGAGEMENT_CONDITIONS.GOTO_PERM_LIM == TRUE)
      {
        /* Remind the CONTROL_STATE after Permanent Limiter */
        if ((driver_requests->CONTROL_STATE == Cc_cc_disengage) || (driver_requests->CONTROL_STATE == Cc_cc_decel_only))
        {
          driver_requests->CONTROL_STATE_PLIM = Cc_cc_ready;
        }
        else
        {
          driver_requests->CONTROL_STATE_PLIM = Cc_lim_ready;
        }

        driver_requests->CONTROL_STATE = Cc_plim_active;
      }
      else
#endif /* CFG_FCT_CC_USE_PLIM_CONTROL_STATE */
      {
        if (driver_requests->ENGAGEMENT_CONDITIONS.CC_DISENGAGEMENT == TRUE)
        {
          if ((driver_requests->CONTROL_STATE == Cc_cc_disengage) || (driver_requests->CONTROL_STATE == Cc_cc_decel_only))
          {
            driver_requests->CONTROL_STATE = Cc_cc_ready;
          }
        }
        else
        {
          if ((driver_requests->DRIVER_OPERATIONS.CC_TAKE_ACTUAL_SPEED == TRUE) || (driver_requests->DRIVER_OPERATIONS.CC_RESUME_SET_SPEED == TRUE))
          {
            if (driver_requests->ENGAGEMENT_CONDITIONS.ACCEPT_CC_ENGAGEMENT == TRUE)
            {
              /* Engage Cruise */
              driver_requests->CONTROL_STATE = Cc_cc_engage;
              driver_requests->OPERATIONAL_MODE = Display_op_cc_valid;
            }
            else
            {
              driver_requests->OPERATIONAL_MODE = Display_op_cc_invalid;
            }
          }
          else
          {
            if ((driver_requests->DRIVER_OPERATIONS.LIM_TAKE_ACTUAL_SPEED == TRUE) || (driver_requests->DRIVER_OPERATIONS.LIM_RESUME_SET_SPEED == TRUE))
            {
#if (CFG_FCT_LIM)
              if (driver_requests->ENGAGEMENT_CONDITIONS.ACCEPT_LIM_ENGAGEMENT == TRUE)
              {
                /* Engage Limiter */
                driver_requests->CONTROL_STATE = Cc_lim_active;
                driver_requests->OPERATIONAL_MODE = Display_op_lim_valid;
              }
              else
#endif
              {
                driver_requests->OPERATIONAL_MODE = Display_op_lim_invalid;
              }
            }
            else
            {
              if (
                (
                (driver_requests->ENGAGEMENT_CONDITIONS.CC_END_DECEL_ONLY == TRUE)
                &&
                (driver_requests->CONTROL_STATE == Cc_cc_decel_only)
                )
                ||
                (
                (driver_requests->ENGAGEMENT_CONDITIONS.END_CC_DISENGAGEMENT == TRUE)
                &&
                (driver_requests->CONTROL_STATE == Cc_cc_disengage)
                )
                ||
                (
                (driver_requests->ENGAGEMENT_CONDITIONS.END_LIM_DISENGAGEMENT == TRUE)
                &&
                (driver_requests->CONTROL_STATE == Cc_lim_disengage)
                )
                )
              {
                if (driver_controls->SELECTED_FUNCTION == Cc_function_cc)
                {
                  /* Cruise Selected: Standby to engage Cruise */
                  driver_requests->CONTROL_STATE = Cc_cc_ready;
                }
                else
                {
                  if (driver_controls->SELECTED_FUNCTION == Cc_function_lim)/* PRQA S 715 */
                 /* date: 2018-03-22, reviewer: Ravi kiran Gurrala (uidn6378), reason: Nested control structures exceeds 15, not safety critical */
                  {	//PRQA S 715
                    /* Limiter Selected: Standby to engage Limiter */
                    driver_requests->CONTROL_STATE = Cc_lim_ready;
                  }
                  else
                  {	//PRQA S 715
                    /* Nothing Selected: go to OFF */
                    driver_requests->CONTROL_STATE = Cc_cc_off;
                  }
                }
              }
              else
              {
                /* Stay in Mode "Shutoff"/"Decel Only" */
                if (driver_requests->CONTROL_STATE == Cc_cc_decel_only)
                {
                  error_data->DISENGAGE_SIGNAL = TRUE;
                  driver_requests->OPERATIONAL_MODE = Display_op_cc_disengage;
                }
              }
            }
          }
        }
      }
      break;
    }
    case Cc_lim_ready:
    {
      das_output->DAS_STAT.DAS_ENGAGED = FALSE;
      das_output->DAS_STAT.DAS_LIM  = FALSE;
      das_output->DAS_STAT.DAS_OVERRIDE  = FALSE;
      das_output->DAS_STAT.DAS_SHUTOFF_REQ  = FALSE;

      driver_requests->OPERATIONAL_MODE = Display_op_lim_none;

#if (CFG_FCT_CC_USE_PLIM_CONTROL_STATE)
      if (driver_requests->ENGAGEMENT_CONDITIONS.GOTO_PERM_LIM == TRUE)
      {
        /* Remind the CONTROL_STATE after Permanent Limiter */
        driver_requests->CONTROL_STATE_PLIM = Cc_lim_ready;
        driver_requests->CONTROL_STATE = Cc_plim_active;
      }
      else
#endif  /* CFG_FCT_CC_USE_PLIM_CONTROL_STATE */
      {
        if (driver_controls->SELECTED_FUNCTION == Cc_function_cc)
        {
          /* MainSwitch On and ACC Selected: Standby to engage ACC */
          driver_requests->CONTROL_STATE = Cc_cc_ready;
        }
        else
        {
          if (driver_controls->SELECTED_FUNCTION == Cc_function_lim)
          {
            if ((driver_requests->DRIVER_OPERATIONS.LIM_TAKE_ACTUAL_SPEED == TRUE) || (driver_requests->DRIVER_OPERATIONS.LIM_RESUME_SET_SPEED == TRUE))
            {
#if (CFG_FCT_LIM)
              if (driver_requests->ENGAGEMENT_CONDITIONS.ACCEPT_LIM_ENGAGEMENT == TRUE)
              {
                /* Engage ACC */
                driver_requests->CONTROL_STATE = Cc_lim_active;
                driver_requests->OPERATIONAL_MODE = Display_op_lim_valid;
              }
              else
#endif
              {
                driver_requests->OPERATIONAL_MODE = Display_op_lim_invalid;
              }
            }
            else
            {
              /* Stay in Mode "Ready" */
              if(driver_requests->DRIVER_OPERATIONS.SWITCH_SPEED_UNIT == TRUE)
              {
                driver_requests->OPERATIONAL_MODE = Display_op_lim_valid;
              }
            }
          }
          else
          {
            driver_requests->CONTROL_STATE = Cc_cc_off;
          }
        }
      }
      break;
    }
    case Cc_lim_active:
    case Cc_lim_override:
    {
      das_output->DAS_STAT.DAS_ENGAGED = TRUE;
      das_output->DAS_STAT.DAS_LIM  = TRUE;
      das_output->DAS_STAT.DAS_SHUTOFF_REQ  = FALSE;

      driver_requests->OPERATIONAL_MODE = Display_op_lim_active;

      if (driver_requests->CONTROL_STATE == Cc_lim_override)
      {
        das_output->DAS_STAT.DAS_OVERRIDE  = TRUE;
      }
      else
      {
        das_output->DAS_STAT.DAS_OVERRIDE  = FALSE;
      }

      if ((driver_requests->DRIVER_OPERATIONS.CANCEL_FUNKTION == TRUE) || (driver_requests->ENGAGEMENT_CONDITIONS.LIM_DISENGAGEMENT == TRUE))
      {
#if (CFG_FCT_CC_USE_PLIM_CONTROL_STATE)
        if (driver_requests->ENGAGEMENT_CONDITIONS.GOTO_PERM_LIM == TRUE)
        {
          /* Remind the CONTROL_STATE after Permanent Limiter */
          driver_requests->CONTROL_STATE_PLIM = Cc_lim_ready;
          driver_requests->CONTROL_STATE = Cc_plim_active;
        }
        else
#endif  /* CFG_FCT_CC_USE_PLIM_CONTROL_STATE */
        {
          if (driver_requests->CONTROL_STATE == Cc_lim_active)
          {
            driver_requests->CONTROL_STATE = Cc_lim_disengage;
          }
          else
          {
            driver_requests->CONTROL_STATE = Cc_lim_ready;
          }

          driver_requests->OPERATIONAL_MODE = Display_op_lim_disengage;

          if (driver_requests->ENGAGEMENT_CONDITIONS.LIM_DISENGAGEMENT == TRUE)
          {
            error_data->DISENGAGE_SIGNAL = TRUE;
          }
        }
      }
      else
      {
        if ((driver_requests->DRIVER_OPERATIONS.LIM_INCREASE_SET_SPEED == TRUE) || (driver_requests->DRIVER_OPERATIONS.LIM_DECREASE_SET_SPEED == TRUE) || (driver_requests->DRIVER_OPERATIONS.ACCEL_MODE == TRUE) || (driver_requests->DRIVER_OPERATIONS.DECEL_MODE == TRUE))
        {
          driver_requests->OPERATIONAL_MODE = Display_op_lim_valid;
        }

        if(driver_requests->DRIVER_OPERATIONS.SWITCH_SPEED_UNIT == TRUE)
        {
          driver_requests->OPERATIONAL_MODE = Display_op_lim_valid;
        }

        if (driver_requests->CONTROL_STATE == Cc_lim_active)
        {
          if (driver_requests->ENGAGEMENT_CONDITIONS.DRIVER_OVERRIDE == TRUE)
          {
            driver_requests->CONTROL_STATE = Cc_lim_override;
          }
        }
        else
        {
          if (driver_requests->ENGAGEMENT_CONDITIONS.DRIVER_OVERRIDE == FALSE)
          {
            driver_requests->CONTROL_STATE = Cc_lim_active;
          }
        }
      }
      break;
    }
    case Cc_plim_active:
    {
      das_output->DAS_STAT.DAS_ENGAGED = TRUE;
      das_output->DAS_STAT.DAS_LIM  = TRUE;
      das_output->DAS_STAT.DAS_SHUTOFF_REQ  = FALSE;
      das_output->DAS_STAT.DAS_OVERRIDE  = FALSE;

      driver_requests->OPERATIONAL_MODE = Display_op_plim;

#if (CFG_FCT_CC_USE_PLIM_CONTROL_STATE)
      if (driver_requests->ENGAGEMENT_CONDITIONS.GOTO_PERM_LIM == TRUE)
      {
        /* Go back to control mode B4 Permanent Limiter */
        driver_requests->CONTROL_STATE = driver_requests->CONTROL_STATE_PLIM;
      }
      else
#endif  /* CFG_FCT_CC_USE_PLIM_CONTROL_STATE */
      {
        /* Driver Actuation? */
        if ((driver_requests->DRIVER_OPERATIONS.CC_TAKE_ACTUAL_SPEED == TRUE) || (driver_requests->DRIVER_OPERATIONS.CC_RESUME_SET_SPEED == TRUE))
        {
          if (driver_requests->ENGAGEMENT_CONDITIONS.ACCEPT_CC_ENGAGEMENT == TRUE)
          {
            /* Engage Cruise */
            driver_requests->CONTROL_STATE = Cc_cc_engage;
            driver_requests->OPERATIONAL_MODE = Display_op_cc_valid;
          }
          else
          {
            driver_requests->OPERATIONAL_MODE = Display_op_cc_invalid;
          }
        }
        else
        {
          if ((driver_requests->DRIVER_OPERATIONS.LIM_TAKE_ACTUAL_SPEED == TRUE) || (driver_requests->DRIVER_OPERATIONS.LIM_RESUME_SET_SPEED == TRUE))
          {
#if (CFG_FCT_LIM)
            if (driver_requests->ENGAGEMENT_CONDITIONS.ACCEPT_LIM_ENGAGEMENT == TRUE)
            {
              /* Engage Limiter */
              driver_requests->CONTROL_STATE = Cc_lim_active;
              driver_requests->OPERATIONAL_MODE = Display_op_lim_valid;
            }
            else
#endif
            {
              driver_requests->OPERATIONAL_MODE = Display_op_lim_invalid;
            }
          }
          else
          {
            /* Remind Disengagement of Cruise */
            if (driver_requests->CONTROL_STATE_PLIM == Cc_cc_active)
            {
              if ((driver_requests->ENGAGEMENT_CONDITIONS.CC_DISENGAGEMENT_RAMP == TRUE) || (driver_requests->ENGAGEMENT_CONDITIONS.CC_DISENGAGEMENT == TRUE) || (driver_requests->DRIVER_OPERATIONS.CANCEL_FUNKTION == TRUE))
              {
                driver_requests->CONTROL_STATE_PLIM = Cc_cc_ready;
                driver_requests->OPERATIONAL_MODE = Display_op_cc_disengage;
              }
            }
          }
        }
      }
      break;
    }
    default :
    {
        break;
    }
  }
  _PARAM_UNUSED(input_data);

#endif

  if (das_input->LODM_STAT.STANDSTILL == TRUE)
  {
    driver_requests->CONTROL_MODE = Cc_standstill_mode;
  }
  else
  {
    if (accel_control_data->ACCEL_STATUS.OBJECT_EFFECTIVE == TRUE)
    {
      driver_requests->CONTROL_MODE = Cc_follow_mode;
    }
    else
    {
      driver_requests->CONTROL_MODE = Cc_free_mode;
    }
  }
  
  if(driver_requests->DRIVER_OPERATIONS.SWITCH_SPEED_UNIT == TRUE)
  {
    driver_requests->OPERATIONAL_MODE = Display_op_cc_valid;
  }
}// PRQA S 7012, 7004
/* date: 2018-03-23, reviewer: Ravi Kiran Gurrala, reason: Cyclomatic complexity, Not safety critical */

/*************************************************************************************************************************
  Functionname:    KMC_v_DetermineSpeedLimits                                                                       */ /*!

  @brief           Determine the Limits for SetSpeed

  @description     Speedometer vehicle speed offset is determined as a function of vehicle acceleration.
                   Minimum and maximum speed limits for CC setspeed and limiter set speed are determined 
                   based on feature availability like only CC, ACC or FSRACC and country of application. 
                   These criteria are also used to determine engage, disengage and permanent limiter speed 
                   limit thresholds. Setspeed levels that are used by the driver are defined. Calculation 
                   of speedometer vehicle speed used for calculation of accelerations.

@startuml
Start
Partition KMC_v_DetermineSpeedLimits(){
: Acceleration offset is determined as a function of vehicle acceleration and limited to min and max offset values;
: Minimum and maximum speed limits for CC setspeed ,limiter\n set speed and CC Disengage Speed are determined based on feature availability\n like ACC, CC, FSRACC;
: Speed Offset is calculated as a function of Input Vehicle Speed;
If (Speed unit is KPH) Then (True)
: Convert Acceleration offset, Speed offset, Input Speedometer Speed\n, Speedometer Limits from KPH to m/s;
Else (false)
:convert Acceleration offset, Speed Offset, Input Speedometer Speed\n, Speedometer Limits from MPH to m/s;
endif
: Speedometer Speed is calculated from sum of Input Speedometer Speed and Speed Offsets;
: Speedometer Vehilce speed offset is calculated from Speedometer Speed and Acceleration offset;
}
End
@enduml 


  @return          -

  @param[in]       accel_control_data : Pointer to CC acceleration control data [cc_acceleration_control_data_t as per cc_ext.h]
                    ACCEL_STATUS.OBJECT_EFFECTIVE : Boolean, if TRUE indicating effective OOI for ACC [TRUE, FALSE]
  @param[in]       das_input : Pointer to input from longitudinal dynamics management to driver assistance system [cart_das_input_data_t as per cart_ext.h]
                    VEHICLE_ACCEL : Ego longitudinal acceleration [-30000u ...+30000u] m/s2 (with factor Acceleration_s)
                    VEHICLE_SPEED : Ego speed with factor Velocity_s [-30000u ... 30000u] cm/s
  @param[in]       input : Pointer to cc_input_data_t type structure containing input data to CC [cc_input_data_t as per cc_ext.h]
                    VEHICLE_STATUS.SPEED_UNIT_KMH : Boolean if speed unit is kmh (TRUE: kmh, FALSE: mph) 
                    COUNTRY_CODE : Code indicating region of the world [cc_country_code_t as per cc_ext.h]
                    VEHICLE_SPEED_LIMIT : Upper speed limit of vehicle [0u ... 255u]
                    PERMANENT_LIMITER_SETSPEED : Maximum permanent (winter tire) limiter speed [0u ... 255u]
                    SPEEDOMETER_VEHICLE_SPEED : Current speedometer speed with factor Velocity_s [-30000u ... 30000u]
  @param[in,out]   driver_requests : Pointer to driver request input structure [cc_driver_requests_t as per cc_ext.h]
                    MIN_CC_SETSPEED : Minimal Cruise Control set speed [0u ... 255u] 
                    MIN_CC_ENGAGESPEED : Minimum speed for engaging CC [0u ... 255u]
                    MAX_CC_SETSPEED :  Maximal Cruise Control set speed [0u ... 255u]
                    CC_DISENGAGE_THRESHOLD : Speed threshold below minimum setspeed below which, CC is disengaged [0u ... 255u]
                    SETSPEED_STEP_LEVEL_1 : Set speed step small [0u ... 255u]
                    SETSPEED_STEP_LEVEL_2 : Set speed step large [0u ... 255u]
                    PLIM_HYST : Hysteresis for disengagement of permanent limiter [0u ... 255u]
                    MIN_LIM_SETSPEED : Minimum set speed for the Limiter function [0u ... 255u]
                    MAX_LIM_SETSPEED : Maximum set speed for the Limiter function [0u ... 255u]
                    PLIM_THRESHOLD : Threshold for engagement of permanent limiter below driver selected maximum speed [0 ... 255u]
                    SPEEDOMETER_VEHICLE_SPEED : Current speedometer speed with factor Velocity_s [-30000u ... 30000u]
                    SPEEDOMETER_VEHICLE_SPEED_OFFSET : Offset compensated speedometer speed [-30000u ... 30000u]

  @glob_in         -
  @glob_out        -

  @c_switch_part   FCT_CFG_FSRACC : Configuration switch enabling Full Speed Range Adaptive Cruise Control functionality (with object evaluation and stop and go capability)
  @c_switch_part   FCT_CFG_ACC_HEADWAY_PLANNER : Configuration switch for enabling CC processing
  @c_switch_part   CFG_FCT_LIM : Configuration switch for enabling limiter function
  @c_switch_part   CFG_FCT_PLIM : Configuration switch for enabling permanenter limiter function
  @c_switch_part   LONG_CFG_USE_EXTERN_ACC_STATE_MACHINE : Configuration switch to use external ACC state machine
  @c_switch_full   FCT_CFG_LOPC_COMPONENT : Configuration switch for enabling LOPC processing
  @c_switch_full   FCT_CFG_CC : Configuration switch for enabling CC processing
*************************************************************************************************************************/
static void KMC_v_DetermineSpeedLimits(const cc_acceleration_control_data_t* accel_control_data,
                                      const cart_das_input_data_t* das_input,
                                      const cc_input_data_t* input,
                                      cc_driver_requests_t* driver_requests)
{
  sint32        AccelerationOffset;   /* to clarify if the variable still needed */
  sint32        MinAccelerationOffset; /* to clarify if the variable still needed */
  sint32        MaxAccelerationOffset; /* to clarify if the variable still needed */
  sint32        MinValidSpeedoVelocity; /*!< Minimum valid speedometer velosity */
  sint32        MaxValidSpeedoVelocity; /*!< Maximum valid speedometer velosity */

  MinAccelerationOffset = Cc_max_neg_accel_offset;
  MaxAccelerationOffset = Cc_max_pos_accel_offset;

  if (das_input->VEHICLE_ACCEL < (acceleration_t)0)
  {
    AccelerationOffset = (sint32)Cc_neg_accel_offset;
  }
  else
  {
    AccelerationOffset = (sint32)Cc_pos_accel_offset;
  }
  
  if (input->VEHICLE_STATUS.SPEED_UNIT_KMH == TRUE)
  {
    /*unit KMH*/

#if(FCT_CFG_FSRACC)
    driver_requests->MIN_CC_SETSPEED = Kmc_acc_fsr_min_setspeed_kmh;
    driver_requests->MIN_CC_ENGAGESPEED = Kmc_acc_fsr_min_v_engage_kmh;
#else
    driver_requests->MIN_CC_SETSPEED = Cc_min_setspeed_kmh;
    driver_requests->MIN_CC_ENGAGESPEED = Cc_min_v_engage_kmh;
#endif
#if (FCT_CFG_ACC_HEADWAY_PLANNER)
    driver_requests->MAX_CC_SETSPEED = Kmc_acc_max_setspeed_kmh;
#else
    driver_requests->MAX_CC_SETSPEED = Cc_max_setspeed_kmh;
#endif
#if (FCT_CFG_ACC_HEADWAY_PLANNER)
    if(accel_control_data->ACCEL_STATUS.OBJECT_EFFECTIVE == TRUE)
    {
      /*object effectiv == true*/
#if (FCT_CFG_FSRACC)
      driver_requests->CC_DISENGAGE_THRESHOLD = Kmc_acc_fsr_disengage_threshold_kmh;
#else
      driver_requests->CC_DISENGAGE_THRESHOLD = Cc_disengage_threshold_kmh;
#endif
    }
    else
    {
      /*object effectiv == false*/
      driver_requests->CC_DISENGAGE_THRESHOLD = Cc_disengage_threshold_cruise_kmh;
    }
#else
    driver_requests->CC_DISENGAGE_THRESHOLD = Cc_disengage_threshold_cruise_kmh;
#endif
#if(!LONG_CFG_USE_EXTERN_ACC_STATE_MACHINE)
    driver_requests->SETSPEED_STEP_LEVEL_1 = Cc_setspeed_step_level_1_kmh;
    driver_requests->SETSPEED_STEP_LEVEL_2 = Cc_setspeed_step_level_2_kmh;
#endif
    driver_requests->MAX_CC_SPEED = Cc_max_speed_kmh;
#if (CFG_FCT_LIM || CFG_FCT_PLIM)
    driver_requests->PLIM_THRESHOLD = Plim_threshold_kmh;
    driver_requests->PLIM_HYST = Plim_hyst_kmh;
    driver_requests->MIN_LIM_SETSPEED = Lim_min_setspeed_kmh;
    driver_requests->MAX_LIM_SETSPEED = Lim_max_setspeed_kmh;
#endif

    AccelerationOffset *= (sint32)Speed_conv_factor_kmh;
    AccelerationOffset /= (sint32)Factor_s;
    MinAccelerationOffset *= (sint32)Speed_conv_factor_kmh;
    MinAccelerationOffset /= (sint32)Factor_s;
    MaxAccelerationOffset *= (sint32)Speed_conv_factor_kmh;
    MaxAccelerationOffset /= (sint32)Factor_s;
  }
  else
  {
    /*unit MPH*/

#if(FCT_CFG_FSRACC)
    if (input->COUNTRY_CODE == Cc_usa)
    {
      driver_requests->MIN_CC_SETSPEED = Kmc_acc_fsr_min_setspeed_usa_mph;
      driver_requests->MIN_CC_ENGAGESPEED = Kmc_acc_fsr_min_v_engage_usa_mph;
    }
    else
    {
      driver_requests->MIN_CC_SETSPEED = Kmc_acc_fsr_min_setspeed_mph;
      driver_requests->MIN_CC_ENGAGESPEED = Kmc_acc_fsr_min_v_engage_mph;
    }
#else
    if (input->COUNTRY_CODE == Cc_usa) {
     
      driver_requests->MIN_CC_SETSPEED = Cc_min_setspeed_usa_mph;
      driver_requests->MIN_CC_ENGAGESPEED = Cc_min_v_engage_usa_mph;
    }
    else {
      
      driver_requests->MIN_CC_SETSPEED = Cc_min_setspeed_mph;
      driver_requests->MIN_CC_ENGAGESPEED = Cc_min_v_engage_mph;
    }        
#endif

#if (FCT_CFG_ACC_HEADWAY_PLANNER)
    driver_requests->MAX_CC_SETSPEED = Kmc_acc_max_setspeed_mph;
#else
    driver_requests->MAX_CC_SETSPEED = Cc_max_setspeed_mph;
#endif
#if (FCT_CFG_ACC_HEADWAY_PLANNER)
    if(accel_control_data->ACCEL_STATUS.OBJECT_EFFECTIVE == TRUE)
    {
      /*object effectiv == true*/
#if (FCT_CFG_FSRACC)
      driver_requests->CC_DISENGAGE_THRESHOLD = Kmc_acc_fsr_disengage_threshold_mph;
#else
      driver_requests->CC_DISENGAGE_THRESHOLD = Cc_disengage_threshold_mph;
#endif
    }
    else
    {
      /*object effectiv == false*/
      driver_requests->CC_DISENGAGE_THRESHOLD = Cc_disengage_threshold_cruise_mph;
    }
#else
    driver_requests->CC_DISENGAGE_THRESHOLD = Cc_disengage_threshold_cruise_mph;
#endif

#if(!LONG_CFG_USE_EXTERN_ACC_STATE_MACHINE)
    driver_requests->SETSPEED_STEP_LEVEL_1 = Cc_setspeed_step_level_1_mph;
    driver_requests->SETSPEED_STEP_LEVEL_2 = Cc_setspeed_step_level_2_mph;
#endif
    driver_requests->MAX_CC_SPEED = Cc_max_speed_mph;
#if (CFG_FCT_LIM || CFG_FCT_PLIM)
    driver_requests->PLIM_THRESHOLD = Plim_threshold_mph;
    driver_requests->PLIM_HYST = Plim_hyst_mph;
    driver_requests->MIN_LIM_SETSPEED = Lim_min_setspeed_mph;
    driver_requests->MAX_LIM_SETSPEED = Lim_max_setspeed_mph;
#endif
    AccelerationOffset *= (sint32)Speed_conv_factor_mph;
    AccelerationOffset /= (sint32)Factor_s;
    MinAccelerationOffset *= (sint32)Speed_conv_factor_mph;
    MinAccelerationOffset /= (sint32)Factor_s;
    MaxAccelerationOffset *= (sint32)Speed_conv_factor_mph;
    MaxAccelerationOffset /= (sint32)Factor_s;
  }

  /* Limit to the maximum vehicle speed */
  driver_requests->MIN_CC_SETSPEED = (setspeed_t)MAT_MIN((sint32)driver_requests->MIN_CC_SETSPEED, (sint32)input->VEHICLE_SPEED_LIMIT);
  driver_requests->MAX_CC_SETSPEED = (setspeed_t)MAT_MIN((sint32)driver_requests->MAX_CC_SETSPEED, (sint32)input->VEHICLE_SPEED_LIMIT);

  /* Limit to the PermanentLimiterSetSpeed */
  driver_requests->MIN_CC_SETSPEED = (setspeed_t)MAT_MIN((sint32)driver_requests->MIN_CC_SETSPEED, (sint32)input->PERMANENT_LIMITER_SETSPEED);
  driver_requests->MAX_CC_SETSPEED = (setspeed_t)MAT_MIN((sint32)driver_requests->MAX_CC_SETSPEED, (sint32)input->PERMANENT_LIMITER_SETSPEED);
#if (CFG_FCT_LIM || CFG_FCT_PLIM)
  driver_requests->MIN_LIM_SETSPEED = (setspeed_t)MAT_MIN((sint32)driver_requests->MIN_LIM_SETSPEED, (sint32)input->VEHICLE_SPEED_LIMIT);
  driver_requests->MAX_LIM_SETSPEED = (setspeed_t)MAT_MIN((sint32)driver_requests->MAX_LIM_SETSPEED, (sint32)input->VEHICLE_SPEED_LIMIT);

  driver_requests->MIN_LIM_SETSPEED = (setspeed_t)MAT_MIN((sint32)driver_requests->MIN_LIM_SETSPEED, (sint32)input->PERMANENT_LIMITER_SETSPEED);
  driver_requests->MAX_LIM_SETSPEED = (setspeed_t)MAT_MIN((sint32)driver_requests->MAX_LIM_SETSPEED, (sint32)input->PERMANENT_LIMITER_SETSPEED);
#endif

  /* Offset is a function of vehicle acceleration */
  AccelerationOffset *= (sint32)das_input->VEHICLE_ACCEL;
  AccelerationOffset /= (sint32)Acceleration_s;
  AccelerationOffset = MAT_LIM(AccelerationOffset, MinAccelerationOffset, MaxAccelerationOffset);

  /*! The minimum valid speed is the real vehicle speed from VDY + Cc_min_valid_speedo_offset */
  MinValidSpeedoVelocity = (sint32)das_input->VEHICLE_SPEED;
  MinValidSpeedoVelocity += (sint32)MAT_CALCULATE_PARAM_VALUE1D(Cc_min_valid_speedo_offset, Cc_min_valid_speedo_offset_points, das_input->VEHICLE_SPEED);
  /*! The maximum valid speedometer speed is the vehicle speed + Cc_max_valid_speedo_offset */
  MaxValidSpeedoVelocity = (sint32)das_input->VEHICLE_SPEED;
  MaxValidSpeedoVelocity += (sint32)MAT_CALCULATE_PARAM_VALUE1D(Cc_max_valid_speedo_offset, Cc_max_valid_speedo_offset_points, das_input->VEHICLE_SPEED);

  /*! Velocity conversion depending of velocity unit */
  if (input->VEHICLE_STATUS.SPEED_UNIT_KMH == TRUE)
  {
    /*! unit KMH */
    MinValidSpeedoVelocity *= (sint32)Speed_conv_factor_kmh;
    MinValidSpeedoVelocity /= (sint32)Factor_s;
    MaxValidSpeedoVelocity *= (sint32)Speed_conv_factor_kmh;
    MaxValidSpeedoVelocity /= (sint32)Factor_s;
  }
  else
  {
    /*! unit MPH */
    MinValidSpeedoVelocity *= (sint32)Speed_conv_factor_mph;
    MinValidSpeedoVelocity /= (sint32)Factor_s;
    MaxValidSpeedoVelocity *= (sint32)Speed_conv_factor_mph;
    MaxValidSpeedoVelocity /= (sint32)Factor_s;
  }

  /*! If the speedometer speed exceeds the allowed borders, then the speedometer speed will be ignored */
  /*! That "safe" speedometer speed is used for acceleration calculation in cruise control case */
  driver_requests->SPEEDOMETER_VEHICLE_SPEED = (speedometer_speed_t)MAT_LIM((sint32)input->SPEEDOMETER_VEHICLE_SPEED, MinValidSpeedoVelocity, MaxValidSpeedoVelocity);
  /*! The speedometer speed offset is still needed for the determing of the set speed */
  /*! The speedometer speed offset is not used for the acceleration calculation in cruise control case */
  driver_requests->SPEEDOMETER_VEHICLE_SPEED_OFFSET = (speedometer_speed_t)((sint32)driver_requests->SPEEDOMETER_VEHICLE_SPEED + AccelerationOffset);
  /*! Value limitation */
  driver_requests->SPEEDOMETER_VEHICLE_SPEED_OFFSET = (speedometer_speed_t)MAT_LIM((sint32)driver_requests->SPEEDOMETER_VEHICLE_SPEED_OFFSET, (sint32)0, (sint32)(driver_requests->MAX_CC_SPEED * (setspeed_t)Speedo_speed_s));
}

#if (FCT_CFG_SLA_FEATURE)
/*************************************************************************************************************************
  Functionname:    KMC_v_DetermineSLASpeed                                                                          */ /*!

  @brief           SLA support function state machine, provides state of SLA speed acceptace: idle, proposed, accepted,
                   applied, declined, aborted and default.

  @description     Saved SLA speeds reset if speedunit changed by driver. Driver SLA setspeed saved based on boolean 
                   (b_SLA_SAVE_DRIVER_SETSPEED) and limited to minimum driver set speed limits (Cc_sla_min_driver_speed_kmh). 
                   State changed from Idle only if a new SLA speed is available. If new speed is acceptable as per customer 
                   requirements, speed data is saved in internal structure. Decision to regulate the saved speed 
                   (SLA_ACCEL_REQUEST_GRANTED calculated in acoor.c) changes SLA state to applied and also resets the state 
                   if FALSE. Saved speed can also be declined or aborted as per requirements, upon which, speed is saved in 
                   internal structure as declined or aborted and corresponding last SLA speed is then saved as current relevant 
                   SLA speed.

@startuml
Start
Partition KMC_v_DetermineSLASpeed(){
: SLA support function state machine, provides state of SLA speed acceptance: idle, proposed, accepted, applied, declined, aborted and default;
if (Speed Unit is changed by Driver) Then (True)
: saved SLA Speeds are reset;
Else (false)
: No Reset of Saved SLA Speed;
: Driver SLA setspeed saved and limited on minimum driver set speed limits;
endif
If (new SLA Speed is available) Then (True)
: SLA Support function changed from Idle State;
Else (false)
: Maintain the current state;
Endif
If (new Speed is accepted as per customer requirements) Then (True)
: speed data is saved in internal structure;
Endif
}
End
@enduml


  @return          -

  @param[in]       sla_input_data : Pointer to input structure for SLA support function [t_SLA_InputData as per cc_ext.h]
                    sla_input_data->SLA_InputStatus.b_SLA_NEW_SPEED_AVAILABLE : boolean indicating if new valid speed limit available [TRUE, FALSE]
                    sla_input_data->SLA_InputStatus.b_SLA_SPEED_ACCEPTED : boolean indicating if the new speed limit was accepted [TRUE, FALSE]
                    sla_input_data->SLA_InputStatus.b_SLA_SPEED_DECLINED : boolean indicating if driver declined the proposed speed limit [TRUE, FALSE]
                    sla_input_data->SLA_InputStatus.b_SLA_SPEED_ABORTED : boolean indicating if a speed limit is aborted [TRUE, FALSE]
                    sla_input_data->SLA_SpeedLimit.u_SpeedLimitDistance : Speed limit distance after wrapper [0u ... 65530u]m (with factor Scale_10)
                    sla_input_data->SLA_SpeedLimit.u_SpeedLimit : Speed limit after wrapper [0u ... 255u]
                    sla_input_data->SLA_SpeedLimit.s_SpeedLimitOffset : Speed limit offset after wrapper [0u ... 255u]
                    sla_input_data->SLA_SpeedLimit.SpeedLimitType : Type of reaction to speed limit [t_SpeedLimitType as per cc_ext.h]

  @param[in]       vehicle_status : Bits for driver assistance system vehicle status [cc_das_vehicle_status_t as per cc_ext.h]
                    vehicle_status.SPEED_UNIT_KMH : boolean indicating the speed unit, i.e. KMH or MPH [TRUE, FALSE]
                    
  @param[in,out]   driver_requests : Pointer to driver request input structure [cc_driver_requests_t as per cc_ext.h]
                    driver_requests->OPERATIONAL_MODE : Display operational mode [full range of datatype display_op_status_t as in Rte_Type.h]
                    driver_requests->DRIVER_OPERATIONS.SWITCH_SPEED_UNIT : Boolean if speed unit is changed by driver [TRUE, FALSE]
                    driver_requests->CC_SETSPEED : Current Cruise Control set speed [0u ... 255u]

  @param[in,out]   cc_sla_hmi_data : Pointer to data struct SLA HMI [t_SLA_HMI_Data as per cc_ext.h]
                    cc_sla_hmi_data->SLA_Event.b_SLA_SAVE_DRIVER_SETSPEED : boolean indicating if the set speed requested by driver shall be saved [TRUE, FALSE]
                    cc_sla_hmi_data->SLA_Event.b_SLA_SET_DRIVER_SETSPEED : boolean indicating, that the saved setspeed requested by driver have to be set [TRUE, FALSE]
                    cc_sla_hmi_data->u_SLA_DriverLastSetSpeed : the saved setspeed requested by driver [0u ... 255u]
                    cc_sla_hmi_data->e_SLA_State : State of SLA state machine [t_e_SLA_State as per cc_ext.h]
                    cc_sla_hmi_data->u_SLA_SpeedLimitActualAccepted.u_SpeedLimit : Accepted speed limit [0u ... 255u]
                    cc_sla_hmi_data->u_SLA_SpeedLimitActualAccepted.u_SpeedLimitDistance : Accepted speed limit distance [0u ... 65530u]m (with factor Scale_10)
                    cc_sla_hmi_data->u_SLA_SpeedLimitActualAccepted.s_SpeedLimitOffset : Accepted speed limit offset [0u ... 255u]
                    cc_sla_hmi_data->u_SLA_SpeedLimitActualAccepted.SpeedLimitType.b_SLA_CONTROL_BEFOR_LIMIT : Type of reaction to speed limit [TRUE, FALSE]
                    cc_sla_hmi_data->u_SLA_SpeedLimitActualAccepted.SpeedLimitType.b_SLA_CONTROL_AFTER_LIMIT : Type of reaction to speed limit [TRUE, FALSE]
                    cc_sla_hmi_data->u_SLA_SpeedLimitLastAccepted : Previous accepted SLA speed limit [0u ... 255u]
                    cc_sla_hmi_data->u_SLA_DriverLastSetSpeed : Previous speed limit set by driver [0u ... 255u]
                    cc_sla_hmi_data->u_SLA_LastSetSpeedForTakeOver : Previous regulated SLA speed limit [0u ... 255u]
                    cc_sla_hmi_data->u_SLA_SpeedLimitLastDeclined : Previous declined speed limit [0u ... 255u]
  @param[in,out]   cc_sla_ctrl_data : Pointer to data struct SLA control [t_SLA_Ctrl_Data as per cc_ext.h]
                    cc_sla_ctrl_data->SLA_CtrlState.SLA_ACCEL_REQUEST_GRANTED : Boolean indicating if SLA acceleration request granted [TRUE, FALSE]

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_SLA_FEATURE : Switch for enabling SLA Support functions
  @c_switch_full   FCT_CFG_LOPC_COMPONENT : Configuration switch for enabling LOPC processing
  @c_switch_full   FCT_CFG_CC : Configuration switch for enabling CC processing

  @pre             -
  @post            -

  @created         08.06.2016
  @changed         08.06.2016

  @author          Simon Sinnstein | simon.sinnstein@continental-corporation.com | +49 (8382) 9699-160
*************************************************************************************************************************/
static void KMC_v_DetermineSLASpeed(const t_SLA_InputData* sla_input_data,
                                   const cc_das_vehicle_status_t vehicle_status,
                                   cc_driver_requests_t* driver_requests,
                                   t_SLA_HMI_Data* cc_sla_hmi_data,
                                   t_SLA_Ctrl_Data* cc_sla_ctrl_data)
{
  /* Reset of SLA velocities if speedunit is changed by driver */
  if(driver_requests->DRIVER_OPERATIONS.SWITCH_SPEED_UNIT == TRUE)
  {
    cc_sla_hmi_data->SLA_SpeedLimitActualAccepted.SpeedLimitType.b_SLA_CONTROL_AFTER_LIMIT = FALSE;
    cc_sla_hmi_data->SLA_SpeedLimitActualAccepted.SpeedLimitType.b_SLA_CONTROL_BEFOR_LIMIT = FALSE;
    cc_sla_hmi_data->SLA_SpeedLimitActualAccepted.u_SpeedLimitIncOffset = 0;
    cc_sla_hmi_data->s_SLA_Offset = 0;
    cc_sla_hmi_data->SLA_SpeedLimitActualAccepted.u_SpeedLimit = 0;
    cc_sla_hmi_data->SLA_SpeedLimitActualAccepted.u_SpeedLimitDistance = 0;
    cc_sla_hmi_data->u_SLA_DriverLastSetSpeed = 0;
    cc_sla_hmi_data->u_SLA_LastSetSpeedForTakeOver = 0;
    cc_sla_hmi_data->u_SLA_SpeedLimitLastAccepted = 0;
    cc_sla_hmi_data->u_SLA_SpeedLimitLastDeclined = 0;
    cc_sla_hmi_data->e_SLA_State = SLA_STATE_IDLE;
  }

  /* Save current setspeed or zone speed for reuse when speed restriction is removed */
  if(cc_sla_hmi_data->SLA_Event.b_SLA_SAVE_DRIVER_SETSPEED == TRUE)
  {
    /* Driver set speed below autobahn minimum speed is not to be accepted */
    if(vehicle_status.SPEED_UNIT_KMH == TRUE)
    {
      cc_sla_hmi_data->u_SLA_DriverLastSetSpeed = (setspeed_t)MAT_MAX((sint32)Cc_sla_min_driver_speed_kmh, (sint32)driver_requests->CC_SETSPEED);
    }
    else
    {
      cc_sla_hmi_data->u_SLA_DriverLastSetSpeed = (setspeed_t)MAT_MAX((sint32)Cc_sla_min_driver_speed_mph, (sint32)driver_requests->CC_SETSPEED);
    }
  }
  else
  {
    if(cc_sla_hmi_data->SLA_Event.b_SLA_DELETE_DRIVER_SETSPEED == TRUE)
    {
      cc_sla_hmi_data->u_SLA_DriverLastSetSpeed = 0u;
    }
    else{/* u_SLA_DriverLastSetSpeed stay saved */}
  }

  /* SLA support function state machine */
  switch(cc_sla_hmi_data->e_SLA_State)
  {
  case SLA_STATE_IDLE:
    if(sla_input_data->SLA_InputStatus.b_SLA_SPEED_DECLINED == TRUE) /*!< Decline logic needed in each state, rework for future */
    {
      cc_sla_hmi_data->e_SLA_State = SLA_STATE_DECLINED;
      if((cc_sla_hmi_data->SLA_SpeedLimitActualAccepted.u_SpeedLimit == sla_input_data->SLA_SpeedLimit.u_SpeedLimit)
         || (cc_sla_hmi_data->SLA_SpeedLimitActualAccepted.u_SpeedLimit == cc_sla_hmi_data->u_SLA_DriverLastSetSpeed)) /* For declining of accepted previous setspeed */
      {/*!< Set last set speed */
        cc_sla_hmi_data->u_SLA_SpeedLimitLastDeclined = cc_sla_hmi_data->SLA_SpeedLimitActualAccepted.u_SpeedLimit;
        cc_sla_hmi_data->SLA_SpeedLimitActualAccepted.u_SpeedLimit = cc_sla_hmi_data->u_SLA_SpeedLimitLastAccepted;
        cc_sla_hmi_data->SLA_SpeedLimitActualAccepted.u_SpeedLimitIncOffset = cc_sla_hmi_data->u_SLA_LastSetSpeedForTakeOver;
        driver_requests->CC_SETSPEED = cc_sla_hmi_data->u_SLA_LastSetSpeedForTakeOver;
        cc_sla_ctrl_data->SLA_CtrlState.SLA_ACCEL_REQUEST_GRANTED = FALSE;
        driver_requests->OPERATIONAL_MODE = Display_op_cc_valid;
      }
      else
      {/*!< Set last declined speed limit */
        cc_sla_hmi_data->u_SLA_SpeedLimitLastDeclined = sla_input_data->SLA_SpeedLimit.u_SpeedLimit;
      }
    }
    else
    {
      if(sla_input_data->SLA_InputStatus.b_SLA_NEW_SPEED_AVAILABLE == TRUE)
      {
        cc_sla_hmi_data->e_SLA_State = SLA_STATE_PROPOSED;
      }
      else
      { /*!< Reset the last declined speed limit */
        if(cc_sla_hmi_data->u_SLA_SpeedLimitLastDeclined != sla_input_data->SLA_SpeedLimit.u_SpeedLimit)
        {
          cc_sla_hmi_data->u_SLA_SpeedLimitLastDeclined = 0;
        }
        /*! if new SLA speed limit is equal to the setspeed, update accepted speed limit */
        if(sla_input_data->SLA_SpeedLimit.u_SpeedLimitIncOffset == driver_requests->CC_SETSPEED)
        {
          cc_sla_hmi_data->SLA_SpeedLimitActualAccepted.u_SpeedLimit = sla_input_data->SLA_SpeedLimit.u_SpeedLimit;
          cc_sla_hmi_data->SLA_SpeedLimitActualAccepted.u_SpeedLimitIncOffset = sla_input_data->SLA_SpeedLimit.u_SpeedLimitIncOffset;
        }
        else /*! If new SLA speed is not equal to the setspeed, but the driver speed was set, update accepted speed limit */
        {
          if(cc_sla_hmi_data->SLA_Event.b_SLA_SET_DRIVER_SETSPEED == TRUE)
          {
            cc_sla_hmi_data->SLA_SpeedLimitActualAccepted.u_SpeedLimitIncOffset = cc_sla_hmi_data->u_SLA_DriverLastSetSpeed;
          }
          else{/* do nothing */}
        }
      }
    }
    break;
  case SLA_STATE_PROPOSED:
    if(sla_input_data->SLA_InputStatus.b_SLA_NEW_SPEED_AVAILABLE == TRUE)
    {
      if(sla_input_data->SLA_InputStatus.b_SLA_SPEED_ACCEPTED == TRUE)
      {
        if(cc_sla_hmi_data->SLA_SpeedLimitActualAccepted.u_SpeedLimit != sla_input_data->SLA_SpeedLimit.u_SpeedLimit)
        { /* Last speed accepted not overwritten when new input speed is same as already accepted speed. 
              This means only offset has been changed */
          cc_sla_hmi_data->u_SLA_SpeedLimitLastAccepted = cc_sla_hmi_data->SLA_SpeedLimitActualAccepted.u_SpeedLimit;
        }
        cc_sla_hmi_data->SLA_SpeedLimitActualAccepted.u_SpeedLimitDistance = sla_input_data->SLA_SpeedLimit.u_SpeedLimitDistance;
        cc_sla_hmi_data->SLA_SpeedLimitActualAccepted.SpeedLimitType = sla_input_data->SLA_SpeedLimit.SpeedLimitType;
        cc_sla_hmi_data->u_SLA_SpeedLimitLastDeclined = 0;
        if(cc_sla_hmi_data->SLA_Event.b_SLA_SET_DRIVER_SETSPEED == TRUE)
        {
          cc_sla_hmi_data->SLA_SpeedLimitActualAccepted.u_SpeedLimitIncOffset = cc_sla_hmi_data->u_SLA_DriverLastSetSpeed;
          cc_sla_hmi_data->SLA_SpeedLimitActualAccepted.u_SpeedLimit = SLA_UNRESTRICTED_SPEED;
        }
        else
        { /* Road traffic sign is accepted as SLA control speed */
          cc_sla_hmi_data->SLA_SpeedLimitActualAccepted.u_SpeedLimit = sla_input_data->SLA_SpeedLimit.u_SpeedLimit;
          cc_sla_hmi_data->SLA_SpeedLimitActualAccepted.u_SpeedLimitIncOffset = sla_input_data->SLA_SpeedLimit.u_SpeedLimitIncOffset;
        }
        /* Set SLA state ACCEPTED */
        cc_sla_hmi_data->e_SLA_State = SLA_STATE_ACCEPTED;
      }
      else
        if(sla_input_data->SLA_InputStatus.b_SLA_SPEED_DECLINED == TRUE)
        {
          cc_sla_hmi_data->e_SLA_State = SLA_STATE_DECLINED;
          cc_sla_hmi_data->u_SLA_SpeedLimitLastDeclined = sla_input_data->SLA_SpeedLimit.u_SpeedLimit;
        }
        else
        { /*!< Reset the last declined speed limit */
          if(cc_sla_hmi_data->u_SLA_SpeedLimitLastDeclined != sla_input_data->SLA_SpeedLimit.u_SpeedLimit)
          {
            cc_sla_hmi_data->u_SLA_SpeedLimitLastDeclined = 0;
          }
        }
    }
    else
    {
      cc_sla_hmi_data->e_SLA_State = SLA_STATE_IDLE;
    }
    break;
  case SLA_STATE_ACCEPTED:
    if(cc_sla_ctrl_data->SLA_CtrlState.SLA_ACCEL_REQUEST_GRANTED == TRUE)
    {
      cc_sla_hmi_data->SLA_SpeedLimitActualAccepted.u_SpeedLimitDistance = sla_input_data->SLA_SpeedLimit.u_SpeedLimitDistance;
      cc_sla_hmi_data->e_SLA_State = SLA_STATE_APPLIED;
    }
    else
    {
      if(sla_input_data->SLA_InputStatus.b_SLA_SPEED_DECLINED == TRUE)
      {
        cc_sla_hmi_data->e_SLA_State = SLA_STATE_DECLINED;
        if(cc_sla_hmi_data->SLA_SpeedLimitActualAccepted.u_SpeedLimit == sla_input_data->SLA_SpeedLimit.u_SpeedLimit)
        {
          cc_sla_hmi_data->u_SLA_SpeedLimitLastDeclined = cc_sla_hmi_data->SLA_SpeedLimitActualAccepted.u_SpeedLimit;
          cc_sla_hmi_data->SLA_SpeedLimitActualAccepted.u_SpeedLimit = cc_sla_hmi_data->u_SLA_SpeedLimitLastAccepted;
          cc_sla_hmi_data->SLA_SpeedLimitActualAccepted.u_SpeedLimitIncOffset = cc_sla_hmi_data->u_SLA_LastSetSpeedForTakeOver;
        }
        else
        {
          cc_sla_hmi_data->u_SLA_SpeedLimitLastDeclined = sla_input_data->SLA_SpeedLimit.u_SpeedLimit;
        }
      }
      else
        if((sla_input_data->SLA_InputStatus.b_SLA_NEW_SPEED_AVAILABLE == TRUE)
          &&(cc_sla_hmi_data->SLA_SpeedLimitActualAccepted.u_SpeedLimit != sla_input_data->SLA_SpeedLimit.u_SpeedLimit))
        {
          /* speed limit was not applied */
          cc_sla_hmi_data->SLA_SpeedLimitActualAccepted.u_SpeedLimit = cc_sla_hmi_data->u_SLA_SpeedLimitLastAccepted;
          cc_sla_hmi_data->e_SLA_State = SLA_STATE_PROPOSED;
        }
        else
          /* If speed limit accepted and wait for applying */
          /* If speed limit not valid == 0, abort accepted speed limit */
          if(sla_input_data->SLA_InputStatus.b_SLA_SPEED_ABORTED == TRUE)
          {
            cc_sla_hmi_data->SLA_SpeedLimitActualAccepted.u_SpeedLimit = cc_sla_hmi_data->u_SLA_SpeedLimitLastAccepted;
            cc_sla_hmi_data->e_SLA_State = SLA_STATE_ABORTED;
          }
          else
          {
            cc_sla_hmi_data->SLA_SpeedLimitActualAccepted.u_SpeedLimitDistance = sla_input_data->SLA_SpeedLimit.u_SpeedLimitDistance;
          }
    }
    break;
  case SLA_STATE_APPLIED:
    if(cc_sla_ctrl_data->SLA_CtrlState.SLA_ACCEL_REQUEST_GRANTED == FALSE)
    {
      if(sla_input_data->SLA_InputStatus.b_SLA_NEW_SPEED_AVAILABLE == TRUE)
      {
        cc_sla_hmi_data->e_SLA_State = SLA_STATE_PROPOSED;
      }
      else
      {
        cc_sla_hmi_data->e_SLA_State = SLA_STATE_IDLE;
      }
    }
    else
      if(sla_input_data->SLA_InputStatus.b_SLA_SPEED_DECLINED == TRUE)
      {
        cc_sla_hmi_data->e_SLA_State = SLA_STATE_DECLINED;
        if(cc_sla_hmi_data->SLA_SpeedLimitActualAccepted.u_SpeedLimit == sla_input_data->SLA_SpeedLimit.u_SpeedLimit)
        {
          cc_sla_hmi_data->u_SLA_SpeedLimitLastDeclined = cc_sla_hmi_data->SLA_SpeedLimitActualAccepted.u_SpeedLimit;
          cc_sla_hmi_data->SLA_SpeedLimitActualAccepted.u_SpeedLimit = cc_sla_hmi_data->u_SLA_SpeedLimitLastAccepted;
          cc_sla_hmi_data->SLA_SpeedLimitActualAccepted.u_SpeedLimitIncOffset = cc_sla_hmi_data->u_SLA_LastSetSpeedForTakeOver;
          driver_requests->CC_SETSPEED = cc_sla_hmi_data->u_SLA_LastSetSpeedForTakeOver;
          cc_sla_ctrl_data->SLA_CtrlState.SLA_ACCEL_REQUEST_GRANTED = FALSE;
          driver_requests->OPERATIONAL_MODE = Display_op_cc_valid;
        }
        else
        {
          cc_sla_hmi_data->u_SLA_SpeedLimitLastDeclined = sla_input_data->SLA_SpeedLimit.u_SpeedLimit;
        }
      }
      else
        if(sla_input_data->SLA_InputStatus.b_SLA_NEW_SPEED_AVAILABLE == FALSE)
        {
          /* If during speed limit is applying */
          /* If speed limit not valid == 0, abort accepted speed limit */
          if(sla_input_data->SLA_InputStatus.b_SLA_SPEED_ABORTED == TRUE)
          {
            cc_sla_hmi_data->SLA_SpeedLimitActualAccepted.u_SpeedLimit = cc_sla_hmi_data->u_SLA_SpeedLimitLastAccepted;
            cc_sla_hmi_data->SLA_SpeedLimitActualAccepted.u_SpeedLimitIncOffset = cc_sla_hmi_data->u_SLA_LastSetSpeedForTakeOver;
            driver_requests->CC_SETSPEED = cc_sla_hmi_data->u_SLA_LastSetSpeedForTakeOver;
            cc_sla_ctrl_data->SLA_CtrlState.SLA_ACCEL_REQUEST_GRANTED = FALSE;
            driver_requests->OPERATIONAL_MODE = Display_op_cc_valid;
            cc_sla_hmi_data->e_SLA_State = SLA_STATE_ABORTED;
          }
          cc_sla_hmi_data->SLA_SpeedLimitActualAccepted.u_SpeedLimitDistance = sla_input_data->SLA_SpeedLimit.u_SpeedLimitDistance;
        }
        else{/* do nothing, the case will be checkt in CC_DETERMINE_SLA_ACCEL function  */}
    break;
  case SLA_STATE_DECLINED:
    cc_sla_hmi_data->e_SLA_State = SLA_STATE_IDLE;
    break;
  case SLA_STATE_ABORTED:
    cc_sla_hmi_data->e_SLA_State = SLA_STATE_IDLE;
    break;
  default:
    cc_sla_hmi_data->e_SLA_State = SLA_STATE_IDLE;
    break;
  }
}/* PRQA S 7004 */
/* date: 2018-03-26, reviewer: Ravi Kiran Gurrala, reason : Cyclomatic complexity. Not Safety critical*/
#endif /* (FCT_CFG_SLA_FEATURE) */

/*************************************************************************************************************************
  Functionname:    KMC_v_DetermineControlstateSetspeed                                                              */ /*!

  @brief           Call all functions concerning the interpretation of
                   driver_controls

  @description     Call all functions concerning the interpretation of
                   driver_controls
                   - KMC_v_DetermineSpeedLimits
                   - KMC_v_DetermineEngagementConditions
                   - KMC_v_DetermineControlState
                   - KMC_v_DetermineSetSpeed
                   - KMC_v_DetermineSLASpeed

    @startuml
    Start
    Partition KMC_v_DetermineControlstateSetspeed {
      : KMC_v_DetermineSpeedLimits;
      : KMC_v_DetermineEngagementConditions;
      : KMC_v_DetermineControlState;
      : KMC_v_DetermineSetSpeed;
      : KMC_v_DetermineSLASpeed;
    }
    End
    @enduml

  @return          -

  @param[in]       cycle_time : cycle time of FCT_VEH cycle [0u ... 1000u] ms
  @param[in]       das_input : Pointer to input from longitudinal dynamics management to driver assistance system [cart_das_input_data_t as per cart_ext.h]
                    LODM_STAT : Longitudinal dynamics management status bits [cart_lodm_status_t as per cart_ext.h]
  @param[in]       driver_controls : Pointer to Selected CC function by driver [cc_driver_controls_t as per cc_ext.h]
  @param[in]       input : Pointer to cc_input_data_t type structure containing input data to CC [cc_input_data_t as per cc_ext.h]
                    SLA_INPUT_DATA : Input structure for SLA function [t_SLA_InputData as per cc_ext.h]
                    VEHICLE_STATUS : Bits for driver assistance system vehicle status [cc_das_vehicle_status_t as per cc_ext.h]
                    VEHICLE_STATUS.SPEED_UNIT_KMH : Boolean if speed unit is kmh [TRUE, FALSE] (TRUE: kmh, FALSE: mph)
  @param[in,out]   error_data : Information about CC and CC Limiter error state [cc_error_data_t as per cc_ext.h]
  @param[in,out]   das_output : Pointer to output data from driver assistance system to longitudinal dynamics management [cart_das_output_data_t as per cart_ext.h]
  @param[in,out]   cc_status : Pointer to Cruisecontrol status [cc_status_t as per cc_ext.h]
                    CC_DRIVER_REQUESTS : Pointer to driver request input structure [cc_driver_requests_t as per cc_ext.h]
                    CC_ACCEL_CONTROL_DATA : Pointer to CC acceleration control data [cc_acceleration_control_data_t as per cc_ext.h]
                    CC_SLA_HMI_DATA : Pointer to data struct SLA HMI [t_SLA_HMI_Data as per cc_ext.h]
                    CC_CONTROL_DATA.CC_SLA_CTRL_DATA : Pointer to data struct SLA control [t_SLA_Ctrl_Data as per cc_ext.h]
                    LODM_STAT_LAST_CYCLE : Longitudinal dynamics management status bits as per last cycle [cart_lodm_status_t as per cart_ext.h]
                    CC_SPEED_UNIT_LAST_CYCLE : Boolean indicating CC speed unit of last cycle [TRUE, FALSE]
  @param[in]       acc_output : Output data structure from ACC passed through to reference function [acc_output_data_t as per Rte_type.h]

  @glob_in         - 
  @glob_out        - 

  @c_switch_part   LONG_CFG_USE_EXTERN_ACC_STATE_MACHINE : Configuration switch to use external ACC state machine
  @c_switch_part   FCT_CFG_SLA_FEATURE : Switch for enabling SLA Support functions
  @c_switch_full   FCT_CFG_LOPC_COMPONENT : Configuration switch for enabling LOPC processing
  @c_switch_full   FCT_CFG_CC : Configuration switch for enabling CC processing

  @traceability    doors://rbgs854a:40000/?version=2&prodID=0&view=00000002&urn=urn:telelogic::1-503e822e5ec3651e-O-148-0008a220
*************************************************************************************************************************/
void KMC_v_DetermineControlstateSetspeed(const times_t cycle_time, 
                                        const cart_das_input_data_t* das_input, 
                                        const cc_driver_controls_t* driver_controls, 
                                        const cc_input_data_t* input, 
                                        cc_error_data_t* error_data, 
                                        cart_das_output_data_t* das_output, 
                                        cc_status_t *cc_status, 
                                        const acc_output_data_t* acc_output)
{

  KMC_v_DetermineSpeedLimits(&cc_status->CC_ACCEL_CONTROL_DATA, das_input, input, &cc_status->CC_DRIVER_REQUESTS);

  KMC_v_DetermineEngagementConditions(cycle_time, das_input, input, &cc_status->CC_ACCEL_CONTROL_DATA, &cc_status->CC_DRIVER_REQUESTS, cc_status, driver_controls, acc_output);

  KMC_v_DetermineControlState(driver_controls, &cc_status->CC_ACCEL_CONTROL_DATA, das_input, error_data, &cc_status->CC_DRIVER_REQUESTS, das_output, input);

#if (!LONG_CFG_USE_EXTERN_ACC_STATE_MACHINE)
  KMC_v_DetermineSetSpeed(input, error_data, &cc_status->CC_DRIVER_REQUESTS);
 
#if (FCT_CFG_SLA_FEATURE)
  KMC_v_DetermineSLASpeed(&input->SLA_INPUT_DATA, input->VEHICLE_STATUS,&cc_status->CC_DRIVER_REQUESTS,&cc_status->CC_SLA_HMI_DATA,&cc_status->CC_CONTROL_DATA.CC_SLA_CTRL_DATA);
#endif
#endif

  cc_status->LODM_STAT_LAST_CYCLE = das_input->LODM_STAT;
  cc_status->CC_SPEED_UNIT_LAST_CYCLE = (uint8)input->VEHICLE_STATUS.SPEED_UNIT_KMH;
}

#endif

/** @} end defgroup */
/* date: 2019-02-08, reviewer: Niraj Mistry, reason: Number of lines exceeded per file, not safety critical */
// PRQA S 7013