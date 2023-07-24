/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   ARS4xx

CPU:                       CPU-Independent

COMPONENT:                 EMP - Environment Model Prediction

PACKAGENAME:               emp_objcircles.h

DESCRIPTION:               Functions for the description of the objects shape by circles

AUTHOR:                    Danner Andreas (uid41765)

CREATION DATE:             01.03.2018

VERSION:                   $Revision: 1.9 $

**************************************************************************** */
#ifndef EMP_OBJCIRCLES_H_INCLUDED
#define EMP_OBJCIRCLES_H_INCLUDED

/************************************************************************/
/* INCLUDES                                                             */
/************************************************************************/
#include "emp_int.h"

#if (ACDC_CFG_EMP)
/************************************************************************/
/* MODULE DESCRIPTION                                                   */
/************************************************************************/
/*!
  @defgroup emp_objcircles Object Circles
  @ingroup emp

  @brief          The object circles module calculates circles to describe the objects shape.\n\n

  @description    Circles are used to calculate a circle based description of the objects shape points. 
                  On base of these circles the DistToTrajMax and the DistToTrajMin are calculated.
                  The functionalities provided by this module are:
                  - Calculation of circles with the minimum and the maximum distance to trajectory: @ref EMP_v_CalcObjectCircles
                  - Calculation of the number of circle that are required to describe an object entirely 
                    (= usually defined by the the ratio of width and length): @ref EMP_v_CalcNumofCircles
                  - Calculation of the nth circle inside an object: @ref EMP_v_CalculateCurrentCircle
  @{
  */
/************************************************************************/
/* MACROS                                                               */
/************************************************************************/

/************************************************************************/
/* TYPEDEFS                                                             */
/************************************************************************/


/*!@}*/

#endif /* ACDC_CFG_EMP */
#endif /* EMP_OBJCIRCLES_H_INCLUDED */

