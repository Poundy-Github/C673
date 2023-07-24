/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   ARS4xx

CPU:                       CPU-Independent

COMPONENT:                 SFL (Safety Functions Library)

PACKAGENAME:               sfl_circle.c

DESCRIPTION:               Functions for circle related calculations

AUTHOR:                    Danner Andreas (uid41765)

CREATION DATE:             21.09.2018

VERSION:                   $Revision: 1.7 $

**************************************************************************** */
#include "sfl_int.h"

#if (ACDC_CFG_SFL)
/************************************************************************/
/*                      Module Description                              */
/************************************************************************/
/**
  @defgroup sfl_circle Circle
  @ingroup sfl
  @brief        This module provides circle related calculation functions for the generic use in all safety function components. \n\n

  @description  The following functionalities are provided:
                - Check if a position is inside of a circle: @ref SFL_b_CheckPosInCircle
                - Calculate the intersection points of a position vector and a circle: @ref SFL_v_CircleIntersectWithVector
                - Calculate the arc length from 0 to a given position: @ref SFL_f_CircleCalcArcLengthAtPos
  @{
  */

/***********************************************************************
  FUNCTION DEFINITIONS
************************************************************************/
/*************************************************************************************************************************
  Functionname:         SFL_b_CheckPosInCircle                                                                       */ /*!

  @brief                Checks if a position is inside of a circle

  @description          Sets up a vector from the circle center to the position to check. Calculates the length 
                        of this vector. If the length is smaller than the circle radius, the position is inside of 
                        the circle.

  @return               boolean

  @param[in]            pCircle : Circle with position and radius.
  @param[in]            pPos :    Position to check.

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_SFL\n

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_SFL_B_CHECKPOSINCIRCLE_001 \n
                        @ref TEST_SFL_B_CHECKPOSINCIRCLE_002

  @traceability         Design Decision

  @author               Andreas Danner | Andreas.Danner@continental-corporation.com | +49 (8382) 9699-4995
*************************************************************************************************************************/
boolean SFL_b_CheckPosInCircle(SFLCircle_t   const * const pCircle,
                               SFLVector2D_t const * const pPos)
{
  boolean bIsInCircle;
  /* Get the length of the vector from the circle center to the position to check */
  float32 const fLengthDelta = SFL_f_GetVector2Length(SFL_s_SetupVector2(pPos->fX - pCircle->fX, pPos->fY - pCircle->fY));

  /* Check if the length is smaller than the radius */
  if(fLengthDelta < pCircle->fRadius)
  {
    bIsInCircle = b_TRUE;
  }
  else
  {
    bIsInCircle = b_FALSE;
  }
  return bIsInCircle;
}


/*************************************************************************************************************************
  Functionname:         SFL_v_CircleIntersectWithVector                                                              */ /*!

  @brief                Intersects a given position vector with a given circle.

  @description          Sets up a quadratic equation which describes the intersection of the circle with the position vector. 
                        Afterwards uses the function @ref SFL_v_SolveQuadrEquation to solve it. \n
                        Applies the found distances to the position vector to get the intersection positions.
                        The found intersection will be appended to the passed array.

  @return               void

  @param[in]            pCircle :         Circle with position and radius.
  @param[in]            pPosVector :      Position vector with Foot Point and line.
  @param[in,out]        aPosIntersect :   Array of intersection positions. The found intersections are appended to the array. 
                                          Thus,The array has to be initialized, before passing it to the function.
  @param[in,out]        piNofSolutions :  Number of found intersection positions. This variable has to be initialized before passing it to the function.

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_SFL\n

  @pre                  None
  @post                 None

  @InOutCorrelation     **Quadratic Equation**: \n
                        \f$C2 = X_{Line}^2 + Y_{Line}^2\f$ \n
                        \f$C1 = 2 \cdot (X_{Line} \cdot (X_{Foot} - X_{Circle}) + Y_{Line} \cdot (Y_{Foot} - Y_{Circle}))\f$ \n
                        \f$C0 = (X_{Foot} - X_{Circle})^2 + (Y_{Foot} + Y_{Circle})^2 - R^2\f$

  @testmethod           @ref TEST_SFL_V_CIRCLEINTERSECTWITHVECTOR_001 \n
                        @ref TEST_SFL_V_CIRCLEINTERSECTWITHVECTOR_002

  @traceability         Design Decision

  @author               Andreas Danner | Andreas.Danner@continental-corporation.com | +49 (8382) 9699-4995
*************************************************************************************************************************/
void SFL_v_CircleIntersectWithVector(SFLCircle_t              const * const pCircle,
                                     SFLPositionVector2D_t    const * const pPosVector,
                                     SFLVector2D_t                          aPosIntersect[],
                                     sint32                          * const piNofSolutions)
{
  
  SFLPolynomialSolutions_t Solutions;
  uint32 uSolNo;
  float32 const fC2           = SQR(pPosVector->Line.fX) + SQR(pPosVector->Line.fY);
  float32 const fC1           = 2.f * (   (pPosVector->Line.fX * (pPosVector->Foot.fX - pCircle->fX)) 
                                        + (pPosVector->Line.fY * (pPosVector->Foot.fY - pCircle->fY)) );
  float32 const fC0           = (SQR(pPosVector->Foot.fX - pCircle->fX) + SQR(pPosVector->Foot.fY - pCircle->fY)) - SQR(pCircle->fRadius);

  /* Calculate the distances on the position vector at which a intersection takes place */
  SFL_v_SolveQuadrEquation(fC2,fC1,fC0,&Solutions);

  /* Append the found solutions to the array aPosIntersect */
  for (uSolNo = 0; uSolNo < Solutions.uNofSolutions; ++uSolNo)
  {
    aPosIntersect[*piNofSolutions] = SFL_s_AddVector2(pPosVector->Foot,
                                                      SFL_s_MultiplyScalarVector(Solutions.afSolutions[uSolNo],pPosVector->Line));
    (*piNofSolutions)++;
  }

}


/*************************************************************************************************************************
  Functionname:         SFL_f_CircleCalcArcLengthAtPos                                                               */ /*!

  @brief                Calculates the ArcLength along a circle up to a given position.

  @description          Sets up a normed vector from the circle center to the given position. 
                        Calculates the angle by projecting this vector onto the circle radius.
                        Calculates the arcLength by means of the angle and the circle radius.
                        (see In-Out Correlation)

  @return               float32 : ArcLength at the given position

  @param[in]            pCircle : Circle with position and radius.
  @param[in]            pPos :    Position up to which the arc length shall be calculated. (Not necessarily on the circle)

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_SFL\n

  @pre                  None
  @post                 None

  @InOutCorrelation     
                        - **ArcLength**: \n
                        \f$\alpha = \arcsin(\frac{X}{R})\f$ \n
                        \f$ArcLength = \alpha \cdot R\f$

  @testmethod           @ref TEST_SFL_F_CIRCLECALCARCLENGTHATPOS_001 \n
                        @ref TEST_SFL_F_CIRCLECALCARCLENGTHATPOS_002

  @traceability         Design Decision

  @author               Andreas Danner | Andreas.Danner@continental-corporation.com | +49 (8382) 9699-4995
*************************************************************************************************************************/
float32 SFL_f_CircleCalcArcLengthAtPos(SFLCircle_t const * const pCircle,
                                       SFLVector2D_t const * const pPos)
{
  /*PRQA S 1031 1*//* 2018-09-24, reviewer: Andreas Danner, Initialization with non standard structures is allowed in ISO C99 */
  SFLVector2D_t const NormedVectorToPos = SFL_s_CalculateNormalizedVector(SFL_s_SetupVector2(pPos->fX - pCircle->fX,pPos->fY - pCircle->fY));
  float32 fArcLength;
  /* The normalized x-value is in the range [0:1] as it is normalized */
  float32 fAngle = ASIN_(NormedVectorToPos.fX);

  if(fAngle < 0.f)
  {
    fAngle = (2.f * CML_f_Pi) - fAngle;
  }
  fArcLength = fAngle * pCircle->fRadius;

  
  return fArcLength;
}



/*!@}*/
#endif /*ACDC_CFG_SFL*/
