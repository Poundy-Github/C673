//* **********************************************************************
//  COMPANY:         $CompanyInfo: CONFIDENTIAL AND PROPRIETARY PROPERTY OF CONTINENTAL AG , A.D.C. GmbH  -  ALL RIGHTS RESERVED $
//  
//  PROJECT:         MFC30x_MCU
//  CPU:             MPC5675K
//  
//  PACKAGE:         $Source: ic_interface.h $ $Revision: 1.1 $
//  MKS Date:        $Date: 2021/12/13 17:25:55CET $
//  
//  RHAPSODY:        7.5.3
//  COMPONENT:       IC
//  CONFIGURATION:   DefaultConfig
//  MODEL ELEMENT:   ic_interface
//  MODULNAME:       ..\..\..\04_Engineering\01_Source_Code\Algo\ic\ic_interface.h
//  LOGIN:           uidt3974  
//  
//  This is the top-level interface file of the Imager Control component. All calls from
//  the runtime environment (aka FrameSW) are going through this interface. It is not
//  allowed to directly call functions of IC submodules, which are not defined in this
//  interface file!
//  
//  In fact, this file is only a wrapper, which calls IC submodule functions.
//  
//  =======================================================================================
//  |                                   The Imager Control                                |
//  =======================================================================================
//  The Imager Control component handles most of the tasks related to the imager. This
//  includes, but is not limited to:
//    * Initializing Imagers
//       * Includes register verification
//    * Executing Startup tests
//       * Imager BIST
//       * Databus Test
//       * Analog Test
//    * Imager timing control
//       * Imager synchronization
//       * Jittering of even numbered images
//    * Imager column noise correction triggering, based on temperature changes
//    * Software exposure regulation
//       * Independent control loops for even/odd frames, each having its own set of
//         parameters
//    * Calculation of image characteristics
//       * Response curve calculation (Output to Algos)
//       * Brightness calculation
//       * Noise estimation
//       * Imager temperature
//    * Cyclic FuSi checks
//       * Checking embedded data consistency
//       * Register verification
//       * Cyclic databus test
//       * Framecounter check
//       * Checking I2C register transfer timing
//  
//  =======================================================================================
//  |                                        HIL-Mode                                     |
//  =======================================================================================
//  This module can be initialized in 'HIL-Mode'. This can be used when no real imagers are
//  actually connected to the ECU (open control loop) or when this module is simulated on
//  a PC (e.g. as MTS MO). It is _not_ intended to be used on a simple 'Monitor HIL', which
//  has a camera mounted in front of the screen.
//  
//  In HIL-Mode, the IC skips the following execution steps during init / cyclic execution:
//    * Imager Initialization
//    * Startup tests (BIST, Databus Test, Analog Test)
//    * Cyclic checking of register contents
//    * Cyclic checking of I2C transfer timing
//    * Cyclic checking of left/right imager synchronization
//    * Cyclic checking of IC-ROI position and dimensions
//  
//  When HIL-Mode is enabled, the IC calls external callback 'pfct_v_ResyncSystemTime' on
//  each odd frame and passes the timing offset between embedded frame timestamp and current
//  ECU time as an argument. This can be used to resychronize the ECU time to the time base
//  which is embedded in the recording, which is currently streamed to the ECU camera
//  connectors.
//  
//  To enable HIL-Mode, set 'b_HILMode' to 'b_TRUE' when calling 'IC_e_Init()'.
//  
//  AUTHOR:          $Author: Wang, David (Wangd3) $
//! CREATION DATE:   Thu, 18, Oct 2012  5:52 W. Europe Daylight Time PM 
//**************************************************************************** */

#ifndef ic_interface_H
#define ic_interface_H

/*## dependency ic_errcodes */
#include "ic_errcodes.h"
/*## dependency ic_types */
#include "ic_types.h"
/*## package Ic_Pkg */

/*## class TopLevel::ic_interface */
/*#[ ignore */
//  This is the top-level interface file of the Imager Control component. All calls from
//  the runtime environment (aka FrameSW) are going through this interface. It is not
//  allowed to directly call functions of IC submodules, which are not defined in this
//  interface file!
//  
//  In fact, this file is only a wrapper, which calls IC submodule functions.
//  
//  =======================================================================================
//  |                                   The Imager Control                                |
//  =======================================================================================
//  The Imager Control component handles most of the tasks related to the imager. This
//  includes, but is not limited to:
//    * Initializing Imagers
//       * Includes register verification
//    * Executing Startup tests
//       * Imager BIST
//       * Databus Test
//       * Analog Test
//    * Imager timing control
//       * Imager synchronization
//       * Jittering of even numbered images
//    * Imager column noise correction triggering, based on temperature changes
//    * Software exposure regulation
//       * Independent control loops for even/odd frames, each having its own set of
//         parameters
//    * Calculation of image characteristics
//       * Response curve calculation (Output to Algos)
//       * Brightness calculation
//       * Noise estimation
//       * Imager temperature
//    * Cyclic FuSi checks
//       * Checking embedded data consistency
//       * Register verification
//       * Cyclic databus test
//       * Framecounter check
//       * Checking I2C register transfer timing
//  
//  =======================================================================================
//  |                                        HIL-Mode                                     |
//  =======================================================================================
//  This module can be initialized in 'HIL-Mode'. This can be used when no real imagers are
//  actually connected to the ECU (open control loop) or when this module is simulated on
//  a PC (e.g. as MTS MO). It is _not_ intended to be used on a simple 'Monitor HIL', which
//  has a camera mounted in front of the screen.
//  
//  In HIL-Mode, the IC skips the following execution steps during init / cyclic execution:
//    * Imager Initialization
//    * Startup tests (BIST, Databus Test, Analog Test)
//    * Cyclic checking of register contents
//    * Cyclic checking of I2C transfer timing
//    * Cyclic checking of left/right imager synchronization
//    * Cyclic checking of IC-ROI position and dimensions
//  
//  When HIL-Mode is enabled, the IC calls external callback 'pfct_v_ResyncSystemTime' on
//  each odd frame and passes the timing offset between embedded frame timestamp and current
//  ECU time as an argument. This can be used to resychronize the ECU time to the time base
//  which is embedded in the recording, which is currently streamed to the ECU camera
//  connectors.
//  
//  To enable HIL-Mode, set 'b_HILMode' to 'b_TRUE' when calling 'IC_e_Init()'.
/*#]*/


/*#[ ignore */

#ifdef __cplusplus
extern "C"
{
#endif

/*#]*/


/*#[ type IC_E_RXTXERR */
typedef enum
{
    IC_e_RXTXERR_OK,
    IC_e_RXTXERR_BUSERR,
    IC_e_RXTXERR_NOACK,
    IC_e_RXTXERR_BUFFER_OVERFLOW,
    IC_e_RXTXERR_OTHER
}  IC_E_RXTXERR;
/*#]*/

/*#[ type ICIF_E_MEASERR */
typedef enum
{
    ICIF_e_MEASERR_OK,
    ICIF_e_MEASERR_BUSY,
    ICIF_e_MEASERR_OVERFLOW,
    ICIF_e_MEASERR_GENERICERR,
    ICIF_e_MEASERR_TOO_MUCH_GROUPS
}  ICIF_E_MEASERR;
/*#]*/

/*#[ type ICIF_E_ROIERR */
typedef enum
{
    ICIF_e_ROIERR_OK,
    ICIF_e_ROIERR_ERROR
}  ICIF_E_ROIERR;
/*#]*/

/*#[ type ICIF_E_ROIFRAMETYPE */
typedef enum
{
    ICIF_e_ROIFRAMETYPE_EVEN,
    ICIF_e_ROIFRAMETYPE_ODD,
    ICIF_e_ROIFRAMETYPE_ALL,
    ICIF_e__NUM_ENTRIES_
}  ICIF_E_ROIFRAMETYPE;
/*#]*/

/*#[ type IC_E_ADAPTERR */
typedef enum
{
    IC_e_ADAPTERR_OK,
    IC_e_ADAPTERR_FAILED
}  IC_E_ADAPTERR;
/*#]*/

/*#[ type IC_E_I2CTIMING */
typedef enum
{
    IC_e_I2CTIMING_SLOW,
    IC_e_I2CTIMING_FAST
}  IC_E_I2CTIMING;
/*#]*/

/*## type IC_S_ResultsPart1 */
typedef struct IC_S_ResultsPart1 {
    IRCC_S_ResponseCurve * ps_ResponseCurve;		/*## attribute ps_ResponseCurve */
    IC_S_EmbeddedRegData * ps_EmbeddedData;		/*## attribute ps_EmbeddedData */
    #if (ICCFG_ENABLE_LEFT_IMAGER == 1)
    IC_S_RegTransfReq s_RegTransferRequest;
    #endif		/*## attribute s_RegTransferRequest */
    IC_E_INTRADAY_STATE e_IntradayState;		/*## attribute e_IntradayState */
    IC_E_FRAMETYPE e_FrameType;		/*## attribute e_FrameType */
    float32 f32_NoiseStdDev;		/*## attribute f32_NoiseStdDev */
    float32 f32_Blacklevel;		/*## attribute f32_Blacklevel */
    boolean b_DualExposureEnabled;		/*## attribute b_DualExposureEnabled */
} IC_S_ResultsPart1;

/*## type IC_S_ResultsPart2 */
typedef struct IC_S_ResultsPart2 {
    uint64 ui64_FrameTimestamp;		/*## attribute ui64_FrameTimestamp */
    IC_S_EmbeddedStatData * ps_StatisticsData;		/*## attribute ps_StatisticsData */
    float32 f32_BrightnessCdqm;		/*## attribute f32_BrightnessCdqm */
    uint32 ui32_LumaMeanWeighted;		/*## attribute ui32_LumaMeanWeighted */
    uint16 ui16_FrameNum;		/*## attribute ui16_FrameNum */
    uint16 ui16_LumaMeanCompanded;		/*## attribute ui16_LumaMeanCompanded */
} IC_S_ResultsPart2;

/*## type IC_S_CommStats */
typedef struct IC_S_CommStats {
    uint32 ui32_ISRRuntimeTotalUs;		/*## attribute ui32_ISRRuntimeTotalUs */
    uint32 ui32_ISRCountTotal;		/*## attribute ui32_ISRCountTotal */
    uint16 ui16_TxDataBuffUsageMax;		/*## attribute ui16_TxDataBuffUsageMax */
    uint16 ui16_TxTransBuffUsageMax;		/*## attribute ui16_TxTransBuffUsageMax */
} IC_S_CommStats;

//  Handle to an externally registered ROI
/*#[ type IC_t_RoiHandle */
typedef uint32 IC_t_RoiHandle;
/*#]*/

//  This callback is called by the ImagerCommBridge layer when a register transfer has been completed
/*#[ type IC_Fct_TransfCallback */
typedef void (* IC_Fct_TransfCallback)(const IC_E_RXTXERR e_RetCode, const uint8 ui8_TransferId);
/*#]*/

//  Pointer to OS Sleep function
/*#[ type IC_Fct_DelayUs */
typedef void (* IC_Fct_DelayUs)(const uint32 ui32_DelayUs);
/*#]*/

//  Pointer to OS function for returning current system time
/*#[ type IC_Fct_GetTimeUs */
typedef uint32 (* IC_Fct_GetTimeUs)(void);
/*#]*/

//  Pointer to OS function for returning current system time
/*#[ type IC_Fct_GetTimeUs64 */
typedef uint64 (* IC_Fct_GetTimeUs64)(void);
/*#]*/

//  Pointer to function for setting the imager's trigger/exposure pin
/*#[ type IC_Fct_SetTriggerPin */
typedef void (* IC_Fct_SetTriggerPin)(const boolean b_Value);
/*#]*/

//  Function for setting external ic debug LED
/*#[ type IC_Fct_SetDebugLed */
typedef void (* IC_Fct_SetDebugLed)(const boolean b_Value);
/*#]*/

//  Function for setting external ic debug LED
/*#[ type IC_Fct_SetTestvoltage */
typedef void (* IC_Fct_SetTestvoltage)(const IC_E_TESTVOLTAGE e_Voltage);
/*#]*/

//  Function for setting I2C bus timing/speed
/*#[ type IC_Fct_SetI2CTiming */
typedef void (* IC_Fct_SetI2CTiming)(const IC_E_I2CTIMING e_Timing);
/*#]*/

//  Function for getting imager communication/transfer statistics
/*#[ type IC_Fct_GetCommStats */
typedef void (* IC_Fct_GetCommStats)(IC_S_CommStats * const ps_Stats);
/*#]*/

//  Function for reinitializing imager comm stack
/*#[ type IC_Fct_ReInitImgComm */
typedef IC_E_ADAPTERR (* IC_Fct_ReInitImgComm)(void);
/*#]*/

//  Function is called by IC when new image characteristics data is available
/*#[ type IC_Fct_ResultsPart1Avail */
typedef void (* IC_Fct_ResultsPart1Avail)(IC_S_ResultsPart1 const * const ps_Results);
/*#]*/

//  Function is called by IC when new image statistical data is available
/*#[ type IC_Fct_ResultsPart2Avail */
typedef void (* IC_Fct_ResultsPart2Avail)(IC_S_ResultsPart2 const * const ps_Results);
/*#]*/

//  Pointer to function for reading and writing registers from/to the imager(s).
//  
//  The implementation has to support both register read and register write transfers.
//  Transfer type is selected via 'e_TransferMode'. Write transfers allow to set
//  'e_Imager' to IC_e_IMAGER_ALL - this does not apply to read transfers of course.
//  
//  The implementation has to support both asynchronous and synchronous register transfers.
//  Synchronous transfers are selected when 'fct_Callback' is set to 'NULL'. In this mode
//  the underlying driver must block this function call until the transfer is finished.
//  
//  When 'fct_Callback' is valid (not NULL), a synchronous transfer will be executed.
//  The driver has to buffer write transfers (or queue read transfers) and return
//  immediately. The transfer shall run in background and when it finishs, the callback
//  passed via 'fct_Callback' has to be executed, passing 'ui8_TransferId' as parameter.
//  
//  
//  Parameter:     e_Imager  <IN>
//  Description:   Imager type, which is selected for the transfer
//  Range:         On TX: All enum valuse
//                 On RX: All enum values except 'IC_e_IMAGER_ALL'
//  
//  Parameter:     ps_Buffer  <IN/OUT>
//  Description:   Register transfer buffer for reading/writing data
//  
//  Parameter:     ui32_NumRegisters  <IN>
//  Description:   Number of registers which are requested to be read/written
//  
//  Parameter:     e_TransferMode  <IN>
//  Description:   Selects the register transfer mode (read or write)
//  
//  Parameter:     fct_Callback  <IN>
//  Description:   Callback function, which is called when the transfer completes. Setting this
//                 to 'NULL' will enable synchronous transfer mode, so this function blocks until
//                 all registers are read/written.
//  
//  Parameter:     ui8_TransferId  <IN>
//  Description:   Arbitrary transfer identification number, which identifies this transfer.
//                 It has to be passed back to 'fct_Callback' when the transfer completes.
//  Range:         0 - 255
/*#[ type IC_Fct_RegTransBuff */
typedef IC_E_RXTXERR (* IC_Fct_RegTransBuff)(const IC_E_Imager e_Imager, IC_S_RegDataPair * const ps_Buffer, const uint32 ui32_NumRegisters, const IC_E_TRANSFMODE e_TransferMode, IC_Fct_TransfCallback fct_Callback, const uint8 ui8_TransferId);
/*#]*/

//  Callback function which signals completion of measfreeze jobs
/*#[ type IC_Fct_MeasComplete */
typedef void (* IC_Fct_MeasComplete)(void);
/*#]*/

//  Function for doing measfreezes
/*#[ type IC_Fct_MeasFreeze */
typedef ICIF_E_MEASERR (* IC_Fct_MeasFreeze)(const uint8 ui8_CycleId, const uint32 ui32_VirtAddr, const void * pv_Buffer, const uint32 ui32_NumBytes, const uint8 ui8_MeasGroup);
/*#]*/

//  Function for reporting DEM status
/*#[ type IC_Fct_DemReport */
typedef boolean (* IC_Fct_DemReport)(const IC_E_DEM e_Dem, const IC_E_DEMSTATUS e_Status, const IC_Un_DemDtcExtData * pun_ExtData, const uint8 ui8_ExtDataBytes) ;
/*#]*/

//  Function for registering a ROI.
//  NOTE: Coordinates are referenced to the RAW-Image! So Y=18 means first optical active line.
/*#[ type IC_Fct_RoiRegister */
typedef ICIF_E_ROIERR (* IC_Fct_RoiRegister)(IC_t_RoiHandle * const pRh_Handle, IC_S_Roi const * const ps_Roi, const ICIF_E_ROIFRAMETYPE e_FrameType);
/*#]*/

//  Function for unregistering a ROI.
/*#[ type IC_Fct_RoiUnregister */
typedef ICIF_E_ROIERR (* IC_Fct_RoiUnregister)(IC_t_RoiHandle * const pRh_Handle);
/*#]*/

//  Function for setting new ECU systemtime. This is used in HIL-Mode to set system-time to
//  embedded timestamp from recording.
/*#[ type IC_Fct_ResyncSystemTime */
typedef void (* IC_Fct_ResyncSystemTime)(const sint64 si64_Time);
/*#]*/

//  Collection of service callback function pointers, which provide hardware- and runtime environment
//  specific functionalities. This functions must be implemented in the module, which sets up the
//  interface to the Imager Control (e.g. the 'Algo Adapter'). The callback functions are called from
//  within the IC.
/*## type IC_S_PlatformFuncs */
typedef struct IC_S_PlatformFuncs {
    //  Callback function, which blocks execution until a specific time passed
    IC_Fct_DelayUs pfct_v_DelayUs;		/*## attribute pfct_v_DelayUs */
    //  Callback function for getting current system time [us] (32-bit version)
    IC_Fct_GetTimeUs pfct_ui32_GetTimeUs;		/*## attribute pfct_ui32_GetTimeUs */
    //  Callback function for getting current system time [us] (64-bit version)
    IC_Fct_GetTimeUs64 pfct_ui64_GetTimeUs;		/*## attribute pfct_ui64_GetTimeUs */
    //  Callback function for setting trigger GPIO pin (aka 'EXPOSURE'-Pin), which is used to synchronize
    //  image timing of both imagers on stereo cameras.
    IC_Fct_SetTriggerPin pfct_v_SetTriggerPin;		/*## attribute pfct_v_SetTriggerPin */
    //  Callback function for controlling debug LED state
    IC_Fct_SetDebugLed pfct_v_SetDebugLed;		/*## attribute pfct_v_SetDebugLed */
    //  Callback function for setting imager analog test voltage
    IC_Fct_SetTestvoltage pfct_v_SetTestvoltage;		/*## attribute pfct_v_SetTestvoltage */
    //  Callback function for switching I2C timing / clock rate
    IC_Fct_SetI2CTiming pfct_v_SetI2CTiming;		/*## attribute pfct_v_SetI2CTiming */
    //  Callback function for queueing imager register transfers (read / write)
    IC_Fct_RegTransBuff pfct_RegTransBuff;		/*## attribute pfct_RegTransBuff */
    //  Callback function for reporting image characteristics and other data from IC part1 execution
    IC_Fct_ResultsPart1Avail pfct_ResultsPart1Available;		/*## attribute pfct_ResultsPart1Available */
    //  Callback function for reporting image statistics and other data from IC part2 execution
    IC_Fct_ResultsPart2Avail pfct_ResultsPart2Available;		/*## attribute pfct_ResultsPart2Available */
    //  Callback function for executing measfreezes
    IC_Fct_MeasFreeze pfct_MeasFreeze;		/*## attribute pfct_MeasFreeze */
    //  Callback function for reporting DEMs
    IC_Fct_DemReport pfct_b_DemReport;		/*## attribute pfct_b_DemReport */
    //  Callback function for registering ROIs, which have to be passed each frame to IC_e_LineFunc()
    IC_Fct_RoiRegister pfct_e_RoiRegister;		/*## attribute pfct_e_RoiRegister */
    //  Callback function for unregistering ROIs
    IC_Fct_RoiUnregister pfct_e_RoiUnregister;		/*## attribute pfct_e_RoiUnregister */
    //  Callback function that executed re-initialization (recovering) of the Imager Comm Bridge / I2C driver.
    IC_Fct_ReInitImgComm pfct_e_ReInitImgComm;		/*## attribute pfct_e_ReInitImgComm */
    //  Callback function, which is called in HIL mode to resynchronize ECU system time to embedded image timestamp
    IC_Fct_ResyncSystemTime pfct_v_ResyncSystemTime;		/*## attribute pfct_v_ResyncSystemTime */
    //  Callback function for getting statistical data from the underlaying Imager Comm Bridge / I2C driver
    IC_Fct_GetCommStats pfct_v_GetCommStats;		/*## attribute pfct_v_GetCommStats */
} IC_S_PlatformFuncs;

//  A list of commands which can be used to control the IC via XCP by using IC_e_ExternalControl()
/*#[ type ICIF_E_EXTCMD */
typedef enum
{                     
    // No operation, just ignore
    ICIF_e_EXTCMD_NOP,
                        
    // Unlocks the IC external control interface
    //
    //  byte[0] = KEY_BYTE0 (MSB)
    //  byte[1] = KEY_BYTE1
    //  byte[2] = KEY_BYTE2
    //  byte[3] = KEY_BYTE3 (LSB)
    ICIF_e_EXTCMD_UNLOCK,

    // Disable exposure regulation
    ICIF_e_EXTCMD_EXPOSURECTL_DISABLE,
    
    // (Re-)Enable exposure regulation
    ICIF_e_EXTCMD_EXPOSURECTL_ENABLE,

    // Dummy entry marking last valid command
    ICIF_e_EXTCMD__NUM_ENTRIES_
} ICIF_E_EXTCMD;
/*#]*/

/*## attribute IC_rh_ROIHANDLE_INVALID */
#define IC_rh_ROIHANDLE_INVALID ((IC_t_RoiHandle)0xFFFF)

/*## attribute ICIF_cui32_KEY_UNLOCK_CONTROL */
#define ICIF_cui32_KEY_UNLOCK_CONTROL 0x3872A9D5

/*## attribute ICIF_cui32_EXTCTL_ARGSIZE */
#define ICIF_cui32_EXTCTL_ARGSIZE 5

/***    User explicit entries    ***/


/* Operations */

//*****************************************************************************
//  Functionname:  IC_v_SetInput
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
//  Parameter:     const IC_S_Input * const ps_InputIn   <In>
//  Description:   Pointer to input data struct. The target structure contents must not
//                 change until the end of current frame!
//  Range:         none
//  Resolution:    none
//  Unit:          none
//    
//  
//  return         void
//**************************************************************************** */
/*## operation IC_v_SetInput(const IC_S_Input * const) */
void IC_v_SetInput(const IC_S_Input * const ps_InputIn);

//*****************************************************************************
//  Functionname:  IC_v_NewFrameStarted
//  
//  Description:
//    Tells the IC that a new frame has been started.
//  
//  Preconditions:
//    * IC must be initialized
//  
//  Postconditions:
//    none
//  
//  Parameter:     const uint16 ui16_FrameNum   <In>
//  
//  
//  Parameter:     const uint64 ui64_FrameTimestampIn   <In>
//  
//    
//  
//  return         void
//**************************************************************************** */
/*## operation IC_v_NewFrameStarted(const uint16,const uint64) */
void IC_v_NewFrameStarted(const uint16 ui16_FrameNum, const uint64 ui64_FrameTimestampIn);

//*****************************************************************************
//  Functionname:  IC_e_LineFunc
//  
//  Description:
//    This function must be called for each line of the ROIs, which have been registered by
//    the IC via callback 'pfct_e_RoiRegister'. It is the main cyclic execution entry point
//    of the Imager Control. All control functions are executed from within this function.
//    This includes, but is not limited to:
//      * Analyzing image data (embedded/statistics data, dark-rows)
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
//  Preconditions:
//    * Module must be initialized by calling 'IC_e_Init()'
//    * All callbacks passed to 'IC_e_Init()' must be ready for calling
//    * 'IC_v_NewFrameStarted()' must be called when a new frame has started
//    * 'IC_v_SetInput()'        must be called when a new frame has started
//  
//  Postconditions:
//    none
//  
//  Parameter:     const IC_E_FRAMETYPE e_FrameType   <In>
//  Description:   Current type of frame (even/odd)
//  Range:         (enum)
//  Resolution:    none
//  Unit:          none
//  
//  Parameter:     const uint16 ui16_LineNum   <In>
//  Description:   Line number of pointer target 'pui16_PixelData'
//  Range:         0 - 2^16
//  Resolution:    1
//  Unit:          lines
//  
//  Parameter:     const uint16 * const pui16_PixelData   <In>
//  Description:   Pointer to pixeldata of current line
//  Range:         none
//  Resolution:    none
//  Unit:          none
//    
//  
//  return         IC_E_ERROR
//**************************************************************************** */
/*## operation IC_e_LineFunc(const IC_E_FRAMETYPE,const uint16,const uint16 * const) */
IC_E_ERROR IC_e_LineFunc(const IC_E_FRAMETYPE e_FrameType, const uint16 ui16_LineNum, const uint16 * const pui16_PixelData);

//*****************************************************************************
//  Functionname:  IC_e_Init
//  
//  Description:
//    Initializes the Imager Control component (includes imager initialization).
//  
//    In summary this includes the following steps:
//      * Initializing submodules and internal data structures
//      * Reading image sensor model/revision -> unknown imagers will trigger an error!
//      * Execute imager BIST (build in self-test)
//      * Initializing image sensors, including register value verification
//      * Reading image sensor serial number (aka FuseIDs)
//      * Synchronization of imagers (on stereo cameras)
//  
//    When this function returns, the imagers will start streaming image data of fixed size
//    and fixed timing. To start exposure regulation and alternating image sizes/timing control,
//    IC_e_Start() has to be called after this function.
//  
//    IMPORTANT: Initializing imagers will take a significant amount of time, as the init-sequence
//    contains some explicit delays. This function should be called from a task context, which is
//    allowed to be blocked for a extended period of time!
//  
//    Function execution time:
//      * Mono Entry Cameras: tbd ms
//      * Mono Cameras:       tbd ms
//      * Stereo Cameras:     tbd ms
//  
//  Preconditions:
//    * Imager Comm Bridge (ICB) / I2C interface driver must be ready
//    * Imager(s) must be powered on
//    * Imager(s) reset bar must be released at least for 120ms
//    * Most functions passed via struct 'IC_S_PlatformFuncs' must be ready for calling
//      (however, pfct_e_RoiRegister / pfct_e_RoiUnregister are not used here)
//  
//  Postconditions:
//    * IC_e_Start() must be called to start IC
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
//  Description:   Setting this to 'b_TRUE' will enable HIL-Mode (see chapter in module description)
//  
//  Parameter:     const boolean b_DisableAnalogTest   <In>
//  Description:   Setting this to 'b_TRUE' will DISABLE imager analog path test during startup.
//    
//  
//  return         IC_E_ERROR
//**************************************************************************** */
/*## operation IC_e_Init(const IC_S_PlatformFuncs * const,const IC_S_StaticInput * const,const boolean,const boolean) */
IC_E_ERROR IC_e_Init(const IC_S_PlatformFuncs * const ps_PlatformFuncsIn, const IC_S_StaticInput * const ps_StaticInputIn, const boolean b_UseHilMode, const boolean b_DisableAnalogTest);

//*****************************************************************************
//  Functionname:  IC_e_DeInit
//  
//  Description:
//    Stops the Imager Control component. This triggers deregistering ROIs through the
//    callback function, which has been passed to 'IC_e_Init()'.
//  
//    NOTE: Imagers will _not_ be stopped here! This has to be done externally by asserting
//          reset bar or powering down the imager supply voltage.
//  
//  Preconditions:
//    * None (can be called any time)
//  
//  Postconditions:
//    * Cyclic functions must _not_ be called anymore
//    * Re-initialization is necessary before the IC can be used again
//    * Wait at least 20ms before powering down the imagers, as there may be ongoing
//      register transfers in the I2C driver buffers!
//  
//    
//  
//  return         IC_E_ERROR
//**************************************************************************** */
/*## operation IC_e_DeInit() */
IC_E_ERROR IC_e_DeInit(void);

//*****************************************************************************
//  Functionname:  IC_e_Start
//  
//  Description:
//    Starts the Imager Control component. This triggers registering ROIs through the
//    callback function, which has been passed to 'IC_e_Init()'.
//  
//  Preconditions:
//    * IC_e_Init() must have been called once each life-cycle
//  
//  Postconditions:
//    * Cyclic functions must be called, see top level activity chart for details
//  
//    
//  
//  return         IC_E_ERROR
//**************************************************************************** */
/*## operation IC_e_Start() */
IC_E_ERROR IC_e_Start(void);

//*****************************************************************************
//  Functionname:  IC_v_GetImagerCroi
//  
//  Description:
//    Returns the CROI (cropped image ROI) of a specific imager (left/right) and frame type (even/odd).
//    The CROIs are calculated during IC initialization and will not change afterwards, so this function
//    is usually only called once after init.
//  
//  Preconditions:
//    * IC must be initialized
//  
//  Postconditions:
//    none
//  
//  Parameter:     IC_S_Croi * const ps_Croi   <Out>
//  Description:   Will be filled with CROI data
//  
//  Parameter:     const IC_E_Imager e_ImagerTypeLR   <In>
//  Description:   The imager, whose CROI is returned
//  Range:         (enum): not 'IC_e_IMAGER_ALL' !
//  
//  Parameter:     const IC_E_FRAMETYPE e_FrameType   <In>
//  Description:   Type of frame, whose CROI will be returned
//  Range:         (enum)
//    
//  
//  return         void
//**************************************************************************** */
/*## operation IC_v_GetImagerCroi(IC_S_Croi * const,const IC_E_Imager,const IC_E_FRAMETYPE) */
void IC_v_GetImagerCroi(IC_S_Croi * const ps_Croi, const IC_E_Imager e_ImagerTypeLR, const IC_E_FRAMETYPE e_FrameType);

//*****************************************************************************
//  Functionname:  IC_e_GetTemperature
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
//    * The IC must have been executed at least for one frame since init (via IC_e_LineFunc)
//    * Left imager only: Left imager register data must be available (e.g. provided via IPC from
//      slave DSP) and must not be older than 'ICCFG_cui32_TEMPERATURE_MAXAGE_US.
//  
//  Postconditions:
//    none
//  
//  Parameter:     const IC_E_Imager e_Imager   <In>
//  Description:   Imager type, whose temperature is requested
//  Range:         (enum): _not_ IC_e_IMAGER_ALL
//  Resolution:    none
//  Unit:          none
//  
//  Parameter:     float32 * const pf32_Temp   <Out>
//  Description:   Target will be set to the requested imager's temperature
//  Range:         -100.0f ... +175.0f
//  Resolution:    varies
//  Unit:          °C
//  
//  Parameter:     uint64 * const pui64_TimeStamp   <Out>
//  Description:   Temperature sample timestamp
//  Range:         0 - 0xFFFFFFFFFFFFFFFF
//  Resolution:    1
//  Unit:          us
//    
//  
//  return         IC_E_ERROR
//**************************************************************************** */
/*## operation IC_e_GetTemperature(const IC_E_Imager,float32 * const,uint64 * const) */
IC_E_ERROR IC_e_GetTemperature(const IC_E_Imager e_Imager, float32 * const pf32_Temp, uint64 * const pui64_TimeStamp);

//*****************************************************************************
//  Functionname:  IC_v_GetSensorIDs
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
//  Parameter:     IC_S_SensorIDs * const ps_SensorIDs   <Out>
//  Description:   Pointer to output struct, which will be updated with sensor identification data
//  
//  Parameter:     const IC_E_Imager e_Imager   <In>
//  Description:   The imager, whose identification data is returned
//  Range:         (enum): not 'IC_e_IMAGER_ALL' !
//    
//  
//  return         void
//**************************************************************************** */
/*## operation IC_v_GetSensorIDs(IC_S_SensorIDs * const,const IC_E_Imager) */
void IC_v_GetSensorIDs(IC_S_SensorIDs * const ps_SensorIDs, const IC_E_Imager e_Imager);

//*****************************************************************************
//  Functionname:  IC_b_IsStableStateReached
//  
//  Description:
//    Returns information about the current state of the Imager Control. When the IC is in normal operation
//    mode (i.e. it's fully initialized and all startup tests are finished), it returns 'b_TRUE'.
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
/*## operation IC_b_IsStableStateReached() */
boolean IC_b_IsStableStateReached(void);

//*****************************************************************************
//  Functionname:  IC_e_SetTemporaryFixedExposureT1
//  
//  
//  
//  Parameter:     const uint16 ui16_T1_us   <In>
//  
//  
//  Parameter:     const uint32 ui32_NumFramesPersistence   <In>
//  
//    
//  
//  return         IC_E_ERROR
//**************************************************************************** */
/*## operation IC_e_SetTemporaryFixedExposureT1(const uint16,const uint32) */
IC_E_ERROR IC_e_SetTemporaryFixedExposureT1(const uint16 ui16_T1_us, const uint32 ui32_NumFramesPersistence);

//*****************************************************************************
//  Functionname:  IC_v_ResetTemporaryFixedExposureT1
//  
//  Description:
//    Stops 'Fixed Exposure Control'-Mode and goes back to normal exposure regulation mode.
//    See 'IC_e_SetTemporaryFixedExposureT1' for details about fixed exposure mode.
//  
//  Preconditions:
//    * IC must be initialized
//  
//  Postconditions:
//    none
//  
//    
//  
//  return         void
//**************************************************************************** */
/*## operation IC_v_ResetTemporaryFixedExposureT1() */
void IC_v_ResetTemporaryFixedExposureT1(void);

//*****************************************************************************
//  Functionname:  IC_v_SetTestpatternLeft
//  
//  Description:
//    Enables/disables left imager testpattern output. If enabled, the imager outputs a modified
//    walking-ones pattern instead of sampled pixel data.
//   
//  Preconditions:
//    * IC must be initialized
//  
//  Postconditions:
//    none
//  
//  Parameter:     const boolean b_Enabled   <In>
//  Description:   Enable flag
//  Range:         b_TRUE  - Enable testpattern output
//                 b_FALSE - Disable testpattern output
//    
//  
//  return         void
//**************************************************************************** */
/*## operation IC_v_SetTestpatternLeft(const boolean) */
#if (ICCFG_ENABLE_LEFT_IMAGER == 1)
void IC_v_SetTestpatternLeft(const boolean b_Enabled);
#endif

//*****************************************************************************
//  Functionname:  IC_e_SetAnalogTestParams
//  
//  Description:
//    Sets the analog test parameters, which are used when analog test execution is triggered
//    by calling 'IC_e_StartAnalogTest()'.
//   
//  Preconditions:
//    * IC must be initialized
//  
//  Postconditions:
//    none
//  
//  Parameter:     const IC_S_ATestExternParams * const ps_Params   <In>
//  Description:   Parameter set for analog test execution. The structure is copied to local memory and thus
//                 can be destroyed after the function returns.
//    
//  
//  return         IC_E_ERROR
//**************************************************************************** */
/*## operation IC_e_SetAnalogTestParams(const IC_S_ATestExternParams * const) */
#if (IC_ANALOG_TEST_ENABLED == 1)
IC_E_ERROR IC_e_SetAnalogTestParams(const IC_S_ATestExternParams * const ps_Params);
#endif

//*****************************************************************************
//  Functionname:  IC_e_StartAnalogTest
//  
//  Description:
//    Starts analog test execution. The test itself is executed in main entry function 'IC_e_LineFunc()'.
//    The test takes several frames to complete. The current status and result can be queried by calling
//    'IC_ps_GetATestResults()'.
//   
//  Preconditions:
//    * IC must be initialized
//    * IC is running ('IC_e_Start()' has been called)
//    * Analog test parameters are set by calling 'IC_e_SetAnalogTestParams()'
//  
//  Postconditions:
//    none
//  
//    
//  
//  return         IC_E_ERROR
//**************************************************************************** */
/*## operation IC_e_StartAnalogTest() */
#if (IC_ANALOG_TEST_ENABLED == 1)
IC_E_ERROR IC_e_StartAnalogTest(void);
#endif

//*****************************************************************************
//  Functionname:  IC_ps_GetATestResults
//  
//  Description:
//    Returns the current status of analog test execution.
//   
//  Preconditions:
//    * IC must be initialized
//  
//  Postconditions:
//    none
//  
//    
//  
//  return         IC_S_ATestResults * 
//**************************************************************************** */
/*## operation IC_ps_GetATestResults() */
#if (IC_ANALOG_TEST_ENABLED == 1)
IC_S_ATestResults * IC_ps_GetATestResults(void);
#endif

//*****************************************************************************
//  Functionname:  IC_e_RegTransAsyncWrite
//  
//  Description:
//    Schedules an asynchronous register read or write transfer. This is intended to be used
//    in production only (e.g. via XCP interface)!
//  
//  Preconditions:
//    * IC must be initialized and started (IC_e_Init(), IC_e_Start() called)
//  
//  Postconditions:
//    * Poll transfer results via IC_e_RegTransGetResults()
//  
//  Parameter:     const IC_E_Imager e_Imager   <In>
//  
//  
//  Parameter:     const uint16 ui16_RegisterAddress   <In>
//  
//  
//  Parameter:     const uint16 ui16_RegisterData   <In>
//  
//    
//  
//  return         IC_E_ERROR
//**************************************************************************** */
/*## operation IC_e_RegTransAsyncWrite(const IC_E_Imager,const uint16,const uint16) */
IC_E_ERROR IC_e_RegTransAsyncWrite(const IC_E_Imager e_Imager, const uint16 ui16_RegisterAddress, const uint16 ui16_RegisterData);

//*****************************************************************************
//  Functionname:  IC_e_RegTransAsyncRead
//  
//  Description:
//    Schedules an asynchronous register read or write transfer. This is intended to be used
//    in production only (e.g. via XCP interface)!
//  
//  Preconditions:
//    * IC must be initialized and started (IC_e_Init(), IC_e_Start() called)
//  
//  Postconditions:
//    * Poll transfer results via IC_e_RegTransGetResults()
//  
//  Parameter:     const IC_E_Imager e_Imager   <In>
//  
//  
//  Parameter:     const uint16 ui16_RegisterAddress   <In>
//  
//    
//  
//  return         IC_E_ERROR
//**************************************************************************** */
/*## operation IC_e_RegTransAsyncRead(const IC_E_Imager,const uint16) */
IC_E_ERROR IC_e_RegTransAsyncRead(const IC_E_Imager e_Imager, const uint16 ui16_RegisterAddress);

//*****************************************************************************
//  Functionname:  IC_v_RegTransGetResult
//  
//  
//  
//  Parameter:     IC_S_RegTransExtResult * ps_Result   <Out>
//  
//    
//  
//  return         void
//**************************************************************************** */
/*## operation IC_v_RegTransGetResult(IC_S_RegTransExtResult *) */
void IC_v_RegTransGetResult(IC_S_RegTransExtResult * ps_Result);

//*****************************************************************************
//  Functionname:  IC_e_ExternalControl
//  
//  
//  
//  Parameter:     const ICIF_E_EXTCMD e_Command   <In>
//  Description:   Command which is to be executed
//  Range:         (enum)
//  Resolution:    none
//  Unit:          none
//  
//  Parameter:     const uint8 %s[ICIF_cui32_EXTCTL_ARGSIZE] aui8_ControlSequence   <In>
//  Description:   Command arguments. Content format depends on command, see ICIF_E_EXTCMD
//  Range:         (varies)
//  Resolution:    (varies)
//  Unit:          (varies)
//    
//  
//  return         IC_E_ERROR
//**************************************************************************** */
/*## operation IC_e_ExternalControl(const ICIF_E_EXTCMD,const uint8 [ICIF_cui32_EXTCTL_ARGSIZE]) */
IC_E_ERROR IC_e_ExternalControl(const ICIF_E_EXTCMD e_Command, const uint8 aui8_ControlSequence[ICIF_cui32_EXTCTL_ARGSIZE]);

//*****************************************************************************
//  Functionname:  IC_ui32_GetVersion
//  
//  Description:
//    Returns the version number of the IC. It is 'BCD' encoded, so the number has to be
//    interpreted as following:
//  
//    0xAABBCCDD  ->  AA.BB.CC.DD
//  
//  Preconditions:
//    none
//  
//  Postconditions:
//    none
//  
//    
//  
//  return         uint32
//**************************************************************************** */
/*## operation IC_ui32_GetVersion() */
uint32 IC_ui32_GetVersion(void);

/***    User explicit entries    ***/



/*#[ ignore */

#ifdef __cplusplus
}
#endif

/*#]*/


#endif
/*********************************************************************
	File Path: ..\..\..\04_Engineering\01_Source_Code\Algo\ic\ic_interface.h
*********************************************************************/
