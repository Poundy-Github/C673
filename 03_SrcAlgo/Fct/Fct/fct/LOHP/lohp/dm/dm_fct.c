/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC/LOHP/DM (Adaptive Cruise Control - Longitudinal Headway Planner - Driver Monitoring)

PACKAGENAME:               dm_fct.c

DESCRIPTION:               This file contains all the functions concerning 
                           Distance Monitoring Functionality

AUTHOR:                    Mistry Niraj (uidq5738)

CREATION DATE:             24.02.2017

VERSION:                   $Revision: 1.3 $

LEGACY VERSION:            Revision: 1.9.1.2

**************************************************************************** */

#include "dm.h"

#if ((FCT_CFG_LOHP_COMPONENT) && (FCT_CFG_DM))

/* ***********************************************************************
  @fn               DM_v_TickerSaverAlert */ /*!

  @brief            Decide whether a StaticAlert should be issued

  @description      Decide whether a StaticAlert should be issued

  @param[in,out]    AlertData
  @param[in,out]    dm_status
  @param[in,out]    object
  @param[in]        cycle_time

  @return           void

  @pre              Precondition:  none

  @post             Postcondition: none
**************************************************************************** */
static void DM_v_TickerSaverAlert(const times_t cycle_time, dm_output_data_t* AlertData, const acc_object_t *object, dm_status_t *dm_status)
{

  if (
      (AlertData->DM_STATE == Dm_on_active)
      &&
      (dm_status->DM_ESTIMATED_TIMEGAP < (times_t)Time_max)
      &&
      (object->AUTOSAR.OBJECT_STATUS.NEW == FALSE)
    ) {

    /* Determine AlertLevel if DM_state is OnActive and object available */

    if (AlertData->DM_ALERT_LEVEL != Display_alert_level4) {
      
      /* Alert not set before */
      if (dm_status->StaticAlertCounter > (uint16)0) {
        
        if (dm_status->DM_ESTIMATED_TIMEGAP < (Dm_alert_timegap_threshold_1 - Dm_time_hysteresis_down)) {
          
          /* Increase timer */
          dm_status->StaticAlertCounter--;
        }
        else {
          
          /* Reset timer - comment: div/0 -> cycle time will never be zero*/
          dm_status->StaticAlertCounter = (uint16)(Dm_static_alert_time / cycle_time);
        }

        if (AlertData->DM_ALERT_LEVEL != Display_alert_level0) {

          /* Reset AlertLevel */
          AlertData->DM_ALERT_LEVEL = Display_alert_level0;
        }
      }
      else {
        
        /* AlertLevel = critical */
        AlertData->DM_ALERT_LEVEL = Display_alert_level4;
      }
    }
    else {
      
      /* Alert set before */
      if (dm_status->DM_ESTIMATED_TIMEGAP > (Dm_alert_timegap_threshold_1 + Dm_time_hysteresis_up)) {
        
        /* Reset AlertLevel */
        AlertData->DM_ALERT_LEVEL = Display_alert_level0;
        /*comment: div/0 -> cycle time will never be zero*/
        dm_status->StaticAlertCounter = (uint16)(Dm_static_alert_time / cycle_time);
      }
      else {
      
        /* stay at Alert */
      }
    } 
  }
  else {
  
    /* Change of inpath-object or no object: Reset Alert */
    AlertData->DM_ALERT_LEVEL = Display_alert_level0;
    /*comment: div/0 -> cycle time will never be zero*/
    dm_status->StaticAlertCounter = (uint16)(Dm_static_alert_time / cycle_time);
  }
}


/* ***********************************************************************
  @fn               DM_v_ThreeLevelAlert */ /*!

  @brief            Determine Alert with three levels

  @description      Determine Alert with three levels

  @param[in,out]    AlertData
  @param[in]        cycle_time
  @param[in,out]    dm_status

  @param[in]        

  @return           void

  @pre              Precondition:  none

  @post             Postcondition: none
**************************************************************************** */
static void DM_v_ThreeLevelAlert(const times_t cycle_time, dm_output_data_t* AlertData, dm_status_t *dm_status)
{

  if (
      (AlertData->DM_STATE == Dm_on_active)
      &&
      (dm_status->DM_ESTIMATED_TIMEGAP < (times_t)Time_max)
    ) {

    /* Determine AlertLevel if DM is ActiveOn and AlertObject is valid */

    if (dm_status->DM_ESTIMATED_TIMEGAP < (Dm_alert_timegap_threshold_2 - Dm_time_hysteresis_down)) {

      /* AlertLevel = near */
      AlertData->DM_ALERT_LEVEL = Display_alert_level3;
    }
    else {
    
      if (dm_status->DM_ESTIMATED_TIMEGAP < (Dm_alert_timegap_threshold_2 + Dm_time_hysteresis_up)) {

        if (AlertData->DM_ALERT_LEVEL != Display_alert_level3) {

          /* AlertLevel = ok */
          AlertData->DM_ALERT_LEVEL = Display_alert_level2;
        }
      }
      else {
      
        if (dm_status->DM_ESTIMATED_TIMEGAP < (Dm_alert_timegap_threshold_1 - Dm_time_hysteresis_down)) {

          /* AlertLevel = ok */
          AlertData->DM_ALERT_LEVEL = Display_alert_level2;
        }
        else {
        
          if (dm_status->DM_ESTIMATED_TIMEGAP < (Dm_alert_timegap_threshold_1 + Dm_time_hysteresis_up)) {

            if (
                (AlertData->DM_ALERT_LEVEL == Display_alert_level1)
                ||
                (AlertData->DM_ALERT_LEVEL == Display_alert_level0)
              ) {

              /* AlertLevel = far */
              AlertData->DM_ALERT_LEVEL = Display_alert_level1;
            }
            else {
            
              /* AlertLevel = ok */
              AlertData->DM_ALERT_LEVEL = Display_alert_level2;
            }
          }
          else {
          
            /* AlertLevel = far */
            AlertData->DM_ALERT_LEVEL = Display_alert_level1;
          }
        }
      }
    }
  }
  else {
  
    /* DM is not active or AlertObject is not valid */
    /* Reset Alert */
    AlertData->DM_ALERT_LEVEL = Display_alert_level0;
    /*comment: div/0 -> cycle time will never be zero*/
    dm_status->StaticAlertCounter = (uint16)(Dm_static_alert_time / cycle_time);
  }
}


/* ***********************************************************************
  @fn               DM_v_FourLevelAlert */ /*!

  @brief            Determine Alert with four levels

  @description      Determine Alert with four levels

  @param[in,out]    AlertData

  @param[in]        cycle_time

  @param[in,out]    dm_status

  @return           void

  @pre              Precondition:  none

  @post             Postcondition: none
**************************************************************************** */
static void DM_v_FourLevelAlert(const times_t cycle_time, dm_output_data_t* AlertData, dm_status_t *dm_status)
{

  if (
      (AlertData->DM_STATE == Dm_on_active)
      &&
      (dm_status->DM_ESTIMATED_TIMEGAP < (times_t)Time_max)
    ) {

    /* Determine AlertLevel if DM is ActiveOn and AlertObject is valid */

    if (dm_status->DM_ESTIMATED_TIMEGAP < (Dm_alert_timegap_threshold_3 - Dm_time_hysteresis_down)) {

      /* AlertLevel = critical */
      AlertData->DM_ALERT_LEVEL = Display_alert_level4;
    }
    else {

      if (dm_status->DM_ESTIMATED_TIMEGAP < (Dm_alert_timegap_threshold_3 + Dm_time_hysteresis_up)) {
        
        if (AlertData->DM_ALERT_LEVEL != Display_alert_level4) {
        
          /* AlertLevel = near */
          AlertData->DM_ALERT_LEVEL = Display_alert_level3;
        }
      }
      else {

        if (dm_status->DM_ESTIMATED_TIMEGAP < (Dm_alert_timegap_threshold_2 - Dm_time_hysteresis_down)) {

          /* AlertLevel = near */
          AlertData->DM_ALERT_LEVEL = Display_alert_level3;
        }
        else {
        
          if (dm_status->DM_ESTIMATED_TIMEGAP < (Dm_alert_timegap_threshold_2 + Dm_time_hysteresis_up)) {

            if (
                (AlertData->DM_ALERT_LEVEL != Display_alert_level3)
                &&
                (AlertData->DM_ALERT_LEVEL != Display_alert_level4)
              ) {

              /* AlertLevel = ok */
              AlertData->DM_ALERT_LEVEL = Display_alert_level2;
            }
            else {
            
              /* AlertLevel = near */
              AlertData->DM_ALERT_LEVEL = Display_alert_level3;
            }
          }
          else {
          
            if (dm_status->DM_ESTIMATED_TIMEGAP < (Dm_alert_timegap_threshold_1 - Dm_time_hysteresis_down)) {

              /* AlertLevel = ok */
              AlertData->DM_ALERT_LEVEL = Display_alert_level2;
            }
            else {
            
              if (dm_status->DM_ESTIMATED_TIMEGAP < (Dm_alert_timegap_threshold_1 + Dm_time_hysteresis_up)) {

                if (
                    (AlertData->DM_ALERT_LEVEL == Display_alert_level1)
                    ||
                    (AlertData->DM_ALERT_LEVEL == Display_alert_level0)
                  ) {

                  /* AlertLevel = far */
                  AlertData->DM_ALERT_LEVEL = Display_alert_level1;
                }
                else {
                
                  /* AlertLevel = ok */
                  AlertData->DM_ALERT_LEVEL = Display_alert_level2;
                }
              }
              else {
              
                /* AlertLevel = far */
                AlertData->DM_ALERT_LEVEL = Display_alert_level1;
              }
            }
          }
        }
      }
    }
  }
  else {
  
    /* DM is not active or AlertObject is not valid */
    /* Reset Alert */
    AlertData->DM_ALERT_LEVEL = Display_alert_level0;
    /*comment: div/0 -> cycle time will never be zero*/
    dm_status->StaticAlertCounter = (uint16)(Dm_static_alert_time / cycle_time);
  }
}

/* ***********************************************************************
  @fn               DM_v_DetermineAlert */ /*!
  
  @brief            Decide whether a StaticAlert should be issued

  @description      Decide whether a StaticAlert should be issued

  @param[in,out]    cycle_time
  @param[in,out]    input
  @param[in,out]    output
  @param[in,out]    object
  @param[in,out]    dm_status

  @return           void

  @pre              Precondition:  none

  @post             Postcondition: none
**************************************************************************** */
void DM_v_DetermineAlert(const times_t cycle_time,
                        const dm_input_data_t* input,
                        dm_output_data_t* output,
                        const acc_object_t* object,
                        dm_status_t *dm_status)
{
  sint32  d_obj_pred;
  sint32  v_host_pred;
  sint32  temp;
  times_t estimated_timegap;


  /* Determine Estimated Timegap */
  /* only if vehicle speed is higher than Dm_v_min_dm_alert and object is detected and moving */
  if (
      (object->AUTOSAR.OBJECT_STATUS.DETECTED == TRUE)
      &&
      (object->AUTOSAR.OBJECT_STATUS.MOVING == TRUE)
      &&
      (input->LONG_VELOCITY > Dm_v_min_dm_alert)
    ) {

    /* dObjPred = dObj +(vRel * tPred) + (1/2 * aRel * tPred^2) */
    d_obj_pred = (sint32)object->AUTOSAR.LONG_DISPLACEMENT;
    temp = (sint32)(object->AUTOSAR.REL_LONG_SPEED) * (sint32)Dm_timegap_prediction_time;
    temp /= (sint32)Time_s;
    temp *= (sint32)Distance_s;
    temp /= (sint32)Velocity_s;
    d_obj_pred += temp;
    temp = (sint32)(object->AUTOSAR.REL_LONG_ACCEL) * (sint32)Dm_timegap_prediction_time;
    temp /= (sint32)Time_s;
    temp *= (sint32)Dm_timegap_prediction_time;
    temp /= (sint32)Time_s;
    temp *= (sint32)Distance_s;
    temp /= (sint32)2;
    temp /= (sint32)Acceleration_s;
    d_obj_pred += temp;

    /* vHostPred = vHost + aHost * tPred */
    v_host_pred = (sint32)(input->LONG_VELOCITY);
    temp = (sint32)input->LONG_ACCELERATION * (sint32)Dm_timegap_prediction_time;
    temp /= (sint32)Time_s;
    temp *= (sint32)Distance_s;
    temp /= (sint32)Acceleration_s;
    v_host_pred += temp;

    /* tGapEstimated = dObjPred / vHostPred */
    temp = (sint32)Time_s * d_obj_pred;
    temp /= (sint32)Distance_s;
    temp *= (sint32)Velocity_s;
    temp /= v_host_pred;

    estimated_timegap = (times_t)MAT_LIM(temp,(sint32)Time_min,(sint32)Dm_timegap_huge);
  
  }
  else {
  
    estimated_timegap = (times_t)Time_max;
  }

  dm_status->DM_ESTIMATED_TIMEGAP = (times_t)estimated_timegap;


  /* Determine AlertFunction */
  if (
      (Dm_alert_timegap_threshold_3 > Dm_alert_timegap_threshold_off)
      &&
      (Dm_alert_timegap_threshold_2 > Dm_alert_timegap_threshold_off)
    ) {

    /* TicketSaver: Determine AlertLevel critical */
    DM_v_TickerSaverAlert(cycle_time, output, object, dm_status);
  }
  else {

    if (Dm_alert_timegap_threshold_3 > Dm_alert_timegap_threshold_off) {

      /* ThreelLevelAlert: Determine AlertLevel near, ok and far */
      DM_v_ThreeLevelAlert(cycle_time, output, dm_status);
    }
    else {

      /* FourLevelAlert: Determine AlertLevel critical, near, ok and far */
      DM_v_FourLevelAlert(cycle_time, output, dm_status);
    }
  }
}


#endif  /* (FCT_CFG_LOHP_COMPONENT) && (FCT_CFG_DM) */
