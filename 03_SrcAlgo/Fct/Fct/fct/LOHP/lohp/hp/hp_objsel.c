/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC/LOHP/HP (Adaptive Cruise Control - Longitudinal Headway Planner - Headway Planner)

PACKAGENAME:               hp_objsel.c

DESCRIPTION:               This file contains all functions concerning the
                           selection of object of interest for HP

AUTHOR:                    Mistry Niraj (uidq5738)

CREATION DATE:             24.02.2017

VERSION:                   $Revision: 1.55 $

LEGACY VERSION:            Revision: 1.25

**************************************************************************** */

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/** 
@defgroup   hp_objsel Hp_objsel
@ingroup    hp
@brief      File contains functions concerning selection of object of interest for HP
@{ */ 

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "hp.h"

#if ((FCT_CFG_ACT_CODE_VERSION == SWITCH_OFF) && (FCT_CFG_LOHP_COMPONENT) && (FCT_CFG_ACC_HEADWAY_PLANNER))

/*****************************************************************************
  MODULE LOCAL CONSTANTS
*****************************************************************************/
#if (HP_CFG_OVERTAKE_SUPPORT_FEATURE)
#if (CFG_FCT_ACC_APPROACH_SUPPRESSION)
#define HP_OTS_DIST_ENA_CTL_OUT_OPT (( distance_t )4000 ) /* 40m */
#endif
#endif

#define HEADWAY_SMOOTHNESS_MIN 40
#define HEADWAY_SMOOTHNESS_MAX 60
#define Hp_headway_reduction_grad ((distance_t)-10000) /*100 m/s*/

/*****************************************************************************
  MODULE GLOBAL VARIABLES
*****************************************************************************/

/*****************************************************************************
  MODULE FUNCTIONS
*****************************************************************************/
static void HP_v_SetCutinMaxDecel(acc_object_ptr_t object);
static void HP_v_EstimateControlDistance(acc_object_ptr_t object, const acc_driver_intention_t* driver_intention, const acc_input_data_t *input, acc_status_t *status, uint8 u_ObjNr, times_t cycle_time);


/*************************************************************************************************************************
  Functionname:    HP_v_SetCutinMaxDecel                                                                            */ /*!

  @brief           Sets the maximum allowed deceleration depending on the objects cut in probability

  @description     Sets the maximum allowed deceleration depending on the objects cut in probability

          @startuml
          Start
            Partition HP_v_SetCutinMaxDecel {
              - Calculate the maximum allowed deceleration depending on the objects cut in probability
            }
          End 
          @enduml
  
  @return          static void

  @param[in,out]   object : ACC control object
                        MAX_ALLOWED_DECEL : ACC deceleration limit for this control object [Full range of datatype acceleration_t as in Rte_type.h]
                        ACC_CUT_IN_OUT_POTENTIAL : Potential of this object to cut in or out for ACC funtion [0 ... 100] %

  @glob_in         -
  @glob_out        -

  @c_switch_full   FCT_CFG_LOHP_COMPONENT : Configuration switch for enabling LOHP component
  @c_switch_full   FCT_CFG_ACC_HEADWAY_PLANNER : Configuration switch to enable ACC functionality

  @pre             Precondition:  maximum allowed deceleration is already calculated due to lane change probability
  @post            -

  @created         17.05.2016
  @changed         17.05.2016

  @author          Jens Both | jens.both@continental-corporation.com | +49 (8382) 9699-757
*************************************************************************************************************************/
static void HP_v_SetCutinMaxDecel(acc_object_ptr_t object)
{
  object->MAX_ALLOWED_DECEL = (acceleration_t)MAT_MIN((sint32)object->MAX_ALLOWED_DECEL, (sint32)MAT_CALCULATE_PARAM_VALUE1D(Acc_max_decel_cut_in, (uint16)Acc_max_decel_cut_in_points, (sint16)object->ACC_CUT_IN_OUT_POTENTIAL));
}



/*************************************************************************************************************************
  Functionname:    HP_v_EstimateControlDistance                                                                     */ /*!

  @brief           Estimates a control distance and smoothness for a object depending on driver intention and object properties

  @description     Calculate the distance to the control object used by the headway controller based on different inputs and configurations (see switch_part explanation).
                   Control distance defined by driver (headway setting) is modified by specific conditions like cut-in situation, ACC system state or alert modification.

          @startuml
          Start
            Partition HP_v_EstimateControlDistance {
              - Define and initialize local variables
              - Set smoothness between 40 and 60 depending on headway setting

              Partition OvertakePreventionFeature {
                If (Object is NOT Obj_first_host_lane \n AND object is NOT Obj_hidden_host_lane) then (true)
                  If (Relative velocity grater than 0 m/s) then (true)
                    - Object is faster
                    - Set overtake prevention activation velocity threshold to 0 m/s
                  Else
                    - Ego vehicle is faster
                    - Calculate overtake prevention activation velocity threshold \n depending on the current long displacement
                  Endif
                  - Calculate overtake prevention activation condition: \n object speed and Object relative speed must be greater than threshold
                  - Calculate overtake prevention deactivation condition: \n Object speed lesser than threshold with hysteresis offset
                  If (Object has a valid object ID \n AND Overtake prevention input flag is true) then (true)
                    If (Overtake prevention Run flag is false) then (true)
                      - Map Overtake prevention Run flag to previously \n calculated overtake prevention activation condition
                    Else
                      If (Previously calculated overtake prevention\n deactivation condition is false) then (true)
                        - Set Overtake prevention Run flag
                      Else
                        - Reset Overtake prevention Run flag
                      Endif
                    Endif
                    If (Overtake support feature TGR state is active) then (True)
                      - Stop overtake prevention on object
                      - Reset object alert factor and desired obj distance
                    Endif
                  Else
                    - Reset Overtake prevention Run flag
                  Endif
                  If (Overtake prevention Run flag is true) then (true)
                    If (LOHP status for Overtake prevention is still not set \n AND object is closer than desired distance) then (true)
                      - Set flag for smooth ramping up of desired distance
                    Endif
                    - Set LOHP status for active Overtake prevention
                  Else
                    - Reset LOHP status for active Overtake prevention
                  Endif
                Endif
              }


              If (Object status detected \n OR Object status measured \n OR Object status tracked) then (true)
                If (Overtake prevention Run flag is true) then (true)
                  - driver_desired_dist = REQ_DIST_OT_PREVENTION
                  - driver_desired_dist increased based on Cutin probability
                Else (false)
                  - driver_desired_dist = REQUESTED_DISTANCE_ACT
                Endif
                If (Overtake support feature was active for this object\n AND\n Ramp command from OTS cancel is On) then (true)
                  - b_OTS_InitObjDist set to 1
                Endif
                If (Object is NEW \n OR ACC is newly engaged \n OR Overtake prevention is newly started \n OR Driver override phase is ended\n OR object performs cutin \n OR b_OTS_InitObjDist is 1 ) then (true)
                  - b_ResetObjCtrlDist set to 1
                  - Desired object distance \n will be initialized
                Endif
                If (b_ResetObjCtrlDist is TRUE \n OR Distance being ramped \n OR intrusion distance being ramped) then (true)
                  If (Ego vehicle is stationary) then (true)
                    - REQUESTED_DISTANCE_MODIFIED_ACT\n = Object distance
                  Else (false)
                    If (b_ResetObjCtrlDist is TRUE) then (true)
                      - Modify start distance of ramp \n dependent on relative speed\n and driver desired end distance
                      - Set REQUESTED_DISTANCE_MODIFIED_ACT\n to start distance
                      If (relative speed is not critically high) then (true)
                        - Reduce intrusion distance factor\n dependent on relative speed \n and 'short' headway distance
                      Endif
                      If (b_OTS_InitObjDist is 1) then (true)
                        - Set alert mod factor to OTS cancel parameter
                        - Calculate REQUESTED_DISTANCE_MODIFIED_ACT \n based on alert modification factor of object
                      Endif
                    Else (false)
                      - Ramping gradient reduced if\n relative speed is still high
                      - Ramp up REQUESTED_DISTANCE_MODIFIED_ACT\n to driver_desired_dist
                      - Ramp up intrusion distance factor to 1000
                    Endif
                  Endif
                Else (false)
                  - REQUESTED_DISTANCE_MODIFIED_ACT\n = driver_desired_dist
                Endif
                If (REQUESTED_DISTANCE_MODIFIED_ACT > driver_desired_dist) then (true)
                - REQUESTED_DISTANCE_MODIFIED_ACT \nset to driver_desired_dist
                Endif
              Endif
              

              Partition OvertakeSupportFeature{
                If (Object is OOI-0 or 1) then (true)
                  If (Overtake support is active \n AND Object for Overtake support is OOI-0 or 1) then (true)
                    - Set alert modification factor of object \n to reduced value based on feature
                  Else (false)
                    - Set alert modification factor of object \n to reduced value based on cutout probability
                  Endif
                  - Calculated REQUESTED_DISTANCE_MODIFIED_ACT based \n on alert modification factor of object
                  - Calculated Control_Smoothness based \n on alert modification factor of object
                Endif
              }
            }
          End 
          @enduml
  
  @return          static void

  @param[in,out]   object : ACC control object
                        AUTOSAR.REL_LONG_SPEED : Object relative speed [Full range of datatype velocity_t as in Rte_type.h]
                        CONTROL_SMOOTHNESS : Smoothness value for longitudinal control [0 ... 100] %
                        ALERT_MODIFICATION_FACTOR : Factor for modifying the alert distance [0 ... 100] %
                        AUTOSAR.OBJECT_STATUS.MEASURED : Flag for object detection [TRUE,FALSE]
                        AUTOSAR.OBJECT_STATUS.TRACKED : Flag for object detection [TRUE,FALSE]
                        AUTOSAR.OBJECT_STATUS.DETECTED : Flag for object detection [TRUE,FALSE]
                        AUTOSAR.OBJECT_STATUS.NEW : Flag which indicates newly selection of object [TRUE,FALSE]
                        AUTOSAR.LONG_DISPLACEMENT : Object distance [Full range of datatype distance_t as in Rte_type.h]
                        REQUESTED_DISTANCE_MODIFIED_ACT : Actual object control distance modified by different functions [Full range of datatype distance_t as in Rte_type.h]
                        REQUESTED_DISTANCE_MODIFIED_PRED : Predited object control distance modified by different functions [Full range of datatype distance_t as in Rte_type.h]
  @param[in]       driver_intention : Driver intention for ACC
                        LANE_CHANGE_LEFT_PROBABILITY : Probability of a lane change to left direction [0 ... 100] %
                        LANE_CHANGE_RIGHT_PROBABILITY : Probability of a lane change to right direction [0 ... 100] %
                        ACC_ENAGAGED : ACC Engagement State [Struct of type switch_t]
  @param[in]       *input : ACC input interface (vehicle related data)
                        DRIVER_CONTROLS.HEADWAY_SETTING : ACC distance setting [0 ... 100] %
                        LODM_STAT.STANDSTILL : Ego vehicle in stand still [TRUE,FALSE]
  @param[in,out]   *status : ACC status - handles all internal status information of acc component
                        REQUESTED_DISTANCE_ACT : Actual object control distance WITHOUT modification [Full range of datatype distance_t as in Rte_type.h]
                        REQUESTED_DISTANCE_PREDICTED : Predited object control distance WITHOUT modification [Full range of datatype distance_t as in Rte_type.h]
                        ACC_OVERTAKE_DATA.b_Overtake_Support_On : boolean indicating that overtake support is active [TRUE, FALSE]
                        ACC_OVERTAKE_DATA.e_OTState : Overtake support feature transition state [full range of datatape OTState_t_e as in hp_ext.h]
                        ACC_OVERTAKE_DATA.s_LCModFactor : Overtake maneuver alert modification factor [0 ... 1000]
  @param[in]       u_ObjNr : ACC Object number as part of OOI List [0,6]
  @param[in]       cycle_time : Task cycle time [Full range of datatype times_t as in Rte_type.h]

  @glob_in         -
  @glob_out        -

  @c_switch_part   CFG_FCT_ACC_MODIFY_REQ_DIST_TO_CURR_DIST : Modify requested distanc to current distance and ramp it up to requested distance (e.g. in standstill)
  @c_switch_part   CFG_FCT_ACC_USE_DRVINT_FOR_HOSTLANE_OBJ : Use driver intention for host lane objects requested distance modification
  @c_switch_part   CFG_FCT_ACC_USE_CUTOUT_FOR_HOSTLANE_OBJ : Use cut out potential for host lane objects requested distance modification
  @c_switch_part   HP_CFG_OVERTAKE_SUPPORT_FEATURE : Configuration switch for enabling overtake support feature

  @c_switch_full   FCT_CFG_LOHP_COMPONENT : Configuration switch for enabling LOHP component
  @c_switch_full   FCT_CFG_ACC_HEADWAY_PLANNER : Configuration switch to enable ACC functionality

  @pre             -
  @post            -

  @created         17.05.2016
  @changed         17.05.2016

  @author          Jens Both | jens.both@continental-corporation.com | +49 (8382) 9699-757
*************************************************************************************************************************/
static void HP_v_EstimateControlDistance(acc_object_ptr_t object, const acc_driver_intention_t* driver_intention, 
  const acc_input_data_t *input, acc_status_t *status, uint8 u_ObjNr, times_t cycle_time)
{

  acc_object_ptr_t Object_local;
  factor_t local_alert_mod_factor;
  boolean b_ResetObjCtrlDist, help_state;
#if (CFG_FCT_ACC_MODIFY_REQ_DIST_TO_CURR_DIST)
  distance_t req_dist, min_dist, driver_desired_dist;
#endif
#if (HP_CFG_OVERTAKE_SUPPORT_FEATURE)
  boolean b_OTS_InitObjDist;
#endif
#if (HP_CFG_OVERTAKE_PREVENTION_FEATURE)
  boolean b_OTPrevention_Activation = FALSE;
  boolean b_OTPrevention_Deactivation = FALSE;
  boolean b_OTPrevention_Run = FALSE;
  boolean b_OTP_InitObjDist = FALSE;
  velocity_t s_Vrel_Threshold = (velocity_t)0;
#endif
#if ((CFG_FCT_ACC_USE_DRVINT_FOR_HOSTLANE_OBJ) || (CFG_FCT_ACC_USE_CUTOUT_FOR_HOSTLANE_OBJ))
  factor_t local_alert_mod_factor_lane_change = Factor_s;
#endif
  local_alert_mod_factor = Factor_s;
  /* Local variable created from external pointer */
  Object_local = object;


  /*set smoothness between 40 and 60 depending on headway setting*/
  Object_local->CONTROL_SMOOTHNESS = (percentage_t)( HEADWAY_SMOOTHNESS_MIN + ((sint32)((HEADWAY_SMOOTHNESS_MAX-HEADWAY_SMOOTHNESS_MIN) * input->DRIVER_CONTROLS.HEADWAY_SETTING) )/ ((sint32)Percentage_max) );


#if (HP_CFG_OVERTAKE_PREVENTION_FEATURE)

  /* Overtake prevention considered for objects not in our lane */
  if((u_ObjNr != Obj_first_host_lane) && (u_ObjNr != Obj_hidden_host_lane))
  { 
    if(Object_local->AUTOSAR.REL_LONG_SPEED > 0)
    { /* Object is faster */
        s_Vrel_Threshold = (velocity_t)0;
    }
    else
    { /* Ego vehicle is faster */
      s_Vrel_Threshold = MAT_CALCULATE_PARAM_VALUE1D(Acc_otprevent_maxrelspeed,Acc_otprevent_maxrelspeed_points, Object_local->AUTOSAR.LONG_DISPLACEMENT);
    }
    
    /* For activation: object speed and Object relative speed must be greater than threshold */
    /* Incase object on neighbouring lane is relevant because of cut-in or ego lane change probability, overtake prevention feature is not to be active */
    /* In this situation, max_allowed_decel for the object will be reduced. This can be compared to allowed acceleration for CC or with value zero */
    /* To note: Max_allowed_decel for objects is calculated before HP_v_EsimateControlDistance function is called */
    /* Only if OTP is active, max_allowed_decel is again reduced further */
    b_OTPrevention_Activation = (boolean)(
                                          (Object_local->LONG_SPEED > Acc_otprevent_min_speed)&&
                                          (Object_local->AUTOSAR.REL_LONG_SPEED > s_Vrel_Threshold) &&
                                          (Object_local->AUTOSAR.LONG_DISPLACEMENT > Acc_otprevent_maxrelspeed[0]) &&
                                          (Object_local->MAX_ALLOWED_DECEL >= input->CC_ACCEL_LIMIT)  /* Object is not selected through cut-in or ego lane change probability */
                                         );
    /* For deactivation: Object speed lesser than threshold with hysteresis offset */
    b_OTPrevention_Deactivation = (boolean)(
                                            (Object_local->LONG_SPEED < (Acc_otprevent_min_speed-Acc_otprevent_deact_speed_offset))
                                            || /* Object is selected through cut-in or ego lane change probability, OTP to be deactivated */
                                            (Object_local->MAX_ALLOWED_DECEL < 0)
                                           );

    if(
        (Object_local->AUTOSAR.OBJECT_ID != OBJ_INDEX_NO_OBJECT) &&     /* Valid object must exist */
        (input->OT_PREVENTION[u_ObjNr] == TRUE)                         /* Flag mapped from SLATE must be true */
      )
    {
      if(status->OT_PREVENTION[u_ObjNr] == FALSE)
      { /* Run if feature to be activated */
        b_OTPrevention_Run = b_OTPrevention_Activation;
      }
      else
      { /* Stop only if feature to be deactivated */
        b_OTPrevention_Run = ((b_OTPrevention_Deactivation == FALSE)?TRUE:FALSE);
      }

#if (HP_CFG_OVERTAKE_SUPPORT_FEATURE)
      if(
          (status->ACC_OVERTAKE_DATA.e_OTState == OVERTAKE_RUNNING) ||
          (status->ACC_OVERTAKE_DATA.e_OTState == OVERTAKE_EXTENDED)
        )
      { /* Overtake prevention deactivated when overtake support feature is active */
        b_OTPrevention_Run = FALSE; 
        Object_local->ALERT_MODIFICATION_FACTOR = Factor_s;
        Object_local->REQUESTED_DISTANCE_MODIFIED_ACT = status->REQUESTED_DISTANCE_ACT;
        Object_local->REQUESTED_DISTANCE_MODIFIED_ACT = status->REQUESTED_DISTANCE_ACT;
      }
#endif  /* HP_CFG_OVERTAKE_SUPPORT_FEATURE */

    }
    else
    { /* Object lost, do not run */
      b_OTPrevention_Run= FALSE;
    }

    if (b_OTPrevention_Run == TRUE)
    {
      if((status->OT_PREVENTION[u_ObjNr] != TRUE) && (Object_local->AUTOSAR.LONG_DISPLACEMENT < status->REQ_DIST_OT_PREVENTION))
      { /* If obj is newly selected for OT prevention feature and it is closer than desired distance, ramping of distance to be done */
        b_OTP_InitObjDist = TRUE;
      }
      /* Status flag set for given object */
      status->OT_PREVENTION[u_ObjNr] = TRUE;
    }
    else
    { /* Reset */
      status->OT_PREVENTION[u_ObjNr] = FALSE;
    }

  } /* Neighbouring lane objects */

#endif  /* HP_CFG_OVERTAKE_PREVENTION_FEATURE */

#if (HP_CFG_OVERTAKE_SUPPORT_FEATURE)
  /* Ramping up of req dist to object after feature is stopped */
  if(
      (status->ACC_OVERTAKE_DATA.b_RampObjReqDist == TRUE) &&                           /* Check if Ramping command from OTS cancel is On */
      (Object_local->AUTOSAR.OBJECT_ID == status->ACC_OVERTAKE_DATA.OOI_OTS_ObjId) &&   /* Check if reducing distance on required Object only */
      (Object_local->ALERT_MODIFICATION_FACTOR < Factor_s)
    )
  {
    b_OTS_InitObjDist = TRUE; 
  }
  else
  {
    b_OTS_InitObjDist = FALSE;
  }
#endif  /* HP_CFG_OVERTAKE_SUPPORT_FEATURE */


#if (CFG_FCT_ACC_MODIFY_REQ_DIST_TO_CURR_DIST)
  if(
     (Object_local->AUTOSAR.OBJECT_STATUS.DETECTED == TRUE)
     ||
     (Object_local->AUTOSAR.OBJECT_STATUS.MEASURED == TRUE)
     ||
     (Object_local->AUTOSAR.OBJECT_STATUS.TRACKED == TRUE)
    )
  {
#if (HP_CFG_OVERTAKE_PREVENTION_FEATURE)
    if(b_OTPrevention_Run == TRUE)
    {
      driver_desired_dist = status->REQ_DIST_OT_PREVENTION;
      /* Based on cutin probability, if OTP is already active, desired distance to target increased in order to make cutin smoother */
      /* Ego Lane change directly triggers OTP to be deactivated by asking for max_allowed_decel<0 */
      if(Object_local->ACC_CUT_IN_OUT_POTENTIAL > Acc_otp_cutin_dist_factor[0])
      {
        distance_t temp = status->REQUESTED_DISTANCE_ACT - driver_desired_dist;
        sint16 fac = MAT_CALCULATE_PARAM_VALUE1D(Acc_otp_cutin_dist_factor, Acc_otp_cutin_dist_factor_points, Object_local->ACC_CUT_IN_OUT_POTENTIAL);
        driver_desired_dist += (distance_t)MAT_MUL(temp, fac, Distance_s, Factor_s, Distance_s);
      }
      Object_local->CONTROL_SMOOTHNESS = (percentage_t)HEADWAY_SMOOTHNESS_MAX; /* To ensure smooth control to object in other lane */
    }
    else
    {
      driver_desired_dist = status->REQUESTED_DISTANCE_ACT;
    }
#else
    driver_desired_dist = status->REQUESTED_DISTANCE_ACT;
#endif  /* HP_CFG_OVERTAKE_PREVENTION_FEATURE */
   

    /*if current distance is lesser than requested distance -> ramp up */
    /* If desired dist to object reduced in previous cycle -> ramp up */
    /* ALERT_MODIFICATION_FACTOR is initialized for new objects */

    /* Check for situations that require a new requested distance in order to permit */
    /* a comfortable driving feeling while increasing the distance to the object used for control */
    help_state = (boolean)(SWITCH_RISING_EDGE(&(driver_intention->ACC_ENGAGED), TRUE) == SWITCH_STATE_ON);
    if(
        ( Object_local->AUTOSAR.OBJECT_STATUS.NEW == TRUE )
        || ( help_state == TRUE )
          /* In case an override phase is over and the host vehicle is closer */
          /* to the object vehicle than the headway setting */
        || (( driver_intention->DECEL_LIM_OVERRIDE.ACC_LIMITER_ACTIVE == TRUE ) &&
        ( driver_intention->DECEL_LIM_OVERRIDE.ACC_LIMITER_ACTIVE_LAST_CYCLE == FALSE ))
          /* Object not in ego lane has a cut in potential */
        || ( (u_ObjNr > Obj_hidden_host_lane) &&
             (Object_local->ACC_CUT_IN_OUT_POTENTIAL > 0))
#if (HP_CFG_OVERTAKE_SUPPORT_FEATURE)
          /* Overtake support feature stopped for an object */
        || (b_OTS_InitObjDist == TRUE)
#endif   
#if (HP_CFG_OVERTAKE_PREVENTION_FEATURE)
          /* Overtake prevention activated for new object */
        || ( b_OTP_InitObjDist == TRUE )
#endif         
      )
    {
      b_ResetObjCtrlDist = TRUE;
    }
    else
    {
      b_ResetObjCtrlDist = FALSE;
    }

    min_dist = MAT_CALCULATE_PARAM_VALUE1D(Acc_headway_min_dist, Acc_headway_min_dist_points, input->LONG_VELOCITY);

    if(
        (b_ResetObjCtrlDist == TRUE)  /* Desired distance to object to be initialized */
        ||
        (Object_local->ALERT_MODIFICATION_FACTOR < Factor_s) /* Ramping up of obj alert factor from previous cycles */
        ||
        (Object_local->REQUESTED_DISTANCE_MODIFIED_ACT < driver_desired_dist) /* Ramping up of req dist to object from previous cycles */
      )
    {
      /*if host is in stand still, alway set requested distance to current distance*/
      if(input->LODM_STAT.STANDSTILL == TRUE)
      {
        Object_local->REQUESTED_DISTANCE_MODIFIED_ACT = Object_local->AUTOSAR.LONG_DISPLACEMENT;
        Object_local->REQUESTED_DISTANCE_MODIFIED_PRED = Object_local->AUTOSAR.LONG_DISPLACEMENT;
      }
      else
      { /*host is not in stand still*/

        if ( b_ResetObjCtrlDist == TRUE)
        { /* Initialization of desired distance to target */

          distance_t new_distance, distance_error;
          factor_t rel_dist_min;
          factor_t headway_add_factor;
          velocity_t max_vrel_thres;
          
          /* Using distance for HS short for calculation of initial desired distance to object */
          /* This reduces deceleration for larger headway settings */
          distance_error = (distance_t)MAT_MAX(((sint32)min_dist - Object_local->AUTOSAR.LONG_DISPLACEMENT), 0);
          /* Increase start distance of distance ramp dependent on relative speed */
          headway_add_factor = MAT_CALCULATE_PARAM_VALUE1D(Acc_headway_add_factor, (uint16)Acc_headway_add_factor_points, Object_local->AUTOSAR.REL_LONG_SPEED);
          new_distance = Object_local->AUTOSAR.LONG_DISPLACEMENT + 
                          (distance_t)MAT_MUL((sint32)distance_error, (sint32)headway_add_factor, Distance_s, Factor_s, Distance_s);
         
#if (HP_CFG_OVERTAKE_PREVENTION_FEATURE)
          if (b_OTP_InitObjDist == TRUE)
          {
            new_distance = Object_local->AUTOSAR.LONG_DISPLACEMENT;
          }
#endif

          max_vrel_thres = MAT_CALCULATE_PARAM_VALUE1D(Hp_intrusion_red_vrel_thres,(uint16)Hp_intrusion_red_vrel_thres_points, Object_local->AUTOSAR.LONG_DISPLACEMENT);
          if(object->AUTOSAR.REL_LONG_SPEED > max_vrel_thres)
          {
            /* Modification of alert factor */
            rel_dist_min = (factor_t)MAT_DIV((sint32)Object_local->AUTOSAR.LONG_DISPLACEMENT, (sint32)min_dist, Distance_s, Distance_s, Factor_s);
            local_alert_mod_factor = MAT_CALCULATE_PARAM_VALUE2D(Hp_alert_fac_red_reldist_vrel, 
                                                                  (uint16)Hp_alert_fac_red_points_reldist, (uint16)Hp_alert_fac_red_points_vrel, 
                                                                  Hp_alert_fac_red_step_reldist, Hp_alert_fac_red_step_vrel, 
                                                                  Hp_alert_fac_red_start_reldist, Hp_alert_fac_red_start_vrel, 
                                                                  (sint32)rel_dist_min, (sint32)Object_local->AUTOSAR.REL_LONG_SPEED);
          }

#if (HP_CFG_OVERTAKE_SUPPORT_FEATURE)
          if(
              (b_OTS_InitObjDist == TRUE) &&
              (status->ACC_CONTROL_OBJECT.CONTROL_ACCEL < Acc_otsupport_ooi_accel_threshold)
            )
          {
            local_alert_mod_factor = Acc_otsupport_dist_fact_cancel;
            new_distance = (distance_t)MAT_MUL((sint32)driver_desired_dist, (sint32)local_alert_mod_factor, Distance_s, Factor_s, Distance_s);
          }
#endif  /* HP_CFG_OVERTAKE_SUPPORT_FEATURE */

          Object_local->REQUESTED_DISTANCE_MODIFIED_ACT = new_distance;
          Object_local->REQUESTED_DISTANCE_MODIFIED_PRED = new_distance;

        } /* End initialization of desired distance to target */
        else
        {
          /* Desired distance to target ramped from initial value */
          distance_t headway_increase_grad;
          factor_t alert_factor_inc_grad;
          headway_increase_grad = (distance_t)MAT_MUL((sint32)driver_desired_dist, (sint32)Hp_headway_increase_grad_factor, Distance_s, Factor_s, Distance_s);
          alert_factor_inc_grad = Hp_headway_increase_grad_factor;
          
          if((Object_local->AUTOSAR.REL_LONG_SPEED < Hp_reduced_distramp_vrel_thres) && (Object_local->LONG_ACCEL > Hp_reduced_distramp_aobj_thres))
          { /* For large -ve vrel, ramp gradient reduced for lesser deceleration peak, if aobj is safe */
            headway_increase_grad /= Hp_reduced_distramp_grad_factor;
            alert_factor_inc_grad /= Hp_reduced_alertramp_grad_factor;
          }
		  /*protection to prevent saturation*/
		  headway_increase_grad = (distance_t)MAT_MAX((sint32)headway_increase_grad,(sint32)Hp_dist_alert_minimum_grad);
		  alert_factor_inc_grad = (factor_t)MAT_MAX((sint32)alert_factor_inc_grad,(sint32)Hp_dist_alert_minimum_grad);		  

          /*ramp requested distance for this object to the requested global distance with a limited positive gradient*/
          req_dist = (distance_t)MAT_LIM_GRAD((sint32)driver_desired_dist, (sint32)Object_local->REQUESTED_DISTANCE_MODIFIED_ACT, 
                                              Hp_headway_reduction_grad, (sint32)headway_increase_grad, cycle_time);
          local_alert_mod_factor = (distance_t)MAT_LIM_GRAD(Factor_s, (sint32)Object_local->ALERT_MODIFICATION_FACTOR, 
                                              Hp_headway_reduction_grad, (sint32)alert_factor_inc_grad, cycle_time);

          Object_local->REQUESTED_DISTANCE_MODIFIED_ACT = req_dist;
          /*modify the predicted distance - at the moment use the same distance*/
          Object_local->REQUESTED_DISTANCE_MODIFIED_PRED = req_dist;
        }
      }      
    }
    else
    { /* No reduction of desired distance to object */
      Object_local->REQUESTED_DISTANCE_MODIFIED_ACT = driver_desired_dist;
      Object_local->REQUESTED_DISTANCE_MODIFIED_PRED = driver_desired_dist;  
    }

#if (HP_CFG_OVERTAKE_PREVENTION_FEATURE)
    if (b_OTPrevention_Run == TRUE)
    {
      /* Obj alert mod factor varied based on factor of calculated desired obj dist to min driver desired dist */
      local_alert_mod_factor = (factor_t)MAT_LIM(
                                MAT_DIV(Object_local->REQUESTED_DISTANCE_MODIFIED_ACT, min_dist, Distance_s, Distance_s, Factor_s), 
                                0, Factor_s); 
    }
#endif  /* HP_CFG_OVERTAKE_PREVENTION_FEATURE */

    /* Code check in case desired obj distance surpasses driver desired dist */
    if(Object_local->REQUESTED_DISTANCE_MODIFIED_ACT > driver_desired_dist)
    {
      Object_local->REQUESTED_DISTANCE_MODIFIED_ACT = driver_desired_dist;
      Object_local->REQUESTED_DISTANCE_MODIFIED_PRED = driver_desired_dist;
    }

  }

#else
  /*set original control distance and smoothness of hws*/
  Object_local->REQUESTED_DISTANCE_MODIFIED_ACT = status->REQUESTED_DISTANCE_ACT;
  Object_local->REQUESTED_DISTANCE_MODIFIED_PRED = status->REQUESTED_DISTANCE_PREDICTED;
#endif  /* CFG_FCT_ACC_MODIFY_REQ_DIST_TO_CURR_DIST */

  /* Update alert_mod_factor based on reduced REQUESTED_DISTANCE_MODIFIED_ACT and local_alert_mod_factor */
  Object_local->ALERT_MODIFICATION_FACTOR = local_alert_mod_factor;



#if ((CFG_FCT_ACC_USE_DRVINT_FOR_HOSTLANE_OBJ) || (CFG_FCT_ACC_USE_CUTOUT_FOR_HOSTLANE_OBJ))

  if((u_ObjNr == Obj_first_host_lane) || (u_ObjNr == Obj_hidden_host_lane))
  {
#if (HP_CFG_OVERTAKE_SUPPORT_FEATURE)
    /* Change of modification factor & obj distance to ensure acceleration for overtake support */
    if(
        (status->ACC_OVERTAKE_DATA.b_Overtake_Support_On == TRUE) &&
        (Object_local->AUTOSAR.OBJECT_ID == status->ACC_OVERTAKE_DATA.OOI_OTS_ObjId)  /* Check if reducing distance on required Object only */
      )
    {
      if (status->ACC_OVERTAKE_DATA.e_OTState == OVERTAKE_EXTENDED)
      {
        local_alert_mod_factor_lane_change = Acc_otsupport_distance_factor_low;
      }
      if (status->ACC_OVERTAKE_DATA.e_OTState == OVERTAKE_RUNNING) /* For state running, a higher distance kept to OOI-0 */
      {
        local_alert_mod_factor_lane_change = Acc_otsupport_distance_factor_high;
      }

      status->ACC_OVERTAKE_DATA.s_LCModFactor = local_alert_mod_factor_lane_change;
    }

#endif  /* HP_CFG_OVERTAKE_SUPPORT_FEATURE */

#if (CFG_FCT_ACC_USE_CUTOUT_FOR_HOSTLANE_OBJ)
#if ( HP_CFG_OVERTAKE_SUPPORT_FEATURE )
    
    /*! If Lane change probability exists, do not use Cut Out potential */
    /* 1e-3 [-], 0x8000 ... 0x7FFF */
    if ( status->ACC_OVERTAKE_DATA.s_LCModFactor >= Factor_s )
    {
      /*! no lane change detected, use cut out probability if exists */
      /* 1e-3 [-], 0x8000 ... 0x7FFF */
      local_alert_mod_factor_lane_change = ( factor_t )
        /* 1e-3 [-], 0x8000 ... 0x7FFF */
        MAT_CALCULATE_PARAM_VALUE1D
        (  Acc_cut_out_distance_factor
         , Acc_cut_out_distance_factor_points
           /* 1 [%], 0 ... 0xFF */
         , ( sint16 )Object_local->ACC_CUT_IN_OUT_POTENTIAL
        );
    }
#else
    /* 1e-3 [-], 0x8000 ... 0x7FFF */
    local_alert_mod_factor_lane_change = ( factor_t )
      /* 1e-3 [-], 0x8000 ... 0x7FFF */
      MAT_CALCULATE_PARAM_VALUE1D
      (  Acc_cut_out_distance_factor
       , Acc_cut_out_distance_factor_points
         /* 1 [%], 0 ... 0xFF */
       , ( sint16 )Object_local->ACC_CUT_IN_OUT_POTENTIAL
      );
#endif  /* HP_CFG_OVERTAKE_SUPPORT_FEATURE */
#endif  /* CFG_FCT_ACC_USE_CUTOUT_FOR_HOSTLANE_OBJ */

    if(local_alert_mod_factor_lane_change < Factor_s)
    {
      Object_local->REQUESTED_DISTANCE_MODIFIED_ACT =  (distance_t)MAT_MIN((sint32)Object_local->REQUESTED_DISTANCE_MODIFIED_ACT, MAT_MUL((sint32)status->REQUESTED_DISTANCE_ACT,  (sint32)local_alert_mod_factor_lane_change, Distance_s, Factor_s, Distance_s));
      Object_local->REQUESTED_DISTANCE_MODIFIED_PRED = (distance_t)MAT_MIN((sint32)Object_local->REQUESTED_DISTANCE_MODIFIED_PRED,MAT_MUL((sint32)status->REQUESTED_DISTANCE_PREDICTED,  (sint32)local_alert_mod_factor_lane_change, Distance_s, Factor_s, Distance_s));
      Object_local->ALERT_MODIFICATION_FACTOR = local_alert_mod_factor_lane_change;
    }

    if(Object_local->ALERT_MODIFICATION_FACTOR < Factor_s) 
    { /* Reduced smoothness leads to larger acceleration */
      Object_local->CONTROL_SMOOTHNESS = (percentage_t)MAT_MUL((sint32)Object_local->CONTROL_SMOOTHNESS, 
                                                                (sint32)Object_local->ALERT_MODIFICATION_FACTOR, 
                                                                Percentage_s, Factor_s, Percentage_s);
    }
  } /* Distance reduction for overtake support/cutout */

  /*avoid division by zero*/
  Object_local->REQUESTED_DISTANCE_MODIFIED_ACT = (distance_t)MAT_MAX((sint32)Object_local->REQUESTED_DISTANCE_MODIFIED_ACT, 1);
  Object_local->REQUESTED_DISTANCE_MODIFIED_PRED = (distance_t)MAT_MAX((sint32)Object_local->REQUESTED_DISTANCE_MODIFIED_PRED, 1);

#endif /*(CFG_FCT_ACC_USE_DRVINT_FOR_HOSTLANE_OBJ) || (CFG_FCT_ACC_USE_CUTOUT_FOR_HOSTLANE_OBJ)*/


  /* Saving local variable to global pointer */
  object = Object_local;// PRQA S 3199
  /* date: 2018-03-21, reviewer: Ravi kiran Gurrala, reason: Redundant, but may be used in future*/
}/* PRQA S 7004 */
/* date: 2018-06-13, reviewer: Ravi Kiran Gurrala, reason : Cyclomatic complexity. Not Safety critical*/


/*************************************************************************************************************************
  Functionname:    HP_v_SelectObjectsOfInterest                                                                     */ /*!

  @brief           Selects the objects that can be interesting in this situation

  @description     Selects the control object out of the OOI list depending on project setting (see switch_part explanation).
                   Mainly, the allowed deceleration for each object is calculated based on it's attributes, like cut-in/out potential.
                   The object with the highest necessary deceleration request is selected as the control object (done in HP_v_SelectRelevantObject()).

				   @startuml
					Start
					  Partition HP_v_SelectObjectsOfInterest {
						If(ACC Object lost confirmed) Then (Yes)
						-Restart the timer
						Endif
						If(Object lost countdown is not reached zero \nAND\n Valid OOI-0 exists)then (Yes)
						-Reset Object lost timer to 0
						Endif 
						-Decrement the objecet lost countdown
						-Check the stationary possiblity of each objects
						If(if Object is stationary and ego velocity greater than threshould )then(yes)
							If(OBJECT_NR_TO_CONTROL_TO is not equal to current Object ID )then(yes)
							-Limit object deceleration to Acc_min_accel_object_stationary(0)
							Endif
						Endif 	
						If(Check for all OOi objects if it is new) then (yes)
							-Initialize overtake prevention, support flags		
						Endif
						-Calculate the estimated control distance of OOi_0 
						-Calculate the allowed deceleration for OOi_1 based on OOi_0 cutout probability
						-Calculate the estimated control distance of OOi_1
						-Calculate max allowed deceleration for left and\n right lane object based on ego lane change probability 
						-Calculate max allowed deceleration form custom requiments. 
						-Calculate max allowed deceleration for left and\n right lane object based on cutin probability 
						- Calculate the estimated control distance of OOi_2,3,4,5 
						If(Check overtake prevention status of ooi objects)then(yes)
						-Calculate max allowed deceleration for overtake prevention feature 
						Endif 
						-Remove interest flag of object if max allowed\n decel is greater than or equal to cc max accel(Object is not relevant)
						-Save a copy of the ACC deceleration limitation after override 
					  }
					End 
					@enduml

  @return          void

  @param[in,out]   driver_intention : Driver intention for ACC
                        OBJECT_NR_TO_CONTROL_TO : Object nr that is used to control regardless if it is stationary or not! [Full range of datatype ObjNumber_t as in Rte_type.h]
                        DECEL_LIM_OVERRIDE.ACC_LIMITER_ACTIVE : Flag indicate the state of ACC limiter function [TRUE,FALSE]
                        DECEL_LIM_OVERRIDE_ACCEL : Max allowed deceleration after override [Full range of datatype acceleration_t as in Rte_type.h]
  @param[in]       acc_input : ACC input interface (vehicle related data)
                        INPUT_STATUS.OBJECT_LOST : 
                        LONG_VELOCITY : Longitudinal velocity of the host vehicle [Full range of datatype velocity_t as in Rte_type.h]
                        CC_DECEL_LIMIT : Maximum allowed deceleration [Full range of datatype acceleration_t as in Rte_type.h]
                        CC_ACCEL_LIMIT : Maximum allowed acceleration [Full range of datatype acceleration_t as in Rte_type.h]

@param[in,out]     object_list: ACC object list of [0u ... Acc_max_number_ooi] with Acc_max_number_ooi in acc_ext.h
                        MAX_ALLOWED_ACCEL : ACC acceleration limit for this control object [Full range of datatype acceleration_t as in Rte_type.h]
                        MAX_ALLOWED_DECEL : ACC deceleration limit for this control object [Full range of datatype acceleration_t as in Rte_type.h]
                        AUTOSAR.OBJECT_STATUS.STOPPED : Object stopped (seen moving) [TRUE,FALSE]
                        AUTOSAR.OBJECT_STATUS.STANDING : Object standing (never seen moving) [TRUE,FALSE]
                        AUTOSAR.OBJECT_STATUS.NEW : Flag which indicates newly selection of object [TRUE,FALSE]
                        AUTOSAR.OBJECT_STATUS.DETECTED : Flag for object detection [TRUE,FALSE]
                        AUTOSAR.OBJECT_STATUS.MEASURED : Flag for object detection [TRUE,FALSE]
                        AUTOSAR.OBJECT_STATUS.TRACKED : Flag for object detection [TRUE,FALSE]
                        LONG_ACCEL_MODIFIED : Object acceleration modified [Full range of datatype acceleration_t as in Rte_type.h]
                        USAGE_STATUS.INTEREST : Indicates the OOI state [TRUE,FALSE]

  @param[in]       status : ACC status - handles all internal status information of acc component (only used for inner function parameter)
  @param[in]       cycle_time : Task cycle time [Full range of datatype times_t as in Rte_type.h]

  @glob_in         -
  @glob_out        -

  @c_switch_part   CFG_FCT_ACC_REACT_ON_STANDING_OBJECTS : Activate control reaction on stationary objects (never seen moving)
  @c_switch_part   CFG_FCT_ACC_USE_ONLY_FIRST_OBJECT : Restrict control reaction only on OOI 0 (first object in ego lane)
  @c_switch_part   CFG_FCT_ACC_USE_ONLY_OBJECTS_IN_LANE : Restrict control reaction only on OOI 0 and 1 (all relevant objects assigned to ego lane)

  @c_switch_full   FCT_CFG_LOHP_COMPONENT : Configuration switch for enabling LOHP component
  @c_switch_full   CFG_FCT_ACC : Configuration switch to enable ACC functionality

  @pre             Precondition:  HP_ESTIMATE_DRIVER_INTENTION
  @post            -

  @created         17.05.2016
  @changed         17.05.2016

  @traceability    doors://rbgs854a:40000/?version=2&prodID=0&view=00000002&urn=urn:telelogic::1-503e822e5ec3651e-O-97-0008a201

  @author          Jens Both | jens.both@continental-corporation.com | +49 (8382) 9699-757
*************************************************************************************************************************/
void HP_v_SelectObjectsOfInterest(acc_driver_intention_t* driver_intention, const acc_input_data_t *acc_input, 
  acc_object_t object_list[Acc_max_number_ooi], acc_status_t *status, times_t cycle_time)
{ 
  /*---------------- estimate max accel/decel to each object --------*/
  uint8           onr;

  /* Count down timer value for acceleration limitation */
  /* 1e-3 [s], 0 ... 0xFFFF */
  SWITCH_SET_COUNTER( cycle_time, &( status->TIMER_LIMIT_ACCEL_OBJ_LOST ));

  /* After an object disappeared or was lost in a curve, a countdown timer is restarted */
  if ((   acc_input->INPUT_STATUS.OBJECT_LOST == TRUE)
         /* 1e-3 [s], 0 ... 0xFFFF */
     )
  {
    /* Restart timer */
    /* 1e-3 [s], 0 ... 0xFFFF */
    status->TIMER_LIMIT_ACCEL_OBJ_LOST = Acc_timer_limit_accel_obj_lost;
  }

  /* Limitation of deceleration for stationary objects no longer done here since this is
    decided in components COF, FPS ,SLATE */


  /* Initialisation of object status information incase of OOI object change */
  for(onr = 0u; onr<Acc_max_number_ooi; onr++)
  {
    if (object_list[onr].AUTOSAR.OBJECT_STATUS.NEW == TRUE)
    { /* Object Id has changed. Status info must be reset */
#if (HP_CFG_OVERTAKE_PREVENTION_FEATURE)
      status->OT_PREVENTION[onr] = FALSE;
#endif
#if (HP_CFG_OVERTAKE_SUPPORT_FEATURE)
      status->APPROACH_SUPPRESSION[onr] = FALSE;
#endif
    }
  }


  /*---------------- select objects -------------------------------*/
  /*the first object in the same lane is always interesting!*/
  object_list[Obj_first_host_lane].USAGE_STATUS.INTEREST = TRUE; 
  object_list[Obj_first_host_lane].MAX_ALLOWED_DECEL = Acc_max_allowed_decel;
  HP_v_EstimateControlDistance(&object_list[Obj_first_host_lane], driver_intention, acc_input, status, (uint8)Obj_first_host_lane, cycle_time);
  /* As long as the timer has not reached 0ms the acceleration output shall be limited */
  /* 1e-3 [s], 0 ... 0xFFFF */
  if ( status->TIMER_LIMIT_ACCEL_OBJ_LOST > (times_t)0 )
  {
    if(object_list[Obj_first_host_lane].AUTOSAR.OBJECT_STATUS.TRACKED == TRUE)
    { /* OOI-0 object is present when lost timer running. Timer to be ended */
      status->TIMER_LIMIT_ACCEL_OBJ_LOST = 0u;
    } 
  }

#if !CFG_FCT_ACC_USE_ONLY_FIRST_OBJECT  
  /*the object in the same lane in front of the first target is also interesting!*/
  object_list[Obj_hidden_host_lane].USAGE_STATUS.INTEREST = TRUE;
  /*allow only limited deceleration - shall be quality dependent in future*/
  /*max allowed deceleration for hidden next object dependent on cut-out probability of the next object in lane*/
  object_list[Obj_hidden_host_lane].MAX_ALLOWED_DECEL = MAT_CALCULATE_PARAM_VALUE1D(Acc_max_decel_hidden_object, (uint16)Acc_max_decel_hidden_object_points, (sint16)object_list[Obj_first_host_lane].ACC_CUT_IN_OUT_POTENTIAL);
  HP_v_EstimateControlDistance(&object_list[Obj_hidden_host_lane], driver_intention, acc_input, status, (uint8)Obj_hidden_host_lane, cycle_time);

#if !CFG_FCT_ACC_USE_ONLY_OBJECTS_IN_LANE

  /*if object in actual lane is NOT present anymore (or only a standing object is available)*/
#if !CFG_FCT_ACC_USE_OBJECTS_IN_ALL_LANES
   if(
     (
      (
       (object_list[Obj_first_host_lane].AUTOSAR.OBJECT_STATUS.MEASURED == FALSE)
       && 
       (object_list[Obj_first_host_lane].AUTOSAR.OBJECT_STATUS.TRACKED == FALSE)
      )
      || 
      (
       (object_list[Obj_first_host_lane].AUTOSAR.OBJECT_STATUS.STOPPED == FALSE)
       &&
       (object_list[Obj_first_host_lane].AUTOSAR.OBJECT_STATUS.STANDING == TRUE)
      )
     )      
    )
#endif
  {
	object_list[Obj_first_left_lane].USAGE_STATUS.INTEREST = TRUE;
	object_list[Obj_second_left_lane].USAGE_STATUS.INTEREST = TRUE;
	object_list[Obj_first_right_lane].USAGE_STATUS.INTEREST = TRUE;
	object_list[Obj_second_right_lane].USAGE_STATUS.INTEREST = TRUE;

	/*MAX_ALLOWED_DECEL calculation for OOI2,3,4 & 5 based on Lane change probability*/    
    object_list[Obj_first_left_lane].MAX_ALLOWED_DECEL = MAT_CALCULATE_PARAM_VALUE1D(Acc_max_decel_outer_lanes, Acc_max_decel_outer_lanes_points, 
                                                          (sint16)driver_intention->LANE_CHANGE_LEFT_PROBABILITY);
    object_list[Obj_second_left_lane].MAX_ALLOWED_DECEL = MAT_CALCULATE_PARAM_VALUE1D(Acc_max_decel_outer_lanes, Acc_max_decel_outer_lanes_points, 
                                                          (sint16)driver_intention->LANE_CHANGE_LEFT_PROBABILITY);
	object_list[Obj_first_right_lane].MAX_ALLOWED_DECEL = MAT_CALCULATE_PARAM_VALUE1D(Acc_max_decel_outer_lanes, Acc_max_decel_outer_lanes_points, 
                                                          (sint16)driver_intention->LANE_CHANGE_RIGHT_PROBABILITY);
	object_list[Obj_second_right_lane].MAX_ALLOWED_DECEL = MAT_CALCULATE_PARAM_VALUE1D(Acc_max_decel_outer_lanes, Acc_max_decel_outer_lanes_points, 
                                                          (sint16)driver_intention->LANE_CHANGE_RIGHT_PROBABILITY);

	/*MAX_ALLOWED_DECEL calculation for OOI's form custome requiments*/ 
	HP_v_SetMaxDecelCustom(acc_input, driver_intention, object_list, status, cycle_time);

	/*MAX_ALLOWED_DECEL calculation for OOI2,3,4 & 5 based on CutIn/Out Probability*/    
    HP_v_SetCutinMaxDecel(&(object_list[Obj_first_left_lane]));
	HP_v_SetCutinMaxDecel(&(object_list[Obj_second_left_lane]));
	HP_v_SetCutinMaxDecel(&(object_list[Obj_first_right_lane]));
	HP_v_SetCutinMaxDecel(&(object_list[Obj_second_right_lane]));
    
	/*Estimation of control distance for OOI2,3,4 & 5*/
    HP_v_EstimateControlDistance(&object_list[Obj_first_left_lane], driver_intention, acc_input, status, (uint8)Obj_first_left_lane, cycle_time);    
    HP_v_EstimateControlDistance(&object_list[Obj_second_left_lane], driver_intention, acc_input, status, (uint8)Obj_second_left_lane, cycle_time);    
    HP_v_EstimateControlDistance(&object_list[Obj_first_right_lane], driver_intention, acc_input, status, (uint8)Obj_first_right_lane, cycle_time);    
    HP_v_EstimateControlDistance(&object_list[Obj_second_right_lane], driver_intention, acc_input, status, (uint8)Obj_second_right_lane, cycle_time);

#if (HP_CFG_OVERTAKE_PREVENTION_FEATURE)
    /* Overtake prevention considered for objects not in our lane */
    for(onr = Obj_first_left_lane; onr < Acc_max_number_ooi; onr++)
    {
      if (status->OT_PREVENTION[onr] == TRUE)
      {
        /* Min allowed reaction for object is set */
        object_list[onr].MAX_ALLOWED_DECEL = (acceleration_t)MAT_MIN((sint32)object_list[onr].MAX_ALLOWED_DECEL, (sint32)Acc_otprevent_min_allowed_decel);
      }
    }
#endif

  }
#endif /*!CFG_FCT_ACC_USE_ONLY_OBJECTS_IN_LANE*/

#endif /*!CFG_FCT_ACC_USE_ONLY_FIRST_OBJECT*/

   /* remove interest stat if max allowed decel >= cc max decel*/
  for (onr = 0u; onr < Acc_max_number_ooi; onr++)
  {
    if(object_list[onr].MAX_ALLOWED_DECEL >= acc_input->CC_ACCEL_LIMIT) /*!!! should be the max allowed acceleration at the moment*/
    {
      object_list[onr].USAGE_STATUS.INTEREST = FALSE;
    }
  }

  /* Save a copy of the ACC deceleration limitation */
  /* in order to be able to detect a rising edge in next cycle */
  driver_intention->DECEL_LIM_OVERRIDE.ACC_LIMITER_ACTIVE_LAST_CYCLE = driver_intention->DECEL_LIM_OVERRIDE.ACC_LIMITER_ACTIVE;
}

/*************************************************************************************************************************
  Functionname:    HP_v_SelectRelevantObject                                                                        */ /*!

  @brief           Selects the relevant objects out of the list of objects of interest

  @description     Selects the relevant objects out of the list of objects of interest
                   The object with the highest necessary deceleration request (calculated in HP_v_SelectObjectsOfInterest())
                   is selected as the control object.

      @startuml
        Start
          Partition HP_v_SelectRelevantObject {

            If(ooi object list is valid)then (Yes)
              Note left:Checking for all six OOI 
              If(Object of interest, measured flags and tracked flags are set) then (Yes)
                -Calculate the needed deceleration of object
                If(Max allowed acceleration is not equal to\n max allowed deceleration(Object is relevant)) then (Yes)
                  -Calculate control acceleration for object
                  If(Overtake support feature is active and relative speed less than zero)then(Yes)
                    - Calculate minimal braking distance for\n the current maximal possible deceleration
                    -Add safety offset to minimal braking distance 
                    -Calculate the intrusion distance based\n on the headway setting and relative speed
                    -Calculate the possible braking distance
                    If(The possible braking distance is greater than minimum braking distance and approach suppression flag is false)then(Yes)
                      - Set the approach suppression flag to TRUE
                    Endif 
                    If(possible braking distance is greater than the minimum braking distance and suppression flag is true)then(Yes)
                      -Object control accel is limited to Acc_otsupport_min_approach_accel
                    Else(No)
                      - Set the approach suppression flag to FALSE
                    Endif 	 
                  Else(No)
                    - Set the approach suppression flag to FALSE
                  Endif  	
                Else (No)
                  - Control acceleration of object set to the acc max allowed acceleration of Object
                Endif 
                -Object control accel is limited to allowed limits 
                If(Control acceleration is less than min command control acceleration)then(Yes)
                  -Update the relevant object number
                  -Set the min command control acceleration to object control acceleration
                Endif
                If(Control acceleration is less than alert acceleration)then(Yes)
                  -Update the relevant object number
                  -Set the alert acceleration to object control acceleration
                Endif
              Else (No)
                -Control acceleration of object set to the acc max allowed acceleration 	
              Endif
            Endif

            If(Relevant control object exists)then(Yes)	
              -Set the “USE_FOR_CONTROL” flag
              If(Relevant object is OOi_0 and newly relevant)then(Yes)
                - Set the ALLOW_INIT flag to TRUE
              Endif
              -Set control object to relevant object 
              If(Object control distance was modified)then(Yes)
                - Set the ALLOW_INIT flag to TRUE
              Endif 	
              - Limit control accel to HP limits
            Else (No)
              If(Relevant object was present in last cycle)then(Yes)
                - Set the ALLOW_INIT flag to TRUE
              Endif 	
              -Delete control object
            Endif  
            If (Lost object countdown is active) then (Yes)
              -Limit HP and control object acceleration value
            Endif
            -Set the alert object	
            -Select display object from control object and OOI_0   	

            If(Acc Inhibition flag is enabled)then (Yes)
              -Do not show any object 		
            Endif		

          }
        End 
      @enduml

  @return          void


  @param[in,out]   object_list: ACC object list of [0u ... Acc_max_number_ooi] with Acc_max_number_ooi in acc_ext.h
                        USAGE_STATUS.USE_FOR_CONTROL : Indicates, if object is selected as control object [TRUE,FALSE]
                        USAGE_STATUS.USE_FOR_ALERT : Indicates, if object is selected as alert object [TRUE,FALSE]
                        USAGE_STATUS.INTEREST : Indicates the OOI state [TRUE,FALSE]
                        AUTOSAR.OBJECT_ID : object ID number [-1 ... 127]
                        AUTOSAR.OBJECT_STATUS.MEASURED : Flag for object detection [TRUE,FALSE]
                        AUTOSAR.OBJECT_STATUS.TRACKED : Flag for object detection [TRUE,FALSE]
                        LANE_INFORMATION : Lane the object is associated to [-1,0,1]
  @param[in,out]   control_object : Object selected for ACC control
                        AUTOSAR.OBJECT_ID : object ID number [-1 ... 127]
                        REQUESTED_DISTANCE_MODIFIED_ACT : Actual object control distance modified by different functions [Full range of datatype distance_t as in Rte_type.h]
  @param[in,out]   alert_object : Object selected for ACC headway control alert (ACC warning)
  @param[in,out]   display_object : Object selected for the HMI dispay information
                        CONTROL_ACCEL : Needed acceleration/deceleration to maintain requested distance to the object  [Full range of datatype acceleration_t as in Rte_type.h]
                        MAX_ALLOWED_ACCEL : ACC acceleration limit for this control object [Full range of datatype acceleration_t as in Rte_type.h]
                        MAX_ALLOWED_DECEL : ACC deceleration limit for this control object [Full range of datatype acceleration_t as in Rte_type.h]
  @param[in]       input : ACC input interface (vehicle related data)
                        LONG_ACCELERATION : Longitudinal acceleration of the host vehicle [Full range of datatype acceleration_t as in Rte_type.h]
                        LONG_VELOCITY : Longitudinal velocity of the host vehicle [Full range of datatype velocity_t as in Rte_type.h]
                        DRIVER_CONTROLS.HEADWAY_SETTING : ACC distance setting [0 ... 100] %
                        CC_ACCEL_LIMIT : Maximum allowed acceleration [Full range of datatype acceleration_t as in Rte_type.h]
  @param[out]      output : ACC output structure
                        ACC_OUTPUT_STATUS.ALLOW_INIT : Indicates the possibility, to initialize the control acceleration to the current ego vehicle acceleration [TRUE,FALSE]
                        ACC_OUTPUT_STATUS.INHIBITED : Indicates the inhibition of the ACC function - no vehicle controlling or displaying information [TRUE,FALSE]
  @param[in,out]   status : ACC status - handles all internal status information of acc component
                        REQUESTED_DISTANCE_ACT : Actual object control distance WITHOUT modification [Full range of datatype distance_t as in Rte_type.h]

  @glob_in         -
  @glob_out        -

  @c_switch_part   CFG_FCT_USE_ONLY_FIRST_OBJECT_FOR_ALERT : Acc alert only to first object in current lane
  @c_switch_part   CFG_FCT_ACC_DISPLAY_ONLY_FIRST_OBJECT : Display only the next object (OOI 0) if available, not the objects on adjacent lanes if selected as control object!

  @c_switch_full   FCT_CFG_LOHP_COMPONENT : Configuration switch for enabling LOHP component
  @c_switch_full   FCT_CFG_ACC_HEADWAY_PLANNER : Configuration switch to enable ACC functionality

  @pre             Precondition:  ACC_OOI_LIST
  @post            -

  @created         17.05.2016
  @changed         17.05.2016

  @traceability    doors://rbgs854a:40000/?version=2&prodID=0&view=00000002&urn=urn:telelogic::1-503e822e5ec3651e-O-98-0008a201

  @author          Jens Both | jens.both@continental-corporation.com | +49 (8382) 9699-757
*************************************************************************************************************************/
void HP_v_SelectRelevantObject(acc_object_t object_list[Acc_max_number_ooi], acc_object_t* control_object, acc_object_t* alert_object, 
  acc_object_t* display_object, const acc_input_data_t* input, acc_output_data_t* output, acc_status_t *status)
{
  uint8          obj_nr;
  sint8          relevant_obj_nr_ctrl, relevant_obj_nr_alert;
  acceleration_t min_command_accel_ctrl, min_command_accel_alert;
  acceleration_t ctrl_accel;
  acc_object_t * object;
  times_t        ReactionTime;

  min_command_accel_ctrl = Accel_max;
  min_command_accel_alert = Accel_max;
  relevant_obj_nr_ctrl = OBJ_INDEX_NO_OBJECT;
  relevant_obj_nr_alert = OBJ_INDEX_NO_OBJECT;
  ReactionTime = Acc_t_reaction_brake;

  output->ACC_OUTPUT_STATUS.ALLOW_INIT = FALSE;

  if (object_list != NULL)
  {
    for(obj_nr = 0u; obj_nr < Acc_max_number_ooi; obj_nr++)
    {
      object = &(object_list[obj_nr]);
      if(
          (object->USAGE_STATUS.INTEREST == TRUE)
          &&
          (
            (object->AUTOSAR.OBJECT_STATUS.MEASURED == TRUE)
            ||
            (object->AUTOSAR.OBJECT_STATUS.TRACKED == TRUE)
          )
          &&
          ( /* Object dynamic property is validated for ACC reaction */
            (object->AUTOSAR.OBJECT_STATUS.MOVING == TRUE)
            ||
            (object->AUTOSAR.OBJECT_STATUS.STANDING == TRUE)
            ||
            (object->AUTOSAR.OBJECT_STATUS.STOPPED == TRUE)
          )
        )
      {
        object->NEEDED_DECEL = PHYS_CALC_NEEDED_DECEL(input->LONG_ACCELERATION, input->LONG_VELOCITY, ReactionTime, object->AUTOSAR.REL_LONG_SPEED, object->AUTOSAR.REL_LONG_ACCEL, object->LONG_SPEED, object->LONG_ACCEL_MODIFIED, object->AUTOSAR.LONG_DISPLACEMENT);

        /*calculate needed acceleration if not defined by accel band*/
        if(object->MAX_ALLOWED_ACCEL != object->MAX_ALLOWED_DECEL)
        {

          object->CONTROL_ACCEL = HP_t_DetermineDistControlAccel(object, input->DRIVER_CONTROLS.HEADWAY_SETTING, input->LONG_ACCELERATION);

#if ( HP_CFG_OVERTAKE_SUPPORT_FEATURE && CFG_FCT_ACC_APPROACH_SUPPRESSION )

          /* Optimization of control acceleration is only done */
          /* in case of active overtake support feature and */
          /* a present approach situation */
          if (   (   ( status->ACC_OVERTAKE_DATA.e_OTState == OVERTAKE_RUNNING )
                  || ( status->ACC_OVERTAKE_DATA.e_OTState == OVERTAKE_EXTENDED )
                  )
                  /* 1e-2 [m/s], 0x8000 ... 0x7FFF */
              && ( object->AUTOSAR.REL_LONG_SPEED < ( velocity_t )0 )
              && (object->AUTOSAR.OBJECT_ID == status->ACC_OVERTAKE_DATA.OOI_OTS_ObjId)  /* Check if reducing distance on required Object only */
              )
          {
            /* local vars */
            distance_t s16_min_decel_dist;
            distance_t s16_ena_ctl_out_opt_dist;
            distance_t s16_poss_brake_dist;
            distance_t s16_max_intr_dist;
              
            /* Calculate minimal braking distance for the current maximal possible deceleration */
            /* and the current maximal deceleration gradient */
            s16_min_decel_dist = HP_t_DetermineMinDecelDistance
                                  (  input->LONG_ACCELERATION
                                  , input->LONG_VELOCITY
                                  , object
                                  , output
                                  );

            /* Calculate the distance threshold to re-enable the controller output optimization */
            /* 1e-2 [m], 0x8000 ... 0x7FFF */
            s16_ena_ctl_out_opt_dist = ( distance_t )
              /* 1e-2 [m], 0x8000 ... 0x7FFF */
              MAT_LIM
              (  /* 1e-2 [m], 0x8000.0000 ... 0x7FFF.FFFF */
                  ( sint32 )( s16_min_decel_dist + HP_OTS_DIST_ENA_CTL_OUT_OPT )
                , Distance_min
                , Distance_max
              );

            /* Calculate the intrusion distance based on the headway setting and relative speed */
            /* 1e-2 [m], 0x8000 ... 0x7FFF */
            s16_max_intr_dist =
              /* 1e-2 [m], 0x8000 ... 0x7FFF */
              HP_t_DetermineMaxIntrusion
              (  /* 1e-2 [m], 0x8000 ... 0x7FFF */
                  HP_t_GetAlertDistance( object )
                , object->REQUESTED_DISTANCE_MODIFIED_PRED
                , input->LONG_VELOCITY
                , input->DRIVER_CONTROLS.HEADWAY_SETTING
                , object->AUTOSAR.REL_LONG_SPEED
                , object->ALERT_MODIFICATION_FACTOR
                , object->AUTOSAR.REL_LONG_ACCEL
              );

            /* Calculate the possible braking distance */
            /* 1e-2 [m], 0x8000 ... 0x7FFF */
            s16_poss_brake_dist = object->AUTOSAR.LONG_DISPLACEMENT - s16_max_intr_dist;

            /* Re-enable the controller output optimization if the possible braking distance */
            /* is significantly greater than the minimum braking distance */
            /* This mechanism should avoid a toggling behavior of the output controller */
            if (   /* 1e-2 [m], 0x8000 ... 0x7FFF */
                    ( s16_poss_brake_dist > s16_ena_ctl_out_opt_dist )
                && ( status->APPROACH_SUPPRESSION[obj_nr] == FALSE )
                )
            {
              status->APPROACH_SUPPRESSION[obj_nr] = TRUE;
            }

            /* As long as the possible braking distance is greater than the minimum */
            /* braking distance, the controller output can be set to 0 [m/s^2] */
            /* in case of an approach situation with active overtake support feature */
            if (   /* 1e-2 [m], 0x8000 ... 0x7FFF */
                    ( s16_poss_brake_dist > s16_min_decel_dist )
                && ( status->APPROACH_SUPPRESSION[obj_nr] == TRUE )
                )
            {
              /* Only optimize the controller output in case the requested acceleration is negative */
              /* 1e-3 [m/s^2], 0x8000 ... 0x7FFF */
              if ( object->CONTROL_ACCEL < Acc_otsupport_min_approach_accel )
              {
                /* 1e-3 [m/s^2], 0x8000 ... 0x7FFF */
                object->CONTROL_ACCEL = Acc_otsupport_min_approach_accel;
              }
            }
            /* In case the possible brake distance undershoots the calculated minimal */
            /* braking distance, the controller output is not optimized anymore */
            /* Optimization is inhibited */
            else
            {
              status->APPROACH_SUPPRESSION[obj_nr] = FALSE;
            }
          }
          /* Reset the approach suppression flag when overtake support is not active */
          else
          {
            status->APPROACH_SUPPRESSION[obj_nr] = FALSE;
          }
    
#endif /* HP_CFG_OVERTAKE_SUPPORT_FEATURE && CFG_FCT_ACC_APPROACH_SUPPRESSION */

          /* Output acceleration arbitrated in critical situations to prevent crash */
          if(
              (object->TTC < Hp_critical_ttc_thres) &&
              (output->ACC_OUTPUT_STATUS.ALERT == TRUE)
            )
          {
            object->CONTROL_ACCEL = (acceleration_t)MAT_MIN((sint32)object->CONTROL_ACCEL, (sint32)object->NEEDED_DECEL);
            object->CONTROL_ACCEL = (acceleration_t)MAT_MAX((sint32)object->CONTROL_ACCEL, (sint32)output->MAX_ACC_DECELERATION);
          }
            
        }
        else
        {
          object->CONTROL_ACCEL = object->MAX_ALLOWED_ACCEL;
        }

        /*control object - use smallest limited acceleration*/
        ctrl_accel = (acceleration_t)MAT_LIM((sint32)object->CONTROL_ACCEL, (sint32)object->MAX_ALLOWED_DECEL, (sint32)object->MAX_ALLOWED_ACCEL);
        if(ctrl_accel < min_command_accel_ctrl)
        {
          min_command_accel_ctrl = ctrl_accel;
          relevant_obj_nr_ctrl = (sint8)obj_nr;
#if ( FCT_CFG_DEBUG_FUZZY_CONTROLLER )
          /* Save a copy of the Fuzzy Controller internal values if for the object that is used for control */
          FuzzyDebugDataControlObject = FuzzyDebugData;
#endif
        }

        /*alert object - use smallest overall acceleration*/
        if(
           (object->CONTROL_ACCEL < min_command_accel_alert)
#if CFG_FCT_USE_ONLY_FIRST_OBJECT_FOR_ALERT 
           &&
           (obj_nr == Obj_first_host_lane)
#endif
          )
        {
          min_command_accel_alert = object->CONTROL_ACCEL;
          relevant_obj_nr_alert = (sint8)obj_nr;
        }
      }
      else
      {
        object->CONTROL_ACCEL = Acc_max_allowed_accel;
      }
    }
  }

  if (relevant_obj_nr_ctrl >= 0)
  {
    object_list[relevant_obj_nr_ctrl].USAGE_STATUS.USE_FOR_CONTROL = TRUE;// PRQA S 505
    /* date: 2018-03-22, reviewer: Ravikiran Gurrala, reason: Checked that array index is within boundary values */

    /* New OOI-0 as control object -> Output accel jump in LOPC to ego acceleration through initialization */
    if ((relevant_obj_nr_ctrl == Obj_first_host_lane) && (control_object->AUTOSAR.OBJECT_ID != object_list[relevant_obj_nr_ctrl].AUTOSAR.OBJECT_ID)) 
    {
      output->ACC_OUTPUT_STATUS.ALLOW_INIT = TRUE;
    }

    *control_object = (object_list[relevant_obj_nr_ctrl]);
    /* Control accel with object specific limitations */
    control_object->CONTROL_ACCEL = (acceleration_t)MAT_LIM((sint32)min_command_accel_ctrl, (sint32)output->MAX_ACC_DECELERATION, (sint32)output->MAX_ACC_ACCELERATION);
  }
  else
  {
    if(control_object->AUTOSAR.OBJECT_ID != ACC_NO_OBJECT.AUTOSAR.OBJECT_ID)
    { /* Control object has been lost -> Output accel jump in LOPC to ego acceleration through initialization */
      output->ACC_OUTPUT_STATUS.ALLOW_INIT = TRUE;
    }

    *control_object = ACC_NO_OBJECT;
  }

  /* Output acceleration suppression for lost targets */
  if (status->TIMER_LIMIT_ACCEL_OBJ_LOST > ( times_t )0)
  {
    output->MAX_ACC_ACCELERATION = (acceleration_t)MAT_MIN((sint32)output->MAX_ACC_ACCELERATION, (sint32)Acc_max_accel_object_lost);
    control_object->CONTROL_ACCEL  = (acceleration_t)MAT_MIN((sint32)control_object->CONTROL_ACCEL, (sint32)output->MAX_ACC_ACCELERATION);
  }

  if(relevant_obj_nr_alert >= 0)
  {
    object_list[relevant_obj_nr_alert].USAGE_STATUS.USE_FOR_ALERT = TRUE;
    *alert_object = (object_list[relevant_obj_nr_alert]);
  }
  else
  {
    *alert_object = ACC_NO_OBJECT;
  }


  /*if object in own lane available, use this object as display object otherwise use control object*/
#if (CFG_FCT_ACC_DISPLAY_ONLY_FIRST_OBJECT) 
  *display_object = ACC_NO_OBJECT;

  if(&(object_list[0]) != 0)
  {
    if(
       (object_list[0].LANE_INFORMATION == Obj_lane_same) 
       && 
       (object_list[0].USAGE_STATUS.INTEREST == TRUE)
       &&
       (
        (object_list[0].AUTOSAR.OBJECT_STATUS.MEASURED == TRUE)
        ||
        (object_list[0].AUTOSAR.OBJECT_STATUS.TRACKED == TRUE)
       )
      )
    {
      /*use first object in lane*/
      *display_object = object_list[0];
    }
  }
#else
  *display_object = *control_object;

  if(relevant_obj_nr_ctrl != Obj_first_host_lane)
  { /*do not show objects from adjacent lanes if they are not used for control*/
    if(MAT_LIM((sint32)display_object->CONTROL_ACCEL, (sint32)display_object->MAX_ALLOWED_DECEL, (sint32)display_object->MAX_ALLOWED_ACCEL) >= input->CC_ACCEL_LIMIT)
    {
      *display_object = ACC_NO_OBJECT; 
    }
  }
#endif

  if(output->ACC_OUTPUT_STATUS.INHIBITED == TRUE)
  { /*do not show objects if acc is inhibited*/
    *display_object = ACC_NO_OBJECT; 
  }

  _PARAM_UNUSED(status);
}	// PRQA S 7004
/* date: 2019-06-18, reviewer: Niraj Mistry, reason: Cyclomatic complexity. Not safety critical */

/*************************************************************************************************************************
  Functionname:    HP_v_DeleteObject                                                                                */ /*!

  @brief           Initialize object to a safe value (no object detected)

  @description     Initialize object to a safe value (no object detected)
                   Reset all object attributes

				   @startuml
					Start
					  Partition HP_v_DeleteObject {
						If(Valid object is present) then (Yes)
						-Clear the object quality
						-Restet the object status values
						-Reset the lognitudinal speed 
						-Reset the longitudinal acceleration 
						-Reset the longitudinal and latral displacement 
						-Control acceleration set to ACC max allowed acceleration 
						-Maximum acceleration set to ACC max allowed acceleration 
						-Maximum deceleration set to ACC max allowed deceleration 
						-Reset the lateral displacement from lane 
						-Reset the lane information, object id and width
						-Set cut in and out potential to zero
						-Set the control smoothness to zero 
						-Set the alert modification factor to default value
						-Set the TTS, TTC default value
						-Acceleration request fuzzy, tts, and dim value set to zero    
 						-Update the object uiVersionNumber
						Endif 	
					  }	
					End 
				   @enduml

  @return          void

  @param[in,out]   object : ACC control object
                        AUTOSAR.QUALITY : object quality [Full range of datatype confidence_t as in Rte_type.h]
                        AUTOSAR.CLASS : object classification [0 ... 4]
                        AUTOSAR.OBJECT_ID : object ID number [-1 ... 127]
                        AUTOSAR.WIDTH : Object width [Full range of datatype distance_t as in Rte_type.h]
                        AUTOSAR.OBJECT_STATUS.MEASURED : Flag for object detection [TRUE,FALSE]
                        AUTOSAR.OBJECT_STATUS.TRACKED : Flag for object detection [TRUE,FALSE]
                        AUTOSAR.OBJECT_STATUS.NEW : Flag which indicates newly selection of object [TRUE,FALSE]
                        AUTOSAR.OBJECT_STATUS.DETECTED : Flag for object detection [TRUE,FALSE]
                        AUTOSAR.OBJECT_STATUS.STOPPED : Object stopped (seen moving) [TRUE,FALSE]
                        AUTOSAR.OBJECT_STATUS.STANDING : Object standing (never seen moving) [TRUE,FALSE]
                        AUTOSAR.OBJECT_STATUS.MOVING : Object moving [TRUE,FALSE]
                        LONG_SPEED : Object speed [Full range of datatype velocity_t as in Rte_type.h]
                        LONG_ACCEL : Object acceleration [Full range of datatype acceleration_t as in Rte_type.h]
                        CONTROL_ACCEL : Needed acceleration/deceleration to maintain requested distance to the object  [Full range of datatype acceleration_t as in Rte_type.h]
                        AUTOSAR.LONG_DISPLACEMENT : Object distance [Full range of datatype distance_t as in Rte_type.h]
                        AUTOSAR.LAT_DISPLACEMENT : Object lateral distance [Full range of datatype distance_t as in Rte_type.h]
                        AUTOSAR.REL_LONG_ACCEL : Object relative acceleration [Full range of datatype acceleration_t as in Rte_type.h]
                        AUTOSAR.REL_LAT_ACCEL : Object relative lateral acceleration [Full range of datatype acceleration_t as in Rte_type.h]
                        AUTOSAR.REL_LONG_SPEED : Object relative speed [Full range of datatype velocity_t as in Rte_type.h]
                        AUTOSAR.REL_LAT_SPEED : Object relative lateral speed [Full range of datatype velocity_t as in Rte_type.h]
                        MAX_ALLOWED_ACCEL : ACC acceleration limit for this control object [Full range of datatype acceleration_t as in Rte_type.h]
                        MAX_ALLOWED_DECEL : ACC deceleration limit for this control object [Full range of datatype acceleration_t as in Rte_type.h]
                        LAT_DISPL_FROM_LANE : Lateral displacement from predicted path [Full range of datatype distance_t as in Rte_type.h]
                        LANE_INFORMATION : Lane the object is associated to [-1,0,1]
                        ACC_CUT_IN_OUT_POTENTIAL : Potential of this object to cut in or out for ACC funtion [0 ... 100] %
                        CONTROL_SMOOTHNESS : Smoothness value for longitudinal control [0 ... 100] %
                        ALERT_MODIFICATION_FACTOR : Factor for modifying the alert distance [0 ... 100] %
                        TTS : Time to stop for objects stopping within the next seconds [Full range of datatype times_t as in Rte_type.h]
                        ACCEL_REQUEST_FUZZY : Acceleration request from fuzzy controller [Full range of datatype acceleration_t as in Rte_type.h]
                        ACCEL_REQUEST_TTS : Acceleration request from physics to standstill [Full range of datatype acceleration_t as in Rte_type.h]
                        ACCEL_REQUEST_DMIN : Acceleration request from physics to approach to set distance [Full range of datatype acceleration_t as in Rte_type.h]

  @glob_in         -
  @glob_out        -

  @c_switch_full   FCT_CFG_LOHP_COMPONENT : Configuration switch for enabling LOHP component
  @c_switch_full   FCT_CFG_ACC_HEADWAY_PLANNER : Configuration switch to enable ACC functionality

  @pre             -
  @post            -

  @created         14.04.2016
  @changed         14.04.2016

  @traceability    doors://rbgs854a:40000/?version=2&prodID=0&view=00000002&urn=urn:telelogic::1-503e822e5ec3651e-O-110-0008a201
  
  @author          Jens Both | jens.both@continental-corporation.com | +49 (8382) 9699-757
*************************************************************************************************************************/
void HP_v_DeleteObject(acc_object_t * const object)
{
  if(object != NULL)
  {
    object->AUTOSAR.QUALITY = 0u;
    object->AUTOSAR.CLASS = Obj_class_none;
    object->AUTOSAR.OBJECT_STATUS.MEASURED = FALSE;
    object->AUTOSAR.OBJECT_STATUS.TRACKED = FALSE;
    object->AUTOSAR.OBJECT_STATUS.NEW = FALSE;
    object->AUTOSAR.OBJECT_STATUS.STANDING = FALSE;
    object->AUTOSAR.OBJECT_STATUS.STOPPED = FALSE;
    object->AUTOSAR.OBJECT_STATUS.MOVING = FALSE;
    object->AUTOSAR.OBJECT_STATUS.DETECTED = FALSE;
    object->LONG_SPEED = (velocity_t)0;
    object->LONG_ACCEL = (acceleration_t)0;
    object->AUTOSAR.REL_LONG_ACCEL = (acceleration_t)0;
    object->AUTOSAR.REL_LAT_ACCEL = (acceleration_t)0;
    object->AUTOSAR.LONG_DISPLACEMENT = (distance_t)Distance_max;
    object->AUTOSAR.LAT_DISPLACEMENT = (distance_t)0;
    object->AUTOSAR.REL_LONG_SPEED = (velocity_t)0;
    object->AUTOSAR.REL_LAT_SPEED = (velocity_t)0;  
    object->CONTROL_ACCEL = Acc_max_allowed_accel;
    object->MAX_ALLOWED_ACCEL = Acc_max_allowed_accel;
    object->MAX_ALLOWED_DECEL = Acc_max_allowed_decel;
    object->LAT_DISPL_FROM_LANE = (distance_t)0;
    object->LANE_INFORMATION = Obj_lane_same;
    object->AUTOSAR.OBJECT_ID = OBJ_INDEX_NO_OBJECT;
    object->AUTOSAR.WIDTH = 0;
    object->ACC_CUT_IN_OUT_POTENTIAL = (quality_t)0;
    object->CONTROL_SMOOTHNESS = (percentage_t)0;
    /* do not set  object->REQUESTED_DISTANCE_MODIFIED_ACT and object->REQUESTED_DISTANCE_MODIFIED_PRED  here */
    object->ALERT_MODIFICATION_FACTOR = Factor_s;
    /*do not set object->LONG_ACCEL_MODIFIED*/
    /* do not set object->LAST_OBJECT_ID = OBJ_INDEX_NO_OBJECT; */
    object->TTS = Acc_tts_default_value;
    object->TTC = Acc_si_max_relevant_ttc;
    object->ACCEL_REQUEST_FUZZY = 0;
    object->ACCEL_REQUEST_TTS = 0;
    object->ACCEL_REQUEST_DMIN = 0;

    object->uiVersionNumber = ACC_DISPLAY_OBJECT_INTFVER;
  }
}


#endif /* (FCT_CFG_LOHP_COMPONENT) && (FCT_CFG_ACC_HEADWAY_PLANNER) */

/** @} end defgroup */
