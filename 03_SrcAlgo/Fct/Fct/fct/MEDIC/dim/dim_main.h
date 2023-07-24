/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG
  
PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 DIM (Driver Intention Monitoring)

PACKAGENAME:               dim_main.h

DESCRIPTION:               declarations for dim_main.c

AUTHOR:                    $Author: Vogl, Armin (uid19462) $

CREATION DATE:             $Date: 2019/05/24 16:37:33CEST $

VERSION:                   $Revision: 1.7 $
**************************************************************************** */

#ifndef DIM_MAIN_H_INCLUDED
#define DIM_MAIN_H_INCLUDED

#include "dim/dim_cfg.h"

#if (MEDIC_CFG_DRIVER_INTENTION_MONITORING)
#include "dim/dim.h"
#if (DIM_CFG_HYPO_EBA)
#include "dim/dim_eba/dim_eba.h"
#endif


#endif // MEDIC_CFG_DRIVER_INTENTION_MONITORING
#endif // DIM_MAIN_H_INCLUDED

