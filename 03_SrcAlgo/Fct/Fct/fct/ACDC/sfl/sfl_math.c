/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   ARS4xx

CPU:                       CPU-Independent

COMPONENT:                 SFL (Safety Functions Library)

PACKAGENAME:               sfl_math.c

DESCRIPTION:               Generic mathematical functions.

AUTHOR:                    Almalih Ayman (uid6193)

CREATION DATE:             03.12.2018

VERSION:                   $Revision: 1.18 $

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
  @defgroup sfl_math Math
  @ingroup sfl
  @brief        This module provides mathematical calculation functions for the generic use in all safety function components. \n\n

  @description  The following functionalities are provided:
                - Solving of a quadratic equation: @ref SFL_v_SolveQuadrEquation
                - Solving of a cubic equation: @ref SFL_v_SolveCubicEquation
                - Selection of the minimum value from an array: @ref SFL_f_SelectMinValue
                - Calculation of the solution of a polynomial of 2nd degree at a certain point: @ref SFL_f_EvalPolyDeg2
                - Calculation of the cube root of a given value: @ref SFL_f_CalcCubeRoot
                - Shifting of a position alongside a given angle: @ref SFL_s_ShiftPositionAlongAngle
                - Calculation of a linear approximation of a polynomial of degree 2: @ref SFL_v_CalcLinearApproximation
                - Setting up of a polynomial of degree 1: @ref SFL_b_SetupLine
                - Calculation of the distance between a point and a line: @ref SFL_f_CalcDistPointToLine
                - Calculation of the arc length of a polynomial: @ref SFL_f_CalcArcLengthPolynomial
                - Safe division function: @ref SFL_f_SafeDiv
  @{
  */

/*************************************************************************************************************************
  Functionname:         SFL_v_SolveQuadrEquation                                                                         */ /*!

  @brief                Solves a quadratic equation of the form \f$ f(x) = C2 x^2 + C1 x + C0 \f$ by applying the formula: \n
                        \f$ x_{1,2} = \frac{-C1\pm \sqrt{C1^2-4\cdot C2\cdot C0}}{2\cdot C2}\f$\n

  @description          Solves a quadratic equation.
                        @startuml SFL_v_SolveQuadrEquation_activity.png
                        start
                        if(C2 == 0?) then (Yes)
                          if (C1 == 0?) then (Yes)
                            if(C0 == 0?) then (Yes)
                              :1}
                              :Every value is a solution because same equations;
                              note left: >see formula\n"Infinite Solutions"
                            else (No)
                              :2}
                              :No solution because different offsets;
                              note left:>see formula\n"No Solution"
                            endif
                          else (No)
                          :3}
                          : Linear Equation;
                          note left: >see formula\n"Linear Equation"
                          endif
                        else (No)
                          :Quadratic equation;
                          if(Discriminant == 0) then (Yes)
                          :4}
                          :Double solution because discriminant is zero;
                          note left: >see formula\n"Double Solution"
                          else (No)
                            if(Discriminant < 0) then (Yes)
                              :5}
                              :No solution because discriminant is less than zero;
                              note right:>see formula\n"No Solution"
                            else (No)
                              if(C0 == 0?) then (Yes)
                              :6}
                              :Special case to safeguard vs numerical effects;
                              note left: >see formula\n"2 Solutions Special"
                              else (No)
                              :7}
                              :Two solutions for positive discriminant;
                              note right: >see formula\n"2 Solutions"
                              endif
                            endif
                          endif
                        endif
                        stop
                        @enduml

  @return               boolean : False if NULL pointer is detected.

  @param[in]            fC2 :         Degree 2 coefficient of the equation.
  @param[in]            fC1 :         Degree 1 coefficient of the equation.
  @param[in]            fC0 :         Degree 0 coefficient of the equation.
  @param[in,out]        pSolutions:   Structure containing all achieved non complex results and the number of results.

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_SFL

  @pre                  None
  @post                 None

  @InOutCorrelation       
                          - **Linear Equation**:
                            - \f$x_1     = \frac{-C_0}{C_1}\f$
                            - \f$SolNum  = 1\f$
                          - **Infinite Solutions** :
                            - \f$x_1     = 0\f$
                            - \f$SolNum  = 1\f$
                          - **Discriminant** :
                            - \f$D       = C_1^2 - 4\cdot C_2\cdot C_0\f$
                          - **1 Solution** :
                            - \f$x_1     = \frac{-C_1}{2\cdot C_2}\f$
                            - \f$x_2     = 0\f$
                            - \f$SolNum  = 1\f$
                          - **Double Solution** :
                            - \f$x_1     = \frac{-C_1}{2\cdot C_2}\f$
                            - \f$x_2     = x_1\f$
                            - \f$SolNum  = 2\f$
                          - **2 Solutions** :
                            - \f$x_1     = \frac{-C_1 +\sqrt{D}}{2\cdot C_2}\f$
                            - \f$x_2     = \frac{-C_1 -\sqrt{D}}{2\cdot C_2}\f$
                            - \f$SolNum  = 2\f$
                          - **2 Solutions Special** :
                            - \f$x_1     = 0\f$
                            - \f$x_2     = \frac{-C_1}{C_2}\f$
                            - \f$SolNum  = 2\f$
                          - **No Solution**:
                            - \f$x_{1,2} = default\f$
                            - \f$SolNum  = 0\f$

  @testmethod           @ref TEST_SFL_V_SOLVEQUADREQUATION_001 \n
                        @ref TEST_SFL_V_SOLVEQUADREQUATION_002 \n
						@ref TEST_SFL_V_SOLVEQUADREQUATION_003 \n
                        @ref TEST_SFL_V_SOLVEQUADREQUATION_004 \n
						@ref TEST_SFL_V_SOLVEQUADREQUATION_005 \n
                        @ref TEST_SFL_V_SOLVEQUADREQUATION_006 \n
						@ref TEST_SFL_V_SOLVEQUADREQUATION_007

  @traceability         Design Decision 

  @author               Christian Gutmann
*************************************************************************************************************************/
void SFL_v_SolveQuadrEquation( float32            const         fC2,
                               float32            const         fC1,
                               float32            const         fC0,
                               SFLPolynomialSolutions_t * const pSolutions)
{

  pSolutions->uNofSolutions = 0u;

  /* equation reduces to linear one */
  if (fABS(fC2) < SFL_COEFFICIENT_MINIMUM)
  {
    /* equation is only constant */
    if (fABS(fC1) < SFL_COEFFICIENT_MINIMUM)
    {
      /* every value is a solution because same equations */
      if (fABS(fC0) < SFL_COEFFICIENT_MINIMUM)
      {
        pSolutions->afSolutions[0] = 0.f;
        pSolutions->uNofSolutions  = 1u;
      }
      /* no solution because different offsets */
      else
      {
        pSolutions->uNofSolutions = 0u;
      }
    }
    /* one solution because quadratic equation reduces to linear equation */
    else
    {
      pSolutions->afSolutions[0] = -fC0/fC1;
      pSolutions->uNofSolutions  = 1u;
    }
  }
  /* solve quadratic equation */
  else
  {
    /*general solution of the quadratic equation: sol_0,1=[-fB +- sqrt(fB^2-4*fA*fC)]/(2*fA)*/
    /*PRQA S 3121 26*/
    float32 const fDiscriminant = SQR(fC1) - (4.0f * fC2 * fC0);
    /* double solution because discriminant is zero */
    if (fABS(fDiscriminant) < SFL_COEFFICIENT_MINIMUM)
    {
      pSolutions->afSolutions[0] = -fC1/(2.0f * fC2);
      pSolutions->afSolutions[1] = pSolutions->afSolutions[0];
      pSolutions->uNofSolutions = 2u;
    }
    else
    {
      /* no solution because discriminant is less than zero */
      if (fDiscriminant < 0.f)
      {
        pSolutions->uNofSolutions = 0u;
      }
      /* two solutions for positive discriminant */
      else
      {
        if (fABS(fC0) < SFL_COEFFICIENT_MINIMUM) /* special case to safeguard vs numerical effects*/
        {
          pSolutions->afSolutions[0] = 0.f;
          pSolutions->afSolutions[1] = -fC1/fC2;
        }
        else
        {
          pSolutions->afSolutions[0] = (-fC1 + SQRT(fDiscriminant))/(2.0f * fC2);
          pSolutions->afSolutions[1] = (-fC1 - SQRT(fDiscriminant))/(2.0f * fC2);
        }
        pSolutions->uNofSolutions = 2u;
      }
    }
  }
}


/*************************************************************************************************************************
  Functionname:         SFL_v_SolveCubicEquation                                                                     */ /*!

  @brief                Solves a cubic equation of the form fC3 * x^3 + fC2 * x^2 + fC1 * x + fC0 = 0.

  @description          The Equation if solved by applying the **Cardano formula**.
                        @startuml SFL_v_SolveCubicEquation_activity.png
                        start
                          if(fA is not 0?) then (Yes)
                            :1}
                            :Apply the Cardano Formula;
                            note left:>see **Cardano Formula**
                          else (No)
                            :2}
                            #Orange:Equation is only quadratical, solve by 
                            using the corresponding function:
                            <b>SFL_v_SolveQuadrEquation</b> >
                          endif
                        stop
                        @enduml

  @return               void

  @param[in]            fC3 :         Degree 3 coefficient of the equation.
  @param[in]            fC2 :         Degree 2 coefficient of the equation.
  @param[in]            fC1 :         Degree 1 coefficient of the equation.
  @param[in]            fC0 :         Degree 0 coefficient of the equation.
  @param[in,out]        pSolutions : Structure containing all achieved non complex results and the number of results.

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_SFL\n

  @pre                  None
  @post                 None

  @InOutCorrelation     - **Cardano Formula:**
                            Assume a polynomial of the form \f$C_3 \cdot x^3 + C_2 \cdot x^2 + C_1 \cdot x + C_0 = 0\f$ \n
                            \f$ Q = \frac{3 \cdot C_3 \cdot C_1 - C_2^2}{9 \cdot C_3^2}\f$             \n
                            \f$ R = \frac{9 \cdot (C_3 \cdot C_2 \cdot C_1)-27 \cdot C_3^2 \cdot C_0 - 2 \cdot C_2^3}{54\cdot C_3^3}\f$   \n
                            Discriminant: \f$ D = Q^3 + R^2\f$ \n
                            - **Case 1: D > 0** => Only one root is real, two are complex conjugates: \n
                              \f$ S = \sqrt[3]{R + \sqrt{Q^3+R^2}} \f$ \n
                              \f$ T = \sqrt[3]{R - \sqrt{Q^3+R^2}} \f$ \n
                              \f$ x_1 = S + T -\frac{b}{3a}\f$ \n
                            - **Case 2: D < 0** => All three roots are real: \n
                              \f$ x_1 = 2\cdot \sqrt{-Q}\cdot\cos{(\frac{R}{3\sqrt-Q^3})}-\frac{b}{3a}\f$ \n
                              \f$ x_2 = 2\cdot \sqrt{-Q}\cdot\cos{(\frac{R}{3\sqrt-Q^3}+\frac{2\pi}{3})}-\frac{C_2}{3 \cdot C_3}\f$ \n
                              \f$ x_3 = 2\cdot \sqrt{-Q}\cdot\cos{(\frac{R}{3\sqrt-Q^3}+\frac{4\pi}{3})}-\frac{C_2}{3 \cdot C_3}\f$ \n

  @testmethod           @ref TEST_SFL_V_SOLVECUBICEQUATION_001 \n
                        @ref TEST_SFL_V_SOLVECUBICEQUATION_002 \n
						@ref TEST_SFL_V_SOLVECUBICEQUATION_003 \n
						@ref TEST_SFL_V_SOLVECUBICEQUATION_004

  @traceability         Design Decision 

  @author               Andreas Danner | Andreas.Danner@continental-corporation.com | +49 (8382) 9699-4995
*************************************************************************************************************************/
void SFL_v_SolveCubicEquation(float32 const         fC3  ,
                              float32 const         fC2  ,
                              float32 const         fC1  ,
                              float32 const         fC0  ,
                              SFLPolynomialSolutions_t * const pSolutions)
{

  pSolutions->uNofSolutions = 0u;

  if(fABS(fC3) > SFL_COEFFICIENT_MINIMUM)
  {
    /* Equation is actually of 3rd degree => Apply Cardano Formula */
    float32 const fQ            = ((3.f * fC3 * fC1) - SQR(fC2)) / (9.f * SQR(fC3));
    float32 const fR            = ( (9.f * fC3 * fC2 * fC1) - (27.f * SQR(fC3) * fC0) - (2.0f * fC2 * SQR(fC2)) ) / (54.f * SQR(fC3) * fC3);
    float32 const fQ_3          = SQR(fQ) * fQ;
    float32 const fR_2          = SQR(fR);
    float32 const fDiscriminant = fQ_3 + fR_2;

    if(fDiscriminant > SFL_COEFFICIENT_MINIMUM)
    {
      /* 1 valid non complex solution */
      float32 const fS           = SFL_f_CalcCubeRoot(fR + SQRT(fDiscriminant));
      float32 const fT           = SFL_f_CalcCubeRoot(fR - SQRT(fDiscriminant));
      pSolutions->afSolutions[0] = (fS + fT) - (fC2 / (3.f * fC3));
      pSolutions->uNofSolutions  = 1u;
    }
    else if(    (fDiscriminant <  SFL_COEFFICIENT_MINIMUM) 
             && (fABS(fQ_3)     > SFL_COEFFICIENT_MINIMUM) )
    {
      /* 3 valid non complex solutions */
      const float32 fSqrtQCuNeg = SQRT((-1.0f)*fQ_3);
      const float32 fSqrtQNeg   = SQRT((-1.0f)*fQ  );
      const float32 fPhi        = ACOS_(fR / fSqrtQCuNeg);

      pSolutions->afSolutions[0] = (2.0f * fSqrtQNeg * COS_( fPhi/3.0f                          )) - (fC2/(3.0f * fC3));
      pSolutions->afSolutions[1] = (2.0f * fSqrtQNeg * COS_((fPhi/3.0f) + ((2.0f*CML_f_Pi)/3.0f))) - (fC2/(3.0f * fC3));
      pSolutions->afSolutions[2] = (2.0f * fSqrtQNeg * COS_((fPhi/3.0f) + ((4.0f*CML_f_Pi)/3.0f))) - (fC2/(3.0f * fC3));
      pSolutions->uNofSolutions  = 3u;
    }
    else
    {
      /* No valid non complex solution */
      pSolutions->uNofSolutions  = 0u;
    }

  }
  else
  {
    /* Equation is only 2nd degree */
    SFL_v_SolveQuadrEquation(fC2, fC1, fC0, pSolutions);
  }
}


/*************************************************************************************************************************
  Functionname:         SFL_v_GetSortedArrayIndices                                                                  */ /*!

  @brief                Returns an array of indices corresponding to the input array being sorted in ascending order.

  @description          This function computes a permutation of the index set \f$\{0, \dots, \mathrm{u\_size-1\}}\f$ that
                        corresponds to the indices of the input array being sorted in ascending order.
                        The sorting algorithm used is heapsort. The reason for choosing this algorithm over 
                        e.g. quicksort is the favourable worst case running time. \n
                        \n
                        A general descrtiption of the terminology used can e.g. be found in
                        Cormen et al.: "Introduction to algorithms", MIT Press, Third edition.\n
                        \n 
                        \b Note: While actually indices are sorted/permuted, the comments in the code at times refer to the
                        sorting of the elements in the float array, e.g. regarding max-heap properties and parent and child
                        nodes, in order to provide a concise description.\n
                        \n
                        The running time of this routine could be reduced by using break statements instead
                        of checking s_heapSize in the outer while-loop and for the else part in the inner
                        loop. As the use of break statements is generally avoided in loops and would also cause
                        a QA-C warning for the outer while-loop, it can be checked if it is reasonable in this case.

  @return               void

  @param[in]            a_val  : Array of float values for which the sorted index set is to be provided
  @param[in]            u_size : Length of the input as well as the output array @range [1,255]
  @param[out]           a_sort : Sorted indices of the float array. @range [0,254]
  
  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_SFL

  @pre                  Caller has to make sure that the input and output arrays exist and have at least
                        u_size elements and at most 255.

  @post                 None

  @InOutCorrelation     The output array a_sort contains a permuation of the set 
                        \f$\{0, \dots, \mathrm{u\_size}-1\}\f$ such that
                        \f$\mathrm{a\_val}[\mathrm{a\_sort}[i]] \leq \mathrm{a\_val}[\mathrm{a\_sort}[i+1]] 
                        \quad \forall i \in \{0, \dots, \mathrm{u\_size}-2\}\f$.

  @testmethod           @ref TEST_SFL_V_GETSORTEDARRAYINDICES_001 \n
                        @ref TEST_SFL_V_GETSORTEDARRAYINDICES_002 \n
						@ref TEST_SFL_V_GETSORTEDARRAYINDICES_003 \n
                        @ref TEST_SFL_V_GETSORTEDARRAYINDICES_004 \n
						@ref TEST_SFL_V_GETSORTEDARRAYINDICES_005

  @traceability         Design Decision 

  @author               Lukas Stein | lukas.stein@conti-engineering.com
*************************************************************************************************************************/
void SFL_v_GetSortedArrayIndices ( float32 const a_val[],
                                   uint8   const u_size,
                                   uint8         a_sort[])
{
  sint32 s_fd; // initial index of the element that shall float down the tree
  sint32 s_i; // current index of the element that shall float down the tree
  sint32 s_child; // a child node of s_i
  sint32 s_heapSize;
  uint8 u_temp;

  // initialize array of indices
  for ( u_temp = 0u; u_temp < u_size; ++u_temp )
  {
    a_sort[u_temp] = u_temp;
  }

  // sort the array if it has a reasonable size
  if ( u_size > 1u )
  {
    // start with a heap size that matches the array length
    s_heapSize = (sint32)u_size;
    // all elements after the (u_size/2)th are leaves of the binary tree
    /*PRQA S 4394 2*/ /* date: 2019-05-14, reviewer: Schnurr, Clemens, reason: Cast to sint32 intended as implemented*/
    s_fd = (sint32)(u_size >> 1u);
    while ( s_heapSize > 1 )
    {
      if ( s_fd > 0 )
      {
        // first phase of the algorithm: build a max-heap
        // s_fd is the index corresponding to the value which should float down the
        // binary tree to get a max-heap
        --s_fd; // -1 also in the first cycle of the loop due zero-based indexing
      }
      else
      {
        // second phase: move the element corresponding to the largest value to the end of the (reduced) heap
        // and decrease its size and build a max-heap again
        --s_heapSize;
        u_temp = a_sort[0];
        a_sort[0] = a_sort[s_heapSize];
        a_sort[s_heapSize] = u_temp;
      }
      // set the index corresponding to the node which shall float down the tree to get a max-heap
      s_i = s_fd;
      // set the index corresponding to its left child
      s_child = (2*s_i)+1;
      // while there are valid child nodes
      while ( s_child < s_heapSize )
      {
        // compare the left and right child nodes if the later exists
        if ( (s_child < (s_heapSize-1)) && (a_val[a_sort[s_child]] < a_val[a_sort[s_child+1]]) )
        {
          //update the index to the right child node if it corresponds to the larger element
          ++s_child;
        }
        // compare the parent to the larger child node
        if ( a_val[a_sort[s_i]] < a_val[a_sort[s_child]] )
        {
          // swap the elements for the parent and child nodes if the child is larger
          u_temp = a_sort[s_i];
          a_sort[s_i] = a_sort[s_child];
          a_sort[s_child] = u_temp;
          // update the indices for the parent and left child nodes and repeat
          s_i = s_child;
          s_child = (2*s_i)+1;
        }
        else
        {
          // max-heap property achieved
          s_child = s_heapSize;
        }
      }
    }
  }
}


/*************************************************************************************************************************
  Functionname:         SFL_f_SelectMinValue                                                                             */ /*!

  @brief                Finds and returns the minimum value of an array.

  @description          Loops through an array and compares the current value to the current minimum value. If the 
                        current value is smaller, it is set as new minimum value. In the end returns the smallest 
                        found value. \n
                        By using the OnlyPositive Flag this function can be configured to ignore negative values.

  @return               float32 : Minimum value.

  @param[in]            fArray :        Array of which the minimum value shall be determined.
  @param[in]            ArrayLen :      Length of this array. @range[0,+...]
  @param[in]            fDefault :      Default Value. Only values below this are considered. Is returned if Array Length = 0. @range ]-...,+...[
  @param[in]            OnlyPositive :  Flag indicating whether only positive numbers shall be considered (TRUE: Negatives are ignored).

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_SFL

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_SFL_F_SELECTMINVALUE_001 \n
                        @ref TEST_SFL_F_SELECTMINVALUE_002 \n
						@ref TEST_SFL_F_SELECTMINVALUE_003
                         
  
  @traceability         Design Decision

  @author               Christian Gutmann
*************************************************************************************************************************/
float32 SFL_f_SelectMinValue(float32 const fArray[], 
                             uint32  const ArrayLen, 
                             float32 const fDefault, 
                             boolean const OnlyPositive )
{
  /* local variable(s) */
  float32 fVal = fDefault;
  uint32 ii;

  for (ii = 0u; ii < ArrayLen; ii++)
  {
    if ( (!(fArray[ii] < 0.0f)) ||
         (OnlyPositive != b_TRUE) )
    {
      fVal = MIN_FLOAT(fVal, fArray[ii]);
    }
  }

  /* return */
  return fVal;
}

/*************************************************************************************************************************
  Functionname:         SFL_f_EvalPolyDeg2                                                                              */ /*!

  @brief                Calculates the result of a 2nd degree Polynomial.

  @return               float32: Result of the polynomial.

  @param[in]            *pInPolynom :   Coefficients of the calculated polynomial.
  @param[in]            fSamplePoint :  variable/indeterminate of the polynomial.

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_SFL

  @pre                  Assure that pointer is valid
  @post                 None

  @InOutCorrelation     - **Formula 2nd degree polynomial:**\n
                        \f$ C_2 \cdot x^2 + C_1 \cdot x + C_0 \f$ \n
                        With\n
                        \f$C_{0/1/2} = \f$ Coefficients of the polynomial \n
                        \f$X  = \f$ SamplePoint

  @testmethod           @ref TEST_SFL_F_EVALPOLYDEG2_001

  @traceability         Design Decision

  @author               Matthias Thomi | matthias.thomi@continental-corporation.com
*************************************************************************************************************************/
float32 SFL_f_EvalPolyDeg2(SFLPolyDeg2_t const * const pInPolynom, 
                           float32       const         fSamplePoint )
{
  return (pInPolynom->fC2 * fSamplePoint * fSamplePoint) + (pInPolynom->fC1 * fSamplePoint) + pInPolynom->fC0;
}

/*************************************************************************************************************************
  Functionname:         SFL_f_CalcCubeRoot                                                                              */ /*!

  @brief                Calculates the cube root of given value.

  @description          Calculates the cube root of given value by iterating with the formula Iteration step. \n
                        The calculation is finished if the result equals the result of the previous cycle 
                        or after 20 iterations. If the input was negative, the sign of the result is inverted.
                        @startuml SFL_f_CalcCubeRoot_activity.png
                        start
                          while(Less than 20 Iterations?\nAND Found object is not previously found object?) is (True)
                            :Execute iteration step;
                            note left: >see Formula "Iteration step"
                          endwhile(False)

                          :Return absolute value of the last result;
                        stop
                        @enduml
  @return               float32 : Cube root of fX.

  @param[in]            fX : Value of which the cube root shall be calculated.

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_SFL

  @pre                  None
  @post                 None

  @InOutCorrelation     - **Formula Iteration step:**\n
                        \f$ R_0 = R_{-1} \cdot \frac{R_{-1}^3 + 2 \cdot |X|}{2\cdot R_{-1}^3 + |X|}\f$ \n
                        start value: \n
                        \f$R_{-1} = \sqrt{X} \f$\n

  @testmethod           @ref TEST_SFL_F_CALCCUBEROOT_001 \n
                        @ref TEST_SFL_F_CALCCUBEROOT_002 \n
						@ref TEST_SFL_F_CALCCUBEROOT_003

  @traceability         Design Decision

  @author               Matthias Thomi
*************************************************************************************************************************/
float32 SFL_f_CalcCubeRoot( float32 fX )
{
  float32 fResult        = 0.f;
  boolean bInputZero     = (boolean)((fX > -C_F32_DELTA) && (fX < C_F32_DELTA));

  if (bInputZero != b_FALSE)
  {
    fResult = 0.f;
  } 
  else
  {
    boolean bInputNegative        = (boolean)(fX < 0.f);
    float32 fXAbs                 = fABS(fX);
    float32 fIterResult           = SQRT(fXAbs);
    float32 fIterResultOld        = 0.f;
    const uint8   uiMaxIterations = 20u;
    uint8   uiCurrID              = 0u;
    float32 fDiffAbortCrit        = fIterResult;
    boolean bAbortCritMet         = b_FALSE;

    for ( uiCurrID = 0; (uiCurrID < uiMaxIterations) && (bAbortCritMet!= b_TRUE); ++uiCurrID )
    {
      float32 fIterResultCube = fIterResult*fIterResult*fIterResult;
      fIterResult = fIterResult * ((fIterResultCube + (2.0f*fXAbs))/((2.0f*fIterResultCube)+fXAbs));
      fDiffAbortCrit = fABS(fIterResult - fIterResultOld);
      bAbortCritMet = (fDiffAbortCrit > CML_f_Delta) ? b_FALSE : b_TRUE;
      fIterResultOld = fIterResult;
    }

    if (bInputNegative != b_FALSE)
    {
      fResult = -fIterResult;
    }
    else
    {
      fResult = fIterResult;
    }
  }
  return fResult;
}

/*************************************************************************************************************************
  Functionname:         SFL_s_ShiftPositionAlongAngle                                                                          */ /*!

  @brief                Shifts a position alongside and orthogonally to a given angle.

  @description          Shifts a given position according to 3 parameters:
                        - Angle : Reference direction for the shifting.
                        - ShiftDistance: Distance by which the position shall be shifted alongside with the Angle.
                        - OrthogonalDistance: Distance by which the position shall be shifted orthogonally towards the Angle.
                        @startuml SFL_s_ShiftPositionAlongAngle_activity.png
                        start
                          :Set up a transformation matrix for the 
                          roation around the given angle;
                          #Orange:Rotate the shift distances:
                          <b>CML_v_TransformPosition2D</b> >
                          :Add the rotated shift distances to 
                          the starting position;
                        stop
                        @enduml

  @return               SFLVector2D_t : Shifted Position.

  @param[in]            Position :                  Position that shall be shifted.
  @param[in]            fAngle :                    Reference Angle for the shift. @phys_unit [rad]
  @param[in]            fShiftDistance :            Distance by which the position shall be shifted alongside the given Angle. @phys_unit [m]
  @param[in]            fOrthogonalShiftDistance :  Distance by which the position shall be shifted orthogonally to the given Angle. @phys_unit [m]

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_SFL\n

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_SFL_S_SHIFTPOSITIONALONGANGLE_001
                       
  
  @traceability         Design Decision

  @author               Andreas Danner | Andreas.Danner@continental-corporation.com | +49 (8382) 9699-4995
*************************************************************************************************************************/
SFLVector2D_t SFL_s_ShiftPositionAlongAngle(SFLVector2D_t const Position, 
                                            float32       const fAngle,
                                            float32             fShiftDistance,
                                            float32             fOrthogonalShiftDistance)
{
  CML_t_TrafoMatrix2D TrafoMatrix;
  float32             fCos_Angle;
  float32             fSin_Angle;
  SFLVector2D_t       ShiftedPosition;

  GDBsincos(fAngle,&fSin_Angle,&fCos_Angle);

  /* Set up a trafo matrix for a rotation */
  TrafoMatrix.TrafoType = ROTATION_;
  TrafoMatrix.f00       = fCos_Angle;
  TrafoMatrix.f02       = 0.0f;
  TrafoMatrix.f10       = fSin_Angle;
  TrafoMatrix.f12       = 0.0f;

  /* Rotate the given shift distances by the given angle */
  CML_v_TransformPosition2D(&TrafoMatrix, &fShiftDistance , &fOrthogonalShiftDistance);

  /* Shift the X and Y position by the rotated distances */
  ShiftedPosition.fX = Position.fX + fShiftDistance;
  ShiftedPosition.fY = Position.fY + fOrthogonalShiftDistance;

  return ShiftedPosition;
}


/*************************************************************************************************************************
  Functionname:         SFL_v_CalcLinearApproximation                                                                */ /*!

  @brief                Calculates a linear approximation of a given 2nd degree polynomial at a given x position. 
                        (>see **Linear Approximation**)

  @return               void

  @param[in]            fXApprox :        X position for which the linear approximation shall be calculated.
  @param[in]            pPolynomialDeg2 : Polynomial of degree 2 which shall be approximated.
  @param[in,out]        pPolynomialDeg1 : Polynomial of degree 1 wich approximates the 2nd degree polynomial at X.

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_SFL\n

  @pre                  None
  @post                 None

  @InOutCorrelation     - **Linear Approximation:**\n
                        \f$C_{1,Approx} = 2 \cdot C_2 \cdot X + C_1\f$ \n
                        \f$C_{0,Approx} = C_2 \cdot X^2 + C_1 \cdot X + C_0 - C_{1,Approx} \cdot X\f$

  @testmethod           @ref TEST_SFL_V_CALCLINEARAPPROXIMATION_001

  @traceability         Design Decision

  @author               Andreas Danner | Andreas.Danner@continental-corporation.com | +49 (8382) 9699-4995
*************************************************************************************************************************/
void SFL_v_CalcLinearApproximation(float32       const         fXApprox,
                                   SFLPolyDeg2_t const * const pPolynomialDeg2,
                                   SFLPolyDeg1_t       * const pPolynomialDeg1)
{
  pPolynomialDeg1->fC1 = (2.f * pPolynomialDeg2->fC2 * fXApprox) + pPolynomialDeg2->fC1;
  pPolynomialDeg1->fC0 = SFL_f_EvalPolyDeg2(pPolynomialDeg2,fXApprox) - (fXApprox * pPolynomialDeg1->fC1);
}

/*************************************************************************************************************************
  Functionname:         SFL_b_SetupLine                                                                             */ /*!

  @brief                Calculates a line in the form of a linear equation \f$A \cdot x + B \cdot y = C \f$
                        from two given points (including vertical lines).

  @description          Calculates a parameterization of a line L through two given points
                        \f$ p_1 = (x1, y1) \f$ and \f$ p2 = (x2, y2) \f$ \n
                        in terms of defining linear equation, 
                        i.e. \f$ L = \{ (x, y) \in R^2 :\ Ax + By = C \} \f$ 
                        The coefficients are given by: \n
                        \f$ A = y2 - y1 \f$ \n
                        \f$ B = -(x2 - x1) \f$ \n
                        \f$ C = (A * x1) + (B * y1) \f$ \n
                        In case of identical points, returns FALSE and set all coefficients to zero.

  @return               boolean bResultValid: FALSE is returned if the two points are identical.

  @param[in]            pPos1 : First point for the line creation.
  @param[in]            pPos2 : Second point for the line creation.
  @param[in,out]        pLine : Calculated line going through the two given points.

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_SFL\n

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_SFL_B_SETUPLINE_001 \n
                        @ref TEST_SFL_B_SETUPLINE_002 \n
						@ref TEST_SFL_B_SETUPLINE_003 \n
						@ref TEST_SFL_B_SETUPLINE_004

  @traceability         Design Decision

  @author               Ayman Almalih | Ayman.almalih@continental-corporation.com | +49 (8382) 9699-9777
*************************************************************************************************************************/
boolean SFL_b_SetupLine(SFLVector2D_t const * const pPos1,
                        SFLVector2D_t const * const pPos2, 
                        SFLLine_t           * const pLine)
{

  boolean bResultValid = b_TRUE;
  float32 fX_Delta = pPos2->fX - pPos1->fX;
  float32 fY_Delta = pPos2->fY - pPos1->fY;

  /* Check if Pos1 == Pos2*/
  if(    (fABS(fX_Delta) < C_F32_DELTA)
      && (fABS(fY_Delta) < C_F32_DELTA) )
  {
    pLine->fA = 0.f;
    pLine->fB = 0.f;
    pLine->fC = 0.f;
    bResultValid = b_FALSE;
  }
  else
  {
    pLine->fA = fY_Delta;
    pLine->fB = -fX_Delta;
    pLine->fC = (pLine->fA * pPos1->fX) + (pLine->fB * pPos1->fY);
  }

  return bResultValid;
}

/*************************************************************************************************************************
  Functionname:         SFL_f_CalcDistPointToLine                                                                    */ /*!

  @brief                Calculates a signed distance between a point and a given line.

  @description          Returns the distance between a point and a line:
                        - Positive if the point is left of the line
                        - Negative if the point is right of the line

  @return               float32 : Distance Point - Line, @range ]-...,+...[

  @param[in]            pLine :  Line to which a distance shall be calculated.
  @param[in]            pPoint : Position from which a distance shall be calculated to the line.

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_SFL\n

  @pre                  None
  @post                 None

  @InOutCorrelation     
                        - **X Min Dist:**\n
                        \f$Dist_{X,Min} = \frac{X + C_1 \cdot (Y - C_0)}{1 + C_1^2} \f$
                        - **Y Min Dist:**\n
                        \f$Dist_{Y,Min} = C_1 \cdot Dist_{X,Min} + C_0\f$

  @testmethod           @ref TEST_SFL_F_CALCDISTPOINTTOLINE_001 \n
                        @ref TEST_SFL_F_CALCDISTPOINTTOLINE_002

  @traceability         Design Decision

  @author               Andreas Danner | Andreas.Danner@continental-corporation.com | +49 (8382) 9699-4995
*************************************************************************************************************************/
float32 SFL_f_CalcDistPointToLine(SFLPolyDeg1_t const * const pLine, SFLVector2D_t const * const pPoint )
{
  /* Calculate the reference position on the line */
  float32 const fXDistMin   = (pPoint->fX + (pLine->fC1 * (pPoint->fY - pLine->fC0)))/(1.f + SQR(pLine->fC1));
  float32 const fYDistMin   = (pLine->fC1 * fXDistMin) + pLine->fC0;
  
  /* Calculate the distance between the reference position and the point */
  float32       fDistToLine = SQRT(SQR(pPoint->fX - fXDistMin) + SQR(pPoint->fY - fYDistMin));

  /* Add a sign to the resulting distance */
  if(pPoint->fY < fYDistMin)
  {
    fDistToLine *= -1.f;
  }

  return fDistToLine;
}


/*************************************************************************************************************************
  Functionname:         SFL_f_CalcArcLengthPolynomial                                                                */ /*!

  @brief                Calculates the arc length of a polynomial up to the position fX.

  @description          Calculates the arc length of a polynomial from 0 up to the position fX by applying the formula 
                        described in the InOutCorrelation. The formula can also be found here:
                        https://www.schuelerkonferenz.edu.tum.de/fileadmin/w00brm/www/Facharbeiten_2009/dueren_philipp_cc.pdf

  @return               float32 : Arc length

  @param[in]            pPolynomial : Polynomial for which the arc length shall be calculated.
  @param[in]            fX :          X Position up to which the arc length shall be calculated.

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_SFL\n

  @pre                  None
  @post                 None

  @InOutCorrelation     - **Arc Length:** \n
                        \f$Discriminant = \sqrt{1 + 4 \cdot C_2^2 \cdot X^2}\f$ \n
                        \f$ArcLength    = \frac{1}{4 \cdot C_2} \cdot \ln(2 \cdot C_2 \cdot X + Discriminant) + 0.5\cdot X \cdot Discriminant\f$

  @testmethod           @ref TEST_SFL_F_CALCARCLENGTHPOLYNOMIAL_001 \n
						@ref TEST_SFL_F_CALCARCLENGTHPOLYNOMIAL_002

  @traceability         Design Decision

  @author               Andreas Danner | Andreas.Danner@continental-corporation.com | +49 (8382) 9699-4995
*************************************************************************************************************************/
float32 SFL_f_CalcArcLengthPolynomial(SFLPolyDeg2_t const * const pPolynomial, 
                                      float32       const         fX)
{
  float32 fArcLength = fX;

  if(fABS(pPolynomial->fC2) > C_F32_DELTA)
  {
    float32 const fDiscr = SQRT_(1.f + (4.f * SQR(pPolynomial->fC2) * SQR(fX)));
    fArcLength           = ( (1.f / (4.f * pPolynomial->fC2)) * CML_f_ln((2.f * pPolynomial->fC2 * fX) + fDiscr) )  + (0.5f * fX * fDiscr);
  }

  return fArcLength;
}

/*************************************************************************************************************************
  Functionname:         SFL_f_SafeDiv                                                                             */ /*!

  @brief                Returns division result.

  @description          Returns division result. Division by zero is checked and the sign is handled correctly.
                        @startuml SFL_f_SafeDiv_activity.png
                        start
                          if(fDenom is not 0?) then (Yes)
                            :1}
                            :fRet = fNum / fDenom;
                          else (No)
                            :fRet = fNum / fDenomMin;
                            if(fDenom < 0?) then (Yes)
                              :2}
                              :fRet = -fRet;
                            else (No)
                              :3}
                            endif
                          endif
                        stop
                        @enduml

  @return               float32 : division result.

  @param[in]            fNum :   Numerator, @range ]-...,+...[
  @param[in]            fDenom : Denominator, @range ]-...,+...[

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_SFL

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_SFL_F_SAFEDIV_001

  @traceability         Design Decision

  @author               Andreas Kramer
*************************************************************************************************************************/
float32 SFL_f_SafeDiv (float32 const fNum, float32 const fDenom)
{
  float32       fRet;
  float32 const fDenomMin = C_F32_DELTA;

  /* Check whether the denominator is too close to 0 */
  if (    (fDenom >  fDenomMin)
       || (fDenom < -fDenomMin) )
  {
    fRet = fNum / fDenom;
  }
  else
  {
    /* Divide by the least valid value */
    fRet  = fNum / fDenomMin;
    /* Preserve the correct sign */
    if (fDenom < 0.0F)
    {
      fRet = -fRet;
    }
  }
  return fRet;
}

/*!@} */

#endif /* ACDC_CFG_SFL */

