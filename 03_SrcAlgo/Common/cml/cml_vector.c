/*! \file **********************************************************************

  COMPANY:                   Continental AG, A.D.C. GmbH

  CPU:                       CPU-Independent

  COMPONENT:                 CML (Common Math Library)

  MODULNAME:                 cml_vector.c

  DESCRIPTION:               Vector Computations Library

  AUTHOR:                    Jochen Spruck

  CREATION DATE:             24.10.2010

  VERSION:                   $Revision: 1.15 $

  ---*/ /*---
  CHANGES:                   $Log: cml_vector.c  $
  CHANGES:                   Revision 1.15 2017/11/27 06:19:25CET A, Nandu (uidr5428) (uidr5428) 
  CHANGES:                   Replaced TRUE and FALSE with b_TRUE and b_FALSE to match the Mainstream update
  CHANGES:                   Revision 1.14 2017/11/24 07:05:59CET Kotre-EXT, Jeevan (uidk9586) 
  CHANGES:                   Updated cml_vector with naming conventions.
  CHANGES:                   Revision 1.13 2017/11/16 14:19:33CET Kotre-EXT, Jeevan (uidk9586) 
  CHANGES:                   Updated cml_vector module functions with coding standard naming convention.
  CHANGES:                   Revision 1.12 2016/05/20 11:06:01CEST Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   - Updated function header with argument range
  CHANGES:                   Revision 1.11 2015/08/25 12:23:31CEST Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   Updated doxygen compliant function headers
  CHANGES:                   - Added comments -  uidr5428 [Aug 25, 2015 12:23:32 PM CEST]
  CHANGES:                   Change Package : 360603:2 http://mks-psad:7002/im/viewissue?selection=360603
  CHANGES:                   Revision 1.10 2015/04/29 18:07:16CEST Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   - Changes with respect to Coding Guidelines
  CHANGES:                     of variables
  CHANGES:                   --- Added comments ---  uidr5428 [Apr 29, 2015 6:07:16 PM CEST]
  CHANGES:                   Change Package : 324617:3 http://mks-psad:7002/im/viewissue?selection=324617
  CHANGES:                   Revision 1.9 2015/04/21 16:52:18CEST Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   Edited the docu header of the function Vector2GetSqrDist_i16
  CHANGES:                   --- Added comments ---  uidr5428 [Apr 21, 2015 4:52:19 PM CEST]
  CHANGES:                   Change Package : 316978:1 http://mks-psad:7002/im/viewissue?selection=316978
  CHANGES:                   Revision 1.8 2014/12/05 10:11:07CET Schwarzkopf, Sebastian (uidg6516) 
  CHANGES:                   changed several function parameters of VectorWeightedPNorm() from pointer to array as they're accessed like that
  CHANGES:                   --- Added comments ---  uidg6516 [Dec 5, 2014 10:11:07 AM CET]
  CHANGES:                   Change Package : 266613:11 http://mks-psad:7002/im/viewissue?selection=266613
  CHANGES:                   Revision 1.7 2014/06/03 10:31:06CEST Brendel, Matthias (uidv8244) 
  CHANGES:                   fixing p-norm, the weights must not be taken to the power!
  CHANGES:                   --- Added comments ---  uidv8244 [Jun 3, 2014 10:31:07 AM CEST]
  CHANGES:                   Change Package : 235600:1 http://mks-psad:7002/im/viewissue?selection=235600
  CHANGES:                   Revision 1.6 2014/03/25 11:42:42CET Schwarzkopf, Sebastian (uidg6516) 
  CHANGES:                   - fixed Doxygen comments
  CHANGES:                   --- Added comments ---  uidg6516 [Mar 25, 2014 11:42:42 AM CET]
  CHANGES:                   Change Package : 227281:1 http://mks-psad:7002/im/viewissue?selection=227281
  CHANGES:                   Revision 1.5 2014/03/12 13:38:36CET Brendel, Matthias (uidv8244) 
  CHANGES:                   Fix warnings and coding guideline problems in function VectorWeightedPNorm.
  CHANGES:                   --- Added comments ---  uidv8244 [Mar 12, 2014 1:38:36 PM CET]
  CHANGES:                   Change Package : 223474:2 http://mks-psad:7002/im/viewissue?selection=223474
  CHANGES:                   Revision 1.4 2014/03/12 10:45:25CET Brendel, Matthias (uidv8244) 
  CHANGES:                   added weighted p-norm
  CHANGES:                   --- Added comments ---  uidv8244 [Mar 12, 2014 10:45:25 AM CET]
  CHANGES:                   Change Package : 223474:1 http://mks-psad:7002/im/viewissue?selection=223474
  CHANGES:                   Revision 1.3 2013/05/03 09:58:25CEST Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   - drop algo_common from CML
  CHANGES:                   - use new standard type names, e.g. float32 instead of f32_t
  CHANGES:                   --- Added comments ---  uidu0849 [May 3, 2013 9:58:26 AM CEST]
  CHANGES:                   Change Package : 159154:27 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.2 2012/09/20 13:29:45CEST Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   - delete old log in file header
  CHANGES:                   --- Added comments ---  uidu0849 [Sep 20, 2012 1:29:45 PM CEST]
  CHANGES:                   Change Package : 159154:3 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.1 2012/09/14 14:31:19CEST Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/CML_CommonMathLibrary/04_Engineering/01_Source_Code/algo/cml/project.pj

**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "cml_ext.h"

/*****************************************************************************
  FUNCTIONS
*****************************************************************************/
/*****************************************************************************
 
  Functionname:    CML_f_vectorWeightedPNorm                                   *//*!

  @brief           Computes the so called p norm of a vector
  
  @description     The implementation is using and modifying the input vectors
                   for computation. 
                   Let 
                   A = [a1, a2, a3,..., an] = the vector, 
                   W = [w1, w2, w3,..., wn] = weights,
                   n = length
                   p = exponent, then p-norm of the vector would be,

                   Norm = [{(w1*(a1^p)) + (w2*(a2^p)) + (w3*(a3^p)) + ..
                          ..  + (wn*(an^p))}/(w1 + w2 + w3 + .. + wn)}] ^ (1/p)

                   The implementation is general and inefficient,
                   should not be called thousands of times.
  
  @param[in,out]   a_vector :    The input values, they are modified in the function, negative numbers are handled az 0
                                 Supported values [Full range of float32]
  @param[in,out]   a_weights :   The weights, , they are modified in the function, negative numbers are handled az 0
                                 Supported values [Full range of float32]  
                                 Overflow may occur when one or more values are at extremities.
  @param[in]       u_length :    length of vector and weights
                                 Supported values [Full range of uint32]
  @param[in]       u_exponent :  exponent of the norm. shall be >0
                                 Supported values [Full range of uint32]
  
  
  
  @return           the norm
  
  @author          Matthias Brendel
*//************************************************************************/


float32 CML_f_vectorWeightedPNorm(float32 a_vector[], float32 a_weights[], uint32 u_length, uint32 u_exponent)
{
    uint32  u_index;
    float32 f_sumweights = 0.0f;
    float32 f_result     = 0.0f;
    float32 f_reciprocpower;

    if (u_exponent>0u)
    {
        f_reciprocpower=1.0f/(float32)u_exponent;

    /*compute powers*/

        for(u_index = 0u; u_index < u_length; ++u_index)
        {
            f_sumweights += a_weights[u_index];
            if (a_vector[u_index] > CML_f_AlmostZero) /*if zero, nothing has to be done, negative numbers are handled as zero*/
            {
                f_result += a_weights[u_index] * CML_f_expPower(a_vector[u_index], u_exponent);
            }
        }

        /*normalize */
        if (f_sumweights>CML_f_AlmostZero)
        {
            f_result /= f_sumweights;
        }

        /*compute root*/
        if (f_result>CML_f_AlmostZero)
        {
            f_result = EXP_(f_reciprocpower*CML_f_fastlog(f_result));
        }
    } /*if (exponent>0)*/

    return f_result;

}

/*****************************************************************************

  Functionname:    CML_v_vector2AddPi16                                    */ /*!

  @brief           Add two int 16 vectors
  
  @description     This function add two vectors whose x,y values are defined
                   by int16 values


  @param[in]       p_vector1  : pointer to vector 1
                                Optimal values for p_vector1->nXDist [Half range of signed short]
                                Optimal values for p_vector1->nYDist [Half range of signed short]
  @param[in,out]   p_vector2  : pointer to vector 2 
                                holds the sum after addition
                                Optimal values for p_vector2->nXDist [Half range of signed short]
                                Optimal values for p_vector2->nYDist [Half range of signed short]

  @return          void

  @author          jochen.spruck@contiautomotive.com

****************************************************************************/
void CML_v_vector2AddPi16(const Vector2_i16_t * p_vector1, Vector2_i16_t * p_vector2)
{
  p_vector2->nXDist = p_vector1->nXDist + p_vector2->nXDist;
  p_vector2->nYDist = p_vector1->nYDist + p_vector2->nYDist;
}

/*****************************************************************************

  Functionname:    CML_v_vector2SubPi16                                      */ /*!

  @brief           Subtract two int 16 vectors

  @description     This function subtract two vectors whose x,y values are 
                   defined by int16 values

  @param[in,out]   p_min  : input vector 1 -> min = min - sub
                            Optimal values for p_min->nXDist [Half range of signed short]
                            Optimal values for p_min->nYDist [Half range of signed short]
  @param[in]       p_sub  : substract sub from min
                            Optimal values for p_sub->nXDist [Half range of signed short]
                            Optimal values for p_sub->nYDist [Half range of signed short]

  @return          void

  @author          jochen.spruck@contiautomotive.com

****************************************************************************/
void CML_v_vector2SubPi16(Vector2_i16_t * p_min, const Vector2_i16_t * p_sub)
{
  p_min->nXDist = p_min->nXDist - p_sub->nXDist;
  p_min->nYDist = p_min->nYDist - p_sub->nYDist;
}

/*****************************************************************************

  Functionname:    CML_vector2Mulli16                                      */ /*!

  @brief           Multiplicate int 16 vector with a f32 factor

  @description     This function multiply vector whose x,y values are 
                   defined by int16 values with a float32 factor 

  @param[in]       Vec      : input vector
                              Optimal values for Vec.nXDist [Full range of signed short]
                              Optimal values for Vec.nYDist [Full range of signed short]
  @param[in]       f_Factor : with this factor the input vector should be 
                              multiplied
                              Optimal Range [-F_MAX..F_MAX]
                              where F_MAX is square root of max range of float.

  @return          product of Vec and f_Factor

  @author          jochen.spruck@contiautomotive.com

****************************************************************************/
Vector2_f32_t CML_vector2Mulli16(Vector2_i16_t Vec, float32 f_Factor)
{
  Vector2_f32_t loc;
  loc.fXDist = (float32)Vec.nXDist * f_Factor;
  loc.fYDist = (float32)Vec.nYDist * f_Factor;
  return loc;
}

/*****************************************************************************

  Functionname:    CML_s_vector2ScalarProdi16                                */ /*!

  @brief           Scalar product of i16 vector

  @description     This function does the scalar multiplication of two vectors
                   whose x,y values are defined by int16 values

  @param[in]       Point1  : input vector 1
                             Supported values for Point1.nXDist [Full range of signed short]
                             Supported values for Point1.nYDist [Full range of signed short]
  @param[in]       Point2  : input vector 2
                             Supported values for Point2.nXDist [Full range of signed short]
                             Supported values for Point2.nYDist [Full range of signed short]

  @return          scalarproduct of input vectors

  @author          jochen.spruck@contiautomotive.com

****************************************************************************/
sint32 CML_s_vector2ScalarProdi16(Vector2_i16_t Point1, Vector2_i16_t Point2)
{
  return ( ((sint32)Point1.nXDist*(sint32)Point2.nXDist) + ((sint32)Point1.nYDist*(sint32)Point2.nYDist) );
}

/*****************************************************************************

  Functionname:    CML_s_vector2GetSqrDisti16                              */ /*!

  @brief           Get the square dist of the vector
                   
  @description     The function returns the square distance of the vector
                   Limitation: When both inputs are least possible values
                   (negative), the result will overflow
                   
  @param[in]       input_vector  : input vector
                                   Supported values for input_vector.nXDist 
                                   [Full range of signed short]
                                   Supported values for input_vector.nYDist 
                                   [Full range of signed short]
                   
  @return          square distance of vector
                   
  @author          jochen.spruck@contiautomotive.com

****************************************************************************/
sint32 CML_s_vector2GetSqrDisti16(Vector2_i16_t input_vector)
{
  return SQR((sint32)input_vector.nXDist)+SQR((sint32)input_vector.nYDist);
}

/***************************************************************************** 

  Functionname:    CML_v_vector2MathRotate2Di16                              */ /*!

  @brief           Calculate Transformation of Coordiantes using 
                   Transformation matrix M

  @description     This function calculates the transformation of cordinates
                   using the transfromation matrix.
                   Let the vector be defined by V = (x,y) and transformed vector
                   be V1 = (x1,y1) and the transformation matrix be 
                   M = |f00  f01|
                       |f10  f11|,
                   then,
                   x1 = x * f00 - y * f10
                   y1 = x * f10 + y * f00

  @param[in]       p_Transform_Matrix : The transformation matrix
                                        Optimal values for p_Transform_Matrix->f00 
                                        [-F_MAX..F_MAX]
                                        Optimal values for p_Transform_Matrix->f10 
                                        [-F_MAX..F_MAX]
                                        where F_MAX is square root of max range of float.
  @param[out]      p_input_vector : Vector to be transformed
                                    Supported values for p_input_vector->nXDist 
                                    [Full range of signed short]
                                    Supported values for p_input_vector->nYDist 
                                    [Full range of signed short]

  @return          -

  @author          jochen.spruck@contiautomotive.com

****************************************************************************/
void CML_v_vector2MathRotate2Di16(CML_t_TrafoMatrix2D const *p_Transform_Matrix , Vector2_i16_t *p_input_vector)
{
  sint16 s_YDist = p_input_vector->nYDist;

  /* <ln_offset:+1 MISRA Rule 10.4: reviewer name: Jochen Spruck date: 15-03-2011 reason: Cast needed to round float value i16 */
  p_input_vector->nYDist = (sint16)(CML_s_Round2Int( ((float32)p_input_vector->nXDist * p_Transform_Matrix->f10) + ((float32)s_YDist * p_Transform_Matrix->f00) ));
  /* <ln_offset:+1 MISRA Rule 10.4: reviewer name: Jochen Spruck date: 15-03-2011 reason: Cast needed to round float value i16 */
  p_input_vector->nXDist = (sint16)(CML_s_Round2Int( ((float32)p_input_vector->nXDist * p_Transform_Matrix->f00) - ((float32)s_YDist * p_Transform_Matrix->f10) ));
}

/*****************************************************************************

  Functionname:    CML_f_vector2AngleToXAxisi16                              */ /*!

  @brief           Angle between vector and the x axis

  @description     This function calculates the angle between given vector
                   and x-axis. This makes use of the arctangent function.

  @param[in]       input_vector  : input vector
                                   Optimal values for input_vector.nXDist 
                                   [Full range of signed short]
                                   Optimal values for input_vector.nYDist 
                                   [Full range of signed short]

  @return          Angle between vector and the x axis

  @author          jochen.spruck@contiautomotive.com

****************************************************************************/
float32 CML_f_vector2AngleToXAxisi16(Vector2_i16_t input_vector)
{
  return ATAN2_((float32)input_vector.nYDist, (float32)input_vector.nXDist);
}

/*****************************************************************************

  Functionname:    CML_v_vector2Initi16                                      */ /*!

  @brief           Init the Vector distances with zero

  @description     This function initializes x and y values of the given vector
                   with zero.

  @param[in]       p_Vector    : i16 vector to init
                                 [Valid pointer to the structure]

  @return          void

  @author          jochen.spruck@contiautomotive.com

****************************************************************************/
void CML_v_vector2Initi16(Vector2_i16_t * p_Vector)
{
  p_Vector->nXDist = 0;
  p_Vector->nYDist = 0;
}

/*****************************************************************************

  Functionname:    CML_vector2AddI16i32                                    */ /*!

  @brief           Add int 16 to an int 32  vectors

  @description     This function adds a vector whose x,y values are defined
                   by int16 values to another vector whose x,y values are 
                   defined by int32 values
                   
  @param[in]       input_vector1  : vector 1
                                    Optimal values for input_vector2.nXDist 
                                    [Half range of signed long]
                                    Optimal values for input_vector2.nYDist 
                                    [Half range of signed long]
  @param[in]       input_vector2  : vector 2 to add to vector 1
                                    Supported values for input_vector2.nXDist 
                                    [Full range of signed short]
                                    Supported values for input_vector2.nYDist 
                                    [Full range of signed short]
                   
  @return          Sum of vectors
                   
  @author          jochen.spruck@contiautomotive.com

****************************************************************************/
Vector2_i32_t CML_vector2AddI16i32(Vector2_i32_t input_vector1, Vector2_i16_t input_vector2)
{
  Vector2_i32_t vector_sum;
  vector_sum.nXDist = input_vector1.nXDist + input_vector2.nXDist;
  vector_sum.nYDist = input_vector1.nYDist + input_vector2.nYDist;
  return vector_sum;
}

/*****************************************************************************

  Functionname:    CML_s_vector2ScalarProdi32                                */ /*!

  @brief           Scalar product of i32 vector

  @description     This function does the scalar multiplication of two vectors
                   whose x,y values are defined by int32 values
                   
  @param[in]       Point1  : input vector 1
                             Optimal values for Point1.nXDist 
                             [-S_MAX..S_MAX]
                             Optimal values for Point1.nYDist 
                             [-S_MAX..S_MAX]
                             where S_MAX is square root of half the max range of sint32.
  @param[in]       Point2  : input vector 1
                             Optimal values for Point2.nXDist 
                             [-S_MAX..S_MAX]
                             Optimal values for Point2.nYDist 
                             [-S_MAX..S_MAX]
                             where S_MAX is square root of half the max range of sint32.
                   
  @return          scalarproduct of input vectors
                   
  @author          jochen.spruck@contiautomotive.com

****************************************************************************/
sint32 CML_s_vector2ScalarProdi32(Vector2_i32_t Point1, Vector2_i32_t Point2)
{
  return ( (Point1.nXDist*Point2.nXDist) + (Point1.nYDist*Point2.nYDist) );
}

/*****************************************************************************

  Functionname:    CML_b_vector2YAxisIntersectionAddi32                      */ /*!

  @brief           Intersection of line defined with x = p1 +t*(p2-p1) and 
                   the y axis

  @description     This function calculates the intersection of line and 
                   y axis.
                   The calculation is based on basic line equation. 
                   If two points of line are defined by (x1,y1) and (x2,y2), 
                   then Line equation is :
                    y-y1      x-x1
                   ------ =  ------  ==> y = y1 + (x-x1)*(y2-y1)/(x2-x1)
                   y2-y1     x2-x1

                   and for Y intersection, x=0, so,

                   y = y1 - x1*(y2-y1)/(x2-x1)

  @param[in]       Point1           : first point on lane
                                      Optimal values for Point2.nXDist 
                                      [-S_MAX..S_MAX]
                                      Optimal values for Point2.nYDist 
                                      [-S_MAX..S_MAX]
                                      where S_MAX is square root of max range of sint32.
  @param[in]       Point2           : second point on lane
                                      Optimal values for Point2.nXDist 
                                      [-S_MAX..S_MAX]
                                      Optimal values for Point2.nYDist 
                                      [-S_MAX..S_MAX]
                                      where S_MAX is square root of max range of sint32.
  @param[out]      p_YIntersection  : y value of lane with intersection with the y axis

  @return          true if intersection to y axis could be calculated otherwise false

  @author          jochen.spruck@contiautomotive.com

****************************************************************************/
boolean CML_b_vector2YAxisIntersectionAddi32(Vector2_i32_t Point1, Vector2_i32_t Point2, sint32 *p_YIntersection)
{
  sint32 s_Temp;
  boolean ret_value;
  /* if line is paralell to y axix no intersection could be calculated*/
  s_Temp = Point2.nXDist - Point1.nXDist;
  if (s_Temp == 0)
  {
    /* no valid trace intersection */
    *p_YIntersection    = VECTOR_I32_VALUE_INVALID;
    ret_value = b_FALSE;
  }
  else
  {
    /* trace intersection with y axis*/
    *p_YIntersection    = Point1.nYDist - ( (Point1.nXDist*(Point2.nYDist - Point1.nYDist))/s_Temp );
    ret_value = b_TRUE;
  }
  return ret_value;
}

/*****************************************************************************

  Functionname:    CML_vector2Addf32                                       */ /*!

  @brief           Add two float 32 vectors

  @description     This function adds two vectors whose x,y values are defined
                   by float32 values

  @param[in]       vector1  : vector 1
                              Optimal values for vector1.fXDist 
                              [Half range of float32]
                              Optimal values for vector1.fYDist 
                              [Half range of float32]
  @param[in]       vector2  : vector 2 to add to vector 1
                              Optimal values for vector2.fXDist 
                              [Half range of float32]
                              Optimal values for vector2.fYDist 
                              [Half range of float32]

  @return          Sum of vectors

  @pre             -

  @post            -

  @author          jochen.spruck@contiautomotive.com

****************************************************************************/
Vector2_f32_t CML_vector2Addf32(Vector2_f32_t vector1, Vector2_f32_t vector2)
{
  Vector2_f32_t sum;
  sum.fXDist = vector1.fXDist + vector2.fXDist;
  sum.fYDist = vector1.fYDist + vector2.fYDist;
  return sum;
}

/*****************************************************************************

  Functionname:    CML_vector2Subf32                                       */ /*!

  @brief           Substract two float 32 vectors

  @description     This function subtracts two vectors whose x,y values are
                   defined by float32 values

  @param[in]       min  : vector 1
                          Optimal values for min.fXDist [Half range of float32]
                          Optimal values for min.fYDist [Half range of float32]
  @param[in]       sub  : substract sub from min
                          Optimal values for sub.fXDist [Half range of float32]
                          Optimal values for sub.fYDist [Half range of float32]

  @return          return vector substract min-sub

  @pre             -

  @post            -

  @author          jochen.spruck@contiautomotive.com

****************************************************************************/
Vector2_f32_t CML_vector2Subf32(Vector2_f32_t min, Vector2_f32_t sub)
{
  Vector2_f32_t result;
  result.fXDist = min.fXDist - sub.fXDist;
  result.fYDist = min.fYDist - sub.fYDist;
  return result;
}

/*****************************************************************************

  Functionname:    CML_b_vector2GetYPointOnLinef32                            */ /*!

  @brief           Get point on line x = Point +t*DirectionVector
                   input x position and the lane vectors 
                   returns false if x is never on the line, otherwise true

  @description     This function gets point on line x = Point +t*DirectionVector
                   input x position and the lane vectors.
                   returns false if x is never on the line, otherwise true

  @param[in]       Point            : Starting point of lane
                                      Optimal values for Point.fXDist 
                                      [-F_MAX..F_MAX]
                                      Optimal values for Point.fYDist 
                                      [-F_MAX..F_MAX]
                                      where F_MAX is square root of max range of float32.
  @param[in]       DirectionVector  : Direction vector of lane
                                      Supported values for DirectionVector.nXDist 
                                      [Full range of signed short]
                                      Supported values for DirectionVector.nYDist 
                                      [Full range of signed short]
  @param[in,out]   p_InOut          : input and output vector 
                                      (f(InOut.fXDist) = InOut.fYDist)
                                      Optimal values for p_InOut->fXDist 
                                      [-F_MAX..F_MAX]
                                      Optimal values for p_InOut->fYDist 
                                      [-F_MAX..F_MAX]
                                      where F_MAX is square root of max range of float32.
                                      As an output the structure supports full range 
                                      of float32.

  @return          returns false if x is never on the lane, otherwise true

  @pre             -

  @post            -

  @author          jochen.spruck@contiautomotive.com

****************************************************************************/
boolean CML_b_vector2GetYPointOnLinef32(Vector2_f32_t Point, Vector2_i16_t DirectionVector, Vector2_f32_t *p_InOut)
{
  boolean ret_value;
  if (DirectionVector.nXDist == 0)
  {
    p_InOut->fXDist = 0.0F;
    p_InOut->fYDist = 0.0F;
    ret_value = b_FALSE;
  }
  else
  {
    p_InOut->fYDist = Point.fYDist + ( ((p_InOut->fXDist - Point.fXDist)/(float32)DirectionVector.nXDist)*(float32)DirectionVector.nYDist);
    ret_value = b_TRUE;
  }
  return ret_value;
}

/*****************************************************************************

  Functionname:    CML_f_vector2GetSqrDistf32                                */ /*!

  @brief           Get the square dist of the vector

  @description     This function caculates the square distance of the vector
                   with values defined by float. 
                   r = x^2 + y^2

  @param[in]       input_vector : Input vector
                                  Optimal values for input_vector.fXDist 
                                  [-F_MAX..F_MAX]
                                  Optimal values for input_vector.fYDist 
                                  [-F_MAX..F_MAX]
                                  where F_MAX is square root of half the max range of float32.

  @return          the square distance of the vector

  @pre             -

  @post            -

  @author          jochen.spruck@contiautomotive.com

****************************************************************************/
float32 CML_f_vector2GetSqrDistf32(Vector2_f32_t input_vector)
{
  return SQR(input_vector.fXDist)+SQR(input_vector.fYDist);
}

/*****************************************************************************

  Functionname:    CML_f_vector2GetSqrDistI32f32                             */ /*!

  @brief           Get the square dist of a int 32 vector

  @description     This function caculates the square distance of the vector
                   with values defined by 32bit integer. 
                   r = x^2 + y^2

  @param[in]       input_vector : Input vector
                                  Supported values for input_vector.nYDist 
                                  [Full range of signed long]
                                  Supported values for input_vector.nYDist 
                                  [Full range of signed long]

  @return          the square distance of the vector

  @pre             -

  @post            -

  @author          jochen.spruck@contiautomotive.com

****************************************************************************/
float32 CML_f_vector2GetSqrDistI32f32(Vector2_i32_t input_vector)
{
  return SQR((float32)input_vector.nXDist)+SQR((float32)input_vector.nYDist);
}

/*****************************************************************************

  Functionname:    CML_f_vector2GetSqrDistI16f32                             */ /*!

  @brief           Get the square dist of a int 16 vector

  @description     This function caculates the square distance of the vector
                   with values defined by 16bit integer. 
                   r = x^2 + y^2

  @param[in]       input_vector : Input vector
                                  Supported values for input_vector.nYDist 
                                  [Full range of signed short]
                                  Supported values for input_vector.nYDist 
                                  [Full range of signed short]

  @return          the square distance of the vector

  @pre             -

  @post            -

  @author          jochen.spruck@contiautomotive.com

****************************************************************************/
float32 CML_f_vector2GetSqrDistI16f32(Vector2_i16_t input_vector)
{
  return SQR((float32)input_vector.nXDist)+SQR((float32)input_vector.nYDist);
}

/*****************************************************************************

  Functionname:    CML_f_vector2AngleToXAxisf32                              */ /*!

  @brief           Angle between vector and the x axis

  @description     This function caculates the angle between the given vector 
                   and x-axis. This function n turn calls the arctangent function
                   for the computation.

  @param[in]       input_vector : Input vector
                                  Optimal values for input_vector.fXDist 
                                  [-MAX_ANGLE,..,MAX_ANGLE], 
                                  Optimal values for input_vector.fYDist 
                                  [-MAX_ANGLE,..,MAX_ANGLE], 
                                  where MAX_ANGLE is cube root of max value of float32

  @return          the angle vector and x axis

  @pre             -

  @post            -

  @author          jochen.spruck@contiautomotive.com

****************************************************************************/
float32 CML_f_vector2AngleToXAxisf32(Vector2_f32_t input_vector)
{
  return ATAN2_(input_vector.fYDist,input_vector.fXDist);
}
