//* **********************************************************************
//  COMPANY:         $CompanyInfo: CONFIDENTIAL AND PROPRIETARY PROPERTY OF CONTINENTAL AG , A.D.C. GmbH  -  ALL RIGHTS RESERVED $
//  
//  PROJECT:         MFC30x_MCU
//  CPU:             MPC5675K
//  
//  PACKAGE:         $Source: ic_responsecurve.c $ $Revision: 1.1 $
//  MKS Date:        $Date: 2021/12/13 17:26:03CET $
//  
//  RHAPSODY:        7.5.3
//  COMPONENT:       IC
//  CONFIGURATION:   DefaultConfig
//  MODEL ELEMENT:   ic_responsecurve
//  MODULNAME:       ..\..\..\04_Engineering\01_Source_Code\Algo\ic\ic_responsecurve.c
//  LOGIN:           uidt3974  
//  
//  ==========================================================================================
//  The following QAC messages are suppressed for this module:
//  
//  This is a pure algorithmic module, which is implemented according a specification document,
//  so there are many 'magic' numbers of course. Giving all of them a name would result in
//  unreadable code:
//      PRQA S 3120,3121 EOF
//  
//  The formulas are working since a long time and have been verified by doing lab tests with
//  a light source, so we will not modify them again by adding extra parentheses here:
//      PRQA S 3401,3393,3395 EOF
//  
//  Possible dereference of NULL pointer
//      PRQA S 0506 EOF
//  
//  AUTHOR:          $Author: Wang, David (Wangd3) $
//! CREATION DATE:   Fri, 20, Jul 2012  9:47 W. Europe Daylight Time PM 
//**************************************************************************** */

/*## auto_generated */
#include "ic_responsecurve.h"
/*## dependency ic_registers_bitmasks */
#include "ic_registers_bitmasks.h"
/*## package Ic_Pkg */

/*## class TopLevel::ic_responsecurve */


/*#[ ignore */
#ifdef __cplusplus
extern "C"
{
#endif

/*#]*/


//*****************************************************************************
//  Functionname:  IRCC_e_CalcResponseCurveConstants
//  
//  
//  
//  Parameter:     IRCC_S_Constants * const ps_ProdConstants   <In>
//  
//    
//  
//  return         IRCC_E_ERROR
//**************************************************************************** */
/*## operation IRCC_e_CalcResponseCurveConstants(IRCC_S_Constants * const) */
static IRCC_E_ERROR IRCC_e_CalcResponseCurveConstants(IRCC_S_Constants * const ps_ProdConstants);

//*****************************************************************************
//  Functionname:  IRCC_v_CurveIndexToValues
//  
//  
//  
//  Parameter:     const uint8 ui8_Index   <In>
//  
//  
//  Parameter:     float32 * const pf32_R1   <In>
//  
//  
//  Parameter:     float32 * const pf32_R2   <In>
//  
//  
//  Parameter:     float32 * const pf32_YSat   <In>
//  
//  
//  Parameter:     float32 * const pf32_P2   <In>
//  
//    
//  
//  return         void
//**************************************************************************** */
/*## operation IRCC_v_CurveIndexToValues(const uint8,float32 * const,float32 * const,float32 * const,float32 * const) */
static void IRCC_v_CurveIndexToValues(const uint8 ui8_Index, float32 * const pf32_R1, float32 * const pf32_R2, float32 * const pf32_YSat, float32 * const pf32_P2);

//*****************************************************************************
//  Functionname:  IRCC_v_OpModeCtrlRegToCurveFormIndex
//  
//  
//  
//  Parameter:     const uint16 ui16_OpModeCtrl   <In>
//  
//  
//  Parameter:     uint8 * const pui_Index   <In>
//  
//    
//  
//  return         void
//**************************************************************************** */
/*## operation IRCC_v_OpModeCtrlRegToCurveFormIndex(const uint16,uint8 * const) */
static void IRCC_v_OpModeCtrlRegToCurveFormIndex(const uint16 ui16_OpModeCtrl, uint8 * const pui_Index);

/*## operation IRCC_e_SetImagerPPARs(IRCC_S_Obj * const,const IRCC_S_PPARs * const) */
IRCC_E_ERROR IRCC_e_SetImagerPPARs(IRCC_S_Obj * const ps_Obj, const IRCC_S_PPARs * const ps_PPARs) {
    /*#[ operation IRCC_e_SetImagerPPARs(IRCC_S_Obj * const,const IRCC_S_PPARs * const) */
    float32 f32_gain = 1.0f;
    IRCC_S_Constants * const ps_ProdConstants = &ps_Obj->s_Constants;
    IRCC_E_ERROR e_Ret = IRCC_e_ERROR_OK;
    
    // Copy over production parameters
    ps_ProdConstants->f32_X_Meas_1500  = ps_PPARs->f32_X_Meas_1500;
    ps_ProdConstants->f32_X_Meas_2500  = ps_PPARs->f32_X_Meas_2500;
    ps_ProdConstants->f32_X_Meas_3500  = ps_PPARs->f32_X_Meas_3500;
    ps_ProdConstants->f32_Y_Meas_1500  = ps_PPARs->f32_Y_Meas_1500;
    ps_ProdConstants->f32_Y_Meas_2500  = ps_PPARs->f32_Y_Meas_2500;
    ps_ProdConstants->f32_Y_Meas_3500  = ps_PPARs->f32_Y_Meas_3500;
    ps_ProdConstants->f32_X_BL_0       = ps_PPARs->f32_X_BL_0;
    ps_ProdConstants->f32_Y_BL_0       = ps_PPARs->f32_Y_BL_0;
    IRCC_v_CurveIndexToValues(
        ps_PPARs->ui8_ResponseCurveFormIndex,
        &ps_ProdConstants->f32_R1_prod,
        &ps_ProdConstants->f32_R2_prod,
        &ps_ProdConstants->f32_Y_Saturation_prod,
        &ps_ProdConstants->f32_P2_prod
    );
    ps_ProdConstants->f32_ACT_R1_prod    = ps_PPARs->f32_ACT_R1;
    ps_ProdConstants->f32_ACT_R2_prod    = ps_PPARs->f32_ACT_R2;
    ps_ProdConstants->f32_DCG_Factor     = ps_PPARs->f32_DCG_Factor;
    ps_ProdConstants->f32_T1_prod        = ps_PPARs->f32_T1;
    ps_ProdConstants->f32_RatioRedGreen  = ps_PPARs->f32_RatioRedGreen;
    ps_ProdConstants->f32_RatioBlueGreen = ps_PPARs->f32_RatioBlueGreen;
    
    // Calculate gain
    f32_gain  = (ps_PPARs->ui16_DCG_State == 1) ? ps_PPARs->f32_DCG_Factor : 1.0f;
    f32_gain *= ps_PPARs->f32_Analog_Gain;
    f32_gain *= ps_PPARs->f32_Digital_Gain;
    ps_ProdConstants->f32_Gain_prod = f32_gain;
    
    // Calculate response curve constants
    e_Ret = IRCC_e_CalcResponseCurveConstants(&ps_Obj->s_Constants);
    return e_Ret;
    /*#]*/
}

/*## operation IRCC_v_SetInput(IRCC_S_Obj * const,IRCC_S_Input * const) */
void IRCC_v_SetInput(IRCC_S_Obj * const ps_Obj, IRCC_S_Input * const ps_Input) {
    /*#[ operation IRCC_v_SetInput(IRCC_S_Obj * const,IRCC_S_Input * const) */
    ps_Obj->ps_Input = ps_Input;
    /*#]*/
}

/*## operation IRCC_e_CalcResponseCurveConstants(IRCC_S_Constants * const) */
static IRCC_E_ERROR IRCC_e_CalcResponseCurveConstants(IRCC_S_Constants * const ps_ProdConstants) {
    /*#[ operation IRCC_e_CalcResponseCurveConstants(IRCC_S_Constants * const) */
    IRCC_S_Constants * const p = ps_ProdConstants;
    
    p->f32_P1                = 2048.0f; // = 2^11
    p->f32_X_BL_1            = 0.0f;
    p->f32_X_BL_2            = 0.0f;
    
    p->f32_Y_Kneepoint_1     = p->f32_P1;
    p->f32_Y_Kneepoint_2     = (p->f32_P2_prod - p->f32_P1) / (p->f32_R1_prod * 4.0f) + p->f32_P1;
    p->f32_Y_BL_1_prod       = p->f32_P1 - (p->f32_P1 - p->f32_Y_BL_0) / (4.0f * p->f32_R1_prod);
    p->f32_Y_BL_2_prod       = p->f32_Y_Kneepoint_2 - ((p->f32_Y_Kneepoint_2 - p->f32_Y_BL_1_prod)/p->f32_R2_prod);
    
    // Calculate slopes
    p->f32_m_main_prod_1     = (p->f32_Y_Meas_1500 - p->f32_Y_BL_0) / (p->f32_X_Meas_1500 - p->f32_X_BL_0);
    p->f32_m_slope_2_1       = (p->f32_Y_Meas_2500 - p->f32_Y_BL_1_prod) / (p->f32_X_Meas_2500 - p->f32_X_BL_1);
    p->f32_m_main_prod_2     =  p->f32_m_slope_2_1 * 4.0f * p->f32_R1_prod;
    p->f32_m_slope_3_1       = (p->f32_Y_Meas_3500 - p->f32_Y_BL_2_prod) / (p->f32_X_Meas_3500 - p->f32_X_BL_2);
    p->f32_m_main_prod_3     =  p->f32_m_slope_3_1 * 4.0f * p->f32_R1_prod * p->f32_R2_prod;
    p->f32_m_main_prod       = (p->f32_m_main_prod_1 + p->f32_m_main_prod_2 + p->f32_m_main_prod_3) / 3.0f;
    p->f32_m_slope_2_2       = (p->f32_m_main_prod / (4.0f * p->f32_R1_prod));
    p->f32_m_slope_2_3       =  p->f32_m_slope_3_1 * p->f32_R2_prod;
    p->f32_m_slope_2_prod    = (p->f32_m_slope_2_1 + p->f32_m_slope_2_2 + p->f32_m_slope_2_3) / 3.0f;
    p->f32_m_slope_3_2       =  p->f32_m_slope_2_prod / p->f32_R2_prod;
    p->f32_m_slope_3_3       =  p->f32_m_main_prod / (4.0f * p->f32_R1_prod * p->f32_R2_prod);
    p->f32_m_slope_3_prod    = (p->f32_m_slope_3_1 + p->f32_m_slope_3_2 + p->f32_m_slope_3_3) / 3.0f;
    
    // Calculcate kneepoints
    p->f32_X_Kneepoint_1_1    =  p->f32_X_Meas_1500 + (p->f32_Y_Kneepoint_1 - p->f32_Y_Meas_1500) / p->f32_m_main_prod;
    p->f32_X_Kneepoint_1_2    = (p->f32_Y_Kneepoint_1 - p->f32_Y_BL_1_prod) / p->f32_m_slope_2_prod;
    p->f32_X_Kneepoint_1_prod = (p->f32_X_Kneepoint_1_1 + p->f32_X_Kneepoint_1_2) / 2.0f;
    p->f32_X_Kneepoint_2_1    =  p->f32_X_Meas_2500 + (p->f32_Y_Kneepoint_2 - p->f32_Y_Meas_2500) / p->f32_m_slope_2_prod;
    p->f32_X_Kneepoint_2_2    = (p->f32_Y_Kneepoint_2 - p->f32_Y_BL_2_prod) / p->f32_m_slope_3_prod;
    p->f32_X_Kneepoint_2_prod = (p->f32_X_Kneepoint_2_1 + p->f32_X_Kneepoint_2_2) / 2.0f;
    
    // Calculate saturation
    p->f32_X_Saturation_1    =  p->f32_X_Meas_3500 + (p->f32_Y_Saturation_prod - p->f32_Y_Meas_3500) / p->f32_m_slope_3_prod;
    p->f32_X_Saturation_2    = (p->f32_Y_Saturation_prod - p->f32_Y_BL_2_prod) / p->f32_m_slope_3_prod;
    p->f32_X_Saturation_prod = (p->f32_X_Saturation_1 + p->f32_X_Saturation_2) / 2.0f;
    
    p->f32_m_T1_prod         = (p->f32_m_main_prod * ((p->f32_ACT_R1_prod*p->f32_ACT_R2_prod) / (p->f32_ACT_R1_prod*p->f32_ACT_R2_prod + p->f32_ACT_R2_prod + 1.0f)));
    
    p->b_DerivedConstantsCalculated = b_TRUE;
    return IRCC_e_ERROR_OK;
    /*#]*/
}

/*## operation IRCC_e_CalcImagerResponseCurve(IRCC_S_Obj * const) */
IRCC_E_ERROR IRCC_e_CalcImagerResponseCurve(IRCC_S_Obj * const ps_Obj) {
    /*#[ operation IRCC_e_CalcImagerResponseCurve(IRCC_S_Obj * const) */
    IRCC_E_ERROR                   e_Ret   = IRCC_e_ERROR_OK;
    IRCC_S_Results         * const r       = &ps_Obj->s_ResponseCurveIntermResults;
    IRCC_S_Constants const * const pc      = &ps_Obj->s_Constants;
    IC_S_RegBuff     const * const ps_Regs = ps_Obj->ps_Input->ps_ImagerRegs;
    
    // Fetch registers from inputs
    const uint16 ui16_reg_ae_ctrl                 = ps_Regs->aRegs[IMGREG_e_REG_AE_CTRL_REG];
    const uint16 ui16_reg_digital_test            = ps_Regs->aRegs[IMGREG_e_REG_DIGITAL_TEST];
    const uint16 ui16_reg_digital_test_anal_gain  = (ui16_reg_digital_test & IMGREG_cui16_BITMASK_DIGITAL_TEST_COL_GAIN)
                                                                          >> IMGREG_cui16_BITSHIFT_DIGITAL_TEST_COL_GAIN;
    const uint16 ui16_reg_exposure_t1             = ps_Regs->aRegs[IMGREG_e_REG_EXPOSURE_T1];
    const uint16 ui16_reg_exposure_t2             = ps_Regs->aRegs[IMGREG_e_REG_EXPOSURE_T2];
    const uint16 ui16_reg_exposure_t3             = ps_Regs->aRegs[IMGREG_e_REG_EXPOSURE_T3];
    const uint16 ui16_reg_operation_mode_control  = ps_Regs->aRegs[IMGREG_e_REG_OPERATION_MODE_CTRL];
    const float32 f32_DigitalGain                 = (float32)ps_Regs->aRegs[IMGREG_e_REG_GLOBAL_GAIN] / 32.0f;
    
    // Calculate integration time ratios
    r->f32_T1_New = (float32)(ui16_reg_exposure_t1);
    r->f32_Act_R1 = (float32)(ui16_reg_exposure_t1) / (float32)(ui16_reg_exposure_t2);
    r->f32_Act_R2 = (float32)(ui16_reg_exposure_t2) / ((float32)(ui16_reg_exposure_t3) / 1650.0f);
    
    // Get response curve index from operation mode control register and extract specific curve-form-values
    IRCC_v_OpModeCtrlRegToCurveFormIndex(ui16_reg_operation_mode_control, &r->ui8_ResponseCurveFormIndex);
    IRCC_v_CurveIndexToValues(r->ui8_ResponseCurveFormIndex, &r->f32_R1, &r->f32_R2, &r->f32_Y_Saturation, &r->f32_P2);
    
    // Calculate current gain: DCG
    if ((ui16_reg_ae_ctrl & IMGREG_cui16_BITMASK_AE_CTRL_REG_DCG_MANUAL_SET) != 0)
    {
      r->f32_Gain = pc->f32_DCG_Factor;
    }
    else
    {
      r->f32_Gain = 1.0f;
    }
    
    // Calculate current gain: Take analog gain into account
    switch (ui16_reg_digital_test_anal_gain)
    {
    case 0u:
      //r->f32_Gain *= 1.0f;
      break;
    case 1u:
      r->f32_Gain *= 2.0f;
      break;
    case 2u:
      r->f32_Gain *= 4.0f;
      break;
    default:
      e_Ret = IRCC_e_ERROR_INVALID_ANAL_GAIN;
      break;
    }
    
    // Calculate response curve if there as no error
    if (IRCC_e_ERROR_OK == e_Ret)
    {
      // Take digital gain into account, but compensate imager bug in 4x/16x mode
      r->f32_Gain *= f32_DigitalGain;
      if (r->f32_R1 == 4.0f) /* power-of-two value from LUT, so compare is ok here */ // PRQA S 3341
      {
        r->f32_Gain *= 4.0f;
      }
    
      // Get current blacklevel from inputs
      r->f32_Y_BL_0 = ps_Obj->ps_Input->ui16_Blacklevel;
    
      // Base-Slope
      r->f32_m_T1_new      =  pc->f32_m_T1_prod * (r->f32_T1_New / pc->f32_T1_prod);
      r->f32_m_main_new    =  r->f32_m_T1_new * ((r->f32_Act_R1 * r->f32_Act_R2 + r->f32_Act_R2 + 1.0f) / (r->f32_Act_R1 * r->f32_Act_R2)) * (r->f32_Gain / pc->f32_Gain_prod);
    
      // Kneepoint 1 + Slope
      r->f32_Y_Kneepoint_1 =  pc->f32_P1;
      r->f32_X_Kneepoint_1 = (r->f32_Y_Kneepoint_1 - r->f32_Y_BL_0) / r->f32_m_main_new;
      r->f32_m_slope_2     =  r->f32_m_main_new / (4.0f * r->f32_R1);
      r->f32_Y_BL_1        =  r->f32_Y_Kneepoint_1 - ((r->f32_Y_Kneepoint_1 - r->f32_Y_BL_0) / (4.0f * r->f32_R1));
    
      // Kneepoint 2 + Slope
      r->f32_Y_Kneepoint_2 = (r->f32_P2 - pc->f32_P1) / (r->f32_R1 * 4.0f) + pc->f32_P1;
      r->f32_X_Kneepoint_2 = (r->f32_Y_Kneepoint_2 - r->f32_Y_BL_1) / r->f32_m_slope_2;
      r->f32_m_slope_3     =  r->f32_m_main_new / (4.0f * r->f32_R1 * r->f32_R2);
      r->f32_Y_BL_2        =  r->f32_Y_Kneepoint_2 - ((r->f32_Y_Kneepoint_2 - r->f32_Y_BL_1) / r->f32_R2);
    
      r->f32_X_Saturation    = (r->f32_Y_Saturation - r->f32_Y_BL_2) / r->f32_m_slope_3;
      r->f32_Y_Grayvalue_512 = 512.0f;
      r->f32_X_Grayvalue_512 = pc->f32_X_BL_0 + ((r->f32_Y_Grayvalue_512 - r->f32_Y_BL_0) / (r->f32_Y_Kneepoint_1 - r->f32_Y_BL_0) * (r->f32_X_Kneepoint_1 - pc->f32_X_BL_0));
    }
    return e_Ret;
    /*#]*/
}

/*## operation IRCC_e_GetResponseCurve(const IRCC_S_Obj * const,IRCC_S_ResponseCurve * const) */
IRCC_E_ERROR IRCC_e_GetResponseCurve(const IRCC_S_Obj * const ps_Instance, IRCC_S_ResponseCurve * const ps_ResposeCurve) {
    /*#[ operation IRCC_e_GetResponseCurve(const IRCC_S_Obj * const,IRCC_S_ResponseCurve * const) */
    IRCC_S_Results const * const ps_Results = &ps_Instance->s_ResponseCurveIntermResults;
    uint32  ui32_Index   = 0;
    float32 f32_FactorGR = 0.0f;
    float32 f32_FactorGB = 0.0f;
    
    // Copy blacklevels
    ps_ResposeCurve->ui16_BlackLevel_0       = (uint16)(ps_Results->f32_Y_BL_0 + 0.5f); // PRQA S 4119
    ps_ResposeCurve->ui16_BlackLevel_1       = (uint16)(ps_Results->f32_Y_BL_1 + 0.5f); // PRQA S 4119
    ps_ResposeCurve->ui16_BlackLevel_2       = (uint16)(ps_Results->f32_Y_BL_2 + 0.5f); // PRQA S 4119
    
    // Copy support points
    ps_ResposeCurve->f32_BrightnessG[0]       = 0.0f;
    ps_ResposeCurve->f32_BrightnessG[1]       = ps_Results->f32_X_Kneepoint_1;
    ps_ResposeCurve->f32_BrightnessG[2]       = ps_Results->f32_X_Kneepoint_2;
    ps_ResposeCurve->f32_BrightnessG[3]       = ps_Results->f32_X_Saturation;
    ps_ResposeCurve->f32_BrightnessG[4]       = 0.0f;
    ps_ResposeCurve->ui16_GreyValues[0]       = (uint16)(ps_Results->f32_Y_BL_0        + 0.5f); // PRQA S 4119
    ps_ResposeCurve->ui16_GreyValues[1]       = (uint16)(ps_Results->f32_Y_Kneepoint_1 + 0.5f); // PRQA S 4119
    ps_ResposeCurve->ui16_GreyValues[2]       = (uint16)(ps_Results->f32_Y_Kneepoint_2 + 0.5f); // PRQA S 4119
    ps_ResposeCurve->ui16_GreyValues[3]       = (uint16)(ps_Results->f32_Y_Saturation  + 0.5f); // PRQA S 4119
    ps_ResposeCurve->ui16_GreyValues[4]       = 0;
    ps_ResposeCurve->f32_BrightnessGAtGrey512 = ps_Results->f32_X_Grayvalue_512;
    ps_ResposeCurve->ui16_NumSupportPoints    = 4;
    
    // Calculate other support-points for red and blue by using the color-ratios
    f32_FactorGR = 1.0f / ps_Instance->s_Constants.f32_RatioRedGreen;
    f32_FactorGB = 1.0f / ps_Instance->s_Constants.f32_RatioBlueGreen;
    for (ui32_Index = 0; ui32_Index < IC_ARRLEN(ps_ResposeCurve->f32_BrightnessG); ui32_Index++)
    {
      ps_ResposeCurve->f32_BrightnessR[ui32_Index] = ps_ResposeCurve->f32_BrightnessG[ui32_Index] * f32_FactorGR;
      ps_ResposeCurve->f32_BrightnessB[ui32_Index] = ps_ResposeCurve->f32_BrightnessG[ui32_Index] * f32_FactorGB;
    }
    
    // Shape
    ps_ResposeCurve->ui16_RequestedSlopeR1   = (uint16)(ps_Results->f32_R1);
    ps_ResposeCurve->ui16_RequestedSlopeR2   = (uint16)(ps_Results->f32_R2);
    ps_ResposeCurve->f32_ActualSlopeR1       = ps_Results->f32_Act_R1;
    ps_ResposeCurve->f32_ActualSlopeR2       = ps_Results->f32_Act_R2;
    ps_ResposeCurve->f32_TotalGain           = ps_Results->f32_Gain;
    
    return IRCC_e_ERROR_OK;
    /*#]*/
}

/*## operation IRCC_ui16_Calc12BitCompandedMean(const IRCC_S_Obj * const,const uint32) */
uint16 IRCC_ui16_Calc12BitCompandedMean(const IRCC_S_Obj * const ps_Instance, const uint32 ui32_Mean20Bit) {
    /*#[ operation IRCC_ui16_Calc12BitCompandedMean(const IRCC_S_Obj * const,const uint32) */
    IRCC_S_Results const * const ps_Results = &ps_Instance->s_ResponseCurveIntermResults;
    const uint32 ui32_P1     = 2048; // 2^11 fixed in 12-Bit companding mode
    const uint32 ui32_P2     = (uint32)(ps_Results->f32_P2);
    const uint32 ui32_R1     = (uint32)(ps_Results->f32_R1);
          uint32 ui32_R2     = (uint32)(ps_Results->f32_R2);
          uint32 ui32_pk     = 0;
          uint32 ui32_Mean12 = 0;
    
    // Limit R2 to 16 according to formulas from Aptina
    if (ui32_R2 > 16)
    {
      ui32_R2 = 16;
    }
    
    // Calculate "pk"
    ui32_pk = (ui32_P2 - ui32_P1) / (4 * ui32_R1) + ui32_P1;
    
    // Mean below of first Kneepoint ?
    if (ui32_Mean20Bit <= ui32_P1)
    {
      ui32_Mean12 = ui32_Mean20Bit;
    }
    else if (ui32_Mean20Bit <= ui32_P2)
    {
      ui32_Mean12 = ui32_P1 + ((ui32_Mean20Bit - ui32_P1) / (4 * ui32_R1));
    }
    else
    {
      ui32_Mean12 = ui32_pk + (ui32_Mean20Bit - ui32_P2) / (4 * ui32_R1 * ui32_R2);
    }
    return (uint16)ui32_Mean12;
    /*#]*/
}

/*## operation IRCC_ui32_Calc20BitLinearMean(const IRCC_S_Obj * const,const uint16) */
uint32 IRCC_ui32_Calc20BitLinearMean(const IRCC_S_Obj * const ps_Instance, const uint16 ui16_Mean12Bit) {
    /*#[ operation IRCC_ui32_Calc20BitLinearMean(const IRCC_S_Obj * const,const uint16) */
    IRCC_S_Results const * const ps_Results = &ps_Instance->s_ResponseCurveIntermResults;
    const uint32 ui32_P1     = 2048; // 2^11 fixed in 12-Bit companding mode
    const uint32 ui32_P2     = (uint32)(ps_Results->f32_P2);
    const uint32 ui32_R1     = (uint32)(ps_Results->f32_R1 + 0.5f); // PRQA S 4119
          uint32 ui32_R2     = (uint32)(ps_Results->f32_R2 + 0.5f); // PRQA S 4119
          uint32 ui32_pk     = 0;
          uint32 ui32_Mean20 = 0;
    const uint32 ui32_Mean12 = (uint32)ui16_Mean12Bit;
    
    // Limit R2 to 16 according to formulas from Aptina
    if (ui32_R2 > 16)
    {
      ui32_R2 = 16;
    }
    
    // Calculate "pk"
    ui32_pk = (ui32_P2 - ui32_P1) / (4 * ui32_R1) + ui32_P1;
    
    // Below first Kneepoint ?
    if (ui32_Mean12 <= ui32_P1)
    {
      ui32_Mean20 = ui32_Mean12;
    }
    else if (ui32_Mean12 <= ui32_pk)
    {
      ui32_Mean20 = ui32_P1 + (ui32_Mean12 - ui32_P1) * 4 * ui32_R1;
    }
    else
    {
      ui32_Mean20 = ui32_P2 + (ui32_Mean12 - ui32_pk) * 4 * ui32_R1 * ui32_R2;
    }
    return ui32_Mean20;
    /*#]*/
}

/*## operation IRCC_f32_CalcBrightnessCd(const IRCC_S_Obj * const,const uint32) */
float32 IRCC_f32_CalcBrightnessCd(const IRCC_S_Obj * const ps_Instance, const uint32 ui32_Mean20Bit) {
    /*#[ operation IRCC_f32_CalcBrightnessCd(const IRCC_S_Obj * const,const uint32) */
    float32 f32_MeanBrightnessCdqm = 0.0f;
    IRCC_S_Results const * const ps_Results = &ps_Instance->s_ResponseCurveIntermResults;
    
    f32_MeanBrightnessCdqm = ((float32)ui32_Mean20Bit - ps_Results->f32_Y_BL_0) / ps_Results->f32_m_main_new;
    if (f32_MeanBrightnessCdqm < 0.0f)
    {
      f32_MeanBrightnessCdqm = 0.0f;
    }
    return f32_MeanBrightnessCdqm;
    /*#]*/
}

/*## operation IRCC_f32_CalcBrightnessCdCompanded(const IRCC_S_Obj * const,const uint16) */
float32 IRCC_f32_CalcBrightnessCdCompanded(const IRCC_S_Obj * const ps_Instance, const uint16 ui16_CompandedGrayValue12Bit) {
    /*#[ operation IRCC_f32_CalcBrightnessCdCompanded(const IRCC_S_Obj * const,const uint16) */
    float32 f32_BrightnessCdqm = 0.0f;
    IRCC_S_Results const * const ps_Results = &ps_Instance->s_ResponseCurveIntermResults;
    
    if (ui16_CompandedGrayValue12Bit < ps_Results->f32_Y_BL_0)
    {
      f32_BrightnessCdqm = 0.0f;
    }
    else if (ui16_CompandedGrayValue12Bit < ps_Results->f32_Y_Kneepoint_1)
    {
      f32_BrightnessCdqm = (ui16_CompandedGrayValue12Bit - ps_Results->f32_Y_BL_0) / ps_Results->f32_m_main_new;
    }
    else if (ui16_CompandedGrayValue12Bit < ps_Results->f32_Y_Kneepoint_2)
    {
      f32_BrightnessCdqm = (ui16_CompandedGrayValue12Bit - ps_Results->f32_Y_Kneepoint_1) / ps_Results->f32_m_slope_2 + ps_Results->f32_X_Kneepoint_1;
    }
    else if (ui16_CompandedGrayValue12Bit < ps_Results->f32_Y_Saturation)
    {
      f32_BrightnessCdqm = (ui16_CompandedGrayValue12Bit - ps_Results->f32_Y_Kneepoint_2) / ps_Results->f32_m_slope_3 + ps_Results->f32_X_Kneepoint_2;
    }
    else
    {
      f32_BrightnessCdqm = ps_Results->f32_X_Saturation;
    }
    return f32_BrightnessCdqm;
    /*#]*/
}

/*## operation IRCC_v_CurveIndexToValues(const uint8,float32 * const,float32 * const,float32 * const,float32 * const) */
static void IRCC_v_CurveIndexToValues(const uint8 ui8_Index, float32 * const pf32_R1, float32 * const pf32_R2, float32 * const pf32_YSat, float32 * const pf32_P2) {
    /*#[ operation IRCC_v_CurveIndexToValues(const uint8,float32 * const,float32 * const,float32 * const,float32 * const) */
    typedef struct
    {
      float32 f32_R1;
      float32 f32_R2;
      float32 f32_Y_Sat;
      float32 f32_P2;
    } IRCC_S_CurveDef;
    static const IRCC_S_CurveDef cas_curveValues[9] = // PRQA S 3132
    {
        //  R1     R2    Y_Sat      P2
        { 16.0f, 16.0f, 4000.0f, 65536.0f },
        {  8.0f, 16.0f, 3968.0f, 32768.0f },
        {  4.0f, 16.0f, 3904.0f, 16384.0f },
        { 16.0f,  8.0f, 4000.0f, 65536.0f },
        {  8.0f,  8.0f, 3968.0f, 32768.0f },
        {  4.0f,  8.0f, 3904.0f, 16384.0f },
        { 16.0f,  4.0f, 4000.0f, 65536.0f },
        {  8.0f,  4.0f, 3968.0f, 32768.0f },
        {  4.0f,  4.0f, 3904.0f, 16384.0f }
    };
    *pf32_R1   = cas_curveValues[ui8_Index].f32_R1;
    *pf32_R2   = cas_curveValues[ui8_Index].f32_R2;
    *pf32_YSat = cas_curveValues[ui8_Index].f32_Y_Sat;
    *pf32_P2   = cas_curveValues[ui8_Index].f32_P2;
    /*#]*/
}

/*## operation IRCC_v_OpModeCtrlRegToCurveFormIndex(const uint16,uint8 * const) */
static void IRCC_v_OpModeCtrlRegToCurveFormIndex(const uint16 ui16_OpModeCtrl, uint8 * const pui_Index) {
    /*#[ operation IRCC_v_OpModeCtrlRegToCurveFormIndex(const uint16,uint8 * const) */
    // This LUT maps the 4 R1/R2 ratio-bits of the operation-mode-control register to the
    // "response curve index" as defined in the specification. See also LUT in si_CurveIndexToValues()
    // and imager register reference "operation_mode_ctrl":
    static const uint8 aui8_Mapping[12] = // PRQA S 3132
    {
        8, 7, 6, 99, // Last value is dummy
        5, 4, 3, 99, // Last value is dummy
        2, 1, 0, 99  // Last value is dummy
    };
    
    // Extract [ratio_t2_t3, ratio_t1_t2] from register value
    const uint8 ui8_ArrayIndex = (uint8)((ui16_OpModeCtrl >> 2) & 0xF);
    *pui_Index = aui8_Mapping[ui8_ArrayIndex];
    /*#]*/
}


/*#[ ignore */

#ifdef __cplusplus
}
#endif

/*#]*/


/*********************************************************************
	File Path: ..\..\..\04_Engineering\01_Source_Code\Algo\ic\ic_responsecurve.c
*********************************************************************/
