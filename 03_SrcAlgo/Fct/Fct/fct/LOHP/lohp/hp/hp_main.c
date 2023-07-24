/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC/LOHP/HP (Adaptive Cruise Control - Longitudinal Headway Planner - Headway Planner)

PACKAGENAME:               hp_main.c

DESCRIPTION:               This file contains all functions concerning the
                           processing of object data for headway planner

AUTHOR:                    Mistry Niraj (uidq5738)

CREATION DATE:             24.02.2017

VERSION:                   $Revision: 1.59 $

LEGACY VERSION:            Revision: 1.22

**************************************************************************** */

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/** 
@defgroup   hp_main Hp_main
@ingroup    hp
@brief      Main functions for HP module
@{ */ 

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "hp.h"

#ifdef FCT_SIMULATION
#include "calcFuzzy.h"
#endif

#if ((FCT_CFG_LOHP_COMPONENT) && (FCT_CFG_ACC_HEADWAY_PLANNER))

/*****************************************************************************
  MODULE LOCAL SYMBOLIC CONSTANTS
*****************************************************************************/

/* Hysteresis factor for performance degradation */
#define HP_MAX_DIST_PERF_HYST           0.1f
/* Maximum positive jerk limit for target vehicle */
#define HP_MAX_TARGET_JERK              5000
/* Default width for object */
#define HP_DEFAULT_OBJECT_WIDTH         200
/* Maximum intrusion distance */
#define HP_DEFAULT_INTRUSION_DIST       20000

/*****************************************************************************
  MODULE LOCAL TYPES
*****************************************************************************/

/*****************************************************************************
  MODULE GLOBAL VARIABLES
*****************************************************************************/
acc_object_t ACC_NO_OBJECT;

/*****************************************************************************
  MODULE LOCAL FUNCTIONS
*****************************************************************************/
static void HP_v_DetermineRecommendedVelocity(const acc_input_data_t* input, acc_output_data_t* output);
static void HP_v_CheckForInhibition(const acc_input_data_t* input, acc_output_data_t* output);
static void HP_v_InitDriverIntention(acc_driver_intention_t* driver_intention);
static void HP_v_AssembleOutputData(const acc_input_data_t* input, const acc_object_t* control_object, acc_output_data_t* output);
static void HP_v_DetermineControlDistance(const acc_input_data_t *input, acc_status_t *status, acc_output_data_t *output);
static void HP_v_ModifyObjectProperties(const times_t cycle_time, acc_object_t object_list[Acc_max_number_ooi]);
static void HP_v_ModifyObjectPropertiesLastCycle(acc_object_t object_list[Acc_max_number_ooi]);
static void HP_v_LimitObjAccelNegGrad(const times_t cycle_time, acc_object_t *object);
static void HP_v_CopyInputObj(const CopyObjInput_t t_CopyObjInput, CopyObjOutput_t t_CopyObjOutput, uint8 u8_OOINr);
#if (HP_CFG_OVERTAKE_SUPPORT_FEATURE)
static void HP_v_InitOvertakeData(acc_overtake_data_t* overtake_data);
#endif



#ifdef FCT_SIMULATION  
/*************************************************************************************************************************
  @fn               HP_v_GetFuzzyInput                                                                              */ /*!
  @brief            puts all the fuzzy inputs together (for ACC FRC tool)

  @description     for FuzzyRuleCreator: puts all the fuzzy inputs together (for ACC FRC tool)

  @return          DLLEXPORT void

  @param[in,out]   input : pointer to acc_input_data_t structure for acc input interface containing vehicle related data
                      input->LONG_ACCELERATION : longitudinal acceleration of the host vehicle (ego)    [full range of acceleration_t type as defined in Rte_Type.h]
                      input->DRIVER_CONTROLS.HEADWAY_SETTING : actual headway setting in percent        [percentage_t type as defined in Rte_Type.h] [0u... 100u]

  @param[in]       control_object : Pointer to acc_object_t structure containing acc output from FCT SEN to FCT VEH
                      control_object->LONG_SPEED : Longitudinal speed of control object                        [full range of velocity_t type as defined in Rte_Type.h]
                      control_object->AUTOSAR.REL_LONG_SPEED : Relative longitudinal speed of control object   [full range of velocity_t type as defined in Rte_Type.h]
                      control_object->REQUESTED_DISTANCE_MODIFIED_PRED : Requested distance                    [full range of distance_t type as defined in Rte_Type.h]
                      control_object->LONG_ACCEL_MODIFIED : Modified longitudinal acceleration                 [full range of acceleration_t type as defined in Rte_Type.h]
                      control_object->AUTOSAR.LONG_DISPLACEMENT : Longitudinal displacement of control object  [full range of distance_t type as defined in Rte_Type.h]
                      control_object->REQUESTED_DISTANCE_MODIFIED_ACT : Modified requested distance            [full range of distance_t type as defined in Rte_Type.h]
                      control_object->CONTROL_SMOOTHNESS : Smoothness of control                               [percentage_t type as defined in Rte_Type.h] [0u... 100u]

  @param[in,out]   output : Pointer to acc_output_data_t structure containing 

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_LOHP_COMPONENT : Configuration switch for enabling LOHP component
                   FCT_CFG_ACC_HEADWAY_PLANNER : Configuration switch enabeling Adaptive Cruise Control functionality (with object evaluation)

  @pre             -
  @post            -

  @created         -
  @changed         5/31/2016

  @author          -
*************************************************************************************************************************/
DLLEXPORT void HP_v_GetFuzzyInput(acc_input_data_t* input, const acc_object_t* control_object, acc_output_data_t* output)
{
  sint32  sim[32];  /*!< Note changed from direct signed long int to sint32 */
  sint32  help_var;
  sint32  host_acceleration, object_acceleration;
  sint32  control_error;
  sint32  requested_distance, max_intrusion_distance;  
  sint32  host_velocity;
  sint32  dist;

  sint32  max_pred_time,time_to_stop;

  host_velocity = (velocity_t)(control_object->LONG_SPEED - control_object->AUTOSAR.REL_LONG_SPEED);
  host_acceleration = (sint32)input->LONG_ACCELERATION;

  /*calculate time to stop of host vehicle*/
  time_to_stop = HP_t_DetermineTimeToStop(host_acceleration, host_velocity);

  max_pred_time = MAT_MIN((sint32)Acc_predicted_reaction_time,time_to_stop);

  /*Predict vehicle velocity after prediction time */
  /*It is assumed that the host vehicle has a PT1 behaviour*/
  help_var = (sint32)host_acceleration * (sint32)max_pred_time;
  help_var /= (sint32)Acceleration_s;
  help_var *= (sint32)Velocity_s; 
  help_var /= (sint32)Time_s;

  host_velocity += (velocity_t)help_var;
  host_velocity = (velocity_t)MAT_LIM((sint32)host_velocity,(sint32)0,(sint32)Speed_max);


  requested_distance = control_object->REQUESTED_DISTANCE_MODIFIED_PRED;
  max_intrusion_distance = HP_t_DetermineMaxIntrusion(HP_t_GetAlertDistance(control_object),requested_distance, host_velocity, input->DRIVER_CONTROLS.HEADWAY_SETTING, control_object->AUTOSAR.REL_LONG_SPEED, control_object->ALERT_MODIFICATION_FACTOR);

  object_acceleration = (sint32)control_object->LONG_ACCEL_MODIFIED;
  control_error = (sint32)(control_object->AUTOSAR.LONG_DISPLACEMENT - requested_distance); 

  dist = control_object->REQUESTED_DISTANCE_MODIFIED_ACT;
  /*just for simulation startup...*/
  if(dist == 0)
  {
    dist = 100;
  }


  sim[0] = ((sint32)control_object->AUTOSAR.LONG_DISPLACEMENT * (sint32)Factor_s) / dist;
  sim[1] = (sint32)(control_object->AUTOSAR.REL_LONG_SPEED - help_var) ;
  sim[2] = object_acceleration;
  sim[3] = control_error;
  sim[4] = (sint32)(control_object->AUTOSAR.LONG_DISPLACEMENT - max_intrusion_distance);
  sim[5] = (sint32)control_object->CONTROL_SMOOTHNESS;
  sim[6] = (sint32)host_velocity;
  sim[7] = (sint32)(control_object->LONG_SPEED);
  sim[8] = (sint32)(control_object->AUTOSAR.LONG_DISPLACEMENT);
  setFuzzyInput(sim);
}
#endif


/*************************************************************************************************************************
  Functionname:    HP_v_DetermineRecommendedVelocity                                                                */ /*!

  @brief           Functional Summary

  @description     Detailed Design

					@startuml
					Start
						Partition HP_v_DetermineRecommendedVelocity {
						 - Calculate the recommended Velocity from parametr table by interpolation 
					}
					End	
					@enduml

  @return          void

  @param[in]       input : pointer to acc_input_data_t structure for acc input interface containing vehicle related data
                      input->VISIBILITY_RANGE : maximum longitudinal displacement at 
                                                        which objects can be reported      [full range of distance_t type as defined in Rte_Type.h]
  @param[in,out]   output : Pointer to acc_output_data_t structure containing 
                                                    acc output from FCT SEN to FCT VEH
                      output->RECOMMENDED_VELOCITY : Recommended Velocity                  [full range of velocity_t type as defined in Rte_Type.h]

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_LOHP_COMPONENT : Configuration switch for enabling LOHP component
                   FCT_CFG_ACC_HEADWAY_PLANNER : Configuration switch enabeling Adaptive Cruise Control functionality (with object evaluation)

  @pre             -
  @post            -

  @created         -
  @changed         5/31/2016

  @author          -
*************************************************************************************************************************/
static void HP_v_DetermineRecommendedVelocity(const acc_input_data_t* input, acc_output_data_t* output)
{
  output->RECOMMENDED_VELOCITY = (velocity_t)MAT_CALCULATE_PARAM_VALUE1D(Acc_recommended_velocity_curve, (uint16)Acc_recommended_velocity_curve_points,  input->VISIBILITY_RANGE);
}

/*************************************************************************************************************************
  Functionname:    HP_v_CheckForInhibition                                                                          */ /*!

  @brief           When the visibility range is to low for the driven velocity,
                   the inhibit bit shall be set

  @description     When the visibility range is to low for the driven velocity,
                   the inhibit bit shall be set

				   @startuml
					Start
						Partition HP_v_CheckForInhibition {
						If(Ego velocity is greater than zero)then(Yes)
							-Calculate the visibility (Seconds)
						Else(No)
							-Set visibility to the maximum value (65535u) 
						endif
						If(Visbility value is below or near to longitudinal visibilty \n threshold  for ACC engagement OR Input inhibition is set) then (Yes)
							-Set the Acc output inhibition bit 
						Else(No)
							If(Visibility is greater than or equal to\n longitudinal visibilty threshold for ACC engaged)
							-Clear the Acc output inhibition bit
							endif
						endif
					}
					End	
					@enduml

  @return          void

  @param[in]       input : pointer to acc_input_data_t structure for acc input interface containing vehicle related data
                      input->LONG_VELOCITY : longitudinal velocity of the host vehicle (ego)      [full range of velocity_t type as defined in Rte_Type.h]
                      input->VISIBILITY_RANGE : maximum longitudinal displacement at 
                                                               which objects can be reported      [full range of distance_t type as defined in Rte_Type.h]
                      input->INPUT_STATUS.INHIBIT : flag to determine acc inhibited or active     [ubit8_t type as defined in algo_type.h] [0u...1u]

  @param[in,out]   output : Pointer to acc_output_data_t structure containing acc output from FCT SEN to FCT VEH
                      output->ACC_OUTPUT_STATUS.INHIBITED : flag to determine acc inhibited or not    [boolean type as defined in Platform_Types.h] [0u....1u]

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_LOHP_COMPONENT : Configuration switch for enabling LOHP component
                   FCT_CFG_ACC_HEADWAY_PLANNER : Configuration switch enabeling Adaptive Cruise Control functionality (with object evaluation)

  @pre             -
  @post            -

  @created         -
  @changed         5/31/2016

  @author          -
*************************************************************************************************************************/
static void HP_v_CheckForInhibition(const acc_input_data_t* input, acc_output_data_t* output)
{
  sint32         visibility;

  /* visibility [s] = range [m] / velocity [m/s] */
  if (input->LONG_VELOCITY > (velocity_t)0) 
  {
    visibility = (sint32)input->VISIBILITY_RANGE;
    visibility *= (sint32)Time_s;
    visibility /= (sint32)Distance_s;
    visibility *= (sint32)Velocity_s;
    visibility /= (sint32)input->LONG_VELOCITY;
    visibility = MAT_LIM(visibility, (sint32)0, (sint32)Time_max);
  }
  else
  {
    visibility = Time_max; 
  }

  if (
       (visibility <= Acc_t_visibility_disengage)
       ||
       (input->INPUT_STATUS.INHIBIT == TRUE)
     )
  {
    output->ACC_OUTPUT_STATUS.INHIBITED = TRUE;
  }
  else
  {
    if (visibility >= Acc_t_visibility_engage)
    {
      output->ACC_OUTPUT_STATUS.INHIBITED = FALSE;
    }
  }
}

/*************************************************************************************************************************
  Functionname:    HP_v_AssembleOutputData                                                                          */ /*!

  @brief           Calculates the needed acceleration for the control object

  @description     Assembles the acc output data for external usage

				@startuml
				Start
					Partition HP_v_AssembleOutputData {
						-Convert the headway setting from percentage to second 
						-Calculate the time to stop of host vehicle 
						-Calculate the ACC predicted reaction time 
						-Calculate the predicted velocity of host vehicle
					If(Acc output inhibition flag is false)then (Yes)
						-Calculate the maximum allowed intrusion distance
						-Calculate acceleration output of LOHP
					Else(No)
						-Maximum allowed intrusion distance set to 20000 value
						-Set the min and max distance control \nacceleration to the maximum allowed acceleration(4000)	
					Endif
						-Update the output of headway setting
				}
				End	
				@enduml
	
  @return          void

  @param[in]       input : Pointer to ACC input interface vehicle related data
                       input->LONG_ACCELERATION : longitudinal acceleration of the host vehicle (ego)    [full range of acceleration_t type as defined in Rte_Type.h]
                       input->LONG_VELOCITY : longitudinal velocity of the host vehicle (ego)            [full range of velocity_t type as defined in Rte_Type.h]
                       input->DRIVER_CONTROLS.HEADWAY_SETTING : actual headway setting in percent        [percentage_t type as defined in Rte_Type.h] [0u... 100u]


  @param[in]       control_object : Pointer to acc_object_t structure containing acc output from FCT SEN to FCT VEH
                      control_object->REQUESTED_DISTANCE_MODIFIED_PRED : Requested distance                    [full range of distance_t type as defined in Rte_Type.h]
                      control_object->AUTOSAR.REL_LONG_SPEED : Relative longitudinal speed of control object   [full range of velocity_t type as defined in Rte_Type.h]
                      control_object->CONTROL_ACCEL : Control object acceleration                              [full range of acceleration_t type as defined in Rte_Type.h]
                      control_object->MAX_ALLOWED_DECEL : Maximum allowed decelration for control object       [full range of acceleration_t type as defined in Rte_Type.h]
                      control_object->MAX_ALLOWED_ACCEL : Maximum allowed acceleration for control object      [full range of acceleration_t type as defined in Rte_Type.h]


  @param[in,out]   output : Pointer to acc_output_data_t structure containing acc output from FCT SEN to FCT VEH
                      output->REQUESTED_TIMEGAP : Requested time gap                                  [times_t type as defined in Rte_Type.h] [0u....+65535u]
                      output->MAX_ACC_ACCELERATION : Maximum acc acceleration                         [full range of acceleration_t type as defined in Rte_Type.h]
                      output->MAX_ACC_DECELERATION : Maximum acc decelration                          [full range of acceleration_t type as defined in Rte_Type.h]
                      output->ACC_OUTPUT_STATUS.INHIBITED : flag to determine acc inhibited or not    [boolean type as defined in Platform_Types.h] [0u....1u]
                      output->REQUESTED_MAX_INTRUSION : Maximum intrusion distance                    [full range of distance_t type as defined in Rte_Type.h]
                      output->DISTANCE_CTRL_ACCEL_MAX : Maximum acceleration for intrusion distance   [full range of acceleration_t type as defined in Rte_Type.h]
                      output->DISTANCE_CTRL_ACCEL_MIN : Minimum acceleration for intrusion distance   [full range of acceleration_t type as defined in Rte_Type.h]
                      output->HEADWAY_SETTING : actual headway setting in percent                     [percentage_t type as defined in Rte_Type.h] [0u... 100u]

  @glob_in         -
  @glob_out        -

  @c_switch_part   FCT_CFG_FSRACC : Configuration switch enabeling Full Speed Range Adaptive Cruise Control functionality with stop and go feature
  @c_switch_full   FCT_CFG_LOHP_COMPONENT : Configuration switch for enabling LOHP component
                   FCT_CFG_ACC_HEADWAY_PLANNER : Configuration switch enabeling Adaptive Cruise Control functionality (with object evaluation)

  @pre             -
  @post            -

  @created         -
  @changed         5/31/2016

  @author          -
*************************************************************************************************************************/
static void HP_v_AssembleOutputData(const acc_input_data_t* input, const acc_object_t* control_object, acc_output_data_t* output)
{

  velocity_t host_predicted_velocity, host_velocity;
  acceleration_t host_acceleration, a_rel;
  sint32         help_var, time_to_stop, max_pred_time;


  host_acceleration = input->LONG_ACCELERATION;
  host_velocity = input->LONG_VELOCITY;
  a_rel = control_object->AUTOSAR.REL_LONG_ACCEL;

  /*convert headway setting from 0-100% to 1-2s (*1000)*/
  output->REQUESTED_TIMEGAP = (times_t)(((uint32)input->DRIVER_CONTROLS.HEADWAY_SETTING * (sint32)Time_s) / (uint32)Percentage_max + (uint32)Time_s);
  /*calculate time to stop of host vehicle*/

  time_to_stop = (sint32)HP_t_DetermineTimeToStop(host_acceleration, host_velocity);

  max_pred_time = MAT_MIN((sint32)Acc_predicted_reaction_time,time_to_stop);

  /* Predict vehicle velocity after reaction time */
  /*It is assumed that the host vehicle has a PT1 behaviour*/ 
  help_var = (sint32)host_acceleration * (sint32)max_pred_time;
  help_var /= (sint32)Acceleration_s;
  help_var *= (sint32)Velocity_s; 
  help_var /= (sint32)Time_s;
  host_predicted_velocity = (velocity_t)MAT_LIM(((sint32)host_velocity + help_var),(sint32)0,(sint32)Speed_max);


  if(output->ACC_OUTPUT_STATUS.INHIBITED == FALSE)
  {
    output->REQUESTED_MAX_INTRUSION = HP_t_DetermineMaxIntrusion(HP_t_GetAlertDistance(control_object), control_object->REQUESTED_DISTANCE_MODIFIED_PRED, 
                                                                host_predicted_velocity, input->DRIVER_CONTROLS.HEADWAY_SETTING, control_object->AUTOSAR.REL_LONG_SPEED, 
                                                                control_object->ALERT_MODIFICATION_FACTOR, a_rel);

    /*calculate max acceleration*/
    output->DISTANCE_CTRL_ACCEL_MAX = (acceleration_t)MAT_LIM((sint32)control_object->CONTROL_ACCEL, (sint32)control_object->MAX_ALLOWED_DECEL, (sint32)control_object->MAX_ALLOWED_ACCEL);
    output->DISTANCE_CTRL_ACCEL_MIN = output->DISTANCE_CTRL_ACCEL_MAX;
  }
  else
  {
    /*ACC is inhibited - so use standard values*/
    output->REQUESTED_MAX_INTRUSION = (distance_t)HP_DEFAULT_INTRUSION_DIST;

    /*calculate max acceleration*/
    output->DISTANCE_CTRL_ACCEL_MAX = Acc_max_allowed_accel;
    output->DISTANCE_CTRL_ACCEL_MIN = output->DISTANCE_CTRL_ACCEL_MAX;
  }
  output->HEADWAY_SETTING = input->DRIVER_CONTROLS.HEADWAY_SETTING;
}


/*************************************************************************************************************************
  Functionname:    HP_v_InitDriverIntention                                                                         */ /*!

  @brief           Initialize driver intention variables

  @description     Initialize driver intention variables

					@startuml
					Start
						Partition HP_v_InitDriverIntention {
						-Reset all driver intention variables 
					}
					End	
					@enduml


  @return          void

  @param[in,out]   *driver_intention : Pointer to acc_driver_intention_t type structure defined in acc_ext.h containing driver intention data for ACC
                          driver_intention->DECEL_LIM_OVERRIDE.ACC_LIMITER_ACTIVE : flag indicating acc limited active or not   [ubit8_t type as defined in algo_type.h] [0u...1u]
                          driver_intention->DECEL_LIM_OVERRIDE.CC_LIMITER_ACTIVE : flag indicating acc limited active or not    [ubit8_t type as defined in algo_type.h] [0u...1u]
                          driver_intention->DECEL_LIM_OVERRIDE_ACCEL : max allowed acceleration after override                  [full range of acceleration_t type as defined in Rte_Type.h]
                          driver_intention->LANE_CHANGE_LEFT_PROBABILITY : probability of a lane change to left direction       [percentage_t type as defined in Rte_Type.h] [0u... 100u]
                          driver_intention->LANE_CHANGE_RIGHT_PROBABILITY : probability of a lane change to right direction     [percentage_t type as defined in Rte_Type.h] [0u... 100u]
                          SWITCH_INIT_SWITCH(&(driver_intention->ACC_ENAGAGED)) : strcture containing acc switches
                          driver_intention->OBJECT_NR_TO_CONTROL_TO : object index number that is used to control regardless
                                                                                                   if it is stationary or not   [ObjNumber_t type as defined in Rte_Type.h] [-1...+39]

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_LOHP_COMPONENT : Configuration switch for enabling LOHP component
                   FCT_CFG_ACC_HEADWAY_PLANNER : Configuration switch enabeling Adaptive Cruise Control functionality (with object evaluation)

  @pre             -
  @post            -

  @created         -
  @changed         5/31/2016

  @author          -
*************************************************************************************************************************/
static void HP_v_InitDriverIntention(acc_driver_intention_t* driver_intention)
{
  driver_intention->DECEL_LIM_OVERRIDE.ACC_LIMITER_ACTIVE = FALSE;
  driver_intention->DECEL_LIM_OVERRIDE.ACC_LIMITER_ACTIVE_LAST_CYCLE = FALSE;
  driver_intention->DECEL_LIM_OVERRIDE.CC_LIMITER_ACTIVE = FALSE;
  driver_intention->DECEL_LIM_OVERRIDE_ACCEL = Accel_min;
  driver_intention->LANE_CHANGE_LEFT_PROBABILITY = 0u;
  driver_intention->LANE_CHANGE_RIGHT_PROBABILITY = 0u;
  SWITCH_INIT_SWITCH(&(driver_intention->ACC_ENGAGED));
  driver_intention->OBJECT_NR_TO_CONTROL_TO = OBJ_INDEX_NO_OBJECT;
}

#if (HP_CFG_OVERTAKE_SUPPORT_FEATURE)
/*************************************************************************************************************************
  Functionname:    HP_v_InitOvertakeData                                                                            */ /*!

  @brief           Initialize overtake support feature data variables

  @description     Initialize overtake support feature data variables

					@startuml
					Start
						Partition HP_v_InitOvertakeData {
						 - Reset overtake support feature data variables
					}
					End	
					@enduml

  @return          void

  @param[in,out]   overtake_data : Pointer to acc_overtake_data_t type structure defined in acc_ext.h containing overtake support feature data for ACC
                          b_Overtake_Support_On: Boolean indicating overtake support is active [0,1]
                          b_RampObjReqDist     : Boolean to ramp up object distance after feature cancel [0,1]
                          s_LCModFactor        : Overtake maneuver alert modification factor [0, 1000]
                          Timer_TGR            : Timer for running of time gap reduction phase [0,65535u; times_t as per Rte_Type.h]
                          Timer_BP             : Timer for running of bypass phase [0,65535u; times_t as per Rte_Type.h]
                          e_OTState            : Overtake support feature transition state [0,5; OTState_t_e as per hp_ext.h]
                          e_OTDirection        : Overtake direction status [OTIntention_t_e as per hp_ext.h]
                          OOI_OTS_ObjId        : Object Id of OOI-0 at start of overtake support maneouvre [-1, 255]

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_LOHP_COMPONENT : Configuration switch for enabling LOHP component
                   FCT_CFG_ACC_HEADWAY_PLANNER : Configuration switch enabling Adaptive Cruise Control functionality (with object evaluation)
                   HP_CFG_OVERTAKE_SUPPORT_FEATURE : Overtake support feature activation

  @pre             -
  @post            -

  @created         -
  @changed         5/31/2016

  @author          -
*************************************************************************************************************************/
static void HP_v_InitOvertakeData(acc_overtake_data_t* overtake_data)
{
  overtake_data->b_Overtake_Support_On = FALSE;
  overtake_data->b_RampObjReqDist = FALSE;
  overtake_data->s_LCModFactor = Factor_s;
  overtake_data->Timer_TGR = (times_t)0;
  overtake_data->Timer_BP = (times_t)0;
  overtake_data->e_OTState = OVERTAKE_IDLE;
  overtake_data->e_OTDirection = OVERTAKE_OFF;
  overtake_data->OOI_OTS_ObjId = OBJ_INDEX_NO_OBJECT;
}
#endif

/*************************************************************************************************************************
  Functionname:    HP_v_Init                                                                                        */ /*!

  @brief           Initialize global variables

  @description     Initialize global variables

  @startuml
    Start
      Partition HP_v_Init {
        -Initialize global variable ACC_NO_OBJECT to\n default values (no object detected)
        -Initialize ACC alert data
        -Initialize driver intention variables
        -Reset local 6 object list
        -Reset overtake prevention bits of six objects
        -Initialize overtake support feature data variables
        -Clear approach decel suppression flag for ooi objects
        -Initialize the acc input data
        -Reset parallel lane change flag
      }
    End	
  @enduml


  @return          void

  @param[in,out]   *alert_object : Pointer to acc_object_t type structure as defined in Rte_Type.h for alert object
  @param[in,out]   *acc_status : Pointer to acc_status_t type structure as defined in Rte_Type.h containing all internal status information of acc component
                        acc_status->ACC_ALERT_DATA : acc_alert_data_t type structure containing Result of the ACC alert algorithm
                        acc_status->ACC_DRIVER_INTENTION : acc_driver_intention_t type structure containing driver intention data for ACC
  @param[in,out]   *acc_input_data_ptr : ACC input interface struct
  @param[out]      object_list : ACC internal OOI object list

  @glob_in         -
  @glob_out        -

  @c_switch_part   HP_CFG_OVERTAKE_PREVENTION_FEATURE : Activation of Overtake prevention feature
  @c_switch_part   HP_CFG_OVERTAKE_SUPPORT_FEATURE : Activation of Overtake support feature
  @c_switch_full   FCT_CFG_LOHP_COMPONENT : Configuration switch for enabling LOHP component
                   FCT_CFG_ACC_HEADWAY_PLANNER : Configuration switch enabling Adaptive Cruise Control functionality (with object evaluation)

  @pre             -
  @post            -

  @created         -
  @changed         5/31/2016

  @traceability	   doors://rbgs854a:40000/?version=2&prodID=0&view=00000002&urn=urn:telelogic::1-503e822e5ec3651e-O-108-0008a201

  @author          -
*************************************************************************************************************************/
void HP_v_Init(acc_object_t *alert_object, acc_status_t *acc_status, acc_input_data_t * acc_input_data_ptr, acc_object_t object_list[Acc_max_number_ooi])
{
  uint8 i;

  HP_v_DeleteObject(&ACC_NO_OBJECT);
  *alert_object = ACC_NO_OBJECT;  
  HP_v_AlertInit(&acc_status->ACC_ALERT_DATA);
  HP_v_InitDriverIntention(&acc_status->ACC_DRIVER_INTENTION);

  for( i = 0u; i < Acc_max_number_ooi; i++ )
  {
    object_list[i] = ACC_NO_OBJECT;
  }

#if (HP_CFG_OVERTAKE_PREVENTION_FEATURE)

  for( i = 0; i < Acc_max_number_ooi; i++ )
  {
    acc_input_data_ptr->OT_PREVENTION[i] = FALSE;
    acc_status->OT_PREVENTION[i] = FALSE;
  }
  acc_status->REQ_DIST_OT_PREVENTION = (distance_t)0;
#endif
#if (HP_CFG_OVERTAKE_SUPPORT_FEATURE)
  
  HP_v_InitOvertakeData(&acc_status->ACC_OVERTAKE_DATA);
  
  for( i = 0u; i < Acc_max_number_ooi; i++ )
  {
    acc_status->APPROACH_SUPPRESSION[i] = FALSE;
  }

  /* 1e-3 [s], 0 ... 0xFFFF */
  acc_status->TIMER_LIMIT_ACCEL_OBJ_LOST = ( times_t )0;
#endif

  acc_input_data_ptr->CC_ACCEL_LIMIT = Acc_max_allowed_accel;
  acc_input_data_ptr->CC_DECEL_LIMIT = Acc_max_allowed_decel;
  acc_input_data_ptr->DRIVER_CONTROLS.HEADWAY_SETTING = Acc_default_headway_setting;
  acc_input_data_ptr->DRIVER_CONTROLS.P_LANE_CHANGE_LEFT = 0u;
  acc_input_data_ptr->DRIVER_CONTROLS.P_LANE_CHANGE_RIGHT = 0u;
  acc_input_data_ptr->DRIVER_CONTROLS.e_OTIntention = OVERTAKE_OFF;
  acc_input_data_ptr->DRIVER_CONTROLS.e_LCPhase = LANECHANGE_NO;
  acc_input_data_ptr->DRIVER_CONTROLS.e_TurnIndicator = INDICATOR_OFF;
#if ( HP_CFG_PARALLEL_LANE_CHANGE )
  for( i = 0; i < Acc_max_number_ooi; i++ )
  {
    acc_input_data_ptr->OOI_LC_DIRECTION[i] = LANECHANGE_NONE;
  }
#endif

}


/*************************************************************************************************************************
  Functionname:    HP_v_DetermineControlDistance                                                                    */ /*!

  @brief           determines the control distance using predicted speed values

  @description     determines the control distance using predicted speed values

					@startuml
					Start
						Partition HP_v_DetermineControlDistance {
						-Calculate time to stop value of host vehicle
						-Calculate maximum prediction time 
						-Calculate driver desired distance based on host vehicle velocity 
						-Calculate the predicted velocity of host vehicle 
						-Calculate predicted driver desired distance\n based on predicted host vehicle velocity
					}
					End	
					@enduml

  @return          void

  @param[in]       *input : Pointer to ACC input interface vehicle related data
                      input->LONG_VELOCITY : longitudinal velocity of the host vehicle (ego)            [full range of velocity_t type as defined in Rte_Type.h]
                      input->LONG_ACCELERATION : longitudinal acceleration of the host vehicle (ego)    [full range of acceleration_t type as defined in Rte_Type.h]
                      input->DRIVER_CONTROLS.HEADWAY_SETTING : actual headway setting in percent        [percentage_t type as defined in Rte_Type.h] [0u... 100u]


  @param[in,out]   *status : Pointer to structure containing all internal status information of acc component
                      status->REQUESTED_DISTANCE_ACT : current requested distance                       [full range of distance_t type as defined in Rte_Type.h]
                      status->REQUESTED_DISTANCE_PREDICTED : current predicted requested distance       [full range of distance_t type as defined in Rte_Type.h]


  @param[in,out]   *output : Pointer to acc_output_data_t structure containing acc output from FCT SEN to FCT VEH
                      output->REQUESTED_DISTANCE : requested distance           [full range of distance_t type as defined in Rte_Type.h]

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_LOHP_COMPONENT : Configuration switch for enabling LOHP component
                   FCT_CFG_ACC_HEADWAY_PLANNER : Configuration switch enabeling Adaptive Cruise Control functionality (with object evaluation)

  @pre             -
  @post            -

  @created         -
  @changed         5/31/2016

  @author          -
*************************************************************************************************************************/
static void HP_v_DetermineControlDistance(const acc_input_data_t *input, acc_status_t *status, acc_output_data_t *output)
{
  distance_t mindist, maxdist;

  times_t        max_pred_time, time_to_stop;
  sint32         help_var;
  velocity_t     host_velocity;
  acceleration_t host_acceleration;

  host_velocity = input->LONG_VELOCITY;
  host_acceleration = input->LONG_ACCELERATION;

  /*calculate time to stop of host vehicle*/
  time_to_stop = HP_t_DetermineTimeToStop(host_acceleration, host_velocity);
  
  max_pred_time = (times_t)MAT_MIN((sint32)Acc_predicted_reaction_time,(sint32)time_to_stop);

  /*Predict vehicle velocity after prediction time */
  /*It is assumed that the host vehicle has a PT1 behaviour*/
  help_var = (sint32)host_acceleration* (sint32)max_pred_time;
  help_var /= (sint32)Acceleration_s;
  help_var *= (sint32)Velocity_s; 
  help_var /= (sint32)Time_s;

  mindist = MAT_CALCULATE_PARAM_VALUE1D(Acc_headway_min_dist, Acc_headway_min_dist_points, host_velocity);
  maxdist = MAT_CALCULATE_PARAM_VALUE1D(Acc_headway_max_dist, Acc_headway_max_dist_points, host_velocity);
  status->REQUESTED_DISTANCE_ACT = (distance_t)MAT_MAX((((sint32)input->DRIVER_CONTROLS.HEADWAY_SETTING * ((sint32)maxdist - (sint32)mindist)) / (sint32)Percentage_max + (sint32)mindist), 1);
  output->REQUESTED_DISTANCE = status->REQUESTED_DISTANCE_ACT;
#if (HP_CFG_OVERTAKE_PREVENTION_FEATURE)
  status->REQ_DIST_OT_PREVENTION = (distance_t)MAT_MUL((sint32)Acc_otprevent_des_timegap, host_velocity, Time_s, Velocity_s, Distance_s);
#endif

  host_velocity = (velocity_t)(host_velocity + help_var);
  host_velocity = (velocity_t)MAT_LIM((sint32)host_velocity,(sint32)0,(sint32)Speed_max);

  mindist = MAT_CALCULATE_PARAM_VALUE1D(Acc_headway_min_dist, Acc_headway_min_dist_points, host_velocity);
  maxdist = MAT_CALCULATE_PARAM_VALUE1D(Acc_headway_max_dist, Acc_headway_max_dist_points, host_velocity);
  status->REQUESTED_DISTANCE_PREDICTED = (distance_t)MAT_MAX((((sint32)input->DRIVER_CONTROLS.HEADWAY_SETTING * ((sint32)maxdist - (sint32)mindist)) / (sint32)Percentage_max + (sint32)mindist), 1);
  
}

/*************************************************************************************************************************
  Functionname:    HP_v_LimitObjAccelNegGrad                                                                        */ /*!

  @brief           limits an object acceleration neg grad (for gear shift handling)

  @description     limits an object acceleration neg grad (for gear shift handling)

					@startuml
					Start
						Partition HP_v_LimitObjAccelNegGrad {
						If(Longitudinal acceleration of object is less than  modified acceleration)then (Yes)
						-Calculate the negative grad limiter
						-Calculate the modified logitudinal acceleration
						Else (No)
						-Update the modified acceleration by current acceleration 
						endif
					}
					End	
					@enduml

  @return          void

  @param[in]       cycle_time : Cycle time in mseconds     [full range of times_t type as defined in Rte_Type.h]
  @param[in,out]   *object : Pointer to acc_object_t type output structure as defined in Rte_Type.h
                       object->LONG_ACCEL : Longitudinal acceleration                      [full range of acceleration_t type as defined in Rte_Type.h]
                       object->LONG_ACCEL_MODIFIED : Modified longitudinal acceleration    [full range of acceleration_t type as defined in Rte_Type.h]

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_LOHP_COMPONENT : Configuration switch for enabling LOHP component
                   FCT_CFG_ACC_HEADWAY_PLANNER : Configuration switch enabeling Adaptive Cruise Control functionality (with object evaluation)

  @pre             -
  @post            -

  @created         -
  @changed         5/31/2016

  @author          -
*************************************************************************************************************************/
static void HP_v_LimitObjAccelNegGrad(const times_t cycle_time, acc_object_t *object)
{
  gradient_t max_neg_grad;

  if(object->LONG_ACCEL < object->LONG_ACCEL_MODIFIED)
  {
    /*neg grad limiter needs to be used*/  
    max_neg_grad = (gradient_t)MAT_CALCULATE_PARAM_VALUE1D(Acc_obj_accel_max_neg_grad, Acc_obj_accel_max_neg_grad_points, (sint16)object->LONG_ACCEL);
    max_neg_grad = MAT_MUL(max_neg_grad, (sint32)MAT_CALCULATE_PARAM_VALUE1D(Acc_obj_accel_grad_speed_fac, Acc_obj_accel_grad_speed_fac_points, object->LONG_SPEED), Acceleration_s, Factor_s, Acceleration_s);
    max_neg_grad = MAT_MUL(max_neg_grad, (sint32)MAT_CALCULATE_PARAM_VALUE1D(Acc_obj_accel_grad_accel_d_fac, Acc_obj_accel_grad_accel_d_fac_pt, object->LONG_ACCEL - object->LONG_ACCEL_MODIFIED), Acceleration_s, Factor_s, Acceleration_s);
    object->LONG_ACCEL_MODIFIED = (acceleration_t)MAT_LIM_GRAD((sint32)object->LONG_ACCEL, (sint32)object->LONG_ACCEL_MODIFIED, max_neg_grad, HP_MAX_TARGET_JERK, cycle_time);
  }
  else
  {
    /*just use the current acceleration*/
    object->LONG_ACCEL_MODIFIED = object->LONG_ACCEL;
  }
}

/*************************************************************************************************************************
  Functionname:    HP_v_ModifyObjectProperties                                                                      */ /*!

  @brief           modifies some of the object properties for acc control (special filtering ...)

  @description     modifies some of the object properties for acc control (special filtering ...)

					@startuml
					Start
						Partition HP_v_ModifyObjectProperties {
						If(If object status is detected) then (Yes)
							If(autosar object id is equal to last object id)then (True)
								-update the acceleration for object on host lane
							Else (False)
								-Set the modified longitudinal\n acceleration to current acceleration
							Endif
						Else(No)
							-Update the modified acceleration\n by current acceleration
						endif
					}
					End	
					@enduml

  @return          void

  @param[in]       cycle_time : Cycle time in mseconds     [full range of times_t as defined in Rte_Type.h]

  @param[in]       object_list : Pointer to acc_object_t type structure as defined in Rte_Type.h
                        object_list[onr].AUTOSAR.OBJECT_STATUS.DETECTED : Status of the object     [boolean type as defined in Rte_Type.h] [0u...1u]
                        object_list[onr].AUTOSAR.OBJECT_ID : Object Id of given object             [ObjNumber_t type as defined Rte_Type.h] [0...+39]
                        object_list[onr].LAST_OBJECT_ID : Object id of last detected object        [ObjNumber_t type as defined Rte_Type.h] [0...+39]
                        object_list[onr].LONG_ACCEL_MODIFIED : Modified longitudinal acceleration  [full range of acceleration_t type as defined in Rte_Type.h]
                        object_list[onr].LONG_ACCEL : Longitudinal acceleration                    [full range of acceleration_t type as defined in Rte_Type.h]
  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_LOHP_COMPONENT : Configuration switch for enabling LOHP component
                   FCT_CFG_ACC_HEADWAY_PLANNER : Configuration switch enabeling Adaptive Cruise Control functionality (with object evaluation)

  @pre             object list must be completed
  @post            -

  @created         -
  @changed         5/31/2016

  @author          -
*************************************************************************************************************************/
static void HP_v_ModifyObjectProperties(const times_t cycle_time, acc_object_t object_list[Acc_max_number_ooi])
{
  uint8           onr;

  for(onr = 0u; onr < Acc_max_number_ooi; onr++)
  {
    if(object_list[onr].AUTOSAR.OBJECT_STATUS.DETECTED == TRUE)
    {
      if(object_list[onr].AUTOSAR.OBJECT_ID == object_list[onr].LAST_OBJECT_ID)
      {
        /*same object as in last cycle --> accel filter*/
        switch(onr)
        {
          case (uint8)Obj_first_host_lane:
          case (uint8)Obj_hidden_host_lane:
            HP_v_LimitObjAccelNegGrad(cycle_time, &(object_list[onr]));
            break;

          default:
            object_list[onr].LONG_ACCEL_MODIFIED = object_list[onr].LONG_ACCEL;
            break;
        }
      }
      else
      {
        /* set LONG_ACCEL_MODIFIED to LONG_ACCEL */
        object_list[onr].LONG_ACCEL_MODIFIED = object_list[onr].LONG_ACCEL;
      }
    }
  }
}

/*************************************************************************************************************************
  Functionname:    HP_v_ModifyObjectPropertiesLastCycle                                                             */ /*!

  @brief           modifies some of the object properties for acc control (special filtering ...)

  @description     modifies some of the object properties for acc control (special filtering ...)
		
					@startuml
					Start
						Partition HP_v_ModifyObjectPropertiesLastCycle {
						-Update the all last cycle object\n IDs by current cycle object IDs
					}
					End	
					@enduml

  @return          void

  @param[in]       object_list : Pointer to acc_object_t type structure as defined in Rte_Type.h
                        object_list[onr].AUTOSAR.OBJECT_ID : Object Id of given object             [ObjNumber_t type as defined Rte_Type.h] [0...+39]
                        object_list[onr].LAST_OBJECT_ID : Object id of last detected object        [ObjNumber_t type as defined Rte_Type.h] [0...+39]

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_LOHP_COMPONENT : Configuration switch for enabling LOHP component
                   FCT_CFG_ACC_HEADWAY_PLANNER : Configuration switch enabeling Adaptive Cruise Control functionality (with object evaluation)

  @pre             object list must be completed
  @post            -

  @created         -
  @changed         5/31/2016

  @author          -
*************************************************************************************************************************/
static void HP_v_ModifyObjectPropertiesLastCycle(acc_object_t object_list[Acc_max_number_ooi])
{
  uint8           onr;

  for(onr = 0u; onr < Acc_max_number_ooi; onr++)
  {
    /*! copy object current id to last id*/
    object_list[onr].LAST_OBJECT_ID = object_list[onr].AUTOSAR.OBJECT_ID;
  }
}

/*************************************************************************************************************************
  Functionname:    HP_v_OutInit                                                                                     */ /*!

  @brief           initialize acc output data to neutral values

  @description     initialize acc output data to neutral values

					@startuml
					Start
						Partition HP_v_OutInit {
						-Reset the ACC output status data
						-Reset max and min distance control accelerations
						-Reset requested distance value 
						-Reset max intrusion distance 
						-Reset the time gap value
						-Reset situation class
						-Reset the Acc display object list 
					}
					End	
					@enduml


  @return          -

  @param[out]      pAccDisplayObj : ACC display object struct pointer
  @param[out]      acc_output_data : acc_output_data pointer to acc_output_data structure
                      ACC_OUTPUT_STATUS.ALERT      [true, false]
                      ACC_OUTPUT_STATUS.ALLOW_INIT [true, false]
                      ACC_OUTPUT_STATUS.INHIBITED  [true, false]
                      ACC_OUTPUT_STATUS.INHIBITION_REASON [INHIBITION_REASON_t as per Rte_Type.h]
                      DISTANCE_CTRL_ACCEL_MAX      [acceleration_t as per Rte_Type.h]
                      DISTANCE_CTRL_ACCEL_MIN      [acceleration_t as per Rte_Type.h]
                      HEADWAY_SETTING              [percentage_t as per Rte_Type.h]
                      MAX_ACC_ACCELERATION         [acceleration_t as per Rte_Type.h]
                      MAX_ACC_DECELERATION         [acceleration_t as per Rte_Type.h]
                      REQUESTED_DISTANCE           [distance_t as per Rte_Type.h]
                      REQUESTED_MAX_INTRUSION      [distance_t as per Rte_Type.h]
                      REQUESTED_TIMEGAP            [times_t as per Rte_Type.h]
                      SITUATION_CLASS.CRITICALITY  [confidence_t as per Rte_Type.h]
                      SITUATION_CLASS.SITUATION    [acc_situation_class_t as per Rte_Type.h]

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_HEADWAY_PLANNER : ACC function is enabled
  @c_switch_full   FCT_CFG_LOHP_COMPONENT : Configuration switch for enabling LOHP component

  @pre             -
  @post            -

  @created         -
  @changed         4/20/2016

  @traceability    doors://rbgs854a:40000/?version=2&prodID=0&view=00000002&urn=urn:telelogic::1-503e822e5ec3651e-O-111-0008a201

  @author          -
*************************************************************************************************************************/
void HP_v_OutInit(acc_object_t* pAccDisplayObj, acc_output_data_t *acc_output_data)
{
  acc_output_data->ACC_OUTPUT_STATUS.ALERT      = FALSE;
  acc_output_data->ACC_OUTPUT_STATUS.ALLOW_INIT = FALSE;
  acc_output_data->ACC_OUTPUT_STATUS.INHIBITED  = FALSE;
  acc_output_data->ACC_OUTPUT_STATUS.INHIBITION_REASON = Acc_inhibition_none;
  acc_output_data->DISTANCE_CTRL_ACCEL_MAX      = Acc_max_allowed_accel; /*neutral acc acceleration*/
  acc_output_data->DISTANCE_CTRL_ACCEL_MIN      = Acc_max_allowed_accel; /*neutral acc acceleration*/
  acc_output_data->HEADWAY_SETTING              = Acc_default_headway_setting; /*default headway setting*/
  acc_output_data->MAX_ACC_ACCELERATION         = Acc_max_allowed_accel; /*neutral limit*/
  acc_output_data->MAX_ACC_DECELERATION         = Acc_max_allowed_accel; /*neutral limit*/
  acc_output_data->REQUESTED_DISTANCE           = Distance_max; /*max distance*/
  acc_output_data->REQUESTED_MAX_INTRUSION      = Distance_max; /*neutral distance*/
  acc_output_data->REQUESTED_TIMEGAP            = Time_max; /*max timegap*/
  acc_output_data->SITUATION_CLASS.CRITICALITY  = 0u;
  acc_output_data->SITUATION_CLASS.SITUATION    = Acc_sit_class_undefined;

  *pAccDisplayObj = ACC_NO_OBJECT;
}

#if (FCT_CFG_SEN2VEH_ACC_OOI_PORT)
/*************************************************************************************************************************
  Functionname:    HP_v_CopyObjectUsage                                                                             */ /*!

  @brief           copy object usage, determed by acc control, to 
                   FCTSenAccOOI Port

  @description     copy object usage, determed by acc control, to 
                   FCTSenAccOOI Port

				   @startuml
					Start
						Partition HP_v_CopyObjectUsage {
						If(Acc object ID is valid) then (true)
							- Update the usage state of corresponding ooi object
					Note Left: UsageState:\nOBJ_USAGE_DISPLAY,\nOBJ_USAGE_IDLE,\nOBJ_USAGE_CONTROL,\nOBJ_USAGE_ALERT,
						endif
					}
					End	
				   @enduml

  @return          -

  @param[in,out]   pFCTAccOOIData : FCTSenAccOOI Port [FCTSenAccOOI_t as per Rte_Type.h]
                      AccOOINextLong.Attributes.uiObjectID : [ObjNumber_t as per Rte_Type.h]
                      AccOOIHiddenNextLong.Attributes.uiObjectID : [ObjNumber_t as per Rte_Type.h]
                      AccOOINextLeft.Attributes.uiObjectID : [ObjNumber_t as per Rte_Type.h]
                      AccOOINextRight.Attributes.uiObjectID : [ObjNumber_t as per Rte_Type.h]
                      AccOOIHiddenNextLeft.Attributes.uiObjectID : [ObjNumber_t as per Rte_Type.h]
                      AccOOIHiddenNextRight.Attributes.uiObjectID : [ObjNumber_t as per Rte_Type.h]
  @param[out]      pLOHPUsageState: Pointer to usage state of objects of interest
                      UsageState_OOI_0 : [FCTObjUsageState_t as per Rte_Type.h]
                      UsageState_OOI_1 : [FCTObjUsageState_t as per Rte_Type.h]
                      UsageState_OOI_2 : [FCTObjUsageState_t as per Rte_Type.h]
                      UsageState_OOI_3 : [FCTObjUsageState_t as per Rte_Type.h]
                      UsageState_OOI_4 : [FCTObjUsageState_t as per Rte_Type.h]
                      UsageState_OOI_5 : [FCTObjUsageState_t as per Rte_Type.h]
  @param[in]       ACC_LONG_OBJECT_ID : Object nummber from control, display and alert object [ObjNumber_t as per Rte_Type.h]
  @param[in]       eUsageState : Usage state of object [FCTObjUsageState_t as per Rte_Type.h]

  @glob_in         OBJ_INDEX_NO_OBJECT : [ObjNumber_t as per Rte_Type.h]
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_SEN2VEH_ACC_OOI_PORT : Compiler switch used around this function/file
  @c_switch_full   FCT_CFG_ACC_HEADWAY_PLANNER : ACC function is enabled

  @pre             -
  @post            -

  @created         -
  @changed         4/19/2016

  @traceability	   doors://rbgs854a:40000/?version=2&prodID=0&view=00000002&urn=urn:telelogic::1-503e822e5ec3651e-O-112-0008a201

  @author          -
*************************************************************************************************************************/
void HP_v_CopyObjectUsage(const FCTSenAccOOI_t* pFCTAccOOIData, const ObjNumber_t ACC_LONG_OBJECT_ID, const FCTObjUsageState_t eUsageState, LOHP_ObjUsageState_t* pLOHPUsageState)
{
  /*! Copy object usage to FCTAccOOIData */
  if(ACC_LONG_OBJECT_ID != OBJ_INDEX_NO_OBJECT)
  {
    if(pFCTAccOOIData->AccOOINextLong.Attributes.uiObjectID == ACC_LONG_OBJECT_ID)
    {
      pLOHPUsageState->UsageState_OOI_0 |= eUsageState;
    }
    else if(pFCTAccOOIData->AccOOIHiddenNextLong.Attributes.uiObjectID == ACC_LONG_OBJECT_ID)
    {
      pLOHPUsageState->UsageState_OOI_1 |= eUsageState;
    }
    else if(pFCTAccOOIData->AccOOINextLeft.Attributes.uiObjectID == ACC_LONG_OBJECT_ID)
    {
      pLOHPUsageState->UsageState_OOI_2 |= eUsageState;
    }
    else if(pFCTAccOOIData->AccOOINextRight.Attributes.uiObjectID == ACC_LONG_OBJECT_ID)
    {
      pLOHPUsageState->UsageState_OOI_3 |= eUsageState;
    }
    else if(pFCTAccOOIData->AccOOIHiddenNextLeft.Attributes.uiObjectID == ACC_LONG_OBJECT_ID)
    {
      pLOHPUsageState->UsageState_OOI_4 |= eUsageState;
    }
    else if(pFCTAccOOIData->AccOOIHiddenNextRight.Attributes.uiObjectID == ACC_LONG_OBJECT_ID)
    {
      pLOHPUsageState->UsageState_OOI_5 |= eUsageState;
    }
    else
    {
      /* nothing to do */
    }
  }
}
#endif


/*************************************************************************************************************************
  Functionname:    HP_v_CopyInputObj                                                                                */ /*!

  @brief           copy an input object

  @description     copy object with specified object ID into the buffer
                   provided

          @startuml
          Start
            Partition HP_v_CopyInputObj {
            If(Pointer to object kinematics and attributes from FctSenAccOOI port exist)then (True)
            	-Save the last cycle object ID
            	-Update the object lost information
            	-Update the object status and its tracking information    
            	-Update the object moving status based on dynamic property\n Oncoming OOI-0 selected as relevant.\n Objects with no moving status not considered for ACC reaction
              Note left: STATIONARY\n STOPPED\n MOVING\n ONCOMING\n OTHERS
            	-Determine absolute object speed and acceleration
            	-Determine object kinematic values
            	-Update cutin, cutout potential
            	-Update the object lane information based on associated lane info
            	-Calculate the lateral displacement from lane
            Else (False)
            	-No object currently in given position, delete the object
            Endif
            -Update the ACC object internal values
            }
            End	
          @enduml

  @return          -

  @param[in]       t_CopyObjInput : Input data struct [CopyObjInput_t as per hp.h]
  @param[in]       t_CopyObjOutput : Output data struct [CopyObjOutput_t as per hp.h]
  @param[in]       u8_OOINr : the object ID (index) of the object to copy [0-39]

  @c_switch_full   FCT_CFG_ACC_HEADWAY_PLANNER : ACC function is enabled
  @c_switch_full   FCT_CFG_LOHP_COMPONENT : Configuration switch for enabling LOHP component

  @pre             ACC_INPUT_DATA.LONG_ACCELERATION has to be filled with
                   correct ego longitudinal acceleration signal
  @post            -

  @created         -
  @changed         4/18/2016

  @author          -
*************************************************************************************************************************/
static void HP_v_CopyInputObj(const CopyObjInput_t t_CopyObjInput, CopyObjOutput_t t_CopyObjOutput, uint8 u8_OOINr)
{

  acc_object_t * pDestObj = t_CopyObjOutput.pDestObj;

  /* Check if object exists */
  if ((t_CopyObjInput.pOOIKinematics != NULL) && (t_CopyObjInput.pOOIAttribute != NULL))
  {
    /* Save last cycle object ID */
    const ObjNumber_t LastObjId = pDestObj->AUTOSAR.OBJECT_ID;

    pDestObj->AUTOSAR.LAT_DISPLACEMENT        = (distance_t)(t_CopyObjInput.pOOIKinematics->fDistY * (float32)Distance_s);
    /*! Use hypotenuse instead of DistX, use only positive values of DistX for calculation */
    pDestObj->AUTOSAR.LONG_DISPLACEMENT       = (distance_t)(SQRT(SQR(MAX(0.F,t_CopyObjInput.pOOIKinematics->fDistX)) + SQR(t_CopyObjInput.pOOIKinematics->fDistY)) * (float32)Distance_s);
  
    pDestObj->AUTOSAR.OBJECT_ID               = t_CopyObjInput.ObjNr;
    pDestObj->LAST_OBJECT_ID                  = LastObjId;
    pDestObj->AUTOSAR.OBJECT_STATUS.DETECTED  = TRUE;
    pDestObj->AUTOSAR.OBJECT_STATUS.MEASURED  = TRUE;
    pDestObj->AUTOSAR.OBJECT_STATUS.TRACKED   = TRUE;
    if (LastObjId != t_CopyObjInput.ObjNr)
    {
      pDestObj->AUTOSAR.OBJECT_STATUS.NEW      = TRUE;
      pDestObj->ALERT_MODIFICATION_FACTOR      = Factor_s; /* Initialized for new object */
    }
    else
    {
      pDestObj->AUTOSAR.OBJECT_STATUS.NEW      = FALSE;
    }
    
    /* Determine object property: standing, stopped, moving */
    switch (t_CopyObjInput.pOOIAttribute->eDynamicProperty)
    {
    case EM_GEN_OBJECT_DYN_PROPERTY_STATIONARY:
      pDestObj->AUTOSAR.OBJECT_STATUS.STANDING  = TRUE;
      pDestObj->AUTOSAR.OBJECT_STATUS.STOPPED   = FALSE;
      pDestObj->AUTOSAR.OBJECT_STATUS.MOVING    = FALSE;
      break;
    case EM_GEN_OBJECT_DYN_PROPERTY_STOPPED:
      pDestObj->AUTOSAR.OBJECT_STATUS.STANDING  = FALSE;
      pDestObj->AUTOSAR.OBJECT_STATUS.STOPPED   = TRUE;
      pDestObj->AUTOSAR.OBJECT_STATUS.MOVING    = FALSE;
      break;
    case EM_GEN_OBJECT_DYN_PROPERTY_MOVING:
      pDestObj->AUTOSAR.OBJECT_STATUS.STANDING  = FALSE;
      pDestObj->AUTOSAR.OBJECT_STATUS.STOPPED   = FALSE;
      pDestObj->AUTOSAR.OBJECT_STATUS.MOVING    = TRUE;
      break;
    case EM_GEN_OBJECT_DYN_PROPERTY_ONCOMING:
    case EM_GEN_OBJECT_DYN_PROPERTY_CROSSING_LEFT:
    case EM_GEN_OBJECT_DYN_PROPERTY_CROSSING_RIGHT:
    case EM_GEN_OBJECT_DYN_PROPERTY_UNKNOWN:
    case EM_GEN_OBJECT_DYN_PROPERTY_MAX_DIFF_TYPES:
    default:
      pDestObj->AUTOSAR.OBJECT_STATUS.STANDING  = FALSE;
      pDestObj->AUTOSAR.OBJECT_STATUS.STOPPED   = FALSE;
      pDestObj->AUTOSAR.OBJECT_STATUS.MOVING    = FALSE;

      if((t_CopyObjInput.pOOIAttribute->eDynamicProperty == EM_GEN_OBJECT_DYN_PROPERTY_ONCOMING)
          &&(u8_OOINr == OBJ_NEXT_OOI))
      { /* OOI-0 that has oncoming property is an object in our lane that is rolling back.
          Hence treated as relevant. */
        pDestObj->AUTOSAR.OBJECT_STATUS.MOVING = TRUE;
      }
      break;
    }

    /* Determine absolute object speed and acceleration*/
    HP_v_ObjDataWapper(t_CopyObjInput, pDestObj, u8_OOINr);

    pDestObj->AUTOSAR.QUALITY           = (confidence_t)Confidence_max;
    pDestObj->AUTOSAR.REL_LAT_ACCEL     = (acceleration_t)(t_CopyObjInput.pOOIKinematics->fArelY * (float32)Acceleration_s);
    pDestObj->AUTOSAR.REL_LAT_SPEED     = (velocity_t)(t_CopyObjInput.pOOIKinematics->fVrelY * (float32)Velocity_s);
    pDestObj->AUTOSAR.REL_LONG_ACCEL    = pDestObj->LONG_ACCEL - t_CopyObjInput.acc_input_data_ptr->LONG_ACCELERATION;
    pDestObj->AUTOSAR.WIDTH             = HP_DEFAULT_OBJECT_WIDTH;
    pDestObj->ACC_CUT_IN_OUT_POTENTIAL  = t_CopyObjInput.pOOIAttribute->uiCutInOutProbability;
    /* pDestObj->LAT_DISPL_FROM_LANE       = (distance_t)(t_CopyObjInput.pOOIKinematics->fDistOnTraj * (float32)Distance_s); */
    switch(u8_OOINr)
    {
      case (uint8)OBJ_NEXT_OOI:
      case (uint8)OBJ_HIDDEN_NEXT_OOI:
        pDestObj->LANE_INFORMATION          = Obj_lane_same;
        pDestObj->USAGE_STATUS.LOST_REASON  = LOHP_pSLATEData->t_ObjLossReasonACCOOI[u8_OOINr];
        break;
      case (uint8)OBJ_NEXT_LONG_LEFT_OOI:
      case (uint8)OBJ_NEXT_LAT_LEFT_OOI:
        pDestObj->LANE_INFORMATION          = Obj_lane_left1;
        pDestObj->USAGE_STATUS.LOST_REASON  = LOHP_pSLATEData->t_ObjLossReasonACCOOI[u8_OOINr];
        break;
      case (uint8)OBJ_NEXT_LONG_RIGHT_OOI:
      case (uint8)OBJ_NEXT_LAT_RIGHT_OOI:
        pDestObj->LANE_INFORMATION          = Obj_lane_right1;
        pDestObj->USAGE_STATUS.LOST_REASON  = LOHP_pSLATEData->t_ObjLossReasonACCOOI[u8_OOINr];
        break;
      default:
        pDestObj->LANE_INFORMATION          = Obj_lane_same; 
        pDestObj->USAGE_STATUS.LOST_REASON  = FALSE;
        break;
    }

  }
  else
  {
    /* No object currently in given position, delete the object */
    HP_v_DeleteObject(pDestObj);
  }

  /* Internal values*/
  pDestObj->uiVersionNumber = ACC_DISPLAY_OBJECT_INTFVER;
  pDestObj->USAGE_STATUS.INTEREST          = 0u;

  pDestObj->USAGE_STATUS.USE_FOR_ALERT     = 0u;
  pDestObj->USAGE_STATUS.USE_FOR_CONTROL   = 0u; 
  pDestObj->NEEDED_DECEL                   = 0;
  pDestObj->CONTROL_ACCEL                  = Acc_max_allowed_accel;
  pDestObj->MAX_ALLOWED_ACCEL              = Acc_max_allowed_accel;
  pDestObj->MAX_ALLOWED_DECEL              = Acc_max_allowed_decel;
}

/*************************************************************************************************************************
  Functionname:    HP_v_PreProcess                                                                                  */ /*!

  @brief           Functional Summary

  @description     Detailed Design

					@startuml
					Start
						Partition HP_v_PreProcess {
						-Set ACC input data based on FctVeh2SenInfo port
					Note left: FctVeh2SenInfo: Headway Setting\n Vehicl accel limits \n ACC state On\Off,\n Driver override,\n Ego stand still 
						-Set the driver indicator Status based on input indicator status
					Note left:INDICATOR_OFF, INDICATOR_RIGHT_ON\n INDICATOR_LEFT_ON, INDICATOR_OFF
						-Get lane change information from SLATE
						If(Overtake possible flag is set) then (ture)
	
							-Update the driver overtake intention
							Note left: OVERTAKE_LEFT_ON,\nOVERTAKE_RIGHT_ON

							-Set the driver lane change to LANECHANGE_ON\n if slate e_LCPhase not set to no lane change or prelane change
						Else(False)
							-Set the overtake intention OFF and no lane change
						Endif
						-Update Ego lane change probability for Left and Right lane
						-Set OOi's lane change information
						-Determine ego speed and acceleration
						-Input from SLATE for flag to prevent overtake\nis mapped for objects not in the lane
						-Calculate minimum performance distance with customer restriction	
						-Check the inhibition reason and performance degradation 
						-Setting function parameters for function HP_v_CopyInputObj
						-Call function to set HP parameter
						-Calculate the max ACC acceleration and deceleration limits 
					}
					End	
					@enduml

  @return          -

  @param[in]      cycle_time: the cycle time since last call
  @param[in]      pFctVehLongOut : Pointer to info from LOPC to LOHP
  @param[in]      pVehDyn : Pointer to vehicle dynamics input
  @param[in]      pSLATEData: SLATE output data struct
  @param[in]      pFCTAccOOIData: SLATE 6 ACC object list port
*/
#if (FCT_CFG_CUSTOM_IO_INTERFACE)
/*!
  @param[in]      pCustomInput: Custom Input port to FCT
  */
#endif
/*!
  @param[out]     object_list: pointer to the ACC display object passed to LOPC
  @param[out]     acc_input_data_ptr: ACC input interface struct
  @param[out]     pAccOutput: pointer to the ACC control output data passed to LOPC

  @c_switch_part   FCT_USE_EM_GENERIC_OBJECT_LIST
  @c_switch_part   FCT_USE_EM_ARS_TECH_OBJECT_LIST
  @c_switch_part   FCT_CFG_SLATE_COMPONENT
  @c_switch_part   FCT_CFG_CUSTOM_IO_INTERFACE
  @c_switch_part   FCT_CFG_CUSTOM_IO_ABS_KINEMATIC
  @c_switch_part   CFG_FCT_USE_VDY_HOST_VELOCITY
  @c_switch_part   VDY_VEH_DYN_INTFVER
  @c_switch_full   FCT_CFG_LOHP_COMPONENT
  @c_switch_full   FCT_CFG_ACC_HEADWAY_PLANNER

  @pre             -
  @post            HP_v_Process

  @created         11.07.2017
  @changed         11.07.2017

  @traceability	   doors://rbgs854a:40000/?version=2&prodID=0&view=00000002&urn=urn:telelogic::1-503e822e5ec3651e-O-113-0008a201

  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
void HP_v_PreProcess(const times_t            cycle_time,
                      const FctVeh2SenInfo_t  * pFctVehLongOut, 
                      const VehDyn_t          * pVehDyn,
                      const SLATE_HC_Data_t   * pSLATEData,
                      const FCTSenAccOOI_t    * pFCTAccOOIData,
#if (FCT_CFG_CUSTOM_IO_INTERFACE)
                      const FCTCustomInput_t  * pCustomInput,
#endif
                      acc_object_t            object_list[Acc_max_number_ooi],
                      acc_input_data_t        * const acc_input_data_ptr,
                      acc_output_data_t       * pAccOutput)
{
  uint8 onr;
  CopyObjInput_t t_CopyObjInput;
  CopyObjOutput_t t_CopyObjOutput;
  SLATE_LC_LaneChangePhaseInfo_t t_SLATE_LCInfo;
  fDistance_t f_MaxDistPerf, f_MinDistPerf;

  /*wrapper set ACC_INPUT_DATA*/
  acc_input_data_ptr->CC_ACCEL_LIMIT                      = pFctVehLongOut->MaxAccelLimit;
  acc_input_data_ptr->CC_DECEL_LIMIT                      = pFctVehLongOut->MinAccelLimit;
  acc_input_data_ptr->DRIVER_CONTROLS.HEADWAY_SETTING     = pFctVehLongOut->HeadwaySetting;

#if (FCT_CFG_CUSTOM_IO_INTERFACE)
  switch(pCustomInput->eTurnIndicator)
  {
    case eTurnIndicator_Off:
      acc_input_data_ptr->DRIVER_CONTROLS.e_TurnIndicator = INDICATOR_OFF;
      break;
    case eTurnIndicator_Right:
      acc_input_data_ptr->DRIVER_CONTROLS.e_TurnIndicator = INDICATOR_RIGHT_ON;
      break;
    case eTurnIndicator_Left:
      acc_input_data_ptr->DRIVER_CONTROLS.e_TurnIndicator = INDICATOR_LEFT_ON;
      break;
    default:
      acc_input_data_ptr->DRIVER_CONTROLS.e_TurnIndicator = INDICATOR_OFF;
      break;
  }

#else
  acc_input_data_ptr->DRIVER_CONTROLS.e_TurnIndicator     = INDICATOR_OFF;
#endif  /* FCT_CFG_CUSTOM_IO_INTERFACE */

  /*! Get lane change information from SLATE, convert to local data structure */
  t_SLATE_LCInfo = pSLATEData->t_SLATE_LC;
  if((t_SLATE_LCInfo.e_LCDirection != SLATE_LC_NONE) && (t_SLATE_LCInfo.b_AllowOvertake == TRUE))
  {
    if(t_SLATE_LCInfo.e_LCDirection == SLATE_LC_LEFT)
    { /* Lane change to left */
      acc_input_data_ptr->DRIVER_CONTROLS.e_OTIntention = OVERTAKE_LEFT_ON;
    }
    else
    { /* Lane change to right */
      acc_input_data_ptr->DRIVER_CONTROLS.e_OTIntention = OVERTAKE_RIGHT_ON;
    }
    if(
        (t_SLATE_LCInfo.e_LCPhase == SLATE_LC_NO_LANECHANGE) ||
        (t_SLATE_LCInfo.e_LCPhase == SLATE_LC_PRELANECHANGE)
      )
    {
      acc_input_data_ptr->DRIVER_CONTROLS.e_LCPhase = LANECHANGE_NO;
    }
    else
    {
      acc_input_data_ptr->DRIVER_CONTROLS.e_LCPhase = LANECHANGE_ON;
    }
  }
  else  /* Overtake support is not expected */
  {
    acc_input_data_ptr->DRIVER_CONTROLS.e_OTIntention = OVERTAKE_OFF;
    acc_input_data_ptr->DRIVER_CONTROLS.e_LCPhase = LANECHANGE_NO;
  }

  /* Ego lane change probability */
  if(t_SLATE_LCInfo.e_LCDirection == SLATE_LC_LEFT)
  { /* Lane change to left */
    acc_input_data_ptr->DRIVER_CONTROLS.P_LANE_CHANGE_LEFT  = 
      (percentage_t)MINMAX(Percentage_min, Percentage_max, ROUND_TO_UINT((float32)t_SLATE_LCInfo.u_LCPhaseProb)); // PRQA S 3356
    /* date: 2015-09-16, reviewer: Chirag Patel, reason: Non QAC related but required. */
    acc_input_data_ptr->DRIVER_CONTROLS.P_LANE_CHANGE_RIGHT = (percentage_t)0;
  }
  else if (t_SLATE_LCInfo.e_LCDirection == SLATE_LC_RIGHT)
  { /* Lane change to right */
    acc_input_data_ptr->DRIVER_CONTROLS.P_LANE_CHANGE_RIGHT  = 
      (percentage_t)MINMAX(Percentage_min, Percentage_max, ROUND_TO_UINT((float32)t_SLATE_LCInfo.u_LCPhaseProb)); // PRQA S 3356
    /* date: 2015-09-16, reviewer: Chirag Patel, reason: Non QAC related but required. */
    acc_input_data_ptr->DRIVER_CONTROLS.P_LANE_CHANGE_LEFT = (percentage_t)0;
  }
  else
  {
    acc_input_data_ptr->DRIVER_CONTROLS.P_LANE_CHANGE_RIGHT = (percentage_t)0;
    acc_input_data_ptr->DRIVER_CONTROLS.P_LANE_CHANGE_LEFT = (percentage_t)0;
  }

#if ( HP_CFG_PARALLEL_LANE_CHANGE )
  /* OOI's lane change direction */
  for ( onr = 0; onr < Acc_max_number_ooi; onr++ )
  {
    if ( pSLATEData->t_OOILCState[onr] == SLATE_LC_LEFT )
    {
      acc_input_data_ptr->OOI_LC_DIRECTION[onr] = LANECHANGE_LEFT;
    } 
    else if ( pSLATEData->t_OOILCState[onr] == SLATE_LC_RIGHT )
    {
      acc_input_data_ptr->OOI_LC_DIRECTION[onr] = LANECHANGE_RIGHT;
    }
    else
    {
      acc_input_data_ptr->OOI_LC_DIRECTION[onr] = LANECHANGE_NONE;
    }
  }
#endif

  acc_input_data_ptr->INPUT_STATUS.ACC_ON                 = pFctVehLongOut->AccOn;
  acc_input_data_ptr->INPUT_STATUS.ACC_NOT_OFF            = pFctVehLongOut->AccNotOff; /* ACC active including override */
  acc_input_data_ptr->INPUT_STATUS.INHIBIT                = FALSE;
  acc_input_data_ptr->INPUT_STATUS.CC_DECEL_LIM_OVERRIDE  = pFctVehLongOut->DecelLimOverride;
  acc_input_data_ptr->INPUT_STATUS.ACC_CONTROL_TO_FIRST_OBJECT = pFctVehLongOut->CtrlToRelevObj;
  acc_input_data_ptr->INPUT_STATUS.OBJECT_EFFECTIVE       = pFctVehLongOut->ObjectEffective;
  acc_input_data_ptr->INPUT_STATUS.OBJECT_LOST            = FALSE; /*will be set later in code*/

  acc_input_data_ptr->LODM_STAT.STANDSTILL      = pFctVehLongOut->StandStill;
  acc_input_data_ptr->LODM_STAT.OVERRIDE_ACCEL  = pFctVehLongOut->OverrideAccel;

  /* Determine ego speed and acceleration */
  HP_v_EgoDataWapper(pVehDyn, pFctVehLongOut, acc_input_data_ptr);
  acc_input_data_ptr->VISIBILITY_RANGE    = (distance_t)(180 * Distance_s);

  /*! Object lost information for relevant object */
  if(pFCTAccOOIData->AccOOINextLong.Attributes.uiObjectID == OBJ_INDEX_NO_OBJECT)
  {
    /* The object lost information in LOHP is used limit the acceleration output in case */
    /* the object has disappeared or been lost due to a curve */
    /* 1 [-], 0 ... 0xFF */
    if (( pFCTAccOOIData->AccOOINextLong.eRelObjLossReason == OBJ_LOSS_DISAPPEARED)
      || (pFCTAccOOIData->AccOOINextLong.eRelObjLossReason == OBJ_LOSS_CURVE_LEFT)
      || (pFCTAccOOIData->AccOOINextLong.eRelObjLossReason == OBJ_LOSS_CURVE_RIGHT)
      || (pFCTAccOOIData->AccOOINextLong.eRelObjLossReason == OBJ_LOSS_STEER_LEFT)
      || (pFCTAccOOIData->AccOOINextLong.eRelObjLossReason == OBJ_LOSS_STEER_RIGHT)
      )
    {
      acc_input_data_ptr->INPUT_STATUS.OBJECT_LOST  = TRUE;
    }
    else
    {
      acc_input_data_ptr->INPUT_STATUS.OBJECT_LOST  = FALSE;
    }
  }

#if (HP_CFG_OVERTAKE_PREVENTION_FEATURE)
  /* Input from SLATE for flag to prevent overtake is mapped for objects not in the lane */
  acc_input_data_ptr->OT_PREVENTION[Obj_first_left_lane] = pFCTAccOOIData->AccOOINextLeft.Attributes.b_PreventOvertake;
  acc_input_data_ptr->OT_PREVENTION[Obj_first_right_lane] = pFCTAccOOIData->AccOOINextRight.Attributes.b_PreventOvertake;
  acc_input_data_ptr->OT_PREVENTION[Obj_second_left_lane] = pFCTAccOOIData->AccOOIHiddenNextLeft.Attributes.b_PreventOvertake;
  acc_input_data_ptr->OT_PREVENTION[Obj_second_right_lane] = pFCTAccOOIData->AccOOIHiddenNextRight.Attributes.b_PreventOvertake;
#else
  _PARAM_UNUSED(pFCTAccOOIData);
#endif

  /* Setting of distance for performance degradation */
#ifdef FCT_SIM_EXT
  /* For fct_sim_ext simulation, deactivate performance degradation */
  f_MaxDistPerf = 250.0f;
  f_MinDistPerf = 250.0f;
#else
  f_MaxDistPerf = pSLATEData->t_APM_Data.f_MaxDistALN;//APM_f_GetMaxDistPerfACC_ALN();
  /* Min performance distance with customer restrictions */
  f_MinDistPerf = MAX_FLOAT(pSLATEData->t_APM_Data.f_MaxDistPerfMin,((float32)Acc_min_cust_perf_dist)/((float32)Distance_s));
#endif

  /* Go through OOI list */
  for(onr = 0u; onr < Acc_max_number_ooi; onr++) 
  {

    ObjNumber_t CurObjId;
    const AccOOIGenKinematics_t * pOOIKinematics;
    const AccOOIGenAttributes_t * pOOIAttribute;

    switch(onr)
    {
    case (uint8)OBJ_NEXT_OOI:
      CurObjId        =   pFCTAccOOIData->AccOOINextLong.Attributes.uiObjectID;
      pOOIKinematics  = &(pFCTAccOOIData->AccOOINextLong.Kinematic);
      pOOIAttribute   = &(pFCTAccOOIData->AccOOINextLong.Attributes);
      break;
    case (uint8)OBJ_HIDDEN_NEXT_OOI:
      CurObjId        =   pFCTAccOOIData->AccOOIHiddenNextLong.Attributes.uiObjectID;
      pOOIKinematics  = &(pFCTAccOOIData->AccOOIHiddenNextLong.Kinematic);
      pOOIAttribute   = &(pFCTAccOOIData->AccOOIHiddenNextLong.Attributes);
      break;
    case (uint8)OBJ_NEXT_LONG_LEFT_OOI:
      CurObjId        =   pFCTAccOOIData->AccOOINextLeft.Attributes.uiObjectID;
      pOOIKinematics  = &(pFCTAccOOIData->AccOOINextLeft.Kinematic);
      pOOIAttribute   = &(pFCTAccOOIData->AccOOINextLeft.Attributes);
      break;
    case (uint8)OBJ_NEXT_LONG_RIGHT_OOI: 
      CurObjId        =   pFCTAccOOIData->AccOOINextRight.Attributes.uiObjectID;
      pOOIKinematics  = &(pFCTAccOOIData->AccOOINextRight.Kinematic);
      pOOIAttribute   = &(pFCTAccOOIData->AccOOINextRight.Attributes);
      break;
    case (uint8)OBJ_NEXT_LAT_LEFT_OOI:
      CurObjId        =   pFCTAccOOIData->AccOOIHiddenNextLeft.Attributes.uiObjectID;
      pOOIKinematics  = &(pFCTAccOOIData->AccOOIHiddenNextLeft.Kinematic);
      pOOIAttribute   = &(pFCTAccOOIData->AccOOIHiddenNextLeft.Attributes);
      break;
    case (uint8)OBJ_NEXT_LAT_RIGHT_OOI:
      CurObjId       =   pFCTAccOOIData->AccOOIHiddenNextRight.Attributes.uiObjectID;
      pOOIKinematics = &(pFCTAccOOIData->AccOOIHiddenNextRight.Kinematic);
      pOOIAttribute  = &(pFCTAccOOIData->AccOOIHiddenNextRight.Attributes);
      break;
    default:
      CurObjId       = OBJ_INDEX_NO_OBJECT;
      pOOIKinematics = NULL;
      pOOIAttribute  = NULL;
      break;
    }

    if ((CurObjId >= 0) && (CurObjId < EM_N_OBJECTS))
    {
      if( /*! Distance hysteresis for performance degradation */
        (pOOIKinematics->fDistX < f_MinDistPerf)
        ||
        ((object_list[onr].AUTOSAR.OBJECT_ID == CurObjId)
        && (pOOIKinematics->fDistX < (f_MaxDistPerf + f_MaxDistPerf * HP_MAX_DIST_PERF_HYST)))
        ||
        ((object_list[onr].AUTOSAR.OBJECT_ID != CurObjId)
        && (pOOIKinematics->fDistX < f_MaxDistPerf))
        )
      {
        /* Do nothing. Object information carried over */
      }
      else
      {
        pOOIKinematics = NULL;
        pOOIAttribute  = NULL;
      }
    }
    else
    { /* Object not existing -> Leads to HP_v_DeleteObject */
      pOOIKinematics = NULL;
      pOOIAttribute  = NULL;
    }
      
    /* Setting function parameters for function HP_v_CopyInputObj */
    t_CopyObjInput.cycle_time         = cycle_time;
    t_CopyObjInput.pSLATEData         = pSLATEData;
    t_CopyObjInput.pFCTAccOOIData     = pFCTAccOOIData;
    t_CopyObjInput.pOOIKinematics     = pOOIKinematics;
    t_CopyObjInput.pOOIAttribute      = pOOIAttribute;
    t_CopyObjInput.ObjNr              = CurObjId;
    t_CopyObjInput.acc_input_data_ptr = acc_input_data_ptr;
    t_CopyObjOutput.pDestObj          = &object_list[onr];
    t_CopyObjInput.pFctVehLongOut     = pFctVehLongOut;

#if (HP_CFG_PRE_LC_OBJ_LA)
	/* Input from SLATE about OOI's Lane assosiation when pre lane chnage starts*/
  acc_input_data_ptr->FuncLaneAss_AT_PRE_LC[onr] = pSLATEData->t_FuncLaneAss_LC[onr];
#endif /* HP_CFG_PRE_LC_OBJ_LA */

    HP_v_CopyInputObj(t_CopyObjInput, t_CopyObjOutput, onr);
    
  }  /*end for */

  HP_v_SelectParamSet();

  /* Fill output acceleration limits dependent on ego speed */
#if (FCT_CFG_FSRACC)
  pAccOutput->MAX_ACC_ACCELERATION = MAT_CALCULATE_PARAM_VALUE1D(Acc_fsr_max_acceleration,(uint16)Acc_fsr_max_acceleration_points, acc_input_data_ptr->LONG_VELOCITY);
  pAccOutput->MAX_ACC_DECELERATION = MAT_CALCULATE_PARAM_VALUE1D(Acc_fsr_max_deceleration,(uint16)Acc_fsr_max_deceleration_points, acc_input_data_ptr->LONG_VELOCITY); 
#else
  pAccOutput->MAX_ACC_ACCELERATION = MAT_CALCULATE_PARAM_VALUE1D(Acc_max_acceleration, (uint16)Acc_max_acceleration_points, acc_input_data_ptr->LONG_VELOCITY);
  pAccOutput->MAX_ACC_DECELERATION = MAT_CALCULATE_PARAM_VALUE1D(Acc_max_deceleration, (uint16)Acc_max_deceleration_points, acc_input_data_ptr->LONG_VELOCITY);
#endif

}// PRQA S 7012, 7004
/* date: 2019-05-06, reviewer: Niraj Mistry, reason: Cyclomatic complexity. Not safety critical */

/*************************************************************************************************************************
  Functionname:    HP_v_Process                                                                                     */ /*!

  @brief           Execute sequence for Headway planner

  @description     HP main loop

					@startuml
					Start
						Partition HP_v_Process{
						-Check the inhibition condition 
						-Calculate the Velocity from paramaetr table with interpolation
						-determines the control distance using predicted speed values
						-Modifies some of the object properties for acc control
						-Estimate driver intention
						-Select objects of interest and update the information
						-Select function relevant objects
						-Estimation traffic situation
						-Update the HP output data
						-Determine ALERT_DATA
						-Modifies some of the object properties for acc control
					}
					End	
					@enduml

  @return          DLLEXPORT void

  @param[in]       cycle_time : Cycle time in mseconds     [full range of times_t type as defined in Rte_Type.h]
  @param[in]       *input : Pointer to acc_input_data_t type structure as defined in acc_ext.h containing input data to acc
  @param[in,out]   object_list : array of acc_object_t type structure for 6 OOI as defined in Rte_Type.h
  @param[in,out]   *output : pointer to acc_output_data_t type structure as defined in Rte_Type.h containing acc output data
  @param[in,out]   *alert_object : Pointer to acc_object_t type structure as defined in Rte_Type.h for alert object
  @param[in,out]   *display_object : Pointer to acc_object_t type structure as defined in Rte_Type.h for display object
  @param[in,out]   *acc_status : Pointer to acc_status_t type structure as defined in Rte_Type.h containing all internal status information of acc component

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_LOHP_COMPONENT : Configuration switch for enabling LOHP component
                   FCT_CFG_ACC_HEADWAY_PLANNER : Configuration switch enabeling Adaptive Cruise Control functionality (with object evaluation)

  @pre             -
  @post            -

  @created         -
  @changed         5/31/2016

  @traceability   doors://rbgs854a:40000/?version=2&prodID=0&view=00000002&urn=urn:telelogic::1-503e822e5ec3651e-O-109-0008a201 

  @author          -
*************************************************************************************************************************/
DLLEXPORT void HP_v_Process(const times_t cycle_time, const acc_input_data_t* input, acc_object_t object_list[Acc_max_number_ooi],
              acc_output_data_t* output, acc_object_t* alert_object, acc_object_t* display_object, acc_status_t *acc_status)
{

  HP_v_CheckForInhibition(input, output);

  HP_v_DetermineRecommendedVelocity(input, output);

  HP_v_DetermineControlDistance(input, acc_status, output);

  HP_v_ModifyObjectProperties(cycle_time, object_list);

  /* estimate driver intention */
  HP_v_EstimateDriverIntention(cycle_time, object_list, input, &acc_status->ACC_DRIVER_INTENTION, acc_status);
  
  /* select objects of interest and add some information */
  HP_v_SelectObjectsOfInterest(&acc_status->ACC_DRIVER_INTENTION, input, object_list, acc_status, cycle_time);
  
  /* select function relevant objects */
  HP_v_SelectRelevantObject(object_list, &acc_status->ACC_CONTROL_OBJECT, alert_object, display_object, input, output, acc_status);   
  
  /* traffic situation estimation */  
  HP_v_EstimateTrafficSituation(cycle_time, object_list, input, acc_status, output);
  
  /* assemble outputdata */
  HP_v_AssembleOutputData(input, &acc_status->ACC_CONTROL_OBJECT, output);

  HP_v_AlertProcess(input, alert_object, output, &acc_status->ACC_ALERT_DATA, cycle_time);

  HP_v_ModifyObjectPropertiesLastCycle(object_list);

  /* Freezing of ACC parameters */
#if (CFG_FCT_ACC_PARAMS_DEBUG)
  HP_v_FreezeACCParams();
#endif
}


#endif /* (FCT_CFG_LOHP_COMPONENT) && (FCT_CFG_ACC_HEADWAY_PLANNER) */

/** @} end defgroup */
