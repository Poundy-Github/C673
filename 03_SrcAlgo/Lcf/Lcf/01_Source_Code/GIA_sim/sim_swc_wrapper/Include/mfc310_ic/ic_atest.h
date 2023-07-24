//* **********************************************************************
//  COMPANY:         $CompanyInfo: CONFIDENTIAL AND PROPRIETARY PROPERTY OF CONTINENTAL AG , A.D.C. GmbH  -  ALL RIGHTS RESERVED $
//  
//  PROJECT:         MFC30x_MCU
//  CPU:             MPC5675K
//  
//  PACKAGE:         $Source: ic_atest.h $ $Revision: 1.1 $
//  MKS Date:        $Date: 2021/12/13 17:25:46CET $
//  
//  RHAPSODY:        7.5.3
//  COMPONENT:       IC
//  CONFIGURATION:   DefaultConfig
//  MODEL ELEMENT:   ic_atest
//  MODULNAME:       ..\..\..\04_Engineering\01_Source_Code\Algo\ic\ic_atest.h
//  LOGIN:           uidt3974  
//  
//  =======================================================================================
//  The following QAC messages are suppressed for this module:
//  
//    Error handling is emulated by using an exclusive label ERROR_EXIT, which is entered
//    via GOTO on error. Code using this type of error handling is much easier to read,
//    as no nested if() statements are required and checking of error-code/flag on each
//    block can be omitted. Suppress QAC warnings related to this functionality:
//      PRQA S 2001,2015,7003 EOF
//  
//    The parameter 'xxxx' is never modified and so it could be declared with the 'const' qualifier.
//      PRQA S 3227 EOF
//  
//    Possible dereference of NULL pointer.
//      PRQA S 0506 EOF
//  
//  AUTHOR:          $Author: Wang, David (Wangd3) $
//! CREATION DATE:   Mon, 30, Jul 2012  4:08 W. Europe Daylight Time PM 
//**************************************************************************** */

#ifndef ic_atest_H
#define ic_atest_H

/*## dependency ic_cfg */
#include "ic_cfg.h"
/*## operation ICAT_e_SetRefValues(const IC_S_ATestRefValues *,const IC_S_ATestMaxTols *) */
#include "ic_errcodes.h"
/*## dependency ic_types */
#include "ic_types.h"
/*## package Ic_Pkg */

/*## class TopLevel::ic_atest */
/*#[ ignore */
//  =======================================================================================
//  The following QAC messages are suppressed for this module:
//  
//    Error handling is emulated by using an exclusive label ERROR_EXIT, which is entered
//    via GOTO on error. Code using this type of error handling is much easier to read,
//    as no nested if() statements are required and checking of error-code/flag on each
//    block can be omitted. Suppress QAC warnings related to this functionality:
//      PRQA S 2001,2015,7003 EOF
//  
//    The parameter 'xxxx' is never modified and so it could be declared with the 'const' qualifier.
//      PRQA S 3227 EOF
//  
//    Possible dereference of NULL pointer.
//      PRQA S 0506 EOF
/*#]*/


/*#[ ignore */
// Do not define anything if analog test is disabled in config file
#if (IC_ANALOG_TEST_ENABLED == 1)

#ifdef __cplusplus
extern "C"
{
#endif

/*#]*/


/*## type ICAT_S_Parameters */
typedef struct ICAT_S_Parameters {
    IC_S_ATestRefValues s_ReferenceValues;		/*## attribute s_ReferenceValues */
    IC_S_ATestMaxTols s_MaxTols;		/*## attribute s_MaxTols */
    IC_S_Rect_ui16 s_CalcRoi;		/*## attribute s_CalcRoi */
    uint16 ui16_RoiStepsizeY;		/*## attribute ui16_RoiStepsizeY */
} ICAT_S_Parameters;

/*## type ICAT_S_Results */
typedef struct ICAT_S_Results {
    float32 f32_DevMean;		/*## attribute f32_DevMean */
    float32 f32_DevColmeanMin;		/*## attribute f32_DevColmeanMin */
    float32 f32_DevColmeanMax;		/*## attribute f32_DevColmeanMax */
    float32 f32_DevColmeanAbs;		/*## attribute f32_DevColmeanAbs */
    uint32 ui32_TotalMean;		/*## attribute ui32_TotalMean */
    uint32 ui32_ColMeanMin;		/*## attribute ui32_ColMeanMin */
    uint32 ui32_ColMeanMax;		/*## attribute ui32_ColMeanMax */
    uint8 ui8_ProcessedLines;		/*## attribute ui8_ProcessedLines */
    boolean b_ColumnCheckPassed;		/*## attribute b_ColumnCheckPassed */
} ICAT_S_Results;

/*#[ type ICAT_E_STATE */
typedef enum {
    ICAT_e_STATE_WAIT_START,
    ICAT_e_STATE_PREPARE,
    ICAT_e_STATE_MEAS_ATV3_1XGAIN,
    ICAT_e_STATE_MEAS_ATV1_1XGAIN,
    ICAT_e_STATE_MEAS_ATV1_2XGAIN,
    ICAT_e_STATE_CLEANUP,
    ICAT_e_STATE_FINISHED
}  ICAT_E_STATE;
/*#]*/

/*## type ICAT_S_MeasData */
typedef struct ICAT_S_MeasData {
    ICAT_S_Results s_Results_ATV3_1x;		/*## attribute s_Results_ATV3_1x */
    ICAT_S_Results s_Results_ATV1_1x;		/*## attribute s_Results_ATV1_1x */
    ICAT_S_Results s_Results_ATV1_2x;		/*## attribute s_Results_ATV1_2x */
    ICAT_S_Parameters s_Parameters;		/*## attribute s_Parameters */
    sint16 si16_Y0_1x;		/*## attribute si16_Y0_1x */
    sint16 si16_Y0_2x;		/*## attribute si16_Y0_2x */
    ICAT_E_STATE e_State;		/*## attribute e_State */
    IC_E_ATEST_STATUS e_Status;		/*## attribute e_Status */
} ICAT_S_MeasData;

/*## type ICAT_S_Obj */
typedef struct ICAT_S_Obj {
    uint64 ui64_SensorFuseId;		/*## attribute ui64_SensorFuseId */
    IC_S_ATestResults s_ExtResults;		/*## attribute s_ExtResults */
    ICAT_S_Parameters * ps_Parameters;		/*## attribute ps_Parameters */
    ICAT_S_Results * ps_Results_ATV3_1x;		/*## attribute ps_Results_ATV3_1x */
    ICAT_S_Results * ps_Results_ATV1_1x;		/*## attribute ps_Results_ATV1_1x */
    ICAT_S_Results * ps_Results_ATV1_2x;		/*## attribute ps_Results_ATV1_2x */
    uint32 aui32_ColumnPixelsSum[ICCFG_cui16_CROI_ODD_WIDTH];		/*## attribute aui32_ColumnPixelsSum */
    uint16 * pui16_RoiBuffer;		/*## attribute pui16_RoiBuffer */
    uint16 ui16_CurrentLineNum;		/*## attribute ui16_CurrentLineNum */
    uint16 ui16_NumLinesToAcquire;		/*## attribute ui16_NumLinesToAcquire */
    uint16 ui16_ProcessedLineCount;		/*## attribute ui16_ProcessedLineCount */
    uint16 ui16_CopiedLinesCount;		/*## attribute ui16_CopiedLinesCount */
    sint16 si16_Y0_1x;		/*## attribute si16_Y0_1x */
    sint16 si16_Y0_2x;		/*## attribute si16_Y0_2x */
    uint16 ui16_TriggerFrame;		/*## attribute ui16_TriggerFrame */
    uint16 ui16_TriggerFrameNext;		/*## attribute ui16_TriggerFrameNext */
    boolean b_NextTriggerValid;		/*## attribute b_NextTriggerValid */
    boolean b_SamplingEnabled;		/*## attribute b_SamplingEnabled */
    boolean b_LineCalcFinished;		/*## attribute b_LineCalcFinished */
} ICAT_S_Obj;

/***    User explicit entries    ***/


/* Operations */

//*****************************************************************************
//  Functionname:  ICAT_v_Init
//  
//  
//  
//  Parameter:     ICAT_S_MeasData * ps_Meas   <In>
//  
//    
//  
//  return         void
//**************************************************************************** */
/*## operation ICAT_v_Init(ICAT_S_MeasData *) */
void ICAT_v_Init(ICAT_S_MeasData * ps_Meas);

//*****************************************************************************
//  Functionname:  ICAT_e_SetRefValues
//  
//  
//  
//  Parameter:     const IC_S_ATestRefValues * ps_ReferenceValues   <In>
//  
//  
//  Parameter:     const IC_S_ATestMaxTols * ps_MaxTols   <In>
//  
//    
//  
//  return         IC_E_ERROR
//**************************************************************************** */
/*## operation ICAT_e_SetRefValues(const IC_S_ATestRefValues *,const IC_S_ATestMaxTols *) */
IC_E_ERROR ICAT_e_SetRefValues(const IC_S_ATestRefValues * ps_ReferenceValues, const IC_S_ATestMaxTols * ps_MaxTols);

//*****************************************************************************
//  Functionname:  ICAT_e_SetRoi
//  
//  
//  
//  Parameter:     const IC_S_Roi * ps_Roi   <In>
//  
//  
//  Parameter:     uint16 ui16_RoiStepsizeY   <In>
//  
//    
//  
//  return         IC_E_ERROR
//**************************************************************************** */
/*## operation ICAT_e_SetRoi(const IC_S_Roi *,uint16) */
IC_E_ERROR ICAT_e_SetRoi(const IC_S_Roi * ps_Roi, uint16 ui16_RoiStepsizeY);

//*****************************************************************************
//  Functionname:  ICAT_e_SetAcquisitionParams
//  
//  
//  
//  Parameter:     const IC_S_ATestAcquParams * ps_AcquParams   <In>
//  
//    
//  
//  return         IC_E_ERROR
//**************************************************************************** */
/*## operation ICAT_e_SetAcquisitionParams(const IC_S_ATestAcquParams *) */
IC_E_ERROR ICAT_e_SetAcquisitionParams(const IC_S_ATestAcquParams * ps_AcquParams);

//*****************************************************************************
//  Functionname:  ICAT_v_SetSensorFuseId
//  
//  
//  
//  Parameter:     uint64 ui64_SensorId   <In>
//  
//    
//  
//  return         void
//**************************************************************************** */
/*## operation ICAT_v_SetSensorFuseId(uint64) */
void ICAT_v_SetSensorFuseId(uint64 ui64_SensorId);

//*****************************************************************************
//  Functionname:  ICAT_e_Start
//  
//  
//  
//    
//  
//  return         IC_E_ERROR
//**************************************************************************** */
/*## operation ICAT_e_Start() */
IC_E_ERROR ICAT_e_Start(void);

//*****************************************************************************
//  Functionname:  ICAT_v_Reset
//  
//  
//  
//    
//  
//  return         void
//**************************************************************************** */
/*## operation ICAT_v_Reset() */
void ICAT_v_Reset(void);

//*****************************************************************************
//  Functionname:  ICAT_e_Exec
//  
//  
//  
//  Parameter:     uint16 ui16_FrameCnt   <In>
//  
//    
//  
//  return         IC_E_ERROR
//**************************************************************************** */
/*## operation ICAT_e_Exec(uint16) */
IC_E_ERROR ICAT_e_Exec(uint16 ui16_FrameCnt);

//*****************************************************************************
//  Functionname:  ICAT_e_LineFunc
//  
//  
//  
//  Parameter:     uint16 ui16_LineNumber   <In>
//  
//  
//  Parameter:     const uint16 %s[ICCFG_cui16_ATEST_ROI_WIDTH] aui16_LineRawData   <In>
//  
//  
//  Parameter:     uint16 ui16_FrameNum   <In>
//  
//    
//  
//  return         IC_E_ERROR
//**************************************************************************** */
/*## operation ICAT_e_LineFunc(uint16,const uint16 [ICCFG_cui16_ATEST_ROI_WIDTH] ,uint16) */
IC_E_ERROR ICAT_e_LineFunc(uint16 ui16_LineNumber, const uint16 aui16_LineRawData[ICCFG_cui16_ATEST_ROI_WIDTH], uint16 ui16_FrameNum);

//*****************************************************************************
//  Functionname:  ICAT_e_GetStatus
//  
//  
//  
//    
//  
//  return         IC_E_ATEST_STATUS
//**************************************************************************** */
/*## operation ICAT_e_GetStatus() */
IC_E_ATEST_STATUS ICAT_e_GetStatus(void);

//*****************************************************************************
//  Functionname:  ICAT_b_IsAnalogTestFinished
//  
//  
//  
//    
//  
//  return         boolean
//**************************************************************************** */
/*## operation ICAT_b_IsAnalogTestFinished() */
boolean ICAT_b_IsAnalogTestFinished(void);

//*****************************************************************************
//  Functionname:  ICAT_ps_GetExtResults
//  
//  
//  
//    
//  
//  return         IC_S_ATestResults * 
//**************************************************************************** */
/*## operation ICAT_ps_GetExtResults() */
IC_S_ATestResults * ICAT_ps_GetExtResults(void);


/*#[ ignore */

#ifdef __cplusplus
}
#endif

#endif /* (IC_ANALOG_TEST_ENABLED == 1) */
/*#]*/


#endif
/*********************************************************************
	File Path: ..\..\..\04_Engineering\01_Source_Code\Algo\ic\ic_atest.h
*********************************************************************/
