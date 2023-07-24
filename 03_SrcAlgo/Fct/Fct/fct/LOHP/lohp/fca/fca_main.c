/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC/LOHP/FCA (Adaptive Cruise Control - Longitudinal Headway Planner - Forward Collision Alert)

PACKAGENAME:               fca_main.c

DESCRIPTION:               This file contains sequence control and the main function for FCA functionality

AUTHOR:                    Mistry Niraj (uidq5738)

CREATION DATE:             24.02.2017

VERSION:                   $Revision: 1.5 $

LEGACY VERSION:            Revision: 1.8.1.2

**************************************************************************** */

#include "fca.h"

#if ((FCT_CFG_LOHP_COMPONENT) && (FCT_CFG_FCA))


/*************************************************************************************************************************
  Functionname:    FCA_v_OutInit                                                                                    */ /*!

  @brief           initialize fca output data to neutral values

  @description     initialize fca output data to neutral values

  @return          -

  @param[out]      *fca_output_data : 
  @param[out]      fca_output_data->FCA_STATE [0, 2]
  @param[out]      fca_output_data->FCA_STATUS.FCA_ALERT [true, false]
  @param[out]      fca_output_data->NEEDED_ACCEL [acceleration_t as per Rte_Type.h]

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_LOHP_COMPONENT : Configuration switch for enabling LOHP component
  @c_switch_full   FCT_CFG_FCA : Configuration switch for enabling FCT_FCA processing

  @pre             -
  @post            -
  
  @created         -
  @changed         4/20/2016

  @author          -
*************************************************************************************************************************/
void FCA_v_OutInit(fca_output_data_t *fca_output_data)
{
  fca_output_data->FCA_STATE = Fca_status_off;
  fca_output_data->FCA_STATUS.FCA_ALERT = FALSE;
#if (FCT_CFG_ACC_HEADWAY_PLANNER)
  fca_output_data->NEEDED_ACCEL = Acc_max_allowed_accel;
#else
  /* No ACC functionality, thus define Acc_max_allowed_accel not
  available. In this special case take hard-coded acceleration */
  fca_output_data->NEEDED_ACCEL = 4000;
#endif
}

/*************************************************************************************************************************
  @fn               FCA_v_Process                                                                                   */ /*!

  @brief            Determine operating sequence for Forward Collision Alert function

  @description      Determine operating sequence for Forward Collision Alert function

  @param[in]        cycle_time
  @param[in]        input_data
  @param[in]        output_data
  @param[in]        Object

  @return           --

  @pre              Precondition:  none

  @post             Postcondition: none
*************************************************************************************************************************/
void FCA_v_Process(const times_t cycle_time, const fca_input_data_t* input_data, fca_output_data_t* output_data, const acc_object_t* Object)
{
  times_t ReactionTime;

  cycle_time;

  if (input_data->BRAKE_STATUS.PEDAL_INIT_TRAVEL == TRUE)
  {
    ReactionTime = Fca_t_reaction_brake;
  }
  else
  {
    ReactionTime = Fca_t_reaction;
  }

  FCA_v_DetermineAlertState(input_data, output_data);

  output_data->NEEDED_ACCEL = PHYS_CALC_NEEDED_DECEL(input_data->LONG_ACCELERATION, input_data->LONG_VELOCITY, ReactionTime, Object->AUTOSAR.REL_LONG_SPEED, Object->AUTOSAR.REL_LONG_ACCEL, Object->LONG_SPEED, Object->LONG_ACCEL, Object->AUTOSAR.LONG_DISPLACEMENT);

  FCA_v_DetermineAlert(output_data, &Object->AUTOSAR);
}


#endif /* (FCT_CFG_LOHP_COMPONENT) && (FCT_CFG_FCA) */

