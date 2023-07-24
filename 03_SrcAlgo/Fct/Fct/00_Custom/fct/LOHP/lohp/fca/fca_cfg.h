/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC/LOHP/FCA (Adaptive Cruise Control - Longitudinal Headway Planner - Forward Collision Alert)

PACKAGENAME:               fca_cfg.h

DESCRIPTION:               Configuration file for function FCA

AUTHOR:                    $Author: Russell, Robert (russellr) $

CREATION DATE:             10.05.2010

VERSION:                   $Revision: 1.1 $

LEGACY VERSION:            Revision: 1.1

**************************************************************************** */

#ifndef FCA_CFG_H_INCLUDED
#define FCA_CFG_H_INCLUDED

/*****************************************************************************
  Config: FCA (Forward collision Alert function)
*****************************************************************************/

/*! fca alert also for (stationary) objects (alert will always be occur to stopped objects!) */
#define CFG_FCT_FCA_ALERT_STATIONARY_OBJ         (1)


#endif
