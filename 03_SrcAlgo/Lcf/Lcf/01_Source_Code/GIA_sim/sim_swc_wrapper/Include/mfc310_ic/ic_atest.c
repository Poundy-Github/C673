//* **********************************************************************
//  COMPANY:         $CompanyInfo: CONFIDENTIAL AND PROPRIETARY PROPERTY OF CONTINENTAL AG , A.D.C. GmbH  -  ALL RIGHTS RESERVED $
//  
//  PROJECT:         MFC30x_MCU
//  CPU:             MPC5675K
//  
//  PACKAGE:         $Source: ic_atest.c $ $Revision: 1.1 $
//  MKS Date:        $Date: 2021/12/13 17:25:46CET $
//  
//  RHAPSODY:        7.5.3
//  COMPONENT:       IC
//  CONFIGURATION:   DefaultConfig
//  MODEL ELEMENT:   ic_atest
//  MODULNAME:       ..\..\..\04_Engineering\01_Source_Code\Algo\ic\ic_atest.c
//  LOGIN:           uidt3974  
//  
//  =======================================================================================
//  The following QAC messages are suppressed for this module:
//  
//    Error handling is emulated by using an exclusive label ERROR_EXIT, which is entered
//    via GOTO on error. Code using this type of error handling is much easier to read,
//    as no nested if() statements are required and checking of error-code/flag on each
//    block can be omitted. Suppress QAC warnings related to this functionality:
//      PRQA S 2001,2015,7003 EOF
//  
//    The parameter 'xxxx' is never modified and so it could be declared with the 'const' qualifier.
//      PRQA S 3227 EOF
//  
//    Possible dereference of NULL pointer.
//      PRQA S 0506 EOF
//  
//  AUTHOR:          $Author: Wang, David (Wangd3) $
//! CREATION DATE:   Fri, 7, Sep 2012  10:50 W. Europe Daylight Time AM 
//**************************************************************************** */

/*## auto_generated */
#include "ic_atest.h"
/*## dependency ic_common */
#include "ic_common.h"
/*## dependency ic_driver */
#include "ic_driver.h"
/*## dependency ic_errmanager */
#include "ic_errmanager.h"
/*## dependency ic_initdata */
#include "ic_initdata.h"
/*## dependency ic_oswrapper */
#include "ic_oswrapper.h"
/*## dependency ic_regmanager */
#include "ic_regmanager.h"
/*## package Ic_Pkg */

/*## class TopLevel::ic_atest */


/*#[ ignore */
// Do not define anything if analog test is disabled in config file
#if (IC_ANALOG_TEST_ENABLED == 1)

// Optimize this file by size, as code is only used once at startup and thus
// it's not so much time critical
#pragma optimize_for_size on

// Use Signal Processing Extension intrinsics if available
#if (__SPE__ == 1)
#include "spe.h"
#endif

#ifdef __cplusplus
extern "C"
{
#endif

/*#]*/


//  Number of Frames that we use for calculation (3 Tests = 3 Frames)
/*## attribute ICAT_cui_NUM_USED_FRAMES */
#define ICAT_cui_NUM_USED_FRAMES 3u

//  The image integration time which will be used during analog test. This value should
//  not affect the results, because the analog test does not operate on pixel-level.
/*## attribute ICAT_cui_INTEGRATION_TIME_ATEST */
#define ICAT_cui_INTEGRATION_TIME_ATEST 1173

//  Conversion factor from fraction to percentage
/*## attribute ICAT_cf32_FRACT2PERC */
#define ICAT_cf32_FRACT2PERC 100.0f

//  ATest internal state
/*## attribute ICAT_e_State */
static ICAT_E_STATE ICAT_e_State = ICAT_e_STATE_WAIT_START;

/*## attribute ICAT_e_Status */
static IC_E_ATEST_STATUS ICAT_e_Status = IC_e_ATEST_STATUS_NOT_STARTED;

/*## attribute ICAT_s_Obj */
#pragma push
#if (ICCFG_HARDWARE_STEREO == 0)
#pragma section data_type ".ddr_data" ".ddr_bss"
#endif
static ICAT_S_Obj ICAT_s_Obj;
#pragma pop

/*## attribute ICAT_ps_MeasData */
static ICAT_S_MeasData * ICAT_ps_MeasData;

//  Name of this module, required for calls to ICERR_HANDLE().
//  
//  Character string is only used for debugging & recording analysis, so suppress QAC warnings:
//  PRQA S 5013,3625 3
/*## attribute pch_ModuleName */
static const char * const pch_ModuleName = "ATEST";

//*****************************************************************************
//  Functionname:  ICAT_v_PrepareNewFrame
//  
//  
//  
//  Parameter:     uint16 ui16_TriggerFrame   <In>
//  
//    
//  
//  return         void
//**************************************************************************** */
/*## operation ICAT_v_PrepareNewFrame(uint16) */
static void ICAT_v_PrepareNewFrame(uint16 ui16_TriggerFrame);

//*****************************************************************************
//  Functionname:  ICAT_e_CalcResults
//  
//  
//  
//  Parameter:     ICAT_S_Results * ps_Results   <In>
//  
//  
//  Parameter:     IC_E_ANALOG_GAIN e_Gain   <In>
//  
//  
//  Parameter:     boolean b_FillHighestDevs   <In>
//  
//    
//  
//  return         IC_E_ERROR
//**************************************************************************** */
/*## operation ICAT_e_CalcResults(ICAT_S_Results *,IC_E_ANALOG_GAIN,boolean) */
static IC_E_ERROR ICAT_e_CalcResults(ICAT_S_Results * ps_Results, IC_E_ANALOG_GAIN e_Gain, boolean b_FillHighestDevs);

//*****************************************************************************
//  Functionname:  ICAT_e_CheckResults
//  
//  
//  
//    
//  
//  return         IC_E_ERROR
//**************************************************************************** */
/*## operation ICAT_e_CheckResults() */
static IC_E_ERROR ICAT_e_CheckResults(void);

//*****************************************************************************
//  Functionname:  ICAT_e_CheckDeviation
//  
//  
//  
//  Parameter:     ICAT_S_Results * ps_Results   <In>
//  
//  
//  Parameter:     float32 f32_MeanRef   <In>
//  
//  
//  Parameter:     float32 f32_MeanTol   <In>
//  
//  
//  Parameter:     float32 f32_ColTol   <In>
//  
//    
//  
//  return         IC_E_ERROR
//**************************************************************************** */
/*## operation ICAT_e_CheckDeviation(ICAT_S_Results *,float32,float32,float32) */
static IC_E_ERROR ICAT_e_CheckDeviation(ICAT_S_Results * ps_Results, float32 f32_MeanRef, float32 f32_MeanTol, float32 f32_ColTol);

//*****************************************************************************
//  Functionname:  ICAT_v_UpdateExtResults
//  
//  
//  
//    
//  
//  return         void
//**************************************************************************** */
/*## operation ICAT_v_UpdateExtResults() */
static void ICAT_v_UpdateExtResults(void);

//*****************************************************************************
//  Functionname:  ICAT_e_RecalcNormOffsets
//  
//  
//  
//  Parameter:     const IC_S_ATestRefValues * ps_Ref   <In>
//  
//    
//  
//  return         IC_E_ERROR
//**************************************************************************** */
/*## operation ICAT_e_RecalcNormOffsets(const IC_S_ATestRefValues *) */
static IC_E_ERROR ICAT_e_RecalcNormOffsets(const IC_S_ATestRefValues * ps_Ref);

//*****************************************************************************
//  Functionname:  ICAT_v_ColumnwiseAccumulate_u16u32
//  
//  
//  
//  Parameter:     uint32 * pui32_Dst   <In>
//  
//  
//  Parameter:     const uint16 * pui16_Src   <In>
//  
//  
//  Parameter:     uint32 ui32_Count   <In>
//  
//    
//  
//  return         void
//**************************************************************************** */
/*## operation ICAT_v_ColumnwiseAccumulate_u16u32(uint32 *,const uint16 *,uint32) */
static void ICAT_v_ColumnwiseAccumulate_u16u32(uint32 * pui32_Dst, const uint16 * pui16_Src, uint32 ui32_Count);

//*****************************************************************************
//  Functionname:  ICAT_ui32_Normalize
//  
//  
//  
//  Parameter:     uint32 ui32_Value   <In>
//  
//  
//  Parameter:     IC_E_ANALOG_GAIN e_Gain   <In>
//  
//    
//  
//  return         uint32
//**************************************************************************** */
/*## operation ICAT_ui32_Normalize(uint32,IC_E_ANALOG_GAIN) */
static uint32 ICAT_ui32_Normalize(uint32 ui32_Value, IC_E_ANALOG_GAIN e_Gain);

//*****************************************************************************
//  Functionname:  ICAT_ui32_LinearizePixelValue_4x16x
//  
//  
//  
//  Parameter:     uint16 ui16_PixelValue   <In>
//  
//    
//  
//  return         uint32
//**************************************************************************** */
/*## operation ICAT_ui32_LinearizePixelValue_4x16x(uint16) */
static uint32 ICAT_ui32_LinearizePixelValue_4x16x(uint16 ui16_PixelValue);

/*## operation ICAT_v_Init(ICAT_S_MeasData *) */
void ICAT_v_Init(ICAT_S_MeasData * ps_Meas) {
    /*#[ operation ICAT_v_Init(ICAT_S_MeasData *) */
    ICAT_ps_MeasData = ps_Meas;
    
    // Initialize variables
    IC_v_ZEROMEM(ICAT_s_Obj);
    ICAT_e_State  = ICAT_e_STATE_WAIT_START;
    ICAT_e_Status = IC_e_ATEST_STATUS_NOT_STARTED;
    
    // Map some structs into measdata to save memory
    ICAT_s_Obj.ps_Results_ATV1_1x = &ICAT_ps_MeasData->s_Results_ATV1_1x;
    ICAT_s_Obj.ps_Results_ATV1_2x = &ICAT_ps_MeasData->s_Results_ATV1_2x;
    ICAT_s_Obj.ps_Results_ATV3_1x = &ICAT_ps_MeasData->s_Results_ATV3_1x;
    ICAT_s_Obj.ps_Parameters      = &ICAT_ps_MeasData->s_Parameters;
    
    // Call other init stuff
    ICAT_v_Reset();
    /*#]*/
}

/*## operation ICAT_e_SetRefValues(const IC_S_ATestRefValues *,const IC_S_ATestMaxTols *) */
IC_E_ERROR ICAT_e_SetRefValues(const IC_S_ATestRefValues * ps_ReferenceValues, const IC_S_ATestMaxTols * ps_MaxTols) {
    /*#[ operation ICAT_e_SetRefValues(const IC_S_ATestRefValues *,const IC_S_ATestMaxTols *) */
    IC_E_ERROR e_Ret = IC_e_ERR_OK;
    
    ICAT_s_Obj.ps_Parameters->s_ReferenceValues = *ps_ReferenceValues;
    ICAT_s_Obj.ps_Parameters->s_MaxTols         = *ps_MaxTols;
    
    // Recalculate offset required for normalization
    e_Ret = ICAT_e_RecalcNormOffsets(&ICAT_s_Obj.ps_Parameters->s_ReferenceValues);
    return e_Ret;
    /*#]*/
}

/*## operation ICAT_e_SetRoi(const IC_S_Roi *,uint16) */
IC_E_ERROR ICAT_e_SetRoi(const IC_S_Roi * ps_Roi, uint16 ui16_RoiStepsizeY) {
    /*#[ operation ICAT_e_SetRoi(const IC_S_Roi *,uint16) */
    IC_E_ERROR e_Ret = IC_e_ERR_OK;
    
    // Do range-checks
    if ( (ui16_RoiStepsizeY   < ICCFG_cui16_ATEST_ROI_MODULUS)
     ||  (ps_Roi->ui16_StartY < ICCFG_cui16_NumEmbeddedLinesPre)
     || ((ps_Roi->ui16_StartX + ps_Roi->ui16_Width)  > ICCFG_cui16_CROI_ODD_WIDTH)
     || ((ps_Roi->ui16_StartY + ps_Roi->ui16_Height) > ICCFG_cui_EMBEDDED_STAT_LINE_START_ODD)
        )
    {
      // Illegal parameter
      e_Ret = IC_e_ERR_ILLEGAL_ARGUMENT;
    }
    else
    {
      // Take over parameters
      ICAT_s_Obj.ps_Parameters->s_CalcRoi.ui16_x1 = ps_Roi->ui16_StartX;
      ICAT_s_Obj.ps_Parameters->s_CalcRoi.ui16_y1 = ps_Roi->ui16_StartY;
      ICAT_s_Obj.ps_Parameters->s_CalcRoi.ui16_x2 = IC_ui16_RoiEndX(ps_Roi);
      ICAT_s_Obj.ps_Parameters->s_CalcRoi.ui16_y2 = IC_ui16_RoiEndY(ps_Roi);
      ICAT_s_Obj.ps_Parameters->ui16_RoiStepsizeY = ui16_RoiStepsizeY;
    }
    return e_Ret;
    /*#]*/
}

/*## operation ICAT_e_SetAcquisitionParams(const IC_S_ATestAcquParams *) */
IC_E_ERROR ICAT_e_SetAcquisitionParams(const IC_S_ATestAcquParams * ps_AcquParams) {
    /*#[ operation ICAT_e_SetAcquisitionParams(const IC_S_ATestAcquParams *) */
    IC_E_ERROR e_Ret             = IC_e_ERR_OK;
    uint16 ui16_LinesUsedForCalc = 0;
    uint16 ui16_NumLinesPerRoi   = 0;
    uint32 ui32_BytesRequired    = 0;
    ICAT_S_Parameters const * const ps_Params = ICAT_s_Obj.ps_Parameters;
    
    // Nullpointer checks
    if (NULL == ps_AcquParams)
    {
      e_Ret = IC_e_ERR_NULLPOINTER;
    }
    else
    {
      // Checks: Number of lines to acquire can not be lower than # lines which are processed in the ROI
      ui16_LinesUsedForCalc = IC_ui16_RectHeight(&(ps_Params->s_CalcRoi)) / ps_Params->ui16_RoiStepsizeY;
      if (ps_AcquParams->ui16_NumLinesToAcquire > ui16_LinesUsedForCalc)
      {
        e_Ret = IC_e_ERR_ILLEGAL_ARGUMENT;
      }
    
      // Checks: ROI-Buffer big enough for acquisition?
      ui16_NumLinesPerRoi   = ps_AcquParams->ui16_NumLinesToAcquire + ICCFG_cui16_NumEmbeddedRegLines + ICCFG_cui16_NumEmbeddedStatLines;
      ui32_BytesRequired    = ui16_NumLinesPerRoi * ICCFG_cui16_ATEST_COPY_PIXELSPERLINE
                            * ICAT_cui_NUM_USED_FRAMES * ICCFG_cui16_BytesPerPixel;
      if ((ps_AcquParams->pui16_RoiBuffer != NULL)
            && (ps_AcquParams->ui32_BuffSizeBytes < ui32_BytesRequired))
      {
        e_Ret = IC_e_ERR_BUFFER_OVERRUN;
      }
    
      // Copy acquisition parameters if everything was OK
      if (IC_e_ERR_OK == e_Ret)
      {
        ICAT_s_Obj.pui16_RoiBuffer        = ps_AcquParams->pui16_RoiBuffer;
        ICAT_s_Obj.ui16_NumLinesToAcquire = ps_AcquParams->ui16_NumLinesToAcquire;
      }
    }
    
    return e_Ret;
    /*#]*/
}

/*## operation ICAT_v_SetSensorFuseId(uint64) */
void ICAT_v_SetSensorFuseId(uint64 ui64_SensorId) {
    /*#[ operation ICAT_v_SetSensorFuseId(uint64) */
    ICAT_s_Obj.ui64_SensorFuseId = ui64_SensorId;
    /*#]*/
}

/*## operation ICAT_e_Start() */
IC_E_ERROR ICAT_e_Start(void) {
    /*#[ operation ICAT_e_Start() */
    IC_E_ERROR e_Ret = IC_e_ERR_OK;
    
    // Check state
    if (ICAT_e_STATE_WAIT_START != ICAT_e_State)
    {
      e_Ret = IC_e_ERR_WRONG_STATE;
      ICAT_e_Status = IC_e_ATEST_STATUS_ERROR; /* Signal error to extern */
    }
    else
    {
      // Goto next state
      ICAT_e_Status = IC_e_ATEST_STATUS_EXECUTING;
      ICAT_e_State  = ICAT_e_STATE_PREPARE;
    }
    
    // Provide state to extern
    ICAT_v_UpdateExtResults();
    return e_Ret;
    /*#]*/
}

/*## operation ICAT_v_Reset() */
void ICAT_v_Reset(void) {
    /*#[ operation ICAT_v_Reset() */
    IC_v_ZEROMEM(*ICAT_s_Obj.ps_Results_ATV1_1x);
    IC_v_ZEROMEM(*ICAT_s_Obj.ps_Results_ATV1_2x);
    IC_v_ZEROMEM(*ICAT_s_Obj.ps_Results_ATV3_1x);
    IC_v_ZEROMEM(ICAT_s_Obj.aui32_ColumnPixelsSum);
    IC_v_ZEROMEM(ICAT_s_Obj.s_ExtResults);
    
    ICAT_s_Obj.ui16_CurrentLineNum     = 0;
    ICAT_s_Obj.ui16_CopiedLinesCount   = 0;
    ICAT_s_Obj.ui16_ProcessedLineCount = 0;
    ICAT_s_Obj.ui16_NumLinesToAcquire  = 0;
    ICAT_s_Obj.pui16_RoiBuffer         = NULL;
    ICAT_s_Obj.b_SamplingEnabled       = b_FALSE;
    ICAT_e_State                       = ICAT_e_STATE_WAIT_START;
    ICAT_e_Status                      = IC_e_ATEST_STATUS_NOT_STARTED;
    /*#]*/
}

/*## operation ICAT_e_Exec(uint16) */
IC_E_ERROR ICAT_e_Exec(uint16 ui16_FrameCnt) {
    /*#[ operation ICAT_e_Exec(uint16) */
    static const float32 cf32_DIGITAL_GAIN_1X = 1.0f; // 1x digital gain
    static const uint16  ui16_FRAMES_STEP     = 2;    // Number of frames between each step
    
    IC_E_ERROR          e_Ret         = IC_e_ERR_OK;
    IC_E_ERROR          e_SubRet      = IC_e_ERR_OK;
    IC_S_Roi            s_TestRoi;
    
    // Reflect current (entry) state in measurement data
    ICAT_ps_MeasData->e_State = ICAT_e_State;
    
    // Do processing according to state
    switch (ICAT_e_State)
    {
    case ICAT_e_STATE_WAIT_START:
      /* Do nothing, just wait */
      break;
    
    case ICAT_e_STATE_PREPARE:
      // Execution started
      ICAT_e_Status = IC_e_ATEST_STATUS_EXECUTING;
    
      // If analog test is in preparation, send register sequence now
      e_SubRet = ICRM_e_SendInitSequenceAsync(ICINIT_caui16_SensorEnterATestInitData,
                                              ICINIT_caui16_SensorEnterATestInitDataEntries);
      if (IC_e_ERR_OK != e_SubRet)
      {
        e_Ret = ICERR_HANDLE(IC_e_ERR_REGTX, e_SubRet);
        goto ERROR_EXIT;
      }
    
      // Set other register values
      (void)IMGDRV_e_SetExposureTime(ICAT_cui_INTEGRATION_TIME_ATEST);
      IMGDRV_v_SetDCG(IC_e_DCG_HIGH);
      IMGDRV_v_SetDigitalGain(cf32_DIGITAL_GAIN_1X);
      IMGDRV_v_SetIntegrationTimeRatios(IC_e_INTEGR_RATIO_16, IC_e_INTEGR_RATIO_16);
    
      // Register analog test ROI
      IC_v_RectToRoi(&s_TestRoi, &ICAT_s_Obj.ps_Parameters->s_CalcRoi);
      e_SubRet = ICOSW_e_RegisterTestRoi(&s_TestRoi);
      if (IC_e_ERR_OK != e_SubRet)
      {
        e_Ret = ICERR_HANDLE(IC_e_ERR_REGISTER_ROI, e_SubRet);
        goto ERROR_EXIT;
      }
    
      // Prepare first measurement: Set voltage and analog gain and trigger to two frames in future
      ICOSW_v_SetTestvoltage(IC_e_TESTVOLTAGE_ATV3);
      IMGDRV_v_SetAnalogGain(IC_e_ANALOG_GAIN_1X);
      ICAT_v_PrepareNewFrame(ui16_FrameCnt + ui16_FRAMES_STEP);
      ICAT_e_State = ICAT_e_STATE_MEAS_ATV3_1XGAIN;
      break;
    
    case ICAT_e_STATE_MEAS_ATV3_1XGAIN:
      if (b_TRUE == ICAT_s_Obj.b_LineCalcFinished)
      {
        e_SubRet = ICAT_e_CalcResults(ICAT_s_Obj.ps_Results_ATV3_1x, IC_e_ANALOG_GAIN_1X, b_TRUE);
        if (IC_e_ERR_OK != e_SubRet)
        {
          ICAT_e_Status = IC_e_ATEST_STATUS_ERROR;
          ICAT_e_State  = ICAT_e_STATE_CLEANUP;
        }
    
        // Prepare next voltage and gains
        ICOSW_v_SetTestvoltage(IC_e_TESTVOLTAGE_ATV1);
        ICAT_v_PrepareNewFrame(ui16_FrameCnt + ui16_FRAMES_STEP);
        ICAT_e_State = ICAT_e_STATE_MEAS_ATV1_1XGAIN;
      }
      break;
    
    case ICAT_e_STATE_MEAS_ATV1_1XGAIN:
      if (b_TRUE == ICAT_s_Obj.b_LineCalcFinished)
      {
        e_SubRet = ICAT_e_CalcResults(ICAT_s_Obj.ps_Results_ATV1_1x, IC_e_ANALOG_GAIN_1X, b_FALSE);
        if (IC_e_ERR_OK != e_SubRet)
        {
          ICAT_e_Status = IC_e_ATEST_STATUS_ERROR;
          ICAT_e_State  = ICAT_e_STATE_CLEANUP;
        }
    
        // Prepare next voltage and gains
        IMGDRV_v_SetAnalogGain(IC_e_ANALOG_GAIN_2X);
        ICAT_v_PrepareNewFrame(ui16_FrameCnt + ui16_FRAMES_STEP);
        ICAT_e_State = ICAT_e_STATE_MEAS_ATV1_2XGAIN;
      }
      break;
    
    case ICAT_e_STATE_MEAS_ATV1_2XGAIN:
      if (b_TRUE == ICAT_s_Obj.b_LineCalcFinished)
      {
        e_SubRet = ICAT_e_CalcResults(ICAT_s_Obj.ps_Results_ATV1_2x, IC_e_ANALOG_GAIN_2X, b_FALSE);
        if (IC_e_ERR_OK != e_SubRet)
        {
          ICAT_e_Status = IC_e_ATEST_STATUS_ERROR;
          ICAT_e_State  = ICAT_e_STATE_CLEANUP;
        }
    
        // This is the last tested frame, so do final checks
        e_SubRet = ICAT_e_CheckResults();
        if (IC_e_ERR_OK != e_SubRet)
        {
          ICAT_e_Status = IC_e_ATEST_STATUS_FINISHED_FAILED;
        }
        else
        {
          ICAT_e_Status = IC_e_ATEST_STATUS_FINISHED_PASSED;
        }
        ICAT_e_State = ICAT_e_STATE_CLEANUP;
      }
      break;
    
    case ICAT_e_STATE_CLEANUP:
      (void)ICOSW_e_DeleteTestRoi();
    
      // Set back to normal operation voltage
      ICOSW_v_SetTestvoltage(IC_e_TESTVOLTAGE_OMV);
    
      // If analog test is finished, send register sequence now
      e_SubRet = ICRM_e_SendInitSequenceAsync(ICINIT_caui16_SensorExitATestInitData,
                                              ICINIT_caui16_SensorExitATestInitDataEntries);
      if (IC_e_ERR_OK != e_SubRet)
      {
        e_Ret = ICERR_HANDLE(IC_e_ERR_REGTX, e_SubRet);
        goto ERROR_EXIT;
      }
    
      // We are finished!
      ICAT_e_State = ICAT_e_STATE_FINISHED;
      break;
    
    default:
      e_Ret = ICERR_HANDLE(IC_e_ERR_WRONG_STATE, ICAT_e_State);
      break;
    }
    
    // Update external results and measurement data
    ICAT_v_UpdateExtResults();
    ICAT_ps_MeasData->e_Status = ICAT_e_Status;
    
    ERROR_EXIT:
    if (IC_e_ERR_OK != e_Ret)
    {
      // Something went wrong ... goto cleanup state to prevent lock in ATEST Mode
      ICAT_e_State  = ICAT_e_STATE_CLEANUP;
      ICAT_e_Status = IC_e_ATEST_STATUS_ERROR;
    }
    return e_Ret;
    
    // PRQA S 7006 3
    /*#]*/
}

/*## operation ICAT_e_LineFunc(uint16,const uint16 [ICCFG_cui16_ATEST_ROI_WIDTH] ,uint16) */
IC_E_ERROR ICAT_e_LineFunc(uint16 ui16_LineNumber, const uint16 aui16_LineRawData[ICCFG_cui16_ATEST_ROI_WIDTH], uint16 ui16_FrameNum) {
    /*#[ operation ICAT_e_LineFunc(uint16,const uint16 [ICCFG_cui16_ATEST_ROI_WIDTH] ,uint16) */
    IC_E_ERROR e_Ret           = IC_e_ERR_OK;
    boolean    b_ProcessLine   = b_FALSE;
    boolean    b_CopyLine      = b_FALSE;
    uint16     ui16_NumColumns = 0;
    IC_S_Rect_ui16 const * const ps_Roi = &ICAT_s_Obj.ps_Parameters->s_CalcRoi;
    
    // Check nullpointers
    if (NULL == aui16_LineRawData)
    {
      e_Ret = IC_e_ERR_NULLPOINTER;
      goto ERROR_EXIT;
    }
    
    // Just for debugging ...
    ICAT_s_Obj.ui16_CurrentLineNum = ui16_LineNumber;
    
    // Finished last frame?
    if ((ui16_FrameNum > ICAT_s_Obj.ui16_TriggerFrame) && (b_TRUE == ICAT_s_Obj.b_SamplingEnabled))
    {
      ICAT_s_Obj.b_LineCalcFinished = b_TRUE;
      ICAT_s_Obj.b_SamplingEnabled  = b_FALSE;
    }
    
    // Copy new trigger if we have done last frame and there is a new trigger available
    if ((b_FALSE == ICAT_s_Obj.b_SamplingEnabled) && (b_TRUE == ICAT_s_Obj.b_NextTriggerValid))
    {
      ICAT_s_Obj.ui16_TriggerFrame        = ICAT_s_Obj.ui16_TriggerFrameNext;
      ICAT_s_Obj.b_SamplingEnabled        = b_TRUE;
      ICAT_s_Obj.b_NextTriggerValid       = b_FALSE;
      ICAT_s_Obj.ui16_ProcessedLineCount  = 0;
      ICAT_s_Obj.ui16_CopiedLinesCount    = 0;
    }
    
    // Skip if disabled
    if ((b_TRUE == ICAT_s_Obj.b_SamplingEnabled) && (ui16_FrameNum == ICAT_s_Obj.ui16_TriggerFrame))
    {
      // Process only every n'th line that's in our ROI
      if ( (((ui16_LineNumber -  ps_Roi->ui16_y1) % ICAT_s_Obj.ps_Parameters->ui16_RoiStepsizeY) == 0)
          && (ui16_LineNumber >= ps_Roi->ui16_y1)
          && (ui16_LineNumber <= ps_Roi->ui16_y2))
      {
        b_ProcessLine = b_TRUE;
      }
    
      // Copy image including embedded data to external image-buffer if requested (e.g. via XCP)
      if (ICAT_s_Obj.pui16_RoiBuffer != NULL)
      {
        // Always copy embedded data
        if (  (ICCFG_cui16_EmbeddedRegLineStart == ui16_LineNumber)
          || ((ICCFG_cui16_EmbeddedRegLineStart + 1) == ui16_LineNumber)
          ||  (ICCFG_cui_EMBEDDED_STAT_LINE_START_ODD == ui16_LineNumber)
          || ((ICCFG_cui_EMBEDDED_STAT_LINE_START_ODD + 1) == ui16_LineNumber)
          )
        {
          b_CopyLine = b_TRUE;
        }
    
        // Copy also lines that are processed and our buffer is not already full
        if ((b_TRUE == b_ProcessLine) && (ICAT_s_Obj.ui16_CopiedLinesCount < ICAT_s_Obj.ui16_NumLinesToAcquire))
        {
          ICAT_s_Obj.ui16_CopiedLinesCount++;
          b_CopyLine = b_TRUE;
        }
    
        // Copy to line buffer
        if (b_TRUE == b_CopyLine)
        {
          (void)memcpy(ICAT_s_Obj.pui16_RoiBuffer, aui16_LineRawData, ICCFG_cui16_ATEST_COPY_PIXELSPERLINE * IC_cui_BYTES_PER_PIXEL);
    
          // Move to next line in buffer
          ICAT_s_Obj.pui16_RoiBuffer += ICCFG_cui16_ATEST_COPY_PIXELSPERLINE; // PRQA S 0488
        }
      }
    
      // Process only lines contained in the requested ROI
      if (b_TRUE == b_ProcessLine)
      {
        ui16_NumColumns = IC_ui16_RectWidth(ps_Roi);
    
        // Do calculations
        ICAT_v_ColumnwiseAccumulate_u16u32(
            &ICAT_s_Obj.aui32_ColumnPixelsSum[ps_Roi->ui16_x1], // Destination
            &aui16_LineRawData[ps_Roi->ui16_x1],                // Source
            ui16_NumColumns);                                   // Count
        ICAT_s_Obj.ui16_ProcessedLineCount++;
      }
    }
    
    // Set return code for later evaluation
    ERROR_EXIT:
    return e_Ret;
    
    // PRQA S 7002 3
    /*#]*/
}

/*## operation ICAT_v_PrepareNewFrame(uint16) */
static void ICAT_v_PrepareNewFrame(uint16 ui16_TriggerFrame) {
    /*#[ operation ICAT_v_PrepareNewFrame(uint16) */
    // We can only process odd frames, as the IA does not provide ROIs in center of even frame
    ui16_TriggerFrame |= 1;
    
    // Setup next measurement
    IC_v_ZEROMEM(ICAT_s_Obj.aui32_ColumnPixelsSum);
    ICAT_s_Obj.ui16_TriggerFrameNext   = ui16_TriggerFrame;
    ICAT_s_Obj.b_NextTriggerValid      = b_TRUE;
    ICAT_s_Obj.b_LineCalcFinished      = b_FALSE;
    /*#]*/
}

/*## operation ICAT_e_GetStatus() */
IC_E_ATEST_STATUS ICAT_e_GetStatus(void) {
    /*#[ operation ICAT_e_GetStatus() */
    return ICAT_e_Status;
    /*#]*/
}

/*## operation ICAT_b_IsAnalogTestFinished() */
boolean ICAT_b_IsAnalogTestFinished(void) {
    /*#[ operation ICAT_b_IsAnalogTestFinished() */
    return (ICAT_e_STATE_FINISHED == ICAT_e_State) ? b_TRUE : b_FALSE;
    /*#]*/
}

/*## operation ICAT_e_CalcResults(ICAT_S_Results *,IC_E_ANALOG_GAIN,boolean) */
static IC_E_ERROR ICAT_e_CalcResults(ICAT_S_Results * ps_Results, IC_E_ANALOG_GAIN e_Gain, boolean b_FillHighestDevs) {
    /*#[ operation ICAT_e_CalcResults(ICAT_S_Results *,IC_E_ANALOG_GAIN,boolean) */
    IC_E_ERROR e_Ret = IC_e_ERR_OK;
    
    IC_S_Rect_ui16 const * const ps_Roi = &ICAT_s_Obj.ps_Parameters->s_CalcRoi;
    uint32  ui32_x = 0;
    uint32  ui32_Index = 0;
    uint32  ui32_SmallestIndex = 0;
    uint32  ui32_SmallestValue = 0;
    uint32  ui32_RoiWidth = 0;
    uint32  ui32_RoiHeight = 0;
    uint32  ui32_ColMean = 0;
    uint32  ui32_MaxColMean = 0;
    uint32  ui32_MinColMean = 0;
    uint32  ui32_OverallMean = 0;
    uint32  ui32_Deviation = 0;
    uint32  ui32_Value = 0;
    uint32  ui32_ColMeanSum = 0;
    boolean b_SmallerFound = b_FALSE;
    
    // Calc dimensions
    ui32_RoiWidth   = IC_ui16_RectWidth(ps_Roi);
    ui32_RoiHeight  = ICAT_s_Obj.ui16_ProcessedLineCount; //IC_ui16_RectHeight(*ps_Roi);
    
    // Height and width must not be zero
    if ((0 == ui32_RoiHeight) || (0 == ui32_RoiWidth))
    {
      e_Ret = IC_e_ERR_ILLEGAL_DIMENSIONS;
      goto ERROR_EXIT;
    }
    
    // Calculate mean of all linearized and normalized column means
    for (ui32_x = ps_Roi->ui16_x1; ui32_x <= ps_Roi->ui16_x2; ui32_x++)
    {
      ui32_ColMean = ICAT_s_Obj.aui32_ColumnPixelsSum[ui32_x] / ui32_RoiHeight;
      ui32_ColMeanSum += ICAT_ui32_LinearizePixelValue_4x16x((uint16)ui32_ColMean);
    }
    ui32_OverallMean = ui32_ColMeanSum / ui32_RoiWidth;
    ui32_OverallMean = ICAT_ui32_Normalize(ui32_OverallMean, e_Gain);
    
    // Find maximum deviations
    ui32_MaxColMean = TYPEMIN_UI32;
    ui32_MinColMean = TYPEMAX_UI32;
    for (ui32_x = ps_Roi->ui16_x1; ui32_x <= ps_Roi->ui16_x2; ui32_x++)
    {
      ui32_ColMean = ICAT_s_Obj.aui32_ColumnPixelsSum[ui32_x] / ui32_RoiHeight;
      ui32_ColMean = ICAT_ui32_LinearizePixelValue_4x16x((uint16)ui32_ColMean);
      ui32_ColMean = ICAT_ui32_Normalize(ui32_ColMean, e_Gain);
      ui32_Deviation  = (uint32)ABS((sint32)ui32_ColMean - (sint32)ui32_OverallMean);
    
      // Find min/max column mean from current frame
      ui32_MaxColMean = MAX(ui32_MaxColMean, ui32_ColMean);
      ui32_MinColMean = MIN(ui32_MinColMean, ui32_ColMean);
    
      // Find smallest deviation that's smaller than current one and replace it
      if (b_TRUE == b_FillHighestDevs)
      {
        ui32_SmallestValue = TYPEMAX_UI32;
        b_SmallerFound = b_FALSE;
        for (ui32_Index = 0;
            (ui32_Index < IC_ARRLEN(ICAT_s_Obj.s_ExtResults.aui16_HighestDeviationValues)) && (b_FALSE == b_SmallerFound);
             ui32_Index++)
        {
          ui32_Value = ICAT_s_Obj.s_ExtResults.aui16_HighestDeviationValues[ui32_Index];
          if ((ui32_Value < ui32_Deviation) && (ui32_Value < ui32_SmallestValue))
          {
            ui32_SmallestValue = ui32_Value;
            ui32_SmallestIndex = ui32_Index;
            b_SmallerFound     = b_TRUE;
          }
        }
        if (b_TRUE == b_SmallerFound)
        {
          ICAT_s_Obj.s_ExtResults.aui16_HighestDeviationValues   [ui32_SmallestIndex] = IC_ui16_SaturateUi32(ui32_Deviation);
          ICAT_s_Obj.s_ExtResults.aui16_HighestDeviationPositions[ui32_SmallestIndex] = (uint16)ui32_x;
        }
      }
    }
    
    // Calculate relative maximum deviation to total mean. Using the extremes (min/max)
    // column means is sufficient to achieve this.
    ps_Results->f32_DevColmeanMin = ((float32)ui32_MinColMean / (float32)ui32_OverallMean) - IC_cf32_ONE;
    ps_Results->f32_DevColmeanMax = ((float32)ui32_MaxColMean / (float32)ui32_OverallMean) - IC_cf32_ONE;
    ps_Results->f32_DevColmeanAbs = MAX(fABS(ps_Results->f32_DevColmeanMin), fABS(ps_Results->f32_DevColmeanMax));
    
    // Store results
    ps_Results->ui32_ColMeanMax     = ui32_MaxColMean;
    ps_Results->ui32_ColMeanMin     = ui32_MinColMean;
    ps_Results->ui32_TotalMean      = ui32_OverallMean;
    ps_Results->ui8_ProcessedLines  = IC_ui8_SaturateUi16(ICAT_s_Obj.ui16_ProcessedLineCount);
    
    ERROR_EXIT:
    return e_Ret;
    /*#]*/
}

/*## operation ICAT_e_CheckResults() */
static IC_E_ERROR ICAT_e_CheckResults(void) {
    /*#[ operation ICAT_e_CheckResults() */
    IC_E_ERROR       e_Ret              = IC_e_ERR_OK;
    IC_E_ERROR       e_SubRet           = IC_e_ERR_OK;
    float32          f32_OurRatio;
    float32          f32_RefRatio;
    float32          f32_Deviation;
    IC_S_ATestRefValues const * const ps_Ref = &(ICAT_s_Obj.ps_Parameters->s_ReferenceValues);
    IC_S_ATestMaxTols   const * const ps_Tol = &(ICAT_s_Obj.ps_Parameters->s_MaxTols);
    
    // Mark column check as passed. Will be set to failed in ICAT_e_CheckDeviation()
    ICAT_s_Obj.s_ExtResults.b_ColumnCheckPassed = b_TRUE;
    
    // Check results from calculation against expected values (ATV3 1x gain)
    e_SubRet = ICAT_e_CheckDeviation(ICAT_s_Obj.ps_Results_ATV3_1x,
            (float32)ps_Ref->ui16_MeanATV3_1x_LinNorm - (float32)ICAT_s_Obj.si16_Y0_1x,
            ps_Tol->f32_MeanATV3_1xGain,
            ps_Tol->f32_ColMeanATV3_1xGain);
    if (e_SubRet != IC_e_ERR_OK)
    {
      e_Ret = ICERR_HANDLE(IC_e_ERR_ATEST_ATV3_1X, e_SubRet);
    }
    
    // Check results from calculation against expected values (ATV1 1x gain)
    e_SubRet = ICAT_e_CheckDeviation(ICAT_s_Obj.ps_Results_ATV1_1x,
            (float32)ps_Ref->ui16_MeanATV1_1x_LinNorm - (float32)ICAT_s_Obj.si16_Y0_1x,
            ps_Tol->f32_MeanATV1_1xGain,
            ps_Tol->f32_ColMeanATV1_1xGain);
    if (e_SubRet != IC_e_ERR_OK)
    {
      e_Ret = ICERR_HANDLE(IC_e_ERR_ATEST_ATV1_1X, e_SubRet);
    }
    
    // Check results from calculation against expected values (ATV1 2x gain)
    e_SubRet = ICAT_e_CheckDeviation(ICAT_s_Obj.ps_Results_ATV1_2x,
            (float32)ps_Ref->ui16_MeanATV1_2x_LinNorm - (float32)ICAT_s_Obj.si16_Y0_2x,
            ps_Tol->f32_MeanATV1_2xGain,
            ps_Tol->f32_ColMeanATV1_2xGain);
    if (e_SubRet != IC_e_ERR_OK)
    {
      e_Ret = ICERR_HANDLE(IC_e_ERR_ATEST_ATV1_2X, e_SubRet);
    }
    
    // Now check the mean-ratios against the reference mean-ratios (ATV3_1xGain)
    f32_OurRatio  = (float32)ICAT_s_Obj.ps_Results_ATV3_1x->ui32_TotalMean / (float32)ICAT_s_Obj.ps_Results_ATV1_1x->ui32_TotalMean;
    f32_RefRatio  = ((float32)ps_Ref->ui16_MeanATV3_1x_LinNorm - (float32)ICAT_s_Obj.si16_Y0_1x)
                  / ((float32)ps_Ref->ui16_MeanATV1_1x_LinNorm - (float32)ICAT_s_Obj.si16_Y0_1x);
    f32_Deviation = (f32_OurRatio / f32_RefRatio) - IC_cf32_ONE;
    if (fABS(f32_Deviation) > ps_Tol->f32_RatioATV3_1xGain)
    {
      // Suppress 4119 (cast float to int) as this is only optional debug data
      e_Ret = ICERR_HANDLE(IC_e_ERR_ATEST_MEAN_REF_1X, f32_Deviation * ICAT_cf32_FRACT2PERC); // PRQA S 4119
    }
    
    // Now check the mean-ratios against the reference mean-ratios (ATV1_2xGain)
    f32_OurRatio  = (float32)ICAT_s_Obj.ps_Results_ATV1_2x->ui32_TotalMean / (float32)ICAT_s_Obj.ps_Results_ATV1_1x->ui32_TotalMean;
    f32_RefRatio  = ((float32)ps_Ref->ui16_MeanATV1_2x_LinNorm - (float32)ICAT_s_Obj.si16_Y0_2x)
                  / ((float32)ps_Ref->ui16_MeanATV1_1x_LinNorm - (float32)ICAT_s_Obj.si16_Y0_1x);
    f32_Deviation = (f32_OurRatio / f32_RefRatio) - IC_cf32_ONE;
    if (fABS(f32_Deviation) > ps_Tol->f32_RatioATV1_2xGain)
    {
      // Suppress 4119 (cast float to int) as this is only optional debug data
      e_Ret = ICERR_HANDLE(IC_e_ERR_ATEST_MEAN_REF_2X, f32_Deviation * ICAT_cf32_FRACT2PERC); // PRQA S 4119
    }
    
    return e_Ret;
    /*#]*/
}

/*## operation ICAT_e_CheckDeviation(ICAT_S_Results *,float32,float32,float32) */
static IC_E_ERROR ICAT_e_CheckDeviation(ICAT_S_Results * ps_Results, float32 f32_MeanRef, float32 f32_MeanTol, float32 f32_ColTol) {
    /*#[ operation ICAT_e_CheckDeviation(ICAT_S_Results *,float32,float32,float32) */
    IC_E_ERROR    e_Ret          = IC_e_ERR_OK;
    float32       f32_DevMeanVal = IC_cf32_ZERO;
    float32       f32_DevColMin  = IC_cf32_ZERO;
    float32       f32_DevColMax  = IC_cf32_ZERO;
    const float32 f32_TotalMean  = (float32)ps_Results->ui32_TotalMean;
    const float32 f32_MinColMean = (float32)ps_Results->ui32_ColMeanMin;
    const float32 f32_MaxColMean = (float32)ps_Results->ui32_ColMeanMax;
    
    // Check deviation of total mean against reference value
    f32_DevMeanVal = (f32_TotalMean / f32_MeanRef) - IC_cf32_ONE;
    if (fABS(f32_DevMeanVal) > f32_MeanTol)
    {
      // Suppress 4119 (cast float to int) as this is only optional debug data
      e_Ret = ICERR_HANDLE(IC_e_ERR_ATEST_MEAN_TO_REFMEAN, f32_DevMeanVal * ICAT_cf32_FRACT2PERC); // PRQA S 4119
    }
    ps_Results->f32_DevMean = f32_DevMeanVal;
    
    // Check deviation of column means against total mean. Using the extremes (min/max)
    // column means is sufficient to achieve this.
    f32_DevColMin = (f32_MinColMean / f32_TotalMean) - IC_cf32_ONE;
    f32_DevColMax = (f32_MaxColMean / f32_TotalMean) - IC_cf32_ONE;
    if (fABS(f32_DevColMin) > f32_ColTol)
    {
      // Suppress 4119 (cast float to int) as this is only optional debug data
      e_Ret = ICERR_HANDLE(IC_e_ERR_ATEST_MEAN_TO_COLMEAN, f32_DevColMin * ICAT_cf32_FRACT2PERC); // PRQA S 4119
    }
    else if (fABS(f32_DevColMax) > f32_ColTol)
    {
      // Suppress 4119 (cast float to int) as this is only optional debug data
      e_Ret = ICERR_HANDLE(IC_e_ERR_ATEST_MEAN_TO_COLMEAN, f32_DevColMax * ICAT_cf32_FRACT2PERC); // PRQA S 4119
    }
    else
    {
      // No error on column check
      ps_Results->b_ColumnCheckPassed = b_TRUE;
    }
    ps_Results->f32_DevColmeanMin = f32_DevColMin;
    ps_Results->f32_DevColmeanMax = f32_DevColMax;
    
    return e_Ret;
    /*#]*/
}

/*## operation ICAT_v_UpdateExtResults() */
static void ICAT_v_UpdateExtResults(void) {
    /*#[ operation ICAT_v_UpdateExtResults() */
    ICAT_s_Obj.s_ExtResults.e_TestResult         = ICAT_e_Status;
    ICAT_s_Obj.s_ExtResults.ui16_RoiHeight       = IC_ui16_RectHeight(&(ICAT_s_Obj.ps_Parameters->s_CalcRoi));
    ICAT_s_Obj.s_ExtResults.ui16_RoiWidth        = IC_ui16_RectWidth (&(ICAT_s_Obj.ps_Parameters->s_CalcRoi));
    ICAT_s_Obj.s_ExtResults.ui16_RoiStartX       = ICAT_s_Obj.ps_Parameters->s_CalcRoi.ui16_x1;
    ICAT_s_Obj.s_ExtResults.ui16_RoiStartY       = ICAT_s_Obj.ps_Parameters->s_CalcRoi.ui16_y1;
    ICAT_s_Obj.s_ExtResults.ui16_RoiStepsizeY    = ICAT_s_Obj.ps_Parameters->ui16_RoiStepsizeY;
    ICAT_s_Obj.s_ExtResults.ui16_ATV1_mV         = ICAT_s_Obj.ps_Parameters->s_ReferenceValues.ui16_ATV1_mV;
    ICAT_s_Obj.s_ExtResults.ui16_ATV3_mV         = ICAT_s_Obj.ps_Parameters->s_ReferenceValues.ui16_ATV3_mV;
    ICAT_s_Obj.s_ExtResults.ui16_MeanATV1_1xGain = IC_ui16_SaturateUi32(ICAT_s_Obj.ps_Results_ATV1_1x->ui32_TotalMean);
    ICAT_s_Obj.s_ExtResults.ui16_MeanATV1_2xGain = IC_ui16_SaturateUi32(ICAT_s_Obj.ps_Results_ATV1_2x->ui32_TotalMean);
    ICAT_s_Obj.s_ExtResults.ui16_MeanATV3_1xGain = IC_ui16_SaturateUi32(ICAT_s_Obj.ps_Results_ATV3_1x->ui32_TotalMean);
    ICAT_s_Obj.s_ExtResults.b_ColumnCheckPassed  = (ICAT_s_Obj.ps_Results_ATV1_1x->b_ColumnCheckPassed == b_TRUE)
                                                && (ICAT_s_Obj.ps_Results_ATV1_2x->b_ColumnCheckPassed == b_TRUE)
                                                && (ICAT_s_Obj.ps_Results_ATV3_1x->b_ColumnCheckPassed == b_TRUE);
    ICAT_s_Obj.s_ExtResults.ui64_ImagerFuseId = ICAT_s_Obj.ui64_SensorFuseId;
    /*#]*/
}

/*## operation ICAT_ps_GetExtResults() */
IC_S_ATestResults * ICAT_ps_GetExtResults(void) {
    /*#[ operation ICAT_ps_GetExtResults() */
    return &ICAT_s_Obj.s_ExtResults;
    /*#]*/
}

/*## operation ICAT_e_RecalcNormOffsets(const IC_S_ATestRefValues *) */
static IC_E_ERROR ICAT_e_RecalcNormOffsets(const IC_S_ATestRefValues * ps_Ref) {
    /*#[ operation ICAT_e_RecalcNormOffsets(const IC_S_ATestRefValues *) */
    const float32 cf32_GAIN_2x = 2.0f;
    sint32  si32_Y0_1x = 0;
    sint32  si32_Y0_2x = 0;
    float32 f32_m_1x   = IC_cf32_ZERO;
    
    // Give shorter/easier to read naming for our measurement points
    const float32 f32_Y1_1x = (float32)ps_Ref->ui16_MeanATV1_1x_LinNorm;
    const float32 f32_Y1_2x = (float32)ps_Ref->ui16_MeanATV1_2x_LinNorm;
    const float32 f32_Y2_1x = (float32)ps_Ref->ui16_MeanATV3_1x_LinNorm;
    const float32 f32_X1    = (float32)ps_Ref->ui16_ATV1_mV;
    const float32 f32_X2    = (float32)ps_Ref->ui16_ATV3_mV;
    
    // Calculate slope for 1x gain
    f32_m_1x = (f32_Y2_1x - f32_Y1_1x) / (f32_X2 - f32_X1);
    
    // Calculate offset for 1x gain (intersection with Y axis)
    si32_Y0_1x = (sint32)(f32_Y2_1x - (f32_X2 * f32_m_1x)); // PRQA S 4119
    
    // Calculate offset for 2x gain (intersection with Y axis)
    si32_Y0_2x = (sint32)(f32_Y1_2x - (f32_X1 * f32_m_1x * cf32_GAIN_2x)); // PRQA S 4119
    
    // Update data: Saturation is only done to catch overflows
    // QAC seems to have a bug and thinks si32_Y0_* is always positive ... disable 3356
    ICAT_s_Obj.si16_Y0_1x        = IC_si16_SaturateSi32(si32_Y0_1x); // PRQA S 3356
    ICAT_s_Obj.si16_Y0_2x        = IC_si16_SaturateSi32(si32_Y0_2x); // PRQA S 3356
    ICAT_ps_MeasData->si16_Y0_1x = IC_si16_SaturateSi32(si32_Y0_1x); // PRQA S 3356
    ICAT_ps_MeasData->si16_Y0_2x = IC_si16_SaturateSi32(si32_Y0_2x); // PRQA S 3356
    
    return IC_e_ERR_OK;
    /*#]*/
}

/*## operation ICAT_v_ColumnwiseAccumulate_u16u32(uint32 *,const uint16 *,uint32) */
static void ICAT_v_ColumnwiseAccumulate_u16u32(uint32 * pui32_Dst, const uint16 * pui16_Src, uint32 ui32_Count) {
    /*#[ operation ICAT_v_ColumnwiseAccumulate_u16u32(uint32 *,const uint16 *,uint32) */
    // Use Signal Processing Extension intrinsics if available
    #if (__SPE__ == 1)
    // QAC has many problems with SPE intrinsics, so disable error processing here
    //
    register __ev64_opaque__ ui64_Src;
    register __ev64_opaque__ ui64_Dst;
    register __ev64_opaque__ * pevu64_Dst;
    const uint32 cui32_PIXELS_PER_LOOP = 2;
    uint32 *pui32_Src;
    
    // Do pointer alignment checks, as needed by SIMD code
    //     Destination must be 8 byte aligned!
    //     Source      must be 4 byte aligned!
    //
    // Suppress QAC messages as we need this for alignment checks:
    //   PRQA S 0306,3120 ALIGN_CHECK
    //
    if (((uint32)pui32_Dst & 7) != 0)
    {
      (void)ICERR_HANDLE(IC_e_ERR_SOURCECODE_ERROR, 0);
    }
    else if (((uint32)pui16_Src & 3) != 0)
    {
      (void)ICERR_HANDLE(IC_e_ERR_SOURCECODE_ERROR, 0);
    }
    else // PRQA L:ALIGN_CHECK
    {
      // QAC has many issues with the following SPE optimized code, as SPE intrinsics are multi-instruction macros.
      // So suppress messages here:
      //
      //   PRQA S 0310,0311,3305,2205,0489,0510,1021,3112,3196,3205,3220,3321,3440,3454,3430,3198,3203,3401 SIMD_LOOP
      //
      pevu64_Dst = (__ev64_opaque__*)pui32_Dst;
      pui32_Src = (uint32*)pui16_Src;
      ui32_Count /= cui32_PIXELS_PER_LOOP;
      while (ui32_Count > 0)
      {
        ui32_Count--;
        ui64_Src = __ev_lwhou(pui32_Src, 0);      // Load two 16-bit pixels into 64-bit register (zero extend)
        pui32_Src++;                              // Increment source address (jump two pixels)
        ui64_Dst = __ev_ldd (pevu64_Dst, 0);      // Load old sum
        ui64_Dst = __ev_addw(ui64_Dst, ui64_Src); // 32-bit Vector Add
        *pevu64_Dst = ui64_Dst;                   // Store to destination
        pevu64_Dst++;                             // Increment destination address (jump two result-values)
      }
      // PRQA L:SIMD_LOOP
    }
    #else
    uint32 *pui32_LastDst = pui32_Dst + ui32_Count - 1;
    while (pui32_Dst <= pui32_LastDst)
    {
      *pui32_Dst++ += *pui16_Src++;
    }
    #endif
    /*#]*/
}

/*## operation ICAT_ui32_Normalize(uint32,IC_E_ANALOG_GAIN) */
static uint32 ICAT_ui32_Normalize(uint32 ui32_Value, IC_E_ANALOG_GAIN e_Gain) {
    /*#[ operation ICAT_ui32_Normalize(uint32,IC_E_ANALOG_GAIN) */
    sint32 si32_Ret = 0;
    
    // Normalize value depending on current gain
    if (IC_e_ANALOG_GAIN_2X == e_Gain)
    {
      si32_Ret = (sint32)ui32_Value - (sint32)ICAT_s_Obj.si16_Y0_2x;
    }
    else
    {
      si32_Ret = (sint32)ui32_Value - (sint32)ICAT_s_Obj.si16_Y0_1x;
    }
    
    // Clap value to zero
    if (si32_Ret < 0)
    {
      si32_Ret = 0;
    }
    
    return (uint32)si32_Ret;
    /*#]*/
}

/*## operation ICAT_ui32_LinearizePixelValue_4x16x(uint16) */
static uint32 ICAT_ui32_LinearizePixelValue_4x16x(uint16 ui16_PixelValue) {
    /*#[ operation ICAT_ui32_LinearizePixelValue_4x16x(uint16) */
    // NOTE: This linearization function only works when the imager is put into analog test mode!
    //       This is due to the fact that the integration times have no effect on the output value,
    //       but the imager executes companding as if this would be the case. See analog test
    //       specification chapter "4.1 Linearization of Data" for details.
    //
    // Formulas are defined in analog test specification, so there are some "anonymous" magic numbers.
    // Suppress QAC message for magic numbers (3120) here:
    //
    //   PRQA S 3120 18
    //
    uint32 ui32_OutValue = 0;
    
    if (ui16_PixelValue < 2048)
    {
      ui32_OutValue = ui16_PixelValue;
    }
    else if (ui16_PixelValue <= 2068)
    {
      ui32_OutValue = 2048 + (((((((uint32)ui16_PixelValue) - 2048) * 4) * 16) * 17) / 16);
    }
    else if (ui16_PixelValue <= 3040)
    {
      ui32_OutValue = 3408 + ((((uint32)ui16_PixelValue) - 2068) * 4);
    }
    else
    {
      ui32_OutValue = 3408 + ((((((uint32)ui16_PixelValue) - 2068) * 4) * 16) / 17); // yes, 16 and 17 swapped here!
    }
    return ui32_OutValue;
    /*#]*/
}


/*#[ ignore */

#ifdef __cplusplus
}
#endif


#endif /* (IC_ANALOG_TEST_ENABLED == 1) */
/*#]*/


/*********************************************************************
	File Path: ..\..\..\04_Engineering\01_Source_Code\Algo\ic\ic_atest.c
*********************************************************************/
