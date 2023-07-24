//* **********************************************************************
//  COMPANY:         $CompanyInfo: CONFIDENTIAL AND PROPRIETARY PROPERTY OF CONTINENTAL AG , A.D.C. GmbH  -  ALL RIGHTS RESERVED $
//  
//  PROJECT:         MFC30x_MCU
//  CPU:             MPC5675K
//  
//  PACKAGE:         $Source: ic_driver.h $ $Revision: 1.1 $
//  MKS Date:        $Date: 2021/12/13 17:25:49CET $
//  
//  RHAPSODY:        7.5.3
//  COMPONENT:       IC
//  CONFIGURATION:   DefaultConfig
//  MODEL ELEMENT:   ic_driver
//  MODULNAME:       ..\..\..\04_Engineering\01_Source_Code\Algo\ic\ic_driver.h
//  LOGIN:           uidt3974  
//  
//  Disable QAC Messages:
//  
//    Possible dereference of NULL pointer.
//     PRQA S 0506 EOF
//  
//  AUTHOR:          $Author: Wang, David (Wangd3) $
//! CREATION DATE:   Fri, 20, Jul 2012  9:42 W. Europe Daylight Time PM 
//**************************************************************************** */

#ifndef ic_driver_H
#define ic_driver_H

/*## operation IMGDRV_e_Init(const IC_Fct_v_SetRegister) */
#include "ic_errcodes.h"
/*## dependency ic_registers */
#include "ic_registers.h"
/*## dependency ic_types */
#include "ic_types.h"
/*## package Ic_Pkg */

/*## class TopLevel::ic_driver */
/*#[ ignore */
//  Disable QAC Messages:
//  
//    Possible dereference of NULL pointer.
//     PRQA S 0506 EOF
/*#]*/


/*#[ ignore */

#ifdef __cplusplus
extern "C"
{
#endif

/*#]*/


/*## type IMGDRV_E_SensorTestmode */
typedef enum IMGDRV_E_SensorTestmode {
    IMGDRV_e_TESTPATTERN_NONE,
    IMGDRV_e_TESTPATTERN_SOLID_PATTERN,
    IMGDRV_e_TESTPATTERN_FADETOGRAY,
    IMGDRV_e_TESTPATTERN_WALKING_ONES
} IMGDRV_E_SensorTestmode;

/*## type IMGDRV_E_StreamingMode */
typedef enum IMGDRV_E_StreamingMode {
    IMGDRV_e_STREAMING_MODE_OFF = 0,
    IMGDRV_e_STREAMING_MODE_ON = 1,
    IMGDRV_e_STREAMING_MODE_EXTTRIGGER = 2
} IMGDRV_E_StreamingMode;

/*#[ type IC_Fct_v_SetRegister */
typedef void  (* IC_Fct_v_SetRegister)(IMGREG_E_SENSOR_REG e_Reg, uint16 ui16_Value, IC_E_Imager e_Imager) ;
/*#]*/

/*#[ type IC_Fct_v_GetRegister */
typedef IC_E_ERROR  (* IC_Fct_v_GetRegister)(IMGREG_E_SENSOR_REG e_Reg, uint16 * pui16_Value, IC_E_Imager e_Imager);
/*#]*/

/***    User explicit entries    ***/


/* Operations */

//*****************************************************************************
//  Functionname:  IMGDRV_e_Init
//  
//  
//  
//  Parameter:     const IC_Fct_v_SetRegister pfct_v_SetReg   <In>
//  
//    
//  
//  return         IC_E_ERROR
//**************************************************************************** */
/*## operation IMGDRV_e_Init(const IC_Fct_v_SetRegister) */
IC_E_ERROR IMGDRV_e_Init(const IC_Fct_v_SetRegister pfct_v_SetReg);

//*****************************************************************************
//  Functionname:  IMGDRV_v_SetRegisterInput
//  
//  
//  
//  Parameter:     const IC_S_RegBuff * const pRb_Regs   <In>
//  
//  
//  Parameter:     const IC_E_Imager e_Imager   <In>
//  
//    
//  
//  return         void
//**************************************************************************** */
/*## operation IMGDRV_v_SetRegisterInput(const IC_S_RegBuff * const,const IC_E_Imager) */
void IMGDRV_v_SetRegisterInput(const IC_S_RegBuff * const pRb_Regs, const IC_E_Imager e_Imager);

//*****************************************************************************
//  Functionname:  IMGDRV_v_SetRegisterOutput
//  
//  
//  
//  Parameter:     IC_S_RegBuff * const pRb_Regs   <In>
//  
//  
//  Parameter:     const IC_E_Imager e_Imager   <In>
//  
//    
//  
//  return         void
//**************************************************************************** */
/*## operation IMGDRV_v_SetRegisterOutput(IC_S_RegBuff * const,const IC_E_Imager) */
void IMGDRV_v_SetRegisterOutput(IC_S_RegBuff * const pRb_Regs, const IC_E_Imager e_Imager);

//*****************************************************************************
//  Functionname:  IMGDRV_e_SetCorrectionFactor
//  
//  Sets the gain correction factor between the two imagers, which is the ratio Gain(right)/Gain(left)
//  
//  Parameter:     const float32 f32_CorrectionFactor   <In>
//  
//    
//  
//  return         IC_E_ERROR
//**************************************************************************** */
/*## operation IMGDRV_e_SetCorrectionFactor(const float32) */
IC_E_ERROR IMGDRV_e_SetCorrectionFactor(const float32 f32_CorrectionFactor);

//*****************************************************************************
//  Functionname:  IMGDRV_e_SetCROI
//  
//  
//  
//  Parameter:     const IC_E_Imager e_Imager   <In>
//  
//  
//  Parameter:     const IC_S_Croi * const ps_Croi   <In>
//  
//    
//  
//  return         IC_E_ERROR
//**************************************************************************** */
/*## operation IMGDRV_e_SetCROI(const IC_E_Imager,const IC_S_Croi * const) */
IC_E_ERROR IMGDRV_e_SetCROI(const IC_E_Imager e_Imager, const IC_S_Croi * const ps_Croi);

//*****************************************************************************
//  Functionname:  IMGDRV_v_SetDCG
//  
//  
//  
//  Parameter:     const IC_E_DCG_STATE e_DCGstate   <In>
//  
//    
//  
//  return         void
//**************************************************************************** */
/*## operation IMGDRV_v_SetDCG(const IC_E_DCG_STATE) */
void IMGDRV_v_SetDCG(const IC_E_DCG_STATE e_DCGstate);

//*****************************************************************************
//  Functionname:  IMGDRV_e_GetDCGState
//  
//  
//  
//    
//  
//  return         IC_E_DCG_STATE
//**************************************************************************** */
/*## operation IMGDRV_e_GetDCGState() */
IC_E_DCG_STATE IMGDRV_e_GetDCGState(void);

//*****************************************************************************
//  Functionname:  IMGDRV_v_SetDigitalGain
//  
//  
//  
//  Parameter:     const float32 f32_DigitalGain   <In>
//  
//    
//  
//  return         void
//**************************************************************************** */
/*## operation IMGDRV_v_SetDigitalGain(const float32) */
void IMGDRV_v_SetDigitalGain(const float32 f32_DigitalGain);

//*****************************************************************************
//  Functionname:  IMGDRV_f32_GetDigitalGainRight
//  
//  
//  
//    
//  
//  return         float32
//**************************************************************************** */
/*## operation IMGDRV_f32_GetDigitalGainRight() */
float32 IMGDRV_f32_GetDigitalGainRight(void);

//*****************************************************************************
//  Functionname:  IMGDRV_v_SetAnalogGain
//  
//  
//  
//  Parameter:     const IC_E_ANALOG_GAIN e_AnalogGain   <In>
//  
//    
//  
//  return         void
//**************************************************************************** */
/*## operation IMGDRV_v_SetAnalogGain(const IC_E_ANALOG_GAIN) */
void IMGDRV_v_SetAnalogGain(const IC_E_ANALOG_GAIN e_AnalogGain);

//*****************************************************************************
//  Functionname:  IMGDRV_v_SetColCorrRetriggDCG
//  
//  
//  
//  Parameter:     const boolean b_TrigOnDCG   <In>
//  
//    
//  
//  return         void
//**************************************************************************** */
/*## operation IMGDRV_v_SetColCorrRetriggDCG(const boolean) */
void IMGDRV_v_SetColCorrRetriggDCG(const boolean b_TrigOnDCG);

//*****************************************************************************
//  Functionname:  IMGDRV_v_SetColCorrCorrectAlways
//  
//  
//  
//  Parameter:     const boolean b_CorrectAlways   <In>
//  
//    
//  
//  return         void
//**************************************************************************** */
/*## operation IMGDRV_v_SetColCorrCorrectAlways(const boolean) */
void IMGDRV_v_SetColCorrCorrectAlways(const boolean b_CorrectAlways);

//*****************************************************************************
//  Functionname:  IMGDRV_v_SetFrameId
//  
//  
//  
//  Parameter:     const uint16 ui16_FrameId   <In>
//  
//  
//  Parameter:     const IC_E_Imager e_Imager   <In>
//  
//    
//  
//  return         void
//**************************************************************************** */
/*## operation IMGDRV_v_SetFrameId(const uint16,const IC_E_Imager) */
void IMGDRV_v_SetFrameId(const uint16 ui16_FrameId, const IC_E_Imager e_Imager);

//*****************************************************************************
//  Functionname:  IMGDRV_e_SetICROI
//  
//  
//  
//  Parameter:     const IC_S_Roi * const ps_Roi   <In>
//  
//    
//  
//  return         IC_E_ERROR
//**************************************************************************** */
/*## operation IMGDRV_e_SetICROI(const IC_S_Roi * const) */
IC_E_ERROR IMGDRV_e_SetICROI(const IC_S_Roi * const ps_Roi);

//*****************************************************************************
//  Functionname:  IMGDRV_v_GetIcRoi
//  
//  
//  
//  Parameter:     IC_S_Roi * const ps_Roi   <In>
//  
//    
//  
//  return         void
//**************************************************************************** */
/*## operation IMGDRV_v_GetIcRoi(IC_S_Roi * const) */
void IMGDRV_v_GetIcRoi(IC_S_Roi * const ps_Roi);

//*****************************************************************************
//  Functionname:  IMGDRV_e_SetExposureTime
//  
//  
//  
//  Parameter:     const uint16 ui16_ExposureTimeUs   <In>
//  
//    
//  
//  return         IC_E_ERROR
//**************************************************************************** */
/*## operation IMGDRV_e_SetExposureTime(const uint16) */
IC_E_ERROR IMGDRV_e_SetExposureTime(const uint16 ui16_ExposureTimeUs);

//*****************************************************************************
//  Functionname:  IMGDRV_ui16_GetExposureTime
//  
//  
//  
//    
//  
//  return         uint16
//**************************************************************************** */
/*## operation IMGDRV_ui16_GetExposureTime() */
uint16 IMGDRV_ui16_GetExposureTime(void);

//*****************************************************************************
//  Functionname:  IMGDRV_v_SetIntegrationTimeRatios
//  
//  
//  
//  Parameter:     const IC_E_INTEGR_RATIO e_R1   <In>
//  
//  
//  Parameter:     const IC_E_INTEGR_RATIO e_R2   <In>
//  
//    
//  
//  return         void
//**************************************************************************** */
/*## operation IMGDRV_v_SetIntegrationTimeRatios(const IC_E_INTEGR_RATIO,const IC_E_INTEGR_RATIO) */
void IMGDRV_v_SetIntegrationTimeRatios(const IC_E_INTEGR_RATIO e_R1, const IC_E_INTEGR_RATIO e_R2);

//*****************************************************************************
//  Functionname:  IMGDRV_v_GetIntegrationTimeRatios
//  
//  
//  
//  Parameter:     IC_E_INTEGR_RATIO * const pe_R1   <In>
//  
//  
//  Parameter:     IC_E_INTEGR_RATIO * const pe_R2   <In>
//  
//    
//  
//  return         void
//**************************************************************************** */
/*## operation IMGDRV_v_GetIntegrationTimeRatios(IC_E_INTEGR_RATIO * const,IC_E_INTEGR_RATIO * const) */
void IMGDRV_v_GetIntegrationTimeRatios(IC_E_INTEGR_RATIO * const pe_R1, IC_E_INTEGR_RATIO * const pe_R2);

//*****************************************************************************
//  Functionname:  IMGDRV_v_SetTestpattern
//  
//  
//  
//  Parameter:     const IC_E_Imager e_Imager   <In>
//  
//  
//  Parameter:     const IMGDRV_E_SensorTestmode e_TestMode   <In>
//  
//    
//  
//  return         void
//**************************************************************************** */
/*## operation IMGDRV_v_SetTestpattern(const IC_E_Imager,const IMGDRV_E_SensorTestmode) */
void IMGDRV_v_SetTestpattern(const IC_E_Imager e_Imager, const IMGDRV_E_SensorTestmode e_TestMode);

//*****************************************************************************
//  Functionname:  IMGDRV_v_SetDatabusTestpattern
//  
//  
//  
//  Parameter:     const uint16 ui16_Pattern   <In>
//  
//    
//  
//  return         void
//**************************************************************************** */
/*## operation IMGDRV_v_SetDatabusTestpattern(const uint16) */
void IMGDRV_v_SetDatabusTestpattern(const uint16 ui16_Pattern);

//*****************************************************************************
//  Functionname:  IMGDRV_ui16_GetDatabusTestpattern
//  
//  
//  
//  Parameter:     const IC_E_Imager e_Imager   <In>
//  
//    
//  
//  return         uint16
//**************************************************************************** */
/*## operation IMGDRV_ui16_GetDatabusTestpattern(const IC_E_Imager) */
uint16 IMGDRV_ui16_GetDatabusTestpattern(const IC_E_Imager e_Imager);

//*****************************************************************************
//  Functionname:  IMGDRV_v_SetStreamingMode
//  
//  
//  
//  Parameter:     const IMGDRV_E_StreamingMode e_Mode   <In>
//  
//    
//  
//  return         void
//**************************************************************************** */
/*## operation IMGDRV_v_SetStreamingMode(const IMGDRV_E_StreamingMode) */
void IMGDRV_v_SetStreamingMode(const IMGDRV_E_StreamingMode e_Mode);

//*****************************************************************************
//  Functionname:  IMGDRV_v_SetAllowReadFuseId
//  
//  
//  
//  Parameter:     const boolean b_AllowRead   <In>
//  
//    
//  
//  return         void
//**************************************************************************** */
/*## operation IMGDRV_v_SetAllowReadFuseId(const boolean) */
void IMGDRV_v_SetAllowReadFuseId(const boolean b_AllowRead);

//*****************************************************************************
//  Functionname:  IMGDRV_e_GetTemperature
//  
//  
//  
//  Parameter:     const IC_E_Imager e_Imager   <In>
//  
//  
//  Parameter:     float32 * const pf32_Temp   <In>
//  
//    
//  
//  return         IC_E_ERROR
//**************************************************************************** */
/*## operation IMGDRV_e_GetTemperature(const IC_E_Imager,float32 * const) */
IC_E_ERROR IMGDRV_e_GetTemperature(const IC_E_Imager e_Imager, float32 * const pf32_Temp);

//*****************************************************************************
//  Functionname:  IMGDRV_v_SetTimestampEmbedded
//  
//  Copies a 64-bit timestamp into the embedded data. For this purpose
//  four unused registers are used:
//  
//    0x3102: AE_LUMA_TARGET_REG (LSB)
//    0x3104: AE_HIST_TARGET_REG
//    0x310C: AE_DAMP_OFFSET_REG
//    0x310E: AE_DAMP_GAIN_REG   (MSB)
//  
//  Parameter:     const IC_E_Imager e_Imager   <In>
//  
//  
//  Parameter:     const uint64 ui64_TimeStamp   <In>
//  
//    
//  
//  return         void
//**************************************************************************** */
/*## operation IMGDRV_v_SetTimestampEmbedded(const IC_E_Imager,const uint64) */
void IMGDRV_v_SetTimestampEmbedded(const IC_E_Imager e_Imager, const uint64 ui64_TimeStamp);

//*****************************************************************************
//  Functionname:  IMGDRV_ui64_GetTimestampEmbedded
//  
//  
//  
//  Parameter:     const IC_E_Imager e_Imager   <In>
//  
//    
//  
//  return         uint64
//**************************************************************************** */
/*## operation IMGDRV_ui64_GetTimestampEmbedded(const IC_E_Imager) */
uint64 IMGDRV_ui64_GetTimestampEmbedded(const IC_E_Imager e_Imager);

//*****************************************************************************
//  Functionname:  IMGDRV_v_SetFrameHeightTotal
//  
//  Sets the total height of an frame, including any blanking and embedded rows
//  
//  Parameter:     const IC_E_Imager e_Imager   <In>
//  
//  
//  Parameter:     const uint16 ui16_LinesTotal   <In>
//  
//    
//  
//  return         void
//**************************************************************************** */
/*## operation IMGDRV_v_SetFrameHeightTotal(const IC_E_Imager,const uint16) */
void IMGDRV_v_SetFrameHeightTotal(const IC_E_Imager e_Imager, const uint16 ui16_LinesTotal);

//*****************************************************************************
//  Functionname:  IMGDRV_ui16_GetImageHeightTotalR
//  
//  
//  
//    
//  
//  return         uint16
//**************************************************************************** */
/*## operation IMGDRV_ui16_GetImageHeightTotalR() */
uint16 IMGDRV_ui16_GetImageHeightTotalR(void);

//*****************************************************************************
//  Functionname:  IMGDRV_ui64_GetFuseId
//  
//  
//  
//  Parameter:     const IC_E_Imager e_Imager   <In>
//  
//    
//  
//  return         uint64
//**************************************************************************** */
/*## operation IMGDRV_ui64_GetFuseId(const IC_E_Imager) */
uint64 IMGDRV_ui64_GetFuseId(const IC_E_Imager e_Imager);

//*****************************************************************************
//  Functionname:  IMGDRV_ui16_GetModelId
//  
//  
//  
//  Parameter:     const IC_E_Imager e_Imager   <In>
//  
//    
//  
//  return         uint16
//**************************************************************************** */
/*## operation IMGDRV_ui16_GetModelId(const IC_E_Imager) */
uint16 IMGDRV_ui16_GetModelId(const IC_E_Imager e_Imager);

//*****************************************************************************
//  Functionname:  IMGDRV_ui8_GetRevisionNumber
//  
//  
//  
//  Parameter:     const IC_E_Imager e_Imager   <In>
//  
//    
//  
//  return         uint8
//**************************************************************************** */
/*## operation IMGDRV_ui8_GetRevisionNumber(const IC_E_Imager) */
uint8 IMGDRV_ui8_GetRevisionNumber(const IC_E_Imager e_Imager);

//*****************************************************************************
//  Functionname:  IMGDRV_v_SetEmbeddedDataVersion
//  
//  Sets an 8-bit version information into the embedded data
//  
//  Parameter:     const uint8 ui8_Version   <In>
//  
//    
//  
//  return         void
//**************************************************************************** */
/*## operation IMGDRV_v_SetEmbeddedDataVersion(const uint8) */
void IMGDRV_v_SetEmbeddedDataVersion(const uint8 ui8_Version);

//*****************************************************************************
//  Functionname:  IMGDRV_b_GetBistStatusPassed
//  
//  
//  
//  Parameter:     const IC_E_Imager e_Imager   <In>
//  
//    
//  
//  return         boolean
//**************************************************************************** */
/*## operation IMGDRV_b_GetBistStatusPassed(const IC_E_Imager) */
boolean IMGDRV_b_GetBistStatusPassed(const IC_E_Imager e_Imager);

//*****************************************************************************
//  Functionname:  IMGDRV_v_CollectImageData
//  
//  
//  
//  Parameter:     IC_S_EmbeddedRegData * const ps_EmbDat   <In>
//  
//  
//  Parameter:     const IC_E_Imager e_Imager   <In>
//  
//    
//  
//  return         void
//**************************************************************************** */
/*## operation IMGDRV_v_CollectImageData(IC_S_EmbeddedRegData * const,const IC_E_Imager) */
void IMGDRV_v_CollectImageData(IC_S_EmbeddedRegData * const ps_EmbDat, const IC_E_Imager e_Imager);

//*****************************************************************************
//  Functionname:  IMGDRV_ui32_LinesToUs
//  
//  
//  
//  Parameter:     const uint16 ui16_Lines   <In>
//  
//    
//  
//  return         uint32
//**************************************************************************** */
/*## operation IMGDRV_ui32_LinesToUs(const uint16) */
uint32 IMGDRV_ui32_LinesToUs(const uint16 ui16_Lines);

//*****************************************************************************
//  Functionname:  IMGDRV_ui16_UsToLines
//  
//  
//  
//  Parameter:     const uint32 ui32_TimeUs   <In>
//  
//    
//  
//  return         uint16
//**************************************************************************** */
/*## operation IMGDRV_ui16_UsToLines(const uint32) */
uint16 IMGDRV_ui16_UsToLines(const uint32 ui32_TimeUs);


/*#[ ignore */

#ifdef __cplusplus
}
#endif

/*#]*/


#endif
/*********************************************************************
	File Path: ..\..\..\04_Engineering\01_Source_Code\Algo\ic\ic_driver.h
*********************************************************************/
