//* **********************************************************************
//  COMPANY:         $CompanyInfo: CONFIDENTIAL AND PROPRIETARY PROPERTY OF CONTINENTAL AG , A.D.C. GmbH  -  ALL RIGHTS RESERVED $
//  
//  PROJECT:         MFC30x_MCU
//  CPU:             MPC5675K
//  
//  PACKAGE:         $Source: ic_responsecurve.h $ $Revision: 1.1 $
//  MKS Date:        $Date: 2021/12/13 17:26:03CET $
//  
//  RHAPSODY:        7.5.3
//  COMPONENT:       IC
//  CONFIGURATION:   DefaultConfig
//  MODEL ELEMENT:   ic_responsecurve
//  MODULNAME:       ..\..\..\04_Engineering\01_Source_Code\Algo\ic\ic_responsecurve.h
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
//! CREATION DATE:   Mon, 16, Jul 2012  6:11 W. Europe Daylight Time PM 
//**************************************************************************** */

#ifndef ic_responsecurve_H
#define ic_responsecurve_H

/*## dependency ic_registers */
#include "ic_registers.h"
/*## dependency ic_types */
#include "ic_types.h"
/*## package Ic_Pkg */

/*## class TopLevel::ic_responsecurve */
/*#[ ignore */
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
/*#]*/


/*#[ ignore */

#ifdef __cplusplus
extern "C"
{
#endif

/*#]*/


/*#[ type IRCC_E_ERROR */
typedef enum {
    IRCC_e_ERROR_OK,
    IRCC_e_ERROR_INVALID_ANAL_GAIN
}  IRCC_E_ERROR;
/*#]*/

/*## type IRCC_S_Constants */
typedef struct IRCC_S_Constants {
    boolean b_DerivedConstantsCalculated;		/*## attribute b_DerivedConstantsCalculated */
    float32 f32_ACT_R1_prod;		/*## attribute f32_ACT_R1_prod */
    float32 f32_ACT_R2_prod;		/*## attribute f32_ACT_R2_prod */
    float32 f32_DCG_Factor;		/*## attribute f32_DCG_Factor */
    float32 f32_Gain_prod;		/*## attribute f32_Gain_prod */
    float32 f32_P1;		/*## attribute f32_P1 */
    float32 f32_P2_prod;		/*## attribute f32_P2_prod */
    float32 f32_R1_prod;		/*## attribute f32_R1_prod */
    float32 f32_R2_prod;		/*## attribute f32_R2_prod */
    float32 f32_T1_prod;		/*## attribute f32_T1_prod */
    float32 f32_X_BL_0;		/*## attribute f32_X_BL_0 */
    float32 f32_X_BL_1;		/*## attribute f32_X_BL_1 */
    float32 f32_X_BL_2;		/*## attribute f32_X_BL_2 */
    float32 f32_X_Kneepoint_1_1;		/*## attribute f32_X_Kneepoint_1_1 */
    float32 f32_X_Kneepoint_1_2;		/*## attribute f32_X_Kneepoint_1_2 */
    float32 f32_X_Kneepoint_1_prod;		/*## attribute f32_X_Kneepoint_1_prod */
    float32 f32_X_Kneepoint_2_1;		/*## attribute f32_X_Kneepoint_2_1 */
    float32 f32_X_Kneepoint_2_2;		/*## attribute f32_X_Kneepoint_2_2 */
    float32 f32_X_Kneepoint_2_prod;		/*## attribute f32_X_Kneepoint_2_prod */
    float32 f32_X_Meas_1500;		/*## attribute f32_X_Meas_1500 */
    float32 f32_X_Meas_2500;		/*## attribute f32_X_Meas_2500 */
    float32 f32_X_Meas_3500;		/*## attribute f32_X_Meas_3500 */
    float32 f32_X_Saturation_1;		/*## attribute f32_X_Saturation_1 */
    float32 f32_X_Saturation_2;		/*## attribute f32_X_Saturation_2 */
    float32 f32_X_Saturation_prod;		/*## attribute f32_X_Saturation_prod */
    float32 f32_Y_BL_0;		/*## attribute f32_Y_BL_0 */
    float32 f32_Y_BL_1_prod;		/*## attribute f32_Y_BL_1_prod */
    float32 f32_Y_BL_2_prod;		/*## attribute f32_Y_BL_2_prod */
    float32 f32_Y_Kneepoint_1;		/*## attribute f32_Y_Kneepoint_1 */
    float32 f32_Y_Kneepoint_2;		/*## attribute f32_Y_Kneepoint_2 */
    float32 f32_Y_Meas_1500;		/*## attribute f32_Y_Meas_1500 */
    float32 f32_Y_Meas_2500;		/*## attribute f32_Y_Meas_2500 */
    float32 f32_Y_Meas_3500;		/*## attribute f32_Y_Meas_3500 */
    float32 f32_Y_Saturation_prod;		/*## attribute f32_Y_Saturation_prod */
    float32 f32_m_T1_prod;		/*## attribute f32_m_T1_prod */
    float32 f32_m_main_prod;		/*## attribute f32_m_main_prod */
    float32 f32_m_main_prod_1;		/*## attribute f32_m_main_prod_1 */
    float32 f32_m_main_prod_2;		/*## attribute f32_m_main_prod_2 */
    float32 f32_m_main_prod_3;		/*## attribute f32_m_main_prod_3 */
    float32 f32_m_slope_2_1;		/*## attribute f32_m_slope_2_1 */
    float32 f32_m_slope_2_2;		/*## attribute f32_m_slope_2_2 */
    float32 f32_m_slope_2_3;		/*## attribute f32_m_slope_2_3 */
    float32 f32_m_slope_2_prod;		/*## attribute f32_m_slope_2_prod */
    float32 f32_m_slope_3_1;		/*## attribute f32_m_slope_3_1 */
    float32 f32_m_slope_3_2;		/*## attribute f32_m_slope_3_2 */
    float32 f32_m_slope_3_3;		/*## attribute f32_m_slope_3_3 */
    float32 f32_m_slope_3_prod;		/*## attribute f32_m_slope_3_prod */
    float32 f32_RatioRedGreen;		/*## attribute f32_RatioRedGreen */
    float32 f32_RatioBlueGreen;		/*## attribute f32_RatioBlueGreen */
} IRCC_S_Constants;

/*## type IRCC_S_Input */
typedef struct IRCC_S_Input {
    IC_S_RegBuff * ps_ImagerRegs;		/*## attribute ps_ImagerRegs */
    uint16 ui16_Blacklevel;		/*## attribute ui16_Blacklevel */
} IRCC_S_Input;

/*## type IRCC_S_Results */
typedef struct IRCC_S_Results {
    float32 f32_Act_R1;		/*## attribute f32_Act_R1 */
    float32 f32_Act_R2;		/*## attribute f32_Act_R2 */
    float32 f32_Gain;		/*## attribute f32_Gain */
    float32 f32_P2;		/*## attribute f32_P2 */
    float32 f32_R1;		/*## attribute f32_R1 */
    float32 f32_R2;		/*## attribute f32_R2 */
    float32 f32_T1_New;		/*## attribute f32_T1_New */
    float32 f32_X_Grayvalue_512;		/*## attribute f32_X_Grayvalue_512 */
    float32 f32_X_Kneepoint_1;		/*## attribute f32_X_Kneepoint_1 */
    float32 f32_X_Kneepoint_2;		/*## attribute f32_X_Kneepoint_2 */
    float32 f32_X_Saturation;		/*## attribute f32_X_Saturation */
    float32 f32_Y_BL_0;		/*## attribute f32_Y_BL_0 */
    float32 f32_Y_BL_1;		/*## attribute f32_Y_BL_1 */
    float32 f32_Y_BL_2;		/*## attribute f32_Y_BL_2 */
    float32 f32_Y_Grayvalue_512;		/*## attribute f32_Y_Grayvalue_512 */
    float32 f32_Y_Kneepoint_1;		/*## attribute f32_Y_Kneepoint_1 */
    float32 f32_Y_Kneepoint_2;		/*## attribute f32_Y_Kneepoint_2 */
    float32 f32_Y_Saturation;		/*## attribute f32_Y_Saturation */
    float32 f32_m_T1_new;		/*## attribute f32_m_T1_new */
    float32 f32_m_main_new;		/*## attribute f32_m_main_new */
    float32 f32_m_slope_2;		/*## attribute f32_m_slope_2 */
    float32 f32_m_slope_3;		/*## attribute f32_m_slope_3 */
    uint8 ui8_ResponseCurveFormIndex;		/*## attribute ui8_ResponseCurveFormIndex */
} IRCC_S_Results;

/*## type IRCC_S_Obj */
typedef struct IRCC_S_Obj {
    IRCC_S_Input * ps_Input;		/*## attribute ps_Input */
    IRCC_S_Constants s_Constants;		/*## attribute s_Constants */
    IRCC_S_Results s_ResponseCurveIntermResults;		/*## attribute s_ResponseCurveIntermResults */
} IRCC_S_Obj;

/***    User explicit entries    ***/


/* Operations */

//*****************************************************************************
//  Functionname:  IRCC_e_SetImagerPPARs
//  
//  
//  
//  Parameter:     IRCC_S_Obj * const ps_Obj   <In>
//  
//  
//  Parameter:     const IRCC_S_PPARs * const ps_PPARs   <In>
//  
//    
//  
//  return         IRCC_E_ERROR
//**************************************************************************** */
/*## operation IRCC_e_SetImagerPPARs(IRCC_S_Obj * const,const IRCC_S_PPARs * const) */
IRCC_E_ERROR IRCC_e_SetImagerPPARs(IRCC_S_Obj * const ps_Obj, const IRCC_S_PPARs * const ps_PPARs);

//*****************************************************************************
//  Functionname:  IRCC_v_SetInput
//  
//  
//  
//  Parameter:     IRCC_S_Obj * const ps_Obj   <In>
//  
//  
//  Parameter:     IRCC_S_Input * const ps_Input   <In>
//  
//    
//  
//  return         void
//**************************************************************************** */
/*## operation IRCC_v_SetInput(IRCC_S_Obj * const,IRCC_S_Input * const) */
void IRCC_v_SetInput(IRCC_S_Obj * const ps_Obj, IRCC_S_Input * const ps_Input);

//*****************************************************************************
//  Functionname:  IRCC_e_CalcImagerResponseCurve
//  
//  
//  
//  Parameter:     IRCC_S_Obj * const ps_Obj   <In>
//  
//    
//  
//  return         IRCC_E_ERROR
//**************************************************************************** */
/*## operation IRCC_e_CalcImagerResponseCurve(IRCC_S_Obj * const) */
IRCC_E_ERROR IRCC_e_CalcImagerResponseCurve(IRCC_S_Obj * const ps_Obj);

//*****************************************************************************
//  Functionname:  IRCC_e_GetResponseCurve
//  
//  
//  
//  Parameter:     const IRCC_S_Obj * const ps_Instance   <In>
//  
//  
//  Parameter:     IRCC_S_ResponseCurve * const ps_ResposeCurve   <In>
//  
//    
//  
//  return         IRCC_E_ERROR
//**************************************************************************** */
/*## operation IRCC_e_GetResponseCurve(const IRCC_S_Obj * const,IRCC_S_ResponseCurve * const) */
IRCC_E_ERROR IRCC_e_GetResponseCurve(const IRCC_S_Obj * const ps_Instance, IRCC_S_ResponseCurve * const ps_ResposeCurve);

//*****************************************************************************
//  Functionname:  IRCC_ui16_Calc12BitCompandedMean
//  
//  Converts a 20-bit linear mean to the corresponding companded 12-bit value
//  by using the current imager settings (division ratios etc.)
//  
//  Parameter:     const IRCC_S_Obj * const ps_Instance   <In>
//  
//  
//  Parameter:     const uint32 ui32_Mean20Bit   <In>
//  
//    
//  
//  return         uint16
//**************************************************************************** */
/*## operation IRCC_ui16_Calc12BitCompandedMean(const IRCC_S_Obj * const,const uint32) */
uint16 IRCC_ui16_Calc12BitCompandedMean(const IRCC_S_Obj * const ps_Instance, const uint32 ui32_Mean20Bit);

//*****************************************************************************
//  Functionname:  IRCC_ui32_Calc20BitLinearMean
//  
//  Linearize companded grayvalue
//  
//  Parameter:     const IRCC_S_Obj * const ps_Instance   <In>
//  
//  
//  Parameter:     const uint16 ui16_Mean12Bit   <In>
//  
//    
//  
//  return         uint32
//**************************************************************************** */
/*## operation IRCC_ui32_Calc20BitLinearMean(const IRCC_S_Obj * const,const uint16) */
uint32 IRCC_ui32_Calc20BitLinearMean(const IRCC_S_Obj * const ps_Instance, const uint16 ui16_Mean12Bit);

//*****************************************************************************
//  Functionname:  IRCC_f32_CalcBrightnessCd
//  
//  Calculates the "true" "real world" brightness in Cd/qm from a 20-bit linearized pixel value
//  
//  Parameter:     const IRCC_S_Obj * const ps_Instance   <In>
//  
//  
//  Parameter:     const uint32 ui32_Mean20Bit   <In>
//  
//    
//  
//  return         float32
//**************************************************************************** */
/*## operation IRCC_f32_CalcBrightnessCd(const IRCC_S_Obj * const,const uint32) */
float32 IRCC_f32_CalcBrightnessCd(const IRCC_S_Obj * const ps_Instance, const uint32 ui32_Mean20Bit);

//*****************************************************************************
//  Functionname:  IRCC_f32_CalcBrightnessCdCompanded
//  
//  Calculates the "true" "real world" brightness in Cd/qm from a 12-Bit companded pixel value
//  
//  Parameter:     const IRCC_S_Obj * const ps_Instance   <In>
//  
//  
//  Parameter:     const uint16 ui16_CompandedGrayValue12Bit   <In>
//  
//    
//  
//  return         float32
//**************************************************************************** */
/*## operation IRCC_f32_CalcBrightnessCdCompanded(const IRCC_S_Obj * const,const uint16) */
float32 IRCC_f32_CalcBrightnessCdCompanded(const IRCC_S_Obj * const ps_Instance, const uint16 ui16_CompandedGrayValue12Bit);


/*#[ ignore */

#ifdef __cplusplus
}
#endif

/*#]*/


#endif
/*********************************************************************
	File Path: ..\..\..\04_Engineering\01_Source_Code\Algo\ic\ic_responsecurve.h
*********************************************************************/
