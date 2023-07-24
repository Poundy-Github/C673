//* **********************************************************************
//  COMPANY:         $CompanyInfo: CONFIDENTIAL AND PROPRIETARY PROPERTY OF CONTINENTAL AG , A.D.C. GmbH  -  ALL RIGHTS RESERVED $
//  
//  PROJECT:         MFC30x_MCU
//  CPU:             MPC5675K
//  
//  PACKAGE:         $Source: ic_noisecalc.c $ $Revision: 1.1 $
//  MKS Date:        $Date: 2021/12/13 17:25:55CET $
//  
//  RHAPSODY:        7.5.3
//  COMPONENT:       IC
//  CONFIGURATION:   DefaultConfig
//  MODEL ELEMENT:   ic_noisecalc
//  MODULNAME:       ..\..\..\04_Engineering\01_Source_Code\Algo\ic\ic_noisecalc.c
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
//! CREATION DATE:   Tue, 24, Jul 2012  11:49 W. Europe Daylight Time AM 
//**************************************************************************** */

/*## auto_generated */
#include "ic_noisecalc.h"
/*## auto_generated */
#include <math.h>
/*## package Ic_Pkg */

/*## class TopLevel::ic_noisecalc */


/*#[ ignore */
#ifdef __cplusplus
extern "C"
{
#endif

/*#]*/


/*## attribute IMGNC_cui16_ROWNUM_8_SHIELDED */
#define IMGNC_cui16_ROWNUM_8_SHIELDED 8u

/*## attribute IMGNC_cui16_ROWNUM_10_TIED */
#define IMGNC_cui16_ROWNUM_10_TIED 10u

/*## attribute IMGNC_cui16_ROWNUM_12_SHIELDED */
#define IMGNC_cui16_ROWNUM_12_SHIELDED 12u

//  Width of sub-block with or without DDC (delta dark correction)
/*## attribute IMGNC_cui16_SUBBLOCK_WIDTH */
#define IMGNC_cui16_SUBBLOCK_WIDTH ((uint16)32)

//  Width of a single block (in columns)
/*## attribute IMGNC_cui16_BLOCK_WIDTH */
#define IMGNC_cui16_BLOCK_WIDTH (2u * IMGNC_cui16_SUBBLOCK_WIDTH)

//  Absolute start position of the first block (in columns).
//  NOTE: This is the relative to the first internal imager column,
//       not to the first column of the output-image!
/*## attribute IMGNC_cui16_COL_FIRST_BLOCK_ABS */
#define IMGNC_cui16_COL_FIRST_BLOCK_ABS ((uint16)116)

//  First imager internal column of the active pixel area (0..95 are black columns)
/*## attribute IMGNC_cui16_COL_ACTIVE_AREA_START */
#define IMGNC_cui16_COL_ACTIVE_AREA_START ((uint16)96)

//  Offset of a DDC subblock inside a 64-pixel block
/*## attribute IMGNC_cui16_SUBBLOCK_DDC_OFFSET */
#define IMGNC_cui16_SUBBLOCK_DDC_OFFSET (IMGNC_cui16_SUBBLOCK_WIDTH)

//  Offset of a NoDDC subblock inside a 64-pixel block
/*## attribute IMGNC_cui16_SUBBLOCK_NODDC_OFFSET */
#define IMGNC_cui16_SUBBLOCK_NODDC_OFFSET (0)

//  According to spec, actual noise is a bit higher than measured
/*## attribute IMGNC_cf32_NOISE_CORR_FACTOR */
#define IMGNC_cf32_NOISE_CORR_FACTOR 1.1f

//  Laboratory experiments showed that real noise in image can not be lower than this value
/*## attribute IMGNC_cf32_NOISE_CLAMP_LOWER */
#define IMGNC_cf32_NOISE_CLAMP_LOWER 2.0f

//  The next state after init which is also the first starting-state
//  in the periodic execution cycle
/*## attribute IMGNC_ce_STATE_AFTER_INIT */
#define IMGNC_ce_STATE_AFTER_INIT (IMGNC_e_STATE_LINE8_SHIELDED_ROW)

//*****************************************************************************
//  Functionname:  IMGNC_v_CalcSubblockSums
//  
//  
//  
//  Parameter:     const uint16 * const pui16_FirstSubblockPixel   <In>
//  
//  
//  Parameter:     uint16 ui16_NumBlocks   <In>
//  
//  
//  Parameter:     uint32 * const pui32_Sum   <In>
//  
//  
//  Parameter:     uint32 * const pui32_SquareSum   <In>
//  
//    
//  
//  return         void
//**************************************************************************** */
/*## operation IMGNC_v_CalcSubblockSums(const uint16 * const,uint16,uint32 * const,uint32 * const) */
static void IMGNC_v_CalcSubblockSums(const uint16 * const pui16_FirstSubblockPixel, uint16 ui16_NumBlocks, uint32 * const pui32_Sum, uint32 * const pui32_SquareSum);

/*## operation IMGNC_e_Init(IMGNC_S_Obj * const,const IMGNC_S_Params * const) */
IMGNC_E_ERROR IMGNC_e_Init(IMGNC_S_Obj * const ps_Obj, const IMGNC_S_Params * const ps_Params) {
    /*#[ operation IMGNC_e_Init(IMGNC_S_Obj * const,const IMGNC_S_Params * const) */
    IMGNC_E_ERROR e_Ret = IMGNC_e_ERR_OK;
    sint16 si16_FirstBlockStartX = 0;
    
    // Check input
    if (  (ps_Params->f32_FilterDampingFactor <  0.0f)
       || (ps_Params->f32_FilterDampingFactor >= 1.0f)
       || (ps_Params->ui16_ImgWidth           <  IMGNC_cui16_BLOCK_WIDTH)
       || (ps_Params->ui16_ImgXStart          >  (ps_Params->ui16_ImgWidth - IMGNC_cui16_BLOCK_WIDTH))
       )
    {
      e_Ret = IMGNC_e_ERR_BAD_PARAMS;
    }
    else
    {
      ps_Obj->e_State = IMGNC_e_STATE_INIT;
      ps_Obj->s_Results.f32_BlacklevelFiltered = 0.0f;
    
      // Calculate some constants
      si16_FirstBlockStartX = ((sint16)(IMGNC_cui16_COL_FIRST_BLOCK_ABS)
                             - (sint16)(IMGNC_cui16_COL_ACTIVE_AREA_START + ps_Params->ui16_ImgXStart));
      while (si16_FirstBlockStartX < 0)
      {
        si16_FirstBlockStartX += (sint16)IMGNC_cui16_BLOCK_WIDTH;
      }
      ps_Obj->ui16_FirstBlockStartX = (uint16)si16_FirstBlockStartX;
      ps_Obj->ui16_NumBlocks = (ps_Params->ui16_ImgWidth - ps_Obj->ui16_FirstBlockStartX) / IMGNC_cui16_BLOCK_WIDTH;
    
      // Take over the parameters
      ps_Obj->s_Params = *ps_Params;
      ps_Obj->e_State = IMGNC_ce_STATE_AFTER_INIT;
    }
    return e_Ret;
    /*#]*/
}

/*## operation IMGNC_e_LineCallback(IMGNC_S_Obj * const,const uint16,const uint16 * const) */
IMGNC_E_ERROR IMGNC_e_LineCallback(IMGNC_S_Obj * const ps_Obj, const uint16 ui16_LineNumber, const uint16 * const pui16_PixelData) {
    /*#[ operation IMGNC_e_LineCallback(IMGNC_S_Obj * const,const uint16,const uint16 * const) */
    IMGNC_E_ERROR e_Ret = IMGNC_e_ERR_OK;
    uint32 ui32_BlockStart  = 0;
    uint32 ui32_Sum         = 0;
    uint32 ui32_SquareSum   = 0;
    
    // If we are in state done from a previous run, switch to first valid processing state
    if (IMGNC_e_STATE_DONE == ps_Obj->e_State)
    {
      ps_Obj->e_State = IMGNC_ce_STATE_AFTER_INIT;
    }
    
    // Check state
    if (
        ( (ui16_LineNumber == IMGNC_cui16_ROWNUM_8_SHIELDED)  && (ps_Obj->e_State != IMGNC_e_STATE_LINE8_SHIELDED_ROW)  )
     || ( (ui16_LineNumber == IMGNC_cui16_ROWNUM_10_TIED)     && (ps_Obj->e_State != IMGNC_e_STATE_LINE10_TIED_ROW)     )
     || ( (ui16_LineNumber == IMGNC_cui16_ROWNUM_12_SHIELDED) && (ps_Obj->e_State != IMGNC_e_STATE_LINE12_SHIELDED_ROW) )
       )
    {
      e_Ret = IMGNC_e_ERR_WRONG_STATE;
      ps_Obj->e_State = IMGNC_ce_STATE_AFTER_INIT;
    }
    
    // Go on if no error
    if (IMGNC_e_ERR_OK == e_Ret)
    {
      switch (ui16_LineNumber)
      {
      case IMGNC_cui16_ROWNUM_8_SHIELDED:
        ui32_BlockStart = ps_Obj->ui16_FirstBlockStartX + IMGNC_cui16_SUBBLOCK_DDC_OFFSET;
        IMGNC_v_CalcSubblockSums(pui16_PixelData + ui32_BlockStart, ps_Obj->ui16_NumBlocks, &ui32_Sum, &ui32_SquareSum); // PRQA S 0488,0510
        ps_Obj->ui32_PixelSumDDC = ui32_Sum;
        ps_Obj->ui32_PixelSquareSumDDC = ui32_SquareSum;
    
        // Reset NoDDC sums to zero
        ps_Obj->ui32_PixelSumNoDDC = 0;
        ps_Obj->ui32_PixelSquareSumNoDDC = 0;
        ps_Obj->e_State = IMGNC_e_STATE_LINE10_TIED_ROW;
        break;
    
      case IMGNC_cui16_ROWNUM_10_TIED:
        // Calculate Sum and Square-Sum for non-DDC blocks
        ui32_BlockStart = ps_Obj->ui16_FirstBlockStartX + IMGNC_cui16_SUBBLOCK_NODDC_OFFSET;
        IMGNC_v_CalcSubblockSums(pui16_PixelData + ui32_BlockStart, ps_Obj->ui16_NumBlocks, &ui32_Sum, &ui32_SquareSum); // PRQA S 0488,0510
        ps_Obj->ui32_PixelSumNoDDC += ui32_Sum;
        ps_Obj->ui32_PixelSquareSumNoDDC += ui32_SquareSum;
        ps_Obj->e_State = IMGNC_e_STATE_LINE12_SHIELDED_ROW;
        break;
    
      case IMGNC_cui16_ROWNUM_12_SHIELDED:
        // Calculate Sum and Square-Sum for DDC blocks
        ui32_BlockStart = ps_Obj->ui16_FirstBlockStartX + IMGNC_cui16_SUBBLOCK_DDC_OFFSET;
        IMGNC_v_CalcSubblockSums(pui16_PixelData + ui32_BlockStart, ps_Obj->ui16_NumBlocks, &ui32_Sum, &ui32_SquareSum); // PRQA S 0488,0510
        ps_Obj->ui32_PixelSumDDC += ui32_Sum;
        ps_Obj->ui32_PixelSquareSumDDC += ui32_SquareSum;
        ps_Obj->e_State = IMGNC_e_STATE_REGISTERS;
        break;
    
      default:
        /* We are not interested in this line, so do nothing */
        break;
      }
    }
    return e_Ret;
    /*#]*/
}

/*## operation IMGNC_e_MainFunc(IMGNC_S_Obj * const,const uint32,const float32) */
IMGNC_E_ERROR IMGNC_e_MainFunc(IMGNC_S_Obj * const ps_Obj, const uint32 ui32_SumDeltaDkT1T2T3, const float32 f32_ApplyGain) {
    /*#[ operation IMGNC_e_MainFunc(IMGNC_S_Obj * const,const uint32,const float32) */
    IMGNC_E_ERROR e_Ret = IMGNC_e_ERR_OK;
    const float32 f32_ApplyGainSquare = f32_ApplyGain * f32_ApplyGain;
    float32 f32_SigmaSquare     = 0.0f;
    float32 f32_NumPixelsDDC    = 0.0f;
    float32 f32_NumPixelsNoDDC  = 0.0f;
    float32 f32_MeanDDC         = 0.0f;
    float32 f32_MeanNonDDC      = 0.0f;
    
    // Are we in the correct state?
    if (IMGNC_e_STATE_REGISTERS != ps_Obj->e_State)
    {
      e_Ret = IMGNC_e_ERR_WRONG_STATE;
      ps_Obj->e_State = IMGNC_ce_STATE_AFTER_INIT;
    }
    else
    {
      // NoDDC dark-rows doesn't "see" digital-gain factor, so apply correction factor to pre-calculations
      // PRQA S 4119 2
      ps_Obj->ui32_PixelSumNoDDC       = (uint32)((float32)ps_Obj->ui32_PixelSumNoDDC * f32_ApplyGain);
      ps_Obj->ui32_PixelSquareSumNoDDC = (uint32)((float32)ps_Obj->ui32_PixelSquareSumNoDDC * f32_ApplyGainSquare);
    
      // Calculate means
      f32_NumPixelsDDC           = (float32)(ps_Obj->ui16_NumBlocks * (IMGNC_cui16_SUBBLOCK_WIDTH * 2));
      f32_NumPixelsNoDDC         = (float32)(ps_Obj->ui16_NumBlocks * (IMGNC_cui16_SUBBLOCK_WIDTH * 1));
      f32_MeanDDC                = (1.0f / f32_NumPixelsDDC)   * (float32)ps_Obj->ui32_PixelSumDDC;
      f32_MeanNonDDC             = (1.0f / f32_NumPixelsNoDDC) * (float32)ps_Obj->ui32_PixelSumNoDDC;
      ps_Obj->f32_PixelMeanDDC   = f32_MeanDDC;
      ps_Obj->f32_PixelMeanNoDDC = f32_MeanNonDDC;
    
      // Calculate variance on no-DDC blocks:
      // Use modified single-pass formula according to specs because it's faster than
      // the "standard" way
      f32_SigmaSquare = - (f32_MeanNonDDC*f32_MeanNonDDC)
                        + ((1.0f / f32_NumPixelsNoDDC) * (float32)ps_Obj->ui32_PixelSquareSumNoDDC);
      f32_SigmaSquare *= f32_NumPixelsNoDDC / (f32_NumPixelsNoDDC - 1.0f);
    
      // Calculate standard deviation
      ps_Obj->s_Results.f32_NoiseStdDev = (float32)sqrt(f32_SigmaSquare) + IMGNC_cf32_NOISE_CORR_FACTOR;
    
      // According to spec, real noise can not be lower than some boundary
      ps_Obj->s_Results.f32_NoiseStdDevToAlgo = MAX(ps_Obj->s_Results.f32_NoiseStdDev, IMGNC_cf32_NOISE_CLAMP_LOWER);
    
      // Do black-level estimation
      ps_Obj->s_Results.f32_BlacklevelCurrent = f32_MeanDDC
                                              + ps_Obj->s_Params.f32_BlacklevelOffset
                                              + ((float32)ui32_SumDeltaDkT1T2T3 - f32_MeanNonDDC);
    
      // Filter black-level
      if (0.0f == ps_Obj->s_Results.f32_BlacklevelFiltered) // PRQA S 3341
      {
        // First execution: Initialize filter with first non-filtered blacklevel
        ps_Obj->s_Results.f32_BlacklevelFiltered = ps_Obj->s_Results.f32_BlacklevelCurrent;
      }
      else
      {
        // Apply filter
        ps_Obj->s_Results.f32_BlacklevelFiltered
              = (ps_Obj->s_Results.f32_BlacklevelCurrent * (1.0f - ps_Obj->s_Params.f32_FilterDampingFactor))
              + (ps_Obj->s_Results.f32_BlacklevelFiltered * ps_Obj->s_Params.f32_FilterDampingFactor);
      }
    
      ps_Obj->e_State = IMGNC_e_STATE_DONE;
    }
    return e_Ret;
    /*#]*/
}

/*## operation IMGNC_e_GetResults(const IMGNC_S_Obj * const,IMGNC_S_Results * const) */
IMGNC_E_ERROR IMGNC_e_GetResults(const IMGNC_S_Obj * const ps_Obj, IMGNC_S_Results * const ps_Results) {
    /*#[ operation IMGNC_e_GetResults(const IMGNC_S_Obj * const,IMGNC_S_Results * const) */
    IMGNC_E_ERROR e_Ret = IMGNC_e_ERR_OK;
    
    if (ps_Obj->e_State != IMGNC_e_STATE_DONE)
    {
      e_Ret = IMGNC_e_ERR_WRONG_STATE;
    }
    else
    {
      *ps_Results = ps_Obj->s_Results;
    }
    return e_Ret;
    /*#]*/
}

/*## operation IMGNC_v_CalcSubblockSums(const uint16 * const,uint16,uint32 * const,uint32 * const) */
static void IMGNC_v_CalcSubblockSums(const uint16 * const pui16_FirstSubblockPixel, uint16 ui16_NumBlocks, uint32 * const pui32_Sum, uint32 * const pui32_SquareSum) {
    /*#[ operation IMGNC_v_CalcSubblockSums(const uint16 * const,uint16,uint32 * const,uint32 * const) */
    #define cui16_PIXELS_PER_LOOP 4
    
    uint16 const *pui16_CurrentPixel = pui16_FirstSubblockPixel;
    uint32 ui32_LoopCounter = 0;
    uint32 aui32_Pix[cui16_PIXELS_PER_LOOP];
    uint32 ui32_Sum = 0;
    uint32 ui32_SquareSum = 0;
    
    // Process all blocks of the current line
    while (ui16_NumBlocks > 0)
    {
      // Process sub-block
      for (ui32_LoopCounter = 0; ui32_LoopCounter < IMGNC_cui16_SUBBLOCK_WIDTH; ui32_LoopCounter += cui16_PIXELS_PER_LOOP)
      {
        // Load 4 pixels (~50% faster than doing only one calc per loop)
        aui32_Pix[0] = (uint32)*pui16_CurrentPixel;
        pui16_CurrentPixel++; // PRQA S 0489
        aui32_Pix[1] = (uint32)*pui16_CurrentPixel;
        pui16_CurrentPixel++; // PRQA S 0489
        aui32_Pix[2] = (uint32)*pui16_CurrentPixel;
        pui16_CurrentPixel++; // PRQA S 0489
        aui32_Pix[3] = (uint32)*pui16_CurrentPixel;
        pui16_CurrentPixel++; // PRQA S 0489
    
        // Do calculations
        ui32_Sum       += aui32_Pix[0];
        ui32_Sum       += aui32_Pix[1];
        ui32_Sum       += aui32_Pix[2];
        ui32_Sum       += aui32_Pix[3];
        ui32_SquareSum += aui32_Pix[0] * aui32_Pix[0];
        ui32_SquareSum += aui32_Pix[1] * aui32_Pix[1];
        ui32_SquareSum += aui32_Pix[2] * aui32_Pix[2];
        ui32_SquareSum += aui32_Pix[3] * aui32_Pix[3];
      }
    
      // Skip following "other-type" sub-block
      pui16_CurrentPixel += IMGNC_cui16_SUBBLOCK_WIDTH; // PRQA S 0488
      ui16_NumBlocks--;
    }
    
    // Copy to outputs
    *pui32_Sum = ui32_Sum;
    *pui32_SquareSum = ui32_SquareSum;
    /*#]*/
}


/*#[ ignore */

#ifdef __cplusplus
}
#endif

/*#]*/


/*********************************************************************
	File Path: ..\..\..\04_Engineering\01_Source_Code\Algo\ic\ic_noisecalc.c
*********************************************************************/
