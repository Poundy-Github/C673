/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   ARS5xx

CPU:                       CPU-Independent

COMPONENT:                 CAL (Common ACC Library)

PACKAGENAME:               cal_lineseg.c

DESCRIPTION:               Functionalities for line segment calculations

AUTHOR:                    Shang, Hanyu

CREATION DATE:             27.02.2017

VERSION:                   $Revision: 1.9 $

LEGACY VERSION:            Revision: 2.1


**************************************************************************** */
/*****************************************************************************
  INCLUDES
*****************************************************************************/

/*! @todo: later clean-up include structure to only include "cp.h" and let it
include the files necessary for our run-time environment */

#include "cal_int.h"/* PRQA S 0380
date: 28/06/2019 author: Pruthvi Reason: Can be ignored as no functional impact */

#if (FCT_CFG_ACC_CAL)
#if (0) /* Disabling unused functions */

/*****************************************************************************
  MACROS
*****************************************************************************/
/*! Static switch to enable extending point lists at both ends to infinite
distance. Note: this switch has to be on, so functions CAL_f_CalculatePoint2SamplesDist,
CPCalculatePoint2TraceDist etc. boolean parameter for extending end segments
has any effect! */
#define CAL_CFG_EXTEND_SAMPLE_END_LINE_SEGS  1

/*****************************************************************************
  FUNCTION
*****************************************************************************/

/* The following static functions are only used for testing - but may be
activated later for other use */
// PRQA S 7013 STTLN_EXCEEDED
/* date: 2015-05-18, reviewer: Gangadhar Badiger, reason: Number of lines exceeded per file, not safety critical */

/*************************************************************************************************************************
  Functionname:    CAL_f_CalculatePoint2LineDist                                                                        */ /*!

  @brief           Calculate signed distance between a line of infinite length and a given point

  @description     Calculate signed distance between a line of infinite length and a given point. The distance
                   is perpendicular to the line. The line is defined by two points connecting the two.
                   The distance returned is signed: it is negative, when the point is on the 'left' side of the
                   line (meaning when looking from pLineSeg1 into the direction of pLineSeg2, then the point
                   is to the left).
                   Ranges for input parameters are based on assumption about probable use.

                   @startuml
                   Start
                   Partition CAL_f_CalculatePoint2LineDist {

                   : calculate the square of the length of the line segment;
                   if (**If square of the distance of the line segment is non-zero**) then (Yes)
                        : The distance between the given point and the line segment is \n calculated as the cross product divided by the length of the line segment;
                   else (No)
                        : The two points of the line segment are one. \n Calculate the distance between this point and the line segment;
                   Endif
                   
                   }
                   Stop
                   @enduml

  @return          fDist : The distance of the point from the infinite line [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m

  @param[in]       pLineSeg1 : Pointer to the first point of the line [GDBVector2_t as defined in cml_mapping.h]
                      f0 : First dimension of the two-dimensional vector  [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                      f1 : Second dimension of the two-dimensional vector [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @param[in]       pLineSeg2 : Pointer to the second point of the line [GDBVector2_t as defined in cml_mapping.h]
                      f0 : First dimension of the two-dimensional vector  [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                      f1 :Second dimension of the two-dimensional vector  [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @param[in]       pPoint : Pointer to the point for which the distance to the line shall be calculated [GDBVector2_t as defined in cml_mapping.h]
                      f0 : First dimension of the two-dimensional vector  [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                      f1 : Second dimension of the two-dimensional vector [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m

  @glob_in         No global input variable used
  @glob_out        No global output variable used

  @c_switch_part   -
  @c_switch_full   FCT_CFG_COURSE_PREDICTION : Switch to configure FCT support for CP sub-component

  @pre             None
  @post            None

  @InOutCorrelation   None

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis). \n
                   Test of run time error/warnings (Static code analysis).

  @traceability    <a href="doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-495-0009fc80">CAL_495</a> \n

  @created         -
  @changed         14.03.2016

  @author          Gergely Ungvary | Gergely.Ungvary@continental-corporation.com
*************************************************************************************************************************/
fDistance_t CAL_f_CalculatePoint2LineDist(const GDBVector2_t * pLineSeg1, const GDBVector2_t * pLineSeg2, const GDBVector2_t * pPoint)
{
  fDistance_t fDist;
  /* We need the length of the line segment: calculate the square length here */
  const fDistance_t fLineSegLenSq = (SQR(pLineSeg2->f0 - pLineSeg1->f0) + SQR(pLineSeg2->f1 - pLineSeg1->f1));
  /* If the line segment has a length (i.e.: is non zero), then we can use a formula
  as described by http://mathworld.wolfram.com/images/equations/Point-LineDistance2-Dimensional/NumberedEquation8.gif
  and http://mathworld.wolfram.com/images/eps-gif/PointLineDistance2DVec_1000.gif */
  if (fLineSegLenSq > C_F32_DELTA)
  {
    /* Calculate cross product */
    fDist = (((pLineSeg2->f0 - pLineSeg1->f0)*(pLineSeg1->f1 - pPoint->f1)) - ((pLineSeg1->f0 - pPoint->f0)*(pLineSeg2->f1 - pLineSeg1->f1)));
    /* Take signed cross product and divide by square root of square line length */
    fDist = (fDist / SQRT_(fLineSegLenSq));
  }
  else
  {
    /* The two points of the line-segment are indeed one: in this case the distance
    is the distance to this point */
    fDist = SQRT_(SQR(pPoint->f0 - pLineSeg1->f0) + SQR(pPoint->f1 - pLineSeg1->f1));
  }
  
  return fDist;
}

/*************************************************************************************************************************
  Functionname:    CAL_f_CalculatePoint2LineSegDist                                                                     */ /*!

  @brief           Calculate signed distance between finite line segment and a given point

  @description     Calculate signed distance between finite line segment and a given point.
                   Ranges for input parameters are based on assumption about probable use.

                    @startuml
                    Start
                    Partition CAL_f_CalculatePoint2LineSegDist {

                    : calculate the square of the length of the line segment;
                    if (**square of length of the line segment is non-zero**) then (yes)
                        : calculate cross product of given point and points of line segment;
                        : calculate distance between given point and line;
                        if (** cross product is negative**) then 
                            : point lies on left and distance is negative;
                        Else (no)
                            : point lies on right and distance is positive;
                         endif
                    else (no)
                         : The two points of the line segment are one. \n Calculate the distance between this point and the line segment;
                    endif
                    }
                    Stop
                    @enduml

  @return          fDist : Perpendicular distance of the point from the finite line segment [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m

  @param[in]       pLineSeg1 : Pointer to the first point of the line [GDBVector2_t as defined in cml_mapping.h]
                      f0 : First dimension of the two-dimensional vector  [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                      f1 : Second dimension of the two-dimensional vector [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @param[in]       pLineSeg2 : Pointer to the second point of the line [GDBVector2_t as defined in cml_mapping.h]
                      f0 : First dimension of the two-dimensional vector  [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                      f1 :Second dimension of the two-dimensional vector  [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @param[in]       pPoint : Pointer to the point for which the distance to the line shall be calculated [GDBVector2_t as defined in cml_mapping.h]
                      f0 : First dimension of the two-dimensional vector  [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                      f1 : Second dimension of the two-dimensional vector [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m

  @glob_in         No global input variable used
  @glob_out        No global output variable used

  @c_switch_part   -
  @c_switch_full   FCT_CFG_COURSE_PREDICTION : Switch to configure FCT support for CP sub-component

  @pre             None
  @post            None

  @InOutCorrelation   None

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis). \n
                   Test of run time error/warnings (Static code analysis).

  @traceability    <a href="doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-496-0009fc80">CAL_496</a> \n

  @created         -
  @changed         18.03.2016

  @author          Gergely Ungvary | Gergely.Ungvary@continental-corporation.com
*************************************************************************************************************************/
fDistance_t CAL_f_CalculatePoint2LineSegDist(const GDBVector2_t * pLineSeg1, const GDBVector2_t * pLineSeg2, const GDBVector2_t * pPoint)
{
  fDistance_t fDist;
  /* We need the length of the line segment: calculate the square length here */
  const fDistance_t fLineSegLenSq = (SQR(pLineSeg2->f0 - pLineSeg1->f0) + SQR(pLineSeg2->f1 - pLineSeg1->f1));
  /* If the line segment has a length (i.e.: is non zero), then we can use a formula
  as described by http://mathworld.wolfram.com/images/equations/Point-LineDistance2-Dimensional/NumberedEquation8.gif
  and http://mathworld.wolfram.com/images/eps-gif/PointLineDistance2DVec_1000.gif */
  if (fLineSegLenSq > C_F32_DELTA)
  {
    const float32 fPoint1DistSq = (SQR(pPoint->f0 - pLineSeg1->f0) + SQR(pPoint->f1 - pLineSeg1->f1));
    const float32 fPoint2DistSq = (SQR(pPoint->f0 - pLineSeg2->f0) + SQR(pPoint->f1 - pLineSeg2->f1));
    float32 fCrossProd;

    /* Calculate cross product */
    fCrossProd = (((pLineSeg2->f0 - pLineSeg1->f0)*(pLineSeg1->f1 - pPoint->f1)) - ((pLineSeg1->f0 - pPoint->f0)*(pLineSeg2->f1 - pLineSeg1->f1)));
    /* Now the sign of the fCrossProd intermediate result tells us, on which side
    of the line the pPoint is on (negative: left, positive: right)
    using Pythagoras theorem, decide if distance to line or distance
    to point (with sign adjustment) shall be used */
    if ((fPoint1DistSq + fLineSegLenSq) >= fPoint2DistSq)
    {
      if ((fPoint2DistSq + fLineSegLenSq) >= fPoint1DistSq)
      {
        /* Take signed cross product and divide by square root of square line length */
        fDist = (fCrossProd / SQRT_(fLineSegLenSq));
      }
      else
      {
        /* Distance to line segment is distance to point 2 */
        fDist = SQRT_(fPoint2DistSq);
        if (fCrossProd < 0.0F)
        {
          fDist = -fDist;
        }
      }
    }
    else
    {
      /* Distance to line segment is distance to point 1 */
      fDist = SQRT_(fPoint1DistSq);
      if (fCrossProd < 0.0F)
      {
        fDist = -fDist;
      }
    }
  }
  else
  {
    /* The two points of the line-segment are indeed one: in this case the distance
    is the distance to this point */
    fDist = SQRT_(SQR(pPoint->f0 - pLineSeg1->f0) + SQR(pPoint->f1 - pLineSeg1->f1));
  }
  
  return fDist;
}

/*************************************************************************************************************************
  Functionname:    CAL_f_CalculateAbsPoint2LineSegDist                                                                  */ /*!

  @brief           Calculate absolute distance between finite line segment and a given point

  @description     Calculate absolute distance between finite line segment and a given point.
                   Ranges for input parameters are based on assumption about probable use.

                   @startuml
                   Start
                   Partition CAL_f_CalculateAbsPoint2LineSegDist {

                   : calculate the square of the length of the line segment;
                   if (**square of the length of the line segment is non-zero**) then (yes)
                       : calculate the normal vector of line segment;
                       : calculate length of vector pointing to perpendicular projection point;
                       If (** length of vector is positive**) then (yes)
                            if (**length of vector is less than or equal to square of line segment length**) then (yes) 
                               : calculate the distance with projection point lying between the line segment;
                            Else (no)
                               : calculate the distance with projection point lying to right of the line segment;
                            Endif
                       Else (no)
                            : calculate the distance with projection point lying to left of the line segment;
                       endif
                   else (no)
                         : The two points of the line segment are one. \n Calculate the distance between this point and the line segment;
                   endif
                   }
                   Stop
                   @enduml

  @return          fDist : Perpendicular distance of the point from the finite line segment

  @param[in]       pLineSeg1 :
                      f0 : First dimension of the starting point of the line segment    [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                      f1 : Second dimension of the starting point of the line segment   [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @param[in]       pLineSeg2 :
                      f0 : First dimension of the starting point of the line segment    [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                      f1 : Second dimension of the starting point of the line segment   [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @param[in]       pPoint :
                      f0 : First dimension of the point for which the distance to the line shall be calculated  [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                      f1 : Second dimension of the point for which the distance to the line shall be calculated [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m

  @glob_in         No global input variable used
  @glob_out        No global output variable used

  @c_switch_part   -
  @c_switch_full   FCT_CFG_COURSE_PREDICTION : Switch to configure FCT support for CP sub-component

  @pre             None
  @post            None

  @InOutCorrelation   None

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis). \n
                   Test of run time error/warnings (Static code analysis).

  @traceability    <a href="doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-497-0009fc80">CAL_497</a> \n

  @created         -
  @changed         15.03.2016

  @author          Gergely Ungvary | Gergely.Ungvary@continental-corporation.com
*************************************************************************************************************************/
fDistance_t CAL_f_CalculateAbsPoint2LineSegDist(const GDBVector2_t * pLineSeg1, const GDBVector2_t * pLineSeg2, const GDBVector2_t * pPoint)
{
  fDistance_t fDist;
  /* We need the length of the line segment: calculate the square length here */
  const fDistance_t fLineSegLenSq = (SQR(pLineSeg2->f0 - pLineSeg1->f0) + SQR(pLineSeg2->f1 - pLineSeg1->f1));
  if (fLineSegLenSq > C_F32_DELTA)
  {
    float32 fLineSegNormVecDot;
    GDBVector2_t LineNormVec;
    /* For ease of use calculate inverse of line segment length */
    const float32 fLineSegLenInv = (1.0f / SQRT_(fLineSegLenSq));
    /* Calculate line segment normal vector */
    LineNormVec.f0 = (pLineSeg2->f0 - pLineSeg1->f0)*fLineSegLenInv;
    LineNormVec.f1 = (pLineSeg2->f1 - pLineSeg1->f1)*fLineSegLenInv;
    /* Calculate the dot product of the line segment normal vector and the vector pointing from
    pLineSeg1 to pPoint. Basically this is the length of the vector pointing from pLineSeg1
    point into the perpendicular projection point on the line from the pPoint. */
    fLineSegNormVecDot = ((pPoint->f0 - pLineSeg1->f0) * LineNormVec.f0) + ((pPoint->f1 - pLineSeg1->f1) * LineNormVec.f1);
    /* Now we have the length of the vector pointing to the perpendicular projection point.
    If this length is negative, then this means the projection point lies beyond pLineSeg1,
    if this length is greater then the length of the pLineSeg1-pLineSeg2 line segment, then
    it lies beyond pLineSeg2. If neither of the previous two cases is met, then we have the
    'normal' case, when the perpendicular projection point is between pLineSeg1 pLineSeg2. */
    if (fLineSegNormVecDot >= 0.0F)
    {
      if (SQR(fLineSegNormVecDot) <= fLineSegLenSq)
      {
        /* The perpendicular projection point of pPoint to the line between pLineSeg1 & pLineSeg2
        lies in between pLineSeg1 and pLineSeg2 */
        GDBVector2_t PerpendPoint;
        PerpendPoint.f0 = ((LineNormVec.f0 * fLineSegNormVecDot) + pLineSeg1->f0);
        PerpendPoint.f1 = ((LineNormVec.f1 * fLineSegNormVecDot) + pLineSeg1->f1);
        fDist = SQRT_(SQR(pPoint->f0 - PerpendPoint.f0) + SQR(pPoint->f1 - PerpendPoint.f1));
      }
      else
      {
        /* The perpendicular projection point of pPoint lies beyond pLineSeg2 */
        fDist = SQRT_(SQR(pPoint->f0 - pLineSeg2->f0) + SQR(pPoint->f1 - pLineSeg2->f1));
      }
    }
    else
    {
      /* The perpendicular projection point of pPoint lies beyond pLineSeg1 */
      fDist = SQRT_(SQR(pPoint->f0 - pLineSeg1->f0) + SQR(pPoint->f1 - pLineSeg1->f1));
    }
  }
  else
  {
    /* pLineSeg1 and pLineSeg2 are in reality the same point */
    fDist = SQRT_(SQR(pPoint->f0 - pLineSeg1->f0) + SQR(pPoint->f1 - pLineSeg1->f1));
  }
  
  return fDist;
}

/*************************************************************************************************************************
  Functionname:    CAL_f_CalculatePoint2SamplesDist                                                                     */ /*!

  @brief           Calculate signed distance between samples (line segments) and a point

  @description     Calculates the signed distance between a CAL_t_PosSamples structure, which
                   defines a list of contiguous line segments and a point. If the
                   samples structure contains at least two sample points, then
                   it consists of one or more line segments.
                   If the samples structure consists of a single sample point,
                   then the return value is the distance from that point.
                   If the samples structure contains no points, then it returns
                   the predefined CAL_INFINITE_DIST value
                   Otherwise it returns the signed distance from the closest line
                   segment, with negative values denoting that the point is 'left'
                   of the line segment.
                   
                   @startuml
                   Start
                   Partition CAL_f_CalculatePoint2SamplesDist {

                   : Calculate signed distance between list of contiguous line segments \n and given point;
                   }
                   Stop
                   @enduml
                   

  @return          fDistance_t : Signed distance between line segments and point [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m

  @param[in]       pSamples : Pointer to structure containing the samples [CAL_t_PosSamples as defined in cp_ext.h]
                      fx : Array of longitudinal coordinates [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m of size pSamples->nb_samples
                      fy : Array of lateral coordinates      [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m of size pSamples->nb_samples
                      nb_samples : Number of samples [full range of uint8]
  @param[in]       fPointX : Longitudinal coordinate of given point [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
  @param[in]       fPointY : Lateral coordinate of given point [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @param[in]       bExtendSampleEnds :  Switch to indicate if first and last line segment shall be treated
                                          as an infinite line (effectively extending it outwards) [TRUE, FALSE]

  @glob_in         No global input variable used
  @glob_out        No global output variable used

  @c_switch_part   -
  @c_switch_full   FCT_CFG_COURSE_PREDICTION : Switch to configure FCT support for CP sub-component

  @pre             None
  @post            None

  @InOutCorrelation   None

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis). \n
                   Test of run time error/warnings (Static code analysis).

  @traceability    <a href="doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-498-0009fc80">CAL_498</a> \n

  @created         -
  @changed         24.03.2016

  @author          Gergely Ungvary | Gergely.Ungvary@continental-corporation.com
*************************************************************************************************************************/
fDistance_t CAL_f_CalculatePoint2SamplesDist(const CAL_t_PosSamples * pSamples, fDistance_t fPointX, fDistance_t fPointY, boolean bExtendSampleEnds)
{
  return CAL_f_CalculatePoint2LineSegCoordArr(pSamples->fx, pSamples->fy, pSamples->nb_samples, fPointX, fPointY, bExtendSampleEnds);
}

/*************************************************************************************************************************
  Functionname:    CAL_v_CalculateRadii                                                                                 */ /*!

  @brief           Calculate circumscribed circle radii for triplets

  @description     Calculates the signed circumscribed circle radii for each
                   neighboring point triplet. This is useful for determining
                   the curvature for a given trace for example.

                    @startuml
                    Start

                    Partition CAL_v_CalculateRadii {

                    :Read the input number of sample points, array point values of X & Y;
                    Note left : X is longitudinal coordinate and Y is lataeral coordinate
                    If (**Number of samples more than 3 ?**) then (Yes)
                    Repeat
                        :Calculate the side lengths of the triangle using X & Y of sample points;
                        Note left: Triangle can be formed
                    If (Y disstance between 2nd & 3rd point is not zero ?) then (Yes)
                        : Calculate the divisor using side lengths of the triangle;
                        If (Calculated divisor is not zero ?) then (Yes)
                            : Calculate the X & Y point of the Center of the circle;
                            : Calculate the Radius by using center and triangle points; 

                        Else (No)
                            : Radius of the circumscribed circle is infinity;
                        Endif;

                    Elseif(X distance between 2nd & 3rd point is not zero ?) then (Yes)
                        : Calculate the divisor using side lengths of the triangle;
                        If (Calculated divisor is not zero ?) then (Yes)
                            : Calculate the X & Y point of the Center of the circle;
                            : Calculate the Radius by using X,Y coordinates of center of circle and triangle points;    
                            If (Sign of cross product of the vecors from the sides 1-2 and 2-3 is negative ?) then (Yes)
                                :Multiply the radius of the circumscribed circle vecor with minus(-); 
                            Endif
                        Else (No)
                            : Radius of the circumscribed circle is infinity;
                        Endif;

                    Else(No)
                        : Points 2 and 3 are the same,
                            So Radius of the circumscribed circle is infinite;
                    Endif   

                    :Update the next X, Y input values;

                    Repeat while(**If formation of more triangle is possible(No of samples points-2) ? **)

                    Else(No)
                        :Triangle formation is not possible,
                         so Radius of the circumscribed circle
                         can not be calculated;
                    Endif
                    }
                    stop
                    @enduml

  @return          void

  @param[in]       pSamplesX[] : Array of longitudinal coordinates [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m of size [0 ... NumSamples-1]
  @param[in]       pSamplesY[] : Array of lateral coordinates      [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m of size [0 ... NumSamples-1]
  @param[in]       NumSamples : Number of sample coordinates       [full range of uint8]
  @param[in,out]   pfRadius : The array where the resulting radii are placed, this should be at least NumSamples-2 size [0 ... CP_INFINITE_RADIUS]

  @glob_in         No global input variable used
  @glob_out        No global output variable used

  @c_switch_part   -
  @c_switch_full   FCT_CFG_OBJECT_LIST_PROC : Object list processing interface input/output
  @c_switch_full   FCT_CFG_COURSE_PREDICTION : Switch to configure FCT support for CP sub-component

  @pre             None
  @post            None

  @InOutCorrelation   None

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis). \n
                   Test of run time error/warnings (Static code analysis).

  @traceability    <a href="doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-499-0009fc80">CAL_499</a> \n

  @created         -
  @changed         24.03.2016

  @author          Gergely Ungvary |  gergely.ungvary@continental-corporation.com | +36 88 548 671
*************************************************************************************************************************/
void CAL_v_CalculateRadii(const float32 pSamplesX[], const float32 pSamplesY[], uint8 NumSamples, fDistance_t * pfRadius)
{
  uint8 i;
  /* For every three points (which form a valid triangle) we can determine the
  radius of the circumscribed circle. This of course requires that we have more
  than three points to begin with */
  if (NumSamples >= 3u)
  {
    /* Now taking three points and marking their coordinates (X1,Y1) (X2,Y2) and (X3,Y3),
    then the coordinates of the circle's center are
    XC = X1 + 0.5*(X2-X1) - 0.5*(Y2-Y1)*fSubExp
    YC = Y1 + 0.5*(Y2-Y1) + 0.5*(X2-X1)*fSubExp,
    where fSubExp = 0.5f * ((X3-X1)(X3-X2) + (Y3-Y1)(Y3-Y2)) / (((X3-X2)*(Y2-Y1)) - ((X2-X1)*(Y3-Y2)))
    (The formula comes from calculation of the common point of the perpendicular halving lines
    of the sides 1-2 and 2-3, and is valid as long as Y3 != Y2)
    As can be seen, the later part of the equations is the same, so it can be reused.
    If only the unsigned radius is the question, then the formula
    R = 0.5 * (a*b*c)/sqrt(s(s-a)(s-b)(s-c)),
    where a,b,c are the sides of the triangle and s=(a+b+c)/2
    can also be used. Note: sign detection could then be done over calculation
    of crossproduct or similar...
    Now: outside of processing loop allocate delta X2-X3 and delta Y2-Y3,
    since these values can be re-used among iterations (shifting them)
    */
    float32 fX3X2, fY3Y2;

    fX3X2 = pSamplesX[1] - pSamplesX[0];
    fY3Y2 = pSamplesY[1] - pSamplesY[0];

    for (i=0u; i<(uint8)(NumSamples-2u); i++)
    {
      float32 fX2X1, fY2Y1, fX3X1, fY3Y1, fDivisor, fSubExp, fRadius;
      /* Reuse delta coordinates (side length) from last iteration */
      fX2X1 = fX3X2;
      fY2Y1 = fY3Y2;

      /* Calculate delta coordinates */
      fX3X2 = pSamplesX[2] - pSamplesX[1];
      fY3Y2 = pSamplesY[2] - pSamplesY[1];

      fX3X1 = pSamplesX[2] - pSamplesX[0];
      fY3Y1 = pSamplesY[2] - pSamplesY[0];

      /* The equation described above is only valid, when fY3Y2 is non-zero.
      If it is zero, we need to modify the calculation, but in that case we
      need an extra check to verify that points 2 and 3 are not the same */
      if ((fY3Y2 >= C_F32_DELTA) || (fY3Y2 <= -C_F32_DELTA))
      {
        /* Formula valid, calculate sub-expression divisor first */
        fDivisor = ((fX3X2*fY2Y1) - (fX2X1*fY3Y2));
        fSubExp = 0.5f*((fX3X2 * fX3X1) + (fY3Y2 * fY3Y1));
        /* Check if divisor valid */
        if ((fDivisor >= C_F32_DELTA) || (fDivisor <= -C_F32_DELTA))
        {
          float32 fXC, fYC;
          /* We can now perform the division (since sign safe) */
          fSubExp /= fDivisor;
          /* And using the value of fSubExp, we can easily find circle's center */
          fXC = (pSamplesX[0] + (0.5f * fX2X1)) + (fY2Y1 * fSubExp);
          fYC = (pSamplesY[0] + (0.5f * fY2Y1)) - (fX2X1 * fSubExp);
          /* Calculate unsigned radius based on coordinates */
          fRadius = SQRT_(SQR(fXC - pSamplesX[0]) + SQR(fYC - pSamplesY[0]));
          /* Depending on the sign of the cross product of the vectors
          from the sides 1-2 and 2-3 change the sign of radius to negative */
          if (((fX2X1 * fY3Y2) - (fX3X2 * fY2Y1)) < 0.f)
          {
            fRadius = -fRadius;
          }
        }
        else
        {
          fRadius = CAL_INFINITE_RADIUS;
        }
      }
      else if ((fX3X2 >= C_F32_DELTA) ||
               (fX3X2 <= -C_F32_DELTA))
      {
        /* Formula plagued by division by zero issue, but using this
        we can simplify the sub-formula: fSubExp = 0.5f*fX3X1/fY2Y1
        (if other side also zero, we don't have a triangle) */
        fDivisor = fY2Y1;
        fSubExp = 0.5f * fX3X1;
        /* Check if divisor valid */
        if ((fDivisor >= C_F32_DELTA) || (fDivisor <= -C_F32_DELTA))
        {
          float32 fXC, fYC;
          /* We can now perform the division (since sign safe) */
          fSubExp /= fDivisor;
          /* And using the value of fSubExp, we can easily find circle's center */
          fXC = (pSamplesX[0] + (0.5f * fX2X1)) + (fY2Y1 * fSubExp);
          fYC = (pSamplesY[0] + (0.5f * fY2Y1)) - (fX2X1 * fSubExp);
          /* Calculate unsigned radius based on coordinates */
          fRadius = SQRT_(SQR(fXC - pSamplesX[0]) + SQR(fYC - pSamplesY[0]));
          /* Depending on the sign of the cross product of the vectors
          from the sides 1-2 and 2-3 change the sign of radius to negative */
          if (((fX2X1 * fY3Y2) - (fX3X2 * fY2Y1)) < 0.f)
          {
            fRadius = -fRadius;
          }
        }
        else
        {
          fRadius = CAL_INFINITE_RADIUS;
        }
      }
      else
      {
        /* Special case: points 2 and 3 are the same */
        fRadius = CAL_INFINITE_RADIUS;
      }

      /* Advance source point pointers all by one */
      pSamplesX++;// PRQA S 0489
     /* date: 2015-04-27, reviewer: Gangadhar Badiger, reason: Application wide deviation to rule agreed upon*/
      pSamplesY++;// PRQA S 0489
     /* date: 2015-04-27, reviewer: Gangadhar Badiger, reason: Application wide deviation to rule agreed upon*/
      /* Store result and advance pointer by one (to fill next) */
      *pfRadius = fRadius;
      pfRadius++;// PRQA S 0489
     /* date: 2015-04-27, reviewer: Gangadhar Badiger, reason: Application wide deviation to rule agreed upon*/
    }
  }
}
#endif /* (0) Unused functions */

/*************************************************************************************************************************
  Functionname:    CAL_v_CalcPointApproxPolyL2                                                                          */ /*!

  @brief           Calculate 2nd power polynomial for approximating sample points

  @description     This function calculates the approximate polynomial fitting
                   the sample points using least square fit. The calculated
                   polynomial has the form f(x) = fC0 + fC1*x + fC2*x^2
                    @startuml
                    Start
                    Partition CAL_v_CalPointApproxPolyL2 {

                    If (**number of trace points more than 2 ?**) then (yes)
                        : Initialize the coefficient C0 of trace polynomial to first Y point of trace;
                        : Calculate necessary terms of linear equation set to use for least square fit;
                        If (**If diagonal of matrix of linear equations is positive**) then (yes)
                            : Convert the matrix to upper triangular form \n using Gaussian elimination;
                            : Calculate the matrix values via reverse elimination;
                            : Update coefficients using terms of linear equation;
                            : The trace polynomial is valid;
                        Else (no)
                            : Update coefficients C1,C2 to zero and \n C0 to first Y point of trace;
                            : The trace polynomial is invalid;
                        Endif
                    Else (no)
                        : Update the trace polynomial coefficients C1 and C2 to zero and \n C0 to Y coordinate of first trace point;
                        : The trace polynomial is invalid;
                        If (**Is number of trace points more than 1 ?**) then (yes)
                            : approximation of trace is using a line with two points;
                            : Update coefficients C0 to y-intercept of line, \n C1 to the slope of the line and C2 to zero;
                            : The trace polynomial is valid;
                        Endif
                    Endif
                    }
                    Stop
                    @enduml

  @return          void

  @param[in,out]   pPoly : Pointer to structure storing the second degree polynomial approximation of a trace [CAL_t_TracePolyL2 as defined in cp_ext.h]
                        pPoly->fC2 : Coefficient of second-order term                                      [-1f...+1f]
                        pPoly->fC1 : Coefficient of first-order term                                       [-1f...+1f]
                        pPoly->fC0 : Coefficient of zeroth-order term                                      [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX]
                        pPoly->isValid : Flag to indicate whether the trace polynomial is valid            [TRUE, FALSE]
  @param[in]       pafX[] : array of x coordinates of trace points                  [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] of size [0 ... FIP_STATIC_TRACE_NO_OF_POINTS[
  @param[in]       pafY[] : array of y coordinates of trace points                  [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] of size [0 ... FIP_STATIC_TRACE_NO_OF_POINTS[
  @param[in]       uNumPts : Number of trace points                                  [0 ... FIP_STATIC_TRACE_NO_OF_POINTS]

  @glob_in         No global input variable used
  @glob_out        No global output variable used

  @c_switch_part   -
  @c_switch_full   FCT_CFG_COURSE_PREDICTION : Switch to configure FCT support for CP sub-component

  @pre             None
  @post            None

  @InOutCorrelation   None

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis). \n
                   Test of run time error/warnings (Static code analysis).

  @traceability    <a href="doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-500-0009fc80">CAL_500</a> \n

  @created         -
  @changed         14.03.2016

  @author          Gergely Ungvary |  gergely.ungvary@continental-corporation.com | +36 88 548 671
*************************************************************************************************************************/
void CAL_v_CalcPointApproxPolyL2(CAL_t_TracePolyL2 * pPoly, const float32 pafX[], const float32 pafY[], uint8 uNumPts)
{
  sint32 i,j,k;
  float32 fXPow4Sum, fXPow3Sum, fXPow2Sum, fXSum;
  float32 fXYSum, fX2YSum, fYSum, fNumPts;
  float32 fLinEqMatrix[3][4];

  /* Verify that we have at least 3 points, below that just use a line extrapolation */
  if (uNumPts > 2u)
  {
    /* First calculate the necessary terms for our linear equation set
    to use for least squares fit */
    fXPow4Sum = 0.f;
    fXPow3Sum = 0.f;
    fXPow2Sum = 0.f;
    fXSum = 0.f;
    fXYSum = 0.f;
    fX2YSum = 0.f;
    fYSum = 0.f;
    fNumPts = (float32)uNumPts;
    /* Initialize return polynomial C0 to Y0 (plays a role when X coordinates all zero) */
    pPoly->fC0 = *pafY;
    /* Go through all points and calculate the sums */
    while (uNumPts > 0u)
    {
      const float32 fCurX = *pafX;
      const float32 fCurY = *pafY;
      const float32 fCurX2 = SQR(fCurX);
      pafX++;// PRQA S 0489
     /* date: 2015-04-27, reviewer: Gangadhar Badiger, reason: Application wide deviation to rule agreed upon*/
      pafY++;// PRQA S 0489
     /* date: 2015-04-27, reviewer: Gangadhar Badiger, reason: Application wide deviation to rule agreed upon*/
      /* Update sums */
      fXSum += fCurX;
      fXPow2Sum += fCurX2;
      fXPow3Sum += fCurX2*fCurX;
      fXPow4Sum += SQR(fCurX2);
      fYSum += fCurY;
      fXYSum += fCurX*fCurY;
      fX2YSum += fCurX2*fCurY;
      /* Decrease remaining number of points */
      uNumPts--;
    }
    /* Now we have a linear equation set:
    fXPow4Sum*C2 + fXPow3Sum*C1 + fXPow2Sum*C0 = fX2YSum
    fXPow3Sum*C2 + fXPow2Sum*C1 + fXSum*C0     = fXYSum
    fXPow2Sum*C2 + fXSum*C1     + NumPts*C0    = fYSum
    Notice how the diagonal of the matrix is always positive, if there is
    at least one point with an X coordinate other than 0. Also note that
    the inverse of fXPowySum always exists (due to this) */
    if (fABS( (fXPow2Sum*fXPow4Sum) - ( fXPow3Sum*fXPow3Sum) ) > C_F32_DELTA)/* PRQA S 3416 */
	/* Date: 02-12-2020, Reviewer:Gireesh , Reason:This warning  does not have any critical impact the functionality. */
    {
      fLinEqMatrix[0][0] = fXPow4Sum; 
      fLinEqMatrix[0][1] = fXPow3Sum; 
      fLinEqMatrix[0][2] = fXPow2Sum; 
      fLinEqMatrix[0][3] = fX2YSum;
      fLinEqMatrix[1][0] = fXPow3Sum; 
      fLinEqMatrix[1][1] = fXPow2Sum; 
      fLinEqMatrix[1][2] = fXSum;     
      fLinEqMatrix[1][3] = fXYSum;
      fLinEqMatrix[2][0] = fXPow2Sum; 
      fLinEqMatrix[2][1] = fXSum;     
      fLinEqMatrix[2][2] = fNumPts;   
      fLinEqMatrix[2][3] = fYSum;
      /* Now solve it, first converting the matrix to upper triangular form
      and then using elimination to solve it (Gauss elimination) */
      for (i=0; i<2; i++)
      {
        float32 fDivisor = fLinEqMatrix[i][i];
        float32 fInvColumnMax;
        /* Calculate inverse of column max once here, prevent devision by zero */
        if (fABS(fDivisor) < C_F32_DELTA) /* PRQA S 3416 */
		/* Date: 02-12-2020, Reviewer:Gireesh , Reason:This warning  does not have any critical impact the functionality. */
        {
          if (fDivisor < 0.0F)
          {
            fDivisor = -C_F32_DELTA;
          }
          else
          {
            fDivisor =  C_F32_DELTA;
          }
        }
        fInvColumnMax = 1.f / fDivisor;
        /* Now do forward substitution */
        for (j=3; j >= i; j--)
        {
          for (k=i+1; k<3; k++)
          {
            fLinEqMatrix[k][j] -= fLinEqMatrix[k][i]*fInvColumnMax * fLinEqMatrix[i][j];
          }
        }
      }
      /* Now do reverse elimination */
      for (i=2; i>=0; i--)
      {
        /* Verify that we have a leading non-zero value in the row */
        if ((fLinEqMatrix[i][i] > C_F32_EXT_DELTA) || (fLinEqMatrix[i][i] < -C_F32_EXT_DELTA))
        {
          /* Calculate inverse of the diagonal element currently processed */
          const float32 fInvCurDiagVal = 1.f / fLinEqMatrix[i][i];
          fLinEqMatrix[i][3] = fLinEqMatrix[i][3] * fInvCurDiagVal;
          fLinEqMatrix[i][i] = 1.f;
          for (j=i-1; j>=0; j--)
          {
            fLinEqMatrix[j][3] -= fLinEqMatrix[j][i] * fLinEqMatrix[i][3];
            fLinEqMatrix[j][i] = 0.f;
          }
        }
        else
        {
          fLinEqMatrix[i][3] = 0.f;
        }
      }
      /* Fill in result */
      pPoly->fC2 = fLinEqMatrix[0][3];
      pPoly->fC1 = fLinEqMatrix[1][3];
      pPoly->fC0 = fLinEqMatrix[2][3];
      pPoly->isValid = TRUE;
    }
    else
    {
      /* fXPow2Sum is zero -> all points have zero X coordinate */
      pPoly->fC2 = 0.f;
      pPoly->fC1 = 0.f;
      pPoly->isValid = FALSE;
      /* C0 initialization value to Y coordinate already OK */
    }
  }
  else
  {
    /* Initialize default return value */
    pPoly->fC2 = 0.f;
    pPoly->fC1 = 0.f;
    pPoly->fC0 = pafY[0];
    pPoly->isValid = FALSE;
    /* Approximate object movement by a simple line */
    if (uNumPts > 1u)
    {
      const float32 fDeltaX = pafX[1] - pafX[0];
      const float32 fDeltaY = pafY[1] - pafY[0];
      if ((fDeltaX > C_F32_DELTA) || (fDeltaX < -C_F32_DELTA))
      {
        pPoly->fC2 = 0.f;
        pPoly->fC1 = (fDeltaY / fDeltaX);
        pPoly->fC0 = pafY[0] - (pafX[0] * pPoly->fC1);
        pPoly->isValid = TRUE;
      }
    }
  }
}

#if (0) /* Disabling unused functions */
/*************************************************************************************************************************
  Functionname:    CAL_v_CalcPointApproxPolyL2Ext                                                                       */ /*!

  @brief           Calculate 2nd power polynomial for approximating sample points

  @description     This function calculates the approximate polynomial fitting
                   the sample points using least square fit. The calculated
                   polynomial has the form f(x) = fC0 + fC1*x + fC2*x^2
                   This is the extended version using standard deviations
                   supplied.

                    @startuml
                    Start
                    Partition CAL_v_CalPointApproxPolyL2 {

                    If (**number of trace points is more than 2**) then (yes)
                        : Initialize the coefficient C0 of trace polynomial to first Y point of trace;
                        : Calculate necessary terms of linear equation set to use for least square fit;
                        If (**diagonal of matrix of linear equations is positive**) then (yes)
                            : Convert the matrix to upper triangular form \n using Gaussian elimination;
                            : Calculate the matrix values via reverse elimination;
                            : Update coefficients using terms of linear equation;
                        Else (no)
                            : Update coefficients C1,C2 to zero and \n C0 to first Y point of trace;
                        Endif
                    Else (no)
                        : Update the trace polynomial coefficients C1 and C2 to zero and \n C0 to Y coordinate of first trace point;
                        If (**Is number of trace points more than 1 ?**) then (yes)
                            : approximation of trace is using a line with two points;
                            : Update coefficients C0 to y-intercept of line, \n C1 to the slope of the line and C2 to zero;
                        Endif
                    Endif
                    }
                    Stop
                    @enduml

  @return          void

  @param[in,out]   pPoly : Pointer to structure storing the second degree polynomial approximation of a trace [CAL_t_TracePolyL2 as defined in cal_ext.h]
                      pPoly->fC2 : Coefficient of second-order term                                     [-1f...+1f]
                      pPoly->fC1 : Coefficient of first-order term                                      [-1f...+1f]
                      pPoly->fC0 : Coefficient of zeroth-order term                                     [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX]
                      pPoly->isValid : Flag to indicate whether the trace polynomial is valid           [TRUE, FALSE]
  @param[in]       pafX : array of x coordinates of trace points                  [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] of size [0 ... FIP_STATIC_TRACE_NO_OF_POINTS]
  @param[in]       pafY : array of y coordinates of trace points                  [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] of size [0 ... FIP_STATIC_TRACE_NO_OF_POINTS]
  @param[in]       pafYStdDev : Pointer to standard deviation of y coordinates of trace points used for weighting the samples [0 ... PI/2*RW_FCT_MAX]
  @param[in]       uNumPts : Number of trace points                               [0 ... FIP_STATIC_TRACE_NO_OF_POINTS]

  @glob_in         No global input variable used
  @glob_out        No global output variable used

  @c_switch_part   -
  @c_switch_full   FCT_CFG_COURSE_PREDICTION : Switch to configure FCT support for CP sub-component

  @pre             None
  @post            None

  @InOutCorrelation   None

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis). \n
                   Test of run time error/warnings (Static code analysis).

  @traceability    <a href="doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-500-0009fc80">CAL_500</a> \n

  @created         -
  @changed         14.03.2016

  @author          Gergely Ungvary |  gergely.ungvary@continental-corporation.com | +36 88 548 671
*************************************************************************************************************************/
void CAL_v_CalcPointApproxPolyL2Ext(CAL_t_TracePolyL2 * pPoly, const float32 pafX[], const float32 pafY[], const float32 * pafYStdDev, uint8 uNumPts)
{
  sint32 i,j,k;
  float32 fXPow4Sum, fXPow3Sum, fXPow2Sum, fXSum;
  float32 fXYSum, fX2YSum, fYSum, fNumPts;
  float32 fLinEqMatrix[3][4];

  /* Verify that we have at least 3 points, below that just use a line extrapolation */
  if (uNumPts > 2u)
  {
    /* First calculate the necessary terms for our linear equation set
    to use for least squares fit */
    fXPow4Sum = 0.f;
    fXPow3Sum = 0.f;
    fXPow2Sum = 0.f;
    fXSum = 0.f;
    fXYSum = 0.f;
    fX2YSum = 0.f;
    fYSum = 0.f;
    fNumPts = (float32)uNumPts;
    /* Initilaize return poly C0 to Y0 (plays a role when X coordinates all zero) */
    pPoly->fC0 = *pafY;
    /* Go through all points and calculate the sums */
    while (uNumPts > 0u)
    {
      const float32 fCurX = *pafX;
      const float32 fCurY = *pafY;
      const float32 fCurStdDev = *pafYStdDev;
      const float32 fCurX2 = SQR(fCurX);
      /* Use 1/stddev to weight the current sample */
      const float32 fInvCurStdDev = (1.f/(MAX_FLOAT(C_F32_DELTA, fCurStdDev)));
      pafX++;// PRQA S 0489
     /* date: 2015-04-27, reviewer: Gangadhar Badiger, reason: Application wide deviation to rule agreed upon*/
      pafY++;// PRQA S 0489
     /* date: 2015-04-27, reviewer: Gangadhar Badiger, reason: Application wide deviation to rule agreed upon*/
      pafYStdDev++;// PRQA S 0489
     /* date: 2015-04-27, reviewer: Gangadhar Badiger, reason: Application wide deviation to rule agreed upon*/
      /* Update sums */
      fXSum += fCurX * fInvCurStdDev;
      fXPow2Sum += fCurX2 * fInvCurStdDev;
      fXPow3Sum += fCurX2 * fCurX * fInvCurStdDev;
      fXPow4Sum += SQR(fCurX2) * fInvCurStdDev;
      fYSum += fCurY * fInvCurStdDev;
      fXYSum += fCurX*fCurY * fInvCurStdDev;
      fX2YSum += fCurX2*fCurY * fInvCurStdDev;
      /* Decrease remaining number of points */
      uNumPts--;
    }
    /* Now we have a linear equation set:
    fXPow4Sum*C2 + fXPow3Sum*C1 + fXPow2Sum*C0 = fX2YSum
    fXPow3Sum*C2 + fXPow2Sum*C1 + fXSum*C0     = fXYSum
    fXPow2Sum*C2 + fXSum*C1     + NumPts*C0    = fYSum
    Notice how the diagonal of the matrix is always positive, if there is
    at least one point with an X coordinate other than 0. Also note that
    the inverse of fXPowySum always exists (due to this) */
    if ( fABS( (fXPow2Sum*fXPow4Sum) - ( fXPow3Sum*fXPow3Sum) ) > C_F32_DELTA)
    {
      fLinEqMatrix[0][0] = fXPow4Sum; fLinEqMatrix[0][1] = fXPow3Sum; fLinEqMatrix[0][2] = fXPow2Sum; fLinEqMatrix[0][3] = fX2YSum;
      fLinEqMatrix[1][0] = fXPow3Sum; fLinEqMatrix[1][1] = fXPow2Sum; fLinEqMatrix[1][2] = fXSum;     fLinEqMatrix[1][3] = fXYSum;
      fLinEqMatrix[2][0] = fXPow2Sum; fLinEqMatrix[2][1] = fXSum;     fLinEqMatrix[2][2] = fNumPts;   fLinEqMatrix[2][3] = fYSum;
      /* Now solve it, first converting the matrix to upper triangular form
      and then using elimination to solve it (Gauss elimination) */
      for (i=0; i<2; i++)
      {
        /* Calculate inverse of column max once here */
        float32 fDivisor = fLinEqMatrix[i][i];
        float32 fInvColumnMax;
        /* Calculate inverse of column max once here, prevent devision by zero */
        if (fABS(fDivisor) < C_F32_DELTA)
        {
          if (fDivisor < 0.0F)
          {
            fDivisor = -C_F32_DELTA;
          }
          else
          {
            fDivisor =  C_F32_DELTA;
          }
        }
        fInvColumnMax = 1.f / fDivisor;
        /* Now do forward substitution */
        for (j=3; j >= i; j--)
        {
          for (k=i+1; k<3; k++)
          {
            fLinEqMatrix[k][j] -= fLinEqMatrix[k][i]*fInvColumnMax * fLinEqMatrix[i][j];
          }
        }
      }
      /* Now do reverse elimination */
      for (i=2; i>=0; i--)
      {
        /* Verify that we have a leading non-zero value in the row */
        if ((fLinEqMatrix[i][i] > C_F32_EXT_DELTA) || (fLinEqMatrix[i][i] < -C_F32_EXT_DELTA))
        {
          /* Calculate inverse of the diagonal element currently processed */
          const float32 fInvCurDiagVal = 1.f / fLinEqMatrix[i][i];
          fLinEqMatrix[i][3] = fLinEqMatrix[i][3] * fInvCurDiagVal;
          fLinEqMatrix[i][i] = 1.f;
          for (j=i-1; j>=0; j--)
          {
            fLinEqMatrix[j][3] -= fLinEqMatrix[j][i] * fLinEqMatrix[i][3];
            fLinEqMatrix[j][i] = 0.f;
          }
        }
        else
        {
          fLinEqMatrix[i][3] = 0.f;
        }
      }
      /* Fill in result */
      pPoly->fC2 = fLinEqMatrix[0][3];
      pPoly->fC1 = fLinEqMatrix[1][3];
      pPoly->fC0 = fLinEqMatrix[2][3];
    }
    else
    {
      /* fXPow2Sum is zero -> all points have zero X coordinate */
      pPoly->fC2 = 0.f;
      pPoly->fC1 = 0.f;
      /* C0 initialization value to Y coordinate already OK */
    }
  }
  else
  {
    /* Initialize default return value */
    pPoly->fC2 = 0.f;
    pPoly->fC1 = 0.f;
    pPoly->fC0 = pafY[0];
    /* Approximate object movement by a simple line */
    if (uNumPts > 1u)
    {
      const float32 fDeltaX = pafX[1] - pafX[0];
      const float32 fDeltaY = pafY[1] - pafY[0];
      if ((fDeltaX > C_F32_DELTA) || (fDeltaX < -C_F32_DELTA))
      {
        pPoly->fC2 = 0.f;
        pPoly->fC1 = (fDeltaY / fDeltaX);
        pPoly->fC0 = pafY[0] - (pafX[0] * pPoly->fC1);
      }
    }
  }
}
#endif /* (0) Unused functions */

#if (0)  /* Disabling unused functions */
/* Uncomment the function CAL_v_CalcPointApproxPolyL3Ext when FCT_CFG_TJA_OBJECT_TRACE is SWITCH_ON */
/*************************************************************************************************************************
  Functionname:    CAL_v_CalcPointApproxPolyL3Ext                                                                       */ /*!

  @brief           Calculate 3-rd order polynomial for approximating sample points of object traces.

  @description     This function calculates the approximate polynomial fitting
                   the sample points using least square fit with coefficient and residual variance. 
                   The special cases for only two or three sample points are considered.
                   This is done for object traces.
                   The calculated polynomial has the form f(x) = fC0 + fC1*x + fC2*x^2 + fC3*x^3
                    
                    @startuml
                    Start
                    Partition CAL_v_CalcPointApproxPolyL3Ext{

                    If (**If Referenced object has to be added to trace points ?**) then (TRUE)
                        :Matrix dimenson is 1+ Minimum between No of trace points & 3;
                    Else (FALSE)
                        : Matrix dimenson is Minimum between No of trace points & 4;
                    endif

                    If (**If matrix dimension is 2 ?**) then (Yes)
                        : Create matrices for linear equation system;
                        If (**If to use the Current object ?**) then (TRUE)
                            : Assign Object-distance & 0th Trace point for Matrix X, Y & Cov(Y);
                        Else (FALSE)
                            : Assign 0th & 1st Trace point for Matrix X, Y & Cov(Y);
                        Endif
                        : Assign values of X, Y & CovY matrix to polynomial struct;
                        : Do matrix operation to calculate Covarience matrix (Cov(C));
                        : Assign values of Cov(C) matrix to polynomial struct;

                    Elseif(**If matrix dimension is 3 ?**) then (Yes)
                        : Create matrices for linear equation system;
                        If (**To use the Current object ?**) then (TRUE)
                            : Assign object-distance, 0th & 1st Trace point for Matrix X, Y & Cov(Y);
                        Else (FALSE)
                            : Assign 0th, 1st & 2nd Trace point for Matrix X, Y & Cov(Y);
                        Endif
                        : Assign values of X, Y & CovY matrix to polynomial struct;
                        : Do matrix operation to calculate Covarience matrix (Cov(C));
                        : Assign values of Cov(C) matrix to polynomial struct;

                    Elseif(**If matrix dimension is 4 ?**)then (Yes)
                        : Create matrices for linear equation system;
                        : Create the sum values and initialise to zero;

                        If (Is the current object actual) 
                        Note left : Evaluate actual object point and calculate the sums; then (TRUE)
                            : weight the current sample;
                            : Init powers of X and XY;
                            : Cumulate the power sums;
                        Else (FALSE)
                        Endif 
                            Repeat
                                : weight the current sample;
                                Note left:Going through all points and calculate the sums;
                                : Init powers of X and XY;
                                :Cumulate the power sums;
                            Repeat while( Next point is available ?)
                        :Assign Xmax and Xmin values;
                        If (Is the current object actual) then(Yes)
                            :X_max is X distance to the object;
                        Else (No)
                            :X_max is X distance of 0th trace point;
                        Endif;
                        : Evaluate X-matrix condition;
                        If (**Is X-matrix conditioned well ?**) then (Yes)
                            :Assign Row- 0,1,2 of Matrix-X;
                            :Assign matrix-Y values;
                            :Do matrix operations and mark the polynomial as valid;
                        Else (No)
                            : X-matrix is badly conditioned;
                        Endif;
                    Else(No)
                    : Too less Matrix points; 
                    Endif

                    }
                    End 
                    @enduml

  @return          void

  @param[out]      pPoly : Structure storing the third degree polynomial approximation of a trace
                     pPoly->fC0    [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX]
                     pPoly->fC1    [-PI/2 ... PI/2]
                     pPoly->fC2    [full range of datatype float32]
                     pPoly->fC3    [full range of datatype float32]
                     pPoly->fC0Var [full range of datatype float32]
                     pPoly->fC1Var [full range of datatype float32]
                     pPoly->fC2Var [full range of datatype float32]
                     pPoly->fC3Var [full range of datatype float32]
                     pPoly->fXmin  [-5*RW_FCT_MAX ... 5*RW_FCT_MAX]
                     pPoly->fXmax  [-5*RW_FCT_MAX ... 5*RW_FCT_MAX]
                     pPoly->bValid [TRUE, FALSE]
  @param[in]       pActObjKin : Pointer to Kinematic struct of actual trace object
                      fDistX : X-Position of actual trace object [-5*RW_FCT_MAX ... 5*RW_FCT_MAX]
                      fDistY : Y-Position of actual trace object [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX]
                      fDistYStd : Standard deviation of y-position of actual trace object [full range of datatype float32]
  @param[in]       pObjTrace  : Pointer to actual trace struct
                      iNumberOfPoints : Number of sample points [0 ...FIP_STATIC_TRACE_NO_OF_POINTS[
                      fTracePointX[i] : X-Position of sample point i [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m of size FIP_STATIC_TRACE_NO_OF_POINTS
                      fTracePointY[i] :  Y-Position of sample point i [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m of size FIP_STATIC_TRACE_NO_OF_POINTS
                      fTracePointYStdDev[i] : Standard deviation of y-position of sample point i [full range of datatype float32] of size FIP_STATIC_TRACE_NO_OF_POINTS
  @param[in]       bUseActObjKin : Information if to use the current object pActObjKin [TRUE, FALSE]

  @glob_in         No global input variable used
  @glob_out        No global output variable used

  @c_switch_part   -
  @c_switch_full   -

  @pre             None
  @post            None

  @InOutCorrelation   None

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis). \n
                   Test of run time error/warnings (Static code analysis).

  @traceability    <a href="doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-501-0009fc80">CAL_501</a> \n

  @created         25.09.2015
  @changed         15.01.2016

  @author          Wolfgang Borgs | wolfgang.borgs@continental-corporation.com
*************************************************************************************************************************/
void CAL_v_CalcPointApproxPolyL3Ext(CAL_t_TracePolyL3* pPoly, const ObjectTrace_t* pObjTrace, const EM_t_GenObjKinematics* pActObjKin, const boolean bUseActObjKin)
{
  uint8 uMatDim;
  uint8 uIndPoint;
  boolean bCondition;

  /* if referenced object has to be added to trace points */
  if (bUseActObjKin == TRUE)
  {
    /* define matrix dimension depending on number of points plus object - max 3+1 */
    uMatDim = 1+MIN(((uint8)pObjTrace->iNumberOfPoints), 3);
  }
  else
  {
    /* define matrix dimension depending on number of points - max 4 */
    uMatDim = MIN(((uint8)pObjTrace->iNumberOfPoints), 4);
  }

  switch (uMatDim)
  {
  case 2:
    {
      /* Create matrices for linear equation system */
      CML_CreateMatrixLocal(mX, 2, 2)     // PRQA S 1031
      /* date: 2015-10-21, reviewer: Wolfgang Borgs, reason: Allowed in later versions of ISO C99*/
      CML_CreateMatrixLocal(mInvX, 2, 2)  // PRQA S 1031
      /* date: 2015-10-21, reviewer: Wolfgang Borgs, reason: Allowed in later versions of ISO C99*/
      CML_CreateMatrixLocal(mY, 2, 1)     // PRQA S 1031
      /* date: 2015-10-21, reviewer: Wolfgang Borgs, reason: Allowed in later versions of ISO C99*/
      CML_CreateMatrixLocal(mC, 2, 1)     // PRQA S 1031
      /* date: 2015-10-21, reviewer: Wolfgang Borgs, reason: Allowed in later versions of ISO C99*/
      CML_CreateMatrixLocal(mCovY, 2, 2)     // PRQA S 1031
      /* date: 2015-10-21, reviewer: Wolfgang Borgs, reason: Allowed in later versions of ISO C99*/
      CML_CreateMatrixLocal(mInvXCovY, 2, 2)  // PRQA S 1031
      /* date: 2015-10-21, reviewer: Wolfgang Borgs, reason: Allowed in later versions of ISO C99*/
      CML_CreateMatrixLocal(mCovC, 2, 2)     // PRQA S 1031
      /* date: 2015-10-21, reviewer: Wolfgang Borgs, reason: Allowed in later versions of ISO C99*/

      if (bUseActObjKin == TRUE)
      {
        /* Assign X matrix */
        CML_GetMatrixElement(mX, 0, 0) = 1.0F;
        CML_GetMatrixElement(mX, 0, 1) = pActObjKin->fDistX;
        CML_GetMatrixElement(mX, 1, 0) = 1.0F;
        CML_GetMatrixElement(mX, 1, 1) = pObjTrace->fTracePointX[0];

        /* Assign Y matrix */
        CML_GetMatrixElement(mY, 0, 0) = pActObjKin->fDistY;
        CML_GetMatrixElement(mY, 1, 0) = pObjTrace->fTracePointY[0];

        /* Assign Cov(Y) matrix */
        CML_GetMatrixElement(mCovY, 0, 0) = CML_Sqr(pActObjKin->fDistYStd);
        CML_GetMatrixElement(mCovY, 0, 1) = 0.0F;
        CML_GetMatrixElement(mCovY, 1, 0) = 0.0F;
        CML_GetMatrixElement(mCovY, 1, 1) = CML_Sqr(pObjTrace->fTracePointYStdDev[0]);
      }
      else
      {
        /* Assign X matrix */
        CML_GetMatrixElement(mX, 0, 0) = 1.0F;
        CML_GetMatrixElement(mX, 0, 1) = pObjTrace->fTracePointX[0];
        CML_GetMatrixElement(mX, 1, 0) = 1.0F;
        CML_GetMatrixElement(mX, 1, 1) = pObjTrace->fTracePointX[1];

        /* Assign Y matrix */
        CML_GetMatrixElement(mY, 0, 0) = pObjTrace->fTracePointY[0];
        CML_GetMatrixElement(mY, 1, 0) = pObjTrace->fTracePointY[1];

        /* Assign Cov(Y) matrix */
        CML_GetMatrixElement(mCovY, 0, 0) = CML_Sqr(pObjTrace->fTracePointYStdDev[0]);
        CML_GetMatrixElement(mCovY, 0, 1) = 0.0F;
        CML_GetMatrixElement(mCovY, 1, 0) = 0.0F;
        CML_GetMatrixElement(mCovY, 1, 1) = CML_Sqr(pObjTrace->fTracePointYStdDev[1]);
      }

      /* Assign values of X matrix to polynomial struct */
      pPoly->fXmax = CML_GetMatrixElement(mX, 0, 1);
      pPoly->fXmin = MAX_FLOAT(CML_GetMatrixElement(mX, 1, 1), 0.0F);

      /* Linear equation system (mX * mC = mY) */
      /* Invert X matrix (mInvX = Inverse(mX), mX = I !!!)*/
      CML_v_InvertMatrix(mInvX, mX);

      /* Multiply Inv(X) matrix by Y matrix (mC = mInvX * mY) */
      CML_v_MultiplyMatrices(mC, mInvX, mY);

      /* Assign values of C matrix to polynomial struct */
      pPoly->fC0 = CML_GetMatrixElement(mC, 0, 0);
      pPoly->fC1 = CML_GetMatrixElement(mC, 1, 0);
      pPoly->fC2 = 0.0F;
      pPoly->fC3 = 0.0F;

      /* Multiply Inv(X) matrix by Cov(Y) matrix (mInvXCovY = mInvX * mCovY) */
      CML_v_MultiplyMatrices(mInvXCovY, mInvX, mCovY);

      /* Multiply Inv(X)*Cov(Y) matrix by Trans(Inv(X)) matrix (mCovC = mInvXCovY * Trans(mInvX) */
      CML_v_MultiplyMatrixWithTranspose(mCovC, mInvXCovY, mInvX);

      /* Assign values of Cov(C) matrix to polynomial struct */
      pPoly->fC0Var = CML_GetMatrixElement(mCovC, 0, 0);
      pPoly->fC1Var = CML_GetMatrixElement(mCovC, 1, 1);
      pPoly->fC2Var = 0.0F;
      pPoly->fC3Var = 0.0F;

      /* Mark polynomial as valid */
      pPoly->bValid = TRUE;
    }
    break;

  case 3:
    {
      /* Create matrices for linear equation system */
      CML_CreateMatrixLocal(mX, 3, 3)     // PRQA S 1031
      /* date: 2015-10-21, reviewer: Wolfgang Borgs, reason: Allowed in later versions of ISO C99*/
      CML_CreateMatrixLocal(mInvX, 3, 3)  // PRQA S 1031
      /* date: 2015-10-21, reviewer: Wolfgang Borgs, reason: Allowed in later versions of ISO C99*/
      CML_CreateMatrixLocal(mY, 3, 1)     // PRQA S 1031
      /* date: 2015-10-21, reviewer: Wolfgang Borgs, reason: Allowed in later versions of ISO C99*/
      CML_CreateMatrixLocal(mC, 3, 1)     // PRQA S 1031
      /* date: 2015-10-21, reviewer: Wolfgang Borgs, reason: Allowed in later versions of ISO C99*/
      CML_CreateMatrixLocal(mCovY, 3, 3)     // PRQA S 1031
      /* date: 2015-10-21, reviewer: Wolfgang Borgs, reason: Allowed in later versions of ISO C99*/
      CML_CreateMatrixLocal(mInvXCovY, 3, 3)  // PRQA S 1031
      /* date: 2015-10-21, reviewer: Wolfgang Borgs, reason: Allowed in later versions of ISO C99*/
      CML_CreateMatrixLocal(mCovC, 3, 3)     // PRQA S 1031
      /* date: 2015-10-21, reviewer: Wolfgang Borgs, reason: Allowed in later versions of ISO C99*/

      if (bUseActObjKin == TRUE)
      {
        /* Assign X matrix */
        CML_GetMatrixElement(mX, 0, 0) = 1.0F;
        CML_GetMatrixElement(mX, 0, 1) = pActObjKin->fDistX;
        CML_GetMatrixElement(mX, 0, 2) = CML_Sqr(pActObjKin->fDistX);
        CML_GetMatrixElement(mX, 1, 0) = 1.0F;
        CML_GetMatrixElement(mX, 1, 1) = pObjTrace->fTracePointX[0];
        CML_GetMatrixElement(mX, 1, 2) = CML_Sqr(pObjTrace->fTracePointX[0]);
        CML_GetMatrixElement(mX, 2, 0) = 1.0F;
        CML_GetMatrixElement(mX, 2, 1) = pObjTrace->fTracePointX[1];
        CML_GetMatrixElement(mX, 2, 2) = CML_Sqr(pObjTrace->fTracePointX[1]);

        /* Assign Y matrix */
        CML_GetMatrixElement(mY, 0, 0) = pActObjKin->fDistY;
        CML_GetMatrixElement(mY, 1, 0) = pObjTrace->fTracePointY[0];
        CML_GetMatrixElement(mY, 2, 0) = pObjTrace->fTracePointY[1];

        /* Assign Cov(Y) matrix */
        CML_GetMatrixElement(mCovY, 0, 0) = CML_Sqr(pActObjKin->fDistYStd);
        CML_GetMatrixElement(mCovY, 0, 1) = 0.0F;
        CML_GetMatrixElement(mCovY, 0, 2) = 0.0F;
        CML_GetMatrixElement(mCovY, 1, 0) = 0.0F;
        CML_GetMatrixElement(mCovY, 1, 1) = CML_Sqr(pObjTrace->fTracePointYStdDev[0]);
        CML_GetMatrixElement(mCovY, 1, 2) = 0.0F;
        CML_GetMatrixElement(mCovY, 2, 0) = 0.0F;
        CML_GetMatrixElement(mCovY, 2, 1) = 0.0F;
        CML_GetMatrixElement(mCovY, 2, 2) = CML_Sqr(pObjTrace->fTracePointYStdDev[1]);
      }
      else
      {
        /* Assign X matrix */
        CML_GetMatrixElement(mX, 0, 0) = 1.0F;
        CML_GetMatrixElement(mX, 0, 1) = pObjTrace->fTracePointX[0];
        CML_GetMatrixElement(mX, 0, 2) = CML_Sqr(pObjTrace->fTracePointX[0]);
        CML_GetMatrixElement(mX, 1, 0) = 1.0F;
        CML_GetMatrixElement(mX, 1, 1) = pObjTrace->fTracePointX[1];
        CML_GetMatrixElement(mX, 1, 2) = CML_Sqr(pObjTrace->fTracePointX[1]);
        CML_GetMatrixElement(mX, 2, 0) = 1.0F;
        CML_GetMatrixElement(mX, 2, 1) = pObjTrace->fTracePointX[2];
        CML_GetMatrixElement(mX, 2, 2) = CML_Sqr(pObjTrace->fTracePointX[2]);

        /* Assign Y matrix */
        CML_GetMatrixElement(mY, 0, 0) = pObjTrace->fTracePointY[0];
        CML_GetMatrixElement(mY, 1, 0) = pObjTrace->fTracePointY[1];
        CML_GetMatrixElement(mY, 2, 0) = pObjTrace->fTracePointY[2];

        /* Assign Cov(Y) matrix */
        CML_GetMatrixElement(mCovY, 0, 0) = CML_Sqr(pObjTrace->fTracePointYStdDev[0]);
        CML_GetMatrixElement(mCovY, 0, 1) = 0.0F;
        CML_GetMatrixElement(mCovY, 0, 2) = 0.0F;
        CML_GetMatrixElement(mCovY, 1, 0) = 0.0F;
        CML_GetMatrixElement(mCovY, 1, 1) = CML_Sqr(pObjTrace->fTracePointYStdDev[1]);
        CML_GetMatrixElement(mCovY, 1, 2) = 0.0F;
        CML_GetMatrixElement(mCovY, 2, 0) = 0.0F;
        CML_GetMatrixElement(mCovY, 2, 1) = 0.0F;
        CML_GetMatrixElement(mCovY, 2, 2) = CML_Sqr(pObjTrace->fTracePointYStdDev[2]);
      }

      /* Assign values of X matrix to polynomial struct */
      pPoly->fXmax = CML_GetMatrixElement(mX, 0, 1);
      pPoly->fXmin = MAX_FLOAT(CML_GetMatrixElement(mX, 2, 1), 0.0F);

      /* Linear equation system (mX * mC = mY) */
      /* Invert X matrix (mInvX = Inverse(mX), mX = I !!!)*/
      CML_v_InvertMatrix(mInvX, mX);

      /* Multiply Inv(X) matrix by Y matrix (mC = mInvX * mY) */
      CML_v_MultiplyMatrices(mC, mInvX, mY);

      /* Assign values of C matrix to polynomial struct */
      pPoly->fC0 = CML_GetMatrixElement(mC, 0, 0);
      pPoly->fC1 = CML_GetMatrixElement(mC, 1, 0);
      pPoly->fC2 = CML_GetMatrixElement(mC, 2, 0);
      pPoly->fC3 = 0.0F;

      /* Multiply Inv(X) matrix by Cov(Y) matrix (mInvXCovY = mInvX * mCovY) */
      CML_v_MultiplyMatrices(mInvXCovY, mInvX, mCovY);

      /* Multiply Inv(X)*Cov(Y) matrix by Trans(Inv(X)) matrix (mCovC = mInvXCovY * Trans(mInvX) */
      CML_v_MultiplyMatrixWithTranspose(mCovC, mInvXCovY, mInvX);

      /* Assign values of Cov(C) matrix to polynomial struct */
      pPoly->fC0Var = CML_GetMatrixElement(mCovC, 0, 0);
      pPoly->fC1Var = CML_GetMatrixElement(mCovC, 1, 1);
      pPoly->fC2Var = CML_GetMatrixElement(mCovC, 2, 2);
      pPoly->fC3Var = 0.0F;

      /* Mark polynomial as valid */
      pPoly->bValid = TRUE;
    }
    break;

  case 4:
    {
      /* Create matrices for linear equation system */
      CML_CreateMatrixLocal(mX, 4, 4)     // PRQA S 1031
      /* date: 2015-10-21, reviewer: Wolfgang Borgs, reason: Allowed in later versions of ISO C99*/
      CML_CreateMatrixLocal(mCopX, 4, 4)     // PRQA S 1031
      /* date: 2015-10-21, reviewer: Wolfgang Borgs, reason: Allowed in later versions of ISO C99*/
      CML_CreateMatrixLocal(mInvX, 4, 4)  // PRQA S 1031
      /* date: 2015-10-21, reviewer: Wolfgang Borgs, reason: Allowed in later versions of ISO C99*/
      CML_CreateMatrixLocal(mY, 4, 1)     // PRQA S 1031
      /* date: 2015-10-21, reviewer: Wolfgang Borgs, reason: Allowed in later versions of ISO C99*/
      CML_CreateMatrixLocal(mC, 4, 1)     // PRQA S 1031
      /* date: 2015-10-21, reviewer: Wolfgang Borgs, reason: Allowed in later versions of ISO C99*/
      CML_CreateMatrixLocal(mCt, 1, 4)     // PRQA S 1031
      /* date: 2015-10-21, reviewer: Wolfgang Borgs, reason: Allowed in later versions of ISO C99*/
      CML_CreateMatrixLocal(mCtX, 1, 4)     // PRQA S 1031
      /* date: 2015-10-21, reviewer: Wolfgang Borgs, reason: Allowed in later versions of ISO C99*/
      CML_CreateMatrixLocal(mCtXC, 1, 1)     // PRQA S 1031
      /* date: 2015-10-21, reviewer: Wolfgang Borgs, reason: Allowed in later versions of ISO C99*/
      CML_CreateMatrixLocal(mCtY, 1, 1)     // PRQA S 1031
      /* date: 2015-10-21, reviewer: Wolfgang Borgs, reason: Allowed in later versions of ISO C99*/

      float32 fYVar;
      float32 fInvVar;
      float32 fResVar;

      float32 fCurX1;
      float32 fCurX1W;
      float32 fCurX2W;
      float32 fCurX3W;
      float32 fCurX4W;
      float32 fCurX5W;
      float32 fCurY1;
      float32 fCurX0YW;
      float32 fCurX1YW;
      float32 fCurX2YW;

      /* Initialize sums for all points */
      float32 fX0Sum = 0.f;
      float32 fX1Sum = 0.f;
      float32 fX2Sum = 0.f;
      float32 fX3Sum = 0.f;
      float32 fX4Sum = 0.f;
      float32 fX5Sum = 0.f;
      float32 fX6Sum = 0.f;
      float32 fX0YSum = 0.f;
      float32 fX1YSum = 0.f;
      float32 fX2YSum = 0.f;
      float32 fX3YSum = 0.f;
      float32 fY2Sum = 0.f;

      /* eval actual object point and calculate the sums */
      if (bUseActObjKin == TRUE)
      {
        /* Use 1/SQR(stddev) to weight the current sample */
        fYVar = CML_Sqr(pActObjKin->fDistYStd);
        fInvVar = (1.f/(MAX_FLOAT(fYVar, C_F32_DELTA)));

        /* Init powers of X */
        fCurX1  = pActObjKin->fDistX;
        fCurX1W = fInvVar * fCurX1;
        fCurX2W = fCurX1W * fCurX1;
        fCurX3W = fCurX2W * fCurX1;
        fCurX4W = fCurX3W * fCurX1;
        fCurX5W = fCurX4W * fCurX1;

        /* Init powers of XY */
        fCurY1   = pActObjKin->fDistY;
        fCurX0YW = fInvVar  * fCurY1;
        fCurX1YW = fCurX0YW * fCurX1;
        fCurX2YW = fCurX1YW * fCurX1;

        /* Cumulate power sums */
        fX0Sum  =  fInvVar;
        fX1Sum  =  fCurX1W;
        fX2Sum  =  fCurX2W;
        fX3Sum  =  fCurX3W;
        fX4Sum  =  fCurX4W;
        fX5Sum  =  fCurX5W;
        fX6Sum  = (fCurX5W * fCurX1);
        fX0YSum =  fCurX0YW;
        fX1YSum =  fCurX1YW;
        fX2YSum =  fCurX2YW;
        fX3YSum = (fCurX2YW * fCurX1);
        fY2Sum  = (fCurX0YW * fCurY1);
      }

      /* Go through all points and calculate the sums */
      for (uIndPoint=0u; uIndPoint<pObjTrace->iNumberOfPoints; uIndPoint++)
      {
        /* Use 1/SQR(stddev) to weight the current sample */
        fYVar = CML_Sqr(pObjTrace->fTracePointYStdDev[uIndPoint]);
        fInvVar = (1.f/(MAX_FLOAT(fYVar, C_F32_DELTA)));

        /* Init powers of X */
        fCurX1  = pObjTrace->fTracePointX[uIndPoint];
        fCurX1W = fInvVar * fCurX1;
        fCurX2W = fCurX1W * fCurX1;
        fCurX3W = fCurX2W * fCurX1;
        fCurX4W = fCurX3W * fCurX1;
        fCurX5W = fCurX4W * fCurX1;

        /* Init powers of XY */
        fCurY1   = pObjTrace->fTracePointY[uIndPoint];
        fCurX0YW = fInvVar  * fCurY1;
        fCurX1YW = fCurX0YW * fCurX1;
        fCurX2YW = fCurX1YW * fCurX1;

        /* Cumulate power sums */
        fX0Sum  +=  fInvVar;
        fX1Sum  +=  fCurX1W;
        fX2Sum  +=  fCurX2W;
        fX3Sum  +=  fCurX3W;
        fX4Sum  +=  fCurX4W;
        fX5Sum  +=  fCurX5W;
        fX6Sum  += (fCurX5W * fCurX1);
        fX0YSum +=  fCurX0YW;
        fX1YSum +=  fCurX1YW;
        fX2YSum +=  fCurX2YW;
        fX3YSum += (fCurX2YW * fCurX1);
        fY2Sum  += (fCurX0YW * fCurY1);
      }

      /* Assign Xmax and Xmin values to polynomial struct */
      if (bUseActObjKin == TRUE)
      {
        pPoly->fXmax = pActObjKin->fDistX;
      }
      else
      {
        pPoly->fXmax = pObjTrace->fTracePointX[0];
      }
      pPoly->fXmin = MAX_FLOAT(pObjTrace->fTracePointX[pObjTrace->iNumberOfPoints-1], 0.0F);

      /* Now we have a linear equation set:
      fX0Sum * C0 + fX1Sum * C1 + fX2Sum * C2 + fX3Sum * C3 = fX0YSum
      fX1Sum * C0 + fX2Sum * C1 + fX3Sum * C2 + fX4Sum * C3 = fX1YSum
      fX2Sum * C0 + fX3Sum * C1 + fX4Sum * C2 + fX5Sum * C3 = fX2YSum
      fX3Sum * C0 + fX4Sum * C1 + fX5Sum * C2 + fX6Sum * C3 = fX3YSum */

      /* Evaluate X-matrix condition */
      /* For CML_v_InvertMatrix() the largest element on each column MUST BE greater than the tolerance value (1e-10).
         To improve numerical stability it has been decided to use C_F32_DELTA (1e-4) instead */

      /* Check elements X(0,3), X(1,2), X(2,1), X(3,0) */
      if (fX3Sum > C_F32_DELTA)
      {
        bCondition = TRUE;
      }
      /* Check elements X(0,2), X(1,1), X(2,0) */
      else if (fX2Sum > C_F32_DELTA)
      {
        /* Check elements X(1,3), X(2,2), X(3,1) or X(2,3), X(3,2) or X(3,3) */
        bCondition = (boolean)((fX4Sum > C_F32_DELTA) || (fX5Sum > C_F32_DELTA) || (fX6Sum > C_F32_DELTA));
      }
      /* Check elements X(1,3), X(2,2), X(3,1) */
      else if (fX4Sum > C_F32_DELTA)
      {
        /* Check elements X(0,0) or X(0,1), X(1,0) */
        bCondition = (boolean)((fX0Sum > C_F32_DELTA) || (fX1Sum > C_F32_DELTA));
      }
      else
      {
        /* Check elements X(0,1), X(1,0) and X(2,3), X(3,2) */
        bCondition = (boolean)((fX1Sum > C_F32_DELTA) && (fX5Sum > C_F32_DELTA));
      }

      /* if X-matrix is well conditioned */
      if (bCondition)
      {
        /* Assign row [0] of X-matrix */
        CML_GetMatrixElement(mX, 0, 0) = fX0Sum;
        CML_GetMatrixElement(mX, 0, 1) = fX1Sum;
        CML_GetMatrixElement(mX, 0, 2) = fX2Sum;
        CML_GetMatrixElement(mX, 0, 3) = fX3Sum;

        /* Assign row [1] of X-matrix */
        CML_GetMatrixElement(mX, 1, 0) = fX1Sum;
        CML_GetMatrixElement(mX, 1, 1) = fX2Sum;
        CML_GetMatrixElement(mX, 1, 2) = fX3Sum;
        CML_GetMatrixElement(mX, 1, 3) = fX4Sum;

        /* Assign row [2] of X-matrix */
        CML_GetMatrixElement(mX, 2, 0) = fX2Sum;
        CML_GetMatrixElement(mX, 2, 1) = fX3Sum;
        CML_GetMatrixElement(mX, 2, 2) = fX4Sum;
        CML_GetMatrixElement(mX, 2, 3) = fX5Sum;

        /* Assign row [3] of X-matrix */
        CML_GetMatrixElement(mX, 3, 0) = fX3Sum;
        CML_GetMatrixElement(mX, 3, 1) = fX4Sum;
        CML_GetMatrixElement(mX, 3, 2) = fX5Sum;
        CML_GetMatrixElement(mX, 3, 3) = fX6Sum;

        /* Assign Y-matrix */
        CML_GetMatrixElement(mY, 0, 0) = fX0YSum;
        CML_GetMatrixElement(mY, 1, 0) = fX1YSum;
        CML_GetMatrixElement(mY, 2, 0) = fX2YSum;
        CML_GetMatrixElement(mY, 3, 0) = fX3YSum;

        /* Linear equation system (mX * mC = mY) */

        /* if referenced object plus number of trace points are sufficient for variance computation */
        if (pObjTrace->iNumberOfPoints > (bUseActObjKin == TRUE ? 3 : 4))
        {
          /* Copy X matrix (mCopX = mX) */
          CML_v_CopyMatrix(mCopX, mX);
        }

        /* Invert X matrix (mInvX = Inverse(mX), mX = I !!!)*/
        CML_v_InvertMatrix(mInvX, mX);

        /* Multiply Inv(X) matrix by Y matrix (mC = mInvX * mY) */
        CML_v_MultiplyMatrices(mC, mInvX, mY);

        /* Assign values of C matrix to polynomial struct */
        pPoly->fC0 = CML_GetMatrixElement(mC, 0, 0);
        pPoly->fC1 = CML_GetMatrixElement(mC, 1, 0);
        pPoly->fC2 = CML_GetMatrixElement(mC, 2, 0);
        pPoly->fC3 = CML_GetMatrixElement(mC, 3, 0);

        /* if referenced object plus number of trace points are sufficient for variance computation */
        if (pObjTrace->iNumberOfPoints > (bUseActObjKin == TRUE ? 3 : 4))
        {
          /* Transpose C matrix (mCt = T(mC)) */
          CML_v_TransposeMatrix(mCt, mC);

          /* Multiply Ct matrix by CopX matrix (mCtX = mCt * mCopX) */
          CML_v_MultiplyMatrices(mCtX, mCt, mCopX);

          /* Multiply CtX matrix by C matrix (mCtXC = mCtX * mC) */
          CML_v_MultiplyMatrices(mCtXC, mCtX, mC);

          /* Multiply Ct matrix by Y matrix (mCtY = mCt * mY) */
          CML_v_MultiplyMatrices(mCtY, mCt, mY);

          /* Evaluate total weighted trace variance */
          fResVar = (CML_GetMatrixElement(mCtXC, 0, 0) - 2.0F*CML_GetMatrixElement(mCtY, 0, 0) + fY2Sum) / fX0Sum;

          /* Assign values of Inv(X) matrix to polynomial struct */
          pPoly->fC0Var = fResVar * CML_GetMatrixElement(mInvX, 0, 0);
          pPoly->fC1Var = fResVar * CML_GetMatrixElement(mInvX, 1, 1);
          pPoly->fC2Var = fResVar * CML_GetMatrixElement(mInvX, 2, 2);
          pPoly->fC3Var = fResVar * CML_GetMatrixElement(mInvX, 3, 3);
        }
        else
        {
          /* Assign default values to polynomial struct */
          pPoly->fC0Var = 0.0F;
          pPoly->fC1Var = 0.0F;
          pPoly->fC2Var = 0.0F;
          pPoly->fC3Var = 0.0F;
        }

        /* Mark polynomial as valid */
        pPoly->bValid = TRUE;
      }
      else
      {
        /* X-matrix is badly conditioned */
        pPoly->bValid = FALSE;
      }
    }
    break;

  default:
    {
      /* Too less points */
      pPoly->bValid = FALSE;
    }
    break;
  }
}
#endif /* (0) Unused functions */

#if (FCT_CFG_NEW_TRACES_INTERFACE)
/* ****************************************************************************

  @fn             CAL_u_CalcObjTraceApproxPolyL2                             */ /*!

  @brief           Calculate 2-nd power polynomial for approximating trace

  @description     This function calculates the approximate polynomial fitting
                   the sample points using least square fit. The calculated
                   polynomial has the form f(x) = fC0 + fC1*x + fC2*x^2

                    @startuml
                    Start
                    Partition CAL_u_CalcObjTraceApproxPolyL2 {

                    : The number of trace points is minimum of the available trace points \n and the trace points to be used;
                    : Initialize the current X and Y coordinates with the trace head;
                    : Get valid number of trace points by skipping the trace points which are far; 
                    If (**number of trace points greater than 2 ?**) then (yes)
                        : Initialize the coefficient C0 of trace polynomial to first Y point of trace;
                        : Calculate necessary terms of linear equation set to use for least square fit;
                        If (**If diagonal of matrix of linear equations is positive**) then (yes)
                            : Convert the matrix to upper triangular form \n using Gaussian elimination;
                            : Calculate the matrix values via reverse elimination;
                            : Update coefficients using terms of linear equation;
                            : The trace polynomial is valid;
                        Else (no)
                            : Update coefficients C1,C2 to zero and \n C0 to first Y point of trace;
                            : The trace polynomial is invalid;
                        Endif
                    Else (no)
                        : Update the trace polynomial coefficients C1 and C2 to zero and \n C0 to Y coordinate of first trace point;
                        : The trace polynomial is invalid;
                        If (**Is number of trace points more than 1 ?**) then (yes)
                            : approximation of trace is using a line with two points;
                            : Update coefficients C0 to y-intercept of line, \n C1 to the slope of the line and C2 to zero;
                            : The trace polynomial is valid;
                        Endif
                    Endif
                    }
                    Stop
                    @enduml

  @return          uiUsedPts : The number of trace sample points used for the polynomial
                   approximation

  @param[in,out]   pPoly : Pointer to structure storing the second degree polynomial approximation of a trace [CAL_t_TracePolyL2 as defined in cp_ext.h]
                        pPoly->fC2 : Coefficient of second-order term                                     [-1f...+1f]
                        pPoly->fC1 : Coefficient of first-order term                                      [-1f...+1f]
                        pPoly->fC0 : Coefficient of zeroth-order term                                     [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX]
                        pPoly->isValid : Flag to indicate whether the trace polynomial is valid           [0u...1u]
  @param[in]       pTrace :
                        ObjectTraceBasic.Head.fXDist : Longitudinal coordinate of head sample [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                        ObjectTraceBasic.Head.fYDist : Lateral coordinate of head sample      [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                        ObjectTraceBasic.Points[i] : Pointer to two dimensional vector of trace samples [Vector2_i16_t as defined in Rte_Type.h]
                                                        with i [0 ... FIP_STATIC_TRACE_NO_OF_POINTS[
                        ObjectTraceBasic.Points[i].nXDist : Longitudinal coordinate of trace sample i [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                        ObjectTraceBasic.Points[i].nYDist : Lateral coordinate of trace sample i [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                        ObjectTraceBasic.uiHead : Index of the head trace sample [0 ... FIP_STATIC_TRACE_NO_OF_POINTS]
                        ObjectTraceBasic.uiNumberOfPoints : Number of trace points we have already seen    [0 ... FIP_STATIC_TRACE_NO_OF_POINTS[

  @param[in,out]   puiSkipPts : Filled to indicate the number of points that had to be skipped             [0 ... FIP_STATIC_TRACE_NO_OF_POINTS[

  @param[in]       uiNumPts : Number of points to use from beginning of trace                              [0 ... FIP_STATIC_TRACE_NO_OF_POINTS[

  @glob_in         No global input variable used
  @glob_out        No global output variable used

  @c_switch_part   -
  @c_switch_full   FCT_CFG_NEW_TRACES_INTERFACE : Switch to configure new interface for Traces

  @pre             None
  @post            None

  @InOutCorrelation   None

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis). \n
                   Test of run time error/warnings (Static code analysis).

  @traceability    <a href="doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-500-0009fc80">CAL_500</a> \n

  @created         -
  @changed         14.03.2016

  @author          Gergely Ungvary | Gergely.Ungvary@continental-corporation.com
*************************************************************************************************************************/
uint8 CAL_u_CalcObjTraceApproxPolyL2(CAL_t_TracePolyL2 * pPoly, const ObjectTraces_t * const pTrace, uint8 * puiSkipPts, uint8 uiNumPts)
{
  uint8 uiUsedPts;
  sint32 iNumPts;
  sint32 i,j,k;
  float32 fCurX, fCurY;
  float32 fXPow4Sum, fXPow3Sum, fXPow2Sum, fXSum;
  float32 fXYSum, fX2YSum, fYSum, fNumPts;
  float32 fLinEqMatrix[3][4];

  /* Take the smaller number of points available and number allowed to be used */
  iNumPts = MIN(pTrace->ObjectTraceBasic.uiNumberOfPoints, uiNumPts);

  /* Initialize the current X / Y coordinate with trace head */
  fCurX = pTrace->ObjectTraceBasic.Head.fXDist;
  fCurY = pTrace->ObjectTraceBasic.Head.fYDist;

  /* Set 'i', which is used as index into trace points array to head */
  i = pTrace->ObjectTraceBasic.uiHead;

  /* Skip all points that are too far behind us */
  *puiSkipPts = 0;
  while ((iNumPts > 0) && (fCurX <= (-10.f)))
  {
    const Vector2_i16_t * const pCurTrPoint = &pTrace->ObjectTraceBasic.Points[i];
    /* Update current X/Y for next iteration */
    fCurX += (pCurTrPoint->nXDist * TRACE_SCALE_CONST_INV);
    fCurY += (pCurTrPoint->nYDist * TRACE_SCALE_CONST_INV);
    /* Set 'i' to previous trace point : this corresponds to a i-=1 in
    modulo 'FIP_STATIC_TRACE_NO_OF_POINTS' arithmetic */
    i = ((i+(FIP_STATIC_TRACE_NO_OF_POINTS-1))%(FIP_STATIC_TRACE_NO_OF_POINTS));
    /* Decrease remaining number of points */
    iNumPts--;
    /* And increase number of points skipped */
    (*puiSkipPts)++;
  }

  /* Verify that we have at least 3 points, below that just use a line extrapolation */
  if (iNumPts > 2)
  {
    uiUsedPts = (uint8)iNumPts;
    /* First calculate the necessary terms for our linear equation set
    to use for least squares fit */
    fXPow4Sum = fXPow3Sum = fXPow2Sum = fXSum = 0.f;
    fXYSum = fX2YSum = fYSum = 0.f;
    fNumPts = (float32)iNumPts;
    /* Initilaize return poly C0 to Y0 (plays a role when X coordinates all zero) */
    pPoly->fC0 = fCurY;
    /* Go through all points and calculate the sums */
    while (iNumPts > 0)
    {
      const float32 fCurX2 = SQR(fCurX);
      const Vector2_i16_t * const pCurTrPoint = &pTrace->ObjectTraceBasic.Points[i];
      /* Update sums */
      fXSum += fCurX;
      fXPow2Sum += fCurX2;
      fXPow3Sum += fCurX2*fCurX;
      fXPow4Sum += SQR(fCurX2);
      fYSum += fCurY;
      fXYSum += fCurX*fCurY;
      fX2YSum += fCurX2*fCurY;
      /* Update current X/Y for next iteration */
      fCurX += (pCurTrPoint->nXDist * TRACE_SCALE_CONST_INV);
      fCurY += (pCurTrPoint->nYDist * TRACE_SCALE_CONST_INV);
      /* Set 'i' to previous trace point : this corresponds to a i-=1 in
      modulo 'FIP_STATIC_TRACE_NO_OF_POINTS' arithmetic */
      i = ((i+(FIP_STATIC_TRACE_NO_OF_POINTS-1))%(FIP_STATIC_TRACE_NO_OF_POINTS));
      /* Decrease remaining number of points */
      iNumPts--;
    }
    /* Now we have a linear equation set:
    fXPow4Sum*C2 + fXPow3Sum*C1 + fXPow2Sum*C0 = fX2YSum
    fXPow3Sum*C2 + fXPow2Sum*C1 + fXSum*C0     = fXYSum
    fXPow2Sum*C2 + fXSum*C1     + NumPts*C0    = fYSum
    Notice how the diagonal of the matrix is always positive, if there is
    at least one point with an X coordinate other than 0. Also note that
    the inverse of fXPowySum always exists (due to this) */
    if (fXPow2Sum > C_F32_DELTA)
    {
      fLinEqMatrix[0][0] = fXPow4Sum; fLinEqMatrix[0][1] = fXPow3Sum; fLinEqMatrix[0][2] = fXPow2Sum; fLinEqMatrix[0][3] = fX2YSum;
      fLinEqMatrix[1][0] = fXPow3Sum; fLinEqMatrix[1][1] = fXPow2Sum; fLinEqMatrix[1][2] = fXSum;     fLinEqMatrix[1][3] = fXYSum;
      fLinEqMatrix[2][0] = fXPow2Sum; fLinEqMatrix[2][1] = fXSum;     fLinEqMatrix[2][2] = fNumPts;   fLinEqMatrix[2][3] = fYSum;
      /* Now solve it, first converting the matrix to upper triangular form
      and then using elimination to solve it (Gauss elimination) */
      for (i=0; i<2; i++)
      {
        /* Calculate inverse of column max once here */
        float32 fDivisor = fLinEqMatrix[i][i];
        float32 fInvColumnMax;
        /* Calculate inverse of column max once here, prevent devision by zero */
        if (fABS(fDivisor) < C_F32_DELTA)
        {
          if (fDivisor < 0.0F)
          {
            fDivisor = -C_F32_DELTA;
          }
          else
          {
            fDivisor =  C_F32_DELTA;
          }
        }
        fInvColumnMax = 1.f / fDivisor;
        /* Now do forward substitution */
        for (j=3; j >= i; j--)
        {
          for (k=i+1; k<3; k++)
          {
            fLinEqMatrix[k][j] -= fLinEqMatrix[k][i]*fInvColumnMax * fLinEqMatrix[i][j];
          }
        }
      }
      /* Now do reverse elimination */
      for (i=2; i>=0; i--)
      {
        /* Verify that we have a leading non-zero value in the row */
        if ((fLinEqMatrix[i][i] > C_F32_EXT_DELTA) || (fLinEqMatrix[i][i] < -C_F32_EXT_DELTA))
        {
          /* Calculate inverse of the diagonal element currently processed */
          const float32 fInvCurDiagVal = 1.f / fLinEqMatrix[i][i];
          fLinEqMatrix[i][3] = fLinEqMatrix[i][3] * fInvCurDiagVal;
          fLinEqMatrix[i][i] = 1.f;
          for (j=i-1; j>=0; j--)
          {
            fLinEqMatrix[j][3] -= fLinEqMatrix[j][i] * fLinEqMatrix[i][3];
            fLinEqMatrix[j][i] = 0.f;
          }
        }
        else
        {
          fLinEqMatrix[i][3] = 0.f;
        }
      }
      /* Fill in result */
      pPoly->fC2 = fLinEqMatrix[0][3];
      pPoly->fC1 = fLinEqMatrix[1][3];
      pPoly->fC0 = fLinEqMatrix[2][3];
      pPoly->isValid = TRUE;
    }
    else
    {
      /* fXPow2Sum is zero -> all points have zero X coordinate */
      pPoly->fC2 = 0.f;
      pPoly->fC1 = 0.f;
      pPoly->isValid = FALSE;
      /* C0 initialization value to Y coordinate already OK */
    }
  }
  else
  {
    /* Initialize default return value */
    pPoly->fC2 = 0.f;
    pPoly->fC1 = 0.f;
    pPoly->fC0 = fCurY;
    uiUsedPts = 0;
    pPoly->isValid = FALSE;
    /* Approximate object movement by a simple line */
    if (iNumPts > 1)
    {
      const Vector2_i16_t * const pCurTrPoint = &pTrace->ObjectTraceBasic.Points[i];
      const float32 fDeltaX = (pCurTrPoint->nXDist * TRACE_SCALE_CONST_INV);
      const float32 fDeltaY = (pCurTrPoint->nYDist * TRACE_SCALE_CONST_INV);
      if ((fDeltaX > C_F32_DELTA) || (fDeltaX < -C_F32_DELTA))
      {
        pPoly->fC2 = 0.f;
        pPoly->fC1 = (fDeltaY / fDeltaX);
        pPoly->fC0 = fCurY - (fCurX * pPoly->fC1);
      }
      /* Set used points to 2 (linear interpolation between the two) */
      uiUsedPts = 2;
    }
  }
  return uiUsedPts;
}

/*************************************************************************************************************************
  Functionname:    CAL_f_CalcObjTraceSumSqDist                                                                          */ /*!

  @brief           Squared distance of trace samples from  2nd power polynomial

  @description     This function calculates the summed square distance from the
                   second order polynomial for the given first 'uiNumPts' of
                   the trace's points. This function can be used to calculate
                   the residual for a polynomial approximation of the trace.
                    
                    @startuml
                    Start
                    Partition CAL_f_CalcObjTraceSumSqDist {

                    : The number of trace points is minimum of the available trace points \n and the trace points to be used;
                    : Initialize the current X and Y coordinates with the trace head;
                    : Get valid number of trace points by skipping the trace points which are far; 
                    while (**valid trace points are available**) is (yes) 
                        : Calculate the signed distance of trace point to trace polynomial;
                        : Calculate the sum of the squared signed distance of the \n trace points to the polynomial;
                        : Find minimum and maximum X value of trace point;
                        : Update the X and Y coordinates for the trace points;
                    endwhile (no)
                    : Store the minimum and maximum X value of trace point;
                    }
                    Stop
                    @enduml

  @return          fSumDistance : Sum of squared lateral distance of each trace point to the approximated polynomial [0 ... FIP_STATIC_TRACE_NO_OF_POINTS*SQR(PI/2*RW_FCT_MAX)] m

  @param[in]       pPoly : Pointer to second degree polynomial [CAL_t_TracePolyL2 as defined in cp_ext.h]
  @param[in]       pTrace : Pointer to trace containing the points for which the summed squared distance
                            shall be calculated [ObjectTraces_t as defined in Rte_Type.h]
                      ObjectTraceBasic.uiNumberOfPoints : Number of trace points we have already seen        [0 ... FIP_STATIC_TRACE_NO_OF_POINTS]
                      ObjectTraceBasic.Head.fXDist : Current longitudinal coordinate of trace head           [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                      ObjectTraceBasic.Head.fYDist : Current lateral coordinate of trace head                [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      ObjectTraceBasic.uiHead : Index of head trace point                                    [0 ... FIP_STATIC_TRACE_NO_OF_POINTS-1]
                      ObjectTraceBasic.Points : Array of trace points                                        [0 ... FIP_STATIC_TRACE_NO_OF_POINTS]
  @param[out]      pfMinX : The smallest X distance of the sample points                                     [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
  @param[out]      pfMaxX : The greatest X distance of the sample points                                     [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
  @param[in]       uNumPtsSkipped : Number of points to use from beginning of trace                          [0 ... FIP_STATIC_TRACE_NO_OF_POINTS]
  @param[in]       uiNumPts : Number of points to use from beginning of trace                                [0 ... FIP_STATIC_TRACE_NO_OF_POINTS]

  @glob_in         No global input variable used
  @glob_out        No global output variable used

  @c_switch_part   -
  @c_switch_full   FCT_CFG_COURSE_PREDICTION : Switch to configure FCT support for CP sub-component

  @pre             None
  @post            None

  @InOutCorrelation   None

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis). \n
                   Test of run time error/warnings (Static code analysis).

  @traceability    <a href="doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-502-0009fc80">CAL_502</a> \n

  @created         -
  @changed         15.03.2016

  @author          Gergely Ungvary |  gergely.ungvary@continental-corporation.com | +36 88 548 671
*************************************************************************************************************************/
float32 CAL_f_CalcObjTraceSumSqDist(const CAL_t_TracePolyL2 * const pPoly, const ObjectTraces_t * const pTrace, float32 * const pfMinX, float32 * const pfMaxX, uint8 uNumPtsSkipped, uint8 uiNumPts)
{
  sint32 iNumPts;
  uint32 i;
  float32 fMinX, fMaxX;
  float32 fCurX, fCurY;
  float32 fSumDistance = 0.f;

  /* Take the smaller number of points available and number allowed to be used */
  iNumPts = MIN(pTrace->ObjectTraceBasic.uiNumberOfPoints, uiNumPts);

  /* Initialize the current X / Y coordinate with trace head */
  fCurX = pTrace->ObjectTraceBasic.Head.fXDist;
  fCurY = pTrace->ObjectTraceBasic.Head.fYDist;

  /* Set 'i', which is used as index into trace points array to head */
  i = pTrace->ObjectTraceBasic.uiHead;

  /* Skip the required amount of trace points */
  while (uNumPtsSkipped > 0)
  {
    const Vector2_i16_t * const pCurTrPoint = &pTrace->ObjectTraceBasic.Points[i];
    /* Update current X/Y for next iteration */
    fCurX += (pCurTrPoint->nXDist * TRACE_SCALE_CONST_INV);
    fCurY += (pCurTrPoint->nYDist * TRACE_SCALE_CONST_INV);
    /* Set 'i' to previous trace point : this corresponds to a i-=1 in
    modulo 'FIP_STATIC_TRACE_NO_OF_POINTS' arithmetic */
    i = ((i+(FIP_STATIC_TRACE_NO_OF_POINTS-1))%(FIP_STATIC_TRACE_NO_OF_POINTS));
    uNumPtsSkipped--;
    iNumPts--;
  }

  /* Initialize minimum/maximum X to head's X coordinate */
  fMinX = fMaxX = fCurX;

  /* Go through the points calculating the squared distance */
  while (iNumPts > 0)
  {
    const Vector2_i16_t * const pCurTrPoint = &pTrace->ObjectTraceBasic.Points[i];
    /* Calculate signed distance of current point */
    const float32 fCurDist = CAL_f_CalcDistToPolyL2Y(pPoly, fCurX, fCurY);
    /* Add the current squared distance to the sum */
    fSumDistance += SQR(fCurDist);
    /* Update minimum/maximum X when necessary */
    fMinX = MIN_FLOAT(fMinX, fCurX);
    fMaxX = MAX_FLOAT(fMaxX, fCurX);
    /* Update current X/Y for next iteration */
    fCurX += (pCurTrPoint->nXDist * TRACE_SCALE_CONST_INV);
    fCurY += (pCurTrPoint->nYDist * TRACE_SCALE_CONST_INV);
    /* Set 'i' to previous trace point : this corresponds to a i-=1 in
    modulo 'FIP_STATIC_TRACE_NO_OF_POINTS' arithmetic */
    i = ((i+(FIP_STATIC_TRACE_NO_OF_POINTS-1))%(FIP_STATIC_TRACE_NO_OF_POINTS));
    /* Decrease remaining number of points */
    iNumPts--;
  }
  /* Store min/max X in output params */
  *pfMinX = fMinX;
  *pfMaxX = fMaxX;
  return fSumDistance;
}
#endif  /* FCT_CFG_NEW_TRACES_INTERFACE */

/*************************************************************************************************************************
  Functionname:    CPCalcDistToPolyL2Y                                                                              */ /*!

  @brief           Calculate a points distance to a 2nd degree polynomial

  @description     Calculate the signed distance of a given point to the polynomial (as calculated by SICalculateTracePoly)
                   Formerly called SICalcDistToPolyL2Y

                    @startuml
                    Start
                    Partition CAL_f_CalcDistToPolyL2Y {

                    : Calculate the signed distance of a given point to the second degree trace polynomial;
                    }
                    Stop
                    @enduml

  @return          The signed distance to the polynomial [full range of datatype float32]

  @param[in]       pPoly : Structure storing the second degree polynomial approximation of a trace, using y = f(x) = fC0 + fC1 * x + fC2 * x^2
                      pPoly->fC0 [full range of datatype float32]
                      pPoly->fC1 [full range of datatype float32]
                      pPoly->fC2 [full range of datatype float32]
                      pPoly->isValid [TRUE, FALSE]
  @param[in]       fX : x coordinate of the point [full range of datatype float32]
  @param[in]       fY : y coordinate of the point [full range of datatype float32]

  @glob_in         No global input variable used
  @glob_out        No global output variable used

  @c_switch_part   -
  @c_switch_full   FCT_CFG_COURSE_PREDICTION : FCT support for CP sub-component

  @pre             None
  @post            None

  @InOutCorrelation   Output(Distance of point to 2nd order trace polynomial) = (fY - (fC0 + fX*(fC1 +Fc2*fX)))

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis). \n
                   Test of run time error/warnings (Static code analysis).

  @traceability    <a href="doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-503-0009fc80">CAL_503</a> \n

  @created         20.10.2011
  @changed         10.09.2015

  @todo           Add better approximation

  @author          Gergely Ungvary | Gergely.Ungvary@continental-corporation.com
*************************************************************************************************************************/
float32 CAL_f_CalcDistToPolyL2Y(const CAL_t_TracePolyL2 * const pPoly, const float32 fX, const float32 fY)
{
  return fY - ((((pPoly->fC2 * fX) + pPoly->fC1) * fX) + pPoly->fC0);
}

/*************************************************************************************************************************
  Functionname:    CAL_f_CalcSumSqDistance                                                                              */ /*!

  @brief           Calculate the sum of squared distance of points to a polynomial.

  @description     Calculate the sum of squared distance of points to a polynomial.

                    @startuml
                    Start
                    Partition CAL_f_CalcSumSqDistance {

                    while (**Trace points are available ? **) is (yes)
                        : Calculate the signed distance of each trace point to the trace polynomial;
                        : Calculate the sum of squares of the distance of trace point to the polynomial;
                    endwhile (no)
                    }
                    Stop
                    @enduml

  @return          fSumDistance : The sum of the squared point to approximation polynomial distance. This is useful for determining
                   the residual of the original sample points [0 ... FIP_STATIC_TRACE_NO_OF_POINTS*SQRT(PI/2*RW_FCT_MAX)]

  @param[in]       pPoly : Pointer to structure storing the second degree polynomial approximation of a trace [CAL_t_TracePolyL2 as defined in cp_ext.h]
  @param[in]       pfPointX :  array of x coordinates of trace points                  [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] of size [0 ... FIP_STATIC_TRACE_NO_OF_POINTS]
  @param[in]       *pfPointY : array of y coordinates of trace points                  [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] of size [0 ... FIP_STATIC_TRACE_NO_OF_POINTS]
  @param[in]       uNumPoints : Number of trace points                                 [0 ... FIP_STATIC_TRACE_NO_OF_POINTS]

  @glob_in         No global input variable used
  @glob_out        No global output variable used

  @c_switch_part   -
  @c_switch_full   FCT_CFG_COURSE_PREDICTION : Switch to configure FCT support for CP sub-component

  @pre             None
  @post            None

  @InOutCorrelation   None

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis). \n
                   Test of run time error/warnings (Static code analysis).

  @traceability    <a href="doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-504-0009fc80">CAL_504</a> \n

  @created         20.10.2011
  @changed         14.03.2016

  @author          Gergely Ungvary | Gergely.Ungvary@continental-corporation.com
*************************************************************************************************************************/
float32 CAL_f_CalcSumSqDistance(const CAL_t_TracePolyL2 * const pPoly, const float32 * pfPointX, const float32 *pfPointY, uint8 uNumPoints)
{
  float32 fSumDistance = 0.f;

  /* Go through the points, and calculate the distances */
  while (uNumPoints > 0u)
  {
    /* Calculate signed distance of current point */
    const float32 fCurDist = CAL_f_CalcDistToPolyL2Y(pPoly, *pfPointX, *pfPointY);
    /* Add the current squared distance to the sum */
    fSumDistance += SQR(fCurDist);
    /* Advance point coordinate pointers and update remaining number of points */
    pfPointX++;// PRQA S 0489
   /* date: 2015-04-27, reviewer: Gangadhar Badiger, reason: Application wide deviation to rule agreed upon*/
    pfPointY++;// PRQA S 0489
   /* date: 2015-04-27, reviewer: Gangadhar Badiger, reason: Application wide deviation to rule agreed upon*/
    uNumPoints--;// PRQA S 0489
   /* date: 2015-04-27, reviewer: Gangadhar Badiger, reason: Application wide deviation to rule agreed upon*/
  }
  return fSumDistance;
}

#endif /* (FCT_CFG_ACC_CALL) */
/* ************************************************************************* */
/*   Copyright ADC-GmbH, Lindau                                              */
/* ************************************************************************* */
// PRQA L:STTLN_EXCEEDED

