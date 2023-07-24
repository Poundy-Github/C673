/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG
  
PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 EMP - Environment Model Prediction

PACKAGENAME:               emp_int.h

DESCRIPTION:               internal header of EMP

AUTHOR:                    $Author: uidn4751 $

CREATION DATE:             $Date: 2019/06/03 15:28:53CEST $

VERSION:                   $Revision: 1.19 $
**************************************************************************** */
#ifndef EMP_INT_INCLUDED
#define EMP_INT_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "acdc_int.h"

#if(ACDC_CFG_EMP)
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
\addtogroup emp
\{
*/


/***********************************************************************
      MACROS                                                           
************************************************************************/

/*****************************************************************************
  PUBLIC FUNCTIONS
*****************************************************************************/
extern boolean EMPCalcObjExDesc(float32 fTime, ACDCObjPred_t const *const pIn_Obj, EMPObjExDesc_t *const pOut_ExistenceDesc );
extern boolean EMPCalcCollProbExDesc(EMPObjExDesc_t const *const pIn_ExDescObj1, EMPObjExDesc_t const *const pIn_ExDescObj2, float32 *const pOut_CollisionProb );
extern float32 EMPCalcVariance( const float32 afValues[], uint16 uiArraySize );
extern void    EMP_v_CalcObjectCircles(ObjNumber_t const iObjectIndex, ACDCObjectCircleData_t * const pCircleData);
#endif /* ACDC_CFG_EMP */

#endif /* EMP_INT_INCLUDED */

///\}

