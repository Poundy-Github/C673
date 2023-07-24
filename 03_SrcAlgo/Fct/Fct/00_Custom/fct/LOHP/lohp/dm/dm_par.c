/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC/LOHP/DM (Adaptive Cruise Control - Longitudinal Headway Planner - Driver Monitoring)

PACKAGENAME:               dm_par.h

DESCRIPTION:               Parameters file for function DM

AUTHOR:                    $Author: Russell, Robert (russellr) $

CREATION DATE:             10.05.2010

VERSION:                   $Revision: 1.1 $

LEGACY VERSION:            Revision: 1.2.2.1

**************************************************************************** */

#include "dm.h"

#if ((FCT_CFG_LOHP_COMPONENT) && (FCT_CFG_DM))

Dm_const times_t DM_T_STAT_ALERT = 5000;

Dm_const times_t DM_TIMEGAP_HUGE = 10000;

Dm_const velocity_t DM_V_MIN_DM = 2222;

Dm_const velocity_t DM_V_MAX_DM = 5000;

Dm_const velocity_t DM_V_MIN_HYST = 139;

Dm_const velocity_t DM_V_MAX_HYST = 139;

Dm_const times_t DM_ALERT_THRES_1 = 2000;

Dm_const times_t DM_ALERT_THRES_2 = 1500;

Dm_const times_t DM_ALERT_THRES_3 = 1000;

Dm_const times_t DM_ALERT_THRES_OFF = 25400;

Dm_const times_t DM_T_HYST_DOWN = 0;

Dm_const times_t DM_T_HYST_UP = 100;

Dm_const times_t DM_T_PRED = 1000;

#endif  /* #if ((FCT_CFG_LOHP_COMPONENT) && (FCT_CFG_DM)) */
