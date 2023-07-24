//* **********************************************************************
//  COMPANY:         $CompanyInfo: CONFIDENTIAL AND PROPRIETARY PROPERTY OF CONTINENTAL AG , A.D.C. GmbH  -  ALL RIGHTS RESERVED $
//  
//  PROJECT:         MFC30x_MCU
//  CPU:             MPC5675K
//  
//  PACKAGE:         $Source: ic_roi.c $ $Revision: 1.1 $
//  MKS Date:        $Date: 2021/12/13 17:26:03CET $
//  
//  RHAPSODY:        7.5.3
//  COMPONENT:       IC
//  CONFIGURATION:   DefaultConfig
//  MODEL ELEMENT:   ic_roi
//  MODULNAME:       ..\..\..\04_Engineering\01_Source_Code\Algo\ic\ic_roi.c
//  LOGIN:           uidt3974  
//  
//  ==========================================================================================
//  The following QAC messages are suppressed for this module:
//  
//  Error handling is emulated by using an exclusive label ERROR_EXIT, which is entered
//  via GOTO on error. Code using this type of error handling is much easier to read,
//  as no nested if() statements are required and checking of error-code/flag on each
//  block can be omitted. Suppress QAC warnings related to this functionality:
//    PRQA S 2001,2015,7003 EOF
//  
//  We intentionally have several data structures on file scope, even when they are used
//  only in one function:
//    PRQA S 3218 EOF
//  
//  A subsequent declaration of 'xxxx' means that it is being used both as a structure/union member
//  and also as a label, tag or ordinary identifier.
//    PRQA S 0781,0783 EOF
//  
//  Magic numbers with 0.0f and 1.0f are OK according to QAC documentation, however the tool
//  has a bug and gives a warning:
//  Hard-coded 'magic' floating constant '0.0f' and
//  Hard-coded 'magic' floating constant '1.0f'
//    PRQA S 3121 EOF
//  
//  Possible dereference of NULL pointer
//    PRQA S 0506 EOF
//  
//  AUTHOR:          $Author: Wang, David (Wangd3) $
//! CREATION DATE:   Wed, 7, Nov 2012  11:37 W. Europe Standard Time AM 
//**************************************************************************** */

/*## auto_generated */
#include "ic_roi.h"
/*## dependency ic_cfg */
#include "ic_cfg.h"
/*## dependency ic_errmanager */
#include "ic_errmanager.h"
/*## package Ic_Pkg */

/*## class TopLevel::ic_roi */


/*#[ ignore */
#ifdef __cplusplus
extern "C"
{
#endif

/*#]*/


//  Name of this module, required for calls to ICERR_HANDLE().
//  
//  Character string is only used for debugging & recording analysis, so suppress QAC warnings:
//  PRQA S 5013,3625 3
/*## attribute pch_ModuleName */
static const char * const pch_ModuleName = "ROI";

//  Width of the imager control ROIs (even/odd frames)
/*## attribute ICROI_caui16_IC_ROI_WIDTHs */
static const uint16 ICROI_caui16_IC_ROI_WIDTHs[IC_cui16_NumFrameTypes] = { ICCFG_cui16_IC_ROI_WIDTH_EVEN, ICCFG_cui16_IC_ROI_WIDTH_ODD };

//  Height of the imager control ROIs (even/odd frames)
/*## attribute ICROI_caui16_IC_ROI_HEIGHTs */
static const uint16 ICROI_caui16_IC_ROI_HEIGHTs[IC_cui16_NumFrameTypes] = { ICCFG_cui16_IC_ROI_HEIGHT_EVEN, ICCFG_cui16_IC_ROI_HEIGHT_ODD };

//  Nominal positions and dimensions of the imager output rois (excluding all embedded data)
//  for an ECU mounting-angle of zero. The actual position will be adjusted in ICA_e_InitCroi.
/*## attribute ICROI_cas_IMAGER_CROIS_BASE */
static const IC_S_Croi ICROI_cas_IMAGER_CROIS_BASE[IC_cui16_NumFrameTypes] = {
    {
        ICCFG_cui16_CROI_EVEN_BASE_X,
        ICCFG_cui16_CROI_EVEN_BASE_Y,
        ICCFG_cui16_CROI_EVEN_WIDTH,
        ICCFG_cui16_CROI_EVEN_HEIGHT
    },
    {
        ICCFG_cui16_CROI_ODD_BASE_X,
        ICCFG_cui16_CROI_ODD_BASE_Y,
        ICCFG_cui16_CROI_ODD_WIDTH,
        ICCFG_cui16_CROI_ODD_HEIGHT
    }
};

//  Actual positions and dimensions of the image CROIs for right even/odd frames
/*## attribute ICROI_as_ImagerRightCROIs */
static IC_S_Croi ICROI_as_ImagerRightCROIs[IC_cui16_NumFrameTypes];

//  Actual positions and dimensions of the image CROIs for left even/odd frames
/*## attribute ICROI_as_ImagerLeftCROIs */
#if (ICCFG_ENABLE_LEFT_IMAGER == 1)
static IC_S_Croi ICROI_as_ImagerLeftCROIs[IC_cui16_NumFrameTypes];
#endif

//  Pointer to camera parameters (mounting-angle, intrinsics)
/*## attribute ICROI_ps_CamParam */
static const IC_S_CamParam * ICROI_ps_CamParam = 0;

//  Filtered pitch for determining the position of the IC-ROI
/*## attribute ICROI_f32_CalibDeltaPitchFiltered */
static float32 ICROI_f32_CalibDeltaPitchFiltered;

//  Measurement data for this component.
//  
//  QAC does not understand that this struct is read/used in calling module:
//  PRQA S 3229 2
/*## attribute ICROI_ps_MeasData */
static ICROI_S_MeasData * ICROI_ps_MeasData = NULL;

//*****************************************************************************
//  Functionname:  ICROI_e_InitCroi
//  
//  
//  
//  Parameter:     IC_S_Croi (* const %s)[IC_cui16_NumFrameTypes] pas_TargetCROIs   <In>
//  
//  
//  Parameter:     const IC_S_CamIntrinsics * const ps_CamIntr   <In>
//  
//    
//  
//  return         IC_E_ERROR
//**************************************************************************** */
/*## operation ICROI_e_InitCroi(IC_S_Croi (* const )[IC_cui16_NumFrameTypes] ,const IC_S_CamIntrinsics * const) */
static IC_E_ERROR ICROI_e_InitCroi(IC_S_Croi (* const pas_TargetCROIs)[IC_cui16_NumFrameTypes], const IC_S_CamIntrinsics * const ps_CamIntr);

//*****************************************************************************
//  Functionname:  ICROI_e_SetupICRoi
//  
//  
//  
//  Parameter:     IC_S_Roi * const ps_IcRoi   <In>
//  
//  
//  Parameter:     const float32 f32_PitchDelta   <In>
//  
//  
//  Parameter:     const float32 f32_YawDelta   <In>
//  
//  
//  Parameter:     const IC_E_FRAMETYPE e_FrameType   <In>
//  
//    
//  
//  return         IC_E_ERROR
//**************************************************************************** */
/*## operation ICROI_e_SetupICRoi(IC_S_Roi * const,const float32,const float32,const IC_E_FRAMETYPE) */
static IC_E_ERROR ICROI_e_SetupICRoi(IC_S_Roi * const ps_IcRoi, const float32 f32_PitchDelta, const float32 f32_YawDelta, const IC_E_FRAMETYPE e_FrameType);

/*## operation ICROI_e_Init(ICROI_S_MeasData * const,const IC_S_CamParam * const) */
#pragma push
#pragma optimize_for_size on
IC_E_ERROR ICROI_e_Init(ICROI_S_MeasData * const ps_MeasDataIn, const IC_S_CamParam * const ps_CamParamIn) {
    /*#[ operation ICROI_e_Init(ICROI_S_MeasData * const,const IC_S_CamParam * const) */
    IC_E_ERROR      e_Ret                 = IC_e_ERR_OK;
    uint32          ui32_Index            = 0;
    
    // Store camera parameters
    ICROI_ps_CamParam = ps_CamParamIn;
    ICROI_ps_MeasData = ps_MeasDataIn;
    
    // Setup CROIs for right imager
    e_Ret = ICROI_e_InitCroi(&ICROI_as_ImagerRightCROIs, &ICROI_ps_CamParam->s_IntrR);
    if (e_Ret != IC_e_ERR_OK)
    {
      /* Keep error-code */
      goto ERROR_EXIT;
    }
    
    // Setup CROIs for left imager
    #if (ICCFG_ENABLE_LEFT_IMAGER == 1)
    e_Ret = ICROI_e_InitCroi(&ICROI_as_ImagerLeftCROIs, &ICROI_ps_CamParam->s_IntrL);
    if (e_Ret != IC_e_ERR_OK)
    {
      /* Keep error-code */
      goto ERROR_EXIT;
    }
    #endif
    
    // Add constants to MTS output
    ICROI_ps_MeasData->s_IcRoiCalib.f32_FilterDamping = ICCFG_cf32_OnlineCalibFilterDamping;
    ICROI_ps_MeasData->s_CamParams = *ICROI_ps_CamParam;
    for (ui32_Index = 0; ui32_Index < IC_cui16_NumFrameTypes; ui32_Index++)
    {
      ICROI_ps_MeasData->as_CroisRight[ui32_Index] = ICROI_as_ImagerRightCROIs[ui32_Index];
    #if (ICCFG_ENABLE_LEFT_IMAGER == 1)
      ICROI_ps_MeasData->as_CroisLeft[ui32_Index] = ICROI_as_ImagerLeftCROIs[ui32_Index];
    #endif
    }
    
    ERROR_EXIT:
    return e_Ret;
    /*#]*/
}
#pragma pop

/*## operation ICROI_e_InitCroi(IC_S_Croi (* const )[IC_cui16_NumFrameTypes] ,const IC_S_CamIntrinsics * const) */
#pragma push
#pragma optimize_for_size on
static IC_E_ERROR ICROI_e_InitCroi(IC_S_Croi (* const pas_TargetCROIs)[IC_cui16_NumFrameTypes], const IC_S_CamIntrinsics * const ps_CamIntr) {
    /*#[ operation ICROI_e_InitCroi(IC_S_Croi (* const )[IC_cui16_NumFrameTypes] ,const IC_S_CamIntrinsics * const) */
    IC_E_ERROR     e_Ret               = IC_e_ERR_OK;
    float32        f32_StartYPixOffset = 0.0f;
    sint32         si32_StartYPix      = 0;
    uint32         ui32_Index          = 0;
    
    // Checks
    if ((NULL == ICROI_ps_CamParam) || (NULL == pas_TargetCROIs))
    {
      e_Ret = IC_e_ERR_NULLPOINTER;
      goto ERROR_EXIT;
    }
    
    // Different StartY for each frame-type is illegal, so check it here.
    // This is parameter/code check and the loop is currently only executed once, so disable QAC warning:
    // PRQA S 2465 1
    for (ui32_Index = 1; ui32_Index < IC_cui16_NumFrameTypes; ui32_Index++)
    {
      if (ICROI_cas_IMAGER_CROIS_BASE[ui32_Index-1].ui16_StartY != ICROI_cas_IMAGER_CROIS_BASE[ui32_Index].ui16_StartY)
      {
        e_Ret = IC_e_ERR_CROI_STARTY_MUSTBEEQUAL;
        goto ERROR_EXIT;
      }
    }
    
    // ========== Calculate Image-CROI delta/offset ==========
    #if (IC_CROISHIFT_ENABLED == 1)
    // Use intrinsic imager pitch angle for moving CROI
    f32_StartYPixOffset = (-1.0f) * ps_CamIntr->f32_Pitch * ICCFG_cf32_PIXELS_PER_RADIAN;
    
    // Add external specified angle (e.g. SCN-Parameter for mounting-angle)
    f32_StartYPixOffset += (-1.0f) * ICROI_ps_CamParam->f32_CamPitchSCN * ICCFG_cf32_PIXELS_PER_RADIAN;
    #else
    // CROI shift is disabled
    f32_StartYPixOffset = 0;
    
    // Avoid compiler warning
    (void)ps_CamIntr;
    #endif
    
    // Calculate position of CROI (imager output roi): The values of ICROI_cas_IMAGER_CROIS_BASE
    // determine the starting-point for this calculation (referring to a mounting position of zero degrees).
    for (ui32_Index = (IC_E_FRAMETYPE)0; ui32_Index < IC_cui16_NumFrameTypes; ui32_Index++)
    {
      si32_StartYPix = (sint32)ICROI_cas_IMAGER_CROIS_BASE[ui32_Index].ui16_StartY + (sint32)ROUND(f32_StartYPixOffset);
    
      // The start-position must be even because of the bayer pattern
      si32_StartYPix &= ~1; // PRQA S 0277,4130
    
      // Check whether position is in range
      if (si32_StartYPix < (sint32)ICCFG_cui16_CROI_STARTY_MIN) // PRQA S 1258
      {
        e_Ret = IC_e_ERR_CROI_OUT_OF_RANGE;
        goto ERROR_EXIT;
      }
      if ((((uint32)si32_StartYPix + ICROI_cas_IMAGER_CROIS_BASE[ui32_Index].ui16_Height) - 1u)
          > ICCFG_cui16_CROI_ENDY_MAX)
      {
        e_Ret = IC_e_ERR_CROI_OUT_OF_RANGE;
        goto ERROR_EXIT;
      }
    
      // Assign CROIs
      (*pas_TargetCROIs)[ui32_Index].ui16_StartY = (uint16)si32_StartYPix;
      (*pas_TargetCROIs)[ui32_Index].ui16_StartX = ICROI_cas_IMAGER_CROIS_BASE[ui32_Index].ui16_StartX;
      (*pas_TargetCROIs)[ui32_Index].ui16_Width  = ICROI_cas_IMAGER_CROIS_BASE[ui32_Index].ui16_Width;
      (*pas_TargetCROIs)[ui32_Index].ui16_Height = ICROI_cas_IMAGER_CROIS_BASE[ui32_Index].ui16_Height;
    }
    
    ERROR_EXIT:
    return e_Ret;
    /*#]*/
}
#pragma pop

/*## operation ICROI_e_SetupICRoi(IC_S_Roi * const,const float32,const float32,const IC_E_FRAMETYPE) */
static IC_E_ERROR ICROI_e_SetupICRoi(IC_S_Roi * const ps_IcRoi, const float32 f32_PitchDelta, const float32 f32_YawDelta, const IC_E_FRAMETYPE e_FrameType) {
    /*#[ operation ICROI_e_SetupICRoi(IC_S_Roi * const,const float32,const float32,const IC_E_FRAMETYPE) */
    IC_E_ERROR  e_Ret                = IC_e_ERR_OK;
    sint16      si16_XStart          = 0;
    sint16      si16_YStart          = 0;
    sint16      si16_MainpointXRelImgOut = 0;
    sint16      si16_MainpointYRelImgOut = 0;
    sint16      si16_ICRoiDeltaX     = 0;
    sint16      si16_ICRoiDeltaY     = 0;
    sint16      si16_ICRoiWidth      = 0;
    sint16      si16_ICRoiHeight     = 0;
    sint16      si16_CROIWidth       = 0;
    sint16      si16_CROIHeight      = 0;
    float32     f32_PitchTotal       = 0.0f;
    float32     f32_YawTotal         = 0.0f;
    
    // Get size of IC-ROI
    si16_ICRoiWidth  = (sint16)ICROI_caui16_IC_ROI_WIDTHs[e_FrameType];
    si16_ICRoiHeight = (sint16)ICROI_caui16_IC_ROI_HEIGHTs[e_FrameType];
    si16_CROIWidth   = (sint16)ICROI_as_ImagerRightCROIs[e_FrameType].ui16_Width;
    si16_CROIHeight  = (sint16)ICROI_as_ImagerRightCROIs[e_FrameType].ui16_Height;
    
    #if (IC_ICROI_EVEN_USESTATICPOSITION == 1)
    if (e_FrameType == IC_e_FRAMETYPE_EVEN)
    {
      // Use static position for EVEN frame IC-ROI
      si16_XStart = ICCFG_cui16_IC_ROI_STATIC_X_EVEN;
      si16_YStart = ICCFG_cui16_IC_ROI_STATIC_Y_EVEN;
    }
    else
    {
    #endif
      // Translate mainpoint into coordinate-system of IC-ROI, which is based on the CROI,
      // so it has (0,0) at imager-output-pixel (0,0).
      si16_MainpointXRelImgOut = (sint16)ICROI_ps_CamParam->s_IntrR.ui16_PrincipalPointX
                               - (sint16)ICROI_as_ImagerRightCROIs[e_FrameType].ui16_StartX;
      si16_MainpointYRelImgOut = (sint16)ICROI_ps_CamParam->s_IntrR.ui16_PrincipalPointY
                               - (sint16)ICROI_as_ImagerRightCROIs[e_FrameType].ui16_StartY;
    
      // Calculate position of IC-ROI based on the new calculated angles
      //  PITCH is positive, if the camera is looking downwards,   so move ROI up (Y--)
      //  YAW   is positive, if the camera is looking to the left, so move ROI to the right (X++)
      f32_PitchTotal   = (ICROI_ps_CamParam->f32_EOLCalibPitch + f32_PitchDelta)
                       - ICCFG_cf32_IC_ROI_DESIRED_DELTA_ANGLE_TO_HORIZON;
      f32_YawTotal     = ICROI_ps_CamParam->f32_EOLCalibYaw   + f32_YawDelta;
      si16_ICRoiDeltaX = (sint16)(( 1.0f) * (f32_YawTotal   * ICCFG_cf32_PIXELS_PER_RADIAN));   // PRQA S 4119
      si16_ICRoiDeltaY = (sint16)((-1.0f) * (f32_PitchTotal * ICCFG_cf32_PIXELS_PER_RADIAN));   // PRQA S 4119
      si16_XStart      = (si16_MainpointXRelImgOut + si16_ICRoiDeltaX) - (si16_ICRoiWidth / 2); // PRQA S 3103,3120
      si16_YStart      = (si16_MainpointYRelImgOut + si16_ICRoiDeltaY);
    
      // Limit IC-ROI: Top, Left, Right: Limit to frame-boundaries
      if (si16_XStart < 0)
      {
        e_Ret = ICERR_HANDLE(IC_e_ERR_ICROI_OUT_OF_RANGE, si16_XStart);
        si16_XStart = 0;
      }
      if (si16_YStart < 0)
      {
        e_Ret = ICERR_HANDLE(IC_e_ERR_ICROI_OUT_OF_RANGE, si16_YStart);
        si16_YStart = 0;
      }
      if ((si16_XStart + si16_ICRoiWidth) > si16_CROIWidth)
      {
        e_Ret = ICERR_HANDLE(IC_e_ERR_ICROI_OUT_OF_RANGE, si16_XStart);
        si16_XStart = si16_CROIWidth - si16_ICRoiWidth;
      }
    
      // Limit IC-ROI:
      // Bottom: Allow to move the IC-ROI outside the frame, max.
      // 'csi16_ICRoiBottomMaxAllowedPixelsOutsideCroi' pixels. Crop it at frame-boundary if it's moving outside.
      if (((uint16)si16_YStart + si16_ICRoiHeight) >
            (si16_CROIHeight + ICCFG_csi16_ICRoiMaxAllowedPixelsOutsideCroiBottom))
      {
        // IC-ROI would exceed limit csi16_ICRoiBottomMaxAllowedPixelsOutsideCroi, so crop and move up
        e_Ret = ICERR_HANDLE(IC_e_ERR_ICROI_OUT_OF_RANGE, si16_YStart);
        si16_ICRoiHeight -= ICCFG_csi16_ICRoiMaxAllowedPixelsOutsideCroiBottom;
        si16_YStart = si16_CROIHeight - si16_ICRoiHeight;
      }
      else if ((si16_YStart + si16_ICRoiHeight) > si16_CROIHeight)
      {
        // IC-ROI moves outside CROI, but is within allowed limits. So crop only height to limits.
        si16_ICRoiHeight = si16_CROIHeight - si16_YStart;
      }
      else
      {
        // IC-ROI fits within the CROI, so do nothing
      }
    #if (IC_ICROI_EVEN_USESTATICPOSITION == 1)
    }
    #endif
    
    // XStart, YStart and heights are always a multiple of two because of the bayer-pattern
    si16_XStart      &= ~1; // PRQA S 0277,4130
    si16_YStart      &= ~1; // PRQA S 0277,4130
    si16_ICRoiHeight &= ~1; // PRQA S 0277,4130
    si16_ICRoiWidth  &= ~1; // PRQA S 0277,4130
    
    // Finally, assign output values
    ps_IcRoi->ui16_StartX = (uint16)si16_XStart;
    ps_IcRoi->ui16_StartY = (uint16)si16_YStart;
    ps_IcRoi->ui16_Width  = (uint16)si16_ICRoiWidth;
    ps_IcRoi->ui16_Height = (uint16)si16_ICRoiHeight;
    
    // Copy IC-ROI to measurement output
    ICROI_ps_MeasData->as_ICRois[e_FrameType] = *ps_IcRoi;
    return e_Ret;
    /*#]*/
}

/*## operation ICROI_e_SetupICRoiLd(IC_S_Roi * const,const IC_S_LdOnlineCalib * const,const IC_S_VehicleDyn * const,const IC_E_FRAMETYPE) */
IC_E_ERROR ICROI_e_SetupICRoiLd(IC_S_Roi * const ps_IcRoi, const IC_S_LdOnlineCalib * const ps_LdOnlineCalib, const IC_S_VehicleDyn * const ps_VehicleDyn, const IC_E_FRAMETYPE e_FrameType) {
    /*#[ operation ICROI_e_SetupICRoiLd(IC_S_Roi * const,const IC_S_LdOnlineCalib * const,const IC_S_VehicleDyn * const,const IC_E_FRAMETYPE) */
    IC_E_ERROR  e_Ret                = IC_e_ERR_OK;
    boolean     b_FreezeFilter       = b_FALSE;
    float32     f32_OnlinePitch      = 0.0f;
    float32     f32_ACPitch          = 0.0f;
    float32     f32_ACYaw            = 0.0f;
    float32     f32_PitchDeltaTotal  = 0.0f;
    float32     f32_PitchDeltaFiltClamp = 0.0f;
    
    // Use AC yaw from LD if quality is good enough
    if (ps_LdOnlineCalib->si32_ACYawStage >= ICCFG_csi32_MinLDOnlineCalibQuality)
    {
      f32_ACYaw = ps_LdOnlineCalib->f32_ACYaw;
    }
    
    // Only use online and AC pitch if stage is OK
    if (ps_LdOnlineCalib->si32_ACPitchStage >= ICCFG_csi32_MinLDOnlineCalibQuality)
    {
      f32_ACPitch = ps_LdOnlineCalib->f32_ACPitch;
    
      // Get current online pitch if both lanes are available
      if ((ps_LdOnlineCalib->si32_AvailableLeft > 0) && (ps_LdOnlineCalib->si32_AvailableRight > 0))
      {
        f32_OnlinePitch = ps_LdOnlineCalib->f32_OnlinePitch;
      }
      else
      {
        // Freeze pitch filter if no track available
        b_FreezeFilter = b_TRUE;
        f32_OnlinePitch = 0.0f;
      }
    
      // Freeze pitch if some type of construction side is detected
      if (0 != ps_LdOnlineCalib->si32_ConstructionSite)
      {
        b_FreezeFilter = b_TRUE;
      }
    
      // Freeze pitch if yaw-rate is too high
      if (fABS(ps_VehicleDyn->f32_YawRate) > ICCFG_cf32_OnlineCalibYawrateMax)
      {
        b_FreezeFilter = b_TRUE;
      }
    
      // Freeze pitch if speed is too low
      if (fABS(ps_VehicleDyn->f32_Velocity) < ICCFG_cf32_OnlineCalibSpeedMin)
      {
        b_FreezeFilter = b_TRUE;
      }
    
      // Drop invalid out-of-range pitches from online calibration (at filter input stage)
      if ((f32_OnlinePitch > ICCFG_cf32_OnlineCalibPitchMax) || (f32_OnlinePitch < ICCFG_cf32_OnlineCalibPitchMin))
      {
        f32_OnlinePitch = 0.0f;
      }
    
      // Sum-up total delta angle
      f32_PitchDeltaTotal = f32_ACPitch + f32_OnlinePitch;
    }
    
    // Filter stage
    if (b_FALSE == b_FreezeFilter)
    {
      ICROI_f32_CalibDeltaPitchFiltered = (ICROI_f32_CalibDeltaPitchFiltered * ICCFG_cf32_OnlineCalibFilterDamping)
                                  + ((1.0f - ICCFG_cf32_OnlineCalibFilterDamping) * f32_PitchDeltaTotal);
    }
    
    // Clamp delta angle to allowed range after low-pass filter. In fact only the online-calib
    // is clamped, but because the AC pitch is added in front of the filter stage, it has to be
    // taken into account here
    f32_PitchDeltaFiltClamp = ICROI_f32_CalibDeltaPitchFiltered;
    f32_PitchDeltaFiltClamp = MAX(f32_PitchDeltaFiltClamp, ICCFG_cf32_OnlineCalibPitchPostFiltClampMin + f32_ACPitch);
    f32_PitchDeltaFiltClamp = MIN(f32_PitchDeltaFiltClamp, ICCFG_cf32_OnlineCalibPitchPostFiltClampMax + f32_ACPitch);
    
    // Now calculate IC ROI position based on delta pitch
    e_Ret = ICROI_e_SetupICRoi(ps_IcRoi, f32_PitchDeltaFiltClamp, f32_ACYaw, e_FrameType);
    
    // Copy to measurement output
    ICROI_ps_MeasData->s_IcRoiCalib.f32_CalibDeltaPitchFiltered = ICROI_f32_CalibDeltaPitchFiltered;
    ICROI_ps_MeasData->s_IcRoiCalib.f32_PitchDeltaPreFilter     = f32_PitchDeltaTotal;
    ICROI_ps_MeasData->s_IcRoiCalib.f32_PitchTotalFiltClamp     = f32_PitchDeltaFiltClamp;
    ICROI_ps_MeasData->s_IcRoiCalib.b_FilterFrozen              = b_FreezeFilter;
    return e_Ret;
    
    // PRQA S 7002 3
    /*#]*/
}

/*## operation ICROI_e_SetupICRoiHla(IC_S_Roi * const,const IC_S_HlaOnlineCalib * const,const IC_E_FRAMETYPE) */
IC_E_ERROR ICROI_e_SetupICRoiHla(IC_S_Roi * const ps_IcRoi, const IC_S_HlaOnlineCalib * const ps_HlaOnlineCalib, const IC_E_FRAMETYPE e_FrameType) {
    /*#[ operation ICROI_e_SetupICRoiHla(IC_S_Roi * const,const IC_S_HlaOnlineCalib * const,const IC_E_FRAMETYPE) */
    // Simply use HLA online calibration pitch for positioning of the IC-ROI, without any filtering (HLA already filters)
    return ICROI_e_SetupICRoi(ps_IcRoi, ps_HlaOnlineCalib->f32_Pitch, 0.0f, e_FrameType);
    /*#]*/
}

/*## operation ICROI_v_GetImagerCroi(IC_S_Croi * const,const IC_E_Imager,const IC_E_FRAMETYPE) */
void ICROI_v_GetImagerCroi(IC_S_Croi * const ps_Croi, const IC_E_Imager e_ImagerTypeLR, const IC_E_FRAMETYPE e_FrameType) {
    /*#[ operation ICROI_v_GetImagerCroi(IC_S_Croi * const,const IC_E_Imager,const IC_E_FRAMETYPE) */
    // Assign output
    switch (e_ImagerTypeLR)
    {
    #if (ICCFG_ENABLE_LEFT_IMAGER == 1)
    case IC_e_IMAGER_LEFT:
      *ps_Croi = ICROI_as_ImagerLeftCROIs[e_FrameType];
      break;
    #endif
    case IC_e_IMAGER_RIGHT:
    default:
      *ps_Croi = ICROI_as_ImagerRightCROIs[e_FrameType];
      break;
    }
    /*#]*/
}

/*## operation ICROI_v_SimInject(float32) */
#if (IC_COMPILE_FOR_MTS == 1)
void ICROI_v_SimInject(float32 f32_CalibDeltaPitchFiltered) {
    /*#[ operation ICROI_v_SimInject(float32) */
    ICROI_f32_CalibDeltaPitchFiltered = f32_CalibDeltaPitchFiltered;
    /*#]*/
}
#endif


/*#[ ignore */

#ifdef __cplusplus
}
#endif

/*#]*/


/*********************************************************************
	File Path: ..\..\..\04_Engineering\01_Source_Code\Algo\ic\ic_roi.c
*********************************************************************/
