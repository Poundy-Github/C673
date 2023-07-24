         /*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   ARS4xx

CPU:                       CPU-Independent

COMPONENT:                 SFL (Safety Functions Library)

PACKAGENAME:               sfl_vector.c

DESCRIPTION:               ACDC specific math functions

AUTHOR:                    Danner Andreas (uid41765)

CREATION DATE:             10.04.2018

VERSION:                   $Revision: 1.12 $

**************************************************************************** */

/************************************************************************
  INCLUDES
 ************************************************************************/
#include "sfl_int.h"

#if (ACDC_CFG_SFL)


/************************************************************************/
/*                      Module Description                              */
/************************************************************************/
/**
  @defgroup sfl_vector Vector
  @ingroup sfl
  @brief        This module provides vector calculation functions for the generic use in all safety function components. \n\n

  @description  The following functionalities are provided:
                - Get the length of a vector: @ref SFL_f_GetVector2Length
                - Set up a 2 dimensional vector: @ref SFL_s_SetupVector2
                - Normalize a given angle to the range of -pi to pi: @ref SFL_f_NormalizeRadiansToPi
                - Normalize a given angle to the range of 0 to 2*pi: @ref SFL_f_NormalizeRadiansToTwoPi
                - Normalize a given vector: @ref SFL_s_CalculateNormalizedVector
                - Calculate the angle of a vector: @ref SFL_f_CalcAngleFromVector
                - Calculate the gradient of a given angle: @ref SFL_f_CalcGradientFromAngle
                - Multiply a matrix with a vector: @ref SFL_s_MultiplyMatrixVector
                - Multiply a scalar with a vector: @ref SFL_s_MultiplyScalarVector

  @{
  */

/***********************************************************************
  MACROS
************************************************************************/
/*! @description  Maximum reachable Gradient to limit towards infinity.\n
                  @typical 10000.f, @unit []*/
#define SFL_VECTOR_GRADIENT_MAX                          (      10000.f)


/***********************************************************************
  FUNCTION DECLARATIONS
************************************************************************/

/*************************************************************************************************************************
  Functionname:         SFL_f_GetVector2Length                                                                       */ /*!

  @brief                Calculates the length of a given vector.

  @description          Calculates the length of a given vector by applying the formula that is given in the In-OutCorrelation.

  @return               float32 : Length of the vector. @phys_unit [m]

  @param[in]            Vector : Vector for which the length shall be calculated.

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_SFL\n

  @pre                  None
  @post                 None

  @InOutCorrelation     \f$Length = \sqrt{X^2 + Y^2}\f$

  @testmethod           @ref TEST_SFL_F_GETVECTOR2LENGTH_001
                       

  @traceability            Design Desision

  @author               Zijad Maksuti | Zijad.Maksuti@continental-automotive.com
*************************************************************************************************************************/
float32 SFL_f_GetVector2Length(SFLVector2D_t const Vector)
{
  float32 const fLength = SQRT(SQR(Vector.fX)+SQR(Vector.fY));

  return fLength;
}

/*************************************************************************************************************************
  Functionname:         SFL_s_SetupVector2                                                                           */ /*!

  @brief                Sets up a vector on base of a given X and a given Y value.

  @return               SFLVector2D_t : [X, Y]

  @param[in]            fX : Value for the vectors first dimension (= X)
  @param[in]            fY : Value for the vectors second dimension (= Y)

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_SFL\n

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_SFL_S_SETUPVECTOR2_001 
                        

  @traceability            Design Desision

  @author               Zijad Maksuti | Zijad.Maksuti@continental-automotive.com
*************************************************************************************************************************/
SFLVector2D_t SFL_s_SetupVector2(float32 const fX, float32 const fY)
{
  SFLVector2D_t tResult;

  tResult.fX = fX;
  tResult.fY = fY;

  return tResult;
}

/*************************************************************************************************************************
  Functionname:         SFL_s_AddVector2                                                                           */ /*!

  @brief                Adds two vectors.

  @return               SFLVector2D_t : [X, Y]

  @param[in]            Vector1 : First vector.
  @param[in]            Vector2 : Second vector.

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_SFL\n

  @pre                  None
  @post                 None

  @InOutCorrelation     \f$\begin{bmatrix} X \\ Y \end{bmatrix} = \begin{bmatrix} X_1 + X_2 \\ Y_1 + Y_2 \end{bmatrix}\f$

  @testmethod           @ref TEST_SFL_S_ADDVECTOR2_001 
                        

  @traceability          Design Desision

  @author               Zijad Maksuti | Zijad.Maksuti@continental-automotive.com
*************************************************************************************************************************/
SFLVector2D_t SFL_s_AddVector2(SFLVector2D_t const Vector1,
                               SFLVector2D_t const Vector2)
{
  SFLVector2D_t sum;
  sum.fX = Vector1.fX + Vector2.fX;
  sum.fY = Vector1.fY + Vector2.fY;
  return sum;
}

/*************************************************************************************************************************
  Functionname:         SFL_s_SubVector2                                                                           */ /*!

  @brief                Subtracts vector 2 from vector 1.

  @return               SFLVector2D_t : [X, Y]

  @param[in]            Vector1 : First vector.
  @param[in]            Vector2 : Vector to be subtracted from the first vector.

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_SFL\n

  @pre                  None
  @post                 None

  @InOutCorrelation     \f$\begin{bmatrix} X \\ Y \end{bmatrix} = \begin{bmatrix} X_1 - X_2 \\ Y_1 - Y_2 \end{bmatrix}\f$

  @testmethod           @ref TEST_SFL_S_SUBVECTOR2_001

@traceability            Design Desision

  @author               Zijad Maksuti | Zijad.Maksuti@continental-automotive.com
*************************************************************************************************************************/
SFLVector2D_t SFL_s_SubVector2(SFLVector2D_t const Vector1,
                               SFLVector2D_t const Vector2)
{
  SFLVector2D_t result;
  result.fX = Vector1.fX - Vector2.fX;
  result.fY = Vector1.fY - Vector2.fY;
  return result;
}

/*************************************************************************************************************************
  Functionname:         SFL_f_NormalizeRadiansToPi                                                                   */ /*!

  @brief                Normalizes a given angle to the interval [-pi; pi[.

  @return               float32 : Normalized Angle

  @param[in]            fAngleRadians : Angle to be normalized. @phys_unit [rad]

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_SFL\n

  @pre                  None
  @post                 None

  @InOutCorrelation     \f$\alpha_{Norm} = \alpha - (2 \pi \cdot floor(\frac{\alpha + \pi}{2 \pi}))\f$

  @testmethod           @ref TEST_SFL_F_NORMALIZERADIANSTOPI_001

  @author               Zijad Maksuti | Zijad.Maksuti@continental-automotive.com
*************************************************************************************************************************/
float32 SFL_f_NormalizeRadiansToPi(const float32 fAngleRadians)
{
  const float32 fReturn = fAngleRadians - (CML_f_two_Pi*CML_f_Floor((fAngleRadians+CML_f_Pi)/CML_f_two_Pi));

  return fReturn;
}

/*************************************************************************************************************************
  Functionname:         SFL_f_NormalizeRadiansToTwoPi                                                                   */ /*!

  @brief                Normalizes a given angle to the interval [0; 2*pi[.

  @description          Normalizes a given angle to the interval [0; 2*pi[ by
                        first normalizing it to the interval [-pi; pi[ with
                        \ref SFL_f_NormalizeRadiansToPi and then
                        adding pi if the intermediate result is smaller than 0.

  @return               float32 : Normalized angle.

  @param[in]            fAngleRadians : Angle to be normalized. @phys_unit [rad]

  @glob_in              \ref SFL_f_NormalizeRadiansToPi
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_SFL\n

  @pre                  None
  @post                 None

  @InOutCorrelation     See description.

  @testmethod           @ref TEST_SFL_f_NormalizeRadiansToTwoPi_001 \n
                        @ref TEST_SFL_f_NormalizeRadiansToTwoPi_002

  @author               Zijad Maksuti | Zijad.Maksuti@continental-automotive.com
*************************************************************************************************************************/
float32 SFL_f_NormalizeRadiansToTwoPi(const float32 fAngleRadians)
{
  const float32 fTemp = SFL_f_NormalizeRadiansToPi(fAngleRadians);

  const float32 fReturn = (fTemp >= 0.f)? fTemp : (fTemp + CML_f_two_Pi);

  return fReturn;
}

/*************************************************************************************************************************
  Functionname:         SFL_s_CalculateNormalizedVector                                                              */ /*!

  @brief                Normalizes a given vector to the length 1.

  @description          Normalized copy of pVector. If the length of the given vector is 0, the function returns a
                        Null-Vector.

  @return               SFLVector2D_t : Normalized Vector

  @param[in]            Vector : Vector to be normalized.

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_SFL\n

  @pre                  None
  @post                 None

  @InOutCorrelation     \f$\vec{V_{Norm}} = \begin{bmatrix} \frac{V_1}{|\vec{V}|} \\ \frac{V_2}{|\vec{V}|} \end{bmatrix}\f$

  @testmethod           @ref TEST_SFL_S_CALCULATENORMALIZEDVECTOR_001 \n
                        @ref TEST_SFL_S_CALCULATENORMALIZEDVECTOR_002

  @traceability            Design Desision

  @author               Zijad Maksuti | Zijad.Maksuti@continental-automotive.com
*************************************************************************************************************************/
SFLVector2D_t SFL_s_CalculateNormalizedVector(SFLVector2D_t const Vector)
{
  SFLVector2D_t result;
  const float32 fVectorsLength = SFL_f_GetVector2Length(Vector);

  if(CML_f_IsZero(fVectorsLength))
  {
    result = SFL_s_SetupVector2(0.0f, 0.0f);
  }else
  {
    result = SFL_s_SetupVector2(Vector.fX/fVectorsLength, Vector.fY/fVectorsLength);
  }

  return result;
}

/*************************************************************************************************************************
  Functionname:         SFL_f_CalcAngleFromVector                                                                       */ /*!

  @brief                Calculates the orientation of a given vector.

  @description          Calculates an angle based on a given 2 dimensional vector. The heading of the vector is
                        NOT considered. The returned angle describes always the smallest possible angle to 0. \n
                        If a different behavior is desired, use @ref ATAN2_ instead of @ref ATAN_. The current
                        implementation is required for the ObjectCircle calculation (see @ref EMP_v_CalcObjectCircles).
                        @startuml SFL_f_CalcAngleFromVector_activity.png
                        start
                          if(Vectors X Coordinate is NOT 0?) then (Yes)
                            :1}
                            :Calculate Angle;
                            note left: >see Formula "Calculate Angle"
                          elseif(Vectors Y Coordinate is > 0?) then (Yes)
                            :2}
                            :Angle is 0.5 * pi;
                          elseif(Vectors Y Coordinate is < 0?) then (Yes)
                            :3}
                            :Angle is -0.5 * pi;
                          else (No)
                            :4}
                            :Angle is 0;
                          endif
                        stop
                        @enduml

  @return               float32: Orientation Angle. @unit [rad], @range [-0.5 * pi, + 0.5 * pi]

  @param[in]            fX        : Extension in X-Direction of the Vector.
  @param[in]            fY        : Extension in Y-Direction of the Vector.
  @param[in]            bUseATAN2 : Flag indicating if the atan2 (TRUE) or the atan (FALSE) shall be used for the calculation of the angle.

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_SFL\n

  @InOutCorrelation     - **Formula Calculate Angle:** \n
                          \f$ Angle = \tan^{-1}(\frac{Y}{X})\f$

  @TESTmethod            @ref TEST_SFL_F_CALCANGLEFROMVECTOR_001 \n
                         @ref TEST_SFL_F_CALCANGLEFROMVECTOR_002 \n
                         @ref TEST_SFL_F_CALCANGLEFROMVECTOR_003 \n
                         @ref TEST_SFL_F_CALCANGLEFROMVECTOR_004 \n
                         @ref TEST_SFL_F_CALCANGLEFROMVECTOR_005 \n
                         @ref TEST_SFL_F_CALCANGLEFROMVECTOR_006 \n
                         @ref TEST_SFL_F_CALCANGLEFROMVECTOR_007 \n
                         @ref TEST_SFL_F_CALCANGLEFROMVECTOR_008

  @traceability            Design Desision

  @remark               The Angle returned by this function does not consider the vectors direction and only refers
                        to a range from -0.5 * pi to 0.5 * pi. If this would be required, add ATAN2_ and a flag to
                        switch between the two forms of calculation.

  @author               Andreas Danner | Andreas.Danner@continental-corporation.com | +49 (8382) 9699-4995
*************************************************************************************************************************/
float32 SFL_f_CalcAngleFromVector(float32 fX, float32 fY, boolean bUseATAN2)
{
  float32 fAngle = 0.f;

  if(bUseATAN2 == b_TRUE)
  {
    fAngle = ATAN2_(fY,fX);
  }
  /* Secure ATAN against Div by 0*/
  else if(fABS(fX) > C_F32_DELTA)
  {
    fAngle = ATAN_(fY/fX);
  }
  /* Check Sign of the Y coordinate to determine the sign of the default value */
  else if (fY > C_F32_DELTA)
  {
    fAngle = 0.5f * CML_f_Pi;
  }
  else if (fY < -C_F32_DELTA)
  {
    fAngle = -0.5f * CML_f_Pi;
  }
  /* If no significant sign can be found, set angle as 0 */
  else
  {
    fAngle = 0.f;
  }
  return fAngle;
}

/*************************************************************************************************************************
  Functionname:         SFL_f_CalcGradientFromAngle                                                                     */ /*!

  @brief                Calculates a gradient of an angle.

  @description          Converts a given angle into a gradient. The gradient is calculated over the x-axis.
                        @startuml SFL_f_CalcGradientFromAngle_activity.png
                        start
                          if(Angle is close to 90 or -90 degree?) then (Yes)
                            :1}
                            :Set Gradient to default value EMP_GRADIENT_MAX,
                            Set the sign according to the angles sign;
                          else (No)
                            :2}
                            :Gradient = TAN(Angle);
                          endif
                        stop
                        @enduml

  @return               float32 : calculated gradient

  @param[in]            fAngle : Angle for which the gradient shall be calculated. @phys_unit [rad], @range]-...,+...[

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_SFL\n

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @testmethod             @ref TEST_SFL_F_CALCGRADIENTFROMANGLE_001 \n
                          @ref TEST_SFL_F_CALCGRADIENTFROMANGLE_002 \n

  @traceability            Design Desision

  @author               Andreas Danner | Andreas.Danner@continental-corporation.com | +49 (8382) 9699-4995
*************************************************************************************************************************/
float32 SFL_f_CalcGradientFromAngle(float32 fAngle)
{
  float32 fGradient;

  if(fABS(CML_Deg2Rad(90.0f) - fABS(fAngle)) < C_F32_DELTA)
  {
    /*Falling gradient for positive orientation, rising gradient for negative in case Orientation is close to +-90°*/
    fGradient = SFL_VECTOR_GRADIENT_MAX * (float32)CML_f_Sign(fAngle);
  }
  else
  {
    fGradient = TAN_(fAngle);
  }

  /*Limit the gradient to Min/Max Gradient. Limits can possibly be exceeded in case of small angles.*/
  fGradient = MINMAX(-SFL_VECTOR_GRADIENT_MAX, SFL_VECTOR_GRADIENT_MAX, fGradient);

  return fGradient;
}

/*************************************************************************************************************************
  Functionname:         SFL_s_MultiplyMatrixVector                                                                   */ /*!

  @brief                Multiplies a given Matrix with a given vector.

  @description          Multiplies a given Matrix with a given vector by using the function @ref CML_v_TransformPosition2D.

  @return               SFLVector2D_t : Product of the Matrix and the vector.

  @param[in]            pMatrix : Matrix to be multiplied.
  @param[in]            pVector : Vector to be multiplied.

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_SFL\n

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_SFL_S_MULTIPLYMATRIXVECTOR_001

  @author               Zijad Maksuti | Zijad.Maksuti@continental-automotive.com
*************************************************************************************************************************/
SFLVector2D_t SFL_s_MultiplyMatrixVector(CML_t_TrafoMatrix2D const *const pMatrix,
                                         SFLVector2D_t       const *const pVector)
{
  SFLVector2D_t tResult;

  tResult = SFL_s_SetupVector2(pVector->fX, pVector->fY);
  CML_v_TransformPosition2D(pMatrix, &tResult.fX, &tResult.fY);

  return tResult;
}

/*************************************************************************************************************************
  Functionname:         SFL_s_MultiplyScalarVector                                                                   */ /*!

  @brief                Multiplies a given scalar with a given vector.

  @description          Multiplies a given scalar s with a given vector (v.x, v.y) by calculating (a*v.x, a*v.y).

  @return               SFLVector2D_t : Product of the scalar and the vector.

  @param[in]            fScalar : Scalar to be multiplied.
  @param[in]            Vector : Vector to be multiplied.

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_SFL\n

  @pre                  None
  @post                 None

  @InOutCorrelation     \f$\binom{x_1}{y_1} = \binom{s \cdot x_0}{s \cdot y_0}\f$

  @testmethod           @ref TEST_SFL_S_MULTIPLYSCALARVECTOR_001

  @traceability            Design Desision

  @author               Zijad Maksuti | Zijad.Maksuti@continental-automotive.com
*************************************************************************************************************************/
SFLVector2D_t SFL_s_MultiplyScalarVector(float32 const fScalar, SFLVector2D_t const Vector)
{
  return SFL_s_SetupVector2(fScalar * Vector.fX, fScalar * Vector.fY);
}


/*************************************************************************************************************************
  Functionname:         SFL_b_IntersectPositionVectors                                                                           */ /*!

  @brief                Calculate the point at which two vectors intersect.

  @description          If both vectors are valid and not parallel (verified by the cross product), the
                        intersection point is calculated by applying the steps shown in In-Out-Correlation.

  @return               boolean : Flag indicating whether the two vectors intersect (True) or not (False).

  @param[in]            pPosVector1   : A vector.
  @param[in]            pPosVector2   : Vector for which the intersection point with vector 1 shall be found.
  @param[in,out]        pPosIntersect : Coordinates of the intersection position

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_USE_EBA_BOX_OBJECTS \n
                        @ref ACDC_CFG_EMP \n
                        @ref ACDC_CFG_CD \n
                        @ref ACDC_CFG_FRAME\n

  @pre                  None
  @post                 None

  @InOutCorrelation
                        1. **Assumption:**\n
                        \f$\begin{bmatrix}A_{0,x}\\A_{0,y}\end{bmatrix} + \lambda \cdot \begin{bmatrix}A_x\\A_y\end{bmatrix}
                        =  \begin{bmatrix}B_{0,x}\\B_{0,y}\end{bmatrix} + \sigma  \cdot \begin{bmatrix}B_x\\B_y\end{bmatrix}\f$
                        2. **Equations:** \n
                        \f$ A_{0,x} + \lambda \cdot A_x = B_{0,x} + \sigma \cdot B_x \f$ \n
                        \n
                        \f$ A_{0,y} + \lambda \cdot A_y = B_{0,y} + \sigma \cdot B_y \f$
                        3. **Calculate Factor for Position Vector 1:** \n
                        \f$ \sigma = \frac{A_{0,y}+\lambda\cdot A_y-B_{0,y}}{B_y}\f$ \n
                        => \f$ \lambda = \frac{B_{0,y}B_y-A_{0,y}B_y+A_{0,y}B_x-B_{0,y}B_x}{A_xB_y-A_yB_x} \f$
                        4. **Insert** \f$\lambda\f$ **in equation of position vector 1:** \n
                        \f$\begin{bmatrix}Intersect_x\\Intersect_y\end{bmatrix} =\begin{bmatrix}A_{0,x}\\A_{0,y}\end{bmatrix} +
                        \lambda \cdot \begin{bmatrix}A_x\\A_y\end{bmatrix}\f$

  @testmethod           @ref TEST_SFL_B_INTERSECTPOSITIONVECTORS_001 \n
                        @ref TEST_SFL_B_INTERSECTPOSITIONVECTORS_002


  @traceability         Design Desision

  @author               Christian Obst
*************************************************************************************************************************/
boolean SFL_b_IntersectPositionVectors(SFLPositionVector2D_t const * const pPosVector1,
                                       SFLPositionVector2D_t const * const pPosVector2,
                                       SFLVector2D_t               * const pPosIntersect)
{
  boolean       bIntersectionFound = b_FALSE;
  float32 const fCrossProduct      = SFL_f_Vector2CrossProduct(pPosVector1->Line, pPosVector2->Line);

  if ( CML_f_IsNonZero( fCrossProduct ))
  {
    /*Vectors are not parallel*/
    float32 fs1 = (   (   (   ( pPosVector2->Line.fY * ( pPosVector2->Foot.fX - pPosVector1->Foot.fX )   )
                            - ( pPosVector2->Line.fX * pPosVector2->Foot.fY                              ) )
                        + (     pPosVector2->Line.fX * pPosVector1->Foot.fY                                ) )
                    / (         fCrossProduct                                                                ) );

    pPosIntersect->fX = ( pPosVector1->Foot.fX + ( fs1 * pPosVector1->Line.fX ) );
    pPosIntersect->fY = ( pPosVector1->Foot.fY + ( fs1 * pPosVector1->Line.fY ) );
    bIntersectionFound = b_TRUE;
  }
  else
  {
    pPosIntersect->fX = ACDC_DIST_DEFAULT;
    pPosIntersect->fY = ACDC_DIST_DEFAULT;
  }
  return bIntersectionFound;
}

/*************************************************************************************************************************
  Functionname:         SFL_s_SetupPositionVector2                                                                   */ /*!

  @brief                Sets up a position vector with a foot and a line vector.

  @return               SFLPositionVector2D_t

  @param[in]            FootVector : Vector to the foot of the position vector
  @param[in]            LineVector : Line of the position vector

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_SFL\n

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @testmethod             @ref TEST_SFL_S_SETUPPOSITIONVECTOR2_001

  @traceability            Design Desision

  @author               Andreas Danner | Andreas.Danner@continental-corporation.com | +49 (8382) 9699-4995
*************************************************************************************************************************/
SFLPositionVector2D_t SFL_s_SetupPositionVector2(SFLVector2D_t const FootVector,
                                                 SFLVector2D_t const LineVector)
{
  SFLPositionVector2D_t PosVector;
  PosVector.Foot = FootVector;
  PosVector.Line = LineVector;
  return PosVector;
}

/*************************************************************************************************************************
  Functionname:         SFL_f_Vector2CrossProduct                                                                     */ /*!

  @brief                Calculates the cross product of two given 2 dimensional vectors

  @return               float32

  @param[in]            Vector1 : First vector.
  @param[in]            Vector2 : Second vector.

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_SFL\n

  @pre                  None
  @post                 None

  @InOutCorrelation     **Cross product:**\n
                        \f$c = X_1 \cdot Y_2 - X_2 \cdot Y_1\f$

  @testmethod             @ref TEST_SFL_F_VECTOR2CROSSPRODUCT_001

  @traceability            Design Desision

  @author               Andreas Danner | Andreas.Danner@continental-corporation.com | +49 (8382) 9699-4995
*************************************************************************************************************************/
float32 SFL_f_Vector2CrossProduct(SFLVector2D_t const Vector1, SFLVector2D_t const Vector2)
{
  return ((Vector1.fX * Vector2.fY) - (Vector2.fX * Vector1.fY ));
}

/*!@}*/
#endif /* ACDC_CFG_SFL */

