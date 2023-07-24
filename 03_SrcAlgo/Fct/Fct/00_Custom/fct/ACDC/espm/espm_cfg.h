/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG
  
PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 ESPM (EBA signal performance degradation)

PACKAGENAME:               espm_cfg.h

DESCRIPTION:               Configuration Header File for EBA signal performance degradation (ESPM) module

AUTHOR:                    $Author: Rastogi, Abhishek (uib10447) (uib10447) $

CREATION DATE:             $Date: 2019/10/04 12:44:14CEST $

VERSION:                   $Revision: 1.9 $
**************************************************************************** */

#ifndef ESPM_CFG_H_INCLUDED
#define ESPM_CFG_H_INCLUDED

#include "acdc_cfg.h"

#if (ACDC_CFG_ESPM)
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/*!
@defgroup espm_cfg Configuration
@ingroup espm
@brief    Contains all configuration switches of the ESPM subcomponent.\n\n
@{
*/

/*! @brief Switch activates the elevation range in the degradation concept */
#define ESPM_USE_ELEVATION_DEGR_DIST                  SWITCH_ON 

/*! @brief Use performance degradation results from FCT/SPM */
#define ESPM_CFG_USE_SPM_OUTPUT                       FCT_CFG_SWITCH_RADAR(SWITCH_ON)

/*makes degradation independent of VDY considerations
To be switched on only if VDY curve error is not reliably
determined at all */
#define ESPM_CFG_CURVEERROR_INDEPENDENT_DEGRADATION   SWITCH_OFF 

/*! Fill interface for EBA Safety Distance with custom max allowed distance 
if calculated EBA Safety Distance is less than threshold*/
#define ESPM_USE_CUST_SAFETY_DIST                     SWITCH_OFF

///@}
#endif /* ACDC_CFG_ESPM */
#endif /*!< ESPM_CFG_H_INCLUDED */
