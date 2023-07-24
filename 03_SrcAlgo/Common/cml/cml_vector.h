/*! \file **********************************************************************

  COMPANY:                   Continental AG, A.D.C. GmbH

  CPU:                       CPU-Independent

  COMPONENT:                 CML (Common Math Library)

  MODULNAME:                 cml_vector.h

  DESCRIPTION:               Vector Computations Library

  AUTHOR:                    Jochen Spruck

  CREATION DATE:             24.10.2010

  VERSION:                   $Revision: 1.13 $

  ---*/ /*---
  CHANGES:                   $Log: cml_vector.h  $
  CHANGES:                   Revision 1.13 2017/11/24 07:06:00CET Kotre, Jeevan (uidk9586) (uidk9586) 
  CHANGES:                   Updated cml_vector with naming conventions.
  CHANGES:                   Revision 1.12 2017/11/15 10:31:25CET Kotre-EXT, Jeevan (uidk9586) 
  CHANGES:                   Updates done after review.
  CHANGES:                   Revision 1.11 2017/11/13 06:43:14CET Kotre-EXT, Jeevan (uidk9586) 
  CHANGES:                   Updated cml_vector module functions with coding standard naming convention.
  CHANGES:                   Revision 1.10 2017/10/13 11:15:59CEST Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   Corrected the function header format
  CHANGES:                   Revision 1.9 2017/09/27 05:58:48CEST Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   Merged from branch with Detailed Design
  CHANGES:                   Revision 1.8 2015/04/29 18:07:37CEST Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   - Changes with respect to Coding Guidelines
  CHANGES:                     of variables
  CHANGES:                   - Added comments -  uidr5428 [Apr 29, 2015 6:07:37 PM CEST]
  CHANGES:                   Change Package : 324617:3 http://mks-psad:7002/im/viewissue?selection=324617
  CHANGES:                   Revision 1.7 2014/12/05 10:11:36CET Schwarzkopf, Sebastian (uidg6516) 
  CHANGES:                   changed several function parameters of VectorWeightedPNorm() from pointer to array as they're accessed like that
  CHANGES:                   --- Added comments ---  uidg6516 [Dec 5, 2014 10:11:36 AM CET]
  CHANGES:                   Change Package : 266613:11 http://mks-psad:7002/im/viewissue?selection=266613
  CHANGES:                   Revision 1.6 2014/04/07 10:33:22CEST Schwarzkopf, Sebastian (uidg6516) 
  CHANGES:                   - fixed erroneous include protection
  CHANGES:                   --- Added comments ---  uidg6516 [Apr 7, 2014 10:33:22 AM CEST]
  CHANGES:                   Change Package : 227281:3 http://mks-psad:7002/im/viewissue?selection=227281
  CHANGES:                   Revision 1.5 2014/03/12 10:45:07CET Brendel, Matthias (uidv8244) 
  CHANGES:                   added weighted p-norm
  CHANGES:                   --- Added comments ---  uidv8244 [Mar 12, 2014 10:45:07 AM CET]
  CHANGES:                   Change Package : 223474:1 http://mks-psad:7002/im/viewissue?selection=223474
  CHANGES:                   Revision 1.4 2014/02/04 15:15:17CET Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   - improve code quality
  CHANGES:                   --- Added comments ---  uidu0849 [Feb 4, 2014 3:15:18 PM CET]
  CHANGES:                   Change Package : 159154:34 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.3 2013/05/03 09:58:26CEST Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   - drop algo_common from CML
  CHANGES:                   - use new standard type names, e.g. float32 instead of f32_t
  CHANGES:                   --- Added comments ---  uidu0849 [May 3, 2013 9:58:26 AM CEST]
  CHANGES:                   Change Package : 159154:27 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.2 2012/09/20 13:29:44CEST Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   - delete old log in file header
  CHANGES:                   --- Added comments ---  uidu0849 [Sep 20, 2012 1:29:44 PM CEST]
  CHANGES:                   Change Package : 159154:3 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.1 2012/09/14 14:31:19CEST Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/CML_CommonMathLibrary/04_Engineering/01_Source_Code/algo/cml/project.pj

**************************************************************************** */

/**
@defgroup vector VECTOR (Math Vector Library)
  @ingroup cml
@{ */

/*****************************************************************************
  INCLUDE PROTECTION
*****************************************************************************/

/* allow inclusion of cml sub-headers only if external cml header is included */
#ifndef _CML_EXT_INCLUDED
  #pragma message(__FILE__": Inclusion of cml_vector.h is discouraged. It exists only for compatibility with ARS3xx and might be deleted without prior notice. Include cml_ext.h instead.")
#endif /* #ifdef _CML_EXT_INCLUDED */

#ifndef _CML_VECTOR_INCLUDED
#define _CML_VECTOR_INCLUDED


/*****************************************************************************
  CONSTANTS
*****************************************************************************/
#define VECTOR_I32_VALUE_INVALID      0x7FFFFFFF

/*****************************************************************************
  FUNCTION DECLARATIONS
*****************************************************************************/

/*****************************************************************************
  i16 Vector Functions
*****************************************************************************/

/*****************************************************************************

  Functionname:    CML_v_vector2AddPi16                                      *//*! 

  \brief           Add two int 16 vectors
  
  \description     This function add two vectors whose x,y values are defined
                   by int16 values

  \InOutCorrelation
                   \f[If\ (x_1, y_1)\ and\ (x_2, y_2)\ are\ two\ input\ vectors,\ then\ resultant\ vector\ (x,y)\f]
                   \f[x = x_1 + x_2\f]  
                   \f[y = y_1 + y_2\f]
  \attention       
                   NOTE: vector2 values get updated with results of the sum.
  \param[in]       p_vector1  : pointer to vector 1
                                Optimal values for p_vector1->nXDist [Half range of signed short]
                                Optimal values for p_vector1->nYDist [Half range of signed short]
  \param[in,out]   p_vector2  : pointer to vector 2 
                                holds the sum after addition
                                Optimal values for p_vector2->nXDist [Half range of signed short]
                                Optimal values for p_vector2->nYDist [Half range of signed short]

  \return          void

  \author          jochen.spruck@contiautomotive.com

  \testmethod  
  \traceability   
****************************************************************************/
extern void CML_v_vector2AddPi16(const Vector2_i16_t * p_vector1, Vector2_i16_t * p_vector2);

/*****************************************************************************

  Functionname:    CML_v_vector2SubPi16                                      *//*! 

  \brief           Subtract two int 16 vectors

  \description     This function subtract two vectors whose x,y values are 
                   defined by int16 values

  \InOutCorrelation
                   \f[If\ (x_1, y_1)\ and\ (x_2, y_2)\ are\ two\ input\ vectors,\ then\ resultant\ scalar\ product\ is\f]
                   \f[x = x_1 - x_2\f]  
                   \f[y = y_1 - y_2\f]
  \attention       
                   NOTE: vector2 values get updated with results.
  \param[in,out]   p_min  : input vector 1 -> min = min - sub
                            Optimal values for p_min->nXDist [Half range of signed short]
                            Optimal values for p_min->nYDist [Half range of signed short]
  \param[in]       p_sub  : substract sub from min
                            Optimal values for p_sub->nXDist [Half range of signed short]
                            Optimal values for p_sub->nYDist [Half range of signed short]

  \return          void

  \author          jochen.spruck@contiautomotive.com

  \testmethod  
  \traceability    
****************************************************************************/
extern void CML_v_vector2SubPi16(Vector2_i16_t * p_min, const Vector2_i16_t * p_sub);

/*****************************************************************************

  Functionname:    CML_vector2Mulli16                                      *//*! 

  \brief           Multiplicate int 16 vector with a f32 factor

  \description     This function multiply vector whose x,y values are 
                   defined by int16 values with a float32 factor 

  \InOutCorrelation
                   \f[If\ (x_1, y_1)\ and\ (x_2, y_2)\ are\ two\ input\ vectors,\ then\ resultant\ scalar\ product\ is\f]
                   \f[x = x_1 \times F\f]  
                   \f[y = y_1 \times F\f]
  \param[in]       Vec      : input vector
                              Optimal values for Vec.nXDist [Full range of signed short]
                              Optimal values for Vec.nYDist [Full range of signed short]
  \param[in]       f_Factor : with this factor the input vector should be 
                              multiplied
                              Optimal Range [-F_MAX..F_MAX]
                              where F_MAX is square root of max range of float.

  \return          product of Vec and f_Factor

  \author          jochen.spruck@contiautomotive.com

  \testmethod  
  \traceability    
****************************************************************************/
extern Vector2_f32_t CML_vector2Mulli16(Vector2_i16_t Vec, float32 f_Factor);

/*****************************************************************************

  Functionname:    CML_s_vector2ScalarProdi16                                *//*!

  \brief           Scalar product of i16 vector

  \description     This function does the scalar multiplication of two vectors
                   whose x,y values are defined by int16 values

  \InOutCorrelation
                   \f[If\ (x_1, y_1)\ and\ (x_2, y_2)\ are\ two\ input\ vectors,\ then\ resultant\ scalar\ product\ is\f]
                   \f[P = x_1 \times x_2 + y_1 \times y_2\f]  
  \param[in]       Point1  : input vector 1
                             Supported values for Point1.nXDist [Full range of signed short]
                             Supported values for Point1.nYDist [Full range of signed short]
  \param[in]       Point2  : input vector 2
                             Supported values for Point2.nXDist [Full range of signed short]
                             Supported values for Point2.nYDist [Full range of signed short]

  \return          scalarproduct of input vectors

  \author          jochen.spruck@contiautomotive.com

  \testmethod  
  \traceability    
****************************************************************************/
extern sint32 CML_s_vector2ScalarProdi16(Vector2_i16_t Point1, Vector2_i16_t Point2);

/*****************************************************************************

  Functionname:    CML_s_vector2GetSqrDisti16t                              *//*! 

  \brief           Get the square dist of the vector
                   
  \description     The function returns the square distance of the vector
                   Limitation: When both inputs are least possible values
                   (negative), the result will overflow
                 
  \InOutCorrelation
                   \f[If\ (x, y)\ is\ an\ input\ vectors,\ then\ return\ value\ is\ : \f]
                   \f[r = x^2 + y^2\f]  
  \param[in]       input_vector  : input vector
                                   Supported values for input_vector.nXDist 
                                   [Full range of signed short]
                                   Supported values for input_vector.nYDist 
                                   [Full range of signed short]
                   
  \return          square distance of vector
                   
  \author          jochen.spruck@contiautomotive.com

  \testmethod  
  \traceability    
****************************************************************************/
extern sint32 CML_s_vector2GetSqrDisti16(Vector2_i16_t input_vector);

/***************************************************************************** 

  Functionname:    CML_v_vector2MathRotate2Di16                              *//*! 

  \brief           Calculate Transformation of Coordiantes using 
                   Transformation matrix M

  \description     This function calculates the transformation of cordinates
                   using the transfromation matrix.
                   Let the vector be defined by V = (x,y) and transformed vector
                   be V1 = (x1,y1) and the transformation matrix be 
                   \f[ M\ = 
                   \begin{bmatrix}
                   f_{00}    &   f_{01} \\
                   f_{10}    &   f_{11} \\
                   \end{bmatrix}
                   then,\\
                   x1 = x \times f_{00} - y \times f_{10}\\
                   y1 = x \times f_{10} + y \times f_{00}
                   \f]
  \InOutCorrelation
                   If M is input trafo matrix and (x,y) is an input vectors, then return
                   \f[x = x \times f_{00}\ -\ y \times f_{10}\f]
                   \f[y = x \times f_{10}\ +\ y \times f_{00}\f]
  \param[in]       p_Transform_Matrix : The transformation matrix
                                        Optimal values for p_Transform_Matrix->f00 
                                        [-F_MAX..F_MAX]
                                        Optimal values for p_Transform_Matrix->f10 
                                        [-F_MAX..F_MAX]
                                        where F_MAX is square root of max range of float.
  \param[out]      p_input_vector : Vector to be transformed
                                    Supported values for p_input_vector->nXDist 
                                    [Full range of signed short]
                                    Supported values for p_input_vector->nYDist 
                                    [Full range of signed short]

  \return          -

  \author          jochen.spruck@contiautomotive.com

  \testmethod  
  \traceability    
****************************************************************************/
extern void CML_v_vector2MathRotate2Di16(CML_t_TrafoMatrix2D const *p_Transform_Matrix , Vector2_i16_t *p_input_vector);

/*****************************************************************************

  Functionname:    CML_f_vector2AngleToXAxisi16                              *//*! 

  \brief           Angle between vector and the x axis

  \description     This function calculates the angle between given vector
                   and x-axis. This makes use of the arctangent function.Internally GDBatan2_66 has been defined to handle ATAN2_ functions.
                   Therefore GDBatan2_66 function would be called.

  \InOutCorrelation
                   \f[If\ (x,y)\ is\ an\ input\ vector,\ then\ function\ returns\f]
                   \f[ATAN2\_(x \ ,\ y) \f]
  \param[in]       input_vector  : input vector
                                   Optimal values for input_vector.nXDist 
                                   [Full range of signed short]
                                   Optimal values for input_vector.nYDist 
                                   [Full range of signed short]

  \return          Angle between vector and the x axis

  \author          jochen.spruck@contiautomotive.com

  \testmethod  
  \traceability    
****************************************************************************/
extern float32 CML_f_vector2AngleToXAxisi16(Vector2_i16_t input_vector);

/*****************************************************************************

  Functionname:    CML_v_vector2Initi16                                      *//*! 

  \brief           Init the Vector distances with zero

  \description     This function initializes x and y values of the given vector
                   with zero.

  \InOutCorrelation
                   \f[If\ (x,y)\ is\ an\ input\ vector,\ then\ function\ returns\f]
                   \f[x = 0 \\ y  = 0\f]
  \param[in]       p_Vector    : i16 vector to init
                                 [Valid pointer to the structure]

  \return          void

  \author          jochen.spruck@contiautomotive.com

  \testmethod  
  \traceability    
****************************************************************************/
extern void CML_v_vector2Initi16(Vector2_i16_t * p_Vector);

/*****************************************************************************
  i32 Vector Functions
*****************************************************************************/

/*****************************************************************************

  Functionname:    CML_vector2AddI16i32                                    *//*! 

  \brief           Add int 16 to an int 32  vectors

  \description     This function adds a vector whose x,y values are defined
                   by int16 values to another vector whose x,y values are 
                   defined by int32 values
  \InOutCorrelation
                   \f[ If\  (x_1, y_1)\ and\ (x_2, y_2)\ are\ two\ input\ vectors,\ then\ resultant\ vector\ (x,y) \f]
                   \f[x = x_1 + x_2\f]  
                   \f[y = y_1 + y_2\f]
                   
  \param[in]       input_vector1  : vector 1
                                    Optimal values for input_vector2.nXDist 
                                    [Half range of signed long]
                                    Optimal values for input_vector2.nYDist 
                                    [Half range of signed long]
  \param[in]       input_vector2  : vector 2 to add to vector 1
                                    Supported values for input_vector2.nXDist 
                                    [Full range of signed short]
                                    Supported values for input_vector2.nYDist 
                                    [Full range of signed short]
                   
  \return          Sum of vectors
                   
  \author          jochen.spruck@contiautomotive.com

  \testmethod  
  \traceability    
****************************************************************************/
extern Vector2_i32_t CML_vector2AddI16i32(Vector2_i32_t input_vector1, Vector2_i16_t input_vector2);

/*****************************************************************************

  Functionname:    CML_s_vector2ScalarProdi32                                *//*! 

  \brief           Scalar product of i32 vector

  \description     This function does the scalar multiplication of two vectors
                   whose x,y values are defined by int32 values
  \InOutCorrelation
                   \f[If\ (x_1, y_1)\ and\ (x_2, y_2)\ are\ two\ input\ vectors,\ then\ result\f]
                   \f[ result = x_1 \times x_2 + y_1 \times y_2 \f]
                   
  \param[in]       Point1  : input vector 1
                             Optimal values for Point1.nXDist 
                             [-S_MAX..S_MAX]
                             Optimal values for Point1.nYDist 
                             [-S_MAX..S_MAX]
                             where S_MAX is square root of half the max range of sint32.
  \param[in]       Point2  : input vector 1
                             Optimal values for Point2.nXDist 
                             [-S_MAX..S_MAX]
                             Optimal values for Point2.nYDist 
                             [-S_MAX..S_MAX]
                             where S_MAX is square root of half the max range of sint32.
                   
  \return          scalarproduct of input vectors
                   
  \author          jochen.spruck@contiautomotive.com

  \testmethod  
  \traceability    
****************************************************************************/
extern sint32 CML_s_vector2ScalarProdi32(Vector2_i32_t Point1, Vector2_i32_t Point2);

/*****************************************************************************

  Functionname:    CML_b_vector2YAxisIntersectionAddi32                      *//*! 

  \brief           Intersection of line defined with x = p1 +t*(p2-p1) and 
                   the y axis

  \description     This function calculates the intersection of line and 
                   y axis.
                   The calculation is based on basic line equation. 
  \InOutCorrelation
                   \f[If\ (x_1, y_1)\ and\ (x_2, y_2)\ are\ two\ input\ vector,\ then\  Line\ equation\ is\ :\f]
                   \f[
                   \frac{y-y_1}{y_2-y_1} = \frac{x-x_1}{x_2-x_1}
                     ==> y = y_1 + \frac{{(x-x_1)}{(y_2-y_1)}}{(x_2-x_1)}\\

                   and\ for\ Y\ intersection,\ x\ =\ 0,\ so,\\

                   y = y_1 - \frac{{x_1}{(y_2-y_1)}}{(x_2-x_1)}\f]

  \param[in]       Point1           : first point on lane
                                      Optimal values for Point2.nXDist 
                                      [-S_MAX..S_MAX]
                                      Optimal values for Point2.nYDist 
                                      [-S_MAX..S_MAX]
                                      where S_MAX is square root of max range of sint32.
  \param[in]       Point2           : second point on lane
                                      Optimal values for Point2.nXDist 
                                      [-S_MAX..S_MAX]
                                      Optimal values for Point2.nYDist 
                                      [-S_MAX..S_MAX]
                                      where S_MAX is square root of max range of sint32.
  \param[out]      p_YIntersection  : y value of lane with intersection with the y axis

  \return          true if intersection to y axis could be calculated otherwise false

  \author          jochen.spruck@contiautomotive.com

  \testmethod  
  \traceability    
****************************************************************************/
extern boolean CML_b_vector2YAxisIntersectionAddi32(Vector2_i32_t Point1, Vector2_i32_t Point2, sint32 *p_YIntersection);

/*****************************************************************************
  f32 Vector Functions
*****************************************************************************/

/*****************************************************************************

  Functionname:    CML_vector2Addf32                                       *//*! 

  \brief           Add two float 32 vectors

  \description     This function adds two vectors whose x,y values are defined
                   by float32 values

  \InOutCorrelation
                   \f[If (x_1, y_1) and (x_2, y_2) are two input vectors, then resultant vector (x,y)\f]
                   \f[x = x_1 + x_2\f]  
                   \f[y = y_1 + y_2\f]
  \param[in]       vector1  : vector 1
                              Optimal values for vector1.fXDist 
                              [Half range of float32]
                              Optimal values for vector1.fYDist 
                              [Half range of float32]
  \param[in]       vector2  : vector 2 to add to vector 1
                              Optimal values for vector2.fXDist 
                              [Half range of float32]
                              Optimal values for vector2.fYDist 
                              [Half range of float32]

  \return          Sum of vectors

  \author          jochen.spruck@contiautomotive.com

  \testmethod  
  \traceability    
****************************************************************************/
extern Vector2_f32_t CML_vector2Addf32(Vector2_f32_t vector1, Vector2_f32_t vector2);

/*****************************************************************************

  Functionname:    CML_vector2Subf32                                       *//*! 

  \brief           Substract two float 32 vectors

  \description     This function subtracts two vectors whose x,y values are
                   defined by float32 values
  \InOutCorrelation
                   \f[If\ (x_1, y_1)\ and\ (x_2, y_2)\ are\ two\ input\ vectors,\ then\ resultant\ scalar\ product\ is\f]
                   \f[x = x_1 - x_2\f]  
                   \f[y = y_1 - y_2\f]

  \param[in]       min  : vector 1
                          Optimal values for min.fXDist [Half range of float32]
                          Optimal values for min.fYDist [Half range of float32]
  \param[in]       sub  : substract sub from min
                          Optimal values for sub.fXDist [Half range of float32]
                          Optimal values for sub.fYDist [Half range of float32]

  \return          return vector substract min-sub

  \author          jochen.spruck@contiautomotive.com

  \testmethod  
  \traceability    
****************************************************************************/
extern Vector2_f32_t CML_vector2Subf32(Vector2_f32_t min, Vector2_f32_t sub);

/*****************************************************************************

  Functionname:    CML_b_vector2GetYPointOnLinef32                            *//*! 

  \brief           Get point on line x = Point +t*DirectionVector
                   input x position and the lane vectors 
                   returns false if x is never on the line, otherwise true

  \description     This function gets point on line x = Point +t*DirectionVector
                   input x position and the lane vectors.
                   returns false if x is never on the line, otherwise true
  \InOutCorrelation
                   \f[If\ (P_x, P_y)\ and\ (D_x, D_y)\ are\ two\ input\ vectors,\ then\ InOut\ vector\ (x,y)\ will\ be\f]
                   \f[ y = P_y + {\frac{x - P_x}{D_x}\times {D_y}}\f]

  \param[in]       Point            : Starting point of lane
                                      Optimal values for Point.fXDist 
                                      [-F_MAX..F_MAX]
                                      Optimal values for Point.fYDist 
                                      [-F_MAX..F_MAX]
                                      where F_MAX is square root of max range of float32.
  \param[in]       DirectionVector  : Direction vector of lane
                                      Supported values for DirectionVector.nXDist 
                                      [Full range of signed short]
                                      Supported values for DirectionVector.nYDist 
                                      [Full range of signed short]
  \param[in,out]   p_InOut          : input and output vector 
                                      (f(InOut.fXDist) = InOut.fYDist)
                                      Optimal values for p_InOut->fXDist 
                                      [-F_MAX..F_MAX]
                                      Optimal values for p_InOut->fYDist 
                                      [-F_MAX..F_MAX]
                                      where F_MAX is square root of max range of float32.
                                      As an output the structure supports full range 
                                      of float32.

  \return          returns false if x is never on the lane, otherwise true

  \author          jochen.spruck@contiautomotive.com

  \testmethod  
  \traceability    
****************************************************************************/
extern boolean CML_b_vector2GetYPointOnLinef32(Vector2_f32_t Point, Vector2_i16_t DirectionVector, Vector2_f32_t *p_InOut);

/*****************************************************************************

  Functionname:    CML_f_vector2GetSqrDistf32                                *//*! 

  \brief           Get the square dist of the vector

  \description     This function caculates the square distance of the vector
                   with values defined by float. 

  \InOutCorrelation
                   \f[If\ (x, y)\ is\ an\ input\ vectors,\ then\ return\ value\ is\ : \f]
                   \f[r = x^2 + y^2\f]  
  \param[in]       input_vector : Input vector
                                  Optimal values for input_vector.fXDist 
                                  [-F_MAX..F_MAX]
                                  Optimal values for input_vector.fYDist 
                                  [-F_MAX..F_MAX]
                                  where F_MAX is square root of half the max range of float32.

  \return          the square distance of the vector

  \author          jochen.spruck@contiautomotive.com

  \testmethod  
  \traceability    
****************************************************************************/
extern float32 CML_f_vector2GetSqrDistf32(Vector2_f32_t input_vector);

/*****************************************************************************

  Functionname:    CML_f_vector2GetSqrDistI32f32                             *//*! 

  \brief           Get the square dist of a int 32 vector

  \description     This function caculates the square distance of the vector
                   with values defined by 32bit integer. 

  \InOutCorrelation
                   \f[If\ (x, y)\ is\ an\ input\ vectors,\ then\ return\ value\ is\ : \f]
                   \f[r = x^2 + y^2\f]  

  \param[in]       input_vector : Input vector
                                  Supported values for input_vector.nYDist 
                                  [Full range of signed long]
                                  Supported values for input_vector.nYDist 
                                  [Full range of signed long]

  \return          the square distance of the vector

  \author          jochen.spruck@contiautomotive.com

  \testmethod  
  \traceability    
****************************************************************************/
extern float32 CML_f_vector2GetSqrDistI32f32(Vector2_i32_t input_vector);

/*****************************************************************************

  Functionname:    CML_f_vector2GetSqrDistI16f32                             *//*! 

  \brief           Get the square dist of a int 16 vector

  \description     This function caculates the square distance of the vector
                   with values defined by 16bit integer. 

  \InOutCorrelation
                   \f[If\ (x, y)\ is\ an\ input\ vectors,\ then\ return\ value\ is\ : \f]
                   \f[r = x^2 + y^2\f]    

  \param[in]       input_vector : Input vector
                                  Supported values for input_vector.nYDist 
                                  [Full range of signed short]
                                  Supported values for input_vector.nYDist 
                                  [Full range of signed short]

  \return          the square distance of the vector

  \pre             -

  \post            -

  \author          jochen.spruck@contiautomotive.com

  \testmethod  
  \traceability    
****************************************************************************/
extern float32 CML_f_vector2GetSqrDistI16f32(Vector2_i16_t input_vector);

/*****************************************************************************

  Functionname:    Vector2AngleToXAxis_i16                              *//*! 

  \brief           Angle between vector and the x axis

  \description     This function caculates the angle between the given vector 
                   and x-axis. This function n turn calls the arctangent function
                   for the computation.Internally GDBatan2_66 has been defined to handle ATAN2_ functions.
                   Therefore GDBatan2_66 function would be called.
  \InOutCorrelation
                   \f[If\ (x_1, y_1)\ is\ an\ input\ vectors,\ then\ return\ value\ is\ : \f]
                   \f[ATAN2\_(y \ ,\ x) \f]

  \param[in]       input_vector : Input vector
                                  Optimal values for input_vector.fXDist 
                                  [-MAX_ANGLE,..,MAX_ANGLE], 
                                  Optimal values for input_vector.fYDist 
                                  [-MAX_ANGLE,..,MAX_ANGLE], 
                                  where MAX_ANGLE is cube root of max value of float32

  \return          the angle vector and x axis

  \author          jochen.spruck@contiautomotive.com

  \testmethod  
  \traceability    
****************************************************************************/
extern float32 CML_f_vector2AngleToXAxisf32(Vector2_f32_t input_vector);

/*****************************************************************************
 
  Functionname:    CML_f_vectorWeightedPNorm                                   *//*!

  \brief           Computes the so called p norm of a vector
  
  \description     The implementation is using and modifying the input vectors
                   for computation.
                   u_exponent should be greter than 0, else return value will be 0.
                   vector value should be greater than 0. negative numbers are handled as zero.
  \InOutCorrelation
                   Let 
                   \f[A = [a1, a2, a3,..., an] = the\ vector, \\
                   W = [w1, w2, w3,..., wn] = weights,\\
                   n = length\\
                   p = exponent, then\ p-norm\ of\ the\ vector\ would\ be,\\
                   \f]
                   \f[Norm = {\frac{(w_1\times ({a_1}^p)) + (w_2\times ({a_2}^p)) + (w_3\times ({a_3}^p)) + ..
                          ..  + (w_n\times ({a_n}^p))}{(w_1 + w_2 + w_3 + .. + w_n)}}^{\frac{1}{p}}\f]

  \attention       
                   NOTE: The implementation is general and inefficient, should not be called thousands of times.
  
  \param[in,out]   a_vector :    The input values, they are modified in the function, negative numbers are handled az 0
                                 Supported values [Full range of float32]
  \param[in,out]   a_weights :   The weights, , they are modified in the function, negative numbers are handled az 0
                                 Supported values [Full range of float32]  
                                 Overflow may occur when one or more values are at extremities.
  \param[in]       u_length :    length of vector and weights
                                 Supported values [Full range of uint32]
  \param[in]       u_exponent :  exponent of the norm. shall be >0
                                 Supported values [Full range of uint32]
  
  
  
  \return           the norm
  
  \author          Matthias Brendel

  \testmethod  
  \traceability    
************************************************************************/
extern float32 CML_f_vectorWeightedPNorm(float32 a_vector[], float32 a_weights[], uint32 u_length, uint32 u_exponent);

#endif  /* #ifndef _CML_VECTOR_INCLUDED */


/** @} end defgroup */
