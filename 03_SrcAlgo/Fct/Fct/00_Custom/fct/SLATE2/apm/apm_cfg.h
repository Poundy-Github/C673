/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 Adaptive Cruise Control (ACC)

PACKAGENAME:               apm_cfg.h

DESCRIPTION:               Configuration Header File for ACC Performance Monitoring (APM) module

AUTHOR:                    Boll Marie-Theres (uidu1091)

CREATION DATE:             24.10.2016

VERSION:                   $Revision: 1.5 $

LEGACY VERSION:            Revision: 2.0

**************************************************************************** */
#ifndef APM_CFG_H_INCLUDED
#define APM_CFG_H_INCLUDED
#include "slate_config.h"

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/*!
@defgroup apm_cfg Configuration
@ingroup apm
@brief    Contains all configuration switches related to the apm subcomponent.\n\n
@{
*/

/*! Switch activates the elevation range in the degradation concept */
#define APM_USE_ELEVATION_DEGR_DIST           SWITCH_ON // duplicate to SPM_USE_ELEVATION_DEGR_DIST

/*makes degradation independent of VDY considerations
To be switched on only if VDY curve error is not reliably
determined at all */
#define APM_CFG_CURVEERROR_INDEPENDENT_DEGRADATION   SWITCH_OFF 
///@}
#endif /*!< APM_CFG_H_INCLUDED */
