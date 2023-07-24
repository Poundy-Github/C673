//* **********************************************************************
//  COMPANY:         $CompanyInfo: CONFIDENTIAL AND PROPRIETARY PROPERTY OF CONTINENTAL AG , A.D.C. GmbH  -  ALL RIGHTS RESERVED $
//  
//  PROJECT:         MFC30x_MCU
//  CPU:             MPC5675K
//  
//  PACKAGE:         $Source: ic_errmanager.c $ $Revision: 1.1 $
//  MKS Date:        $Date: 2021/12/13 17:25:50CET $
//  
//  RHAPSODY:        7.5.3
//  COMPONENT:       IC
//  CONFIGURATION:   DefaultConfig
//  MODEL ELEMENT:   ic_errmanager
//  MODULNAME:       ..\..\..\04_Engineering\01_Source_Code\Algo\ic\ic_errmanager.c
//  LOGIN:           uidt3974  
//  
//  This is the central error manager for the imager control. Almost every error
//  which is detected in any C module goes through the error manager and is handled there.
//  
//  The IC error manager has the following tasks:
//  - Insert errors into an internal error ringbuffer. This is only used to create
//    debug data to assist recording analysis via MTS.
//  - Filter errors according to current IC state or error relevance (i.e. ignore non
//    critical measfreeze errors)
//  - Handle dedicated error counters which exists for several types of errors. Those
//    counters are part of the measurement data
//  - Map internal IC errors (IC_E_ERROR) to external DEMs. This is a N:1 mapping,
//    which also allows to specify a priority level for each mapping entry, which is
//    evaluated in case several errors are reported which map to the same DEM.
//  - Map DEMs to DTCs and handle DTC debouncing
//  - Provide context data to errors and DEMs (i.e. failing module, source-code line num,
//    error code)
//  
//  =======================================================================================
//  |                                 USING THE ERROR MANAGER                             |
//  =======================================================================================
//  To make use of the error manager, it is necessary to populate a module scope variable,
//  which contains the name of the module. This can be done either with the macro
//  ICERR_DEFINE_MODULE("MYMOD") or manually adding a "const char *" pointer with the name
//  "pch_ModuleName", which points to the naming char-array.
//  
//  Errors are usually reported via ICERR_HANDLE(), which is actually a macro. This macro
//  calls ICERR_e_HandleErr() function, which inserts the error into an error ringbuffer,
//  adding modulename, sourcecode-linenumber, timestamp and 32-bit optional data (supplied
//  by caller). This data is cyclically measfreezed to MTS and thus is available in the
//  recordings for later analysis.
//  
//  Each internal error (IC_E_ERROR) can be mapped to a DEM via 'ICERR_cas_DemMapping'. If
//  an error is reported, the mapped DEM will be set to failed, adding the context data
//  collected via ICERR_HANDLE(). Note: DEMs will _not_ implicitly be reported as 'passed'
//  when the error does not occur. This must be done via explicit DEM reporting:
//  
//  DEMs can also be explicitly reported via ICERR_v_DemFailed*() and ICERR_v_DemPassed*()
//  functions. This is recommended for DEMs which belongs to a certain test, e.g. databus
//  test, so it's clearly visible in the code what's done with the test results.
//  
//  It's _required_ to report each DEM at least once per ignition cycle as passed or failed.
//  As some DEMs are sort of 'catch-all-other-errors', which can not be reasonable reported
//  as passed via ICERR_v_DemPassed(), a special function 'ICERR_v_DemPassedWeak' exists.
//  This function sets a specific DEM to passed, if it has not been set to failed in the last
//  n cycles.
//  
//  =======================================================================================
//  |                       FLUSHING DEMS TO THE RUNTIME ENVIRONMENT                      |
//  =======================================================================================
//  DEMs are not immediately reported to the underlying runtime environment / IC adapter as
//  they occur. They are buffered until flushed via ICERR_v_DemFlush(), which must be called
//  at least each cycle. It is important to know that the ECU can not issue error reactions
//  to failed DEMs before they have been flushed.
//  
//  There is a special handling for DEMs which are marked as 'passed': As it's quite runtime
//  expensive to report DEMs to the runtime environment / external DEM component, not all
//  passed DEMs are reported in every cycle again and again. A passed DEM is only flushed
//  when calling ICERR_v_DemFlush(), if it was previously _not_ reported as passed (e.g.
//  failed or first time passed). This does not apply to failed DEMs, which are always
//  reported regardless of the last status.
//  
//  For all DEMs which were last reported as passed and are set afterwards to passed again
//  without failing in between, the flush-function goes cyclically through this list and
//  reports ONE of them as passed again (round-robin). This ensures that all passed DEMs are
//  flushed at least every N cycles, whereas N is the total number of DEMs.
//  
//  =======================================================================================
//  The following QAC messages are suppressed for this module:
//  
//    The parameter 'xxxx' is never modified and so it could be declared with the 'const' qualifier.
//      PRQA S 3227 EOF
//  
//    A subsequent declaration of 'xxxx' means that it is being used both as a structure/union member
//    and also as a label, tag or ordinary identifier.
//      PRQA S 0783 EOF
//  
//  
//  AUTHOR:          $Author: Wang, David (Wangd3) $
//! CREATION DATE:   Fri, 26, Oct 2012  4:08 W. Europe Daylight Time PM 
//**************************************************************************** */

/*## auto_generated */
#include "ic_errmanager.h"
/*## dependency ic_common */
#include "ic_common.h"
/*## dependency ic_oswrapper */
#include "ic_oswrapper.h"
/*## package Ic_Pkg */

/*## class TopLevel::ic_errmanager */


/*#[ ignore */
#ifdef __cplusplus
extern "C"
{
#endif

/*#]*/


//  HIGH priority value
/*## attribute ICERR_cui8_PRIO_HIGH */
#define ICERR_cui8_PRIO_HIGH 55

//  Default (normal/medium) priority value
/*## attribute ICERR_cui8_PRIO_NORMAL */
#define ICERR_cui8_PRIO_NORMAL 50

//  LOW priority value
/*## attribute ICERR_cui8_PRIO_LOW */
#define ICERR_cui8_PRIO_LOW 45

//  Priority of DEMs which are marked as 'permanently failed' due to an fatal error
/*## attribute ICERR_cui8_PRIO_PERM_FAILED */
#define ICERR_cui8_PRIO_PERM_FAILED 120

//  Default priority of explicitly reported DEM errors (reported via ICERR_v_DemFailed())
/*## attribute ICERR_cui8_PRIO_EXPLICIT_DEM */
#define ICERR_cui8_PRIO_EXPLICIT_DEM 100

//  Flag for enabling anti-flood protection for a specific error-code. See description of
//  anti-flood protection in ICERR_e_HandleErr()
/*## attribute ICERR_cui8_MAPFLAG_ANTIFLOOD */
#define ICERR_cui8_MAPFLAG_ANTIFLOOD (1 << 0)

//  Flag indicating that this (fatal) error will never be reset
/*## attribute ICERR_cui8_MAPFLAG_STICKY */
#define ICERR_cui8_MAPFLAG_STICKY (1 << 1)

//  Flag indicating that this DEM failed permanent and must never be reset/reported to/as passed again
/*## attribute ICERR_cui8_STATFLAG_FAILED_PERM */
#define ICERR_cui8_STATFLAG_FAILED_PERM (1 << 0)

//  A DEM status will be raised to this error-level when the DEM fails
/*## attribute ICERR_cui8_DEMFAILED_ERROR_LEVEL */
#define ICERR_cui8_DEMFAILED_ERROR_LEVEL 10

//  Indicator for a not-mapped IC_E_ERROR -> DEM
/*## attribute ICERR_ce_ERR_NOT_MAPPED */
#define ICERR_ce_ERR_NOT_MAPPED IC_e_DEM__NUM_ENTRIES__

//  Pointer to counters for some interresting errors
/*## attribute ICERR_ps_ErrCnts */
static ICERR_S_ErrorCounters * ICERR_ps_ErrCnts = NULL;

//  Measurement data storage for this module
/*## attribute ICERR_ps_MeasData */
static ICERR_S_MeasData * ICERR_ps_MeasData = NULL;

//  Index for next entry in the error list
/*## attribute ICERR_ui32_ErrBuffIndex */
static uint32 ICERR_ui32_ErrBuffIndex = 0;

//  Index for next DEM which is reported cyclic as passed
/*## attribute ICERR_ui16_NextCycSlowPassedRepDemIdx */
static uint16 ICERR_ui16_NextCycSlowPassedRepDemIdx = 0;

//  Current frame-number (attached to error entries)
/*## attribute ICERR_ui16_FrameNum */
static uint16 ICERR_ui16_FrameNum = 0;

//  Current frame-number saturated, at max ui16 value (attached to DEM optional data)
/*## attribute ICERR_ui16_FrameNumSaturated */
static uint16 ICERR_ui16_FrameNumSaturated = 0;

//  Current cycle-counter (can be used for filtering some errors at startup)
/*## attribute ICERR_ui32_CycleCnt */
static uint32 ICERR_ui32_CycleCnt = 0;

//  Setting this value to 'IC_cui32_KEY_HILMODE' enables HIL mode and suppresses some errors
//  which are known to appear on HIL as there is no real closed control loop to the imager.
/*## attribute ICERR_ui32_HILModeEnabled */
static uint32 ICERR_ui32_HILModeEnabled = 0u;

//  Basic initialization done, so we can add errors to the error-list
/*## attribute ICERR_b_BasicInitDone */
static boolean ICERR_b_BasicInitDone = b_FALSE;

//  Full initialization done, so we can also handle DEMs and DTCs
/*## attribute ICERR_b_FullInitDone */
static boolean ICERR_b_FullInitDone = b_FALSE;

//  Bitfield indicating which error types were reported during current cycle
/*## attribute ICERR_bf_FailedErrsThisCycle */
static uint8 ICERR_bf_FailedErrsThisCycle[IC_BITFIELD_UI8SIZE(IC_e_ERR__NUM_ENTRIES__)];

//  Bitfield indicating which error types were reported during the last cycle
/*## attribute ICERR_bf_FailedErrsLastCycle */
static uint8 ICERR_bf_FailedErrsLastCycle[IC_BITFIELD_UI8SIZE(IC_e_ERR__NUM_ENTRIES__)];

//  Information about the IC internal state, which will be appended to the DEM optional/PreExtData
/*## attribute ICERR_s_IcState */
static IC_S_DemExtDataIcState ICERR_s_IcState;

//  Current temperature (right imager) as 8-bit signed. This will be put into DEM optional data.
/*## attribute ICERR_si8_Temperature */
static sint8 ICERR_si8_Temperature = 0;

//  Name of this module, required for calls to ICERR_HANDLE().
//  
//  Character string is only used for debugging & recording analysis, so suppress QAC warnings:
//  PRQA S 5013,3625 3
/*## attribute pch_ModuleName */
static const char * const pch_ModuleName = "ERRMGR";

/*## attribute ICERR_pfct_SimLogErr */
#if (IC_COMPILE_FOR_MTS == 1)
static ICERR_Fct_SimLogErr ICERR_pfct_SimLogErr = NULL;
#endif

//  Stores the status of DEMs (and DTCs which are handled similary)
/*## attribute ICERR_as_DemStatus */
static ICERR_S_DemStatus ICERR_as_DemStatus[IC_e_DEM__NUM_ENTRIES__] = { 0 };

//  Lookup-table for mapping IC_E_ERROR -> DEM event
/*## attribute ICERR_aui8_DemMappingLut */
static uint8 ICERR_aui8_DemMappingLut[IC_e_ERR__NUM_ENTRIES__];

//  This map assigns each IC_E_ERROR to an DEM. Each entry has a priority specified.
//  The priority (higher number means higher priority) is used for a replacement-decision,
//  e.g. the DEM optional data of a higher priority error replaces lower prio error
//  opt-datas. Equal priorities don't lead to a replacement. See ICERR_e_HandleErr()
//  
//  NOTE: Explicit DEM reports via ICERR_v_DemFailed() have a default priority
//        of 'ICERR_cui8_PRIO_EXPLICIT_DEM'.
/*## attribute ICERR_cas_DemMapping */
static const ICERR_S_DemMapEntry ICERR_cas_DemMapping[IC_e_ERR__NUM_ENTRIES__] = {
    /* Errors to be ignored */
    ICERR_DEMMAP_IGNORE     (IC_e_ERR_OK),
    ICERR_DEMMAP_IGNORE     (IC_e_ERR_MEASFREEZE),          /* Don't care about lost measfreezes */
    ICERR_DEMMAP_IGNORE     (IC_e_ERR_NOTAVAILABLE),        /* External interface error */
    ICERR_DEMMAP_IGNORE     (IC_e_ERR_ILLEGAL_ARGUMENT),    /* External interface error */
    ICERR_DEMMAP_IGNORE     (IC_e_ERR_EXPLICIT_DEM),        /* Explicit DEM reporting, no mapping needed */
    ICERR_DEMMAP_IGNORE     (IC_e_ERR_INIT_ERRMANAGER),     /* Chicken-egg problem -> Should never happen and would prevent camera from startup */
    ICERR_DEMMAP_IGNORE     (IC_e_ERR_LOCKED),              /* External XCP interface locked -> do not generate an internal error */

    /* Register checks */
    ICERR_DEMMAP (IC_e_ERR_CHECK_REGISTERS_R,           IC_e_DEM_REGCHECK_FAILED_R, ICERR_cui8_PRIO_NORMAL),
    ICERR_DEMMAP (IC_e_ERR_CHECK_REGISTERS_R_FSYNCED,   IC_e_DEM_REGCHECK_FAILED_R, ICERR_cui8_PRIO_NORMAL),
    ICERR_DEMMAP (IC_e_ERR_INITSEQ_VERIFY,              IC_e_DEM_REGCHECK_FAILED_R, ICERR_cui8_PRIO_NORMAL),
    ICERR_DEMMAP (IC_e_ERR_REGCOMPARE_FAILED,           IC_e_DEM_REGCHECK_FAILED_R, ICERR_cui8_PRIO_LOW),
    ICERR_DEMMAP (IC_e_ERR_CHECK_REGISTERS_I2C_R,       IC_e_DEM_REGCHECK_FAILED_R, ICERR_cui8_PRIO_LOW),
    ICERR_DEMMAP (IC_e_ERR_CHECK_REGISTERS_R_CONST,     IC_e_DEM_REGCHECK_FAILED_R, ICERR_cui8_PRIO_LOW),
#if (ICCFG_ENABLE_LEFT_IMAGER == 1)
    ICERR_DEMMAP (IC_e_ERR_CHECK_REGISTERS_I2C_L,       IC_e_DEM_REGCHECK_FAILED_L, ICERR_cui8_PRIO_LOW),
    ICERR_DEMMAP (IC_e_ERR_CHECK_REGISTERS_L,           IC_e_DEM_REGCHECK_FAILED_L, ICERR_cui8_PRIO_NORMAL),
    ICERR_DEMMAP (IC_e_ERR_CHECK_REGISTERS_L_FSYNCED,   IC_e_DEM_REGCHECK_FAILED_L, ICERR_cui8_PRIO_NORMAL),
    ICERR_DEMMAP (IC_e_ERR_CHECK_REGISTERS_L_LATENCY,   IC_e_DEM_REGCHECK_FAILED_L, ICERR_cui8_PRIO_NORMAL),
    ICERR_DEMMAP (IC_e_ERR_CHECK_REGISTERS_L_CONST,     IC_e_DEM_REGCHECK_FAILED_L, ICERR_cui8_PRIO_LOW),
#endif

    /* Embedded data and related checks */
    ICERR_DEMMAP (IC_e_ERR_EMBEDDED_REGS_LINE0_CORRUPTED, IC_e_DEM_EMBEDDED_REGS_CORRUPTED,   ICERR_cui8_PRIO_NORMAL),
    ICERR_DEMMAP (IC_e_ERR_EMBEDDED_REGS_LINE1_CORRUPTED, IC_e_DEM_EMBEDDED_REGS_CORRUPTED,   ICERR_cui8_PRIO_NORMAL),
    ICERR_DEMMAP (IC_e_ERR_EXTRACT_EMBEDDED_DATA,         IC_e_DEM_EMBEDDED_REGS_CORRUPTED,   ICERR_cui8_PRIO_NORMAL),
    ICERR_DEMMAP (IC_e_ERR_EMBEDDED_STAT_CORRUPTED,       IC_e_DEM_EMBEDDED_STAT_CORRUPTED,   ICERR_cui8_PRIO_NORMAL),
    ICERR_DEMMAP (IC_e_ERR_EMBEDDED_HIST_CORRUPTED,       IC_e_DEM_EMBEDDED_STAT_CORRUPTED,   ICERR_cui8_PRIO_NORMAL),
    ICERR_DEMMAP (IC_e_ERR_CHECK_FRAMENUM_INCR,           IC_e_DEM_FRAMECOUNTER,              ICERR_cui8_PRIO_NORMAL),
    ICERR_DEMMAP (IC_e_ERR_CHECK_FRAMENUM_REGSTAT_MATCH,  IC_e_DEM_FRAMECOUNTER_INCONSISTENT, ICERR_cui8_PRIO_NORMAL),
    ICERR_DEMMAP (IC_e_ERR_CHECK_FRAMEID,                 IC_e_DEM_UNEXPECTED_EMBD_REG_STAT,  ICERR_cui8_PRIO_NORMAL),
    ICERR_DEMMAP (IC_e_ERR_HISTOGRAM_PIXELCOUNT_MISMATCH, IC_e_DEM_UNEXPECTED_EMBD_REG_STAT,  ICERR_cui8_PRIO_NORMAL),
    ICERR_DEMMAP (IC_e_ERR_IC_ROI_SIZE_POSITION_MISMATCH, IC_e_DEM_UNEXPECTED_EMBD_REG_STAT,  ICERR_cui8_PRIO_NORMAL),
    ICERR_DEMMAP (IC_e_ERR_BLACKLEVEL_RANGE,              IC_e_DEM_UNEXPECTED_EMBD_REG_STAT,  ICERR_cui8_PRIO_NORMAL),
#if (ICCFG_ENABLE_LEFT_IMAGER == 1)
    ICERR_DEMMAP (IC_e_ERR_IMAGERS_SWAPPED,               IC_e_DEM_GENERAL_FATAL, ICERR_cui8_PRIO_NORMAL),
#endif

    /* Timing related checks */
    ICERR_DEMMAP (IC_e_ERR_PART1_NOT_CALLED,          IC_e_DEM_PART1_NOTCALLED,    ICERR_cui8_PRIO_NORMAL), /* Call to Part1 missing! */
    ICERR_DEMMAP (IC_e_ERR_PART2_NOT_CALLED,          IC_e_DEM_PART2_NOTCALLED,    ICERR_cui8_PRIO_NORMAL), /* Call to Part2 missing! */
    ICERR_DEMMAP (IC_e_ERR_I2C_TIMING_LATE_RIGHT,     IC_e_DEM_IMAGER_COMM_TIMING, ICERR_cui8_PRIO_NORMAL),
    ICERR_DEMMAP (IC_e_ERR_REGCHECK_I2C_NOT_FINISHED, IC_e_DEM_SOFTWARE_TIMING,    ICERR_cui8_PRIO_NORMAL),
#if (ICCFG_ENABLE_LEFT_IMAGER == 1)
    ICERR_DEMMAP (IC_e_ERR_I2C_TIMING_LATE_LEFT,      IC_e_DEM_IMAGER_COMM_TIMING, ICERR_cui8_PRIO_NORMAL),
    ICERR_DEMMAP (IC_e_ERR_IMGSYNC_OUTOFSYNC,         IC_e_DEM_HARDWARE_TIMING,    ICERR_cui8_PRIO_NORMAL), /* Imagers out-of-sync or received garbage from DSP2 */
#endif

    /* Imager communication (e.g. I2C) */
    ICERR_DEMMAP (IC_e_ERR_REGTX,                    IC_e_DEM_IMAGER_COMM, ICERR_cui8_PRIO_NORMAL),
    ICERR_DEMMAP (IC_e_ERR_REGRX,                    IC_e_DEM_IMAGER_COMM, ICERR_cui8_PRIO_NORMAL),
    ICERR_DEMMAP (IC_e_ERR_RXTX_BUSERR,              IC_e_DEM_IMAGER_COMM, ICERR_cui8_PRIO_NORMAL),
    ICERR_DEMMAP (IC_e_ERR_RXTX_NOACK,               IC_e_DEM_IMAGER_COMM, ICERR_cui8_PRIO_NORMAL),
    ICERR_DEMMAP (IC_e_ERR_RXTX_BUFFER_OVERFLOW,     IC_e_DEM_IMAGER_COMM, ICERR_cui8_PRIO_LOW), /* Lower prio, because maybe consecutive fault */
    ICERR_DEMMAP (IC_e_ERR_RXTX_OTHER,               IC_e_DEM_IMAGER_COMM, ICERR_cui8_PRIO_LOW), /* Lower prio, because maybe consecutive fault */
    ICERR_DEMMAP (IC_e_ERR_REGTRANS_ERRORS_NOT_ZERO, IC_e_DEM_IMAGER_COMM, ICERR_cui8_PRIO_NORMAL),
    ICERR_DEMMAP (IC_e_ERR_ASYNC_REGCHECK_READ_R,    IC_e_DEM_IMAGER_COMM_R, ICERR_cui8_PRIO_NORMAL),
    ICERR_DEMMAP (IC_e_ERR_REGTX_VERIFY_FAILED_R,    IC_e_DEM_REGTX_SYNC_VERIFY_FAILED_R, ICERR_cui8_PRIO_NORMAL),
#if (ICCFG_ENABLE_LEFT_IMAGER == 1)
    ICERR_DEMMAP (IC_e_ERR_ASYNC_REGCHECK_READ_L,    IC_e_DEM_IMAGER_COMM_L, ICERR_cui8_PRIO_NORMAL),
    ICERR_DEMMAP (IC_e_ERR_REGTX_VERIFY_FAILED_L,    IC_e_DEM_REGTX_SYNC_VERIFY_FAILED_L, ICERR_cui8_PRIO_NORMAL),
#endif

    /* Parameters & external Inputs */
    ICERR_DEMMAP (IC_e_ERR_INIT_ICPARAMETERS,         IC_e_DEM_PARAMETER, ICERR_cui8_PRIO_NORMAL),
    ICERR_DEMMAP (IC_e_ERR_IRCC_SET_PPARS,            IC_e_DEM_PARAMETER, ICERR_cui8_PRIO_NORMAL),
    ICERR_DEMMAP (IC_e_ERR_CROI_OUT_OF_RANGE,         IC_e_DEM_PARAMETER, ICERR_cui8_PRIO_NORMAL),
    ICERR_DEMMAP (IC_e_ERR_INVALID_CORRECTION_FACTOR, IC_e_DEM_PARAMETER, ICERR_cui8_PRIO_NORMAL),
    ICERR_DEMMAP (IC_e_ERR_IMGNC_INIT,                IC_e_DEM_PARAMETER, ICERR_cui8_PRIO_NORMAL),
    ICERR_DEMMAP (IC_e_ERR_ICROI_OUT_OF_RANGE,        IC_e_DEM_CALIBRATION, ICERR_cui8_PRIO_NORMAL),
    ICERR_DEMMAP_ANTIFLOOD (IC_e_ERR_INPUTTIMEOUT_LDONLINECALIB,   IC_e_DEM_INPUTS, ICERR_cui8_PRIO_NORMAL),
    ICERR_DEMMAP_ANTIFLOOD (IC_e_ERR_INPUTTIMEOUT_VDY,             IC_e_DEM_INPUTS, ICERR_cui8_PRIO_NORMAL),
#if (ICCFG_ENABLE_LEFT_IMAGER == 1)
    ICERR_DEMMAP (IC_e_ERR_IMGSYNC_RANGE_EXCEEDED,                 IC_e_DEM_INPUTS_DSP2, ICERR_cui8_PRIO_NORMAL), /* Wrong input from SAC    */
    ICERR_DEMMAP (IC_e_ERR_IMGSYNC,                                IC_e_DEM_INPUTS_DSP2, ICERR_cui8_PRIO_NORMAL), /* TODO: Replace "IMGSYNC" */
    ICERR_DEMMAP (IC_e_ERR_PROCESS_LEFTREGS_REPONSE,               IC_e_DEM_INPUTS_DSP2, ICERR_cui8_PRIO_HIGH),   /* Wrong data from DSP2    */
    ICERR_DEMMAP_ANTIFLOOD (IC_e_ERR_INPUTTIMEOUT_IMGSYNC_MEAS,    IC_e_DEM_INPUTS_DSP2, ICERR_cui8_PRIO_NORMAL),
    ICERR_DEMMAP_ANTIFLOOD (IC_e_ERR_INPUTTIMEOUT_IMGSYNC_REQ,     IC_e_DEM_INPUTS_DSP2, ICERR_cui8_PRIO_NORMAL),
    ICERR_DEMMAP_ANTIFLOOD (IC_e_ERR_INPUTTIMEOUT_LEFTREGRESPONSE, IC_e_DEM_INPUTS_DSP2, ICERR_cui8_PRIO_NORMAL),
#endif

    /* Data processing, e.g. noise calculation etc. */
    ICERR_DEMMAP (IC_e_ERR_IRCC_CALC,                IC_e_DEM_GENERAL_FATAL, ICERR_cui8_PRIO_NORMAL),
    ICERR_DEMMAP (IC_e_ERR_IC_RUN,                   IC_e_DEM_GENERAL_FATAL, ICERR_cui8_PRIO_NORMAL),
    ICERR_DEMMAP (IC_e_ERR_IMGNC_LINECALLBACK,       IC_e_DEM_GENERAL, ICERR_cui8_PRIO_NORMAL),
    ICERR_DEMMAP (IC_e_ERR_IMGNC_REGCALLBACK,        IC_e_DEM_GENERAL, ICERR_cui8_PRIO_NORMAL),
    ICERR_DEMMAP (IC_e_ERR_IMGNC_GETRESULTS,         IC_e_DEM_GENERAL, ICERR_cui8_PRIO_NORMAL),

    /* Startup tests */
    ICERR_DEMMAP (IC_e_ERR_DATABUSTEST_FAILED,       IC_e_DEM_IMAGER_DATABUS_MCU_STARTUP, ICERR_cui8_PRIO_NORMAL), /* Hardware error */
    ICERR_DEMMAP (IC_e_ERR_DATABUSTEST_CYCLIC,       IC_e_DEM_IMAGER_DATABUS_MCU_CYCLIC,  ICERR_cui8_PRIO_NORMAL), /* Hardware error */
    ICERR_DEMMAP (IC_e_ERR_BIST_FAILED_RIGHT,        IC_e_DEM_IMAGER_BIST_R, ICERR_cui8_PRIO_NORMAL),      /* Hardware error */
#if (ICCFG_ENABLE_LEFT_IMAGER == 1)
    ICERR_DEMMAP (IC_e_ERR_BIST_FAILED_LEFT,         IC_e_DEM_IMAGER_BIST_L, ICERR_cui8_PRIO_NORMAL),      /* Hardware error */
#endif

    /* Analog test*/
#if (IC_ANALOG_TEST_ENABLED == 1)
    ICERR_DEMMAP (IC_e_ERR_ATEST_INIT,               IC_e_DEM_GENERAL_FATAL,  ICERR_cui8_PRIO_NORMAL),      /* Software error */
    ICERR_DEMMAP (IC_e_ERR_ATEST_LINE,               IC_e_DEM_GENERAL_FATAL,  ICERR_cui8_PRIO_NORMAL),      /* Software error */
    ICERR_DEMMAP (IC_e_ERR_ATEST_MEAN_TO_COLMEAN,    IC_e_DEM_IMAGER_ATEST_R, ICERR_cui8_PRIO_NORMAL),
    ICERR_DEMMAP (IC_e_ERR_ATEST_MEAN_TO_REFMEAN,    IC_e_DEM_IMAGER_ATEST_R, ICERR_cui8_PRIO_NORMAL),
    ICERR_DEMMAP (IC_e_ERR_ATEST_ATV1_1X,            IC_e_DEM_IMAGER_ATEST_R, ICERR_cui8_PRIO_NORMAL),
    ICERR_DEMMAP (IC_e_ERR_ATEST_ATV1_2X,            IC_e_DEM_IMAGER_ATEST_R, ICERR_cui8_PRIO_NORMAL),
    ICERR_DEMMAP (IC_e_ERR_ATEST_ATV3_1X,            IC_e_DEM_IMAGER_ATEST_R, ICERR_cui8_PRIO_NORMAL),
    ICERR_DEMMAP (IC_e_ERR_ATEST_MEAN_REF_1X,        IC_e_DEM_IMAGER_ATEST_R, ICERR_cui8_PRIO_NORMAL),
    ICERR_DEMMAP (IC_e_ERR_ATEST_MEAN_REF_2X,        IC_e_DEM_IMAGER_ATEST_R, ICERR_cui8_PRIO_NORMAL),
#endif

    /* Other software errors */
    ICERR_DEMMAP (IC_e_ERR_READ_TEMPERATURE,         IC_e_DEM_GENERAL,       ICERR_cui8_PRIO_NORMAL),
    ICERR_DEMMAP (IC_e_ERR_TEMPSENS_NOT_ENABLED,     IC_e_DEM_GENERAL,       ICERR_cui8_PRIO_NORMAL),
    ICERR_DEMMAP (IC_e_ERR_WRONG_STATE,              IC_e_DEM_GENERAL_FATAL, ICERR_cui8_PRIO_NORMAL),   /* IC has been called in wrong state! */

    /* Fatal errors that can only be caused by malicious software                                */
    /* Those errors are 'sticky', so the DEM will never be set to passed again (only on re-init) */
#if (ICCFG_ENABLE_LEFT_IMAGER == 1)
    ICERR_DEMMAP_STICKY (IC_e_ERR_REGISTER_LEFT_REQUEST_TOO_BIG, IC_e_DEM_GENERAL_FATAL, ICERR_cui8_PRIO_NORMAL),
#endif
    ICERR_DEMMAP_STICKY (IC_e_ERR_FATAL_PROGRAM_ERROR,      IC_e_DEM_GENERAL_FATAL, ICERR_cui8_PRIO_NORMAL),
    ICERR_DEMMAP_STICKY (IC_e_ERR_DEMREPORT,                IC_e_DEM_GENERAL_FATAL, ICERR_cui8_PRIO_NORMAL),
    ICERR_DEMMAP_STICKY (IC_e_ERR_CROI_STARTY_MUSTBEEQUAL,  IC_e_DEM_GENERAL_FATAL, ICERR_cui8_PRIO_NORMAL),
    ICERR_DEMMAP_STICKY (IC_e_ERR_INIT_SENSORDRV,           IC_e_DEM_GENERAL_FATAL, ICERR_cui8_PRIO_NORMAL),
    ICERR_DEMMAP_STICKY (IC_e_ERR_IRCC_GET,                 IC_e_DEM_GENERAL_FATAL, ICERR_cui8_PRIO_NORMAL),
    ICERR_DEMMAP_STICKY (IC_e_ERR_IC_INPUT,                 IC_e_DEM_GENERAL_FATAL, ICERR_cui8_PRIO_NORMAL),
    ICERR_DEMMAP_STICKY (IC_e_ERR_NULLPOINTER,              IC_e_DEM_GENERAL_FATAL, ICERR_cui8_PRIO_NORMAL),
    ICERR_DEMMAP_STICKY (IC_e_ERR_DIVISION_BY_ZERO,         IC_e_DEM_GENERAL_FATAL, ICERR_cui8_PRIO_NORMAL),
    ICERR_DEMMAP_STICKY (IC_e_ERR_ILLEGAL_ENUM_VALUE,       IC_e_DEM_GENERAL_FATAL, ICERR_cui8_PRIO_NORMAL),
    ICERR_DEMMAP_STICKY (IC_e_ERR_SET_FRAMEHEIGHT,          IC_e_DEM_GENERAL_FATAL, ICERR_cui8_PRIO_NORMAL),
    ICERR_DEMMAP_STICKY (IC_e_ERR_ILLEGAL_REGISTER,         IC_e_DEM_GENERAL_FATAL, ICERR_cui8_PRIO_NORMAL),
    ICERR_DEMMAP_STICKY (IC_e_ERR_ILLEGAL_SENSORNUM,        IC_e_DEM_GENERAL_FATAL, ICERR_cui8_PRIO_NORMAL),
    ICERR_DEMMAP_STICKY (IC_e_ERR_INIT_IEDP,                IC_e_DEM_GENERAL_FATAL, ICERR_cui8_PRIO_NORMAL),
    ICERR_DEMMAP_STICKY (IC_e_ERR_XSTART,                   IC_e_DEM_GENERAL_FATAL, ICERR_cui8_PRIO_NORMAL),
    ICERR_DEMMAP_STICKY (IC_e_ERR_YSTART,                   IC_e_DEM_GENERAL_FATAL, ICERR_cui8_PRIO_NORMAL),
    ICERR_DEMMAP_STICKY (IC_e_ERR_CROI_WIDTH,               IC_e_DEM_GENERAL_FATAL, ICERR_cui8_PRIO_NORMAL),
    ICERR_DEMMAP_STICKY (IC_e_ERR_CROI_HEIGHT,              IC_e_DEM_GENERAL_FATAL, ICERR_cui8_PRIO_NORMAL),
    ICERR_DEMMAP_STICKY (IC_e_ERR_IMGDRV_GETBUFFERS,        IC_e_DEM_GENERAL_FATAL, ICERR_cui8_PRIO_NORMAL),
    ICERR_DEMMAP_STICKY (IC_e_ERR_SOURCECODE_ERROR,         IC_e_DEM_GENERAL_FATAL, ICERR_cui8_PRIO_NORMAL),
    ICERR_DEMMAP_STICKY (IC_e_ERR_EXPOSURE_LINENUM,         IC_e_DEM_GENERAL_FATAL, ICERR_cui8_PRIO_NORMAL),
    ICERR_DEMMAP_STICKY (IC_e_ERR_BUFFER_OVERRUN,           IC_e_DEM_GENERAL_FATAL, ICERR_cui8_PRIO_NORMAL),
    ICERR_DEMMAP_STICKY (IC_e_ERR_REGISTERTABLE,            IC_e_DEM_GENERAL_FATAL, ICERR_cui8_PRIO_NORMAL),
    ICERR_DEMMAP_STICKY (IC_e_ERR_NOTINIT,                  IC_e_DEM_GENERAL_FATAL, ICERR_cui8_PRIO_NORMAL),
    ICERR_DEMMAP_STICKY (IC_e_ERR_ILLEGAL_DIMENSIONS,       IC_e_DEM_GENERAL_FATAL, ICERR_cui8_PRIO_NORMAL),
    ICERR_DEMMAP_STICKY (IC_e_ERR_NOT_IMPLEMENTED,          IC_e_DEM_GENERAL_FATAL, ICERR_cui8_PRIO_NORMAL),
    ICERR_DEMMAP_STICKY (IC_e_ERR_ICEXPMG_SETTODRIVER,      IC_e_DEM_GENERAL_FATAL, ICERR_cui8_PRIO_NORMAL),
    ICERR_DEMMAP_STICKY (IC_e_ERR_REGISTER_ROI,             IC_e_DEM_GENERAL_FATAL, ICERR_cui8_PRIO_NORMAL),
    ICERR_DEMMAP_STICKY (IC_e_ERR_DELETE_ROI,               IC_e_DEM_GENERAL_FATAL, ICERR_cui8_PRIO_NORMAL),
    ICERR_DEMMAP_STICKY (IC_e_ERR_ROI_ALREADY_REGISTERED,   IC_e_DEM_GENERAL_FATAL, ICERR_cui8_PRIO_NORMAL),
    ICERR_DEMMAP_STICKY (IC_e_ERR_GETEXPMEASFREEZE,         IC_e_DEM_GENERAL_FATAL, ICERR_cui8_PRIO_NORMAL),
    ICERR_DEMMAP_STICKY (IC_e_ERR_REINIT_IMGCOMM,           IC_e_DEM_GENERAL_FATAL, ICERR_cui8_PRIO_NORMAL),
    ICERR_DEMMAP_STICKY (IC_e_ERR_ILLEGAL_REGTRANSFER_ID,   IC_e_DEM_GENERAL_FATAL, ICERR_cui8_PRIO_NORMAL),
    ICERR_DEMMAP_STICKY (IC_e_ERR_UNSUPPORTED_IMAGER,       IC_e_DEM_GENERAL_FATAL, ICERR_cui8_PRIO_NORMAL),
    ICERR_DEMMAP_STICKY (IC_e_ERR_GET_REGISTER_DEFAULTS,    IC_e_DEM_GENERAL_FATAL, ICERR_cui8_PRIO_NORMAL),
    ICERR_DEMMAP_STICKY (IC_e_ERR_IMGDRV_SET_ICROI,         IC_e_DEM_GENERAL_FATAL, ICERR_cui8_PRIO_NORMAL)
};

//  This map assigns DEMs to a DTC and provides parameters for debouncing. It is not
//  required to map every DEM to a DTC. The array element order defines the priority
//  which is used for storing the source DEM id to the DTC's optional data, in case more
//  DEMs would trigger the same DTC during one cycle.
//  
//  Ignore hardcoded values, implizit num initializers:
//  PRQA S 3120,3218,3111,3674 DTC_MAP
/*## attribute ICERR_cas_DtcMap */
static const ICERR_S_DtcMapEntry ICERR_cas_DtcMap[] = {
#if (ICCFG_ENABLE_LEFT_IMAGER == 1)
    { IC_e_DEM_IMAGER_COMM_L,               IC_e_DEM_COMMON_HW_DEF_ERR,  1,  1,   1 }, /* Handle hard */
    { IC_e_DEM_IMAGER_BIST_L,               IC_e_DEM_COMMON_HW_DEF_ERR,  1,  1,   3 }, /* 3x retry on startup, so trigger after 3x failed in series */
    { IC_e_DEM_REGTX_SYNC_VERIFY_FAILED_L,  IC_e_DEM_COMMON_HW_DEF_ERR,  1,  1,   1 }, /* Handle hard */
    { IC_e_DEM_REGCHECK_FAILED_L,           IC_e_DEM_COMMON_HW_DEF_ERR, 33,  1, 100 }, /* DTC if failed more than 3 times in 100 frames */
#endif
    { IC_e_DEM_IMAGER_BIST_R,               IC_e_DEM_COMMON_HW_DEF_ERR,  1,  1,   3 }, /* 3x retry on startup, so trigger after 3x failed in series */
    { IC_e_DEM_IMAGER_DATABUS_MCU_STARTUP,  IC_e_DEM_COMMON_HW_DEF_ERR,  1,  1,   1 }, /* Handle hard */
    { IC_e_DEM_IMAGER_ATEST_R,              IC_e_DEM_COMMON_HW_DEF_ERR,  1,  1,   1 }, /* Handle hard */
    { IC_e_DEM_REGTX_SYNC_VERIFY_FAILED_R,  IC_e_DEM_COMMON_HW_DEF_ERR,  1,  1,   1 }, /* Handle hard */
    { IC_e_DEM_FRAMECOUNTER,                IC_e_DEM_COMMON_HW_DEF_ERR, 33,  1, 100 }, /* DTC if failed more than 3 times in 100 frames */
    { IC_e_DEM_FRAMECOUNTER_INCONSISTENT,   IC_e_DEM_COMMON_HW_DEF_ERR, 33,  1, 100 }, /* DTC if failed more than 3 times in 100 frames */
    { IC_e_DEM_UNEXPECTED_EMBD_REG_STAT,    IC_e_DEM_COMMON_HW_DEF_ERR, 33,  1, 100 }, /* DTC if failed more than 3 times in 100 frames */
    { IC_e_DEM_PART1_NOTCALLED,             IC_e_DEM_COMMON_HW_DEF_ERR, 33,  1, 100 }, /* DTC if failed more than 3 times in 100 frames */
    { IC_e_DEM_PART2_NOTCALLED,             IC_e_DEM_COMMON_HW_DEF_ERR, 33,  1, 100 }, /* DTC if failed more than 3 times in 100 frames */
    { IC_e_DEM_IMAGER_COMM_R,               IC_e_DEM_COMMON_HW_DEF_ERR,  1,  1,   1 }, /* Handle hard */
    { IC_e_DEM_IMAGER_COMM,                 IC_e_DEM_COMMON_HW_DEF_ERR,  1,  1,   1 }, /* Handle hard */
    { IC_e_DEM_IMAGER_COMM_TIMING,          IC_e_DEM_COMMON_HW_DEF_ERR, 33,  1, 100 }, /* DTC if failed more than 3 times in 100 frames */
    { IC_e_DEM_EMBEDDED_REGS_CORRUPTED,     IC_e_DEM_COMMON_HW_DEF_ERR, 33,  1, 100 }, /* DTC if failed more than 3 times in 100 frames */
    { IC_e_DEM_EMBEDDED_STAT_CORRUPTED,     IC_e_DEM_COMMON_HW_DEF_ERR, 33,  1, 100 }, /* DTC if failed more than 3 times in 100 frames */
    { IC_e_DEM_REGCHECK_FAILED_R,           IC_e_DEM_COMMON_HW_DEF_ERR, 33,  1, 100 }, /* DTC if failed more than 3 times in 100 frames */
    { IC_e_DEM_GENERAL_FATAL,               IC_e_DEM_COMMON_HW_DEF_ERR, 33,  1, 100 }, /* DTC if failed more than 3 times in 100 frames */
#if (ICCFG_ENABLE_LEFT_IMAGER == 1)
    { IC_e_DEM_HARDWARE_TIMING,             IC_e_DEM_COMMON_HW_DEF_ERR, 33,  1, 100 }, /* DTC if failed more than 3 times in 100 frames */
#endif
    { IC_e_DEM_SOFTWARE_TIMING,             IC_e_DEM_COMMON_HW_DEF_ERR, 33,  1, 100 }, /* DTC if failed more than 3 times in 100 frames */
    { IC_e_DEM_IMAGER_DATABUS_MCU_CYCLIC,   IC_e_DEM_COMMON_HW_DEF_ERR, 33,  1, 100 }, /* DTC if failed more than 3 times in 100 frames */
    { IC_e_DEM_PARAMETER,                   IC_e_DEM_COMMON_HW_DEF_ERR,  1,  1,   1 }, /* No debouncing! */
};// PRQA L:DTC_MAP

//*****************************************************************************
//  Functionname:  ICERR_b_HILMODE_ACTIVE
//  
//  Macro for detecting whether we are running on HIL
//  
//    
//  
//  return         RhpString
//**************************************************************************** */
/*## operation ICERR_b_HILMODE_ACTIVE() const */
#define ICERR_b_HILMODE_ACTIVE()    \
    ((IC_cui32_KEY_HILMODE == ICERR_ui32_HILModeEnabled) ? b_TRUE : b_FALSE) // PRQA S 3429

//*****************************************************************************
//  Functionname:  ICERR_v_DtcEvaluation
//  
//  Evaluates the status of DTCs. For each mapping DEM->DTC, the DEM status is evaluated and
//  the associated DTC status is updated. Debouncing is implemented, so the DTC is only set to
//  failed in case the DEM debounce counter exceeds the threshold defined in the mapping.
//  
//  The debounce counter is incremented by the value specified in the DEM->DTC mapping in case
//  the DEM is failed and decremented by another specified value of the mapping entry in case
//  the DEM is passed. If the DEM is not tested, the debounce counter is not changed.
//  
//    
//  
//  return         void
//**************************************************************************** */
/*## operation ICERR_v_DtcEvaluation() */
static void ICERR_v_DtcEvaluation(void);

//*****************************************************************************
//  Functionname:  ICERR_e_CheckErrorDefinitions
//  
//  Static code check function, which checks whether the enum IC_E_ERROR is consistent with the
//  structure definition ICERR_S_ErrCodeNamesForMTS.
//  
//    
//  
//  return         IC_E_ERROR
//**************************************************************************** */
/*## operation ICERR_e_CheckErrorDefinitions() */
static IC_E_ERROR ICERR_e_CheckErrorDefinitions(void);

//*****************************************************************************
//  Functionname:  ICERR_e_CreateDemMapping
//  
//  Creates a mapping LUT with IC_E_ERROR => IC_E_DEM from the list defined by ICERR_cas_DemMapping.
//  It is checked whether the mapping is complete, so every IC_E_ERROR must have an entry in the list!
//  
//    
//  
//  return         IC_E_ERROR
//**************************************************************************** */
/*## operation ICERR_e_CreateDemMapping() */
static IC_E_ERROR ICERR_e_CreateDemMapping(void);

/*## operation ICERR_e_HandleErr(const char *,uint16,IC_E_ERROR,sint32) */

/*#[ ignore */
// Suppress QAC Messages:
// - 5013: Use of basic type 'char'.
// - 3625: Type 'char' has been used in the declaration of an object or a function.
//         => Strings are only copied to measfreeze struct for MTS and never evaluated in the software
//        
// PRQA S 5013,3625 3
/*#]*/
IC_E_ERROR ICERR_e_HandleErr(const char * pch_ModuleNameStr, uint16 ui16_LineNum, IC_E_ERROR e_ErrCode, sint32 si32_Hint) {
    /*#[ operation ICERR_e_HandleErr(const char *,uint16,IC_E_ERROR,sint32) */
    ICERR_S_ErrorEntry  *ps_ErrEntry = NULL;
    ICERR_S_DemStatus   *ps_DemStat = NULL;
    ICERR_S_DemMapEntry const * ps_DemMapping = NULL;
    uint8 ui8_DemMappingIndex = 0u;
    boolean b_DoNotLog = b_FALSE;
    IC_E_DEM e_Dem; // PRQA S 0781
    
    if (b_TRUE == ICERR_b_BasicInitDone)
    {
    
      // Count occurrence of some specific errors and do some filtering
      if (NULL != ICERR_ps_ErrCnts)
      {
        switch (e_ErrCode)
        {
        case IC_e_ERR_EMBEDDED_REGS_LINE0_CORRUPTED:
          ICERR_ps_ErrCnts->ui16_ErrCntWrongEmbeddedRegDat++;
          break;
        case IC_e_ERR_MEASFREEZE:
          ICERR_ps_ErrCnts->ui16_ErrCntMeasfreeze++;
    
          // TODO: Workaround until FR 110410 fixed: Ignore measfreeze errors
          e_ErrCode = IC_e_ERR_OK;
          break;
        case IC_e_ERR_CHECK_FRAMENUM_INCR:
          ICERR_ps_ErrCnts->ui16_ErrCntFrameNumIncr++;
          break;
        case IC_e_ERR_CHECK_FRAMENUM_REGSTAT_MATCH:
          ICERR_ps_ErrCnts->ui16_ErrCntFrameNumRegStatMatch++;
          break;
    #if (ICCFG_ENABLE_LEFT_IMAGER == 1)
        case IC_e_ERR_CHECK_REGISTERS_L:
          /* !!Fallthrough!!*/
        case IC_e_ERR_CHECK_REGISTERS_L_FSYNCED:
          ICERR_ps_ErrCnts->ui16_ErrCntImagerRegCompareL++;
          break;
    #endif
        case IC_e_ERR_CHECK_REGISTERS_R:
          /* !!Fallthrough!!*/
        case IC_e_ERR_CHECK_REGISTERS_R_FSYNCED:
          ICERR_ps_ErrCnts->ui16_ErrCntImagerRegCompareR++;
          break;
        case IC_e_ERR_IC_ROI_SIZE_POSITION_MISMATCH:
          ICERR_ps_ErrCnts->ui16_ErrCntICRoiRegisterMismatch++;
          break;
        case IC_e_ERR_EMBEDDED_STAT_CORRUPTED:
          ICERR_ps_ErrCnts->ui16_ErrCntWrongEmbeddedStatDat++;
          break;
        case IC_e_ERR_CHECK_FRAMEID:
          ICERR_ps_ErrCnts->ui16_ErrCntFrameId++;
          break;
        case IC_e_ERR_HISTOGRAM_PIXELCOUNT_MISMATCH:
          ICERR_ps_ErrCnts->ui16_ErrCntHistogramPixelCount++;
          
          // Filter this error in HIL mode, as histogram pixelcount depends on IC-ROI
          // size which in turn can vary when calibration forces it to move outside
          // the CROI
          if (ICERR_b_HILMODE_ACTIVE() == b_TRUE)
          {
            e_ErrCode = IC_e_ERR_OK;
          }
          break;
        default:
          // Do nothing
          break;
        }
      }
    
      // Handle error if not filtered
      if (e_ErrCode != IC_e_ERR_OK)
      {
        // The following section needs correct init of this module
        if (b_FALSE != ICERR_b_FullInitDone)
        {
          // Lookup map-entry for this error
          ui8_DemMappingIndex = ICERR_aui8_DemMappingLut[(uint8)e_ErrCode];
          ps_DemMapping       = &ICERR_cas_DemMapping[ui8_DemMappingIndex];
    
          // Add DEM entry, replace already existing errors by higher priority errors
          e_Dem = ps_DemMapping->e_Dem;
          if ((ICERR_ce_ERR_NOT_MAPPED != ps_DemMapping->e_Dem) && (e_Dem < IC_e_DEM__NUM_ENTRIES__))
          {
            // Get status for current DEM entry.
            // QAC is wrong where with array index beyond size, so suppress 3692
            ps_DemStat = &ICERR_as_DemStatus[e_Dem];
            if ((IC_e_DEMSTATUS_FAILED != ps_DemStat->e_Status) ||
                (ps_DemStat->ui8_CurrentPrio < ps_DemMapping->ui8_Priority))
            {
              ps_DemStat->e_Status                           = IC_e_DEMSTATUS_FAILED;
              ps_DemStat->ui8_CurrentPrio                    = ps_DemMapping->ui8_Priority;
              ps_DemStat->uN_OptData.s_DemExt.e_ErrCode      = e_ErrCode;
              ps_DemStat->uN_OptData.s_DemExt.ui8_Reserved   = 0;
              ps_DemStat->uN_OptData.s_DemExt.ui16_LineNum   = ui16_LineNum;
              ps_DemStat->uN_OptData.s_DemExt.si32_Hint      = si32_Hint;
              ps_DemStat->uN_OptData.s_DemExt.ui16_FrameCtr  = ICERR_ui16_FrameNumSaturated;
              ps_DemStat->uN_OptData.s_DemExt.s_IcState      = ICERR_s_IcState;
              ps_DemStat->uN_OptData.s_DemExt.si8_TempDegree = ICERR_si8_Temperature;
            }
    
            // If current map entry is marked as 'sticky', then flag this DEM as permanently failed!
            if ((ps_DemMapping->ui8_Flags & ICERR_cui8_MAPFLAG_STICKY) != 0)
            {
              ps_DemStat->ui8_Flags |= ICERR_cui8_STATFLAG_FAILED_PERM;
            }
          }
    
          // Handle anti-flood protection: For errors flagged as anti-flood, do not add
          // them to the error-list if same error occurred during last cycle.
          //
          // NOTE: Failed DEMs are always reported!
          if ((ps_DemMapping->ui8_Flags & ICERR_cui8_MAPFLAG_ANTIFLOOD) != 0)
          {
            if (IC_b_BitmapGetBit(ICERR_bf_FailedErrsLastCycle, (uint32)e_ErrCode) == b_TRUE)
            {
              b_DoNotLog = b_TRUE;
              if (NULL != ICERR_ps_ErrCnts)
              {
                ICERR_ps_ErrCnts->ui16_ErrCntAntiFlood++;
              }
            }
          }
        }
    
        // Add entry to error-list
        if ((b_DoNotLog != b_TRUE)
            && (NULL != ICERR_ps_MeasData)
            && (NULL != ICERR_ps_ErrCnts))
        {
          ps_ErrEntry = &ICERR_ps_MeasData->as_ErrorList[ICERR_ui32_ErrBuffIndex];
          ps_ErrEntry->ui16_ErrNum    = (uint16)ICERR_ps_ErrCnts->ui32_TotalErrCnt;
          ps_ErrEntry->si32_Hint      = si32_Hint;
          ps_ErrEntry->e_ErrCode      = e_ErrCode;
          ps_ErrEntry->ui16_FrameNum  = ICERR_ui16_FrameNum;
          ps_ErrEntry->ui64_Timestamp = ICOSW_ui64_GetTimeUs();
          ps_ErrEntry->ui16_LineNum   = ui16_LineNum;
          (void)memcpy(ps_ErrEntry->ach_ModuleName, pch_ModuleNameStr, ICERR_cui16_ModuleNameLength);
    
          // Increment error-list entry index and handle wrap-around
          ICERR_ui32_ErrBuffIndex++;
          if (ICERR_ui32_ErrBuffIndex >= ICCFG_cui32_ERRORLIST_SIZE)
          {
            ICERR_ui32_ErrBuffIndex = 0;
          }
    
          // Count total number of errors
          if (NULL != ICERR_ps_ErrCnts)
          {
            ICERR_ps_ErrCnts->ui32_TotalErrCnt++;
          }
          
          // Log to simulation environment on MTS
    #if (IC_COMPILE_FOR_MTS == 1)
          if (ICERR_pfct_SimLogErr != NULL)
          {
            ICERR_pfct_SimLogErr(ps_ErrEntry);
          }
    #endif
        }
    
        // Set bit for failed error
        IC_v_BitmapSetBit(ICERR_bf_FailedErrsThisCycle, (uint32)e_ErrCode);
      }
    }
    
    return e_ErrCode;
    
    // PRQA S 7002,7004 4
    /*#]*/
}

/*## operation ICERR_e_Init(ICERR_S_MeasData,uint32) */
#pragma push
#pragma optimize_for_size on
IC_E_ERROR ICERR_e_Init(ICERR_S_MeasData* ps_MeasStruct, uint32 ui32_EnableHILMode) {
    /*#[ operation ICERR_e_Init(ICERR_S_MeasData,uint32) */
    IC_E_ERROR e_Ret  = IC_e_ERR_OK;
    uint32 ui32_Index = 0;
    
    // Do nullpointer checks
    if (ps_MeasStruct == NULL)
    {
      e_Ret = ICERR_HANDLE(IC_e_ERR_NULLPOINTER, 0);
    }
    else
    {
      // Setup some pointers
      ICERR_ps_MeasData =  ps_MeasStruct;
      ICERR_ps_ErrCnts  = &ps_MeasStruct->s_ErrorCounters;
    
      // Init variables
      ICERR_b_BasicInitDone        = b_FALSE;
      ICERR_b_FullInitDone         = b_FALSE;
      ICERR_ui16_FrameNum          = 0;
      ICERR_ui16_FrameNumSaturated = 0;
      ICERR_ui32_ErrBuffIndex      = 0;
      ICERR_ui32_CycleCnt          = 0;
      ICERR_ui32_HILModeEnabled    = ui32_EnableHILMode;
      /* Do _NOT_ clear ICERR_as_DemStatus, as debouncing will not work correctly on init retry  */
      IC_v_ZEROMEM(ICERR_aui8_DemMappingLut);
      IC_v_ZEROMEM(ICERR_bf_FailedErrsThisCycle);
      IC_v_ZEROMEM(ICERR_bf_FailedErrsLastCycle);
    
      // We finished basic initialization, so we can now also add our own errors to the
      // error-list
      ICERR_b_BasicInitDone = b_TRUE;
    
      // Init DEM stuff
      e_Ret = ICERR_e_CreateDemMapping();
    
      if (IC_e_ERR_OK == e_Ret)
      {
        // Check if definition of 'IC_E_ERROR' and 'ICERR_S_ErrCodeNamesForMTS' is consistent
        e_Ret = ICERR_e_CheckErrorDefinitions();
        if (IC_e_ERR_OK != e_Ret)
        {
          (void)ICERR_HANDLE(e_Ret, 0);
        }
      }
    
      // Initialize DEM status list
      ICERR_ui16_NextCycSlowPassedRepDemIdx = 0;
      for (ui32_Index = 0; ui32_Index < IC_ARRLEN(ICERR_as_DemStatus); ui32_Index++)
      {
        ICERR_as_DemStatus[ui32_Index].e_LastReportedStatus = IC_e_DEMSTATUS_NOT_TESTED;
        ICERR_as_DemStatus[ui32_Index].ui8_ErrorLevel       = ICERR_cui8_DEMFAILED_ERROR_LEVEL;
      }
    }
    
    // Everything was OK!
    if (IC_e_ERR_OK == e_Ret)
    {
      ICERR_b_FullInitDone = b_TRUE;
    }
    return e_Ret;
    /*#]*/
}
#pragma pop

/*## operation ICERR_v_DemFailedExt(IC_E_DEM,uint32,uint16) */
void ICERR_v_DemFailedExt(IC_E_DEM e_DemEvent, uint32 ui32_OptData, uint16 ui16_LineNum) {
    /*#[ operation ICERR_v_DemFailedExt(IC_E_DEM,uint32,uint16) */
    ICERR_S_DemStatus *ps_DemStat;
    if(e_DemEvent < IC_e_DEM__NUM_ENTRIES__)
    {
      ps_DemStat = &ICERR_as_DemStatus[(uint8)e_DemEvent];
    
      // Count failed DEMs
      if (NULL != ICERR_ps_ErrCnts)
      {
        ICERR_ps_ErrCnts->ui16_ErrCntDemErrCount++;
      }
    
      // Do not overwrite FAILED status having higher priorities
      if (  (ps_DemStat->e_Status        != IC_e_DEMSTATUS_FAILED)
         || (ps_DemStat->ui8_CurrentPrio  < ICERR_cui8_PRIO_EXPLICIT_DEM))
      {
        ps_DemStat->e_Status                           = IC_e_DEMSTATUS_FAILED;
        ps_DemStat->ui8_CurrentPrio                    = ICERR_cui8_PRIO_EXPLICIT_DEM;
        ps_DemStat->uN_OptData.s_DemExt.e_ErrCode      = IC_e_ERR_EXPLICIT_DEM;
        ps_DemStat->uN_OptData.s_DemExt.si32_Hint      = (sint32)ui32_OptData;
        ps_DemStat->uN_OptData.s_DemExt.ui16_LineNum   = ui16_LineNum;
        ps_DemStat->uN_OptData.s_DemExt.ui16_FrameCtr  = ICERR_ui16_FrameNumSaturated;
        ps_DemStat->uN_OptData.s_DemExt.s_IcState      = ICERR_s_IcState;
        ps_DemStat->uN_OptData.s_DemExt.si8_TempDegree = ICERR_si8_Temperature;
      }
    }
    else
    {
      // Report non-existing DEMs
      (void)ICERR_HANDLE(IC_e_ERR_ILLEGAL_ENUM_VALUE, e_DemEvent);
    }
    /*#]*/
}

/*## operation ICERR_v_DemFailedExtKeep(IC_E_DEM,uint32,uint16) */
void ICERR_v_DemFailedExtKeep(IC_E_DEM e_DemEvent, uint32 ui32_OptData, uint16 ui16_LineNum) {
    /*#[ operation ICERR_v_DemFailedExtKeep(IC_E_DEM,uint32,uint16) */
    if(e_DemEvent < IC_e_DEM__NUM_ENTRIES__)
    {
      if (IC_e_DEMSTATUS_FAILED != ICERR_as_DemStatus[(uint8)e_DemEvent].e_Status)
      {
        ICERR_v_DemFailedExt(e_DemEvent, ui32_OptData, ui16_LineNum);
      }
    }
    else
    {
      // Report non-existing DEMs
      (void)ICERR_HANDLE(IC_e_ERR_ILLEGAL_ENUM_VALUE, e_DemEvent);
    }
    /*#]*/
}

/*## operation ICERR_v_DemPassed(const IC_E_DEM) */
void ICERR_v_DemPassed(const IC_E_DEM e_DemEvent) {
    /*#[ operation ICERR_v_DemPassed(const IC_E_DEM) */
    // Check valid enum value
    if(e_DemEvent < IC_e_DEM__NUM_ENTRIES__)
    {
      // Do not overwrite FAILED status
      if (IC_e_DEMSTATUS_FAILED != ICERR_as_DemStatus[e_DemEvent].e_Status)
      {
        ICERR_as_DemStatus[e_DemEvent].e_Status        = IC_e_DEMSTATUS_PASSED;
        ICERR_as_DemStatus[e_DemEvent].ui8_CurrentPrio = ICERR_cui8_PRIO_EXPLICIT_DEM;
        ICERR_as_DemStatus[e_DemEvent].ui8_ErrorLevel  = 0;
      }
    }
    else
    {
      // Report non-existing DEMs
      (void)ICERR_HANDLE(IC_e_ERR_ILLEGAL_ENUM_VALUE, e_DemEvent);
    }
    /*#]*/
}

/*## operation ICERR_v_DemPassedWeak(const IC_E_DEM) */
void ICERR_v_DemPassedWeak(const IC_E_DEM e_DemEvent) {
    /*#[ operation ICERR_v_DemPassedWeak(const IC_E_DEM) */
    ICERR_S_DemStatus * ps_DemStat;
    
    if (e_DemEvent < IC_e_DEM__NUM_ENTRIES__)
    {
      ps_DemStat = &ICERR_as_DemStatus[e_DemEvent];
      if (ps_DemStat->ui8_ErrorLevel > 0)
      {
        ps_DemStat->ui8_ErrorLevel--;
      }
      else
      {
        ICERR_v_DemPassed(e_DemEvent);
      }
    }
    else
    {
      // Report non-existing DEMs
      (void)ICERR_HANDLE(IC_e_ERR_ILLEGAL_ENUM_VALUE, e_DemEvent);
    }
    /*#]*/
}

/*## operation ICERR_v_DemFlush() */
void ICERR_v_DemFlush(void) {
    /*#[ operation ICERR_v_DemFlush() */
    IC_E_DEM e_DemEvent;
    IC_E_ERROR e_Ret = IC_e_ERR_OK;
    ICERR_S_DemStatus *ps_DemStat;
    uint32 ui32_Index = 0;
    
    // Evaluate, debounce and update DTC status
    ICERR_v_DtcEvaluation();
    
    // Loop through DEM-List and report every failed/passed error
    for (ui32_Index = 0; ui32_Index < IC_e_DEM__NUM_ENTRIES__; ui32_Index++)
    {
      e_DemEvent = (IC_E_DEM)ui32_Index; // PRQA S 1482
      ps_DemStat = &ICERR_as_DemStatus[ui32_Index];
    
      // Check status and report
      if (ps_DemStat->e_Status == IC_e_DEMSTATUS_FAILED)
      {
        // Report DEM error status
        e_Ret = ICOSW_e_DemReport(e_DemEvent, ps_DemStat->e_Status, &(ps_DemStat->uN_OptData));
    
        // Reset DEM-Status if reporting was OK and the DEM is not marked as permanently failed
        if ( (IC_e_ERR_OK == e_Ret)
          && ((ps_DemStat->ui8_Flags & ICERR_cui8_STATFLAG_FAILED_PERM) == 0))
        {
          ps_DemStat->e_Status             = IC_e_DEMSTATUS_NOT_TESTED;
          ps_DemStat->e_LastReportedStatus = IC_e_DEMSTATUS_FAILED;
          ps_DemStat->ui8_CurrentPrio      = 0;
          ps_DemStat->ui8_ErrorLevel       = ICERR_cui8_DEMFAILED_ERROR_LEVEL;
        }
      }
      else if ((IC_e_DEMSTATUS_PASSED == ps_DemStat->e_Status)
            && (IC_e_DEMSTATUS_PASSED != ps_DemStat->e_LastReportedStatus))
      {
        // To save runtime, we only report Passed DEMs if previous status was not passed.
        // This saves ~100us/Frame. Nevertheless one DEM per cycle is always reported, which
        // is done below the loop.
        (void)ICOSW_e_DemReport(e_DemEvent, IC_e_DEMSTATUS_PASSED, NULL);
        ps_DemStat->e_Status = IC_e_DEMSTATUS_NOT_TESTED;
        ps_DemStat->e_LastReportedStatus = IC_e_DEMSTATUS_PASSED;
      }
      else
      {
        // DEM not tested: Do nothing
      }
    }
    
    // To achieve a cyclic report of all passed DEMs every ~1 second, we report one of them here
    // if it is marked as passed.
    //
    // Index wraparound is handled below, so suppress 3692
    ps_DemStat = &ICERR_as_DemStatus[ICERR_ui16_NextCycSlowPassedRepDemIdx]; // PRQA S 3692
    if (IC_e_DEMSTATUS_PASSED == ps_DemStat->e_Status)
    {
      e_DemEvent = (IC_E_DEM)ICERR_ui16_NextCycSlowPassedRepDemIdx; // PRQA S 1482
      e_Ret = ICOSW_e_DemReport(e_DemEvent, IC_e_DEMSTATUS_PASSED, NULL);
      if (IC_e_ERR_OK == e_Ret)
      {
        ps_DemStat->e_Status = IC_e_DEMSTATUS_NOT_TESTED;
        ps_DemStat->e_LastReportedStatus = IC_e_DEMSTATUS_PASSED;
      }
    }
    
    // Goto next entry and handle wraparound
    ICERR_ui16_NextCycSlowPassedRepDemIdx++;
    if (ICERR_ui16_NextCycSlowPassedRepDemIdx >= IC_e_DEM__NUM_ENTRIES__)
    {
      ICERR_ui16_NextCycSlowPassedRepDemIdx = 0;
    }
    /*#]*/
}

/*## operation ICERR_v_DtcEvaluation() */
static void ICERR_v_DtcEvaluation(void) {
    /*#[ operation ICERR_v_DtcEvaluation() */
    ICERR_S_DtcMapEntry const *ps_DtcEntry;
    ICERR_S_DemStatus         *ps_DemStat;
    ICERR_S_DemStatus         *ps_DtcStat;
    sint16                     si16_NewValue;
    uint32                     ui32_Index;
    
    // For all DEM/DTC-Map entries ...
    for (ui32_Index = 0; ui32_Index < IC_ARRLEN(ICERR_cas_DtcMap); ui32_Index++)
    {
      ps_DtcEntry = &ICERR_cas_DtcMap[ui32_Index];
    
      // Check enum values
      if ((ps_DtcEntry->e_SourceDem >= IC_e_DEM__NUM_ENTRIES__)
       || (ps_DtcEntry->e_DestDtc   >= IC_e_DEM__NUM_ENTRIES__))
      {
        (void)ICERR_HANDLE(IC_e_ERR_SOURCECODE_ERROR, 0);
      }
      else
      {
        // Get status data for current entry (QAC is wrong with array index beyond size)
        ps_DemStat  = &ICERR_as_DemStatus[ps_DtcEntry->e_SourceDem]; // PRQA S 3692
        ps_DtcStat  = &ICERR_as_DemStatus[ps_DtcEntry->e_DestDtc];   // PRQA S 3692
    
        // Update debounce counter value
        if (IC_e_DEMSTATUS_FAILED == ps_DemStat->e_Status)
        {
          si16_NewValue = (sint16)ps_DemStat->ui8_DtcDebounceCtr + (sint16)ps_DtcEntry->ui8_DebounceIncrValue;
          ps_DemStat->ui8_DtcDebounceCtr = (uint8)MIN(si16_NewValue, (sint16)TYPEMAX_UI8);
        }
        else if (IC_e_DEMSTATUS_PASSED == ps_DemStat->e_Status)
        {
          si16_NewValue = (sint16)ps_DemStat->ui8_DtcDebounceCtr - (sint16)ps_DtcEntry->ui8_DebounceDecrValue;
          ps_DemStat->ui8_DtcDebounceCtr = (uint8)MAX(si16_NewValue, 0);
        }
        else
        {
          // Source DEM not tested: Do nothing
        }
    
        // Update DTC status
        if (ps_DtcStat->e_Status == IC_e_DEMSTATUS_FAILED)
        {
          // Do nothing if DTC is already set to FAILED.
          // NOTE: It will be reset to NOT_TESTED in ICERR_v_DemFlush()
        }
        else if (ps_DemStat->ui8_DtcDebounceCtr >= ps_DtcEntry->ui8_DebounceTriggerThres)
        {
          // If debounce counter of source DEM is above threshold, set DTC to failed!
          ps_DtcStat->e_Status                            = IC_e_DEMSTATUS_FAILED;
          ps_DtcStat->uN_OptData.s_DtcExt.e_IcDemId       = ps_DtcEntry->e_SourceDem;
          ps_DtcStat->uN_OptData.s_DtcExt.ui16_DemEventId = 0; /* Will be filled by adapter */
          ps_DtcStat->uN_OptData.s_DtcExt.ui8_Reserved    = 0;
        }
        else if (ps_DemStat->ui8_DtcDebounceCtr == 0)
        {
          ps_DtcStat->e_Status = IC_e_DEMSTATUS_PASSED;
        }
        else
        {
          // Do not change DTC status
        }
      }
    }
    /*#]*/
}

/*## operation ICERR_v_StartNewCycle(uint16) */
void ICERR_v_StartNewCycle(uint16 ui16_FrameNum) {
    /*#[ operation ICERR_v_StartNewCycle(uint16) */
    const uint16 cui16_WrapAroundMaxValue = 2; /* Used to prevent framecnt-jumps as beeing detected as wraparounds */
    
    // Shift anti-flood buffers. They have only a few bytes, so just copy them
    // instead of using pointer stuff:
    (void)memcpy(ICERR_bf_FailedErrsLastCycle, ICERR_bf_FailedErrsThisCycle, (size_t)sizeof(ICERR_bf_FailedErrsLastCycle));
    (void)memset(ICERR_bf_FailedErrsThisCycle, 0, (size_t)sizeof(ICERR_bf_FailedErrsThisCycle));
    
    // Handle special DEM framecounter. That counter has to saturate at max value, so
    // use simple wraparound detection with protection against illegal frame-counter
    // jumps.
    if ( (ui16_FrameNum < ICERR_ui16_FrameNum)
      && (ui16_FrameNum < cui16_WrapAroundMaxValue)
       )
    {
      ICERR_ui16_FrameNumSaturated = TYPEMAX_UI16;
    }
    else
    {
      if (TYPEMAX_UI16 != ICERR_ui16_FrameNumSaturated)
      {
        ICERR_ui16_FrameNumSaturated = ui16_FrameNum;
      }
    }
    
    // Goto next cycle
    ICERR_ui16_FrameNum = ui16_FrameNum;
    ICERR_ui32_CycleCnt++;
    /*#]*/
}

/*## operation ICERR_e_CheckErrorDefinitions() */
#pragma push
#pragma optimize_for_size on
static IC_E_ERROR ICERR_e_CheckErrorDefinitions(void) {
    /*#[ operation ICERR_e_CheckErrorDefinitions() */
    IC_E_ERROR e_Ret         = IC_e_ERR_OK;
    uint32 ui32_LastIndex    = 0;
    uint32 ui32_BitPosition  = 0;
    uint32 ui32_BitfieldSize = 0;
    uint32 ui32_LastValue    = 0;
    const uint32 cui32_BITS_PER_UNIT = 32;
    
    // Do nullpointer checks
    if (ICERR_ps_MeasData == NULL)
    {
      e_Ret = ICERR_HANDLE(IC_e_ERR_NULLPOINTER, 0);
    }
    else
    {
      // Check if the structure provided to MTS for mapping of IC_E_ERROR enum values to strings
      // is consistent with the IC_E_ERROR definition by comparing their sizes. As the struct
      // ErrorCodeNames is a bitfield, sizeof() does not work. So we have to find it's number
      // of entries by marking last bit and find it's position.
      //
      // QAC is wrong with nullpointer warning
      //   PRQA S 0506 1
      (void)memset(&(ICERR_ps_MeasData->ErrorCodeNames), 0, (size_t)sizeof(ICERR_ps_MeasData->ErrorCodeNames));
      ICERR_ps_MeasData->ErrorCodeNames.IC_e_ERR__NUM_ENTRIES__ = 1;
      ui32_LastIndex = ((uint32)sizeof(ICERR_ps_MeasData->ErrorCodeNames) / (uint32)sizeof(uint32)) - 1;
      ui32_LastValue = *((uint32*)&(ICERR_ps_MeasData->ErrorCodeNames) + ui32_LastIndex); // PRQA S 0310,0488
    
      // Find our marked bit in the last bitfield's byte
      for (ui32_BitPosition = 0; ui32_BitPosition < cui32_BITS_PER_UNIT; ui32_BitPosition++)
      {
        if (ui32_LastValue == (1u << ui32_BitPosition))
        {
          if (IC_b_IsBigEndian() == b_TRUE)
          {
            ui32_BitfieldSize = (ui32_LastIndex * cui32_BITS_PER_UNIT) + (cui32_BITS_PER_UNIT - ui32_BitPosition - 1);
          }
          else
          {
            ui32_BitfieldSize = (ui32_LastIndex * cui32_BITS_PER_UNIT) + ui32_BitPosition;
          }
        }
      }
    
      // Compare sizes
      if (ui32_BitfieldSize != IC_e_ERR__NUM_ENTRIES__)
      {
        e_Ret = ICERR_HANDLE(IC_e_ERR_SOURCECODE_ERROR, (ui32_BitfieldSize << 16) | (IC_e_ERR__NUM_ENTRIES__)); // PRQA S 3120
      }
    }
    return e_Ret;
    /*#]*/
}
#pragma pop

/*## operation ICERR_e_CreateDemMapping() */
#pragma push
#pragma optimize_for_size on
static IC_E_ERROR ICERR_e_CreateDemMapping(void) {
    /*#[ operation ICERR_e_CreateDemMapping() */
    const uint8 cui8_NOT_MAPPED = 0xFF;
    uint32      ui32_Index      = 0u;
    IC_E_ERROR  e_Ret           = IC_e_ERR_OK;
    IC_E_ERROR  e_MappedErr     = IC_e_ERR_OK;
    
    // Create mapping from IC error code to DEMs
    (void)memset(&ICERR_aui8_DemMappingLut, cui8_NOT_MAPPED, (size_t)sizeof(ICERR_aui8_DemMappingLut));
    for (ui32_Index = 0; ui32_Index < IC_ARRLEN(ICERR_cas_DemMapping); ui32_Index++)
    {
      e_MappedErr = ICERR_cas_DemMapping[ui32_Index].e_Err;
      if ((uint8)e_MappedErr < IC_ARRLEN(ICERR_aui8_DemMappingLut))
      {
        ICERR_aui8_DemMappingLut[(uint8)e_MappedErr] = (uint8)ui32_Index;
      }
      else
      {
        e_Ret = ICERR_HANDLE(IC_e_ERR_SOURCECODE_ERROR, ui32_Index);
      }
    }
    
    // Check if all errors are mapped
    for (ui32_Index = 0; ui32_Index < IC_ARRLEN(ICERR_aui8_DemMappingLut); ui32_Index++)
    {
      if (cui8_NOT_MAPPED == ICERR_aui8_DemMappingLut[ui32_Index])
      {
        e_Ret = ICERR_HANDLE(IC_e_ERR_SOURCECODE_ERROR, ui32_Index);
      }
    }
    
    return e_Ret;
    /*#]*/
}
#pragma pop

/*## operation ICERR_v_SetContextTemperature(const float32) */
void ICERR_v_SetContextTemperature(const float32 f32_Temperature) {
    /*#[ operation ICERR_v_SetContextTemperature(const float32) */
    sint32 si32_Temp = 0;
    
    // Convert temperature to signed 8-bit, saturated
    si32_Temp = (sint32)(f32_Temperature + 0.5f);
    if (si32_Temp < TYPEMIN_SI8)
    {
      ICERR_si8_Temperature = TYPEMIN_SI8;
    }
    else if (si32_Temp > TYPEMAX_SI8)
    {
      ICERR_si8_Temperature = TYPEMAX_SI8;
    }
    else
    {
      ICERR_si8_Temperature = f32_Temperature;
    }
    /*#]*/
}

/*## operation ICERR_v_SetContextState(const IC_S_DemExtDataIcState) */
void ICERR_v_SetContextState(const IC_S_DemExtDataIcState s_IcState) {
    /*#[ operation ICERR_v_SetContextState(const IC_S_DemExtDataIcState) */
    ICERR_s_IcState = s_IcState;
    /*#]*/
}

/*## operation ICERR_v_SetSimLogErrCallback(ICERR_Fct_SimLogErr) */
#if (IC_COMPILE_FOR_MTS == 1)
void ICERR_v_SetSimLogErrCallback(ICERR_Fct_SimLogErr pfct_LogFunc) {
    /*#[ operation ICERR_v_SetSimLogErrCallback(ICERR_Fct_SimLogErr) */
    ICERR_pfct_SimLogErr = pfct_LogFunc;
    /*#]*/
}
#endif


/*#[ ignore */

#ifdef __cplusplus
}
#endif

/*#]*/


/*********************************************************************
	File Path: ..\..\..\04_Engineering\01_Source_Code\Algo\ic\ic_errmanager.c
*********************************************************************/
