/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC/LOPC/KMC (Adaptive Cruise Control - Longitudinal Planner and Controller - Kinematic Motion Control)

PACKAGENAME:               kmc_acoor.c

DESCRIPTION:               This file contains functions concerning coordination of commanded acceleration from KMC

AUTHOR:                    Mistry Niraj (uidq5738)

CREATION DATE:             24.02.2017

VERSION:                   $Revision: 1.29 $

LEGACY VERSION:            Revision: 1.57.1.3

**************************************************************************** */

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/** 
@defgroup   kmc_acoor Kmc_acoor
@ingroup    kmc
@brief      KMC acceleration coordination functions
@{ */ 

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "kmc.h"

#if ((FCT_CFG_LOPC_COMPONENT) && (FCT_CFG_CC) && (LOPC_CFG_KMC))

#if CFG_FCT_CC_USE_BRAKES_FOR_LAT_LIM 
#if !(CFG_FCT_CC_USE_BRAKE)
#error "CFG_FCT_CC_USE_BRAKES_FOR_LAT_LIM requires CFG_FCT_CC_USE_BRAKE!"
#endif
#endif

#if CFG_FCT_CC_USE_BRAKES_FOR_LAT_LIM 
#if !(CFG_FCT_CC_USE_LAT_LIM)
#error "CFG_FCT_CC_USE_BRAKES_FOR_LAT_LIM requires CFG_FCT_CC_USE_LAT_LIM!"
#endif
#endif

#if ((!CFG_FCT_LIM) && (CFG_FCT_FLIM))
#error "CFG_FCT_FLIM requires CFG_FCT_LIM"
#endif

#if (FCT_CFG_FSRACC && !FCT_CFG_ACC_HEADWAY_PLANNER)
#error "FCT_CFG_FSRACC needs FCT_CFG_ACC_HEADWAY_PLANNER"
#endif

/*****************************************************************************
  MODULE LOCAL CONSTANTS
*****************************************************************************/
#define ACCEPTABLE_TIME 250
#define ACCELERATION_FOR_MAXIMUM_GRAD (-3500)
#define MAX_ACCEL_DELTA 1500
#define HIGH_GRAD_CRITICALITY_THRES 4

#if (CFG_FCT_CC_USE_CONTROL_CRITICALITY)
#define MINIMUM_FILTER_CONST 30
#endif
#if (CFG_FCT_CC_USE_ACCEL_BAND_MODIFICATION)
#define minallowedband 25
#endif
#define MAX_VALID_SPEED_FOR_DETECTION (velocity_t)1600 /* 16 m/s */
#define TIME_OF_TRANSITION            (times_t)3000

/*****************************************************************************
  MODULE GLOBAL VARIABLES
*****************************************************************************/
#if (KMC_NO_SMOOTH_JERK_IN_LOW_SPEED)
static boolean b_DetectStrongBrakeRelease = FALSE;  /* Detection of fast strong brake release from large deceleration value */
#endif

/*****************************************************************************
  MODULE LOCAL FUNCTIONS
*****************************************************************************/

static void KMC_v_InitAccelRequest(const cc_driver_requests_t* driver_requests, cc_control_data_t* cc_control_data, cc_acceleration_control_data_t* accel_control_data,const cart_das_input_data_t* das_input);
#if (CFG_FCT_LIM || CFG_FCT_PLIM)
static void KMC_v_DetermineLimiterAccel(const cc_input_data_t* input, const cc_driver_requests_t* driver_requests, cc_control_data_t* cc_control_data);
#endif
static void KMC_v_CoordinateAccel(const cc_driver_requests_t* driver_requests, const acc_output_data_t* acc_output, cc_control_data_t* cc_control_data, cc_acceleration_control_data_t* accel_control_data, const cart_das_input_data_t* das_input);
static void KMC_v_LimitAccelChangeRate(const times_t cycle_time, const cc_driver_requests_t* driver_requests, cc_control_data_t* cc_control_data, cc_acceleration_control_data_t* accel_control_data, const cart_das_input_data_t* das_input, cart_das_output_data_t* das_output, const cc_input_data_t* input, const acc_output_data_t* acc_output);
static void KMC_v_LimitDecel(cc_status_t *cc_status);
static void KMC_v_DetermineCCAccel(const cc_input_data_t* input, const cart_das_input_data_t* das_input, const cc_driver_requests_t* driver_requests, cc_control_data_t* cc_control_data);
#if (FCT_CFG_SLA_FEATURE)
static void KMC_v_DetermineSLAAccel(const cc_input_data_t* input, const cart_das_input_data_t* das_input,
                                    cc_driver_requests_t* driver_requests,
                                    t_SLA_HMI_Data* cc_sla_hmi_data, t_SLA_Ctrl_Data* cc_sla_ctrl_data);
static void KMC_v_ArbitrateCruiseAccel(cc_control_data_t* cc_control_data);
#endif
#if (CFG_FCT_CC_USE_ACCEL_BAND_MODIFICATION)
static void KMC_v_DetermineAccelBand(const times_t cycle_time, cc_control_data_t* cc_control_data, cc_acceleration_control_data_t *accel_control_data, velocity_t vown);
#endif
static void KMC_v_Coordinator(const times_t cycle_time, const acc_output_data_t* acc_output, const cart_das_input_data_t* das_input, cart_das_output_data_t* das_output, cc_status_t *cc_status, const cc_input_data_t* input);
#if (FCT_CFG_FSRACC)
static void KMC_v_CoordinateStandstill(const acc_output_data_t* acc_output, const cart_das_input_data_t* das_input, cart_das_output_data_t* das_output, cc_status_t *cc_status);
#endif
#if (CFG_FCT_CC_SMOOTH_ACCEL_REQUEST)
static void KMC_v_AccelRequestFiltering(const times_t cycle_time, cc_acceleration_control_data_t *accel_control_data, const cc_driver_requests_t* driver_requests, const acc_output_data_t* acc_output, const cart_das_input_data_t* das_input, cc_control_data_t* cc_control_data);
#endif
static void KMC_v_SetAccelRequest(const times_t cycle_time, cc_acceleration_control_data_t *accel_control_data, cart_das_output_data_t* das_output, const cc_driver_requests_t* driver_requests);
static void KMC_v_DetectTransitionACCtoCC(const times_t cycle_time, const cart_das_input_data_t* das_input, cc_status_t *cc_status);



/*************************************************************************************************************************
  Functionname:    KMC_v_InitAccelRequest                                                                           */ /*!

  @brief           Initialize accel request

  @description     Initialize acceleration request at engagement or after driver
                   override with the INIT_ACCELERATION. When the CC is engaged
                   in a highly dynamic situation, the so called initialization
                   phase is started. In this phase, higher gradients of the 
                   acceleration request are allowed, to prevent acceleration or deceleration
                   overshoot. It is marked with INIT_PHASE_ACTIVE.
    @startuml
    Start
    Partition KMC_v_InitAccelRequest {
    note right
    MaxCA = MAXIMUM_COMMANDED_ACCELERATION 
    MinCA = MINIMUM_COMMANDED_ACCELERATION 
    MaxRA = MAXIMUM_REQUESTED_ACCELERATION 
    MinRA = MINIMUM_REQUESTED_ACCELERATION 
    endnote
      If (Transition Engage-->Active) then (yes)
        : Last Cycle MinRA/MaxRA \n initialised to A_INIT;
        : Last Cycle MinRA/MaxRA \n limited to allowed accelerations;
      Elseif (Limiter after override is inactive \n AND \nLateral accel limiter is inactive\n AND \nState is active/disengaged/override\n AND \nALLOW_INIT == TRUE) then (yes)
        If (A_INIT has a value between \nMinCA and lastcycle MinRA) then (yes)
          : Lastcycle MinRA = A_INIT;
        Else (no)
        Endif
        If (A_INIT has a value between \nMaxCA and lastcycle MaxRA) then (yes)
        : Lastcycle MaxRA = A_INIT;
        Else (no)
        Endif
      Else (no)
      Endif
      If (Standstill and Driveoff_confirm becomes true) then (yes)
      : Lastcycle MaxRA/MinRA \ninitialised to MaxCA/MinCA;
      note right
      This ensures that no jerk limitation is applicable 
      and acceleration can be increased with a jump
      endnote
      Else (no)
      Endif
    }
    End
    @enduml
  @return          -

  @param[in]       driver_requests : Pointer to driver request input structure [cc_driver_requests_t as per cc_ext.h]
                    CONTROL_STATE : Variable that reflects the state of the HMI state machine [full range of datatype cc_control_state_t as in cc_ext.h]
                    CONTROL_STATE_LAST_CYCLE : Variable that reflects the state of the HMI state machine as per last cycle [full range of datatype cc_control_state_t as in cc_ext.h]
                    DRIVER_OPERATIONS.DRIVE_OFF_CONFIRM : Boolean confirming drive off request from driver [True, False]
                    DRIVER_OPERATIONS_LAST_CYCLE.DRIVE_OFF_CONFIRM : Boolean confirming drive off request from driver as per last cycle [True, False]

  @param[in,out]   cc_control_data : Pointer to CC control data [cc_control_data_t as per cc_ext.h]
                    cc_control_data->DECEL_LIM_OVERRIDE_ACTIVE: Boolean indicating if deceleration is limited after override [True, False]
  @param[in,out]   accel_control_data : Pointer to CC acceleration control data [cc_acceleration_control_data_t as per cc_ext.h]
                    MINIMUM_REQUESTED_ACCELERATION_LAST_CYCLE : Minimum requested acceleration as per last cycle [-30000u ...+30000u] m/s2 (with factor Acceleration_s)
                    MAXIMUM_REQUESTED_ACCELERATION_LAST_CYCLE : Maximum requested acceleration as per last cycle [-30000u ...+30000u] m/s2 (with factor Acceleration_s)
                    MAXIMUM_COMMANDED_ACCELERATION : Maximum commanded acceleration [-30000u ...+30000u] m/s2 (with factor Acceleration_s)
                    MINIMUM_COMMANDED_ACCELERATION : Minimum commanded acceleration [-30000u ...+30000u] m/s2 (with factor Acceleration_s)
                    MIN_ALLOWED_ACCEL : Minimum allowed acceleration for control object [-30000u ...+30000u] m/s2 (with factor Acceleration_s)
                    MAX_ALLOWED_ACCEL : Maximum allowed acceleration for control object [-30000u ...+30000u] m/s2 (with factor Acceleration_s)
                    ACCEL_STATUS.LAT_ACCEL_LIM_ACTIVE : Boolean indicating whether limiter due to lateral acceleration is active [True, False]
                    ACCEL_STATUS.ALLOW_INIT : Indicates the possibility, to initialize the control acceleration to the current ego vehicle acceleration [TRUE,FALSE]
  @param[in]       das_input : Pointer to input from longitudinal dynamics management to driver assistance system [cart_das_input_data_t as per cart_ext.h]
                    A_INIT : Vehicle initialisation acceleration [-30000u ...+30000u] m/s2 (with factor Acceleration_s)

  @glob_in         -
  @glob_out        -

  @c_switch_part   CFG_FCT_CC_ALLOW_INIT_ACCEL_REQUEST : Configuration switch for init request acceleration to host vehicle acceleration
  @c_switch_part   CFG_FCT_CC_USE_ACCEL_BAND_MODIFICATION : Configuration switch to use modification of acceleration band
  @c_switch_part   LONG_CFG_USE_EXTERN_ACC_STATE_MACHINE : Configuration switch to use external ACC state machine

  @c_switch_full   FCT_CFG_LOPC_COMPONENT : Configuration switch for enabling LOPC processing
  @c_switch_full   FCT_CFG_CC : Configuration switch for enabling CC processing


*************************************************************************************************************************/
static void KMC_v_InitAccelRequest(const cc_driver_requests_t* driver_requests, cc_control_data_t* cc_control_data, 
                                  cc_acceleration_control_data_t* accel_control_data,const cart_das_input_data_t* das_input)
{

  /* Newly Engaged... */
  if (
      (driver_requests->CONTROL_STATE_LAST_CYCLE != driver_requests->CONTROL_STATE)
      &&
      (driver_requests->CONTROL_STATE_LAST_CYCLE != Cc_cc_override)
      &&
      (
       (driver_requests->CONTROL_STATE == Cc_plim_active)
       ||
       (driver_requests->CONTROL_STATE == Cc_lim_active)
       ||
       (driver_requests->CONTROL_STATE == Cc_cc_active)
      )
     )
  {
#if (CFG_FCT_CC_ALLOW_INIT_ACCEL_REQUEST)
    /* Initialize CommandedAcceleration of last Cycle */
    if (driver_requests->CONTROL_STATE == Cc_plim_active)
    {
      accel_control_data->MINIMUM_REQUESTED_ACCELERATION_LAST_CYCLE = das_input->A_INIT;
      accel_control_data->MAXIMUM_REQUESTED_ACCELERATION_LAST_CYCLE = accel_control_data->MINIMUM_REQUESTED_ACCELERATION_LAST_CYCLE;
    }
    else
    {
      if (driver_requests->CONTROL_STATE == Cc_lim_active)
      {
        accel_control_data->MINIMUM_REQUESTED_ACCELERATION_LAST_CYCLE = das_input->A_INIT;
        accel_control_data->MAXIMUM_REQUESTED_ACCELERATION_LAST_CYCLE = accel_control_data->MINIMUM_REQUESTED_ACCELERATION_LAST_CYCLE;
      }
      else
      {
        /* cc_active */
#if (CFG_FCT_CC_USE_ACCEL_BAND_MODIFICATION)
        /* Initialize acceleration request with accel band spreading */
        if(das_input->A_INIT < accel_control_data->MAXIMUM_COMMANDED_ACCELERATION)
        {
          accel_control_data->MAXIMUM_REQUESTED_ACCELERATION_LAST_CYCLE = accel_control_data->MAXIMUM_COMMANDED_ACCELERATION;
          accel_control_data->MINIMUM_REQUESTED_ACCELERATION_LAST_CYCLE = (acceleration_t)MAT_LIM((sint32)das_input->A_INIT, (sint32)accel_control_data->MIN_ALLOWED_ACCEL, (sint32)accel_control_data->MAX_ALLOWED_ACCEL);
        }
        else
        {
          accel_control_data->MAXIMUM_REQUESTED_ACCELERATION_LAST_CYCLE = (acceleration_t)MAT_LIM((sint32)das_input->A_INIT, (sint32)accel_control_data->MIN_ALLOWED_ACCEL, (sint32)accel_control_data->MAX_ALLOWED_ACCEL);
          accel_control_data->MINIMUM_REQUESTED_ACCELERATION_LAST_CYCLE = accel_control_data->MINIMUM_COMMANDED_ACCELERATION;
        }
#else
        /* Initialize acceleration request without accel band => jump to das_input->A_INIT */
        accel_control_data->MINIMUM_REQUESTED_ACCELERATION_LAST_CYCLE = (acceleration_t)MAT_LIM((sint32)das_input->A_INIT, (sint32)accel_control_data->MIN_ALLOWED_ACCEL, (sint32)accel_control_data->MAX_ALLOWED_ACCEL);
        accel_control_data->MAXIMUM_REQUESTED_ACCELERATION_LAST_CYCLE = (acceleration_t)MAT_LIM((sint32)das_input->A_INIT, (sint32)accel_control_data->MIN_ALLOWED_ACCEL, (sint32)accel_control_data->MAX_ALLOWED_ACCEL);
#endif
      }
    }
#else
        accel_control_data->MINIMUM_REQUESTED_ACCELERATION_LAST_CYCLE = accel_control_data->MINIMUM_COMMANDED_ACCELERATION;
        accel_control_data->MAXIMUM_REQUESTED_ACCELERATION_LAST_CYCLE = accel_control_data->MAXIMUM_COMMANDED_ACCELERATION;
#endif
  }
#if (CFG_FCT_CC_ALLOW_INIT_ACCEL_REQUEST)
  else
  {
    /*init accel request if actual accel is in between commanded accel and last requested accel*/
    if (
        (cc_control_data->DECEL_LIM_OVERRIDE_ACTIVE == FALSE)
        &&
        (accel_control_data->ACCEL_STATUS.LAT_ACCEL_LIM_ACTIVE == FALSE)
        &&
        (
         (driver_requests->CONTROL_STATE == Cc_cc_active)
         ||
         (driver_requests->CONTROL_STATE == Cc_cc_disengage)
         ||
         (driver_requests->CONTROL_STATE == Cc_cc_override)
        )
        &&
        (accel_control_data->ACCEL_STATUS.ALLOW_INIT == TRUE)
       )
    {
      if (das_input->A_INIT == (acceleration_t)MAT_LIM((sint32)das_input->A_INIT, (sint32)accel_control_data->MAXIMUM_COMMANDED_ACCELERATION, (sint32)accel_control_data->MAXIMUM_REQUESTED_ACCELERATION_LAST_CYCLE))
      {
        accel_control_data->MAXIMUM_REQUESTED_ACCELERATION_LAST_CYCLE = das_input->A_INIT;
      }
      if (das_input->A_INIT == (acceleration_t)MAT_LIM((sint32)das_input->A_INIT, (sint32)accel_control_data->MINIMUM_COMMANDED_ACCELERATION, (sint32)accel_control_data->MINIMUM_REQUESTED_ACCELERATION_LAST_CYCLE))
      {
        accel_control_data->MINIMUM_REQUESTED_ACCELERATION_LAST_CYCLE = das_input->A_INIT;
      }
    }
  }
#else
  _PARAM_UNUSED(cc_control_data);
  _PARAM_UNUSED(das_input);
#endif

#if (LONG_CFG_USE_EXTERN_ACC_STATE_MACHINE)
  /* ACC activation during driver accelerating (control state changes from disengage to override) */
  if (
      (driver_requests->CONTROL_STATE_LAST_CYCLE != driver_requests->CONTROL_STATE)
      &&
      (driver_requests->CONTROL_STATE_LAST_CYCLE != Cc_cc_active)
      &&
      (driver_requests->CONTROL_STATE == Cc_cc_override)
     )
  {
    /* Set acceleration request to commanded acceleration within specific limits */
    accel_control_data->MINIMUM_REQUESTED_ACCELERATION_LAST_CYCLE = (acceleration_t)MAT_LIM((sint32)accel_control_data->MINIMUM_COMMANDED_ACCELERATION, (sint32)Cc_max_decel_during_override, MAT_MIN((sint32)das_input->A_INIT, (sint32)accel_control_data->MAX_ALLOWED_ACCEL));
    accel_control_data->MAXIMUM_REQUESTED_ACCELERATION_LAST_CYCLE = (acceleration_t)MAT_LIM((sint32)accel_control_data->MAXIMUM_COMMANDED_ACCELERATION, (sint32)Cc_max_decel_during_override, MAT_MIN((sint32)das_input->A_INIT, (sint32)accel_control_data->MAX_ALLOWED_ACCEL));

  }
#endif

  /*init accel request after standstill and driver input*/
  if (
      (driver_requests->DRIVER_OPERATIONS.DRIVE_OFF_CONFIRM == TRUE) 
#if (!CFG_FCT_INIT_ACCEL_AFTER_STANDSTILL)
      &&
      (driver_requests->DRIVER_OPERATIONS_LAST_CYCLE.DRIVE_OFF_CONFIRM == FALSE)
#endif
     )
  {
    accel_control_data->MAXIMUM_REQUESTED_ACCELERATION_LAST_CYCLE = accel_control_data->MAXIMUM_COMMANDED_ACCELERATION;
    accel_control_data->MINIMUM_REQUESTED_ACCELERATION_LAST_CYCLE = accel_control_data->MAXIMUM_COMMANDED_ACCELERATION;
  }
  accel_control_data->MINIMUM_REQUESTED_ACCELERATION_LAST_CYCLE = (acceleration_t)MAT_MIN((sint32)accel_control_data->MINIMUM_REQUESTED_ACCELERATION_LAST_CYCLE, (sint32)accel_control_data->MAXIMUM_REQUESTED_ACCELERATION_LAST_CYCLE);

}


/*************************************************************************************************************************
  Functionname:    KMC_v_LimitAccelChangeRate                                                                       */ /*!

  @brief           This function limits the gradient in the requested acceleration
                   to increase comfort for the driver. The allowed gradients depend
                   on the control mode.

  @description     Positive and negative gradient limits (jerk) for maximum and minimum acceleration requests are 
                   calculated based on speed, ACC/CC conditions, limiter conditions, ramp conditions, etc. If CC is 
                   engaged in dynamic situations, higher acceleration gradients are allowed via KMC_v_InitAccelRequest. 
                   Difference between current commanded acceleration and requested acceleration of last cycle is used 
                   to calculate actual required jerks for both min and max values. Actual jerks are then limited within 
                   calculated positive and negative jerk limits giving allowed jerks. Maximum and minimum requested 
                   accelerations are limited from previous cycle values based on allowed jerks.
    @startuml
    Start
    Partition KMC_v_LimitAccelChangeRate {
      If (Object control) then (yes)
        : Max +ve and -ve jerks \nlimits for Follow mode calculated (<b>A</b>);
      Else (CC Control)
        : Max +ve and -ve jerks \nlimits for CC mode calculated (<b>A</b>);
        If (Transition from ACC to CC) then (yes)
          : Positive jerk limit reduced by a factor;
        Else (no)
        Endif
      Endif
      note right
      MaxCA = MAXIMUM_COMMANDED_ACCELERATION (Input)
      MinCA = MINIMUM_COMMANDED_ACCELERATION (Input)
      MaxRA = MAXIMUM_REQUESTED_ACCELERATION (Output)
      MinRA = MINIMUM_REQUESTED_ACCELERATION (Output)
      endnote
      If (Accelerating from braking phase and \ntime estimate for it is too long) then(yes)
        : Positive jerk is limited;
      Else (no)
      Endif
      : Positive/Negative jerks can be reduced;
      Note right
        Jerk reduction only if configured
        Extent of reduction dependent on speed,
        difference of commanded and requested accel
        and situation criticality
      End Note
      : KMC_v_InitAccelRequest;
      Partition Jerk_Limits_Modified {
        : Actual jerk calculated based \non MinCA/MinRA and MaxCA/MaxRA (<b>B</b>);
        If (Active or Decel_Only State) then (yes)
          : Accel ramps set to FALSE;
          : Max +ve and -ve jerk limits used (from <b>A</b>);
          : Jerk limited if accelerating to 0 almost reached;
          : Positive jerk is minimum Cc_min_grad_rest;
          : Negative jerk is maximum -Cc_min_grad_rest;
          : Allowed jerk limit (<b>C</b>) for state calculated;
        Elseif (Disengaged State) then (yes)
          : ACCEL_RAMP_ACTIVE = TRUE;
          note right
          Inhibition bits copied to accel control data
          endnote
          : ACCEL_STATUS.NO_RAMP = INHIBIT.CC_DISENGAGEMENT_NO_RAMP;
          : ACCEL_STATUS.CANCEL_RAMP = INHIBIT.CC_DISENGAGEMENT_RAMP;
          : ACCEL_STATUS.RAPID_RAMP = INHIBIT.CC_DISENGAGEMENT_RAPID_RAMP;
          If (NO_RAMP == TRUE) then (yes)
            : Max +ve and -ve jerk limits used (from <b>A</b>);
          Elseif (RAPID_RAMP == TRUE) then (yes)
            : Cc_max_neg_grad_rapid_disengage used;
            : Cc_max_pos_grad_rapid_disengage used;
          Elseif (CANCEL_RAMP == TRUE) then (yes)
          : Cc_max_neg_grad_disengage used;
          : Cc_max_pos_grad_disengage used;
          Else (no)
          Endif
          : Allowed jerk limit (<b>C</b>) for state calculated;
          If (Commanded/Desired acceleration is almost reached) then (yes)
            : ACCEL_RAMP_ACTIVE = FALSE;
          Else (no)
          Endif
        Elseif (Override State) then (yes)
          : Max +ve and -ve jerk limits used (from <b>A</b>);
          : Allowed jerk limit (<b>C</b>) for state calculated;
        Else (no)
        Endif
        : Actual jerk (<b>B</b>) limited to allowed jerk (<b>C</b>);
        : MaxRA/MinRA calculated based on final jerk limits;
      }
    }
    End
    @enduml

  @return          -

  @param[in]       cycle_time : cycle time of FCT_VEH cycle [0u ... 1000u] ms
  @param[in]       driver_requests : Pointer to driver request input structure [cc_driver_requests_t as per cc_ext.h]
                    CONTROL_STATE : Variable that reflects the state of the HMI state machine [full range of datatype cc_control_state_t as in cc_ext.h]
                    DRIVER_OPERATIONS.ACCEL_MODE : Boolean indicating if acceleration with constant value [TRUE, FALSE]
                    DRIVER_OPERATIONS.DECEL_MODE : Boolean indicating if deceleration with constant value [TRUE, FALSE]
                    ENGAGEMENT_CONDITIONS.DRIVER_OVERRIDE : Boolean indicating override condition by driver [TRUE, FALSE]
  @param[in,out]   cc_control_data : Pointer to CC control data [cc_control_data_t as per cc_ext.h]
                    cc_control_data->CC_ACC_TO_CC_TRANSITION : Boolean, if TRUE indicates transition from ACC (object-control) to CC [TRUE, FALSE]
  @param[in,out]   accel_control_data : Pointer to CC acceleration control data [cc_acceleration_control_data_t as per cc_ext.h]
                    ACCEL_STATUS.OBJECT_EFFECTIVE : Boolean, if TRUE indicating effective OOI for ACC [TRUE, FALSE]
                    MINIMUM_COMMANDED_ACCELERATION : Minimum commanded acceleration [-30000u ...+30000u] m/s2 (with factor Acceleration_s)
                    MAXIMUM_COMMANDED_ACCELERATION : Maximum commanded acceleration [-30000u ...+30000u] m/s2 (with factor Acceleration_s)
                    MINIMUM_REQUESTED_ACCELERATION : Minimum requested acceleration [-30000u ...+30000u] m/s2 (with factor Acceleration_s)
                    MAXIMUM_REQUESTED_ACCELERATION : Maximum requested acceleration [-30000u ...+30000u] m/s2 (with factor Acceleration_s)
                    MINIMUM_REQUESTED_ACCELERATION_LAST_CYCLE : Minimum requested acceleration as per last cycle [-30000u ...+30000u] m/s2 (with factor Acceleration_s)
                    MAXIMUM_REQUESTED_ACCELERATION_LAST_CYCLE : Maximum requested acceleration as per last cycle [-30000u ...+30000u] m/s2 (with factor Acceleration_s)
                    ACCEL_STATUS.NO_RAMP : Boolean, if TRUE indicating no acceleration ramp [TRUE, FALSE]
                    ACCEL_STATUS.RAPID_RAMP : Boolean, if TRUE indicating rapid acceleration ramp [TRUE, FALSE]
                    ACCEL_STATUS.CANCEL_RAMP : Boolean, if TRUE indicating acceleration ramp cancelled [TRUE, FALSE]
                    ACCEL_STATUS.ACCEL_RAMP_ACTIVE : Boolean ,if TRUE indicating acceleration ramp active [TRUE, FALSE]
  @param[in]       das_input : Pointer to input from longitudinal dynamics management to driver assistance system [cart_das_input_data_t as per cart_ext.h]
                    VEHICLE_SPEED : Ego speed with factor Velocity_s [-30000u ... 30000u] cm/s
  @param[in,out]   das_output : Pointer to output data from driver assistance system to longitudinal dynamics management [cart_das_output_data_t as per cart_ext.h]
                    MIN_REQ_ACCEL : Minimum required acceleration output [-30000u ...+30000u] m/s2 (with factor Acceleration_s)
  @param[in]       input : Pointer to cc_input_data_t type structure containing input data to CC [cc_input_data_t as per cc_ext.h]
                    INHIBIT.CC_DISENGAGEMENT_NO_RAMP : Inhibition bit for no ramp [TRUE, FALSE]
                    INHIBIT.CC_DISENGAGEMENT_RAMP : Inhibition bit for ramp [TRUE, FALSE]
                    INHIBIT.CC_DISENGAGEMENT_RAPID_RAMP : Inhibition bit for rapid ramp [TRUE, FALSE]
  @param[in]       acc_output : Pointer to ACC output [acc_output_data_t as per Rte_Type.h]
                    SITUATION_CLASS.CRITICALITY : Criticality of the situation [0u ... 255u] (with factor 255/100)

  @glob_in         - 
  @glob_out        - 

  @c_switch_part   FCT_CFG_ACC_HEADWAY_PLANNER : Configuration switch for enabling ACC processing
  @c_switch_part   CFG_FCT_FLIM : Configuration switch for FLIM support
  @c_switch_part   CFG_FCT_CC_USE_SMOOTH_JERKS : Configuration switch enabling smooth gradients for acceleration requests
  @c_switch_part   CFG_FCT_CC_USE_MIN_MAX_DISENGAGEMENT : Configuration switch enabling ramping of required acceleration at disengagement
  @c_switch_full   FCT_CFG_LOPC_COMPONENT : Configuration switch for enabling LOPC processing
  @c_switch_full   FCT_CFG_CC : Configuration switch for enabling CC processing
*************************************************************************************************************************/
static void KMC_v_LimitAccelChangeRate(const times_t cycle_time, const cc_driver_requests_t* driver_requests, cc_control_data_t* cc_control_data, cc_acceleration_control_data_t* accel_control_data, const cart_das_input_data_t* das_input, cart_das_output_data_t* das_output, const cc_input_data_t* input, const acc_output_data_t* acc_output)
{
  gradient_t min_actual_grad;
  gradient_t max_actual_grad;
  gradient_t min_neg_grad_limit;
  gradient_t max_neg_grad_limit;
  gradient_t min_pos_grad_limit;
  gradient_t max_pos_grad_limit;
  gradient_t min_allowed_grad;
  gradient_t max_allowed_grad;
  gradient_t min_max_pos_grad;
  gradient_t min_max_neg_grad;
  gradient_t max_max_pos_grad;
  gradient_t max_max_neg_grad;
  sint32     help_accel;
  
  sint32     com_req_max_accel_delta;
  gradient_t max_neg_grad;
  gradient_t max_pos_grad;

#if (CFG_FCT_CC_USE_SMOOTH_JERKS)
  times_t    smooth_grad_neg_time;
#endif
  times_t    smooth_grad_pos_time;
  
  sint32     delta_time;
  
#if (FCT_CFG_ACC_HEADWAY_PLANNER || CFG_FCT_FLIM)

  /* Does the Inpath-Object actually influence the longitudinal control ?*/
  if (accel_control_data->ACCEL_STATUS.OBJECT_EFFECTIVE == TRUE)
  {
/****************************/
/*   ACC Gradient Limits    */
/****************************/
    max_neg_grad = MAT_CALCULATE_PARAM_VALUE1D(Kmc_acc_max_neg_grad, Kmc_acc_neg_grad_points, das_input->VEHICLE_SPEED);

    /* modify positive acceleration request dependent on the sign */
    if(das_output->MIN_REQ_ACCEL >= (acceleration_t)0)
    {
      /* acceleration gradient for positive accel requests */
      max_pos_grad = MAT_CALCULATE_PARAM_VALUE1D(Kmc_acc_max_pos_grad_pos_accel, Kmc_acc_pos_grad_pos_accel_points, das_input->VEHICLE_SPEED);
      /*max_pos_grad = (gradient_t)(max_pos_grad*accel_pos_gradient_factor/Factor_s);*/
    }
    else
    {
      /* acceleration gradient for negative accel requests */
      max_pos_grad = MAT_CALCULATE_PARAM_VALUE1D(Kmc_acc_max_pos_grad_neg_accel, Kmc_acc_pos_grad_neg_accel_points, das_input->VEHICLE_SPEED);
    }

  }
  else
  {
/****************************/
/*    CC Gradient Limits    */
/****************************/
    max_neg_grad = MAT_CALCULATE_PARAM_VALUE1D(Cc_max_neg_grad, Cc_neg_grad_points, das_input->VEHICLE_SPEED);

    /* modify positive acceleration request dependent on the sign */
    if(das_output->MIN_REQ_ACCEL >= (acceleration_t)0)
    {
      /* acceleration gradient for positive accel requests */
      max_pos_grad = MAT_CALCULATE_PARAM_VALUE1D(Cc_max_pos_grad_pos_accel, Cc_pos_grad_pos_accel_points, das_input->VEHICLE_SPEED);
      /*max_pos_grad = (gradient_t)(max_pos_grad*accel_pos_gradient_factor/Factor_s);*/
      if(cc_control_data->CC_ACC_TO_CC_TRANSITION == TRUE)
      {
        /*! max_pos_grad in the case of transition will be reduced for some time */
        help_accel = (sint32)max_pos_grad * (sint32)Cc_acc_to_cc_transition_factor;
        help_accel /= (sint32)Acceleration_s;
        max_pos_grad = help_accel;
      }
    }
    else
    {
      /* acceleration gradient for negative accel requests */
      max_pos_grad = MAT_CALCULATE_PARAM_VALUE1D(Cc_max_pos_grad_neg_accel, Cc_pos_grad_neg_accel_points, das_input->VEHICLE_SPEED);
    }
  }
#else
  max_neg_grad = MAT_CALCULATE_PARAM_VALUE1D(Cc_max_neg_grad, Cc_neg_grad_points, das_input->VEHICLE_SPEED);;
  max_pos_grad = MAT_CALCULATE_PARAM_VALUE1D(Cc_max_pos_grad, Cc_pos_grad_points, das_input->VEHICLE_SPEED);;
#endif
  
  /*Determine acceleration difference*/
  com_req_max_accel_delta = ((sint32)accel_control_data->MAXIMUM_COMMANDED_ACCELERATION - (sint32)accel_control_data->MAXIMUM_REQUESTED_ACCELERATION);
  
  /*Determine smooth gradient times*/
  smooth_grad_pos_time = (times_t)MAT_CALCULATE_PARAM_VALUE1D(Cc_smooth_gradient_pos_time, Cc_smooth_gradient_pos_time_points, das_input->VEHICLE_SPEED);
#if (CFG_FCT_CC_USE_SMOOTH_JERKS)
  smooth_grad_neg_time = (times_t)MAT_CALCULATE_PARAM_VALUE1D(Cc_smooth_gradient_neg_time, Cc_smooth_gradient_neg_time_points, das_input->VEHICLE_SPEED);
#endif

  /*Determine after which time the difference will be zero in case of max_pos_grad*/
  delta_time = MAT_DIV(com_req_max_accel_delta, max_pos_grad, Acceleration_s, Time_s, Time_s);
  delta_time = MAT_LIM(delta_time, Time_min, Time_max);

  if (
      (delta_time > (smooth_grad_pos_time/ 2) )
      &&
      (accel_control_data->MAXIMUM_COMMANDED_ACCELERATION > 0)
       &&
      (accel_control_data->MINIMUM_REQUESTED_ACCELERATION < 0)
     )
  {
    max_pos_grad = Cc_max_release_brake_grad;
  }


#if (CFG_FCT_CC_USE_SMOOTH_JERKS)
  {
    sint32     absacc;
    gradient_t set_grad;
    
    absacc = MAT_MAX(
      MAT_ABS((sint32)accel_control_data->MINIMUM_COMMANDED_ACCELERATION - (sint32)accel_control_data->MINIMUM_REQUESTED_ACCELERATION),
      MAT_ABS((sint32)accel_control_data->MAXIMUM_COMMANDED_ACCELERATION - (sint32)accel_control_data->MAXIMUM_REQUESTED_ACCELERATION)
      );

    /* Reduction of smoothing time dependent on absolute acceleration error */
    smooth_grad_neg_time = (times_t)MAT_MUL(smooth_grad_neg_time, 
                                            MAT_CALCULATE_PARAM_VALUE1D(Kmc_smooth_gradient_gain, Kmc_smooth_gradient_gain_points, (sint16)absacc),
                                            Time_s, Factor_s, Time_s);
    
    if (driver_requests->CONTROL_STATE != Cc_cc_disengage)
    {
      set_grad = MAT_DIV(absacc, smooth_grad_pos_time, Acceleration_s, Time_s, Time_s);
      
#if (KMC_NO_SMOOTH_JERK_IN_LOW_SPEED)
      /* If detected that fast brake release is desired, positive gradient to not be reduced */
      /* Boolean calculated with hysteresis between -3 m/s^2 and -1 m/s^2 */
      if (b_DetectStrongBrakeRelease == FALSE)
      {
        if((das_input->VEHICLE_ACCEL < Kmc_fast_brake_release_accel_high_thres) &&
            (das_input->VEHICLE_SPEED < Kmc_fast_brake_release_speed_thres))
        {
          b_DetectStrongBrakeRelease = TRUE;
        }
      }
      else
      {
        if(das_input->VEHICLE_ACCEL > Kmc_fast_brake_release_accel_low_thres)
        {
          b_DetectStrongBrakeRelease = FALSE;
        }
      }

      if((das_input->VEHICLE_SPEED < Kmc_fast_brake_release_speed_thres)
          && (b_DetectStrongBrakeRelease == TRUE))
      {
        /* Jerk smoothing not performed for positive gradients */
      }
      else 
      {
#endif  /* KMC_NO_SMOOTH_JERK_IN_LOW_SPEED */

        if(das_input->VEHICLE_SPEED > Cc_smooth_gradient_pos_min_velocity)
        {
          max_pos_grad = MAT_LIM(set_grad, Cc_smooth_jerk_min_gradient,max_pos_grad);
        }
#if (KMC_NO_SMOOTH_JERK_IN_LOW_SPEED)
      }
#endif  /* KMC_NO_SMOOTH_JERK_IN_LOW_SPEED */
      
#if (KMC_NO_SMOOTH_JERK_IN_LOW_SPEED)
      if(
          (das_input->VEHICLE_SPEED < Kmc_low_speed_thres_neg_smooth_jerk) &&
          (acc_output->SITUATION_CLASS.CRITICALITY*Scale_100/Confidence_s > HIGH_GRAD_CRITICALITY_THRES)
        )
      {
        /* Jerk smoothing not performed for negative gradient */
      }
      else
      {
#endif  /* KMC_NO_SMOOTH_JERK_IN_LOW_SPEED */

        /*Only smooth jerks within normal acceleration requests*/
        if (accel_control_data->MINIMUM_COMMANDED_ACCELERATION > ACCELERATION_FOR_MAXIMUM_GRAD)
        {
          set_grad = MAT_DIV(-absacc, smooth_grad_neg_time, Acceleration_s, Time_s, Time_s);
          max_neg_grad = MAT_LIM(set_grad,max_neg_grad,-Cc_smooth_jerk_min_gradient);
        }

#if (KMC_NO_SMOOTH_JERK_IN_LOW_SPEED)
      }
#endif
    }
  }
#endif /* (CFG_FCT_CC_USE_SMOOTH_JERKS) */

/* Modify the limits of the acceleration gradient in critical situations */
#if (CFG_FCT_CC_USE_CONTROL_CRITICALITY)
  {
    /* Allow bigger accel gradients in critical traffic situations to reduce the reaction time */
    max_neg_grad *= (sint32)MAT_CALCULATE_PARAM_VALUE1D(criticality_accel_gradient_gain,accel_gradient_gain_points,(sint16)(acc_output->SITUATION_CLASS.CRITICALITY*Scale_100/Confidence_s));
    max_neg_grad /= Scale_100;
    /* Limit negative gradient to the maximum allowed threshold (within ISO norm 22179:2009) */
    max_neg_grad_limit = MAT_CALCULATE_PARAM_VALUE1D(max_decel_gradient_critical,max_decel_gradient_critical_points,das_input->VEHICLE_SPEED);
    max_neg_grad = MAT_MAX(max_neg_grad,max_neg_grad_limit);
  }
#else
  _PARAM_UNUSED(acc_output);
#endif

  /*save last acceleration request*/
  accel_control_data->MINIMUM_REQUESTED_ACCELERATION_LAST_CYCLE = accel_control_data->MINIMUM_REQUESTED_ACCELERATION;
  accel_control_data->MAXIMUM_REQUESTED_ACCELERATION_LAST_CYCLE = accel_control_data->MAXIMUM_REQUESTED_ACCELERATION;


  /* CmdAccelOld is initialized at engagement */
  KMC_v_InitAccelRequest(driver_requests, cc_control_data, accel_control_data, das_input);


  /* Determine ActualJerk */
  min_actual_grad = ((((sint32)accel_control_data->MINIMUM_COMMANDED_ACCELERATION - (sint32)accel_control_data->MINIMUM_REQUESTED_ACCELERATION_LAST_CYCLE) * (sint32)Time_s) / (sint32)cycle_time);
  max_actual_grad = ((((sint32)accel_control_data->MAXIMUM_COMMANDED_ACCELERATION - (sint32)accel_control_data->MAXIMUM_REQUESTED_ACCELERATION_LAST_CYCLE) * (sint32)Time_s) / (sint32)cycle_time);
  
  min_neg_grad_limit = min_pos_grad_limit = min_actual_grad;
  max_neg_grad_limit = max_pos_grad_limit = max_actual_grad;
  
  /* Determine Minimum and Maximum Jerk for Positive and Negative Ramp */
  if (
      (driver_requests->CONTROL_STATE == Cc_lim_active)
      ||
      (driver_requests->CONTROL_STATE == Cc_plim_active)
     )
  {
    /* Variable or Permanent Speed limiter active */
    min_neg_grad_limit = MAT_MIN(min_neg_grad_limit, Lim_max_neg_grad);
    min_neg_grad_limit = MAT_MAX(min_neg_grad_limit, -Lim_min_grad_rest);
    min_pos_grad_limit = MAT_MIN(min_pos_grad_limit, Lim_max_pos_grad);
    min_pos_grad_limit = MAT_MAX(min_pos_grad_limit, Lim_min_grad_rest);
    
    max_neg_grad_limit = MAT_MIN(max_neg_grad_limit, Lim_max_neg_grad);
    max_neg_grad_limit = MAT_MAX(max_neg_grad_limit, -Lim_min_grad_rest);
    max_pos_grad_limit = MAT_MIN(max_pos_grad_limit, Lim_max_pos_grad);
    max_pos_grad_limit = MAT_MAX(max_pos_grad_limit, Lim_min_grad_rest);
  }
  else
  {
    if (driver_requests->CONTROL_STATE == Cc_lim_override)
    {
      /* Variable Speed limiter override */
      min_neg_grad_limit = Lim_max_neg_grad_override;
      min_pos_grad_limit = Lim_max_pos_grad_override;
      
      max_neg_grad_limit = Lim_max_neg_grad_override;
      max_pos_grad_limit = Lim_max_pos_grad_override;
    }
    else
    {
      /* engaged or override */
      if (
          (driver_requests->CONTROL_STATE == Cc_cc_active)
          ||
          (driver_requests->CONTROL_STATE == Cc_cc_decel_only)
         )
      {
        /*Reset accel ramps when active*/
        accel_control_data->ACCEL_STATUS.NO_RAMP     = FALSE;
        accel_control_data->ACCEL_STATUS.RAPID_RAMP  = FALSE;
        accel_control_data->ACCEL_STATUS.CANCEL_RAMP = FALSE;
        
        if (
            (driver_requests->DRIVER_OPERATIONS.ACCEL_MODE == TRUE)
            ||
            (driver_requests->DRIVER_OPERATIONS.DECEL_MODE == TRUE)
           )
        {
          min_max_neg_grad = Cc_max_neg_grad_accel_decel;
          min_max_pos_grad = Cc_max_pos_grad_accel_decel;
          max_max_neg_grad = Cc_max_neg_grad_accel_decel;
          max_max_pos_grad = Cc_max_pos_grad_accel_decel;
        }
        else
        {
          min_max_neg_grad = max_neg_grad;
          min_max_pos_grad = max_pos_grad;
          max_max_neg_grad = max_neg_grad;
          max_max_pos_grad = max_pos_grad;
        }
        
        /* The system is decelerating */
        if (
            (das_output->MIN_REQ_ACCEL < (acceleration_t)0)
            &&
            (accel_control_data->ACCEL_STATUS.OBJECT_EFFECTIVE == FALSE)
           )
        {
          /* With the next step 0 will be passed... */
          if (((sint32)accel_control_data->MINIMUM_REQUESTED_ACCELERATION_LAST_CYCLE + ((min_pos_grad_limit * (sint32)cycle_time) / (sint32)Time_s)) > (sint32)0)
          {
            /* the next step will be the difference to 0 */
            min_pos_grad_limit = (((((sint32)0 - (sint32)accel_control_data->MINIMUM_REQUESTED_ACCELERATION_LAST_CYCLE) * (sint32)Time_s) / (sint32)cycle_time));
          }
        }
        min_pos_grad_limit = MAT_MIN(min_pos_grad_limit, min_max_pos_grad);
        min_pos_grad_limit = MAT_MAX(min_pos_grad_limit, Cc_min_grad_rest);
        min_neg_grad_limit = MAT_MIN(min_neg_grad_limit, -Cc_min_grad_rest);
        min_neg_grad_limit = MAT_MAX(min_neg_grad_limit, min_max_neg_grad);
        
        /* The system is decelerating */
        if( 
           (das_output->MAX_REQ_ACCEL < (acceleration_t)0) 
           &&
           (accel_control_data->ACCEL_STATUS.OBJECT_EFFECTIVE == FALSE)
          )
        {
          /* With the next step 0 will be passed... */
          if (((sint32)accel_control_data->MAXIMUM_REQUESTED_ACCELERATION_LAST_CYCLE + ((max_pos_grad_limit * (sint32)cycle_time) / (sint32)Time_s)) > (sint32)0)
          {
            /* the next step will be the difference to 0 */
            max_pos_grad_limit = (((((sint32)0 - (sint32)accel_control_data->MAXIMUM_REQUESTED_ACCELERATION_LAST_CYCLE) * (sint32)Time_s) / (sint32)cycle_time));
          }
        }
        max_pos_grad_limit = MAT_MIN(max_pos_grad_limit, max_max_pos_grad);
        max_pos_grad_limit = MAT_MAX(max_pos_grad_limit, Cc_min_grad_rest);
        max_neg_grad_limit = MAT_MIN(max_neg_grad_limit, -Cc_min_grad_rest);
        max_neg_grad_limit = MAT_MAX(max_neg_grad_limit, max_max_neg_grad);
      }
      else
      {
        if (driver_requests->CONTROL_STATE == Cc_cc_disengage)
        {
          /*copy inhibition bits*/
          if(input->INHIBIT.CC_DISENGAGEMENT_NO_RAMP == TRUE)
          {
            accel_control_data->ACCEL_STATUS.NO_RAMP = TRUE;
          }
          if(input->INHIBIT.CC_DISENGAGEMENT_RAMP == TRUE)
          {
            accel_control_data->ACCEL_STATUS.CANCEL_RAMP = TRUE;
          }
          if(input->INHIBIT.CC_DISENGAGEMENT_RAPID_RAMP == TRUE)
          {
            accel_control_data->ACCEL_STATUS.RAPID_RAMP = TRUE;
          }
          
          accel_control_data->ACCEL_STATUS.ACCEL_RAMP_ACTIVE = TRUE;
            
          if (accel_control_data->ACCEL_STATUS.NO_RAMP == TRUE)
          {
            min_neg_grad_limit = max_neg_grad;
            min_pos_grad_limit = max_pos_grad;
          }
          else
          {
            if (accel_control_data->ACCEL_STATUS.RAPID_RAMP == TRUE)
            {
              min_neg_grad_limit = Cc_max_neg_grad_rapid_disengage;
              min_pos_grad_limit = Cc_max_pos_grad_rapid_disengage;
              
              max_neg_grad_limit = Cc_max_neg_grad_rapid_disengage;
              max_pos_grad_limit = Cc_max_pos_grad_rapid_disengage;
            }
            else
            {
              if (accel_control_data->ACCEL_STATUS.CANCEL_RAMP == TRUE)
              {
                min_neg_grad_limit = Cc_max_neg_grad_disengage;
                min_pos_grad_limit = Cc_max_pos_grad_disengage;

                max_neg_grad_limit = Cc_max_neg_grad_disengage;
                max_pos_grad_limit = Cc_max_pos_grad_disengage;
              }
            }
          }

#if (CFG_FCT_CC_USE_MIN_MAX_DISENGAGEMENT)
            
          if (
              (das_output->MIN_REQ_ACCEL <= accel_control_data->MIN_ALLOWED_ACCEL)
              &&
              (das_output->MAX_REQ_ACCEL >= accel_control_data->MAX_ALLOWED_ACCEL)
             )
#else
          if (
            ((das_output->MIN_REQ_ACCEL - accel_control_data->MINIMUM_COMMANDED_ACCELERATION) > -Cc_accel_band)
            &&
            ((das_output->MAX_REQ_ACCEL - accel_control_data->MAXIMUM_COMMANDED_ACCELERATION) < Cc_accel_band)
            )
#endif
          {
            accel_control_data->ACCEL_STATUS.ACCEL_RAMP_ACTIVE = FALSE;
          }
        }
        else
        {
          if (driver_requests->CONTROL_STATE == Cc_lim_disengage)
          {
            accel_control_data->ACCEL_STATUS.ACCEL_RAMP_ACTIVE = TRUE;

            min_neg_grad_limit = Lim_max_neg_grad_disengage;
            min_pos_grad_limit = Lim_max_pos_grad_disengage;
            
            max_neg_grad_limit = Lim_max_neg_grad_disengage;
            max_pos_grad_limit = Lim_max_pos_grad_disengage;

            if (
                (das_output->MIN_REQ_ACCEL >=  Lim_accel_limit)
                ||
                (driver_requests->ENGAGEMENT_CONDITIONS.DRIVER_OVERRIDE == TRUE)
               )
            {
              accel_control_data->ACCEL_STATUS.ACCEL_RAMP_ACTIVE = FALSE;
            }
          }
          else
          {
            /*cc_override*/
            if (driver_requests->CONTROL_STATE == Cc_cc_override)
            {
              /* During Override any jerk shall be accepted */
              min_neg_grad_limit = max_neg_grad;
              min_pos_grad_limit = max_pos_grad;
            }
          }
        }
      }
    }
  }

  /* Limit Jerk */

  min_allowed_grad = MAT_LIM(min_actual_grad,min_neg_grad_limit,min_pos_grad_limit);
  min_allowed_grad = MAT_LIM(min_allowed_grad,accel_control_data->MIN_CUSTOM_ALLOWED_GRAD,accel_control_data->MAX_CUSTOM_ALLOWED_GRAD);
  help_accel = ((min_allowed_grad * (sint32)cycle_time) / (sint32)Time_s);
  accel_control_data->MINIMUM_REQUESTED_ACCELERATION = (acceleration_t)((sint32)accel_control_data->MINIMUM_REQUESTED_ACCELERATION_LAST_CYCLE + help_accel);

  max_allowed_grad = MAT_LIM(max_actual_grad,max_neg_grad_limit,max_pos_grad_limit);
  max_allowed_grad = MAT_LIM(max_allowed_grad,accel_control_data->MIN_CUSTOM_ALLOWED_GRAD,accel_control_data->MAX_CUSTOM_ALLOWED_GRAD);
  help_accel = ((max_allowed_grad * (sint32)cycle_time) / (sint32)Time_s);
  accel_control_data->MAXIMUM_REQUESTED_ACCELERATION = (acceleration_t)((sint32)accel_control_data->MAXIMUM_REQUESTED_ACCELERATION_LAST_CYCLE + help_accel);
}// PRQA S 7004
/* date: 2018-03-26, reviewer: Ravi Kiran Gurrala, reason: Cyclomatic complexity. Not safety critical */

/*************************************************************************************************************************
  Functionname:    KMC_v_LimitDecel                                                                                 */ /*!

  @brief           Limitation of CC deceleration after override

  @description     After a driver override, the deceleration needed to control to the set speed, is limited to 
                   increase comfort for the driver. The DECEL_LIM_OVERRIDE bit is set when a transition from "override"
                   to "active" is detected and the commanded acceleration is lower than the according calibration 
                   Cc_max_decel_after_override. The DECEL_LIM_OVERRIDE bit is reset when the setspeed is decreased
                   or the commanded acceleration is higher than the according calibration Cc_max_decel_after_override. 
                   When engagement transition for ACC is detected the boolean DECEL_LIM_ENGAGE is set as TRUE. This boolean 
                   is reset again when driver reduces set speed or commanded acceleration is greater than Cc_max_decel_after_engage.

    @startuml
    Start
    Partition KMC_v_LimitDecel {
      If (DECEL_LIM_OVERRIDE_ACTIVE == FALSE) then (yes)
        If (State changed from override to active) then (yes)
          : DECEL_LIM_ENGAGE = TRUE;
          If (Setspeed not manually decreased\n AND \nCC AccelRequest < Cc_max_decel_after_override)
            : DECEL_LIM_OVERRIDE_ACTIVE = TRUE;
            : Counter reset to init value;
          Else (no)
          Endif
        Else (no)
        Endif
      Else (no)
        If (ACC active state) then (yes)
          If (Counter not yet 0) then (yes)
            : Decrement counter;
            If (Setspeed decreased manually \n OR \nCC AccelRequest > Cc_max_decel_after_override) then (yes)
              : DECEL_LIM_OVERRIDE_ACTIVE = FALSE;
            Else (no)
            Endif
          Else (no)
            : DECEL_LIM_OVERRIDE_ACTIVE = FALSE;
          Endif
        Else (no)
          : DECEL_LIM_OVERRIDE_ACTIVE = FALSE;
        Endif
      Endif
      If (DECEL_LIM_OVERRIDE_ACTIVE == TRUE) then (yes)
        : CC MINIMUM_ACCELERATION_LIMIT set \nwith Cc_max_decel_after_override;
      Else (no)
      Endif

      If (DECEL_LIM_ENGAGE == FALSE) then (yes)
        If (New engagement from Ready) then (yes)
          : DECEL_LIM_ENGAGE = TRUE;
        Else (no)
          If (Setspeed manually decreased \n OR \nCC AccelReq > Cc_max_decel_after_engage)
            : DECEL_LIM_ENGAGE = FALSE;
          Else (no)
          Endif
        Endif
      Else (no)
      Endif
    }
    End
    @enduml

  @return          -

  @param[in,out]   cc_status : Pointer to Cruisecontrol status [cc_status_t as per cc_ext.h]
                    CC_ACCEL_CONTROL_DATA.ACCEL_STATUS.DECEL_LIM_ENGAGE : Boolean, if TRUE indicating limitation of deceleration after engage [TRUE, FALSE]
                    CC_CONTROL_DATA.CC_ACCELERATION : CC acceleration [-30000u ...+30000u] m/s2 (with factor Acceleration_s)
                    CC_CONTROL_DATA.DECEL_LIM_OVERRIDE_ACTIVE : Boolean indicating if deceleration is limited after override [TRUE, FALSE]
                    CC_CONTROL_DATA.DECEL_LIM_ACTIVE_COUNTER : Counter for tracking duration that deceleration limiter is active [0u ... 65500u]
                    CC_CONTROL_DATA.MINIMUM_ACCELERATION_LIMIT : Minimum CC acceleration limit [-30000u ...+30000u] m/s2 (with factor Acceleration_s)
                    CC_DRIVER_REQUESTS.CONTROL_STATE : Variable that reflects the state of the HMI state machine [full range of datatype cc_control_state_t as in cc_ext.h]
                    CC_DRIVER_REQUESTS.CONTROL_STATE_LAST_CYCLE : Variable that reflects the state of the HMI state machine as per last cycle [full range of datatype cc_control_state_t as in cc_ext.h]
                    CC_DRIVER_REQUESTS.DRIVER_OPERATIONS.CC_DECREASE_SET_SPEED : Boolean if constant decreasing of set speed [TRUE, FALSE]
                    CC_DRIVER_REQUESTS.DRIVER_OPERATIONS.ACCEL_MODE : Boolean indicating if acceleration with constant value [TRUE, FALSE]
                    CC_DRIVER_REQUESTS.DRIVER_OPERATIONS.DECEL_MODE : Boolean indicating if deceleration with constant value [TRUE, FALSE]

  @glob_in         -
  @glob_out        -

  @c_switch_part   CFG_FCT_CC_USE_DECEL_LIM_OVERRIDE : Configuration switch enabling deceleration limitation after override
  @c_switch_part   CFG_FCT_CC_USE_DECEL_LIM_ENGAGE : Configuration switch enabling deceleration limitation after CC engage
  @c_switch_full   FCT_CFG_LOPC_COMPONENT : Configuration switch for enabling LOPC processing
  @c_switch_full   FCT_CFG_CC : Configuration switch for enabling CC processing
*************************************************************************************************************************/
static void KMC_v_LimitDecel(cc_status_t *cc_status)
{
#if (CFG_FCT_CC_USE_DECEL_LIM_OVERRIDE)
  /* Limit Deceleration After Override ? */
  if (cc_status->CC_CONTROL_DATA.DECEL_LIM_OVERRIDE_ACTIVE == FALSE)
  {
    /* Activate Limiter when not active */
    if (
       (cc_status->CC_DRIVER_REQUESTS.CONTROL_STATE == Cc_cc_active)
       &&
       (cc_status->CC_DRIVER_REQUESTS.CONTROL_STATE_LAST_CYCLE == Cc_cc_override)
      )
    {
      /*set ENGAGE_LIMITER always to true after override*/
      cc_status->CC_ACCEL_CONTROL_DATA.ACCEL_STATUS.DECEL_LIM_ENGAGE = TRUE;
      /* set deceleration limiter if no set speed decrease happened and commanded acceleration < -0.4 */
      if (
           (cc_status->CC_DRIVER_REQUESTS.DRIVER_OPERATIONS.CC_DECREASE_SET_SPEED == FALSE)
           &&
           (cc_status->CC_CONTROL_DATA.CC_ACCELERATION < Cc_max_decel_after_override)
         )
      {
        cc_status->CC_CONTROL_DATA.DECEL_LIM_OVERRIDE_ACTIVE = TRUE;
        cc_status->CC_CONTROL_DATA.DECEL_LIM_ACTIVE_COUNTER = Cc_max_decel_limit_time;
      }
    }
  }
  else
  {
    /* Deactivate Limiter when active */
    if (cc_status->CC_DRIVER_REQUESTS.CONTROL_STATE == Cc_cc_active)
    {
      if (cc_status->CC_CONTROL_DATA.DECEL_LIM_ACTIVE_COUNTER > (uint16)0 )
      {
        cc_status->CC_CONTROL_DATA.DECEL_LIM_ACTIVE_COUNTER--;

        if (
            (cc_status->CC_DRIVER_REQUESTS.DRIVER_OPERATIONS.CC_DECREASE_SET_SPEED == TRUE)
            ||
            (cc_status->CC_CONTROL_DATA.CC_ACCELERATION > Cc_max_decel_after_override)
            ||
            (cc_status->CC_DRIVER_REQUESTS.DRIVER_OPERATIONS.ACCEL_MODE == TRUE)
            ||
            (cc_status->CC_DRIVER_REQUESTS.DRIVER_OPERATIONS.DECEL_MODE == TRUE)
          )
        {
          cc_status->CC_CONTROL_DATA.DECEL_LIM_OVERRIDE_ACTIVE = FALSE;
        }
      }
      else
      {
        cc_status->CC_CONTROL_DATA.DECEL_LIM_OVERRIDE_ACTIVE = FALSE;
      }
    }
    else
    {
      cc_status->CC_CONTROL_DATA.DECEL_LIM_OVERRIDE_ACTIVE = FALSE;
    }
  }
#else /*#if (CFG_FCT_CC_USE_DECEL_LIM_OVERRIDE)*/
  cc_status->CC_CONTROL_DATA.DECEL_LIM_OVERRIDE_ACTIVE = FALSE;
#endif

  /*if cc_control_data->DECEL_LIM_OVERRIDE_ACTIVE -> limit max deceleration to -0.4m/s²*/
  if(cc_status->CC_CONTROL_DATA.DECEL_LIM_OVERRIDE_ACTIVE == TRUE)
  {
    cc_status->CC_CONTROL_DATA.MINIMUM_ACCELERATION_LIMIT = Cc_max_decel_after_override;
  }
  else
  {
    cc_status->CC_CONTROL_DATA.MINIMUM_ACCELERATION_LIMIT = Accel_min;
  }

/*------------------ decel limit after engagement to avoid using brakes directly after engagement*/

  /* Limit Deceleration After Resume / Set */
  if (cc_status->CC_ACCEL_CONTROL_DATA.ACCEL_STATUS.DECEL_LIM_ENGAGE == FALSE)
  {
    if (
        (cc_status->CC_DRIVER_REQUESTS.CONTROL_STATE == Cc_cc_engage)
        &&
        (cc_status->CC_DRIVER_REQUESTS.CONTROL_STATE_LAST_CYCLE == Cc_cc_ready)
       )
    {
      cc_status->CC_ACCEL_CONTROL_DATA.ACCEL_STATUS.DECEL_LIM_ENGAGE = TRUE;
    }
  }
  else
  {
    if (
        (cc_status->CC_DRIVER_REQUESTS.DRIVER_OPERATIONS.CC_DECREASE_SET_SPEED == TRUE)
        ||
        (cc_status->CC_CONTROL_DATA.CC_ACCELERATION > Cc_max_decel_after_engage)
        ||
        (cc_status->CC_DRIVER_REQUESTS.DRIVER_OPERATIONS.ACCEL_MODE == TRUE)
        ||
        (cc_status->CC_DRIVER_REQUESTS.DRIVER_OPERATIONS.DECEL_MODE == TRUE)
#if (!CFG_FCT_CC_USE_DECEL_LIM_ENGAGE)
        ||
        (cc_status->CC_CONTROL_DATA.CC_ACCELERATION < Cc_max_decel_after_engage)
#endif
       )
    {
      cc_status->CC_ACCEL_CONTROL_DATA.ACCEL_STATUS.DECEL_LIM_ENGAGE = FALSE;
    }
  }
}


/*************************************************************************************************************************
  Functionname:    KMC_v_CoordinateAccel                                                                            */ /*!

  @brief           Determine the acceleration band depending on the CONTROL_STATE.
                   At this point the decision is made which "use case" for the
                   acceleration band is to be used. See CARTRONIC documentation.

  @description     Based on the control state, the acceleration band (MINIMUM_COMMANDED_ACCELERATION and 
                   MAXIMUM_COMMANDED_ACCELERATION) is determined. The band values are selected amongst maximum acceleration 
                   limited due to lateral acceleration and acceleration requests from CC, limiter as well as ACC (object-based). 
                   The values are limited as required within max and min allowed acceleration limits as well as customer 
                   specific allowed limits. If the object-based ACC acceleration is lowest amongst the available requests, 
                   ACC flag (OBJECT_EFFECTIVE) is set to TRUE. Conditions for acceleration initialisation are also tested.
    @startuml
    Start
    Partition KMC_v_CoordinateAccel {
      note right
      MaxCA = MAXIMUM_COMMANDED_ACCELERATION
      MinCA = MINIMUM_COMMANDED_ACCELERATION
      endnote
      : Switch on ACC Control State;
      If (Cc_cc_active\nOR\nCc_cc_override\nOR\nCc_cc_decel_only) then (yes)
        If (Overtake maneouvre is in passby phase) then (yes)
          : Positive CC acceleration is increased by factor;
        Else (no)
        Endif
        : Commanded acceleration set as min from CC, \nObject and lateral limitation acceleration;
        If (Cc_cc_decel_only) then (yes)
          : MaxCA set to min of commanded accel\n and Cc_min_decel_brake_only;
          : MinCA set to MIN_ALLOWED_ACCEL;
        Elseif (Cc_cc_override) then (yes)
        : MaxCA set to max of commanded\n accel and A_INIT;
        : MinCA set to max of commanded accel\n and Cc_max_decel_during_override;
        Else (Cc_cc_active)
          If (Limiter after first engagement\n or override is active) then (yes)
            : Negative CC accel is limited\n to Cc_max_decel_after_engage;
            : This is arbitrated with obj accel\n and saved to MinCA;
            : MinCA arbitrated with lateral accel\n limiter and saved to MaxCA;
          Else (no)
            : MinCA/MaxCA set to commanded accel;
          Endif
        Endif
      Elseif (Cc_cc_disengage) then (yes)
        : MinCA/MaxCA set to 0;
      Elseif (Cc_cc_off\nOR\nCc_cc_engage\nOR\nCc_cc_ready) then (yes)
        : MinCA/MaxCA set to 0;
      Else (no)
      : MinCA/MaxCA set to 0;
      Endif
      :  MinCA/MaxCA limited\n to custom accel limits;
      :  MinCA/MaxCA limited\n to allowed accel limits;
      If (Object accel is lower than CC accel) then (yes)
        : OBJECT_EFFECTIVE is set to 1;
      Else (no)
        : OBJECT_EFFECTIVE is set to 0;
      Endif
      : ALLOW_INIT bool set dependent on switch/situation;
    }
    End
    @enduml

  @return          -

  @param[in]       driver_requests : Pointer to driver request input structure [cc_driver_requests_t as per cc_ext.h]
                    CONTROL_STATE : Variable that reflects the state of the HMI state machine [full range of datatype cc_control_state_t as in cc_ext.h]
                    DRIVER_OPERATIONS.CC_DECREASE_SET_SPEED : Boolean if constant decreasing of set speed [TRUE, FALSE]
                    DRIVER_OPERATIONS.CC_INCREASE_SET_SPEED : Boolean if constant increasing of set speed [TRUE, FALSE]
  @param[in]       acc_output : Pointer to ACC output [acc_output_data_t as per Rte_Type.h]
                    DISTANCE_CTRL_ACCEL_MIN : Minimum acceleration for intrusion distance [-30000u ...+30000u] m/s2 (with factor Acceleration_s)
                    DISTANCE_CTRL_ACCEL_MAX : Maximum acceleration for intrusion distance [-30000u ...+30000u] m/s2 (with factor Acceleration_s)
                    MAX_ACC_ACCELERATION : Maximum allowed ACC acceleration [-30000u ...+30000u] m/s2 (with factor Acceleration_s)
                    ACC_OUTPUT_STATUS.ALLOW_INIT : Indicates the possibility, to initialize the control acceleration to the current ego vehicle acceleration [TRUE,FALSE]
  @param[in,out]   cc_control_data : Pointer to CC control data [cc_control_data_t as per cc_ext.h]
                    CC_ACCELERATION : CC acceleration limit [-30000u ...+30000u] m/s2 (with factor Acceleration_s)
                    MINIMUM_ACCELERATION_LIMIT : Minimum CC acceleration limit [-30000u ...+30000u] m/s2 (with factor Acceleration_s)
                    DECEL_LIM_OVERRIDE_ACTIVE : Boolean indicating if deceleration is limited after override [TRUE, FALSE]
                    LIM_ACCELERATION : Limiter acceleration limit [-30000u ...+30000u] m/s2 (with factor Acceleration_s)
  @param[in,out]   accel_control_data : Pointer to CC acceleration control data [cc_acceleration_control_data_t as per cc_ext.h]
                    MAXIMUM_ACCELERATION_LATERAL_LIMITED : Maximum longitudinal acceleration limited due to lateral acceleration [-30000u ...+30000u] m/s2 (with factor Acceleration_s)
                    MIN_ALLOWED_ACCEL : Minimum allowed acceleration for control object [-30000u ...+30000u] m/s2 (with factor Acceleration_s)
                    MAX_ALLOWED_ACCEL : Minimum allowed acceleration for control object [-30000u ...+30000u] m/s2 (with factor Acceleration_s)
                    MINIMUM_COMMANDED_ACCELERATION : Minimum commanded acceleration [-30000u ...+30000u] m/s2 (with factor Acceleration_s)
                    MAXIMUM_COMMANDED_ACCELERATION : Maximum commanded acceleration [-30000u ...+30000u] m/s2 (with factor Acceleration_s)
                    MIN_CUSTOM_ALLOWED_ACCEL : Minimum custom allowed acceleration [-30000u ...+30000u] m/s2 (with factor Acceleration_s)
                    MAX_CUSTOM_ALLOWED_ACCEL : Maximum custom allowed acceleration [-30000u ...+30000u] m/s2 (with factor Acceleration_s)
                    ACCEL_STATUS.OBJECT_EFFECTIVE : Boolean, if TRUE indicating effective OOI for ACC [TRUE, FALSE]
                    ACCEL_STATUS.LAT_ACCEL_LIM_ACTIVE : Boolean indicating whether limiter due to lateral acceleration is active [True, False]
                    ACCEL_STATUS.ALLOW_INIT : Indicates the possibility, to initialize the control acceleration to the current ego vehicle acceleration [TRUE,FALSE]
  @param[in]       das_input : Pointer to input from longitudinal dynamics management to driver assistance system [cart_das_input_data_t as per cart_ext.h]
                    A_INIT : Vehicle initialisation acceleration [-30000u ...+30000u] m/s2 (with factor Acceleration_s)
                    VEHICLE_SPEED : Ego speed with factor Velocity_s [-30000u ... 30000u] cm/s

  @c_switch_part   FCT_CFG_ACC_HEADWAY_PLANNER : Configuration switch for enabling ACC processing
  @c_switch_part   CFG_FCT_ALWAYS_ALLOW_INITIALISATION : Configuration switch to allow initialisation
  @c_switch_part   CFG_FCT_CC_BRAKE_LAT_LIM_AFTER_OR : Configuration switch for enabling brake usage for lateral limiter also after override
  @c_switch_part   CFG_FCT_CC_NO_ACCEL_LIM_IN_DISENGAGE : Configuration switch to disable acceleration limitation in disengage mode
  @c_switch_part   CFG_FCT_CC_USE_ACCEL_BAND_MODIFICATION : Configuration switch to use modification of acceleration band
  @c_switch_part   CFG_FCT_CC_USE_BRAKE : Configuration switch for enabling brake usage for CC
  @c_switch_part   CFG_FCT_CC_USE_BRAKES_FOR_LAT_LIM : Configuration switch for enabling brake usage for lateral limiter
  @c_switch_part   CFG_FCT_CC_USE_LONG_ACCEL_CUSTOM_LIMIT : Configuration switch enabling custom limitation of longitudinal acceleration
  @c_switch_part   CFG_FCT_CC_USE_MIN_MAX_DISENGAGEMENT : Configuration switch enabling ramping of required acceleration at disengagement
  @c_switch_part   CFG_FCT_CC_USE_HIGH_MIN_MAX_ACCEL_LIMIT : Configuration switch to raise and lower max and min acceleration limit respectively
  @c_switch_part   CFG_FCT_FLIM : Configuration switch for FLIM support
  @c_switch_full   FCT_CFG_LOPC_COMPONENT : Configuration switch for enabling LOPC processing
  @c_switch_full   FCT_CFG_CC : Configuration switch for enabling CC processing
*************************************************************************************************************************/
static void KMC_v_CoordinateAccel(const cc_driver_requests_t* driver_requests, const acc_output_data_t* acc_output, 
                                  cc_control_data_t* cc_control_data, cc_acceleration_control_data_t* accel_control_data,
                                  const cart_das_input_data_t* das_input)
{
  sint32         help_accel;

#if (!KMC_CFG_CUSTOM_ACCEL_ARBITRATION)
  acceleration_t commanded_engine_acceleration;
  acceleration_t commanded_brake_acceleration;
  

  /* Determine CommandedAcceleration (Evaluation of control states) */
  switch (driver_requests->CONTROL_STATE)
  {
    case Cc_cc_active:
    case Cc_cc_override:
    case Cc_cc_decel_only:
    {

#if (FCT_CFG_ACC_HEADWAY_PLANNER)
#if (CFG_FCT_CC_USE_BRAKE)
#if (KMC_CFG_OVERTAKE_SUPPORT_FEATURE)
      /* Increased acceleration performance from CC controller in the pass-by phase of overtaking */
      if((acc_output->SITUATION_CLASS.SITUATION == Acc_sit_class_overtake)
          &&(cc_control_data->CC_ACCELERATION > 0))
      {
        cc_control_data->CC_ACCELERATION = (acceleration_t)MAT_MUL(cc_control_data->CC_ACCELERATION, Cc_ot_pos_accel_factor, Acceleration_s, Scale_100, Acceleration_s);
      }
#endif  /* KMC_CFG_OVERTAKE_SUPPORT_FEATURE */
      commanded_brake_acceleration =  (acceleration_t)MAT_MIN(MAT_MAX((sint32)cc_control_data->CC_ACCELERATION,(sint32)cc_control_data->MINIMUM_ACCELERATION_LIMIT), (sint32)acc_output->DISTANCE_CTRL_ACCEL_MAX);
      commanded_engine_acceleration = (acceleration_t)MAT_MIN((sint32)cc_control_data->CC_ACCELERATION, (sint32)acc_output->DISTANCE_CTRL_ACCEL_MIN);

      commanded_engine_acceleration = (acceleration_t)MAT_MIN((sint32)commanded_engine_acceleration, (sint32)accel_control_data->MAXIMUM_ACCELERATION_LATERAL_LIMITED);
#if CFG_FCT_CC_USE_BRAKES_FOR_LAT_LIM
  #if CFG_FCT_CC_BRAKE_LAT_LIM_AFTER_OR
      commanded_brake_acceleration = (acceleration_t)MAT_MIN((sint32)commanded_brake_acceleration, (sint32)accel_control_data->MAXIMUM_ACCELERATION_LATERAL_LIMITED);
  #else
      commanded_brake_acceleration = (acceleration_t)MAT_MIN((sint32)commanded_brake_acceleration, MAT_MAX((sint32)accel_control_data->MAXIMUM_ACCELERATION_LATERAL_LIMITED,(sint32)cc_control_data->MINIMUM_ACCELERATION_LIMIT));        
  #endif
#endif
#else /*CFG_FCT_CC_USE_BRAKE*/
      commanded_brake_acceleration = acc_output->DISTANCE_CTRL_ACCEL_MAX;
      commanded_engine_acceleration = (acceleration_t)MAT_MIN((sint32)cc_control_data->CC_ACCELERATION, (sint32)accel_control_data->MAXIMUM_ACCELERATION_LATERAL_LIMITED);
#endif
#else /*FCT_CFG_ACC_HEADWAY_PLANNER*/
#if (CFG_FCT_CC_USE_BRAKE)
  #if (CFG_FCT_CC_USE_BRAKES_FOR_LAT_LIM)
    #if (CFG_FCT_CC_BRAKE_LAT_LIM_AFTER_OR)
          commanded_brake_acceleration = (acceleration_t)MAT_MIN(MAT_MAX((sint32)cc_control_data->CC_ACCELERATION,(sint32)cc_control_data->MINIMUM_ACCELERATION_LIMIT), (sint32)accel_control_data->MAXIMUM_ACCELERATION_LATERAL_LIMITED);
    #else
          commanded_brake_acceleration = (acceleration_t)MAT_MIN(MAT_MAX((sint32)cc_control_data->CC_ACCELERATION,(sint32)cc_control_data->MINIMUM_ACCELERATION_LIMIT), MAT_MAX((sint32)accel_control_data->MAXIMUM_ACCELERATION_LATERAL_LIMITED,(sint32)cc_control_data->MINIMUM_ACCELERATION_LIMIT));
#endif
  #else /*CFG_FCT_CC_USE_BRAKES_FOR_LAT_LIM*/
        commanded_brake_acceleration = (acceleration_t)MAT_MAX((sint32)cc_control_data->CC_ACCELERATION,cc_control_data->MINIMUM_ACCELERATION_LIMIT);
#endif
        commanded_engine_acceleration = (acceleration_t)MAT_MIN((sint32)cc_control_data->CC_ACCELERATION, (sint32)accel_control_data->MAXIMUM_ACCELERATION_LATERAL_LIMITED);
#else /*CFG_FCT_CC_USE_BRAKE*/
      commanded_brake_acceleration = accel_control_data->MAX_ALLOWED_ACCEL;
      commanded_engine_acceleration = (acceleration_t)MAT_MIN((sint32)cc_control_data->CC_ACCELERATION, (sint32)accel_control_data->MAXIMUM_ACCELERATION_LATERAL_LIMITED);
#endif
#endif  /* FCT_CFG_ACC_HEADWAY_PLANNER */

       /*if MAX<MIN -> MIN=MAX*/
      commanded_engine_acceleration = (acceleration_t) MAT_MIN((sint32)commanded_engine_acceleration,(sint32)commanded_brake_acceleration);


      if (driver_requests->CONTROL_STATE == Cc_cc_decel_only) 
      {
        /* use case "Brake Only" */
        accel_control_data->MAXIMUM_COMMANDED_ACCELERATION = (acceleration_t)MAT_MIN((sint32)commanded_brake_acceleration, (sint32)Cc_min_decel_brake_only);
        accel_control_data->MINIMUM_COMMANDED_ACCELERATION = accel_control_data->MIN_ALLOWED_ACCEL;
      }
      else 
      {
        if (driver_requests->CONTROL_STATE == Cc_cc_override) 
        {
          accel_control_data->MAXIMUM_COMMANDED_ACCELERATION = (acceleration_t)MAT_MAX((sint32)commanded_brake_acceleration, (sint32)das_input->A_INIT);
          /*! for commanded acceleration during override the parameter Cc_max_decel_during_override have to be set to Accel_min = -32767 */
          /*! for the special value (mostly 0) the parameter Cc_max_decel_during_override have to be set to that value */
          accel_control_data->MINIMUM_COMMANDED_ACCELERATION = (acceleration_t)MAT_MAX((sint32)commanded_engine_acceleration, (sint32)Cc_max_decel_during_override);
        }
        else 
        {
          if((accel_control_data->ACCEL_STATUS.DECEL_LIM_ENGAGE == TRUE)
            ||(cc_control_data->DECEL_LIM_OVERRIDE_ACTIVE == TRUE))
          {
            /* use case "Comfort" */
            help_accel = MAT_MAX((sint32)Cc_max_decel_after_engage, MAT_MAX((sint32)cc_control_data->CC_ACCELERATION,(sint32)cc_control_data->MINIMUM_ACCELERATION_LIMIT));
#if (FCT_CFG_ACC_HEADWAY_PLANNER || CFG_FCT_FLIM)
            accel_control_data->MAXIMUM_COMMANDED_ACCELERATION = (acceleration_t)MAT_MIN(help_accel, (sint32)acc_output->DISTANCE_CTRL_ACCEL_MAX); 
#else
            accel_control_data->MAXIMUM_COMMANDED_ACCELERATION = (acceleration_t)help_accel;
#endif

#if CFG_FCT_CC_USE_BRAKES_FOR_LAT_LIM
            accel_control_data->MAXIMUM_COMMANDED_ACCELERATION = (acceleration_t)MAT_MIN((sint32)accel_control_data->MAXIMUM_COMMANDED_ACCELERATION, (sint32)accel_control_data->MAXIMUM_ACCELERATION_LATERAL_LIMITED);
#endif
#if (CFG_FCT_CC_USE_ACCEL_BAND_MODIFICATION)
            accel_control_data->MINIMUM_COMMANDED_ACCELERATION = commanded_engine_acceleration;
#else
            accel_control_data->MINIMUM_COMMANDED_ACCELERATION = (acceleration_t)MAT_MIN(help_accel, (sint32)acc_output->DISTANCE_CTRL_ACCEL_MIN);
#endif
          }
          else
          {
            accel_control_data->MAXIMUM_COMMANDED_ACCELERATION = commanded_brake_acceleration;
            accel_control_data->MINIMUM_COMMANDED_ACCELERATION = commanded_engine_acceleration;
          }
        }
      }
      break;
    }
    case Cc_plim_active:
    case Cc_lim_active:
    case Cc_lim_override:
    {

    commanded_brake_acceleration = Lim_accel_limit;

#if (CFG_FCT_FLIM)
      /* ACC acceleration is effective, when object is effective
        object is effective when ACC acceleration is below Acc_acceleration_limit*/
      if(
          (acc_output->DISTANCE_CTRL_ACCEL_MAX < acc_output->MAX_ACC_ACCELERATION)
         )
      {
        commanded_brake_acceleration = acc_output->DISTANCE_CTRL_ACCEL_MAX;
      }
#endif

      accel_control_data->MAXIMUM_COMMANDED_ACCELERATION = (acceleration_t)MAT_MIN((sint32)cc_control_data->LIM_ACCELERATION,(sint32)commanded_brake_acceleration);
      accel_control_data->MINIMUM_COMMANDED_ACCELERATION = accel_control_data->MAXIMUM_COMMANDED_ACCELERATION;
      break;
    }
    case Cc_cc_disengage:
    {
#if (CFG_FCT_CC_USE_MIN_MAX_DISENGAGEMENT)
      accel_control_data->MAXIMUM_COMMANDED_ACCELERATION = Acc_max_accel_disengage;
      accel_control_data->MINIMUM_COMMANDED_ACCELERATION = Acc_min_accel_disengage;
#else
      accel_control_data->MAXIMUM_COMMANDED_ACCELERATION = (acceleration_t)0;
      accel_control_data->MINIMUM_COMMANDED_ACCELERATION = (acceleration_t)0;
#endif

      break;
    }
    case Cc_lim_disengage:
    {

      accel_control_data->MAXIMUM_COMMANDED_ACCELERATION = Lim_accel_limit;
      accel_control_data->MINIMUM_COMMANDED_ACCELERATION = Lim_accel_limit;

      break;
    }
    case Cc_cc_off:
    case Cc_cc_engage:
    case Cc_cc_ready:
    case Cc_lim_ready:
    {
      accel_control_data->MAXIMUM_COMMANDED_ACCELERATION = (acceleration_t)0;
      accel_control_data->MINIMUM_COMMANDED_ACCELERATION = (acceleration_t)0;
      break;
    }
    default:
    {
      /* CommandedAcceleration is 0, CONTROL_STATE not defined */
      accel_control_data->MAXIMUM_COMMANDED_ACCELERATION = (acceleration_t)0;
      accel_control_data->MINIMUM_COMMANDED_ACCELERATION = (acceleration_t)0;
      break;
    }
  }
#else //KMC_CFG_CUSTOM_ACCEL_ARBITRATION
  KMC_ACC_CUSTOM_ARBITRATION(driver_requests, acc_output, cc_control_data, accel_control_data, das_input, LOPC_pLongCtrlOutput);
#endif //KMC_CFG_CUSTOM_ACCEL_ARBITRATION

  /*! Limitation to customer acceleration, the specific customer requirements should be available for using this function */
#if (CFG_FCT_CC_USE_LONG_ACCEL_CUSTOM_LIMIT)
  accel_control_data->MAXIMUM_COMMANDED_ACCELERATION = (acceleration_t)MAT_LIM((sint32)accel_control_data->MAXIMUM_COMMANDED_ACCELERATION,(sint32)accel_control_data->MIN_CUSTOM_ALLOWED_ACCEL, (sint32)accel_control_data->MAX_CUSTOM_ALLOWED_ACCEL);
  accel_control_data->MINIMUM_COMMANDED_ACCELERATION = (acceleration_t)MAT_LIM((sint32)accel_control_data->MINIMUM_COMMANDED_ACCELERATION,(sint32)accel_control_data->MIN_CUSTOM_ALLOWED_ACCEL, (sint32)accel_control_data->MAX_CUSTOM_ALLOWED_ACCEL);
#endif

  /*if MAX<MIN -> MIN=MAX*/
  accel_control_data->MINIMUM_COMMANDED_ACCELERATION = (acceleration_t) MAT_MIN((sint32)accel_control_data->MAXIMUM_COMMANDED_ACCELERATION,(sint32)accel_control_data->MINIMUM_COMMANDED_ACCELERATION);

#if(CFG_FCT_CC_USE_ACCEL_BAND_MODIFICATION && (FCT_CFG_ACC_HEADWAY_PLANNER || CFG_FCT_FLIM))
  if (
      (driver_requests->CONTROL_STATE !=Cc_cc_ready)
      &&
      (driver_requests->CONTROL_STATE !=Cc_cc_off)
      &&
      (driver_requests->CONTROL_STATE !=Cc_cc_disengage)
      )
  {
      /*spread band in low speed situations*/
    accel_control_data->MINIMUM_COMMANDED_ACCELERATION = (acceleration_t) (accel_control_data->MINIMUM_COMMANDED_ACCELERATION + MAT_CALCULATE_PARAM_VALUE1D(Acc_decrease_minaccel_curve, Acc_decrease_minaccel_points, das_input->VEHICLE_SPEED));
    accel_control_data->MAXIMUM_COMMANDED_ACCELERATION = (acceleration_t) (accel_control_data->MAXIMUM_COMMANDED_ACCELERATION + MAT_CALCULATE_PARAM_VALUE1D(Acc_increase_maxaccel_curve, Acc_increase_maxaccel_points, das_input->VEHICLE_SPEED));
  }
  
#endif

  if(
     (driver_requests->CONTROL_STATE == Cc_cc_ready)
     ||
#if (CFG_FCT_CC_NO_ACCEL_LIM_IN_DISENGAGE)
     (driver_requests->CONTROL_STATE == Cc_cc_disengage)
     ||
#endif
     (driver_requests->CONTROL_STATE == Cc_cc_engage)
     ||
     (driver_requests->CONTROL_STATE == Cc_cc_active)
     ||
     (driver_requests->CONTROL_STATE == Cc_cc_override)
     ||
     (driver_requests->CONTROL_STATE == Cc_cc_decel_only)
    )
  {

#if(CFG_FCT_CC_USE_HIGH_MIN_MAX_ACCEL_LIMIT)
    /*limit to allowed acceleration range*/
    accel_control_data->MAXIMUM_COMMANDED_ACCELERATION= (acceleration_t)MAT_LIM((sint32)accel_control_data->MAXIMUM_COMMANDED_ACCELERATION, (sint32)accel_control_data->MIN_ALLOWED_ACCEL, (sint32)Acc_max_accel_disengage);
    accel_control_data->MINIMUM_COMMANDED_ACCELERATION= (acceleration_t)MAT_LIM((sint32)accel_control_data->MINIMUM_COMMANDED_ACCELERATION, (sint32)Acc_min_accel_disengage,            (sint32)accel_control_data->MAX_ALLOWED_ACCEL);
#else
    /*limit to allowed acceleration range*/
    accel_control_data->MAXIMUM_COMMANDED_ACCELERATION= (acceleration_t)MAT_LIM((sint32)accel_control_data->MAXIMUM_COMMANDED_ACCELERATION, (sint32)accel_control_data->MIN_ALLOWED_ACCEL, (sint32)accel_control_data->MAX_ALLOWED_ACCEL);
    accel_control_data->MINIMUM_COMMANDED_ACCELERATION= (acceleration_t)MAT_LIM((sint32)accel_control_data->MINIMUM_COMMANDED_ACCELERATION, (sint32)accel_control_data->MIN_ALLOWED_ACCEL, (sint32)accel_control_data->MAX_ALLOWED_ACCEL);
#endif
  }

#if (FCT_CFG_ACC_HEADWAY_PLANNER || CFG_FCT_FLIM)

  help_accel = MAT_MAX((sint32)accel_control_data->MAXIMUM_COMMANDED_ACCELERATION,MAT_MAX((sint32)cc_control_data->CC_ACCELERATION,(sint32)cc_control_data->MINIMUM_ACCELERATION_LIMIT));
  /* Determine ObjectEffective */
  if (acc_output->DISTANCE_CTRL_ACCEL_MAX < (acceleration_t)help_accel)
  {
    accel_control_data->ACCEL_STATUS.OBJECT_EFFECTIVE = TRUE;
  }
  else
  {
    accel_control_data->ACCEL_STATUS.OBJECT_EFFECTIVE = FALSE;
  }


  if (
      (acc_output->ACC_OUTPUT_STATUS.ALLOW_INIT == TRUE) 
      || 
      (driver_requests->DRIVER_OPERATIONS.CC_DECREASE_SET_SPEED == TRUE)
      ||
      (driver_requests->DRIVER_OPERATIONS.CC_INCREASE_SET_SPEED == TRUE)
      ||
      (accel_control_data->ACCEL_STATUS.LAT_ACCEL_LIM_ACTIVE == TRUE)
      ||
      (driver_requests->CONTROL_STATE == Cc_cc_override)
     )
  {
    accel_control_data->ACCEL_STATUS.ALLOW_INIT = TRUE;
  }
  else
  {
    accel_control_data->ACCEL_STATUS.ALLOW_INIT = FALSE;
  }
#if (CFG_FCT_ALWAYS_ALLOW_INITIALISATION) 
  accel_control_data->ACCEL_STATUS.ALLOW_INIT = TRUE;
#endif 
#endif

}

#if (CFG_FCT_CC_SMOOTH_ACCEL_REQUEST)

/*************************************************************************************************************************
  Functionname:    KMC_v_AccelRequestFiltering                                                                      */ /*!

  @brief           Apply a smoothing filter for the calculated acceleration request

  @description     Apply a smoothing filter for the calculated acceleration request
                   The function is using the information about the current control state for correct initialization.
                   Furthermore, the criticality estimation is used to adjust the filter strength in critical situations.

    @startuml
    Start
    Partition KMC_v_AccelRequestFiltering {
      If (Control_State is \nCc_cc_off)\nOR\nCc_cc_disengage)\nOR\nCc_cc_decel_only\nOR\nCc_cc_ready) then (yes)
        :No Filtering;
      Else (no)
        If (ACC is just activated\nOR\nDRIVE_OFF_CONFIRM == TRUE) then (yes)
          : Special initialisation that \nleads to no filtering;
        Else (no)
          : Filtering done;
          If (CFG_FCT_CC_USE_CONTROL_CRITICALITY) then (yes)
            : PT1 Filter constant dependent \non situation criticality calculated;
          Else (no)
            : Constant PT1 Filter constant;
          Endif
          : Filtering of required acceleration based \non last cycle value and PT1 constant;
        Endif
        : Acceleration request gradient calculated;
        : MINIMUM_REQUESTED_ACCELERATION_FILTERED written;
      Endif
    }
    End
    @enduml

  @return          -

  @param[in]       cycle_time : Task cycle time [0u ... 1000u] ms
  @param[in,out]   *accel_control_data : Acceleration output structure
                        MINIMUM_REQUESTED_ACCELERATION : Current acceleration output [-30000.f ...+30000.f] m/s2 (with factor Acceleration_s)
                        MAXIMUM_REQUESTED_ACCELERATION : Current acceleration output [-30000.f ...+30000.f] m/s2 (with factor Acceleration_s)
                        MINIMUM_REQUESTED_ACCELERATION_LAST_CYCLE : Acceleration output last cycle [-30000.f ...+30000.f] m/s2 (with factor Acceleration_s)
                        MAXIMUM_REQUESTED_ACCELERATION_LAST_CYCLE : Acceleration output last cycle [-30000.f ...+30000.f] m/s2 (with factor Acceleration_s)
                        MINIMUM_REQUESTED_ACCELERATION_FILTERED : Filtered acceleration output [-30000.f ...+30000.f] m/s2 (with factor Acceleration_s)
                        MAXIMUM_REQUESTED_ACCELERATION_FILTERED : Filtered acceleration output [-30000.f ...+30000.f] m/s2 (with factor Acceleration_s)
  @param[in]       driver_requests : Data that reflects the drivers request intention
                        CONTROL_STATE : ACC control state [full range of datatype cc_control_state_t as in cc_ext.h]
                        CONTROL_STATE_LAST_CYCLE : ACC control state last cycle [full range of datatype cc_control_state_t as in cc_ext.h]
  @param[in]       acc_output : ACC output structure
                        SITUATION_CLASS.CRITICALITY : Criticality estimation based on traffic situation [-30000.f ...+30000.f] m/s2 (with factor Acceleration_s)
  @param[in,out]   cc_control_data : Data for the speed control
                        ACCELERATION_REQUEST_GRAD : [Full range of datatype gradient_t as in fct_types.h]

  @glob_in         -
  @glob_out        -

  @c_switch_part   CFG_ACC_LEVER_INPUT : Interface switch for the AccLeverInput_t structure
  @c_switch_part   CFG_FCT_CC_USE_CONTROL_CRITICALITY : Modify the behavior of the longitudinal controller dependent on the criticality esitmation of the traffic situation
  @c_switch_full   CFG_FCT_CC_SMOOTH_ACCEL_REQUEST : Use smoothing filter to prevent small oscillations and other discontinuous waveforms
  @c_switch_full   FCT_CFG_LOPC_COMPONENT : Configuration switch for enabling LOPC processing
  @c_switch_full   FCT_CFG_CC : Configuration switch for enabling CC processing

  @pre             -
  @post            -

  @created         30.05.2016
  @changed         30.05.2016

  @author          Jens Both | jens.both@continental-corporation.com | +49 (8382) 9699-757
*************************************************************************************************************************/
static void KMC_v_AccelRequestFiltering(const times_t cycle_time, cc_acceleration_control_data_t *accel_control_data, const cc_driver_requests_t* driver_requests, const acc_output_data_t* acc_output, const cart_das_input_data_t* das_input, cc_control_data_t* cc_control_data)
{
  sint32 help;
  times_t pt1_filter_constant;
  acceleration_t min_req_accel_last_cycle, max_req_accel_last_cycle;
  acceleration_t min_requested_accel, max_requested_accel;

  if (
      (driver_requests->CONTROL_STATE == Cc_cc_disengage)
      ||
      (driver_requests->CONTROL_STATE == Cc_cc_off)
      ||
      (driver_requests->CONTROL_STATE == Cc_cc_decel_only)
      ||
      (driver_requests->CONTROL_STATE == Cc_cc_ready)
    )
  {
    /* No filtering required */
    accel_control_data->MINIMUM_REQUESTED_ACCELERATION_FILTERED = accel_control_data->MINIMUM_REQUESTED_ACCELERATION;
    accel_control_data->MAXIMUM_REQUESTED_ACCELERATION_FILTERED = accel_control_data->MAXIMUM_REQUESTED_ACCELERATION;
  }
  else
  {
    /* Special initialization to allow jump of accel request with an applied smoothing filter */
    if (
        ((driver_requests->CONTROL_STATE_LAST_CYCLE != driver_requests->CONTROL_STATE)
          &&
          (
            (driver_requests->CONTROL_STATE_LAST_CYCLE == Cc_cc_disengage)
            ||
            (driver_requests->CONTROL_STATE_LAST_CYCLE == Cc_cc_ready)
            ||
            (driver_requests->CONTROL_STATE_LAST_CYCLE == Cc_cc_engage)
            ||
            ((driver_requests->CONTROL_STATE_LAST_CYCLE == Cc_cc_active) && (driver_requests->CONTROL_STATE != Cc_cc_override))
          )
        )
#if (CFG_ACC_LEVER_INPUT)
        ||
        /* Drive off initialization */
        (driver_requests->DRIVER_OPERATIONS.DRIVE_OFF_CONFIRM == TRUE)
#endif
       )
    {
      /* Save last requested acceleration for initialization */
      min_req_accel_last_cycle = accel_control_data->MINIMUM_REQUESTED_ACCELERATION_LAST_CYCLE;
      max_req_accel_last_cycle = accel_control_data->MAXIMUM_REQUESTED_ACCELERATION_LAST_CYCLE;
    }
    else
    {
      /* Save last requested acceleration (filtered)*/
      min_req_accel_last_cycle = accel_control_data->MINIMUM_REQUESTED_ACCELERATION_FILTERED;
      max_req_accel_last_cycle = accel_control_data->MAXIMUM_REQUESTED_ACCELERATION_FILTERED;
    }

    min_requested_accel = accel_control_data->MINIMUM_REQUESTED_ACCELERATION;
    max_requested_accel = accel_control_data->MAXIMUM_REQUESTED_ACCELERATION;

#if (CFG_FCT_CC_USE_CONTROL_CRITICALITY)

    /* Modify the smoothing filter time constant in critical situation to allow quicker reaction */
    pt1_filter_constant = (times_t)MAT_CALCULATE_PARAM_VALUE1D((const sint16*)criticality_accel_filter_time,
                                                                accel_filter_time_time_points,
                                                                (sint16)(acc_output->SITUATION_CLASS.CRITICALITY*Scale_100/Confidence_s));
    /* Modify smoothing filter based on ego speed */
#if (KMC_NO_SMOOTH_JERK_IN_LOW_SPEED)
    if(b_DetectStrongBrakeRelease == TRUE)
    {
      pt1_filter_constant = (times_t)MAT_MUL(pt1_filter_constant, 
                                    (sint32)MAT_CALCULATE_PARAM_VALUE1D(egospeed_accel_filter_time, egospeed_accel_filter_time_points, (sint16)das_input->VEHICLE_SPEED), 
                                    Time_s, Factor_s, Time_s);
    }
#endif
    pt1_filter_constant = (times_t)MAT_MIN((sint32)pt1_filter_constant,(sint32)cc_control_data->CC_ACCEL_FILTER_TIME);
    pt1_filter_constant = (times_t)MAT_MAX((sint32)pt1_filter_constant, MINIMUM_FILTER_CONST);

#else /* CFG_FCT_CC_USE_CONTROL_CRITICALITY */
    _PARAM_UNUSED(acc_output);
    pt1_filter_constant = (times_t)criticality_accel_filter_time[1];
#endif  /* CFG_FCT_CC_USE_CONTROL_CRITICALITY */

    /* Apply filtering */
    min_requested_accel = (acceleration_t) MAT_PT1_FILTER(cycle_time, pt1_filter_constant, (sint32)min_requested_accel, (sint32)min_req_accel_last_cycle);
    max_requested_accel = (acceleration_t) MAT_PT1_FILTER(cycle_time, pt1_filter_constant, (sint32)max_requested_accel, (sint32)max_req_accel_last_cycle);

    /*write gradient of acceleration request */
    help = (sint32)((min_requested_accel-min_req_accel_last_cycle)*(sint32)Factor_s);
    help /= (sint32)cycle_time; 
    cc_control_data->ACCELERATION_REQUEST_GRAD = (gradient_t)help;

    /*write output data */
    accel_control_data->MINIMUM_REQUESTED_ACCELERATION_FILTERED = min_requested_accel;
    accel_control_data->MAXIMUM_REQUESTED_ACCELERATION_FILTERED = max_requested_accel;
  }
  
#if( (CFG_FCT_CC_USE_CONTROL_CRITICALITY == SWITCH_OFF) || (KMC_NO_SMOOTH_JERK_IN_LOW_SPEED == SWITCH_OFF))
  _PARAM_UNUSED(das_input);
#endif
}
#endif /* CFG_FCT_CC_SMOOTH_ACCEL_REQUEST */



#if (CFG_FCT_LIM || CFG_FCT_PLIM)
/*************************************************************************************************************************
  Functionname:    KMC_v_DetermineLimiterAccel                                                                      */ /*!

  @brief           Determine speed limiter acceleration

  @description     Determine CommandedAcceleration for the SpeedLimiter
                   In the "accel mode" or "decel mode"
                   a calibratable level of acceleration/deceleration shall be
                   commanded. Else the commanded acceleration is a function of
                   the difference between VehicleSpeed and SetSpeed.

  @return          -

  @param[in]       input : Pointer to cc_input_data_t type structure containing input data to CC [cc_input_data_t as per cc_ext.h]
                    VEHICLE_STATUS.SPEED_UNIT_KMH : boolean indicating the speed unit, i.e. KMH or MPH [TRUE, FALSE]
  @param[in]       driver_requests : Pointer to driver request input structure [cc_driver_requests_t as per cc_ext.h]
                    LIM_SETSPEED : Current Limiter setspeed [0u ... 255u]
                    SPEEDOMETER_VEHICLE_SPEED : Current speedometer speed with factor Velocity_s [-30000u ... 30000u]
  @param[in,out]   cc_control_data : Pointer to CC control data [cc_control_data_t as per cc_ext.h]
                    LIM_ACCELERATION : Limiter acceleration limit [-30000u ...+30000u] m/s2 (with factor Acceleration_s)

  @glob_in         - 
  @glob_out        - 

  @c_switch_part   -
  @c_switch_full   FCT_CFG_LOPC_COMPONENT : Configuration switch for enabling LOPC processing
  @c_switch_full   FCT_CFG_CC : Configuration switch for enabling CC processing
  @c_switch_full   CFG_FCT_LIM : Configuration switch for enabling limiter function
  @c_switch_full   CFG_FCT_PLIM : Configuration switch for enabling permanent limiter function
*************************************************************************************************************************/
static void KMC_v_DetermineLimiterAccel(const cc_input_data_t* input, const cc_driver_requests_t* driver_requests, cc_control_data_t* cc_control_data)
{
  sint32         delta_speed;
  sint32         limiter_accel;

  delta_speed = (((sint32)driver_requests->LIM_SETSPEED * (sint32)Velocity_s) - (sint32)driver_requests->SPEEDOMETER_VEHICLE_SPEED);
  delta_speed *= (sint32)Factor_s;

  /* Convert to m/s */
  if (input->VEHICLE_STATUS.SPEED_UNIT_KMH == TRUE)
  {
    delta_speed /= (sint32)Speed_conv_factor_kmh;
  }
  else
  {
    delta_speed /= (sint32)Speed_conv_factor_mph;
  }

  limiter_accel = MAT_CALCULATE_PARAM_VALUE1D(Lim_accel_curve, (uint16)Lim_curve_points, (sint16)delta_speed);

  cc_control_data->LIM_ACCELERATION = (acceleration_t)(limiter_accel);

}
#endif


/*************************************************************************************************************************
  Functionname:    KMC_v_DetermineCCAccel                                                                           */ /*!

  @brief           Determine commanded (= unfiltered) acceleration for CruiseControl
                   as a function of the difference between VehicleSpeed
                   and SetSpeed. In the "accel mode" or "decel mode"
                   a calibratable level of acceleration/deceleration shall be
                   commanded.

  @description     Determine commanded (= unfiltered) acceleration for CruiseControl
                   as a function of the difference between VehicleSpeed
                   and SetSpeed. In the "accel mode" or "decel mode"
                   a calibratable level of acceleration/deceleration shall be
                   commanded. The current state machine state is considered.

@startuml
Start
partition KMC_v_DetermineCCAccel(){
: Calculate difference between Vehicle speed \n and set speed as delta speed;
If (speed unit == Km/h) Then (True)
:Delta Speed is converted from Kph into m/s;
Else (false)
: Delta speed is converted to m/s from Mph;
Endif
: Determine commanded acceleration for \n Cruise Control as a function of delta speed;
: Limit Acceleration based on vehicle speed\n;
: In the states of disengage, off, decel only ready,\n the commanded accelration will be set to the default positive value; 
}
End 
@enduml


  @return          -

  @param[in]       input : Pointer to cc_input_data_t type structure containing input data to CC [cc_input_data_t as per cc_ext.h]
                    VEHICLE_STATUS.SPEED_UNIT_KMH : boolean indicating the speed unit, i.e. KMH or MPH [TRUE, FALSE]
  @param[in]       das_input : Driver assistant system input structure [cart_das_input_data_t as per cart_ext.h]
                    VEHICLE_SPEED : Ego speed with factor Velocity_s [-30000u ... 30000u] cm/s 
  @param[in]       driver_requests : Driver request input structure [cc_driver_requests_t as per cc_ext.h]
                    DRIVER_OPERATIONS.ACCEL_MODE : Boolean indicating if acceleration with constant value [TRUE, FALSE]
                    DRIVER_OPERATIONS.DECEL_MODE : Boolean indicating if deceleration with constant value [TRUE, FALSE]
                    SPEEDOMETER_VEHICLE_SPEED : Current speedometer speed [-30000u ... 30000u]
                    MAX_CC_SETSPEED : Maximal Cruise Control set speed [0u ... 255u]
                    MIN_CC_SETSPEED : Minimal Cruise Control set speed [0u ... 255u]
                    CC_SETSPEED : Current Cruise Control set speed [0u ... 255u]
                    CC_SETSPEED_CUSTOM : Custom cruise control set speed [0u ... 255u]
                    SPEEDOMETER_VEHICLE_SPEED_OFFSET : Offset compensated speedometer speed [-30000u ... 30000u]
                    DRIVER_REQUEST_STATUS.TIMED_INCREMENT : Boolean if constant increasing of set speed [TRUE, FALSE]
                    DRIVER_REQUEST_STATUS.TIMED_DECREMENT : Boolean if constant decreasing of set speed [TRUE, FALSE]
                    CONTROL_STATE : Current state of the longitudinal control state machine [full range of datatype cc_control_state_t as in cc_ext.h]
  @param[in,out]   cc_control_data : Cruise control data structure [cc_control_data_t as per cc_ext.h]
                    MINIMUM_ACCELERATION_LIMIT : Minimal allowed cruise control acceleration [-30000u...+30000u] m/s2 (with factor Acceleration_s)
                    MAXIMUM_ACCELERATION_LIMIT : Maximal allowed cruise control acceleration [-30000u ...+30000u] m/s2 (with factor Acceleration_s)
                    CC_ACCELERATION : Current cruise control acceleration [-30000u ...+30000u] m/s2 (with factor Acceleration_s)

  @glob_in         -
  @glob_out        -

  @c_switch_part   CFG_FCT_USE_ACCEL_GAIN : use accel gain functionality for acceleration low speed range
  @c_switch_part   CFG_FCT_CC_USE_ACCEL_DECEL_MODE : Use a special accel/decel mode where a specific acceleration request is used as long as the driver wants so
  @c_switch_full   FCT_CFG_LOPC_COMPONENT : Configuration switch for enabling LOPC processing
  @c_switch_full   FCT_CFG_CC : Configuration switch for enabling CC processing

  @pre             -
  @post            -

  @created         -
  @changed         07.04.2016

  @author          Simon Sinnstein | simon.sinnstein@continental-corporation.com | +49 (8382) 9699-160
*************************************************************************************************************************/
static void KMC_v_DetermineCCAccel(const cc_input_data_t* input, const cart_das_input_data_t* das_input, const cc_driver_requests_t* driver_requests, cc_control_data_t* cc_control_data)
{
  sint32         delta_speed;
  sint32         set_speed;
  sint32         cruise_accel;
#if (CFG_FCT_USE_ACCEL_GAIN)
  sint32         help_qoud, help_accel,accel_gain,accel_quod;
#endif

#if (CFG_FCT_CC_USE_ACCEL_DECEL_MODE)

  if (driver_requests->DRIVER_OPERATIONS.ACCEL_MODE == TRUE)
  {
    set_speed = Cc_accelmode_delta;
  }
  else
  {
    if (driver_requests->DRIVER_OPERATIONS.DECEL_MODE == TRUE)
    {
      set_speed = Cc_decelmode_delta;
    }
    else
    {
      set_speed = (sint32)0;
    }
  }
  if (input->VEHICLE_STATUS.SPEED_UNIT_KMH == TRUE)
  {
    set_speed *= (sint32)Speed_conv_factor_kmh;
  }
  else
  {
    set_speed *= (sint32)Speed_conv_factor_mph;
  }
  set_speed /= (sint32)Factor_s;
  set_speed += (sint32)driver_requests->SPEEDOMETER_VEHICLE_SPEED;
  set_speed *= (sint32)(Setspeed_s);
  set_speed /= (sint32)(Speedo_speed_s);
  set_speed = MAT_MIN(driver_requests->MAX_CC_SETSPEED, set_speed);
  set_speed = MAT_MAX(driver_requests->MIN_CC_SETSPEED, set_speed);
#else
  set_speed = (sint32)driver_requests->CC_SETSPEED;
#endif

  /*use  speedometer_vehicle_speed_offset for delta_speed_calculation*/
  delta_speed = ((set_speed * (sint32)Velocity_s) - (sint32)driver_requests->SPEEDOMETER_VEHICLE_SPEED_OFFSET);

#if (LONG_CFG_USE_EXTERN_ACC_STATE_MACHINE && FCT_LONG_CTRL_INPUT_INTFVER > 18)
  /* Use external set speed with higher resolution, requires new interface version.
     Signal to be mapped within FCT_LONG_VEH_PROCESS_EXTERNAL_ACC_INTERFACES() */
  delta_speed = ((sint32)(driver_requests->CC_SETSPEED_CUSTOM) - (sint32)driver_requests->SPEEDOMETER_VEHICLE_SPEED_OFFSET);
#endif

  delta_speed *= (sint32)Factor_s;

  /* Convert to m/s */
  if (input->VEHICLE_STATUS.SPEED_UNIT_KMH == TRUE)
  {
    delta_speed /= (sint32)Speed_conv_factor_kmh;
  }
  else
  {
    delta_speed /= (sint32)Speed_conv_factor_mph;
  }

  /* Determine cc acceleration depending on differential velocity (Look up table) */
  cruise_accel = MAT_CALCULATE_PARAM_VALUE1D(Cc_accel_curve, (uint16)Cc_curve_points, (sint16)delta_speed);


  /*Modify cruise acceleration in low speed range*/
#if (CFG_FCT_USE_ACCEL_GAIN)

  accel_gain = MAT_CALCULATE_PARAM_VALUE1D(Cc_accel_gain_curve, (uint16)Cc_accel_gain_curve_points, das_input->VEHICLE_SPEED);

  if (
      (accel_gain >= Cc_accel_limit)
      &&
      (Cc_accel_limit > 0)
      &&
      (cruise_accel > 0)
     )
  {
    help_qoud = cruise_accel;
    help_qoud *= Factor_s;
    help_qoud /= Cc_accel_limit;

    help_accel = Factor_s;
    help_accel -= help_qoud;
    help_accel *= accel_gain;
    help_accel /= Acceleration_s;
    help_accel += help_qoud;

    accel_quod = Factor_s;
    accel_quod = MAT_DIV(accel_quod, help_accel, Factor_s, Factor_s, Factor_s);
      
    cruise_accel *= accel_gain;
    cruise_accel /= Acceleration_s;
    cruise_accel *= accel_quod;
    cruise_accel /= Factor_s;
  }
#endif

  /*limit cruise acceleration over the velocity dependent on vehicle characteristics */
  cc_control_data->MINIMUM_ACCELERATION_LIMIT = Cc_decel_limit;
  cc_control_data->MAXIMUM_ACCELERATION_LIMIT = MAT_CALCULATE_PARAM_VALUE1D(Cc_max_accel_curve,(uint16)Cc_max_accel_curve_points, das_input->VEHICLE_SPEED);

  cruise_accel = MAT_LIM(cruise_accel, (sint32)cc_control_data->MINIMUM_ACCELERATION_LIMIT, (sint32)cc_control_data->MAXIMUM_ACCELERATION_LIMIT);

  cc_control_data->CC_ACCELERATION = (acceleration_t)(cruise_accel);
  
  if (driver_requests->DRIVER_REQUEST_STATUS.TIMED_INCREMENT == TRUE)
  {
    cc_control_data->CC_ACCELERATION = (acceleration_t)MAT_MAX((sint32)cc_control_data->CC_ACCELERATION, (sint32)Cc_max_decel_during_accel_mode);
  }
  else
  {
    if (driver_requests->DRIVER_REQUEST_STATUS.TIMED_DECREMENT == TRUE)
    {
      cc_control_data->CC_ACCELERATION = (acceleration_t)MAT_MIN((sint32)cc_control_data->CC_ACCELERATION, (sint32)Cc_max_accel_during_decel_mode);
    }
  }
  if (
      (driver_requests->CONTROL_STATE == Cc_cc_disengage)
      ||
      (driver_requests->CONTROL_STATE == Cc_cc_off)
      ||
      (driver_requests->CONTROL_STATE == Cc_cc_decel_only)
      ||
      (driver_requests->CONTROL_STATE == Cc_cc_ready)
    )
  {
    cc_control_data->CC_ACCELERATION = MAT_CALCULATE_PARAM_VALUE1D(Cc_max_accel_curve,(uint16)Cc_max_accel_curve_points, (sint16)driver_requests->MIN_CC_SETSPEED);
  }
}

#if (FCT_CFG_SLA_FEATURE)

/*************************************************************************************************************************
  Functionname:    KMC_t_DetermSLACtrlDistBeforeLimit                                                               */ /*!

  @brief           Control distance calculation for SLA speeds

  @description     Based on type of reaction expected to SLA speed limit sign, 
                   distance to be used for the control of speed is calculated. 
@startuml
Start
Partition KMC_t_DetermSLACtrlDistBeforeLimit(){
If (Speed limit Information is available before Speed Limit is reached) Then (True)
:Calculate relevant Before Distance based on vehicle speed; 
Else (false)
: set the before distance to zero;
Endif
}
End
@enduml

  @return          The control distance before the speed limit sign [0u ... 65530u]m (with factor Scale_10)

  @param[in]       SLA_SpeedLimit : Pointer to input data structure for SLA speed limit [t_SLA_SpeedLimit as per cc_ext.h]
                    SLA_SpeedLimit->SpeedLimitType.b_SLA_CONTROL_AFTER_LIMIT : Type of reaction to speed limit [TRUE, FALSE]
                    SLA_SpeedLimit->SpeedLimitType.b_SLA_CONTROL_BEFOR_LIMIT : Type of reaction to speed limit [TRUE, FALSE]
                    SLA_SpeedLimit->u_SpeedLimitDistance : Current distance to SLA speed limit sign [0u ... 65530u]m (with factor Scale_10)
                    SLA_SpeedLimit->u_SpeedLimit : Speed of SLA speed limit [0u ... 255u]

  @param[in]       vehicle_speed : Speed of ego vehicle with factor Velocity_s [-30000u ... 30000u] cm/s

  @param[in]       driver_requests : Pointer to driver request input structure [cc_driver_requests_t as per cc_ext.h]
                    driver_requests->SPEEDOMETER_VEHICLE_SPEED : Current speedometer speed with factor Velocity_s [-30000u ... 30000u]

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_SLA_FEATURE : Switch for enabling SLA Support functions
  @c_switch_full   FCT_CFG_LOPC_COMPONENT : Configuration switch for enabling LOPC processing
  @c_switch_full   FCT_CFG_CC : Configuration switch for enabling CC processing

  @created         15.06.2016
  @changed         15.06.2016
  @traceability    doors://rbgs854a:40000/?version=2&prodID=0&view=00000002&urn=urn:telelogic::1-503e822e5ec3651e-O-152-0008a220
  @author          Simon Sinnstein | simon.sinnstein@continental-corporation.com | +49 (8382) 9699-160
*************************************************************************************************************************/
t_u_DistanceLong KMC_t_DetermSLACtrlDistBeforeLimit(const t_SLA_SpeedLimit* SLA_SpeedLimit,
                                                    const velocity_t vehicle_speed,
                                                    const cc_driver_requests_t* driver_requests)
{
  sint32 help_var;

  if(SLA_SpeedLimit->SpeedLimitType.b_SLA_CONTROL_BEFOR_LIMIT == TRUE)
  {
    if(SLA_SpeedLimit->SpeedLimitType.b_SLA_CONTROL_AFTER_LIMIT == TRUE)
    {
      if(driver_requests->SPEEDOMETER_VEHICLE_SPEED > (SLA_SpeedLimit->u_SpeedLimitIncOffset * Speedo_speed_s)) /* Deceleration case */
      {
        help_var = MAT_CALCULATE_PARAM_VALUE1D(Cc_sla_ctrl_dist_befor_limit_decel, Cc_sla_ctrl_dist_befor_limit_decel_points, vehicle_speed);
      }
      else /* Acceleration case */
      {
        help_var = MAT_CALCULATE_PARAM_VALUE1D(Cc_sla_ctrl_dist_befor_limit_accel, Cc_sla_ctrl_dist_befor_limit_accel_points, vehicle_speed);
      }
      /* conversion from type distance_t to t_u_DistanceLong is needed */
      help_var = help_var / (sint32)Scale_10;
    }
    else
    {
      /*! then control befor speed limit is required */
      help_var = SLA_SpeedLimit->u_SpeedLimitDistance;
    }
  }
  else
  {
    help_var = 0u;
  }

  return (t_u_DistanceLong)help_var;
}

/*************************************************************************************************************************
  Functionname:    KMC_t_DetermSLACtrlDistAfterLimit                                                                */ /*!

  @brief           Control distance calculation for SLA speeds

  @description     Based on type of reaction expected to SLA speed limit sign, 
                   distance to be used for the control of speed is calculated.

@startuml
Start
Partition KMC_t_DetermSLACtrlDistAfterLimit(){
If (Possible to Control after passing Speed Limit Sign) Then (True)
    If (Vehicle Speed is greater than speed Limit ) Then (True)
    : control Distance calculated based on Vehicle Speed;
    Else (False)
    : Control Distance is zero;
    endif
Else (false)
: Control Distance as zero;
Endif
}
End
@enduml

  @return          The control distance after the speed limit sign [0 ... 65530]m (with factor Scale_10)

  @param[in]       SLA_SpeedLimit : Pointer to input data structure for SLA speed limit [t_SLA_SpeedLimit as per cc_ext.h]
                    SLA_SpeedLimit->SpeedLimitType.b_SLA_CONTROL_AFTER_LIMIT : Type of reaction to speed limit [TRUE, FALSE]
                    SLA_SpeedLimit->SpeedLimitType.b_SLA_CONTROL_BEFOR_LIMIT : Type of reaction to speed limit [TRUE, FALSE]
                    SLA_SpeedLimit->u_SpeedLimitDistance : Current distance to SLA speed limit sign [0u ... 65530u]m (with factor Scale_10)
                    SLA_SpeedLimit->u_SpeedLimitIncOffset : Speed of SLA speed limit [0u ... 255u]

  @param[in]       vehicle_speed : Speed of ego vehicle with factor Velocity_s [-30000u ... 30000u] cm/s
   
  @param[in]       driver_requests : Pointer to driver request input structure [cc_driver_requests_t as per cc_ext.h]
                    driver_requests->SPEEDOMETER_VEHICLE_SPEED : Current speedometer speed with factor Velocity_s [-30000u ... 30000u]

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_SLA_FEATURE : Switch for enabling SLA Support functions
  @c_switch_full   FCT_CFG_LOPC_COMPONENT : Configuration switch for enabling LOPC processing
  @c_switch_full   FCT_CFG_CC : Configuration switch for enabling CC processing

  @created         15.06.2016
  @changed         15.06.2016
  @traceability    doors://rbgs854a:40000/?version=2&prodID=0&view=00000002&urn=urn:telelogic::1-503e822e5ec3651e-O-153-0008a220
  @author          Simon Sinnstein | simon.sinnstein@continental-corporation.com | +49 (8382) 9699-160
*************************************************************************************************************************/
t_u_DistanceLong KMC_t_DetermSLACtrlDistAfterLimit(const t_SLA_SpeedLimit* SLA_SpeedLimit,
                                                         const velocity_t vehicle_speed,
                                                         const cc_driver_requests_t* driver_requests)
{
  sint32 help_var;

  /* calculate control distances befor and after the traffic sign */
  if(SLA_SpeedLimit->SpeedLimitType.b_SLA_CONTROL_AFTER_LIMIT == TRUE)
  {
    if(driver_requests->SPEEDOMETER_VEHICLE_SPEED > (SLA_SpeedLimit->u_SpeedLimitIncOffset * Speedo_speed_s)) /* Deceleration case */
    {
      help_var = MAT_CALCULATE_PARAM_VALUE1D(Cc_sla_ctrl_dist_after_limit, Cc_sla_ctrl_dist_after_limit_points, vehicle_speed);
      help_var = help_var / (sint32)Scale_10;
    }
    else /* Acceleration case */
    {
      help_var = 0u;
    }
  }
  else
  {
    /*! then control befor speed limit is required */
    help_var = 0u;
  }

  return (t_u_DistanceLong)help_var;
}

/*************************************************************************************************************************
  Functionname:    KMC_t_CalculateSLAAccel                                                                          */ /*!

  @brief           Calculation of SLA speedlimit Acceleration

  @description     Acceleration required to achieve SLA speed limit is calculated 
                   based on distance to speed limit sign and current velocity.

@startuml
Start
Partition KMC_t_CalculateSLAAccel(){
: Calculation of SLA speed limit Acceleration;
If (vehicle Speed is greater than SLA Speed Limit) Then (True)
: Calculate deceleration to achieve SLA Speed Limit;
: Deceleration = (V^2 – U^2)/ (2*S);
Else  (False)
: Calculate Acceleration Request as zero;
endif
}
End
@enduml


  @return          Required SLA acceleration for given SLA speed limit [-30000u ...+30000u] m/s2 (with factor Acceleration_s)

  @param[in]       b_SpeedUnit_KMH : Boolean indicating the unit of SLA speed limit of KPH or MPH [TRUE, FALSE]
  @param[in]       vehicle_speed : Ego speed [-30000u ... 30000u] cm/s
  @param[in]       sla_ctrl_distance : Control distance required for calculation of SLA acceleration [0 ... 65530]m (with factor Scale_10)
  @param[in]       SpeedLimit : SLA speed limit to be attained [0u ... 255u]
  @param[in]       driver_requests : Pointer to driver request input structure [cc_driver_requests_t as per cc_ext.h]
                    driver_requests->SPEEDOMETER_VEHICLE_SPEED : Current speedometer speed with factor Velocity_s [-30000u ... 30000u]

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_SLA_FEATURE : Switch for enabling SLA Support functions
  @c_switch_full   FCT_CFG_LOPC_COMPONENT : Configuration switch for enabling LOPC processing
  @c_switch_full   FCT_CFG_CC : Configuration switch for enabling CC processing

  @created         15.06.2016
  @changed         15.06.2016

  @traceability    doors://rbgs854a:40000/?version=2&prodID=0&view=00000002&urn=urn:telelogic::1-503e822e5ec3651e-O-154-0008a220
  @author          Simon Sinnstein | simon.sinnstein@continental-corporation.com | +49 (8382) 9699-160
*************************************************************************************************************************/
acceleration_t KMC_t_CalculateSLAAccel(const boolean b_SpeedUnit_KMH,
                                      const velocity_t vehicle_speed,
                                      const setspeed_t SpeedLimit,
                                      const t_u_DistanceLong sla_ctrl_distance,
                                      const cc_driver_requests_t* driver_requests)
{
  sint32 help_var;

 /* Calculate SLA support function request */
  if(driver_requests->SPEEDOMETER_VEHICLE_SPEED > (SpeedLimit * Speedo_speed_s)) /* Deceleration case */
  {
    /* calculate deceleration request */
    if (b_SpeedUnit_KMH == TRUE)
    {
      /*! unit KMH */
      help_var = (sint32)SpeedLimit * (sint32)Factor_s * (sint32)Velocity_s;
      help_var /= (sint32)Speed_conv_factor_kmh;
    }
    else
    {
      /*! unit MPH */
      help_var = (sint32)SpeedLimit * (sint32)Factor_s * (sint32)Velocity_s;
      help_var /= (sint32)Speed_conv_factor_mph;
    }
    /* Add Formel */
    help_var *= help_var;
    help_var -= (sint32)(vehicle_speed * vehicle_speed);
    help_var *= Scale_10;
    help_var /= Velocity_s;
    help_var /= (sint32)(2*MAT_MAX((sla_ctrl_distance), Scale_10));
    help_var *= (sint32)Acceleration_s;
    help_var /= (sint32)Velocity_s;
  }
  else /* acceleration case */
  {
    /* calculate acceleration request */
    /* no requirements regarding calculating of positive acceleration request known */
    help_var = 0;
  }

  return (acceleration_t)MAT_LIM(help_var, Accel_min, Accel_max);
}



/*************************************************************************************************************************
  Functionname:    KMC_v_DetermineSLAAccel                                                                          */ /*!

  @brief           Determination of SLA accleration

  @description     SLA acceleration is determined based on the speed limit and distance inputs.
                   Required acceleration is calculated for new speed limits or for the existing speed limit. 
                   The distance used for calculation for acceleration is determined via functions 
                   KMC_t_DetermSLACtrlDistBeforeLimit and KMC_t_DetermSLACtrlDistAfterLimit. The acceleration
                   values are limited to the velocity dependent allowed limits. Acceleration requests are arbitrated
                   in case of receival of two speed limits, taking the lower acceleration request.

@startuml
Start
Partition KMC_v_DetermineSLAAccel(){
: Limit deceleration request according to customer requirements;
If (New Speed Limit is accepted) Then (True)
: Determine control distance for calulation of SLA request;
    If(Speed Limit have to be achieved before limit) Then (True)
       If (SLA Accel request is less than decel Limit) Then (True)
        : Start SLA request;
        endif
     Else(False)
            If (Speed Limit to be achieved only after speed limit) Then (True)
            : Start SLA request;
            Else(false)
            :Speed Limit will be achieved after and before Speed Limit;
                If (SLA Speed Limit Distance is less than Control Distance)
                   : Process SLA Request;
                 Endif
            Endif
        :SLA request is accepted;
        If (SLA Request is accepted) Then (True)
          :save last Set Speed;
            If (driver request Speed is greater than Set Speed) Then (True)
            : LastSpeedforTakeover is set as CC_SetSpeed;
            Else (false)
            :last Speed for takeover is set as Actual Speed Limit;
            endif
            : set the new set speed;
            If( SLA Accelrequest is less than 0) Then (True)
            : Deceleration is calculated;
            

             Else (false)
             : Acceleration is set as 0;
             Endif
         Endif
     Endif
Else (false)
     If (SLA is in Active mode) Then (True)
       If (if new Speed Limit Sign is present) Then (true)
       : Caluclate new SLA Request each cycle and update the SLA Request;
       endif    
       If (Decision from SLA request to Normal Crusie Control is Accepted) Then (True)
       : Parameters Cc_sla_goto_cruise_decel_speedo_speed,\n Cc_sla_goto_cruise_accel_speedo_speed define when the \n swap to cruise control request have to be done;
       : Deceleration case is applied in either of below two cases;
                If (Vehicle Sttaus speed Unit is Kmh) Then (True)
                : Deceleration case is calculated by subtracting Vehicle Speed\n and SLA Speed in Kmh and should not greatr than deceleration Limit;
                Else(false)
                :Deceleration case is calculated by subtracting Vehicle Speed\n and SLA Speed in mph and should not greatr than deceleration Limit;
                Endif
        Else (false) 
              If (speed unit is Kmh) Then (True)
              : Acceleration case is applied by by subtracting Vehicle Speed\n and SLA Speed in Kmh and should not greatr than deceleration Limit;
              Else (false)
              : Deceleration case is calculated by subtracting Vehicle Speed\n and SLA Speed in mph and should not greatr than deceleration Limit;
              endif
        Endif
        If ( Acccel request is granted as false) Then (True)
        : Set Accelration as zero;
        Else (false)
          If (during a SLA request , New Speed Limit is Available) Then (true)
             If (SLA Control before limit is set as false) Then (true)
             : SLA Request Granted as false;
             Else (false)
             : Determine Control Distance for calculation\n of SLA Request for new Speed limit;
             : Calculation of SLA Request for new speed limit;
             : Determine the control distance befor the speed limit\n for arbitration of speed limits;
                 If (Arbitration Conditions possible) Then(true)
                 : Stop the Existing SLA request and go to New Speed limit;
                 Endif
              Endif
          Endif
        Endif
       If (CC Set speed is not euqal to SLA Control Speed) Then (true)
       : SLA No Longer Accepted;
       Endif
   Else (false)
      : SLA ACCEL Request granted is set as false;
      : Acceleration is set zero;
   Endif
Endif    
}
End
@enduml


  @return          -

  @param[in]       input : Pointer to CC input interface [cc_input_data_t as per cc_ext.h]
                    input->VEHICLE_STATUS.SPEED_UNIT_KMH: boolean indicating the speed unit, i.e. KMH or MPH [TRUE, FALSE]
                    input->SLA_INPUT_DATA.SLA_InputStatus.b_SLA_NEW_SPEED_AVAILABLE : boolean indicating if new valid speed limit available [TRUE, FALSE]
                    input->SLA_INPUT_DATA.SLA_InputStatus.b_SLA_SPEED_ACCEPTED : boolean indicating if the new speed limit was accepted [TRUE, FALSE]
                    input->SLA_INPUT_DATA.SLA_SpeedLimit : Input struct of SLA speed limit [t_SLA_SpeedLimit as per cc_ext.h]
                    input->SLA_INPUT_DATA.SLA_SpeedLimit.u_SpeedLimit : Speed limit after wrapper [0u ... 255u]
                    input->SLA_INPUT_DATA.SLA_SpeedLimit.SpeedLimitType.b_SLA_CONTROL_BEFOR_LIMIT : Type of reaction to speed limit [TRUE, FALSE]
                    input->SLA_INPUT_DATA.SLA_SpeedLimit.SpeedLimitType.b_SLA_CONTROL_AFTER_LIMIT : Type of reaction to speed limit [TRUE, FALSE
                    input->SLA_INPUT_DATA.SLA_SpeedLimit.u_SpeedLimitDistance : Speed limit distance after wrapper [0u ... 65530u]m (with factor Scale_10)

  @param[in]       das_input : Pointer to input from longitudinal dynamics management to driver assistance system [cart_das_input_data_t as per cart_ext.h]
                    das_input->VEHICLE_SPEED : Ego speed with factor Velocity_s [-30000u ... 30000u] cm/s 
  @param[in,out]   driver_requests : Pointer to driver request input structure [cc_driver_requests_t as per cc_ext.h]
                    driver_requests->CC_SETSPEED : Current Cruise Control set speed [0u ... 255u]
                    driver_requests->SPEEDOMETER_VEHICLE_SPEED : Current speedometer speed with factor Velocity_s [-30000u ... 30000u]
                    driver_requests->SPEEDOMETER_VEHICLE_SPEED_OFFSET : Offset compensated speedometer speed [-30000u... 30000u]
  
  @param[in,out]   cc_sla_hmi_data : Pointer to data struct SLA HMI [t_SLA_HMI_Data as per cc_ext.h]
                    cc_sla_hmi_data->u_SLA_LastSetSpeedForTakeOver : Last set speed changed by SLA Function [0u ... 255u]
                    cc_sla_hmi_data->e_SLA_State : State of SLA state machine [t_e_SLA_State as per cc_ext.h]
                    cc_sla_hmi_data->SLA_SpeedLimitActualAccepted : Data struct accepted SLA speed limit [t_SLA_SpeedLimit as per cc_ext.h]
                    cc_sla_hmi_data->u_SLA_SpeedLimitActualAccepted.u_SpeedLimit : Accepted speed limit [0u ... 255u]
                    cc_sla_hmi_data->u_SLA_SpeedLimitActualAccepted.SpeedLimitType.b_SLA_CONTROL_BEFOR_LIMIT : Type of reaction to speed limit [TRUE, FALSE]
                    cc_sla_hmi_data->u_SLA_SpeedLimitActualAccepted.SpeedLimitType.b_SLA_CONTROL_AFTER_LIMIT : Type of reaction to speed limit [TRUE, FALSE]
                    cc_sla_hmi_data->u_SLA_SpeedLimitActualAccepted.u_SpeedLimitDistance : Accepted speed limit distance [0u ... 65530u]m (with factor Scale_10)

  @param[in,out]   cc_sla_ctrl_data : Pointer to data struct SLA control [t_SLA_Ctrl_Data as per cc_ext.h]
                    cc_sla_ctrl_data->SLA_CtrlState.SLA_ACCEL_REQUEST_GRANTED : Boolean indicating if SLA acceleration request granted [TRUE, FALSE]
                    cc_sla_ctrl_data->s_SlaCtrlAccelRequest : SLA acceleration request [-30000u ...+30000u] m/s2 (with factor Acceleration_s)

  @glob_in         - 
  @glob_out        - 

  @c_switch_part   -
  @c_switch_full   FCT_CFG_SLA_FEATURE : Switch for enabling SLA Support finctions
  @c_switch_full   FCT_CFG_LOPC_COMPONENT : Configuration switch for enabling LOPC processing
  @c_switch_full   FCT_CFG_CC : Configuration switch for enabling CC processing

  @pre             -
  @post            -

  @created         08.06.2016
  @changed         08.06.2016

  @author          Simon Sinnstein | simon.sinnstein@continental-corporation.com | +49 (8382) 9699-160
*************************************************************************************************************************/
static void KMC_v_DetermineSLAAccel(const cc_input_data_t* input, const cart_das_input_data_t* das_input,
                                    cc_driver_requests_t* driver_requests,
                                    t_SLA_HMI_Data* cc_sla_hmi_data, t_SLA_Ctrl_Data* cc_sla_ctrl_data)
{
  t_u_DistanceLong u_SlaCtrlDistance;
  acceleration_t s_SlaMinDecelLimit, s_SlaMaxDecelLimit, s_SlaAccelRequest;
  boolean help_condition;

  /* Limit deceleration request according requerements */
  s_SlaMaxDecelLimit = MAT_CALCULATE_PARAM_VALUE1D(Cc_sla_max_decel_limit, Cc_sla_max_decel_limit_points, das_input->VEHICLE_SPEED);
  s_SlaMinDecelLimit = MAT_CALCULATE_PARAM_VALUE1D(Cc_sla_min_decel_limit, Cc_sla_min_decel_limit_points, das_input->VEHICLE_SPEED);

  u_SlaCtrlDistance = 0u;
  s_SlaAccelRequest = (acceleration_t)0;

  /* if new speed limit accepted */
  if(cc_sla_hmi_data->e_SLA_State == SLA_STATE_ACCEPTED)
  {
    /* Determin control distance for calulation of SLA request */
    u_SlaCtrlDistance = KMC_t_DetermSLACtrlDistBeforeLimit(&cc_sla_hmi_data->SLA_SpeedLimitActualAccepted,
                                                                das_input->VEHICLE_SPEED,
                                                                driver_requests);
    u_SlaCtrlDistance += KMC_t_DetermSLACtrlDistAfterLimit(&cc_sla_hmi_data->SLA_SpeedLimitActualAccepted,
                                                                 das_input->VEHICLE_SPEED,
                                                                 driver_requests);

    /* Calculation SLA request */
    s_SlaAccelRequest = KMC_t_CalculateSLAAccel(input->VEHICLE_STATUS.SPEED_UNIT_KMH, das_input->VEHICLE_SPEED,
                                               cc_sla_hmi_data->SLA_SpeedLimitActualAccepted.u_SpeedLimitIncOffset, u_SlaCtrlDistance, driver_requests);

    /* Decision if the reaction have to be started, custom part? */
    /* if the speed limit have to be achieved befor limit */
    if(cc_sla_hmi_data->SLA_SpeedLimitActualAccepted.SpeedLimitType.b_SLA_CONTROL_AFTER_LIMIT == FALSE)
    {
      if((s_SlaAccelRequest <= s_SlaMaxDecelLimit)||(u_SlaCtrlDistance == 0u))
      {
        /* start SLA request */
        cc_sla_ctrl_data->SLA_CtrlState.SLA_ACCEL_REQUEST_GRANTED = TRUE;
      }
    }
    else
      /* if the speed limit have to be achieved only after limit */
      if(cc_sla_hmi_data->SLA_SpeedLimitActualAccepted.SpeedLimitType.b_SLA_CONTROL_BEFOR_LIMIT == FALSE)
      {
        /* start SLA request */
        cc_sla_ctrl_data->SLA_CtrlState.SLA_ACCEL_REQUEST_GRANTED = TRUE;
      }
      else
      {
        u_SlaCtrlDistance = KMC_t_DetermSLACtrlDistBeforeLimit(&cc_sla_hmi_data->SLA_SpeedLimitActualAccepted,
                                                                    das_input->VEHICLE_SPEED,
                                                                    driver_requests);

        /* if the speed limit have to be achieved befor and after limit */
        if(cc_sla_hmi_data->SLA_SpeedLimitActualAccepted.u_SpeedLimitDistance < u_SlaCtrlDistance)
        {
          /* start SLA request */
          cc_sla_ctrl_data->SLA_CtrlState.SLA_ACCEL_REQUEST_GRANTED = TRUE;
        }
      }

      /* SLA request granted */
      if(cc_sla_ctrl_data->SLA_CtrlState.SLA_ACCEL_REQUEST_GRANTED == TRUE)
      {
        /* save last set speed */
        if(driver_requests->CC_SETSPEED > (setspeed_t)0)
        {
          cc_sla_hmi_data->u_SLA_LastSetSpeedForTakeOver = driver_requests->CC_SETSPEED;
        }
        else
        {
          cc_sla_hmi_data->u_SLA_LastSetSpeedForTakeOver = cc_sla_hmi_data->SLA_SpeedLimitActualAccepted.u_SpeedLimitIncOffset;
        }
        /* set the new setspeed */
        driver_requests->CC_SETSPEED = cc_sla_hmi_data->SLA_SpeedLimitActualAccepted.u_SpeedLimitIncOffset;
        /* set the SLA request */
        if(s_SlaAccelRequest < (acceleration_t)0)
        {
          /* if deceleration calculated */
          cc_sla_ctrl_data->s_SlaCtrlAccelRequest = (acceleration_t)MAT_LIM(s_SlaAccelRequest, s_SlaMinDecelLimit, s_SlaMaxDecelLimit);
        }
        else
        {
          /* in acceleration case provide 0 aceleration at the moment */
          cc_sla_ctrl_data->s_SlaCtrlAccelRequest = (acceleration_t)0;
        }
      }
  } /* end if(cc_sla_hmi_data->e_SLA_State == SLA_STATE_ACCEPTED) */
  else
  {
    if(cc_sla_hmi_data->e_SLA_State == SLA_STATE_APPLIED)
    {
      if(cc_sla_hmi_data->SLA_SpeedLimitActualAccepted.u_SpeedLimitDistance > 0u)
      {
        /* if the speed limit steel in front, caculate the new SLA request each cycle */
        u_SlaCtrlDistance = KMC_t_DetermSLACtrlDistAfterLimit(&cc_sla_hmi_data->SLA_SpeedLimitActualAccepted,
                                                                    das_input->VEHICLE_SPEED,
                                                                    driver_requests);

        u_SlaCtrlDistance += cc_sla_hmi_data->SLA_SpeedLimitActualAccepted.u_SpeedLimitDistance;

        s_SlaAccelRequest = KMC_t_CalculateSLAAccel(input->VEHICLE_STATUS.SPEED_UNIT_KMH, das_input->VEHICLE_SPEED,
                                                 cc_sla_hmi_data->SLA_SpeedLimitActualAccepted.u_SpeedLimitIncOffset, u_SlaCtrlDistance, driver_requests);
        /* Update the SLA request */
        cc_sla_ctrl_data->s_SlaCtrlAccelRequest = (acceleration_t)MAT_LIM(s_SlaAccelRequest, s_SlaMinDecelLimit, s_SlaMaxDecelLimit);
      }

      /* Decision to swap from SLA request to normal cruise contol
      The parameters Cc_sla_goto_cruise_decel_speedo_speed, Cc_sla_goto_cruise_accel_speedo_speed define when the swap to cruise control request have to be done
      If the parameters Cc_sla_goto_cruise_decel_speedo_speed, Cc_sla_goto_cruise_accel_speedo_speed will be big enough like 200, only cruise control request will be used */
      if((cc_sla_hmi_data->SLA_SpeedLimitActualAccepted.u_SpeedLimitIncOffset * Speedo_speed_s) < driver_requests->SPEEDOMETER_VEHICLE_SPEED)
      {
        /* Deceleration case */
        if(input->VEHICLE_STATUS.SPEED_UNIT_KMH == TRUE)
        {
          help_condition = ((setspeed_t)MAT_ABS((setspeed_t)(driver_requests->SPEEDOMETER_VEHICLE_SPEED_OFFSET/Speedo_speed_s)
                                               - cc_sla_hmi_data->SLA_SpeedLimitActualAccepted.u_SpeedLimitIncOffset ) < Cc_sla_common_decel_speed_diff_kmh);
        }
        else
        {
          help_condition = ((setspeed_t)MAT_ABS((setspeed_t)(driver_requests->SPEEDOMETER_VEHICLE_SPEED_OFFSET/Speedo_speed_s)
                                               - cc_sla_hmi_data->SLA_SpeedLimitActualAccepted.u_SpeedLimitIncOffset ) < Cc_sla_common_decel_speed_diff_mph);
        }
      }
      else
      {
        /* Acceleration case */
        if(input->VEHICLE_STATUS.SPEED_UNIT_KMH == TRUE)
        {
          help_condition = ((setspeed_t)MAT_ABS((setspeed_t)(driver_requests->SPEEDOMETER_VEHICLE_SPEED_OFFSET/Speedo_speed_s)
                                               - cc_sla_hmi_data->SLA_SpeedLimitActualAccepted.u_SpeedLimitIncOffset ) < Cc_sla_common_accel_speed_diff_kmh);
        }
        else
        {
          help_condition = ((setspeed_t)MAT_ABS((setspeed_t)(driver_requests->SPEEDOMETER_VEHICLE_SPEED_OFFSET/Speedo_speed_s)
                                               - cc_sla_hmi_data->SLA_SpeedLimitActualAccepted.u_SpeedLimitIncOffset ) < Cc_sla_common_accel_speed_diff_mph);
        }
      }
      /* help_condition is needed because of QAC findings */
      if(help_condition == TRUE)
      {
        cc_sla_ctrl_data->SLA_CtrlState.SLA_ACCEL_REQUEST_GRANTED = FALSE;
        cc_sla_ctrl_data->s_SlaCtrlAccelRequest = (acceleration_t)0;
      }
      else
      {
        /* If during a SLA request a new speed limit available */
        if((input->SLA_INPUT_DATA.SLA_InputStatus.b_SLA_NEW_SPEED_AVAILABLE == TRUE)
            &&(input->SLA_INPUT_DATA.SLA_InputStatus.b_SLA_SPEED_ACCEPTED == TRUE))
        {
          if(input->SLA_INPUT_DATA.SLA_SpeedLimit.SpeedLimitType.b_SLA_CONTROL_BEFOR_LIMIT == FALSE)
          {
            cc_sla_ctrl_data->SLA_CtrlState.SLA_ACCEL_REQUEST_GRANTED = FALSE;
          }
          else
          {
            /* Determin control distance for calulation of SLA request for new speed limit */
            u_SlaCtrlDistance = KMC_t_DetermSLACtrlDistBeforeLimit(&input->SLA_INPUT_DATA.SLA_SpeedLimit,
                                                                        das_input->VEHICLE_SPEED,
                                                                        driver_requests);
            u_SlaCtrlDistance += KMC_t_DetermSLACtrlDistAfterLimit(&input->SLA_INPUT_DATA.SLA_SpeedLimit,
                                                                         das_input->VEHICLE_SPEED,
                                                                         driver_requests);

            /* Calculation SLA request for new speed limit */
            s_SlaAccelRequest = KMC_t_CalculateSLAAccel(input->VEHICLE_STATUS.SPEED_UNIT_KMH, das_input->VEHICLE_SPEED,
                                                       input->SLA_INPUT_DATA.SLA_SpeedLimit.u_SpeedLimitIncOffset,
                                                       u_SlaCtrlDistance, driver_requests);
            s_SlaAccelRequest = (acceleration_t)MAT_LIM(s_SlaAccelRequest, s_SlaMinDecelLimit, s_SlaMaxDecelLimit);
            /* Determ the control distance befor the speed limit for arbitration of speed limits */
            u_SlaCtrlDistance = KMC_t_DetermSLACtrlDistBeforeLimit(&input->SLA_INPUT_DATA.SLA_SpeedLimit,
                                                                           das_input->VEHICLE_SPEED,
                                                                           driver_requests);

            /* Arbitration conditions for new speed limit */
            if(((input->SLA_INPUT_DATA.SLA_SpeedLimit.SpeedLimitType.b_SLA_CONTROL_AFTER_LIMIT == FALSE)
               &&(s_SlaAccelRequest < cc_sla_ctrl_data->s_SlaCtrlAccelRequest))
              ||
              ((input->SLA_INPUT_DATA.SLA_SpeedLimit.SpeedLimitType.b_SLA_CONTROL_AFTER_LIMIT == TRUE)
               &&((input->SLA_INPUT_DATA.SLA_SpeedLimit.u_SpeedLimitDistance < u_SlaCtrlDistance)))
              )
            {
              /* Stop the SLA request and go to new speed limit */
              cc_sla_ctrl_data->SLA_CtrlState.SLA_ACCEL_REQUEST_GRANTED = FALSE;
            }
          }
        }
      }

      if(driver_requests->CC_SETSPEED != cc_sla_hmi_data->SLA_SpeedLimitActualAccepted.u_SpeedLimitIncOffset)
      {
        /* SLA control no longer accepted */
        cc_sla_ctrl_data->SLA_CtrlState.SLA_ACCEL_REQUEST_GRANTED = FALSE;
      }

    } /* end if(cc_sla_hmi_data->e_SLA_State == SLA_STATE_APPLIED) */
    else
    {
      /* any other state */
      cc_sla_ctrl_data->SLA_CtrlState.SLA_ACCEL_REQUEST_GRANTED = FALSE;
      cc_sla_ctrl_data->s_SlaCtrlAccelRequest = (acceleration_t)0;
    }
  }
}


/*************************************************************************************************************************
  Functionname:    KMC_v_ArbitrateCruiseAccel                                                                       */ /*!

  @brief           Arbitration between Cruise Control acceleration and SLA acceleration request

  @description     Arbitration between Cruise Control acceleration and SLA acceleration request.
                   SLA acceleration is prioritised, if available.
    @startuml
    Start
    Partition KMC_v_ArbitrateCruiseAccel {
      If (SLA_ACCEL_REQUEST_GRANTED == TRUE) then (yes)
        :SLA Ctrl acceleration is saved to CC acceleration;
      Else (no)
      Endif
    }
    End
    @enduml

  @return          --

  @param[in,out]   cc_control_data_t : Cruise Control data struct [cc_control_data_t as per cc_ext.h]
                    cc_control_data->CC_SLA_CTRL_DATA.SLA_CtrlState.SLA_ACCEL_REQUEST_GRANTED : Boolean indicating if SLA acceleration request granted [TRUE, FALSE]
                    cc_control_data->CC_SLA_CTRL_DATA.s_SlaCtrlAccelRequest : SLA acceleration request [-30000u ...+30000u] m/s2 (with factor Acceleration_s)
                    cc_control_data->CC_ACCELERATION : Cruise Control acceleration [-30000u ...+30000u] m/s2 (with factor Acceleration_s)

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_SLA_FEATURE : Switch for enabling SLA Support finctions
  @c_switch_full   FCT_CFG_LOPC_COMPONENT : Configuration switch for enabling LOPC processing
  @c_switch_full   FCT_CFG_CC : Configuration switch for enabling CC processing

  @created         08.06.2016
  @changed         08.06.2016

  @author          Simon Sinnstein | simon.sinnstein@continental-corporation.com | +49 (8382) 9699-160
*************************************************************************************************************************/
static void KMC_v_ArbitrateCruiseAccel(cc_control_data_t* cc_control_data)
{
  if(cc_control_data->CC_SLA_CTRL_DATA.SLA_CtrlState.SLA_ACCEL_REQUEST_GRANTED == TRUE)
  {
    cc_control_data->CC_ACCELERATION = cc_control_data->CC_SLA_CTRL_DATA.s_SlaCtrlAccelRequest;
  }
  else
  {
    /* provide normal cruise control acceleration CC_ACCELERATION */
  }
}
#endif /* (FCT_CFG_SLA_FEATURE) */

#if (CFG_FCT_CC_USE_ACCEL_BAND_MODIFICATION)
/*************************************************************************************************************************
  Functionname:    KMC_v_DetermineAccelBand                                                                         */ /*!

  @brief           Calculates a comfort band for the acceleration request. The output is a positive and negative limit 
                   for the maximum acceleration and positive and negative limit for the minimum acceleration.

  @description     Calculation of positive and negative limit acceleration bands based on commanded acceleration
                   for the purpose of comfort. Calculation also considers cruise control acceleration
                   and longitudinal acceleration limited due to lateral acceleration. The band is restricted to change 
                   within a definite amount with respect to the previous cycle values.
                   The output is a positive and negative limit for the maximum acceleration and 
                   positive and negative limit for the minimum acceleration.

  @return          -

  @param[in]       cycle_time : cycle time of FCT_VEH cycle [0u ... 1000u] ms
  @param[in,out]   cc_control_data : Pointer to CC control data [cc_control_data_t as per cc_ext.h]
                    CC_ACCELERATION : CC acceleration [-30000u ...+30000u] m/s2 (with factor Acceleration_s)
  @param[in,out]   accel_control_data : Pointer to CC acceleration control data [cc_acceleration_control_data_t as per cc_ext.h]
                    MIN_ACCEL_POS_BAND : Minimum positive acceleration band [-30000u ...+30000u] m/s2 (with factor Acceleration_s)
                    MIN_ACCEL_NEG_BAND : Minimum negative acceleration band [-30000u ...+30000u] m/s2 (with factor Acceleration_s)
                    MAX_ACCEL_POS_BAND : Maximum positive acceleration band [-30000u ...+30000u] m/s2 (with factor Acceleration_s)
                    MAX_ACCEL_NEG_BAND : Maximum negative acceleration band [-30000u ...+30000u] m/s2 (with factor Acceleration_s)
                    MINIMUM_REQUESTED_ACCELERATION : Minimum requested acceleration [-30000u ...+30000u] m/s2 (with factor Acceleration_s)
                    MAXIMUM_REQUESTED_ACCELERATION : Maximum requested acceleration [-30000u ...+30000u] m/s2 (with factor Acceleration_s)
                    MINIMUM_COMMANDED_ACCELERATION : Minimum commanded acceleration [-30000u ...+30000u] m/s2 (with factor Acceleration_s)
                    MAXIMUM_COMMANDED_ACCELERATION : Maximum commanded acceleration [-30000u ...+30000u] m/s2 (with factor Acceleration_s)
                    MAXIMUM_ACCELERATION_LATERAL_LIMITED : Maximum longitudinal acceleration limited due to lateral acceleration [-30000u ...+30000u] m/s2 (with factor Acceleration_s)
  @param[in]       vown : Ego speed with factor Velocity_s [-30000u ... 30000u] cm/s

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_LOPC_COMPONENT : Configuration switch for enabling LOPC processing
  @c_switch_full   FCT_CFG_CC : Configuration switch for enabling CC processing
  @c_switch_full   CFG_FCT_CC_USE_ACCEL_BAND_MODIFICATION : Configuration switch to use modification of acceleration band
*************************************************************************************************************************/
static void KMC_v_DetermineAccelBand(const times_t cycle_time, cc_control_data_t* cc_control_data, cc_acceleration_control_data_t *accel_control_data, velocity_t vown)
{

  sint32         maxposband, maxnegband, minposband, minnegband, latlim, accelband_scale;
  acceleration_t minnegbandlc, minposbandlc, maxnegbandlc, maxposbandlc;

  /*save values from last cycle*/
  minposbandlc = accel_control_data->MIN_ACCEL_POS_BAND;
  minnegbandlc = accel_control_data->MIN_ACCEL_NEG_BAND;
  maxposbandlc = accel_control_data->MAX_ACCEL_POS_BAND;
  maxnegbandlc = accel_control_data->MAX_ACCEL_NEG_BAND;

  /*Do not take ACCEL_BAND in lowest velocitys into consideration*/
  accelband_scale = MAT_CALCULATE_PARAM_VALUE1D(Cc_accel_band_scale, Cc_accel_band_scale_points, (sint16)vown);

  /*get max/min values*/
  maxposband = MAT_CALCULATE_PARAM_VALUE1D(Cc_accel_band_pos, Cc_max_accel_band_pos_points, accel_control_data->MAXIMUM_COMMANDED_ACCELERATION);
  maxnegband = MAT_CALCULATE_PARAM_VALUE1D(Cc_accel_band_neg, Cc_max_accel_band_neg_points, accel_control_data->MAXIMUM_COMMANDED_ACCELERATION);

  maxposband *=accelband_scale;
  maxposband /=Factor_s;
  maxnegband *=accelband_scale;
  maxnegband /=Factor_s;

  minposband = MAT_CALCULATE_PARAM_VALUE1D(Cc_accel_band_pos, Cc_max_accel_band_pos_points, accel_control_data->MINIMUM_COMMANDED_ACCELERATION);
  minnegband = MAT_CALCULATE_PARAM_VALUE1D(Cc_accel_band_neg, Cc_max_accel_band_neg_points, accel_control_data->MINIMUM_COMMANDED_ACCELERATION);

  minposband *=accelband_scale;
  minposband /=Factor_s;
  minnegband *=accelband_scale;
  minnegband /=Factor_s;

  /*pos band - limit to output acceleration to cc acceleration*/
  latlim = MAT_MIN((sint32)cc_control_data->CC_ACCELERATION, (sint32)accel_control_data->MAXIMUM_ACCELERATION_LATERAL_LIMITED);
  accel_control_data->MAX_ACCEL_POS_BAND = (acceleration_t)MAT_MIN(latlim - (sint32)accel_control_data->MAXIMUM_REQUESTED_ACCELERATION, maxposband);
  accel_control_data->MIN_ACCEL_POS_BAND = (acceleration_t)MAT_MIN(latlim - (sint32)accel_control_data->MINIMUM_REQUESTED_ACCELERATION, minposband);

  /*neg band - always 0 if object not effective*/
  if(accel_control_data->ACCEL_STATUS.OBJECT_EFFECTIVE == FALSE)
  {
    accel_control_data->MAX_ACCEL_NEG_BAND = (acceleration_t)minallowedband;
    accel_control_data->MIN_ACCEL_NEG_BAND = (acceleration_t)minallowedband;
  }
  else
  {
    accel_control_data->MAX_ACCEL_NEG_BAND = (acceleration_t)maxnegband;
    accel_control_data->MIN_ACCEL_NEG_BAND = (acceleration_t)minnegband;
  }

  /*limit bands*/
  accel_control_data->MAX_ACCEL_POS_BAND = (acceleration_t)MAT_LIM((sint32)accel_control_data->MAX_ACCEL_POS_BAND, (sint32)minallowedband, maxposband);
  accel_control_data->MAX_ACCEL_NEG_BAND = (acceleration_t)MAT_LIM((sint32)accel_control_data->MAX_ACCEL_NEG_BAND, (sint32)minallowedband, maxnegband);
  accel_control_data->MIN_ACCEL_POS_BAND = (acceleration_t)MAT_LIM((sint32)accel_control_data->MIN_ACCEL_POS_BAND, (sint32)minallowedband, minposband);
  accel_control_data->MIN_ACCEL_NEG_BAND = (acceleration_t)MAT_LIM((sint32)accel_control_data->MIN_ACCEL_NEG_BAND, (sint32)minallowedband, minnegband);

  /*limit change rate*/
  accel_control_data->MAX_ACCEL_POS_BAND = (acceleration_t)MAT_LIM_GRAD((sint32)accel_control_data->MAX_ACCEL_POS_BAND, (sint32)maxposbandlc, -Cc_accel_band_gradient, Cc_accel_band_gradient, cycle_time);
  accel_control_data->MIN_ACCEL_POS_BAND = (acceleration_t)MAT_LIM_GRAD((sint32)accel_control_data->MIN_ACCEL_POS_BAND, (sint32)minposbandlc, -Cc_accel_band_gradient, Cc_accel_band_gradient, cycle_time);

  if(accel_control_data->ACCEL_STATUS.OBJECT_EFFECTIVE == TRUE)
  {
    accel_control_data->MAX_ACCEL_NEG_BAND = (acceleration_t)MAT_LIM_GRAD((sint32)accel_control_data->MAX_ACCEL_NEG_BAND, (sint32)maxnegbandlc, -Cc_accel_band_gradient, Cc_accel_band_gradient, cycle_time);
    accel_control_data->MIN_ACCEL_NEG_BAND = (acceleration_t)MAT_LIM_GRAD((sint32)accel_control_data->MIN_ACCEL_NEG_BAND, (sint32)minnegbandlc, -Cc_accel_band_gradient, Cc_accel_band_gradient, cycle_time);
  }
}

#endif /* (CFG_FCT_CC_USE_ACCEL_BAND_MODIFICATION) */


/*************************************************************************************************************************
  Functionname:    KMC_v_SetAccelRequest                                                                            */ /*!

  @brief           Sets the minimum and maximum acceleration requests to the longitudinal dynamics management

  @description     If acceleration bands are to be modified, min and max acceleration requests are limited within the 
                   positive and negative comfort bands from the last cycle values. The requests are then ramped as per
                   defined gradients. If required, the filtered acceleration requests are used as outputs. Accelerations 
                   are set as outputs for the longitudinal dynamics management (via MIN_REQ_ACCEL and MAX_REQ_ACCEL).

@startuml
Start
Partition KMC_v_SetAccelRequest(){
: If acceleration bands are to be modified, limit min\n and max acceleration requests within the positive and negative comfort bands from\n the last cycle values;
: Sets the minimum and maximum acceleration requests \n to the longitudinal dynamic controller (via MIN_REQ_ACCEL and MAX_REQ_ACCEL);
}
End
@enduml


  @return          -

  @param[in]       cycle_time : cycle time of FCT_VEH cycle [0u ... 1000u] ms
  @param[in,out]   accel_control_data : Pointer to CC acceleration control data [cc_acceleration_control_data_t as per cc_ext.h]
                    MIN_ACCEL_NEG_BAND : Minimum negative acceleration band [-30000u ...+30000u] m/s2 (with factor Acceleration_s)
                    MAX_ACCEL_NEG_BAND : Maximum negative acceleration band [-30000u ...+30000u] m/s2 (with factor Acceleration_s)
                    MINIMUM_REQUESTED_ACCELERATION : Minimum requested acceleration [-30000u ...+30000u] m/s2 (with factor Acceleration_s)
                    MAXIMUM_REQUESTED_ACCELERATION : Maximum requested acceleration [-30000u ...+30000u] m/s2 (with factor Acceleration_s)
                    MINIMUM_REQUESTED_ACCELERATION_FILTERED : Minimum requested filtered acceleration [-30000u ...+30000u] m/s2 (with factor Acceleration_s)
                    MAXIMUM_REQUESTED_ACCELERATION_FILTERED : Maximum requested filtered acceleration [-30000u ...+30000u] m/s2 (with factor Acceleration_s)
  @param[in,out]   das_output : Pointer to output data from driver assistance system to longitudinal dynamics management [cart_das_output_data_t as per cart_ext.h]
                    MIN_REQ_ACCEL : Minimum required acceleration output [-30000u ...+30000u] m/s2 (with factor Acceleration_s)
                    MAX_REQ_ACCEL : Maximum required acceleration output [-30000u ...+30000u] m/s2 (with factor Acceleration_s)
  @param[in]       driver_requests : Pointer to driver request input structure [cc_driver_requests_t as per cc_ext.h]
                    CONTROL_STATE : Variable that reflects the state of the HMI state machine [full range of datatype cc_control_state_t as in cc_ext.h]

  @glob_in         -
  @glob_out        -

  @c_switch_part   CFG_FCT_CC_USE_ACCEL_BAND_MODIFICATION : Configuration switch to use modification of acceleration band
  @c_switch_part   CFG_FCT_CC_SMOOTH_ACCEL_REQUEST : Switch to configure filter to prevent oscillations and other discontinuous waveforms 
  @c_switch_full   FCT_CFG_LOPC_COMPONENT : Configuration switch for enabling LOPC processing
  @c_switch_full   FCT_CFG_CC : Configuration switch for enabling CC processing

*************************************************************************************************************************/
static void KMC_v_SetAccelRequest(const times_t cycle_time, cc_acceleration_control_data_t *accel_control_data, cart_das_output_data_t* das_output, const cc_driver_requests_t* driver_requests)
{
#if (CFG_FCT_CC_USE_ACCEL_BAND_MODIFICATION)
  acceleration_t min_accel_last_cycle, max_accel_last_cycle;
  acceleration_t min_requested_accel, max_requested_accel;

  if (
      (driver_requests->CONTROL_STATE == Cc_cc_disengage)
      ||
      (driver_requests->CONTROL_STATE == Cc_cc_off)
      ||
      (driver_requests->CONTROL_STATE == Cc_cc_decel_only)
      ||
      (driver_requests->CONTROL_STATE == Cc_cc_ready)
    )
  {
    das_output->MIN_REQ_ACCEL = accel_control_data->MINIMUM_REQUESTED_ACCELERATION;
    das_output->MAX_REQ_ACCEL = accel_control_data->MAXIMUM_REQUESTED_ACCELERATION;
  }
  else
  {
    /*save last requested acceleration*/
    min_accel_last_cycle = das_output->MIN_REQ_ACCEL;
    max_accel_last_cycle = das_output->MAX_REQ_ACCEL;

    /*limit requested accel last cycle between the accel band borders*/

    /*
       It is possible that the acceleration request jumps unauthorised by a value of CC_ACCEL_BAND_POS/NEG
       It is assumed that a limitation here will not solve the issue because also authorised jumps are effected
       CR: 5622
    */
    min_requested_accel = (acceleration_t)MAT_LIM((sint32)min_accel_last_cycle, accel_control_data->MINIMUM_REQUESTED_ACCELERATION - accel_control_data->MIN_ACCEL_NEG_BAND, accel_control_data->MINIMUM_REQUESTED_ACCELERATION + accel_control_data->MIN_ACCEL_POS_BAND);
    max_requested_accel = (acceleration_t)MAT_LIM((sint32)max_accel_last_cycle, accel_control_data->MAXIMUM_REQUESTED_ACCELERATION - accel_control_data->MAX_ACCEL_NEG_BAND, accel_control_data->MAXIMUM_REQUESTED_ACCELERATION + accel_control_data->MAX_ACCEL_POS_BAND);

    /*ramp accel request slowly to real requested accel*/
    min_requested_accel = (acceleration_t)MAT_LIM_GRAD((sint32)accel_control_data->MINIMUM_REQUESTED_ACCELERATION, (sint32)min_requested_accel, -Cc_accel_band_approach_gradient, Cc_accel_band_approach_gradient, cycle_time);
    max_requested_accel = (acceleration_t)MAT_LIM_GRAD((sint32)accel_control_data->MAXIMUM_REQUESTED_ACCELERATION, (sint32)max_requested_accel, -Cc_accel_band_approach_gradient, Cc_accel_band_approach_gradient, cycle_time);

    /*write data to cartronic data*/
    das_output->MIN_REQ_ACCEL = min_requested_accel;
    das_output->MAX_REQ_ACCEL = max_requested_accel;
  }

#else /* (CFG_FCT_CC_USE_ACCEL_BAND_MODIFICATION) */

#if (CFG_FCT_CC_SMOOTH_ACCEL_REQUEST)

  /*write filtered accel_control_data->(MAX/MIN)_ACCEL_(POS/NEG)_BAND to CARTRONIC_DATA */
  das_output->MIN_REQ_ACCEL = accel_control_data->MINIMUM_REQUESTED_ACCELERATION_FILTERED;
  das_output->MAX_REQ_ACCEL = accel_control_data->MAXIMUM_REQUESTED_ACCELERATION_FILTERED;

#else

  /*write accel_control_data->(MAX/MIN)_ACCEL_(POS/NEG)_BAND to CARTRONIC_DATA */
  das_output->MIN_REQ_ACCEL = accel_control_data->MINIMUM_REQUESTED_ACCELERATION;
  das_output->MAX_REQ_ACCEL = accel_control_data->MAXIMUM_REQUESTED_ACCELERATION;

#endif /* (CFG_FCT_CC_SMOOTH_ACCEL_REQUEST) */

_PARAM_UNUSED(cycle_time);
_PARAM_UNUSED(driver_requests);

#endif /* (CFG_FCT_CC_USE_ACCEL_BAND_MODIFICATION) */
}

/*************************************************************************************************************************
  Functionname:    KMC_v_CoordinateStandstill                                                                       */ /*!

  @brief           Sets the standstill management bits from and to the longitudinal dynamics management

  @description     Standstill and driveoff conditions determined based on driver inputs and traffic situation 
                   and set as outputs for longitudinal dynamics management.

    @startuml
    Start
    Partition KMC_v_CoordinateStandstill {
      If (CONTROL_STATE == Cc_cc_active) then (yes)
        If (Vehicle is stationary and\n(\nStop situation in traffic\nOR\nDriver pressed brake\n)) then (yes)
          : DAS_STAND_STILL = TRUE;
        Else (no)
          If (DAS_DRIVE_OFF == TRUE and DAS_STAND_STILL == FALSE) then (yes)
            : DAS_DRIVE_OFF = FALSE;
          Endif
          If (Vehicle is not stationary) then (yes)
          : DAS_STAND_STILL = FALSE;
          Endif
        Endif

        If (DRIVE_OFF_CONFIRM == TRUE) then (yes)
          : DAS_STAND_STILL = FALSE;
          : DAS_DRIVE_OFF = TRUE;
        Endif

        If (DAS_STAND_STILL == TRUE) then (yes)
          : Output acceleration is overwritten with \nmin of LOHP output acceleration, \nMAX_CUSTOM_ALLOWED_ACCEL and \nKmc_acc_standstill_accel_req;
        Endif
      Else (no)
      : DAS_STAND_STILL = FALSE;
      : DAS_DRIVE_OFF = FALSE;
      Endif
    }
    End
    @enduml

  @return          -

  @param[in]       acc_output : Pointer to ACC output [acc_output_data_t as per Rte_Type.h]
                    SITUATION_CLASS.SITUATION : Classifier of the current traffic situation [full range of datatype acc_situation_class_t as in Rte_Type.h]
                    DISTANCE_CTRL_ACCEL_MIN : Minimum acceleration for intrusion distance [-30000u ...+30000u] m/s2 (with factor Acceleration_s)
                    DISTANCE_CTRL_ACCEL_MAX : Maximum acceleration for intrusion distance [-30000u ...+30000u] m/s2 (with factor Acceleration_s)
  @param[in]       das_input : Pointer to input from longitudinal dynamics management to driver assistance system [cart_das_input_data_t as per cart_ext.h]
                    LODM_STAT.STANDSTILL : Boolean indicating if vehicle standstill is detected [TRUE, FALSE]
                    BRAKE_STAT.PEDAL_INIT_TRAVEL : Boolean indicating if brake pedal is pressed [TRUE, FALSE]

  @param[in,out]   das_output : Pointer to output data from driver assistance system to longitudinal dynamics management [cart_das_output_data_t as per cart_ext.h]
                    DAS_STAT.DAS_STAND_STILL : Boolean output indicating if vehicle standstill is detected [TRUE, FALSE]
                    DAS_STAT.DAS_DRIVE_OFF : Boolean output indicating if driveoff is confirmed [TRUE, FALSE]
  @param[in,out]   cc_status : Pointer to Cruisecontrol status [cc_status_t as per cc_ext.h]
                    CC_DRIVER_REQUESTS.CONTROL_STATE : Variable that reflects the state of the HMI state machine [full range of datatype cc_control_state_t as in cc_ext.h]
                    CC_DRIVER_REQUESTS.DRIVER_OPERATIONS.DRIVE_OFF_CONFIRM : Boolean indicating vehicle drive off [TRUE, FALSE]
                    CC_ACCEL_CONTROL_DATA.MINIMUM_COMMANDED_ACCELERATION : Minimum commanded acceleration [-30000u ...+30000u] m/s2 (with factor Acceleration_s)
                    CC_ACCEL_CONTROL_DATA.MAXIMUM_COMMANDED_ACCELERATION : Maximum commanded acceleration [-30000u ...+30000u] m/s2 (with factor Acceleration_s)
                    CC_ACCEL_CONTROL_DATA.MAX_CUSTOM_ALLOWED_ACCEL : Maximum custom allowed acceleration [-30000u ...+30000u] m/s2 (with factor Acceleration_s)

  @glob_in         -
  @glob_out        -

  @c_switch_part   FCT_CFG_FSRACC : Configuration switch enabling Full Speed Range Adaptive Cruise Control functionality with stop and go feature
  @c_switch_full   FCT_CFG_LOPC_COMPONENT : Configuration switch for enabling LOPC processing
  @c_switch_full   FCT_CFG_CC : Configuration switch for enabling CC processing

*************************************************************************************************************************/
static void KMC_v_CoordinateStandstill(const acc_output_data_t* acc_output, const cart_das_input_data_t* das_input, 
                                       cart_das_output_data_t* das_output, cc_status_t *cc_status)
{
#if (FCT_CFG_FSRACC)

  if (cc_status->CC_DRIVER_REQUESTS.CONTROL_STATE == Cc_cc_active)
  {
    if (
        (das_input->LODM_STAT.STANDSTILL == TRUE)
        &&
        (
         (acc_output->SITUATION_CLASS.SITUATION == Acc_sit_class_stop) /*&& driver was informed*/
         ||
         /*Prevent acceleration request if driver presses brakes after engagement in standstill*/
         (das_input->BRAKE_STAT.PEDAL_INIT_TRAVEL == TRUE)
        )
       )
    {
      das_output->DAS_STAT.DAS_STAND_STILL = TRUE;
    }
    else
    {
      /* There is no use of DAS_DRIVE_OFF in Cartronic interface */
      if (
          (das_output->DAS_STAT.DAS_DRIVE_OFF == TRUE) 
          &&
          (das_output->DAS_STAT.DAS_STAND_STILL == FALSE)
        ) 
      {
        das_output->DAS_STAT.DAS_DRIVE_OFF = FALSE;
      }

      if (das_input->LODM_STAT.STANDSTILL == FALSE) 
      {
        das_output->DAS_STAT.DAS_STAND_STILL = FALSE;
      }
    }

    if (cc_status->CC_DRIVER_REQUESTS.DRIVER_OPERATIONS.DRIVE_OFF_CONFIRM == TRUE)
    {
      /* additional check for (acc_output->SITUATION_CLASS.SITUATION == Acc_sit_class_go) possible */
      das_output->DAS_STAT.DAS_STAND_STILL = FALSE;
      das_output->DAS_STAT.DAS_DRIVE_OFF = TRUE;
    }

    /*vehicle shall be kept in standstill mode*/
    if (
        (das_input->LODM_STAT.STANDSTILL == TRUE)
        &&
        (das_output->DAS_STAT.DAS_STAND_STILL == TRUE)
       )
    {
      /*
      The vehicle should be hold in stand still. 
      DAS_STAT.DAS_STAND_STILL will be SET if LODM is standstill and sit_class_stop is set
      
      LODM shall gurantee standstill!*/
      /* MAX_CUSTOM_ALLOWED_ACCEL is used to allow custom logic for stand still request requirements */
      cc_status->CC_ACCEL_CONTROL_DATA.MAXIMUM_COMMANDED_ACCELERATION = (acceleration_t)MAT_MIN(MAT_MIN((sint32)cc_status->CC_ACCEL_CONTROL_DATA.MAX_CUSTOM_ALLOWED_ACCEL,(sint32)Kmc_acc_standstill_accel_req), (sint32)acc_output->DISTANCE_CTRL_ACCEL_MAX); 
      cc_status->CC_ACCEL_CONTROL_DATA.MINIMUM_COMMANDED_ACCELERATION = (acceleration_t)MAT_MIN(MAT_MIN((sint32)cc_status->CC_ACCEL_CONTROL_DATA.MAX_CUSTOM_ALLOWED_ACCEL,(sint32)Kmc_acc_standstill_accel_req), (sint32)acc_output->DISTANCE_CTRL_ACCEL_MIN); 
    }
  }
  else
  {
    das_output->DAS_STAT.DAS_STAND_STILL = FALSE;
    das_output->DAS_STAT.DAS_DRIVE_OFF = FALSE;
  }

#endif
}

/*************************************************************************************************************************
  Functionname:    KMC_v_DetectTransitionACCtoCC                                                                    */ /*!

  @brief           Detects transition from ACC (control with object) to 
                   CC (control with no object) at low speed range

  @description     When effective object is no longer available, there is transition from ACC to CC, 
                   after ensuring that required time has elapsed. This detection is only applicable 
                   for low speeds. As long as timer does not expire, the accel gradient will be reduced.

    @startuml
    Start
    Partition KMC_v_DetectTransitionACCtoCC {
      If (Object is no longer effective, ACC is in active \nphase and Ego speed is less than 16 m/s) then (yes)
        : Timer set to TIME_OF_TRANSITION;
      Else (no)
        : Timer reset to 0;
      Endif
      If (Timer time is over) then (yes)
        : CC_ACC_TO_CC_TRANSITION = TRUE;
      Else (no)
        : CC_ACC_TO_CC_TRANSITION = FALSE;
      Endif
    }
    End
    @enduml

  @return          -

  @param[in]       cycle_time : cycle time of FCT_VEH cycle [0u ... 1000u] ms
  @param[in]       das_input : Pointer to input from longitudinal dynamics management to driver assistance system [cart_das_input_data_t as per cart_ext.h]
                    VEHICLE_SPEED : Ego speed with factor Velocity_s [-30000u ... 30000u] cm/s 
  @param[in,out]   cc_status : Pointer to Cruisecontrol status [cc_status_t as per cc_ext.h]
                    CC_ACCEL_CONTROL_DATA.ACCEL_STATUS.OBJECT_EFFECTIVE : Boolean, if TRUE indicating effective OOI for ACC [TRUE, FALSE]
                    CC_DRIVER_REQUESTS.DRIVER_REQUEST_STATUS.SELECTED_FUNCTION_ACTIVE : Boolean indicating if ACC/CC active  [TRUE, FALSE]
                    CC_CONTROL_DATA.CC_ACC_TO_CC_TRANSITION : Boolean, if TRUE indicates transition from ACC (object-control) to CC [TRUE, FALSE]
  @glob_in         -
  @glob_out        object_effective_last_cycle : Boolean indicating effective OOI for previous cycle [TRUE, FALSE]
                   transion_timer : Timer to ensure timed transition from ACC to CC [0u ... 10000u]ms

  @c_switch_part   -
  @c_switch_full   FCT_CFG_LOPC_COMPONENT : Configuration switch for enabling LOPC processing
  @c_switch_full   FCT_CFG_CC : Configuration switch for enabling CC processing
*************************************************************************************************************************/
static void KMC_v_DetectTransitionACCtoCC(const times_t cycle_time, const cart_das_input_data_t* das_input, cc_status_t *cc_status)
{

  static boolean object_effective_last_cycle = FALSE;
  static times_t transion_timer = (times_t)0;

  /*! if no object and functon is active, cc mode */
  if(
      (cc_status->CC_ACCEL_CONTROL_DATA.ACCEL_STATUS.OBJECT_EFFECTIVE == FALSE)
      &&
      (cc_status->CC_DRIVER_REQUESTS.DRIVER_REQUEST_STATUS.SELECTED_FUNCTION_ACTIVE == TRUE)
    )
  {
    /*! last cycle object was available and vehicle at low speed */
    if(
        (object_effective_last_cycle == TRUE)
        &&
        (das_input->VEHICLE_SPEED < MAX_VALID_SPEED_FOR_DETECTION)
      )
    {
      /*! set time of transion, the accel gradient will be reduced */
      transion_timer = TIME_OF_TRANSITION;
    }
  }
  else
  {
    /* OBJECT_EFFECTIVE == TRUE or Function OFF */
    transion_timer = (times_t)0;
  }

  /*! if timer not expires, the accel gradient will be reduced */
  if(transion_timer >= cycle_time)
  {
    cc_status->CC_CONTROL_DATA.CC_ACC_TO_CC_TRANSITION = TRUE;
  }
  else
  {
    cc_status->CC_CONTROL_DATA.CC_ACC_TO_CC_TRANSITION = FALSE;
  }

  if(transion_timer >= cycle_time)
  {
    transion_timer -= cycle_time;
  }

  /*! update object_effective_last_cycle */
  object_effective_last_cycle = cc_status->CC_ACCEL_CONTROL_DATA.ACCEL_STATUS.OBJECT_EFFECTIVE;
}


/*************************************************************************************************************************
  Functionname:    KMC_v_Coordinator                                                                                   */ /*!

  @brief           Call all functions related to coordination of the commanded acceleration

  @description     Determination of acceleration limits. Limitation of requested acceleration 
                   based on limits and acceleration gradients. Here, only a list of functions is called.
                   - KMC_v_CoordinateAccel
                   - KMC_v_CoordinateStandstill
                   - KMC_v_DetectTransitionACCtoCC
                   - KMC_v_LimitAccelChangeRate
                   - KMC_v_AccelRequestFiltering

    @startuml
    Start
    Partition KMC_v_Coordinator {
      : KMC_v_CoordinateAccel;
      : KMC_v_CoordinateStandstill;
      : KMC_v_DetectTransitionACCtoCC;
      : KMC_v_LimitAccelChangeRate;
      : KMC_v_AccelRequestFiltering;
    }
    End
    @enduml

  @return          -

  @param[in]       cycle_time : cycle time of FCT_VEH cycle [0u ... 1000u] ms
  @param[in]       acc_output : Pointer to ACC output [acc_output_data_t as per Rte_Type.h]
  @param[in]       das_input : Pointer to input from longitudinal dynamics management to driver assistance system [cart_das_input_data_t as per cart_ext.h]
                    LODM_STAT : Longitudinal dynamics management status bits[cart_lodm_status_t as per cart_ext.h]
  @param[in,out]   das_output : Pointer to output data from driver assistance system to longitudinal dynamics management [cart_das_output_data_t as per cart_ext.h]
  @param[in,out]   cc_status : Pointer to Cruisecontrol status [cc_status_t as per cc_ext.h]
                    LODM_STAT_LAST_CYCLE : Longitudinal dynamics management status bits as per last cycle [cart_lodm_status_t as per cart_ext.h]
                    CC_DRIVER_REQUESTS : Data that reflects the driver's request intention [cc_driver_requests_t as per cc_ext.h]
                    CC_CONTROL_DATA : Pointer to CC control data [cc_control_data_t as per cc_ext.h]
                    CC_ACCEL_CONTROL_DATA : Pointer to CC acceleration control data [cc_acceleration_control_data_t as per cc_ext.h]
  @param[in]       input : Pointer to cc_input_data_t type structure containing input data to CC [cc_input_data_t as per cc_ext.h]
  @glob_in         
  @glob_out        

  @c_switch_part   CFG_FCT_CC_SMOOTH_ACCEL_REQUEST : Switch to configure filter to prevent oscillations and other discontinuous waveforms 
  @c_switch_full   FCT_CFG_LOPC_COMPONENT : Configuration switch for enabling LOPC processing
  @c_switch_full   FCT_CFG_CC : Configuration switch for enabling CC processing
*************************************************************************************************************************/
static void KMC_v_Coordinator(const times_t cycle_time, const acc_output_data_t* acc_output, const cart_das_input_data_t* das_input,
  cart_das_output_data_t* das_output, cc_status_t *cc_status, const cc_input_data_t* input)
{

  KMC_v_CoordinateAccel(&cc_status->CC_DRIVER_REQUESTS, acc_output, &cc_status->CC_CONTROL_DATA, &cc_status->CC_ACCEL_CONTROL_DATA, das_input);

  KMC_v_CoordinateStandstill(acc_output, das_input, das_output, cc_status);

  cc_status->LODM_STAT_LAST_CYCLE = das_input->LODM_STAT;

  KMC_v_DetectTransitionACCtoCC(cycle_time, das_input, cc_status);

  KMC_v_LimitAccelChangeRate(cycle_time, &cc_status->CC_DRIVER_REQUESTS, &cc_status->CC_CONTROL_DATA, &cc_status->CC_ACCEL_CONTROL_DATA, das_input, das_output, input, acc_output);

#if (CFG_FCT_CC_SMOOTH_ACCEL_REQUEST)

  KMC_v_AccelRequestFiltering(cycle_time, &cc_status->CC_ACCEL_CONTROL_DATA, &cc_status->CC_DRIVER_REQUESTS, acc_output, das_input, &cc_status->CC_CONTROL_DATA);

#endif

}


/*************************************************************************************************************************
  Functionname:    KMC_v_CommandAcceleration                                                                        */ /*!

  @brief           Call all functions related to the determination of the commanded acceleration

  @description     Commanded acceleration calculated and arbitrated based on inputs from cruise control, 
                   speed limit assist, ACC object control, whichever applicable. Requested acceleration 
                   calculated from commanded acceleration based on limitations from lateral acceleration 
                   and comfort requirements (gradients and bands). MIN_REQ_ACCEL and MAX_REQ_ACCEL sent 
                   as output to LODM
    @startuml
    Start
    Partition KMC_v_CommandAcceleration {
      : KMC_v_DetermineSLAAccel;
      : KMC_v_DetermineCCAccel;
      : KMC_v_ArbitrateCruiseAccel;
      : KMC_v_DetermineLimiterAccel;
      : KMC_v_LimitLateralAccel;
      : KMC_v_LimitDecel;
      : KMC_v_Coordinator;
      : KMC_v_DetermineAccelBand;
      : KMC_v_SetAccelRequest;
      : MIN_REQ_ACCEL is written as min of \nMIN_REQ_ACCEL and MAX_REQ_ACCEL;
    }
    End
    @enduml

  @return          -

  @param[in]       cycle_time : cycle time of FCT_VEH cycle [0u ... 1000u] ms
  @param[in]       input : Pointer to cc_input_data_t type structure containing input data to CC [cc_input_data_t as per cc_ext.h]
  @param[in]       das_input : Pointer to input from longitudinal dynamics management to driver assistance system [cart_das_input_data_t as per cart_ext.h]
                    VEHICLE_SPEED : Ego speed with factor Velocity_s [-30000u ... 30000u] cm/s
  @param[in]       acc_output : Pointer to ACC output [acc_output_data_t as per Rte_Type.h]
  @param[in,out]   das_output : Pointer to output data from driver assistance system to longitudinal dynamics management [cart_das_output_data_t as per cart_ext.h]
                    MIN_REQ_ACCEL : Minimum required acceleration output [-30000u ...+30000u] m/s2 (with factor Acceleration_s)
                    MAX_REQ_ACCEL : Maximum required acceleration output [-30000u ...+30000u] m/s2 (with factor Acceleration_s)
  @param[in,out]   cc_status : Pointer to Cruisecontrol status [cc_status_t as per cc_ext.h]
                    CC_DRIVER_REQUESTS : Data that reflects the driver's request intention [cc_driver_requests_t as per cc_ext.h]
                    CC_SLA_HMI_DATA : Pointer to data struct SLA HMI [t_SLA_HMI_Data as per cc_ext.h]
                    CC_ACCEL_CONTROL_DATA : Pointer to CC acceleration control data [cc_acceleration_control_data_t as per cc_ext.h]
                    CC_CONTROL_DATA : Pointer to CC control data [cc_control_data_t as per cc_ext.h]
                    CC_CONTROL_DATA.CC_SLA_CTRL_DATA : Pointer to SLA control data [t_SLA_Ctrl_Data as per cc_ext.h]

  @glob_in         
  @glob_out        

  @c_switch_part   FCT_CFG_SLA_FEATURE : Switch for enabling SLA Support functions
  @c_switch_part   CFG_FCT_LIM : Configuration switch for enabling limiter function
  @c_switch_part   CFG_FCT_PLIM : Configuration switch for enabling permanent limiter function
  @c_switch_part   CFG_FCT_CC_USE_LAT_LIM : Configuration switch for enabling lateral acceleration limitations
  @c_switch_part   CFG_FCT_CC_USE_ACCEL_BAND_MODIFICATION : Configuration switch to use modification of acceleration band
  @c_switch_full   FCT_CFG_LOPC_COMPONENT : Configuration switch for enabling LOPC processing
  @c_switch_full   FCT_CFG_CC : Configuration switch for enabling CC processing

  @traceability    doors://rbgs854a:40000/?version=2&prodID=0&view=00000002&urn=urn:telelogic::1-503e822e5ec3651e-O-147-0008a220
 
*************************************************************************************************************************/
void KMC_v_CommandAcceleration(const times_t cycle_time, 
                              const cc_input_data_t* input, 
                              const cart_das_input_data_t* das_input, 
                              const acc_output_data_t* acc_output, 
                              cart_das_output_data_t* das_output, 
                              cc_status_t *cc_status)
{
#if (FCT_CFG_SLA_FEATURE)
  KMC_v_DetermineSLAAccel(input, das_input,&cc_status->CC_DRIVER_REQUESTS,&cc_status->CC_SLA_HMI_DATA,&cc_status->CC_CONTROL_DATA.CC_SLA_CTRL_DATA);
#endif

  KMC_v_DetermineCCAccel(input, das_input, &cc_status->CC_DRIVER_REQUESTS, &cc_status->CC_CONTROL_DATA);

#if (FCT_CFG_SLA_FEATURE)
  KMC_v_ArbitrateCruiseAccel(&cc_status->CC_CONTROL_DATA);
#endif

#if (CFG_FCT_LIM || CFG_FCT_PLIM)
  KMC_v_DetermineLimiterAccel(input, &cc_status->CC_DRIVER_REQUESTS, &cc_status->CC_CONTROL_DATA);
#endif

#if (CFG_FCT_CC_USE_LAT_LIM)
  KMC_v_LimitLateralAccel(cycle_time, input, acc_output, das_input, cc_status);
#endif

  KMC_v_LimitDecel(cc_status);

  KMC_v_Coordinator(cycle_time, acc_output, das_input, das_output, cc_status, input);

#if (CFG_FCT_CC_USE_ACCEL_BAND_MODIFICATION)

  KMC_v_DetermineAccelBand(cycle_time, &cc_status->CC_CONTROL_DATA, &cc_status->CC_ACCEL_CONTROL_DATA, das_input->VEHICLE_SPEED);

#endif /* (CFG_FCT_CC_USE_ACCEL_BAND_MODIFICATION) */

  KMC_v_SetAccelRequest(cycle_time, &cc_status->CC_ACCEL_CONTROL_DATA, das_output, &cc_status->CC_DRIVER_REQUESTS);

  /*if MAX<MIN -> MIN=MAX*/
  das_output->MIN_REQ_ACCEL = (acceleration_t) MAT_MIN((sint32)das_output->MAX_REQ_ACCEL,(sint32)das_output->MIN_REQ_ACCEL);
}

#endif

/** @} end defgroup */

/* date: 2019-02-08, reviewer: Niraj Mistry, reason: Number of lines exceeded per file, not safety critical */
// PRQA S 7013