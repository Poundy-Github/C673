/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC/LOHP/FCA (Adaptive Cruise Control - Longitudinal Headway Planner - Forward Collision Alert)

PACKAGENAME:               fca_par.h

DESCRIPTION:               Alert parameter definition for function FCA

AUTHOR:                    $Author: Russell, Robert (russellr) $

CREATION DATE:             10.05.2010

VERSION:                   $Revision: 1.1 $

LEGACY VERSION:            Revision: 1.5.2.2

**************************************************************************** */

/* conditional include */
#ifndef FCAPAR_INCLUDED
#define FCAPAR_INCLUDED


#if ((FCT_CFG_LOHP_COMPONENT) && (FCT_CFG_FCA))

#define Fca_const

/*! [m/s²] Alert Threshold */
#define Fca_alert_thres FCA_ALERT_THRES
extern Fca_const acceleration_t FCA_ALERT_THRES;

/*! [s] Driver reaction time when not already braking */
#define Fca_t_reaction FCA_T_REACT
extern Fca_const times_t FCA_T_REACT;

/*! [s] Driver reaction time when already braking */
#define Fca_t_reaction_brake FCA_T_REACT_BRAKE
extern Fca_const times_t FCA_T_REACT_BRAKE;

/*! [m/s] Minimum speed for enabling the dynamic alert function */
#define Fca_v_min_alert FCA_VMIN_DYN_ALERT
extern Fca_const velocity_t FCA_VMIN_DYN_ALERT;

#endif  /* #if ((FCT_CFG_LOHP_COMPONENT) && (FCT_CFG_FCA)) */

#endif
