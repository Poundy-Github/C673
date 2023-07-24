//* **********************************************************************
//  COMPANY:         $CompanyInfo: CONFIDENTIAL AND PROPRIETARY PROPERTY OF CONTINENTAL AG , A.D.C. GmbH  -  ALL RIGHTS RESERVED $
//  
//  PROJECT:         MFC30x_MCU
//  CPU:             MPC5675K
//  
//  PACKAGE:         $Source: ic_exposure.c $ $Revision: 1.1 $
//  MKS Date:        $Date: 2021/12/13 17:25:52CET $
//  
//  RHAPSODY:        7.5.3
//  COMPONENT:       IC
//  CONFIGURATION:   DefaultConfig
//  MODEL ELEMENT:   ic_exposure
//  MODULNAME:       ..\..\..\04_Engineering\01_Source_Code\Algo\ic\ic_exposure.c
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

/*## auto_generated */
#include "ic_exposure.h"
/*## dependency ic_errmanager */
#include "ic_errmanager.h"
/*## package Ic_Pkg */

/*## class TopLevel::ic_exposure */


/*#[ ignore */
#ifdef __cplusplus
extern "C"
{
#endif

/*#]*/


//  Bin-number which contains the saturated pixels in 16x16x mode
//  PRQA S 3218 2
/*## attribute ICEXP_cui16_SaturatedPixelsBin16x16x */
static const uint16 ICEXP_cui16_SaturatedPixelsBin16x16x = 243;

//  Bin-number which contains the saturated pixels in 4x16x mode
//  PRQA S 3218 2
/*## attribute ICEXP_cui16_SaturatedPixelsBin4x16x */
static const uint16 ICEXP_cui16_SaturatedPixelsBin4x16x = 196;

//*****************************************************************************
//  Functionname:  ICEXP_b_LumaIsInRange
//  
//  Description:      
//    Determines whether the given mean grayvalue is within the desired limits / control target
//    luma as defined in the IC exposure settings (see ICEXP_S_Settings.ui16_Luma***NoControl).
//  
//  Return value:     
//    b_TRUE:  Luma is within desired limits definied in the ICEXP settings
//    b_FALSE: Luma is NOT within desired limits definied in the ICEXP settings
//  
//  Preconditions:
//    ICEXP object 'ps_ICObj' must be initialized and settings must have been provided via
//    ICEXP_e_SetControlParameters()
//  
//  
//  Parameter:     const ICEXP_S_Obj * ps_ICObj   <InOut>
//  Description:   IC Object - must not be NULL
//  Range:         not NULL
//  Resolution:    none
//  Unit:          none
//  
//  Parameter:     uint32 ui32_Luma   <In>
//  Description:   Grayvalue (i.e. IC-ROI mean or weighted mean) which is tested
//  Range:         0-0xFFFFFFFF
//  Resolution:    1
//  Unit:          Grayvalue (linear)
//    
//  
//  return         boolean
//**************************************************************************** */
/*## operation ICEXP_b_LumaIsInRange(const ICEXP_S_Obj *,uint32) */
static boolean ICEXP_b_LumaIsInRange(const ICEXP_S_Obj * ps_ICObj, uint32 ui32_Luma);

//*****************************************************************************
//  Functionname:  ICEXP_ui16_CalcT1
//  
//  Description:
//    Calculates T1 integration time based on passed total integration time (Ttot=T1+T2+T3) and
//    current slope ratio state (R1 / R2). As current IC object state affects results, it makes
//    a different whether this method is called before or after ICEXP_e_RunControl().
//  
//  Return value:
//    Description:   T1 integration time
//    Range:         0-0xFFFF
//    Resolution:    1
//    Unit:          lines
//  
//  Preconditions:
//    - ICEXP object 'ps_ICObj' must be initialized
//    - Settings must have been provided by calling ICEXP_e_SetControlParameters()
//  
//  
//  Parameter:     const ICEXP_S_Obj * ps_ICObj   <In>
//  Description:   ICEXP object instance, which will be used for this function call
//  Range:         not NULL
//  Resolution:    none
//  Unit:          none
//  
//  Parameter:     uint16 ui16_Ttot   <In>
//  Description:   Total integration time, from which T1 is to be calculated
//  Range:         0-0xFFFF
//  Resolution:    1
//  Unit:          us
//    
//  
//  return         uint16
//**************************************************************************** */
/*## operation ICEXP_ui16_CalcT1(const ICEXP_S_Obj *,uint16) */
static uint16 ICEXP_ui16_CalcT1(const ICEXP_S_Obj * ps_ICObj, uint16 ui16_Ttot);

//*****************************************************************************
//  Functionname:  ICEXP_ui16_CalcTges
//  
//  Description:
//    Calculates total integration time based on passed T1 integration time (T1=Ttot-T2-T3) and
//    current slope ratio state (R1 / R2). As current IC object state affects results, it makes
//    a different whether this method is called before or after ICEXP_e_RunControl().
//  
//  Return value:
//    Description:   Total integration time Ttot=T1+T2+T3
//    Range:         0-0xFFFF
//    Resolution:    1
//    Unit:          lines
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
//  Parameter:     uint16 ui16_T1us   <In>
//  Description:   T1 integration time, from which total integration time is to be calculated
//  Range:         0-0xFFFF
//  Resolution:    1
//  Unit:          us
//    
//  
//  return         uint16
//**************************************************************************** */
/*## operation ICEXP_ui16_CalcTges(const ICEXP_S_Obj *,uint16) */
static uint16 ICEXP_ui16_CalcTges(const ICEXP_S_Obj * ps_ICObj, uint16 ui16_T1us);

//*****************************************************************************
//  Functionname:  ICEXP_ui32_CalcLumaFromHist
//  
//  Description:
//    Calculates a weighted mean from histogram-data and weights array. Abstract calculation formula
//    can be described as:
//  
//      w_mean = sum(HistData[n] * BinCenter[n] * Weight[n]) / sum(Weight[n])
//  
//    In words: It calculates the weighted sum of all histogram values, which is a weighted mean value
//    of the histogram data.
//  
//  Return value:
//    Description:   Weighted mean value
//    Range:         0-2^20
//    Resolution:    1
//    Unit:          Grayvalue (linear)
//  
//  Preconditions:
//    None
//  
//  
//  Parameter:     const IC_S_Histogram * ps_HistData   <In>
//  Description:   Pointer to histogram data, extracted from the image
//  Range:         none
//  Resolution:    none
//  Unit:          none
//  
//  Parameter:     const IC_S_HistogramWeights * ps_Weights   <In>
//  Description:   Pointer to weights, which are used to weight the histogram bins
//  Range:         none
//  Resolution:    none
//  Unit:          none
//  
//  Parameter:     const IC_S_HistogramBinParams * ps_BinParams   <In>
//  Description:   Pointer to parameters, which characterize the bins (e.g. bin center value)
//  Range:         none
//  Resolution:    none
//  Unit:          none
//  
//  Parameter:     uint32 * pui32_NumHistogramValuesOut   <In>
//  Description:   Pointer to an output value, which will be set to the number of the total histogram value count
//                 (sum of all bin counts). Setting to NULL will ignore this parameter.
//  Range:         NULL is allowed
//  Resolution:    none
//  Unit:          none
//    
//  
//  return         uint32
//**************************************************************************** */
/*## operation ICEXP_ui32_CalcLumaFromHist(const IC_S_Histogram *,const IC_S_HistogramWeights *,const IC_S_HistogramBinParams *,uint32 *) */
static uint32 ICEXP_ui32_CalcLumaFromHist(const IC_S_Histogram * ps_HistData, const IC_S_HistogramWeights * ps_Weights, const IC_S_HistogramBinParams * ps_BinParams, uint32 * pui32_NumHistogramValuesOut);

//*****************************************************************************
//  Functionname:  ICEXP_v_DCGControl
//  
//  Description:
//    This function controls the dual conversion gain (DCG) state based on current exposure time
//    (evaluated from object state). If the function changes the DCG state it adapts also the value
//    of new exposure time to compensate the new gain, so image brightness is not influenced.
//    Resulting DCG setting is written to object state.
//  
//  Preconditions:
//    State of working object 'ps_ICObj' must reflect correct state for exposure time and DCG
//    (usualy done in ICEXP_e_RunControl())
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
/*## operation ICEXP_v_DCGControl(ICEXP_S_Obj *) */
static void ICEXP_v_DCGControl(ICEXP_S_Obj * ps_ICObj);

//*****************************************************************************
//  Functionname:  ICEXP_v_ExposureTimeCalculation
//  
//  Description:
//    This function calculates the new exposure time based on:
//      - Input luma value
//      - Current exposure time
//      - Control settings: Desired target luma
//      - Control settings: Attenuation factor
//  
//    T_New = T_Old * (1 + Atten * (TargetLuma / InputLuma - 1))
//  
//  Inputs:
//    ps_ICObj->s_State.ui16_ExposureTimeUs
//    ps_ICObj->s_State.ui32_Luma
//    ps_ICObj->ps_Parameters->f32_TargetLuma
//    ps_ICObj->ps_Parameters->f32_Attenuation
//  
//  Outputs:
//    ps_ICObj->s_State.ui16_ExposureTimeUs
//  
//  Preconditions:
//    State data of working object 'ps_ICObj' must reflect correct values for current cycle
//    (usualy done in ICEXP_e_RunControl()).
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
/*## operation ICEXP_v_ExposureTimeCalculation(ICEXP_S_Obj *) */
static void ICEXP_v_ExposureTimeCalculation(ICEXP_S_Obj * ps_ICObj);

//*****************************************************************************
//  Functionname:  ICEXP_v_ExposureTimeLimit
//  
//  Description:
//    This function clamps current exposure time to limits specified in the control settings.
//    The old value before clamping is stored in the object state 'ui32_ExposureTimeOutBeforeLimit_us'.
//  
//  Inputs:
//    ps_ICObj->s_State.ui16_ExposureTimeUs
//    ps_ICObj->ps_Parameters->ui16_MaxExposureT1us
//    ps_ICObj->ps_Parameters->ui16_MinExposureT1us
//  
//  Outputs:
//    ps_ICObj->s_State.ui16_ExposureTimeUs
//    ps_ICObj->s_State.ui32_ExposureTimeOutBeforeLimit_us
//  
//  Preconditions:
//    - ICEXP object 'ps_ICObj' must be initialized 
//    - Settings must have been provided via ICEXP_e_SetControlParameters()
//    - State data of working object 'ps_ICObj' must reflect correct values for exposure time
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
/*## operation ICEXP_v_ExposureTimeLimit(ICEXP_S_Obj *) */
static void ICEXP_v_ExposureTimeLimit(ICEXP_S_Obj * ps_ICObj);

//*****************************************************************************
//  Functionname:  ICEXP_v_FastLumaReduction
//  
//  Description:
//    This function does aggressive reduction of image brightness by adjusting DCG or exposure time. It
//    depends on current setting of DCG:
//    
//    DCG=HIGH: Switch the DCG state to LOW, which will reduce brightness by the DCG factor (MT9M025 has ~2.78)
//    DCG=LOW:  DCG is already LOW, so halve current exposure time.
//  
//    In any case the object state's 'Intraday State Flag' is set to DAY.
//  
//  Inputs:
//    ps_ICObj->s_State.ui16_ExposureTimeUs
//    ps_ICObj->s_State.e_DCGState
//  
//  Outputs:
//    ps_ICObj->s_State.ui16_ExposureTimeUs
//    ps_ICObj->s_State.e_DCGState
//  
//  Preconditions:
//    - ICEXP object 'ps_ICObj' must be initialized 
//    - Settings must have been provided via ICEXP_e_SetControlParameters()
//    - State data of working object 'ps_ICObj' must reflect correct values for exposure time and DCG
//  
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
/*## operation ICEXP_v_FastLumaReduction(ICEXP_S_Obj *) */
static void ICEXP_v_FastLumaReduction(ICEXP_S_Obj * ps_ICObj);

//*****************************************************************************
//  Functionname:  ICEXP_v_IntradayStateControl
//  
//  Description:
//    Function for calculating the 'Intraday State Flag', depending on values of:
//      - Exposure time
//      - DCG state
//      - Luma / (weighted) mean image grayvalue or "low end mean" (depends on settings)
//  
//    See Visio Document 'IC_spec_BSB_stereo_work.VSD' for details, sheet 'Short_Nightflag'.
//  
//  Inputs:
//    ps_ICObj->ps_Settings->e_NightModeCondition
//    ps_ICObj->ps_Settings->f32_IntradayThresNightPercLowEndMin
//    ps_ICObj->ps_Settings->ui16_MaxExposureT1us
//    ps_ICObj->ps_Settings->ui16_IntradayThresNight_LowEndMeanMax
//    ps_ICObj->ps_Settings->ui16_IntradayThresNight_Frames
//    ps_ICObj->ps_Settings->ui16_IntradayThresDay_Frames
//    ps_ICObj->ps_Settings->ui16_IntradayThresDay_LumaMax
//    ps_ICObj->s_State.ui32_Luma
//    ps_ICObj->s_State.ui32_HistEndMeanLow
//    ps_ICObj->s_State.ui16_ExposureTimeUs
//    ps_ICObj->s_State.ui16_IntradayFrameCountNight
//    ps_ICObj->s_State.ui16_IntradayFrameCountDay
//    ps_ICObj->s_State.e_IntradayState
//    ps_ICObj->s_State.e_DCGState
//  
//  Outputs:
//    ps_ICObj->s_State.ui16_IntradayFrameCountNight
//    ps_ICObj->s_State.ui16_IntradayFrameCountDay
//    ps_ICObj->s_State.e_IntradayState
//  
//  Preconditions:
//    - ICEXP object 'ps_ICObj' must be initialized
//    - Settings must have been provided via ICEXP_e_SetControlParameters()
//    - State data of working object 'ps_ICObj' must reflect correct values for values listed above
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
/*## operation ICEXP_v_IntradayStateControl(ICEXP_S_Obj *) */
static void ICEXP_v_IntradayStateControl(ICEXP_S_Obj * ps_ICObj);

//*****************************************************************************
//  Functionname:  ICEXP_v_LumaFilter
//  
//  Description:
//    This function applies a filter to the value of 'ps_State->ui32_Luma', which avoids undesired
//    reaction of the regulator against sporadic changes of image brightness. This may happen due to
//    temporary imager converage by the wiper during a single frame or brightness flickering
//    introduced by tree branches on sunny days.
//  
//    The actual filter implementation which is used can be selected in the control parameters
//    (e_LumaFilterMode). See definition of type ICEXP_E_FILTER_MODE.
//  
//  Preconditions:
//    - ICEXP object 'ps_ICObj' must be initialized
//    - Settings must have been provided via ICEXP_e_SetControlParameters()
//    - State data of working object 'ps_ICObj' must reflect correct values for ui32_Luma
//  
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
/*## operation ICEXP_v_LumaFilter(ICEXP_S_Obj *) */
static void ICEXP_v_LumaFilter(ICEXP_S_Obj * ps_ICObj);

//*****************************************************************************
//  Functionname:  ICEXP_v_LumaFilterAverage
//  
//  Description:
//    This function applies a filter to the value of 'ps_State->ui32_Luma', which calculates the
//    weighted running average over the last N values. N can be chosen in the control parameters
//    'ui16_LumaFilterDepth'. The weights are set in array 'aui16_LumaAveragerWeights', whereas
//    index[0] corresponds to value N, index[1] to N-1, ...
//  
//  Preconditions:
//    - ICEXP object 'ps_ICObj' must be initialized
//    - Settings must have been provided via ICEXP_e_SetControlParameters()
//    - State data of working object 'ps_ICObj' must reflect correct values for ui32_Luma
//  
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
/*## operation ICEXP_v_LumaFilterAverage(ICEXP_S_Obj *) */
static void ICEXP_v_LumaFilterAverage(ICEXP_S_Obj * ps_ICObj);

//*****************************************************************************
//  Functionname:  ICEXP_v_LumaFilterBaratoffschRoth
//  
//  Description:
//    This function implements filter type 'ICEXP_e_FILTER_BARATOFFSCH_ROTH' to the value of 'ps_State->ui32_Luma'.
//    See definition of type 'ICEXP_E_FILTER_MODE' for details how the filter works.
//  
//  Preconditions:
//    - ICEXP object 'ps_ICObj' must be initialized
//    - Settings must have been provided via ICEXP_e_SetControlParameters()
//    - State data of working object 'ps_ICObj' must reflect correct values for 'ui32_Luma'
//  
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
/*## operation ICEXP_v_LumaFilterBaratoffschRoth(ICEXP_S_Obj *) */
static void ICEXP_v_LumaFilterBaratoffschRoth(ICEXP_S_Obj * ps_ICObj);

//*****************************************************************************
//  Functionname:  ICEXP_v_LumaFilterMedian
//  
//  Description:
//    This function implements filter type 'ICEXP_e_FILTER_MEDIAN' to the value of 'ps_State->ui32_Luma'.
//    It selects the 'median' value from last N frames. N can be chosen in the control parameters
//    (ui16_LumaFilterDepth).
//  
//  Preconditions:
//    - ICEXP object 'ps_ICObj' must be initialized
//    - Settings must have been provided via ICEXP_e_SetControlParameters()
//    - State data of working object 'ps_ICObj' must reflect correct values for 'ui32_Luma'
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
/*## operation ICEXP_v_LumaFilterMedian(ICEXP_S_Obj *) */
static void ICEXP_v_LumaFilterMedian(ICEXP_S_Obj * ps_ICObj);

//*****************************************************************************
//  Functionname:  ICEXP_v_LumaFilterRoth
//  
//  Description:
//    This function implements filter type 'ICEXP_e_FILTER_ROTH' to the value of 'ps_State->ui32_Luma'.
//    See definition of type 'ICEXP_E_FILTER_MODE' for details how the filter works.
//  
//  Preconditions:
//    - ICEXP object 'ps_ICObj' must be initialized
//    - Settings must have been provided via ICEXP_e_SetControlParameters()
//    - State data of working object 'ps_ICObj' must reflect correct values for 'ui32_Luma'
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
/*## operation ICEXP_v_LumaFilterRoth(ICEXP_S_Obj *) */
static void ICEXP_v_LumaFilterRoth(ICEXP_S_Obj * ps_ICObj);

//*****************************************************************************
//  Functionname:  ICEXP_v_SlopeRatioControl
//  
//  Description:
//    Function for calculating the imager integration time ratios R1 and R2. The criteria for selecting
//    different ratios depends on the control settings value of 'e_SlopeSwitchingMode'. See definition
//    of type 'ICEXP_E_SLOPE_SWITCHING_MODE' for details.
//  
//    IMPORTANT NOTE: The imager has a bug in R1R2 = 4x16x mode, which results in an image which is 4-times
//    brighter than expected. To compensate this, the value of digital gain is multiplied by 0.25.
//  
//  Preconditions:
//    - ICEXP object 'ps_ICObj' must be initialized
//    - Settings must have been provided via ICEXP_e_SetControlParameters()
//    - State data of working object 'ps_ICObj' must reflect correct values for exposure time and
//      Intraday State
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
/*## operation ICEXP_v_SlopeRatioControl(ICEXP_S_Obj *) */
static void ICEXP_v_SlopeRatioControl(ICEXP_S_Obj * ps_ICObj);

//*****************************************************************************
//  Functionname:  ICEXP_v_UpdateFilterHistory
//  
//  Description:
//    Updates the luma filter history.
//      1. Shift in new value of 'ps_ICObj->ui32_Luma'
//      2. Update 'ps_ICObj->ui16_FilterHistoryCount', which reflects the number of valid values
//         which are present in the history buffer.
//  
//  Preconditions:
//    - ICEXP object 'ps_ICObj' must be initialized
//    - Settings must have been provided via ICEXP_e_SetControlParameters()
//    - State data of working object 'ps_ICObj' must reflect correct values for 'ps_ICObj->ui32_Luma'
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
/*## operation ICEXP_v_UpdateFilterHistory(ICEXP_S_Obj *) */
static void ICEXP_v_UpdateFilterHistory(ICEXP_S_Obj * ps_ICObj);

/*## operation ICEXP_e_MeasFreezeBuffer(ICEXP_S_Obj *,ICEXP_S_MeasData *) */
ICEXP_E_ERROR ICEXP_e_MeasFreezeBuffer(ICEXP_S_Obj * ps_ICObj, ICEXP_S_MeasData * ps_MeasData) {
    /*#[ operation ICEXP_e_MeasFreezeBuffer(ICEXP_S_Obj *,ICEXP_S_MeasData *) */
    ICEXP_E_ERROR e_Ret = ICEXP_e_ERR_OK;
    
    if ((NULL == ps_ICObj) || (ps_MeasData == NULL))
    {
      e_Ret = ICEXP_e_ERR_NULLPOINTER;
    }
    else if (ps_ICObj->e_ModuleState == ICEXP_e_STATE_CLOSED)
    {
      e_Ret = ICEXP_e_ERR_MODULESTATE;
    }
    else
    {
    
      // Fill contents of measurement buffer
      ps_ICObj->ui32_MeasCounter++;
      ps_MeasData->s_Parameters       = *ps_ICObj->ps_Parameters;
      ps_MeasData->s_Input            = *ps_ICObj->ps_Input;
      ps_MeasData->s_Output           =  ps_ICObj->s_Output;
      ps_MeasData->s_StateBeforeRun   =  ps_ICObj->s_EntryState;
      ps_MeasData->s_StateAfterRun    =  ps_ICObj->s_State;
      ps_MeasData->ui32_MeasCounter   =  ps_ICObj->ui32_MeasCounter;
    }
    
    return e_Ret;
    /*#]*/
}

/*## operation ICEXP_e_RunControl(ICEXP_S_Obj *,ICEXP_S_Output * *) */
ICEXP_E_ERROR ICEXP_e_RunControl(ICEXP_S_Obj * ps_ICObj, ICEXP_S_Output * * pps_Output) {
    /*#[ operation ICEXP_e_RunControl(ICEXP_S_Obj *,ICEXP_S_Output * *) */
    ICEXP_S_Settings * ps_Settings   = NULL;
    ICEXP_S_Input    * ps_Input      = NULL;
    ICEXP_S_Output   * ps_Output     = NULL;
    ICEXP_S_State    * ps_State      = NULL;
    ICEXP_S_State    * ps_EntryState = NULL;
    ICEXP_E_ERROR      e_Ret         = ICEXP_e_ERR_OK;
    const uint32 ui32_FAST_LUMA_REDUCT_LIMIT = 0xFFFF;
    const uint16 ui16_SLOPE_4X = 4u;
    const uint16 cui16_DEFAULT_EXPOSURETIME_us = 1000;
    
    // Precondition checks
    if ((ps_ICObj == NULL) || (pps_Output == NULL))
    {
      e_Ret = ICEXP_e_ERR_NULLPOINTER;
    }
    else if (ICEXP_e_STATE_EXEC != ps_ICObj->e_ModuleState)
    {
      e_Ret = ICEXP_e_ERR_MODULESTATE;
    }
    else if (NULL == ps_ICObj->ps_Parameters)
    {
      e_Ret = ICEXP_e_ERR_NO_PARAMS_SET;
    }
    else
    {
      // Assign pointers for our working data
      ps_Settings   =  ps_ICObj->ps_Parameters;
      ps_Input      =  ps_ICObj->ps_Input;
      ps_Output     = &ps_ICObj->s_Output;
      ps_State      = &ps_ICObj->s_State;
      ps_EntryState = &ps_ICObj->s_EntryState;
    
      // Copy inputs to state
      ps_State->ui32_Luma                           = ps_Input->ui32_LumaMean;
      ps_State->ui32_MeanLow                        = ps_Input->ui32_HistEndMeanLow;
      ps_State->ui32_MeanNormal                     = ps_Input->ui32_LumaMean;
      ps_State->f32_BrightnessCdqm                  = ps_Input->f32_BrightnessCdqm;
    
      // Only use exposure settings from imager if we had not been forced to compensate a forced DCG change.
      // In the latter case we keep old state variables, which reflect the values of exposure control before
      // forced DCG overwrite compensation.
      if (ICEXP_e_FORCED_DCG_COMP_DISABLED == ps_State->e_ForcedDcgCompensation)
      {
        ps_State->e_DCGState                          = ps_Input->e_DCGState;
        ps_State->ui16_ExposureTimeUs                 = ps_Input->ui16_ExposureTimeUs;
        ps_State->ui32_ExposureTimeOutBeforeLimit_us  = ps_Input->ui16_ExposureTimeUs;
      }
      ps_State->e_ForcedDcgCompensation = ICEXP_e_FORCED_DCG_COMP_DISABLED;
    
      // Always start with a digital gain of 1.0f
      ps_State->f32_DigitalGain = 1.0f;
    
      // Remember entry-state to track differences from entry vs. exit
      *ps_EntryState = *ps_State;
    
      // Overwrite DCG-State if we are not in auto-mode
      if (ICEXP_e_DCGMODE_ALWAYS_LOW == ps_Settings->e_DCGControl)
      {
        ps_State->e_DCGState = IC_e_DCG_LOW;
      }
      else if (ICEXP_e_DCGMODE_ALWAYS_HIGH == ps_Settings->e_DCGControl)
      {
        ps_State->e_DCGState = IC_e_DCG_HIGH;
      }
      else
      {
        // Do not change DTC here
      }
    
      // Calculate weighted mean and fraction of saturated pixels
      if (ps_State->ui16_SlopeRatioR1 == ui16_SLOPE_4X)
      {
        ps_State->ui32_MeanWeighted = ICEXP_ui32_CalcLumaFromHist(
            ps_Input->ps_HistogramData,
            ps_Settings->ps_HistWeights_4x16x,
            ps_Settings->ps_HistBinParams,
            &ps_Output->ui32_NumHistogramPixels);
        ps_Output->f32_SaturatedPixelsFraction = (float32)ps_Input->ps_HistogramData->aui32_Bins[ICEXP_cui16_SaturatedPixelsBin4x16x]
                                               / (float32)ps_Output->ui32_NumHistogramPixels;
      }
      else
      {
        ps_State->ui32_MeanWeighted = ICEXP_ui32_CalcLumaFromHist(
            ps_Input->ps_HistogramData,
            ps_Settings->ps_HistWeights_16x16x,
            ps_Settings->ps_HistBinParams,
            &ps_Output->ui32_NumHistogramPixels);
        ps_Output->f32_SaturatedPixelsFraction = (float32)ps_Input->ps_HistogramData->aui32_Bins[ICEXP_cui16_SaturatedPixelsBin16x16x]
                                               / (float32)ps_Output->ui32_NumHistogramPixels;
      }
    
      // Copy into luma if weighted mean enabled
      if (b_TRUE == ps_Settings->b_UseWeightedMean)
      {
        ps_State->ui32_Luma = ps_State->ui32_MeanWeighted;
      }
    
      // Filter incoming luma-values
      ICEXP_v_LumaFilter(ps_ICObj);
    
      // Check night-mode conditions
      ICEXP_v_IntradayStateControl(ps_ICObj);
    
      // Are we in forced-night-mode?
      if (b_TRUE == ps_Settings->b_ForceNightMode)
      {
        if (ICEXP_e_DCGMODE_ALWAYS_LOW == ps_Settings->e_DCGControl)
        {
          ps_State->e_DCGState = IC_e_DCG_LOW;
        }
        else
        {
          ps_State->e_DCGState = IC_e_DCG_HIGH;
        }
        ps_State->ui16_ExposureTimeUs = ps_Settings->ui16_MaxExposureT1us;
        ps_State->ui32_ExposureTimeOutBeforeLimit_us = ps_Settings->ui16_MaxExposureT1us;
        ps_State->e_IntradayState = IC_e_INTRADAY_STATE_NIGHT;
      }
      else if(b_TRUE == ICEXP_b_LumaIsInRange(ps_ICObj, ps_State->ui32_Luma))
      {
        // Current luma is in range, so do nothing
      }
      else if (0 == ps_State->ui32_Luma)
      {
        // No histogram information is available at this moment.
        // Set exposure time and DCG state on their start values
        ps_State->ui16_ExposureTimeUs = cui16_DEFAULT_EXPOSURETIME_us;
        if (ICEXP_e_DCGMODE_ALWAYS_HIGH == ps_Settings->e_DCGControl)
        {
          ps_State->e_DCGState = IC_e_DCG_HIGH;
        }
        else
        {
          ps_State->e_DCGState = IC_e_DCG_LOW;
        }
      }
      else
      {
        // Determine new values for DCG state and exposure time
        if(ui32_FAST_LUMA_REDUCT_LIMIT <= ps_State->ui32_Luma)
        {
          // Current luma is too big, run fast luma reduction
          ICEXP_v_FastLumaReduction(ps_ICObj);
        }
        else
        {
          // Night-Mode?
          if(ps_State->e_IntradayState == IC_e_INTRADAY_STATE_NIGHT)
          {
            //Set exposuretime on max value and dcg state on to ON and set night mode
            ps_State->ui16_ExposureTimeUs = ps_Settings->ui16_MaxExposureT1us;
            ps_State->e_DCGState          = IC_e_DCG_HIGH;
          }
    
          // Day-mode
          else
          {
            // Have new exposure time calculated
            ICEXP_v_ExposureTimeCalculation(ps_ICObj);
    
            // Run DCG control
            ICEXP_v_DCGControl(ps_ICObj);
          }
        }
      }
    
      // Run Slope Ratio Control (16x/16x vs. 4x/16x); Note: May modify exposure-time
      ICEXP_v_SlopeRatioControl(ps_ICObj);
    
      // Check if new exposure time is in range
      ICEXP_v_ExposureTimeLimit(ps_ICObj);
    
      // Copy the internal states to output
      ps_Output->e_IntradayState      = ps_State->e_IntradayState;
      ps_Output->ui16_SlopeRatioR1    = ps_State->ui16_SlopeRatioR1;
      ps_Output->ui16_SlopeRatioR2    = ps_State->ui16_SlopeRatioR2;
      ps_Output->e_DCGState           = ps_State->e_DCGState;
      ps_Output->ui16_ExposureTimeUs  = ps_State->ui16_ExposureTimeUs;
      ps_Output->f32_DigitalGain      = ps_State->f32_DigitalGain;
      ps_Output->ui32_MeanWeighted    = ps_State->ui32_MeanWeighted;
      ps_Output->ui32_ExposureTimeOutBeforeLimit_us = ps_State->ui32_ExposureTimeOutBeforeLimit_us;
      *pps_Output = ps_Output;
    
      // If DCG or Slope-Ratios changed, reset luma-filter
      if ((ps_EntryState->e_DCGState        != ps_State->e_DCGState) ||
          (ps_EntryState->ui16_SlopeRatioR1 != ps_State->ui16_SlopeRatioR1) ||
          (ps_EntryState->ui16_SlopeRatioR2 != ps_State->ui16_SlopeRatioR2))
      {
        ps_State->ui16_FilterHistoryCount = 0;
      }
    
      // Goto next state
      ps_ICObj->e_ModuleState = ICEXP_e_STATE_INPUT;
    }
    
    return e_Ret;
    
    // PRQA S 7002 3
    /*#]*/
}

/*## operation ICEXP_e_SetControlInput(ICEXP_S_Obj *,ICEXP_S_Input *) */
ICEXP_E_ERROR ICEXP_e_SetControlInput(ICEXP_S_Obj * ps_ICObj, ICEXP_S_Input * ps_ICInput) {
    /*#[ operation ICEXP_e_SetControlInput(ICEXP_S_Obj *,ICEXP_S_Input *) */
    ICEXP_E_ERROR e_Ret = ICEXP_e_ERR_OK;
    
    // Precondition check
    if ((NULL == ps_ICObj) || (NULL == ps_ICInput))
    {
      e_Ret = ICEXP_e_ERR_NULLPOINTER;
    }
    else if (NULL == ps_ICInput->ps_HistogramData)
    {
      e_Ret = ICEXP_e_ERR_NULLPOINTER;
    }
    else if (ICEXP_e_STATE_INPUT != ps_ICObj->e_ModuleState)
    {
      e_Ret = ICEXP_e_ERR_MODULESTATE;
    }
    else
    {
      // Set input values for exposure control
      ps_ICObj->ps_Input = ps_ICInput;
    
      // Switch to next state
      ps_ICObj->e_ModuleState = ICEXP_e_STATE_EXEC;
    }
    return e_Ret;
    /*#]*/
}

/*## operation ICEXP_e_SetControlParameters(ICEXP_S_Obj *,ICEXP_S_Settings *) */
ICEXP_E_ERROR ICEXP_e_SetControlParameters(ICEXP_S_Obj * ps_ICObj, ICEXP_S_Settings * ps_Settings) {
    /*#[ operation ICEXP_e_SetControlParameters(ICEXP_S_Obj *,ICEXP_S_Settings *) */
    const float32 cf32_MIN_ATTENUATION = 0.5f;
    const float32 cf32_MAX_ATTENUATION = 1.0f;
    ICEXP_E_ERROR e_Ret = ICEXP_e_ERR_OK;
    
    // Nullpointer?
    if ((NULL == ps_Settings) || (NULL == ps_ICObj))
    {
      e_Ret = ICEXP_e_ERR_NULLPOINTER;
    }
    // Attenuation within range?
    else if ((ps_Settings->f32_Attenuation < cf32_MIN_ATTENUATION)
          || (ps_Settings->f32_Attenuation > cf32_MAX_ATTENUATION))
    {
      e_Ret = ICEXP_e_ERR_PARAM_ATTENUATION;
    }
    // Number of filter taps exceeded?
    else if (ps_Settings->ui16_LumaFilterDepth > ICEXP_cui_MAX_LUMA_FILTER_VALUES)
    {
      e_Ret = ICEXP_e_ERR_PARAM_LUMAFILTER_DEPTH;
    }
    // Check MAX > MIN
    else if (ps_Settings->ui16_DCGThresholdHighUs < ps_Settings->ui16_DCGThresholdLowUs)
    {
      e_Ret = ICEXP_e_ERR_PARAM_DCG_THRESHOLD;
    }
    // Target-Luma is between Min/Max NoControl ?
    else if ((ps_Settings->ui16_LumaMaxNoControl < ps_Settings->f32_TargetLuma) ||
             (ps_Settings->ui16_LumaMinNoControl > ps_Settings->f32_TargetLuma))
    {
      e_Ret = ICEXP_e_ERR_PARAM_LUMA_MINMAX_NC;
    }
    else
    {
      // Everything ok, import parameters
      ps_ICObj->ps_Parameters = ps_Settings;
    }
    
    return e_Ret;
    
    /*#]*/
}

/*## operation ICEXP_ui16_RoundTimeNearestLineCnt(const ICEXP_S_Obj *,uint16) */
uint16 ICEXP_ui16_RoundTimeNearestLineCnt(const ICEXP_S_Obj * ps_ICObj, uint16 ui16_TimeUs) {
    /*#[ operation ICEXP_ui16_RoundTimeNearestLineCnt(const ICEXP_S_Obj *,uint16) */
    uint16 ui16_RetVal = 0;
    uint32 ui32_TimeNs = IC_ui32_CONV_us_ns(ui16_TimeUs);            /* Convert to ns              */
    if (NULL == ps_ICObj)
    {
      ui16_RetVal = 0;
    }
    else
    {
      ui32_TimeNs += ps_ICObj->ps_Parameters->ui32_LineTimeNs / 2;     /* Add half line for rounding */ // PRQA S 3120
      ui32_TimeNs /= ps_ICObj->ps_Parameters->ui32_LineTimeNs;         /* Convert to lines           */
      ui32_TimeNs *= ps_ICObj->ps_Parameters->ui32_LineTimeNs;         /* Convert back to us         */
      ui16_RetVal = (uint16)IC_ui32_CONV_ns_us(ui32_TimeNs);
    }
    return ui16_RetVal;
    /*#]*/
}

/*## operation ICEXP_v_Init(ICEXP_S_Obj *) */
void ICEXP_v_Init(ICEXP_S_Obj * ps_ICObj) {
    /*#[ operation ICEXP_v_Init(ICEXP_S_Obj *) */
    const uint16  cui16_DEFAULT_SLOPE_R1        = 16;
    const uint16  cui16_DEFAULT_SLOPE_R2        = 16;
    const uint16  cui16_DEFAULT_MEAN            = 1000;
    const uint16  cui16_DEFAULT_EXPOSURETIME_us = 1000;
    const float32 cf32_DEFAULT_DIGI_GAIN        = 1.0f;
    ICEXP_S_State * ps_State;
    uint32 ui32_Index;
    
    if (NULL != ps_ICObj)
    {
      ps_State = &ps_ICObj->s_State;
      ps_ICObj->e_ModuleState                   = ICEXP_e_STATE_INPUT;
      ps_ICObj->ps_Input                        = 0;
      ps_ICObj->ps_Parameters                   = 0;
      ps_State->f32_DigitalGain                 = cf32_DEFAULT_DIGI_GAIN;
      ps_State->f32_BrightnessCdqm              = 0.0f;
      ps_State->ui16_IntradayFrameCountDay      = 0;
      ps_State->ui16_IntradayFrameCountNight    = 0;
      ps_State->e_IntradayState                 = IC_e_INTRADAY_STATE_DAY;
      ps_State->ui16_SlopeRatioR1               = cui16_DEFAULT_SLOPE_R1;
      ps_State->ui16_SlopeRatioR2               = cui16_DEFAULT_SLOPE_R2;
      ps_State->ui16_FilterHistoryCount         = 0;
      ps_State->e_DCGState                      = IC_e_DCG_LOW;
      ps_State->ui32_Luma                       = 0;
      ps_State->ui32_MeanLow                    = 0;
      ps_State->ui32_MeanNormal                 = 0;
      ps_State->ui32_MeanWeighted               = 0;
      for (ui32_Index = 0; ui32_Index < IC_ARRLEN(ps_State->as_FilterHistory); ui32_Index++)
      {
        ps_State->as_FilterHistory[ui32_Index].ui32_Mean            = cui16_DEFAULT_MEAN;
        ps_State->as_FilterHistory[ui32_Index].ui16_ExposureTimeUs  = cui16_DEFAULT_EXPOSURETIME_us;
        ps_State->as_FilterHistory[ui32_Index].f32_BrightnessCdqm   = 0.0f;
      }
    }
    /*#]*/
}

/*## operation ICEXP_v_OverwriteDcgOutputCompensated(ICEXP_S_Obj *,IC_E_DCG_STATE) */
void ICEXP_v_OverwriteDcgOutputCompensated(ICEXP_S_Obj * ps_ICObj, IC_E_DCG_STATE e_ForcedValue) {
    /*#[ operation ICEXP_v_OverwriteDcgOutputCompensated(ICEXP_S_Obj *,IC_E_DCG_STATE) */
    ICEXP_S_Output * const ps_Out = &ps_ICObj->s_Output; // PRQA S 506
    uint16  ui16_OldExpTotalUs = 0;
    uint16  ui16_NewExpTotalUs = 0;
    uint16  ui16_NewT1         = 0;
    float32 f32_ExpTimeGain    = 0.0f;
    float32 f32_RemGain        = 0.0f;
    
    // Only overwrite and compensate DCG if we need to
    if (ps_Out->e_DCGState != e_ForcedValue)
    {
      if (IC_e_DCG_HIGH == e_ForcedValue)
      {
        // Compensate DCG factor first by reducing exposure time, then calculate remaining
        // gain and apply it to the digital gain.
        //
        // NOTE: We are allowed to go below minimum exposure time for this special case
        ui16_OldExpTotalUs = ICEXP_ui16_CalcTges(ps_ICObj, ps_Out->ui16_ExposureTimeUs);
        ui16_NewExpTotalUs = (uint16)((float32)ui16_OldExpTotalUs / ps_ICObj->ps_Parameters->f32_DCGGainFactor); // PRQA S 4119
        ui16_NewExpTotalUs = MAX(ui16_NewExpTotalUs, ps_ICObj->ps_Parameters->ui16_CriticalMinTotalExposureUs);  // PRQA S 4119
        ui16_NewT1         = ICEXP_ui16_CalcT1(ps_ICObj, ui16_NewExpTotalUs);
        f32_ExpTimeGain    = (float32)ui16_NewExpTotalUs / (float32)ui16_OldExpTotalUs;
        f32_RemGain        = 1.0f / (ps_ICObj->ps_Parameters->f32_DCGGainFactor * f32_ExpTimeGain);
        ps_Out->f32_DigitalGain    *= f32_RemGain;
        ps_Out->ui16_ExposureTimeUs = ui16_NewT1;
        ps_Out->e_DCGState          = IC_e_DCG_HIGH;
        ps_ICObj->s_State.e_ForcedDcgCompensation = ICEXP_e_FORCED_DCG_COMP_TOHIGH;
      }
      else
      {
        // Compensate DCG factor first by increasing exposure time, then calculate remaining
        // gain and apply it to the digital gain.
        //
        // NOTE: We are allowed to go above maximum exposure time for this special case,
        //       but we need to take into account that T2 has a maximum value of XX lines!
        ui16_OldExpTotalUs = ICEXP_ui16_CalcTges(ps_ICObj, ps_Out->ui16_ExposureTimeUs);
        ui16_NewExpTotalUs = (uint16)((float32)ui16_OldExpTotalUs * ps_ICObj->ps_Parameters->f32_DCGGainFactor); // PRQA S 4119
        ui16_NewExpTotalUs = MIN(ui16_NewExpTotalUs, ps_ICObj->ps_Parameters->ui16_CriticalMaxTotalExposureUs);
        ui16_NewT1         = ICEXP_ui16_CalcT1(ps_ICObj, ui16_NewExpTotalUs);
        f32_ExpTimeGain   = (float32)ui16_NewExpTotalUs / (float32)ui16_OldExpTotalUs;
        f32_RemGain       = (ps_ICObj->ps_Parameters->f32_DCGGainFactor / f32_ExpTimeGain);
        ps_Out->f32_DigitalGain    *= f32_RemGain;
        ps_Out->ui16_ExposureTimeUs = ui16_NewT1;
        ps_Out->e_DCGState          = IC_e_DCG_LOW;
        ps_ICObj->s_State.e_ForcedDcgCompensation = ICEXP_e_FORCED_DCG_COMP_TOLOW;
      }
    }
    /*#]*/
}

/*## operation ICEXP_b_LumaIsInRange(const ICEXP_S_Obj *,uint32) */
static boolean ICEXP_b_LumaIsInRange(const ICEXP_S_Obj * ps_ICObj, uint32 ui32_Luma) {
    /*#[ operation ICEXP_b_LumaIsInRange(const ICEXP_S_Obj *,uint32) */
    boolean b_Ret = b_FALSE;
    
    // Function is static - nullpointer checks are already done:
    // PRQA S 0506 2
    if ((ui32_Luma >= ps_ICObj->ps_Parameters->ui16_LumaMinNoControl)
     && (ui32_Luma <= ps_ICObj->ps_Parameters->ui16_LumaMaxNoControl))
    {
      b_Ret = b_TRUE;
    }
    return b_Ret;
    /*#]*/
}

/*## operation ICEXP_ui16_CalcT1(const ICEXP_S_Obj *,uint16) */
static uint16 ICEXP_ui16_CalcT1(const ICEXP_S_Obj * ps_ICObj, uint16 ui16_Ttot) {
    /*#[ operation ICEXP_ui16_CalcT1(const ICEXP_S_Obj *,uint16) */
    // Create some short named variables to gain better readable formulas
    //
    // Function is static - nullpointer checks are already done:
    // PRQA S 0506 4
    const uint32 ui32_R1      = (uint32)ps_ICObj->s_State.ui16_SlopeRatioR1;
    const uint32 ui32_R2      = (uint32)ps_ICObj->s_State.ui16_SlopeRatioR2;
    const uint32 ui32_T2max   = (uint32)ps_ICObj->ps_Parameters->ui16_MaxPossibleT2us;
    const uint32 ui32_T3max   = (uint32)ps_ICObj->ps_Parameters->ui16_MaxPossibleT3us;
    const uint32 ui32_MaxTtot = (ui32_R1 * ui32_T2max) + ui32_T2max + ui32_T3max;
    const uint32 ui32_Ttot    = (uint32)ui16_Ttot;
    uint32 ui32_T1            = 0u;
    
    if (ui32_Ttot > ui32_MaxTtot)
    {
      ui32_T1 = ui32_Ttot - ui32_T2max - ui32_T3max;
    }
    else
    {
      ui32_T1 = (ui32_Ttot * ui32_R1 * ui32_R2) / ((ui32_R1*ui32_R2) + ui32_R2 + 1);
    }
    return (uint16)ui32_T1;
    /*#]*/
}

/*## operation ICEXP_ui16_CalcTges(const ICEXP_S_Obj *,uint16) */
static uint16 ICEXP_ui16_CalcTges(const ICEXP_S_Obj * ps_ICObj, uint16 ui16_T1us) {
    /*#[ operation ICEXP_ui16_CalcTges(const ICEXP_S_Obj *,uint16) */
    // Function is static - nullpointer checks are already done:
    // PRQA S 0506 FUNC_END_CALCTGES
    const uint16 ui16_R1 = ps_ICObj->s_State.ui16_SlopeRatioR1;
    const uint16 ui16_R2 = ps_ICObj->s_State.ui16_SlopeRatioR2;
    uint16 ui16_T2us = 0;
    uint16 ui16_T3us = 0;
    uint16 ui16_Tges = 0;
    
    ui16_T2us = MIN(ui16_T1us / ui16_R1, ps_ICObj->ps_Parameters->ui16_MaxPossibleT2us);
    ui16_T3us = MIN(ui16_T2us / ui16_R2, ps_ICObj->ps_Parameters->ui16_MaxPossibleT3us);
    ui16_Tges = ui16_T1us + ui16_T2us + ui16_T3us;
    
    return ui16_Tges;
    // PRQA L:FUNC_END_CALCTGES
    /*#]*/
}

/*## operation ICEXP_ui32_CalcLumaFromHist(const IC_S_Histogram *,const IC_S_HistogramWeights *,const IC_S_HistogramBinParams *,uint32 *) */
static uint32 ICEXP_ui32_CalcLumaFromHist(const IC_S_Histogram * ps_HistData, const IC_S_HistogramWeights * ps_Weights, const IC_S_HistogramBinParams * ps_BinParams, uint32 * pui32_NumHistogramValuesOut) {
    /*#[ operation ICEXP_ui32_CalcLumaFromHist(const IC_S_Histogram *,const IC_S_HistogramWeights *,const IC_S_HistogramBinParams *,uint32 *) */
    // Function is static - nullpointer checks are already done:
    // PRQA S 0506 FUNC_CALCLUMAFROMHIST
    uint64 ui64_HistSum             = 0;
    uint64 ui32_WeightSum           = 0;
    uint32 ui32_WeightedFrequency   = 0;
    uint32 ui32_NumHistogramValues  = 0;
    uint32 ui32_Index               = 0;
    uint32 ui32_Result              = 0;
    
    // Loop through histogram values and apply weights for calculation of a 'weighted' histogram mean
    for (ui32_Index = 0; ui32_Index < ICCFG_cui16_NumHistogramValues; ui32_Index++)
    {
      ui32_NumHistogramValues += ps_HistData->aui32_Bins[ui32_Index];
      ui32_WeightedFrequency   = ps_HistData->aui32_Bins[ui32_Index] * (uint32)ps_Weights->aui16_Weights[ui32_Index];
      ui64_HistSum            += (uint64)ui32_WeightedFrequency * (uint64)ps_BinParams->aui32_CenterValue[ui32_Index];
      ui32_WeightSum          += ui32_WeightedFrequency;
    }
    
    // Calculate final value (and prevent division by zero)
    if (ui32_WeightSum != 0)
    {
      ui32_Result = (uint32)(ui64_HistSum / ui32_WeightSum);
    }
    else
    {
      // Histogram does not contain any data, so luma is also ZERO (should never happen)
      ui32_Result = 0;
    }
    
    // In case the caller want's to know the number of total histogram samples, set corresponding output value
    if (NULL != pui32_NumHistogramValuesOut)
    {
      *pui32_NumHistogramValuesOut = ui32_NumHistogramValues;
    }
    return ui32_Result;
    // PRQA L:FUNC_CALCLUMAFROMHIST
    /*#]*/
}

/*## operation ICEXP_v_DCGControl(ICEXP_S_Obj *) */
static void ICEXP_v_DCGControl(ICEXP_S_Obj * ps_ICObj) {
    /*#[ operation ICEXP_v_DCGControl(ICEXP_S_Obj *) */
    // Function is static - nullpointer checks are already done:
    // PRQA S 0506 FUNC_DCGControl
    ICEXP_S_Settings * const ps_Settings =  ps_ICObj->ps_Parameters;
    ICEXP_S_State    * const ps_State    = &ps_ICObj->s_State;
    
    // Assign exposure time to float
    const float32 f32_ExposureTime = (float32)ps_State->ui16_ExposureTimeUs;
    
    // Only do modifications to DCG-State if we are in auto-mode
    if (ICEXP_e_DCGMODE_AUTO == ps_Settings->e_DCGControl)
    {
      // Check current DCG state and exposure time
      if(  (IC_e_DCG_HIGH == ps_State->e_DCGState)
         &&(ps_Settings->ui16_DCGThresholdLowUs > ps_State->ui16_ExposureTimeUs))
      {
        // switch DCG off and correct exposure-time for new gain
        ps_State->e_DCGState          = IC_e_DCG_LOW;
        ps_State->ui16_ExposureTimeUs = (uint16)(f32_ExposureTime * ps_Settings->f32_DCGGainFactor); // PRQA S 4119
      }
      else if(  (IC_e_DCG_LOW == ps_State->e_DCGState)
              &&(ps_Settings->ui16_DCGThresholdHighUs < ps_State->ui16_ExposureTimeUs))
      {
        // switch DCG on and correct exposure-time for new gain
        ps_State->e_DCGState          = IC_e_DCG_HIGH;
        ps_State->ui16_ExposureTimeUs = (uint16)(f32_ExposureTime / ps_Settings->f32_DCGGainFactor); // PRQA S 4119
      }
      else
      {
        // Anything is ok, set new dcg state on the current dcg state
        // Keep the exposure time unchanged
      }
    }
    else
    {
      // Not in auto-mode, so don't modify DCG-State
    }
    
    // PRQA L:FUNC_DCGControl
    /*#]*/
}

/*## operation ICEXP_v_ExposureTimeCalculation(ICEXP_S_Obj *) */
static void ICEXP_v_ExposureTimeCalculation(ICEXP_S_Obj * ps_ICObj) {
    /*#[ operation ICEXP_v_ExposureTimeCalculation(ICEXP_S_Obj *) */
    // Function is static - nullpointer checks are already done:
    // PRQA S 0506 FUNC_ExposureTimeCalculation
    ICEXP_S_Settings * const ps_Settings =  ps_ICObj->ps_Parameters;
    ICEXP_S_State    * const ps_State    = &ps_ICObj->s_State;
    const uint16 ui16_MAXVAL_UI16 = 0xFFFF;
    
    // Calculation is done with float, so convert INTs
    const float32 f32_InExposureTime_us = (float32)(ps_State->ui16_ExposureTimeUs);
    const float32 f32_InLuma            = (float32)(ps_State->ui32_Luma);
    
    // Calculate new exposure time  
    const float32 f32_ExposureTime = f32_InExposureTime_us *
            (1.0f + (ps_Settings->f32_Attenuation * ((ps_Settings->f32_TargetLuma/f32_InLuma) - 1.0f)));
    
    // Convert/Limit value to uint16
    if(f32_ExposureTime <= (float32)ui16_MAXVAL_UI16)
    {
      ps_State->ui16_ExposureTimeUs = (uint16)f32_ExposureTime;
    }
    else
    {
      ps_State->ui16_ExposureTimeUs = ui16_MAXVAL_UI16;
    }
    
    // PRQA L:FUNC_ExposureTimeCalculation
    /*#]*/
}

/*## operation ICEXP_v_ExposureTimeLimit(ICEXP_S_Obj *) */
static void ICEXP_v_ExposureTimeLimit(ICEXP_S_Obj * ps_ICObj) {
    /*#[ operation ICEXP_v_ExposureTimeLimit(ICEXP_S_Obj *) */
    // Function is static - nullpointer checks are already done:
    // PRQA S 0506 FUNC_ExposureTimeLimit
    ICEXP_S_State    * const ps_State    = &ps_ICObj->s_State;
    ICEXP_S_Settings * const ps_Settings =  ps_ICObj->ps_Parameters;
    
    // Store old exposure time before applying limits
    ps_State->ui32_ExposureTimeOutBeforeLimit_us = ps_State->ui16_ExposureTimeUs;
    
    if(ps_Settings->ui16_MaxExposureT1us < ps_State->ui16_ExposureTimeUs)
    {
      // Calculated exposure time is too big, set it to its max value
      ps_State->ui16_ExposureTimeUs = ps_Settings->ui16_MaxExposureT1us;
    }
    else if(ps_Settings->ui16_MinExposureT1us > ps_State->ui16_ExposureTimeUs)
    {
      // Calculated exposure time is too small, set it to its min value
      ps_State->ui16_ExposureTimeUs = ps_Settings->ui16_MinExposureT1us;
    }
    else
    {
      // Exposure time is in range, do not change
    }
    // PRQA L:FUNC_ExposureTimeLimit
    /*#]*/
}

/*## operation ICEXP_v_FastLumaReduction(ICEXP_S_Obj *) */
static void ICEXP_v_FastLumaReduction(ICEXP_S_Obj * ps_ICObj) {
    /*#[ operation ICEXP_v_FastLumaReduction(ICEXP_S_Obj *) */
    // Function is static - nullpointer checks are already done:
    // PRQA S 0506 FUNC_FastLumaReduction
    ICEXP_S_State    * const ps_State    = &ps_ICObj->s_State;
    ICEXP_S_Settings * const ps_Settings =  ps_ICObj->ps_Parameters;
    const uint16 ui16_EXPOSURE_DIVISOR = (uint16)2;
    
    // Enter day-mode if we are in night-mode: This avoids toggling DCG in night-mode if
    // the image gets suddenly very bright
    if (ps_State->e_IntradayState == IC_e_INTRADAY_STATE_NIGHT)
    {
      ps_State->e_IntradayState = IC_e_INTRADAY_STATE_DAY;
    }
    
    // Check whether DCG-State is locked (non-auto-mode)
    if (ICEXP_e_DCGMODE_AUTO != ps_Settings->e_DCGControl)
    {
      // DCG-State is locked by configuration, so half exposure-time
      ps_State->ui16_ExposureTimeUs = (uint16)(ps_State->ui16_ExposureTimeUs / ui16_EXPOSURE_DIVISOR);
    }
    else if(IC_e_DCG_HIGH == ps_State->e_DCGState)
    {
      // DCG state is on, so switch DCG off and keep the exposure time unchanged
      ps_State->e_DCGState = IC_e_DCG_LOW;
    }
    else
    { 
      // DCG state is already off, halve the exposure time
      ps_State->e_DCGState          = IC_e_DCG_LOW;
      ps_State->ui16_ExposureTimeUs = (uint16)(ps_State->ui16_ExposureTimeUs / ui16_EXPOSURE_DIVISOR);
    }
    // PRQA L:FUNC_FastLumaReduction
    /*#]*/
}

/*## operation ICEXP_v_IntradayStateControl(ICEXP_S_Obj *) */
static void ICEXP_v_IntradayStateControl(ICEXP_S_Obj * ps_ICObj) {
    /*#[ operation ICEXP_v_IntradayStateControl(ICEXP_S_Obj *) */
    // Function is static - nullpointer checks are already done:
    // PRQA S 0506 FUNC_IntradayStateControl
    ICEXP_S_State    * const ps_State     = &ps_ICObj->s_State;
    ICEXP_S_Input    * const ps_CtrlInput =  ps_ICObj->ps_Input;
    ICEXP_S_Settings * const ps_Settings  =  ps_ICObj->ps_Parameters;
    uint32 ui32_LumaForComparation = 0;
    uint16 ui16_ExpTimeRoundup     = 0;
    
    // Fixed to day or night?
    if (ps_Settings->e_NightModeCondition == ICEXP_e_NIGHTMODECOND_ALWAYS_DAY)
    {
      ps_State->e_IntradayState = IC_e_INTRADAY_STATE_DAY;
    }
    else if (ps_Settings->e_NightModeCondition == ICEXP_e_NIGHTMODECOND_ALWAYS_NIGHT)
    {
      ps_State->e_IntradayState = IC_e_INTRADAY_STATE_NIGHT;
    }
    else
    {
      // Determine input luma value for nightmode-condition
      if (ps_Settings->e_NightModeCondition == ICEXP_e_NIGHTMODECOND_USE_MEAN)
      {
        ui32_LumaForComparation = ps_State->ui32_Luma;
      }
      else
      {
        ui32_LumaForComparation = ps_CtrlInput->ui32_HistEndMeanLow;
      }
    
      // Determine condition to enter night-mode.
      //
      // NOTE: Day-mode has higher priority than night-mode and might overwrite the IntradayState below.
      //
      // Account for rounding-errors in comparation current_exposure <=> maximum_exposure_time by adding
      // nearly a line:
      ui16_ExpTimeRoundup = (ps_State->ui16_ExposureTimeUs + (uint16)IC_ui32_CONV_ns_us(ps_Settings->ui32_LineTimeNs)) - 1;
      if(  (   (ps_State->e_DCGState              == IC_e_DCG_HIGH)
            && (ui32_LumaForComparation           <  ps_Settings->ui16_IntradayThresNight_LowEndMeanMax)
            && (ps_CtrlInput->f32_PercLowEnd      >  ps_Settings->f32_IntradayThresNightPercLowEndMin)
            && (ui16_ExpTimeRoundup               >= ps_Settings->ui16_MaxExposureT1us)
           )
         || (ps_State->e_IntradayState == IC_e_INTRADAY_STATE_NIGHT)
        )
      {
        // Increment "night-condition"-counter
        if (ps_State->ui16_IntradayFrameCountNight < TYPEMAX_UI16)
        {
          ps_State->ui16_IntradayFrameCountNight++;
        }
    
        // Check if we are allowed to switch to night.
        if (ps_State->ui16_IntradayFrameCountNight >= ps_Settings->ui16_IntradayThresNight_Frames)
        {
          ps_State->e_IntradayState = IC_e_INTRADAY_STATE_NIGHT;
        }
      }
      else
      {
        ps_State->ui16_IntradayFrameCountNight = 0;
      }
    
      // Determine condition to enter day-mode
      // NOTE: Day-mode has higher priority than night-mode
      if ( ( (   (ps_CtrlInput->f32_PercLowEnd     < ps_Settings->f32_IntradayThresDay_PercLowEndMin)
              || (ui32_LumaForComparation          > (uint32)ps_Settings->ui16_IntradayThresDay_LowEndMeanMax)
             )
             && (ps_State->ui32_Luma             > (uint32)ps_Settings->ui16_IntradayThresDay_LumaMax)
           )
           || (ps_CtrlInput->f32_PercLowEnd == 0.0f) // PRQA S 3341
         )
      {
        // Increment "day-condition"-counter
        if (ps_State->ui16_IntradayFrameCountDay < TYPEMAX_UI16)
        {
          ps_State->ui16_IntradayFrameCountDay++;
        }
    
        // Are we currently in night-mode? Then check if we are allowed to switch to night.
        if (ps_State->ui16_IntradayFrameCountDay >= ps_Settings->ui16_IntradayThresDay_Frames)
        {
          ps_State->e_IntradayState = IC_e_INTRADAY_STATE_DAY;
        }
        ps_State->ui16_IntradayFrameCountNight = 0;
      }
      else
      {
        ps_State->ui16_IntradayFrameCountDay = 0;
      }
    }
    
    // PRQA L:FUNC_IntradayStateControl
    /*#]*/
}

/*## operation ICEXP_v_LumaFilter(ICEXP_S_Obj *) */
static void ICEXP_v_LumaFilter(ICEXP_S_Obj * ps_ICObj) {
    /*#[ operation ICEXP_v_LumaFilter(ICEXP_S_Obj *) */
    // Function is static - nullpointer checks are already done:
    // PRQA S 0506 1
    ICEXP_S_Settings * const ps_Settings = ps_ICObj->ps_Parameters;
    
    switch (ps_Settings->e_LumaFilterMode)
    {
    case ICEXP_e_FILTER_NONE:
      /* Keep luma untouched */
      break;
    case ICEXP_e_FILTER_AVERAGE:
      ICEXP_v_LumaFilterAverage(ps_ICObj);
      break;
    case ICEXP_e_FILTER_MEDIAN:
      ICEXP_v_LumaFilterMedian(ps_ICObj);
      break;
    case ICEXP_e_FILTER_ROTH:
      ICEXP_v_LumaFilterRoth(ps_ICObj);
      break;
    case ICEXP_e_FILTER_BARATOFFSCH_ROTH:
      ICEXP_v_LumaFilterBaratoffschRoth(ps_ICObj);
      break;
    default:
      /* Keep luma untouched */
      break;
    }
    /*#]*/
}

/*## operation ICEXP_v_LumaFilterAverage(ICEXP_S_Obj *) */
static void ICEXP_v_LumaFilterAverage(ICEXP_S_Obj * ps_ICObj) {
    /*#[ operation ICEXP_v_LumaFilterAverage(ICEXP_S_Obj *) */
    // Function is static - nullpointer checks are already done:
    // PRQA S 0506 2
    ICEXP_S_State    * const ps_State    = &ps_ICObj->s_State;
    ICEXP_S_Settings * const ps_Settings = ps_ICObj->ps_Parameters;
    sint16 si_Index                = 0;
    uint64 ui64_SumOfWeightedLumas = 0;
    uint32 ui32_SumOfWeights       = 0;
    uint32 ui32_WeightedLuma       = 0;
    uint32 ui32_Luma               = 0;
    
    // Update filter-array (shift new luma into the array)
    ICEXP_v_UpdateFilterHistory(ps_ICObj);
    
    // Filter data
    for (si_Index = 0; si_Index < ps_Settings->ui16_LumaFilterDepth; si_Index++)
    {
      ui32_Luma = ps_State->as_FilterHistory[si_Index].ui32_Mean;
      ui64_SumOfWeightedLumas += (uint64)(ui32_Luma) * ps_Settings->aui16_LumaAveragerWeights[si_Index];
      ui32_SumOfWeights       += (uint32)(ps_Settings->aui16_LumaAveragerWeights[si_Index]);
    }
    
    // Prevent division by zero in case all weights are zero
    if (ui32_SumOfWeights > 0)
    {
      ui32_WeightedLuma = (uint32)(ui64_SumOfWeightedLumas / ui32_SumOfWeights);
    }
    ps_State->ui32_Luma = ui32_WeightedLuma;
    /*#]*/
}

/*## operation ICEXP_v_LumaFilterBaratoffschRoth(ICEXP_S_Obj *) */
static void ICEXP_v_LumaFilterBaratoffschRoth(ICEXP_S_Obj * ps_ICObj) {
    /*#[ operation ICEXP_v_LumaFilterBaratoffschRoth(ICEXP_S_Obj *) */
    // Function is static - nullpointer checks are already done:
    // PRQA S 0506 2
    ICEXP_S_State        * const ps_State     = &ps_ICObj->s_State;
    ICEXP_S_Settings     * const ps_Settings  =  ps_ICObj->ps_Parameters;
    ICEXP_S_HistoryEntry *       ps_LastFrame = NULL;
    boolean                      b_LumaInRangeThis;
    boolean                      b_LumaInRangePrev;
    
    // Update filter-array (shift new luma into the array)
    ICEXP_v_UpdateFilterHistory(ps_ICObj);
    
    // Pick last frame from history
    ps_LastFrame = &ps_State->as_FilterHistory[1];
    
    // Select old frame only if current luma is out of range and history-frame has good luma.
    // History must contain at least two entries
    if (ps_State->ui16_FilterHistoryCount >= 2) // PRQA S 3120
    {
      b_LumaInRangeThis = ICEXP_b_LumaIsInRange(ps_ICObj, ps_State->ui32_Luma);
      b_LumaInRangePrev = ICEXP_b_LumaIsInRange(ps_ICObj, ps_LastFrame->ui32_Mean);
      if (   ( (b_LumaInRangeThis == b_FALSE)
            && (b_LumaInRangePrev == b_TRUE )
             )
          || (       (ps_State->ui32_Luma < ps_Settings->ui16_LumaMinNoControl)
              && (ps_LastFrame->ui32_Mean > ps_Settings->ui16_LumaMaxNoControl)
             )
         )
      {
        // Use data from previous frame
        ps_State->ui32_Luma           = ps_LastFrame->ui32_Mean;
        ps_State->ui16_ExposureTimeUs = ps_LastFrame->ui16_ExposureTimeUs;
      }
    }
    /*#]*/
}

/*## operation ICEXP_v_LumaFilterMedian(ICEXP_S_Obj *) */
static void ICEXP_v_LumaFilterMedian(ICEXP_S_Obj * ps_ICObj) {
    /*#[ operation ICEXP_v_LumaFilterMedian(ICEXP_S_Obj *) */
    // Function is static - nullpointer checks are already done:
    // PRQA S 0506 2
    ICEXP_S_State        * const ps_State       = &ps_ICObj->s_State;
    ICEXP_S_Settings     * const ps_Settings    = ps_ICObj->ps_Parameters;
    ICEXP_S_HistoryEntry        *ps_Temp        = 0;
    ICEXP_S_HistoryEntry        *ps_SortedHistory[ICEXP_cui_MAX_LUMA_FILTER_VALUES];
    const uint8                  ui8_MedianPosition = (uint8)(ps_Settings->ui16_LumaFilterDepth / 2);
    uint32                       ui32_Index     = 0;
    uint32                       ui32_LoopNum   = 0;
    
    // Update filter history (adds new element into front of array) and copy pointers to local sort array
    ICEXP_v_UpdateFilterHistory(ps_ICObj);
    for (ui32_Index = 0; ui32_Index < ICEXP_cui_MAX_LUMA_FILTER_VALUES; ui32_Index++)
    {
      ps_SortedHistory[ui32_Index] = &ps_State->as_FilterHistory[ui32_Index];
    }
    
    // Only do processing if complete history is available
    if ((ps_State->ui16_FilterHistoryCount == ps_Settings->ui16_LumaFilterDepth)
     && (   (ps_State->ui32_Luma > ps_Settings->ui16_LumaMaxNoControl)
         || (ps_State->ui32_Luma < ps_Settings->ui16_LumaMinNoControl)
        )
       )
    {
    
      // Sort data
      for (ui32_LoopNum = 0; ui32_LoopNum < ps_State->ui16_FilterHistoryCount; ui32_LoopNum++)
      {
        for (ui32_Index = 0; ui32_Index < (ps_State->ui16_FilterHistoryCount - 1); ui32_Index++)
        {
          if (ps_SortedHistory[ui32_Index]->f32_BrightnessCdqm > ps_SortedHistory[ui32_Index+1]->f32_BrightnessCdqm)
          {
            // Swap pointers
            ps_Temp                        = ps_SortedHistory[ui32_Index];
            ps_SortedHistory[ui32_Index]   = ps_SortedHistory[ui32_Index+1];
            ps_SortedHistory[ui32_Index+1] = ps_Temp;
          }
        }
      }
    
      // Choose median and exposure-time according to selected median
      ps_State->ui32_Luma           = ps_SortedHistory[ui8_MedianPosition]->ui32_Mean;
      ps_State->ui16_ExposureTimeUs = ps_SortedHistory[ui8_MedianPosition]->ui16_ExposureTimeUs;
    }
    /*#]*/
}

/*## operation ICEXP_v_LumaFilterRoth(ICEXP_S_Obj *) */
static void ICEXP_v_LumaFilterRoth(ICEXP_S_Obj * ps_ICObj) {
    /*#[ operation ICEXP_v_LumaFilterRoth(ICEXP_S_Obj *) */
    // Function is static - nullpointer checks are already done:
    // PRQA S 0506 2
    ICEXP_S_State        * const ps_State     = &ps_ICObj->s_State;
    ICEXP_S_HistoryEntry *       ps_LastFrame =  0;
    boolean                      b_LumaInRangeThis;
    boolean                      b_LumaInRangePrev;
    
    // Update filter-array (shift new luma into the array)
    ICEXP_v_UpdateFilterHistory(ps_ICObj);
    
    // Pick last frame from history
    ps_LastFrame = &ps_State->as_FilterHistory[1];
    
    // Select old frame only if current luma is out of range and history-frame has good luma
    b_LumaInRangeThis = ICEXP_b_LumaIsInRange(ps_ICObj, ps_State->ui32_Luma);
    b_LumaInRangePrev = ICEXP_b_LumaIsInRange(ps_ICObj, ps_LastFrame->ui32_Mean);
    if ((b_FALSE == b_LumaInRangeThis) && (b_TRUE == b_LumaInRangePrev))
    {
      ps_State->ui32_Luma           = ps_LastFrame->ui32_Mean;
      ps_State->ui16_ExposureTimeUs = ps_LastFrame->ui16_ExposureTimeUs;
    }
    /*#]*/
}

/*## operation ICEXP_v_SlopeRatioControl(ICEXP_S_Obj *) */
static void ICEXP_v_SlopeRatioControl(ICEXP_S_Obj * ps_ICObj) {
    /*#[ operation ICEXP_v_SlopeRatioControl(ICEXP_S_Obj *) */
    // Function is static - nullpointer checks are already done:
    // PRQA S 0506 2
    ICEXP_S_State    * const ps_State    = &ps_ICObj->s_State;
    ICEXP_S_Settings * const ps_Settings =  ps_ICObj->ps_Parameters;
    const uint16 cui16_Ratio_4X  = 4;
    const uint16 cui16_Ratio_16X = 16;
    const float32 cf32_4xBugRatio = 0.25f;
    
    // Determine mode for switching the slope R1
    if (ICEXP_e_SLOPE_SWITCH_BY_T1THRES == ps_Settings->e_SlopeSwitchingMode)
    {
    
      // Mode is switch by exposure time T1 thresholds with hysteresis.
      // Switch 4x -> 16x on upper bound of threshold
      if ((ps_State->ui16_SlopeRatioR1   == cui16_Ratio_4X)
       && (ps_State->ui16_ExposureTimeUs >= ps_Settings->ui16_SlopeRatioSwitchThresT1UsHigh))
      {
        ps_State->ui16_SlopeRatioR1 = cui16_Ratio_16X;
      }
    
      // Switch 16x -> 4x on lower bound of threshold
      if ((ps_State->ui16_SlopeRatioR1   == cui16_Ratio_16X)
       && (ps_State->ui16_ExposureTimeUs <= ps_Settings->ui16_SlopeRatioSwitchThresT1UsLow))
      {
        ps_State->ui16_SlopeRatioR1 = cui16_Ratio_4X;
      }
    }
    else if (ICEXP_e_SLOPE_SWITCH_BY_INTRADAYSTATE == ps_Settings->e_SlopeSwitchingMode)
    {
    
      // Mode is switch by intraday-state
      // Switch 4x -> 16x if night is active
      if ((ps_State->ui16_SlopeRatioR1 == cui16_Ratio_4X) && (ps_State->e_IntradayState == IC_e_INTRADAY_STATE_NIGHT))
      {
        ps_State->ui16_SlopeRatioR1 = cui16_Ratio_16X;
      }
    
      // Switch 16x -> 4x if day is active
      if ((ps_State->ui16_SlopeRatioR1 == cui16_Ratio_16X) && (ps_State->e_IntradayState == IC_e_INTRADAY_STATE_DAY))
      {
        ps_State->ui16_SlopeRatioR1 = cui16_Ratio_4X;
      }
    }
    else if (ICEXP_e_SLOPE_SWITCH_FIXED == ps_Settings->e_SlopeSwitchingMode)
    {
      // Don't switch thresholds in this mode, just copy R1 and R2 from IC-Settings
      ps_State->ui16_SlopeRatioR1 = ps_Settings->ui16_IntegrationTimeRatioR1;
      ps_State->ui16_SlopeRatioR2 = ps_Settings->ui16_IntegrationTimeRatioR2;
    }
    else
    {
      //(void)ICERR_HANDLE(ICEXP_e_ERR_PARAM_SLOPESWITCHMODE, 0);
    }
    
    // To compensate an bug in the imager when R1=4, we have to apply a factor of 0.25 to
    // the digital gain register:
    if (ps_State->ui16_SlopeRatioR1 == cui16_Ratio_4X)
    {
      ps_State->f32_DigitalGain *= cf32_4xBugRatio;
    }
    /*#]*/
}

/*## operation ICEXP_v_UpdateFilterHistory(ICEXP_S_Obj *) */
static void ICEXP_v_UpdateFilterHistory(ICEXP_S_Obj * ps_ICObj) {
    /*#[ operation ICEXP_v_UpdateFilterHistory(ICEXP_S_Obj *) */
    // Function is static - nullpointer checks are already done:
    // PRQA S 0506 2
    ICEXP_S_Settings     * const ps_Settings        =  ps_ICObj->ps_Parameters;
    ICEXP_S_State        * const ps_State           = &ps_ICObj->s_State;
    ICEXP_S_HistoryEntry * const ps_History         =  ps_State->as_FilterHistory;
    ICEXP_S_HistoryEntry *       ps_NewHistoryEntry =  NULL;
    uint32                       ui32_Index         =  0;
    
    // Shift filter array right one entry and add new value
    for (ui32_Index = (uint32)(ps_Settings->ui16_LumaFilterDepth - 1); ui32_Index > 0; ui32_Index--)
    {
      // Pointer points to an array, so suppress QAC MSG:
      // PRQA S 0491 1
      ps_History[ui32_Index] = ps_History[ui32_Index-1];
    }
    ps_NewHistoryEntry                      = &ps_History[0]; // PRQA S 0491
    ps_NewHistoryEntry->f32_BrightnessCdqm  = ps_State->f32_BrightnessCdqm;
    ps_NewHistoryEntry->ui16_ExposureTimeUs = ps_State->ui16_ExposureTimeUs;
    ps_NewHistoryEntry->ui32_Mean           = ps_State->ui32_Luma;
    
    // Increment element-counter if array is not already filled
    if (ps_State->ui16_FilterHistoryCount < ps_ICObj->ps_Parameters->ui16_LumaFilterDepth)
    {
      ps_State->ui16_FilterHistoryCount++;
    }
    /*#]*/
}


/*#[ ignore */

#ifdef __cplusplus
}
#endif

/*#]*/


/*********************************************************************
	File Path: ..\..\..\04_Engineering\01_Source_Code\Algo\ic\ic_exposure.c
*********************************************************************/
