/*! \file **********************************************************************

  COMPANY:                   Continental AG, A.D.C. GmbH

  CPU:                       CPU-Independent

  COMPONENT:                 CML (Common Math Library)

  MODULNAME:                 cml_stat.c

  DESCRIPTION:               Statistics Library

  AUTHOR:                    N.Hanel / P.Dintzer

  CREATION DATE:             03.02.2010

  VERSION:                   $Revision: 1.23.1.3 $

  ---*/ /*---
  CHANGES:                   $Log: cml_stat.c  $
  CHANGES:                   Revision 1.23.1.3 2020/01/08 11:33:10CET Thomas, Jyothy (uid22555) 
  CHANGES:                   corrected alignment
  CHANGES:                   Revision 1.23.1.2 2019/11/11 11:42:11CET Thomas, Jyothy (uid22555) 
  CHANGES:                   CML_f_calcGaussErrorFunction is rewritten to have one computation per line. 
  CHANGES:                   This is to have ECU-SIL bitexactness on A15.
  CHANGES:                   Revision 1.23.1.1 2019/06/24 10:39:52CEST Kotre-EXT, Jeevan (uidk9586) 
  CHANGES:                   QAF level 3 warnings have been fixed.
  CHANGES:                   Revision 1.23 2018/02/26 08:52:40CET Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   Updated the source code with respect to AL_CML_01.09.18_INT-1
  CHANGES:                   Revision 1.22 2017/11/15 17:39:11CET Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   Replaced FALSE/TRUE by b_FALSE/b_TRUE
  CHANGES:                   Revision 1.21 2016/05/20 11:01:34CEST Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   - Updated function header with argument range
  CHANGES:                   Revision 1.21 2016/05/20 11:01:34CEST Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   - Updated function header with argument range
  CHANGES:                   Revision 1.21 2016/05/20 11:01:34CEST Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   - Updated function header with argument range
  CHANGES:                   Revision 1.20 2015/10/12 05:46:54CEST Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   - Fix for doxygen warning
  CHANGES:                   - Added comments -  uidr5428 [Oct 12, 2015 5:46:54 AM CEST]
  CHANGES:                   Change Package : 383331:1 http://mks-psad:7002/im/viewissue?selection=383331
  CHANGES:                   Revision 1.19 2015/10/02 16:10:13CEST Sauer, Stefan (uidg5644) 
  CHANGES:                   Clip minimum and maximum values in function CML_v_EncodeData_LSF_Quant to avoid floating point exception
  CHANGES:                   --- Added comments ---  uidg5644 [Oct 2, 2015 4:10:14 PM CEST]
  CHANGES:                   Change Package : 382619:1 http://mks-psad:7002/im/viewissue?selection=382619
  CHANGES:                   Revision 1.18 2015/08/25 12:10:28CEST Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   Updated doxygen compliant function headers
  CHANGES:                   --- Added comments ---  uidr5428 [Aug 25, 2015 12:10:28 PM CEST]
  CHANGES:                   Change Package : 360603:2 http://mks-psad:7002/im/viewissue?selection=360603
  CHANGES:                   Revision 1.17 2015/05/19 14:01:46CEST Sauer, Stefan (uidg5644) 
  CHANGES:                   - Added functions for quantized LSF
  CHANGES:                   --- Added comments ---  uidg5644 [May 19, 2015 2:01:47 PM CEST]
  CHANGES:                   Change Package : 334078:1 http://mks-psad:7002/im/viewissue?selection=334078
  CHANGES:                   Revision 1.16 2015/04/29 17:14:33CEST Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   - Changes with respect to Coding Guidelines
  CHANGES:                     of variables
  CHANGES:                   --- Added comments ---  uidr5428 [Apr 29, 2015 5:14:34 PM CEST]
  CHANGES:                   Change Package : 324617:3 http://mks-psad:7002/im/viewissue?selection=324617
  CHANGES:                   Revision 1.15 2014/12/12 13:33:43CET Schwarzkopf, Sebastian (uidg6516) 
  CHANGES:                   - added review ID to QA-C suppressions
  CHANGES:                   --- Added comments ---  uidg6516 [Dec 12, 2014 1:33:43 PM CET]
  CHANGES:                   Change Package : 266613:12 http://mks-psad:7002/im/viewissue?selection=266613
  CHANGES:                   Revision 1.14 2014/12/04 17:21:32CET Schwarzkopf, Sebastian (uidg6516) 
  CHANGES:                   - changed interface data of CML_f_CalcQuantile() from pointer to array as they're accessed that way
  CHANGES:                   --- Added comments ---  uidg6516 [Dec 4, 2014 5:21:32 PM CET]
  CHANGES:                   Change Package : 266613:11 http://mks-psad:7002/im/viewissue?selection=266613
  CHANGES:                   Revision 1.13 2014/10/22 09:46:58CEST Dintzer, Philippe (dintzerp) 
  CHANGES:                   - Prevent function from returning not initialised variables
  CHANGES:                   --- Added comments ---  dintzerp [Oct 22, 2014 9:46:59 AM CEST]
  CHANGES:                   Change Package : 273876:1 http://mks-psad:7002/im/viewissue?selection=273876
  CHANGES:                   Revision 1.12 2014/03/25 11:35:31CET Schwarzkopf, Sebastian (uidg6516) 
  CHANGES:                   - fixed Doxygen comments
  CHANGES:                   --- Added comments ---  uidg6516 [Mar 25, 2014 11:35:31 AM CET]
  CHANGES:                   Change Package : 227281:1 http://mks-psad:7002/im/viewissue?selection=227281
  CHANGES:                   Revision 1.11 2013/12/11 11:06:06CET Dintzer, Philippe (dintzerp) 
  CHANGES:                   - Replace computation of constant value with its value
  CHANGES:                   --- Added comments ---  dintzerp [Dec 11, 2013 11:06:06 AM CET]
  CHANGES:                   Change Package : 210483:1 http://mks-psad:7002/im/viewissue?selection=210483
  CHANGES:                   Revision 1.10 2013/10/15 10:01:25CEST Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   - add least squares fit with weight decay of old measurements
  CHANGES:                   --- Added comments ---  uidu0849 [Oct 15, 2013 10:01:26 AM CEST]
  CHANGES:                   Change Package : 191344:1 http://mks-psad:7002/im/viewissue?selection=191344
  CHANGES:                   Revision 1.9 2013/05/06 14:45:51CEST Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   - reduce Lint/Misra warnings
  CHANGES:                   --- Added comments ---  uidu0849 [May 6, 2013 2:45:51 PM CEST]
  CHANGES:                   Change Package : 159154:28 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.8 2013/05/03 09:57:45CEST Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   - drop algo_common from CML
  CHANGES:                   - use new standard type names, e.g. float32 instead of f32_t
  CHANGES:                   --- Added comments ---  uidu0849 [May 3, 2013 9:57:45 AM CEST]
  CHANGES:                   Change Package : 159154:27 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.7 2013/04/12 15:19:50CEST Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   - Add calculation of Gaussian quantiles
  CHANGES:                   --- Added comments ---  uidu0849 [Apr 12, 2013 3:19:50 PM CEST]
  CHANGES:                   Change Package : 159154:24 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.6 2013/04/09 12:58:55CEST Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   - Replace SQRT_ by CML_f_Sqrt
  CHANGES:                   --- Added comments ---  uidu0849 [Apr 9, 2013 12:58:55 PM CEST]
  CHANGES:                   Change Package : 159154:21 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.5 2013/02/22 09:32:22CET Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   - include prediction for least square fit
  CHANGES:                   --- Added comments ---  uidu0849 [Feb 22, 2013 9:32:22 AM CET]
  CHANGES:                   Change Package : 159154:16 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.4 2013/02/12 13:13:57CET Juengst, Markus (uidv8617) 
  CHANGES:                   - functions for linear approximation included
  CHANGES:                   --- Added comments ---  uidv8617 [Feb 12, 2013 1:13:57 PM CET]
  CHANGES:                   Change Package : 165907:1 http://mks-psad:7002/im/viewissue?selection=165907
  CHANGES:                   Revision 1.3 2012/12/20 16:38:45CET Diewald, Fabian (uidt8878) 
  CHANGES:                   added method for quantile calculation
  CHANGES:                   --- Added comments ---  uidt8878 [Dec 20, 2012 4:38:45 PM CET]
  CHANGES:                   Change Package : 158114:8 http://mks-psad:7002/im/viewissue?selection=158114
  CHANGES:                   Revision 1.2 2012/09/20 13:29:43CEST Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   - delete old log in file header
  CHANGES:                   --- Added comments ---  uidu0849 [Sep 20, 2012 1:29:43 PM CEST]
  CHANGES:                   Change Package : 159154:3 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.1 2012/09/14 14:31:17CEST Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/CML_CommonMathLibrary/04_Engineering/01_Source_Code/algo/cml/project.pj

**************************************************************************** */
/* PRQA S 0380 10 */
/* Deactivate QAF warning 0380, Date: 2019-06-17; Reviewer: uidk9586;  
   Reason: The warning is seen as number of macros exceeds 4095 which can not be avoided here. 
   Warning is analysed and no risk in suppressing this. */

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "cml_ext.h"

/*****************************************************************************
  LOCAL SYMBOLIC CONSTANTS
*****************************************************************************/
#define SQRT_OF_2 (1.414213562373095f) /* square root of 2 */

/*****************************************************************************
  FUNCTIONS
*****************************************************************************/

/*****************************************************************************
  Functionname:    CML_v_initWeightedSample                             */ /*!

  @brief           Initialisation of the weighted sample structure
                   
  @description     This function initializes all elements of the weighted
                   sample structure to zero.
                   
  @param[in]       p_sample : structure to be initialized
                              [Valid pointer to the structure]

  @return          void
                   
  @author          R. Ehrhardt

*****************************************************************************/
void CML_v_initWeightedSample(CML_t_WeightedSample *p_sample)
{
  p_sample->dSumme         = 0.0F;
  p_sample->dQuadSumme     = 0.0F;
  p_sample->f_sumOfWeights = 0.0F;
  p_sample->dMittel        = 0.0F;
  p_sample->dStdAbw        = 0.0F;
}

/*****************************************************************************
  Functionname:    CML_v_addSamplePoint                                 */ /*!

  @brief           Add a sample point to the weighted sample structure
                   
  @description     This function adds a sample point to the weighted sample 
                   structure

  @param[in,out]   p_sample : sample structure to which the new point is added
                              Supported values for p_sample.dSumme [Full range of float]
                              Supported values for p_sample.dQuadSumme [Full range of float]
                              Supported values for p_sample.f_sumOfWeights [Full range of float]
  @param[in]       f_value :  value of the new sample point
                              [Full range of float]
  @param[in]       f_weight : weight of the new sample point, must not be negative
                              [Full range of float]
                              Overflow may occur when one or more input values 
                              are at the defined range extremities.

  @return          none
                   
  @author          R. Ehrhardt

*****************************************************************************/
void CML_v_addSamplePoint(CML_t_WeightedSample *p_sample, float32 f_value, float32 f_weight)
{
  if (f_weight >= 0.f)
  {
    p_sample->dSumme         += f_value * f_weight;
    p_sample->dQuadSumme     += SQR(f_value) * f_weight;
    p_sample->f_sumOfWeights += f_weight;
  }
}

/*****************************************************************************
  Functionname:    CML_v_multiplySampleWithFactor                       */ /*!
  
  @brief           Multiplies the sample with a factor
                   
  @description     This function multiplies the weighted structure sample 
                   with a given factor
                   
  @param[in]       p_sample : sample structure
                              Supported values for p_sample.dSumme [Full range of float]
                              Supported values for p_sample.dQuadSumme [Full range of float]
                              Supported values for p_sample.f_sumOfWeights [Full range of float]
  @param[in]       f_factor : the factor to multiply the values and weights with, 
                              must NOT be negative
                              [Full positive range of float]

  @return          none
                   
  @author          R. Ehrhardt

*****************************************************************************/
void CML_v_multiplySampleWithFactor(CML_t_WeightedSample *p_sample, float32 f_factor)
{
  if (f_factor >= 0.f)
  {
    p_sample->dSumme         *= f_factor;
    p_sample->dQuadSumme     *= f_factor;
    p_sample->f_sumOfWeights *= f_factor;
  }
}

/*****************************************************************************
  Functionname:    CML_v_computeMeanStd                                 */ /*!

  @brief           Compute mean and standard deviation of the sample
                   
  @description     This function computes mean and standard deviation of 
                   the sample.
                   If S is the sum of weighted samples x1, x2, .., xn and N be  
                   the sum of weights of these samples, then mean,
                   M = S/N,
                   Now let QS be the sum of squares of weighted samples, then 
                   standard deviation,
                   SD = sqrt((QS/N) - (M))

  @param[in,out]   p_sample : structure for which mean and std should be 
                              computed
                              Supported values for p_sample.dSumme [Full range of float]
                              Supported values for p_sample.dQuadSumme [Full range of float]
                              Supported values for p_sample.f_sumOfWeights [Full range of float]

  @return          none
                   
  @author          R. Ehrhardt

*****************************************************************************/
void CML_v_computeMeanStd(CML_t_WeightedSample *p_sample)
{
  float32 f_dVarianz;

  if (p_sample->f_sumOfWeights > 0.0F)
  {
    p_sample->dMittel = p_sample->dSumme / p_sample->f_sumOfWeights;

    f_dVarianz = ( p_sample->dQuadSumme / p_sample->f_sumOfWeights ) - SQR( p_sample->dMittel );

    if (f_dVarianz > 0.F)
    {
      p_sample->dStdAbw = CML_f_Sqrt( f_dVarianz );
    }
    else
    {
      p_sample->dStdAbw = 0.0F;
    }
  }
  else
  {
    p_sample->dStdAbw    = 0.0F;
  }
}

/*****************************************************************************
  Functionname:    CML_f_calcGaussErrorFunction                         */ /*!

  @brief           Calculate the Gauss Error Function
                   
  @description     This function calculate the Gauss Error Function
                   Aproximate with a 4th order polynomial, the return value
                   G = ( ( ( (C4 * x^4) - (C3 * x^3) ) - (C2 * x^2) ) + (C1 * x) ) + C0,
                   where the coefficients C0, C1, C2, C3 and C4 are predefined 
                   values.
                   
  @param[in]       f_value : input to the Gauss error function
                             Supported values for f_value [-F_MAX...F_MAX]
                             where F_MAX is the fourth root of the maximum value of float32.

  @return          Gauss error function value
                   
  @author          Gicu Benchea
                   
*****************************************************************************/

float32 CML_f_calcGaussErrorFunction  ( float32 f_value )
{
  float32 f_temp2, f_temp3, f_temp, f_temp4;
  float32 f_temp5, f_temp6, f_temp7 , f_temp8, f_temp9;

  if ( f_value >= CML_f_GaussErrFctMaxX )
  {
    f_temp = 1.0f;
  }
  else
  {
    f_temp2 = f_value * f_value;   /* x^2 */
    f_temp3 = f_temp2 * f_value;   /* x^3 */
    f_temp4 = f_temp2 * f_temp2;   /* x^4 */
    f_temp5 = CML_f_GaussErrFctConst4 * f_temp4;
    f_temp6 = CML_f_GaussErrFctConst3 * f_temp3;
    f_temp7 = CML_f_GaussErrFctConst2 * f_temp2;
    f_temp8 = CML_f_GaussErrFctConst1 * f_value;
    f_temp9 = f_temp5 - f_temp6;
    f_temp2 = f_temp9 - f_temp7;
    f_temp3 = f_temp2 + f_temp8;
    f_temp = f_temp3 + CML_f_GaussErrFctConst0;
    f_temp = CML_f_Min(f_temp, 1.0f);
  }

  return f_temp;
}
/*****************************************************************************
  Functionname:    CML_f_calcStdGaussianCDF                             */ /*!

  @brief           Calculate the value of the standard Gaussian CDF
                   
  @description     This function calculate the value of the standard Gaussian
                   cumulative distribution function
                   CDF = 0.5 ( 1 + errorfunction ( ( x - aver ) / (sigma * sqrt(2) ) )
                   
  @param[in]       f_value : input to the CDF
                             [Full range of float]
  @param[in]       f_avg   : mean of the Gaussian distribution
                             [Full range of float]
  @param[in]       f_sigma : standard deviation of the Gaussian distribution
                             [Full range of float]

  @return          standard Gaussian CDF at the given value
                   
  @author          Gicu Benchea

*****************************************************************************/

float32 CML_f_calcStdGaussianCDF ( float32 f_value, float32 f_avg, float32 f_sigma )
{
  float32 f_temp;
  float32 f_temp1, f_temp2;

  if ( CML_f_Abs( f_sigma ) < CML_f_GaussianCDFMinSigma )
  {
    if ( f_value < f_avg )
    {
      f_temp = 0.0f;
    }
    else
    {
      f_temp = 1.0f;
    }
  }
  else
  { 
    f_temp1 =  f_value - f_avg;
    f_temp2 = f_sigma * SQRT_OF_2;

    /* <ln_offset:1 MISRA Rule 1.2: reviewer name: Daniel Meschenmoser date: 2013-05-03 reason: division by zero impossible due to if statement above */
    f_temp =  f_temp1 / f_temp2;

    /* check for negative values */
    if ( f_temp < 0.0f )
    {
      f_temp = - CML_f_calcGaussErrorFunction ( -f_temp );
    }
    else
    {
      f_temp = CML_f_calcGaussErrorFunction ( f_temp );
    }

    f_temp = CML_f_MultAdd(0.5f,f_temp,0.5f);
  }

  return f_temp;
}

/*****************************************************************************
  Functionname:    CML_f_calculateWeightedSum                             */ /*!

  @brief           Calculate the weighted sum of the given values
                   
  @description     This function calculate the weighted sum of the given values.
                   The values and the corresponding weights are expected as inputs.
                   Also the number of input values to be processed should be 
                   provided to the function. The values and their weights must be 
                   positive values. The function will return zero if sum of weights
                   provided computes to zero.
                   
  @param[in]       f_inputValues    : input values 
                                      [Positive range of float]
  @param[in]       f_weights        : weights of the input values
                                      [Positive range of float]
  @param[in]       u_numberOfValues : Number of input values
                                      [Full range of uint32]

  @return          Weighted Sum

  @author          Matthias Brendel / Nandu Arulkumar

*****************************************************************************/
float32 CML_f_calculateWeightedSum(const float32 f_inputValues[], const float32 f_weights[], const uint32 u_numberOfValues) 
{ 
  /*counter indexing the arrays*/ 
  uint32  u_counter; 
  /*variable to compute the value returned*/ 
  float32 f_weightedSum  = 0.0f; 
  /*the sum of the weights accumulated for normalization*/ 
  float32 f_sumofWeights = 0.0f; 
  /*variable to fetch one weight. it is used twice*/ 
  float32 f_thisWeight; 
  /*loop trough the arrays and accumulate the weighted sum*/ 
  float32 f_thisValue; 

  for(u_counter = 0; u_counter < u_numberOfValues; ++u_counter) 
  { 
    f_thisValue     = f_inputValues[u_counter]; 
    f_thisWeight    = f_weights[u_counter]; 
    f_sumofWeights += f_thisWeight; 
    if (f_thisValue > CML_f_AlmostZero) 
    { 
      f_weightedSum = CML_f_MultAdd(f_thisWeight,f_thisValue,f_weightedSum); 
      //f_weightedSum += f_thisWeight*f_thisValue; 
    } 
  }  
  if (f_sumofWeights > CML_f_AlmostZero) 
  { 
    f_weightedSum /= f_sumofWeights; 
  }
  else 
  { 
    f_weightedSum = 0.0f; 
  }  
  return f_weightedSum; 
}

/************************************************************************************/
/****************** Functions for linear Least Square Fit (LSF) *********************/


/*****************************************************************************

  Functionname:    CML_v_initLSF                                       */ /*!

  @brief           Initialize the LSF storage structure

  @description     This function initializes all the elements of the LSF
                   storage structure to zero 

  @param[in,out]   p_LSF : LSF storage structure
                           [Valid pointer to the structure]

  @return          void

  @author          nele.hanel@contiautomotive.com

****************************************************************************/
/* PRQA S 1257 10 */
/* Deactivate QAC warning 1257, Date: 2019-06-18; Reviewer: uidk9586;
   Reason: There is no risk as there is no loss of data or change of data in this conversion */
void CML_v_initLSF(CML_t_LeastSquareFit *const p_LSF)
{
  p_LSF->iData_Counter  = 0L;
  p_LSF->fsumX          = 0.0f;
  p_LSF->fsumV          = 0.0f;
  p_LSF->fsumXX         = 0.0f;
  p_LSF->fsumXV         = 0.0f;
  p_LSF->fsumVV         = 0.0f;
}

/*****************************************************************************

  Functionname:    CML_v_initResultsLSF                                */ /*!

  @brief           Initialize the LSF result structure

  @description     This function initializes all the elements of LSF result
                   structure to zero

  @param[in,out]   p_LSFRes : LSF result structure
                              [Valid pointer to the structure]

  @return          void

  @author          nele.hanel@contiautomotive.com

****************************************************************************/
void CML_v_initResultsLSF(CML_t_LeastSquareFitResults *const p_LSFRes)
{
  p_LSFRes->fSlope         = 0.0f;
  p_LSFRes->fCorrelation   = 0.0f;
  p_LSFRes->fYIntersection = 0.0f;
  p_LSFRes->fChi2_Error    = 0.0f;
  p_LSFRes->fmse           = 0.0f;
}



/*****************************************************************************

  Functionname:    CML_v_addDataLSF                                    */ /*!

  @brief           Add Datapair (x, v) to the LSF storage structure

  @description     This function adds a datapair defined by the given 
                   abscissae and ordinate to the LSF storage structure

  @param[in,out]   p_LSF :       LSF storage structure
                                 Supported values for p_LSF->fsumX [Full range of float32]
                                 Supported values for p_LSF->fsumV [Full range of float32]
                                 Supported values for p_LSF->fsumXX [Full range of float32]
                                 Supported values for p_LSF->fsumXV [Full range of float32]
                                 Supported values for p_LSF->fsumVV [Full range of float32]
                                 Supported values for p_LSF->iData_Counter [Full range of sint32]
  @param[in]       f_abscissae : abscissae of the datapair
                                 Supported values for f_value [-F_MAX...F_MAX]
  @param[in]       f_ordinate :  ordinate of the datapair
                                 Supported values for f_value [-F_MAX...F_MAX]
                                 where F_MAX is the square root of the maximum value of float32.
                                 Overflow may occur when one or more input values 
                                 are at the defined range extremities.

  @return          void

  @pre             -
  @post            -

  @todo            avoid overflow!

  @author          nele.hanel@contiautomotive.com

****************************************************************************/
void CML_v_addDataLSF(CML_t_LeastSquareFit *const p_LSF, const float32 f_abscissae, const float32 f_ordinate)
{
  p_LSF->fsumX        += f_abscissae;
  p_LSF->fsumV        += f_ordinate;
  p_LSF->fsumXX       = CML_f_MultAdd(f_abscissae, f_abscissae, p_LSF->fsumXX);
  p_LSF->fsumXV       = CML_f_MultAdd(f_abscissae, f_ordinate, p_LSF->fsumXV);
  p_LSF->fsumVV       = CML_f_MultAdd(f_ordinate, f_ordinate, p_LSF->fsumVV);
  p_LSF->iData_Counter++;
}


/*****************************************************************************

  Functionname:    CML_f_calculateSlopeLSF                             */ /*!

  @brief           Calculate Slope of the fitting line out of actual LSF 
                   storage structure

  @description     This function calculates the slope of the fitting line
                   out of actual LSF storage structure. The calulation 
                   requires at least two data points, otherwise the function 
                   will return a slope value of zero.

  @param[in]       p_LSF : LSF storage structure
                           Supported values for p_LSF->fsumX [Full range of float32]
                           Supported values for p_LSF->fsumV [Full range of float32]
                           Supported values for p_LSF->fsumXX [Full range of float32]
                           Supported values for p_LSF->fsumXV [Full range of float32]
                           Supported values for p_LSF->iData_Counter [Full range of sint32]
                           Overflow may occur when one or more input values 
                           are at the defined range extremities.

  @return          Slope value of the fitting line


  @author          nele.hanel@contiautomotive.com

****************************************************************************/
float32 CML_f_calculateSlopeLSF(CML_t_LeastSquareFit const *const p_LSF)
{
  float32 f_tempDenominator;
  float32 f_DataCounter;
  float32 f_Slope;

  /* you need minimal 2 Datapoints for calulation */
  if(p_LSF->iData_Counter >= 2L)
  {
    f_DataCounter = (float32) (p_LSF->iData_Counter);
    f_tempDenominator = (f_DataCounter * p_LSF->fsumXX) - (p_LSF->fsumX * p_LSF->fsumX);

    /* avoid Division by Zero */
    if (fABS(f_tempDenominator) < C_F32_DELTA)
    {
      f_Slope = 0.0f;
    }
    else
    {
      f_Slope = ((f_DataCounter * p_LSF->fsumXV) - (p_LSF->fsumX * p_LSF->fsumV)) / f_tempDenominator;
    }
  }
  else
  {
    f_Slope = 0.0f;
  }
 
  return f_Slope;
}



/*****************************************************************************

  Functionname:    CML_f_calculateCorrelationLSF                       */ /*!

  @brief           Calculate Correlation of the fitting line out of actual 
                   LSF storage structure

  @description     This function calculates the correlation of the fitting
                   line out of the actual LSF storage structure.The calulation 
                   requires at least two data points, otherwise the function 
                   will return a correlation value of zero.

  @param[in]       p_LSF : LSF storage structure
                           Supported values for p_LSF->fsumX [Full range of float32]
                           Supported values for p_LSF->fsumV [Full range of float32]
                           Supported values for p_LSF->fsumXX [Full range of float32]
                           Supported values for p_LSF->fsumVV [Full range of float32]
                           Supported values for p_LSF->fsumXV [Full range of float32]
                           Supported values for p_LSF->iData_Counter [Full range of sint32]
                           Overflow may occur when one or more input values 
                           are at the defined range extremities.

  @return          Correlation of the fitting line

  @author          nele.hanel@contiautomotive.com

****************************************************************************/
float32 CML_f_calculateCorrelationLSF(CML_t_LeastSquareFit const *const p_LSF)
{
  float32 f_tempNominator;
  float32 f_tempDenominatorX;
  float32 f_tempDenominatorV;
  float32 f_tempDenominatorXV;
  float32 f_DataCounter;
  float32 f_Correlation;

  /* you need minimal 2 Datapoints for calulation */
  if(p_LSF->iData_Counter >= (sint32)2)
  {
    f_DataCounter       = (float32) (p_LSF->iData_Counter);
    f_tempDenominatorX  = (f_DataCounter * p_LSF->fsumXX) - (p_LSF->fsumX * p_LSF->fsumX);
    f_tempDenominatorV  = (f_DataCounter * p_LSF->fsumVV) - (p_LSF->fsumV * p_LSF->fsumV);
    f_tempNominator     = (f_DataCounter * p_LSF->fsumXV) - (p_LSF->fsumX * p_LSF->fsumV);
    f_tempDenominatorXV = f_tempDenominatorX * f_tempDenominatorV;

    /* avoid Division by Zero */
    if ( f_tempDenominatorXV < C_F32_DELTA )
    {
      f_Correlation = 0.0f;
    }
    else
    {
      f_Correlation = f_tempNominator / CML_f_Sqrt(f_tempDenominatorXV);
    }
  }
  else
  {
    f_Correlation = 0.0f;
  }

  return f_Correlation;
}



/*****************************************************************************

  Functionname:    CML_f_calculateYIntersectionLSF                     */ /*!

  @brief           Calculate Point of Intersection with Y-Axis of the fitting
                   line out of actual LSF storage structure

  @description     This function calculates the point of intersection with
                   Y-axis of the fitting line out of the actual LSF storage
                   structure.The calulation requires at least two data points,
                   otherwise the function will return a Y-intersection value of 
                   zero.

  @param[in]       p_LSF : LSF storage structure
                           Supported values for p_LSF->fsumX [Full range of float32]
                           Supported values for p_LSF->fsumV [Full range of float32]
                           Supported values for p_LSF->fsumXX [Full range of float32]
                           Supported values for p_LSF->fsumVV [Full range of float32]
                           Supported values for p_LSF->fsumXV [Full range of float32]
                           Supported values for p_LSF->iData_Counter [Full range of sint32]
                           Overflow may occur when one or more input values 
                           are at the defined range extremities.

  @return          Point of Intersection with Y-Axis of the fitting line

  @pre             -
  @post            -

  @author          nele.hanel@contiautomotive.com

****************************************************************************/
float32 CML_f_calculateYIntersectionLSF(CML_t_LeastSquareFit const *const p_LSF)
{
  float32 f_tempDenominator;
  float32 f_DataCounter;
  float32 f_YIntersection;

  /* you need minimal 2 Datapoints for calulation */
  if(p_LSF->iData_Counter >= 2L)
  {
    f_DataCounter = (float32) (p_LSF->iData_Counter);
    f_tempDenominator = (f_DataCounter * p_LSF->fsumXX) - (p_LSF->fsumX * p_LSF->fsumX);

    /* avoid Division by Zero */
    if (fABS(f_tempDenominator) < C_F32_DELTA)
    {
      f_YIntersection = 0.0f;
    }
    else
    {
      f_YIntersection = ((p_LSF->fsumV * p_LSF->fsumXX) - (p_LSF->fsumX * p_LSF->fsumXV)) / f_tempDenominator;
    }
  }
  else
  {
    f_YIntersection = 0.0f;
  }

  return f_YIntersection;
}


/*****************************************************************************

  Functionname:    CML_f_calculateSquareErrorLSF                       */ /*!

  @brief           Calculate Least Squared Error of the fitting line out of
                   actual LSF storage structure

  @description     This function calulates the least squared error of the 
                   fitting line out of the actual LSF storage structure.

                   chi^2 = sum_{i=1}^n ( v_i - slope * x_i - YIntersection )^2. 
                   This is not calculated directly, but instead
                   chi^2 = (1-correlation^2)*NVarV  (with NVarV = sumVV - sumV*sumV/n)

                   The calulation requires at least two data points,
                   otherwise the function will return a least squared error
                   value of zero.

  @param[in]       p_LSF : LSF storage structure
                           Supported values for p_LSF->fsumV [Full range of float32]
                           Supported values for p_LSF->fsumVV [Full range of float32]
                           Supported values for p_LSF->iData_Counter [Full range of sint32]
                           Overflow may occur when one or more input values 
                           are at the defined range extremities.
  @param[in]       f_LSFCorrelation : Correlation of the fitting line
                                      Supported values [Full range of sint32]

  @return          Least Squared Error of the fitting line

  @pre             Calculate actual Correlation!
  @post            -

  @author          nele.hanel@contiautomotive.com

****************************************************************************/
float32 CML_f_calculateSquareErrorLSF(CML_t_LeastSquareFit const *const p_LSF, const float32 f_LSFCorrelation)
{
  float32 f_tempNVarV;
  float32 f_DataCounter;
  float32 f_Chi2_Error;

  /* you need minimal 2 Datapoints for calulation */
  if(p_LSF->iData_Counter >= 2L)
  {
    f_DataCounter = (float32) (p_LSF->iData_Counter);

    f_tempNVarV  = p_LSF->fsumVV - ((p_LSF->fsumV * p_LSF->fsumV)/f_DataCounter); 

    f_Chi2_Error = (1.f - (f_LSFCorrelation * f_LSFCorrelation)) * f_tempNVarV;
  }
  else
  {
    f_Chi2_Error = 0.0f;
  }

  return f_Chi2_Error;
}


/*****************************************************************************

  Functionname:    CML_f_calculateMeanSquareErrorLSF                   */ /*!

  @brief           Calculate the Mean Square Error of the fitting line out of
                   actual LSF storage structure

  @description     This function calcuates the mean square error of the fitting
                   line out out of the actual LSF storage structure.
                   The calulation requires at least two data points,
                   otherwise the function will return a mean square error
                   value of zero.

  @param[in]       p_LSF : LSF storage structure
                           Supported values for p_LSF->fsumV [Full range of float32]
                           Supported values for p_LSF->fsumVV [Full range of float32]
                           Supported values for p_LSF->iData_Counter [Full range of sint32]
                           Overflow may occur when one or more input values 
                           are at the defined range extremities.
  @param[in]       f_LSFCorrelation : Correlation of the fitting line
                                      Supported values [Full range of sint32]

  @return          Mean Square Error of actual LSF-Structure

  @pre             Calculate actual Correlation!
  @post            -

  @author          philippe.dintzer@contiautomotive.com

****************************************************************************/
float32 CML_f_calculateMeanSquareErrorLSF(CML_t_LeastSquareFit const *const p_LSF, const float32 f_LSFCorrelation)
{
  float32 f_Chi2_Error;
  float32 f_mse;

  if(p_LSF->iData_Counter >= 2L) /* you need minimal 2 Datapoints for calulation */
  {
    f_Chi2_Error = CML_f_calculateSquareErrorLSF(p_LSF, f_LSFCorrelation);

    f_mse = f_Chi2_Error / ((float32)p_LSF->iData_Counter);
  }
  else
  {
    f_mse = 0.0f;
  }

  return f_mse;
}

/*****************************************************************************

  Functionname:    CML_v_calculateQualityLSF                           */ /*!

  @brief           Calculate Quality of the fitting line out of actual
                   LSF storage structure

  @description     This function calculate properties describing the Quality 
                   of the fitting line based on the actual LSF storage structure:
                     - Correlation
                     - Mean Square Error
                   
                   The calulation requires at least two data points,
                   otherwise the function will set mean square error
                   and correlation values of zero.

  @param[in]       p_LSF : LSF storage structure
                           Supported values for p_LSF->fsumX [Full range of float32]
                           Supported values for p_LSF->fsumV [Full range of float32]
                           Supported values for p_LSF->fsumXX [Full range of float32]
                           Supported values for p_LSF->fsumVV [Full range of float32]
                           Supported values for p_LSF->fsumXV [Full range of float32]
                           Supported values for p_LSF->iData_Counter [Full range of sint32]
                           Overflow may occur when one or more input values 
                           are at the defined range extremities.
  @param[out]      f_LSFCorrelation : Correlation of the fitting line
                                      [Full range of float32]
  @param[out]      f_LSFmse : Mean Square Error of the fitting line
                              [Full range of float32]

  @return          void

  @pre             -
  @post            -

  @author          philippe.dintzer@contiautomotive.com

****************************************************************************/
void CML_v_calculateQualityLSF(CML_t_LeastSquareFit const *const p_LSF, float32 *const f_LSFCorrelation, float32 *const f_LSFmse)
{
  float32 f_tempNominator;
  float32 f_tempDenominatorX;
  float32 f_tempDenominatorV;
  float32 f_tempDenominatorXV;
  float32 f_temp;
  float32 f_DataCounter;

  if(p_LSF->iData_Counter >= 2L) /* you need minimal 2 Datapoints for calulation */
  {
    f_DataCounter = (float32) (p_LSF->iData_Counter);
    f_tempDenominatorX   = (f_DataCounter * p_LSF->fsumXX) - (p_LSF->fsumX * p_LSF->fsumX);
    f_tempDenominatorV   = (f_DataCounter * p_LSF->fsumVV) - (p_LSF->fsumV * p_LSF->fsumV);
    f_tempNominator      = (f_DataCounter * p_LSF->fsumXV) - (p_LSF->fsumX * p_LSF->fsumV);
    f_tempDenominatorXV  = f_tempDenominatorX * f_tempDenominatorV;
    f_temp               = f_tempDenominatorV / (f_DataCounter*f_DataCounter);

    /* avoid Division by Zero */
    if ( f_tempDenominatorXV < C_F32_DELTA )
    {
      *f_LSFCorrelation = 0.0f;
      *f_LSFmse = f_temp;
    }
    else
    {
      /* calculate Correlation */
      *f_LSFCorrelation = f_tempNominator / CML_f_Sqrt(f_tempDenominatorXV);
      /* calculate mean square error */
      *f_LSFmse = (1.f - ( (*f_LSFCorrelation) * (*f_LSFCorrelation))) * f_temp;
    }
  }
  else
  {
    *f_LSFCorrelation = 0.0f;
    *f_LSFmse = 0.0f;
  }
}



/*****************************************************************************

  Functionname:    CML_v_calculateAllLSF                               */ /*!

  @brief           Calculate Fitting results of the fitting line out of actual
                   LSF storage structure

  @description     This function calculate all properties of the fitting line 
                   based on the actual LSF storage structure:
                     - Slope
                     - Y-Intersection
                     - Correlation
                     - Square Error
                     - Mean Square Error
                   The calulation requires at least two data points,
                   otherwise no calculation is done.

  @param[in]       p_LSF : LSF storage structure
                           Supported values for p_LSF->fsumX [Full range of float32]
                           Supported values for p_LSF->fsumV [Full range of float32]
                           Supported values for p_LSF->fsumXX [Full range of float32]
                           Supported values for p_LSF->fsumVV [Full range of float32]
                           Supported values for p_LSF->fsumXV [Full range of float32]
                           Supported values for p_LSF->iData_Counter [Full range of sint32]
                           Overflow may occur when one or more input values 
                           are at the defined range extremities.
  @param[out]      p_LSFRes : LSF result structure

  @return          void

  @pre             -
  @post            -

  @author          nele.hanel@contiautomotive.com

****************************************************************************/
void CML_v_calculateAllLSF(CML_t_LeastSquareFit const *const p_LSF, CML_t_LeastSquareFitResults *const p_LSFRes)
{
  float32 f_tempNominator;
  float32 f_tempDenominatorX;
  float32 f_tempDenominatorV;
  float32 f_tempDenominatorXV;
  float32 f_tempNVarV;
  float32 f_DataCounter;

  if(p_LSF->iData_Counter >= 2L) /* you need minimal 2 Datapoints for calulation */
  {
    f_DataCounter = (float32) (p_LSF->iData_Counter);
    f_tempDenominatorX   = (f_DataCounter * p_LSF->fsumXX) - (p_LSF->fsumX * p_LSF->fsumX);
    f_tempDenominatorV   = (f_DataCounter * p_LSF->fsumVV) - (p_LSF->fsumV * p_LSF->fsumV);
    f_tempNominator      = (f_DataCounter * p_LSF->fsumXV) - (p_LSF->fsumX * p_LSF->fsumV);
    f_tempDenominatorXV  = f_tempDenominatorX * f_tempDenominatorV;
    f_tempNVarV          = f_tempDenominatorV / f_DataCounter; /*LSF->fsumVV - (LSF->fsumV * LSF->fsumV)/fData_Counter*/

    /* avoid Division by Zero */
    if ( f_tempDenominatorXV < C_F32_DELTA )
    {
      p_LSFRes->fCorrelation = 0.0f;
      p_LSFRes->fChi2_Error  = f_tempNVarV;
    }
    else
    {
      /* calculate Correlation */
      p_LSFRes->fCorrelation = f_tempNominator / CML_f_Sqrt(f_tempDenominatorXV);
      /* calculate chi^2 */
      p_LSFRes->fChi2_Error = (1.f - (p_LSFRes->fCorrelation * p_LSFRes->fCorrelation)) * f_tempNVarV;
    }

    /* calculate Slope, YIntersection */
    /* avoid Division by Zero */
    if (fABS(f_tempDenominatorX) < C_F32_DELTA)
    {
      p_LSFRes->fSlope         = 0.0f;
      p_LSFRes->fYIntersection = 0.0f;
    }
    else
    {
      p_LSFRes->fSlope         = ((f_DataCounter * p_LSF->fsumXV) - (p_LSF->fsumX * p_LSF->fsumV)) / f_tempDenominatorX;
      p_LSFRes->fYIntersection = ((p_LSF->fsumV * p_LSF->fsumXX) - (p_LSF->fsumX * p_LSF->fsumXV)) / f_tempDenominatorX;
    }

    /* calculate mean square error */
    p_LSFRes->fmse = p_LSFRes->fChi2_Error / f_DataCounter;
  }
}


/*****************************************************************************

  Functionname:    CML_f_predictLSF                                    */ /*!

  @brief           Predict y-value on least square fit for given x-value

  @description     This function predict y-value on least square fit for 
                   given x-value.The calculation is done using basic eqaution 
                   for line,
                   y = mx + c, 
                   where,
                   m = slope
                   c = Y intersection 

  @param[in]       f_xValue : x-value for which y-value to be determined
                              Supported values [Full range of float32]
  @param[in,out]   p_LSFResults : LSF result structure
                                  Supported values for p_LSFResults->fSlope [Full range of float32]
                                  Supported values for p_LSFResults->fYIntersection [Full range of float32]
                                  Overflow may occur when one or more input values 
                                  are at the defined range extremities.
  @return          y-value on least square fit for given x-value

  @author          D. Meschenmoser

****************************************************************************/
float32 CML_f_predictLSF(CML_t_LeastSquareFitResults const *const p_LSFResults, float32 f_xValue)
{
  return CML_f_MultAdd(f_xValue,p_LSFResults->fSlope,p_LSFResults->fYIntersection);
}


/*****************************************************************************

  Functionname:    CML_v_initLSFForgetExponential                     */ /*!

  @brief           Init the LSF storage structure with exponential forget

  @description     This function initializes all the elements of LSF storage 
                   structure with exponential forget to zero.

  @param[in,out]   p_LSF : LSF storage structure with exponential forget
                           [Valid pointer to the structure]

  @return          void

  @pre             -
  @post            -

  @author          martin.warnecke@continental-corporation.com

****************************************************************************/
void CML_v_initLSFForgetExponential(t_LeastSquareFit_ForgetExponential *const p_LSF)
{
  p_LSF->fData_Counter  = 0.0f;
  p_LSF->fsumX          = 0.0f;
  p_LSF->fsumV          = 0.0f;
  p_LSF->fsumXX         = 0.0f;
  p_LSF->fsumXV         = 0.0f;
  p_LSF->fsumVV         = 0.0f;
}


/***********************************************************************
  Functionname:    CML_v_addDataLSFForgetExponential             */ /*!

  @brief           Add data pair (x, v) to the LSF storage structure
                   with exponential forget

  @description     This function adds a data pair (f_abscissa, f_ordinate) 
                   to the LSF storage structure with exponential forget

  @param[in,out]   p_LSF  : LSF storage structure with exponential forget
                            Supported values for p_LSF->fsumX [Full range of float32]
                            Supported values for p_LSF->fsumV [Full range of float32]
                            Supported values for p_LSF->fsumXX [Full range of float32]
                            Supported values for p_LSF->fsumVV [Full range of float32]
                            Supported values for p_LSF->fsumXV [Full range of float32]
                            Supported values for p_LSF-fData_Counter [Full range of float32]
                            Overflow may occur when one or more input values 
                            are at the defined range extremities.
  @param[in]       f_abscissa  : abscissa of the data pair
                                 Supported values [Full range of float32]
  @param[in]       f_ordinate  : ordinate of the data pair
                                 Supported values [Full range of float32]
  @param[in]       f_MemoryWeight : Supported values [Full range of float32]

  @return          void

  @author          martin.warnecke@continental-corporation.com
************************************************************************/

void CML_v_addDataLSFForgetExponential(t_LeastSquareFit_ForgetExponential *const p_LSF, const float32 f_abscissa, const float32 f_ordinate, const float32 f_MemoryWeight)
{
  p_LSF->fsumX         *= f_MemoryWeight;
  p_LSF->fsumV         *= f_MemoryWeight;
  p_LSF->fsumXX        *= f_MemoryWeight;
  p_LSF->fsumXV        *= f_MemoryWeight;
  p_LSF->fsumVV        *= f_MemoryWeight;
  p_LSF->fData_Counter *= f_MemoryWeight;

  p_LSF->fsumX  += f_abscissa;
  p_LSF->fsumV  += f_ordinate;
  p_LSF->fsumXX += (f_abscissa*f_abscissa);
  p_LSF->fsumXV += (f_abscissa*f_ordinate);
  p_LSF->fsumVV += (f_ordinate*f_ordinate);
  p_LSF->fData_Counter++;
}


/*****************************************************************************

  Functionname:    CML_v_calculateAllLSFForgetExponential             */ /*!

  @brief           Calculate Fitting results of the fitting line out of actual
                   LSF storage structure with exponential forget

  @description     This function calculate all properties of the fitting line 
                   based on the actual LSF storage structure with exponential forget:
                     - Slope
                     - Y-Intersection
                     - Correlation
                     - Square Error
                     - Mean Square Error
                   The calulation requires at least two data points,
                   otherwise no calculation is done.

  @param[in]       p_LSF : LSF storage structure with exponential forget
                           Supported values for p_LSF->fsumX [Full range of float32]
                           Supported values for p_LSF->fsumV [Full range of float32]
                           Supported values for p_LSF->fsumXX [Full range of float32]
                           Supported values for p_LSF->fsumVV [Full range of float32]
                           Supported values for p_LSF->fsumXV [Full range of float32]
                           Supported values for p_LSF-fData_Counter [Full range of float32]
                           Overflow may occur when one or more input values 
                           are at the defined range extremities.
  @param[out]      p_LSFRes : LSF result structure

  @return          -

  @pre             -
  @post            -

  @author          martin.warnecke@continental-corporation.com

****************************************************************************/
void CML_v_calculateAllLSFForgetExponential(t_LeastSquareFit_ForgetExponential const *const p_LSF, CML_t_LeastSquareFitResults *const p_LSFRes)
{
  float32 f_tempNominator;
  float32 f_tempDenominatorX;
  float32 f_tempDenominatorV;
  float32 f_tempDenominatorXV;
  float32 f_tempNVarV;
  float32 f_DataCounter;

  if(p_LSF->fData_Counter > 1.f) /* you need minimal 2 data points for calculation */
  {
    f_DataCounter = (float32) (p_LSF->fData_Counter);
    f_tempDenominatorX   = (f_DataCounter * p_LSF->fsumXX) - (p_LSF->fsumX * p_LSF->fsumX);
    f_tempDenominatorV   = (f_DataCounter * p_LSF->fsumVV) - (p_LSF->fsumV * p_LSF->fsumV);
    f_tempNominator      = (f_DataCounter * p_LSF->fsumXV) - (p_LSF->fsumX * p_LSF->fsumV);
    f_tempDenominatorXV  = f_tempDenominatorX * f_tempDenominatorV;
    f_tempNVarV          = f_tempDenominatorV / f_DataCounter;

    /* avoid Division by Zero */
    if ( f_tempDenominatorXV < C_F32_DELTA )
    {
      p_LSFRes->fCorrelation = 0.0f;
      p_LSFRes->fChi2_Error  = f_tempNVarV;
    }
    else
    {
      /* calculate Correlation */
      p_LSFRes->fCorrelation = f_tempNominator / CML_f_Sqrt(f_tempDenominatorXV);
      /* calculate chi^2 */
      p_LSFRes->fChi2_Error = (1.f - (p_LSFRes->fCorrelation * p_LSFRes->fCorrelation)) * f_tempNVarV;
    }

    /* calculate Slope, YIntersection */
    /* avoid Division by Zero */
    if (fABS(f_tempDenominatorX) < C_F32_DELTA)
    {
      p_LSFRes->fSlope         = 0.0f;
      p_LSFRes->fYIntersection = 0.0f;
    }
    else
    {
      p_LSFRes->fSlope         = ((f_DataCounter * p_LSF->fsumXV) - (p_LSF->fsumX * p_LSF->fsumV)) / f_tempDenominatorX;
      p_LSFRes->fYIntersection = ((p_LSF->fsumV * p_LSF->fsumXX) - (p_LSF->fsumX * p_LSF->fsumXV)) / f_tempDenominatorX;
    }

    /* calculate mean square error */
    p_LSFRes->fmse = p_LSFRes->fChi2_Error / f_DataCounter;
  }
}


/*****************************************************************************
  Functionname:    CML_f_calcQuantile                                   */ /*!

  @brief           Calculates a quantile using the fast quick select algorithm
                   
  @description     This function calculates the quantile defined by the given 
                   position. 
                   For example, if requested for 3rd smallest element
                   in an array, then the function partly sorts the array, finds out
                   the 3rd smallest element and returns this value.
                   
  @param[in,out]   a_valuesDestroyed : pointer onto values from which quantile 
                   should be calculated, 
                   NOTE: array is PARTLY sorted, so if values are needed later, 
                   copy before!
                   Supported values for a_valuesDestroyed[] [Full range of float32]
  @param[in]       u_NofValues : number of values in a_valuesDestroyed
                                 Supported values [Full range of uint32]
  @param[in]       u_NthSmallest: sorted list index of element to be returned, 
                   i.e. 0u for the smallest element, uNofValues-1u for the maximum, 
                   uNofValues/2u for the median
                   Supported values [Full range of uint32]
                   
  @return          quantile
                   
  @author          fabian.diewald@continental-corporation.com
  
*****************************************************************************/
float32 CML_f_calcQuantile(float32 a_valuesDestroyed[], const uint32 u_NofValues, const uint32 u_NthSmallest)
{
  float32   f_Pivot;

  uint32  u_Left   = 0u,
          u_Right  = u_NofValues - 1u,
          u_Pos    = u_NthSmallest+1u,
          u_Ind;

  while ((u_Left < u_Right) && (u_Pos != u_NthSmallest))
  {
    float32 f_Temp;
    f_Pivot = a_valuesDestroyed[u_NthSmallest];
    
    /* swap */
    f_Temp = a_valuesDestroyed[u_NthSmallest];
    a_valuesDestroyed[u_NthSmallest] = a_valuesDestroyed[u_Right];
    a_valuesDestroyed[u_Right] = f_Temp;
    u_Pos = u_Left;

    for (u_Ind = u_Pos; u_Ind < u_Right; u_Ind++)
    {
      if (a_valuesDestroyed[u_Ind] < f_Pivot)
      {
        /* swap */
        f_Temp = a_valuesDestroyed[u_Ind];
        a_valuesDestroyed[u_Ind] = a_valuesDestroyed[u_Pos];
        a_valuesDestroyed[u_Pos] = f_Temp;
        u_Pos++;
      }
    }
    /* swap */
    f_Temp = a_valuesDestroyed[u_Right];
    a_valuesDestroyed[u_Right] = a_valuesDestroyed[u_Pos];
    a_valuesDestroyed[u_Pos] = f_Temp;

    if (u_Pos < u_NthSmallest)
    {
      u_Left = u_Pos + 1u;
    }
    else if (u_Pos > u_NthSmallest)
    {
      /* Deactivate QA-C warning 3382; Reviewer: S. Schwarzkopf; 
         Date: 04.12.2014; Reason: As uPos > uNthSmallest to get here, a 
         wraparound will never happen by subtracting 1.
         Review-ID: 3942463 */
      /* PRQA S 3382 1 */
      u_Right = u_Pos - 1u;
    }
    else
    {
      /* do nothing */
    }
  }
  return a_valuesDestroyed[u_NthSmallest];
}


/*****************************************************************************
  Functionname:    CML_f_stdGaussQuantile                               */ /*!

  @brief           Calculates a quantile of the standard Gaussian distribution N(0,1)
                   
  @description     Calculates a quantile of the standard Gaussian distribution N(0,1)
                   by the Beasly-Springer approach, i.e. using a rational
                   approximation of order (3,4)
                   
  @param[in]       f_Prob: the probability for which the quantile should be calculated
                           Supported values are float values in the range [0,..,1]
                   
  @return          the standard Gaussian quantile for the given probability
                   
  @author          daniel.meschenmoser@continental-corporation.com

*****************************************************************************/
float32 CML_f_stdGaussQuantile(float32 f_Prob)
{
  const float32 f_ProbShifted = f_Prob - 0.5f;
  const float32 f_AbsProbShifted = CML_f_Abs(f_ProbShifted);
  const float32 f_ProbShifted2 = f_ProbShifted * f_ProbShifted;
  float32 f_Tmp;
  float32 f_Ret;

  /* use Beasley-Springer approach in [0.08 ; 0.92], outside use simplified linear approximation */
  if (f_AbsProbShifted < CML_f_GaussQuantile_lowerBound)
  {
    f_Ret = f_ProbShifted * 
      ( ( ( ( ( ( (CML_f_GaussQuantile_a3 * f_ProbShifted2) + CML_f_GaussQuantile_a2) * f_ProbShifted2) + CML_f_GaussQuantile_a1) * f_ProbShifted2) + CML_f_GaussQuantile_a0) /
      ( ( ( ( ( ( ( (CML_f_GaussQuantile_b4 * f_ProbShifted2) + CML_f_GaussQuantile_b3) * f_ProbShifted2) + CML_f_GaussQuantile_b2) * f_ProbShifted2) + CML_f_GaussQuantile_b1) * f_ProbShifted2) + CML_f_GaussQuantile_b0) );
  }
  else if (f_AbsProbShifted < CML_f_GaussQuantile_sigma2Bound) /* linear approx to 2 sigma*/
  {
    f_Tmp = (f_AbsProbShifted - CML_f_GaussQuantile_lowerBound) / (CML_f_GaussQuantile_sigma2Bound - CML_f_GaussQuantile_lowerBound);
    f_Ret = (f_Tmp * (CML_f_GaussQuantile_sigma2Value - CML_f_GaussQuantile_lowerValue) ) + CML_f_GaussQuantile_lowerValue;
    if (f_ProbShifted < 0.0f)
    {
      f_Ret = -f_Ret;
    }
  } 
  else if (f_AbsProbShifted < CML_f_GaussQuantile_sigma3Bound) /* linear approx to 3 sigma*/
  {
    f_Tmp = (f_AbsProbShifted - CML_f_GaussQuantile_sigma2Bound) / (CML_f_GaussQuantile_sigma3Bound - CML_f_GaussQuantile_sigma2Bound);
    f_Ret = (f_Tmp * (CML_f_GaussQuantile_sigma3Value - CML_f_GaussQuantile_sigma2Value) ) + CML_f_GaussQuantile_sigma2Value;
    if (f_ProbShifted < 0.0f)
    {
      f_Ret = -f_Ret;
    }
  }
  else /* set to 4 sigma*/
  {
    f_Ret = (f_ProbShifted < 0.0f) ? (-CML_f_GaussQuantile_highValue) : CML_f_GaussQuantile_highValue;
  }

  return f_Ret;
}


/*****************************************************************************
  Functionname:    CML_f_gaussQuantile                                  */ /*!

  @brief           Calculates a quantile of a Gaussian distribution
                   
  @description     This function calculates a quantile of a Gaussian 
                   distribution.
                   
  @param[in]       f_Mean: mean value of the Gaussian distribution
                           Supported values [Full range of float32]
  @param[in]       f_Std:  standard deviation of the Gaussian distribution
                           Supported values [Full range of float32]
  @param[in]       f_Prob: the probability for which the quantile should be calculated
                           Supported values [Full range of float32]
                           Overflow may occur when one or more input values 
                           are at the defined range extremities.
                   
  @return          the Gaussian quantile for the given probability
                   
  @author          daniel.meschenmoser@continental-corporation.com

*****************************************************************************/
float32 CML_f_gaussQuantile(float32 f_Mean, float32 f_Std, float32 f_Prob)
{
  return CML_f_MultAdd(f_Std,CML_f_stdGaussQuantile(f_Prob),f_Mean);
}

/*****************************************************************************

  Functionname:    CML_v_initLSFQuant                                 */ /*!

  @brief           Init the LSF storage structure for quantized LSF

  @description     Initialize the LSF storage structure for quantized 
                   (compressed) LSF. All the elements are set to Zero.
                   The abscissa variable is assumed to take non-negative values,
                   the ordinate variable can also take negative values.

  @param[in,out]   p_LSFQuant : LSF storage structure for quantized LSF
                                [Valid pointer to the structure]

  @return          void

  @pre             -
  @post            -

  @author          stefan.sauer@continental-corporation.com

****************************************************************************/
void CML_v_initLSFQuant(CML_t_LeastSquareFitQuant *const p_LSFQuant)
{
  p_LSFQuant->u_Data_Counter  = 0u;
  p_LSFQuant->u_sumX          = 0u;
  p_LSFQuant->s_sumV          = 0;
  p_LSFQuant->u_sumXX         = 0u;
  p_LSFQuant->s_sumXV         = 0;
  p_LSFQuant->u_sumVV         = 0u;
}

/*****************************************************************************
  
  Functionname:    CML_v_decodeDataLSFQuant                           */ /*!

  @brief           Decode the quantized LSF data to reconstructed
                   floating point LSF data
  
  @description     Inverse quantization (reconstruction) stage:
                   Decode the quantized LSF data p_LSFQuant to reconstructed
                   floating point LSF data p_LSFNonQuant using the
                   decoding factors f_decodeX and f_decodeV for the abscissa
                   and ordinate, respectively.

  @attention       Make sure that (p_LSFQuant->u_Data_Counter < (uint16)CML_u_UNSIGNED_16BIT_QUANT_SIZE)
                   if subsequently a new datapair (x_i,v_i) should be added to the statistics

  @param[in]       p_LSFQuant    : LSF storage structure for quantized LSF
                                   Supported values for p_LSFQuant->u_sumX [Full range of uint16]
                                   Supported values for p_LSFQuant->s_sumV [Full range of sint16]
                                   Supported values for p_LSFQuant->u_sumXX [Full range of uint16]
                                   Supported values for p_LSFQuant->s_sumXV [Full range of sint16]
                                   Supported values for p_LSFQuant->u_sumVV [Full range of uint16]
                                   Supported values for p_LSFQuant->u_Data_Counter [Full range of uint16]
                                   Overflow may occur when one or more input values 
                                   are at the defined range extremities.
  @param[in]       f_decodeX     : decoding factor for abscissa of the datapair
                                   [Full range of float32]
  @param[in]       f_decodeV     : decoding factor for ordinate of the datapair
                                   [Full range of float32]
  @param[out]      p_LSFNonQuant : LSF storage structure for reconstructed LSF
                                   [Valid pointer to the structure]

  @return          void

  @pre             Make sure that (p_LSFQuant->u_Data_Counter < (uint16)CML_u_UNSIGNED_16BIT_QUANT_SIZE)
                   if subsequently a new datapair (x_i,v_i) should be added to the statistics
  @post            -

  @author          stefan.sauer@continental-corporation.com

****************************************************************************/
void CML_v_decodeDataLSFQuant(CML_t_LeastSquareFitQuant const *const p_LSFQuant, const float32 f_decodeX, const float32 f_decodeV, CML_t_LeastSquareFit *const p_LSFNonQuant)
{
  /* precalculated decoding factor for abscissa and ordinate, respectively, for runtime optimization */
  float32 f_decodeFactorX, f_decodeFactorV;
  
  CML_ASSERT(p_LSFQuant->u_Data_Counter < (uint16)CML_u_UNSIGNED_16BIT_QUANT_SIZE);
  
  f_decodeFactorX = ( f_decodeX * (1.f/(float32)CML_u_UNSIGNED_16BIT_QUANT_SIZE) ) * (float32)p_LSFQuant->u_Data_Counter;
  f_decodeFactorV = ( f_decodeV * (1.f/(float32)CML_u_SIGNED_16BIT_QUANT_SIZE) ) * (float32)p_LSFQuant->u_Data_Counter;

/* PRQA S 1800 12 */
/* Deactivate QAC warning 1800, Date: 2019-06-18; Reviewer: uidk9586;
   Reason: There is no risk here as want the output to be in float and there is no loss of data. */
  /* decode the quantized LSF data to reconstructed floating point LSF data */
  p_LSFNonQuant->fsumX  = p_LSFQuant->u_sumX  * f_decodeFactorX;
  p_LSFNonQuant->fsumV  = p_LSFQuant->s_sumV  * f_decodeFactorV;
  p_LSFNonQuant->fsumXX = p_LSFQuant->u_sumXX * (f_decodeFactorX * f_decodeX);
  p_LSFNonQuant->fsumXV = p_LSFQuant->s_sumXV * (f_decodeFactorV * f_decodeX);
  p_LSFNonQuant->fsumVV = p_LSFQuant->u_sumVV * ( ( (f_decodeV*f_decodeV) * (1.f/(float32)CML_u_UNSIGNED_16BIT_QUANT_SIZE) ) * (float32)p_LSFQuant->u_Data_Counter );
  p_LSFNonQuant->iData_Counter = (sint32)p_LSFQuant->u_Data_Counter;
}

/*****************************************************************************

  Functionname:    CML_v_encodeDataLSFQuant                           */ /*!

  @brief           Encode the reconstructed floating point LSF data to
                   quantized LSF data
  
  @description     Forward quantization (classification) stage:
                   Encode the reconstructed floating point LSF data p_LSFNonQuant
                   to quantized LSF data p_LSFQuant using the
                   encoding factors f_encodeX and f_encodeV for the abscissa
                   and ordinate, respectively

  @attention       * To avoid division by zero make sure that the following conditions are fulfilled:
                   ( (CML_f_IsNonZero(f_encodeX)) && (CML_f_IsNonZero(f_encodeV)) &&
                   (p_LSFQuant->u_Data_Counter < (uint16)CML_u_UNSIGNED_16BIT_QUANT_SIZE) )
                   * Ensure correct quantization and avoid integer overflow (see detailed description below),
                   e.g., by setting f_encodeX = max(abs(x_i)) for all i and
                   f_encodeV = max(abs(v_i)) for all i

  @param[in]       p_LSFNonQuant : LSF storage structure for reconstructed LSF
                                   Supported values for p_LSF->fsumX [Full range of float32]
                                   Supported values for p_LSF->fsumV [Full range of float32]
                                   Supported values for p_LSF->fsumXX [Full range of float32]
                                   Supported values for p_LSF->fsumVV [Full range of float32]
                                   Supported values for p_LSF->fsumXV [Full range of float32]
                                   Supported values for p_LSF->iData_Counter [Full range of sint32]
                                   Overflow may occur when one or more input values 
                                   are at the defined range extremities.
  @param[in]       f_encodeX     : encoding factor for abscissa of the datapair
                                   [Full range of float32]
  @param[in]       f_encodeV     : encoding factor for ordinate of the datapair
                                   [Full range of float32]
  @param[out]      p_LSFQuant    : LSF storage structure for quantized LSF
                                   [Valid pointer to the structure]

  @return          void

  @pre             * To avoid division by zero make sure that the following conditions are fulfilled:
                   ( (CML_f_IsNonZero(f_encodeX)) && (CML_f_IsNonZero(f_encodeV)) &&
                   (p_LSFQuant->u_Data_Counter < (uint16)CML_u_UNSIGNED_16BIT_QUANT_SIZE) )
                   * Ensure correct quantization and avoid integer overflow (see detailed description below),
                   e.g., by setting f_encodeX = max(abs(x_i)) for all i and
                   f_encodeV = max(abs(v_i)) for all i

  @post            -

  @author          stefan.sauer@continental-corporation.com

****************************************************************************/
void CML_v_encodeDataLSFQuant(CML_t_LeastSquareFit const *const p_LSFNonQuant, const float32 f_encodeX, const float32 f_encodeV, CML_t_LeastSquareFitQuant *const p_LSFQuant)
{
  /* precalculated encoding factor of abscissa and ordinate, respectively, for runtime optimization */
  float32 f_encodeFactorX, f_encodeFactorV;
  /* inverse of encoding factor of abscissa for runtime optimization */
  float32 f_encodeXInverse;
  float32 f_valueClipped;

  /* encode the reconstructed floating point LSF data to quantized LSF data only if it is ensured that no division by zero occurs */
  if ( (CML_f_IsNonZero(f_encodeX)) && (CML_f_IsNonZero(f_encodeV)) && (p_LSFQuant->u_Data_Counter < (uint16)CML_u_UNSIGNED_16BIT_QUANT_SIZE) )
  {
    /* By checking the condition (p_LSFQuant->u_Data_Counter < (uint16)CML_u_UNSIGNED_16BIT_QUANT_SIZE)
    it is ensured that after the increment p_LSFQuant->u_Data_Counter++ the variable p_LSFQuant->u_Data_Counter
    is nonzero */
    p_LSFQuant->u_Data_Counter++;

    f_encodeFactorX = (float32)CML_u_UNSIGNED_16BIT_QUANT_SIZE / ( (float32)p_LSFQuant->u_Data_Counter * f_encodeX );
    f_encodeFactorV = (float32)CML_u_SIGNED_16BIT_QUANT_SIZE   / ( (float32)p_LSFQuant->u_Data_Counter * f_encodeV );

    /* encode the reconstructed floating point LSF data to quantized LSF data */

    /* integer overflow is avoided by the following described facts: */

    /* 0 <= ( p_LSFNonQuant->fsumX / (p_LSFQuant->u_Data_Counter * f_encodeX) ) < 1 */
    f_valueClipped = CML_f_MinMax(0.f, (float32)CML_u_UNSIGNED_16BIT_QUANT_SIZE, p_LSFNonQuant->fsumX  * f_encodeFactorX);
    p_LSFQuant->u_sumX  = (uint16)CML_u_Round2Uint( f_valueClipped );

    /* -1 < ( p_LSFNonQuant->fsumV / (p_LSFQuant->u_Data_Counter * f_encodeV) ) < 1 */
    f_valueClipped = CML_f_MinMax((float32)CML_s_SIGNED_16BIT_LOWER_LIMIT, (float32)CML_u_SIGNED_16BIT_QUANT_SIZE, p_LSFNonQuant->fsumV  * f_encodeFactorV);
    p_LSFQuant->s_sumV  = (sint16)CML_s_Round2Int( f_valueClipped );

    f_encodeXInverse = 1.f / f_encodeX;

    /* 0 <= ( p_LSFNonQuant->fsumXX / (p_LSFQuant->u_Data_Counter * f_encodeX * f_encodeX) ) < 1 */
    f_valueClipped = CML_f_MinMax(0.f, (float32)CML_u_UNSIGNED_16BIT_QUANT_SIZE, p_LSFNonQuant->fsumXX * (f_encodeFactorX * f_encodeXInverse) );
    p_LSFQuant->u_sumXX = (uint16)CML_u_Round2Uint( f_valueClipped );

    /* -1 < ( p_LSFNonQuant->fsumXV / (p_LSFQuant->u_Data_Counter * f_encodeV * f_encodeX) ) < 1 */
    f_valueClipped = CML_f_MinMax((float32)CML_s_SIGNED_16BIT_LOWER_LIMIT, (float32)CML_u_SIGNED_16BIT_QUANT_SIZE, p_LSFNonQuant->fsumXV * (f_encodeFactorV * f_encodeXInverse) );
    p_LSFQuant->s_sumXV = (sint16)CML_s_Round2Int( f_valueClipped );

    /* 0 <= ( p_LSFNonQuant->fsumVV / (p_LSFQuant->u_Data_Counter * f_encodeV * f_encodeV) ) < 1 */
    f_valueClipped = CML_f_MinMax(0.f, (float32)CML_u_UNSIGNED_16BIT_QUANT_SIZE,
      p_LSFNonQuant->fsumVV * ( (float32)CML_u_UNSIGNED_16BIT_QUANT_SIZE / ( (float32)p_LSFQuant->u_Data_Counter * (f_encodeV*f_encodeV) ) ) );
    p_LSFQuant->u_sumVV = (uint16)CML_u_Round2Uint( f_valueClipped );
  }
  else
  {
    CML_ASSERT(b_FALSE);
  }

}
