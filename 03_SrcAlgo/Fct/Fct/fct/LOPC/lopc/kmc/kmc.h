/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC/LOPC/KMC (Adaptive Cruise Control - Longitudinal Planner and Controller - Kinematic Motion Control)

PACKAGENAME:               kmc.h

DESCRIPTION:               Internal header file for Cruise control functionality in KMC

AUTHOR:                    Mistry Niraj (uidq5738)

CREATION DATE:             24.02.2017

VERSION:                   $Revision: 1.20 $

LEGACY VERSION:            Revision: 1.12.3.2

**************************************************************************** */

#ifndef KMC_H_INCLUDED
#define KMC_H_INCLUDED

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/** 
@defgroup   kmc_h Kmc_h
@ingroup    kmc
@brief      KMC internal header file
@{ */ 

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "frame_lopc.h"
#include "kmc_cfg.h"
#include "kmc_par.h"

#if ((FCT_CFG_LOPC_COMPONENT) && (FCT_CFG_CC) && (LOPC_CFG_KMC))

/*****************************************************************************
  SYMBOLIC CONSTANTS (COMPONENT EXTERN)
*****************************************************************************/


/*****************************************************************************
  MACROS (COMPONENT EXTERN)
*****************************************************************************/

/*! Gear */
#define Pt_gear_neutral   DYN_GEAR_NEUTRAL_GEAR
#define Pt_gear_first     DYN_GEAR_FIRST_GEAR
#define Pt_gear_second    DYN_GEAR_SECOND_GEAR
#define Pt_gear_third     DYN_GEAR_THIRD_GEAR
#define Pt_gear_fourth    DYN_GEAR_FOURTH_GEAR
#define Pt_gear_fifth     DYN_GEAR_FIFTH_GEAR
#define Pt_gear_sixth     DYN_GEAR_SIXTH_GEAR
#define Pt_gear_seventh   DYN_GEAR_SEVENTH_GEAR
#define Pt_gear_eighth    DYN_GEAR_EIGHTH_GEAR   /* @todo: Verify consequent support everywhere in code */
#define Pt_gear_ninth     DYN_GEAR_NINTH_GEAR
#define Pt_gear_reverse   DYN_GEAR_REVERSE_GEAR  /* Value change 9=>10 */
#define Pt_gear_park      DYN_GEAR_PARK_GEAR     /* Value change 10=>11 */

#define Cc_speed_default_value         ((setspeed_t)255)

#define Accelgradient_min  (gradient_t)(-500000)
#define Accelgradient_max  (gradient_t)(500000)

/*****************************************************************************
  TYPEDEFS (COMPONENT EXTERN)
*****************************************************************************/

#ifndef Cc_no_error
/* ReportedError */
#define Cc_no_error                 ((cc_reported_error_t)0)
#define Cc_performance_degradation  ((cc_reported_error_t)1)
#define Cc_temp_unavailable         ((cc_reported_error_t)2)
#define Cc_error_service            ((cc_reported_error_t)3)
typedef enum_t cc_reported_error_t; /*!< @values: Cc_no_error,Cc_performance_degradation,Cc_temp_unavailable,Cc_error_service */
#endif


/* Shifted from pt_ext.h */
/* WORK-AROUND FOR MISSING GEAR DEFINES in ARS4D2 common */
#ifndef DYN_GEAR_NEUTRAL_GEAR
typedef enum {
  DYN_GEAR_NEUTRAL_GEAR=0,
  DYN_GEAR_FIRST_GEAR=1,
  DYN_GEAR_SECOND_GEAR=2,
  DYN_GEAR_THIRD_GEAR=3,
  DYN_GEAR_FOURTH_GEAR=4,
  DYN_GEAR_FIFTH_GEAR=5,
  DYN_GEAR_SIXTH_GEAR=6,
  DYN_GEAR_SEVENTH_GEAR=7,
  DYN_GEAR_EIGHTH_GEAR=8,
  DYN_GEAR_NINTH_GEAR=9,
  DYN_GEAR_REVERSE_GEAR=10,
  DYN_GEAR_PARK_GEAR=11,
  DYN_GEAR_POWER_FREE=12,
} eTransmissionGear_t;
#endif

typedef TransmissionGear_t pt_gear_t; /*!< @todo: Remove pt_gear_t and replace with proper RTE type */

/*! @brief Power train status bits */
typedef struct pt_status_t {
  ubit8_t FAIL_REVERSABLE     :1;
  ubit8_t FAIL_IRREVERSABLE   :1;
  ubit8_t KICKDOWN            :1;
  ubit8_t CLUTCH_OPEN         :1;
  ubit8_t SHIFT_IN_PROGRESS   :1;
ubit8_t                     :3;
} pt_status_t;


/* Moved from brake_ext.h */
/*! @brief Brake status bits */
typedef struct brake_status_t {
  ubit8_t BRAKE_FAILED       :1;
  ubit8_t OVER_HEATED        :1;
  ubit8_t PEDAL_INIT_TRAVEL  :1;
ubit8_t                    :5;
} brake_status_t;

/* Moved from chassis_ext.h */
/*! @brief Chassis status bits */
typedef struct chassis_status_t {
  ubit8_t ABS_ACT      :1;
  ubit8_t TCS_ACT      :1;
  ubit8_t ESP_ACT      :1;
  ubit8_t PB_ACT       :1;
  ubit8_t TCS_ESP_OFF  :1;
ubit8_t              :3;
} chassis_status_t;


/* Moved from cart_ext.h*/
/*! Shift request */
#define Cart_no_shift_request ((cart_shift_request_t)0)
#define Cart_keep_gear        ((cart_shift_request_t)1)
#define Cart_shift_down       ((cart_shift_request_t)2)
typedef enum_t cart_shift_request_t;  /*!< @values:Cart_no_shift_request,Cart_keep_gear,Cart_shift_down */

/*! @brief Driver assistance system status bits */
typedef struct cart_das_status_t {
  ubit8_t DAS_FAIL_REVERSABLE    :1;
  ubit8_t DAS_FAIL_IRREVERSABLE  :1;
  ubit8_t DAS_PREFILL            :1;
  ubit8_t DAS_STAND_STILL        :1;
  ubit8_t DAS_DRIVE_OFF          :1;
  ubit8_t DAS_ENGAGED            :1;
  ubit8_t DAS_SHUTOFF_REQ        :1;
  ubit8_t DAS_OVERRIDE           :1;

  ubit8_t DAS_LIM                :1;
ubit8_t                        :7;
} cart_das_status_t;

/*! @brief Longitudinal dynamics management status bits */
typedef struct cart_lodm_status_t {
  ubit8_t DC_FAIL          :1; /*!!! not used at the moment*/
  ubit8_t DAS_ENABLE       :1; /*driver assistance system can be enabled*/
  ubit8_t DC_LIM_ACCEL     :1; /*acceleration request is limited*/
  ubit8_t DC_LIM_DECEL     :1; /*deceleration request is limited*/
  ubit8_t DAS_SHUTOFF_ACQ  :1; /*shutoff was acknowledged by LODM*/
  ubit8_t OVERRIDE_ACCEL   :1; /*driver override by accelerator pedal*/
  ubit8_t OVERRIDE_DECEL   :1; /*driver override by decelerator pedal*/
  ubit8_t STANDSTILL       :1; /*standstill detected*/

  ubit8_t BRAKE_LIGHT_REQ  :1;
ubit8_t                  :7;
} cart_lodm_status_t;

/*! @brief Data from driver assistance system to longitudinal dynamics management */
typedef struct cart_das_output_data_t {
  acceleration_t    MIN_REQ_ACCEL;
  acceleration_t    MAX_REQ_ACCEL;
  cart_das_status_t DAS_STAT;
} cart_das_output_data_t;

/*! Result of the decision between engine and brake */
#define Cart_arbit_none   (cart_arbit_mode_t)0
#define Cart_arbit_engine (cart_arbit_mode_t)1
#define Cart_arbit_brake  (cart_arbit_mode_t)2
typedef enum_t cart_arbit_mode_t; /*!< @values:Cart_arbit_none,Cart_arbit_engine,Cart_arbit_brake */

/*! @brief Validity bits for data from longitudinal dynamics management to driver assistance system */
typedef struct cart_lodm_data_valid_t {
  ubit8_t VEHICLE_SPEED  :1;
  ubit8_t VEHICLE_ACCEL  :1;
  ubit8_t INIT_ACCEL     :1;
ubit8_t                :5;
} cart_lodm_data_valid_t;

#if ( FCT_VEH_CFG_USE_LODMC_OUTPUT )
typedef struct {
  lodmc_op_state_t LODMC_STATE;
} lodmc_status_t;
#endif

#if ( FCT_VEH_CFG_LOPC_SM_USE_EBA_OUTPUT )
typedef struct {
  boolean PRE_BRK_DECEL_ENA;
} eba_status_t;
#endif

/*! @brief Data from longitudinal dynamics management to driver assistance system */
typedef struct cart_das_input_data_t {
  velocity_t              VEHICLE_SPEED;
  acceleration_t          VEHICLE_ACCEL;
  acceleration_t          A_INIT;
  pt_status_t             PT_STAT;
  brake_status_t          BRAKE_STAT;
  chassis_status_t        CHASSIS_STAT;
  cart_lodm_status_t      LODM_STAT;
  cart_lodm_data_valid_t  DATA_VALID;
#if ( FCT_VEH_CFG_USE_LODMC_OUTPUT )
  lodmc_status_t          LODMC_STAT;
#endif
#if ( FCT_VEH_CFG_LOPC_SM_USE_EBA_OUTPUT )
  eba_status_t            EBA_STAT;
#endif
} cart_das_input_data_t;


/*! Status of the switch that preselects the cruise control or the speed limiter function */
#define Cc_function_none  ((cc_selected_function_t)0)
#define Cc_function_cc    ((cc_selected_function_t)1)
#define Cc_function_lim   ((cc_selected_function_t)3)
typedef enum_t cc_selected_function_t;


/*! Country variant code */
#define Cc_rest_of_world  ((cc_country_code_t)0)
#define Cc_usa            ((cc_country_code_t)1)
#define Cc_japan          ((cc_country_code_t)2)
#define Cc_canada         ((cc_country_code_t)3)
typedef enum_t cc_country_code_t;  /*!< @values: Cc_rest_of_world,Cc_usa,Cc_japan,Cc_canada */


/*! @brief Validity bits for driver assistance system vehicle data */
typedef struct cc_das_data_validity_t {
  ubit8_t LATERAL_ACCEL :1;
  ubit8_t ACTUAL_GEAR   :1;
  ubit8_t SPEEDO_SPEED  :1;
  ubit8_t               :5;
} cc_das_data_validity_t;

/*! @brief Bits for driver assistance system vehicle status */
typedef struct cc_das_vehicle_status_t {
  ubit8_t SPEED_UNIT_KMH     :1;
  ubit8_t SPORTS_MODE        :1;
  ubit8_t                    :6;
} cc_das_vehicle_status_t;

/*! @brief Bits for driver assistance system inhibit */
typedef struct cc_das_inhibit_t {
  ubit8_t CC_DISENGAGEMENT_NO_RAMP    :1;
  ubit8_t CC_DISENGAGEMENT_RAMP       :1;
  ubit8_t CC_DISENGAGEMENT_RAPID_RAMP :1;
  ubit8_t CC_DISENGAGEMENT_DECEL_ONLY :1;
  ubit8_t CC_INHIBIT_ENGAGEMENT       :1;
  ubit8_t CC_SIGNALCHECK_FAIL         :1;
  ubit8_t                             :2;
} cc_das_inhibit_t;

#if (FCT_CFG_SLA_FEATURE)
typedef struct t_SLA_InputStatus
{
  ubit8_t b_SLA_SET_ENGAGED           :1; /* TRUE SLA Support enagaged, FALSE SLA Support disengaged */
  ubit8_t b_SLA_SET_AUTOMATIC         :1; /* TRUE SLA speed accepted automaticaly, FALSE manuel */
  ubit8_t b_SLA_NEW_SPEED_AVAILABLE   :1; /* TRUE new speed limit available */
  ubit8_t b_SLA_SPEED_ACCEPTED        :1; /* TRUE the speed limit was accepted */
  ubit8_t b_SLA_SPEED_DECLINED        :1; /* TRUE the speed limit was declined */
  ubit8_t b_SLA_SPEED_ABORTED         :1; /* TRUE the speed limit was aborted */
  ubit8_t b_SLA_RETAKE_SPEED          :1; /* TRUE: Retake currently accepted road traffic sign */
  ubit8_t                             :1;
} t_SLA_InputStatus;

typedef struct t_SpeedLimitType
{
  ubit8_t b_SLA_CONTROL_BEFOR_LIMIT   :1;
  ubit8_t b_SLA_CONTROL_AFTER_LIMIT   :1;
  ubit8_t                             :6;
} t_SpeedLimitType;

typedef struct t_SLA_SpeedLimit
{
  setspeed_t        u_SpeedLimit;
  setspeed_t        u_SpeedLimitIncOffset;
  t_u_DistanceLong  u_SpeedLimitDistance;
  t_SpeedLimitType  SpeedLimitType;
} t_SLA_SpeedLimit;

/*! @brief SLA Input Data: SLA_INPUT_DATA */
typedef struct t_SLA_InputData
{
  t_SLA_SpeedLimit  SLA_SpeedLimit;
  t_SLA_InputStatus SLA_InputStatus;
} t_SLA_InputData;

/*! SLA State type */
typedef enum t_e_SLA_State
{
  SLA_STATE_IDLE,
  SLA_STATE_PROPOSED,
  SLA_STATE_ACCEPTED,
  SLA_STATE_APPLIED,
  SLA_STATE_DECLINED,
  SLA_STATE_ABORTED
} t_e_SLA_State; /*!< @values: SLA_STATE_IDLE,SLA_STATE_PROPOSED,SLA_STATE_ACCEPTED,SLA_STATE_APPLIED,SLA_STATE_DECLINED,SLA_STATE_ABORTED */

typedef struct t_SLA_Event
{
  ubit8_t b_SLA_SAVE_DRIVER_SETSPEED    :1; /* If TRUE, current driver set speed is saved to u_SLA_DriverLastSetSpeed */
  ubit8_t b_SLA_DELETE_DRIVER_SETSPEED  :1; /* If TRUE, delete saved setspeed from u_SLA_DriverLastSetSpeed */
  ubit8_t b_SLA_SET_DRIVER_SETSPEED     :1; /* Previously saved driver setspeed or zone speed is reused as current setspeed */
  ubit8_t b_SLA_USAGE_AVAILABLE         :1; /* SLA function available and uses driver inputs with priority */
  ubit8_t b_SLA_WARNING                 :1; /* SLA Warning */
  ubit8_t                               :3;
} t_SLA_Event;

/*! SLA Data */
typedef struct t_SLA_HMI_Data
{
  t_SLA_SpeedLimit  SLA_SpeedLimitActualAccepted;   /* Current SLA control speed (contains road sign and offset) */
  setspeed_t        u_SLA_SpeedLimitLastAccepted;   /* Last speed accepted by SLA (without offset) */
  setspeed_t        u_SLA_DriverLastSetSpeed;       /* Last speed set by driver. Used for retaking after unrestricted sign is seen */
  setspeed_t        u_SLA_LastSetSpeedForTakeOver;  /* Last set speed changed by SLA Function. Used for retaking when driver declines a speedlimit */
  setspeed_t        u_SLA_SpeedLimitLastDeclined;   /* Speed limit last declined by driver (without offset) */
  sint8             s_SLA_Offset;                   /* Offset provided by driver */
  t_e_SLA_State     e_SLA_State;
  t_SLA_Event       SLA_Event;
} t_SLA_HMI_Data;

typedef struct t_SLA_Ctrl_State
{
  ubit8_t SLA_ACCEL_REQUEST_GRANTED :1;
ubit8_t                           :7;
} t_SLA_Ctrl_State;

typedef struct t_SLA_Ctrl_Data
{
  acceleration_t    s_SlaCtrlAccelRequest;
  t_SLA_Ctrl_State  SLA_CtrlState;
} t_SLA_Ctrl_Data;

#endif  /* FCT_CFG_SLA_FEATURE */


/*! @brief CC input interface: input data*/
typedef struct cc_input_data_t {
  gradient_t              ACCELERATION_GRADIENT;
  acceleration_t          LATERAL_ACCELERATION;
  pt_gear_t               ACTUAL_GEAR;
  cc_das_data_validity_t  DATA_VALIDITY;
  cc_das_inhibit_t        INHIBIT;
  cc_das_vehicle_status_t VEHICLE_STATUS;
  speedometer_speed_t     SPEEDOMETER_VEHICLE_SPEED;
  setspeed_t              PERMANENT_LIMITER_SETSPEED;
  cc_country_code_t       COUNTRY_CODE;
  setspeed_t              VEHICLE_SPEED_LIMIT;
  setspeed_t              CURRENT_SPEED_LIMIT;
#if (FCT_CFG_SLA_FEATURE)
  t_SLA_InputData         SLA_INPUT_DATA; /* to do add switch */
#endif
#if (LONG_CFG_USE_EXTERN_ACC_STATE_MACHINE)
  const EngineEcuInput_t* pENGINE_ECU_INPUT;
#endif
} cc_input_data_t;

/*! State variable of the HMI state machine */
#define Cc_cc_off                 ((cc_control_state_t)0)
#define Cc_cc_ready               ((cc_control_state_t)1)
#define Cc_cc_engage              ((cc_control_state_t)2)
#define Cc_cc_active              ((cc_control_state_t)3)
#define Cc_cc_override            ((cc_control_state_t)4)
#define Cc_cc_disengage           ((cc_control_state_t)5)
#define Cc_cc_decel_only          ((cc_control_state_t)6)
#define Cc_lim_ready              ((cc_control_state_t)7)
#define Cc_lim_active             ((cc_control_state_t)8)
#define Cc_lim_override           ((cc_control_state_t)9)
#define Cc_lim_disengage          ((cc_control_state_t)10)
#define Cc_plim_active            ((cc_control_state_t)11)
typedef enum_t cc_control_state_t;  /*!< @values: Cc_cc_off,Cc_cc_ready,Cc_cc_engage,Cc_cc_active,Cc_cc_override,Cc_cc_disengage,Cc_cc_decel_only,Cc_lim_ready,Cc_lim_active,Cc_lim_override,Cc_lim_disengage,Cc_plim_active */

/*! Mode within the active state */
#define Cc_standstill_mode        ((cc_control_mode_t)0)
#define Cc_follow_mode            ((cc_control_mode_t)1)
#define Cc_free_mode              ((cc_control_mode_t)2)
typedef enum_t cc_control_mode_t;   /*!< @values: Cc_standstill_mode,Cc_follow_mode,Cc_free_mode */

/*! @brief Bits to reflect state transitions within the hmi state machine */
typedef struct cc_engagement_conditions_t {
  ubit8_t ACCEPT_CC_ENGAGEMENT      :1;
  ubit8_t ACCEPT_LIM_ENGAGEMENT     :1;
  ubit8_t END_CC_ENGAGEMENT         :1;
  ubit8_t DRIVER_OVERRIDE           :1; 
  ubit8_t CC_DISENGAGEMENT          :1;
  ubit8_t CC_DISENGAGEMENT_RAMP     :1; 
  ubit8_t CC_DECEL_ONLY             :1;
  ubit8_t CC_END_DECEL_ONLY         :1;

  ubit8_t END_CC_DISENGAGEMENT      :1;
  ubit8_t LIM_DISENGAGEMENT         :1;
  ubit8_t END_LIM_DISENGAGEMENT     :1; 
  ubit8_t GOTO_PERM_LIM             :1;
  ubit8_t END_PERM_LIM              :1;
  ubit8_t DRIVE_OFF_POSSIBLE        :1;
  ubit8_t CC_ENGAGEMENT_STAT        :1;
  ubit8_t CONTROL_TO_RELEVANT_OBJECT :1;
} cc_engagement_conditions_t;

/*! @brief Bits to reflect the operations of the driver */
typedef struct cc_driver_operations_t {
  ubit8_t CC_TAKE_ACTUAL_SPEED         :1;
  ubit8_t LIM_TAKE_ACTUAL_SPEED        :1;
  ubit8_t CC_RESUME_SET_SPEED          :1;
  ubit8_t LIM_RESUME_SET_SPEED         :1;
  ubit8_t ACCEL_MODE                   :1;
  ubit8_t CC_INCREASE_SET_SPEED        :1;
  ubit8_t CC_DECREASE_SET_SPEED        :1;
  ubit8_t DECEL_MODE                   :1;

  ubit8_t LIM_INCREASE_SET_SPEED       :1;
  ubit8_t LIM_DECREASE_SET_SPEED       :1;
  ubit8_t SPEED_STEP_1                 :1;
  ubit8_t CANCEL_FUNKTION              :1;
  ubit8_t DISENGAGE_DRIVER_INTERVENED  :1;
  ubit8_t RESET_SETSPEED               :1;
  ubit8_t SWITCH_SPEED_UNIT            :1;
  ubit8_t DRIVE_OFF_CONFIRM            :1;
#if (FCT_CFG_SLA_FEATURE)
  ubit8_t SPEED_LIMIT_ACCEPTED         :1; /* speed limit accepted from driver, if SLA support is active (FCT_CFG_SLA_FEATURE) */
  ubit8_t SPEED_LIMIT_DECLINED         :1; /* speed limit declined from driver, if SLA support is active (FCT_CFG_SLA_FEATURE) */
  ubit8_t                              :6;
#endif
} cc_driver_operations_t;


/*! @brief Status bits for the driver requests */
typedef struct cc_driver_request_status_t {
  ubit8_t ACTUAL_SPEED_TAKEN_OVERRIDE :1;
  ubit8_t ACTUAL_SPEED_TAKEN_OBJECT   :1;
  ubit8_t ACTUAL_SPEED_TAKEN_SET      :1;
  ubit8_t OVERRIDE_WHILE_ENGAGEMENT   :1; /* Override happens just after engagement. Lever buttons to not be used for taking current speed */
  ubit8_t SELECTED_FUNCTION_ACTIVE    :1;
  ubit8_t TIMED_INCREMENT             :1;
  ubit8_t TIMED_DECREMENT             :1;
  ubit8_t                             :1;
} cc_driver_request_status_t;

/*! @brief Data that reflects the drivers request intention */
typedef struct cc_driver_requests_t {
  cc_driver_operations_t        DRIVER_OPERATIONS;
  cc_driver_operations_t        DRIVER_OPERATIONS_LAST_CYCLE;
  cc_engagement_conditions_t    ENGAGEMENT_CONDITIONS;
  display_op_status_t           OPERATIONAL_MODE;
  cc_control_state_t            CONTROL_STATE_LAST_CYCLE;
  cc_control_state_t            CONTROL_STATE;
  cc_control_state_t            CONTROL_STATE_PLIM;
  cc_control_mode_t             CONTROL_MODE;
  setspeed_t                    CC_SETSPEED;
  setspeed_t                    MIN_CC_SETSPEED;
  setspeed_t                    MAX_CC_SETSPEED;
  setspeed_t                    MIN_CC_ENGAGESPEED;
  setspeed_t                    MAX_CC_SPEED;
  setspeed_t                    CC_DISENGAGE_THRESHOLD;
#if (CFG_FCT_LIM || CFG_FCT_PLIM)
  setspeed_t                    LIM_SETSPEED;
  setspeed_t                    MIN_LIM_SETSPEED;
  setspeed_t                    MAX_LIM_SETSPEED;
  setspeed_t                    PLIM_THRESHOLD;
  setspeed_t                    PLIM_HYST;
  speedometer_speed_t           PLIM_VLIMIT;
#endif
#if (!LONG_CFG_USE_EXTERN_ACC_STATE_MACHINE)
  setspeed_t                    SETSPEED_STEP_LEVEL_1;
  setspeed_t                    SETSPEED_STEP_LEVEL_2;
#else
  /* Setspeed from external input signal */
  cc_setspeed16_t               CC_SETSPEED_CUSTOM;
#endif
  speedometer_speed_t           SPEEDOMETER_VEHICLE_SPEED;
  speedometer_speed_t           SPEEDOMETER_VEHICLE_SPEED_OFFSET;
  cc_driver_request_status_t    DRIVER_REQUEST_STATUS;
  times_t                       DRIVE_OFF_TIME;
  times_t                       STAND_STILL_TIME;
} cc_driver_requests_t;


/*! @brief selected CC function*/
typedef struct cc_driver_controls_t {
  uint32           DUMMY_FOR_ALIGNMENT;
  cc_selected_function_t SELECTED_FUNCTION;
  cc_selected_function_t SELECTED_FUNCTION_LAST_CYCLE;
} cc_driver_controls_t;


/*! @brief Status bits for the acceleration control */
typedef struct cc_accel_status_t {
  ubit8_t LAT_ACCEL_LIM_ACTIVE      :1;
  ubit8_t DECEL_LIM_ENGAGE          :1;
  ubit8_t OBJECT_EFFECTIVE          :1;
  ubit8_t ACCEL_RAMP_ACTIVE         :1;
  ubit8_t ALLOW_INIT                :1;
  ubit8_t CANCEL_RAMP               :1;
  ubit8_t RAPID_RAMP                :1;
  ubit8_t NO_RAMP                   :1;
} cc_accel_status_t;


/*! @brief Data for the speed control */
typedef struct cc_control_data_t {
  acceleration_t  LIM_ACCELERATION;
  acceleration_t  CC_ACCELERATION;
  acceleration_t  MAXIMUM_ACCELERATION_LIMIT;
  acceleration_t  MINIMUM_ACCELERATION_LIMIT;
  gradient_t      ACCELERATION_REQUEST_GRAD;
  boolean         DECEL_LIM_OVERRIDE_ACTIVE;
  boolean         CC_ACC_TO_CC_TRANSITION;
#if (CFG_FCT_CC_USE_DECEL_LIM_OVERRIDE)
  uint16          DECEL_LIM_ACTIVE_COUNTER;
#endif
  times_t         CC_ACCEL_FILTER_TIME;
#if (FCT_CFG_SLA_FEATURE)
  t_SLA_Ctrl_Data CC_SLA_CTRL_DATA;
#endif
} cc_control_data_t;


/*! @brief Data for the acceleration control */
typedef struct cc_acceleration_control_data_t {
  acceleration_t MAXIMUM_ACCELERATION_LATERAL_LIMITED;
#if (KMC_CFG_CUSTOM_LAT_LIM)  
  acceleration_t MAXIMUM_ACCELERATION_LATERAL_LIMITED_CUSTOM;
#endif 
  acceleration_t MAXIMUM_COMMANDED_ACCELERATION;
  acceleration_t MINIMUM_COMMANDED_ACCELERATION;
  acceleration_t MAXIMUM_REQUESTED_ACCELERATION;
  acceleration_t MINIMUM_REQUESTED_ACCELERATION;
#if (CFG_FCT_CC_SMOOTH_ACCEL_REQUEST)
  acceleration_t MAXIMUM_REQUESTED_ACCELERATION_FILTERED;
  acceleration_t MINIMUM_REQUESTED_ACCELERATION_FILTERED;
#endif
  acceleration_t MAXIMUM_REQUESTED_ACCELERATION_LAST_CYCLE;
  acceleration_t MINIMUM_REQUESTED_ACCELERATION_LAST_CYCLE;
#if (CFG_FCT_CC_USE_ACCEL_BAND_MODIFICATION)
  acceleration_t MIN_ACCEL_POS_BAND;
  acceleration_t MIN_ACCEL_NEG_BAND;
  acceleration_t MAX_ACCEL_POS_BAND;
  acceleration_t MAX_ACCEL_NEG_BAND;
#endif
  acceleration_t MIN_ALLOWED_ACCEL;
  acceleration_t MAX_ALLOWED_ACCEL;
  acceleration_t MAX_CUSTOM_ALLOWED_ACCEL;
  acceleration_t MIN_CUSTOM_ALLOWED_ACCEL;
  gradient_t MAX_CUSTOM_ALLOWED_GRAD;
  gradient_t MIN_CUSTOM_ALLOWED_GRAD;
  cc_accel_status_t ACCEL_STATUS;
} cc_acceleration_control_data_t;

/*! @brief CC SystemStatus */
typedef struct cc_system_status_t {
  ubit8_t SHUTDOWN_RAMP    :1;
  ubit8_t SHUTDOWN_SIGNAL  :1;
  ubit8_t DISENGAGE_SIGNAL :1;
  ubit8_t                  :5;
} cc_system_status_t;


/*! @brief CC status data*/
typedef struct cc_status_t {
  cc_driver_requests_t            CC_DRIVER_REQUESTS;
  cc_acceleration_control_data_t  CC_ACCEL_CONTROL_DATA;
  cc_control_data_t               CC_CONTROL_DATA;
#if (FCT_CFG_SLA_FEATURE)
  t_SLA_HMI_Data                  CC_SLA_HMI_DATA;
#endif
  cart_lodm_status_t              LODM_STAT_LAST_CYCLE;
  acceleration_t                  CC_LAT_ACCEL_LAST_CYCLE;
  gradient_t                      CC_LAT_ACCEL_GRAD_LAST_CYCLE;
  uint16                          CC_ENGAGE_OVERRIDE_COUNTER;
  uint16                          CC_ABS_ACT_CNT;
  uint16                          CC_ESP_ACT_CNT;
  uint16                          CC_TCS_ACT_CNT;
  uint32                          CC_DECEL_ONLY_MODE_CNT;
  uint8                           CC_SPEED_UNIT_LAST_CYCLE;
} cc_status_t;

/*! @brief CC error data*/
typedef struct cc_error_data_t {
  cc_reported_error_t REPORTED_ERROR;
  ubit8_t             CC_INHIBIT          :1; /* CC can not be activated */
  ubit8_t             LIM_INHIBIT         :1; /* LIM can not be activated */
  ubit8_t             SHUTDOWN_RAMP       :1; /* Switch-Off with ramp */
  ubit8_t             SHUTDOWN_DECEL_ONLY :1; /* Switch-Off decel only */
  ubit8_t             DISENGAGE_SIGNAL    :1; /* Switch-Off msg 1. This bit is set when the active function is disengaged without intervention from the driver */
  ubit8_t             SHUTDOWN_SIGNAL     :1; /* Switch-Off msg 2 */
  ubit8_t                                 :2;
} cc_error_data_t;

/*****************************************************************************
  CONSTANTS (COMPONENT EXTERN)
*****************************************************************************/


/*****************************************************************************
  VARIABLES (COMPONENT EXTERN)
*****************************************************************************/


/*****************************************************************************
  FUNCTIONS (COMPONENT EXTERN)
*****************************************************************************/
extern void KMC_v_LimitLateralAccel(const times_t cycle_time, const cc_input_data_t* input, const acc_output_data_t* acc_output, const cart_das_input_data_t* das_input, cc_status_t *cc_status);
extern void KMC_v_CommandAcceleration(const times_t cycle_time, const cc_input_data_t* input, const cart_das_input_data_t* das_input, const acc_output_data_t* acc_output, cart_das_output_data_t* das_output, cc_status_t *cc_status);
extern void KMC_v_DetermineControlstateSetspeed(const times_t cycle_time, const cart_das_input_data_t* das_input, const cc_driver_controls_t* driver_controls, const cc_input_data_t* input, cc_error_data_t* error_data, cart_das_output_data_t* das_output, cc_status_t *cc_status, const acc_output_data_t* acc_output);
extern void KMC_v_InitHMI(const cc_input_data_t* input_data, cc_status_t *cc_status);
extern void KMC_v_InitCC(cc_input_data_t* cc_input, cc_driver_controls_t* driver_controls, cc_status_t *cc_status);

DLLEXPORT void KMC_v_ProcessMain(const times_t cycle_time, 
                                 cc_driver_controls_t* driver_controls, 
                                 const cc_input_data_t* cc_input, 
                                 cc_error_data_t *error_data, 
                                 const cart_das_input_data_t* das_input,
                                 cart_das_output_data_t* das_output, 
#if (FCT_CFG_ACC_HEADWAY_PLANNER)
                                 const acc_output_data_t* acc_output, 
#endif
                                 cc_status_t *cc_status);


#if (FCT_CFG_SLA_FEATURE)
extern t_u_DistanceLong KMC_t_DetermSLACtrlDistBeforeLimit(const t_SLA_SpeedLimit* SLA_SpeedLimit,
                                                           const velocity_t vehicle_speed,
                                                           const cc_driver_requests_t* driver_requests);
extern t_u_DistanceLong KMC_t_DetermSLACtrlDistAfterLimit(const t_SLA_SpeedLimit* SLA_SpeedLimit,
                                                          const velocity_t vehicle_speed,
                                                          const cc_driver_requests_t* driver_requests);
extern acceleration_t KMC_t_CalculateSLAAccel(const boolean b_SpeedUnit_KMH,
                                             const velocity_t vehicle_speed,
                                             const setspeed_t SpeedLimit,
                                             const t_u_DistanceLong sla_ctrl_distance,
                                             const cc_driver_requests_t* driver_requests);
#endif /* FCT_CFG_SLA_FEATURE */


#if ((FCT_CFG_LOPC_COMPONENT) && (LOPC_CFG_KMC))
#if (LONG_CFG_USE_EXTERN_ACC_STATE_MACHINE)

extern void KMC_v_ProcessExternalACCInterfaces(const cc_input_data_t* pCcInputData,
                                                  const cc_error_data_t* error_data,
                                                  cc_driver_requests_t* driver_requests,
                                                  cart_das_output_data_t* das_output);

#endif/*LONG_CFG_USE_EXTERN_ACC_STATE_MACHINE*/
#endif/*(FCT_CFG_LOPC_COMPONENT) && (LOPC_CFG_KMC)*/


#if ((FCT_CFG_LOPC_COMPONENT) && (LOPC_CFG_KMC))

extern void KMC_v_InitDASOutputData(cart_das_output_data_t* das_output_data);
extern void KMC_v_InitDASInputData(cart_das_input_data_t* das_input_data);
#endif

#if (KMC_CFG_CUSTOM_ACCEL_ARBITRATION)
extern void KMC_ACC_CUSTOM_ARBITRATION(const cc_driver_requests_t* driver_requests, const acc_output_data_t* acc_output, 
                                  cc_control_data_t* cc_control_data, cc_acceleration_control_data_t* accel_control_data,
                                  const cart_das_input_data_t* das_input, LongCtrlOutput_t* pLongCtrlCmd);
#endif /* KMC_CFG_CUSTOM_ACCEL_ARBITRATION */

#endif  /* (FCT_CFG_LOPC_COMPONENT) && (FCT_CFG_CC) && (LOPC_CFG_KMC) */

/** @} end defgroup */

#endif /* KMC_H_INCLUDED */


