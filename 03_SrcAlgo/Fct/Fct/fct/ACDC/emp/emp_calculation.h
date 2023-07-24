/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG
  
PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 EMP - Environment Model Prediction

PACKAGENAME:               emp_calculation.h

DESCRIPTION:               heade file for EMP

AUTHOR:                    $Author: uidn4751 $

CREATION DATE:             $Date: 2019/06/03 15:28:51CEST $

VERSION:                   $Revision: 1.10 $
**************************************************************************** */

#ifndef EMP_CALCULATION_H_INCLUDED
#define EMP_CALCULATION_H_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "emp_int.h"

#if ( ACDC_CFG_EMP )
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
@defgroup emp_calculation Calculation
@ingroup emp
 
 @brief The EMP calculation module provides functions for simple kinematic calculations towards the emp_main module as soon as towards cd.\n\n

 This function category is provided in the module Calculation:
 - **Common functions** can be used in all subcomponents inside of ACDC. They are as generic as possible:\n
      @ref EMPCalcMinDistTime          \n
      @ref EMPCalcObjObjDistAtTime     \n
      @ref EMPCalcPositionAtTime       \n
      @ref EMPCalcVariance             \n
 - **Specific Functions** are outsourced parts of a mayor function. Their implementation is specialized on only one purpose: \n
      @ref EMPCalcObjExDesc     \n
      @ref EMPCalcCollProbExDesc
  @{
*/



/*****************************************************************************
  (SYMBOLIC) CONSTANTS
*****************************************************************************/

/*****************************************************************************
  MACROS 
*****************************************************************************/


/*****************************************************************************
  LOCAL VARIABLES
*****************************************************************************/



/*****************************************************************************
  LOCAL FUNCTIONS
*****************************************************************************/



/*!@}*/
#endif /* ACDC_CFG_EMP */
#endif /* EMP_CALCULATION_H_INCLUDED */
