/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   ARS5xx

CPU:                       CPU-Independent

COMPONENT:                 CAL (Common ACC Library)

PACKAGENAME:               cal_dist2curve.c

DESCRIPTION:               Functionalities of distance to curve calculations

AUTHOR:                    Shang, Hanyu

CREATION DATE:             27.02.2017

VERSION:                   $Revision: 1.7 $

LEGACY VERSION:            Revision: 2.0


**************************************************************************** */
/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "cal_int.h"/* PRQA S 0380
date: 28/06/2019 author: Pruthvi Reason: Can be ignored as no functional impact */

#if (FCT_CFG_ACC_CAL)
/*****************************************************************************
  FUNCTION PROTOTYPES
*****************************************************************************/
static void CAL_v_ApproximateRefpoint(const float32 fX, const float32 fY, const float32 fC0, const float32 fC1, float32 * pfRefX);

/*************************************************************************************************************************
  Functionname:    CAL_t_CalculateDistancePoint2Circle                                                                  */ /*!

  @brief           Calculates the distance to trajectory

  @description     Calculates the distance to trajectory for the given fX, fY and fC0.

                    @startuml
                    Partition CAL_t_CalculateDistancePoint2Circle {
                    Start
                        If (**Is Curvature of trajectory more than curvature threshold value for circle ?**) then (yes)
                            : calculate the radius as the reciprocal of the curvature;
                            : Calculate normal vector to the course;
                            If (**curvature is positive?**) then (yes)
                                : The distance to trajectory is calculated as the difference between \n the radius and norm vector and is positive;
                                : The distance on trajectory is calculated using radius and \n the angle of sample points to trajectory;
                            Else (no)
                                : The distance to trajectory is calculated as the difference between \n the radius and norm vector and is negative;
                                : The distance on trajectory is calculated using radius and \n the angle of sample points to trajectory;
                            endif
                            : Calculate reference point (X,Y) using the sample points and \n the distance to course;
                        Else (no)
                            : Calculate the reference point (X,Y), distance to trajectory and \n distance on the trajectory using parabolic approximation;
                        endif
                    Stop
                    }
                    @enduml

  @return          CAL_t_TrajRefPoint : which contains Trajectory Reference point coordinates Distance to directory
                                      Distance from vehicle center of gravity to object on trajectory.
                                      ReferencePoint.fX           [-5*RW_FCT_MAX        5*RW_FCT_MAX] m
                                      ReferencePoint.fY           [-PI/2*RW_FCT_MAX     PI/2*RW_FCT_MAX] m
                                      ReferencePoint.fDistToTraj  [-PI/2*RW_FCT_MAX     PI/2*RW_FCT_MAX] m
                                      ReferencePoint.fDistOnTraj  [-5*RW_FCT_MAX        5*RW_FCT_MAX] m

  @param[in]       fX : X coordinate to get trajectory distance of            [-5*RW_FCT_MAX        5*RW_FCT_MAX] m
  @param[in]       fY : Y coordinate to get trajectory distance of            [-PI/2*RW_FCT_MAX     PI/2*RW_FCT_MAX] m
  @param[in]       fC0 : Curvature of clothoid                                [-1   +1] m^-1

  @glob_in         No global input variable used
  @glob_out        No global output variable used

  @c_switch_part   -
  @c_switch_full   -FCT_CFG_COURSE_PREDICTION    : FCT support for CP sub component

  @InOutCorrelation   None

  @pre             None
  @post            None

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis). \n
                   Test of run time error/warnings (Static code analysis).
  
  @traceability    <a href="doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-494-0009fc80">CAL_494</a> \n

  @created         -
  @changed         2/26/2016

  @author          Norman Apel,  norman.apel@contiautomotive.com
*************************************************************************************************************************/
CAL_t_TrajRefPoint CAL_t_CalculateDistancePoint2Circle(float32 fX, float32 fY, float32 fC0)
{
  float32 fRadius         = 999999.f;
  float32 fR      = 0.f;
  float32 fDistToCourse     = 0.f; 
  float32 fDistOnCourse     = 0.f; 
  float32 fNormVecX       = 0.f;
  float32 fNormVecY       = 0.f;
  float32 fRefCourseDistX = 0.f;
  float32 fRefCourseDistY = 0.f; 
  CAL_t_TrajRefPoint ReferencePoint;

  if (fABS( fC0 ) > CAL_CURVATURE_USE_CIRCLE_EQUATION)/* PRQA S 3416 */
  /* Date: 02-12-2020, Reviewer:Gireesh , Reason:This warning  does not have any critical impact the functionality. */
  {
    fRadius = 1.0f/(fC0);
    /* Object Transform to Moment Pole Coordinates */
    fY-=fRadius;
    fR = SQRT_( SQR(fX) + SQR(fY));
    /* NormVec to Course always pointing to the left side of course */
   if(fR >= C_F32_DELTA )
   {
    if(fC0 > 0.0f)
    {
      fNormVecX = -fX/fR;
      fNormVecY = -fY/fR;
      fDistToCourse = (fABS(fRadius)-fR);
      fDistOnCourse = fRadius * (C_HALFPI + ATAN2_(fY, fX));
    }
    else
    {
      fNormVecX = fX/fR;
      fNormVecY = fY/fR;
      fDistToCourse = -(fABS(fRadius)-fR);
      fDistOnCourse = fRadius * (ATAN2_(fY, fX) - C_HALFPI);
    }
   }
    /* DistCourse (fRadius-fR) positive when object left of course; negative when object right of course*/
    /* |RefCourseDistXRef| + DistCourse * |dNormVec[0]| = |fX| */
    /* |RefCourseDistYRef|                |dNormVec[1]|   |fY| */
    fRefCourseDistX =  fX - (fNormVecX * fDistToCourse);
    fRefCourseDistY = (fY - (fNormVecY * fDistToCourse) ) + fRadius;
    
  }
  else
  {
    /* use old parabolic approximation for wide curves and distance in Y- Direction*/
    fRefCourseDistX    = fX;
    fRefCourseDistY    = SQR( fX ) * (fC0) * (0.5f);
    fDistToCourse = (fY - fRefCourseDistY);
    /*instead of integral 0 to fX of function SQRT(1+(fC0*x)^2) dx*/
    fDistOnCourse = fX;
  }
  ReferencePoint.fX              = fRefCourseDistX;
  ReferencePoint.fY              = fRefCourseDistY;
  ReferencePoint.fDistToTraj     = fDistToCourse;
  ReferencePoint.fDistOnTraj     = fDistOnCourse;
   
  return ReferencePoint;
}

/*************************************************************************************************************************
  Functionname:    CAL_t_CalculateDistancePoint2Clothoid                                                                */ /*!

  @brief           Calculates the distance to trajectory.

  @description     Calculates the distance to trajectory for the given fX, fY, fC0 and fC1.

                    @startuml
                    Partition CAL_t_CalculateDistancePoint2Clothoid {
                    Start
                        : Calculate the reference point X using the given points, coefficients C0 and C1;
                        : Calculate the reference point Y using trace polynomial equation;
                        : The distance to the trajectory is calculated as the distance between the \n reference trajectory point (X,Y) and the given point;
                        If (**difference between Y value of a point and reference point is negative**) then
                            : The distance to the trajectory shall be made negative;
                        endif
                        : Update the distance on the trajectory to the reference point X;
                    Stop
                    }
                    @enduml

  @return          CAL_t_TrajRefPoint - which contains
                                      Trajectory Reference point coordinates
                                      Distance to directory
                                      Distance from vehicle center of gravity to object on trajectory

  @param[in]       fX : X coordinate to get trajectory distance of            [-5*RW_FCT_MAX        5*RW_FCT_MAX] m
  @param[in]       fY : Y coordinate to get trajectory distance of            [-PI/2*RW_FCT_MAX     PI/2*RW_FCT_MAX] m
  @param[in]       fC0 : C0 of 3 degree clothoid polynom                      [-1   +1] m^-1
  @param[in]       fC1 : C1 of 3 degree clothoid polynom                      [-1   +1] m^-2

  @glob_in         No global input variable used
  @glob_out        No global output variable used

  @c_switch_part   -
  @c_switch_full   FCT_CFG_COURSE_PREDICTION    : FCT support for CP sub component

  @InOutCorrelation   None

  @pre             None
  @post            None

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis). \n
                   Test of run time error/warnings (Static code analysis).

  @traceability    <a href="doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-494-0009fc80">CAL_494</a>

  @created         -
  @changed         2/26/2016

  @author          Norman Apel,  norman.apel@contiautomotive.com
*************************************************************************************************************************/
CAL_t_TrajRefPoint CAL_t_CalculateDistancePoint2Clothoid(const float32 fX, const float32 fY, const float32 fC0, const float32 fC1)
{
  float32 fTemp;
  float32 fYDiff;  
  CAL_t_TrajRefPoint ReferencePoint;
  ReferencePoint.fX          = fX;
  CAL_v_ApproximateRefpoint(fX, fY, fC0, fC1, &ReferencePoint.fX);

  fTemp                      = SQR(ReferencePoint.fX);
  ReferencePoint.fY          = (0.5f*fC0*fTemp) + ((fC1*fTemp*ReferencePoint.fX) * C_SIXTH);
  fYDiff = fY - ReferencePoint.fY;
  ReferencePoint.fDistToTraj = SQRT_(SQR(fX - ReferencePoint.fX)+SQR(fYDiff));
  if (fYDiff < 0.0f)
  {
    ReferencePoint.fDistToTraj *= -1.0f;
  }

  /*@todo implement arclength on clothoid approximation*/
  /*@hack use difference in x instead*/
  ReferencePoint.fDistOnTraj = ReferencePoint.fX;

  return ReferencePoint;
}

/*************************************************************************************************************************
  Functionname:    CAL_v_ApproximateRefpoint                                                                            */ /*!

  @brief           calculates X value of the normal crossing from object to clothoid tangent at last approximated X value

  @description     calculates X value of the normal crossing from object to clothoid tangent at last approximated X value

                    @startuml
                    Partition CAL_v_ApproximateRefpoint {
                    Start
                        If (** Is slope of the clothoid is less than threshold 0.0001 ?**) then (yes)
                            : Set reference point X as X value of the input sample point;
                        Else (no)
                            : Calculate X value of the reference point using the clothoid polynomial;
                        endif
                    }
                    Stop
                    @enduml

  @return          static void

  @param[in]       fX : X coordinate to get trajectory distance of            [-5*RW_FCT_MAX        5*RW_FCT_MAX] m
  @param[in]       fY : Y coordinate to get trajectory distance of            [-PI/2*RW_FCT_MAX     PI/2*RW_FCT_MAX] m
  @param[in]       fC0 : C0 of 3 degree clothoid polynom                      [-1   +1] m^-1
  @param[in]       fC1 : C1 of 3 degree clothoid polynom                      [-1   +1] m^-2
  @param[in,out]   pfRefX : last approximated X value of Reference point      [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m

  @glob_in         No global input variable used
  @glob_out        No global output variable used

  @c_switch_part   -
  @c_switch_full   -FCT_CFG_COURSE_PREDICTION    : FCT support for CP sub component

  @InOutCorrelation   None

  @pre             None
  @post            None

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis). \n
                   Test of run time error/warnings (Static code analysis).

  @traceability    <a href="doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-494-0009fc80">CAL_494</a> \n

  @created         -
  @changed         2/26/2016

  @author          Norman Apel,  norman.apel@contiautomotive.com
*************************************************************************************************************************/
static void CAL_v_ApproximateRefpoint(const float32 fX, const float32 fY, const float32 fC0, const float32 fC1, float32 * pfRefX)
{
  float32 fXc     = *pfRefX;
  float32 fXXc    = SQR(fXc);
  float32 fC1XXc  = fC1*fXXc;
  float32 fC0Xc   = fC0*fXc;
  float32 fYc     = (C_SIXTH*fC1XXc*fXc) + (0.5f*fC0Xc*fXc);
  float32 fm      = ((0.5f*fC1XXc)+fC0Xc);
  float32 fm_inv;

  if(fABS(fm) < C_F32_DELTA)/* PRQA S 3416 */
  /* Date: 02-12-2020, Reviewer:Gireesh , Reason:This warning  does not have any critical impact the functionality. */
  {
    *pfRefX = fX;
  }
  else
  {
    fm_inv  = 1.0f/fm;  
    *pfRefX = ( ((fY - fYc) + (fm*fXc)) + (fm_inv*fX) ) / ( fm + fm_inv );
  }
}
#endif /*!< (FCT_CFG_ACC_CAL) */

