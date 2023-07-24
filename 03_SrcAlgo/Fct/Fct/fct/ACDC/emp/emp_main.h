/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG
  
PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 EMP - Environment Model Prediction

PACKAGENAME:               emp_main.h

DESCRIPTION:               header file of the EMP process

AUTHOR:                    $Author: uidn4751 $

CREATION DATE:             $Date: 2019/06/03 15:28:54CEST $

VERSION:                   $Revision: 1.16 $
**************************************************************************** */

#ifndef EMP_MAIN_H_INCLUDED
#define EMP_MAIN_H_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/
/* EMP Includes */
#include "emp_int.h"

#if (ACDC_CFG_EMP)

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
\defgroup emp_main Main
  \ingroup emp

  \brief  EMP Main provides functions for the prediction of ego and object movements and for the calculation of criticality attributes.\n\n

  The following are the externally provided functionalities of the EMP Main module: \n
- **Criticality classificator functions**: 
  - *Collision Probability*: \n
  Calculates the probability for a collision between two objects. It is calculated by the function \ref EMPCalcCollProbObjObj.
  - *Trajectory Relation*: \n
  Specifies at which distance and with which velocity a object behaves in relation to the ego vehicles trajectory. It is calculated by the  \n
  function \ref EMP_v_CalcObjToEgoTrajRelation
  .
- **Initialization functions**:
  - *Reset Trajectory Prediction*: \n
  If an object gets deleted, at the same time its trajectory prediction has to be initialized. Therefore the function \ref EMPResetTrajPred is provided.
  .
- **Trajectory prediction functions**:
  - *Object trajectory calculation*: \n
  Predicts the trajectory of an object based on its current kinematics (\ref EMPPredictObjTraj).
  - *Ego trajectory calculation*: \n
  Predicts the trajectory of the ego vehicle based on its current kinematics (\ref EMPPredictEgoTraj).

  \{
  */
/*****************************************************************************
  MACROS 
*****************************************************************************/



/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/

/*!@}*/

#endif /* ACDC_CFG_EMP */

#endif /* EMP_MAIN_H_INCLUDED */

