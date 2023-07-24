/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC/LOHP/FCA (Adaptive Cruise Control - Longitudinal Headway Planner - Forward Collision Alert)

PACKAGENAME:               fca_fct.c

DESCRIPTION:               This file contains all the functions concerning FCA functionality

AUTHOR:                    Mistry Niraj (uidq5738)

CREATION DATE:             24.02.2017

VERSION:                   $Revision: 1.3 $

LEGACY VERSION:            Revision: 1.9.1.2

**************************************************************************** */

#include "fca.h"

#if ((FCT_CFG_LOHP_COMPONENT) && (FCT_CFG_FCA))


/*************************************************************************************************************************
  @fn               FCA_v_DetermineAlert                                                                            */ /*!

  @brief            Decide whether a DynamicAlert should be issued

  @description      Decide whether a DynamicAlert should be issued

  @param[in,out]    AlertData

  @param[in]        Object

  @return           void

  @pre              Precondition:  none

  @post             Postcondition: none
*************************************************************************************************************************/
void FCA_v_DetermineAlert(fca_output_data_t* AlertData, const object_t *Object)
{
  if (
      (AlertData->FCA_STATE == Fca_status_on_active)
     )
  {

    if ((AlertData->FCA_STATUS).FCA_ALERT == FALSE)
    {

      if (
          (AlertData->NEEDED_ACCEL < FCA_ALERT_THRES)
          &&
          (Object->OBJECT_STATUS.DETECTED == TRUE)
#if (!CFG_FCT_FCA_ALERT_STATIONARY_OBJ)
          &&
          (
           (Object->OBJECT_STATUS.STANDING == FALSE)
           ||
           (Object->OBJECT_STATUS.STOPPED == TRUE)
          )
#endif
         )
      {
        (AlertData->FCA_STATUS).FCA_ALERT = TRUE;
      }
    }
    else
    {

      if (
          (AlertData->NEEDED_ACCEL > FCA_ALERT_THRES)
         )
      {
        (AlertData->FCA_STATUS).FCA_ALERT = FALSE;
      }
    }
  }
  else
  {
    (AlertData->FCA_STATUS).FCA_ALERT = FALSE;
  }
}


#endif  /* (FCT_CFG_LOHP_COMPONENT) && (FCT_CFG_FCA) */
