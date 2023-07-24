/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC/LOHP/FCA (Adaptive Cruise Control - Longitudinal Headway Planner - Forward Collision Alert)

PACKAGENAME:               fca_par.c

DESCRIPTION:               Parameters file for function FCA

AUTHOR:                    $Author: Russell, Robert (russellr) $

CREATION DATE:             10.05.2010

VERSION:                   $Revision: 1.1 $

LEGACY VERSION:            Revision: 1.2.2.1

**************************************************************************** */

#include "fca.h"

#if ((FCT_CFG_LOHP_COMPONENT) && (FCT_CFG_FCA))

Fca_const acceleration_t FCA_ALERT_THRES = -6000;

Fca_const distance_t FCA_DMIN_BRAKE = 10;

Fca_const times_t FCA_T_REACT = 1500;

Fca_const times_t FCA_T_REACT_BRAKE = 200;

Fca_const velocity_t FCA_VMIN_DYN_ALERT = 888;

#endif  /* #if ((FCT_CFG_LOHP_COMPONENT) && (FCT_CFG_FCA)) */
