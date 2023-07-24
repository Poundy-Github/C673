//* **********************************************************************
//  COMPANY:         $CompanyInfo: CONFIDENTIAL AND PROPRIETARY PROPERTY OF CONTINENTAL AG , A.D.C. GmbH  -  ALL RIGHTS RESERVED $
//  
//  PROJECT:         MFC30x_MCU
//  CPU:             MPC5675K
//  
//  PACKAGE:         $Source: ic_controller.h $ $Revision: 1.1 $
//  MKS Date:        $Date: 2021/12/13 17:25:49CET $
//  
//  RHAPSODY:        7.5.3
//  COMPONENT:       IC
//  CONFIGURATION:   DefaultConfig
//  MODEL ELEMENT:   ic_controller
//  MODULNAME:       ..\..\..\04_Engineering\01_Source_Code\Algo\ic\ic_controller.h
//  LOGIN:           uidt3974  
//  
//  The IC-Controller is the central file of the IC. It controls the top level execution
//  flow of the IC. All submodules are handled and called by the IC-Controller.
//  
//  =======================================================================================
//  |                                   Main Entry Point                                  |
//  =======================================================================================
//  The main cyclic entry point of the IC is the function 'ICCTL_e_LineFunc()'. It has to
//  be called each frame for each line, which has been registered as a ROI. See function
//  description and diagrams in interface file 'ic_interface' for details on how the IC
//  must be called.
//  
//  The 'ic_interface' is actually mostly only a function wrapper, which just calls the
//  functions of the 'ic_controller' (with a few exceptions).
//  
//  =======================================================================================
//  |                               TWO-Part Execution Design                             |
//  =======================================================================================
//  The IC controller is split into two main functions:
//    * ICCTL_e_ExecPart1()
//    * ICCTL_e_ExecPart2()
//  
//  Part1 is executed when both embedded register lines (top of frame) are available from
//  current frame, Part2 is executed on frame end when statistics data is available.
//  
//  Both parts have individual tasks to perform. Part1 mostly operates on embedded register
//  data, extracting them, calculate image characteristics like response curve, doing FuSi
//  checks based on the register values and update all frame size/timing relevant register
//  settings. All new register values for the next frame, which can already be calculated
//  here, are finally written to the imager by the Part1 function.
//  
//  Part2 mainly works with frame statistical data. It extracts the embedded histogram,
//  does a few FuSi checks, and primary executes the imager exposure control module. All
//  register values which influences image brightness are calculated and written to the
//  imager here. Finally, measfreezes are done, which freezes also data from Part1 execution.
//  
//  See individual functions (desciptions, diagrams) for details.
//  
//  =======================================================================================
//  |                                        HIL-Mode                                     |
//  =======================================================================================
//  The IC can run on a hardware HIL with open loop 'virtual' imagers. As there are no real
//  imagers connected to the ECU, which accepts register writes and reflecting their changes
//  in the embedded register data, certain things must be handled differently in HIL-Mode.
//  
//  Details are described in section 'HIL-Mode' of file 'ic_controller'.
//  
//  =======================================================================================
//  The following QAC messages are suppressed for this module:
//  
//  Error handling is emulated by using an exclusive label ERROR_EXIT, which is entered
//  via GOTO on error. Code using this type of error handling is much easier to read,
//  as no nested if() statements are required and checking of error-code/flag on each
//  block can be omitted. Suppress QAC warnings related to this functionality:
//  PRQA S 2001,2015,7003 EOF
//  
//  We intentionally have several data structures on file scope, even when they are used
//  only in one function:
//  PRQA S 3218 EOF
//  
//  Possible dereference of NULL pointer
//  PRQA S 0506 EOF
//  
//  AUTHOR:          $Author: Wang, David (Wangd3) $
//! CREATION DATE:   Wed, 14, Nov 2012  11:30 W. Europe Standard Time AM 
//**************************************************************************** */

#ifndef ic_controller_H
#define ic_controller_H

/*## dependency ic_errcodes */
#include "ic_errcodes.h"
/*## dependency ic_interface */
#include "ic_interface.h"
/*## dependency ic_types */
#include "ic_types.h"
/*## package Ic_Pkg */

/*## class TopLevel::ic_controller */
/*#[ ignore */
//  The IC-Controller is the central file of the IC. It controls the top level execution
//  flow of the IC. All submodules are handled and called by the IC-Controller.
//  
//  =======================================================================================
//  |                                   Main Entry Point                                  |
//  =======================================================================================
//  The main cyclic entry point of the IC is the function 'ICCTL_e_LineFunc()'. It has to
//  be called each frame for each line, which has been registered as a ROI. See function
//  description and diagrams in interface file 'ic_interface' for details on how the IC
//  must be called.
//  
//  The 'ic_interface' is actually mostly only a function wrapper, which just calls the
//  functions of the 'ic_controller' (with a few exceptions).
//  
//  =======================================================================================
//  |                               TWO-Part Execution Design                             |
//  =======================================================================================
//  The IC controller is split into two main functions:
//    * ICCTL_e_ExecPart1()
//    * ICCTL_e_ExecPart2()
//  
//  Part1 is executed when both embedded register lines (top of frame) are available from
//  current frame, Part2 is executed on frame end when statistics data is available.
//  
//  Both parts have individual tasks to perform. Part1 mostly operates on embedded register
//  data, extracting them, calculate image characteristics like response curve, doing FuSi
//  checks based on the register values and update all frame size/timing relevant register
//  settings. All new register values for the next frame, which can already be calculated
//  here, are finally written to the imager by the Part1 function.
//  
//  Part2 mainly works with frame statistical data. It extracts the embedded histogram,
//  does a few FuSi checks, and primary executes the imager exposure control module. All
//  register values which influences image brightness are calculated and written to the
//  imager here. Finally, measfreezes are done, which freezes also data from Part1 execution.
//  
//  See individual functions (desciptions, diagrams) for details.
//  
//  =======================================================================================
//  |                                        HIL-Mode                                     |
//  =======================================================================================
//  The IC can run on a hardware HIL with open loop 'virtual' imagers. As there are no real
//  imagers connected to the ECU, which accepts register writes and reflecting their changes
//  in the embedded register data, certain things must be handled differently in HIL-Mode.
//  
//  Details are described in section 'HIL-Mode' of file 'ic_controller'.
//  
//  =======================================================================================
//  The following QAC messages are suppressed for this module:
//  
//  Error handling is emulated by using an exclusive label ERROR_EXIT, which is entered
//  via GOTO on error. Code using this type of error handling is much easier to read,
//  as no nested if() statements are required and checking of error-code/flag on each
//  block can be omitted. Suppress QAC warnings related to this functionality:
//  PRQA S 2001,2015,7003 EOF
//  
//  We intentionally have several data structures on file scope, even when they are used
//  only in one function:
//  PRQA S 3218 EOF
//  
//  Possible dereference of NULL pointer
//  PRQA S 0506 EOF
/*#]*/


/*#[ ignore */

#ifdef __cplusplus
extern "C"
{
#endif

/*#]*/


//  Number of entries in line callback time measurement array (only for debug)
/*#[ type ICCTL_cui32_LINECB_EXECTIME_ARRSIZE */
#define ICCTL_cui32_LINECB_EXECTIME_ARRSIZE 14
/*#]*/

//  Number of pixels which are copied to debug/measdata in case corrupted embedded
//  data has been detected.
/*#[ type ICCTL_cui32_EMBDDEBUG_CORRUPT_PIX_COPY */
#define ICCTL_cui32_EMBDDEBUG_CORRUPT_PIX_COPY 32
/*#]*/

//  Tolerances for analog test if executed on startup.
//  NOTE: This variable is not declared in 'ic_cfg.h', as it requires inclusion of 'ic_types.h',
//  which would generate cyclic dependencies!
/*#[ type ICCFG_s_ATest_MaxTolsStartup */
extern const IC_S_ATestMaxTols ICCFG_s_ATest_MaxTolsStartup;
/*#]*/

//  Tolerances for analog test if executed via XCP in production.
//  NOTE: This variable is not declared in 'ic_cfg.h', as it requires inclusion of 'ic_types.h',
//  which would generate cyclic dependencies!
/*#[ type ICCFG_s_ATest_MaxTolsProduction */
extern const IC_S_ATestMaxTols ICCFG_s_ATest_MaxTolsProduction;
/*#]*/

//  Structure for injection of internal IC Controller state, used for post-simulation on a PC
/*## type ICCTL_S_SimInjectionData */
typedef struct ICCTL_S_SimInjectionData {
    float32 f32_LastColCorrTemp;		/*## attribute f32_LastColCorrTemp */
    uint32 ui32_LastColCorrTimeMs;		/*## attribute ui32_LastColCorrTimeMs */
    uint8 ui8_CycColCorrTriggerCount;		/*## attribute ui8_CycColCorrTriggerCount */
} ICCTL_S_SimInjectionData;

/***    User explicit entries    ***/


/* Operations */

//*****************************************************************************
//  Functionname:  ICCTL_e_Init
//  
//  Description:
//    Initializes the Imager Control component (includes imager initialization).
//  
//    In summary this includes the following steps:
//      * Initializing submodules and internal data structures
//      * Initialize imagers (see ICCTL_e_InitImagers() for details)
//  
//    When this function returns, the imagers will start streaming image data of fixed
//    size and fixed timing. To start exposure regulation and alternating image sizes/
//    timing control, ICCTL_e_Start() has to be called after this function.
//  
//    IMPORTANT: Initializing imagers will take a significant amount of time, as the
//    init-sequence contains some explicit delays. This function should be called from
//    a task context, which is allowed to be blocked for a extended period of time!
//  
//  Preconditions:
//    * Imager Comm Bridge (ICB) / I2C interface driver must be ready
//    * Imager(s) must be powered on
//    * Imager(s) reset bar must be released at least for 120ms
//  
//  Postconditions:
//    * ICCTL_e_Start() must be called to start IC
//  
//  Parameter:     const IC_S_PlatformFuncs * const ps_PlatformFuncsIn   <In>
//  Description:   Pointer to a struct, which contains function pointer for all service functions,
//                 which are needed by the IC. ALL pointers must be valid! An error will be returned
//                 when an NULL-Pointer has been detected.
//                 NOTE: Some of the callbacks are already called while this function executes!
//  
//  Parameter:     const IC_S_StaticInput * const ps_StaticInputIn   <In>
//  Description:   Pointer to static input data, like camera calibration data
//  
//  Parameter:     const boolean b_UseHilMode   <In>
//  Description:   Setting this to 'b_TRUE' will enable HIL-Mode (see chapter in top level
//                 interface description)
//  
//  Parameter:     const boolean b_DisableAnalogTest   <In>
//  Description:   Setting this to 'b_TRUE' will DISABLE imager analog path test during startup.
//    
//  
//  return         IC_E_ERROR
//**************************************************************************** */
/*## operation ICCTL_e_Init(const IC_S_PlatformFuncs * const,const IC_S_StaticInput * const,const boolean,const boolean) */
IC_E_ERROR ICCTL_e_Init(const IC_S_PlatformFuncs * const ps_PlatformFuncsIn, const IC_S_StaticInput * const ps_StaticInputIn, const boolean b_UseHilMode, const boolean b_DisableAnalogTest);

//*****************************************************************************
//  Functionname:  ICCTL_e_Start
//  
//  Description:
//    Starts the Imager Control component. All image ROIs which are required for IC operation
//    are registered here by using platform callback functions (aka IC Adapter callbacks).
//  
//  Preconditions:
//    * ICCTL_e_Init() must have been called before
//  
//    
//  
//  return         IC_E_ERROR
//**************************************************************************** */
/*## operation ICCTL_e_Start() */
IC_E_ERROR ICCTL_e_Start(void);

//*****************************************************************************
//  Functionname:  ICCTL_e_DeInit
//  
//  Description:
//    Deinitializes the Imager Control component. All registered ROIs are
//    unregistered and the state is set back to 'INIT'.
//  
//  Preconditions:
//    * None (can be called any time)
//  
//  Postconditions:
//    * Cyclic functions (ICCTL_e_LineFunc()) must _not_ be called anymore
//    * Re-initialization is necessary before the IC can be used again
//    * Wait at least 20ms before powering down the imagers, as there may be ongoing
//      register transfers in the I2C driver buffers!
//  
//    
//  
//  return         IC_E_ERROR
//**************************************************************************** */
/*## operation ICCTL_e_DeInit() */
IC_E_ERROR ICCTL_e_DeInit(void);

//*****************************************************************************
//  Functionname:  ICCTL_v_NewFrameStarted
//  
//  Description:
//    Tells the IC that a new frame has been started. This must be called at the
//    start of each frame, before any ICCTL_e_LineFunc() has been executed during
//    current frame.
//  
//  Preconditions:
//    none
//  
//  Parameter:     const uint16 ui16_FrameNum   <In>
//  Description:   Number of the new frame
//  Range:         0 - 0xFFFF
//  Resolution:    1
//  Unit:          frames
//  
//  Parameter:     const uint64 ui64_FrameTimestamp   <In>
//  Description:   Timestamp of the new frame. This is the point in time of the
//                 frame-valid (V-SYNC) rising edge.
//  Range:         0 - 0xFFFFFFFFFFFFFFFF
//  Resolution:    1
//  Unit:          us
//    
//  
//  return         void
//**************************************************************************** */
/*## operation ICCTL_v_NewFrameStarted(const uint16,const uint64) */
void ICCTL_v_NewFrameStarted(const uint16 ui16_FrameNum, const uint64 ui64_FrameTimestamp);

//*****************************************************************************
//  Functionname:  ICCTL_v_SetInput
//  
//  Description:
//    Passes new input values to the IC.
//  
//  Preconditions:
//    * IC must be initialized
//  
//  Postconditions:
//    * Pointer target structure contents must not change until end of frame!
//  
//  Parameter:     const IC_S_Input * const ps_Input   <In>
//  
//    
//  
//  return         void
//**************************************************************************** */
/*## operation ICCTL_v_SetInput(const IC_S_Input * const) */
void ICCTL_v_SetInput(const IC_S_Input * const ps_Input);

//*****************************************************************************
//  Functionname:  ICCTL_e_LineFunc
//  
//  Description:
//    This is the central cyclic execution entry point of the Imager Control. This function
//    must be called for each line of the ROIs, which have been registered by the IC via
//    callback 'pfct_e_RoiRegister'. All control functions and submodules are executed
//    from within this function. This includes, but is not limited to:
//      * Analyzing image data (embedded/statistics data, dark-rows, noise calculation)
//      * Exposure regulation
//      * Frame timing and frame size control
//      * Starting imager register transfers (call I2C driver via callbacks)
//      * Registering ROIs for startup tests (via callbacks)
//      * Provide image characteristics and statistical data (via callbacks)
//      * Report DEMs (via callbacks)
//  
//    Runtime of this function depends highly on the current line number. It has peaks at each
//    the last embedded register and embedded statistics data line.
//  
//    See activity chart for details.
//  
//  Preconditions:
//    * Module must be initialized by calling 'ICCTL_e_Init()'
//    * 'IC_v_NewFrameStarted()' must be called when a new frame has started
//    * 'IC_v_SetInput()'        must be called when a new frame has started
//  
//  Postconditions:
//    none
//  
//  Parameter:     const IC_E_FRAMETYPE e_FrameType   <In>
//  Description:   Type of the current frame (even|odd)
//  Range:         (enum)
//  Resolution:    none
//  Unit:          none
//  
//  Parameter:     const uint16 ui16_LineNum   <In>
//  Description:   Number of the line, which is passed as 'pui16_PixelData'
//  Range:         0 - 0xFFFF
//  Resolution:    1
//  Unit:          lines
//  
//  Parameter:     const uint16 * const pui16_PixelData   <In>
//  Description:   Pointer to the contents of line 'ui16_LineNum' in current frame
//  Range:         0 - 4095
//  Resolution:    1
//  Unit:          pixeldata
//    
//  
//  return         IC_E_ERROR
//**************************************************************************** */
/*## operation ICCTL_e_LineFunc(const IC_E_FRAMETYPE,const uint16,const uint16 * const) */
IC_E_ERROR ICCTL_e_LineFunc(const IC_E_FRAMETYPE e_FrameType, const uint16 ui16_LineNum, const uint16 * const pui16_PixelData);

//*****************************************************************************
//  Functionname:  ICCTL_v_SetTestpatternLeft
//  
//  Description:
//    Enables/disables left imager testpattern output. If enabled, the imager outputs a modified
//    walking-ones pattern instead of sampled pixel data. Embedded data is not affected by this
//    setting.
//   
//  Preconditions:
//    * IC must be initialized
//  
//  Postconditions:
//    * IC must be started and 'Part2' must be called cyclic to apply changes
//  
//  Parameter:     const boolean b_Enabled   <In>
//  
//    
//  
//  return         void
//**************************************************************************** */
/*## operation ICCTL_v_SetTestpatternLeft(const boolean) */
#if (ICCFG_ENABLE_LEFT_IMAGER == 1)
void ICCTL_v_SetTestpatternLeft(const boolean b_Enabled);
#endif

//*****************************************************************************
//  Functionname:  ICCTL_e_SetAnalogTestParams
//  
//  Description:
//    Sets the parameters for 'manual' analog test execution. The structure is copied to
//    local memory, so it can be destroyed after function returns.
//  
//    NOTE: This function is not intended to be used for the analog test which is executed
//          on startup. It uses 'production level' tolerances, which are stricter than
//          'startup test' tolerances.
//  
//  Parameter:     const IC_S_ATestExternParams * const ps_Params   <In>
//  
//    
//  
//  return         IC_E_ERROR
//**************************************************************************** */
/*## operation ICCTL_e_SetAnalogTestParams(const IC_S_ATestExternParams * const) */
#if (IC_ANALOG_TEST_ENABLED == 1)
IC_E_ERROR ICCTL_e_SetAnalogTestParams(const IC_S_ATestExternParams * const ps_Params);
#endif

//*****************************************************************************
//  Functionname:  ICCTL_e_StartAnalogTest
//  
//  Description:
//    Starts analog test execution. This function is intended to be used when analog test
//    is executed 'manually' (e.g. via XCP in production). It is _not_ intended to be used
//    for startup tests!
//  
//  Preconditions:
//    * Analog test paramters must have been set by calling ICCTL_e_SetAnalogTestParams()
//    * IC must be in state 'RUNNING'
//  
//    
//  
//  return         IC_E_ERROR
//**************************************************************************** */
/*## operation ICCTL_e_StartAnalogTest() */
#if (IC_ANALOG_TEST_ENABLED == 1)
IC_E_ERROR ICCTL_e_StartAnalogTest(void);
#endif

//*****************************************************************************
//  Functionname:  ICCTL_v_GetSensorIDs
//  
//  Description:
//    Returns sensor identification data of a specific imager:
//      * Imager ModelId
//      * Imager Revision
//      * Imager serial number (aka FuseID)
//  
//  Preconditions:
//    * IC must be initialized
//  
//  Postconditions:
//    none
//  
//  Parameter:     IC_S_SensorIDs * const ps_SensorIDs   <In>
//  
//  
//  Parameter:     const IC_E_Imager e_Imager   <In>
//  
//    
//  
//  return         void
//**************************************************************************** */
/*## operation ICCTL_v_GetSensorIDs(IC_S_SensorIDs * const,const IC_E_Imager) */
void ICCTL_v_GetSensorIDs(IC_S_SensorIDs * const ps_SensorIDs, const IC_E_Imager e_Imager);

//*****************************************************************************
//  Functionname:  ICCTL_e_GetTemperature
//  
//  Description:
//    Returns the temperature of a specific sensor, inluding timestamp.
//  
//    NOTE: Output pointer targets are not updated when an error occurs (check return code!).
//  
//  Returns:
//    IC_e_ERR_OK                -> No error occurred
//    IC_e_ERR_NOTAVAILABLE      -> Temperature is currently unknown
//    IC_e_ERR_ILLEGAL_SENSORNUM -> Illegal sensor has been requested
//  
//  Preconditions:
//    * IC must be initialized
//    * ICCTL_e_ExecPart1() must have been executed at least once
//    * Left imager only: Left imager register data must be available (e.g. provided via
//      IPC from slave DSP) and must not be older than 'ICCFG_cui32_TEMPERATURE_MAXAGE_US'.
//  
//  Postconditions:
//    none
//  
//  Parameter:     const IC_E_Imager e_Imager   <In>
//  
//  
//  Parameter:     float32 * const pf32_Temp   <In>
//  
//  
//  Parameter:     uint64 * const pui64_TimeStamp   <In>
//  
//    
//  
//  return         IC_E_ERROR
//**************************************************************************** */
/*## operation ICCTL_e_GetTemperature(const IC_E_Imager,float32 * const,uint64 * const) */
IC_E_ERROR ICCTL_e_GetTemperature(const IC_E_Imager e_Imager, float32 * const pf32_Temp, uint64 * const pui64_TimeStamp);

//*****************************************************************************
//  Functionname:  ICCTL_b_IsStableStateReached
//  
//  Description:
//    Returns information about the current state of the Imager Control. When the IC is in
//    normal operation mode (i.e. it's fully initialized and all startup tests are finished),
//    it returns 'b_TRUE'.
//  
//  Returns:
//    b_TRUE  - IC is running stable in normal operation mode, including exposure regulation
//    b_FALSE - IC is currently _not_ in normal operation mode (i.e. executes startup tests)
//   
//  Preconditions:
//    none (can be called any time)
//  
//  Postconditions:
//    none
//  
//    
//  
//  return         boolean
//**************************************************************************** */
/*## operation ICCTL_b_IsStableStateReached() */
boolean ICCTL_b_IsStableStateReached(void);

//*****************************************************************************
//  Functionname:  ICCTL_v_SimInject
//  
//  Description:
//    Injects new values of some internal variables of this module. This is intended
//    to be called only when this module is simulated on PC (e.g. via MTS).
//  
//  
//  Parameter:     ICCTL_S_SimInjectionData * ps_Inject   <In>
//  
//    
//  
//  return         void
//**************************************************************************** */
/*## operation ICCTL_v_SimInject(ICCTL_S_SimInjectionData *) */
#if (IC_COMPILE_FOR_MTS == 1)
void ICCTL_v_SimInject(ICCTL_S_SimInjectionData * ps_Inject);
#endif

//*****************************************************************************
//  Functionname:  ICCTL_e_ExternalControl
//  
//  Description:
//    Executes commands which are sent via external control interface (e.g. via XCP).
//  
//  Parameter:     const ICIF_E_EXTCMD e_Command   <In>
//  
//  
//  Parameter:     const uint8 %s[ICIF_cui32_EXTCTL_ARGSIZE] aui8_Arguments   <In>
//  
//    
//  
//  return         IC_E_ERROR
//**************************************************************************** */
/*## operation ICCTL_e_ExternalControl(const ICIF_E_EXTCMD,const uint8 [ICIF_cui32_EXTCTL_ARGSIZE]) */
IC_E_ERROR ICCTL_e_ExternalControl(const ICIF_E_EXTCMD e_Command, const uint8 aui8_Arguments[ICIF_cui32_EXTCTL_ARGSIZE]);


/*#[ ignore */

#ifdef __cplusplus
}
#endif

/*#]*/


#endif
/*********************************************************************
	File Path: ..\..\..\04_Engineering\01_Source_Code\Algo\ic\ic_controller.h
*********************************************************************/
