/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   ARS4xx

CPU:                       CPU-Independent

COMPONENT:                 SFL (Safety Functions Library)

PACKAGENAME:               sfl_ext.h

DESCRIPTION:               Functions for the generic use in the safety function components.

AUTHOR:                    Almalih Ayman (uid6193)

CREATION DATE:             03.12.2018

VERSION:                   $Revision: 1.22 $

**************************************************************************** */
#ifndef SFL_EXT_H_INCLUDED
#define SFL_EXT_H_INCLUDED

/************************************************************************
  INCLUDES
 ************************************************************************/
#include "acdc_par.h"

#if (ACDC_CFG_SFL)

/******************************************************************************
  sfl parameters
******************************************************************************/
/*! @brief       SFL_QUAD_EQU_SOLUTION_ARRAY_SIZE
    @general     Array size for the solution of equations solved by the functions @ref SFL_v_SolveQuadrEquation and @ref SFL_v_SolveCubicEquation
*/
#define SFL_QUAD_EQU_SOLUTION_ARRAY_SIZE    (2u)
#define SFL_CUBE_EQU_SOLUTION_ARRAY_SIZE    (3u)


/*! @brief      Minimum valid coefficient value for the functions @ref SFL_v_SolveQuadrEquation and @ref SFL_v_SolveCubicEquation
    @general    Due to experienced effects (Big deviation of the Ref point on trajectory due to a limitation to C_F32_DELTA)
                the minimum limit should not be C_F32_DELTA.
                Neither should it be CML_f_AlmostZero, as this can lead to floating point exceptions in the further calculations.*/
#define SFL_COEFFICIENT_MINIMUM            (0.000001f)

#define SFL_TRAJOCC_MAX_NOF_LINES         200u   /*!< size of afTimeList (array of timestamps for SFL computation) */
#define SFL_TRAJOCC_MAX_TIME              5.f    /*!< largest time considered in SFL calculations, @phys_unit: s */
#define SFL_TRAJOCC_STEP_SIZE_TIME        0.06f  /*!< time discretization constant for SFL calculations, @phys_unit: s */
#define SFL_TRAJOCC_MAX_NOF_TIME_STEPS    (83u)  /*!< size of afDeclarations (array describing the deceleration profile) value is (uint8)(SFL_TRAJOCC_MAX_TIME/SFL_TRAJOCC_STEP_SIZE_TIME)) */
#define SFL_TIME_MAX                      40.f   /*!< default time for TTB and TTC, @phys_unit: s */
/************************************************************************
  TYPEDEFS
 ************************************************************************/
typedef struct SFLTrajOccupancy{
  uint8   uNofLines;
  float32 fMinDistances[SFL_TRAJOCC_MAX_NOF_LINES];
  float32 fMaxDistances[SFL_TRAJOCC_MAX_NOF_LINES];
  uint8   uTimeAccessTable[SFL_TRAJOCC_MAX_NOF_TIME_STEPS];
}SFLTrajOccupancy_t;

/*! @brief Structure used for defining a line (including vertical lines), described by a linear equation of the form: \n \f$A \cdot x + B \cdot y = C \f$   */
typedef struct SFLLine{
  float32 fA;
  float32 fB;
  float32 fC;
} SFLLine_t;

/*! @brief Structure used for defining a polynomial of first degree: \n \f$C_1 \cdot x + C_0 \f$   */
typedef struct SFLPolyDeg1{
  float32 fC0;                /*!< Coefficient 0 of first degree polynomial: distance constant\n     \f$s = C_0 \f$*/
  float32 fC1;                /*!< Coefficient 1 of first degree polynomial: velocity constant\n     \f$v = C_1 \f$*/ 
} SFLPolyDeg1_t;

/*! @brief Structure used for defining a polynomial of second degree: \n \f$C_2 \cdot x^2 + C_1 \cdot x + C_0 \f$   */
typedef struct SFLPolyDeg2
{
  float32 fC2;                /*!< Coefficient 2 of second degree polynomial: acceleration constant\n \f$0.5\cdot a = C_2 \f$*/ 
  float32 fC1;                /*!< Coefficient 1 of second degree polynomial: velocity constant\n     \f$v = C_1 \f$*/ 
  float32 fC0;                /*!< Coefficient 0 of second degree polynomial: distance constant\n     \f$s = C_0 \f$*/
} SFLPolyDeg2_t;

/*! @brief Two dimensional vector: \f$ \begin{bmatrix}x\\y\end{bmatrix} \f$ */
typedef struct SFLVector2D{
  float32 fX;                 /*!< X Coordinate of the Vector*/
  float32 fY;                 /*!< Y Coordinate of the Vector*/
}SFLVector2D_t;

/*! @brief Position Vector to describe a vector with a foot position: \f$ \begin{bmatrix}x_0\\y_0\end{bmatrix} + \lambda \cdot \begin{bmatrix}x\\y\end{bmatrix} \f$ */
typedef struct SFLPositionVector2D{
  SFLVector2D_t Foot;                 /*!< Foot position of the position vector*/
  SFLVector2D_t Line;                 /*!< Line of the position vector*/
}SFLPositionVector2D_t;

/*! @brief Structure to describe a two dimensional movement with velocity and acceleration */
typedef struct SFLMovement{
  SFLVector2D_t Vel;              /*!< Velocity in X and Y direction*/
  SFLVector2D_t Accel;            /*!< Acceleration in X and Y direction*/
}SFLMovement_t;

/*! @brief  Structure to describe the results of a polynomial up to third degree*/
typedef struct SFLPolynomialSolutions{
  float32 afSolutions[SFL_CUBE_EQU_SOLUTION_ARRAY_SIZE]; /*!< Array containing all non complex solutions*/
  uint8   uNofSolutions;                                 /*!< Number of valid solutions */
}SFLPolynomialSolutions_t;


typedef struct SFLCircle{
  float32 fX;
  float32 fY;
  float32 fRadius;
}SFLCircle_t;

#ifdef PRQA_SIZE_T
  /* Switch off QA-C warnings on side effects for functions, which don't have 
     any side effects and will sure never have some. */
#pragma PRQA_NO_SIDE_EFFECTS SFL_s_SetupVector2
#pragma PRQA_NO_SIDE_EFFECTS SFL_s_SubVector2
#pragma PRQA_NO_SIDE_EFFECTS SFL_s_AddVector2
#pragma PRQA_NO_SIDE_EFFECTS SFL_f_GetVector2Length
#pragma PRQA_NO_SIDE_EFFECTS SFL_f_NormalizeRadiansToPi
#pragma PRQA_NO_SIDE_EFFECTS SFL_f_NormalizeRadiansToTwoPi
#pragma PRQA_NO_SIDE_EFFECTS SFL_s_CalculateNormalizedVector
#pragma PRQA_NO_SIDE_EFFECTS SFL_f_CalcAngleFromVector
#pragma PRQA_NO_SIDE_EFFECTS SFL_f_CalcGradientFromAngle
#pragma PRQA_NO_SIDE_EFFECTS SFL_s_MultiplyScalarVector
#pragma PRQA_NO_SIDE_EFFECTS SFL_b_CheckPosInCircle
#pragma PRQA_NO_SIDE_EFFECTS SFL_f_CircleCalcArcLengthAtPos

#endif

/*--- sfl_vector.c ---*/
extern SFLVector2D_t SFL_s_SetupVector2(float32 const fX, float32 const fY);
extern SFLVector2D_t SFL_s_SubVector2(SFLVector2D_t const Vector1, SFLVector2D_t const Vector2);
extern SFLVector2D_t SFL_s_AddVector2(SFLVector2D_t const Vector1, SFLVector2D_t const Vector2);
extern float32       SFL_f_GetVector2Length(SFLVector2D_t const Vector);
extern float32       SFL_f_NormalizeRadiansToPi(const float32 fAngleRadians);
extern float32       SFL_f_NormalizeRadiansToTwoPi(const float32 fAngleRadians);
extern SFLVector2D_t SFL_s_CalculateNormalizedVector(SFLVector2D_t const Vector);
extern float32       SFL_f_CalcAngleFromVector(float32 fX, float32 fY, boolean bUseATAN2);
extern float32       SFL_f_CalcGradientFromAngle(float32 fAngle);
extern SFLVector2D_t SFL_s_MultiplyScalarVector(float32 const fScalar, SFLVector2D_t const Vector);
extern float32       SFL_f_Vector2CrossProduct(SFLVector2D_t const Vector1, SFLVector2D_t const Vector2);
extern SFLPositionVector2D_t SFL_s_SetupPositionVector2(SFLVector2D_t const FootVector, SFLVector2D_t const LineVector);
extern boolean       SFL_b_IntersectPositionVectors(SFLPositionVector2D_t const * const pPosVector1, SFLPositionVector2D_t const * const pPosVector2, SFLVector2D_t * const pPosIntersect);
extern SFLVector2D_t SFL_s_MultiplyMatrixVector(CML_t_TrafoMatrix2D const *const pMatrix, SFLVector2D_t const *const pVector);


/*--- sfl_trajoccupancy.c ---*/
extern void SFL_v_TrajOccCalcTTX(SFLTrajOccupancy_t const * const pTrajOccupancy,
                                       float32            const         afAssumedDeceleration[],
                                       float32            const         fEgoLength,
                                       SFLPolyDeg2_t      const * const pEgoKinematic,
                                       float32                  * const pfTTC,
                                       float32                  * const pfTTB);

/*--- sfl_circle.c ---*/
extern float32  SFL_f_CircleCalcArcLengthAtPos(SFLCircle_t   const * const pCircle,
                                               SFLVector2D_t const * const pPos);
extern void     SFL_v_CircleIntersectWithVector(SFLCircle_t           const * const pCircle, 
                                                SFLPositionVector2D_t const * const pPosVector, 
                                                SFLVector2D_t                       aPosIntersect[], 
                                                sint32                      * const piNofSolutions);
extern boolean  SFL_b_CheckPosInCircle(SFLCircle_t   const * const pCircle,
                                       SFLVector2D_t const * const pPos);

/*--- sfl_math.c ---*/
extern void SFL_v_GetSortedArrayIndices(float32 const a_val[], 
                                        uint8   const u_size, 
                                        uint8         a_sort[]);

extern float32       SFL_f_CalcCubeRoot( float32 fX );

extern float32       SFL_f_EvalPolyDeg2(SFLPolyDeg2_t const * const pInPolynom, 
                                        float32       const         fSamplePoint );

extern void          SFL_v_SolveQuadrEquation( float32            const         fC2,
                                               float32            const         fC1,
                                               float32            const         fC0,
                                               SFLPolynomialSolutions_t * const pSolutions);

extern void          SFL_v_SolveCubicEquation(float32 const         fC3  ,
                                              float32 const         fC2  ,
                                              float32 const         fC1  ,
                                              float32 const         fC0  ,
                                              SFLPolynomialSolutions_t * const pSolutions);

extern SFLVector2D_t SFL_s_ShiftPositionAlongAngle(SFLVector2D_t const Position, 
                                                   float32       const fAngle, 
                                                   float32             fShiftDistance, 
                                                   float32             fOrthogonalShiftDistance);

extern float32       SFL_f_SelectMinValue( float32 const fArray[], 
                                           uint32  const ArrayLen, 
                                           float32 const fDefault, 
                                           boolean const OnlyPositive );

extern float32       SFL_f_CalcDistPointToLine(SFLPolyDeg1_t const * const pLine,
                                               SFLVector2D_t const * const pPoint );

extern void          SFL_v_CalcLinearApproximation(float32       const         fXApprox,
                                                   SFLPolyDeg2_t const * const pPolynomialDeg2,
                                                   SFLPolyDeg1_t       * const pPolynomialDeg1);

extern float32       SFL_f_CalcArcLengthPolynomial(SFLPolyDeg2_t const * const pPolynomial, 
                                                   float32       const         fX);

extern boolean       SFL_b_SetupLine(SFLVector2D_t const * const pPos1,
                                     SFLVector2D_t const * const pPos2,
                                     SFLLine_t           * const pLine);

extern float32       SFL_f_SafeDiv(float32 const fNum, float32 const fDenom);

#endif /* ACDC_CFG_SFL */

#endif /* SFL_EXT_H_INCLUDED */
