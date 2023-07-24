/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 Adaptive Cruise Control (ACC)

PACKAGENAME:               apm_par.c

DESCRIPTION:               Parameter File for ACC Performance Monitoring (APM) module

AUTHOR:                    Boll Marie-Theres (uidu1091)

CREATION DATE:             24.10.2016

VERSION:                   $Revision: 1.4 $

LEGACY VERSION:            Revision: 2.0

**************************************************************************** */
#include "apm.h"

#if (FCT_CFG_ACC_PERF_MONITORING)

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/*!
@addtogroup apm_par
@{
*/

/*****************************************************************************
  SYMOBLIC CONSTANTS (COMPONENT INTERNAL SCOPE)
*****************************************************************************/


/*****************************************************************************
  MACROS (COMPONENT INTERNAL SCOPE)
*****************************************************************************/


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


/***************************/
/* Degradation parameters */
/***************************/

SET_MEMSEC_CONST(APM_ACC_MAX_LAT_DIST_PERF_c)       
FCT_DEF_FIX_PARAM(float32 , APM_ACC_MAX_LAT_DIST_PERF_c ,   1.75f )
/*! @brief       max lateral displacement for the ACC fused performance distance
    @general     s. brief
    @conseq      @incp  performance distance is getting higher 
                 @decp  performance distance is getting lower 
    @attention   -
    @typical     2.5    @unit  [m]   @min 0   @max 10   */

SET_MEMSEC_CONST(APM_ACC_MAX_LAT_DIST_PERF_ALN_c)   
FCT_DEF_FIX_PARAM(float32 , APM_ACC_MAX_LAT_DIST_PERF_ALN_c ,   1.f )
/*! @brief       max lateral displacement for the ACC ALN only performance distance
    @general     s. brief
    @conseq      @incp  performance distance is getting higher 
                 @decp  performance distance is getting lower 
    @attention   -
    @typical     1.0    @unit  [m]   @min 0   @max 10   */


SET_MEMSEC_CONST(APM_ACC_MAX_LAT_DIST_PERF_VDY_c)    
FCT_DEF_FIX_PARAM(float32 , APM_ACC_MAX_LAT_DIST_PERF_VDY_c ,   0.75f )
/*! @brief       max lateral displacement for the ACC VDY only performance distance
    @general     s. brief
    @conseq      @incp  performance distance is getting higher 
                 @decp  performance distance is getting lower 
    @attention   -
    @typical     2.5    @unit  [m]   @min 0   @max 10   */


SET_MEMSEC_CONST(APM_ACC_PERF_ALN_MAX_QUOTA_c)      
FCT_DEF_FIX_PARAM(float32 , APM_ACC_PERF_ALN_MAX_QUOTA_c ,   1.f )
/*! @brief       max lateral displacement for the ACC ALN part of the fused performance distance. 
                 If the performance distance is below the min perf dist and ALN exceeds its quota. ALN is the error cause
    @general     s. brief
    @conseq      @incp  it needs a higher ALN error to assign ALN as error cause
                 @decp  it needs a lower ALN error to assign ALN as error cause
    @attention   -
    @typical     1.425f    @unit  [m]   @min 0   @max 10   */

SET_MEMSEC_CONST(APM_ACC_PERF_VDY_MAX_QUOTA_c)    
FCT_DEF_FIX_PARAM(float32 , APM_ACC_PERF_VDY_MAX_QUOTA_c ,   0.75f )
/*! @brief       max lateral displacement for the ACC VDY part of the fused performance distance. 
                 If the performance distance is below the min perf dist and ALN exceeds its quota. ALN is the error cause
    @general     s. brief
    @conseq      @incp  it needs a higher VDY error to assign VDY as error cause
                 @decp  it needs a lower VDY error to assign VDY as error cause
    @attention   -
    @typical     1.025f    @unit  [m]   @min 0   @max 10   */

SET_MEMSEC_CONST(APM_MIN_PERF_DIST_V_DIFF_MAX_c)   
FCT_DEF_FIX_PARAM(float32 , APM_MIN_PERF_DIST_V_DIFF_MAX_c ,   0.4f )
/*! @brief       percetage of the ego-velocity to determine worst case target-velocity
    @general     s. brief
    @conseq      @incp  higher target velocity -> lower relative velocity -> lower minimal performance distance
                 @decp  lower target velocity -> higher relative velocity -> higher minimal performance distance
    @attention   -
    @typical     0.4f    @unit  [%]   @min 0   @max 10   */

SET_MEMSEC_CONST(APM_MIN_PERF_DIST_T_REAK_c)       
FCT_DEF_FIX_PARAM(float32 , APM_MIN_PERF_DIST_T_REAK_c ,   1.f )
/*! @brief       assumption for the reaktion time of the driver
    @general     s. brief
    @conseq      @incp  higher reaction time -> higher free running distance -> higher minimal performance distance
                 @decp  lower reaction time -> lower free running distance -> lower minimal performance distance
    @attention   -
    @typical     1.f    @unit  [s]   @min 0   @max 10   */

SET_MEMSEC_CONST(APM_MIN_PERF_DIST_A_EGO_MAX_c)     
FCT_DEF_FIX_PARAM(float32 , APM_MIN_PERF_DIST_A_EGO_MAX_c ,   8.f )
/*! @brief       assumption for the maximum deceleration of the driver
    @general     s. brief
    @conseq      @incp  higher max deceleration -> lower braking distance -> lower minimal performance distance
                 @decp  lower max deceleration -> higher braking distance -> higher minimal performance distance
    @attention   -
    @typical     8.f    @unit  [m/s^2]   @min 0   @max 12   */

SET_MEMSEC_CONST(APM_MIN_PERF_DIST_A_TARGET_MAX_c) 
FCT_DEF_FIX_PARAM(float32 , APM_MIN_PERF_DIST_A_TARGET_MAX_c ,   1.f )
/*! @brief       assumption for the minimum deceleration of the target vehicle
    @general     s. brief
    @conseq      @incp  higher max deceleration -> higher minimal performance distance
                 @decp  lower max deceleration -> lower minimal performance distance
    @attention   -
    @typical     1.f    @unit  [m/s^2]   @min 0   @max 12   */

///@}
#endif  /*!< FCT_CFG_ACC_PERF_MONITORING */

