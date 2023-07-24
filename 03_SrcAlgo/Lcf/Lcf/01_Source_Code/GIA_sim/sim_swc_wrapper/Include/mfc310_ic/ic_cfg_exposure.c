//  ==========================================================================================
//  The following QAC messages are suppressed for this module:
//
//  We intentionally have several data structures on file scope, even when they are used
//  only in one function:
//    PRQA S 3218 EOF

#include "ic_cfg.h"
#include "ic_cfg_exposure.h"

static const IC_S_HistogramBinParams ICCFG_cs_HistBinParams = {
    {
      32,96,160,224,288,352,416,480,544,608,672,736,800,864,928,992,1056,1120,1184,1248,1312,1376,
      1440,1504,1568,1632,1696,1760,1824,1888,1952,2016,2080,2144,2208,2272,2336,2400,2464,2528,
      2592,2656,2720,2784,2848,2912,2976,3040,3104,3168,3232,3296,3360,3424,3488,3552,3616,3680,
      3744,3808,3872,3936,4000,4064,4352,4864,5376,5888,6400,6912,7424,7936,8448,8960,9472,9984,
      10496,11008,11520,12032,12544,13056,13568,14080,14592,15104,15616,16128,16640,17152,17664,
      18176,18688,19200,19712,20224,20736,21248,21760,22272,22784,23296,23808,24320,24832,25344,
      25856,26368,26880,27392,27904,28416,28928,29440,29952,30464,30976,31488,32000,32512,33024,
      33536,34048,34560,35072,35584,36096,36608,37120,37632,38144,38656,39168,39680,40192,40704,
      41216,41728,42240,42752,43264,43776,44288,44800,45312,45824,46336,46848,47360,47872,48384,
      48896,49408,49920,50432,50944,51456,51968,52480,52992,53504,54016,54528,55040,55552,56064,
      56576,57088,57600,58112,58624,59136,59648,60160,60672,61184,61696,62208,62720,63232,63744,
      64256,64768,65280,73728,90112,106496,122880,139264,155648,172032,188416,204800,221184,
      237568,253952,270336,286720,303104,319488,335872,352256,368640,385024,401408,417792,434176,
      450560,466944,483328,499712,516096,532480,548864,565248,581632,598016,614400,630784,647168,
      663552,679936,696320,712704,729088,745472,761856,778240,794624,811008,827392,843776,860160,
      876544,892928,909312,925696,942080,958464,974848,991232,1007616,1024000,1040384
    }
};

// Weighting-table for the imager's 244 histogram-bins (statistics data): Unity
//
// This table is currently unsused, but it's kept here for testing purposes:
//   PRQA S 3207 2
static const IC_S_HistogramWeights ICCFG_cs_HistWeights_Unity = {
    {
      1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,
      1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,
      1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,
      1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,
      1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,
      1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,
      1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,
      1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,
      1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,
      1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,
      1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,
      1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,
      1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,
      1000,1000,1000,1000,1000,1000,1000,1000,1000,1000
    }
};

// Weighting-table for the imager's 244 histogram-bins (statistics data): 4x/16x characteristic (alternative 2)
static const IC_S_HistogramWeights ICCFG_cs_HistWeights_4x16x = {
    {
      1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000,
      1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000,
      1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000,
      1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000,
      992, 985, 977, 969, 962, 954, 946, 938, 931, 923, 915, 908, 900, 892, 885, 877, 869, 862, 854,
      846, 838, 831, 823, 815, 808, 800, 792, 785, 777, 769, 762, 754, 746, 738, 731, 723, 715, 708,
      700, 692, 685, 677, 669, 662, 654, 646, 638, 631, 623, 615, 608, 600, 592, 585, 577, 569, 562,
      554, 546, 538, 531, 523, 515, 508, 500, 492, 485, 477, 469, 462, 454, 446, 438, 431, 423, 415,
      408, 400, 392, 385, 377, 369, 362, 354, 346, 338, 331, 323, 315, 308, 300, 292, 285, 277, 269,
      262, 254, 246, 238, 231, 223, 215, 208, 200, 192, 185, 177, 169, 162, 154, 146, 138, 131, 123,
      115, 108, 100, 92, 85, 77, 69, 62, 54, 46, 38, 31, 23, 15, 8, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
      1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
      1, 1, 1, 1, 1, 1, 1, 1
    }
};

// Weighting-table for the imager's 244 histogram-bins (statistics data): 16x/16x characteristic
static const IC_S_HistogramWeights ICCFG_cs_HistWeights_16x16x = {
    {
      1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,
      1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,995,990,986,981,976,
      971,967,962,957,952,948,943,938,933,929,924,919,914,910,905,900,895,890,886,881,876,871,
      867,862,857,852,848,843,838,833,829,824,819,814,810,805,800,795,790,786,781,776,771,767,
      762,757,752,748,743,738,733,729,724,719,714,710,705,700,695,690,686,681,676,671,667,662,
      657,652,648,643,638,633,629,624,619,614,610,605,600,595,590,586,581,576,571,567,562,557,
      552,548,543,538,533,529,524,519,514,510,505,500,495,490,486,481,476,471,467,462,457,452,
      448,443,438,433,429,424,419,414,410,405,400,395,390,386,381,376,371,367,362,357,352,348,
      343,338,333,329,324,319,314,310,305,300,295,290,286,281,276,271,267,262,257,252,248,243,
      238,233,229,224,219,214,210,205,200,195,190,186,181,176,171,167,162,157,152,148,143,138,
      133,129,124,119,114,110,105,100,95,90,86,81,76,71,67,62,57,52,48,43,38,33,29,24,19,14,10,
      5,1,1,1
    }
};

void ICCFG_v_GetExposureSettings(ICEXP_S_Settings * const ps_Settings, const IC_E_FRAMETYPE e_FrameType)
{
    // We have many magic numbers here, intentionally of course:
    // PRQA S 3120,3121,3227 GET_EXPOSURE_SETTINGS

    /************************************************************************************/
    //                           Settings for both frame-types                          //
    /************************************************************************************/
    // PRQA S 0506 1
    ps_Settings->b_ForceNightMode             = b_FALSE;
    ps_Settings->b_UseWeightedMean            = b_TRUE;
    ps_Settings->e_DCGControl                 = ICEXP_e_DCGMODE_AUTO;
    ps_Settings->e_LumaFilterMode             = ICEXP_e_FILTER_BARATOFFSCH_ROTH;
    ps_Settings->f32_Attenuation              = 0.8f;
    ps_Settings->ps_HistWeights_4x16x         = &ICCFG_cs_HistWeights_4x16x;
    ps_Settings->ps_HistWeights_16x16x        = &ICCFG_cs_HistWeights_16x16x;
    ps_Settings->ps_HistBinParams             = &ICCFG_cs_HistBinParams;
    ps_Settings->aui16_LumaAveragerWeights[0] = 1;
    ps_Settings->aui16_LumaAveragerWeights[1] = 0;
    ps_Settings->aui16_LumaAveragerWeights[2] = 0;
    ps_Settings->ui16_LumaFilterDepth         = 3;
    ps_Settings->ui32_LineTimeNs              = ICCFG_cui32_LineTimeNs;
    ps_Settings->ui16_MaxPossibleT2us         = (uint16)((float32)ICCFG_cui16_MaxT2lines  * ICCFG_cf32_LineTimeUs);  // PRQA S 4119
    ps_Settings->ui16_MaxPossibleT3us         = (uint16)((float32)ICCFG_cui16_MaxT3pixClk * ICCFG_cf32_PixelTimeUs); // PRQA S 4119

    /************************************************************************************/
    //                   Settings for odd/long frame (MASTER-Frame)                     //
    /************************************************************************************/
    if (IC_e_FRAMETYPE_ODD == e_FrameType)
    {
        ps_Settings->f32_TargetLuma                        = 1000.0f;
        ps_Settings->ui16_LumaMinNoControl                 = 800;
        ps_Settings->ui16_LumaMaxNoControl                 = 1200;
        ps_Settings->ui16_MaxExposureT1us                  = 18750;
        ps_Settings->ui16_MinExposureT1us                  = 260;
        ps_Settings->ui16_CriticalMaxTotalExposureUs       = 30000; /* lines2us(frame_length_lines - 1) */
        ps_Settings->ui16_CriticalMinTotalExposureUs       = 260;
        ps_Settings->ui16_DCGThresholdHighUs               = 7033;
        ps_Settings->ui16_DCGThresholdLowUs                = 2000;
        ps_Settings->e_SlopeSwitchingMode                  = ICEXP_e_SLOPE_SWITCH_BY_INTRADAYSTATE;
        ps_Settings->ui16_SlopeRatioSwitchThresT1UsHigh    = 0; /* Unused in this mode */
        ps_Settings->ui16_SlopeRatioSwitchThresT1UsLow     = 0; /* Unused in this mode */
        ps_Settings->ui16_IntegrationTimeRatioR1           = 0; /* Unused in this mode */
        ps_Settings->ui16_IntegrationTimeRatioR2           = 0; /* Unused in this mode */

        ps_Settings->e_NightModeCondition                  = ICEXP_e_NIGHTMODECOND_USE_MEANLOW;
        ps_Settings->f32_IntradayThresDay_PercLowEndMin    = 0.50f;
        ps_Settings->f32_IntradayThresNightPercLowEndMin   = 0.70f;
        ps_Settings->ui16_IntradayThresDay_LowEndMeanMax   = 740;
        ps_Settings->ui16_IntradayThresDay_LumaMax         = 1500;
        ps_Settings->ui16_IntradayThresNight_LowEndMeanMax = 600;
        ps_Settings->ui16_IntradayThresDay_Frames          = 2;
        ps_Settings->ui16_IntradayThresNight_Frames        = 2;
    }

    /************************************************************************************/
    //                        Settings for even/short frame                             //
    /************************************************************************************/
    if (IC_e_FRAMETYPE_EVEN == e_FrameType)
    {
        ps_Settings->f32_TargetLuma                        = 2000.0f;
        ps_Settings->ui16_LumaMinNoControl                 = 1600;
        ps_Settings->ui16_LumaMaxNoControl                 = 2400;
        ps_Settings->ui16_MaxExposureT1us                  = 5930;
        ps_Settings->ui16_MinExposureT1us                  = 795;
        ps_Settings->ui16_CriticalMaxTotalExposureUs       = 17965; /* lines2us(frame_length_lines - 1) */
        ps_Settings->ui16_CriticalMinTotalExposureUs       = 260;
        ps_Settings->e_SlopeSwitchingMode                  = ICEXP_e_SLOPE_SWITCH_FIXED;
        ps_Settings->ui16_IntegrationTimeRatioR1           = 4;
        ps_Settings->ui16_IntegrationTimeRatioR2           = 16;
        ps_Settings->ui16_DCGThresholdHighUs               = 5900;
        ps_Settings->ui16_DCGThresholdLowUs                = 1800;

        ps_Settings->e_NightModeCondition                  = ICEXP_e_NIGHTMODECOND_ALWAYS_DAY;
        ps_Settings->f32_IntradayThresDay_PercLowEndMin    = 0.00f; /* Unused in this mode */
        ps_Settings->f32_IntradayThresNightPercLowEndMin   = 0.00f; /* Unused in this mode */
        ps_Settings->ui16_IntradayThresDay_LowEndMeanMax   = 0; /* Unused in this mode */
        ps_Settings->ui16_IntradayThresDay_LumaMax         = 0; /* Unused in this mode */
        ps_Settings->ui16_IntradayThresNight_LowEndMeanMax = 0; /* Unused in this mode */
        ps_Settings->ui16_IntradayThresDay_Frames          = 0; /* Unused in this mode */
        ps_Settings->ui16_IntradayThresNight_Frames        = 0; /* Unused in this mode */
    }

    // PRQA L:GET_EXPOSURE_SETTINGS
    // PRQA S 7001 3
}
