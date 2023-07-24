/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC/LOPC/KMC (Adaptive Cruise Control - Longitudinal Planner and Controller - Kinematic Motion Control)

PACKAGENAME:               kmc_customfunctions.c

DESCRIPTION:               File containing custom functions for KMC in LOPC

AUTHOR:                    Mistry Niraj (uidq5738)

CREATION DATE:             24.02.2017

VERSION:                   $Revision: 1.22.9.3 $

LEGACY VERSION:            Revision: 1.29.1.2
**************************************************************************** */

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/*!
@defgroup         kmc_customfuncs   Kmc_Customfunctions
@ingroup          kmc_custom
@brief            File containing custom functions for KMC
@{
*/

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "kmc.h"
#include "kmc_custom.h"
#include "cml_trigo.h"


#if ((FCT_CFG_LOPC_COMPONENT) && (LOPC_CFG_KMC))

#if ((!FCT_CFG_CC) && (FCT_CFG_ACC_HEADWAY_PLANNER))
#error "FCT_CFG_ACC_HEADWAY_PLANNER needs FCT_CFG_CC!"
#endif

/*****************************************************************************
  MACROS 
*****************************************************************************/


/*****************************************************************************
  MODULE LOCAL TYPES
*****************************************************************************/

/*****************************************************************************
  MODULE LOCAL CONSTANTS
*****************************************************************************/

#if (FCT_CFG_SLA_FEATURE)
#define MAX_EXRAPOLATION_DEVIATION (199u)
#define MAX_SLA_SPEED_KPH (setspeed_t)130
#define MAX_SLA_SPEED_MPH (setspeed_t)100
#define MIN_SLA_SPEED_KPH (setspeed_t)30
#define MIN_SLA_SPEED_MPH (setspeed_t)20
#define MAX_SLA_OFFSET_KPH (setspeed_t)10
#define MAX_SLA_OFFSET_MPH (setspeed_t)5
#define SLA_INTIALIZE_SPEED (setspeed_t)0
#define SLA_SPEED_URBAN (setspeed_t)50
#define SLA_SPEED_HIGHWAY (setspeed_t)130
#define UINT8_MAX_RANGE 255u
#define SLA_SPD_DISPLAY_TIME (times_t) 5000

/*!< Cfg switch On when no information of implicit signs are received 
    because of no navi input or not supported by camera
    Leads to SLA manual mode and saving of setspeeds in explicit zones also */
#define KMC_CFG_SLA_EXPLICIT_SIGNS_ONLY (1)
#endif /* FCT_CFG_SLA_FEATURE */



//////////////////define value here//////////////////////

#define ACCFailureMode_NoError     0
#define ACCFailureMode_TempError   1
#define ACCFailureMode_PermError   2

#define StandStillState_None				0U
#define StandStillState_StandActive			1U
#define StandStillState_StandWait			2U
#define StandStillState_Deactivating		3U

#define Kmc_overridetime_counter_C      45000U  //15 min counter 
#define Kmc_standstill_counter_C        9000U //3 min counter
#define Kmc_standstill_3sec_counter_C   (9000 - 150)  //3 sec counter

#define Switch_Debounce_Time            1  //100ms
#define Headway_Handbag_Time            50  //1000ms
#define CCMode_LongPress_Time           50  //1000ms
#define TJA_Active_Time                 40  //800ms
#define TJA_Deactive_Time               25  //500ms

#define StateAccLowSpd_UNDEFINED          (uint8)0
#define StateAccLowSpd_INIT               (uint8)1
#define StateAccLowSpd_OBJ_DETECTED       (uint8)2
#define StateAccLowSpd_ACC_CANCEL         (uint8)3

#define DistThdAccLowSpdCancel            ((distance_t)600)    /* 30 m */
#define DistThdAccLowSpdImmediateCancel   ((distance_t)500)    /* 5 m */
#define VehSpdThdAccLowSpdCancel          ((velocity_t)1000) /* 10 m/s = 36 km/h */
#define ACCTextMessage_Display_Counter      (uint8)150  //3s

#define ACCTextMessage_NoDisplay            (uint8)0
#define ACCTextMessage_Unable2ActiveACC     (uint8)1
#define ACCTextMessage_ACCCancelled         (uint8)2
#define ACCTextMessage_ACCActive            (uint8)3
#define ACCTextMessage_ACCErrorMode         (uint8)4
#define ACCTextMessage_ACCWwitchedOn        (uint8)5
#define ACCTextMessage_ACCSwitchedOff       (uint8)6
#define ACCTextMessage_TakeoverRequest      (uint8)7
#define ACCTextMessage_AccelOrResume2Go     (uint8)8
#define ACCTextMessage_ACCOverride          (uint8)9

#define Kmc_cc_fsr_min_setspeedhys_kmh      500    //5kph  /*%unit:km/h|mph*/
#define Kmc_cc_fsr_min_setspeed_kmh         3000   //30kph

#define Cc_max_softstop_request_distance    600     //6m
#define Cc_max_softstop_request_velocity    111     //1.11m/s   4kph

#define ShutdownMode_SoftOff           0
#define ShutdownMode_FastOff           1
#define ShutdownMode_ImmediateOff      2
#define ShutdownMode_NoReq             3

#define ObjectDetection_Detected		0U
#define ObjectDetection_Losing			1U
#define ObjectDetection_Lost 			2U

#define OBJECTDETECTION_LOSING_DURATION			25 // 500ms

#define	INHIBITREASON_CC_INHIBIT_DAS_ENABLE	1	//1
#define	INHIBITREASON_CC_INHIBIT_POWER_BATTERY_FAIL	2	//2

#define	INHIBITREASON_NO_RAMP_CC_SIGNALCHECK_FAIL	1	//1
#define	INHIBITREASON_NO_RAMP_INHIBIED	2	//2
#define	INHIBITREASON_NO_RAMP_CC_INHIBIT	4	//3
#define	INHIBITREASON_NO_RAMP_REPORTED_ERROR	8	//4
#define	INHIBITREASON_NO_RAMP_PARK_BRAKE_ACTIVE	16	//5
#define	INHIBITREASON_NO_RAMP_DRIVER_BRAKE_WHEN_EGO_VEHICLE_MOVING	32	//6
#define	INHIBITREASON_NO_RAMP_ACTUATOR_OFF	64	//7
#define	INHIBITREASON_NO_RAMP_CDP_ACTIVE	128	//8
#define	INHIBITREASON_NO_RAMP_SPEEDOSPEED_GREATER_THAN_MAX_ENGAGE_SPEED	256	//9
#define	INHIBITREASON_NO_RAMP_SPEEDOSPEED_LESS_THAN_MIN_ENGAGE_SPEED	512	//10
#define	INHIBITREASON_NO_RAMP_AEB_ACTIVE	1024	//11
#define	INHIBITREASON_NO_RAMP_CLOSE_OBJECT_LOST	2048	//12
#define	INHIBITREASON_NO_RAMP_EGO_VEHICLE_ROLLING_BACK	4096	//13
#define	INHIBITREASON_NO_RAMP_TCU_FAIL	8192	//14
#define	INHIBITREASON_NO_RAMP_ACTUATOR_FUNCTION_FAIL	16384	//15

#define	INHIBITREASON_RAPID_RAMP_OVERRIDE_OVERTIME	1	//1
#define	INHIBITREASON_RAPID_RAMP_STADNSTILL_STATE_OVERTIME	2	//2

#define	INHIBITREASON_RAMP_SOFT_OFF_AND_VEHICLE_NOT_DECELERATING	1
#define	INHIBITREASON_RAMP_SOFT_OFF	2
#define	INHIBITREASON_RAMP_BOM_STATE_AND_NOT_OBJ_EFFECTIVE	4
#define	INHIBITREASON_RAMP_BOM_STATE_AND_VEHICLE_NOT_BRAKING	8
#define	INHIBITREASON_RAMP_BOM_STATE_AND_NO_BRAKEFORCE	16
#define	INHIBITREASON_RAMP_BOM_STATE_AND_DRIVER_BRAKING	32
#define	INHIBITREASON_RAMP_BOM_STATE_AND_DRIVER_ACCELERATING	64
#define	INHIBITREASON_RAMP_BOM_STATE_AND_EGO_VEHICLE_STANDSTILL	128
#define	INHIBITREASON_RAMP_BOM_STATE_OVERTIME	256

#define	INHIBITREASON_INHIBIT_ENGAGEMENT_NO_BRRAKING_WHEN_STANDSTILL	1	//1

#define	INHIBITREASON_SOFT_OFF_CONDITION_GEAR_PNR	1	//1
#define	INHIBITREASON_SOFT_OFF_CONDITION_MANUNAL_GEAR	2	//2
#define	INHIBITREASON_SOFT_OFF_CONDITION_DOOR_OPEN_FRONT_LEFT	4	//3
#define	INHIBITREASON_SOFT_OFF_CONDITION_DOOR_OPEN_FRONT_RIGHT	8	//4
#define	INHIBITREASON_SOFT_OFF_CONDITION_DOOR_OPEN_REAR_LEFT	16	//5
#define	INHIBITREASON_SOFT_OFF_CONDITION_DOOR_OPEN_REAR_RIGHT	32	//6
#define	INHIBITREASON_SOFT_OFF_CONDITION_ENGINE_HOOD_OPEN	64	//7
#define	INHIBITREASON_SOFT_OFF_CONDITION_TRUNK_OPEN	128	//8
#define	INHIBITREASON_SOFT_OFF_CONDITION_SEATBELT_OPEN	256	//9
#define	INHIBITREASON_SOFT_OFF_CONDITION_HDC_ACTIVE	512	//10
#define	INHIBITREASON_SOFT_OFF_CONDITION_ESP_ACTIVE	1024	//11
#define	INHIBITREASON_SOFT_OFF_CONDITION_TCS_ACTIVE	2048	//12
#define	INHIBITREASON_SOFT_OFF_CONDITION_ABS_ACTIVE	4096	//13
#define	INHIBITREASON_SOFT_OFF_CONDITION_ESP_FAIL	8192	//14
#define	INHIBITREASON_SOFT_OFF_CONDITION_TCS_FAIL	16384	//15
#define	INHIBITREASON_SOFT_OFF_CONDITION_ABS_FAIL	32768	//16
#define	INHIBITREASON_SOFT_OFF_CONDITION_ENGINE_NOT_OK	65536	//17
#define INHIBITREASON_SOFT_OFF_CONDITION_CANCEL_BUTTON 131072    //18
/*****************************************************************************
 APPLICATION PARAMETERS 
*****************************************************************************/

/*! Headway_Setting = 0   % means 1 sec of Timegap */
/*! Headway_Setting = 100 % means 2 sec of Timegap */

#define Headway_Setting_level_4			(percentage_t)130
#define Headway_Setting_level_3			(percentage_t)90
#define Headway_Setting_level_2			(percentage_t)50
#define Headway_Setting_level_1			(percentage_t)0

#if (KMC_CFG_AUTOGO_FEATURE)
#define FCT_PAR_LONG_VEH_AUTOGO_TIME_MAX    (times_t)       (15.0f * Time_s)         // 15.0 s
#define FCT_PAR_LONG_VEH_CREEP_ACCEL_MAX    (acceleration_t)( 1.0f * Acceleration_s) //  1.0 m/s^2
#define FCT_PAR_LONG_VEH_STOP_DECEL_MIN     (acceleration_t)(-5.0f * Acceleration_s) // -5.0 m/s^2
#define FCT_PAR_LONG_VEH_CREEP_DIST_THR     10.0F                                    // 10.0 m
#define FCT_PAR_LONG_VEH_AUTO_STOP          FALSE
#endif

#define KMC_DRIVEOFF_CONFIRM_DURATION (times_t) 1000 /* Driver confirmation for driveoff valid for 1s */


/*****************************************************************************
  MODULE VARIABLES 
*****************************************************************************/

#if (FCT_CFG_CC)
static kmc_static_mem_u_t KMC_STATIC_MEMORY_UNION;
/* date: 2015-09-16, reviewer: Chirag Patel, reason: static local required for saving data across function calls */
static cart_das_input_data_t   DAS_INPUT_DATA_LAST_CYCLE;
/* date: 2015-09-16, reviewer: Chirag Patel, reason: static local required for saving data across function calls */

#endif  /* FCT_CFG_CC */



static fct_inhibit_storage_t INHIBIT_BUFFER; // PRQA S 3218
/* date: 2015-09-16, reviewer: Chirag Patel, reason: static local required for saving data across function calls */

#if (KMC_CFG_AUTOGO_FEATURE)
/* OOI Object at hold transition */
static ObjNumber_t t_OOIObjNr = OBJ_INDEX_NO_OBJECT;// PRQA S 3203
/* date: 2018-03-21, reviewer: Ravi kiran Gurrala, reason: Redundant, but may be used in future*/
boolean fct_par_long_veh_auto_stop;// PRQA S 3408
/* date: 2018-03-22, reviewer: Ravi Kiran Gurrala, reason: Not Safety critical */
#endif

static boolean b_KmcIsInitialized = FALSE;/*PRQA S 3218  */
/* date: 2018-03-22, reviewer: Ravi Kiran Gurrala, reason: kept here for better maintainability*/

#if (FCT_CFG_ACC_HEADWAY_PLANNER)
static percentage_t HeadwaySetting = Kmc_acc_default_headway_setting;
#endif
#if (!CFG_FCT_USE_VDY_HOST_ACCEL)
  /* low pass filter value for velocity */
  static float32 VehVeloFlt = 0.0F;
#endif

  /*! Variables of KMC_v_DetermineDriverOperations */
#if (CFG_FCT_USE_TWICE_CONFIRMATION_FOR_DRIVE_OFF)
static times_t DriveOffConfirmation_Timer = Cc_default_drive_off_confirmation_time;
static uint8           DriveOffConfirmation = FALSE;
#endif
static boolean b_Stand_Still_Request; /*!< Boolean providing stand still request as output */
static times_t ui_Drive_Off_Confirmation_Timer; /*!< Timer to store driver driveoff confirmation value */


#if (FCT_CFG_SLA_FEATURE)
static distance_t u_DeltaDist;
static t_u_DistanceLong u_SpeedLimitDistLC; /*!< Last cycle extrapolated speed limit distance */
static times_t uiSLA_MsgDisplayTimer = 0u;
static boolean b_NewUnrestictedSign;        /*!< Boolean indicating first detection of new unrestricted speed limit sign */
static t_SLA_SpeedLimit SLA_SpeedLimitNow;
static setspeed_t Min_sla_speed;
static setspeed_t Max_sla_speed;
static times_t uiSLA_ManUsageTimer = 0u; /*!< Timer to select usage of resume button between SLA and CC */
#if (KMC_CFG_SLA_EXPLICIT_SIGNS_ONLY == SWITCH_OFF)
static boolean b_ImplicitSpeedZone;         /*!< Boolean indicating vehicle currently in an implicit speed zone (city/highway) */
static boolean b_ImplicitSpeedZoneEntry;    /*!< Boolean indicating recent entry into implicit zone. Rising Edge of b_ImplicitSpeedZone */
static boolean b_SpeedLimitSavedForRetake;  /*!< Speed saved for retaking (after Unrestricted sign) at u_SLA_DriverLastSetSpeed is a traffic sign speed limit. Else it is a setspeed from driver */
#endif

#endif  /* FCT_CFG_SLA_FEATURE */


/////////////variable here//////////////////////
SET_MEMSEC_VAR(Kmc_overridetime_counter)
static uint16 Kmc_overridetime_counter = Kmc_overridetime_counter_C;

SET_MEMSEC_VAR(Kmc_standstill_counter)
static uint16 Kmc_standstill_counter = Kmc_standstill_counter_C;

SET_MEMSEC_VAR(Kmc_Standstillstate)
static uint8  Kmc_Standstillstate = StandStillState_None;/*PRQA S 3218, 3229  */
/* date: 2019-06-03, reviewer: zhihua zhuang, reason: kept here for better maintainability*/

SET_MEMSEC_VAR(StateAccLowSpd)
static uint8  StateAccLowSpd = StateAccLowSpd_UNDEFINED;

SET_MEMSEC_VAR(ACC_Cancellation_Flag)
static boolean ACC_Cancellation_Flag = FALSE;

SET_MEMSEC_VAR(DistObjBeforeLoss)
static float32 DistObjBeforeLoss = 0.0F;

SET_MEMSEC_VAR(objstatus_detect_lastcycle)
static boolean objstatus_detect_lastcycle = FALSE;// PRQA S 3229, 3218
/* date: 2019-06-03, reviewer: zhihua zhuang, reason: static local for saving data across function calls/cycles - After the discussion it can be removed if not needed. */

SET_MEMSEC_VAR(ACC_State)
static uint8 ACC_State = ACC_STAT_OFF;

SET_MEMSEC_VAR(ACC_State_Last_Cycle)
static uint8 ACC_State_Last_Cycle;

SET_MEMSEC_VAR(b_Button_Resume_AccelSwitch_Inhibit)
static boolean b_Button_Resume_AccelSwitch_Inhibit = FALSE;

SET_MEMSEC_VAR(b_Button_Set_DecelSwitch_Inhibit)
static boolean b_Button_Set_DecelSwitch_Inhibit = FALSE;

SET_MEMSEC_VAR(b_Soft_Off_Condition)
static boolean b_Soft_Off_Condition;

#if (CN_ACCSM_BOM)
SET_MEMSEC_VAR(b_BOM_Enter_Conditions)
static boolean b_BOM_Enter_Conditions;

SET_MEMSEC_VAR(b_BOM_Exists)
static boolean b_BOM_Exists;

SET_MEMSEC_VAR(u_BOM_Counter)
static uint32 u_BOM_Counter;
#endif

SET_MEMSEC_VAR(InhibitReason_CC_INHIBIT)
static uint32 InhibitReason_CC_INHIBIT;

SET_MEMSEC_VAR(InhibitReason_No_Ramp)
static uint32 InhibitReason_No_Ramp;

SET_MEMSEC_VAR(InhibitReason_Rapid_Ramp)
static uint32 InhibitReason_Rapid_Ramp;

SET_MEMSEC_VAR(InhibitReason_Ramp)
static uint32 InhibitReason_Ramp;

SET_MEMSEC_VAR(InhibitReason_Inhibit_Engagement)
static uint32 InhibitReason_Inhibit_Engagement;

SET_MEMSEC_VAR(InhibitReason_Soft_Off_Condition)
static uint32 InhibitReason_Soft_Off_Condition;

SET_MEMSEC_VAR(b_flag_igon)
static boolean b_flag_igon = TRUE;
/*****************************************************************************
  MODULE LOCAL FUNCTIONS
*****************************************************************************/
static void KMC_v_Init(void);

#if (FCT_CFG_CC)
static void KMC_v_InputWrapper(const times_t cycle_time,
                               const VehDyn_t* pVehDyn,
#if (CFG_ACC_LEVER_INPUT)
                               const AccLeverInput_t* pAccLever,
#endif
                               const LongCtrlInput_t* pLongCtrlResp,
                               const PowerTrain_t * pPowerTrain,
                               cart_das_input_data_t* das_input_data,
#if (CFG_ACC_LEVER_INPUT)
                               cc_driver_inputs_t* driver_inputs,
#endif
                               cc_status_t* cc_status,
                               FctVeh2SenInfo_t* pFctVehLongOut,
                               cc_driver_controls_t* driver_controls,
                               cc_input_data_t* cc_input,
							   cc_error_data_t* error_data
                              );

static void KMC_v_SignalInhibitionCheck(const VehDyn_t * pVehDyn,
#if (CFG_ACC_LEVER_INPUT)
                                       const AccLeverInput_t * pAccLever,
#endif
                                       const LongCtrlInput_t * pLongCtrlResp,
                                       cc_input_data_t* cc_input_data,
                                       uint16* Inhibit_nr);

static void KMC_v_InhibitionCheck(const times_t cycle_time,
                                  const VehDyn_t* pVehDyn,
                                  const LongCtrlInput_t* pLongCtrlResp,
                                  const cart_das_input_data_t* das_input_data,
                                  const cart_das_input_data_t* das_input_data_last_cycle,
                                  const cc_driver_controls_t *driver_controls,
#if (FCT_CFG_ACC_HEADWAY_PLANNER)
                                  const acc_output_data_t* acc_output,
#endif
								  const cc_driver_inputs_t *driver_inputs,
                                  cc_input_data_t* input, 
                                  cc_error_data_t *error_data,
                                  cc_status_t *cc_status,
								  cc_driver_information_t* driver_information);

static void KMC_v_InhibitionCheck_CC_INHIBIT(const times_t cycle_time,
                                            const VehDyn_t* pVehDyn,
                                            const LongCtrlInput_t* pLongCtrlResp,
                                            const cart_das_input_data_t* das_input_data,
                                            const cart_das_input_data_t* das_input_data_last_cycle,
                                            const cc_driver_controls_t *driver_controls,
#if (FCT_CFG_ACC_HEADWAY_PLANNER)
                                            const acc_output_data_t* acc_output,
#endif
                                            cc_input_data_t* input, 
                                            cc_error_data_t *error_data,
                                            cc_status_t *cc_status);

static void KMC_v_InhibitionCheck_No_Ramp(const times_t cycle_time,
		                                  const VehDyn_t* pVehDyn,
		                                  const LongCtrlInput_t* pLongCtrlResp,
		                                  const cart_das_input_data_t* das_input_data,
		                                  const cart_das_input_data_t* das_input_data_last_cycle,
		                                  const cc_driver_controls_t *driver_controls,
#if (FCT_CFG_ACC_HEADWAY_PLANNER)
		                                  const acc_output_data_t* acc_output,
#endif
		                                  cc_input_data_t* input, 
		                                  cc_error_data_t *error_data,
		                                  cc_status_t *cc_status);

static void KMC_v_InhibitionCheck_Rapid_Ramp(const times_t cycle_time,
                                             const VehDyn_t* pVehDyn,
                                             const LongCtrlInput_t* pLongCtrlResp,
                                             const cart_das_input_data_t* das_input_data,
                                             const cart_das_input_data_t* das_input_data_last_cycle,
                                             const cc_driver_controls_t *driver_controls,
#if (FCT_CFG_ACC_HEADWAY_PLANNER)
                                             const acc_output_data_t* acc_output,
#endif
                                             cc_input_data_t* input, 
                                             cc_error_data_t *error_data,
                                             cc_status_t *cc_status);

static void KMC_v_InhibitionCheck_Ramp(const times_t cycle_time,
                                       const VehDyn_t* pVehDyn,
                                       const LongCtrlInput_t* pLongCtrlResp,
                                       const cart_das_input_data_t* das_input_data,
                                       const cart_das_input_data_t* das_input_data_last_cycle,
                                       const cc_driver_controls_t *driver_controls,
#if (FCT_CFG_ACC_HEADWAY_PLANNER)
                                       const acc_output_data_t* acc_output,
#endif
                                       cc_input_data_t* input, 
                                       cc_error_data_t *error_data,
                                       cc_status_t *cc_status);

static void KMC_v_InhibitionCheck_Inhibit_Engagement(const times_t cycle_time,
                                                     const VehDyn_t* pVehDyn,
                                                     const LongCtrlInput_t* pLongCtrlResp,
                                                     const cart_das_input_data_t* das_input_data,
                                                     const cart_das_input_data_t* das_input_data_last_cycle,
                                                     const cc_driver_controls_t *driver_controls,
#if (FCT_CFG_ACC_HEADWAY_PLANNER)
                                                     const acc_output_data_t* acc_output,
#endif
                                                     cc_input_data_t* input, 
                                                     cc_error_data_t *error_data,
                                                     cc_status_t *cc_status);

static void KMC_v_InhibitionCheck_Soft_Off_Condition(const times_t cycle_time,
                                                     const VehDyn_t* pVehDyn,
                                                     const LongCtrlInput_t* pLongCtrlResp,
                                                     const cart_das_input_data_t* das_input_data,
                                                     const cart_das_input_data_t* das_input_data_last_cycle,
                                                     const cc_driver_controls_t *driver_controls,
#if (FCT_CFG_ACC_HEADWAY_PLANNER)
                                                     const acc_output_data_t* acc_output,
#endif
													 const cc_driver_inputs_t *driver_inputs,
                                                     cc_input_data_t* input, 
                                                     cc_error_data_t *error_data,
                                                     cc_status_t *cc_status,
													 cc_driver_information_t* driver_information);

#if (FCT_CFG_SLA_FEATURE)
static t_u_DistanceLong KMC_t_SLACalcSpeedlimitDist(const times_t cycle_time,
                                                    const t_u_DistanceLong uSpeedLimitDistance,
                                                    const velocity_t vehicle_speed,
                                                    const t_SLA_SpeedLimit* SLA_SpeedLimit);
static void KMC_v_SLADetermineSpeedlimitState(const cc_input_data_t* cc_input,
                                              const t_SLA_HMI_Data* pSLA_HMI_Data,
                                              const cc_driver_requests_t* cc_driver_requests,
                                              t_SLA_SpeedLimit* pSLA_SpeedLimit,
                                              t_SLA_InputStatus* pSLA_InputStatus);
static void KMC_v_SLAInputWrapper(const times_t cycle_time,
                                  const LongCtrlInput_t* pLongCtrlResp,
#if (FCT_CFG_SLA_FEATURE)
                                  const SLAData_t* pSLAInputData,
#endif
                                  const cart_das_input_data_t* das_input_data,
                                  t_SLA_HMI_Data* pSLA_HMI_Data,
                                  cc_driver_requests_t* cc_driver_requests,
                                  cc_input_data_t* cc_input);

static void KMC_v_SLADetermineState(const SLAData_t* pSLAInputData,
                                    cc_input_data_t* cc_input,
                                    cc_status_t *cc_status);
#endif /* (FCT_CFG_SLA_FEATURE) */

static void KMC_v_DetermineDriverOperations(const times_t cycle_time,
                                            const cart_das_input_data_t* das_input,
                                            const cc_input_data_t* input,
                                            cc_driver_controls_t* driver_controls,
                                            const cc_error_data_t* error_data,
                                            cc_status_t *cc_status,
#if (CFG_ACC_LEVER_INPUT)
                                            cc_driver_inputs_t *driver_inputs
#else
                                            const acc_output_data_t * acc_output 
#endif
                                            );

static void KMC_v_LimitLongAccelCustom(const times_t cycle_time, cc_status_t *cc_status, const cc_input_data_t* input, const acc_output_data_t* acc_output, const cart_das_input_data_t* das_input, cart_das_output_data_t* das_output, cc_driver_information_t* driver_information
#if (FCT_CFG_SEN2VEH_ACC_OOI_PORT)
                                      ,const FCTSenAccOOI_t* pFCTAccOOIData
#endif
#if CN_ACCSM
                                      ,const acc_object_t * pAccDisplayObj
#endif
                                      );


static void KMC_v_ProcVehDriveOff(const times_t cycle_time,
                                  const LongCtrlInput_t* pLongCtrlResp,
                                  const FCTSenAccOOI_t* pFCTAccOOIData,
                                  cart_das_input_data_t* das_input,
                                  const cart_das_output_data_t* das_output,
                                  const acc_output_data_t* acc_output,
                                  cc_status_t *cc_status);


static void KMC_v_InformDriver(const cc_driver_requests_t* driver_requests,
                               const acc_output_data_t* acc_output,
#if (LONG_CFG_USE_EXTERN_ACC_STATE_MACHINE)
                               const cc_input_data_t* cc_input,
                               const cart_das_input_data_t* das_input,
#endif
                               const acc_object_t* display_object,
                               const cc_error_data_t* error_data,
                               cc_driver_information_t* driver_information,
                               cart_das_output_data_t* das_output);
#endif  /* FCT_CFG_CC */

static void KMC_v_FillVehToSenInfo(const cc_status_t* cc_status,
                                   const cart_das_input_data_t* das_input_data,
                                   const LongCtrlInput_t* pLongCtrlResp,
                                   FctVeh2SenInfo_t* pFctVehLongOut
                                  );

static void KMC_v_OutputWrapper(const times_t cycle_time, 
                                const FCTSenAccOOI_t* pFCTAccOOIData,
                                const acc_output_data_t* acc_output,
								const VehDyn_t* pVehDyn,
                                const cc_input_data_t* cc_input,
                                const cart_das_input_data_t* das_input_data,
                                const cart_das_output_data_t* das_output,
								const cc_driver_inputs_t* driver_inputs,
								const LongCtrlInput_t* pLongCtrlResp,
                                cc_driver_information_t* driver_information,
                                cc_status_t* cc_status,								
                                const cc_error_data_t* error_data,
                                LongCtrlOutput_t * pLongCtrlCmd);


static void KMC_v_SoftStopRequestFlag(const cart_das_output_data_t* pDasOutputData,
                                                     const cc_driver_information_t* pDriverInformation,
                                                     const velocity_t vehicle_speed,
                                                     const acc_object_t * pAccDisplayObj,
                                                     const cc_status_t * pCCStatus,
                                                     const acc_output_data_t * pAccOutput,
                                                     LongCtrlOutput_t * pLongCtrlCmd);


#if (FCT_CFG_CC)
/*************************************************************************************************************************
  Functionname:    KMC_v_Init                                                                                       */ /*!

  @brief           initialize longitudinal function data

  @description     initialize longitudinal function data

@startuml
Start
Partition KMC_v_Init(){
: initialize longitudinal function data;
: functions relating to KMC Initializations are called;
    Note right
    CC_SET_SWITCH
    RESUME_SWITCH
    CANCEL_SWITCH
    ACCEL_SWITCH_1
    ACCEL_SWITCH_2
    DECEL_SWITCH_1
    DECEL_SWITCH_2
    HEADWAY_DEC_SWITCH
    HEADWAY_INC_SWITCH
    HEADWAY_SETTING
    OBJECT_DETECTED information
    OPERATION MODE
    REPORTED_ERROR
    End note
}
end
@enduml


  @return          -

  @param[in]       -

  @glob_in         -
  @glob_out        CC_DRIVER_INF.CC_DRIVER_INF.ACC_DRIVE_OFF_POSSIBLE  : [true, false]
  @glob_out        CC_DRIVER_INF.CC_DRIVER_INF.BIT_ACC_ALERT : [true, false]
  @glob_out        CC_DRIVER_INF.CC_DRIVER_INF.BIT_DM_ALERT : [true, false]
  @glob_out        CC_DRIVER_INF.CC_DRIVER_INF.BIT_FCA_ALERT : [true, false]
  @glob_out        CC_DRIVER_INF.CC_DRIVER_INF.DRIVER_CONFIRMATION_NEEDED : [true, false]
  @glob_out        CC_DRIVER_INF.CC_DRIVER_INF.HEADWAY_SETTING : [percentage_t as per Rte_Type.h]
  @glob_out        CC_DRIVER_INF.CC_DRIVER_INF.OBJECT_DETECTED : [true, false]
  @glob_out        CC_DRIVER_INF.CC_DRIVER_INF.OPERATIONAL_MODE : [display_op_status_t as per Rte_Type.h]
  @glob_out        CC_DRIVER_INF.CC_DRIVER_INF.REPORTED_ERROR : [full range of unsigned char]
  @glob_out        cc_das_custom_state.CC_CUSTOM_DRIVER_OUTSIDE_HOLD : [true, false]
  @glob_out        cc_das_custom_state.CC_CUSTOM_STAND_STILL_HOLD : [true, false]
  @glob_out        cc_das_stop_go_state : [0,3]
  @glob_out        HeadwayThumbSettingLC : [percentage_t as per Rte_Type.h]
  @glob_out        HeadwaySetting : [percentage_t as per Rte_Type.h]
  @glob_out        drive_off_cycle_counter : [full range of unsigned char]
  @glob_out        stop_start_cycle_counter : [times_t as per Rte_Type.h]
  @glob_out        b_drive_off_confirm_last : [true, false]
  @glob_out        drive_off_min_accel_rq_timer : [true, false]
  @glob_out        DriveOffConfirmation_Timer : [times_t as per Rte_Type.h]
  @glob_out        DriveOffConfirmation : [true, false]
  @glob_out        set_speed_last_cycle : [full range of unsigned char]
  @glob_out        last_effective_object_id : [ObjNumber_t as per Rte_Type.h]
  @glob_out        uiOperationalTimer : [times_t as per Rte_Type.h]
  @glob_out        uiReTriggerSetTimer            : [times_t as per Rte_Type.h]
  @glob_out        uiReTriggerRequestTimer        : [times_t as per Rte_Type.h]
  @glob_out        uiReTriggerRepeatTimer         : [times_t as per Rte_Type.h]
  @glob_out        LDC_DTR_MsgDisp_Rq_RDU_Timer   : [times_t as per Rte_Type.h]
  @glob_out        uiDisplayDelayTimer            : [times_t as per Rte_Type.h]
  @glob_out        uiHeadwayDisplayTimer          : [times_t as per Rte_Type.h]
  @glob_out        last_object_id                 : [ObjNumber_t as per Rte_Type.h]
  @glob_out        bDriverInterventedOff : [true, false]
  @glob_out        bHeadwayChangeDetected : [true, false]
  @glob_out        uiInitHeadwaySettingTimer : [times_t as per Rte_Type.h]

  @c_switch_part   FCT_CFG_CC : Configuration switch for enabling CC processing
  @c_switch_part   CFG_FCT_USE_TWICE_CONFIRMATION_FOR_DRIVE_OFF : Only accept confirmation to drive off in standstill if driver as pressed Resume twice
  @c_switch_part   FCT_CFG_ACC_HEADWAY_PLANNER : Configuration switch for enabling ACC processing
  @c_switch_part   CFG_ACC_LEVER_INPUT : Configuration switch for enabling lever input
  @c_switch_full   FCT_CFG_LOPC_COMPONENT : Configuration switch for enabling LOPC processing
                   
  @pre             -
  @post            -
                   
  @created         -
  @changed         5/4/2016

  @author          -
*************************************************************************************************************************/
static void KMC_v_Init(void)
{
#if (FCT_CFG_CC)
  KMC_v_InitCC(&KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.CC_INPUT_DATA, &KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.CC_DRIVER_CONTROLS, &KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.CC_STATUS);
#if (CFG_ACC_LEVER_INPUT)
  SWITCH_INIT_SWITCH(&KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.CC_DRIVER_INPUTS.CC_SET_SWITCH);
  SWITCH_INIT_SWITCH(&KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.CC_DRIVER_INPUTS.CC_RESUME_SWITCH);
  SWITCH_INIT_SWITCH(&KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.CC_DRIVER_INPUTS.CC_CANCEL_SWITCH);
  SWITCH_INIT_SWITCH(&KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.CC_DRIVER_INPUTS.CC_ACCEL_SWITCH_1);
  SWITCH_INIT_SWITCH(&KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.CC_DRIVER_INPUTS.CC_ACCEL_SWITCH_2);
  SWITCH_INIT_SWITCH(&KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.CC_DRIVER_INPUTS.CC_DECEL_SWITCH_1);
  SWITCH_INIT_SWITCH(&KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.CC_DRIVER_INPUTS.CC_DECEL_SWITCH_2);
  SWITCH_INIT_SWITCH(&KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.CC_DRIVER_INPUTS.CC_HEADWAY_DEC_SWITCH);
  SWITCH_INIT_SWITCH(&KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.CC_DRIVER_INPUTS.CC_HEADWAY_INC_SWITCH);
  /* All falling edge conditions for these switches run without condition consideration
    Hence setting condition checking variable to True */
  KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.CC_DRIVER_INPUTS.CC_ACCEL_SWITCH_1.OK_WHILE_SWITCHED_ON = TRUE;
  KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.CC_DRIVER_INPUTS.CC_ACCEL_SWITCH_2.OK_WHILE_SWITCHED_ON = TRUE;
  KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.CC_DRIVER_INPUTS.CC_DECEL_SWITCH_1.OK_WHILE_SWITCHED_ON = TRUE;
  KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.CC_DRIVER_INPUTS.CC_DECEL_SWITCH_2.OK_WHILE_SWITCHED_ON = TRUE;
  KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.CC_DRIVER_INPUTS.CC_RESUME_SWITCH.OK_WHILE_SWITCHED_ON  = TRUE;
  KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.CC_DRIVER_INPUTS.CC_SET_SWITCH.OK_WHILE_SWITCHED_ON     = TRUE;
  KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.CC_DRIVER_INPUTS.CC_HEADWAY_INC_SWITCH.OK_WHILE_SWITCHED_ON = TRUE;
  KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.CC_DRIVER_INPUTS.CC_HEADWAY_DEC_SWITCH.OK_WHILE_SWITCHED_ON = TRUE;
#endif

  KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.CC_DRIVER_INF.ACC_DRIVE_OFF_POSSIBLE = FALSE;
  KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.CC_DRIVER_INF.BIT_ACC_ALERT = FALSE;
  KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.CC_DRIVER_INF.BIT_DM_ALERT = FALSE;
  KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.CC_DRIVER_INF.BIT_FCA_ALERT = FALSE;
  KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.CC_DRIVER_INF.DRIVER_CONFIRMATION_NEEDED = FALSE;
  KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.CC_DRIVER_INF.HEADWAY_SETTING = Kmc_acc_default_headway_setting;
  KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.CC_DRIVER_INF.OBJECT_DETECTED = FALSE;
  KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.CC_DRIVER_INF.OPERATIONAL_MODE = Display_op_none;
  KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.CC_DRIVER_INF.REPORTED_ERROR = Cc_no_error;
  /*! Calclulate slope variable defination*/
  KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.CC_DRIVER_INF.ACC_SLOPE_STATE = FALSE;
  KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.CC_DRIVER_INF.COUNTER_SLOPE = Counter_enter_slope;
  KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.CC_DRIVER_INF.COUNTER_EXIT_SLOPE = Counter_exit_slope;
  /*! End*/
  KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.CC_DRIVER_INF.CC_DRIVER_DOOR_CNT = 0U;
  KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.CC_DRIVER_INF.CC_DRIVER_BELT_CNT = 0U;


  KMC_v_InitDASInputData(&DAS_INPUT_DATA_LAST_CYCLE);
  KMC_v_InitDASInputData(&KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.DAS_INPUT_DATA);
  KMC_v_InitDASOutputData(&KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.DAS_OUTPUT_DATA);

  /*! Initialisation of customer specific variables */
#if (FCT_CFG_ACC_HEADWAY_PLANNER)
  HeadwaySetting = Kmc_acc_default_headway_setting;
#endif
  /* low pass filter value for velocity */
#if (!CFG_FCT_USE_VDY_HOST_ACCEL)
  VehVeloFlt = 0.0F;
#endif

  /*! Variables of KMC_v_DetermineDriverOperations */
#if (CFG_FCT_USE_TWICE_CONFIRMATION_FOR_DRIVE_OFF)
  DriveOffConfirmation_Timer = Cc_default_drive_off_confirmation_time;
  DriveOffConfirmation = FALSE;
#endif
  b_Stand_Still_Request = FALSE;
  ui_Drive_Off_Confirmation_Timer = (times_t)0;
#if (FCT_CFG_SLA_FEATURE)
  u_DeltaDist = (distance_t)0;
  u_SpeedLimitDistLC = 0u; /*!< Last cycle extrapolated speed limit distance */
  uiSLA_MsgDisplayTimer = 0u;
  Min_sla_speed = MIN_SLA_SPEED_KPH;
  Max_sla_speed = MAX_SLA_SPEED_KPH;
  b_NewUnrestictedSign = FALSE;
  SLA_SpeedLimitNow.u_SpeedLimit = 0u;
  SLA_SpeedLimitNow.u_SpeedLimitIncOffset = 0;
  SLA_SpeedLimitNow.u_SpeedLimitDistance = 0u;
  SLA_SpeedLimitNow.SpeedLimitType.b_SLA_CONTROL_AFTER_LIMIT = FALSE;
  SLA_SpeedLimitNow.SpeedLimitType.b_SLA_CONTROL_BEFOR_LIMIT = FALSE;
  uiSLA_ManUsageTimer = 0u;
#if (KMC_CFG_SLA_EXPLICIT_SIGNS_ONLY == SWITCH_OFF)
  b_ImplicitSpeedZone = TRUE; /* Initial assumption is that we start from a zone where no speed limit is applicable */
  b_ImplicitSpeedZoneEntry = FALSE;
  b_SpeedLimitSavedForRetake = FALSE;
#endif
#endif /* Endif (FCT_CFG_SLA_FEATURE) */

#endif /* Endif (FCT_CFG_CC) */

  KMC_v_InhibitInit(&INHIBIT_BUFFER);


  /* Deactivate AutoGo */
  KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.KMC_Auto_Go_Mode = eAutoGoMode_BASE;
#if (KMC_CFG_AUTOGO_FEATURE)
  /* Deactivate AutoStop by default */
  fct_par_long_veh_auto_stop = FCT_PAR_LONG_VEH_AUTO_STOP;
#endif

	//Init variables for VA10
	Kmc_overridetime_counter = Kmc_overridetime_counter_C;
	Kmc_standstill_counter = Kmc_standstill_counter_C;
	Kmc_Standstillstate = StandStillState_None;
	StateAccLowSpd = StateAccLowSpd_UNDEFINED;
	ACC_Cancellation_Flag = FALSE;
	DistObjBeforeLoss = 0.0F;
	objstatus_detect_lastcycle = FALSE;
	ACC_State = ACC_STAT_OFF;
	ACC_State_Last_Cycle = ACC_STAT_OFF;
	b_Button_Resume_AccelSwitch_Inhibit = FALSE;
	b_Button_Set_DecelSwitch_Inhibit = FALSE;
	b_Soft_Off_Condition = FALSE;
	b_flag_igon = TRUE;
#if (CN_ACCSM_BOM)
	b_BOM_Enter_Conditions = FALSE;
	b_BOM_Exists = FALSE;
#endif
	InhibitReason_Inhibit_Engagement = 0U;
}


/*************************************************************************************************************************
  Functionname:    KMC_v_InputWrapper                                                                               */ /*!

  @brief           Input Signals Wrapper for fct_long_veh.c

  @description     Input Signals Wrapper for fct_long_veh.c

	@startuml
	Start
	Partition KMC_v_InputWrapper {
		:Determine b_Soft_Off_Condition according several conditions;
		
		If (Main button switched on) then (yes)
			:SELECTED_FUNCTION = Cc_function_cc;
		Else (no)
			:SELECTED_FUNCTION = Cc_function_none;
		Endif
		
		If (Brake Input Standstill) then (yes)
			If (Driver is braking) then (yes)
				: Stand still timer set to \nCc_standstill_delay_time;
				Note: if driver braking -> delay time is defined to be expired;
			Endif
			: Timer incremented;
			: LODM_STAT.STANDSTILL = TRUE;
		Else (no)
			: Stand still timer reset to 0;
			: LODM_STAT.STANDSTILL = FALSE;
		Endif
	}
	End
	@enduml


  @return          void

  @param[in]       cycle_time : cycle time of FCT_VEH cycle [times_t as per Rte_Type.h]ms
  @param[in]       pVehDyn : Pointer to vehicle dynamic data [VehDyn_t as per Rte_type.h]
                    pVehDyn->Longitudinal.VeloCorr.corrVelo : Corrected ego longitudinal velocity [full range of float] m/s
                    pVehDyn->Lateral.DrvIntCurve.Curve : Curvature of vehicle path                [full range of float] 1/m
                    pVehDyn->Lateral.Accel.LatAccel : Lateral acceleration of vehicle             [full range of float] m/s2
                    pVehDyn->Longitudinal.MotVar.Accel : Longitudinal acceleration of vehicle     [full range of float] m/s2
                    pVehDyn->MotionState.MotState : State of motion of vehicle                    [0, 3]
  @param[in]       pAccLever : Pointer to input from ACC lever [AccLeverInput_t as per Rte_type.h]
                    pAccLever->sSigHeader.eSigStatus : Algo Signal state input [AlgoSignalState_t as per Rte_type.h]
                    pAccLever->AccelSwitch : Accelswitch input from driver [AccelSwitch_t as per Rte_type.h]
                    pAccLever->DecelSwitch : Decelswitch input from driver [DecelSwitch_t as per Rte_type.h]
                    pAccLever->Cancel : Boolean, if TRUE indicates Cancel input from driver [TRUE, FALSE]
                    pAccLever->Resume : Boolean, if TRUE indicates Resume input from driver [TRUE, FALSE]
                    pAccLever->HeadwayInc : Boolean, if TRUE indicates headway decrease input from driver [TRUE, FALSE]
                    pAccLever->HeadwayDec : Boolean, if TRUE indicates headway decrease input from driver [TRUE, FALSE]
                    pAccLever->Headway : CC headway input from driver [Headway as oer Rte_type.h]
  @param[in]       pLongCtrlResp : Pointer to Longitudinal control input structure [LongCtrlInput_t as per Rte_type.h]
                    pLongCtrlResp->DisplayOutput.speedometer_speed : Current speedometer speed with factor 100 [speedometer_speed as per Rte_type.h]
                    pLongCtrlResp->DisplayOutput.speed_unit : Unit of vehicle speed [SpeedUnitEnum_t as per Rte_type.h]
                    pLongCtrlResp->KinCtrlDynInput.park_brk_eng : [TRUE, FALSE]
                    pLongCtrlResp->KinCtrlDynInput.longi_initialization_accel : [longi_initialization_accel as per Rte_type.h]
                    pLongCtrlResp->KinCtrlDynInput.driver_braking : [TRUE, FALSE]
                    pLongCtrlResp->KinCtrlDynInput.acc_enable : [TRUE, FALSE]
                    pLongCtrlResp->KinCtrlDynInput.longi_shutoff_acknowledged : [TRUE, FALSE]
                    pLongCtrlResp->KinCtrlDynInput.DAS_accel_request_limited : [TRUE, FALSE]
                    pLongCtrlResp->KinCtrlDynInput.DAS_decel_request_limited : [TRUE, FALSE]
                    pLongCtrlResp->KinCtrlDynInput.driver_override_accel_pedal : [TRUE, FALSE]
                    pLongCtrlResp->KinCtrlDynInput.driver_override_decel_pedal : [TRUE, FALSE]
                    pLongCtrlResp->KinCtrlDynInput.DC_status_information : External error state from SW [DC_status_information_t as per Rte_type.h]
  @param[in,out]   das_input_data : Pointer to input from longitudinal dynamics management to driver assistance system [cart_das_input_data_t as per cart_ext.h]
                    das_input_data->BRAKE_STAT.BRAKE_FAILED : Boolean, if TRUE indicates failed brake [TRUE, FALSE]
                    das_input_data->BRAKE_STAT.OVER_HEATED : Boolean, if TRUE indicates over heated brake [TRUE, FALSE]
                    das_input_data->BRAKE_STAT.PEDAL_INIT_TRAVEL : Boolean indicating if brake pedal is pressed [TRUE, FALSE]
                    das_input_data->DATA_VALID.INIT_ACCEL :             [TRUE, FALSE]
                    das_input_data->DATA_VALID.VEHICLE_ACCEL :          [TRUE, FALSE]
                    das_input_data->DATA_VALID.VEHICLE_SPEED :          [TRUE, FALSE]
                    das_input_data->LODM_STAT.DC_FAIL :                 [TRUE, FALSE]
                    das_input_data->LODM_STAT.DAS_ENABLE :              [TRUE, FALSE]
                    das_input_data->LODM_STAT.DAS_SHUTOFF_ACQ :         [TRUE, FALSE]
                    das_input_data->LODM_STAT.DC_LIM_ACCEL :            [TRUE, FALSE]
                    das_input_data->LODM_STAT.DC_LIM_DECEL :            [TRUE, FALSE]
                    das_input_data->LODM_STAT.OVERRIDE_ACCEL :          [TRUE, FALSE]
                    das_input_data->LODM_STAT.OVERRIDE_DECEL :          [TRUE, FALSE]
                    das_input_data->LODM_STAT.STANDSTILL : Boolean indicating if vehicle standstill is detected [TRUE, FALSE]
                    das_input_data->PT_STAT.FAIL_IRREVERSABLE :         [TRUE, FALSE]
                    das_input_data->PT_STAT.FAIL_REVERSABLE :           [TRUE, FALSE]
                    das_input_data->PT_STAT.SHIFT_IN_PROGRESS : Boolean, if TRUE indicates gear shifting oin progress [TRUE, FALSE]
                    das_input_data->PT_STAT.KICKDOWN : Boolean, if TRUE indicates kickdown mode                       [TRUE, FALSE]
                    das_input_data->PT_STAT.CLUTCH_OPEN : Boolean, if TRUE indicates open clutch                      [TRUE, FALSE]
                    das_input_data->CHASSIS_STAT.PB_ACT : Boolean, if TRUE indicates Park Brake active                [TRUE, FALSE]
                    das_input_data->A_INIT : Vehicle initialisation acceleration with factor Acceleration_s [acceleration_t as per Rte_type.h] m/s2
                    das_input_data->VEHICLE_ACCEL : Ego longitudinal acceleration with factor Acceleration_s [acceleration_t as per Rte_type.h] m/s2
                    das_input_data->VEHICLE_SPEED : Ego speed with factor Velocity_s [full range of datatype sint16] cm/s

  @param[in,out]   driver_inputs : Pointer to inputs received from driver [cc_driver_inputs_t as per fct_long_veh_customfunctions]
                    driver_inputs->CC_ACCEL_SWITCH_1 : Input of ACCEL_SWITCH_LOW from driver      [switch_t as per switch_ext.h]
                    driver_inputs->CC_ACCEL_SWITCH_2 : Input of ACCEL_SWITCH_HIGH from driver     [switch_t as per switch_ext.h]
                    driver_inputs->CC_DECEL_SWITCH_1 : Input of DECEL_SWITCH_LOW from driver      [switch_t as per switch_ext.h]
                    driver_inputs->CC_DECEL_SWITCH_2 : Input of DECEL_SWITCH_HIGH from driver     [switch_t as per switch_ext.h]
                    driver_inputs->CC_CANCEL_SWITCH : Input of CANCEL switch from driver          [switch_t as per switch_ext.h]
                    driver_inputs->CC_RESUME_SWITCH : Input of RESUME switch from driver          [switch_t as per switch_ext.h]
                    driver_inputs->CC_HEADWAY_INC_SWITCH : Input of HeadwayInc switch from driver [switch_t as per switch_ext.h]
                    driver_inputs->CC_HEADWAY_DEC_SWITCH : Input of HeadwayDec switch from driver [switch_t as per switch_ext.h]
  @param[in,out]   cc_status : Pointer to Cruisecontrol status [cc_status_t as per cc_ext.h]
                    cc_status->CC_DRIVER_REQUESTS.CONTROL_STATE : Variable that reflects the state of the HMI state machine [0, 11]
                    cc_status->CC_DRIVER_REQUESTS.STAND_STILL_TIME : Timer for stand still [times_t as per Rte_Type.h]ms
                    cc_status->CC_CONTROL_DATA.CC_ACCELERATION : Acceleration of cruise control with factor Acceleration_s [acceleration_t as per Rte_Type.h] m/s2
  @param[in,out]   pFctVehLongOut : Pointer to longitudinal control internal buffer for passing information from FCT_VEH to FCT_SEN [FctVeh2SenInfo_t as per Rte_type.h]
                    pFctVehLongOut->HeadwaySetting : Headway setting for Cruise control [percentage_t as per Rte_Type.h]
  @param[in,out]   driver_controls : Pointer to Selected CC function by driver [cc_driver_controls_t as per cc_ext.h]
                    driver_controls->SELECTED_FUNCTION : This variable reflects which function is selected by the driver [cc_selected_function_t as per cc_ext.h]
                    driver_controls->SELECTED_FUNCTION_LAST_CYCLE : This variable reflects which function was selected by the driver in the former cycle [cc_selected_function_t as per cc_ext.h]
  @param[in,out]   cc_input : Pointer to CC input interface [cc_input_data_t as per cc_ext.h]
                    cc_input->DATA_VALIDITY.LATERAL_ACCEL : [TRUE, FALSE]
                    cc_input->DATA_VALIDITY.SPEEDO_SPEED : [TRUE, FALSE]
                    cc_input->VEHICLE_STATUS.SPORTS_MODE : boolean, if TRUE indicating sports mode on [TRUE, FALSE]
                    cc_input->PERMANENT_LIMITER_SETSPEED : Setspeed of CC Limiter [full range of uint8] 
                    cc_input->COUNTRY_CODE : Code indicating region of the world [cc_country_code_t as per cc_ext.h]
                    cc_input->VEHICLE_SPEED_LIMIT : Upper speed limit of vehicle [full range of datatype uint8]
                    cc_input->ACTUAL_GEAR : Currently valid transmission gear of vehicle [TransmissionGear_t as per Rte_type.h]
                    cc_input->DATA_VALIDITY.ACTUAL_GEAR : Boolean, if TRUE indicates succesful conversion of gear type to pt_gear_t [TRUE, FALSE]
                    cc_input->ACCELERATION_GRADIENT : Gradient of longitudinal acceleration [gradient_t as per fct_types.h] m/s3
                    cc_input->SPEEDOMETER_VEHICLE_SPEED : Current speedometer speed with factor Velocity_s [full range of datatype sint16]
                    cc_input->VEHICLE_STATUS.SPEED_UNIT_KMH : boolean indicating the speed unit, i.e. KMH or MPH [TRUE, FALSE]
                    cc_input->LATERAL_ACCELERATION : Lateral acceleration of vehicle with factor Acceleration_s [acceleration_t as per Rte_type.h] m/s2
  @param[in,out]   error_data : Pointer to error data from CC [cc_error_data_t as per cc_ext.h]
                    error_data->REPORTED_ERROR : Error reported by CC [cc_error_data_t as per cc_ext.h]
  @glob_in         None
  @glob_out        None

  @c_switch_part   CFG_ACC_LEVER_INPUT : Configuration switch for enabling lever input
  @c_switch_part   FCT_CFG_ACC_HEADWAY_PLANNER : Configuration switch for enabling ACC processing
  @c_switch_part   CFG_FCT_USE_PRED_VELO_FOR_ALAT : Configuration switch for using predicted velocity for calculation of lateral acceleration
  @c_switch_part   CFG_FCT_USE_VDY_HOST_ACCEL : Configuration switch for using VDY host acceleration

  @c_switch_full   FCT_CFG_CC : Configuration switch for enabling CC processing

  @pre             
  @post            

  @created         
  @changed         

  @todo            Review this function

  @author         Simon Sinnstein
*************************************************************************************************************************/
static void KMC_v_InputWrapper(const times_t cycle_time,
                               const VehDyn_t* pVehDyn,
#if (CFG_ACC_LEVER_INPUT)
                               const AccLeverInput_t* pAccLever,
#endif
                               const LongCtrlInput_t* pLongCtrlResp,
                               const PowerTrain_t * pPowerTrain,
                               cart_das_input_data_t* das_input_data,
#if (CFG_ACC_LEVER_INPUT)
                               cc_driver_inputs_t* driver_inputs,
#endif
                               cc_status_t* cc_status,
                               FctVeh2SenInfo_t* pFctVehLongOut,
                               cc_driver_controls_t* driver_controls,
                               cc_input_data_t* cc_input,
							   cc_error_data_t* error_data
                              )
{
  float32 VehVeloRaw;
#if (!CFG_FCT_USE_VDY_HOST_ACCEL)
  float32 VehVeloFltNew;
#endif
#if (CFG_FCT_USE_PRED_VELO_FOR_ALAT)
  float32 VehVeloPred;
#endif
  float32 LongAcc, LatAcc;
  sint32 Help = (sint32)0;
      
  switch(pLongCtrlResp->Custom.CustomInput.GearPosition)
  {
	case GEAR_POSITION_PARK:
		cc_input->ACTUAL_GEAR = Pt_gear_park;
		break;
	case GEAR_POSITION_NEUTRAL:
		cc_input->ACTUAL_GEAR = Pt_gear_neutral;
		break;
	case GEAR_POSITION_REVERSE:
		cc_input->ACTUAL_GEAR = Pt_gear_reverse;
		break;
	default:
		cc_input->ACTUAL_GEAR = Pt_gear_first;
		break;
  }
  
  /*wrapper for CC_DRIVER_CONTROLS*/
#if (CFG_ACC_LEVER_INPUT)
  if ((pAccLever != NULL) && (pAccLever->sSigHeader.eSigStatus == AL_SIG_STATE_OK))
  {
    /* To avoid MISRA violation, calculate the headway setting condition once here */
    const boolean headway_set_cond = (boolean)((ACC_State == ACC_STAT_PASSIVE)       || 
                                               (ACC_State == ACC_STAT_STANDBY)       ||
									           (ACC_State == ACC_STAT_ACTIVECONTROL) ||
									           (ACC_State == ACC_STAT_BRAKEONLYMODE) ||
									           (ACC_State == ACC_STAT_OVERRIDE)      ||
									           (ACC_State == ACC_STAT_STANDSTILL));									  

	// Map Res/v+ button to Resume and AccelSwitch
	if (b_Button_Resume_AccelSwitch_Inhibit == FALSE)
	{
		if	(
				(pLongCtrlResp->Custom.CustomInput.Button_Resume_AccelSwitch == TRUE)
				&&
				(ACC_State != ACC_State_Last_Cycle)
			)
		{
			b_Button_Resume_AccelSwitch_Inhibit = TRUE;
		}
	}
	else // b_Button_Resume_AccelSwitch_Inhibit == TRUE
	{
		if (pLongCtrlResp->Custom.CustomInput.Button_Resume_AccelSwitch == FALSE)
		{
			b_Button_Resume_AccelSwitch_Inhibit = FALSE;
		}
	}
		
	if	(
			(pLongCtrlResp->Custom.CustomInput.Button_Resume_AccelSwitch == TRUE)
			&&
			(b_Button_Resume_AccelSwitch_Inhibit == FALSE)
		)
	{
		switch (ACC_State)
		{
		    case ACC_STAT_PASSIVE:
			case ACC_STAT_STANDBY:
				SWITCH_SET_STATE(&(driver_inputs->CC_RESUME_SWITCH), TRUE);
				SWITCH_SET_STATE(&(driver_inputs->CC_ACCEL_SWITCH_1), FALSE);
				break;

			case ACC_STAT_ACTIVECONTROL:
			case ACC_STAT_BRAKEONLYMODE:
			case ACC_STAT_OVERRIDE:
				SWITCH_SET_STATE(&(driver_inputs->CC_RESUME_SWITCH), FALSE);
				SWITCH_SET_STATE(&(driver_inputs->CC_ACCEL_SWITCH_1), TRUE);
				break;

			case ACC_STAT_STANDSTILL:
				if (pLongCtrlResp->KinCtrlDynInput.driver_braking == TRUE)
				{
					SWITCH_SET_STATE(&(driver_inputs->CC_RESUME_SWITCH), FALSE);
					SWITCH_SET_STATE(&(driver_inputs->CC_ACCEL_SWITCH_1), TRUE);
				}
				else
				{
					SWITCH_SET_STATE(&(driver_inputs->CC_RESUME_SWITCH), TRUE);
					SWITCH_SET_STATE(&(driver_inputs->CC_ACCEL_SWITCH_1), FALSE);
				}
				break;

			default:
				SWITCH_SET_STATE(&(driver_inputs->CC_RESUME_SWITCH), FALSE);
				SWITCH_SET_STATE(&(driver_inputs->CC_ACCEL_SWITCH_1), FALSE);
				break;
		}
	}
	else
	{
		SWITCH_SET_STATE(&(driver_inputs->CC_RESUME_SWITCH), FALSE);
		SWITCH_SET_STATE(&(driver_inputs->CC_ACCEL_SWITCH_1), FALSE);
	}

	// Map Set/v- button to Set and DecelSwitch
	if (b_Button_Set_DecelSwitch_Inhibit == FALSE)
	{
		if	(
				(pLongCtrlResp->Custom.CustomInput.Button_Set_DecelSwitch == TRUE)
				&&
				(ACC_State != ACC_State_Last_Cycle)
			)
		{
			b_Button_Set_DecelSwitch_Inhibit = TRUE;
		}
	}
	else // b_Button_Set_DecelSwitch_Inhibit == TRUE
	{
		if (pLongCtrlResp->Custom.CustomInput.Button_Set_DecelSwitch == FALSE)
		{
			b_Button_Set_DecelSwitch_Inhibit = FALSE;
		}
	}
	
	if	(
			(pLongCtrlResp->Custom.CustomInput.Button_Set_DecelSwitch == TRUE)
			&&
			(b_Button_Set_DecelSwitch_Inhibit == FALSE)
		)
	{
		switch (ACC_State)
		{
			case ACC_STAT_PASSIVE:
			case ACC_STAT_STANDBY:
			case ACC_STAT_OVERRIDE:
				SWITCH_SET_STATE(&(driver_inputs->CC_SET_SWITCH), TRUE);
				SWITCH_SET_STATE(&(driver_inputs->CC_DECEL_SWITCH_1), FALSE);
				break;
				
			case ACC_STAT_ACTIVECONTROL:
			case ACC_STAT_BRAKEONLYMODE:
				SWITCH_SET_STATE(&(driver_inputs->CC_SET_SWITCH), FALSE);
				SWITCH_SET_STATE(&(driver_inputs->CC_DECEL_SWITCH_1), TRUE);
				break;
				
			case ACC_STAT_STANDSTILL:
				if (pLongCtrlResp->KinCtrlDynInput.driver_braking == TRUE)
				{
					SWITCH_SET_STATE(&(driver_inputs->CC_SET_SWITCH), FALSE);
					SWITCH_SET_STATE(&(driver_inputs->CC_DECEL_SWITCH_1), TRUE);
				}
				else
				{
					SWITCH_SET_STATE(&(driver_inputs->CC_SET_SWITCH), TRUE);
					SWITCH_SET_STATE(&(driver_inputs->CC_DECEL_SWITCH_1), FALSE);
				}
				break;
				
			default:
				SWITCH_SET_STATE(&(driver_inputs->CC_SET_SWITCH), FALSE);
				SWITCH_SET_STATE(&(driver_inputs->CC_DECEL_SWITCH_1), FALSE);
				break;
		}
	}
	else
	{
		SWITCH_SET_STATE(&(driver_inputs->CC_SET_SWITCH), FALSE);
		SWITCH_SET_STATE(&(driver_inputs->CC_DECEL_SWITCH_1), FALSE);
	}

//	SWITCH_SET_STATE(&(driver_inputs->CC_ACCEL_SWITCH_1), (boolean)(pAccLever->AccelSwitch == ACC_LEVER_ACCEL_LOW)) ;
//	SWITCH_SET_STATE(&(driver_inputs->CC_ACCEL_SWITCH_2), FALSE);
//	SWITCH_SET_STATE(&(driver_inputs->CC_DECEL_SWITCH_1), (boolean)(pAccLever->DecelSwitch == ACC_LEVER_DECEL_LOW));
//	SWITCH_SET_STATE(&(driver_inputs->CC_DECEL_SWITCH_2), FALSE);

//	SWITCH_SET_STATE(&(driver_inputs->CC_SET_SWITCH),     pAccLever->Set);
	SWITCH_SET_STATE(&(driver_inputs->CC_CANCEL_SWITCH),  (pAccLever->Cancel)&&(pLongCtrlResp->Custom.CustomInput.CDDActive == FALSE));
	SWITCH_SET_STATE(&(driver_inputs->CC_CANCEL_SWITCH_WITHOUT_BOM),  pAccLever->Cancel);
//	SWITCH_SET_STATE(&(driver_inputs->CC_RESUME_SWITCH),  pAccLever->Resume);

	SWITCH_SET_STATE(&(driver_inputs->CC_HEADWAY_INC_SWITCH), pAccLever->HeadwayInc);
	SWITCH_SET_STATE(&(driver_inputs->CC_HEADWAY_DEC_SWITCH), pAccLever->HeadwayDec);
	SWITCH_SET_STATE(&(driver_inputs->CC_Main_SWITCH), pAccLever->MainMode);

#if (FCT_CFG_ACC_HEADWAY_PLANNER)

    /* If ACC-lever input provides a headway setting by itself (i.e.: some logic provides it to us as
    external input), then take over it's setting */
//	HeadwaySetting = MAX(pAccLever->Headway, (percentage_t)100);
//	HeadwaySetting = MIN(HeadwaySetting, (percentage_t)230);

    // HMI - Headway decrease Button : L4 -> L3 -> L2 -> L1
    if ((SWITCH_FALLING_EDGE(&driver_inputs->CC_HEADWAY_DEC_SWITCH, headway_set_cond) == SWITCH_STATE_ON)
        &&
        (driver_inputs->CC_HEADWAY_DEC_SWITCH.DURATION_TIME_ACTIVE <= Headway_Handbag_Time)
        &&
        (driver_inputs->CC_HEADWAY_DEC_SWITCH.DURATION_TIME_ACTIVE >= Switch_Debounce_Time))
    {
      if (HeadwaySetting <= Headway_Setting_level_2)
      {
        HeadwaySetting = Headway_Setting_level_1;
      }
      else if (HeadwaySetting <= Headway_Setting_level_3)
      {
        HeadwaySetting = Headway_Setting_level_2;
      }
      else
      {
        HeadwaySetting = Headway_Setting_level_3;
      }
    }

    // HMI - Headway increase Button : L1 -> L2 -> L3 -> L4
    if ((SWITCH_FALLING_EDGE(&driver_inputs->CC_HEADWAY_INC_SWITCH, headway_set_cond) == SWITCH_STATE_ON)
        &&
        (driver_inputs->CC_HEADWAY_INC_SWITCH.DURATION_TIME_ACTIVE <= Headway_Handbag_Time)
        &&
        (driver_inputs->CC_HEADWAY_INC_SWITCH.DURATION_TIME_ACTIVE >= Switch_Debounce_Time))
    {
      if (HeadwaySetting <= Headway_Setting_level_1)
      {
        HeadwaySetting = Headway_Setting_level_2;
      }
      else if (HeadwaySetting <= Headway_Setting_level_2)
      {
        HeadwaySetting = Headway_Setting_level_3;
      }
      else
      {
        HeadwaySetting = Headway_Setting_level_4;
      }
    }

    /* Fill in output structure to FCT_SEN part */
    pFctVehLongOut->HeadwaySetting = HeadwaySetting;
#endif    /* FCT_CFG_ACC_HEADWAY_PLANNER */

	if (pAccLever->MainMode == TRUE)
	{
		driver_controls->SELECTED_FUNCTION = Cc_function_cc;
	}
	else
	{
		driver_controls->SELECTED_FUNCTION = Cc_function_none;
	}

  }
  else
  {
    /* ACC lever pointer null or signal status invalid : do not evaluate it's switches */
  }

  /*! Accelerator pedal state */
  driver_inputs->CC_ACCEL_PEDAL = pLongCtrlResp->KinCtrlDynInput.driver_accel;
#else /* CFG_ACC_LEVER_INPUT */

  /*Determine current headway setting (given by engine ecu)*/
  switch (pLongCtrlResp->Custom.EngineEcuInput.LTME2)
  {
  case LTME2_VEH_FOLLOW_TIME_LONG:
    {
      HeadwaySetting= Headway_Setting_long;
      break;
    }
  case LTME2_VEH_FOLLOW_TIME_MIDDLE:
    {
      HeadwaySetting= Headway_Setting_mid;
      break;
    }
  case LTME2_VEH_FOLLOW_TIME_SHORT:
    {
      HeadwaySetting= Headway_Setting_short;
      break;
    }
  case LTME2_VEH_FOLLOW_TIME_UNDEFINED: /* Undefined value not specified */
    {
      HeadwaySetting= Kmc_acc_default_headway_setting; /* Default value is 100 percent (equals time gap of 2sec) */
      break;
    }
  }
  /* Fill in output structure to FCT_SEN part */
  pFctVehLongOut->HeadwaySetting = HeadwaySetting;
 
  driver_controls->SELECTED_FUNCTION            = Cc_function_cc; 
  driver_controls->SELECTED_FUNCTION_LAST_CYCLE = Cc_function_cc; 

#endif /* CFG_ACC_LEVER_INPUT */

  /*CC_ERROR*/
  /* Fill gCC_ERROR_DATA.REPORTED_ERROR based on pLongCtrlResp->KinCtrlDynInput.DC_status_information */
  KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.CC_ERROR_DATA.REPORTED_ERROR = Cc_no_error; /* Initialization of error every cycle */

  /*wrapper for CC_INPUT_DATA*/
  cc_input->DATA_VALIDITY.LATERAL_ACCEL  = TRUE;
  cc_input->DATA_VALIDITY.SPEEDO_SPEED   = TRUE;
  cc_input->VEHICLE_STATUS.SPORTS_MODE   = FALSE;

  /*! Permanent speed limiter, Winter Tire speed limiter */
  if(pLongCtrlResp->KinCtrlDynInput.perm_lim_setspeed > 0u)
  {
    cc_input->PERMANENT_LIMITER_SETSPEED = pLongCtrlResp->KinCtrlDynInput.perm_lim_setspeed;
  }
  else
  {
    cc_input->PERMANENT_LIMITER_SETSPEED   = 255u;
  }

  /*! COUNTRY_CODE */
  cc_input->COUNTRY_CODE                 = Cc_rest_of_world;
  /*! VEHICLE_SPEED_LIMIT */
  cc_input->VEHICLE_SPEED_LIMIT          = 255u;
  /* cc_input->DATA_VALIDITY.ACTUAL_GEAR    = KMC_b_ConvertGearInfo(pPowerTrain->ActualGear, &cc_input->ACTUAL_GEAR); */

#if (FCT_LONG_CTRL_INPUT_INTFVER < 10u)
  cc_input->SPEEDOMETER_VEHICLE_SPEED      = ((speedometer_speed_t)pLongCtrlResp->DisplayOutput.speedometer_speed * Speedo_speed_s);
#else
  /*! Input pLongCtrlResp->DisplayOutput.speedometer_speed Factor 100 uint16 Velocity!*/
  cc_input->SPEEDOMETER_VEHICLE_SPEED      = ((speedometer_speed_t)pLongCtrlResp->DisplayOutput.speedometer_speed); /* factor 100 */
#endif
  /*! DISPLAY SPEED and UNIT */
  if (pLongCtrlResp->DisplayOutput.speed_unit == SPD_UNIT_KMH)
  {
    cc_input->VEHICLE_STATUS.SPEED_UNIT_KMH  = TRUE;
    /* the speedometer speed will be sent by DAI allways in kmh
    cc_input->SPEEDOMETER_VEHICLE_SPEED = cc_input->SPEEDOMETER_VEHICLE_SPEED; */
  }
  else
  {
    cc_input->VEHICLE_STATUS.SPEED_UNIT_KMH = FALSE;
    /* calculation from kph to mph */
    Help = (sint32)cc_input->SPEEDOMETER_VEHICLE_SPEED;
    Help*= (sint32)Speed_conv_factor_mph;
    Help+= (sint32)Speed_conv_factor_kmh / (sint32)2;
    Help/= (sint32)Speed_conv_factor_kmh;
    cc_input->SPEEDOMETER_VEHICLE_SPEED = (speedometer_speed_t)MAT_LIM(Help, Speedo_speed_min, Speedo_speed_max);
  }
  
#if (LONG_CFG_USE_EXTERN_ACC_STATE_MACHINE)
  cc_input->pENGINE_ECU_INPUT = &pLongCtrlResp->Custom.EngineEcuInput;
#endif

  /*wrapper for DAS_INPUT_DATA*/
  das_input_data->BRAKE_STAT.BRAKE_FAILED      = FALSE;
  das_input_data->BRAKE_STAT.OVER_HEATED       = FALSE;
  das_input_data->BRAKE_STAT.PEDAL_INIT_TRAVEL = (boolean)((pLongCtrlResp->KinCtrlDynInput.driver_braking) || (pLongCtrlResp->Custom.CustomInput.AVHActive));  //avh active or driver brake
  das_input_data->DATA_VALID.INIT_ACCEL        = TRUE;
  das_input_data->DATA_VALID.VEHICLE_ACCEL     = TRUE;
  das_input_data->DATA_VALID.VEHICLE_SPEED     = TRUE;
  das_input_data->PT_STAT.FAIL_IRREVERSABLE    = FALSE; /*!!! where to find?*/
  das_input_data->PT_STAT.FAIL_REVERSABLE      = FALSE; /*!!! where to find?*/
  das_input_data->PT_STAT.SHIFT_IN_PROGRESS    = FALSE; /*!!! where to find?*/
  das_input_data->PT_STAT.KICKDOWN             = FALSE;
  das_input_data->PT_STAT.CLUTCH_OPEN          = FALSE;

  if (pVehDyn != NULL)
  {
#if (VDY_VEH_DYN_INTFVER >= 0x20)   // 0x20 -> 18
    VehVeloRaw     = pVehDyn->Longitudinal.Velocity;
    LongAcc = pVehDyn->Longitudinal.Accel;
#else
    VehVeloRaw  = pVehDyn->Longitudinal.MotVar.Velocity;
    LongAcc     = pVehDyn->Longitudinal.MotVar.Accel;
#endif

#if (CFG_FCT_USE_PRED_VELO_FOR_ALAT)
    /*! Determine vehicle velocity to calc lateralacceleration */
    /*! if velocity < 15 m/s */
    if (VehVeloRaw < 15.0f)
    {
      /*! empiric logic: calculate predicted velocity if vehicle velocity < 15 m/s */
      VehVeloPred = VehVeloRaw + (((float32)cc_status->CC_CONTROL_DATA.CC_ACCELERATION / (float32)Acceleration_s) * (1.5f - (VehVeloRaw / 10.0f)));
    }
    else
    {
      VehVeloPred = VehVeloRaw;
    }

    LatAcc = (pVehDyn->Lateral.DrvIntCurve.Curve * VehVeloPred * VehVeloPred);
#else
    LatAcc = pVehDyn->Lateral.Accel.LatAccel;
#endif
  } /* pVehDyn */
  else
  {
    VehVeloRaw = 0.f;
    LatAcc      = 0.f;
    LongAcc     = 0.f;
  } /* pVehDyn */

  /*! transform longitudinal velocity to fixpoint representation */
  das_input_data->VEHICLE_SPEED = (velocity_t)MAT_LIM(ROUND_TO_INT(VehVeloRaw * (float32)Velocity_s), Velocity_min, Velocity_max);
#if (CFG_FCT_USE_VDY_HOST_ACCEL)
  das_input_data->A_INIT = (acceleration_t)MAT_LIM(ROUND_TO_INT(LongAcc * (float32)Acceleration_s), Accel_min, Accel_max);
#else
  /*! compute longitudinal acceleration by filtering of VDY velocity signal */
  VehVeloFltNew = CML_f_LowPassFilter (VehVeloRaw, VehVeloFlt, 200.0F/cycle_time);
  LongAcc = (VehVeloFltNew - VehVeloFlt) * ((float32)Time_s / (float32)cycle_time);
  VehVeloFlt = VehVeloFltNew;
  /*! transform longitudinal acceleration to fixpoint representation and eval gradient */
  das_input_data->A_INIT = (acceleration_t)MAT_LIM(ROUND_TO_INT(LongAcc * (float32)Acceleration_s), Accel_min, Accel_max);
  //das_input_data->A_INIT                       = pLongCtrlResp->KinCtrlDynInput.longi_initialization_accel;
#endif
  /*! ACCELERATION_GRADIENT checked to switch from control state Engage to Active */
  //cc_input->ACCELERATION_GRADIENT        = ((gradient_t)cc_input->ACCELERATION_GRADIENT - (gradient_t)pLongCtrlResp->KinCtrlDynInput.longi_initialization_accel)/cycle_time;
  cc_input->ACCELERATION_GRADIENT = (gradient_t)(das_input_data->A_INIT - das_input_data->VEHICLE_ACCEL) * (Time_s / cycle_time);
  das_input_data->VEHICLE_ACCEL = (acceleration_t)MAT_LIM((sint32)das_input_data->A_INIT, Accel_min, Accel_max);
  //das_input_data->VEHICLE_ACCEL = (acceleration_t)MAT_LIM(ROUND_TO_INT(LongAcc * (float32)Acceleration_s), Accel_min, Accel_max);
  cc_input->LATERAL_ACCELERATION = (acceleration_t)MAT_LIM(ROUND_TO_INT(LatAcc * (float32)Acceleration_s), Accel_min, Accel_max);

  /*! Evaluation of vehicle hold state */
  if (pLongCtrlResp->KinCtrlDynInput.stand_still_detected)
  {
    /*! if driver braking -> delay time is defined to be expired */
    if (pLongCtrlResp->KinCtrlDynInput.driver_braking)
    {
      cc_status->CC_DRIVER_REQUESTS.STAND_STILL_TIME = Cc_standstill_delay_time;
    }
    /*! increment delay time by cycle time up to uint_max */
    if (cc_status->CC_DRIVER_REQUESTS.STAND_STILL_TIME + cycle_time <= CML_u_UNSIGNED_16BIT_QUANT_SIZE)
    {
      cc_status->CC_DRIVER_REQUESTS.STAND_STILL_TIME += cycle_time;
    }
    /*! vehicle is defined to be in hold state */
    das_input_data->LODM_STAT.STANDSTILL = TRUE;   
  }
  else
  {
    /*! reset delay time */
    cc_status->CC_DRIVER_REQUESTS.STAND_STILL_TIME = 0u;
    /*! vehicle is defined not to be in hold state */
    das_input_data->LODM_STAT.STANDSTILL = FALSE;
    
    if(ui_Drive_Off_Confirmation_Timer > (times_t)0)
    { /* Reset timer if no longer in standstill */
      ui_Drive_Off_Confirmation_Timer = (times_t)0;
    }
  }

  das_input_data->CHASSIS_STAT.ABS_ACT         = (boolean)((pLongCtrlResp->KinCtrlDynInput.ldm_ctrl_state & LDM_CTRL_ABS_ACTIVE) == LDM_CTRL_ABS_ACTIVE);
  das_input_data->CHASSIS_STAT.ESP_ACT         = (boolean)((pLongCtrlResp->KinCtrlDynInput.ldm_ctrl_state & LDM_CTRL_ESP_ACTIVE) == LDM_CTRL_ESP_ACTIVE);
  das_input_data->CHASSIS_STAT.PB_ACT          = pLongCtrlResp->KinCtrlDynInput.park_brk_eng;
  das_input_data->CHASSIS_STAT.TCS_ACT         = (boolean)((pLongCtrlResp->KinCtrlDynInput.ldm_ctrl_state & LDM_CTRL_TCS_ACTIVE) == LDM_CTRL_TCS_ACTIVE);
  das_input_data->CHASSIS_STAT.TCS_ESP_OFF     = (boolean)pLongCtrlResp->Custom.CustomInput.ESPOFFStatus;//FALSE; //(cart_input.LDMState.BIT.TCSOff || cart_input.LDMState.BIT.ESPOff); 

  das_input_data->LODM_STAT.DC_FAIL             = FALSE; /*!!! not defined at the moment*/
  das_input_data->LODM_STAT.DAS_ENABLE          = pLongCtrlResp->KinCtrlDynInput.acc_enable;
  das_input_data->LODM_STAT.DAS_SHUTOFF_ACQ     = TRUE;  //  pLongCtrlResp->KinCtrlDynInput.longi_shutoff_acknowledged;
  das_input_data->LODM_STAT.BRAKE_LIGHT_REQ     = FALSE;
  das_input_data->LODM_STAT.DC_LIM_ACCEL        = (pLongCtrlResp->KinCtrlDynInput.DAS_accel_request_limited);
  das_input_data->LODM_STAT.DC_LIM_DECEL        = (pLongCtrlResp->KinCtrlDynInput.DAS_decel_request_limited);
  das_input_data->LODM_STAT.OVERRIDE_ACCEL      = (pLongCtrlResp->KinCtrlDynInput.driver_override_accel_pedal);
  das_input_data->LODM_STAT.OVERRIDE_DECEL      = (pLongCtrlResp->KinCtrlDynInput.driver_override_decel_pedal);
  
  _PARAM_UNUSED(pPowerTrain);
  _PARAM_UNUSED(error_data);
  
}/* PRQA S 7004, 7012 */
/* date: 2019-06-03, reviewer: zhihua zhuang, reason : Cyclomatic complexity. Not Safety critical*/


/*************************************************************************************************************************
  Functionname:    KMC_v_DetermineDriverOperations                                                                  */ /*!
  
  @brief           Interpret driver input and categorize them in DRIVER_OPERATIONS

  @description     

  @startuml
  
    start
    Partition KMC_v_DetermineDriverOperations(){

    : All variables of output (driver_operations) set to 0;
    If (CC is enabled ) Then (true)
      
      If (ACC is engaged or Active or Override) Then (true)
        : SELECTED_FUNCTION_ACTIVE = 1;
        : Driver intervene must be set to active\n in case brake pedal was pressed;
      Endif

      Note left
      CC_DECREASE_SET_SPEED : Reduce setspeed by a step
      CC_INCREASE_SET_SPEED : Increase setspeed by a step
      TIMED_INCREMENT       : Increase setspeed continuously
      TIMED_DECREMENT       : Reduce setspeed continuously
      CANCEL_FUNKTION       : Disengage ACC due to cancel button usage
      DISENGAGE_DRIVER_INTERVENED: Command to disengage ACC due to driver action
      SELECTED_FUNCTION_ACTIVE: ACC/CC is selected by driver to be available
      SPEED_LIMIT_ACCEPTED  : SLA speed limit take over command by driver
      SPEED_LIMIT_DECLINED  : SLA speed limit rejection command by driver
      CC_TAKE_ACTUAL_SPEED  : Command to set current vehicle speed as setspeed. Also used for ACC activation (Applicable for inactive or override states)
      CC_RESUME_SET_SPEED   : Command to activate ACC with previously saved setspeed (Applicable for inactive state)
      ACTUAL_SPEED_TAKEN_OVERRIDE: Current speed taken as setspeed in override state
      OVERRIDE_WHILE_ENGAGEMENT : Override happens just after ACC activation. Lever buttons to not be used for taking current speed
      Endnote

      If (CC_Inhibit is false) Then (true)
        If (Cancel switch is pressed OR \nFunction changed CC<->Limiter) Then (True)
          : CANCEL_FUNKTION = TRUE;
          : DISENGAGE_DRIVER_INTERVENED = TRUE;
          : CANCEL_RAMP = TRUE;
        Endif

        If (ACC state is engaged/active) then (True)

          If (Decel switch active) then (True)
            If (Decel Button held) then (True)
              : CC_DECREASE_SET_SPEED = 1;
              : TIMED_DECREMENT = 1;
            Endif
            If (Decel Button falling edge) then (True)
              : CC_DECREASE_SET_SPEED = 1;
            Endif

          Elseif (Accel switch active) then (True)
            If (Accel Button held) then (True)
              : CC_INCREASE_SET_SPEED = 1;
              : TIMED_DECREMENT = 1;
            Endif
            If (Accel Button falling edge) then (True)
              : CC_INCREASE_SET_SPEED = 1;
            Endif

          Elseif (Resume button active) then (True)
            If (Ego vehicle standstill) then (True)
              If (Resume button rising edge) then (True)
                : DRIVE_OFF_CONFIRM = 1;
                : Drive off timer set to 0;
              Else (False)
                : Drive off timer incremented upto 3s;
              Endif
            Else (False)
              If (SLA manual mode and new speed available) then (TRUE)
                If (Resume button rising edge\n) then (TRUE)
                  : SPEED_LIMIT_ACCEPTED = 1;
                Endif
                If (Resume button falling edge\nAND\nSLA speed used as setspeed) then (TRUE)
                : Reset SLA button usage;
                : Reset SLA manual usage timer;
                Endif
              Else (False - Resume button for CC)
                If (Resume button held) then (TRUE)
                  : CC_INCREASE_SET_SPEED = 1;
                  : TIMED_INCREMENT = 1;
                Endif
                If (Resume button rising edge) then (TRUE)
                  : CC_INCREASE_SET_SPEED = 1;
                Endif
              Endif
            Endif

          Elseif (Set button active) then (True)
            If (b_SLA_USAGE_AVAILABLE is TRUE) then (TRUE)
              If (Set Button Falling edge) then (TRUE)
                : Reset SLA button usage;
                : Reset SLA manual usage timer;
                : SPEED_LIMIT_DECLINED = 1;
              Endif
            Else (False)
              If (Set button falling edge) then (TRUE)
                : CC_TAKE_ACTUAL_SPEED = 1;
              Endif
            Endif
          Endif 
        
        Else (False)
        Endif
        If (ACC state Override) then (True)

          If (Decel switch active) then (True)
            If (Decel Button falling edge) then (True)
              If (ACTUAL_SPEED_TAKEN_OVERRIDE is 0\nAND OVERRIDE_WHILE_ENGAGEMENT is0\n AND Vehicle speed more than Setspeed) then (TRUE)
                : CC_TAKE_ACTUAL_SPEED = 1;
                : ACTUAL_SPEED_TAKEN_OVERRIDE = 1;
              Else (FALSE)
                : CC_DECREASE_SET_SPEED = 1;
              Endif
            Endif

          Elseif (Accel switch active) then (True)
            If (Accel Button held) then (True)
              If (ACTUAL_SPEED_TAKEN_OVERRIDE is 0\nAND OVERRIDE_WHILE_ENGAGEMENT is0\n AND Vehicle speed more than Setspeed) then (TRUE)
                : CC_TAKE_ACTUAL_SPEED = 1;
                : ACTUAL_SPEED_TAKEN_OVERRIDE = 1;
              Else (FALSE)
                : CC_INCREASE_SET_SPEED = 1;
                : TIMED_INCREMENT = 1;
              Endif
            Endif            
            If (Accel Button falling edge) then (True)
              If (ACTUAL_SPEED_TAKEN_OVERRIDE is 0\nAND OVERRIDE_WHILE_ENGAGEMENT is0\n AND Vehicle speed more than Setspeed) then (TRUE)
                : CC_TAKE_ACTUAL_SPEED = 1;
                : ACTUAL_SPEED_TAKEN_OVERRIDE = 1;
              Else (FALSE)
                : CC_INCREASE_SET_SPEED = 1;
              Endif
            Endif

          Elseif (Resume button active) then (True)

            If (Resume button held AND not standstill) then (TRUE)
              If (ACTUAL_SPEED_TAKEN_OVERRIDE is 0\nAND OVERRIDE_WHILE_ENGAGEMENT is0\n AND Vehicle speed more than Setspeed) then (TRUE)
                : CC_TAKE_ACTUAL_SPEED = 1;
                : ACTUAL_SPEED_TAKEN_OVERRIDE = 1;
              Else (FALSE)
                : CC_INCREASE_SET_SPEED = 1;
                : TIMED_INCREMENT = 1;
              Endif
            Endif
            If (Resume Button rising edge) then (True)
              If (ACTUAL_SPEED_TAKEN_OVERRIDE is 0\nAND OVERRIDE_WHILE_ENGAGEMENT is0\n AND Vehicle speed more than Setspeed) then (TRUE)
                : CC_TAKE_ACTUAL_SPEED = 1;
                : ACTUAL_SPEED_TAKEN_OVERRIDE = 1;
              Else (FALSE)
                : CC_INCREASE_SET_SPEED = 1;
              Endif
            Endif

          Elseif (Set button active) then (True)
            If (Set Button falling edge) then (True)
              If (ACTUAL_SPEED_TAKEN_OVERRIDE is 0\nAND OVERRIDE_WHILE_ENGAGEMENT is0\n AND Vehicle speed more than Setspeed) then (TRUE)
                : CC_TAKE_ACTUAL_SPEED = 1;
                : ACTUAL_SPEED_TAKEN_OVERRIDE = 1;
              Else (FALSE)
                : CC_DECREASE_SET_SPEED = 1;
              Endif
            Endif
          Endif
        
        Else (False)
        Endif
        If (ACC is disengaged)

          If (Resume button Rising Edge) then (True)
            : CC_RESUME_SET_SPEED = 1;
            : OVERRIDE_WHILE_ENGAGEMENT = 1;
          Elseif (Decel button Rising Edge) then (True)
            : CC_TAKE_ACTUAL_SPEED = 1;
            : ACTUAL_SPEED_TAKEN_SET = 1;
            : OVERRIDE_WHILE_ENGAGEMENT = 1;
          Elseif (Set button Rising Edge) then (True)
            : CC_TAKE_ACTUAL_SPEED = 1;
            : ACTUAL_SPEED_TAKEN_SET = 1;
            : OVERRIDE_WHILE_ENGAGEMENT = 1;
          Elseif (Accel button Rising Edge) then (True)
            : CC_TAKE_ACTUAL_SPEED = 1;
            : ACTUAL_SPEED_TAKEN_SET = 1;
            : OVERRIDE_WHILE_ENGAGEMENT = 1;
          Endif
        
        Else (False)
        Endif

      Endif
    Endif

    If (Accel pedal pressed AND\nVehicle in standstill AND\nTarget drive off started) then (TRUE)
      : DRIVE_OFF_CONFIRM = 1;
    Else (FALSE)
    Endif
    : Reset Setspeed if Function CC/Limiter changed;
    If (ACC State Override) then (TRUE)
      : Reset CC_ENGAGE_OVERRIDE_COUNTER to 0.16s;
    Else (FALSE)
      If (CC_TAKE_ACTUAL_SPEED is 0 AND\nCC_RESUME_SET_SPEED is 0 AND\nACC State not engaged) then (TRUE)
        : Decrement CC_ENGAGE_OVERRIDE_COUNTER \nOR set OVERRIDE_WHILE_ENGAGEMENT to 0;
      Else (FALSE)
        : Reset CC_ENGAGE_OVERRIDE_COUNTER to 0.16s;
      Endif
    Endif
    If (Override state over OR\nVehicle speed greater than setspeed) then (TRUE)
      : Reset ACTUAL_SPEED_TAKEN_OVERRIDE to 0;
    Else
    Endif
    }
    End

  @enduml

  @return          void

  @param[in]       cycle_time : cycle time of FCT_VEH cycle [times_t as per Rte_Type.h]ms
  @param[in]       das_input : Pointer to input from longitudinal dynamics management to driver assistance system [cart_das_input_data_t as per cart_ext.h]
                    das_input->BRAKE_STAT.PEDAL_INIT_TRAVEL : Boolean indicating if brake pedal is pressed [TRUE, FALSE]
                    das_input->LODM_STAT.STANDSTILL : Boolean indicating if vehicle standstill is detected [TRUE, FALSE]
  @param[in]       input : Pointer to CC input interface [cc_input_data_t as per cc_ext.h]
                    input->SLA_INPUT_DATA.SLA_InputStatus.b_SLA_NEW_SPEED_AVAILABLE : Boolean indicating if new valid SLA speed limit available [TRUE, FALSE]
                    input->VEHICLE_STATUS.SPEED_UNIT_KMH : boolean indicating the speed unit, i.e. KMH or MPH [TRUE, FALSE]
                    input->PERMANENT_LIMITER_SETSPEED : Setspeed of CC Limiter [full range of uint8]
  @param[in,out]   driver_controls : Pointer to Selected CC function by driver [cc_driver_controls_t as per cc_ext.h]
                    driver_controls->SELECTED_FUNCTION : This variable reflects which function is selected by the driver [cc_selected_function_t as per cc_ext.h]
                    driver_controls->SELECTED_FUNCTION_LAST_CYCLE : This variable reflects which function was selected by the driver in the former cycle [cc_selected_function_t as per cc_ext.h]
  @param[in]       error_data : Pointer to error data from CC [cc_error_data_t as per cc_ext.h]
                    error_data->CC_INHIBIT : Boolean indicating CC can not be activated [TRUE, FALSE]
  @param[in,out]   cc_status : Pointer to Cruisecontrol status [cc_status_t as per cc_ext.h]
                    cc_status->CC_ACCEL_CONTROL_DATA.ACCEL_STATUS.CANCEL_RAMP : [TRUE, FALSE]
                    cc_status->CC_ACCEL_CONTROL_DATA.ACCEL_STATUS.OBJECT_EFFECTIVE : [TRUE, FALSE]
                    cc_status->CC_DRIVER_REQUESTS : Data that reflects the driver's request intention [cc_driver_requests_t as per cc_ext.h]
                    cc_status->CC_DRIVER_REQUESTS.DRIVER_REQUEST_STATUS.SELECTED_FUNCTION_ACTIVE : Boolean indicating if ACC/CC active  [TRUE, FALSE]
                    cc_status->CC_DRIVER_REQUESTS.DRIVER_REQUEST_STATUS.TIMED_INCREMENT : Boolean if constant increasing of set speed   [TRUE, FALSE]
                    cc_status->CC_DRIVER_REQUESTS.DRIVER_REQUEST_STATUS.TIMED_DECREMENT : Boolean if constant decreasing of set speed   [TRUE, FALSE]
                    cc_status->CC_DRIVER_REQUESTS.DRIVER_REQUEST_STATUS.ACTUAL_SPEED_TAKEN_SET :      [TRUE, FALSE]
                    cc_status->CC_DRIVER_REQUESTS.DRIVER_REQUEST_STATUS.ACTUAL_SPEED_TAKEN_OVERRIDE : [TRUE, FALSE]
                    cc_status->CC_DRIVER_REQUESTS.DRIVER_REQUEST_STATUS.OVERRIDE_WHILE_ENGAGEMENT :   [TRUE, FALSE]
                    cc_status->CC_DRIVER_REQUESTS.DRIVER_OPERATIONS.DRIVE_OFF_CONFIRM : Boolean indicating vehicle drive off [TRUE, FALSE]
                    cc_status->CC_DRIVER_REQUESTS.DRIVER_OPERATIONS.CC_TAKE_ACTUAL_SPEED : Boolean, if TRUE take actual vehicle speedometer speed as CC_SETSPEED [TRUE, FALSE]
                    cc_status->CC_DRIVER_REQUESTS.DRIVER_OPERATIONS.LIM_TAKE_ACTUAL_SPEED : Boolean, if TRUE take actual vehicle speedometer speed as LIM_SETSPEED [TRUE, FALSE]
                    cc_status->CC_DRIVER_REQUESTS.DRIVER_OPERATIONS.CC_RESUME_SET_SPEED : Boolean, if TRUE use the stored set speed as CC_SETSPEED [TRUE, FALSE]
                    cc_status->CC_DRIVER_REQUESTS.DRIVER_OPERATIONS.LIM_RESUME_SET_SPEED : Boolean, if TRUE use the stored limiter speed as CC_SETSPEED [TRUE, FALSE]
                    cc_status->CC_DRIVER_REQUESTS.DRIVER_OPERATIONS.CC_INCREASE_SET_SPEED : Boolean if constant increasing of set speed [TRUE, FALSE]
                    cc_status->CC_DRIVER_REQUESTS.DRIVER_OPERATIONS.CC_DECREASE_SET_SPEED : Boolean if constant decreasing of set speed [TRUE, FALSE]
                    cc_status->CC_DRIVER_REQUESTS.DRIVER_OPERATIONS.LIM_INCREASE_SET_SPEED : Boolean, if TRUE increase the LIM_SETSPEED [TRUE, FALSE]
                    cc_status->CC_DRIVER_REQUESTS.DRIVER_OPERATIONS.LIM_DECREASE_SET_SPEED : Boolean, if TRUE decrease the LIM_SETSPEED [TRUE, FALSE]
                    cc_status->CC_DRIVER_REQUESTS.DRIVER_OPERATIONS.SPEED_STEP_1 : Boolean, if TRUE SPEED_STEP_1 is active [TRUE, FALSE]
                    cc_status->CC_DRIVER_REQUESTS.DRIVER_OPERATIONS.CANCEL_FUNKTION : [TRUE, FALSE]
                    cc_status->CC_DRIVER_REQUESTS.DRIVER_OPERATIONS.RESET_SETSPEED : Boolean, if TRUE reset CC_SETSPEED and LIM_SETSPEED to 0 [TRUE, FALSE]
                    cc_status->CC_DRIVER_REQUESTS.DRIVER_OPERATIONS.SWITCH_SPEED_UNIT : Boolean if speed unit is changed by driver [TRUE, FALSE]
                    cc_status->CC_DRIVER_REQUESTS.DRIVER_OPERATIONS.SPEED_LIMIT_ACCEPTED : Boolean indicating speed limit accepted from driver, if SLA support is active (FCT_CFG_SLA_FEATURE) [TRUE, FALSE]
                    cc_status->CC_DRIVER_REQUESTS.DRIVER_OPERATIONS.SPEED_LIMIT_DECLINED : Boolean indicating speed limit declined from driver, if SLA support is active (FCT_CFG_SLA_FEATURE) [TRUE, FALSE]
                    cc_status->CC_DRIVER_REQUESTS.DRIVER_OPERATIONS.DECEL_MODE : Boolean indicating if deceleration with constant value [TRUE, FALSE]
                    cc_status->CC_DRIVER_REQUESTS.DRIVER_OPERATIONS.ACCEL_MODE : Boolean indicating if acceleration with constant value [TRUE, FALSE]
                    cc_status->CC_DRIVER_REQUESTS.DRIVER_OPERATIONS.DISENGAGE_DRIVER_INTERVENED : [TRUE, FALSE]
                    cc_status->CC_DRIVER_REQUESTS.DRIVE_OFF_TIME : Timer for drive-off [times_t as per Rte_Type.h]ms
                    cc_status->CC_DRIVER_REQUESTS.STAND_STILL_TIME : Timer for stand still [times_t as per Rte_Type.h]ms
                    cc_status->CC_DRIVER_REQUESTS.DRIVER_OPERATIONS_LAST_CYCLE : Bitfields represeting driver operations from last cycle [cc_driver_operations_t as per cc_ext.h]
                    cc_status->CC_DRIVER_REQUESTS.CC_SETSPEED : Current Cruise Control set speed [full range of datatype uint8]
                    cc_status->CC_DRIVER_REQUESTS.CONTROL_MODE : Cruise control mode within the active state [0, 2]
                    cc_status->CC_DRIVER_REQUESTS.SPEEDOMETER_VEHICLE_SPEED_OFFSET : Offset compensated speedometer speed  with factor Speedo_speed_s [full range of datatype sint16]
                    cc_status->CC_DRIVER_REQUESTS.ENGAGEMENT_CONDITIONS.DRIVE_OFF_POSSIBLE : Boolean, if TRUE drive-off is possible [TRUE, FALSE]
                    cc_status->CC_DRIVER_REQUESTS.CONTROL_STATE : Variable that reflects the state of the HMI state machine [0, 11]
                    cc_status->CC_DRIVER_REQUESTS.CONTROL_STATE_LAST_CYCLE : Variable that reflects the state of the HMI state machine in the former cycle [0, 11]
                    cc_status->CC_ENGAGE_OVERRIDE_COUNTER : Counter [full range of uint16]
                    cc_status->CC_SPEED_UNIT_LAST_CYCLE : Speed unit of previous cycle [full range of uint8]
                    cc_status->CC_SLA_HMI_DATA.e_SLA_State : State of SLA state machine [t_e_SLA_State as per cc_ext.h]
                    cc_status->CC_SLA_HMI_DATA.SLA_SpeedLimitActualAccepted.u_SpeedLimit : Accepted speed limit [full range of datatype uint8]
                    cc_status->CC_SLA_HMI_DATA.u_SLA_LastSetSpeedForTakeOver : Last set speed changed by SLA Function [full range of datatype uint8]
  @param[in,out]   driver_inputs : Pointer to inputs received from driver [cc_driver_inputs_t as per fct_long_veh_customfunctions]
                    driver_inputs->CC_DECEL_SWITCH_1 : Input of DECEL_SWITCH_1 from driver [switch_t as per switch_ext.h]
                    driver_inputs->CC_DECEL_SWITCH_1.AKT_STATUS : Actual status for input of decel_switch_1 from driver [full range of ubit32]
                    driver_inputs->CC_DECEL_SWITCH_1.DURATION_TIME_ACTIVE : Number of cycles for which switch is inactive [full range of ubit32]
                    driver_inputs->CC_DECEL_SWITCH_2 : Input of DECEL_SWITCH_2 from driver [switch_t as per switch_ext.h]
                    driver_inputs->CC_DECEL_SWITCH_2.AKT_STATUS : Actual status for input of decel_switch_2 from driver [full range of ubit32]
                    driver_inputs->CC_DECEL_SWITCH_2.DURATION_TIME_INACTIVE : Number of cycles for which switch is inactive [full range of ubit32]
                    driver_inputs->CC_ACCEL_SWITCH_1 : Input of ACCEL_SWITCH_1 from driver [switch_t as per switch_ext.h]
                    driver_inputs->CC_ACCEL_SWITCH_1.AKT_STATUS : Actual status for input of accel_switch_1 from driver [full range of ubit32]
                    driver_inputs->CC_ACCEL_SWITCH_1.DURATION_TIME_ACTIVE : Number of cycles for which switch is inactive [full range of ubit32]
                    driver_inputs->CC_ACCEL_SWITCH_2 : Input of ACCEL_SWITCH_2 from driver [switch_t as per switch_ext.h]
                    driver_inputs->CC_ACCEL_SWITCH_2.AKT_STATUS : Actual status for input of accel_switch_2 from driver [full range of ubit32]
                    driver_inputs->CC_ACCEL_SWITCH_2.DURATION_TIME_INACTIVE : Number of cycles for which switch is inactive [full range of ubit32]
                    driver_inputs->CC_CANCEL_SWITCH.AKT_STATUS : Actual status for input of cancel_switch from driver [full range of ubit32]
                    driver_inputs->CC_RESUME_SWITCH : Input of RESUME_SWITCH from driver [switch_t as per switch_ext.h]
  @param[in]       pFCTAccOOIData : Pointer to ACC Objects from FCT_SEN to FCT_VEH [FCTSenAccOOI_t as per Rte_type.h]
                    pFCTAccOOIData->AccOOINextLong.Attributes.uiObjectID : FCT Obj Id of OOI-0 [ObjNumber_t as per Rte_type.h]
                    pFCTAccOOIData->AccOOINextLong.Kinematic.fDistX : Longitudinal distance to OOI-0 [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m

  @glob_in         None
  @glob_out        uiSLA_SpeedAppliedTimer : Timer measuring duration after SLA speed limit is regulated or applied [times_t as per Rte_type.h]ms
  @glob_out        uiSLA_OverrideTimer : Timer for SLA speed limit to be cancelled due to driver override [times_t as per Rte_type.h]ms
  @glob_out        DriveOffConfirmation_Timer : Timer measuring duration after driveoff [times_t as per Rte_type.h]ms
  @glob_out        DriveOffConfirmation : Boolean confirming Driveoff [full range of uint8]
  @glob_out        set_speed_last_cycle : Cruise control setspeed from last cycle [full range of uint16]
  @glob_out        last_effective_object_id : Object Id of last effective object [ObjNumber_t as per Rte_type.h]

  @c_switch_part   CFG_FCT_CC_USE_ACCEL_DECEL_MODE : Use a special accel/decel mode where a specific acceleration request is used as long as the driver wants so
  @c_switch_part   FCT_CFG_FSRACC : Configuration switch enabling Full Speed Range Adaptive Cruise Control functionality (with object evaluation and stop and go capability)
  @c_switch_part   CFG_FCT_USE_TWICE_CONFIRMATION_FOR_DRIVE_OFF : Only accept confirmation to drive off in standstill if driver as pressed Resume twice
  @c_switch_part   CFG_FCT_CC_RST_SETSPEED_DECEL_ONLY : Configuration switch for enabling Setspeed Reset only if state changes from Cc_cc_decel_only
  @c_switch_full   FCT_CFG_LOPC_COMPONENT : Configuration switch for enabling LOPC processing
  @c_switch_full   FCT_CFG_CC : Configuration switch for enabling CC processing

  @pre             
  @post            

  @created         
  @changed         22.07.2019

  @todo            

  @author          

*****************************************************************************/
static void KMC_v_DetermineDriverOperations(const times_t cycle_time,
                                           const cart_das_input_data_t* das_input,
                                           const cc_input_data_t* input,
                                           cc_driver_controls_t* driver_controls,
                                           const cc_error_data_t* error_data, 
                                           cc_status_t *cc_status,
#if (CFG_ACC_LEVER_INPUT)
                                           cc_driver_inputs_t *driver_inputs
#else
                                           const acc_output_data_t * acc_output
#endif
                                           )
{
#if (CFG_FCT_USE_TWICE_CONFIRMATION_FOR_DRIVE_OFF)
static times_t DriveOffConfirmation_Timer = Cc_default_drive_off_confirmation_time;
static uint8           DriveOffConfirmation = FALSE;
#endif
#if (CFG_FCT_CC_USE_ACCEL_DECEL_MODE)
  /*! Use of an AUTOSAR type : here it makes sense, to avoid MISRA violations:
  logical expressions are per default of 'int' type, but directly using 'int's
  is prohibited */
  boolean temp_condition;
#endif 
#if (CFG_ACC_LEVER_INPUT)
  /*! Calculate the number of cycles for Cc_start_repeat_function_time here once.
  Note: would be better to adapt switch to time instead of cycles... */
  const uint16           cc_start_repeat_fun_cycles = (uint16)(Cc_start_repeat_function_time / cycle_time);
  /*! Calculate the number of cycles for Cc_repeat_function_time once. */
  const uint16           cc_repeat_fun_cycles = (uint16)(Cc_repeat_function_time / cycle_time);
  switch_state_t t_switch_hold = SWITCH_STATE_OFF;
  switch_state_t t_switch_falling_edge = SWITCH_STATE_OFF;
//switch_state_t t_switch_rising_edge = SWITCH_STATE_OFF;
#endif
  /* Get utility pointer to driver requests (used in filling) */
  cc_driver_requests_t * const driver_requests = &cc_status->CC_DRIVER_REQUESTS;
  
  /* Interpret DriverActions */
  driver_requests->DRIVER_REQUEST_STATUS.SELECTED_FUNCTION_ACTIVE = FALSE;
  driver_requests->DRIVER_OPERATIONS.CC_TAKE_ACTUAL_SPEED = FALSE;
  driver_requests->DRIVER_OPERATIONS.LIM_TAKE_ACTUAL_SPEED = FALSE;
  driver_requests->DRIVER_OPERATIONS.CC_RESUME_SET_SPEED = FALSE;
  driver_requests->DRIVER_OPERATIONS.LIM_RESUME_SET_SPEED = FALSE;
  driver_requests->DRIVER_OPERATIONS.CC_INCREASE_SET_SPEED = FALSE;
  driver_requests->DRIVER_OPERATIONS.CC_DECREASE_SET_SPEED = FALSE;
  driver_requests->DRIVER_OPERATIONS.LIM_INCREASE_SET_SPEED = FALSE;
  driver_requests->DRIVER_OPERATIONS.LIM_DECREASE_SET_SPEED = FALSE;
  driver_requests->DRIVER_OPERATIONS.SPEED_STEP_1 = FALSE;
  driver_requests->DRIVER_OPERATIONS.CANCEL_FUNKTION = FALSE;
  driver_requests->DRIVER_OPERATIONS.DISENGAGE_DRIVER_INTERVENED = FALSE;
  driver_requests->DRIVER_OPERATIONS.RESET_SETSPEED = FALSE;
  driver_requests->DRIVER_OPERATIONS.SWITCH_SPEED_UNIT = FALSE;
  driver_requests->DRIVER_OPERATIONS.DRIVE_OFF_CONFIRM = FALSE;
#if (FCT_CFG_SLA_FEATURE)
  driver_requests->DRIVER_OPERATIONS.SPEED_LIMIT_ACCEPTED = FALSE;
  driver_requests->DRIVER_OPERATIONS.SPEED_LIMIT_DECLINED = FALSE;
#endif
  driver_requests->DRIVER_OPERATIONS.DECEL_MODE = FALSE;
  driver_requests->DRIVER_OPERATIONS.ACCEL_MODE = FALSE;

#if (CFG_ACC_LEVER_INPUT)

  if (driver_inputs->CC_ACCEL_SWITCH_2.AKT_STATUS == FALSE)
  {
    driver_requests->DRIVER_REQUEST_STATUS.TIMED_INCREMENT = FALSE;
  }

  if (driver_inputs->CC_DECEL_SWITCH_2.AKT_STATUS == FALSE)
  {
    driver_requests->DRIVER_REQUEST_STATUS.TIMED_DECREMENT = FALSE;
  }

  if (
      (driver_inputs->CC_ACCEL_SWITCH_1.AKT_STATUS == FALSE)
      &&
      (driver_inputs->CC_DECEL_SWITCH_1.AKT_STATUS == FALSE)
      &&
      (driver_inputs->CC_ACCEL_SWITCH_2.AKT_STATUS == FALSE)
      &&
      (driver_inputs->CC_DECEL_SWITCH_2.AKT_STATUS == FALSE)
      &&
      (driver_inputs->CC_SET_SWITCH.AKT_STATUS == FALSE)
      &&
      (driver_inputs->CC_RESUME_SWITCH.AKT_STATUS == FALSE)
     )
  {
    driver_requests->DRIVER_REQUEST_STATUS.ACTUAL_SPEED_TAKEN_SET = FALSE;
  }

  if(
      (driver_requests->CONTROL_STATE != Cc_cc_override) 
      || 
      ((driver_requests->SPEEDOMETER_VEHICLE_SPEED_OFFSET/Speedo_speed_s) > (sint16)driver_requests->CC_SETSPEED)
    )
  { /* Reset of ACTUAL_SPEED_TAKEN_OVERRIDE flag which is set to 1,
    if vehicle speed is taken as set speed during override */
    driver_requests->DRIVER_REQUEST_STATUS.ACTUAL_SPEED_TAKEN_OVERRIDE = FALSE;
  }

  if (driver_controls->SELECTED_FUNCTION == Cc_function_cc)
  { /* ACC switched ON */
    if(
        (driver_requests->CONTROL_STATE == Cc_cc_engage)
        ||
        (driver_requests->CONTROL_STATE == Cc_cc_active)
        ||
        (driver_requests->CONTROL_STATE == Cc_cc_override)
      )
    {
      driver_requests->DRIVER_REQUEST_STATUS.SELECTED_FUNCTION_ACTIVE = TRUE; /* Indicates ACC currently active */

      /* Driver intervention must be set to active in case brake pedal was pressed */
      if (   ( das_input->BRAKE_STAT.PEDAL_INIT_TRAVEL == TRUE )
          || ( das_input->LODM_STAT.OVERRIDE_DECEL     == TRUE )
         )
      {
        driver_requests->DRIVER_OPERATIONS.DISENGAGE_DRIVER_INTERVENED = TRUE;
      }
    }

    if (error_data->CC_INHIBIT == FALSE)  
    { /* No button interpretation in case of ACC system error flag */
      if ((driver_inputs->CC_CANCEL_SWITCH.AKT_STATUS == TRUE) || (driver_controls->SELECTED_FUNCTION_LAST_CYCLE != driver_controls->SELECTED_FUNCTION)) 
      { /* cancel switch pressed or activated limiter function*/
        driver_requests->DRIVER_OPERATIONS.CANCEL_FUNKTION = TRUE;
        driver_requests->DRIVER_OPERATIONS.DISENGAGE_DRIVER_INTERVENED = TRUE;
        cc_status->CC_ACCEL_CONTROL_DATA.ACCEL_STATUS.CANCEL_RAMP = TRUE;

        driver_inputs->CC_ACCEL_SWITCH_1.OK_WHILE_SWITCHED_ON = (boolean)(driver_controls->SELECTED_FUNCTION == Cc_function_cc);
        driver_inputs->CC_ACCEL_SWITCH_2.OK_WHILE_SWITCHED_ON = (boolean)(driver_controls->SELECTED_FUNCTION == Cc_function_cc);
        driver_inputs->CC_DECEL_SWITCH_1.OK_WHILE_SWITCHED_ON = (boolean)(driver_controls->SELECTED_FUNCTION == Cc_function_cc);
        driver_inputs->CC_DECEL_SWITCH_2.OK_WHILE_SWITCHED_ON = (boolean)(driver_controls->SELECTED_FUNCTION == Cc_function_cc);
        driver_inputs->CC_RESUME_SWITCH.OK_WHILE_SWITCHED_ON  = (boolean)(driver_controls->SELECTED_FUNCTION == Cc_function_cc);
        driver_inputs->CC_SET_SWITCH.OK_WHILE_SWITCHED_ON     = (boolean)(driver_controls->SELECTED_FUNCTION == Cc_function_cc);

      }
      else 
      {
        switch (driver_requests->CONTROL_STATE)
        {
          case Cc_cc_engage:
          /* Do not add code here. Allow to pass */
          case Cc_cc_active:
          /* Do not add code here. Allow to pass */
          case Cc_cc_override:
          {
            /* Common operation conditions for engaged, active, override states */
#if (CFG_FCT_CC_USE_ACCEL_DECEL_MODE)
            if (SWITCH_HOLD_REPEAT(&driver_inputs->CC_DECEL_SWITCH, TRUE, TRUE, cc_start_repeat_fun_cycles, (uint16)(One)) == TRUE) 
            { /*decel switch pressed and hold*/
              driver_requests->DRIVER_OPERATIONS.DECEL_MODE = TRUE;
            }
            else if (SWITCH_HOLD_REPEAT(&driver_inputs->CC_ACCEL_SWITCH, TRUE, TRUE, cc_start_repeat_fun_cycles, (uint16)(One)) == TRUE) 
            { /*accel switch pressed and hold*/
              driver_requests->DRIVER_OPERATIONS.ACCEL_MODE = TRUE;
            }

            temp_condition = (boolean)((driver_requests->DRIVER_OPERATIONS_LAST_CYCLE.ACCEL_MODE == FALSE) && (driver_requests->DRIVER_REQUEST_STATUS.ACTUAL_SPEED_TAKEN_SET == FALSE));
            if (SWITCH_FALLING_EDGE(&driver_inputs->CC_ACCEL_SWITCH, temp_condition) == SWITCH_STATE_ON) 
            {
              driver_requests->DRIVER_OPERATIONS.CC_INCREASE_SET_SPEED = TRUE;
            }
            temp_condition = (boolean)((driver_requests->DRIVER_OPERATIONS_LAST_CYCLE.DECEL_MODE == FALSE) && (driver_requests->DRIVER_REQUEST_STATUS.ACTUAL_SPEED_TAKEN_SET == FALSE));
            if (SWITCH_FALLING_EDGE(&driver_inputs->CC_DECEL_SWITCH, temp_condition) == SWITCH_STATE_ON) 
            {
              driver_requests->DRIVER_OPERATIONS.CC_DECREASE_SET_SPEED = TRUE;
            }
#else /*CFG_FCT_CC_USE_ACCEL_DECEL_MODE*/

            /* Start of conditions specific for non-override mode */
            if(driver_requests->CONTROL_STATE != Cc_cc_override)
            {
              if ((driver_inputs->CC_DECEL_SWITCH_1.AKT_STATUS == TRUE) || (driver_inputs->CC_DECEL_SWITCH_1.LAST_STATUS == TRUE))
              { /* CC_DECEL_SWITCH_1 */
                if(SWITCH_HOLD_REPEAT(&driver_inputs->CC_DECEL_SWITCH_1, TRUE, TRUE, cc_start_repeat_fun_cycles, cc_repeat_fun_cycles) == SWITCH_STATE_ON)
                {
                  driver_requests->DRIVER_OPERATIONS.CC_DECREASE_SET_SPEED = TRUE;
                  driver_requests->DRIVER_REQUEST_STATUS.TIMED_DECREMENT = TRUE;
                  driver_requests->DRIVER_OPERATIONS.SPEED_STEP_1 = TRUE;
                }
                t_switch_falling_edge = SWITCH_FALLING_EDGE(&driver_inputs->CC_DECEL_SWITCH_1, TRUE);
                if( (driver_inputs->CC_DECEL_SWITCH_1.DURATION_TIME_ACTIVE < cc_start_repeat_fun_cycles)
                  && (driver_inputs->CC_DECEL_SWITCH_2.DURATION_TIME_INACTIVE > cc_start_repeat_fun_cycles)
                  && (driver_inputs->CC_DECEL_SWITCH_2.AKT_STATUS == FALSE)
                  && (t_switch_falling_edge == SWITCH_STATE_ON))
                {
                  /* Decel2 switch must be inactive */
                  driver_requests->DRIVER_OPERATIONS.CC_DECREASE_SET_SPEED = TRUE;
                  //driver_requests->DRIVER_OPERATIONS.SPEED_STEP_1 = TRUE;
                }
              } /* End CC_DECEL_SWITCH_1 */
              else if((driver_inputs->CC_DECEL_SWITCH_2.AKT_STATUS == TRUE) || (driver_inputs->CC_DECEL_SWITCH_2.LAST_STATUS == TRUE))
              { /* CC_DECEL_SWITCH_2 */
                if (SWITCH_HOLD_REPEAT(&driver_inputs->CC_DECEL_SWITCH_2,TRUE, TRUE, cc_start_repeat_fun_cycles, cc_repeat_fun_cycles) == SWITCH_STATE_ON)
                {/* PRQA S 715 */
                 /* date: 2018-03-22, reviewer: Ravi kiran Gurrala (uidn6378), reason: Nested control structures exceeds 15, not safety critical */
                  driver_requests->DRIVER_OPERATIONS.CC_DECREASE_SET_SPEED = TRUE;
                  driver_requests->DRIVER_REQUEST_STATUS.TIMED_DECREMENT = TRUE; 
                }
                t_switch_falling_edge = SWITCH_FALLING_EDGE(&driver_inputs->CC_DECEL_SWITCH_2, TRUE);
                if( (driver_inputs->CC_DECEL_SWITCH_2.DURATION_TIME_ACTIVE < cc_start_repeat_fun_cycles)
                  && (t_switch_falling_edge == SWITCH_STATE_ON))
                {/* PRQA S 715 */
                 /* date: 2018-03-22, reviewer: Ravi kiran Gurrala (uidn6378), reason: Nested control structures exceeds 15, not safety critical */
                  driver_requests->DRIVER_OPERATIONS.CC_DECREASE_SET_SPEED = TRUE;
                }
              } /* End CC_DECEL_SWITCH_2 */
              else if((driver_inputs->CC_ACCEL_SWITCH_1.AKT_STATUS == TRUE) || (driver_inputs->CC_ACCEL_SWITCH_1.LAST_STATUS == TRUE))
              /* PRQA S 715 */
              /* date: 2018-03-22, reviewer: Ravi kiran Gurrala (uidn6378), reason: Nested control structures exceeds 15, not safety critical */
              { /* CC_ACCEL_SWITCH_1 */
                if (SWITCH_HOLD_REPEAT(&driver_inputs->CC_ACCEL_SWITCH_1, TRUE, TRUE, cc_start_repeat_fun_cycles, cc_repeat_fun_cycles) == SWITCH_STATE_ON)/* PRQA S 715 */
                 /* date: 2018-03-22, reviewer: Ravi kiran Gurrala (uidn6378), reason: Nested control structures exceeds 15, not safety critical */
                {
                  driver_requests->DRIVER_OPERATIONS.CC_INCREASE_SET_SPEED = TRUE;
                  driver_requests->DRIVER_REQUEST_STATUS.TIMED_INCREMENT = TRUE;
                  driver_requests->DRIVER_OPERATIONS.SPEED_STEP_1 = TRUE;
                }
                t_switch_falling_edge = SWITCH_FALLING_EDGE(&driver_inputs->CC_ACCEL_SWITCH_1, TRUE);
                if( (driver_inputs->CC_ACCEL_SWITCH_1.DURATION_TIME_ACTIVE < cc_start_repeat_fun_cycles)/* PRQA S 715 */
                 /* date: 2018-03-22, reviewer: Ravi kiran Gurrala (uidn6378), reason: Nested control structures exceeds 15, not safety critical */
                  && (driver_inputs->CC_ACCEL_SWITCH_2.DURATION_TIME_INACTIVE > cc_start_repeat_fun_cycles)
                  && (driver_inputs->CC_ACCEL_SWITCH_2.AKT_STATUS == FALSE)
                  && (t_switch_falling_edge == SWITCH_STATE_ON))
                {
                  /* Accel2 switch must be inactive */
                  driver_requests->DRIVER_OPERATIONS.CC_INCREASE_SET_SPEED = TRUE;
                  //driver_requests->DRIVER_OPERATIONS.SPEED_STEP_1 = TRUE;
                }
              } /* End CC_ACCEL_SWITCH_1 */
              else if ((driver_inputs->CC_ACCEL_SWITCH_2.AKT_STATUS == TRUE) || (driver_inputs->CC_ACCEL_SWITCH_2.LAST_STATUS == TRUE))
              /* PRQA S 715 */
              /* date: 2018-03-22, reviewer: Ravi kiran Gurrala (uidn6378), reason: Nested control structures exceeds 15, not safety critical */
              { /* CC_ACCEL_SWITCH_2 *//* PRQA S 715 */
              /* date: 2018-03-22, reviewer: Ravi kiran Gurrala (uidn6378), reason: Nested control structures exceeds 15, not safety critical */
                if(SWITCH_HOLD_REPEAT(&driver_inputs->CC_ACCEL_SWITCH_2, TRUE, TRUE, cc_start_repeat_fun_cycles, cc_repeat_fun_cycles) == SWITCH_STATE_ON)
                {
                  driver_requests->DRIVER_OPERATIONS.CC_INCREASE_SET_SPEED = TRUE;
                  driver_requests->DRIVER_REQUEST_STATUS.TIMED_INCREMENT = TRUE;
                }
                t_switch_falling_edge = SWITCH_FALLING_EDGE(&driver_inputs->CC_ACCEL_SWITCH_2, TRUE);
                if((driver_inputs->CC_ACCEL_SWITCH_2.DURATION_TIME_ACTIVE < cc_start_repeat_fun_cycles)
                  &&(t_switch_falling_edge == SWITCH_STATE_ON))
                {
                  driver_requests->DRIVER_OPERATIONS.CC_INCREASE_SET_SPEED = TRUE;
                }
              } /* End CC_ACCEL_SWITCH_2 */
#endif /*CFG_FCT_CC_USE_ACCEL_DECEL_MODE*/
              else if((driver_inputs->CC_RESUME_SWITCH.AKT_STATUS == TRUE) || (driver_inputs->CC_RESUME_SWITCH.LAST_STATUS == TRUE))/* PRQA S 715 */
                 /* date: 2018-03-22, reviewer: Ravi kiran Gurrala (uidn6378), reason: Nested control structures exceeds 15, not safety critical */
              {   /* CC_RESUME_SWITCH */
				
                if(driver_requests->CONTROL_MODE == Cc_standstill_mode)
                {
#if (FCT_CFG_FSRACC)
#if (CFG_FCT_USE_TWICE_CONFIRMATION_FOR_DRIVE_OFF) 
                  /* Driver has to confirm drive off with twice actuations of resume switch within a special time Cc_drive_off_confirmation_time */
                  if(
                    (DriveOffConfirmation_Timer < Cc_drive_off_confirmation_time) 
                    &&
                    (DriveOffConfirmation == FALSE)
                    )
                  {
                    if(SWITCH_RISING_EDGE(&driver_inputs->CC_RESUME_SWITCH, driver_requests->DRIVER_REQUEST_STATUS.SELECTED_FUNCTION_ACTIVE) == SWITCH_STATE_ON)
                    {
                      DriveOffConfirmation = TRUE;
                    }
                    else
                    {
                      DriveOffConfirmation_Timer += cycle_time;
                    }
                  }
                  else
                  {
                    DriveOffConfirmation = FALSE;
                    DriveOffConfirmation_Timer = Cc_drive_off_confirmation_time;
                    if(SWITCH_RISING_EDGE(&driver_inputs->CC_RESUME_SWITCH, TRUE) == SWITCH_STATE_ON)
                    {
                      DriveOffConfirmation_Timer = 0;
                    }
                  }
                  if(DriveOffConfirmation == TRUE)
#else /*CFG_FCT_USE_TWICE_CONFIRMATION_FOR_DRIVE_OFF */
                  if(SWITCH_FALLING_EDGE(&driver_inputs->CC_RESUME_SWITCH, TRUE) == SWITCH_STATE_ON)
#endif /*CFG_FCT_USE_TWICE_CONFIRMATION_FOR_DRIVE_OFF */
                  {
                    /* When driver presses the resume switch the 5 second counter allowing automatic
                    drive off starts counting from zero again (prolonging the time allowed for drive off) */
                    driver_requests->DRIVE_OFF_TIME = 0u;
                    driver_requests->DRIVER_OPERATIONS.DRIVE_OFF_CONFIRM = TRUE;
                  }
                  else
                  {
                    /* When driver did not press the resume switch, then increase the drive off timer to
                    count the number of miliseconds ellapsed, until Cc_drive_off_smooth_time is reached */
                    if(driver_requests->DRIVE_OFF_TIME < Cc_drive_off_smooth_time)
                    {
                      driver_requests->DRIVE_OFF_TIME += cycle_time;
                    }
                    else
                    {
                      driver_requests->DRIVE_OFF_TIME = Cc_drive_off_smooth_time;
                    }
                  }
#endif /* FCT_CFG_FSRACC */
                }
                else  /* Not in standstill mode */
                {
                  if(SWITCH_HOLD_REPEAT(&driver_inputs->CC_RESUME_SWITCH, TRUE, TRUE, cc_start_repeat_fun_cycles, cc_repeat_fun_cycles) == SWITCH_STATE_ON)
                  {
                    /*! That logic increment the set speed for SPEED_STEP_1*/
                    driver_requests->DRIVER_OPERATIONS.CC_INCREASE_SET_SPEED = TRUE;
                    driver_requests->DRIVER_REQUEST_STATUS.TIMED_INCREMENT = TRUE;
                    driver_requests->DRIVER_OPERATIONS.SPEED_STEP_1 = TRUE;
                  }
                  t_switch_falling_edge = SWITCH_FALLING_EDGE(&driver_inputs->CC_RESUME_SWITCH, TRUE);
                  if( (driver_inputs->CC_RESUME_SWITCH.DURATION_TIME_ACTIVE < cc_start_repeat_fun_cycles)
                    && (driver_inputs->CC_ACCEL_SWITCH_2.DURATION_TIME_INACTIVE > cc_start_repeat_fun_cycles)
                    && (driver_inputs->CC_ACCEL_SWITCH_2.AKT_STATUS == FALSE)
                    && (t_switch_falling_edge == SWITCH_STATE_ON))
                  {
                    /* Accel2 switch must be inactive */
                    driver_requests->DRIVER_OPERATIONS.CC_INCREASE_SET_SPEED = TRUE;
                    driver_requests->DRIVER_OPERATIONS.SPEED_STEP_1 = TRUE;
                  }
                }
              }   /* End CC_RESUME_SWITCH */
              else if ((driver_inputs->CC_SET_SWITCH.AKT_STATUS == TRUE) || (driver_inputs->CC_SET_SWITCH.LAST_STATUS == TRUE))// PRQA S 2004 
              /* date: 2018-03-22, reviewer: Ravi Kiran Gurrala, reason: conditions are checking in if and elseif, else is not required*/
              { /* CC_SET_SWITCH */
                if(
#if (FCT_CFG_SLA_FEATURE)
                    (cc_status->CC_SLA_HMI_DATA.SLA_Event.b_SLA_USAGE_AVAILABLE == FALSE) /* Driver operations not used for SLA */
#else               
                    (TRUE) /* If SLA feature is off, this condition must always be true */
#endif
                  )
                { /* Button allowed to be used to change set speed */
					t_switch_falling_edge = SWITCH_FALLING_EDGE(&driver_inputs->CC_SET_SWITCH, TRUE);
					if (t_switch_falling_edge == SWITCH_STATE_ON)
					{
						driver_requests->DRIVER_OPERATIONS.CC_TAKE_ACTUAL_SPEED = TRUE;
						/*add this logic for standtill can use set button to active fucntion by customer req*/
						if(driver_requests->CONTROL_MODE == Cc_standstill_mode)
						{
							driver_requests->DRIVER_OPERATIONS.DRIVE_OFF_CONFIRM = TRUE;
						}
						else
						{
							// do nothing
						}
					}
                }
                else
                { /* Button used for SLA interaction */  // PRQA S 3201
				/* date: 2018-03-22, reviewer: Letian Zhang, reason: below sentences are reachable when SLA feature is switched on*/
#if (FCT_CFG_SLA_FEATURE)
                    /* Set button to be used for SLA */
                    if(SWITCH_RISING_EDGE(&driver_inputs->CC_SET_SWITCH, TRUE) == SWITCH_STATE_ON)
                    {
                      if(input->SLA_INPUT_DATA.SLA_InputStatus.b_SLA_NEW_SPEED_AVAILABLE)
                      {
                        driver_requests->DRIVER_OPERATIONS.SPEED_LIMIT_ACCEPTED = TRUE;
                      }
                    }
                    driver_inputs->CC_SET_SWITCH.OK_WHILE_SWITCHED_ON = TRUE;
                    if(
                        (SWITCH_FALLING_EDGE(&driver_inputs->CC_SET_SWITCH, TRUE) == SWITCH_STATE_ON)
                        &&						
                        (uiSLA_MsgDisplayTimer > 0)						
                      )
                    { /* Set button has already been used for SLA activation */
                      cc_status->CC_SLA_HMI_DATA.SLA_Event.b_SLA_USAGE_AVAILABLE = FALSE; /* Reset usage of set button for speed change, after end of pressing */
                      uiSLA_ManUsageTimer = (times_t)0; /* Reset timer for manual usage of SLA function */
                    }
#endif  /* FCT_CFG_SLA_FEATURE */
                }
              } /* End CC_SET_SWITCH */
              /* End of conditions common for engaged, active mode */
            }
            else /* Start of conditions specific for Override mode */
            {
#if (!CFG_FCT_CC_USE_ACCEL_DECEL_MODE)
              if ((driver_inputs->CC_DECEL_SWITCH_1.AKT_STATUS == TRUE) || (driver_inputs->CC_DECEL_SWITCH_1.LAST_STATUS == TRUE))
              { /* CC_DECEL_SWITCH_1 */
                t_switch_falling_edge = SWITCH_FALLING_EDGE(&driver_inputs->CC_DECEL_SWITCH_1, TRUE);
                if( (driver_inputs->CC_DECEL_SWITCH_1.DURATION_TIME_ACTIVE < cc_start_repeat_fun_cycles)
                  && (driver_inputs->CC_DECEL_SWITCH_2.DURATION_TIME_INACTIVE > cc_start_repeat_fun_cycles)
                  && (driver_inputs->CC_DECEL_SWITCH_2.AKT_STATUS == FALSE)
                  && (t_switch_falling_edge == SWITCH_STATE_ON))
                {
                  /* Decel2 switch must be inactive */
                  /* Leads to setspeed increase (because in override) even though Decel is pressed */
                  if(
                    (driver_requests->DRIVER_REQUEST_STATUS.ACTUAL_SPEED_TAKEN_OVERRIDE == FALSE)/* PRQA S 715 */
                     /* date: 2018-03-22, reviewer: Ravi kiran Gurrala (uidn6378), reason: Nested control structures exceeds 15, not safety critical */
                    && 
                    (driver_requests->DRIVER_REQUEST_STATUS.OVERRIDE_WHILE_ENGAGEMENT == FALSE) 
                    &&
                    ((driver_requests->SPEEDOMETER_VEHICLE_SPEED_OFFSET/Speedo_speed_s) > (sint16)(driver_requests->CC_SETSPEED))
                    )
                  {
                    driver_requests->DRIVER_REQUEST_STATUS.ACTUAL_SPEED_TAKEN_OVERRIDE = TRUE;
                    driver_requests->DRIVER_OPERATIONS.CC_TAKE_ACTUAL_SPEED = TRUE; 
                  }
                  else 
                  {  
                    driver_requests->DRIVER_OPERATIONS.CC_DECREASE_SET_SPEED = TRUE;
                    driver_requests->DRIVER_OPERATIONS.SPEED_STEP_1 = TRUE;
                  }
                }
              } /* End CC_DECEL_SWITCH_1 */
              else if((driver_inputs->CC_DECEL_SWITCH_2.AKT_STATUS == TRUE) || (driver_inputs->CC_DECEL_SWITCH_2.LAST_STATUS == TRUE))
              { /* CC_DECEL_SWITCH_2 */
                t_switch_falling_edge = SWITCH_FALLING_EDGE(&driver_inputs->CC_DECEL_SWITCH_2, TRUE);
                if((driver_inputs->CC_DECEL_SWITCH_2.DURATION_TIME_ACTIVE < cc_start_repeat_fun_cycles)
                  &&(t_switch_falling_edge == SWITCH_STATE_ON))
                {/* PRQA S 715 */
                 /* date: 2018-03-22, reviewer: Ravi kiran Gurrala (uidn6378), reason: Nested control structures exceeds 15, not safety critical */
                  /* Leads to setspeed increase (because in override) even though Decel is pressed */
                  if(
                    (driver_requests->DRIVER_REQUEST_STATUS.ACTUAL_SPEED_TAKEN_OVERRIDE == FALSE) 
                    && 
                    (driver_requests->DRIVER_REQUEST_STATUS.OVERRIDE_WHILE_ENGAGEMENT == FALSE)
                    &&
                    ((driver_requests->SPEEDOMETER_VEHICLE_SPEED_OFFSET/Speedo_speed_s) > (sint16)driver_requests->CC_SETSPEED)
                    )
                  {
                    driver_requests->DRIVER_REQUEST_STATUS.ACTUAL_SPEED_TAKEN_OVERRIDE = TRUE;
                    driver_requests->DRIVER_OPERATIONS.CC_TAKE_ACTUAL_SPEED = TRUE; 
                  }
                  else
                  {
                    driver_requests->DRIVER_OPERATIONS.CC_DECREASE_SET_SPEED = TRUE;
                  }
                }
              } /* End CC_DECEL_SWITCH_2 */
              else if((driver_inputs->CC_ACCEL_SWITCH_1.AKT_STATUS == TRUE) || (driver_inputs->CC_ACCEL_SWITCH_1.LAST_STATUS == TRUE))
              { /* CC_ACCEL_SWITCH_1 */
                if (SWITCH_HOLD_REPEAT(&driver_inputs->CC_ACCEL_SWITCH_1, TRUE, TRUE, cc_start_repeat_fun_cycles, cc_repeat_fun_cycles) == SWITCH_STATE_ON)/* PRQA S 715 */
                 /* date: 2018-03-22, reviewer: Ravi kiran Gurrala (uidn6378), reason: Nested control structures exceeds 15, not safety critical */
                {
				   /* No Actual speed should be taken if Resume/+ pressed during override (ARS410VA10 custom)
                  if(
                    (driver_requests->DRIVER_REQUEST_STATUS.ACTUAL_SPEED_TAKEN_OVERRIDE == FALSE) 
                    && 
                    (driver_requests->DRIVER_REQUEST_STATUS.OVERRIDE_WHILE_ENGAGEMENT == FALSE) 
                    &&
                    ((driver_requests->SPEEDOMETER_VEHICLE_SPEED_OFFSET/Speedo_speed_s) > (sint16)driver_requests->CC_SETSPEED)
                    )
                  {
                    driver_requests->DRIVER_REQUEST_STATUS.ACTUAL_SPEED_TAKEN_OVERRIDE = TRUE;
                    driver_requests->DRIVER_OPERATIONS.CC_TAKE_ACTUAL_SPEED = TRUE; 
                  }
                  else
                  {*/
                    driver_requests->DRIVER_OPERATIONS.CC_INCREASE_SET_SPEED = TRUE;
                    driver_requests->DRIVER_REQUEST_STATUS.TIMED_INCREMENT = TRUE;
                    driver_requests->DRIVER_OPERATIONS.SPEED_STEP_1 = TRUE;
                  /*}*/
                }
                t_switch_falling_edge = SWITCH_FALLING_EDGE(&driver_inputs->CC_ACCEL_SWITCH_1, TRUE);
                if( (driver_inputs->CC_ACCEL_SWITCH_1.DURATION_TIME_ACTIVE < cc_start_repeat_fun_cycles)/* PRQA S 715 */
                 /* date: 2018-03-22, reviewer: Ravi kiran Gurrala (uidn6378), reason: Nested control structures exceeds 15, not safety critical */
                  && (driver_inputs->CC_ACCEL_SWITCH_2.DURATION_TIME_INACTIVE > cc_start_repeat_fun_cycles)
                  && (driver_inputs->CC_ACCEL_SWITCH_2.AKT_STATUS == FALSE)
                  && (t_switch_falling_edge == SWITCH_STATE_ON))
                {
                  /* Accel2 switch must be inactive */
				   /* No Actual speed should be taken if Resume/+ pressed during override (ARS410VA10 custom)
                  if(
                    (driver_requests->DRIVER_REQUEST_STATUS.ACTUAL_SPEED_TAKEN_OVERRIDE == FALSE) 
                    && 
                    (driver_requests->DRIVER_REQUEST_STATUS.OVERRIDE_WHILE_ENGAGEMENT == FALSE) 
                    &&
                    ((driver_requests->SPEEDOMETER_VEHICLE_SPEED_OFFSET/Speedo_speed_s) > (sint16)driver_requests->CC_SETSPEED)
                    )
                  {
                    driver_requests->DRIVER_REQUEST_STATUS.ACTUAL_SPEED_TAKEN_OVERRIDE = TRUE;
                    driver_requests->DRIVER_OPERATIONS.CC_TAKE_ACTUAL_SPEED = TRUE; 
                  }
                  else
                  {
					  */
                    driver_requests->DRIVER_OPERATIONS.CC_INCREASE_SET_SPEED = TRUE;
                    //driver_requests->DRIVER_OPERATIONS.SPEED_STEP_1 = TRUE;
                  /*}*/
                }
              } /* End CC_ACCEL_SWITCH_1 */
              else if ((driver_inputs->CC_ACCEL_SWITCH_2.AKT_STATUS == TRUE) || (driver_inputs->CC_ACCEL_SWITCH_2.LAST_STATUS == TRUE))
              { /* CC_ACCEL_SWITCH_2 *//* PRQA S 715 */
                 /* date: 2018-03-22, reviewer: Ravi kiran Gurrala (uidn6378), reason: Nested control structures exceeds 15, not safety critical */
                if(SWITCH_HOLD_REPEAT(&driver_inputs->CC_ACCEL_SWITCH_2, TRUE, TRUE, cc_start_repeat_fun_cycles, cc_repeat_fun_cycles) == SWITCH_STATE_ON)
                {
				   /* No Actual speed should be taken if Resume/+ pressed during override (ARS410VA10 custom)
                  if(
                    (driver_requests->DRIVER_REQUEST_STATUS.ACTUAL_SPEED_TAKEN_OVERRIDE == FALSE)
                    && 
                    (driver_requests->DRIVER_REQUEST_STATUS.OVERRIDE_WHILE_ENGAGEMENT == FALSE)
                    &&
                    ((driver_requests->SPEEDOMETER_VEHICLE_SPEED_OFFSET/Speedo_speed_s) > (sint16)driver_requests->CC_SETSPEED)
                    )
                  {
                    driver_requests->DRIVER_REQUEST_STATUS.ACTUAL_SPEED_TAKEN_OVERRIDE = TRUE;
                    driver_requests->DRIVER_OPERATIONS.CC_TAKE_ACTUAL_SPEED = TRUE; 
                  }
                  else
                  {*/
                    driver_requests->DRIVER_OPERATIONS.CC_INCREASE_SET_SPEED = TRUE;
                    driver_requests->DRIVER_REQUEST_STATUS.TIMED_INCREMENT = TRUE;
                  /*}*/
                }
                t_switch_falling_edge = SWITCH_FALLING_EDGE(&driver_inputs->CC_ACCEL_SWITCH_2, TRUE);
                if((driver_inputs->CC_ACCEL_SWITCH_2.DURATION_TIME_ACTIVE < cc_start_repeat_fun_cycles)
                  &&(t_switch_falling_edge == SWITCH_STATE_ON))
                {
				   /* No Actual speed should be taken if Resume/+ pressed during override (ARS410VA10 custom)
                  if(
                    (driver_requests->DRIVER_REQUEST_STATUS.ACTUAL_SPEED_TAKEN_OVERRIDE == FALSE)
                    &&
                    (driver_requests->DRIVER_REQUEST_STATUS.OVERRIDE_WHILE_ENGAGEMENT == FALSE)
                    &&
                    ((driver_requests->SPEEDOMETER_VEHICLE_SPEED_OFFSET/Speedo_speed_s) > (sint16)driver_requests->CC_SETSPEED)
                    )
                  {
                    driver_requests->DRIVER_REQUEST_STATUS.ACTUAL_SPEED_TAKEN_OVERRIDE = TRUE;
                    driver_requests->DRIVER_OPERATIONS.CC_TAKE_ACTUAL_SPEED = TRUE;
                  }
                  else
                  {*/
                    driver_requests->DRIVER_OPERATIONS.CC_INCREASE_SET_SPEED = TRUE;
                  /*}*/
                }
              } /* End CC_ACCEL_SWITCH_2 */
#endif /*CFG_FCT_CC_USE_ACCEL_DECEL_MODE*/
              else if((driver_inputs->CC_RESUME_SWITCH.AKT_STATUS == TRUE) || (driver_inputs->CC_RESUME_SWITCH.LAST_STATUS == TRUE))/* PRQA S 715 */
              /* date: 2018-04-18, reviewer: Ravi kiran Gurrala (uidn6378), reason: Nested control structures exceeds 15, not safety critical */
              {   /* CC_RESUME_SWITCH */

                t_switch_hold = SWITCH_HOLD_REPEAT(&driver_inputs->CC_RESUME_SWITCH, TRUE, TRUE, cc_start_repeat_fun_cycles, cc_repeat_fun_cycles);
                if((driver_requests->CONTROL_MODE != Cc_standstill_mode)
                  &&( t_switch_hold == SWITCH_STATE_ON))
                {
                  if(
                    (driver_requests->DRIVER_REQUEST_STATUS.ACTUAL_SPEED_TAKEN_OVERRIDE == FALSE) 
                    && 
                    (driver_requests->DRIVER_REQUEST_STATUS.OVERRIDE_WHILE_ENGAGEMENT == FALSE) 
                    &&
                    ((driver_requests->SPEEDOMETER_VEHICLE_SPEED_OFFSET/Speedo_speed_s) > (sint16)driver_requests->CC_SETSPEED)
                    )
                  {
                    driver_requests->DRIVER_REQUEST_STATUS.ACTUAL_SPEED_TAKEN_OVERRIDE = TRUE;
                    driver_requests->DRIVER_OPERATIONS.CC_TAKE_ACTUAL_SPEED = TRUE; 
                  }
                  else
                  { /* Resume switch used in place of Accel_Switch_1 */
                    driver_requests->DRIVER_OPERATIONS.CC_INCREASE_SET_SPEED = TRUE;
                    driver_requests->DRIVER_REQUEST_STATUS.TIMED_INCREMENT = TRUE;
                    driver_requests->DRIVER_OPERATIONS.SPEED_STEP_1 = TRUE;
                  }
                }

                /*if(SWITCH_RISING_EDGE(&driver_inputs->CC_RESUME_SWITCH, TRUE) == SWITCH_STATE_ON)
                {
                  if((das_input->LODM_STAT.STANDSTILL == FALSE)
                    &&
                    (driver_requests->DRIVER_REQUEST_STATUS.ACTUAL_SPEED_TAKEN_OVERRIDE == FALSE) 
                    && 
                    (driver_requests->DRIVER_REQUEST_STATUS.OVERRIDE_WHILE_ENGAGEMENT == FALSE) 
                    &&
                    ((driver_requests->SPEEDOMETER_VEHICLE_SPEED_OFFSET/Speedo_speed_s) > (sint16)driver_requests->CC_SETSPEED)
                    )
                  {
                    driver_requests->DRIVER_REQUEST_STATUS.ACTUAL_SPEED_TAKEN_OVERRIDE = TRUE;
                    driver_requests->DRIVER_OPERATIONS.CC_TAKE_ACTUAL_SPEED = TRUE; 
                  }
                  else
                  {
                    if(driver_requests->CONTROL_MODE != Cc_standstill_mode) 
                    {
                      driver_requests->DRIVER_OPERATIONS.CC_RESUME_SET_SPEED = TRUE;
                    }
                  }
                } */
                /* Use of resume button in place of Accel_switch_1 */
                t_switch_falling_edge = SWITCH_FALLING_EDGE(&driver_inputs->CC_RESUME_SWITCH, TRUE);
                if( (driver_inputs->CC_RESUME_SWITCH.DURATION_TIME_ACTIVE < cc_start_repeat_fun_cycles)
                  && (driver_inputs->CC_ACCEL_SWITCH_2.DURATION_TIME_INACTIVE > cc_start_repeat_fun_cycles)
                  && (driver_inputs->CC_ACCEL_SWITCH_2.AKT_STATUS == FALSE)
                  && (t_switch_falling_edge == SWITCH_STATE_ON))
                {
                  /* Accel2 switch must be inactive */
                  if(
                    (driver_requests->DRIVER_REQUEST_STATUS.ACTUAL_SPEED_TAKEN_OVERRIDE == FALSE) 
                    && 
                    (driver_requests->DRIVER_REQUEST_STATUS.OVERRIDE_WHILE_ENGAGEMENT == FALSE) 
                    &&
                    ((driver_requests->SPEEDOMETER_VEHICLE_SPEED_OFFSET/Speedo_speed_s) > (sint16)driver_requests->CC_SETSPEED)
                    )
                  {
                    driver_requests->DRIVER_REQUEST_STATUS.ACTUAL_SPEED_TAKEN_OVERRIDE = TRUE;
                    driver_requests->DRIVER_OPERATIONS.CC_TAKE_ACTUAL_SPEED = TRUE; 
                  }
                  else
                  {
                    driver_requests->DRIVER_OPERATIONS.CC_INCREASE_SET_SPEED = TRUE;
                    driver_requests->DRIVER_OPERATIONS.SPEED_STEP_1 = TRUE;
                  }
                }
              } /* End CC_RESUME_SWITCH */
              else if ((driver_inputs->CC_SET_SWITCH.AKT_STATUS == TRUE) || (driver_inputs->CC_SET_SWITCH.LAST_STATUS == TRUE))
              { /* CC_SET_SWITCH */
                t_switch_falling_edge = SWITCH_FALLING_EDGE(&driver_inputs->CC_SET_SWITCH, TRUE);
                if( 
					// Allow long press Set switch in Override (ARS410VA10 custom)
					/*
					(driver_inputs->CC_SET_SWITCH.DURATION_TIME_ACTIVE < cc_start_repeat_fun_cycles)
					&&
					*/
					(driver_inputs->CC_DECEL_SWITCH_2.DURATION_TIME_INACTIVE > cc_start_repeat_fun_cycles)
					&&
					(driver_inputs->CC_DECEL_SWITCH_2.AKT_STATUS == FALSE)
					&&
					(t_switch_falling_edge == SWITCH_STATE_ON))
                {
                  /* Decel2 switch must be inactive */
                  /* Leads to setspeed increase (because in override) even though Decel is pressed */
                  if(
                    (driver_requests->DRIVER_REQUEST_STATUS.ACTUAL_SPEED_TAKEN_OVERRIDE == FALSE)/* PRQA S 715 */
                    /* date: 2018-03-22, reviewer: Ravi kiran Gurrala (uidn6378), reason: Nested control structures exceeds 15, not safety critical */
                    && 
                    (driver_requests->DRIVER_REQUEST_STATUS.OVERRIDE_WHILE_ENGAGEMENT == FALSE) 
                   /* No Set speed decrease in Override state (ARS410VA10 custom)
				    &&
                    ((driver_requests->SPEEDOMETER_VEHICLE_SPEED_OFFSET/Speedo_speed_s) > (sint16)(driver_requests->CC_SETSPEED))
					*/
                    )
                  {
                    driver_requests->DRIVER_REQUEST_STATUS.ACTUAL_SPEED_TAKEN_OVERRIDE = TRUE;
                    driver_requests->DRIVER_OPERATIONS.CC_TAKE_ACTUAL_SPEED = TRUE; 
                  }
                  else 
                  {  
                   /* No Set speed decrease in Override state (ARS410VA10 custom)
					driver_requests->DRIVER_OPERATIONS.CC_DECREASE_SET_SPEED = TRUE;
                    driver_requests->DRIVER_OPERATIONS.SPEED_STEP_1 = TRUE;
					*/
                  }
                }
              } /* End CC_SET_SWITCH */
              else
              {
                /* No buttons active, do nothing */
              }
            } /* End of Override state */

            break;
          } /* End of conditions for engaged, active, override states */
          default:
          /* Disengaged state */
          {

            /*resume switch pressed once while disengaged*/
            if(SWITCH_FALLING_EDGE(&driver_inputs->CC_RESUME_SWITCH, TRUE) == SWITCH_STATE_ON)
            {
					
				if(b_flag_igon == TRUE)
				{
					driver_requests->DRIVER_OPERATIONS.CC_TAKE_ACTUAL_SPEED = TRUE;
					driver_requests->DRIVER_OPERATIONS.CC_RESUME_SET_SPEED = TRUE;
				}
				else
				{
					 driver_requests->DRIVER_OPERATIONS.CC_RESUME_SET_SPEED = TRUE;
				}
//            driver_requests->DRIVER_REQUEST_STATUS.OVERRIDE_WHILE_ENGAGEMENT = TRUE;
            }
            /*decel switch pressed while disengaged*/
            else if (SWITCH_FALLING_EDGE(&driver_inputs->CC_DECEL_SWITCH_1, TRUE) == SWITCH_STATE_ON) 
            {
              driver_requests->DRIVER_OPERATIONS.CC_TAKE_ACTUAL_SPEED = TRUE;
              driver_requests->DRIVER_REQUEST_STATUS.ACTUAL_SPEED_TAKEN_SET = TRUE;
//            driver_requests->DRIVER_REQUEST_STATUS.OVERRIDE_WHILE_ENGAGEMENT = TRUE;
            }
            else if (SWITCH_FALLING_EDGE(&driver_inputs->CC_DECEL_SWITCH_2, TRUE) == SWITCH_STATE_ON) 
            {
              driver_requests->DRIVER_OPERATIONS.CC_TAKE_ACTUAL_SPEED = TRUE;
              driver_requests->DRIVER_REQUEST_STATUS.ACTUAL_SPEED_TAKEN_SET = TRUE;
//            driver_requests->DRIVER_REQUEST_STATUS.OVERRIDE_WHILE_ENGAGEMENT = TRUE;
            }
            else if (SWITCH_FALLING_EDGE(&driver_inputs->CC_SET_SWITCH, TRUE) == SWITCH_STATE_ON) 
            {
              driver_requests->DRIVER_OPERATIONS.CC_TAKE_ACTUAL_SPEED = TRUE;
              driver_requests->DRIVER_REQUEST_STATUS.ACTUAL_SPEED_TAKEN_SET = TRUE;
//            driver_requests->DRIVER_REQUEST_STATUS.OVERRIDE_WHILE_ENGAGEMENT = TRUE;
            }
            /*accel switch pressed while disengaged*/
            else if (SWITCH_FALLING_EDGE(&driver_inputs->CC_ACCEL_SWITCH_1, TRUE) == SWITCH_STATE_ON)
            {
              driver_requests->DRIVER_OPERATIONS.CC_TAKE_ACTUAL_SPEED = TRUE;
              driver_requests->DRIVER_REQUEST_STATUS.ACTUAL_SPEED_TAKEN_SET = TRUE;
//            driver_requests->DRIVER_REQUEST_STATUS.OVERRIDE_WHILE_ENGAGEMENT = TRUE;
            }
            else if (SWITCH_FALLING_EDGE(&driver_inputs->CC_ACCEL_SWITCH_2, TRUE) == SWITCH_STATE_ON)// PRQA S 2004 
            /* date: 2018-03-22, reviewer: Ravi Kiran Gurrala, reason: conditions are checking in if and elseif, else is not required*/
            {/* PRQA S 715 */
             /* date: 2018-03-22, reviewer: Ravi kiran Gurrala (uidn6378), reason: Nested control structures exceeds 15, not safety critical */
              driver_requests->DRIVER_OPERATIONS.CC_TAKE_ACTUAL_SPEED = TRUE;
              driver_requests->DRIVER_REQUEST_STATUS.ACTUAL_SPEED_TAKEN_SET = TRUE;
              driver_requests->DRIVER_REQUEST_STATUS.OVERRIDE_WHILE_ENGAGEMENT = TRUE;
            }
            break;
          } /* End Disengaged state */
        } /* Switch(Control_State) */

#endif /* CFG_ACC_LEVER_INPUT */


#if (FCT_CFG_FSRACC)

#if (!CFG_FCT_USE_TWICE_CONFIRMATION_FOR_DRIVE_OFF)
#if(!CFG_ACC_LEVER_INPUT)
        if ((acc_output->SITUATION_CLASS.SITUATION != Acc_sit_class_stop) && (input->pENGINE_ECU_INPUT->ACCSTAT == ACCSTAT_ACTIVE_OR_OVERRIDE))
        {
          /* When driver pressses the resume switch the 5 second counter allowing automatic
          drive off starts counting from zero again (prolonging the time allowed for drive off) */
          driver_requests->DRIVE_OFF_TIME = 0u;
        }
        else
        {
          /* When driver did not press the resume switch, then increase the drive off timer to
          count the number of miliseconds ellapsed, until Cc_drive_off_smooth_time is reached */
          if (driver_requests->DRIVE_OFF_TIME < Cc_drive_off_smooth_time)
          {
            driver_requests->DRIVE_OFF_TIME += cycle_time;
          }
          else
          {
            driver_requests->DRIVE_OFF_TIME = Cc_drive_off_smooth_time;
          }
        }
#endif /* !CFG_ACC_LEVER_INPUT */ 
#endif /* !CFG_FCT_USE_TWICE_CONFIRMATION_FOR_DRIVE_OFF */
#endif /*FCT_CFG_FSRACC*/

#if (!CFG_ACC_LEVER_INPUT)
        if((acc_output->SITUATION_CLASS.SITUATION != Acc_sit_class_stop) &&
            (input->pENGINE_ECU_INPUT->ACCSTAT != ACCSTAT_ACTIVE_OR_OVERRIDE))
        {
          driver_requests->DRIVER_OPERATIONS.CC_RESUME_SET_SPEED = TRUE;
          driver_requests->DRIVER_REQUEST_STATUS.OVERRIDE_WHILE_ENGAGEMENT = TRUE;
        }
#endif

#if (!CFG_FCT_USE_TWICE_CONFIRMATION_FOR_DRIVE_OFF)
#if (CFG_ACC_LEVER_INPUT)
        if (driver_inputs->CC_ACCEL_PEDAL == TRUE)
#else
        if ((acc_output->SITUATION_CLASS.SITUATION != Acc_sit_class_stop) && input->pENGINE_ECU_INPUT->ACCSTAT == ACCSTAT_ACTIVE_OR_OVERRIDE)
#endif
        {
#if (FCT_CFG_FSRACC)
          if ((driver_requests->CONTROL_MODE == Cc_standstill_mode) && (driver_requests->ENGAGEMENT_CONDITIONS.DRIVE_OFF_POSSIBLE == TRUE))
          {
            driver_requests->DRIVER_OPERATIONS.DRIVE_OFF_CONFIRM = TRUE;
          }
#endif
        }
#endif /* !CFG_FCT_USE_TWICE_CONFIRMATION_FOR_DRIVE_OFF */

#if (CFG_ACC_LEVER_INPUT)
      }
    }
  }

  if(
     (driver_controls->SELECTED_FUNCTION_LAST_CYCLE != driver_controls->SELECTED_FUNCTION)
#if (CFG_FCT_CC_RST_SETSPEED_DECEL_ONLY)
     ||
     ((driver_requests->CONTROL_STATE_LAST_CYCLE == Cc_cc_decel_only) && (driver_requests->CONTROL_STATE != Cc_cc_decel_only))
#endif
    )
  {
    driver_requests->DRIVER_OPERATIONS.RESET_SETSPEED = TRUE;
  }

  /* Set Counter for time after transition to override state.
    After sufficient time is over, OVERRIDE_WHILE_ENGAGEMENT=0 and buttons can be
    interpreted again in override mode. */
  if (driver_requests->CONTROL_STATE != Cc_cc_override) 
  {
    if(
       (driver_requests->DRIVER_OPERATIONS.CC_TAKE_ACTUAL_SPEED == FALSE) 
       && 
       (driver_requests->DRIVER_OPERATIONS.CC_RESUME_SET_SPEED == FALSE) 
       && 
       (driver_requests->CONTROL_STATE != Cc_cc_engage)
      )
    {
      if(cc_status->CC_ENGAGE_OVERRIDE_COUNTER > 0u)
      {
        cc_status->CC_ENGAGE_OVERRIDE_COUNTER--;
      }
      else
      {
        driver_requests->DRIVER_REQUEST_STATUS.OVERRIDE_WHILE_ENGAGEMENT = FALSE;
      }
    }
    else
    {
      cc_status->CC_ENGAGE_OVERRIDE_COUNTER = (uint16)(Cc_engage_override_time / cycle_time);
    }
  }
  else
  {
    cc_status->CC_ENGAGE_OVERRIDE_COUNTER = (uint16)(Cc_engage_override_time / cycle_time);
  }

  if((uint8)input->VEHICLE_STATUS.SPEED_UNIT_KMH != cc_status->CC_SPEED_UNIT_LAST_CYCLE)
  {
    driver_requests->DRIVER_OPERATIONS.SWITCH_SPEED_UNIT = TRUE;
  }
#endif /* CFG_ACC_LEVER_INPUT */

  /*copy last cycle operations*/
  driver_requests->DRIVER_OPERATIONS_LAST_CYCLE = driver_requests->DRIVER_OPERATIONS;
  driver_controls->SELECTED_FUNCTION_LAST_CYCLE = driver_controls->SELECTED_FUNCTION;


}// PRQA S 7012, 7004
/* date: 2018-03-23, reviewer: Ravi Kiran Gurrala, reason: Cyclomatic complexity. Not safety critical */

/*****************************************************************************
  FUNCTION NAME:  KMC_v_SignalInhibitionCheck */ /*!

  @description    Process all data that inhibits the DAS for a specific customer.

@startuml
Start
Partition KMC_v_SignalInhibitionCheck(){
: Start Signal Inhibition Check;
: Check signal status of ACCleverInput and LongCtrlInput ports;
: Check Signal status of Vehicle Motion State and Vehile Velocity from VDY;
: Set Inhibition Flag based on above checks;
If (Inhibition flag is True or LOPC opmode is not running) Then (True)
: set SignalCheckfail to true;
endif
}
End
@enduml


  @param          pVehDyn
  @param          pAccLever
  @param          pLongCtrlResp
  @param          cc_input_data
  @param          Inhibit_nr
  @return         void

*****************************************************************************/
static void KMC_v_SignalInhibitionCheck(const VehDyn_t * pVehDyn,
#if(CFG_ACC_LEVER_INPUT)
                                        const AccLeverInput_t * pAccLever,
#endif
                                        const LongCtrlInput_t * pLongCtrlResp,
                                        cc_input_data_t* cc_input_data,
                                        uint16* Inhibit_nr)
{

  fct_inhibit_t LocalInhibitionBuffer;
  boolean b_KMCInhibition;

  /*! Start Signal Inhibition Check */
  KMC_v_InhibitStartCycle(&LocalInhibitionBuffer);
  *Inhibit_nr = 0u;

  /* Check ACC Lever Input port */
#if (CFG_ACC_LEVER_INPUT)
  KMC_v_InhibitAddInhibition(
    &LocalInhibitionBuffer, 
    (uint8)(pAccLever->sSigHeader.eSigStatus != AL_SIG_STATE_OK),
    Fct_inhibit_FctACC | Fct_inhibit_FctCC |Fct_inhibit_DspTmpNotAv
    );
#endif

  /* Check longitudinal controller response input port */
  KMC_v_InhibitAddInhibition(
    &LocalInhibitionBuffer,
    (uint8)(pLongCtrlResp->sSigHeader.eSigStatus != AL_SIG_STATE_OK),
    Fct_inhibit_FctACC | Fct_inhibit_FctCC |Fct_inhibit_DspTmpNotAv
    );

  /* Check state of vehicle speed from VDY */
  KMC_v_InhibitAddInhibition(
    &LocalInhibitionBuffer, 
    (uint8)
#if (VDY_VEH_DYN_INTFVER >= 0x20)   // 0x20 -> 18
    (VDY_GET_IO_STATE(VDY_SOUT_POS_VELOCITY, pVehDyn->State) != VDY_IO_STATE_VALID),
#else
    (VDY_GET_IO_STATE(VDY_SOUT_POS_VEL, pVehDyn->State) != VDY_IO_STATE_VALID),
#endif
    Fct_inhibit_FctCC  |Fct_inhibit_DspTmpNotAv
    );

  /* Check state of vehicle motion state from VDY */
  KMC_v_InhibitAddInhibition(
    &LocalInhibitionBuffer, 
    (uint8)
#if (VDY_VEH_DYN_INTFVER >= 0x20)   // 0x20 -> 18
    (VDY_GET_IO_STATE(VDY_SOUT_POS_MOTIONSTATE, pVehDyn->State) != VDY_IO_STATE_VALID),
#else
    (VDY_GET_IO_STATE(VDY_SOUT_POS_MSTAT, pVehDyn->State) != VDY_IO_STATE_VALID),
#endif
    Fct_inhibit_FctCC  |Fct_inhibit_DspTmpNotAv
    );

  *Inhibit_nr = LocalInhibitionBuffer.INHiBIT_NR;
  KMC_v_InhibitFinishCycle(&LocalInhibitionBuffer, &INHIBIT_BUFFER, Fct_inhibit_task_LC_EXEC);

  b_KMCInhibition = KMC_u_InhibitGetInhibition(LocalInhibitionBuffer, Fct_inhibit_FctCC | Fct_inhibit_FctACC);
  if (
      (LOPC_STATIC_MEMORY.LOPC_Frame.eLOPCOpMode != FCT_MOD_RUNNING) ||
      (b_KMCInhibition == TRUE)
     )
  {
    cc_input_data->INHIBIT.CC_SIGNALCHECK_FAIL = TRUE;
  }
  else
  {
    cc_input_data->INHIBIT.CC_SIGNALCHECK_FAIL = FALSE;
  }

  _PARAM_UNUSED(pLongCtrlResp);
#ifdef FCT_SIM_EXT
  /* Signal check removed for carmaker simulation */
  cc_input_data->INHIBIT.CC_SIGNALCHECK_FAIL = FALSE;
#endif
}


/*****************************************************************************
  @fn             KMC_v_InhibitionCheck */ /*!

  @brief          Process all data that inhibits the DAS for a specific customer.
  @description    Process all data that inhibits the DAS for a specific customer.

@startuml
Start
	Partition KMC_v_InhibitionCheck(){
		: Update counter for ABS & ESP & TCS active;
		
		: Receive error information from RTE;
		: Reset SetSpeed to 0 if permanent error occurs;
		
		: Determine SHUTDOWN_SIGNAL;
		: KMC_v_InhibitionCheck_CC_INHIBIT;

		: KMC_v_InhibitionCheck_No_Ramp;

		: KMC_v_InhibitionCheck_Rapid_Ramp;

		: KMC_v_InhibitionCheck_Ramp;

		: KMC_v_InhibitionCheck_Inhibit_Engagement;

		: KMC_v_InhibitionCheck_Soft_Off_Condition;
		
		If (CDDActive && soft off condition satisfied) then (true)
			: b_BOM_Enter_Conditions = TRUE;
		Else (false)
			: b_BOM_Enter_Conditions = FALSE;
		Endif
	}
end
@enduml

  @param[in,out]  cycle_time
  @param[in,out]  pVehDyn
  @param[in,out]  pLongCtrlResp
  @param[in,out]  das_input_data
  @param[in,out]  das_input_data_last_cycle
  @param[in,out]  driver_controls
  @param[in,out]  acc_output
  @param[in,out]  input
  @param[in,out]  error_data
  @param[in,out]  cc_status
  @return         void

*****************************************************************************/
static void KMC_v_InhibitionCheck(const times_t cycle_time,
                                  const VehDyn_t* pVehDyn,
                                  const LongCtrlInput_t* pLongCtrlResp,
                                  const cart_das_input_data_t* das_input_data,
                                  const cart_das_input_data_t* das_input_data_last_cycle,
                                  const cc_driver_controls_t *driver_controls,
#if (FCT_CFG_ACC_HEADWAY_PLANNER)
                                  const acc_output_data_t* acc_output,
#endif
								  const cc_driver_inputs_t *driver_inputs,
                                  cc_input_data_t* input, 
                                  cc_error_data_t *error_data,
                                  cc_status_t *cc_status,
								  cc_driver_information_t* driver_information)
{
	
	SWITCH_SET_COND_COUNTER(das_input_data->CHASSIS_STAT.ABS_ACT, Cc_abs_act_inhibit_time, cycle_time, &cc_status->CC_ABS_ACT_CNT, 
							cc_status->CC_DRIVER_REQUESTS.DRIVER_REQUEST_STATUS.SELECTED_FUNCTION_ACTIVE);
	SWITCH_SET_COND_COUNTER(das_input_data->CHASSIS_STAT.ESP_ACT, Cc_esp_act_inhibit_time, cycle_time, &cc_status->CC_ESP_ACT_CNT, 
							cc_status->CC_DRIVER_REQUESTS.DRIVER_REQUEST_STATUS.SELECTED_FUNCTION_ACTIVE);
	SWITCH_SET_COND_COUNTER(das_input_data->CHASSIS_STAT.TCS_ACT, Cc_tcs_act_inhibit_time, cycle_time, &cc_status->CC_TCS_ACT_CNT, 
							cc_status->CC_DRIVER_REQUESTS.DRIVER_REQUEST_STATUS.SELECTED_FUNCTION_ACTIVE);

	if(pLongCtrlResp->Custom.CustomInput.ACCFailureMode == ACCFailureMode_PermError)
	{
		error_data->REPORTED_ERROR = Cc_error_service;
	}
	else if (pLongCtrlResp->Custom.CustomInput.ACCFailureMode == ACCFailureMode_TempError)
	{
		error_data->REPORTED_ERROR = Cc_temp_unavailable;		
	}
	else
	{
		error_data->REPORTED_ERROR = Cc_no_error;
	}

    if(error_data->REPORTED_ERROR == Cc_error_service)
    {
		cc_status->CC_DRIVER_REQUESTS.CC_SETSPEED = (setspeed_t)0; /* reset set speed if ignition switch on/off needed */
    }	


	// Never used
	if	(
			(
				((error_data->CC_INHIBIT == TRUE) && (driver_controls->SELECTED_FUNCTION == Cc_function_cc))
				||
				((error_data->LIM_INHIBIT == TRUE) && (driver_controls->SELECTED_FUNCTION == Cc_function_lim))
			)
			&&
#if (CFG_ACC_LEVER_INPUT)
			(
				(cc_status->CC_DRIVER_REQUESTS.CONTROL_STATE == Cc_cc_active)
				||
				(cc_status->CC_DRIVER_REQUESTS.CONTROL_STATE == Cc_cc_engage)
				||
				(cc_status->CC_DRIVER_REQUESTS.CONTROL_STATE == Cc_cc_override)
				||
				(cc_status->CC_DRIVER_REQUESTS.CONTROL_STATE == Cc_lim_active)
				||
				(cc_status->CC_DRIVER_REQUESTS.CONTROL_STATE == Cc_lim_override)
				||
				(cc_status->CC_DRIVER_REQUESTS.CONTROL_STATE == Cc_plim_active)
			)
#else
     /* Control state cc_engage not available from EngineEcuInput directly */
     (input->pENGINE_ECU_INPUT->ACCSTAT == ACCSTAT_ACTIVE_OR_OVERRIDE)
#endif
		)
	{ /* Saved command to shutdown system because of CC_INHIBIT(Error) when ACC was being used */
		error_data->SHUTDOWN_SIGNAL = TRUE;
	}
	else
	{
		error_data->SHUTDOWN_SIGNAL = FALSE;
	}

	KMC_v_InhibitionCheck_CC_INHIBIT(cycle_time,pVehDyn,pLongCtrlResp,das_input_data,das_input_data_last_cycle,driver_controls,acc_output,input,error_data,cc_status);

	KMC_v_InhibitionCheck_No_Ramp(cycle_time,pVehDyn,pLongCtrlResp,das_input_data,das_input_data_last_cycle,driver_controls,acc_output,input,error_data,cc_status);

	KMC_v_InhibitionCheck_Rapid_Ramp(cycle_time,pVehDyn,pLongCtrlResp,das_input_data,das_input_data_last_cycle,driver_controls,acc_output,input,error_data,cc_status);

	KMC_v_InhibitionCheck_Ramp(cycle_time,pVehDyn,pLongCtrlResp,das_input_data,das_input_data_last_cycle,driver_controls,acc_output,input,error_data,cc_status);

	KMC_v_InhibitionCheck_Inhibit_Engagement(cycle_time,pVehDyn,pLongCtrlResp,das_input_data,das_input_data_last_cycle,driver_controls,acc_output,input,error_data,cc_status);

	KMC_v_InhibitionCheck_Soft_Off_Condition(cycle_time,pVehDyn,pLongCtrlResp,das_input_data,das_input_data_last_cycle,driver_controls,acc_output,driver_inputs,input,error_data,cc_status,driver_information);

#if (CN_ACCSM_BOM)
	/*go to decel only*/
	if	(
			(pLongCtrlResp->Custom.CustomInput.CDDActive == TRUE)
			&&
			(b_Soft_Off_Condition == TRUE)
		)
	{
		b_BOM_Enter_Conditions = TRUE;
	}
	else
	{
		b_BOM_Enter_Conditions = FALSE;
	}
#endif

	_PARAM_UNUSED(das_input_data_last_cycle);
}// PRQA S 7012
/* date: 2018-03-23, reviewer: Ravi Kiran Gurrala, reason: Not safety critical */

/*****************************************************************************
  @fn             KMC_v_InhibitionCheck_CC_INHIBIT */ /*!

  @brief          Determine inhibition condition: CC_INHIBIT.
  @description    Determine inhibition condition: CC_INHIBIT.

@startuml
Start
	Partition KMC_v_InhibitionCheck_CC_INHIBIT(){
		:Determine InhibitReason_CC_INHIBIT with multiple condtions checking;
		If (No InhibitReason satisfied) Then (true)
			: CC_INHIBIT is set as false;
		Else (false)
			: CC_INHIBIT is set as true;
		endif
	}
end
@enduml

  @param[in,out]  cycle_time
  @param[in,out]  pVehDyn
  @param[in,out]  pLongCtrlResp
  @param[in,out]  das_input_data
  @param[in,out]  das_input_data_last_cycle
  @param[in,out]  driver_controls
  @param[in,out]  acc_output
  @param[in,out]  input
  @param[in,out]  error_data
  @param[in,out]  cc_status
  @return         void

*****************************************************************************/
static void KMC_v_InhibitionCheck_CC_INHIBIT(const times_t cycle_time,
                                            const VehDyn_t* pVehDyn,
                                            const LongCtrlInput_t* pLongCtrlResp,
                                            const cart_das_input_data_t* das_input_data,
                                            const cart_das_input_data_t* das_input_data_last_cycle,
                                            const cc_driver_controls_t *driver_controls,
#if (FCT_CFG_ACC_HEADWAY_PLANNER)
                                            const acc_output_data_t* acc_output,
#endif
                                            cc_input_data_t* input, 
                                            cc_error_data_t *error_data,
                                            cc_status_t *cc_status)
{
	InhibitReason_CC_INHIBIT = 0U;
	if (das_input_data->LODM_STAT.DAS_ENABLE == FALSE)
	{
		InhibitReason_CC_INHIBIT |= INHIBITREASON_CC_INHIBIT_DAS_ENABLE;
	}
	
	if (pLongCtrlResp->Custom.CustomInput.PowerBatteryFail == TRUE)
	{
		InhibitReason_CC_INHIBIT |= INHIBITREASON_CC_INHIBIT_POWER_BATTERY_FAIL;
	}
	
	if (InhibitReason_CC_INHIBIT == 0)	
	{
		error_data->CC_INHIBIT = FALSE;
		error_data->SHUTDOWN_RAMP = FALSE;
	}
	else
	{
		error_data->CC_INHIBIT = TRUE; /* Buttons will no longer be used. ACC to be deactivated */
	}

	_PARAM_UNUSED(cycle_time);
	_PARAM_UNUSED(pVehDyn);
	_PARAM_UNUSED(pLongCtrlResp);
	_PARAM_UNUSED(das_input_data_last_cycle);
	_PARAM_UNUSED(driver_controls);
	_PARAM_UNUSED(acc_output);
	_PARAM_UNUSED(input);
	_PARAM_UNUSED(cc_status);
}

/*****************************************************************************
  @fn             KMC_v_InhibitionCheck_No_Ramp */ /*!

  @brief          Determine inhibition condition: CC_DISENGAGEMENT_NO_RAMP.
  @description    Determine inhibition condition: CC_DISENGAGEMENT_NO_RAMP.

@startuml
Start
	Partition KMC_v_InhibitionCheck_No_Ramp(){
		:Determine InhibitReason_No_Ramp with multiple condtions checking;
		If (No InhibitReason satisfied) Then (true)
			: CC_DISENGAGEMENT_NO_RAMP is set as false;
		Else (false)
			: CC_DISENGAGEMENT_NO_RAMP is set as true;
		endif
	}
end
@enduml

  @param[in,out]  cycle_time
  @param[in,out]  pVehDyn
  @param[in,out]  pLongCtrlResp
  @param[in,out]  das_input_data
  @param[in,out]  das_input_data_last_cycle
  @param[in,out]  driver_controls
  @param[in,out]  acc_output
  @param[in,out]  input
  @param[in,out]  error_data
  @param[in,out]  cc_status
  @return         void

*****************************************************************************/
static void KMC_v_InhibitionCheck_No_Ramp(const times_t cycle_time,
		                                  const VehDyn_t* pVehDyn,
		                                  const LongCtrlInput_t* pLongCtrlResp,
		                                  const cart_das_input_data_t* das_input_data,
		                                  const cart_das_input_data_t* das_input_data_last_cycle,
		                                  const cc_driver_controls_t *driver_controls,
#if (FCT_CFG_ACC_HEADWAY_PLANNER)
		                                  const acc_output_data_t* acc_output,
#endif
		                                  cc_input_data_t* input, 
		                                  cc_error_data_t *error_data,
		                                  cc_status_t *cc_status)
{
	InhibitReason_No_Ramp = 0U;
	
	if (input->INHIBIT.CC_SIGNALCHECK_FAIL == TRUE)
	{
		InhibitReason_No_Ramp |= INHIBITREASON_NO_RAMP_CC_SIGNALCHECK_FAIL;
	}
	
#if (FCT_CFG_ACC_HEADWAY_PLANNER)
	if (acc_output->ACC_OUTPUT_STATUS.INHIBITED == TRUE)
	{
		InhibitReason_No_Ramp |= INHIBITREASON_NO_RAMP_INHIBIED;
	}
#endif

	if (error_data->CC_INHIBIT == TRUE)
	{
		InhibitReason_No_Ramp |= INHIBITREASON_NO_RAMP_CC_INHIBIT;
	}
	
	if (error_data->REPORTED_ERROR != Cc_no_error)
	{
		InhibitReason_No_Ramp |= INHIBITREASON_NO_RAMP_REPORTED_ERROR;
	}
	
	if (das_input_data->CHASSIS_STAT.PB_ACT == TRUE)
	{
		InhibitReason_No_Ramp |= INHIBITREASON_NO_RAMP_PARK_BRAKE_ACTIVE;
	}
	
	if	(
			(
				(das_input_data->BRAKE_STAT.PEDAL_INIT_TRAVEL == TRUE)
				||
				(das_input_data->LODM_STAT.OVERRIDE_DECEL == TRUE)
			)
			&&
			(das_input_data->LODM_STAT.STANDSTILL == FALSE)
		)
	{
		InhibitReason_No_Ramp |= INHIBITREASON_NO_RAMP_DRIVER_BRAKE_WHEN_EGO_VEHICLE_MOVING;
	}
	
	if (pLongCtrlResp->Custom.CustomInput.ESPOFFStatus == TRUE)
	{
		InhibitReason_No_Ramp |= INHIBITREASON_NO_RAMP_ACTUATOR_OFF;
	}
	
	if (pLongCtrlResp->Custom.CustomInput.CDPActive == TRUE)
	{
		InhibitReason_No_Ramp |= INHIBITREASON_NO_RAMP_CDP_ACTIVE;
	}
	
  	if	(
			(input->SPEEDOMETER_VEHICLE_SPEED > ((speedometer_speed_t)Cc_max_speed_kmh * Speedo_speed_s))
			||
			(Cc_max_speed_kmh == Cc_speed_default_value)
		)
	{
		InhibitReason_No_Ramp |= INHIBITREASON_NO_RAMP_SPEEDOSPEED_GREATER_THAN_MAX_ENGAGE_SPEED;
	}
	
	if (input->SPEEDOMETER_VEHICLE_SPEED < ((speedometer_speed_t)Kmc_acc_fsr_min_v_engage_kmh * Speedo_speed_s))
	{
		InhibitReason_No_Ramp |= INHIBITREASON_NO_RAMP_SPEEDOSPEED_LESS_THAN_MIN_ENGAGE_SPEED;
	}
	
	if (pLongCtrlResp->Custom.CustomInput.AEBActive == TRUE)
	{
		InhibitReason_No_Ramp |= INHIBITREASON_NO_RAMP_AEB_ACTIVE;
	}
	
	if	(
			(ACC_Cancellation_Flag == TRUE)
			&&
			(ACC_State != ACC_STAT_STANDSTILL)  //When not standstill mode, Close target lost( distance smaller than 5m)  ACC_DISPLAY_OBJECT
		)
	{
		InhibitReason_No_Ramp |= INHIBITREASON_NO_RAMP_CLOSE_OBJECT_LOST;
	}
	
	if	(
			(pVehDyn->MotionState.MotState == VDY_LONG_MOT_STATE_MOVE_RWD) // VDY motion state
			&&
			(das_input_data->LODM_STAT.STANDSTILL == FALSE) // input from CAN
			&&
			(pVehDyn->Longitudinal.MotVar.Velocity > 0.28) // VDY ego vehicle speed > 1 kph
		)
	{
		InhibitReason_No_Ramp |= INHIBITREASON_NO_RAMP_EGO_VEHICLE_ROLLING_BACK;
	}

//  Not needed for BD10 project	
//	if (FALSE)
//	{
//		InhibitReason_No_Ramp |= INHIBITREASON_NO_RAMP_TCU_FAIL;
//	}
	
	if	(
			(pLongCtrlResp->Custom.CustomInput.CDDAvail == FALSE)
			||
			(pLongCtrlResp->Custom.CustomInput.VLCAvail == FALSE)
		)
	{
		InhibitReason_No_Ramp |= INHIBITREASON_NO_RAMP_ACTUATOR_FUNCTION_FAIL;
	}

	if ( InhibitReason_No_Ramp == 0)
	{
		input->INHIBIT.CC_DISENGAGEMENT_NO_RAMP = FALSE;	
	}
	else
	{
		input->INHIBIT.CC_DISENGAGEMENT_NO_RAMP = TRUE;
		cc_status->CC_ACCEL_CONTROL_DATA.ACCEL_STATUS.NO_RAMP = TRUE;
	}

	_PARAM_UNUSED(cycle_time);
	_PARAM_UNUSED(das_input_data_last_cycle);
	_PARAM_UNUSED(driver_controls);
	_PARAM_UNUSED(cc_status);
}

/*****************************************************************************
  @fn             KMC_v_InhibitionCheck_Rapid_Ramp */ /*!

  @brief          Determine inhibition condition: CC_DISENGAGEMENT_RAPID_RAMP.
  @description    Determine inhibition condition: CC_DISENGAGEMENT_RAPID_RAMP.

@startuml
Start
	Partition KMC_v_InhibitionCheck_Rapid_Ramp(){
		:Determine InhibitReason_Rapid_Ramp with multiple condtions checking;
		If (No InhibitReason satisfied) Then (true)
			: CC_DISENGAGEMENT_RAPID_RAMP is set as false;
		Else (false)
			: CC_DISENGAGEMENT_RAPID_RAMP is set as true;
		endif
	}
end
@enduml

  @param[in,out]  cycle_time
  @param[in,out]  pVehDyn
  @param[in,out]  pLongCtrlResp
  @param[in,out]  das_input_data
  @param[in,out]  das_input_data_last_cycle
  @param[in,out]  driver_controls
  @param[in,out]  acc_output
  @param[in,out]  input
  @param[in,out]  error_data
  @param[in,out]  cc_status
  @return         void

*****************************************************************************/
static void KMC_v_InhibitionCheck_Rapid_Ramp(const times_t cycle_time,
                                             const VehDyn_t* pVehDyn,
                                             const LongCtrlInput_t* pLongCtrlResp,
                                             const cart_das_input_data_t* das_input_data,
                                             const cart_das_input_data_t* das_input_data_last_cycle,
                                             const cc_driver_controls_t *driver_controls,
#if (FCT_CFG_ACC_HEADWAY_PLANNER)
                                             const acc_output_data_t* acc_output,
#endif
                                             cc_input_data_t* input, 
                                             cc_error_data_t *error_data,
                                             cc_status_t *cc_status)
{
	if	(
			(cc_status->CC_DRIVER_REQUESTS.CONTROL_STATE == Cc_cc_override) 
			&& 
			(Kmc_overridetime_counter > 0)
		)
	{
		Kmc_overridetime_counter --;
	}
	else if(cc_status->CC_DRIVER_REQUESTS.CONTROL_STATE != Cc_cc_override)
	{
		Kmc_overridetime_counter = Kmc_overridetime_counter_C;
	}
	else
	{
		//do nothing
	}

	InhibitReason_Rapid_Ramp = 0U;
	if (
			(cc_status->CC_DRIVER_REQUESTS.CONTROL_STATE == Cc_cc_override)
			&&
			(Kmc_overridetime_counter == 0)
		)
	{
		InhibitReason_Rapid_Ramp |= INHIBITREASON_RAPID_RAMP_OVERRIDE_OVERTIME;
	}

	if	(
			(Kmc_Standstillstate == StandStillState_Deactivating)
			&&
			(das_input_data->LODM_STAT.STANDSTILL == TRUE)
		)
	{
		InhibitReason_Rapid_Ramp |= INHIBITREASON_RAPID_RAMP_STADNSTILL_STATE_OVERTIME;
	}

	if (InhibitReason_Rapid_Ramp == 0)
	{
		input->INHIBIT.CC_DISENGAGEMENT_RAPID_RAMP = FALSE;
	}
	else
	{
		input->INHIBIT.CC_DISENGAGEMENT_RAPID_RAMP = TRUE;
		cc_status->CC_ACCEL_CONTROL_DATA.ACCEL_STATUS.RAPID_RAMP = TRUE;
	}
	_PARAM_UNUSED(cycle_time);
	_PARAM_UNUSED(pVehDyn);
	_PARAM_UNUSED(pLongCtrlResp);
	_PARAM_UNUSED(das_input_data_last_cycle);
	_PARAM_UNUSED(driver_controls);
	_PARAM_UNUSED(acc_output);
	_PARAM_UNUSED(error_data);
}

/*****************************************************************************
  @fn             KMC_v_InhibitionCheck_Ramp */ /*!

  @brief          Determine inhibition condition: CC_DISENGAGEMENT_RAMP.
  @description    Determine inhibition condition: CC_DISENGAGEMENT_RAMP.

@startuml
Start
	Partition KMC_v_InhibitionCheck_Ramp(){
		:Determine InhibitReason_Ramp with multiple condtions checking;
		If (No InhibitReason satisfied) Then (true)
			: CC_DISENGAGEMENT_RAMP is set as false;
		Else (false)
			: CC_DISENGAGEMENT_RAMP is set as true;
		endif
	}
end
@enduml

  @param[in,out]  cycle_time
  @param[in,out]  pVehDyn
  @param[in,out]  pLongCtrlResp
  @param[in,out]  das_input_data
  @param[in,out]  das_input_data_last_cycle
  @param[in,out]  driver_controls
  @param[in,out]  acc_output
  @param[in,out]  input
  @param[in,out]  error_data
  @param[in,out]  cc_status
  @return         void

*****************************************************************************/
static void KMC_v_InhibitionCheck_Ramp(const times_t cycle_time,
                                       const VehDyn_t* pVehDyn,
                                       const LongCtrlInput_t* pLongCtrlResp,
                                       const cart_das_input_data_t* das_input_data,
                                       const cart_das_input_data_t* das_input_data_last_cycle,
                                       const cc_driver_controls_t *driver_controls,
#if (FCT_CFG_ACC_HEADWAY_PLANNER)
                                       const acc_output_data_t* acc_output,
#endif
                                       cc_input_data_t* input, 
                                       cc_error_data_t *error_data,
                                       cc_status_t *cc_status)
{
	InhibitReason_Ramp = 0U;

#if (CN_ACCSM_BOM)
	if	(
			(pLongCtrlResp->Custom.CustomInput.CDDActive == FALSE) //cdd is not active
			&&
			(b_Soft_Off_Condition == TRUE)
		)
	{
		InhibitReason_Ramp |= INHIBITREASON_RAMP_SOFT_OFF_AND_VEHICLE_NOT_DECELERATING;
	}
#else
	if (b_Soft_Off_Condition == TRUE)
	{
		InhibitReason_Ramp |= INHIBITREASON_RAMP_SOFT_OFF;
	}
#endif

#if (CN_ACCSM_BOM)
	if	(
			(ACC_State == ACC_STAT_BRAKEONLYMODE)
			&&
			(cc_status->CC_ACCEL_CONTROL_DATA.ACCEL_STATUS.OBJECT_EFFECTIVE == FALSE)
		)
	{
		InhibitReason_Ramp |= INHIBITREASON_RAMP_BOM_STATE_AND_NOT_OBJ_EFFECTIVE;
	}

	if	(
			(ACC_State == ACC_STAT_BRAKEONLYMODE)
			&&
			(pLongCtrlResp->Custom.CustomInput.CDDActive == FALSE)
		)
	{
		InhibitReason_Ramp |= INHIBITREASON_RAMP_BOM_STATE_AND_VEHICLE_NOT_BRAKING;
	}	
	
	if	(
			(ACC_State == ACC_STAT_BRAKEONLYMODE)
			&&
			(pLongCtrlResp->Custom.CustomInput.BrakeForceExist == FALSE) //Nobrakeforce == true
		)
	{
		InhibitReason_Ramp |= INHIBITREASON_RAMP_BOM_STATE_AND_NO_BRAKEFORCE;
	}

	if	(
			(ACC_State == ACC_STAT_BRAKEONLYMODE)
			&&
			(
				(das_input_data->BRAKE_STAT.PEDAL_INIT_TRAVEL == TRUE)
				||
				(das_input_data->LODM_STAT.OVERRIDE_DECEL == TRUE)
			)
		)
	{
		InhibitReason_Ramp |= INHIBITREASON_RAMP_BOM_STATE_AND_DRIVER_BRAKING;
	}
	
	if	(
			(ACC_State == ACC_STAT_BRAKEONLYMODE)
			&&
			(das_input_data->LODM_STAT.OVERRIDE_ACCEL == TRUE)
		)
	{
		InhibitReason_Ramp |= INHIBITREASON_RAMP_BOM_STATE_AND_DRIVER_ACCELERATING;
	}
	
	if	(
			(ACC_State == ACC_STAT_BRAKEONLYMODE)
			&&
			(das_input_data->LODM_STAT.STANDSTILL == TRUE)
		)
	{
		InhibitReason_Ramp |= INHIBITREASON_RAMP_BOM_STATE_AND_EGO_VEHICLE_STANDSTILL;
	}
	
	if	(
			(ACC_State == ACC_STAT_BRAKEONLYMODE)
			&&
			(u_BOM_Counter == (uint32)0)
		)
	{
		InhibitReason_Ramp |= INHIBITREASON_RAMP_BOM_STATE_OVERTIME;
	}
#endif
	
	if (InhibitReason_Ramp == 0)
	{
		input->INHIBIT.CC_DISENGAGEMENT_RAMP = FALSE;
	}
	else
	{
		input->INHIBIT.CC_DISENGAGEMENT_RAMP = TRUE;
		cc_status->CC_ACCEL_CONTROL_DATA.ACCEL_STATUS.CANCEL_RAMP = TRUE;
	}

	_PARAM_UNUSED(cycle_time);
	_PARAM_UNUSED(pVehDyn);
	_PARAM_UNUSED(das_input_data_last_cycle);
	_PARAM_UNUSED(driver_controls);
	_PARAM_UNUSED(acc_output);
	_PARAM_UNUSED(error_data);
#if (!CN_ACCSM_BOM)
	_PARAM_UNUSED(pLongCtrlResp);
	_PARAM_UNUSED(das_input_data);
#endif
}

/*****************************************************************************
  @fn             KMC_v_InhibitionCheck_Inhibit_Engagement */ /*!

  @brief          Determine inhibition condition: CC_INHIBIT_ENGAGEMENT.
  @description    Determine inhibition condition: CC_INHIBIT_ENGAGEMENT.

@startuml
Start
	Partition KMC_v_InhibitionCheck_Inhibit_Engagement(){
		:Determine InhibitReason_Inhibit_Engagement with multiple condtions checking;
		If (No InhibitReason satisfied) Then (true)
			: CC_INHIBIT_ENGAGEMENT is set as false;
		Else (false)
			: CC_INHIBIT_ENGAGEMENT is set as true;
		endif
	}
end
@enduml

  @param[in,out]  cycle_time
  @param[in,out]  pVehDyn
  @param[in,out]  pLongCtrlResp
  @param[in,out]  das_input_data
  @param[in,out]  das_input_data_last_cycle
  @param[in,out]  driver_controls
  @param[in,out]  acc_output
  @param[in,out]  input
  @param[in,out]  error_data
  @param[in,out]  cc_status
  @return         void

*****************************************************************************/
static void KMC_v_InhibitionCheck_Inhibit_Engagement(const times_t cycle_time,
                                                     const VehDyn_t* pVehDyn,
                                                     const LongCtrlInput_t* pLongCtrlResp,
                                                     const cart_das_input_data_t* das_input_data,
                                                     const cart_das_input_data_t* das_input_data_last_cycle,
                                                     const cc_driver_controls_t *driver_controls,
#if (FCT_CFG_ACC_HEADWAY_PLANNER)
                                                     const acc_output_data_t* acc_output,
#endif
                                                     cc_input_data_t* input, 
                                                     cc_error_data_t *error_data,
                                                     cc_status_t *cc_status)
{
	InhibitReason_Inhibit_Engagement = 0U;
	if	(
			(pLongCtrlResp->KinCtrlDynInput.stand_still_detected == TRUE) 
			&& 
			(pLongCtrlResp->KinCtrlDynInput.driver_braking == FALSE)
			&&
			(pLongCtrlResp->Custom.CustomInput.AVHActive == FALSE)
		)
	{
		InhibitReason_Inhibit_Engagement |= INHIBITREASON_INHIBIT_ENGAGEMENT_NO_BRRAKING_WHEN_STANDSTILL;
	}
	
	if (InhibitReason_Inhibit_Engagement == 0)
	{
		input->INHIBIT.CC_INHIBIT_ENGAGEMENT = FALSE;
	}
	else
	{
		input->INHIBIT.CC_INHIBIT_ENGAGEMENT = TRUE;
	}
	_PARAM_UNUSED(cycle_time);
	_PARAM_UNUSED(pVehDyn);
	_PARAM_UNUSED(das_input_data);
	_PARAM_UNUSED(das_input_data_last_cycle);
	_PARAM_UNUSED(driver_controls);
	_PARAM_UNUSED(acc_output);
	_PARAM_UNUSED(error_data);
	_PARAM_UNUSED(cc_status);
}

/*****************************************************************************
  @fn             KMC_v_InhibitionCheck_Soft_Off_Condition */ /*!

  @brief          Determine inhibition condition: b_Soft_Off_Condition.
  @description    Determine inhibition condition: b_Soft_Off_Condition.

@startuml
Start
	Partition KMC_v_InhibitionCheck_Soft_Off_Condition(){
		:Determine InhibitReason_Soft_Off_Condition with multiple condtions checking;
		If (No InhibitReason satisfied) Then (true)
			: b_Soft_Off_Condition is set as false;
		Else (false)
			: b_Soft_Off_Condition is set as true;
		endif
	}
end
@enduml

  @param[in,out]  cycle_time
  @param[in,out]  pVehDyn
  @param[in,out]  pLongCtrlResp
  @param[in,out]  das_input_data
  @param[in,out]  das_input_data_last_cycle
  @param[in,out]  driver_controls
  @param[in,out]  acc_output
  @param[in,out]  input
  @param[in,out]  error_data
  @param[in,out]  cc_status
  @return         void

*****************************************************************************/
static void KMC_v_InhibitionCheck_Soft_Off_Condition(const times_t cycle_time,
                                                     const VehDyn_t* pVehDyn,
                                                     const LongCtrlInput_t* pLongCtrlResp,
                                                     const cart_das_input_data_t* das_input_data,
                                                     const cart_das_input_data_t* das_input_data_last_cycle,
                                                     const cc_driver_controls_t *driver_controls,
#if (FCT_CFG_ACC_HEADWAY_PLANNER)
                                                     const acc_output_data_t* acc_output,
#endif
													 const cc_driver_inputs_t *driver_inputs,
                                                     cc_input_data_t* input, 
                                                     cc_error_data_t *error_data,
                                                     cc_status_t *cc_status,
													 cc_driver_information_t* driver_information)
{
	SWITCH_SET_COND_COUNTER(((pLongCtrlResp->KinCtrlDynInput.door_state & DOOR_FRONT_LEFT_OPEN) == DOOR_FRONT_LEFT_OPEN),Cc_driver_door_inhibit_time,cycle_time,&driver_information->CC_DRIVER_DOOR_CNT, 
							cc_status->CC_DRIVER_REQUESTS.DRIVER_REQUEST_STATUS.SELECTED_FUNCTION_ACTIVE);
	SWITCH_SET_COND_COUNTER(((pLongCtrlResp->KinCtrlDynInput.seatbelt_state &SEATBELT_DRIVER_CLOSED) ==0u),Cc_driver_seat_inhibit_time,cycle_time,&driver_information->CC_DRIVER_BELT_CNT, 
							cc_status->CC_DRIVER_REQUESTS.DRIVER_REQUEST_STATUS.SELECTED_FUNCTION_ACTIVE);
	InhibitReason_Soft_Off_Condition = 0U;
	if	(
			(input->ACTUAL_GEAR == Pt_gear_neutral)
			||
			(input->ACTUAL_GEAR == Pt_gear_park)
			||
			(input->ACTUAL_GEAR == Pt_gear_reverse)
		)
	{
		InhibitReason_Soft_Off_Condition |= INHIBITREASON_SOFT_OFF_CONDITION_GEAR_PNR;
	}
	
	if (pLongCtrlResp->Custom.CustomInput.GearPosition == GEAR_POSITION_MANUAL)
	{
		InhibitReason_Soft_Off_Condition |= INHIBITREASON_SOFT_OFF_CONDITION_MANUNAL_GEAR;
	}

	if(driver_information->CC_DRIVER_DOOR_CNT == (uint16) 0)
	{
		InhibitReason_Soft_Off_Condition |= INHIBITREASON_SOFT_OFF_CONDITION_DOOR_OPEN_FRONT_LEFT;
	}

	if(driver_information->CC_DRIVER_BELT_CNT == (uint16)0)
	{
		InhibitReason_Soft_Off_Condition |= INHIBITREASON_SOFT_OFF_CONDITION_SEATBELT_OPEN;
	}
	
	/* BYD customer need to deboucne time for door open and seat open to disable ACC fucntion 
	if ((pLongCtrlResp->KinCtrlDynInput.door_state & DOOR_FRONT_LEFT_OPEN) == DOOR_FRONT_LEFT_OPEN)
	{
		InhibitReason_Soft_Off_Condition |= INHIBITREASON_SOFT_OFF_CONDITION_DOOR_OPEN_FRONT_LEFT;
	}
	
	if ((pLongCtrlResp->KinCtrlDynInput.door_state & DOOR_FRONT_RIGHT_OPEN) == DOOR_FRONT_RIGHT_OPEN)
	{
		InhibitReason_Soft_Off_Condition |= INHIBITREASON_SOFT_OFF_CONDITION_DOOR_OPEN_FRONT_RIGHT;
	}
	
	if ((pLongCtrlResp->KinCtrlDynInput.door_state & DOOR_REAR_LEFT_OPEN) == DOOR_REAR_LEFT_OPEN)
	{
		InhibitReason_Soft_Off_Condition |= INHIBITREASON_SOFT_OFF_CONDITION_DOOR_OPEN_REAR_LEFT;
	}
	
	if ((pLongCtrlResp->KinCtrlDynInput.door_state & DOOR_REAR_RIGHT_OPEN) == DOOR_REAR_RIGHT_OPEN)
	{
		InhibitReason_Soft_Off_Condition |= INHIBITREASON_SOFT_OFF_CONDITION_DOOR_OPEN_REAR_RIGHT;
	}
	
	if ((pLongCtrlResp->KinCtrlDynInput.door_state & DOOR_ENG_HOOD_OPEN) == DOOR_ENG_HOOD_OPEN)
	{
		InhibitReason_Soft_Off_Condition |= INHIBITREASON_SOFT_OFF_CONDITION_ENGINE_HOOD_OPEN;
	}
	
	if ((pLongCtrlResp->KinCtrlDynInput.door_state & DOOR_TRUNK_OPEN) == DOOR_TRUNK_OPEN)
	{
		InhibitReason_Soft_Off_Condition |= INHIBITREASON_SOFT_OFF_CONDITION_TRUNK_OPEN;
	}
	
	if ((pLongCtrlResp->KinCtrlDynInput.seatbelt_state & SEATBELT_DRIVER_CLOSED) == 0u)
	{
		InhibitReason_Soft_Off_Condition |= INHIBITREASON_SOFT_OFF_CONDITION_SEATBELT_OPEN;
	}
	*/


	if (pLongCtrlResp->Custom.CustomInput.HDCSysStat == HDC_STAT_ACTIVE)
	{
		InhibitReason_Soft_Off_Condition |= INHIBITREASON_SOFT_OFF_CONDITION_HDC_ACTIVE;
	}
	
	if (cc_status->CC_ESP_ACT_CNT == (uint16)0)
	{
		InhibitReason_Soft_Off_Condition |= INHIBITREASON_SOFT_OFF_CONDITION_ESP_ACTIVE;
	}
	
	if (cc_status->CC_TCS_ACT_CNT == (uint16)0)
	{
		InhibitReason_Soft_Off_Condition |= INHIBITREASON_SOFT_OFF_CONDITION_TCS_ACTIVE;
	}
	
	if (cc_status->CC_ABS_ACT_CNT == (uint16)0)
	{
		InhibitReason_Soft_Off_Condition |= INHIBITREASON_SOFT_OFF_CONDITION_ABS_ACTIVE;
	}
	
	if ((pLongCtrlResp->KinCtrlDynInput.ldm_ctrl_state & LDM_CTRL_ESP_DEFECTIVE) == LDM_CTRL_ESP_DEFECTIVE)
	{
		InhibitReason_Soft_Off_Condition |= INHIBITREASON_SOFT_OFF_CONDITION_ESP_FAIL;
	}
	
	if ((pLongCtrlResp->KinCtrlDynInput.ldm_ctrl_state & LDM_CTRL_TCS_DEFECTIVE) == LDM_CTRL_TCS_DEFECTIVE)
	{
		InhibitReason_Soft_Off_Condition |= INHIBITREASON_SOFT_OFF_CONDITION_TCS_FAIL;
	}
	
	if ((pLongCtrlResp->KinCtrlDynInput.ldm_ctrl_state & LDM_CTRL_ABS_DEFECTIVE) == LDM_CTRL_ABS_DEFECTIVE)
	{
		InhibitReason_Soft_Off_Condition |= INHIBITREASON_SOFT_OFF_CONDITION_ABS_FAIL;
	}
	
	if (
			(pLongCtrlResp->Custom.CustomInput.EngineStatus != ENGINE_RUNNING)
			&&
			(pLongCtrlResp->Custom.CustomInput.EngineStatus != ENGINE_CRANKING)
		)
	{
		InhibitReason_Soft_Off_Condition |= INHIBITREASON_SOFT_OFF_CONDITION_ENGINE_NOT_OK;
	}	

	if (driver_inputs->CC_CANCEL_SWITCH_WITHOUT_BOM.AKT_STATUS == TRUE)
	{
		InhibitReason_Soft_Off_Condition |= INHIBITREASON_SOFT_OFF_CONDITION_CANCEL_BUTTON;
	}
	
	if (InhibitReason_Soft_Off_Condition == 0)
	{
		b_Soft_Off_Condition = FALSE;
	}
	else
	{
		b_Soft_Off_Condition = TRUE;
	}

	_PARAM_UNUSED(cycle_time);
	_PARAM_UNUSED(pVehDyn);
	_PARAM_UNUSED(das_input_data);
	_PARAM_UNUSED(das_input_data_last_cycle);
	_PARAM_UNUSED(driver_controls);
	_PARAM_UNUSED(acc_output);
	_PARAM_UNUSED(input);
	_PARAM_UNUSED(error_data);
}


/* **********************************************************************
  @fn             KMC_v_ProcVehDriveOff */ /*!

  @brief          Custom function to process ego vehicle drive off

  @description    Custom function to process ego vehicle drive off

  @startuml
    Start
      Partition KMC_v_ProcVehDriveOff(){
        : Evaluate Driver Confirmation(including saved Request);
        : Evaluate restart request;
        If (ACC State Machine is equal to off or ready) Then (True)
          : Set KMC to AutoGoMode_base;
        Endif
        if (AutoGoMode_base) Then (True)
          : Set DRIVE_OFF_CONFIRM to false;
          If (vehicle is in Standstill and brake is not pressed) Then (True)
              If (no Target Object is Present) Then (True)
                : Set DRIVE_OFF_CONFIRM to driver confirmation;
              Elseif (Standstill time is less than 3s) Then (True)
                : Set DRIVE_OFF_CONFIRM to restart request;
              Elseif (Driver Confirmation is True)\n or (it is existing within 5 secs) Then (True)
                : Set DRIVE_OFF_CONFIRM to True;
              Endif
          Else (False)
          Endif
        Else (False)
      Endif
      }
    End
  @enduml


  @param[in]      das_input

  @param[in/out]  cc_status
  
  @return         void

  @todo           Review this function

  @author         Wolfgang Borgs
**************************************************************************** */
static void KMC_v_ProcVehDriveOff(const times_t cycle_time,
                                  const LongCtrlInput_t* pLongCtrlResp,
                                  const FCTSenAccOOI_t* pFCTAccOOIData,
                                  cart_das_input_data_t* das_input,
                                  const cart_das_output_data_t* das_output,
                                  const acc_output_data_t* acc_output,
                                  cc_status_t *cc_status)
{
  boolean b_confirm, b_restart;
#if (KMC_CFG_AUTOGO_FEATURE)
  /* Flag for autostop */
  boolean b_autostop;

  /* CREEP DISTANCE */
  static float32 f_creep_distance = 0.0f;

  /* evaluate disable request for auto-go */
  boolean b_disable = (boolean)((pFCTAccOOIData->bFrontObstacleDetected == TRUE)
    ||
    ((pLongCtrlResp->KinCtrlDynInput.door_state & DOOR_FRONT_LEFT_OPEN) != 0x0u)
    ||
    ((pLongCtrlResp->KinCtrlDynInput.seatbelt_state & SEATBELT_DRIVER_CLOSED) == 0x0u)
    ||
    (pFCTAccOOIData->AccOOINextLong.Attributes.uiObjectID != t_OOIObjNr)
    ||
    (pFCTAccOOIData->AccOOINextLong.Attributes.uiObjectID == OBJ_INDEX_NO_OBJECT));

  /* evaluate autogo request */
  boolean b_autogo =  (boolean)((cc_status->CC_DRIVER_REQUESTS.DRIVER_REQUEST_STATUS.SELECTED_FUNCTION_ACTIVE == TRUE)
    &&
    (cc_status->CC_DRIVER_REQUESTS.ENGAGEMENT_CONDITIONS.DRIVE_OFF_POSSIBLE == TRUE)
    &&
    (cc_status->CC_DRIVER_REQUESTS.DRIVER_OPERATIONS.DRIVE_OFF_CONFIRM == FALSE));
#endif /* KMC_CFG_AUTOGO_FEATURE */

  /* Evaluate driver confirmation to drive off */
  if (cc_status->CC_DRIVER_REQUESTS.DRIVER_OPERATIONS.DRIVE_OFF_CONFIRM == TRUE)
  {
    b_confirm = TRUE;
    ui_Drive_Off_Confirmation_Timer = KMC_DRIVEOFF_CONFIRM_DURATION;  /* Timer set to max value */
  }
  else if (ui_Drive_Off_Confirmation_Timer > (times_t)0)
  {
    b_confirm = TRUE;
  }
  else
  {
    b_confirm = FALSE;
  }

  /* Evaluate restart request based on ACC active state and target drive off condition */
  b_restart =  (boolean)((cc_status->CC_DRIVER_REQUESTS.DRIVER_REQUEST_STATUS.SELECTED_FUNCTION_ACTIVE == TRUE)
                                 &&
                                 (cc_status->CC_DRIVER_REQUESTS.ENGAGEMENT_CONDITIONS.DRIVE_OFF_POSSIBLE == TRUE));

#if (KMC_CFG_AUTOGO_FEATURE)
  /* evaluate autostop request flag */
  if (fct_par_long_veh_auto_stop)
  {
    b_autostop = (boolean)((pFCTAccOOIData->bFrontObstacleDetected == TRUE)
                           &&
                           (pFCTAccOOIData->AccOOINextLong.Attributes.uiObjectID == t_OOIObjNr)
                           &&
                           (pFCTAccOOIData->AccOOINextLong.Attributes.uiObjectID != OBJ_INDEX_NO_OBJECT));
  }
  else
  {
    b_autostop = FALSE;
  }
#endif /* KMC_CFG_AUTOGO_FEATURE */


  /* Reset AutoGo State to eAutoGoMode_BASE during OFF and STANDBY */
  if ((cc_status->CC_DRIVER_REQUESTS.CONTROL_STATE == Cc_cc_off)
      ||
      (cc_status->CC_DRIVER_REQUESTS.CONTROL_STATE == Cc_cc_ready))
  {
    KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.KMC_Auto_Go_Mode = eAutoGoMode_BASE;
  }

  /* AutoGo Statemachine */
  switch (KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.KMC_Auto_Go_Mode)
  {
    case eAutoGoMode_BASE:
      /* unlimit acceleration */
      cc_status->CC_ACCEL_CONTROL_DATA.MAX_CUSTOM_ALLOWED_ACCEL = (acceleration_t)Accel_max;
      cc_status->CC_DRIVER_REQUESTS.DRIVER_OPERATIONS.DRIVE_OFF_CONFIRM = FALSE;
  
      if (
          (das_input->LODM_STAT.STANDSTILL == TRUE)
          &&
          (das_input->BRAKE_STAT.PEDAL_INIT_TRAVEL != TRUE)
         )
      { /* Vehicle is in standstill and brakes not pressed */
        /* freemode (StandWait without target) */
        if (acc_output->SITUATION_CLASS.SITUATION == Acc_sit_class_freemode)
        {
          /* confirm driveoff only by driver */
          cc_status->CC_DRIVER_REQUESTS.DRIVER_OPERATIONS.DRIVE_OFF_CONFIRM = b_confirm;
        }
        /* target related */
        else
        {
          if (Kmc_Standstillstate == StandStillState_StandActive)
          {
            /* confirm driveoff under restart conditions */
            cc_status->CC_DRIVER_REQUESTS.DRIVER_OPERATIONS.DRIVE_OFF_CONFIRM = b_restart;
          }
          else //Kmc_Standstillstate == StandStillState_StandWait
          {
            /* with driver confirmation */
            if (b_confirm == TRUE)
            {
              /* confirm driveoff */
              cc_status->CC_DRIVER_REQUESTS.DRIVER_OPERATIONS.DRIVE_OFF_CONFIRM = TRUE;
            }
#if (KMC_CFG_AUTOGO_FEATURE)  /* Transit to other states of autogo state machine only when feature is activated.  */
            /* if in standstill longer than 3s from valid object */
            else if ((das_output->DAS_STAT.DAS_STAND_STILL == TRUE)
                  && (das_output->DAS_STAT.DAS_DRIVE_OFF == FALSE)
                  && (t_OOIObjNr != OBJ_INDEX_NO_OBJECT))
            {
              /* delegate driveoff to ENABLED state */
              cc_status->CC_DRIVER_REQUESTS.DRIVER_OPERATIONS.DRIVE_OFF_CONFIRM = FALSE;

              /* activate ENABLED MODE */
              KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.KMC_Auto_Go_Mode = eAutoGoMode_ENABLED;
            }            
#endif /* KMC_CFG_AUTOGO_FEATURE */
          }
        }
      }
      else
      { /* vehicle is moving */
#if ( KMC_CFG_AUTOGO_FEATURE )
        /* store actual OOI object */
        t_OOIObjNr = pFCTAccOOIData->AccOOINextLong.Attributes.uiObjectID;
#endif
      }
    break;

#if (KMC_CFG_AUTOGO_FEATURE)
    case eAutoGoMode_ENABLED:
      /* prevent driveoff */
      cc_status->CC_DRIVER_REQUESTS.DRIVER_OPERATIONS.DRIVE_OFF_CONFIRM = FALSE;

      /* unlimit acceleration */
      cc_status->CC_ACCEL_CONTROL_DATA.MAX_CUSTOM_ALLOWED_ACCEL = (acceleration_t)Accel_max;

      /* if disable condition or timeout */
      if (b_disable || (cc_status->CC_DRIVER_REQUESTS.STAND_STILL_TIME > FCT_PAR_LONG_VEH_AUTOGO_TIME_MAX))
      {
        /* invalidate stored OOI object */
        t_OOIObjNr = OBJ_INDEX_NO_OBJECT;

        /* activate DISABLED MODE */
        KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.KMC_Auto_Go_Mode = eAutoGoMode_DISABLED;
      }
      /* if driver confirmation */
      else if (b_confirm)
      {
        /* activate BASE MODE */
        KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.KMC_Auto_Go_Mode = eAutoGoMode_BASE;

        /* confirm driveoff */
        cc_status->CC_DRIVER_REQUESTS.DRIVER_OPERATIONS.DRIVE_OFF_CONFIRM = TRUE;
      }
      /* else if autogo is required */
      else if (b_autogo)
      {
        /* reset creep distance */
        f_creep_distance = 0.0F;

        /* activate CREEP MODE */
        KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.KMC_Auto_Go_Mode = eAutoGoMode_CREEP;
      }
    break;

    case eAutoGoMode_DISABLED:
      /* prevent driveoff */
      cc_status->CC_DRIVER_REQUESTS.DRIVER_OPERATIONS.DRIVE_OFF_CONFIRM = FALSE;

      /* unlimit acceleration */
      cc_status->CC_ACCEL_CONTROL_DATA.MAX_CUSTOM_ALLOWED_ACCEL = (acceleration_t)Accel_max;

      /* only by driver confirmation */
      if (b_confirm)
      {
        /* activate BASE MODE */
        KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.KMC_Auto_Go_Mode = eAutoGoMode_BASE;

        /* confirm driveoff */
        cc_status->CC_DRIVER_REQUESTS.DRIVER_OPERATIONS.DRIVE_OFF_CONFIRM = TRUE;
      }
    break;

    case eAutoGoMode_CREEP:
      /* assign driveoff confirmation for auto-go */
      cc_status->CC_DRIVER_REQUESTS.DRIVER_OPERATIONS.DRIVE_OFF_CONFIRM = TRUE;

      /* limit to creep acceleration (1.0 m/s^2) */
      cc_status->CC_ACCEL_CONTROL_DATA.MAX_CUSTOM_ALLOWED_ACCEL = FCT_PAR_LONG_VEH_CREEP_ACCEL_MAX;

      /* increment creep distance */
      f_creep_distance += (float32)das_input->VEHICLE_SPEED / (float32)Velocity_s * cycle_time / (float32)Time_s;

      /* if autostop condition is true */
      if (b_autostop)
      {
        /* invalidate stored OOI object */
        t_OOIObjNr = OBJ_INDEX_NO_OBJECT;

        /* activate STOP MODE */
        KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.KMC_Auto_Go_Mode = eAutoGoMode_STOP;
      }
      /* else if vehicle comes to further standstill */
      else if (  (das_input->LODM_STAT.STANDSTILL == TRUE)
              && (cc_status->CC_DRIVER_REQUESTS.STAND_STILL_TIME < Cc_standstill_delay_time) )
      {
        /* delegate driveoff to ENABLED state */
        cc_status->CC_DRIVER_REQUESTS.DRIVER_OPERATIONS.DRIVE_OFF_CONFIRM = FALSE;

        /* activate ENABLED MODE */
        KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.KMC_Auto_Go_Mode = eAutoGoMode_ENABLED;
      }
      /* else if confirmation by driver or creep distance above threshold (10.0 m) */
      else if (b_confirm || (f_creep_distance > FCT_PAR_LONG_VEH_CREEP_DIST_THR))
      {
        /* activate BASE MODE */
        KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.KMC_Auto_Go_Mode = eAutoGoMode_BASE;
      }
    break;

    case eAutoGoMode_STOP:
      /* limit to stop deceleration (-5.0 m/s^2) */
      cc_status->CC_ACCEL_CONTROL_DATA.MAX_CUSTOM_ALLOWED_ACCEL = FCT_PAR_LONG_VEH_STOP_DECEL_MIN;

      /* if confirmation by driver */
      if (b_confirm)
      {
        /* activate BASE MODE */
        KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.KMC_Auto_Go_Mode = eAutoGoMode_BASE;
      }
      /* if vehicle has come to standstill */
      else if (das_input->LODM_STAT.STANDSTILL == TRUE)
      {
        /* set brake activation signal to prevent normal restart */
        das_input->BRAKE_STAT.PEDAL_INIT_TRAVEL = TRUE;

        /* activate DISABLED MODE */
        KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.KMC_Auto_Go_Mode = eAutoGoMode_DISABLED;
      }
    break;
#endif /* KMC_CFG_AUTOGO_FEATURE */

    default:
    break;
  }

  /* Driver driveoff confirmation timer to be decremented */
  SWITCH_SET_COUNTER(cycle_time, &ui_Drive_Off_Confirmation_Timer);

#if (KMC_CFG_AUTOGO_FEATURE == SWITCH_OFF)
  _PARAM_UNUSED(pFCTAccOOIData);
  _PARAM_UNUSED(pLongCtrlResp);
  _PARAM_UNUSED(das_output);
#endif
}



/* **********************************************************************
  @fn             KMC_v_LimitLongAccelCustom */ /*!

  @brief          Custom function to limit longitudinal acceleration
                  according specific customer requirements

  @description    Custom function to limit longitudinal acceleration
                  according specific customer requirements
  
@startuml
Start
Partition KMC_v_LimitLongAccelCustom(){
: Custom function to limit longitudinal acceleration according specific customer requirements;
}
End
@enduml

  @param[in]      


  @return         None

  @todo           Review this function

  @author         Simon Sinnstein
**************************************************************************** */
static void KMC_v_LimitLongAccelCustom(const times_t cycle_time, 
                                        cc_status_t *cc_status, 
                                        const cc_input_data_t* input, 
                                        const acc_output_data_t* acc_output, 
                                        const cart_das_input_data_t* das_input, 
                                        cart_das_output_data_t* das_output, 
                                        cc_driver_information_t* driver_information
#if (FCT_CFG_SEN2VEH_ACC_OOI_PORT)
                                      ,const FCTSenAccOOI_t* pFCTAccOOIData
#endif
#if CN_ACCSM
                                      ,const acc_object_t * pAccDisplayObj
#endif
                                      )
{
_PARAM_UNUSED(input);
_PARAM_UNUSED(driver_information);
_PARAM_UNUSED(das_output);
_PARAM_UNUSED(cycle_time);
_PARAM_UNUSED(acc_output);
  /*! reset MAX_CUSTOM_ALLOWED_ACCEL */
  cc_status->CC_ACCEL_CONTROL_DATA.MAX_CUSTOM_ALLOWED_ACCEL = (acceleration_t)Accel_max;
  cc_status->CC_ACCEL_CONTROL_DATA.MIN_CUSTOM_ALLOWED_ACCEL = (acceleration_t)Accel_min;

//////////////////////for close object detect/////////////////////

#if CN_ACCSM

  switch(StateAccLowSpd)
  {
    case StateAccLowSpd_INIT:
      /* Check exit condition */
      if (pAccDisplayObj->AUTOSAR.OBJECT_STATUS.DETECTED == TRUE)
      {
        /* inti ACC_Cancellation_Flag as FALSE*/
        ACC_Cancellation_Flag = FALSE;
        /* Store the values before the object is lost */
        DistObjBeforeLoss = (float32)pAccDisplayObj->AUTOSAR.LONG_DISPLACEMENT;
        /* Switch to OBJ_DETECTED */
        StateAccLowSpd = StateAccLowSpd_OBJ_DETECTED;
      }
      else
      {
        /* During INIT, no action is required */
      }
      break;

  case StateAccLowSpd_OBJ_DETECTED:
    /* Check exit condition */
    if ( ((pFCTAccOOIData->AccOOINextLong.eRelObjLossReason == OBJ_LOSS_DISAPPEARED) ||
        (pFCTAccOOIData->AccOOINextLong.eRelObjLossReason == OBJ_LOSS_DISAPP_LOWDIST))
        /*(pAccDisplayObj->AUTOSAR.OBJECT_STATUS.DETECTED == FALSE)
        &&
        (objstatus_detect_lastcycle == TRUE)*/
        &&
        (das_input->VEHICLE_SPEED <= VehSpdThdAccLowSpdCancel) 
        &&
        (DistObjBeforeLoss <= (float32)DistThdAccLowSpdImmediateCancel))
    {
        /* Switch to ACC_CANCEL, immediate cancellation */
        StateAccLowSpd = StateAccLowSpd_ACC_CANCEL;
        ACC_Cancellation_Flag  = TRUE;
    }
    else
    {
      /* During OBJ_DETECTED */
      if(pAccDisplayObj->AUTOSAR.OBJECT_STATUS.DETECTED == TRUE)
      {
        /* Store the values before the object is lost */
        DistObjBeforeLoss = (float32)pAccDisplayObj->AUTOSAR.LONG_DISPLACEMENT;
      }
      /* During OBJ OBJ_LOSS_DISAPPEARED but distance before loss more than 30m or ego speed more than 10m/s */
      else if((DistObjBeforeLoss > (float32)DistThdAccLowSpdCancel) || (das_input->VEHICLE_SPEED > VehSpdThdAccLowSpdCancel))
      {
        /* Switch to Init State */
        StateAccLowSpd = StateAccLowSpd_INIT;
      }
      else
      {
        /* Do Nothing */
      }
    }
    break;

  case StateAccLowSpd_ACC_CANCEL:

    ACC_Cancellation_Flag  = TRUE;
    if((cc_status->CC_DRIVER_REQUESTS.CONTROL_STATE == Cc_cc_ready) || (cc_status->CC_DRIVER_REQUESTS.CONTROL_STATE == Cc_cc_off))
    {
      /* switch to INIT */
      StateAccLowSpd = StateAccLowSpd_INIT;
      /* action on entry */
      ACC_Cancellation_Flag = FALSE;
    }
    break;

  default: /* UNDEFINED */
    /* switch to INIT */
    StateAccLowSpd = StateAccLowSpd_INIT;
    /* action on entry */
    ACC_Cancellation_Flag = FALSE;
    break;
  }

  objstatus_detect_lastcycle = pAccDisplayObj->AUTOSAR.OBJECT_STATUS.DETECTED;

#endif

}

#if (FCT_CFG_SLA_FEATURE)
/*************************************************************************************************************************
  Functionname:    KMC_t_SLACalcSpeedlimitDist                                                                      */ /*!

  @brief           Calculate speed limit distance

  @description     Distance to the future speed limit have to be extrapolated (= predicted) for the functional use
                    because of too low resolution of navi data . Only necessary if no new value is available.
  
@startuml
start
Partition KMC_t_SLACalcSpeedlimitDist(){
If (last Cycle Speed Limit Distance is not equal to current cycle Speed Limit Distance) Then (True)
: Not to predict the Future Speed Limit Value;
Else (False)
: Extrapolate distance travelled by vehicle;
  If (value is too small) then (True)
  : accumulate the distance and send the old value;
  Else (false)
  : Update the speed limit distance;
  endif
Endif
}
end
@enduml


  @return          u_SpeedLimitDist : Interpolated distance to next speed limit for functional use [t_u_DistanceLong as per Rte_Type.h]m

  @param[in]       cycle_time : cycle time of FCT_VEH cycle [times_t as per Rte_Type.h]ms
  @param[in]       uSpeedLimitDistance : Distance to speed limit sign as input from sensors with factor Scale_10 [full range of t_u_DistanceLong] m
  @param[in]       vehicle_speed : Ego speed with factor Velocity_s [full range of datatype sint16] cm/s 
  @param[in]       SLA_SpeedLimit : Pointer to internally saved speed limit data
                    SLA_SpeedLimit->u_SpeedLimitDistance : Internally saved last cycle distance to next speed limit sign  with factor Scale_10 [full range of t_u_DistanceLong] m

  @glob_in         u_DeltaDist : Driven distance since last update of speed limit distance (necessary due to low resolution in s_SpeedLimitDist; 
                        s_SpeedLimitDist cannot be updated in every cycle) [0u ...MAX_EXRAPOLATION_DEVIATION]m 

  @glob_in         u_SpeedLimitDistLC : Local last cycle extrapolated speed limit distance with factor Scale_10 [t_u_DistanceLong as per Rte_Type.h]m
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_SLA_FEATURE : Switch for enabling SLA Support functions
  @c_switch_full   FCT_CFG_LOPC_COMPONENT : Configuration switch for enabling LOPC processing

  @created         08.06.2016
  @changed         08.06.2016

  @author          Simon Sinnstein | simon.sinnstein@continental-corporation.com | +49 (8382) 9699-160
*************************************************************************************************************************/
static t_u_DistanceLong KMC_t_SLACalcSpeedlimitDist(const times_t cycle_time,// PRQA S 3219
/* date: 2018-03-22, reviewer: Ravikiran Gurrala, reason: Will be used in future.*/
                                                    const t_u_DistanceLong uSpeedLimitDistance,
                                                    const velocity_t vehicle_speed,
                                                    const t_SLA_SpeedLimit* SLA_SpeedLimit)
{
  distance_t u_Help;
  sint32 s_SpeedLimitDist;                    /*!< Current cycle extrapolated speed limit distance */

  if(uSpeedLimitDistance != 0u)
  {
    if(u_SpeedLimitDistLC != uSpeedLimitDistance)
    {
      /* no exrapolation, only write a new value */
      s_SpeedLimitDist = (sint32)uSpeedLimitDistance;
      u_DeltaDist = 0u;
    }
    else
    {
      /* Get last cycle extrapolated value*/
      s_SpeedLimitDist = (sint32)SLA_SpeedLimit->u_SpeedLimitDistance;
      /* Determine driven distance from last cycle */
      u_Help = (distance_t)MAT_MUL((sint32)cycle_time, (sint32)vehicle_speed, (sint32)Time_s, (sint32)Velocity_s, (sint32)Distance_s);
      /* Driven distance since last update of speed limit distance (necessary due to low resolution in s_SpeedLimitDist; 
      s_SpeedLimitDist cannot be updated in every cycle)*/
      u_DeltaDist += u_Help;
      /* Update s_SpeedLimitDist if dirven distance ist higer than resolution of s_SpeedLimitDist */
      if(u_DeltaDist >= Scale_10)
      {
        /* enough resolution */
        s_SpeedLimitDist -= (sint32)(u_DeltaDist / Scale_10);
        /* reset driven distance ofter s_SpeedLimitDist update */
        u_DeltaDist = 0u;
        /* extrapolate only for MAX_EXRAPOLATION_DEVIATION/10 m, otherwise don't update extrapolated value */
        s_SpeedLimitDist = MAT_MAX(s_SpeedLimitDist, MAT_MAX((sint32)0, (((sint32)u_SpeedLimitDistLC) - (sint32)MAX_EXRAPOLATION_DEVIATION)));
      }
      else
      {
        /* the value is too small, accumulate the distance, send the old value */
        /*  */
      }
    }
  }
  else
  {
    s_SpeedLimitDist = 0u;
    u_DeltaDist = 0u;
  }
  /* Speed limit distance last cycle */
  u_SpeedLimitDistLC = uSpeedLimitDistance;
  /* return valid speed limit distance */
  return (t_u_DistanceLong)s_SpeedLimitDist;
}

/*************************************************************************************************************************
  Functionname:    KMC_v_SLADetermineSpeedlimitState                                                                */ /*!

  @brief           Determination of state of acceptance of SLA speed limit

  @description     SLA speed limit is assessed based on customer requirements and 
                   speed limitations, if the speed limit is to be accepted or not.

  @startuml
    Start
      Partition KMC_v_SLADetermineSpeedlimitState(){

        If (Speedlimit is beyond CC limits\nOR\nSpeedlimit beyond max SLA limit) then (True)
          : set the sla speed to 0 because of Invalid input;
        Else (False)
        Endif

        Note left
          Set values b_SLA_NEW_SPEED_AVAILABLE
          and b_SLA_SPEED_ACCEPTED in speed
          limit status
        Endnote

        If (Speedlimit does not equal 0 AND\n SLA feature internal status is Active) then (True)
          
          If (Speedlimit equals already accepted speed) then (True)
            If (Offset is changed by driver\nAND\nSpeed with offset does\n not equal current setspeed\nAND\nCurrent setspeed is from SLA,\n not driver) then (True)
              : Speedlimit status set \nto New, Accepted;
            Else (False)
              : Speedlimit status set to \nNot New,Not Accepted;
            Endif
            
          Else (False)
            : Speedlimit is compared to current setspeed,\n and last declined speed \nto check if it is New;                   
            If (Speedlimit is New \nAND\nSpeedlimit value has not been declined before\nAND\nSpeedlimit has not been aborted before\nAND\nCurrent setspeed is not beyond \nmonotonically increasing/decreasing\n speed limits, in Auto mode) then (True)
              If (SLA mode) then (Auto mode)
                : Speedlimit status set to Accepted;
              Else (Manual mode)
                : Speedlimit status set only\n after driver confirmation;
              Endif
              : Speedlimit status set to Accepted;
            Else (False)
              : Speedlimit status set to\n Not New,Not Accepted;
            Endif
          Endif

        Else (False)
          : Speedlimit status set to\n Not New,Not Accepted;
        Endif
      }
    end
  @enduml

  
  @return          -

  @param[in]       cc_input : Pointer to CC input interface
                    cc_input->VEHICLE_STATUS.SPEED_UNIT_KMH :  boolean indicating the speed unit, i.e. KMH or MPH [TRUE, FALSE]
                    cc_input->SLA_INPUT_DATA.SLA_InputStatus.b_SLA_SPEED_ABORTED : boolean indicating if a speed limit is aborted [TRUE, FALSE]

  @param[in]       pSLA_HMI_Data : Pointer to data struct SLA HMI
                    pSLA_HMI_Data->SLA_SpeedLimitActualAccepted.u_SpeedLimit : Accepted speed limit [full range of datatype uint8]
                    pSLA_HMI_Data->e_SLA_State: State of SLA state machine [t_e_SLA_State as per cc_ext.h]
                    pSLA_HMI_Data->u_SLA_SpeedLimitLastDeclined : Previous declined speed limit [full range of datatype uint8]

  @param[in]       cc_driver_requests : Pointer to driver requests input structure
                    cc_driver_requests->MAX_CC_SETSPEED : Maximal Cruise Control set speed [full range of datatype uint8] 
                    cc_driver_requests->MIN_CC_SETSPEED : Minimal Cruise Control set speed [full range of datatype uint8] 
                    cc_driver_requests->DRIVER_REQUEST_STATUS.SELECTED_FUNCTION_ACTIVE : Boolean indicating if ACC / CC active [TRUE, FALSE]
                    cc_driver_requests->CC_SETSPEED : Current Cruise Control set speed [full range of datatype uint8]
                    cc_driver_requests->DRIVER_OPERATIONS.SPEED_LIMIT_ACCEPTED : Boolean indicating if driver accepted the proposed speed limit [TRUE, FALSE]

  @param[in,out]   pSLA_SpeedLimit : Pointer to data struct of SLA speed limit
                    pSLA_SpeedLimit->u_SpeedLimit : SLA speed limit [full range of datatype uint8]

  @param[in,out]   pSLA_InputStatus : Pointer to SLA status structure of speed limit
                    pSLA_InputStatus->b_SLA_NEW_SPEED_AVAILABLE : boolean indicating if new valid speed limit available [TRUE, FALSE]
                    pSLA_InputStatus->b_SLA_SPEED_ACCEPTED : boolean indicating if the new speed limit was accepted [TRUE, FALSE]

  @glob_out        -

  @c_switch_part   None
  @c_switch_full   FCT_CFG_SLA_FEATURE : Switch for enabling SLA Support functions
  @c_switch_full   FCT_CFG_LOPC_COMPONENT : Configuration switch for enabling LOPC processing

  @pre             -
  @post            -

  @created         18.07.2016
  @changed         22.07.2019

  @author          Simon Sinnstein | simon.sinnstein@continental-corporation.com | +49 (8382) 9699-160
*************************************************************************************************************************/
static void KMC_v_SLADetermineSpeedlimitState(const cc_input_data_t* cc_input,
                                              const t_SLA_HMI_Data* pSLA_HMI_Data,
                                              const cc_driver_requests_t* cc_driver_requests,
                                              t_SLA_SpeedLimit* pSLA_SpeedLimit,
                                              t_SLA_InputStatus* pSLA_InputStatus)
{
  boolean SLA_PERMISSION, SLA_RESTRICTION;
  setspeed_t u_SLASpeedLimit = pSLA_SpeedLimit->u_SpeedLimit;
  setspeed_t u_SLA_SLPlusOffset = pSLA_SpeedLimit->u_SpeedLimitIncOffset;

  if(
      (
        (u_SLA_SLPlusOffset != SLA_UNRESTRICTED_SPEED)
        &&
        (
         (u_SLA_SLPlusOffset > cc_driver_requests->MAX_CC_SETSPEED)
         ||
         (u_SLA_SLPlusOffset < cc_driver_requests->MIN_CC_SETSPEED)
         ||
         (pSLA_SpeedLimit->u_SpeedLimit > Max_sla_speed)
        )
      )
    )
  {
    /* set the sla speed to 0 because of invalid input */
    u_SLA_SLPlusOffset = SLA_INTIALIZE_SPEED;
  }

  /* Reset status input to retake previous speeds */
  pSLA_InputStatus->b_SLA_RETAKE_SPEED = FALSE;


  /* Speed limit to be judged only if SLA status is active */
  if((cc_input->SLA_INPUT_DATA.SLA_InputStatus.b_SLA_SET_ENGAGED == TRUE)
     &&(u_SLA_SLPlusOffset != SLA_INTIALIZE_SPEED)
    )
  {

    /* Decision to accept the speed limit */
    if(u_SLASpeedLimit == pSLA_HMI_Data->SLA_SpeedLimitActualAccepted.u_SpeedLimit) 
    { 
      /* Speedlimit is same as already accepted SLA speed */

      if(
          (u_SLA_SLPlusOffset != pSLA_HMI_Data->SLA_SpeedLimitActualAccepted.u_SpeedLimitIncOffset) && /* Speed offset is changed */
          (u_SLA_SLPlusOffset != cc_driver_requests->CC_SETSPEED)    &&                         /* New speed is different from current setspeed */
          (pSLA_HMI_Data->SLA_SpeedLimitActualAccepted.u_SpeedLimitIncOffset == cc_driver_requests->CC_SETSPEED) /* Current setspeed is from SLA sign */
        )
      { /* Speed limit status setting for change in offset by driver */
        pSLA_InputStatus->b_SLA_NEW_SPEED_AVAILABLE = TRUE;
        pSLA_InputStatus->b_SLA_SPEED_ACCEPTED = TRUE;
      } 
      else
      {
        pSLA_InputStatus->b_SLA_NEW_SPEED_AVAILABLE = FALSE;
        pSLA_InputStatus->b_SLA_SPEED_ACCEPTED = FALSE;
      }
      
    } 
    else
    { 
      /* Speed limit status setting for newly received traffic sign */

      /* Check if new Speed limit is distinct */
      if( 
          /* Reject new speed limits if same as current setspeed */
          (u_SLA_SLPlusOffset != cc_driver_requests->CC_SETSPEED) && 
          /* Reject new speed limits if same as declined by driver */
          (u_SLASpeedLimit != pSLA_HMI_Data->u_SLA_SpeedLimitLastDeclined)
        )
      {
        pSLA_InputStatus->b_SLA_NEW_SPEED_AVAILABLE = TRUE;
      }
      else
      {
        pSLA_InputStatus->b_SLA_NEW_SPEED_AVAILABLE = FALSE;
      }

      /* Validation if the speed limit have to be proposed, according to customer requirements */
      SLA_PERMISSION = (boolean)
      ( /* SLA Manual mode: Acceptance only with driver confirmation */
        ((cc_input->SLA_INPUT_DATA.SLA_InputStatus.b_SLA_SET_AUTOMATIC == FALSE) && (cc_driver_requests->DRIVER_OPERATIONS.SPEED_LIMIT_ACCEPTED == TRUE))
        ||
        ( /* SLA Auto mode */
          (cc_input->SLA_INPUT_DATA.SLA_InputStatus.b_SLA_SET_AUTOMATIC == TRUE)
          &&(cc_input->SLA_INPUT_DATA.SLA_InputStatus.b_SLA_SPEED_DECLINED == FALSE)
          &&(cc_input->SLA_INPUT_DATA.SLA_InputStatus.b_SLA_SPEED_ABORTED == FALSE)
        )
      );

      SLA_RESTRICTION = (boolean)
      (
        (pSLA_InputStatus->b_SLA_NEW_SPEED_AVAILABLE == FALSE)
        ||
        (
          (cc_input->SLA_INPUT_DATA.SLA_InputStatus.b_SLA_SET_AUTOMATIC == TRUE)
          &&
          (pSLA_HMI_Data->SLA_SpeedLimitActualAccepted.u_SpeedLimitIncOffset != SLA_INTIALIZE_SPEED)
          &&
          ( /* Check setspeed change is done by driver and not by SLA Feature */
            (cc_driver_requests->CC_SETSPEED != pSLA_HMI_Data->SLA_SpeedLimitActualAccepted.u_SpeedLimitIncOffset)
            &&
            (
              ( /* Setspeed decreased by driver between subsequent traffic signs */
                (cc_driver_requests->CC_SETSPEED < pSLA_HMI_Data->SLA_SpeedLimitActualAccepted.u_SpeedLimitIncOffset)
                &&
                (cc_driver_requests->CC_SETSPEED < u_SLA_SLPlusOffset)
                &&
                (u_SLA_SLPlusOffset < pSLA_HMI_Data->SLA_SpeedLimitActualAccepted.u_SpeedLimitIncOffset)
              )
              ||
              ( /* Setspeed increased by driver between subsequent traffic signs */
                (cc_driver_requests->CC_SETSPEED > pSLA_HMI_Data->SLA_SpeedLimitActualAccepted.u_SpeedLimitIncOffset)
                &&
                (cc_driver_requests->CC_SETSPEED > u_SLA_SLPlusOffset)
                &&
                (u_SLA_SLPlusOffset > pSLA_HMI_Data->SLA_SpeedLimitActualAccepted.u_SpeedLimitIncOffset)
              )
            )
          )
        )
      );

      if((SLA_PERMISSION == TRUE)&&(SLA_RESTRICTION == FALSE))
      {
        pSLA_InputStatus->b_SLA_SPEED_ACCEPTED = TRUE;
      }
      else
      {
        pSLA_InputStatus->b_SLA_SPEED_ACCEPTED = FALSE;
      }
    }

  }
  else  /* SLA off or no valid input. Speed limit not to be used */
  {
    pSLA_InputStatus->b_SLA_NEW_SPEED_AVAILABLE = FALSE;
    pSLA_InputStatus->b_SLA_SPEED_ACCEPTED = FALSE;
  }

}

/*************************************************************************************************************************
  Functionname:    KMC_v_SLAInputWrapper                                                                            */ /*!

  @brief           Input Signals Wrapper for SLA Support Function

  @description     Input wrapper with functions like signal mapping (driver SLA mode selection,
                   driver SLA offset, driver takeover of speed limit, etc.). Input speed limit received from SLATE
                   is converted to correct speed units, limited to allowed max speed limits, compared to 
                   existing/previous speed limits and processed for usage for the feature. Based on auto/manual mode, 
                   a speed limit is either selected for takeover for shown to driver for approval.

  @startuml
    Start
      Partition KMC_v_SLAInputWrapper(){
        : Input Signals Wrapper for SLA Support Function;

        If (SLA Support function is switched ON) then (True)
          : SLA auto/manual setting is saved,\n depending on HMI setting in the vehicle;
          : If no implicit speedlimits are received,\n only Manual cfg is selected;
          : Received traffic sign speed from SLATE\n is converted to correct units (kph/mph);
          : Flags set if brand new speed limit\n or unrestricted sign is received;
          : Driver warning set if input speed limit is out of SLA limits\n and input is restricted to SLA limits [30,130];
          : Driver offset saved, if speed limit within limits;
          : Flag set on receival of brand new driver offset;
          : Driver offset added to input speed \nlimits within SLA limits and not Unrestricted;
          Note right
            SLA_SpeedLimitNow: Current received input speed limit
            SLA_SpeedLimitActAccepted: Speedlimit that is saved
            in HMI, for reuse if offset is changed
          End Note
          : Detect street type implicit/explicit\n from speed limit inputs;
          : SLA internal status set using ACC state;
          : Reset HMI variables when ACC transitions Passive->Active;
          : Check speed limits against criteria for distinctiveness/acceptance;

          If (SLA mode) Then (SLA Manual mode)
            If (SLA_SpeedLimitNow is new & distinct) then (True)
              : Driver button usage reserved for SLA;
              : Max timer of button usage started;
            Else (False)
            Endif
            : If timer is over, button usage flag reset;
          Else (SLA Auto mode)
            If (Accepted SLA speed newly used to change setspeed) then (True)
              : Driver button usage reserved for SLA;
              : Max timer of button usage started;
            Else (False)
            Endif
            : If timer is over, button usage flag reset;
          Endif

          If (Offset has been changed and \n SLA_SpeedLimitActAccepted is valid) then (True)
            : Suggested speed limit updated \nwith SLA_SpeedLimitActAccepted;
            : Suggested speed acceptance flag set to 1;
          Note right
            Path used to update setspeed if
            driver has changed offset
          Endnote
          Elseif (SLA_SpeedLimitNow is not 0) then (True)
            : Suggested speed limit updated\n with SLA_SpeedLimitNow;
          Note right
            Path used to update setspeed
            from new input speed limit
          Endnote
            : Suggested speed acceptance flag copied\n from flag of SLA_SpeedLimitNow;
          Else (no valid speedlimit exists)
            : Suggested speed limit reset to 0;
          Endif
          Note right
            Single speedlimit selected
            to be forwarded to 
            SLA_INPUT_DATA variable
          Endnote
          : Store the Speed Limit in the Internal buffer;
        Else (False)
          : Initialize all SLA inputs;
        Endif

      }
    End
  @enduml


  @return          -

  @param[in]       cycle_time : cycle time of FCT_VEH cycle [times_t as per Rte_Type.h]ms
  @param[in]       pLongCtrlResp : Pointer to Longitudinal control input structure [LongCtrlInput_t as per Rte_type.h]
                    pLongCtrlResp->SLA_Input.e_SLA_Setting : SLA setting: manual or automatic [t_e_SLA_Setting as per Rte_Type.h]
                    pLongCtrlResp->SLA_Input.e_SLA_SpeedLimitUnit : Speed unit of speed limit [SpeedUnitEnum_t as per Rte_Type.h]
                    pLongCtrlResp->SLA_Input.u_SLA_SpeedLimitNow : Speed limit valid now [full range of datatype uint8]
                    pLongCtrlResp->SLA_Input.u_SLA_SpeedLimitNext : Speed limit valid next in the future [full range of datatype uint8]
                    pLongCtrlResp->SLA_Input.u_SLA_SpeedLimitNextDistance : Distance to next speed limit  with factor Scale_10 [t_u_DistanceLong as per Rte_Type.h]m
                    pLongCtrlResp->SLA_Input.e_SLA_SpeedLimitNextType : Type of reaction to next speed limit [t_e_SLA_SpeedLimitNextTyp as per Rte_Type.h]
                    pLongCtrlResp->Navi_Input.e_NavStreetType : Street type send from navigation [t_NavStreetType as per Rte_Type.h]
  @param[in]       das_input_data : Pointer to driver assistant system input structure
                    das_input_data->VEHICLE_SPEED : Ego speed with factor Velocity_s [full range of datatype sint16] cm/s
  @param[in]       pSLA_HMI_Data : Pointer to Data struct SLA HMI

  @param[in,out]   cc_driver_requests : Pointer to driver request input structure
                    cc_driver_requests->DRIVER_OPERATIONS.SPEED_LIMIT_ACCEPTED : Boolean indicating if driver accepted the proposed speed limit [TRUE, FALSE]
  @param[in,out]   cc_input : Pointer to CC Input structure
                    cc_input->VEHICLE_STATUS.SPEED_UNIT_KMH : boolean indicating the speed unit, i.e. KMH or MPH [TRUE, FALSE]
                    cc_input->SLA_INPUT_DATA.SLA_SpeedLimit.u_SpeedLimit : Speed limit after wrapper [full range of datatype uint8]
                    cc_input->SLA_INPUT_DATA.SLA_SpeedLimit.u_SpeedLimitIncOffset : Speed limit inclusive offset after wrapper  [full range of datatype uint8]
                    cc_input->SLA_INPUT_DATA.SLA_SpeedLimit.u_SpeedLimitDist : Speed limit distance after wrapper with factor Scale_10 [t_u_DistanceLong as per Rte_Type.h]m
                    cc_input->SLA_INPUT_DATA.SLA_SpeedLimit.SpeedLimitType.b_SLA_CONTROL_BEFOR_LIMIT : Type of reaction to speed limit [true, false]
                    cc_input->SLA_INPUT_DATA.SLA_SpeedLimit.SpeedLimitType.b_SLA_CONTROL_AFTER_LIMIT : Type of reaction to speed limit [true, false]
                    cc_input->SLA_INPUT_DATA.SLA_InputStatus.b_SLA_SET_ENGAGED : Speed limit support function engage state [true, false]
                    cc_input->SLA_INPUT_DATA.SLA_InputStatus.b_SLA_SET_AUTOMATIC : SLA setting: manual or automatic after wrapper [true, false]
                    cc_input->SLA_INPUT_DATA.SLA_InputStatus.b_SLA_SPEED_ABORTED : boolean indicating if next speed limit has been aborted [true, false]
                    cc_input->SLA_INPUT_DATA.SLA_InputStatus.b_SLA_SPEED_ACCEPTED : boolean indicating if the new speed limit was accepted [TRUE, FALSE]
                    cc_input->SLA_INPUT_DATA.SLA_InputStatus.b_SLA_NEW_SPEED_AVAILABLE : boolean indicating if new valid speed limit available [TRUE, FALSE]

  @glob_in         b_SpeedLimitSavedForRetake
  @glob_out        SLA_SpeedLimitNow : Struct for saving currently valid SLA speed limit [t_SLA_SpeedLimit as per cc_ext.h]
  @glob_out        b_NewUnrestictedSign
  @glob_out        uiSLA_ManUsageTimer
  @glob_out        uiSLA_MsgDisplayTimer
  @glob_out        Max_sla_speed
  @glob_out        Min_sla_speed
  @glob_out        b_ImplicitSpeedZone    
  @glob_out        b_ImplicitSpeedZoneEntry      

  @c_switch_part   -
  @c_switch_full   FCT_CFG_SLA_FEATURE : Switch for enabling SLA Support functions
  @c_switch_full   FCT_CFG_LOPC_COMPONENT : Configuration switch for enabling LOPC processing

  @pre             -
  @post            -

  @created         08.06.2016
  @changed         22.07.2019

  @author          Simon Sinnstein | simon.sinnstein@continental-corporation.com | +49 (8382) 9699-160
*************************************************************************************************************************/
static void KMC_v_SLAInputWrapper( const times_t cycle_time,
                                  const LongCtrlInput_t* pLongCtrlResp,
                                  const SLAData_t* pSLAInputData,
                                  const cart_das_input_data_t* das_input_data,
                                  t_SLA_HMI_Data* pSLA_HMI_Data,
                                  cc_driver_requests_t* cc_driver_requests,
                                  cc_input_data_t* cc_input)
{
  t_SLA_InputStatus SLA_StatusSpeedLimitNow = {0}, SLA_StatusSpeedLimitActAccepted = {0};
  t_SLA_SpeedLimit SLA_SpeedLimitActAccepted = {0};
  boolean bSLA_SpeedLimitNowNew, b_NewSLAOffset;
  uint32 uSpeedLimitNowTemp;
  uint8 uSpeedLimitNowInput;
  sint8 s_SLAOffset;
  sint8 s_MaxSLAOffset;

  bSLA_SpeedLimitNowNew = FALSE;
#if (defined(SLAData_INTFVER))
  uSpeedLimitNowInput = pSLAInputData->u_SLA_SpeedLimitNow;
#elif (FCT_LONG_CTRL_INPUT_INTFVER < 37u)
  uSpeedLimitNowInput = pLongCtrlResp->SLA_Input.u_SLA_SpeedLimitNow;
#endif

  /* If SLA support function is active proceed */
  if ((pLongCtrlResp->SLA_Input.e_SLA_Setting != SLA_CFG_OFF) && (ACC_WorkMode_Status != ACC_WorkMode_Status_AutoFollow))
  {
#if (KMC_CFG_SLA_EXPLICIT_SIGNS_ONLY)
    cc_input->SLA_INPUT_DATA.SLA_InputStatus.b_SLA_SET_AUTOMATIC = FALSE;
#else
    /* Determine the SLA setting, depending of HMI setting in the vehicle */
    if (pLongCtrlResp->SLA_Input.e_SLA_Setting == SLA_CFG_MANUAL) 
    {
      cc_input->SLA_INPUT_DATA.SLA_InputStatus.b_SLA_SET_AUTOMATIC = FALSE;
    }
    else
    {
      if(cc_input->SLA_INPUT_DATA.SLA_InputStatus.b_SLA_SET_AUTOMATIC == FALSE)
      {
        cc_driver_requests->DRIVER_OPERATIONS.SPEED_LIMIT_ACCEPTED = TRUE; /* At first engagement, existing SLA speed is accepted */
      }
      cc_input->SLA_INPUT_DATA.SLA_InputStatus.b_SLA_SET_AUTOMATIC = TRUE;
    }
#endif

    /* Convert speed limit in unit of vehicle HMI */
    if((cc_input->VEHICLE_STATUS.SPEED_UNIT_KMH == TRUE)&&
#if (defined(SLAData_INTFVER))
      (pSLAInputData->e_SLA_SpeedLimitUnit == SPD_UNIT_MPH)
#elif (FCT_LONG_CTRL_INPUT_INTFVER < 37u)
      (pLongCtrlResp->SLA_Input.e_SLA_SpeedLimitUnit == SPD_UNIT_MPH)
#endif
      )
    {
      if(uSpeedLimitNowInput != SLA_UNRESTRICTED_SPEED)
      {
        uSpeedLimitNowTemp = (uint32)uSpeedLimitNowInput * (uint32)Speed_conv_factor_kmh;
        uSpeedLimitNowTemp+= (uint32)Speed_conv_factor_mph / (sint32)2;
        uSpeedLimitNowTemp/= (uint32)Speed_conv_factor_mph;
      }
      else
      {
        uSpeedLimitNowTemp = uSpeedLimitNowInput;
      }
    }
    else if((cc_input->VEHICLE_STATUS.SPEED_UNIT_KMH == FALSE)&&
#if (defined(SLAData_INTFVER))
      (pSLAInputData->e_SLA_SpeedLimitUnit == SPD_UNIT_KMH)
#elif (FCT_LONG_CTRL_INPUT_INTFVER < 37u)
      (pLongCtrlResp->SLA_Input.e_SLA_SpeedLimitUnit == SPD_UNIT_KMH)
#endif
      )
    {
      if(uSpeedLimitNowInput != SLA_UNRESTRICTED_SPEED)
      {
        uSpeedLimitNowTemp = (uint32)uSpeedLimitNowInput * (uint32)Speed_conv_factor_mph;
        uSpeedLimitNowTemp+= (uint32)Speed_conv_factor_kmh / (sint32)2;
        uSpeedLimitNowTemp/= (uint32)Speed_conv_factor_kmh;
      }
      else
      {
        uSpeedLimitNowTemp = uSpeedLimitNowInput;
      }
    }
    else
    {
      uSpeedLimitNowTemp = uSpeedLimitNowInput;
    }
    /* Set max ranges for uint8 conversion */
    uSpeedLimitNowTemp = (uint32)MAT_LIM((sint32)uSpeedLimitNowTemp, (sint32)0, (sint32)UINT8_MAX_RANGE);

    SWITCH_SET_COUNTER(cycle_time, &uiSLA_ManUsageTimer); /* Timer decrementation */

    /* Previous Now speed limit */
    if((uSpeedLimitNowTemp != SLA_SpeedLimitNow.u_SpeedLimit)
      &&(uSpeedLimitNowTemp != 0u))
    {
      bSLA_SpeedLimitNowNew = TRUE;
      if(uSpeedLimitNowTemp == SLA_UNRESTRICTED_SPEED)
      { /* If new sign is unrestricted, flag is set */
        b_NewUnrestictedSign = TRUE;
      }
      else
      {
        b_NewUnrestictedSign = FALSE;
      }
    }

    /* Fill speed limit data */
    SLA_SpeedLimitNow.u_SpeedLimit = (setspeed_t)uSpeedLimitNowTemp;
    SLA_SpeedLimitActAccepted = pSLA_HMI_Data->SLA_SpeedLimitActualAccepted;
    SLA_SpeedLimitNow.u_SpeedLimitIncOffset = SLA_SpeedLimitNow.u_SpeedLimit;                 /* Reset of speedlimit offset */
    SLA_SpeedLimitActAccepted.u_SpeedLimitIncOffset = SLA_SpeedLimitActAccepted.u_SpeedLimit; /* Reset of speedlimit offset */
    SLA_SpeedLimitNow.u_SpeedLimitDistance = 0u;
    SLA_SpeedLimitActAccepted.u_SpeedLimitDistance = 0u;
    SLA_SpeedLimitNow.SpeedLimitType.b_SLA_CONTROL_AFTER_LIMIT = TRUE;
    SLA_SpeedLimitNow.SpeedLimitType.b_SLA_CONTROL_BEFOR_LIMIT = FALSE;
    SLA_SpeedLimitActAccepted.SpeedLimitType.b_SLA_CONTROL_AFTER_LIMIT = TRUE;
    SLA_SpeedLimitActAccepted.SpeedLimitType.b_SLA_CONTROL_BEFOR_LIMIT = FALSE;  
    

    /* Offset setting based on driver offset selection */
    if (cc_input->VEHICLE_STATUS.SPEED_UNIT_KMH == TRUE)
    {
      s_MaxSLAOffset = MAX_SLA_OFFSET_KPH;
      s_SLAOffset = (sint8)MAT_LIM(pLongCtrlResp->SLA_Input.s_SLA_SpeedOffset, (-1)*s_MaxSLAOffset, s_MaxSLAOffset);
      Min_sla_speed = MIN_SLA_SPEED_KPH;
      Max_sla_speed = MAX_SLA_SPEED_KPH;
    } 
    else
    {
      s_MaxSLAOffset = MAX_SLA_OFFSET_MPH;
      s_SLAOffset = (sint8)MAT_LIM(pLongCtrlResp->SLA_Input.s_SLA_SpeedOffset, (-1)*s_MaxSLAOffset, s_MaxSLAOffset);
      Min_sla_speed = MIN_SLA_SPEED_MPH;
      Max_sla_speed = MAX_SLA_SPEED_MPH;
    }
      
    if(pSLA_HMI_Data->s_SLA_Offset != s_SLAOffset)
    {
      b_NewSLAOffset = TRUE;
#if (KMC_CFG_SLA_EXPLICIT_SIGNS_ONLY == SWITCH_OFF)
      if (b_SpeedLimitSavedForRetake == TRUE)
      { /* Speed for retaking is recalculated whenever offset is changed */
        pSLA_HMI_Data->u_SLA_DriverLastSetSpeed = pSLA_HMI_Data->u_SLA_DriverLastSetSpeed + s_SLAOffset - pSLA_HMI_Data->s_SLA_Offset;
      }
#endif  /* KMC_CFG_SLA_EXPLICIT_SIGNS_ONLY */
    }
    else
    {
      b_NewSLAOffset = FALSE;
    }

    /* Set offset to the current speed limits */
    pSLA_HMI_Data->s_SLA_Offset = s_SLAOffset;
    pSLA_HMI_Data->SLA_Event.b_SLA_WARNING = FALSE; /* Flag reset for current cycle */

    if(SLA_SpeedLimitNow.u_SpeedLimit <= SLA_INTIALIZE_SPEED)
    {
      /* No speedlimit input. Do nothing */
    }
    else if (SLA_SpeedLimitNow.u_SpeedLimit < Min_sla_speed)
    {
      pSLA_HMI_Data->SLA_Event.b_SLA_WARNING = TRUE;
      SLA_SpeedLimitNow.u_SpeedLimitIncOffset = Min_sla_speed;
    } 
    else if(SLA_SpeedLimitNow.u_SpeedLimit <= Max_sla_speed)
    {
      SLA_SpeedLimitNow.u_SpeedLimitIncOffset = (setspeed_t)MAT_MIN(SLA_SpeedLimitNow.u_SpeedLimit + s_SLAOffset, 
                                                                    Max_sla_speed + s_MaxSLAOffset);
    }
    else
    {
      /* Unrestricted speedlimit. Do nothing */
    }

    if(SLA_SpeedLimitActAccepted.u_SpeedLimit <= SLA_INTIALIZE_SPEED)
    {
      /* No speedlimit input. Do nothing */
    }
    else if (SLA_SpeedLimitActAccepted.u_SpeedLimit < Min_sla_speed)
    {
      pSLA_HMI_Data->SLA_Event.b_SLA_WARNING = TRUE;
      SLA_SpeedLimitActAccepted.u_SpeedLimitIncOffset = Min_sla_speed;
    } 
    else if(SLA_SpeedLimitActAccepted.u_SpeedLimit <= Max_sla_speed)
    {
      SLA_SpeedLimitActAccepted.u_SpeedLimitIncOffset = (setspeed_t)MAT_MIN(SLA_SpeedLimitActAccepted.u_SpeedLimit + s_SLAOffset, 
                                                                            Max_sla_speed + s_MaxSLAOffset);
    }
    else
    {
      /* Unrestricted speedlimit. Do nothing */
    }

    /* end conversion */

    /* Detection of explicit and implicit traffic sign zone */
#if (KMC_CFG_SLA_EXPLICIT_SIGNS_ONLY == SWITCH_OFF)
    if(bSLA_SpeedLimitNowNew)
    {
      if (b_ImplicitSpeedZone == FALSE)
      { /* Currently in zone with valid explicit speed limit sign */
        if(     /* Previous speed limit is removed */
            (SLA_SpeedLimitNow.u_SpeedLimit == SLA_UNRESTRICTED_SPEED)
            ||  /* Highway zone */
            ((pSLAInputData->e_StreetType == NAV_STT_FEDERAL_HIGHWAY) && 
              (SLA_SpeedLimitNow.u_SpeedLimit == SLA_SPEED_HIGHWAY)) 
            ||  /* City zone */
            ((pSLAInputData->e_StreetType == NAV_STT_URBAN_BIDIRECTION) && 
              (SLA_SpeedLimitNow.u_SpeedLimit == SLA_SPEED_URBAN))  
          )
        {
          b_ImplicitSpeedZone = TRUE;
          b_ImplicitSpeedZoneEntry = TRUE;
        }
      } 
      else
      { /* Currently in zone without explicit speed limit sign */
        if( /* Highway zone */
            ((pSLAInputData->e_StreetType == NAV_STT_FEDERAL_HIGHWAY) && 
              (SLA_SpeedLimitNow.u_SpeedLimit == SLA_SPEED_HIGHWAY)) 
            ||  /* City zone */
            ((pSLAInputData->e_StreetType == NAV_STT_URBAN_BIDIRECTION) && 
              (SLA_SpeedLimitNow.u_SpeedLimit == SLA_SPEED_URBAN)) 
          )
        {
          b_ImplicitSpeedZoneEntry = TRUE;
        }

        if( /* Detection of speed limit to trigger explicit speed limit zone */
            (SLA_SpeedLimitNow.u_SpeedLimit > SLA_INTIALIZE_SPEED) &&
            (SLA_SpeedLimitNow.u_SpeedLimit != SLA_UNRESTRICTED_SPEED) &&
            (SLA_SpeedLimitNow.u_SpeedLimit != SLA_SPEED_URBAN) &&
            (SLA_SpeedLimitNow.u_SpeedLimit != SLA_SPEED_HIGHWAY)
          )
        {
          b_ImplicitSpeedZone = FALSE;
        }
      }
    } /* New Now speed limit */
#endif

    if((cc_driver_requests->CONTROL_STATE == Cc_cc_active) || (cc_driver_requests->CONTROL_STATE == Cc_cc_override))
    {
      cc_input->SLA_INPUT_DATA.SLA_InputStatus.b_SLA_SET_ENGAGED = TRUE; /* ACC SLA support function is engaged */
    }
    else
    {
      cc_input->SLA_INPUT_DATA.SLA_InputStatus.b_SLA_SET_ENGAGED = FALSE; /* ACC SLA support function is disengaged */
    }

    /* If SLA engaged: only new speed limit will be accepted, reset SLA variables */
    if(cc_driver_requests->CONTROL_STATE == Cc_cc_engage)
    {
      pSLA_HMI_Data->SLA_SpeedLimitActualAccepted.u_SpeedLimit = 0;
      pSLA_HMI_Data->SLA_SpeedLimitActualAccepted.u_SpeedLimitIncOffset = 0;
      pSLA_HMI_Data->s_SLA_Offset = 0;
      pSLA_HMI_Data->SLA_SpeedLimitActualAccepted.SpeedLimitType.b_SLA_CONTROL_AFTER_LIMIT = FALSE;
      pSLA_HMI_Data->SLA_SpeedLimitActualAccepted.SpeedLimitType.b_SLA_CONTROL_BEFOR_LIMIT = FALSE;
      pSLA_HMI_Data->SLA_SpeedLimitActualAccepted.u_SpeedLimitDistance = 0;
      pSLA_HMI_Data->u_SLA_DriverLastSetSpeed = 0;
      pSLA_HMI_Data->u_SLA_LastSetSpeedForTakeOver = 0;
      pSLA_HMI_Data->u_SLA_SpeedLimitLastAccepted = 0;
      pSLA_HMI_Data->u_SLA_SpeedLimitLastDeclined = 0;
      pSLA_HMI_Data->e_SLA_State = SLA_STATE_IDLE;

      uiSLA_MsgDisplayTimer = 0u;
      uiSLA_ManUsageTimer = 0u;
    }    

    /* Check each speed limit (inclusive offsets) against its acceptance criteria */
    KMC_v_SLADetermineSpeedlimitState(cc_input, pSLA_HMI_Data, cc_driver_requests, &SLA_SpeedLimitNow, &SLA_StatusSpeedLimitNow);
    KMC_v_SLADetermineSpeedlimitState(cc_input, pSLA_HMI_Data, cc_driver_requests, &SLA_SpeedLimitActAccepted, &SLA_StatusSpeedLimitActAccepted);

    if(cc_input->SLA_INPUT_DATA.SLA_InputStatus.b_SLA_SET_AUTOMATIC == FALSE)
    { /* SLA Manual mode */

      if( /* Decision to accept speeds for manual takeover for display to driver */
          ((bSLA_SpeedLimitNowNew == TRUE) && (SLA_StatusSpeedLimitNow.b_SLA_NEW_SPEED_AVAILABLE == TRUE))
          ||
          (SLA_StatusSpeedLimitNow.b_SLA_RETAKE_SPEED == TRUE)
        )
      {
        pSLA_HMI_Data->SLA_Event.b_SLA_USAGE_AVAILABLE = TRUE; /* Whenever new Now Limit is recognized, buttons be used for SLA only */
        uiSLA_ManUsageTimer = Cc_sla_manual_usage_time; /* Timer started for duration of SLA manual availability */
      }

      if((uiSLA_ManUsageTimer == 0) && (pSLA_HMI_Data->SLA_Event.b_SLA_USAGE_AVAILABLE == TRUE))
      {
        pSLA_HMI_Data->SLA_Event.b_SLA_USAGE_AVAILABLE = FALSE; /* At end of timer, Resume button is to be used for +1 function and not SLA */
        b_NewUnrestictedSign = FALSE; /* Reset at end of timer */
      }
    }
    else
    { /* SLA auto mode */
      if(
          (cc_driver_requests->CC_SETSPEED == pSLA_HMI_Data->SLA_SpeedLimitActualAccepted.u_SpeedLimitIncOffset) 
          && (pSLA_HMI_Data->e_SLA_State == SLA_STATE_ACCEPTED)
        )
      { /* Vehicle set speed is same as SLA accepted speed which should mean, sla is actively used. SLA State would still be Idle */
        pSLA_HMI_Data->SLA_Event.b_SLA_USAGE_AVAILABLE = TRUE; /* Driver operations used for SLA function */
        uiSLA_ManUsageTimer = Cc_sla_manual_usage_time; /* Timer started for duration of SLA manual availability */
      }
      if((uiSLA_ManUsageTimer == 0) && (pSLA_HMI_Data->SLA_Event.b_SLA_USAGE_AVAILABLE == TRUE))
      {
        pSLA_HMI_Data->SLA_Event.b_SLA_USAGE_AVAILABLE = FALSE; /* At end of timer, Resume button is to be used for +1 function and not SLA */
      }
    }

    /* Determine valid relevant speed limit */
    if(
        (b_NewSLAOffset == TRUE) &&
        (SLA_StatusSpeedLimitActAccepted.b_SLA_SPEED_ACCEPTED == TRUE) /* Speed limit accepted */
      )
    { /* the next speed limit has higher prio */
      cc_input->SLA_INPUT_DATA.SLA_SpeedLimit.u_SpeedLimit = SLA_SpeedLimitActAccepted.u_SpeedLimit;
      cc_input->SLA_INPUT_DATA.SLA_SpeedLimit.u_SpeedLimitIncOffset = SLA_SpeedLimitActAccepted.u_SpeedLimitIncOffset;
      cc_input->SLA_INPUT_DATA.SLA_SpeedLimit.u_SpeedLimitDistance = SLA_SpeedLimitActAccepted.u_SpeedLimitDistance;
      cc_input->SLA_INPUT_DATA.SLA_SpeedLimit.SpeedLimitType = SLA_SpeedLimitActAccepted.SpeedLimitType;
      cc_input->SLA_INPUT_DATA.SLA_InputStatus.b_SLA_NEW_SPEED_AVAILABLE = SLA_StatusSpeedLimitActAccepted.b_SLA_NEW_SPEED_AVAILABLE;
      cc_input->SLA_INPUT_DATA.SLA_InputStatus.b_SLA_SPEED_ACCEPTED = TRUE;
      /* New SLA offset has been implemented */

      cc_input->SLA_INPUT_DATA.SLA_InputStatus.b_SLA_SPEED_ABORTED = FALSE;
    }
    else
      if(SLA_SpeedLimitNow.u_SpeedLimit != SLA_INTIALIZE_SPEED) /*!< Valid speed limit available */
      { /* the actual speed limit has higher prio */
        cc_input->SLA_INPUT_DATA.SLA_SpeedLimit.u_SpeedLimit = SLA_SpeedLimitNow.u_SpeedLimit;
        cc_input->SLA_INPUT_DATA.SLA_SpeedLimit.u_SpeedLimitIncOffset = SLA_SpeedLimitNow.u_SpeedLimitIncOffset;
        cc_input->SLA_INPUT_DATA.SLA_SpeedLimit.u_SpeedLimitDistance = SLA_SpeedLimitNow.u_SpeedLimitDistance;
        cc_input->SLA_INPUT_DATA.SLA_SpeedLimit.SpeedLimitType = SLA_SpeedLimitNow.SpeedLimitType;
        cc_input->SLA_INPUT_DATA.SLA_InputStatus.b_SLA_NEW_SPEED_AVAILABLE = SLA_StatusSpeedLimitNow.b_SLA_NEW_SPEED_AVAILABLE;
        if(SLA_StatusSpeedLimitNow.b_SLA_SPEED_ACCEPTED == TRUE)
        { /* Current now speed has been accepted. Either manual or automatic */
          cc_input->SLA_INPUT_DATA.SLA_InputStatus.b_SLA_SPEED_ACCEPTED = TRUE;
        }
        else if((pSLA_HMI_Data->e_SLA_State == SLA_STATE_ACCEPTED) || (bSLA_SpeedLimitNowNew ==  TRUE))// PRQA S 2004 
	      /* date: 2018-03-22, reviewer: Ravi Kiran Gurrala, reason: conditions are checking in if and elseif, else is not required*/
        { /* Accepted speed limit has been stored in hmi internal struct, or a new now speed exists and boolean must be initialised */
          cc_input->SLA_INPUT_DATA.SLA_InputStatus.b_SLA_SPEED_ACCEPTED = FALSE;
        }

        cc_input->SLA_INPUT_DATA.SLA_InputStatus.b_SLA_SPEED_ABORTED = FALSE;
      }
      else
      {
        /* no valid speed limit available */
        cc_input->SLA_INPUT_DATA.SLA_SpeedLimit.u_SpeedLimit = 0;
        cc_input->SLA_INPUT_DATA.SLA_SpeedLimit.u_SpeedLimitIncOffset = 0;
        cc_input->SLA_INPUT_DATA.SLA_SpeedLimit.u_SpeedLimitDistance = 0;
        cc_input->SLA_INPUT_DATA.SLA_SpeedLimit.SpeedLimitType.b_SLA_CONTROL_BEFOR_LIMIT = FALSE;
        cc_input->SLA_INPUT_DATA.SLA_SpeedLimit.SpeedLimitType.b_SLA_CONTROL_AFTER_LIMIT = FALSE;
      }
  }
  else
  {
    /* write default values if SLA not engaged */
    cc_input->SLA_INPUT_DATA.SLA_SpeedLimit.u_SpeedLimit = 0;
    cc_input->SLA_INPUT_DATA.SLA_SpeedLimit.u_SpeedLimitIncOffset = 0;
    cc_input->SLA_INPUT_DATA.SLA_SpeedLimit.u_SpeedLimitDistance = 0;
    cc_input->SLA_INPUT_DATA.SLA_SpeedLimit.SpeedLimitType.b_SLA_CONTROL_BEFOR_LIMIT = FALSE;
    cc_input->SLA_INPUT_DATA.SLA_SpeedLimit.SpeedLimitType.b_SLA_CONTROL_AFTER_LIMIT = FALSE;
    cc_input->SLA_INPUT_DATA.SLA_InputStatus.b_SLA_SET_ENGAGED = FALSE;
    cc_input->SLA_INPUT_DATA.SLA_InputStatus.b_SLA_SET_AUTOMATIC = FALSE;
    cc_input->SLA_INPUT_DATA.SLA_InputStatus.b_SLA_SPEED_ABORTED = FALSE;
    cc_input->SLA_INPUT_DATA.SLA_InputStatus.b_SLA_SPEED_ACCEPTED = FALSE;
    cc_input->SLA_INPUT_DATA.SLA_InputStatus.b_SLA_SPEED_DECLINED = FALSE;
    cc_input->SLA_INPUT_DATA.SLA_InputStatus.b_SLA_RETAKE_SPEED = FALSE;
    SLA_SpeedLimitNow.u_SpeedLimit = 0;
    SLA_SpeedLimitNow.u_SpeedLimitIncOffset = 0;
    SLA_SpeedLimitNow.u_SpeedLimitDistance = 0;
    SLA_SpeedLimitNow.SpeedLimitType.b_SLA_CONTROL_AFTER_LIMIT = FALSE;
    SLA_SpeedLimitNow.SpeedLimitType.b_SLA_CONTROL_BEFOR_LIMIT = FALSE;
  }
  _PARAM_UNUSED(cycle_time);
  _PARAM_UNUSED(das_input_data);
}/* PRQA S 7004 */
/* date: 2018-03-26, reviewer: Ravi Kiran Gurrala, reason : Cyclomatic complexity. Not Safety critical*/

/*************************************************************************************************************************
  Functionname:    KMC_v_SLADetermineState                                                                          */ /*!

  @brief           Determination of SLA states, depending of customer specific conditions

  @description     Speed limit validity check, determination if the speed limit can be proposed
                   replace unrestricted speed limit on highway through driver set speed stored on highway

  @startuml
    Start
      Partition KMC_v_SLADetermineState(){
        If (Implicit signs/zones can be detected) Then (True)
          : Implicit zone speed saved on first entry;
          : Setspeed change by driver saved\n when in implicit zone only;
        Else (False)
          : Setspeed change by driver\n saved everytime;
        Endif
        Note right
          b_SLA_SAVE_DRIVER_SETSPEED is set
          to save setspeed from driver at
          u_SLA_DriverLastSetSpeed
        Endnote

        : Driver Input used to decline SLA Speed:
          In auto mode, decline offered when accepted speed is same as
          input or when input is 253 and accepted speed is driverlastsetspeed
          In manual mode, decline possible only before speed is accepted by driver;

        : Modification of Driver setspeed due to\n limited possibility of display in vehicle;


        If (Input speed limit is not 0) Then (True)
          If (Input speed limit is not 253) Then (True)
            : b_SLA_SET_DRIVER_SETSPEED = 0;
          Else (False)
            If (u_SLA_DriverLastSetSpeed is not 0\nAND\nu_SLA_DriverLastSetSpeed is different from setspeed \nAND\nNew Unrestricted sign exists\nAND\nManual mode OR setspeed smaller than u_SLA_DriverLastSetSpeed) then (True)
              : b_SLA_SET_DRIVER_SETSPEED = 1;
              : b_SLA_NEW_SPEED_AVAILABLE = 1;
            Else (False)
              : b_SLA_NEW_SPEED_AVAILABLE = 0;
              : Flag for new unrestricted sign is reset;
              : Reset b_SLA_SET_DRIVER_SETSPEED;
            Endif
          Endif
          
        Else (False)
          : b_SLA_SET_DRIVER_SETSPEED = 0;
        Endif
        Note right
          b_SLA_SET_DRIVER_SETSPEED is set
          to update vehicle setspeed to
          u_SLA_DriverLastSetSpeed
        Endnote
      }
    end
  @enduml


  @return          static void

  @param[in]       pSLAInputData: Pointer to input struct from SLATE [SLAData_t as per Rte_type.h]
  @param[in,out]   cc_input : Pointer to Input structure
                    cc_input->VEHICLE_STATUS.SPEED_UNIT_KMH : boolean indicating the speed unit, i.e. KMH or MPH [TRUE, FALSE]
                    cc_input->SLA_INPUT_DATA.u_SlaSpeedLimit : Speed limit after wrapper [full range of datatype uint8]
                    cc_input->SLA_INPUT_DATA.SLA_InputStatus.b_SLA_SET_AUTOMATIC : SLA setting: manual or automatic after wrapper [true, false]
                    cc_input->SLA_INPUT_DATA.SLA_InputStatus.b_SLA_NEW_SPEED_AVAILABLE : boolean indicating if new valid speed limit available [true, false]
                    cc_input->SLA_INPUT_DATA.SLA_InputStatus.b_SLA_SPEED_ACCEPTED : boolean indicating if the new speed limit was accepted [true, false]
  @param[in,out]   cc_status : Pointer to internal structure for (Adaptive) Cruise Control
                      cc_status->CC_SLA_HMI_DATA.SLA_Event.b_SLA_SAVE_DRIVER_SETSPEED : boolean indicating if the set speed requested by driver shall be saved [true, false]
                      cc_status->CC_DRIVER_REQUESTS.MAX_CC_SETSPEED : Maximal Cruise Control set speed [full range of datatype uint8]
                      cc_status->CC_DRIVER_REQUESTS.MIN_CC_SETSPEED : Minimal Cruise Control set speed [full range of datatype uint8]
                      cc_status->CC_DRIVER_REQUESTS.DRIVER_REQUEST_STATUS.SELECTED_FUNCTION_ACTIVE : boolean indicating if ACC / CC active [true, false]
                      cc_status->CC_SLA_HMI_DATA.u_SLA_SpeedLimitActualAccepted : Accepted speed limit [full range of datatype uint8]
                      cc_status->CC_DRIVER_REQUESTS.CC_SETSPEED : Current Cruise Control set speed [full range of datatype uint8]
                      cc_status->CC_SLA_HMI_DATA.SLA_Event.b_SLA_SET_DRIVER_SETSPEED : boolean indicating, that the saved setspeed requested by driver have to be set [true, false]
                      cc_status->CC_SLA_HMI_DATA.u_SLA_DriverLastSetSpeed : the saved setspeed requested by driver [full range of datatype uint8]
                      cc_status->CC_DRIVER_REQUESTS.DRIVER_OPERATIONS.SPEED_LIMIT_ACCEPTED : boolean indicating if drive accepted the proposed speed limit [true, false]
                      cc_status->CC_DRIVER_REQUESTS.SPEEDOMETER_VEHICLE_SPEED : Current speedometer speed with factor Velocity_s [full range of datatype sint16]
                      cc_status->CC_DRIVER_REQUESTS.DRIVER_OPERATIONS.CC_TAKE_ACTUAL_SPEED : Boolean, if TRUE take actual vehicle speedometer speed as CC_SETSPEED [TRUE, FALSE]
                      cc_status->CC_DRIVER_REQUESTS.DRIVER_OPERATIONS.CC_INCREASE_SET_SPEED : Boolean if constant increasing of set speed [TRUE, FALSE]
                      cc_status->CC_DRIVER_REQUESTS.DRIVER_OPERATIONS.CC_DECREASE_SET_SPEED : Boolean if constant decreasing of set speed [TRUE, FALSE]

  @glob_in         b_ImplicitSpeedZone    
  @glob_out        b_NewUnrestictedSign
  @glob_out        uiSLA_ManUsageTimer
  @glob_out        uiSLA_MsgDisplayTimer
  @glob_out        Max_sla_speed
  @glob_out        Min_sla_speed
  @glob_out        SLA_SpeedLimitNow  
  @glob_out        b_ImplicitSpeedZoneEntry
  @glob_out        b_SpeedLimitSavedForRetake

  @c_switch_full   FCT_CFG_SLA_FEATURE : Switch for enabling SLA Support functions
  @c_switch_full   FCT_CFG_LOPC_COMPONENT : Configuration switch for enabling LOPC processing

  @pre             -
  @post            -

  @created         08.06.2016
  @changed         22.07.2019

  @author          Simon Sinnstein | simon.sinnstein@continental-corporation.com | +49 (8382) 9699-160
*************************************************************************************************************************/
static void KMC_v_SLADetermineState(const SLAData_t* pSLAInputData,
                                    cc_input_data_t* cc_input,
                                    cc_status_t *cc_status)
{
  /* set speed requested from driver has to be stored only in zones with implicit limits */
  if(cc_status->CC_DRIVER_REQUESTS.ENGAGEMENT_CONDITIONS.CC_ENGAGEMENT_STAT == TRUE)
  {

#if (KMC_CFG_SLA_EXPLICIT_SIGNS_ONLY == SWITCH_OFF)
    if(b_ImplicitSpeedZone == TRUE)
    {
#endif
      if(
          (cc_status->CC_SLA_HMI_DATA.u_SLA_DriverLastSetSpeed == SLA_INTIALIZE_SPEED)
          /* Driver is updating setspeed manually */
          ||(cc_status->CC_DRIVER_REQUESTS.DRIVER_OPERATIONS.CC_DECREASE_SET_SPEED == TRUE)
          ||(cc_status->CC_DRIVER_REQUESTS.DRIVER_OPERATIONS.CC_INCREASE_SET_SPEED == TRUE)
          ||(cc_status->CC_DRIVER_REQUESTS.DRIVER_OPERATIONS.CC_TAKE_ACTUAL_SPEED == TRUE)
        )
      {
        cc_status->CC_SLA_HMI_DATA.SLA_Event.b_SLA_SAVE_DRIVER_SETSPEED = TRUE;
#if (KMC_CFG_SLA_EXPLICIT_SIGNS_ONLY == SWITCH_OFF)
        b_SpeedLimitSavedForRetake = FALSE;
#endif
      }
      else
      {
        cc_status->CC_SLA_HMI_DATA.SLA_Event.b_SLA_SAVE_DRIVER_SETSPEED = FALSE;
      }
      cc_status->CC_SLA_HMI_DATA.SLA_Event.b_SLA_DELETE_DRIVER_SETSPEED = FALSE;

#if (KMC_CFG_SLA_EXPLICIT_SIGNS_ONLY == SWITCH_OFF)
      /* Save current implicit speed limit to u_SLA_DriverLastSetSpeed to be reused */
      /* If first entry into Implicit speed limit zone and Speed limit is not 253 */
      if(( b_ImplicitSpeedZoneEntry == TRUE ) && (cc_input->SLA_INPUT_DATA.SLA_SpeedLimit.u_SpeedLimit != SLA_UNRESTRICTED_SPEED))
      {
        cc_status->CC_SLA_HMI_DATA.u_SLA_DriverLastSetSpeed = cc_input->SLA_INPUT_DATA.SLA_SpeedLimit.u_SpeedLimitIncOffset;
        b_ImplicitSpeedZoneEntry = FALSE;
        b_SpeedLimitSavedForRetake = TRUE;
      }

    } /* Implicit Zone Flag */
#endif  /*KMC_CFG_SLA_EXPLICIT_SIGNS_ONLY*/

  }
  else
  {
    cc_status->CC_SLA_HMI_DATA.SLA_Event.b_SLA_SAVE_DRIVER_SETSPEED = FALSE;
    cc_status->CC_SLA_HMI_DATA.SLA_Event.b_SLA_DELETE_DRIVER_SETSPEED = TRUE;
  }


  /* Usage of driver input to decline SLA speed */
  if(
      (cc_status->CC_DRIVER_REQUESTS.DRIVER_OPERATIONS.SPEED_LIMIT_DECLINED == TRUE) /* Driver initiated declination */
      &&
      (
        (cc_input->SLA_INPUT_DATA.SLA_InputStatus.b_SLA_SET_AUTOMATIC == FALSE) /* Manual mode */
        ||
        (/* In auto mode, declined offered when accepted speed is same as input or when input is 253 and accepted speed is driverlastsetspeed */
          (cc_input->SLA_INPUT_DATA.SLA_InputStatus.b_SLA_SET_AUTOMATIC == TRUE) 
          && 
          (
            (cc_status->CC_SLA_HMI_DATA.SLA_SpeedLimitActualAccepted.u_SpeedLimit == cc_input->SLA_INPUT_DATA.SLA_SpeedLimit.u_SpeedLimit)
            ||
            ((cc_status->CC_SLA_HMI_DATA.SLA_SpeedLimitActualAccepted.u_SpeedLimitIncOffset == cc_status->CC_SLA_HMI_DATA.u_SLA_DriverLastSetSpeed) 
              &&(cc_input->SLA_INPUT_DATA.SLA_SpeedLimit.u_SpeedLimit == SLA_UNRESTRICTED_SPEED))
          )
        )
      )
    )
  {
    cc_input->SLA_INPUT_DATA.SLA_InputStatus.b_SLA_SPEED_DECLINED = TRUE;
  }
  else
  { /* Reset */
    cc_input->SLA_INPUT_DATA.SLA_InputStatus.b_SLA_SPEED_DECLINED = FALSE;
  }


  /* Check if new SLA speed limit on interface available
     on highway and unrestricted limit (end of speed limit sign) the driver set speed have to be proposed */
  if((cc_status->CC_DRIVER_REQUESTS.DRIVER_REQUEST_STATUS.SELECTED_FUNCTION_ACTIVE == TRUE)
     &&(cc_input->SLA_INPUT_DATA.SLA_SpeedLimit.u_SpeedLimit != SLA_INTIALIZE_SPEED)
    )
  {
    if(cc_input->SLA_INPUT_DATA.SLA_SpeedLimit.u_SpeedLimit != SLA_UNRESTRICTED_SPEED)
    {
      cc_status->CC_SLA_HMI_DATA.SLA_Event.b_SLA_SET_DRIVER_SETSPEED = FALSE;
    }
    else
    { /*! If speed limit is unrestricted */
      if(
          /* Valid driver set speed is available */
          (cc_status->CC_SLA_HMI_DATA.u_SLA_DriverLastSetSpeed != SLA_INTIALIZE_SPEED) &&
          /* the actual set speed deviate from driver speed */
          (cc_status->CC_DRIVER_REQUESTS.CC_SETSPEED != cc_status->CC_SLA_HMI_DATA.u_SLA_DriverLastSetSpeed) &&
          /* Unrestricted speed limit is newly present */
          (b_NewUnrestictedSign == TRUE) &&
          ( /* In auto mode, increase of speedlimit should not lead to reduction of setspeed */
            ((cc_input->SLA_INPUT_DATA.SLA_InputStatus.b_SLA_SET_AUTOMATIC == TRUE) &&
              (cc_status->CC_SLA_HMI_DATA.u_SLA_DriverLastSetSpeed > cc_status->CC_DRIVER_REQUESTS.CC_SETSPEED))
            ||
            (cc_input->SLA_INPUT_DATA.SLA_InputStatus.b_SLA_SET_AUTOMATIC == FALSE)
          )
        )
      { /*! The driver speed have to be set */
        cc_input->SLA_INPUT_DATA.SLA_InputStatus.b_SLA_NEW_SPEED_AVAILABLE = TRUE;
        cc_status->CC_SLA_HMI_DATA.SLA_Event.b_SLA_SET_DRIVER_SETSPEED = TRUE;
      }
      else
      { /* No saved Driver last setspeed available */
        cc_input->SLA_INPUT_DATA.SLA_InputStatus.b_SLA_NEW_SPEED_AVAILABLE = FALSE;
        b_NewUnrestictedSign = FALSE; /* Reset for unrestricted speed usage */
        /* Reset b_SLA_SET_DRIVER_SETSPEED flag */
        if(cc_status->CC_DRIVER_REQUESTS.CC_SETSPEED == cc_status->CC_SLA_HMI_DATA.u_SLA_DriverLastSetSpeed)
        {
          cc_status->CC_SLA_HMI_DATA.SLA_Event.b_SLA_SET_DRIVER_SETSPEED = FALSE;
        }

      }
    }
  }
  else
  {
    cc_input->SLA_INPUT_DATA.SLA_InputStatus.b_SLA_NEW_SPEED_AVAILABLE = FALSE;
    cc_input->SLA_INPUT_DATA.SLA_InputStatus.b_SLA_SPEED_ACCEPTED = FALSE;
    cc_status->CC_SLA_HMI_DATA.SLA_Event.b_SLA_SET_DRIVER_SETSPEED = FALSE;
  }

  _PARAM_UNUSED(pSLAInputData);
}/* PRQA S 7004 */
/* date: 2018-03-26, reviewer: Ravi Kiran Gurrala, reason : Cyclomatic complexity. Not Safety critical*/
#endif /* (FCT_CFG_SLA_FEATURE) */


/*****************************************************************************
  @fn             KMC_v_InformDriver */ /*!

  @description    Process all data to be displayed to the driver for a specific customer.

@startuml
Start
Partition KMC_v_InformDriver(){
: Process all data to be displayed to the driver for a specific customer;
If (Acc is in Active , Disengage, Decel only state) then (true)
: Set ACC alert if alert is calculated from LOHP;
endif
: Display ACC objects;
: Inform driver about drive off situation;
: Map Acc error conditions incase of error;
}
@enduml

                  
  @param[in]      driver_requests
  @param[in]      acc_output
*/ 
#if (LONG_CFG_USE_EXTERN_ACC_STATE_MACHINE)
/*!
  @param[in]      cc_input
  @param[in]      das_input  
*/ 
#endif
/*!
  @param[in]      display_object
  @param[in]      error_data
  @param[in]      driver_information
  @param[in]      das_output

  @return         void

*****************************************************************************/
static void KMC_v_InformDriver(const cc_driver_requests_t* driver_requests,
                               const acc_output_data_t* acc_output,
#if (LONG_CFG_USE_EXTERN_ACC_STATE_MACHINE)
                               const cc_input_data_t* cc_input,
                               const cart_das_input_data_t* das_input,
#endif
                               const acc_object_t* display_object,
                               const cc_error_data_t* error_data,
                               cc_driver_information_t* driver_information,
                               cart_das_output_data_t* das_output)
{
  static times_t ObjectDetection_Counter;
  static uint8 ObjectDetection_Status;

  driver_information->HEADWAY_SETTING = acc_output->HEADWAY_SETTING;
  driver_information->OPERATIONAL_MODE = driver_requests->OPERATIONAL_MODE;
  driver_information->BIT_ACC_ALERT = FALSE;

  if(driver_information->BIT_ACC_ALERT == FALSE)
  {
#if (LONG_CFG_USE_EXTERN_ACC_STATE_MACHINE)
    /* Check conditions for alert output */
    if(
        (cc_input->pENGINE_ECU_INPUT->XACCACT == TRUE)
        &&
        /* During override, no Alert allowed */
        (das_input->LODM_STAT.OVERRIDE_ACCEL == FALSE)
      )
    {
      /* With ACC active only takeover */
      if(
          (acc_output->ACC_OUTPUT_STATUS.ALERT == TRUE)
          ||
          (error_data->DISENGAGE_SIGNAL == TRUE)
        )
      {
        /* Alert output active */
        driver_information->BIT_ACC_ALERT = TRUE;
      }
    }
#else /* LONG_CFG_USE_EXTERN_ACC_STATE_MACHINE */
    /* AlertLevel and ACCActive/ACCOverride -Flag */
    if(
        (driver_requests->CONTROL_STATE == Cc_cc_active)
        ||
        (driver_requests->CONTROL_STATE == Cc_cc_disengage)
        ||
        (driver_requests->CONTROL_STATE == Cc_cc_decel_only)
		/* No alert for ACC disengagement (for Venucia)
        ||
        (error_data->DISENGAGE_SIGNAL == TRUE)  // ACC disengaged without driver intervention 
		*/
      )
    {
      /* With ACC active only takeover */
      if (
          (acc_output->ACC_OUTPUT_STATUS.ALERT == TRUE)
		  /* No alert for ACC disengagement (for Venucia)
          ||
          (error_data->DISENGAGE_SIGNAL == TRUE)
		  */
         )
      {
        driver_information->BIT_ACC_ALERT = TRUE;
      }
    }
#endif /* LONG_CFG_USE_EXTERN_ACC_STATE_MACHINE */
  }

  driver_information->BIT_FCA_ALERT = 0u;
  driver_information->BIT_DM_ALERT = 0u;
  driver_information->DM_STATE = 0u;

  driver_information->REQUESTED_DISTANCE = (uint8)MAT_MIN((((sint32)acc_output->REQUESTED_DISTANCE + (Distance_s/2)) / Distance_s), 255);
  //driver_information->RECOMMENDED_SPEED = driver_requests->RECOMMENDED_SPEED; 

	// If Object lost, hold the display for <OBJECTDETECTION_LOSING_DURATION> cycles.
	switch (ObjectDetection_Status)
	{
		case ObjectDetection_Detected:
			if (display_object->AUTOSAR.OBJECT_STATUS.DETECTED == FALSE)
			{
				ObjectDetection_Status = ObjectDetection_Losing;
				ObjectDetection_Counter = 0U;
			}
			break;
		
		case ObjectDetection_Losing:
			if (display_object->AUTOSAR.OBJECT_STATUS.DETECTED == TRUE)
			{
				ObjectDetection_Status = ObjectDetection_Detected;
			}
			else if (ObjectDetection_Counter == OBJECTDETECTION_LOSING_DURATION)
			{
				ObjectDetection_Status = ObjectDetection_Lost;
			}
			else
			{
				ObjectDetection_Counter++;
			}
			break;
			
		case ObjectDetection_Lost:
			if (display_object->AUTOSAR.OBJECT_STATUS.DETECTED == TRUE)
			{
				ObjectDetection_Status = ObjectDetection_Detected;
			}
			break;
			
		default:
			ObjectDetection_Status = ObjectDetection_Lost;
			break;
	}

	if	(
			/*! The display object can be the first one, or any of six objects
				use the switch CFG_FCT_ACC_DISPLAY_ONLY_FIRST_OBJECT to define it */
			//(display_object->AUTOSAR.OBJECT_STATUS.DETECTED == TRUE)
			/*! Add here some additional conditions, if needed */
			
			ObjectDetection_Status == ObjectDetection_Detected
		)
	{
		sint32         help;
		help = display_object->LONG_SPEED;
		help *= (sint32)Speed_conv_factor_kmh;
		help /= (sint32)Factor_s;
		help += (sint32)(Velocity_s / 2);
		help /= (sint32)Velocity_s;
		driver_information->OBJECT_SPEED =  (setspeed_t)MAT_LIM(help,(sint32)0,(sint32)255);
		driver_information->OBJECT_DISTANCE = (uint8)(((uint16)display_object->AUTOSAR.LONG_DISPLACEMENT + (uint16)(Distance_s / 2)) / (uint16)Distance_s);
		driver_information->OBJECT_DETECTED = TRUE;
	}
	else if (ObjectDetection_Status == ObjectDetection_Lost)
	{
		driver_information->OBJECT_SPEED = (setspeed_t)255;
		driver_information->OBJECT_DISTANCE = (uint8)255;
		driver_information->OBJECT_DETECTED = FALSE;
	}
	else // ObjectDetection_Status == ObjectDetection_Losing
	{
		// Hold the display
	}
	
	if (driver_requests->CC_SETSPEED <= driver_requests->MIN_CC_SETSPEED)
	{
		driver_information->SET_SPEED = driver_requests->MIN_CC_SETSPEED;
	}
	else
	{
		driver_information->SET_SPEED = driver_requests->CC_SETSPEED;
	}

#if (FCT_CFG_FSRACC)
  /*Inform Driver about drive off situation*/
  if (
      (driver_requests->ENGAGEMENT_CONDITIONS.DRIVE_OFF_POSSIBLE == TRUE)
      &&
      (Kmc_Standstillstate == StandStillState_StandWait)
	  &&
	  (b_Stand_Still_Request == TRUE)
	  &&
	  (ACC_State != ACC_STAT_OVERRIDE)
     )
  {
    driver_information->ACC_DRIVE_OFF_POSSIBLE = TRUE;
  }
  else
  {
    driver_information->ACC_DRIVE_OFF_POSSIBLE = FALSE;
  }
#endif /*FCT_CFG_FSRACC*/

  driver_information->REPORTED_ERROR = error_data->REPORTED_ERROR;
	if	(
			(error_data->REPORTED_ERROR == Cc_no_error)
			||
			(error_data->REPORTED_ERROR == Cc_performance_degradation)
		)
	{
		das_output->DAS_STAT.DAS_FAIL_IRREVERSABLE = FALSE;
		das_output->DAS_STAT.DAS_FAIL_REVERSABLE = FALSE;
	}
	else
	{
		/*set acc main lamp to  (error)*/
		if (error_data->REPORTED_ERROR == Cc_temp_unavailable)
		{
			das_output->DAS_STAT.DAS_FAIL_IRREVERSABLE = FALSE;
			das_output->DAS_STAT.DAS_FAIL_REVERSABLE = TRUE;
		}
		else
		{
			das_output->DAS_STAT.DAS_FAIL_IRREVERSABLE = TRUE;
			das_output->DAS_STAT.DAS_FAIL_REVERSABLE = FALSE;
		}
	}

  
  /* Signal used for drive off state handling */
  driver_information->DRIVER_CONFIRMATION_NEEDED = FALSE;
}
#endif  /* FCT_CFG_CC */


/*************************************************************************************************************************
  Functionname:    KMC_v_FillVehToSenInfo                                                                           */ /*!

  @brief           Fill FctVeh2SenInfo Port

  @description     Fill FctVeh2SenInfo Port

@startuml
Start
Partition KMC_v_FillVehToSenInfo(){
: Update related to Vehicle to Sensor information port;
  Note right
    Standstill flag
    Override Accel Information
    Current Longitudinal Control velocity
    Current Longitudinal Control Acceleration
    Maximum Acceleration Limit
    Minimum Acceleration Limit
    Drive modes
    Current ACC State
  End note
}
End
@enduml


  @return          static void

  @param[in]       pLongCtrlResp : [LongCtrlInput_t as per Rte_Type.h]
  @param[in]       pLongCtrlResp->KinCtrlDynInput.driver_override_accel_pedal : [true, false]
  @param[in]       pLongCtrlResp->KinCtrlDynInput.longi_initialization_accel : [full range of signed short]
  @param[in]       cc_status : [cc_status_t as per cc_ext.h]
  @param[in]       cc_status->CC_CONTROL_DATA.MAXIMUM_ACCELERATION_LIMIT : [acceleration_t as per Rte_Type.h]
  @param[in]       cc_status->CC_CONTROL_DATA.MINIMUM_ACCELERATION_LIMIT : [acceleration_t as per Rte_Type.h]
  @param[in]       cc_status->CC_DRIVER_REQUESTS.STAND_STILL_TIME : [times_t as per Rte_Type.h]
  @param[in]       cc_status->CC_DRIVER_REQUESTS.CONTROL_STATE : [0, 11]
  @param[in]       cc_status->CC_CONTROL_DATA.DECEL_LIM_OVERRIDE_ACTIVE : [full range of unsigned char]
  @param[in]       cc_status->CC_DRIVER_REQUESTS.ENGAGEMENT_CONDITIONS.CONTROL_TO_RELEVANT_OBJECT : [true, false]
  @param[in]       cc_status->CC_ACCEL_CONTROL_DATA.ACCEL_STATUS.OBJECT_EFFECTIVE : [true, false]
  @param[out]      pFctVehLongOut : [FctVeh2SenInfo_t as per Rte_Type.h]
  @param[out]      pFctVehLongOut->StandStill      : [true, false]
  @param[out]      pFctVehLongOut->OverrideAccel   : [true, false]
  @param[out]      pFctVehLongOut->CurLongCtrlAccel : [acceleration_t as per Rte_Type.h]
  @param[out]      pFctVehLongOut->MaxAccelLimit : [acceleration_t as per Rte_Type.h]
  @param[out]      pFctVehLongOut->MinAccelLimit   : [acceleration_t as per Rte_Type.h]
  @param[out]      pFctVehLongOut->ProbLaneChgLeft : [percentage_t as per Rte_Type.h]
  @param[out]      pFctVehLongOut->ProbLaneChgRight : [percentage_t as per Rte_Type.h]
  @param[out]      pFctVehLongOut->AccOn    : [true, false]
  @param[out]      pFctVehLongOut->DecelLimOverride : [true, false]
  @param[out]      pFctVehLongOut->CtrlToRelevObj   : [true, false]
  @param[out]      pFctVehLongOut->ObjectEffective  : [true, false]

  @glob_in         -
  @glob_out        -
                   
  @c_switch_part   -
  @c_switch_full   FCT_CFG_LOPC_COMPONENT : Configuration switch for enabling LOPC processing
                   
  @pre             -
  @post            -
                   
  @created         -
  @changed         5/4/2016

  @todo            Review this function

  @author         Simon Sinnstein
**************************************************************************** */
static void KMC_v_FillVehToSenInfo(const cc_status_t* cc_status,
                                   const cart_das_input_data_t* das_input_data,
                                   const LongCtrlInput_t* pLongCtrlResp,
                                   FctVeh2SenInfo_t* pFctVehLongOut
                                  )
{
  /* Fill standstill flag. Note: timing and behaviour is the same as in old projects, but clean
  interface used instead of global variables */
  pFctVehLongOut->StandStill          = (boolean)das_input_data->LODM_STAT.STANDSTILL;
  pFctVehLongOut->OverrideAccel       = (boolean)das_input_data->LODM_STAT.OVERRIDE_ACCEL;
  pFctVehLongOut->CurLongCtrlVelocity = das_input_data->VEHICLE_SPEED;
  pFctVehLongOut->CurLongCtrlAccel    = das_input_data->VEHICLE_ACCEL;
  pFctVehLongOut->MaxAccelLimit       = cc_status->CC_CONTROL_DATA.MAXIMUM_ACCELERATION_LIMIT;
  pFctVehLongOut->MinAccelLimit       = cc_status->CC_CONTROL_DATA.MINIMUM_ACCELERATION_LIMIT;
  /* pFctVehLongOut->HeadwaySetting is assigned in KMC_v_InputWrapper */

  /*! Lanechange probability will be provided directly by SLATE
      these signals are not needed any more */
  pFctVehLongOut->ProbLaneChgLeft   = 0u;
  pFctVehLongOut->ProbLaneChgRight  = 0u;

#if (CFG_ACC_LEVER_INPUT)
  pFctVehLongOut->AccOn             = (boolean)((cc_status->CC_DRIVER_REQUESTS.CONTROL_STATE == Cc_cc_active) || (cc_status->CC_DRIVER_REQUESTS.CONTROL_STATE == Cc_cc_engage));
  pFctVehLongOut->AccNotOff         = (boolean)((cc_status->CC_DRIVER_REQUESTS.CONTROL_STATE == Cc_cc_active) || (cc_status->CC_DRIVER_REQUESTS.CONTROL_STATE == Cc_cc_engage) || (cc_status->CC_DRIVER_REQUESTS.CONTROL_STATE == Cc_cc_override));
  _PARAM_UNUSED(pLongCtrlResp);
#else
  /* ACC in control mode */
  pFctVehLongOut->AccOn     = (boolean)(((pLongCtrlResp->Custom.EngineEcuInput.XACCACT) && (cc_status->CC_DRIVER_REQUESTS.ENGAGEMENT_CONDITIONS.DRIVER_OVERRIDE)) == FALSE);
  /* ACC in control or override mode */
  pFctVehLongOut->AccNotOff = (boolean)(pLongCtrlResp->Custom.EngineEcuInput.ACCSTAT == ACCSTAT_ACTIVE_OR_OVERRIDE);
#endif
  pFctVehLongOut->DecelLimOverride  = cc_status->CC_CONTROL_DATA.DECEL_LIM_OVERRIDE_ACTIVE;
  pFctVehLongOut->CtrlToRelevObj    = (boolean)cc_status->CC_DRIVER_REQUESTS.ENGAGEMENT_CONDITIONS.CONTROL_TO_RELEVANT_OBJECT;
  pFctVehLongOut->ObjectEffective   = (boolean)cc_status->CC_ACCEL_CONTROL_DATA.ACCEL_STATUS.OBJECT_EFFECTIVE;

#if (CFG_FCT_CC_USE_DRIVE_MODE)
  pFctVehLongOut->eDriveMode = pLongCtrlResp->KinCtrlDynInput.eDriveMode;
#endif

}


/*********************************************************************************************************************
  Functionname               KMC_v_SoftStopRequestFlag */ /*!

  @brief			determine soft stop request to hold vehicle in standstill
  
  @description      Determines the soft stop request according to customer requirement (ARS410GY18 specific). If the
                    relevant object is stoped and if additionally the ego velocity and the distance to the relevant
                    object drop below a certain threshold, a stop is about to happen an the SoftStopRequest is set
                    TRUE.

                    The soft stop request is reset whenever the SITUATION_CLASS.SITUATION indicates the host is not
                    stopped.

					If soft stop request is set and vehicle speed is 0, the brake will hold the car.

  @return			void
  
  @param[in]	   vehicle_speed: speed of ego vehicle																		[velocity_t as per Rte_Type.h]
  @param[in]       pDasOutputData : Data from driver assistance system to longitudinal dynamics management \n
                      pDasOutputData->DAS_STAT.DAS_ENGAGED: status of ACC engagement											[TRUE, FALSE] \n
  @param[in]       pDriverInformation : HMI Output data \n
                      pDriverInformation->OBJECT_DETECTED : target object detected                                          [full range of unsigned char] \n
  @param[in]       pCCStatus : the cruise control status information \n
					  pCCStatus->CC_DRIVER_REQUESTS.CONTROL_STATE: internal cc state										[0...11] \n
  @param[in]       pAccOutput->SITUATION_CLASS.SITUATION: classification of estimated traffic situation						[0...6]
  @param[in]       pAccDisplayObj: data regarding selected object
				      pAccDisplayObj->AUTOSAR.LONG_DISPLACEMENT: longitudinal displacement of target							[distance_t as per Rte_Type.h]\n
				      pAccDisplayObj->AUTOSAR.OBJECT_STATUS.STANDING: signal if object is standing (not been moving)			[TRUE, FALSE]\n
				      pAccDisplayObj->AUTOSAR.OBJECT_STATUS.STOPPED: signal if object is right stopped							[TRUE, FALSE]\n
  @param[in,out]   pLongCtrlCmd : the output for the longitudinal controller \n
                      pLongCtrlCmd->Custom.CustomOutput.SoftStopRequest: request to keep vehicle in standstill				[TRUE, FALSE]
					  
  @glob_in         None
  @glob_out        None
  
  
  @c_switch_full   FCT_CFG_LONG_PROCESSING : Configuration switch for enabling FCT_LONG processing
  
  @pre             None
  @post            None

*********************************************************************************************************************/
static void KMC_v_SoftStopRequestFlag(const cart_das_output_data_t* pDasOutputData,
                                                     const cc_driver_information_t* pDriverInformation,
                                                     const velocity_t vehicle_speed,
                                                     const acc_object_t * pAccDisplayObj,
                                                     const cc_status_t * pCCStatus,
                                                     const acc_output_data_t * pAccOutput,
                                                     LongCtrlOutput_t * pLongCtrlCmd)
{
    if(    ((boolean)(pDasOutputData->DAS_STAT.DAS_ENGAGED) == TRUE)
		&& (pDriverInformation->OBJECT_DETECTED == TRUE)
        && (pAccDisplayObj->AUTOSAR.LONG_DISPLACEMENT <= Cc_max_softstop_request_distance)
        && (vehicle_speed <= Cc_max_softstop_request_velocity) 
        && (    (pAccDisplayObj->AUTOSAR.OBJECT_STATUS.STANDING == TRUE)
             || (pAccDisplayObj->AUTOSAR.OBJECT_STATUS.STOPPED == TRUE))
	  ) 
	{
		pLongCtrlCmd->Custom.CustomOutput.SoftStopRequest = TRUE;
	}
	else
	{
		if(    (pCCStatus->CC_DRIVER_REQUESTS.CONTROL_STATE == Cc_cc_active)
			 && (pAccOutput->SITUATION_CLASS.SITUATION != Acc_sit_class_stop))
		{
			pLongCtrlCmd->Custom.CustomOutput.SoftStopRequest = FALSE;
		}
		else
		{
			/* do nothing */
		}
	}
}


/*************************************************************************************************************************
  Functionname:    KMC_v_OutputWrapper                                                                              */ /*!

  @brief           Output Signals Wrapper for fct_long_veh.c

  @description     Output Signals Wrapper for fct_long_veh.c

	@startuml
	Start
		Partition KMC_v_OutputWrapper(){
			: Processing Output for Minimum Requested Acceleration on both channels;
			: Processing state outputs and update standstill flag with \nrequested acceleration;
			: Standstil request set to False if state is not cc_cc_active;
			If (Standstill request is true) then (True)
				If (vehicle is in standstill) Then (True)
					if (Target vehicle is stationary or stopped) Then (True)
						: Release stop flag if we are much too far away or if\n acceleration output is beyond limit (0.5m/s^2);
					Else
						: Release stop flag if acceleration output is beyond\n limit (0.5m/s^2);
					endif
				Else(False)
					: do not change request (dynamic phase of standstill req \n sent by KMC but not taken by   DMC);
				Endif
			Else (False)
				If (output state is not override) Then (True)
					: Set request if vehicle is in standstill and acceleration output is negative;
				Endif
			Endif
			: process standstill Request;
			: update ACC Fail info;
			: SLA speed available for takeover shown to driver;
			: SLA output speed shown to driver;
			: Write default value for outputs when CC not in active, \n engaged or override mode;
			
			if (ego vehicle standstill && in active state && Kmc_standstill_counter>0) then (True)
				:Kmc_standstill_counter--;
				:Kmc_Standstillstate = StandWait;
				if (Kmc_standstill_counter is within 3s) then (True)
					:Kmc_Standstillstate = StandActive;
				endif
				if (Kmc_standstill_counter == 0) then (True)
					:Kmc_inhibit_standstill = TRUE;
				endif
			else (False)
				:Kmc_standstill_counter set to 3 minutes;
				:Kmc_Standstillstate = None;
			endif
			
			if (internal state is Cc_cc_off) then (True)
				:output state is OFF;
			elseif (internal state is ready/engage) then (True)
				if (CC_INHIBIT_ENGAGEMENT == FALSE or\nCC_DISENGAGEMENT_NO_RAMP == FALSE or\nCC_DISENGAGEMENT_RAMP == FALSE or\nCC_DISENGAGEMENT_RAPID_RAMP == FALSE or\nb_BOM_Enter_Conditions == FALSE or\nDAS_ENABLE == FALSE) then (True)
					:output state is Passive;
				else (False)
					:output state is StandBy;
				endif
			elseif (internal state is override) then (True)
				:output state is Override;
			elseif (internal state is decel_only) then (True)
				:output state is BrakeOnlyMode;
			elseif (internal state is active/disengage) then (True)
				if (ego vehicle standstill) then (True)
					:output state is Standstill;
				else (False)
					:output state is ActiveControl;
				endif
			endif
			
			if (internal state is off) then (True)
				:output state is OFF;
			elseif (DAS_FAIL_IRREVERSABLE == TRUE or\nDAS_FAIL_REVERSABLE == TRUE) then (True)
				:output state is Failure;
			endif
			
			:Output shutdown request (custom requirement);
			:Output textmessage (custom requirement);
		}
	End
	@enduml


  @return          static void

  @param[in]       cycle_time : [times_t as per Rte_Type.h]
  @param[in]       cc_input : [cc_input_data_t as per cc_ext.h]
  @param[in]       cc_input->VEHICLE_STATUS.SPEED_UNIT_KMH : [true, false]
  @param[in]       cc_input->SLA_INPUT_DATA.SLA_InputStatus.b_SLA_SET_AUTOMATIC : SLA setting: manual or automatic after wrapper [true, false]
  @param[in]       das_input_data : [cart_das_input_data_t as per cart_ext.h]
  @param[in]       das_input_data->VEHICLE_SPEED : [velocity_t as per Rte_Type.h]
  @param[in]       das_output_data : [cart_das_output_data_t as per cart_ext.h]
  @param[in]       das_output_data->MAX_REQ_ACCEL : [acceleration_t as per Rte_Type.h]
  @param[in]       das_output_data->MIN_REQ_ACCEL : [acceleration_t as per Rte_Type.h]
  @param[in]       das_output_data->DAS_STAT.DAS_FAIL_REVERSABLE : [true, false]
  @param[in]       das_output_data->DAS_STAT.DAS_FAIL_IRREVERSABLE : [true, false]
  @param[in]       driver_inputs : [cc_driver_inputs_t as per fct_long_veh_customfunctions.c]
  @param[in]       driver_information : [cc_driver_information_t as per fct_long_veh_customfunctions.c]
  @param[in]       driver_information->ACC_DRIVE_OFF_POSSIBLE : [true, false]
  @param[in]       driver_information->BIT_ACC_ALERT      : [full range of unsigned char]
  @param[in]       driver_information->BIT_FCA_ALERT      : [full range of unsigned char]
  @param[in]       driver_information->BIT_DM_ALERT       : [full range of unsigned char]
  @param[in]       driver_information->OBJECT_DETECTED    : [full range of unsigned char]
  @param[in]       driver_information->REQUESTED_DISTANCE : [full range of unsigned char]
  @param[in]       driver_information->OBJECT_DISTANCE    : [full range of unsigned char]
  @param[in]       driver_information->HEADWAY_SETTING    : [full range of unsigned char]
  @param[in]       driver_information->SET_SPEED          : [full range of unsigned char]
  @param[in]       driver_information->OBJECT_SPEED       : [full range of unsigned char]
  @param[in]       driver_information->REPORTED_ERROR : [full range of unsigned char]
  @param[in]       cc_status : [cc_status_t as per cc_ext.h]
  @param[in]       cc_status->CC_DRIVER_REQUESTS.CONTROL_STATE : [0, 11]
  @param[in]       cc_status->CC_DRIVER_REQUESTS.CONTROL_MODE : [0,2]
  @param[in]       cc_status->CC_DRIVER_REQUESTS.DRIVER_OPERATIONS.DRIVE_OFF_CONFIRM : [true, false]
  @param[in]       cc_status->CC_ACCEL_CONTROL_DATA.MINIMUM_COMMANDED_ACCELERATION : [acceleration_t as per Rte_Type.h]
  @param[in]       cc_status->CC_ACCEL_CONTROL_DATA.ACCEL_STATUS.OBJECT_EFFECTIVE : [true, false]
  @param[in]       cc_status->CC_DRIVER_REQUESTS.OPERATIONAL_MODE : [display_op_status_t as per Rte_Type.h]
  @param[in]       cc_status->CC_SLA_HMI_DATA.e_SLA_State
  @param[in]       cc_status->CC_CONTROL_DATA.CC_SLA_CTRL_DATA.SLA_CtrlState.SLA_ACCEL_REQUEST_GRANTED
  @param[in]       cc_status->CC_SLA_HMI_DATA.u_SLA_SpeedLimitLastAccepted
  @param[in]       cc_status->CC_SLA_HMI_DATA.SLA_SpeedLimitActualAccepted.u_SpeedLimit
  @param[in]       error_data : Pointer to error data from CC [cc_error_data_t as per cc_ext.h]

  @param[in,out]   pLongCtrlCmd : [LongCtrlOutput_t as per Rte_Type.h]
  @param[out]      pLongCtrlCmd->KinOutput.DAS_status : [DAS_status_t as per Rte_Type.h]
  @param[out]      pLongCtrlCmd->DriverData.drive_off_possible : [true, false]
  @param[out]      pLongCtrlCmd->DriverData.drive_off_request : [true, false]
  @param[out]      pLongCtrlCmd->KinOutput.MinRequestedLongAcceleration ; [full range of signed short]
  @param[out]      pLongCtrlCmd->KinOutput.MaxRequestedLongAcceleration ; [full range of signed short]
  @param[out]      pLongCtrlCmd->KinOutput.brake_pre_fill : [true, false]
  @param[out]      pLongCtrlCmd->KinOutput.DAS_failure_information : [DAS_failure_information_t as per Rte_Type.h]
  @param[out]      pLongCtrlCmd->KinFctInfo.headway_control_alert : [full range of unsigned char]
  @param[out]      pLongCtrlCmd->KinFctInfo.FCA_alert             : [full range of unsigned char]
  @param[out]      pLongCtrlCmd->KinFctInfo.DM_alert_level        : [DM_alert_level_t as per Rte_Type.h]
  @param[out]      pLongCtrlCmd->KinFctInfo.object_detected       : [full range of unsigned char]
  @param[out]      pLongCtrlCmd->KinFctInfo.requested_distance    : [full range of unsigned char]
  @param[out]      pLongCtrlCmd->KinFctInfo.obj_interest_distance : [full range of unsigned char]
  @param[out]      pLongCtrlCmd->KinFctInfo.headway_setting       : [full range of unsigned char]
  @param[out]      pLongCtrlCmd->KinFctInfo.desired_speed         : [full range of unsigned char]
  @param[out]      pLongCtrlCmd->KinFctInfo.recommended_speed     : [full range of unsigned char]
  @param[out]      pLongCtrlCmd->KinFctInfo.speed_target          : [full range of unsigned char]
  @param[out]      pLongCtrlCmd->KinFctInfo.DM_status : [DM_status_t as per Rte_Type.h]
  @param[out]      pLongCtrlCmd->DriverData.failure_state    : [cc_reported_error_t as per Rte_Type.h]
  @param[out]      pLongCtrlCmd->DriverData.operational_mode : [display_op_status_t as per Rte_Type.h]
  @param[out]      pLongCtrlCmd->DriverData.ldm_drive_mode : [ldm_drive_mode_t as per Rte_Type.h]
  @param[in]       pFCTAccOOIData : [FCTSenAccOOI_t as per Rte_Type.h]
  @param[in]       pFCTAccOOIData->AccOOINextLong.Kinematic.fVabsX : [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
  @param[in]       pFCTAccOOIData->AccOOINextLong.Kinematic.fDistX : [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m

  @glob_in         drive_off_cycle_counter : [full range of unsigned char]
  @glob_in         cc_das_custom_state.CC_CUSTOM_DRIVER_OUTSIDE_HOLD : [true, false]
  @glob_in         cc_das_custom_state.CC_CUSTOM_STAND_STILL_HOLD : [true, false]
  @glob_in         cc_das_stop_go_state : [0,3]
  @glob_in         b_drive_off_confirm_last : [true, false]
  @glob_in         CC_DRIVER_INF.CC_DRIVER_INF.DM_STATE : [0,2]
  @glob_out        b_drive_off_confirm_last : [true, false]
  @glob_out        stop_start_cycle_counter : [times_t as per Rte_Type.h]
  @glob_out        drive_off_min_accel_rq_timer : [times_t as per Rte_Type.h]
  @glob_out        uiSLA_MsgDisplayTimer : Timer for display of SLA message [times_t as per Rte_Type.h] ms
                   
  @c_switch_part   FCT_CFG_SLA_FEATURE : Configuration switch for enabling SLA support functions
  @c_switch_full   FCT_CFG_LOPC_COMPONENT : Configuration switch for enabling LOPC processing
                   
  @pre             -
  @post            -
                   
  @created         -
  @changed         22/07/2019

  @author         Simon Sinnstein
**************************************************************************** */
static void KMC_v_OutputWrapper(const times_t cycle_time, 
                                const FCTSenAccOOI_t* pFCTAccOOIData,
                                const acc_output_data_t* acc_output,
								const VehDyn_t* pVehDyn,
                                const cc_input_data_t* cc_input,
                                const cart_das_input_data_t* das_input_data,
                                const cart_das_output_data_t* das_output,
								const cc_driver_inputs_t* driver_inputs,
								const LongCtrlInput_t* pLongCtrlResp,
                                cc_driver_information_t* driver_information,
                                cc_status_t* cc_status,
                                const cc_error_data_t* error_data,
                                LongCtrlOutput_t * pLongCtrlCmd)
{
#if (CFG_FCT_CC_PARAMS_DEBUG)
  uint8 u_count;
#endif
	static percentage_t ratio = 0U;
	static uint8 uDisplayDistanceLevel = DISTANCE_NO_DISPLAY;
	float32 t_slope = 0.0F;
	float32 t_accel = 0.0F;
	static float32 accel = 0.0F;
	static float32 slope = 0.0F;
	static uint16 HMI_Display_counter = 0U;
	static ACCStatus_Radar_t Pre_ACCStatus_Radar = ACC_STAT_OFF;
	static ACCTextMessageBD10_t Pre_ACCTextInfo_Radar = ACCTextMessageBD10_eNo_display;
	static boolean b_notactive_driverselt = FALSE; 
	static boolean b_notactive_dooropen = FALSE;
	static boolean b_notactive_notDgear = FALSE;
	static boolean b_notactive_espoff = FALSE;
	static boolean b_notactive_epboff = FALSE;

	static boolean b_Stand_Still_Request_last_cycle;
	b_Stand_Still_Request_last_cycle = b_Stand_Still_Request;

	pLongCtrlCmd->Custom.CustomOutput.InhibitReason_CC_INHIBIT = InhibitReason_CC_INHIBIT;
	pLongCtrlCmd->Custom.CustomOutput.InhibitReason_No_Ramp = InhibitReason_No_Ramp;
	pLongCtrlCmd->Custom.CustomOutput.InhibitReason_Rapid_Ramp = InhibitReason_Rapid_Ramp;
	pLongCtrlCmd->Custom.CustomOutput.InhibitReason_Ramp = InhibitReason_Ramp;
	pLongCtrlCmd->Custom.CustomOutput.InhibitReason_Inhibit_Engagement = InhibitReason_Inhibit_Engagement;
	pLongCtrlCmd->Custom.CustomOutput.InhibitReason_Soft_Off_Condition = InhibitReason_Soft_Off_Condition;

  /* Output of Minimum Requested Acceleration on both channels ! */
  pLongCtrlCmd->KinOutput.MaxRequestedLongAcceleration = das_output->MIN_REQ_ACCEL;
  pLongCtrlCmd->KinOutput.MinRequestedLongAcceleration = das_output->MIN_REQ_ACCEL;

  /* State Output */
  if ((das_output->DAS_STAT.DAS_FAIL_REVERSABLE == TRUE) ||
      (das_output->DAS_STAT.DAS_FAIL_IRREVERSABLE == TRUE))
  { /* ACC Failure */
    pLongCtrlCmd->KinOutput.DAS_status = DAS_STATUS_OFF;
    b_Stand_Still_Request = FALSE;
  }
  else
  { /* No ACC Failure */
    switch (cc_status->CC_DRIVER_REQUESTS.CONTROL_STATE)
    {
    case Cc_cc_off:
      pLongCtrlCmd->KinOutput.DAS_status = DAS_STATUS_OFF;
      b_Stand_Still_Request = FALSE;
      break;

    case Cc_cc_ready:
    case Cc_cc_engage:
      pLongCtrlCmd->KinOutput.DAS_status = DAS_STATUS_ENGAGED;
      b_Stand_Still_Request = FALSE;
      break;

    case Cc_cc_active:
      pLongCtrlCmd->KinOutput.DAS_status = DAS_STATUS_ACTIVE;
      /* b_Stand_Still_Request is left unchanged */
      break;

    case Cc_cc_override:
      pLongCtrlCmd->KinOutput.DAS_status = DAS_STATUS_OVERRIDE;
      b_Stand_Still_Request = FALSE;
      break;

    case Cc_cc_disengage:
      pLongCtrlCmd->KinOutput.DAS_status = DAS_STATUS_DISENGAGE;
      b_Stand_Still_Request = FALSE;
      break;

    default:
      pLongCtrlCmd->KinOutput.DAS_status = DAS_STATUS_OFF;
      b_Stand_Still_Request = FALSE;
      break;
    }
  }

  pLongCtrlCmd->KinOutput.brake_pre_fill = FALSE;

  /* Set standstill request flag in case of standstill with requested deceleration */
  if (b_Stand_Still_Request == TRUE)
  { // When reseting standstill request, not checking whether ego vehicle reaches full standstill
      /* If target vehicle is stopped => release stop flag if we are much too far away and try to start */
      if ((pFCTAccOOIData->AccOOINextLong.Attributes.eDynamicProperty == EM_GEN_OBJECT_DYN_PROPERTY_STATIONARY)
       || (pFCTAccOOIData->AccOOINextLong.Attributes.eDynamicProperty == EM_GEN_OBJECT_DYN_PROPERTY_STOPPED))
      {
        b_Stand_Still_Request = (boolean)((das_output->MIN_REQ_ACCEL < (acceleration_t)50) /* 0.05 m/s^2 */
                                          || ((pFCTAccOOIData->AccOOINextLong.Kinematic.fDistX * (float32)Distance_s) < (float32)(acc_output->REQUESTED_DISTANCE + Kmc_acc_drive_off_dist_hyst))
                                         );
      }
      /* If target vehicle moves => release stop flag if we try to start */
      else
      {
        b_Stand_Still_Request = (boolean)(das_output->MIN_REQ_ACCEL < (acceleration_t)50); /* 0.05 m/s^2 */
      }
  }
  else
  {
	if	(
			(cc_status->CC_DRIVER_REQUESTS.CONTROL_STATE == Cc_cc_active)
			&&
			(das_output->DAS_STAT.DAS_FAIL_REVERSABLE == FALSE)
			&&
			(das_output->DAS_STAT.DAS_FAIL_IRREVERSABLE == FALSE)
		)
	{
		b_Stand_Still_Request = (boolean)(
											(das_output->MIN_REQ_ACCEL < (acceleration_t)0)
											&&
											(
												(das_input_data->VEHICLE_SPEED < (velocity_t)25)
												||
												(das_input_data->LODM_STAT.STANDSTILL == TRUE)
										  	)
										 );
	}
  }
  pLongCtrlCmd->KinOutput.stand_still_request = b_Stand_Still_Request;

  /*method: Calculate the slope*/
  /*Input signal: ESP acceleration
                  VDY acceleration calculate by four wheel speed
	methods: 1) filter the ESP aceeleration 
	         2) calculate the slope = arcsin[(ESP accel-wheel accel)/g]
			 3) filter the slope
			 4) create a statemachine for smooth slope output*/

  t_accel = pLongCtrlResp->KinCtrlDynInput.ACC_Esp_Ax;
  t_accel = t_accel + p_slopeTc*(accel-t_accel);
  accel = t_accel; 

  t_slope = ASIN_((t_accel-pVehDyn->Longitudinal.AccelCorr.corrAccel)/ALGO_f_Gravity);
  t_slope = 180*t_slope/ACC_f_PI;
  t_slope = t_slope + p_slopeTc1*(slope-t_slope);
  slope = t_slope;

  /*state machine for slope state
    note: for this slope only used in uphill or downhill following low speed vehicle, so add conditions for 
	entering slope state( drive not acceleration, driver not break and acc output acceleration small than 0.5m/s2) */
  switch(driver_information->ACC_SLOPE_STATE)
  {
	case FALSE:
		driver_information->COUNTER_EXIT_SLOPE = Counter_exit_slope;
		if((t_slope >= THRESHOLD_ENTER_SLOPE )&&
			(pLongCtrlResp->KinCtrlDynInput.driver_override_accel_pedal == FALSE)&&
			(pLongCtrlResp->KinCtrlDynInput.driver_override_decel_pedal == FALSE)&&
			(ABS(pLongCtrlCmd->KinOutput.MinRequestedLongAcceleration) <= p_threshold_accel_slope)
			)
		{
			driver_information->COUNTER_SLOPE--;
			if(driver_information->COUNTER_SLOPE == 0)
			{
				driver_information->ACC_SLOPE_STATE = TRUE;
			}
		}
		else
		{
			driver_information->COUNTER_SLOPE= Counter_enter_slope;
		}
		break;
	case TRUE:
		driver_information->COUNTER_SLOPE= Counter_enter_slope;
		if(t_slope<=THRESHOLD_EXIT_SLOPE)
		{
			driver_information->COUNTER_EXIT_SLOPE--;
			if(driver_information->COUNTER_EXIT_SLOPE == 0)
			{
				driver_information->ACC_SLOPE_STATE = FALSE;
			}
		}
		else
		{
			driver_information->COUNTER_EXIT_SLOPE = Counter_exit_slope;
		}
		break;
	default:
		break; 
  }

  /*Add this condtions is dealing with esp cannot hold vehicle in slope with acc request very low deceleration request*/
  if(b_Stand_Still_Request == TRUE)
  {
	  if(das_input_data->VEHICLE_SPEED < Kmc_acc_standsitll_velocity_threshold)
	  {
		  if(driver_information->ACC_SLOPE_STATE == TRUE)
		  {
			pLongCtrlCmd->KinOutput.MinRequestedLongAcceleration = pLongCtrlCmd->KinOutput.MinRequestedLongAcceleration + Kmc_acc_offset_for_roll;
		  }
		  else
		  {		
		  }		
	  }
	  else
	  {		
	  }
  }
  else
  {
	  //do nothing
  }
 


  /* ACCFailInfo */
/*
  if (das_output->DAS_STAT.DAS_FAIL_REVERSABLE == TRUE)
  {
    if (driver_information->REPORTED_ERROR == Cc_performance_degradation)
    {
      pLongCtrlCmd->KinOutput.DAS_failure_information = DAS_FAILURE_PERF_DEGR;
    }
    else
    {
      pLongCtrlCmd->KinOutput.DAS_failure_information = DAS_FAILURE_TMP_NOT_AVAIL;
    }
  }
  else
  {
    if (das_output->DAS_STAT.DAS_FAIL_IRREVERSABLE == TRUE)
    {
      pLongCtrlCmd->KinOutput.DAS_failure_information = DAS_FAILURE_SRV_REQUESTED;
    }
    else
    {
      pLongCtrlCmd->KinOutput.DAS_failure_information = DAS_FAILURE_NONE;
    }
  }
*/

  pLongCtrlCmd->KinFctInfo.headway_control_alert  = driver_information->BIT_ACC_ALERT;
#if (FCT_CFG_SLA_FEATURE)
  /* SLA speed sign below minimum */
  if(cc_status->CC_SLA_HMI_DATA.SLA_Event.b_SLA_WARNING == TRUE)
  {
    pLongCtrlCmd->KinFctInfo.headway_control_alert = TRUE;
  }
#endif
  pLongCtrlCmd->KinFctInfo.FCA_alert              = driver_information->BIT_FCA_ALERT;
  pLongCtrlCmd->KinFctInfo.DM_alert_level         = driver_information->BIT_DM_ALERT;
  pLongCtrlCmd->KinFctInfo.object_detected        = driver_information->OBJECT_DETECTED;
  pLongCtrlCmd->KinFctInfo.requested_distance     = driver_information->REQUESTED_DISTANCE;
  pLongCtrlCmd->KinFctInfo.obj_interest_distance  = driver_information->OBJECT_DISTANCE;
  pLongCtrlCmd->KinFctInfo.headway_setting        = driver_information->HEADWAY_SETTING;
  pLongCtrlCmd->KinFctInfo.desired_speed          = driver_information->SET_SPEED;
  pLongCtrlCmd->KinFctInfo.recommended_speed      = driver_information->RECOMMENDED_SPEED;
  pLongCtrlCmd->KinFctInfo.speed_target           = driver_information->OBJECT_SPEED;

#if (FCT_CFG_DM)
  switch (driver_information->DM_STATE)
  {
  case Dm_off:
  default:
    pLongCtrlCmd->KinFctInfo.DM_status            = DM_STATUS_OFF;
    break;
  case Dm_on_inactive:
    pLongCtrlCmd->KinFctInfo.DM_status            = DM_STATUS_ON_INACTIVE;
    break;
  case Dm_on_active:
    pLongCtrlCmd->KinFctInfo.DM_status            = DM_STATUS_ON_ACTIVE;
    break;
  }
#else
  pLongCtrlCmd->KinFctInfo.DM_status      = DM_STATUS_OFF;
#endif

  pLongCtrlCmd->DriverData.drive_off_possible     = driver_information->ACC_DRIVE_OFF_POSSIBLE;  //to dash bord
  pLongCtrlCmd->DriverData.failure_state          = driver_information->REPORTED_ERROR;
  pLongCtrlCmd->DriverData.operational_mode       = cc_status->CC_DRIVER_REQUESTS.OPERATIONAL_MODE;
  /* Storage of cc parameter values for debugging */
#if (CFG_FCT_CC_PARAMS_DEBUG)
  u_count = 0;

  KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.CC_PARAMS.CC_MAX_DECEL_DURING_OVERRIDE = (sint16)Cc_max_decel_during_override;
  KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.CC_PARAMS.CC_MAX_DECEL_AFTER_OVERRIDE = (sint16)Cc_max_decel_after_override;
  KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.CC_PARAMS.CC_MAX_DECEL_AFTER_ENGAGE = (sint16)Cc_max_decel_after_engage;
  KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.CC_PARAMS.CC_ACC_TO_CC_TRANSITON_FACTOR_DEFAULT = (sint16)Cc_acc_to_cc_transition_factor;
  KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.CC_PARAMS.CC_SLA_MANUAL_USAGE_TIME = (sint16)Cc_sla_manual_usage_time;
  for (u_count=0; u_count < 40; u_count++)
  {
    if (2*Cc_curve_points > u_count)
    {
      KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.CC_PARAMS.CC_ACCEL_CURVE[u_count] = Cc_accel_curve[u_count];
    }
    if (2*Cc_max_vehicle_accel_points > u_count)
    {
      KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.CC_PARAMS.CC_MAX_VEHICLE_ACCEL[u_count] = Cc_max_vehicle_accel[u_count];
    }
    if (2*Cc_max_vehicle_decel_points > u_count)
    {
      KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.CC_PARAMS.CC_MAX_VEHICLE_DECEL[u_count] = Cc_max_vehicle_decel[u_count];
    }
    if (2*Cc_max_accel_curve_points > u_count)
    {
      KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.CC_PARAMS.CC_MAX_ACCEL_CURVE_EU[u_count] = Cc_max_accel_curve[u_count];
    }
    if (2*Cc_pos_grad_neg_accel_points > u_count)
    {
      KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.CC_PARAMS.CC_MAX_POS_GRAD_DEFAULT_NEG_ACCEL[u_count] = Cc_max_pos_grad_neg_accel[u_count];
    }
    if (2*Cc_pos_grad_pos_accel_points > u_count)
    {
      KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.CC_PARAMS.CC_MAX_POS_GRAD_DEFAULT_POS_ACCEL[u_count] = Cc_max_pos_grad_pos_accel[u_count];
    }
    if (2*Cc_neg_grad_points > u_count)
    {
      KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.CC_PARAMS.CC_MAX_NEG_GRAD_DEFAULT[u_count] = Cc_max_neg_grad[u_count];
    }
    if (2*Cc_long_accel_curve_points > u_count)
    {
      KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.CC_PARAMS.CC_LONG_ACCEL_CURVE[u_count] = Cc_long_accel_curve[u_count];
    }
    if (2*Cc_alat_speed_curve_points > u_count)
    {
      KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.CC_PARAMS.CC_ALAT_SPEED_CURVE_DEFAULT[u_count] = Cc_alat_speed_curve[u_count];
    }
  }
#endif

  /* Custom outputs from SLA */
#if (FCT_CFG_SLA_FEATURE) 

  if(cc_input->SLA_INPUT_DATA.SLA_InputStatus.b_SLA_SET_ENGAGED == TRUE)
  {
    pLongCtrlCmd->SlaOutput.SLA_TkOvr_State = SLA_TK_OVR_ON;

    /*! SLA display message timer */
    SWITCH_SET_COUNTER(cycle_time, &uiSLA_MsgDisplayTimer);
    /* Output SLA Support */
    if(cc_status->CC_SLA_HMI_DATA.e_SLA_State == SLA_STATE_ACCEPTED)
    {
      if(cc_status->CC_CONTROL_DATA.CC_SLA_CTRL_DATA.SLA_CtrlState.SLA_ACCEL_REQUEST_GRANTED == FALSE)
      {
        pLongCtrlCmd->SlaOutput.SLA_SpdLimit = cc_status->CC_SLA_HMI_DATA.u_SLA_SpeedLimitLastAccepted;
      }
      else 
      { /* Initialization of SLA msg timer when SLA speed is first accepted before it can be regulated */
        uiSLA_MsgDisplayTimer = SLA_SPD_DISPLAY_TIME;
      }
    }
    else
    {
      pLongCtrlCmd->SlaOutput.SLA_SpdLimit = cc_status->CC_SLA_HMI_DATA.SLA_SpeedLimitActualAccepted.u_SpeedLimitIncOffset;
    }

    /* Display of available speed to driver for speed takeover suggestion */
    if(cc_input->SLA_INPUT_DATA.SLA_InputStatus.b_SLA_SET_AUTOMATIC == FALSE)
    { /* SLA manual mode */
      if(uiSLA_ManUsageTimer > 0) /* New SLA speed limit is available */
      {
        if(cc_input->SLA_INPUT_DATA.SLA_SpeedLimit.u_SpeedLimit != SLA_UNRESTRICTED_SPEED)
        { /* Showing actual traffic sign to driver without offset */
          /* Max of speedlimit and Min_allowed_SLA because saved speed can be lower than 30 */
          pLongCtrlCmd->SlaOutput.SLA_SpdLimit_Available = (setspeed_t) MAT_MAX(cc_input->SLA_INPUT_DATA.SLA_SpeedLimit.u_SpeedLimit, Min_sla_speed);
        }
        else if(cc_status->CC_SLA_HMI_DATA.SLA_Event.b_SLA_SET_DRIVER_SETSPEED == TRUE) /*!< Valid driver set speed is available */
        { /* Speed cancelled input leads to taking of previous saved speed */
          pLongCtrlCmd->SlaOutput.SLA_SpdLimit_Available = cc_status->CC_SLA_HMI_DATA.u_SLA_DriverLastSetSpeed;
        }
        else
        {
          /* Default value */
          pLongCtrlCmd->SlaOutput.SLA_SpdLimit_Available = (setspeed_t)0;
        }
      }
      else
      { /* Default value */
        pLongCtrlCmd->SlaOutput.SLA_SpdLimit_Available = (setspeed_t)0;
      }
    }
    else
    { /* Automatic mode*/
      if(cc_status->CC_SLA_HMI_DATA.SLA_Event.b_SLA_USAGE_AVAILABLE == TRUE) /* SLA speed available to be cancelled */
      { /* SLA output speed shown to driver via SLA_SpdLimit_Available signal to offer cancellation of */
        /* automatically accepted speed limit within timer */
        pLongCtrlCmd->SlaOutput.SLA_SpdLimit_Available = cc_status->CC_SLA_HMI_DATA.SLA_SpeedLimitActualAccepted.u_SpeedLimit;
      }
      else
      {
        pLongCtrlCmd->SlaOutput.SLA_SpdLimit_Available = (setspeed_t)0;
      }
    }

    pLongCtrlCmd->SlaOutput.SLA_MsgDisp = SLA_IDLE;
    if(cc_input->SLA_INPUT_DATA.SLA_InputStatus.b_SLA_SET_AUTOMATIC == TRUE)
    { /* Automatic Takeover mode */
      pLongCtrlCmd->SlaOutput.SLA_MsgDisp = SLA_AUTO;
    }
    else
    { /* Manual Takeover mode */
      pLongCtrlCmd->SlaOutput.SLA_MsgDisp = SLA_MANUAL;
    }

#if (FCT_LONG_CTRL_OUTPUT_INTFVER >= 22)
    /* Output of SLA Offset */
    pLongCtrlCmd->SlaOutput.SLA_SpdLimit_Offset = cc_status->CC_SLA_HMI_DATA.s_SLA_Offset;

#endif
  }
  else
  { /* CC not in active, engaged or override mode. Default values for outputs */
    pLongCtrlCmd->SlaOutput.SLA_TkOvr_State = SLA_TK_OVR_OFF;
    pLongCtrlCmd->SlaOutput.SLA_MsgDisp = SLA_IDLE;
    pLongCtrlCmd->SlaOutput.SLA_SpdLimit = (setspeed_t)0;
    pLongCtrlCmd->SlaOutput.SLA_SpdLimit_Available = (setspeed_t)0;
#if (FCT_LONG_CTRL_OUTPUT_INTFVER >= 22)
    pLongCtrlCmd->SlaOutput.SLA_SpdLimit_Offset = 0;
#endif
    uiSLA_MsgDisplayTimer = (times_t)0;
  }
#else
  _PARAM_UNUSED(cc_input);
  _PARAM_UNUSED(cycle_time);

#endif /* FCT_CFG_SLA_FEATURE */


///////////////////////CN_ACCSM///////////////////////////
#if CN_ACCSM

  /*pre acc status*/
  Pre_ACCStatus_Radar = pLongCtrlCmd->Custom.CustomOutput.ACCStatus_Radar;

  //////////////////out put state mapping/////////////////////////////////
	switch(cc_status->CC_DRIVER_REQUESTS.CONTROL_STATE)
	{
		case Cc_cc_off:
			pLongCtrlCmd->Custom.CustomOutput.ACCStatus_Radar = ACC_STAT_OFF;
			break;

		case Cc_cc_ready:
		case Cc_cc_engage:
			if(driver_inputs->CC_Main_SWITCH.AKT_STATUS == FALSE)
			{
				pLongCtrlCmd->Custom.CustomOutput.ACCStatus_Radar = ACC_STAT_OFF;
			}
			else if	(
					(cc_input->INHIBIT.CC_INHIBIT_ENGAGEMENT == FALSE) // only "not braking when standstill" satisfied in CC_INHIBIT_ENGAGEMENT
					&&
					(cc_input->INHIBIT.CC_DISENGAGEMENT_NO_RAMP == FALSE)
					&&
					(cc_input->INHIBIT.CC_DISENGAGEMENT_RAMP == FALSE)
					&&
					(cc_input->INHIBIT.CC_DISENGAGEMENT_RAPID_RAMP == FALSE)
					&&
					(b_BOM_Enter_Conditions == FALSE)
				)
			{ // if (driver not braking or AVH not active) when ego vehicle, and other inhibition not satisfied, display as standby state
				pLongCtrlCmd->Custom.CustomOutput.ACCStatus_Radar = ACC_STAT_STANDBY;
			}
			else if	(
						(cc_input->INHIBIT.CC_INHIBIT_ENGAGEMENT == TRUE)
						||
						(cc_input->INHIBIT.CC_DISENGAGEMENT_NO_RAMP == TRUE)
						||
						(cc_input->INHIBIT.CC_DISENGAGEMENT_RAMP == TRUE)
						||
						(cc_input->INHIBIT.CC_DISENGAGEMENT_RAPID_RAMP == TRUE)
						||
						(das_input_data->LODM_STAT.DAS_ENABLE == FALSE)
						||
						(b_BOM_Enter_Conditions == TRUE)
					)
			{
				pLongCtrlCmd->Custom.CustomOutput.ACCStatus_Radar = ACC_STAT_PASSIVE; 
			}
			else
			{
				pLongCtrlCmd->Custom.CustomOutput.ACCStatus_Radar = ACC_STAT_STANDBY;
			}
			break;

		case Cc_cc_override:
			pLongCtrlCmd->Custom.CustomOutput.ACCStatus_Radar = ACC_STAT_OVERRIDE;
			break;
		case Cc_cc_active:
		case Cc_cc_disengage:
#if (CN_ACCSM_BOM)
			// First cycle after entering Cc_cc_active/Cc_cc_disengage, reset b_BOM_Exists and u_BOM_Counter
			if	(
					(cc_status->CC_DRIVER_REQUESTS.CONTROL_STATE_LAST_CYCLE != Cc_cc_active)
					&&
					(cc_status->CC_DRIVER_REQUESTS.CONTROL_STATE_LAST_CYCLE != Cc_cc_disengage)
				)
			{
				b_BOM_Exists = FALSE;
				u_BOM_Counter = (uint32)Cc_max_decel_only_time / cycle_time;
			}

			if ( (b_BOM_Exists == FALSE) && (b_BOM_Enter_Conditions == TRUE) )
			{
				b_BOM_Exists = TRUE;
			}
			else
			{
				// Do nothing, never reset b_BOM_Exists in Cc_cc_active and Cc_cc_disengage
			}
			
			if((b_BOM_Exists == TRUE)&&(u_BOM_Counter!=0))
			{
				pLongCtrlCmd->Custom.CustomOutput.ACCStatus_Radar = ACC_STAT_BRAKEONLYMODE;
				u_BOM_Counter--;
			}
			else if(((b_BOM_Exists == FALSE)||(u_BOM_Counter==0))&&(cc_status->CC_DRIVER_REQUESTS.CONTROL_STATE==Cc_cc_disengage))
			{
				pLongCtrlCmd->Custom.CustomOutput.ACCStatus_Radar = ACC_STAT_PASSIVE;
			}
			
#endif
			else if((das_input_data->LODM_STAT.STANDSTILL == TRUE)&&(pLongCtrlCmd->DriverData.drive_off_request == FALSE))
			{
				pLongCtrlCmd->Custom.CustomOutput.ACCStatus_Radar = ACC_STAT_STANDSTILL;
			}
			else
			{
				pLongCtrlCmd->Custom.CustomOutput.ACCStatus_Radar = ACC_STAT_ACTIVECONTROL;
			}
			break;

		default:
			{
				break;
			}
	}

	
	if	(
				(das_output->DAS_STAT.DAS_FAIL_IRREVERSABLE == TRUE)
				||
				(das_output->DAS_STAT.DAS_FAIL_REVERSABLE == TRUE) //error state
			)
	{
		pLongCtrlCmd->Custom.CustomOutput.ACCStatus_Radar = ACC_STAT_FAILUREMODE;
	}
	else
	{
		//do nothing
	}
	ACC_State_Last_Cycle = ACC_State;
	ACC_State = pLongCtrlCmd->Custom.CustomOutput.ACCStatus_Radar;
  
  //////////////////////Divide Standstill state into StandActive, StandWait, Deactivating////////////////////
	if	(pLongCtrlCmd->Custom.CustomOutput.ACCStatus_Radar == ACC_STAT_STANDSTILL)
	{
		if (Kmc_standstill_counter>0)
		{
			Kmc_standstill_counter--;
		}
	}
	else
	{
		Kmc_standstill_counter = Kmc_standstill_counter_C;
	}

	switch(Kmc_Standstillstate)
	{
		case StandStillState_None:
			if (pLongCtrlCmd->Custom.CustomOutput.ACCStatus_Radar != ACC_STAT_STANDSTILL)
			{
				Kmc_Standstillstate = StandStillState_None;
			}
			else if	(Kmc_standstill_counter > Kmc_standstill_3sec_counter_C)
			{ // 0 ~ 3s, StandActive
				Kmc_Standstillstate = StandStillState_StandActive;
			}
			else
			{
				// Do nothing
			}
			break;
				
		case StandStillState_StandActive:
			if (pLongCtrlCmd->Custom.CustomOutput.ACCStatus_Radar != ACC_STAT_STANDSTILL)
			{
				Kmc_Standstillstate = StandStillState_None;
			}
			else if	(
						(Kmc_standstill_counter <= Kmc_standstill_3sec_counter_C)
						// standstill for 3s ~ 3 minutes, StandActive --> StandWait
						||
						(das_input_data->BRAKE_STAT.PEDAL_INIT_TRAVEL == TRUE)
						// if driver press brake pedal or AVH active, StandActive --> StandWait
						||
						(ACC_Cancellation_Flag == TRUE)
						//Close target lost( distance smaller than 5m)   ACC_DISPLAY_OBJECT
					)
			{				
				Kmc_Standstillstate = StandStillState_StandWait;
			}
			else
			{
				// Do nothing
			}
			break;
				
		case StandStillState_StandWait:
			if (pLongCtrlCmd->Custom.CustomOutput.ACCStatus_Radar != ACC_STAT_STANDSTILL)
			{
				Kmc_Standstillstate = StandStillState_None;
			}
			else if (Kmc_standstill_counter == 0)
			{ // standstil for 3 minutes, ACC shall be deactivated. StandStillState_Deactivating is one condition of CC_DISENGAGEMENT_NO_RAMP .
				Kmc_Standstillstate = StandStillState_Deactivating;
			}
			else
			{
				// Do nothing
			}
			break;
			
		case StandStillState_Deactivating:
			if (pLongCtrlCmd->Custom.CustomOutput.ACCStatus_Radar != ACC_STAT_STANDSTILL)
			{
				Kmc_Standstillstate = StandStillState_None;
			}
			break;
			
		default:
			Kmc_Standstillstate = StandStillState_None;
			break;
	}

	// drive off request to actuator
	if (pLongCtrlCmd->DriverData.drive_off_request == FALSE)
	{
		if	(
				(
					(	
						(das_input_data->LODM_STAT.STANDSTILL == TRUE)
						&&
						(b_Stand_Still_Request_last_cycle == TRUE)
						&&
						(b_Stand_Still_Request == FALSE)
					)
					||
					(
						(das_input_data->LODM_STAT.STANDSTILL == TRUE)
						&&
						(b_Stand_Still_Request == FALSE)
						&&
						(acc_output->SITUATION_CLASS.SITUATION != Acc_sit_class_stop)
						&&
						(cc_status->CC_DRIVER_REQUESTS.DRIVER_OPERATIONS.DRIVE_OFF_CONFIRM == TRUE)			
					)
				)
				&&
				(
					(pLongCtrlCmd->Custom.CustomOutput.ACCStatus_Radar == ACC_STAT_STANDSTILL)
					||
					(pLongCtrlCmd->Custom.CustomOutput.ACCStatus_Radar == ACC_STAT_ACTIVECONTROL)
					||
					(pLongCtrlCmd->Custom.CustomOutput.ACCStatus_Radar == ACC_STAT_OVERRIDE)
				)
			)
		{
			pLongCtrlCmd->DriverData.drive_off_request = TRUE;
		}
	}
	else //pLongCtrlCmd->DriverData.drive_off_request == TRUE
	{
		if	(
				(das_input_data->LODM_STAT.STANDSTILL == FALSE)
				||
				(b_Stand_Still_Request == TRUE)
				||
				(pLongCtrlCmd->Custom.CustomOutput.ACCStatus_Radar == ACC_STAT_OFF)
				||
				(pLongCtrlCmd->Custom.CustomOutput.ACCStatus_Radar == ACC_STAT_PASSIVE)
				||
				(pLongCtrlCmd->Custom.CustomOutput.ACCStatus_Radar == ACC_STAT_STANDBY)
				||
				(pLongCtrlCmd->Custom.CustomOutput.ACCStatus_Radar == ACC_STAT_FAILUREMODE)
				||
				(pLongCtrlCmd->Custom.CustomOutput.ACCStatus_Radar == ACC_STAT_BRAKEONLYMODE)
			)
		{
			pLongCtrlCmd->DriverData.drive_off_request = FALSE;
		}
	}

#endif
///////////////////////end CN_ACCSM///////////////////////
	if	(
			(
				(pLongCtrlCmd->Custom.CustomOutput.ACCStatus_Radar == ACC_STAT_ACTIVECONTROL)
				||
				(pLongCtrlCmd->Custom.CustomOutput.ACCStatus_Radar == ACC_STAT_BRAKEONLYMODE)
				||
				(pLongCtrlCmd->Custom.CustomOutput.ACCStatus_Radar == ACC_STAT_OVERRIDE)
				||
				(pLongCtrlCmd->Custom.CustomOutput.ACCStatus_Radar == ACC_STAT_STANDSTILL)
			)
			&&
			(driver_information->REQUESTED_DISTANCE > 0)
			&&
			(pLongCtrlCmd->KinFctInfo.object_detected == TRUE)
		)
	{
		ratio = (percentage_t) MAT_MIN( (driver_information -> OBJECT_DISTANCE) * 100 / (driver_information -> REQUESTED_DISTANCE), 255);

		switch (uDisplayDistanceLevel)
		{
			case DISTANCE_NO_DISPLAY:
				if (ratio <= display_distance_threshold_1)
				{
					uDisplayDistanceLevel = DISTANCE_LEVEL_1;
				}
				else if (ratio <= display_distance_threshold_2)
				{
					uDisplayDistanceLevel = DISTANCE_LEVEL_2;
				}
				else
				{
					uDisplayDistanceLevel = DISTANCE_LEVEL_3;
				}
				break;
			
			case DISTANCE_LEVEL_1:
				if (ratio <= display_distance_threshold_1 + display_distance_hyst)
				{
					uDisplayDistanceLevel = DISTANCE_LEVEL_1;
				}
				else if (ratio <= display_distance_threshold_2 + display_distance_hyst)
				{
					uDisplayDistanceLevel = DISTANCE_LEVEL_2;
				}
				else
				{
					uDisplayDistanceLevel = DISTANCE_LEVEL_3;
				}
				break;
			
			case DISTANCE_LEVEL_2:
				if (ratio <= display_distance_threshold_1 - display_distance_hyst)
				{
					uDisplayDistanceLevel = DISTANCE_LEVEL_1;
				}
				else if (ratio <= display_distance_threshold_2 + display_distance_hyst)
				{
					uDisplayDistanceLevel = DISTANCE_LEVEL_2;
				}
				else
				{
					uDisplayDistanceLevel = DISTANCE_LEVEL_3;
				}
				break;
			
			case DISTANCE_LEVEL_3:
				if (ratio <= display_distance_threshold_1 - display_distance_hyst)
				{
					uDisplayDistanceLevel = DISTANCE_LEVEL_1;
				}
				else if (ratio <= display_distance_threshold_2 - display_distance_hyst)
				{
					uDisplayDistanceLevel = DISTANCE_LEVEL_2;
				}
				else
				{
					uDisplayDistanceLevel = DISTANCE_LEVEL_3;
				}
				break;
			
			default:
				uDisplayDistanceLevel = DISTANCE_NO_DISPLAY;
				break;
		}
	}
	else
	{
		ratio = 0U;
		uDisplayDistanceLevel = DISTANCE_NO_DISPLAY;
	}
	pLongCtrlCmd->Custom.CustomOutput.DisplayDistanceLevel = uDisplayDistanceLevel;

	/*Text information mapping logic base on BD10 project*/
	Pre_ACCTextInfo_Radar = pLongCtrlCmd->Custom.CustomOutput.ACCTextMessageBD10;

	//priority 1: acc failure 
	if(pLongCtrlCmd->Custom.CustomOutput.ACCStatus_Radar == ACC_STAT_FAILUREMODE ) 
	{
	   b_notactive_driverselt = FALSE; 
	   b_notactive_dooropen = FALSE;
	   b_notactive_notDgear = FALSE;
	   b_notactive_espoff = FALSE;
	   b_notactive_epboff = FALSE;
	  pLongCtrlCmd->Custom.CustomOutput.ACCTextMessageBD10 = ACCTextMessageBD10_efailure;   
	}
	else if( (Pre_ACCStatus_Radar!=ACC_STAT_OFF)&&
		     (pLongCtrlCmd->Custom.CustomOutput.ACCStatus_Radar == ACC_STAT_OFF)
		   )
	{
		b_notactive_driverselt = FALSE; 
	    b_notactive_dooropen = FALSE;
	    b_notactive_notDgear = FALSE;
	    b_notactive_espoff = FALSE;
	    b_notactive_epboff = FALSE;
		pLongCtrlCmd->Custom.CustomOutput.ACCTextMessageBD10 = ACCTextMessageBD10_eACC_off;
	}
	//priority 2: acc take over request 
	else if( pLongCtrlCmd->KinFctInfo.headway_control_alert == TRUE)
	{
		pLongCtrlCmd->Custom.CustomOutput.ACCTextMessageBD10 = ACCTextMessageBD10_etake_over; 
	}
	//priority 3: driver override
	else if(pLongCtrlCmd->Custom.CustomOutput.ACCStatus_Radar == ACC_STAT_OVERRIDE)
	{
		pLongCtrlCmd->Custom.CustomOutput.ACCTextMessageBD10 = ACCTextMessageBD10_eoverride; 
	}

	//priority 4: acc can not active by driver press set or resume button
	else if( (pLongCtrlCmd->Custom.CustomOutput.ACCStatus_Radar == ACC_STAT_PASSIVE) &&            
			  (
				((driver_inputs->CC_SET_SWITCH.AKT_STATUS == FALSE)&&(driver_inputs->CC_SET_SWITCH.LAST_STATUS == TRUE))||
				((driver_inputs->CC_RESUME_SWITCH.AKT_STATUS == FALSE)&&(driver_inputs->CC_RESUME_SWITCH.LAST_STATUS ==TRUE))
			  )
		    )
	{
		//priority 4-1: driver selt off
		if((InhibitReason_Soft_Off_Condition & INHIBITREASON_SOFT_OFF_CONDITION_SEATBELT_OPEN) != 0)
		{
			pLongCtrlCmd->Custom.CustomOutput.ACCTextMessageBD10 = ACCTextMessageBD10_edriver_belt_off;
			b_notactive_driverselt = TRUE;
		}
		//priority 4-2: driver door open
		else if((InhibitReason_Soft_Off_Condition & INHIBITREASON_SOFT_OFF_CONDITION_DOOR_OPEN_FRONT_LEFT) != 0)	
		{
			pLongCtrlCmd->Custom.CustomOutput.ACCTextMessageBD10 = ACCTextMessageBD10_eDoor_open;
			b_notactive_dooropen = TRUE;
		}
		//priority 4-3:  vehicle not in D gear
		else if(
					((InhibitReason_Soft_Off_Condition & INHIBITREASON_SOFT_OFF_CONDITION_GEAR_PNR) != 0)
					||
					((InhibitReason_Soft_Off_Condition & INHIBITREASON_SOFT_OFF_CONDITION_MANUNAL_GEAR) != 0)
				)
		{
			pLongCtrlCmd->Custom.CustomOutput.ACCTextMessageBD10 = ACCTextMessageBD10_eNot_in_Dgear;
			b_notactive_notDgear = TRUE;
		}
		//priority 4-4: EPB not release
		else if((InhibitReason_No_Ramp & INHIBITREASON_NO_RAMP_PARK_BRAKE_ACTIVE) != 0)
		{
			pLongCtrlCmd->Custom.CustomOutput.ACCTextMessageBD10 = ACCTextMessageBD10_eEPB_not_release;
			b_notactive_epboff = TRUE;
		}
		//priority 4-5: ESP off
		else if ((InhibitReason_No_Ramp & INHIBITREASON_NO_RAMP_ACTUATOR_OFF) != 0)
		{
			pLongCtrlCmd->Custom.CustomOutput.ACCTextMessageBD10 = ACCTextMessageBD10_eESP_off;
			b_notactive_espoff = TRUE;
		}
		//priority 4-6: other reason cause ACC can not active
		else if(
					(cc_input->INHIBIT.CC_INHIBIT_ENGAGEMENT == TRUE)
					||
					(cc_input->INHIBIT.CC_DISENGAGEMENT_NO_RAMP == TRUE)
					||
					(cc_input->INHIBIT.CC_DISENGAGEMENT_RAMP == TRUE)
					||
					(cc_input->INHIBIT.CC_DISENGAGEMENT_RAPID_RAMP == TRUE)
					||
					(das_input_data->LODM_STAT.DAS_ENABLE == FALSE)
					||
					(b_BOM_Enter_Conditions == TRUE)
				)
		{
			pLongCtrlCmd->Custom.CustomOutput.ACCTextMessageBD10 = ACCTextMessageBD10_eACC_ativation_failure;
		}
		else
		{
			//do nothing 
		}
	}
	//priority 5: ACC cancel when state change from active to passive or standby or off
	else if( 
			  (
			   (Pre_ACCStatus_Radar == ACC_STAT_ACTIVECONTROL)||
			   (Pre_ACCStatus_Radar == ACC_STAT_BRAKEONLYMODE)||
			   (Pre_ACCStatus_Radar == ACC_STAT_OVERRIDE)||
			   (Pre_ACCStatus_Radar == ACC_STAT_STANDSTILL)
			   )
			   &&
			   (
				(pLongCtrlCmd->Custom.CustomOutput.ACCStatus_Radar == ACC_STAT_PASSIVE)			
				||
				(pLongCtrlCmd->Custom.CustomOutput.ACCStatus_Radar == ACC_STAT_STANDBY)		
			  )
			)				
	{		
		pLongCtrlCmd->Custom.CustomOutput.ACCTextMessageBD10 = ACCTextMessageBD10_eACC_canceled;		
	}
	//priority 6: ACC active when state from passive or standby to active 
	else if( 
			  (
				(Pre_ACCStatus_Radar == ACC_STAT_PASSIVE)	||
				(Pre_ACCStatus_Radar == ACC_STAT_STANDBY)
			  )
			  &&
			 (
			   (pLongCtrlCmd->Custom.CustomOutput.ACCStatus_Radar  == ACC_STAT_ACTIVECONTROL)||
			   (pLongCtrlCmd->Custom.CustomOutput.ACCStatus_Radar  == ACC_STAT_BRAKEONLYMODE)||
			   (pLongCtrlCmd->Custom.CustomOutput.ACCStatus_Radar  == ACC_STAT_OVERRIDE)||
			   (pLongCtrlCmd->Custom.CustomOutput.ACCStatus_Radar  == ACC_STAT_STANDSTILL)	   
			  )
		)
	{
		b_notactive_driverselt = FALSE; 
	    b_notactive_dooropen = FALSE;
	    b_notactive_notDgear = FALSE;
	    b_notactive_espoff = FALSE;
	    b_notactive_epboff = FALSE;
		pLongCtrlCmd->Custom.CustomOutput.ACCTextMessageBD10 = ACCTextMessageBD10_eACC_activated;
	}
	//priority 7: ACC on when state change from off to error
	else if((Pre_ACCStatus_Radar == ACC_STAT_OFF)&&(pLongCtrlCmd->Custom.CustomOutput.ACCStatus_Radar!=ACC_STAT_OFF))
	{
		pLongCtrlCmd->Custom.CustomOutput.ACCTextMessageBD10 = ACCTextMessageBD10_eACC_on;
	}
	//priority 8:No display 
	else
	{
		//pLongCtrlCmd->Custom.CustomOutput.ACCTextMessageBD10 = ACCTextMessageBD10_eNo_display;
	}

	if( Pre_ACCTextInfo_Radar!= pLongCtrlCmd->Custom.CustomOutput.ACCTextMessageBD10 )
	{

		if(	(pLongCtrlCmd->Custom.CustomOutput.ACCTextMessageBD10 == ACCTextMessageBD10_edriver_belt_off)||
			(pLongCtrlCmd->Custom.CustomOutput.ACCTextMessageBD10 == ACCTextMessageBD10_eDoor_open)||
			(pLongCtrlCmd->Custom.CustomOutput.ACCTextMessageBD10 == ACCTextMessageBD10_eNot_in_Dgear)||
			(pLongCtrlCmd->Custom.CustomOutput.ACCTextMessageBD10 == ACCTextMessageBD10_eEPB_not_release)||
			(pLongCtrlCmd->Custom.CustomOutput.ACCTextMessageBD10 == ACCTextMessageBD10_eESP_off)||
			(pLongCtrlCmd->Custom.CustomOutput.ACCTextMessageBD10 == ACCTextMessageBD10_eACC_ativation_failure)		
			)
		{
			HMI_Display_counter = 250; //can not active display 5s
		}
		else
		{
			HMI_Display_counter = 150; //others display 3s
		}
	}
	else if(HMI_Display_counter ==0)
	{
		b_notactive_driverselt = FALSE; 
	    b_notactive_dooropen = FALSE;
	    b_notactive_notDgear = FALSE;
	    b_notactive_espoff = FALSE;
	    b_notactive_epboff = FALSE;
		pLongCtrlCmd->Custom.CustomOutput.ACCTextMessageBD10 = ACCTextMessageBD10_eNo_display;
	}
	else if(  (pLongCtrlCmd->Custom.CustomOutput.ACCTextMessageBD10 == ACCTextMessageBD10_efailure)&&
			  (pLongCtrlCmd->Custom.CustomOutput.ACCStatus_Radar != ACC_STAT_FAILUREMODE)
			)
	{
		pLongCtrlCmd->Custom.CustomOutput.ACCTextMessageBD10 = ACCTextMessageBD10_eNo_display;
	}
	else if(
				( pLongCtrlCmd->Custom.CustomOutput.ACCTextMessageBD10 == ACCTextMessageBD10_etake_over)&&
				( pLongCtrlCmd->KinFctInfo.headway_control_alert == FALSE)
			)
	{
		pLongCtrlCmd->Custom.CustomOutput.ACCTextMessageBD10 = ACCTextMessageBD10_eNo_display;
	}
	else if(
				( pLongCtrlCmd->Custom.CustomOutput.ACCTextMessageBD10 == ACCTextMessageBD10_eoverride)&&
				( pLongCtrlCmd->Custom.CustomOutput.ACCStatus_Radar  != ACC_STAT_OVERRIDE)
			)
	{
		pLongCtrlCmd->Custom.CustomOutput.ACCTextMessageBD10 = ACCTextMessageBD10_eNo_display;
	}	
	else if(
				(pLongCtrlCmd->Custom.CustomOutput.ACCTextMessageBD10 ==ACCTextMessageBD10_eoverride)||
				(pLongCtrlCmd->Custom.CustomOutput.ACCTextMessageBD10 ==ACCTextMessageBD10_etake_over)||
				(pLongCtrlCmd->Custom.CustomOutput.ACCTextMessageBD10 ==ACCTextMessageBD10_efailure)
		)
	{
		//do nothing 
	}
	else if((b_notactive_driverselt == TRUE)&&((InhibitReason_Soft_Off_Condition & INHIBITREASON_SOFT_OFF_CONDITION_SEATBELT_OPEN) == 0))
	{
		pLongCtrlCmd->Custom.CustomOutput.ACCTextMessageBD10 = ACCTextMessageBD10_eNo_display;
		b_notactive_driverselt = FALSE;
	}
	else if((b_notactive_dooropen == TRUE)&&((InhibitReason_Soft_Off_Condition & INHIBITREASON_SOFT_OFF_CONDITION_DOOR_OPEN_FRONT_LEFT) == 0))
	{
		pLongCtrlCmd->Custom.CustomOutput.ACCTextMessageBD10 = ACCTextMessageBD10_eNo_display;
		b_notactive_dooropen = FALSE;
	}
	else if(
				(b_notactive_notDgear == TRUE)&&
				(
					((InhibitReason_Soft_Off_Condition & INHIBITREASON_SOFT_OFF_CONDITION_GEAR_PNR) == 0)
					&&
					((InhibitReason_Soft_Off_Condition & INHIBITREASON_SOFT_OFF_CONDITION_MANUNAL_GEAR) == 0)
				)
			)
	{
		pLongCtrlCmd->Custom.CustomOutput.ACCTextMessageBD10 = ACCTextMessageBD10_eNo_display;
		b_notactive_notDgear = FALSE;
	}
	else if((b_notactive_epboff == TRUE)&&((InhibitReason_No_Ramp & INHIBITREASON_NO_RAMP_PARK_BRAKE_ACTIVE) == 0))
	{
		pLongCtrlCmd->Custom.CustomOutput.ACCTextMessageBD10 = ACCTextMessageBD10_eNo_display;
		b_notactive_epboff = FALSE;
	}
	else if((b_notactive_espoff ==TRUE)&& ((InhibitReason_No_Ramp & INHIBITREASON_NO_RAMP_ACTUATOR_OFF) == 0))
	{
		pLongCtrlCmd->Custom.CustomOutput.ACCTextMessageBD10 = ACCTextMessageBD10_eNo_display;
		b_notactive_espoff = FALSE;
	}
	else
	{
		HMI_Display_counter--;
	}


	if(		
		    (
				(Pre_ACCStatus_Radar == ACC_STAT_OFF)||
				(Pre_ACCStatus_Radar == ACC_STAT_PASSIVE)||
				(Pre_ACCStatus_Radar == ACC_STAT_STANDBY)||
				(Pre_ACCStatus_Radar == ACC_STAT_FAILUREMODE)
			)&&
			(
				(pLongCtrlCmd->Custom.CustomOutput.ACCStatus_Radar == ACC_STAT_ACTIVECONTROL)||
				(pLongCtrlCmd->Custom.CustomOutput.ACCStatus_Radar == ACC_STAT_BRAKEONLYMODE)||
				(pLongCtrlCmd->Custom.CustomOutput.ACCStatus_Radar == ACC_STAT_OVERRIDE)||
				(pLongCtrlCmd->Custom.CustomOutput.ACCStatus_Radar == ACC_STAT_STANDSTILL)		
			)		
		)
	{
		b_flag_igon = FALSE;
	}
	else if(pLongCtrlCmd->Custom.CustomOutput.ACCStatus_Radar == ACC_STAT_OFF)
	{
		b_flag_igon = TRUE;
	}
	else
	{
		// do nothing
	}

	// requests to ESP
	pLongCtrlCmd->KinOutput.UpperAccelerationValue = upper_acceleration_value;
	pLongCtrlCmd->KinOutput.LowerAccelerationValue = lower_acceleration_value;
	pLongCtrlCmd->KinOutput.UpperAccelerationRateValue = upper_acceleration_rate_value;
	pLongCtrlCmd->KinOutput.LowerAccelerationRateValue = lower_acceleration_rate_value;
	pLongCtrlCmd->KinOutput.Decel_LiM_Override_Active = cc_status->CC_CONTROL_DATA.DECEL_LIM_OVERRIDE_ACTIVE;
	
	// break pre signal mapping  in active mode and ego speed < 17m/s and target speed < 7m/s and acceleration request < -3.5m/s
	if ( (
			(pLongCtrlCmd->Custom.CustomOutput.ACCStatus_Radar == ACC_STAT_ACTIVECONTROL)
			||
			(pLongCtrlCmd->Custom.CustomOutput.ACCStatus_Radar == ACC_STAT_BRAKEONLYMODE)
			||
			(pLongCtrlCmd->Custom.CustomOutput.ACCStatus_Radar == ACC_STAT_OVERRIDE)						
		  )	
		 &&
		 (pVehDyn->Longitudinal.MotVar.Velocity <= (float32)threshold_breakpre_egospeed_value) //m/s
		 &&
		 (pFCTAccOOIData->AccOOINextLong.Kinematic.fVabsX <= (float32)threshold_breakpre_tarspeed_value)   //m/s
		 &&
		 (das_output->MIN_REQ_ACCEL <= threshold_breakpre_egoaccel_value) // m/s^2
	) 
	{
		pLongCtrlCmd->KinOutput.Brake_preferred = TRUE;
	}
	// else set to false
	else
	{
		pLongCtrlCmd->KinOutput.Brake_preferred = FALSE;
	}
	// if standstill then set to false 
	if(pLongCtrlCmd->Custom.CustomOutput.ACCStatus_Radar == ACC_STAT_STANDSTILL)
	{
		pLongCtrlCmd->KinOutput.Brake_preferred = FALSE;
	}
	else
	{
		// do nothing 
	}
	

	// shutdown mode output
	if (pLongCtrlCmd->Custom.CustomOutput.InhibitReason_No_Ramp != 0)
	{
		pLongCtrlCmd->Custom.CustomOutput.shutdownMode = ImmediateOff;
	}
	else if (pLongCtrlCmd->Custom.CustomOutput.InhibitReason_Rapid_Ramp != 0)
	{
		pLongCtrlCmd->Custom.CustomOutput.shutdownMode = FastOff;
	}
	else if (pLongCtrlCmd->Custom.CustomOutput.InhibitReason_Ramp != 0)
	{
		pLongCtrlCmd->Custom.CustomOutput.shutdownMode = SoftOff;
	}
	else
	{
		pLongCtrlCmd->Custom.CustomOutput.shutdownMode = NoReq;
	}
	
	// speed unit output
	if (cc_input->VEHICLE_STATUS.SPEED_UNIT_KMH == TRUE)
	{
		pLongCtrlCmd->Custom.CustomOutput.SpeedUnit = SPD_UNIT_KMH;
	}
	else
	{
		pLongCtrlCmd->Custom.CustomOutput.SpeedUnit = SPD_UNIT_MPH;
	}

	if (pLongCtrlCmd->Custom.CustomOutput.ACCStatus_Radar == ACC_STAT_OFF)
	{
		pLongCtrlCmd->Custom.CustomOutput.ACCStatus_OnOff = FALSE;
	}
	else if((driver_inputs->CC_Main_SWITCH.AKT_STATUS == FALSE)&&(pLongCtrlCmd->Custom.CustomOutput.ACCStatus_Radar == ACC_STAT_FAILUREMODE))
	{
		pLongCtrlCmd->Custom.CustomOutput.ACCStatus_OnOff = FALSE;
	}
	else
	{
		pLongCtrlCmd->Custom.CustomOutput.ACCStatus_OnOff = TRUE;
	}

	
	_PARAM_UNUSED(error_data);
	_PARAM_UNUSED(driver_inputs);
}/* PRQA S 7004 , 7012 */
/* date: 2018-03-26, reviewer: Ravi Kiran Gurrala, reason : Cyclomatic complexity. Not Safety critical*/



#if (LONG_CFG_USE_EXTERN_ACC_STATE_MACHINE)
/*********************************************************************************************************************
  @fn               KMC_v_ProcessExternalACCInterfaces */ /*!

  @description      Wrapper for internal control states. Set driver_requests->CONTROL_STATE and das_output->DAS_STAT 
                    based on Ext_AccState transmitted by external ACC state machine and based on internal inhibitions.
                    Additionally the set speed determined by the external ACC unit is assigned to the internal 
                    variable.

  @param[in]        pCcInputData->pENGINE_ECU_INPUT->Ext_AccState   External ACC State     

  @param[in]        pCcInputData->INHIBIT             Inhibition flags

  @param[in]        error_data->CC_INHIBIT            Inhibition flag

  @param[out]       driver_requests.CONTROL_STATE     Variable that reflects the proposed next state of the HMI 
                                                      state machine
  @param[out]       das_output->DAS_STAT              Driver assistance system status bits

  @traceability     doors://rbgs854a:40000/?version=2&prodID=0&view=00000002&urn=urn:telelogic::1-503e822e5ec3651e-O-171-0008a220
  @return           void

*********************************************************************************************************************/
void KMC_v_ProcessExternalACCInterfaces(const cc_input_data_t* pCcInputData,
                                        const cc_error_data_t* error_data,
                                        cc_driver_requests_t* driver_requests,
                                        cart_das_output_data_t* das_output)
{

}
#endif /* LONG_CFG_USE_EXTERN_ACC_STATE_MACHINE */


/*****************************************************************************

  @fn             KMC_v_Process */ /*!

  @description    Execute longitudinal functions (controller and hmi)

@startuml
Start
Partition KMC_v_Process(){
: Execute longitudinal functions (controller and hmi);
: Initialize output interface and Execute Init function if SW or HW reset;
: Select Parameter depending of different drive Modes;
: Check logical inhibition conditions;
: Determining driver operations;
: Custom function to process vehicle drive off conditions;
: Custom function to limit longitudinal acceleration according to customer requirements;
}
End
@enduml


  @param[in]      cycle_time : the cycle time (for non-first call:
                  ellapsed time since last call) in miliseconds

  @param[in]      pVehDyn : the raw vehicle dynamics

  @param[in]      pPowerTrain : the powertrain information (gear)

*/
#if (CFG_ACC_LEVER_INPUT)
/*!
  @param[in]      pAccLever : the ACC lever input
*/
#endif
/*!
  @param[in]      pLongCtrlResp : the longitudinal controller response
*/
#if (FCT_CFG_ACC_HEADWAY_PLANNER)
/*!
  @param[in]      pAccDisplayObj  the ACC display object from FCT_SEN
  @param[out]     pAccOutput the ACC output information from FCT_SEN
  @param[out]     pFctVehLongOut
*/
#endif
/*!
  @param[out]     pLongCtrlCmd : the output for the longitudinal controller

  @traceability   doors://rbgs854a:40000/?version=2&prodID=0&view=00000002&urn=urn:telelogic::1-503e822e5ec3651e-O-157-0008a220
  @return         void

*****************************************************************************/
void KMC_v_Process(const times_t cycle_time,
                   const VehDyn_t * pVehDyn,
                   const PowerTrain_t * pPowerTrain,
#if (CFG_ACC_LEVER_INPUT)
                   const AccLeverInput_t * pAccLever,
#endif
                   const LongCtrlInput_t * pLongCtrlResp,
#if (FCT_CFG_FCA)
                   const fct_output_data_t * pFCAOutput,
#endif
#if (FCT_CFG_DM)
                   const dm_output_data_t * pDMOutput,
#endif
#if (FCT_CFG_ACC_HEADWAY_PLANNER)
                   const acc_object_t * pAccDisplayObj,
                   const acc_output_data_t * pAccOutput,
#if (FCT_CFG_SEN2VEH_ACC_OOI_PORT)
                   const FCTSenAccOOI_t* pFCTAccOOIData,
#endif
#if (FCT_CFG_SLA_FEATURE)
                   const SLAData_t* pSLAData,
#endif
                   FctVeh2SenInfo_t * pFctVehLongOut,
#endif
                   LongCtrlOutput_t * pLongCtrlCmd)
{
#if (FCT_CFG_SEN2VEH_ACC_OOI_PORT)
  _PARAM_UNUSED(pFCTAccOOIData);
#endif

  /* Initialize output interface version information */
  pLongCtrlCmd->uiVersionNumber = FCT_LONG_CTRL_OUTPUT_INTFVER;

  /*! Execute Init function if SW or HW reset */
  if((LOPC_STATIC_MEMORY.LOPC_Frame.eLOPCState == LOPC_INIT) || (b_KmcIsInitialized == FALSE))
  {
    KMC_v_Init();
    b_KmcIsInitialized = TRUE;
  }

#if (FCT_CFG_CC)
  /*! Input Wrapper */
  KMC_v_InputWrapper(cycle_time,
                      pVehDyn,
#if (CFG_ACC_LEVER_INPUT)
                      pAccLever,
#endif
                      pLongCtrlResp,
                      pPowerTrain,
                      &(KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.DAS_INPUT_DATA),
#if (CFG_ACC_LEVER_INPUT)
                      &(KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.CC_DRIVER_INPUTS),
#endif
                      &(KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.CC_STATUS),
                      pFctVehLongOut,
                      &(KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.CC_DRIVER_CONTROLS),
                      &(KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.CC_INPUT_DATA),
					  &(KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.CC_ERROR_DATA)
                    );

#if (FCT_CFG_SLA_FEATURE)
  KMC_v_SLAInputWrapper(cycle_time, pLongCtrlResp,
                       pSLAData,
                       &(KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.DAS_INPUT_DATA),
                       &(KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.CC_STATUS.CC_SLA_HMI_DATA),
                       &(KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.CC_STATUS.CC_DRIVER_REQUESTS),
                       &(KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.CC_INPUT_DATA));
#endif

  /*! Select Parameter depending of different Mods */
  KMC_v_SelectParamSet();

  /*! Check signal states */
  KMC_v_SignalInhibitionCheck(pVehDyn,
#if (CFG_ACC_LEVER_INPUT)
                              pAccLever,
#endif
                              pLongCtrlResp,
                              &(KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.CC_INPUT_DATA),
                              &(KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.Inhibit_nr));

  /*! Check logical inhibition conditions */
  KMC_v_InhibitionCheck(cycle_time,
                        pVehDyn,
                        pLongCtrlResp,
                        &(KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.DAS_INPUT_DATA),
                        &DAS_INPUT_DATA_LAST_CYCLE,
                        &(KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.CC_DRIVER_CONTROLS),
#if (FCT_CFG_ACC_HEADWAY_PLANNER)
                        pAccOutput,
#endif
						&(KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.CC_DRIVER_INPUTS),
                        &(KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.CC_INPUT_DATA),
                        &(KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.CC_ERROR_DATA),
                        &(KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.CC_STATUS),
						&(KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.CC_DRIVER_INF));

  /*! Determ driver operations */
  KMC_v_DetermineDriverOperations(cycle_time,
                                  &(KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.DAS_INPUT_DATA),
                                  &(KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.CC_INPUT_DATA),
                                  &(KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.CC_DRIVER_CONTROLS),
                                  &(KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.CC_ERROR_DATA),
                                  &(KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.CC_STATUS),
#if (CFG_ACC_LEVER_INPUT)
                                  &(KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.CC_DRIVER_INPUTS)
#else
                                  pAccOutput
#endif
                                  );


  /*! Custom function to process additional creep mode according TJA requirements */
  KMC_v_ProcVehDriveOff(cycle_time,
                        pLongCtrlResp,
                        pFCTAccOOIData,
                        &(KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.DAS_INPUT_DATA),
                        &(KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.DAS_OUTPUT_DATA),
                        pAccOutput,
                        &(KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.CC_STATUS));


  /*! Custom function to limit longitudinal acceleration according customer requirements */
  KMC_v_LimitLongAccelCustom(cycle_time, &(KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.CC_STATUS), &(KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.CC_INPUT_DATA), pAccOutput, &(KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.DAS_INPUT_DATA), &(KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.DAS_OUTPUT_DATA), &(KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.CC_DRIVER_INF)
#if (FCT_CFG_SEN2VEH_ACC_OOI_PORT)
                             ,pFCTAccOOIData
#endif
#if CN_ACCSM
                               ,pAccDisplayObj
#endif
                            );


#if (FCT_CFG_SLA_FEATURE)
  KMC_v_SLADetermineState(pSLAData,
                         &(KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.CC_INPUT_DATA),
                         &(KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.CC_STATUS));
#endif

  KMC_v_ProcessMain(cycle_time,
                    &(KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.CC_DRIVER_CONTROLS),
                    &(KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.CC_INPUT_DATA),
                    &(KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.CC_ERROR_DATA),
                    &(KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.DAS_INPUT_DATA),
                    &(KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.DAS_OUTPUT_DATA),
#if (FCT_CFG_ACC_HEADWAY_PLANNER)
                    pAccOutput,
#endif
                    &(KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.CC_STATUS));

  /*! Call display wrapper function */
  KMC_v_InformDriver(&(KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.CC_STATUS.CC_DRIVER_REQUESTS),
                     pAccOutput,
#if (LONG_CFG_USE_EXTERN_ACC_STATE_MACHINE)
                     &(KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.CC_INPUT_DATA),
                     &(KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.DAS_INPUT_DATA),
#endif
                     pAccDisplayObj,
                     &(KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.CC_ERROR_DATA),
                     &(KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.CC_DRIVER_INF),
                     &(KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.DAS_OUTPUT_DATA));

  /*! Save das input data last cycle */
  DAS_INPUT_DATA_LAST_CYCLE = KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.DAS_INPUT_DATA;

#endif /* FCT_CFG_CC */

#if (CFG_FCT_CC_USE_HOLD_STILLSTAND_MOD)

  /* Modify CommandedAcceleration to hold in stillstand */
  if (KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.DAS_OUTPUT_DATA.DAS_STAT.DAS_STAND_STILL) {

    aCmdMax = aCmdMin = -2.0f;

    if (aCmdMax < aCmdMaxLast - 0.02f) {
      aCmdMax = aCmdMaxLast - 0.02f;
    }

    if (aCmdMin < aCmdMinLast - 0.02f) {
      aCmdMin = aCmdMinLast - 0.02f;
    }


    KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.DAS_OUTPUT_DATA.MAX_REQ_ACCEL = (acceleration_t)(aCmdMax * Acceleration_s);
    KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.DAS_OUTPUT_DATA.MIN_REQ_ACCEL = (acceleration_t)(aCmdMin * Acceleration_s);
  }

  aCmdMaxLast = (float32)KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.DAS_OUTPUT_DATA.MAX_REQ_ACCEL / (float32)Acceleration_s;
  aCmdMinLast = (float32)KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.DAS_OUTPUT_DATA.MIN_REQ_ACCEL / (float32)Acceleration_s;

#endif /*(CFG_FCT_CC_USE_HOLD_STILLSTAND_MOD)*/

#if (FCT_CFG_ACC_HEADWAY_PLANNER)
  /*! Fill FctVeh2SenInfo Port */
  KMC_v_FillVehToSenInfo(&(KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.CC_STATUS), 
                          &(KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.DAS_INPUT_DATA), 
                          pLongCtrlResp, 
                          pFctVehLongOut);
#endif


  /*! Determine soft stop request according to customer requirement (ARS410GY18 specific)*/
  KMC_v_SoftStopRequestFlag(&(KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.DAS_OUTPUT_DATA),
                                           &(KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.CC_DRIVER_INF),
                                           KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.DAS_INPUT_DATA.VEHICLE_SPEED,
                                           pAccDisplayObj,
                                           &(KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.CC_STATUS),
                                           pAccOutput,
                                           pLongCtrlCmd);

  /*! Call wrapper output function */
  KMC_v_OutputWrapper(cycle_time,
                      pFCTAccOOIData,
                      pAccOutput,
					  pVehDyn,
                      &(KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.CC_INPUT_DATA),
                      &(KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.DAS_INPUT_DATA),
                      &(KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.DAS_OUTPUT_DATA),
					  &(KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.CC_DRIVER_INPUTS),
					  pLongCtrlResp,
                      &(KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.CC_DRIVER_INF),
                      &(KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.CC_STATUS),
					  &(KMC_STATIC_MEMORY_UNION.KMC_STATIC_MEMORY.CC_ERROR_DATA),
                      pLongCtrlCmd);


#if (FCT_CFG_CC)
  (void)MeasFreeze_Lopc_GlobVar(FCT_MEAS_ID_LOPC_KMC_STATIC_MEM,        (void*)&(KMC_STATIC_MEMORY_UNION.MTS_DUMMY),     sizeof(kmc_static_mem_u_t));

#endif  /* FCT_CFG_CC */

}


#if (KMC_CFG_CUSTOM_ACCEL_ARBITRATION)
/*************************************************************************************************************************
  Functionname:         KMC_ACC_CUSTOM_ARBITRATION                                                                   */ /*!

  @brief                Custom acceleration source arbitration function

  @description          Custom function to arbitrate between various acceleration sources

  @return               None

  @param[in]            driver_requests
  @param[in]            acc_output
  @param[in,out]        cc_control_data
  @param[in,out]        accel_control_data
  @param[in]            das_input
  @param[in,out]        pLongCtrlCmd

  @glob_in              None
  @glob_out             None

  @c_switch_part        None  
  @c_switch_full        @ref FCT_CFG_LOPC_COMPONENT  \n
                        @ref KMC_CFG_CUSTOM_ACCEL_ARBITRATION  \n

  @pre                  None
  @post                 None

  @InOutCorrelation     Not defined
  @traceability         doors://rbgs854a:40000/?version=2&prodID=0&view=00000002&urn=urn:telelogic::1-503e822e5ec3651e-O-172-0008a220
  @author               Niraj Mistry | Niraj.Mistry@continental-corporation.com | +49 (69) 7603-6827
*************************************************************************************************************************/
extern void KMC_ACC_CUSTOM_ARBITRATION(const cc_driver_requests_t* driver_requests, const acc_output_data_t* acc_output, 
                                  cc_control_data_t* cc_control_data, cc_acceleration_control_data_t* accel_control_data,
                                  const cart_das_input_data_t* das_input, LongCtrlOutput_t* pLongCtrlCmd)
{
  
  _PARAM_UNUSED(driver_requests);
  _PARAM_UNUSED(acc_output);  
  _PARAM_UNUSED(cc_control_data);
  _PARAM_UNUSED(accel_control_data);
  _PARAM_UNUSED(das_input);
  _PARAM_UNUSED(pLongCtrlCmd);        

}
#endif //KMC_CFG_CUSTOM_ACCEL_ARBITRATION

#endif  /*!< (FCT_CFG_LOPC_COMPONENT  && LOPC_CFG_KMC)*/

/** @} end defgroup */

/* ************************************************************************* */
/*   Copyright ADC-GmbH, Lindau                                              */
/* ************************************************************************* */ // PRQA S 7013
