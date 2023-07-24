//* **********************************************************************
//  COMPANY:         $CompanyInfo: CONFIDENTIAL AND PROPRIETARY PROPERTY OF CONTINENTAL AG , A.D.C. GmbH  -  ALL RIGHTS RESERVED $
//  
//  PROJECT:         MFC30x_MCU
//  CPU:             MPC5675K
//  
//  PACKAGE:         $Source: ic_oswrapper.c $ $Revision: 1.1 $
//  MKS Date:        $Date: 2021/12/13 17:25:56CET $
//  
//  RHAPSODY:        7.5.3
//  COMPONENT:       IC
//  CONFIGURATION:   DefaultConfig
//  MODEL ELEMENT:   ic_oswrapper
//  MODULNAME:       ..\..\..\04_Engineering\01_Source_Code\Algo\ic\ic_oswrapper.c
//  LOGIN:           uidt3974  
//  
//  ==========================================================================================
//  The following QAC messages are suppressed for this module:
//  
//  Possible dereference of NULL pointer
//    PRQA S 0506 EOF
//  
//  AUTHOR:          $Author: Wang, David (Wangd3) $
//! CREATION DATE:   Tue, 31, Jul 2012  2:42 W. Europe Daylight Time PM 
//**************************************************************************** */

/*## auto_generated */
#include "ic_oswrapper.h"
/*## dependency ic_errmanager */
#include "ic_errmanager.h"
/*## package Ic_Pkg */

/*## class TopLevel::ic_oswrapper */


/*#[ ignore */
#ifdef __cplusplus
extern "C"
{
#endif

/*#]*/


/*## type ICOSW_S_RoiDef */
typedef struct ICOSW_S_RoiDef {
    IC_t_RoiHandle rh_Handle;		/*## attribute rh_Handle */
    ICIF_E_ROIFRAMETYPE e_FrameType;		/*## attribute e_FrameType */
} ICOSW_S_RoiDef;

//  Stores all externally registered image-ROIs
/*## attribute ICOSW_as_RegisteredRois */
static ICOSW_S_RoiDef ICOSW_as_RegisteredRois[IC_e_ROIID__NUM_ENTRIES__];

/*## attribute ICOSW_ps_Funcs */
static const IC_S_PlatformFuncs * ICOSW_ps_Funcs = NULL;

//  Handle to Test-ROI used for analog-test, databus-test, ...
/*## attribute ICOSW_rh_TestRoiHandle */
static IC_t_RoiHandle ICOSW_rh_TestRoiHandle = IC_rh_ROIHANDLE_INVALID;

//  Name of this module, required for calls to ICERR_HANDLE().
//  
//  Character string is only used for debugging & recording analysis, so suppress QAC warnings:
//  PRQA S 5013,3625 3
/*## attribute pch_ModuleName */
static const char * const pch_ModuleName = "OSWRP";

/*## operation ICOSW_v_Init(const IC_S_PlatformFuncs * const) */
void ICOSW_v_Init(const IC_S_PlatformFuncs * const ps_PlatFuncs) {
    /*#[ operation ICOSW_v_Init(const IC_S_PlatformFuncs * const) */
    uint32 ui32_Index = 0;
    
    ICOSW_ps_Funcs = ps_PlatFuncs;
    
    // Set all roi-handles to invalid
    IC_v_ZEROMEM(ICOSW_as_RegisteredRois);
    for (ui32_Index = 0; ui32_Index < IC_ARRLEN(ICOSW_as_RegisteredRois); ui32_Index++)
    {
      ICOSW_as_RegisteredRois[ui32_Index].rh_Handle = IC_rh_ROIHANDLE_INVALID;
    }
    /*#]*/
}

/*## operation ICOSW_ui32_GetTimeUs() */
uint32 ICOSW_ui32_GetTimeUs(void) {
    /*#[ operation ICOSW_ui32_GetTimeUs() */
    return ICOSW_ps_Funcs->pfct_ui32_GetTimeUs();
    /*#]*/
}

/*## operation ICOSW_ui64_GetTimeUs() */
uint64 ICOSW_ui64_GetTimeUs(void) {
    /*#[ operation ICOSW_ui64_GetTimeUs() */
    return ICOSW_ps_Funcs->pfct_ui64_GetTimeUs();
    /*#]*/
}

/*## operation ICOSW_v_DelayUs(const uint32) */
void ICOSW_v_DelayUs(const uint32 ui32_TimeUs) {
    /*#[ operation ICOSW_v_DelayUs(const uint32) */
    ICOSW_ps_Funcs->pfct_v_DelayUs(ui32_TimeUs);
    /*#]*/
}

/*## operation ICOSW_v_SetTriggerPin(const boolean) */
void ICOSW_v_SetTriggerPin(const boolean b_Level) {
    /*#[ operation ICOSW_v_SetTriggerPin(const boolean) */
    ICOSW_ps_Funcs->pfct_v_SetTriggerPin(b_Level);
    /*#]*/
}

/*## operation ICOSW_v_SetDebugLED(const boolean) */
void ICOSW_v_SetDebugLED(const boolean b_State) {
    /*#[ operation ICOSW_v_SetDebugLED(const boolean) */
    ICOSW_ps_Funcs->pfct_v_SetDebugLed(b_State);
    /*#]*/
}

/*## operation ICOSW_v_SetTestvoltage(const IC_E_TESTVOLTAGE) */
void ICOSW_v_SetTestvoltage(const IC_E_TESTVOLTAGE e_Voltage) {
    /*#[ operation ICOSW_v_SetTestvoltage(const IC_E_TESTVOLTAGE) */
    ICOSW_ps_Funcs->pfct_v_SetTestvoltage(e_Voltage);
    /*#]*/
}

/*## operation ICOSW_v_SetI2CBusTiming(const IC_E_I2CTIMING) */
void ICOSW_v_SetI2CBusTiming(const IC_E_I2CTIMING e_Timing) {
    /*#[ operation ICOSW_v_SetI2CBusTiming(const IC_E_I2CTIMING) */
    ICOSW_ps_Funcs->pfct_v_SetI2CTiming(e_Timing);
    /*#]*/
}

/*## operation ICOSW_e_RegTransfer(const IC_E_Imager,IC_S_RegDataPair * const,const uint32,const IC_E_TRANSFMODE,const IC_Fct_TransfCallback,const uint8) */
IC_E_ERROR ICOSW_e_RegTransfer(const IC_E_Imager e_SensorId, IC_S_RegDataPair * const ps_AddrDataPairs, const uint32 ui32_NumRegs, const IC_E_TRANSFMODE e_TransferMode, const IC_Fct_TransfCallback fct_DoneCallback, const uint8 ui8_Id) {
    /*#[ operation ICOSW_e_RegTransfer(const IC_E_Imager,IC_S_RegDataPair * const,const uint32,const IC_E_TRANSFMODE,const IC_Fct_TransfCallback,const uint8) */
    IC_E_ERROR e_Ret = IC_e_ERR_OK;
    IC_E_RXTXERR e_TransRet = IC_e_RXTXERR_OK;
    
    e_TransRet = ICOSW_ps_Funcs->pfct_RegTransBuff(e_SensorId, ps_AddrDataPairs, ui32_NumRegs, e_TransferMode, fct_DoneCallback, ui8_Id);
    if (IC_e_RXTXERR_OK != e_TransRet)
    {
      e_Ret = ICOSW_e_HandleRXTXErr(e_TransRet);
    }
    return e_Ret;
    /*#]*/
}

/*## operation ICOSW_e_RoiRegister(const IC_E_ROIID,const IC_S_Roi * const,const ICIF_E_ROIFRAMETYPE) */
IC_E_ERROR ICOSW_e_RoiRegister(const IC_E_ROIID e_RoiId, const IC_S_Roi * const ps_Roi, const ICIF_E_ROIFRAMETYPE e_FrameType) {
    /*#[ operation ICOSW_e_RoiRegister(const IC_E_ROIID,const IC_S_Roi * const,const ICIF_E_ROIFRAMETYPE) */
    IC_E_ERROR      e_Ret     = IC_e_ERR_OK;
    ICIF_E_ROIERR   e_RoiRet  = ICIF_e_ROIERR_OK;
    ICOSW_S_RoiDef *ps_RoiDef = NULL;
    
    // Check input data
    if ((ps_Roi      == NULL)
     || (e_RoiId     >= IC_e_ROIID__NUM_ENTRIES__)
     || (e_FrameType >= ICIF_e__NUM_ENTRIES_))
    {
      e_Ret = IC_e_ERR_ILLEGAL_ARGUMENT;
    }
    
    // Check if ROI is already registered
    if (IC_e_ERR_OK == e_Ret)
    {
      // e_RoiId is checked above, so QAC is wrong here:
      // PRQA S 3692 1
      ps_RoiDef = &ICOSW_as_RegisteredRois[e_RoiId];
      if (ps_RoiDef->rh_Handle != IC_rh_ROIHANDLE_INVALID)
      {
        e_Ret = IC_e_ERR_ROI_ALREADY_REGISTERED;
      }
    }
    
    // Register ROI
    if (IC_e_ERR_OK == e_Ret)
    {
      // 'ps_RoiDef' is assigned above, QAC is wrong with 'Apparent dereference of NULL pointer':
      // PRQA S 0505 1
      e_RoiRet = ICOSW_ps_Funcs->pfct_e_RoiRegister(&ps_RoiDef->rh_Handle, ps_Roi, e_FrameType);
      if (e_RoiRet == ICIF_e_ROIERR_OK)
      {
        ps_RoiDef->e_FrameType = e_FrameType;
      }
      else
      {
        e_Ret = ICERR_HANDLE(IC_e_ERR_REGISTER_ROI, e_RoiRet);
      }
    }
    
    return e_Ret;
    /*#]*/
}

/*## operation ICOSW_e_RoiDelete(const IC_E_ROIID) */
IC_E_ERROR ICOSW_e_RoiDelete(const IC_E_ROIID e_RoiId) {
    /*#[ operation ICOSW_e_RoiDelete(const IC_E_ROIID) */
    IC_E_ERROR e_Ret    = IC_e_ERR_OK;
    ICIF_E_ROIERR e_RoiRet = ICIF_e_ROIERR_OK;
    ICOSW_S_RoiDef *ps_RoiDef = NULL;
    
    // Check argument
    if (e_RoiId >= IC_e_ROIID__NUM_ENTRIES__)
    {
      e_Ret = IC_e_ERR_ILLEGAL_ARGUMENT;
    }
    else
    {
      // Delete ROI if it's registered (do nothing if ROI is not mapped)
      ps_RoiDef = &ICOSW_as_RegisteredRois[e_RoiId];
      if (ps_RoiDef->rh_Handle != IC_rh_ROIHANDLE_INVALID)
      {
        e_RoiRet = ICOSW_ps_Funcs->pfct_e_RoiUnregister(&(ps_RoiDef->rh_Handle));
        ps_RoiDef->rh_Handle = IC_rh_ROIHANDLE_INVALID;
      }
      if (e_RoiRet != ICIF_e_ROIERR_OK)
      {
        e_Ret = ICERR_HANDLE(IC_e_ERR_DELETE_ROI, e_RoiRet);
      }
    }
    
    return e_Ret;
    /*#]*/
}

/*## operation ICOSW_e_RoiUnregisterAll() */
IC_E_ERROR ICOSW_e_RoiUnregisterAll(void) {
    /*#[ operation ICOSW_e_RoiUnregisterAll() */
    IC_E_ERROR      e_Ret      = IC_e_ERR_OK;
    IC_E_ERROR      e_SubRet   = IC_e_ERR_OK;
    ICOSW_S_RoiDef *ps_RoiDef  = NULL;
    uint32          ui32_Index = 0;
    
    // Unregister all registered ROIs
    for (ui32_Index = 0; ui32_Index < IC_ARRLEN(ICOSW_as_RegisteredRois); ui32_Index++)
    {
      ps_RoiDef = &ICOSW_as_RegisteredRois[ui32_Index];
      if (ps_RoiDef->rh_Handle != IC_rh_ROIHANDLE_INVALID)
      {
        e_SubRet = ICOSW_e_RoiDelete((IC_E_ROIID)ui32_Index); // PRQA S 1482
        if (IC_e_ERR_OK == e_SubRet)
        {
          e_Ret = e_SubRet;
        }
      }
    }
    return e_Ret;
    /*#]*/
}

/*## operation ICOSW_e_RegisterTestRoi(const IC_S_Roi * const) */
IC_E_ERROR ICOSW_e_RegisterTestRoi(const IC_S_Roi * const ps_Roi) {
    /*#[ operation ICOSW_e_RegisterTestRoi(const IC_S_Roi * const) */
    IC_E_ERROR    e_Ret    = IC_e_ERR_OK;
    ICIF_E_ROIERR e_RoiRet = ICIF_e_ROIERR_OK;
    
    e_RoiRet = ICOSW_ps_Funcs->pfct_e_RoiRegister(&ICOSW_rh_TestRoiHandle, ps_Roi, ICIF_e_ROIFRAMETYPE_ODD);
    if (e_RoiRet != ICIF_e_ROIERR_OK)
    {
      e_Ret = ICERR_HANDLE(IC_e_ERR_REGISTER_ROI, e_RoiRet);
    }
    return e_Ret;
    /*#]*/
}

/*## operation ICOSW_e_DeleteTestRoi() */
IC_E_ERROR ICOSW_e_DeleteTestRoi(void) {
    /*#[ operation ICOSW_e_DeleteTestRoi() */
    IC_E_ERROR    e_Ret    = IC_e_ERR_OK;
    ICIF_E_ROIERR e_RoiRet = ICIF_e_ROIERR_OK;
    
    e_RoiRet = ICOSW_ps_Funcs->pfct_e_RoiUnregister(&ICOSW_rh_TestRoiHandle);
    if (e_RoiRet != ICIF_e_ROIERR_OK)
    {
      e_Ret = ICERR_HANDLE(IC_e_ERR_DELETE_ROI, e_RoiRet);
    }
    else
    {
      ICOSW_rh_TestRoiHandle = IC_rh_ROIHANDLE_INVALID;
    }
    return e_Ret;
    /*#]*/
}

/*## operation ICOSW_e_Measfreeze(const uint8,const uint32,const void * const,const uint32,const uint8) */
IC_E_ERROR ICOSW_e_Measfreeze(const uint8 ui8_FuncId, const uint32 ui32_VirtAddr, const void * const pv_Buff, const uint32 ui32_Size, const uint8 ui8_MeasGroup) {
    /*#[ operation ICOSW_e_Measfreeze(const uint8,const uint32,const void * const,const uint32,const uint8) */
    IC_E_ERROR e_Ret = IC_e_ERR_OK;
    ICIF_E_MEASERR e_MeasErr = ICIF_e_MEASERR_OK;
    
    e_MeasErr = ICOSW_ps_Funcs->pfct_MeasFreeze(ui8_FuncId, ui32_VirtAddr, pv_Buff, ui32_Size, ui8_MeasGroup);
    if (e_MeasErr != ICIF_e_MEASERR_OK)
    {
      e_Ret = IC_e_ERR_MEASFREEZE;
    }
    return e_Ret;
    /*#]*/
}

/*## operation ICOSW_e_DemReport(const IC_E_DEM,const IC_E_DEMSTATUS,const IC_Un_DemDtcExtData * const) */
IC_E_ERROR ICOSW_e_DemReport(const IC_E_DEM e_Dem, const IC_E_DEMSTATUS e_Status, const IC_Un_DemDtcExtData * const pun_ExtData) {
    /*#[ operation ICOSW_e_DemReport(const IC_E_DEM,const IC_E_DEMSTATUS,const IC_Un_DemDtcExtData * const) */
    uint8 ui8_OptDataSize;
    IC_E_ERROR e_Ret = IC_e_ERR_OK;
    if ((NULL != ICOSW_ps_Funcs) && (NULL != ICOSW_ps_Funcs->pfct_b_DemReport))
    {
      if (pun_ExtData == NULL)
      {
        ui8_OptDataSize = 0;
      }
      else
      {
        ui8_OptDataSize = ICCFG_cui32_DEM_EXTDATA_SIZE;
      }
      if (b_FALSE == ICOSW_ps_Funcs->pfct_b_DemReport(e_Dem, e_Status, pun_ExtData, ui8_OptDataSize))
      {
        e_Ret = ICERR_HANDLE(IC_e_ERR_DEMREPORT, e_Dem);
      }
    }
    else
    {
      e_Ret = ICERR_HANDLE(IC_e_ERR_NULLPOINTER, 0);
    }
    return e_Ret;
    /*#]*/
}

/*## operation ICOSW_v_GetCommStats(IC_S_CommStats * const) */
void ICOSW_v_GetCommStats(IC_S_CommStats * const ps_CommStats) {
    /*#[ operation ICOSW_v_GetCommStats(IC_S_CommStats * const) */
    ICOSW_ps_Funcs->pfct_v_GetCommStats(ps_CommStats);
    /*#]*/
}

/*## operation ICOSW_e_HandleRXTXErr(const IC_E_RXTXERR) */
IC_E_ERROR ICOSW_e_HandleRXTXErr(const IC_E_RXTXERR e_TransRet) {
    /*#[ operation ICOSW_e_HandleRXTXErr(const IC_E_RXTXERR) */
    IC_E_ERROR e_Ret = IC_e_ERR_OK;
    
    // LUT style switch/case, so suppress QAC warning:
    // PRQA S 2205 RXTXERR_LUT
    switch (e_TransRet)
    {
      case IC_e_RXTXERR_OK:               e_Ret = IC_e_ERR_OK;                   break;
      case IC_e_RXTXERR_BUSERR:           e_Ret = IC_e_ERR_RXTX_BUSERR;          break;
      case IC_e_RXTXERR_NOACK:            e_Ret = IC_e_ERR_RXTX_NOACK;           break;
      case IC_e_RXTXERR_BUFFER_OVERFLOW:  e_Ret = IC_e_ERR_RXTX_BUFFER_OVERFLOW; break;
      case IC_e_RXTXERR_OTHER:            e_Ret = IC_e_ERR_RXTX_OTHER;           break;
      default:                            e_Ret = IC_e_ERR_RXTX_OTHER;           break;
    }
    // PRQA L:RXTXERR_LUT
    
    // Report errors via DEM
    if (IC_e_ERR_OK != e_Ret)
    {
      ICERR_v_DemFailed(IC_e_DEM_IMAGER_COMM, (uint32)e_TransRet);
    }
    
    return ICERR_HANDLE(e_Ret, 0);
    /*#]*/
}


/*#[ ignore */

#ifdef __cplusplus
}
#endif

/*#]*/


/*********************************************************************
	File Path: ..\..\..\04_Engineering\01_Source_Code\Algo\ic\ic_oswrapper.c
*********************************************************************/
