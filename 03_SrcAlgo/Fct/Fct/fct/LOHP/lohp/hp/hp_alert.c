/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC/LOHP/HP (Adaptive Cruise Control - Longitudinal Headway Planner - Headway Planner)

PACKAGENAME:               hp_alert.c

DESCRIPTION:               This module contains all functions concerning the
                           alert functionality in LOHP/HP

AUTHOR:                    Mistry Niraj (uidq5738)

CREATION DATE:             24.02.2017

VERSION:                   $Revision: 1.11 $

LEGACY VERSION:            Revision: 1.22

**************************************************************************** */

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/** 
@defgroup   hp_alert Hp_alert
@ingroup    hp
@brief      File contains functions concerning alert functionality in HP
@{ */ 

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "hp.h"

#if ((FCT_CFG_LOHP_COMPONENT) && (FCT_CFG_ACC_HEADWAY_PLANNER))

#define Fct_acc_alert_max_sim_steps 15u

static times_t AccAlertOutputTimer = (times_t)0; /*!< the acc alert shall be output a defined period of time,
                                                      to avoid to short acoustical and visual signals */


static void HP_v_DetermineAlert(acc_alert_data_t* alert_data, const acc_object_t* alert_object, acc_output_data_t* output, times_t cycle_time, const acc_input_data_t* input);
static void HP_v_DetermineEstimatedDistance(acc_alert_data_t* alert_data, const acc_object_t* alert_object, const acc_input_data_t* input);
static void HP_v_DetermineAlertThreshold(acc_alert_data_t* alert_data, const acc_input_data_t* input);

/*************************************************************************************************************************
  Functionname:    HP_v_DetermineAlert                                                                              */ /*!

  @brief           Decide whether or not a Takeover alert should be issued

  @description     Decide whether or not a Takeover alert should be issued

          @startuml
					Start
						Partition HP_v_DetermineAlert {
							- Calculate temporary ACC Alert suppress time
              If (ACC Alert is not set) then (true)
                If (Conditions to decrease ACC Alert suppress time) then (true)
                  If (Estimated alert distance smaller or equals 0[m]) then (true)
                    - Set ACC Alert suppress time to 0[s]
                  Endif
                  If (ACC Alert suppress time greater or equals cycle time) then (true) 
                    - Decrease ACC Alert suppress time by cycle time
                  Else (false)
                    - Set ACC Alert Status
                  Endif
                Else (false)
                  - Map ACC Alert suppress time to the previously calculated temporary ACC Alert suppress time
                Endif
              Else (false)
                If (Conditions to clear ACC Alert Status and reset ACC Alert suppress time) then (true)
                  - Clear ACC Alert Status
                  - Map ACC Alert suppress time to the previously calculated temporary ACC Alert suppress time
                Endif
              Endif
						}
					End 
					@enduml

  @return          -

  @param[in,out]   alert_data : information about the previously calculated alert data [acc_alert_data_t as per acc_ext.h]
                      ESTIM_DISTANCE : [distance_t as per Rte_Type.h]
                      ALERT_DISTANCE : [distance_t as per Rte_Type.h]
                      ESTIM_REL_SPEED : [velocity_t as per Rte_Type.h]
                      ALERT_SUPRESS_TIME : [times_t as per Rte_Type.h]
  @param[in]       alert_object : [acc_object_t as per Rte_Type.h]
                      AUTOSAR.OBJECT_STATUS.STANDING : [true, false]
                      AUTOSAR.OBJECT_STATUS.MOVING : [true, false]
                      AUTOSAR.OBJECT_STATUS.STOPPED : [true, false]
                      AUTOSAR.REL_LONG_SPEED : [velocity_t as per Rte_Type.h]
  @param[in,out]   output : [acc_output_data_t as per Rte_Type.h]
                      ACC_OUTPUT_STATUS.ALERT : [true, false]
  @param[in]       cycle_time : [times_t as per Rte_Type.h]
  @param[in]       input : [acc_input_data_t as per acc_ext.h]
                      LONG_VELOCITY : [velocity_t as per Rte_Type.h]

  @glob_in         -
  @glob_out        -
                   
  @c_switch_part   CFG_FCT_ACC_ALERT_STATIONARY_OBJ : acc alert also to (stationary) objektcs (alert will always be occur to stopped objects!)
  @c_switch_full   FCT_CFG_ACC_HEADWAY_PLANNER : ACC function is enabled
  @c_switch_full   FCT_CFG_LOHP_COMPONENT : Configuration switch for enabling LOHP component
                   
  @pre             -
  @post            -
                   
  @created         -
  @changed         4/20/2016

  @author          -
*************************************************************************************************************************/
static void HP_v_DetermineAlert(acc_alert_data_t* alert_data, const acc_object_t* alert_object, acc_output_data_t* output, times_t cycle_time, const acc_input_data_t* input)
{
  times_t Acc_alert_supress_time;

  Acc_alert_supress_time = (times_t)MAT_CALCULATE_PARAM_VALUE1D((const sint16*)Acc_alert_supress_alert_time, (uint16)Acc_alert_supress_alert_time_points, input->LONG_VELOCITY);

  if (output->ACC_OUTPUT_STATUS.ALERT == FALSE)
  {
    if(
       (alert_data->ESTIM_DISTANCE < alert_data->ALERT_DISTANCE) 
       &&
       (alert_data->ESTIM_REL_SPEED < Acc_vrel_estim_min)
       &&
       (
        /* check allowed dynamic state of alert object */
        (alert_object->AUTOSAR.OBJECT_STATUS.MOVING == TRUE)
        ||
        (alert_object->AUTOSAR.OBJECT_STATUS.STOPPED == TRUE)
#if (CFG_FCT_ACC_ALERT_STATIONARY_OBJ)
        ||
        ((alert_object->AUTOSAR.OBJECT_STATUS.STANDING == TRUE)
        && (input->LONG_VELOCITY < Acc_decel_on_stationary_speed))
#endif
       )
      )
    {
      if(alert_data->ESTIM_DISTANCE <= (distance_t)0)
      {
        alert_data->ALERT_SUPRESS_TIME = (times_t)0;
      }
      
      if(alert_data->ALERT_SUPRESS_TIME >= cycle_time)
      {
        alert_data->ALERT_SUPRESS_TIME = (times_t)(alert_data->ALERT_SUPRESS_TIME - cycle_time);
      }
      else
      {
        output->ACC_OUTPUT_STATUS.ALERT = TRUE;
        /* set the acc alert output timer */
        AccAlertOutputTimer = Acc_alert_min_output_time;
      }
      
    }
    else
    {
      alert_data->ALERT_SUPRESS_TIME = Acc_alert_supress_time;
    }
  }
  else
  {
    if (
        (
          ((sint32)alert_data->ESTIM_DISTANCE > (((sint32)alert_data->ALERT_DISTANCE * ((sint32)Factor_s + (sint32)Acc_end_alert_hyst_factor)) / (sint32)Factor_s))
          ||
          (
          (alert_data->ESTIM_DISTANCE > alert_data->ALERT_DISTANCE)
          &&
          (alert_data->ESTIM_REL_SPEED > (velocity_t)0)
          )
          ||
          /* Ego vehicle stopped below alert distance */
          (input->LONG_VELOCITY < Acc_stopped_speed)
          ||
          /* relative speed zero check (not predicted) */
          (alert_object->AUTOSAR.REL_LONG_SPEED > (velocity_t)0)
        )
        &&
        (AccAlertOutputTimer == (times_t)0)
       )
    {
      output->ACC_OUTPUT_STATUS.ALERT = FALSE;
      alert_data->ALERT_SUPRESS_TIME = Acc_alert_supress_time;
    }
  }
  /*! Count down the AccAlertOutputTimer */
  SWITCH_SET_COUNTER(cycle_time, &AccAlertOutputTimer);
}

/*************************************************************************************************************************
  Functionname:    HP_v_DetermineEstimatedDistance                                                                  */ /*!

  @brief           Predict the time gap for the next few seconds

  @description     Simulation of the current situation for the next few seconds to determine the takeover alert

          @startuml
					Start
						Partition HP_v_DetermineEstimatedDistance {
							If (Alert Object is detected) then (true)
                If (Host vehicle is faster than target vehicle) then (true)
                  - Calculate simulation time in 1D interpolation based on host vehicle speed
                Else (false)
                  - Set simulation time to 0[s]
                Endif
                - Calculate discrete simulation steps
                Repeat
                  - Simulate Distance control acceleration
                  - Limit own acceleration to allowed limits
                  - Limit own acceleration change rate
                  - Filter own acceleration based on a simple vehicle model
                  - Predict distance of host vehicle for the next simulation step
                  - Predict speed of host vehicle for the next simulation step
                  - Predict distance of in-path vehicle for the next simulation step
                  - Predict speed of in-path vehicle for the next simulation step
                  - Estimate relative speed between host and in-path vehicle
                  If (Simulated distance and speed values undercut thresholds and alert was still not set) then (true)
                    - Store alert distance and speed
                  Endif
                  If (Simulation abortion conditions are fulfilled) then (true)
                    - Set simulation abortion condition
                  Endif
                Repeat while (Loop over for number of discrete simulation steps without active abortion condition)
                If (Estimated distance does not undercut alert distance threshold or estimated distance does not go below 0) then (true)
                  - Alert data is saved
                Endif
              Else (false)
                - Alert data is set to initialization/neutral values
              Endif
						}
					End
					@enduml

  @return          -

  @param[in,out]   alert_data : information about the previously calculated alert data [acc_alert_data_t as per acc_ext.h]
                      ESTIM_DISTANCE : [distance_t as per Rte_Type.h]
                      ESTIM_REL_SPEED : [velocity_t as per Rte_Type.h]
                      ESTIM_HOST_SPEED : [velocity_t as per Rte_Type.h]
  @param[in,out]   alert_object : [acc_object_t as per Rte_Type.h]
                      AUTOSAR.OBJECT_STATUS.DETECTED : [true, false]
                      AUTOSAR.LONG_DISPLACEMENT : [distance_t as per Rte_Type.h]
                      AUTOSAR.REL_LONG_SPEED : [velocity_t as per Rte_Type.h]
                      MAX_ALLOWED_ACCEL : [acceleration_t as per Rte_Type.h]
                      MAX_ALLOWED_DECEL : [acceleration_t as per Rte_Type.h]
                      LONG_SPEED : [velocity_t as per Rte_Type.h]
                      AUTOSAR.REL_LONG_SPEED : [velocity_t as per Rte_Type.h]
                      LONG_ACCEL_MODIFIED : [acceleration_t as per Rte_Type.h]
                      AUTOSAR.LONG_DISPLACEMENT : [distance_t as per Rte_Type.h]
  @param[in]       input : [acc_input_data_t as per acc_ext.h]
                      LONG_ACCELERATION : [acceleration_t as per Rte_Type.h]
                      LONG_VELOCITY : [velocity_t as per Rte_Type.h]
                      DRIVER_CONTROLS.HEADWAY_SETTING : [percentage_t as per Rte_Type.h]

  @glob_in         -
  @glob_out        -
                   
  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_HEADWAY_PLANNER : ACC function is enabled
  @c_switch_full   FCT_CFG_LOHP_COMPONENT : Configuration switch for enabling LOHP component
                   
  @pre             -
  @post            -
                   
  @created         -
  @changed         4/20/2016

  @author          -
*************************************************************************************************************************/
static void HP_v_DetermineEstimatedDistance(acc_alert_data_t* alert_data, const acc_object_t* alert_object, const acc_input_data_t* input)
{
  sint32            help_var;
  uint8             index;
  uint8             sim_steps;
  acceleration_t    a_own, a_comm, a_req;
  velocity_t        v_own;
  distance_t        s_own;
  distance_t        s_host;
  acc_object_t      sim_object;
  uint8             stop_sim;
  times_t           sim_time;
  uint8             was_below_alert_dist;

  was_below_alert_dist = FALSE;

  index = (uint8)0;
  sim_steps = (uint8)0;
  sim_object = *alert_object;

  stop_sim = FALSE;

  if (sim_object.AUTOSAR.OBJECT_STATUS.DETECTED == TRUE)
  {
    /* Initialization */
    a_own = input->LONG_ACCELERATION;
    a_comm = a_own;
    a_req = a_own;
    v_own = input->LONG_VELOCITY;
    s_own = (distance_t)0;

    s_host = sim_object.AUTOSAR.LONG_DISPLACEMENT;

    /*host faster than target*/
    if (sim_object.AUTOSAR.REL_LONG_SPEED < Acc_vrel_estim_min) 
    {
      sim_time = (times_t)MAT_CALCULATE_PARAM_VALUE1D((const sint16*)Acc_alert_max_sim_time, (uint16)Acc_max_sim_time_points, v_own);
    }
    else 
    {
      sim_time = (times_t)0;
    }
    /*calculate discrete sim steps*/
    sim_steps = (uint8)MAT_DIV( ((sint32)sim_time + (Acc_alert_sim_time_step >> 1)), (sint32)Acc_alert_sim_time_step, Scale_1, Scale_1, Scale_1);

    if(sim_steps > Fct_acc_alert_max_sim_steps)
    {
      sim_steps = Fct_acc_alert_max_sim_steps;
    }

#if (CFG_FCT_ACC_TTS_CONTROLLER)
    /* object is indicated as "simulated" for TTS controller */
    sim_object.AUTOSAR.OBJECT_STATUS.MEASURED = FALSE;
#endif

    /* Start Simulation */
    for (index = 0u; (index < sim_steps) && (stop_sim == (uint8)FALSE); index++)
    {
      a_comm =  HP_t_DetermineDistControlAccel(&sim_object, input->DRIVER_CONTROLS.HEADWAY_SETTING, a_own);
      /*limit aown to allowed limits*/
      a_comm = (acceleration_t)MAT_LIM((sint32)a_comm, (sint32)sim_object.MAX_ALLOWED_DECEL, (sint32)sim_object.MAX_ALLOWED_ACCEL);

      /*limit change rate*/
      a_req = (acceleration_t)MAT_LIM_GRAD((sint32)a_comm, (sint32)a_req, (sint32)MAT_CALCULATE_PARAM_VALUE1D(Acc_max_neg_grad, Acc_neg_grad_points, v_own), (sint32)MAT_CALCULATE_PARAM_VALUE1D(Acc_max_pos_grad_neg_accel, Acc_pos_grad_neg_accel_points, v_own), Acc_alert_sim_time_step);

      /*use a simple vehicle model to filter a_own*/
      a_own = (acceleration_t)MAT_FILT((sint32)a_req, (sint32)a_own, ((sint32)Acc_alert_sim_vehicle_filter_time / Acc_alert_sim_time_step));

      /* Predict Path of host vehicle for the next step */
      help_var = (sint32)v_own * (sint32)Acc_alert_sim_time_step;
      help_var /= ((sint32)Time_s);
      help_var *= ((sint32)Distance_s);
      help_var /= ((sint32)Velocity_s);
      s_own = (distance_t)MAT_LIM(((sint32)s_own + help_var),(sint32)Distance_min,(sint32)Distance_max);
      help_var = (sint32)a_own * (sint32)Acc_alert_sim_time_step;
      help_var /= ( ((sint32)2) * ((sint32)Time_s) );
      help_var *= ((sint32)Acc_alert_sim_time_step);
      help_var /= ((sint32)Time_s);
      help_var *= ((sint32)Distance_s);
      help_var /= ((sint32)Acceleration_s);
      s_own = (distance_t)MAT_LIM(((sint32)s_own + help_var),(sint32)Distance_min,(sint32)Distance_max);

      /* Predict Speed of host vehicle for the next step */
      help_var = (sint32)a_own * (sint32)Acc_alert_sim_time_step;
      help_var /= ((sint32)Acceleration_s);
      help_var *= ((sint32)Velocity_s);
      help_var /= ((sint32)Time_s);
      v_own = (velocity_t)MAT_LIM(((sint32)v_own + help_var),(sint32)0,(sint32)Speed_max);

      /* Predict Distance of In path Object for the next step */
      help_var = (sint32)sim_object.LONG_SPEED * (sint32)Acc_alert_sim_time_step;
      help_var /= ((sint32)Time_s);
      help_var *= ((sint32)Distance_s);
      help_var /= ((sint32)Velocity_s);
      s_host = (distance_t)MAT_LIM(((sint32)s_host + help_var),(sint32)Distance_min,(sint32)Distance_max);
      help_var = (sint32)sim_object.LONG_ACCEL_MODIFIED * (sint32)Acc_alert_sim_time_step;
      help_var /= ( ((sint32)2) * ((sint32)Time_s) );
      help_var *= ((sint32)Acc_alert_sim_time_step);
      help_var /= ((sint32)Time_s);
      help_var *= ((sint32)Distance_s);
      help_var /= ((sint32)Acceleration_s);
      s_host = (distance_t)MAT_LIM(((sint32)s_host + help_var),(sint32)Distance_min,(sint32)Distance_max);
      sim_object.AUTOSAR.LONG_DISPLACEMENT = (distance_t)MAT_LIM(((sint32)s_host - (sint32)s_own),(sint32)Distance_min,(sint32)Distance_max);

      /* Predict Speed of In path Object for the next step */
      help_var = (sint32)sim_object.LONG_ACCEL_MODIFIED * (sint32)Acc_alert_sim_time_step;
      help_var /= ((sint32)Time_s);
      help_var *= ((sint32)Velocity_s);
      help_var /= ((sint32)Acceleration_s);
      sim_object.LONG_SPEED = (velocity_t)MAT_LIM(((sint32)sim_object.LONG_SPEED + help_var),(sint32)0,(sint32)Speed_max);

      /* Estimated RelativeSpeed is difference in ObjectSpeed and v_own */			
      sim_object.AUTOSAR.REL_LONG_SPEED = (velocity_t)(sim_object.LONG_SPEED - v_own);

      /*save values...*/
      if(
         (sim_object.AUTOSAR.LONG_DISPLACEMENT < (distance_t)MAT_CALCULATE_PARAM_VALUE1D(Acc_min_alert_thres, (uint16)Acc_min_alert_thres_points, v_own))
         && 
         (sim_object.AUTOSAR.REL_LONG_SPEED < Acc_vrel_estim_min)
         &&
         (was_below_alert_dist == (uint8)FALSE)
        )
      {
        /* Set flag that we were already below alert threshold */
        was_below_alert_dist = TRUE;
        /* Store the alert data */
        alert_data->ESTIM_DISTANCE = sim_object.AUTOSAR.LONG_DISPLACEMENT;
        alert_data->ESTIM_REL_SPEED = sim_object.AUTOSAR.REL_LONG_SPEED;
        alert_data->ESTIM_HOST_SPEED = v_own;
      }



      /* Stop simulation */
      if (
          (
           (sim_object.AUTOSAR.LONG_DISPLACEMENT <= (distance_t)0)
          )
          ||
          (sim_object.AUTOSAR.REL_LONG_SPEED >= (velocity_t)0)
          ||
          (v_own == (velocity_t)0)
         ) 
      {
        stop_sim = TRUE;
      }

      /*avoid s_host exceeding the upper limit*/
      if(s_host > s_own)
      {
        s_host  = (distance_t)(s_host - s_own);
        s_own = (distance_t)0;
      }
    }

    /*if estimated distance distance goes not below 0 - use saved values*/
    if((was_below_alert_dist != (uint8)TRUE) || (sim_object.AUTOSAR.LONG_DISPLACEMENT <= (distance_t)0))
    {
      alert_data->ESTIM_DISTANCE = sim_object.AUTOSAR.LONG_DISPLACEMENT;
      alert_data->ESTIM_REL_SPEED = sim_object.AUTOSAR.REL_LONG_SPEED;
      alert_data->ESTIM_HOST_SPEED = v_own;
    }
    else
    {
      /* Alert data already written in the simulation loop */
    }
  }
  else
  {
    alert_data->ESTIM_DISTANCE = Distance_max;

    alert_data->ESTIM_REL_SPEED = (velocity_t)0;

    alert_data->ESTIM_HOST_SPEED = (velocity_t)0;
  }

}

/*************************************************************************************************************************
  Functionname:    HP_v_DetermineAlertThreshold                                                                     */ /*!

  @brief           Determine the TimeGap-Threshold for Takeover

  @description     determins an alert distance threshold

          @startuml
					Start
						Partition HP_v_DetermineAlertThreshold {
							- Calculate temporary minimal and maximal alert distance based in 1D interpolation curves
              If (ACC is not active) then (true)
                - Alert factor is set to 0 in order to use minimal alert distance
              Else (false)
                If (Temporary maximal alert distance is greater than temporary minimal alert distance) then (true)
                  If (Estimated alert distance is greater or equals temporary maximal alert distance) then (true)
                    - Alert threshold factor is set to use maximal alert distance
                  Else (false)
                    If (Estimated alert distance is smaller or equals temporary minimal alert distance) then (true)
                      - Alert threshold factor is set to use minimal alert distance
                    Else (false)
                      - Alert threshold factor is calculated based on estimated alert distance and temporary minimal and maximal alert distance
                    Endif
                  Endif
                Else (false)
                  If (Estimated alert distance is greater than temporary maximal alert distance) then (true)
                    - Alert threshold factor is set to use maximal alert distance
                  Else (false)
                    - Alert threshold factor is set to use minimal alert distance
                  Endif
                Endif
              - Maximum calculation between old and new alert threshold factor
              Endif
              - Alert distance is calculated based on temporary maximal and minimal alert distance
						}
					End 
					@enduml

  @return          -

  @param[in,out]   alert_data : alert_data information about the previously calculated alert data [acc_alert_data_t as per acc_ext.h]
                      ESTIM_HOST_SPEED : [velocity_t as per Rte_Type.h]
                      ALERT_THRES_FACTOR : [factor_t as per Rte_Type.h]
                      ALERT_DISTANCE : [distance_t as per Rte_Type.h]
                      ESTIM_DISTANCE : [distance_t as per Rte_Type.h]
  @param[in]       input : ControlMode [acc_input_data_t as per acc_ext.h]
                      INPUT_STATUS.ACC_ON : [true, false]

  @glob_in         -
  @glob_out        -
                   
  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_HEADWAY_PLANNER : ACC function is enabled
  @c_switch_full   FCT_CFG_LOHP_COMPONENT : Configuration switch for enabling LOHP component
                   
  @pre             -
  @post            -
                   
  @created         -
  @changed         4/20/2016

  @author          -
*************************************************************************************************************************/
static void HP_v_DetermineAlertThreshold(acc_alert_data_t* alert_data, const acc_input_data_t* input)
{
  distance_t MinDist, MaxDist;
  MinDist = MAT_CALCULATE_PARAM_VALUE1D(Acc_min_alert_thres,(uint16)Acc_min_alert_thres_points,alert_data->ESTIM_HOST_SPEED);
  MaxDist = MAT_CALCULATE_PARAM_VALUE1D(Acc_max_alert_thres,(uint16)Acc_max_alert_thres_points,alert_data->ESTIM_HOST_SPEED);

  /* Min alert distance selected when ACC is active */
  if (input->INPUT_STATUS.ACC_NOT_OFF == FALSE)
  {
    /*set position between Acc_min_alert_thres curve and Acc_max_alert_thres curve to 0 (Acc_min_alert_thres)*/
    alert_data->ALERT_THRES_FACTOR = 0;
  }
  else
  {  
    factor_t NewFactor;       

    if (MaxDist > MinDist)
    {
      if(alert_data->ESTIM_DISTANCE >= MaxDist)
      {
        NewFactor = Factor_s;
      }
      else
      {
        if(alert_data->ESTIM_DISTANCE <= MinDist)
        {
          NewFactor = 0;
        }
        else
        {
          NewFactor = (factor_t)(((sint32)Factor_s * ((sint32)alert_data->ESTIM_DISTANCE - (sint32)MinDist)) / ((sint32)MaxDist - (sint32)MinDist));
        }
      }
    }
    else /* If max and min dist are the same */
    {
      if(alert_data->ESTIM_DISTANCE > MaxDist)
      {
        NewFactor = Factor_s;
      }
      else
      {
        NewFactor = 0;
      }
    }

    alert_data->ALERT_THRES_FACTOR = (factor_t)MAT_MAX((sint32)NewFactor, (sint32)alert_data->ALERT_THRES_FACTOR);
  }

  alert_data->ALERT_DISTANCE = (distance_t) (MinDist + (distance_t)((((sint32)MaxDist-(sint32)MinDist) * (sint32)alert_data->ALERT_THRES_FACTOR) / (sint32)Factor_s));
}

/*************************************************************************************************************************
  Functionname:    HP_v_AlertProcess                                                                                    */ /*!

  @brief           Determine ALERT_DATA

  @description     main function for acc alert

          @startuml
					Start
						Partition HP_v_AlertProcess {
							- Determine estimated alert distance
              - Determine alert distance threshold
              - Determine alert status
						}
					End 
					@enduml

  @return          -

  @param[in]       input : [acc_input_data_t as per acc_ext.h]
  @param[in]       alert_object : [acc_object_t as per Rte_Type.h]
  @param[in]       output : [acc_output_data_t as per Rte_Type.h]
  @param[in]       acc_alert_data : information about the previously calculated alert data [acc_alert_data_t as per acc_ext.h]
  @param[in]       cycle_time : [time_t as per Rte_Type.h]

  @glob_in         -
  @glob_out        -
                   
  @c_switch_part   -
  @c_switch_full   -
                   
  @pre             -
  @post            -
                   
  @created         -
  @changed         4/20/2016
  @traceability    doors://rbgs854a:40000/?version=2&prodID=0&view=00000002&urn=urn:telelogic::1-503e822e5ec3651e-O-96-0008a201

  @author          -
*************************************************************************************************************************/
void HP_v_AlertProcess(const acc_input_data_t* input, const acc_object_t* alert_object, acc_output_data_t* output, acc_alert_data_t *acc_alert_data, times_t cycle_time)
{
  HP_v_DetermineEstimatedDistance(acc_alert_data, alert_object, input);

  HP_v_DetermineAlertThreshold(acc_alert_data, input);

  HP_v_DetermineAlert(acc_alert_data, alert_object, output, cycle_time, input);
}


/*************************************************************************************************************************
  Functionname:    HP_v_AlertInit                                                                                    */ /*!

  @brief           Initialize ALERT_DATA

  @description     Initialize ALERT_DATA

          @startuml
					Start
						Partition HP_v_AlertInit {
							- Initialize estimated alert relative speed to a neutral value
              - Initialize estimated alert distance to a neutral value
              - Initialize estimated host speed to a neutral value
              - Initialize alert threshold factor to a neutral value
              - Initialize alert distance to a neutral value
              - Initialize alert suppression time to a neutral value
              - Initialize alert alert output timer to a neutral value
						}
					End 
					@enduml

  @return          -

  @param[out]      acc_alert_data : [acc_alert_data_t as per acc_ext.h]
                      ESTIM_REL_SPEED  : [velocity_t as per Rte_Type.h]
                      ESTIM_DISTANCE : [distance_t as per Rte_Type.h]
                      ESTIM_HOST_SPEED  : [velocity_t as per Rte_Type.h]
                      ALERT_THRES_FACTOR : [factor_t as per Rte_Type.h]
                      ALERT_DISTANCE : [distance_t as per Rte_Type.h]
                      ALERT_SUPRESS_TIME : [time_t as per Rte_Type.h]

  @glob_in         -
  @glob_out        AccAlertOutputTimer : [time_t as per Rte_Type.h]
                   
  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_HEADWAY_PLANNER : ACC function is enabled
  @c_switch_full   FCT_CFG_LOHP_COMPONENT : Configuration switch for enabling LOHP component
                   
  @pre             -
  @post            -
                   
  @created         -
  @changed         4/20/2016
  @traceability    doors://rbgs854a:40000/?version=2&prodID=0&view=00000002&urn=urn:telelogic::1-503e822e5ec3651e-O-95-0008a201

  @author          -
*************************************************************************************************************************/
void HP_v_AlertInit(acc_alert_data_t *acc_alert_data)
{
  acc_alert_data->ESTIM_REL_SPEED = (velocity_t)0;
  acc_alert_data->ESTIM_DISTANCE = (distance_t)0;
  acc_alert_data->ESTIM_HOST_SPEED = (velocity_t)0;  
  acc_alert_data->ALERT_THRES_FACTOR = (factor_t)Factor_s;
  acc_alert_data->ALERT_DISTANCE = (distance_t)0;
  acc_alert_data->ALERT_SUPRESS_TIME = Acc_alert_sim_vehicle_filter_time;

  AccAlertOutputTimer = (times_t)0;
}

#endif  /* (FCT_CFG_LOHP_COMPONENT) && (FCT_CFG_ACC_HEADWAY_PLANNER) */

/** @} end defgroup */
