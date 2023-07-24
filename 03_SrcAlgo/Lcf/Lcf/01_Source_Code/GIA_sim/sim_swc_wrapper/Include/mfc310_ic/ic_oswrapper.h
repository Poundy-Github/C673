//* **********************************************************************
//  COMPANY:         $CompanyInfo: CONFIDENTIAL AND PROPRIETARY PROPERTY OF CONTINENTAL AG , A.D.C. GmbH  -  ALL RIGHTS RESERVED $
//  
//  PROJECT:         MFC30x_MCU
//  CPU:             MPC5675K
//  
//  PACKAGE:         $Source: ic_oswrapper.h $ $Revision: 1.1 $
//  MKS Date:        $Date: 2021/12/13 17:25:56CET $
//  
//  RHAPSODY:        7.5.3
//  COMPONENT:       IC
//  CONFIGURATION:   DefaultConfig
//  MODEL ELEMENT:   ic_oswrapper
//  MODULNAME:       ..\..\..\04_Engineering\01_Source_Code\Algo\ic\ic_oswrapper.h
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

#ifndef ic_oswrapper_H
#define ic_oswrapper_H

/*## dependency ic_interface */
#include "ic_interface.h"
/*## dependency ic_types */
#include "ic_types.h"
/*## package Ic_Pkg */

/*## class TopLevel::ic_oswrapper */
/*#[ ignore */
//  ==========================================================================================
//  The following QAC messages are suppressed for this module:
//  
//  Possible dereference of NULL pointer
//    PRQA S 0506 EOF
/*#]*/


/*#[ ignore */

#ifdef __cplusplus
extern "C"
{
#endif

/*#]*/


/***    User explicit entries    ***/


/* Operations */

//*****************************************************************************
//  Functionname:  ICOSW_v_Init
//  
//  
//  
//  Parameter:     const IC_S_PlatformFuncs * const ps_PlatFuncs   <In>
//  
//    
//  
//  return         void
//**************************************************************************** */
/*## operation ICOSW_v_Init(const IC_S_PlatformFuncs * const) */
void ICOSW_v_Init(const IC_S_PlatformFuncs * const ps_PlatFuncs);

//*****************************************************************************
//  Functionname:  ICOSW_ui32_GetTimeUs
//  
//  
//  
//    
//  
//  return         uint32
//**************************************************************************** */
/*## operation ICOSW_ui32_GetTimeUs() */
uint32 ICOSW_ui32_GetTimeUs(void);

//*****************************************************************************
//  Functionname:  ICOSW_ui64_GetTimeUs
//  
//  
//  
//    
//  
//  return         uint64
//**************************************************************************** */
/*## operation ICOSW_ui64_GetTimeUs() */
uint64 ICOSW_ui64_GetTimeUs(void);

//*****************************************************************************
//  Functionname:  ICOSW_v_DelayUs
//  
//  
//  
//  Parameter:     const uint32 ui32_TimeUs   <In>
//  
//    
//  
//  return         void
//**************************************************************************** */
/*## operation ICOSW_v_DelayUs(const uint32) */
void ICOSW_v_DelayUs(const uint32 ui32_TimeUs);

//*****************************************************************************
//  Functionname:  ICOSW_v_SetTriggerPin
//  
//  
//  
//  Parameter:     const boolean b_Level   <In>
//  
//    
//  
//  return         void
//**************************************************************************** */
/*## operation ICOSW_v_SetTriggerPin(const boolean) */
void ICOSW_v_SetTriggerPin(const boolean b_Level);

//*****************************************************************************
//  Functionname:  ICOSW_v_SetDebugLED
//  
//  
//  
//  Parameter:     const boolean b_State   <In>
//  
//    
//  
//  return         void
//**************************************************************************** */
/*## operation ICOSW_v_SetDebugLED(const boolean) */
void ICOSW_v_SetDebugLED(const boolean b_State);

//*****************************************************************************
//  Functionname:  ICOSW_v_SetTestvoltage
//  
//  
//  
//  Parameter:     const IC_E_TESTVOLTAGE e_Voltage   <In>
//  
//    
//  
//  return         void
//**************************************************************************** */
/*## operation ICOSW_v_SetTestvoltage(const IC_E_TESTVOLTAGE) */
void ICOSW_v_SetTestvoltage(const IC_E_TESTVOLTAGE e_Voltage);

//*****************************************************************************
//  Functionname:  ICOSW_v_SetI2CBusTiming
//  
//  
//  
//  Parameter:     const IC_E_I2CTIMING e_Timing   <In>
//  
//    
//  
//  return         void
//**************************************************************************** */
/*## operation ICOSW_v_SetI2CBusTiming(const IC_E_I2CTIMING) */
void ICOSW_v_SetI2CBusTiming(const IC_E_I2CTIMING e_Timing);

//*****************************************************************************
//  Functionname:  ICOSW_e_RegTransfer
//  
//  
//  
//  Parameter:     const IC_E_Imager e_SensorId   <In>
//  
//  
//  Parameter:     IC_S_RegDataPair * const ps_AddrDataPairs   <In>
//  
//  
//  Parameter:     const uint32 ui32_NumRegs   <In>
//  
//  
//  Parameter:     const IC_E_TRANSFMODE e_TransferMode   <In>
//  
//  
//  Parameter:     const IC_Fct_TransfCallback fct_DoneCallback   <In>
//  
//  
//  Parameter:     const uint8 ui8_Id   <In>
//  
//    
//  
//  return         IC_E_ERROR
//**************************************************************************** */
/*## operation ICOSW_e_RegTransfer(const IC_E_Imager,IC_S_RegDataPair * const,const uint32,const IC_E_TRANSFMODE,const IC_Fct_TransfCallback,const uint8) */
IC_E_ERROR ICOSW_e_RegTransfer(const IC_E_Imager e_SensorId, IC_S_RegDataPair * const ps_AddrDataPairs, const uint32 ui32_NumRegs, const IC_E_TRANSFMODE e_TransferMode, const IC_Fct_TransfCallback fct_DoneCallback, const uint8 ui8_Id);

//*****************************************************************************
//  Functionname:  ICOSW_e_RoiRegister
//  
//  
//  
//  Parameter:     const IC_E_ROIID e_RoiId   <In>
//  
//  
//  Parameter:     const IC_S_Roi * const ps_Roi   <In>
//  
//  
//  Parameter:     const ICIF_E_ROIFRAMETYPE e_FrameType   <In>
//  
//    
//  
//  return         IC_E_ERROR
//**************************************************************************** */
/*## operation ICOSW_e_RoiRegister(const IC_E_ROIID,const IC_S_Roi * const,const ICIF_E_ROIFRAMETYPE) */
IC_E_ERROR ICOSW_e_RoiRegister(const IC_E_ROIID e_RoiId, const IC_S_Roi * const ps_Roi, const ICIF_E_ROIFRAMETYPE e_FrameType);

//*****************************************************************************
//  Functionname:  ICOSW_e_RoiDelete
//  
//  
//  
//  Parameter:     const IC_E_ROIID e_RoiId   <In>
//  
//    
//  
//  return         IC_E_ERROR
//**************************************************************************** */
/*## operation ICOSW_e_RoiDelete(const IC_E_ROIID) */
IC_E_ERROR ICOSW_e_RoiDelete(const IC_E_ROIID e_RoiId);

//*****************************************************************************
//  Functionname:  ICOSW_e_RoiUnregisterAll
//  
//  
//  
//    
//  
//  return         IC_E_ERROR
//**************************************************************************** */
/*## operation ICOSW_e_RoiUnregisterAll() */
IC_E_ERROR ICOSW_e_RoiUnregisterAll(void);

//*****************************************************************************
//  Functionname:  ICOSW_e_RegisterTestRoi
//  
//  
//  
//  Parameter:     const IC_S_Roi * const ps_Roi   <In>
//  
//    
//  
//  return         IC_E_ERROR
//**************************************************************************** */
/*## operation ICOSW_e_RegisterTestRoi(const IC_S_Roi * const) */
IC_E_ERROR ICOSW_e_RegisterTestRoi(const IC_S_Roi * const ps_Roi);

//*****************************************************************************
//  Functionname:  ICOSW_e_DeleteTestRoi
//  
//  
//  
//    
//  
//  return         IC_E_ERROR
//**************************************************************************** */
/*## operation ICOSW_e_DeleteTestRoi() */
IC_E_ERROR ICOSW_e_DeleteTestRoi(void);

//*****************************************************************************
//  Functionname:  ICOSW_e_Measfreeze
//  
//  
//  
//  Parameter:     const uint8 ui8_FuncId   <In>
//  
//  
//  Parameter:     const uint32 ui32_VirtAddr   <In>
//  
//  
//  Parameter:     const void * const pv_Buff   <In>
//  
//  
//  Parameter:     const uint32 ui32_Size   <In>
//  
//  
//  Parameter:     const uint8 ui8_MeasGroup   <In>
//  
//    
//  
//  return         IC_E_ERROR
//**************************************************************************** */
/*## operation ICOSW_e_Measfreeze(const uint8,const uint32,const void * const,const uint32,const uint8) */
IC_E_ERROR ICOSW_e_Measfreeze(const uint8 ui8_FuncId, const uint32 ui32_VirtAddr, const void * const pv_Buff, const uint32 ui32_Size, const uint8 ui8_MeasGroup);

//*****************************************************************************
//  Functionname:  ICOSW_e_DemReport
//  
//  
//  
//  Parameter:     const IC_E_DEM e_Dem   <In>
//  
//  
//  Parameter:     const IC_E_DEMSTATUS e_Status   <In>
//  
//  
//  Parameter:     const IC_Un_DemDtcExtData * const pun_ExtData   <In>
//  
//    
//  
//  return         IC_E_ERROR
//**************************************************************************** */
/*## operation ICOSW_e_DemReport(const IC_E_DEM,const IC_E_DEMSTATUS,const IC_Un_DemDtcExtData * const) */
IC_E_ERROR ICOSW_e_DemReport(const IC_E_DEM e_Dem, const IC_E_DEMSTATUS e_Status, const IC_Un_DemDtcExtData * const pun_ExtData);

//*****************************************************************************
//  Functionname:  ICOSW_v_GetCommStats
//  
//  
//  
//  Parameter:     IC_S_CommStats * const ps_CommStats   <In>
//  
//    
//  
//  return         void
//**************************************************************************** */
/*## operation ICOSW_v_GetCommStats(IC_S_CommStats * const) */
void ICOSW_v_GetCommStats(IC_S_CommStats * const ps_CommStats);

//*****************************************************************************
//  Functionname:  ICOSW_e_HandleRXTXErr
//  
//  
//  
//  Parameter:     const IC_E_RXTXERR e_TransRet   <In>
//  
//    
//  
//  return         IC_E_ERROR
//**************************************************************************** */
/*## operation ICOSW_e_HandleRXTXErr(const IC_E_RXTXERR) */
IC_E_ERROR ICOSW_e_HandleRXTXErr(const IC_E_RXTXERR e_TransRet);


/*#[ ignore */

#ifdef __cplusplus
}
#endif

/*#]*/


#endif
/*********************************************************************
	File Path: ..\..\..\04_Engineering\01_Source_Code\Algo\ic\ic_oswrapper.h
*********************************************************************/
