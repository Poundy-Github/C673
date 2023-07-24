/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG
  
PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 ESPM (EBA signal performance degradation)

PACKAGENAME:               espm_par.c

DESCRIPTION:               Parameter File for EBA signal performance degradation (ESPM) module

AUTHOR:                    $Author: uidn4751 $

CREATION DATE:             $Date: 2019/06/03 16:56:06CEST $

VERSION:                   $Revision: 1.4 $

**************************************************************************** */

#include "espm_int.h"

#if (ACDC_CFG_ESPM)
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/*!
\addtogroup espm_par
\{
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
/*! @brief       max lateral displacement for the EBA fused safety distance
    @conseq      @incp  safety distance is getting higher \n
                 @decp  safety distance is getting lower \n
    @typical     1.75f   @unit  [m]   @min 0   @max 10   */
SET_MEMSEC_CONST(ESPM_MAX_LAT_DIST_SAFE_c)
/*PRQA S 3432 1*/ /* date: 2019-05-15, reviewer: Schnurr, Clemens, reason: Macro does not work with paranthesis*/
FCT_DEF_FIX_PARAM(float32 , ESPM_MAX_LAT_DIST_SAFE_c ,   1.75f )

/*! @brief       max lateral displacement for the EBA fused performance distance
    @conseq      @incp  performance distance is getting higher \n
                 @decp  performance distance is getting lower \n
    @typical     2.5    @unit  [m]   @min 0   @max 10   */
SET_MEMSEC_CONST(ESPM_MAX_LAT_DIST_PERF_c)
/*PRQA S 3432 1*/ /* date: 2019-05-15, reviewer: Schnurr, Clemens, reason: Macro does not work with paranthesis*/
FCT_DEF_FIX_PARAM(float32 ,ESPM_MAX_LAT_DIST_PERF_c ,   1.75f )


/*! @brief       max lateral displacement for the EBA ALN only safety distance
    @general     s. brief
    @conseq      @incp  safety distance is getting higher \n
                 @decp  safety distance is getting lower \n
    @typical     0.75    @unit  [m]   @min 0   @max 10   */
SET_MEMSEC_CONST(ESPM_MAX_LAT_DIST_SAFE_ALN_c)
/*PRQA S 3432 1*/ /* date: 2019-05-15, reviewer: Schnurr, Clemens, reason: Macro does not work with paranthesis*/
FCT_DEF_FIX_PARAM(float32 , ESPM_MAX_LAT_DIST_SAFE_ALN_c ,   1.f )

/*! @brief       max lateral displacement for the EBA ALN only performance distance
    @conseq      @incp  performance distance is getting higher \n
                 @decp  performance distance is getting lower \n
    @typical     1.0    @unit  [m]   @min 0   @max 10   */
SET_MEMSEC_CONST(ESPM_MAX_LAT_DIST_PERF_ALN_c)
/*PRQA S 3432 1*/ /* date: 2019-05-15, reviewer: Schnurr, Clemens, reason: Macro does not work with paranthesis*/ 
FCT_DEF_FIX_PARAM(float32 ,ESPM_MAX_LAT_DIST_PERF_ALN_c ,   1.f )

/*! @brief       max lateral displacement for the EBA VDY only safety distance
    @general     s. brief
    @conseq      @incp  safety distance is getting higher \n
                 @decp  safety distance is getting lower \n
    @typical     1.5    @unit  [m]   @min 0   @max 10   */
SET_MEMSEC_CONST(ESPM_MAX_LAT_DIST_SAFE_VDY_c)
/*PRQA S 3432 1*/ /* date: 2019-05-15, reviewer: Schnurr, Clemens, reason: Macro does not work with paranthesis*/
FCT_DEF_FIX_PARAM(float32 , ESPM_MAX_LAT_DIST_SAFE_VDY_c ,   0.75f )

/*! @brief       max lateral displacement for the EBA VDY only performance distance
    @conseq      @incp  performance distance is getting higher \n
                 @decp  performance distance is getting lower \n
    @typical     2.5    @unit  [m]   @min 0   @max 10   */
SET_MEMSEC_CONST(ESPM_MAX_LAT_DIST_PERF_VDY_c)
/*PRQA S 3432 1*/ /* date: 2019-05-15, reviewer: Schnurr, Clemens, reason: Macro does not work with paranthesis*/
FCT_DEF_FIX_PARAM(float32 , ESPM_MAX_LAT_DIST_PERF_VDY_c ,   0.75f )

/*! @brief       max lateral displacement for the EBA ALN part of the fused performance distance. 
                 If the performance distance is below the min perf dist and ALN exceeds its quota. ALN is the error cause
    @conseq      @incp  it needs a higher ALN error to assign ALN as error cause \n
                 @decp  it needs a lower ALN error to assign ALN as error cause \n
    @typical     1.425f    @unit  [m]   @min 0   @max 10   */
SET_MEMSEC_CONST(ESPM_PERF_ALN_MAX_QUOTA_c)
/*PRQA S 3432 1*/ /* date: 2019-05-15, reviewer: Schnurr, Clemens, reason: Macro does not work with paranthesis*/
FCT_DEF_FIX_PARAM(float32 , ESPM_PERF_ALN_MAX_QUOTA_c ,   1.f )

/*! @brief       max lateral displacement for the EBA VDY part of the fused performance distance. 
                 If the performance distance is below the min perf dist and ALN exceeds its quota. ALN is the error cause
    @conseq      @incp  it needs a higher VDY error to assign VDY as error cause\n
                 @decp  it needs a lower VDY error to assign VDY as error cause \n
    @typical     1.025f    @unit  [m]   @min 0   @max 10   */
SET_MEMSEC_CONST(ESPM_PERF_VDY_MAX_QUOTA_c)
/*PRQA S 3432 1*/ /* date: 2019-05-15, reviewer: Schnurr, Clemens, reason: Macro does not work with paranthesis*/
FCT_DEF_FIX_PARAM(float32 , ESPM_PERF_VDY_MAX_QUOTA_c ,   0.75f )

///@}
#endif  /*!< ACDC_CFG_ESPM */

