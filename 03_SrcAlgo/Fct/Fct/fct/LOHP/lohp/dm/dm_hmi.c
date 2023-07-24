/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC/LOHP/DM (Adaptive Cruise Control - Longitudinal Headway Planner - Driver Monitoring)

PACKAGENAME:               dm_hmi.c

DESCRIPTION:               This file contains the HMI (Human machine interface) 
                           for Distance Monitoring functionality

AUTHOR:                    Mistry Niraj (uidq5738)

CREATION DATE:             24.02.2017

VERSION:                   $Revision: 1.3 $

LEGACY VERSION:            Revision: 1.8

**************************************************************************** */

#include "dm.h"

#if ((FCT_CFG_LOHP_COMPONENT) && (FCT_CFG_DM))

/* ***********************************************************************
  @fn               DM_v_DetermineAlertState */ /*!

  @brief            Determine whether or not an alert shall be issued

  @description      Determine whether or not an alert shall be issued

  @param[in,out]    input
  @param[in,out]    output

  @return           void

  @pre              Precondition:  none

  @post             Postcondition: none
**************************************************************************** */
void DM_v_DetermineAlertState(const dm_input_data_t* input, dm_output_data_t* output)
{

  if (
      (input->CONTROL.DM_ON == FALSE)
      ||
      (input->CONTROL.INHIBIT == TRUE)
    ) {
  
    output->DM_STATE = Dm_off;
  }
  else {

    if (output->DM_STATE == Dm_on_active) {

      if (
          (input->SPEEDO_SPEED <= (Dm_v_min_dm_alert - Dm_v_min_hysteresis))
          ||
          (input->SPEEDO_SPEED >= Dm_v_max_dm_alert)
        ) {
    
        output->DM_STATE = Dm_on_inactive;
      }
    }
    else {

      /* state is Off or OnInactive */
      if (
          (input->SPEEDO_SPEED >= Dm_v_min_dm_alert)
          &&
          (input->SPEEDO_SPEED <= (Dm_v_max_dm_alert - Dm_v_min_hysteresis))
        ) 
      {    
        output->DM_STATE = Dm_on_active;
      }
    }
  }
}


#endif  /* (FCT_CFG_LOHP_COMPONENT) && (FCT_CFG_DM) */
