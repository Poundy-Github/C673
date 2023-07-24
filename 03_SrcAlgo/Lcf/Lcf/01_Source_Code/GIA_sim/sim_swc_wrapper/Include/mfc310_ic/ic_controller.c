//* **********************************************************************
//  COMPANY:         $CompanyInfo: CONFIDENTIAL AND PROPRIETARY PROPERTY OF CONTINENTAL AG , A.D.C. GmbH  -  ALL RIGHTS RESERVED $
//  
//  PROJECT:         MFC30x_MCU
//  CPU:             MPC5675K
//  
//  PACKAGE:         $Source: ic_controller.c $ $Revision: 1.1 $
//  MKS Date:        $Date: 2021/12/13 17:25:48CET $
//  
//  RHAPSODY:        7.5.3
//  COMPONENT:       IC
//  CONFIGURATION:   DefaultConfig
//  MODEL ELEMENT:   ic_controller
//  MODULNAME:       ..\..\..\04_Engineering\01_Source_Code\Algo\ic\ic_controller.c
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
//! CREATION DATE:   Wed, 14, Nov 2012  11:40 W. Europe Standard Time AM 
//**************************************************************************** */

/*## auto_generated */
#include "ic_controller.h"
/*## dependency ic_atest */
#include "ic_atest.h"
/*## dependency ic_cfg */
#include "ic_cfg.h"
/*## dependency ic_common */
#include "ic_common.h"
/*## dependency ic_driver */
#include "ic_driver.h"
/*## dependency ic_embdat_proc */
#include "ic_embdat_proc.h"
/*## dependency ic_errmanager */
#include "ic_errmanager.h"
/*## dependency ic_exposuremgr */
#include "ic_exposuremgr.h"
/*## dependency ic_globdefs */
#include "ic_globdefs.h"
/*## dependency ic_initdata */
#include "ic_initdata.h"
/*## dependency ic_noisecalc */
#include "ic_noisecalc.h"
/*## dependency ic_oswrapper */
#include "ic_oswrapper.h"
/*## dependency ic_profiling */
#include "ic_profiling.h"
/*## dependency ic_regmanager */
#include "ic_regmanager.h"
/*## dependency ic_responsecurve */
#include "ic_responsecurve.h"
/*## dependency ic_roi */
#include "ic_roi.h"
/*## dependency ic_testmanager */
#include "ic_testmanager.h"
/*## dependency ic_timing */
#include "ic_timing.h"
/*## package Ic_Pkg */

/*## class TopLevel::ic_controller */


/*#[ ignore */
#ifdef __cplusplus
extern "C"
{
#endif

/*#]*/


//  Sub-state of IC controller
/*#[ type ICCTL_E_EXEC_SUBSTATE */
typedef enum {
    ICCTL_e_EXECSTATE_PART1,
    ICCTL_e_EXECSTATE_PART2
}  ICCTL_E_EXEC_SUBSTATE;
/*#]*/

//  Main state of the IC controller
/*#[ type ICCTL_E_STATE */
typedef enum {
    ICCTL_e_STATE_INIT,
    ICCTL_e_STATE_WAIT_START,
    ICCTL_e_STATE_DATABUS_TEST,
#if (IC_ANALOG_TEST_ENABLED == 1)
    ICCTL_e_STATE_ANALOG_TEST,
#endif
    ICCTL_e_STATE_COLUMN_CORRECTION,
    ICCTL_e_STATE_RUNNING
}  ICCTL_E_STATE;
/*#]*/

//  State of startup column correction trigger functionality
/*#[ type ICCTL_E_COLCORR_STATE */
typedef enum {
  ICCTL_e_COLCORRSTATE_ENABLE_TRIGGER,
  ICCTL_e_COLCORRSTATE_CHANGE_DCG,
  ICCTL_e_COLCORRSTATE_DISABLE_TRIGGER,
  ICCTL_e_COLCORRSTATE_FINISHED
}  ICCTL_E_COLCORR_STATE;
/*#]*/

//  State of cyclic column correction trigger functionality
/*#[ type ICCTL_E_CYC_COLCORR_STATE */
typedef enum
{
    ICCTL_e_CYC_COLCORR_STATE_CHECK_CONDITION,
    ICCTL_e_CYC_COLCORR_STATE_EXECUTE,
    ICCTL_e_CYC_COLCORR_STATE_CLEANUP
}  ICCTL_E_CYC_COLCORR_STATE;
/*#]*/

//  Enumeration of IC input types used for timeout checks.
//  NOTE: Index must match with ICCTL_ae_InputTimeoutErrCodes[] !
/*#[ type ICCTL_E_INPUTTYPE */
typedef enum
{
    ICCTL_e_INPUTTYPE_VEHDYN,
#if (IC_ONLINECALIB_USE_LD == 1)
    ICCTL_e_INPUTTYPE_LDONLINECALIB,
#endif
#if (ICCFG_ENABLE_LEFT_IMAGER == 1)
    ICCTL_e_INPUTTYPE_IMGSYNC_REQ,
    ICCTL_e_INPUTTYPE_IMGSYNC_MEAS,
    ICCTL_e_INPUTTYPE_REGRESP,
#endif
    ICCTL_e_INPUTTYPE__NUM_ENTRIES__
}  ICCTL_E_INPUTTYPE;
/*#]*/

//  State/data storage for cyclic column correction functionality
/*## type ICCTL_S_CycColCorrData */
typedef struct ICCTL_S_CycColCorrData {
    float32 f32_LastColCorrTemp;		/*## attribute f32_LastColCorrTemp */
    uint32 ui32_LastColCorrTimeMs;		/*## attribute ui32_LastColCorrTimeMs */
    uint8 ui8_TriggerCount;		/*## attribute ui8_TriggerCount */
    ICCTL_E_CYC_COLCORR_STATE e_State;		/*## attribute e_State */
} ICCTL_S_CycColCorrData;

//  Stores execution time (runtime) and the line number of a specific line callback
/*## type ICCTL_S_LineDuration */
typedef struct ICCTL_S_LineDuration {
    uint16 ui16_LineNum;		/*## attribute ui16_LineNum */
    uint16 ui16_CalcTimeUs;		/*## attribute ui16_CalcTimeUs */
} ICCTL_S_LineDuration;

//  Stores execution runtimes and the most important timestamps of the IC execution cycle
/*## type ICCTL_S_TimingInfo */
typedef struct ICCTL_S_TimingInfo {
    ICCTL_S_LineDuration as_LineCbExecTime[ICCTL_cui32_LINECB_EXECTIME_ARRSIZE];		/*## attribute as_LineCbExecTime */
    uint32 ui32_Part1StartSinceFrameStartUs;		/*## attribute ui32_Part1StartSinceFrameStartUs */
    uint32 ui32_Part2StartSinceFrameStartUs;		/*## attribute ui32_Part2StartSinceFrameStartUs */
    uint32 ui32_FramePeriodEvenUs;		/*## attribute ui32_FramePeriodEvenUs */
    uint32 ui32_FramePeriodOddUs;		/*## attribute ui32_FramePeriodOddUs */
    uint16 ui16_Part1ExecDurationUs;		/*## attribute ui16_Part1ExecDurationUs */
    uint16 ui16_Part2ExecDurationUs;		/*## attribute ui16_Part2ExecDurationUs */
    uint16 ui16_I2CIsrExecDurationLastCycleUs;		/*## attribute ui16_I2CIsrExecDurationLastCycleUs */
    uint16 ui16_TotalExecDurationUs;		/*## attribute ui16_TotalExecDurationUs */
    sint16 si16_HilResyncOffset;		/*## attribute si16_HilResyncOffset */
} ICCTL_S_TimingInfo;

//  Execution counts for most important line callbacks. Can be used to detect line-drops
//  and wrong calling sequence.
/*## type ICCTL_S_CallbackCounters */
typedef struct ICCTL_S_CallbackCounters {
    uint16 ui16_CallbackCountReg0;		/*## attribute ui16_CallbackCountReg0 */
    uint16 ui16_CallbackCountReg1;		/*## attribute ui16_CallbackCountReg1 */
    uint16 ui16_CallbackCountEvenStat0;		/*## attribute ui16_CallbackCountEvenStat0 */
    uint16 ui16_CallbackCountEvenStat1;		/*## attribute ui16_CallbackCountEvenStat1 */
    uint16 ui16_CallbackCountOddStat0;		/*## attribute ui16_CallbackCountOddStat0 */
    uint16 ui16_CallbackCountOddStat1;		/*## attribute ui16_CallbackCountOddStat1 */
} ICCTL_S_CallbackCounters;

//  Debug / measurement data struct for the IC-Controller
/*## type ICCTL_S_MeasData */
typedef struct ICCTL_S_MeasData {
    ICCTL_S_CallbackCounters s_CallbackCounters;		/*## attribute s_CallbackCounters */
    uint16 ui16_TotalInitCnt;		/*## attribute ui16_TotalInitCnt */
    uint8 ui8_InitTryCnt;		/*## attribute ui8_InitTryCnt */
    ICCTL_E_STATE e_State;		/*## attribute e_State */
} ICCTL_S_MeasData;

//  Stores imager specific information, like model id, revision, serial number and temperature
/*## type ICCTL_S_ImagerInfos */
typedef struct ICCTL_S_ImagerInfos {
    IC_S_SensorIDs s_ImagerIdsRight;		/*## attribute s_ImagerIdsRight */
    #if (ICCFG_ENABLE_LEFT_IMAGER == 1)
    IC_S_SensorIDs s_ImagerIdsLeft;
    #endif		/*## attribute s_ImagerIdsLeft */
    float32 f32_TempRightC;		/*## attribute f32_TempRightC */
    #if (ICCFG_ENABLE_LEFT_IMAGER == 1)
    float32 f32_TempLeftC;
    #endif		/*## attribute f32_TempLeftC */
} ICCTL_S_ImagerInfos;

//  Stores debug context information in case corrupted embedded data has been detected
/*## type ICCTL_S_EmbdDataDebug */
typedef struct ICCTL_S_EmbdDataDebug {
    uint16 ui16_CorruptedLineNum;		/*## attribute ui16_CorruptedLineNum */
    sint16 si16_CorruptedLine_CpyOffset;		/*## attribute si16_CorruptedLine_CpyOffset */
    uint16 ui16_CorruptedLine_FailedPix;		/*## attribute ui16_CorruptedLine_FailedPix */
    uint16 aui16_CorruptedLineContext[ICCTL_cui32_EMBDDEBUG_CORRUPT_PIX_COPY];		/*## attribute aui16_CorruptedLineContext */
} ICCTL_S_EmbdDataDebug;

//  Top-level debug/measurement data structure, which is cyclically sent to MTS.
/*## type IC_S_MeasData */
typedef struct IC_S_MeasData {
    uint8 aui8_VersionNumber[(uint32)sizeof(uint32)];		/*## attribute aui8_VersionNumber */
    uint32 ui32_VersionNumber;		/*## attribute ui32_VersionNumber */
    uint32 IC_PREPROC_CONCAT(IC_Version_ , IC_TOPLEVEL_VERSION);		/*## attribute IC_Version_ */
    uint32 ui32_MeasCounter;		/*## attribute ui32_MeasCounter */
    uint64 ui64_MeasTimestamp;		/*## attribute ui64_MeasTimestamp */
    uint16 ui16_FrameCounterReg;		/*## attribute ui16_FrameCounterReg */
    uint16 ui16_FrameCounterStat;		/*## attribute ui16_FrameCounterStat */
    ICCTL_S_MeasData s_Controller;		/*## attribute s_Controller */
    ICCTL_S_TimingInfo s_TimingInfo;		/*## attribute s_TimingInfo */
    ICTIM_S_MeasData s_TimingManager;		/*## attribute s_TimingManager */
    ICEXPMG_S_MeasData s_ExposureManager;		/*## attribute s_ExposureManager */
    ICROI_S_MeasData s_RoiManager;		/*## attribute s_RoiManager */
    ICRM_S_MeasData s_RegisterManager;		/*## attribute s_RegisterManager */
    ICCTL_S_ImagerInfos s_ImagerInfos;		/*## attribute s_ImagerInfos */
    ICERR_S_MeasData s_ErrorManager;		/*## attribute s_ErrorManager */
    ICTM_S_MeasData s_TestManager;		/*## attribute s_TestManager */
    #if (IC_ANALOG_TEST_ENABLED == 1)
    ICAT_S_MeasData s_AnalogTest;
    #endif		/*## attribute s_AnalogTest */
    ICCTL_S_CycColCorrData s_CyclicColCorr;		/*## attribute s_CyclicColCorr */
    IC_S_EmbeddedRegData s_EmbeddedRegData;		/*## attribute s_EmbeddedRegData */
    IC_S_EmbeddedStatData s_EmbeddedStatData;		/*## attribute s_EmbeddedStatData */
    #if (IC_EXPOSURE_EVEN_MEASDATA == 1)
    IRCC_S_ResponseCurve s_ResponseCurveEven;
    #endif		/*## attribute s_ResponseCurveEven */
    IRCC_S_ResponseCurve s_ResponseCurveOdd;		/*## attribute s_ResponseCurveOdd */
    IMGNC_S_Results s_NoiseResultsEven;		/*## attribute s_NoiseResultsEven */
    IMGNC_S_Results s_NoiseResultsOdd;		/*## attribute s_NoiseResultsOdd */
    IC_S_Input s_Input;		/*## attribute s_Input */
    IC_S_StaticInput s_InputStatic;		/*## attribute s_InputStatic */
    IC_S_ResultsPart1 s_OutputPart1;		/*## attribute s_OutputPart1 */
    IC_S_ResultsPart2 s_OutputPart2;		/*## attribute s_OutputPart2 */
    ICCTL_S_EmbdDataDebug s_EmbeddedDataDebug;		/*## attribute s_EmbeddedDataDebug */
    uint32 ui32_MeasCounterBottomCheck;		/*## attribute ui32_MeasCounterBottomCheck */
    uint32 ui32_CDLCheck;		/*## attribute ui32_CDLCheck */
} IC_S_MeasData;/*!< @vaddr: 0x200bc000 @vname: IC_Common @cycleid: imagercontrol_cycle_id */

//  Number of cycles for which FuSi checks are disabled after initialization of the IC.
/*## attribute ICCTL_cui16_SKIPCHECKS_POSTINITCYCLES */
#define ICCTL_cui16_SKIPCHECKS_POSTINITCYCLES 2

//  Number of cycles for which FuSi checks are disabled after IC is running in normal execution mode
//  (all startup tests are done)
/*## attribute ICCTL_cui16_SKIPCHECKS_RUNNINGCYCLES */
#define ICCTL_cui16_SKIPCHECKS_RUNNINGCYCLES 2

//  Number of cycles for which providing results to external is skipped after IC
//  is running in normal execution mode
/*## attribute ICCTL_cui16_SKIPRESULTS_RUNNINGCYCLES */
#define ICCTL_cui16_SKIPRESULTS_RUNNINGCYCLES 2

//  Number of frames for which IC part2 execution will be skipped after IC init
/*## attribute ICCTL_cui16_SKIPPART2EXEC_POSTINITCYCLES */
#define ICCTL_cui16_SKIPPART2EXEC_POSTINITCYCLES 2

//  Number of frames after which the IC is considered to be stable and other algos are allowed to be executed
/*## attribute ICCTL_cui16_STABLESTATE_POSTEXECCYCLES */
#define ICCTL_cui16_STABLESTATE_POSTEXECCYCLES 4

//  First line of TOP image data ROI, which will be registered for pixeldata reception
/*## attribute ICCTL_cui16_TOPROI_STARTY */
#define ICCTL_cui16_TOPROI_STARTY 8u

//  Height of TOP image data ROI, which will be registered for pixeldata reception
/*## attribute ICCTL_cui16_TOPROI_HEIGHT */
#define ICCTL_cui16_TOPROI_HEIGHT 10u

//  Unique identifier for measurement group 'Common IC Data'
/*## attribute ICCTL_ui8_MEASGROUP_IC_COMMON */
#define ICCTL_ui8_MEASGROUP_IC_COMMON 0

//  Unique identifier for measurement group 'Exposure Control Measurement Data'
/*## attribute ICCTL_ui8_MEASGROUP_IC_EXPOSURE */
#define ICCTL_ui8_MEASGROUP_IC_EXPOSURE 1

//  Name of this module, required for calls to ICERR_HANDLE().
//  
//  Character string is only used for debugging & recording analysis, so suppress QAC warnings:
//  PRQA S 5013,3625 3
/*## attribute pch_ModuleName */
static const char * const pch_ModuleName = "CONTRL";

//  Storage for image data (histogram and interpreted/converted data)
/*## attribute ICCTL_s_ImageData */
static IC_S_ImageDataContainer ICCTL_s_ImageData;

//  Current state of the imager control
/*## attribute ICCTL_e_State */
static ICCTL_E_STATE ICCTL_e_State = ICCTL_e_STATE_INIT;

//  Current substate of the imager control adapter
/*## attribute ICCTL_e_ExecSubstate */
static ICCTL_E_EXEC_SUBSTATE ICCTL_e_ExecSubstate = ICCTL_e_EXECSTATE_PART1;

//  Number of IC initializations
/*## attribute ICCTL_ui16_InitCnt */
static uint16 ICCTL_ui16_InitCnt = 0;

//  Flags successful initialization
/*## attribute ICCTL_b_Initialized */
static boolean ICCTL_b_Initialized = b_FALSE;

//  Flag indicates successful registered ROIs and running IA/ROI callbacks
/*## attribute ICCTL_b_Started */
static boolean ICCTL_b_Started = b_FALSE;

//  Result from databus test
/*## attribute ICCTL_e_DBusTestResult */
static ICTM_E_DBUS_RESULT ICCTL_e_DBusTestResult = ICTM_e_DBUS_RESULT_NOT_FINISHED;

//  The object for the imager response curve calculation
/*## attribute ICCTL_s_IRCCObj */
static IRCC_S_Obj ICCTL_s_IRCCObj;

//  PPARs for the imager response curve calculation
/*## attribute ICCTL_ps_IRCCPPARs */
static const IRCC_S_PPARs * ICCTL_ps_IRCCPPARs;

//  Output/results of the imager response curve
/*## attribute ICCTL_as_ResponseCurve */
static IRCC_S_ResponseCurve ICCTL_as_ResponseCurve[IC_cui16_NumFrameTypes];

//  Stores results of noise calculation
/*## attribute ICCTL_s_NCResults */
static IMGNC_S_Results ICCTL_s_NCResults;

//  Objects for noise calculation and blacklevel estimation
/*## attribute ICCTL_as_IMGNCObj */
static IMGNC_S_Obj ICCTL_as_IMGNCObj[IC_cui16_NumFrameTypes];

//  Data from cyclic column correction trigger mechanism
/*## attribute ICCTL_s_CycColCorrData */
static ICCTL_S_CycColCorrData ICCTL_s_CycColCorrData;

//  Timestamp of FrameValid high edge in current frame
/*## attribute ICCTL_ui64_FrameStartUs */
static uint64 ICCTL_ui64_FrameStartUs = 0;

//  If the temperature has this value, the real temperature is not available
/*## attribute ICCTL_cf32_TEMP_NOT_AVAILABLE_INDICATOR */
#define ICCTL_cf32_TEMP_NOT_AVAILABLE_INDICATOR (-1024.0f)

//  Timestamp of FrameValid high edge in previous frames
/*## attribute ICCTL_aui32_LastFrameStartUs */
static uint32 ICCTL_aui32_LastFrameStartUs[IC_cui16_NumFrameTypes] = { 0, 0 };

//  Stores an externally setable byte that is included into the FrameID field of the
//  Image-Statistics-Data
/*## attribute ICCTL_aui8_FrameIdMSB */
static uint8 ICCTL_aui8_FrameIdMSB[ICCFG_NUM_IMAGERS];

//  Stores the current temperatures of the imagers
/*## attribute ICCTL_af32_ImagerTemperatures */
static float32 ICCTL_af32_ImagerTemperatures[ICCFG_NUM_IMAGERS] = {
    ICCTL_cf32_TEMP_NOT_AVAILABLE_INDICATOR,
#if (ICCFG_ENABLE_LEFT_IMAGER == 1)
    ICCTL_cf32_TEMP_NOT_AVAILABLE_INDICATOR
#endif
};

//  Stores timestamps of imager temperatures
/*## attribute ICCTL_aui64_ImagerTempTimeStamps */
static uint64 ICCTL_aui64_ImagerTempTimeStamps[ICCFG_NUM_IMAGERS];

//  Error codes for input timeouts
//  !!! IMPORTANT: Index must map to ICCTL_E_INPUTTYPE !!!
/*## attribute ICCTL_cae_InputTimeoutErrCodes */
static const IC_E_ERROR ICCTL_cae_InputTimeoutErrCodes[ICCTL_e_INPUTTYPE__NUM_ENTRIES__] = {
    IC_e_ERR_INPUTTIMEOUT_VDY,
#if (IC_ONLINECALIB_USE_LD == 1)
    IC_e_ERR_INPUTTIMEOUT_LDONLINECALIB,
#endif
#if (ICCFG_ENABLE_LEFT_IMAGER == 1)
    IC_e_ERR_INPUTTIMEOUT_IMGSYNC_REQ,
    IC_e_ERR_INPUTTIMEOUT_IMGSYNC_MEAS,
    IC_e_ERR_INPUTTIMEOUT_LEFTREGRESPONSE,
#endif
    // PRQA S 3111 1
};

//  Last receive timestamps of input signals (stamped when received from IC)
/*## attribute ICCTL_ui64_LastInputRecvTime */
static uint64 ICCTL_ui64_LastInputRecvTime[ICCTL_e_INPUTTYPE__NUM_ENTRIES__];

//  Last source timestamps of input signals (stamped at data source)
/*## attribute ICCTL_ui64_LastInputSrcTime */
static uint64 ICCTL_ui64_LastInputSrcTime[ICCTL_e_INPUTTYPE__NUM_ENTRIES__];

//  Tells us if new data is available for a specific data-type
/*## attribute ICCTL_ab_InputUpdated */
static uint64 ICCTL_ab_InputUpdated[ICCTL_e_INPUTTYPE__NUM_ENTRIES__];

//  Counter number of measurement data cycles
/*## attribute ICCTL_ui32_MeasCounter */
static uint32 ICCTL_ui32_MeasCounter = 0;

//  Current frame number
/*## attribute ICCTL_ui16_FrameNum */
static uint16 ICCTL_ui16_FrameNum = 0;

//  Line-number from last callback
/*## attribute ICCTL_ui16_LastLineNum */
static uint16 ICCTL_ui16_LastLineNum = 0;

//  Last known frame number after last execution
/*## attribute ICCTL_ui16_OldFrameCounter */
static uint16 ICCTL_ui16_OldFrameCounter = 0;

//  This counts the number of cycles after initialization
/*## attribute ICCTL_ui16_PostInitExecCount */
static uint16 ICCTL_ui16_PostInitExecCount = 0;

//  This counts the number of cycles after normal running mode has been entered
/*## attribute ICCTL_ui16_RunningModeExecCount */
static uint16 ICCTL_ui16_RunningModeExecCount = 0;

//  Timestamp when IC was first started
/*## attribute ICCTL_ui64_IcStartTimestamp */
static uint64 ICCTL_ui64_IcStartTimestamp = 0;

//  Total runtime of all line-callbacks
/*## attribute ICCTL_ui16_AccumulativeRuntime */
static uint16 ICCTL_ui16_AccumulativeRuntime = 0;

//  Current index in individual line-callback-runtime measurement data array
/*## attribute ICCTL_ui16_LineCbDurationIndex */
static uint16 ICCTL_ui16_LineCbDurationIndex = 0;

//  Current frame type (even/odd)
/*## attribute ICCTL_e_FrameType */
static IC_E_FRAMETYPE ICCTL_e_FrameType = IC_e_FRAMETYPE_ODD;

//  Next (following) frame type (even/odd)
/*## attribute ICCTL_e_FrameTypeOther */
static IC_E_FRAMETYPE ICCTL_e_FrameTypeOther = IC_e_FRAMETYPE_EVEN;

//  Actual calculated position and sizes of the imager control ROIs (in pixels)
/*## attribute ICCTL_s_ICRois */
static IC_S_Roi ICCTL_s_ICRois[IC_cui16_NumFrameTypes];

//  Results from Part1 execution (embedded data processing)
/*## attribute ICCTL_as_ResultsPart1 */
static IC_S_ResultsPart1 ICCTL_as_ResultsPart1[IC_cui16_NumFrameTypes];

//  Results from Part2 execution (statistics data processing)
/*## attribute ICCTL_as_ResultsPart2 */
static IC_S_ResultsPart2 ICCTL_as_ResultsPart2[IC_cui16_NumFrameTypes];

//  Results from imager exposure control
/*## attribute ICCTL_as_IcExpResults */
static ICEXPMG_S_Results ICCTL_as_IcExpResults[IC_cui16_NumFrameTypes];

//  Measurement data for imager control component (excluding exposure control
//  submodule even/odd) which are send separate
/*## attribute IC_s_MeasData */
static IC_S_MeasData IC_s_MeasData;

//  Marks register data as corrupt
/*## attribute ICCTL_b_CorruptedRegs */
static boolean ICCTL_b_CorruptedRegs = b_FALSE;

//  Variable stores current state of the debug LED
/*## attribute ICCTL_b_LedToggleFlag */
static boolean ICCTL_b_LedToggleFlag = b_TRUE;

//  Setting this variable to 'b_TRUE' will trigger analog test execution on next cycle
/*## attribute ICCTL_b_ATestExternalTrigger */
static boolean ICCTL_b_ATestExternalTrigger = b_FALSE;

//  Setting this variable to 'b_TRUE' will enable left imager testpattern on next cycle
/*## attribute ICCTL_b_EnableTestpatternLeft */
static boolean ICCTL_b_EnableTestpatternLeft = b_FALSE;

//  Setting this variable to 'b_TRUE' will disable left imager testpattern on next cycle
/*## attribute ICCTL_b_DisableTestpatternLeft */
static boolean ICCTL_b_DisableTestpatternLeft = b_FALSE;

//  Setting this variable to 'b_TRUE' will force a change of the imagers 'DCG' bit.
//  This is used to trigger the imagers internal column noise correction algo.
/*## attribute ICCTL_b_ForceDcgChange */
static boolean ICCTL_b_ForceDcgChange = b_FALSE;

//  Forces setting the exposure controlling registers to their initial values
/*## attribute ICCTL_b_ExposureRegsSetToInit */
static boolean ICCTL_b_ExposureRegsSetToInit = b_FALSE;

//  Current state of the startup column correction trigger function
/*## attribute ICCTL_e_ColCorrState */
static ICCTL_E_COLCORR_STATE ICCTL_e_ColCorrState = ICCTL_e_COLCORRSTATE_ENABLE_TRIGGER;

//  Delay, which will be waited after the IC has reset the imagers using soft-reset
/*## attribute ICCTL_cui32_SoftResetDelayUs */
static const uint32 ICCTL_cui32_SoftResetDelayUs = 66000;

//  Delay, which will be waited before the IC talks (register read/write) to the imagers on init.
//  NOTE: There is also a delay in the PMC, which is inserted after imager reset (nominal 30ms,
//  but varies heavily). Both delays add and should not be lower than 66ms according to the imager
//  vendor Aptina.
/*## attribute ICCTL_cui32_ImagerInitDelayUs */
static const uint32 ICCTL_cui32_ImagerInitDelayUs = 40000;

//  Pointer to callback which is called when analog test is finished
/*## attribute ICCTL_pfct_ATestFinishedCb */
static IC_Fct_ATestFinishedCb ICCTL_pfct_ATestFinishedCb = NULL;

//  Pointer to the current frames' input register data buffer
/*## attribute ICCTL_pRb_RegsInR */
static IC_S_RegBuff * ICCTL_pRb_RegsInR = NULL;

//  Pointer to the current frames' image data
/*## attribute ICCTL_ps_ImageData */
static IC_S_ImageDataContainer * ICCTL_ps_ImageData = 0;

//  Pointer to the current frames' embedded data
/*## attribute ICCTL_ps_EmbeddedData */
static IC_S_EmbeddedRegData * ICCTL_ps_EmbeddedData = 0;

//  Pointer to the current frames' statistical data (extracted from embedded statistics)
/*## attribute ICCTL_ps_StatisticsData */
static IC_S_EmbeddedStatData * ICCTL_ps_StatisticsData = 0;

//  Pointer to the current frames' imager reponse curve
/*## attribute ICCTL_ps_ResponseCurve */
static IRCC_S_ResponseCurve * ICCTL_ps_ResponseCurve = 0;

//  Pointer to the current frames' noise calculation instance
/*## attribute ICCTL_ps_NCObj */
static IMGNC_S_Obj * ICCTL_ps_NCObj = 0;

//  Pointer to the current frames' input data
/*## attribute ICCTL_ps_Input */
static const IC_S_Input * ICCTL_ps_Input;

//  Pointer to the current frames' first embedded data line
/*## attribute ICCTL_pui16_EmbDatLine0 */
static const uint16 * ICCTL_pui16_EmbDatLine0 = 0;

//  Pointer to the current frames' second embedded data line
/*## attribute ICCTL_pui16_EmbDatLine1 */
static const uint16 * ICCTL_pui16_EmbDatLine1 = 0;

//  Pointer to the current frames' first statistics data line
/*## attribute ICCTL_pui16_EmbStatLine0 */
static const uint16 * ICCTL_pui16_EmbStatLine0 = 0;

//  Pointer to the current frames' second statistics data line
/*## attribute ICCTL_pui16_EmbStatLine1 */
static const uint16 * ICCTL_pui16_EmbStatLine1 = 0;

//  This is a unique value that is used to disable analog test on startup. This is resistant to illegal memory-overwrites.
/*## attribute ICCTL_cui32_KEY_ATEST_DISABLE */
#define ICCTL_cui32_KEY_ATEST_DISABLE 0x6903CCABu

//  This is a unique value that is used to disable analog test on startup. This is resistant to illegal memory-overwrites.
/*## attribute ICCTL_cui32_KEY_EXPOSURE_DISABLE */
#define ICCTL_cui32_KEY_EXPOSURE_DISABLE 0xAC845BE3u

//  This is a unique value that is used to disable analog test on startup. This is resistant to illegal memory-overwrites.
/*## attribute ICCTL_cui32_KEY_REGCHECKS_DISABLE */
#define ICCTL_cui32_KEY_REGCHECKS_DISABLE 0x89052CADu

//  Pointer to platform service functions, which are passed on init
/*## attribute ICCTL_ps_PlatformFuncs */
static const IC_S_PlatformFuncs * ICCTL_ps_PlatformFuncs = 0;

//  Used to disable I2C and several checks on HIL
/*## attribute ICCTL_ui32_HILModeEnabled */
static uint32 ICCTL_ui32_HILModeEnabled = 0;

//  Skip analog test on startup (e.g. used for <C0 samples)
/*## attribute ICCTL_ui32_SkipAnalogTest */
static uint32 ICCTL_ui32_SkipAnalogTest = 0;

//  Used to disable exposure regulation and writing exposure relevant registers to the imagers.
//  This is not allowed to be used during normal operation!
/*## attribute ICCTL_ui32_IcExposureDisabled */
static uint32 ICCTL_ui32_IcExposureDisabled = 0;

//  Used to disable cyclic register checks. This is not allowed to be used during normal operation!
/*## attribute ICCTL_ui32_RegChecksDisabled */
static uint32 ICCTL_ui32_RegChecksDisabled = 0;

//  Marks first signal reception of 'Image Sync Request' (part of IC inputs)
/*## attribute ICCTL_b_ImgSyncReqReceived */
static boolean ICCTL_b_ImgSyncReqReceived = b_FALSE;

//*****************************************************************************
//  Functionname:  ICCTL_b_HILMODE_ACTIVE
//  
//  Macro for detecting whether we are running on HIL.
//  
//    
//  
//  return         RhpString
//**************************************************************************** */
/*## operation ICCTL_b_HILMODE_ACTIVE() const */
#define ICCTL_b_HILMODE_ACTIVE()    \
    ((IC_cui32_KEY_HILMODE == ICCTL_ui32_HILModeEnabled) ? b_TRUE : b_FALSE) // PRQA S 3429

//*****************************************************************************
//  Functionname:  ICCTL_e_InitImagers
//  
//  Description:
//    Initializes the imagers. In summary this includes the following steps:
//      * Reading image sensor model/revision -> unknown imagers will trigger an error!
//      * Execute imager BIST (build in self-test)
//      * Initializing image sensors, including register value verification
//      * Reading image sensor serial number (aka FuseIDs)
//      * Synchronization of imagers (on stereo cameras)
//  
//    When this function returns, the imagers will start streaming image data of fixed
//    size and fixed timing. To start exposure regulation and alternating image sizes/
//    timing control, ICCTL_e_Start() has to be called after this function.
//  
//    IMPORTANT: Initializing imagers will take a significant amount of time, as the
//    init-sequence contains some explicit delays. This function should be called from
//    a task context, which is allowed to be blocked for a extended period of time
//    (several 100ms)!
//  
//  Preconditions:
//    * Imager Comm Bridge (ICB) / I2C interface driver must be ready
//    * Imager(s) must be powered on
//    * Imager(s) reset bar must be released at least for 120ms
//  
//    
//  
//  return         IC_E_ERROR
//**************************************************************************** */
/*## operation ICCTL_e_InitImagers() */
static IC_E_ERROR ICCTL_e_InitImagers(void);

//*****************************************************************************
//  Functionname:  ICCTL_e_ExecPart1
//  
//  Description:
//    This is the first of two main IC execution functions, which has to be called
//    cyclic when embedded register data is available for the current frame. It
//    extracts register data, calculates image characteristics, executes the majority
//    of the FuSi checks and schedules writing of new register data to the imagers.
//  
//    See activity diagram for details on what's actually done here in detail.
//  
//  Preconditions:
//    * IC must be initialized and started
//    * If this is not the very first frame: ICCTL_e_ExecPart2() must have been called
//      in previous frame - otherwise an error is reported, but function continues
//      execution.
//  
//  Postconditions:
//    * ICCTL_e_ExecPart2() must be called at the end of this frame
//  
//  
//    
//  
//  return         IC_E_ERROR
//**************************************************************************** */
/*## operation ICCTL_e_ExecPart1() */
static IC_E_ERROR ICCTL_e_ExecPart1(void);

//*****************************************************************************
//  Functionname:  ICCTL_e_ExecPart2
//  
//  Description:
//    This is the second of two main IC execution functions, which has to be called
//    cyclic when embedded statistics data is available for the current frame. It
//    extracts statistics data, does a few FuSi checks, and mainly executes the imager
//    exposure control module, which calculates new values for brightness influencing
//    register values. The new register values are written to the imager and finally
//    all debug data is measfreezed.
//    
//    See activity diagram for details on what's actually done here in detail.
//  
//  Preconditions:
//    * IC must be initialized and started
//    * ICCTL_e_ExecPart1() must have been called during the current frame
//  
//  
//  Parameter:     const uint16 * const pui16_EmbStatLine0   <In>
//  
//  
//  Parameter:     const uint16 * const pui16_EmbStatLine1   <In>
//  
//    
//  
//  return         IC_E_ERROR
//**************************************************************************** */
/*## operation ICCTL_e_ExecPart2(const uint16 * const,const uint16 * const) */
static IC_E_ERROR ICCTL_e_ExecPart2(const uint16 * const pui16_EmbStatLine0, const uint16 * const pui16_EmbStatLine1);

//*****************************************************************************
//  Functionname:  ICCTL_v_ProvideResultsPart1
//  
//  Description:
//    Provides results of 'Part1' execution to other algos by executing platform
//    callback and passing a pointer to the results as argument. This includes
//    mainly image characteristic data.
//  
//  Preconditions:
//    * ICCTL_e_ExecPart1() must have been called for current frame
//  
//  Parameter:     IC_S_ResultsPart1 * const ps_Results   <In>
//  
//    
//  
//  return         void
//**************************************************************************** */
/*## operation ICCTL_v_ProvideResultsPart1(IC_S_ResultsPart1 * const) */
static void ICCTL_v_ProvideResultsPart1(IC_S_ResultsPart1 * const ps_Results);

//*****************************************************************************
//  Functionname:  ICCTL_v_ProvideResultsPart2
//  
//  Description:
//    Provides results of 'Part2' execution to other algos by executing platform
//    callback and passing a pointer to the results as argument. This includes
//    mainly statistical image data, like image brightness.
//  
//  Preconditions:
//    * ICCTL_e_ExecPart2() must have been called for current frame
//  
//  Parameter:     IC_S_ResultsPart2 * const ps_Results   <In>
//  
//    
//  
//  return         void
//**************************************************************************** */
/*## operation ICCTL_v_ProvideResultsPart2(IC_S_ResultsPart2 * const) */
static void ICCTL_v_ProvideResultsPart2(IC_S_ResultsPart2 * const ps_Results);

//*****************************************************************************
//  Functionname:  ICCTL_v_CheckNewInputs
//  
//  Description:
//    Checks input data and does the following tasks:
//      * Check signal timeouts (period, first signal reception)
//      * Mark updated input signals as 'new' (update ICCTL_ab_InputUpdated)
//  
//  Preconditions:
//    * IC must be initialized and in state 'RUNNING'
//  
//  Outputs:
//    * ICCTL_ab_InputUpdated
//    * ICCTL_ui64_LastInputSrcTime
//    * ICCTL_ui64_LastInputRecvTime
//    * ICCTL_b_ImgSyncReqReceived
//  
//  Parameter:     const IC_S_Input * const ps_In   <In>
//  
//  
//  Parameter:     const uint64 ui64_CurrentTimeUs   <In>
//  
//    
//  
//  return         void
//**************************************************************************** */
/*## operation ICCTL_v_CheckNewInputs(const IC_S_Input * const,const uint64) */
static void ICCTL_v_CheckNewInputs(const IC_S_Input * const ps_In, const uint64 ui64_CurrentTimeUs);

//*****************************************************************************
//  Functionname:  ICCTL_v_StateTransition
//  
//  Description:
//    Executes state transition logic. This function has to be called at least each
//    frame before IC 'Part1' is executed.
//  
//    See state chart 'MainStateMachine' for details.
//  
//  Preconditions:
//    none
//  
//    
//  
//  return         void
//**************************************************************************** */
/*## operation ICCTL_v_StateTransition() */
static void ICCTL_v_StateTransition(void);

//*****************************************************************************
//  Functionname:  ICCTL_e_ExtractRegs
//  
//  Description:
//    Extracts register data from embedded data lines. It also checks consistency/the
//    format of the embedded data, so corrupted data is detected and reported. In case
//    corrupted data is detected, no extraction is performed, but frame-counter register
//    is updated!
//  
//    The function updates data pointers which are used in other ICCTL functions and
//    also passes extracted registers to the imager driver, which uses them as input
//    for all IMGDRV_*_Get*() functions.
//  
//  Parameter:     const uint16 * const pui16_EmbDatLine0   <In>
//  
//  
//  Parameter:     const uint16 * const pui16_EmbDatLine1   <In>
//  
//    
//  
//  return         IC_E_ERROR
//**************************************************************************** */
/*## operation ICCTL_e_ExtractRegs(const uint16 * const,const uint16 * const) */
static IC_E_ERROR ICCTL_e_ExtractRegs(const uint16 * const pui16_EmbDatLine0, const uint16 * const pui16_EmbDatLine1);

//*****************************************************************************
//  Functionname:  ICCTL_e_SetCroi
//  
//  Description:
//    Passes the CROI settings (image start position / size) for the current frame
//    type to the imager driver. It will be valid after two frames, which has the
//    same frame type as the current image is.
//  
//  Postconditions:
//    * Register data must be flushed for writing changes to the imagers
//  
//    
//  
//  return         IC_E_ERROR
//**************************************************************************** */
/*## operation ICCTL_e_SetCroi() */
static IC_E_ERROR ICCTL_e_SetCroi(void);

//*****************************************************************************
//  Functionname:  ICCTL_v_ExecColumnCorrection
//  
//  Description:
//    Forces the imager to execute column noise correction algorithm. This function
//    is intended to be executed on startup. Execution has it's own state machine, 
//    which takes several cycles to finish.
//  
//    See state chart 'ColumnCorrectionStartup' for details.
//  
//  Preconditions:
//    * IC must be initialized and started
//    * Exposure control must not be running yet: DCG is not allowed to be changed
//      externally when column correction is executed
//  
//  
//    
//  
//  return         void
//**************************************************************************** */
/*## operation ICCTL_v_ExecColumnCorrection() */
static void ICCTL_v_ExecColumnCorrection(void);

//*****************************************************************************
//  Functionname:  ICCTL_v_ExecColCorrCyclic
//  
//  Description:
//    Executes cyclic column correction trigger logic. It forces the imager to execute
//    column noise correction when certain conditions are met, which primarily depends
//    on the imager temperture.
//  
//    See state statechart 'ColumnCorrectionCyclic' for details.
//  
//  Preconditions:
//    * IC must be initialized and in state 'RUNNING'
//  
//    
//  
//  return         void
//**************************************************************************** */
/*## operation ICCTL_v_ExecColCorrCyclic() */
static void ICCTL_v_ExecColCorrCyclic(void);

//*****************************************************************************
//  Functionname:  ICCTL_v_NewRegDataChecks
//  
//  Description:
//    Executes FuSi checks based on extracted embedded register data. This includes:
//      * Checking frame number increment
//      * Checking extracted register values against written values ('register checks')
//      * Checking critical registers against constants
//      * Checking IC-ROI position/size against expected values, which have been
//        calculated on previous frame
//  
//  Preconditions:
//    * Embedded register data must have been extracted   (ICCTL_ps_EmbeddedData)
//  
//    
//  
//  return         void
//**************************************************************************** */
/*## operation ICCTL_v_NewRegDataChecks() */
static void ICCTL_v_NewRegDataChecks(void);

//*****************************************************************************
//  Functionname:  ICCTL_e_NewStatDataChecks
//  
//  Description:
//    Executes FuSi checks based on extracted embedded statistics data. This includes:
//      * Compare framecounters from embedded statistics vs. embedded register
//      * Check custom FrameId against written value
//      * Check custom FrameId LSB against frame counter LSB
//  
//  Preconditions:
//    * Embedded statistics data must have been extracted (ICCTL_ps_StatisticsData)
//    * Embedded register data must have been extracted   (ICCTL_ps_EmbeddedData)
//  
//    
//  
//  return         IC_E_ERROR
//**************************************************************************** */
/*## operation ICCTL_e_NewStatDataChecks() */
static IC_E_ERROR ICCTL_e_NewStatDataChecks(void);

//*****************************************************************************
//  Functionname:  ICCTL_e_CalcImageStuff
//  
//  Description:
//    Calculates characteristics for the current image. This includes:
//      * Noise Level (precalculations are already done prior in line callbacks)
//      * Blacklevel
//      * Imager response curve
//  
//  Preconditions:
//    * Register data must have been extracted for the current frame.
//  
//  Outputs:
//    * ICCTL_s_NCResults
//    * ICCTL_ps_ResponseCurve
//  
//    
//  
//  return         IC_E_ERROR
//**************************************************************************** */
/*## operation ICCTL_e_CalcImageStuff() */
static IC_E_ERROR ICCTL_e_CalcImageStuff(void);

//*****************************************************************************
//  Functionname:  ICCTL_v_ExecMeasfreeze
//  
//  Description:
//    Measfreezes all collected debug data.
//    
//  Preconditions:
//    * All debug data, which shall be contained in the measfreeze, must be available
//      in 'IC_s_MeasData'
//  
//    
//  
//  return         void
//**************************************************************************** */
/*## operation ICCTL_v_ExecMeasfreeze() */
static void ICCTL_v_ExecMeasfreeze(void);

//*****************************************************************************
//  Functionname:  ICCTL_v_ExecMeasfreezeExposure
//  
//  Description:
//    Measfreezes all collected debug data from the exposure control submodule instance,
//    which is responsable for the current frame-type (even/odd).
//    
//  Preconditions:
//    * Exposure control manager must have been executed for current cycle
//  
//    
//  
//  return         void
//**************************************************************************** */
/*## operation ICCTL_v_ExecMeasfreezeExposure() */
static void ICCTL_v_ExecMeasfreezeExposure(void);

//*****************************************************************************
//  Functionname:  ICCTL_v_UpdateTemperatures
//  
//  Description:
//    Calculates imager temperatures from current register values. If a temperature value is
//    not available or 'too old', it will be set to 'ICCTL_cf32_TEMP_NOT_AVAILABLE_INDICATOR'.
//    This especially applies to the left imager, whose register data is transferred from the
//    slave DSP via IPC and may be outdated or not available (because DSP is shut down or not
//    functional).
//  
//  Preconditions:
//    * Right Imager: Register values must have been extracted
//    * Left Imager:  Left imager register response must be available and processed
//  
//    
//  
//  return         void
//**************************************************************************** */
/*## operation ICCTL_v_UpdateTemperatures() */
static void ICCTL_v_UpdateTemperatures(void);

//*****************************************************************************
//  Functionname:  ICCTL_v_UpdateErrContext
//  
//  Description:
//    Passes current IC state and other context information to the error manager. This
//    will be appended to the errors / DEMs which are reported as failed.
//  
//  Preconditions:
//    * IC must be initialized
//  
//    
//  
//  return         void
//**************************************************************************** */
/*## operation ICCTL_v_UpdateErrContext() */
static void ICCTL_v_UpdateErrContext(void);

//*****************************************************************************
//  Functionname:  ICCTL_e_ImagerSoftReset
//  
//  Description:
//    Resets the imager(s) by writing to their reset register. After reset, the function is
//    delayed for 'ICCTL_cui32_SoftResetDelayUs' before it returns. An error is returned,
//    when an imager is not responding.
//  
//    
//  
//  return         IC_E_ERROR
//**************************************************************************** */
/*## operation ICCTL_e_ImagerSoftReset() */
static IC_E_ERROR ICCTL_e_ImagerSoftReset(void);

//*****************************************************************************
//  Functionname:  ICCTL_v_DebugLedToggle
//  
//  Description:
//    Toggles the state of the IC dedicated on-board diagnostic debug LED
//  
//    
//  
//  return         void
//**************************************************************************** */
/*## operation ICCTL_v_DebugLedToggle() */
static void ICCTL_v_DebugLedToggle(void);

//*****************************************************************************
//  Functionname:  ICCTL_v_SetExposureRegsToInit
//  
//  Description:
//    Re-initialized the exposure relevant registers to their initial values. This can
//    be used to bring that values into a defined state when the Exposure Control is
//    externally disabled.
//  
//  Preconditions:
//    * IC must be initialized and started
//    * Exposure Control must be disabled (ICCTL_ui32_IcExposureDisabled)
//  
//    
//  
//  return         void
//**************************************************************************** */
/*## operation ICCTL_v_SetExposureRegsToInit() */
static void ICCTL_v_SetExposureRegsToInit(void);

/*## operation ICCTL_e_Init(const IC_S_PlatformFuncs * const,const IC_S_StaticInput * const,const boolean,const boolean) */
#pragma push
#pragma optimize_for_size on
IC_E_ERROR ICCTL_e_Init(const IC_S_PlatformFuncs * const ps_PlatformFuncsIn, const IC_S_StaticInput * const ps_StaticInputIn, const boolean b_UseHilMode, const boolean b_DisableAnalogTest) {
    /*#[ operation ICCTL_e_Init(const IC_S_PlatformFuncs * const,const IC_S_StaticInput * const,const boolean,const boolean) */
    IC_E_ERROR     e_Ret        = IC_e_ERR_OK;
    IC_E_ERROR     e_SubRet     = IC_e_ERR_OK;
    IC_E_ERROR     e_SubRet2    = IC_e_ERR_OK;
    IC_E_ERROR     e_ImgInitRet = IC_e_ERR_OK;
    IRCC_E_ERROR   e_IRCCRet    = IRCC_e_ERROR_OK;
    IC_E_ADAPTERR  e_AdaptRet   = IC_e_ADAPTERR_OK;
    sint16         si16_Ret         = 0;
    uint32         ui32_Index       = 0;
    uint32         ui32_NumFuncPtrs = 0;
    uint32         ui32_FuncPtrAddr = 0;
    uint8          ui8_ImgInitCnt   = 0;
    IC_S_Croi      s_Croi;
    IMGNC_S_Params s_IMGNCParamsEven;
    IMGNC_S_Params s_IMGNCParamsOdd;
    IC_S_Roi       s_ATestRoi;
    IC_S_ATestRefValues s_ATestRefValues;
    
    // Check function pointers
    ui32_NumFuncPtrs = ((uint32)sizeof(*ps_PlatformFuncsIn) / (uint32)sizeof(uint32));
    for (ui32_Index = 0; ui32_Index < ui32_NumFuncPtrs; ui32_Index++)
    {
      ui32_FuncPtrAddr = ((uint32 const*)ps_PlatformFuncsIn)[ui32_Index]; // PRQA S 0310,0492
      if (ui32_FuncPtrAddr == 0)
      {
        e_Ret = IC_e_ERR_NULLPOINTER;
        goto ERROR_EXIT;
      }
    }
    ICCTL_ps_PlatformFuncs = ps_PlatformFuncsIn;
    ICOSW_v_Init(ICCTL_ps_PlatformFuncs);
    
    // Start profiling of init function.
    // NOTE: Must be done after checking function points, because
    //       they are used to get timestamps for profiling.
    IC_PROFILE_START(IC_e_PROFSECT_INIT_TOTAL); // PRQA S 3138,3141,3109
    
    // Zero some private structs
    IC_v_ZEROMEM(IC_s_MeasData);
    IC_v_ZEROMEM(ICCTL_as_IMGNCObj);
    IC_v_ZEROMEM(s_ATestRefValues);
    IC_v_ZEROMEM(s_ATestRoi);
    IC_v_ZEROMEM(ICCTL_s_CycColCorrData);
    IC_v_ZEROMEM(ICCTL_s_IRCCObj);
    IC_v_ZEROMEM(ICCTL_as_ResponseCurve);
    IC_v_ZEROMEM(ICCTL_s_NCResults);
    
    // Initialize other variables
    ICCTL_e_State                     = ICCTL_e_STATE_INIT;
    ICCTL_e_ColCorrState              = ICCTL_e_COLCORRSTATE_ENABLE_TRIGGER;
    ICCTL_ui32_MeasCounter            = 0;
    ICCTL_ui16_PostInitExecCount      = 0;
    ICCTL_ui16_RunningModeExecCount   = 0;
    ICCTL_e_DBusTestResult            = ICTM_e_DBUS_RESULT_NOT_FINISHED;
    ICCTL_b_ImgSyncReqReceived        = b_FALSE;
    
    // Increment init counter and pass to measfreezes
    ICCTL_ui16_InitCnt++;
    IC_s_MeasData.s_Controller.ui16_TotalInitCnt = ICCTL_ui16_InitCnt;
    
    // Copy flags
    if (b_TRUE == b_UseHilMode)
    {
      ICCTL_ui32_HILModeEnabled = IC_cui32_KEY_HILMODE;
    }
    if (b_TRUE == b_DisableAnalogTest)
    {
      ICCTL_ui32_SkipAnalogTest = ICCTL_cui32_KEY_ATEST_DISABLE;
    }
    
    // Update version number and set CDL check magic number
    // PRQA S 3120 4
    IC_s_MeasData.aui8_VersionNumber[0] = (uint8)(IC_TOPLEVEL_VERSION >> IC_BITSHIFT_3BYTE);
    IC_s_MeasData.aui8_VersionNumber[1] = (uint8)(IC_TOPLEVEL_VERSION >> IC_BITSHIFT_2BYTE);
    IC_s_MeasData.aui8_VersionNumber[2] = (uint8)(IC_TOPLEVEL_VERSION >> IC_BITSHIFT_1BYTE);
    IC_s_MeasData.aui8_VersionNumber[3] = (uint8)(IC_TOPLEVEL_VERSION);
    IC_s_MeasData.ui32_VersionNumber    = IC_TOPLEVEL_VERSION;
    IC_s_MeasData.ui32_CDLCheck         = ICCFG_cui32_MAGIC_CDLCHECK;
    
    // Initialize error-handler
    e_SubRet = ICERR_e_Init(&IC_s_MeasData.s_ErrorManager, ICCTL_ui32_HILModeEnabled);
    if (e_SubRet != IC_e_ERR_OK)
    {
      e_Ret = IC_e_ERR_INIT_ERRMANAGER;
      goto ERROR_EXIT;
    }
    
    // Initialize sensor-driver (doesn't initialize imagers)
    e_SubRet = IMGDRV_e_Init(&ICRM_v_SetRegisterSingle);
    if (e_SubRet != IC_e_ERR_OK)
    {
      e_Ret = IC_e_ERR_INIT_SENSORDRV;
      goto ERROR_EXIT;
    }
    
    // Initialize Register Manager
    e_SubRet = ICRM_e_Init(&IC_s_MeasData.s_RegisterManager);
    if (e_SubRet != IC_e_ERR_OK)
    {
      e_Ret = e_SubRet;
      goto ERROR_EXIT;
    }
    
    // Initialize exposure manager
    e_SubRet = ICEXPMG_e_Init(&IC_s_MeasData.s_ExposureManager, ps_StaticInputIn->s_IrccPPars.f32_DCG_Factor);
    if (e_SubRet != IC_e_ERR_OK)
    {
      e_Ret = e_SubRet;
      goto ERROR_EXIT;
    }
    
    // Initialize timing manager and enable jittering
    ICTIM_v_Init(&IC_s_MeasData.s_TimingManager);
    #if (IC_JITTERING_ENABLED == 1)
    ICTIM_v_SetJittering(b_TRUE);
    #else
    ICTIM_v_SetJittering(b_FALSE);
    #endif
    
    // Initialize embedded data parser
    si16_Ret = IEDP_si16_Init();
    if (IEDP_csi16_NOERROR != si16_Ret)
    {
      e_Ret = IC_e_ERR_INIT_IEDP;
      goto ERROR_EXIT;
    }
    
    // Initialize CROI and IC ROI
    e_SubRet = ICROI_e_Init(&IC_s_MeasData.s_RoiManager, &ps_StaticInputIn->s_CamParam);
    if (IC_e_ERR_OK != e_SubRet)
    {
      e_Ret = e_SubRet;
      goto ERROR_EXIT;
    }
    
    // Initialize test manager
    ICROI_v_GetImagerCroi(&s_Croi, IC_e_IMAGER_RIGHT, IC_ce_MASTER_FRAMETYPE);
    ICTM_v_Init(&IC_s_MeasData.s_TestManager, &s_Croi);
    
    // Set FrameIdMSBs
    ICCTL_aui8_FrameIdMSB[IC_e_IMAGER_RIGHT] = 0x00;
    #if (ICCFG_ENABLE_LEFT_IMAGER == 1)
    ICCTL_aui8_FrameIdMSB[IC_e_IMAGER_LEFT]  = 0x01;
    #endif
    
    // Set correction factor
    if (IC_e_ERR_OK != IMGDRV_e_SetCorrectionFactor(ps_StaticInputIn->s_CamParam.f32_GainFactorLR))
    {
      e_Ret = IC_e_ERR_INVALID_CORRECTION_FACTOR;
      goto ERROR_EXIT;
    }
    
    // Set PPARs for IRCC
    ICCTL_ps_IRCCPPARs = &ps_StaticInputIn->s_IrccPPars;
    e_IRCCRet = IRCC_e_SetImagerPPARs(&ICCTL_s_IRCCObj, ICCTL_ps_IRCCPPARs);
    if (IRCC_e_ERROR_OK != e_IRCCRet)
    {
      e_Ret = IC_e_ERR_IRCC_SET_PPARS;
      goto ERROR_EXIT;
    }
    
    // Initialize noise-calculation and blacklevel-estimation
    ICROI_v_GetImagerCroi(&s_Croi, IC_e_IMAGER_RIGHT, IC_e_FRAMETYPE_ODD);
    s_IMGNCParamsOdd.f32_BlacklevelOffset = ps_StaticInputIn->s_CamParam.f32_BlacklevelOffset;
    s_IMGNCParamsOdd.f32_FilterDampingFactor = ICCFG_cf32_BlEstimationFilterDamping;
    s_IMGNCParamsOdd.ui16_ImgWidth  = s_Croi.ui16_Width;
    s_IMGNCParamsOdd.ui16_ImgXStart = s_Croi.ui16_StartX;
    
    ICROI_v_GetImagerCroi(&s_Croi, IC_e_IMAGER_RIGHT, IC_e_FRAMETYPE_EVEN);
    s_IMGNCParamsEven.f32_BlacklevelOffset = ps_StaticInputIn->s_CamParam.f32_BlacklevelOffset;
    s_IMGNCParamsEven.f32_FilterDampingFactor = ICCFG_cf32_BlEstimationFilterDamping;
    s_IMGNCParamsEven.ui16_ImgWidth  = s_Croi.ui16_Width;
    s_IMGNCParamsEven.ui16_ImgXStart = s_Croi.ui16_StartX;
    if ((IMGNC_e_Init(&ICCTL_as_IMGNCObj[IC_e_FRAMETYPE_ODD],  &s_IMGNCParamsOdd) != IMGNC_e_ERR_OK)   // PRQA S 3415
      ||(IMGNC_e_Init(&ICCTL_as_IMGNCObj[IC_e_FRAMETYPE_EVEN], &s_IMGNCParamsEven) != IMGNC_e_ERR_OK)) // PRQA S 3415
    {
      e_Ret = IC_e_ERR_IMGNC_INIT;
      goto ERROR_EXIT;
    }
    
    #if (IC_ANALOG_TEST_ENABLED == 1)
    // Initialize analog test
    ICAT_v_Init(&IC_s_MeasData.s_AnalogTest);
    s_ATestRoi.ui16_StartX = ICCFG_cui16_ATEST_ROI_STARTX;
    s_ATestRoi.ui16_StartY = ICCFG_cui16_ATEST_ROI_STARTY;
    s_ATestRoi.ui16_Width  = ICCFG_cui16_ATEST_ROI_WIDTH;
    s_ATestRoi.ui16_Height = ICCFG_cui16_ATEST_ROI_HEIGHT;
    
    // Give analog test initial parameters
    if (b_DisableAnalogTest != b_TRUE)
    {
      e_SubRet  = ICAT_e_SetRoi(&s_ATestRoi, ICCFG_cui16_ATEST_ROI_MODULUS);
      e_SubRet2 = ICAT_e_SetRefValues(&ps_StaticInputIn->s_AnalogTestRefValues, &ICCFG_s_ATest_MaxTolsStartup);
      if ((IC_e_ERR_OK != e_SubRet) || (IC_e_ERR_OK != e_SubRet2))
      {
        e_Ret = ICERR_HANDLE(IC_e_ERR_ATEST_INIT, 0);
        goto ERROR_EXIT;
      }
    }
    #endif
    
    // Copy static input
    IC_s_MeasData.s_InputStatic = *ps_StaticInputIn;
    
    // This is a test for the "Late-ACK" issue (imager I2C ACK comes too late if streaming is off)
    #if (IC_I2C_LATE_ACK_TEST == 1)
    #warning "I2C Late-ACK Test enabled!!" // PRQA S 3115
    ICRM_v_SetTXMode(ICRM_e_TXMODE_WRITEINSTANT_SYNC);
    while(1)
    {
      IMGDRV_v_SetStreamingMode(IMGDRV_e_STREAMING_MODE_ON);
      DELAY_v_DelayUs(1000000);
      IMGDRV_v_SetStreamingMode(IMGDRV_e_STREAMING_MODE_OFF);
      DELAY_v_DelayUs(1000000);
    }
    #endif
    
    // Initialize imagers
    if (b_TRUE != b_UseHilMode)
    {
      // PMC waits ~35ms after imager reset before starting IC init, so wait additional 35ms here to
      // fulfill the new requirement of minimum 66ms delay after each reset. Otherwise some imagers
      // will not ACK on I2C when executing BIST.
      //
      // TODO: Move this delay to PMC
      ICOSW_v_DelayUs(ICCTL_cui32_ImagerInitDelayUs);
    
      ui8_ImgInitCnt = 0;
      do
      {
        // I2C timing has to be set to SLOW here as init-sequence disables streaming on some
        // points. When streaming is disabled, the imager is put into low power mode and
        // uses slower EXTCLK (bypassing PLL) for internal clocking. Fast I2C sometimes
        // fails then.
        ICOSW_v_SetI2CBusTiming(IC_e_I2CTIMING_SLOW);
        e_ImgInitRet = ICCTL_e_InitImagers();
        if (IC_e_ERR_OK != e_ImgInitRet)
        {
          // Re-init imager comm module
          e_AdaptRet = ICCTL_ps_PlatformFuncs->pfct_e_ReInitImgComm();
          if (IC_e_ADAPTERR_OK != e_AdaptRet)
          {
            e_Ret = ICERR_HANDLE(IC_e_ERR_REINIT_IMGCOMM, e_AdaptRet);
            goto ERROR_EXIT;
          }
    
          // Re-init register manager
          e_SubRet = ICRM_e_Init(&IC_s_MeasData.s_RegisterManager);
          if (IC_e_ERR_OK != e_SubRet)
          {
            e_Ret = ICERR_HANDLE(e_SubRet, 0);
            goto ERROR_EXIT;
          }
    
          // Execute imager soft-reset
          e_SubRet = ICCTL_e_ImagerSoftReset();
          if (IC_e_ERR_OK != e_SubRet)
          {
            e_Ret = ICERR_HANDLE(e_SubRet, 0);
            goto ERROR_EXIT;
          }
          
          // Flush DEM events, which also handles debouncing. It is important to call this here
          // on every (re-)try, as debouncing will not work otherwise.
          ICERR_v_DemFlush();
        }
    
        // Set I2C timing back to FAST
        ICOSW_v_SetI2CBusTiming(IC_e_I2CTIMING_FAST);
    
        // If imager initialization fails, try again as configured in ic_cfg.h
        ui8_ImgInitCnt++;
      } while((e_ImgInitRet != IC_e_ERR_OK) && (ui8_ImgInitCnt < ICCFG_cui8_INIT_IMAGERS_MAXTRIES));
    
      // Remember how often we tried to reinitialize
      IC_s_MeasData.s_Controller.ui8_InitTryCnt = ui8_ImgInitCnt;
    
      // We have a problem if IC initialization fails several times
      if (IC_e_ERR_OK != e_ImgInitRet)
      {
        e_Ret = ICERR_HANDLE(e_ImgInitRet, 0);
        goto ERROR_EXIT;
      }
    }
    
    // We are done with init. Switch register-writing behavior to explicit-flush-mode
    ICRM_v_SetTXMode(ICRM_e_TXMODE_BUFFER_TILL_FLUSHED);
    
    // Analog test results wants to have sensor fuse id for copying into results for XCP
    #if (IC_ANALOG_TEST_ENABLED == 1)
    ICAT_v_SetSensorFuseId(IC_s_MeasData.s_ImagerInfos.s_ImagerIdsRight.ui64_SensorFuseId);
    #endif
    
    // Done! Report some DEMs as passed:
    ICERR_v_DemPassed(IC_e_DEM_PARAMETER);
    ICERR_v_DemPassed(IC_e_DEM_GENERAL_FATAL);
    ICERR_v_DemPassed(IC_e_DEM_GENERAL);
    ICERR_v_DemPassed(IC_e_DEM_IMAGER_COMM_R);
    ICERR_v_DemPassed(IC_e_DEM_REGTX_SYNC_VERIFY_FAILED_R);
    #if (ICCFG_ENABLE_LEFT_IMAGER == 1)
    ICERR_v_DemPassed(IC_e_DEM_IMAGER_COMM_L);
    ICERR_v_DemPassed(IC_e_DEM_REGTX_SYNC_VERIFY_FAILED_L);
    #endif
    
    // Goto next state
    ICCTL_b_Initialized = b_TRUE;
    ICCTL_v_StateTransition();
    
    ERROR_EXIT:
    
    // Flush DEM status
    ICERR_v_DemFlush();
    IC_PROFILE_STOP(IC_e_PROFSECT_INIT_TOTAL); // PRQA S 3138,3141,3109
    IC_PROFILE_START(IC_e_PROFSECT_INIT_FINISH_2_IC_START); // PRQA S 3138,3141,3109
    return e_Ret;
    
    // PRQA S 7002,7004,7006 2
    /*#]*/
}
#pragma pop

/*## operation ICCTL_e_InitImagers() */
#pragma push
#pragma optimize_for_size on
static IC_E_ERROR ICCTL_e_InitImagers(void) {
    /*#[ operation ICCTL_e_InitImagers() */
    IC_E_ERROR     e_Ret                 = IC_e_ERR_OK;
    IC_E_ERROR     e_SubRet              = IC_e_ERR_OK;
    IC_E_Imager    e_Imager              = IC_ce_MASTER_IMAGER;
    uint16         ui16_RegVal           = 0;
    uint16         ui16_RegAddr          = 0;
    uint16         ui16_Index            = 0;
    uint8          aui8_ImagerRevision[ICCFG_NUM_IMAGERS];
    uint16         aui16_ModelId[ICCFG_NUM_IMAGERS];
    IC_S_SensorIDs *ps_SensIds;
    
    // Mark start of INIT
    ICOSW_v_SetDebugLED(b_TRUE);
    IC_PROFILE_START(IC_e_PROFSECT_INIT_IMAGERS); // PRQA S 3138,3141,3109
    ICCTL_b_LedToggleFlag = b_TRUE;
    
    // Read revision number and initialize default register values for that model
    for (ui16_Index = 0; ui16_Index < ICCFG_NUM_IMAGERS; ui16_Index++)
    {
      e_Imager = (IC_E_Imager)ui16_Index; // PRQA S 1482
    
      // Read model id
      ui16_RegAddr = IMGREG_ui16_GetRegAddr(IMGREG_e_REG_MODEL_ID);
      e_SubRet = ICRM_e_SensorRegRXSingle(e_Imager, ui16_RegAddr, &ui16_RegVal);
      if (IC_e_ERR_OK != e_SubRet)
      {
        e_Ret = ICERR_HANDLE(e_SubRet, 0);
        goto ERROR_EXIT;
      }
      aui16_ModelId[ui16_Index] = ui16_RegVal;
    
      // Read revision number
      ui16_RegAddr = IMGREG_ui16_GetRegAddr(IMGREG_e_REG_REVISION_NUMBER);
      e_SubRet = ICRM_e_SensorRegRXSingle(e_Imager, ui16_RegAddr, &ui16_RegVal);
      if (IC_e_ERR_OK != e_SubRet)
      {
        e_Ret = ICERR_HANDLE(e_SubRet, 0);
        goto ERROR_EXIT;
      }
    
      // The revision number is actually an (and the only) 8-bit register!
      // The content is in the MSB, so extract it:
      aui8_ImagerRevision[ui16_Index] = (uint8)(ui16_RegVal >> IC_NUMBITS_8);
    
      // Get default register values for our specific imager model
      e_SubRet = ICRM_e_SetRegisterResetValues(e_Imager, aui16_ModelId[ui16_Index], aui8_ImagerRevision[ui16_Index]);
      if (IC_e_ERR_OK != e_SubRet)
      {
        e_Ret = ICERR_HANDLE(e_SubRet, e_Imager);
        goto ERROR_EXIT;
      }
    }
    
    // Execute BIST (build-in self-test)
    #if (IC_BIST_ENABLED == 1)
    ICCTL_v_DebugLedToggle(); // Mark start of BIST
    IC_PROFILE_START(IC_e_PROFSECT_INIT_BIST); // PRQA S 3138,3141,3109
    e_Ret = ICTM_e_ExecBIST();
    if (IC_e_ERR_OK != e_Ret)
    {
      /* Keep error-code */
      goto ERROR_EXIT;
    }
    IC_PROFILE_STOP(IC_e_PROFSECT_INIT_BIST); // PRQA S 3138,3141,3109
    ICCTL_v_DebugLedToggle(); // Mark end of BIST
    #endif
    
    // **** Initialize imagers ****
    // NOTE: Sequencer load should be done always according to SFE, so CR 59463 has been reverted
    IC_PROFILE_START(IC_e_PROFSECT_INIT_INITREGISTERS); // PRQA S 3138,3141,3109
    e_SubRet = ICRM_e_SendInitSequence(ICINIT_caui16_SensorInitData, ICINIT_caui16_SensorInitDataEntries);
    if (e_SubRet != IC_e_ERR_OK)
    {
      e_Ret = e_SubRet;
      goto ERROR_EXIT;
    }
    IC_PROFILE_STOP(IC_e_PROFSECT_INIT_INITREGISTERS); // PRQA S 3138,3141,3109
    ICCTL_v_DebugLedToggle(); // Mark end of sensor init
    
    // Enable "allow read from fuse id"
    IMGDRV_v_SetAllowReadFuseId(b_TRUE);
    
    // Set some other stuff
    IMGDRV_v_SetEmbeddedDataVersion(IC_cui8_IC_EMBEDDED_DATA_VERSION);
    e_Ret = ICRM_e_FlushSensorRegisters(b_TRUE);
    if (e_Ret != IC_e_ERR_OK)
    {
      /* Keep error-code */
      goto ERROR_EXIT;
    }
    
    // Now read some important registers via I2C, like imager fuse id and temperature calibration registers.
    // This is essential for all cyclic non-written registers which are involved in the register check!
    e_SubRet = ICRM_e_ReadInitialRegisters();
    if (IC_e_ERR_OK != e_SubRet)
    {
      e_Ret = e_SubRet;
      goto ERROR_EXIT;
    }
    
    // Disable "allow read from fuse id"
    IMGDRV_v_SetAllowReadFuseId(b_FALSE);
    
    // Set imager output data path slew rate
    ICRM_v_SetRegisterSingle(IMGREG_e_REG_DATAPATH_SELECT, ICCFG_cui16_IMAGER_DATAPATH_RIGHT, IC_e_IMAGER_RIGHT);
    #if (ICCFG_HARDWARE_STEREO == 1)
    ICRM_v_SetRegisterSingle(IMGREG_e_REG_DATAPATH_SELECT, ICCFG_cui16_IMAGER_DATAPATH_LEFT, IC_e_IMAGER_LEFT);
    #endif
    
    // Flush registers to sensors
    e_Ret = ICRM_e_FlushSensorRegisters(b_TRUE);
    if (IC_e_ERR_OK != e_Ret)
    {
      /* Keep error-code */
      goto ERROR_EXIT;
    }
    
    // Read ModelId, RevisionNumber and FuseId
    ps_SensIds                            = &IC_s_MeasData.s_ImagerInfos.s_ImagerIdsRight;
    ps_SensIds->ui16_SensorModelId        = IMGDRV_ui16_GetModelId(IC_e_IMAGER_RIGHT);
    ps_SensIds->ui8_SensorRevisionNumber  = IMGDRV_ui8_GetRevisionNumber(IC_e_IMAGER_RIGHT);
    ps_SensIds->ui64_SensorFuseId         = IMGDRV_ui64_GetFuseId(IC_e_IMAGER_RIGHT);
    #if (ICCFG_ENABLE_LEFT_IMAGER == 1)
    ps_SensIds                             = &IC_s_MeasData.s_ImagerInfos.s_ImagerIdsLeft;
    ps_SensIds->ui16_SensorModelId         = IMGDRV_ui16_GetModelId(IC_e_IMAGER_LEFT);
    ps_SensIds->ui8_SensorRevisionNumber   = IMGDRV_ui8_GetRevisionNumber(IC_e_IMAGER_LEFT);
    ps_SensIds->ui64_SensorFuseId          = IMGDRV_ui64_GetFuseId(IC_e_IMAGER_LEFT);
    #endif
    
    // >>>>>>>>>>>>>> THIS BLOCK SHOULD BE THE LAST STEP WHICH WRITES TO ANY REGISTERS >>>>>>>>
    // >>>>>>>>>>>>>>          RELIABLE IMAGE-SYNC MAY NOT WORK OTHERWISE              >>>>>>>>
    // Synchronize Imagers
    //  1. Pull trigger-pins low
    //  2. Stop Streaming and force the PLL to stay always on (Bit 11 in reset-reg)
    //  3. Wait until streaming is stopped (sleep for >one frame ~50 ms)
    //  4. Enable streaming by pulling trigger-pins high
    IC_PROFILE_START(IC_e_PROFSECT_INIT_SYNC_IMAGERS); // PRQA S 3138,3141,3109
    #if (ICCFG_ENABLE_LEFT_IMAGER == 1)
    ICCTL_v_DebugLedToggle();
    ICOSW_v_SetTriggerPin(b_FALSE);
    IMGDRV_v_SetStreamingMode(IMGDRV_e_STREAMING_MODE_EXTTRIGGER);
    e_Ret = ICRM_e_FlushSensorRegisters(b_TRUE);
    if (e_Ret != IC_e_ERR_OK)
    {
      goto ERROR_EXIT;
    }
    ICOSW_v_DelayUs(ICCFG_cui32_TRIGGERPIN_DELAY_MS);
    ICOSW_v_SetTriggerPin(b_TRUE);
    #else
    IMGDRV_v_SetStreamingMode(IMGDRV_e_STREAMING_MODE_ON);
    e_Ret = ICRM_e_FlushSensorRegisters(b_TRUE);
    if (e_Ret != IC_e_ERR_OK)
    {
      goto ERROR_EXIT;
    }
    ICOSW_v_SetTriggerPin(b_TRUE);
    #endif
    IC_PROFILE_STOP(IC_e_PROFSECT_INIT_SYNC_IMAGERS); // PRQA S 3138,3141,3109
    // <<<<<<<<<<<<<< THIS BLOCK SHOULD BE THE LAST STEP WHICH WRITES TO ANY REGISTERS <<<<<<<<
    // <<<<<<<<<<<<<<          RELIABLE IMAGE-SYNC MAY NOT WORK OTHERWISE              <<<<<<<<
    
    ICCTL_v_DebugLedToggle(); // Mark end of init
    IC_PROFILE_STOP(IC_e_PROFSECT_INIT_IMAGERS); // PRQA S 3138,3141,3109
    
    ERROR_EXIT:
    return e_Ret;
    
    // PRQA S 7002,7006 2
    /*#]*/
}
#pragma pop

/*## operation ICCTL_e_Start() */
#pragma push
#pragma optimize_for_size on
IC_E_ERROR ICCTL_e_Start(void) {
    /*#[ operation ICCTL_e_Start() */
    IC_E_ERROR e_Ret    = IC_e_ERR_OK;
    IC_E_ERROR e_RoiRet = IC_e_ERR_OK;
    IC_S_Roi   s_Roi;
    uint32     ui32_Index = 0;
    
    // Private structure for defining ROIs for registering
    struct My_S_RoiDef
    {
        IC_E_ROIID e_RoiId;
        uint16 ui16_StartY;
        uint16 ui16_Height;
        uint16 ui16_Width;
        ICIF_E_ROIFRAMETYPE e_FrameType;
    };
    
    // This are the ROIs which we will register now
    struct My_S_RoiDef as_RoiDefs[] = // PRQA S 3674
    {
        /* Dark-rows and embedded registers */
        {
            IC_e_ROIID_EMBEDDED,               /* ROI ID     */
            ICCTL_cui16_TOPROI_STARTY,         /* StartY     */
            ICCTL_cui16_TOPROI_HEIGHT,         /* Height     */
            ICCFG_cui16_NumEmbeddedPixelsMax,  /* Width      */
            ICIF_e_ROIFRAMETYPE_ALL            /* Frame type */
        },
    
        /* Even frame embedded statistics */
        {
            IC_e_ROIID_STATISTIC_EVEN,               /* ROI ID     */
            ICCFG_cui_EMBEDDED_STAT_LINE_START_EVEN, /* StartY     */
            ICCFG_cui16_NumEmbeddedStatLines,        /* Height     */
            ICCFG_cui16_NumEmbeddedPixelsMax,        /* Width      */
            ICIF_e_ROIFRAMETYPE_EVEN                 /* Frame type */
        },
    
        /* Odd frame embedded statistics */
        {
            IC_e_ROIID_STATISTIC_ODD,                /* ROI ID     */
            ICCFG_cui_EMBEDDED_STAT_LINE_START_ODD,  /* StartY     */
            ICCFG_cui16_NumEmbeddedStatLines,        /* Height     */
            ICCFG_cui16_NumEmbeddedPixelsMax,        /* Width      */
            ICIF_e_ROIFRAMETYPE_ODD                  /* Frame type */
        }
    };
    struct My_S_RoiDef *ps_RoiDef;
    
    // Register ROIs: Always use full image-width
    for (ui32_Index = 0; ui32_Index < IC_ARRLEN(as_RoiDefs); ui32_Index++)
    {
      ps_RoiDef = &as_RoiDefs[ui32_Index];
      s_Roi.ui16_StartX = 0;
      s_Roi.ui16_StartY = ps_RoiDef->ui16_StartY;
      s_Roi.ui16_Height = ps_RoiDef->ui16_Height;
      s_Roi.ui16_Width  = ps_RoiDef->ui16_Width;
      e_RoiRet = ICOSW_e_RoiRegister(ps_RoiDef->e_RoiId, &s_Roi, ps_RoiDef->e_FrameType);
      if (IC_e_ERR_OK != e_RoiRet)
      {
        e_Ret = ICERR_HANDLE(IC_e_ERR_REGISTER_ROI, e_RoiRet);
        goto ERROR_EXIT;
      }
    }
    
    // We are finished!
    ICCTL_b_Started = b_TRUE;
    ICCTL_v_StateTransition();
    
    ERROR_EXIT:
    return e_Ret;
    /*#]*/
}
#pragma pop

/*## operation ICCTL_e_DeInit() */
IC_E_ERROR ICCTL_e_DeInit(void) {
    /*#[ operation ICCTL_e_DeInit() */
    IC_E_ERROR e_Ret;
    
    // Unregister all ROIs
    if (ICCTL_e_STATE_INIT != ICCTL_e_State)
    {
      e_Ret = ICOSW_e_RoiUnregisterAll();
    }
    
    // Reset our state back to init
    ICCTL_e_State       = ICCTL_e_STATE_INIT;
    ICCTL_b_Initialized = b_FALSE;
    ICCTL_b_Started     = b_FALSE;
    
    return e_Ret;
    /*#]*/
}

/*## operation ICCTL_v_NewFrameStarted(const uint16,const uint64) */
void ICCTL_v_NewFrameStarted(const uint16 ui16_FrameNum, const uint64 ui64_FrameTimestamp) {
    /*#[ operation ICCTL_v_NewFrameStarted(const uint16,const uint64) */
    ICERR_v_StartNewCycle(ui16_FrameNum);
    ICCTL_ui64_FrameStartUs = ui64_FrameTimestamp;
    /*#]*/
}

/*## operation ICCTL_v_SetInput(const IC_S_Input * const) */
void ICCTL_v_SetInput(const IC_S_Input * const ps_Input) {
    /*#[ operation ICCTL_v_SetInput(const IC_S_Input * const) */
    ICCTL_ps_Input = ps_Input;
    /*#]*/
}

/*## operation ICCTL_e_LineFunc(const IC_E_FRAMETYPE,const uint16,const uint16 * const) */
IC_E_ERROR ICCTL_e_LineFunc(const IC_E_FRAMETYPE e_FrameType, const uint16 ui16_LineNum, const uint16 * const pui16_PixelData) {
    /*#[ operation ICCTL_e_LineFunc(const IC_E_FRAMETYPE,const uint16,const uint16 * const) */
    IC_E_ERROR     e_Ret      = IC_e_ERR_OK;
    IMGNC_E_ERROR  e_NCErr    = IMGNC_e_ERR_OK;
    uint32         ui32_StartTimeUs = 0;
    uint16         ui16_RuntimeUs   = 0;
    
    // Record start-time
    ui32_StartTimeUs = ICCTL_ps_PlatformFuncs->pfct_ui32_GetTimeUs();
    
    // Detect new frame start
    if (ui16_LineNum < ICCTL_ui16_LastLineNum)
    {
      // New frame started: Increment frame-counter. It will be overwritten later
      // by embedded data extraction! Because the "real" frame-counter in the embedded data
      // is only available after raw-image line 17, it is incremented here to allow
      // functions that are called before line 17 to see correct frame-counter.
      ICCTL_ui16_FrameNum++;
      
      // Cleanup runtimes
      IC_v_ZEROMEM(IC_s_MeasData.s_TimingInfo.as_LineCbExecTime);
      ICCTL_ui16_LineCbDurationIndex = 0;
      
      // Execute state transition logic
      ICCTL_v_StateTransition();
    }
    ICCTL_ui16_LastLineNum = ui16_LineNum;
    
    switch (ui16_LineNum)
    {
    case ICCFG_cui16_EmbeddedRegLineStart + 0u:
      ICCTL_pui16_EmbDatLine0 = pui16_PixelData;
      IC_s_MeasData.s_Controller.s_CallbackCounters.ui16_CallbackCountReg0++;
      break;
    
    case ICCFG_cui16_EmbeddedRegLineStart + 1u:
      ICCTL_pui16_EmbDatLine1 = pui16_PixelData;
      IC_s_MeasData.s_Controller.s_CallbackCounters.ui16_CallbackCountReg1++;
      e_Ret = ICCTL_e_ExecPart1();
      break;
    
    case ICCFG_cui_EMBEDDED_STAT_LINE_START_ODD + 0u:
      if (IC_e_FRAMETYPE_ODD == e_FrameType)
      {
        IC_s_MeasData.s_Controller.s_CallbackCounters.ui16_CallbackCountOddStat0++;
        ICCTL_pui16_EmbStatLine0 = pui16_PixelData;
      }
      break;
    
    case ICCFG_cui_EMBEDDED_STAT_LINE_START_ODD + 1u:
      if (IC_e_FRAMETYPE_ODD == e_FrameType)
      {
        IC_s_MeasData.s_Controller.s_CallbackCounters.ui16_CallbackCountOddStat1++;
        ICCTL_pui16_EmbStatLine1 = pui16_PixelData;
        e_Ret = ICCTL_e_ExecPart2(ICCTL_pui16_EmbStatLine0, ICCTL_pui16_EmbStatLine1);
      }
      break;
    
    case ICCFG_cui_EMBEDDED_STAT_LINE_START_EVEN + 0u:
      if (IC_e_FRAMETYPE_EVEN == e_FrameType)
      {
        IC_s_MeasData.s_Controller.s_CallbackCounters.ui16_CallbackCountEvenStat0++;
        ICCTL_pui16_EmbStatLine0 = pui16_PixelData;
      }
      break;
    
    case ICCFG_cui_EMBEDDED_STAT_LINE_START_EVEN + 1u:
      if (IC_e_FRAMETYPE_EVEN == e_FrameType)
      {
        IC_s_MeasData.s_Controller.s_CallbackCounters.ui16_CallbackCountEvenStat1++;
        ICCTL_pui16_EmbStatLine1 = pui16_PixelData;
        e_Ret = ICCTL_e_ExecPart2(ICCTL_pui16_EmbStatLine0, ICCTL_pui16_EmbStatLine1);
      }
      break;
    
    default:
    #if (IC_NOISECALC_ENABLED == 1)
      if (ui16_LineNum < ICCFG_cui16_NumDarkrows)
      {
        // Other line-type of top-block
        if (ICCTL_e_STATE_RUNNING == ICCTL_e_State)
        {
          e_NCErr = IMGNC_e_LineCallback(&ICCTL_as_IMGNCObj[e_FrameType], ui16_LineNum, pui16_PixelData);
          if (IMGNC_e_ERR_OK != e_NCErr)
          {
            e_Ret = ICERR_HANDLE(IC_e_ERR_IMGNC_LINECALLBACK, e_NCErr);
          }
        }
      }
    #endif
    #if (IC_DATABUS_CHECK_STARTUP_ENABLED == 1)
      if (ICCTL_e_State == ICCTL_e_STATE_DATABUS_TEST)
      {
        ICTM_v_DatabusCheckLineFunc(ui16_LineNum, pui16_PixelData);
      }
    #endif
    #if (IC_DATABUS_CHECK_VIA_NOISE_ENABLED == 1)
      if (ICCTL_e_State == ICCTL_e_STATE_RUNNING)
      {
        ICTM_v_DatabusCheckNoiseLineFunc(ui16_LineNum, pui16_PixelData);
      }
    #endif
      break;
    }
    
    // Feed analog test? It also needs access to embedded data lines, so pass just everything to sub-module
    #if (IC_ANALOG_TEST_ENABLED == 1)
    if (ICCTL_e_State == ICCTL_e_STATE_ANALOG_TEST)
    {
      if (ICAT_e_LineFunc(ui16_LineNum, pui16_PixelData, ICCTL_ui16_FrameNum) != IC_e_ERR_OK)
      {
        e_Ret = ICERR_HANDLE(IC_e_ERR_ATEST_LINE, 0);
      }
    }
    #endif
    
    // Store single and Accumulated run-time
    ui16_RuntimeUs = (uint16)(ICCTL_ps_PlatformFuncs->pfct_ui32_GetTimeUs() - ui32_StartTimeUs);
    ICCTL_ui16_AccumulativeRuntime += ui16_RuntimeUs;
    if (ICCTL_ui16_LineCbDurationIndex < IC_ARRLEN(IC_s_MeasData.s_TimingInfo.as_LineCbExecTime))
    {
      IC_s_MeasData.s_TimingInfo.as_LineCbExecTime[ICCTL_ui16_LineCbDurationIndex].ui16_LineNum = ui16_LineNum;
      IC_s_MeasData.s_TimingInfo.as_LineCbExecTime[ICCTL_ui16_LineCbDurationIndex].ui16_CalcTimeUs = ui16_RuntimeUs;
      ICCTL_ui16_LineCbDurationIndex++;
    }
    
    return e_Ret;
    
    // PRQA S 7002 2
    /*#]*/
}

/*## operation ICCTL_e_ExecPart1() */
static IC_E_ERROR ICCTL_e_ExecPart1(void) {
    /*#[ operation ICCTL_e_ExecPart1() */
    IC_E_ERROR   e_Ret               = IC_e_ERR_OK;
    IC_E_ERROR   e_SubRet            = IC_e_ERR_OK;
    uint32       ui32_StartTimeUs    = 0;
    sint64       si64_TimeOffset     = 0;
    sint32       si32_ImgOffsetLR_us = 0;
    boolean      b_Part2NotExecuted  = b_FALSE;
    
    // Get start-time and start profiling
    ui32_StartTimeUs = ICOSW_ui32_GetTimeUs();
    IC_PROFILE_START(IC_e_PROFSECT_P1_TOTAL); // PRQA S 3138,3141,3109
    
    // Prerequisites
    if (ICCTL_e_State <= ICCTL_e_STATE_WAIT_START)
    {
      e_Ret = ICERR_HANDLE(IC_e_ERR_WRONG_STATE, ICCTL_e_State);
      goto ERROR_EXIT;
    }
        
    // If IC is not in 'running' state, reset execution counter.
    if (ICCTL_e_STATE_RUNNING != ICCTL_e_State)
    {
      ICCTL_ui16_RunningModeExecCount = 0;
    }
    
    // TODO: Check if part1 has been called and issue IC_e_ERR_PART1_NOT_CALLED, either by
    //   1) checking execution time delta < (39.4ms + someWindow)
    //   2) checking against pre-calculated execution time (using frame-length from ICTIM module)
    
    // Check if part2 has been called on last frame
    if (ICCTL_e_EXECSTATE_PART1 != ICCTL_e_ExecSubstate)
    {
      // ROI_HAL seems to take two frames until it's running stable
      if (ICCTL_ui16_PostInitExecCount > 1)
      {
        e_Ret = ICERR_HANDLE(IC_e_ERR_PART2_NOT_CALLED, ICCTL_e_ExecSubstate);
      }
      b_Part2NotExecuted = b_TRUE;
    }
    
    #if (IC_FAKE_EMBEDDED_DATA_DESTRUCTION == 1)
    #warning "IC Fake Embedded Data Destruction is enabled!!" // PRQA S 3115
    // Destroy embedded data each 15 frames
    if ((ICCTL_ui16_FrameNum % 15) == 10)
    {
      memset(ICCTL_pui16_EmbDatLine0 + 156, 0xAA, 8);
      memset(ICCTL_pui16_EmbDatLine1 + 47, 0x33, 8);
    }
    #endif
    
    // Check input signal timeouts and mark new signals as updated
    ICCTL_v_CheckNewInputs(ICCTL_ps_Input, ICCTL_ui64_FrameStartUs);
    
    // Process embedded data
    e_SubRet = ICCTL_e_ExtractRegs(ICCTL_pui16_EmbDatLine0, ICCTL_pui16_EmbDatLine1);
    if (IC_e_ERR_OK != e_SubRet)
    {
      e_Ret = ICERR_HANDLE(e_SubRet, 0);
    }
    
    // Do checks, but skip if registers are corrupted or checks are explicitly disabled
    if ((b_FALSE == ICCTL_b_CorruptedRegs) && (ICCTL_cui32_KEY_REGCHECKS_DISABLE != ICCTL_ui32_RegChecksDisabled))
    {
      IC_PROFILE_START(IC_e_PROFSECT_P1_NEW_REGDATA_CHECKS); // PRQA S 3138,3141,3109
      ICCTL_v_NewRegDataChecks();
      IC_PROFILE_STOP(IC_e_PROFSECT_P1_NEW_REGDATA_CHECKS); // PRQA S 3138,3141,3109
    }
    
    // Process left imager's register response
    #if (ICCFG_ENABLE_LEFT_IMAGER == 1)
    if (b_TRUE == ICCTL_ab_InputUpdated[ICCTL_e_INPUTTYPE_REGRESP])
    {
      ICCTL_ab_InputUpdated[ICCTL_e_INPUTTYPE_REGRESP] = b_FALSE;
      IC_PROFILE_START(IC_e_PROFSECT_P1_PROCESS_REGRESPONSE); // PRQA S 3138,3141,3109
      e_SubRet = ICRM_e_ProcessRegisterResponse(ICCTL_ui16_FrameNum, &ICCTL_ps_Input->s_RegTransfResponse);
      if (IC_e_ERR_OK != e_SubRet)
      {
        e_Ret = ICERR_HANDLE(IC_e_ERR_PROCESS_LEFTREGS_REPONSE, e_SubRet);
      }
      else
      {
        // Execute register check for left imager (not on HIL, as there is no "closed-loop")
    #if (IC_REGISTER_CHECK_LEFT_ENABLED == 1)
        if ((ICCTL_b_HILMODE_ACTIVE() != b_TRUE) && (ICCTL_cui32_KEY_REGCHECKS_DISABLE != ICCTL_ui32_RegChecksDisabled))
        {
          ICRM_v_CheckRegistersLeft(ICCTL_ui16_FrameNum);
        }
    #endif
      }
      IC_PROFILE_STOP(IC_e_PROFSECT_P1_PROCESS_REGRESPONSE); // PRQA S 3138,3141,3109
    }
    #endif
    
    // Prepare output buffers for new data
    // !!IMPORTANT!! Rotation of output buffers must be done _after_ executing register checks!
    //               Otherwise the correct history buffer will be mismatched!
    IC_PROFILE_START(IC_e_PROFSECT_P1_ROTATE_REGOUTPUT_BUFF); // PRQA S 3138,3141,3109
    ICRM_v_RotateOutputShadBuffers();
    IC_PROFILE_STOP(IC_e_PROFSECT_P1_ROTATE_REGOUTPUT_BUFF); // PRQA S 3138,3141,3109
    
    // Calc noise, blacklevel and response curve
    IC_PROFILE_START(IC_e_PROFSECT_P1_CALC_IMAGESTUFF); // PRQA S 3138,3141,3109
    e_Ret = ICCTL_e_CalcImageStuff();
    IC_PROFILE_STOP(IC_e_PROFSECT_P1_CALC_IMAGESTUFF); // PRQA S 3138,3141,3109
    
    // Do only provide results if normal mode is running at least since xx frames
    if (ICCTL_ui16_RunningModeExecCount >= ICCTL_cui16_SKIPRESULTS_RUNNINGCYCLES)
    {
      IC_PROFILE_START(IC_e_PROFSECT_P1_PROVIDERESULTS); // PRQA S 3138,3141,3109
      ICCTL_v_ProvideResultsPart1(&ICCTL_as_ResultsPart1[ICCTL_e_FrameType]);
      IC_PROFILE_STOP(IC_e_PROFSECT_P1_PROVIDERESULTS); // PRQA S 3138,3141,3109
    }
    
    // Execute cyclic databus check every 2nd frame, as the StereoDSP only processes ODD frames.
    //
    // IMPORTANT NOTE: The actual check is automatically done
    // during the register verification checks in ICRM_e_CheckRegisters(). The following
    // function only changes the pattern written to the register used for this test.
    if (IC_e_FRAMETYPE_ODD == ICCTL_e_FrameType)
    {
      e_SubRet = ICTM_e_ChangeDatabusTestpattern();
      if (IC_e_ERR_OK != e_SubRet)
      {
        e_Ret = ICERR_HANDLE(e_SubRet, 0);
      }
    }
    
    // Set image output size according to current frame type
    e_SubRet = ICCTL_e_SetCroi();
    if (IC_e_ERR_OK != e_SubRet)
    {
      e_Ret = ICERR_HANDLE(e_SubRet, 0);
      goto ERROR_EXIT;
    }
    
    #if (ICCFG_ENABLE_LEFT_IMAGER == 1)
    // Resync imagers
    if (b_TRUE == ICCTL_ab_InputUpdated[ICCTL_e_INPUTTYPE_IMGSYNC_REQ])
    {
      ICCTL_ab_InputUpdated[ICCTL_e_INPUTTYPE_IMGSYNC_REQ] = b_FALSE;
      e_SubRet = ICTIM_e_ResyncImagersSetLtoR(ICCTL_ps_Input->s_ImagerSyncReq.si16_ImageSyncOffsetRequested);
      if (IC_e_ERR_OK != e_SubRet)
      {
        e_Ret = ICERR_HANDLE(IC_e_ERR_IMGSYNC, 0);
      }
    }
    
    // Check measured image sync offset
    if (b_TRUE == ICCTL_ab_InputUpdated[ICCTL_e_INPUTTYPE_IMGSYNC_MEAS])
    {
      ICCTL_ab_InputUpdated[ICCTL_e_INPUTTYPE_IMGSYNC_MEAS] = b_FALSE;
      if (ICCTL_b_HILMODE_ACTIVE() != b_TRUE)
      {
        ICTIM_v_CheckFrameSync(ICCTL_ps_Input->s_ImagerSyncMeas.si16_ImageSyncOffsetMeasured);
      }
    }
    #endif
    
    // Handle total frame duration and jittering
    ICTIM_v_UpdateFrameTiming(ICCTL_e_FrameType);
    
    // Check I2C timing, but only if PART2 has been executed to suppress consecutive
    // errors.
    //
    // NOTE: Must be executed after ICTIM_e_UpdateFrameTiming(), otherwise
    //       the timing-offset between Left/Right image may not be correct,
    //       which is required for accurate calculation.
    if ((b_FALSE == b_Part2NotExecuted) && (b_FALSE == ICCTL_b_HILMODE_ACTIVE()))
    {
    #if (ICCFG_ENABLE_LEFT_IMAGER == 1)
      si32_ImgOffsetLR_us = ICTIM_si32_GetTimingOffsetLR_us();
    #else
      si32_ImgOffsetLR_us = 0;
    #endif
      ICRM_v_CheckI2CTiming((uint32)ICCTL_ui64_FrameStartUs, si32_ImgOffsetLR_us);
    }
    
    // Check communication statistics and add to accumulative runtime
    ICRM_v_UpdateCommStats(&IC_s_MeasData.s_TimingInfo.ui16_I2CIsrExecDurationLastCycleUs);
    ICCTL_ui16_AccumulativeRuntime += IC_s_MeasData.s_TimingInfo.ui16_I2CIsrExecDurationLastCycleUs;
    
    // Execute special functions if state is not running
    switch (ICCTL_e_State)
    {
    case ICCTL_e_STATE_DATABUS_TEST:
      // Execute databus test
      ICCTL_e_DBusTestResult = ICTM_e_DatabusCheckMainFunc();
      // NOTE: Return-code and Errors are handled in ICCTL_v_StateTransition()
      break;
    
    #if (IC_ANALOG_TEST_ENABLED == 1)
    case ICCTL_e_STATE_ANALOG_TEST:
      // Execute analog test
      e_SubRet = ICAT_e_Exec(ICCTL_ui16_FrameNum);
      if (IC_e_ERR_OK != e_SubRet)
      {
        e_Ret = e_SubRet;
      }
      break;
    #endif
    
    case ICCTL_e_STATE_COLUMN_CORRECTION:
      // Execute column correction
      ICCTL_v_ExecColumnCorrection();
      break;
    
    case ICCTL_e_STATE_RUNNING:
      // Enable or disable testpattern according to request-flags
    #if (ICCFG_ENABLE_LEFT_IMAGER == 1)
      if (b_TRUE == ICCTL_b_EnableTestpatternLeft)
      {
        ICCTL_b_EnableTestpatternLeft = b_FALSE;
        IMGDRV_v_SetTestpattern(IC_e_IMAGER_LEFT, IMGDRV_e_TESTPATTERN_WALKING_ONES);
      }
      if (b_TRUE == ICCTL_b_DisableTestpatternLeft)
      {
        ICCTL_b_DisableTestpatternLeft = b_FALSE;
        IMGDRV_v_SetTestpattern(IC_e_IMAGER_LEFT, IMGDRV_e_TESTPATTERN_NONE);
      }
    #endif
    
      // Execute cyclic column correction
      ICCTL_v_ExecColCorrCyclic();
      break;
    
    default:
      /* Should never be reached: do nothing */
      break;
    }
    
    // The FrameId is set to the LSB of the Framecounter and an additional identifier (MSB)
    #if (ICCFG_ENABLE_LEFT_IMAGER == 1)
    IMGDRV_v_SetFrameId(  ((uint16)ICCTL_aui8_FrameIdMSB[IC_e_IMAGER_LEFT]  << IC_NUMBITS_8)
                        | (ICCTL_ui16_FrameNum & IC_BITMASK_U8),
                        IC_e_IMAGER_LEFT);
    #endif
    IMGDRV_v_SetFrameId(  ((uint16)ICCTL_aui8_FrameIdMSB[IC_e_IMAGER_RIGHT] << IC_NUMBITS_8)
                        | (ICCTL_ui16_FrameNum & IC_BITMASK_U8),
                        IC_e_IMAGER_RIGHT);
    
    // Set timestamp for next image
    ICTIM_v_SetEmbeddedTimestamp(ICCTL_ui64_FrameStartUs);
    
    // Flush all changed regs from sensor-driver
    IC_PROFILE_START(IC_e_PROFSECT_P1_FLUSH_REGS); // PRQA S 3138,3141,3109
    e_SubRet = ICRM_e_WriteRegistersPart1();
    IC_PROFILE_STOP(IC_e_PROFSECT_P1_FLUSH_REGS); // PRQA S 3138,3141,3109
    if (IC_e_ERR_OK != e_SubRet)
    {
      e_Ret = ICERR_HANDLE(e_SubRet, 0);
      goto ERROR_EXIT;
    }
    
    // Schedule asynchronous register reads. Avoid disturbing HLA segmentation and do
    // this task only during even frame
    #if (IC_REGISTER_CHECK_I2C_ENABLED == 1)
    if (ICCTL_e_STATE_RUNNING ==  ICCTL_e_State)
    {
      if ((IC_e_FRAMETYPE_EVEN == ICCTL_e_FrameType) && (ICCTL_b_HILMODE_ACTIVE() != b_TRUE))
      {
        ICRM_v_HandleI2CRegChecks();
      }
    }
    #endif
    
    // Handle external (XCP) register read/write requests during odd frame
    if (IC_e_FRAMETYPE_ODD == ICCTL_e_FrameType)
    {
      ICRM_v_HandleRegTransExtReq();
    }
    
    // Read some registers from left imager when StereoDSP is not ready yet
    #if (ICCFG_ENABLE_LEFT_IMAGER == 1)
    if (b_TRUE == ICCTL_ps_Input->b_DSPNotAvailable)
    {
      ICRM_v_RegTransRxLeftSchedule();
    }
    #endif
    
    // Update measurement data
    ICCTL_ui32_MeasCounter++;
    IC_s_MeasData.ui32_MeasCounter      = ICCTL_ui32_MeasCounter;
    IC_s_MeasData.s_Controller.e_State  = ICCTL_e_State;
    IC_s_MeasData.s_OutputPart1         = ICCTL_as_ResultsPart1[ICCTL_e_FrameType];
    if (IC_e_FRAMETYPE_EVEN == ICCTL_e_FrameType)
    {
      IC_s_MeasData.s_TimingInfo.ui32_FramePeriodEvenUs = (uint32)ICCTL_ui64_FrameStartUs - ICCTL_aui32_LastFrameStartUs[IC_e_FRAMETYPE_EVEN];
      IC_s_MeasData.s_NoiseResultsEven = ICCTL_s_NCResults;
      ICCTL_aui32_LastFrameStartUs[IC_e_FRAMETYPE_EVEN] = (uint32)ICCTL_ui64_FrameStartUs;
    }
    else
    {
      IC_s_MeasData.s_TimingInfo.ui32_FramePeriodOddUs = (uint32)ICCTL_ui64_FrameStartUs - ICCTL_aui32_LastFrameStartUs[IC_e_FRAMETYPE_ODD];
      IC_s_MeasData.s_NoiseResultsOdd = ICCTL_s_NCResults;
      ICCTL_aui32_LastFrameStartUs[IC_e_FRAMETYPE_ODD] = (uint32)ICCTL_ui64_FrameStartUs;
    }
    IC_s_MeasData.ui16_FrameCounterReg                          = ICCTL_ps_EmbeddedData->ui16_FrameCounter;
    IC_s_MeasData.s_TimingInfo.ui32_Part1StartSinceFrameStartUs = ui32_StartTimeUs - (uint32)ICCTL_ui64_FrameStartUs;
    
    // If we are running on HIL, then resychronize ECU system time to embedded timestamp every odd frame
    if ((b_TRUE == ICCTL_b_HILMODE_ACTIVE()) && (IC_e_FRAMETYPE_ODD == ICCTL_e_FrameType))
    {
      // Resync ECU system time to embedded timestamp
      si64_TimeOffset = (sint64)ICCTL_ps_EmbeddedData->ui64_FrameTimestamp_us - (sint64)ICCTL_ui64_FrameStartUs;
      ICCTL_ps_PlatformFuncs->pfct_v_ResyncSystemTime(si64_TimeOffset);
      IC_s_MeasData.s_TimingInfo.si16_HilResyncOffset = (sint16)si64_TimeOffset;
    
      // Adjust frame start times to allow correct calculation of frame period
      ICCTL_aui32_LastFrameStartUs[IC_e_FRAMETYPE_EVEN] = (uint32)((sint64)ICCTL_aui32_LastFrameStartUs[IC_e_FRAMETYPE_EVEN] + si64_TimeOffset);
      ICCTL_aui32_LastFrameStartUs[IC_e_FRAMETYPE_ODD]  = (uint32)((sint64)ICCTL_aui32_LastFrameStartUs[IC_e_FRAMETYPE_ODD]  + si64_TimeOffset);
    }
    
    // Report non-failed DEMs as "weak" passed
    ICERR_v_DemPassedWeak(IC_e_DEM_GENERAL);
    ICERR_v_DemPassedWeak(IC_e_DEM_GENERAL_FATAL);
    ICERR_v_DemPassedWeak(IC_e_DEM_IMAGER_COMM);
    ICERR_v_DemPassedWeak(IC_e_DEM_IMAGER_COMM_R);
    ICERR_v_DemPassedWeak(IC_e_DEM_INPUTS);
    ICERR_v_DemPassedWeak(IC_e_DEM_PART1_NOTCALLED);
    ICERR_v_DemPassedWeak(IC_e_DEM_PART2_NOTCALLED);
    ICERR_v_DemPassedWeak(IC_e_DEM_REGTX_SYNC_VERIFY_FAILED_R);
    ICERR_v_DemPassedWeak(IC_e_DEM_SOFTWARE_TIMING);
    #if (ICCFG_ENABLE_LEFT_IMAGER == 1)
    ICERR_v_DemPassedWeak(IC_e_DEM_IMAGER_COMM_L);
    ICERR_v_DemPassedWeak(IC_e_DEM_REGTX_SYNC_VERIFY_FAILED_L);
    ICERR_v_DemPassedWeak(IC_e_DEM_INPUTS_DSP2);
    #endif
    
    // Increment post-init execution counter
    if (ICCTL_ui16_PostInitExecCount < TYPEMAX_UI16)
    {
      ICCTL_ui16_PostInitExecCount++;
    }
    if ((ICCTL_ui16_RunningModeExecCount < TYPEMAX_UI16) && (ICCTL_e_STATE_RUNNING == ICCTL_e_State))
    {
      ICCTL_ui16_RunningModeExecCount++;
    }
    
    // Remember last frame-counter
    ICCTL_ui16_OldFrameCounter = ICCTL_ui16_FrameNum;
    
    // Done
    ICCTL_e_ExecSubstate = ICCTL_e_EXECSTATE_PART2;
    
    ERROR_EXIT:
    
    // Flush DEM status and update runtime
    IC_PROFILE_START(IC_e_PROFSECT_P1_DEMFLUSH); // PRQA S 3138,3141,3109
    ICERR_v_DemFlush();
    IC_PROFILE_STOP(IC_e_PROFSECT_P1_DEMFLUSH); // PRQA S 3138,3141,3109
    IC_s_MeasData.s_TimingInfo.ui16_Part1ExecDurationUs = (uint16)(ICOSW_ui32_GetTimeUs() - ui32_StartTimeUs);
    IC_PROFILE_STOP(IC_e_PROFSECT_P1_TOTAL); // PRQA S 3138,3141,3109
    return e_Ret;
    
    // PRQA S 7002,7004,7006 2
    /*#]*/
}

/*## operation ICCTL_e_ExecPart2(const uint16 * const,const uint16 * const) */
static IC_E_ERROR ICCTL_e_ExecPart2(const uint16 * const pui16_EmbStatLine0, const uint16 * const pui16_EmbStatLine1) {
    /*#[ operation ICCTL_e_ExecPart2(const uint16 * const,const uint16 * const) */
    // Local variables
    IC_E_ERROR  e_Ret                = IC_e_ERR_OK;
    IC_E_ERROR  e_SubRet             = IC_e_ERR_OK;
    sint16      si16_Ret             = IEDP_csi16_NOERROR;
    uint32      ui32_StartTimeUs     = 0;
    uint16      ui16_Runtime         = 0;
    uint16      ui16_TotalRuntime    = 0;
    
    // Start profiling
    IC_PROFILE_START(IC_e_PROFSECT_P2_TOTAL); // PRQA S 3138,3141,3109
    
    // Prerequisites
    if (ICCTL_e_State <= ICCTL_e_STATE_WAIT_START)
    {
      e_Ret = IC_e_ERR_WRONG_STATE;
      goto ERROR_EXIT;
    }
    if (ICCTL_e_EXECSTATE_PART2 != ICCTL_e_ExecSubstate)
    {
      e_Ret = ICERR_HANDLE(IC_e_ERR_PART1_NOT_CALLED, ICCTL_e_ExecSubstate);
      goto ERROR_EXIT;
    }
    
    // Remember start-time
    ui32_StartTimeUs = ICOSW_ui32_GetTimeUs();
    
    // Update error manager context data (for DEM optional data, aka. PreExtData)
    ICCTL_v_UpdateErrContext();
    
    // The first embedded data after init is corrupted, so stop execution then
    if (ICCTL_ui16_PostInitExecCount < ICCTL_cui16_SKIPPART2EXEC_POSTINITCYCLES)
    {
      e_Ret = IC_e_ERR_OK;
      goto NOERROR_EXIT;
    }
    
    // Extract embedded statistics from image
    si16_Ret = IEDP_si16_ExtractStatistics(pui16_EmbStatLine0, pui16_EmbStatLine1, ICCTL_ps_StatisticsData);
    if (IEDP_csi16_NOERROR != si16_Ret)
    {
      ICERR_v_DemFailed(IC_e_DEM_EMBEDDED_STAT_CORRUPTED, (uint32)si16_Ret);
      e_Ret = ICERR_HANDLE(IC_e_ERR_EMBEDDED_STAT_CORRUPTED, ICCTL_ui16_FrameNum);
    }
    else
    {
      ICERR_v_DemPassed(IC_e_DEM_EMBEDDED_STAT_CORRUPTED);
    }
    
    // Extract histogram from embedded data
    IC_PROFILE_START(IC_e_PROFSECT_P2_EXTRACT_HISTOGRAM); // PRQA S 3138,3141,3109
    si16_Ret = IEDP_si16_ExtractHistogram(pui16_EmbStatLine0, &ICCTL_s_ImageData.s_HistogramData);
    IC_PROFILE_STOP(IC_e_PROFSECT_P2_EXTRACT_HISTOGRAM); // PRQA S 3138,3141,3109
    if (IEDP_csi16_NOERROR != si16_Ret)
    {
      ICERR_v_DemFailed(IC_e_DEM_EMBEDDED_STAT_CORRUPTED, (uint32)si16_Ret);
      e_Ret = ICERR_HANDLE(IC_e_ERR_EMBEDDED_HIST_CORRUPTED, ICCTL_ui16_FrameNum);
    }
    
    // Skip some code if exposure control is explicitly disabled via external control interface
    if (ICCTL_cui32_KEY_EXPOSURE_DISABLE != ICCTL_ui32_IcExposureDisabled)
    {
      // Do checks of statistics data
      e_SubRet = ICCTL_e_NewStatDataChecks();
      if (IC_e_ERR_OK != e_SubRet)
      {
        e_Ret = e_SubRet;
      }
    
      // Only run exposure control if we are in running state
      if (ICCTL_e_STATE_RUNNING == ICCTL_e_State)
      {
        // Execute exposure control stuff and get results
        IC_PROFILE_START(IC_e_PROFSECT_P2_EXPOSURE); // PRQA S 3138,3141,3109
        e_SubRet = ICEXPMG_e_Exec(ICCTL_e_FrameType, &ICCTL_s_ImageData, &ICCTL_s_ICRois[ICCTL_e_FrameType], ICCTL_b_ForceDcgChange);
        IC_PROFILE_STOP(IC_e_PROFSECT_P2_EXPOSURE); // PRQA S 3138,3141,3109
        if (IC_e_ERR_OK != e_SubRet)
        {
          e_Ret = ICERR_HANDLE(e_SubRet, ICCTL_e_FrameType);
        }
        ICEXPMG_v_GetResults(&ICCTL_as_IcExpResults[ICCTL_e_FrameType], ICCTL_e_FrameType);
    
        // Reset flag just to be safe
        ICCTL_b_ForceDcgChange = b_FALSE;
      }
    
      // Update IC-ROI
      #if (IC_ONLINECALIB_USE_LD == 1)
      e_SubRet = ICROI_e_SetupICRoiLd(&ICCTL_s_ICRois[ICCTL_e_FrameType], &ICCTL_ps_Input->s_LdOnlineCalib, &ICCTL_ps_Input->s_VehicleDyn, ICCTL_e_FrameType);
      #else
      e_SubRet = ICROI_e_SetupICRoiHla(&ICCTL_s_ICRois[ICCTL_e_FrameType], &ICCTL_ps_Input->s_HlaOnlineCalib, ICCTL_e_FrameType);
      #endif
      if (IC_e_ERR_OK != e_SubRet)
      {
        e_Ret = ICERR_HANDLE(e_SubRet, 0);
      }
    
      // ATTENTION: Writing IC-ROI registers become active immediately, so when we are here at the end-of-frame,
      //            we have to write the "other" frame type's value (that from the following image)
      e_SubRet = IMGDRV_e_SetICROI(&ICCTL_s_ICRois[ICCTL_e_FrameTypeOther]);
      if (IC_e_ERR_OK != e_SubRet)
      {
        e_Ret = ICERR_HANDLE(IC_e_ERR_IMGDRV_SET_ICROI, ICCTL_s_ICRois[ICCTL_e_FrameTypeOther].ui16_StartY);
      }
    
      // Flush registers
      IC_PROFILE_START(IC_e_PROFSECT_P2_FLUSH_REGS); // PRQA S 3138,3141,3109
      e_SubRet = ICRM_e_WriteRegistersPart2();
      IC_PROFILE_STOP(IC_e_PROFSECT_P2_FLUSH_REGS); // PRQA S 3138,3141,3109
      if (IC_e_ERR_OK != e_SubRet)
      {
        e_Ret = ICERR_HANDLE(e_SubRet, 0);
        goto ERROR_EXIT;
      }
    }
    else
    {
      // Exposure control is disabled ... check if we have to write initial values
      if (b_TRUE == ICCTL_b_ExposureRegsSetToInit)
      {
        // Set initial register values
        ICCTL_v_SetExposureRegsToInit();
        ICCTL_b_ExposureRegsSetToInit = b_FALSE;
    
        // Flush changed registers to the imager
        e_SubRet = ICRM_e_WriteRegistersPart2();
        e_Ret = ICERR_HANDLE(e_SubRet, 0);
      }
    }
    
    // Execute cyclic databus test, needs frame-counter from statistical data
    #if (IC_DATABUS_CHECK_VIA_NOISE_ENABLED == 1)
    if (ICCTL_e_State == ICCTL_e_STATE_RUNNING)
    {
      ICTM_v_DatabusCheckNoiseMainFunc(ICCTL_ps_StatisticsData->ui16_FrameCounter);
    }
    #endif
    
    // Update/read temperature values
    ICCTL_v_UpdateTemperatures();
    
    // Collect and provide results for other functions
    IC_PROFILE_START(IC_e_PROFSECT_P2_PROVIDERESULTS); // PRQA S 3138,3141,3109
    ICCTL_v_ProvideResultsPart2(&ICCTL_as_ResultsPart2[ICCTL_e_FrameType]);
    IC_PROFILE_STOP(IC_e_PROFSECT_P2_PROVIDERESULTS); // PRQA S 3138,3141,3109
    IC_s_MeasData.s_OutputPart2 = ICCTL_as_ResultsPart2[ICCTL_e_FrameType];
    
    // Update measurement data
    IC_s_MeasData.s_Input = *ICCTL_ps_Input;
    IC_s_MeasData.s_TimingInfo.ui32_Part2StartSinceFrameStartUs = ui32_StartTimeUs - (uint32)ICCTL_ui64_FrameStartUs;
    IC_s_MeasData.s_ImagerInfos.f32_TempRightC = ICCTL_af32_ImagerTemperatures[IC_e_IMAGER_RIGHT];
    #if (ICCFG_ENABLE_LEFT_IMAGER == 1)
    IC_s_MeasData.s_ImagerInfos.f32_TempLeftC  = ICCTL_af32_ImagerTemperatures[IC_e_IMAGER_LEFT];
    #endif
    IC_s_MeasData.ui16_FrameCounterStat        = ICCTL_ps_StatisticsData->ui16_FrameCounter;
    IC_s_MeasData.s_EmbeddedStatData           = *ICCTL_ps_StatisticsData;
    IC_s_MeasData.s_EmbeddedRegData            = *ICCTL_ps_EmbeddedData;
    if (IC_e_FRAMETYPE_EVEN == ICCTL_e_FrameType)
    {
      #if (IC_EXPOSURE_EVEN_MEASDATA == 1)
      IC_s_MeasData.s_ResponseCurveEven = ICCTL_as_ResponseCurve[IC_e_FRAMETYPE_EVEN];
      #endif
    }
    else
    {
      IC_s_MeasData.s_ResponseCurveOdd  = ICCTL_as_ResponseCurve[IC_e_FRAMETYPE_ODD];
    }
    
    // Execute measfreeze: Exposure control module
    IC_PROFILE_START(IC_e_PROFSECT_P2_MEASFREEZE); // PRQA S 3138,3141,3109
    if (ICCTL_e_STATE_RUNNING == ICCTL_e_State)
    {
      // On single-exposure cameras (MFC316), we do not control the even frame, so there is only
      // exposure measfreeze for the odd frame available:
    #if (IC_EXPOSURE_EVEN_MEASDATA == 0)
      if (IC_e_FRAMETYPE_ODD == ICCTL_e_FrameType)
      {
        ICCTL_v_ExecMeasfreezeExposure();
      }
    #else
      ICCTL_v_ExecMeasfreezeExposure();
    #endif
    }
    
    // Calculate runtimes and add to measurement data. As we are now at the last code executed in this cycle,
    // reset accumulator and individual times here.
    ui16_Runtime             = (uint16)(ICOSW_ui32_GetTimeUs() - ui32_StartTimeUs);
    ui16_TotalRuntime        = ICCTL_ui16_AccumulativeRuntime;
    ICCTL_ui16_AccumulativeRuntime = 0;
    IC_s_MeasData.s_TimingInfo.ui16_Part2ExecDurationUs = ui16_Runtime;
    IC_s_MeasData.s_TimingInfo.ui16_TotalExecDurationUs = ui16_TotalRuntime;
    
    // Execute measfreeze: Common data
    ICCTL_v_ExecMeasfreeze();
    IC_PROFILE_STOP(IC_e_PROFSECT_P2_MEASFREEZE); // PRQA S 3138,3141,3109
    
    // Toggle debug-led
    ICCTL_v_DebugLedToggle();
    
    // Done / error handling
    NOERROR_EXIT:
    ERROR_EXIT:
    ICCTL_e_ExecSubstate = ICCTL_e_EXECSTATE_PART1;
    
    // Flush DEM status
    IC_PROFILE_START(IC_e_PROFSECT_P2_DEMFLUSH); // PRQA S 3138,3141,3109
    ICERR_v_DemFlush();
    IC_PROFILE_STOP(IC_e_PROFSECT_P2_DEMFLUSH); // PRQA S 3138,3141,3109
    IC_PROFILE_STOP(IC_e_PROFSECT_P2_TOTAL); // PRQA S 3138,3141,3109
    return e_Ret;
    
    // PRQA S 7002,7006 2
    /*#]*/
}

/*## operation ICCTL_v_ProvideResultsPart1(IC_S_ResultsPart1 * const) */
static void ICCTL_v_ProvideResultsPart1(IC_S_ResultsPart1 * const ps_Results) {
    /*#[ operation ICCTL_v_ProvideResultsPart1(IC_S_ResultsPart1 * const) */
    // The intraday-state that was valid at time of exposure of the current frame
    // is the output/next-value from the last execution of the exposure control
    ps_Results->e_IntradayState  = ICCTL_as_IcExpResults[ICCTL_e_FrameType].e_IntradaystateNext;
    
    // Collect other results
    ps_Results->e_FrameType      = ICCTL_e_FrameType;
    ps_Results->f32_Blacklevel   = ICCTL_s_NCResults.f32_BlacklevelFiltered;
    ps_Results->f32_NoiseStdDev  = ICCTL_s_NCResults.f32_NoiseStdDevToAlgo;
    ps_Results->ps_EmbeddedData  = ICCTL_ps_EmbeddedData;
    ps_Results->ps_ResponseCurve = ICCTL_ps_ResponseCurve;
    ps_Results->b_DualExposureEnabled = ICCTL_as_IcExpResults[ICCTL_e_FrameType].b_DualExposureEnabled;
    
    // Request registers for left imager
    #if (ICCFG_ENABLE_LEFT_IMAGER == 1)
    ICRM_v_GetRegisterRequest(&ps_Results->s_RegTransferRequest);
    #endif
    
    // Call notification callback function
    if (ICCTL_ps_PlatformFuncs->pfct_ResultsPart1Available != NULL)
    {
      ICCTL_ps_PlatformFuncs->pfct_ResultsPart1Available(ps_Results);
    }
    /*#]*/
}

/*## operation ICCTL_v_ProvideResultsPart2(IC_S_ResultsPart2 * const) */
static void ICCTL_v_ProvideResultsPart2(IC_S_ResultsPart2 * const ps_Results) {
    /*#[ operation ICCTL_v_ProvideResultsPart2(IC_S_ResultsPart2 * const) */
    ICEXPMG_S_Results * const ps_ExpResults = &ICCTL_as_IcExpResults[ICCTL_e_FrameType];
    
    // Collect results
    ps_Results->ui64_FrameTimestamp    = ICCTL_ps_EmbeddedData->ui64_FrameTimestamp_us;
    ps_Results->ui16_FrameNum          = ICCTL_ps_StatisticsData->ui16_FrameCounter;
    ps_Results->ui32_LumaMeanWeighted  = ps_ExpResults->ui32_LumaMeanWeighted;
    ps_Results->ui16_LumaMeanCompanded = IRCC_ui16_Calc12BitCompandedMean(&ICCTL_s_IRCCObj, ps_ExpResults->ui32_LumaMeanWeighted);
    ps_Results->f32_BrightnessCdqm     = IRCC_f32_CalcBrightnessCd(&ICCTL_s_IRCCObj, ps_ExpResults->ui32_LumaMeanWeighted);
    ps_Results->ps_StatisticsData      = ICCTL_ps_StatisticsData;
    
    // Call notification callback function
    if (ICCTL_ps_PlatformFuncs->pfct_ResultsPart2Available != NULL)
    {
      ICCTL_ps_PlatformFuncs->pfct_ResultsPart2Available(ps_Results);
    }
    /*#]*/
}

/*## operation ICCTL_v_CheckNewInputs(const IC_S_Input * const,const uint64) */
static void ICCTL_v_CheckNewInputs(const IC_S_Input * const ps_In, const uint64 ui64_CurrentTimeUs) {
    /*#[ operation ICCTL_v_CheckNewInputs(const IC_S_Input * const,const uint64) */
    uint32 ui32_Index      = 0;
    uint64 ui64_NewSrcTs   = 0;
    uint64 ui64_LastSrcTs  = 0;
    sint64 si64_Delta      = 0;
    boolean b_NewData      = b_FALSE;
    boolean b_SkipCheck    = b_FALSE;
    ICCTL_E_INPUTTYPE e_InType;
    IC_E_ERROR e_ErrorCode = IC_e_ERR_OK;
    
    // Loop through all input signal types
    for (ui32_Index = 0; ui32_Index < ICCTL_e_INPUTTYPE__NUM_ENTRIES__; ui32_Index++)
    {
      b_SkipCheck = b_FALSE;
      b_NewData   = b_FALSE;
    
      // Get timestamp for current input signal
      e_InType = (ICCTL_E_INPUTTYPE)ui32_Index; // PRQA S 1482
      switch (e_InType)
      {
      case ICCTL_e_INPUTTYPE_VEHDYN:
        ui64_NewSrcTs = ps_In->s_VehicleDyn.ui64_Timestamp;
        b_SkipCheck = ps_In->b_AlgosNotAvailable;
        break;
    #if (ICCFG_ENABLE_LEFT_IMAGER == 1)
      case ICCTL_e_INPUTTYPE_IMGSYNC_MEAS:
        ui64_NewSrcTs = ps_In->s_ImagerSyncMeas.ui64_Timestamp;
        if ((b_TRUE == ps_In->b_DSPNotAvailable) || (b_TRUE == ps_In->b_AlgosNotAvailable))
        {
          b_SkipCheck = b_TRUE;
        }
        break;
      case ICCTL_e_INPUTTYPE_IMGSYNC_REQ:
        ui64_NewSrcTs = ps_In->s_ImagerSyncReq.ui64_Timestamp;
        if ((b_TRUE == ps_In->b_DSPNotAvailable) || (b_TRUE == ps_In->b_AlgosNotAvailable))
        {
          b_SkipCheck = b_TRUE;
        }
    
        // Special handling for image sync request signal: As the value is always constant,
        // we only need one, so disable checks after first signal reception
        b_SkipCheck |= ICCTL_b_ImgSyncReqReceived;
        break;
      case ICCTL_e_INPUTTYPE_REGRESP:
        ui64_NewSrcTs = ps_In->s_RegTransfResponse.ui64_Timestamp;
        b_SkipCheck = ps_In->b_DSPNotAvailable;
        break;
    #endif
    #if (IC_ONLINECALIB_USE_LD == 1)
      case ICCTL_e_INPUTTYPE_LDONLINECALIB:
        ui64_NewSrcTs = ps_In->s_LdOnlineCalib.ui64_Timestamp;
        b_SkipCheck = ps_In->b_AlgosNotAvailable;
        break;
    #endif
      default:
        b_SkipCheck = b_TRUE;
        break;
      }
    
      // Is there new data available for current signal?
      ui64_LastSrcTs = ICCTL_ui64_LastInputSrcTime[e_InType];
      if (ui64_LastSrcTs != ui64_NewSrcTs)
      {
        b_NewData = b_TRUE;
        ICCTL_ui64_LastInputSrcTime [e_InType] = ui64_NewSrcTs;
        ICCTL_ui64_LastInputRecvTime[e_InType] = ui64_CurrentTimeUs;
    
        // Mark this input signal as updated, but only if timestamp is not zero!
        if (ui64_NewSrcTs != 0)
        {
          ICCTL_ab_InputUpdated[e_InType] = b_TRUE;
        }
      }
      b_SkipCheck |= b_NewData;
    
      // Check timeout if there has been no new data received
      if (b_TRUE != b_SkipCheck)
      {
        // Check first signal reception timeout
        si64_Delta = (sint64)ui64_CurrentTimeUs - (sint64)ICCTL_ui64_IcStartTimestamp;
        if (si64_Delta > (sint64)ICCFG_cui32_INPUTTIMEOUT_FIRSTDATA_US)
        {
          // Check for current signal periodic timeout
          si64_Delta = (sint64)ui64_CurrentTimeUs - (sint64)ICCTL_ui64_LastInputRecvTime[e_InType];
          if (si64_Delta > (sint64)ICCFG_cui32_INPUTTIMEOUT_MAXPERIOD_US)
          {
            // Signal timed out! Report error!
            e_ErrorCode = ICCTL_cae_InputTimeoutErrCodes[e_InType];
            (void)ICERR_HANDLE(e_ErrorCode, (sint32)si64_Delta); // PRQA S 3212
          }
        }
      }
    }
    
    // Mark (first) reception of requested image sync offset
    #if (ICCFG_ENABLE_LEFT_IMAGER == 1)
    ICCTL_b_ImgSyncReqReceived |= ICCTL_ab_InputUpdated[ICCTL_e_INPUTTYPE_IMGSYNC_REQ];
    #endif
    
    // PRQA S 7002 2
    /*#]*/
}

/*## operation ICCTL_v_StateTransition() */
static void ICCTL_v_StateTransition(void) {
    /*#[ operation ICCTL_v_StateTransition() */
    IC_E_ERROR e_SubRet = IC_e_ERR_OK;
    boolean b_GotoNextState = b_FALSE;
    #if (IC_ANALOG_TEST_ENABLED == 1)
    IC_E_ATEST_STATUS e_AnalogTestStatus;
    #endif
    
    // We must skip databus-check and analog-test when we are connected to a HIL.
    // Variables can not be const due to project variants:
    // PRQA S 3204 2
    boolean b_SkipDatabusCheck = ICCTL_b_HILMODE_ACTIVE();
    boolean b_SkipAnalogTest   = ICCTL_b_HILMODE_ACTIVE();
    if (ICCTL_cui32_KEY_ATEST_DISABLE == ICCTL_ui32_SkipAnalogTest)
    {
      b_SkipAnalogTest = b_TRUE;
    }
    
    // Skip databus-check and/or analog-test if disabled in ic_cfg.h
    #if (IC_DATABUS_CHECK_STARTUP_ENABLED == 0)
    b_SkipDatabusCheck = b_TRUE;
    #endif
    #if (IC_ANALOG_TEST_ENABLED == 0)
    b_SkipAnalogTest = b_TRUE;
    
    // Do not skip atest if triggered via XCP
    if (ICCTL_b_ATestExternalTrigger)
    {
      b_SkipAnalogTest = b_FALSE;
    }
    #endif
    
    // Now do state transition based on current state and specific conditions
    switch (ICCTL_e_State)
    {
    case ICCTL_e_STATE_INIT:
      if (b_TRUE == ICCTL_b_Initialized)
      {
        ICCTL_e_ExecSubstate = ICCTL_e_EXECSTATE_PART1;
        ICCTL_e_State = ICCTL_e_STATE_WAIT_START;
      }
      break;
    
    case ICCTL_e_STATE_WAIT_START:
      if (b_TRUE == ICCTL_b_Started)
      {
        ICCTL_ui64_IcStartTimestamp = ICOSW_ui64_GetTimeUs();
        IC_PROFILE_STOP(IC_e_PROFSECT_INIT_FINISH_2_IC_START); // PRQA S 3138,3141,3109
        IC_PROFILE_START(IC_e_PROFSECT_START_2_DBTEST_DONE); // PRQA S 3138,3141,3109
        IC_PROFILE_START(IC_e_PROFSECT_START_2_ATEST_DONE); // PRQA S 3138,3141,3109
        IC_PROFILE_START(IC_e_PROFSECT_START_2_RUNNINGSTABLE); // PRQA S 3138,3141,3109
    
        // Determine next state
        if (b_TRUE != b_SkipDatabusCheck)
        {
          ICCTL_e_State = ICCTL_e_STATE_DATABUS_TEST;
        }
    #if (IC_ANALOG_TEST_ENABLED == 1)
        else if (b_TRUE != b_SkipAnalogTest)
        {
          ICCTL_e_State = ICCTL_e_STATE_ANALOG_TEST;
        }
    #endif
        else
        {
          ICCTL_e_State = ICCTL_e_STATE_COLUMN_CORRECTION;
        }
      }
      break;
    
    case ICCTL_e_STATE_DATABUS_TEST:
      switch (ICCTL_e_DBusTestResult)
      {
      case ICTM_e_DBUS_RESULT_FINISHED_OK:
        ICERR_v_DemPassed(IC_e_DEM_IMAGER_DATABUS_MCU_STARTUP);
        b_GotoNextState = b_TRUE;
        break;
    
      case ICTM_e_DBUS_RESULT_FINISHED_FAILED:
        (void)ICERR_HANDLE(IC_e_ERR_DATABUSTEST_FAILED, ICCTL_e_DBusTestResult);
        ICERR_v_DemFailed(IC_e_DEM_IMAGER_DATABUS_MCU_STARTUP, (uint32)ICCTL_e_DBusTestResult);
        b_GotoNextState = b_TRUE;
        break;
    
      case ICTM_e_DBUS_RESULT_ERROR:
        (void)ICERR_HANDLE(IC_e_ERR_DATABUSTEST_FAILED, ICCTL_e_DBusTestResult);
        ICERR_v_DemFailed(IC_e_DEM_IMAGER_DATABUS_MCU_STARTUP, (uint32)ICCTL_e_DBusTestResult);
        b_GotoNextState = b_TRUE;
        break;
    
      default:
        // Not finished yet ...
        break;
      }
    
      // Determine next state
      if (b_TRUE == b_GotoNextState)
      {
    #if (IC_ANALOG_TEST_ENABLED == 1)
        if (b_TRUE != b_SkipAnalogTest)
        {
          ICCTL_e_State = ICCTL_e_STATE_ANALOG_TEST;
        }
        else
    #endif
        {
          ICCTL_e_State = ICCTL_e_STATE_COLUMN_CORRECTION;
        }
    
        // Profile finish time
        IC_PROFILE_STOP(IC_e_PROFSECT_START_2_DBTEST_DONE); // PRQA S 3138,3141,3109
      }
      break;
    
    #if (IC_ANALOG_TEST_ENABLED == 1)
    case ICCTL_e_STATE_ANALOG_TEST:
      if (ICAT_e_GetStatus() == IC_e_ATEST_STATUS_NOT_STARTED)
      {
        // Start analog test execution
        e_SubRet = ICAT_e_Start();
        (void)ICERR_HANDLE(e_SubRet, 0);
      }
      else if (ICAT_b_IsAnalogTestFinished() == b_TRUE)
      {
        ICCTL_b_ATestExternalTrigger = b_FALSE;
    
        // Analog test is finished, so notify caller
        if (NULL != ICCTL_pfct_ATestFinishedCb)
        {
          ICCTL_pfct_ATestFinishedCb();
          ICCTL_pfct_ATestFinishedCb = NULL;
        }
    
        // Handle status
        e_AnalogTestStatus = ICAT_e_GetStatus();
        if (e_AnalogTestStatus == IC_e_ATEST_STATUS_FINISHED_PASSED)
        {
          ICERR_v_DemPassed(IC_e_DEM_IMAGER_ATEST_R);
        }
        else
        {
          // Reason why ATEST failed (internal IC error-code) is much better handled in error manager,
          // so keep data if DEM is already set to failed.
          ICERR_v_DemFailedKeep(IC_e_DEM_IMAGER_ATEST_R, (uint32)e_AnalogTestStatus);
        }
    
        // Goto next state
        ICCTL_e_State = ICCTL_e_STATE_COLUMN_CORRECTION;
        IC_PROFILE_STOP(IC_e_PROFSECT_START_2_ATEST_DONE); // PRQA S 3138,3141,3109
      }
      else
      {
        // Analog test is still executing ...
      }
      break;
    #endif
    
    case ICCTL_e_STATE_COLUMN_CORRECTION:
      if (ICCTL_e_COLCORRSTATE_FINISHED == ICCTL_e_ColCorrState)
      {
        ICCTL_e_State = ICCTL_e_STATE_RUNNING;
      }
      break;
    
    case ICCTL_e_STATE_RUNNING:
    #if (IC_ANALOG_TEST_ENABLED == 1)
      if (b_TRUE == ICCTL_b_ATestExternalTrigger)
      {
        // Enter analog test state
        ICCTL_e_State = ICCTL_e_STATE_ANALOG_TEST;
      }
    #endif
      break;
    
    default:
      // Never reachable
      (void)ICERR_HANDLE(IC_e_ERR_FATAL_PROGRAM_ERROR, 0);
      break;
    }
    
    // Update error manager context data
    ICCTL_v_UpdateErrContext();
    
    // Profile IC running stable time
    if ((ICCTL_e_STATE_RUNNING == ICCTL_e_State) && (ICCTL_ui16_RunningModeExecCount == 0))
    {
      IC_PROFILE_STOP(IC_e_PROFSECT_START_2_RUNNINGSTABLE); // PRQA S 3138,3141,3109
    }
    
    // PRQA S 7002,7004 2
    /*#]*/
}

/*## operation ICCTL_e_ExtractRegs(const uint16 * const,const uint16 * const) */
static IC_E_ERROR ICCTL_e_ExtractRegs(const uint16 * const pui16_EmbDatLine0, const uint16 * const pui16_EmbDatLine1) {
    /*#[ operation ICCTL_e_ExtractRegs(const uint16 * const,const uint16 * const) */
    IC_E_ERROR e_Ret                     = IC_e_ERR_OK;
    IC_E_ERROR e_CheckErr                = IC_e_ERR_OK;
    sint16     si16_Ret                  = 0;
    uint16     ui16_FailedPixelPos       = 0;
    sint16     si16_FailedPixelCpyOffset = 0;
    uint32     ui32_OptData              = 0;
    uint16     ui16_LineIndex            = 0;
    uint16 const *pui16_CurrLine         = NULL;
    
    // Check integrity of all (both) embedded data lines
    ICCTL_b_CorruptedRegs = b_FALSE;
    IC_PROFILE_START(IC_e_PROFSECT_P1_EMBDAT_CHECK); // PRQA S 3138,3141,3109
    for (ui16_LineIndex = 0; ui16_LineIndex < ICCFG_cui16_NumEmbeddedRegLines; ui16_LineIndex++)
    {
      // Set parameters for current line
      switch (ui16_LineIndex)
      {
      case 0u:
        pui16_CurrLine = pui16_EmbDatLine0;
        e_CheckErr = IC_e_ERR_EMBEDDED_REGS_LINE0_CORRUPTED;
        break;
    
      case 1u:
        pui16_CurrLine = pui16_EmbDatLine1;
        e_CheckErr = IC_e_ERR_EMBEDDED_REGS_LINE1_CORRUPTED;
        break;
    
      default:
        // Unreachable
        e_Ret = ICERR_HANDLE(IC_e_ERR_FATAL_PROGRAM_ERROR, 0);
        goto ERROR_EXIT;
      }
    
      // Execute integrity check
      si16_Ret = IEDP_si16_CheckRegisterLine(pui16_CurrLine, ui16_LineIndex, &ui16_FailedPixelPos);
      if (IEDP_csi16_NOERROR != si16_Ret)
      {
        // We have corrupted register data!
        ICCTL_b_CorruptedRegs = b_TRUE;
    
        // Report error and DEM
        // PRQA S 3120 2
        ui32_OptData = ((uint32)ui16_LineIndex      << 31u)
                     | ((uint32)ui16_FailedPixelPos << 16u)
                     | ((uint32)ICCTL_ui16_FrameNum       );
        e_Ret = ICERR_HANDLE(e_CheckErr, ui32_OptData);
        ICERR_v_DemFailed(IC_e_DEM_EMBEDDED_REGS_CORRUPTED, ui32_OptData);
    
        // Copy 32 pixels of embedded data around the failed pixel to the meas struct
        // (failed pixel is in the middle at index 16))
        // PRQA S 3120 2
        si16_FailedPixelCpyOffset = (sint16)ui16_FailedPixelPos
                                  - (sint16)(IC_ARRLEN(IC_s_MeasData.s_EmbeddedDataDebug.aui16_CorruptedLineContext) / 2);
        IC_s_MeasData.s_EmbeddedDataDebug.si16_CorruptedLine_CpyOffset = si16_FailedPixelCpyOffset;
        IC_s_MeasData.s_EmbeddedDataDebug.ui16_CorruptedLine_FailedPix = ui16_FailedPixelPos;
        IC_s_MeasData.s_EmbeddedDataDebug.ui16_CorruptedLineNum        = ui16_LineIndex;
        (void)memcpy(IC_s_MeasData.s_EmbeddedDataDebug.aui16_CorruptedLineContext,
            pui16_CurrLine + si16_FailedPixelCpyOffset, // PRQA S 0501,0488,0510
            (size_t)sizeof(IC_s_MeasData.s_EmbeddedDataDebug.aui16_CorruptedLineContext));
      }
    }
    IC_PROFILE_STOP(IC_e_PROFSECT_P1_EMBDAT_CHECK); // PRQA S 3138,3141,3109
    
    // Extract frame-number if data is not corrupted
    if (b_FALSE == ICCTL_b_CorruptedRegs)
    {
      ICCTL_ui16_FrameNum = IEDP_ui16_GetFrameNumber(pui16_EmbDatLine0);
      ICERR_v_DemPassed(IC_e_DEM_EMBEDDED_REGS_CORRUPTED);
    }
    else
    {
      // THAT's VERY BAD, WE HAVE CORRUPTED EMBEDDED DATA !! Frame-counter has already been
      // incremented in line-callback when linenumber wraparound has been detected, so framecounter
      // should be fine here if there was no frame-drop. Don't simply abort IC cycle here
      // as it would cause wrong frame-sizes, bright/dark flashes etc.
    }
    
    // Determine frame-type
    ICCTL_e_FrameType      = IC_e_ImageCounterToFrameType(ICCTL_ui16_FrameNum);
    ICCTL_e_FrameTypeOther = IC_e_ImageCounterToFrameType(ICCTL_ui16_FrameNum + 1);
    
    // Get target buffer for embedded register data
    ICCTL_pRb_RegsInR = ICRM_pRb_GetRegistersIn(IC_e_IMAGER_RIGHT, ICCTL_e_FrameType);
    
    // Extract all register-data from image if not corrupted. Else do nothing and keep old values,
    // but update frame-counter register.
    if (b_FALSE == ICCTL_b_CorruptedRegs)
    {
      IC_PROFILE_START(IC_e_PROFSECT_P1_EMBDAT_EXTRACT); // PRQA S 3138,3141,3109
      si16_Ret = IEDP_si16_ExtractRegisters(pui16_EmbDatLine0, pui16_EmbDatLine1, ICCTL_pRb_RegsInR);
      IC_PROFILE_STOP(IC_e_PROFSECT_P1_EMBDAT_EXTRACT); // PRQA S 3138,3141,3109
      if (IEDP_csi16_NOERROR != si16_Ret)
      {
        e_Ret = IC_e_ERR_EXTRACT_EMBEDDED_DATA;
      }
    }
    else
    {
      // CORRUPTED DATA! Keep old registers and manually update frame-counter
      // TODO: Better copy some values from last output register buffer?
      ICCTL_pRb_RegsInR->aRegs[IMGREG_e_REG_FRAME_COUNT] = ICCTL_ui16_FrameNum;
    }
    
    // Setup some working pointers
    ICCTL_ps_ImageData      = &ICCTL_s_ImageData;
    ICCTL_ps_EmbeddedData   = &ICCTL_ps_ImageData->s_EmbeddedData;
    ICCTL_ps_StatisticsData = &ICCTL_ps_ImageData->s_StatisticsData;
    ICCTL_ps_ResponseCurve  = &ICCTL_as_ResponseCurve[ICCTL_e_FrameType];
    ICCTL_ps_NCObj          = &ICCTL_as_IMGNCObj[ICCTL_e_FrameType];
    
    // Set input to sensor driver
    IMGDRV_v_SetRegisterInput(ICCTL_pRb_RegsInR, IC_e_IMAGER_RIGHT);
    
    // Collect image data
    ICCTL_ps_ImageData->e_FrameType = ICCTL_e_FrameType;
    IMGDRV_v_CollectImageData(ICCTL_ps_EmbeddedData, IC_e_IMAGER_RIGHT);
    
    ERROR_EXIT:
    return e_Ret;
    /*#]*/
}

/*## operation ICCTL_e_SetCroi() */
static IC_E_ERROR ICCTL_e_SetCroi(void) {
    /*#[ operation ICCTL_e_SetCroi() */
    IC_E_ERROR e_SubRet;
    IC_E_ERROR e_Ret = IC_e_ERR_OK;
    IC_S_Croi  s_ImageCroi[ICCFG_NUM_IMAGERS];
    
    // Set image output size according to current frame type
    ICROI_v_GetImagerCroi(&s_ImageCroi[IC_e_IMAGER_RIGHT], IC_e_IMAGER_RIGHT, ICCTL_e_FrameType);
    e_SubRet  = IMGDRV_e_SetCROI(IC_e_IMAGER_RIGHT, &s_ImageCroi[IC_e_IMAGER_RIGHT]);
    if (IC_e_ERR_OK != e_SubRet)
    {
      e_Ret = ICERR_HANDLE(IC_e_ERR_CROI_OUT_OF_RANGE, IC_e_IMAGER_RIGHT);
    }
    
    #if (ICCFG_ENABLE_LEFT_IMAGER == 1)
    ICROI_v_GetImagerCroi(&s_ImageCroi[IC_e_IMAGER_LEFT], IC_e_IMAGER_LEFT, ICCTL_e_FrameType);
    e_SubRet = IMGDRV_e_SetCROI(IC_e_IMAGER_LEFT, &s_ImageCroi[IC_e_IMAGER_LEFT]);
    if (IC_e_ERR_OK != e_SubRet)
    {
      e_Ret = ICERR_HANDLE(IC_e_ERR_CROI_OUT_OF_RANGE, IC_e_IMAGER_LEFT);
    }
    #endif
    
    return e_Ret;
    /*#]*/
}

/*## operation ICCTL_v_ExecColumnCorrection() */
static void ICCTL_v_ExecColumnCorrection(void) {
    /*#[ operation ICCTL_v_ExecColumnCorrection() */
    switch (ICCTL_e_ColCorrState)
    {
    case ICCTL_e_COLCORRSTATE_ENABLE_TRIGGER:
      // Enable column correction trigger on DCG change
      IMGDRV_v_SetColCorrRetriggDCG(b_TRUE);
      IMGDRV_v_SetColCorrCorrectAlways(b_TRUE);
      IMGDRV_v_SetDCG(IC_e_DCG_LOW);
      ICCTL_e_ColCorrState = ICCTL_e_COLCORRSTATE_CHANGE_DCG;
      break;
    case ICCTL_e_COLCORRSTATE_CHANGE_DCG:
      // Change DCG to trigger column correction
      IMGDRV_v_SetDCG(IC_e_DCG_HIGH);
      ICCTL_e_ColCorrState = ICCTL_e_COLCORRSTATE_DISABLE_TRIGGER;
      break;
    case ICCTL_e_COLCORRSTATE_DISABLE_TRIGGER:
      // Switch off column correction retrigger
      IMGDRV_v_SetColCorrRetriggDCG(b_FALSE);
      IMGDRV_v_SetDCG(IC_e_DCG_LOW);
    
      // Initialize data for cyclic column correction
      ICCTL_s_CycColCorrData.f32_LastColCorrTemp = ICCTL_af32_ImagerTemperatures[IC_e_IMAGER_RIGHT];
      ICCTL_s_CycColCorrData.ui32_LastColCorrTimeMs = (uint32)IC_ui64_CONV_us_ms(ICCTL_ui64_FrameStartUs);
      ICCTL_s_CycColCorrData.ui8_TriggerCount++;
      ICCTL_e_ColCorrState = ICCTL_e_COLCORRSTATE_FINISHED;
      break;
    case ICCTL_e_COLCORRSTATE_FINISHED:
      // Never reached
      break;
    default:
      // Never reached
      (void)ICERR_HANDLE(IC_e_ERR_FATAL_PROGRAM_ERROR, 0);
      break;
    }
    /*#]*/
}

/*## operation ICCTL_v_ExecColCorrCyclic() */
static void ICCTL_v_ExecColCorrCyclic(void) {
    /*#[ operation ICCTL_v_ExecColCorrCyclic() */
    float32 f32_DeltaTemp  = 0.0f; // PRQA S 3121
    uint32  ui32_DeltaTime = 0;
    boolean b_Trigger      = b_FALSE;
    ICCTL_S_CycColCorrData * const ps_Dat = &ICCTL_s_CycColCorrData;
    
    switch (ps_Dat->e_State)
    {
    case ICCTL_e_CYC_COLCORR_STATE_CHECK_CONDITION:
      // Calculate deltas
      f32_DeltaTemp  = fABS(ICCTL_af32_ImagerTemperatures[IC_e_IMAGER_RIGHT] - ps_Dat->f32_LastColCorrTemp);
      ui32_DeltaTime = ((uint32)IC_ui64_CONV_us_ms(ICCTL_ui64_FrameStartUs)) - ps_Dat->ui32_LastColCorrTimeMs;
    
      // Above lower threshold?
      if (f32_DeltaTemp > ICCFG_cf32_COLCORR_THRES1_CELSIUS)
      {
        // Trigger on standstill or time exceeded
        if ((ICCTL_ps_Input->s_VehicleDyn.e_MotionState == IC_e_VEH_MOTSTATE_STANDSTILL)
         || (ui32_DeltaTime > ICCFG_ui32_COLCORR_THRES1_TIME_MSEC))
        {
          b_Trigger = b_TRUE;
        }
      }
    
      // Trigger always when higher threshold reached
      if (f32_DeltaTemp > ICCFG_cf32_COLCORR_THRES2_CELSIUS)
      {
        b_Trigger = b_TRUE;
      }
    
      // Check if we need to trigger the imager's column correction algorithm
      if ((b_TRUE == b_Trigger) && (ICCTL_e_FrameType == IC_e_FRAMETYPE_EVEN))
      {
        // We want to trigger on even/short image, so force change of DCG on that frame-type
        // (will be visible on next even/short image two frames later)
        ICCTL_b_ForceDcgChange = b_TRUE;
    
        // Update internal data and goto next state
        ps_Dat->f32_LastColCorrTemp    = ICCTL_af32_ImagerTemperatures[IC_e_IMAGER_RIGHT];
        ps_Dat->ui32_LastColCorrTimeMs = (uint32)IC_ui64_CONV_us_ms(ICCTL_ui64_FrameStartUs);
        ps_Dat->ui8_TriggerCount++;
        ps_Dat->e_State = ICCTL_e_CYC_COLCORR_STATE_EXECUTE;
      }
      break;
    
    case ICCTL_e_CYC_COLCORR_STATE_EXECUTE:
      // Enable column correction trigger, will be active next frame, so same time as the DCG toggle
      IMGDRV_v_SetColCorrRetriggDCG(b_TRUE);
      IMGDRV_v_SetColCorrCorrectAlways(b_TRUE);
      ICCTL_b_ForceDcgChange = b_FALSE;
      ps_Dat->e_State = ICCTL_e_CYC_COLCORR_STATE_CLEANUP;
      break;
    
    case ICCTL_e_CYC_COLCORR_STATE_CLEANUP:
      // DCG toggled this frame and column correction has been triggered here, so disable trigger now
      // (it's disabled on next frame)
      IMGDRV_v_SetColCorrRetriggDCG(b_FALSE);
      ps_Dat->e_State = ICCTL_e_CYC_COLCORR_STATE_CHECK_CONDITION;
      break;
    
    default:
      // Unreachable
      (void)ICERR_HANDLE(IC_e_ERR_FATAL_PROGRAM_ERROR, 0);
      break;
    }
    
    // Update meas-data
    IC_s_MeasData.s_CyclicColCorr = *ps_Dat;
    /*#]*/
}

/*## operation ICCTL_v_NewRegDataChecks() */
static void ICCTL_v_NewRegDataChecks(void) {
    /*#[ operation ICCTL_v_NewRegDataChecks() */
    IC_S_Roi s_IcRoi;
    
    // Do some checks after first execution done
    if (ICCTL_ui16_PostInitExecCount >= ICCTL_cui16_SKIPCHECKS_POSTINITCYCLES)
    {
      // Check framecounter
      if (ICCTL_ui16_FrameNum != ((ICCTL_ui16_OldFrameCounter + 1u) & IC_BITMASK_U16))
      {
        (void)ICERR_HANDLE(IC_e_ERR_CHECK_FRAMENUM_INCR, ICCTL_ui16_OldFrameCounter);
        ICERR_v_DemFailed(IC_e_DEM_FRAMECOUNTER, ((uint32)ICCTL_ui16_OldFrameCounter << IC_NUMBITS_16) | ((uint32)ICCTL_ui16_FrameNum));
      }
      else
      {
        ICERR_v_DemPassed(IC_e_DEM_FRAMECOUNTER);
      }
    
    #if (IC_REGISTER_CHECK_ENABLED == 1)
      // Skip register-checks in HIL-Mode
      if (b_FALSE == ICCTL_b_HILMODE_ACTIVE())
      {
        // Check read-back registers against last values in register-shadow-buffer buffer.
        // This checks only right imager's registers. There is separate function for the
        // left imager.
        // ATTENTION: This must be done BEFORE call to IMGDRV_v_SetRegisterDataRight().
        ICRM_v_CheckRegisters(ICCTL_e_FrameType);
    
        // Check very critical registers against constant values
        ICRM_v_HandleConstRegChecks();
      }
    #endif
    }
    
    // Do some checks after first execution done and we are not on HIL
    if ((ICCTL_ui16_RunningModeExecCount >= ICCTL_cui16_SKIPCHECKS_RUNNINGCYCLES) && (ICCTL_b_HILMODE_ACTIVE() != b_TRUE))
    {
      // Check if IC-ROI matches expected values.
      IMGDRV_v_GetIcRoi(&s_IcRoi);
      if (   (s_IcRoi.ui16_StartX != ICCTL_s_ICRois[ICCTL_e_FrameType].ui16_StartX)
          || (s_IcRoi.ui16_StartY != ICCTL_s_ICRois[ICCTL_e_FrameType].ui16_StartY)
          || (s_IcRoi.ui16_Width  != ICCTL_s_ICRois[ICCTL_e_FrameType].ui16_Width)
          || (s_IcRoi.ui16_Height != ICCTL_s_ICRois[ICCTL_e_FrameType].ui16_Height))
      {
        (void)ICERR_HANDLE(IC_e_ERR_IC_ROI_SIZE_POSITION_MISMATCH, 0);
      }
    }
    /*#]*/
}

/*## operation ICCTL_e_NewStatDataChecks() */
static IC_E_ERROR ICCTL_e_NewStatDataChecks(void) {
    /*#[ operation ICCTL_e_NewStatDataChecks() */
    IC_E_ERROR e_Ret = IC_e_ERR_OK;
    uint32 ui32_Hint = 0;
    
    // Check if framecounter in register- and statistics-data match
    if (ICCTL_ps_EmbeddedData->ui16_FrameCounter != ICCTL_ps_StatisticsData->ui16_FrameCounter)
    {
      ui32_Hint = (((uint32)ICCTL_ps_EmbeddedData->ui16_FrameCounter) << IC_NUMBITS_16)
                | ( (uint32)ICCTL_ps_StatisticsData->ui16_FrameCounter     );
      e_Ret = ICERR_HANDLE(IC_e_ERR_CHECK_FRAMENUM_REGSTAT_MATCH, ui32_Hint);
    }
    else
    {
      ICERR_v_DemPassed(IC_e_DEM_FRAMECOUNTER_INCONSISTENT);
    }
    
    // Do some checks, but first two frames after startup to account for the delays
    // in the chain: execution -> register setting -> embedded statistics data
    if (ICCTL_ui16_PostInitExecCount > ICCTL_cui16_SKIPCHECKS_POSTINITCYCLES)
    {
      // The LSB of the FrameCounter is put into the LSB of the FrameId, so compare here with
      // the framecounter from the previous run
      if ((ICCTL_ps_EmbeddedData->ui16_FrameCounter & IC_BITMASK_U8) != (ICCTL_ps_StatisticsData->ui16_FrameId & IC_BITMASK_U8))
      {
        ui32_Hint = ((uint32)(ICCTL_ps_EmbeddedData->ui16_FrameCounter & IC_BITMASK_U8) << IC_NUMBITS_16)
                  | ((uint32)(ICCTL_ps_StatisticsData->ui16_FrameId & IC_BITMASK_U8));
        e_Ret = ICERR_HANDLE(IC_e_ERR_CHECK_FRAMEID, ui32_Hint);
        ICERR_v_DemFailedKeep(IC_e_DEM_UNEXPECTED_EMBD_REG_STAT, ui32_Hint);
      }
      else
      {
        ICERR_v_DemPassed(IC_e_DEM_UNEXPECTED_EMBD_REG_STAT);
      }
    
    #if (ICCFG_ENABLE_LEFT_IMAGER == 1)
      // Check if Frame-id of right image matches the MSB. If not, the imagers may be swapped (e.g. I2C addressing issue)!
      if ((ICCTL_ps_StatisticsData->ui16_FrameId >> IC_NUMBITS_8) != ICCTL_aui8_FrameIdMSB[IC_e_IMAGER_RIGHT])
      {
        e_Ret = ICERR_HANDLE(IC_e_ERR_IMAGERS_SWAPPED, ICCTL_ps_StatisticsData->ui16_FrameId);
      }
    #endif
    }
    return e_Ret;
    /*#]*/
}

/*## operation ICCTL_e_CalcImageStuff() */
static IC_E_ERROR ICCTL_e_CalcImageStuff(void) {
    /*#[ operation ICCTL_e_CalcImageStuff() */
    IC_E_ERROR      e_Ret         = IC_e_ERR_OK;
    IRCC_E_ERROR    e_IRCCRet;
    IRCC_S_Input    s_IRCCInput;
    IMGNC_E_ERROR   e_ImgNcRet   = IMGNC_e_ERR_OK;
    float32         f32_DigiGain = 0.0f; // PRQA S 3121
    uint32          ui32_SumDeltaDk = 0;
    
    // Calculate noise and blacklevel
    #if ((IC_NOISECALC_ENABLED == 1) || (IC_BLACKLEVEL_CALC_ENABLED == 1))
    
    // Skip noise calculation when IC is not in running state
    if (ICCTL_e_STATE_RUNNING == ICCTL_e_State)
    {
      // Get digital gain
      f32_DigiGain = IMGDRV_f32_GetDigitalGainRight();
    
      // Calculate sum of all DeltaDk register values (T1+T2+T3):
      ui32_SumDeltaDk = ICCTL_pRb_RegsInR->aRegs[IMGREG_e_REG_DELTA_DK_T1]
                      + ICCTL_pRb_RegsInR->aRegs[IMGREG_e_REG_DELTA_DK_T2]
                      + ICCTL_pRb_RegsInR->aRegs[IMGREG_e_REG_DELTA_DK_T3];
    
      // Execute noise calculation main function
      e_ImgNcRet = IMGNC_e_MainFunc(ICCTL_ps_NCObj, ui32_SumDeltaDk, f32_DigiGain);
      if (e_ImgNcRet != IMGNC_e_ERR_OK)
      {
        e_Ret = ICERR_HANDLE(IC_e_ERR_IMGNC_REGCALLBACK, 0);
      }
      else
      {
        e_ImgNcRet = IMGNC_e_GetResults(ICCTL_ps_NCObj, &ICCTL_s_NCResults);
        if (e_ImgNcRet != IMGNC_e_ERR_OK)
        {
          e_Ret = ICERR_HANDLE(IC_e_ERR_IMGNC_GETRESULTS, 0);
        }
      }
    }
    #else
    ICCTL_s_NCResults.f32_NoiseStdDev = 0.0f; // PRQA S 3121
    #endif
    
    // Calculate response curve
    s_IRCCInput.ps_ImagerRegs = ICCTL_pRb_RegsInR;
    #if (IC_BLACKLEVEL_CALC_ENABLED != 1)
    ICCTL_s_NCResults.f32_BlacklevelCurrent  = ICCTL_ps_IRCCPPARs->f32_Y_BL_0;
    ICCTL_s_NCResults.f32_BlacklevelFiltered = ICCTL_ps_IRCCPPARs->f32_Y_BL_0;
    #endif
    s_IRCCInput.ui16_Blacklevel = (uint16)ICCTL_s_NCResults.f32_BlacklevelFiltered;
    IRCC_v_SetInput(&ICCTL_s_IRCCObj, &s_IRCCInput);
    e_IRCCRet = IRCC_e_CalcImagerResponseCurve(&ICCTL_s_IRCCObj);
    if (IRCC_e_ERROR_OK != e_IRCCRet)
    {
      e_Ret = ICERR_HANDLE(IC_e_ERR_IRCC_CALC, e_IRCCRet);
      goto ERROR_EXIT;
    }
    e_IRCCRet = IRCC_e_GetResponseCurve(&ICCTL_s_IRCCObj, ICCTL_ps_ResponseCurve);
    if (IRCC_e_ERROR_OK != e_IRCCRet)
    {
      e_Ret = ICERR_HANDLE(IC_e_ERR_IRCC_GET, e_IRCCRet);
      goto ERROR_EXIT;
    }
    
    // Do plausi-check for blacklevel
    if ((ICCTL_s_NCResults.f32_BlacklevelFiltered < ICCFG_cf32_BLACKLEVEL_PLAUSI_MIN)
     || (ICCTL_s_NCResults.f32_BlacklevelFiltered > ICCFG_cf32_BLACKLEVEL_PLAUSI_MAX))
    {
      e_Ret = ICERR_HANDLE(IC_e_ERR_BLACKLEVEL_RANGE, ICCTL_s_NCResults.f32_BlacklevelFiltered);
    }
    
    ERROR_EXIT:
    return e_Ret;
    /*#]*/
}

/*## operation ICCTL_v_ExecMeasfreeze() */
static void ICCTL_v_ExecMeasfreeze(void) {
    /*#[ operation ICCTL_v_ExecMeasfreeze() */
    IC_E_ERROR e_Ret = IC_e_ERR_OK;
    
    // Increment this counter. This can be used to detect inconsistent meas-freezes by comparing this
    // value with 'IC_s_MeasData.ui32_MeasCounter'
    IC_s_MeasData.ui32_MeasCounterBottomCheck = ICCTL_ui32_MeasCounter;
    IC_s_MeasData.ui64_MeasTimestamp = ICOSW_ui64_GetTimeUs();
    
    // Freeze common meas-data
    e_Ret = ICOSW_e_Measfreeze(
            ICCFG_cui8_MeasFuncChanId,
            ICCFG_cui32_MeasVirtAddrIC,
            &IC_s_MeasData,
            (uint32)sizeof(IC_s_MeasData),
            ICCTL_ui8_MEASGROUP_IC_COMMON);
    if (e_Ret != IC_e_ERR_OK)
    {
      (void)ICERR_HANDLE(e_Ret, 0);
    }
    /*#]*/
}

/*## operation ICCTL_v_ExecMeasfreezeExposure() */
static void ICCTL_v_ExecMeasfreezeExposure(void) {
    /*#[ operation ICCTL_v_ExecMeasfreezeExposure() */
    IC_E_ERROR e_Ret = IC_e_ERR_OK;
    void *pv_ExposureMeasData = 0;
    uint32 ui32_ExposureMeasDataSize = 0;
    
    // Freeze meas-data from exposure control
    ICEXPMG_v_GetExposureMeasData(&pv_ExposureMeasData, &ui32_ExposureMeasDataSize, ICCTL_e_FrameType);
    if (IC_e_FRAMETYPE_EVEN == ICCTL_e_FrameType)
    {
      e_Ret = ICOSW_e_Measfreeze(
          ICCFG_cui8_MeasFuncChanId,
          ICCFG_cui32_MeasVirtAddrICExpEven,
          pv_ExposureMeasData,
          ui32_ExposureMeasDataSize,
          ICCTL_ui8_MEASGROUP_IC_EXPOSURE);
    }
    else
    {
      e_Ret = ICOSW_e_Measfreeze(
          ICCFG_cui8_MeasFuncChanId,
          ICCFG_cui32_MeasVirtAddrICExpOdd,
          pv_ExposureMeasData,
          ui32_ExposureMeasDataSize,
          ICCTL_ui8_MEASGROUP_IC_EXPOSURE);
    }
    if (e_Ret != IC_e_ERR_OK)
    {
      (void)ICERR_HANDLE(e_Ret, 0);
    }
    /*#]*/
}

/*## operation ICCTL_v_SetTestpatternLeft(const boolean) */
#if (ICCFG_ENABLE_LEFT_IMAGER == 1)
void ICCTL_v_SetTestpatternLeft(const boolean b_Enabled) {
    /*#[ operation ICCTL_v_SetTestpatternLeft(const boolean) */
    if (b_TRUE == b_Enabled)
    {
      // Set flag to ENable test-pattern
      ICCTL_b_EnableTestpatternLeft = b_TRUE;
    }
    else
    {
      // Set flag to DISable test-pattern
      ICCTL_b_DisableTestpatternLeft = b_TRUE;
    }
    /*#]*/
}
#endif

/*## operation ICCTL_e_SetAnalogTestParams(const IC_S_ATestExternParams * const) */
#if (IC_ANALOG_TEST_ENABLED == 1)
IC_E_ERROR ICCTL_e_SetAnalogTestParams(const IC_S_ATestExternParams * const ps_Params) {
    /*#[ operation ICCTL_e_SetAnalogTestParams(const IC_S_ATestExternParams * const) */
    IC_E_ERROR e_Ret = IC_e_ERR_OK;
    IC_S_Roi s_Roi;
    
    // Check pointer
    if (NULL == ps_Params)
    {
      e_Ret = IC_e_ERR_NULLPOINTER;
    }
    else
    {
      // Reset analog test
      ICAT_v_Reset();
    
      // Pass ROI to analog test component
      s_Roi.ui16_StartX = ICCFG_cui16_ATEST_ROI_STARTX;
      s_Roi.ui16_StartY = ps_Params->ui16_RoiStartY;
      s_Roi.ui16_Width  = ICCFG_cui16_ATEST_ROI_WIDTH;
      s_Roi.ui16_Height = ps_Params->ui16_RoiHeight;
      e_Ret = ICAT_e_SetRoi(&s_Roi, ps_Params->ui16_RoiStepsizeY);
    
      if (IC_e_ERR_OK == e_Ret)
      {
        // Set reference values: Allowed tolerances are used from CFG file (production version)
        e_Ret = ICAT_e_SetRefValues(&ps_Params->s_ReferenceValues, &ICCFG_s_ATest_MaxTolsProduction);
      }
    
      if (IC_e_ERR_OK == e_Ret)
      {
        // Set acquisition parameters
        e_Ret = ICAT_e_SetAcquisitionParams(&ps_Params->s_AcquParameters);
      }
    
      if (IC_e_ERR_OK == e_Ret)
      {
        // Take over other parameters
        ICCTL_pfct_ATestFinishedCb = ps_Params->pfct_FinishedCb;
      }
    }
    
    return e_Ret;
    /*#]*/
}
#endif

/*## operation ICCTL_e_StartAnalogTest() */
#if (IC_ANALOG_TEST_ENABLED == 1)
IC_E_ERROR ICCTL_e_StartAnalogTest(void) {
    /*#[ operation ICCTL_e_StartAnalogTest() */
    IC_E_ERROR e_Ret = IC_e_ERR_OK;
    
    if (ICCTL_e_STATE_RUNNING != ICCTL_e_State)
    {
      e_Ret = IC_e_ERR_WRONG_STATE;
    }
    else
    {
      ICCTL_b_ATestExternalTrigger = b_TRUE;
      e_Ret = ICAT_e_Start();
    }
    
    return e_Ret;
    /*#]*/
}
#endif

/*## operation ICCTL_v_UpdateTemperatures() */
static void ICCTL_v_UpdateTemperatures(void) {
    /*#[ operation ICCTL_v_UpdateTemperatures() */
    IC_E_ERROR  e_SubRet             = IC_e_ERR_OK;
    float32     f32_Temp             = 0.0f; // PRQA S 3121
    sint64      si64_TempLeftAge     = 0;
    
    // Read/convert temperature (right imager)
    if (IC_e_ERR_OK != IMGDRV_e_GetTemperature(IC_e_IMAGER_RIGHT, &f32_Temp))
    {
      ICCTL_af32_ImagerTemperatures[IC_e_IMAGER_RIGHT] = ICCTL_cf32_TEMP_NOT_AVAILABLE_INDICATOR;
      (void)ICERR_HANDLE(IC_e_ERR_READ_TEMPERATURE, 0);
    }
    else
    {
      ICCTL_af32_ImagerTemperatures[IC_e_IMAGER_RIGHT] = f32_Temp;
      ICCTL_aui64_ImagerTempTimeStamps[IC_e_IMAGER_RIGHT] = ICCTL_ui64_FrameStartUs;
      
      // Pass temperature to error manager (for DEM optional data)
      ICERR_v_SetContextTemperature(f32_Temp);
    }
    
    #if (ICCFG_ENABLE_LEFT_IMAGER == 1)
    // Read/convert temperature (left imager). When DSP is not available the temperature register
    // is read via I2C
    if (b_TRUE == ICCTL_ps_Input->b_DSPNotAvailable)
    {
      // Get last async register RX timestamp from register manager
      ICCTL_aui64_ImagerTempTimeStamps[IC_e_IMAGER_LEFT] = ICRM_ui64_GetRegRxAsyncTimeLeft();
    }
    else
    {
      // Get timestamp from embedded data
      ICCTL_aui64_ImagerTempTimeStamps[IC_e_IMAGER_LEFT] = IMGDRV_ui64_GetTimestampEmbedded(IC_e_IMAGER_LEFT);
    }
    
    // Data must not be older than XX seconds. NOTE: 'Age' may also become negative, when the temperature
    // is read via I2C (so the frame start is older than temperature timestamp)
    si64_TempLeftAge = ((sint64)ICCTL_ui64_FrameStartUs) - ((sint64)ICCTL_aui64_ImagerTempTimeStamps[IC_e_IMAGER_LEFT]);
    if (si64_TempLeftAge > (sint64)ICCFG_cui32_TEMPERATURE_MAXAGE_US)
    {
      // Embedded data is too old, so invalidate temperature
      ICCTL_af32_ImagerTemperatures[IC_e_IMAGER_LEFT] = ICCTL_cf32_TEMP_NOT_AVAILABLE_INDICATOR;
    }
    else
    {
      // Get temperature
      e_SubRet = IMGDRV_e_GetTemperature(IC_e_IMAGER_LEFT, &f32_Temp);
      if (IC_e_ERR_OK != e_SubRet)
      {
        ICCTL_af32_ImagerTemperatures[IC_e_IMAGER_LEFT] = ICCTL_cf32_TEMP_NOT_AVAILABLE_INDICATOR;
      }
      else
      {
        ICCTL_af32_ImagerTemperatures[IC_e_IMAGER_LEFT] = f32_Temp;
      }
    }
    #endif
    /*#]*/
}

/*## operation ICCTL_v_UpdateErrContext() */
static void ICCTL_v_UpdateErrContext(void) {
    /*#[ operation ICCTL_v_UpdateErrContext() */
    IC_S_DemExtDataIcState s_DemIcState = { 0 };
    s_DemIcState.ui4_State     = (uint8)ICCTL_e_State;
    s_DemIcState.ui1_SubState  = (uint8)ICCTL_e_ExecSubstate;
    s_DemIcState.ui1_FrameType = (uint8)IC_e_ImageCounterToFrameType(ICCTL_ui16_FrameNum);
    ICERR_v_SetContextState(s_DemIcState);
    /*#]*/
}

/*## operation ICCTL_e_ImagerSoftReset() */
static IC_E_ERROR ICCTL_e_ImagerSoftReset(void) {
    /*#[ operation ICCTL_e_ImagerSoftReset() */
    IC_E_ERROR e_Ret = IC_e_ERR_OK;
    
    const uint16 ui16_RegAddr = IMGREG_ui16_GetRegAddr(IMGREG_e_REG_RESET_REGISTER);
    const uint16 ui16_RegVal  = 0x0001;
    
    // Reset imager
    e_Ret = ICRM_e_SensorRegTXSingle(IC_e_IMAGER_ALL, ui16_RegAddr, ui16_RegVal, 0x0000);
    if (IC_e_ERR_OK != e_Ret)
    {
      e_Ret = ICERR_HANDLE(e_Ret, ui16_RegAddr);
    }
    else
    {
      // Wait at least 66ms after reset
      ICOSW_v_DelayUs(ICCTL_cui32_SoftResetDelayUs);
    }
    
    return e_Ret;
    /*#]*/
}

/*## operation ICCTL_v_DebugLedToggle() */
static void ICCTL_v_DebugLedToggle(void) {
    /*#[ operation ICCTL_v_DebugLedToggle() */
    if (b_TRUE == ICCTL_b_LedToggleFlag)
    {
      ICCTL_b_LedToggleFlag = b_FALSE;
      ICOSW_v_SetDebugLED(b_TRUE);
    }
    else
    {
      ICCTL_b_LedToggleFlag = b_TRUE;
      ICOSW_v_SetDebugLED(b_FALSE);
    }
    /*#]*/
}

/*## operation ICCTL_v_GetSensorIDs(IC_S_SensorIDs * const,const IC_E_Imager) */
void ICCTL_v_GetSensorIDs(IC_S_SensorIDs * const ps_SensorIDs, const IC_E_Imager e_Imager) {
    /*#[ operation ICCTL_v_GetSensorIDs(IC_S_SensorIDs * const,const IC_E_Imager) */
    #if (ICCFG_ENABLE_LEFT_IMAGER == 1)
        if (IC_e_IMAGER_LEFT == e_Imager)
        {
          *ps_SensorIDs = IC_s_MeasData.s_ImagerInfos.s_ImagerIdsLeft;
        }
        else
    #else
        (void)e_Imager; /* Suppress compiler warning */
    #endif
        {
          *ps_SensorIDs = IC_s_MeasData.s_ImagerInfos.s_ImagerIdsRight;
        }
    /*#]*/
}

/*## operation ICCTL_e_GetTemperature(const IC_E_Imager,float32 * const,uint64 * const) */
IC_E_ERROR ICCTL_e_GetTemperature(const IC_E_Imager e_Imager, float32 * const pf32_Temp, uint64 * const pui64_TimeStamp) {
    /*#[ operation ICCTL_e_GetTemperature(const IC_E_Imager,float32 * const,uint64 * const) */
    IC_E_ERROR e_Ret = IC_e_ERR_OK;
    float32 f32_Temp = ICCTL_cf32_TEMP_NOT_AVAILABLE_INDICATOR;
    
    // Check imager
    if (e_Imager > IC_ce_LAST_SINGLE_IMAGER)
    {
      e_Ret = IC_e_ERR_ILLEGAL_SENSORNUM;
    }
    else
    {
      // Get current temperature
      f32_Temp = ICCTL_af32_ImagerTemperatures[e_Imager];
    
      // Temperature available? Comparation against power-of-two constant, so disable QAC warning:
      // PRQA S 3341 1
      if (ICCTL_cf32_TEMP_NOT_AVAILABLE_INDICATOR == f32_Temp)
      {
        e_Ret = IC_e_ERR_NOTAVAILABLE;
      }
      else
      {
        *pf32_Temp = f32_Temp;
      }
      *pui64_TimeStamp = ICCTL_aui64_ImagerTempTimeStamps[e_Imager];
    }
    return e_Ret;
    /*#]*/
}

/*## operation ICCTL_b_IsStableStateReached() */
boolean ICCTL_b_IsStableStateReached(void) {
    /*#[ operation ICCTL_b_IsStableStateReached() */
    return ((ICCTL_e_STATE_RUNNING == ICCTL_e_State)
         && (ICCTL_ui16_RunningModeExecCount > ICCTL_cui16_STABLESTATE_POSTEXECCYCLES)
           )
        ? b_TRUE
        : b_FALSE;
    /*#]*/
}

/*## operation ICCTL_v_SimInject(ICCTL_S_SimInjectionData *) */
#if (IC_COMPILE_FOR_MTS == 1)
void ICCTL_v_SimInject(ICCTL_S_SimInjectionData * ps_Inject) {
    /*#[ operation ICCTL_v_SimInject(ICCTL_S_SimInjectionData *) */
    ICCTL_s_CycColCorrData.f32_LastColCorrTemp = ps_Inject->f32_LastColCorrTemp;
    ICCTL_s_CycColCorrData.ui32_LastColCorrTimeMs = ps_Inject->ui32_LastColCorrTimeMs;
    ICCTL_s_CycColCorrData.ui8_TriggerCount = ps_Inject->ui8_CycColCorrTriggerCount;
    IC_s_MeasData.s_CyclicColCorr = ICCTL_s_CycColCorrData;
    /*#]*/
}
#endif

/*## operation ICCTL_e_ExternalControl(const ICIF_E_EXTCMD,const uint8 [ICIF_cui32_EXTCTL_ARGSIZE]) */
IC_E_ERROR ICCTL_e_ExternalControl(const ICIF_E_EXTCMD e_Command, const uint8 aui8_Arguments[ICIF_cui32_EXTCTL_ARGSIZE]) {
    /*#[ operation ICCTL_e_ExternalControl(const ICIF_E_EXTCMD,const uint8 [ICIF_cui32_EXTCTL_ARGSIZE]) */
    IC_E_ERROR e_Ret = IC_e_ERR_OK;
    
    // Arguments are currently unused, so cast to void to prevent compiler warning
    (void)aui8_Arguments;
    
    switch (e_Command)
    {
    case ICIF_e_EXTCMD_NOP:
      /* Do nothing*/
      break;
    case ICIF_e_EXTCMD_UNLOCK:
      /* Unlocking is done at interface level */
      break;
    case ICIF_e_EXTCMD_EXPOSURECTL_ENABLE:
      ICCTL_ui32_IcExposureDisabled = 0u;
      break;
    case ICIF_e_EXTCMD_EXPOSURECTL_DISABLE:
      ICCTL_ui32_IcExposureDisabled = ICCTL_cui32_KEY_EXPOSURE_DISABLE;
      ICCTL_ui32_RegChecksDisabled  = ICCTL_cui32_KEY_REGCHECKS_DISABLE;
      ICCTL_b_ExposureRegsSetToInit = b_TRUE;
      break;
    default:
      e_Ret = IC_e_ERR_NOTAVAILABLE;
      break;
    }
    
    return e_Ret;
    /*#]*/
}

/*## operation ICCTL_v_SetExposureRegsToInit() */
#pragma push
#pragma optimize_for_size on
static void ICCTL_v_SetExposureRegsToInit(void) {
    /*#[ operation ICCTL_v_SetExposureRegsToInit() */
    static const IMGREG_E_SENSOR_REG ICCTL_cae_ExposureRegs[] = {
        IMGREG_e_REG_AE_CTRL_REG,
        IMGREG_e_REG_OPERATION_MODE_CTRL,
        IMGREG_e_REG_COARSE_INTEGRATION_TIME,
        IMGREG_e_REG_GLOBAL_GAIN,
        IMGREG_e_REG_AE_ROI_X_START_OFFSET,
        IMGREG_e_REG_AE_ROI_Y_START_OFFSET,
        IMGREG_e_REG_AE_ROI_X_SIZE,
        IMGREG_e_REG_AE_ROI_Y_SIZE
    };
    uint16              ui16_Index    = 0;
    uint16              ui16_RegValue = 0;
    IMGREG_E_SENSOR_REG e_Reg         = IMGREG_e_REG__LAST_ENTRY_;
    IC_E_ERROR          e_Ret         = IC_e_ERR_OK;
    
    // For each register in the list: Find it's initial value and set it
    for (ui16_Index = 0; ui16_Index < IC_ARRLEN(ICCTL_cae_ExposureRegs); ui16_Index++)
    {
      e_Reg = ICCTL_cae_ExposureRegs[ui16_Index];
      e_Ret = ICRM_e_FindLastRegValue(e_Reg, ICINIT_caui16_SensorInitData, ICINIT_caui16_SensorInitDataEntries, &ui16_RegValue);
      if (IC_e_ERR_OK == e_Ret)
      {
        ICRM_v_SetRegister(e_Reg, ui16_RegValue);
      }
    }
    /*#]*/
}
#pragma pop


/*#[ ignore */

#ifdef __cplusplus
}
#endif

/*#]*/


/*********************************************************************
	File Path: ..\..\..\04_Engineering\01_Source_Code\Algo\ic\ic_controller.c
*********************************************************************/

// PRQA S 7013 2
