/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC/LOHP/DM (Adaptive Cruise Control - Longitudinal Headway Planner - Driver Monitoring)

PACKAGENAME:               dm_par.h

DESCRIPTION:               Alert parameter definition for function DM

AUTHOR:                    $Author: Russell, Robert (russellr) $

CREATION DATE:             10.05.2010

VERSION:                   $Revision: 1.1 $

LEGACY VERSION:            Revision: 1.5.2.2

**************************************************************************** */

/* conditional include */
#ifndef DMPAR_INCLUDED
#define DMPAR_INCLUDED


#if ((FCT_CFG_LOHP_COMPONENT) && (FCT_CFG_DM))

#define Dm_const

/*! [ms] Time till static alert */
#define Dm_static_alert_time DM_T_STAT_ALERT
extern Dm_const times_t DM_T_STAT_ALERT;

/*! [s] Time gap huge */
#define Dm_timegap_huge DM_TIMEGAP_HUGE
extern Dm_const times_t DM_TIMEGAP_HUGE;

/*! [m/s] Lower velocity threshold */
#define Dm_v_min_dm_alert DM_V_MIN_DM
extern Dm_const velocity_t DM_V_MIN_DM;

/*! [m/s] Upper velocity threshold */
#define Dm_v_max_dm_alert DM_V_MAX_DM
extern Dm_const velocity_t DM_V_MAX_DM;

/*! [m/s] Velocity hysteresis to OnInactive after OnActive */
#define Dm_v_min_hysteresis DM_V_MIN_HYST
extern Dm_const velocity_t DM_V_MIN_HYST;

/*! [m/s] Velocity hysteresis to OnActive after OnInactive */
#define Dm_v_max_hysteresis DM_V_MAX_HYST
extern Dm_const velocity_t DM_V_MAX_HYST;

/*! [s] Time gap threshold far / ok */
#define Dm_alert_timegap_threshold_1 DM_ALERT_THRES_1
extern Dm_const times_t DM_ALERT_THRES_1;

/*! [s] Time gap threshold ok / near */
#define Dm_alert_timegap_threshold_2 DM_ALERT_THRES_2
extern Dm_const times_t DM_ALERT_THRES_2;

/*! [s] Time gap threshold near / critical */
#define Dm_alert_timegap_threshold_3 DM_ALERT_THRES_3
extern Dm_const times_t DM_ALERT_THRES_3;

/*! [s] Time gap threshold off */
#define Dm_alert_timegap_threshold_off DM_ALERT_THRES_OFF
extern Dm_const times_t DM_ALERT_THRES_OFF;

/*! [s] Time hysteresis when transitioning to an upper alert level */
#define Dm_time_hysteresis_down DM_T_HYST_DOWN
extern Dm_const times_t DM_T_HYST_DOWN;

/*! [s] Time hysteresis when transitioning to a lower alert level */
#define Dm_time_hysteresis_up DM_T_HYST_UP
extern Dm_const times_t DM_T_HYST_UP;

/*! [s] Time to determine the estimated timegap */
#define Dm_timegap_prediction_time DM_T_PRED
extern Dm_const times_t DM_T_PRED;

#endif  /* #if ((FCT_CFG_LOHP_COMPONENT) && (FCT_CFG_DM)) */

#endif
