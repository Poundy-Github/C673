/*! \file **********************************************************************

  COMPANY:                 Continental AG, A.D.C. GmbH

  CPU:                     CPU-Independent

  COMPONENT:               CML (Common Math Library)

  MODULNAME:               cml_interpol.h

  DESCRIPTION:             interpolation functions of the CML

  AUTHOR:                  sebastian.schwarzkopf@continental-corporation.com

  CREATION DATE:           10.12.2014
 
  VERSION:                 $Revision: 1.5.1.2 $


  ---*/ /*---
  CHANGES:                 $Log: cml_interpol.h  $
  CHANGES:                 Revision 1.5.1.2 2019/06/21 15:15:07CEST Thomas, Jyothy (uid22555) 
  CHANGES:                 QAF Level3 fixes for MFC431TA19
  CHANGES:                 Revision 1.5.1.1 2019/05/27 10:59:24CEST Thomas, Jyothy (uid22555) 
  CHANGES:                 MFC431TA19: QAF L4 fixes added
  CHANGES:                 Revision 1.5 2018/02/26 08:50:04CET Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                 Updated the source code with respect to AL_CML_01.09.18_INT-1
  CHANGES:                 Revision 1.4 2017/11/14 18:41:41CET Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                 Updated to the code from AL_CML_01.09.13_INT-1
  CHANGES:                 Revision 1.3 2017/08/04 06:04:19CEST Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                 Aligned and merged changes from AL_CML_01.09.11_INT-1
  CHANGES:                 Revision 1.2 2015/04/29 14:10:26CEST Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                 - Changes with respect to Coding Guidelines
  CHANGES:                   of variables
  CHANGES:                 - Added comments -  uidr5428 [Apr 29, 2015 2:10:26 PM CEST]
  CHANGES:                 Change Package : 324617:1 http://mks-psad:7002/im/viewissue?selection=324617
  CHANGES:                 Revision 1.1 2014/12/10 13:18:56CET Schwarzkopf, Sebastian (uidg6516) 
  CHANGES:                 Initial revision
  CHANGES:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/CML_CommonMathLibrary/04_Engineering/01_Source_Code/algo/cml/project.pj

**************************************************************************** */

/**
@defgroup interpol INTERPOL (interpolation tools)
  @ingroup cml
@{ */

/*****************************************************************************
  INCLUDE PROTECTION
*****************************************************************************/
#ifndef CML_INTERPOL_INCLUDED
#define CML_INTERPOL_INCLUDED      ///< To avoid multiple inclusion of the file

/* allow inclusion of cml sub-headers only if external cml header is included */
#ifndef CML_EXT_INCLUDED
  #pragma message(__FILE__": Inclusion of cml_interpol.h is discouraged. It exists only for compatibility with ARS3xx and might be deleted without prior notice. Include cml_ext.h instead.")
#endif /* #ifdef CML_EXT_INCLUDED */

/*****************************************************************************
  QA-C
*****************************************************************************/
/* Check if we are in QA-C: PRQA_SIZE_T is defined in QA-C environment. */
#ifdef PRQA_SIZE_T
  /* Switch off QA-C warnings on side effects for functions, which don't have 
     any side effects and will sure never have some. */
  #pragma PRQA_NO_SIDE_EFFECTS CML_f_Sign
#endif /* #ifdef PRQA_SIZE_T */

/* Check if we are in QA-C: PRQA_SIZE_T is defined in QA-C environment. */
#ifdef PRQA_SIZE_T
  /* Switch off QA-C warnings on side effects for functions, which don't have 
     any side effects and will sure never have some. */
  #pragma PRQA_NO_SIDE_EFFECTS CML_f_linearInterpolation
  #pragma PRQA_NO_SIDE_EFFECTS CML_f_boundedLinInterpol
  #pragma PRQA_NO_SIDE_EFFECTS CML_f_boundedLinInterpol2
#endif /* #ifdef PRQA_SIZE_T */


/*****************************************************************************
  CONSTANTS
*****************************************************************************/

/*****************************************************************************
  TYPEDEFS
*****************************************************************************/

/*****************************************************************************
  MACROS
*****************************************************************************/

/*****************************************************************************
  FUNCTION DECLARATIONS
*****************************************************************************/

/*****************************************************************************
  Functionname:    CML_f_linearInterpolation                               *//*! 

  \brief           linear interpolation between two given points

  \description     This function computes the linear interpolation value 
                   between two given points. The interpolated value can be 
                   calculated using the following formula: 
                   y = mx + c;
                   where 'm' is the slope and 'c' is the offset. 
  \InOutCorrelation
                   Let m = Slope of the line and \n
                       c = Intercept of the line on Y axis. \n
                   Let (x1,y1) and (x2,y2) be the two points given on the line. 
                   For a given x, y can be found by,
                   \f[ m = \frac{y_2 - y_1}{x_2 - x_1} \\
                       c = y_1 - (m \times x_1) \\
                       y = (m \times x) + c
                   \f]
                     
  \param[in]       f_X1 :  x-coordinate of first point
                           [Full range of float32]
  \param[in]       f_Y1 :  y-coordinate of first point
                           [Full range of float32]
  \param[in]       f_X2 :  x-coordinate of second point
                           [Full range of float32]
  \param[in]       f_Y2 :  y-coordinate of second point
                           [Full range of float32]
  \param[in]       f_XPos :  x-value to interpolate
                             [Full range of float32]

  \return          the interpolated value

  \author          R. Ehrhardt

  \testmethod 
  \traceability    
*****************************************************************************/
extern float32 CML_f_linearInterpolation(float32 f_X1,  
                                         float32 f_Y1, 
                                         float32 f_X2, 
                                         float32 f_Y2, 
                                         float32 f_XPos); 

/*****************************************************************************
  Functionname:    CML_f_boundedLinInterpol                                 *//*!

  \brief           bounded linear interpolation between two given points

  \description     This function computes the bounded linear interpolation value 
                   between two given points. The minimum and maximum boundary 
                   values are taken from the input structure.
  \InOutCorrelation
                   With provided slope(m) and y intercept(c) of the line, y value for given
                   x value can be found by
                   \f[ y = (m \times x)  + c  \\
                      and\ output\ bounded\ in\ the\ range\ [y_{min}, y_{max}) \f]  

  \param[in]       p_Params : structure for parameters
                              Range for p_Params->dAmin is [Full range of float32]
                              Range for p_Params->dAmax is [Full range of float32]
                              Range for p_Params-> dM is [Full range of float32]
                              Range for p_Params-> dB is [Full range of float32]
                              Overflow may occur if all the input values to the function
                              are at maximum possible value at the same time.

  \param[in]       f_Value : x-value to interpolate
                             [Full range of float32]

  \return          the bounded interpolated value

  \author          R. Ehrhardt

  \testmethod 
  \traceability
*****************************************************************************/
extern float32 CML_f_boundedLinInterpol(CML_t_LinFunctionArgs const*const p_Params, const float32 f_Value); 

/*****************************************************************************
  Functionname:    CML_f_boundedLinInterpol2                                *//*!

  \brief           Calculates a linear Interpolation between two limiting points, 
                   bounding the input value

  \description     This function calculates a linear interpolation value between 
                   two limiting points, (Imin, Omin) and (Imax, Omax)
                   output value will be bounded between [Omin, Omax].
               
                                     +--------  Omax
                                    /:     
                                   / :  
                                  /  :    
                     Omin   -----+   :
                                 :   :
                               Imin  Imax
                               
  \InOutCorrelation
                   Let the I values represent the x coordinates of the points and 
                   O values represent the y coordinates, then,
                   \f[ Output  = O_{min} + ((I_{val} - I_{min}) \times \frac{(O_{max} - O_{min})}{(I_{max} - I_{min})}) \f]
                   The output value will be bounded between 
  \param[in]       f_IVal : input value
                            Optimal Range is [-F_MAX..F_MAX]
                            where F_MAX is one-third of the max range of float.
  \param[in]       f_Imin : x value of the lower point where the interpolation takes place
                            Optimal Range is [-F_MAX..F_MAX]
                            where F_MAX is one-third of the max range of float.
  \param[in]       f_Imax : x value of the upper point where the interpolation takes place
                            Optimal Range is [-F_MAX..F_MAX]
                            where F_MAX is one-third of the max range of float.
  \param[in]       f_Omin : limits of the interpolated output value
                            Optimal Range is [-F_MAX..F_MAX]
                            where F_MAX is one-third of the max range of float.
  \param[in]       f_Omax : limits of the interpolated output value
                            Optimal Range is [-F_MAX..F_MAX]
                            where F_MAX is one-third of the max range of float.

  \return          the interpolated value between [Omin, Omax] (returns (Omin+Omax)/2 if CML_f_IsZero(Imax-Imin))

  \author          Dan Oprisan

  \testmethod 
  \traceability    
*****************************************************************************/
extern float32 CML_f_boundedLinInterpol2(float32 f_IVal, float32 f_Imin, float32 f_Imax, float32 f_Omin, float32 f_Omax); 

/*****************************************************************************
  Functionname:    CML_f_BoundedLinInterpol3                             *//*!

  \brief           calculate an lin. interpolated value out of two points

  \description     This function calculates the linear interpolated value out 
                   of two points (X1,Y1) and (X2,Y2). The input value is
                   compared against the 'X' values of the given points, the
                   interpolated Y value is calculated bounded by the given
                   points and returned.
  \InOutCorrelation
                   Let Point1(x1,y1) and Point2(x2,y2) be two given points such that 
                   x2 > x1, then the output is given by  
                   \f[ y = y_1 + ((x - x_1) \times (\frac{y_2 - y_1}{x_2 - x_1}))   \f]
                   
  \param[in]       Point1 : first input point
                            Optimal Range for Point1.X is [-F_MAX..F_MAX]
                            where F_MAX is one-third of the max range of float.
                            Optimal Range for Point1.Y is [-F_MAX..F_MAX]
                            where F_MAX is one-third of the max range of float.
  \param[in]       Point2 : second input point
                            Optimal Range for Point2.X is [-F_MAX..F_MAX]
                            where F_MAX is one-third of the max range of float.
                            Optimal Range for Point2.Y is [-F_MAX..F_MAX]
                            where F_MAX is one-third of the max range of float.
  \param[in]       f_In   : x-value to be interpolated
                            Optimal Range for f_In is [-F_MAX..F_MAX]
                            where F_MAX is one-third of the max range of float.

  \return          interpolated value

  \author          Juergen Brugger

  \testmethod 
  \traceability
*****************************************************************************/
extern float32 CML_f_boundedLinInterpol3(CML_t_Point2D Point1, 
                                         CML_t_Point2D Point2, 
                                         float32 f_In); 

/*****************************************************************************
  Functionname:    CML_f_boundedLinInterpol4                                *//*!

  \brief           calculate an lin. interpolated value out of two vectors

  \description     This function calculate the linear interpolated value out 
                   of two given vectors (X1,Y1) and (X2,Y2). The input value is
                   compared against the 'X' distances of the given vector, the
                   interpolated Y distance is calculated bounded by the given
                   vectors and returned. The X and Y distances of vectors are 
                   defined by float values.
  \InOutCorrelation
                   Let Vector1(x1,y1) and Vector2(x2,y2) be two given points such that 
                   x2 > x1, then the output is given by  
                   \f[ y = y_1 + ((x - x_1) \times (\frac{y_2 - y_1}{x_2 - x_1}))   \f]

  \param[in]       Point1 :  first input vector
                             Optimal Range for Point1.fXDist is [-F_MAX..F_MAX]
                             where F_MAX is one-third of the max range of float.
                             Optimal Range for Point1.fYDist is [-F_MAX..F_MAX]
                             where F_MAX is one-third of the max range of float.
  \param[in]       Point2 :  second input vector
                             Optimal Range for Point2.fXDist is [-F_MAX..F_MAX]
                             where F_MAX is one-third of the max range of float.
                             Optimal Range for Point2.fYDist is [-F_MAX..F_MAX]
                             where F_MAX is one-third of the max range of float.
  \param[in]       f_In :    x-value to be interpolated
                             Optimal Range for f_In is [-F_MAX..F_MAX]
                             where F_MAX is one-third of the max range of float.

  \return          interpolated value

  \author          Juergen Brugger, Jochen Spruck

  \testmethod 
  \traceability    
*****************************************************************************/
extern float32 CML_f_boundedLinInterpol4(Vector2_f32_t Point1, 
                                         Vector2_f32_t Point2, 
                                         float32 f_In);

/*****************************************************************************
  Functionname:    CML_f_boundedLinInterpol5                                *//*!

  \brief           calculate an lin. interpolated value out of two vectors

  \description     This function calculate the linear interpolated value out 
                   of two given vectors (X1,Y1) and (X2,Y2). The input value is
                   compared against the 'X' distances of the given vector, the
                   interpolated Y distance is calculated bounded by the given
                   vectors and returned. The X and Y distances of vectors are 
                   defined by integer values.
  \InOutCorrelation
                   Let Vector1(x1,y1) and Vector2(x2,y2) be two given points such that 
                   x2 > x1, then the output is given by  
                   \f[ y = y_1 + ((x - x_1) \times (\frac{y_2 - y_1}{x_2 - x_1}))   \f]

  \param[in]       Point1 :  first input vector
                             Range for Point1.nXDist is [Full range of signed long]
                             Range for Point1.nYDist is [Full range of signed long]
  \param[in]       Point2 :  second input vector
                             Range for Point2.nXDist is [Full range of signed long]
                             Range for Point2.nYDist is [Full range of signed long]
  \param[out]      f_In :    x-value to be interpolated
                             Optimal Range for f_In is [-F_MAX..F_MAX]
                             where F_MAX is one-third of the max range of float.

  \return          interpolated value

  \author          Juergen Brugger, Jochen Spruck

  \testmethod 
  \traceability    
*****************************************************************************/
extern float32 CML_f_boundedLinInterpol5(Vector2_i32_t Point1, 
                                         Vector2_i32_t Point2, 
                                         float32 f_In); 

/*****************************************************************************
  Functionname:    CML_f_calculatePolygonValue                              *//*!

  \brief           Calculates the value of a polygon at a specific position

  \description     This function calculates the value of a polygon at a given 
                   position. The polygon is specified by the 2D sampling points 
                   (X,Y). The X-position is given by fInputValue.
                   The function returns the Y-Value at the given X-Position
                   based on the provided sampling points.
                   Let (x1,y1), (x2,y2),...(xn,yn) be the points provided by the
                   input table and xi be the input x value then,
                   @startuml
                   (*)-->[table,xi] If (xi<=x0)
                   --> [Yes] yi = y0
                   -->(*)
                   note left : Input is less than or equal to the minimum value
                   Else
                   --> [No] If (xi>=xn)
                   --> [Yes] yi = yn
                   -->(*)
                   note left : Input is greater than or equal to the maximum value
                   Else
                   --> [No] Find index value r, such that xr < xi
                   --> Find the difference d = xr - xs, where s = r - 1
                   --> Calculate the weightage, w = (xi-xs)/d
                   note left : In case d = 0, then avoid calculation and assign w = 0
                   --> Compute yi = (ys*(1-w)) + (yr * w)
                   -->(*)
                   EndIf
                   EndIf
                   @enduml
  \param[in]       s_NrOfTableRows : number of samplings points in parameter pTable
                   This value must be a positive integer greater than or equal to 1.
  \param[in]       a_Table : pointer to the sampling points. Note: has to be
                   sorted in X (X ascending)!
                   Range for a_Table[].f0 is [Full range of float32]
                   Range for a_Table[].f1 is [Full range of float32]
  \param[in]       f_InputValue : the X value for which the linear interpolated
                   Y bases on 'pTable' shall be returned.
                   [Full range of float32]

  \return          The y-value at the specified x-position

  \author          Robert Thiel

  \testmethod 
  \traceability    
*****************************************************************************/
extern float32 CML_f_calculatePolygonValue(sint32 s_NrOfTableRows, 
                                           const GDBVector2_t a_Table[], 
                                           float32 f_InputValue);

/* ***********************************************************************
  Functionname:    CML_b_calculateCubicSplineClamped                     *//*!

  \brief           Determine a "clamped" cubic spline (y'[0] = f_SlopeStart 
                   and y'[end] = f_SlopeEnd) based on given shape points

  \description     This function determine a "clamped" cubic spline 
                   (y'[0] = f_SlopeStart and y'[end] = f_SlopeEnd) based on 
                   given shape points. The coefficient arrays from the 
                   following formula are calculated.
                   y = A[i] + B[i] * (x - x_i) + C[i]*(x - x_i)^2 + D[i]*(x - x_i)^3 \n
                   for x in [x_i x_(i+1)] \n
                   i = 0 till (ui_NrOfShapePoints - 1). \n
                   With the given number of shape points and the shape point table, 
                   We need to find the four coefficient arrays ParA, ParB, ParC and ParD.
                   @startuml
                   legend  
                   Figure (1)
                   endlegend
                   (*)--> Calculate the Y Vector 
                   --> Y[0] = start of slope, Y[n] = end of slope 
                   note left : n is one less than the number of shape points
                   --> Y[] =  3 * ( (DeltaY1/(DeltaX1^2)) + (DeltaY2/(DeltaX2^2)) );
                   note left #aqua
                   Calculation for Y[1] to Y[n-2]. In case any of the denominator 
                   required for the calculation is zero, the corresponding Y vector 
                   element is also set to zero.
                   end note
                   note right #FFAAAA
                   For Y[j], let  i = j-1, k= j+1, \n
                   DeltaY1 = yj - yi, DeltaX1 = xj - xi \n
                   DeltaY2 = yk - yj, DeltaX2 = xk - xj \n
                   end note
                   --> Compute the B Matrix
                   note right : The computation happens as per figure (2)
                   --> Find inverse of B matrix
                   --> Find the product (P) of inverse of B matrix and the Y vector
                   --> Loop for j=0 to (number of shape points - 1) 
                   --> Compute DeltaX = xk - xj, DeltaY = yk - yj
                   note right : k = j+1
                   If (|DeltaX| > 0)
                   --> [Yes] ParB[j] = P[j]
                   --> ParA[j] = yj
                   note left : y value of the j th shape point
                   --> ParC[j] = (((3 * (DeltaY/DeltaX)) - R[k]) - (2 * ParaB[j]))/DeltaX
                   --> ParD[j] = ((R[k] + a_ParaB[j]) - (2 *(DeltaY/DeltaX)))/((DeltaX)^2);
                   --> Check if loop is complete.
                   Else
                   --> [No] ParA[j] = ParB[j] = ParC[j] = ParD[j] = 0
                   EndIf
                   --> Check if loop is complete.
                   If Is Loop Complete ?
                   --> [No] Loop for j=0 to (number of shape points - 1)
                   Else
                   --> [Yes] (*)
                   EndIf
                   @enduml

                   @startuml
                   legend
                   Figure (2)
                   endlegend
                   --> Loop for i =0 to (no. of shape points)
                   --> DeltaX1 = xj - xi and DeltaX2 = xi - xk
                   note left 
                   j = i + 1, DeltaX1 = 0 when i = no. of shape points -1, 
                   k = i - 1, DeltaX2 = 0 when i = 0, 
                   end note
                   --> Initialize each column of B matrix to zero
                   note left #aqua
                   All the denominators from next section are verified to be non zero.
                   In case the denominators happen to be zero, then ith element of B matrix is set to 1.
                   end note
                   --> Set the (i-1)th element in each column ,\n BMatrix[(i * no. of shape points) + (i - 1)] = -1/DeltaX2
                   note right : Operation is done if i > 1, if i = 1, then ,BMatrix[(i * no. of shape points)] = 0
                   --> Set the i-th element in each column, \n BMatrix[(i * no. of shape points) + i] = 2 * ( (1/DeltaX2) + (1/DeltaX1) )
                   note left : Operation is done if i is in between 1 and one less than no. of shape points, otherwise, BMatrix[(i * no. of shape points) + i] = 1
                   --> Set the (i+1)-th element in each column, \n BMatrix[(i * no. of shape points) + (i + 1)] = 1/DeltaX1
                   note right : Operation is done if (i+2) is less than no. of shape points, otherwise, BMatrix[(i * no. of shape points) + (i + 1)] = 0
                   --> Continue the loop for no.of shape points.
                   --> (*)
                   @enduml
  \attention       The function do not validate the array argument address. Make sure
                   to pass a valid address
  \param[in]       u_NrOfShapePoints :     Number of shape points
                                           optimal range of values [0,..,255]
  \param[in]       a_ShapePointTable :     Table containing the x- and y-coordinates 
                                           of the shape points; size: ui_NrOfShapePoints x 1
                                           [Valid float vector array]
  \param[in]       f_SlopeStart :          Slope at the first shape point
                                           [Full range of float32]
                                           Overflow may occur when input values 
                                           are at the defined range extremities.
  \param[in]       f_SlopeEnd :            Slope at the last shape point
                                           [Full range of float32]
                                           Overflow may occur when input values 
                                           are at the defined range extremities.
  \param[in]       a_BMatrix :             Matrix for calculating a_ParaB; 
                                           [Valid float array]
                                           size: ui_NrOfShapePoints x ui_NrOfShapePoints
  \param[in]       a_BMatrixInv :          Inverse matrix of a_BMatrix -> 
                                           a_BMatrixInv = a_BMatrix^-1;
                                           [Valid float array]
                                           size: ui_NrOfShapePoints x ui_NrOfShapePoints
  \param[in]       a_Temp :                Temporary matrix for calculating a_BMatrixInv; 
                                           [Valid float array]
                                           size: ui_NrOfShapePoints x ui_NrOfShapePoints
  \param[in]       a_YVector :             Vector for calculating a_ParaB, contains 
                                           x- and y-differences between shape points; 
                                           [Valid float array]
                                           size: ui_NrOfShapePoints x 1
  \param[in]       a_BInvXYVec :           Vector for calculating 
                                           a_ParaB -> a_BInvXYVec = a_BMatrixInv * a_YVector; 
                                           [Valid float array]
                                           size: ui_NrOfShapePoints x 1
  \param[in]       a_SegmentSplineValid :  array with data if a spline segment is valid or not.
                                           [Valid Boolean array]

  \param[out]      a_ParaA :               Coefficient A for each segment
                                           [Valid float array]
  \param[out]      a_ParaB :               Coefficient B for each segment 
                                           [Valid float array]
  \param[out]      a_ParaC :               Coefficient C for each segment 
                                           [Valid float array]
  \param[out]      a_ParaD :               Coefficient D for each segment
                                           [Valid float array]
                                           (number of segments = ui_NrOfShapePoints - 1)

  \return          b_ResultValid :         Info if results are valid

  \author          Marie-Theres Boll

  \testmethod 
  \traceability    
*****************************************************************************/
extern boolean CML_b_calculateCubicSplineClamped(const uint32 u_NrOfShapePoints, 
                                               const Vector2_f32_t a_ShapePointTable[], 
                                               const float32 f_SlopeStart, 
                                               const float32 f_SlopeEnd, 
                                               float32 a_BMatrix[], 
                                               float32 a_BMatrixInv[], 
                                               float32 a_Temp[], 
                                               float32 a_YVector[], 
                                               float32 a_BInvXYVec[], 
                                               float32 a_ParaA[], 
                                               float32 a_ParaB[], 
                                               float32 a_ParaC[], 
                                               float32 a_ParaD[], 
                                               boolean a_SegmentSplineValid[]);


/*****************************************************************************
  Functionname:    CML_f_piecewiseLinearInterpolation                                */ /*!
  
  @brief           Computes a piecewise linear function, based on the input points.
  
  @description     Computes a piecewise linear function, based on the supporting
                   points given as input. The linear pieces at both end are continued
                   to +-infinity.
    
  @param[in]       f_InputValue : the value of the input (x) of the function.[Full range of float]
  @param[in,out]   f_XValues : x values of the supporting points. [Array of float, should be increasing in seqeunce]
  @param[in,out]   f_YValues : y values of the supporting points. [Array of float]
  @param[in]       s_NBPoints : the number of supporting points.  [Array length]
  
  @pre             f_XValues and f_YValues shall be filled with coordinates of s_NBPoints number of points
                   defining the wished function shape.

  @return          float32
  
  @author          Jeevan Kotre

*****************************************************************************/

float32 CML_f_piecewiseLinearInterpolation(float32 f_InputValue, const float32 f_XValues[], const float32 f_YValues[], uint32 u_NBPoints);
#endif /* #ifndef CML_INTERPOL_INCLUDED */


/** @} end defgroup */
