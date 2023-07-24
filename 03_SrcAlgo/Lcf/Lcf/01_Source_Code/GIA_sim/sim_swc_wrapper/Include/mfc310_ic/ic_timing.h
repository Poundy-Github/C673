//* **********************************************************************
//  COMPANY:         $CompanyInfo: CONFIDENTIAL AND PROPRIETARY PROPERTY OF CONTINENTAL AG , A.D.C. GmbH  -  ALL RIGHTS RESERVED $
//  
//  PROJECT:         MFC30x_MCU
//  CPU:             MPC5675K
//  
//  PACKAGE:         $Source: ic_timing.h $ $Revision: 1.1 $
//  MKS Date:        $Date: 2021/12/13 17:26:05CET $
//  
//  RHAPSODY:        7.5.3
//  COMPONENT:       IC
//  CONFIGURATION:   DefaultConfig
//  MODEL ELEMENT:   ic_timing
//  MODULNAME:       ..\..\..\04_Engineering\01_Source_Code\Algo\ic\ic_timing.h
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

#ifndef ic_timing_H
#define ic_timing_H

/*## dependency ic_types */
#include "ic_types.h"
/*## package Ic_Pkg */

/*## class TopLevel::ic_timing */
/*#[ ignore */
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
/*#]*/


/*#[ ignore */

#ifdef __cplusplus
extern "C"
{
#endif

/*#]*/


//  Measurement data structure for the IC timing module.
/*## type ICTIM_S_MeasData */
typedef struct ICTIM_S_MeasData {
    uint16 ui16_JitterIndex;		/*## attribute ui16_JitterIndex */
    sint16 si16_SyncOffsetPending;		/*## attribute si16_SyncOffsetPending */
    sint16 si16_SyncOffsetTotal;		/*## attribute si16_SyncOffsetTotal */
    sint16 si16_SyncOffsetMeasured;		/*## attribute si16_SyncOffsetMeasured */
    uint64 ui64_IAFrameStartTime;		/*## attribute ui64_IAFrameStartTime */
    uint64 ui64_NextTimestampL;		/*## attribute ui64_NextTimestampL */
    uint64 ui64_NextTimestampR;		/*## attribute ui64_NextTimestampR */
} ICTIM_S_MeasData;

/***    User explicit entries    ***/


/* Operations */

//*****************************************************************************
//  Functionname:  ICTIM_v_Init
//  
//  Description:
//    Initializes the imager control timing module.
//  
//  Parameter:     ICTIM_S_MeasData * const ps_MeasDataIn   <In>
//  Description:   Pointer to measurement structure
//  
//    
//  
//  return         void
//**************************************************************************** */
/*## operation ICTIM_v_Init(ICTIM_S_MeasData * const) */
void ICTIM_v_Init(ICTIM_S_MeasData * const ps_MeasDataIn);

//*****************************************************************************
//  Functionname:  ICTIM_v_SetEmbeddedTimestamp
//  
//  Description:
//    Updates the imager frame timestamp registers with a value, which will appear in the
//    embedded data of the next frame N+1. So when this method is called in frame N, it
//    pre-calculates the future timestamp of frame N+1 and passes that value to the imager
//    driver.
//  
//    The function takes image jittering and imager resynchronization into account when
//    the next embedded timestamp is calculated.
//  
//  Preconditions:
//    - ICTIM_v_UpdateFrameTiming() must have been called for current frame
//  
//  Parameter:     const uint64 ui64_FrameStartUs   <In>
//  Description:   Frame timestamp of the _current_ frame (NOT the one that's written into embedded data)
//  Range:         uint64
//  Resolution:    1
//  Unit:          us
//    
//  
//  return         void
//**************************************************************************** */
/*## operation ICTIM_v_SetEmbeddedTimestamp(const uint64) */
void ICTIM_v_SetEmbeddedTimestamp(const uint64 ui64_FrameStartUs);

//*****************************************************************************
//  Functionname:  ICTIM_v_SetJittering
//  
//  Description:
//    Enables or disables timing-jittering of the even numbered frames.
//  
//  Parameter:     const boolean b_Enabled   <In>
//  
//    
//  
//  return         void
//**************************************************************************** */
/*## operation ICTIM_v_SetJittering(const boolean) */
void ICTIM_v_SetJittering(const boolean b_Enabled);

//*****************************************************************************
//  Functionname:  ICTIM_e_ResyncImagersSetLtoR
//  
//  Description:
//    Re-times the left imager in relation to the right imager by temporarily adjusting the image
//    blanking period. This method will set the absolute timing-difference t(L)-t(R) in lines.
//    See ICA_e_ResyncImagersAddLinesLeft.
//  
//    * A positive number -delays-   the left imager in repect to the right imager.
//    * A negative number -advances- the left imager in repect to the right imager.
//    * A number of -ZERO- synchronizes both imagers, so their frame valid signals are asserted
//      at same point in time.
//  
//    NOTE: There is a limit for the number of lines that can be re-timed each cycle (see ic_cfg.h
//          ICCFG_csi16_RESYNC_LEFT_LINES_STEP_MAX). Higher values are automatically split over
//          several cycles.
//  
//  Preconditions:
//    - This Module must be initialized
//  
//  Postconditions:
//    - ICTIM_v_UpdateFrameTiming() must be called to apply changes
//  
//  Parameter:     const sint16 si16_NumLinesLtoR   <In>
//  Description:   Absolute number of lines for setting left-to-right imager frame timing.
//                 Negative number advances left image, positive delays it in relation to the right.
//  Range:         ICCFG_csi16_RESYNC_LEFT_LINES_TOTAL_MIN ... ICCFG_csi16_RESYNC_LEFT_LINES_TOTAL_MAX
//  Resolution:    1
//  Unit:          lines
//    
//  
//  return         IC_E_ERROR
//**************************************************************************** */
/*## operation ICTIM_e_ResyncImagersSetLtoR(const sint16) */
#if (ICCFG_ENABLE_LEFT_IMAGER == 1)
IC_E_ERROR ICTIM_e_ResyncImagersSetLtoR(const sint16 si16_NumLinesLtoR);
#endif

//*****************************************************************************
//  Functionname:  ICTIM_e_ResyncImagersAddLinesLeft
//  
//  Description:
//    Re-times the left imager in relation to the right imager by substracting or adding a number
//    of lines from/to the image blanking period. This is used by the SAC to resynchronize the
//    CROIs of the left and right imager.
//  
//    * A positive number -delays-   the left imager by si16_NumLines.
//    * A negative number -advances- the left imager by si16_NumLines.
//  
//    NOTE: There is a limit for the number of lines that can be re-timed each cycle (see ic_cfg.h
//          ICCFG_csi16_RESYNC_LEFT_LINES_STEP_MAX). Higher values are automatically split over
//          several cycles.
//  
//  Preconditions:
//    - This Module must be initialized
//  
//  Postconditions:
//    - ICTIM_v_UpdateFrameTiming() must be called to apply changes
//  
//  Parameter:     const sint16 si16_NumLines   <In>
//  Description:   Relative number of lines for adjusting left imager frame timing.
//  Range:         ICCFG_csi16_RESYNC_LEFT_LINES_TOTAL_MIN ... ICCFG_csi16_RESYNC_LEFT_LINES_TOTAL_MAX
//  Resolution:    1
//  Unit:          lines
//    
//  
//  return         IC_E_ERROR
//**************************************************************************** */
/*## operation ICTIM_e_ResyncImagersAddLinesLeft(const sint16) */
#if (ICCFG_ENABLE_LEFT_IMAGER == 1)
IC_E_ERROR ICTIM_e_ResyncImagersAddLinesLeft(const sint16 si16_NumLines);
#endif

//*****************************************************************************
//  Functionname:  ICTIM_v_UpdateFrameTiming
//  
//  Description:
//    This function calculates new values for the frame timing registers (aka TOTAL frame length/height,
//    including blanking) and passes the new values to the imager driver.
//  
//    The timing is influenced by:
//    * Jittering of even image  (every cycle)
//    * Imager resynchronization (only when offset changed)
//  
//  Inputs:
//    * ICTIM_caui16_ICJitterSequence
//    * ICTIM_b_EnableJittering
//    * ICTIM_ui16_JitterIndex
//    * ICTIM_si16_ImagerLineOffsetLeftPending
//  
//  Outputs:
//    * ICTIM_ui32_FramesSinceLastSyncChange
//    * ICTIM_si16_ImagerLineOffsetLeftTotalThis
//    * ICTIM_asi16_ImagerLineOffsetLeftTotalDelayed
//  
//  Preconditions:
//    - ICTIM_v_UpdateFrameTiming() must have been called for current frame
//  
//  Parameter:     const IC_E_FRAMETYPE e_CurrentFrameType   <In>
//  Description:   Frame type of the current image
//  Range:         (enum)
//  Resolution:    -
//  Unit:          -
//    
//  
//  return         void
//**************************************************************************** */
/*## operation ICTIM_v_UpdateFrameTiming(const IC_E_FRAMETYPE) */
void ICTIM_v_UpdateFrameTiming(const IC_E_FRAMETYPE e_CurrentFrameType);

//*****************************************************************************
//  Functionname:  ICTIM_v_CheckFrameSync
//  
//  Description:
//    Checks if the measured left/right imager timing offset equals the expected value, which
//    has been set via ICTIM_e_ResyncImagers*().
//  
//    Measuring frame timing is done by the FPGA in MFC310 and passed to the IC inputs via
//    IPC, so there is a multiframe delay until the IC receives the measured value of a
//    specific frame. To take this into account, the function ignores the measured value for
//    'ICCFG_cui32_MAX_ALLOWED_SYNC_FEEDBACK_DELAY' frames after a timing change has been
//    requested.
//  
//  Parameter:     const sint16 si16_SyncOffsetMeasured   <In>
//  Description:   Measured image sync offset left-to-right
//  Resolution:    1
//  Unit:          lines
//    
//  
//  return         void
//**************************************************************************** */
/*## operation ICTIM_v_CheckFrameSync(const sint16) */
#if (ICCFG_ENABLE_LEFT_IMAGER == 1)
void ICTIM_v_CheckFrameSync(const sint16 si16_SyncOffsetMeasured);
#endif

//*****************************************************************************
//  Functionname:  ICTIM_si32_GetTimingOffsetLR_us
//  
//  Description:
//    Returns image timing offset between Left/Right imager.
//  
//    
//  
//  return         sint32
//**************************************************************************** */
/*## operation ICTIM_si32_GetTimingOffsetLR_us() */
#if (ICCFG_ENABLE_LEFT_IMAGER == 1)
sint32 ICTIM_si32_GetTimingOffsetLR_us(void);
#endif

//*****************************************************************************
//  Functionname:  ICTIM_v_SimInject
//  
//  Description:
//    Injects internal data into this module. This is used to restore a specific state during
//    component simulation in MTS.
//  
//  Parameter:     uint16 ui16_JitterIndex   <In>
//  
//    
//  
//  return         void
//**************************************************************************** */
/*## operation ICTIM_v_SimInject(uint16) */
#if (IC_COMPILE_FOR_MTS == 1)
void ICTIM_v_SimInject(uint16 ui16_JitterIndex);
#endif


/*#[ ignore */

#ifdef __cplusplus
}
#endif

/*#]*/


#endif
/*********************************************************************
	File Path: ..\..\..\04_Engineering\01_Source_Code\Algo\ic\ic_timing.h
*********************************************************************/
