//* **********************************************************************
//  COMPANY:         $CompanyInfo: CONFIDENTIAL AND PROPRIETARY PROPERTY OF CONTINENTAL AG , A.D.C. GmbH  -  ALL RIGHTS RESERVED $
//  
//  PROJECT:         MFC30x_MCU
//  CPU:             MPC5675K
//  
//  PACKAGE:         $Source: ic_exposure.h $ $Revision: 1.1 $
//  MKS Date:        $Date: 2021/12/13 17:25:53CET $
//  
//  RHAPSODY:        7.5.3
//  COMPONENT:       IC
//  CONFIGURATION:   DefaultConfig
//  MODEL ELEMENT:   ic_exposure
//  MODULNAME:       ..\..\..\04_Engineering\01_Source_Code\Algo\ic\ic_exposure.h
//  LOGIN:           uidt3974  
//  
//  The Imager Control Exposure Control module (ICEXP) is the core algorithmic module which implements
//  image brightness regulation. It processes inputs based on statistical image data and current imager
//  settings to determine new settings which have to be written to the imager. Inputs include, but are
//  not limited to:
//    - Input image exposure time (T1)
//    - Input image histogram data
//    - Input image integration time ratios (R1, R2)
//    - Input image DCG state
//    - Other statistical data from input image
//  
//  The following outputs are generated:
//    - Exposure Time (T1)
//    - Integration Time Ratios (R1, R2)
//    - DCG state (Dual Conversion Gain)
//    - Digital Gain
//  
//  The module calculates also some additional results which can be passed to algos or used for
//  FuSi/plausibility checks. This includes:
//    - Fraction of saturated pixels
//    - Number of total values/pixels contained in the histogram
//    - Weighted mean value (see below)
//  
//  Almost every function() works on instance objects of type ICEXP_S_Object, which are fully independent
//  of each other. This allows to handle multiple object instances for independent frame types with
//  different control settings. Before using an object, it must be initialized and configured by calling:
//    1) ICEXP_v_Init()
//    2) ICEXP_e_SetControlParameters()
//  
//  Typical cyclic usage is the following sequence:
//    1) ICEXP_e_SetControlInput()   - Provide input values to the ICEXP
//    2) ICEXP_e_RunControl()        - Execute calculation and get results
//    3) ICEXP_e_MeasFreezeBuffer()  - Get measurement data for MTS
//  
//  
//  Some special topics are addressed in separate sections here:
//  
//  
//  =======================================================================================
//  |             FORCED DCG OVERWRITE (dual conversion gain) / COMPENSATATION            |
//  =======================================================================================
//  The imagers used in the MFC3xx project have a feature called 'column FPN correction' (FPN=fixed
//  pattern noise). This corrects column noise resulting from a fixed column offset. However,
//  this correction drifts over temperature, so it has to be repeated when the imager temperature
//  changes significantly. After image streaming is enabled, the imager can only be forced to
//  do a 'column FPN correction' by switching the DCG.
//  
//  This is where forced DCG comes into place. It forces the Exposure Control to set the DCG
//  to a specific value. To prevent changing image brightness due to a DCG switch, the ICEXP
//  compensates this by adapting exposure time and digital gain.
//  
//  A DCG overwrite can be done by calling ICEXP_v_OverwriteDcgOutputCompensated(). This setting
//  lasts only one cycle and will be reset on next call to ICEXP_e_RunControl().
//  
//  See Exposure Manager module description for additional infos.
//  
//  
//  =======================================================================================
//  |            MEAN, WEIGHTED MEAN, LOW-END MEAN ... what does all this mean?           |
//  =======================================================================================
//  The mean values are some kind of 'average' grayvalues calculated from pixels within the ICROI.
//  The calculation differs for each type of 'MEAN', so not all of them are 'true' means. Here are
//  some explanations:
//  
//  1) The MEAN (or 'NORMAL MEAN' or 'IMAGER MEAN') is automatically calculated by the imager.
//     It is the true mean/average value of all Gr pixels within the ICROI and put into the statistics
//     data.
//  2) The 'LOW-END MEAN' is the mean grayvalue of all pixels within the ICROI, which are in the
//     LOW END of the histogram (i.e. below a specific histogram bin). Other pixels above that threshold
//     are not considered when calculating that mean. The value which divides the histogram into
//     low/high end can be configured though an imager register. This value is calculated in
//     the imager and also part of the statistics data.
//  3) The 'WEIGHTED MEAN' is calculated in software by using the histogram. Each histogram bin
//     is weighted by a custom value defined in an array referenced in the ICEXP control parameters.
//     See ICEXP_ui32_CalcLumaFromHist().
//  
//  
//  =======================================================================================
//  |                                     INTRADAY STATE                                  |
//  =======================================================================================
//  The Intraday State (sometimes also referred to as 'nightflag') is a status flag, which indicates
//  if we have daylight or night. It uses a metric based on the LOW-END MEAN (see chapter above),
//  the 'PercLowEnd' and current imager settings. The 'PercLowEnd' is the percentage of pixels which
//  are in the LOW-END of the histogram (see LOW-END MEAN above). The metric is decribed in
//  'IC_spec_BSB_stereo_work.VSD', sheet 'Short_Nightflag' (see controlled files).
//  
//  The Intraday State is used to change imager integration time ratios R1=T1/T2 and R2=T2/T3, if
//  control parameter value 'e_SlopeSwitchingMode' is set to 'ICEXP_e_SLOPE_SWITCH_BY_INTRADAYSTATE'.
//  
//  The Intraday State can also be passed to other algos (HLA), which may use it for different decisions.
//  
//  
//  ==========================================================================================
//  The following QAC messages are suppressed for this module:
//  
//    The parameter 'xxxx' is never modified and so it could be declared with the 'const' qualifier.
//        PRQA S 3227 EOF
//  
//    'xxxx' is being used as a structure/union member as well as being a label, tag or ordinary identifier.
//        PRQA S 0781,0783 EOF
//  
//    Magic numbers with 0.0f and 1.0f are OK according to QAC documentation, however the tool
//    has a bug and gives a warning in both cases:
//      Hard-coded 'magic' floating constant '0.0f' and
//      Hard-coded 'magic' floating constant '1.0f'
//  
//      PRQA S 3121 EOF
//  
//  
//  AUTHOR:          $Author: Wang, David (Wangd3) $
//! CREATION DATE:   Mon, 16, Jul 2012  11:12 W. Europe Daylight Time AM 
//**************************************************************************** */

#ifndef ic_exposure_H
#define ic_exposure_H

/*## dependency ic_types */
#include "ic_types.h"
/*## package Ic_Pkg */

/*## class TopLevel::ic_exposure */
/*#[ ignore */
//  The Imager Control Exposure Control module (ICEXP) is the core algorithmic module which implements
//  image brightness regulation. It processes inputs based on statistical image data and current imager
//  settings to determine new settings which have to be written to the imager. Inputs include, but are
//  not limited to:
//    - Input image exposure time (T1)
//    - Input image histogram data
//    - Input image integration time ratios (R1, R2)
//    - Input image DCG state
//    - Other statistical data from input image
//  
//  The following outputs are generated:
//    - Exposure Time (T1)
//    - Integration Time Ratios (R1, R2)
//    - DCG state (Dual Conversion Gain)
//    - Digital Gain
//  
//  The module calculates also some additional results which can be passed to algos or used for
//  FuSi/plausibility checks. This includes:
//    - Fraction of saturated pixels
//    - Number of total values/pixels contained in the histogram
//    - Weighted mean value (see below)
//  
//  Almost every function() works on instance objects of type ICEXP_S_Object, which are fully independent
//  of each other. This allows to handle multiple object instances for independent frame types with
//  different control settings. Before using an object, it must be initialized and configured by calling:
//    1) ICEXP_v_Init()
//    2) ICEXP_e_SetControlParameters()
//  
//  Typical cyclic usage is the following sequence:
//    1) ICEXP_e_SetControlInput()   - Provide input values to the ICEXP
//    2) ICEXP_e_RunControl()        - Execute calculation and get results
//    3) ICEXP_e_MeasFreezeBuffer()  - Get measurement data for MTS
//  
//  
//  Some special topics are addressed in separate sections here:
//  
//  
//  =======================================================================================
//  |             FORCED DCG OVERWRITE (dual conversion gain) / COMPENSATATION            |
//  =======================================================================================
//  The imagers used in the MFC3xx project have a feature called 'column FPN correction' (FPN=fixed
//  pattern noise). This corrects column noise resulting from a fixed column offset. However,
//  this correction drifts over temperature, so it has to be repeated when the imager temperature
//  changes significantly. After image streaming is enabled, the imager can only be forced to
//  do a 'column FPN correction' by switching the DCG.
//  
//  This is where forced DCG comes into place. It forces the Exposure Control to set the DCG
//  to a specific value. To prevent changing image brightness due to a DCG switch, the ICEXP
//  compensates this by adapting exposure time and digital gain.
//  
//  A DCG overwrite can be done by calling ICEXP_v_OverwriteDcgOutputCompensated(). This setting
//  lasts only one cycle and will be reset on next call to ICEXP_e_RunControl().
//  
//  See Exposure Manager module description for additional infos.
//  
//  
//  =======================================================================================
//  |            MEAN, WEIGHTED MEAN, LOW-END MEAN ... what does all this mean?           |
//  =======================================================================================
//  The mean values are some kind of 'average' grayvalues calculated from pixels within the ICROI.
//  The calculation differs for each type of 'MEAN', so not all of them are 'true' means. Here are
//  some explanations:
//  
//  1) The MEAN (or 'NORMAL MEAN' or 'IMAGER MEAN') is automatically calculated by the imager.
//     It is the true mean/average value of all Gr pixels within the ICROI and put into the statistics
//     data.
//  2) The 'LOW-END MEAN' is the mean grayvalue of all pixels within the ICROI, which are in the
//     LOW END of the histogram (i.e. below a specific histogram bin). Other pixels above that threshold
//     are not considered when calculating that mean. The value which divides the histogram into
//     low/high end can be configured though an imager register. This value is calculated in
//     the imager and also part of the statistics data.
//  3) The 'WEIGHTED MEAN' is calculated in software by using the histogram. Each histogram bin
//     is weighted by a custom value defined in an array referenced in the ICEXP control parameters.
//     See ICEXP_ui32_CalcLumaFromHist().
//  
//  
//  =======================================================================================
//  |                                     INTRADAY STATE                                  |
//  =======================================================================================
//  The Intraday State (sometimes also referred to as 'nightflag') is a status flag, which indicates
//  if we have daylight or night. It uses a metric based on the LOW-END MEAN (see chapter above),
//  the 'PercLowEnd' and current imager settings. The 'PercLowEnd' is the percentage of pixels which
//  are in the LOW-END of the histogram (see LOW-END MEAN above). The metric is decribed in
//  'IC_spec_BSB_stereo_work.VSD', sheet 'Short_Nightflag' (see controlled files).
//  
//  The Intraday State is used to change imager integration time ratios R1=T1/T2 and R2=T2/T3, if
//  control parameter value 'e_SlopeSwitchingMode' is set to 'ICEXP_e_SLOPE_SWITCH_BY_INTRADAYSTATE'.
//  
//  The Intraday State can also be passed to other algos (HLA), which may use it for different decisions.
//  
//  
//  ==========================================================================================
//  The following QAC messages are suppressed for this module:
//  
//    The parameter 'xxxx' is never modified and so it could be declared with the 'const' qualifier.
//        PRQA S 3227 EOF
//  
//    'xxxx' is being used as a structure/union member as well as being a label, tag or ordinary identifier.
//        PRQA S 0781,0783 EOF
//  
//    Magic numbers with 0.0f and 1.0f are OK according to QAC documentation, however the tool
//    has a bug and gives a warning in both cases:
//      Hard-coded 'magic' floating constant '0.0f' and
//      Hard-coded 'magic' floating constant '1.0f'
//  
//      PRQA S 3121 EOF
/*#]*/


/*#[ ignore */

#ifdef __cplusplus
extern "C"
{
#endif

/*#]*/


//  Depth of the luma history buffer array, which is used by the luma filtering routines
/*#[ type ICEXP_cui_MAX_LUMA_FILTER_VALUES */
#define ICEXP_cui_MAX_LUMA_FILTER_VALUES 3u
/*#]*/

//  Enumeration of return-codes from the exposure control module
/*#[ type ICEXP_E_ERROR */
typedef enum {
    ICEXP_e_ERR_OK,
    ICEXP_e_ERR_PARAM_SLOPESWITCHMODE,
    ICEXP_e_ERR_MODULESTATE,
    ICEXP_e_ERR_NO_PARAMS_SET,
    ICEXP_e_ERR_NULLPOINTER,
    ICEXP_e_ERR_PARAM_ATTENUATION,
    ICEXP_e_ERR_PARAM_DCG_GAIN,
    ICEXP_e_ERR_PARAM_DCG_THRESHOLD,
    ICEXP_e_ERR_PARAM_LUMA_MINMAX_NC,
    ICEXP_e_ERR_PARAM_LUMAFILTER_DEPTH,
    ICEXP_e_ERR_MEASBUFFER_OVERRUN
}  ICEXP_E_ERROR;
/*#]*/

//  Current state of the exposure control module.
//  
//  ICEXP_e_STATE_CLOSED
//      Module is closed / not initialized
//  
//  ICEXP_e_STATE_INPUT
//      Module is waiting for inputs
//  
//  ICEXP_e_STATE_EXEC
//      Module has inputs and is waiting to be executed through ICEXP_e_RunControl()
/*#[ type ICEXP_E_MODULE_STATE */
typedef enum {
    ICEXP_e_STATE_CLOSED,
    ICEXP_e_STATE_INPUT,
    ICEXP_e_STATE_EXEC
}  ICEXP_E_MODULE_STATE;
/*#]*/

//  The control-behavior of the DCG (imager dual conversion gain):
//  
//  ICEXP_e_DCGMODE_ALWAYS_LOW
//      DCG is always set to LOW gain
//  
//  ICEXP_e_DCGMODE_ALWAYS_HIGH
//      DCG is always set to HIGH gain
//  
//  ICEXP_e_DCGMODE_AUTO
//      DCG is switched depending on exposure time. IC settings must provide two
//      thresholds - one for switching DCG to HIGH and another threshold for LOW.
/*#[ type ICEXP_E_DCG_CONTROLMODE */
typedef enum {
    ICEXP_e_DCGMODE_ALWAYS_LOW,
    ICEXP_e_DCGMODE_ALWAYS_HIGH,
    ICEXP_e_DCGMODE_AUTO
} ICEXP_E_DCG_CONTROLMODE;
/*#]*/

//  Luma filtering mode which determines how to filter lumas depending on the history values
//  of previous frames.
//  
//  NOTE: If a luma value from the history is chosen, we also take over the exposure time which
//  belongs to the same frame, because the luma is related to that exposure time. Mixing luma and
//  exposure time from different frames would produce bad effects like over-/undershot.
//  
//  ICEXP_e_FILTER_NONE
//      Luma value is not filtered at all - always use value from current frame
//  
//  ICEXP_e_FILTER_AVERAGE
//      Do a weighted running average over last N frames. Number of values involved can be parametrized,
//      for each tap there is also a weight to be set in the control parameters.
//  
//  ICEXP_e_FILTER_MEDIAN
//      Choose the 'median' value from last N frames. Number of values involved can be parametrized.
//  
//  ICEXP_e_FILTER_ROTH,
//      Luma filter 'roth' is used. This type of filter uses two values: Current and previous
//      luma. The output of the filter is determined by checking luma ranges. 'In range' means
//      the image brightness is good (within limits) and the ICEXP would not change exposure
//      time. This filter implements the following rules:
//         
//        OutOfRange('current') AND InRange('previous') ==> Use 'previous'
//        else                                          ==> Use 'current'
//  
//      In Words: If the current value is not in range but the previous value was OK, then use
//      the previous luma. This prevents unnecessary changes of the exposure time due to single
//      frame image brightness changes issued by a wiper, which covers the imager.
//  
//  ICEXP_e_FILTER_BARATOFFSCH_ROTH
//      This filter uses the same condition for selecting the 'previous' value as the ROTH filter,
//      but it adds another condition:
//  
//        OutOfRange('current') AND InRange('previous')     ==> Use 'previous'
//        LumaTooLow('current') AND LumaTooHigh('previous') ==> Use 'previous'
//        else                                              ==> Use 'current'
//  
//      This improves the behaviour of the 'ROTH' wiper filter in case value N and N-1 are both
//      out of range.
/*#[ type ICEXP_E_FILTER_MODE */
typedef enum {
    ICEXP_e_FILTER_NONE,
    ICEXP_e_FILTER_AVERAGE,
    ICEXP_e_FILTER_MEDIAN,
    ICEXP_e_FILTER_ROTH,
    ICEXP_e_FILTER_BARATOFFSCH_ROTH
} ICEXP_E_FILTER_MODE;
/*#]*/

//  Determines the condition for switching imager integration time ratios.
//  
//  ICEXP_e_SLOPE_SWITCH_FIXED
//      The integration time ratios are always fixed and must be provided by the exposure
//      control parameters 'ui16_IntegrationTimeRatioR*'
//  
//  ICEXP_e_SLOPE_SWITCH_BY_T1THRES
//      The integration time ratios are switched depending on T1 (coarse integration time).
//      Thresholds have to be provided in the exposure control parameters:
//  
//      T1 > 'ThresholdHigh'  ==>   R1=16
//      T1 < 'ThresholdLow'   ==>   R1=4
//  
//  ICEXP_e_SLOPE_SWITCH_BY_INTRADAYSTATE
//      The integration time ratios are switched depending on the intraday state. The following
//      rules apply:
//  
//      IntradayState is NIGHT ==>  R1=16
//      IntradayState is DAY   ==>  R1=4
/*#[ type ICEXP_E_SLOPE_SWITCHING_MODE */
typedef enum {
    ICEXP_e_SLOPE_SWITCH_FIXED,
    ICEXP_e_SLOPE_SWITCH_BY_T1THRES,
    ICEXP_e_SLOPE_SWITCH_BY_INTRADAYSTATE
} ICEXP_E_SLOPE_SWITCHING_MODE;
/*#]*/

//  Condition for determination whether we have day or night.
//  
//  ICEXP_e_NIGHTMODECOND_ALWAYS_DAY
//      Always assume we have 'daytime'
//  
//  ICEXP_e_NIGHTMODECOND_ALWAYS_NIGHT
//      Always assume we have 'nighttime'
//  
//  ICEXP_e_NIGHTMODECOND_USE_MEANLOW
//      Use 'low end mean' value from imager to determine if we have night or day. The low end
//      mean is mean pixel value of the low end of the histogram. The value which defines the
//      boundary for division of low/high end is defined by the imager register settings.
//      See function ICEXP_v_IntradayStateControl() for details.
//  
//  ICEXP_e_NIGHTMODECOND_USE_MEAN
//      Use 'mean' brightness value to determine if we have night or day. See function
//      ICEXP_v_IntradayStateControl() for details.
/*#[ type ICEXP_E_NIGHT_MODE_CONDITION */
typedef enum {
    ICEXP_e_NIGHTMODECOND_ALWAYS_DAY,
    ICEXP_e_NIGHTMODECOND_USE_MEANLOW,
    ICEXP_e_NIGHTMODECOND_USE_MEAN,
    ICEXP_e_NIGHTMODECOND_ALWAYS_NIGHT
}  ICEXP_E_NIGHT_MODE_CONDITION;
/*#]*/

//  Control parameter for forced DCG switching. If this control parameter is set to TOHIGH
//  or TOLOW, then the exposure control module will issue an DCG switching even if the current
//  exposure settings and image brightness would not lead to a DCG switch. This is useful to
//  manually trigger the imager's column correction, which can only be triggered by a DCG switch
//  during video streaming.
//  
//  ICEXP_e_FORCED_DCG_COMP_DISABLED
//      Forced DCG switching is disabled.
//  
//  ICEXP_e_FORCED_DCG_COMP_TOHIGH
//      DCG is forced to be HIGH. If DCG is already HIGH, it is forced to stay there.
//      If DCG is currently LOW, then it will be switched to HIGH under any circumstances.
//  
//  ICEXP_e_FORCED_DCG_COMP_TOLOW,
//      DCG is forced to be LOW. If DCG is already LOW, it is forced to stay there.
//      If DCG is currently HIGH, then it will be switched to LOW under any circumstances.
//  
//  
//  See 'ICEXP_v_OverwriteDcgOutputCompensated' for further details.
/*#[ type ICEXP_E_FORCED_DCG_COMP */
typedef enum {
    ICEXP_e_FORCED_DCG_COMP_DISABLED,
    ICEXP_e_FORCED_DCG_COMP_TOHIGH,
    ICEXP_e_FORCED_DCG_COMP_TOLOW
}  ICEXP_E_FORCED_DCG_COMP;
/*#]*/

//  Main settings / control parameters for an Exposure Control instance. They control how exposure
//  regulation and imager settings calculation is done.
/*## type ICEXP_S_Settings */
typedef struct ICEXP_S_Settings {
    //  Description:   Control behaviour of the dual conversion gain. See type description for details.
    //  Range:         (enum)
    //  Resolution:    none
    //  Unit:          none
    ICEXP_E_DCG_CONTROLMODE e_DCGControl;		/*## attribute e_DCGControl */
    //  Description:   Filter method used to filter the input luma-values for the exposure control.
    //                 See type description for details.
    //  Range:         (enum)
    //  Resolution:    none
    //  Unit:          none
    ICEXP_E_FILTER_MODE e_LumaFilterMode;		/*## attribute e_LumaFilterMode */
    //  Description:   Condition for switching the slopes R1/R2. See type description for details.
    //  Range:         (enum)
    //  Resolution:    none
    //  Unit:          none
    ICEXP_E_SLOPE_SWITCHING_MODE e_SlopeSwitchingMode;		/*## attribute e_SlopeSwitchingMode */
    //  Description:   Condition for switching intraday state to night or day. See type description for details.
    //  Range:         (enum)
    //  Resolution:    none
    //  Unit:          none
    ICEXP_E_NIGHT_MODE_CONDITION e_NightModeCondition;		/*## attribute e_NightModeCondition */
    //  Description:   The attenuation-factor used in the exposure time regulation loop.
    //  Range:         ]0.0 ... 1.0[
    //  Resolution:    none
    //  Unit:          none
    float32 f32_Attenuation;		/*## attribute f32_Attenuation */
    //  Description:   The gain-factor of the dual conversion gain for this specific imager
    //  Range:         0.0 - 10.0
    //  Resolution:    none
    //  Unit:          none
    float32 f32_DCGGainFactor;		/*## attribute f32_DCGGainFactor */
    //  Description:   The desired target value of the image luma/mean value for exposure control loop
    //  Range:         0.0 - 2^20
    //  Resolution:    none
    //  Unit:          Grayvalues (linear)
    float32 f32_TargetLuma;		/*## attribute f32_TargetLuma */
    //  Description:   Lower threshold of fraction of pixels in the 'low end' histogram, used to decide switching of
    //                 the intraday-state flag to day. See 'intraday state switching' for details.
    //  Range:         0.0 - 1.0
    //  Resolution:    none
    //  Unit:          none
    float32 f32_IntradayThresDay_PercLowEndMin;		/*## attribute f32_IntradayThresDay_PercLowEndMin */
    //  Description:   Upper threshold of fraction of pixels in the 'low end' histogram, used to decide switching of
    //                 the intraday-state flag to night. See 'intraday state switching' for details.
    //  Range:         0.0 - 1.0
    //  Resolution:    none
    //  Unit:          none
    float32 f32_IntradayThresNightPercLowEndMin;		/*## attribute f32_IntradayThresNightPercLowEndMin */
    //  Description:   Delta time between two image lines, as defined in imager timing configuration
    //  Range:         0 - 2^32
    //  Resolution:    1
    //  Unit:          ns
    uint32 ui32_LineTimeNs;		/*## attribute ui32_LineTimeNs */
    //  Description:   Weights for the luma averager filter (ignored if other filter enabled)
    //  Range:         none
    //  Resolution:    none
    //  Unit:          none
    uint16 aui16_LumaAveragerWeights[ICEXP_cui_MAX_LUMA_FILTER_VALUES];		/*## attribute aui16_LumaAveragerWeights */
    //  Description:   LOWER threshold of exposure-time until DCG is switched to HIGH. This is only
    //                 used if 'e_DCGControl' is set to AUTO.
    //  Range:         0 - 0xFFFF
    //  Resolution:    1
    //  Unit:          us
    uint16 ui16_DCGThresholdHighUs;		/*## attribute ui16_DCGThresholdHighUs */
    //  Description:   UPPER threshold of exposure-time until DCG is switched to HIGH. This is only
    //                 used if 'e_DCGControl' is set to AUTO.
    //  Range:         0 - 0xFFFF
    //  Resolution:    1
    //  Unit:          us
    uint16 ui16_DCGThresholdLowUs;		/*## attribute ui16_DCGThresholdLowUs */
    //  Description:   As long as the mean/luma is in the range between 'ui16_LumaMinNoControl' and
    //                 'ui16_LumaMaxNoControl', no correction of the exposure time will be done.
    //  Range:         0 - 0xFFFF
    //  Resolution:    1
    //  Unit:          Grayvalues (linear)
    uint16 ui16_LumaMaxNoControl;		/*## attribute ui16_LumaMaxNoControl */
    //  Description:   As long as the mean/luma is in the range between 'ui16_LumaMinNoControl' and
    //                 'ui16_LumaMaxNoControl', no correction of the exposure time will be done.
    //  Range:         0 - 0xFFFF
    //  Resolution:    1
    //  Unit:          Grayvalues (linear)
    uint16 ui16_LumaMinNoControl;		/*## attribute ui16_LumaMinNoControl */
    //  Description:   The upper limit for the output exposure time T1.
    //                 NOTE: There is one exception where this limit is ignored: Forced DCG switching.
    //                       See description of 'TODO: xyz'
    //  Range:         0 - 0xFFFF
    //  Resolution:    1
    //  Unit:          us
    uint16 ui16_MaxExposureT1us;		/*## attribute ui16_MaxExposureT1us */
    //  Description:   The lower limit for the output exposure time T1.
    //                 NOTE: There is one exception where this limit is ignored: Forced DCG switching.
    //                       See description of 'TODO: xyz'
    //  Range:         0 - 0xFFFF
    //  Resolution:    1
    //  Unit:          us
    uint16 ui16_MinExposureT1us;		/*## attribute ui16_MinExposureT1us */
    //  Description:   This is the absolute maximum exposure time, which must never be exceeded!
    //                 In contrast to 'ui16_MaxExposureT1us', which can be overwritten by the 'forced
    //                 DCG compenstation', this value is a hard limit for the output exposure time value,
    //                 which is always applied.
    //  Range:         0 - 0xFFFF
    //  Resolution:    1
    //  Unit:          us
    uint16 ui16_CriticalMaxTotalExposureUs;		/*## attribute ui16_CriticalMaxTotalExposureUs */
    //  Description:   This is the absolute minimum exposure time, which must never be underrun!
    //                 In contrast to 'ui16_MinExposureT1us', which can be overwritten by the 'forced
    //                 DCG compenstation', this value is a hard limit for the output exposure time value,
    //                 which is always applied.
    //  Range:         0 - 0xFFFF
    //  Resolution:    1
    //  Unit:          us
    uint16 ui16_CriticalMinTotalExposureUs;		/*## attribute ui16_CriticalMinTotalExposureUs */
    //  Description:   Maximum possible value for T2, until the imager clamps that value due to
    //                 internal hardware related limitations.
    //  Range:         0 - 0xFFFF
    //  Resolution:    1
    //  Unit:          us
    uint16 ui16_MaxPossibleT2us;		/*## attribute ui16_MaxPossibleT2us */
    //  Description:   Maximum possible value for T3, until the imager clamps that value due to
    //                 internal hardware related limitations.
    //  Range:         0 - 0xFFFF
    //  Resolution:    1
    //  Unit:          us
    uint16 ui16_MaxPossibleT3us;		/*## attribute ui16_MaxPossibleT3us */
    //  Description:   The minimum number of frames for which the intradaystate-flag switch condition
    //                 must last until the mode is actually switched to night.
    //  Range:         0 - 0xFFFF
    //  Resolution:    none
    //  Unit:          frames
    uint16 ui16_IntradayThresNight_Frames;		/*## attribute ui16_IntradayThresNight_Frames */
    //  Description:   Threshold on the 'low end mean' for switching to night mode. Only used
    //                 if 'e_NightModeCondition' is set to 'ICEXP_e_NIGHTMODECOND_USE_MEANLOW'.
    //                 See desciption of intraday state switching for details.
    //  Range:         0 - 0xFFFF
    //  Resolution:    none
    //  Unit:          Grayvalues (linear)
    uint16 ui16_IntradayThresNight_LowEndMeanMax;		/*## attribute ui16_IntradayThresNight_LowEndMeanMax */
    //  Description:   Threshold on the 'low end mean' for switching to day mode. Only used
    //                 if 'e_NightModeCondition' is set to 'ICEXP_e_NIGHTMODECOND_USE_MEANLOW'.
    //                 See desciption of intraday state switching for details.
    //  Range:         0 - 0xFFFF
    //  Resolution:    none
    //  Unit:          Grayvalues (linear)
    uint16 ui16_IntradayThresDay_LowEndMeanMax;		/*## attribute ui16_IntradayThresDay_LowEndMeanMax */
    //  Description:   Upper threshold for the luma to switch the intraday-state flag to day.
    //                 See intraday state for details.
    //  Range:         0 - 0xFFFF
    //  Resolution:    none
    //  Unit:          Grayvalues (linear)
    uint16 ui16_IntradayThresDay_LumaMax;		/*## attribute ui16_IntradayThresDay_LumaMax */
    //  Description:   The minimum number of frames for which the intradaystate-flag switch condition
    //                 must last until the mode is actually switched to day.
    //  Range:         0 - 0xFFFF
    //  Resolution:    none
    //  Unit:          frames
    uint16 ui16_IntradayThresDay_Frames;		/*## attribute ui16_IntradayThresDay_Frames */
    //  Description:   Fixed value of R1=T1/T2 in case slope-switching is not enabled via 'e_SlopeSwitchingMode'
    //  Range:         {4, 16}
    //  Resolution:    none
    //  Unit:          none
    uint16 ui16_IntegrationTimeRatioR1;		/*## attribute ui16_IntegrationTimeRatioR1 */
    //  Description:   Fixed value of R2=T2/T3 in case slope-switching is not enabled via 'e_SlopeSwitchingMode'
    //  Range:         {4, 16}
    //  Resolution:    none
    //  Unit:          none
    uint16 ui16_IntegrationTimeRatioR2;		/*## attribute ui16_IntegrationTimeRatioR2 */
    //  Description:   Upper threshold for switching imager integration time ratios.
    //                 Used only if slope-switching is set to 'ICEXP_e_SLOPE_SWITCH_BY_T1THRES'.
    //                 See <TODO> for details how slope ratio switching works.
    //  Range:         0 - 0xFFFF
    //  Resolution:    1
    //  Unit:          us
    uint16 ui16_SlopeRatioSwitchThresT1UsHigh;		/*## attribute ui16_SlopeRatioSwitchThresT1UsHigh */
    //  Description:   Lower threshold for switching imager integration time ratios.
    //                 Used only if slope-switching is set to 'ICEXP_e_SLOPE_SWITCH_BY_T1THRES'.
    //                 See function ICEXP_v_SlopeRatioControl() for details how slope ratio
    //                 switching works.
    //  Range:         0 - 0xFFFF
    //  Resolution:    1
    //  Unit:          us
    uint16 ui16_SlopeRatioSwitchThresT1UsLow;		/*## attribute ui16_SlopeRatioSwitchThresT1UsLow */
    //  Description:   Depth (history-length / number of used values) of the luma filter buffer
    //  Range:         0 - ICEXP_cui_MAX_LUMA_FILTER_VALUES
    //  Resolution:    1
    //  Unit:          none
    uint16 ui16_LumaFilterDepth;		/*## attribute ui16_LumaFilterDepth */
    //  Description:   If set to true, the intraday state is always forced to NIGHT, and exposure
    //                 time is fixed to ui16_MaxExposureT1us. Futher DCG is set to HIGH, in case
    //                 e_DCGControl is not 'ICEXP_e_DCGMODE_ALWAYS_LOW'.
    //  Range:         (boolean)
    //  Resolution:    none
    //  Unit:          none
    boolean b_ForceNightMode;		/*## attribute b_ForceNightMode */
    //  Description:   If set to true, the exposure time regulation is based on the luma value determined
    //                 by calculating the 'weighted mean' from the imager histogram. Otherwise the 'true'
    //                 linear mean from the imager is used.
    //  Range:         (boolean)
    //  Resolution:    none
    //  Unit:          none
    boolean b_UseWeightedMean;		/*## attribute b_UseWeightedMean */
    //  Description:   A pointer to the weights used to calculate the weighted mean from the imager
    //                 histogram in 16x/16x slope ratio mode (R1=16, R2=16).
    //  Range:         0 - 0xFFFF
    //  Resolution:    none
    //  Unit:          none
    const IC_S_HistogramWeights * ps_HistWeights_16x16x;		/*## attribute ps_HistWeights_16x16x */
    //  Description:   A pointer to the weights used to calculate the weighted mean from the imager
    //                 histogram in 4x/16x slope ratio mode (R1=4, R2=16).
    //  Range:         0 - 0xFFFF
    //  Resolution:    none
    //  Unit:          none
    const IC_S_HistogramWeights * ps_HistWeights_4x16x;		/*## attribute ps_HistWeights_4x16x */
    //  Description:   A pointer to the characteristics of the imager statistics histogram bins. This is
    //                 used to calculate the 'weighted mean'.
    //  Range:         none
    //  Resolution:    none
    //  Unit:          none
    const IC_S_HistogramBinParams * ps_HistBinParams;		/*## attribute ps_HistBinParams */
} ICEXP_S_Settings;

//  Structure storing some values from previous frames
/*## type ICEXP_S_HistoryEntry */
typedef struct ICEXP_S_HistoryEntry {
    //  Description:   Scene brightness value
    //  Range:         0.0 - INF
    //  Resolution:    none
    //  Unit:          cd/m^2
    float32 f32_BrightnessCdqm;		/*## attribute f32_BrightnessCdqm */
    //  Description:   Luma value from the image
    //  Range:         0 - 2^20
    //  Resolution:    1
    //  Unit:          Imager data grayvalues (linear)
    uint32 ui32_Mean;		/*## attribute ui32_Mean */
    //  Description:   Exposure time
    //  Range:         0 - 0xFFFF
    //  Resolution:    1
    //  Unit:          us
    uint16 ui16_ExposureTimeUs;		/*## attribute ui16_ExposureTimeUs */
} ICEXP_S_HistoryEntry;

//  State storage structure of an exposure control instance
/*## type ICEXP_S_State */
typedef struct ICEXP_S_State {
    //  Description:   Current luma value, which is (depending on setting) one of:
    //                   * Imager ('normal') mean
    //                   * Weighted mean
    //  Range:         0 - 2^20
    //  Resolution:    1
    //  Unit:          Grayvalues (linear)
    uint32 ui32_Luma;		/*## attribute ui32_Luma */
    //  Description:   New output exposure time value, right before limiting/clamping is applied
    //  Range:         0 - 0xFFFF
    //  Resolution:    1
    //  Unit:          us
    uint32 ui32_ExposureTimeOutBeforeLimit_us;		/*## attribute ui32_ExposureTimeOutBeforeLimit_us */
    //  Description:   Current (working) value of weighted mean
    //  Range:         0 - 2^20
    //  Resolution:    1
    //  Unit:          Grayvalues (linear)
    uint32 ui32_MeanWeighted;		/*## attribute ui32_MeanWeighted */
    //  Description:   Current value of mean from imager's statistic data
    //  Range:         0 - 2^20
    //  Resolution:    1
    //  Unit:          Grayvalues (linear)
    uint32 ui32_MeanNormal;		/*## attribute ui32_MeanNormal */
    //  Description:   Current mean value of histogram's 'low end' from imager's statistic data
    //  Range:         0 - 2^20
    //  Resolution:    1
    //  Unit:          Grayvalues (linear)
    uint32 ui32_MeanLow;		/*## attribute ui32_MeanLow */
    //  Description:   Current setting of imager digital gain
    //  Range:         0.03125 - 7.96875
    //  Resolution:    none (quantized to 0.03125 in imager driver)
    //  Unit:          none
    float32 f32_DigitalGain;		/*## attribute f32_DigitalGain */
    //  Description:   Current scene brightness value
    //  Range:         0.0 - INF
    //  Resolution:    none
    //  Unit:          cd/m^2
    float32 f32_BrightnessCdqm;		/*## attribute f32_BrightnessCdqm */
    //  Description:   Luma history value buffer, used by luma filter
    //  Range:         none
    //  Resolution:    none
    //  Unit:          none
    ICEXP_S_HistoryEntry as_FilterHistory[ICEXP_cui_MAX_LUMA_FILTER_VALUES];		/*## attribute as_FilterHistory */
    //  Description:   Number of valid values in the luma filter history buffer array
    //  Range:         0 - Parameters->ui16_LumaFilterDepth
    //  Resolution:    1
    //  Unit:          none
    uint16 ui16_FilterHistoryCount;		/*## attribute ui16_FilterHistoryCount */
    //  Description:   Current exposure time (working value). May be changed several times until final
    //                 output value is calculated.
    //  Range:         0 - 0xFFFF
    //  Resolution:    1
    //  Unit:          us
    uint16 ui16_ExposureTimeUs;		/*## attribute ui16_ExposureTimeUs */
    //  Description:   Current intraday state (day/night)
    //  Range:         (enum)
    //  Resolution:    none
    //  Unit:          none
    IC_E_INTRADAY_STATE e_IntradayState;		/*## attribute e_IntradayState */
    //  Description:   Number of frames since intraday state is at 'day'
    //  Range:         0 - 0xFFFF
    //  Resolution:    1
    //  Unit:          frames
    uint16 ui16_IntradayFrameCountDay;		/*## attribute ui16_IntradayFrameCountDay */
    //  Description:   Number of frames since intraday state is at 'night'
    //  Range:         0 - 0xFFFF
    //  Resolution:    1
    //  Unit:          frames
    uint16 ui16_IntradayFrameCountNight;		/*## attribute ui16_IntradayFrameCountNight */
    //  Description:   Current imager integration time ratio R1
    //  Range:         {4, 16}
    //  Resolution:    none
    //  Unit:          none
    uint16 ui16_SlopeRatioR1;		/*## attribute ui16_SlopeRatioR1 */
    //  Description:   Current imager integration time ratio R2
    //  Range:         {4, 16}
    //  Resolution:    none
    //  Unit:          none
    uint16 ui16_SlopeRatioR2;		/*## attribute ui16_SlopeRatioR2 */
    //  Description:   Current value of imager dual conversion gain
    //  Range:         (enum)
    //  Resolution:    none
    //  Unit:          none
    IC_E_DCG_STATE e_DCGState;		/*## attribute e_DCGState */
    //  Description:   Current value of DCG overwrite setting
    //  Range:         (enum)
    //  Resolution:    none
    //  Unit:          none
    ICEXP_E_FORCED_DCG_COMP e_ForcedDcgCompensation;		/*## attribute e_ForcedDcgCompensation */
} ICEXP_S_State;

//  Stores all input data from current cycle, which are passed to the Exposure Control
/*## type ICEXP_S_Input */
typedef struct ICEXP_S_Input {
    //  Description:   Mean luma/gray value from imager statistics data
    //  Range:         0 - 2^32
    //  Resolution:    1
    //  Unit:          Grayvalues (linear)
    uint32 ui32_LumaMean;		/*## attribute ui32_LumaMean */
    //  Description:   Fraction of pixels in the 'low end' histogram
    //  Range:         0.0 - 1.0
    //  Resolution:    none
    //  Unit:          none (fraction)
    float32 f32_PercLowEnd;		/*## attribute f32_PercLowEnd */
    //  Description:   Scene brightness of the current image
    //  Range:         0.0 - INF
    //  Resolution:    none
    //  Unit:          cd/m^2
    float32 f32_BrightnessCdqm;		/*## attribute f32_BrightnessCdqm */
    //  Description:   Mean grayvalue of the histogram's low end (value from imager register)
    //  Range:         0 - 2^32
    //  Resolution:    1
    //  Unit:          Grayvalues (linear)
    uint32 ui32_HistEndMeanLow;		/*## attribute ui32_HistEndMeanLow */
    //  Description:   Exposure time of input image
    //  Range:         0 - 0xFFFF
    //  Resolution:    1
    //  Unit:          us
    uint16 ui16_ExposureTimeUs;		/*## attribute ui16_ExposureTimeUs */
    //  Description:   Pointer to histogram data from input image
    //  Range:         none
    //  Resolution:    none
    //  Unit:          none
    IC_S_Histogram const * ps_HistogramData;		/*## attribute ps_HistogramData */
    //  Description:   Dual conversion gain (DCG) settings of input frame
    //  Range:         (enum)
    //  Resolution:    none
    //  Unit:          none
    IC_E_DCG_STATE e_DCGState;		/*## attribute e_DCGState */
} ICEXP_S_Input;

//  Stores all control and calculation outputs of the Exposure Control, which have to be commanded
//  to the imager.
/*## type ICEXP_S_Output */
typedef struct ICEXP_S_Output {
    //  The new calculated exposure time in us, before it's limited by certain conditions
    float32 f32_DigitalGain;		/*## attribute f32_DigitalGain */
    //  The new exposure time in us.
    uint32 ui32_ExposureTimeOutBeforeLimit_us;		/*## attribute ui32_ExposureTimeOutBeforeLimit_us */
    //  The new gain for the imager
    uint16 ui16_ExposureTimeUs;		/*## attribute ui16_ExposureTimeUs */
    //  New slope ratio R1=T1/T2
    uint16 ui16_SlopeRatioR1;		/*## attribute ui16_SlopeRatioR1 */
    //  New slope ratio R2=T2/T3
    uint16 ui16_SlopeRatioR2;		/*## attribute ui16_SlopeRatioR2 */
    //  The weighted mean calculated from the histogram data
    uint32 ui32_MeanWeighted;		/*## attribute ui32_MeanWeighted */
    //  Number of total pixels counted in histogram data
    uint32 ui32_NumHistogramPixels;		/*## attribute ui32_NumHistogramPixels */
    //  Fraction of pixels which are saturated [0 ... 1.0]
    float32 f32_SaturatedPixelsFraction;		/*## attribute f32_SaturatedPixelsFraction */
    //  The new intra day state
    IC_E_INTRADAY_STATE e_IntradayState;		/*## attribute e_IntradayState */
    //  The new DCG setting
    IC_E_DCG_STATE e_DCGState;		/*## attribute e_DCGState */
} ICEXP_S_Output;

//  Stores measurement output data for a Exposure Control instance
/*## type ICEXP_S_MeasData */
typedef struct ICEXP_S_MeasData {
    uint32 ui32_MeasCounter;		/*## attribute ui32_MeasCounter */
    ICEXP_S_Settings s_Parameters;		/*## attribute s_Parameters */
    ICEXP_S_Input s_Input;		/*## attribute s_Input */
    ICEXP_S_Output s_Output;		/*## attribute s_Output */
    ICEXP_S_State s_StateBeforeRun;		/*## attribute s_StateBeforeRun */
    ICEXP_S_State s_StateAfterRun;		/*## attribute s_StateAfterRun */
} ICEXP_S_MeasData;

//  This is the 'object storage' structure, which holds all data belonging to an Exposure Control
//  instance. Almost all functions of the Exposure Control module are working on objects of this type.
//  This allows to handle multiple instances of the Exposure Control module.
/*## type ICEXP_S_Obj */
typedef struct ICEXP_S_Obj {
    uint32 ui32_MeasCounter;		/*## attribute ui32_MeasCounter */
    ICEXP_S_Settings * ps_Parameters;		/*## attribute ps_Parameters */
    ICEXP_S_Input * ps_Input;		/*## attribute ps_Input */
    ICEXP_S_Output s_Output;		/*## attribute s_Output */
    ICEXP_S_State s_State;		/*## attribute s_State */
    ICEXP_S_State s_EntryState;		/*## attribute s_EntryState */
    ICEXP_E_MODULE_STATE e_ModuleState;		/*## attribute e_ModuleState */
} ICEXP_S_Obj;

//  Size of exposure module measurement data
/*## attribute ICEXP_cui32_MeasDataSize */
#define ICEXP_cui32_MeasDataSize (sizeof(ICEXP_S_MeasData))

/***    User explicit entries    ***/


/* Operations */

//*****************************************************************************
//  Functionname:  ICEXP_e_MeasFreezeBuffer
//  
//  Description:      
//    This function fills measurement-data for a specific ICEXP instance into 'ps_MeasData'.
//  
//  Return value:     
//    ICEXP_e_ERR_OK:  No error occurred.
//  
//  Preconditions:
//    ICEXP object 'ps_ICObj' must be initialized
//  
//  Parameter:     ICEXP_S_Obj * ps_ICObj   <In>
//  Description:   ICEXP object instance, which will be used for this function call
//  Range:         not NULL
//  Resolution:    none
//  Unit:          none
//  
//  Parameter:     ICEXP_S_MeasData * ps_MeasData   <In>
//  Description:   Pointer to measurement struct, which will be filled with data
//  Range:         none
//  Resolution:    none
//  Unit:          none
//    
//  
//  return         ICEXP_E_ERROR
//**************************************************************************** */
/*## operation ICEXP_e_MeasFreezeBuffer(ICEXP_S_Obj *,ICEXP_S_MeasData *) */
ICEXP_E_ERROR ICEXP_e_MeasFreezeBuffer(ICEXP_S_Obj * ps_ICObj, ICEXP_S_MeasData * ps_MeasData);

//*****************************************************************************
//  Functionname:  ICEXP_e_RunControl
//  
//  Description:      
//    This is the main exposure control function. It does all processing based on current state
//    and input data to calculate new imager exposure relevant settings for the next frame. Results
//    to the output structure are passed to caller via pointer 'pps_Output'. See flowchart/activity
//    diagram for details.
//  
//  Return value:     
//    ICEXP_e_ERR_OK:            No error occurred
//    ICEXP_e_ERR_MODULESTATE:   Wrong state (i.e. no inputs for current cycle provided)
//    ICEXP_e_ERR_NO_PARAMS_SET: Settings have not been provided yet
//  
//  Preconditions:
//    - ICEXP object 'ps_ICObj' must be initialized 
//    - Settings must have been provided via ICEXP_e_SetControlParameters()
//    - Input data must have been provided via ICEXP_e_SetControlInput()
//  
//  Parameter:     ICEXP_S_Obj * ps_ICObj   <InOut>
//  Description:   ICEXP object instance, which will be used for this function call
//  Range:         not NULL
//  Resolution:    none
//  Unit:          none
//  
//  Parameter:     ICEXP_S_Output * * pps_Output   <Out>
//  Description:   Reference to output structure pointer. This pointer will point to output data when this function
//                 returns without an error.
//  Range:         none
//  Resolution:    none
//  Unit:          none
//    
//  
//  return         ICEXP_E_ERROR
//**************************************************************************** */
/*## operation ICEXP_e_RunControl(ICEXP_S_Obj *,ICEXP_S_Output * *) */
ICEXP_E_ERROR ICEXP_e_RunControl(ICEXP_S_Obj * ps_ICObj, ICEXP_S_Output * * pps_Output);

//*****************************************************************************
//  Functionname:  ICEXP_e_SetControlInput
//  
//  Description:      
//    This function sets all input parameter for image control. It has to be invoked before
//    ICEXP_e_RunControl is called.
//  
//  Return value:     
//    ICEXP_e_ERR_OK:            No error occurred
//    ICEXP_e_ERR_MODULESTATE:   Wrong state (not initialized or inputs already provided in current cycle)
//  
//  Preconditions:
//    ICEXP object 'ps_ICObj' must be initialized
//  
//  Parameter:     ICEXP_S_Obj * ps_ICObj   <InOut>
//  Description:   ICEXP object instance, which will be used for this function call
//  Range:         not NULL
//  Resolution:    none
//  Unit:          none
//  
//  Parameter:     ICEXP_S_Input * ps_ICInput   <In>
//  Description:   Pointer to input data, which is processed when calling ICEXP_v_RunControl().
//                 NOTE: Only pointer is copied, so the structure data pointed to must not change until
//                 ICEXP_v_RunControl() finished!
//  Range:         none
//  Resolution:    none
//  Unit:          none
//    
//  
//  return         ICEXP_E_ERROR
//**************************************************************************** */
/*## operation ICEXP_e_SetControlInput(ICEXP_S_Obj *,ICEXP_S_Input *) */
ICEXP_E_ERROR ICEXP_e_SetControlInput(ICEXP_S_Obj * ps_ICObj, ICEXP_S_Input * ps_ICInput);

//*****************************************************************************
//  Functionname:  ICEXP_e_SetControlParameters
//  
//  Description:      
//    Sets the parameters to be used on next execution of ICEXP_e_RunControl().
//  
//  Return value:     
//    ICEXP_e_ERR_OK:            No error occurred
//    ICEXP_e_ERR_NULLPOINTER:   Nullpointer has been provided
//    ICEXP_e_ERR_PARAM_*:       Parameter * is out-of-range or illegal
//  
//  Preconditions:
//    ICEXP object 'ps_ICObj' must be initialized
//  
//  Parameter:     ICEXP_S_Obj * ps_ICObj   <InOut>
//  Description:   ICEXP object instance, which will be used for this function call
//  Range:         not NULL
//  
//  Parameter:     ICEXP_S_Settings * ps_Settings   <In>
//  Description:   Pointer to control parameters, which is used for many functions.
//                 NOTE: Structure at pointer address is not copied, so it must be hold available
//                 for the entire lifetime of the associated IC object. Nevertheless it is allowed
//                 to change settings between completed function cycles.
//  Range:         not NULL
//    
//  
//  return         ICEXP_E_ERROR
//**************************************************************************** */
/*## operation ICEXP_e_SetControlParameters(ICEXP_S_Obj *,ICEXP_S_Settings *) */
ICEXP_E_ERROR ICEXP_e_SetControlParameters(ICEXP_S_Obj * ps_ICObj, ICEXP_S_Settings * ps_Settings);

//*****************************************************************************
//  Functionname:  ICEXP_ui16_RoundTimeNearestLineCnt
//  
//  Description:
//    Rounds the given time to the nearest integer line time, according to line-time / pixelclock gathered
//    from control parameters.
//  
//  Return value:
//    Description:   Rounded time value
//    Range:         0-0xFFFF
//    Resolution:    one line-duration
//    Unit:          us
//  
//  Preconditions:
//    - ICEXP object 'ps_ICObj' must be initialized
//    - Settings must have been provided by calling ICEXP_e_SetControlParameters()
//  
//  Parameter:     const ICEXP_S_Obj * ps_ICObj   <In>
//  Description:   ICEXP object instance, which will be used for this function call
//  Range:         not NULL
//  Resolution:    none
//  Unit:          none
//  
//  Parameter:     uint16 ui16_TimeUs   <In>
//  Description:   Input value which will be used for rounding
//  Range:         0-0xFFFF
//  Resolution:    1
//  Unit:          us
//    
//  
//  return         uint16
//**************************************************************************** */
/*## operation ICEXP_ui16_RoundTimeNearestLineCnt(const ICEXP_S_Obj *,uint16) */
uint16 ICEXP_ui16_RoundTimeNearestLineCnt(const ICEXP_S_Obj * ps_ICObj, uint16 ui16_TimeUs);

//*****************************************************************************
//  Functionname:  ICEXP_v_Init
//  
//  Description:
//    Initializes an Exposure Control instance object, setting the state variables to default values.
//  
//  Preconditions:
//    None
//  
//  Postconditions:
//    Control parameters must be provided via ICEXP_e_SetControlParameters() before this object can
//    actually be used.
//  
//  Parameter:     ICEXP_S_Obj * ps_ICObj   <InOut>
//  Description:   ICEXP object instance, which will be used for this function call
//  Range:         not NULL
//  Resolution:    none
//  Unit:          none
//    
//  
//  return         void
//**************************************************************************** */
/*## operation ICEXP_v_Init(ICEXP_S_Obj *) */
void ICEXP_v_Init(ICEXP_S_Obj * ps_ICObj);

//*****************************************************************************
//  Functionname:  ICEXP_v_OverwriteDcgOutputCompensated
//  
//  Description:
//    This function forces the DCG output to a specific value, regardless of what the regulator
//    in ICEXP_e_RunControl() has chosen. To avoid changing image brightness, this function
//    will alter Tint and DigitalGain to compensate this in case the DCG has been modified.
//  
//    If the forced value is the same as the regulator output value, this function does nothing.
//    See module description "FORCED DCG OVERWRITE" for additional information.
//  
//  Preconditions:
//    ICEXP_e_RunControl() must have been called for current cycle.
//  
//  Parameter:     ICEXP_S_Obj * ps_ICObj   <InOut>
//  Description:   ICEXP object instance, which will be used for this function call
//  Range:         not NULL
//  Resolution:    none
//  Unit:          none
//  
//  Parameter:     IC_E_DCG_STATE e_ForcedValue   <In>
//  Description:   Desired DCG value which will be forced to the output
//  Range:         (enum)
//  Resolution:    none
//  Unit:          none
//    
//  
//  return         void
//**************************************************************************** */
/*## operation ICEXP_v_OverwriteDcgOutputCompensated(ICEXP_S_Obj *,IC_E_DCG_STATE) */
void ICEXP_v_OverwriteDcgOutputCompensated(ICEXP_S_Obj * ps_ICObj, IC_E_DCG_STATE e_ForcedValue);

/***    User explicit entries    ***/



/*#[ ignore */

#ifdef __cplusplus
}
#endif

/*#]*/


#endif
/*********************************************************************
	File Path: ..\..\..\04_Engineering\01_Source_Code\Algo\ic\ic_exposure.h
*********************************************************************/
