/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG
  
PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 ESPM (EBA signal performance degradation)

PACKAGENAME:               espm_par.h

DESCRIPTION:               Parameter File for EBA signal performance degradation (ESPM) module

AUTHOR:                    $Author: Rastogi, Abhishek (uib10447) (uib10447) $

CREATION DATE:             $Date: 2019/10/04 11:55:22CEST $

VERSION:                   $Revision: 1.7 $

**************************************************************************** */

#ifndef ESPM_PAR_H_INCLUDED
#define ESPM_PAR_H_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "acdc_par.h"
#include "espm_cfg.h"
#if (ACDC_CFG_ESPM)
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/*!
@defgroup espm_par Parameter
@ingroup espm
@brief    Contains all parameters that are used in the ESPM subcomponent.\n\n
@{
*/
/*****************************************************************************
  SYMOBLIC CONSTANTS (COMPONENT INTERNAL SCOPE)
*****************************************************************************/


/*****************************************************************************
  MACROS (COMPONENT INTERNAL SCOPE)
*****************************************************************************/

/*! Degradation parameters -> degradation distances*/
#define ESPM_MAX_LAT_DIST_SAFE                 ESPM_MAX_LAT_DIST_SAFE_c
#define ESPM_MAX_LAT_DIST_PERF                 ESPM_MAX_LAT_DIST_PERF_c
#define ESPM_MAX_LAT_DIST_SAFE_ALN             ESPM_MAX_LAT_DIST_SAFE_ALN_c
#define ESPM_MAX_LAT_DIST_PERF_ALN             ESPM_MAX_LAT_DIST_PERF_ALN_c
#define ESPM_MAX_LAT_DIST_SAFE_VDY             ESPM_MAX_LAT_DIST_SAFE_VDY_c
#define ESPM_MAX_LAT_DIST_PERF_VDY             ESPM_MAX_LAT_DIST_PERF_VDY_c
#define ESPM_PERF_ALN_MAX_QUOTA                ESPM_PERF_ALN_MAX_QUOTA_c
#define ESPM_PERF_VDY_MAX_QUOTA                ESPM_PERF_VDY_MAX_QUOTA_c

/* defines*/
  /****************************************************************
  Performance Degradation Settings (cd_wrapper.c, cd_customfunctions.c)
 *****************************************************************/
/*! @brief  Max lateral error for safety functions at max. distance 
            @typical 1.5f, @unit [m]*/
#define ESPM_PERF_DEG_MAX_LAT_ERR_DIST_SFTY           (         1.5f)
/*! @brief  Max lateral error for performance functions at max. distance.
            @typical 2.5f, @unit [m]*/
#define ESPM_PERF_DEG_MAX_LAT_ERR_DIST_PERF           (         2.5f)
/*! @brief  Distance in case of no lateral errors maximal possible distance.
            @typical 200.0f, @unit [m]*/
#define ESPM_PERF_DEG_MAX_DIST                        (       200.0f)
/*! @brief  PT1 filter constant for moving horizon distance filtering.
            @typical 0.2f*/
#define ESPM_PERF_DEG_HRZ_DIST_PT1_CONST              (         0.2f)
/*! @brief  Lower velocity limit for moving horizon fusion.
            @typical 5.0f, @unit [m/s]*/
#define ESPM_PERF_DEG_HRZ_DIST_FUSE_VEL_LOW           (         5.0f)
/*! @brief  Upper velocity limit for moving horizon fusion.
            @typical 8.0f, @unit [m/s]*/
#define ESPM_PERF_DEG_HRZ_DIST_FUSE_VEL_HIGH          (         8.0f)
/*! @brief  Initial value of Safety Distance.
            @typical 7.5f, @unit [m]*/
#define ESPM_SAFETY_DISTANCE_INIT_VALUE               (         7.5f)
/*****************************************************************************
  TYPEDEFS (COMPONENT INTERNAL SCOPE)
*****************************************************************************/


/*****************************************************************************
  CONSTANTS (COMPONENT INTERNAL SCOPE)
*****************************************************************************/


/*****************************************************************************
  VARIABLES (COMPONENT INTERNAL SCOPE)
*****************************************************************************/


/*****************************************************************************
  FUNCTION PROTOTYPES (COMPONENT INTERNAL SCOPE)
*****************************************************************************/


/* End of conditional inclusion */
///@}
#endif  /*!< ACDC_CFG_ESPM */
#endif  /*!< ESPM_PAR_H_INCLUDED */

