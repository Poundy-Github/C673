/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC/LOHP/HP (Adaptive Cruise Control - Longitudinal Headway Planner - Headway Planner)

PACKAGENAME:               hp_tsc.c

DESCRIPTION:               This file contains all functions concerning the
                           traffic situation classification needed for HP

AUTHOR:                    Mistry Niraj (uidq5738)

CREATION DATE:             24.02.2017

VERSION:                   $Revision: 1.16 $

LEGACY VERSION:            Revision: 1.23.1.3

**************************************************************************** */

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/** 
@defgroup   hp_tsc Hp_tsc
@ingroup    hp
@brief      File contains functions concerning traffic situation classification for HP
@{ */ 

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "hp.h"


#if ((FCT_CFG_LOHP_COMPONENT) && (FCT_CFG_ACC_HEADWAY_PLANNER))

static confidence_t HP_t_EstimateControlCriticality(acc_object_t object_list[Acc_max_number_ooi], acc_output_data_t* output);
static void HP_v_EstimateCriticality(const times_t cycle_time, acc_object_t object_list[Acc_max_number_ooi], acc_output_data_t* output);

/*************************************************************************************************************************
  Functionname:    HP_t_EstimateControlCriticality                                                                  */ /*!

  @brief           Estimates the criticality of the relevant object

  @description     Estimates the criticality of the relevant object focused on longitudinal control usage: 
                   Three individual criticality indicators are determined and fused.
                      - Criticality based on relevant object deceleration
                      - Criticality based on relevant object distance
                      - Criticality based on TTC
                      - Calculate combined criticality between 0 and 100 % (100% means very critical)

				   @startuml
					Start
					Partition HP_t_EstimateControlCriticality(){
					: Estimates the Criticality of the relevant object focused on Longitudinal Control Usage;
					: Criticality of the relevant object is done by using;
					: Criticality based on relevant object deceleration, Distance\n, TTC;
					: Calculate Combined criticality between 0 and 100%(high criticality);
					: Calculate Time to collision based on the difference between\n Object Velocity, Acceleration, Relative speed,\n Ego Acceleration and Displacement;
					: Calculate Criticality object deceleration by using Acc\n Criticality Factor corresponding to the Object Acceleration;
					: Apply scaling factor for different headway settings (long, middle, short);
					: Limiting the Criticality of Object deceleration from 0 – 1000;
					If (Object Distance is less than Requested Distance\n and Max Intrusion Distance less than Requested Distance) Then (True)
						 If (Object Distance is greater than Maximum Intrusion\n Distance) Then (True)
						 : Criticality Distance is calculated by using Difference between \ncurrent Object distance and the Requested Maximum Intrusion Distance;
							  If (difference between Requested Distance and\n the Requested Maximum Intrusion Distance is not equal to 0) Then (True)
							  : Criticality distance is divided by the difference\n between Requested distance and the Requested maximum intrusion Distance;
							   endif
						else (false)
							  : Distance closer than intrusion assigned to maximum\n distance criticality;
						endif
					Else (false)
					  : Distance longer than requested distance assigned\n to zero (no distance criticality);
					Endif
					 If (Object Relative Longitudinal Velocity is less than 0)\n Then (True)
						: Simple TTC is calculated from Distance and relative Speed;
						: Time To Collision is limited from 0 to 10secs;
					 Else (false)
						: TTC is equal to 10 secs;
					 Endif
					: Calculate Criticality based on TTC;
					: Calculate Combined Criticality;
					If (TTC is less than the factor 10secs) Then (True)
					: Combined Criticality is calculated based on the mean value\n of Object deceleration and Criticality TTC;
						If (Criticality Distance,\n Criticality Object deceleration and Criticality TTC are greater than 0) Then (True)
						: Combined Criticality is multiplied with the factor\n (1000) and Criticality Distance;
						Endif
					Endif
					:Combined criticality is limited to 0 – 100%;
					:Adapt to confidence scale of 0 to 255;
					}
					End
				   @enduml

	
  @return          criticality_control : criticality on this object [full range of datatype confidence_t as in Rte_Type.h]

  @param[in]       object_list : ACC object list of [0u ... Acc_max_number_ooi] with Acc_max_number_ooi in acc_ext.h
                        LONG_SPEED : Object speed [Full range of datatype velocity_t as in Rte_type.h]
                        LONG_ACCEL : Object acceleration [Full range of datatype acceleration_t as in Rte_type.h]
                        AUTOSAR.REL_LONG_SPEED : Object relative speed [Full range of datatype velocity_t as in Rte_type.h]
                        AUTOSAR.LONG_DISPLACEMENT : Object distance [Full range of datatype distance_t as in Rte_type.h]
  @param[in,out]   output : ACC output structure
                        HEADWAY_SETTING : ACC distance setting [0u ... 100u] %
                        REQUESTED_DISTANCE : ACC control distance [Full range of datatype distance_t as in Rte_type.h]
                        REQUESTED_MAX_INTRUSION : ACC minimum undershooting distance [Full range of datatype distance_t as in Rte_type.h]

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_LOHP_COMPONENT : Configuration switch for enabling LOHP component
  @c_switch_full   FCT_CFG_ACC_HEADWAY_PLANNER : Configuration switch to enable ACC functionality

  @pre             -
  @post            -

  @created         -
  @changed         17.03.2016

  @author          Jens Both | jens.both@continental-corporation.com | +49 (8382) 9699-757
*************************************************************************************************************************/
static confidence_t HP_t_EstimateControlCriticality(acc_object_t object_list[Acc_max_number_ooi], acc_output_data_t* output)
{
  uint32       criticality_control, criticality_dist, criticality_obj_decel, criticality_ttc;
  velocity_t   impact_velocity;
  acc_object_t *object;
  uint32       ttc;

  criticality_control = 0u;
  criticality_ttc = 0u;
  criticality_dist = 0u;
  criticality_obj_decel = 0u;

  /* Use only OOI 0 */
  object = &(object_list[0]);

  /* Calculate TTC with a_rel */
  ttc = (uint32)MAT_MIN((sint32)PHYS_CALCULATE_TTC(object->LONG_SPEED, object->LONG_ACCEL, (velocity_t)((sint32)object->LONG_SPEED - (sint32)object->AUTOSAR.REL_LONG_SPEED), (acceleration_t)((sint32)object->LONG_ACCEL - (sint32)object->AUTOSAR.REL_LONG_ACCEL), object->AUTOSAR.LONG_DISPLACEMENT, &impact_velocity), (sint32)Acc_si_criticality_from_ttc[2*(Acc_si_crit_from_ttc_points-1)]);
  object->TTC = (times_t)(ttc);

  /*****************************************************/
  /* Criticality based on relevant object deceleration */
  /*****************************************************/

  criticality_obj_decel = (uint32)(MAT_CALCULATE_PARAM_VALUE1D(Acc_si_crit_factor_obj_accel, Acc_si_crit_factor_obj_accel_points, (sint16)object->LONG_ACCEL));

  /* Apply scaling factor for different headway settings (long, middle, short) */
  criticality_obj_decel =  (uint32)MAT_MUL((sint32)criticality_obj_decel,
                                           (sint32)MAT_CALCULATE_PARAM_VALUE1D(Acc_si_criticality_headway_factor, Acc_si_criticality_headway_factor_points, (sint16)output->HEADWAY_SETTING),
                                           Factor_s,Factor_s,Factor_s);
  criticality_obj_decel  = (uint32)MAT_LIM((sint32)criticality_obj_decel,0,Factor_s);


  /*************************************************/
  /* Criticality based on relevant object distance */
  /*************************************************/

  if ((object->AUTOSAR.LONG_DISPLACEMENT <= output->REQUESTED_DISTANCE)
     && 
     (output->REQUESTED_MAX_INTRUSION < output->REQUESTED_DISTANCE))
  {
    if(object->AUTOSAR.LONG_DISPLACEMENT >= output->REQUESTED_MAX_INTRUSION)
    {
      criticality_dist = (uint32)(Factor_s*(object->AUTOSAR.LONG_DISPLACEMENT - output->REQUESTED_MAX_INTRUSION));
      if ((output->REQUESTED_DISTANCE - output->REQUESTED_MAX_INTRUSION) != 0) /* div by 0 check ! */
      {
        criticality_dist /= (uint32)((output->REQUESTED_DISTANCE - output->REQUESTED_MAX_INTRUSION));
        criticality_dist = Factor_s-(uint32)(MAT_LIM((sint32)criticality_dist,0,Factor_s));
      }
    }
    else
    {
      /* distance closer than intrusion => max distance criticality */
      criticality_dist = (uint32)Factor_s;
    }
  }
  else
  {
    /* distance longer than requested distance => no distance criticality */
    criticality_dist = 0u;
  }

  /****************************/
  /* Criticality based on TTC */
  /****************************/

  if (object->AUTOSAR.REL_LONG_SPEED < 0)
  {
    /* simple ttc estimation without a_rel */
    ttc = (uint32)(object->AUTOSAR.LONG_DISPLACEMENT *Factor_s / MAT_ABS((sint32)object->AUTOSAR.REL_LONG_SPEED));
    ttc = (uint32)(MAT_LIM((sint32)ttc,0,Scale_10000));
  }
  else
  {
   ttc = (uint32)Scale_10000; /* 10 sec (default value) */
  }

  if ((ttc < object->TTC))
  {
    /* object->TTC calculated with a_rel -> not usefull if a_rel->0 */
    object->TTC = (times_t)(ttc);
  }

  criticality_ttc = (uint32)MAT_CALCULATE_PARAM_VALUE1D(Acc_si_criticality_from_ttc, (uint16)Acc_si_crit_from_ttc_points, (sint16)object->TTC);

  /**********************************/
  /* Calculate combined criticality */
  /**********************************/

  if (object->TTC < Scale_10000)
  {
    /* Mean value of obj_decel and ttc criticality*/
    criticality_control = (criticality_obj_decel+criticality_ttc)/2;

    /* Distance criticality can amplify the overall criticality */
    if ((criticality_dist > 0) && (criticality_obj_decel > 0) && (criticality_ttc > 0))
    {
      criticality_control *= (Factor_s + criticality_dist);
      criticality_control /= Factor_s;
    }
  }

  /* Limit criticality result 0..100% */
  criticality_control = (uint32)MAT_LIM((sint32)criticality_control,0,Factor_s);

  /* Adapt to confidence scale 0..255 */
  criticality_control = criticality_control*Confidence_s/Scale_1000;
  
  return (confidence_t)(criticality_control);
}

/*************************************************************************************************************************
  Functionname:    HP_v_EstimateCriticality                                                                         */ /*!

  @brief           Estimates the criticality of the whole situation

  @description     Estimates the criticality of the whole situation. Based on the configuration switch. The criticality is 
                   determined either for the relevant object only or loops over the six OOI's.
                   Output: The calculated criticality for the traffic situation (gradient limited)

				   @startuml
					Start
					Partition HP_v_EstimateCriticality(){
					: Estimates the criticality of the whole traffic situation;
					: The criticality is determined for OOI- 0;
					: Traffic Situation Criticality is limited between the Positive and negative criticality gradient Limits;
					}
					End
				   @enduml

  @return          -

  @param[in]       cycle_time : Task cycle time [Full range of datatype times_t as in Rte_type.h]
  @param[in]       object_list : ACC object list of [0u ... Acc_max_number_ooi] with Acc_max_number_ooi in acc_ext.h
  @param[in,out]   output : ACC output structures
                        SITUATION_CLASS.CRITICALITY : Criticality of the situation

  @glob_in         -
  @glob_out        -

  @c_switch_full   FCT_CFG_LOHP_COMPONENT : Configuration switch for enabling LOHP component
  @c_switch_full   FCT_CFG_ACC_HEADWAY_PLANNER : Configuration switch to enable ACC functionality

  @pre             -
  @post            -

  @created         -
  @changed         18.03.2016

  @author          Jens Both | jens.both@continental-corporation.com | +49 (8382) 9699-757
*************************************************************************************************************************/
static void HP_v_EstimateCriticality(const times_t cycle_time, acc_object_t object_list[Acc_max_number_ooi], acc_output_data_t* output)
{
  confidence_t max_criticality;

  /* Calculate object criticality focused on longitudinal control usage */
  max_criticality = HP_t_EstimateControlCriticality(object_list, output);

  /* Write output with applied gradient limit */
  output->SITUATION_CLASS.CRITICALITY = (confidence_t)MAT_LIM_GRAD((sint32)max_criticality, (sint32)output->SITUATION_CLASS.CRITICALITY, Acc_si_crit_neg_grad, Acc_si_crit_pos_grad, cycle_time);
}

/*************************************************************************************************************************
  Functionname:    HP_v_EstimateTrafficSituation                                                                    */ /*!

  @brief           Estimates the current traffic situation: stop, go,... including criticality

  @description     Estimates the current traffic situation: stop, go, overtake, crawl, free, follow (including criticality)
                   Situation interpretation focused on longitudinal control usage(e.g. Stop & Go handling, free/follow mode):
                   Based on current acceleration request, ego/object velocity and acceleration, motion state, lane change probability

				   @startuml
					Start
					  Partition HP_v_EstimateTrafficSituation {
					  If(Control object is not detected) then(Yes)
						-Current traffic situation set to FREE_MODE
					   Else (No)
						If(Longitudinal ego velocity is greater\n than Acc crawl velocity)then (Yes)
						  -Current traffic situation set to acc FOLLOW_MODE
						Else (No)
						  If(Object velocity is greater than\n Acc crawl velocity)then (Yes)
							-Current traffic situation set to acc FOLLOW_MODE
						  Else(No)
							If(Last cycle traffic situation \nclass was not stop class)then(Yes)
							  -Current traffic situation set to acc CRAWL_MODE
							Else(No)
								If(Object Control acceleration is greater\n than Acc min obj crawl accel)then(Yes)
								  -Traffic situation set to CRAWL_MODE
								Else(No)
								  -Traffic situation set to STOP_MODE	
								Endif	 
							Endif				
						  Endif 
						 Endif 
						-Calculate time to get the target to a full stop
						If(Object control accel is less than Acc min stop accel)then(Yes)
						  If(Check dynamic properties for stop, standing conditions \n and last cycle was stop mode)then(Yes)
							-Current traffic situation set to STOP_MODE
						  Else(No)
							If(Time to stop is less than min Acc_si_min_hys_time_to_stop and \n Object distance is <= max stop distance)then(Yes)
							  -Current traffic situation set to STOP_MODE	
							Else(No) 
							  If(time to stop is less than Acc_si_max_time_to_stop_2obj and\n hidden object is stopped)then(Yes)
								-Current traffic situation set to STOP_MODE	
							  Endif 
							Endif 
						  Endif 				
						Else(No)
						  -Stay in crawl mode
						Endif
						If(Standstill flag set and control accel is less than min stop accel \n and ego velocity is less than Acc_stopped_speed)then(Yes)
							-Current traffic situation set to STOP_MODE
						Else
							-Stay in crawl mode  
						Endif 
						If(Traffic situation is set to crawl mode)then(Yes)
						  If(Control object velocity is greater than ego velocity)then(Yes)
	  						If(Object accel is greater than min go accel)then(Yes)
								-Current traffic situation set to GO_MODE
							Else (No)
								If(Object accel is greater than Acc_si_min_go_accel_2obj\n and Hidden object intrest flag set and its accel greater than  Acc_si_min_go_accel_2obj)then(Yes)
		 						  -Current traffic situation set to GO_MODE
								Endif 
	  						Endif 
  						  Endif 		
						Endif	
					  Endif
					  If(Ego lane change is detected and driver override ON or\n e_OTState is set to passby)(Yes)
						-Current traffic situation set to OVERTAKE_MODE
					  Endif 
					  -Estimates the criticality of the whole situation
					  }	
					End 
					@enduml

  @return          void

  @param[in]       cycle_time : Task cycle time [Full range of datatype times_t as in Rte_type.h]
  @param[in]       object_list : ACC object list of [0u ... Acc_max_number_ooi] with Acc_max_number_ooi in acc_ext.h
                        USAGE_STATUS.INTEREST : Flag for selected object [TRUE,FALSE]
                        LONG_ACCEL_MODIFIED : Object acceleration [Full range of datatype acceleration_t as in Rte_type.h]
                        AUTOSAR.OBJECT_STATUS.STOPPED : Object stopped (seen moving) [TRUE,FALSE]
  @param[in]       input : ACC input interface (vehicle related data)
                        LONG_VELOCITY : Longitudinal velocity of the host vehicle [Full range of datatype velocity_t as in Rte_type.h]
                        INPUT_STATUS.OBJECT_EFFECTIVE : The object is effective for control [TRUE,FALSE]
                        LODM_STAT.OVERRIDE_ACCEL : Driver override of accelerator pedal [TRUE,FALSE]
                        LODM_STAT.STANDSTILL : Ego vehicle in stand still [TRUE,FALSE]

  @param[in,out]   status: ACC internal status data struct
                        ACC_CONTROL_OBJECT.AUTOSAR.OBJECT_STATUS.DETECTED : Flag for object detection [TRUE,FALSE]
                        ACC_CONTROL_OBJECT.LONG_SPEED : Object speed [Full range of datatype velocity_t as in Rte_type.h]
                        ACC_CONTROL_OBJECT.CONTROL_ACCEL : Needed acceleration/deceleration to maintain requested distance to the object  [Full range of datatype acceleration_t as in Rte_type.h]
                        ACC_CONTROL_OBJECT.LONG_ACCEL_MODIFIED : Object acceleration [Full range of datatype acceleration_t as in Rte_type.h]
                        ACC_CONTROL_OBJECT.AUTOSAR.OBJECT_STATUS.STOPPED : Object stopped (seen moving) [TRUE,FALSE]
                        ACC_CONTROL_OBJECT.AUTOSAR.OBJECT_STATUS.STANDING : Object standing (never seen moving) [TRUE,FALSE]
                        ACC_CONTROL_OBJECT.AUTOSAR.LONG_DISPLACEMENT : Object distance [Full range of datatype distance_t as in Rte_type.h]

  @param[in,out]   output : ACC output structure (SEN to VEH)
                        SITUATION_CLASS.SITUATION : Classifier of the current traffic situation

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_LOHP_COMPONENT : Configuration switch for enabling LOHP component
  @c_switch_full   FCT_CFG_ACC_HEADWAY_PLANNER : Configuration switch to enable ACC functionality

  @pre             ACC_READ_OBJECTS
  @post            -

  @created         -
  @changed         18.03.2016

  @traceability    doors://rbgs854a:40000/?version=2&prodID=0&view=00000002&urn=urn:telelogic::1-503e822e5ec3651e-O-93-0008a201

  @author          Jens Both | jens.both@continental-corporation.com | +49 (8382) 9699-757
*************************************************************************************************************************/
void HP_v_EstimateTrafficSituation(const times_t cycle_time, acc_object_t object_list[Acc_max_number_ooi], const acc_input_data_t* input, acc_status_t* status, acc_output_data_t* output)
{
  sint32                time_to_stop;
  acc_situation_class_t situation_class_last_cycle;
  acc_object_t Control_Object;

  situation_class_last_cycle = output->SITUATION_CLASS.SITUATION;
  output->SITUATION_CLASS.SITUATION = Acc_sit_class_undefined;
  /* Local variable from input pointer */
  Control_Object = status->ACC_CONTROL_OBJECT;

  if(
     (Control_Object.AUTOSAR.OBJECT_STATUS.DETECTED == FALSE)
      ||
     (input->INPUT_STATUS.OBJECT_EFFECTIVE == FALSE)
    )
  {
    output->SITUATION_CLASS.SITUATION = Acc_sit_class_freemode;
  }
  else
  {
    /*effective object available*/
    if(input->LONG_VELOCITY > Acc_crawl_max_velocity)
    {
      output->SITUATION_CLASS.SITUATION = Acc_sit_class_follow;
    }
    else
    {
      if(Control_Object.LONG_SPEED > Acc_crawl_max_velocity)
      {
        output->SITUATION_CLASS.SITUATION = Acc_sit_class_follow;
      }
      else
      {
        /*situation can be "crawl" only if both, the target and the host are slower than Acc_si_crawl_max_speed*/
        if(situation_class_last_cycle != Acc_sit_class_stop)
        {
          output->SITUATION_CLASS.SITUATION = Acc_sit_class_crawl;
        }
        else
        {
          if(Control_Object.CONTROL_ACCEL > Acc_min_obj_crawl_accel)
          {
            /* go from stopped in crawl with hysteresis (Acc_min_obj_crawl_accel-Acc_min_obj_stop_accel) */
            output->SITUATION_CLASS.SITUATION = Acc_sit_class_crawl;
          }
          else
          {
            /* Keep situation stop with hysteresis (Acc_min_obj_crawl_accel-Acc_min_obj_stop_accel) */
            output->SITUATION_CLASS.SITUATION = Acc_sit_class_stop;
          }
        }
      }
    }

    /*calculate time to get the target to a full stop*/
    time_to_stop =  (sint32)HP_t_DetermineTimeToStop(Control_Object.LONG_ACCEL_MODIFIED, Control_Object.LONG_SPEED);

    /* test for Stop situation*/
    if(status->ACC_CONTROL_OBJECT.CONTROL_ACCEL < Acc_min_obj_stop_accel)
    {
      if(
          (situation_class_last_cycle == Acc_sit_class_stop)
          && 
          (
            (time_to_stop < (sint32)Acc_si_max_hys_time_to_stop) 
            ||
            /* Additional check of EM dynamic property to keep the "Acc_sit_class_stop" more stable */
            ((Control_Object.AUTOSAR.OBJECT_STATUS.STOPPED == TRUE) || (Control_Object.AUTOSAR.OBJECT_STATUS.STANDING == TRUE))
          )
        )
      {
        output->SITUATION_CLASS.SITUATION = Acc_sit_class_stop;
      }
      else
      {
        if (
            (time_to_stop < (sint32)Acc_si_min_hys_time_to_stop) 
            &&
            (Control_Object.AUTOSAR.LONG_DISPLACEMENT <= (distance_t)Acc_max_stop_distance)
           )
        {
          output->SITUATION_CLASS.SITUATION = Acc_sit_class_stop;
        }
        else
        {
          if(
             (time_to_stop < (sint32)Acc_si_max_time_to_stop_2obj)
             &&
             (object_list[Obj_hidden_host_lane].USAGE_STATUS.INTEREST == TRUE)
             &&
             (object_list[Obj_hidden_host_lane].AUTOSAR.OBJECT_STATUS.STOPPED == TRUE)
            )
          {
            output->SITUATION_CLASS.SITUATION = Acc_sit_class_stop;
          }
        }
      }
    }
    else
    {
      /*stay in crawl*/
    }

    if (
        (Control_Object.CONTROL_ACCEL < Acc_min_obj_stop_accel)
        && 
        (input->LODM_STAT.STANDSTILL == TRUE)
        &&
        /* check ego velocity in case standstill flag is released too late (prevent brake hold reaction during drive away) */
        (input->LONG_VELOCITY < Acc_stopped_speed)
       )
    {
      output->SITUATION_CLASS.SITUATION = Acc_sit_class_stop;
    }
    else 
    {
      /*stay in crawl*/
    }


    /* test if GO situation is active*/
    if(output->SITUATION_CLASS.SITUATION == Acc_sit_class_crawl)
    {
      if(Control_Object.LONG_SPEED > input->LONG_VELOCITY)
      {
        if(Control_Object.LONG_ACCEL_MODIFIED > Acc_si_min_go_accel)
        {
          output->SITUATION_CLASS.SITUATION = Acc_sit_class_go;
        }
        else
        {
          if(
             (Control_Object.LONG_ACCEL_MODIFIED > Acc_si_min_go_accel_2obj)
             &&
             (object_list[Obj_hidden_host_lane].USAGE_STATUS.INTEREST == TRUE)
             &&
             (object_list[Obj_hidden_host_lane].LONG_ACCEL_MODIFIED > Acc_si_min_go_accel_2obj)
            )
          {
            output->SITUATION_CLASS.SITUATION = Acc_sit_class_go;
          }
        }
      }
    }
  }

  /*overtake situation*/
  if(input->LODM_STAT.OVERRIDE_ACCEL == TRUE)
  {
    if(input->DRIVER_CONTROLS.e_LCPhase == LANECHANGE_ON)
    {
      output->SITUATION_CLASS.SITUATION = Acc_sit_class_overtake;
    }
  }
#if (HP_CFG_OVERTAKE_SUPPORT_FEATURE)
  if(status->ACC_OVERTAKE_DATA.e_OTState == OVERTAKE_PASSBY)
  {
    output->SITUATION_CLASS.SITUATION = Acc_sit_class_overtake;
  }
#endif

  HP_v_EstimateCriticality(cycle_time, object_list, output);
}


#endif /* (FCT_CFG_LOHP_COMPONENT) && (FCT_CFG_ACC_HEADWAY_PLANNER) */

/** @} end defgroup */
