/*! \file **********************************************************************

  COMPANY:                   Continental AG, A.D.C. GmbH

  CPU:                       CPU-Independent

  COMPONENT:                 CML (Common Math Library)

  MODULNAME:                 cml_stat.h

  DESCRIPTION:               Statistics Library

  AUTHOR:                    N.Hanel / P.Dintzer

  CREATION DATE:             03.02.2010

  VERSION:                   $Revision: 1.16 $

  ---*/ /*---
  CHANGES:                   $Log: cml_stat.h  $
  CHANGES:                   Revision 1.16 2017/11/24 06:32:04CET Kotre, Jeevan (uidk9586) (uidk9586) 
  CHANGES:                   Updated cml_stat with proper naming conventions.
  CHANGES:                   Revision 1.15 2017/10/13 11:05:26CEST Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   Corrected the function header format
  CHANGES:                   Revision 1.14 2017/09/27 05:59:28CEST Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   Merged from branch with Detailed Design
  CHANGES:                   Revision 1.13 2015/05/19 13:46:58CEST Sauer, Stefan (uidg5644) 
  CHANGES:                   - Added structure and functions for quantized LSF
  CHANGES:                   - Added comments -  uidg5644 [May 19, 2015 1:46:59 PM CEST]
  CHANGES:                   Change Package : 334078:1 http://mks-psad:7002/im/viewissue?selection=334078
  CHANGES:                   Revision 1.12 2015/04/29 17:14:52CEST Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   - Changes with respect to Coding Guidelines
  CHANGES:                     of variables
  CHANGES:                   --- Added comments ---  uidr5428 [Apr 29, 2015 5:14:52 PM CEST]
  CHANGES:                   Change Package : 324617:3 http://mks-psad:7002/im/viewissue?selection=324617
  CHANGES:                   Revision 1.11 2014/12/04 17:21:53CET Schwarzkopf, Sebastian (uidg6516) 
  CHANGES:                   - changed interface data of CML_f_CalcQuantile() from pointer to array as they're accessed that way
  CHANGES:                   --- Added comments ---  uidg6516 [Dec 4, 2014 5:21:56 PM CET]
  CHANGES:                   Change Package : 266613:11 http://mks-psad:7002/im/viewissue?selection=266613
  CHANGES:                   Revision 1.10 2014/04/07 10:32:12CEST Schwarzkopf, Sebastian (uidg6516) 
  CHANGES:                   - fixed erroneous include protection
  CHANGES:                   --- Added comments ---  uidg6516 [Apr 7, 2014 10:32:13 AM CEST]
  CHANGES:                   Change Package : 227281:3 http://mks-psad:7002/im/viewissue?selection=227281
  CHANGES:                   Revision 1.9 2014/02/04 15:13:45CET Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   - improve code quality
  CHANGES:                   --- Added comments ---  uidu0849 [Feb 4, 2014 3:13:45 PM CET]
  CHANGES:                   Change Package : 159154:34 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.8 2013/10/15 10:01:28CEST Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   - add least squares fit with weight decay of old measurements
  CHANGES:                   --- Added comments ---  uidu0849 [Oct 15, 2013 10:01:28 AM CEST]
  CHANGES:                   Change Package : 191344:1 http://mks-psad:7002/im/viewissue?selection=191344
  CHANGES:                   Revision 1.7 2013/05/03 09:57:47CEST Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   - drop algo_common from CML
  CHANGES:                   - use new standard type names, e.g. float32 instead of f32_t
  CHANGES:                   --- Added comments ---  uidu0849 [May 3, 2013 9:57:47 AM CEST]
  CHANGES:                   Change Package : 159154:27 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.6 2013/04/12 15:19:51CEST Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   - Add calculation of Gaussian quantiles
  CHANGES:                   --- Added comments ---  uidu0849 [Apr 12, 2013 3:19:51 PM CEST]
  CHANGES:                   Change Package : 159154:24 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.5 2013/02/22 09:32:22CET Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   - include prediction for least square fit
  CHANGES:                   --- Added comments ---  uidu0849 [Feb 22, 2013 9:32:23 AM CET]
  CHANGES:                   Change Package : 159154:16 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.4 2013/02/12 13:13:57CET Juengst, Markus (uidv8617) 
  CHANGES:                   - functions for linear approximation included
  CHANGES:                   --- Added comments ---  uidv8617 [Feb 12, 2013 1:13:58 PM CET]
  CHANGES:                   Change Package : 165907:1 http://mks-psad:7002/im/viewissue?selection=165907
  CHANGES:                   Revision 1.3 2012/12/20 16:39:03CET Diewald, Fabian (uidt8878) 
  CHANGES:                   added method for quantile calculation
  CHANGES:                   --- Added comments ---  uidt8878 [Dec 20, 2012 4:39:03 PM CET]
  CHANGES:                   Change Package : 158114:8 http://mks-psad:7002/im/viewissue?selection=158114
  CHANGES:                   Revision 1.2 2012/09/20 13:29:47CEST Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   - delete old log in file header
  CHANGES:                   --- Added comments ---  uidu0849 [Sep 20, 2012 1:29:47 PM CEST]
  CHANGES:                   Change Package : 159154:3 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.1 2012/09/14 14:31:17CEST Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/CML_CommonMathLibrary/04_Engineering/01_Source_Code/algo/cml/project.pj

**************************************************************************** */

/**
@defgroup stat STAT (Statistics Library)
  @ingroup cml
@{ */

/*****************************************************************************
  INCLUDE PROTECTION
*****************************************************************************/

/* allow inclusion of cml sub-headers only if external cml header is included */
#ifndef _CML_EXT_INCLUDED
  #pragma message(__FILE__": Inclusion of cml_stat.h is discouraged. It exists only for compatibility with ARS3xx and might be deleted without prior notice. Include cml_ext.h instead.")
#endif /* #ifdef _CML_EXT_INCLUDED */

#ifndef _CML_STAT_INCLUDED
#define _CML_STAT_INCLUDED


/*****************************************************************************
  CONSTANTS
*****************************************************************************/

#define CML_f_GaussErrFctMaxX 1.99f                        ///< Input value threshold for Gauss Error Function \description For input greater than this the Gauss error function return 1.0f 

/* magic constants to approximate the Gauss error function */
#define CML_f_GaussErrFctConst0 0.002289f                  ///< Constant in the 4th order polynomial for the Gauss Error function
#define CML_f_GaussErrFctConst1 1.146f                     ///< Coefficient for the first term in the 4th order polynomial for the Gauss Error function
#define CML_f_GaussErrFctConst2 0.1092f                    ///< Coefficient for the second term in the 4th order polynomial for the Gauss Error function
#define CML_f_GaussErrFctConst3 0.2841f                    ///< Coefficient for the third term in the 4th order polynomial for the Gauss Error function
#define CML_f_GaussErrFctConst4 0.08869f                   ///< Coefficient for the fourth term in the 4th order polynomial for the Gauss Error function

#define CML_f_GaussianCDFMinSigma 0.000001f                ///< Minimum standard deviation value to trigger the calculation of Standard Gaussian CDF \description The approximation of the Gaussian CDF just return 0 / 1 (Based on input value) for sigma smaller than this

/* magic constants for the calculation of Gaussian quantiles (Beasly-Springer approach) */
#define CML_f_GaussQuantile_a0  (  2.50662823884f)         ///< Constant term in the numerator polynomial for the standard Gaussian distribution calculation
#define CML_f_GaussQuantile_a1  (-18.61500062529f)         ///< Coefficient for the first term in the numerator polynomial standard Gaussian distribution calculation
#define CML_f_GaussQuantile_a2  ( 41.39119773534f)         ///< Coefficient for the second term in the numerator polynomial standard Gaussian distribution calculation
#define CML_f_GaussQuantile_a3  (-25.44106049637f)         ///< Coefficient for the third term in the numerator polynomial standard Gaussian distribution calculation
#define CML_f_GaussQuantile_b0  (  1.f)                    ///< Constant term in the denominator polynomial for the standard Gaussian distribution calculation
#define CML_f_GaussQuantile_b1  ( -8.47351093090f)         ///< Coefficient for the first term in the denominator polynomial standard Gaussian distribution calculation
#define CML_f_GaussQuantile_b2  ( 23.08336743743f)         ///< Coefficient for the second term in the denominator polynomial standard Gaussian distribution calculation
#define CML_f_GaussQuantile_b3  (-21.06224101826f)         ///< Coefficient for the third term in the denominator polynomial standard Gaussian distribution calculation
#define CML_f_GaussQuantile_b4  (  3.13082909833f)         ///< Coefficient for the fourth term in the denominator polynomial standard Gaussian distribution calculation

/* bounds and values for the calculation of Gaussian quantiles (Beasly-Springer approach) */
/* bounds shifted by 0.5 to use symmetry for efficient calculation */
#define CML_f_GaussQuantile_lowerValue   (1.40507145f)      ///< Minimum value for the output in Gauss quantile calculation using linear approximation to 2 sigma 
#define CML_f_GaussQuantile_lowerBound   (0.92f - 0.5f)     ///< Maximum value of shifted input to perform Beasley Springer approach for Gauss quantile calculation
#define CML_f_GaussQuantile_sigma2Value  (1.99539331f)      ///< Constant value for the Gauss quantile calculation using linear approximation to 2 sigma. Minimum value for the output in Gauss quantile calculation using linear approximation to 3 sigma  
#define CML_f_GaussQuantile_sigma2Bound  (0.977f - 0.5f)    ///< Maximum value of shifted input for Gauss quantile calculation using linear approximation to 2 sigma
#define CML_f_GaussQuantile_sigma3Value  (3.090232306f)     ///< Constant value for the Gauss quantile calculation using linear approximation to 3 sigma  
#define CML_f_GaussQuantile_sigma3Bound  (0.999f - 0.5f)    ///< Maximum value of shifted input for Gauss quantile calculation using linear approximation to 3 sigma
#define CML_f_GaussQuantile_highValue    (4.0f)             ///< The output value for Gauss Quantile calculation, in case the input exceeds the sigma 3 bound value

/*****************************************************************************
  TYPEDEFS
*****************************************************************************/

///< \brief       Structure for the summary of a weighted sample
///< \description The weighted sample structure contains the following information : 
///<              sum of elements, sum of square of elements, sum of weights, mean and standrad deviation
typedef struct {
  float32 dSumme;          ///< Sum of the elements
  float32 dQuadSumme;      ///< Sum of Square of elements
  float32 f_sumOfWeights;  ///< Sum of the weight of the elements
  float32 dMittel;         ///< Mean of the elements
  float32 dStdAbw;         ///< Standard Deviation of the elements
} CML_t_WeightedSample;

/**/
///< \brief       Structure for Least Squares Fit
///< \description The Least Squares Fit structure contains the following information : 
///<              number of data pairs, sum of X value, sum of V value, sum of X*X, sum of X*V and sum of V*V
typedef struct {
  sint32 iData_Counter;     ///< Number of Datapairs (x_i,v_i) in Statistics 
  float32 fsumX;            ///< Sum of (x_i) 
  float32 fsumV;            ///< Sum of (v_i) 
  float32 fsumXX;           ///< Sum of (x_i * x_i) 
  float32 fsumXV;           ///< Sum of (x_i * v_i) 
  float32 fsumVV;           ///< Sum of (v_i * v_i) 
} CML_t_LeastSquareFit;

/**/
///< \brief       Structure for Quantized Least Squares Fit
///< \description The Quantized Least Squares Fit structure contains the following information : 
///<              number fo data pairs, sum of X value, sum of V value, sum of X*X, sum of X*V and sum of V*V
typedef struct {
  uint16  u_Data_Counter;    ///< Number of Datapairs (x_i,v_i) in Statistics 
  uint16  u_sumX;            ///< Sum of (x_i) 
  sint16  s_sumV;            ///< Sum of (v_i) 
  uint16  u_sumXX;           ///< Sum of (x_i * x_i) 
  sint16  s_sumXV;           ///< Sum of (x_i * v_i) 
  uint16  u_sumVV;           ///< Sum of (v_i * v_i) 
} CML_t_LeastSquareFitQuant;

/**/
///< \brief       Structure for Exponential Forget Least Squares Fit
///< \description The Exponential Forget Least Squares Fit structure contains the following information : 
///<              number fo data pairs, sum of X value, sum of V value, sum of X*X, sum of X*V and sum of V*V
typedef struct {
  float32 fData_Counter;    ///< Number of Datapairs (x_i,v_i) in Statistics 
  float32 fsumX;            ///< Sum of (x_i) 
  float32 fsumV;            ///< Sum of (v_i) 
  float32 fsumXX;           ///< Sum of (x_i * x_i) 
  float32 fsumXV;           ///< Sum of (x_i * v_i) 
  float32 fsumVV;           ///< Sum of (v_i * v_i) 
} t_LeastSquareFit_ForgetExponential;

/**/
///< \brief       Structure for least square fit result
///< \description The Least Squares Fit Result structure contains the following information : 
///<              slope, correlation, Y-intersection, square error and mean square error.
typedef struct {
  float32 fSlope;           ///< Slope value.           v = Slope * x + YIntersection 
  float32 fCorrelation;     ///< Linear Correlation Coefficient 
  float32 fYIntersection;   ///< Y-Intersection Value.  v = Slope * x + YIntersection 
  float32 fChi2_Error;      ///< Square error : sum (v_i - Slope * x_i - YIntersection)^2 
  float32 fmse;             ///< Mean Square Error 
} CML_t_LeastSquareFitResults;

/*****************************************************************************
  FUNCTION DECLARATIONS
*****************************************************************************/

/*****************************************************************************
  Functionname:    CML_v_initWeightedSample                              *//*!

  \brief           Initialisation of the weighted sample structure
                   
  \description     This function initializes all elements of the weighted
                   sample structure to zero. The elements include the sum 
                   of the samples, sum of sample squares , sum of the weights,
                   mean and standard deviation of the samples.
  \attention       The function does NOT check the validity of the pointer passed
                   
  \param[in]       p_sample : structure to be initialized
                              [Valid pointer to the structure]

  \return          void
                   
  \author          R. Ehrhardt

  \testmethod  
  \traceability    
*****************************************************************************/
extern void CML_v_initWeightedSample(CML_t_WeightedSample *p_sample);

/*****************************************************************************
  Functionname:    CML_v_addSamplePoint                                  *//*!

  \brief           Add a sample point to the weighted sample structure
                   
  \description     This function adds a sample point to the weighted sample 
                   structure. The function checks if the given weight is greater than or equal to zero.
                   If yes, then the given sample is added to the structure elements with the
                   given weights. Otherwise the values are kept unchanged.
  \InOutCorrelation
                   \f[ Sum = Sum + (value_new \times weight_new) \\ \f]
                   \f[ SquareSum = SquareSum + ((value_new)^2 \times weight_new) \\ \f]
                   \f[ Weights = Weights + weight_new \\ \f]
  \attention       The function does NOT check the validity of the pointer passed

  \param[in,out]   p_sample : sample structure to which the new point is added
                              Supported values for p_sample.dSumme [Full range of float]
                              Supported values for p_sample.dQuadSumme [Full range of float]
                              Supported values for p_sample.f_sumOfWeights [Full range of float]
  \param[in]       f_value :  value of the new sample point
                              [Full range of float]
  \param[in]       f_weight : weight of the new sample point, must not be negative
                              [Full range of float]
                              Overflow may occur when one or more input values 
                              are at the defined range extremities.

  \return          none
                   
  \author          R. Ehrhardt

  \testmethod  
  \traceability    
*****************************************************************************/
extern void CML_v_addSamplePoint(CML_t_WeightedSample *p_sample, float32 f_value, float32 f_weight);

/*****************************************************************************
  Functionname:    CML_v_multiplySampleWithFactor                        *//*!
  
  \brief           Multiplies the sample with a factor
                   
  \description     This function multiplies the weighted structure sample 
                   with a given factor.The function checks if the given factor is greater than or equal to zero.
                   If yes, then the given factor is multiplied to the structure elements 
                   Otherwise the values are kept unchanged.
  \InOutCorrelation
                   \f[ Sum = Sum \times factor (value_new \times weight_new) \\ \f]
                   \f[ SquareSum = SquareSum \times factor \\ \f]
                   \f[ Weights = Weights \times factor \\ \f]
  \attention       The function does NOT check the validity of the pointer passed
                   
  \param[in]       p_sample : sample structure
                              Supported values for p_sample.dSumme [Full range of float]
                              Supported values for p_sample.dQuadSumme [Full range of float]
                              Supported values for p_sample.f_sumOfWeights [Full range of float]
  \param[in]       f_factor : the factor to multiply the values and weights with, 
                              must NOT be negative
                              [Full positive range of float]

  \return          none
                   
  \author          R. Ehrhardt

  \testmethod  
  \traceability    
*****************************************************************************/
extern void CML_v_multiplySampleWithFactor(CML_t_WeightedSample *p_sample, float32 f_factor); 

/*****************************************************************************
  Functionname:    CML_v_computeMeanStd                                  *//*!

  \brief           Compute mean and standard deviation of the sample
                   
  \description     This function computes mean and standard deviation of 
                   the sample.The function checks if the sum of weights is 
                   greater than zero. If yes, then calculates the mean and standard
                   deviation of the given sample structure. Otherwise it returns just
                   by setting the standard deviation to zero.
  \InOutCorrelation
                   If sum of weighted samples x1, x2, .., xn and the sum of 
                   weights of these samples are given, then 
                   \f[ Mean = \frac{Sum \ of \ weighted \ samples}{Sum \ of \ weights} \f]
                   If sum of square of weighted samples and the sum of 
                   weights of these samples are given, then standard deviation is, 
                   \f[ \sigma = \sqrt{\frac{Sum \ of \ square \ of \ weighted \ samples}{Sum \ of \ weights} - Mean^2} \f]
  \attention       The function does NOT check the validity of the pointer passed

  \param[in,out]   p_sample : structure for which mean and std should be 
                              computed
                              Supported values for p_sample.dSumme [Full range of float]
                              Supported values for p_sample.dQuadSumme [Full range of float]
                              Supported values for p_sample.f_sumOfWeights [Full range of float]

  \return          none
                   
  \author          R. Ehrhardt

  \testmethod  
  \traceability    
*****************************************************************************/
extern void CML_v_computeMeanStd(CML_t_WeightedSample *p_sample); 

/*****************************************************************************
  Functionname:    CML_f_calcGaussErrorFunction                          *//*!

  \brief           Calculate the Gauss Error Function
                   
  \description     This function calculate the Gauss Error Function.
                   Aproximation is done with a 4th order polynomial. 
                   The function perform calculation only if the input value is
                   less than a threshold of 1.99 
  \InOutCorrelation 
                   The return value is calculated as,
                   \f[ G = ( ( ( (C_4 \times x^4) - (C_3 \times x^3) ) - (C_2 \times x^2) ) + (C_1 \times x) ) + C_0 \f]
                   where the coefficients C_0, C_1, C_2, C_3 and C_4 are predefined 
                   values.
                   
  \param[in]       f_value : input to the Gauss error function
                             Supported values for f_value [-F_MAX...F_MAX]
                             where F_MAX is the fourth root of the maximum value of float32.

  \return          Gauss error function value
                   
  \author          Gicu Benchea
   
  \testmethod  
  \traceability   
*****************************************************************************/
extern float32 CML_f_calcGaussErrorFunction  ( float32 f_value );

/*****************************************************************************
  Functionname:    CML_f_calcStdGaussianCDF                              *//*!

  \brief           Calculate the value of the standard Gaussian CDF
                   
  \description     This function calculate the value of the standard Gaussian
                   cumulative distribution function. The function flow is as shown below.
                   @startuml
                   (*) --> [value,avg,sigma] If (sigma < (min standard deviation))
                   --> [Yes] If (value < avg)
                   --> [Yes] CDF = 0
                   --> (*)
                   note left : 
                   else
                   --> [No] CDF = 1
                   --> (*)
                   Endif
                   else
                   --> [No] Calculate the Gauss error function input, x = (value - avg)/(sigma * sqrt(2))
                   If x < 0
                   --> [Yes] Call the gaussian error function f(x) : x= -f(-x)
                   note left: process the negative values
                   --> x = (1 + x )/2
                   else
                   --> [No] Call the gaussian error function f(x) : x= f(x)
                   note right: process positive values
                   Endif
                   --> x = (1 + x )/2
                   --> (*)
                   @enduml
  \InOutCorrelation
                   \f[ CDF, x = \frac{( 1 + errorfunction(\frac{(val - avg)}{(sigma \times \sqrt{2})})}{2} \f]
                   
  \param[in]       f_value : input to the CDF
                             [Full range of float]
  \param[in]       f_avg   : mean of the Gaussian distribution
                             [Full range of float]
  \param[in]       f_sigma : standard deviation of the Gaussian distribution
                             [Full range of float]

  \return          standard Gaussian CDF at the given value
                   
  \author          Gicu Benchea

  \testmethod  
  \traceability    
*****************************************************************************/
extern float32 CML_f_calcStdGaussianCDF ( float32 f_value, float32 f_avg, float32 f_sigma );


/*****************************************************************************
  
  Functionname:    CML_v_initLSF                                        *//*!

  \brief           Initialize the LSF storage structure

  \description     This function initializes all the elements of the LSF
                   storage structure to zero  The elements include the 
                   data counter, sum of x and v values, sum of squares of x and v, and 
                   sum of product of x and v. 
  \attention       The function does NOT check the validity of the pointer passed

  \param[in,out]   p_LSF : LSF storage structure
                           [Valid pointer to the structure]

  \return          void

  \author          nele.hanel@contiautomotive.com

  \testmethod 
  \traceability    
****************************************************************************/
extern void CML_v_initLSF(CML_t_LeastSquareFit *const p_LSF);

/*****************************************************************************

  Functionname:    CML_v_initResultsLSF                                 *//*!

  \brief           Initialize the LSF result structure

  \description     This function initializes all the elements of LSF result
                   structure to zero. The elements of the sructure include 
                   the slope, the correlation, Y-intersection, chi-square error,
                   mean square error.
  \attention       The function does NOT check the validity of the pointer passed

  \param[in,out]   p_LSFRes : LSF result structure
                              [Valid pointer to the structure]

  \return          void

  \author          nele.hanel@contiautomotive.com

  \testmethod
  \traceability    
****************************************************************************/
extern void CML_v_initResultsLSF(CML_t_LeastSquareFitResults *const p_LSFRes);

/*****************************************************************************

  Functionname:    CML_v_addDataLSF                                     *//*!

  \brief           Add Datapair (x, v) to the LSF storage structure

  \description     This function adds a datapair defined by the given 
                   abscissae and ordinate to the LSF storage structure. 
                   The elements that are updated include the 
                   data counter, sum of x and v values, sum of squares of x and v, and 
                   sum of product of x and v. 
  \InOutCorrelation
                   If the new data pair is (abscissa, ordinate)
                   \f[ sum_x = sum_x + abscissa \\
                       sum_v = sum_v + ordinate \\
                       sum_{x^2} = sum_{x^2} + abscissa^2 \\
                       sum_{v^2} = sum_{v^2} + ordinate^2 \\
                       sum{xv} = sum_{xv} + (abscissa \times ordinate) \f]
                   The data counter is increased by 1 after every data pair addition.
  \attention       The function does NOT check the validity of the pointer passed.

  \param[in,out]   p_LSF :       LSF storage structure
                                 Supported values for p_LSF->fsumX [Full range of float32]
                                 Supported values for p_LSF->fsumV [Full range of float32]
                                 Supported values for p_LSF->fsumXX [Full range of float32]
                                 Supported values for p_LSF->fsumXV [Full range of float32]
                                 Supported values for p_LSF->fsumVV [Full range of float32]
                                 Supported values for p_LSF->iData_Counter [Full range of sint32]
  \param[in]       f_abscissae : abscissae of the datapair
                                 Supported values for f_value [-F_MAX...F_MAX]
  \param[in]       f_ordinate :  ordinate of the datapair
                                 Supported values for f_value [-F_MAX...F_MAX]
                                 where F_MAX is the square root of the maximum value of float32.
                                 Overflow may occur when one or more input values 
                                 are at the defined range extremities.

  \return          void

  \author          nele.hanel@contiautomotive.com

  \testmethod  
  \traceability    
****************************************************************************/
extern void CML_v_addDataLSF(CML_t_LeastSquareFit *const p_LSF, const float32 f_abscissae, const float32 f_ordinate);

/*****************************************************************************

  Functionname:    CML_f_calculateSlopeLSF                             *//*!

  \brief           Calculate Slope of the fitting line out of actual LSF 
                   storage structure

  \description     This function calculates the slope of the fitting line
                   out of actual LSF storage structure. The calculation 
                   requires at least two data points, otherwise the function 
                   will return a slope value of zero. The function will 
                   return 0 if the calculation of denominator in the fraction
                   computes to zero. This is in order to avoid any division by 
                   zero occurance in the function.
  \InOutCorrelation
                   Let d be the data counter of the structure, then 
                   \f[  Slope = \frac{((d \times sum_{xv}) - (sum_x \times sum_v))}{(d \times sum_{x^2})-(sum_x)^2}  \f]
  \attention       The function does NOT check the validity of the pointer passed

  \param[in]       p_LSF : LSF storage structure
                           Supported values for p_LSF->fsumX [Full range of float32]
                           Supported values for p_LSF->fsumV [Full range of float32]
                           Supported values for p_LSF->fsumXX [Full range of float32]
                           Supported values for p_LSF->fsumXV [Full range of float32]
                           Supported values for p_LSF->iData_Counter [Full range of sint32]
                           Overflow may occur when one or more input values 
                           are at the defined range extremities.

  \return          Slope value of the fitting line


  \author          nele.hanel@contiautomotive.com

  \testmethod  
  \traceability    
****************************************************************************/
extern float32 CML_f_calculateSlopeLSF(CML_t_LeastSquareFit const *const p_LSF);

/*****************************************************************************

  Functionname:    CML_f_calculateCorrelationLSF                        *//*!

  \brief           Calculate Correlation of the fitting line out of actual 
                   LSF storage structure

  \description     This function calculates the correlation of the fitting
                   line out of the actual LSF storage structure.The calulation 
                   requires at least two data points, otherwise the function 
                   will return a correlation value of zero.The function will 
                   return 0 if the calculation of denominator in the fraction
                   computes to zero. This is in order to avoid any division by 
                   zero occurance in the function.
  \InOutCorrelation
                   Let d be the data counter of the structure, then 
                   \f[  Correlation = \frac{((d \times sum_{xv}) - (sum_x \times sum_v))}{\sqrt{((d \times sum_{x^2})-(sum_x)^2) \times ((d \times sum_{v^2})-(sum_v)^2)}}  \f]

  \attention       The function does NOT check the validity of the pointer passed
  \param[in]       p_LSF : LSF storage structure
                           Supported values for p_LSF->fsumX [Full range of float32]
                           Supported values for p_LSF->fsumV [Full range of float32]
                           Supported values for p_LSF->fsumXX [Full range of float32]
                           Supported values for p_LSF->fsumVV [Full range of float32]
                           Supported values for p_LSF->fsumXV [Full range of float32]
                           Supported values for p_LSF->iData_Counter [Full range of sint32]
                           Overflow may occur when one or more input values 
                           are at the defined range extremities.

  \return          Correlation of the fitting line

  \author          nele.hanel@contiautomotive.com

  \testmethod  
  \traceability    
****************************************************************************/
extern float32 CML_f_calculateCorrelationLSF(CML_t_LeastSquareFit const *const p_LSF);

/*****************************************************************************

  Functionname:    CML_f_calculateYIntersectionLSF                      *//*!

  \brief           Calculate Point of Intersection with Y-Axis of the fitting
                   line out of actual LSF storage structure

  \description     This function calculates the point of intersection with
                   Y-axis of the fitting line out of the actual LSF storage
                   structure.The calulation requires at least two data points,
                   otherwise the function will return a Y-intersection value of 
                   zero. The function will return 0 if the calculation of 
                   denominator in the fraction computes to zero. 
                   This is in order to avoid any division by zero  
                   occurance in the function.
  \InOutCorrelation
                   Let d be the data counter of the structure, then 
                   \f[  Y_{intersection} = \frac{((sum_v \times sum_{x^2}) - (sum_x \times sum_{xv}))}{((d \times sum_{x^2})-(sum_x)^2)}  \f]

  \attention       The function does NOT check the validity of the pointer passed

  \param[in]       p_LSF : LSF storage structure
                           Supported values for p_LSF->fsumX [Full range of float32]
                           Supported values for p_LSF->fsumV [Full range of float32]
                           Supported values for p_LSF->fsumXX [Full range of float32]
                           Supported values for p_LSF->fsumVV [Full range of float32]
                           Supported values for p_LSF->fsumXV [Full range of float32]
                           Supported values for p_LSF->iData_Counter [Full range of sint32]
                           Overflow may occur when one or more input values 
                           are at the defined range extremities.

  \return          Point of Intersection with Y-Axis of the fitting line

  \author          nele.hanel@contiautomotive.com

  \testmethod  
  \traceability    
****************************************************************************/
extern float32 CML_f_calculateYIntersectionLSF(CML_t_LeastSquareFit const *const p_LSF);

/*****************************************************************************

  Functionname:    CML_f_calculateSquareErrorLSF                        *//*!

  \brief           Calculate Least Squared Error of the fitting line out of
                   actual LSF storage structure

  \description     This function calulates the least squared error of the 
                   fitting line out of the actual LSF storage structure.
                   The calulation requires at least two data points,
                   otherwise the function will return a least squared error
                   value of zero.
  \InOutCorrelation
                   Let n be the data counter
                   \f[ \chi^2 = \sum_{i=1}^n ( v_i - (slope \times x_i) - Y_{Intersection} )^2. \f]
                   This is not calculated directly, but instead
                   \f[ \chi^2 = (1-correlation^2) \times N_{VarV}  \\ 
                       N_{VarV} = sum_{V^2} - \frac{(sum_V)^2}{n} \f]
  \attention       The function does NOT check the validity of the pointer passed
  \param[in]       p_LSF : LSF storage structure
                           Supported values for p_LSF->fsumV [Full range of float32]
                           Supported values for p_LSF->fsumVV [Full range of float32]
                           Supported values for p_LSF->iData_Counter [Full range of sint32]
                           Overflow may occur when one or more input values 
                           are at the defined range extremities.
  \param[in]       f_LSFCorrelation : Correlation of the fitting line
                                      Supported values [Full range of sint32]

  \return          Least Squared Error of the fitting line

  \pre             Calculate actual Correlation!

  \author          nele.hanel@contiautomotive.com

  \testmethod  
  \traceability    
****************************************************************************/
extern float32 CML_f_calculateSquareErrorLSF(CML_t_LeastSquareFit const *const p_LSF, const float32 f_LSFCorrelation);

/*****************************************************************************

  Functionname:    CML_f_calculateMeanSquareErrorLSF                    *//*!

  \brief           Calculate the Mean Square Error of the fitting line out of
                   actual LSF storage structure

  \description     This function calcuates the mean square error of the fitting
                   line out out of the actual LSF storage structure.
                   The calulation requires at least two data points,
                   otherwise the function will return a mean square error
                   value of zero. The function calls the method to calculate the
                   square error first (CML_f_CalculateSquareError_LSF) and then divides this data by the available data 
                   counter value.
  \InOutCorrelation
                   Let d be the data counter,
                   \f[ MSE = \frac{\chi^2}{d} \f]
  \attention       The function does NOT check the validity of the pointer passed

  \param[in]       p_LSF : LSF storage structure
                           Supported values for p_LSF->fsumV [Full range of float32]
                           Supported values for p_LSF->fsumVV [Full range of float32]
                           Supported values for p_LSF->iData_Counter [Full range of sint32]
                           Overflow may occur when one or more input values 
                           are at the defined range extremities.
  \param[in]       f_LSFCorrelation : Correlation of the fitting line
                                      Supported values [Full range of sint32]

  \return          Mean Square Error of actual LSF-Structure

  \pre             Calculate actual Correlation!

  \author          philippe.dintzer@contiautomotive.com

  \testmethod  
  \traceability    
****************************************************************************/
extern float32 CML_f_calculateMeanSquareErrorLSF(CML_t_LeastSquareFit const *const p_LSF, const float32 f_LSFCorrelation);

/*****************************************************************************

  Functionname:    CML_v_calculateQualityLSF                            *//*!

  \brief           Calculate Quality of the fitting line out of actual
                   LSF storage structure

  \description     This function calculate properties describing the Quality 
                   of the fitting line based on the actual LSF storage structure:
                     - Correlation
                     - Mean Square Error
                   The calulation requires at least two data points,
                   otherwise the function will set mean square error
                   and correlation values of zero. The function will return 0 
                   if the calculation of denominator in the fraction computes to zero. 
                   This is in order to avoid any division by zero  
                   occurance in the function.
  \InOutCorrelation
                   Let d be the data counter of the structure, then  Correlation is,
                   \f[  Correlation = \frac{((d \times sum_{xv}) - (sum_x \times sum_{v}))}{\sqrt{((d \times sum_{x^2})-(sum_x)^2) \times ((d \times sum_{v^2})-(sum_v)^2)}}  \f]
                   and Mean Square error is,
                   \f[  MSE = (1 - Correlation^2) \times \frac{((d \times sum_{v^2})-(sum_v)^2)}{d^2} \f]
  \attention       The function does NOT check the validity of the pointer passed

  \param[in]       p_LSF : LSF storage structure
                           Supported values for p_LSF->fsumX [Full range of float32]
                           Supported values for p_LSF->fsumV [Full range of float32]
                           Supported values for p_LSF->fsumXX [Full range of float32]
                           Supported values for p_LSF->fsumVV [Full range of float32]
                           Supported values for p_LSF->fsumXV [Full range of float32]
                           Supported values for p_LSF->iData_Counter [Full range of sint32]
                           Overflow may occur when one or more input values 
                           are at the defined range extremities.
  \param[out]      f_LSFCorrelation : Correlation of the fitting line
                                      [Full range of float32]
  \param[out]      f_LSFmse : Mean Square Error of the fitting line
                              [Full range of float32]

  \return          void

  \author          philippe.dintzer@contiautomotive.com

  \testmethod  
  \traceability    
****************************************************************************/
extern void CML_v_calculateQualityLSF(CML_t_LeastSquareFit const *const p_LSF, float32 *const f_LSFCorrelation, float32 *const f_LSFmse);

/*****************************************************************************

  Functionname:    CML_v_calculateAllLSF                               *//*!

  \brief           Calculate Fitting results of the fitting line out of actual
                   LSF storage structure

  \description     This function calculate all properties of the fitting line 
                   based on the actual LSF storage structure:
                     - Slope
                     - Y-Intersection
                     - Correlation
                     - Square Error
                     - Mean Square Error
                   The calulation requires at least two data points,
                   otherwise no calculation is done. The function will return 0 
                   for the elements if the calculation of denominator in the fraction  
                   computes to zero. This is in order to avoid any division by zero  
                   occurance in the function.
  \InOutCorrelation
                   Let d be the data counter of the structure, then  Correlation is
                   \f[  Correlation = \frac{((d \times sum_{xv}) - (sum_x \times sum_v))}{\sqrt{((d \times sum_{x^2})-(sum_x)^2) \times ((d \times sum_{v^2})-(sum_v)^2)}}  \f]
                   Square error is
                   \f[  \chi^2 = (1 - Correlation^2) \times \frac{((d \times sum_{v^2})-(sum_v)^2)}{d^2} \f]
                   Slope, 
                   \f[  Slope = \frac{((d \times sum_{xv}) - (sum_x \times sum_v))}{((d \times sum_{x^2})-(sum_x)^2)}  \f]
                   YIntersection
                   \f[  Y_{Intersection} = \frac{((sum_v \times sum_{x^2}) - (sum_x \times sum_{xv}))}{((d \times sum_{x^2})-(sum_x)^2)}  \f]
                   and Mean Square Error,
                   \f[ MSE = \frac{\chi^2}{d} \f]
  \attention       The function does NOT check the validity of the pointer passed

  \param[in]       p_LSF : LSF storage structure
                           Supported values for p_LSF->fsumX [Full range of float32]
                           Supported values for p_LSF->fsumV [Full range of float32]
                           Supported values for p_LSF->fsumXX [Full range of float32]
                           Supported values for p_LSF->fsumVV [Full range of float32]
                           Supported values for p_LSF->fsumXV [Full range of float32]
                           Supported values for p_LSF->iData_Counter [Full range of sint32]
                           Overflow may occur when one or more input values 
                           are at the defined range extremities.
  \param[out]      p_LSFRes : LSF result structure

  \return          void

  \author          nele.hanel@contiautomotive.com

  \testmethod  
  \traceability    
****************************************************************************/
extern void CML_v_calculateAllLSF(CML_t_LeastSquareFit const *const p_LSF, CML_t_LeastSquareFitResults *const p_LSFRes);

/*****************************************************************************

  Functionname:    CML_f_predictLSF                                     *//*!

  \brief           Predict y-value on least square fit for given x-value

  \description     This function predict y-value on least square fit for 
                   given x-value.The calculation is done using basic eqaution 
                   for line,
                   y = mx + c, 
                   where,
                   m = slope
                   c = Y intersection 
  \InOutCorrelation
                   \f[ y = (slope \times value) + Y_{Intersection} \f]
  \attention       The function does NOT check the validity of the pointer passed

  \param[in]       f_xValue : x-value for which y-value to be determined
                              Supported values [Full range of float32]
  \param[in,out]   p_LSFResults : LSF result structure
                                  Supported values for p_LSFResults->fSlope [Full range of float32]
                                  Supported values for p_LSFResults->fYIntersection [Full range of float32]
                                  Overflow may occur when one or more input values 
                                  are at the defined range extremities.
  \return          y-value on least square fit for given x-value

  \author          D. Meschenmoser

  \testmethod  
  \traceability    
****************************************************************************/
extern float32 CML_f_predictLSF(CML_t_LeastSquareFitResults const *const p_LSFResults, float32 f_xValue);

/*****************************************************************************

  Functionname:    CML_v_initLSFForgetExponential                     *//*!

  \brief           Init the LSF storage structure with exponential forget

  \description     This function initializes all the elements of LSF storage 
                   structure with exponential forget to zero. The elements include the 
                   data counter, sum of x and v values, sum of squares of x and v, and 
                   sum of product of x and v. 
  \attention       The function does NOT check the validity of the pointer passed

  \param[in,out]   p_LSF : LSF storage structure with exponential forget
                           [Valid pointer to the structure]

  \return          void

  \author          martin.warnecke@continental-corporation.com

  \testmethod  
  \traceability    
****************************************************************************/
extern void CML_v_initLSFForgetExponential(t_LeastSquareFit_ForgetExponential *const p_LSF);

/***********************************************************************
  Functionname:    CML_v_addDataLSFForgetExponential             *//*!

  \brief           Add data pair (x, v) to the LSF storage structure
                   with exponential forget

  \description     This function adds a data pair (f_abscissa, f_ordinate) 
                   to the LSF storage structure with exponential forget.
                   The elements that are updated include the data counter,
                   sum of x and v values, sum of squares of x and v, and 
                   sum of product of x and v. 
  \InOutCorrelation
                   If the new data pair is (abscissa, ordinate) and the weightage 
                   for the existing values is M, 
                   \f[ sum_x = (sum_x \times M) + abscissa \\
                       sum_v = (sum_v \times M) + ordinate \\
                       sum_{x^2} = (sum_{x^2} \times M) + abscissa^2 \\
                       sum_{v^2} = (sum_{v^2} \times M) + ordinate^2 \\
                       sum{xv} = (sum_{xv} \times M) + (abscissa \times ordinate) \f]
                   The data counter is increased by 1 after every data pair addition.
  \attention       The function does NOT check the validity of the pointer passed.

  \param[in,out]   p_LSF  : LSF storage structure with exponential forget
                            Supported values for p_LSF->fsumX [Full range of float32]
                            Supported values for p_LSF->fsumV [Full range of float32]
                            Supported values for p_LSF->fsumXX [Full range of float32]
                            Supported values for p_LSF->fsumVV [Full range of float32]
                            Supported values for p_LSF->fsumXV [Full range of float32]
                            Supported values for p_LSF-fData_Counter [Full range of float32]
                            Overflow may occur when one or more input values 
                            are at the defined range extremities.
  \param[in]       f_abscissa  : abscissa of the data pair
                                 Supported values [Full range of float32]
  \param[in]       f_ordinate  : ordinate of the data pair
                                 Supported values [Full range of float32]
  \param[in]       f_MemoryWeight : Supported values [Full range of float32]

  \return          void

  \author          martin.warnecke@continental-corporation.com

  \testmethod  
  \traceability    
************************************************************************/
extern void CML_v_addDataLSFForgetExponential(t_LeastSquareFit_ForgetExponential *const p_LSF, const float32 f_abscissa, const float32 f_ordinate, const float32 f_MemoryWeight);

/*****************************************************************************

  Functionname:    CML_v_calculateAllLSFForgetExponential             *//*!

  \brief           Calculate Fitting results of the fitting line out of actual
                   LSF storage structure with exponential forget

  \description     This function calculate all properties of the fitting line 
                   based on the actual LSF storage structure with exponential forget:
                     - Slope
                     - Y-Intersection
                     - Correlation
                     - Square Error
                     - Mean Square Error
                   The calulation requires at least two data points,
                   otherwise no calculation is done. The function will return 0 
                   for the elements if the calculation of denominator in the fraction  
                   computes to zero. This is in order to avoid any division by zero  
                   occurance in the function.
  \InOutCorrelation
                   Let d be the data counter of the structure, then  Correlation is
                   \f[  Correlation = \frac{((d \times sum_{xv}) - (sum_x \times sum_v))}{\sqrt{((d \times sum_{x^2})-(sum_x)^2) \times ((d \times sum_{v^2})-(sum_v)^2)}}  \f]
                   Square error is
                   \f[  \chi^2 = (1 - Correlation^2) \times \frac{((d \times sum_{v^2})-(sum_v)^2)}{d^2} \f]
                   Slope, 
                   \f[  Slope = \frac{((d \times sum_{xv}) - (sum_x \times sum_v))}{((d \times sum_{x^2})-(sum_x)^2)}  \f]
                   YIntersection
                   \f[  Y_{Intersection} = \frac{((sum_v \times sum_{x^2}) - (sum_x \times sum_{xv}))}{((d \times sum_{x^2})-(sum_x)^2)}  \f]
                   and Mean Square Error,
                   \f[ MSE = \frac{\chi^2}{d} \f]
  \attention       The function does NOT check the validity of the pointer passed

  \param[in]       p_LSF : LSF storage structure with exponential forget
                           Supported values for p_LSF->fsumX [Full range of float32]
                           Supported values for p_LSF->fsumV [Full range of float32]
                           Supported values for p_LSF->fsumXX [Full range of float32]
                           Supported values for p_LSF->fsumVV [Full range of float32]
                           Supported values for p_LSF->fsumXV [Full range of float32]
                           Supported values for p_LSF-fData_Counter [Full range of float32]
                           Overflow may occur when one or more input values 
                           are at the defined range extremities.
  \param[out]      p_LSFRes : LSF result structure

  \return          -

  \author          martin.warnecke@continental-corporation.com

  \testmethod  
  \traceability    
****************************************************************************/
extern void CML_v_calculateAllLSFForgetExponential(t_LeastSquareFit_ForgetExponential const *const p_LSF, CML_t_LeastSquareFitResults *const p_LSFRes);

/*****************************************************************************
  Functionname:    CML_f_calcQuantile                                    *//*!

  \brief           Calculates a quantile using the fast quick select algorithm
                   
  \description     This function calculates the quantile defined by the given 
                   position. 
                   For example, if requested for 3rd smallest element
                   in an array, then the function partly sorts the array, finds out
                   the 3rd smallest element and returns this value. 
                   @startuml
                   (*) --> [array A, position p] Set Pivot element 
                   note right : Element present at the position of interest (p)
                   --> swap elements of A[last] and A[p]
                   --> i = pos = first
                   --> Check the array value against pivot element 
                   note right: Loop through all values from first to last
                   If A[i] < pivot element
                   --> [Yes] swap A[i] and A[pos]
                   --> Pos = next index of array
                   --> i = the next index of array
                   Else
                   --> [No] i = the next index of array
                   EndIf
                   --> If i < last
                   --> [Yes] Check the array value against pivot element
                   Else
                   --> [No] Swap A[pos] and A[last]
                   Endif
                   If pos < p
                   --> [Yes] Increment 'first' by one 
                   note left : The values at and left of 'first' is not required 
                   --> check for loop condition
                   Else 
                   -->[No] If pos > p
                   -->  [Yes] Decrement 'last' by one
                   note right : The values at and right of 'last' is not required 
                   --> check for loop condition
                   Else 
                   --> [No] check for loop condition
                   EndIf
                   EndIf
                   If (first < last) and (pos!=p)
                   --> [Yes] i = pos = first
                   Else
                   --> [No] Exit Loop 
                   note left: Now the array will be partially sorted and the required value at position p.
                   EndIf
                   --> (*)
                   @enduml
                   
  \param[in,out]   a_valuesDestroyed : pointer onto values from which quantile 
                   should be calculated, 
                   NOTE: array is PARTLY sorted, so if values are needed later, 
                   copy before!
                   Supported values for a_valuesDestroyed[] [Full range of float32]
  \param[in]       u_NofValues : number of values in a_valuesDestroyed
                                 Supported values [Full range of uint32]
  \param[in]       u_NthSmallest: sorted list index of element to be returned, 
                   i.e. 0u for the smallest element, uNofValues-1u for the maximum, 
                   uNofValues/2u for the median
                   Supported values [Full range of uint32]
                   
  \return          quantile
                   
  \author          fabian.diewald@continental-corporation.com

  \testmethod  
  \traceability    
*****************************************************************************/
extern float32 CML_f_calcQuantile(float32 a_valuesDestroyed[], const uint32 u_NofValues, const uint32 u_NthSmallest);

/*****************************************************************************
  Functionname:    CML_f_stdGaussQuantile                                *//*!

  \brief           Calculates a quantile of the standard Gaussian distribution N(0,1)
                   
  \description     Calculates a quantile of the standard Gaussian distribution N(0,1)
                   by the Beasly-Springer approach, i.e. using a rational
                   approximation of order (3,4). The calculation is done based on the 
                   value range in which the shifted input falls in. \n
                   A polynomial form is used for the central region of the quantile, where 0.08 < x < 0.92: \n
                   y = x - 0.5
                   \f[
                      r = y \times \frac{a_1 + (a_2 y^2) + (a_3 y^4) + (a_4 y^6)}{1 + (b_1 y^2) + (b_2 y^4) + (b_3 y^6) + (b_4 y^8)}
                   \f]
                   For the other values simplified linear approximation is used. 
                   If the input is in the range 0.92 - 0.977 (c - d), y = |x - 0.5| ,then,
                   \f[ 
                   r = +-(\frac{(y - c)}{(d - c)}) \times (s_1 - lo) ) + lo
                   \f]
                   If the input is in the range 0.977 - 0.999 (c - d), y = |x - 0.5| ,then,
                   \f[ 
                   r = +-(\frac{(y - d)}{(e - d)}) \times (s_2 - s_1) ) + s_1
                   \f]
                   Otherwise, 
                   \f[ r = +- (hi) \f]
                   
  \param[in]       f_Prob: the probability for which the quantile should be calculated
                           Supported values are float values in the range [0,..,1]
                   
  \return          the standard Gaussian quantile for the given probability
                   
  \author          daniel.meschenmoser@continental-corporation.com

  \testmethod  
  \traceability    
*****************************************************************************/
extern float32 CML_f_stdGaussQuantile(float32 f_Prob);

/*****************************************************************************
  Functionname:    CML_f_gaussQuantile                                   *//*!

  \brief           Calculates a quantile of a Gaussian distribution
                   
  \description     This function calculates a quantile of a Gaussian 
                   distribution. The function calls the CML_f_StdGaussQuantile
                   with the given probability and multiplies it with the standard
                   deviation and added with the mean value.
  \InOutCorrelation 
                   \f[ Let p \ - \ the \ probability \ value,\\
                           \sigma \ - \ standard \ deviation, \\
                           \mu \ - \ mean, \\ then,
                      r = (\sigma \times f(p) ) + \mu \f]
                   
  \param[in]       f_Mean: mean value of the Gaussian distribution
                           Supported values [Full range of float32]
  \param[in]       f_Std:  standard deviation of the Gaussian distribution
                           Supported values [Full range of float32]
  \param[in]       f_Prob: the probability for which the quantile should be calculated
                           Supported values [Full range of float32]
                           Overflow may occur when one or more input values 
                           are at the defined range extremities.
                   
  \return          the Gaussian quantile for the given probability
                   
  \author          daniel.meschenmoser@continental-corporation.com

  \testmethod  
  \traceability    
*****************************************************************************/
extern float32 CML_f_gaussQuantile(float32 f_Mean, float32 f_Std, float32 f_Prob);

/*****************************************************************************

  Functionname:    CML_v_initLSFQuant                                  *//*!

  \brief           Init the LSF storage structure for quantized LSF

  \description     Initialize the LSF storage structure for quantized 
                   (compressed) LSF. All the elements are set to Zero.
                   The abscissa variable is assumed to take non-negative values,
                   the ordinate variable can also take negative values.
                   The elements include the data counter, 
                   sum of x and v values, sum of squares of x and v, and 
                   sum of product of x and v. 
  \attention       The function does NOT check the validity of the pointer passed

  \param[in,out]   p_LSFQuant : LSF storage structure for quantized LSF
                                [Valid pointer to the structure]

  \return          void

  \author          stefan.sauer@continental-corporation.com

  \testmethod  
  \traceability    
****************************************************************************/
extern void CML_v_initLSFQuant(CML_t_LeastSquareFitQuant *const p_LSFQuant);

/*****************************************************************************
  
  Functionname:    CML_v_decodeDataLSFQuant                            *//*!

  \brief           Decode the quantized LSF data to reconstructed
                   floating point LSF data
  
  \description     Inverse quantization (reconstruction) stage:
                   Decode the quantized LSF data p_LSFQuant to reconstructed
                   floating point LSF data p_LSFNonQuant using the
                   decoding factors f_decodeX and f_decodeV for the abscissa
                   and ordinate, respectively.
                   The quantized LSF structure is considered sunch that 
                   the abscissa variable is assumed to take non-negative values (unsigned)
                   the ordinate variable can also take negative values (signed). 
                   The decoding factor for both abscissa and ordinate are calculated 
                   from the decode values given and each element of the non quantized 
                   LSF is computed with the decoding factor.
                   Let the decode values passed are x and v , and the data counter in the 
                   structure be c, then Decoding factors for 
                   abscissa and ordinate are computed as follows.
                   \f[  d_x =  (x \times \frac{1}{Q_{us}}) \times c \f]
                   \f[  d_v =  (v \times \frac{1}{Q_s}) \times c \f]
  \InOutCorrelation
                   \f[ sum_{xNonQuant}   =  sum_{xQuant} \times d_x  \f]
                   \f[ sum_{vNonQuant}   =  sum_{vQuant} \times d_v  \f]
                   \f[ sum_{x^2NonQuant} =  sum_{x^2Quant} \times (d_x \times x) \f]
                   \f[ sum_{xvNonQuant}  =  sum_{xvQuant} \times (d_x \times x)  \f]
                   \f[ sum_{v^2NonQuant} =  sum_{v^2Quant} \times ((v^2 \times \frac{1}{Q_{us}}) \times c)    \f]

                    Q_s = CML_u_SIGNED_16BIT_QUANT_SIZE , Q_us = CML_u_UNSIGNED_16BIT_QUANT_SIZE

  \attention       Make sure that (p_LSFQuant->u_Data_Counter < (uint16)CML_u_UNSIGNED_16BIT_QUANT_SIZE)
                   if subsequently a new datapair (x_i,v_i) should be added to the statistics.
  \param[in]       p_LSFQuant    : LSF storage structure for quantized LSF
                                   Supported values for p_LSFQuant->u_sumX [Full range of uint16]
                                   Supported values for p_LSFQuant->s_sumV [Full range of sint16]
                                   Supported values for p_LSFQuant->u_sumXX [Full range of uint16]
                                   Supported values for p_LSFQuant->s_sumXV [Full range of sint16]
                                   Supported values for p_LSFQuant->u_sumVV [Full range of uint16]
                                   Supported values for p_LSFQuant->u_Data_Counter [Full range of uint16]
                                   Overflow may occur when one or more input values 
                                   are at the defined range extremities.
  \param[in]       f_decodeX     : decoding factor for abscissa of the datapair
                                   [Full range of float32]
  \param[in]       f_decodeV     : decoding factor for ordinate of the datapair
                                   [Full range of float32]
  \param[out]      p_LSFNonQuant : LSF storage structure for reconstructed LSF
                                   [Valid pointer to the structure]

  \return          void

  \pre             Make sure that (p_LSFQuant->u_Data_Counter < (uint16)CML_u_UNSIGNED_16BIT_QUANT_SIZE)
                   if subsequently a new datapair (x_i,v_i) should be added to the statistics

  \author          stefan.sauer@continental-corporation.com

  \testmethod  
  \traceability    
****************************************************************************/
extern void CML_v_decodeDataLSFQuant(CML_t_LeastSquareFitQuant const *const p_LSFQuant, const float32 f_decodeX, const float32 f_decodeV, CML_t_LeastSquareFit *const p_LSFNonQuant);

/*****************************************************************************

  Functionname:    CML_v_encodeDataLSFQuant                           *//*!

  \brief           Encode the reconstructed floating point LSF data to
                   quantized LSF data
  
  \description     Forward quantization (classification) stage:
                   Encode the reconstructed floating point LSF data p_LSFNonQuant
                   to quantized LSF data p_LSFQuant using the
                   encoding values f_encodeX and f_encodeV for the abscissa
                   and ordinate, respectively. The encode factors are calculated based on
                   the provided values and all the quantized structure elements are
                   then calculated. If x and v are the encode values and c be the data
                   counter, then the encodefactors are calculated as,
                   \f[  e_x =  (\frac{Q_{us}}{c \times x}) \f]
                   \f[  e_v =  (\frac{Q_s}{c \times v})    \f]
                   
  \InOutCorrelation
                   \f[ sum_{xQuant}   =  (sum_{xNonQuant} \times d_x)  \f]
                   \f[ sum_{vQuant}   =  (sum_{vNonQuant} \times d_v)  \f]
                   \f[ sum_{x^2Quant}   =  (sum_{xNonQuant} \times (\frac{d_x}{x}) )  \f]
                   \f[ sum_{xvQuant}   =  (sum_{xvNonQuant} \times (\frac{d_v}{x}) )  \f]
                   \f[ sum_{v^2Quant}   =  (sum_{v^2NonQuant} \times (\frac{Q_{us}}{c \times v^2}))  \f]
                   \f[ The \ values \ sum_{xQuant},\ sum_{x^2Quant} \ and \ sum_{v^2Quant} \ are \ clipped
                       \  in \ the \ range \ [0,Q_{us}] \\ whereas \ values \ sum_{vQuant} \ and \ 
                       sum_{xvQuant} \ are \ clipped \  in \ the \ range \ [Q_{-s},Q_s]  \f]

                    All these computed values are then rounded to the nearest integer.

                    Q_-s = CML_s_SIGNED_16BIT_LOWER_LIMIT, Q_s = CML_u_SIGNED_16BIT_QUANT_SIZE , Q_us = CML_u_UNSIGNED_16BIT_QUANT_SIZE 

  \attention       For the function to execute make sure that the following conditions are fulfilled:
                   ( (CML_f_IsNonZero(f_encodeX)) && (CML_f_IsNonZero(f_encodeV)) &&
                   (p_LSFQuant->u_Data_Counter < (uint16)CML_u_UNSIGNED_16BIT_QUANT_SIZE) )
                   Ensure correct quantization and avoid integer overflow (see detailed description),
                   e.g., by setting f_encodeX = max(abs(x_i)) for all i and
                   f_encodeV = max(abs(v_i)) for all i

  \param[in]       p_LSFNonQuant : LSF storage structure for reconstructed LSF
                                   Supported values for p_LSF->fsumX [Full range of float32]
                                   Supported values for p_LSF->fsumV [Full range of float32]
                                   Supported values for p_LSF->fsumXX [Full range of float32]
                                   Supported values for p_LSF->fsumVV [Full range of float32]
                                   Supported values for p_LSF->fsumXV [Full range of float32]
                                   Supported values for p_LSF->iData_Counter [Full range of sint32]
                                   Overflow may occur when one or more input values 
                                   are at the defined range extremities.
  \param[in]       f_encodeX     : encoding factor for abscissa of the datapair
                                   [Full range of float32]
  \param[in]       f_encodeV     : encoding factor for ordinate of the datapair
                                   [Full range of float32]
  \param[out]      p_LSFQuant    : LSF storage structure for quantized LSF
                                   [Valid pointer to the structure]

  \return          void

  \pre             * To avoid division by zero make sure that the following conditions are fulfilled:
                   ( (CML_f_IsNonZero(f_encodeX)) && (CML_f_IsNonZero(f_encodeV)) &&
                   (p_LSFQuant->u_Data_Counter < (uint16)CML_u_UNSIGNED_16BIT_QUANT_SIZE) )
                   * Ensure correct quantization and avoid integer overflow (see detailed description below),
                   e.g., by setting f_encodeX = max(abs(x_i)) for all i and
                   f_encodeV = max(abs(v_i)) for all i

  \author          stefan.sauer@continental-corporation.com

  \testmethod  
  \traceability    
****************************************************************************/
extern void CML_v_encodeDataLSFQuant(CML_t_LeastSquareFit const *const p_LSFNonQuant, const float32 f_encodeX, const float32 f_encodeV, CML_t_LeastSquareFitQuant *const p_LSFQuant);

#endif /* #ifndef _CML_STAT_INCLUDED */


/** @} end defgroup */
