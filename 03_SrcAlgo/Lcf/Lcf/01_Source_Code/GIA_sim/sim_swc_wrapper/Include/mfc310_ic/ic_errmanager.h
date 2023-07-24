//* **********************************************************************
//  COMPANY:         $CompanyInfo: CONFIDENTIAL AND PROPRIETARY PROPERTY OF CONTINENTAL AG , A.D.C. GmbH  -  ALL RIGHTS RESERVED $
//  
//  PROJECT:         MFC30x_MCU
//  CPU:             MPC5675K
//  
//  PACKAGE:         $Source: ic_errmanager.h $ $Revision: 1.1 $
//  MKS Date:        $Date: 2021/12/13 17:25:51CET $
//  
//  RHAPSODY:        7.5.3
//  COMPONENT:       IC
//  CONFIGURATION:   DefaultConfig
//  MODEL ELEMENT:   ic_errmanager
//  MODULNAME:       ..\..\..\04_Engineering\01_Source_Code\Algo\ic\ic_errmanager.h
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

#ifndef ic_errmanager_H
#define ic_errmanager_H

/*## dependency ic_errcodes */
#include "ic_errcodes.h"
/*## dependency ic_types */
#include "ic_types.h"
/*## package Ic_Pkg */

/*## class TopLevel::ic_errmanager */
/*#[ ignore */
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
/*#]*/


/*#[ ignore */

#ifdef __cplusplus
extern "C"
{
#endif

/*#]*/


//  This 'type' is actually an attribute (Rhapsody workaround).
//  It defines the maximum length of the module name character string, which is used to fill the error list for MTS
/*#[ type ICERR_cui16_ModuleNameLength */
#define ICERR_cui16_ModuleNameLength 5
/*#]*/

//  Structure for counting occurrance of most interresting error. This is only used for
//  recording analysis.
/*## type ICERR_S_ErrorCounters */
typedef struct ICERR_S_ErrorCounters {
    //  Counts total number of errors detected
    uint32 ui32_TotalErrCnt;		/*## attribute ui32_TotalErrCnt */
    //  Counter which increments when permanent errors are not written to the MTS error list due to
    //  antiflood protection.
    uint16 ui16_ErrCntAntiFlood;		/*## attribute ui16_ErrCntAntiFlood */
    //  Counter which increments when the FrameNumber jumps unexpected.
    uint16 ui16_ErrCntFrameNumIncr;		/*## attribute ui16_ErrCntFrameNumIncr */
    //  Counter which increments when the FrameNumber in the embedded register data does not
    //  match the FrameNumber in the embedded statistics data.
    uint16 ui16_ErrCntFrameNumRegStatMatch;		/*## attribute ui16_ErrCntFrameNumRegStatMatch */
    //  Counter which increments when an unexpected FrameId has been detected.
    uint16 ui16_ErrCntFrameId;		/*## attribute ui16_ErrCntFrameId */
    //  Counter which increments when the register check fails for the right imager.
    uint16 ui16_ErrCntImagerRegCompareR;		/*## attribute ui16_ErrCntImagerRegCompareR */
    //  Counter which increments when the register check fails for the left imager.
    uint16 ui16_ErrCntImagerRegCompareL;		/*## attribute ui16_ErrCntImagerRegCompareL */
    //  Counter which increments when the embedded register data is corrupted
    uint16 ui16_ErrCntWrongEmbeddedRegDat;		/*## attribute ui16_ErrCntWrongEmbeddedRegDat */
    //  Counter which increments when the embedded statistics data is corrupted
    uint16 ui16_ErrCntWrongEmbeddedStatDat;		/*## attribute ui16_ErrCntWrongEmbeddedStatDat */
    //  Counter which increments when a DEM is reported as failed.
    uint16 ui16_ErrCntDemErrCount;		/*## attribute ui16_ErrCntDemErrCount */
    //  Counter which increments when the software returned an error during an external measfreeze call.
    uint16 ui16_ErrCntMeasfreeze;		/*## attribute ui16_ErrCntMeasfreeze */
    //  Counter which increments when the histogram has an unexpected number of values.
    uint16 ui16_ErrCntHistogramPixelCount;		/*## attribute ui16_ErrCntHistogramPixelCount */
    //  Counter which increments when the last IC-ROI values mismatches the corresponding register values.
    uint16 ui16_ErrCntICRoiRegisterMismatch;		/*## attribute ui16_ErrCntICRoiRegisterMismatch */
} ICERR_S_ErrorCounters;

/*## type ICERR_S_ErrorEntry */
typedef struct ICERR_S_ErrorEntry {
    //  Description:   Timestamp of the point in time at which the error has been reported
    //  Range:         0-0xFFFFFFFFFFFFFFFF
    //  Resolution:    1
    //  Unit:          us
    uint64 ui64_Timestamp;		/*## attribute ui64_Timestamp */
    //  Description:   Error number/counter value
    //  Range:         0-65535
    //  Resolution:    1
    //  Unit:          none
    uint16 ui16_ErrNum;		/*## attribute ui16_ErrNum */
    //  Description:   Frame number when the error occurred
    //  Range:         0-65535
    //  Resolution:    1
    //  Unit:          frames
    uint16 ui16_FrameNum;		/*## attribute ui16_FrameNum */
    //  Description:   Arbitrary 32-Bit value which provides optional context information for this error
    //  Range:         sint32
    //  Resolution:    1
    //  Unit:          (depends on usage)
    sint32 si32_Hint;		/*## attribute si32_Hint */
    //  Description:   Line number of the source-file where the error ocurred
    //  Range:         0-65535
    //  Resolution:    1
    //  Unit:          lines
    uint16 ui16_LineNum;		/*## attribute ui16_LineNum */
    //  Description:   Name of the module which reported the error
    //  Range:         none
    //  Resolution:    none
    //  Unit:          none
    //  
    //  String only used for MTS/debugging, so suppress QAC message:
    //    PRQA S 5013,3625 1
    char ach_ModuleName[ICERR_cui16_ModuleNameLength];		/*## attribute ach_ModuleName */
    //  Description:   Error code of this error
    //  Range:         (enum)
    //  Resolution:    none
    //  Unit:          none
    IC_E_ERROR e_ErrCode;		/*## attribute e_ErrCode */
} ICERR_S_ErrorEntry;

//  Measfreeze data from the error manager. This structure can be interpreted by the
//  IC-Observer MTS MO DLL and used to provide data to the MTS SystemHealthLog Engine.
/*## type ICERR_S_MeasData */
typedef struct ICERR_S_MeasData {
    //  Structure for counting occurrance of most interresting errors
    ICERR_S_ErrorCounters s_ErrorCounters;		/*## attribute s_ErrorCounters */
    //  Ringbuffer which stores the last <ICCFG_cui32_ERRORLIST_SIZE> reported errors
    ICERR_S_ErrorEntry as_ErrorList[ICCFG_cui32_ERRORLIST_SIZE];		/*## attribute as_ErrorList */
    //  This struct does not contain any data, but the field definitions provides MTS MOs
    //  a mapping from Error-Codes to strings via SDL/CDL file, which is generated from this
    //  struct.
    ICERR_S_ErrCodeNamesForMTS ErrorCodeNames;		/*## attribute ErrorCodeNames */
} ICERR_S_MeasData;

//  Struct for mapping internal IC error codes (IC_E_ERROR) to DEMs.
/*## type ICERR_S_DemMapEntry */
typedef struct ICERR_S_DemMapEntry {
    //  Description:   Source error code, which is mapped to the DEM
    //  Range:         (enum)
    //  Resolution:    none
    //  Unit:          none
    IC_E_ERROR e_Err;		/*## attribute e_Err */
    //  Description:   Destination DEM event for this mapping
    //  Range:         (enum)
    //  Resolution:    none
    //  Unit:          none
    IC_E_DEM e_Dem;		/*## attribute e_Dem */
    //  Description:   Priority level of this mapping/error code. The priority level is evaluated when reporting
    //                 errors via ICERR_e_HandleErr(). In case the DEM is already set to FAILED by another error,
    //                 the priority level decides whether to overwrite the context data of the DEM or not. This
    //                 may be useful to prevent consecutive errors from overwriting context data provided by the
    //                 initial error.
    //                 NOTE: Higher number means higher priority.
    //  Range:         0-255
    //  Resolution:    none
    //  Unit:          none
    uint8 ui8_Priority;		/*## attribute ui8_Priority */
    //  Description:   Additional flags for this mapping
    //  Range:         See attributes with prefix 'ICERR_cui8_MAPFLAG_*'
    //  Resolution:    none
    //  Unit:          none
    uint8 ui8_Flags;		/*## attribute ui8_Flags */
} ICERR_S_DemMapEntry;

//  Maps a DEM to a DTC and allows to specify values for debouncing
/*## type ICERR_S_DtcMapEntry */
typedef struct ICERR_S_DtcMapEntry {
    //  Source DEM, which is mapped to the DTC
    IC_E_DEM e_SourceDem;		/*## attribute e_SourceDem */
    //  Destination DTC (actually same datatype as DEM)
    IC_E_DEM e_DestDtc;		/*## attribute e_DestDtc */
    //  Description:   The debounce counter is incremented by this value if the source DEM event is 'FAILED'
    //  Range:         0-255
    //  Resolution:    1
    //  Unit:          none
    uint8 ui8_DebounceIncrValue;		/*## attribute ui8_DebounceIncrValue */
    //  Description:   The debounce counter is decremented by this value if the source DEM event is 'PASSED'
    //  Range:         0-255
    //  Resolution:    1
    //  Unit:          none
    uint8 ui8_DebounceDecrValue;		/*## attribute ui8_DebounceDecrValue */
    //  Description:   Upper threshold for the DEM debounce counter, at which the mapped DTC will be set to 'FAILED'
    //  Range:         0-255
    //  Resolution:    1
    //  Unit:          none
    uint8 ui8_DebounceTriggerThres;		/*## attribute ui8_DebounceTriggerThres */
} ICERR_S_DtcMapEntry;

//  Stores current status of a DEM event. As DTCs are handled in the same way as DEMs are,
//  this structure also stores status of DTCs.
/*## type ICERR_S_DemStatus */
typedef struct ICERR_S_DemStatus {
    //  Description:   Optional context information data which has been collected for this specific error.
    //                 This is stored to NvM. As DTCs cannot store as much optional data as DEMs do, we
    //                 have a union here with separate structures for both.
    //  Range:         none
    //  Resolution:    none
    //  Unit:          none
    IC_Un_DemDtcExtData uN_OptData;		/*## attribute uN_OptData */
    //  Description:   Current priority level of this status. See ICERR_e_HandleErr() for details about priority levels.
    //  Range:         0-255
    //  Resolution:    1
    //  Unit:          none
    uint8 ui8_CurrentPrio;		/*## attribute ui8_CurrentPrio */
    //  Description:   Current value of the DEM->DTC debouncing counter
    //  Range:         0-255
    //  Resolution:    1
    //  Unit:          none
    uint8 ui8_DtcDebounceCtr;		/*## attribute ui8_DtcDebounceCtr */
    //  Description:   Current error level of this DEM. This is used in conjunction with reporting DEMs as 'WEAK'
    //                 passed (see ICERR_v_DemPassedWeak)
    //  Range:         0-255
    //  Resolution:    1
    //  Unit:          none
    uint8 ui8_ErrorLevel;		/*## attribute ui8_ErrorLevel */
    //  Description:   Additional flags for the current DEM status
    //  Range:         Logical OR of all attributes with prefix 'ICERR_cui8_STATFLAG_*'
    //  Resolution:    1
    //  Unit:          none
    uint8 ui8_Flags;		/*## attribute ui8_Flags */
    //  Description:   Current DEM event status
    //  Range:         (enum)
    //  Resolution:    none
    //  Unit:          none
    IC_E_DEMSTATUS e_Status;		/*## attribute e_Status */
    //  Description:   Last DEM event status, which has been reported to the frame software/adapter
    //  Range:         (enum)
    //  Resolution:    none
    //  Unit:          none
    IC_E_DEMSTATUS e_LastReportedStatus;		/*## attribute e_LastReportedStatus */
} ICERR_S_DemStatus;

#if (IC_COMPILE_FOR_MTS == 1)
/*#[ type ICERR_Fct_SimLogErr */
typedef void (* ICERR_Fct_SimLogErr)(const ICERR_S_ErrorEntry *ps_ErrEntry);
/*#]*/
#endif

/***    User explicit entries    ***/


/* Operations */

//*****************************************************************************
//  Functionname:  ICERR_DEFINE_MODULE
//  
//  Macro for defining a character array holding the name of a module, which is used
//  for reporting errors to the error list. That name can be seen on MTS when errors
//  are reported from that module.
//  
//  This has to be used at least once for each module. Example:
//  
//  ICERR_DEFINE_MODULE("MYMOD")
//  
//  Parameter:     const RhpString module_name   <In>
//  
//    
//  
//  return         RhpString
//**************************************************************************** */
/*## operation ICERR_DEFINE_MODULE(RhpString) const */
#define ICERR_DEFINE_MODULE(module_name)    \
    static const char * const pch_ModuleName = (module_name); // PRQA S 5013,3625,3412,3429

//*****************************************************************************
//  Functionname:  ICERR_HANDLE
//  
//  Public macro for reporting errors to the Error Manager, which is a wrapper to ICERR_e_HandleErr().
//  It can be used from any IC submodule and automatically inserts the current source code line to the
//  argument list.
//  
//  See ICERR_e_HandleErr() for details.
//  
//  Parameter:     const RhpString e_ICErrcode   <In>
//  
//  
//  Parameter:     const RhpString si32_Hint   <In>
//  
//    
//  
//  return         RhpString
//**************************************************************************** */
/*## operation ICERR_HANDLE(RhpString,RhpString) const */
#define ICERR_HANDLE(e_ICErrcode, si32_Hint)    \
    ICERR_e_HandleErr(pch_ModuleName, __LINE__, e_ICErrcode, (sint32)(si32_Hint)) // PRQA S 3429,3453 

//*****************************************************************************
//  Functionname:  ICERR_e_HandleErr
//  
//  This is the global error handler function, which is wrapped by macro ICERR_HANDLE(). It can be
//  called by any IC submodule and does the following steps:
//  
//  Error filtering:
//  - Some errors can be filtered here depending on current IC state or error criticality.
//    At the moment only IC_e_ERR_MEASFREEZE is filtered and set to IC_e_ERR_OK, as it
//    does not have any affect to the ECU software/algos.
//  
//  Error counting:
//  - Some errors have dedicated counters, which are part of the measfreeze data. See structure
//    declaration ICERR_S_ErrorCounters.
//  
//  Error mapping to DEMs:
//  - Each error can be mapped to a DEM, so when the error is raised, the associated DEM event
//    status is set to failed. Additionally the DEM is fed with the data provided to this function:
//      * e_ErrCode
//      * ui16_LineNum
//      * si32_Hint
//  - In case a DEM is already set to failed, the priority specified in the IC_E_ERROR->DEM mapping
//    of the currently reported error defines the replacement strategy. If the current error has a
//    higher priority than the previous error, the DEM context/optional data will be overwritten.
//  
//  Error reporting to MTS:
//  - Errors are collected in an internal ringbuffer array, which is part of the measfreeze data.
//    This includes name of failed module, timestamp, framenumber, error counter and optional data
//    passed to this function.
//  - There is a 'antiflood' protection, which prevents errors from being continously inserted into
//    the error list in case they are failing each cycle. This does _NOT_ affect reporting of DEMs.
//  
//  Function returns the input e_ErrCode in case the error has not been filtered. Filtered errors
//  result in IC_e_ERR_OK.
//  
//  Parameter:     const char * pch_ModuleNameStr   <In>
//  Name of the module which detected the error (max length is ICERR_cui16_ModuleNameLength)
//  
//  Parameter:     uint16 ui16_LineNum   <In>
//  Line number in source-code file where the error has been detected
//  
//  Parameter:     IC_E_ERROR e_ErrCode   <In>
//  Error which has been detected
//  
//  Parameter:     sint32 si32_Hint   <In>
//  Arbitrary optional 32-Bit value, which is stored to the error list and to DEM extended data
//    
//  
//  return         IC_E_ERROR
//**************************************************************************** */
/*## operation ICERR_e_HandleErr(const char *,uint16,IC_E_ERROR,sint32) */

/*#[ ignore */
// Suppress QAC Messages:
// - 5013: Use of basic type 'char'.
// - 3625: Type 'char' has been used in the declaration of an object or a function.
//         => Strings are only copied to measfreeze struct for MTS and never evaluated in the software
//        
// PRQA S 5013,3625 3
/*#]*/
IC_E_ERROR ICERR_e_HandleErr(const char * pch_ModuleNameStr, uint16 ui16_LineNum, IC_E_ERROR e_ErrCode, sint32 si32_Hint);

//*****************************************************************************
//  Functionname:  ICERR_e_Init
//  
//  Initializes the IC Error Manager. The following steps are done:
//  
//  - Initialize module variables
//  - Create and verify DEM-Mapping by calling ICERR_e_CreateDemMapping()
//  - Check error definitions by calling ICERR_e_CheckErrorDefinitions()
//  - Set all DEMs to NOT_TESTED
//  
//  NOTE: ICERR_as_DemStatus is _NOT_ cleared, as DTC debouncing would not work accross
//  ignition cycles (each ignition cycle will result in a call to ICERR_e_Init()).
//  
//  Parameter:     ICERR_S_MeasData* ps_MeasStruct   <InOut>
//  Struct which is used to provide measfreeze data
//  
//  Parameter:     uint32 ui32_EnableHILMode   <In>
//  Setting this value to 'IC_cui32_KEY_HILMODE' enables HIL mode and suppresses some errors
//  which are known to appear on HIL as there is no real closed control loop to the imager.
//    
//  
//  return         IC_E_ERROR
//**************************************************************************** */
/*## operation ICERR_e_Init(ICERR_S_MeasData,uint32) */
IC_E_ERROR ICERR_e_Init(ICERR_S_MeasData* ps_MeasStruct, uint32 ui32_EnableHILMode);

//*****************************************************************************
//  Functionname:  ICERR_v_DemFailedExt
//  
//  Function for explicit reporting a DEM Event Id as failed. The new event status is actually
//  kept in a buffer until it's flushed by calling ICERR_v_DemFlush().
//  
//  In case the DEM is already set to failed since last flush, the status (and thus the optional data)
//  is only updated in case the current status priority level is lower than ICERR_cui8_PRIO_EXPLICIT_DEM.
//  
//  Parameter:     IC_E_DEM e_DemEvent   <In>
//  DEM which failed
//  
//  Parameter:     uint32 ui32_OptData   <In>
//  Arbitrary optional data which is stored to NvM (pre-ext data)
//  
//  Parameter:     uint16 ui16_LineNum   <In>
//  Line number of the source-code file where the error has been detected
//    
//  
//  return         void
//**************************************************************************** */
/*## operation ICERR_v_DemFailedExt(IC_E_DEM,uint32,uint16) */
void ICERR_v_DemFailedExt(IC_E_DEM e_DemEvent, uint32 ui32_OptData, uint16 ui16_LineNum);

//*****************************************************************************
//  Functionname:  ICERR_v_DemFailedExtKeep
//  
//  Function for explicit reporting a DEM Event Id as failed. The new event status is actually
//  kept in a buffer until it's flushed by calling ICERR_v_DemFlush().
//  
//  In case the DEM is already set to failed since last flush, the status and DEM optional data
//  is _not_ overwritten. This can be useful if a DEM is implicitly reported by calling
//  ICERR_e_HandleErr(), which will usualy assign a lower priority than explicit call of
//  ICERR_v_DemFailedExt(). In contrast to that function, this function will not overwrite
//  the optional data which has been provided by ICERR_e_HandleErr().
//  
//  Parameter:     IC_E_DEM e_DemEvent   <In>
//  
//  
//  Parameter:     uint32 ui32_OptData   <In>
//  
//  
//  Parameter:     uint16 ui16_LineNum   <In>
//  
//    
//  
//  return         void
//**************************************************************************** */
/*## operation ICERR_v_DemFailedExtKeep(IC_E_DEM,uint32,uint16) */
void ICERR_v_DemFailedExtKeep(IC_E_DEM e_DemEvent, uint32 ui32_OptData, uint16 ui16_LineNum);

//*****************************************************************************
//  Functionname:  ICERR_v_DemFailed
//  
//  Wrapper macro for ICERR_v_DemFailedExt() which adds the current source code line number
//  to the argument list. See DemFailedExt() for details.
//  
//  Parameter:     const RhpString e_Dem   <In>
//  Failed DEM event
//  
//  Parameter:     const RhpString ui32_OptData   <In>
//  Optional data which is stored to NvM
//    
//  
//  return         RhpString
//**************************************************************************** */
/*## operation ICERR_v_DemFailed(RhpString,RhpString) const */
#define ICERR_v_DemFailed(e_Dem, ui32_OptData)    \
    ICERR_v_DemFailedExt(e_Dem, ui32_OptData, __LINE__) // PRQA S 3429,3453

//*****************************************************************************
//  Functionname:  ICERR_v_DemFailedKeep
//  
//  Wrapper macro for ICERR_v_DemFailedExtKeep() which adds the current source code line number
//  to the argument list. See ICERR_v_DemFailedExtKeep() for details.
//  
//  Parameter:     const RhpString e_Dem   <In>
//  
//  
//  Parameter:     const RhpString ui32_OptData   <In>
//  
//    
//  
//  return         RhpString
//**************************************************************************** */
/*## operation ICERR_v_DemFailedKeep(RhpString,RhpString) const */
#define ICERR_v_DemFailedKeep(e_Dem, ui32_OptData)    \
    ICERR_v_DemFailedExtKeep(e_Dem, ui32_OptData, __LINE__)  // PRQA S 3429,3453

//*****************************************************************************
//  Functionname:  ICERR_v_DemPassed
//  
//  Sets the status of a DEM to passed, but *only* in case the DEM is not already set to failed.
//  The status is sent to the frame software later by calling ICERR_v_DemFlush(). See there
//  for details.
//  
//  Parameter:     const IC_E_DEM e_DemEvent   <In>
//  Passed DEM event
//    
//  
//  return         void
//**************************************************************************** */
/*## operation ICERR_v_DemPassed(const IC_E_DEM) */
void ICERR_v_DemPassed(const IC_E_DEM e_DemEvent);

//*****************************************************************************
//  Functionname:  ICERR_v_DemPassedWeak
//  
//  Sets a DEM status to 'passed' if it did not fail in the last ICERR_cui8_DEMFAILED_ERROR_LEVEL
//  cycles - so this is a 'weak passed'.
//  
//  This can be used to report some common DEMs as passed, where an explicit call to ICERR_v_DemPassed()
//  may be incorrect or difficult to implement. This includes DEMs like 'IC_e_DEM_GENERAL_FATAL', which
//  catch all common fatal errors handled in ICERR_e_HandleErr(). It would not be nice to call PASSED in
//  each cycle, because it might lead to toggling PASS/FAIL if the error comes each second frame. This
//  can also be considered as some kind of simple debouncing.
//  
//  Parameter:     const IC_E_DEM e_DemEvent   <In>
//  Passed DEM event
//    
//  
//  return         void
//**************************************************************************** */
/*## operation ICERR_v_DemPassedWeak(const IC_E_DEM) */
void ICERR_v_DemPassedWeak(const IC_E_DEM e_DemEvent);

//*****************************************************************************
//  Functionname:  ICERR_v_DemFlush
//  
//  Flushes the current DEM status to the frame software / imager control adapter. There are some
//  special things to be aware of:
//  
//  All FAILED events are reported to the adapter by calling ICOSW_e_DemReport().
//  
//  All PASSED events are reported to the adapter, *if there last reported status was NOT passed*.
//  In case the DEM has already been reported as PASSED in the previous cycles, it is not reported
//  again every call of this function. Instead there is a round-robin handling of all passed DEMs,
//  so only one of those DEMs are reported each cycle. This saves a lot runtime as calls to external
//  DEM component are very expensive (take 8us / call on MPC5675K at time of writing).
//  
//  After a DEM has been reported to the adapter, it's status is reset to NOT_TESTED.
//  
//    
//  
//  return         void
//**************************************************************************** */
/*## operation ICERR_v_DemFlush() */
void ICERR_v_DemFlush(void);

//*****************************************************************************
//  Functionname:  ICERR_v_StartNewCycle
//  
//  Tells the Error Manager that a new cycle has been started. Updates some internal status variables.
//  
//  Parameter:     uint16 ui16_FrameNum   <In>
//  Framenumber of new started cycle
//    
//  
//  return         void
//**************************************************************************** */
/*## operation ICERR_v_StartNewCycle(uint16) */
void ICERR_v_StartNewCycle(uint16 ui16_FrameNum);

//*****************************************************************************
//  Functionname:  ICERR_DEMMAP_IGNORE
//  
//  Macro used for creating an element of ICERR_S_DemMapEntry which says to ignore the error
//  (destination DEM set to ICERR_ce_ERR_NOT_MAPPED).
//  
//  Parameter:     const RhpString ic_err   <In>
//  Error code which will be ignored (which is not mapped to a DEM)
//    
//  
//  return         RhpString
//**************************************************************************** */
/*## operation ICERR_DEMMAP_IGNORE(RhpString) const */
#define ICERR_DEMMAP_IGNORE(ic_err)    \
    { ic_err, ICERR_ce_ERR_NOT_MAPPED, 0, 0 }           // PRQA S 3429,3457

//*****************************************************************************
//  Functionname:  ICERR_DEMMAP
//  
//  Macro used for creating an element of ICERR_S_DemMapEntry without any special flags.
//  
//  Parameter:     const RhpString ic_err   <In>
//  
//  
//  Parameter:     const RhpString dem   <In>
//  
//  
//  Parameter:     const RhpString prio   <In>
//  
//    
//  
//  return         RhpString
//**************************************************************************** */
/*## operation ICERR_DEMMAP(RhpString,RhpString,RhpString) const */
#define ICERR_DEMMAP(ic_err, dem, prio)    \
    { ic_err, dem, prio, 0 }                            // PRQA S 3429,3457

//*****************************************************************************
//  Functionname:  ICERR_DEMMAP_ANTIFLOOD
//  
//  Macro used for creating an element of ICERR_S_DemMapEntry which flags the error as
//  ANTIFLOOD. Antiflood errors are not continously reported to the error list in case
//  they are failing each cycle. However this does NOT affect DEM status update.
//  
//  Parameter:     const RhpString ic_err   <In>
//  
//  
//  Parameter:     const RhpString dem   <In>
//  
//  
//  Parameter:     const RhpString prio   <In>
//  
//    
//  
//  return         RhpString
//**************************************************************************** */
/*## operation ICERR_DEMMAP_ANTIFLOOD(RhpString,RhpString,RhpString) const */
#define ICERR_DEMMAP_ANTIFLOOD(ic_err, dem, prio)    \
    { ic_err, dem, prio, ICERR_cui8_MAPFLAG_ANTIFLOOD } // PRQA S 3429,3457

//*****************************************************************************
//  Functionname:  ICERR_DEMMAP_STICKY
//  
//  Macro used for creating an element of ICERR_S_DemMapEntry which flags the error as
//  STICKY. Sticky errors will never be allowed to be set to PASSED again and will always
//  stay failed until the Error Manager is reinitialized.
//  
//  Parameter:     const RhpString ic_err   <In>
//  
//  
//  Parameter:     const RhpString dem   <In>
//  
//  
//  Parameter:     const RhpString prio   <In>
//  
//    
//  
//  return         RhpString
//**************************************************************************** */
/*## operation ICERR_DEMMAP_STICKY(RhpString,RhpString,RhpString) const */
#define ICERR_DEMMAP_STICKY(ic_err, dem, prio)    \
    { ic_err, dem, prio, ICERR_cui8_MAPFLAG_STICKY }    // PRQA S 3429,3457

//*****************************************************************************
//  Functionname:  ICERR_v_SetContextTemperature
//  
//  Passes current ECU or imager temperature to the error manager. This data will
//  be appended to the DEMs and thus can be read from the ECU error memory.
//  
//  Parameter:     const float32 f32_Temperature   <In>
//  Current ECU or right imager temperature
//    
//  
//  return         void
//**************************************************************************** */
/*## operation ICERR_v_SetContextTemperature(const float32) */
void ICERR_v_SetContextTemperature(const float32 f32_Temperature);

//*****************************************************************************
//  Functionname:  ICERR_v_SetContextState
//  
//  Passes IC internal state context data to the error manager. This data will
//  be appended to the DEMs and thus can be read from the ECU error memory.
//  
//  Parameter:     const IC_S_DemExtDataIcState s_IcState   <In>
//  Current ECU or right imager temperature
//    
//  
//  return         void
//**************************************************************************** */
/*## operation ICERR_v_SetContextState(const IC_S_DemExtDataIcState) */
void ICERR_v_SetContextState(const IC_S_DemExtDataIcState s_IcState);

//*****************************************************************************
//  Functionname:  ICERR_v_SetSimLogErrCallback
//  
//  
//  
//  Parameter:     ICERR_Fct_SimLogErr pfct_LogFunc   <In>
//  
//    
//  
//  return         void
//**************************************************************************** */
/*## operation ICERR_v_SetSimLogErrCallback(ICERR_Fct_SimLogErr) */
#if (IC_COMPILE_FOR_MTS == 1)
void ICERR_v_SetSimLogErrCallback(ICERR_Fct_SimLogErr pfct_LogFunc);
#endif


/*#[ ignore */

#ifdef __cplusplus
}
#endif

/*#]*/


#endif
/*********************************************************************
	File Path: ..\..\..\04_Engineering\01_Source_Code\Algo\ic\ic_errmanager.h
*********************************************************************/
