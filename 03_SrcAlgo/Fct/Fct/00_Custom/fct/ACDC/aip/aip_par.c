/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG
  
PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 AIP (ACDC Input Processing)

PACKAGENAME:               aip_par.c

DESCRIPTION:               parameter for the ACDC Input Processing module

AUTHOR:                    $Author: uidn4751 $

CREATION DATE:             $Date: 2019/06/03 16:53:33CEST $

VERSION:                   $Revision: 1.5 $
**************************************************************************** */


/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "aip_int.h"
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/*!
@addtogroup aip_par
@{
*/

#if (ACDC_CFG_USE_ADD_OFFSET_SIMU)
/*! @brief      Simulate additional longitudinal offset, used to fake shorter distance 
                for the hypothesis calculation
    @conseq     @incp  (+) increase long. object distance
                @decp  (-) decrease long. object distance
    @attention  Activation thresholds on end function are not affected
    @typical    0.0    @unit  m   @min -50.0   @max 50.0   */
SET_MEMSEC_VAR(ACDC_LONG_OFFSET_SIMU)
/*PRQA S 3432 1*/ /* date: 2019-05-15, reviewer: Schnurr, Clemens, reason: Macro does not work with paranthesis*/
ACDC_DEF_PARAM(float32, ACDC_LONG_OFFSET_SIMU, ACDC_LONG_OFFSET_SIMU_DEFAULT)

/*! @brief      Simulate additional lateral offset, used to fake shorter distance 
                for the hypothesis calculation
    @conseq     @incp  (+) shift object to left direction
                @decp  (-) shift object to right direction
    @attention  Consider field of view limitation, thus, parameter is only effective
                in conjunction width longitudinal offset and track width factor
    @typical    0.0    @unit  m   @min -5.0   @max 5.0   */
SET_MEMSEC_VAR(ACDC_LAT_OFFSET_SIMU)
/*PRQA S 3432 1*/ /* date: 2019-05-15, reviewer: Schnurr, Clemens, reason: Macro does not work with paranthesis*/
ACDC_DEF_PARAM(float32, ACDC_LAT_OFFSET_SIMU, ACDC_LAT_OFFSET_SIMU_DEFAULT)
#endif

///@}
