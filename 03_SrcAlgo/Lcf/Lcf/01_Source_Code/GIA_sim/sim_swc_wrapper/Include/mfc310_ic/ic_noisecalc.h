//* **********************************************************************
//  COMPANY:         $CompanyInfo: CONFIDENTIAL AND PROPRIETARY PROPERTY OF CONTINENTAL AG , A.D.C. GmbH  -  ALL RIGHTS RESERVED $
//  
//  PROJECT:         MFC30x_MCU
//  CPU:             MPC5675K
//  
//  PACKAGE:         $Source: ic_noisecalc.h $ $Revision: 1.1 $
//  MKS Date:        $Date: 2021/12/13 17:25:55CET $
//  
//  RHAPSODY:        7.5.3
//  COMPONENT:       IC
//  CONFIGURATION:   DefaultConfig
//  MODEL ELEMENT:   ic_noisecalc
//  MODULNAME:       ..\..\..\04_Engineering\01_Source_Code\Algo\ic\ic_noisecalc.h
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
//  Possible dereference of NULL pointer
//      PRQA S 0506 EOF
//  
//  AUTHOR:          $Author: Wang, David (Wangd3) $
//! CREATION DATE:   Tue, 24, Jul 2012  11:53 W. Europe Daylight Time AM 
//**************************************************************************** */

#ifndef ic_noisecalc_H
#define ic_noisecalc_H

/*## dependency ic_types */
#include "ic_types.h"
/*## package Ic_Pkg */

/*## class TopLevel::ic_noisecalc */
/*#[ ignore */
//  ==========================================================================================
//  The following QAC messages are suppressed for this module:
//  
//  This is a pure algorithmic module, which is implemented according a specification document,
//  so there are many 'magic' numbers of course. Giving all of them a name would result in
//  unreadable code:
//      PRQA S 3120,3121 EOF
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


/*#[ type IMGNC_E_ERROR */
typedef enum {
    IMGNC_e_ERR_OK,
    IMGNC_e_ERR_WRONG_STATE,
    IMGNC_e_ERR_BAD_PARAMS,
    IMGNC_e_ERR_BAD_INPUT
}  IMGNC_E_ERROR;
/*#]*/

/*#[ type IMGNC_E_STATE */
typedef enum {
    IMGNC_e_STATE_INIT,
    IMGNC_e_STATE_LINE8_SHIELDED_ROW,
    IMGNC_e_STATE_LINE10_TIED_ROW,
    IMGNC_e_STATE_LINE12_SHIELDED_ROW,
    IMGNC_e_STATE_REGISTERS,
    IMGNC_e_STATE_DONE
}  IMGNC_E_STATE;
/*#]*/

/*## type IMGNC_S_Params */
typedef struct IMGNC_S_Params {
    float32 f32_BlacklevelOffset;		/*## attribute f32_BlacklevelOffset */
    float32 f32_FilterDampingFactor;		/*## attribute f32_FilterDampingFactor */
    uint16 ui16_ImgWidth;		/*## attribute ui16_ImgWidth */
    uint16 ui16_ImgXStart;		/*## attribute ui16_ImgXStart */
} IMGNC_S_Params;

/*## type IMGNC_S_Results */
typedef struct IMGNC_S_Results {
    float32 f32_NoiseStdDev;		/*## attribute f32_NoiseStdDev */
    float32 f32_NoiseStdDevToAlgo;		/*## attribute f32_NoiseStdDevToAlgo */
    float32 f32_BlacklevelCurrent;		/*## attribute f32_BlacklevelCurrent */
    float32 f32_BlacklevelFiltered;		/*## attribute f32_BlacklevelFiltered */
} IMGNC_S_Results;

/*## type IMGNC_S_Obj */
typedef struct IMGNC_S_Obj {
    IMGNC_E_STATE e_State;		/*## attribute e_State */
    IMGNC_S_Params s_Params;		/*## attribute s_Params */
    IMGNC_S_Results s_Results;		/*## attribute s_Results */
    uint32 ui32_PixelSumDDC;		/*## attribute ui32_PixelSumDDC */
    uint32 ui32_PixelSumNoDDC;		/*## attribute ui32_PixelSumNoDDC */
    uint32 ui32_PixelSquareSumDDC;		/*## attribute ui32_PixelSquareSumDDC */
    uint32 ui32_PixelSquareSumNoDDC;		/*## attribute ui32_PixelSquareSumNoDDC */
    float32 f32_PixelMeanDDC;		/*## attribute f32_PixelMeanDDC */
    float32 f32_PixelMeanNoDDC;		/*## attribute f32_PixelMeanNoDDC */
    uint16 ui16_FirstBlockStartX;		/*## attribute ui16_FirstBlockStartX */
    uint16 ui16_NumBlocks;		/*## attribute ui16_NumBlocks */
    uint16 ui16_NumPixelsDDC;		/*## attribute ui16_NumPixelsDDC */
    uint16 ui16_NumPixelsNoDDC;		/*## attribute ui16_NumPixelsNoDDC */
} IMGNC_S_Obj;

/***    User explicit entries    ***/


/* Operations */

//*****************************************************************************
//  Functionname:  IMGNC_e_Init
//  
//  Initializes the imager noise calculation module.
//  The parameters will be copied to the object structure, so
//  *ps_Params is never accessed after this function returns.
//  
//  Parameter:     IMGNC_S_Obj * const ps_Obj   <In>
//  
//  
//  Parameter:     const IMGNC_S_Params * const ps_Params   <In>
//  
//    
//  
//  return         IMGNC_E_ERROR
//**************************************************************************** */
/*## operation IMGNC_e_Init(IMGNC_S_Obj * const,const IMGNC_S_Params * const) */
IMGNC_E_ERROR IMGNC_e_Init(IMGNC_S_Obj * const ps_Obj, const IMGNC_S_Params * const ps_Params);

//*****************************************************************************
//  Functionname:  IMGNC_e_LineCallback
//  
//  
//  
//  Parameter:     IMGNC_S_Obj * const ps_Obj   <In>
//  
//  
//  Parameter:     const uint16 ui16_LineNumber   <In>
//  
//  
//  Parameter:     const uint16 * const pui16_PixelData   <In>
//  
//    
//  
//  return         IMGNC_E_ERROR
//**************************************************************************** */
/*## operation IMGNC_e_LineCallback(IMGNC_S_Obj * const,const uint16,const uint16 * const) */
IMGNC_E_ERROR IMGNC_e_LineCallback(IMGNC_S_Obj * const ps_Obj, const uint16 ui16_LineNumber, const uint16 * const pui16_PixelData);

//*****************************************************************************
//  Functionname:  IMGNC_e_MainFunc
//  
//  
//  
//  Parameter:     IMGNC_S_Obj * const ps_Obj   <In>
//  
//  
//  Parameter:     const uint32 ui32_SumDeltaDkT1T2T3   <In>
//  
//  
//  Parameter:     const float32 f32_ApplyGain   <In>
//  
//    
//  
//  return         IMGNC_E_ERROR
//**************************************************************************** */
/*## operation IMGNC_e_MainFunc(IMGNC_S_Obj * const,const uint32,const float32) */
IMGNC_E_ERROR IMGNC_e_MainFunc(IMGNC_S_Obj * const ps_Obj, const uint32 ui32_SumDeltaDkT1T2T3, const float32 f32_ApplyGain);

//*****************************************************************************
//  Functionname:  IMGNC_e_GetResults
//  
//  
//  
//  Parameter:     const IMGNC_S_Obj * const ps_Obj   <In>
//  
//  
//  Parameter:     IMGNC_S_Results * const ps_Results   <In>
//  
//    
//  
//  return         IMGNC_E_ERROR
//**************************************************************************** */
/*## operation IMGNC_e_GetResults(const IMGNC_S_Obj * const,IMGNC_S_Results * const) */
IMGNC_E_ERROR IMGNC_e_GetResults(const IMGNC_S_Obj * const ps_Obj, IMGNC_S_Results * const ps_Results);


/*#[ ignore */

#ifdef __cplusplus
}
#endif

/*#]*/


#endif
/*********************************************************************
	File Path: ..\..\..\04_Engineering\01_Source_Code\Algo\ic\ic_noisecalc.h
*********************************************************************/
