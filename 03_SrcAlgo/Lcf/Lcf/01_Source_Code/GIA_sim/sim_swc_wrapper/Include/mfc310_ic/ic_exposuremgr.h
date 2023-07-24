//* **********************************************************************
//  COMPANY:         $CompanyInfo: CONFIDENTIAL AND PROPRIETARY PROPERTY OF CONTINENTAL AG , A.D.C. GmbH  -  ALL RIGHTS RESERVED $
//  
//  PROJECT:         MFC30x_MCU
//  CPU:             MPC5675K
//  
//  PACKAGE:         $Source: ic_exposuremgr.h $ $Revision: 1.1 $
//  MKS Date:        $Date: 2021/12/13 17:25:53CET $
//  
//  RHAPSODY:        7.5.3
//  COMPONENT:       IC
//  CONFIGURATION:   DefaultConfig
//  MODEL ELEMENT:   ic_exposuremgr
//  MODULNAME:       ..\..\..\04_Engineering\01_Source_Code\Algo\ic\ic_exposuremgr.h
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
//! CREATION DATE:   Mon, 30, Jul 2012  4:39 W. Europe Daylight Time PM 
//**************************************************************************** */

#ifndef ic_exposuremgr_H
#define ic_exposuremgr_H

/*## dependency ic_types */
#include "ic_types.h"
/*## package Ic_Pkg */

/*## class TopLevel::ic_exposuremgr */
/*#[ ignore */
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
/*#]*/


/*#[ ignore */

#ifdef __cplusplus
extern "C"
{
#endif

/*#]*/


//  Structure for transferring results to the calling module.
/*## type ICEXPMG_S_Results */
typedef struct ICEXPMG_S_Results {
    //  Description:   Stores the 'Weighted Mean' value, which has been calculated by the Exposure Control instance
    //                 from current image histogram. See chapter 'MEAN, WEIGHTED MEAN, LOW-END MEAN' of 'ic_exposure'
    //                 module description for details.
    //  Range:         0-2^20
    //  Resolution:    1
    //  Unit:          Grayvalues (linear)
    uint32 ui32_LumaMeanWeighted;		/*## attribute ui32_LumaMeanWeighted */
    //  Description:   Storing whether dual or single exposure mode is enabled. See 'EXPOSURE CONTROL MODES' in module
    //                 description.
    //                 - b_TRUE:  Dual exposure mode enabled
    //                 - b_FALSE: Single exposure mode enabled
    //  Range:         (boolean)
    //  Resolution:    none
    //  Unit:          none
    boolean b_DualExposureEnabled;		/*## attribute b_DualExposureEnabled */
    //  Description:   Intraday State flag from previous frame of same type (in other word: from last camera cycle)
    //  Range:         (enum)
    //  Resolution:    none
    //  Unit:          none
    IC_E_INTRADAY_STATE e_IntradaystateLast;		/*## attribute e_IntradaystateLast */
    //  Description:   Intraday State flag which will be valid on next frame of same type (next camera cycle).
    //  Range:         (enum)
    //  Resolution:    none
    //  Unit:          none
    IC_E_INTRADAY_STATE e_IntradaystateNext;		/*## attribute e_IntradaystateNext */
} ICEXPMG_S_Results;

//  Structure for storing the MTS Measurement Data of this module.
/*## type ICEXPMG_S_MeasData */
typedef struct ICEXPMG_S_MeasData {
    //  Description:   Number of frames left until normal exposure control operation mode will be entered again
    //  Range:         0-0xFFFFFFFF
    //  Resolution:    1
    //  Unit:          frames
    uint32 ui32_FixedExposureModeFramesLeft;		/*## attribute ui32_FixedExposureModeFramesLeft */
    //  Description:   Storing whether dual or single exposure mode is enabled. See 'EXPOSURE CONTROL MODES' in module
    //                 description.
    //                 - b_TRUE:  Dual exposure mode enabled
    //                 - b_FALSE: Single exposure mode enabled
    //  Range:         (boolean)
    //  Resolution:    none
    //  Unit:          none
    boolean b_DualExposureEnabled;		/*## attribute b_DualExposureEnabled */
} ICEXPMG_S_MeasData;

/***    User explicit entries    ***/


/* Operations */

//*****************************************************************************
//  Functionname:  ICEXPMG_e_Exec
//  
//  Description:
//    Executes an Exposure Control calculation/regulation cycle. Input data is passed to that underlying
//    ICEXP control instance, which is responsible for the current frame type. Calculations of the new
//    control settings are done there.
//  
//    The results from the Exposure Control instance is forwarded to the Imager Driver, which converts
//    the values into raw register values and forwards them to the Register Manager.
//  
//    NOTE: Writing the register values to the imager is initiated by the IC Controller and executed by
//    the Register Manager, so this function will _not_ result in writing values directly to the imager.
//  
//  Preconditions:
//    Module must be intialized.
//  
//  Parameter:     const IC_E_FRAMETYPE e_FrameType   <In>
//  Description:   Frame type which is processed during this execution
//  Range:         (enum)
//  Resolution:    none
//  Unit:          none
//  
//  Parameter:     IC_S_ImageDataContainer const * const ps_ImageData   <In>
//  Description:   Input image extracted embedded and statistics data
//  Range:         none
//  Resolution:    none
//  Unit:          none
//  
//  Parameter:     IC_S_Roi const * const ps_IcRoi   <In>
//  Description:   Position and size of the input image IC-ROI (used only for plausibilisation)
//  Range:         none
//  Resolution:    none
//  Unit:          none
//  
//  Parameter:     const boolean b_ForceDcgChange   <In>
//  Description:   Flag to force a change of the DCG. The change is actually done in frame N+2.
//                 See module description section "FORCING A DCG CHANGE".
//  Range:         (boolean)
//  Resolution:    none
//  Unit:          none
//    
//  
//  return         IC_E_ERROR
//**************************************************************************** */
/*## operation ICEXPMG_e_Exec(const IC_E_FRAMETYPE,IC_S_ImageDataContainer const * const,IC_S_Roi const * const,const boolean) */
IC_E_ERROR ICEXPMG_e_Exec(const IC_E_FRAMETYPE e_FrameType, IC_S_ImageDataContainer const * const ps_ImageData, IC_S_Roi const * const ps_IcRoi, const boolean b_ForceDcgChange);

//*****************************************************************************
//  Functionname:  ICEXPMG_e_Init
//  
//  Description:
//    Initializes this module and all it's submodules. This includes passing Exposure Control Parameters
//    to the Exposure Control instances.
//  
//  Preconditions:
//    none
//  
//  Parameter:     ICEXPMG_S_MeasData * const ps_MeasDataIn   <In>
//  Description:   Pointer to measurement data struct, which will be filled on each execution
//                 of ICEXPMG_e_Exec()
//  Range:         (boolean)
//  Resolution:    none
//  Unit:          none
//  
//  Parameter:     const float32 f32_DcgFactor   <In>
//  Description:   DCG factor of the (right) imager, from PPAR
//  Range:         none
//  Resolution:    none
//  Unit:          none
//    
//  
//  return         IC_E_ERROR
//**************************************************************************** */
/*## operation ICEXPMG_e_Init(ICEXPMG_S_MeasData * const,const float32) */
IC_E_ERROR ICEXPMG_e_Init(ICEXPMG_S_MeasData * const ps_MeasDataIn, const float32 f32_DcgFactor);

//*****************************************************************************
//  Functionname:  ICEXPMG_e_SetTemporaryFixedExposureT1
//  
//  Description:
//    This function allows to set a fixed exposure time for a specific number of frames. In fact not only
//    the exposure time is fixed, but also some other control values are set to a fixed value. The settings
//    are as follow:
//    
//      T1  = ui16_T1_us
//      R1  = 16
//      R2  = 16
//      DCG = LOW
//  
//    ... and the Exposure Control mode is switched to 'Single Exposure' (see module description).
//  
//    The normal control behavior is restored after the given number of frames. This is actually done in
//    the ICEXPMG_e_Exec() function.
//  
//    See module description for additional info.
//  
//  Preconditions:
//    Module must be intialized.
//  
//  Parameter:     const uint16 ui16_T1_us   <In>
//  Description:   Exposure time to set
//  Range:         260-20000
//  Resolution:    1
//  Unit:          us
//  
//  Parameter:     const uint32 ui32_NumFramesPersistence   <In>
//  Description:   Number of frames until the previous settings are restored
//  Range:         1-0xFFFF
//  Resolution:    1
//  Unit:          us
//    
//  
//  return         IC_E_ERROR
//**************************************************************************** */
/*## operation ICEXPMG_e_SetTemporaryFixedExposureT1(const uint16,const uint32) */
IC_E_ERROR ICEXPMG_e_SetTemporaryFixedExposureT1(const uint16 ui16_T1_us, const uint32 ui32_NumFramesPersistence);

//*****************************************************************************
//  Functionname:  ICEXPMG_v_GetExposureMeasData
//  
//  Description:
//    Returns a pointer to the MTS measurement data of the underlying Exposure Control instance, which
//    is selected by 'e_FrameType'.
//  
//  Preconditions:
//    ICEXPMG_e_Exec() must have been called for current frame
//  
//  Parameter:     void * * const ppv_Data   <Out>
//  Description:   Reference to a pointer, which will be set to the address of the exposure control
//                 instance measurement data.
//                 data.
//  Range:         1-0xFFFF
//  Resolution:    1
//  Unit:          us
//  
//  Parameter:     uint32 * const pui32_Size   <Out>
//  Description:   Output pointer, whose target will be set to the number of bytes in '**ppv_Data'.
//  Range:         sizeof(ICEXP_S_MeasData)
//  Resolution:    1
//  Unit:          bytes
//  
//  Parameter:     const IC_E_FRAMETYPE e_FrameType   <In>
//  Description:   Frame type for which measurement data shall be returned
//  Range:         (enum)
//  Resolution:    none
//  Unit:          none
//    
//  
//  return         void
//**************************************************************************** */
/*## operation ICEXPMG_v_GetExposureMeasData(void * * const,uint32 * const,const IC_E_FRAMETYPE) */
void ICEXPMG_v_GetExposureMeasData(void * * const ppv_Data, uint32 * const pui32_Size, const IC_E_FRAMETYPE e_FrameType);

//*****************************************************************************
//  Functionname:  ICEXPMG_v_GetResults
//  
//  Description:
//    Returns results from current execution cycle, which have been produced by calling ICEXPMG_e_Exec().
//  
//  Preconditions:
//    ICEXPMG_e_Exec() must have been called for current frame
//  
//  Parameter:     ICEXPMG_S_Results * const ps_Results   <Out>
//  Description:   Pointer to struct which will be filled with results
//  Range:         none
//  Resolution:    none
//  Unit:          none
//  
//  Parameter:     const IC_E_FRAMETYPE e_FrameType   <In>
//  Description:   Frame type for which results are returned
//  Range:         none
//  Resolution:    none
//  Unit:          none
//    
//  
//  return         void
//**************************************************************************** */
/*## operation ICEXPMG_v_GetResults(ICEXPMG_S_Results * const,const IC_E_FRAMETYPE) */
void ICEXPMG_v_GetResults(ICEXPMG_S_Results * const ps_Results, const IC_E_FRAMETYPE e_FrameType);

//*****************************************************************************
//  Functionname:  ICEXPMG_v_ResetTemporaryFixedExposureT1
//  
//  Description:
//    This function restores normal control behavior which was changed by a previous call to
//    ICEXPMG_e_SetTemporaryFixedExposureT1().
//  
//  Preconditions:
//    Module must be intialized.
//  
//    
//  
//  return         void
//**************************************************************************** */
/*## operation ICEXPMG_v_ResetTemporaryFixedExposureT1() */
void ICEXPMG_v_ResetTemporaryFixedExposureT1(void);

//*****************************************************************************
//  Functionname:  ICEXPMG_v_SimInjectState
//  
//  Description:
//    Injects a state into an ICEXP object.
//  
//    This function is only used if the IC is compiled for MTS!
//  
//  Parameter:     void * ps_State   <In>
//  Description:   This is actually a ICEXP_S_State* pointer type! To prevent inclusion of 'ic_exposure.h'
//                 in the header file of this module, it's declared as a void pointer here.
//  Range:         none
//  Resolution:    none
//  Unit:          none
//  
//  Parameter:     IC_E_FRAMETYPE e_FrameType   <In>
//  Description:   Specifies the target ICEXP object for injection
//  Range:         (enum)
//  Resolution:    none
//  Unit:          none
//    
//  
//  return         void
//**************************************************************************** */
/*## operation ICEXPMG_v_SimInjectState(void *,IC_E_FRAMETYPE) */
#if (IC_COMPILE_FOR_MTS == 1)
void ICEXPMG_v_SimInjectState(void * ps_State, IC_E_FRAMETYPE e_FrameType);
#endif


/*#[ ignore */

#ifdef __cplusplus
}
#endif

/*#]*/


#endif
/*********************************************************************
	File Path: ..\..\..\04_Engineering\01_Source_Code\Algo\ic\ic_exposuremgr.h
*********************************************************************/
