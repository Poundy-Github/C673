/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC/LOHP/FCA (Adaptive Cruise Control - Longitudinal Headway Planner - Forward Collision Alert)

PACKAGENAME:               fca_hmi.c

DESCRIPTION:               This file contains the state machine for the FCA functionality

AUTHOR:                    Mistry Niraj (uidq5738)

CREATION DATE:             24.02.2017

VERSION:                   $Revision: 1.3 $

LEGACY VERSION:            Revision: 1.8.1.1

**************************************************************************** */

#include "fca.h"

#if ((FCT_CFG_LOHP_COMPONENT) && (FCT_CFG_FCA))


/*************************************************************************************************************************
  @fn               FCA_DETERMINE_ALERT_STAT                                                                        */ /*!

  @brief            state machine for FCA

  @description      state machine for FCA

  @param[in,out]    AlertData

  @param[in]        input Object

  @param[in]        output VehicleData

  @return           void

  @pre              Precondition:  none

  @post             Postcondition: none
*************************************************************************************************************************/
void FCA_v_DetermineAlertState(const fca_input_data_t* input, fca_output_data_t* output)
{
  switch(output->FCA_STATE) {
    case Fca_status_off:
    {
      if (input->CONTROL.FCA_ON == TRUE) {

        output->FCA_STATE = Fca_status_on_inactive;
      }
      break;
    }
    case Fca_status_on_inactive:
    {
    
      if (input->CONTROL.FCA_ON == FALSE) {

        output->FCA_STATE = Fca_status_off;
      }
      else {

        if (input->SPEEDO_SPEED > Fca_v_min_alert) {

          output->FCA_STATE = Fca_status_on_active;
        }
      }
      break;
    }
    case Fca_status_on_active:
    {
    
      if (input->CONTROL.FCA_ON == FALSE) {

        output->FCA_STATE = Fca_status_off;
      }
      else {

        if (input->SPEEDO_SPEED < Fca_v_min_alert) {

          output->FCA_STATE = Fca_status_on_inactive;
        }
      }
      break;
    }
    default:
    {
      output->FCA_STATE = Fca_status_off;
      break;
    }
  }
}


#endif /* (FCT_CFG_LOHP_COMPONENT) && (FCT_CFG_FCA) */
