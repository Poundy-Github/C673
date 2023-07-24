/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC/LOHP/DM (Adaptive Cruise Control - Longitudinal Headway Planner - Driver Monitoring)

PACKAGENAME:               dm_main.c

DESCRIPTION:               This file contains the sequencing and the main 
                           function for Distance Monitoring functionality

AUTHOR:                    Mistry Niraj (uidq5738)

CREATION DATE:             24.02.2017

VERSION:                   $Revision: 1.5 $

LEGACY VERSION:            Revision: 1.8.1.2

**************************************************************************** */

#include "dm.h"

#if ((FCT_CFG_LOHP_COMPONENT) && (FCT_CFG_DM))

/* ***********************************************************************
  @fn               DM_v_Process */ /*!

  @brief            Determine operating sequence for Distance Monitoring function

  @description      Determine operating sequence for Distance Monitoring function

  @param[in]        cycle_time,
  @param[in]        input
  @param[in]        output
  @param[in]        object
  @param[in]        dm_status

  @return           void

  @pre              Precondition:  none

  @post             Postcondition: none
**************************************************************************** */
void DM_v_Process(const times_t cycle_time,
             const dm_input_data_t* input,
             dm_output_data_t* output,
             const acc_object_t* object,
             dm_status_t *dm_status)
{

  DM_v_DetermineAlertState(input, output);

  DM_v_DetermineAlert(cycle_time, input, output, object, dm_status);
}

/* ***********************************************************************
  @fn               DM_v_Init */ /*!

  @brief            initialize module data

  @description      initialize module data

  @param[out]       dm_status

  @return           void

  @pre              Precondition:  none

  @post             Postcondition: none
**************************************************************************** */
void DM_v_Init(dm_status_t *dm_status)
{
  dm_status->DM_ESTIMATED_TIMEGAP = Dm_timegap_huge;
}

/*************************************************************************************************************************
  Functionname:    DM_v_OutInit                                                                                      */ /*!

  @brief           initialize dm output data to neutral values

  @description     initialize dm output data to neutral values

  @return          -

  @param[out]      *dm_output_data : 
  @param[out]      dm_output_data->DM_ALERT_LEVEL : [0, 4]
  @param[out]      dm_output_data->DM_STATE       : [0, 2]

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_DM : DM module is active or not
  @c_switch_full   FCT_CFG_LOHP_COMPONENT : Configuration switch for enabling LOHP component

  @pre             -
  @post            -

  @created         -
  @changed         4/20/2016

  @author          -
*************************************************************************************************************************/
void DM_v_OutInit(dm_output_data_t *dm_output_data)
{
  dm_output_data->DM_ALERT_LEVEL = Display_alert_level0;
  dm_output_data->DM_STATE = Dm_off;
}


#endif  /* (FCT_CFG_LOHP_COMPONENT) && (FCT_CFG_DM) */
