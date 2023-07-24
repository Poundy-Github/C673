/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   ARS5xx

CPU:                       CPU-Independent

COMPONENT:                 CAL (Common ACC Library)

PACKAGENAME:               cal_linetraceseg.c

DESCRIPTION:               Functionalities for line trace segment calculations

AUTHOR:                    Shang, Hanyu

CREATION DATE:             27.02.2017

VERSION:                   $Revision: 1.6 $

LEGACY VERSION:            Revision: 2.0

---*/ /*---
CHANGES:                    $Log: cal_linetraceseg.c  $
CHANGES:                    Revision 1.6 2020/06/29 15:57:31CEST P, Gowthama (uib47932) (uib47932) 
CHANGES:                    [CAL] Update CAL Source Code files according to SWE.3 ASPICE Process Detailed Design
CHANGES:                    Revision 1.5 2019/07/29 12:13:15CEST Nadiminti, Saroja Kumar (uib59070) (uib59070) 
CHANGES:                    [CAL] Disabling unused Code and redundant code in CAL for Code Optimization
CHANGES:                    Revision 1.4 2019/07/10 08:43:06CEST M R, Pruthvi (uib61632) (uib61632) 
CHANGES:                    QAF level-3 warninings fix/suppress
CHANGES:                    Revision 1.3 2019/06/19 11:31:12CEST P, Gowthama (uib47932) (uib47932) 
CHANGES:                    Plant UML update
CHANGES:                    Revision 1.2 2017/04/25 12:54:03CEST uidj3583 
CHANGES:                    Update CAL towards mainstream maturity

**************************************************************************** */
/*****************************************************************************
  INCLUDES
*****************************************************************************/

/*! @todo: later clean-up include structure to only include "cp.h" and let it
include the files necessary for our run-time environment */

#include "cal_int.h"/* PRQA S 0380
date: 28/06/2019 author: Pruthvi Reason: Can be ignored as no functional impact */

/* PRQA S 1863 450
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
/*************************************************************************************************************************
  Functionname:    CAL_f_CalculatePoint2LineSegListDist                                                                 */ /*!

  @brief           Calculate signed distance between samples (line segments) and a point

  @description     Calculates the signed distance between a CAL_t_PosSamples structure,
                   which defines a list of contigous line segments and a point.
                   If the samples structure contains at least two sample points,
                   then it consists of one or more line segments. In this case the
                   algorithm first searches for the sample point that is closest
                   to the point. While performing this search, it also selects
                   the neighbor sample point which is nearer to the point. Later
                   it uses these two points to determine the distance of the point
                   from the line segment between the nearest sample & it's nearest
                   neighbor.If the samples structure consists of a single sample point,
                   then the return value is the distance from that point.
                   If the samples structure contains no points, then it returns
                   the predefined CAL_INFINITE_DIST value 

                    @startuml
                    Start
                    Partition CAL_f_CalculatePoint2LineSegListDist {

                    if (** number of samples more than 0**) then (yes)
                      : Initialize last sample square distance to distance to fist sample;
                      : Set this square distance as minimum and the sign of distance to positive;
                      If (**Is number of samples equal to 2 or more ?**) then (yes)
                        : Calculate the squared distance between current and last sample points;
                        : Calculate the squared distance of current sample point;
                        If (**samples are not same**) then (yes)
                            : calculate the cross product of line vector and \n vector from last sample to the given point;
                            : calculate the squared distance of line segment;
                            : Set squared distance to line segment as minimum squared distance \n if it is less than minimum so far;
                              : sign of minimum squared distance depends on cross product;
                        Endif
                        : Store the current sample and the squared distance of current sample;
                      Endif
                      : The signed distance between samples and point is square root \n of the minimum squared distance along with the sign; 
                    Endif

                    }
                    Stop
                    @enduml

  @return          The signed distance of the point from the line segments in the
                   samples. (The distance is negative if the point is to the left
                   of the line segment that is closest to it) Note: if the point
                   is closest to an end point of the line segment list and
                   bExtendEndLineSegs is false, then the distance is a distance
                   to point (which is always positive) 

  @param[in]       pSamples :           Pointers to the line segment samples GDBVector2_t defined in cml_mapping.h
                                        pSamples.f0    0th element of the pSamples                    [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                                        pSamples.f1    0th element of the pSamples                    [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @param[in]       NumSamples :         Number of samples                                             [0 ... 20]
  @param[in]       fPointX :            X coordinate of the point                                     [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
  @param[in]       fPointY :            Y coordinate of the point                                     [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @param[in]       bExtendEndLineSegs : Boolean (only supported when compiler
                                        switch CAL_CFG_EXTEND_SAMPLE_END_LINE_SEGS is set) which
                                        indicates if first and last line segment shall be treated
                                        as an infinite line (effectively extending it outwards)       [0 or 1]

  @glob_in         No global input variable used
  @glob_out        No global output variable used

  @c_switch_part    CAL_CFG_EXTEND_SAMPLE_END_LINE_SEGS        Static switch to enable extending point lists at both ends to infinite
                                                              distance. Note: this switch has to be on, so functions CAL_f_CalculatePoint2SamplesDist,
                                                              CPCalculatePoint2TraceDist etc. boolean parameter for extending end segments has any effect.

  @c_switch_full    FCT_CFG_COURSE_PREDICTION                 FCT configuration for course prediction.

  @pre             None
  @post            None

  @InOutCorrelation   None

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis). \n
                   Test of run time error/warnings (Static code analysis).

  @traceability    <a href="doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-505-0009fc80">CAL_505</a> \n

  @created         -
  @changed         3/24/2016

  @author          Gergely Ungvary
*************************************************************************************************************************/
fDistance_t CAL_f_CalculatePoint2LineSegListDist(const GDBVector2_t pSamples[], uint8 NumSamples, fDistance_t fPointX, fDistance_t fPointY, boolean bExtendEndLineSegs)
{
  fDistance_t fSamplesDist;

  /* Initialize return value to infinite distance */
  fSamplesDist = CAL_INFINITE_DIST;
  /* If more then two samples are present, then these samples form a line-segment(s) */
  if (NumSamples > (uint8)0)
  {
    fDistance_t fSmallestAbsSqDist;
    fDistance_t fSmallestDistSign;
    fDistance_t fLastSamplePtSqDist;
    const GDBVector2_t * pPrevSample = pSamples;
    uint8 uRemainSegs;

    /* Initialize last sample square distance to distance to first sample */
    fLastSamplePtSqDist = (SQR(fPointX - pSamples[0].f0) + SQR(fPointY - pSamples[0].f1));

    /* Also set this as the minimum (initialization) */
    fSmallestAbsSqDist = fLastSamplePtSqDist;

    /* Also set sign of distance to positive (with a single point) we
    can only have positive signs, as no directions yet known */
    fSmallestDistSign = 1.0f;

    /* Loop through line segments. Loop runs (NumSamples-1) times */
    for (uRemainSegs=(uint8)(NumSamples-1u); uRemainSegs > (uint8)0; uRemainSegs--)
    {
      float32 fCurLineSegDistSq;

      /* Get current sample from previous one */
      const GDBVector2_t * const pCurSample = &pPrevSample[1];
      /* Calculate delta X and delta Y between the sample points */
      const fDistance_t fSampleDX = (pCurSample->f0 - pPrevSample->f0);
      const fDistance_t fSampleDY = (pCurSample->f1 - pPrevSample->f1);
      /* Based on delta X & Y calculate squared distance of sample points */
      const float32 fSamplesSqDist = SQR(fSampleDX) + SQR(fSampleDY);
      /* Calculate current sample point square distance */
      const float32 fCurSamplePtSqDist = (SQR(fPointX - pCurSample->f0) + SQR(fPointY - pCurSample->f1));
      /* Verify that the samples are not the same (if they are, we can skip
      processing, since results from last line segment still apply */
      if (fSamplesSqDist > C_F32_DELTA)
      {
        /* Calculate cross product of line vector and vector from line segment
        starting point (previous sample) to the point */
        const float32 fCrossProd = ((fSampleDX * (pPrevSample->f1 - fPointY)) - (fSampleDY * (pPrevSample->f0 - fPointX)));
        /* Using the pythagoras theorem verify that the triangle between the previous
        sample, current sample and the point has angles smaller equal 90 degrees in
        the samples' corners */
        if (
          ((fSamplesSqDist + fLastSamplePtSqDist) >= fCurSamplePtSqDist)
#if (CAL_CFG_EXTEND_SAMPLE_END_LINE_SEGS)
          || ((bExtendEndLineSegs == TRUE) && (pPrevSample == pSamples))
#endif /* (CAL_CFG_EXTEND_SAMPLE_END_LINE_SEGS) */
          )
        {
          if (
            ((fSamplesSqDist + fCurSamplePtSqDist) >= fLastSamplePtSqDist)
#if (CAL_CFG_EXTEND_SAMPLE_END_LINE_SEGS)
            || ((bExtendEndLineSegs == TRUE) && (pCurSample == &pSamples[NumSamples-(uint8)1]))
#endif /* (CAL_CFG_EXTEND_SAMPLE_END_LINE_SEGS) */
            )
          {
            /* Both angles in the sample points are smaller 90 degrees,
            the distance to the line segment is the distance to the line.
            Based on the cross product we can calculate the square distance
            by dividing the cross products square with the length of the
            sample delta vector length's square */
            fCurLineSegDistSq = (SQR(fCrossProd)/fSamplesSqDist);
          }
          else
          {
            /* The angle in the current sample point is > 90 degrees,
            the distance to the line segment is the distance to the
            current sample point */
            fCurLineSegDistSq = fCurSamplePtSqDist;
          }
        }
        else
        {
          /* The angle in the last sample point is > 90 degrees,
          the distance to the line segment is the distance to the
          last sample point */
          fCurLineSegDistSq = fLastSamplePtSqDist;
        }
        /* Now check if the distance to the current line segment is
        smaller then the minimum found so far, if yes, store new
        minimum value NOTE: smaller equal used to catch the special
        case of when the first point is being processed: then if
        the end-point is the nearmost, then
        fCurLineSegDistSq == fSmallestAbsSqDist, but we do not yet
        know the sign, thus updated that now. */
        if (fCurLineSegDistSq <= fSmallestAbsSqDist)
        {
          fSmallestAbsSqDist = fCurLineSegDistSq;
          fSmallestDistSign  = ((fCrossProd >= 0.f)?1.f:-1.f);
        }
      }
      /* Store last data for next iteration */
      pPrevSample = pCurSample;
      fLastSamplePtSqDist = fCurSamplePtSqDist;
    }

    /* When we reach this point, we know that fSmallesAbsSqDist is the
    square of the distance we are looking for, while fSmallestDistSign
    is the sign of it */
    fSamplesDist = SQRT_(fSmallestAbsSqDist) * fSmallestDistSign;
  }
  
  return fSamplesDist;
}

/*************************************************************************************************************************
  Functionname:    CAL_f_CalculatePoint2LineSegCoordArr                                                                 */ /*!

  @brief           Calculate signed distance between line segments and point 

  @description     Calculate signed distance between line segments specified
                   by seperate coordinate arrays for X & Y.
                   Same implementation as CAL_f_CalculatePoint2LineSegListDist, just
                   with seperate X & Y coordinate arrays passed

                    @startuml
                    Start
                    Partition CAL_f_CalculatePoint2LineSegCoordArr {

                    if (** number of samples more than 0**) then (yes)
                      : Initialize last sample square distance to distance to fist sample;
                      : Set this square distance as minimum and the sign of distance to positive;
                      If (**Is number of samples equal to 2 or more ?**) then (yes)
                        : Calculate the squared distance between current and last sample points;
                        : Calculate the squared distance of current sample point;
                        If (**samples are not same**) then (yes)
                            : calculate the cross product of line vector and \n vector from last sample to the given point;
                            : calculate the squared distance of line segment;
                            : Set squared distance to line segment as minimum squared distance \n if it is less than minimum so far;
                              : sign of minimum squared distance depends on cross product;
                        Endif
                        : Store the current sample and the squared distance of current sample;
                      Endif
                      : The signed distance between samples and point is square root \n of the minimum squared distance along with the sign; 
                    Endif

                    }
                    Stop
                    @enduml

  @return          The signed distance of the point from the line segments in the
                   samples. (The distance is negative if the point is to the left
                   of the line segment that is closest to it) Note: if the point
                   is closest to an end point of the line segment list and
                   bExtendEndLineSegs is false, then the distance is a distance
                   to point (which is always positive)

  @param[in]       pSamplesX : Line segment point X coordintae array  [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
  @param[in]       pSamplesY : Line segment point Y coordintae array  [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @param[in]       NumSamples : Number of samples                     [0 ... 20]
  @param[in]       fPointX :    X coordinate of the point             [fDistance_t defined in Rte_Type.h] m
  @param[in]       fPointY :    Y coordinate of the point             [fDistance_t defined in Rte_Type.h] m
  @param[in]       bExtendEndLineSegs :                               [0 or 1]

  @glob_in         No global input variable used
  @glob_out        No global output variable used

  @c_switch_part   CAL_CFG_EXTEND_SAMPLE_END_LINE_SEGS        Static switch to enable extending point lists at both ends to infinite
                                                             distance. Note: this switch has to be on, so functions CAL_f_CalculatePoint2SamplesDist,
                                                             CPCalculatePoint2TraceDist etc. boolean parameter for extending end segments has any effect.

  @c_switch_full   FCT_CFG_COURSE_PREDICTION                 FCT configuration for course prediction.

  @pre             None
  @post            None

  @InOutCorrelation   None

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis). \n
                   Test of run time error/warnings (Static code analysis).

  @traceability    <a href="doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-505-0009fc80">CAL_505</a> \n

  @created         -
  @changed         3/24/2016

  @author          Gergely Ungvary
*************************************************************************************************************************/
fDistance_t CAL_f_CalculatePoint2LineSegCoordArr(const float32 * pSamplesX, const float32 * pSamplesY, uint8 NumSamples, fDistance_t fPointX, fDistance_t fPointY, boolean bExtendEndLineSegs)
{
  fDistance_t fSamplesDist;
  /* Initialize return value to infinite distance */
  fSamplesDist = CAL_INFINITE_DIST;
  /* If more then two samples are present, then these samples form a line-segment(s) */
  if (NumSamples > (uint8)0)
  {
    fDistance_t fSmallestAbsSqDist;
    fDistance_t fSmallestDistSign;
    fDistance_t fLastSamplePtSqDist;
    float32 fPrevSampleX = *pSamplesX;
    float32 fPrevSampleY = *pSamplesY;
    uint8 uRemainSegs;

    pSamplesX++;// PRQA S 0489 
   /* date: 2015-04-27, reviewer: Gangadhar Badiger, reason: Application wide deviation to rule agreed upon*/
    pSamplesY++;// PRQA S 0489 
   /* date: 2015-04-27, reviewer: Gangadhar Badiger, reason: Application wide deviation to rule agreed upon*/

    /* Initialize last sample square distance to distance to first sample */
    fLastSamplePtSqDist = (SQR(fPointX - fPrevSampleX) + SQR(fPointY - fPrevSampleY));

    /* Also set this as the minimum (initialization) */
    fSmallestAbsSqDist = fLastSamplePtSqDist;

    /* Also set sign of distance to positive (with a single point) we
    can only have positive signs, as no directions yet known */
    fSmallestDistSign = 1.0f;

    /* Loop through line segments. Loop runs (NumSamples-1) times */
    for (uRemainSegs=(uint8)(NumSamples-1u); uRemainSegs > (uint8)0; uRemainSegs--)
    {
      float32 fCurLineSegDistSq;

      /* Calculate delta X and delta Y between the sample points */
      const fDistance_t fSampleDX = (*pSamplesX - fPrevSampleX);
      const fDistance_t fSampleDY = (*pSamplesY - fPrevSampleY);
      /* Based on delta X & Y calculate squared distance of sample points */
      const float32 fSamplesSqDist = SQR(fSampleDX) + SQR(fSampleDY);
      /* Calculate current sample point square distance */
      const float32 fCurSamplePtSqDist = (SQR(fPointX - *pSamplesX) + SQR(fPointY - *pSamplesY));
      /* Verify that the samples are not the same (if they are, we can skip
      processing, since results from last line segment still apply */
      if (fSamplesSqDist > C_F32_DELTA)
      {
        /* Calculate cross product of line vector and vector from line segment
        starting point (previous sample) to the point */
        const float32 fCrossProd = ((fSampleDX * (fPrevSampleY - fPointY)) - (fSampleDY * (fPrevSampleX - fPointX)));
        /* Using the pythagoras theorem verify that the triangle between the previous
        sample, current sample and the point has angles smaller equal 90 degrees in
        the samples' corners */
        if (
          ((fSamplesSqDist + fLastSamplePtSqDist) >= fCurSamplePtSqDist)
#if (CAL_CFG_EXTEND_SAMPLE_END_LINE_SEGS)
          || ((bExtendEndLineSegs == TRUE) && (uRemainSegs == (uint8)(NumSamples-1u)))
#endif /* (CAL_CFG_EXTEND_SAMPLE_END_LINE_SEGS) */
          )
        {
          if (
            ((fSamplesSqDist + fCurSamplePtSqDist) >= fLastSamplePtSqDist)
#if (CAL_CFG_EXTEND_SAMPLE_END_LINE_SEGS)
            || ((bExtendEndLineSegs == TRUE) && (uRemainSegs == (uint8)1u))
#endif /* (CAL_CFG_EXTEND_SAMPLE_END_LINE_SEGS) */
            )
          {
            /* Both angles in the sample points are smaller 90 degrees,
            the distance to the line segment is the distance to the line.
            Based on the cross product we can calculate the square distance
            by dividing the cross products square with the length of the
            sample delta vector length's square */
            fCurLineSegDistSq = (SQR(fCrossProd)/fSamplesSqDist);
          }
          else
          {
            /* The angle in the current sample point is > 90 degrees,
            the distance to the line segment is the distance to the
            current sample point */
            fCurLineSegDistSq = fCurSamplePtSqDist;
          }
        }
        else
        {
          /* The angle in the last sample point is > 90 degrees,
          the distance to the line segment is the distance to the
          last sample point */
          fCurLineSegDistSq = fLastSamplePtSqDist;
        }
        /* Now check if the distance to the current line segment is
        smaller then the minimum found so far, if yes, store new
        minimum value NOTE: smaller equal used to catch the special
        case of when the first point is being processed: then if
        the end-point is the nearmost, then
        fCurLineSegDistSq == fSmallestAbsSqDist, but we do not yet
        know the sign, thus updated that now. */
        if (fCurLineSegDistSq <= fSmallestAbsSqDist)
        {
          fSmallestAbsSqDist = fCurLineSegDistSq;
          fSmallestDistSign  = ((fCrossProd >= 0.f)?1.f:-1.f);
        }
      }
      /* Store last data for next iteration */
      fPrevSampleX = *pSamplesX;
      pSamplesX++;// PRQA S 0489 
     /* date: 2015-04-27, reviewer: Gangadhar Badiger, reason: Application wide deviation to rule agreed upon*/
      fPrevSampleY = *pSamplesY;
      pSamplesY++;// PRQA S 0489 
     /* date: 2015-04-27, reviewer: Gangadhar Badiger, reason: Application wide deviation to rule agreed upon*/
      fLastSamplePtSqDist = fCurSamplePtSqDist;
    }

    /* When we reach this point, we know that fSmallesAbsSqDist is the
    square of the distance we are looking for, while fSmallestDistSign
    is the sign of it */
    fSamplesDist = (SQRT_(fSmallestAbsSqDist) * fSmallestDistSign);
  }
  
  return fSamplesDist;
}

/* ************************************************************************* */
/*   Copyright ADC-GmbH, Lindau                                              */
/* ************************************************************************* */
#endif /* (0) Unused functions */
#endif /* (FCT_CFG_ACC_CAL) */

