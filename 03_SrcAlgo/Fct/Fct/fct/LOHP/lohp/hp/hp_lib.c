/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC/LOHP/HP (Adaptive Cruise Control - Longitudinal Headway Planner - Headway Planner)

PACKAGENAME:               hp_lib.c

DESCRIPTION:               This module handles the estimation of distance control acceleration to an object

AUTHOR:                    Mistry Niraj (uidq5738)

CREATION DATE:             24.02.2017

VERSION:                   $Revision: 1.44 $

LEGACY VERSION:            Revision: 1.23

**************************************************************************** */

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/** 
@defgroup   hp_lib Hp_lib
@ingroup    hp
@brief      File contains functions for estimation of distance control acceleration to an object
@{ */ 

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "hp.h"
#include "hp_lib.h"

#if ((FCT_CFG_LOHP_COMPONENT) && (FCT_CFG_ACC_HEADWAY_PLANNER))


/*****************************************************************************
  MODULE LOCAL CONSTANTS
*****************************************************************************/

#if (CFG_FCT_ACC_TTS_CONTROLLER)
#define HP_TTS_PROF_MAX_DECEL   (-3.0f)
/*! Maximum launch acceleration for TTS speed controller [0.001 m/s²] */
#define Acc_tts_control_accel_launch_max ACC_TTS_CONTROL_ACCEL_LAUNCH_MAX
acceleration_t ACC_TTS_CONTROL_ACCEL_LAUNCH_MAX = 1000;// PRQA S 3408
/* date: 2018-06-13, reviewer: Ravi Kiran Gurrala, reason: Not Safety critical */
typedef struct
{
  float32 f_DistMin;
  float32 f_DistMax;
  float32 f_DistStop;
  float32 f_AccelMin;
  float32 f_AccelMax;
  float32 f_AccelStop;
  float32 f_DistError;
  float32 f_VeloError;
  float32 f_VeloTarget;
  boolean b_TargetStop;
}
HP_TTS_ProfileParam_t;
typedef struct
{
  float32 f_AccelMin;
  float32 f_DistMin;
  boolean b_Active;
}
HP_TTS_ApproachParam_t;

#else

#define HP_MIN_DIST_FOR_TTS_CALC   (50u)  /* Min available distance to be used for TTS Calculation (0.5m) */
#endif  /* CFG_FCT_ACC_TTS_CONTROLLER */
#define HP_FUZZY_TTS_BLEND_ACCEL_THRESHOLD   (10u)

/*****************************************************************************
  MODULE GLOBAL VARIABLES
*****************************************************************************/
#if ( FCT_CFG_DEBUG_FUZZY_CONTROLLER )
FuzzyDebugData_t FuzzyDebugDataControlObject;
FuzzyDebugData_t FuzzyDebugData;
FuzzyDebugData_t *pFuzzyDebugData = &FuzzyDebugData;
#endif

/*****************************************************************************
  MODULE FUNCTIONS
*****************************************************************************/
static times_t HP_t_CalcObjectTTS(const acc_object_t * const object);
static acceleration_t HP_t_CalcApproachDecel(const acc_object_t * const Object, const distance_t RequestedDistance);
#if (CFG_FCT_ACC_TTS_CONTROLLER)
static HP_TTS_ApproachParam_t HP_TTS_AppParReal[Acc_max_number_ooi];/*PRQA S 3218  */
/* date: 2018-06-13, reviewer: Ravi Kiran Gurrala, reason: kept here for better maintainability*/
static HP_TTS_ApproachParam_t HP_TTS_AppParSim[Acc_max_number_ooi];/*PRQA S 3218  */
/* date: 2018-06-13, reviewer: Ravi Kiran Gurrala, reason: kept here for better maintainability*/

static acceleration_t HP_t_CalcStopDecel(const acc_object_t * const object, percentage_t headway_setting);
static void HP_v_CalcAppProfile(const HP_TTS_ProfileParam_t *pt_ProfPar, boolean b_Init, HP_TTS_ApproachParam_t *pt_AppPar);
static void HP_v_CalcRefProfile(const HP_TTS_ProfileParam_t *pt_TTS_ProfPar, float32 *pf_VeloRef, float32 *pf_AccelRef, float32 *pf_WeightCtrl);
#else
static acceleration_t HP_t_CalcStopDecel(const acc_object_t * const object, const times_t time_to_stop, percentage_t headway_setting);
#endif


/*************************************************************************************************************************
  Functionname:    HP_t_DetermineDistControlAccel                                                                   */ /*!

  @brief           Determine the acceleration for the headway control

  @description     Depending on the relative distance, relative speed and the driving behaviors of both vehicles (the host vehicle 
                   and the object vehicle), the acceleration is calculated based on fuzzy logic in consideration of the different logic rules. 
                   The function HP_t_CalcApproachDecel calculates the acceleration for approaching to the intrusion distance and the function
                   HP_t_CalcStopDecel calculates the acceleration for stopping with the driver setting distance. 
                   The three calculated accelerations are merged to control the vehicle to either stop or to maintain the required distance.

          @startuml
          Start
            Partition HP_t_DetermineDistControlAccel {
              - Calculate real velocity of host vehicle
              - Determine TTS of host vehicle
              - Calculate maximal prediction time
              - Predict host vehicle velocity after prediction time assuming a PT1 behavior
              - Calculate the intrusion distance based on the headway setting and relative speed
              - Calculate the maximal acceleration/deceleration with the host vehicle speed for (FSR)ACC
              - Calculate control accel
              - Calculate control error
              - Execute fuzzy controller function to calculate the acceleration depending on different logic rules
              - Calculate TTS of object vehicle
              - Calculate required deceleration of object vehicle for a full stop
              - Calculate merging factor using the absolute target velocity
              - Evaluate blending between the fuzzy and TTS controller
              - Calculate requested acceleration using merging factor
              - Calculate needed deceleration for approaching
              If (Approach situation detected) then (true)
                - Merge with requested acceleration depending on relative speed
                - Merge with requested acceleration depending on host vehicle speed
                - Merge with requested acceleration depending on requested deceleration \n to maximal intrusion distance
                - Calculate ramp down factor in case of smooth approaching
                - Calculate requested acceleration again considering approach deceleration
              Endif
              - Blend with approach acceleration dependent on relative acceleration\n to start earlier brake release at end of follow deceleration
              - Blend with approach acceleration if obj dist is large for \nhigher headway settings to avoid strong reaction
              - Save calculation results to the corresponding object
              - Limit requested acceleration to maximal acceleration/deceleration limits
            }
          End 
          @enduml

  @return          Acceleration for the headway control in m/s2, multiplied with factor Acceleration_s. Range: [-30000...30000u]   

  @param[in]       headway_setting: actual headway setting in percent in %, Range: [0u... 100u]
  @param[in]       a_own: acceleration of the host vehicle in m/s2, multiplied with factor Acceleration_s. Range: [-30000...30000u]   
  @param[in,out]   Object: Pointer to acc input interface containing object data [acc_object_t as defined in Rte_Type.h]
                       Object->LONG_SPEED: object longitudinal speed in m/s, multiplied with factor Velocity_s. Range: [-30000...30000u]
                       Object->AUTOSAR.REL_LONG_SPEED: relative object longitudinal speed in m/s,  multiplied with factor Velocity_s. Range: [-30000...30000u]
                       Object->REQUESTED_DISTANCE_MODIFIED_PRED: predicted control distance modified by different functions in m, multiplied with factor Distance_s. Range: [-30000...30000u] 
                       Object->LONG_ACCEL_MODIFIED: modified object longitudinal acceleration in m/s2, multiplied with factor Acceleration_s. Range: [-30000...30000u] 
                       Object->AUTOSAR.LONG_DISPLACEMENT: longitudinal displacement of object in m, multiplied with factor Distance_s. Range: [-30000...30000u]  
                       Object->REQUESTED_DISTANCE_MODIFIED_ACT: current control distance modified by different functions in m, multiplied with factor Distance_s. Range: [-30000...30000u]
                       Object->CONTROL_SMOOTHNESS: smoothness value for longitudinal control in percent in %, Range: [0u... 100u]
                       Object->TTS: time to stop for objects stopping within the next seconds in s, multiplied with factor Time_s. Range: [0u... 65000u] 
                       Object->ACCEL_REQUEST_FUZZY: acceleration request from fuzzy controller in m/s2, multiplied with factor Acceleration_s. Range: [-30000...30000u]  
                       Object->ACCEL_REQUEST_TTS: acceleration request from physics to standstill in m/s2, multiplied with factor Acceleration_s. Range: [-30000...30000u]
                       Object->ACCEL_REQUEST_DMIN: acceleration request from physics to approach to set distance in m/s2, multiplied with factor Acceleration_s: Range: [-30000...30000u]  
                       Object->ALERT_MODIFICATION_FACTOR: Factor for modifying the alert distance with scale Factor_s (1000). Range: [-30000...30000u]

  @glob_in         -
  @glob_out        -

  @c_switch_part   FCT_CFG_FSRACC : Configuration switch enabeling Full Speed Range Adaptive Cruise Control functionality (with object evaluation and stop and go capability)
  @c_switch_full   FCT_CFG_LOHP_COMPONENT : Configuration switch for enabling LOHP component
  @c_switch_full   FCT_CFG_ACC_HEADWAY_PLANNER : Configuration switch enabeling Adaptive Cruise Control functionality (with object evaluation)
  @c_switch_full   HP_CFG_OVERTAKE_SUPPORT_FEATURE : Configuration switch enabling overtake support features

  @pre             - 
  @post            -

  @created         02.11.2016
  @changed         02.11.2016
  @traceability    doors://rbgs854a:40000/?version=2&prodID=0&view=00000002&urn=urn:telelogic::1-503e822e5ec3651e-O-104-0008a201

  @author          Liting Lu | liting.lu@continental-corporation.com | +49 1721626978
*************************************************************************************************************************/
acceleration_t HP_t_DetermineDistControlAccel(acc_object_t* const Object, percentage_t headway_setting, acceleration_t a_own)
{
  sint32         req_acc, help_var, rel_dist;
  signed_fuzzy_t req_acc_fuzzy;
  acceleration_t req_acc_tts;
  signed_fuzzy_t accel;
  signed_fuzzy_t control_error;
  acceleration_t max_accel,max_decel, req_acc_dInt, a_rel;
  distance_t requested_distance, max_intrusion_distance;
  velocity_t v_own, v_own_real;
  times_t  time_to_stop, max_pred_time;
  factor_t fac_tts_blend;

  v_own_real = (velocity_t)(Object->LONG_SPEED - Object->AUTOSAR.REL_LONG_SPEED);
  a_rel = Object->AUTOSAR.REL_LONG_ACCEL;
  /* calculate the time to stop of the host vehicle */
  time_to_stop = HP_t_DetermineTimeToStop(a_own, v_own_real);
  
  max_pred_time = (times_t)MAT_MIN((sint32)Acc_predicted_reaction_time, (sint32)time_to_stop);

  /*Predict vehicle velocity after prediction time */
  /* It is assumed that the host vehicle has a PT1 behavior */
  help_var = (sint32)a_own * (sint32)max_pred_time;
  help_var /= (sint32)Acceleration_s;
  help_var *= (sint32)Velocity_s; 
  help_var /= (sint32)Time_s;
  /* calculate the vehicle velocity within the prediction time */  
  v_own = (velocity_t)(v_own_real + help_var);
  v_own = (velocity_t)MAT_LIM((sint32)v_own,(sint32)0,(sint32)Speed_max);
  v_own_real = (velocity_t)MAT_LIM((sint32)v_own_real,(sint32)0,(sint32)Speed_max);

  requested_distance = Object->REQUESTED_DISTANCE_MODIFIED_PRED;
  /* calculate the intrusion distance based on the headway setting and relative speed */
  max_intrusion_distance = HP_t_DetermineMaxIntrusion(HP_t_GetAlertDistance(Object), requested_distance, v_own, headway_setting, 
                                                      Object->AUTOSAR.REL_LONG_SPEED, Object->ALERT_MODIFICATION_FACTOR, a_rel);

#if (FCT_CFG_FSRACC)
    /* calculate the maximal acceleration/deceleration with the host vehicle speed for FSR ACC*/
  max_accel = MAT_CALCULATE_PARAM_VALUE1D(Acc_fsr_max_acceleration,(uint16)Acc_fsr_max_acceleration_points, v_own_real);
  max_decel = MAT_CALCULATE_PARAM_VALUE1D(Acc_fsr_max_deceleration,(uint16)Acc_fsr_max_deceleration_points, v_own_real);
#else
    /* calculate the maximal acceleration/deceleration with the host vehicle speed for ACC */
  max_accel = MAT_CALCULATE_PARAM_VALUE1D(Acc_max_acceleration,(uint16)Acc_max_acceleration_points, v_own_real);
  max_decel = MAT_CALCULATE_PARAM_VALUE1D(Acc_max_deceleration,(uint16)Acc_max_deceleration_points, v_own_real);
#endif

  /*calculate control accel every time, although object is not detected!*/
  accel = (signed_fuzzy_t)Object->LONG_ACCEL_MODIFIED;
  /* calculate the headway control error */
  control_error = (signed_fuzzy_t)(Object->AUTOSAR.LONG_DISPLACEMENT - requested_distance);

  /*avoid division by zero*/
  if (Object->REQUESTED_DISTANCE_MODIFIED_ACT<1)
  {
    Object->REQUESTED_DISTANCE_MODIFIED_ACT = (distance_t)MAT_MAX((sint32)Object->REQUESTED_DISTANCE_MODIFIED_ACT, 1);
    Object->REQUESTED_DISTANCE_MODIFIED_PRED = (distance_t)MAT_MAX((sint32)Object->REQUESTED_DISTANCE_MODIFIED_PRED, 1);
  }
  rel_dist = MAT_DIV((sint32)Object->AUTOSAR.LONG_DISPLACEMENT, (sint32)Object->REQUESTED_DISTANCE_MODIFIED_ACT, Distance_s, Distance_s, Factor_s);
  /* call the fuzzy controller function to calculate the acceleration depending on different logic rules */
  req_acc_fuzzy =
    HP_v_DoFuzzy
    (  ( signed_fuzzy_t )rel_dist
     , ( signed_fuzzy_t )( Object->AUTOSAR.REL_LONG_SPEED - help_var )
     , accel
     , control_error
     , ( signed_fuzzy_t )( Object->AUTOSAR.LONG_DISPLACEMENT - max_intrusion_distance )
     , ( signed_fuzzy_t )Object->CONTROL_SMOOTHNESS
     , ( signed_fuzzy_t )v_own
     , ( signed_fuzzy_t )Object->LONG_SPEED
     , ( signed_fuzzy_t )Object->AUTOSAR.LONG_DISPLACEMENT
#if ( FCT_CFG_DEBUG_FUZZY_CONTROLLER )
     , pFuzzyDebugData
#endif
    );

  /* FuzzyDebugData */
#if ( FCT_CFG_DEBUG_FUZZY_CONTROLLER )
  /* Save a copy of the Fuzzy Controller inputs */
  FuzzyDebugData.FUZZY_INPUT_DATA.REL_DISTANCE = rel_dist;
  FuzzyDebugData.FUZZY_INPUT_DATA.SPEED_REL = ( signed_fuzzy_t )( Object->AUTOSAR.REL_LONG_SPEED - help_var );
  FuzzyDebugData.FUZZY_INPUT_DATA.A_OBJECT = accel;
  FuzzyDebugData.FUZZY_INPUT_DATA.DISTANCE_SET_ERROR = control_error;
  FuzzyDebugData.FUZZY_INPUT_DATA.DISTANCE_MIN_ERROR = ( signed_fuzzy_t )( Object->AUTOSAR.LONG_DISPLACEMENT - max_intrusion_distance );
  FuzzyDebugData.FUZZY_INPUT_DATA.SOFTNESS = ( signed_fuzzy_t )Object->CONTROL_SMOOTHNESS;
  FuzzyDebugData.FUZZY_INPUT_DATA.V_OWN = ( signed_fuzzy_t )v_own;
  FuzzyDebugData.FUZZY_INPUT_DATA.V_OBJ = ( signed_fuzzy_t )Object->LONG_SPEED;
  FuzzyDebugData.FUZZY_INPUT_DATA.DISTANCE = ( signed_fuzzy_t )Object->AUTOSAR.LONG_DISPLACEMENT;

#endif /* FCT_CFG_DEBUG_FUZZY_CONTROLLER */
  
  
  /*----------------------------------------------------------------------*/
  /* calculate the time until the object comes to a full stop */
  time_to_stop = HP_t_CalcObjectTTS(Object);
  /* calculate the needed deceleration to stop */
#if (CFG_FCT_ACC_TTS_CONTROLLER)
  req_acc_tts = HP_t_CalcStopDecel(Object, headway_setting);
  
  /* merge both accelerations */
  /* calculate the merging factor using the absolut target velocity */
  fac_tts_blend = MAT_CALCULATE_PARAM_VALUE1D(Acc_use_calc_tts_factor, Acc_use_calc_tts_factor_points, (sint16)Object->LONG_SPEED);

  /* with the factor the blending between the fuzzy and TTS controller is evaluated */
  req_acc = (acceleration_t)(MAT_MUL(fac_tts_blend, req_acc_tts, Factor_s, Acceleration_s, Acceleration_s) + MAT_MUL(Factor_s-fac_tts_blend, req_acc_fuzzy, Factor_s, Acceleration_s, Acceleration_s));
  
#else
  req_acc_tts = HP_t_CalcStopDecel(Object, time_to_stop, headway_setting);

  /* merge both accelerations */
  /* calculate the merging factor using the time to stop */
  fac_tts_blend = MAT_CALCULATE_PARAM_VALUE1D(Acc_use_calc_decel_factor, Acc_use_calc_decel_factor_points, (sint16)time_to_stop);
  /* for positive acceleration, the acceleration calculated by fuzzy logic is used */
  if((req_acc_fuzzy > (signed_fuzzy_t)HP_FUZZY_TTS_BLEND_ACCEL_THRESHOLD)&&(req_acc_tts >= Acc_minimum_calculated_brake_request))
  {
    req_acc = (acceleration_t)req_acc_fuzzy;
  }
  else
  {
  /* with the factor there is a transitional process to stop the vehicle */
    req_acc = (acceleration_t)(MAT_MUL((sint32)fac_tts_blend, (sint32)req_acc_tts, Factor_s, Acceleration_s, Acceleration_s) + MAT_MUL((sint32)Factor_s-fac_tts_blend, req_acc_fuzzy, Factor_s, Acceleration_s, Acceleration_s));
  }
    
#endif /* CFG_FCT_ACC_TTS_CONTROLLER */


  /*----------------------------------------------------------------------*/
  /* calculate needed deceleration for approaching*/
  req_acc_dInt = HP_t_CalcApproachDecel(Object, max_intrusion_distance); 
  /* select and merge both accelerations */
  /*if approach situation*/
  if(
     (req_acc_dInt < 0)     
     &&
     (Object->AUTOSAR.REL_LONG_SPEED < Acc_use_approach_decel_speed_factor[2*Acc_use_approach_decel_speed_factor_points-2])    
     &&
     (time_to_stop > 0)
    )
  {
    acceleration_t approach_accel;

    approach_accel = req_acc_dInt;
    /* merge with req_acc depending on relative speed */
    help_var = MAT_MIN(Factor_s, (sint32)MAT_CALCULATE_PARAM_VALUE1D(Acc_use_approach_decel_speed_factor, Acc_use_approach_decel_speed_factor_points, Object->AUTOSAR.REL_LONG_SPEED));
    help_var = (help_var * approach_accel) + (Factor_s - help_var)* (acceleration_t)req_acc;
    approach_accel = (acceleration_t)(help_var/Factor_s);
    /* merge with req_accel depending on host vehicle speed */
    help_var = MAT_MIN(Factor_s, (sint32)MAT_CALCULATE_PARAM_VALUE1D(Acc_use_approach_decel_v_host_factor, Acc_use_approach_decel_v_host_factor_points, v_own));
    help_var = (help_var * approach_accel) + (Factor_s - help_var)* (acceleration_t)req_acc;
    approach_accel = (acceleration_t)(help_var/Factor_s);
    /* merge with req_accel depending on object deceleration. Higher deceleration requires higher proportion of fuzzy controller */
    help_var = MAT_MIN(Factor_s, (sint32)MAT_CALCULATE_PARAM_VALUE1D(Acc_use_approach_decel_obj_accel_factor, Acc_use_approach_decel_obj_accel_factor_points, Object->LONG_ACCEL));
    help_var = (help_var * approach_accel) + (Factor_s - help_var)* (acceleration_t)req_acc;
    approach_accel = (acceleration_t)(help_var/Factor_s);
    /* merge with req_accel depending on requested decel to max intrusion */
    /* ramp deceleration down to zero in case of very smooth approaching */
    help_var = MAT_CALCULATE_PARAM_VALUE1D(Acc_use_approach_decel_decel_factor, Acc_use_approach_decel_decel_factor_points, req_acc_dInt);
    help_var = (help_var * approach_accel); 
    req_acc = (acceleration_t)MAT_LIM(help_var/Factor_s, (sint32)approach_accel, req_acc);
  }

  if((Object->AUTOSAR.REL_LONG_SPEED > Acc_vrel_val_fuzzy_to_dmin) && (req_acc_dInt <= 0) && (fac_tts_blend == 0))
  {
    help_var = MAT_CALCULATE_PARAM_VALUE1D(Acc_use_approach_arel_factor, (uint16)Acc_use_approach_arel_factor_points, (sint16)Object->AUTOSAR.REL_LONG_ACCEL);
    help_var = (help_var * req_acc) + (Factor_s - help_var)* (acceleration_t)req_acc_dInt;
    req_acc = (acceleration_t)MAT_LIM(help_var/Factor_s, (sint32)(req_acc*Acc_min_factor_fuzzy_to_dmin/Factor_s), (sint32)req_acc); 
  }

  /* Very high distance compensation to prevent overreaction on object decel */
  if((rel_dist > Hp_fuzzy_high_rel_dist_thres) && (req_acc_dInt <= 0))
  {
    help_var = MAT_CALCULATE_PARAM_VALUE1D(Acc_use_approach_dist_factor, (uint16)Acc_use_approach_dist_factor_points, (sint16)rel_dist);
    help_var = (sint32)MAT_MUL((sint32)help_var,(sint32)headway_setting,Acceleration_s, Scale_100,Acceleration_s);
    help_var = (help_var * req_acc_dInt) + (Factor_s - help_var) * (acceleration_t) req_acc;
    req_acc = (acceleration_t)MAT_LIM(help_var/Factor_s, (sint32)(req_acc*Acc_min_factor_fuzzy_to_dmin/Factor_s), (sint32)req_acc); 
  }

  /* assign the calculation results to the corresponding object */
  Object->TTS = time_to_stop;
  Object->ACCEL_REQUEST_FUZZY = (acceleration_t)req_acc_fuzzy;
  Object->ACCEL_REQUEST_TTS = req_acc_tts;
  Object->ACCEL_REQUEST_DMIN = req_acc_dInt;
 
  req_acc = MAT_LIM(req_acc, (sint32)max_decel, (sint32)max_accel);
  return (acceleration_t)req_acc;
}


/*************************************************************************************************************************
  Functionname:    HP_t_CalcApproachDecel                                                                           */ /*!

  @brief           Calculate the needed deceleration for approaching the object

  @description     The needed deceleration for approaching the object is calculated based on the requested distance 
                   and relative longitudinal velocity

          @startuml
          Start
            Partition HP_t_CalcApproachDecel {
              - Calculate distance considering requested intrusion distance
              If (Host vehicle is approaching to an object) then (true)
                - Calculate required deceleration to reach \n object's velocity at end of approaching
              Endif
            }
          End 
          @enduml

  @return          Needed deceleration for approaching in m/s2, multiplied with factor Acceleration_s. Range: [-30000...30000u]

  @param[in]       RequestedDistance: the following distance in m, multiplied with factor Distance_s. Range: [-30000...30000u]
  @param[in]       Object: Object: Pointer to acc input interface containing object data [acc_object_t as defined in Rte_Type.h]
                        Object->AUTOSAR.LONG_DISPLACEMENT: longitudinal displacement of object in m, multiplied with factor Distance_s. Range: [-30000...30000u] 
                        Object->AUTOSAR.REL_LONG_SPEED: relative object longitudinal speed in m/s, multiplied with factor Velocity_s. Range: [-30000...30000u] 

  @glob_in         - 
  @glob_out        - 

  @c_switch_part   -
  @c_switch_full   FCT_CFG_LOHP_COMPONENT : Configuration switch for enabling LOHP component
  @c_switch_full   FCT_CFG_ACC_HEADWAY_PLANNER : Configuration switch enabling Adaptive Cruise Control functionality (with object evaluation)

  @pre             - 
  @post            -

  @created         02.11.2016
  @changed         02.11.2016

  @author          Liting Lu | liting.lu@continental-corporation.com | +49 1721626978
*************************************************************************************************************************/
static acceleration_t HP_t_CalcApproachDecel(const acc_object_t * const Object, const distance_t RequestedDistance)
{
  sint32         help;
  distance_t dist;
  acceleration_t return_val;
  
  return_val = Acceleration_s;  /* return positive acceleration value in case of no approach situation */   
  dist = (distance_t)MAT_MAX((sint32)Distance_s, (sint32)(Object->AUTOSAR.LONG_DISPLACEMENT - (RequestedDistance)));
   /* when the distance is positive and the relative speed is negative, calculate the needed deceleration for approaching*/
  if(Object->AUTOSAR.REL_LONG_SPEED < Speed_s)
  {
   /* at the end of the approaching the host vehicle speed is the same as the object vehicle speed */
    help = (sint32)Object->AUTOSAR.REL_LONG_SPEED * (sint32)Object->AUTOSAR.REL_LONG_SPEED;
    help/= Velocity_s;
    help*= Distance_s;
    help/= ((-2)*dist);
    help*= Acceleration_s;
    help/= Velocity_s;
    return_val = (acceleration_t) MAT_LIM(help, (sint32)Acc_max_allowed_decel, (sint32)Acc_max_allowed_accel);
  }
  return return_val;
}


#if (CFG_FCT_ACC_TTS_CONTROLLER)
/*************************************************************************************************************************
  Functionname:    HP_t_CalcStopDecel                                                                               */ /*!

  @brief           Calculate the needed deceleration to stop with requested distance

  @description     The minimum stopping distance is calculated in consideration of the headway setting. The deceleration is 
                   calculated using the distance available to stop. This distance is equal to the difference between driven 
                   distances of ego and object vehicles. Both of these distances are calculated using the respective velocities 
                   and decelerations (s = v^2/(2a)).

          @startuml
          Start
            Partition HP_t_CalcStopDecel {
              - Calculate time constant for TTS controller
              - Initialize maximal and minimal gradient \n depending on the object's velocity
              - Initialize maximal and minimal acceleration
              - Initialize stop acceleration
              - Initialize maximal and minimal distance
              - Initialize stop distance
              - Calculate the minimum and maximum stopping \n distance to object taking the host vehicle speed as 0
              - Calculate the required stop distance using \n the headway setting with respect to the \n maximum and minimum stop distances
              - Transformation of signals to floating point representation
              - Calculate distance error/difference for TTS controller
              - Calculate velocity error/difference for TTS controller
              - Calculate velocity target/setpoint for TTS controller
              - Evaluation of relative Velocity and Acceleration Reference
              Repeat
                If (OOI not existing for index value) then (true)
                  - invalidate object without ID
                  - Set real and simulation profiles to neutral values
                Elseif (OOI existing for index value) then (true)
                  - Identify OOI number of actual object
                Endif
              Repeat while (Index < Acc_max_number_ooi)
              If (Actual object number is valid) then (true)
                If (Object motion is measured) then (true)
                - Calculate new real approach profile
                  If (Real approach profile is valid) then (true)
                    - Use calculated real approach profile for control
                    - Init sim approach profile with real profile
                  Endif
                Else
                  - Motion is simulated for alert
                  - Calculate new sim approach profile
                  If (Sim approach profile is valid) then (true)
                    - Use calculated sim approach profile for control
                  Endif
                Endif
                - Generation of Velocity and Acceleration for Reference Profile
              Else
                - Invalidate object
              Endif
              - Speed Control in Target Coordinate System
              - Calculate velocity delta
              - Calculate control acceleration depending on velocity delta, gradient and time constant
              - Back transformation of Commanded Acceleration to fixed point representation
              If (Long displacement < emergency brake distance) then (true)
                - Limit calculated control acceleration to <= Acc_emergency_brake_deceleration
              Endif
            }
          End 
          @enduml

  @return          Needed deceleration to stop in m/s2, multiplied with factor Acceleration_s. Range: [-30000...30000u]

  @param[in]       time_to_stop: the time until the host vehicle comes to a full stop in s, multiplied with factor Time_s. Range: [0u... 65000u] 
  @param[in]       headway_setting: actual headway setting in percent in %, Range: [0u... 100u] 
  @param[in]       object: Object: Pointer to acc input interface containing object data [acc_object_t as defined in Rte_Type.h]
                       object->LONG_ACCEL_MODIFIED: modified object longitudinal accelerationin in m/s2, multiplied with factor Acceleration_s. Range: [-30000...30000u] 
                       object->LONG_SPEED: object longitudinal speed in m/s, multiplied with factor Velocity_s. Range: [-30000...30000u]
                       object->AUTOSAR.LONG_DISPLACEMENT: longitudinal displacement of object in m, multiplied with factor Distance_s. Range: [-30000...30000u]
                       object->AUTOSAR.REL_LONG_SPEED: relative object longitudinal speed in m/s, multiplied with factor Velocity_s. Range: [-30000...30000u] 
   

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_LOHP_COMPONENT : Configuration switch for enabling LOHP component
  @c_switch_full   FCT_CFG_ACC_HEADWAY_PLANNER : Configuration switch enabeling Adaptive Cruise Control functionality (with object evaluation)

  @pre             - 
  @post            -

  @created         02.11.2016
  @changed         02.11.2016

  @author          Liting Lu | liting.lu@continental-corporation.com | +49 1721626978
*************************************************************************************************************************/
static acceleration_t HP_t_CalcStopDecel(const acc_object_t * const object, percentage_t headway_setting)
{
  uint8 i;
  ObjNumber_t s_OOI_Nr;
  acceleration_t s_AccelOut;
  distance_t mindist, maxdist, reqdist;
  HP_TTS_ProfileParam_t t_TTS_ProfPar;
  float32 f_VeloRef, f_VeloDelta;
  float32 f_AccelRef, f_AccelCmd, f_WeightCtrl;

  float32 f_TimeConst = (float32)Acc_tts_control_time_const / (float32)Time_s;
  float32 f_AccelLaunchMax = (float32)Acc_tts_control_accel_launch_max / (float32)Acceleration_s;
  float32 f_GradMin = (float32)MAT_CALCULATE_PARAM_VALUE1D(Acc_max_neg_grad, Acc_neg_grad_points, (sint16)object->LONG_SPEED) / (float32)Acceleration_s;
  float32 f_GradMax = (float32)MAT_CALCULATE_PARAM_VALUE1D(Acc_max_pos_grad_neg_accel, Acc_pos_grad_neg_accel_points, (sint16)object->LONG_SPEED) / (float32)Acceleration_s;

  t_TTS_ProfPar.f_AccelMin = (float32)Acc_tts_control_accel_ramp_min / (float32)Acceleration_s;
  t_TTS_ProfPar.f_AccelMax = (float32)Acc_tts_control_accel_ramp_max / (float32)Acceleration_s;
  t_TTS_ProfPar.f_AccelStop = (float32)Acc_tts_control_accel_ramp_stop / (float32)Acceleration_s;

  t_TTS_ProfPar.f_DistMin = (float32)Acc_tts_control_dist_ramp_min / (float32)Distance_s;
  t_TTS_ProfPar.f_DistMax = (float32)Acc_tts_control_dist_ramp_max / (float32)Distance_s;
  t_TTS_ProfPar.f_DistStop = t_TTS_ProfPar.f_DistMin / t_TTS_ProfPar.f_AccelMin * t_TTS_ProfPar.f_AccelStop;

  /* calculate the minimum and maximum distance to object depending on the object speed */
  mindist = MAT_CALCULATE_PARAM_VALUE1D(Acc_headway_min_dist, Acc_headway_min_dist_points, (sint16)object->LONG_SPEED);
  maxdist = MAT_CALCULATE_PARAM_VALUE1D(Acc_headway_max_dist, Acc_headway_max_dist_points, (sint16)object->LONG_SPEED);

  /* calculate the required stop distance using the headway setting with respect to the maximum and minimum stop distances */
  reqdist = (distance_t)MAT_MAX((((sint32)headway_setting * ((sint32)maxdist - (sint32)mindist)) / (sint32)Percentage_max + (sint32)mindist), 1);

  /* Transformation of signals to floating point representation */
  t_TTS_ProfPar.f_DistError = (float32)(reqdist - object->AUTOSAR.LONG_DISPLACEMENT)/(float32)Distance_s;
  t_TTS_ProfPar.f_VeloError = (float32)(-object->AUTOSAR.REL_LONG_SPEED)/(float32)Velocity_s;
  t_TTS_ProfPar.f_VeloTarget = (float32)(object->LONG_SPEED)/(float32)Velocity_s;

  /* Evaluation of relative Velocity and Acceleration Reference */
  t_TTS_ProfPar.b_TargetStop = ((object->AUTOSAR.OBJECT_STATUS.STANDING) || (object->AUTOSAR.OBJECT_STATUS.STOPPED));

  /* loop through OOI profile array */
  s_OOI_Nr = OBJ_INDEX_NO_OBJECT;
  for (i=0u; i<Acc_max_number_ooi; i++)
  {
    /* invalidate objects without ID */
    if (LOHP_pPubFctObjList->HeaderAssessedObjList.aiOOIList[i] == OBJ_INDEX_NO_OBJECT)
    {
      /* Real Profiles */
      HP_TTS_AppParReal[i].f_AccelMin = 0.0f;
      HP_TTS_AppParReal[i].f_DistMin = 0.0f;
      HP_TTS_AppParReal[i].b_Active = FALSE;

      /* Sim Profiles */
      HP_TTS_AppParSim[i].f_AccelMin = 0.0f;
      HP_TTS_AppParSim[i].f_DistMin = 0.0f;
      HP_TTS_AppParSim[i].b_Active = FALSE;
    }
    /* identify OOI number of actual object */
    else if (LOHP_pPubFctObjList->HeaderAssessedObjList.aiOOIList[i] == object->AUTOSAR.OBJECT_ID)
    {
      s_OOI_Nr = (ObjNumber_t)i;
    }
	else
	{
		/*Added to make QAC Happy*/
	}
  }

  /* if OOI number is valid */
  if (s_OOI_Nr > OBJ_INDEX_NO_OBJECT)
  {
    /* if motion is real measured */
    if (object->AUTOSAR.OBJECT_STATUS.MEASURED)
    {
      /* calc new real approach profile */
      HP_v_CalcAppProfile(&t_TTS_ProfPar, object->AUTOSAR.OBJECT_STATUS.NEW, &HP_TTS_AppParReal[s_OOI_Nr]);

      /* if real approach profile is valid */
      if (HP_TTS_AppParReal[s_OOI_Nr].b_Active)
      {
        /* use calculated real approach profile for control */
        t_TTS_ProfPar.f_AccelMin = HP_TTS_AppParReal[s_OOI_Nr].f_AccelMin;
        t_TTS_ProfPar.f_DistMin = HP_TTS_AppParReal[s_OOI_Nr].f_DistMin;

        /* init sim approach profile with real profile */
        HP_TTS_AppParSim[s_OOI_Nr] = HP_TTS_AppParReal[s_OOI_Nr];
      }
    }
    /* if motion is simulated for alert */
    else
    {
      /* calc new sim approach profile */
      HP_v_CalcAppProfile(&t_TTS_ProfPar, object->AUTOSAR.OBJECT_STATUS.NEW, &HP_TTS_AppParSim[s_OOI_Nr]);

      /* if sim approach profile is valid */
      if (HP_TTS_AppParSim[s_OOI_Nr].b_Active)
      {
        /* use calculated sim approach profile for control */
        t_TTS_ProfPar.f_AccelMin = HP_TTS_AppParSim[s_OOI_Nr].f_AccelMin;
        t_TTS_ProfPar.f_DistMin = HP_TTS_AppParSim[s_OOI_Nr].f_DistMin;
      }
    }

    /* Generation of Velocity and Acceleration for Reference Profile */
    HP_v_CalcRefProfile(&t_TTS_ProfPar, &f_VeloRef, &f_AccelRef, &f_WeightCtrl);
  }
  /* OOI number invalid - should not happen at all */
  else
  {
    f_VeloRef = 0.0f;
    f_AccelRef = 0.0f;
    f_WeightCtrl = 1.0f;
  }
  
  /* Speed Control in Target Coordinate System */
  f_VeloDelta = t_TTS_ProfPar.f_VeloError-f_VeloRef;
  if (f_VeloDelta < f_GradMin*CML_Sqr(f_TimeConst))
  {
    f_AccelCmd = f_AccelRef + CML_f_Sqrt(2.0f*f_VeloDelta*f_GradMin - CML_Sqr(f_TimeConst)*CML_Sqr(f_GradMin));
  }
  else if (f_VeloDelta > f_GradMax*CML_Sqr(f_TimeConst))
  {
    f_AccelCmd = f_AccelRef - CML_f_Sqrt(2.0f*f_VeloDelta*f_GradMax - CML_Sqr(f_TimeConst)*CML_Sqr(f_GradMax));
  }
  else
  {
    f_AccelCmd = f_AccelRef + CML_Min(-f_VeloDelta/f_TimeConst*f_WeightCtrl, f_AccelLaunchMax);
  }

  /* Backtransformation of Commanded Acceleration to fixed point representation */
  s_AccelOut = (acceleration_t)(f_AccelCmd * (float32)Acceleration_s);
  s_AccelOut = (acceleration_t)MAT_LIM(s_AccelOut, Acc_max_allowed_decel, Acc_max_allowed_accel);

  if(object->AUTOSAR.LONG_DISPLACEMENT < Acc_emergency_brake_distance)
  {
    /*if distance is too low -> emergency brake*/
    s_AccelOut = (acceleration_t)MAT_LIM(s_AccelOut, Acc_max_allowed_decel, Acc_emergency_brake_deceleration);
  }

  return s_AccelOut;
}

#else  /* CFG_FCT_ACC_TTS_CONTROLLER */
/*************************************************************************************************************************
  Functionname:    HP_t_CalcStopDecel                                                                               */ /*!

  @brief           Calculate the needed deceleration to stop with requested distance

  @description     The minimum stopping distance is calculated in consideration of the headway setting. The deceleration is 
                   calculated using the distance available to stop. This distance is equal to the difference between driven 
                   distances of ego and object vehicles. Both of these distances are calculated using the respective velocities 
                   and decelerations (s = v^2/(2a)).

          @startuml
          Start
            Partition HP_t_CalcStopDecel {
              - Calculate the minimum and maximum stopping \n distance to object taking the host vehicle speed as 0
              - Calculate the required stop distance using \n the headway setting with respect to the \n maximum and minimum stop distances
              If (Time to stop for object is lesser than 10s) then (True)
                - Local variables a_obj(Object acceleration),\n v_obj (Object speed), v_ego (Ego speed) saved
                - a_obj and v_obj set to 0 for negative object speed (toggling signals)
                - (Current distance to Obj - Required stop distance)\n gives distance for host (delta_s_ego)
                - Distance target obj covers before stopping calculated (delta_s_obj)
                - Total stopping distance is delta_s_obj + delta_s_ego
                - Deceleration is -v_ego^2/(2*(ds_obj+ds_ego))
                - Ideal Vrel determined dependent on distance to object
                - Factor dependent on difference of ideal Vrel and actual Vrel determined
                note right
                Factors used to increase deceleration earlier 
                in braking scenarios to achieve lower relative
                speeds at the end. Reduction of end jerk.
                endnote
                - Factor increased for lower ego speeds
                - Calculated deceleration increased by multiplying with factor
                - Output deceleration increased to set parameters for low distance values
              Else (False)
                - Return Output acceleration as 0
              Endif
              - Output limited to allowed deceleration limits
            }
          End
          @enduml

  @return          Needed deceleration to stop in m/s2, multiplied with factor Acceleration_s. Range: [-30000...30000u]

  @param[in]       time_to_stop: the time until the host vehicle comes to a full stop in s, multiplied with factor Time_s. Range: [0u... 65000u] 
  @param[in]       headway_setting: actual headway setting in percent in %, Range: [0u... 100u] 
  @param[in]       object: Object: Pointer to acc input interface containing object data [acc_object_t as defined in Rte_Type.h]
                       object->LONG_ACCEL_MODIFIED: modified object longitudinal accelerationin in m/s2, multiplied with factor Acceleration_s. Range: [-30000...30000u] 
                       object->LONG_SPEED: object longitudinal speed in m/s, multiplied with factor Velocity_s. Range: [-30000...30000u]
                       object->AUTOSAR.LONG_DISPLACEMENT: longitudinal displacement of object in m, multiplied with factor Distance_s. Range: [-30000...30000u]
                       object->AUTOSAR.REL_LONG_SPEED: relative object longitudinal speed in m/s, multiplied with factor Velocity_s. Range: [-30000...30000u] 
   

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_LOHP_COMPONENT : Configuration switch for enabling LOHP component
  @c_switch_full   FCT_CFG_ACC_HEADWAY_PLANNER : Configuration switch enabling Adaptive Cruise Control functionality (with object evaluation)

  @pre             - 
  @post            -

  @created         02.11.2016
  @changed         01.10.2019

  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 6976036827
*************************************************************************************************************************/
static acceleration_t HP_t_CalcStopDecel(const acc_object_t * const object, const times_t time_to_stop, percentage_t headway_setting)
{
  acceleration_t out_accel, a_obj;
  distance_t req_stop_distance, mindist, maxdist;
  velocity_t v_obj, v_ego;

  /* calculate the minimum and maximum stopping distance to object taking the ego vehicle speed as 0*/
  mindist = MAT_CALCULATE_PARAM_VALUE1D(Acc_headway_min_dist, Acc_headway_min_dist_points, 0);
  maxdist = MAT_CALCULATE_PARAM_VALUE1D(Acc_headway_max_dist, Acc_headway_max_dist_points, 0);
  /* calculate the required stop distance using the headway setting with respect to the maximum and minimum stop distances */
  req_stop_distance = (distance_t)MAT_MAX((((sint32)headway_setting * ((sint32)maxdist - (sint32)mindist)) / (sint32)Percentage_max + (sint32)mindist), 1);

  out_accel = 0;
   /* Check if stop is necessary */
  if(time_to_stop < Acc_tts_default_value)
  {
    sint32         help1, help2, delta_s_ego, delta_s_obj, temp_accel;
    a_obj = object->LONG_ACCEL_MODIFIED;
    v_obj = object->LONG_SPEED;
    v_ego = object->LONG_SPEED - object->AUTOSAR.REL_LONG_SPEED ;

    /* if object speed is <= 0 -> object is stationary! */
    if(v_obj <= 0) 
    {
      v_obj = 0;
      if(a_obj < 0)
      {
        a_obj = 0;
      }      
    }
    
    /* calculate distance available for stopping */
    delta_s_ego = (sint32)object->AUTOSAR.LONG_DISPLACEMENT - req_stop_distance ;
    if(v_obj > 0)
    {
      if(a_obj < -Acc_min_decel_resolution)
      {
        /* ds_obj = -v_obj^2/(2*a_obj) */
        help1 = -MAT_MUL((sint32)v_obj, (sint32)v_obj, Velocity_s, Velocity_s, Factor_s);
        delta_s_obj = MAT_DIV(help1, (sint32)(2*a_obj), Factor_s, Distance_s, Acceleration_s);
      }
      else
      {
        delta_s_obj = 0;
      }
    }
    else
    {
      delta_s_obj = 0;
    }
    /* Dist covered by ego = Available dist to obj + Dist covered by obj */
    help2 = delta_s_obj + delta_s_ego;
    /* restrict available distance to 0.5m to avoid small denominator */
    help2 = MAT_LIM(help2, (sint32)HP_MIN_DIST_FOR_TTS_CALC, (sint32)Acc_object_max_distance_for_tts_calc);

    /* Calculate deceleration for available limit */
    /* decel = -v_ego^2/(2*(ds_obj+ds_ego)) */
    help1 = MAT_MUL((sint32)v_ego, (sint32)v_ego, Velocity_s, Velocity_s, Factor_s);
    temp_accel = MAT_DIV(-help1, 2*(help2), Factor_s, Distance_s, Acceleration_s);
    out_accel = (acceleration_t)MAT_LIM(temp_accel, (sint32)Acc_max_allowed_decel, (sint32)Acc_minimum_calculated_brake_request);
     
    /* Deceleration increase based on factor */
    if(out_accel < Acc_minimum_calculated_brake_request)
	{
      help1 = MAT_CALCULATE_PARAM_VALUE1D(Acc_tts_dist_vrel, Acc_tts_dist_vrel_points, (sint16)delta_s_ego);
      help1 = MAT_CALCULATE_PARAM_VALUE1D(Acc_tts_del_vrel_fac, Acc_tts_del_vrel_fac_points, (sint16)(object->AUTOSAR.REL_LONG_SPEED-help1)); 
      help1 = MAT_MUL(help1,(sint32)MAT_CALCULATE_PARAM_VALUE1D(Acc_tts_vego_fac, Acc_tts_vego_fac_points, (v_ego)), Factor_s,Factor_s,Factor_s); 

      out_accel = (acceleration_t)MAT_MUL((sint32)out_accel, (Factor_s+help1), Acceleration_s, Factor_s, Acceleration_s);
	}
	else
	{
		/* No increase required since TTS output above minimum threshold */
    }
    if(object->AUTOSAR.LONG_DISPLACEMENT < Acc_emergency_brake_distance)
    {
      /*if distance is too low -> emergency brake*/
      out_accel = (acceleration_t)MAT_LIM((sint32)out_accel, (sint32)Acc_max_allowed_decel, (sint32)Acc_emergency_brake_deceleration);
    } 
    else if((delta_s_ego < Hp_tts_min_brake_dist) && (delta_s_obj == 0))
    {
      /* Object is stationary and very close, decel output should be atleast as desired in standstill */
      out_accel = (acceleration_t)MAT_LIM((sint32)out_accel, (sint32)Acc_max_allowed_decel, (sint32)Acc_standstill_accel_req);
    }
    else
    {
      /* Do nothing */
    }
    
    out_accel = (acceleration_t)MAT_LIM((sint32)out_accel, (sint32)Acc_max_allowed_decel, (sint32)Acc_minimum_calculated_brake_request);
  }

  out_accel = (acceleration_t)MAT_LIM((sint32)out_accel, (sint32)Acc_max_allowed_decel, (sint32)Acc_max_allowed_accel);
  return out_accel;
}

#endif /* CFG_FCT_ACC_TTS_CONTROLLER */

#if (CFG_FCT_ACC_TTS_CONTROLLER)
/*************************************************************************************************************************
  Functionname:    HP_v_InitAppProfile                                                                              */ /*!

  @brief           Initialize approach profile for specific object for TTS controller

  @description     Initialize approach profile for specific object for TTS controller

          @startuml
          Start
            Partition HP_v_CalcAppProfile {
              If (Distance error < minimum distance \n AND Velocity error > 0) then (true)
                - Calculate new Approach profile
                If (INIT case OR reduced deceleration) then (true)
                  - Takeover of limited Approach Profile
                Endif
              Else
                - Takeover of Base Profile
              Endif
            }
          End 
          @enduml

  @return          -

  @param[in]       pt_ProfPar:  Pointer to base control profile
  @param[in]       b_Init:      Flag for initialization
  @param[out]      pt_AppPar:   Pointer to approach profile

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_LOHP_COMPONENT : Configuration switch for enabling LOHP component
  @c_switch_full   FCT_CFG_ACC_HEADWAY_PLANNER : Configuration switch enabeling Adaptive Cruise Control functionality (with object evaluation)
  @c_switch_full   CFG_FCT_ACC_TTS_CONTROLLER : Switch to control version of TTS controller used

  @pre             -
  @post            -

  @created         17.05.2018
  @changed         17.05.2018

  @author          Wolfgang Borgs | wolfgang.borgs@continental-corporation.com | +49-69-7603-6828
*************************************************************************************************************************/
static void HP_v_CalcAppProfile(const HP_TTS_ProfileParam_t *pt_ProfPar, boolean b_Init, HP_TTS_ApproachParam_t *pt_AppPar)
{
  float32 f_RootArg, f_AccProf;

  if ((pt_ProfPar->f_DistError < pt_ProfPar->f_DistMin) && (pt_ProfPar->f_VeloError > 0.0f))
  {
    /* Calculate new Approach profile */
    f_RootArg = CML_Sqr(pt_ProfPar->f_DistError) - CML_Sqr(pt_ProfPar->f_VeloError)*(pt_ProfPar->f_DistMin / pt_ProfPar->f_AccelMin);
    f_AccProf = (pt_ProfPar->f_DistError + CML_f_Sqrt(CML_Max(f_RootArg, 0.0f))) * (pt_ProfPar->f_AccelMin / pt_ProfPar->f_DistMin);

    /* if INIT case OR reduced deceleration */
    if (((b_Init) || (pt_AppPar->b_Active)) && (f_AccProf > pt_AppPar->f_AccelMin))
    {
      /* Takeover of limited Approach Profile */
      pt_AppPar->f_AccelMin = CML_MinMax(HP_TTS_PROF_MAX_DECEL, pt_ProfPar->f_AccelMin, f_AccProf);
      pt_AppPar->f_DistMin = pt_ProfPar->f_DistMin * pt_AppPar->f_AccelMin / pt_ProfPar->f_AccelMin;
      pt_AppPar->b_Active = TRUE;
    }
  }
  else
  {
    /* Takeover of Base Profile */
    pt_AppPar->f_AccelMin = pt_ProfPar->f_AccelMin;
    pt_AppPar->f_DistMin = pt_ProfPar->f_DistMin;
    pt_AppPar->b_Active = TRUE;
  }
}
#endif /* CFG_FCT_ACC_TTS_CONTROLLER */

#if (CFG_FCT_ACC_TTS_CONTROLLER)
/*************************************************************************************************************************
  Functionname:    HP_v_CalcRefProfile                                                                              */ /*!

  @brief           Calculate reference profile for time to stop controller

  @description     Calculate reference profile for time to stop controller

          @startuml
          Start
            Partition HP_v_CalcRefProfile {
              - Evaluation of relative Velocity and Acceleration Reference
              If (Object stopped) then (true)
                If (Distance error < minimum distance) then (true)
                  - Calculate velocity reference
                  - Calculate acceleration reference
                  - Set weight control to 1
                Elseif (Distance error < stop distance) then (true)
                  - Calculate velocity reference
                  - Calculate velocity scale
                  - Calculate acceleration reference
                  - Set weight control to 1
                Elseif (Distance error < 0.5 * stop distance) then (true)
                  - Calculate stop velocity
                  - Calculate velocity reference
                  - Calculate acceleration reference
                  - Set weight control to 1
                Else
                  - Set velocity reference to 0
                  - Set acceleration reference to stop acceleration
                  - Set weight control to 0
                Endif
              Else
                If (Distance error < minimum distance) then (true)
                  - Approach area of constant deceleration
                  - Calculate reference velocity
                  - Calculate reference acceleration
                Elseif (Distance error < 0) then (true)
                  - Approach area of linear deceleration
                  - Calculate reference velocity
                  - Calculate reference acceleration
                Else
                  - Intrusion area
                  - Limitation of negative velocity reference according to object velocity
                  If (Condition for negative velocity reference limitation \n depending on target velocity) then (true)
                    - Limitation by triangle acceleration profile
                    If (Distance error < 0.5 * distance limit) then (true)
                      - Area of rising acceleration
                      - Calculate reference velocity
                      - Calculate reference acceleration
                    Elseif (Distance error < distance limit) then (true)
                      - Area of falling acceleration
                      - Calculate reference velocity
                      - Calculate reference acceleration
                    Else
                      - Area of zero acceleration
                      - Set reference velocity to target velocity
                      - Set reference acceleration to 0
                    Endif
                  Else
                    - Limitation by trapezoid acceleration profile
                    - Calculate distance limit
                    If (Distance error < maximal distance) then (true)
                      - Area of rising acceleration
                      - Calculate reference velocity
                      - Calculate reference acceleration
                    Elseif (Distance error < (distance limit - maximal distance)) then (true)
                      - Area of constant acceleration
                      - Calculate reference velocity
                      - Calculate reference acceleration
                    Elseif (Distance error < distance limit) then (true)
                      - Area of falling acceleration
                      - Calculate reference velocity
                      - Calculate reference acceleration
                    Else
                      - Area of zero acceleration
                      - Set reference velocity to target velocity
                      - Set reference acceleration to 0
                    Endif
                  Endif
                Endif
              - Set weight control to 1
              Endif
            }
          End 
          @enduml

  @return          -

  @param[in]       pt_TTS_ProfPar:
  @param[out]      pf_VeloRef: Pointer to reference velocity
  @param[out]      pf_AccelRef:Pointer to reference acceleration

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_LOHP_COMPONENT : Configuration switch for enabling LOHP component
  @c_switch_full   FCT_CFG_ACC_HEADWAY_PLANNER : Configuration switch enabeling Adaptive Cruise Control functionality (with object evaluation)
  @c_switch_full   CFG_FCT_ACC_TTS_CONTROLLER : Switch to control version of TTS controller used

  @pre             -
  @post            -

  @created         13.02.2018
  @changed         13.02.2018

  @author          Wolfgang Borgs | wolfgang.borgs@continental-corporation.com | +49 (8382) 9699-839
*************************************************************************************************************************/
static void HP_v_CalcRefProfile(const HP_TTS_ProfileParam_t *pt_TTS_ProfPar, float32 *pf_VeloRef, float32 *pf_AccelRef, float32 *pf_WeightCtrl)
{
  /* Evaluation of relative Velocity and Acceleration Reference */
  float32 f_AccDistRoot, f_VeloStop, f_VeloScale;

  /* If object is stopped */
  if (pt_TTS_ProfPar->b_TargetStop)
  {
    if (pt_TTS_ProfPar->f_DistError < pt_TTS_ProfPar->f_DistMin)
    {
      *pf_VeloRef = CML_f_Sqrt(pt_TTS_ProfPar->f_AccelMin * (2.0f*pt_TTS_ProfPar->f_DistError - pt_TTS_ProfPar->f_DistMin));
      *pf_AccelRef = pt_TTS_ProfPar->f_AccelMin * pt_TTS_ProfPar->f_VeloError / *pf_VeloRef;
      *pf_WeightCtrl = 1.0f;
    }
    else if (pt_TTS_ProfPar->f_DistError < pt_TTS_ProfPar->f_DistStop)
    {
      f_AccDistRoot = CML_f_Sqrt(pt_TTS_ProfPar->f_AccelMin/pt_TTS_ProfPar->f_DistMin);
      *pf_VeloRef = -pt_TTS_ProfPar->f_DistError * f_AccDistRoot;
      f_VeloScale = pt_TTS_ProfPar->f_VeloError + (*pf_VeloRef - pt_TTS_ProfPar->f_VeloError) *
                                                  (pt_TTS_ProfPar->f_DistError - pt_TTS_ProfPar->f_DistMin) /
                                                  (pt_TTS_ProfPar->f_DistStop -  pt_TTS_ProfPar->f_DistMin);
      *pf_AccelRef = - f_VeloScale * f_AccDistRoot;
      *pf_WeightCtrl = 1.0f;
    }
    else if (pt_TTS_ProfPar->f_DistError < 0.5f*pt_TTS_ProfPar->f_DistStop)
    {
      f_AccDistRoot = CML_f_Sqrt(pt_TTS_ProfPar->f_AccelMin/pt_TTS_ProfPar->f_DistMin);
      f_VeloStop = -pt_TTS_ProfPar->f_DistStop * f_AccDistRoot;
      *pf_VeloRef = CML_f_Sqrt(pt_TTS_ProfPar->f_AccelStop * (2.0f*pt_TTS_ProfPar->f_DistError - pt_TTS_ProfPar->f_DistStop));
      *pf_AccelRef = pt_TTS_ProfPar->f_AccelStop;
      *pf_WeightCtrl = CML_Min(pt_TTS_ProfPar->f_VeloError/f_VeloStop, 1.0f);
    }
    else
    {
      *pf_VeloRef = 0.0f;
      *pf_AccelRef = pt_TTS_ProfPar->f_AccelStop;
      *pf_WeightCtrl = 0.0f;
    }
  }
  /* If object is moving */
  else
  {
    /* Approach area of constant deceleration */
    if (pt_TTS_ProfPar->f_DistError < pt_TTS_ProfPar->f_DistMin)
    {
      *pf_VeloRef = CML_f_Sqrt(pt_TTS_ProfPar->f_AccelMin * (2.0f*pt_TTS_ProfPar->f_DistError - pt_TTS_ProfPar->f_DistMin));
      *pf_AccelRef = pt_TTS_ProfPar->f_AccelMin * pt_TTS_ProfPar->f_VeloError / CML_Max(*pf_VeloRef, 0.1f);
    }
    /* Approach area of linear deceleration */
    else if (pt_TTS_ProfPar->f_DistError < 0.0f)
    {
      f_AccDistRoot = CML_f_Sqrt(pt_TTS_ProfPar->f_AccelMin/pt_TTS_ProfPar->f_DistMin);
      *pf_VeloRef = -pt_TTS_ProfPar->f_DistError * f_AccDistRoot;
      *pf_AccelRef = -pt_TTS_ProfPar->f_VeloError * f_AccDistRoot;
    }
    /* Intrusion area */
    else
    {
      float32 f_DistLim;

      /* Limitation of negative velocity reference according to object velocity */
      if (CML_Sqr(pt_TTS_ProfPar->f_VeloTarget) < 2.0f*pt_TTS_ProfPar->f_DistMax*pt_TTS_ProfPar->f_AccelMax)
      {
        /* Limitation by triangle acceleration profile */
        f_DistLim = pt_TTS_ProfPar->f_VeloTarget * CML_f_Sqrt(2.0f*pt_TTS_ProfPar->f_DistMax/pt_TTS_ProfPar->f_AccelMax);

        /* Area of rising acceleration */
        if (pt_TTS_ProfPar->f_DistError < 0.5f*f_DistLim)
        {
          f_AccDistRoot = CML_f_Sqrt(pt_TTS_ProfPar->f_AccelMax/pt_TTS_ProfPar->f_DistMax);
          *pf_VeloRef = -pt_TTS_ProfPar->f_DistError * f_AccDistRoot;
          *pf_AccelRef = -pt_TTS_ProfPar->f_VeloError * f_AccDistRoot;
        }
        /* Area of falling acceleration */
        else if (pt_TTS_ProfPar->f_DistError < f_DistLim)
        {
          *pf_VeloRef = -CML_f_Sqrt(pt_TTS_ProfPar->f_AccelMax / pt_TTS_ProfPar->f_DistMax
            * (2.0f*f_DistLim*pt_TTS_ProfPar->f_DistError-0.5f*CML_Sqr(f_DistLim)-CML_Sqr(pt_TTS_ProfPar->f_DistError)) );
          *pf_AccelRef = pt_TTS_ProfPar->f_AccelMax/pt_TTS_ProfPar->f_DistMax
            * (f_DistLim-pt_TTS_ProfPar->f_DistError) * pt_TTS_ProfPar->f_VeloError/CML_Min(*pf_VeloRef, -0.1f);
        }
        /* Area of zero acceleration */
        else
        {
          *pf_VeloRef = -pt_TTS_ProfPar->f_VeloTarget;
          *pf_AccelRef = 0.0f;
        }
      }
      else
      {
        /* Limitation by trapezoid acceleration profile */
        f_DistLim = pt_TTS_ProfPar->f_DistMax + CML_Sqr(pt_TTS_ProfPar->f_VeloTarget)/(2.0f*pt_TTS_ProfPar->f_AccelMax);

        /* Area of rising acceleration */
        if (pt_TTS_ProfPar->f_DistError < pt_TTS_ProfPar->f_DistMax)
        {
          f_AccDistRoot = CML_f_Sqrt(pt_TTS_ProfPar->f_AccelMax/pt_TTS_ProfPar->f_DistMax);
          *pf_VeloRef = -pt_TTS_ProfPar->f_DistError * f_AccDistRoot;
          *pf_AccelRef = -pt_TTS_ProfPar->f_VeloError * f_AccDistRoot;
        }
        /* Area of constant acceleration */
        else if (pt_TTS_ProfPar->f_DistError < f_DistLim-pt_TTS_ProfPar->f_DistMax)
        {
          *pf_VeloRef = -CML_f_Sqrt(pt_TTS_ProfPar->f_AccelMax * (2.0f*pt_TTS_ProfPar->f_DistError-pt_TTS_ProfPar->f_DistMax));
          *pf_AccelRef = pt_TTS_ProfPar->f_AccelMax * pt_TTS_ProfPar->f_VeloError/CML_Min(*pf_VeloRef, -0.1f);
        }
        /* Area of falling acceleration */
        else if (pt_TTS_ProfPar->f_DistError < f_DistLim)
        {
          *pf_VeloRef = -CML_f_Sqrt( pt_TTS_ProfPar->f_AccelMax*(2.0f*f_DistLim-3.0f*pt_TTS_ProfPar->f_DistMax)
            + (pt_TTS_ProfPar->f_DistError+pt_TTS_ProfPar->f_DistMax-f_DistLim)
            * (pt_TTS_ProfPar->f_AccelMax+pt_TTS_ProfPar->f_AccelMax/pt_TTS_ProfPar->f_DistMax*(f_DistLim-pt_TTS_ProfPar->f_DistError)));
          *pf_AccelRef = pt_TTS_ProfPar->f_AccelMax/pt_TTS_ProfPar->f_DistMax
            * (f_DistLim-pt_TTS_ProfPar->f_DistError) * pt_TTS_ProfPar->f_VeloError/CML_Min(*pf_VeloRef, -0.1f);
        }
        /* Area of zero acceleration */
        else
        {
          *pf_VeloRef = -pt_TTS_ProfPar->f_VeloTarget;
          *pf_AccelRef = 0.0f;
        }
      }
    }
    *pf_WeightCtrl = 1.0f;
  }
}
#endif /* CFG_FCT_ACC_TTS_CONTROLLER */

/*************************************************************************************************************************
  Functionname:    HP_t_CalcObjectTTS                                                                               */ /*!

  @brief           Calculate the time until the object comes to a full stop (with special care to acc)

  @description     The function HP_t_DetermineTimeToStop is called to calculate the time to stop of the object vehicle,
                   if it is determined that the object vehicle will probably stop.

          @startuml
          Start
            Partition HP_t_CalcObjectTTS {
              - Set TTS (time to stop) variable to initialization value
              If (Object detected) then (true)
                If (Object might come to standstill) then (true)
                  - Determine time to stop considering object's acceleration and speed
                  If (Object's acceleration is smaller than threshold \n AND Object's speed is smaller than threshold \n AND Object's relative speed is smaller than threshold) then (true)
                    - Set time to stop to 0s
                  Endif
                Endif
              Endif
            }
          End 
          @enduml

  @return          Time to stop of the object vehicle in s, multiplied with factor Time_s. Range: [0u... 65000u]  

  @param[in]       object: Pointer to acc input interface containing object data [acc_object_t as defined in Rte_Type.h]
                       object->AUTOSAR.OBJECT_STATUS.DETECTED: status of the object, Range: [True, False]
                       object->LONG_ACCEL: longitudinal acceleration of the object in m/s2, multiplied with factor Acceleration_s. Range: [-30000...30000u] 
                       object->LONG_SPEED: object longitudinal speed, in m/s, multiplied with factor Velocity_s. Range: [-30000...30000u]                                
                       object->AUTOSAR.LONG_DISPLACEMENT: longitudinal displacement of object in m, multiplied with factor Distance_s. Range: [-30000...30000u] 
                       object->AUTOSAR.REL_LONG_SPEED: relative object longitudinal speedin m/s, multiplied with factor Velocity_s. Range: [-30000...30000u]  

  @glob_in         - 
  @glob_out        - 
                               
  @c_switch_part   - 
  @c_switch_full   FCT_CFG_LOHP_COMPONENT : Configuration switch for enabling LOHP component
  @c_switch_full   FCT_CFG_ACC_HEADWAY_PLANNER : Configuration switch enabling Adaptive Cruise Control functionality (with object evaluation)

  @pre             - 
  @post            -

  @created         02.11.2016
  @changed         02.11.2016

  @author          Liting Lu | liting.lu@continental-corporation.com | +49 1721626978
*************************************************************************************************************************/
static times_t HP_t_CalcObjectTTS(const acc_object_t * const object)
{
  times_t tts;
  tts = Acc_tts_default_value;
  if(object->AUTOSAR.OBJECT_STATUS.DETECTED == TRUE)
  {
    /*if object standstill is probable */
    if(
       (
        (object->LONG_ACCEL < (Acc_object_decel_for_tts_calc))
        ||
        (object->LONG_SPEED < Acc_object_speed_for_tts_calc)
       )
       &&
       (object->AUTOSAR.LONG_DISPLACEMENT < Acc_object_max_distance_for_tts_calc)
       &&
       (object->AUTOSAR.REL_LONG_SPEED < Acc_object_rel_speed_for_tts_calc)
      )
    {
      tts = HP_t_DetermineTimeToStop(object->LONG_ACCEL, object->LONG_SPEED);
      
      /* For negative relative velocity, low obj speed and acceleration, TTS made 0. Configured for stationary approaches */
      if(
          (tts == Acc_tts_default_value) &&
          (object->LONG_ACCEL < Acc_object_accel_for_tts_zero) &&
          (object->LONG_SPEED < Acc_object_speed_for_tts_zero) &&
          (object->AUTOSAR.REL_LONG_SPEED < Acc_rel_speed_for_tts_zero) /* Rel speed added to distinguish between approach and normal city driving */
        )
      {
        tts = 0u;
      }

#if (CFG_FCT_ACC_TTS_CONTROLLER == SWITCH_OFF)
      /* Ramping out of TTS calculation for robustness against sensor measurements */
      if ((object->TTS < Acc_use_calc_decel_factor[0]) && (tts == Acc_tts_default_value) && (object->LONG_ACCEL < Acc_object_accel_for_tts_zero))
      {
        tts = object->TTS + Hp_tts_grad_limit;
        tts = (times_t)MAT_LIM((sint32)tts, (sint32)object->TTS, (sint32)Acc_tts_default_value);
      }
#endif
    }
  }

  return tts;
}

/*************************************************************************************************************************
  Functionname:    HP_t_GetAlertDistance                                                                            */ /*!

  @brief           Calculate the alert distance for a specific object speed

  @description     The alert distance is calculated based on the object vehicle speed. It is multiplied by the 
                   ALERT_MODIFICATION_FACTOR which is dependent on the situation.

          @startuml
          Start
            Partition HP_t_GetAlertDistance {
              - Calculate alert distance with an 1D interpolation based on object's velocity
              - Modify alert distance with modification factor
            }
          End 
          @enduml
  
  @return          Alert distance in m, multiplied with factor Distance_s. Range: [0...30000u]  

  @param[in]       object: Pointer to acc input interface containing object data [acc_object_t as defined in Rte_Type.h] 
                       object->LONG_SPEED: object longitudinal speed in m/s, multiplied with factor Velocity_s. Range: [-30000...30000u] 
                       object->ALERT_MODIFICATION_FACTOR: Factor for modifying the alert distance with scale Factor_s (1000). Range: [-30000...30000u]

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_LOHP_COMPONENT : Configuration switch for enabling LOHP component
  @c_switch_full   FCT_CFG_ACC_HEADWAY_PLANNER : Configuration switch enabeling Adaptive Cruise Control functionality (with object evaluation)

  @pre             - 
  @post            - 

  @created         02.11.2016
  @changed         02.11.2016

  @traceability    doors://rbgs854a:40000/?version=2&prodID=0&view=00000002&urn=urn:telelogic::1-503e822e5ec3651e-O-102-0008a201

  @author          Liting Lu | liting.lu@continental-corporation.com | +49 172 1626978
*************************************************************************************************************************/
distance_t HP_t_GetAlertDistance(const acc_object_t *object)
{
  distance_t alert_dist;

  alert_dist = (distance_t)MAT_CALCULATE_PARAM_VALUE1D(Acc_max_alert_thres, (uint16)Acc_max_alert_thres_points, object->LONG_SPEED);

  /*modify alert distance with factor*/
  alert_dist = (distance_t)MAT_MUL((sint32)alert_dist, (sint32)object->ALERT_MODIFICATION_FACTOR, Distance_s, Factor_s, Distance_s); 

  return alert_dist;
}

/*************************************************************************************************************************
  Functionname:    HP_t_DetermineMaxIntrusion                                                                       */ /*!

  @brief           Calculate the maximum allowed intrusion distance for a given alert distance and a requested distance

  @description     Minimum and maximum instrusion distances are calculated based on vehicle speed. They are then modified 
                   based on headway setting and requested distance. The difference between max and min intrusion distance 
                   is modified based on relative velocity which also considers approach/following scenarios. This 
                   difference along with min intrusion distance is modified as per alert modification factor. The end 
                   distance is limited within alert and requested distance and returned as output.

          @startuml
          Start
            Partition HP_t_DetermineMaxIntrusion {
              - Determine minimal requested distance (headway setting = 0)
              - Determine maximal intrusion distance depending\n on host vehicle speed (upper limit)
              - Calculate minimum intrusion distance based on\n maximum intrusion distance (lower limit)
              - Increase intrusion distance (min and max) depending\n on headway setting (maximum = requested distance)
              - Limit upper intrusion distance to the requested distance
              - Use relative velocity to calculate i_IntrusionDistanceFactor\nApproach (Larger vrel) has larger factor
              - Positive Arel used to reduce i_IntrusionDistanceFactor
              - Set the intrusion distance according to i_IntrusionDistanceFactor\n between min and max undershooting
              - Apply alert modification factor
              - Apply valid limits
            }
          End 
          @enduml
  
  @return          Maximum intrusion distance in m, multiplied with factor Distance_s. Range: [0...30000u]

  @param[in]       AlertDistance: alert threshold distance in m, multiplied with factor Distance_s. Range: [0...30000u] 
  @param[in]       RequestedDistance: following distance in m, multiplied with factor Distance_s. Range: [0...30000u] 
  @param[in]       VehicleSpeed: host vehicle speed in m/s, multiplied with factor Velocity_s. Range: [-30000...30000u]  
  @param[in]       headway_setting: actual headway setting in percent in %, Range: [0u... 100u]
  @param[in]       Relative_Speed: object vehicle relative speed in m/s, multiplied with factor Velocity_s. Range: [-30000...30000u] 
  @param[in]       modification_factor: factor for modifying the alert distance, multiplied with factor Factor_s Range: [-30000...30000u]
  @param[in]       Relative_Accel: object vehicle relative acceleration in m/s^2, multiplied with Acceleration_s. Range: [-10000...10000u]

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_LOHP_COMPONENT : Configuration switch for enabling LOHP component
  @c_switch_full   FCT_CFG_ACC_HEADWAY_PLANNER : Configuration switch enabling Adaptive Cruise Control functionality (with object evaluation)

  @pre             - 
  @post            - 

  @created         02.11.2016
  @changed         02.11.2016

  @traceability    doors://rbgs854a:40000/?version=2&prodID=0&view=00000002&urn=urn:telelogic::1-503e822e5ec3651e-O-103-0008a201

  @author          Liting Lu | liting.lu@continental-corporation.com | +49 172 1626978
*************************************************************************************************************************/
distance_t HP_t_DetermineMaxIntrusion(distance_t AlertDistance, distance_t RequestedDistance, velocity_t VehicleSpeed, percentage_t headway_setting, velocity_t Relative_Speed, factor_t modification_factor, acceleration_t Relative_Accel)
{
  sint32 i_MinRequestedDistance;
  sint32 i_IntrusionDistance, i_MinIntrusionDistance, i_MaxIntrusionDistance;
  sint32 i_IntrusionDistanceFactor;
  sint32 i_help_var;

  /*! Determ minimal requested distance (headway setting = 0) */
  i_MinRequestedDistance= MAT_CALCULATE_PARAM_VALUE1D(Acc_headway_min_dist, Acc_headway_min_dist_points, VehicleSpeed);

  /*! Determ maximal intrusion distance depending of host vehicle speed (upper limit) */
  i_MaxIntrusionDistance = MAT_CALCULATE_PARAM_VALUE1D(Acc_max_intrusion_distance, (uint16)Acc_max_intrusion_distance_points, VehicleSpeed);

  /* Calculate minimum intrusion distance based on maximum intrusion distance (lower limit)*/
  i_help_var = MAT_CALCULATE_PARAM_VALUE1D(Acc_min_to_max_intrusion_factor, (uint16)Acc_min_to_max_intrusion_factor_points, VehicleSpeed);
  i_MinIntrusionDistance = i_MaxIntrusionDistance*i_help_var;
  i_MinIntrusionDistance /= (sint32)Factor_s;

  /*! Increase intrusion distance (min and max) depending on headway setting (maximum = requested distance) */
  i_IntrusionDistanceFactor = MAT_CALCULATE_PARAM_VALUE1D(Acc_intrusion_headway_factor, (uint16)Acc_intrusion_headway_factor_points, (sint16)headway_setting);
  i_help_var = ((sint32)RequestedDistance - i_MinRequestedDistance) * i_IntrusionDistanceFactor;
  i_help_var /= (sint32)Factor_s;
  i_MinIntrusionDistance += i_help_var;
  i_MaxIntrusionDistance += i_help_var;

  /*! Limit upper intrusion distance to the requested distance */
  i_MaxIntrusionDistance = MAT_LIM(i_MaxIntrusionDistance, i_MinIntrusionDistance, (sint32)RequestedDistance);

  /*! Relation between relative speed and vehicle speed, to be independent from host vehicle velocity */
  /*! Use relative velocity relation to distinguish between approach and following scenarios */
  i_IntrusionDistanceFactor = MAT_CALCULATE_PARAM_VALUE1D(Acc_intrusion_vrel_factor, (uint16)Acc_intrusion_vrel_factor_points, Relative_Speed);
   
  /* Reduce intrusion factor for big positive relative acceleration to prevent object driving away */
  i_IntrusionDistanceFactor = MAT_MUL( i_IntrusionDistanceFactor, 
                                      (sint32)MAT_CALCULATE_PARAM_VALUE1D(Acc_intrusion_arel_factor, (uint16)Acc_intrusion_arel_factor_points, Relative_Accel) , 
                                      Distance_s, Factor_s, Distance_s);

  /*! Set the intrusion distance according to i_IntrusionDistanceFactor between min and max undershooting */
  i_IntrusionDistance = MAT_MUL( (i_MaxIntrusionDistance - i_MinIntrusionDistance), i_IntrusionDistanceFactor, Distance_s, Factor_s, Distance_s);
  i_IntrusionDistance += i_MinIntrusionDistance;

  /* Apply alert modification factor */
  i_IntrusionDistance = MAT_MUL(i_IntrusionDistance, (sint32)modification_factor, Distance_s, Factor_s, Distance_s);

  /*! Apply valid limits */
  i_IntrusionDistance = MAT_LIM(i_IntrusionDistance, (sint32)AlertDistance, (sint32)RequestedDistance);

  return (distance_t)i_IntrusionDistance;
}

/*************************************************************************************************************************
  Functionname:    HP_t_DetermineTimeToStop                                                                        */ /*!

  @brief           Calculate the time until the vehicle comes to a full stop

  @description     The time until the vehicle comes to a full stop is calculated based on current velocity and acceleration.

          @startuml
          Start
            Partition HP_t_DetermineTimeToStop {
              If (Vehicle's velocity > 0) then (true)
                If (Vehicle's acceleration < 0) then (true)
                  - Calculate time to stop (vel/accel)
                  - Limit calculation result
                Else
                  - Set TTS (time to stop) to default value (10s)
                Endif
              Else
                - Set TTS (time to stop) to 0s
              Endif
            }
          End 
          @enduml
  
  @return          Time to stop of the vehicle in s, multiplied with factor Time_s. Range: [0u... 65000u]  

  @param[in]       acceleration: acceleration of the vehicle in m/s2, multiplied with factor Acceleration_s. Range: [-30000...30000u]
  @param[in]       velocity: velocity of the vehicle in m/s, multiplied with factor Velocity_s. Range: [-30000...30000u] 

  @glob_in         -
  @glob_out        -
  
  @c_switch_part   - 
  @c_switch_full   FCT_CFG_LOHP_COMPONENT : Configuration switch for enabling LOHP component
  @c_switch_full   FCT_CFG_ACC_HEADWAY_PLANNER : Configuration switch enabling Adaptive Cruise Control functionality (with object evaluation)

  @pre             -
  @post            -

  @created         02.11.2016
  @changed         02.11.2016
  @traceability    doors://rbgs854a:40000/?version=2&prodID=0&view=00000002&urn=urn:telelogic::1-503e822e5ec3651e-O-105-0008a201

  @author          Liting Lu | liting.lu@continental-corporation.com | +49 172 1626978
*************************************************************************************************************************/
times_t HP_t_DetermineTimeToStop(const acceleration_t acceleration, const velocity_t velocity)
{
  times_t time_to_stop;
  sint32  help_var_tts;

  /*calculate time to stop of host vehicle*/
  if(velocity > (velocity_t)0)
  {
    if(acceleration < (acceleration_t)0)
    {
      help_var_tts = MAT_MIN((sint32)acceleration, (sint32)(-Acc_min_decel_resolution));          
      time_to_stop = (times_t)MAT_LIM(MAT_DIV((sint32)(-velocity), help_var_tts, Velocity_s, Acceleration_s, Time_s), 0, (sint32)Acc_tts_default_value);
    }
    else
    {
      time_to_stop = Acc_tts_default_value;
    }
  }
  else
  {
    /* when the speed of the vehicle is not positive */
    time_to_stop = 0u;
  }
  
  return time_to_stop;
}

#if ( HP_CFG_OVERTAKE_SUPPORT_FEATURE )
/*************************************************************************************************************************
  Functionname:    HP_t_DetermineMinDecelDistance                                                                   */ /*!

  @brief           Calculate the distance that the vehicle requires to increase the relative velocity to 0

  @description     Calculate the distance that the vehicle requires to increase the relative velocity to 0
                   in case the maximal allowed deceleration and maximal deceleration gradient is used for decelerating.
                   The result can be used for bypassing the approach control deceleration during
                   an overtake support situation if the calculated distance is smaller than the longitudinal
                   displacement minus the maximal intrusion.

          @startuml
          Start
            Partition HP_t_DetermineMinDecelDistance {
              - Initialize deceleration distance with 0m
              If (Object's relative velocity < 0m/s) then (true)
                - Transform several inputs to floating point variables
                - Calculate the distance (f32_sDelay) that might be covered, caused by the system's reaction time (0.3s)
                - Calculate delta between current host acceleration and maximum possible deceleration
                - Calculate the maximal deceleration gradient depending on host vehicle speed
                - Transform deceleration gradient to floating point
                - Calculate required time (f32_t1) to reach maximum allowed deceleration dependent of deceleration gradient
                - Calculate the vehicle's velocity reduction during the time f32_t1
                - Check if velocity reduction before reaching maximal allowed deceleration \n is enough to increase relative velocity to >= 0m/s
                If (Velocity reduction <= relative velocity) then (true)
                  - Set flag indicating that deceleration process has only one phase
                  If (Velocity reduction < relative velocity) then (true)
                    - Recalculate deceleration time (f32_t1) for 1st deceleration phase
                    - Limit result to positive values
                  Endif
                Else
                  - Calculation of deceleration time t2 after first transition phase \n with a constant maximum ACC deceleration and a linear velocity reduction
                  - Limit result to positive values
                Endif
                - Calculate the braking distance for first deceleration phase: \n s1 = ( v_host * t ) + ( 1/2 * a_host * t^2 ) + ( 1/6 * max_decel_grad * t^3 )
                - Limit result to positive values
                If (Deceleration process consists of 2 phases) then (true)
                  - Calculate braking distance of the 2nd deceleration phase due to \n not sufficient velocity reduction during the 1st phase: \n s2 = (( v_host - delta_v1 ) * t ) + ( 1/2 * max_decel * t^2 )
                  - Limit result to positive values
                Endif
                - Add 3 calculated distances: \n f32_sDelay + f32_s1 + f32_s2
                - Limit result to fixed point range
                - Back transformation to fixed point variable
              Endif
            }
          End 
          @enduml
  
  @return          Minimal required distance for reducing relative velocity to 0 in m,
                   multiplied with factor Distance_s. Range: [0...30000u]

  @param[in]       s16_a_host: acceleration of the vehicle in m/s2, multiplied with factor Acceleration_s. Range: [-30000...30000u]
  @param[in]       s16_v_host: velocity of the vehicle in m/s, multiplied with factor Velocity_s. Range: [-30000...30000u]
  @param[in]	     pt_object: Pointer to ACC input interface containing object data [acc_object_t as defined in Rte_Type.h] 
                       pt_object->AUTOSAR.REL_LONG_SPEED: object vehicle relative speed in m/s, multiplied with factor Velocity_s. Range: [-30000...30000u]
  @param[in]	     pt_output: Pointer to acc_output_data_t structure containing ACC output from FCT SEN to FCT VEH
                      pt_output->MAX_ACC_DECELERATION: Maximum acc decelration [full range of acceleration_t type as defined in Rte_Type.h]

  @glob_in         -
  @glob_out        -
  
  @c_switch_part   - 
  @c_switch_full   -

  @pre             -
  @post            -

  @created         04.04.2018
  @changed         04.04.2018

  @traceability    doors://rbgs854a:40000/?version=2&prodID=0&view=00000002&urn=urn:telelogic::1-503e822e5ec3651e-O-106-0008a201

  @author          Hans-Juergen Schnellbach | Hans-Juergen.Schnellbach@continental-corporation.com | +49-8382-9699-573
*************************************************************************************************************************/
distance_t HP_t_DetermineMinDecelDistance
           (  
              acceleration_t s16_a_host
            , velocity_t s16_v_host
            , const acc_object_t *pt_object
            , const acc_output_data_t* pt_output
           )
{
  /* Return var */
  distance_t s16_ret_val = 0;
  
  /* Function calculates the required deceleration distance */
  /* required to increase the relative velocity to 0 m/s */
  /* Calculations are only performed, if host vehicle is approaching object vehicle */
  if ( pt_object->AUTOSAR.REL_LONG_SPEED < ( velocity_t )0 )
  {
    /* Local vars */
    float32 f32_a_host;
    float32 f32_tDelay;
    float32 f32_sDelay;
    float32 f32_t1;
    float32 f32_s1;
    float32 f32_t2 = 0;
    float32 f32_s2 = 0;
    float32 f32_delta_v1;
    float32 f32_delta_a;
    float32 f32_half_p;
    float32 f32_max_decel;
    float32 f32_max_decel_grad;
    float32 f32_v_rel;
    sint16 s16_max_decel_grad;
    boolean b_only_ph1 = FALSE;
  
    f32_a_host    = ( float32 )s16_a_host / ( float32 )Acceleration_s;
    f32_v_rel     = ( float32 )pt_object->AUTOSAR.REL_LONG_SPEED / ( float32 )Velocity_s;
    f32_max_decel = ( float32 )pt_output->MAX_ACC_DECELERATION / ( float32 )Acceleration_s;
    f32_tDelay    = ( float32 )Acc_otsupport_decel_delay / ( float32 )Time_s;

    /* Calculate the distance that is covered during the delay until a deceleration reaction */
    /* f32_sDelay = ( v_rel * tDelay ) + ( 1/2 * f32_a_host * tDelay^2 ) */
    f32_sDelay = fABS( f32_v_rel ) * f32_tDelay ;
    if (f32_a_host >(float32) 0)
    {
      f32_sDelay += ( f32_a_host * SQR( f32_tDelay ) * 0.5f );
    }
    else
    {
      /* Host acceleration is negative. No extra delay distance from it */
    }

    /* Calculate delta between current host acceleration and maximum possible deceleration */
    f32_delta_a = f32_a_host - f32_max_decel;

    /* Calculate the maximal deceleration gradient depending on host vehicle speed */
    /* 1e-3 [m/s^3], 0x8000 ... 0x7FFF */
    s16_max_decel_grad =
      MAT_CALCULATE_PARAM_VALUE1D
      (  Acc_max_neg_grad 
       , Acc_neg_grad_points
       , s16_v_host
      );

    f32_max_decel_grad = ( float32 )(s16_max_decel_grad / Acceleration_s);
  
    /* Calculate required time to reach pt_output->MAX_ACC_DECELERATION considering velocity dependent gradient limit */
    f32_t1 = f32_delta_a / -( f32_max_decel_grad );

    /* Avoid incorrect/impossible calculation results */
    if ( f32_t1 < ( float32 )0 )
    {
      f32_t1 = ( float32 )Time_max / ( float32 )Time_s;
    }

    /* Calculate the vehicle's velocity reduction during the time f32_t1 */
    /* delta_v = ( a_host * t ) + ( 1/2 * max_decel_grad * t^2 ) */
    f32_delta_v1 = 
        ( f32_a_host * f32_t1 )
      + ( f32_max_decel_grad * SQR( f32_t1 ) * 0.5f );

    /* Check if velocity reduction before reaching maximal allowed deceleration */
    /* is enough to increase relative velocity to >= 0m/s */
    if ( f32_delta_v1 <= f32_v_rel )
    {
      /* vehicle deceleration has only 1 phase */
      b_only_ph1 = TRUE;

      /* If the vehicle's velocity reduction during f32_t1 is greater than */
      /* the current absolute relative velocity, the deceleration time */
      /* has to be calculated again depending on the relative velocity */
      if ( f32_delta_v1 < f32_v_rel )
      {
        if ( f32_max_decel_grad < ( float32 )0 )
        {
          /* x^2 + px + q = 0 */
          /* p = 2 * a_host / max_decel_grad  */
          /* q = 2 * rel_speed / max_decel_grad */
          /* x1 = -( p/2 ) + sqrt( ( p/2 )^2 - q ) */
          /* x2 = -( p/2 ) - sqrt( ( p/2 )^2 - q ) */
          f32_half_p = f32_a_host / f32_max_decel_grad;
          /* x1 */
          f32_t1 =
            /* -( p/2 ) */
            ( -( f32_half_p ))
          + /* sqrt( ( p/2 )^2 - q ) */
            ( SQRT
              (  ( SQR( f32_half_p ))
               + ( 2.0f * ( f32_v_rel / f32_max_decel_grad ))
              )
            );

          /* Avoid incorrect/impossible calculation results */
          if ( f32_t1 < ( float32 )0 )
          {
            f32_t1 = ( float32 )Time_max / ( float32 )Time_s;
          }
        }
        /* In case deceleration gradient greater or equal 0, maximal possible time is used as result */
        else 
        {
          f32_t1 = ( float32 )Time_max / ( float32 )Time_s;
        }
      }
    }
    /* Calculation of deceleration time t2 after first transition phase */
    /* with a constant maximum ACC deceleration and a linear velocity reduction */
    else
    {
      /* Calculate time for linear velocity reduction depending on the maximal deceleration */
      if ( f32_max_decel < ( float32 )0 )
      {
        /* t2 = ( v_rel - f32_delta_v1 ) / max_decel */
        f32_t2 = ( f32_v_rel - f32_delta_v1 ) / f32_max_decel;

        /* Avoid incorrect/impossible calculation results */
        if ( f32_t2 < ( float32 )0 )
        {
          f32_t2 = ( float32 )Time_max / ( float32 )Time_s;
        }
      }
      else
      {
        f32_t2 = ( float32 )Time_max / ( float32 )Time_s;
      }
    }

    /* Calculate the braking distance for first deceleration phase */
    /* s1 = ( v_host * t ) + ( 1/2 * a_host * t^2 ) + ( 1/6 * max_decel_grad * t^3 ) */
    f32_s1 =
      /* v_host * t */
      ( -( f32_v_rel ) * f32_t1 )
      /* 1/2 * a_host * t^2 */
    + ( f32_a_host * SQR( f32_t1 ) * 0.5f )
      /* 1/6 * max_decel_grad * t^3 */
    + ( f32_max_decel_grad * SQR( f32_t1 ) * f32_t1 * 0.166667f );

    /* Limit result in case of too large or incorrect t1 value */
    if ( f32_s1 < ( float32 )0 )
    {
      f32_s1 = ( float32 )Distance_max / ( float32 )Distance_s;
    }

    /* Calculate braking distance of the 2nd phase only if the velocity reduction */
    /* during the 1st phase was not sufficient */
    if ( b_only_ph1 == FALSE )
    {
      /* Calculate the braking distance for second deceleration phase */
      /* s2 = (( v_host - delta_v1 ) * t ) + ( 1/2 * max_decel * t^2 ) */
      f32_s2 =
        /*( v_host - delta_v1 ) * t */
        (( -( f32_v_rel ) + f32_delta_v1 ) * f32_t2 )
        /* 1/2 * max_decel * t^2 */
      + ( f32_max_decel * SQR( f32_t2 ) * 0.5f );

      /* Limit result in case of too large or incorrect t2 value */
      if ( f32_s2 < ( float32 )0 )
      {
        f32_s2 = ( float32 )Distance_max / ( float32 )Distance_s;
      }
    }
  
    /* Limit calculation result */
    if (   (( f32_sDelay + f32_s1 + f32_s2 ) < (( float32 )Distance_max / ( float32 )Distance_s ))
        && (( f32_sDelay + f32_s1 + f32_s2 ) > ( float32 )0 )
       )
    {
      /* 1e-2 [m], 0x8000 ... 0x7FFF */
      s16_ret_val =
          ( distance_t )f32_sDelay
        + ( distance_t )f32_s1
        + ( distance_t )f32_s2;

      /* 1e-2 [m], 0x8000 ... 0x7FFF */
      s16_ret_val *= ( distance_t )Distance_s;
    }
    else
    {
      /* 1e-2 [m], 0x8000 ... 0x7FFF */
      s16_ret_val = Distance_max;
    }
  }

  return s16_ret_val;
}
#endif /* HP_CFG_OVERTAKE_SUPPORT_FEATURE */


#endif /* (FCT_CFG_LOHP_COMPONENT) && (FCT_CFG_ACC_HEADWAY_PLANNER) */

/** @} end defgroup */
