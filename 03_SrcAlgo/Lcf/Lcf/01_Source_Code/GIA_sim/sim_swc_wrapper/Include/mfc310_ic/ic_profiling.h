//* **********************************************************************
//  COMPANY:         $CompanyInfo: CONFIDENTIAL AND PROPRIETARY PROPERTY OF CONTINENTAL AG , A.D.C. GmbH  -  ALL RIGHTS RESERVED $
//  
//  PROJECT:         MFC30x_MCU
//  CPU:             MPC5675K
//  
//  PACKAGE:         $Source: ic_profiling.h $ $Revision: 1.1 $
//  MKS Date:        $Date: 2021/12/13 17:25:56CET $
//  
//  RHAPSODY:        7.5.3
//  COMPONENT:       IC
//  CONFIGURATION:   DefaultConfig
//  MODEL ELEMENT:   ic_profiling
//  MODULNAME:       ..\..\..\04_Engineering\01_Source_Code\Algo\ic\ic_profiling.h
//  LOGIN:           uidt3974  
//  
//  
//  
//  AUTHOR:          $Author: Wang, David (Wangd3) $
//! CREATION DATE:   Thu, 2, Aug 2012  5:00 W. Europe Daylight Time PM 
//**************************************************************************** */

#ifndef ic_profiling_H
#define ic_profiling_H

/*## dependency ic_cfg */
#include "ic_cfg.h"
/*## package Ic_Pkg */

/*## class TopLevel::ic_profiling */


/*#[ ignore */

#ifdef __cplusplus
extern "C"
{
#endif

/*#]*/


/*#[ type IC_E_ProfileSection */
typedef enum {
    IC_e_PROFSECT__NOT_PROFILED_YET__,
    IC_e_PROFSECT_P1_TOTAL,
    IC_e_PROFSECT_P2_TOTAL,
    IC_e_PROFSECT_INIT_TOTAL,
    IC_e_PROFSECT_INIT_IMAGERS,
    IC_e_PROFSECT_INIT_BIST,
    IC_e_PROFSECT_INIT_INITREGISTERS,
    IC_e_PROFSECT_INIT_SYNC_IMAGERS,
    IC_e_PROFSECT_INIT_FINISH_2_IC_START,
    IC_e_PROFSECT_START_2_DBTEST_DONE,
    IC_e_PROFSECT_START_2_ATEST_DONE,
    IC_e_PROFSECT_START_2_RUNNINGSTABLE,
    IC_e_PROFSECT_P1_EMBDAT_CHECK,
    IC_e_PROFSECT_P1_EMBDAT_EXTRACT,
    IC_e_PROFSECT_P1_NEW_REGDATA_CHECKS,
    IC_e_PROFSECT_P1_ROTATE_REGOUTPUT_BUFF,
    IC_e_PROFSECT_P1_CALC_IMAGESTUFF,
    IC_e_PROFSECT_P1_PROVIDERESULTS,
    IC_e_PROFSECT_P1_PROCESS_REGRESPONSE,
    IC_e_PROFSECT_P1_FLUSH_REGS,
    IC_e_PROFSECT_P1_DEMFLUSH,
    IC_e_PROFSECT_P2_EXTRACT_HISTOGRAM,
    IC_e_PROFSECT_P2_DEMFLUSH,
    IC_e_PROFSECT_P2_EXPOSURE,
    IC_e_PROFSECT_P2_FLUSH_REGS,
    IC_e_PROFSECT_P2_MEASFREEZE,
    IC_e_PROFSECT_P2_PROVIDERESULTS,
    IC_e_PROFSECT_I2C_DURATION_P1,
    IC_e_PROFSECT_I2C_DURATION_P2,
    IC_e_PROFSECT_WILDCARD_1,
    IC_e_PROFSECT_WILDCARD_2,
    IC_e_PROFSECT__LAST_ENTRY__
}  IC_E_ProfileSection;
/*#]*/

/*## type IC_S_ProfDataEntry */
typedef struct IC_S_ProfDataEntry {
    uint32 ui32_StartUs;		/*## attribute ui32_StartUs */
    uint32 ui32_EndUs;		/*## attribute ui32_EndUs */
    uint32 ui32_RuntimeUs;		/*## attribute ui32_RuntimeUs */
    IC_E_ProfileSection e_Section;		/*## attribute e_Section */
} IC_S_ProfDataEntry;

//  Stores profiling data timestamps and runtime. It's globally visible and is intended to be handled by
//  macros 'IC_PROFILE_START' and 'IC_PROFILE_STOP'.
/*## attribute IC_as_ProfilingData */
#if (IC_PROFILING_ENABLED == 1)
extern IC_S_ProfDataEntry IC_as_ProfilingData[IC_e_PROFSECT__LAST_ENTRY__];
#endif

/***    User explicit entries    ***/


/* Operations */

//*****************************************************************************
//  Functionname:  IC_PROFILE_START
//  
//  Set start timestamp of a specific profiling section.
//  
//  This is an inline-function implemented as a macro, as calling profiling functions should
//  not affect performance due to function call overhead and missing optimizations.
//  
//  If IC_PROFILING_ENABLED != 1, then the call is replaced by a null statement and does nothing.
//  
//  Parameter:     const RhpString e_ProfSect   <In>
//  
//    
//  
//  return         RhpString
//**************************************************************************** */
/*## operation IC_PROFILE_START(RhpString) const */
// PRQA S 3429,3435,3456,3412 4
#if (IC_PROFILING_ENABLED == 1)
#define IC_PROFILE_START(e_ProfSect)    \
    IC_as_ProfilingData[(e_ProfSect)].e_Section = (e_ProfSect);\
    IC_as_ProfilingData[(e_ProfSect)].ui32_StartUs = ICOSW_ui32_GetTimeUs();
#else
#define IC_PROFILE_START(e_ProfSect)
#endif


//*****************************************************************************
//  Functionname:  IC_PROFILE_STOP
//  
//  Set stop timestamp of a specific profiling section and calculates the section's runtime.
//  
//  This is an inline-function implemented as a macro, as calling profiling functions should
//  not affect performance due to function call overhead and missing optimizations.
//  
//  If IC_PROFILING_ENABLED != 1, then the call is replaced by a null statement and does nothing.
//  
//  Parameter:     const RhpString e_ProfSect   <In>
//  
//    
//  
//  return         RhpString
//**************************************************************************** */
/*## operation IC_PROFILE_STOP(RhpString) const */
// PRQA S 3429,3435,3456,3412 4
#if (IC_PROFILING_ENABLED == 1)
#define IC_PROFILE_STOP(e_ProfSect)    \
    IC_as_ProfilingData[(e_ProfSect)].ui32_EndUs = ICOSW_ui32_GetTimeUs();\
    IC_as_ProfilingData[(e_ProfSect)].ui32_RuntimeUs = IC_as_ProfilingData[(e_ProfSect)].ui32_EndUs - IC_as_ProfilingData[(e_ProfSect)].ui32_StartUs;
#else
#define IC_PROFILE_STOP(e_ProfSect)
#endif


/***    User explicit entries    ***/



/*#[ ignore */

#ifdef __cplusplus
}
#endif

/*#]*/


#endif
/*********************************************************************
	File Path: ..\..\..\04_Engineering\01_Source_Code\Algo\ic\ic_profiling.h
*********************************************************************/
