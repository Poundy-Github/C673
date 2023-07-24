/*! \file **********************************************************************

  COMPANY:                   Continental AG, A.D.C. GmbH

  CPU:                       CPU-Independent

  COMPONENT:                 CML (Common Math Library)

  MODULNAME:                 cml_const.h

  DESCRIPTION:               Constants used in the CML

  AUTHOR:                    D. Meschenmoser

  CREATION DATE:             12.09.2012

  VERSION:                   $Revision: 1.19.1.2 $

  ---*/ /*---
  CHANGES:                   $Log: cml_const.h  $
  CHANGES:                   Revision 1.19.1.2 2019/06/24 12:20:11CEST Reddy, Purushothama (uid33569) 
  CHANGES:                   updated with QAF warnings handled.
  CHANGES:                   Revision 1.19.1.1 2019/05/27 11:06:40CEST Thomas, Jyothy (uid22555) 
  CHANGES:                   MFC431TA19: QAF L4 fixes added
  CHANGES:                   Revision 1.19 2018/07/30 07:43:26CEST Kotre-EXT, Jeevan (uidk9586) 
  CHANGES:                   Floating point masks have been added.
  CHANGES:                   Revision 1.18 2018/07/16 13:07:32CEST Kotre-EXT, Jeevan (uidk9586) 
  CHANGES:                   LSF quantization constants have been added for 32 bit float numbers.
  CHANGES:                   Revision 1.17 2017/11/14 18:41:35CET Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   Updated to the code from AL_CML_01.09.13_INT-1
  CHANGES:                   Revision 1.16 2016/03/15 14:34:13CET Ulveland, Lars (uidt7777) 
  CHANGES:                   Added double precision constants used for a few critical operations.
  CHANGES:                   Revision 1.16 2016/03/15 14:34:13CET Ulveland, Lars (uidt7777) 
  CHANGES:                   Added double precision constants used for a few critical operations.
  CHANGES:                   Revision 1.16 2016/03/15 14:34:13CET Ulveland, Lars (uidt7777) 
  CHANGES:                   Added double precision constants used for a few critical operations.
  CHANGES:                   Revision 1.15 2015/10/02 16:08:49CEST Sauer, Stefan (uidg5644) 
  CHANGES:                   Add constant CML_s_SIGNED_16BIT_LOWER_LIMIT
  CHANGES:                   --- Added comments ---  uidg5644 [Oct 2, 2015 4:08:50 PM CEST]
  CHANGES:                   Change Package : 382619:1 http://mks-psad:7002/im/viewissue?selection=382619
  CHANGES:                   Revision 1.14 2015/05/19 13:36:06CEST Sauer, Stefan (uidg5644) 
  CHANGES:                   - added define for LSF quantization constants
  CHANGES:                   --- Added comments ---  uidg5644 [May 19, 2015 1:36:07 PM CEST]
  CHANGES:                   Change Package : 334078:1 http://mks-psad:7002/im/viewissue?selection=334078
  CHANGES:                   Revision 1.13 2014/11/10 08:59:20CET Schwarzkopf, Sebastian (uidg6516) 
  CHANGES:                   - added define for "nearly -0.0f"
  CHANGES:                   --- Added comments ---  uidg6516 [Nov 10, 2014 8:59:21 AM CET]
  CHANGES:                   Change Package : 266613:9 http://mks-psad:7002/im/viewissue?selection=266613
  CHANGES:                   Revision 1.12 2014/10/22 11:05:51CEST Davtjan, Grant (uidg3349) 
  CHANGES:                   move parameters to correct header
  CHANGES:                   --- Added comments ---  uidg3349 [Oct 22, 2014 11:05:52 AM CEST]
  CHANGES:                   Change Package : 266613:6 http://mks-psad:7002/im/viewissue?selection=266613
  CHANGES:                   Revision 1.11 2014/10/01 14:45:41CEST Davtjan, Grant (uidg3349) 
  CHANGES:                   add distance point 2 circle and distance point 2 clothoid computation from FCT to CML
  CHANGES:                   --- Added comments ---  uidg3349 [Oct 1, 2014 2:45:42 PM CEST]
  CHANGES:                   Change Package : 265242:1 http://mks-psad:7002/im/viewissue?selection=265242
  CHANGES:                   Revision 1.10 2014/05/27 09:45:44CEST Schwarzkopf, Sebastian (uidg6516) 
  CHANGES:                   - added define for sqrt(2)
  CHANGES:                   --- Added comments ---  uidg6516 [May 27, 2014 9:45:45 AM CEST]
  CHANGES:                   Change Package : 230040:4 http://mks-psad:7002/im/viewissue?selection=230040
  CHANGES:                   Revision 1.9 2014/04/07 10:29:37CEST Schwarzkopf, Sebastian (uidg6516) 
  CHANGES:                   - fixed erroneous include protection
  CHANGES:                   --- Added comments ---  uidg6516 [Apr 7, 2014 10:29:37 AM CEST]
  CHANGES:                   Change Package : 227281:3 http://mks-psad:7002/im/viewissue?selection=227281
  CHANGES:                   Revision 1.8 2014/03/27 11:22:11CET Schwarzkopf, Sebastian (uidg6516) 
  CHANGES:                   - fixed some QA-C- and Styleguide-issues
  CHANGES:                   --- Added comments ---  uidg6516 [Mar 27, 2014 11:22:11 AM CET]
  CHANGES:                   Change Package : 227281:2 http://mks-psad:7002/im/viewissue?selection=227281
  CHANGES:                   Revision 1.7 2014/02/04 15:10:16CET Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   - improve code quality
  CHANGES:                   --- Added comments ---  uidu0849 [Feb 4, 2014 3:10:17 PM CET]
  CHANGES:                   Change Package : 159154:34 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.6 2013/10/11 12:34:48CEST Fuentes, Juan-Carlos (uidu2446) 
  CHANGES:                   - added half pi to the constants.
  CHANGES:                   --- Added comments ---  uidu2446 [Oct 11, 2013 12:34:48 PM CEST]
  CHANGES:                   Change Package : 170691:89 http://mks-psad:7002/im/viewissue?selection=170691
  CHANGES:                   Revision 1.5 2013/05/06 14:46:47CEST Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   - reduce Lint/Misra warnings
  CHANGES:                   --- Added comments ---  uidu0849 [May 6, 2013 2:46:47 PM CEST]
  CHANGES:                   Change Package : 159154:28 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.4 2013/05/03 09:55:32CEST Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   - drop algo_common from CML
  CHANGES:                   - use new standard type names, e.g. float32 instead of f32_t
  CHANGES:                   --- Added comments ---  uidu0849 [May 3, 2013 9:55:33 AM CEST]
  CHANGES:                   Change Package : 159154:27 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.3 2013/04/15 08:38:47CEST Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   - Add constant CML_f_AlmostZero
  CHANGES:                   --- Added comments ---  uidu0849 [Apr 15, 2013 8:38:48 AM CEST]
  CHANGES:                   Change Package : 159154:25 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.2 2013/02/28 13:24:19CET Diewald, Fabian (uidt8878) 
  CHANGES:                   added LUT for RCS calculation
  CHANGES:                   --- Added comments ---  uidt8878 [Feb 28, 2013 1:24:19 PM CET]
  CHANGES:                   Change Package : 176321:1 http://mks-psad:7002/im/viewissue?selection=176321
  CHANGES:                   Revision 1.1 2012/09/14 14:31:02CEST Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/CML_CommonMathLibrary/04_Engineering/01_Source_Code/algo/cml/project.pj

**************************************************************************** */

/**
@defgroup const CONST (constants used in the CML)
  @ingroup cml
@{ */

/*****************************************************************************
  INCLUDE PROTECTION
*****************************************************************************/
#ifndef CML_CONST_INCLUDED
#define CML_CONST_INCLUDED

/* allow inclusion of cml sub-headers only if external cml header is included */
#ifndef CML_EXT_INCLUDED
  #pragma message(__FILE__": Inclusion of cml_const.h is discouraged. Include cml_ext.h instead.")
#endif /* #ifdef CML_EXT_INCLUDED */

/*****************************************************************************
  CONSTANTS
*****************************************************************************/
#define CML_f_Delta (0.0001F)              ///< Delta threshold value for 32 bit floating point equality tests 
#define CML_f_AlmostZero (1e-15f)          ///< 'Almost Zero' value for the floating point comparison tests for positive numbers
#define CML_f_AlmostNegZero (-1e-15f)      ///< 'Almost Zero' value for the floating point comparison tests for negative numbers

// GDB_SUBS_VAL_FOR_LOG_OF_ZERO
#define CML_f_SubsForLogOfZero (-999.0f)   ///< Substitute for log(0) = -Inf 


#define CML_f_Pi 3.14159265359f            ///< Holds the value of the mathematical constant Pi in 32 bit floating point to be used in all calculations

#define CML_d_Pi (3.1415926535897932)      ///< Holds the value of the mathematical constant Pi in double to be used in calculations

/*! 2 * pi */
#define CML_f_two_Pi (6.283185307f)        ///< Holds the value of two times the mathematical constant Pi in 32 bit floating point to be used in all calculations


#define CML_d_Two_Pi (6.2831853071795685)  ///< Holds the value of two times the mathematical constant Pi in double to be used in calculations


/*! pi / 2 */
#define CML_f_Half_Pi (1.5707964f)         ///< Holds half the value of the mathematical constant Pi in 32 bit floating point to be used in all calculations

#define CML_d_Pi_Half (1.5707963267948966) ///< Holds half the value of the mathematical constant Pi in double to be used in calculations


#define CML_d_ThreeHalf_Pi (4.7123889803846899) ///< Holds one and a half times the value of the mathematical constant Pi in double to be used in calculations

/*! sqrt(2) */
#define CML_f_Sqrt_Two (1.4142136f)       ///< Holds the value of square root of two.

/*! km/h <-> m/s */
#define CML_f_Kmh2Ms 3.6f                ///< Conversion constant for converting value from Km/hr to m/s and vice versa


#define CML_s_LUT_DB_LENGTH   (256L)                   ///< resolution of lookup table for dB->lin 
#define CML_s_LUT_DB_MIN_IND  (1L)                     ///< min index value for the dB->lin lookup table 
#define CML_s_LUT_DB_MAX_IND  (CML_s_LUT_DB_LENGTH-1L) ///< max index value for the dB->lin lookup table 
#define CML_f_LUT_DB_RES      (0.5f)                   ///< resolution of the dB->lin lookup table 
#define CML_f_LUT_DB_MINVAL   (-40.0f)                 ///< min input value for the dB->lin lookup table 


/*   Usage: ---> allocate LUT: 
          static const float32 af_LutDB[CML_s_LUT_DB_LENGTH] = CML_af_LUT_DB;
          ---> to get a linear value from dB:
          sint32 s_Ind       = CML_s_GetLutIndex(<f_RcsInDB>, CML_f_LUT_DB_MINVAL, CML_f_LUT_DB_RES, CML_s_LUT_DB_MIN_IND, CML_s_LUT_DB_MAX_IND);
          float32 f_RcsLinear = af_LutDB[s_Ind];
          ---> to get a dB value from linear:
          sint32 s_IndBack   = CML_s_GetLutIndexBackwards(<f_RcsLinear>, af_LutDB, CML_s_LUT_DB_MIN_IND, CML_s_LUT_DB_MAX_IND);
          float32 f_RcsDB     = CML_f_LUT_DB_MINVAL + ((s_IndBack-CML_s_LUT_DB_MIN_IND) * CML_f_LUT_DB_RES); */
#define CML_af_LUT_DB         \
{\
  0.f,            0.0001000000f,  0.0001122018f,  0.0001258925f,  0.0001412538f,  0.0001584893f,  0.0001778279f,  0.0001995262f,  0.0002238721f,  0.0002511886f,\
  0.0002818383f,  0.0003162278f,  0.0003548134f,  0.0003981072f,  0.0004466836f,  0.0005011872f,  0.0005623413f,  0.0006309574f,  0.0007079458f,  0.0007943282f,\
  0.0008912510f,  0.001000000f,   0.001122018f,   0.001258925f,   0.001412538f,   0.001584893f,   0.001778279f,   0.001995262f,   0.002238721f,   0.002511886f,\
  0.002818383f,   0.003162278f,   0.003548134f,   0.003981072f,   0.004466836f,   0.005011872f,   0.005623413f,   0.006309574f,   0.007079458f,   0.007943282f,\
  0.008912509f,   0.01000000f,    0.01122018f,    0.01258925f,    0.01412538f,    0.01584893f,    0.01778279f,    0.01995262f,    0.02238721f,    0.02511887f,\
  0.02818383f,    0.03162277f,    0.03548134f,    0.03981072f,    0.04466836f,    0.05011872f,    0.05623413f,    0.06309573f,    0.07079457f,    0.07943282f,\
  0.08912510f,    0.1000000f,     0.1122018f,     0.1258925f,     0.1412538f,     0.1584893f,     0.1778279f,     0.1995262f,     0.2238721f,     0.2511886f,\
  0.2818383f,     0.3162278f,     0.3548134f,     0.3981072f,     0.4466836f,     0.5011872f,     0.5623413f,     0.6309574f,     0.7079458f,     0.7943282f,\
  0.8912509f,     1.f,            1.122018f,      1.258925f,      1.412538f,      1.584893f,      1.778279f,      1.995262f,      2.238721f,      2.511886f,\
  2.818383f,      3.162278f,      3.548134f,      3.981072f,      4.466836f,      5.011872f,      5.623413f,      6.309574f,      7.079458f,      7.943282f,\
  8.912509f,      10.f,           11.22018f,      12.58925f,      14.12538f,      15.84893f,      17.78279f,      19.95262f,      22.38721f,      25.11886f,\
  28.18383f,      31.62278f,      35.48134f,      39.81072f,      44.66836f,      50.11872f,      56.23413f,      63.09573f,      70.79458f,      79.43282f,\
  89.12509f,      100.f,          112.2018f,      125.8925f,      141.2538f,      158.4893f,      177.8279f,      199.5262f,      223.8721f,      251.1886f,\
  281.8383f,      316.2278f,      354.8134f,      398.1072f,      446.6836f,      501.1872f,      562.3413f,      630.9573f,      707.9458f,      794.3282f,\
  891.2509f,      1000.f,         1122.018f,      1258.925f,      1412.538f,      1584.893f,      1778.279f,      1995.262f,      2238.721f,      2511.886f,\
  2818.383f,      3162.278f,      3548.134f,      3981.072f,      4466.836f,      5011.873f,      5623.413f,      6309.573f,      7079.458f,      7943.282f,\
  8912.510f,      10000.f,        11220.18f,      12589.25f,      14125.38f,      15848.93f,      17782.79f,      19952.62f,      22387.21f,      25118.87f,\
  28183.83f,      31622.78f,      35481.34f,      39810.72f,      44668.36f,      50118.72f,      56234.13f,      63095.73f,      70794.58f,      79432.82f,\
  89125.09f,      100000.f,       112201.8f,      125892.5f,      141253.8f,      158489.3f,      177827.9f,      199526.2f,      223872.1f,      251188.6f,\
  281838.3f,      316227.8f,      354813.4f,      398107.2f,      446683.6f,      501187.2f,      562341.3f,      630957.4f,      707945.8f,      794328.3f,\
  891250.9f,      1000000.f,      1122019.f,      1258925.f,      1412538.f,      1584893.f,      1778279.f,      1995262.f,      2238721.f,      2511887.f,\
  2818383.f,      3162278.f,      3548134.f,      3981072.f,      4466836.f,      5011873.f,      5623414.f,      6309574.f,      7079458.f,      7943283.f,\
  8912509.f,      10000000.f,     11220185.f,     12589254.f,     14125375.f,     15848932.f,     17782794.f,     19952624.f,     22387212.f,     25118864.f,\
  28183830.f,     31622776.f,     35481340.f,     39810716.f,     44668360.f,     50118724.f,     56234132.f,     63095736.f,     70794576.f,     79432824.f,\
  89125096.f,     100000000.f,    112201848.f,    125892544.f,    141253760.f,    158489312.f,    177827936.f,    199526224.f,    223872112.f,    251188640.f,\
  281838304.f,    316227776.f,    354813376.f,    398107168.f,    446683584.f,    501187232.f\
} ///< Lookup table for linear amplitude values, first value is zero, second corresponds to CML_f_LUT_DB_MINVAL. 


#define CML_u_UNSIGNED_16BIT_QUANT_SIZE               (65535u)  ///< constant 2^16-1 for Least Squares Fit (LSF) data quantization

#define CML_u_SIGNED_16BIT_QUANT_SIZE                 (32767u)  ///< constant 2^15-1 for Least Squares Fit (LSF) data quantization 

#define CML_s_SIGNED_16BIT_LOWER_LIMIT                (-32768)  ///< constant -2^15 for Least Squares Fit (LSF) data quantization 

/*! threshold (~ 2^32-1) for Least Squares Fit (LSF) data quantization */
#define CML_f_UNSIGNED_32BIT_QUANT_SIZE               (4.29496704e9f)
/*! threshold (~ 2^31-1) for Least Squares Fit (LSF) data quantization */
#define CML_f_SIGNED_32BIT_QUANT_SIZE                 (2.14748352e9f)
/*! threshold (~ -2^31+1) for Least Squares Fit (LSF) data quantization */
#define CML_f_SIGNED_32BIT_LOWER_LIMIT                (-2.14748352e9f)

#ifndef Percentage_min
  #define Percentage_min (0U)     ///< Minimum percentage value
#endif
#ifndef Percentage_max
  #define Percentage_max (100U)   ///< Maximum percentage value
#endif

#define FLOAT_EXP_MASK    0x7F800000U  /*!< mask for exponent in single precision float */
#define FLOAT_MANT_MASK   0x007FFFFFU  /*!< mask for mantissa in single precision float */
#define FLOAT_EXP_SHIFT   23          /*!< shift value for exponent in single precision float */
#define FLOAT_EXP_OFFSET  127          /*!< offset of exponent in single precision float */
#define FLOAT_ZERO_HEX    0x3F800000U  /*!< hexadecimal representation of 0.0f */

#define FLOAT_NEG_INF 0xFF800000UL  /* float representation for (-inf) */
#define FLOAT_NEG_NAN 0xFFC00000UL  /* float representation for (-NAN) */

#define NOF_LOG2_POLY_ELEMENTS 8  /* polynome size for calculation of CML_f_log2() */

#define ONE_OVER_LOG2_OF_10 0.301029995663981f /*!< 1.0 / log2(10) */
#define ONE_OVER_LOG2_OF_E  0.693147180559945f /*!< 1.0 / log2(e) */

#endif /* #ifndef CML_CONST_INCLUDED */


/** @} end defgroup */
