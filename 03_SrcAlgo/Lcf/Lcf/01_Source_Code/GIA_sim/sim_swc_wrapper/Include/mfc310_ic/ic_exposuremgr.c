//* **********************************************************************
//  COMPANY:         $CompanyInfo: CONFIDENTIAL AND PROPRIETARY PROPERTY OF CONTINENTAL AG , A.D.C. GmbH  -  ALL RIGHTS RESERVED $
//  
//  PROJECT:         MFC30x_MCU
//  CPU:             MPC5675K
//  
//  PACKAGE:         $Source: ic_exposuremgr.c $ $Revision: 1.1 $
//  MKS Date:        $Date: 2021/12/13 17:25:53CET $
//  
//  RHAPSODY:        7.5.3
//  COMPONENT:       IC
//  CONFIGURATION:   DefaultConfig
//  MODEL ELEMENT:   ic_exposuremgr
//  MODULNAME:       ..\..\..\04_Engineering\01_Source_Code\Algo\ic\ic_exposuremgr.c
//  LOGIN:           uidt3974  
//  
//  The IC Exposure Manager (ICEXPMG) and it's submodule "IC Exposure" (ICEXP) handles
//  everything related to Image Exposure. This includes calculation of new exposure
//  settings and forwarding them to the Imager Driver.
//  
//  The Exposure Manager holds two instances of "IC Exposure", which implements/does the
//  algorithmic/calculation part. Each instance is responsable for a specific frame-type
//  (even/odd). The ICEXP forwards input data to the particular ICEXP instance, calls its
//  execute function, and forwards outputs to the Imager Driver.
//  
//  =======================================================================================
//  |                                EXPOSURE CONTROL MODES                               |
//  =======================================================================================
//  There are two operation modes for the Exposure Control Manager:
//  
//  Single Exposure Mode:
//      Single Exposure Mode means that both frames (even and odd) are controlled using a
//      single Exposure Control instance, which is executed only when the 'Master' frame
//      (IC_ce_MASTER_FRAMETYPE) is being processed. Both frame types will have same
//      exposure related control settings.
//  
//  Dual Exposure Mode:
//      In Dual Exposure Mode we use two Exposure Control instances, one for each frame type
//      (even/odd). They are handled completly independent and also have different control
//      parameters.
//  
//  The normal operation mode is 'Dual Exposure', but it will be changed temporary to 'Single
//  Exposure' when forcing fixed exposure settings by calling ICEXPMG_e_SetTemporaryFixedExposureT1().
//  
//  =======================================================================================
//  |                              SETTING FIXED EXPOSURE TIME                            |
//  =======================================================================================
//  Exposure time can be fixed to a specific value for a specific time by calling function
//  ICEXPMG_e_SetTemporaryFixedExposureT1(). During that time, the Exposure Control parameters
//  are changed to reflect fixed values, so no regulation is done within this time. After
//  time expires, the old settings are restored.
//  
//  This can be used in production, where some tests/calibration routines expect the imager
//  to have specific exposure settings.
//  
//  =======================================================================================
//  |                                 FORCING A DCG CHANGE                                |
//  =======================================================================================
//  The imagers used in the MFC3xx project have a feature called 'column FPN correction' (FPN=fixed
//  pattern noise). This corrects column noise resulting from a fixed column offset. However,
//  this correction drifts over temperature, so it has to be repeated when the imager temperature
//  changes significantly. After image streaming is enabled, the imager can only be forced to
//  do a 'column FPN correction' by switching the DCG.
//  
//  This is where forced DCG change comes into place. It forces a change of the DCG, regardless
//  of what the Exposure Control algo instances would usually do with the input data. To achieve
//  this, the ICEXP module has a function to set a fixed DCG value via
//  ICEXP_v_OverwriteDcgOutputCompensated(). This is called on instance B with the opposite
//  DCG to that DCG, which results from the previous execution of instance A. This forces a
//  change of the DCG in the next frame-type B.
//  
//  ==========================================================================================
//  The following QAC messages are suppressed for this module:
//  
//    Error handling is emulated by using an exclusive label ERROR_EXIT, which is entered
//    via GOTO on error. Code using this type of error handling is much easier to read,
//    as no nested if() statements are required. Suppress QAC warnings related to this
//    functionality:
//  
//    PRQA S 2001,2015,7003 EOF
//  
//  AUTHOR:          $Author: Wang, David (Wangd3) $
//! CREATION DATE:   Mon, 6, Aug 2012  3:02 W. Europe Daylight Time PM 
//**************************************************************************** */

/*## auto_generated */
#include "ic_exposuremgr.h"
/*## dependency ic_cfg_exposure */
#include "ic_cfg_exposure.h"
/*## dependency ic_common */
#include "ic_common.h"
/*## dependency ic_driver */
#include "ic_driver.h"
/*## dependency ic_errmanager */
#include "ic_errmanager.h"
/*## dependency ic_exposure */
#include "ic_exposure.h"
/*## package Ic_Pkg */

/*## class TopLevel::ic_exposuremgr */


/*#[ ignore */
#ifdef __cplusplus
extern "C"
{
#endif

/*#]*/


//  Stores new image sensor settings for the cycle (of a specific frame-type). This settings
//  have to be written to the imager.
/*## type ICEXPMG_S_SensValues */
typedef struct ICEXPMG_S_SensValues {
    //  Description:   Value of Intraday State flag
    //  Range:         (enum)
    //  Resolution:    none
    //  Unit:          none
    IC_E_INTRADAY_STATE e_newIntradayState;		/*## attribute e_newIntradayState */
    //  Description:   Setting of dual conversion gain (DCG)
    //  Range:         (enum)
    //  Resolution:    none
    //  Unit:          none
    IC_E_DCG_STATE e_newDCGState;		/*## attribute e_newDCGState */
    //  Description:   New digital gain which has to be written to the imager
    //  Range:         none
    //  Resolution:    none
    //  Unit:          none
    float32 f32_newDigitalGain;		/*## attribute f32_newDigitalGain */
    //  Description:   Image integration time T1
    //  Range:         none
    //  Resolution:    1
    //  Unit:          lines
    uint16 ui16_newExposureTimeLines;		/*## attribute ui16_newExposureTimeLines */
    //  Description:   Image integration time T1
    //  Range:         none
    //  Resolution:    1
    //  Unit:          us
    uint16 ui16_newExposureTime;		/*## attribute ui16_newExposureTime */
    //  Description:   Integration time ratio R1=T1/T2
    //  Range:         {4,16}
    //  Resolution:    1
    //  Unit:          none
    uint16 ui16_newSlopeR1;		/*## attribute ui16_newSlopeR1 */
    //  Description:   Integration time ratio R2=T2/T3
    //  Range:         {4,16}
    //  Resolution:    1
    //  Unit:          none
    uint16 ui16_newSlopeR2;		/*## attribute ui16_newSlopeR2 */
} ICEXPMG_S_SensValues;

//  Name of this module, required for calls to ICERR_HANDLE().
//  
//  Character string is only used for debugging & recording analysis, so suppress QAC warnings:
//  PRQA S 5013,3625 3
/*## attribute pch_ModuleName */
static const char * const pch_ModuleName = "EXPMG";

//  Stores the temporary input for the current execution cycle of the exposure control module.
//  Array stores data for all image types (even / odd).
/*## attribute ICEXPMG_as_ICInput */
static ICEXP_S_Input ICEXPMG_as_ICInput[IC_cui16_NumFrameTypes];

//  Instance objects for Imager Exposure Control Module (even and odd frame)
/*## attribute ICEXPMG_as_ICObjects */
static ICEXP_S_Obj ICEXPMG_as_ICObjects[IC_cui16_NumFrameTypes];

//  Stores the control parameters for the Exposure Control (even and odd frame)
/*## attribute ICEXPMG_as_ICSettings */
static ICEXP_S_Settings ICEXPMG_as_ICSettings[IC_cui16_NumFrameTypes];

//  Stores the imager configuration for the next frame (separate for even/odd)
/*## attribute ICEXPMG_as_NextFrameValues */
static ICEXPMG_S_SensValues ICEXPMG_as_NextFrameValues[IC_cui16_NumFrameTypes];

//  Flag stores current mode of the Exposure Control Manager. See 'EXPOSURE CONTROL MODES' in module description.
//  
//  b_FALSE: The ICEXPMG is running in single exposure mode.
//  b_TRUE:  The ICEXPMG is running in dual exposure mode.
/*## attribute ICEXPMG_b_DualExposureControl */
static boolean ICEXPMG_b_DualExposureControl = b_TRUE;

//  Backup variable for flag 'ICEXPMG_b_DualExposureControl'. This is used as temporary storage
//  for the flag.
/*## attribute ICEXPMG_b_DualExposureControlBkup */
static boolean ICEXPMG_b_DualExposureControlBkup = b_TRUE;

//  State of DCG in previous frame (n-1)
//  
//  This is intended to be on file scope, so suppress QAC warning:
//  PRQA S 3218 2
/*## attribute ICEXPMG_e_PrevDcg */
static IC_E_DCG_STATE ICEXPMG_e_PrevDcg = IC_e_DCG_LOW;

//  MTS Measurement data struct for this module, will will be sent to MTS every cycle.
//  
//  Structure data is cyclically sent to MTS by calling module, so suppress QAC warning "written but not used":
//  PRQA S 3229 2
/*## attribute ICEXPMG_ps_MeasData */
static ICEXPMG_S_MeasData * ICEXPMG_ps_MeasData = NULL;

//  Measurement data for exposure control (odd frame type)
/*## attribute ICEXPMG_s_ExposureMeasOdd */
static ICEXP_S_MeasData ICEXPMG_s_ExposureMeasOdd = { 0 } /*!< @vaddr: 0x200b4000 @vname: IC_OddFrame @cycleid: imagercontrol_cycle_id */;

//  Measurement data for exposure control (even frame type)
/*## attribute ICEXPMG_s_ExposureMeasEven */
#if (IC_EXPOSURE_EVEN_MEASDATA == 1)
static ICEXP_S_MeasData ICEXPMG_s_ExposureMeasEven = { 0 } /*!< @vaddr: 0x200b0000 @vname: IC_EvenFrame @cycleid: imagercontrol_cycle_id */;
#endif

//  Used to temporary save the "normal" ICEXP control parameters, when setting a fixed exposure time with
//  ICA_e_SetTemporaryFixedExposure(). Settings will be restored when the Exposure Control Manager will go
//  back to normal operation.
/*## attribute ICEXPMG_s_ICSettingsBackup */
static ICEXP_S_Settings ICEXPMG_s_ICSettingsBackup;

//  Pointers to MTS measurement data for all frame-types, which are written by the ICEXP
//  object instances.
//  
//  This is intended to be on file scope, so suppress QAC warning:
//  PRQA S 3218 2
/*## attribute ICEXPMG_pas_ExposureMeasData */
static ICEXP_S_MeasData * const ICEXPMG_pas_ExposureMeasData[IC_cui16_NumFrameTypes] = {
#if (IC_EXPOSURE_EVEN_MEASDATA == 1)
        &ICEXPMG_s_ExposureMeasEven, &ICEXPMG_s_ExposureMeasOdd
#else
        NULL, &ICEXPMG_s_ExposureMeasOdd
#endif
};

//  Countdown framecounter for disabling externally set fixed exposure times.
/*## attribute ICEXPMG_ui32_ICFixedExposureDisableFrameCnt */
static uint32 ICEXPMG_ui32_ICFixedExposureDisableFrameCnt = 0;

/*## operation ICEXPMG_e_Exec(const IC_E_FRAMETYPE,IC_S_ImageDataContainer const * const,IC_S_Roi const * const,const boolean) */
IC_E_ERROR ICEXPMG_e_Exec(const IC_E_FRAMETYPE e_FrameType, IC_S_ImageDataContainer const * const ps_ImageData, IC_S_Roi const * const ps_IcRoi, const boolean b_ForceDcgChange) {
    /*#[ operation ICEXPMG_e_Exec(const IC_E_FRAMETYPE,IC_S_ImageDataContainer const * const,IC_S_Roi const * const,const boolean) */
    IC_E_ERROR                    e_Ret                   = IC_e_ERR_OK;
    ICEXP_E_ERROR                 e_ExpRet;
    ICEXP_S_Obj           * const ps_IC                   = &ICEXPMG_as_ICObjects[e_FrameType];
    ICEXP_S_Input         * const ps_ICInput              = &ICEXPMG_as_ICInput[e_FrameType];
    ICEXPMG_S_SensValues  * const ps_NextFrameValuesThis  = &ICEXPMG_as_NextFrameValues[e_FrameType];
    ICEXPMG_S_SensValues  *       ps_NextFrameValuesCmd   = &ICEXPMG_as_NextFrameValues[e_FrameType];
    ICEXP_S_Output        *       ps_ICOutput             = NULL;
    IC_S_EmbeddedRegData  const * ps_EmbeddedDat          = NULL;
    IC_S_EmbeddedStatData const * ps_StatisticsDat        = NULL;
    IC_E_INTEGR_RATIO             e_R1;
    IC_E_INTEGR_RATIO             e_R2;
    uint32                        ui32_ICRoiNumPixelsUsed = 0;
    
    // Nullpointer checks
    if ((NULL == ps_ImageData) || (NULL == ps_IcRoi))
    {
      e_Ret = ICERR_HANDLE(IC_e_ERR_NULLPOINTER, 0);
      goto ERROR_EXIT;
    }
    else
    {
      // Setup pointers
      ps_EmbeddedDat   = &ps_ImageData->s_EmbeddedData;
      ps_StatisticsDat = &ps_ImageData->s_StatisticsData;
    
      // Evaluate current fixed-exposure-expiration-counter and go back to normal mode if expired
      if (ICEXPMG_ui32_ICFixedExposureDisableFrameCnt > 0)
      {
        if (1 == ICEXPMG_ui32_ICFixedExposureDisableFrameCnt)
        {
          ICEXPMG_v_ResetTemporaryFixedExposureT1();
          ICEXPMG_ui32_ICFixedExposureDisableFrameCnt = 0;
        }
        else
        {
          ICEXPMG_ui32_ICFixedExposureDisableFrameCnt--;
        }
      }
    
      // Setup input for IC
      ps_ICInput->f32_BrightnessCdqm  = 0.0f; /* Unused here */ // PRQA S 3121
      ps_ICInput->f32_PercLowEnd      = ps_StatisticsDat->f32_PercLowEnd;
      ps_ICInput->ps_HistogramData    = &ps_ImageData->s_HistogramData;
      ps_ICInput->e_DCGState          = ps_EmbeddedDat->e_DcgState;
      ps_ICInput->ui16_ExposureTimeUs = ps_EmbeddedDat->ui16_ExposureTimeT1_us;
      ps_ICInput->ui32_HistEndMeanLow = ps_StatisticsDat->ui32_LowEndMean;
      ps_ICInput->ui32_LumaMean       = ps_StatisticsDat->ui32_LumaMean;
      e_ExpRet = ICEXP_e_SetControlInput(ps_IC, ps_ICInput);
      if (ICEXP_e_ERR_OK != e_ExpRet)
      {
        e_Ret = ICERR_HANDLE(IC_e_ERR_IC_INPUT, 0);
        goto ERROR_EXIT;
      }
    
      // Run IC
      e_ExpRet = ICEXP_e_RunControl(ps_IC, &ps_ICOutput);
      if (ICEXP_e_ERR_OK != e_ExpRet)
      {
        e_Ret = ICERR_HANDLE(IC_e_ERR_IC_RUN, 0);
        goto ERROR_EXIT;
      }
    
      // Check output pointer
      if (NULL == ps_ICOutput)
      {
        e_Ret = ICERR_HANDLE(IC_e_ERR_NULLPOINTER, 0);
        goto ERROR_EXIT;
      }
    
      // Are we forced to introduce a change of the DCG?
      if (b_TRUE == b_ForceDcgChange)
      {
        if (IC_e_DCG_LOW == ICEXPMG_e_PrevDcg)
        {
          ICEXP_v_OverwriteDcgOutputCompensated(ps_IC, IC_e_DCG_HIGH);
        }
        else
        {
          ICEXP_v_OverwriteDcgOutputCompensated(ps_IC, IC_e_DCG_LOW);
        }
      }
    
      // Check if histogram was ok by looking if it has the expected number of total pixels in sum.
      // Due to the bayer-pattern only the Gr-Pixels are used (every fourth), so divide by four:
      ui32_ICRoiNumPixelsUsed = (ps_IcRoi->ui16_Height * ps_IcRoi->ui16_Width) / ICCFG_cui16_NUM_COLOR_PLANES;
      if (ps_ICOutput->ui32_NumHistogramPixels != ui32_ICRoiNumPixelsUsed)
      {
        e_Ret = ICERR_HANDLE(IC_e_ERR_HISTOGRAM_PIXELCOUNT_MISMATCH, ps_ICOutput->ui32_NumHistogramPixels);
      }
    
      #if (IC_RAMPING_EXPOSURE_TEST == 1)
      #if 0
      ps_ICOutput->ui16_ExposureTimeUs = MAX(((ui16_FrameNum << 1) & 0x1FF) * 37, 260);
      #else
      ui16_FrameNum = ps_ImageData->s_EmbeddedData.ui16_FrameCounter;
      if ((ui16_FrameNum & 0xFF) < 128)
      {
        ps_ICOutput->ui16_ExposureTimeUs = MAX((ui16_FrameNum & 0xFF) * 18, 260);
      }
      else
      {
        ps_ICOutput->ui16_ExposureTimeUs = ((ui16_FrameNum & 0xFF) - 128) * 37 * 4 + 2304;
      }
      #endif
      ps_ICOutput->e_DCGState          = (ui16_FrameNum & 0x100) ? 1 : 0;
      ps_ICOutput->ui16_SlopeRatioR1   = (ui16_FrameNum & 0x200) ? 4 : 16;
      ps_ICOutput->ui16_SlopeRatioR2   = 16;
      if (ps_ICOutput->ui16_SlopeRatioR1 == 16) {
        ps_ICOutput->f32_DigitalGain = 1.0f;
      } else if (ps_ICOutput->ui16_SlopeRatioR1 == 4) {
        ps_ICOutput->f32_DigitalGain = 0.25f;
      }
      #endif
    
      // Store values for next frame
      ps_NextFrameValuesThis->ui16_newExposureTime        = ps_ICOutput->ui16_ExposureTimeUs;
      ps_NextFrameValuesThis->ui16_newExposureTimeLines   = IMGDRV_ui16_UsToLines(ps_ICOutput->ui16_ExposureTimeUs);
      ps_NextFrameValuesThis->e_newDCGState               = ps_ICOutput->e_DCGState;
      ps_NextFrameValuesThis->e_newIntradayState          = ps_ICOutput->e_IntradayState;
      ps_NextFrameValuesThis->f32_newDigitalGain          = ps_ICOutput->f32_DigitalGain;
      ps_NextFrameValuesThis->ui16_newSlopeR1             = ps_ICOutput->ui16_SlopeRatioR1;
      ps_NextFrameValuesThis->ui16_newSlopeR2             = ps_ICOutput->ui16_SlopeRatioR2;
    
      // If we are in single exposure mode, just replace the "next frame values" pointer by the frame
      // type which shall be used for single exposure:
      if (b_FALSE == ICEXPMG_b_DualExposureControl)
      {
        ps_NextFrameValuesCmd = &ICEXPMG_as_NextFrameValues[IC_ce_MASTER_FRAMETYPE];
      }
    
      // Forward output to sensor-driver
      e_R1 = IC_e_SlopeRatioIntToEnum(ps_NextFrameValuesCmd->ui16_newSlopeR1);
      e_R2 = IC_e_SlopeRatioIntToEnum(ps_NextFrameValuesCmd->ui16_newSlopeR2);
      IMGDRV_v_SetIntegrationTimeRatios(e_R1, e_R2);
      IMGDRV_v_SetDCG(ps_NextFrameValuesCmd->e_newDCGState);
      IMGDRV_v_SetDigitalGain(ps_NextFrameValuesCmd->f32_newDigitalGain);
      if (IMGDRV_e_SetExposureTime(ps_NextFrameValuesCmd->ui16_newExposureTime) != IC_e_ERR_OK)
      {
        // Something went wrong
        e_Ret = ICERR_HANDLE(IC_e_ERR_ICEXPMG_SETTODRIVER, 0);
        goto ERROR_EXIT;
      }
    
      // Housekeeping
      ICEXPMG_e_PrevDcg = ps_ICOutput->e_DCGState;
    
      // Measurement data. Pointer passed on init, so suppress QAC warning 'possible nullpointer':
      // PRQA S 0506 2
      ICEXPMG_ps_MeasData->b_DualExposureEnabled = ICEXPMG_b_DualExposureControl;
      ICEXPMG_ps_MeasData->ui32_FixedExposureModeFramesLeft = ICEXPMG_ui32_ICFixedExposureDisableFrameCnt;
    }
    
    ERROR_EXIT:
    return e_Ret;
    
    // PRQA S 7002 3
    /*#]*/
}

/*## operation ICEXPMG_e_Init(ICEXPMG_S_MeasData * const,const float32) */
IC_E_ERROR ICEXPMG_e_Init(ICEXPMG_S_MeasData * const ps_MeasDataIn, const float32 f32_DcgFactor) {
    /*#[ operation ICEXPMG_e_Init(ICEXPMG_S_MeasData * const,const float32) */
    IC_E_ERROR e_Ret = IC_e_ERR_OK;
    ICEXP_E_ERROR e_IC_Ret = ICEXP_e_ERR_OK;
    
    // Take over measurement data struct pointer
    ICEXPMG_ps_MeasData = ps_MeasDataIn;
    
    // Zero some private structs
    IC_v_ZEROMEM(ICEXPMG_as_ICObjects);
    IC_v_ZEROMEM(ICEXPMG_as_ICInput);
    IC_v_ZEROMEM(ICEXPMG_as_ICSettings);
    IC_v_ZEROMEM(ICEXPMG_as_NextFrameValues);
    IC_v_ZEROMEM(ICEXPMG_s_ExposureMeasOdd);
    #if (IC_EXPOSURE_EVEN_MEASDATA == 1)
    IC_v_ZEROMEM(ICEXPMG_s_ExposureMeasEven);
    #endif
    
    // Get exposure settings from configuration
    ICCFG_v_GetExposureSettings(&ICEXPMG_as_ICSettings[IC_e_FRAMETYPE_EVEN], IC_e_FRAMETYPE_EVEN);
    ICCFG_v_GetExposureSettings(&ICEXPMG_as_ICSettings[IC_e_FRAMETYPE_ODD ], IC_e_FRAMETYPE_ODD);
    
    // Take over DCG factor for specific imager
    ICEXPMG_as_ICSettings[IC_e_FRAMETYPE_EVEN].f32_DCGGainFactor = f32_DcgFactor;
    ICEXPMG_as_ICSettings[IC_e_FRAMETYPE_ODD ].f32_DCGGainFactor = f32_DcgFactor;
    
    // Initialize exposure control objects
    ICEXP_v_Init(&ICEXPMG_as_ICObjects[IC_e_FRAMETYPE_EVEN]);
    ICEXP_v_Init(&ICEXPMG_as_ICObjects[IC_e_FRAMETYPE_ODD]);
    
    // Set parameters to IC objects
    e_IC_Ret = ICEXP_e_SetControlParameters(&ICEXPMG_as_ICObjects[IC_e_FRAMETYPE_EVEN], &ICEXPMG_as_ICSettings[IC_e_FRAMETYPE_EVEN]);
    if (ICEXP_e_ERR_OK != e_IC_Ret)
    {
      e_Ret = IC_e_ERR_INIT_ICPARAMETERS;
      goto ERROR_EXIT;
    }
    e_IC_Ret = ICEXP_e_SetControlParameters(&ICEXPMG_as_ICObjects[IC_e_FRAMETYPE_ODD], &ICEXPMG_as_ICSettings[IC_e_FRAMETYPE_ODD]);
    if (ICEXP_e_ERR_OK != e_IC_Ret)
    {
      e_Ret = IC_e_ERR_INIT_ICPARAMETERS;
      goto ERROR_EXIT;
    }
    
    ERROR_EXIT:
    return e_Ret;
    /*#]*/
}

/*## operation ICEXPMG_e_SetTemporaryFixedExposureT1(const uint16,const uint32) */
IC_E_ERROR ICEXPMG_e_SetTemporaryFixedExposureT1(const uint16 ui16_T1_us, const uint32 ui32_NumFramesPersistence) {
    /*#[ operation ICEXPMG_e_SetTemporaryFixedExposureT1(const uint16,const uint32) */
    const uint16 cui16_FIXED_EXPOSURE_R1 = 16;
    const uint16 cui16_FIXED_EXPOSURE_R2 = 16;
    
    // Backup old settings
    ICEXPMG_s_ICSettingsBackup = ICEXPMG_as_ICSettings[IC_ce_MASTER_FRAMETYPE];
    ICEXPMG_b_DualExposureControlBkup = ICEXPMG_b_DualExposureControl;
    
    // Set fixed exposure
    ICEXPMG_as_ICSettings[IC_ce_MASTER_FRAMETYPE].e_SlopeSwitchingMode        = ICEXP_e_SLOPE_SWITCH_FIXED;
    ICEXPMG_as_ICSettings[IC_ce_MASTER_FRAMETYPE].ui16_MaxExposureT1us        = ui16_T1_us;
    ICEXPMG_as_ICSettings[IC_ce_MASTER_FRAMETYPE].ui16_MinExposureT1us        = ui16_T1_us;
    ICEXPMG_as_ICSettings[IC_ce_MASTER_FRAMETYPE].ui16_IntegrationTimeRatioR1 = cui16_FIXED_EXPOSURE_R1;
    ICEXPMG_as_ICSettings[IC_ce_MASTER_FRAMETYPE].ui16_IntegrationTimeRatioR2 = cui16_FIXED_EXPOSURE_R2;
    ICEXPMG_as_ICSettings[IC_ce_MASTER_FRAMETYPE].e_DCGControl                = ICEXP_e_DCGMODE_ALWAYS_LOW;
    ICEXPMG_b_DualExposureControl = b_FALSE;
    
    // Set counter for going back to normal mode
    ICEXPMG_ui32_ICFixedExposureDisableFrameCnt = ui32_NumFramesPersistence;
    return IC_e_ERR_OK;
    /*#]*/
}

/*## operation ICEXPMG_v_GetExposureMeasData(void * * const,uint32 * const,const IC_E_FRAMETYPE) */
void ICEXPMG_v_GetExposureMeasData(void * * const ppv_Data, uint32 * const pui32_Size, const IC_E_FRAMETYPE e_FrameType) {
    /*#[ operation ICEXPMG_v_GetExposureMeasData(void * * const,uint32 * const,const IC_E_FRAMETYPE) */
    ICEXP_E_ERROR e_ExpRet = ICEXP_e_ERR_OK;
    ICEXP_S_MeasData * const ps_MeasDat = ICEXPMG_pas_ExposureMeasData[e_FrameType];
    
    if ((NULL != ppv_Data) && (NULL != pui32_Size))
    {
      e_ExpRet = ICEXP_e_MeasFreezeBuffer(&ICEXPMG_as_ICObjects[e_FrameType], ps_MeasDat);
      if (ICEXP_e_ERR_OK != e_ExpRet)
      {
        *ppv_Data = NULL;
        *pui32_Size = 0;
        (void)ICERR_HANDLE(IC_e_ERR_GETEXPMEASFREEZE, e_ExpRet);
      }
      else
      {
        *ppv_Data = ps_MeasDat;
        *pui32_Size = (uint32)sizeof(ICEXP_S_MeasData);
      }
    }
    /*#]*/
}

/*## operation ICEXPMG_v_GetResults(ICEXPMG_S_Results * const,const IC_E_FRAMETYPE) */
void ICEXPMG_v_GetResults(ICEXPMG_S_Results * const ps_Results, const IC_E_FRAMETYPE e_FrameType) {
    /*#[ operation ICEXPMG_v_GetResults(ICEXPMG_S_Results * const,const IC_E_FRAMETYPE) */
    if (ps_Results != NULL)
    {
      ps_Results->e_IntradaystateLast   = ICEXPMG_as_ICObjects[e_FrameType].s_EntryState.e_IntradayState;
      ps_Results->e_IntradaystateNext   = ICEXPMG_as_ICObjects[e_FrameType].s_Output.e_IntradayState;
      ps_Results->ui32_LumaMeanWeighted = ICEXPMG_as_ICObjects[e_FrameType].s_Output.ui32_MeanWeighted;
      ps_Results->b_DualExposureEnabled = ICEXPMG_b_DualExposureControl;
    }
    /*#]*/
}

/*## operation ICEXPMG_v_ResetTemporaryFixedExposureT1() */
void ICEXPMG_v_ResetTemporaryFixedExposureT1(void) {
    /*#[ operation ICEXPMG_v_ResetTemporaryFixedExposureT1() */
    ICEXPMG_as_ICSettings[IC_ce_MASTER_FRAMETYPE] = ICEXPMG_s_ICSettingsBackup;
    ICEXPMG_b_DualExposureControl = ICEXPMG_b_DualExposureControlBkup;
    ICEXPMG_ui32_ICFixedExposureDisableFrameCnt = 0;
    /*#]*/
}

/*## operation ICEXPMG_v_SimInjectState(void *,IC_E_FRAMETYPE) */
#if (IC_COMPILE_FOR_MTS == 1)
void ICEXPMG_v_SimInjectState(void * ps_State, IC_E_FRAMETYPE e_FrameType) {
    /*#[ operation ICEXPMG_v_SimInjectState(void *,IC_E_FRAMETYPE) */
    ICEXPMG_as_ICObjects[e_FrameType].s_State = *((ICEXP_S_State*)ps_State);
    /*#]*/
}
#endif


/*#[ ignore */

#ifdef __cplusplus
}
#endif

/*#]*/


/*********************************************************************
	File Path: ..\..\..\04_Engineering\01_Source_Code\Algo\ic\ic_exposuremgr.c
*********************************************************************/
