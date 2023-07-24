//* **********************************************************************
//  COMPANY:         $CompanyInfo: CONFIDENTIAL AND PROPRIETARY PROPERTY OF CONTINENTAL AG , A.D.C. GmbH  -  ALL RIGHTS RESERVED $
//  
//  PROJECT:         MFC30x_MCU
//  CPU:             MPC5675K
//  
//  PACKAGE:         $Source: ic_timing.c $ $Revision: 1.1 $
//  MKS Date:        $Date: 2021/12/13 17:26:04CET $
//  
//  RHAPSODY:        7.5.3
//  COMPONENT:       IC
//  CONFIGURATION:   DefaultConfig
//  MODEL ELEMENT:   ic_timing
//  MODULNAME:       ..\..\..\04_Engineering\01_Source_Code\Algo\ic\ic_timing.c
//  LOGIN:           uidt3974  
//  
//  This module implements all imager timing related functionalities. This includes:
//  
//  Jittering of the even image:
//    The time-period of the even numbered frames shall not be constant due to requirements
//    of the sign recognition algorithm (pulsed LED traffic signs). This module implements
//    jittering, so the time-period of the even image will vary over time. A fixed timing
//    table with 16 values is used for adjusting frame timing.
//  
//    Jittering is actually done by adjusting the total frame height imager registers, which
//    influence the length of frame blanking. All details are explained in the specification
//    document 'Base_MFC300_Imager_Timing.doc'.
//  
//  Imager resychronization (aka imager sync):
//    Due to production tolerances of stereo cameras, the stereo functions need to adjust
//    the timing between left and right imager. This is explained in detail in the linked
//    document 'Base_MFC300_Imager_Sync.doc'.
//  
//    Image resynchronization can be done on-demand. It is done by adjusting total frame
//    height (frame blanking) of the left imager.
//  
//  Calculating embedded timestamps:
//    Each frame contains a timestamp in it's embedded data. This timestamp is pre-calculated
//    by this module and passed to the imager driver. So calculation for frame N+1 is actually
//    done in frame N and depends on the frame length of frame N.
//  
//  Image timing and imager synchronization is specified in attached documents:
//    * Base_MFC300_Imager_Timing.doc
//    * Base_MFC300_Imager_Sync.doc
//  
//  AUTHOR:          $Author: Wang, David (Wangd3) $
//! CREATION DATE:   Tue, 11, Sep 2012  5:02 W. Europe Daylight Time PM 
//**************************************************************************** */

/*## auto_generated */
#include "ic_timing.h"
/*## dependency ic_driver */
#include "ic_driver.h"
/*## dependency ic_errmanager */
#include "ic_errmanager.h"
/*## package Ic_Pkg */

/*## class TopLevel::ic_timing */


/*#[ ignore */
#ifdef __cplusplus
extern "C"
{
#endif

/*#]*/


//  Description:   Depth of the delay chain 'ICTIM_asi16_ImagerLineOffsetLeftTotalDelayed[]'
//  Resolution:    1
//  Unit:          entries
/*## attribute ICTIM_cui_DELAY_CHAIN_LENGTH */
#define ICTIM_cui_DELAY_CHAIN_LENGTH 2

//  Name of this module, required for calls to ICERR_HANDLE().
//  
//  Character string is only used for debugging & recording analysis, so suppress QAC warnings:
//  PRQA S 5013,3625 3
/*## attribute pch_ModuleName */
static const char * const pch_ModuleName = "TIMING";

//  Description:   This array contains a timing table that is used to achieve a jittering of the even
//                 image. It contains the number of lines, by which the odd image is enlarged (and even
//                 shorted) to achieve this.
//  Range:         Depends on frame timing! MFC310: 0 - 255
//  Resolution:    1
//  Unit:          lines
//  
//  PRQA S 3674 3
/*## attribute ICTIM_caui16_ICJitterSequence */
static const uint16 ICTIM_caui16_ICJitterSequence[] = { ICCFG_caui_JITTER_SEQUENCE };

//  Description:   Number of elements in the jitter sequence
//  Range:         =length(ICTIM_caui16_ICJitterSequence)
//  Resolution:    1
//  Unit:          elements
//  
//  PRQA S 3218 2
/*## attribute ICTIM_cui16_ICJitterSequenceLength */
static const uint16 ICTIM_cui16_ICJitterSequenceLength = IC_ARRLEN(ICTIM_caui16_ICJitterSequence);

//  Description:   Current position in the jitter sequence array ICTIM_caui16_ICJitterSequence[]
//  Range:         0 ... length(ICTIM_caui16_ICJitterSequence)
//  Resolution:    1
//  Unit:          -
/*## attribute ICTIM_ui16_JitterIndex */
static uint16 ICTIM_ui16_JitterIndex = 0;

//  Description:   See si16_ImagerLineOffsetLeftTotalNext. This is the actual line-offset of the current
//                 frame after ICTIM_v_UpdateFrameTiming() has been called.
//  Range:         ICCFG_csi16_RESYNC_LEFT_LINES_TOTAL_MIN ... ICCFG_csi16_RESYNC_LEFT_LINES_TOTAL_MAX
//  Resolution:    1
//  Unit:          lines
/*## attribute ICTIM_si16_ImagerLineOffsetLeftTotalThis */
static sint16 ICTIM_si16_ImagerLineOffsetLeftTotalThis = 0;

//  Description:   Number of lines the left-imager's vsync rising edge starts after the
//                 right imager. It is defined as:
//  
//                   si16_ImagerLineOffsetLeftCurrent = T_VSYNC(Left) - T_VSYNC(Right)
//  
//                 Changes of this value will be applied by calling ICTIM_v_UpdateFrameTiming()
//  
//  Range:         ICCFG_csi16_RESYNC_LEFT_LINES_TOTAL_MIN ... ICCFG_csi16_RESYNC_LEFT_LINES_TOTAL_MAX
//  Resolution:    1
//  Unit:          lines
/*## attribute ICTIM_si16_ImagerLineOffsetLeftTotalNext */
static sint16 ICTIM_si16_ImagerLineOffsetLeftTotalNext = 0;

//  Description:   See si16_ImagerLineOffsetLeftTotalNext.
//                 This delay-chain is used to calc the expected offset of the current frame.
//  Range:         ICCFG_csi16_RESYNC_LEFT_LINES_TOTAL_MIN ... ICCFG_csi16_RESYNC_LEFT_LINES_TOTAL_MAX
//  Resolution:    1
//  Unit:          lines
/*## attribute ICTIM_asi16_ImagerLineOffsetLeftTotalDelayed */
static sint16 ICTIM_asi16_ImagerLineOffsetLeftTotalDelayed[ICTIM_cui_DELAY_CHAIN_LENGTH] = { 0, 0 };

//  Description:   Number of lines the left-imager has to be resynchronized in relation to the right
//  Range:         ICCFG_csi16_RESYNC_LEFT_LINES_TOTAL_MIN ... ICCFG_csi16_RESYNC_LEFT_LINES_TOTAL_MAX
//  Resolution:    1
//  Unit:          lines
/*## attribute ICTIM_si16_ImagerLineOffsetLeftPending */
static sint16 ICTIM_si16_ImagerLineOffsetLeftPending = 0;

//  Description:   Number of frames since the last change of imager sync offset has been applied
//  Range:         0 - 2^32
//  Resolution:    1
//  Unit:          frames
/*## attribute ICTIM_ui32_FramesSinceLastSyncChange */
static uint32 ICTIM_ui32_FramesSinceLastSyncChange = 0;

//  Description:   This flag enables jittering of the even image
//  Range:         -
//  Resolution:    -
//  Unit:          -
/*## attribute ICTIM_b_EnableJittering */
static boolean ICTIM_b_EnableJittering = b_FALSE;

//  Description:   Pointer to measurement data buffer struct of this module.
//  Range:         not NULL
//  Resolution:    -
//  Unit:          -
//  
//  Target structure data is cyclically sent to MTS by calling module, so suppress QAC warning "written but not used":
//  PRQA S 3229 2
/*## attribute ICTIM_ps_MeasData */
static ICTIM_S_MeasData * ICTIM_ps_MeasData = NULL;

/*## operation ICTIM_v_Init(ICTIM_S_MeasData * const) */
void ICTIM_v_Init(ICTIM_S_MeasData * const ps_MeasDataIn) {
    /*#[ operation ICTIM_v_Init(ICTIM_S_MeasData * const) */
    ICTIM_ps_MeasData = ps_MeasDataIn;
    
    // Initialize variables
    IC_v_ZEROMEM(ICTIM_asi16_ImagerLineOffsetLeftTotalDelayed);
    ICTIM_ui16_JitterIndex                    = 0;
    ICTIM_si16_ImagerLineOffsetLeftTotalNext  = 0;
    ICTIM_si16_ImagerLineOffsetLeftTotalThis  = 0;
    ICTIM_si16_ImagerLineOffsetLeftPending    = 0;
    ICTIM_ui32_FramesSinceLastSyncChange      = 0;
    ICTIM_b_EnableJittering                   = b_FALSE;
    /*#]*/
}

/*## operation ICTIM_v_SetEmbeddedTimestamp(const uint64) */
void ICTIM_v_SetEmbeddedTimestamp(const uint64 ui64_FrameStartUs) {
    /*#[ operation ICTIM_v_SetEmbeddedTimestamp(const uint64) */
    uint64 ui64_TimestampR = 0;
    uint64 ui64_TimestampL = 0;
    sint32 si32_TimeDiffLR_us = 0;
    uint32 ui32_CurrentFrameTimeTotalUs = 0;
    uint32 ui32_CurrentFrameHeightTotal = 0;
    
    // Get the height of the current image from the registers
    ui32_CurrentFrameHeightTotal = IMGDRV_ui16_GetImageHeightTotalR();
    
    // Calculate total time of the current frame (including blanking) to predict
    // the timestamp of the next rising edge
    ui32_CurrentFrameTimeTotalUs = (ICCFG_cui32_LineTimeNs * ui32_CurrentFrameHeightTotal) / IC_FACTOR_US2NS;
    
    // The timing-difference between L/R must also be considered
    // PRQA S 3103,1258 1
    si32_TimeDiffLR_us = ((sint32)ICCFG_cui32_LineTimeNs * ICTIM_si16_ImagerLineOffsetLeftTotalThis) / IC_FACTOR_US2NS;
    
    // The embedded data in the next image shall represent the time of it's frame-valid
    // rising edge, so add the total frame-time of the current frame here
    ui64_TimestampR = ui64_FrameStartUs + (uint64)ui32_CurrentFrameTimeTotalUs;
    ui64_TimestampL = ui64_FrameStartUs + (uint64)((sint32)ui32_CurrentFrameTimeTotalUs + si32_TimeDiffLR_us); // PRQA S 4121
    
    // Update timestamp in the measurement-buffer
    // PRQA S 0506 1
    ICTIM_ps_MeasData->ui64_NextTimestampL   = ui64_TimestampL;
    ICTIM_ps_MeasData->ui64_NextTimestampR   = ui64_TimestampR;
    ICTIM_ps_MeasData->ui64_IAFrameStartTime = ui64_FrameStartUs;
    
    // Integrate timestamp into embedded data. The used registers are not frame-synced, so they
    // will be reflected in the embedded data of the next frame.
    IMGDRV_v_SetTimestampEmbedded(IC_e_IMAGER_RIGHT, ui64_TimestampR);
    #if (ICCFG_ENABLE_LEFT_IMAGER == 1)
    IMGDRV_v_SetTimestampEmbedded(IC_e_IMAGER_LEFT,  ui64_TimestampL);
    #endif
    /*#]*/
}

/*## operation ICTIM_v_SetJittering(const boolean) */
void ICTIM_v_SetJittering(const boolean b_Enabled) {
    /*#[ operation ICTIM_v_SetJittering(const boolean) */
    ICTIM_b_EnableJittering = b_Enabled;
    /*#]*/
}

/*## operation ICTIM_e_ResyncImagersSetLtoR(const sint16) */
#if (ICCFG_ENABLE_LEFT_IMAGER == 1)
IC_E_ERROR ICTIM_e_ResyncImagersSetLtoR(const sint16 si16_NumLinesLtoR) {
    /*#[ operation ICTIM_e_ResyncImagersSetLtoR(const sint16) */
    const sint16 si16_CurrentSum = ICTIM_si16_ImagerLineOffsetLeftTotalNext + ICTIM_si16_ImagerLineOffsetLeftPending;
    return ICTIM_e_ResyncImagersAddLinesLeft(si16_NumLinesLtoR - si16_CurrentSum);
    /*#]*/
}
#endif

/*## operation ICTIM_e_ResyncImagersAddLinesLeft(const sint16) */
#if (ICCFG_ENABLE_LEFT_IMAGER == 1)
IC_E_ERROR ICTIM_e_ResyncImagersAddLinesLeft(const sint16 si16_NumLines) {
    /*#[ operation ICTIM_e_ResyncImagersAddLinesLeft(const sint16) */
    IC_E_ERROR e_Ret = IC_e_ERR_OK;
    
    // Check if we are in range
    const sint16 si16_TotalSum = si16_NumLines + ICTIM_si16_ImagerLineOffsetLeftTotalNext + ICTIM_si16_ImagerLineOffsetLeftPending;
    if ((si16_TotalSum > ICCFG_csi16_RESYNC_LEFT_LINES_TOTAL_MAX)
     || (si16_TotalSum < ICCFG_csi16_RESYNC_LEFT_LINES_TOTAL_MIN))
    {
      e_Ret = ICERR_HANDLE(IC_e_ERR_IMGSYNC_RANGE_EXCEEDED, si16_NumLines);
    }
    else
    {
      ICTIM_si16_ImagerLineOffsetLeftPending += si16_NumLines;
    }
    return e_Ret;
    /*#]*/
}
#endif

/*## operation ICTIM_v_UpdateFrameTiming(const IC_E_FRAMETYPE) */
void ICTIM_v_UpdateFrameTiming(const IC_E_FRAMETYPE e_CurrentFrameType) {
    /*#[ operation ICTIM_v_UpdateFrameTiming(const IC_E_FRAMETYPE) */
    sint16 si16_ResyncLines = 0;
    
    // Total height of the next frame (including v-blanking)
    uint16 ui16_NextFrameHeightTotal = 0;
    uint16 ui16_NextFrameHeightLeft = 0;
    
    // The image-length register is frame-sync'd, so it will be effective two frames later
    #if (IC_JITTERING_ENABLED == 1)
    if (IC_e_FRAMETYPE_ODD == e_CurrentFrameType)
    {
      // If the frame-type is odd, EXTEND the total size of the next odd image to let the following
      // even image start a bit later
      ui16_NextFrameHeightTotal = ICCFG_cui16_FrameHeightTotalOdd + ICTIM_caui16_ICJitterSequence[ICTIM_ui16_JitterIndex];
    }
    else
    {
      // If the frame-type is even, REDUCE the size of the next even image to let the odd image
      // appear as non-jittering
      ui16_NextFrameHeightTotal = ICCFG_cui16_FrameHeightTotalEven - ICTIM_caui16_ICJitterSequence[ICTIM_ui16_JitterIndex];
    
      // Move to next value of the jitter sequence if jittering is enabled. Do this check here
      // because jittering might have been disabled externally in odd frame, which would result
      // to an unexpected odd-frame period.
      if (b_TRUE == ICTIM_b_EnableJittering)
      {
        ICTIM_ui16_JitterIndex++;
        if (ICTIM_ui16_JitterIndex >= ICTIM_cui16_ICJitterSequenceLength)
        {
          ICTIM_ui16_JitterIndex = 0;
        }
      }
      else
      {
        // Jittering is disabled
        ICTIM_ui16_JitterIndex = 0;
      }
    }

    #else
    // Jittering disabled, so just set total frame heights according to configuration
    if (IC_e_FRAMETYPE_ODD == e_CurrentFrameType)
    {
      ui16_NextFrameHeightTotal = ICCFG_cui16_FrameHeightTotalOdd;
    }
    else
    {
      ui16_NextFrameHeightTotal = ICCFG_cui16_FrameHeightTotalEven;
    }
    #endif
    
    #if (ICCFG_ENABLE_LEFT_IMAGER == 1)
    // Resynchronisation for left imager requested? This should only be done in the even frame cycle!
    if ((0 != ICTIM_si16_ImagerLineOffsetLeftPending) && (IC_e_FRAMETYPE_EVEN == e_CurrentFrameType))
    {
      si16_ResyncLines = MINMAX(ICCFG_csi16_RESYNC_LEFT_LINES_STEP_MIN,
                                ICCFG_csi16_RESYNC_LEFT_LINES_STEP_MAX,
                                ICTIM_si16_ImagerLineOffsetLeftPending);
      ICTIM_si16_ImagerLineOffsetLeftTotalNext += si16_ResyncLines;
      ICTIM_si16_ImagerLineOffsetLeftPending -= si16_ResyncLines;
      ICTIM_ui32_FramesSinceLastSyncChange = 0;
      ui16_NextFrameHeightLeft = (uint16)((sint16)ui16_NextFrameHeightTotal + si16_ResyncLines);
    }
    else
    {
      ui16_NextFrameHeightLeft = ui16_NextFrameHeightTotal;
    }
    ICTIM_ui32_FramesSinceLastSyncChange++;
    
    // Update delay-chain for L-R timing offset. This is used to calculate valid timestamps for
    // the left imager.
    ICTIM_si16_ImagerLineOffsetLeftTotalThis        = ICTIM_asi16_ImagerLineOffsetLeftTotalDelayed[1];
    ICTIM_asi16_ImagerLineOffsetLeftTotalDelayed[1] = ICTIM_asi16_ImagerLineOffsetLeftTotalDelayed[0];
    ICTIM_asi16_ImagerLineOffsetLeftTotalDelayed[0] = ICTIM_si16_ImagerLineOffsetLeftTotalNext;
    #endif
    
    // Update meas-data
    // PRQA S 0506 1
    ICTIM_ps_MeasData->si16_SyncOffsetPending = ICTIM_si16_ImagerLineOffsetLeftPending;
    ICTIM_ps_MeasData->si16_SyncOffsetTotal   = ICTIM_si16_ImagerLineOffsetLeftTotalNext;
    ICTIM_ps_MeasData->ui16_JitterIndex       = ICTIM_ui16_JitterIndex;
    
    // Set registers: The image-length register is frame-sync'd, so it will be effective two frames later
    IMGDRV_v_SetFrameHeightTotal(IC_e_IMAGER_RIGHT, ui16_NextFrameHeightTotal);
    #if (ICCFG_ENABLE_LEFT_IMAGER == 1)
    IMGDRV_v_SetFrameHeightTotal(IC_e_IMAGER_LEFT, ui16_NextFrameHeightLeft);
    #endif
    /*#]*/
}

/*## operation ICTIM_v_CheckFrameSync(const sint16) */
#if (ICCFG_ENABLE_LEFT_IMAGER == 1)
void ICTIM_v_CheckFrameSync(const sint16 si16_SyncOffsetMeasured) {
    /*#[ operation ICTIM_v_CheckFrameSync(const sint16) */
    uint32 ui32_Hint  = 0;
    
    // Check if the requested image-sync is actually present. To account for delays in IPC chain,
    // wait some frames since last change until we really execute the check
    if (ICTIM_ui32_FramesSinceLastSyncChange > ICCFG_cui32_MAX_ALLOWED_SYNC_FEEDBACK_DELAY)
    {
      if (si16_SyncOffsetMeasured != ICTIM_si16_ImagerLineOffsetLeftTotalNext)
      {
        ui32_Hint = (((uint32)si16_SyncOffsetMeasured) << IC_NUMBITS_16) | ((uint32)ICTIM_si16_ImagerLineOffsetLeftTotalNext);
        (void)ICERR_HANDLE(IC_e_ERR_IMGSYNC_OUTOFSYNC, ui32_Hint); /* Don't report to caller, handle in ErrManager */
        ICERR_v_DemFailed(IC_e_DEM_HARDWARE_TIMING, ui32_Hint);
      }
      else
      {
        ICERR_v_DemPassed(IC_e_DEM_HARDWARE_TIMING);
      }
    }
    
    // Update measurement data
    // PRQA S 0506 1
    ICTIM_ps_MeasData->si16_SyncOffsetMeasured = si16_SyncOffsetMeasured;
    /*#]*/
}
#endif

/*## operation ICTIM_si32_GetTimingOffsetLR_us() */
#if (ICCFG_ENABLE_LEFT_IMAGER == 1)
sint32 ICTIM_si32_GetTimingOffsetLR_us(void) {
    /*#[ operation ICTIM_si32_GetTimingOffsetLR_us() */
    // The timing-difference between L/R
    // PRQA S 1258,3103 1
    return ((sint32)ICCFG_cui32_LineTimeNs * ICTIM_si16_ImagerLineOffsetLeftTotalThis) / IC_FACTOR_US2NS;
    /*#]*/
}
#endif

/*## operation ICTIM_v_SimInject(uint16) */
#if (IC_COMPILE_FOR_MTS == 1)
void ICTIM_v_SimInject(uint16 ui16_JitterIndex) {
    /*#[ operation ICTIM_v_SimInject(uint16) */
    ICTIM_ui16_JitterIndex = ui16_JitterIndex;
    /*#]*/
}
#endif


/*#[ ignore */

#ifdef __cplusplus
}
#endif

/*#]*/


/*********************************************************************
	File Path: ..\..\..\04_Engineering\01_Source_Code\Algo\ic\ic_timing.c
*********************************************************************/
